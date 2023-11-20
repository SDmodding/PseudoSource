// File Line: 111
// RVA: 0x4CB470
void __fastcall UFG::ConversationElement::ConversationElement(UFG::ConversationElement *this, UFG::ConversationElement::eConversationElementType type)
{
  UFG::ConversationElement::eConversationElementType v2; // ebx
  UFG::ConversationElement *v3; // rdi
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v5; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v6; // [rsp+50h] [rbp+18h]
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0> *v7; // [rsp+50h] [rbp+18h]

  v2 = type;
  v3 = this;
  v4 = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  this->vfptr = (UFG::ConversationElementVtbl *)&UFG::ConversationElement::`vftable;
  this->m_playbackEvent.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  UFG::qString::qString(&v3->m_context);
  v5 = &v3->m_spkAac;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v3->m_spkAac.m_pPointer = 0i64;
  v6 = &v3->m_tgtAac;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v3->m_tgtAac.m_pPointer = 0i64;
  v7 = &v3->m_interruptionPoints;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v3->m_type = v2;
  UFG::ConversationElement::NullifyMembers(v3);
}

// File Line: 116
// RVA: 0x4CBBC0
void __fastcall UFG::ConversationElement::~ConversationElement(UFG::ConversationElement *this)
{
  UFG::ConversationElement *v1; // rdi
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v2; // rbx
  UFG::SimComponent **v3; // rax
  UFG::SimComponent **v4; // rsi
  _QWORD *v5; // rdx
  UFG::SimComponent *v6; // rcx
  UFG::SimComponent *v7; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v8; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v20; // rdx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v21; // rcx
  UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *v22; // rax

  v1 = this;
  this->vfptr = (UFG::ConversationElementVtbl *)&UFG::ConversationElement::`vftable;
  v2 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_interruptionPoints;
  v3 = (UFG::SimComponent **)&this->m_interruptionPoints.mNode.mNext[-1].mNext;
  v4 = &this->m_tgtAac.m_pPointer;
  if ( v3 != &this->m_tgtAac.m_pPointer )
  {
    do
    {
      v5 = v3 + 1;
      v6 = v3[1];
      v7 = v3[2];
      v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v7;
      v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v6;
      *v5 = v5;
      v5[1] = v5;
      if ( v5 != (_QWORD *)8 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))*(v5 - 1))(v5 - 1, 1i64);
      v3 = (UFG::SimComponent **)&v2->mNode.mNext[-1].mNext;
    }
    while ( v3 != v4 );
  }
  UFG::ConversationElement::NullifyMembers(v1);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(v2);
  v8 = v2->mNode.mPrev;
  v9 = v2->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
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
  v13 = v10->mPrev;
  v14 = v1->m_tgtAac.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->m_tgtAac.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_tgtAac.mPrev;
  v15 = &v1->m_spkAac;
  if ( v1->m_spkAac.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v1->m_spkAac.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v1->m_spkAac.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_spkAac.mPrev;
  }
  v1->m_spkAac.m_pPointer = 0i64;
  v18 = v15->mPrev;
  v19 = v1->m_spkAac.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v1->m_spkAac.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_spkAac.mPrev;
  UFG::qString::~qString(&v1->m_context);
  _((AMD_HD3D *)v1->m_playbackEvent.mUID);
  v20 = (UFG::qNode<UFG::ConversationElement,UFG::ConversationElement> *)&v1->mPrev;
  v21 = v1->mPrev;
  v22 = v1->mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v20->mPrev = v20;
  v20->mNext = v20;
}

// File Line: 184
// RVA: 0x59D570
UFG::SimObject *__fastcall UFG::ConversationElement::GetSpeaker(UFG::ConversationElement *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->m_spkAac.m_pPointer;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

// File Line: 185
// RVA: 0x59D6C0
UFG::SimObject *__fastcall UFG::ConversationElement::GetTarget(UFG::ConversationElement *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->m_tgtAac.m_pPointer;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

// File Line: 212
// RVA: 0x4CB580
void __fastcall UFG::ScriptedConversationElement::ScriptedConversationElement(UFG::ScriptedConversationElement *this, ASymbol *symbol)
{
  ASymbol *v2; // rbx
  UFG::ScriptedConversationElement *v3; // rdi

  v2 = symbol;
  v3 = this;
  UFG::ConversationElement::ConversationElement((UFG::ConversationElement *)&this->vfptr, 0);
  v3->vfptr = (UFG::ConversationElementVtbl *)&UFG::ScriptedConversationElement::`vftable;
  v3->m_script = 0i64;
  v3->m_nonCharInfo = 0i64;
  v3->m_instSpk = 0i64;
  v3->m_instTgt = 0i64;
  UFG::ScriptedConversationElement::SetupScript(v3, v2);
}

// File Line: 325
// RVA: 0x5943B0
void __fastcall UFG::ConversationElementInterruption::~ConversationElementInterruption(UFG::ConversationElementInterruption *this)
{
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v1; // rdx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v2; // rcx
  UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *v3; // rax

  this->vfptr = (UFG::ConversationElementInterruptionVtbl *)&UFG::ConversationElementInterruption::`vftable;
  v1 = (UFG::qNode<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 705
// RVA: 0x593110
void __fastcall UFG::AmbientConversationConfigurator::Context::Context(UFG::AmbientConversationConfigurator::Context *this)
{
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *v1; // rax
  UFG::qList<UFG::AmbientConversationConfigurator::Action,UFG::AmbientConversationConfigurator::Action,1,0> *v2; // rbx
  signed __int64 i; // rax
  _QWORD *v4; // rdx
  __int64 v5; // rcx
  _QWORD *v6; // rax

  v1 = (UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::AmbientConversationConfigurator::ContextVtbl *)&UFG::AmbientConversationConfigurator::Context::`vftable;
  this->m_weight = 0;
  v2 = &this->m_actions;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qString::qString(&this->m_contextStr, &customWorldMapCaption);
  for ( i = (signed __int64)&v2->mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::AmbientConversationConfigurator::Action,UFG::AmbientConversationConfigurator::Action> **)i != &v2[-1].mNode.mNext;
        i = (signed __int64)&v2->mNode.mNext[-1].mNext )
  {
    v4 = (_QWORD *)(i + 8);
    v5 = *(_QWORD *)(i + 8);
    v6 = *(_QWORD **)(i + 16);
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *v4 = v4;
    v4[1] = v4;
  }
}

// File Line: 709
// RVA: 0x594230
void __fastcall UFG::AmbientConversationConfigurator::Context::~Context(UFG::AmbientConversationConfigurator::Context *this)
{
  UFG::AmbientConversationConfigurator::Context *v1; // rsi
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v2; // rbx
  unsigned int *v3; // rax
  unsigned int *v4; // rdi
  _QWORD *v5; // rdx
  __int64 v6; // rcx
  _QWORD *v7; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v8; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v9; // rax
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *v10; // rdx
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *v11; // rcx
  UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::AmbientConversationConfigurator::ContextVtbl *)&UFG::AmbientConversationConfigurator::Context::`vftable;
  v2 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_actions;
  v3 = (unsigned int *)&this->m_actions.mNode.mNext[-1].mNext;
  v4 = &this->m_weight;
  if ( v3 != &this->m_weight )
  {
    do
    {
      v5 = v3 + 2;
      v6 = *((_QWORD *)v3 + 1);
      v7 = (_QWORD *)*((_QWORD *)v3 + 2);
      *(_QWORD *)(v6 + 8) = v7;
      *v7 = v6;
      *v5 = v5;
      v5[1] = v5;
      if ( v5 != (_QWORD *)8 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))*(v5 - 1))(v5 - 1, 1i64);
      v3 = (unsigned int *)&v2->mNode.mNext[-1].mNext;
    }
    while ( v3 != v4 );
  }
  UFG::qString::~qString(&v1->m_contextStr);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(v2);
  v8 = v2->mNode.mPrev;
  v9 = v2->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v10 = (UFG::qNode<UFG::AmbientConversationConfigurator::Context,UFG::AmbientConversationConfigurator::Context> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
}

// File Line: 850
// RVA: 0x52C120
UFG::Conversation *__fastcall UFG::ConversationManager::GetConversation(unsigned int uid)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::Conversation *result; // rax

  if ( uid && (v1 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, uid)) != 0i64 )
    result = (UFG::Conversation *)&v1[-1].mCount;
  else
    result = 0i64;
  return result;
}

