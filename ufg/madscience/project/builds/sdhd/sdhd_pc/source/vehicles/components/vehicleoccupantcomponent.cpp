// File Line: 27
// RVA: 0x157B8F0
__int64 dynamic_initializer_for__UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList__);
}

// File Line: 28
// RVA: 0x67B530
__int64 __fastcall UFG::HasAttackRequestComponent::GetTypeSize(UFG::qReflectInventory<UFG::DUIPopupMenuWindow> *this)
{
  return 376i64;
}

// File Line: 44
// RVA: 0x66B610
void __fastcall UFG::VehicleOccupantComponent::VehicleOccupantComponent(
        UFG::VehicleOccupantComponent *this,
        UFG::SceneObjectProperties *sceneObject)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mpReservations; // rsi
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v26; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v32; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax

  UFG::SimComponent::SimComponent(this, sceneObject->m_NameUID);
  this->mPrev = &this->UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent>;
  this->mNext = &this->UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleOccupantComponent::`vftable;
  this->mpParkingSpot = 0i64;
  this->mpDriver.mPrev = &this->mpDriver;
  this->mpDriver.mNext = &this->mpDriver;
  this->mpDriver.m_pPointer = 0i64;
  this->mPassengers.mNode.mPrev = &this->mPassengers.mNode;
  this->mPassengers.mNode.mNext = &this->mPassengers.mNode;
  mpReservations = this->mpReservations;
  `eh vector constructor iterator(
    this->mpReservations,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  this->mSeatCount = 0;
  UFG::SimComponent::AddType(
    this,
    UFG::VehicleOccupantComponent::_VehicleOccupantComponentTypeUID,
    "VehicleOccupantComponent");
  mPrev = UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mPrev;
  UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList;
  UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mPrev = &this->UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent>;
  if ( this->mpReservations[0].m_pPointer )
  {
    v6 = mpReservations->mPrev;
    mNext = this->mpReservations[0].mNext;
    v6->mNext = mNext;
    mNext->mPrev = v6;
    mpReservations->mPrev = mpReservations;
    this->mpReservations[0].mNext = this->mpReservations;
  }
  this->mpReservations[0].m_pPointer = 0i64;
  v8 = &this->mpReservations[1];
  if ( this->mpReservations[1].m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = this->mpReservations[1].mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = v8;
    this->mpReservations[1].mNext = &this->mpReservations[1];
  }
  this->mpReservations[1].m_pPointer = 0i64;
  v11 = &this->mpReservations[2];
  if ( this->mpReservations[2].m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = this->mpReservations[2].mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = v11;
    this->mpReservations[2].mNext = &this->mpReservations[2];
  }
  this->mpReservations[2].m_pPointer = 0i64;
  v14 = &this->mpReservations[3];
  if ( this->mpReservations[3].m_pPointer )
  {
    v15 = v14->mPrev;
    v16 = this->mpReservations[3].mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = v14;
    this->mpReservations[3].mNext = &this->mpReservations[3];
  }
  this->mpReservations[3].m_pPointer = 0i64;
  v17 = &this->mpReservations[4];
  if ( this->mpReservations[4].m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = this->mpReservations[4].mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = v17;
    this->mpReservations[4].mNext = &this->mpReservations[4];
  }
  this->mpReservations[4].m_pPointer = 0i64;
  v20 = &this->mpReservations[5];
  if ( this->mpReservations[5].m_pPointer )
  {
    v21 = v20->mPrev;
    v22 = this->mpReservations[5].mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    v20->mPrev = v20;
    this->mpReservations[5].mNext = &this->mpReservations[5];
  }
  this->mpReservations[5].m_pPointer = 0i64;
  v23 = &this->mpReservations[6];
  if ( this->mpReservations[6].m_pPointer )
  {
    v24 = v23->mPrev;
    v25 = this->mpReservations[6].mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    v23->mPrev = v23;
    this->mpReservations[6].mNext = &this->mpReservations[6];
  }
  this->mpReservations[6].m_pPointer = 0i64;
  v26 = &this->mpReservations[7];
  if ( this->mpReservations[7].m_pPointer )
  {
    v27 = v26->mPrev;
    v28 = this->mpReservations[7].mNext;
    v27->mNext = v28;
    v28->mPrev = v27;
    v26->mPrev = v26;
    this->mpReservations[7].mNext = &this->mpReservations[7];
  }
  this->mpReservations[7].m_pPointer = 0i64;
  v29 = &this->mpReservations[8];
  if ( this->mpReservations[8].m_pPointer )
  {
    v30 = v29->mPrev;
    v31 = this->mpReservations[8].mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    v29->mPrev = v29;
    this->mpReservations[8].mNext = &this->mpReservations[8];
  }
  this->mpReservations[8].m_pPointer = 0i64;
  v32 = &this->mpReservations[9];
  if ( this->mpReservations[9].m_pPointer )
  {
    v33 = v32->mPrev;
    v34 = this->mpReservations[9].mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v32->mPrev = v32;
    this->mpReservations[9].mNext = &this->mpReservations[9];
  }
  this->mpReservations[9].m_pPointer = 0i64;
  this->mSeatCount = PropertyUtils::Get<unsigned long>(sceneObject, (UFG::qArray<unsigned long,0> *)&qSymbol_SeatCount)->mFlags;
}

// File Line: 60
// RVA: 0x66D600
void __fastcall UFG::VehicleOccupantComponent::~VehicleOccupantComponent(UFG::VehicleOccupantComponent *this)
{
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v2; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *i; // r8
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v4; // rdx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *mPrev; // rcx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *mNext; // rax
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v7; // rdi
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v8; // rdx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpDriver; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v15; // rcx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v16; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleOccupantComponent::`vftable;
  v2 = this->mPassengers.mNode.mNext - 4;
  for ( i = &this->m_BoundComponentHandles;
        v2 != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)i;
        v2 = this->mPassengers.mNode.mNext - 4 )
  {
    v4 = v2 + 4;
    mPrev = v2[4].mPrev;
    mNext = v2[4].mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  if ( this == UFG::VehicleOccupantComponent::s_VehicleOccupantComponentpCurrentIterator )
    UFG::VehicleOccupantComponent::s_VehicleOccupantComponentpCurrentIterator = (UFG::VehicleOccupantComponent *)&this->mPrev[-4];
  v7 = &this->UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent>;
  v8 = this->mPrev;
  v9 = this->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->mPrev = &this->UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent>;
  this->mNext = &this->UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent>;
  `eh vector destructor iterator(
    this->mpReservations,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  UFG::qList<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList,0,0>::~qList<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList,0,0>((UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *)&this->mPassengers);
  p_mpDriver = &this->mpDriver;
  if ( this->mpDriver.m_pPointer )
  {
    v11 = p_mpDriver->mPrev;
    v12 = this->mpDriver.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_mpDriver->mPrev = p_mpDriver;
    this->mpDriver.mNext = &this->mpDriver;
  }
  this->mpDriver.m_pPointer = 0i64;
  v13 = p_mpDriver->mPrev;
  v14 = this->mpDriver.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_mpDriver->mPrev = p_mpDriver;
  this->mpDriver.mNext = &this->mpDriver;
  v15 = v7->mPrev;
  v16 = this->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v7->mPrev = v7;
  this->mNext = &this->UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 74
// RVA: 0x67D0B0
bool __fastcall UFG::VehicleOccupantComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentVehicleOccupant);
}

// File Line: 80
// RVA: 0x687C00
UFG::VehicleOccupantComponent *__fastcall UFG::VehicleOccupantComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *sceneObject)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::VehicleOccupantComponent *v4; // rax
  UFG::VehicleOccupantComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x178ui64, "VehicleOccupantComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::VehicleOccupantComponent::VehicleOccupantComponent((UFG::VehicleOccupantComponent *)v3, sceneObject);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags >= 0 )
    v8 = -1;
  else
    v8 = 30;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v5, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  UFG::VehicleOccupantComponent::SetupPassengerData(v5, sceneObject);
  return v5;
}

// File Line: 92
// RVA: 0x683980
void __fastcall UFG::VehicleOccupantComponent::OnAttach(UFG::VehicleOccupantComponent *this, UFG::SimObject *object)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mpReservations; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v21; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v30; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax

  mpReservations = this->mpReservations;
  if ( mpReservations->m_pPointer )
  {
    mPrev = mpReservations->mPrev;
    mNext = mpReservations->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mpReservations->mPrev = mpReservations;
    mpReservations->mNext = mpReservations;
  }
  v6 = &this->mpReservations[1];
  mpReservations->m_pPointer = 0i64;
  if ( this->mpReservations[1].m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = this->mpReservations[1].mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    this->mpReservations[1].mNext = &this->mpReservations[1];
  }
  this->mpReservations[1].m_pPointer = 0i64;
  v9 = &this->mpReservations[2];
  if ( this->mpReservations[2].m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = this->mpReservations[2].mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = v9;
    this->mpReservations[2].mNext = &this->mpReservations[2];
  }
  this->mpReservations[2].m_pPointer = 0i64;
  v12 = &this->mpReservations[3];
  if ( this->mpReservations[3].m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = this->mpReservations[3].mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = v12;
    this->mpReservations[3].mNext = &this->mpReservations[3];
  }
  this->mpReservations[3].m_pPointer = 0i64;
  v15 = &this->mpReservations[4];
  if ( this->mpReservations[4].m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = this->mpReservations[4].mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = v15;
    this->mpReservations[4].mNext = &this->mpReservations[4];
  }
  this->mpReservations[4].m_pPointer = 0i64;
  v18 = &this->mpReservations[5];
  if ( this->mpReservations[5].m_pPointer )
  {
    v19 = v18->mPrev;
    v20 = this->mpReservations[5].mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v18->mPrev = v18;
    this->mpReservations[5].mNext = &this->mpReservations[5];
  }
  this->mpReservations[5].m_pPointer = 0i64;
  v21 = &this->mpReservations[6];
  if ( this->mpReservations[6].m_pPointer )
  {
    v22 = v21->mPrev;
    v23 = this->mpReservations[6].mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    v21->mPrev = v21;
    this->mpReservations[6].mNext = &this->mpReservations[6];
  }
  this->mpReservations[6].m_pPointer = 0i64;
  v24 = &this->mpReservations[7];
  if ( this->mpReservations[7].m_pPointer )
  {
    v25 = v24->mPrev;
    v26 = this->mpReservations[7].mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mPrev = v24;
    this->mpReservations[7].mNext = &this->mpReservations[7];
  }
  this->mpReservations[7].m_pPointer = 0i64;
  v27 = &this->mpReservations[8];
  if ( this->mpReservations[8].m_pPointer )
  {
    v28 = v27->mPrev;
    v29 = this->mpReservations[8].mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v27->mPrev = v27;
    this->mpReservations[8].mNext = &this->mpReservations[8];
  }
  v30 = &this->mpReservations[9];
  v27->m_pPointer = 0i64;
  if ( v30->m_pPointer )
  {
    v31 = v30->mPrev;
    v32 = v30->mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    v30->mPrev = v30;
    v30->mNext = v30;
  }
  v30->m_pPointer = 0i64;
}

// File Line: 103
// RVA: 0x68BA50
void __fastcall UFG::VehicleOccupantComponent::SetupPassengerData(
        UFG::VehicleOccupantComponent *this,
        UFG::SceneObjectProperties *pSOP)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  int v5; // eax

  mpWritableProperties = pSOP->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSOP->mpConstProperties;
  if ( UFG::SimObjectUtility::IsClassType(mpWritableProperties, &qSymbol_Taxi) == 1
    && !(unsigned int)UFG::qRandom(0x64u, (unsigned int *)&UFG::qDefaultSeed) )
  {
    v5 = UFG::qRandom(this->mSeatCount - 2, (unsigned int *)&UFG::qDefaultSeed);
    PropertyUtils::SetRuntime<unsigned long>(
      pSOP,
      (UFG::qArray<unsigned long,0> *)&qSymbol_AmbientPassengerCount,
      v5 + 1);
  }
}

// File Line: 129
// RVA: 0x67D1E0
bool __fastcall UFG::VehicleOccupantComponent::HasPassengers(UFG::VehicleOccupantComponent *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  int v3; // edx
  UFG::VehicleOccupantComponent *v4; // rax
  UFG::SimObject *m_pSimObject; // rax

  m_pSceneObj = 0i64;
  v3 = 0;
  v4 = (UFG::VehicleOccupantComponent *)&this->mPassengers.mNode.mNext[-4];
  if ( v4 != (UFG::VehicleOccupantComponent *)&this->m_BoundComponentHandles )
  {
    do
    {
      ++v3;
      v4 = (UFG::VehicleOccupantComponent *)&v4->mNext[-4];
    }
    while ( v4 != (UFG::VehicleOccupantComponent *)&this->m_BoundComponentHandles );
    if ( v3 )
      return 1;
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  return PropertyUtils::Get<unsigned long>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_AmbientPassengerCount) != 0i64;
}

// File Line: 151
// RVA: 0x68D0D0
void __fastcall UFG::VehicleOccupantComponent::TeleportEventHandler(
        UFG::VehicleOccupantComponent *this,
        UFG::Event *event)
{
  UFG::allocator::free_link *v4; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v5; // rbx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *i; // rsi
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *mNext; // rdi
  UFG::allocator::free_link *v8; // rax

  if ( this->mpDriver.m_pPointer )
  {
    v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    if ( v4 )
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v4,
        (UFG::qMatrix44 *)&event[1].m_EventUID,
        this->mpDriver.m_pPointer->mNode.mUID,
        0,
        UFG::TeleportEvent::m_Name,
        0);
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  }
  if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)&this->mPassengers.mNode.mNext[-4] != &this->m_BoundComponentHandles )
  {
    v5 = this->mPassengers.mNode.mNext - 4;
    for ( i = &this->m_BoundComponentHandles;
          v5 != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)i;
          v5 = v5[4].mNext - 4 )
    {
      mNext = v5[2].mNext;
      v8 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      if ( v8 )
        UFG::TeleportEvent::TeleportEvent(
          (UFG::TeleportEvent *)v8,
          (UFG::qMatrix44 *)&event[1].m_EventUID,
          (unsigned int)mNext[4].mPrev,
          0,
          UFG::TeleportEvent::m_Name,
          0);
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v8);
    }
  }
}

// File Line: 177
// RVA: 0x66FAE0
void __fastcall UFG::VehicleOccupantComponent::AddOccupant(
        UFG::VehicleOccupantComponent *this,
        UFG::CharacterOccupantComponent *pOccupant,
        bool bDriver)
{
  unsigned int v3; // r9d
  UFG::SimObject *m_pSimObject; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpDriver; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObject *m_pPointer; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mpReservations; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v16; // rax
  UFG::qList<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList,0,0> *p_mPassengers; // rsi
  int v18; // ecx
  UFG::CharacterOccupantComponent *v19; // rdi
  UFG::CharacterOccupantComponent *v20; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v21; // rax
  unsigned int v22; // edx
  UFG::CharacterOccupantComponent *v23; // rax
  UFG::SimObject *Occupant; // rax
  unsigned __int16 *v25; // r8
  __int64 v26; // rdx
  _QWORD *v27; // rcx
  _QWORD *p_mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  int v30; // ecx
  UFG::CharacterOccupantComponent *v31; // rax
  UFG::SimObjectGame *v32; // rcx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rsi
  UFG::SimComponent *v35; // rax
  UFG::SimObjectGame *v36; // rcx
  __int16 v37; // dx
  UFG::StreamedResourceComponent *v38; // rdi
  UFG::SimComponent *v39; // rax
  UFG::qSymbol *SpawnPriority; // rax
  UFG::SimObjectCharacter *v41; // rcx
  __int16 v42; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  UFG::eTargetTypeEnum pTargetType; // [rsp+38h] [rbp+10h] BYREF

  if ( pOccupant )
  {
    v3 = 0;
    if ( bDriver )
    {
      m_pSimObject = pOccupant->m_pSimObject;
      p_mpDriver = &this->mpDriver;
      if ( this->mpDriver.m_pPointer )
      {
        mPrev = p_mpDriver->mPrev;
        mNext = p_mpDriver->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpDriver->mPrev = p_mpDriver;
        p_mpDriver->mNext = p_mpDriver;
      }
      p_mpDriver->m_pPointer = m_pSimObject;
      if ( m_pSimObject )
      {
        v10 = m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v10->mNext = p_mpDriver;
        p_mpDriver->mPrev = v10;
        p_mpDriver->mNext = &m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpDriver;
      }
      m_pPointer = this->mpDriver.m_pPointer;
      mpReservations = this->mpReservations;
      this->mpParkingSpot = 0i64;
      if ( this->mpReservations[0].m_pPointer )
      {
        v13 = mpReservations->mPrev;
        v14 = this->mpReservations[0].mNext;
        v13->mNext = v14;
        v14->mPrev = v13;
        mpReservations->mPrev = mpReservations;
        this->mpReservations[0].mNext = this->mpReservations;
      }
      this->mpReservations[0].m_pPointer = m_pPointer;
      if ( m_pPointer )
      {
        v15 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v15->mNext = mpReservations;
        mpReservations->mPrev = v15;
        this->mpReservations[0].mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = mpReservations;
      }
    }
    else
    {
      v16 = this->mPassengers.mNode.mNext;
      p_mPassengers = &this->mPassengers;
      v18 = -1;
      v19 = (UFG::CharacterOccupantComponent *)&p_mPassengers[-4];
      v20 = (UFG::CharacterOccupantComponent *)&v16[-4];
      if ( v20 == (UFG::CharacterOccupantComponent *)&p_mPassengers[-4] )
        goto LABEL_16;
      while ( 1 )
      {
        ++v18;
        if ( v20 == pOccupant )
          break;
        v20 = (UFG::CharacterOccupantComponent *)&v20->mNext[-4];
        if ( v20 == v19 )
          goto LABEL_16;
      }
      if ( v18 == -1 )
      {
LABEL_16:
        v21 = p_mPassengers->mNode.mPrev;
        v21->mNext = &pOccupant->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
        pOccupant->mPrev = v21;
        pOccupant->mNext = &p_mPassengers->mNode;
        p_mPassengers->mNode.mPrev = &pOccupant->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
      }
      v22 = -1;
      v23 = (UFG::CharacterOccupantComponent *)&p_mPassengers->mNode.mNext[-4];
      if ( v23 == v19 )
      {
LABEL_20:
        v22 = -1;
      }
      else
      {
        while ( 1 )
        {
          ++v22;
          if ( v23 == pOccupant )
            break;
          v23 = (UFG::CharacterOccupantComponent *)&v23->mNext[-4];
          if ( v23 == v19 )
            goto LABEL_20;
        }
      }
      pTargetType = eTARGET_TYPE_INVALID;
      if ( this->mpDriver.m_pPointer )
        ++v22;
      Occupant = UFG::VehicleOccupantComponent::GetOccupant(this, v22, &pTargetType);
      v25 = &this->m_Flags + 12 * pTargetType;
      if ( *((_QWORD *)v25 + 2) )
      {
        v26 = *(_QWORD *)v25;
        v27 = (_QWORD *)*((_QWORD *)v25 + 1);
        *(_QWORD *)(v26 + 8) = v27;
        *v27 = v26;
        *(_QWORD *)v25 = v25;
        *((_QWORD *)v25 + 1) = v25;
      }
      *((_QWORD *)v25 + 2) = Occupant;
      if ( Occupant )
      {
        p_mPrev = &Occupant->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v29 = Occupant->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v29->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v25;
        *(_QWORD *)v25 = v29;
        *((_QWORD *)v25 + 1) = p_mPrev;
        *p_mPrev = v25;
      }
      v30 = -1;
      v31 = (UFG::CharacterOccupantComponent *)&p_mPassengers->mNode.mNext[-4];
      if ( v31 == v19 )
      {
LABEL_30:
        v30 = -1;
      }
      else
      {
        while ( 1 )
        {
          ++v30;
          if ( v31 == pOccupant )
            break;
          v31 = (UFG::CharacterOccupantComponent *)&v31->mNext[-4];
          if ( v31 == v19 )
            goto LABEL_30;
        }
      }
      v3 = v30 + 1;
    }
    UFG::CharacterOccupantComponent::SetVehicleOccupantComponent(pOccupant, this, v3);
    v32 = (UFG::SimObjectGame *)pOccupant->m_pSimObject;
    if ( v32 )
    {
      m_Flags = v32->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)v32->m_Components.p[10].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)v32->m_Components.p[7].m_pComponent;
        }
        else
        {
          v35 = (m_Flags & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v32, UFG::StreamedResourceComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v32, UFG::StreamedResourceComponent::_TypeUID);
          m_pComponent = (UFG::StreamedResourceComponent *)v35;
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)v32->m_Components.p[10].m_pComponent;
      }
      if ( m_pComponent )
      {
        v36 = (UFG::SimObjectGame *)this->m_pSimObject;
        if ( v36 )
        {
          v37 = v36->m_Flags;
          if ( (v37 & 0x4000) != 0 )
          {
            v38 = (UFG::StreamedResourceComponent *)v36->m_Components.p[10].m_pComponent;
          }
          else if ( v37 >= 0 )
          {
            if ( (v37 & 0x2000) != 0 )
            {
              v38 = (UFG::StreamedResourceComponent *)v36->m_Components.p[7].m_pComponent;
            }
            else
            {
              v39 = (v37 & 0x1000) != 0
                  ? UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::StreamedResourceComponent::_TypeUID)
                  : UFG::SimObject::GetComponentOfType(v36, UFG::StreamedResourceComponent::_TypeUID);
              v38 = (UFG::StreamedResourceComponent *)v39;
            }
          }
          else
          {
            v38 = (UFG::StreamedResourceComponent *)v36->m_Components.p[10].m_pComponent;
          }
          if ( v38 )
          {
            SpawnPriority = UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64);
            UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v38, SpawnPriority);
          }
        }
      }
    }
    v41 = (UFG::SimObjectCharacter *)pOccupant->m_pSimObject;
    if ( v41 )
    {
      v42 = v41->m_Flags;
      if ( (v42 & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v41);
      }
      else if ( v42 < 0 || (v42 & 0x2000) != 0 || (v42 & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v41,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                          v41,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        *((_BYTE *)ComponentOfTypeHK + 553) |= 4u;
    }
  }
}

// File Line: 234
// RVA: 0x689710
void __fastcall UFG::VehicleOccupantComponent::RemoveOccupant(
        UFG::VehicleOccupantComponent *this,
        UFG::CharacterOccupantComponent *pOccupant)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpDriver; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mpReservations; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v11; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rcx
  int v13; // edx
  UFG::CharacterOccupantComponent *v14; // rax
  __int64 v15; // rdx
  bool v16; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v17; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v18; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v19; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v20; // rcx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v21; // rax
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rsi
  UFG::SimComponent *v25; // rax
  UFG::SimObjectGame *v26; // rcx
  __int16 v27; // dx
  UFG::StreamedResourceComponent *v28; // rdi
  UFG::SimComponent *v29; // rax
  UFG::qSymbol *SpawnPriority; // rax
  UFG::SimObjectCharacter *v31; // rcx
  __int16 v32; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  UFG::eTargetTypeEnum pTargetType; // [rsp+38h] [rbp+10h] BYREF

  if ( pOccupant )
  {
    m_pPointer = this->mpDriver.m_pPointer;
    if ( pOccupant->m_pSimObject == m_pPointer )
    {
      p_mpDriver = &this->mpDriver;
      if ( this->mpDriver.m_pPointer )
      {
        mPrev = p_mpDriver->mPrev;
        mNext = p_mpDriver->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpDriver->mPrev = p_mpDriver;
        p_mpDriver->mNext = p_mpDriver;
      }
      p_mpDriver->m_pPointer = 0i64;
      mpReservations = this->mpReservations;
      if ( this->mpReservations[0].m_pPointer )
      {
        v9 = mpReservations->mPrev;
        v10 = this->mpReservations[0].mNext;
        v9->mNext = v10;
        v10->mPrev = v9;
        mpReservations->mPrev = mpReservations;
        this->mpReservations[0].mNext = this->mpReservations;
      }
      this->mpReservations[0].m_pPointer = 0i64;
    }
    else
    {
      v11 = this->mPassengers.mNode.mNext;
      p_m_BoundComponentHandles = &this->m_BoundComponentHandles;
      v13 = -1;
      v14 = (UFG::CharacterOccupantComponent *)&v11[-4];
      if ( v14 != (UFG::CharacterOccupantComponent *)p_m_BoundComponentHandles )
      {
        while ( 1 )
        {
          ++v13;
          if ( v14 == pOccupant )
            break;
          v14 = (UFG::CharacterOccupantComponent *)&v14->mNext[-4];
          if ( v14 == (UFG::CharacterOccupantComponent *)p_m_BoundComponentHandles )
            goto LABEL_18;
        }
        if ( v13 != -1 )
        {
          pTargetType = eTARGET_TYPE_INVALID;
          if ( m_pPointer )
            ++v13;
          UFG::VehicleOccupantComponent::GetOccupant(this, v13, &pTargetType);
          v15 = pTargetType - 4 + 2 * (pTargetType - 4 + 8i64);
          v16 = *((_QWORD *)&this->m_SafePointerList.mNode.mNext + v15) == 0i64;
          v17 = &(&this->vfptr)[v15];
          if ( !v16 )
          {
            v18 = *v17;
            v19 = v17[1];
            v18[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v19;
            v19->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v18;
            *v17 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v17;
            v17[1] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v17;
          }
          v17[2] = 0i64;
          v20 = pOccupant->mPrev;
          v21 = pOccupant->mNext;
          v20->mNext = v21;
          v21->mPrev = v20;
          pOccupant->mPrev = &pOccupant->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
          pOccupant->mNext = &pOccupant->UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList>;
        }
      }
    }
LABEL_18:
    UFG::CharacterOccupantComponent::SetVehicleOccupantComponent(pOccupant, 0i64, 0);
    m_pSimObject = (UFG::SimObjectGame *)pOccupant->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[10].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[7].m_pComponent;
        }
        else
        {
          v25 = (m_Flags & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::StreamedResourceComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::StreamedResourceComponent::_TypeUID);
          m_pComponent = (UFG::StreamedResourceComponent *)v25;
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[10].m_pComponent;
      }
      if ( m_pComponent )
      {
        v26 = (UFG::SimObjectGame *)this->m_pSimObject;
        if ( v26 )
        {
          v27 = v26->m_Flags;
          if ( (v27 & 0x4000) != 0 )
          {
            v28 = (UFG::StreamedResourceComponent *)v26->m_Components.p[10].m_pComponent;
          }
          else if ( v27 >= 0 )
          {
            if ( (v27 & 0x2000) != 0 )
            {
              v28 = (UFG::StreamedResourceComponent *)v26->m_Components.p[7].m_pComponent;
            }
            else
            {
              v29 = (v27 & 0x1000) != 0
                  ? UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::StreamedResourceComponent::_TypeUID)
                  : UFG::SimObject::GetComponentOfType(v26, UFG::StreamedResourceComponent::_TypeUID);
              v28 = (UFG::StreamedResourceComponent *)v29;
            }
          }
          else
          {
            v28 = (UFG::StreamedResourceComponent *)v26->m_Components.p[10].m_pComponent;
          }
          if ( v28 )
          {
            SpawnPriority = UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64);
            UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v28, SpawnPriority);
          }
        }
      }
    }
    v31 = (UFG::SimObjectCharacter *)pOccupant->m_pSimObject;
    if ( v31 )
    {
      v32 = v31->m_Flags;
      if ( (v32 & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v31);
      }
      else if ( v32 < 0 || (v32 & 0x2000) != 0 || (v32 & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v31,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                          v31,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        *((_BYTE *)ComponentOfTypeHK + 553) &= ~4u;
    }
  }
} }
      if ( ComponentOfTypeHK )
        *((_BYTE *)ComponentOfTypeHK + 553) &= ~4u;
    }
  }
}

// File Line: 280
// RVA: 0x676600
void __fastcall UFG::VehicleOccupantComponent::DeleteAllOccupants(UFG::VehicleOccupantComponent *this)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::SimObjectCharacter *v3; // r14
  UFG::CharacterOccupantComponent *v4; // rdx
  UFG::SimObject *m_pSimObject; // rdi
  UFG::VehicleOccupantComponent *v6; // rbx

  m_pPointer = this->mpDriver.m_pPointer;
  if ( m_pPointer )
  {
    UFG::VehicleOccupantComponent::RemoveOccupant(
      this,
      (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent);
    UFG::PedSpawnManager::GetInstance();
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
  }
  v3 = LocalPlayer;
  v4 = (UFG::CharacterOccupantComponent *)&this->mPassengers.mNode.mNext[-4];
  if ( v4 != (UFG::CharacterOccupantComponent *)&this->m_BoundComponentHandles )
  {
    do
    {
      m_pSimObject = v4->m_pSimObject;
      v6 = (UFG::VehicleOccupantComponent *)&v4->mNext[-4];
      if ( m_pSimObject != v3 )
      {
        UFG::VehicleOccupantComponent::RemoveOccupant(this, v4);
        UFG::PedSpawnManager::GetInstance();
        UFG::Simulation::DestroySimObject(&UFG::gSim, m_pSimObject);
      }
      v4 = (UFG::CharacterOccupantComponent *)v6;
    }
    while ( v6 != (UFG::VehicleOccupantComponent *)&this->m_BoundComponentHandles );
  }
}

// File Line: 310
// RVA: 0x698600
void __fastcall UFG::VehicleOccupantComponent::UpdateOccupantPriority(
        UFG::VehicleOccupantComponent *this,
        UFG::qSymbol *oldPriority,
        UFG::qSymbol *newPriority)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::StreamedResourceComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[10].m_pComponent;
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[7].m_pComponent;
    }
    else
    {
      if ( (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pSimObject,
                              UFG::StreamedResourceComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::StreamedResourceComponent::_TypeUID);
      m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(m_pComponent, oldPriority);
  UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(m_pComponent, newPriority);
}

// File Line: 319
// RVA: 0x67ADA0
__int64 __fastcall UFG::VehicleOccupantComponent::GetNumberOfOccupants(UFG::VehicleOccupantComponent *this)
{
  unsigned int v1; // edx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // r8
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *i; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *j; // rcx

  v1 = 0;
  p_m_BoundComponentHandles = &this->m_BoundComponentHandles;
  if ( this->mpDriver.m_pPointer )
  {
    for ( i = this->mPassengers.mNode.mNext - 4;
          i != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)p_m_BoundComponentHandles;
          i = i[4].mNext - 4 )
    {
      ++v1;
    }
    return v1 + 1;
  }
  else
  {
    for ( j = this->mPassengers.mNode.mNext - 4;
          j != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)p_m_BoundComponentHandles;
          j = j[4].mNext - 4 )
    {
      ++v1;
    }
    return v1;
  }
}

// File Line: 329
// RVA: 0x67AE00
__int64 __fastcall UFG::VehicleOccupantComponent::GetNumberOfPassengers(UFG::VehicleOccupantComponent *this)
{
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *mNext; // rdx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rcx
  __int64 result; // rax
  __int64 i; // rdx

  mNext = this->mPassengers.mNode.mNext;
  p_m_BoundComponentHandles = &this->m_BoundComponentHandles;
  result = 0i64;
  for ( i = (__int64)&mNext[-4];
        (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)i != p_m_BoundComponentHandles;
        i = *(_QWORD *)(i + 0x48) - 0x40i64 )
  {
    result = (unsigned int)(result + 1);
  }
  return result;
}

// File Line: 336
// RVA: 0x67AE40
__int64 __fastcall UFG::VehicleOccupantComponent::GetNumberOfSeats(UFG::VehicleOccupantComponent *this)
{
  return this->mSeatCount;
}

// File Line: 343
// RVA: 0x67AE50
UFG::SimObject *__fastcall UFG::VehicleOccupantComponent::GetOccupant(
        UFG::VehicleOccupantComponent *this,
        int index,
        UFG::eTargetTypeEnum *pTargetType)
{
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v5; // r9
  int v6; // edx
  UFG::CharacterOccupantComponent *v7; // rax
  int v8; // r8d
  UFG::CharacterOccupantComponent *j; // rcx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // r9
  signed int v11; // r8d
  UFG::CharacterOccupantComponent *i; // rcx

  if ( !this->mpDriver.m_pPointer )
  {
    p_m_BoundComponentHandles = &this->m_BoundComponentHandles;
    v11 = 0;
    v7 = (UFG::CharacterOccupantComponent *)&this->mPassengers.mNode.mNext[-4];
    for ( i = v7;
          i != (UFG::CharacterOccupantComponent *)p_m_BoundComponentHandles;
          i = (UFG::CharacterOccupantComponent *)&i->mNext[-4] )
    {
      ++v11;
    }
    if ( index < v11 )
    {
      for ( ; index > 0; v7 = (UFG::CharacterOccupantComponent *)&v7->mNext[-4] )
      {
        if ( v7 == (UFG::CharacterOccupantComponent *)p_m_BoundComponentHandles )
          break;
        --index;
      }
      goto LABEL_12;
    }
    return 0i64;
  }
  if ( !index )
  {
    if ( pTargetType )
      *pTargetType = eTARGET_TYPE_VEHICLE_DRIVER;
    return this->mpDriver.m_pPointer;
  }
  v5 = &this->m_BoundComponentHandles;
  v6 = index - 1;
  v7 = (UFG::CharacterOccupantComponent *)&this->mPassengers.mNode.mNext[-4];
  v8 = 0;
  for ( j = v7; j != (UFG::CharacterOccupantComponent *)v5; j = (UFG::CharacterOccupantComponent *)&j->mNext[-4] )
    ++v8;
  if ( v6 >= v8 )
    return 0i64;
  for ( ; v6 > 0; v7 = (UFG::CharacterOccupantComponent *)&v7->mNext[-4] )
  {
    if ( v7 == (UFG::CharacterOccupantComponent *)v5 )
      break;
    --v6;
  }
LABEL_12:
  if ( pTargetType )
    *pTargetType = v7->mTargetType;
  return v7->m_pSimObject;
}

// File Line: 392
// RVA: 0x67AF40
UFG::SimObject *__fastcall UFG::VehicleOccupantComponent::GetPassenger(
        UFG::VehicleOccupantComponent *this,
        int iIndex,
        bool excludeEnteringAndExiting)
{
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *mNext; // rbx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rcx
  int v5; // r9d
  UFG::CharacterOccupantComponent *v6; // rbx
  __int64 i; // rax

  mNext = this->mPassengers.mNode.mNext;
  p_m_BoundComponentHandles = &this->m_BoundComponentHandles;
  v5 = 0;
  v6 = (UFG::CharacterOccupantComponent *)&mNext[-4];
  for ( i = (__int64)v6;
        (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)i != p_m_BoundComponentHandles;
        i = *(_QWORD *)(i + 0x48) - 0x40i64 )
  {
    ++v5;
  }
  if ( iIndex >= v5 )
    return 0i64;
  for ( ; iIndex > 0; v6 = (UFG::CharacterOccupantComponent *)&v6->mNext[-4] )
  {
    if ( v6 == (UFG::CharacterOccupantComponent *)p_m_BoundComponentHandles )
      break;
    --iIndex;
  }
  if ( excludeEnteringAndExiting && UFG::CharacterOccupantComponent::IsEnteringOrExiting(v6) )
    return 0i64;
  else
    return v6->m_pSimObject;
}

// File Line: 411
// RVA: 0x68ACB0
void __fastcall UFG::VehicleOccupantComponent::SetParkingSpot(
        UFG::RoadNetworkGuide *this,
        UFG::RoadNetworkLane *roadLane)
{
  this->m_NextLane = roadLane;
}

// File Line: 418
// RVA: 0x67F350
_BOOL8 __fastcall UFG::VehicleOccupantComponent::IsParked(UFG::VehicleOccupantComponent *this)
{
  return this->mpParkingSpot != 0i64;
}

// File Line: 425
// RVA: 0x67B190
UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *__fastcall UFG::VehicleOccupantComponent::GetReservationList(
        UFG::VehicleOccupantComponent *this)
{
  return this->mpReservations;
}

