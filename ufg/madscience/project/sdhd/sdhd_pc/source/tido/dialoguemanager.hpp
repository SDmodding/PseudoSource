// File Line: 111
// RVA: 0x4CB470
void __fastcall UFG::ConversationElement::ConversationElement(
        UFG::ConversationElement *this,
        UFG::ConversationElement::eConversationElementType type)
{
  this->mPrev = &this->UFG::qNode<UFG::ConversationElement,UFG::ConversationElement>;
  this->mNext = &this->UFG::qNode<UFG::ConversationElement,UFG::ConversationElement>;
  this->vfptr = (UFG::ConversationElementVtbl *)&UFG::ConversationElement::`vftable;
  this->m_playbackEvent.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  UFG::qString::qString(&this->m_context);
  this->m_spkAac.mPrev = &this->m_spkAac;
  this->m_spkAac.mNext = &this->m_spkAac;
  this->m_spkAac.m_pPointer = 0i64;
  this->m_tgtAac.mPrev = &this->m_tgtAac;
  this->m_tgtAac.mNext = &this->m_tgtAac;
  this->m_tgtAac.m_pPointer = 0i64;
  this->m_interruptionPoints.mNode.mPrev = &this->m_interruptionPoints.mNode;
  this->m_interruptionPoints.mNode.mNext = &this->m_interruptionPoints.mNode;
  this->m_type = type;
  UFG::ConversationElement::NullifyMembers(this);
}

// File Line: 116
// RVA: 0x4CBBC0
void __fastcall UFG::ConversationElement::~ConversationElement(UFG::ConversationElement *this)
{
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *p_m_interruptionPoints; // rbx
  UFG::SimComponent **p_mNext; // rax
  UFG::SimComponent **i; // rsi
  _QWORD *v5; // rdx
  UFG::SimComponent *v6; // rcx
  UFG::SimComponent *v7; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mPrev; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *p_m_tgtAac; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *p_m_spkAac; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v20; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v21; // rax

  this->vfptr = (UFG::ConversationElementVtbl *)&UFG::ConversationElement::`vftable;
  p_m_interruptionPoints = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_interruptionPoints;
  p_mNext = (UFG::SimComponent **)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
  for ( i = &this->m_tgtAac.m_pPointer;
        p_mNext != i;
        p_mNext = (UFG::SimComponent **)&p_m_interruptionPoints->mNode.mNext[-1].mNext )
  {
    v5 = p_mNext + 1;
    v6 = p_mNext[1];
    v7 = p_mNext[2];
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v7;
    v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v6;
    *v5 = v5;
    v5[1] = v5;
    if ( v5 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v5 - 1))(v5 - 1, 1i64);
  }
  UFG::ConversationElement::NullifyMembers(this);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(p_m_interruptionPoints);
  mPrev = p_m_interruptionPoints->mNode.mPrev;
  mNext = p_m_interruptionPoints->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_interruptionPoints->mNode.mPrev = &p_m_interruptionPoints->mNode;
  p_m_interruptionPoints->mNode.mNext = &p_m_interruptionPoints->mNode;
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
  v13 = p_m_tgtAac->mPrev;
  v14 = this->m_tgtAac.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_m_tgtAac->mPrev = p_m_tgtAac;
  this->m_tgtAac.mNext = &this->m_tgtAac;
  p_m_spkAac = &this->m_spkAac;
  if ( this->m_spkAac.m_pPointer )
  {
    v16 = p_m_spkAac->mPrev;
    v17 = this->m_spkAac.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_m_spkAac->mPrev = p_m_spkAac;
    this->m_spkAac.mNext = &this->m_spkAac;
  }
  this->m_spkAac.m_pPointer = 0i64;
  v18 = p_m_spkAac->mPrev;
  v19 = this->m_spkAac.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  p_m_spkAac->mPrev = p_m_spkAac;
  this->m_spkAac.mNext = &this->m_spkAac;
  UFG::qString::~qString(&this->m_context);
  _((AMD_HD3D *)this->m_playbackEvent.mUID);
  v20 = this->mPrev;
  v21 = this->mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  this->mPrev = &this->UFG::qNode<UFG::ConversationElement,UFG::ConversationElement>;
  this->mNext = &this->UFG::qNode<UFG::ConversationElement,UFG::ConversationElement>;
}

// File Line: 184
// RVA: 0x59D570
UFG::qBaseNodeRB *__fastcall UFG::ConversationElement::GetSpeaker(UFG::ConversationElement *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->m_spkAac.m_pPointer;
  if ( result )
    return result[1].mChild[0];
  return result;
}

// File Line: 185
// RVA: 0x59D6C0
UFG::qBaseNodeRB *__fastcall UFG::ConversationElement::GetTarget(UFG::ConversationElement *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->m_tgtAac.m_pPointer;
  if ( result )
    return result[1].mChild[0];
  return result;
}

// File Line: 212
// RVA: 0x4CB580
void __fastcall UFG::ScriptedConversationElement::ScriptedConversationElement(
        UFG::ScriptedConversationElement *this,
        ASymbol *symbol)
{
  UFG::ConversationElement::ConversationElement(this, eConversationElementType_Scripted);
  this->vfptr = (UFG::ConversationElementVtbl *)&UFG::ScriptedConversationElement::`vftable;
  this->m_script = 0i64;
  this->m_nonCharInfo = 0i64;
  this->m_instSpk = 0i64;
  this->m_instTgt = 0i64;
  UFG::ScriptedConversationElement::SetupScript(this, symbol);
}

// File Line: 325
// RVA: 0x5943B0
void __fastcall UFG::ConversationElementInterruption::~ConversationElementInterruption(
        UFG::ConversationElementInterruption *this)
{
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v1; // rdx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mPrev; // rcx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *mNext; // rax

  this->vfptr = (UFG::ConversationElementInterruptionVtbl *)&UFG::ConversationElementInterruption::`vftable;
  v1 = &this->UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 705
// RVA: 0x593110
void __fastcall UFG::AmbientConversationConfigurator::Context::Context(
        UFG::AmbientConversationConfigurator::Context *this)
{
  UFG::qList<UFG::AmbientConversationConfigurator::Action,UFG::AmbientConversationConfigurator::Action,1,0> *p_m_actions; // rbx
  __int64 i; // rax
  _QWORD *v3; // rdx
  __int64 v4; // rcx
  _QWORD *v5; // rax

  this->mPrev = &this->UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context>;
  this->mNext = &this->UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context>;
  this->vfptr = (UFG::AmbientConversationConfigurator::ContextVtbl *)&UFG::AmbientConversationConfigurator::Context::`vftable;
  this->m_weight = 0;
  p_m_actions = &this->m_actions;
  this->m_actions.mNode.mPrev = &this->m_actions.mNode;
  this->m_actions.mNode.mNext = &this->m_actions.mNode;
  UFG::qString::qString(&this->m_contextStr, &customCaption);
  for ( i = (__int64)&p_m_actions->mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::AmbientConversationConfigurator::Action,UFG::AmbientConversationConfigurator::Action> **)i != &p_m_actions[-1].mNode.mNext;
        i = (__int64)&p_m_actions->mNode.mNext[-1].mNext )
  {
    v3 = (_QWORD *)(i + 8);
    v4 = *(_QWORD *)(i + 8);
    v5 = *(_QWORD **)(i + 16);
    *(_QWORD *)(v4 + 8) = v5;
    *v5 = v4;
    *v3 = v3;
    v3[1] = v3;
  }
}

// File Line: 709
// RVA: 0x594230
void __fastcall UFG::AmbientConversationConfigurator::Context::~Context(
        UFG::AmbientConversationConfigurator::Context *this)
{
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *p_m_actions; // rbx
  unsigned int *p_mNext; // rax
  unsigned int *i; // rdi
  _QWORD *v5; // rdx
  __int64 v6; // rcx
  _QWORD *v7; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mPrev; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mNext; // rax
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *v10; // rcx
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *v11; // rax

  this->vfptr = (UFG::AmbientConversationConfigurator::ContextVtbl *)&UFG::AmbientConversationConfigurator::Context::`vftable;
  p_m_actions = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_actions;
  p_mNext = (unsigned int *)&this->m_actions.mNode.mNext[-1].mNext;
  for ( i = &this->m_weight; p_mNext != i; p_mNext = (unsigned int *)&p_m_actions->mNode.mNext[-1].mNext )
  {
    v5 = p_mNext + 2;
    v6 = *((_QWORD *)p_mNext + 1);
    v7 = (_QWORD *)*((_QWORD *)p_mNext + 2);
    *(_QWORD *)(v6 + 8) = v7;
    *v7 = v6;
    *v5 = v5;
    v5[1] = v5;
    if ( v5 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v5 - 1))(v5 - 1, 1i64);
  }
  UFG::qString::~qString(&this->m_contextStr);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(p_m_actions);
  mPrev = p_m_actions->mNode.mPrev;
  mNext = p_m_actions->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_actions->mNode.mPrev = &p_m_actions->mNode;
  p_m_actions->mNode.mNext = &p_m_actions->mNode;
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = &this->UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context>;
  this->mNext = &this->UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context>;
}

// File Line: 850
// RVA: 0x52C120
UFG::Conversation *__fastcall UFG::ConversationManager::GetConversation(unsigned int uid)
{
  UFG::qBaseTreeRB *v1; // rax

  if ( uid && (v1 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, uid)) != 0i64 )
    return (UFG::Conversation *)&v1[-1].mCount;
  else
    return 0i64;
}

