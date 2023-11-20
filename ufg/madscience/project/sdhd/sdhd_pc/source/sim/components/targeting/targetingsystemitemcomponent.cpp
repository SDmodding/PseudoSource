// File Line: 20
// RVA: 0x1544100
__int64 dynamic_initializer_for__UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList__);
}

// File Line: 21
// RVA: 0x1543640
__int64 dynamic_initializer_for__UFG::TargetingSystemItemComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::TargetingSystemItemComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::TargetingSystemItemComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::TargetingSystemItemComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::TargetingSystemItemComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 23
// RVA: 0x1543A70
__int64 dynamic_initializer_for__UFG::TargetingSystemItemComponent::ms_TargetingMap__()
{
  signed __int64 v0; // rcx
  __int64 v1; // rax

  v0 = 91i64;
  v1 = UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.p[v1] = 0;
    v1 = UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.size++ + 1;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemItemComponent::ms_TargetingMap__);
}

// File Line: 43
// RVA: 0x519A50
void __fastcall UFG::TargetingSystemItemComponent::TargetingSystemItemComponent(UFG::TargetingSystemItemComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::TargetingSystemItemComponent *v4; // rbx
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v5; // rdx
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v6; // rax

  v4 = this;
  UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(
    (UFG::TargetingSystemBaseComponent *)&this->vfptr,
    &UFG::TargetingSystemItemComponent::ms_TargetingMap,
    name_uid,
    properties);
  v5 = (UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemItemComponent::`vftable'{for `UFG::SimComponent'};
  v4->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemItemComponent::`vftable'{for `UFG::UpdateInterface'};
  v6 = UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList.mNode.mPrev;
  UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *)&UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList;
  UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList.mNode.mPrev = (UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::TargetingSystemItemComponent::_TargetingSystemItemComponentTypeUID,
    "TargetingSystemItemComponent");
}

// File Line: 51
// RVA: 0x51CE20
void __fastcall UFG::TargetingSystemItemComponent::~TargetingSystemItemComponent(UFG::TargetingSystemItemComponent *this)
{
  UFG::TargetingSystemItemComponent *v1; // r8
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v2; // rdx
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v3; // rcx
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v4; // rax
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemItemComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemItemComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentpCurrentIterator )
    UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentpCurrentIterator = (UFG::TargetingSystemItemComponent *)&this->mPrev[-8].mNext;
  v2 = (UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::TargetingSystemBaseComponent::~TargetingSystemBaseComponent((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
}

// File Line: 58
// RVA: 0x540D00
void __fastcall UFG::TargetingSystemItemComponent::OnDetach(UFG::TargetingSystemItemComponent *this)
{
  UFG::TargetingSystemItemComponent *v1; // rdi
  UFG::SimObjectCharacter *v2; // rcx
  UFG::GameStatTracker *v3; // rax
  unsigned int v4; // ebx
  UFG::SceneObjectProperties *v5; // rcx
  UFG::qResourceData *v6; // rax

  v1 = this;
  v2 = (UFG::SimObjectCharacter *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[54]].m_pTarget.m_pPointer;
  if ( v2 )
  {
    if ( v2 == LocalPlayer )
    {
      v3 = UFG::GameStatTracker::Instance();
      v4 = UFG::GameStatTracker::GetStat(v3, Equipped)->mValue.mUID;
      if ( v4 != -1 )
      {
        v5 = v1->m_pSimObject->m_pSceneObj;
        if ( v5 )
        {
          v6 = UFG::SceneObjectProperties::GetArchetypeProperties(v5);
          if ( v6 )
          {
            if ( v4 == *(_DWORD *)&v6->mDebugName[12] )
              UFG::GameStatAction::Inventory::UnEquip(0);
          }
        }
      }
    }
  }
  UFG::TargetingSystemBaseComponent::OnDetach((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
}

// File Line: 97
// RVA: 0x535820
bool __fastcall UFG::TargetingSystemItemComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentTargetingSystemItem.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 103
// RVA: 0x5456A0
UFG::SimComponent *__fastcall UFG::TargetingSystemItemComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned __int16 v8; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x88ui64, "TargetingSystemItemComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::TargetingSystemItemComponent::TargetingSystemItemComponent(
      (UFG::TargetingSystemItemComponent *)v3,
      v1->m_NameUID,
      v4,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v1->m_pSimObject;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 || (v8 & 0x8000u) != 0 )
    v9 = 20;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v6;
}

// File Line: 112
// RVA: 0x55CBD0
void __fastcall UFG::TargetingSystemItemComponent::Update(UFG::TargetingSystemItemComponent *this, float delta_sec)
{
  UFG::TargetingSystemItemComponent *v2; // rdi
  signed __int64 v3; // rdx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v4; // rcx
  UFG::SimObject *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // er8
  unsigned int v9; // er9
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  unsigned __int8 v12; // cl

  v2 = this;
  v3 = *(_QWORD *)&this->m_TypeUID + 56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_Flags + 62i64);
  if ( !*(_QWORD *)(v3 + 40) || !*(_BYTE *)(v3 + 49) )
  {
    v4 = this[-1].m_TargetedBy.mNode.mNext;
    v5 = 0i64;
    if ( v4 )
    {
      v6 = WORD2(v4[4].mNext);
      if ( !((v6 >> 14) & 1) && (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::SimComponent *)v4[6].mNext[11].mPrev;
        }
        else if ( (v6 >> 12) & 1 )
        {
          v8 = (unsigned int)v4[8].mPrev;
          v9 = (unsigned int)v4[6].mPrev;
          if ( v8 >= v9 )
          {
LABEL_14:
            v7 = 0i64;
          }
          else
          {
            v10 = (signed __int64)&v4[6].mNext[v8];
            while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
                 || UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF )
            {
              ++v8;
              v10 += 16i64;
              if ( v8 >= v9 )
                goto LABEL_14;
            }
            v7 = *(UFG::SimComponent **)v10;
          }
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v4, UFG::InventoryItemComponent::_TypeUID);
        }
        if ( v7 )
        {
          v11 = *(_QWORD *)&v7[1].m_Flags;
          if ( v11 )
            v5 = *(UFG::SimObject **)(v11 + 40);
        }
      }
    }
    v12 = *(_BYTE *)(*(_QWORD *)&v2->m_Flags + 62i64);
    if ( v12 )
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)&v2->m_TypeUID + 56i64 * v12), v5);
  }
}

