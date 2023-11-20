// File Line: 28
// RVA: 0x15441A0
__int64 dynamic_initializer_for__UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList__);
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
  signed __int64 v0; // rcx
  __int64 v1; // rax

  v0 = 91i64;
  v1 = UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[v1] = 0;
    v1 = UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.size++ + 1;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemVehicleComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemVehicleComponent::ms_TargetingMap__);
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
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentTargetingSystemVehicle.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 76
// RVA: 0x545BB0
UFG::SimComponent *__fastcall UFG::TargetingSystemVehicleComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
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
  v3 = UFG::qMemoryPool::Allocate(v2, 0x90ui64, "TargetingSystemVehicleComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::TargetingSystemVehicleComponent::TargetingSystemVehicleComponent(
      (UFG::TargetingSystemVehicleComponent *)v3,
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

// File Line: 94
// RVA: 0x519FB0
void __fastcall UFG::TargetingSystemVehicleComponent::TargetingSystemVehicleComponent(UFG::TargetingSystemVehicleComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::qPropertySet *v4; // rsi
  UFG::TargetingSystemVehicleComponent *v5; // rbx
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v6; // rdx
  UFG::qBaseTreeRB *v7; // rdi
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v8; // rax
  UFG::qSymbol *v9; // rax

  v4 = properties;
  v5 = this;
  UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(
    (UFG::TargetingSystemBaseComponent *)&this->vfptr,
    &UFG::TargetingSystemVehicleComponent::ms_TargetingMap,
    name_uid,
    properties);
  v6 = (UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemVehicleComponent::`vftable'{for `UFG::SimComponent'};
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemVehicleComponent::`vftable'{for `UFG::UpdateInterface'};
  v7 = 0i64;
  v5->m_pActionHijackProfile = 0i64;
  v8 = UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList.mNode.mPrev;
  UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *)&v5->mPrev;
  v6->mPrev = v8;
  v5->mNext = (UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *)&UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList;
  UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentList.mNode.mPrev = (UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::TargetingSystemVehicleComponent::_TargetingSystemVehicleComponentTypeUID,
    "TargetingSystemVehicleComponent");
  if ( v4 )
  {
    v9 = UFG::qPropertySet::Get<UFG::qSymbol>(v4, (UFG::qSymbol *)&UFG::symActionHijackProfile.mUID, DEPTH_RECURSE);
    if ( v9 )
    {
      if ( v9->mUID )
        v7 = UFG::qBaseTreeRB::Get(&UFG::ActionHijackProfiles::ms_ActionHijackProfiles.mTree, v9->mUID);
      v5->m_pActionHijackProfile = (UFG::ActionHijackProfile *)v7;
    }
  }
}

// File Line: 104
// RVA: 0x51D520
void __fastcall UFG::TargetingSystemVehicleComponent::~TargetingSystemVehicleComponent(UFG::TargetingSystemVehicleComponent *this)
{
  UFG::TargetingSystemVehicleComponent *v1; // r8
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v2; // rdx
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v3; // rcx
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v4; // rax
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemVehicleComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemVehicleComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentpCurrentIterator )
    UFG::TargetingSystemVehicleComponent::s_TargetingSystemVehicleComponentpCurrentIterator = (UFG::TargetingSystemVehicleComponent *)&this->mPrev[-8].mNext;
  v2 = (UFG::qNode<UFG::TargetingSystemVehicleComponent,UFG::TargetingSystemVehicleComponent> *)&this->mPrev;
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

// File Line: 110
// RVA: 0x154CB10
__int64 UFG::_dynamic_initializer_for__symActionHijackProfile__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ActionHijackProfile", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symActionHijackProfile, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symActionHijackProfile__);
}

// File Line: 137
// RVA: 0x54F130
void __fastcall UFG::TargetingSystemVehicleComponent::SetTargetLock(UFG::TargetingSystemVehicleComponent *this, UFG::eTargetTypeEnum eTargetType, const bool bLock, const bool bModifyCollision, const float fDelayTime, const char *pDebugOriginatingSystem, ActionContext *pDebugOriginatingContext, ITrack *pDebugOriginatingTrack)
{
  __int64 v8; // r14
  bool v9; // si
  UFG::TargetingSystemVehicleComponent *v10; // rdi
  UFG::SimObject *v11; // rbx
  bool v12; // bp
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  unsigned int v15; // er8
  unsigned int v16; // er9
  signed __int64 v17; // rdx
  UFG::SimObject *v18; // rdx
  unsigned __int8 v19; // cl
  signed __int64 v20; // rcx

  v8 = (unsigned int)eTargetType;
  v9 = bLock;
  v10 = this;
  v11 = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[eTargetType]].m_pTarget.m_pPointer;
  if ( v11 )
  {
    v12 = bLock && bModifyCollision;
    v13 = v11->m_Flags;
    if ( !((v13 >> 14) & 1) )
    {
      if ( (v13 & 0x8000u) != 0 )
      {
        v14 = v11->m_Components.p[34].m_pComponent;
        goto LABEL_19;
      }
      if ( !((v13 >> 13) & 1) )
      {
        if ( (v13 >> 12) & 1 )
        {
          v15 = (unsigned int)v11[1].vfptr;
          v16 = v11->m_Components.size;
          if ( v15 >= v16 )
          {
LABEL_16:
            v14 = 0i64;
          }
          else
          {
            v17 = (signed __int64)&v11->m_Components.p[v15];
            while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                 || UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF )
            {
              ++v15;
              v17 += 16i64;
              if ( v15 >= v16 )
                goto LABEL_16;
            }
            v14 = *(UFG::SimComponent **)v17;
          }
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType(v11, UFG::PhysicsMoverInterface::_TypeUID);
        }
LABEL_19:
        if ( v14 )
          goto LABEL_23;
        goto LABEL_20;
      }
    }
LABEL_20:
    v18 = v10->m_pSimObject;
    if ( v12 )
      UFG::PhysicsSystem::DisableCollisionsBetween((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, v18, v11);
    else
      UFG::PhysicsSystem::ReEnableCollisionsBetween((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, v18, v11);
  }
LABEL_23:
  v19 = v10->m_pTargetingMap->m_Map.p[v8];
  if ( v19 )
  {
    v20 = (signed __int64)&v10->m_pTargets[v19];
    if ( v9 ^ *(_BYTE *)(v20 + 49) )
      *(_BYTE *)(v20 + 49) = v9;
  }
}

// File Line: 170
// RVA: 0x55CF90
void __fastcall UFG::TargetingSystemVehicleComponent::Update(UFG::TargetingSystemVehicleComponent *this, float delta_sec)
{
  UFG::TargetingSystemBaseComponent::updateMySpawnPointTarget((UFG::TargetingSystemBaseComponent *)&this[-1].mNext);
}

