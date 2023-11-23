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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CombatRegion::msCombatRegions__);
}

// File Line: 101
// RVA: 0x516CB0
void __fastcall UFG::CombatRegion::CombatRegion(
        UFG::CombatRegion *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj,
        bool init)
{
  unsigned int mUID; // eax
  UFG::RegionComponent *ComponentOfType; // rbp

  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x30000u);
  mUID = name->mUID;
  ComponentOfType = 0i64;
  this->UFG::qNodeRB<UFG::CombatRegion>::mNode.mParent = 0i64;
  this->UFG::qNodeRB<UFG::CombatRegion>::mNode.mChild[0] = 0i64;
  this->UFG::qNodeRB<UFG::CombatRegion>::mNode.mChild[1] = 0i64;
  this->UFG::qNodeRB<UFG::CombatRegion>::mNode.mUID = mUID;
  UFG::qSafePointerNode<UFG::CombatRegion>::qSafePointerNode<UFG::CombatRegion>(&this->UFG::qSafePointerNode<UFG::CombatRegion>);
  this->UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CombatRegion::`vftable{for `UFG::MarkerBase};
  this->UFG::qSafePointerNode<UFG::CombatRegion>::vfptr = (UFG::qSafePointerNode<UFG::CombatRegion>Vtbl *)&UFG::CombatRegion::`vftable{for `UFG::qSafePointerNode<UFG::CombatRegion>};
  UFG::SimComponent::AddType(this, UFG::CombatRegion::_CombatRegionTypeUID, "CombatRegion");
  if ( init )
  {
    if ( pSimObj )
      ComponentOfType = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(
                                                  pSimObj,
                                                  UFG::RegionComponent::_TypeUID);
    this->mpRegion = ComponentOfType;
    UFG::qBaseTreeRB::Add(&UFG::CombatRegion::msCombatRegions.mTree, &this->UFG::qNodeRB<UFG::CombatRegion>::mNode);
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
void __fastcall UFG::CombatRegion::InitRegion(UFG::CombatRegion *this, UFG::RegionComponent *pSimObj)
{
  UFG::RegionComponent *ComponentOfType; // rax

  ComponentOfType = pSimObj;
  if ( pSimObj )
    ComponentOfType = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)pSimObj,
                                                UFG::RegionComponent::_TypeUID);
  this->mpRegion = ComponentOfType;
  UFG::qBaseTreeRB::Add(&UFG::CombatRegion::msCombatRegions.mTree, &this->UFG::qNodeRB<UFG::CombatRegion>::mNode);
}

// File Line: 160
// RVA: 0x51B390
void __fastcall UFG::CombatRegion::~CombatRegion(UFG::CombatRegion *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *vfptr; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rax

  this->UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CombatRegion::`vftable{for `UFG::MarkerBase};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<UFG::CombatRegion>;
  this->UFG::qSafePointerNode<UFG::CombatRegion>::vfptr = (UFG::qSafePointerNode<UFG::CombatRegion>Vtbl *)&UFG::CombatRegion::`vftable{for `UFG::qSafePointerNode<UFG::CombatRegion>};
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::CombatRegion::msCombatRegions,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::CombatRegion>);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::CombatRegion>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)((char *)v2 + 8);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)v2);
  vfptr = v2->vfptr;
  mPrev = v2->m_SafePointerList.mNode.mPrev;
  vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))mPrev;
  mPrev->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)vfptr;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v2;
  v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v2;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 268
// RVA: 0x5355A0
bool __fastcall UFG::CombatRegion::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentCombatRegion,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 278
// RVA: 0x544DC0
void __fastcall UFG::CombatRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v7; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xB0ui64, "CombatRegion", 0i64, 1u);
  v7 = v3;
  if ( v3 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, (UFG::qWiseSymbol *)&result);
    UFG::CombatRegion::CombatRegion((UFG::CombatRegion *)v3, v5, m_pSimObject, 1);
  }
}

