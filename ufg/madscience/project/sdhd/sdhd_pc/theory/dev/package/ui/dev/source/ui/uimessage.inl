// File Line: 20
// RVA: 0x5C9260
void __fastcall UFG::UICommandData::~UICommandData(UFG::UICommandData *this)
{
  this->vfptr = (UFG::UICommandDataVtbl *)&UFG::UICommandData::`vftable;
}

// File Line: 37
// RVA: 0x491670
void __fastcall UFG::UICommand::~UICommand(UFG::UICommand *this)
{
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v1; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mNext; // rax

  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  v1 = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 83
// RVA: 0xA23090
void __fastcall UFG::UICommandScreenPush::UICommandScreenPush(
        UFG::UICommandScreenPush *this,
        char *screenName,
        unsigned int screenUID,
        int controllerMask)
{
  this->mPrev = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->mNext = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = UICOMMAND_UNKNOWN;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommandScreenPush::`vftable;
  this->m_screenUID = screenUID;
  this->m_controllerMask = controllerMask;
  this->m_preCreatedInstance = 0i64;
  this->m_dimType = UFG::UIScreen::mDefaultDim;
  UFG::qStringCopy(this->m_screenName, 128, screenName, -1);
  this->m_commandType = UICOMMAND_SCREEN_PUSH;
}

// File Line: 326
// RVA: 0xA23000
void __fastcall UFG::UICommandOverlayPush::UICommandOverlayPush(
        UFG::UICommandOverlayPush *this,
        char *screenName,
        unsigned int screenUID,
        unsigned int priority,
        int controllerMask)
{
  this->mPrev = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->mNext = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = UICOMMAND_UNKNOWN;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommandOverlayPush::`vftable;
  this->m_screenUID = screenUID;
  this->m_priority = priority;
  this->m_controllerMask = controllerMask;
  this->m_preCreatedInstance = 0i64;
  UFG::qStringCopy(this->m_screenName, 128, screenName, -1);
  this->m_commandType = UICOMMAND_OVERLAY_PUSH;
}

// File Line: 399
// RVA: 0xA22F90
void __fastcall UFG::UICommandOverlayPop::UICommandOverlayPop(UFG::UICommandOverlayPop *this, char *screenName)
{
  this->mPrev = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->mNext = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = UICOMMAND_UNKNOWN;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommandOverlayPop::`vftable;
  this->m_screenUID = -1;
  UFG::qStringCopy(this->m_screenName, 128, screenName, -1);
  this->m_commandType = UICOMMAND_OVERLAY_POP;
}

// File Line: 556
// RVA: 0xA235A0
void __fastcall UFG::UIMessagePadInput::UIMessagePadInput(
        UFG::UIMessagePadInput *this,
        unsigned int messageId,
        float value,
        int controllerMask)
{
  this->mPrev = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->mNext = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = UICOMMAND_UNKNOWN;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable;
  this->m_messageId = messageId;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = UICOMMAND_MESSAGE;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessagePadInput::`vftable;
  this->m_value = value;
  this->m_controllerMask = controllerMask;
  this->m_commandType = UICOMMAND_INPUT;
  this->m_messageType = UIMESSAGE_PAD_INPUT;
}

// File Line: 614
// RVA: 0xA23620
void __fastcall UFG::UIMessagePadInputAnalogStick::UIMessagePadInputAnalogStick(
        UFG::UIMessagePadInputAnalogStick *this,
        unsigned int messageId,
        float xAxis,
        float yAxis,
        int controllerMask)
{
  this->mPrev = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->mNext = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = UICOMMAND_UNKNOWN;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable;
  this->m_messageId = messageId;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = UICOMMAND_MESSAGE;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessagePadInput::`vftable;
  this->m_value = 1.0;
  this->m_controllerMask = controllerMask;
  this->m_commandType = UICOMMAND_INPUT;
  this->m_messageType = UIMESSAGE_PAD_INPUT;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessagePadInputAnalogStick::`vftable;
  this->m_xAxis = xAxis;
  this->m_yAxis = yAxis;
  this->m_messageType = UIMESSAGE_PAD_INPUT_ANALOG_STICK;
}

// File Line: 688
// RVA: 0xA23500
void __fastcall UFG::UIMessageMouseInput::UIMessageMouseInput(
        UFG::UIMessageMouseInput *this,
        unsigned int messageId,
        int xPos,
        int yPos,
        int rawX,
        int rawY,
        int mouseWheel)
{
  this->mPrev = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->mNext = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = UICOMMAND_UNKNOWN;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable;
  this->m_messageId = messageId;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = UICOMMAND_MESSAGE;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessageMouseInput::`vftable;
  this->m_xPos = xPos;
  this->m_yPos = yPos;
  this->m_mouseWheel = mouseWheel;
  this->m_RawXPos = rawX;
  this->m_RawYPos = rawY;
  this->m_commandType = UICOMMAND_INPUT;
  this->m_messageType = UIMESSAGE_MOUSE_INPUT;
}

// File Line: 746
// RVA: 0xA23460
void __fastcall UFG::UIMessageFlash::UIMessageFlash(
        UFG::UIMessageFlash *this,
        unsigned int messageId,
        Scaleform::GFx::Movie *receiver,
        UFG::qString *args)
{
  this->mPrev = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->mNext = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = UICOMMAND_UNKNOWN;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable;
  this->m_messageId = messageId;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = UICOMMAND_MESSAGE;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessageFlash::`vftable;
  UFG::qString::qString(&this->m_args, args);
  this->mReceiverMovieView = receiver;
  this->m_commandType = UICOMMAND_FLASH_COMMAND;
  this->m_messageType = UIMESSAGE_FLASH;
}

