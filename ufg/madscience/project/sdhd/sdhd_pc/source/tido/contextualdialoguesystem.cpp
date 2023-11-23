// File Line: 19
// RVA: 0x1554E50
__int64 dynamic_initializer_for__UFG::ContextualDialogueManager::sm_rules__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ContextualDialogueManager::sm_rules__);
}

// File Line: 20
// RVA: 0x1554E20
__int64 dynamic_initializer_for__UFG::ContextualDialogueManager::sm_responses__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ContextualDialogueManager::sm_responses.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ContextualDialogueManager::sm_responses__);
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
  UFG::qNode<UFG::Rule,UFG::Rule> *mPrev; // rax
  char *ValuePtr; // rax
  UFG::qPropertySet *v7; // rsi
  UFG::qSymbol *v8; // rbx
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *v10; // rdi
  UFG::qSymbol *v11; // rbx
  UFG::qSymbol *v12; // rax
  UFG::qPropertyList *v13; // r13
  unsigned int v14; // r12d
  UFG::allocator::free_link *v15; // r15
  unsigned int v16; // r14d
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rbx
  UFG::allocator::free_link *mNext; // rax
  char *v20; // rax
  UFG::qPropertySet *v21; // rbp
  UFG::qSymbol *v22; // rsi
  UFG::qSymbol *v23; // rdi
  UFG::qPropertyList *v24; // [rsp+20h] [rbp-88h]
  UFG::qString str; // [rsp+38h] [rbp-70h] BYREF
  unsigned int i; // [rsp+B0h] [rbp+8h]
  unsigned int mNumElements; // [rsp+C0h] [rbp+18h]
  UFG::allocator::free_link *v28; // [rsp+C8h] [rbp+20h]

  v0 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         UFG::ContextualDialogueManager::sm_propertySet,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_rules,
         DEPTH_RECURSE);
  v24 = v0;
  mNumElements = v0->mNumElements;
  v1 = 0;
  for ( i = 0; v1 < mNumElements; v0 = v24 )
  {
    v2 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
    v3 = v2;
    v28 = v2;
    if ( v2 )
    {
      v4 = v2 + 1;
      v4->mNext = v4;
      v4[1].mNext = v4;
      v3->mNext = (UFG::allocator::free_link *)&UFG::Rule::`vftable;
      v3[3].mNext = (UFG::allocator::free_link *)-1i64;
      v3[4].mNext = v3 + 4;
      v3[5].mNext = v3 + 4;
      LODWORD(v3[6].mNext) = -1;
      v3[7].mNext = v3 + 7;
      v3[8].mNext = v3 + 7;
      v3[9].mNext = (UFG::allocator::free_link *)-1i64;
    }
    else
    {
      v3 = 0i64;
      v28 = 0i64;
    }
    mPrev = UFG::ContextualDialogueManager::sm_rules.mNode.mPrev;
    UFG::ContextualDialogueManager::sm_rules.mNode.mPrev->mNext = (UFG::qNode<UFG::Rule,UFG::Rule> *)&v3[1];
    v3[1].mNext = (UFG::allocator::free_link *)mPrev;
    v3[2].mNext = (UFG::allocator::free_link *)&UFG::ContextualDialogueManager::sm_rules;
    UFG::ContextualDialogueManager::sm_rules.mNode.mPrev = (UFG::qNode<UFG::Rule,UFG::Rule> *)&v3[1];
    ValuePtr = UFG::qPropertyList::GetValuePtr(v0, 0x1Au, v1);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v7 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v7 = 0i64;
    LODWORD(v3[3].mNext) = v7->mName.mUID;
    v8 = UFG::qPropertySet::Get<UFG::qSymbol>(v7, (UFG::qArray<unsigned long,0> *)&TiDoSym_concept, DEPTH_RECURSE);
    v9 = UFG::qPropertySet::Get<UFG::qSymbol>(v7, (UFG::qArray<unsigned long,0> *)&TiDoSym_response, DEPTH_RECURSE);
    HIDWORD(v3[3].mNext) = (UFG::qSymbol)v8->mUID;
    LODWORD(v3[6].mNext) = (UFG::qSymbol)v9->mUID;
    v10 = UFG::qPropertySet::Get<UFG::qPropertySet>(v7, (UFG::qArray<unsigned long,0> *)&TiDoSym_apply, DEPTH_RECURSE);
    v11 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qArray<unsigned long,0> *)&TiDoSym_key, DEPTH_RECURSE);
    v12 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qArray<unsigned long,0> *)&TiDoSym_value, DEPTH_RECURSE);
    LODWORD(v3[9].mNext) = (UFG::qSymbol)v11->mUID;
    HIDWORD(v3[9].mNext) = (UFG::qSymbol)v12->mUID;
    v13 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v7,
            (UFG::qArray<unsigned long,0> *)&TiDoSym_criteria,
            DEPTH_RECURSE);
    v14 = 0;
    if ( v13->mNumElements )
    {
      v15 = v3 + 4;
      v16 = v13->mNumElements;
      do
      {
        v17 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
        v18 = v17;
        if ( v17 )
        {
          v17->mNext = v17;
          v17[1].mNext = v17;
          v17[2].mNext = (UFG::allocator::free_link *)-1i64;
        }
        else
        {
          v18 = 0i64;
        }
        mNext = v15->mNext;
        mNext[1].mNext = v18;
        v18->mNext = mNext;
        v18[1].mNext = v15;
        v15->mNext = v18;
        v20 = UFG::qPropertyList::GetValuePtr(v13, 0x1Au, v14);
        if ( v20 && *(_QWORD *)v20 )
          v21 = (UFG::qPropertySet *)&v20[*(_QWORD *)v20];
        else
          v21 = 0i64;
        v22 = UFG::qPropertySet::Get<UFG::qSymbol>(v21, (UFG::qArray<unsigned long,0> *)&TiDoSym_key, DEPTH_RECURSE);
        v23 = UFG::qPropertySet::Get<UFG::qSymbol>(v21, (UFG::qArray<unsigned long,0> *)&TiDoSym_value, DEPTH_RECURSE);
        UFG::qPropertySet::GetPropertyTypeFromName(v21, (UFG::qArray<unsigned long,0> *)&TiDoSym_value, DEPTH_LOCAL);
        LODWORD(v18[2].mNext) = (UFG::qSymbol)v22->mUID;
        HIDWORD(v18[2].mNext) = (UFG::qSymbol)v23->mUID;
        ++v14;
      }
      while ( v14 < v16 );
      v3 = v28;
    }
    UFG::qString::qString(&str);
    UFG::Rule::ToString((UFG::Rule *)v3, &str);
    UFG::qString::~qString(&str);
    v1 = i + 1;
    i = v1;
  }
}

// File Line: 103
// RVA: 0x5A8FE0
void UFG::ContextualDialogueManager::ReadResponses(void)
{
  UFG::qPropertyList *v0; // r13
  UFG::qPropertySet *v1; // rdi
  unsigned int i; // r12d
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rbx
  char *ValuePtr; // rax
  UFG::qSymbolUC *v6; // r15
  unsigned int mUID; // eax
  UFG::qWiseSymbol *v8; // rax
  UFG::qWiseSymbol *v9; // r14
  UFG::qPropertySet *v10; // rdi
  UFG::qWiseSymbol *v11; // rsi
  UFG::qSymbol *v12; // rdi
  UFG::qWiseSymbol *v13; // rbp
  char *v14; // rbx
  char *v15; // rax
  char *v16; // rbx
  char *v17; // rax
  UFG::qString v18; // [rsp+38h] [rbp-90h] BYREF
  UFG::qString v19; // [rsp+60h] [rbp-68h] BYREF
  unsigned int mNumElements; // [rsp+D0h] [rbp+8h]

  v0 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         UFG::ContextualDialogueManager::sm_propertySet,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_responses,
         DEPTH_RECURSE);
  mNumElements = v0->mNumElements;
  v1 = 0i64;
  for ( i = 0; i < mNumElements; v1 = 0i64 )
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
    ValuePtr = UFG::qPropertyList::GetValuePtr(v0, 0x1Au, i);
    if ( ValuePtr )
    {
      if ( *(_QWORD *)ValuePtr )
        v1 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    }
    v6 = (UFG::qSymbolUC *)&v4[5];
    mUID = v1->mName.mUID;
    LODWORD(v4[5].mNext) = mUID;
    LODWORD(v4[4].mNext) = mUID;
    UFG::qBaseTreeRB::Add(&UFG::ContextualDialogueManager::sm_responses.mTree, (UFG::qBaseNodeRB *)&v4[1]);
    v8 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v1, (UFG::qArray<unsigned long,0> *)&TiDoSym_line, DEPTH_RECURSE);
    v9 = (UFG::qWiseSymbol *)&v4[5].mNext + 1;
    UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)&v4[5].mNext + 1, v8);
    v10 = UFG::qPropertySet::Get<UFG::qPropertySet>(v1, (UFG::qArray<unsigned long,0> *)&TiDoSym_then, DEPTH_RECURSE);
    v11 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
            v10,
            (UFG::qArray<unsigned long,0> *)&TiDoSym_character,
            DEPTH_RECURSE);
    v12 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qArray<unsigned long,0> *)&TiDoSym_concept, DEPTH_RECURSE);
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
    ++i;
  }
}

// File Line: 135
// RVA: 0x59B970
void __fastcall UFG::ContextualDialogueManager::ExecuteQuery(UFG::Query *query)
{
  int v2; // edi
  int *p_mCount; // r15
  UFG::Rule *v4; // rbp
  UFG::Rule *p_mNext; // rbx
  int v6; // eax
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v8; // rax
  char *v9; // rdi
  char *v10; // rax
  char *v11; // rbx
  char *v12; // rax
  UFG::qSymbol *Character; // rax
  UFG::SimObjectCharacter *SimObject; // rax
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  UFG::ActorAudioComponent *v17; // rdi
  unsigned int v18; // ebx
  unsigned int v19; // eax
  UFG::qString v20; // [rsp+38h] [rbp-90h] BYREF
  UFG::qString v21; // [rsp+60h] [rbp-68h] BYREF
  UFG::qString str; // [rsp+88h] [rbp-40h] BYREF
  UFG::qSymbol result; // [rsp+D8h] [rbp+10h] BYREF

  UFG::qString::qString(&str);
  UFG::Query::ToString(query, &str);
  v2 = -1;
  p_mCount = 0i64;
  v4 = 0i64;
  p_mNext = (UFG::Rule *)&UFG::ContextualDialogueManager::sm_rules.mNode.mNext[-1].mNext;
  if ( &UFG::ContextualDialogueManager::sm_rules.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Rule,UFG::Rule> **)((char *)&UFG::ContextualDialogueManager::sm_rules - 8) )
  {
    do
    {
      if ( p_mNext->m_concept.mUID == query->m_concept.mUID )
      {
        v6 = UFG::ContextualDialogueManager::Match(query, p_mNext);
        if ( v6 > v2 )
        {
          v2 = v6;
          v4 = p_mNext;
        }
      }
      p_mNext = (UFG::Rule *)&p_mNext->mNext[-1].mNext;
    }
    while ( p_mNext != (UFG::Rule *)((char *)&UFG::ContextualDialogueManager::sm_rules - 8) );
    if ( v4 )
    {
      mUID = v4->m_response.mUID;
      if ( mUID )
      {
        v8 = UFG::qBaseTreeRB::Get(&UFG::ContextualDialogueManager::sm_responses.mTree, mUID);
        if ( v8 )
          p_mCount = &v8[-1].mCount;
      }
      UFG::qString::qString(&v21);
      UFG::qString::qString(&v20);
      v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_mCount + 13);
      v10 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)p_mCount + 12);
      UFG::qString::Format(&v20, "char: %s \tconc: %s\n", v10, v9);
      v11 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)p_mCount + 11);
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_mCount + 10);
      UFG::qString::Format(&v21, "name:     %s\nline:  %s \nthen: %s \n", v12, v11, v20.mData);
      UFG::qString::~qString(&v20);
      Character = UFG::Query::FindCharacter(query, &result);
      SimObject = (UFG::SimObjectCharacter *)UFG::Simulation::GetSimObject(&UFG::gSim, Character);
      if ( SimObject )
      {
        m_Flags = SimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(SimObject);
        }
        else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            SimObject,
                                                            UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                            SimObject,
                                                            UFG::ActorAudioComponent::_TypeUID);
        }
        v17 = ComponentOfTypeHK;
        if ( ComponentOfTypeHK )
        {
          v18 = p_mCount[11];
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
  UFG::Rule *mNext; // r13
  UFG::qList<UFG::KeyValue,UFG::KeyValue,1,0> *p_m_criteria; // rax
  unsigned int v4; // ebp
  UFG::qList<UFG::KeyValue,UFG::KeyValue,1,0> *p_m_facts; // r12
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v6; // rbx
  UFG::qSymbolUC *v7; // r14
  UFG::qSymbolUC *p_mNext; // r13
  char *v9; // rdi
  char *v10; // rax
  char *v11; // rdi
  char *v12; // rax
  UFG::Query *v14; // [rsp+70h] [rbp+8h]
  UFG::Rule *v15; // [rsp+78h] [rbp+10h]
  UFG::qList<UFG::KeyValue,UFG::KeyValue,1,0> *v16; // [rsp+88h] [rbp+20h]

  v14 = query;
  mNext = (UFG::Rule *)rule->m_criteria.mNode.mNext;
  p_m_criteria = &rule->m_criteria;
  v4 = 0;
  v15 = mNext;
  v16 = &rule->m_criteria;
  if ( mNext != (UFG::Rule *)&rule->m_criteria )
  {
    p_m_facts = &query->m_facts;
    do
    {
      v6 = query->m_facts.mNode.mNext;
      if ( v6 != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)p_m_facts )
      {
        v7 = (UFG::qSymbolUC *)&mNext->mNext + 1;
        p_mNext = (UFG::qSymbolUC *)&mNext->mNext;
        do
        {
          v9 = UFG::qSymbol::as_cstr_dbg(v7);
          v10 = UFG::qSymbol::as_cstr_dbg(p_mNext);
          UFG::qPrintf("Match rule: %s \t%s\n", v10, v9);
          v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6[1].mPrev + 1);
          v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6[1]);
          UFG::qPrintf("Match quer: %s \t%s\n", v12, v11);
          if ( p_mNext->mUID == LODWORD(v6[1].mPrev) )
            v4 += v7->mUID == HIDWORD(v6[1].mPrev);
          v6 = v6->mNext;
        }
        while ( v6 != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)p_m_facts );
        mNext = v15;
        p_m_criteria = v16;
        query = v14;
      }
      mNext = (UFG::Rule *)mNext->mPrev;
      v15 = mNext;
    }
    while ( mNext != (UFG::Rule *)p_m_criteria );
  }
  return v4;
}

// File Line: 201
// RVA: 0x593560
void __fastcall UFG::Query::Query(UFG::Query *this)
{
  UFG::qList<UFG::KeyValue,UFG::KeyValue,1,0> *p_m_facts; // r8
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *mNext; // rax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *mPrev; // rdx
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v4; // rcx

  this->vfptr = (UFG::QueryVtbl *)&UFG::Query::`vftable;
  this->m_character = UFG::gNullQSymbol;
  this->m_concept = UFG::gNullQSymbol;
  p_m_facts = &this->m_facts;
  this->m_facts.mNode.mPrev = &this->m_facts.mNode;
  this->m_facts.mNode.mNext = &this->m_facts.mNode;
  mNext = this->m_facts.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&this->m_facts )
  {
    do
    {
      mPrev = mNext->mPrev;
      v4 = mNext->mNext;
      mPrev->mNext = v4;
      v4->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      mNext = p_m_facts->mNode.mNext;
    }
    while ( mNext != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)p_m_facts );
  }
}

// File Line: 206
// RVA: 0x5947F0
void __fastcall UFG::Query::~Query(UFG::Query *this)
{
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *p_m_facts; // rbx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mPrev; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mNext; // rax

  this->vfptr = (UFG::QueryVtbl *)&UFG::Query::`vftable;
  p_m_facts = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_facts;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_facts);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(p_m_facts);
  mPrev = p_m_facts->mNode.mPrev;
  mNext = p_m_facts->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_facts->mNode.mPrev = &p_m_facts->mNode;
  p_m_facts->mNode.mNext = &p_m_facts->mNode;
}

// File Line: 211
// RVA: 0x59BD90
UFG::qSymbol *__fastcall UFG::Query::FindCharacter(UFG::Query *this, UFG::qSymbol *result)
{
  unsigned int mUID; // eax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *mNext; // rdx

  if ( (_S46_0 & 1) == 0 )
  {
    _S46_0 |= 1u;
    UFG::qSymbol::create_from_string(&characterSym, "character");
    atexit(UFG::Query::FindCharacter_::_2_::_dynamic_atexit_destructor_for__characterSym__);
  }
  mUID = this->m_character.mUID;
  if ( mUID == UFG::gNullQSymbol.mUID )
  {
    mNext = this->m_facts.mNode.mNext;
    if ( mNext == (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&this->m_facts )
    {
LABEL_10:
      result->mUID = UFG::gNullQSymbol.mUID;
      return result;
    }
    while ( LODWORD(mNext[1].mPrev) != characterSym.mUID )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&this->m_facts )
        goto LABEL_10;
    }
    mUID = HIDWORD(mNext[1].mPrev);
  }
  result->mUID = mUID;
  return result;
}

// File Line: 228
// RVA: 0x5ACDF0
void __fastcall UFG::Query::ToString(UFG::Query *this, UFG::qString *str)
{
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *i; // rdi
  char *v5; // rbx
  char *v6; // rax
  char *v7; // rbx
  char *v8; // rax
  UFG::qString text; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString v10; // [rsp+60h] [rbp-38h] BYREF

  UFG::qString::qString(&v10);
  for ( i = this->m_facts.mNode.mNext; i != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&this->m_facts; i = i->mNext )
  {
    UFG::qString::qString(&text);
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i[1].mPrev + 1);
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i[1]);
    UFG::qString::Format(&text, "k: %s \tv: %s\n", v6, v5);
    UFG::qString::operator+=(&v10, &text);
    UFG::qString::~qString(&text);
  }
  v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_character);
  v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_concept);
  UFG::qString::Format(str, "\tconcept:     %s\n\tcharacter:  %s \nfacts:\n %s \n", v8, v7, v10.mData);
  UFG::qString::~qString(&v10);
}

// File Line: 241
// RVA: 0x5ACEF0
void __fastcall UFG::Rule::ToString(UFG::Rule *this, UFG::qString *str)
{
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *i; // rbx
  char *v5; // rdi
  char *v6; // rax
  char *v7; // rbx
  char *v8; // rax
  char *mData; // rsi
  char *v10; // rdi
  char *v11; // rbx
  char *v12; // rax
  UFG::qString text; // [rsp+48h] [rbp-80h] BYREF
  UFG::qString v14; // [rsp+70h] [rbp-58h] BYREF
  UFG::qString v15; // [rsp+98h] [rbp-30h] BYREF

  UFG::qString::qString(&v15);
  for ( i = this->m_criteria.mNode.mNext; i != (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&this->m_criteria; i = i->mNext )
  {
    UFG::qString::qString(&text);
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i[1].mPrev + 1);
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i[1]);
    UFG::qString::Format(&text, "k: %s \tv: %s\n", v6, v5);
    UFG::qString::operator+=(&v15, &text);
    UFG::qString::~qString(&text);
  }
  UFG::qString::qString(&v14);
  v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_apply.m_value);
  v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_apply.m_key);
  UFG::qString::Format(&v14, "k: %s \tv: %s\n", v8, v7);
  mData = v15.mData;
  v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_response);
  v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_concept);
  v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_name);
  UFG::qString::Format(
    str,
    "name:     %s\nconcept:  %s \ncriteria: %s \nresponse: %s \napply:    %s\n",
    v12,
    v11,
    mData,
    v10,
    v14.mData);
  UFG::qString::~qString(&v14);
  UFG::qString::~qString(&v15);
}

