// File Line: 28
// RVA: 0x14AEA40
__int64 dynamic_initializer_for__UFG::AIOutlineRegion::s_AIOutlineRegionList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIOutlineRegion::s_AIOutlineRegionList__);
}

// File Line: 29
// RVA: 0x35D8E0
UFG::ComponentIDDesc *__fastcall UFG::AIOutlineRegion::GetDesc(UFG::AIOutlineRegion *this)
{
  return &UFG::AIOutlineRegion::_TypeIDesc;
}

// File Line: 51
// RVA: 0x32B9F0
void __fastcall UFG::AIOutlineRegion::AIOutlineRegion(UFG::AIOutlineRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v3; // rsi
  UFG::AIOutlineRegion *v4; // rdi
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v5; // rbx
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v6; // rax
  UFG::SimComponent *v7; // rax

  v3 = pSimObj;
  v4 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x30000u);
  v5 = (UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIOutlineRegion::`vftable';
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::AIOutlineRegion::_AIOutlineRegionTypeUID,
    "AIOutlineRegion");
  v6 = UFG::AIOutlineRegion::s_AIOutlineRegionList.mNode.mPrev;
  UFG::AIOutlineRegion::s_AIOutlineRegionList.mNode.mPrev->mNext = (UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *)&UFG::AIOutlineRegion::s_AIOutlineRegionList;
  UFG::AIOutlineRegion::s_AIOutlineRegionList.mNode.mPrev = (UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *)&v4->mPrev;
  if ( v3 )
    v7 = UFG::SimObject::GetComponentOfType(v3, UFG::RegionComponent::_TypeUID);
  else
    v7 = 0i64;
  v4->mpRegion = (UFG::RegionComponent *)v7;
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
  UFG::AIOutlineRegion *v1; // r8
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v2; // rdx
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v3; // rcx
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v4; // rax
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v5; // rcx
  UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIOutlineRegion::`vftable';
  if ( this == UFG::AIOutlineRegion::s_AIOutlineRegionpCurrentIterator )
    UFG::AIOutlineRegion::s_AIOutlineRegionpCurrentIterator = (UFG::AIOutlineRegion *)&this->mPrev[-7];
  v2 = (UFG::qNode<UFG::AIOutlineRegion,UFG::AIOutlineRegion> *)&this->mPrev;
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
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 102
// RVA: 0x37E4C0
void __fastcall UFG::AIOutlineRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
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
  v3 = UFG::qMemoryPool::Allocate(v2, 0x88ui64, "AIOutlineRegion", 0i64, 1u);
  v7 = v3;
  if ( v3 )
  {
    v4 = v1->m_pSimObject;
    v5 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::AIOutlineRegion::AIOutlineRegion((UFG::AIOutlineRegion *)v3, v5, v4);
  }
}

