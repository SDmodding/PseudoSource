// File Line: 23
// RVA: 0x350F90
void UFG::NearbyCharacterManager::CreateInstance(void)
{
  UFG::NearbyCharacterManager *v0; // rbx

  v0 = (UFG::NearbyCharacterManager *)UFG::qMalloc(0x20ui64, "NearbyCharacterManager", 0i64);
  if ( v0 )
  {
    `eh vector constructor iterator(v0, 0x10ui64, 2, (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
    UFG::NearbyCharacterManager::s_pInstance = v0;
  }
  else
  {
    UFG::NearbyCharacterManager::s_pInstance = 0i64;
  }
}

// File Line: 28
// RVA: 0x351E60
void UFG::NearbyCharacterManager::DeleteInstance(void)
{
  UFG::NearbyCharacterManager *v0; // rbx

  v0 = UFG::NearbyCharacterManager::s_pInstance;
  if ( UFG::NearbyCharacterManager::s_pInstance )
  {
    `eh vector destructor iterator(
      UFG::NearbyCharacterManager::s_pInstance,
      0x10ui64,
      2,
      (void (__fastcall *)(void *))UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList,1,0>::~qList<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList,1,0>);
    operator delete[](v0);
  }
  UFG::NearbyCharacterManager::s_pInstance = 0i64;
}

// File Line: 93
// RVA: 0x340010
void __fastcall UFG::NearbyCharacterManager::AddCharacter(
        UFG::NearbyCharacterManager *this,
        UFG::AIEntityComponent *ai_entity_component)
{
  UFG::SimComponent *m_pSimComponent; // rax
  BOOL v5; // edi
  UFG::allocator::free_link *v6; // rax
  UFG::NearbyCharacter *v7; // rdx
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_m_pAIEntityComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimComponent *v13; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *p_mNode; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *v19; // rax

  if ( ((unsigned __int8 (__fastcall *)(UFG::AIEntityComponent *))ai_entity_component->vfptr[14].__vecDelDtor)(ai_entity_component) )
  {
    m_pSimComponent = ai_entity_component->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      v5 = LODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev) == 17
        && !UFG::g_AIObjectiveParams[*((int *)&ai_entity_component[3].m_pActionTreeComponent.m_Changed + 1)].m_IsHostile;
      v6 = UFG::qMalloc(0x50ui64, "NearbyCharacter", 0i64);
      v7 = (UFG::NearbyCharacter *)v6;
      if ( v6 )
      {
        v6->mNext = v6;
        v6[1].mNext = v6;
        v6[2].mNext = v6 + 2;
        v6[3].mNext = v6 + 2;
        v8 = v6 + 4;
        v8->mNext = v8;
        v8[1].mNext = v8;
        v8[2].mNext = 0i64;
        v7->m_pTargetingSystemComponent.mPrev = &v7->m_pTargetingSystemComponent;
        v7->m_pTargetingSystemComponent.mNext = &v7->m_pTargetingSystemComponent;
        v7->m_pTargetingSystemComponent.m_pPointer = 0i64;
      }
      else
      {
        v7 = 0i64;
      }
      p_m_pAIEntityComponent = &v7->m_pAIEntityComponent;
      if ( v7->m_pAIEntityComponent.m_pPointer )
      {
        mPrev = p_m_pAIEntityComponent->mPrev;
        mNext = v7->m_pAIEntityComponent.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
        v7->m_pAIEntityComponent.mNext = &v7->m_pAIEntityComponent;
      }
      v7->m_pAIEntityComponent.m_pPointer = ai_entity_component;
      v12 = ai_entity_component->m_SafePointerList.mNode.mPrev;
      v12->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v12;
      v7->m_pAIEntityComponent.mNext = &ai_entity_component->m_SafePointerList.mNode;
      ai_entity_component->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
      v13 = ai_entity_component->m_pTargetingSystemBaseComponent.m_pSimComponent;
      p_m_pTargetingSystemComponent = &v7->m_pTargetingSystemComponent;
      if ( v7->m_pTargetingSystemComponent.m_pPointer )
      {
        v15 = p_m_pTargetingSystemComponent->mPrev;
        v16 = v7->m_pTargetingSystemComponent.mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        p_m_pTargetingSystemComponent->mPrev = p_m_pTargetingSystemComponent;
        v7->m_pTargetingSystemComponent.mNext = &v7->m_pTargetingSystemComponent;
      }
      v7->m_pTargetingSystemComponent.m_pPointer = v13;
      if ( v13 )
      {
        v17 = v13->m_SafePointerList.mNode.mPrev;
        v17->mNext = p_m_pTargetingSystemComponent;
        p_m_pTargetingSystemComponent->mPrev = v17;
        v7->m_pTargetingSystemComponent.mNext = &v13->m_SafePointerList.mNode;
        v13->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemComponent;
      }
      ai_entity_component->m_pNearbyCharacter = v7;
      p_mNode = &this->m_Characters[v5].mNode;
      v19 = p_mNode->mPrev;
      v19->mNext = v7;
      v7->UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList>::mPrev = v19;
      v7->UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList>::mNext = p_mNode;
      p_mNode->mPrev = v7;
    }
  }
}

// File Line: 117
// RVA: 0x381350
void __fastcall UFG::NearbyCharacterManager::RemoveCharacter(
        UFG::NearbyCharacterManager *this,
        UFG::AIEntityComponent *ai_entity_component)
{
  UFG::SimComponent *m_pSimComponent; // rax
  int v4; // eax
  UFG::NearbyCharacter *m_pNearbyCharacter; // rbx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *mPrev; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *mNext; // rax
  UFG::NearbyCharacter *v8; // rcx

  if ( ((unsigned __int8 (__fastcall *)(UFG::AIEntityComponent *))ai_entity_component->vfptr[14].__vecDelDtor)(ai_entity_component) )
  {
    m_pSimComponent = ai_entity_component->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
    if ( m_pSimComponent )
      v4 = LODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev) == 17
        && !UFG::g_AIObjectiveParams[*((int *)&ai_entity_component[3].m_pActionTreeComponent.m_Changed + 1)].m_IsHostile;
    else
      v4 = -1;
    m_pNearbyCharacter = ai_entity_component->m_pNearbyCharacter;
    if ( m_pNearbyCharacter )
    {
      if ( v4 != -1 )
      {
        mPrev = m_pNearbyCharacter->UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList>::mPrev;
        mNext = m_pNearbyCharacter->UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList>::mNext;
        v8 = ai_entity_component->m_pNearbyCharacter;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        m_pNearbyCharacter->UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList>::mPrev = m_pNearbyCharacter;
        m_pNearbyCharacter->UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList>::mNext = m_pNearbyCharacter;
        ai_entity_component->m_pNearbyCharacter = 0i64;
        UFG::NearbyCharacter::~NearbyCharacter(v8);
        operator delete[](m_pNearbyCharacter);
      }
    }
  }
}

// File Line: 137
// RVA: 0x360C90
void __fastcall UFG::NearbyCharacterManager::GetNearbyCharacters(
        UFG::NearbyCharacterManager *this,
        UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> *list,
        UFG::eNearbyCharacterType character_type,
        UFG::qVector3 *position)
{
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *i; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *mNext; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *mPrev; // r9
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v8; // r8
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *j; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v10; // rcx

  for ( i = list->mNode.mNext;
        &i[-1] != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list[-1];
        i = list->mNode.mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
  v8 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&this->m_Characters[character_type];
  for ( j = v8->mNext; j != v8; j = j->mNext )
  {
    v10 = list->mNode.mPrev;
    v10->mNext = j + 1;
    j[1].mPrev = v10;
    j[1].mNext = &list->mNode;
    list->mNode.mPrev = j + 1;
  }
}

// File Line: 150
// RVA: 0x360D10
void __fastcall UFG::NearbyCharacterManager::GetNearbyCharactersAll(
        UFG::NearbyCharacterManager *this,
        UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *list,
        UFG::qVector3 *position)
{
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *i; // r9
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *mNext; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *mPrev; // r8
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *j; // r8
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v7; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *k; // r8
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v9; // rax

  for ( i = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)list->mNext;
        &i[-1] != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list[-1];
        i = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)list->mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
  for ( j = this->m_Characters[0].mNode.mNext;
        j != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)this;
        j = j->mNext )
  {
    v7 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)list->mPrev;
    v7->mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&j[1];
    j[1].mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v7;
    j[1].mNext = list;
    list->mPrev = j + 1;
  }
  for ( k = this->m_Characters[1].mNode.mNext;
        k != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&this->m_Characters[1];
        k = k->mNext )
  {
    v9 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)list->mPrev;
    v9->mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&k[1];
    k[1].mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v9;
    k[1].mNext = list;
    list->mPrev = k + 1;
  }
}

