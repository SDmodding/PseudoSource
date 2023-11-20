// File Line: 20
// RVA: 0x5C9260
void __fastcall UFG::UICommandData::~UICommandData(UFG::UICommandData *this)
{
  this->vfptr = (UFG::UICommandDataVtbl *)&UFG::UICommandData::`vftable';
}

// File Line: 37
// RVA: 0x491670
void __fastcall UFG::UICommand::~UICommand(UFG::UICommand *this)
{
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v1; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v2; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v3; // rax

  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable';
  v1 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 83
// RVA: 0xA23090
void __fastcall UFG::UICommandScreenPush::UICommandScreenPush(UFG::UICommandScreenPush *this, const char *screenName, unsigned int screenUID, int controllerMask)
{
  UFG::UICommandScreenPush *v4; // rbx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v5; // rax

  v4 = this;
  v5 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable';
  this->m_commandType = -1;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommandScreenPush::`vftable';
  this->m_screenUID = screenUID;
  this->m_controllerMask = controllerMask;
  this->m_preCreatedInstance = 0i64;
  this->m_dimType = UFG::UIScreen::mDefaultDim;
  UFG::qStringCopy(this->m_screenName, 128, screenName, -1);
  v4->m_commandType = 0;
}

// File Line: 326
// RVA: 0xA23000
void __fastcall UFG::UICommandOverlayPush::UICommandOverlayPush(UFG::UICommandOverlayPush *this, const char *screenName, unsigned int screenUID, unsigned int priority, int controllerMask)
{
  UFG::UICommandOverlayPush *v5; // rbx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v6; // rax

  v5 = this;
  v6 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable';
  this->m_commandType = -1;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommandOverlayPush::`vftable';
  this->m_screenUID = screenUID;
  this->m_priority = priority;
  this->m_controllerMask = controllerMask;
  this->m_preCreatedInstance = 0i64;
  UFG::qStringCopy(this->m_screenName, 128, screenName, -1);
  v5->m_commandType = 3;
}

// File Line: 399
// RVA: 0xA22F90
void __fastcall UFG::UICommandOverlayPop::UICommandOverlayPop(UFG::UICommandOverlayPop *this, const char *screenName)
{
  UFG::UICommandOverlayPop *v2; // rbx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v3; // rax

  v2 = this;
  v3 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable';
  this->m_commandType = -1;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommandOverlayPop::`vftable';
  this->m_screenUID = -1;
  UFG::qStringCopy(this->m_screenName, 128, screenName, -1);
  v2->m_commandType = 4;
}

// File Line: 556
// RVA: 0xA235A0
void __fastcall UFG::UIMessagePadInput::UIMessagePadInput(UFG::UIMessagePadInput *this, unsigned int messageId, float value, int controllerMask)
{
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v4; // rax

  v4 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable';
  this->m_commandType = -1;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable';
  this->m_messageId = messageId;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = 5;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessagePadInput::`vftable';
  this->m_value = value;
  this->m_controllerMask = controllerMask;
  this->m_commandType = 6;
  this->m_messageType = 0;
}

// File Line: 614
// RVA: 0xA23620
void __fastcall UFG::UIMessagePadInputAnalogStick::UIMessagePadInputAnalogStick(UFG::UIMessagePadInputAnalogStick *this, unsigned int messageId, float xAxis, float yAxis, int controllerMask)
{
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v5; // rax

  v5 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable';
  this->m_commandType = -1;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable';
  this->m_messageId = messageId;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = 5;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessagePadInput::`vftable';
  this->m_value = 1.0;
  this->m_controllerMask = controllerMask;
  this->m_commandType = 6;
  this->m_messageType = 0;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessagePadInputAnalogStick::`vftable';
  this->m_xAxis = xAxis;
  this->m_yAxis = yAxis;
  this->m_messageType = 1;
}

// File Line: 688
// RVA: 0xA23500
void __fastcall UFG::UIMessageMouseInput::UIMessageMouseInput(UFG::UIMessageMouseInput *this, unsigned int messageId, int xPos, int yPos, int rawX, int rawY, int mouseWheel)
{
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v7; // rax

  v7 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable';
  this->m_commandType = -1;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable';
  this->m_messageId = messageId;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = 5;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessageMouseInput::`vftable';
  this->m_xPos = xPos;
  this->m_yPos = yPos;
  this->m_mouseWheel = mouseWheel;
  this->m_RawXPos = rawX;
  this->m_RawYPos = rawY;
  this->m_commandType = 6;
  this->m_messageType = 3;
}

// File Line: 746
// RVA: 0xA23460
void __fastcall UFG::UIMessageFlash::UIMessageFlash(UFG::UIMessageFlash *this, unsigned int messageId, Scaleform::GFx::Movie *receiver, UFG::qString *args)
{
  Scaleform::GFx::Movie *v4; // rbx
  UFG::UIMessageFlash *v5; // rdi
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v6; // rax

  v4 = receiver;
  v5 = this;
  v6 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable';
  this->m_commandType = -1;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable';
  this->m_messageId = messageId;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = 5;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessageFlash::`vftable';
  UFG::qString::qString(&this->m_args, args);
  v5->mReceiverMovieView = v4;
  v5->m_commandType = 7;
  v5->m_messageType = 4;
}

