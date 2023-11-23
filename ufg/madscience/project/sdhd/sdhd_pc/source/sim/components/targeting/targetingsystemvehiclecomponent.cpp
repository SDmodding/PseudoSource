// File Line: 28
// RVA: 0x15441A0
__int64 dynamic_initializer_for__UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList__);
}

// File Line: 29
// RVA: 0x532610
const char *__fastcall UFG::TargetingSystemVehicleComponent::GetTypeName(UFG::TargetingSystemVehicleComponent *this)
{
  return "TargetingSystemVehicleComponent";
}

// File Line: 35
// RVA: 0x1543BF0
__int64 dynamic_initializer_for__UFG::TargetingSystemVehicleComponent::ms_TargetingMap__()
{
  __int64 v0; // rcx
  __int64 size; // rax

  v0 = 91i64;
  size = UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[size] = 0;
    size = ++UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.size;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemVehicleComponent::ms_TargetingMap__);
}

// File Line: 39
// RVA: 0x551370
void UFG::TargetingSystemVehicleComponent::StaticInit(void)
{
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[2] = UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[4] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                   + 1;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[5] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                   + 2;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[6] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                   + 3;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[7] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                   + 4;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[8] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                   + 5;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[9] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                   + 6;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[13] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 7;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[1] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                   + 8;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[10] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 9;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[11] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 10;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[12] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 11;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[33] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 12;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[69] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 13;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[70] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 14;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[71] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 15;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[72] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 16;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[73] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 17;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[74] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 18;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[61] = LOBYTE(UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                    + 19;
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes += 20;
}

// File Line: 70
// RVA: 0x535920
bool __fastcall UFG::TargetingSystemVehicleComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTargetingSystemVehicle,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 76
// RVA: 0x545BB0
UFG::TargetingSystemVehicleComponent *__fastcall UFG::TargetingSystemVehicleComponent::PropertiesOnActivate(
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
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x90ui64, "TargetingSystemVehicleComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::TargetingSystemVehicleComponent::TargetingSystemVehicleComponent(
      (UFG::TargetingSystemVehicleComponent *)v3,
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
  return (UFG::TargetingSystemVehicleComponent *)v6;
}

// File Line: 94
// RVA: 0x519FB0
void __fastcall UFG::TargetingSystemVehicleComponent::TargetingSystemVehicleComponent(
        UFG::TargetingSystemVehicleComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qBaseTreeRB *v6; // rdi
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *mPrev; // rax
  UFG::qSymbol *v8; // rax

  UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(
    this,
    &UFG::TargetingSystemVehicleComponent::ms_TargetingMap,
    name_uid,
    properties);
  this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>;
  this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>;
  this->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemVehicleComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemVehicleComponent::`vftable{for `UFG::UpdateInterface};
  v6 = 0i64;
  this->m_pActionHijackProfile = 0i64;
  mPrev = UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList.mNode.mPrev;
  UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>;
  this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>::mNext = (UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *)&UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList;
  UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TargetingSystemVehicleComponent::_TargetingSystemVehicleComponentTypeUID,
    "TargetingSystemVehicleComponent");
  if ( properties )
  {
    v8 = UFG::qPropertySet::Get<UFG::qSymbol>(
           properties,
           (UFG::qArray<unsigned long,0> *)&UFG::symActionHijackProfile,
           DEPTH_RECURSE);
    if ( v8 )
    {
      if ( v8->mUID )
        v6 = UFG::qBaseTreeRB::Get(&UFG::ActionHijackProfiles::ms_ActionHijackProfiles.mTree, v8->mUID);
      this->m_pActionHijackProfile = (UFG::ActionHijackProfile *)v6;
    }
  }
}

// File Line: 104
// RVA: 0x51D520
void __fastcall UFG::TargetingSystemVehicleComponent::~TargetingSystemVehicleComponent(
        UFG::TargetingSystemVehicleComponent *this)
{
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v2; // rdx
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *mPrev; // rcx
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *mNext; // rax
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v6; // rax

  this->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemVehicleComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemVehicleComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentpCurrentIterator )
    UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentpCurrentIterator = (UFG::TargetingSystemVehicleComponent *)&this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>::mPrev[-8].mNext;
  v2 = &this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>;
  mPrev = this->UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent>::mPrev;
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

// File Line: 110
// RVA: 0x154CB10
__int64 UFG::_dynamic_initializer_for__symActionHijackProfile__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ActionHijackProfile", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symActionHijackProfile, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symActionHijackProfile__);
}

// File Line: 137
// RVA: 0x54F130
void __fastcall UFG::TargetingSystemVehicleComponent::SetTargetLock(
        UFG::TargetingSystemVehicleComponent *this,
        unsigned int eTargetType,
        bool bLock,
        const bool bModifyCollision,
        float fDelayTime,
        const char *pDebugOriginatingSystem,
        ActionContext *pDebugOriginatingContext,
        ITrack *pDebugOriginatingTrack)
{
  __int64 v8; // r14
  UFG::SimObjectGame *m_pPointer; // rbx
  bool v12; // bp
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  __int64 v17; // rdx
  UFG::SimObjectGame *m_pSimObject; // rdx
  unsigned __int8 v19; // cl
  UFG::TargetingSimObject *v20; // rcx

  v8 = eTargetType;
  m_pPointer = (UFG::SimObjectGame *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[eTargetType]].m_pTarget.m_pPointer;
  if ( m_pPointer )
  {
    v12 = bLock && bModifyCollision;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags < 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
        goto LABEL_19;
      }
      if ( (m_Flags & 0x2000) == 0 )
      {
        if ( (m_Flags & 0x1000) != 0 )
        {
          mComponentTableEntryCount = m_pPointer->mComponentTableEntryCount;
          size = m_pPointer->m_Components.size;
          if ( mComponentTableEntryCount >= size )
          {
LABEL_16:
            m_pComponent = 0i64;
          }
          else
          {
            v17 = (__int64)&m_pPointer->m_Components.p[mComponentTableEntryCount];
            while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                 || (UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF) != 0 )
            {
              ++mComponentTableEntryCount;
              v17 += 16i64;
              if ( mComponentTableEntryCount >= size )
                goto LABEL_16;
            }
            m_pComponent = *(UFG::SimComponent **)v17;
          }
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        }
LABEL_19:
        if ( m_pComponent )
          goto LABEL_23;
      }
    }
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v12 )
      UFG::PhysicsSystem::DisableCollisionsBetween(
        (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
        m_pSimObject,
        m_pPointer);
    else
      UFG::PhysicsSystem::ReEnableCollisionsBetween(
        (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
        m_pSimObject,
        m_pPointer);
  }
LABEL_23:
  v19 = this->m_pTargetingMap->m_Map.p[v8];
  if ( v19 )
  {
    v20 = &this->m_pTargets[v19];
    if ( bLock != v20->m_bLock )
      v20->m_bLock = bLock;
  }
}

// File Line: 170
// RVA: 0x55CF90
void __fastcall UFG::TargetingSystemVehicleComponent::Update(
        UFG::TargetingSystemVehicleComponent *this,
        float delta_sec)
{
  UFG::TargetingSystemBaseComponent::updateMySpawnPointTarget((UFG::TargetingSystemVehicleComponent *)((char *)this - 64));
}

