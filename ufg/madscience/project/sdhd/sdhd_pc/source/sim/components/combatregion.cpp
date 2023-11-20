// File Line: 55
// RVA: 0x532410
const char *__fastcall UFG::CombatRegion::GetTypeName(UFG::CombatRegion *this)
{
  return "CombatRegion";
}

// File Line: 57
// RVA: 0x15438D0
__int64 dynamic_initializer_for__UFG::CombatRegion::msCombatRegions__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::CombatRegion::msCombatRegions.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::CombatRegion::msCombatRegions__);
}

// File Line: 101
// RVA: 0x516CB0
void __fastcall UFG::CombatRegion::CombatRegion(UFG::CombatRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj, bool init)
{
  bool v4; // di
  UFG::SimObject *v5; // r14
  UFG::qSymbol *v6; // rbx
  UFG::CombatRegion *v7; // rsi
  unsigned int v8; // eax
  UFG::SimComponent *v9; // rbp

  v4 = init;
  v5 = pSimObj;
  v6 = name;
  v7 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x30000u);
  v8 = v6->mUID;
  v9 = 0i64;
  v7->mNode.mParent = 0i64;
  v7->mNode.mChild[0] = 0i64;
  v7->mNode.mChild[1] = 0i64;
  v7->mNode.mUID = v8;
  UFG::qSafePointerNode<UFG::CombatRegion>::qSafePointerNode<UFG::CombatRegion>((UFG::qSafePointerNode<UFG::CombatRegion> *)&v7->vfptr);
  v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CombatRegion::`vftable'{for `UFG::MarkerBase'};
  v7->vfptr = (UFG::qSafePointerNode<UFG::CombatRegion>Vtbl *)&UFG::CombatRegion::`vftable'{for `UFG::qSafePointerNode<UFG::CombatRegion>'};
  UFG::SimComponent::AddType((UFG::SimComponent *)&v7->vfptr, UFG::CombatRegion::_CombatRegionTypeUID, "CombatRegion");
  if ( v4 )
  {
    if ( v5 )
      v9 = UFG::SimObject::GetComponentOfType(v5, UFG::RegionComponent::_TypeUID);
    v7->mpRegion = (UFG::RegionComponent *)v9;
    UFG::qBaseTreeRB::Add(&UFG::CombatRegion::msCombatRegions.mTree, &v7->mNode);
  }
}

// File Line: 121
// RVA: 0x53A910
bool __fastcall UFG::CombatRegion::IsHitPoint(UFG::CombatRegion *this, UFG::qVector3 *vPoint)
{
  return UFG::RegionComponent::IsHitPoint(this->mpRegion, vPoint);
}

// File Line: 130
// RVA: 0x5391E0
void __fastcall UFG::CombatRegion::InitRegion(UFG::CombatRegion *this, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v2; // rax
  UFG::CombatRegion *v3; // rbx

  v2 = pSimObj;
  v3 = this;
  if ( pSimObj )
    v2 = (UFG::SimObject *)UFG::SimObject::GetComponentOfType(pSimObj, UFG::RegionComponent::_TypeUID);
  v3->mpRegion = (UFG::RegionComponent *)v2;
  UFG::qBaseTreeRB::Add(&UFG::CombatRegion::msCombatRegions.mTree, &v3->mNode);
}

// File Line: 160
// RVA: 0x51B390
void __fastcall UFG::CombatRegion::~CombatRegion(UFG::CombatRegion *this)
{
  UFG::CombatRegion *v1; // rdi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CombatRegion::`vftable'{for `UFG::MarkerBase'};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<UFG::CombatRegion>Vtbl *)&UFG::CombatRegion::`vftable'{for `UFG::qSafePointerNode<UFG::CombatRegion>'};
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::CombatRegion::msCombatRegions,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->mNode);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::CombatRegion>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)((char *)v2 + 8);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)v2);
  v3 = v2->vfptr;
  v4 = v2->m_SafePointerList.mNode.mPrev;
  v3[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v4;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v2;
  v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v2;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 268
// RVA: 0x5355A0
bool __fastcall UFG::CombatRegion::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentCombatRegion.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 278
// RVA: 0x544DC0
void __fastcall UFG::CombatRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v7; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xB0ui64, "CombatRegion", 0i64, 1u);
  v7 = v3;
  if ( v3 )
  {
    v4 = v1->m_pSimObject;
    v5 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::CombatRegion::CombatRegion((UFG::CombatRegion *)v3, v5, v4, 1);
  }
}

