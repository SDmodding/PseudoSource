// File Line: 25
// RVA: 0x15ABE60
__int64 UFG::_dynamic_initializer_for__gUIScreenTextInputChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gUIScreenTextInputChannel,
    "UIScreenTextInput",
    "\tThis gets the keyboard input events to the UI.\n\t\t mUserData0 = msg Type     mUserData1 = msg Data\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gUIScreenTextInputChannel__);
}

// File Line: 28
// RVA: 0x15ABE30
__int64 UFG::_dynamic_initializer_for__gUIScreenMouseInputChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gUIScreenMouseInputChannel,
    "UIScreenMouseInput",
    "\tThis gets the mouse input events to the UI.\n"
    "\t\t winMsg = msg Type     mouseX, mouseY = mouse cursor coordinates\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gUIScreenMouseInputChannel__);
}

// File Line: 32
// RVA: 0x15ABDB0
__int64 UFG::_dynamic_initializer_for__gUIControllerDisconnected__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gUIControllerDisconnected,
    "UIControllerDisconnected",
    "\tHandles controller disconnected.\n\t\t\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gUIControllerDisconnected__);
}

// File Line: 36
// RVA: 0x15ABDE0
__int64 UFG::_dynamic_initializer_for__gUIControllerReconnected__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gUIControllerReconnected,
    "UIControllerReconnected",
    "\tHandles controller reconnected.\n\t\t\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gUIControllerReconnected__);
}

// File Line: 76
// RVA: 0xA23300
void __fastcall UFG::UIInputHandler::UIInputHandler(UFG::UIInputHandler *this)
{
  float v1; // xmm0_4
  unsigned int *mLastAnalogValue; // rdx
  float *p_y; // rax
  __int64 v5; // r8
  fastdelegate::FastDelegate1<UFG::Event *,void> v6; // [rsp+30h] [rbp-18h] BYREF

  v1 = UFG::gUIInputHandlerAnalogStickDeadZone;
  this->mFirstDelay = 0.40000001;
  this->mMaxRepeatDelay = 0.2;
  this->mMinRepeatDelay = 0.050000001;
  this->mAnalogDeadZone = v1;
  this->mRepeatSpeed = 0.015;
  mLastAnalogValue = this->mLastAnalogValue;
  p_y = &this->mRightAnalogStick[0].y;
  v5 = 5i64;
  do
  {
    *(mLastAnalogValue - 25) = 0;
    *(_QWORD *)(p_y - 11) = 0i64;
    *(_QWORD *)(p_y - 1) = 0i64;
    *mLastAnalogValue = 0;
    *((_QWORD *)p_y - 18) = 0i64;
    *((_QWORD *)p_y - 13) = 0i64;
    p_y += 2;
    ++mLastAnalogValue;
    --v5;
  }
  while ( v5 );
  v6.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v6.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIInputHandler::handleKeyboardInput;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v6,
    UFG::gUIScreenTextInputChannel.mUID,
    UFG::gUIScreenTextInputChannel.mName,
    0);
  v6.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIInputHandler::handleMouseInput;
  v6.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v6,
    UFG::gUIScreenMouseInputChannel.mUID,
    UFG::gUIScreenMouseInputChannel.mName,
    0);
  v6.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIInputHandler::handleControllerDisconnect;
  v6.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v6,
    UFG::gUIControllerDisconnected.mUID,
    UFG::gUIControllerDisconnected.mName,
    0);
  v6.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIInputHandler::handleControllerReconnect;
  v6.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v6,
    UFG::gUIControllerReconnected.mUID,
    UFG::gUIControllerReconnected.mName,
    0);
}

// File Line: 102
// RVA: 0xA23C10
void __fastcall UFG::UIInputHandler::~UIInputHandler(UFG::UIInputHandler *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v2; // [rsp+20h] [rbp-18h] BYREF

  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIInputHandler::handleMouseInput;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gUIScreenMouseInputChannel.mUID);
  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIInputHandler::handleKeyboardInput;
  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gUIScreenTextInputChannel.mUID);
  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIInputHandler::handleControllerDisconnect;
  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gUIControllerDisconnected.mUID);
  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIInputHandler::handleControllerReconnect;
  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gUIControllerReconnected.mUID);
}

// File Line: 130
// RVA: 0xA2AE00
__int64 __fastcall UFG::UIInputHandler::getControllerIndex(UFG::UIScreen::ControllerMask controllerMask)
{
  __int64 result; // rax

  switch ( controllerMask )
  {
    case UI_CONTROLLER_MASK_PORT1:
      return 0i64;
    case UI_CONTROLLER_MASK_PORT2:
      return 1i64;
    case UI_CONTROLLER_MASK_PORT3:
      return 2i64;
  }
  result = 0xFFFFFFFFi64;
  if ( controllerMask == UI_CONTROLLER_MASK_PORT4 )
    return 3i64;
  return result;
}

// File Line: 152
// RVA: 0xA2ED20
void __fastcall UFG::UIInputHandler::handleInput(UFG::UIInputHandler *this, float elapsed)
{
  unsigned int v3; // esi
  float *p_y; // rbx
  signed __int64 v5; // r12
  signed __int64 v6; // r14
  __int64 v7; // r15
  int v8; // edi
  __int64 v9; // rax
  int v10; // xmm6_4
  int v11; // xmm7_4
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdx
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::UIMessage *v16; // rax
  __int64 v17; // rax
  int v18; // xmm6_4
  int v19; // xmm7_4
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rdx
  UFG::allocator::free_link *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::UIMessage *v24; // rax

  v3 = 0;
  p_y = &this->mRightAnalogStick[0].y;
  v5 = (char *)&UFG::ActionDef_UILeftThumbstick - (char *)this;
  v6 = (char *)&UFG::ActionDef_UIRightThumbstick - (char *)this;
  v7 = -184i64 - (_QWORD)this;
  do
  {
    if ( *(UFG::Controller **)((char *)UFG::gInputSystem->mControllers + (_QWORD)p_y + v7)
      && v3 == UFG::gActiveControllerNum )
    {
      if ( v3 )
      {
        if ( v3 == 1 )
        {
          v8 = 2;
        }
        else if ( v3 == 2 )
        {
          v8 = 4;
        }
        else
        {
          v8 = -1;
          if ( v3 == 3 )
            v8 = 8;
        }
      }
      else
      {
        v8 = 1;
      }
      UFG::UIInputHandler::handleDirectionalInput(this, elapsed, v3, v8);
      UFG::UIInputHandler::handleButtonInput(this, elapsed, v3, v8);
      v9 = *(_QWORD *)((char *)p_y + v5 - 184);
      if ( v9 && *(_BYTE *)(v9 + 76) )
      {
        v10 = *(_DWORD *)(v9 + 52);
        v11 = *(_DWORD *)(v9 + 40);
        v12 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x48ui64,
                "UIInputHandler::UIMessagePadInputAnalogStick",
                0i64,
                1u);
        v13 = v12;
        if ( v12 )
        {
          v14 = v12 + 1;
          v14->mNext = v14;
          v14[1].mNext = v14;
          v13->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
          LODWORD(v13[3].mNext) = -1;
          v13[4].mNext = 0i64;
          v13->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
          LODWORD(v13[5].mNext) = UI_HASH_THUMBSTICK_LEFT_35;
          HIDWORD(v13[5].mNext) = 0;
          v13[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v13[3].mNext) = 5;
          v13->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
          LODWORD(v13[7].mNext) = 1065353216;
          HIDWORD(v13[7].mNext) = v8;
          LODWORD(v13[3].mNext) = 6;
          HIDWORD(v13[6].mNext) = 0;
          v13->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInputAnalogStick::`vftable;
          LODWORD(v13[8].mNext) = v11;
          HIDWORD(v13[8].mNext) = v10;
          HIDWORD(v13[6].mNext) = 1;
        }
        else
        {
          v13 = 0i64;
        }
        UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, (UFG::UIMessage *)v13);
        *((_DWORD *)p_y - 11) = v11;
        *((_DWORD *)p_y - 10) = v10;
      }
      else if ( UFG::qVector2::msZero.x != *(p_y - 11) || UFG::qVector2::msZero.y != *(p_y - 10) )
      {
        v15 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x48ui64,
                "UIInputHandler::UIMessagePadInputAnalogStick",
                0i64,
                1u);
        if ( v15 )
          UFG::UIMessagePadInputAnalogStick::UIMessagePadInputAnalogStick(
            (UFG::UIMessagePadInputAnalogStick *)v15,
            UI_HASH_THUMBSTICK_LEFT_35,
            0.0,
            0.0,
            v8);
        else
          v16 = 0i64;
        UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, v16);
        *(_QWORD *)(p_y - 11) = 0i64;
      }
      v17 = *(_QWORD *)((char *)p_y + v6 - 184);
      if ( v17 && *(_BYTE *)(v17 + 76) )
      {
        v18 = *(_DWORD *)(v17 + 52);
        v19 = *(_DWORD *)(v17 + 40);
        v20 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x48ui64,
                "UIInputHandler::UIMessagePadInputAnalogStick",
                0i64,
                1u);
        v21 = v20;
        if ( v20 )
        {
          v22 = v20 + 1;
          v22->mNext = v22;
          v22[1].mNext = v22;
          v21->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
          LODWORD(v21[3].mNext) = -1;
          v21[4].mNext = 0i64;
          v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
          LODWORD(v21[5].mNext) = UI_HASH_THUMBSTICK_RIGHT_35;
          HIDWORD(v21[5].mNext) = 0;
          v21[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v21[3].mNext) = 5;
          v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
          LODWORD(v21[7].mNext) = 1065353216;
          HIDWORD(v21[7].mNext) = v8;
          LODWORD(v21[3].mNext) = 6;
          HIDWORD(v21[6].mNext) = 0;
          v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInputAnalogStick::`vftable;
          LODWORD(v21[8].mNext) = v19;
          HIDWORD(v21[8].mNext) = v18;
          HIDWORD(v21[6].mNext) = 1;
        }
        else
        {
          v21 = 0i64;
        }
        UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, (UFG::UIMessage *)v21);
        *((_DWORD *)p_y - 1) = v19;
        *(_DWORD *)p_y = v18;
      }
      else if ( UFG::qVector2::msZero.x != *(p_y - 1) || UFG::qVector2::msZero.y != *p_y )
      {
        v23 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x48ui64,
                "UIInputHandler::UIMessagePadInputAnalogStick",
                0i64,
                1u);
        if ( v23 )
          UFG::UIMessagePadInputAnalogStick::UIMessagePadInputAnalogStick(
            (UFG::UIMessagePadInputAnalogStick *)v23,
            UI_HASH_THUMBSTICK_RIGHT_35,
            0.0,
            0.0,
            v8);
        else
          v24 = 0i64;
        UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, v24);
        *(_QWORD *)(p_y - 1) = 0i64;
      }
    }
    ++v3;
    p_y += 2;
  }
  while ( v3 < 5 );
}

// File Line: 206
// RVA: 0xA2E080
void __fastcall UFG::UIInputHandler::handleDirectionalInput(
        UFG::UIInputHandler *this,
        float elapsed,
        int controllerIndex,
        int controllerMask)
{
  __int64 v5; // rbp
  UFG::allocator::free_link *v8; // r8
  UFG::InputActionData *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::InputActionData *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::InputActionData *v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::InputActionData *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::InputActionData *v21; // rax
  UFG::allocator::free_link *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::InputActionData *v24; // rax
  UFG::allocator::free_link *v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::InputActionData *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::InputActionData *v30; // rax
  UFG::allocator::free_link *v31; // rax
  UFG::allocator::free_link *v32; // rax
  UFG::InputActionData *v33; // rax
  UFG::allocator::free_link *v34; // rax
  UFG::allocator::free_link *v35; // rax
  UFG::InputActionData *v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::allocator::free_link *v38; // rax
  UFG::InputActionData *v39; // rax
  UFG::allocator::free_link *v40; // rax
  UFG::allocator::free_link *v41; // rax
  UFG::InputActionData *v42; // rax
  UFG::allocator::free_link *v43; // rax
  UFG::allocator::free_link *v44; // rax
  UFG::InputActionData *v45; // rax
  float v46; // xmm7_4
  float v47; // xmm6_4
  float mAnalogDeadZone; // xmm1_4
  int v49; // xmm0_4
  UFG::allocator::free_link *v50; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::allocator::free_link *v52; // rax
  UFG::allocator::free_link *v53; // rax
  UFG::allocator::free_link *v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::allocator::free_link *v56; // rax
  UFG::allocator::free_link *v57; // rax
  UFG::InputActionData *v58; // rax
  float v59; // xmm7_4
  float v60; // xmm6_4
  float v61; // xmm1_4
  int v62; // xmm0_4
  UFG::allocator::free_link *v63; // rax
  UFG::allocator::free_link *v64; // rax
  UFG::allocator::free_link *v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::allocator::free_link *v68; // rax
  UFG::allocator::free_link *v69; // rax
  UFG::allocator::free_link *v70; // rax
  unsigned int mNext; // eax

  v5 = controllerIndex;
  v8 = 0i64;
  v9 = UFG::ActionDef_UILeftPressed.mDataPerController[v5];
  if ( v9 && v9->mActionTrue )
  {
    this->mState[v5][0] = UIINPUT_IDLE;
    v10 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
    v8 = v10;
    if ( v10 )
    {
      v11 = v10 + 1;
      v11->mNext = v11;
      v11[1].mNext = v11;
      v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
      LODWORD(v8[3].mNext) = -1;
      v8[4].mNext = 0i64;
      v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
      LODWORD(v8[5].mNext) = UI_HASH_DPAD_LEFT_PRESSED_35;
      HIDWORD(v8[5].mNext) = 0;
      v8[6].mNext = (UFG::allocator::free_link *)-1i64;
      LODWORD(v8[3].mNext) = 5;
      v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
      LODWORD(v8[7].mNext) = 1065353216;
      HIDWORD(v8[7].mNext) = controllerMask;
      LODWORD(v8[3].mNext) = 6;
      HIDWORD(v8[6].mNext) = 0;
    }
    else
    {
      v8 = 0i64;
    }
  }
  else
  {
    v12 = UFG::ActionDef_UILeftRepeat.mDataPerController[v5];
    if ( v12 && v12->mActionTrue )
    {
      v13 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
      v8 = v13;
      if ( v13 )
      {
        v14 = v13 + 1;
        v14->mNext = v14;
        v14[1].mNext = v14;
        v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
        LODWORD(v8[3].mNext) = -1;
        v8[4].mNext = 0i64;
        v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
        LODWORD(v8[5].mNext) = UI_HASH_DPAD_LEFT_REPEAT_35;
        HIDWORD(v8[5].mNext) = 0;
        v8[6].mNext = (UFG::allocator::free_link *)-1i64;
        LODWORD(v8[3].mNext) = 5;
        v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
        LODWORD(v8[7].mNext) = 1065353216;
        HIDWORD(v8[7].mNext) = controllerMask;
        LODWORD(v8[3].mNext) = 6;
        HIDWORD(v8[6].mNext) = 0;
      }
      else
      {
        v8 = 0i64;
      }
    }
    else
    {
      v15 = UFG::ActionDef_UILeftReleased.mDataPerController[v5];
      if ( v15 && v15->mActionTrue )
      {
        this->mState[v5][0] = UIINPUT_IDLE;
        v16 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
        v8 = v16;
        if ( v16 )
        {
          v17 = v16 + 1;
          v17->mNext = v17;
          v17[1].mNext = v17;
          v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
          LODWORD(v8[3].mNext) = -1;
          v8[4].mNext = 0i64;
          v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
          LODWORD(v8[5].mNext) = UI_HASH_DPAD_LEFT_RELEASED_35;
          HIDWORD(v8[5].mNext) = 0;
          v8[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v8[3].mNext) = 5;
          v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
          *(UFG::allocator::free_link **)((char *)&v8[6].mNext + 4) = 0i64;
          HIDWORD(v8[7].mNext) = controllerMask;
          LODWORD(v8[3].mNext) = 6;
        }
        else
        {
          v8 = 0i64;
        }
      }
      else
      {
        v18 = UFG::ActionDef_UIRightPressed.mDataPerController[v5];
        if ( v18 && v18->mActionTrue )
        {
          this->mState[v5][0] = UIINPUT_IDLE;
          v19 = UFG::qMemoryPool::Allocate(
                  &gScaleformMemoryPool,
                  0x40ui64,
                  "UIInputHandler::UIMessagePadInput",
                  0i64,
                  1u);
          v8 = v19;
          if ( v19 )
          {
            v20 = v19 + 1;
            v20->mNext = v20;
            v20[1].mNext = v20;
            v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
            LODWORD(v8[3].mNext) = -1;
            v8[4].mNext = 0i64;
            v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
            LODWORD(v8[5].mNext) = UI_HASH_DPAD_RIGHT_PRESSED_35;
            HIDWORD(v8[5].mNext) = 0;
            v8[6].mNext = (UFG::allocator::free_link *)-1i64;
            LODWORD(v8[3].mNext) = 5;
            v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
            LODWORD(v8[7].mNext) = 1065353216;
            HIDWORD(v8[7].mNext) = controllerMask;
            LODWORD(v8[3].mNext) = 6;
            HIDWORD(v8[6].mNext) = 0;
          }
          else
          {
            v8 = 0i64;
          }
        }
        else
        {
          v21 = UFG::ActionDef_UIRightRepeat.mDataPerController[v5];
          if ( v21 && v21->mActionTrue )
          {
            v22 = UFG::qMemoryPool::Allocate(
                    &gScaleformMemoryPool,
                    0x40ui64,
                    "UIInputHandler::UIMessagePadInput",
                    0i64,
                    1u);
            v8 = v22;
            if ( v22 )
            {
              v23 = v22 + 1;
              v23->mNext = v23;
              v23[1].mNext = v23;
              v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
              LODWORD(v8[3].mNext) = -1;
              v8[4].mNext = 0i64;
              v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
              LODWORD(v8[5].mNext) = UI_HASH_DPAD_RIGHT_REPEAT_35;
              HIDWORD(v8[5].mNext) = 0;
              v8[6].mNext = (UFG::allocator::free_link *)-1i64;
              LODWORD(v8[3].mNext) = 5;
              v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
              LODWORD(v8[7].mNext) = 1065353216;
              HIDWORD(v8[7].mNext) = controllerMask;
              LODWORD(v8[3].mNext) = 6;
              HIDWORD(v8[6].mNext) = 0;
            }
            else
            {
              v8 = 0i64;
            }
          }
          else
          {
            v24 = UFG::ActionDef_UIRightReleased.mDataPerController[v5];
            if ( v24 && v24->mActionTrue )
            {
              this->mState[v5][0] = UIINPUT_IDLE;
              v25 = UFG::qMemoryPool::Allocate(
                      &gScaleformMemoryPool,
                      0x40ui64,
                      "UIInputHandler::UIMessagePadInput",
                      0i64,
                      1u);
              v8 = v25;
              if ( v25 )
              {
                v26 = v25 + 1;
                v26->mNext = v26;
                v26[1].mNext = v26;
                v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                LODWORD(v8[3].mNext) = -1;
                v8[4].mNext = 0i64;
                v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                LODWORD(v8[5].mNext) = UI_HASH_DPAD_RIGHT_RELEASED_35;
                HIDWORD(v8[5].mNext) = 0;
                v8[6].mNext = (UFG::allocator::free_link *)-1i64;
                LODWORD(v8[3].mNext) = 5;
                v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                *(UFG::allocator::free_link **)((char *)&v8[6].mNext + 4) = 0i64;
                HIDWORD(v8[7].mNext) = controllerMask;
                LODWORD(v8[3].mNext) = 6;
              }
              else
              {
                v8 = 0i64;
              }
            }
            else
            {
              v27 = UFG::ActionDef_UIUpPressed.mDataPerController[v5];
              if ( v27 && v27->mActionTrue )
              {
                this->mState[v5][0] = UIINPUT_IDLE;
                v28 = UFG::qMemoryPool::Allocate(
                        &gScaleformMemoryPool,
                        0x40ui64,
                        "UIInputHandler::UIMessagePadInput",
                        0i64,
                        1u);
                v8 = v28;
                if ( v28 )
                {
                  v29 = v28 + 1;
                  v29->mNext = v29;
                  v29[1].mNext = v29;
                  v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                  LODWORD(v8[3].mNext) = -1;
                  v8[4].mNext = 0i64;
                  v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                  LODWORD(v8[5].mNext) = UI_HASH_DPAD_UP_PRESSED_35;
                  HIDWORD(v8[5].mNext) = 0;
                  v8[6].mNext = (UFG::allocator::free_link *)-1i64;
                  LODWORD(v8[3].mNext) = 5;
                  v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                  LODWORD(v8[7].mNext) = 1065353216;
                  HIDWORD(v8[7].mNext) = controllerMask;
                  LODWORD(v8[3].mNext) = 6;
                  HIDWORD(v8[6].mNext) = 0;
                }
                else
                {
                  v8 = 0i64;
                }
              }
              else
              {
                v30 = UFG::ActionDef_UIUpRepeat.mDataPerController[v5];
                if ( v30 && v30->mActionTrue )
                {
                  v31 = UFG::qMemoryPool::Allocate(
                          &gScaleformMemoryPool,
                          0x40ui64,
                          "UIInputHandler::UIMessagePadInput",
                          0i64,
                          1u);
                  v8 = v31;
                  if ( v31 )
                  {
                    v32 = v31 + 1;
                    v32->mNext = v32;
                    v32[1].mNext = v32;
                    v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                    LODWORD(v8[3].mNext) = -1;
                    v8[4].mNext = 0i64;
                    v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                    LODWORD(v8[5].mNext) = UI_HASH_DPAD_UP_REPEAT_35;
                    HIDWORD(v8[5].mNext) = 0;
                    v8[6].mNext = (UFG::allocator::free_link *)-1i64;
                    LODWORD(v8[3].mNext) = 5;
                    v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                    LODWORD(v8[7].mNext) = 1065353216;
                    HIDWORD(v8[7].mNext) = controllerMask;
                    LODWORD(v8[3].mNext) = 6;
                    HIDWORD(v8[6].mNext) = 0;
                  }
                  else
                  {
                    v8 = 0i64;
                  }
                }
                else
                {
                  v33 = UFG::ActionDef_UIUpReleased.mDataPerController[v5];
                  if ( v33 && v33->mActionTrue )
                  {
                    this->mState[v5][0] = UIINPUT_IDLE;
                    v34 = UFG::qMemoryPool::Allocate(
                            &gScaleformMemoryPool,
                            0x40ui64,
                            "UIInputHandler::UIMessagePadInput",
                            0i64,
                            1u);
                    v8 = v34;
                    if ( v34 )
                    {
                      v35 = v34 + 1;
                      v35->mNext = v35;
                      v35[1].mNext = v35;
                      v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                      LODWORD(v8[3].mNext) = -1;
                      v8[4].mNext = 0i64;
                      v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                      LODWORD(v8[5].mNext) = UI_HASH_DPAD_UP_RELEASED_35;
                      HIDWORD(v8[5].mNext) = 0;
                      v8[6].mNext = (UFG::allocator::free_link *)-1i64;
                      LODWORD(v8[3].mNext) = 5;
                      v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                      *(UFG::allocator::free_link **)((char *)&v8[6].mNext + 4) = 0i64;
                      HIDWORD(v8[7].mNext) = controllerMask;
                      LODWORD(v8[3].mNext) = 6;
                    }
                    else
                    {
                      v8 = 0i64;
                    }
                  }
                  else
                  {
                    v36 = UFG::ActionDef_UIDownPressed.mDataPerController[v5];
                    if ( v36 && v36->mActionTrue )
                    {
                      this->mState[v5][0] = UIINPUT_IDLE;
                      v37 = UFG::qMemoryPool::Allocate(
                              &gScaleformMemoryPool,
                              0x40ui64,
                              "UIInputHandler::UIMessagePadInput",
                              0i64,
                              1u);
                      v8 = v37;
                      if ( v37 )
                      {
                        v38 = v37 + 1;
                        v38->mNext = v38;
                        v38[1].mNext = v38;
                        v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                        LODWORD(v8[3].mNext) = -1;
                        v8[4].mNext = 0i64;
                        v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                        LODWORD(v8[5].mNext) = UI_HASH_DPAD_DOWN_PRESSED_35;
                        HIDWORD(v8[5].mNext) = 0;
                        v8[6].mNext = (UFG::allocator::free_link *)-1i64;
                        LODWORD(v8[3].mNext) = 5;
                        v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                        LODWORD(v8[7].mNext) = 1065353216;
                        HIDWORD(v8[7].mNext) = controllerMask;
                        LODWORD(v8[3].mNext) = 6;
                        HIDWORD(v8[6].mNext) = 0;
                      }
                      else
                      {
                        v8 = 0i64;
                      }
                    }
                    else
                    {
                      v39 = UFG::ActionDef_UIDownRepeat.mDataPerController[v5];
                      if ( v39 && v39->mActionTrue )
                      {
                        v40 = UFG::qMemoryPool::Allocate(
                                &gScaleformMemoryPool,
                                0x40ui64,
                                "UIInputHandler::UIMessagePadInput",
                                0i64,
                                1u);
                        v8 = v40;
                        if ( v40 )
                        {
                          v41 = v40 + 1;
                          v41->mNext = v41;
                          v41[1].mNext = v41;
                          v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                          LODWORD(v8[3].mNext) = -1;
                          v8[4].mNext = 0i64;
                          v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                          LODWORD(v8[5].mNext) = UI_HASH_DPAD_DOWN_REPEAT_35;
                          HIDWORD(v8[5].mNext) = 0;
                          v8[6].mNext = (UFG::allocator::free_link *)-1i64;
                          LODWORD(v8[3].mNext) = 5;
                          v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                          LODWORD(v8[7].mNext) = 1065353216;
                          HIDWORD(v8[7].mNext) = controllerMask;
                          LODWORD(v8[3].mNext) = 6;
                          HIDWORD(v8[6].mNext) = 0;
                        }
                        else
                        {
                          v8 = 0i64;
                        }
                      }
                      else
                      {
                        v42 = UFG::ActionDef_UIDownReleased.mDataPerController[v5];
                        if ( v42 && v42->mActionTrue )
                        {
                          this->mState[v5][0] = UIINPUT_IDLE;
                          v43 = UFG::qMemoryPool::Allocate(
                                  &gScaleformMemoryPool,
                                  0x40ui64,
                                  "UIInputHandler::UIMessagePadInput",
                                  0i64,
                                  1u);
                          v8 = v43;
                          if ( v43 )
                          {
                            v44 = v43 + 1;
                            v44->mNext = v44;
                            v44[1].mNext = v44;
                            v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                            LODWORD(v8[3].mNext) = -1;
                            v8[4].mNext = 0i64;
                            v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                            LODWORD(v8[5].mNext) = UI_HASH_DPAD_DOWN_RELEASED_35;
                            HIDWORD(v8[5].mNext) = 0;
                            v8[6].mNext = (UFG::allocator::free_link *)-1i64;
                            LODWORD(v8[3].mNext) = 5;
                            v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                            *(UFG::allocator::free_link **)((char *)&v8[6].mNext + 4) = 0i64;
                            HIDWORD(v8[7].mNext) = controllerMask;
                            LODWORD(v8[3].mNext) = 6;
                          }
                          else
                          {
                            v8 = 0i64;
                          }
                        }
                        else
                        {
                          v45 = UFG::ActionDef_UILeftThumbstick.mDataPerController[v5];
                          if ( v45 && v45->mActionTrue )
                          {
                            v46 = v45->mAxisRawX[0];
                            v47 = v45->mAxisRawY[0];
                            mAnalogDeadZone = this->mAnalogDeadZone;
                            v49 = LODWORD(this->mAnalogDeadZone) ^ _xmm[0];
                            if ( v46 >= *(float *)&v49 )
                            {
                              if ( v46 <= mAnalogDeadZone )
                              {
                                if ( v47 <= mAnalogDeadZone )
                                {
                                  if ( v47 >= *(float *)&v49 )
                                    goto LABEL_102;
                                  v56 = UFG::qMemoryPool::Allocate(
                                          &gScaleformMemoryPool,
                                          0x40ui64,
                                          "UIInputHandler::UIMessagePadInput",
                                          0i64,
                                          1u);
                                  if ( v56 )
                                  {
                                    UFG::UIMessagePadInput::UIMessagePadInput(
                                      (UFG::UIMessagePadInput *)v56,
                                      UI_HASH_THUMBSTICK_LEFT_UP_35,
                                      v47,
                                      controllerMask);
                                    v8 = v57;
                                  }
                                  else
                                  {
                                    v8 = 0i64;
                                  }
                                }
                                else
                                {
                                  v54 = UFG::qMemoryPool::Allocate(
                                          &gScaleformMemoryPool,
                                          0x40ui64,
                                          "UIInputHandler::UIMessagePadInput",
                                          0i64,
                                          1u);
                                  if ( v54 )
                                  {
                                    UFG::UIMessagePadInput::UIMessagePadInput(
                                      (UFG::UIMessagePadInput *)v54,
                                      UI_HASH_THUMBSTICK_LEFT_DOWN_35,
                                      v47,
                                      controllerMask);
                                    v8 = v55;
                                  }
                                  else
                                  {
                                    v8 = 0i64;
                                  }
                                }
                              }
                              else
                              {
                                v52 = UFG::qMemoryPool::Allocate(
                                        &gScaleformMemoryPool,
                                        0x40ui64,
                                        "UIInputHandler::UIMessagePadInput",
                                        0i64,
                                        1u);
                                if ( v52 )
                                {
                                  UFG::UIMessagePadInput::UIMessagePadInput(
                                    (UFG::UIMessagePadInput *)v52,
                                    UI_HASH_THUMBSTICK_LEFT_RIGHT_35,
                                    v46,
                                    controllerMask);
                                  v8 = v53;
                                }
                                else
                                {
                                  v8 = 0i64;
                                }
                              }
                            }
                            else
                            {
                              v50 = UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      0x40ui64,
                                      "UIInputHandler::UIMessagePadInput",
                                      0i64,
                                      1u);
                              if ( v50 )
                              {
                                UFG::UIMessagePadInput::UIMessagePadInput(
                                  (UFG::UIMessagePadInput *)v50,
                                  UI_HASH_THUMBSTICK_LEFT_LEFT_35,
                                  v46,
                                  controllerMask);
                                v8 = v51;
                              }
                              else
                              {
                                v8 = 0i64;
                              }
                            }
                          }
                          else
                          {
                            v58 = UFG::ActionDef_UIRightThumbstick.mDataPerController[v5];
                            if ( !v58 || !v58->mActionTrue )
                            {
                              this->mLastAnalogValue[v5] = 0;
                              goto LABEL_102;
                            }
                            v59 = v58->mAxisRawX[0];
                            v60 = v58->mAxisRawY[0];
                            v61 = this->mAnalogDeadZone;
                            v62 = LODWORD(this->mAnalogDeadZone) ^ _xmm[0];
                            if ( v59 >= *(float *)&v62 )
                            {
                              if ( v59 <= v61 )
                              {
                                if ( v60 <= v61 )
                                {
                                  if ( v60 >= *(float *)&v62 )
                                    goto LABEL_102;
                                  v69 = UFG::qMemoryPool::Allocate(
                                          &gScaleformMemoryPool,
                                          0x40ui64,
                                          "UIInputHandler::UIMessagePadInput",
                                          0i64,
                                          1u);
                                  if ( v69 )
                                  {
                                    UFG::UIMessagePadInput::UIMessagePadInput(
                                      (UFG::UIMessagePadInput *)v69,
                                      UI_HASH_THUMBSTICK_RIGHT_UP_35,
                                      v60,
                                      controllerMask);
                                    v8 = v70;
                                  }
                                  else
                                  {
                                    v8 = 0i64;
                                  }
                                }
                                else
                                {
                                  v67 = UFG::qMemoryPool::Allocate(
                                          &gScaleformMemoryPool,
                                          0x40ui64,
                                          "UIInputHandler::UIMessagePadInput",
                                          0i64,
                                          1u);
                                  if ( v67 )
                                  {
                                    UFG::UIMessagePadInput::UIMessagePadInput(
                                      (UFG::UIMessagePadInput *)v67,
                                      UI_HASH_THUMBSTICK_RIGHT_DOWN_35,
                                      v60,
                                      controllerMask);
                                    v8 = v68;
                                  }
                                  else
                                  {
                                    v8 = 0i64;
                                  }
                                }
                              }
                              else
                              {
                                v65 = UFG::qMemoryPool::Allocate(
                                        &gScaleformMemoryPool,
                                        0x40ui64,
                                        "UIInputHandler::UIMessagePadInput",
                                        0i64,
                                        1u);
                                if ( v65 )
                                {
                                  UFG::UIMessagePadInput::UIMessagePadInput(
                                    (UFG::UIMessagePadInput *)v65,
                                    UI_HASH_THUMBSTICK_RIGHT_RIGHT_35,
                                    v59,
                                    controllerMask);
                                  v8 = v66;
                                }
                                else
                                {
                                  v8 = 0i64;
                                }
                              }
                            }
                            else
                            {
                              v63 = UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      0x40ui64,
                                      "UIInputHandler::UIMessagePadInput",
                                      0i64,
                                      1u);
                              if ( v63 )
                              {
                                UFG::UIMessagePadInput::UIMessagePadInput(
                                  (UFG::UIMessagePadInput *)v63,
                                  UI_HASH_THUMBSTICK_RIGHT_LEFT_35,
                                  v59,
                                  controllerMask);
                                v8 = v64;
                              }
                              else
                              {
                                v8 = 0i64;
                              }
                            }
                          }
                          if ( v8 )
                          {
                            mNext = (unsigned int)v8[5].mNext;
                            if ( mNext != this->mLastAnalogValue[v5] )
                              this->mState[v5][0] = UIINPUT_IDLE;
                            this->mLastAnalogValue[v5] = mNext;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_102:
  UFG::UIInputHandler::update(this, elapsed, (UFG::UIMessage *)v8, v5, UIINPUT_DIRECTIONAL);
}

// File Line: 318
// RVA: 0xA2C190
void __fastcall UFG::UIInputHandler::handleButtonInput(
        UFG::UIInputHandler *this,
        float elapsed,
        int controllerIndex,
        unsigned int controllerMask)
{
  __int64 v5; // r15
  UFG::UIMessage *v7; // rbx
  UFG::InputActionData *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::InputActionData *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::InputActionData *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::InputActionData *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::InputActionData *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::InputActionData *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::InputActionData *v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::InputActionData *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::InputActionData *v24; // rax
  UFG::allocator::free_link *v25; // rax
  UFG::InputActionData *v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::InputActionData *v28; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::InputActionData *v30; // rax
  UFG::allocator::free_link *v31; // rax
  UFG::InputActionData *v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::InputActionData *v34; // rax
  UFG::allocator::free_link *v35; // rax
  UFG::InputActionData *v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::InputActionData *v38; // rax
  UFG::allocator::free_link *v39; // rax
  UFG::InputActionData *v40; // rax
  UFG::allocator::free_link *v41; // rax
  UFG::InputActionData *v42; // rax
  UFG::allocator::free_link *v43; // rax
  UFG::InputActionData *v44; // rax
  UFG::UIScreenTextureManager *v45; // rax
  UFG::UIScreenTextureManager *v46; // rax
  UFG::UIScreenTextureManager *v47; // rax
  UFG::allocator::free_link *v48; // rax
  UFG::allocator::free_link *v49; // rax
  UFG::InputActionData *v50; // rax
  UFG::UIScreenTextureManager *v51; // rax
  UFG::UIScreenTextureManager *v52; // rax
  UFG::UIScreenTextureManager *v53; // rax
  UFG::allocator::free_link *v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::InputActionData *v56; // rax
  UFG::UIScreenTextureManager *v57; // rax
  UFG::UIScreenTextureManager *v58; // rax
  UFG::UIScreenTextureManager *v59; // rax
  UFG::allocator::free_link *v60; // rax
  UFG::allocator::free_link *v61; // rax
  UFG::InputActionData *v62; // rax
  UFG::allocator::free_link *v63; // rax
  UFG::InputActionData *v64; // rax
  UFG::allocator::free_link *v65; // rax
  UFG::InputActionData *v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::InputActionData *v68; // rax
  UFG::allocator::free_link *v69; // rax
  UFG::InputActionData *v70; // rax
  UFG::allocator::free_link *v71; // rax
  UFG::InputActionData *v72; // rax
  UFG::allocator::free_link *v73; // rax
  UFG::InputActionData *v74; // rax
  UFG::allocator::free_link *v75; // rax
  UFG::InputActionData *v76; // rax
  UFG::allocator::free_link *v77; // rax
  UFG::InputActionData *v78; // rax
  UFG::allocator::free_link *v79; // rax
  UFG::InputActionData *v80; // rax
  UFG::allocator::free_link *v81; // rax
  UFG::InputActionData *v82; // rax
  UFG::allocator::free_link *v83; // rax
  UFG::InputActionData *v84; // rax
  UFG::allocator::free_link *v85; // rax
  UFG::InputActionData *v86; // rax
  UFG::allocator::free_link *v87; // rax
  UFG::InputActionData *v88; // rax
  UFG::allocator::free_link *v89; // rax
  UFG::InputActionData *v90; // rax
  UFG::allocator::free_link *v91; // rax
  UFG::InputActionData *v92; // rax
  UFG::allocator::free_link *v93; // rax
  UFG::InputActionData *v94; // rax
  UFG::allocator::free_link *v95; // rax
  UFG::InputActionData *v96; // rax
  UFG::allocator::free_link *v97; // rax

  v5 = controllerIndex;
  v7 = 0i64;
  v8 = UFG::ActionDef_UIAcceptPressed.mDataPerController[controllerIndex];
  if ( v8 && v8->mActionTrue )
  {
    this->mState[controllerIndex][1] = UIINPUT_IDLE;
    v9 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
    if ( v9 )
    {
      v9[1].mNext = v9 + 1;
      v9[2].mNext = v9 + 1;
      v9->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
      LODWORD(v9[3].mNext) = -1;
      v9[4].mNext = 0i64;
      v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
      LODWORD(v9[5].mNext) = UI_HASH_BUTTON_ACCEPT_PRESSED_35;
      HIDWORD(v9[5].mNext) = 0;
      v9[6].mNext = (UFG::allocator::free_link *)-1i64;
      LODWORD(v9[3].mNext) = 5;
      v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
      LODWORD(v9[7].mNext) = 1065353216;
      HIDWORD(v9[7].mNext) = controllerMask;
      LODWORD(v9[3].mNext) = 6;
      HIDWORD(v9[6].mNext) = 0;
      v7 = (UFG::UIMessage *)v9;
    }
  }
  else
  {
    v10 = UFG::ActionDef_UIAcceptRepeat.mDataPerController[controllerIndex];
    if ( v10 && v10->mActionTrue )
    {
      v11 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
      if ( v11 )
      {
        v11[1].mNext = v11 + 1;
        v11[2].mNext = v11 + 1;
        v11->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
        LODWORD(v11[3].mNext) = -1;
        v11[4].mNext = 0i64;
        v11->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
        LODWORD(v11[5].mNext) = UI_HASH_BUTTON_ACCEPT_REPEAT_35;
        HIDWORD(v11[5].mNext) = 0;
        v11[6].mNext = (UFG::allocator::free_link *)-1i64;
        LODWORD(v11[3].mNext) = 5;
        v11->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
        LODWORD(v11[7].mNext) = 1065353216;
        HIDWORD(v11[7].mNext) = controllerMask;
        LODWORD(v11[3].mNext) = 6;
        HIDWORD(v11[6].mNext) = 0;
        v7 = (UFG::UIMessage *)v11;
      }
    }
    else
    {
      v12 = UFG::ActionDef_UIAcceptReleased.mDataPerController[controllerIndex];
      if ( v12 && v12->mActionTrue )
      {
        this->mState[controllerIndex][1] = UIINPUT_IDLE;
        v13 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
        if ( v13 )
        {
          v13[1].mNext = v13 + 1;
          v13[2].mNext = v13 + 1;
          v13->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
          LODWORD(v13[3].mNext) = -1;
          v13[4].mNext = 0i64;
          v13->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
          LODWORD(v13[5].mNext) = UI_HASH_BUTTON_ACCEPT_RELEASED_35;
          HIDWORD(v13[5].mNext) = 0;
          v13[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v13[3].mNext) = 5;
          v13->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
          *(UFG::allocator::free_link **)((char *)&v13[6].mNext + 4) = 0i64;
          HIDWORD(v13[7].mNext) = controllerMask;
          LODWORD(v13[3].mNext) = 6;
          v7 = (UFG::UIMessage *)v13;
        }
      }
      else
      {
        v14 = UFG::ActionDef_UIBackPressed.mDataPerController[controllerIndex];
        if ( v14 && v14->mActionTrue )
        {
          this->mState[controllerIndex][1] = UIINPUT_IDLE;
          v15 = UFG::qMemoryPool::Allocate(
                  &gScaleformMemoryPool,
                  0x40ui64,
                  "UIInputHandler::UIMessagePadInput",
                  0i64,
                  1u);
          if ( v15 )
          {
            v15[1].mNext = v15 + 1;
            v15[2].mNext = v15 + 1;
            v15->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
            LODWORD(v15[3].mNext) = -1;
            v15[4].mNext = 0i64;
            v15->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
            LODWORD(v15[5].mNext) = UI_HASH_BUTTON_BACK_PRESSED_35;
            HIDWORD(v15[5].mNext) = 0;
            v15[6].mNext = (UFG::allocator::free_link *)-1i64;
            LODWORD(v15[3].mNext) = 5;
            v15->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
            LODWORD(v15[7].mNext) = 1065353216;
            HIDWORD(v15[7].mNext) = controllerMask;
            LODWORD(v15[3].mNext) = 6;
            HIDWORD(v15[6].mNext) = 0;
            v7 = (UFG::UIMessage *)v15;
          }
        }
        else
        {
          v16 = UFG::ActionDef_UIBackRepeat.mDataPerController[controllerIndex];
          if ( v16 && v16->mActionTrue )
          {
            v17 = UFG::qMemoryPool::Allocate(
                    &gScaleformMemoryPool,
                    0x40ui64,
                    "UIInputHandler::UIMessagePadInput",
                    0i64,
                    1u);
            if ( v17 )
            {
              v17[1].mNext = v17 + 1;
              v17[2].mNext = v17 + 1;
              v17->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
              LODWORD(v17[3].mNext) = -1;
              v17[4].mNext = 0i64;
              v17->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
              LODWORD(v17[5].mNext) = UI_HASH_BUTTON_BACK_REPEAT_35;
              HIDWORD(v17[5].mNext) = 0;
              v17[6].mNext = (UFG::allocator::free_link *)-1i64;
              LODWORD(v17[3].mNext) = 5;
              v17->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
              LODWORD(v17[7].mNext) = 1065353216;
              HIDWORD(v17[7].mNext) = controllerMask;
              LODWORD(v17[3].mNext) = 6;
              HIDWORD(v17[6].mNext) = 0;
              v7 = (UFG::UIMessage *)v17;
            }
          }
          else
          {
            v18 = UFG::ActionDef_UIBackReleased.mDataPerController[controllerIndex];
            if ( v18 && v18->mActionTrue )
            {
              this->mState[controllerIndex][1] = UIINPUT_IDLE;
              v19 = UFG::qMemoryPool::Allocate(
                      &gScaleformMemoryPool,
                      0x40ui64,
                      "UIInputHandler::UIMessagePadInput",
                      0i64,
                      1u);
              if ( v19 )
              {
                v19[1].mNext = v19 + 1;
                v19[2].mNext = v19 + 1;
                v19->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                LODWORD(v19[3].mNext) = -1;
                v19[4].mNext = 0i64;
                v19->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                LODWORD(v19[5].mNext) = UI_HASH_BUTTON_BACK_RELEASED_35;
                HIDWORD(v19[5].mNext) = 0;
                v19[6].mNext = (UFG::allocator::free_link *)-1i64;
                LODWORD(v19[3].mNext) = 5;
                v19->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                *(UFG::allocator::free_link **)((char *)&v19[6].mNext + 4) = 0i64;
                HIDWORD(v19[7].mNext) = controllerMask;
                LODWORD(v19[3].mNext) = 6;
                v7 = (UFG::UIMessage *)v19;
              }
            }
            else
            {
              v20 = UFG::ActionDef_UIButton1Pressed.mDataPerController[controllerIndex];
              if ( v20 && v20->mActionTrue )
              {
                this->mState[controllerIndex][1] = UIINPUT_IDLE;
                v21 = UFG::qMemoryPool::Allocate(
                        &gScaleformMemoryPool,
                        0x40ui64,
                        "UIInputHandler::UIMessagePadInput",
                        0i64,
                        1u);
                if ( v21 )
                {
                  v21[1].mNext = v21 + 1;
                  v21[2].mNext = v21 + 1;
                  v21->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                  LODWORD(v21[3].mNext) = -1;
                  v21[4].mNext = 0i64;
                  v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                  LODWORD(v21[5].mNext) = UI_HASH_BUTTON_BUTTON1_PRESSED_35;
                  HIDWORD(v21[5].mNext) = 0;
                  v21[6].mNext = (UFG::allocator::free_link *)-1i64;
                  LODWORD(v21[3].mNext) = 5;
                  v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                  LODWORD(v21[7].mNext) = 1065353216;
                  HIDWORD(v21[7].mNext) = controllerMask;
                  LODWORD(v21[3].mNext) = 6;
                  HIDWORD(v21[6].mNext) = 0;
                  v7 = (UFG::UIMessage *)v21;
                }
              }
              else
              {
                v22 = UFG::ActionDef_UIButton1Repeat.mDataPerController[controllerIndex];
                if ( v22 && v22->mActionTrue )
                {
                  v23 = UFG::qMemoryPool::Allocate(
                          &gScaleformMemoryPool,
                          0x40ui64,
                          "UIInputHandler::UIMessagePadInput",
                          0i64,
                          1u);
                  if ( v23 )
                  {
                    v23[1].mNext = v23 + 1;
                    v23[2].mNext = v23 + 1;
                    v23->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                    LODWORD(v23[3].mNext) = -1;
                    v23[4].mNext = 0i64;
                    v23->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                    LODWORD(v23[5].mNext) = UI_HASH_BUTTON_BUTTON1_REPEAT_35;
                    HIDWORD(v23[5].mNext) = 0;
                    v23[6].mNext = (UFG::allocator::free_link *)-1i64;
                    LODWORD(v23[3].mNext) = 5;
                    v23->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                    LODWORD(v23[7].mNext) = 1065353216;
                    HIDWORD(v23[7].mNext) = controllerMask;
                    LODWORD(v23[3].mNext) = 6;
                    HIDWORD(v23[6].mNext) = 0;
                    v7 = (UFG::UIMessage *)v23;
                  }
                }
                else
                {
                  v24 = UFG::ActionDef_UIButton1Released.mDataPerController[controllerIndex];
                  if ( v24 && v24->mActionTrue )
                  {
                    this->mState[controllerIndex][1] = UIINPUT_IDLE;
                    v25 = UFG::qMemoryPool::Allocate(
                            &gScaleformMemoryPool,
                            0x40ui64,
                            "UIInputHandler::UIMessagePadInput",
                            0i64,
                            1u);
                    if ( v25 )
                    {
                      v25[1].mNext = v25 + 1;
                      v25[2].mNext = v25 + 1;
                      v25->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                      LODWORD(v25[3].mNext) = -1;
                      v25[4].mNext = 0i64;
                      v25->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                      LODWORD(v25[5].mNext) = UI_HASH_BUTTON_BUTTON1_RELEASED_35;
                      HIDWORD(v25[5].mNext) = 0;
                      v25[6].mNext = (UFG::allocator::free_link *)-1i64;
                      LODWORD(v25[3].mNext) = 5;
                      v25->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                      *(UFG::allocator::free_link **)((char *)&v25[6].mNext + 4) = 0i64;
                      HIDWORD(v25[7].mNext) = controllerMask;
                      LODWORD(v25[3].mNext) = 6;
                      v7 = (UFG::UIMessage *)v25;
                    }
                  }
                  else
                  {
                    v26 = UFG::ActionDef_UIButton2Pressed.mDataPerController[controllerIndex];
                    if ( v26 && v26->mActionTrue )
                    {
                      this->mState[controllerIndex][1] = UIINPUT_IDLE;
                      v27 = UFG::qMemoryPool::Allocate(
                              &gScaleformMemoryPool,
                              0x40ui64,
                              "UIInputHandler::UIMessagePadInput",
                              0i64,
                              1u);
                      if ( v27 )
                      {
                        v27[1].mNext = v27 + 1;
                        v27[2].mNext = v27 + 1;
                        v27->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                        LODWORD(v27[3].mNext) = -1;
                        v27[4].mNext = 0i64;
                        v27->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                        LODWORD(v27[5].mNext) = UI_HASH_BUTTON_BUTTON2_PRESSED_35;
                        HIDWORD(v27[5].mNext) = 0;
                        v27[6].mNext = (UFG::allocator::free_link *)-1i64;
                        LODWORD(v27[3].mNext) = 5;
                        v27->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                        LODWORD(v27[7].mNext) = 1065353216;
                        HIDWORD(v27[7].mNext) = controllerMask;
                        LODWORD(v27[3].mNext) = 6;
                        HIDWORD(v27[6].mNext) = 0;
                        v7 = (UFG::UIMessage *)v27;
                      }
                    }
                    else
                    {
                      v28 = UFG::ActionDef_UIButton2Repeat.mDataPerController[controllerIndex];
                      if ( v28 && v28->mActionTrue )
                      {
                        v29 = UFG::qMemoryPool::Allocate(
                                &gScaleformMemoryPool,
                                0x40ui64,
                                "UIInputHandler::UIMessagePadInput",
                                0i64,
                                1u);
                        if ( v29 )
                        {
                          v29[1].mNext = v29 + 1;
                          v29[2].mNext = v29 + 1;
                          v29->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                          LODWORD(v29[3].mNext) = -1;
                          v29[4].mNext = 0i64;
                          v29->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                          LODWORD(v29[5].mNext) = UI_HASH_BUTTON_BUTTON2_REPEAT_35;
                          HIDWORD(v29[5].mNext) = 0;
                          v29[6].mNext = (UFG::allocator::free_link *)-1i64;
                          LODWORD(v29[3].mNext) = 5;
                          v29->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                          LODWORD(v29[7].mNext) = 1065353216;
                          HIDWORD(v29[7].mNext) = controllerMask;
                          LODWORD(v29[3].mNext) = 6;
                          HIDWORD(v29[6].mNext) = 0;
                          v7 = (UFG::UIMessage *)v29;
                        }
                      }
                      else
                      {
                        v30 = UFG::ActionDef_UIButton2Released.mDataPerController[controllerIndex];
                        if ( v30 && v30->mActionTrue )
                        {
                          this->mState[controllerIndex][1] = UIINPUT_IDLE;
                          v31 = UFG::qMemoryPool::Allocate(
                                  &gScaleformMemoryPool,
                                  0x40ui64,
                                  "UIInputHandler::UIMessagePadInput",
                                  0i64,
                                  1u);
                          if ( v31 )
                          {
                            v31[1].mNext = v31 + 1;
                            v31[2].mNext = v31 + 1;
                            v31->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                            LODWORD(v31[3].mNext) = -1;
                            v31[4].mNext = 0i64;
                            v31->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                            LODWORD(v31[5].mNext) = UI_HASH_BUTTON_BUTTON2_RELEASED_35;
                            HIDWORD(v31[5].mNext) = 0;
                            v31[6].mNext = (UFG::allocator::free_link *)-1i64;
                            LODWORD(v31[3].mNext) = 5;
                            v31->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                            *(UFG::allocator::free_link **)((char *)&v31[6].mNext + 4) = 0i64;
                            HIDWORD(v31[7].mNext) = controllerMask;
                            LODWORD(v31[3].mNext) = 6;
                            v7 = (UFG::UIMessage *)v31;
                          }
                        }
                        else
                        {
                          v32 = UFG::ActionDef_UISelectPressed.mDataPerController[controllerIndex];
                          if ( v32 && v32->mActionTrue )
                          {
                            this->mState[controllerIndex][1] = UIINPUT_IDLE;
                            v33 = UFG::qMemoryPool::Allocate(
                                    &gScaleformMemoryPool,
                                    0x40ui64,
                                    "UIInputHandler::UIMessagePadInput",
                                    0i64,
                                    1u);
                            if ( v33 )
                            {
                              v33[1].mNext = v33 + 1;
                              v33[2].mNext = v33 + 1;
                              v33->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                              LODWORD(v33[3].mNext) = -1;
                              v33[4].mNext = 0i64;
                              v33->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                              LODWORD(v33[5].mNext) = UI_HASH_BUTTON_SELECT_PRESSED_35;
                              HIDWORD(v33[5].mNext) = 0;
                              v33[6].mNext = (UFG::allocator::free_link *)-1i64;
                              LODWORD(v33[3].mNext) = 5;
                              v33->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                              LODWORD(v33[7].mNext) = 1065353216;
                              HIDWORD(v33[7].mNext) = controllerMask;
                              LODWORD(v33[3].mNext) = 6;
                              HIDWORD(v33[6].mNext) = 0;
                              v7 = (UFG::UIMessage *)v33;
                            }
                          }
                          else
                          {
                            v34 = UFG::ActionDef_UISelectRepeat.mDataPerController[controllerIndex];
                            if ( v34 && v34->mActionTrue )
                            {
                              v35 = UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      0x40ui64,
                                      "UIInputHandler::UIMessagePadInput",
                                      0i64,
                                      1u);
                              if ( v35 )
                              {
                                v35[1].mNext = v35 + 1;
                                v35[2].mNext = v35 + 1;
                                v35->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                LODWORD(v35[3].mNext) = -1;
                                v35[4].mNext = 0i64;
                                v35->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                LODWORD(v35[5].mNext) = UI_HASH_BUTTON_SELECT_REPEAT_35;
                                HIDWORD(v35[5].mNext) = 0;
                                v35[6].mNext = (UFG::allocator::free_link *)-1i64;
                                LODWORD(v35[3].mNext) = 5;
                                v35->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                LODWORD(v35[7].mNext) = 1065353216;
                                HIDWORD(v35[7].mNext) = controllerMask;
                                LODWORD(v35[3].mNext) = 6;
                                HIDWORD(v35[6].mNext) = 0;
                                v7 = (UFG::UIMessage *)v35;
                              }
                            }
                            else
                            {
                              v36 = UFG::ActionDef_UISelectReleased.mDataPerController[controllerIndex];
                              if ( v36 && v36->mActionTrue )
                              {
                                this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                v37 = UFG::qMemoryPool::Allocate(
                                        &gScaleformMemoryPool,
                                        0x40ui64,
                                        "UIInputHandler::UIMessagePadInput",
                                        0i64,
                                        1u);
                                if ( v37 )
                                {
                                  v37[1].mNext = v37 + 1;
                                  v37[2].mNext = v37 + 1;
                                  v37->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                  LODWORD(v37[3].mNext) = -1;
                                  v37[4].mNext = 0i64;
                                  v37->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                  LODWORD(v37[5].mNext) = UI_HASH_BUTTON_SELECT_RELEASED_35;
                                  HIDWORD(v37[5].mNext) = 0;
                                  v37[6].mNext = (UFG::allocator::free_link *)-1i64;
                                  LODWORD(v37[3].mNext) = 5;
                                  v37->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                  *(UFG::allocator::free_link **)((char *)&v37[6].mNext + 4) = 0i64;
                                  HIDWORD(v37[7].mNext) = controllerMask;
                                  LODWORD(v37[3].mNext) = 6;
                                  v7 = (UFG::UIMessage *)v37;
                                }
                              }
                              else
                              {
                                v38 = UFG::ActionDef_UIStartPressed.mDataPerController[controllerIndex];
                                if ( v38 && v38->mActionTrue )
                                {
                                  this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                  v39 = UFG::qMemoryPool::Allocate(
                                          &gScaleformMemoryPool,
                                          0x40ui64,
                                          "UIInputHandler::UIMessagePadInput",
                                          0i64,
                                          1u);
                                  if ( v39 )
                                  {
                                    v39[1].mNext = v39 + 1;
                                    v39[2].mNext = v39 + 1;
                                    v39->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                    LODWORD(v39[3].mNext) = -1;
                                    v39[4].mNext = 0i64;
                                    v39->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                    LODWORD(v39[5].mNext) = UI_HASH_BUTTON_START_PRESSED_35;
                                    HIDWORD(v39[5].mNext) = 0;
                                    v39[6].mNext = (UFG::allocator::free_link *)-1i64;
                                    LODWORD(v39[3].mNext) = 5;
                                    v39->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                    LODWORD(v39[7].mNext) = 1065353216;
                                    HIDWORD(v39[7].mNext) = controllerMask;
                                    LODWORD(v39[3].mNext) = 6;
                                    HIDWORD(v39[6].mNext) = 0;
                                    v7 = (UFG::UIMessage *)v39;
                                  }
                                }
                                else
                                {
                                  v40 = UFG::ActionDef_UIStartRepeat.mDataPerController[controllerIndex];
                                  if ( v40 && v40->mActionTrue )
                                  {
                                    v41 = UFG::qMemoryPool::Allocate(
                                            &gScaleformMemoryPool,
                                            0x40ui64,
                                            "UIInputHandler::UIMessagePadInput",
                                            0i64,
                                            1u);
                                    if ( v41 )
                                    {
                                      v41[1].mNext = v41 + 1;
                                      v41[2].mNext = v41 + 1;
                                      v41->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                      LODWORD(v41[3].mNext) = -1;
                                      v41[4].mNext = 0i64;
                                      v41->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                      LODWORD(v41[5].mNext) = UI_HASH_BUTTON_START_REPEAT_35;
                                      HIDWORD(v41[5].mNext) = 0;
                                      v41[6].mNext = (UFG::allocator::free_link *)-1i64;
                                      LODWORD(v41[3].mNext) = 5;
                                      v41->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                      LODWORD(v41[7].mNext) = 1065353216;
                                      HIDWORD(v41[7].mNext) = controllerMask;
                                      LODWORD(v41[3].mNext) = 6;
                                      HIDWORD(v41[6].mNext) = 0;
                                      v7 = (UFG::UIMessage *)v41;
                                    }
                                  }
                                  else
                                  {
                                    v42 = UFG::ActionDef_UIStartReleased.mDataPerController[controllerIndex];
                                    if ( v42 && v42->mActionTrue )
                                    {
                                      this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                      v43 = UFG::qMemoryPool::Allocate(
                                              &gScaleformMemoryPool,
                                              0x40ui64,
                                              "UIInputHandler::UIMessagePadInput",
                                              0i64,
                                              1u);
                                      if ( v43 )
                                      {
                                        v43[1].mNext = v43 + 1;
                                        v43[2].mNext = v43 + 1;
                                        v43->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                        LODWORD(v43[3].mNext) = -1;
                                        v43[4].mNext = 0i64;
                                        v43->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                        LODWORD(v43[5].mNext) = UI_HASH_BUTTON_START_RELEASED_35;
                                        HIDWORD(v43[5].mNext) = 0;
                                        v43[6].mNext = (UFG::allocator::free_link *)-1i64;
                                        LODWORD(v43[3].mNext) = 5;
                                        v43->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                        *(UFG::allocator::free_link **)((char *)&v43[6].mNext + 4) = 0i64;
                                        HIDWORD(v43[7].mNext) = controllerMask;
                                        LODWORD(v43[3].mNext) = 6;
                                        v7 = (UFG::UIMessage *)v43;
                                      }
                                    }
                                    else
                                    {
                                      v44 = UFG::ActionDef_UIEscapePressed.mDataPerController[controllerIndex];
                                      if ( v44 && v44->mActionTrue )
                                      {
                                        v45 = UFG::UIScreenTextureManager::Instance();
                                        if ( (unsigned int)UFG::UIScreenTextureManager::GetGameState(v45) == 2
                                          || (v46 = UFG::UIScreenTextureManager::Instance(),
                                              (unsigned int)UFG::UIScreenTextureManager::GetGameState(v46) == 4)
                                          || (v47 = UFG::UIScreenTextureManager::Instance(),
                                              (unsigned int)UFG::UIScreenTextureManager::GetGameState(v47) == 32) )
                                        {
                                          this->mState[v5][1] = UIINPUT_IDLE;
                                          v49 = UFG::qMemoryPool::Allocate(
                                                  &gScaleformMemoryPool,
                                                  0x40ui64,
                                                  "UIInputHandler::UIMessagePadInput",
                                                  0i64,
                                                  1u);
                                          if ( v49 )
                                          {
                                            v49[1].mNext = v49 + 1;
                                            v49[2].mNext = v49 + 1;
                                            v49->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                            LODWORD(v49[3].mNext) = -1;
                                            v49[4].mNext = 0i64;
                                            v49->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                            LODWORD(v49[5].mNext) = UI_HASH_BUTTON_START_PRESSED_35;
                                            HIDWORD(v49[5].mNext) = 0;
                                            v49[6].mNext = (UFG::allocator::free_link *)-1i64;
                                            LODWORD(v49[3].mNext) = 5;
                                            v49->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                            LODWORD(v49[7].mNext) = 1065353216;
                                            HIDWORD(v49[7].mNext) = controllerMask;
                                            LODWORD(v49[3].mNext) = 6;
                                            HIDWORD(v49[6].mNext) = 0;
                                            v7 = (UFG::UIMessage *)v49;
                                          }
                                        }
                                        else
                                        {
                                          this->mState[v5][1] = UIINPUT_IDLE;
                                          v48 = UFG::qMemoryPool::Allocate(
                                                  &gScaleformMemoryPool,
                                                  0x40ui64,
                                                  "UIInputHandler::UIMessagePadInput",
                                                  0i64,
                                                  1u);
                                          if ( v48 )
                                          {
                                            v48[1].mNext = v48 + 1;
                                            v48[2].mNext = v48 + 1;
                                            v48->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                            LODWORD(v48[3].mNext) = -1;
                                            v48[4].mNext = 0i64;
                                            v48->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                            LODWORD(v48[5].mNext) = UI_HASH_BUTTON_BACK_PRESSED_35;
                                            HIDWORD(v48[5].mNext) = 0;
                                            v48[6].mNext = (UFG::allocator::free_link *)-1i64;
                                            LODWORD(v48[3].mNext) = 5;
                                            v48->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                            LODWORD(v48[7].mNext) = 1065353216;
                                            HIDWORD(v48[7].mNext) = controllerMask;
                                            LODWORD(v48[3].mNext) = 6;
                                            HIDWORD(v48[6].mNext) = 0;
                                            v7 = (UFG::UIMessage *)v48;
                                          }
                                        }
                                      }
                                      else
                                      {
                                        v50 = UFG::ActionDef_UIEscapeRepeat.mDataPerController[controllerIndex];
                                        if ( v50 && v50->mActionTrue )
                                        {
                                          v51 = UFG::UIScreenTextureManager::Instance();
                                          if ( (unsigned int)UFG::UIScreenTextureManager::GetGameState(v51) == 2
                                            || (v52 = UFG::UIScreenTextureManager::Instance(),
                                                (unsigned int)UFG::UIScreenTextureManager::GetGameState(v52) == 4)
                                            || (v53 = UFG::UIScreenTextureManager::Instance(),
                                                (unsigned int)UFG::UIScreenTextureManager::GetGameState(v53) == 32) )
                                          {
                                            v55 = UFG::qMemoryPool::Allocate(
                                                    &gScaleformMemoryPool,
                                                    0x40ui64,
                                                    "UIInputHandler::UIMessagePadInput",
                                                    0i64,
                                                    1u);
                                            if ( v55 )
                                            {
                                              v55[1].mNext = v55 + 1;
                                              v55[2].mNext = v55 + 1;
                                              v55->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                              LODWORD(v55[3].mNext) = -1;
                                              v55[4].mNext = 0i64;
                                              v55->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                              LODWORD(v55[5].mNext) = UI_HASH_BUTTON_START_REPEAT_35;
                                              HIDWORD(v55[5].mNext) = 0;
                                              v55[6].mNext = (UFG::allocator::free_link *)-1i64;
                                              LODWORD(v55[3].mNext) = 5;
                                              v55->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                              LODWORD(v55[7].mNext) = 1065353216;
                                              HIDWORD(v55[7].mNext) = controllerMask;
                                              LODWORD(v55[3].mNext) = 6;
                                              HIDWORD(v55[6].mNext) = 0;
                                              v7 = (UFG::UIMessage *)v55;
                                            }
                                          }
                                          else
                                          {
                                            v54 = UFG::qMemoryPool::Allocate(
                                                    &gScaleformMemoryPool,
                                                    0x40ui64,
                                                    "UIInputHandler::UIMessagePadInput",
                                                    0i64,
                                                    1u);
                                            if ( v54 )
                                            {
                                              v54[1].mNext = v54 + 1;
                                              v54[2].mNext = v54 + 1;
                                              v54->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                              LODWORD(v54[3].mNext) = -1;
                                              v54[4].mNext = 0i64;
                                              v54->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                              LODWORD(v54[5].mNext) = UI_HASH_BUTTON_BACK_REPEAT_35;
                                              HIDWORD(v54[5].mNext) = 0;
                                              v54[6].mNext = (UFG::allocator::free_link *)-1i64;
                                              LODWORD(v54[3].mNext) = 5;
                                              v54->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                              LODWORD(v54[7].mNext) = 1065353216;
                                              HIDWORD(v54[7].mNext) = controllerMask;
                                              LODWORD(v54[3].mNext) = 6;
                                              HIDWORD(v54[6].mNext) = 0;
                                              v7 = (UFG::UIMessage *)v54;
                                            }
                                          }
                                        }
                                        else
                                        {
                                          v56 = UFG::ActionDef_UIEscapeReleased.mDataPerController[controllerIndex];
                                          if ( v56 && v56->mActionTrue )
                                          {
                                            v57 = UFG::UIScreenTextureManager::Instance();
                                            if ( (unsigned int)UFG::UIScreenTextureManager::GetGameState(v57) == 2
                                              || (v58 = UFG::UIScreenTextureManager::Instance(),
                                                  (unsigned int)UFG::UIScreenTextureManager::GetGameState(v58) == 4)
                                              || (v59 = UFG::UIScreenTextureManager::Instance(),
                                                  (unsigned int)UFG::UIScreenTextureManager::GetGameState(v59) == 32) )
                                            {
                                              this->mState[v5][1] = UIINPUT_IDLE;
                                              v61 = UFG::qMemoryPool::Allocate(
                                                      &gScaleformMemoryPool,
                                                      0x40ui64,
                                                      "UIInputHandler::UIMessagePadInput",
                                                      0i64,
                                                      1u);
                                              if ( v61 )
                                              {
                                                v61[1].mNext = v61 + 1;
                                                v61[2].mNext = v61 + 1;
                                                v61->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                LODWORD(v61[3].mNext) = -1;
                                                v61[4].mNext = 0i64;
                                                v61->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                LODWORD(v61[5].mNext) = UI_HASH_BUTTON_START_RELEASED_35;
                                                HIDWORD(v61[5].mNext) = 0;
                                                v61[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                LODWORD(v61[3].mNext) = 5;
                                                v61->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                *(UFG::allocator::free_link **)((char *)&v61[6].mNext + 4) = 0i64;
                                                HIDWORD(v61[7].mNext) = controllerMask;
                                                LODWORD(v61[3].mNext) = 6;
                                                v7 = (UFG::UIMessage *)v61;
                                              }
                                            }
                                            else
                                            {
                                              this->mState[v5][1] = UIINPUT_IDLE;
                                              v60 = UFG::qMemoryPool::Allocate(
                                                      &gScaleformMemoryPool,
                                                      0x40ui64,
                                                      "UIInputHandler::UIMessagePadInput",
                                                      0i64,
                                                      1u);
                                              if ( v60 )
                                              {
                                                v60[1].mNext = v60 + 1;
                                                v60[2].mNext = v60 + 1;
                                                v60->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                LODWORD(v60[3].mNext) = -1;
                                                v60[4].mNext = 0i64;
                                                v60->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                LODWORD(v60[5].mNext) = UI_HASH_BUTTON_BACK_RELEASED_35;
                                                HIDWORD(v60[5].mNext) = 0;
                                                v60[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                LODWORD(v60[3].mNext) = 5;
                                                v60->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                *(UFG::allocator::free_link **)((char *)&v60[6].mNext + 4) = 0i64;
                                                HIDWORD(v60[7].mNext) = controllerMask;
                                                LODWORD(v60[3].mNext) = 6;
                                                v7 = (UFG::UIMessage *)v60;
                                              }
                                            }
                                          }
                                          else
                                          {
                                            v62 = UFG::ActionDef_UIL1Pressed.mDataPerController[controllerIndex];
                                            if ( v62 && v62->mActionTrue )
                                            {
                                              this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                              v63 = UFG::qMemoryPool::Allocate(
                                                      &gScaleformMemoryPool,
                                                      0x40ui64,
                                                      "UIInputHandler::UIMessagePadInput",
                                                      0i64,
                                                      1u);
                                              if ( v63 )
                                              {
                                                v63[1].mNext = v63 + 1;
                                                v63[2].mNext = v63 + 1;
                                                v63->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                LODWORD(v63[3].mNext) = -1;
                                                v63[4].mNext = 0i64;
                                                v63->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                LODWORD(v63[5].mNext) = UI_HASH_BUTTON_L1_PRESSED_35;
                                                HIDWORD(v63[5].mNext) = 0;
                                                v63[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                LODWORD(v63[3].mNext) = 5;
                                                v63->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                LODWORD(v63[7].mNext) = 1065353216;
                                                HIDWORD(v63[7].mNext) = controllerMask;
                                                LODWORD(v63[3].mNext) = 6;
                                                HIDWORD(v63[6].mNext) = 0;
                                                v7 = (UFG::UIMessage *)v63;
                                              }
                                            }
                                            else
                                            {
                                              v64 = UFG::ActionDef_UIL1Repeat.mDataPerController[controllerIndex];
                                              if ( v64 && v64->mActionTrue )
                                              {
                                                v65 = UFG::qMemoryPool::Allocate(
                                                        &gScaleformMemoryPool,
                                                        0x40ui64,
                                                        "UIInputHandler::UIMessagePadInput",
                                                        0i64,
                                                        1u);
                                                if ( v65 )
                                                {
                                                  v65[1].mNext = v65 + 1;
                                                  v65[2].mNext = v65 + 1;
                                                  v65->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                  LODWORD(v65[3].mNext) = -1;
                                                  v65[4].mNext = 0i64;
                                                  v65->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                  LODWORD(v65[5].mNext) = UI_HASH_BUTTON_L1_REPEAT_35;
                                                  HIDWORD(v65[5].mNext) = 0;
                                                  v65[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                  LODWORD(v65[3].mNext) = 5;
                                                  v65->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                  LODWORD(v65[7].mNext) = 1065353216;
                                                  HIDWORD(v65[7].mNext) = controllerMask;
                                                  LODWORD(v65[3].mNext) = 6;
                                                  HIDWORD(v65[6].mNext) = 0;
                                                  v7 = (UFG::UIMessage *)v65;
                                                }
                                              }
                                              else
                                              {
                                                v66 = UFG::ActionDef_UIL1Released.mDataPerController[controllerIndex];
                                                if ( v66 && v66->mActionTrue )
                                                {
                                                  this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                  v67 = UFG::qMemoryPool::Allocate(
                                                          &gScaleformMemoryPool,
                                                          0x40ui64,
                                                          "UIInputHandler::UIMessagePadInput",
                                                          0i64,
                                                          1u);
                                                  if ( v67 )
                                                  {
                                                    v67[1].mNext = v67 + 1;
                                                    v67[2].mNext = v67 + 1;
                                                    v67->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                    LODWORD(v67[3].mNext) = -1;
                                                    v67[4].mNext = 0i64;
                                                    v67->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                    LODWORD(v67[5].mNext) = UI_HASH_BUTTON_L1_RELEASED_35;
                                                    HIDWORD(v67[5].mNext) = 0;
                                                    v67[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                    LODWORD(v67[3].mNext) = 5;
                                                    v67->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                    *(UFG::allocator::free_link **)((char *)&v67[6].mNext + 4) = 0i64;
                                                    HIDWORD(v67[7].mNext) = controllerMask;
                                                    LODWORD(v67[3].mNext) = 6;
                                                    v7 = (UFG::UIMessage *)v67;
                                                  }
                                                }
                                                else
                                                {
                                                  v68 = UFG::ActionDef_UIL2Pressed.mDataPerController[controllerIndex];
                                                  if ( v68 && v68->mActionTrue )
                                                  {
                                                    this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                    v69 = UFG::qMemoryPool::Allocate(
                                                            &gScaleformMemoryPool,
                                                            0x40ui64,
                                                            "UIInputHandler::UIMessagePadInput",
                                                            0i64,
                                                            1u);
                                                    if ( v69 )
                                                    {
                                                      v69[1].mNext = v69 + 1;
                                                      v69[2].mNext = v69 + 1;
                                                      v69->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                      LODWORD(v69[3].mNext) = -1;
                                                      v69[4].mNext = 0i64;
                                                      v69->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                      LODWORD(v69[5].mNext) = UI_HASH_BUTTON_L2_PRESSED_35;
                                                      HIDWORD(v69[5].mNext) = 0;
                                                      v69[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                      LODWORD(v69[3].mNext) = 5;
                                                      v69->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                      LODWORD(v69[7].mNext) = 1065353216;
                                                      HIDWORD(v69[7].mNext) = controllerMask;
                                                      LODWORD(v69[3].mNext) = 6;
                                                      HIDWORD(v69[6].mNext) = 0;
                                                      v7 = (UFG::UIMessage *)v69;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    v70 = UFG::ActionDef_UIL2Repeat.mDataPerController[controllerIndex];
                                                    if ( v70 && v70->mActionTrue )
                                                    {
                                                      v71 = UFG::qMemoryPool::Allocate(
                                                              &gScaleformMemoryPool,
                                                              0x40ui64,
                                                              "UIInputHandler::UIMessagePadInput",
                                                              0i64,
                                                              1u);
                                                      if ( v71 )
                                                      {
                                                        v71[1].mNext = v71 + 1;
                                                        v71[2].mNext = v71 + 1;
                                                        v71->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                        LODWORD(v71[3].mNext) = -1;
                                                        v71[4].mNext = 0i64;
                                                        v71->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                        LODWORD(v71[5].mNext) = UI_HASH_BUTTON_L2_REPEAT_35;
                                                        HIDWORD(v71[5].mNext) = 0;
                                                        v71[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                        LODWORD(v71[3].mNext) = 5;
                                                        v71->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                        LODWORD(v71[7].mNext) = 1065353216;
                                                        HIDWORD(v71[7].mNext) = controllerMask;
                                                        LODWORD(v71[3].mNext) = 6;
                                                        HIDWORD(v71[6].mNext) = 0;
                                                        v7 = (UFG::UIMessage *)v71;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      v72 = UFG::ActionDef_UIL2Released.mDataPerController[controllerIndex];
                                                      if ( v72 && v72->mActionTrue )
                                                      {
                                                        this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                        v73 = UFG::qMemoryPool::Allocate(
                                                                &gScaleformMemoryPool,
                                                                0x40ui64,
                                                                "UIInputHandler::UIMessagePadInput",
                                                                0i64,
                                                                1u);
                                                        if ( v73 )
                                                        {
                                                          v73[1].mNext = v73 + 1;
                                                          v73[2].mNext = v73 + 1;
                                                          v73->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                          LODWORD(v73[3].mNext) = -1;
                                                          v73[4].mNext = 0i64;
                                                          v73->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                          LODWORD(v73[5].mNext) = UI_HASH_BUTTON_L2_RELEASED_35;
                                                          HIDWORD(v73[5].mNext) = 0;
                                                          v73[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                          LODWORD(v73[3].mNext) = 5;
                                                          v73->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                          *(UFG::allocator::free_link **)((char *)&v73[6].mNext + 4) = 0i64;
                                                          HIDWORD(v73[7].mNext) = controllerMask;
                                                          LODWORD(v73[3].mNext) = 6;
                                                          v7 = (UFG::UIMessage *)v73;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        v74 = UFG::ActionDef_UIL3Pressed.mDataPerController[controllerIndex];
                                                        if ( v74 && v74->mActionTrue )
                                                        {
                                                          this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                          v75 = UFG::qMemoryPool::Allocate(
                                                                  &gScaleformMemoryPool,
                                                                  0x40ui64,
                                                                  "UIInputHandler::UIMessagePadInput",
                                                                  0i64,
                                                                  1u);
                                                          if ( v75 )
                                                          {
                                                            v75[1].mNext = v75 + 1;
                                                            v75[2].mNext = v75 + 1;
                                                            v75->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                            LODWORD(v75[3].mNext) = -1;
                                                            v75[4].mNext = 0i64;
                                                            v75->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                            LODWORD(v75[5].mNext) = UI_HASH_BUTTON_L3_PRESSED_35;
                                                            HIDWORD(v75[5].mNext) = 0;
                                                            v75[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                            LODWORD(v75[3].mNext) = 5;
                                                            v75->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                            LODWORD(v75[7].mNext) = 1065353216;
                                                            HIDWORD(v75[7].mNext) = controllerMask;
                                                            LODWORD(v75[3].mNext) = 6;
                                                            HIDWORD(v75[6].mNext) = 0;
                                                            v7 = (UFG::UIMessage *)v75;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          v76 = UFG::ActionDef_UIL3Repeat.mDataPerController[controllerIndex];
                                                          if ( v76 && v76->mActionTrue )
                                                          {
                                                            v77 = UFG::qMemoryPool::Allocate(
                                                                    &gScaleformMemoryPool,
                                                                    0x40ui64,
                                                                    "UIInputHandler::UIMessagePadInput",
                                                                    0i64,
                                                                    1u);
                                                            if ( v77 )
                                                            {
                                                              v77[1].mNext = v77 + 1;
                                                              v77[2].mNext = v77 + 1;
                                                              v77->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                              LODWORD(v77[3].mNext) = -1;
                                                              v77[4].mNext = 0i64;
                                                              v77->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                              LODWORD(v77[5].mNext) = UI_HASH_BUTTON_L3_REPEAT_35;
                                                              HIDWORD(v77[5].mNext) = 0;
                                                              v77[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                              LODWORD(v77[3].mNext) = 5;
                                                              v77->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                              LODWORD(v77[7].mNext) = 1065353216;
                                                              HIDWORD(v77[7].mNext) = controllerMask;
                                                              LODWORD(v77[3].mNext) = 6;
                                                              HIDWORD(v77[6].mNext) = 0;
                                                              v7 = (UFG::UIMessage *)v77;
                                                            }
                                                          }
                                                          else
                                                          {
                                                            v78 = UFG::ActionDef_UIL3Released.mDataPerController[controllerIndex];
                                                            if ( v78 && v78->mActionTrue )
                                                            {
                                                              this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                              v79 = UFG::qMemoryPool::Allocate(
                                                                      &gScaleformMemoryPool,
                                                                      0x40ui64,
                                                                      "UIInputHandler::UIMessagePadInput",
                                                                      0i64,
                                                                      1u);
                                                              if ( v79 )
                                                              {
                                                                v79[1].mNext = v79 + 1;
                                                                v79[2].mNext = v79 + 1;
                                                                v79->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                LODWORD(v79[3].mNext) = -1;
                                                                v79[4].mNext = 0i64;
                                                                v79->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                LODWORD(v79[5].mNext) = UI_HASH_BUTTON_L3_RELEASED_35;
                                                                HIDWORD(v79[5].mNext) = 0;
                                                                v79[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                LODWORD(v79[3].mNext) = 5;
                                                                v79->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                *(UFG::allocator::free_link **)((char *)&v79[6].mNext + 4) = 0i64;
                                                                HIDWORD(v79[7].mNext) = controllerMask;
                                                                LODWORD(v79[3].mNext) = 6;
                                                                v7 = (UFG::UIMessage *)v79;
                                                              }
                                                            }
                                                            else
                                                            {
                                                              v80 = UFG::ActionDef_UIR1Pressed.mDataPerController[controllerIndex];
                                                              if ( v80 && v80->mActionTrue )
                                                              {
                                                                this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                                v81 = UFG::qMemoryPool::Allocate(
                                                                        &gScaleformMemoryPool,
                                                                        0x40ui64,
                                                                        "UIInputHandler::UIMessagePadInput",
                                                                        0i64,
                                                                        1u);
                                                                if ( v81 )
                                                                {
                                                                  v81[1].mNext = v81 + 1;
                                                                  v81[2].mNext = v81 + 1;
                                                                  v81->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                  LODWORD(v81[3].mNext) = -1;
                                                                  v81[4].mNext = 0i64;
                                                                  v81->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                  LODWORD(v81[5].mNext) = UI_HASH_BUTTON_R1_PRESSED_35;
                                                                  HIDWORD(v81[5].mNext) = 0;
                                                                  v81[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                  LODWORD(v81[3].mNext) = 5;
                                                                  v81->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                  LODWORD(v81[7].mNext) = 1065353216;
                                                                  HIDWORD(v81[7].mNext) = controllerMask;
                                                                  LODWORD(v81[3].mNext) = 6;
                                                                  HIDWORD(v81[6].mNext) = 0;
                                                                  v7 = (UFG::UIMessage *)v81;
                                                                }
                                                              }
                                                              else
                                                              {
                                                                v82 = UFG::ActionDef_UIR1Repeat.mDataPerController[controllerIndex];
                                                                if ( v82 && v82->mActionTrue )
                                                                {
                                                                  v83 = UFG::qMemoryPool::Allocate(
                                                                          &gScaleformMemoryPool,
                                                                          0x40ui64,
                                                                          "UIInputHandler::UIMessagePadInput",
                                                                          0i64,
                                                                          1u);
                                                                  if ( v83 )
                                                                  {
                                                                    v83[1].mNext = v83 + 1;
                                                                    v83[2].mNext = v83 + 1;
                                                                    v83->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                    LODWORD(v83[3].mNext) = -1;
                                                                    v83[4].mNext = 0i64;
                                                                    v83->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                    LODWORD(v83[5].mNext) = UI_HASH_BUTTON_R1_REPEAT_35;
                                                                    HIDWORD(v83[5].mNext) = 0;
                                                                    v83[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                    LODWORD(v83[3].mNext) = 5;
                                                                    v83->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                    LODWORD(v83[7].mNext) = 1065353216;
                                                                    HIDWORD(v83[7].mNext) = controllerMask;
                                                                    LODWORD(v83[3].mNext) = 6;
                                                                    HIDWORD(v83[6].mNext) = 0;
                                                                    v7 = (UFG::UIMessage *)v83;
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  v84 = UFG::ActionDef_UIR1Released.mDataPerController[controllerIndex];
                                                                  if ( v84 && v84->mActionTrue )
                                                                  {
                                                                    this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                                    v85 = UFG::qMemoryPool::Allocate(
                                                                            &gScaleformMemoryPool,
                                                                            0x40ui64,
                                                                            "UIInputHandler::UIMessagePadInput",
                                                                            0i64,
                                                                            1u);
                                                                    if ( v85 )
                                                                    {
                                                                      v85[1].mNext = v85 + 1;
                                                                      v85[2].mNext = v85 + 1;
                                                                      v85->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                      LODWORD(v85[3].mNext) = -1;
                                                                      v85[4].mNext = 0i64;
                                                                      v85->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                      LODWORD(v85[5].mNext) = UI_HASH_BUTTON_R1_RELEASED_35;
                                                                      HIDWORD(v85[5].mNext) = 0;
                                                                      v85[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                      LODWORD(v85[3].mNext) = 5;
                                                                      v85->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                      *(UFG::allocator::free_link **)((char *)&v85[6].mNext + 4) = 0i64;
                                                                      HIDWORD(v85[7].mNext) = controllerMask;
                                                                      LODWORD(v85[3].mNext) = 6;
                                                                      v7 = (UFG::UIMessage *)v85;
                                                                    }
                                                                  }
                                                                  else
                                                                  {
                                                                    v86 = UFG::ActionDef_UIR2Pressed.mDataPerController[controllerIndex];
                                                                    if ( v86 && v86->mActionTrue )
                                                                    {
                                                                      this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                                      v87 = UFG::qMemoryPool::Allocate(
                                                                              &gScaleformMemoryPool,
                                                                              0x40ui64,
                                                                              "UIInputHandler::UIMessagePadInput",
                                                                              0i64,
                                                                              1u);
                                                                      if ( v87 )
                                                                      {
                                                                        v87[1].mNext = v87 + 1;
                                                                        v87[2].mNext = v87 + 1;
                                                                        v87->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                        LODWORD(v87[3].mNext) = -1;
                                                                        v87[4].mNext = 0i64;
                                                                        v87->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                        LODWORD(v87[5].mNext) = UI_HASH_BUTTON_R2_PRESSED_35;
                                                                        HIDWORD(v87[5].mNext) = 0;
                                                                        v87[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                        LODWORD(v87[3].mNext) = 5;
                                                                        v87->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                        LODWORD(v87[7].mNext) = 1065353216;
                                                                        HIDWORD(v87[7].mNext) = controllerMask;
                                                                        LODWORD(v87[3].mNext) = 6;
                                                                        HIDWORD(v87[6].mNext) = 0;
                                                                        v7 = (UFG::UIMessage *)v87;
                                                                      }
                                                                    }
                                                                    else
                                                                    {
                                                                      v88 = UFG::ActionDef_UIR2Repeat.mDataPerController[controllerIndex];
                                                                      if ( v88 && v88->mActionTrue )
                                                                      {
                                                                        v89 = UFG::qMemoryPool::Allocate(
                                                                                &gScaleformMemoryPool,
                                                                                0x40ui64,
                                                                                "UIInputHandler::UIMessagePadInput",
                                                                                0i64,
                                                                                1u);
                                                                        if ( v89 )
                                                                        {
                                                                          v89[1].mNext = v89 + 1;
                                                                          v89[2].mNext = v89 + 1;
                                                                          v89->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                          LODWORD(v89[3].mNext) = -1;
                                                                          v89[4].mNext = 0i64;
                                                                          v89->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                          LODWORD(v89[5].mNext) = UI_HASH_BUTTON_R2_REPEAT_35;
                                                                          HIDWORD(v89[5].mNext) = 0;
                                                                          v89[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                          LODWORD(v89[3].mNext) = 5;
                                                                          v89->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                          LODWORD(v89[7].mNext) = 1065353216;
                                                                          HIDWORD(v89[7].mNext) = controllerMask;
                                                                          LODWORD(v89[3].mNext) = 6;
                                                                          HIDWORD(v89[6].mNext) = 0;
                                                                          v7 = (UFG::UIMessage *)v89;
                                                                        }
                                                                      }
                                                                      else
                                                                      {
                                                                        v90 = UFG::ActionDef_UIR2Released.mDataPerController[controllerIndex];
                                                                        if ( v90 && v90->mActionTrue )
                                                                        {
                                                                          this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                                          v91 = UFG::qMemoryPool::Allocate(
                                                                                  &gScaleformMemoryPool,
                                                                                  0x40ui64,
                                                                                  "UIInputHandler::UIMessagePadInput",
                                                                                  0i64,
                                                                                  1u);
                                                                          if ( v91 )
                                                                          {
                                                                            v91[1].mNext = v91 + 1;
                                                                            v91[2].mNext = v91 + 1;
                                                                            v91->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                            LODWORD(v91[3].mNext) = -1;
                                                                            v91[4].mNext = 0i64;
                                                                            v91->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                            LODWORD(v91[5].mNext) = UI_HASH_BUTTON_R2_RELEASED_35;
                                                                            HIDWORD(v91[5].mNext) = 0;
                                                                            v91[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                            LODWORD(v91[3].mNext) = 5;
                                                                            v91->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                            *(UFG::allocator::free_link **)((char *)&v91[6].mNext + 4) = 0i64;
                                                                            HIDWORD(v91[7].mNext) = controllerMask;
                                                                            LODWORD(v91[3].mNext) = 6;
                                                                            v7 = (UFG::UIMessage *)v91;
                                                                          }
                                                                        }
                                                                        else
                                                                        {
                                                                          v92 = UFG::ActionDef_UIR3Pressed.mDataPerController[controllerIndex];
                                                                          if ( v92 && v92->mActionTrue )
                                                                          {
                                                                            this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                                            v93 = UFG::qMemoryPool::Allocate(
                                                                                    &gScaleformMemoryPool,
                                                                                    0x40ui64,
                                                                                    "UIInputHandler::UIMessagePadInput",
                                                                                    0i64,
                                                                                    1u);
                                                                            if ( v93 )
                                                                            {
                                                                              v93[1].mNext = v93 + 1;
                                                                              v93[2].mNext = v93 + 1;
                                                                              v93->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                              LODWORD(v93[3].mNext) = -1;
                                                                              v93[4].mNext = 0i64;
                                                                              v93->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                              LODWORD(v93[5].mNext) = UI_HASH_BUTTON_R3_PRESSED_35;
                                                                              HIDWORD(v93[5].mNext) = 0;
                                                                              v93[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                              LODWORD(v93[3].mNext) = 5;
                                                                              v93->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                              LODWORD(v93[7].mNext) = 1065353216;
                                                                              HIDWORD(v93[7].mNext) = controllerMask;
                                                                              LODWORD(v93[3].mNext) = 6;
                                                                              HIDWORD(v93[6].mNext) = 0;
                                                                              v7 = (UFG::UIMessage *)v93;
                                                                            }
                                                                          }
                                                                          else
                                                                          {
                                                                            v94 = UFG::ActionDef_UIR3Repeat.mDataPerController[controllerIndex];
                                                                            if ( v94 && v94->mActionTrue )
                                                                            {
                                                                              v95 = UFG::qMemoryPool::Allocate(
                                                                                      &gScaleformMemoryPool,
                                                                                      0x40ui64,
                                                                                      "UIInputHandler::UIMessagePadInput",
                                                                                      0i64,
                                                                                      1u);
                                                                              if ( v95 )
                                                                              {
                                                                                v95[1].mNext = v95 + 1;
                                                                                v95[2].mNext = v95 + 1;
                                                                                v95->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                                LODWORD(v95[3].mNext) = -1;
                                                                                v95[4].mNext = 0i64;
                                                                                v95->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                                LODWORD(v95[5].mNext) = UI_HASH_BUTTON_R3_REPEAT_35;
                                                                                HIDWORD(v95[5].mNext) = 0;
                                                                                v95[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                                LODWORD(v95[3].mNext) = 5;
                                                                                v95->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                                LODWORD(v95[7].mNext) = 1065353216;
                                                                                HIDWORD(v95[7].mNext) = controllerMask;
                                                                                LODWORD(v95[3].mNext) = 6;
                                                                                HIDWORD(v95[6].mNext) = 0;
                                                                                v7 = (UFG::UIMessage *)v95;
                                                                              }
                                                                            }
                                                                            else
                                                                            {
                                                                              v96 = UFG::ActionDef_UIR3Released.mDataPerController[controllerIndex];
                                                                              if ( v96 )
                                                                              {
                                                                                if ( v96->mActionTrue )
                                                                                {
                                                                                  this->mState[controllerIndex][1] = UIINPUT_IDLE;
                                                                                  v97 = UFG::qMemoryPool::Allocate(
                                                                                          &gScaleformMemoryPool,
                                                                                          0x40ui64,
                                                                                          "UIInputHandler::UIMessagePadInput",
                                                                                          0i64,
                                                                                          1u);
                                                                                  if ( v97 )
                                                                                  {
                                                                                    v97[1].mNext = v97 + 1;
                                                                                    v97[2].mNext = v97 + 1;
                                                                                    v97->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                                    LODWORD(v97[3].mNext) = -1;
                                                                                    v97[4].mNext = 0i64;
                                                                                    v97->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                                    LODWORD(v97[5].mNext) = UI_HASH_BUTTON_R3_RELEASED_35;
                                                                                    HIDWORD(v97[5].mNext) = 0;
                                                                                    v97[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                                    LODWORD(v97[3].mNext) = 5;
                                                                                    v97->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                                    *(UFG::allocator::free_link **)((char *)&v97[6].mNext + 4) = 0i64;
                                                                                    HIDWORD(v97[7].mNext) = controllerMask;
                                                                                    LODWORD(v97[3].mNext) = 6;
                                                                                    v7 = (UFG::UIMessage *)v97;
                                                                                  }
                                                                                }
                                                                              }
                                                                            }
                                                                          }
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  UFG::UIInputHandler::update(this, elapsed, v7, v5, UIINPUT_BUTTON);
}

// File Line: 552
// RVA: 0xA32550
void __fastcall UFG::UIInputHandler::update(
        UFG::UIInputHandler *this,
        float elapsed,
        UFG::UIMessage *msg,
        int controllerIndex,
        UFG::eInputHandlerType type)
{
  __int64 v6; // rcx
  __int64 v7; // r10
  UFG::eUIInputHandlerState v8; // r9d
  __int32 v9; // r9d
  __int64 v10; // rax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float mMinRepeatDelay; // xmm1_4
  __int64 v14; // r9
  float v15; // xmm1_4
  float mFirstDelay; // eax

  if ( !msg )
    return;
  v6 = controllerIndex;
  v7 = (int)type + 2i64 * controllerIndex;
  v8 = this->mState[0][v7];
  if ( v8 == UIINPUT_IDLE )
  {
    mFirstDelay = this->mFirstDelay;
    this->mState[0][v7] = UIINPUT_FIRST_REPEAT;
    this->mCurrentDelay[v6][type] = mFirstDelay;
    UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, msg);
    return;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v14 = (int)type + 2 * v6;
    v15 = this->mCurrentDelay[0][v14] - elapsed;
    this->mCurrentDelay[0][v14] = v15;
    if ( v15 < 0.0 )
    {
      this->mState[0][v7] = UIINPUT_REPEATED_INPUT;
      this->mCurrentDelay[0][v14] = this->mMaxRepeatDelay;
      this->mRepeatDelay[v6] = this->mMaxRepeatDelay;
      UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, msg);
      return;
    }
    goto LABEL_11;
  }
  if ( v9 != 1
    || (v10 = (int)type + 2 * v6,
        v11 = this->mCurrentDelay[0][v10] - elapsed,
        this->mCurrentDelay[0][v10] = v11,
        v11 >= 0.0) )
  {
LABEL_11:
    msg->vfptr->__vecDelDtor(msg, 1i64);
    return;
  }
  v12 = this->mRepeatDelay[v6] - this->mRepeatSpeed;
  this->mRepeatDelay[v6] = v12;
  mMinRepeatDelay = this->mMinRepeatDelay;
  if ( v12 < mMinRepeatDelay )
  {
    this->mRepeatDelay[v6] = mMinRepeatDelay;
    v12 = mMinRepeatDelay;
  }
  this->mCurrentDelay[0][v10] = v12;
  UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, msg);
}

// File Line: 617
// RVA: 0xA2F3F0
void __fastcall UFG::UIInputHandler::handleKeyboardInput(UFG::UIInputHandler *this, UFG::Event *msg)
{
  int mUserData1; // ebx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  UFG::allocator::free_link *v5; // rax

  mUserData1 = msg->mUserData1;
  if ( LODWORD(msg->mUserData0) == 256 )
  {
    v3 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessageKeyboardInput", 0i64, 1u);
    v4 = v3;
    if ( v3 )
    {
      v5 = v3 + 1;
      v5->mNext = v5;
      v5[1].mNext = v5;
      v4->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
      LODWORD(v4[3].mNext) = -1;
      v4[4].mNext = 0i64;
      v4->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
      v4[5].mNext = (UFG::allocator::free_link *)UI_HASH_KEYBOARD_INPUT_35;
      v4[6].mNext = (UFG::allocator::free_link *)-1i64;
      LODWORD(v4[3].mNext) = 5;
      v4->mNext = (UFG::allocator::free_link *)&UFG::UIMessageKeyboardInput::`vftable;
      LOBYTE(v4[7].mNext) = mUserData1;
      HIDWORD(v4[7].mNext) = 15;
      LODWORD(v4[3].mNext) = 6;
      HIDWORD(v4[6].mNext) = 2;
    }
    else
    {
      v4 = 0i64;
    }
    if ( v4 )
      UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, (UFG::UIMessage *)v4);
  }
}

// File Line: 640
// RVA: 0xA2E040
void __fastcall UFG::UIInputHandler::handleControllerDisconnect(UFG::UIInputHandler *this, UFG::Event *msg)
{
  UFG::UIScreenManagerBase::queueMessage(
    UFG::UIScreenManager::s_instance,
    UI_HASH_ACTIVE_CONTROLLER_DISCONNECTED_52,
    0xFFFFFFFF);
}

// File Line: 646
// RVA: 0xA2E060
void __fastcall UFG::UIInputHandler::handleControllerReconnect(UFG::UIInputHandler *this, UFG::Event *msg)
{
  UFG::UIScreenManagerBase::queueMessage(
    UFG::UIScreenManager::s_instance,
    UI_HASH_ACTIVE_CONTROLLER_RECONNECTED_52,
    0xFFFFFFFF);
}

// File Line: 652
// RVA: 0xA2F780
void __fastcall UFG::UIInputHandler::handleMouseInput(UFG::UIInputHandler *this, UFG::Event *msg)
{
  int vfptr_high; // ebx
  int rawY; // edi
  int v5; // esi
  int v6; // ebp
  int vfptr; // eax
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rdx
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rax
  unsigned int v23; // r15d
  UFG::allocator::free_link *v24; // rax
  UFG::allocator::free_link *v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // [rsp+88h] [rbp+10h] BYREF
  UFG::qVector2 v29; // [rsp+90h] [rbp+18h] BYREF

  UFG::UIScreenManagerBase::getViewportOffsetAndScale(UFG::UIScreenManager::s_instance, (UFG::qVector2 *)&v28, &v29);
  vfptr_high = HIDWORD(msg[1].vfptr);
  rawY = (int)msg[1].mPrev;
  v5 = (int)(float)((float)((float)vfptr_high - *(float *)&v28) / v29.x);
  v6 = (int)(float)((float)((float)rawY - *((float *)&v28 + 1)) / v29.y);
  vfptr = (int)msg[1].vfptr;
  if ( vfptr != 512 )
  {
    switch ( vfptr )
    {
      case 513:
        v11 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v9 = v11;
        v28 = v11;
        if ( v11 )
        {
          v12 = v11 + 1;
          v12->mNext = v12;
          v12[1].mNext = v12;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
          LODWORD(v9[3].mNext) = -1;
          v9[4].mNext = 0i64;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
          v9[5].mNext = (UFG::allocator::free_link *)UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_35;
          v9[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v9[3].mNext) = 5;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessageMouseInput::`vftable;
          LODWORD(v9[7].mNext) = v5;
          HIDWORD(v9[7].mNext) = v6;
          LODWORD(v9[8].mNext) = 0;
          HIDWORD(v9[8].mNext) = vfptr_high;
          LODWORD(v9[9].mNext) = rawY;
          LODWORD(v9[3].mNext) = 6;
          HIDWORD(v9[6].mNext) = 3;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      case 514:
        v13 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v28 = v13;
        if ( v13 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v13,
            UI_HASH_MOUSE_BUTTON_LEFT_RELEASED_35,
            v5,
            v6,
            vfptr_high,
            rawY,
            0);
          v9 = v14;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      case 516:
        v15 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v28 = v15;
        if ( v15 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v15,
            UI_HASH_MOUSE_BUTTON_RIGHT_PRESSED_35,
            v5,
            v6,
            vfptr_high,
            rawY,
            0);
          v9 = v16;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      case 517:
        v17 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v28 = v17;
        if ( v17 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v17,
            UI_HASH_MOUSE_BUTTON_RIGHT_RELEASED_35,
            v5,
            v6,
            vfptr_high,
            rawY,
            0);
          v9 = v18;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      case 519:
        v19 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v28 = v19;
        if ( v19 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v19,
            UI_HASH_MOUSE_BUTTON_MIDDLE_PRESSED_35,
            v5,
            v6,
            vfptr_high,
            rawY,
            0);
          v9 = v20;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      case 520:
        v21 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v28 = v21;
        if ( v21 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v21,
            UI_HASH_MOUSE_BUTTON_MIDDLE_RELEASED_35,
            v5,
            v6,
            vfptr_high,
            rawY,
            0);
          v9 = v22;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      case 523:
        v23 = UI_HASH_MOUSE_BUTTON_5_PRESSED_35;
        if ( HIDWORD(msg[1].mPrev) == 5 )
          v23 = UI_HASH_MOUSE_BUTTON_4_PRESSED_35;
        v24 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v28 = v24;
        if ( v24 )
        {
LABEL_35:
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v24,
            v23,
            v5,
            v6,
            vfptr_high,
            rawY,
            0);
          v9 = v25;
          break;
        }
        v9 = 0i64;
        break;
      case 524:
        v23 = UI_HASH_MOUSE_BUTTON_5_RELEASED_35;
        if ( HIDWORD(msg[1].mPrev) == 5 )
          v23 = UI_HASH_MOUSE_BUTTON_4_RELEASED_35;
        v24 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v28 = v24;
        if ( v24 )
          goto LABEL_35;
        v9 = 0i64;
        break;
      case 522:
        v26 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v28 = v26;
        if ( v26 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v26,
            UI_HASH_MOUSE_WHEEL_SCROLL_35,
            v5,
            v6,
            vfptr_high,
            rawY,
            (int)msg[1].mNext);
          v9 = v27;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      default:
        return;
    }
LABEL_46:
    if ( v9 )
      UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManager::s_instance, (UFG::UIMessage *)v9);
    return;
  }
  if ( gOldMouseX != vfptr_high || gOldMouseY != rawY )
  {
    gOldMouseX = HIDWORD(msg[1].vfptr);
    gOldMouseY = rawY;
    v8 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x50ui64, "UIInputHandler::UIMessageMouseInput", 0i64, 1u);
    v9 = v8;
    v28 = v8;
    if ( v8 )
    {
      v10 = v8 + 1;
      v10->mNext = v10;
      v10[1].mNext = v10;
      v9->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
      LODWORD(v9[3].mNext) = -1;
      v9[4].mNext = 0i64;
      v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
      v9[5].mNext = (UFG::allocator::free_link *)UI_HASH_MOUSE_MOVE_35;
      v9[6].mNext = (UFG::allocator::free_link *)-1i64;
      LODWORD(v9[3].mNext) = 5;
      v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessageMouseInput::`vftable;
      LODWORD(v9[7].mNext) = v5;
      HIDWORD(v9[7].mNext) = v6;
      LODWORD(v9[8].mNext) = 0;
      HIDWORD(v9[8].mNext) = vfptr_high;
      LODWORD(v9[9].mNext) = rawY;
      LODWORD(v9[3].mNext) = 6;
      HIDWORD(v9[6].mNext) = 3;
    }
    else
    {
      v9 = 0i64;
    }
    goto LABEL_46;
  }
}

