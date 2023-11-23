// File Line: 20
// RVA: 0x1544100
__int64 dynamic_initializer_for__UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList__);
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
  __int64 v0; // rcx
  __int64 size; // rax

  v0 = 91i64;
  size = UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.p[size] = 0;
    size = ++UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.size;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemItemComponent::ms_TargetingMap__);
}

// File Line: 43
// RVA: 0x519A50
void __fastcall UFG::TargetingSystemItemComponent::TargetingSystemItemComponent(
        UFG::TargetingSystemItemComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *mPrev; // rax

  UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(
    this,
    &UFG::TargetingSystemItemComponent::ms_TargetingMap,
    name_uid,
    properties);
  this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>;
  this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>;
  this->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemItemComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemItemComponent::`vftable{for `UFG::UpdateInterface};
  mPrev = UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList.mNode.mPrev;
  UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>;
  this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>::mNext = (UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *)&UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList;
  UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TargetingSystemItemComponent::_TargetingSystemItemComponentTypeUID,
    "TargetingSystemItemComponent");
}

// File Line: 51
// RVA: 0x51CE20
void __fastcall UFG::TargetingSystemItemComponent::~TargetingSystemItemComponent(
        UFG::TargetingSystemItemComponent *this)
{
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v2; // rdx
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *mPrev; // rcx
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *mNext; // rax
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent> *v6; // rax

  this->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemItemComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemItemComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentpCurrentIterator )
    UFG::TargetingSystemItemComponent::s_TargetingSystemItemComponentpCurrentIterator = (UFG::TargetingSystemItemComponent *)&this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>::mPrev[-8].mNext;
  v2 = &this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>;
  mPrev = this->UFG::qNode<UFG::TargetingSystemItemComponent,UFG::TargetingSystemItemComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::TargetingSystemBaseComponent::~TargetingSystemBaseComponent(this);
}

// File Line: 58
// RVA: 0x540D00
void __fastcall UFG::TargetingSystemItemComponent::OnDetach(UFG::TargetingSystemItemComponent *this)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::GameStatTracker *v3; // rax
  unsigned int mUID; // ebx
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qResourceData *ArchetypeProperties; // rax

  m_pPointer = (UFG::SimObjectCharacter *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[54]].m_pTarget.m_pPointer;
  if ( m_pPointer )
  {
    if ( m_pPointer == LocalPlayer )
    {
      v3 = UFG::GameStatTracker::Instance();
      mUID = UFG::GameStatTracker::GetStat(v3, Equipped)->mValue.mUID;
      if ( mUID != -1 )
      {
        m_pSceneObj = this->m_pSimObject->m_pSceneObj;
        if ( m_pSceneObj )
        {
          ArchetypeProperties = UFG::SceneObjectProperties::GetArchetypeProperties(m_pSceneObj);
          if ( ArchetypeProperties )
          {
            if ( mUID == *(_DWORD *)&ArchetypeProperties->mDebugName[12] )
              UFG::GameStatAction::Inventory::UnEquip(0);
          }
        }
      }
    }
  }
  UFG::TargetingSystemBaseComponent::OnDetach(this);
}

// File Line: 97
// RVA: 0x535820
bool __fastcall UFG::TargetingSystemItemComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTargetingSystemItem,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 103
// RVA: 0x5456A0
UFG::TargetingSystemItemComponent *__fastcall UFG::TargetingSystemItemComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x88ui64, "TargetingSystemItemComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::TargetingSystemItemComponent::TargetingSystemItemComponent(
      (UFG::TargetingSystemItemComponent *)v3,
      pSceneObj->m_NameUID,
      mpWritableProperties,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v9 = 20;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::TargetingSystemItemComponent *)v6;
}

// File Line: 112
// RVA: 0x55CBD0
void __fastcall UFG::TargetingSystemItemComponent::Update(UFG::TargetingSystemItemComponent *this, float delta_sec)
{
  __int64 v3; // rdx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *mNext; // rcx
  UFG::SimObject *v5; // rbx
  __int16 v6; // dx
  UFG::SimComponent *mPrev; // rax
  unsigned int v8; // r8d
  unsigned int v9; // r9d
  __int64 v10; // rdx
  __int64 v11; // rcx
  unsigned __int8 v12; // cl

  v3 = *(_QWORD *)&this->m_TypeUID + 56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_Flags + 62i64);
  if ( !*(_QWORD *)(v3 + 40) || !*(_BYTE *)(v3 + 49) )
  {
    mNext = this[-1].m_TargetedBy.mNode.mNext;
    v5 = 0i64;
    if ( mNext )
    {
      v6 = WORD2(mNext[4].mNext);
      if ( (v6 & 0x4000) == 0 && v6 >= 0 )
      {
        if ( (v6 & 0x2000) != 0 )
        {
          mPrev = (UFG::SimComponent *)mNext[6].mNext[11].mPrev;
        }
        else if ( (v6 & 0x1000) != 0 )
        {
          v8 = (unsigned int)mNext[8].mPrev;
          v9 = (unsigned int)mNext[6].mPrev;
          if ( v8 >= v9 )
          {
LABEL_14:
            mPrev = 0i64;
          }
          else
          {
            v10 = (__int64)&mNext[6].mNext[v8];
            while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
                 || (UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v8;
              v10 += 16i64;
              if ( v8 >= v9 )
                goto LABEL_14;
            }
            mPrev = *(UFG::SimComponent **)v10;
          }
        }
        else
        {
          mPrev = UFG::SimObject::GetComponentOfType((UFG::SimObject *)mNext, UFG::InventoryItemComponent::_TypeUID);
        }
        if ( mPrev )
        {
          v11 = *(_QWORD *)&mPrev[1].m_Flags;
          if ( v11 )
            v5 = *(UFG::SimObject **)(v11 + 40);
        }
      }
    }
    v12 = *(_BYTE *)(*(_QWORD *)&this->m_Flags + 62i64);
    if ( v12 )
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(*(_QWORD *)&this->m_TypeUID + 56i64 * v12), v5);
  }
}

