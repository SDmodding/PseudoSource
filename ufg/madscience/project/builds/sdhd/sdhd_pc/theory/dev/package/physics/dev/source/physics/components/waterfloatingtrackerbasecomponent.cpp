// File Line: 21
// RVA: 0x1458E00
__int64 dynamic_initializer_for__UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList__);
}

// File Line: 22
// RVA: 0xAB770
signed __int64 __fastcall UFG::WaterFloatingTrackerBaseComponent::GetTypeSize(UFG::GunRecoilPostEffect *this)
{
  return 88i64;
}

// File Line: 28
// RVA: 0x9A290
void __fastcall UFG::WaterFloatingTrackerBaseComponent::WaterFloatingTrackerBaseComponent(UFG::WaterFloatingTrackerBaseComponent *this, unsigned int name_uid, hkpRigidBody *body)
{
  UFG::WaterFloatingTrackerBaseComponent *v3; // rbx
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v4; // rdx
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v5; // rax

  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  v4 = (UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterFloatingTrackerBaseComponent::`vftable{for `UFG::SimComponent};
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::WaterFloatingTrackerBaseComponent::`vftable{for `UFG::UpdateInterface};
  v5 = UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList.mNode.mPrev;
  UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *)&UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList;
  UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList.mNode.mPrev = (UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::WaterFloatingTrackerBaseComponent::_WaterFloatingTrackerBaseComponentTypeUID,
    "WaterFloatingTrackerBaseComponent");
}

// File Line: 36
// RVA: 0x9D650
void __fastcall UFG::WaterFloatingTrackerBaseComponent::~WaterFloatingTrackerBaseComponent(UFG::WaterFloatingTrackerBaseComponent *this)
{
  UFG::WaterFloatingTrackerBaseComponent *v1; // r8
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v2; // rdx
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v3; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v4; // rax
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v5; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterFloatingTrackerBaseComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::WaterFloatingTrackerBaseComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentpCurrentIterator )
    UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentpCurrentIterator = (UFG::WaterFloatingTrackerBaseComponent *)&this->mPrev[-5].mNext;
  v2 = (UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *)&this->mPrev;
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
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

