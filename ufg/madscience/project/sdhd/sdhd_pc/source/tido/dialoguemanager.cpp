// File Line: 58
// RVA: 0x155CB20
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone, "play_cellphone");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone__);
}

// File Line: 59
// RVA: 0x155C9A0
__int64 UFG::_dynamic_initializer_for__qwsPlay2D__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlay2D, "play_2d");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlay2D__);
}

// File Line: 60
// RVA: 0x155CA30
__int64 UFG::_dynamic_initializer_for__qwsPlayCB__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCB, "play_cb");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCB__);
}

// File Line: 61
// RVA: 0x155CB80
__int64 UFG::_dynamic_initializer_for__qwsPlayDrivingNoLip__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayDrivingNoLip, "play_driving_no_lip");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayDrivingNoLip__);
}

// File Line: 63
// RVA: 0x155CA60
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone0__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone0, "play_cellphone_0");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone0__);
}

// File Line: 64
// RVA: 0x155CA90
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone2__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone2, "play_cellphone_2");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone2__);
}

// File Line: 65
// RVA: 0x155CAC0
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone4__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone4, "play_cellphone_4");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone4__);
}

// File Line: 66
// RVA: 0x155CAF0
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhone6__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhone6, "play_cellphone_6");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhone6__);
}

// File Line: 67
// RVA: 0x155C9D0
__int64 UFG::_dynamic_initializer_for__qwsPlayCB4__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCB4, "play_cb_4");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCB4__);
}

// File Line: 68
// RVA: 0x155CA00
__int64 UFG::_dynamic_initializer_for__qwsPlayCB6__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCB6, "play_cb_6");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCB6__);
}

// File Line: 69
// RVA: 0x155CBB0
__int64 UFG::_dynamic_initializer_for__qwsPlayPoliceBullhorn__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayPoliceBullhorn, "Play_police_bullhorn");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayPoliceBullhorn__);
}

// File Line: 70
// RVA: 0x155CB50
__int64 UFG::_dynamic_initializer_for__qwsPlayCellPhoneRingOutgoing__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayCellPhoneRingOutgoing, "Play_cellphone_ring_outgoing");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayCellPhoneRingOutgoing__);
}

// File Line: 138
// RVA: 0x5931C0
void __fastcall UFG::Conversation::Conversation(UFG::Conversation *this, unsigned int uid, UFG::Conversation::eConversationType type)
{
  UFG::qList<UFG::ConversationElement,UFG::ConversationElement,1,0> *v3; // [rsp+58h] [rbp+20h]
  UFG::qList<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement>,1,0> *v4; // [rsp+58h] [rbp+20h]
  UFG::qList<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol>,1,0> *v5; // [rsp+58h] [rbp+20h]

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  this->vfptr = (UFG::ConversationVtbl *)&UFG::Conversation::`vftable';
  this->m_activeElement = 0i64;
  *(_QWORD *)&this->m_state = 0i64;
  *(_DWORD *)&this->m_curLine = 0;
  this->m_linePriority = 7;
  this->m_type = type;
  v3 = &this->m_lines;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = &this->m_prevPlayed;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = &this->m_animationBanks;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->m_externalSourcePlaybackEvent = 0;
  *(_QWORD *)&this->m_topic = 25i64;
  *(_QWORD *)&this->m_maxSeparationDistance = 1101004800i64;
  this->m_interruptedTime = 0.0;
  *(_DWORD *)&this->m_avoidRepeatingLastNLines = 1;
  *((_BYTE *)this + 168) = -118;
  *((_BYTE *)this + 169) = *((_BYTE *)this + 169) & 0xFB | 0xA;
  UFG::Conversation::Clear(this);
}

// File Line: 154
// RVA: 0x594300
void __fastcall UFG::Conversation::~Conversation(UFG::Conversation *this)
{
  UFG::Conversation *v1; // rdi
  UFG::qList<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol>,1,0> *v2; // rbx
  UFG::qNode<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol> > *v3; // rcx
  UFG::qNode<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol> > *v4; // rax
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v5; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v6; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v7; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::ConversationVtbl *)&UFG::Conversation::`vftable';
  v2 = &this->m_animationBanks;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_animationBanks);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->m_prevPlayed);
  v5 = v1->m_prevPlayed.mNode.mPrev;
  v6 = v1->m_prevPlayed.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->m_prevPlayed.mNode.mPrev = &v1->m_prevPlayed.mNode;
  v1->m_prevPlayed.mNode.mNext = &v1->m_prevPlayed.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_lines);
  v7 = v1->m_lines.mNode.mPrev;
  v8 = v1->m_lines.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->m_lines.mNode.mPrev = &v1->m_lines.mNode;
  v1->m_lines.mNode.mNext = &v1->m_lines.mNode;
}

// File Line: 164
// RVA: 0x5987F0
void __fastcall UFG::Conversation::Clear(UFG::Conversation *this)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v1; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **v2; // rdi
  UFG::Conversation *v3; // rbx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v4; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v5; // rdx

  v1 = this->m_lines.mNode.mNext;
  v2 = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)&this->m_type;
  v3 = this;
  if ( &v1[-1].mNext != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)&this->m_type )
  {
    do
    {
      v4 = v1->mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mPrev = v1;
      v1->mNext = v1;
      if ( v1 != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)8 )
        ((void (__fastcall *)(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **, signed __int64))v1[-1].mNext->mPrev)(
          &v1[-1].mNext,
          1i64);
      v1 = v3->m_lines.mNode.mNext;
    }
    while ( &v1[-1].mNext != v2 );
  }
  v3->m_onResume = 0i64;
  v3->m_onInterrupt = 0i64;
  v3->m_activeElement = 0i64;
}

// File Line: 177
// RVA: 0x596020
char __fastcall UFG::Conversation::AddElement(UFG::Conversation *this, UFG::ConversationElement *element)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v2; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v3; // rdx

  v2 = this->m_lines.mNode.mPrev;
  v3 = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)&element->mPrev;
  v2->mNext = v3;
  v3->mPrev = v2;
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
  UFG::Conversation *v3; // rbx
  UFG::eInterruptType v4; // eax
  bool result; // al
  UFG::Conversation *v6; // rax
  UFG::Conversation *v7; // rcx
  float v8; // xmm0_4
  UFG::Conversation *v9; // rcx

  v2 = delta_sec + this->m_interruptedTime;
  v3 = this;
  this->m_state = this->m_newState;
  v4 = this->m_interruptType;
  this->m_interruptedTime = v2;
  switch ( v4 )
  {
    case 1:
      if ( UFG::Conversation::IsFurtherThanMaxSeparationDistance(this, this->m_activeElement) )
        goto LABEL_20;
      v3->m_newState = 5;
      return 1;
    case 2:
      v9 = this->m_onInterrupt;
      if ( v9 && v9->m_state == 7 )
      {
        *((_BYTE *)v9 + 168) |= 2u;
        v3->m_onInterrupt = 0i64;
      }
      if ( v3->m_onInterrupt )
        goto LABEL_20;
      v8 = FLOAT_6_0;
      goto LABEL_18;
    case 3:
    case 5:
    case 7:
    case 8:
      v6 = this->m_onInterrupt;
      if ( !v6 || v6->m_state != 7 )
        goto LABEL_20;
      *((_BYTE *)v6 + 168) |= 2u;
      result = 1;
      this->m_onInterrupt = 0i64;
      return result;
    case 4:
      v7 = this->m_onInterrupt;
      if ( v7 && v7->m_state == 7 )
      {
        *((_BYTE *)v7 + 168) |= 2u;
        v3->m_onInterrupt = 0i64;
      }
      if ( !v3->m_onInterrupt )
      {
        v8 = FLOAT_2_0;
LABEL_18:
        if ( v8 < v3->m_interruptedTime )
        {
          v3->m_interruptedTime = 0.0;
          v3->m_newState = 5;
        }
      }
      goto LABEL_20;
    case 6:
      UFG::Conversation::ForceFinish(this, 5368709120i64);
      result = 1;
      break;
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
  UFG::Conversation *v2; // rbx
  UFG::Conversation *v3; // rcx
  bool result; // al
  UFG::eConversationState v5; // eax
  bool v6; // zf

  v2 = this;
  v3 = this->m_onResume;
  if ( v3 )
  {
    v5 = v3->m_state;
    if ( v5 )
    {
      if ( v5 == 7 )
      {
        v2->m_newState = 1;
        v2->m_interruptedTime = 0.0;
        *((_BYTE *)v3 + 168) |= 2u;
        v2->m_onResume = 0i64;
      }
    }
    else
    {
      v6 = v2->m_interruptType == 3;
      v2->m_interruptedTime = delta_sec + v2->m_interruptedTime;
      if ( v6 && UFG::Conversation::ConversantsInSameVehicle(v2) )
      {
        UFG::Conversation::Start(v2->m_onResume);
        result = 1;
        v2->m_interruptType = 0;
        return result;
      }
    }
  }
  else if ( v2->m_interruptType != 3
         || (v2->m_interruptedTime = delta_sec + v2->m_interruptedTime, UFG::Conversation::ConversantsInSameVehicle(v2)) )
  {
    result = 1;
    v2->m_newState = 1;
    v2->m_interruptedTime = 0.0;
    return result;
  }
  return 1;
}

// File Line: 371
// RVA: 0x5A49E0
char __fastcall UFG::Conversation::OnResume(UFG::Conversation *this)
{
  UFG::Conversation *v1; // rbx
  UFG::ConversationElement *v2; // rax
  bool v3; // zf

  v1 = this;
  v2 = UFG::Conversation::GetResumeElement(this);
  v1->m_activeElement = v2;
  if ( v2 )
    v2->vfptr->Reset(v2);
  v3 = v1->m_interruptType == 3;
  v1->m_state = 5;
  if ( !v3 || UFG::Conversation::ConversantsInSameVehicle(v1) )
    v1->m_interruptType = 0;
  return 1;
}

// File Line: 432
// RVA: 0x5A43E0
char __fastcall UFG::Conversation::OnInterrupt(UFG::Conversation *this)
{
  UFG::Conversation *v1; // rdi
  UFG::SimObject *v2; // rsi
  UFG::ConversationElement *v3; // rbp
  __int64 v4; // r8
  int v5; // edx
  unsigned int v6; // ebx
  UFG::AmbientConversation *v7; // rax
  UFG::AmbientConversation *v8; // rbx
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rax
  char result; // al
  UFG::qString v14; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = 0i64;
  v3 = 0i64;
  if ( this->m_curLine < this->m_numElements )
    v3 = this->m_activeElement;
  v4 = UFG::ConversationManager::sm_idCounter++;
  UFG::qString::qString(&v14, "AmbientConversation_%u", v4);
  v6 = v14.mStringHash32;
  if ( v14.mStringHash32 == -1 )
  {
    v6 = UFG::qStringHash32(v14.mData, v14.mStringHash32 | v5);
    v14.mStringHash32 = v6;
  }
  UFG::qString::~qString(&v14);
  switch ( v1->m_interruptType )
  {
    case 2:
      v7 = UFG::ConversationManager::AddAmbientConversation(v6);
      v7->m_topic = 56;
      break;
    case 3:
      v7 = UFG::ConversationManager::AddAmbientConversation(v6);
      v7->m_topic = 57;
      break;
    case 4:
      v7 = UFG::ConversationManager::AddAmbientConversation(v6);
      v7->m_topic = 65;
      break;
    default:
      goto LABEL_23;
  }
  v8 = v7;
  if ( *((_BYTE *)v1 + 169) & 1 )
  {
    v9 = v3->m_tgtAac.m_pPointer;
    if ( v9 )
      v10 = v9->m_pSimObject;
    else
      v10 = 0i64;
    v11 = v3->m_spkAac.m_pPointer;
  }
  else
  {
    v12 = v3->m_spkAac.m_pPointer;
    if ( v12 )
      v10 = v12->m_pSimObject;
    else
      v10 = 0i64;
    v11 = v3->m_tgtAac.m_pPointer;
  }
  if ( v11 )
    v2 = v11->m_pSimObject;
  UFG::AmbientConversation::SetupLines(v8, v2, v10);
  v8->m_linePriority = 9;
  *((_BYTE *)&v8->0 + 169) &= 0xFDu;
  *((_BYTE *)&v8->0 + 168) &= 0xFDu;
  *((_BYTE *)&v8->0 + 168) |= 0x80u;
  v1->m_onInterrupt = (UFG::Conversation *)&v8->vfptr;
  UFG::Conversation::Start((UFG::Conversation *)&v8->vfptr);
LABEL_23:
  result = 1;
  v1->m_state = 3;
  return result;
}

// File Line: 508
// RVA: 0x5AC6A0
char __fastcall UFG::Conversation::Start(UFG::Conversation *this)
{
  bool v1; // zf
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v2; // rdx
  UFG::Conversation::eConversationType *v3; // r9
  signed __int64 v4; // rdx
  signed __int64 v5; // rax
  char *v6; // rax

  v1 = this->m_activeElement == 0i64;
  this->m_newState = 1;
  if ( v1 )
    this->m_activeElement = (UFG::ConversationElement *)&this->m_lines.mNode.mNext[-1].mNext;
  v2 = this->m_lines.mNode.mNext;
  v3 = &this->m_type;
  while ( 1 )
  {
    v4 = (signed __int64)&v2[-1].mNext;
    if ( (UFG::Conversation::eConversationType *)v4 == v3 )
      break;
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 144) - 8i64;
      if ( v5 != v4 + 128 )
      {
        while ( !v5 || *(_DWORD *)(v5 + 24) != 2 )
        {
          v5 = *(_QWORD *)(v5 + 16) - 8i64;
          if ( v5 == v4 + 128 )
            goto LABEL_10;
        }
        *((_BYTE *)this + 168) |= 0x40u;
        break;
      }
    }
LABEL_10:
    v2 = *(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)(v4 + 16);
  }
  if ( *v3 == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Playing '%s'\n",
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
  UFG::Conversation::eConversationType *v1; // rsi
  UFG::Conversation *v2; // rbx
  UFG::Conversation *v3; // rdi

  v1 = &this->m_type;
  v2 = (UFG::Conversation *)&this->m_lines.mNode.mNext[-1].mNext;
  v3 = this;
  this->m_curLine = 0;
  this->m_activeElement = 0i64;
  if ( v2 != (UFG::Conversation *)&this->m_type )
  {
    do
    {
      ((void (__fastcall *)(UFG::Conversation *))v2->vfptr->PrintDebugInfo)(v2);
      v2 = (UFG::Conversation *)&v2->mNode.mChild[0][-1].mUID;
    }
    while ( v2 != (UFG::Conversation *)v1 );
  }
  UFG::Conversation::Start(v3);
  return 1;
}

// File Line: 550
// RVA: 0x5AA550
char __fastcall UFG::Conversation::Reset(UFG::Conversation *this)
{
  UFG::Conversation::eConversationType *v1; // rdi
  UFG::Conversation *v2; // rbx

  v1 = &this->m_type;
  v2 = (UFG::Conversation *)&this->m_lines.mNode.mNext[-1].mNext;
  this->m_curLine = 0;
  this->m_activeElement = 0i64;
  if ( v2 != (UFG::Conversation *)&this->m_type )
  {
    do
    {
      ((void (__fastcall *)(UFG::Conversation *))v2->vfptr->PrintDebugInfo)(v2);
      v2 = (UFG::Conversation *)&v2->mNode.mChild[0][-1].mUID;
    }
    while ( v2 != (UFG::Conversation *)v1 );
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
    *((_BYTE *)this + 168) &= 0xEFu;
    this->m_newState = 6;
    *((_BYTE *)this + 168) |= 16 * stoppedAfterLine;
    if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
    {
      v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
      UFG::qPrintf(
        "CONV DEBUG: %s : %6u : Stopping '%s'\n",
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
  UFG::ConversationElement *v1; // rax

  v1 = this->m_activeElement;
  if ( v1 )
  {
    *((_BYTE *)v1 + 156) |= 1u;
    LOBYTE(v1) = 1;
  }
  return (char)v1;
}

// File Line: 620
// RVA: 0x5A35C0
char __fastcall UFG::Conversation::NextLine(UFG::Conversation *this)
{
  if ( this->m_state != 1 )
    this->m_activeElement = UFG::Conversation::GetNextElement(this);
  return 1;
}

// File Line: 633
// RVA: 0x5A8190
char __fastcall UFG::Conversation::PrevLine(UFG::Conversation *this)
{
  UFG::ConversationElement *v1; // rdx
  UFG::Conversation *v3; // rdx

  if ( this->m_state != 1 )
  {
    v1 = this->m_activeElement;
    if ( !v1 )
    {
      this->m_activeElement = 0i64;
      return 1;
    }
    v3 = (UFG::Conversation *)&v1->mPrev[-1].mNext;
    if ( v3 == (UFG::Conversation *)&this->m_type )
      v3 = (UFG::Conversation *)&v3->mNode.mParent[-1].mUID;
    if ( v3 == (UFG::Conversation *)&this->m_lines.mNode.mPrev[-1].mNext )
      v3 = (UFG::Conversation *)&this->m_lines.mNode.mNext[-1].mNext;
    this->m_activeElement = (UFG::ConversationElement *)v3;
  }
  return 1;
}

// File Line: 646
// RVA: 0x5A3510
bool __fastcall UFG::Conversation::MoveToNextGroup(UFG::Conversation *this)
{
  UFG::Conversation *v1; // rdi
  UFG::ConversationElement *v2; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v4; // rbx
  signed __int64 v5; // rdi
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **i; // rbx

  v1 = this;
  if ( this->m_state != 1 )
  {
    if ( (unsigned int)UFG::Conversation::GetGroupCount(this) <= 1 )
    {
      v4 = v1->m_lines.mNode.mNext;
      v1->m_curLine = 0;
      v1->m_activeElement = 0i64;
      v5 = (signed __int64)&v1->m_type;
      for ( i = &v4[-1].mNext;
            i != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)v5;
            i = &i[2][-1].mNext )
      {
        ((void (__fastcall *)(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **))(*i)->mNext)(i);
      }
    }
    else
    {
      while ( 1 )
      {
        v2 = UFG::Conversation::GetNextElement(v1);
        v1->m_activeElement = v2;
        if ( !v2 )
          break;
        if ( *((_BYTE *)v2 + 156) & 1 )
        {
          if ( v2 )
            v1->m_activeElement = UFG::Conversation::GetNextElement(v1);
          break;
        }
      }
      if ( !v1->m_activeElement )
        return UFG::Conversation::Reset(v1);
    }
  }
  return 1;
}

// File Line: 684
// RVA: 0x5A0620
bool __fastcall UFG::Conversation::IsLastLineInGroup(UFG::Conversation *this)
{
  UFG::ConversationElement *v1; // rax
  bool result; // al

  result = 1;
  if ( this->m_curLine != this->m_numElements - 1 )
  {
    v1 = this->m_activeElement;
    if ( !v1 || !(*((_BYTE *)v1 + 156) & 1) )
      result = 0;
  }
  return result;
}

// File Line: 691
// RVA: 0x59A6E0
bool __fastcall UFG::Conversation::CurrentGroupIsLast(UFG::Conversation *this)
{
  UFG::ConversationElement *v1; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v3; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v4; // rcx
  signed __int64 v5; // rax

  v1 = this->m_activeElement;
  if ( !v1 )
    return UFG::Conversation::GetGroupCount(this) < 2;
  v3 = v1->mNext;
  if ( !v3 )
    return 1;
  v4 = v3->mNext;
  v5 = (signed __int64)&v3[-1].mNext;
  if ( !v4 )
    return 1;
  while ( !(*(_BYTE *)(v5 + 156) & 1) )
  {
    v5 = (signed __int64)&v4[-1].mNext;
    if ( !v4 )
      v5 = 0i64;
    v4 = *(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)(v5 + 16);
    if ( !v4 )
      return 1;
  }
  return 0;
}

// File Line: 728
// RVA: 0x59AC30
void __fastcall UFG::Conversation::Destroy(UFG::Conversation *this)
{
  UFG::Conversation *v1; // rdi
  UFG::Conversation *v2; // rcx
  UFG::Conversation *v3; // rcx
  UFG::Conversation::eConversationType *v4; // rsi
  UFG::ConversationElement *v5; // rbx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *i; // rdx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v7; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v8; // rax
  char *v9; // rax

  v1 = this;
  v2 = this->m_onResume;
  if ( v2 )
    UFG::Conversation::Destroy(v2);
  v3 = v1->m_onInterrupt;
  if ( v3 )
    UFG::Conversation::Destroy(v3);
  v4 = &v1->m_type;
  v5 = (UFG::ConversationElement *)&v1->m_lines.mNode.mNext[-1].mNext;
  if ( v5 != (UFG::ConversationElement *)&v1->m_type )
  {
    do
    {
      UFG::ConversationElement::ClearSpeechFlags(v5);
      v5 = (UFG::ConversationElement *)&v5->mNext[-1].mNext;
    }
    while ( v5 != (UFG::ConversationElement *)v4 );
  }
  for ( i = v1->m_lines.mNode.mNext;
        &i[-1].mNext != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)&v1->m_type;
        i = v1->m_lines.mNode.mNext )
  {
    v7 = i->mPrev;
    v8 = i->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **, signed __int64))i[-1].mNext->mPrev)(
        &i[-1].mNext,
        1i64);
  }
  v1->m_activeElement = 0i64;
  v1->m_numElements = 0;
  *(_QWORD *)&v1->m_state = 0i64;
  if ( *v4 == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Forcing Finish '%s'\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v9);
  }
}

// File Line: 783
// RVA: 0x59D4C0
UFG::ConversationElement *__fastcall UFG::Conversation::GetResumeElement(UFG::Conversation *this)
{
  UFG::ConversationElement *v1; // rsi
  UFG::Conversation *v2; // rdi
  UFG::ConversationElement *v3; // rbx
  int v4; // ecx
  char v5; // al
  UFG::ConversationElement *result; // rax

  v1 = 0i64;
  v2 = this;
  v3 = 0i64;
  if ( this->m_curLine < this->m_numElements )
    v3 = this->m_activeElement;
  UFG::Conversation::OnLineFinished(this);
  v4 = v2->m_curLine;
  v5 = (*((_BYTE *)v3 + 156) >> 4) & 1;
  if ( v5 )
    goto LABEL_8;
  while ( v4 > 0 )
  {
    v3 = (UFG::ConversationElement *)&v3->mPrev[-1].mNext;
    if ( v3 == (UFG::ConversationElement *)&v2->m_type )
      v3 = (UFG::ConversationElement *)&v3->mPrev[-1].mNext;
    --v4;
    v5 = (*((_BYTE *)v3 + 156) >> 4) & 1;
    if ( v5 )
      goto LABEL_8;
  }
  if ( v5 )
  {
LABEL_8:
    v2->m_curLine = v4;
    result = v3;
  }
  else
  {
    if ( v2->m_curLine < v2->m_numElements )
      v1 = v2->m_activeElement;
    result = v1;
  }
  return result;
}

// File Line: 820
// RVA: 0x59D0A0
UFG::ConversationElement *__fastcall UFG::Conversation::GetNextElement(UFG::Conversation *this)
{
  UFG::ConversationElement *result; // rax
  UFG::Conversation *v2; // rbx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v3; // rax
  UFG::qList<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement>,1,0> *v4; // rcx
  int i; // edx
  int v6; // ecx
  UFG::ConversationElement *v7; // rbx

  result = this->m_activeElement;
  v2 = this;
  if ( result )
  {
    if ( *((_BYTE *)this + 168) & 0x20 )
    {
      v3 = this->m_prevPlayed.mNode.mNext;
      v4 = &this->m_prevPlayed;
      for ( i = 0;
            v3 != (UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *)v4;
            ++i )
      {
        v3 = v3->mNext;
      }
      v6 = UFG::qRandom((unsigned int)v2->m_numElements - i, &UFG::qDefaultSeed);
      result = (UFG::ConversationElement *)&v2->m_lines.mNode.mNext[-1].mNext;
      if ( v6 >= 0 )
      {
        v7 = (UFG::ConversationElement *)&v2->m_type;
        do
        {
          result = (UFG::ConversationElement *)&result->mNext[-1].mNext;
          if ( result == v7 )
            result = (UFG::ConversationElement *)&result->mNext[-1].mNext;
          if ( !(*((_BYTE *)result + 156) & 4) )
            --v6;
        }
        while ( v6 >= 0 );
      }
    }
    else
    {
      ++this->m_curLine;
      result = (UFG::ConversationElement *)&result->mNext[-1].mNext;
      if ( result == (UFG::ConversationElement *)&this->m_type )
        result = (UFG::ConversationElement *)&result->mNext[-1].mNext;
    }
  }
  return result;
}

// File Line: 888
// RVA: 0x59CE30
UFG::ConversationElement *__fastcall UFG::Conversation::GetElement(UFG::Conversation *this, int idx)
{
  UFG::ConversationElement *result; // rax
  UFG::ConversationElement *v3; // rcx

  result = (UFG::ConversationElement *)&this->m_lines.mNode.mNext[-1].mNext;
  if ( idx > 0 )
  {
    v3 = (UFG::ConversationElement *)&this->m_type;
    do
    {
      if ( result == v3 )
        break;
      --idx;
      result = (UFG::ConversationElement *)&result->mNext[-1].mNext;
    }
    while ( idx > 0 );
  }
  return result;
}

// File Line: 914
// RVA: 0x5A4550
char __fastcall UFG::Conversation::OnLineFinished(UFG::Conversation *this)
{
  UFG::Conversation *v1; // rbx
  UFG::ConversationElement *v2; // rsi
  char *v3; // rdi
  char *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rdx
  UFG::allocator::free_link *v7; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v8; // rax
  signed int v9; // ecx
  UFG::Conversation *i; // rax
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v11; // r8
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v12; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v13; // rax
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v14; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *v15; // rax
  char v16; // di
  char result; // al
  __int64 v18; // [rsp+20h] [rbp-48h]
  UFG::qString v19; // [rsp+38h] [rbp-30h]

  v1 = this;
  if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    if ( this->m_curLine < this->m_numElements )
      v2 = this->m_activeElement;
    else
      v2 = 0i64;
    UFG::qString::qString(&v19, &this->m_activeElement->m_context);
    v3 = v19.mData;
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[1].vfptr[1].PlayLine);
    LODWORD(v18) = v1->m_curLine;
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : %s : line finished %u, %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v4,
      v18,
      v3,
      -2i64);
    UFG::qString::~qString(&v19);
  }
  if ( v1->m_type == eConversationType_Scripted )
    UFG::ScriptedConversationElement::ClearConversationTargets((UFG::ScriptedConversationElement *)v1->m_activeElement);
  *((_BYTE *)v1 + 168) &= 0xFEu;
  v5 = UFG::qMalloc(0x18ui64, "Conversation.ConversationElementPointerNode", 0i64);
  v6 = v5;
  if ( v5 )
  {
    v7 = (UFG::allocator::free_link *)v1->m_activeElement;
    v5->mNext = v5;
    v5[1].mNext = v5;
    v5[2].mNext = v7;
  }
  else
  {
    v6 = 0i64;
  }
  v8 = v1->m_prevPlayed.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *)v6;
  v6->mNext = (UFG::allocator::free_link *)v8;
  v6[1].mNext = (UFG::allocator::free_link *)&v1->m_prevPlayed;
  v1->m_prevPlayed.mNode.mPrev = (UFG::qNode<UFG::qPointerNode<UFG::ConversationElement>,UFG::qPointerNode<UFG::ConversationElement> > *)v6;
  *((_BYTE *)v1->m_activeElement + 156) |= 4u;
  v9 = 0;
  for ( i = (UFG::Conversation *)v1->m_prevPlayed.mNode.mNext;
        i != (UFG::Conversation *)&v1->m_prevPlayed;
        i = (UFG::Conversation *)i->mNode.mParent )
  {
    ++v9;
  }
  if ( v9 > v1->m_avoidRepeatingLastNLines )
  {
    v11 = v1->m_prevPlayed.mNode.mNext;
    v12 = v11->mPrev;
    v13 = v11->mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = v11;
    v11->mNext = v11;
    BYTE4(v11[1].mPrev[9].mNext) &= 0xFBu;
    v14 = v11->mPrev;
    v15 = v11->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v11->mPrev = v11;
    v11->mNext = v11;
    operator delete[](v11);
  }
  ((void (*)(void))v1->m_activeElement->vfptr->Reset)();
  if ( v1->m_state != 6 )
  {
    v16 = *((_BYTE *)v1->m_activeElement + 156);
    v1->m_activeElement = UFG::Conversation::GetNextElement(v1);
    if ( v16 & 1 )
      UFG::Conversation::Stop(v1, 1);
  }
  result = 1;
  if ( v1->m_curLine == v1->m_numElements )
  {
    v1->m_activeElement = 0i64;
    if ( v1->m_newState != 6 )
      v1->m_newState = 7;
  }
  return result;
}

// File Line: 982
// RVA: 0x59CA10
char __fastcall UFG::Conversation::ForceFinish(UFG::Conversation *this, _BOOL8 a2)
{
  UFG::Conversation *v2; // rbx
  char *v3; // rax

  v2 = this;
  if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Forcing Finish '%s'\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v3);
  }
  v2->m_newState = 7;
  UFG::Conversation::OnFinish(v2, a2);
  return 1;
}

// File Line: 1012
// RVA: 0x5A0660
char __fastcall UFG::Conversation::IsSpeaker(UFG::Conversation *this, UFG::SimObject *speaker)
{
  UFG::Conversation::eConversationType *v2; // r8
  UFG::SimObject *v3; // r9
  UFG::Conversation *v4; // rax
  UFG::qNode<UFG::qValueNode<UFG::qSymbol>,UFG::qValueNode<UFG::qSymbol> > *v5; // rcx
  UFG::SimObject *v6; // rdx

  v2 = &this->m_type;
  v3 = speaker;
  v4 = (UFG::Conversation *)&this->m_lines.mNode.mNext[-1].mNext;
  if ( v4 == (UFG::Conversation *)&this->m_type )
    return 0;
  while ( 1 )
  {
    v5 = v4->m_animationBanks.mNode.mPrev;
    v6 = (UFG::SimObject *)(v5 ? v5[2].mNext : 0i64);
    if ( v6 == v3 )
      break;
    v4 = (UFG::Conversation *)&v4->mNode.mChild[0][-1].mUID;
    if ( v4 == (UFG::Conversation *)v2 )
      return 0;
  }
  return 1;
}

// File Line: 1041
// RVA: 0x5AEFD0
bool __usercall UFG::Conversation::Update@<al>(UFG::Conversation *this@<rcx>, float delta_sec@<xmm1>, _BOOL8 a3@<rdx>)
{
  UFG::Conversation *v3; // rbx
  char *v4; // rax
  float v5; // xmm0_4
  bool result; // al

  v3 = this;
  if ( this->m_type == eConversationType_Scripted
    && this->m_newState != this->m_state
    && UFG::ConversationManager::sm_debugScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Updating state '%s' :: %s -> %s\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v4,
      UFG::ConversationStateNames[v3->m_state],
      UFG::ConversationStateNames[v3->m_newState]);
  }
  v5 = delta_sec + v3->m_timeAlive;
  v3->m_timeAlive = v5;
  if ( v5 >= 120.0 && v3->m_type == 1 )
    UFG::Conversation::ForceFinish(v3, a3);
  if ( v3->m_newState == 1 )
  {
    UFG::Conversation::UpdatePlayState(v3, delta_sec);
    return 1;
  }
  if ( v3->m_newState == 3 )
  {
    if ( v3->m_state != 3 )
      UFG::Conversation::OnInterrupt(v3);
    UFG::Conversation::UpdateInterruptState(v3, delta_sec);
    result = 1;
  }
  else
  {
    if ( v3->m_newState != 5 )
    {
      if ( v3->m_newState == 6 )
      {
        if ( v3->m_state != 6 )
        {
          UFG::Conversation::OnStop(v3, a3);
          return 1;
        }
      }
      else if ( v3->m_newState == 7 && v3->m_state != 7 )
      {
        UFG::Conversation::OnFinish(v3, a3);
        return 1;
      }
      return 1;
    }
    if ( v3->m_state != 5 )
      UFG::Conversation::OnResume(v3);
    UFG::Conversation::UpdateResumeState(v3, delta_sec);
    result = 1;
  }
  return result;
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
    if ( (signed __int64)v2 >= (signed __int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_MEATWRAPPED )
      return 25i64;
  }
  return v1;
}

// File Line: 1260
// RVA: 0x5A0400
bool __fastcall UFG::Conversation::IsFurtherThanMaxSeparationDistance(UFG::Conversation *this, UFG::ConversationElement *element)
{
  UFG::Conversation *v2; // rbx
  UFG::ActorAudioComponent *v3; // rcx
  UFG::ActorAudioComponent *v4; // rdx
  float v5; // xmm6_4

  v2 = this;
  if ( !element )
    return 0;
  v3 = (UFG::ActorAudioComponent *)element->m_spkAac.m_pPointer;
  v4 = (UFG::ActorAudioComponent *)element->m_tgtAac.m_pPointer;
  if ( !v3 || !v4 )
    return 0;
  v5 = v2->m_maxSeparationDistance;
  return UFG::ActorAudioComponent::Distance2ToActor(v3, v4) >= (float)(v5 * v5) && !(*((_BYTE *)v2 + 168) & 8);
}

// File Line: 1297
// RVA: 0x59CEF0
signed __int64 __fastcall UFG::Conversation::GetGroupCount(UFG::Conversation *this)
{
  unsigned int v1; // edx
  UFG::Conversation *v2; // r11
  unsigned int v3; // er10
  unsigned int v4; // er9
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v5; // rbx
  signed int v6; // eax
  signed __int64 i; // rcx

  v1 = 0;
  v2 = this;
  v3 = this->m_numElements - 1;
  if ( this->m_numElements == 1 )
    return 0i64;
  v4 = 1;
  if ( this->m_numElements == 1 )
    return 1i64;
  v5 = this->m_lines.mNode.mNext;
  do
  {
    v6 = v1;
    for ( i = (signed __int64)&v5[-1].mNext; v6 > 0; i = *(_QWORD *)(i + 16) - 8i64 )
    {
      if ( (UFG::Conversation::eConversationType *)i == &v2->m_type )
        break;
      --v6;
    }
    if ( *(_BYTE *)(i + 156) & 1 )
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
  UFG::Conversation::eConversationType *v2; // rsi
  UFG::Conversation *v3; // rdi
  char *v4; // rax
  char v5; // cl
  UFG::ConversationElement *v6; // rbx
  _BOOL8 v8; // rdx

  v2 = &this->m_type;
  v3 = this;
  if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Processing stop '%s'\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v4);
  }
  v5 = *((_BYTE *)v3 + 168);
  v3->m_state = 6;
  if ( !(v5 & 0x10) || v5 & 0x20 )
  {
    if ( v3->m_curLine < v3->m_numElements )
      v6 = v3->m_activeElement;
    else
      v6 = 0i64;
  }
  else
  {
    v6 = v3->m_activeElement;
    if ( v6 )
    {
      v6 = (UFG::ConversationElement *)&v6->mPrev[-1].mNext;
      if ( v6 == (UFG::ConversationElement *)v2 )
        v6 = (UFG::ConversationElement *)&v6->mPrev[-1].mNext;
      if ( v6 == (UFG::ConversationElement *)&v3->m_lines.mNode.mPrev[-1].mNext )
        v6 = (UFG::ConversationElement *)&v3->m_lines.mNode.mNext[-1].mNext;
    }
  }
  *((_BYTE *)v3 + 168) = v5 & 0xEF;
  if ( !v6
    || !((unsigned __int8 (__fastcall *)(UFG::ConversationElement *, _BOOL8))v6->vfptr->SpeakerInitialized)(v6, a2) )
  {
    return UFG::Conversation::ForceFinish(v3, a2);
  }
  v6->vfptr->Reset(v6);
  LOBYTE(v8) = 1;
  v6->vfptr->StopLine(v6, v8);
  UFG::ConversationElement::ClearSpeechFlags(v6);
  return 1;
}

// File Line: 1382
// RVA: 0x5A4280
char __fastcall UFG::Conversation::OnFinish(UFG::Conversation *this, _BOOL8 a2)
{
  UFG::Conversation::eConversationType *v2; // rsi
  UFG::Conversation *v3; // rdi
  char *v4; // rax
  UFG::Conversation *v5; // rcx
  UFG::Conversation *v6; // rcx
  unsigned __int16 v7; // ax
  UFG::ConversationElement *v8; // rcx
  UFG::ConversationElement *i; // rbx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **v10; // rbx

  v2 = &this->m_type;
  v3 = this;
  if ( this->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[1].vfptr[4].PrintDebugInfo);
    UFG::qPrintf(
      "CONV DEBUG: %s : %6u : Finish state processed '%s'\n",
      UFG::TidoGame::sm_timeStampStr.mData,
      UFG::Metrics::msInstance.mSimFrameCount,
      v4);
  }
  v5 = v3->m_onResume;
  if ( v5 )
    UFG::Conversation::ForceFinish(v5, a2);
  v6 = v3->m_onInterrupt;
  if ( v6 )
    UFG::Conversation::ForceFinish(v6, a2);
  v7 = v3->m_numElements;
  v3->m_state = 7;
  if ( v3->m_curLine < v7 )
  {
    v8 = v3->m_activeElement;
    if ( v8 )
    {
      LOBYTE(a2) = 1;
      v8->vfptr->StopLine(v8, a2);
    }
  }
  for ( i = (UFG::ConversationElement *)&v3->m_lines.mNode.mNext[-1].mNext;
        i != (UFG::ConversationElement *)v2;
        i = (UFG::ConversationElement *)&i->mNext[-1].mNext )
  {
    UFG::ConversationElement::ClearSpeechFlags(i);
  }
  v10 = &v3->m_lines.mNode.mNext[-1].mNext;
  v3->m_curLine = 0;
  for ( v3->m_activeElement = 0i64;
        v10 != (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)v2;
        v10 = &v10[2][-1].mNext )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **, _BOOL8))(*v10)->mNext)(
      v10,
      a2);
  }
  return 1;
}

// File Line: 1422
// RVA: 0x5AA9D0
void __fastcall UFG::Conversation::SetContainsActionRequests(UFG::Conversation *this)
{
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *i; // rdx
  signed __int64 v2; // rdx
  signed __int64 v3; // rax

  for ( i = this->m_lines.mNode.mNext; ; i = *(UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)(v2 + 16) )
  {
    v2 = (signed __int64)&i[-1].mNext;
    if ( (UFG::Conversation::eConversationType *)v2 == &this->m_type )
      break;
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 144) - 8i64;
      if ( v3 != v2 + 128 )
      {
        while ( !v3 || *(_DWORD *)(v3 + 24) != 2 )
        {
          v3 = *(_QWORD *)(v3 + 16) - 8i64;
          if ( v3 == v2 + 128 )
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
bool __fastcall UFG::Conversation::InterruptIsInvalid(UFG::Conversation *this, UFG::eInterruptType intType)
{
  UFG::Conversation *v2; // r9
  bool v3; // r10
  bool v4; // r11
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v5; // r8
  UFG::Conversation::eConversationType *v6; // rcx
  signed __int64 v7; // r8
  char v8; // cl
  char v9; // al

  v2 = this;
  v3 = this->m_numInterrupts >= UFG::ConversationManager::sm_maxNumInterrupts;
  v4 = this->m_state != 1;
  if ( intType != 3
    || (v5 = this->m_lines.mNode.mNext,
        v6 = &this->m_type,
        v7 = (signed __int64)&v5[-1].mNext,
        (UFG::Conversation::eConversationType *)v7 == v6) )
  {
LABEL_5:
    v8 = 0;
    if ( intType != 3 )
      return *((_BYTE *)v2 + 169) & 4 || v4 || v3;
  }
  else
  {
    while ( *(_DWORD *)(v7 + 24) != qwsPlayCellPhone.mUID )
    {
      v7 = *(_QWORD *)(v7 + 16) - 8i64;
      if ( (UFG::Conversation::eConversationType *)v7 == v6 )
        goto LABEL_5;
    }
    v8 = 1;
  }
  v9 = (*((_BYTE *)v2 + 169) >> 3) & 1;
  if ( v9 )
  {
    if ( !v8 )
      return 0;
LABEL_11:
    if ( !v9 )
      return 1;
    goto LABEL_12;
  }
  if ( intType == 3 )
    goto LABEL_11;
LABEL_12:
  if ( v8 )
    return 1;
  return *((_BYTE *)v2 + 169) & 4 || v4 || v3;
}

// File Line: 1479
// RVA: 0x5A0070
char __fastcall UFG::Conversation::Interrupt(UFG::Conversation *this, UFG::eInterruptType intType, bool force)
{
  bool v3; // bp
  UFG::eInterruptType v4; // esi
  UFG::Conversation *v5; // rbx
  UFG::ConversationElement *v7; // rdi
  UFG::SimComponent *v8; // rax
  UFG::ConversationElement *v9; // rcx

  v3 = force;
  v4 = intType;
  v5 = this;
  if ( UFG::Conversation::InterruptIsInvalid(this, intType) )
    return 0;
  if ( v5->m_curLine >= v5->m_numElements )
    return 0;
  v7 = v5->m_activeElement;
  if ( !v7 )
    return 0;
  v8 = v7->m_spkAac.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v5->m_activeElement;
  *((_BYTE *)v5 + 169) ^= (*((_BYTE *)v5 + 169) ^ (BYTE1(v8[8].m_pSimObject) >> 3)) & 1;
  v7->vfptr->StopLine(v9, v3);
  v7->vfptr->Reset(v7);
  ++v5->m_numInterrupts;
  v5->m_newState = 3;
  v5->m_interruptType = v4;
  v5->m_interruptedTime = 0.0;
  return 1;
}

// File Line: 1516
// RVA: 0x5B0BD0
char __usercall UFG::Conversation::UpdatePlayState@<al>(UFG::Conversation *this@<rcx>, float delta_sec@<xmm1>, _BOOL8 a3@<rdx>)
{
  UFG::Conversation *v3; // rbp
  UFG::ConversationElement *v4; // rsi
  UFG::SimComponent *v5; // rax
  SSInstance *v6; // rcx
  UFG::qBaseNodeRB *v7; // rax
  UFG::SimComponent *v8; // rax
  SSInstance *v9; // rcx
  UFG::qBaseNodeRB *v10; // rax
  hkgpIndexedMeshDefinitions::Edge *v11; // rdx
  UFG::SimComponent *v13; // rax
  hkgpIndexedMesh::EdgeBarrier *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  hkgpIndexedMesh::EdgeBarrierVtbl *v16; // rax
  float v17; // xmm6_4
  UFG::SimComponent *v18; // rax
  UFG::SimComponent *v19; // rax
  float v20; // xmm6_4
  UFG::ConversationElement *v21; // rdx
  UFG::ConversationElement *v22; // rdi
  char *v23; // rbx
  char *v24; // rax
  _BOOL8 v25; // rdx
  __int64 v26; // [rsp+20h] [rbp-68h]
  UFG::qString v27; // [rsp+38h] [rbp-50h]

  v3 = this;
  this->m_state = 1;
  if ( this->m_type == 1
    && *((_BYTE *)this + 169) & 2
    && UFG::AudioListener::sm_pInstance
    && UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled
    && UFG::AudioListener::sm_pInstance->m_highSpeedMode )
  {
    return UFG::Conversation::ForceFinish(this, a3);
  }
  if ( this->m_curLine >= this->m_numElements )
    return UFG::Conversation::ForceFinish(this, a3);
  v4 = this->m_activeElement;
  if ( !v4 )
    return UFG::Conversation::ForceFinish(this, a3);
  v5 = v4->m_spkAac.m_pPointer;
  if ( (!v5 || !v5->m_pSimObject) && v4->m_type == eConversationElementType_Scripted )
  {
    v6 = (SSInstance *)v4[1].mNext;
    if ( v6 )
    {
      v7 = UFG::TSScriptedDialogueElement::GetSimObjectFromSymbol(v6);
      if ( v7 )
      {
        UFG::ConversationElement::SetSpeaker(v4, (UFG::SimObject *)v7);
        v4[1].mNext = 0i64;
      }
    }
  }
  v8 = v4->m_tgtAac.m_pPointer;
  if ( (!v8 || !v8->m_pSimObject) && v4->m_type == eConversationElementType_Scripted )
  {
    v9 = *(SSInstance **)&v4[1].m_playbackEvent.mUID;
    if ( v9 )
    {
      v10 = UFG::TSScriptedDialogueElement::GetSimObjectFromSymbol(v9);
      if ( v10 )
      {
        UFG::ConversationElement::SetTarget(v4, (UFG::SimObject *)v10);
        *(_QWORD *)&v4[1].m_playbackEvent.mUID = 0i64;
      }
    }
  }
  if ( UFG::Conversation::IsFurtherThanMaxSeparationDistance(v3, v4) && v3->m_type == eConversationType_Scripted )
  {
    UFG::Conversation::Interrupt(v3, eInterruptType_Separation, 0);
    return 1;
  }
  v13 = v4->m_spkAac.m_pPointer;
  v14 = (hkgpIndexedMesh::EdgeBarrier *)v4->m_tgtAac.m_pPointer;
  if ( v13 )
  {
    v15 = v13[7].m_BoundComponentHandles.mNode.mPrev;
    if ( !v15 || !BYTE4(v15[7].mPrev) )
    {
      if ( !v14 || (v16 = v14[62].vfptr) == 0i64 || !BYTE4(v16[7].__vecDelDtor) )
      {
        if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v14, v11) )
        {
          v17 = delta_sec + v4->m_timeAlive;
          v4->m_timeAlive = v17;
          if ( v17 > 2.5 )
          {
LABEL_63:
            UFG::Conversation::OnLineFinished(v3);
            return 1;
          }
        }
        else
        {
          v18 = v4->m_spkAac.m_pPointer;
          if ( v18 )
            BYTE1(v18[8].m_pSimObject) &= 0xEFu;
          if ( !v4->vfptr->SpeakerInitialized(v4) )
          {
            v19 = v4->m_spkAac.m_pPointer;
            if ( v19 )
              BYTE1(v19[8].m_pSimObject) &= 0xEFu;
            v20 = delta_sec + v4->m_timeAlive;
            v4->m_timeAlive = v20;
            if ( v20 <= 3.0 )
              return 1;
            goto LABEL_63;
          }
          if ( !v4->vfptr->LineIsPlaying(v4) && v4->m_sampleLength < 0.02 )
          {
            UFG::ConversationElement::SetTagInterruptFlags(v4, (*((_BYTE *)v3 + 168) >> 2) & 1);
            UFG::ConversationElement::SetSpkListFlags(v4, (*((_BYTE *)v3 + 168) >> 6) & 1);
            if ( v3->m_type == 1 )
              UFG::ConversationElement::SetActiveAmbConv(v4, v3);
            if ( v3->m_type == eConversationType_Scripted )
              UFG::ConversationElement::SetDebugFlags(v4, UFG::ConversationManager::sm_debugScrConversations);
            if ( v4->m_preDelay <= v4->m_timeAlive )
            {
              *((_BYTE *)v3 + 168) |= 1u;
              if ( !v4->vfptr->PlayLine(
                      v4,
                      v3->m_externalSourcePlaybackEvent,
                      v3->m_linePriority,
                      *((_BYTE *)v3 + 168) >> 7)
                && v4->m_timeAlive > 3.0 )
              {
                UFG::Conversation::OnLineFinished(v3);
              }
              if ( v3->m_type == eConversationType_Scripted )
              {
                UFG::ScriptedConversationElement::SetConversationTargets((UFG::ScriptedConversationElement *)v4);
                if ( v3->m_type == eConversationType_Scripted && UFG::ConversationManager::sm_debugScrConversations )
                {
                  v21 = v3->m_activeElement;
                  if ( v21 )
                  {
                    v22 = v3->m_activeElement;
                    if ( v3->m_curLine >= v3->m_numElements )
                      v22 = 0i64;
                    UFG::qString::qString(&v27, &v21->m_context);
                    v23 = v27.mData;
                    v24 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v22[1].vfptr[1].PlayLine);
                    LODWORD(v26) = v3->m_curLine;
                    UFG::qPrintf(
                      "CONV DEBUG: %s : %6u : %s : line started %u, %s\n",
                      UFG::TidoGame::sm_timeStampStr.mData,
                      UFG::Metrics::msInstance.mSimFrameCount,
                      v24,
                      v26,
                      v23,
                      -2i64);
                    UFG::qString::~qString(&v27);
                  }
                }
              }
            }
            v4->m_timeAlive = delta_sec + v4->m_timeAlive;
            return 1;
          }
          if ( !v4->vfptr->LineIsPlaying(v4) || !(*((_BYTE *)v3 + 168) & 1) )
          {
            if ( v4->vfptr->LineIsPlaying(v4) || v4->m_sampleLength <= 0.02 )
              return 1;
            v4->m_timeAlive = delta_sec + v4->m_timeAlive;
            goto LABEL_63;
          }
          v4->m_timeAlive = delta_sec + v4->m_timeAlive;
          v4->m_sampleLength = delta_sec + v4->m_sampleLength;
          UFG::ConversationElement::UpdateInterruptionPoints(v4, v3);
        }
        return 1;
      }
    }
  }
  UFG::Conversation::Interrupt(v3, eInterruptType_Death, 0);
  UFG::Conversation::ForceFinish(v3, v25);
  return 1;
}

// File Line: 1733
// RVA: 0x599120
bool __fastcall UFG::Conversation::ConversantsInSameVehicle(UFG::Conversation *this)
{
  UFG::ConversationElement *v1; // rax
  UFG::Conversation *v2; // rbp
  UFG::SimComponent *v3; // rcx
  UFG::SimObjectGame *v4; // rcx
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectGame *v6; // rbx
  UFG::CharacterOccupantComponent *v7; // rdi
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::CharacterOccupantComponent *v10; // rbx
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  signed __int64 v13; // rcx
  UFG::VehicleOccupantComponent *v14; // rbx

  v1 = this->m_activeElement;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->m_spkAac.m_pPointer;
    if ( v3 )
      v4 = (UFG::SimObjectGame *)v3->m_pSimObject;
    else
      v4 = 0i64;
    v5 = v1->m_tgtAac.m_pPointer;
    if ( v5 )
      v6 = (UFG::SimObjectGame *)v5->m_pSimObject;
    else
      v6 = 0i64;
    if ( v4 )
    {
      v8 = v4->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v7 = (UFG::CharacterOccupantComponent *)v4->m_Components.p[44].m_pComponent;
      }
      else
      {
        if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID);
          }
          else
          {
            v9 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v4->vfptr,
                   UFG::CharacterOccupantComponent::_TypeUID);
          }
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID);
        }
        v7 = (UFG::CharacterOccupantComponent *)v9;
      }
    }
    else
    {
      v7 = 0i64;
    }
    if ( v6 )
    {
      v11 = v6->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v10 = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent;
      }
      else
      {
        if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID);
          }
          else if ( (v11 >> 12) & 1 )
          {
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID);
          }
          else
          {
            v12 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v6->vfptr,
                    UFG::CharacterOccupantComponent::_TypeUID);
          }
        }
        else
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID);
        }
        v10 = (UFG::CharacterOccupantComponent *)v12;
      }
    }
    else
    {
      v10 = 0i64;
    }
    v13 = (signed __int64)&v2->m_lines.mNode.mNext[-1].mNext;
    if ( (UFG::Conversation::eConversationType *)v13 == &v2->m_type )
    {
LABEL_35:
      if ( v7 && v10 )
      {
        UFG::CharacterOccupantComponent::GetCurrentVehicle(v7);
        v14 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v10);
        LOBYTE(v1) = UFG::CharacterOccupantComponent::GetCurrentVehicle(v7) == v14;
      }
      else
      {
        LOBYTE(v1) = 0;
      }
    }
    else
    {
      while ( *(_DWORD *)(v13 + 24) != qwsPlayCellPhone.mUID )
      {
        v13 = *(_QWORD *)(v13 + 16) - 8i64;
        if ( (UFG::Conversation::eConversationType *)v13 == &v2->m_type )
          goto LABEL_35;
      }
      LOBYTE(v1) = 1;
    }
  }
  return (char)v1;
}

// File Line: 1776
// RVA: 0x5935E0
void __fastcall UFG::ScriptedConversation::ScriptedConversation(UFG::ScriptedConversation *this, ASymbol *symbol, unsigned int uid)
{
  ASymbol *v3; // rbx
  UFG::ScriptedConversation *v4; // rdi

  v3 = symbol;
  v4 = this;
  UFG::Conversation::Conversation((UFG::Conversation *)&this->vfptr, uid, 0);
  v4->vfptr = (UFG::ConversationVtbl *)&UFG::ScriptedConversation::`vftable';
  v4->m_script = 0i64;
  *((_BYTE *)&v4->0 + 168) &= 0xFDu;
  UFG::ScriptedConversation::SetupScript(v4, v3);
}

// File Line: 1802
// RVA: 0x5AC310
void __fastcall UFG::ScriptedConversation::SetupScript(UFG::ScriptedConversation *this, ASymbol *symbol)
{
  ASymbol *v2; // rsi
  UFG::ScriptedConversation *v3; // rbx
  SSActorClass *v4; // rdi
  UFG::TSScriptedDialogue *v5; // rax

  v2 = symbol;
  v3 = this;
  v4 = (SSActorClass *)SSBrain::get_class("ScriptedDialogue");
  if ( v4 )
  {
    v5 = (UFG::TSScriptedDialogue *)AMemory::c_malloc_func(0x88ui64, "TSScriptedDialogue");
    if ( v5 )
      UFG::TSScriptedDialogue::TSScriptedDialogue(v5, v3, v2, v4);
    v3->m_script = v5;
    ++UFG::gNumScriptedConversations;
    ++v3->m_script->i_ref_count;
    SSInstance::call_default_constructor((SSInstance *)&v3->m_script->vfptr);
    SSActor::enable_behavior((SSActor *)&v3->m_script->vfptr, 1);
  }
}

// File Line: 1940
// RVA: 0x592B50
void __fastcall UFG::AmbientConversation::AmbientConversation(UFG::AmbientConversation *this, unsigned int uid)
{
  UFG::AmbientConversation *v2; // rbx

  v2 = this;
  UFG::Conversation::Conversation((UFG::Conversation *)&this->vfptr, uid, eConversationType_Ambient);
  v2->vfptr = (UFG::ConversationVtbl *)&UFG::AmbientConversation::`vftable';
  *((_BYTE *)&v2->0 + 168) |= 4u;
  v2->m_linePriority = 5;
}

// File Line: 1966
// RVA: 0x5AC2A0
void __fastcall UFG::AmbientConversation::SetupLines(UFG::AmbientConversation *this, UFG::SimObject *person1, UFG::SimObject *person2)
{
  UFG::SimObject *v3; // rsi
  UFG::AmbientConversation *v4; // rbx
  UFG::SimObject *v5; // rdi

  v3 = person1;
  v4 = this;
  v5 = person2;
  if ( UFG::AmbientConversationConfigurator::Start(this->m_topic, (UFG::Conversation *)&this->vfptr) )
  {
    UFG::AmbientConversationConfigurator::SetupConversation((UFG::Conversation *)&v4->vfptr, v3, v5);
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
  return atexit(dynamic_atexit_destructor_for__UFG::AmbientConversationConfigurator::sm_models__);
}

// File Line: 2001
// RVA: 0x5A0960
void __fastcall UFG::AmbientConversationConfigurator::LoadDefinitionFile(float a1)
{
  SimpleXML::XMLDocument *v1; // rax
  SimpleXML::XMLDocument *v2; // rsi
  SimpleXML::XMLNode *v3; // rax
  SimpleXML::XMLNode *v4; // r13
  char *v5; // rdi
  char v6; // si
  char v7; // bp
  __int16 v8; // r14
  char v9; // r15
  char *v10; // r12
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  UFG::allocator::free_link *v13; // r8
  UFG::allocator::free_link *v14; // rdx
  UFG::allocator::free_link *v15; // rcx
  UFG::allocator::free_link *v16; // rax
  signed int v17; // edx
  UFG::qStaticSymbol *v18; // rcx
  UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *v19; // rax
  SimpleXML::XMLNode *v20; // r12
  __int16 v21; // bx
  __int16 v22; // di
  __int16 v23; // si
  __int16 v24; // bp
  char v25; // r14
  char v26; // r15
  UFG::allocator::free_link *v27; // rax
  __int64 v28; // r13
  UFG::allocator::free_link *v29; // ST38_8
  signed __int64 k; // rax
  _QWORD *v31; // rdx
  __int64 v32; // rcx
  _QWORD *v33; // rax
  __int64 *v34; // rax
  SimpleXML::XMLNode *v35; // r12
  char *v36; // rbx
  char *v37; // rbx
  unsigned int v38; // edi
  UFG::AmbientConversationConfigurator::Context *v39; // rax
  UFG::AmbientConversationConfigurator::Context *v40; // r13
  SimpleXML::XMLNode *v41; // rbp
  UFG::qList<UFG::AmbientConversationConfigurator::Action,UFG::AmbientConversationConfigurator::Action,1,0> *v42; // r15
  char *v43; // r14
  char v44; // di
  UFG::allocator::free_link *v45; // rax
  UFG::allocator::free_link *v46; // rbx
  UFG::allocator::free_link *v47; // rcx
  char *v48; // rax
  char *v49; // rax
  signed int v50; // esi
  signed __int64 v51; // rdi
  UFG::allocator::free_link *v52; // rcx
  UFG::allocator::free_link *v53; // rax
  __int64 v54; // rcx
  __int64 *v55; // rdx
  UFG::allocator::free_link *v56; // rax
  UFG::AmbientConversationConfigurator::Context *v57; // [rsp+30h] [rbp-B8h]
  SimpleXML::XMLNode *l; // [rsp+38h] [rbp-B0h]
  SimpleXML::XMLNode *prev_node; // [rsp+40h] [rbp-A8h]
  SimpleXML::XMLNode *j; // [rsp+48h] [rbp-A0h]
  SimpleXML::XMLNode *i; // [rsp+50h] [rbp-98h]
  signed __int64 v62; // [rsp+58h] [rbp-90h]
  void *action_request; // [rsp+F0h] [rbp+8h]
  UFG::qSymbol result; // [rsp+F8h] [rbp+10h]
  SimpleXML::XMLDocument *v65; // [rsp+100h] [rbp+18h]
  UFG::allocator::free_link *v66; // [rsp+108h] [rbp+20h]

  v1 = SimpleXML::XMLDocument::Open("Data\\Audio\\AmbientConversationConfig.xml", 1ui64, 0i64);
  v2 = v1;
  v65 = v1;
  if ( v1 )
  {
    v3 = SimpleXML::XMLDocument::GetNode(v1, 0i64, 0i64);
    for ( i = v3; v3; i = v3 )
    {
      v4 = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, v3);
      for ( j = v4; v4; j = v4 )
      {
        v5 = SimpleXML::XMLNode::GetAttribute(v4, "topic", &customWorldMapCaption);
        v6 = SimpleXML::XMLNode::GetAttribute(v4, "minLines", 0);
        v7 = SimpleXML::XMLNode::GetAttribute(v4, "maxLines", 0);
        v8 = SimpleXML::XMLNode::GetAttribute(v4, "numSpeakers", 0);
        SimpleXML::XMLNode::GetAttribute(v4, "minTimeBetweenLines", 1.0);
        SimpleXML::XMLNode::GetAttribute(v4, "maxTimeBetweenLines", 1.0);
        v9 = SimpleXML::XMLNode::GetAttribute(v4, "showSubtitles", 0);
        v10 = SimpleXML::XMLNode::GetAttribute(v4, "event", &customWorldMapCaption);
        v11 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x38ui64, "ConversationModel", 0i64, 1u);
        v12 = v11;
        action_request = v11;
        if ( v11 )
        {
          v11->mNext = v11;
          v11[1].mNext = v11;
          v11[2].mNext = 0i64;
          v11[3].mNext = 0i64;
          LODWORD(v11[4].mNext) = 0;
          BYTE4(v11[4].mNext) = 0;
          v13 = v11 + 5;
          v66 = v13;
          v13->mNext = v13;
          v13[1].mNext = v13;
          v14 = v11[6].mNext;
          if ( v14 != &v11[5] )
          {
            do
            {
              v15 = v14->mNext;
              v16 = v14[1].mNext;
              v15[1].mNext = v16;
              v16->mNext = v15;
              v14->mNext = v14;
              v14[1].mNext = v14;
              v14 = v12[6].mNext;
            }
            while ( v14 != v13 );
          }
        }
        else
        {
          v12 = 0i64;
        }
        LOBYTE(v12[3].mNext) = v6;
        BYTE1(v12[3].mNext) = v7;
        WORD1(v12[3].mNext) = v8;
        *((float *)&v12[3].mNext + 1) = a1;
        *(float *)&v12[4].mNext = a1;
        BYTE4(v12[4].mNext) = v9;
        UFG::qSymbol::create_from_string(&result, v5);
        v17 = 0;
        v18 = UFG::ConversationTopicEnumSymbols;
        while ( result.mUID != v18->mUID )
        {
          ++v17;
          ++v18;
          if ( (signed __int64)v18 >= (signed __int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_MEATWRAPPED )
          {
            v17 = 25;
            break;
          }
        }
        LODWORD(v12[2].mNext) = v17;
        if ( (signed int)UFG::qStringLength(v10) > 0 )
          HIDWORD(v12[2].mNext) = UFG::TiDo::CalcWwiseUid(v10);
        v19 = UFG::AmbientConversationConfigurator::sm_models.mNode.mPrev;
        UFG::AmbientConversationConfigurator::sm_models.mNode.mPrev->mNext = (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)v12;
        v12->mNext = (UFG::allocator::free_link *)v19;
        v12[1].mNext = (UFG::allocator::free_link *)&UFG::AmbientConversationConfigurator::sm_models;
        UFG::AmbientConversationConfigurator::sm_models.mNode.mPrev = (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)v12;
        v2 = v65;
        v20 = SimpleXML::XMLDocument::GetChildNode(v65, 0i64, v4);
        prev_node = v20;
        if ( v20 )
        {
          v62 = (signed __int64)&v12[5];
          do
          {
            SimpleXML::XMLNode::GetName(v20);
            v21 = SimpleXML::XMLNode::GetAttribute(v20, "groupId", 0);
            v22 = SimpleXML::XMLNode::GetAttribute(v20, "precedingGroupId", 0);
            v23 = SimpleXML::XMLNode::GetAttribute(v20, "speaker", 0);
            v24 = SimpleXML::XMLNode::GetAttribute(v20, "maxLinesFromGroup", 0);
            v25 = SimpleXML::XMLNode::GetAttribute(v20, "terminalNode", 0);
            v26 = SimpleXML::XMLNode::GetAttribute(v20, "startNode", 0);
            v27 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "ConversationModel.LineGroup", 0i64, 1u);
            v28 = (__int64)v27;
            v66 = v27;
            action_request = v27;
            if ( v27 )
            {
              v27->mNext = v27;
              v27[1].mNext = v27;
              LODWORD(v27[2].mNext) = 0;
              WORD2(v27[2].mNext) = -1;
              HIWORD(v27[2].mNext) = 0;
              LOBYTE(v27[3].mNext) = 0;
              v29 = v27 + 4;
              v29->mNext = v29;
              v29[1].mNext = v29;
              for ( k = (signed __int64)&v27[5].mNext[-1]; k != v28 + 24; k = *(_QWORD *)(v28 + 40) - 8i64 )
              {
                v31 = (_QWORD *)(k + 8);
                v32 = *(_QWORD *)(k + 8);
                v33 = *(_QWORD **)(k + 16);
                *(_QWORD *)(v32 + 8) = v33;
                *v33 = v32;
                *v31 = v31;
                v31[1] = v31;
              }
            }
            else
            {
              v28 = 0i64;
              v66 = 0i64;
            }
            *(_WORD *)(v28 + 16) = v21;
            *(_WORD *)(v28 + 22) = v22;
            *(_WORD *)(v28 + 18) = v23;
            *(_WORD *)(v28 + 20) = v24;
            *(_BYTE *)(v28 + 24) = v25;
            *(_BYTE *)(v28 + 25) = v26;
            v34 = *(__int64 **)(v62 + 8);
            *(_QWORD *)(v62 + 8) = v28;
            *(_QWORD *)v28 = v62;
            *(_QWORD *)(v28 + 8) = v34;
            *v34 = v28;
            v2 = v65;
            v35 = SimpleXML::XMLDocument::GetChildNode(v65, 0i64, v20);
            for ( l = v35; v35; l = v35 )
            {
              v36 = SimpleXML::XMLNode::GetName(v35);
              if ( (unsigned int)UFG::qStringCompare(v36, "Context", -1) )
              {
                if ( !(unsigned int)UFG::qStringCompare(v36, "PrecedingGroup", -1) )
                  *(_WORD *)(v28 + 22) |= 1 << SimpleXML::XMLNode::GetAttribute(v35, "id", 0);
              }
              else
              {
                v37 = SimpleXML::XMLNode::GetAttribute(v35, "name", &customWorldMapCaption);
                v38 = SimpleXML::XMLNode::GetAttribute(v35, "weight", 0);
                v39 = (UFG::AmbientConversationConfigurator::Context *)UFG::qMemoryPool::Allocate(
                                                                         &g_AudioComponentPool,
                                                                         0x58ui64,
                                                                         "ConversationModel.Context",
                                                                         0i64,
                                                                         1u);
                action_request = v39;
                if ( v39 )
                  UFG::AmbientConversationConfigurator::Context::Context(v39);
                v40 = v39;
                v57 = v39;
                UFG::qString::Set(&v39->m_contextStr, v37);
                v40->m_weight = v38;
                v41 = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, v35);
                if ( v41 )
                {
                  v42 = &v40->m_actions;
                  do
                  {
                    v43 = SimpleXML::XMLNode::GetAttribute(v41, "name", &customWorldMapCaption);
                    SimpleXML::XMLNode::GetAttribute(v41, "time", 0.0);
                    v44 = SimpleXML::XMLNode::GetAttribute(v41, "onListener", 0);
                    v45 = UFG::qMemoryPool::Allocate(
                            &g_AudioComponentPool,
                            0x28ui64,
                            "AmbientConversation.Action",
                            0i64,
                            1u);
                    v46 = v45;
                    action_request = v45;
                    if ( v45 )
                    {
                      v47 = v45 + 1;
                      v47->mNext = v47;
                      v47[1].mNext = v47;
                      v45->mNext = (UFG::allocator::free_link *)&UFG::AmbientConversationConfigurator::Action::`vftable';
                      *(UFG::allocator::free_link **)((char *)&v45[3].mNext + 4) = 0i64;
                      BYTE4(v45[4].mNext) = 0;
                    }
                    else
                    {
                      v46 = 0i64;
                    }
                    *((float *)&v46[3].mNext + 1) = a1;
                    BYTE4(v46[4].mNext) = v44;
                    v48 = SimpleXML::XMLNode::GetName(v41);
                    if ( (unsigned int)UFG::qStringCompare(v48, "Gesture", -1) )
                    {
                      v49 = SimpleXML::XMLNode::GetName(v41);
                      if ( !(unsigned int)UFG::qStringCompare(v49, "Emotion", -1) )
                      {
                        LODWORD(v46[3].mNext) = 0;
                        v50 = 0;
                        v51 = 0i64;
                        while ( (unsigned int)UFG::qStringCompareInsensitive(
                                                v43,
                                                *(const char **)(v51 + 5402706272i64),
                                                -1)
                             && (unsigned int)UFG::qStringCompareInsensitive(
                                                v43,
                                                *(const char **)(v51 + 5402833232i64),
                                                -1) )
                        {
                          ++v50;
                          v51 += 8i64;
                          if ( v51 >= 104 )
                          {
                            v50 = -1;
                            break;
                          }
                        }
                        LODWORD(v46[4].mNext) = v50;
                        v2 = v65;
                      }
                    }
                    else
                    {
                      LODWORD(v46[3].mNext) = 1;
                      LODWORD(action_request) = gActionRequest_Action.m_EnumValue;
                      Intention::GetActionRequest(v43, (unsigned int *)&action_request);
                      LODWORD(v46[4].mNext) = (_DWORD)action_request;
                    }
                    v52 = v46 + 1;
                    v53 = (UFG::allocator::free_link *)v42->mNode.mPrev;
                    v53[1].mNext = v46 + 1;
                    v52->mNext = v53;
                    v52[1].mNext = (UFG::allocator::free_link *)v42;
                    v42->mNode.mPrev = (UFG::qNode<UFG::AmbientConversationConfigurator::Action,UFG::AmbientConversationConfigurator::Action> *)&v46[1];
                    v41 = SimpleXML::XMLDocument::GetNode(v2, 0i64, v41);
                  }
                  while ( v41 );
                  v35 = l;
                  v40 = v57;
                }
                v54 = (__int64)&v66[4];
                v55 = (__int64 *)&v40->mPrev;
                v56 = v66[5].mNext;
                *(_QWORD *)(v54 + 8) = (char *)v40 + 8;
                *v55 = v54;
                v55[1] = (__int64)v56;
                v56->mNext = (UFG::allocator::free_link *)&v40->mPrev;
                v28 = (__int64)v66;
              }
              v35 = SimpleXML::XMLDocument::GetNode(v2, 0i64, v35);
            }
            v20 = SimpleXML::XMLDocument::GetNode(v2, 0i64, prev_node);
            prev_node = v20;
          }
          while ( v20 );
          v4 = j;
        }
        v4 = SimpleXML::XMLDocument::GetNode(v2, 0i64, v4);
      }
      v3 = SimpleXML::XMLDocument::GetNode(v2, 0i64, i);
    }
    SimpleXML::XMLDocument::~XMLDocument(v2);
    operator delete[](v2);
  }
}

// File Line: 2197
// RVA: 0x5AC5E0
char __fastcall UFG::AmbientConversationConfigurator::Start(UFG::eConversationTopic topic, UFG::Conversation *conv)
{
  UFG::Conversation *v2; // rbx
  int v3; // eax
  UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *v4; // r8
  int v5; // er9
  UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *v6; // rax
  int v7; // ecx
  char result; // al

  v2 = conv;
  v3 = UFG::AmbientConversationConfigurator::GetRandomTopic(topic);
  v4 = UFG::AmbientConversationConfigurator::sm_models.mNode.mNext;
  UFG::AmbientConversationConfigurator::sm_isBusy = 1;
  v5 = v3;
  UFG::AmbientConversationConfigurator::sm_curLine = 0;
  UFG::AmbientConversationConfigurator::sm_curConversation = v2;
  UFG::AmbientConversationConfigurator::sm_lastLineGroup = 0i64;
  if ( (UFG::qList<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel,1,0> *)UFG::AmbientConversationConfigurator::sm_models.mNode.mNext == &UFG::AmbientConversationConfigurator::sm_models )
  {
LABEL_7:
    UFG::AmbientConversationConfigurator::sm_isBusy = 0;
    UFG::AmbientConversationConfigurator::sm_curLine = 0;
    UFG::AmbientConversationConfigurator::sm_curModel = 0i64;
    UFG::AmbientConversationConfigurator::sm_lastLineGroup = 0i64;
    UFG::AmbientConversationConfigurator::sm_curConversation = 0i64;
    result = 0;
  }
  else
  {
    while ( 1 )
    {
      if ( LODWORD(v4[1].mPrev) == v5 )
      {
        v6 = v4[3].mPrev;
        v7 = 0;
        if ( v6 != (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)&v4[2].mNext )
        {
          do
          {
            v6 = v6->mNext;
            ++v7;
          }
          while ( v6 != (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)&v4[2].mNext );
          if ( v7 > 0 )
            break;
        }
      }
      v4 = v4->mNext;
      if ( v4 == (UFG::qNode<UFG::AmbientConversationConfigurator::ConversationModel,UFG::AmbientConversationConfigurator::ConversationModel> *)&UFG::AmbientConversationConfigurator::sm_models )
        goto LABEL_7;
    }
    UFG::AmbientConversationConfigurator::sm_curModel = (UFG::AmbientConversationConfigurator::ConversationModel *)v4;
    result = 1;
  }
  return result;
}

// File Line: 2225
// RVA: 0x59D400
signed __int64 __fastcall UFG::AmbientConversationConfigurator::GetRandomTopic(UFG::eConversationTopic inTopic)
{
  UFG::eConversationTopic v1; // ebx
  signed __int64 result; // rax
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
    v3 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    if ( v3 <= 0.25 )
    {
      v1 = 25;
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
void __fastcall UFG::AmbientConversationConfigurator::SetupConversation(UFG::Conversation *conv, UFG::SimObject *speaker1, UFG::SimObject *speaker2)
{
  UFG::SimObject *v3; // r13
  UFG::SimObject *v4; // r15
  UFG::Conversation *v5; // rbp
  unsigned __int8 v6; // si
  unsigned __int16 v7; // r12
  float v8; // xmm6_4
  float v9; // xmm7_4
  char v10; // r9
  char *v11; // rax
  char *v12; // rax
  UFG::ActorAudioComponent *v13; // r14
  unsigned __int16 v14; // cx
  UFG::ActorAudioComponent *v15; // rax
  unsigned int v16; // edx
  UFG::qBaseTreeRB *v17; // rax
  unsigned int v18; // edx
  UFG::qBaseTreeRB *v19; // rax
  signed __int64 v20; // rdi
  unsigned int v21; // ebx
  char *v22; // rax
  _BOOL8 v23; // rdx
  UFG::AudioEvent *v24; // rcx
  unsigned __int16 v25; // cx
  UFG::ActorAudioComponent *v26; // rax
  UFG::AudioEvent *v27; // rcx
  unsigned int v28; // ebx
  unsigned __int16 v29; // r14
  UFG::AmbientConversationConfigurator::Context *v30; // r12
  UFG::allocator::free_link *v31; // rax
  __int64 v32; // rax
  __int64 v33; // rdi
  __int16 v34; // ax
  UFG::SimObject *v35; // rdx
  __int64 v36; // rax
  int v37; // esi
  signed __int64 i; // rbx
  unsigned int v39; // er9
  float v40; // xmm2_4
  UFG::qWiseSymbol *v41; // rax
  char *v42; // rbx
  const char *v43; // rax
  char *v44; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **v45; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v46; // rax
  bool v47; // cf
  bool v48; // zf
  UFG::AudioEvent *v49; // rcx
  char check_null; // [rsp+20h] [rbp-B8h]
  unsigned int v51; // [rsp+30h] [rbp-A8h]
  UFG::ActorAudioComponent *v52; // [rsp+38h] [rbp-A0h]
  UFG::qString v53; // [rsp+50h] [rbp-88h]
  UFG::Conversation *v54; // [rsp+E0h] [rbp+8h]
  UFG::qWiseSymbol result; // [rsp+E8h] [rbp+10h]
  unsigned int v56; // [rsp+F8h] [rbp+20h]

  v54 = conv;
  v3 = speaker2;
  v4 = speaker1;
  v5 = conv;
  v6 = UFG::AmbientConversationConfigurator::sm_curModel->m_maxLines;
  v7 = UFG::AmbientConversationConfigurator::sm_curModel->m_numSpeakers;
  LOWORD(result.mUID) = UFG::AmbientConversationConfigurator::sm_curModel->m_numSpeakers;
  v8 = UFG::AmbientConversationConfigurator::sm_curModel->m_minTimeBetweenLines;
  v9 = UFG::AmbientConversationConfigurator::sm_curModel->m_maxTimeBetweenLines;
  v10 = UFG::AmbientConversationConfigurator::sm_curModel->m_showSubtitles;
  *((_BYTE *)conv + 168) &= 0x7Fu;
  *((_BYTE *)conv + 168) |= v10 << 7;
  conv->m_externalSourcePlaybackEvent = UFG::AmbientConversationConfigurator::sm_curModel->m_eventId;
  if ( UFG::ConversationManager::sm_debugAmbConversations )
  {
    v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&speaker1->m_Name);
    UFG::qPrintf("AmbConv:: Speaker1: %s \n", v11);
    if ( v3 )
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_Name);
      UFG::qPrintf("AmbConv:: Speaker2: %s \n", v12);
    }
  }
  if ( v4 )
  {
    v14 = v4->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>((UFG::SimObjectCharacter *)v4);
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)v4,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)v4,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v15 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(v4, UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v15 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)v4,
                                          UFG::ActorAudioComponent::_TypeUID);
    }
    v13 = v15;
  }
  else
  {
    v13 = 0i64;
  }
  v52 = v13;
  v16 = v13->m_activeAmbientConversationId;
  if ( v16 )
  {
    v17 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v16);
    if ( v17 )
    {
      if ( v17 != (UFG::qBaseTreeRB *)8 )
      {
        v18 = v13->m_activeAmbientConversationId;
        if ( v18 && (v19 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v18)) != 0i64 )
          v20 = (signed __int64)&v19[-1].mCount;
        else
          v20 = 0i64;
        v21 = *(_DWORD *)(v20 + 144);
        v22 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->m_Name);
        UFG::qPrintf("AmbConv:: Ambient ped in more than 1 ambient conversation: '%s' %u\n", v22, v21);
        UFG::Conversation::ForceFinish((UFG::Conversation *)v20, v23);
      }
    }
  }
  v13->m_activeAmbientConversationId = 0;
  v13->m_activeAmbientConversationId = v5->mNode.mUID;
  if ( v13->m_curPlayingPriority <= 5 )
  {
    if ( *((_BYTE *)v13 + 552) & 8 )
    {
      v24 = v13->m_controller.m_pEvent;
      if ( v24 )
        UFG::AudioEvent::StopAndForget(v24, 0x1F4u);
    }
  }
  if ( v7 == 2 )
  {
    if ( !v3 )
      goto LABEL_79;
    v25 = v3->m_Flags;
    if ( (v25 >> 14) & 1 )
    {
      v26 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>((UFG::SimObjectCharacter *)v3);
    }
    else if ( (v25 & 0x8000u) == 0 )
    {
      if ( (v25 >> 13) & 1 )
        v26 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)v3,
                                            UFG::ActorAudioComponent::_TypeUID);
      else
        v26 = (UFG::ActorAudioComponent *)((v25 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)v3,
                                                               UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(v3, UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v26 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)v3,
                                          UFG::ActorAudioComponent::_TypeUID);
    }
    if ( !v26 )
      goto LABEL_79;
    v26->m_activeAmbientConversationId = 0;
    v26->m_activeAmbientConversationId = v5->mNode.mUID;
    if ( v26->m_curPlayingPriority <= 5 )
    {
      if ( *((_BYTE *)v26 + 552) & 8 )
      {
        v27 = v26->m_controller.m_pEvent;
        if ( v27 )
          UFG::AudioEvent::StopAndForget(v27, 0x1F4u);
      }
    }
  }
  v28 = 0;
  v56 = 0;
  v51 = v6;
  if ( !v6 )
    goto LABEL_78;
  v29 = result.mUID;
  while ( !UFG::AmbientConversationConfigurator::sm_lastLineGroup
       || !UFG::AmbientConversationConfigurator::sm_lastLineGroup->m_terminalNode )
  {
    v30 = UFG::AmbientConversationConfigurator::GetNextLine();
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
      if ( v29 == 1 || (v34 = UFG::AmbientConversationConfigurator::sm_lastLineGroup->m_speakerId, v34 < 0) )
      {
        if ( v28 % v29 )
          goto LABEL_60;
        UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)v33, v4);
        v35 = v3;
LABEL_61:
        UFG::ConversationElement::SetTarget((UFG::ConversationElement *)v33, v35);
      }
      else
      {
        if ( v34 == 1 )
        {
          UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)v33, v4);
          v35 = v3;
          goto LABEL_61;
        }
        if ( v34 == 2 )
        {
LABEL_60:
          UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)v33, v3);
          v35 = v4;
          goto LABEL_61;
        }
      }
      v36 = *(_QWORD *)(v33 + 104);
      if ( v36 && *(_QWORD *)(v36 + 40) && v30->m_contextStr.mLength )
      {
        if ( v28 )
          *(float *)(v33 + 72) = UFG::qRandom(v9 - v8, &UFG::qDefaultSeed) + v8;
        v37 = 0;
        for ( i = (signed __int64)&v30->m_actions.mNode.mNext[-1].mNext;
              (unsigned int *)i != &v30->m_weight;
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
        UFG::qString::Set((UFG::qString *)(v33 + 32), v30->m_contextStr.mData, v30->m_contextStr.mLength, 0i64, 0);
        if ( UFG::ConversationManager::sm_debugAmbConversations )
        {
          v41 = UFG::ActorAudioComponent::GetVoiceId(*(UFG::ActorAudioComponent **)(v33 + 104), &result);
          v42 = v30->m_contextStr.mData;
          v43 = UFG::qWiseSymbol::as_cstr_dbg(v41);
          UFG::qString::qString(&v53, "%s.%s", v43, v42);
          _((AMD_HD3D *)result.mUID);
          v44 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(*(_QWORD *)(*(_QWORD *)(v33 + 104) + 40i64) + 72i64));
          UFG::qPrintf("AmbConv:: %s \t\t %s \n", v44, v53.mData);
          UFG::qString::~qString(&v53);
        }
        v5 = v54;
        v45 = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> **)(v33 + 8);
        v46 = v54->m_lines.mNode.mPrev;
        v46->mNext = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)(v33 + 8);
        *v45 = v46;
        v45[1] = &v54->m_lines.mNode;
        v54->m_lines.mNode.mPrev = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)(v33 + 8);
        ++v5->m_numElements;
        v28 = v56;
      }
      else
      {
        (**(void (__fastcall ***)(__int64, signed __int64))v33)(v33, 1i64);
      }
    }
    v56 = ++v28;
    if ( v28 >= v51 )
      break;
  }
  v13 = v52;
LABEL_78:
  if ( !v5->m_numElements )
  {
LABEL_79:
    v47 = v13->m_curPlayingPriority < 5;
    v48 = v13->m_curPlayingPriority == 5;
    v13->m_activeAmbientConversationId = 0;
    if ( (v47 || v48) && *((_BYTE *)v13 + 552) & 8 )
    {
      v49 = v13->m_controller.m_pEvent;
      if ( v49 )
        UFG::AudioEvent::StopAndForget(v49, 0x1F4u);
    }
  }
}

// File Line: 2441
// RVA: 0x59D150
UFG::AmbientConversationConfigurator::Context *__fastcall UFG::AmbientConversationConfigurator::GetNextLine()
{
  UFG::AmbientConversationConfigurator::LineGroup *v0; // rdi
  UFG::AmbientConversationConfigurator::ConversationModel *v1; // rcx
  UFG::AmbientConversationConfigurator::Context *result; // rax
  unsigned int v3; // edx
  bool v4; // r14
  bool v5; // si
  UFG::qNode<UFG::AmbientConversationConfigurator::LineGroup,UFG::AmbientConversationConfigurator::LineGroup> *v6; // rbx
  UFG::AmbientConversationConfigurator::LineGroup *i; // rdi
  int v8; // eax
  UFG::allocator::free_link *v9; // rax
  __int64 *v10; // rcx
  UFG::allocator::free_link *v11; // rax
  __int64 *v12; // rax
  int v13; // ecx
  __int64 *v14; // rax
  int v15; // eax
  __int64 *v16; // rcx
  UFG::AmbientConversationConfigurator::Context *v17; // rbx
  __int64 *j; // rcx
  __int64 v19; // rdx
  _QWORD *v20; // rax
  __int64 v21; // rdx
  _QWORD *v22; // rax
  __int64 *v23; // rcx
  _QWORD *v24; // rax
  __int64 *v25; // [rsp+28h] [rbp-18h]
  void *mem; // [rsp+30h] [rbp-10h]

  if ( !UFG::AmbientConversationConfigurator::sm_lastLineGroup )
  {
    v0 = 0i64;
    v1 = (UFG::AmbientConversationConfigurator::ConversationModel *)UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups.mNode.mNext;
    if ( v1 != (UFG::AmbientConversationConfigurator::ConversationModel *)&UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups )
    {
      while ( !v1->m_maxLines )
      {
        v1 = (UFG::AmbientConversationConfigurator::ConversationModel *)v1->mNext;
        if ( v1 == (UFG::AmbientConversationConfigurator::ConversationModel *)&UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups )
          goto LABEL_7;
      }
      v0 = (UFG::AmbientConversationConfigurator::LineGroup *)v1;
    }
LABEL_7:
    result = UFG::AmbientConversationConfigurator::LineGroup::ChooseContext(v0);
    UFG::AmbientConversationConfigurator::sm_lastLineGroup = v0;
    return result;
  }
  v3 = UFG::AmbientConversationConfigurator::sm_curConversation->m_numElements;
  v4 = v3 >= (unsigned int)(unsigned __int8)UFG::AmbientConversationConfigurator::sm_curModel->m_minLines - 1;
  v5 = v3 == (unsigned __int8)UFG::AmbientConversationConfigurator::sm_curModel->m_maxLines - 1;
  v25 = (__int64 *)&v25;
  mem = &v25;
  v6 = UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups.mNode.mNext;
  for ( i = 0i64;
        v6 != (UFG::qNode<UFG::AmbientConversationConfigurator::LineGroup,UFG::AmbientConversationConfigurator::LineGroup> *)&UFG::AmbientConversationConfigurator::sm_curModel->m_lineGroups;
        v6 = v6->mNext )
  {
    if ( v5
      || (v8 = HIWORD(v6[1].mPrev),
          !_bittest(&v8, LOBYTE(UFG::AmbientConversationConfigurator::sm_lastLineGroup->m_groupId))) )
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
LABEL_22:
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
      goto LABEL_22;
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
  v15 = UFG::qRandom(50 * v13, &UFG::qDefaultSeed);
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
        goto LABEL_31;
    }
    i = (UFG::AmbientConversationConfigurator::LineGroup *)v16[2];
  }
LABEL_31:
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
UFG::AmbientConversationConfigurator::Context *__fastcall UFG::AmbientConversationConfigurator::LineGroup::ChooseContext(UFG::AmbientConversationConfigurator::LineGroup *this)
{
  UFG::AmbientConversationConfigurator::LineGroup *v1; // rdi
  int v2; // ecx
  int v3; // edx
  signed __int64 v4; // rax
  UFG::AmbientConversationConfigurator::Context *result; // rax
  UFG::AmbientConversationConfigurator::Context *v6; // rbx
  signed __int64 v7; // rax
  int v8; // ecx

  v1 = this;
  v2 = 0;
  v3 = 0;
  v4 = (signed __int64)&v1->m_contexts.mNode.mNext[-1].mNext;
  if ( (bool *)v4 != &v1->m_terminalNode )
  {
    do
    {
      ++v3;
      v4 = *(_QWORD *)(v4 + 16) - 8i64;
    }
    while ( (bool *)v4 != &v1->m_terminalNode );
    if ( v3 == 1 )
      return (UFG::AmbientConversationConfigurator::Context *)&v1->m_contexts.mNode.mNext[-1].mNext;
  }
  v6 = (UFG::AmbientConversationConfigurator::Context *)&v1->m_terminalNode;
  v7 = (signed __int64)&v1->m_contexts.mNode.mNext[-1].mNext;
  if ( (bool *)v7 != &v1->m_terminalNode )
  {
    do
    {
      v2 += *(_DWORD *)(v7 + 24);
      v7 = *(_QWORD *)(v7 + 16) - 8i64;
    }
    while ( (UFG::AmbientConversationConfigurator::Context *)v7 != v6 );
  }
  v8 = UFG::qRandom(v2, &UFG::qDefaultSeed);
  result = (UFG::AmbientConversationConfigurator::Context *)&v1->m_contexts.mNode.mNext[-1].mNext;
  if ( result == v6 )
    return 0i64;
  while ( 1 )
  {
    v8 -= result->m_weight;
    if ( v8 <= 0 )
      break;
    result = (UFG::AmbientConversationConfigurator::Context *)&result->mNext[-1].mNext;
    if ( result == v6 )
      return 0i64;
  }
  return result;
}

// File Line: 2578
// RVA: 0x5AB170
void __fastcall UFG::ConversationElement::SetSpeaker(UFG::ConversationElement *this, UFG::SimObject *speaker)
{
  UFG::SimObjectCharacter *v2; // r8
  unsigned __int16 v3; // dx
  UFG::ConversationElement *v4; // rbx
  UFG::ActorAudioComponent *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v6; // rdx
  UFG::ActorAudioComponent *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  if ( speaker )
  {
    v2 = (UFG::SimObjectCharacter *)speaker;
    v3 = speaker->m_Flags;
    v4 = this;
    if ( (v3 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v6 = &v4->m_spkAac;
    v7 = v5;
    if ( v4->m_spkAac.m_pPointer )
    {
      v8 = v6->mPrev;
      v9 = v4->m_spkAac.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v4->m_spkAac.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->m_spkAac.mPrev;
    }
    v4->m_spkAac.m_pPointer = (UFG::SimComponent *)&v7->vfptr;
    if ( v7 )
    {
      v10 = v7->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mPrev = v10;
      v4->m_spkAac.mNext = &v7->m_SafePointerList.mNode;
      v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
  }
}

// File Line: 2586
// RVA: 0x5AB790
void __fastcall UFG::ConversationElement::SetTarget(UFG::ConversationElement *this, UFG::SimObject *target)
{
  UFG::SimObjectCharacter *v2; // r8
  unsigned __int16 v3; // dx
  UFG::ConversationElement *v4; // rbx
  UFG::ActorAudioComponent *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v6; // rdx
  UFG::ActorAudioComponent *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  if ( target )
  {
    v2 = (UFG::SimObjectCharacter *)target;
    v3 = target->m_Flags;
    v4 = this;
    if ( (v3 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v6 = &v4->m_tgtAac;
    v7 = v5;
    if ( v4->m_tgtAac.m_pPointer )
    {
      v8 = v6->mPrev;
      v9 = v4->m_tgtAac.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v4->m_tgtAac.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->m_tgtAac.mPrev;
    }
    v4->m_tgtAac.m_pPointer = (UFG::SimComponent *)&v7->vfptr;
    if ( v7 )
    {
      v10 = v7->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mPrev = v10;
      v4->m_tgtAac.mNext = &v7->m_SafePointerList.mNode;
      v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
  }
}

// File Line: 2598
// RVA: 0x5A35E0
void __fastcall UFG::ConversationElement::NullifyMembers(UFG::ConversationElement *this)
{
  UFG::ConversationElement *v1; // rbx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *i; // rdx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v3; // rax
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v4; // rcx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax

  *((_BYTE *)this + 156) &= 0xF7u;
  v1 = this;
  this->m_preDelay = 0.0;
  UFG::qWiseSymbol::set_null(&this->m_playbackEvent);
  for ( i = v1->m_interruptionPoints.mNode.mNext;
        &i[-1].mNext != (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> **)&v1->m_tgtAac.m_pPointer;
        i = v1->m_interruptionPoints.mNode.mNext )
  {
    v3 = i->mNext;
    v4 = i->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    i->mPrev = i;
    i->mNext = i;
  }
  *((_BYTE *)v1 + 156) &= 0xE8u;
  v1->m_interjectionPoint = -1.0;
  *(_QWORD *)&v1->m_timeAlive = 0i64;
  if ( UFG::ConversationManager::sm_debugAmbConversations )
  {
    v5 = v1->m_spkAac.m_pPointer;
    v6 = v1->m_tgtAac.m_pPointer;
    if ( v5 )
      BYTE1(v5[8].m_pSimObject) &= 0xFDu;
    if ( v6 )
      BYTE1(v6[8].m_pSimObject) &= 0xFDu;
  }
  v7 = &v1->m_spkAac;
  if ( v1->m_spkAac.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_spkAac.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_spkAac.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_spkAac.mPrev;
  }
  v1->m_spkAac.m_pPointer = 0i64;
  v10 = &v1->m_tgtAac;
  if ( v1->m_tgtAac.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->m_tgtAac.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->m_tgtAac.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_tgtAac.mPrev;
  }
  v1->m_tgtAac.m_pPointer = 0i64;
  UFG::qString::Set(&v1->m_context, &customWorldMapCaption);
}

// File Line: 2640
// RVA: 0x596270
void __fastcall UFG::ConversationElement::AddInterruptPoint(UFG::ConversationElement *this, int id, float point)
{
  int v3; // edi
  UFG::ConversationElement *v4; // rbx
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rcx
  UFG::allocator::free_link *v7; // rcx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v8; // rax

  v3 = id;
  v4 = this;
  v5 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x28ui64, "ConversationElement.ElementInterruption", 0i64, 1u);
  if ( v5 )
  {
    v6 = v5 + 1;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v5->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementInterruption::`vftable';
    LODWORD(v5[3].mNext) = 0;
    HIDWORD(v5[3].mNext) = v3;
    *(float *)&v5[4].mNext = point;
    BYTE4(v5[4].mNext) &= 0xFEu;
  }
  v7 = v5 + 1;
  v8 = v4->m_interruptionPoints.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)v7;
  v7->mNext = (UFG::allocator::free_link *)v8;
  v7[1].mNext = (UFG::allocator::free_link *)&v4->m_interruptionPoints;
  v4->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)v7;
}

// File Line: 2649
// RVA: 0x596130
UFG::allocator::free_link *__fastcall UFG::ConversationElement::AddEmotionRequest(UFG::ConversationElement *this, int id, float point, const char *emotion, bool onListener)
{
  const char *v5; // rsi
  int v6; // ebp
  UFG::ConversationElement *v7; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  _QWORD *v11; // rdx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v12; // rcx

  v5 = emotion;
  v6 = id;
  v7 = this;
  v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "ConversationElement.ElementEmotionScr", 0i64, 1u);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8 + 1;
    v10->mNext = v10;
    v10[1].mNext = v10;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementInterruption::`vftable';
    LODWORD(v9[3].mNext) = 1;
    HIDWORD(v9[3].mNext) = v6;
    *(float *)&v9[4].mNext = point;
    BYTE4(v9[4].mNext) &= 0xFEu;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementEmotionRequest::`vftable';
    BYTE4(v9[5].mNext) = onListener;
    LODWORD(v9[5].mNext) = UFG::ConversationElementEmotionRequest::LookupEmotion(v5);
  }
  else
  {
    v9 = 0i64;
  }
  v11 = &v9[1].mNext;
  v12 = v7->m_interruptionPoints.mNode.mPrev;
  v12->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  *v11 = v12;
  v11[1] = (char *)v7 + 136;
  v7->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  return v9;
}

// File Line: 2659
// RVA: 0x596050
UFG::allocator::free_link *__fastcall UFG::ConversationElement::AddEmotionRequest(UFG::ConversationElement *this, int id, float point, unsigned int emotion_id, bool onListener)
{
  unsigned int v5; // edi
  int v6; // esi
  UFG::ConversationElement *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r10
  UFG::allocator::free_link *v10; // rax
  _QWORD *v11; // rdx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v12; // rcx

  v5 = emotion_id;
  v6 = id;
  v7 = this;
  v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "ConversationElement.ElementEmotionAmb", 0i64, 1u);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8 + 1;
    v10->mNext = v10;
    v10[1].mNext = v10;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementInterruption::`vftable';
    LODWORD(v9[3].mNext) = 1;
    HIDWORD(v9[3].mNext) = v6;
    *(float *)&v9[4].mNext = point;
    BYTE4(v9[4].mNext) &= 0xFEu;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementEmotionRequest::`vftable';
    BYTE4(v9[5].mNext) = onListener;
    LODWORD(v9[5].mNext) = v5;
  }
  else
  {
    v9 = 0i64;
  }
  v11 = &v9[1].mNext;
  v12 = v7->m_interruptionPoints.mNode.mPrev;
  v12->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  *v11 = v12;
  v11[1] = (char *)v7 + 136;
  v7->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  return v9;
}

// File Line: 2670
// RVA: 0x595E10
UFG::ConversationElementActionRequest *__fastcall UFG::ConversationElement::AddActionRequest(UFG::ConversationElement *this, int id, float point, const char *action_request_name, bool onListner)
{
  const char *v5; // rdi
  int v6; // esi
  UFG::ConversationElement *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> **v11; // rcx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v12; // rax

  v5 = action_request_name;
  v6 = id;
  v7 = this;
  v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "ConversationElement.ActionRequest", 0i64, 1u);
  if ( v8 )
  {
    UFG::ConversationElementActionRequest::ConversationElementActionRequest(
      (UFG::ConversationElementActionRequest *)v8,
      v6,
      point,
      v5,
      onListner);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> **)(v10 + 8);
  v12 = v7->m_interruptionPoints.mNode.mPrev;
  v12->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)(v10 + 8);
  *v11 = v12;
  v11[1] = &v7->m_interruptionPoints.mNode;
  v7->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)(v10 + 8);
  return (UFG::ConversationElementActionRequest *)v10;
}

// File Line: 2680
// RVA: 0x595D20
UFG::allocator::free_link *__fastcall UFG::ConversationElement::AddActionRequest(UFG::ConversationElement *this, int id, float point, unsigned int action_request_id, bool onListner)
{
  unsigned int v5; // edi
  int v6; // esi
  UFG::ConversationElement *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r10
  UFG::allocator::free_link *v10; // rax
  _QWORD *v11; // rdx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v12; // rcx

  v5 = action_request_id;
  v6 = id;
  v7 = this;
  v8 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "ConversationElement.ActionRequest", 0i64, 1u);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8 + 1;
    v10->mNext = v10;
    v10[1].mNext = v10;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementInterruption::`vftable';
    LODWORD(v9[3].mNext) = 2;
    HIDWORD(v9[3].mNext) = v6;
    *(float *)&v9[4].mNext = point;
    BYTE4(v9[4].mNext) &= 0xFEu;
    v9->mNext = (UFG::allocator::free_link *)&UFG::ConversationElementActionRequest::`vftable';
    LODWORD(v9[5].mNext) = v5;
    v9[6].mNext = 0i64;
    v9[7].mNext = 0i64;
    LOBYTE(v9[8].mNext) = onListner;
  }
  else
  {
    v9 = 0i64;
  }
  v11 = &v9[1].mNext;
  v12 = v7->m_interruptionPoints.mNode.mPrev;
  v12->mNext = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  *v11 = v12;
  v11[1] = (char *)v7 + 136;
  v7->m_interruptionPoints.mNode.mPrev = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&v9[1];
  return v9;
}

// File Line: 2691
// RVA: 0x598B20
void __fastcall UFG::ConversationElement::ClearSpeechFlags(UFG::ConversationElement *this)
{
  UFG::SimComponent *v1; // rbx
  UFG::ConversationElement *v2; // rdi
  bool v3; // cf
  bool v4; // zf
  UFG::AudioEvent *v5; // rcx
  UFG::SimComponent *v6; // rbx
  UFG::AudioEvent *v7; // rcx

  v1 = this->m_spkAac.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    if ( this->m_type )
    {
      v3 = LODWORD(v1[6].m_pSimObject) < 5;
      v4 = LODWORD(v1[6].m_pSimObject) == 5;
      HIDWORD(v1[6].m_BoundComponentHandles.mNode.mPrev) = 0;
      if ( v3 || v4 )
      {
        if ( (_QWORD)v1[8].m_pSimObject & 8 )
        {
          v5 = (UFG::AudioEvent *)v1[6].m_SafePointerList.mNode.mNext;
          if ( v5 )
            UFG::AudioEvent::StopAndForget(v5, 0x1F4u);
        }
      }
    }
    LOBYTE(v1[8].m_pSimObject) &= 0xFCu;
    BYTE1(v1[8].m_pSimObject) &= 0xDFu;
    LOBYTE(v1[8].m_pSimObject) |= 0x18u;
    if ( UFG::ConversationManager::sm_debugScrConversations )
      BYTE1(v1[8].m_pSimObject) &= 0xFDu;
  }
  v6 = v2->m_tgtAac.m_pPointer;
  if ( v6 )
  {
    if ( v2->m_type )
    {
      v3 = LODWORD(v6[6].m_pSimObject) < 5;
      v4 = LODWORD(v6[6].m_pSimObject) == 5;
      HIDWORD(v6[6].m_BoundComponentHandles.mNode.mPrev) = 0;
      if ( v3 || v4 )
      {
        if ( (_QWORD)v6[8].m_pSimObject & 8 )
        {
          v7 = (UFG::AudioEvent *)v6[6].m_SafePointerList.mNode.mNext;
          if ( v7 )
            UFG::AudioEvent::StopAndForget(v7, 0x1F4u);
        }
      }
    }
    LOBYTE(v6[8].m_pSimObject) &= 0xFCu;
    BYTE1(v6[8].m_pSimObject) &= 0xDFu;
    LOBYTE(v6[8].m_pSimObject) |= 0x18u;
    if ( UFG::ConversationManager::sm_debugScrConversations )
      BYTE1(v6[8].m_pSimObject) &= 0xFDu;
  }
}

// File Line: 2778
// RVA: 0x5AB330
void __fastcall UFG::ConversationElement::SetTagInterruptFlags(UFG::ConversationElement *this, bool enable)
{
  UFG::SimComponent *v2; // rax
  UFG::SimComponent *v3; // rax

  v2 = this->m_spkAac.m_pPointer;
  if ( v2 )
  {
    if ( enable )
      LOBYTE(v2[8].m_pSimObject) |= 0x18u;
    else
      LOBYTE(v2[8].m_pSimObject) &= 0xE7u;
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
  UFG::SimComponent *v2; // r8
  char v3; // al
  UFG::SimComponent *v4; // rax

  v2 = this->m_spkAac.m_pPointer;
  if ( v2 )
  {
    v3 = (char)v2[8].m_pSimObject;
    BYTE1(v2[8].m_pSimObject) &= 0xDFu;
    LOBYTE(v2[8].m_pSimObject) = v3 & 0xFD | 1;
    BYTE1(v2[8].m_pSimObject) |= 32 * actionRequests;
  }
  v4 = this->m_tgtAac.m_pPointer;
  if ( v4 )
  {
    LOBYTE(v4[8].m_pSimObject) &= 0xFEu;
    BYTE1(v4[8].m_pSimObject) &= 0xDFu;
    LOBYTE(v4[8].m_pSimObject) |= 2u;
    BYTE1(v4[8].m_pSimObject) |= 32 * actionRequests;
  }
}

// File Line: 2838
// RVA: 0x5AA980
void __fastcall UFG::ConversationElement::SetActiveAmbConv(UFG::ConversationElement *this, UFG::Conversation *conv)
{
  UFG::SimComponent *v2; // r8
  UFG::AudioEvent *v3; // rcx

  v2 = this->m_spkAac.m_pPointer;
  if ( v2 )
  {
    HIDWORD(v2[6].m_BoundComponentHandles.mNode.mPrev) = 0;
    if ( conv )
      HIDWORD(v2[6].m_BoundComponentHandles.mNode.mPrev) = conv->mNode.mUID;
    if ( LODWORD(v2[6].m_pSimObject) <= 5 && (_QWORD)v2[8].m_pSimObject & 8 )
    {
      v3 = (UFG::AudioEvent *)v2[6].m_SafePointerList.mNode.mNext;
      if ( v3 )
        UFG::AudioEvent::StopAndForget(v3, 0x1F4u);
    }
  }
}

// File Line: 2857
// RVA: 0x5AAB90
void __fastcall UFG::ConversationElement::SetDebugFlags(UFG::ConversationElement *this, bool enable)
{
  UFG::SimComponent *v2; // r8
  UFG::SimComponent *v3; // rax

  v2 = this->m_spkAac.m_pPointer;
  if ( v2 )
  {
    BYTE1(v2[8].m_pSimObject) &= 0xFDu;
    BYTE1(v2[8].m_pSimObject) |= 2 * enable;
  }
  v3 = this->m_tgtAac.m_pPointer;
  if ( v3 )
  {
    BYTE1(v3[8].m_pSimObject) &= 0xFDu;
    BYTE1(v3[8].m_pSimObject) |= 2 * enable;
  }
}

// File Line: 2876
// RVA: 0x5ACB00
void __fastcall UFG::ConversationElement::StopLine(UFG::ConversationElement *this, bool force)
{
  UFG::SimComponent *v2; // rax
  UFG::AudioEvent *v3; // rcx
  unsigned int v4; // ebx
  UFG::TiDo *v5; // rax

  v2 = this->m_spkAac.m_pPointer;
  if ( v2 )
  {
    if ( LOBYTE(v2[5].m_pSimObject) )
    {
      if ( SHIDWORD(v2[6].m_BoundComponentHandles.mNode.mNext) > 0 )
      {
        v3 = (UFG::AudioEvent *)v2[6].m_SafePointerList.mNode.mNext;
        if ( v3 )
        {
          if ( force )
          {
            v4 = v3->m_uPlayingId;
            v3->m_pController = 0i64;
            v2[6].m_SafePointerList.mNode.mNext = 0i64;
            if ( v4 )
            {
              v5 = UFG::TiDo::GetInstance();
              UFG::TiDo::StopPlaying(v5, v4);
            }
          }
          else if ( (_QWORD)v2[8].m_pSimObject & 8 )
          {
            UFG::AudioEvent::StopAndForget(v3, 0x1F4u);
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
  UFG::SimComponent **v1; // r14
  UFG::SimComponent **v2; // rsi
  UFG::ConversationElement *v3; // rbp
  UFG::SimComponent *v4; // rdi
  UFG::SimObject *v5; // rbx
  UFG::SimObject *v6; // rax

  v1 = &this->m_tgtAac.m_pPointer;
  v2 = (UFG::SimComponent **)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
  v3 = this;
  *(_QWORD *)&this->m_timeAlive = 0i64;
  if ( v2 != &this->m_tgtAac.m_pPointer )
  {
    do
    {
      if ( v2 )
      {
        *((_BYTE *)v2 + 36) &= 0xFEu;
        v4 = *v2;
        v5 = UFG::ConversationElement::GetTarget(v3);
        v6 = UFG::ConversationElement::GetSpeaker(v3);
        ((void (__fastcall *)(UFG::SimComponent **, UFG::SimObject *, UFG::SimObject *))v4->m_SafePointerList.mNode.mNext)(
          v2,
          v6,
          v5);
      }
      v2 = (UFG::SimComponent **)&v2[2][-1].m_BoundComponentHandles.mNode.mNext;
    }
    while ( v2 != v1 );
  }
}

// File Line: 2925
// RVA: 0x5AC560
UFG::SimComponent *__fastcall UFG::ConversationElement::SpeakerInitialized(UFG::ConversationElement *this)
{
  UFG::SimComponent *result; // rax

  result = this->m_spkAac.m_pPointer;
  if ( result )
    result = (UFG::SimComponent *)LOBYTE(result[5].m_pSimObject);
  return result;
}

// File Line: 2941
// RVA: 0x5A6450
char __fastcall UFG::ConversationElement::PlayLine(UFG::ConversationElement *this, unsigned int eventId, unsigned int inPriority, bool subtitle)
{
  UFG::ActorAudioComponent *v4; // rbp
  signed int priority; // esi
  bool v6; // r14
  unsigned int v7; // er15
  UFG::ConversationElement *v8; // rbx
  unsigned int v9; // edi
  unsigned int v10; // eax

  v4 = (UFG::ActorAudioComponent *)this->m_spkAac.m_pPointer;
  priority = inPriority;
  v6 = subtitle;
  v7 = eventId;
  if ( *((_BYTE *)this + 156) & 8 )
    priority = 10;
  v8 = this;
  if ( !v4 )
    return 0;
  v9 = this->m_playbackEvent.mUID;
  if ( this->m_playbackEvent.mUID == UFG::qWiseSymbol::get_null()->mUID )
    v9 = v7;
  if ( v8->m_type )
    return UFG::ActorAudioComponent::QueueSpeechExternalAmbient(v4, v9, v8->m_context.mData, 0i64, priority, 0, v6);
  v10 = UFG::TiDo::CalcWwiseUid(v8->m_context.mData);
  return UFG::ActorAudioComponent::QueueSpeechExternalMission(v4, v9, v10, 0i64, priority, v6);
}

// File Line: 2975
// RVA: 0x5A08C0
UFG::SimComponent *__fastcall UFG::ConversationElement::LineIsPlaying(UFG::ConversationElement *this)
{
  UFG::SimComponent *result; // rax

  result = this->m_spkAac.m_pPointer;
  if ( result )
    result = (UFG::SimComponent *)(SHIDWORD(result[6].m_BoundComponentHandles.mNode.mNext) > 0
                                && result[6].m_SafePointerList.mNode.mNext);
  return result;
}

// File Line: 2989
// RVA: 0x5A9FE0
void __fastcall UFG::ConversationElement::RemoveInterruptPoint(UFG::ConversationElement *this, int id)
{
  UFG::SimComponent **v2; // rsi
  int v3; // edi
  UFG::SimComponent **v4; // rbx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  _QWORD *v7; // rdx

  v2 = &this->m_tgtAac.m_pPointer;
  v3 = id;
  v4 = (UFG::SimComponent **)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
  if ( v4 != &this->m_tgtAac.m_pPointer )
  {
    do
    {
      if ( *((_DWORD *)v4 + 7) == v3 )
      {
        v5 = v4[1];
        v6 = v4[2];
        v7 = v4 + 1;
        v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v6;
        v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v5;
        *v7 = v7;
        v7[1] = v7;
        if ( v4 )
          ((void (__fastcall *)(UFG::SimComponent **, signed __int64))(*v4)->vfptr)(v4, 1i64);
      }
      v4 = (UFG::SimComponent **)&v4[2][-1].m_BoundComponentHandles.mNode.mNext;
    }
    while ( v4 != v2 );
  }
}

// File Line: 3006
// RVA: 0x5A0390
bool __fastcall UFG::ConversationElement::InterruptPointReached(UFG::ConversationElement *this, int id)
{
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v2; // rax
  UFG::SimComponent **v3; // rcx
  signed __int64 v4; // rax

  v2 = this->m_interruptionPoints.mNode.mNext;
  v3 = &this->m_tgtAac.m_pPointer;
  v4 = (signed __int64)&v2[-1].mNext;
  if ( (UFG::SimComponent **)v4 == v3 )
    return 0;
  while ( *(_DWORD *)(v4 + 28) != id )
  {
    v4 = *(_QWORD *)(v4 + 16) - 8i64;
    if ( (UFG::SimComponent **)v4 == v3 )
      return 0;
  }
  return *(_BYTE *)(v4 + 36) & 1;
}

// File Line: 3023
// RVA: 0x5B0B20
void __fastcall UFG::ConversationElement::UpdateInterruptionPoints(UFG::ConversationElement *this, UFG::Conversation *conversation)
{
  UFG::SimComponent **v2; // r14
  UFG::ConversationElement *v3; // rbp
  float *v4; // rsi
  char v5; // al
  __int64 v6; // rdi
  UFG::SimObject *v7; // rbx
  UFG::SimObject *v8; // rax

  v2 = &this->m_tgtAac.m_pPointer;
  v3 = this;
  v4 = (float *)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
  if ( v4 != (float *)&this->m_tgtAac.m_pPointer )
  {
    do
    {
      if ( v4[8] <= v3->m_sampleLength )
      {
        v5 = *((_BYTE *)v4 + 36);
        if ( !(v5 & 1) )
        {
          v6 = *(_QWORD *)v4;
          *((_BYTE *)v4 + 36) = v5 | 1;
          v7 = UFG::ConversationElement::GetTarget(v3);
          v8 = UFG::ConversationElement::GetSpeaker(v3);
          (*(void (__fastcall **)(float *, UFG::SimObject *, UFG::SimObject *))(v6 + 8))(v4, v8, v7);
        }
      }
      v4 = (float *)(*((_QWORD *)v4 + 2) - 8i64);
    }
    while ( v4 != (float *)v2 );
  }
}

// File Line: 3106
// RVA: 0x5ACCB0
char *__fastcall UFG::ConversationElement::ToString(UFG::ConversationElement *this)
{
  UFG::ConversationElement *v1; // rbx
  UFG::SimComponent *v2; // rcx
  char *v3; // rdi
  char *v4; // rax
  UFG::SimComponent *v5; // rcx
  __int64 v6; // r8
  signed __int64 i; // rax
  UFG::qString *v8; // rax
  char *v9; // rbx
  UFG::qString v11; // [rsp+20h] [rbp-88h]
  __int64 v12; // [rsp+48h] [rbp-60h]
  UFG::qString text; // [rsp+50h] [rbp-58h]
  UFG::qString v14; // [rsp+78h] [rbp-30h]

  v12 = -2i64;
  v1 = this;
  v2 = this->m_spkAac.m_pPointer;
  v3 = &customWorldMapCaption;
  if ( v2 )
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2->m_pSimObject->m_Name);
  else
    v4 = &customWorldMapCaption;
  UFG::qString::qString(&v11, v4);
  UFG::qString::operator+=(&v11, "->");
  v5 = v1->m_tgtAac.m_pPointer;
  if ( v5 )
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->m_pSimObject->m_Name);
  UFG::qString::operator+=(&v11, v3);
  UFG::qString::operator+=(&v11, " : ");
  UFG::qString::qString(&text, &v1->m_context);
  UFG::qString::operator+=(&v11, &text);
  v6 = 0i64;
  for ( i = (signed __int64)&v1->m_interruptionPoints.mNode.mNext[-1].mNext;
        (UFG::SimComponent **)i != &v1->m_tgtAac.m_pPointer;
        i = *(_QWORD *)(i + 16) - 8i64 )
  {
    v6 = (unsigned int)(v6 + 1);
  }
  UFG::qString::qString(&v14, " : %u int pts", v6);
  UFG::qString::operator+=(&v11, v8);
  UFG::qString::~qString(&v14);
  v9 = v11.mData;
  UFG::qString::~qString(&text);
  UFG::qString::~qString(&v11);
  return v9;
}

// File Line: 3144
// RVA: 0x593290
void __fastcall UFG::ConversationElementActionRequest::ConversationElementActionRequest(UFG::ConversationElementActionRequest *this, int id, float time, const char *action_request_name, bool onListener)
{
  const char *v5; // rbx
  unsigned int v6; // edi
  UFG::ConversationElementActionRequest *v7; // rsi
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v8; // rax
  const char *v9; // r9
  unsigned int action_request; // [rsp+48h] [rbp+10h]

  v5 = action_request_name;
  v6 = id;
  v7 = this;
  v8 = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&this->mPrev;
  v8->mPrev = v8;
  v8->mNext = v8;
  this->vfptr = (UFG::ConversationElementInterruptionVtbl *)&UFG::ConversationElementInterruption::`vftable';
  this->m_type = 2;
  this->m_id = id;
  this->m_point = time;
  *((_BYTE *)&this->0 + 36) &= 0xFEu;
  this->vfptr = (UFG::ConversationElementInterruptionVtbl *)&UFG::ConversationElementActionRequest::`vftable';
  this->m_target = 0i64;
  this->m_targetInst = 0i64;
  this->m_playOnListener = onListener;
  action_request = gActionRequest_Action.m_EnumValue;
  Intention::GetActionRequest(action_request_name, &action_request);
  v9 = v5;
  LODWORD(v5) = action_request;
  UFG::qPrintf("Added action request: id: %3d   %10u --> '%s'\n", v6, action_request, v9, -2i64);
  v7->m_actionRequest = (unsigned int)v5;
}

// File Line: 3167
// RVA: 0x5A4760
void __fastcall UFG::ConversationElementActionRequest::OnReached(UFG::ConversationElementActionRequest *this, UFG::SimObject *speaker, UFG::SimObject *listener)
{
  UFG::SimObjectGame *v3; // rbx
  UFG::ConversationElementActionRequest *v4; // rdi
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rdx
  UFG::SimComponent *v7; // rax
  SSInstance *v8; // rcx
  UFG::TargetingSystemBaseComponent *v9; // rax
  unsigned __int16 v10; // cx
  UFG::SimObjectGame *v11; // rcx
  bool v12; // zf

  v3 = (UFG::SimObjectGame *)speaker;
  v4 = this;
  if ( this->m_playOnListener )
    v3 = (UFG::SimObjectGame *)listener;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[41].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::DialogueAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DialogueAnimationComponent::_TypeUID);
      }
      v6 = v7;
    }
    if ( v6 )
      *((_QWORD *)&v6[2].m_BoundComponentHandles.mNode.mPrev + ((signed __int64)(signed int)v4->m_actionRequest >> 6)) |= 1i64 << (v4->m_actionRequest & 0x3F);
  }
  if ( !v4->m_target )
  {
    if ( !v4->m_targetInst )
      return;
    v8 = v4->m_targetInst;
    if ( v8 )
      v4->m_target = (UFG::SimObject *)UFG::TSScriptedDialogueElement::GetSimObjectFromSymbol(v8);
  }
  if ( v3 )
  {
    v10 = v3->m_Flags;
    if ( (v10 >> 14) & 1 || (v10 & 0x8000u) != 0 )
    {
      v9 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    else
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = v3;
      }
      else
      {
        v12 = ((v10 >> 12) & 1) == 0;
        v11 = v3;
        if ( v12 )
        {
          v9 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v3->vfptr,
                                                      UFG::TargetingSystemBaseComponent::_TypeUID);
          goto LABEL_30;
        }
      }
      v9 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v11,
                                                  UFG::TargetingSystemBaseComponent::_TypeUID);
    }
  }
  else
  {
    v9 = 0i64;
  }
LABEL_30:
  UFG::TargetingSystemBaseComponent::SetTarget(v9, eTARGET_TYPE_POINT_AT, v4->m_target);
}

// File Line: 3265
// RVA: 0x5A30D0
signed __int64 __fastcall UFG::ConversationElementEmotionRequest::LookupEmotion(const char *emotion_name)
{
  unsigned int v1; // edi
  const char *v2; // rsi
  signed __int64 v3; // rbx

  v1 = 0;
  v2 = emotion_name;
  v3 = 0i64;
  while ( (unsigned int)UFG::qStringCompareInsensitive(v2, *(const char **)(v3 + 5402706272i64), -1)
       && (unsigned int)UFG::qStringCompareInsensitive(v2, *(const char **)(v3 + 5402833232i64), -1) )
  {
    v3 += 8i64;
    ++v1;
    if ( v3 >= 104 )
      return 0xFFFFFFFFi64;
  }
  return v1;
}

// File Line: 3291
// RVA: 0x5A48C0
void __fastcall UFG::ConversationElementEmotionRequest::OnReached(UFG::ConversationElementEmotionRequest *this, UFG::SimObject *speaker, UFG::SimObject *listener)
{
  UFG::SimObjectCVBase *v3; // r9
  UFG::ConversationElementEmotionRequest *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::ActiveAIEntityComponent *v6; // rax

  v3 = (UFG::SimObjectCVBase *)speaker;
  v4 = this;
  if ( this->m_playOnListener )
    v3 = (UFG::SimObjectCVBase *)listener;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    if ( v6 )
      v6->m_FacialEmotion = v4->m_emotion;
  }
}

// File Line: 3310
// RVA: 0x5A4950
void __fastcall UFG::ConversationElementEmotionRequest::OnReset(UFG::ConversationElementEmotionRequest *this, UFG::SimObject *speaker, UFG::SimObject *listener)
{
  UFG::SimObjectCVBase *v3; // r9
  unsigned __int16 v4; // cx
  UFG::ActiveAIEntityComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)speaker;
  if ( this->m_playOnListener )
    v3 = (UFG::SimObjectCVBase *)listener;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    if ( v5 )
      v5->m_FacialEmotion = 0;
  }
}

// File Line: 3334
// RVA: 0x5AC3C0
void __fastcall UFG::ScriptedConversationElement::SetupScript(UFG::ScriptedConversationElement *this, ASymbol *symbol)
{
  ASymbol *v2; // rsi
  UFG::ScriptedConversationElement *v3; // rbx
  SSActorClass *v4; // rdi
  UFG::TSScriptedDialogueElement *v5; // rax

  v2 = symbol;
  v3 = this;
  v4 = (SSActorClass *)SSBrain::get_class("ScriptedDialogueElement");
  if ( v4 )
  {
    v5 = (UFG::TSScriptedDialogueElement *)AMemory::c_malloc_func(0x88ui64, "TSScriptedDialogueElement");
    if ( v5 )
      UFG::TSScriptedDialogueElement::TSScriptedDialogueElement(v5, v3, v2, v4);
    v3->m_script = v5;
    ++UFG::gNumScriptedConversationElements;
    ++v3->m_script->i_ref_count;
    SSInstance::call_default_constructor((SSInstance *)&v3->m_script->vfptr);
    SSActor::enable_behavior((SSActor *)&v3->m_script->vfptr, 1);
  }
}

// File Line: 3354
// RVA: 0x5948E0
void __fastcall UFG::ScriptedConversationElement::~ScriptedConversationElement(UFG::ScriptedConversationElement *this)
{
  UFG::ScriptedConversationElement *v1; // rbx
  UFG::TSScriptedDialogueElement *v2; // rcx
  bool v3; // zf
  UFG::AudioEntity *v4; // rcx
  UFG::NonCharacterDialogueContainer *v5; // rcx

  v1 = this;
  this->vfptr = (UFG::ConversationElementVtbl *)&UFG::ScriptedConversationElement::`vftable';
  v2 = this->m_script;
  if ( v2 )
  {
    v3 = v2->i_ref_count-- == 1;
    if ( v3 )
    {
      v2->i_ref_count = 2147483648;
      ((void (__cdecl *)(UFG::TSScriptedDialogueElement *))v2->vfptr[1].get_scope_context)(v2);
    }
    --UFG::gNumScriptedConversationElements;
    v1->m_script = 0i64;
  }
  v4 = (UFG::AudioEntity *)&v1->m_nonCharInfo->vfptr;
  if ( v4 )
  {
    UFG::AudioEntity::Shutdown(v4);
    v5 = v1->m_nonCharInfo;
    if ( v5 )
      v5->vfptr->__vecDelDtor((UFG::AudioEntity *)&v5->vfptr, 1u);
  }
  v1->m_nonCharInfo = 0i64;
  UFG::ConversationElement::~ConversationElement((UFG::ConversationElement *)&v1->vfptr);
}

// File Line: 3379
// RVA: 0x5AB0E0
void __fastcall UFG::ScriptedConversationElement::SetPlaybackEvent(UFG::ScriptedConversationElement *this, const char *playback_event)
{
  UFG::ScriptedConversationElement *v2; // rdi
  unsigned int v3; // eax

  v2 = this;
  UFG::qWiseSymbol::set_from_cstr(&this->m_playbackEvent, playback_event);
  v3 = v2->m_playbackEvent.mUID;
  if ( v3 == qwsPlayCellPhone.mUID
    || v3 == qwsPlay2D.mUID
    || v3 == qwsPlayCB.mUID
    || v3 == qwsPlayDrivingNoLip.mUID
    || v3 == qwsPlayCellPhone0.mUID
    || v3 == qwsPlayCellPhone2.mUID
    || v3 == qwsPlayCellPhone4.mUID
    || v3 == qwsPlayCellPhone6.mUID
    || v3 == qwsPlayCB4.mUID
    || v3 == qwsPlayCB6.mUID
    || v3 == qwsPlayPoliceBullhorn.mUID
    || v3 == qwsPlayCellPhoneRingOutgoing.mUID )
  {
    UFG::ScriptedConversationElement::CreateNonCharacterContainer(v2, 0i64);
  }
}

// File Line: 3405
// RVA: 0x59A5F0
void __fastcall UFG::ScriptedConversationElement::CreateNonCharacterContainer(UFG::ScriptedConversationElement *this, UFG::qVector3 *pos)
{
  UFG::qVector3 *v2; // rsi
  UFG::ScriptedConversationElement *v3; // rbp
  UFG::TransformNodeComponent *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx
  UFG::SimObjectCharacter *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // eax
  UFG::NonCharacterDialogueContainer *v11; // rcx

  v2 = pos;
  v3 = this;
  v4 = 0i64;
  if ( !this->m_nonCharInfo )
  {
    v5 = UFG::qMalloc(0x150ui64, "DialogueManager.NonCharContainer", 0i64);
    v6 = v5;
    if ( v5 )
    {
      UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)v5);
      v6->mNext = (UFG::allocator::free_link *)&UFG::NonCharacterDialogueContainer::`vftable';
      v6[40].mNext = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    v3->m_nonCharInfo = (UFG::NonCharacterDialogueContainer *)v6;
  }
  if ( v2 )
  {
    v8 = v2->y;
    v9 = v2->z;
    v10 = v2->x;
  }
  else
  {
    v7 = UFG::GetLocalPlayer();
    if ( v7 )
      v4 = v7->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v8 = v4->mWorldTransform.v3.y;
    v9 = v4->mWorldTransform.v3.z;
    v10 = v4->mWorldTransform.v3.x;
  }
  v11 = v3->m_nonCharInfo;
  v11->m_WorldMatrix.v3.x = v10;
  v11->m_WorldMatrix.v3.y = v8;
  v11->m_WorldMatrix.v3.z = v9;
  v11->m_WorldMatrix.v3.w = 1.0;
  UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v11->vfptr);
}

// File Line: 3432
// RVA: 0x5AA640
void __fastcall UFG::ScriptedConversationElement::Reset(UFG::ScriptedConversationElement *this)
{
  UFG::ScriptedConversationElement *v1; // rbx
  UFG::NonCharacterDialogueContainer *v2; // rcx

  v1 = this;
  v2 = this->m_nonCharInfo;
  if ( v2 )
    UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&v2->vfptr);
  UFG::ConversationElement::Reset((UFG::ConversationElement *)&v1->vfptr);
}

// File Line: 3446
// RVA: 0x5AC580
char __fastcall UFG::ScriptedConversationElement::SpeakerInitialized(UFG::ScriptedConversationElement *this)
{
  UFG::ScriptedConversationElement *v1; // rbx
  UFG::NonCharacterDialogueContainer *v2; // rcx
  UFG::SimComponent *v3; // rcx
  char result; // al

  v1 = this;
  v2 = this->m_nonCharInfo;
  if ( v2 )
  {
    if ( v2->m_bIsInitialized )
    {
      result = 1;
    }
    else
    {
      UFG::NonCharacterDialogueContainer::Init(v2);
      result = v1->m_nonCharInfo->m_bIsInitialized;
    }
  }
  else
  {
    v3 = v1->m_spkAac.m_pPointer;
    result = 0;
    if ( v3 )
      result = (char)v3[5].m_pSimObject;
  }
  return result;
}

// File Line: 3466
// RVA: 0x5A66D0
char __fastcall UFG::ScriptedConversationElement::PlayLine(UFG::ScriptedConversationElement *this, unsigned int eventId, unsigned int inPriority, bool subtitle)
{
  bool v4; // si
  unsigned int v5; // ebp
  UFG::ScriptedConversationElement *v6; // rdi
  unsigned int v8; // ebx

  v4 = subtitle;
  v5 = eventId;
  v6 = this;
  if ( !this->m_nonCharInfo )
    return UFG::ConversationElement::PlayLine((UFG::ConversationElement *)&this->vfptr, eventId, inPriority, subtitle);
  v8 = this->m_playbackEvent.mUID;
  if ( this->m_playbackEvent.mUID == UFG::qWiseSymbol::get_null()->mUID )
    v8 = v5;
  return UFG::NonCharacterDialogueContainer::PlayLine(v6->m_nonCharInfo, v8, v6->m_context.mData, v4);
}

// File Line: 3481
// RVA: 0x5ACB90
void __fastcall UFG::ScriptedConversationElement::StopLine(UFG::ScriptedConversationElement *this, bool force)
{
  UFG::NonCharacterDialogueContainer *v2; // r8
  UFG::AudioEvent *v3; // rax
  unsigned int v4; // ebx
  UFG::TiDo *v5; // rax

  v2 = this->m_nonCharInfo;
  if ( v2 )
  {
    v3 = v2->m_controller.m_pEvent;
    if ( v3 )
      v4 = v3->m_uPlayingId;
    else
      v4 = 0;
    if ( v3 )
      v3->m_pController = 0i64;
    v2->m_controller.m_pEvent = 0i64;
    v5 = UFG::TiDo::GetInstance();
    UFG::TiDo::StopPlaying(v5, v4);
  }
  else
  {
    UFG::ConversationElement::StopLine((UFG::ConversationElement *)&this->vfptr, force);
  }
}

// File Line: 3494
// RVA: 0x5A08F0
bool __fastcall UFG::ScriptedConversationElement::LineIsPlaying(UFG::ScriptedConversationElement *this)
{
  UFG::NonCharacterDialogueContainer *v1; // rdx
  UFG::SimComponent *v2; // rax

  v1 = this->m_nonCharInfo;
  if ( v1 )
    return v1->m_controller.m_pEvent != 0i64;
  v2 = this->m_spkAac.m_pPointer;
  return v2 && SHIDWORD(v2[6].m_BoundComponentHandles.mNode.mNext) > 0 && v2[6].m_SafePointerList.mNode.mNext;
}

// File Line: 3506
// RVA: 0x5AAA30
void __fastcall UFG::ScriptedConversationElement::SetConversationTargets(UFG::ScriptedConversationElement *this)
{
  UFG::SimComponent *v1; // rdi
  UFG::SimObjectGame *v2; // rbx
  UFG::SimObjectGame *v3; // rdi
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // cx
  UFG::TargetingSystemBaseComponent *v6; // rbp
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::TargetingSystemBaseComponent *v9; // rsi
  UFG::SimComponent *v10; // rax

  v1 = this->m_spkAac.m_pPointer;
  v2 = 0i64;
  if ( v1 )
    v3 = (UFG::SimObjectGame *)v1->m_pSimObject;
  else
    v3 = 0i64;
  v4 = this->m_tgtAac.m_pPointer;
  if ( v4 )
    v2 = (UFG::SimObjectGame *)v4->m_pSimObject;
  if ( v3 && v2 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v6 = (UFG::TargetingSystemBaseComponent *)v7;
    }
    else
    {
      v6 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    v8 = v2->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v2->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v9 = (UFG::TargetingSystemBaseComponent *)v10;
    }
    else
    {
      v9 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      if ( v9 )
      {
        UFG::TargetingSystemBaseComponent::SetTarget(v6, eTARGET_TYPE_CONVERSATION, (UFG::SimObject *)&v2->vfptr);
        UFG::TargetingSystemBaseComponent::SetTarget(v9, eTARGET_TYPE_CONVERSATION, (UFG::SimObject *)&v3->vfptr);
      }
    }
  }
}

// File Line: 3525
// RVA: 0x5988D0
void __fastcall UFG::ScriptedConversationElement::ClearConversationTargets(UFG::ScriptedConversationElement *this)
{
  UFG::ScriptedConversationElement *v1; // rax
  UFG::SimComponent *v2; // rcx
  UFG::SimObjectGame *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  UFG::SimComponent *v5; // rax
  unsigned __int16 v6; // dx
  UFG::TargetingSystemBaseComponent *v7; // rdi
  UFG::SimComponent *v8; // rax
  unsigned __int16 v9; // cx
  UFG::TargetingSystemBaseComponent *v10; // rbx
  UFG::SimComponent *v11; // rax

  v1 = this;
  v2 = this->m_spkAac.m_pPointer;
  v3 = 0i64;
  if ( v2 )
    v4 = (UFG::SimObjectGame *)v2->m_pSimObject;
  else
    v4 = 0i64;
  v5 = v1->m_tgtAac.m_pPointer;
  if ( v5 )
    v3 = (UFG::SimObjectGame *)v5->m_pSimObject;
  if ( v4 && v3 )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v4->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v7 = (UFG::TargetingSystemBaseComponent *)v8;
    }
    else
    {
      v7 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
    }
    v9 = v3->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v9 >> 12) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v11 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v3->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v10 = (UFG::TargetingSystemBaseComponent *)v11;
    }
    else
    {
      v10 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    if ( v7 )
    {
      if ( v10 )
      {
        UFG::TargetingSystemBaseComponent::SetTarget(v7, eTARGET_TYPE_CONVERSATION, 0i64);
        UFG::TargetingSystemBaseComponent::SetTarget(v10, eTARGET_TYPE_CONVERSATION, 0i64);
      }
    }
  }
}

// File Line: 3553
// RVA: 0x59F770
void __fastcall UFG::NonCharacterDialogueContainer::Init(UFG::NonCharacterDialogueContainer *this)
{
  UFG::NonCharacterDialogueContainer *v1; // rbx
  __int64 v2; // r8
  UFG::qString v3; // [rsp+28h] [rbp-30h]
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]

  v1 = this;
  v2 = sNum++;
  UFG::qString::qString(&v3, "NCDC_%u", v2);
  UFG::qSymbol::create_from_string(&result, v3.mData);
  UFG::AudioEntity::Init((UFG::AudioEntity *)&v1->vfptr, &result, &UFG::qMatrix44::msIdentity);
  UFG::qString::~qString(&v3);
}

// File Line: 3570
// RVA: 0x5A6510
char __fastcall UFG::NonCharacterDialogueContainer::PlayLine(UFG::NonCharacterDialogueContainer *this, unsigned int eventId, const char *context, bool subtitle)
{
  bool v4; // r14
  unsigned int v5; // er15
  UFG::NonCharacterDialogueContainer *v6; // rbp
  unsigned int v7; // ebx
  UFG::allocator::free_link *v8; // rax
  UFG::AudioEventExternalSourceInfo *v9; // rax
  UFG::AudioEventExternalSourceInfo *v10; // rsi
  CAkSwitchCntr *v11; // rcx
  UFG::ExternalSourceInfoNode *v12; // rbx
  UFG::AudioEvent **v13; // rdi
  UFG::AudioEventCallbackObject *v14; // rbx
  unsigned int v15; // eax

  v4 = subtitle;
  v5 = eventId;
  v6 = this;
  v7 = UFG::TiDo::CalcWwiseUid(context);
  if ( (signed int)UFG::TiDo::GetWwiseStreamFileSize(v7) > 0 )
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
    v11 = (CAkSwitchCntr *)v10->m_externals.p;
    LODWORD(v11->vfptr) = slot_1_22;
    v10->m_externals.p->m_fileId = v7;
    v12 = v10->m_externals.p;
    v12->m_codecID = Scaleform::Render::DICommand_ApplyFilter::GetType(v11);
    v13 = &v6->m_controller.m_pEvent;
    if ( !v6->m_controller.m_pEvent )
    {
      UFG::AudioEntity::CreateEventA((UFG::AudioEntity *)&v6->vfptr, v5, &v6->m_controller, 0i64, v10);
      if ( *v13 )
      {
        if ( v4 )
        {
          v14 = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
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
          if ( v14 )
          {
            v14->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
            v14->m_next = 0i64;
            v14->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::SubtitleCallback::`vftable';
          }
          if ( *v13 )
            UFG::AudioEvent::AddCallback(*v13, v14);
        }
        if ( *v13 )
        {
          if ( (*v13)->vfptr->Play(*v13, 0) )
            return 1;
          *((_BYTE *)*v13 + 144) |= 4u;
          if ( *v13 )
            (*v13)->m_pController = 0i64;
          *v13 = 0i64;
        }
        if ( *v13 )
          UFG::AudioEvent::Destroy(*v13);
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
  return atexit(dynamic_atexit_destructor_for__UFG::ConversationManager::sm_conversationDb__);
}

// File Line: 3678
// RVA: 0x59AD30
void UFG::ConversationManager::Destroy(void)
{
  Render::SkinningCacheNode *v0; // rax
  Illusion::Buffer **v1; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v2; // rdx

  if ( UFG::ConversationManager::sm_conversationDb.mTree.mCount )
  {
    while ( 1 )
    {
      v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
      if ( !v0 )
        break;
      v1 = &v0[-1].mCachedBufferPtr;
      if ( v0 == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      v2 = &v0->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::ConversationManager::sm_conversationDb,
        v2);
      if ( v1 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v1)->mNode.mParent)(v1, 1i64);
      if ( !UFG::ConversationManager::sm_conversationDb.mTree.mCount )
        return;
    }
    v1 = 0i64;
LABEL_6:
    v2 = 0i64;
    goto LABEL_7;
  }
}

// File Line: 3729
// RVA: 0x5966C0
UFG::ScriptedConversation *__fastcall UFG::ConversationManager::AddScriptedConversation(ASymbol *symbol)
{
  ASymbol *v1; // r14
  unsigned int v2; // ebx
  UFG::qBaseTreeRB *v3; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::qBaseNodeRB *v6; // rsi
  __int64 v7; // rax
  __int64 v8; // rdi
  __int64 v9; // rbx
  char *v10; // rax

  v1 = symbol;
  v2 = symbol->i_uid;
  if ( symbol->i_uid )
  {
    v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2);
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
    UFG::ScriptedConversation::ScriptedConversation((UFG::ScriptedConversation *)v5, v1, v2);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( UFG::ConversationManager::sm_debugScrConversations )
  {
    v9 = *(_QWORD *)(v8 + 176);
    v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v1);
    UFG::qPrintf("Added scripted conversation '%s': 0x%08x  0x%08x\n", v10, v8, v9);
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
  unsigned int v1; // ebx
  UFG::qBaseTreeRB *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qBaseNodeRB *v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rbx

  v1 = uid;
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
    UFG::AmbientConversation::AmbientConversation((UFG::AmbientConversation *)v3, v1);
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
  UFG::Conversation *v2; // rbx

  if ( conv )
  {
    v2 = conv;
    if ( conv->m_type )
    {
      if ( conv->m_state == 1 )
        UFG::Conversation::OnFinish(conv, a2);
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::ConversationManager::sm_conversationDb,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v2->mNode);
    UFG::Conversation::Destroy(v2);
    v2->vfptr->__vecDelDtor(v2, 1u);
  }
}

// File Line: 3859
// RVA: 0x5B0340
void __fastcall UFG::ConversationManager::UpdateConversations(float delta_sec)
{
  UFG::allocator::free_link *v1; // rbp
  unsigned int v2; // er13
  unsigned int v3; // er12
  unsigned int v4; // ebx
  UFG::qBaseTreeRB *i; // rax
  _BOOL8 v6; // rdx
  signed __int64 v7; // rdi
  _BOOL8 v8; // rdx
  int v9; // er14
  __int64 v10; // r15
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rdx
  __int64 v16; // r8
  signed __int64 v17; // rcx
  signed __int64 v18; // rax
  signed __int64 v19; // r9
  __int64 v20; // rdx
  UFG::SimObject *v21; // r8
  __int64 v22; // rax
  UFG::SimObject *v23; // rdx
  unsigned int *v24; // rdi
  __int64 v25; // rsi
  UFG::qBaseTreeRB *v26; // rax
  _BOOL8 v27; // rdx
  signed __int64 v28; // rbx
  UFG::allocator::free_link *mem; // [rsp+30h] [rbp-48h]
  signed int v30; // [rsp+88h] [rbp+10h]

  v1 = 0i64;
  mem = 0i64;
  v2 = 0;
  v3 = 0;
  v4 = 180;
  v30 = 180;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v7 + 8)) )
  {
    v7 = (signed __int64)(i ? &i[-1].mCount : 0i64);
    if ( !v7 )
      break;
    UFG::Conversation::Update((UFG::Conversation *)v7, delta_sec, v6);
    if ( *(_BYTE *)(v7 + 168) & 2 && *(_DWORD *)(v7 + 48) == 7 )
    {
      UFG::Conversation::Update((UFG::Conversation *)v7, 0.0, v8);
      v9 = *(_DWORD *)(v7 + 32);
      v10 = v2;
      v11 = v2 + 1;
      if ( v2 + 1 > v3 )
      {
        v12 = 1;
        if ( v3 )
          v12 = 2 * v3;
        for ( ; v12 < v11; v12 *= 2 )
          ;
        if ( v12 <= 4 )
          v12 = 4;
        if ( v12 - v11 > 0x10000 )
          v12 = v2 + 65537;
        if ( v12 != v2 )
        {
          v13 = 4i64 * v12;
          if ( !is_mul_ok(v12, 4ui64) )
            v13 = -1i64;
          v14 = UFG::qMalloc(v13, "TiDoHK", 0i64);
          v1 = v14;
          if ( mem )
          {
            if ( v2 )
            {
              v15 = v14;
              v16 = v2;
              do
              {
                LODWORD(v15->mNext) = *(_DWORD *)((char *)&v15->mNext + (char *)mem - (char *)v14);
                v15 = (UFG::allocator::free_link *)((char *)v15 + 4);
                --v16;
              }
              while ( v16 );
            }
            operator delete[](mem);
          }
          mem = v1;
          v3 = v12;
        }
        v4 = v30;
      }
      ++v2;
      *((_DWORD *)&v1->mNext + v10) = v9;
    }
    if ( UFG::ConversationManager::sm_debugConversationsWithActor )
    {
      v17 = *(_QWORD *)(v7 + 80) - 8i64;
      v18 = v17;
      v19 = v7 + 64;
      if ( v17 == v7 + 64 )
        continue;
      while ( 1 )
      {
        v20 = *(_QWORD *)(v18 + 104);
        v21 = (UFG::SimObject *)(v20 ? *(_QWORD *)(v20 + 40) : 0i64);
        if ( v21 == UFG::ConversationManager::sm_debugConversationsWithActor )
          break;
        v18 = *(_QWORD *)(v18 + 16) - 8i64;
        if ( v18 == v19 )
        {
          if ( v17 == v19 )
            goto LABEL_49;
          while ( 1 )
          {
            v22 = *(_QWORD *)(v17 + 128);
            v23 = (UFG::SimObject *)(v22 ? *(_QWORD *)(v22 + 40) : 0i64);
            if ( v23 == UFG::ConversationManager::sm_debugConversationsWithActor )
              goto LABEL_42;
            v17 = *(_QWORD *)(v17 + 16) - 8i64;
            if ( v17 == v19 )
              goto LABEL_49;
          }
        }
      }
LABEL_42:
      v4 += 20;
      goto LABEL_48;
    }
    if ( UFG::ConversationManager::sm_debugAmbConversations && *(_DWORD *)(v7 + 64) == 1
      || UFG::ConversationManager::sm_debugScrConversations && !*(_DWORD *)(v7 + 64) )
    {
      v4 += 15;
LABEL_48:
      v30 = v4;
      (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v7 + 8i64))(v7, v4);
      continue;
    }
LABEL_49:
    ;
  }
  if ( v2 >= 1 )
  {
    v24 = (unsigned int *)v1;
    v25 = v2;
    do
    {
      if ( *v24 )
      {
        v26 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, *v24);
        if ( v26 )
        {
          v28 = (signed __int64)&v26[-1].mCount;
          if ( v26 != (UFG::qBaseTreeRB *)8 )
          {
            if ( *(_DWORD *)(v28 + 64) && *(_DWORD *)(v28 + 48) == 1 )
              UFG::Conversation::OnFinish((UFG::Conversation *)&v26[-1].mCount, v27);
            UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
              (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::ConversationManager::sm_conversationDb,
              (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v28 + 8));
            UFG::Conversation::Destroy((UFG::Conversation *)v28);
            (**(void (__fastcall ***)(signed __int64, signed __int64))v28)(v28, 1i64);
          }
        }
      }
      ++v24;
      --v25;
    }
    while ( v25 );
  }
  if ( v1 )
    operator delete[](v1);
}

// File Line: 3973
// RVA: 0x5A0470
char __fastcall UFG::ConversationManager::IsInConversationWithTopic(UFG::SimObject *simObject, UFG::eConversationTopic topic)
{
  UFG::SimObject *v2; // rbx
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v4; // r10
  signed __int64 v5; // r9
  signed __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rdx
  UFG::SimObject *v9; // r8
  __int64 v10; // rcx
  UFG::SimObject *v11; // rdx

  v2 = simObject;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v4 + 8)) )
  {
    if ( i )
      v4 = (signed __int64)&i[-1].mCount;
    else
      v4 = 0i64;
    if ( !v4 )
      return 0;
    v5 = v4 + 64;
    v6 = *(_QWORD *)(v4 + 80) - 8i64;
    v7 = v6;
    if ( v6 != v4 + 64 )
      break;
LABEL_18:
    ;
  }
  while ( 1 )
  {
    v8 = *(_QWORD *)(v7 + 104);
    v9 = (UFG::SimObject *)(v8 ? *(_QWORD *)(v8 + 40) : 0i64);
    if ( v9 == v2 )
      return 1;
    v7 = *(_QWORD *)(v7 + 16) - 8i64;
    if ( v7 == v5 )
    {
      if ( v6 == v5 )
        goto LABEL_18;
      while ( 1 )
      {
        v10 = *(_QWORD *)(v6 + 128);
        v11 = (UFG::SimObject *)(v10 ? *(_QWORD *)(v10 + 40) : 0i64);
        if ( v11 == v2 )
          return 1;
        v6 = *(_QWORD *)(v6 + 16) - 8i64;
        if ( v6 == v5 )
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
  int v1; // edx
  unsigned int v2; // ebx
  UFG::qString v4; // [rsp+28h] [rbp-30h]

  v0 = UFG::ConversationManager::sm_idCounter++;
  UFG::qString::qString(&v4, "AmbientConversation_%u", v0);
  v2 = v4.mStringHash32;
  if ( v4.mStringHash32 == -1 )
  {
    v2 = UFG::qStringHash32(v4.mData, v4.mStringHash32 | v1);
    v4.mStringHash32 = v2;
  }
  UFG::qString::~qString(&v4);
  return v2;
}

// File Line: 4044
// RVA: 0x5AC960
void UFG::ConversationManager::StopAllScriptedConversations(void)
{
  UFG::qBaseTreeRB *i; // rax
  _BOOL8 v1; // rdx
  signed __int64 v2; // rbx
  char *v3; // rax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v2 + 8)) )
  {
    v2 = (signed __int64)(i ? &i[-1].mCount : 0i64);
    if ( !v2 )
      break;
    if ( !*(_DWORD *)(v2 + 64) )
    {
      if ( UFG::ConversationManager::sm_debugScrConversations )
      {
        v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(*(_QWORD *)(v2 + 176) + 72i64));
        UFG::qPrintf(
          "CONV DEBUG: %s : %6u : Forcing Finish '%s'\n",
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
  signed __int64 v2; // rbx

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v2 + 8)) )
  {
    v2 = (signed __int64)(i ? &i[-1].mCount : 0i64);
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
__int64 __fastcall UFG::ConversationManager::InterruptPlayerConversations(UFG::eInterruptType intType, bool force, UFG::SimObject *ignore)
{
  UFG::SimObject *v3; // rbx
  bool v4; // di
  UFG::eInterruptType v5; // esi
  UFG::SimObjectCharacter *v6; // rax

  v3 = ignore;
  v4 = force;
  v5 = intType;
  v6 = UFG::GetLocalPlayer();
  return UFG::ConversationManager::InterruptConversationsWithCharacter((UFG::SimObject *)&v6->vfptr, v5, v4, v3);
}

// File Line: 4100
// RVA: 0x5A0130
__int64 __fastcall UFG::ConversationManager::InterruptConversationsWithCharacter(UFG::SimObject *character, UFG::eInterruptType intType, bool force, UFG::SimObject *ignore)
{
  UFG::SimObject *v4; // rbp
  UFG::SimObject *v5; // rsi
  bool v6; // r14
  UFG::eInterruptType v7; // er15
  unsigned __int8 v8; // di
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v10; // rbx
  signed __int64 v11; // r9
  signed __int64 v12; // rcx
  signed __int64 v13; // rax
  __int64 v14; // rdx
  UFG::SimObject *v15; // r8
  signed __int64 v16; // rax
  __int64 v17; // rdx
  UFG::SimObject *v18; // r8
  signed __int64 v19; // rax
  __int64 v20; // rdx
  UFG::SimObject *v21; // r8
  __int64 v22; // rax
  UFG::SimObject *v23; // rdx

  v4 = character;
  v5 = ignore;
  v6 = force;
  v7 = intType;
  v8 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v10 + 8)) )
  {
    v10 = (signed __int64)(i ? &i[-1].mCount : 0i64);
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
            v18 = (UFG::SimObject *)(v17 ? *(_QWORD *)(v17 + 40) : 0i64);
            if ( v18 == v4 )
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
            v15 = (UFG::SimObject *)(v14 ? *(_QWORD *)(v14 + 40) : 0i64);
            if ( v15 == v4 )
              break;
            v13 = *(_QWORD *)(v13 + 16) - 8i64;
            if ( v13 == v11 )
              goto LABEL_14;
          }
        }
        if ( v5 && (v19 = *(_QWORD *)(v10 + 80) - 8i64, v12 != v11) )
        {
          while ( 1 )
          {
            v20 = *(_QWORD *)(v19 + 104);
            v21 = (UFG::SimObject *)(v20 ? *(_QWORD *)(v20 + 40) : 0i64);
            if ( v21 == v5 )
              break;
            v19 = *(_QWORD *)(v19 + 16) - 8i64;
            if ( v19 == v11 )
            {
              if ( v12 == v11 )
                goto LABEL_34;
              while ( 1 )
              {
                v22 = *(_QWORD *)(v12 + 128);
                v23 = (UFG::SimObject *)(v22 ? *(_QWORD *)(v22 + 40) : 0i64);
                if ( v23 == v5 )
                  goto LABEL_35;
                v12 = *(_QWORD *)(v12 + 16) - 8i64;
                if ( v12 == v11 )
                  goto LABEL_34;
              }
            }
          }
        }
        else
        {
LABEL_34:
          UFG::Conversation::Interrupt((UFG::Conversation *)v10, v7, v6);
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
  UFG::eInterruptType v1; // ebx
  UFG::SimObjectCharacter *v2; // rax

  v1 = intType;
  v2 = UFG::GetLocalPlayer();
  return UFG::ConversationManager::ResumeConversationsWithCharacter((UFG::SimObject *)&v2->vfptr, v1);
}

// File Line: 4147
// RVA: 0x5AA730
__int64 __fastcall UFG::ConversationManager::ResumeConversationsWithCharacter(UFG::SimObject *character, UFG::eInterruptType intType)
{
  UFG::SimObject *v2; // rbx
  UFG::eInterruptType v3; // esi
  unsigned __int8 v4; // di
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v6; // r10
  signed __int64 v7; // r9
  signed __int64 v8; // rax
  signed __int64 v9; // rcx
  __int64 v10; // rdx
  UFG::SimObject *v11; // r8
  __int64 v12; // rcx
  UFG::SimObject *v13; // rdx

  v2 = character;
  v3 = intType;
  v4 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::ConversationManager::sm_conversationDb);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::ConversationManager::sm_conversationDb.mTree, (UFG::qBaseNodeRB *)(v6 + 8)) )
  {
    v6 = (signed __int64)(i ? &i[-1].mCount : 0i64);
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
            v11 = (UFG::SimObject *)(v10 ? *(_QWORD *)(v10 + 40) : 0i64);
            if ( v11 == v2 )
              break;
            v9 = *(_QWORD *)(v9 + 16) - 8i64;
            if ( v9 == v7 )
            {
              if ( v8 == v7 )
                goto LABEL_24;
              while ( 1 )
              {
                v12 = *(_QWORD *)(v8 + 128);
                v13 = (UFG::SimObject *)(v12 ? *(_QWORD *)(v12 + 40) : 0i64);
                if ( v13 == v2 )
                  goto LABEL_21;
                v8 = *(_QWORD *)(v8 + 16) - 8i64;
                if ( v8 == v7 )
                  goto LABEL_24;
              }
            }
          }
LABEL_21:
          if ( v3 == *(_DWORD *)(v6 + 148) )
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

