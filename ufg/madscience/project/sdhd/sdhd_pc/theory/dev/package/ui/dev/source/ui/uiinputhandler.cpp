// File Line: 25
// RVA: 0x15ABE60
__int64 UFG::_dynamic_initializer_for__gUIScreenTextInputChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gUIScreenTextInputChannel,
    "UIScreenTextInput",
    "\tThis gets the keyboard input events to the UI.\n\t\t mUserData0 = msg Type     mUserData1 = msg Data\n");
  return atexit(UFG::_dynamic_atexit_destructor_for__gUIScreenTextInputChannel__);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gUIScreenMouseInputChannel__);
}

// File Line: 32
// RVA: 0x15ABDB0
__int64 UFG::_dynamic_initializer_for__gUIControllerDisconnected__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gUIControllerDisconnected,
    "UIControllerDisconnected",
    "\tHandles controller disconnected.\n\t\t\n");
  return atexit(UFG::_dynamic_atexit_destructor_for__gUIControllerDisconnected__);
}

// File Line: 36
// RVA: 0x15ABDE0
__int64 UFG::_dynamic_initializer_for__gUIControllerReconnected__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gUIControllerReconnected,
    "UIControllerReconnected",
    "\tHandles controller reconnected.\n\t\t\n");
  return atexit(UFG::_dynamic_atexit_destructor_for__gUIControllerReconnected__);
}

// File Line: 76
// RVA: 0xA23300
void __fastcall UFG::UIInputHandler::UIInputHandler(UFG::UIInputHandler *this)
{
  float v1; // xmm0_4
  UFG::UIInputHandler *v2; // rbx
  unsigned int *v3; // rdx
  char *v4; // rax
  signed __int64 v5; // r8
  UFG::UIInputHandler *v6; // [rsp+30h] [rbp-18h]
  void (__fastcall *v7)(UFG::UIInputHandler *, UFG::Event *); // [rsp+38h] [rbp-10h]

  v1 = UFG::gUIInputHandlerAnalogStickDeadZone;
  v2 = this;
  this->mFirstDelay = 0.40000001;
  this->mMaxRepeatDelay = 0.2;
  this->mMinRepeatDelay = 0.050000001;
  this->mAnalogDeadZone = v1;
  this->mRepeatSpeed = 0.015;
  v3 = this->mLastAnalogValue;
  v4 = (char *)&this->mRightAnalogStick[0].y;
  v5 = 5i64;
  do
  {
    *(v3 - 25) = 0;
    *(_QWORD *)(v4 - 44) = 0i64;
    *(_QWORD *)(v4 - 4) = 0i64;
    *v3 = 0;
    *((_QWORD *)v4 - 18) = 0i64;
    *((_QWORD *)v4 - 13) = 0i64;
    v4 += 8;
    ++v3;
    --v5;
  }
  while ( v5 );
  v6 = this;
  v7 = UFG::UIInputHandler::handleKeyboardInput;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v6,
    UFG::gUIScreenTextInputChannel.mUID,
    UFG::gUIScreenTextInputChannel.mName,
    0);
  v7 = UFG::UIInputHandler::handleMouseInput;
  v6 = v2;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v6,
    UFG::gUIScreenMouseInputChannel.mUID,
    UFG::gUIScreenMouseInputChannel.mName,
    0);
  v7 = UFG::UIInputHandler::handleControllerDisconnect;
  v6 = v2;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v6,
    UFG::gUIControllerDisconnected.mUID,
    UFG::gUIControllerDisconnected.mName,
    0);
  v7 = UFG::UIInputHandler::handleControllerReconnect;
  v6 = v2;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v6,
    UFG::gUIControllerReconnected.mUID,
    UFG::gUIControllerReconnected.mName,
    0);
}

// File Line: 102
// RVA: 0xA23C10
void __fastcall UFG::UIInputHandler::~UIInputHandler(UFG::UIInputHandler *this)
{
  UFG::UIInputHandler *v1; // rbx
  UFG::UIInputHandler *v2; // [rsp+20h] [rbp-18h]
  void (__fastcall *v3)(UFG::UIInputHandler *, UFG::Event *); // [rsp+28h] [rbp-10h]

  v1 = this;
  v2 = this;
  v3 = UFG::UIInputHandler::handleMouseInput;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
    UFG::gUIScreenMouseInputChannel.mUID);
  v3 = UFG::UIInputHandler::handleKeyboardInput;
  v2 = v1;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
    UFG::gUIScreenTextInputChannel.mUID);
  v3 = UFG::UIInputHandler::handleControllerDisconnect;
  v2 = v1;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
    UFG::gUIControllerDisconnected.mUID);
  v3 = UFG::UIInputHandler::handleControllerReconnect;
  v2 = v1;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
    UFG::gUIControllerReconnected.mUID);
}

// File Line: 130
// RVA: 0xA2AE00
signed __int64 __fastcall UFG::UIInputHandler::getControllerIndex(UFG::UIScreen::ControllerMask controllerMask)
{
  signed __int64 result; // rax

  switch ( controllerMask )
  {
    case 1u:
      return 0i64;
    case 2u:
      return 1i64;
    case 4u:
      return 2i64;
  }
  result = 0xFFFFFFFFi64;
  if ( controllerMask == 8 )
    result = 3i64;
  return result;
}

// File Line: 152
// RVA: 0xA2ED20
void __fastcall UFG::UIInputHandler::handleInput(UFG::UIInputHandler *this, float elapsed)
{
  UFG::UIInputHandler *v2; // rbp
  unsigned int v3; // esi
  float *v4; // rbx
  signed __int64 v5; // r12
  signed __int64 v6; // r14
  signed __int64 v7; // r15
  signed int v8; // edi
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

  v2 = this;
  v3 = 0;
  v4 = &this->mRightAnalogStick[0].y;
  v5 = (char *)&UFG::ActionDef_UILeftThumbstick - (char *)this;
  v6 = (char *)&UFG::ActionDef_UIRightThumbstick - (char *)this;
  v7 = -184i64 - (_QWORD)this;
  do
  {
    if ( *(UFG::Controller **)((char *)UFG::gInputSystem->mControllers + (_QWORD)v4 + v7)
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
      UFG::UIInputHandler::handleDirectionalInput(v2, elapsed, v3, v8);
      UFG::UIInputHandler::handleButtonInput(v2, elapsed, v3, v8);
      v9 = *(_QWORD *)((char *)v4 + v5 - 184);
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
        UFG::UIScreenManagerBase::queueMessageEx(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          (UFG::UIMessage *)v13);
        *((_DWORD *)v4 - 11) = v11;
        *((_DWORD *)v4 - 10) = v10;
      }
      else if ( UFG::qVector2::msZero.x != *(v4 - 11) || UFG::qVector2::msZero.y != *(v4 - 10) )
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
        UFG::UIScreenManagerBase::queueMessageEx(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v16);
        *(_QWORD *)(v4 - 11) = 0i64;
      }
      v17 = *(_QWORD *)((char *)v4 + v6 - 184);
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
        UFG::UIScreenManagerBase::queueMessageEx(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          (UFG::UIMessage *)v21);
        *((_DWORD *)v4 - 1) = v19;
        *(_DWORD *)v4 = v18;
      }
      else if ( UFG::qVector2::msZero.x != *(v4 - 1) || UFG::qVector2::msZero.y != *v4 )
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
        UFG::UIScreenManagerBase::queueMessageEx(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v24);
        *(_QWORD *)(v4 - 1) = 0i64;
      }
    }
    ++v3;
    v4 += 2;
  }
  while ( v3 < 5 );
}

// File Line: 206
// RVA: 0xA2E080
void __fastcall UFG::UIInputHandler::handleDirectionalInput(UFG::UIInputHandler *this, float elapsed, int controllerIndex, unsigned int controllerMask)
{
  int v4; // edi
  __int64 v5; // rbp
  float v6; // xmm8_4
  UFG::UIInputHandler *v7; // rsi
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
  float v48; // xmm1_4
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
  unsigned int v71; // eax

  v4 = controllerMask;
  v5 = controllerIndex;
  v6 = elapsed;
  v7 = this;
  v8 = 0i64;
  v9 = UFG::ActionDef_UILeftPressed.mDataPerController[v5];
  if ( v9 && v9->mActionTrue )
  {
    this->mState[v5][0] = 0;
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
      HIDWORD(v8[7].mNext) = v4;
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
        HIDWORD(v8[7].mNext) = v4;
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
        this->mState[v5][0] = 0;
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
          HIDWORD(v8[7].mNext) = v4;
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
          this->mState[v5][0] = 0;
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
            HIDWORD(v8[7].mNext) = v4;
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
              HIDWORD(v8[7].mNext) = v4;
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
              this->mState[v5][0] = 0;
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
                HIDWORD(v8[7].mNext) = v4;
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
                this->mState[v5][0] = 0;
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
                  HIDWORD(v8[7].mNext) = v4;
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
                    HIDWORD(v8[7].mNext) = v4;
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
                    this->mState[v5][0] = 0;
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
                      HIDWORD(v8[7].mNext) = v4;
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
                      this->mState[v5][0] = 0;
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
                        HIDWORD(v8[7].mNext) = v4;
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
                          HIDWORD(v8[7].mNext) = v4;
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
                          this->mState[v5][0] = 0;
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
                            HIDWORD(v8[7].mNext) = v4;
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
                            v48 = this->mAnalogDeadZone;
                            v49 = LODWORD(this->mAnalogDeadZone) ^ _xmm[0];
                            if ( v46 >= *(float *)&v49 )
                            {
                              if ( v46 <= v48 )
                              {
                                if ( v47 <= v48 )
                                {
                                  if ( v47 >= *(float *)&v49 )
                                    goto LABEL_121;
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
                                      v4);
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
                                      v4);
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
                                    v4);
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
                                  v4);
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
                              goto LABEL_121;
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
                                    goto LABEL_121;
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
                                      v4);
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
                                      v4);
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
                                    v4);
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
                                  v4);
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
                            v71 = (unsigned int)v8[5].mNext;
                            if ( v71 != v7->mLastAnalogValue[v5] )
                              v7->mState[v5][0] = 0;
                            v7->mLastAnalogValue[v5] = v71;
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
LABEL_121:
  UFG::UIInputHandler::update(v7, v6, (UFG::UIMessage *)v8, v5, 0);
}

// File Line: 318
// RVA: 0xA2C190
void __fastcall UFG::UIInputHandler::handleButtonInput(UFG::UIInputHandler *this, float elapsed, int controllerIndex, unsigned int controllerMask)
{
  unsigned int v4; // er14
  __int64 v5; // r15
  UFG::UIInputHandler *v6; // rsi
  UFG::UIMessage *v7; // rbx
  UFG::InputActionData *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rcx
  UFG::InputActionData *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rcx
  UFG::InputActionData *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rcx
  UFG::InputActionData *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rcx
  UFG::InputActionData *v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rcx
  UFG::InputActionData *v23; // rax
  UFG::allocator::free_link *v24; // rax
  UFG::allocator::free_link *v25; // rcx
  UFG::InputActionData *v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // rcx
  UFG::InputActionData *v29; // rax
  UFG::allocator::free_link *v30; // rax
  UFG::allocator::free_link *v31; // rcx
  UFG::InputActionData *v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::allocator::free_link *v34; // rcx
  UFG::InputActionData *v35; // rax
  UFG::allocator::free_link *v36; // rax
  UFG::allocator::free_link *v37; // rcx
  UFG::InputActionData *v38; // rax
  UFG::allocator::free_link *v39; // rax
  UFG::allocator::free_link *v40; // rcx
  UFG::InputActionData *v41; // rax
  UFG::allocator::free_link *v42; // rax
  UFG::allocator::free_link *v43; // rcx
  UFG::InputActionData *v44; // rax
  UFG::allocator::free_link *v45; // rax
  UFG::allocator::free_link *v46; // rcx
  UFG::InputActionData *v47; // rax
  UFG::allocator::free_link *v48; // rax
  UFG::allocator::free_link *v49; // rcx
  UFG::InputActionData *v50; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::allocator::free_link *v52; // rcx
  UFG::InputActionData *v53; // rax
  UFG::allocator::free_link *v54; // rax
  UFG::allocator::free_link *v55; // rcx
  UFG::InputActionData *v56; // rax
  UFG::allocator::free_link *v57; // rax
  UFG::allocator::free_link *v58; // rcx
  UFG::InputActionData *v59; // rax
  UFG::allocator::free_link *v60; // rax
  UFG::allocator::free_link *v61; // rcx
  UFG::InputActionData *v62; // rax
  UFG::UIScreenTextureManager *v63; // rax
  UFG::UIScreenTextureManager *v64; // rax
  UFG::UIScreenTextureManager *v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::allocator::free_link *v67; // rcx
  UFG::allocator::free_link *v68; // rax
  UFG::allocator::free_link *v69; // rcx
  UFG::InputActionData *v70; // rax
  UFG::UIScreenTextureManager *v71; // rax
  UFG::UIScreenTextureManager *v72; // rax
  UFG::UIScreenTextureManager *v73; // rax
  UFG::allocator::free_link *v74; // rax
  UFG::allocator::free_link *v75; // rcx
  UFG::allocator::free_link *v76; // rax
  UFG::allocator::free_link *v77; // rcx
  UFG::InputActionData *v78; // rax
  UFG::UIScreenTextureManager *v79; // rax
  UFG::UIScreenTextureManager *v80; // rax
  UFG::UIScreenTextureManager *v81; // rax
  UFG::allocator::free_link *v82; // rax
  UFG::allocator::free_link *v83; // rcx
  UFG::allocator::free_link *v84; // rax
  UFG::allocator::free_link *v85; // rcx
  UFG::InputActionData *v86; // rax
  UFG::allocator::free_link *v87; // rax
  UFG::allocator::free_link *v88; // rcx
  UFG::InputActionData *v89; // rax
  UFG::allocator::free_link *v90; // rax
  UFG::allocator::free_link *v91; // rcx
  UFG::InputActionData *v92; // rax
  UFG::allocator::free_link *v93; // rax
  UFG::allocator::free_link *v94; // rcx
  UFG::InputActionData *v95; // rax
  UFG::allocator::free_link *v96; // rax
  UFG::allocator::free_link *v97; // rcx
  UFG::InputActionData *v98; // rax
  UFG::allocator::free_link *v99; // rax
  UFG::allocator::free_link *v100; // rcx
  UFG::InputActionData *v101; // rax
  UFG::allocator::free_link *v102; // rax
  UFG::allocator::free_link *v103; // rcx
  UFG::InputActionData *v104; // rax
  UFG::allocator::free_link *v105; // rax
  UFG::allocator::free_link *v106; // rcx
  UFG::InputActionData *v107; // rax
  UFG::allocator::free_link *v108; // rax
  UFG::allocator::free_link *v109; // rcx
  UFG::InputActionData *v110; // rax
  UFG::allocator::free_link *v111; // rax
  UFG::allocator::free_link *v112; // rcx
  UFG::InputActionData *v113; // rax
  UFG::allocator::free_link *v114; // rax
  UFG::allocator::free_link *v115; // rcx
  UFG::InputActionData *v116; // rax
  UFG::allocator::free_link *v117; // rax
  UFG::allocator::free_link *v118; // rcx
  UFG::InputActionData *v119; // rax
  UFG::allocator::free_link *v120; // rax
  UFG::allocator::free_link *v121; // rcx
  UFG::InputActionData *v122; // rax
  UFG::allocator::free_link *v123; // rax
  UFG::allocator::free_link *v124; // rcx
  UFG::InputActionData *v125; // rax
  UFG::allocator::free_link *v126; // rax
  UFG::allocator::free_link *v127; // rcx
  UFG::InputActionData *v128; // rax
  UFG::allocator::free_link *v129; // rax
  UFG::allocator::free_link *v130; // rcx
  UFG::InputActionData *v131; // rax
  UFG::allocator::free_link *v132; // rax
  UFG::allocator::free_link *v133; // rcx
  UFG::InputActionData *v134; // rax
  UFG::allocator::free_link *v135; // rax
  UFG::allocator::free_link *v136; // rcx
  UFG::InputActionData *v137; // rax
  UFG::allocator::free_link *v138; // rax
  UFG::allocator::free_link *v139; // rcx

  v4 = controllerMask;
  v5 = controllerIndex;
  v6 = this;
  v7 = 0i64;
  v8 = UFG::ActionDef_UIAcceptPressed.mDataPerController[controllerIndex];
  if ( v8 && v8->mActionTrue )
  {
    this->mState[controllerIndex][1] = 0;
    v9 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
    if ( v9 )
    {
      v10 = v9 + 1;
      v10->mNext = v10;
      v10[1].mNext = v10;
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
      HIDWORD(v9[7].mNext) = v4;
      LODWORD(v9[3].mNext) = 6;
      HIDWORD(v9[6].mNext) = 0;
      v7 = (UFG::UIMessage *)v9;
    }
  }
  else
  {
    v11 = UFG::ActionDef_UIAcceptRepeat.mDataPerController[controllerIndex];
    if ( v11 && v11->mActionTrue )
    {
      v12 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
      if ( v12 )
      {
        v13 = v12 + 1;
        v13->mNext = v13;
        v13[1].mNext = v13;
        v12->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
        LODWORD(v12[3].mNext) = -1;
        v12[4].mNext = 0i64;
        v12->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
        LODWORD(v12[5].mNext) = UI_HASH_BUTTON_ACCEPT_REPEAT_35;
        HIDWORD(v12[5].mNext) = 0;
        v12[6].mNext = (UFG::allocator::free_link *)-1i64;
        LODWORD(v12[3].mNext) = 5;
        v12->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
        LODWORD(v12[7].mNext) = 1065353216;
        HIDWORD(v12[7].mNext) = v4;
        LODWORD(v12[3].mNext) = 6;
        HIDWORD(v12[6].mNext) = 0;
        v7 = (UFG::UIMessage *)v12;
      }
    }
    else
    {
      v14 = UFG::ActionDef_UIAcceptReleased.mDataPerController[controllerIndex];
      if ( v14 && v14->mActionTrue )
      {
        this->mState[controllerIndex][1] = 0;
        v15 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIInputHandler::UIMessagePadInput", 0i64, 1u);
        if ( v15 )
        {
          v16 = v15 + 1;
          v16->mNext = v16;
          v16[1].mNext = v16;
          v15->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
          LODWORD(v15[3].mNext) = -1;
          v15[4].mNext = 0i64;
          v15->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
          LODWORD(v15[5].mNext) = UI_HASH_BUTTON_ACCEPT_RELEASED_35;
          HIDWORD(v15[5].mNext) = 0;
          v15[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v15[3].mNext) = 5;
          v15->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
          *(UFG::allocator::free_link **)((char *)&v15[6].mNext + 4) = 0i64;
          HIDWORD(v15[7].mNext) = v4;
          LODWORD(v15[3].mNext) = 6;
          v7 = (UFG::UIMessage *)v15;
        }
      }
      else
      {
        v17 = UFG::ActionDef_UIBackPressed.mDataPerController[controllerIndex];
        if ( v17 && v17->mActionTrue )
        {
          this->mState[controllerIndex][1] = 0;
          v18 = UFG::qMemoryPool::Allocate(
                  &gScaleformMemoryPool,
                  0x40ui64,
                  "UIInputHandler::UIMessagePadInput",
                  0i64,
                  1u);
          if ( v18 )
          {
            v19 = v18 + 1;
            v19->mNext = v19;
            v19[1].mNext = v19;
            v18->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
            LODWORD(v18[3].mNext) = -1;
            v18[4].mNext = 0i64;
            v18->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
            LODWORD(v18[5].mNext) = UI_HASH_BUTTON_BACK_PRESSED_35;
            HIDWORD(v18[5].mNext) = 0;
            v18[6].mNext = (UFG::allocator::free_link *)-1i64;
            LODWORD(v18[3].mNext) = 5;
            v18->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
            LODWORD(v18[7].mNext) = 1065353216;
            HIDWORD(v18[7].mNext) = v4;
            LODWORD(v18[3].mNext) = 6;
            HIDWORD(v18[6].mNext) = 0;
            v7 = (UFG::UIMessage *)v18;
          }
        }
        else
        {
          v20 = UFG::ActionDef_UIBackRepeat.mDataPerController[controllerIndex];
          if ( v20 && v20->mActionTrue )
          {
            v21 = UFG::qMemoryPool::Allocate(
                    &gScaleformMemoryPool,
                    0x40ui64,
                    "UIInputHandler::UIMessagePadInput",
                    0i64,
                    1u);
            if ( v21 )
            {
              v22 = v21 + 1;
              v22->mNext = v22;
              v22[1].mNext = v22;
              v21->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
              LODWORD(v21[3].mNext) = -1;
              v21[4].mNext = 0i64;
              v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
              LODWORD(v21[5].mNext) = UI_HASH_BUTTON_BACK_REPEAT_35;
              HIDWORD(v21[5].mNext) = 0;
              v21[6].mNext = (UFG::allocator::free_link *)-1i64;
              LODWORD(v21[3].mNext) = 5;
              v21->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
              LODWORD(v21[7].mNext) = 1065353216;
              HIDWORD(v21[7].mNext) = v4;
              LODWORD(v21[3].mNext) = 6;
              HIDWORD(v21[6].mNext) = 0;
              v7 = (UFG::UIMessage *)v21;
            }
          }
          else
          {
            v23 = UFG::ActionDef_UIBackReleased.mDataPerController[controllerIndex];
            if ( v23 && v23->mActionTrue )
            {
              this->mState[controllerIndex][1] = 0;
              v24 = UFG::qMemoryPool::Allocate(
                      &gScaleformMemoryPool,
                      0x40ui64,
                      "UIInputHandler::UIMessagePadInput",
                      0i64,
                      1u);
              if ( v24 )
              {
                v25 = v24 + 1;
                v25->mNext = v25;
                v25[1].mNext = v25;
                v24->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                LODWORD(v24[3].mNext) = -1;
                v24[4].mNext = 0i64;
                v24->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                LODWORD(v24[5].mNext) = UI_HASH_BUTTON_BACK_RELEASED_35;
                HIDWORD(v24[5].mNext) = 0;
                v24[6].mNext = (UFG::allocator::free_link *)-1i64;
                LODWORD(v24[3].mNext) = 5;
                v24->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                *(UFG::allocator::free_link **)((char *)&v24[6].mNext + 4) = 0i64;
                HIDWORD(v24[7].mNext) = v4;
                LODWORD(v24[3].mNext) = 6;
                v7 = (UFG::UIMessage *)v24;
              }
            }
            else
            {
              v26 = UFG::ActionDef_UIButton1Pressed.mDataPerController[controllerIndex];
              if ( v26 && v26->mActionTrue )
              {
                this->mState[controllerIndex][1] = 0;
                v27 = UFG::qMemoryPool::Allocate(
                        &gScaleformMemoryPool,
                        0x40ui64,
                        "UIInputHandler::UIMessagePadInput",
                        0i64,
                        1u);
                if ( v27 )
                {
                  v28 = v27 + 1;
                  v28->mNext = v28;
                  v28[1].mNext = v28;
                  v27->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                  LODWORD(v27[3].mNext) = -1;
                  v27[4].mNext = 0i64;
                  v27->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                  LODWORD(v27[5].mNext) = UI_HASH_BUTTON_BUTTON1_PRESSED_35;
                  HIDWORD(v27[5].mNext) = 0;
                  v27[6].mNext = (UFG::allocator::free_link *)-1i64;
                  LODWORD(v27[3].mNext) = 5;
                  v27->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                  LODWORD(v27[7].mNext) = 1065353216;
                  HIDWORD(v27[7].mNext) = v4;
                  LODWORD(v27[3].mNext) = 6;
                  HIDWORD(v27[6].mNext) = 0;
                  v7 = (UFG::UIMessage *)v27;
                }
              }
              else
              {
                v29 = UFG::ActionDef_UIButton1Repeat.mDataPerController[controllerIndex];
                if ( v29 && v29->mActionTrue )
                {
                  v30 = UFG::qMemoryPool::Allocate(
                          &gScaleformMemoryPool,
                          0x40ui64,
                          "UIInputHandler::UIMessagePadInput",
                          0i64,
                          1u);
                  if ( v30 )
                  {
                    v31 = v30 + 1;
                    v31->mNext = v31;
                    v31[1].mNext = v31;
                    v30->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                    LODWORD(v30[3].mNext) = -1;
                    v30[4].mNext = 0i64;
                    v30->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                    LODWORD(v30[5].mNext) = UI_HASH_BUTTON_BUTTON1_REPEAT_35;
                    HIDWORD(v30[5].mNext) = 0;
                    v30[6].mNext = (UFG::allocator::free_link *)-1i64;
                    LODWORD(v30[3].mNext) = 5;
                    v30->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                    LODWORD(v30[7].mNext) = 1065353216;
                    HIDWORD(v30[7].mNext) = v4;
                    LODWORD(v30[3].mNext) = 6;
                    HIDWORD(v30[6].mNext) = 0;
                    v7 = (UFG::UIMessage *)v30;
                  }
                }
                else
                {
                  v32 = UFG::ActionDef_UIButton1Released.mDataPerController[controllerIndex];
                  if ( v32 && v32->mActionTrue )
                  {
                    this->mState[controllerIndex][1] = 0;
                    v33 = UFG::qMemoryPool::Allocate(
                            &gScaleformMemoryPool,
                            0x40ui64,
                            "UIInputHandler::UIMessagePadInput",
                            0i64,
                            1u);
                    if ( v33 )
                    {
                      v34 = v33 + 1;
                      v34->mNext = v34;
                      v34[1].mNext = v34;
                      v33->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                      LODWORD(v33[3].mNext) = -1;
                      v33[4].mNext = 0i64;
                      v33->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                      LODWORD(v33[5].mNext) = UI_HASH_BUTTON_BUTTON1_RELEASED_35;
                      HIDWORD(v33[5].mNext) = 0;
                      v33[6].mNext = (UFG::allocator::free_link *)-1i64;
                      LODWORD(v33[3].mNext) = 5;
                      v33->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                      *(UFG::allocator::free_link **)((char *)&v33[6].mNext + 4) = 0i64;
                      HIDWORD(v33[7].mNext) = v4;
                      LODWORD(v33[3].mNext) = 6;
                      v7 = (UFG::UIMessage *)v33;
                    }
                  }
                  else
                  {
                    v35 = UFG::ActionDef_UIButton2Pressed.mDataPerController[controllerIndex];
                    if ( v35 && v35->mActionTrue )
                    {
                      this->mState[controllerIndex][1] = 0;
                      v36 = UFG::qMemoryPool::Allocate(
                              &gScaleformMemoryPool,
                              0x40ui64,
                              "UIInputHandler::UIMessagePadInput",
                              0i64,
                              1u);
                      if ( v36 )
                      {
                        v37 = v36 + 1;
                        v37->mNext = v37;
                        v37[1].mNext = v37;
                        v36->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                        LODWORD(v36[3].mNext) = -1;
                        v36[4].mNext = 0i64;
                        v36->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                        LODWORD(v36[5].mNext) = UI_HASH_BUTTON_BUTTON2_PRESSED_35;
                        HIDWORD(v36[5].mNext) = 0;
                        v36[6].mNext = (UFG::allocator::free_link *)-1i64;
                        LODWORD(v36[3].mNext) = 5;
                        v36->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                        LODWORD(v36[7].mNext) = 1065353216;
                        HIDWORD(v36[7].mNext) = v4;
                        LODWORD(v36[3].mNext) = 6;
                        HIDWORD(v36[6].mNext) = 0;
                        v7 = (UFG::UIMessage *)v36;
                      }
                    }
                    else
                    {
                      v38 = UFG::ActionDef_UIButton2Repeat.mDataPerController[controllerIndex];
                      if ( v38 && v38->mActionTrue )
                      {
                        v39 = UFG::qMemoryPool::Allocate(
                                &gScaleformMemoryPool,
                                0x40ui64,
                                "UIInputHandler::UIMessagePadInput",
                                0i64,
                                1u);
                        if ( v39 )
                        {
                          v40 = v39 + 1;
                          v40->mNext = v40;
                          v40[1].mNext = v40;
                          v39->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                          LODWORD(v39[3].mNext) = -1;
                          v39[4].mNext = 0i64;
                          v39->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                          LODWORD(v39[5].mNext) = UI_HASH_BUTTON_BUTTON2_REPEAT_35;
                          HIDWORD(v39[5].mNext) = 0;
                          v39[6].mNext = (UFG::allocator::free_link *)-1i64;
                          LODWORD(v39[3].mNext) = 5;
                          v39->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                          LODWORD(v39[7].mNext) = 1065353216;
                          HIDWORD(v39[7].mNext) = v4;
                          LODWORD(v39[3].mNext) = 6;
                          HIDWORD(v39[6].mNext) = 0;
                          v7 = (UFG::UIMessage *)v39;
                        }
                      }
                      else
                      {
                        v41 = UFG::ActionDef_UIButton2Released.mDataPerController[controllerIndex];
                        if ( v41 && v41->mActionTrue )
                        {
                          this->mState[controllerIndex][1] = 0;
                          v42 = UFG::qMemoryPool::Allocate(
                                  &gScaleformMemoryPool,
                                  0x40ui64,
                                  "UIInputHandler::UIMessagePadInput",
                                  0i64,
                                  1u);
                          if ( v42 )
                          {
                            v43 = v42 + 1;
                            v43->mNext = v43;
                            v43[1].mNext = v43;
                            v42->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                            LODWORD(v42[3].mNext) = -1;
                            v42[4].mNext = 0i64;
                            v42->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                            LODWORD(v42[5].mNext) = UI_HASH_BUTTON_BUTTON2_RELEASED_35;
                            HIDWORD(v42[5].mNext) = 0;
                            v42[6].mNext = (UFG::allocator::free_link *)-1i64;
                            LODWORD(v42[3].mNext) = 5;
                            v42->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                            *(UFG::allocator::free_link **)((char *)&v42[6].mNext + 4) = 0i64;
                            HIDWORD(v42[7].mNext) = v4;
                            LODWORD(v42[3].mNext) = 6;
                            v7 = (UFG::UIMessage *)v42;
                          }
                        }
                        else
                        {
                          v44 = UFG::ActionDef_UISelectPressed.mDataPerController[controllerIndex];
                          if ( v44 && v44->mActionTrue )
                          {
                            this->mState[controllerIndex][1] = 0;
                            v45 = UFG::qMemoryPool::Allocate(
                                    &gScaleformMemoryPool,
                                    0x40ui64,
                                    "UIInputHandler::UIMessagePadInput",
                                    0i64,
                                    1u);
                            if ( v45 )
                            {
                              v46 = v45 + 1;
                              v46->mNext = v46;
                              v46[1].mNext = v46;
                              v45->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                              LODWORD(v45[3].mNext) = -1;
                              v45[4].mNext = 0i64;
                              v45->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                              LODWORD(v45[5].mNext) = UI_HASH_BUTTON_SELECT_PRESSED_35;
                              HIDWORD(v45[5].mNext) = 0;
                              v45[6].mNext = (UFG::allocator::free_link *)-1i64;
                              LODWORD(v45[3].mNext) = 5;
                              v45->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                              LODWORD(v45[7].mNext) = 1065353216;
                              HIDWORD(v45[7].mNext) = v4;
                              LODWORD(v45[3].mNext) = 6;
                              HIDWORD(v45[6].mNext) = 0;
                              v7 = (UFG::UIMessage *)v45;
                            }
                          }
                          else
                          {
                            v47 = UFG::ActionDef_UISelectRepeat.mDataPerController[controllerIndex];
                            if ( v47 && v47->mActionTrue )
                            {
                              v48 = UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      0x40ui64,
                                      "UIInputHandler::UIMessagePadInput",
                                      0i64,
                                      1u);
                              if ( v48 )
                              {
                                v49 = v48 + 1;
                                v49->mNext = v49;
                                v49[1].mNext = v49;
                                v48->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                LODWORD(v48[3].mNext) = -1;
                                v48[4].mNext = 0i64;
                                v48->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                LODWORD(v48[5].mNext) = UI_HASH_BUTTON_SELECT_REPEAT_35;
                                HIDWORD(v48[5].mNext) = 0;
                                v48[6].mNext = (UFG::allocator::free_link *)-1i64;
                                LODWORD(v48[3].mNext) = 5;
                                v48->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                LODWORD(v48[7].mNext) = 1065353216;
                                HIDWORD(v48[7].mNext) = v4;
                                LODWORD(v48[3].mNext) = 6;
                                HIDWORD(v48[6].mNext) = 0;
                                v7 = (UFG::UIMessage *)v48;
                              }
                            }
                            else
                            {
                              v50 = UFG::ActionDef_UISelectReleased.mDataPerController[controllerIndex];
                              if ( v50 && v50->mActionTrue )
                              {
                                this->mState[controllerIndex][1] = 0;
                                v51 = UFG::qMemoryPool::Allocate(
                                        &gScaleformMemoryPool,
                                        0x40ui64,
                                        "UIInputHandler::UIMessagePadInput",
                                        0i64,
                                        1u);
                                if ( v51 )
                                {
                                  v52 = v51 + 1;
                                  v52->mNext = v52;
                                  v52[1].mNext = v52;
                                  v51->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                  LODWORD(v51[3].mNext) = -1;
                                  v51[4].mNext = 0i64;
                                  v51->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                  LODWORD(v51[5].mNext) = UI_HASH_BUTTON_SELECT_RELEASED_35;
                                  HIDWORD(v51[5].mNext) = 0;
                                  v51[6].mNext = (UFG::allocator::free_link *)-1i64;
                                  LODWORD(v51[3].mNext) = 5;
                                  v51->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                  *(UFG::allocator::free_link **)((char *)&v51[6].mNext + 4) = 0i64;
                                  HIDWORD(v51[7].mNext) = v4;
                                  LODWORD(v51[3].mNext) = 6;
                                  v7 = (UFG::UIMessage *)v51;
                                }
                              }
                              else
                              {
                                v53 = UFG::ActionDef_UIStartPressed.mDataPerController[controllerIndex];
                                if ( v53 && v53->mActionTrue )
                                {
                                  this->mState[controllerIndex][1] = 0;
                                  v54 = UFG::qMemoryPool::Allocate(
                                          &gScaleformMemoryPool,
                                          0x40ui64,
                                          "UIInputHandler::UIMessagePadInput",
                                          0i64,
                                          1u);
                                  if ( v54 )
                                  {
                                    v55 = v54 + 1;
                                    v55->mNext = v55;
                                    v55[1].mNext = v55;
                                    v54->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                    LODWORD(v54[3].mNext) = -1;
                                    v54[4].mNext = 0i64;
                                    v54->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                    LODWORD(v54[5].mNext) = UI_HASH_BUTTON_START_PRESSED_35;
                                    HIDWORD(v54[5].mNext) = 0;
                                    v54[6].mNext = (UFG::allocator::free_link *)-1i64;
                                    LODWORD(v54[3].mNext) = 5;
                                    v54->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                    LODWORD(v54[7].mNext) = 1065353216;
                                    HIDWORD(v54[7].mNext) = v4;
                                    LODWORD(v54[3].mNext) = 6;
                                    HIDWORD(v54[6].mNext) = 0;
                                    v7 = (UFG::UIMessage *)v54;
                                  }
                                }
                                else
                                {
                                  v56 = UFG::ActionDef_UIStartRepeat.mDataPerController[controllerIndex];
                                  if ( v56 && v56->mActionTrue )
                                  {
                                    v57 = UFG::qMemoryPool::Allocate(
                                            &gScaleformMemoryPool,
                                            0x40ui64,
                                            "UIInputHandler::UIMessagePadInput",
                                            0i64,
                                            1u);
                                    if ( v57 )
                                    {
                                      v58 = v57 + 1;
                                      v58->mNext = v58;
                                      v58[1].mNext = v58;
                                      v57->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                      LODWORD(v57[3].mNext) = -1;
                                      v57[4].mNext = 0i64;
                                      v57->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                      LODWORD(v57[5].mNext) = UI_HASH_BUTTON_START_REPEAT_35;
                                      HIDWORD(v57[5].mNext) = 0;
                                      v57[6].mNext = (UFG::allocator::free_link *)-1i64;
                                      LODWORD(v57[3].mNext) = 5;
                                      v57->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                      LODWORD(v57[7].mNext) = 1065353216;
                                      HIDWORD(v57[7].mNext) = v4;
                                      LODWORD(v57[3].mNext) = 6;
                                      HIDWORD(v57[6].mNext) = 0;
                                      v7 = (UFG::UIMessage *)v57;
                                    }
                                  }
                                  else
                                  {
                                    v59 = UFG::ActionDef_UIStartReleased.mDataPerController[controllerIndex];
                                    if ( v59 && v59->mActionTrue )
                                    {
                                      this->mState[controllerIndex][1] = 0;
                                      v60 = UFG::qMemoryPool::Allocate(
                                              &gScaleformMemoryPool,
                                              0x40ui64,
                                              "UIInputHandler::UIMessagePadInput",
                                              0i64,
                                              1u);
                                      if ( v60 )
                                      {
                                        v61 = v60 + 1;
                                        v61->mNext = v61;
                                        v61[1].mNext = v61;
                                        v60->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                        LODWORD(v60[3].mNext) = -1;
                                        v60[4].mNext = 0i64;
                                        v60->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                        LODWORD(v60[5].mNext) = UI_HASH_BUTTON_START_RELEASED_35;
                                        HIDWORD(v60[5].mNext) = 0;
                                        v60[6].mNext = (UFG::allocator::free_link *)-1i64;
                                        LODWORD(v60[3].mNext) = 5;
                                        v60->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                        *(UFG::allocator::free_link **)((char *)&v60[6].mNext + 4) = 0i64;
                                        HIDWORD(v60[7].mNext) = v4;
                                        LODWORD(v60[3].mNext) = 6;
                                        v7 = (UFG::UIMessage *)v60;
                                      }
                                    }
                                    else
                                    {
                                      v62 = UFG::ActionDef_UIEscapePressed.mDataPerController[controllerIndex];
                                      if ( v62 && v62->mActionTrue )
                                      {
                                        v63 = UFG::UIScreenTextureManager::Instance();
                                        if ( (unsigned int)UFG::UIScreenTextureManager::GetGameState(v63) == 2
                                          || (v64 = UFG::UIScreenTextureManager::Instance(),
                                              (unsigned int)UFG::UIScreenTextureManager::GetGameState(v64) == 4)
                                          || (v65 = UFG::UIScreenTextureManager::Instance(),
                                              (unsigned int)UFG::UIScreenTextureManager::GetGameState(v65) == 32) )
                                        {
                                          v6->mState[v5][1] = 0;
                                          v68 = UFG::qMemoryPool::Allocate(
                                                  &gScaleformMemoryPool,
                                                  0x40ui64,
                                                  "UIInputHandler::UIMessagePadInput",
                                                  0i64,
                                                  1u);
                                          if ( v68 )
                                          {
                                            v69 = v68 + 1;
                                            v69->mNext = v69;
                                            v69[1].mNext = v69;
                                            v68->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                            LODWORD(v68[3].mNext) = -1;
                                            v68[4].mNext = 0i64;
                                            v68->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                            LODWORD(v68[5].mNext) = UI_HASH_BUTTON_START_PRESSED_35;
                                            HIDWORD(v68[5].mNext) = 0;
                                            v68[6].mNext = (UFG::allocator::free_link *)-1i64;
                                            LODWORD(v68[3].mNext) = 5;
                                            v68->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                            LODWORD(v68[7].mNext) = 1065353216;
                                            HIDWORD(v68[7].mNext) = v4;
                                            LODWORD(v68[3].mNext) = 6;
                                            HIDWORD(v68[6].mNext) = 0;
                                            v7 = (UFG::UIMessage *)v68;
                                          }
                                        }
                                        else
                                        {
                                          v6->mState[v5][1] = 0;
                                          v66 = UFG::qMemoryPool::Allocate(
                                                  &gScaleformMemoryPool,
                                                  0x40ui64,
                                                  "UIInputHandler::UIMessagePadInput",
                                                  0i64,
                                                  1u);
                                          if ( v66 )
                                          {
                                            v67 = v66 + 1;
                                            v67->mNext = v67;
                                            v67[1].mNext = v67;
                                            v66->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                            LODWORD(v66[3].mNext) = -1;
                                            v66[4].mNext = 0i64;
                                            v66->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                            LODWORD(v66[5].mNext) = UI_HASH_BUTTON_BACK_PRESSED_35;
                                            HIDWORD(v66[5].mNext) = 0;
                                            v66[6].mNext = (UFG::allocator::free_link *)-1i64;
                                            LODWORD(v66[3].mNext) = 5;
                                            v66->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                            LODWORD(v66[7].mNext) = 1065353216;
                                            HIDWORD(v66[7].mNext) = v4;
                                            LODWORD(v66[3].mNext) = 6;
                                            HIDWORD(v66[6].mNext) = 0;
                                            v7 = (UFG::UIMessage *)v66;
                                          }
                                        }
                                      }
                                      else
                                      {
                                        v70 = UFG::ActionDef_UIEscapeRepeat.mDataPerController[controllerIndex];
                                        if ( v70 && v70->mActionTrue )
                                        {
                                          v71 = UFG::UIScreenTextureManager::Instance();
                                          if ( (unsigned int)UFG::UIScreenTextureManager::GetGameState(v71) == 2
                                            || (v72 = UFG::UIScreenTextureManager::Instance(),
                                                (unsigned int)UFG::UIScreenTextureManager::GetGameState(v72) == 4)
                                            || (v73 = UFG::UIScreenTextureManager::Instance(),
                                                (unsigned int)UFG::UIScreenTextureManager::GetGameState(v73) == 32) )
                                          {
                                            v76 = UFG::qMemoryPool::Allocate(
                                                    &gScaleformMemoryPool,
                                                    0x40ui64,
                                                    "UIInputHandler::UIMessagePadInput",
                                                    0i64,
                                                    1u);
                                            if ( v76 )
                                            {
                                              v77 = v76 + 1;
                                              v77->mNext = v77;
                                              v77[1].mNext = v77;
                                              v76->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                              LODWORD(v76[3].mNext) = -1;
                                              v76[4].mNext = 0i64;
                                              v76->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                              LODWORD(v76[5].mNext) = UI_HASH_BUTTON_START_REPEAT_35;
                                              HIDWORD(v76[5].mNext) = 0;
                                              v76[6].mNext = (UFG::allocator::free_link *)-1i64;
                                              LODWORD(v76[3].mNext) = 5;
                                              v76->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                              LODWORD(v76[7].mNext) = 1065353216;
                                              HIDWORD(v76[7].mNext) = v4;
                                              LODWORD(v76[3].mNext) = 6;
                                              HIDWORD(v76[6].mNext) = 0;
                                              v7 = (UFG::UIMessage *)v76;
                                            }
                                          }
                                          else
                                          {
                                            v74 = UFG::qMemoryPool::Allocate(
                                                    &gScaleformMemoryPool,
                                                    0x40ui64,
                                                    "UIInputHandler::UIMessagePadInput",
                                                    0i64,
                                                    1u);
                                            if ( v74 )
                                            {
                                              v75 = v74 + 1;
                                              v75->mNext = v75;
                                              v75[1].mNext = v75;
                                              v74->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                              LODWORD(v74[3].mNext) = -1;
                                              v74[4].mNext = 0i64;
                                              v74->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                              LODWORD(v74[5].mNext) = UI_HASH_BUTTON_BACK_REPEAT_35;
                                              HIDWORD(v74[5].mNext) = 0;
                                              v74[6].mNext = (UFG::allocator::free_link *)-1i64;
                                              LODWORD(v74[3].mNext) = 5;
                                              v74->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                              LODWORD(v74[7].mNext) = 1065353216;
                                              HIDWORD(v74[7].mNext) = v4;
                                              LODWORD(v74[3].mNext) = 6;
                                              HIDWORD(v74[6].mNext) = 0;
                                              v7 = (UFG::UIMessage *)v74;
                                            }
                                          }
                                        }
                                        else
                                        {
                                          v78 = UFG::ActionDef_UIEscapeReleased.mDataPerController[controllerIndex];
                                          if ( v78 && v78->mActionTrue )
                                          {
                                            v79 = UFG::UIScreenTextureManager::Instance();
                                            if ( (unsigned int)UFG::UIScreenTextureManager::GetGameState(v79) == 2
                                              || (v80 = UFG::UIScreenTextureManager::Instance(),
                                                  (unsigned int)UFG::UIScreenTextureManager::GetGameState(v80) == 4)
                                              || (v81 = UFG::UIScreenTextureManager::Instance(),
                                                  (unsigned int)UFG::UIScreenTextureManager::GetGameState(v81) == 32) )
                                            {
                                              v6->mState[v5][1] = 0;
                                              v84 = UFG::qMemoryPool::Allocate(
                                                      &gScaleformMemoryPool,
                                                      0x40ui64,
                                                      "UIInputHandler::UIMessagePadInput",
                                                      0i64,
                                                      1u);
                                              if ( v84 )
                                              {
                                                v85 = v84 + 1;
                                                v85->mNext = v85;
                                                v85[1].mNext = v85;
                                                v84->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                LODWORD(v84[3].mNext) = -1;
                                                v84[4].mNext = 0i64;
                                                v84->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                LODWORD(v84[5].mNext) = UI_HASH_BUTTON_START_RELEASED_35;
                                                HIDWORD(v84[5].mNext) = 0;
                                                v84[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                LODWORD(v84[3].mNext) = 5;
                                                v84->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                *(UFG::allocator::free_link **)((char *)&v84[6].mNext + 4) = 0i64;
                                                HIDWORD(v84[7].mNext) = v4;
                                                LODWORD(v84[3].mNext) = 6;
                                                v7 = (UFG::UIMessage *)v84;
                                              }
                                            }
                                            else
                                            {
                                              v6->mState[v5][1] = 0;
                                              v82 = UFG::qMemoryPool::Allocate(
                                                      &gScaleformMemoryPool,
                                                      0x40ui64,
                                                      "UIInputHandler::UIMessagePadInput",
                                                      0i64,
                                                      1u);
                                              if ( v82 )
                                              {
                                                v83 = v82 + 1;
                                                v83->mNext = v83;
                                                v83[1].mNext = v83;
                                                v82->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                LODWORD(v82[3].mNext) = -1;
                                                v82[4].mNext = 0i64;
                                                v82->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                LODWORD(v82[5].mNext) = UI_HASH_BUTTON_BACK_RELEASED_35;
                                                HIDWORD(v82[5].mNext) = 0;
                                                v82[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                LODWORD(v82[3].mNext) = 5;
                                                v82->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                *(UFG::allocator::free_link **)((char *)&v82[6].mNext + 4) = 0i64;
                                                HIDWORD(v82[7].mNext) = v4;
                                                LODWORD(v82[3].mNext) = 6;
                                                v7 = (UFG::UIMessage *)v82;
                                              }
                                            }
                                          }
                                          else
                                          {
                                            v86 = UFG::ActionDef_UIL1Pressed.mDataPerController[controllerIndex];
                                            if ( v86 && v86->mActionTrue )
                                            {
                                              this->mState[controllerIndex][1] = 0;
                                              v87 = UFG::qMemoryPool::Allocate(
                                                      &gScaleformMemoryPool,
                                                      0x40ui64,
                                                      "UIInputHandler::UIMessagePadInput",
                                                      0i64,
                                                      1u);
                                              if ( v87 )
                                              {
                                                v88 = v87 + 1;
                                                v88->mNext = v88;
                                                v88[1].mNext = v88;
                                                v87->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                LODWORD(v87[3].mNext) = -1;
                                                v87[4].mNext = 0i64;
                                                v87->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                LODWORD(v87[5].mNext) = UI_HASH_BUTTON_L1_PRESSED_35;
                                                HIDWORD(v87[5].mNext) = 0;
                                                v87[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                LODWORD(v87[3].mNext) = 5;
                                                v87->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                LODWORD(v87[7].mNext) = 1065353216;
                                                HIDWORD(v87[7].mNext) = v4;
                                                LODWORD(v87[3].mNext) = 6;
                                                HIDWORD(v87[6].mNext) = 0;
                                                v7 = (UFG::UIMessage *)v87;
                                              }
                                            }
                                            else
                                            {
                                              v89 = UFG::ActionDef_UIL1Repeat.mDataPerController[controllerIndex];
                                              if ( v89 && v89->mActionTrue )
                                              {
                                                v90 = UFG::qMemoryPool::Allocate(
                                                        &gScaleformMemoryPool,
                                                        0x40ui64,
                                                        "UIInputHandler::UIMessagePadInput",
                                                        0i64,
                                                        1u);
                                                if ( v90 )
                                                {
                                                  v91 = v90 + 1;
                                                  v91->mNext = v91;
                                                  v91[1].mNext = v91;
                                                  v90->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                  LODWORD(v90[3].mNext) = -1;
                                                  v90[4].mNext = 0i64;
                                                  v90->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                  LODWORD(v90[5].mNext) = UI_HASH_BUTTON_L1_REPEAT_35;
                                                  HIDWORD(v90[5].mNext) = 0;
                                                  v90[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                  LODWORD(v90[3].mNext) = 5;
                                                  v90->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                  LODWORD(v90[7].mNext) = 1065353216;
                                                  HIDWORD(v90[7].mNext) = v4;
                                                  LODWORD(v90[3].mNext) = 6;
                                                  HIDWORD(v90[6].mNext) = 0;
                                                  v7 = (UFG::UIMessage *)v90;
                                                }
                                              }
                                              else
                                              {
                                                v92 = UFG::ActionDef_UIL1Released.mDataPerController[controllerIndex];
                                                if ( v92 && v92->mActionTrue )
                                                {
                                                  this->mState[controllerIndex][1] = 0;
                                                  v93 = UFG::qMemoryPool::Allocate(
                                                          &gScaleformMemoryPool,
                                                          0x40ui64,
                                                          "UIInputHandler::UIMessagePadInput",
                                                          0i64,
                                                          1u);
                                                  if ( v93 )
                                                  {
                                                    v94 = v93 + 1;
                                                    v94->mNext = v94;
                                                    v94[1].mNext = v94;
                                                    v93->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                    LODWORD(v93[3].mNext) = -1;
                                                    v93[4].mNext = 0i64;
                                                    v93->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                    LODWORD(v93[5].mNext) = UI_HASH_BUTTON_L1_RELEASED_35;
                                                    HIDWORD(v93[5].mNext) = 0;
                                                    v93[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                    LODWORD(v93[3].mNext) = 5;
                                                    v93->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                    *(UFG::allocator::free_link **)((char *)&v93[6].mNext + 4) = 0i64;
                                                    HIDWORD(v93[7].mNext) = v4;
                                                    LODWORD(v93[3].mNext) = 6;
                                                    v7 = (UFG::UIMessage *)v93;
                                                  }
                                                }
                                                else
                                                {
                                                  v95 = UFG::ActionDef_UIL2Pressed.mDataPerController[controllerIndex];
                                                  if ( v95 && v95->mActionTrue )
                                                  {
                                                    this->mState[controllerIndex][1] = 0;
                                                    v96 = UFG::qMemoryPool::Allocate(
                                                            &gScaleformMemoryPool,
                                                            0x40ui64,
                                                            "UIInputHandler::UIMessagePadInput",
                                                            0i64,
                                                            1u);
                                                    if ( v96 )
                                                    {
                                                      v97 = v96 + 1;
                                                      v97->mNext = v97;
                                                      v97[1].mNext = v97;
                                                      v96->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                      LODWORD(v96[3].mNext) = -1;
                                                      v96[4].mNext = 0i64;
                                                      v96->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                      LODWORD(v96[5].mNext) = UI_HASH_BUTTON_L2_PRESSED_35;
                                                      HIDWORD(v96[5].mNext) = 0;
                                                      v96[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                      LODWORD(v96[3].mNext) = 5;
                                                      v96->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                      LODWORD(v96[7].mNext) = 1065353216;
                                                      HIDWORD(v96[7].mNext) = v4;
                                                      LODWORD(v96[3].mNext) = 6;
                                                      HIDWORD(v96[6].mNext) = 0;
                                                      v7 = (UFG::UIMessage *)v96;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    v98 = UFG::ActionDef_UIL2Repeat.mDataPerController[controllerIndex];
                                                    if ( v98 && v98->mActionTrue )
                                                    {
                                                      v99 = UFG::qMemoryPool::Allocate(
                                                              &gScaleformMemoryPool,
                                                              0x40ui64,
                                                              "UIInputHandler::UIMessagePadInput",
                                                              0i64,
                                                              1u);
                                                      if ( v99 )
                                                      {
                                                        v100 = v99 + 1;
                                                        v100->mNext = v100;
                                                        v100[1].mNext = v100;
                                                        v99->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                        LODWORD(v99[3].mNext) = -1;
                                                        v99[4].mNext = 0i64;
                                                        v99->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                        LODWORD(v99[5].mNext) = UI_HASH_BUTTON_L2_REPEAT_35;
                                                        HIDWORD(v99[5].mNext) = 0;
                                                        v99[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                        LODWORD(v99[3].mNext) = 5;
                                                        v99->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                        LODWORD(v99[7].mNext) = 1065353216;
                                                        HIDWORD(v99[7].mNext) = v4;
                                                        LODWORD(v99[3].mNext) = 6;
                                                        HIDWORD(v99[6].mNext) = 0;
                                                        v7 = (UFG::UIMessage *)v99;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      v101 = UFG::ActionDef_UIL2Released.mDataPerController[controllerIndex];
                                                      if ( v101 && v101->mActionTrue )
                                                      {
                                                        this->mState[controllerIndex][1] = 0;
                                                        v102 = UFG::qMemoryPool::Allocate(
                                                                 &gScaleformMemoryPool,
                                                                 0x40ui64,
                                                                 "UIInputHandler::UIMessagePadInput",
                                                                 0i64,
                                                                 1u);
                                                        if ( v102 )
                                                        {
                                                          v103 = v102 + 1;
                                                          v103->mNext = v103;
                                                          v103[1].mNext = v103;
                                                          v102->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                          LODWORD(v102[3].mNext) = -1;
                                                          v102[4].mNext = 0i64;
                                                          v102->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                          LODWORD(v102[5].mNext) = UI_HASH_BUTTON_L2_RELEASED_35;
                                                          HIDWORD(v102[5].mNext) = 0;
                                                          v102[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                          LODWORD(v102[3].mNext) = 5;
                                                          v102->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                          *(UFG::allocator::free_link **)((char *)&v102[6].mNext + 4) = 0i64;
                                                          HIDWORD(v102[7].mNext) = v4;
                                                          LODWORD(v102[3].mNext) = 6;
                                                          v7 = (UFG::UIMessage *)v102;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        v104 = UFG::ActionDef_UIL3Pressed.mDataPerController[controllerIndex];
                                                        if ( v104 && v104->mActionTrue )
                                                        {
                                                          this->mState[controllerIndex][1] = 0;
                                                          v105 = UFG::qMemoryPool::Allocate(
                                                                   &gScaleformMemoryPool,
                                                                   0x40ui64,
                                                                   "UIInputHandler::UIMessagePadInput",
                                                                   0i64,
                                                                   1u);
                                                          if ( v105 )
                                                          {
                                                            v106 = v105 + 1;
                                                            v106->mNext = v106;
                                                            v106[1].mNext = v106;
                                                            v105->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                            LODWORD(v105[3].mNext) = -1;
                                                            v105[4].mNext = 0i64;
                                                            v105->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                            LODWORD(v105[5].mNext) = UI_HASH_BUTTON_L3_PRESSED_35;
                                                            HIDWORD(v105[5].mNext) = 0;
                                                            v105[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                            LODWORD(v105[3].mNext) = 5;
                                                            v105->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                            LODWORD(v105[7].mNext) = 1065353216;
                                                            HIDWORD(v105[7].mNext) = v4;
                                                            LODWORD(v105[3].mNext) = 6;
                                                            HIDWORD(v105[6].mNext) = 0;
                                                            v7 = (UFG::UIMessage *)v105;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          v107 = UFG::ActionDef_UIL3Repeat.mDataPerController[controllerIndex];
                                                          if ( v107 && v107->mActionTrue )
                                                          {
                                                            v108 = UFG::qMemoryPool::Allocate(
                                                                     &gScaleformMemoryPool,
                                                                     0x40ui64,
                                                                     "UIInputHandler::UIMessagePadInput",
                                                                     0i64,
                                                                     1u);
                                                            if ( v108 )
                                                            {
                                                              v109 = v108 + 1;
                                                              v109->mNext = v109;
                                                              v109[1].mNext = v109;
                                                              v108->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                              LODWORD(v108[3].mNext) = -1;
                                                              v108[4].mNext = 0i64;
                                                              v108->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                              LODWORD(v108[5].mNext) = UI_HASH_BUTTON_L3_REPEAT_35;
                                                              HIDWORD(v108[5].mNext) = 0;
                                                              v108[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                              LODWORD(v108[3].mNext) = 5;
                                                              v108->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                              LODWORD(v108[7].mNext) = 1065353216;
                                                              HIDWORD(v108[7].mNext) = v4;
                                                              LODWORD(v108[3].mNext) = 6;
                                                              HIDWORD(v108[6].mNext) = 0;
                                                              v7 = (UFG::UIMessage *)v108;
                                                            }
                                                          }
                                                          else
                                                          {
                                                            v110 = UFG::ActionDef_UIL3Released.mDataPerController[controllerIndex];
                                                            if ( v110 && v110->mActionTrue )
                                                            {
                                                              this->mState[controllerIndex][1] = 0;
                                                              v111 = UFG::qMemoryPool::Allocate(
                                                                       &gScaleformMemoryPool,
                                                                       0x40ui64,
                                                                       "UIInputHandler::UIMessagePadInput",
                                                                       0i64,
                                                                       1u);
                                                              if ( v111 )
                                                              {
                                                                v112 = v111 + 1;
                                                                v112->mNext = v112;
                                                                v112[1].mNext = v112;
                                                                v111->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                LODWORD(v111[3].mNext) = -1;
                                                                v111[4].mNext = 0i64;
                                                                v111->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                LODWORD(v111[5].mNext) = UI_HASH_BUTTON_L3_RELEASED_35;
                                                                HIDWORD(v111[5].mNext) = 0;
                                                                v111[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                LODWORD(v111[3].mNext) = 5;
                                                                v111->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                *(UFG::allocator::free_link **)((char *)&v111[6].mNext
                                                                                              + 4) = 0i64;
                                                                HIDWORD(v111[7].mNext) = v4;
                                                                LODWORD(v111[3].mNext) = 6;
                                                                v7 = (UFG::UIMessage *)v111;
                                                              }
                                                            }
                                                            else
                                                            {
                                                              v113 = UFG::ActionDef_UIR1Pressed.mDataPerController[controllerIndex];
                                                              if ( v113 && v113->mActionTrue )
                                                              {
                                                                this->mState[controllerIndex][1] = 0;
                                                                v114 = UFG::qMemoryPool::Allocate(
                                                                         &gScaleformMemoryPool,
                                                                         0x40ui64,
                                                                         "UIInputHandler::UIMessagePadInput",
                                                                         0i64,
                                                                         1u);
                                                                if ( v114 )
                                                                {
                                                                  v115 = v114 + 1;
                                                                  v115->mNext = v115;
                                                                  v115[1].mNext = v115;
                                                                  v114->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                  LODWORD(v114[3].mNext) = -1;
                                                                  v114[4].mNext = 0i64;
                                                                  v114->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                  LODWORD(v114[5].mNext) = UI_HASH_BUTTON_R1_PRESSED_35;
                                                                  HIDWORD(v114[5].mNext) = 0;
                                                                  v114[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                  LODWORD(v114[3].mNext) = 5;
                                                                  v114->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                  LODWORD(v114[7].mNext) = 1065353216;
                                                                  HIDWORD(v114[7].mNext) = v4;
                                                                  LODWORD(v114[3].mNext) = 6;
                                                                  HIDWORD(v114[6].mNext) = 0;
                                                                  v7 = (UFG::UIMessage *)v114;
                                                                }
                                                              }
                                                              else
                                                              {
                                                                v116 = UFG::ActionDef_UIR1Repeat.mDataPerController[controllerIndex];
                                                                if ( v116 && v116->mActionTrue )
                                                                {
                                                                  v117 = UFG::qMemoryPool::Allocate(
                                                                           &gScaleformMemoryPool,
                                                                           0x40ui64,
                                                                           "UIInputHandler::UIMessagePadInput",
                                                                           0i64,
                                                                           1u);
                                                                  if ( v117 )
                                                                  {
                                                                    v118 = v117 + 1;
                                                                    v118->mNext = v118;
                                                                    v118[1].mNext = v118;
                                                                    v117->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                    LODWORD(v117[3].mNext) = -1;
                                                                    v117[4].mNext = 0i64;
                                                                    v117->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                    LODWORD(v117[5].mNext) = UI_HASH_BUTTON_R1_REPEAT_35;
                                                                    HIDWORD(v117[5].mNext) = 0;
                                                                    v117[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                    LODWORD(v117[3].mNext) = 5;
                                                                    v117->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                    LODWORD(v117[7].mNext) = 1065353216;
                                                                    HIDWORD(v117[7].mNext) = v4;
                                                                    LODWORD(v117[3].mNext) = 6;
                                                                    HIDWORD(v117[6].mNext) = 0;
                                                                    v7 = (UFG::UIMessage *)v117;
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  v119 = UFG::ActionDef_UIR1Released.mDataPerController[controllerIndex];
                                                                  if ( v119 && v119->mActionTrue )
                                                                  {
                                                                    this->mState[controllerIndex][1] = 0;
                                                                    v120 = UFG::qMemoryPool::Allocate(
                                                                             &gScaleformMemoryPool,
                                                                             0x40ui64,
                                                                             "UIInputHandler::UIMessagePadInput",
                                                                             0i64,
                                                                             1u);
                                                                    if ( v120 )
                                                                    {
                                                                      v121 = v120 + 1;
                                                                      v121->mNext = v121;
                                                                      v121[1].mNext = v121;
                                                                      v120->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                      LODWORD(v120[3].mNext) = -1;
                                                                      v120[4].mNext = 0i64;
                                                                      v120->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                      LODWORD(v120[5].mNext) = UI_HASH_BUTTON_R1_RELEASED_35;
                                                                      HIDWORD(v120[5].mNext) = 0;
                                                                      v120[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                      LODWORD(v120[3].mNext) = 5;
                                                                      v120->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                      *(UFG::allocator::free_link **)((char *)&v120[6].mNext + 4) = 0i64;
                                                                      HIDWORD(v120[7].mNext) = v4;
                                                                      LODWORD(v120[3].mNext) = 6;
                                                                      v7 = (UFG::UIMessage *)v120;
                                                                    }
                                                                  }
                                                                  else
                                                                  {
                                                                    v122 = UFG::ActionDef_UIR2Pressed.mDataPerController[controllerIndex];
                                                                    if ( v122 && v122->mActionTrue )
                                                                    {
                                                                      this->mState[controllerIndex][1] = 0;
                                                                      v123 = UFG::qMemoryPool::Allocate(
                                                                               &gScaleformMemoryPool,
                                                                               0x40ui64,
                                                                               "UIInputHandler::UIMessagePadInput",
                                                                               0i64,
                                                                               1u);
                                                                      if ( v123 )
                                                                      {
                                                                        v124 = v123 + 1;
                                                                        v124->mNext = v124;
                                                                        v124[1].mNext = v124;
                                                                        v123->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                        LODWORD(v123[3].mNext) = -1;
                                                                        v123[4].mNext = 0i64;
                                                                        v123->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                        LODWORD(v123[5].mNext) = UI_HASH_BUTTON_R2_PRESSED_35;
                                                                        HIDWORD(v123[5].mNext) = 0;
                                                                        v123[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                        LODWORD(v123[3].mNext) = 5;
                                                                        v123->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                        LODWORD(v123[7].mNext) = 1065353216;
                                                                        HIDWORD(v123[7].mNext) = v4;
                                                                        LODWORD(v123[3].mNext) = 6;
                                                                        HIDWORD(v123[6].mNext) = 0;
                                                                        v7 = (UFG::UIMessage *)v123;
                                                                      }
                                                                    }
                                                                    else
                                                                    {
                                                                      v125 = UFG::ActionDef_UIR2Repeat.mDataPerController[controllerIndex];
                                                                      if ( v125 && v125->mActionTrue )
                                                                      {
                                                                        v126 = UFG::qMemoryPool::Allocate(
                                                                                 &gScaleformMemoryPool,
                                                                                 0x40ui64,
                                                                                 "UIInputHandler::UIMessagePadInput",
                                                                                 0i64,
                                                                                 1u);
                                                                        if ( v126 )
                                                                        {
                                                                          v127 = v126 + 1;
                                                                          v127->mNext = v127;
                                                                          v127[1].mNext = v127;
                                                                          v126->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                          LODWORD(v126[3].mNext) = -1;
                                                                          v126[4].mNext = 0i64;
                                                                          v126->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                          LODWORD(v126[5].mNext) = UI_HASH_BUTTON_R2_REPEAT_35;
                                                                          HIDWORD(v126[5].mNext) = 0;
                                                                          v126[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                          LODWORD(v126[3].mNext) = 5;
                                                                          v126->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                          LODWORD(v126[7].mNext) = 1065353216;
                                                                          HIDWORD(v126[7].mNext) = v4;
                                                                          LODWORD(v126[3].mNext) = 6;
                                                                          HIDWORD(v126[6].mNext) = 0;
                                                                          v7 = (UFG::UIMessage *)v126;
                                                                        }
                                                                      }
                                                                      else
                                                                      {
                                                                        v128 = UFG::ActionDef_UIR2Released.mDataPerController[controllerIndex];
                                                                        if ( v128 && v128->mActionTrue )
                                                                        {
                                                                          this->mState[controllerIndex][1] = 0;
                                                                          v129 = UFG::qMemoryPool::Allocate(
                                                                                   &gScaleformMemoryPool,
                                                                                   0x40ui64,
                                                                                   "UIInputHandler::UIMessagePadInput",
                                                                                   0i64,
                                                                                   1u);
                                                                          if ( v129 )
                                                                          {
                                                                            v130 = v129 + 1;
                                                                            v130->mNext = v130;
                                                                            v130[1].mNext = v130;
                                                                            v129->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                            LODWORD(v129[3].mNext) = -1;
                                                                            v129[4].mNext = 0i64;
                                                                            v129->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                            LODWORD(v129[5].mNext) = UI_HASH_BUTTON_R2_RELEASED_35;
                                                                            HIDWORD(v129[5].mNext) = 0;
                                                                            v129[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                            LODWORD(v129[3].mNext) = 5;
                                                                            v129->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                            *(UFG::allocator::free_link **)((char *)&v129[6].mNext + 4) = 0i64;
                                                                            HIDWORD(v129[7].mNext) = v4;
                                                                            LODWORD(v129[3].mNext) = 6;
                                                                            v7 = (UFG::UIMessage *)v129;
                                                                          }
                                                                        }
                                                                        else
                                                                        {
                                                                          v131 = UFG::ActionDef_UIR3Pressed.mDataPerController[controllerIndex];
                                                                          if ( v131 && v131->mActionTrue )
                                                                          {
                                                                            this->mState[controllerIndex][1] = 0;
                                                                            v132 = UFG::qMemoryPool::Allocate(
                                                                                     &gScaleformMemoryPool,
                                                                                     0x40ui64,
                                                                                     "UIInputHandler::UIMessagePadInput",
                                                                                     0i64,
                                                                                     1u);
                                                                            if ( v132 )
                                                                            {
                                                                              v133 = v132 + 1;
                                                                              v133->mNext = v133;
                                                                              v133[1].mNext = v133;
                                                                              v132->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                              LODWORD(v132[3].mNext) = -1;
                                                                              v132[4].mNext = 0i64;
                                                                              v132->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                              LODWORD(v132[5].mNext) = UI_HASH_BUTTON_R3_PRESSED_35;
                                                                              HIDWORD(v132[5].mNext) = 0;
                                                                              v132[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                              LODWORD(v132[3].mNext) = 5;
                                                                              v132->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                              LODWORD(v132[7].mNext) = 1065353216;
                                                                              HIDWORD(v132[7].mNext) = v4;
                                                                              LODWORD(v132[3].mNext) = 6;
                                                                              HIDWORD(v132[6].mNext) = 0;
                                                                              v7 = (UFG::UIMessage *)v132;
                                                                            }
                                                                          }
                                                                          else
                                                                          {
                                                                            v134 = UFG::ActionDef_UIR3Repeat.mDataPerController[controllerIndex];
                                                                            if ( v134 && v134->mActionTrue )
                                                                            {
                                                                              v135 = UFG::qMemoryPool::Allocate(
                                                                                       &gScaleformMemoryPool,
                                                                                       0x40ui64,
                                                                                       "UIInputHandler::UIMessagePadInput",
                                                                                       0i64,
                                                                                       1u);
                                                                              if ( v135 )
                                                                              {
                                                                                v136 = v135 + 1;
                                                                                v136->mNext = v136;
                                                                                v136[1].mNext = v136;
                                                                                v135->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                                LODWORD(v135[3].mNext) = -1;
                                                                                v135[4].mNext = 0i64;
                                                                                v135->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                                LODWORD(v135[5].mNext) = UI_HASH_BUTTON_R3_REPEAT_35;
                                                                                HIDWORD(v135[5].mNext) = 0;
                                                                                v135[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                                LODWORD(v135[3].mNext) = 5;
                                                                                v135->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                                LODWORD(v135[7].mNext) = 1065353216;
                                                                                HIDWORD(v135[7].mNext) = v4;
                                                                                LODWORD(v135[3].mNext) = 6;
                                                                                HIDWORD(v135[6].mNext) = 0;
                                                                                v7 = (UFG::UIMessage *)v135;
                                                                              }
                                                                            }
                                                                            else
                                                                            {
                                                                              v137 = UFG::ActionDef_UIR3Released.mDataPerController[controllerIndex];
                                                                              if ( v137 )
                                                                              {
                                                                                if ( v137->mActionTrue )
                                                                                {
                                                                                  this->mState[controllerIndex][1] = 0;
                                                                                  v138 = UFG::qMemoryPool::Allocate(
                                                                                           &gScaleformMemoryPool,
                                                                                           0x40ui64,
                                                                                           "UIInputHandler::UIMessagePadInput",
                                                                                           0i64,
                                                                                           1u);
                                                                                  if ( v138 )
                                                                                  {
                                                                                    v139 = v138 + 1;
                                                                                    v139->mNext = v139;
                                                                                    v139[1].mNext = v139;
                                                                                    v138->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
                                                                                    LODWORD(v138[3].mNext) = -1;
                                                                                    v138[4].mNext = 0i64;
                                                                                    v138->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
                                                                                    LODWORD(v138[5].mNext) = UI_HASH_BUTTON_R3_RELEASED_35;
                                                                                    HIDWORD(v138[5].mNext) = 0;
                                                                                    v138[6].mNext = (UFG::allocator::free_link *)-1i64;
                                                                                    LODWORD(v138[3].mNext) = 5;
                                                                                    v138->mNext = (UFG::allocator::free_link *)&UFG::UIMessagePadInput::`vftable;
                                                                                    *(UFG::allocator::free_link **)((char *)&v138[6].mNext + 4) = 0i64;
                                                                                    HIDWORD(v138[7].mNext) = v4;
                                                                                    LODWORD(v138[3].mNext) = 6;
                                                                                    v7 = (UFG::UIMessage *)v138;
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
  UFG::UIInputHandler::update(v6, elapsed, v7, v5, UIINPUT_BUTTON);
}

// File Line: 552
// RVA: 0xA32550
void __fastcall UFG::UIInputHandler::update(UFG::UIInputHandler *this, float elapsed, UFG::UIMessage *msg, int controllerIndex, UFG::eInputHandlerType type)
{
  UFG::UIInputHandler *v5; // rdx
  __int64 v6; // rcx
  signed __int64 v7; // r10
  UFG::eUIInputHandlerState v8; // er9
  int v9; // er9
  signed __int64 v10; // rax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  signed __int64 v14; // r9
  float v15; // xmm1_4
  float v16; // eax

  v5 = this;
  if ( !msg )
    return;
  v6 = controllerIndex;
  v7 = (signed int)type + 2i64 * controllerIndex;
  v8 = v5->mState[0][v7];
  if ( v8 == UIINPUT_IDLE )
  {
    v16 = v5->mFirstDelay;
    v5->mState[0][v7] = 1;
    v5->mCurrentDelay[0][(signed int)type + 2 * v6] = v16;
    UFG::UIScreenManagerBase::queueMessageEx((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, msg);
    return;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v14 = (signed int)type + 2 * v6;
    v15 = v5->mCurrentDelay[0][v14] - elapsed;
    v5->mCurrentDelay[0][v14] = v15;
    if ( v15 < 0.0 )
    {
      v5->mState[0][v7] = 2;
      v5->mCurrentDelay[0][v14] = v5->mMaxRepeatDelay;
      v5->mRepeatDelay[v6] = v5->mMaxRepeatDelay;
      UFG::UIScreenManagerBase::queueMessageEx(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        msg);
      return;
    }
    goto LABEL_11;
  }
  if ( v9 != 1
    || (v10 = (signed int)type + 2 * v6,
        v11 = v5->mCurrentDelay[0][v10] - elapsed,
        v5->mCurrentDelay[0][v10] = v11,
        v11 >= 0.0) )
  {
LABEL_11:
    msg->vfptr->__vecDelDtor((UFG::UICommand *)msg, 1u);
    return;
  }
  v12 = v5->mRepeatDelay[v6] - v5->mRepeatSpeed;
  v5->mRepeatDelay[v6] = v12;
  v13 = v5->mMinRepeatDelay;
  if ( v12 < v13 )
  {
    v5->mRepeatDelay[v6] = v13;
    v12 = v13;
  }
  v5->mCurrentDelay[0][v10] = v12;
  UFG::UIScreenManagerBase::queueMessageEx((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, msg);
}

// File Line: 617
// RVA: 0xA2F3F0
void __fastcall UFG::UIInputHandler::handleKeyboardInput(UFG::UIInputHandler *this, UFG::Event *msg)
{
  int v2; // ebx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  UFG::allocator::free_link *v5; // rax

  v2 = msg->mUserData1;
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
      LOBYTE(v4[7].mNext) = v2;
      HIDWORD(v4[7].mNext) = 15;
      LODWORD(v4[3].mNext) = 6;
      HIDWORD(v4[6].mNext) = 2;
    }
    else
    {
      v4 = 0i64;
    }
    if ( v4 )
      UFG::UIScreenManagerBase::queueMessageEx(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        (UFG::UIMessage *)v4);
  }
}

// File Line: 640
// RVA: 0xA2E040
void __fastcall UFG::UIInputHandler::handleControllerDisconnect(UFG::UIInputHandler *this, UFG::Event *msg)
{
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_ACTIVE_CONTROLLER_DISCONNECTED_52,
    0xFFFFFFFF);
}

// File Line: 646
// RVA: 0xA2E060
void __fastcall UFG::UIInputHandler::handleControllerReconnect(UFG::UIInputHandler *this, UFG::Event *msg)
{
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_ACTIVE_CONTROLLER_RECONNECTED_52,
    0xFFFFFFFF);
}

// File Line: 652
// RVA: 0xA2F780
void __fastcall UFG::UIInputHandler::handleMouseInput(UFG::UIInputHandler *this, UFG::Event *msg)
{
  UFG::Event *v2; // r14
  int v3; // ebx
  int rawY; // edi
  int v5; // esi
  int v6; // ebp
  int v7; // eax
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
  unsigned int v23; // er15
  UFG::allocator::free_link *v24; // rax
  UFG::allocator::free_link *v25; // rax
  unsigned int v26; // er15
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::allocator::free_link *v30; // rax
  UFG::allocator::free_link *v31; // [rsp+88h] [rbp+10h]
  float v32; // [rsp+90h] [rbp+18h]
  float v33; // [rsp+94h] [rbp+1Ch]

  v2 = msg;
  UFG::UIScreenManagerBase::getViewportOffsetAndScale(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    (UFG::qVector2 *)&v31,
    (UFG::qVector2 *)&v32);
  v3 = HIDWORD(v2[1].vfptr);
  rawY = (int)v2[1].mPrev;
  v5 = (signed int)(float)((float)((float)SHIDWORD(v2[1].vfptr) - *(float *)&v31) / v32);
  v6 = (signed int)(float)((float)((float)SLODWORD(v2[1].mPrev) - *((float *)&v31 + 1)) / v33);
  v7 = (int)v2[1].vfptr;
  if ( v7 != 512 )
  {
    switch ( v7 )
    {
      case 513:
        v11 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v9 = v11;
        v31 = v11;
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
          HIDWORD(v9[8].mNext) = v3;
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
        v31 = v13;
        if ( v13 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v13,
            UI_HASH_MOUSE_BUTTON_LEFT_RELEASED_35,
            v5,
            v6,
            v3,
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
        v31 = v15;
        if ( v15 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v15,
            UI_HASH_MOUSE_BUTTON_RIGHT_PRESSED_35,
            v5,
            v6,
            v3,
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
        v31 = v17;
        if ( v17 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v17,
            UI_HASH_MOUSE_BUTTON_RIGHT_RELEASED_35,
            v5,
            v6,
            v3,
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
        v31 = v19;
        if ( v19 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v19,
            UI_HASH_MOUSE_BUTTON_MIDDLE_PRESSED_35,
            v5,
            v6,
            v3,
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
        v31 = v21;
        if ( v21 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v21,
            UI_HASH_MOUSE_BUTTON_MIDDLE_RELEASED_35,
            v5,
            v6,
            v3,
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
        if ( HIDWORD(v2[1].mPrev) == 5 )
          v23 = UI_HASH_MOUSE_BUTTON_4_PRESSED_35;
        v24 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v31 = v24;
        if ( v24 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput((UFG::UIMessageMouseInput *)v24, v23, v5, v6, v3, rawY, 0);
          v9 = v25;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      case 524:
        v26 = UI_HASH_MOUSE_BUTTON_5_RELEASED_35;
        if ( HIDWORD(v2[1].mPrev) == 5 )
          v26 = UI_HASH_MOUSE_BUTTON_4_RELEASED_35;
        v27 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v31 = v27;
        if ( v27 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput((UFG::UIMessageMouseInput *)v27, v26, v5, v6, v3, rawY, 0);
          v9 = v28;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      case 522:
        v29 = UFG::qMemoryPool::Allocate(
                &gScaleformMemoryPool,
                0x50ui64,
                "UIInputHandler::UIMessageMouseInput",
                0i64,
                1u);
        v31 = v29;
        if ( v29 )
        {
          UFG::UIMessageMouseInput::UIMessageMouseInput(
            (UFG::UIMessageMouseInput *)v29,
            UI_HASH_MOUSE_WHEEL_SCROLL_35,
            v5,
            v6,
            v3,
            rawY,
            (int)v2[1].mNext);
          v9 = v30;
        }
        else
        {
          v9 = 0i64;
        }
        break;
      default:
        return;
    }
    goto LABEL_56;
  }
  if ( gOldMouseX != v3 || gOldMouseY != rawY )
  {
    gOldMouseX = HIDWORD(v2[1].vfptr);
    gOldMouseY = rawY;
    v8 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x50ui64, "UIInputHandler::UIMessageMouseInput", 0i64, 1u);
    v9 = v8;
    v31 = v8;
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
      HIDWORD(v9[8].mNext) = v3;
      LODWORD(v9[9].mNext) = rawY;
      LODWORD(v9[3].mNext) = 6;
      HIDWORD(v9[6].mNext) = 3;
    }
    else
    {
      v9 = 0i64;
    }
LABEL_56:
    if ( v9 )
      UFG::UIScreenManagerBase::queueMessageEx(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        (UFG::UIMessage *)v9);
  }
}

