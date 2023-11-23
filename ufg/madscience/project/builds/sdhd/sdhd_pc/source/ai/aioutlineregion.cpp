// File Line: 28
// RVA: 0x14AEA40
__int64 dynamic_initializer_for__UFG::AIOutlineRegion::s_AIOutlineRegionList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIOutlineRegion::s_AIOutlineRegionList__);
}

// File Line: 29
// RVA: 0x35D8E0
UFG::ComponentIDDesc *__fastcall UFG::AIOutlineRegion::GetDesc(UFG::AIOutlineRegion *this)
{
  return &UFG::AIOutlineRegion::_TypeIDesc;
}

// File Line: 51
// RVA: 0x32B9F0
void __fastcall UFG::AIOutlineRegion::AIOutlineRegion(
        UFG::AIOutlineRegion *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj)
{
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *mPrev; // rax
  UFG::RegionComponent *ComponentOfType; // rax

  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x30000u);
  this->mPrev = &this->UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion>;
  this->mNext = &this->UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIOutlineRegion::`vftable;
  UFG::SimComponent::AddType(this, UFG::AIOutlineRegion::_AIOutlineRegionTypeUID, "AIOutlineRegion");
  mPrev = UFG::AIOutlineRegion::s_AIOutlineRegionList.mNode.mPrev;
  UFG::AIOutlineRegion::s_AIOutlineRegionList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *)&UFG::AIOutlineRegion::s_AIOutlineRegionList;
  UFG::AIOutlineRegion::s_AIOutlineRegionList.mNode.mPrev = &this->UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion>;
  if ( pSimObj )
    ComponentOfType = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(
                                                pSimObj,
                                                UFG::RegionComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  this->mpRegion = ComponentOfType;
}

// File Line: 68
// RVA: 0x3688A0
void __fastcall UFG::AIOutlineRegion::InitRegion(UFG::AIOutlineRegion *this, UFG::SimObject *pSimObj)
{
  if ( pSimObj )
    this->mpRegion = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(pSimObj, UFG::RegionComponent::_TypeUID);
  else
    this->mpRegion = 0i64;
}

// File Line: 76
// RVA: 0x334660
void __fastcall UFG::AIOutlineRegion::~AIOutlineRegion(UFG::AIOutlineRegion *this)
{
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v2; // rdx
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *mPrev; // rcx
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *mNext; // rax
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v5; // rcx
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIOutlineRegion::`vftable;
  if ( this == UFG::AIOutlineRegion::s_AIOutlineRegionpCurrentIterator )
    UFG::AIOutlineRegion::s_AIOutlineRegionpCurrentIterator = (UFG::AIOutlineRegion *)&this->mPrev[-7];
  v2 = &this->UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion>;
  mPrev = this->mPrev;
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
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 102
// RVA: 0x37E4C0
void __fastcall UFG::AIOutlineRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v7; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x88ui64, "AIOutlineRegion", 0i64, 1u);
  v7 = v3;
  if ( v3 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v5 = UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, &result);
    UFG::AIOutlineRegion::AIOutlineRegion((UFG::AIOutlineRegion *)v3, v5, m_pSimObject);
  }
}

