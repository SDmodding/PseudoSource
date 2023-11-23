// File Line: 21
// RVA: 0x419370
const char *__fastcall UFG::StartRegion::GetTypeName(UFG::StartRegion *this)
{
  return "StartRegion";
}

// File Line: 22
// RVA: 0x14F2420
__int64 dynamic_initializer_for__UFG::StartRegion::m_StartRegions__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::StartRegion::m_StartRegions.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StartRegion::m_StartRegions__);
}

// File Line: 31
// RVA: 0x419360
__int64 __fastcall UFG::StartRegion::GetType(UFG::StartRegion *this)
{
  return 0x1000000i64;
}

// File Line: 42
// RVA: 0x4195E0
void __fastcall UFG::StartRegion::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObjectProps)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v7; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x148ui64, "StartRegion", 0i64, 1u);
  v7 = v3;
  if ( v3 )
  {
    m_pSimObject = sceneObjectProps->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, sceneObjectProps->m_NameUID);
    UFG::StartRegion::StartRegion((UFG::StartRegion *)v3, v5, m_pSimObject);
  }
}

// File Line: 67
// RVA: 0x418D70
void __fastcall UFG::StartRegion::StartRegion(UFG::StartRegion *this, UFG::qSymbol *name, UFG::SimObject *simObj)
{
  unsigned int mUID; // eax

  UFG::TriggerRegion::TriggerRegion(this, name, simObj, 1);
  mUID = name->mUID;
  this->UFG::qNodeRB<UFG::StartRegion>::mNode.mParent = 0i64;
  this->UFG::qNodeRB<UFG::StartRegion>::mNode.mChild[0] = 0i64;
  this->UFG::qNodeRB<UFG::StartRegion>::mNode.mChild[1] = 0i64;
  this->UFG::qNodeRB<UFG::StartRegion>::mNode.mUID = mUID;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StartRegion::`vftable;
  this->m_IsAvailable = 1;
  UFG::SimComponent::AddType(this, UFG::StartRegion::_StartRegionTypeUID, "StartRegion");
  UFG::StartRegion::InitTrigger(this, simObj);
}

// File Line: 74
// RVA: 0x419380
void __fastcall UFG::StartRegion::InitTrigger(UFG::StartRegion *this, UFG::SimObject *simObj)
{
  UFG::qNodeRB<UFG::StartRegion> *v2; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mpRegion; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = 0i64;
  if ( simObj )
    ComponentOfType = UFG::SimObject::GetComponentOfType(simObj, UFG::RegionComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  p_mpRegion = &this->mpRegion;
  if ( this->mpRegion.m_pPointer )
  {
    mPrev = p_mpRegion->mPrev;
    mNext = this->mpRegion.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpRegion->mPrev = p_mpRegion;
    this->mpRegion.mNext = &this->mpRegion;
  }
  this->mpRegion.m_pPointer = ComponentOfType;
  if ( ComponentOfType )
  {
    p_mNode = &ComponentOfType->m_SafePointerList.mNode;
    v9 = ComponentOfType->m_SafePointerList.mNode.mPrev;
    v9->mNext = p_mpRegion;
    p_mpRegion->mPrev = v9;
    this->mpRegion.mNext = p_mNode;
    p_mNode->mPrev = p_mpRegion;
  }
  if ( this )
    v2 = &this->UFG::qNodeRB<UFG::StartRegion>;
  UFG::qBaseTreeRB::Add(&UFG::StartRegion::m_StartRegions.mTree, &v2->mNode);
}

