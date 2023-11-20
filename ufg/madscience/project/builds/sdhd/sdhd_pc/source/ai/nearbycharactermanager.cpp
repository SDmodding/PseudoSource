// File Line: 23
// RVA: 0x350F90
void UFG::NearbyCharacterManager::CreateInstance(void)
{
  UFG::NearbyCharacterManager *v0; // rbx

  v0 = (UFG::NearbyCharacterManager *)UFG::qMalloc(0x20ui64, "NearbyCharacterManager", 0i64);
  if ( v0 )
  {
    `eh vector constructor iterator'(v0, 0x10ui64, 2, (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
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
    `eh vector destructor iterator'(
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
void __fastcall UFG::NearbyCharacterManager::AddCharacter(UFG::NearbyCharacterManager *this, UFG::AIEntityComponent *ai_entity_component)
{
  UFG::AIEntityComponent *v2; // rbx
  UFG::NearbyCharacterManager *v3; // rsi
  UFG::SimComponent *v4; // rax
  signed int v5; // edi
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rdx
  UFG::allocator::free_link *v8; // rcx
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimComponent *v14; // r9
  UFG::allocator::free_link *v15; // r8
  UFG::allocator::free_link *v16; // rcx
  UFG::allocator::free_link *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList,1,0> *v19; // rcx
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // [rsp+50h] [rbp+18h]

  v2 = ai_entity_component;
  v3 = this;
  if ( ((unsigned __int8 (__fastcall *)(UFG::AIEntityComponent *))ai_entity_component->vfptr[14].__vecDelDtor)(ai_entity_component) )
  {
    v4 = v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
    if ( v4 )
    {
      v5 = LODWORD(v4[3].m_SafePointerList.mNode.mPrev) != 17
        || UFG::g_AIObjectiveParams[*((signed int *)&v2[3].m_pActionTreeComponent.m_Changed + 1)].m_IsHostile ? 0 : 1;
      if ( v5 != -1 )
      {
        v6 = UFG::qMalloc(0x50ui64, "NearbyCharacter", 0i64);
        v7 = v6;
        if ( v6 )
        {
          v6->mNext = v6;
          v6[1].mNext = v6;
          v8 = v6 + 2;
          v8->mNext = v8;
          v8[1].mNext = v8;
          v9 = v6 + 4;
          v9->mNext = v9;
          v9[1].mNext = v9;
          v9[2].mNext = 0i64;
          v21 = v7 + 7;
          v21->mNext = v21;
          v21[1].mNext = v21;
          v7[9].mNext = 0i64;
        }
        else
        {
          v7 = 0i64;
        }
        v10 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7[4];
        if ( v7[6].mNext )
        {
          v11 = v10->mPrev;
          v12 = v7[5].mNext;
          v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v12;
          v12->mNext = (UFG::allocator::free_link *)v11;
          v10->mPrev = v10;
          v7[5].mNext = v7 + 4;
        }
        v7[6].mNext = (UFG::allocator::free_link *)v2;
        v13 = v2->m_SafePointerList.mNode.mPrev;
        v13->mNext = v10;
        v10->mPrev = v13;
        v7[5].mNext = (UFG::allocator::free_link *)&v2->m_SafePointerList;
        v2->m_SafePointerList.mNode.mPrev = v10;
        v14 = v2->m_pTargetingSystemBaseComponent.m_pSimComponent;
        v15 = v7 + 7;
        if ( v7[9].mNext )
        {
          v16 = v15->mNext;
          v17 = v7[8].mNext;
          v16[1].mNext = v17;
          v17->mNext = v16;
          v15->mNext = v15;
          v7[8].mNext = v7 + 7;
        }
        v7[9].mNext = (UFG::allocator::free_link *)v14;
        if ( v14 )
        {
          v18 = v14->m_SafePointerList.mNode.mPrev;
          v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v15;
          v15->mNext = (UFG::allocator::free_link *)v18;
          v7[8].mNext = (UFG::allocator::free_link *)&v14->m_SafePointerList;
          v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v15;
        }
        v2->m_pNearbyCharacter = (UFG::NearbyCharacter *)v7;
        v19 = &v3->m_Characters[v5];
        v20 = (UFG::allocator::free_link *)v19->mNode.mPrev;
        v20[1].mNext = v7;
        v7->mNext = v20;
        v7[1].mNext = (UFG::allocator::free_link *)v19;
        v19->mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v7;
      }
    }
  }
}

// File Line: 117
// RVA: 0x381350
void __fastcall UFG::NearbyCharacterManager::RemoveCharacter(UFG::NearbyCharacterManager *this, UFG::AIEntityComponent *ai_entity_component)
{
  UFG::AIEntityComponent *v2; // rdi
  UFG::SimComponent *v3; // rax
  signed int v4; // eax
  UFG::NearbyCharacter *v5; // rbx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *v6; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *v7; // rax
  UFG::NearbyCharacter *v8; // rcx

  v2 = ai_entity_component;
  if ( ((unsigned __int8 (__fastcall *)(UFG::AIEntityComponent *))ai_entity_component->vfptr[14].__vecDelDtor)(ai_entity_component) )
  {
    v3 = v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
    if ( v3 )
      v4 = LODWORD(v3[3].m_SafePointerList.mNode.mPrev) == 17
        && !UFG::g_AIObjectiveParams[*((signed int *)&v2[3].m_pActionTreeComponent.m_Changed + 1)].m_IsHostile;
    else
      v4 = -1;
    v5 = v2->m_pNearbyCharacter;
    if ( v5 )
    {
      if ( v4 != -1 )
      {
        v6 = v5->mPrev;
        v7 = v5->mNext;
        v8 = v2->m_pNearbyCharacter;
        v6->mNext = v7;
        v7->mPrev = v6;
        v5->mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&v5->mPrev;
        v5->mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&v5->mPrev;
        v2->m_pNearbyCharacter = 0i64;
        UFG::NearbyCharacter::~NearbyCharacter(v8);
        operator delete[](v5);
      }
    }
  }
}

// File Line: 137
// RVA: 0x360C90
void __fastcall UFG::NearbyCharacterManager::GetNearbyCharacters(UFG::NearbyCharacterManager *this, UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> *list, UFG::eNearbyCharacterType character_type, UFG::qVector3 *position)
{
  UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> *v4; // r10
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *i; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v6; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v7; // r9
  char *v8; // r8
  __int64 j; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v10; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> **v11; // rdx

  v4 = list;
  for ( i = list->mNode.mNext;
        &i[-1] != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&v4[-1];
        i = v4->mNode.mNext )
  {
    v6 = i->mNext;
    v7 = i->mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    i->mPrev = i;
    i->mNext = i;
  }
  v8 = (char *)&this->m_Characters[character_type];
  for ( j = *((_QWORD *)v8 + 1); (char *)j != v8; j = *(_QWORD *)(j + 8) )
  {
    v10 = v4->mNode.mPrev;
    v11 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> **)(j + 16);
    v10->mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)(j + 16);
    *v11 = v10;
    v11[1] = &v4->mNode;
    v4->mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)(j + 16);
  }
}

// File Line: 150
// RVA: 0x360D10
void __fastcall UFG::NearbyCharacterManager::GetNearbyCharactersAll(UFG::NearbyCharacterManager *this, UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> *list, UFG::qVector3 *position)
{
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v3; // r9
  UFG::NearbyCharacterManager *i; // r10
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v5; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v6; // r8
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *v7; // r8
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v8; // rax
  _QWORD *v9; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v10; // r8
  signed __int64 j; // r10
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v12; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v13; // rcx

  v3 = list->mNode.mNext;
  for ( i = this;
        &v3[-1] != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list[-1];
        v3 = list->mNode.mNext )
  {
    v5 = v3->mNext;
    v6 = v3->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v3->mPrev = v3;
    v3->mNext = v3;
  }
  v7 = this->m_Characters[0].mNode.mNext;
  if ( v7 != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)this )
  {
    do
    {
      v8 = list->mNode.mPrev;
      v9 = &v7[1].mPrev;
      v8->mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&v7[1];
      *v9 = v8;
      v9[1] = list;
      list->mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&v7[1];
      v7 = v7->mNext;
    }
    while ( v7 != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)i );
  }
  v10 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)i->m_Characters[1].mNode.mNext;
  for ( j = (signed __int64)&i->m_Characters[1];
        v10 != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)j;
        v10 = v10->mNext )
  {
    v12 = list->mNode.mPrev;
    v13 = v10 + 1;
    v12->mNext = v10 + 1;
    v13->mPrev = v12;
    v13->mNext = &list->mNode;
    list->mNode.mPrev = v10 + 1;
  }
}

