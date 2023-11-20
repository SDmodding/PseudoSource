// File Line: 27
// RVA: 0x157B8F0
__int64 dynamic_initializer_for__UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList__);
}

// File Line: 28
// RVA: 0x67B530
signed __int64 __fastcall UFG::HasAttackRequestComponent::GetTypeSize(UFG::qReflectInventory<UFG::DUIPopupMenuWindow> *this)
{
  return 376i64;
}

// File Line: 44
// RVA: 0x66B610
void __fastcall UFG::VehicleOccupantComponent::VehicleOccupantComponent(UFG::VehicleOccupantComponent *this, UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v2; // rbp
  UFG::VehicleOccupantComponent *v3; // rdi
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v4; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rsi
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v6; // rax
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
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v30; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v33; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v36; // [rsp+68h] [rbp+10h]
  UFG::qList<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList,0,0> *v37; // [rsp+68h] [rbp+10h]

  v2 = sceneObject;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, sceneObject->m_NameUID);
  v4 = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleOccupantComponent::`vftable';
  v3->mpParkingSpot = 0i64;
  v36 = &v3->mpDriver;
  v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v36->mPrev;
  v36->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v36->mPrev;
  v3->mpDriver.m_pPointer = 0i64;
  v37 = &v3->mPassengers;
  v37->mNode.mPrev = &v37->mNode;
  v37->mNode.mNext = &v37->mNode;
  v5 = v3->mpReservations;
  `eh vector constructor iterator'(
    v3->mpReservations,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v3->mSeatCount = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::VehicleOccupantComponent::_VehicleOccupantComponentTypeUID,
    "VehicleOccupantComponent");
  v6 = UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mPrev;
  UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)&v3->mPrev;
  v4->mPrev = v6;
  v3->mNext = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList;
  UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mPrev = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)&v3->mPrev;
  if ( v3->mpReservations[0].m_pPointer )
  {
    v7 = v5->mPrev;
    v8 = v3->mpReservations[0].mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v3->mpReservations[0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v3->mpReservations;
  }
  v3->mpReservations[0].m_pPointer = 0i64;
  v9 = &v3->mpReservations[1];
  if ( v3->mpReservations[1].m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v3->mpReservations[1].mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v3->mpReservations[1].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[1].mPrev;
  }
  v3->mpReservations[1].m_pPointer = 0i64;
  v12 = &v3->mpReservations[2];
  if ( v3->mpReservations[2].m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v3->mpReservations[2].mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v3->mpReservations[2].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[2].mPrev;
  }
  v3->mpReservations[2].m_pPointer = 0i64;
  v15 = &v3->mpReservations[3];
  if ( v3->mpReservations[3].m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v3->mpReservations[3].mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v3->mpReservations[3].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[3].mPrev;
  }
  v3->mpReservations[3].m_pPointer = 0i64;
  v18 = &v3->mpReservations[4];
  if ( v3->mpReservations[4].m_pPointer )
  {
    v19 = v18->mPrev;
    v20 = v3->mpReservations[4].mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v3->mpReservations[4].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[4].mPrev;
  }
  v3->mpReservations[4].m_pPointer = 0i64;
  v21 = &v3->mpReservations[5];
  if ( v3->mpReservations[5].m_pPointer )
  {
    v22 = v21->mPrev;
    v23 = v3->mpReservations[5].mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    v21->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->mPrev;
    v3->mpReservations[5].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[5].mPrev;
  }
  v3->mpReservations[5].m_pPointer = 0i64;
  v24 = &v3->mpReservations[6];
  if ( v3->mpReservations[6].m_pPointer )
  {
    v25 = v24->mPrev;
    v26 = v3->mpReservations[6].mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v3->mpReservations[6].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[6].mPrev;
  }
  v3->mpReservations[6].m_pPointer = 0i64;
  v27 = &v3->mpReservations[7];
  if ( v3->mpReservations[7].m_pPointer )
  {
    v28 = v27->mPrev;
    v29 = v3->mpReservations[7].mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    v3->mpReservations[7].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[7].mPrev;
  }
  v3->mpReservations[7].m_pPointer = 0i64;
  v30 = &v3->mpReservations[8];
  if ( v3->mpReservations[8].m_pPointer )
  {
    v31 = v30->mPrev;
    v32 = v3->mpReservations[8].mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    v30->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v30->mPrev;
    v3->mpReservations[8].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[8].mPrev;
  }
  v3->mpReservations[8].m_pPointer = 0i64;
  v33 = &v3->mpReservations[9];
  if ( v3->mpReservations[9].m_pPointer )
  {
    v34 = v33->mPrev;
    v35 = v3->mpReservations[9].mNext;
    v34->mNext = v35;
    v35->mPrev = v34;
    v33->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v33->mPrev;
    v3->mpReservations[9].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpReservations[9].mPrev;
  }
  v3->mpReservations[9].m_pPointer = 0i64;
  v3->mSeatCount = PropertyUtils::Get<unsigned long>(v2, (UFG::qSymbol *)&qSymbol_SeatCount.mUID)->mFlags;
}

// File Line: 60
// RVA: 0x66D600
void __fastcall UFG::VehicleOccupantComponent::~VehicleOccupantComponent(UFG::VehicleOccupantComponent *this)
{
  UFG::VehicleOccupantComponent *v1; // rbx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v2; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v3; // r8
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v4; // rdx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v5; // rcx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v6; // rax
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v7; // rdi
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v8; // rdx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v15; // rcx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v16; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleOccupantComponent::`vftable';
  v2 = this->mPassengers.mNode.mNext - 4;
  v3 = &this->m_BoundComponentHandles;
  if ( v2 != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)&this->m_BoundComponentHandles )
  {
    do
    {
      v4 = v2 + 4;
      v5 = v2[4].mPrev;
      v6 = v2[4].mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = v4;
      v4->mNext = v4;
      v2 = v1->mPassengers.mNode.mNext - 4;
    }
    while ( v2 != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)v3 );
  }
  if ( v1 == UFG::VehicleOccupantComponent::s_VehicleOccupantComponentpCurrentIterator )
    UFG::VehicleOccupantComponent::s_VehicleOccupantComponentpCurrentIterator = (UFG::VehicleOccupantComponent *)&v1->mPrev[-4];
  v7 = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  `eh vector destructor iterator'(
    v1->mpReservations,
    0x18ui64,
    10,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  UFG::qList<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList,0,0>::~qList<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList,0,0>((UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *)&v1->mPassengers);
  v10 = &v1->mpDriver;
  if ( v1->mpDriver.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->mpDriver.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->mpDriver.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpDriver.mPrev;
  }
  v1->mpDriver.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->mpDriver.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->mpDriver.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpDriver.mPrev;
  v15 = v7->mPrev;
  v16 = v1->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v7->mPrev = v7;
  v1->mNext = (UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 74
// RVA: 0x67D0B0
bool __fastcall UFG::VehicleOccupantComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qSymbol *)&SimSymX_propset_componentVehicleOccupant.mUID);
}

// File Line: 80
// RVA: 0x687C00
UFG::VehicleOccupantComponent *__fastcall UFG::VehicleOccupantComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::VehicleOccupantComponent *v4; // rax
  UFG::VehicleOccupantComponent *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned __int16 v7; // cx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v1 = sceneObject;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x178ui64, "VehicleOccupantComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::VehicleOccupantComponent::VehicleOccupantComponent((UFG::VehicleOccupantComponent *)v3, v1);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1->m_pSimObject;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 || (v7 & 0x8000u) == 0 )
    v8 = -1;
  else
    v8 = 30;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, (UFG::SimComponent *)&v5->vfptr, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  UFG::VehicleOccupantComponent::SetupPassengerData(v5, v1);
  return v5;
}

// File Line: 92
// RVA: 0x683980
void __fastcall UFG::VehicleOccupantComponent::OnAttach(UFG::VehicleOccupantComponent *this, UFG::SimObject *object)
{
  UFG::VehicleOccupantComponent *v2; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
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

  v2 = this;
  v3 = this->mpReservations;
  if ( v3->m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v6 = &v2->mpReservations[1];
  v3->m_pPointer = 0i64;
  if ( v2->mpReservations[1].m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v2->mpReservations[1].mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v2->mpReservations[1].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpReservations[1].mPrev;
  }
  v2->mpReservations[1].m_pPointer = 0i64;
  v9 = &v2->mpReservations[2];
  if ( v2->mpReservations[2].m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v2->mpReservations[2].mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v2->mpReservations[2].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpReservations[2].mPrev;
  }
  v2->mpReservations[2].m_pPointer = 0i64;
  v12 = &v2->mpReservations[3];
  if ( v2->mpReservations[3].m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v2->mpReservations[3].mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v2->mpReservations[3].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpReservations[3].mPrev;
  }
  v2->mpReservations[3].m_pPointer = 0i64;
  v15 = &v2->mpReservations[4];
  if ( v2->mpReservations[4].m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v2->mpReservations[4].mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v2->mpReservations[4].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpReservations[4].mPrev;
  }
  v2->mpReservations[4].m_pPointer = 0i64;
  v18 = &v2->mpReservations[5];
  if ( v2->mpReservations[5].m_pPointer )
  {
    v19 = v18->mPrev;
    v20 = v2->mpReservations[5].mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v2->mpReservations[5].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpReservations[5].mPrev;
  }
  v2->mpReservations[5].m_pPointer = 0i64;
  v21 = &v2->mpReservations[6];
  if ( v2->mpReservations[6].m_pPointer )
  {
    v22 = v21->mPrev;
    v23 = v2->mpReservations[6].mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    v21->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->mPrev;
    v2->mpReservations[6].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpReservations[6].mPrev;
  }
  v2->mpReservations[6].m_pPointer = 0i64;
  v24 = &v2->mpReservations[7];
  if ( v2->mpReservations[7].m_pPointer )
  {
    v25 = v24->mPrev;
    v26 = v2->mpReservations[7].mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v2->mpReservations[7].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpReservations[7].mPrev;
  }
  v2->mpReservations[7].m_pPointer = 0i64;
  v27 = &v2->mpReservations[8];
  if ( v2->mpReservations[8].m_pPointer )
  {
    v28 = v27->mPrev;
    v29 = v2->mpReservations[8].mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    v2->mpReservations[8].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpReservations[8].mPrev;
  }
  v30 = &v2->mpReservations[9];
  v27->m_pPointer = 0i64;
  if ( v30->m_pPointer )
  {
    v31 = v30->mPrev;
    v32 = v30->mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    v30->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v30->mPrev;
    v30->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v30->mPrev;
  }
  v30->m_pPointer = 0i64;
}

// File Line: 103
// RVA: 0x68BA50
void __fastcall UFG::VehicleOccupantComponent::SetupPassengerData(UFG::VehicleOccupantComponent *this, UFG::SceneObjectProperties *pSOP)
{
  UFG::VehicleOccupantComponent *v2; // rdi
  UFG::qPropertySet *v3; // rcx
  UFG::SceneObjectProperties *v4; // rbx
  int v5; // eax

  v2 = this;
  v3 = pSOP->mpWritableProperties;
  v4 = pSOP;
  if ( !v3 )
    v3 = pSOP->mpConstProperties;
  if ( UFG::SimObjectUtility::IsClassType(v3, (UFG::qSymbol *)&qSymbol_Taxi.mUID) == 1
    && !(unsigned int)UFG::qRandom(100, &UFG::qDefaultSeed) )
  {
    v5 = UFG::qRandom(v2->mSeatCount - 2, &UFG::qDefaultSeed);
    PropertyUtils::SetRuntime<unsigned long>(v4, (UFG::qSymbol *)&qSymbol_AmbientPassengerCount.mUID, v5 + 1);
  }
}

// File Line: 129
// RVA: 0x67D1E0
char __fastcall UFG::VehicleOccupantComponent::HasPassengers(UFG::VehicleOccupantComponent *this)
{
  UFG::VehicleOccupantComponent *v1; // r9
  UFG::SceneObjectProperties *v2; // rcx
  int v3; // edx
  signed __int64 v4; // rax
  UFG::SimObject *v6; // rax
  UFG::qPropertySet *v7; // rax
  char v8; // cl

  v1 = this;
  v2 = 0i64;
  v3 = 0;
  v4 = (signed __int64)&v1->mPassengers.mNode.mNext[-4];
  if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v4 != &v1->m_BoundComponentHandles )
  {
    do
    {
      ++v3;
      v4 = *(_QWORD *)(v4 + 72) - 64i64;
    }
    while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v4 != &v1->m_BoundComponentHandles );
    if ( v3 )
      return 1;
  }
  v6 = v1->m_pSimObject;
  if ( v6 )
    v2 = v6->m_pSceneObj;
  v7 = PropertyUtils::Get<unsigned long>(v2, (UFG::qSymbol *)&qSymbol_AmbientPassengerCount.mUID);
  v8 = 0;
  if ( (unsigned __int64)v7 >= 1 )
    v8 = 1;
  return v8;
}

// File Line: 151
// RVA: 0x68D0D0
void __fastcall UFG::VehicleOccupantComponent::TeleportEventHandler(UFG::VehicleOccupantComponent *this, UFG::Event *event)
{
  UFG::Event *v2; // rbp
  UFG::VehicleOccupantComponent *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  signed __int64 v5; // rbx
  signed __int64 i; // rsi
  __int64 v7; // rdi
  UFG::allocator::free_link *v8; // rax

  v2 = event;
  v3 = this;
  if ( this->mpDriver.m_pPointer )
  {
    v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    if ( v4 )
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v4,
        (UFG::qMatrix44 *)&v2[1].m_EventUID,
        v3->mpDriver.m_pPointer->mNode.mUID,
        0,
        UFG::TeleportEvent::m_Name,
        0);
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  }
  if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)&v3->mPassengers.mNode.mNext[-4] != &v3->m_BoundComponentHandles )
  {
    v5 = (signed __int64)&v3->mPassengers.mNode.mNext[-4];
    for ( i = (signed __int64)&v3->m_BoundComponentHandles; v5 != i; v5 = *(_QWORD *)(v5 + 72) - 64i64 )
    {
      v7 = *(_QWORD *)(v5 + 40);
      v8 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      if ( v8 )
        UFG::TeleportEvent::TeleportEvent(
          (UFG::TeleportEvent *)v8,
          (UFG::qMatrix44 *)&v2[1].m_EventUID,
          *(_DWORD *)(v7 + 64),
          0,
          UFG::TeleportEvent::m_Name,
          0);
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v8);
    }
  }
}

// File Line: 177
// RVA: 0x66FAE0
void __fastcall UFG::VehicleOccupantComponent::AddOccupant(UFG::VehicleOccupantComponent *this, UFG::CharacterOccupantComponent *pOccupant, bool bDriver)
{
  unsigned int v3; // er9
  UFG::CharacterOccupantComponent *v4; // rbx
  UFG::VehicleOccupantComponent *v5; // rbp
  UFG::SimObject *v6; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObject *v11; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v16; // rax
  UFG::qList<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList,0,0> *v17; // rsi
  signed int v18; // ecx
  UFG::CharacterOccupantComponent *v19; // rdi
  UFG::CharacterOccupantComponent *v20; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v21; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v22; // rcx
  unsigned int v23; // edx
  signed __int64 v24; // rax
  UFG::SimObject *v25; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v26; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rax
  signed int v31; // ecx
  UFG::CharacterOccupantComponent *v32; // rax
  UFG::SimObjectGame *v33; // rcx
  unsigned __int16 v34; // dx
  UFG::StreamedResourceComponent *v35; // rsi
  UFG::SimComponent *v36; // rax
  UFG::SimObjectGame *v37; // rcx
  unsigned __int16 v38; // dx
  UFG::StreamedResourceComponent *v39; // rdi
  UFG::SimComponent *v40; // rax
  UFG::qSymbol *v41; // rax
  UFG::SimObjectCharacter *v42; // rcx
  unsigned __int16 v43; // dx
  UFG::ActorAudioComponent *v44; // rax
  UFG::eTargetTypeEnum pTargetType; // [rsp+38h] [rbp+10h]

  if ( pOccupant )
  {
    v3 = 0;
    v4 = pOccupant;
    v5 = this;
    if ( bDriver )
    {
      v6 = pOccupant->m_pSimObject;
      v7 = &this->mpDriver;
      if ( this->mpDriver.m_pPointer )
      {
        v8 = v7->mPrev;
        v9 = v7->mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
        v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      }
      v7->m_pPointer = v6;
      if ( v6 )
      {
        v10 = v6->m_SafePointerList.mNode.mPrev;
        v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
        v7->mPrev = v10;
        v7->mNext = &v6->m_SafePointerList.mNode;
        v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      }
      v11 = v5->mpDriver.m_pPointer;
      v12 = v5->mpReservations;
      v5->mpParkingSpot = 0i64;
      if ( v5->mpReservations[0].m_pPointer )
      {
        v13 = v12->mPrev;
        v14 = v5->mpReservations[0].mNext;
        v13->mNext = v14;
        v14->mPrev = v13;
        v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
        v5->mpReservations[0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v5->mpReservations;
      }
      v5->mpReservations[0].m_pPointer = v11;
      if ( v11 )
      {
        v15 = v11->m_SafePointerList.mNode.mPrev;
        v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
        v12->mPrev = v15;
        v5->mpReservations[0].mNext = &v11->m_SafePointerList.mNode;
        v11->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      }
    }
    else
    {
      v16 = this->mPassengers.mNode.mNext;
      v17 = &this->mPassengers;
      v18 = -1;
      v19 = (UFG::CharacterOccupantComponent *)&v17[-4];
      v20 = (UFG::CharacterOccupantComponent *)&v16[-4];
      if ( v20 == (UFG::CharacterOccupantComponent *)&v17[-4] )
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
        v21 = v17->mNode.mPrev;
        v22 = (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)&pOccupant->mPrev;
        v21->mNext = (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)&pOccupant->mPrev;
        v22->mPrev = v21;
        v22->mNext = &v17->mNode;
        v17->mNode.mPrev = (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)&pOccupant->mPrev;
      }
      v23 = -1;
      v24 = (signed __int64)&v17->mNode.mNext[-4];
      if ( (UFG::CharacterOccupantComponent *)v24 == v19 )
      {
LABEL_20:
        v23 = -1;
      }
      else
      {
        while ( 1 )
        {
          ++v23;
          if ( (UFG::CharacterOccupantComponent *)v24 == v4 )
            break;
          v24 = *(_QWORD *)(v24 + 72) - 64i64;
          if ( (UFG::CharacterOccupantComponent *)v24 == v19 )
            goto LABEL_20;
        }
      }
      pTargetType = 0;
      if ( v5->mpDriver.m_pPointer )
        ++v23;
      v25 = UFG::VehicleOccupantComponent::GetOccupant(v5, v23, &pTargetType);
      v26 = &v5->mpReservations[pTargetType - 4];
      if ( v26->m_pPointer )
      {
        v27 = v26->mPrev;
        v28 = v26->mNext;
        v27->mNext = v28;
        v28->mPrev = v27;
        v26->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
        v26->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
      }
      v26->m_pPointer = v25;
      if ( v25 )
      {
        v29 = &v25->m_SafePointerList;
        v30 = v25->m_SafePointerList.mNode.mPrev;
        v30->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
        v26->mPrev = v30;
        v26->mNext = &v29->mNode;
        v29->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
      }
      v31 = -1;
      v32 = (UFG::CharacterOccupantComponent *)&v17->mNode.mNext[-4];
      if ( v32 == v19 )
      {
LABEL_30:
        v31 = -1;
      }
      else
      {
        while ( 1 )
        {
          ++v31;
          if ( v32 == v4 )
            break;
          v32 = (UFG::CharacterOccupantComponent *)&v32->mNext[-4];
          if ( v32 == v19 )
            goto LABEL_30;
        }
      }
      v3 = v31 + 1;
    }
    UFG::CharacterOccupantComponent::SetVehicleOccupantComponent(v4, v5, v3);
    v33 = (UFG::SimObjectGame *)v4->m_pSimObject;
    if ( v33 )
    {
      v34 = v33->m_Flags;
      if ( (v34 >> 14) & 1 )
      {
        v35 = (UFG::StreamedResourceComponent *)v33->m_Components.p[10].m_pComponent;
      }
      else if ( (v34 & 0x8000u) == 0 )
      {
        if ( (v34 >> 13) & 1 )
        {
          v35 = (UFG::StreamedResourceComponent *)v33->m_Components.p[7].m_pComponent;
        }
        else
        {
          v36 = (v34 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v33,
                                    UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                  (UFG::SimObject *)&v33->vfptr,
                                                                                  UFG::StreamedResourceComponent::_TypeUID);
          v35 = (UFG::StreamedResourceComponent *)v36;
        }
      }
      else
      {
        v35 = (UFG::StreamedResourceComponent *)v33->m_Components.p[10].m_pComponent;
      }
      if ( v35 )
      {
        v37 = (UFG::SimObjectGame *)v5->m_pSimObject;
        if ( v37 )
        {
          v38 = v37->m_Flags;
          if ( (v38 >> 14) & 1 )
          {
            v39 = (UFG::StreamedResourceComponent *)v37->m_Components.p[10].m_pComponent;
          }
          else if ( (v38 & 0x8000u) == 0 )
          {
            if ( (v38 >> 13) & 1 )
            {
              v39 = (UFG::StreamedResourceComponent *)v37->m_Components.p[7].m_pComponent;
            }
            else
            {
              v40 = (v38 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v37,
                                        UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                      (UFG::SimObject *)&v37->vfptr,
                                                                                      UFG::StreamedResourceComponent::_TypeUID);
              v39 = (UFG::StreamedResourceComponent *)v40;
            }
          }
          else
          {
            v39 = (UFG::StreamedResourceComponent *)v37->m_Components.p[10].m_pComponent;
          }
          if ( v39 )
          {
            v41 = UFG::StreamedResourceComponent::GetSpawnPriority(v35, 0i64);
            UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v39, v41);
          }
        }
      }
    }
    v42 = (UFG::SimObjectCharacter *)v4->m_pSimObject;
    if ( v42 )
    {
      v43 = v42->m_Flags;
      if ( (v43 >> 14) & 1 )
      {
        v44 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v42);
      }
      else if ( (v43 & 0x8000u) == 0 )
      {
        if ( (v43 >> 13) & 1 )
        {
          v44 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v42->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
        else if ( (v43 >> 12) & 1 )
        {
          v44 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v42->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          v44 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v42->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v44 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v42->vfptr,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      if ( v44 )
        *((_BYTE *)v44 + 553) |= 4u;
    }
  }
}

// File Line: 234
// RVA: 0x689710
void __fastcall UFG::VehicleOccupantComponent::RemoveOccupant(UFG::VehicleOccupantComponent *this, UFG::CharacterOccupantComponent *pOccupant)
{
  UFG::SimObject *v2; // r8
  UFG::CharacterOccupantComponent *v3; // rbx
  UFG::VehicleOccupantComponent *v4; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v11; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v12; // rcx
  unsigned int v13; // edx
  signed __int64 v14; // rax
  signed __int64 v15; // rdx
  bool v16; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v17; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v18; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v19; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v20; // rcx
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v21; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v22; // rdx
  UFG::SimObjectGame *v23; // rcx
  unsigned __int16 v24; // dx
  UFG::StreamedResourceComponent *v25; // rsi
  UFG::SimComponent *v26; // rax
  UFG::SimObjectGame *v27; // rcx
  unsigned __int16 v28; // dx
  UFG::StreamedResourceComponent *v29; // rdi
  UFG::SimComponent *v30; // rax
  UFG::qSymbol *v31; // rax
  UFG::SimObjectCharacter *v32; // rcx
  unsigned __int16 v33; // dx
  UFG::ActorAudioComponent *v34; // rax
  UFG::eTargetTypeEnum pTargetType; // [rsp+38h] [rbp+10h]

  if ( pOccupant )
  {
    v2 = this->mpDriver.m_pPointer;
    v3 = pOccupant;
    v4 = this;
    if ( pOccupant->m_pSimObject == v2 )
    {
      v5 = &this->mpDriver;
      if ( this->mpDriver.m_pPointer )
      {
        v6 = v5->mPrev;
        v7 = v5->mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
        v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
        v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      }
      v5->m_pPointer = 0i64;
      v8 = v4->mpReservations;
      if ( v4->mpReservations[0].m_pPointer )
      {
        v9 = v8->mPrev;
        v10 = v4->mpReservations[0].mNext;
        v9->mNext = v10;
        v10->mPrev = v9;
        v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
        v4->mpReservations[0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v4->mpReservations;
      }
      v4->mpReservations[0].m_pPointer = 0i64;
    }
    else
    {
      v11 = this->mPassengers.mNode.mNext;
      v12 = &this->m_BoundComponentHandles;
      v13 = -1;
      v14 = (signed __int64)&v11[-4];
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v14 != v12 )
      {
        while ( 1 )
        {
          ++v13;
          if ( (UFG::CharacterOccupantComponent *)v14 == v3 )
            break;
          v14 = *(_QWORD *)(v14 + 72) - 64i64;
          if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v14 == v12 )
            goto LABEL_18;
        }
        if ( v13 != -1 )
        {
          pTargetType = 0;
          if ( v2 )
            ++v13;
          UFG::VehicleOccupantComponent::GetOccupant(v4, v13, &pTargetType);
          v15 = pTargetType - 4 + 2 * (pTargetType - 4 + 8i64);
          v16 = *((_QWORD *)&v4->m_SafePointerList.mNode.mNext + v15) == 0i64;
          v17 = &(&v4->vfptr)[v15];
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
          v20 = v3->mPrev;
          v21 = v3->mNext;
          v22 = (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)&v3->mPrev;
          v20->mNext = v21;
          v21->mPrev = v20;
          v22->mPrev = v22;
          v22->mNext = v22;
        }
      }
    }
LABEL_18:
    UFG::CharacterOccupantComponent::SetVehicleOccupantComponent(v3, 0i64, 0);
    v23 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v23 )
    {
      v24 = v23->m_Flags;
      if ( (v24 >> 14) & 1 )
      {
        v25 = (UFG::StreamedResourceComponent *)v23->m_Components.p[10].m_pComponent;
      }
      else if ( (v24 & 0x8000u) == 0 )
      {
        if ( (v24 >> 13) & 1 )
        {
          v25 = (UFG::StreamedResourceComponent *)v23->m_Components.p[7].m_pComponent;
        }
        else
        {
          v26 = (v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v23,
                                    UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                  (UFG::SimObject *)&v23->vfptr,
                                                                                  UFG::StreamedResourceComponent::_TypeUID);
          v25 = (UFG::StreamedResourceComponent *)v26;
        }
      }
      else
      {
        v25 = (UFG::StreamedResourceComponent *)v23->m_Components.p[10].m_pComponent;
      }
      if ( v25 )
      {
        v27 = (UFG::SimObjectGame *)v4->m_pSimObject;
        if ( v27 )
        {
          v28 = v27->m_Flags;
          if ( (v28 >> 14) & 1 )
          {
            v29 = (UFG::StreamedResourceComponent *)v27->m_Components.p[10].m_pComponent;
          }
          else if ( (v28 & 0x8000u) == 0 )
          {
            if ( (v28 >> 13) & 1 )
            {
              v29 = (UFG::StreamedResourceComponent *)v27->m_Components.p[7].m_pComponent;
            }
            else
            {
              v30 = (v28 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v27,
                                        UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                      (UFG::SimObject *)&v27->vfptr,
                                                                                      UFG::StreamedResourceComponent::_TypeUID);
              v29 = (UFG::StreamedResourceComponent *)v30;
            }
          }
          else
          {
            v29 = (UFG::StreamedResourceComponent *)v27->m_Components.p[10].m_pComponent;
          }
          if ( v29 )
          {
            v31 = UFG::StreamedResourceComponent::GetSpawnPriority(v25, 0i64);
            UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v29, v31);
          }
        }
      }
    }
    v32 = (UFG::SimObjectCharacter *)v3->m_pSimObject;
    if ( v32 )
    {
      v33 = v32->m_Flags;
      if ( (v33 >> 14) & 1 )
      {
        v34 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v32);
      }
      else if ( (v33 & 0x8000u) == 0 )
      {
        if ( (v33 >> 13) & 1 )
        {
          v34 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v32->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
        else if ( (v33 >> 12) & 1 )
        {
          v34 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v32->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          v34 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v32->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v34 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v32->vfptr,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      if ( v34 )
        *((_BYTE *)v34 + 553) &= 0xFBu;
    }
  }
}

// File Line: 280
// RVA: 0x676600
void __fastcall UFG::VehicleOccupantComponent::DeleteAllOccupants(UFG::VehicleOccupantComponent *this)
{
  UFG::SimObject *v1; // rbx
  UFG::VehicleOccupantComponent *v2; // rsi
  UFG::SimObjectCharacter *v3; // r14
  UFG::CharacterOccupantComponent *v4; // rdx
  UFG::SimObject *v5; // rdi
  signed __int64 v6; // rbx

  v1 = this->mpDriver.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    UFG::VehicleOccupantComponent::RemoveOccupant(
      this,
      (UFG::CharacterOccupantComponent *)v1->m_Components.p[44].m_pComponent);
    UFG::PedSpawnManager::GetInstance();
    UFG::Simulation::DestroySimObject(&UFG::gSim, v1);
  }
  v3 = LocalPlayer;
  v4 = (UFG::CharacterOccupantComponent *)&v2->mPassengers.mNode.mNext[-4];
  if ( v4 != (UFG::CharacterOccupantComponent *)&v2->m_BoundComponentHandles )
  {
    do
    {
      v5 = v4->m_pSimObject;
      v6 = (signed __int64)&v4->mNext[-4];
      if ( v5 != (UFG::SimObject *)v3 )
      {
        UFG::VehicleOccupantComponent::RemoveOccupant(v2, v4);
        UFG::PedSpawnManager::GetInstance();
        UFG::Simulation::DestroySimObject(&UFG::gSim, v5);
      }
      v4 = (UFG::CharacterOccupantComponent *)v6;
    }
    while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v6 != &v2->m_BoundComponentHandles );
  }
}

// File Line: 310
// RVA: 0x698600
void __fastcall UFG::VehicleOccupantComponent::UpdateOccupantPriority(UFG::VehicleOccupantComponent *this, UFG::qSymbol *oldPriority, UFG::qSymbol *newPriority)
{
  UFG::SimObjectGame *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::qSymbol *v5; // rsi
  UFG::StreamedResourceComponent *v6; // rbx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax

  v3 = (UFG::SimObjectGame *)this->m_pSimObject;
  v4 = newPriority;
  v5 = oldPriority;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 || (v7 & 0x8000u) != 0 )
    {
      v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent;
    }
    else if ( (v7 >> 13) & 1 )
    {
      v6 = (UFG::StreamedResourceComponent *)v3->m_Components.p[7].m_pComponent;
    }
    else
    {
      if ( (v7 >> 12) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StreamedResourceComponent::_TypeUID);
      else
        v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::StreamedResourceComponent::_TypeUID);
      v6 = (UFG::StreamedResourceComponent *)v8;
    }
  }
  else
  {
    v6 = 0i64;
  }
  UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v6, v5);
  UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v6, v4);
}

// File Line: 319
// RVA: 0x67ADA0
__int64 __fastcall UFG::VehicleOccupantComponent::GetNumberOfOccupants(UFG::VehicleOccupantComponent *this)
{
  unsigned int v1; // edx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v2; // r8
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *i; // rax
  __int64 result; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *j; // rcx

  v1 = 0;
  v2 = &this->m_BoundComponentHandles;
  if ( this->mpDriver.m_pPointer )
  {
    for ( i = this->mPassengers.mNode.mNext - 4;
          i != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)v2;
          i = i[4].mNext - 4 )
    {
      ++v1;
    }
    result = v1 + 1;
  }
  else
  {
    for ( j = this->mPassengers.mNode.mNext - 4;
          j != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *)v2;
          j = j[4].mNext - 4 )
    {
      ++v1;
    }
    result = v1;
  }
  return result;
}

// File Line: 329
// RVA: 0x67AE00
__int64 __fastcall UFG::VehicleOccupantComponent::GetNumberOfPassengers(UFG::VehicleOccupantComponent *this)
{
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v1; // rdx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v2; // rcx
  __int64 result; // rax
  signed __int64 i; // rdx

  v1 = this->mPassengers.mNode.mNext;
  v2 = &this->m_BoundComponentHandles;
  result = 0i64;
  for ( i = (signed __int64)&v1[-4];
        (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)i != v2;
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
UFG::SimObject *__fastcall UFG::VehicleOccupantComponent::GetOccupant(UFG::VehicleOccupantComponent *this, unsigned int index, UFG::eTargetTypeEnum *pTargetType)
{
  UFG::eTargetTypeEnum *v3; // r10
  UFG::CharacterOccupantComponent *v5; // r9
  signed int v6; // edx
  UFG::CharacterOccupantComponent *v7; // rax
  signed int v8; // er8
  UFG::CharacterOccupantComponent *j; // rcx
  UFG::CharacterOccupantComponent *v10; // r9
  signed int v11; // er8
  UFG::CharacterOccupantComponent *i; // rcx

  v3 = pTargetType;
  if ( !this->mpDriver.m_pPointer )
  {
    v10 = (UFG::CharacterOccupantComponent *)&this->m_BoundComponentHandles;
    v11 = 0;
    v7 = (UFG::CharacterOccupantComponent *)&this->mPassengers.mNode.mNext[-4];
    for ( i = v7; i != v10; i = (UFG::CharacterOccupantComponent *)&i->mNext[-4] )
      ++v11;
    if ( (signed int)index < v11 )
    {
      for ( ; (signed int)index > 0; v7 = (UFG::CharacterOccupantComponent *)&v7->mNext[-4] )
      {
        if ( v7 == v10 )
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
      *pTargetType = 4;
    return this->mpDriver.m_pPointer;
  }
  v5 = (UFG::CharacterOccupantComponent *)&this->m_BoundComponentHandles;
  v6 = index - 1;
  v7 = (UFG::CharacterOccupantComponent *)&this->mPassengers.mNode.mNext[-4];
  v8 = 0;
  for ( j = v7; j != v5; j = (UFG::CharacterOccupantComponent *)&j->mNext[-4] )
    ++v8;
  if ( v6 >= v8 )
    return 0i64;
  for ( ; v6 > 0; v7 = (UFG::CharacterOccupantComponent *)&v7->mNext[-4] )
  {
    if ( v7 == v5 )
      break;
    --v6;
  }
LABEL_12:
  if ( v3 )
    *v3 = v7->mTargetType;
  return v7->m_pSimObject;
}

// File Line: 392
// RVA: 0x67AF40
UFG::SimObject *__fastcall UFG::VehicleOccupantComponent::GetPassenger(UFG::VehicleOccupantComponent *this, const int iIndex, bool excludeEnteringAndExiting)
{
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> *v3; // rbx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v4; // rcx
  int v5; // er9
  UFG::CharacterOccupantComponent *v6; // rbx
  signed __int64 i; // rax
  UFG::SimObject *result; // rax

  v3 = this->mPassengers.mNode.mNext;
  v4 = &this->m_BoundComponentHandles;
  v5 = 0;
  v6 = (UFG::CharacterOccupantComponent *)&v3[-4];
  for ( i = (signed __int64)v6;
        (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)i != v4;
        i = *(_QWORD *)(i + 0x48) - 0x40i64 )
  {
    ++v5;
  }
  if ( iIndex >= v5 )
    goto LABEL_13;
  for ( ; iIndex > 0; v6 = (UFG::CharacterOccupantComponent *)&v6->mNext[-4] )
  {
    if ( v6 == (UFG::CharacterOccupantComponent *)v4 )
      break;
    --iIndex;
  }
  if ( excludeEnteringAndExiting && UFG::CharacterOccupantComponent::IsEnteringOrExiting(v6) )
LABEL_13:
    result = 0i64;
  else
    result = v6->m_pSimObject;
  return result;
}

// File Line: 411
// RVA: 0x68ACB0
void __fastcall UFG::VehicleOccupantComponent::SetParkingSpot(UFG::RoadNetworkGuide *this, UFG::RoadNetworkLane *roadLane)
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
UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *__fastcall UFG::VehicleOccupantComponent::GetReservationList(UFG::VehicleOccupantComponent *this)
{
  return this->mpReservations;
}

