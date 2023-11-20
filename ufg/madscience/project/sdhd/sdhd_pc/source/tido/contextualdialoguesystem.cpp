// File Line: 19
// RVA: 0x1554E50
__int64 dynamic_initializer_for__UFG::ContextualDialogueManager::sm_rules__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ContextualDialogueManager::sm_rules__);
}

// File Line: 20
// RVA: 0x1554E20
__int64 dynamic_initializer_for__UFG::ContextualDialogueManager::sm_responses__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ContextualDialogueManager::sm_responses.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::ContextualDialogueManager::sm_responses__);
}

// File Line: 44
// RVA: 0x5A9240
void UFG::ContextualDialogueManager::ReadRules(void)
{
  UFG::qPropertyList *v0; // rdi
  unsigned int v1; // ebx
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // r14
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // ST30_8
  UFG::allocator::free_link *v6; // ST30_8
  UFG::qNode<UFG::Rule,UFG::Rule> **v7; // rcx
  UFG::qNode<UFG::Rule,UFG::Rule> *v8; // rax
  char *v9; // rax
  UFG::qPropertySet *v10; // rsi
  UFG::qSymbol *v11; // rbx
  UFG::qSymbol *v12; // rax
  UFG::qPropertySet *v13; // rdi
  UFG::qSymbol *v14; // rbx
  UFG::qSymbol *v15; // rax
  UFG::qPropertyList *v16; // rax
  UFG::qPropertyList *v17; // r13
  unsigned int v18; // eax
  unsigned int v19; // er12
  UFG::allocator::free_link *v20; // r15
  unsigned int v21; // er14
  UFG::allocator::free_link *v22; // rax
  UFG::allocator::free_link *v23; // rbx
  UFG::allocator::free_link *v24; // rax
  char *v25; // rax
  UFG::qPropertySet *v26; // rbp
  UFG::qSymbol *v27; // rsi
  UFG::qSymbol *v28; // rdi
  UFG::qPropertyList *v29; // [rsp+20h] [rbp-88h]
  UFG::qString str; // [rsp+38h] [rbp-70h]
  unsigned int v31; // [rsp+B0h] [rbp+8h]
  unsigned int v32; // [rsp+C0h] [rbp+18h]
  UFG::allocator::free_link *v33; // [rsp+C8h] [rbp+20h]

  v0 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         UFG::ContextualDialogueManager::sm_propertySet,
         (UFG::qSymbol *)&TiDoSym_rules.mUID,
         DEPTH_RECURSE);
  v29 = v0;
  v32 = v0->mNumElements;
  v1 = 0;
  v31 = 0;
  if ( v32 )
  {
    do
    {
      v2 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
      v3 = v2;
      v33 = v2;
      if ( v2 )
      {
        v4 = v2 + 1;
        v4->mNext = v4;
        v4[1].mNext = v4;
        v3->mNext = (UFG::allocator::free_link *)&UFG::Rule::`vftable;
        v3[3].mNext = (UFG::allocator::free_link *)-1i64;
        v5 = v3 + 4;
        v5->mNext = v5;
        v5[1].mNext = v5;
        LODWORD(v3[6].mNext) = -1;
        v6 = v3 + 7;
        v6->mNext = v6;
        v6[1].mNext = v6;
        v3[9].mNext = (UFG::allocator::free_link *)-1i64;
      }
      else
      {
        v3 = 0i64;
        v33 = 0i64;
      }
      v7 = (UFG::qNode<UFG::Rule,UFG::Rule> **)&v3[1];
      v8 = UFG::ContextualDialogueManager::sm_rules.mNode.mPrev;
      UFG::ContextualDialogueManager::sm_rules.mNode.mPrev->mNext = (UFG::qNode<UFG::Rule,UFG::Rule> *)&v3[1];
      *v7 = v8;
      v7[1] = (UFG::qNode<UFG::Rule,UFG::Rule> *)&UFG::ContextualDialogueManager::sm_rules;
      UFG::ContextualDialogueManager::sm_rules.mNode.mPrev = (UFG::qNode<UFG::Rule,UFG::Rule> *)&v3[1];
      v9 = UFG::qPropertyList::GetValuePtr(v0, 0x1Au, v1);
      if ( v9 && *(_QWORD *)v9 )
        v10 = (UFG::qPropertySet *)&v9[*(_QWORD *)v9];
      else
        v10 = 0i64;
      LODWORD(v3[3].mNext) = v10->mName.mUID;
      v11 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&TiDoSym_concept.mUID, DEPTH_RECURSE);
      v12 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&TiDoSym_response.mUID, DEPTH_RECURSE);
      HIDWORD(v3[3].mNext) = (UFG::qSymbol)v11->mUID;
      LODWORD(v3[6].mNext) = (UFG::qSymbol)v12->mUID;
      v13 = UFG::qPropertySet::Get<UFG::qPropertySet>(v10, (UFG::qSymbol *)&TiDoSym_apply.mUID, DEPTH_RECURSE);
      v14 = UFG::qPropertySet::Get<UFG::qSymbol>(v13, (UFG::qSymbol *)&TiDoSym_key.mUID, DEPTH_RECURSE);
      v15 = UFG::qPropertySet::Get<UFG::qSymbol>(v13, (UFG::qSymbol *)&TiDoSym_value.mUID, DEPTH_RECURSE);
      LODWORD(v3[9].mNext) = (UFG::qSymbol)v14->mUID;
      HIDWORD(v3[9].mNext) = (UFG::qSymbol)v15->mUID;
      v16 = UFG::qPropertySet::Get<UFG::qPropertyList>(v10, (UFG::qSymbol *)&TiDoSym_criteria.mUID, DEPTH_RECURSE);
      v17 = v16;
      v18 = v16->mNumElements;
      v19 = 0;
      if ( v18 )
      {
        v20 = v3 + 4;
        v21 = v18;
        do
        {
          v22 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
          v23 = v22;
          if ( v22 )
          {
            v22->mNext = v22;
            v22[1].mNext = v22;
            v22[2].mNext = (UFG::allocator::free_link *)-1i64;
          }
          else
          {
            v23 = 0i64;
          }
          v24 = v20->mNext;
          v24[1].mNext = v23;
          v23->mNext = v24;
          v23[1].mNext = v20;
          v20->mNext = v23;
          v25 = UFG::qPropertyList::GetValuePtr(v17, 0x1Au, v19);
          if ( v25 && *(_QWORD *)v25 )
            v26 = (UFG::qPropertySet *)&v25[*(_QWORD *)v25];
          else
            v26 = 0i64;
          v27 = UFG::qPropertySet::Get<UFG::qSymbol>(v26, (UFG::qSymbol *)&TiDoSym_key.mUID, DEPTH_RECURSE);
          v28 = UFG::qPropertySet::Get<UFG::qSymbol>(v26, (UFG::qSymbol *)&TiDoSym_value.mUID, DEPTH_RECURSE);
          UFG::qPropertySet::GetPropertyTypeFromName(v26, (UFG::qSymbol *)&TiDoSym_value.mUID, 0);
          LODWORD(v23[2].mNext) = (UFG::qSymbol)v27->mUID;
          HIDWORD(v23[2].mNext) = (UFG::qSymbol)v28->mUID;
          ++v19;
        }
        while ( v19 < v21 );
        v3 = v33;
      }
      UFG::qString::qString(&str);
      UFG::Rule::ToString((UFG::Rule *)v3, &str);
      UFG::qString::~qString(&str);
      v1 = v31 + 1;
      v31 = v1;
      v0 = v29;
    }
    while ( v1 < v32 );
  }
}

// File Line: 103
// RVA: 0x5A8FE0
void UFG::ContextualDialogueManager::ReadResponses(void)
{
  UFG::qPropertyList *v0; // r13
  UFG::qPropertySet *v1; // rdi
  unsigned int v2; // er12
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rbx
  char *v5; // rax
  UFG::qSymbolUC *v6; // r15
  unsigned int v7; // eax
  UFG::qWiseSymbol *v8; // rax
  UFG::qWiseSymbol *v9; // r14
  UFG::qPropertySet *v10; // rdi
  UFG::qWiseSymbol *v11; // rsi
  UFG::qSymbol *v12; // rdi
  UFG::qWiseSymbol *v13; // rbp
  char *v14; // rbx
  const char *v15; // rax
  const char *v16; // rbx
  char *v17; // rax
  UFG::qString v18; // [rsp+38h] [rbp-90h]
  UFG::qString v19; // [rsp+60h] [rbp-68h]
  unsigned int v20; // [rsp+D0h] [rbp+8h]

  v0 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         UFG::ContextualDialogueManager::sm_propertySet,
         (UFG::qSymbol *)&TiDoSym_responses.mUID,
         DEPTH_RECURSE);
  v20 = v0->mNumElements;
  v1 = 0i64;
  v2 = 0;
  if ( v20 )
  {
    do
    {
      v3 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
      v4 = v3;
      if ( v3 )
      {
        v3[1].mNext = 0i64;
        v3[2].mNext = 0i64;
        v3[3].mNext = 0i64;
        v3->mNext = (UFG::allocator::free_link *)&UFG::Response::`vftable;
        v3[5].mNext = (UFG::allocator::free_link *)-1i64;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        LODWORD(v4[6].mNext) = -1;
        _((AMD_HD3D *)0xFFFFFFFFi64);
        HIDWORD(v4[6].mNext) = -1;
        v1 = 0i64;
      }
      else
      {
        v4 = 0i64;
      }
      v5 = UFG::qPropertyList::GetValuePtr(v0, 0x1Au, v2);
      if ( v5 )
      {
        if ( *(_QWORD *)v5 )
          v1 = (UFG::qPropertySet *)&v5[*(_QWORD *)v5];
      }
      v6 = (UFG::qSymbolUC *)&v4[5];
      v7 = v1->mName.mUID;
      LODWORD(v4[5].mNext) = v7;
      LODWORD(v4[4].mNext) = v7;
      UFG::qBaseTreeRB::Add(&UFG::ContextualDialogueManager::sm_responses.mTree, (UFG::qBaseNodeRB *)&v4[1]);
      v8 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v1, (UFG::qSymbol *)&TiDoSym_line.mUID, DEPTH_RECURSE);
      v9 = (UFG::qWiseSymbol *)((char *)&v4[5].mNext + 4);
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v4[5].mNext + 1, v8);
      v10 = UFG::qPropertySet::Get<UFG::qPropertySet>(v1, (UFG::qSymbol *)&TiDoSym_then.mUID, DEPTH_RECURSE);
      v11 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v10, (UFG::qSymbol *)&TiDoSym_character.mUID, DEPTH_RECURSE);
      v12 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&TiDoSym_concept.mUID, DEPTH_RECURSE);
      v13 = (UFG::qWiseSymbol *)&v4[6];
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v4[6], v11);
      HIDWORD(v4[6].mNext) = (UFG::qSymbol)v12->mUID;
      UFG::qString::qString(&v19);
      UFG::qString::qString(&v18);
      v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4[6].mNext + 1);
      v15 = UFG::qWiseSymbol::as_cstr_dbg(v13);
      UFG::qString::Format(&v18, "char: %s \tconc: %s\n", v15, v14);
      v16 = UFG::qWiseSymbol::as_cstr_dbg(v9);
      v17 = UFG::qSymbol::as_cstr_dbg(v6);
      UFG::qString::Format(&v19, "name:     %s\nline:  %s \nthen: %s \n", v17, v16, v18.mData);
      UFG::qString::~qString(&v18);
      UFG::qString::~qString(&v19);
      ++v2;
      v1 = 0i64;
    }
    while ( v2 < v20 );
  }
}

// File Line: 135
// RVA: 0x59B970
void __fastcall UFG::ContextualDialogueManager::ExecuteQuery(UFG::Query *query)
{
  UFG::Query *v1; // rsi
  signed int v2; // edi
  signed __int64 v3; // r15
  UFG::Rule *v4; // rbp
  UFG::Rule *v5; // rbx
  int v6; // eax
  unsigned int v7; // edx
  UFG::qBaseTreeRB *v8; // rax
  char *v9; // rdi
  const char *v10; // rax
  const char *v11; // rbx
  char *v12; // rax
  UFG::qSymbol *v13; // rax
  UFG::SimObjectCharacter *v14; // rax
  unsigned __int16 v15; // dx
  UFG::ActorAudioComponent *v16; // rax
  UFG::ActorAudioComponent *v17; // rdi
  unsigned int v18; // ebx
  unsigned int v19; // eax
  UFG::qString v20; // [rsp+38h] [rbp-90h]
  UFG::qString v21; // [rsp+60h] [rbp-68h]
  UFG::qString str; // [rsp+88h] [rbp-40h]
  UFG::qSymbol result; // [rsp+D8h] [rbp+10h]

  v1 = query;
  UFG::qString::qString(&str);
  UFG::Query::ToString(v1, &str);
  v2 = -1;
  v3 = 0i64;
  v4 = 0i64;
  v5 = (UFG::Rule *)&UFG::ContextualDialogueManager::sm_rules.mNode.mNext[-1].mNext;
  if ( &UFG::ContextualDialogueManager::sm_rules.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Rule,UFG::Rule> **)((char *)&UFG::ContextualDialogueManager::sm_rules - 8) )
  {
    do
    {
      if ( v5->m_concept.mUID == v1->m_concept.mUID )
      {
        v6 = UFG::ContextualDialogueManager::Match(v1, v5);
        if ( v6 > v2 )
        {
          v2 = v6;
          v4 = v5;
        }
      }
      v5 = (UFG::Rule *)&v5->mNext[-1].mNext;
    }
    while ( v5 != (UFG::Rule *)((char *)&UFG::ContextualDialogueManager::sm_rules - 8) );
    if ( v4 )
    {
      v7 = v4->m_response.mUID;
      if ( v7 )
      {
        v8 = UFG::qBaseTreeRB::Get(&UFG::ContextualDialogueManager::sm_responses.mTree, v7);
        if ( v8 )
          v3 = (signed __int64)&v8[-1].mCount;
      }
      UFG::qString::qString(&v21);
      UFG::qString::qString(&v20);
      v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v3 + 52));
      v10 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)(v3 + 48));
      UFG::qString::Format(&v20, "char: %s \tconc: %s\n", v10, v9);
      v11 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)(v3 + 44));
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v3 + 40));
      UFG::qString::Format(&v21, "name:     %s\nline:  %s \nthen: %s \n", v12, v11, v20.mData);
      UFG::qString::~qString(&v20);
      v13 = UFG::Query::FindCharacter(v1, &result);
      v14 = (UFG::SimObjectCharacter *)UFG::Simulation::GetSimObject(&UFG::gSim, v13);
      if ( v14 )
      {
        v15 = v14->m_Flags;
        if ( (v15 >> 14) & 1 )
        {
          v16 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v14);
        }
        else if ( (v15 & 0x8000u) == 0 )
        {
          if ( (v15 >> 13) & 1 )
          {
            v16 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v14->vfptr,
                                                UFG::ActorAudioComponent::_TypeUID);
          }
          else if ( (v15 >> 12) & 1 )
          {
            v16 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v14->vfptr,
                                                UFG::ActorAudioComponent::_TypeUID);
          }
          else
          {
            v16 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v14->vfptr,
                                                UFG::ActorAudioComponent::_TypeUID);
          }
        }
        else
        {
          v16 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v14->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
        v17 = v16;
        if ( v16 )
        {
          v18 = *(_DWORD *)(v3 + 44);
          v19 = UFG::TiDo::CalcWwiseUid("play_mission");
          UFG::ActorAudioComponent::QueueSpeechExternalMission(v17, v19, v18, 0i64, 5u, 0);
        }
      }
      UFG::qString::~qString(&v21);
    }
  }
  UFG::qString::~qString(&str);
}

// File Line: 178
// RVA: 0x5A31C0
__int64 __fastcall UFG::ContextualDialogueManager::Match(UFG::Query *query, UFG::Rule *rule)
{
  UFG::Rule *v2; // r13
  UFG::Rule *v3; // rax
  unsigned int v4; // ebp
  UFG::qList<UFG::KeyValue,UFG::KeyValue,1,0> *v5; // r12
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v6; // rbx
  UFG::qSymbolUC *v7; // r14
  UFG::qSymbolUC *v8; // r13
  char *v9; // rdi
  char *v10; // rax
  char *v11; // rdi
  char *v12; // rax
  UFG::Query *v14; // [rsp+70h] [rbp+8h]
  UFG::Rule *v15; // [rsp+78h] [rbp+10h]
  UFG::qList<UFG::KeyValue,UFG::KeyValue,1,0> *v16; // [rsp+88h] [rbp+20h]

  v14 = query;
  v2 = (UFG::Rule *)rule->m_criteria.mNode.mNext;
  v3 = (UFG::Rule *)((char *)rule + 32);
  v4 = 0;
  v15 = v2;
  v16 = &rule->m_criteria;
  if ( v2 != (UFG::Rule *)&rule->m_criteria )
  {
    v5 = &query->m_facts;
    do
    {
      v6 = query->m_facts.mNode.mNext;
      if ( v6 != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v5 )
      {
        v7 = (UFG::qSymbolUC *)((char *)&v2->mNext + 4);
        v8 = (UFG::qSymbolUC *)&v2->mNext;
        do
        {
          v9 = UFG::qSymbol::as_cstr_dbg(v7);
          v10 = UFG::qSymbol::as_cstr_dbg(v8);
          UFG::qPrintf("Match rule: %s \t%s\n", v10, v9);
          v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6[1].mPrev + 1);
          v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6[1]);
          UFG::qPrintf("Match quer: %s \t%s\n", v12, v11);
          if ( v8->mUID == LODWORD(v6[1].mPrev) )
            v4 += v7->mUID == HIDWORD(v6[1].mPrev);
          v6 = v6->mNext;
        }
        while ( v6 != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v5 );
        v2 = v15;
        v3 = (UFG::Rule *)v16;
        query = v14;
      }
      v2 = (UFG::Rule *)v2->mPrev;
      v15 = v2;
    }
    while ( v2 != v3 );
  }
  return v4;
}

// File Line: 201
// RVA: 0x593560
void __fastcall UFG::Query::Query(UFG::Query *this)
{
  UFG::qList<UFG::KeyValue,UFG::KeyValue,1,0> *v1; // r8
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v2; // rax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v3; // rdx
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v4; // rcx

  this->vfptr = (UFG::QueryVtbl *)&UFG::Query::`vftable;
  this->m_character = UFG::gNullQSymbol;
  this->m_concept = UFG::gNullQSymbol;
  v1 = &this->m_facts;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
  v2 = this->m_facts.mNode.mNext;
  if ( v2 != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&this->m_facts )
  {
    do
    {
      v3 = v2->mPrev;
      v4 = v2->mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->mPrev = v2;
      v2->mNext = v2;
      v2 = v1->mNode.mNext;
    }
    while ( v2 != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v1 );
  }
}

// File Line: 206
// RVA: 0x5947F0
void __fastcall UFG::Query::~Query(UFG::Query *this)
{
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v1; // rbx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v2; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v3; // rax

  this->vfptr = (UFG::QueryVtbl *)&UFG::Query::`vftable;
  v1 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_facts;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_facts);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(v1);
  v2 = v1->mNode.mPrev;
  v3 = v1->mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 211
// RVA: 0x59BD90
UFG::qSymbol *__fastcall UFG::Query::FindCharacter(UFG::Query *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx
  UFG::Query *v3; // rdi
  unsigned int v4; // eax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v5; // rdx

  v2 = result;
  v3 = this;
  if ( !(_S46_0 & 1) )
  {
    _S46_0 |= 1u;
    UFG::qSymbol::create_from_string(&characterSym, "character");
    atexit(UFG::Query::FindCharacter_::_2_::_dynamic_atexit_destructor_for__characterSym__);
  }
  v4 = v3->m_character.mUID;
  if ( v4 == UFG::gNullQSymbol.mUID )
  {
    v5 = v3->m_facts.mNode.mNext;
    if ( v5 == (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&v3->m_facts )
    {
LABEL_10:
      v2->mUID = UFG::gNullQSymbol.mUID;
      return v2;
    }
    while ( LODWORD(v5[1].mPrev) != characterSym.mUID )
    {
      v5 = v5->mNext;
      if ( v5 == (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&v3->m_facts )
        goto LABEL_10;
    }
    v4 = HIDWORD(v5[1].mPrev);
  }
  v2->mUID = v4;
  return v2;
}

// File Line: 228
// RVA: 0x5ACDF0
void __fastcall UFG::Query::ToString(UFG::Query *this, UFG::qString *str)
{
  UFG::qString *v2; // r14
  UFG::Query *v3; // rsi
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *i; // rdi
  char *v5; // rbx
  char *v6; // rax
  char *v7; // rbx
  char *v8; // rax
  UFG::qString text; // [rsp+38h] [rbp-60h]
  UFG::qString v10; // [rsp+60h] [rbp-38h]

  v2 = str;
  v3 = this;
  UFG::qString::qString(&v10);
  for ( i = v3->m_facts.mNode.mNext; i != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&v3->m_facts; i = i->mNext )
  {
    UFG::qString::qString(&text);
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i[1].mPrev + 1);
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i[1]);
    UFG::qString::Format(&text, "k: %s \tv: %s\n", v6, v5);
    UFG::qString::operator+=(&v10, &text);
    UFG::qString::~qString(&text);
  }
  v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_character);
  v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_concept);
  UFG::qString::Format(v2, "\tconcept:     %s\n\tcharacter:  %s \nfacts:\n %s \n", v8, v7, v10.mData);
  UFG::qString::~qString(&v10);
}

// File Line: 241
// RVA: 0x5ACEF0
void __fastcall UFG::Rule::ToString(UFG::Rule *this, UFG::qString *str)
{
  UFG::qString *v2; // r14
  UFG::Rule *v3; // rbp
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *i; // rbx
  char *v5; // rdi
  char *v6; // rax
  char *v7; // rbx
  char *v8; // rax
  char *v9; // rsi
  char *v10; // rdi
  char *v11; // rbx
  char *v12; // rax
  UFG::qString text; // [rsp+48h] [rbp-80h]
  UFG::qString v14; // [rsp+70h] [rbp-58h]
  UFG::qString v15; // [rsp+98h] [rbp-30h]

  v2 = str;
  v3 = this;
  UFG::qString::qString(&v15);
  for ( i = v3->m_criteria.mNode.mNext; i != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&v3->m_criteria; i = i->mNext )
  {
    UFG::qString::qString(&text);
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i[1].mPrev + 1);
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i[1]);
    UFG::qString::Format(&text, "k: %s \tv: %s\n", v6, v5);
    UFG::qString::operator+=(&v15, &text);
    UFG::qString::~qString(&text);
  }
  UFG::qString::qString(&v14);
  v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_apply.m_value);
  v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_apply.m_key);
  UFG::qString::Format(&v14, "k: %s \tv: %s\n", v8, v7);
  v9 = v15.mData;
  v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_response);
  v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_concept);
  v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_name);
  UFG::qString::Format(
    v2,
    "name:     %s\nconcept:  %s \ncriteria: %s \nresponse: %s \napply:    %s\n",
    v12,
    v11,
    v9,
    v10,
    v14.mData);
  UFG::qString::~qString(&v14);
  UFG::qString::~qString(&v15);
}

