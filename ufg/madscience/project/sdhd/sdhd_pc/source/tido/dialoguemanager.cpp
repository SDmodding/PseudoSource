// File Line: 58
// RVA: 0x155CB20
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone, "play_cellphone");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone__);
}

// File Line: 59
// RVA: 0x155C9A0
__int64 UFG::_dynamic_initializer_for__qwsPlay2D__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlay2D, "play_2d");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlay2D__);
}

// File Line: 60
// RVA: 0x155CA30
__int64 UFG::_dynamic_initializer_for__qwsPlayCB__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCB, "play_cb");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCB__);
}

// File Line: 61
// RVA: 0x155CB80
__int64 UFG::_dynamic_initializer_for__qwsPlayDrivingNoLip__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayDrivingNoLip, "play_driving_no_lip");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayDrivingNoLip__);
}

// File Line: 63
// RVA: 0x155CA60
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone0__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone0, "play_cellphone_0");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone0__);
}

// File Line: 64
// RVA: 0x155CA90
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone2__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone2, "play_cellphone_2");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone2__);
}

// File Line: 65
// RVA: 0x155CAC0
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone4__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone4, "play_cellphone_4");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone4__);
}

// File Line: 66
// RVA: 0x155CAF0
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone6__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone6, "play_cellphone_6");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone6__);
}

// File Line: 67
// RVA: 0x155C9D0
__int64 UFG::_dynamic_initializer_for__qwsPlayCB4__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCB4, "play_cb_4");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCB4__);
}

// File Line: 68
// RVA: 0x155CA00
__int64 UFG::_dynamic_initializer_for__qwsPlayCB6__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCB6, "play_cb_6");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCB6__);
}

// File Line: 69
// RVA: 0x155CBB0
__int64 UFG::_dynamic_initializer_for__qwsPlayPoliceBullhorn__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayPoliceBullhorn, "Play_police_bullhorn");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayPoliceBullhorn__);
}

// File Line: 70
// RVA: 0x155CB50
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhoneRingOutgoing__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhoneRingOutgoing, "Play_cellphone_ring_outgoing");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhoneRingOutgoing__);
}

// File Line: 138
// RVA: 0x5931C0
void __fastcall UFG::Conversation::Conversation(
        UFG::Conversation *this,
        unsigned int uid,
        UFG::Conversation::eConversationType type)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  this->vfptr = (UFG::ConversationVtbl *)&UFG::Conversation::`vftable;
  this->m_activeElement = 0i64;
  *(_QWORD *)&this->m_state = 0i64;
  *(_DWORD *)&this->m_curLine = 0;
  this->m_linePriority = 7;
  this->m_type = type;
  this->m_lines.mNode.mPrev = &this->m_lines.mNode;
  this->m_lines.mNode.mNext = &this->m_lines.mNode;
  this->m_prevPlayed.mNode.mPrev = &this->m_prevPlayed.mNode;
  this->m_prevPlayed.mNode.mNext = &this->m_prevPlayed.mNode;
  this->m_animationBanks.mNode.mPrev = &this->m_animationBanks.mNode;
  this->m_animationBanks.mNode.mNext = &this->m_animationBanks.mNode;
  this->m_externalSourcePlaybackEvent = 0;
  *(_QWORD *)&this->m_topic = 25i64;
  *(_QWORD *)&this->m_maxSeparationDistance = 1101004800i64;
  this->m_interruptedTime = 0.0;
  *(_DWORD *)&this->m_avoidRepeatingLastNLines = 1;
  *((_BYTE *)this + 168) = -118;
  *((_BYTE *)this + 169) = *((_BYTE *)this + 169) & 0xF1 | 0xA;
  UFG::Conversation::Clear(this);
}

// File Line: 154
// RVA: 0x594300
void __fastcall UFG::Conversation::~Conversation(UFG::Conversation *this)
{
  UFG::qList<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol>,1,0> *p_m_animationBanks; // rbx
  UFG::qNode<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol> > *mPrev; // rcx
  UFG::qNode<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol> > *mNext; // rax
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v5; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v6; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v7; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v8; // rax

  this->vfptr = (UFG::ConversationVtbl *)&UFG::Conversation::`vftable;
  p_m_animationBanks = &this->m_animationBanks;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_animationBanks);
  mPrev = p_m_animationBanks->mNode.mPrev;
  mNext = p_m_animationBanks->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_animationBanks->mNode.mPrev = &p_m_animationBanks->mNode;
  p_m_animationBanks->mNode.mNext = &p_m_animationBanks->mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_prevPlayed);
  v5 = this->m_prevPlayed.mNode.mPrev;
  v6 = this->m_prevPlayed.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->m_prevPlayed.mNode.mPrev = &this->m_prevPlayed.mNode;
  this->m_prevPlayed.mNode.mNext = &this->m_prevPlayed.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_lines);
  v7 = this->m_lines.mNode.mPrev;
  v8 = this->m_lines.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->m_lines.mNode.mPrev = &this->m_lines.mNode;
  this->m_lines.mNode.mNext = &this->m_lines.mNode;
}

// File Line: 164
// RVA: 0x5987F0
void __fastcall UFG::Conversation::Clear(UFG::Conversation *this)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mNext; // rax
  UFG::Conversation::eConversationType *i; // rdi
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v4; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mPrev; // rdx

  mNext = this->m_lines.mNode.mNext;
  for ( i = &this->m_type;
        &mNext[-1].mNext != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)i;
        mNext = this->m_lines.mNode.mNext )
  {
    v4 = mNext->mNext;
    mPrev = mNext->mPrev;
    mPrev->mNext = v4;
    v4->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    if ( mNext != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **, __int64))mNext[-1].mNext->mPrev)(
        &mNext[-1].mNext,
        1i64);
  }
  this->m_onResume = 0i64;
  this->m_onInterrupt = 0i64;
  this->m_activeElement = 0i64;
}

// File Line: 177
// RVA: 0x596020
char __fastcall UFG::Conversation::AddElement(UFG::Conversation *this, UFG::ConversationElement *element)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mPrev; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v3; // rdx

  mPrev = this->m_lines.mNode.mPrev;
  v3 = &element->UFG::qNode<UFG::ConversationElement,UFG::ConversationElement>;
  mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = &this->m_lines.mNode;
  this->m_lines.mNode.mPrev = v3;
  ++this->m_numElements;
  return 1;
}

// File Line: 197
// RVA: 0x5B09D0
bool __fastcall UFG::Conversation::UpdateInterruptState(UFG::Conversation *this, float delta_sec)
{
  float v2; // xmm1_4
  UFG::eInterruptType m_interruptType; // eax
  bool result; // al
  UFG::Conversation *v6; // rax
  UFG::Conversation *v7; // rcx
  float v8; // xmm0_4
  UFG::Conversation *m_onInterrupt; // rcx

  v2 = delta_sec + this->m_interruptedTime;
  this->m_state = this->m_newState;
  m_interruptType = this->m_interruptType;
  this->m_interruptedTime = v2;
  switch ( m_interruptType )
  {
    case eInterruptType_Separation:
      if ( UFG::Conversation::IsFurtherThanMaxSeparationDistance(this, this->m_activeElement) )
        goto LABEL_20;
      this->m_newState = eConversationState_Resume;
      return 1;
    case eInterruptType_Collision:
      m_onInterrupt = this->m_onInterrupt;
      if ( m_onInterrupt && m_onInterrupt->m_state == eConversationState_Finished )
      {
        *((_BYTE *)m_onInterrupt + 168) |= 2u;
        this->m_onInterrupt = 0i64;
      }
      if ( this->m_onInterrupt )
        goto LABEL_20;
      v8 = FLOAT_6_0;
      goto LABEL_18;
    case eInterruptType_GetOutOfVehicle:
    case eInterruptType_GunPointAt:
    case eInterruptType_PDAHangup:
    case eInterruptType_Social:
      v6 = this->m_onInterrupt;
      if ( !v6 || v6->m_state != eConversationState_Finished )
        goto LABEL_20;
      *((_BYTE *)v6 + 168) |= 2u;
      result = 1;
      this->m_onInterrupt = 0i64;
      break;
    case eInterruptType_HitReaction:
      v7 = this->m_onInterrupt;
      if ( v7 && v7->m_state == eConversationState_Finished )
      {
        *((_BYTE *)v7 + 168) |= 2u;
        this->m_onInterrupt = 0i64;
      }
      if ( !this->m_onInterrupt )
      {
        v8 = FLOAT_2_0;
LABEL_18:
        if ( v8 < this->m_interruptedTime )
        {
          this->m_interruptedTime = 0.0;
          this->m_newState = eConversationState_Resume;
        }
      }
      goto LABEL_20;
    case eInterruptType_Death:
      UFG::Conversation::ForceFinish(this, 0x140000000i64);
      return 1;
    default:
LABEL_20:
      result = 1;
      break;
  }
  return result;
}

// File Line: 294
// RVA: 0x5B1110
bool __fastcall UFG::Conversation::UpdateResumeState(UFG::Conversation *this, float delta_sec)
{
  UFG::Conversation *m_onResume; // rcx
  bool result; // al
  UFG::eConversationState m_state; // eax
  bool v6; // zf

  m_onResume = this->m_onResume;
  if ( m_onResume )
  {
    m_state = m_onResume->m_state;
    if ( m_state )
    {
      if ( m_state == eConversationState_Finished )
      {
        this->m_newState = eConversationState_Playing;
        this->m_interruptedTime = 0.0;
        *((_BYTE *)m_onResume + 168) |= 2u;
        this->m_onResume = 0i64;
      }
    }
    else
    {
      v6 = this->m_interruptType == eInterruptType_GetOutOfVehicle;
      this->m_interruptedTime = delta_sec + this->m_interruptedTime;
      if ( v6 && UFG::Conversation::ConversantsInSameVehicle(this) )
      {
        UFG::Conversation::Start(this->m_onResume);
        result = 1;
        this->m_interruptType = eInterruptType_None;
        return result;
      }
    }
  }
  else if ( this->m_interruptType != eInterruptType_GetOutOfVehicle
         || (this->m_interruptedTime = delta_sec + this->m_interruptedTime,
             UFG::Conversation::ConversantsInSameVehicle(this)) )
  {
    result = 1;
    this->m_newState = eConversationState_Playing;
    this->m_interruptedTime = 0.0;
    return result;
  }
  return 1;
}

// File Line: 371
// RVA: 0x5A49E0
char __fastcall UFG::Conversation::OnResume(UFG::Conversation *this)
{
  UFG::ConversationElement *ResumeElement; // rax
  bool v3; // zf

  ResumeElement = UFG::Conversation::GetResumeElement(this);
  this->m_activeElement = ResumeElement;
  if ( ResumeElement )
    ResumeElement->vfptr->Reset(ResumeElement);
  v3 = this->m_interruptType == eInterruptType_GetOutOfVehicle;
  this->m_state = eConversationState_Resume;
  if ( !v3 || UFG::Conversation::ConversantsInSameVehicle(this) )
    this->m_interruptType = eInterruptType_None;
  return 1;
}

// File Line: 432
// RVA: 0x5A43E0
char __fastcall UFG::Conversation::OnInterrupt(UFG::Conversation *this)
{
  UFG::SimObject *v2; // rsi
  UFG::ConversationElement *m_activeElement; // rbp
  __int64 v4; // r8
  unsigned int mStringHash32; // ebx
  UFG::AmbientConversation *v6; // rax
  UFG::AmbientConversation *v7; // rbx
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *m_pSimObject; // r8
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rax
  char result; // al
  UFG::qString v13; // [rsp+28h] [rbp-30h] BYREF

  v2 = 0i64;
  m_activeElement = 0i64;
  if ( this->m_curLine < this->m_numElements )
    m_activeElement = this->m_activeElement;
  v4 = UFG::ConversationManager::sm_idCounter++;
  UFG::qString::qString(&v13, "AmbientConversation_%u", v4);
  mStringHash32 = v13.mStringHash32;
  if ( v13.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(v13.mData, 0xFFFFFFFF);
    v13.mStringHash32 = mStringHash32;
  }
  UFG::qString::~qString(&v13);
  switch ( this->m_interruptType )
  {
    case eInterruptType_Collision:
      v6 = UFG::ConversationManager::AddAmbientConversation(mStringHash32);
      v6->m_topic = eConversationTopic_PassengerReaction;
      break;
    case eInterruptType_GetOutOfVehicle:
      v6 = UFG::ConversationManager::AddAmbientConversation(mStringHash32);
      v6->m_topic = eConversationTopic_PlayerGetOutOfCar;
      break;
    case eInterruptType_HitReaction:
      v6 = UFG::ConversationManager::AddAmbientConversation(mStringHash32);
      v6->m_topic = eConversationTopic_HitReaction;
      break;
    default:
      goto LABEL_23;
  }
  v7 = v6;
  if ( (*((_BYTE *)this + 169) & 1) != 0 )
  {
    m_pPointer = m_activeElement->m_tgtAac.m_pPointer;
    if ( m_pPointer )
      m_pSimObject = m_pPointer->m_pSimObject;
    else
      m_pSimObject = 0i64;
    v10 = m_activeElement->m_spkAac.m_pPointer;
  }
  else
  {
    v11 = m_activeElement->m_spkAac.m_pPointer;
    if ( v11 )
      m_pSimObject = v11->m_pSimObject;
    else
      m_pSimObject = 0i64;
    v10 = m_activeElement->m_tgtAac.m_pPointer;
  }
  if ( v10 )
    v2 = v10->m_pSimObject;
  UFG::AmbientConversation::SetupLines(v7, v2, m_pSimObject);
  v7->m_linePriority = 9;
  *((_BYTE *)&v7->UFG::Conversation + 169) &= ~2u;
  *((_BYTE *)&v7->UFG::Conversation + 168) &= ~2u;
  *((_BYTE *)&v7->UFG::Conversation + 168) |= 0x80u;
  this->m_onInterrupt = v7;
  UFG::Conversation::Start(v7);
LABEL_23:
  result = 1;
  this->m_state = eConversationState_Interrupted;
  return result;
}

// File Line: 508
// RVA: 0x5AC6A0
char __fastcall UFG::Conversation::Start(UFG::Conversation *this)
{
  bool v1; // zf
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mNext; // rdx
  UFG::Conversation::eConversationType *p_m_type; // r9
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **p_mNext; // rdx
  __int64 v5; // rax
  char *v6; // rax

  v1 = this->m_activeElement == 0i64;
  this->m_newState = eConversationState_Playing;
  if ( v1 )
    this->m_activeElement = (UFG::ConversationElement *)&this->m_lines.mNode.mNext[-1].mNext;
  mNext = this->m_lines.mNode.mNext;
  p_m_type = &this->m_type;
  while ( 1 )
  {
    p_mNext = &mNext[-1].mNext;
    if ( p_mNext == (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)p_m_type )
      break;
    if ( p_mNext )
    {
      v5 = (__int64)&p_mNext[18][-1].mNext;
      if ( (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)v5 != p_mNext + 16 )
      {
        while ( !v5 || *(_DWORD *)(v5 + 24) != 2 )
        {
          v5 = *(_QWORD *)(v5 + 16) - 8i64;
          if ( (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)v5 == p_mNext + 16 )
            goto LABEL_10;
        }
        *((_BYTE *)this + 168) |= 0x40u;
        break;
      }
    }
LABEL_10:
    mNext = p_mNext[2];
  }
  if ( *p_m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Playing %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v6);
  }
  return 1;
}

// File Line: 533
// RVA: 0x5AA6D0
char __fastcall UFG::Conversation::Restart(UFG::Conversation *this)
{
  UFG::Conversation::eConversationType *p_m_type; // rsi
  UFG::Conversation *p_mNext; // rbx

  p_m_type = &this->m_type;
  p_mNext = (UFG::Conversation *)&this->m_lines.mNode.mNext[-1].mNext;
  this->m_curLine = 0;
  this->m_activeElement = 0i64;
  if ( p_mNext != (UFG::Conversation *)&this->m_type )
  {
    do
    {
      ((void (__fastcall *)(UFG::Conversation *))p_mNext->vfptr->PrintDebugInfo)(p_mNext);
      p_mNext = (UFG::Conversation *)&p_mNext->mNode.mChild[0][-1].mUID;
    }
    while ( p_mNext != (UFG::Conversation *)p_m_type );
  }
  UFG::Conversation::Start(this);
  return 1;
}

// File Line: 550
// RVA: 0x5AA550
char __fastcall UFG::Conversation::Reset(UFG::Conversation *this)
{
  UFG::Conversation::eConversationType *p_m_type; // rdi
  UFG::Conversation *p_mNext; // rbx

  p_m_type = &this->m_type;
  p_mNext = (UFG::Conversation *)&this->m_lines.mNode.mNext[-1].mNext;
  this->m_curLine = 0;
  this->m_activeElement = 0i64;
  if ( p_mNext != (UFG::Conversation *)&this->m_type )
  {
    do
    {
      ((void (__fastcall *)(UFG::Conversation *))p_mNext->vfptr->PrintDebugInfo)(p_mNext);
      p_mNext = (UFG::Conversation *)&p_mNext->mNode.mChild[0][-1].mUID;
    }
    while ( p_mNext != (UFG::Conversation *)p_m_type );
  }
  return 1;
}

// File Line: 567
// RVA: 0x5AC800
char __fastcall UFG::Conversation::Stop(UFG::Conversation *this, bool stoppedAfterLine)
{
  char *v2; // rax

  if ( this->m_state )
  {
    *((_BYTE *)this + 168) &= ~0x10u;
    this->m_newState = eConversationState_Stopped;
    *((_BYTE *)this + 168) |= 16 * stoppedAfterLine;
    if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
    {
      v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
      UFG::qPrintf(
        "CONV DEBUG: %s : %6u : Stopping %s\n",
        UFG::TidoGame::sm_timeStampStr.mData,
        UFG::Metrics::msInstance.mSimFrameCount,
        v2);
    }
  }
  return 1;
}

// File Line: 605
// RVA: 0x5AC8E0
bool __fastcall UFG::Conversation::StopAfterCurrentLine(UFG::Conversation *this)
{
  UFG::ConversationElement *m_activeElement; // rax

  m_activeElement = this->m_activeElement;
  if ( m_activeElement )
  {
    *((_BYTE *)m_activeElement + 156) |= 1u;
    LOBYTE(m_activeElement) = 1;
  }
  return (char)m_activeElement;
}

// File Line: 620
// RVA: 0x5A35C0
char __fastcall UFG::Conversation::NextLine(UFG::Conversation *this)
{
  if ( this->m_state != eConversationState_Playing )
    this->m_activeElement = (UFG::ConversationElement *)UFG::Conversation::GetNextElement(this);
  return 1;
}

// File Line: 633
// RVA: 0x5A8190
char __fastcall UFG::Conversation::PrevLine(UFG::Conversation *this)
{
  UFG::ConversationElement *m_activeElement; // rdx
  UFG::Conversation *p_mNext; // rdx

  if ( this->m_state != eConversationState_Playing )
  {
    m_activeElement = this->m_activeElement;
    if ( !m_activeElement )
    {
      this->m_activeElement = 0i64;
      return 1;
    }
    p_mNext = (UFG::Conversation *)&m_activeElement->mPrev[-1].mNext;
    if ( p_mNext == (UFG::Conversation *)&this->m_type )
      p_mNext = (UFG::Conversation *)&p_mNext->mNode.mParent[-1].mUID;
    if ( p_mNext == (UFG::Conversation *)&this->m_lines.mNode.mPrev[-1].mNext )
      p_mNext = (UFG::Conversation *)&this->m_lines.mNode.mNext[-1].mNext;
    this->m_activeElement = (UFG::ConversationElement *)p_mNext;
  }
  return 1;
}

// File Line: 646
// RVA: 0x5A3510
bool __fastcall UFG::Conversation::MoveToNextGroup(UFG::Conversation *this)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **NextElement; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mNext; // rbx
  UFG::Conversation::eConversationType *p_m_type; // rdi
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **i; // rbx

  if ( this->m_state != eConversationState_Playing )
  {
    if ( (unsigned int)UFG::Conversation::GetGroupCount(this) <= 1 )
    {
      mNext = this->m_lines.mNode.mNext;
      this->m_curLine = 0;
      this->m_activeElement = 0i64;
      p_m_type = &this->m_type;
      for ( i = &mNext[-1].mNext;
            i != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)p_m_type;
            i = &i[2][-1].mNext )
      {
        ((void (__fastcall *)(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **))(*i)->mNext)(i);
      }
    }
    else
    {
      while ( 1 )
      {
        NextElement = UFG::Conversation::GetNextElement(this);
        this->m_activeElement = (UFG::ConversationElement *)NextElement;
        if ( !NextElement )
          break;
        if ( (*((_BYTE *)NextElement + 156) & 1) != 0 )
        {
          this->m_activeElement = (UFG::ConversationElement *)UFG::Conversation::GetNextElement(this);
          break;
        }
      }
      if ( !this->m_activeElement )
        return UFG::Conversation::Reset(this);
    }
  }
  return 1;
}

// File Line: 684
// RVA: 0x5A0620
bool __fastcall UFG::Conversation::IsLastLineInGroup(UFG::Conversation *this)
{
  UFG::ConversationElement *m_activeElement; // rax
  bool result; // al

  result = 1;
  if ( this->m_curLine != this->m_numElements - 1 )
  {
    m_activeElement = this->m_activeElement;
    if ( !m_activeElement || (*((_BYTE *)m_activeElement + 156) & 1) == 0 )
      return 0;
  }
  return result;
}

// File Line: 691
// RVA: 0x59A6E0
bool __fastcall UFG::Conversation::CurrentGroupIsLast(UFG::Conversation *this)
{
  UFG::ConversationElement *m_activeElement; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mNext; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v4; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **p_mNext; // rax

  m_activeElement = this->m_activeElement;
  if ( !m_activeElement )
    return UFG::Conversation::GetGroupCount(this) < 2;
  mNext = m_activeElement->mNext;
  if ( !mNext )
    return 1;
  v4 = mNext->mNext;
  p_mNext = &mNext[-1].mNext;
  if ( !v4 )
    return 1;
  while ( (*((_BYTE *)p_mNext + 156) & 1) == 0 )
  {
    p_mNext = &v4[-1].mNext;
    v4 = v4->mNext;
    if ( !v4 )
      return 1;
  }
  return 0;
}

// File Line: 728
// RVA: 0x59AC30
void __fastcall UFG::Conversation::Destroy(UFG::Conversation *this)
{
  UFG::Conversation *m_onResume; // rcx
  UFG::Conversation *m_onInterrupt; // rcx
  UFG::Conversation::eConversationType *p_m_type; // rsi
  UFG::ConversationElement *p_mNext; // rbx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *i; // rdx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mPrev; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mNext; // rax
  char *v9; // rax

  m_onResume = this->m_onResume;
  if ( m_onResume )
    UFG::Conversation::Destroy(m_onResume);
  m_onInterrupt = this->m_onInterrupt;
  if ( m_onInterrupt )
    UFG::Conversation::Destroy(m_onInterrupt);
  p_m_type = &this->m_type;
  p_mNext = (UFG::ConversationElement *)&this->m_lines.mNode.mNext[-1].mNext;
  if ( p_mNext != (UFG::ConversationElement *)&this->m_type )
  {
    do
    {
      UFG::ConversationElement::ClearSpeechFlags(p_mNext);
      p_mNext = (UFG::ConversationElement *)&p_mNext->mNext[-1].mNext;
    }
    while ( p_mNext != (UFG::ConversationElement *)p_m_type );
  }
  for ( i = this->m_lines.mNode.mNext;
        &i[-1].mNext != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)&this->m_type;
        i = this->m_lines.mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **, __int64))i[-1].mNext->mPrev)(
        &i[-1].mNext,
        1i64);
  }
  this->m_activeElement = 0i64;
  this->m_numElements = 0;
  *(_QWORD *)&this->m_state = 0i64;
  if ( *p_m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Forcing Finish %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v9);
  }
}

// File Line: 783
// RVA: 0x59D4C0
UFG::ConversationElement *__fastcall UFG::Conversation::GetResumeElement(UFG::Conversation *this)
{
  __int64 v1; // rsi
  UFG::ConversationElement *m_activeElement; // rbx
  int m_curLine; // ecx
  bool v5; // al

  v1 = 0i64;
  m_activeElement = 0i64;
  if ( this->m_curLine < this->m_numElements )
    m_activeElement = this->m_activeElement;
  UFG::Conversation::OnLineFinished(this);
  m_curLine = this->m_curLine;
  v5 = (*((_BYTE *)m_activeElement + 156) & 0x10) != 0;
  if ( (*((_BYTE *)m_activeElement + 156) & 0x10) != 0 )
    goto LABEL_8;
  while ( m_curLine > 0 )
  {
    m_activeElement = (UFG::ConversationElement *)&m_activeElement->mPrev[-1].mNext;
    if ( m_activeElement == (UFG::ConversationElement *)&this->m_type )
      m_activeElement = (UFG::ConversationElement *)&m_activeElement->mPrev[-1].mNext;
    --m_curLine;
    v5 = (*((_BYTE *)m_activeElement + 156) & 0x10) != 0;
    if ( (*((_BYTE *)m_activeElement + 156) & 0x10) != 0 )
      goto LABEL_8;
  }
  if ( v5 )
  {
LABEL_8:
    this->m_curLine = m_curLine;
    return m_activeElement;
  }
  else
  {
    if ( this->m_curLine < this->m_numElements )
      return this->m_activeElement;
    return (UFG::ConversationElement *)v1;
  }
}

// File Line: 820
// RVA: 0x59D0A0
UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **__fastcall UFG::Conversation::GetNextElement(
        UFG::Conversation *this)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **result; // rax
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *mNext; // rax
  UFG::qList<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement>,1,0> *p_m_prevPlayed; // rcx
  int i; // edx
  int v6; // ecx
  UFG::Conversation::eConversationType *p_m_type; // rbx

  result = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)this->m_activeElement;
  if ( result )
  {
    if ( (*((_BYTE *)this + 168) & 0x20) != 0 )
    {
      mNext = this->m_prevPlayed.mNode.mNext;
      p_m_prevPlayed = &this->m_prevPlayed;
      for ( i = 0;
            mNext != (UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *)p_m_prevPlayed;
            ++i )
      {
        mNext = mNext->mNext;
      }
      v6 = UFG::qRandom((unsigned int)this->m_numElements - i, (unsigned int *)&UFG::qDefaultSeed);
      result = &this->m_lines.mNode.mNext[-1].mNext;
      if ( v6 >= 0 )
      {
        p_m_type = &this->m_type;
        do
        {
          result = &result[2][-1].mNext;
          if ( result == (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)p_m_type )
            result = &result[2][-1].mNext;
          if ( (*((_BYTE *)result + 156) & 4) == 0 )
            --v6;
        }
        while ( v6 >= 0 );
      }
    }
    else
    {
      ++this->m_curLine;
      result = &result[2][-1].mNext;
      if ( result == (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)&this->m_type )
        return &result[2][-1].mNext;
    }
  }
  return result;
}

// File Line: 888
// RVA: 0x59CE30
UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **__fastcall UFG::Conversation::GetElement(
        UFG::Conversation *this,
        int idx)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **result; // rax
  UFG::Conversation::eConversationType *p_m_type; // rcx

  result = &this->m_lines.mNode.mNext[-1].mNext;
  if ( idx > 0 )
  {
    p_m_type = &this->m_type;
    do
    {
      if ( result == (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)p_m_type )
        break;
      --idx;
      result = &result[2][-1].mNext;
    }
    while ( idx > 0 );
  }
  return result;
}

// File Line: 914
// RVA: 0x5A4550
bool __fastcall UFG::Conversation::OnLineFinished(UFG::Conversation *this)
{
  UFG::ConversationElement *m_activeElement; // rsi
  char *mData; // rdi
  char *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v6; // rdx
  UFG::ConversationElement *v7; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *mPrev; // rax
  int v9; // ecx
  UFG::Conversation *i; // rax
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *mNext; // r8
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v12; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v13; // rax
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v14; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v15; // rax
  char v16; // di
  bool result; // al
  UFG::qString v18; // [rsp+38h] [rbp-30h] BYREF

  if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    if ( this->m_curLine < this->m_numElements )
      m_activeElement = this->m_activeElement;
    else
      m_activeElement = 0i64;
    UFG::qString::qString(&v18, &this->m_activeElement->m_context);
    mData = v18.mData;
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_activeElement[1].vfptr[1].PlayLine);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : %s : line finished %u, %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v4,
      this->m_curLine,
      mData);
    UFG::qString::~qString(&v18);
  }
  if ( this->m_type == eConversationType_Scripted )
    UFG::ScriptedConversationElement::ClearConversationTargets((UFG::ScriptedConversationElement *)this->m_activeElement);
  *((_BYTE *)this + 168) &= ~1u;
  v5 = UFG::qMalloc(0x18ui64, "Conversation.ConversationElementPointerNode", 0i64);
  v6 = (UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *)v5;
  if ( v5 )
  {
    v7 = this->m_activeElement;
    v5->mNext = v5;
    v5[1].mNext = v5;
    v5[2].mNext = (UFG::allocator::free_link *)v7;
  }
  else
  {
    v6 = 0i64;
  }
  mPrev = this->m_prevPlayed.mNode.mPrev;
  mPrev->mNext = v6;
  v6->mPrev = mPrev;
  v6->mNext = &this->m_prevPlayed.mNode;
  this->m_prevPlayed.mNode.mPrev = v6;
  *((_BYTE *)this->m_activeElement + 156) |= 4u;
  v9 = 0;
  for ( i = (UFG::Conversation *)this->m_prevPlayed.mNode.mNext;
        i != (UFG::Conversation *)&this->m_prevPlayed;
        i = (UFG::Conversation *)i->mNode.mParent )
  {
    ++v9;
  }
  if ( v9 > this->m_avoidRepeatingLastNLines )
  {
    mNext = this->m_prevPlayed.mNode.mNext;
    v12 = mNext->mPrev;
    v13 = mNext->mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    BYTE4(mNext[1].mPrev[9].mNext) &= ~4u;
    v14 = mNext->mPrev;
    v15 = mNext->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    operator delete[](mNext);
  }
  this->m_activeElement->vfptr->Reset(this->m_activeElement);
  if ( this->m_state != eConversationState_Stopped )
  {
    v16 = *((_BYTE *)this->m_activeElement + 156);
    this->m_activeElement = (UFG::ConversationElement *)UFG::Conversation::GetNextElement(this);
    if ( (v16 & 1) != 0 )
      UFG::Conversation::Stop(this, 1);
  }
  result = 1;
  if ( this->m_curLine == this->m_numElements )
  {
    this->m_activeElement = 0i64;
    if ( this->m_newState != eConversationState_Stopped )
      this->m_newState = eConversationState_Finished;
  }
  return result;
}

// File Line: 982
// RVA: 0x59CA10
char __fastcall UFG::Conversation::ForceFinish(UFG::Conversation *this, _BOOL8 a2)
{
  char *v3; // rax

  if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Forcing Finish %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v3);
  }
  this->m_newState = eConversationState_Finished;
  UFG::Conversation::OnFinish(this, a2);
  return 1;
}

// File Line: 1012
// RVA: 0x5A0660
char __fastcall UFG::Conversation::IsSpeaker(UFG::Conversation *this, UFG::SimObject *speaker)
{
  UFG::Conversation::eConversationType *p_m_type; // r8
  UFG::Conversation *p_mNext; // rax
  UFG::qNode<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol> > *mPrev; // rcx
  UFG::SimObject *v6; // rdx

  p_m_type = &this->m_type;
  p_mNext = (UFG::Conversation *)&this->m_lines.mNode.mNext[-1].mNext;
  if ( p_mNext == (UFG::Conversation *)&this->m_type )
    return 0;
  while ( 1 )
  {
    mPrev = p_mNext->m_animationBanks.mNode.mPrev;
    v6 = mPrev ? (UFG::SimObject *)mPrev[2].mNext : 0i64;
    if ( v6 == speaker )
      break;
    p_mNext = (UFG::Conversation *)&p_mNext->mNode.mChild[0][-1].mUID;
    if ( p_mNext == (UFG::Conversation *)p_m_type )
      return 0;
  }
  return 1;
}

// File Line: 1041
// RVA: 0x5AEFD0
char __fastcall UFG::Conversation::Update(UFG::Conversation *this, float delta_sec)
{
  _BOOL8 v2; // rdx
  char *v4; // rax
  float v5; // xmm0_4

  if ( this->m_type == eConversationType_Scripted
    && this->m_newState != this->m_state
    && UFG::ConversationManager::sm_debugScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Updating state %s :: %s -> %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v4,
      UFG::ConversationStateNames[this->m_state],
      UFG::ConversationStateNames[this->m_newState]);
  }
  v5 = delta_sec + this->m_timeAlive;
  this->m_timeAlive = v5;
  if ( v5 >= 120.0 && this->m_type == eConversationType_Ambient )
    UFG::Conversation::ForceFinish(this, v2);
  if ( this->m_newState == eConversationState_Playing )
  {
    UFG::Conversation::UpdatePlayState(this, delta_sec);
    return 1;
  }
  if ( this->m_newState == eConversationState_Interrupted )
  {
    if ( this->m_state != eConversationState_Interrupted )
      UFG::Conversation::OnInterrupt(this);
    UFG::Conversation::UpdateInterruptState(this, delta_sec);
    return 1;
  }
  else
  {
    if ( this->m_newState != eConversationState_Resume )
    {
      if ( this->m_newState == eConversationState_Stopped )
      {
        if ( this->m_state != eConversationState_Stopped )
        {
          UFG::Conversation::OnStop(this, v2);
          return 1;
        }
      }
      else if ( this->m_newState == eConversationState_Finished && this->m_state != eConversationState_Finished )
      {
        UFG::Conversation::OnFinish(this, v2);
        return 1;
      }
      return 1;
    }
    if ( this->m_state != eConversationState_Resume )
      UFG::Conversation::OnResume(this);
    UFG::Conversation::UpdateResumeState(this, delta_sec);
    return 1;
  }
}

// File Line: 1134
// RVA: 0x5A3160
signed __int64 __fastcall UFG::Conversation::LookupTopic(UFG::qSymbol *sym)
{
  unsigned int v1; // edx
  UFG::qStaticSymbol *v2; // rax

  v1 = 0;
  v2 = UFG::ConversationTopicEnumSymbols;
  while ( sym->mUID != v2->mUID )
  {
    ++v2;
    ++v1;
    if ( (__int64)v2 >= (__int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_MEATWRAPPED )
      return 25i64;
  }
  return v1;
}

// File Line: 1260
// RVA: 0x5A0400
bool __fastcall UFG::Conversation::IsFurtherThanMaxSeparationDistance(
        UFG::Conversation *this,
        UFG::ConversationElement *element)
{
  UFG::ActorAudioComponent *m_pPointer; // rcx
  UFG::ActorAudioComponent *v4; // rdx
  float m_maxSeparationDistance; // xmm6_4

  if ( !element )
    return 0;
  m_pPointer = (UFG::ActorAudioComponent *)element->m_spkAac.m_pPointer;
  v4 = (UFG::ActorAudioComponent *)element->m_tgtAac.m_pPointer;
  if ( !m_pPointer || !v4 )
    return 0;
  m_maxSeparationDistance = this->m_maxSeparationDistance;
  return UFG::ActorAudioComponent::Distance2ToActor(m_pPointer, v4) >= (float)(m_maxSeparationDistance
                                                                             * m_maxSeparationDistance)
      && (*((_BYTE *)this + 168) & 8) == 0;
}

// File Line: 1297
// RVA: 0x59CEF0
__int64 __fastcall UFG::Conversation::GetGroupCount(UFG::Conversation *this)
{
  unsigned int v1; // edx
  unsigned int v3; // r10d
  unsigned int v4; // r9d
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mNext; // rbx
  int v6; // eax
  __int64 i; // rcx

  v1 = 0;
  v3 = this->m_numElements - 1;
  if ( this->m_numElements == 1 )
    return 0i64;
  v4 = 1;
  if ( this->m_numElements == 1 )
    return 1i64;
  mNext = this->m_lines.mNode.mNext;
  do
  {
    v6 = v1;
    for ( i = (__int64)&mNext[-1].mNext; v6 > 0; i = *(_QWORD *)(i + 16) - 8i64 )
    {
      if ( (UFG::Conversation::eConversationType *)i == &this->m_type )
        break;
      --v6;
    }
    if ( (*(_BYTE *)(i + 156) & 1) != 0 )
      ++v4;
    ++v1;
  }
  while ( v1 < v3 );
  return v4;
}

// File Line: 1332
// RVA: 0x5A4A30
char __fastcall UFG::Conversation::OnStop(UFG::Conversation *this, _BOOL8 a2)
{
  UFG::Conversation::eConversationType *p_m_type; // rsi
  char *v4; // rax
  char v5; // cl
  UFG::ConversationElement *m_activeElement; // rbx
  _BOOL8 v8; // rdx

  p_m_type = &this->m_type;
  if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Processing stop %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v4);
  }
  v5 = *((_BYTE *)this + 168);
  this->m_state = eConversationState_Stopped;
  if ( (v5 & 0x10) == 0 || (v5 & 0x20) != 0 )
  {
    if ( this->m_curLine < this->m_numElements )
      m_activeElement = this->m_activeElement;
    else
      m_activeElement = 0i64;
  }
  else
  {
    m_activeElement = this->m_activeElement;
    if ( m_activeElement )
    {
      m_activeElement = (UFG::ConversationElement *)&m_activeElement->mPrev[-1].mNext;
      if ( m_activeElement == (UFG::ConversationElement *)p_m_type )
        m_activeElement = (UFG::ConversationElement *)&m_activeElement->mPrev[-1].mNext;
      if ( m_activeElement == (UFG::ConversationElement *)&this->m_lines.mNode.mPrev[-1].mNext )
        m_activeElement = (UFG::ConversationElement *)&this->m_lines.mNode.mNext[-1].mNext;
    }
  }
  *((_BYTE *)this + 168) = v5 & 0xEF;
  if ( !m_activeElement || !m_activeElement->vfptr->SpeakerInitialized(m_activeElement) )
    return UFG::Conversation::ForceFinish(this, a2);
  m_activeElement->vfptr->Reset(m_activeElement);
  LOBYTE(v8) = 1;
  m_activeElement->vfptr->StopLine(m_activeElement, v8);
  UFG::ConversationElement::ClearSpeechFlags(m_activeElement);
  return 1;
}

// File Line: 1382
// RVA: 0x5A4280
char __fastcall UFG::Conversation::OnFinish(UFG::Conversation *this, _BOOL8 a2)
{
  UFG::Conversation::eConversationType *p_m_type; // rsi
  char *v4; // rax
  UFG::Conversation *m_onResume; // rcx
  UFG::Conversation *m_onInterrupt; // rcx
  unsigned __int16 m_numElements; // ax
  UFG::ConversationElement *m_activeElement; // rcx
  UFG::ConversationElement *i; // rbx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **p_mNext; // rbx

  p_m_type = &this->m_type;
  if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Finish state processed %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v4);
  }
  m_onResume = this->m_onResume;
  if ( m_onResume )
    UFG::Conversation::ForceFinish(m_onResume, a2);
  m_onInterrupt = this->m_onInterrupt;
  if ( m_onInterrupt )
    UFG::Conversation::ForceFinish(m_onInterrupt, a2);
  m_numElements = this->m_numElements;
  this->m_state = eConversationState_Finished;
  if ( this->m_curLine < m_numElements )
  {
    m_activeElement = this->m_activeElement;
    if ( m_activeElement )
    {
      LOBYTE(a2) = 1;
      m_activeElement->vfptr->StopLine(m_activeElement, a2);
    }
  }
  for ( i = (UFG::ConversationElement *)&this->m_lines.mNode.mNext[-1].mNext;
        i != (UFG::ConversationElement *)p_m_type;
        i = (UFG::ConversationElement *)&i->mNext[-1].mNext )
  {
    UFG::ConversationElement::ClearSpeechFlags(i);
  }
  p_mNext = &this->m_lines.mNode.mNext[-1].mNext;
  this->m_curLine = 0;
  for ( this->m_activeElement = 0i64;
        p_mNext != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)p_m_type;
        p_mNext = &p_mNext[2][-1].mNext )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **))(*p_mNext)->mNext)(p_mNext);
  }
  return 1;
}

// File Line: 1422
// RVA: 0x5AA9D0
void __fastcall UFG::Conversation::SetContainsActionRequests(UFG::Conversation *this)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *i; // rdx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **p_mNext; // rdx
  __int64 v3; // rax

  for ( i = this->m_lines.mNode.mNext; ; i = p_mNext[2] )
  {
    p_mNext = &i[-1].mNext;
    if ( p_mNext == (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)&this->m_type )
      break;
    if ( p_mNext )
    {
      v3 = (__int64)&p_mNext[18][-1].mNext;
      if ( (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)v3 != p_mNext + 16 )
      {
        while ( !v3 || *(_DWORD *)(v3 + 24) != 2 )
        {
          v3 = *(_QWORD *)(v3 + 16) - 8i64;
          if ( (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)v3 == p_mNext + 16 )
            goto LABEL_8;
        }
        *((_BYTE *)this + 168) |= 0x40u;
        return;
      }
    }
LABEL_8:
    ;
  }
}

// File Line: 1452
// RVA: 0x5A02B0
char __fastcall UFG::Conversation::InterruptIsInvalid(UFG::Conversation *this, UFG::eInterruptType intType)
{
  bool v3; // r10
  bool v4; // r11
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mNext; // r8
  UFG::Conversation::eConversationType *p_m_type; // rcx
  __int64 p_mNext; // r8
  char v8; // cl

  v3 = this->m_numInterrupts >= UFG::ConversationManager::sm_maxNumInterrupts;
  v4 = this->m_state != eConversationState_Playing;
  if ( intType != eInterruptType_GetOutOfVehicle
    || (mNext = this->m_lines.mNode.mNext,
        p_m_type = &this->m_type,
        p_mNext = (__int64)&mNext[-1].mNext,
        (UFG::Conversation::eConversationType *)p_mNext == p_m_type) )
  {
LABEL_5:
    v8 = 0;
    if ( intType != eInterruptType_GetOutOfVehicle )
      return (*((_BYTE *)this + 169) & 4) != 0 || v4 || v3;
  }
  else
  {
    while ( *(_DWORD *)(p_mNext + 24) != qwsPlayCellPhone.mUID )
    {
      p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
      if ( (UFG::Conversation::eConversationType *)p_mNext == p_m_type )
        goto LABEL_5;
    }
    v8 = 1;
  }
  if ( (*((_BYTE *)this + 169) & 8) != 0 && !v8 )
    return 0;
  if ( (*((_BYTE *)this + 169) & 8) == 0 || v8 )
    return 1;
  return (*((_BYTE *)this + 169) & 4) != 0 || v4 || v3;
}

// File Line: 1479
// RVA: 0x5A0070
char __fastcall UFG::Conversation::Interrupt(UFG::Conversation *this, UFG::eInterruptType intType, bool force)
{
  UFG::ConversationElement *m_activeElement; // rdi
  UFG::SimComponent *m_pPointer; // rax
  UFG::ConversationElement *v9; // rcx

  if ( UFG::Conversation::InterruptIsInvalid(this, intType) )
    return 0;
  if ( this->m_curLine >= this->m_numElements )
    return 0;
  m_activeElement = this->m_activeElement;
  if ( !m_activeElement )
    return 0;
  m_pPointer = m_activeElement->m_spkAac.m_pPointer;
  if ( !m_pPointer )
    return 0;
  v9 = this->m_activeElement;
  *((_BYTE *)this + 169) ^= (*((_BYTE *)this + 169) ^ (BYTE1(m_pPointer[8].m_pSimObject) >> 3)) & 1;
  m_activeElement->vfptr->StopLine(v9, force);
  m_activeElement->vfptr->Reset(m_activeElement);
  ++this->m_numInterrupts;
  this->m_newState = eConversationState_Interrupted;
  this->m_interruptType = intType;
  this->m_interruptedTime = 0.0;
  return 1;
}

// File Line: 1516
// RVA: 0x5B0BD0
char __fastcall UFG::Conversation::UpdatePlayState(UFG::Conversation *this, float delta_sec)
{
  _BOOL8 v2; // rdx
  UFG::ConversationElement *m_activeElement; // rsi
  UFG::SimComponent *m_pPointer; // rax
  SSInstance *mNext; // rcx
  UFG::qBaseNodeRB *SimObjectFromSymbol; // rax
  UFG::SimComponent *v8; // rax
  SSInstance *v9; // rcx
  UFG::qBaseNodeRB *v10; // rax
  hkgpIndexedMeshDefinitions::Edge *v11; // rdx
  UFG::SimComponent *v13; // rax
  hkgpIndexedMesh::EdgeBarrier *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  hkgpIndexedMesh::EdgeBarrierVtbl *vfptr; // rax
  float v17; // xmm6_4
  UFG::SimComponent *v18; // rax
  UFG::SimComponent *v19; // rax
  float v20; // xmm6_4
  UFG::ConversationElement *v21; // rdx
  UFG::ConversationElement *v22; // rdi
  char *mData; // rbx
  char *v24; // rax
  _BOOL8 v25; // rdx
  int m_curLine; // [rsp+20h] [rbp-68h]
  UFG::qString v27; // [rsp+38h] [rbp-50h] BYREF

  this->m_state = eConversationState_Playing;
  if ( this->m_type == eConversationType_Ambient
    && (*((_BYTE *)this + 169) & 2) != 0
    && UFG::AudioListener::sm_pInstance
    && UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled
    && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
  {
    return UFG::Conversation::ForceFinish(this, v2);
  }
  if ( this->m_curLine >= this->m_numElements )
    return UFG::Conversation::ForceFinish(this, v2);
  m_activeElement = this->m_activeElement;
  if ( !m_activeElement )
    return UFG::Conversation::ForceFinish(this, v2);
  m_pPointer = m_activeElement->m_spkAac.m_pPointer;
  if ( (!m_pPointer || !m_pPointer->m_pSimObject) && m_activeElement->m_type == eConversationElementType_Scripted )
  {
    mNext = (SSInstance *)m_activeElement[1].mNext;
    if ( mNext )
    {
      SimObjectFromSymbol = UFG::TSScriptedDialogueElement::GetSimObjectFromSymbol(mNext);
      if ( SimObjectFromSymbol )
      {
        UFG::ConversationElement::SetSpeaker(m_activeElement, (UFG::SimObjectCharacter *)SimObjectFromSymbol);
        m_activeElement[1].mNext = 0i64;
      }
    }
  }
  v8 = m_activeElement->m_tgtAac.m_pPointer;
  if ( (!v8 || !v8->m_pSimObject) && m_activeElement->m_type == eConversationElementType_Scripted )
  {
    v9 = *(SSInstance **)&m_activeElement[1].m_playbackEvent.mUID;
    if ( v9 )
    {
      v10 = UFG::TSScriptedDialogueElement::GetSimObjectFromSymbol(v9);
      if ( v10 )
      {
        UFG::ConversationElement::SetTarget(m_activeElement, (UFG::SimObjectCharacter *)v10);
        *(_QWORD *)&m_activeElement[1].m_playbackEvent.mUID = 0i64;
      }
    }
  }
  if ( UFG::Conversation::IsFurtherThanMaxSeparationDistance(this, m_activeElement)
    && this->m_type == eConversationType_Scripted )
  {
    UFG::Conversation::Interrupt(this, eInterruptType_Separation, 0);
    return 1;
  }
  v13 = m_activeElement->m_spkAac.m_pPointer;
  v14 = (hkgpIndexedMesh::EdgeBarrier *)m_activeElement->m_tgtAac.m_pPointer;
  if ( v13 )
  {
    mPrev = v13[7].m_BoundComponentHandles.mNode.mPrev;
    if ( (!mPrev || !BYTE4(mPrev[7].mPrev))
      && (!v14 || (vfptr = v14[62].vfptr) == 0i64 || !BYTE4(vfptr[7].__vecDelDtor)) )
    {
      if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v14, v11) )
      {
        v17 = delta_sec + m_activeElement->m_timeAlive;
        m_activeElement->m_timeAlive = v17;
        if ( v17 > 2.5 )
LABEL_63:
          UFG::Conversation::OnLineFinished(this);
      }
      else
      {
        v18 = m_activeElement->m_spkAac.m_pPointer;
        if ( v18 )
          BYTE1(v18[8].m_pSimObject) &= ~0x10u;
        if ( !m_activeElement->vfptr->SpeakerInitialized(m_activeElement) )
        {
          v19 = m_activeElement->m_spkAac.m_pPointer;
          if ( v19 )
            BYTE1(v19[8].m_pSimObject) &= ~0x10u;
          v20 = delta_sec + m_activeElement->m_timeAlive;
          m_activeElement->m_timeAlive = v20;
          if ( v20 <= 3.0 )
            return 1;
          goto LABEL_63;
        }
        if ( !m_activeElement->vfptr->LineIsPlaying(m_activeElement) && m_activeElement->m_sampleLength < 0.02 )
        {
          UFG::ConversationElement::SetTagInterruptFlags(m_activeElement, (*((_BYTE *)this + 168) & 4) != 0);
          UFG::ConversationElement::SetSpkListFlags(m_activeElement, (*((_BYTE *)this + 168) & 0x40) != 0);
          if ( this->m_type == eConversationType_Ambient )
            UFG::ConversationElement::SetActiveAmbConv(m_activeElement, this);
          if ( this->m_type == eConversationType_Scripted )
            UFG::ConversationElement::SetDebugFlags(m_activeElement, UFG::ConversationManager::sm_debugScrConversations);
          if ( m_activeElement->m_preDelay <= m_activeElement->m_timeAlive )
          {
            *((_BYTE *)this + 168) |= 1u;
            if ( !m_activeElement->vfptr->PlayLine(
                    m_activeElement,
                    this->m_externalSourcePlaybackEvent,
                    this->m_linePriority,
                    *((_BYTE *)this + 168) >> 7)
              && m_activeElement->m_timeAlive > 3.0 )
            {
              UFG::Conversation::OnLineFinished(this);
            }
            if ( this->m_type == eConversationType_Scripted )
            {
              UFG::ScriptedConversationElement::SetConversationTargets((UFG::ScriptedConversationElement *)m_activeElement);
              if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
              {
                v21 = this->m_activeElement;
                if ( v21 )
                {
                  v22 = this->m_activeElement;
                  if ( this->m_curLine >= this->m_numElements )
                    v22 = 0i64;
                  UFG::qString::qString(&v27, &v21->m_context);
                  mData = v27.mData;
                  v24 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v22[1].vfptr[1].PlayLine);
                  m_curLine = this->m_curLine;
                  UFG::qPrintf(
                    "CONV DEBUG: %s : %6u : %s : line started %u, %s\n",
                    UFG::TidoGame::sm_timeStampStr.mData,
                    UFG::Metrics::msInstance.mSimFrameCount,
                    v24,
                    m_curLine,
                    mData);
                  UFG::qString::~qString(&v27);
                }
              }
            }
          }
          m_activeElement->m_timeAlive = delta_sec + m_activeElement->m_timeAlive;
          return 1;
        }
        if ( !m_activeElement->vfptr->LineIsPlaying(m_activeElement) || (*((_BYTE *)this + 168) & 1) == 0 )
        {
          if ( m_activeElement->vfptr->LineIsPlaying(m_activeElement) || m_activeElement->m_sampleLength <= 0.02 )
            return 1;
          m_activeElement->m_timeAlive = delta_sec + m_activeElement->m_timeAlive;
          goto LABEL_63;
        }
        m_activeElement->m_timeAlive = delta_sec + m_activeElement->m_timeAlive;
        m_activeElement->m_sampleLength = delta_sec + m_activeElement->m_sampleLength;
        UFG::ConversationElement::UpdateInterruptionPoints(m_activeElement, this);
      }
      return 1;
    }
  }
  UFG::Conversation::Interrupt(this, eInterruptType_Death, 0);
  UFG::Conversation::ForceFinish(this, v25);
  return 1;
}

// File Line: 1733
// RVA: 0x599120
bool __fastcall UFG::Conversation::ConversantsInSameVehicle(UFG::Conversation *this)
{
  UFG::ConversationElement *m_activeElement; // rax
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectGame *v6; // rbx
  UFG::CharacterOccupantComponent *m_pComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::CharacterOccupantComponent *v10; // rbx
  __int16 v11; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **p_mNext; // rcx
  UFG::VehicleOccupantComponent *CurrentVehicle; // rbx

  m_activeElement = this->m_activeElement;
  if ( m_activeElement )
  {
    m_pPointer = m_activeElement->m_spkAac.m_pPointer;
    if ( m_pPointer )
      m_pSimObject = (UFG::SimObjectGame *)m_pPointer->m_pSimObject;
    else
      m_pSimObject = 0i64;
    v5 = m_activeElement->m_tgtAac.m_pPointer;
    if ( v5 )
      v6 = (UFG::SimObjectGame *)v5->m_pSimObject;
    else
      v6 = 0i64;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::CharacterOccupantComponent *)m_pSimObject->m_Components.p[44].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pSimObject,
                                UFG::CharacterOccupantComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pSimObject,
                                UFG::CharacterOccupantComponent::_TypeUID);
        m_pComponent = (UFG::CharacterOccupantComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    if ( v6 )
    {
      v11 = v6->m_Flags;
      if ( (v11 & 0x4000) != 0 )
      {
        v10 = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent;
      }
      else
      {
        if ( v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v6, UFG::CharacterOccupantComponent::_TypeUID);
        v10 = (UFG::CharacterOccupantComponent *)ComponentOfType;
      }
    }
    else
    {
      v10 = 0i64;
    }
    p_mNext = &this->m_lines.mNode.mNext[-1].mNext;
    if ( p_mNext == (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)&this->m_type )
    {
LABEL_33:
      if ( m_pComponent && v10 )
      {
        UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
        CurrentVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(v10);
        LOBYTE(m_activeElement) = UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent) == CurrentVehicle;
      }
      else
      {
        LOBYTE(m_activeElement) = 0;
      }
    }
    else
    {
      while ( *((_DWORD *)p_mNext + 6) != qwsPlayCellPhone.mUID )
      {
        p_mNext = &p_mNext[2][-1].mNext;
        if ( p_mNext == (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)&this->m_type )
          goto LABEL_33;
      }
      LOBYTE(m_activeElement) = 1;
    }
  }
  return (char)m_activeElement;
}

// File Line: 1776
// RVA: 0x5935E0
void __fastcall UFG::ScriptedConversation::ScriptedConversation(
        UFG::ScriptedConversation *this,
        ASymbol *symbol,
        unsigned int uid)
{
  UFG::Conversation::Conversation(this, uid, eConversationType_Scripted);
  this->vfptr = (UFG::ConversationVtbl *)&UFG::ScriptedConversation::`vftable;
  this->m_script = 0i64;
  *((_BYTE *)&this->UFG::Conversation + 168) &= ~2u;
  UFG::ScriptedConversation::SetupScript(this, symbol);
}

// File Line: 1802
// RVA: 0x5AC310
void __fastcall UFG::ScriptedConversation::SetupScript(UFG::ScriptedConversation *this, ASymbol *symbol)
{
  SSActorClass *v4; // rdi
  UFG::TSScriptedDialogue *v5; // rax

  v4 = (SSActorClass *)SSBrain::get_class("ScriptedDialogue");
  if ( v4 )
  {
    v5 = (UFG::TSScriptedDialogue *)AMemory::c_malloc_func(0x88ui64, "TSScriptedDialogue");
    if ( v5 )
      UFG::TSScriptedDialogue::TSScriptedDialogue(v5, this, symbol, v4);
    this->m_script = v5;
    ++UFG::gNumScriptedConversations;
    ++this->m_script->i_ref_count;
    SSInstance::call_default_constructor(this->m_script);
    SSActor::enable_behavior(this->m_script, 1);
  }
}

// File Line: 1940
// RVA: 0x592B50
void __fastcall UFG::AmbientConversation::AmbientConversation(UFG::AmbientConversation *this, unsigned int uid)
{
  UFG::Conversation::Conversation(this, uid, eConversationType_Ambient);
  this->vfptr = (UFG::ConversationVtbl *)&UFG::AmbientConversation::`vftable;
  *((_BYTE *)&this->UFG::Conversation + 168) |= 4u;
  this->m_linePriority = 5;
}

// File Line: 1966
// RVA: 0x5AC2A0
void __fastcall UFG::AmbientConversation::SetupLines(
        UFG::AmbientConversation *this,
        UFG::SimObjectCharacter *person1,
        UFG::SimObjectCharacter *person2)
{
  if ( UFG::AmbientConversationConfigurator::Start(this->m_topic, this) )
  {
    UFG::AmbientConversationConfigurator::SetupConversation(this, person1, person2);
    UFG::AmbientConversationConfigurator::sm_isBusy = 0;
    UFG::AmbientConversationConfigurator::sm_curModel = 0i64;
    UFG::AmbientConversationConfigurator::sm_lastLineGroup = 0i64;
    UFG::AmbientConversationConfigurator::sm_curConversation = 0i64;
    UFG::AmbientConversationConfigurator::sm_curLine = 0;
  }
}

// File Line: 1980
// RVA: 0x1554DB0
__int64 dynamic_initializer_for__UFG::AmbientConversationConfigurator::sm_models__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AmbientConversationConfigurator::sm_models__);
}

// File Line: 2001
// RVA: 0x5A0960
void UFG::AmbientConversationConfigurator::LoadDefinitionFile(void)
{
  SimpleXML::XMLDocument *v0; // rax
  SimpleXML::XMLDocument *v1; // rsi
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *ChildNode; // r13
  char *Attribute; // rdi
  char v5; // si
  char v6; // bp
  __int16 v7; // r14
  double v8; // xmm0_8
  int v9; // xmm6_4
  double v10; // xmm0_8
  char v11; // r15
  char *v12; // r12
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rbx
  UFG::allocator::free_link *v15; // r8
  UFG::allocator::free_link *mNext; // rdx
  UFG::allocator::free_link *v17; // rcx
  UFG::allocator::free_link *v18; // rax
  int v19; // edx
  UFG::qStaticSymbol *v20; // rcx
  UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *mPrev; // rax
  SimpleXML::XMLNode *v22; // r12
  __int16 v23; // bx
  __int16 v24; // di
  __int16 v25; // si
  __int16 v26; // bp
  char v27; // r14
  char v28; // r15
  UFG::allocator::free_link *v29; // rax
  __int64 v30; // r13
  __int64 k; // rax
  _QWORD *v32; // rdx
  __int64 v33; // rcx
  _QWORD *v34; // rax
  __int64 *v35; // rax
  SimpleXML::XMLNode *v36; // r12
  char *Name; // rbx
  char *v38; // rbx
  unsigned int v39; // edi
  UFG::AmbientConversationConfigurator::Context *v40; // rax
  UFG::AmbientConversationConfigurator::Context *v41; // r13
  SimpleXML::XMLNode *v42; // rbp
  UFG::qList<UFG::AmbientConversationConfigurator::Action,UFG::AmbientConversationConfigurator::Action,1,0> *p_m_actions; // r15
  char *v44; // r14
  double v45; // xmm0_8
  char v46; // di
  UFG::allocator::free_link *v47; // rax
  UFG::allocator::free_link *v48; // rbx
  char *v49; // rax
  char *v50; // rax
  int v51; // esi
  __int64 v52; // rdi
  UFG::allocator::free_link *v53; // rax
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *v54; // rcx
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *v55; // rax
  UFG::AmbientConversationConfigurator::Context *v56; // [rsp+30h] [rbp-B8h]
  SimpleXML::XMLNode *m; // [rsp+38h] [rbp-B0h]
  SimpleXML::XMLNode *prev_node; // [rsp+40h] [rbp-A8h]
  SimpleXML::XMLNode *j; // [rsp+48h] [rbp-A0h]
  SimpleXML::XMLNode *i; // [rsp+50h] [rbp-98h]
  UFG::allocator::free_link *v61; // [rsp+58h] [rbp-90h]
  void *action_request; // [rsp+F0h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+F8h] [rbp+10h] BYREF
  SimpleXML::XMLDocument *v64; // [rsp+100h] [rbp+18h]
  UFG::allocator::free_link *v65; // [rsp+108h] [rbp+20h]

  v0 = SimpleXML::XMLDocument::Open("Data\\Audio\\AmbientConversationConfig.xml", 1ui64, 0i64);
  v1 = v0;
  v64 = v0;
  if ( v0 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v0, 0i64, 0i64);
    for ( i = Node; Node; i = Node )
    {
      ChildNode = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, Node);
      for ( j = ChildNode; ChildNode; j = ChildNode )
      {
        Attribute = SimpleXML::XMLNode::GetAttribute(ChildNode, "topic", &customCaption);
        v5 = SimpleXML::XMLNode::GetAttribute(ChildNode, "minLines", 0);
        v6 = SimpleXML::XMLNode::GetAttribute(ChildNode, "maxLines", 0);
        v7 = SimpleXML::XMLNode::GetAttribute(ChildNode, "numSpeakers", 0);
        v8 = SimpleXML::XMLNode::GetAttribute(
               ChildNode,
               "minTimeBetweenLines",
               COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
        v9 = LODWORD(v8);
        v10 = SimpleXML::XMLNode::GetAttribute(
                ChildNode,
                "maxTimeBetweenLines",
                COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
        v11 = SimpleXML::XMLNode::GetAttribute(ChildNode, "showSubtitles", 0);
        v12 = SimpleXML::XMLNode::GetAttribute(ChildNode, "event", &customCaption);
        v13 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x38ui64, "ConversationModel", 0i64, 1u);
        v14 = v13;
        action_request = v13;
        if ( v13 )
        {
          v13->mNext = v13;
          v13[1].mNext = v13;
          v13[2].mNext = 0i64;
          v13[3].mNext = 0i64;
          LODWORD(v13[4].mNext) = 0;
          BYTE4(v13[4].mNext) = 0;
          v15 = v13 + 5;
          v65 = v13 + 5;
          v13[5].mNext = v13 + 5;
          v13[6].mNext = v13 + 5;
          mNext = v13[6].mNext;
          if ( mNext != &v13[5] )
          {
            do
            {
              v17 = mNext->mNext;
              v18 = mNext[1].mNext;
              v17[1].mNext = v18;
              v18->mNext = v17;
              mNext->mNext = mNext;
              mNext[1].mNext = mNext;
              mNext = v14[6].mNext;
            }
            while ( mNext != v15 );
          }
        }
        else
        {
          v14 = 0i64;
        }
        LOBYTE(v14[3].mNext) = v5;
        BYTE1(v14[3].mNext) = v6;
        WORD1(v14[3].mNext) = v7;
        HIDWORD(v14[3].mNext) = v9;
        LODWORD(v14[4].mNext) = LODWORD(v10);
        BYTE4(v14[4].mNext) = v11;
        UFG::qSymbol::create_from_string(&result, Attribute);
        v19 = 0;
        v20 = UFG::ConversationTopicEnumSymbols;
        while ( result.mUID != v20->mUID )
        {
          ++v19;
          if ( (__int64)++v20 >= (__int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_MEATWRAPPED )
          {
            v19 = 25;
            break;
          }
        }
        LODWORD(v14[2].mNext) = v19;
        if ( (int)UFG::qStringLength(v12) > 0 )
          HIDWORD(v14[2].mNext) = UFG::TiDo::CalcWwiseUid(v12);
        mPrev = UFG::AmbientConversationConfigurator::sm_models.mNode.mPrev;
        UFG::AmbientConversationConfigurator::sm_models.mNode.mPrev->mNext = (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)v14;
        v14->mNext = (UFG::allocator::free_link *)mPrev;
        v14[1].mNext = (UFG::allocator::free_link *)&UFG::AmbientConversationConfigurator::sm_models;
        UFG::AmbientConversationConfigurator::sm_models.mNode.mPrev = (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)v14;
        v1 = v64;
        v22 = SimpleXML::XMLDocument::GetChildNode(v64, 0i64, ChildNode);
        prev_node = v22;
        if ( v22 )
        {
          v61 = v14 + 5;
          do
          {
            SimpleXML::XMLNode::GetName(v22);
            v23 = SimpleXML::XMLNode::GetAttribute(v22, "groupId", 0);
            v24 = SimpleXML::XMLNode::GetAttribute(v22, "precedingGroupId", 0);
            v25 = SimpleXML::XMLNode::GetAttribute(v22, "speaker", 0);
            v26 = SimpleXML::XMLNode::GetAttribute(v22, "maxLinesFromGroup", 0);
            v27 = SimpleXML::XMLNode::GetAttribute(v22, "terminalNode", 0);
            v28 = SimpleXML::XMLNode::GetAttribute(v22, "startNode", 0);
            v29 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "ConversationModel.LineGroup", 0i64, 1u);
            v30 = (__int64)v29;
            v65 = v29;
            action_request = v29;
            if ( v29 )
            {
              v29->mNext = v29;
              v29[1].mNext = v29;
              LODWORD(v29[2].mNext) = 0;
              WORD2(v29[2].mNext) = -1;
              HIWORD(v29[2].mNext) = 0;
              LOBYTE(v29[3].mNext) = 0;
              v29[4].mNext = v29 + 4;
              v29[5].mNext = v29 + 4;
              for ( k = (__int64)&v29[5].mNext[-1]; k != v30 + 24; k = *(_QWORD *)(v30 + 40) - 8i64 )
              {
                v32 = (_QWORD *)(k + 8);
                v33 = *(_QWORD *)(k + 8);
                v34 = *(_QWORD **)(k + 16);
                *(_QWORD *)(v33 + 8) = v34;
                *v34 = v33;
                *v32 = v32;
                v32[1] = v32;
              }
            }
            else
            {
              v30 = 0i64;
              v65 = 0i64;
            }
            *(_WORD *)(v30 + 16) = v23;
            *(_WORD *)(v30 + 22) = v24;
            *(_WORD *)(v30 + 18) = v25;
            *(_WORD *)(v30 + 20) = v26;
            *(_BYTE *)(v30 + 24) = v27;
            *(_BYTE *)(v30 + 25) = v28;
            v35 = (__int64 *)v61[1].mNext;
            v61[1].mNext = (UFG::allocator::free_link *)v30;
            *(_QWORD *)v30 = v61;
            *(_QWORD *)(v30 + 8) = v35;
            *v35 = v30;
            v1 = v64;
            v36 = SimpleXML::XMLDocument::GetChildNode(v64, 0i64, v22);
            for ( m = v36; v36; m = v36 )
            {
              Name = SimpleXML::XMLNode::GetName(v36);
              if ( (unsigned int)UFG::qStringCompare(Name, "Context", -1) )
              {
                if ( !(unsigned int)UFG::qStringCompare(Name, "PrecedingGroup", -1) )
                  *(_WORD *)(v30 + 22) |= 1 << SimpleXML::XMLNode::GetAttribute(v36, "id", 0);
              }
              else
              {
                v38 = SimpleXML::XMLNode::GetAttribute(v36, "name", &customCaption);
                v39 = SimpleXML::XMLNode::GetAttribute(v36, "weight", 0);
                v40 = (UFG::AmbientConversationConfigurator::Context *)UFG::qMemoryPool::Allocate(
                                                                         &g_AudioComponentPool,
                                                                         0x58ui64,
                                                                         "ConversationModel.Context",
                                                                         0i64,
                                                                         1u);
                action_request = v40;
                if ( v40 )
                  UFG::AmbientConversationConfigurator::Context::Context(v40);
                v41 = v40;
                v56 = v40;
                UFG::qString::Set(&v40->m_contextStr, v38);
                v41->m_weight = v39;
                v42 = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, v36);
                if ( v42 )
                {
                  p_m_actions = &v41->m_actions;
                  do
                  {
                    v44 = SimpleXML::XMLNode::GetAttribute(v42, "name", &customCaption);
                    v45 = SimpleXML::XMLNode::GetAttribute(v42, "time", 0.0);
                    v46 = SimpleXML::XMLNode::GetAttribute(v42, "onListener", 0);
                    v47 = UFG::qMemoryPool::Allocate(
                            &g_AudioComponentPool,
                            0x28ui64,
                            "AmbientConversation.Action",
                            0i64,
                            1u);
                    v48 = v47;
                    action_request = v47;
                    if ( v47 )
                    {
                      v47[1].mNext = v47 + 1;
                      v47[2].mNext = v47 + 1;
                      v47->mNext = (UFG::allocator::free_link *)&UFG::AmbientConversationConfigurator::Action::`vftable;
                      *(UFG::allocator::free_link **)((char *)&v47[3].mNext + 4) = 0i64;
                      BYTE4(v47[4].mNext) = 0;
                    }
                    else
                    {
                      v48 = 0i64;
                    }
                    HIDWORD(v48[3].mNext) = LODWORD(v45);
                    BYTE4(v48[4].mNext) = v46;
                    v49 = SimpleXML::XMLNode::GetName(v42);
                    if ( (unsigned int)UFG::qStringCompare(v49, "Gesture", -1) )
                    {
                      v50 = SimpleXML::XMLNode::GetName(v42);
                      if ( !(unsigned int)UFG::qStringCompare(v50, "Emotion", -1) )
                      {
                        LODWORD(v48[3].mNext) = 0;
                        v51 = 0;
                        v52 = 0i64;
                        while ( (unsigned int)UFG::qStringCompareInsensitive(v44, UFG::AIEmotionNames[v52], -1)
                             && (unsigned int)UFG::qStringCompareInsensitive(v44, UFG::FacialEmotionNames[v52], -1) )
                        {
                          ++v51;
                          if ( ++v52 >= 13 )
                          {
                            v51 = -1;
                            break;
                          }
                        }
                        LODWORD(v48[4].mNext) = v51;
                        v1 = v64;
                      }
                    }
                    else
                    {
                      LODWORD(v48[3].mNext) = 1;
                      LODWORD(action_request) = gActionRequest_Action.m_EnumValue;
                      Intention::GetActionRequest(v44, (unsigned int *)&action_request);
                      LODWORD(v48[4].mNext) = (_DWORD)action_request;
                    }
                    v53 = (UFG::allocator::free_link *)p_m_actions->mNode.mPrev;
                    v53[1].mNext = v48 + 1;
                    v48[1].mNext = v53;
                    v48[2].mNext = (UFG::allocator::free_link *)p_m_actions;
                    p_m_actions->mNode.mPrev = (UFG::qNode<UFG::AmbientConversationConfigurator::Action,UFG::AmbientConversationConfigurator::Action> *)&v48[1];
                    v42 = SimpleXML::XMLDocument::GetNode(v1, 0i64, v42);
                  }
                  while ( v42 );
                  v36 = m;
                  v41 = v56;
                }
                v54 = (UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *)&v65[4];
                v55 = (UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *)v65[5].mNext;
                v65[5].mNext = (UFG::allocator::free_link *)&v41->UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context>;
                v41->mPrev = v54;
                v41->mNext = v55;
                v55->mPrev = &v41->UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context>;
                v30 = (__int64)v65;
              }
              v36 = SimpleXML::XMLDocument::GetNode(v1, 0i64, v36);
            }
            v22 = SimpleXML::XMLDocument::GetNode(v1, 0i64, prev_node);
            prev_node = v22;
          }
          while ( v22 );
          ChildNode = j;
        }
        ChildNode = SimpleXML::XMLDocument::GetNode(v1, 0i64, ChildNode);
      }
      Node = SimpleXML::XMLDocument::GetNode(v1, 0i64, i);
    }
    SimpleXML::XMLDocument::~XMLDocument(v1);
    operator delete[](v1);
  }
}

// File Line: 2197
// RVA: 0x5AC5E0
char __fastcall UFG::AmbientConversationConfigurator::Start(UFG::eConversationTopic topic, UFG::Conversation *conv)
{
  int RandomTopic; // eax
  UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *mNext; // r8
  int v5; // r9d
  UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *mPrev; // rax
  int v7; // ecx

  RandomTopic = UFG::AmbientConversationConfigurator::GetRandomTopic(topic);
  mNext = UFG::AmbientConversationConfigurator::sm_models.mNode.mNext;
  UFG::AmbientConversationConfigurator::sm_isBusy = 1;
  v5 = RandomTopic;
  UFG::AmbientConversationConfigurator::sm_curLine = 0;
  UFG::AmbientConversationConfigurator::sm_curConversation = conv;
  UFG::AmbientConversationConfigurator::sm_lastLineGroup = 0i64;
  if ( (UFG::qList<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel,1,0> *)UFG::AmbientConversationConfigurator::sm_models.mNode.mNext == &UFG::AmbientConversationConfigurator::sm_models )
  {
LABEL_7:
    UFG::AmbientConversationConfigurator::sm_isBusy = 0;
    UFG::AmbientConversationConfigurator::sm_curLine = 0;
    UFG::AmbientConversationConfigurator::sm_curModel = 0i64;
    UFG::AmbientConversationConfigurator::sm_lastLineGroup = 0i64;
    UFG::AmbientConversationConfigurator::sm_curConversation = 0i64;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      if ( LODWORD(mNext[1].mPrev) == v5 )
      {
        mPrev = mNext[3].mPrev;
        v7 = 0;
        if ( mPrev != (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)&mNext[2].mNext )
        {
          do
          {
            mPrev = mPrev->mNext;
            ++v7;
          }
          while ( mPrev != (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)&mNext[2].mNext );
          if ( v7 > 0 )
            break;
        }
      }
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)&UFG::AmbientConversationConfigurator::sm_models )
        goto LABEL_7;
    }
    UFG::AmbientConversationConfigurator::sm_curModel = (UFG::AmbientConversationConfigurator::ConversationModel *)mNext;
    return 1;
  }
}

// File Line: 2225
// RVA: 0x59D400
__int64 __fastcall UFG::AmbientConversationConfigurator::GetRandomTopic(UFG::eConversationTopic inTopic)
{
  UFG::eConversationTopic v1; // ebx
  __int64 result; // rax
  float v3; // xmm0_4

  v1 = inTopic;
  if ( inTopic )
    return (unsigned int)v1;
  result = (unsigned int)UFG::ConversationManager::sm_debugConversationTopic;
  if ( UFG::ConversationManager::sm_debugConversationTopic == 1 )
    return 25i64;
  if ( UFG::ConversationManager::sm_debugConversationTopic != 2 )
  {
    if ( UFG::ConversationManager::sm_debugConversationTopic == 3 )
      return 44i64;
    if ( UFG::ConversationManager::sm_debugConversationTopic == 4 )
      return 29i64;
    v3 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    if ( v3 <= 0.25 )
    {
      return 25;
    }
    else
    {
      if ( v3 <= 0.5 )
        return 2i64;
      if ( v3 <= 0.75 )
        return 44i64;
      if ( v3 <= 1.0 )
        return 29i64;
    }
    return (unsigned int)v1;
  }
  return result;
}

// File Line: 2271
// RVA: 0x5ABD20
void __fastcall UFG::AmbientConversationConfigurator::SetupConversation(
        UFG::Conversation *conv,
        UFG::SimObjectCharacter *speaker1,
        UFG::SimObjectCharacter *speaker2)
{
  UFG::Conversation *v5; // rbp
  unsigned __int8 m_maxLines; // si
  unsigned __int16 m_numSpeakers; // r12
  float m_minTimeBetweenLines; // xmm6_4
  float m_maxTimeBetweenLines; // xmm7_4
  char m_showSubtitles; // r9
  char *v11; // rax
  char *v12; // rax
  UFG::ActorAudioComponent *v13; // r14
  signed __int16 m_Flags; // cx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  unsigned int m_activeAmbientConversationId; // edx
  UFG::qBaseTreeRB *v17; // rax
  unsigned int v18; // edx
  UFG::qBaseTreeRB *v19; // rax
  int *p_mCount; // rdi
  unsigned int v21; // ebx
  char *v22; // rax
  _BOOL8 v23; // rdx
  UFG::AudioEvent *m_pEvent; // rcx
  signed __int16 v25; // cx
  UFG::ActorAudioComponent *v26; // rax
  UFG::AudioEvent *v27; // rcx
  unsigned int v28; // ebx
  unsigned __int16 mUID; // r14
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **NextLine; // r12
  UFG::allocator::free_link *v31; // rax
  __int64 v32; // rax
  __int64 v33; // rdi
  __int16 m_speakerId; // ax
  UFG::SimObjectCharacter *v35; // rdx
  __int64 v36; // rax
  int v37; // esi
  __int64 i; // rbx
  unsigned int v39; // r9d
  float v40; // xmm2_4
  UFG::qWiseSymbol *VoiceId; // rax
  const char *v42; // rbx
  char *v43; // rax
  char *v44; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *mPrev; // rax
  bool v46; // cc
  UFG::AudioEvent *v47; // rcx
  char check_null; // [rsp+20h] [rbp-B8h]
  unsigned int v49; // [rsp+30h] [rbp-A8h]
  UFG::ActorAudioComponent *v50; // [rsp+38h] [rbp-A0h]
  UFG::qString v51; // [rsp+50h] [rbp-88h] BYREF
  UFG::qWiseSymbol result; // [rsp+E8h] [rbp+10h] BYREF
  unsigned int v54; // [rsp+F8h] [rbp+20h]

  v5 = conv;
  m_maxLines = UFG::AmbientConversationConfigurator::sm_curModel->m_maxLines;
  m_numSpeakers = UFG::AmbientConversationConfigurator::sm_curModel->m_numSpeakers;
  LOWORD(result.mUID) = m_numSpeakers;
  m_minTimeBetweenLines = UFG::AmbientConversationConfigurator::sm_curModel->m_minTimeBetweenLines;
  m_maxTimeBetweenLines = UFG::AmbientConversationConfigurator::sm_curModel->m_maxTimeBetweenLines;
  m_showSubtitles = UFG::AmbientConversationConfigurator::sm_curModel->m_showSubtitles;
  *((_BYTE *)conv + 168) &= ~0x80u;
  *((_BYTE *)conv + 168) |= m_showSubtitles << 7;
  conv->m_externalSourcePlaybackEvent = UFG::AmbientConversationConfigurator::sm_curModel->m_eventId;
  if ( UFG::ConversationManager::sm_debugAmbConversations )
  {
    v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&speaker1->m_Name);
    UFG::qPrintf("AmbConv:: Speaker1: %s \n", v11);
    if ( speaker2 )
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&speaker2->m_Name);
      UFG::qPrintf("AmbConv:: Speaker2: %s \n", v12);
    }
  }
  if ( speaker1 )
  {
    m_Flags = speaker1->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(speaker1);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        speaker1,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        speaker1,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    v13 = ComponentOfTypeHK;
  }
  else
  {
    v13 = 0i64;
  }
  v50 = v13;
  m_activeAmbientConversationId = v13->m_activeAmbientConversationId;
  if ( m_activeAmbientConversationId )
  {
    v17 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, m_activeAmbientConversationId);
    if ( v17 )
    {
      if ( v17 != (UFG::qBaseTreeRB *)8 )
      {
        v18 = v13->m_activeAmbientConversationId;
        if ( v18 && (v19 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v18)) != 0i64 )
          p_mCount = &v19[-1].mCount;
        else
          p_mCount = 0i64;
        v21 = p_mCount[36];
        v22 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&speaker1->m_Name);
        UFG::qPrintf("AmbConv:: Ambient ped in more than 1 ambient conversation: %s %u\n", v22, v21);
        UFG::Conversation::ForceFinish((UFG::Conversation *)p_mCount, v23);
      }
    }
  }
  v13->m_activeAmbientConversationId = 0;
  v13->m_activeAmbientConversationId = v5->mNode.mUID;
  if ( v13->m_curPlayingPriority <= 5 && (*((_BYTE *)v13 + 552) & 8) != 0 )
  {
    m_pEvent = v13->m_controller.m_pEvent;
    if ( m_pEvent )
      UFG::AudioEvent::StopAndForget(m_pEvent, 500);
  }
  if ( m_numSpeakers == 2 )
  {
    if ( !speaker2 )
      goto LABEL_76;
    v25 = speaker2->m_Flags;
    if ( (v25 & 0x4000) != 0 )
      v26 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(speaker2);
    else
      v26 = (UFG::ActorAudioComponent *)(v25 < 0 || (v25 & 0x2000) != 0 || (v25 & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           speaker2,
                                           UFG::ActorAudioComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(
                                           speaker2,
                                           UFG::ActorAudioComponent::_TypeUID));
    if ( !v26 )
      goto LABEL_76;
    v26->m_activeAmbientConversationId = 0;
    v26->m_activeAmbientConversationId = v5->mNode.mUID;
    if ( v26->m_curPlayingPriority <= 5 && (*((_BYTE *)v26 + 552) & 8) != 0 )
    {
      v27 = v26->m_controller.m_pEvent;
      if ( v27 )
        UFG::AudioEvent::StopAndForget(v27, 500);
    }
  }
  v28 = 0;
  v54 = 0;
  v49 = m_maxLines;
  if ( !m_maxLines )
    goto LABEL_75;
  mUID = result.mUID;
  while ( !UFG::AmbientConversationConfigurator::sm_lastLineGroup
       || !UFG::AmbientConversationConfigurator::sm_lastLineGroup->m_terminalNode )
  {
    NextLine = UFG::AmbientConversationConfigurator::GetNextLine();
    if ( UFG::AmbientConversationConfigurator::sm_lastLineGroup )
    {
      v31 = UFG::qMemoryPool::Allocate(
              &g_AudioComponentPool,
              0xA0ui64,
              "AmbientConversation.ConversationElement",
              0i64,
              1u);
      if ( v31 )
      {
        UFG::ConversationElement::ConversationElement((UFG::ConversationElement *)v31, eConversationElementType_Ambient);
        v33 = v32;
      }
      else
      {
        v33 = 0i64;
      }
      if ( mUID == 1
        || (m_speakerId = UFG::AmbientConversationConfigurator::sm_lastLineGroup->m_speakerId, m_speakerId < 0) )
      {
        if ( v28 % mUID )
          goto LABEL_57;
LABEL_53:
        UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)v33, speaker1);
        v35 = speaker2;
LABEL_58:
        UFG::ConversationElement::SetTarget((UFG::ConversationElement *)v33, v35);
      }
      else
      {
        if ( m_speakerId == 1 )
          goto LABEL_53;
        if ( m_speakerId == 2 )
        {
LABEL_57:
          UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)v33, speaker2);
          v35 = speaker1;
          goto LABEL_58;
        }
      }
      v36 = *(_QWORD *)(v33 + 104);
      if ( v36 && *(_QWORD *)(v36 + 40) && *((_DWORD *)NextLine + 17) )
      {
        if ( v28 )
          *(float *)(v33 + 72) = UFG::qRandom(
                                   m_maxTimeBetweenLines - m_minTimeBetweenLines,
                                   (unsigned int *)&UFG::qDefaultSeed)
                               + m_minTimeBetweenLines;
        v37 = 0;
        for ( i = (__int64)&NextLine[5][-1].mNext;
              (UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **)i != NextLine + 3;
              i = *(_QWORD *)(i + 16) - 8i64 )
        {
          v39 = *(_DWORD *)(i + 32);
          v40 = *(float *)(i + 28);
          check_null = *(_BYTE *)(i + 36);
          if ( *(_DWORD *)(i + 24) )
            UFG::ConversationElement::AddActionRequest((UFG::ConversationElement *)v33, v37, v40, v39, check_null);
          else
            UFG::ConversationElement::AddEmotionRequest((UFG::ConversationElement *)v33, v37, v40, v39, check_null);
          ++v37;
        }
        UFG::qString::Set((UFG::qString *)(v33 + 32), (const char *)NextLine[9], *((_DWORD *)NextLine + 17), 0i64, 0);
        if ( UFG::ConversationManager::sm_debugAmbConversations )
        {
          VoiceId = UFG::ActorAudioComponent::GetVoiceId(*(UFG::ActorAudioComponent **)(v33 + 104), &result);
          v42 = (const char *)NextLine[9];
          v43 = UFG::qWiseSymbol::as_cstr_dbg(VoiceId);
          UFG::qString::qString(&v51, "%s.%s", v43, v42);
          _((AMD_HD3D *)result.mUID);
          v44 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(*(_QWORD *)(*(_QWORD *)(v33 + 104) + 40i64) + 72i64));
          UFG::qPrintf("AmbConv:: %s \t\t %s \n", v44, v51.mData);
          UFG::qString::~qString(&v51);
        }
        v5 = conv;
        mPrev = conv->m_lines.mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)(v33 + 8);
        *(_QWORD *)(v33 + 8) = mPrev;
        *(_QWORD *)(v33 + 16) = &conv->m_lines;
        conv->m_lines.mNode.mPrev = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)(v33 + 8);
        ++conv->m_numElements;
        v28 = v54;
      }
      else
      {
        (**(void (__fastcall ***)(__int64, __int64))v33)(v33, 1i64);
      }
    }
    v54 = ++v28;
    if ( v28 >= v49 )
      break;
  }
  v13 = v50;
LABEL_75:
  if ( !v5->m_numElements )
  {
LABEL_76:
    v46 = v13->m_curPlayingPriority <= 5;
    v13->m_activeAmbientConversationId = 0;
    if ( v46 && (*((_BYTE *)v13 + 552) & 8) != 0 )
    {
      v47 = v13->m_controller.m_pEvent;
      if ( v47 )
        UFG::AudioEvent::StopAndForget(v47, 500);
    }
  }
}

// File Line: 2441
// RVA: 0x59D150
UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **__fastcall UFG::AmbientConversationConfigurator::GetNextLine()
{
  UFG::AmbientConversationConfigurator::LineGroup *v0; // rdi
  UFG::AmbientConversationConfigurator::ConversationModel *mNext; // rcx
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **result; // rax
  unsigned int m_numElements; // edx
  bool v4; // r14
  bool v5; // si
  UFG::qNode<UFG::AmbientConversationConfigurator::LineGroup,UFG::AmbientConversationConfigurator::LineGroup> *v6; // rbx
  UFG::AmbientConversationConfigurator::LineGroup *i; // rdi
  int mPrev_high; // eax
  UFG::allocator::free_link *v9; // rax
  __int64 *v10; // rcx
  UFG::allocator::free_link *v11; // rax
  __int64 *v12; // rax
  int v13; // ecx
  __int64 *v14; // rax
  int v15; // eax
  __int64 *v16; // rcx
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **v17; // rbx
  __int64 *j; // rcx
  __int64 v19; // rdx
  _QWORD *v20; // rax
  __int64 v21; // rdx
  _QWORD *v22; // rax
  __int64 *v23; // rcx
  _QWORD *v24; // rax
  __int64 *v25; // [rsp+28h] [rbp-18h] BYREF
  void *mem; // [rsp+30h] [rbp-10h]

  if ( !UFG::AmbientConversationConfigurator::sm_lastLineGroup )
  {
    v0 = 0i64;
    mNext = (UFG::AmbientConversationConfigurator::ConversationModel *)UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups.mNode.mNext;
    if ( mNext != (UFG::AmbientConversationConfigurator::ConversationModel *)&UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups )
    {
      while ( !mNext->m_maxLines )
      {
        mNext = (UFG::AmbientConversationConfigurator::ConversationModel *)mNext->mNext;
        if ( mNext == (UFG::AmbientConversationConfigurator::ConversationModel *)&UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups )
          goto LABEL_7;
      }
      v0 = (UFG::AmbientConversationConfigurator::LineGroup *)mNext;
    }
LABEL_7:
    result = UFG::AmbientConversationConfigurator::LineGroup::ChooseContext(v0);
    UFG::AmbientConversationConfigurator::sm_lastLineGroup = v0;
    return result;
  }
  m_numElements = UFG::AmbientConversationConfigurator::sm_curConversation->m_numElements;
  v4 = m_numElements >= (unsigned int)(unsigned __int8)UFG::AmbientConversationConfigurator::sm_curModel->m_minLines - 1;
  v5 = m_numElements == (unsigned __int8)UFG::AmbientConversationConfigurator::sm_curModel->m_maxLines - 1;
  v25 = (__int64 *)&v25;
  mem = &v25;
  v6 = UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups.mNode.mNext;
  for ( i = 0i64;
        v6 != (UFG::qNode<UFG::AmbientConversationConfigurator::LineGroup,UFG::AmbientConversationConfigurator::LineGroup> *)&UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups;
        v6 = v6->mNext )
  {
    if ( v5
      || (mPrev_high = HIWORD(v6[1].mPrev),
          !_bittest(&mPrev_high, LOBYTE(UFG::AmbientConversationConfigurator::sm_lastLineGroup->m_groupId))) )
    {
      if ( !LOBYTE(v6[1].mNext) )
        continue;
    }
    else if ( v4 || !LOBYTE(v6[1].mNext) )
    {
      v9 = UFG::qMalloc(0x18ui64, "PotentialLine.LineGroup", 0i64);
      v10 = (__int64 *)v9;
      if ( v9 )
      {
        v9->mNext = v9;
        v9[1].mNext = v9;
        v9[2].mNext = (UFG::allocator::free_link *)v6;
      }
      else
      {
        v10 = 0i64;
      }
LABEL_21:
      v12 = v25;
      v25[1] = (__int64)v10;
      *v10 = (__int64)v12;
      v10[1] = (__int64)&v25;
      v25 = v10;
      continue;
    }
    if ( v5 )
    {
      v11 = UFG::qMalloc(0x18ui64, "PotentialLine.LineGroup", 0i64);
      v10 = (__int64 *)v11;
      if ( v11 )
      {
        v11->mNext = v11;
        v11[1].mNext = v11;
        v11[2].mNext = (UFG::allocator::free_link *)v6;
      }
      else
      {
        v10 = 0i64;
      }
      goto LABEL_21;
    }
  }
  v13 = 0;
  v14 = (__int64 *)mem;
  if ( mem != &v25 )
  {
    do
    {
      ++v13;
      v14 = (__int64 *)v14[1];
    }
    while ( v14 != (__int64 *)&v25 );
  }
  v15 = UFG::qRandom(50 * v13, (unsigned int *)&UFG::qDefaultSeed);
  v16 = (__int64 *)mem;
  if ( mem != &v25 )
  {
    while ( 1 )
    {
      v15 -= 50;
      if ( v15 <= 0 )
        break;
      v16 = (__int64 *)v16[1];
      if ( v16 == (__int64 *)&v25 )
        goto LABEL_30;
    }
    i = (UFG::AmbientConversationConfigurator::LineGroup *)v16[2];
  }
LABEL_30:
  v17 = UFG::AmbientConversationConfigurator::LineGroup::ChooseContext(i);
  UFG::AmbientConversationConfigurator::sm_lastLineGroup = i;
  for ( j = (__int64 *)mem; mem != &v25; j = (__int64 *)mem )
  {
    v19 = *j;
    v20 = (_QWORD *)j[1];
    *(_QWORD *)(v19 + 8) = v20;
    *v20 = v19;
    *j = (__int64)j;
    j[1] = (__int64)j;
    v21 = *j;
    v22 = (_QWORD *)j[1];
    *(_QWORD *)(v21 + 8) = v22;
    *v22 = v21;
    *j = (__int64)j;
    j[1] = (__int64)j;
    operator delete[](j);
  }
  v23 = v25;
  v24 = mem;
  v25[1] = (__int64)mem;
  *v24 = v23;
  return v17;
}

// File Line: 2546
// RVA: 0x598630
UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **__fastcall UFG::AmbientConversationConfigurator::LineGroup::ChooseContext(
        UFG::AmbientConversationConfigurator::LineGroup *this)
{
  unsigned int v2; // ecx
  int v3; // edx
  bool *p_mNext; // rax
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **result; // rax
  bool *p_m_terminalNode; // rbx
  bool *v7; // rax
  int v8; // ecx

  v2 = 0;
  v3 = 0;
  p_mNext = (bool *)&this->m_contexts.mNode.mNext[-1].mNext;
  if ( p_mNext != &this->m_terminalNode )
  {
    do
    {
      ++v3;
      p_mNext = (bool *)(*((_QWORD *)p_mNext + 2) - 8i64);
    }
    while ( p_mNext != &this->m_terminalNode );
    if ( v3 == 1 )
      return &this->m_contexts.mNode.mNext[-1].mNext;
  }
  p_m_terminalNode = &this->m_terminalNode;
  v7 = (bool *)&this->m_contexts.mNode.mNext[-1].mNext;
  if ( v7 != &this->m_terminalNode )
  {
    do
    {
      v2 += *((_DWORD *)v7 + 6);
      v7 = (bool *)(*((_QWORD *)v7 + 2) - 8i64);
    }
    while ( v7 != p_m_terminalNode );
  }
  v8 = UFG::qRandom(v2, (unsigned int *)&UFG::qDefaultSeed);
  result = &this->m_contexts.mNode.mNext[-1].mNext;
  if ( result == (UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **)p_m_terminalNode )
    return 0i64;
  while ( 1 )
  {
    v8 -= *((_DWORD *)result + 6);
    if ( v8 <= 0 )
      break;
    result = &result[2][-1].mNext;
    if ( result == (UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> **)p_m_terminalNode )
      return 0i64;
  }
  return result;
}

// File Line: 2578
// RVA: 0x5AB170
void __fastcall UFG::ConversationElement::SetSpeaker(UFG::ConversationElement *this, UFG::SimObjectCharacter *speaker)
{
  signed __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *p_m_spkAac; // rdx
  UFG::SimComponent *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  if ( speaker )
  {
    m_Flags = speaker->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(speaker);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        speaker,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        speaker,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    p_m_spkAac = &this->m_spkAac;
    v7 = ComponentOfTypeHK;
    if ( this->m_spkAac.m_pPointer )
    {
      mPrev = p_m_spkAac->mPrev;
      mNext = this->m_spkAac.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_spkAac->mPrev = p_m_spkAac;
      this->m_spkAac.mNext = &this->m_spkAac;
    }
    this->m_spkAac.m_pPointer = v7;
    if ( v7 )
    {
      v10 = v7->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_spkAac;
      p_m_spkAac->mPrev = v10;
      this->m_spkAac.mNext = &v7->m_SafePointerList.mNode;
      v7->m_SafePointerList.mNode.mPrev = p_m_spkAac;
    }
  }
}

// File Line: 2586
// RVA: 0x5AB790
void __fastcall UFG::ConversationElement::SetTarget(UFG::ConversationElement *this, UFG::SimObjectCharacter *target)
{
  signed __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *p_m_tgtAac; // rdx
  UFG::SimComponent *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  if ( target )
  {
    m_Flags = target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(target);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        target,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        target,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    p_m_tgtAac = &this->m_tgtAac;
    v7 = ComponentOfTypeHK;
    if ( this->m_tgtAac.m_pPointer )
    {
      mPrev = p_m_tgtAac->mPrev;
      mNext = this->m_tgtAac.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_tgtAac->mPrev = p_m_tgtAac;
      this->m_tgtAac.mNext = &this->m_tgtAac;
    }
    this->m_tgtAac.m_pPointer = v7;
    if ( v7 )
    {
      v10 = v7->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_tgtAac;
      p_m_tgtAac->mPrev = v10;
      this->m_tgtAac.mNext = &v7->m_SafePointerList.mNode;
      v7->m_SafePointerList.mNode.mPrev = p_m_tgtAac;
    }
  }
}

// File Line: 2598
// RVA: 0x5A35E0
void __fastcall UFG::ConversationElement::NullifyMembers(UFG::ConversationElement *this)
{
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *i; // rdx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mNext; // rax
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mPrev; // rcx
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *p_m_spkAac; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *p_m_tgtAac; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax

  *((_BYTE *)this + 156) &= ~8u;
  this->m_preDelay = 0.0;
  UFG::qWiseSymbol::set_null(&this->m_playbackEvent);
  for ( i = this->m_interruptionPoints.mNode.mNext;
        &i[-1].mNext != (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> **)&this->m_tgtAac.m_pPointer;
        i = this->m_interruptionPoints.mNode.mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
  *((_BYTE *)this + 156) &= 0xE8u;
  this->m_interjectionPoint = -1.0;
  *(_QWORD *)&this->m_timeAlive = 0i64;
  if ( UFG::ConversationManager::sm_debugAmbConversations )
  {
    m_pPointer = this->m_spkAac.m_pPointer;
    v6 = this->m_tgtAac.m_pPointer;
    if ( m_pPointer )
      BYTE1(m_pPointer[8].m_pSimObject) &= ~2u;
    if ( v6 )
      BYTE1(v6[8].m_pSimObject) &= ~2u;
  }
  p_m_spkAac = &this->m_spkAac;
  if ( this->m_spkAac.m_pPointer )
  {
    v8 = p_m_spkAac->mPrev;
    v9 = this->m_spkAac.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_spkAac->mPrev = p_m_spkAac;
    this->m_spkAac.mNext = &this->m_spkAac;
  }
  this->m_spkAac.m_pPointer = 0i64;
  p_m_tgtAac = &this->m_tgtAac;
  if ( this->m_tgtAac.m_pPointer )
  {
    v11 = p_m_tgtAac->mPrev;
    v12 = this->m_tgtAac.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_m_tgtAac->mPrev = p_m_tgtAac;
    this->m_tgtAac.mNext = &this->m_tgtAac;
  }
  this->m_tgtAac.m_pPointer = 0i64;
  UFG::qString::Set(&this->m_context, &customCaption);
}

// File Line: 2640
// RVA: 0x596270
void __fastcall UFG::ConversationElement::AddInterruptPoint(UFG::ConversationElement *this, int id, float point)
{
  UFG::allocator::free_link *v5; // rax
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v6; // rcx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mPrev; // rax

  v5 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x28ui64, "ConversationElement.ElementInterruption", 0i64, 1u);
  if ( v5 )
  {
    v5[1].mNext = v5 + 1;
    v5[2].mNext = v5 + 1;
    v5->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementInterruption::`vftable;
    LODWORD(v5[3].mNext) = 0;
    HIDWORD(v5[3].mNext) = id;
    *(float *)&v5[4].mNext = point;
    BYTE4(v5[4].mNext) &= ~1u;
  }
  v6 = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v5[1];
  mPrev = this->m_interruptionPoints.mNode.mPrev;
  mPrev->mNext = v6;
  v6->mPrev = mPrev;
  v6->mNext = &this->m_interruptionPoints.mNode;
  this->m_interruptionPoints.mNode.mPrev = v6;
}

// File Line: 2649
// RVA: 0x596130
UFG::allocator::free_link *__fastcall UFG::ConversationElement::AddEmotionRequest(
        UFG::ConversationElement *this,
        int id,
        float point,
        const char *emotion,
        bool onListener)
{
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mPrev; // rcx

  v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "ConversationElement.ElementEmotionScr", 0i64, 1u);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8 + 1;
    v10->mNext = v10;
    v10[1].mNext = v10;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementInterruption::`vftable;
    LODWORD(v9[3].mNext) = 1;
    HIDWORD(v9[3].mNext) = id;
    *(float *)&v9[4].mNext = point;
    BYTE4(v9[4].mNext) &= ~1u;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementEmotionRequest::`vftable;
    BYTE4(v9[5].mNext) = onListener;
    LODWORD(v9[5].mNext) = UFG::ConversationElementEmotionRequest::LookupEmotion(emotion);
  }
  else
  {
    v9 = 0i64;
  }
  mPrev = this->m_interruptionPoints.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  v9[1].mNext = (UFG::allocator::free_link *)mPrev;
  v9[2].mNext = (UFG::allocator::free_link *)&this->m_interruptionPoints;
  this->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  return v9;
}

// File Line: 2659
// RVA: 0x596050
UFG::allocator::free_link *__fastcall UFG::ConversationElement::AddEmotionRequest(
        UFG::ConversationElement *this,
        int id,
        float point,
        unsigned int emotion_id,
        bool onListener)
{
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r10
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mPrev; // rcx

  v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "ConversationElement.ElementEmotionAmb", 0i64, 1u);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8 + 1;
    v10->mNext = v10;
    v10[1].mNext = v10;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementInterruption::`vftable;
    LODWORD(v9[3].mNext) = 1;
    HIDWORD(v9[3].mNext) = id;
    *(float *)&v9[4].mNext = point;
    BYTE4(v9[4].mNext) &= ~1u;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementEmotionRequest::`vftable;
    BYTE4(v9[5].mNext) = onListener;
    LODWORD(v9[5].mNext) = emotion_id;
  }
  else
  {
    v9 = 0i64;
  }
  mPrev = this->m_interruptionPoints.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  v9[1].mNext = (UFG::allocator::free_link *)mPrev;
  v9[2].mNext = (UFG::allocator::free_link *)&this->m_interruptionPoints;
  this->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  return v9;
}

// File Line: 2670
// RVA: 0x595E10
UFG::ConversationElementActionRequest *__fastcall UFG::ConversationElement::AddActionRequest(
        UFG::ConversationElement *this,
        unsigned int id,
        float point,
        const char *action_request_name,
        bool onListner)
{
  UFG::allocator::free_link *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mPrev; // rax

  v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "ConversationElement.ActionRequest", 0i64, 1u);
  if ( v8 )
  {
    UFG::ConversationElementActionRequest::ConversationElementActionRequest(
      (UFG::ConversationElementActionRequest *)v8,
      id,
      point,
      action_request_name,
      onListner);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  mPrev = this->m_interruptionPoints.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)(v10 + 8);
  *(_QWORD *)(v10 + 8) = mPrev;
  *(_QWORD *)(v10 + 16) = &this->m_interruptionPoints;
  this->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)(v10 + 8);
  return (UFG::ConversationElementActionRequest *)v10;
}

// File Line: 2680
// RVA: 0x595D20
UFG::allocator::free_link *__fastcall UFG::ConversationElement::AddActionRequest(
        UFG::ConversationElement *this,
        int id,
        float point,
        unsigned int action_request_id,
        bool onListner)
{
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r10
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mPrev; // rcx

  v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "ConversationElement.ActionRequest", 0i64, 1u);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8 + 1;
    v10->mNext = v10;
    v10[1].mNext = v10;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementInterruption::`vftable;
    LODWORD(v9[3].mNext) = 2;
    HIDWORD(v9[3].mNext) = id;
    *(float *)&v9[4].mNext = point;
    BYTE4(v9[4].mNext) &= ~1u;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementActionRequest::`vftable;
    LODWORD(v9[5].mNext) = action_request_id;
    v9[6].mNext = 0i64;
    v9[7].mNext = 0i64;
    LOBYTE(v9[8].mNext) = onListner;
  }
  else
  {
    v9 = 0i64;
  }
  mPrev = this->m_interruptionPoints.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  v9[1].mNext = (UFG::allocator::free_link *)mPrev;
  v9[2].mNext = (UFG::allocator::free_link *)&this->m_interruptionPoints;
  this->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  return v9;
}

// File Line: 2691
// RVA: 0x598B20
void __fastcall UFG::ConversationElement::ClearSpeechFlags(UFG::ConversationElement *this)
{
  UFG::SimComponent *m_pPointer; // rbx
  bool v3; // cc
  UFG::AudioEvent *mNext; // rcx
  UFG::SimComponent *v5; // rbx
  UFG::AudioEvent *v6; // rcx

  m_pPointer = this->m_spkAac.m_pPointer;
  if ( m_pPointer )
  {
    if ( this->m_type )
    {
      v3 = LODWORD(m_pPointer[6].m_pSimObject) <= 5;
      HIDWORD(m_pPointer[6].m_BoundComponentHandles.mNode.mPrev) = 0;
      if ( v3 && ((__int64)m_pPointer[8].m_pSimObject & 8) != 0 )
      {
        mNext = (UFG::AudioEvent *)m_pPointer[6].m_SafePointerList.mNode.mNext;
        if ( mNext )
          UFG::AudioEvent::StopAndForget(mNext, 500);
      }
    }
    LOBYTE(m_pPointer[8].m_pSimObject) &= 0xFCu;
    BYTE1(m_pPointer[8].m_pSimObject) &= ~0x20u;
    LOBYTE(m_pPointer[8].m_pSimObject) |= 0x18u;
    if ( UFG::ConversationManager::sm_debugScrConversations )
      BYTE1(m_pPointer[8].m_pSimObject) &= ~2u;
  }
  v5 = this->m_tgtAac.m_pPointer;
  if ( v5 )
  {
    if ( this->m_type )
    {
      v3 = LODWORD(v5[6].m_pSimObject) <= 5;
      HIDWORD(v5[6].m_BoundComponentHandles.mNode.mPrev) = 0;
      if ( v3 && ((__int64)v5[8].m_pSimObject & 8) != 0 )
      {
        v6 = (UFG::AudioEvent *)v5[6].m_SafePointerList.mNode.mNext;
        if ( v6 )
          UFG::AudioEvent::StopAndForget(v6, 500);
      }
    }
    LOBYTE(v5[8].m_pSimObject) &= 0xFCu;
    BYTE1(v5[8].m_pSimObject) &= ~0x20u;
    LOBYTE(v5[8].m_pSimObject) |= 0x18u;
    if ( UFG::ConversationManager::sm_debugScrConversations )
      BYTE1(v5[8].m_pSimObject) &= ~2u;
  }
}

// File Line: 2778
// RVA: 0x5AB330
void __fastcall UFG::ConversationElement::SetTagInterruptFlags(UFG::ConversationElement *this, bool enable)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimComponent *v3; // rax

  m_pPointer = this->m_spkAac.m_pPointer;
  if ( m_pPointer )
  {
    if ( enable )
      LOBYTE(m_pPointer[8].m_pSimObject) |= 0x18u;
    else
      LOBYTE(m_pPointer[8].m_pSimObject) &= 0xE7u;
  }
  v3 = this->m_tgtAac.m_pPointer;
  if ( v3 )
  {
    if ( enable )
      LOBYTE(v3[8].m_pSimObject) |= 0x18u;
    else
      LOBYTE(v3[8].m_pSimObject) &= 0xE7u;
  }
}

// File Line: 2813
// RVA: 0x5AB240
void __fastcall UFG::ConversationElement::SetSpkListFlags(UFG::ConversationElement *this, bool actionRequests)
{
  UFG::SimComponent *m_pPointer; // r8
  char m_pSimObject; // al
  UFG::SimComponent *v4; // rax

  m_pPointer = this->m_spkAac.m_pPointer;
  if ( m_pPointer )
  {
    m_pSimObject = (char)m_pPointer[8].m_pSimObject;
    BYTE1(m_pPointer[8].m_pSimObject) &= ~0x20u;
    LOBYTE(m_pPointer[8].m_pSimObject) = m_pSimObject & 0xFC | 1;
    BYTE1(m_pPointer[8].m_pSimObject) |= 32 * actionRequests;
  }
  v4 = this->m_tgtAac.m_pPointer;
  if ( v4 )
  {
    LOBYTE(v4[8].m_pSimObject) &= ~1u;
    BYTE1(v4[8].m_pSimObject) &= ~0x20u;
    LOBYTE(v4[8].m_pSimObject) |= 2u;
    BYTE1(v4[8].m_pSimObject) |= 32 * actionRequests;
  }
}

// File Line: 2838
// RVA: 0x5AA980
void __fastcall UFG::ConversationElement::SetActiveAmbConv(UFG::ConversationElement *this, UFG::Conversation *conv)
{
  UFG::SimComponent *m_pPointer; // r8
  UFG::AudioEvent *mNext; // rcx

  m_pPointer = this->m_spkAac.m_pPointer;
  if ( m_pPointer )
  {
    HIDWORD(m_pPointer[6].m_BoundComponentHandles.mNode.mPrev) = 0;
    if ( conv )
      HIDWORD(m_pPointer[6].m_BoundComponentHandles.mNode.mPrev) = conv->mNode.mUID;
    if ( LODWORD(m_pPointer[6].m_pSimObject) <= 5 && ((__int64)m_pPointer[8].m_pSimObject & 8) != 0 )
    {
      mNext = (UFG::AudioEvent *)m_pPointer[6].m_SafePointerList.mNode.mNext;
      if ( mNext )
        UFG::AudioEvent::StopAndForget(mNext, 500);
    }
  }
}

// File Line: 2857
// RVA: 0x5AAB90
void __fastcall UFG::ConversationElement::SetDebugFlags(UFG::ConversationElement *this, bool enable)
{
  UFG::SimComponent *m_pPointer; // r8
  UFG::SimComponent *v3; // rax

  m_pPointer = this->m_spkAac.m_pPointer;
  if ( m_pPointer )
  {
    BYTE1(m_pPointer[8].m_pSimObject) &= ~2u;
    BYTE1(m_pPointer[8].m_pSimObject) |= 2 * enable;
  }
  v3 = this->m_tgtAac.m_pPointer;
  if ( v3 )
  {
    BYTE1(v3[8].m_pSimObject) &= ~2u;
    BYTE1(v3[8].m_pSimObject) |= 2 * enable;
  }
}

// File Line: 2876
// RVA: 0x5ACB00
void __fastcall UFG::ConversationElement::StopLine(UFG::ConversationElement *this, bool force)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::AudioEvent *mNext; // rcx
  unsigned int m_uPlayingId; // ebx
  UFG::TiDo *Instance; // rax

  m_pPointer = this->m_spkAac.m_pPointer;
  if ( m_pPointer )
  {
    if ( LOBYTE(m_pPointer[5].m_pSimObject) )
    {
      if ( SHIDWORD(m_pPointer[6].m_BoundComponentHandles.mNode.mNext) > 0 )
      {
        mNext = (UFG::AudioEvent *)m_pPointer[6].m_SafePointerList.mNode.mNext;
        if ( mNext )
        {
          if ( force )
          {
            m_uPlayingId = mNext->m_uPlayingId;
            mNext->m_pController = 0i64;
            m_pPointer[6].m_SafePointerList.mNode.mNext = 0i64;
            if ( m_uPlayingId )
            {
              Instance = UFG::TiDo::GetInstance();
              UFG::TiDo::StopPlaying(Instance, m_uPlayingId);
            }
          }
          else if ( ((__int64)m_pPointer[8].m_pSimObject & 8) != 0 )
          {
            UFG::AudioEvent::StopAndForget(mNext, 500);
          }
        }
      }
    }
  }
}

// File Line: 2893
// RVA: 0x5AA5A0
void __fastcall UFG::ConversationElement::Reset(UFG::ConversationElement *this)
{
  UFG::SimComponent **p_m_pPointer; // r14
  UFG::SimComponent **p_mNext; // rsi
  UFG::SimComponent *v4; // rdi
  UFG::qBaseNodeRB *Target; // rbx
  UFG::qBaseNodeRB *Speaker; // rax

  p_m_pPointer = &this->m_tgtAac.m_pPointer;
  p_mNext = (UFG::SimComponent **)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
  *(_QWORD *)&this->m_timeAlive = 0i64;
  if ( p_mNext != &this->m_tgtAac.m_pPointer )
  {
    do
    {
      if ( p_mNext )
      {
        *((_BYTE *)p_mNext + 36) &= ~1u;
        v4 = *p_mNext;
        Target = UFG::ConversationElement::GetTarget(this);
        Speaker = UFG::ConversationElement::GetSpeaker(this);
        ((void (__fastcall *)(UFG::SimComponent **, UFG::qBaseNodeRB *, UFG::qBaseNodeRB *))v4->m_SafePointerList.mNode.mNext)(
          p_mNext,
          Speaker,
          Target);
      }
      p_mNext = (UFG::SimComponent **)&p_mNext[2][-1].m_BoundComponentHandles.mNode.mNext;
    }
    while ( p_mNext != p_m_pPointer );
  }
}

// File Line: 2925
// RVA: 0x5AC560
UFG::SimComponent *__fastcall UFG::ConversationElement::SpeakerInitialized(UFG::ConversationElement *this)
{
  UFG::SimComponent *result; // rax

  result = this->m_spkAac.m_pPointer;
  if ( result )
    return (UFG::SimComponent *)LOBYTE(result[5].m_pSimObject);
  return result;
}

// File Line: 2941
// RVA: 0x5A6450
char __fastcall UFG::ConversationElement::PlayLine(
        UFG::ConversationElement *this,
        unsigned int eventId,
        unsigned int inPriority,
        bool subtitle)
{
  UFG::ActorAudioComponent *m_pPointer; // rbp
  unsigned int mUID; // edi
  unsigned int v10; // eax

  m_pPointer = (UFG::ActorAudioComponent *)this->m_spkAac.m_pPointer;
  if ( (*((_BYTE *)this + 156) & 8) != 0 )
    inPriority = 10;
  if ( !m_pPointer )
    return 0;
  mUID = this->m_playbackEvent.mUID;
  if ( mUID == UFG::qWiseSymbol::get_null()->mUID )
    mUID = eventId;
  if ( this->m_type )
    return UFG::ActorAudioComponent::QueueSpeechExternalAmbient(
             m_pPointer,
             mUID,
             this->m_context.mData,
             0i64,
             inPriority,
             0,
             subtitle);
  v10 = UFG::TiDo::CalcWwiseUid(this->m_context.mData);
  return UFG::ActorAudioComponent::QueueSpeechExternalMission(m_pPointer, mUID, v10, 0i64, inPriority, subtitle);
}

// File Line: 2975
// RVA: 0x5A08C0
UFG::SimComponent *__fastcall UFG::ConversationElement::LineIsPlaying(UFG::ConversationElement *this)
{
  UFG::SimComponent *result; // rax

  result = this->m_spkAac.m_pPointer;
  if ( result )
    return (UFG::SimComponent *)(SHIDWORD(result[6].m_BoundComponentHandles.mNode.mNext) > 0
                              && result[6].m_SafePointerList.mNode.mNext);
  return result;
}

// File Line: 2989
// RVA: 0x5A9FE0
void __fastcall UFG::ConversationElement::RemoveInterruptPoint(UFG::ConversationElement *this, int id)
{
  UFG::SimComponent **p_m_pPointer; // rsi
  UFG::SimComponent **p_mNext; // rbx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  p_m_pPointer = &this->m_tgtAac.m_pPointer;
  p_mNext = (UFG::SimComponent **)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
  if ( p_mNext != &this->m_tgtAac.m_pPointer )
  {
    do
    {
      if ( *((_DWORD *)p_mNext + 7) == id )
      {
        v5 = p_mNext[1];
        v6 = p_mNext[2];
        v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v6;
        v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v5;
        p_mNext[1] = (UFG::SimComponent *)(p_mNext + 1);
        p_mNext[2] = (UFG::SimComponent *)(p_mNext + 1);
        if ( p_mNext )
          ((void (__fastcall *)(UFG::SimComponent **, __int64))(*p_mNext)->vfptr)(p_mNext, 1i64);
      }
      p_mNext = (UFG::SimComponent **)&p_mNext[2][-1].m_BoundComponentHandles.mNode.mNext;
    }
    while ( p_mNext != p_m_pPointer );
  }
}

// File Line: 3006
// RVA: 0x5A0390
bool __fastcall UFG::ConversationElement::InterruptPointReached(UFG::ConversationElement *this, int id)
{
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mNext; // rax
  UFG::SimComponent **p_m_pPointer; // rcx
  __int64 p_mNext; // rax

  mNext = this->m_interruptionPoints.mNode.mNext;
  p_m_pPointer = &this->m_tgtAac.m_pPointer;
  p_mNext = (__int64)&mNext[-1].mNext;
  if ( (UFG::SimComponent **)p_mNext == p_m_pPointer )
    return 0;
  while ( *(_DWORD *)(p_mNext + 28) != id )
  {
    p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
    if ( (UFG::SimComponent **)p_mNext == p_m_pPointer )
      return 0;
  }
  return *(_BYTE *)(p_mNext + 36) & 1;
}

// File Line: 3023
// RVA: 0x5B0B20
void __fastcall UFG::ConversationElement::UpdateInterruptionPoints(
        UFG::ConversationElement *this,
        UFG::Conversation *conversation)
{
  UFG::SimComponent **p_m_pPointer; // r14
  float *p_mNext; // rsi
  char v5; // al
  __int64 v6; // rdi
  UFG::qBaseNodeRB *Target; // rbx
  UFG::qBaseNodeRB *Speaker; // rax

  p_m_pPointer = &this->m_tgtAac.m_pPointer;
  p_mNext = (float *)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
  if ( p_mNext != (float *)&this->m_tgtAac.m_pPointer )
  {
    do
    {
      if ( p_mNext[8] <= this->m_sampleLength )
      {
        v5 = *((_BYTE *)p_mNext + 36);
        if ( (v5 & 1) == 0 )
        {
          v6 = *(_QWORD *)p_mNext;
          *((_BYTE *)p_mNext + 36) = v5 | 1;
          Target = UFG::ConversationElement::GetTarget(this);
          Speaker = UFG::ConversationElement::GetSpeaker(this);
          (*(void (__fastcall **)(float *, UFG::qBaseNodeRB *, UFG::qBaseNodeRB *))(v6 + 8))(p_mNext, Speaker, Target);
        }
      }
      p_mNext = (float *)(*((_QWORD *)p_mNext + 2) - 8i64);
    }
    while ( p_mNext != (float *)p_m_pPointer );
  }
}

// File Line: 3106
// RVA: 0x5ACCB0
char *__fastcall UFG::ConversationElement::ToString(UFG::ConversationElement *this)
{
  UFG::SimComponent *m_pPointer; // rcx
  char *v3; // rdi
  char *v4; // rax
  UFG::SimComponent *v5; // rcx
  __int64 v6; // r8
  UFG::ConversationElement *i; // rax
  UFG::qString *v8; // rax
  char *mData; // rbx
  UFG::qString v11; // [rsp+20h] [rbp-88h] BYREF
  __int64 v12; // [rsp+48h] [rbp-60h]
  UFG::qString text; // [rsp+50h] [rbp-58h] BYREF
  UFG::qString v14; // [rsp+78h] [rbp-30h] BYREF

  v12 = -2i64;
  m_pPointer = this->m_spkAac.m_pPointer;
  v3 = &customCaption;
  if ( m_pPointer )
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pPointer->m_pSimObject->m_Name);
  else
    v4 = &customCaption;
  UFG::qString::qString(&v11, v4);
  UFG::qString::operator+=(&v11, "->");
  v5 = this->m_tgtAac.m_pPointer;
  if ( v5 )
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->m_pSimObject->m_Name);
  UFG::qString::operator+=(&v11, v3);
  UFG::qString::operator+=(&v11, " : ");
  UFG::qString::qString(&text, &this->m_context);
  UFG::qString::operator+=(&v11, &text);
  v6 = 0i64;
  for ( i = (UFG::ConversationElement *)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
        i != (UFG::ConversationElement *)&this->m_tgtAac.m_pPointer;
        i = (UFG::ConversationElement *)&i->mNext[-1].mNext )
  {
    v6 = (unsigned int)(v6 + 1);
  }
  UFG::qString::qString(&v14, " : %u int pts", v6);
  UFG::qString::operator+=(&v11, v8);
  UFG::qString::~qString(&v14);
  mData = v11.mData;
  UFG::qString::~qString(&text);
  UFG::qString::~qString(&v11);
  return mData;
}

// File Line: 3144
// RVA: 0x593290
void __fastcall UFG::ConversationElementActionRequest::ConversationElementActionRequest(
        UFG::ConversationElementActionRequest *this,
        unsigned int id,
        float time,
        const char *action_request_name,
        bool onListener)
{
  const char *v5; // rbx
  const char *v8; // r9
  unsigned int action_request; // [rsp+48h] [rbp+10h] BYREF

  v5 = action_request_name;
  this->mPrev = &this->UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption>;
  this->mNext = &this->UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption>;
  this->vfptr = (UFG::ConversationElementInterruptionVtbl *)&UFG::ConversationElementInterruption::`vftable;
  this->m_type = eElementInterruptionType_ActionRequest;
  this->m_id = id;
  this->m_point = time;
  *((_BYTE *)&this->UFG::ConversationElementInterruption + 36) &= ~1u;
  this->vfptr = (UFG::ConversationElementInterruptionVtbl *)&UFG::ConversationElementActionRequest::`vftable;
  this->m_target = 0i64;
  this->m_targetInst = 0i64;
  this->m_playOnListener = onListener;
  action_request = gActionRequest_Action.m_EnumValue;
  Intention::GetActionRequest(action_request_name, &action_request);
  v8 = v5;
  LODWORD(v5) = action_request;
  UFG::qPrintf("Added action request: id: %3d   %10u --> %s\n", id, action_request, v8);
  this->m_actionRequest = (unsigned int)v5;
}

// File Line: 3167
// RVA: 0x5A4760
void __fastcall UFG::ConversationElementActionRequest::OnReached(
        UFG::ConversationElementActionRequest *this,
        UFG::SimObjectGame *speaker,
        UFG::SimObjectGame *listener)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  SSInstance *m_targetInst; // rcx
  UFG::TargetingSystemBaseComponent *ComponentOfType; // rax
  signed __int16 v10; // cx
  UFG::SimObjectGame *v11; // rcx
  bool v12; // zf

  if ( this->m_playOnListener )
    speaker = listener;
  if ( speaker )
  {
    m_Flags = speaker->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = speaker->m_Components.p[41].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(speaker, UFG::DialogueAnimationComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(speaker, UFG::DialogueAnimationComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
      *((_QWORD *)&m_pComponent[2].m_BoundComponentHandles.mNode.mPrev + ((__int64)(int)this->m_actionRequest >> 6)) |= 1i64 << (this->m_actionRequest & 0x3F);
  }
  if ( !this->m_target )
  {
    if ( !this->m_targetInst )
      return;
    m_targetInst = this->m_targetInst;
    if ( m_targetInst )
      this->m_target = (UFG::SimObject *)UFG::TSScriptedDialogueElement::GetSimObjectFromSymbol(m_targetInst);
  }
  if ( speaker )
  {
    v10 = speaker->m_Flags;
    if ( (v10 & 0x4000) != 0 || v10 < 0 )
    {
      ComponentOfType = (UFG::TargetingSystemBaseComponent *)speaker->m_Components.p[20].m_pComponent;
    }
    else
    {
      if ( (v10 & 0x2000) != 0 )
      {
        v11 = speaker;
      }
      else
      {
        v12 = (v10 & 0x1000) == 0;
        v11 = speaker;
        if ( v12 )
        {
          ComponentOfType = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                   speaker,
                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
          goto LABEL_29;
        }
      }
      ComponentOfType = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v11,
                                                               UFG::TargetingSystemBaseComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
LABEL_29:
  UFG::TargetingSystemBaseComponent::SetTarget(ComponentOfType, 0x25u, this->m_target);
}

// File Line: 3265
// RVA: 0x5A30D0
__int64 __fastcall UFG::ConversationElementEmotionRequest::LookupEmotion(const char *emotion_name)
{
  unsigned int v1; // edi
  __int64 v3; // rbx

  v1 = 0;
  v3 = 0i64;
  while ( (unsigned int)UFG::qStringCompareInsensitive(emotion_name, UFG::AIEmotionNames[v3], -1)
       && (unsigned int)UFG::qStringCompareInsensitive(emotion_name, UFG::FacialEmotionNames[v3], -1) )
  {
    ++v3;
    ++v1;
    if ( v3 >= 13 )
      return 0xFFFFFFFFi64;
  }
  return v1;
}

// File Line: 3291
// RVA: 0x5A48C0
void __fastcall UFG::ConversationElementEmotionRequest::OnReached(
        UFG::ConversationElementEmotionRequest *this,
        UFG::SimObjectCVBase *speaker,
        UFG::SimObjectCVBase *listener)
{
  signed __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  if ( this->m_playOnListener )
    speaker = listener;
  if ( speaker )
  {
    m_Flags = speaker->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(speaker);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            speaker,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            speaker,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_FacialEmotion = this->m_emotion;
  }
}

// File Line: 3310
// RVA: 0x5A4950
void __fastcall UFG::ConversationElementEmotionRequest::OnReset(
        UFG::ConversationElementEmotionRequest *this,
        UFG::SimObjectCVBase *speaker,
        UFG::SimObjectCVBase *listener)
{
  signed __int16 m_Flags; // cx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  if ( this->m_playOnListener )
    speaker = listener;
  if ( speaker )
  {
    m_Flags = speaker->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(speaker);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            speaker,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            speaker,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_FacialEmotion = eAI_EMOTION_NONE;
  }
}

// File Line: 3334
// RVA: 0x5AC3C0
void __fastcall UFG::ScriptedConversationElement::SetupScript(UFG::ScriptedConversationElement *this, ASymbol *symbol)
{
  SSActorClass *v4; // rdi
  UFG::TSScriptedDialogueElement *v5; // rax

  v4 = (SSActorClass *)SSBrain::get_class("ScriptedDialogueElement");
  if ( v4 )
  {
    v5 = (UFG::TSScriptedDialogueElement *)AMemory::c_malloc_func(0x88ui64, "TSScriptedDialogueElement");
    if ( v5 )
      UFG::TSScriptedDialogueElement::TSScriptedDialogueElement(v5, this, symbol, v4);
    this->m_script = v5;
    ++UFG::gNumScriptedConversationElements;
    ++this->m_script->i_ref_count;
    SSInstance::call_default_constructor(this->m_script);
    SSActor::enable_behavior(this->m_script, 1);
  }
}

// File Line: 3354
// RVA: 0x5948E0
void __fastcall UFG::ScriptedConversationElement::~ScriptedConversationElement(UFG::ScriptedConversationElement *this)
{
  UFG::TSScriptedDialogueElement *m_script; // rcx
  UFG::NonCharacterDialogueContainer *m_nonCharInfo; // rcx
  UFG::NonCharacterDialogueContainer *v5; // rcx

  this->vfptr = (UFG::ConversationElementVtbl *)&UFG::ScriptedConversationElement::`vftable;
  m_script = this->m_script;
  if ( m_script )
  {
    if ( m_script->i_ref_count-- == 1 )
    {
      m_script->i_ref_count = 0x80000000;
      m_script->vfptr[1].get_scope_context(m_script);
    }
    --UFG::gNumScriptedConversationElements;
    this->m_script = 0i64;
  }
  m_nonCharInfo = this->m_nonCharInfo;
  if ( m_nonCharInfo )
  {
    UFG::AudioEntity::Shutdown(m_nonCharInfo);
    v5 = this->m_nonCharInfo;
    if ( v5 )
      v5->vfptr->__vecDelDtor(v5, 1u);
  }
  this->m_nonCharInfo = 0i64;
  UFG::ConversationElement::~ConversationElement(this);
}

// File Line: 3379
// RVA: 0x5AB0E0
void __fastcall UFG::ScriptedConversationElement::SetPlaybackEvent(
        UFG::ScriptedConversationElement *this,
        const char *playback_event)
{
  unsigned int mUID; // eax

  UFG::qWiseSymbol::set_from_cstr(&this->m_playbackEvent, playback_event);
  mUID = this->m_playbackEvent.mUID;
  if ( mUID == qwsPlayCellPhone.mUID
    || mUID == qwsPlay2D.mUID
    || mUID == qwsPlayCB.mUID
    || mUID == qwsPlayDrivingNoLip.mUID
    || mUID == qwsPlayCellPhone0.mUID
    || mUID == qwsPlayCellPhone2.mUID
    || mUID == qwsPlayCellPhone4.mUID
    || mUID == qwsPlayCellPhone6.mUID
    || mUID == qwsPlayCB4.mUID
    || mUID == qwsPlayCB6.mUID
    || mUID == qwsPlayPoliceBullhorn.mUID
    || mUID == qwsPlayCellPhoneRingOutgoing.mUID )
  {
    UFG::ScriptedConversationElement::CreateNonCharacterContainer(this, 0i64);
  }
}

// File Line: 3405
// RVA: 0x59A5F0
void __fastcall UFG::ScriptedConversationElement::CreateNonCharacterContainer(
        UFG::ScriptedConversationElement *this,
        UFG::qVector3 *pos)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::NonCharacterDialogueContainer *v6; // rbx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // eax
  UFG::NonCharacterDialogueContainer *m_nonCharInfo; // rcx

  m_pTransformNodeComponent = 0i64;
  if ( !this->m_nonCharInfo )
  {
    v5 = UFG::qMalloc(0x150ui64, "DialogueManager.NonCharContainer", 0i64);
    v6 = (UFG::NonCharacterDialogueContainer *)v5;
    if ( v5 )
    {
      UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)v5);
      v6->vfptr = (UFG::AudioEntityVtbl *)&UFG::NonCharacterDialogueContainer::`vftable;
      v6->m_controller.m_pEvent = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    this->m_nonCharInfo = v6;
  }
  if ( pos )
  {
    y = pos->y;
    z = pos->z;
    x = pos->x;
  }
  else
  {
    LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
      m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  }
  m_nonCharInfo = this->m_nonCharInfo;
  m_nonCharInfo->m_WorldMatrix.v3.x = x;
  m_nonCharInfo->m_WorldMatrix.v3.y = y;
  m_nonCharInfo->m_WorldMatrix.v3.z = z;
  m_nonCharInfo->m_WorldMatrix.v3.w = 1.0;
  UFG::AudioEntity::ForcePositionUpdate(m_nonCharInfo);
}

// File Line: 3432
// RVA: 0x5AA640
void __fastcall UFG::ScriptedConversationElement::Reset(UFG::ScriptedConversationElement *this)
{
  UFG::NonCharacterDialogueContainer *m_nonCharInfo; // rcx

  m_nonCharInfo = this->m_nonCharInfo;
  if ( m_nonCharInfo )
    UFG::AudioEntity::Shutdown(m_nonCharInfo);
  UFG::ConversationElement::Reset(this);
}

// File Line: 3446
// RVA: 0x5AC580
char __fastcall UFG::ScriptedConversationElement::SpeakerInitialized(UFG::ScriptedConversationElement *this)
{
  UFG::NonCharacterDialogueContainer *m_nonCharInfo; // rcx
  UFG::SimComponent *m_pPointer; // rcx
  char result; // al

  m_nonCharInfo = this->m_nonCharInfo;
  if ( m_nonCharInfo )
  {
    if ( m_nonCharInfo->m_bIsInitialized )
    {
      return 1;
    }
    else
    {
      UFG::NonCharacterDialogueContainer::Init(m_nonCharInfo);
      return this->m_nonCharInfo->m_bIsInitialized;
    }
  }
  else
  {
    m_pPointer = this->m_spkAac.m_pPointer;
    result = 0;
    if ( m_pPointer )
      return (char)m_pPointer[5].m_pSimObject;
  }
  return result;
}

// File Line: 3466
// RVA: 0x5A66D0
char __fastcall UFG::ScriptedConversationElement::PlayLine(
        UFG::ScriptedConversationElement *this,
        unsigned int eventId,
        unsigned int inPriority,
        bool subtitle)
{
  unsigned int mUID; // ebx

  if ( !this->m_nonCharInfo )
    return UFG::ConversationElement::PlayLine(this, eventId, inPriority, subtitle);
  mUID = this->m_playbackEvent.mUID;
  if ( mUID == UFG::qWiseSymbol::get_null()->mUID )
    mUID = eventId;
  return UFG::NonCharacterDialogueContainer::PlayLine(this->m_nonCharInfo, mUID, this->m_context.mData, subtitle);
}

// File Line: 3481
// RVA: 0x5ACB90
void __fastcall UFG::ScriptedConversationElement::StopLine(UFG::ScriptedConversationElement *this, bool force)
{
  UFG::NonCharacterDialogueContainer *m_nonCharInfo; // r8
  UFG::AudioEvent *m_pEvent; // rax
  unsigned int m_uPlayingId; // ebx
  UFG::TiDo *Instance; // rax

  m_nonCharInfo = this->m_nonCharInfo;
  if ( m_nonCharInfo )
  {
    m_pEvent = m_nonCharInfo->m_controller.m_pEvent;
    if ( m_pEvent )
      m_uPlayingId = m_pEvent->m_uPlayingId;
    else
      m_uPlayingId = 0;
    if ( m_pEvent )
      m_pEvent->m_pController = 0i64;
    m_nonCharInfo->m_controller.m_pEvent = 0i64;
    Instance = UFG::TiDo::GetInstance();
    UFG::TiDo::StopPlaying(Instance, m_uPlayingId);
  }
  else
  {
    UFG::ConversationElement::StopLine(this, force);
  }
}

// File Line: 3494
// RVA: 0x5A08F0
bool __fastcall UFG::ScriptedConversationElement::LineIsPlaying(UFG::ScriptedConversationElement *this)
{
  UFG::NonCharacterDialogueContainer *m_nonCharInfo; // rdx
  UFG::SimComponent *m_pPointer; // rax

  m_nonCharInfo = this->m_nonCharInfo;
  if ( m_nonCharInfo )
    return m_nonCharInfo->m_controller.m_pEvent != 0i64;
  m_pPointer = this->m_spkAac.m_pPointer;
  return m_pPointer
      && SHIDWORD(m_pPointer[6].m_BoundComponentHandles.mNode.mNext) > 0
      && m_pPointer[6].m_SafePointerList.mNode.mNext;
}

// File Line: 3506
// RVA: 0x5AAA30
void __fastcall UFG::ScriptedConversationElement::SetConversationTargets(UFG::ScriptedConversationElement *this)
{
  UFG::SimComponent *m_pPointer; // rdi
  UFG::SimObjectGame *v2; // rbx
  UFG::SimObjectGame *m_pSimObject; // rdi
  UFG::SimComponent *v4; // rax
  __int16 m_Flags; // cx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rbp
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v8; // cx
  UFG::TargetingSystemBaseComponent *v9; // rsi
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = this->m_spkAac.m_pPointer;
  v2 = 0i64;
  if ( m_pPointer )
    m_pSimObject = (UFG::SimObjectGame *)m_pPointer->m_pSimObject;
  else
    m_pSimObject = 0i64;
  v4 = this->m_tgtAac.m_pPointer;
  if ( v4 )
    v2 = (UFG::SimObjectGame *)v4->m_pSimObject;
  if ( m_pSimObject && v2 )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pSimObject,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                              m_pSimObject,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
    }
    v8 = v2->m_Flags;
    if ( (v8 & 0x4000) != 0 )
    {
      v9 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
    }
    else if ( v8 >= 0 )
    {
      if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      v9 = (UFG::TargetingSystemBaseComponent *)ComponentOfType;
    }
    else
    {
      v9 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( v9 )
      {
        UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, 0x27u, v2);
        UFG::TargetingSystemBaseComponent::SetTarget(v9, 0x27u, m_pSimObject);
      }
    }
  }
}

// File Line: 3525
// RVA: 0x5988D0
void __fastcall UFG::ScriptedConversationElement::ClearConversationTargets(UFG::ScriptedConversationElement *this)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimObjectGame *v3; // rbx
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::SimComponent *v5; // rax
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v9; // cx
  UFG::TargetingSystemBaseComponent *v10; // rbx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = this->m_spkAac.m_pPointer;
  v3 = 0i64;
  if ( m_pPointer )
    m_pSimObject = (UFG::SimObjectGame *)m_pPointer->m_pSimObject;
  else
    m_pSimObject = 0i64;
  v5 = this->m_tgtAac.m_pPointer;
  if ( v5 )
    v3 = (UFG::SimObjectGame *)v5->m_pSimObject;
  if ( m_pSimObject && v3 )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pSimObject,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                              m_pSimObject,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
    }
    v9 = v3->m_Flags;
    if ( (v9 & 0x4000) != 0 )
    {
      v10 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    else if ( v9 >= 0 )
    {
      if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      v10 = (UFG::TargetingSystemBaseComponent *)ComponentOfType;
    }
    else
    {
      v10 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( v10 )
      {
        UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, 0x27u, 0i64);
        UFG::TargetingSystemBaseComponent::SetTarget(v10, 0x27u, 0i64);
      }
    }
  }
}

// File Line: 3553
// RVA: 0x59F770
void __fastcall UFG::NonCharacterDialogueContainer::Init(UFG::NonCharacterDialogueContainer *this)
{
  __int64 v2; // r8
  UFG::qString v3; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF

  v2 = sNum++;
  UFG::qString::qString(&v3, "NCDC_%u", v2);
  UFG::qSymbol::create_from_string(&result, v3.mData);
  UFG::AudioEntity::Init(this, (UFG::qSymbolUC *)&result, &UFG::qMatrix44::msIdentity);
  UFG::qString::~qString(&v3);
}

// File Line: 3570
// RVA: 0x5A6510
char __fastcall UFG::NonCharacterDialogueContainer::PlayLine(
        UFG::NonCharacterDialogueContainer *this,
        unsigned int eventId,
        const char *context,
        bool subtitle)
{
  unsigned int v7; // ebx
  UFG::allocator::free_link *v8; // rax
  UFG::AudioEventExternalSourceInfo *v9; // rax
  UFG::AudioEventExternalSourceInfo *v10; // rsi
  CAkSwitchCntr *p; // rcx
  UFG::ExternalSourceInfoNode *v12; // rbx
  UFG::AudioEventController *p_m_controller; // rdi
  UFG::AudioEventCallbackObject *mFreeListHead; // rbx
  unsigned int v15; // eax

  v7 = UFG::TiDo::CalcWwiseUid(context);
  if ( (int)UFG::TiDo::GetWwiseStreamFileSize(v7) > 0 )
  {
    v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x20ui64, "ExternalSourceInfo.QueueSpeech", 0i64, 1u);
    if ( v8 )
    {
      UFG::AudioEventExternalSourceInfo::AudioEventExternalSourceInfo((UFG::AudioEventExternalSourceInfo *)v8, 1u);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    p = (CAkSwitchCntr *)v10->m_externals.p;
    LODWORD(p->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr) = slot_1_22;
    v10->m_externals.p->m_fileId = v7;
    v12 = v10->m_externals.p;
    v12->m_codecID = Scaleform::Render::DICommand_ApplyFilter::GetType(p);
    p_m_controller = &this->m_controller;
    if ( !this->m_controller.m_pEvent )
    {
      UFG::AudioEntity::CreateEventA(this, eventId, &this->m_controller, 0i64, v10);
      if ( p_m_controller->m_pEvent )
      {
        if ( subtitle )
        {
          mFreeListHead = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
          if ( UFG::gAudioEventCallbackObjectPool.mFreeListHead )
          {
            UFG::gAudioEventCallbackObjectPool.mFreeListHead = *(char **)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
            v15 = UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated + 1;
            UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated = v15;
            if ( UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated <= v15 )
              UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated = v15;
          }
          else
          {
            UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventCallbackObjectPool);
          }
          if ( mFreeListHead )
          {
            mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
            mFreeListHead->m_next = 0i64;
            mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SubtitleCallback::`vftable;
          }
          if ( p_m_controller->m_pEvent )
            UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, mFreeListHead);
        }
        if ( p_m_controller->m_pEvent )
        {
          if ( p_m_controller->m_pEvent->vfptr->Play(p_m_controller->m_pEvent, 0) )
            return 1;
          *((_BYTE *)p_m_controller->m_pEvent + 144) |= 4u;
          if ( p_m_controller->m_pEvent )
            p_m_controller->m_pEvent->m_pController = 0i64;
          p_m_controller->m_pEvent = 0i64;
        }
        if ( p_m_controller->m_pEvent )
          UFG::AudioEvent::Destroy(p_m_controller->m_pEvent);
      }
    }
  }
  return 0;
}

// File Line: 3645
// RVA: 0x1554C30
__int64 dynamic_initializer_for__UFG::ConversationManager::sm_conversationDb__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ConversationManager::sm_conversationDb.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ConversationManager::sm_conversationDb__);
}

// File Line: 3678
// RVA: 0x59AD30
void UFG::ConversationManager::Destroy(void)
{
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx

  if ( UFG::ConversationManager::sm_conversationDb.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::ConversationManager::sm_conversationDb,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !UFG::ConversationManager::sm_conversationDb.mTree.mCount )
        return;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_6:
    p_mNode = 0i64;
    goto LABEL_7;
  }
}

// File Line: 3729
// RVA: 0x5966C0
UFG::ScriptedConversation *__fastcall UFG::ConversationManager::AddScriptedConversation(ASymbol *symbol)
{
  unsigned int i_uid; // ebx
  UFG::qBaseTreeRB *v3; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::qBaseNodeRB *v6; // rsi
  __int64 v7; // rax
  __int64 v8; // rdi
  __int64 v9; // rbx
  char *v10; // rax

  i_uid = symbol->i_uid;
  if ( symbol->i_uid )
  {
    v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, i_uid);
    if ( v3 )
    {
      if ( v3 != (UFG::qBaseTreeRB *)8 )
        return 0i64;
    }
  }
  v5 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xB8ui64, "ScriptedConversation", 0i64, 1u);
  v6 = 0i64;
  if ( v5 )
  {
    UFG::ScriptedConversation::ScriptedConversation((UFG::ScriptedConversation *)v5, symbol, i_uid);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( UFG::ConversationManager::sm_debugScrConversations )
  {
    v9 = *(_QWORD *)(v8 + 176);
    v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)symbol);
    UFG::qPrintf("Added scripted conversation %s: 0x%08x  0x%08x\n", v10, v8, v9);
  }
  if ( v8 )
    v6 = (UFG::qBaseNodeRB *)(v8 + 8);
  UFG::qBaseTreeRB::Add(&UFG::ConversationManager::sm_conversationDb.mTree, v6);
  return (UFG::ScriptedConversation *)v8;
}

// File Line: 3757
// RVA: 0x595EC0
UFG::AmbientConversation *__fastcall UFG::ConversationManager::AddAmbientConversation(unsigned int uid)
{
  UFG::qBaseTreeRB *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qBaseNodeRB *v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rbx

  if ( uid )
  {
    v2 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, uid);
    if ( v2 )
    {
      if ( v2 != (UFG::qBaseTreeRB *)8 )
        return 0i64;
    }
  }
  if ( UFG::ConversationManager::sm_disableAmbConversations )
    return 0i64;
  v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xB0ui64, "AmbientConversation", 0i64, 1u);
  v4 = 0i64;
  if ( v3 )
  {
    UFG::AmbientConversation::AmbientConversation((UFG::AmbientConversation *)v3, uid);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
    v4 = (UFG::qBaseNodeRB *)(v6 + 8);
  UFG::qBaseTreeRB::Add(&UFG::ConversationManager::sm_conversationDb.mTree, v4);
  return (UFG::AmbientConversation *)v6;
}

// File Line: 3795
// RVA: 0x5A9F40
void __fastcall UFG::ConversationManager::RemoveConversation(UFG::Conversation *conv, _BOOL8 a2)
{
  if ( conv )
  {
    if ( conv->m_type )
    {
      if ( conv->m_state == eConversationState_Playing )
        UFG::Conversation::OnFinish(conv, a2);
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::ConversationManager::sm_conversationDb,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&conv->UFG::qNodeRB<UFG::Conversation>);
    UFG::Conversation::Destroy(conv);
    conv->vfptr->__vecDelDtor(conv, 1i64);
  }
}

// File Line: 3859
// RVA: 0x5B0340
void __fastcall UFG::ConversationManager::UpdateConversations(float delta_sec)
{
  UFG::allocator::free_link *v1; // rbp
  unsigned int v2; // r13d
  unsigned int v3; // r12d
  unsigned int v4; // ebx
  UFG::qBaseTreeRB *i; // rax
  __int64 v6; // rdi
  int v7; // r14d
  __int64 v8; // r15
  unsigned int v9; // esi
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdx
  __int64 v14; // r8
  __int64 v15; // rcx
  __int64 v16; // rax
  __int64 v17; // r9
  __int64 v18; // rdx
  UFG::SimObject *v19; // r8
  __int64 v20; // rax
  UFG::SimObject *v21; // rdx
  unsigned int *v22; // rdi
  __int64 v23; // rsi
  UFG::qBaseTreeRB *v24; // rax
  _BOOL8 v25; // rdx
  int *p_mCount; // rbx
  UFG::allocator::free_link *mem; // [rsp+30h] [rbp-48h]
  int v28; // [rsp+88h] [rbp+10h]

  v1 = 0i64;
  mem = 0i64;
  v2 = 0;
  v3 = 0;
  v4 = 180;
  v28 = 180;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v6 + 8)) )
  {
    v6 = i ? (__int64)&i[-1].mCount : 0i64;
    if ( !v6 )
      break;
    UFG::Conversation::Update((UFG::Conversation *)v6, delta_sec);
    if ( (*(_BYTE *)(v6 + 168) & 2) != 0 && *(_DWORD *)(v6 + 48) == 7 )
    {
      UFG::Conversation::Update((UFG::Conversation *)v6, 0.0);
      v7 = *(_DWORD *)(v6 + 32);
      v8 = v2;
      v9 = v2 + 1;
      if ( v2 + 1 > v3 )
      {
        v10 = 1;
        if ( v3 )
          v10 = 2 * v3;
        for ( ; v10 < v9; v10 *= 2 )
          ;
        if ( v10 <= 4 )
          v10 = 4;
        if ( v10 - v9 > 0x10000 )
          v10 = v2 + 65537;
        if ( v10 != v2 )
        {
          v11 = 4i64 * v10;
          if ( !is_mul_ok(v10, 4ui64) )
            v11 = -1i64;
          v12 = UFG::qMalloc(v11, "TiDoHK", 0i64);
          v1 = v12;
          if ( mem )
          {
            if ( v2 )
            {
              v13 = v12;
              v14 = v2;
              do
              {
                LODWORD(v13->mNext) = *(_DWORD *)((char *)&v13->mNext + (char *)mem - (char *)v12);
                v13 = (UFG::allocator::free_link *)((char *)v13 + 4);
                --v14;
              }
              while ( v14 );
            }
            operator delete[](mem);
          }
          mem = v1;
          v3 = v10;
        }
        v4 = v28;
      }
      ++v2;
      *((_DWORD *)&v1->mNext + v8) = v7;
    }
    if ( UFG::ConversationManager::sm_debugConversationsWithActor )
    {
      v15 = *(_QWORD *)(v6 + 80) - 8i64;
      v16 = v15;
      v17 = v6 + 64;
      if ( v15 == v6 + 64 )
        continue;
      while ( 1 )
      {
        v18 = *(_QWORD *)(v16 + 104);
        v19 = v18 ? *(UFG::SimObject **)(v18 + 40) : 0i64;
        if ( v19 == UFG::ConversationManager::sm_debugConversationsWithActor )
          break;
        v16 = *(_QWORD *)(v16 + 16) - 8i64;
        if ( v16 == v17 )
        {
          if ( v15 == v17 )
            goto LABEL_49;
          while ( 1 )
          {
            v20 = *(_QWORD *)(v15 + 128);
            v21 = v20 ? *(UFG::SimObject **)(v20 + 40) : 0i64;
            if ( v21 == UFG::ConversationManager::sm_debugConversationsWithActor )
              goto LABEL_42;
            v15 = *(_QWORD *)(v15 + 16) - 8i64;
            if ( v15 == v17 )
              goto LABEL_49;
          }
        }
      }
LABEL_42:
      v4 += 20;
      goto LABEL_48;
    }
    if ( UFG::ConversationManager::sm_debugAmbConversations && *(_DWORD *)(v6 + 64) == 1
      || UFG::ConversationManager::sm_debugScrConversations && !*(_DWORD *)(v6 + 64) )
    {
      v4 += 15;
LABEL_48:
      v28 = v4;
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v6 + 8i64))(v6, v4);
      continue;
    }
LABEL_49:
    ;
  }
  if ( v2 )
  {
    v22 = (unsigned int *)v1;
    v23 = v2;
    do
    {
      if ( *v22 )
      {
        v24 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, *v22);
        if ( v24 )
        {
          p_mCount = &v24[-1].mCount;
          if ( v24 != (UFG::qBaseTreeRB *)8 )
          {
            if ( p_mCount[16] && p_mCount[12] == 1 )
              UFG::Conversation::OnFinish((UFG::Conversation *)&v24[-1].mCount, v25);
            UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
              (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::ConversationManager::sm_conversationDb,
              (UFG::qBaseNodeVariableRB<unsigned __int64> *)(p_mCount + 2));
            UFG::Conversation::Destroy((UFG::Conversation *)p_mCount);
            (**(void (__fastcall ***)(char *, __int64))p_mCount)((char *)p_mCount, 1i64);
          }
        }
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  if ( v1 )
    operator delete[](v1);
}

// File Line: 3973
// RVA: 0x5A0470
char __fastcall UFG::ConversationManager::IsInConversationWithTopic(
        UFG::SimObject *simObject,
        UFG::eConversationTopic topic)
{
  UFG::qBaseTreeRB *i; // rax
  int *p_mCount; // r10
  char *v5; // r9
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rdx
  UFG::SimObject *v9; // r8
  __int64 v10; // rcx
  UFG::SimObject *v11; // rdx

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(
              &UFG::ConversationManager::sm_conversationDb.mTree,
              (UFG::qBaseNodeRB *)(p_mCount + 2)) )
  {
    if ( i )
      p_mCount = &i[-1].mCount;
    else
      p_mCount = 0i64;
    if ( !p_mCount )
      return 0;
    v5 = (char *)(p_mCount + 16);
    v6 = *((_QWORD *)p_mCount + 10) - 8i64;
    v7 = v6;
    if ( (int *)v6 != p_mCount + 16 )
      break;
LABEL_18:
    ;
  }
  while ( 1 )
  {
    v8 = *(_QWORD *)(v7 + 104);
    v9 = v8 ? *(UFG::SimObject **)(v8 + 40) : 0i64;
    if ( v9 == simObject )
      return 1;
    v7 = *(_QWORD *)(v7 + 16) - 8i64;
    if ( (char *)v7 == v5 )
    {
      if ( (char *)v6 == v5 )
        goto LABEL_18;
      while ( 1 )
      {
        v10 = *(_QWORD *)(v6 + 128);
        v11 = v10 ? *(UFG::SimObject **)(v10 + 40) : 0i64;
        if ( v11 == simObject )
          return 1;
        v6 = *(_QWORD *)(v6 + 16) - 8i64;
        if ( (char *)v6 == v5 )
          goto LABEL_18;
      }
    }
  }
}

// File Line: 4030
// RVA: 0x59CD80
__int64 __fastcall UFG::ConversationManager::GetConversationId()
{
  __int64 v0; // r8
  unsigned int mStringHash32; // ebx
  UFG::qString v3; // [rsp+28h] [rbp-30h] BYREF

  v0 = UFG::ConversationManager::sm_idCounter++;
  UFG::qString::qString(&v3, "AmbientConversation_%u", v0);
  mStringHash32 = v3.mStringHash32;
  if ( v3.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(v3.mData, 0xFFFFFFFF);
    v3.mStringHash32 = mStringHash32;
  }
  UFG::qString::~qString(&v3);
  return mStringHash32;
}

// File Line: 4044
// RVA: 0x5AC960
void UFG::ConversationManager::StopAllScriptedConversations(void)
{
  UFG::qBaseTreeRB *i; // rax
  _BOOL8 v1; // rdx
  __int64 v2; // rbx
  char *v3; // rax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v2 + 8)) )
  {
    v2 = i ? (__int64)&i[-1].mCount : 0i64;
    if ( !v2 )
      break;
    if ( !*(_DWORD *)(v2 + 64) )
    {
      if ( UFG::ConversationManager::sm_debugScrConversations )
      {
        v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(*(_QWORD *)(v2 + 176) + 72i64));
        UFG::qPrintf(
          "CONV DEBUG: %s : %6u : Forcing Finish %s\n",
          UFG::TidoGame::sm_timeStampStr.mData,
          UFG::Metrics::msInstance.mSimFrameCount,
          v3);
      }
      *(_DWORD *)(v2 + 52) = 7;
      UFG::Conversation::OnFinish((UFG::Conversation *)v2, v1);
    }
  }
}

// File Line: 4064
// RVA: 0x5AC900
void UFG::ConversationManager::StopAllAmbientConversations(void)
{
  UFG::qBaseTreeRB *i; // rax
  _BOOL8 v1; // rdx
  __int64 v2; // rbx

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v2 + 8)) )
  {
    v2 = i ? (__int64)&i[-1].mCount : 0i64;
    if ( !v2 )
      break;
    if ( *(_DWORD *)(v2 + 64) == 1 )
    {
      *(_DWORD *)(v2 + 52) = 7;
      UFG::Conversation::OnFinish((UFG::Conversation *)v2, v1);
    }
  }
  UFG::ConversationManager::UpdateConversations(0.0099999998);
}

// File Line: 4087
// RVA: 0x5A0350
__int64 __fastcall UFG::ConversationManager::InterruptPlayerConversations(
        UFG::eInterruptType intType,
        bool force,
        UFG::SimObject *ignore)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax

  LocalPlayer = UFG::GetLocalPlayer();
  return UFG::ConversationManager::InterruptConversationsWithCharacter(LocalPlayer, intType, force, ignore);
}

// File Line: 4100
// RVA: 0x5A0130
__int64 __fastcall UFG::ConversationManager::InterruptConversationsWithCharacter(
        UFG::SimObject *character,
        UFG::eInterruptType intType,
        bool force,
        UFG::SimObject *ignore)
{
  unsigned __int8 v8; // di
  UFG::qBaseTreeRB *i; // rax
  __int64 v10; // rbx
  __int64 v11; // r9
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rdx
  UFG::SimObject *v15; // r8
  __int64 v16; // rax
  __int64 v17; // rdx
  UFG::SimObject *v18; // r8
  __int64 v19; // rax
  __int64 v20; // rdx
  UFG::SimObject *v21; // r8
  __int64 v22; // rax
  UFG::SimObject *v23; // rdx

  v8 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v10 + 8)) )
  {
    v10 = i ? (__int64)&i[-1].mCount : 0i64;
    if ( !v10 )
      break;
    if ( *(_DWORD *)(v10 + 48) == 1 )
    {
      v11 = v10 + 64;
      if ( !*(_DWORD *)(v10 + 64) )
      {
        v12 = *(_QWORD *)(v10 + 80) - 8i64;
        v13 = v12;
        if ( v12 == v11 )
        {
LABEL_14:
          v16 = *(_QWORD *)(v10 + 80) - 8i64;
          if ( v12 == v11 )
            continue;
          while ( 1 )
          {
            v17 = *(_QWORD *)(v16 + 128);
            v18 = v17 ? *(UFG::SimObject **)(v17 + 40) : 0i64;
            if ( v18 == character )
              break;
            v16 = *(_QWORD *)(v16 + 16) - 8i64;
            if ( v16 == v11 )
              goto LABEL_36;
          }
        }
        else
        {
          while ( 1 )
          {
            v14 = *(_QWORD *)(v13 + 104);
            v15 = v14 ? *(UFG::SimObject **)(v14 + 40) : 0i64;
            if ( v15 == character )
              break;
            v13 = *(_QWORD *)(v13 + 16) - 8i64;
            if ( v13 == v11 )
              goto LABEL_14;
          }
        }
        if ( !ignore || (v19 = *(_QWORD *)(v10 + 80) - 8i64, v12 == v11) )
        {
LABEL_34:
          UFG::Conversation::Interrupt((UFG::Conversation *)v10, intType, force);
        }
        else
        {
          while ( 1 )
          {
            v20 = *(_QWORD *)(v19 + 104);
            v21 = v20 ? *(UFG::SimObject **)(v20 + 40) : 0i64;
            if ( v21 == ignore )
              break;
            v19 = *(_QWORD *)(v19 + 16) - 8i64;
            if ( v19 == v11 )
            {
              if ( v12 == v11 )
                goto LABEL_34;
              while ( 1 )
              {
                v22 = *(_QWORD *)(v12 + 128);
                v23 = v22 ? *(UFG::SimObject **)(v22 + 40) : 0i64;
                if ( v23 == ignore )
                  goto LABEL_35;
                v12 = *(_QWORD *)(v12 + 16) - 8i64;
                if ( v12 == v11 )
                  goto LABEL_34;
              }
            }
          }
        }
LABEL_35:
        v8 = 1;
      }
    }
LABEL_36:
    ;
  }
  return v8;
}

// File Line: 4134
// RVA: 0x5AA830
__int64 __fastcall UFG::ConversationManager::ResumePlayerConversations(UFG::eInterruptType intType)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax

  LocalPlayer = UFG::GetLocalPlayer();
  return UFG::ConversationManager::ResumeConversationsWithCharacter(LocalPlayer, intType);
}

// File Line: 4147
// RVA: 0x5AA730
__int64 __fastcall UFG::ConversationManager::ResumeConversationsWithCharacter(
        UFG::SimObject *character,
        UFG::eInterruptType intType)
{
  unsigned __int8 v4; // di
  UFG::qBaseTreeRB *i; // rax
  __int64 v6; // r10
  __int64 v7; // r9
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rdx
  UFG::SimObject *v11; // r8
  __int64 v12; // rcx
  UFG::SimObject *v13; // rdx

  v4 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v6 + 8)) )
  {
    v6 = i ? (__int64)&i[-1].mCount : 0i64;
    if ( !v6 )
      break;
    if ( *(_DWORD *)(v6 + 48) == 3 )
    {
      v7 = v6 + 64;
      if ( !*(_DWORD *)(v6 + 64) )
      {
        v8 = *(_QWORD *)(v6 + 80) - 8i64;
        v9 = v8;
        if ( v8 != v7 )
        {
          while ( 1 )
          {
            v10 = *(_QWORD *)(v9 + 104);
            v11 = v10 ? *(UFG::SimObject **)(v10 + 40) : 0i64;
            if ( v11 == character )
              break;
            v9 = *(_QWORD *)(v9 + 16) - 8i64;
            if ( v9 == v7 )
            {
              if ( v8 == v7 )
                goto LABEL_24;
              while ( 1 )
              {
                v12 = *(_QWORD *)(v8 + 128);
                v13 = v12 ? *(UFG::SimObject **)(v12 + 40) : 0i64;
                if ( v13 == character )
                  goto LABEL_21;
                v8 = *(_QWORD *)(v8 + 16) - 8i64;
                if ( v8 == v7 )
                  goto LABEL_24;
              }
            }
          }
LABEL_21:
          if ( intType == *(_DWORD *)(v6 + 148) )
            *(_DWORD *)(v6 + 52) = 5;
          v4 = 1;
        }
      }
    }
LABEL_24:
    ;
  }
  return v4;
}

