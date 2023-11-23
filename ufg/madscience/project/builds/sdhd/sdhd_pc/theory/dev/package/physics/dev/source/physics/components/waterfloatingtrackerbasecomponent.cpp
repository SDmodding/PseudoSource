// File Line: 21
// RVA: 0x1458E00
__int64 dynamic_initializer_for__UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList__);
}

// File Line: 22
// RVA: 0xAB770
__int64 __fastcall UFG::WaterFloatingTrackerBaseComponent::GetTypeSize(UFG::GunRecoilPostEffect *this)
{
  return 88i64;
}

// File Line: 28
// RVA: 0x9A290
void __fastcall UFG::WaterFloatingTrackerBaseComponent::WaterFloatingTrackerBaseComponent(
        UFG::WaterFloatingTrackerBaseComponent *this,
        unsigned int name_uid,
        hkpRigidBody *body)
{
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>;
  this->mNext = &this->UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterFloatingTrackerBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::WaterFloatingTrackerBaseComponent::`vftable{for `UFG::UpdateInterface};
  mPrev = UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList.mNode.mPrev;
  UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *)&UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList;
  UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentList.mNode.mPrev = &this->UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::WaterFloatingTrackerBaseComponent::_WaterFloatingTrackerBaseComponentTypeUID,
    "WaterFloatingTrackerBaseComponent");
}

// File Line: 36
// RVA: 0x9D650
void __fastcall UFG::WaterFloatingTrackerBaseComponent::~WaterFloatingTrackerBaseComponent(
        UFG::WaterFloatingTrackerBaseComponent *this)
{
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v2; // rdx
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *mPrev; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *mNext; // rax
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v5; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v6; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterFloatingTrackerBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::WaterFloatingTrackerBaseComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentpCurrentIterator )
    UFG::WaterFloatingTrackerBaseComponent::s_WaterFloatingTrackerBaseComponentpCurrentIterator = (UFG::WaterFloatingTrackerBaseComponent *)&this->mPrev[-5].mNext;
  v2 = &this->UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>;
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
  UFG::SimComponent::~SimComponent(this);
}

