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
  return atexit(dynamic_atexit_destructor_for__UFG::StartRegion::m_StartRegions__);
}

// File Line: 31
// RVA: 0x419360
signed __int64 __fastcall UFG::StartRegion::GetType(UFG::StartRegion *this)
{
  return 0x1000000i64;
}

// File Line: 42
// RVA: 0x4195E0
void __fastcall UFG::StartRegion::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObjectProps)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v7; // [rsp+70h] [rbp+18h]

  v1 = sceneObjectProps;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x148ui64, "StartRegion", 0i64, 1u);
  v7 = v3;
  if ( v3 )
  {
    v4 = v1->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v1->m_NameUID);
    UFG::StartRegion::StartRegion((UFG::StartRegion *)v3, v5, v4);
  }
}

// File Line: 67
// RVA: 0x418D70
void __fastcall UFG::StartRegion::StartRegion(UFG::StartRegion *this, UFG::qSymbol *name, UFG::SimObject *simObj)
{
  UFG::SimObject *v3; // rdi
  UFG::qSymbol *v4; // rbx
  UFG::StartRegion *v5; // rsi
  unsigned int v6; // eax

  v3 = simObj;
  v4 = name;
  v5 = this;
  UFG::TriggerRegion::TriggerRegion((UFG::TriggerRegion *)&this->vfptr, name, simObj, 1);
  v6 = v4->mUID;
  v5->mNode.mParent = 0i64;
  v5->mNode.mChild[0] = 0i64;
  v5->mNode.mChild[1] = 0i64;
  v5->mNode.mUID = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StartRegion::`vftable;
  v5->m_IsAvailable = 1;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v5->vfptr, UFG::StartRegion::_StartRegionTypeUID, "StartRegion");
  UFG::StartRegion::InitTrigger(v5, v3);
}

// File Line: 74
// RVA: 0x419380
void __fastcall UFG::StartRegion::InitTrigger(UFG::StartRegion *this, UFG::SimObject *simObj)
{
  UFG::qBaseNodeRB *v2; // rbx
  UFG::StartRegion *v3; // rdi
  UFG::SimComponent *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = 0i64;
  v3 = this;
  if ( simObj )
    v4 = UFG::SimObject::GetComponentOfType(simObj, UFG::RegionComponent::_TypeUID);
  else
    v4 = 0i64;
  v5 = &v3->mpRegion;
  if ( v3->mpRegion.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v3->mpRegion.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v3->mpRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mpRegion.mPrev;
  }
  v3->mpRegion.m_pPointer = v4;
  if ( v4 )
  {
    v8 = &v4->m_SafePointerList;
    v9 = v4->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mPrev = v9;
    v3->mpRegion.mNext = &v8->mNode;
    v8->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  if ( v3 )
    v2 = &v3->mNode;
  UFG::qBaseTreeRB::Add(&UFG::StartRegion::m_StartRegions.mTree, v2);
}

