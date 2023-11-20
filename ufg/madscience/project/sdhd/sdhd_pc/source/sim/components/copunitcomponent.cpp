// File Line: 37
// RVA: 0x1543E00
__int64 dynamic_initializer_for__UFG::CopUnitComponent::s_CopUnitComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CopUnitComponent::s_CopUnitComponentList__);
}

// File Line: 38
// RVA: 0x532690
signed __int64 __fastcall UFG::FacialActionTreeComponent::GetTypeSize(UFG::FacialActionTreeComponent *this)
{
  return 488i64;
}

// File Line: 55
// RVA: 0x516DA0
void __fastcall UFG::CopUnitComponent::CopUnitComponent(UFG::CopUnitComponent *this, unsigned int name_uid)
{
  UFG::CopUnitComponent *v2; // rdi
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v3; // rbx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  v3 = (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CopUnitComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CopUnitComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::TSActorComponent,0>::RebindingComponentHandle<UFG::TSActorComponent,0>(&v2->mpTSActorComponent);
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0>::RebindingComponentHandle<UFG::VehicleAudioComponent,0>(&v2->mpVehicleAudioComponent);
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>(&v2->mpVehicleRenderComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&v2->mpHealthComponent);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>(&v2->mpMoverComponent);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->mpTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v2->mpAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0>::RebindingComponentHandle<UFG::EncounterUnitComponent,0>(&v2->mpEncounterUnitComponent);
  *(_QWORD *)&v2->mAutoKillTimer = 0i64;
  *((_BYTE *)v2 + 480) = 0;
  *((_BYTE *)v2 + 481) &= 0xF8u;
  v4 = UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mPrev;
  UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *)&UFG::CopUnitComponent::s_CopUnitComponentList;
  UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mPrev = (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::CopUnitComponent::_CopUnitComponentTypeUID,
    "CopUnitComponent");
}

// File Line: 62
// RVA: 0x51B430
void __fastcall UFG::CopUnitComponent::~CopUnitComponent(UFG::CopUnitComponent *this)
{
  UFG::CopUnitComponent *v1; // rdi
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v2; // rbx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v3; // rcx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v4; // rax
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v5; // rcx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CopUnitComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CopUnitComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::CopUnitComponent::s_CopUnitComponentpCurrentIterator )
    UFG::CopUnitComponent::s_CopUnitComponentpCurrentIterator = (UFG::CopUnitComponent *)&this->mPrev[-5].mNext;
  v2 = (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mpEncounterUnitComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mpAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->mpTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mpMoverComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mpHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mpVehicleRenderComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mpVehicleAudioComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mpTSActorComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 66
// RVA: 0x1549AC0
__int64 UFG::_dynamic_initializer_for__gsymUsableByCopSystem__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("UsableByCopSystem", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymUsableByCopSystem, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymUsableByCopSystem__);
}

// File Line: 69
// RVA: 0x53D670
void __fastcall UFG::CopUnitComponent::OnAttach(UFG::CopUnitComponent *this, UFG::SimObject *pObject)
{
  UFG::SimComponent *v2; // rbx
  UFG::SimObject *v3; // rdi
  UFG::CopUnitComponent *v4; // rsi
  UFG::SceneObjectProperties *v5; // rax
  UFG::qPropertySet *v6; // rcx
  bool *v7; // rax
  bool v8; // cl
  char v9; // al
  UFG::RebindingComponentHandle<UFG::TSActorComponent,0> *v10; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *v15; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *v20; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *v25; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *v30; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v32; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v35; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *v40; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v42; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v43; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v44; // rax
  UFG::SimComponent *v45; // rax
  SSActorClass *v46; // rax
  SSClass *v47; // rcx
  unsigned __int16 v48; // cx
  unsigned int v49; // er8
  unsigned int v50; // er9
  signed __int64 v51; // rdx

  v2 = 0i64;
  v3 = pObject;
  v4 = this;
  if ( !pObject || (v5 = pObject->m_pSceneObj) == 0i64 )
  {
    v6 = 0i64;
LABEL_6:
    if ( !v6 )
      goto LABEL_9;
    goto LABEL_7;
  }
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v6 = v5->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v7 = UFG::qPropertySet::Get<bool>(v6, (UFG::qSymbol *)&UFG::gsymUsableByCopSystem.mUID, DEPTH_RECURSE);
  if ( v7 )
  {
    v8 = *v7;
    goto LABEL_10;
  }
LABEL_9:
  v8 = 0;
LABEL_10:
  v9 = *((_BYTE *)v4 + 480);
  *((_BYTE *)v4 + 481) &= 0xF8u;
  v10 = &v4->mpTSActorComponent;
  *((_BYTE *)v4 + 480) = v9 & 0x1D | 2 * v8;
  if ( v4->mpTSActorComponent.m_pSimComponent )
  {
    v11 = v10->mPrev;
    v12 = v4->mpTSActorComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v4->mpTSActorComponent.m_pSimComponent = 0i64;
LABEL_16:
    v4->mpTSActorComponent.m_pSimObject = 0i64;
    v4->mpTSActorComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mpTSActorComponent.mPrev;
    v10->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v10->mPrev;
    goto LABEL_17;
  }
  if ( v4->mpTSActorComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TSActorComponent,0> *)v10->mPrev != v10
     || (UFG::RebindingComponentHandle<UFG::TSActorComponent,0> *)v4->mpTSActorComponent.mNext != &v4->mpTSActorComponent) )
  {
    v13 = v10->mPrev;
    v14 = v4->mpTSActorComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_16;
  }
LABEL_17:
  v4->mpTSActorComponent.m_Changed = 1;
  v4->mpTSActorComponent.m_pSimObject = v3;
  v4->mpTSActorComponent.m_TypeUID = UFG::TSActorComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TSActorComponent,0>::BindInternal<UFG::SimObject>(&v4->mpTSActorComponent, v3);
  v15 = &v4->mpVehicleAudioComponent;
  if ( v4->mpVehicleAudioComponent.m_pSimComponent )
  {
    v16 = v15->mPrev;
    v17 = v4->mpVehicleAudioComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v4->mpVehicleAudioComponent.m_pSimComponent = 0i64;
LABEL_23:
    v4->mpVehicleAudioComponent.m_pSimObject = 0i64;
    v4->mpVehicleAudioComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mpVehicleAudioComponent.mPrev;
    v15->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v15->mPrev;
    goto LABEL_24;
  }
  if ( v4->mpVehicleAudioComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *)v15->mPrev != v15
     || (UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *)v4->mpVehicleAudioComponent.mNext != &v4->mpVehicleAudioComponent) )
  {
    v18 = v15->mPrev;
    v19 = v4->mpVehicleAudioComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_23;
  }
LABEL_24:
  v4->mpVehicleAudioComponent.m_Changed = 1;
  v4->mpVehicleAudioComponent.m_pSimObject = v3;
  v4->mpVehicleAudioComponent.m_TypeUID = UFG::VehicleAudioComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0>::BindInternal<UFG::SimObject>(
    &v4->mpVehicleAudioComponent,
    v3);
  v20 = &v4->mpVehicleRenderComponent;
  if ( v4->mpVehicleRenderComponent.m_pSimComponent )
  {
    v21 = v20->mPrev;
    v22 = v4->mpVehicleRenderComponent.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    v4->mpVehicleRenderComponent.m_pSimComponent = 0i64;
LABEL_30:
    v4->mpVehicleRenderComponent.m_pSimObject = 0i64;
    v4->mpVehicleRenderComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mpVehicleRenderComponent.mPrev;
    v20->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v20->mPrev;
    goto LABEL_31;
  }
  if ( v4->mpVehicleRenderComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *)v20->mPrev != v20
     || (UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *)v4->mpVehicleRenderComponent.mNext != &v4->mpVehicleRenderComponent) )
  {
    v23 = v20->mPrev;
    v24 = v4->mpVehicleRenderComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    goto LABEL_30;
  }
LABEL_31:
  v4->mpVehicleRenderComponent.m_Changed = 1;
  v4->mpVehicleRenderComponent.m_pSimObject = v3;
  v4->mpVehicleRenderComponent.m_TypeUID = UFG::VehicleEffectsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::BindInternal<UFG::SimObject>(
    &v4->mpVehicleRenderComponent,
    v3);
  v25 = &v4->mpHealthComponent;
  if ( v4->mpHealthComponent.m_pSimComponent )
  {
    v26 = v25->mPrev;
    v27 = v4->mpHealthComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    v4->mpHealthComponent.m_pSimComponent = 0i64;
LABEL_37:
    v4->mpHealthComponent.m_pSimObject = 0i64;
    v4->mpHealthComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mpHealthComponent.mPrev;
    v25->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v25->mPrev;
    goto LABEL_38;
  }
  if ( v4->mpHealthComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v25->mPrev != v25
     || (UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v4->mpHealthComponent.mNext != &v4->mpHealthComponent) )
  {
    v28 = v25->mPrev;
    v29 = v4->mpHealthComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    goto LABEL_37;
  }
LABEL_38:
  v4->mpHealthComponent.m_Changed = 1;
  v4->mpHealthComponent.m_pSimObject = v3;
  v4->mpHealthComponent.m_TypeUID = UFG::HealthComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::BindInternal<UFG::SimObject>(&v4->mpHealthComponent, v3);
  v30 = &v4->mpMoverComponent;
  if ( v4->mpMoverComponent.m_pSimComponent )
  {
    v31 = v30->mPrev;
    v32 = v4->mpMoverComponent.mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    v4->mpMoverComponent.m_pSimComponent = 0i64;
LABEL_44:
    v4->mpMoverComponent.m_pSimObject = 0i64;
    v4->mpMoverComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mpMoverComponent.mPrev;
    v30->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v30->mPrev;
    goto LABEL_45;
  }
  if ( v4->mpMoverComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v30->mPrev != v30
     || (UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v4->mpMoverComponent.mNext != &v4->mpMoverComponent) )
  {
    v33 = v30->mPrev;
    v34 = v4->mpMoverComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    goto LABEL_44;
  }
LABEL_45:
  v4->mpMoverComponent.m_Changed = 1;
  v4->mpMoverComponent.m_pSimObject = v3;
  v4->mpMoverComponent.m_TypeUID = UFG::PhysicsMoverInterface::_TypeUID;
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::BindInternal<UFG::SimObject>(&v4->mpMoverComponent, v3);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&v4->mpTransformNodeComponent, v3);
  v35 = &v4->mpAIEntityComponent;
  if ( v4->mpAIEntityComponent.m_pSimComponent )
  {
    v36 = v35->mPrev;
    v37 = v4->mpAIEntityComponent.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    v4->mpAIEntityComponent.m_pSimComponent = 0i64;
LABEL_51:
    v4->mpAIEntityComponent.m_pSimObject = 0i64;
    v4->mpAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mpAIEntityComponent.mPrev;
    v35->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v35->mPrev;
    goto LABEL_52;
  }
  if ( v4->mpAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v35->mPrev != v35
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v4->mpAIEntityComponent.mNext != &v4->mpAIEntityComponent) )
  {
    v38 = v35->mPrev;
    v39 = v4->mpAIEntityComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    goto LABEL_51;
  }
LABEL_52:
  v4->mpAIEntityComponent.m_Changed = 1;
  v4->mpAIEntityComponent.m_pSimObject = v3;
  v4->mpAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    &v4->mpAIEntityComponent,
    v3);
  v40 = &v4->mpEncounterUnitComponent;
  if ( v4->mpEncounterUnitComponent.m_pSimComponent )
  {
    v41 = v40->mPrev;
    v42 = v4->mpEncounterUnitComponent.mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    v4->mpEncounterUnitComponent.m_pSimComponent = 0i64;
LABEL_58:
    v4->mpEncounterUnitComponent.m_pSimObject = 0i64;
    v4->mpEncounterUnitComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mpEncounterUnitComponent.mPrev;
    v40->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v40->mPrev;
    goto LABEL_59;
  }
  if ( v4->mpEncounterUnitComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *)v40->mPrev != v40
     || (UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *)v4->mpEncounterUnitComponent.mNext != &v4->mpEncounterUnitComponent) )
  {
    v43 = v40->mPrev;
    v44 = v4->mpEncounterUnitComponent.mNext;
    v43->mNext = v44;
    v44->mPrev = v43;
    goto LABEL_58;
  }
LABEL_59:
  v4->mpEncounterUnitComponent.m_Changed = 1;
  v4->mpEncounterUnitComponent.m_pSimObject = v3;
  v4->mpEncounterUnitComponent.m_TypeUID = UFG::EncounterUnitComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0>::BindInternal<UFG::SimObject>(
    &v4->mpEncounterUnitComponent,
    v3);
  v45 = v4->mpTSActorComponent.m_pSimComponent;
  if ( v45
    && ((v46 = (SSActorClass *)v45[1].m_SafePointerList.mNode.mNext, UFG::SkookumMgr::mspCharacterClass == v46)
     || (v47 = v46->i_superclass_p) != 0i64
     && SSClass::is_class(v47, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr)) )
  {
    v4->mUnitType = 1;
  }
  else if ( v3 )
  {
    v48 = v3->m_Flags;
    if ( !((v48 >> 14) & 1) )
    {
      if ( (v48 & 0x8000u) == 0 )
      {
        if ( (v48 >> 13) & 1 )
          goto LABEL_80;
        if ( (v48 >> 12) & 1 )
        {
          v49 = (unsigned int)v3[1].vfptr;
          v50 = v3->m_Components.size;
          if ( v49 < v50 )
          {
            v51 = (signed __int64)&v3->m_Components.p[v49];
            while ( (*(_DWORD *)(v51 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                 || UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v51 + 8) & 0x1FFFFFF )
            {
              ++v49;
              v51 += 16i64;
              if ( v49 >= v50 )
                goto LABEL_78;
            }
            v2 = *(UFG::SimComponent **)v51;
          }
        }
        else
        {
          v2 = UFG::SimObject::GetComponentOfType(v3, UFG::PhysicsMoverInterface::_TypeUID);
        }
      }
      else
      {
        v2 = v3->m_Components.p[34].m_pComponent;
      }
LABEL_78:
      if ( v2 )
        v4->mUnitType = 3 - (LODWORD(v2[12].m_BoundComponentHandles.mNode.mNext) != 0);
    }
  }
LABEL_80:
  UFG::CopUnitComponent::UpdateAliveStatus(v4);
}

// File Line: 111
// RVA: 0x540080
void __fastcall UFG::CopUnitComponent::OnDetach(UFG::CopUnitComponent *this)
{
  UFG::CopUnitComponent *v1; // rbx
  UFG::RebindingComponentHandle<UFG::TSActorComponent,0> *v2; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v32; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *v37; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax

  *((_BYTE *)this + 481) &= 0xFBu;
  v1 = this;
  UFG::CopUnitComponent::TurnOff(this);
  v2 = &v1->mpTSActorComponent;
  if ( v1->mpTSActorComponent.m_pSimComponent )
  {
    v3 = v2->mPrev;
    v4 = v1->mpTSActorComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mpTSActorComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->mpTSActorComponent.m_pSimObject = 0i64;
    v1->mpTSActorComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mpTSActorComponent.mPrev;
    v2->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    goto LABEL_8;
  }
  if ( v1->mpTSActorComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TSActorComponent,0> *)v2->mPrev != v2
     || (UFG::RebindingComponentHandle<UFG::TSActorComponent,0> *)v1->mpTSActorComponent.mNext != &v1->mpTSActorComponent) )
  {
    v5 = v2->mPrev;
    v6 = v1->mpTSActorComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v1->mpVehicleAudioComponent;
  v1->mpTSActorComponent.m_Changed = 1;
  if ( v1->mpVehicleAudioComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v1->mpVehicleAudioComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v1->mpVehicleAudioComponent.m_pSimComponent = 0i64;
LABEL_14:
    v1->mpVehicleAudioComponent.m_pSimObject = 0i64;
    v1->mpVehicleAudioComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mpVehicleAudioComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v1->mpVehicleAudioComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *)v1->mpVehicleAudioComponent.mNext != &v1->mpVehicleAudioComponent) )
  {
    v10 = v7->mPrev;
    v11 = v1->mpVehicleAudioComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v1->mpVehicleAudioComponent.m_Changed = 1;
  v12 = &v1->mpVehicleRenderComponent;
  if ( v1->mpVehicleRenderComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v1->mpVehicleRenderComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v1->mpVehicleRenderComponent.m_pSimComponent = 0i64;
LABEL_21:
    v1->mpVehicleRenderComponent.m_pSimObject = 0i64;
    v1->mpVehicleRenderComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mpVehicleRenderComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v1->mpVehicleRenderComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *)v1->mpVehicleRenderComponent.mNext != &v1->mpVehicleRenderComponent) )
  {
    v15 = v12->mPrev;
    v16 = v1->mpVehicleRenderComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v1->mpVehicleRenderComponent.m_Changed = 1;
  v17 = &v1->mpHealthComponent;
  if ( v1->mpHealthComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v1->mpHealthComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v1->mpHealthComponent.m_pSimComponent = 0i64;
LABEL_28:
    v1->mpHealthComponent.m_pSimObject = 0i64;
    v1->mpHealthComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mpHealthComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v1->mpHealthComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v1->mpHealthComponent.mNext != &v1->mpHealthComponent) )
  {
    v20 = v17->mPrev;
    v21 = v1->mpHealthComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v1->mpHealthComponent.m_Changed = 1;
  v22 = &v1->mpMoverComponent;
  if ( v1->mpMoverComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v1->mpMoverComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v1->mpMoverComponent.m_pSimComponent = 0i64;
LABEL_35:
    v1->mpMoverComponent.m_pSimObject = 0i64;
    v1->mpMoverComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mpMoverComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v1->mpMoverComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v1->mpMoverComponent.mNext != &v1->mpMoverComponent) )
  {
    v25 = v22->mPrev;
    v26 = v1->mpMoverComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v1->mpMoverComponent.m_Changed = 1;
  v27 = &v1->mpTransformNodeComponent;
  if ( v1->mpTransformNodeComponent.m_pSimComponent )
  {
    v28 = v27->mPrev;
    v29 = v1->mpTransformNodeComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v1->mpTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_42:
    v1->mpTransformNodeComponent.m_pSimObject = 0i64;
    v1->mpTransformNodeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mpTransformNodeComponent.mPrev;
    v27->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v27->mPrev;
    goto LABEL_43;
  }
  if ( v1->mpTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v27->mPrev != v27
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mpTransformNodeComponent.mNext != &v1->mpTransformNodeComponent) )
  {
    v30 = v27->mPrev;
    v31 = v1->mpTransformNodeComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  v1->mpTransformNodeComponent.m_Changed = 1;
  v32 = &v1->mpAIEntityComponent;
  if ( v1->mpAIEntityComponent.m_pSimComponent )
  {
    v33 = v32->mPrev;
    v34 = v1->mpAIEntityComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v1->mpAIEntityComponent.m_pSimComponent = 0i64;
LABEL_49:
    v1->mpAIEntityComponent.m_pSimObject = 0i64;
    v1->mpAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mpAIEntityComponent.mPrev;
    v32->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v32->mPrev;
    goto LABEL_50;
  }
  if ( v1->mpAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v32->mPrev != v32
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v1->mpAIEntityComponent.mNext != &v1->mpAIEntityComponent) )
  {
    v35 = v32->mPrev;
    v36 = v1->mpAIEntityComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  v1->mpAIEntityComponent.m_Changed = 1;
  v37 = &v1->mpEncounterUnitComponent;
  if ( v1->mpEncounterUnitComponent.m_pSimComponent )
  {
    v38 = v37->mPrev;
    v39 = v1->mpEncounterUnitComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    v1->mpEncounterUnitComponent.m_pSimComponent = 0i64;
LABEL_56:
    v1->mpEncounterUnitComponent.m_pSimObject = 0i64;
    v1->mpEncounterUnitComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mpEncounterUnitComponent.mPrev;
    v37->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v37->mPrev;
    goto LABEL_57;
  }
  if ( v1->mpEncounterUnitComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *)v37->mPrev != v37
     || (UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *)v1->mpEncounterUnitComponent.mNext != &v1->mpEncounterUnitComponent) )
  {
    v40 = v37->mPrev;
    v41 = v1->mpEncounterUnitComponent.mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
    goto LABEL_56;
  }
LABEL_57:
  v1->mpEncounterUnitComponent.m_Changed = 1;
  *((_BYTE *)v1 + 480) &= 0xF7u;
}

// File Line: 129
// RVA: 0x5571E0
void __usercall UFG::CopUnitComponent::TurnOn(UFG::CopUnitComponent *this@<rcx>, float a2@<xmm0>)
{
  UFG::CopUnitComponent *v2; // rbx
  UFG::CopSystem *v3; // rax
  char v4; // r15
  bool v5; // r14
  char v6; // dl
  UFG::SimComponent *v7; // rsi
  UFG::TSActorComponent *v8; // rcx
  SSActorClass *v9; // rcx
  SSClass *v10; // rcx
  UFG::SimObject *v11; // rcx
  UFG::SimComponent *v12; // rax
  unsigned __int16 v13; // dx
  unsigned int v14; // er8
  unsigned int v15; // er9
  signed __int64 v16; // rdx
  unsigned int v17; // er8
  unsigned int v18; // er9
  unsigned int v19; // er8
  unsigned int v20; // er9
  UFG::CopSystem *v21; // rax
  char v22; // al
  UFG::SimObject *v23; // rcx
  UFG::SimComponent *v24; // rax
  unsigned __int16 v25; // dx
  unsigned int v26; // er8
  unsigned int v27; // er9
  signed __int64 v28; // rdx
  unsigned int v29; // er8
  unsigned int v30; // er9
  unsigned int v31; // er8
  unsigned int v32; // er9
  bool v33; // di
  UFG::CopSystem *v34; // rax
  char v35; // al
  char v36; // bp
  char v37; // dl
  const char *v38; // rdx
  UFG::SimObject *v39; // rcx
  unsigned __int16 v40; // dx
  unsigned int v41; // er8
  unsigned int v42; // er9
  signed __int64 v43; // rdx
  unsigned int v44; // er8
  unsigned int v45; // er9
  unsigned int v46; // er8
  unsigned int v47; // er9
  unsigned int v48; // er8
  unsigned int v49; // er9
  UFG::BasePhysicsSystem *v50; // rcx
  UFG::SimObject *v51; // rax
  UFG::qBaseTreeRB *v52; // rdi
  UFG::CopSystem *v53; // rax
  UFG::CopSystem *v54; // rax
  UFG::SimComponent *v55; // rcx
  UFG::VehicleEffectsComponent *v56; // rcx
  UFG::qColour color; // [rsp+30h] [rbp-28h]

  v2 = this;
  v3 = UFG::CopSystem::Instance();
  v4 = ((unsigned int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) == 0;
  v5 = *((_BYTE *)v2 + 480) >> 7 != v4;
  v6 = (v4 << 7) | *((_BYTE *)v2 + 480) & 0x7F;
  v7 = 0i64;
  *((_BYTE *)v2 + 480) = v6;
  if ( !(v6 & 0x20) )
  {
    v8 = (UFG::TSActorComponent *)v2->mpTSActorComponent.m_pSimComponent;
    if ( v8 )
    {
      v9 = (SSActorClass *)UFG::TSActorComponent::GetActor(v8)->i_class_p;
      if ( UFG::SkookumMgr::mspCharacterClass == v9
        || (v10 = v9->i_superclass_p) != 0i64
        && SSClass::is_class(v10, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr) )
      {
        v11 = v2->m_pSimObject;
        if ( !v11 )
        {
LABEL_7:
          v12 = 0i64;
LABEL_33:
          *((_BYTE *)v2 + 480) &= 0xBFu;
          *((_BYTE *)v2 + 480) |= (v12 != 0i64) << 6;
          v21 = UFG::CopSystem::Instance();
          v22 = ((__int64 (__fastcall *)(UFG::CopSystem *))v21->vfptr[16].__vecDelDtor)(v21);
          *((_BYTE *)v2 + 481) &= 0xFEu;
          *((_BYTE *)v2 + 481) |= v22 == 0;
          *((_BYTE *)v2 + 480) |= 0x20u;
          goto LABEL_34;
        }
        v13 = v11->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v12 = v11->m_Components.p[44].m_pComponent;
          goto LABEL_33;
        }
        if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
          {
            v17 = (unsigned int)v11[1].vfptr;
            v18 = v11->m_Components.size;
            if ( v17 >= v18 )
              goto LABEL_7;
            v16 = (signed __int64)&v11->m_Components.p[v17];
            while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                 || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
            {
              ++v17;
              v16 += 16i64;
              if ( v17 >= v18 )
              {
                v12 = 0i64;
                goto LABEL_33;
              }
            }
          }
          else
          {
            if ( !((v13 >> 12) & 1) )
            {
              v12 = UFG::SimObject::GetComponentOfType(v11, UFG::CharacterOccupantComponent::_TypeUID);
              goto LABEL_33;
            }
            v19 = (unsigned int)v11[1].vfptr;
            v20 = v11->m_Components.size;
            if ( v19 >= v20 )
              goto LABEL_7;
            v16 = (signed __int64)&v11->m_Components.p[v19];
            while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                 || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
            {
              ++v19;
              v16 += 16i64;
              if ( v19 >= v20 )
              {
                v12 = 0i64;
                goto LABEL_33;
              }
            }
          }
        }
        else
        {
          v14 = (unsigned int)v11[1].vfptr;
          v15 = v11->m_Components.size;
          if ( v14 >= v15 )
            goto LABEL_7;
          v16 = (signed __int64)&v11->m_Components.p[v14];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
          {
            ++v14;
            v16 += 16i64;
            if ( v14 >= v15 )
            {
              v12 = 0i64;
              goto LABEL_33;
            }
          }
        }
        v12 = *(UFG::SimComponent **)v16;
        goto LABEL_33;
      }
    }
  }
LABEL_34:
  if ( !(*((_BYTE *)v2 + 480) & 0x20) || !v2->mpTSActorComponent.m_pSimComponent )
    goto LABEL_117;
  v23 = v2->m_pSimObject;
  if ( !v23 )
    goto LABEL_37;
  v25 = v23->m_Flags;
  if ( (v25 >> 14) & 1 )
  {
    v24 = v23->m_Components.p[44].m_pComponent;
    goto LABEL_63;
  }
  if ( (v25 & 0x8000u) != 0 )
  {
    v26 = (unsigned int)v23[1].vfptr;
    v27 = v23->m_Components.size;
    if ( v26 < v27 )
    {
      v28 = (signed __int64)&v23->m_Components.p[v26];
      while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
      {
        ++v26;
        v28 += 16i64;
        if ( v26 >= v27 )
        {
          v24 = 0i64;
          goto LABEL_63;
        }
      }
LABEL_47:
      v24 = *(UFG::SimComponent **)v28;
      goto LABEL_63;
    }
    goto LABEL_37;
  }
  if ( (v25 >> 13) & 1 )
  {
    v29 = (unsigned int)v23[1].vfptr;
    v30 = v23->m_Components.size;
    if ( v29 < v30 )
    {
      v28 = (signed __int64)&v23->m_Components.p[v29];
      while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
      {
        ++v29;
        v28 += 16i64;
        if ( v29 >= v30 )
        {
          v24 = 0i64;
          goto LABEL_63;
        }
      }
      goto LABEL_47;
    }
LABEL_37:
    v24 = 0i64;
    goto LABEL_63;
  }
  if ( (v25 >> 12) & 1 )
  {
    v31 = (unsigned int)v23[1].vfptr;
    v32 = v23->m_Components.size;
    if ( v31 < v32 )
    {
      v28 = (signed __int64)&v23->m_Components.p[v31];
      while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
      {
        ++v31;
        v28 += 16i64;
        if ( v31 >= v32 )
        {
          v24 = 0i64;
          goto LABEL_63;
        }
      }
      goto LABEL_47;
    }
    goto LABEL_37;
  }
  v24 = UFG::SimObject::GetComponentOfType(v23, UFG::CharacterOccupantComponent::_TypeUID);
LABEL_63:
  v33 = v24 == 0i64;
  v34 = UFG::CopSystem::Instance();
  v35 = ((__int64 (__fastcall *)(UFG::CopSystem *))v34->vfptr[16].__vecDelDtor)(v34);
  v36 = v35;
  v37 = (*((_BYTE *)v2 + 480) >> 6) & 1;
  if ( v33 != v37 )
  {
    if ( !v5 )
      goto LABEL_68;
LABEL_69:
    UFG::SimObjectUtility::DetachHudSymbol(v2->m_pSimObject);
    if ( v4 )
    {
      if ( v33 )
        v38 = "cop_foot_patrol_symbol";
      else
        v38 = "cop_vehicle_patrol_symbol";
    }
    else
    {
      v38 = "cop_foot_symbol";
      if ( !v33 )
        v38 = "cop_symbol";
    }
    UFG::SimObjectUtility::AttachHudSymbol(v2->m_pSimObject, v38, 0, 0.0, &customWorldMapCaption);
    goto LABEL_76;
  }
  if ( v5 )
    goto LABEL_69;
  if ( v35 == (*((_BYTE *)v2 + 481) & 1) )
    goto LABEL_77;
LABEL_68:
  if ( v33 != v37 )
    goto LABEL_69;
LABEL_76:
  *((_BYTE *)v2 + 480) &= 0xBFu;
  *((_BYTE *)v2 + 481) &= 0xFEu;
  *((_BYTE *)v2 + 480) |= v33 << 6;
  *((_BYTE *)v2 + 481) |= v36 & 1;
LABEL_77:
  v39 = v2->m_pSimObject;
  if ( !v39 )
    goto LABEL_117;
  v40 = v39->m_Flags;
  if ( (v40 >> 14) & 1 )
  {
    v41 = (unsigned int)v39[1].vfptr;
    v42 = v39->m_Components.size;
    if ( v41 < v42 )
    {
      v43 = (signed __int64)&v39->m_Components.p[v41];
      while ( (*(_DWORD *)(v43 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v43 + 8) & 0x1FFFFFF )
      {
        ++v41;
        v43 += 16i64;
        if ( v41 >= v42 )
          goto LABEL_108;
      }
LABEL_85:
      v7 = *(UFG::SimComponent **)v43;
      goto LABEL_108;
    }
  }
  else
  {
    if ( (v40 & 0x8000u) != 0 )
    {
      v44 = (unsigned int)v39[1].vfptr;
      v45 = v39->m_Components.size;
      if ( v44 >= v45 )
        goto LABEL_108;
      v43 = (signed __int64)&v39->m_Components.p[v44];
      while ( (*(_DWORD *)(v43 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v43 + 8) & 0x1FFFFFF )
      {
        ++v44;
        v43 += 16i64;
        if ( v44 >= v45 )
          goto LABEL_108;
      }
      goto LABEL_85;
    }
    if ( (v40 >> 13) & 1 )
    {
      v46 = (unsigned int)v39[1].vfptr;
      v47 = v39->m_Components.size;
      if ( v46 >= v47 )
        goto LABEL_108;
      v43 = (signed __int64)&v39->m_Components.p[v46];
      while ( (*(_DWORD *)(v43 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v43 + 8) & 0x1FFFFFF )
      {
        ++v46;
        v43 += 16i64;
        if ( v46 >= v47 )
          goto LABEL_108;
      }
      goto LABEL_85;
    }
    if ( !((v40 >> 12) & 1) )
    {
      v7 = UFG::SimObject::GetComponentOfType(v39, UFG::HudComponent::_TypeUID);
      goto LABEL_108;
    }
    v48 = (unsigned int)v39[1].vfptr;
    v49 = v39->m_Components.size;
    if ( v48 < v49 )
    {
      v43 = (signed __int64)&v39->m_Components.p[v48];
      while ( (*(_DWORD *)(v43 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v43 + 8) & 0x1FFFFFF )
      {
        ++v48;
        v43 += 16i64;
        if ( v48 >= v49 )
          goto LABEL_108;
      }
      goto LABEL_85;
    }
  }
LABEL_108:
  if ( v7 )
  {
    v50 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
    if ( UFG::UIHKScreenHud::mIconManager )
    {
      if ( !LODWORD(v7[4].m_SafePointerList.mNode.mNext) )
      {
        v51 = v7->m_pSimObject;
        if ( v51 )
          LODWORD(v7[4].m_SafePointerList.mNode.mNext) = v51->m_Name.mUID;
      }
      v52 = UFG::BasePhysicsSystem::GetCollisionModel(v50, (unsigned int)v7[4].m_SafePointerList.mNode.mNext);
      if ( v52 )
      {
        if ( *((_BYTE *)v2 + 480) >= 0 )
        {
          v54 = UFG::CopSystem::Instance();
          ((void (__fastcall *)(UFG::CopSystem *, _QWORD, UFG::SimComponent *))v54->vfptr[17].__vecDelDtor)(
            v54,
            (*((_BYTE *)v2 + 480) >> 6) & 1,
            v2->mpEncounterUnitComponent.m_pSimComponent);
          UFG::UIMapBlip::SetRange((UFG::UIMapBlip *)v52, 1, a2);
        }
        else
        {
          v53 = UFG::CopSystem::Instance();
          ((void (__fastcall *)(UFG::CopSystem *, _QWORD, UFG::SimComponent *))v53->vfptr[17].__vecDelDtor)(
            v53,
            (*((_BYTE *)v2 + 480) >> 6) & 1,
            v2->mpEncounterUnitComponent.m_pSimComponent);
          color.b = 1.0;
          color.r = FLOAT_0_12;
          color.g = FLOAT_0_57999998;
          color.a = FLOAT_0_25;
          UFG::UIMapBlip::SetRange((UFG::UIMapBlip *)v52, 1, a2, &color, 1.0);
        }
      }
    }
  }
LABEL_117:
  if ( *((_BYTE *)v2 + 480) >= 0 )
  {
    if ( !(*((_BYTE *)v2 + 481) & 2) )
    {
      v55 = v2->mpVehicleAudioComponent.m_pSimComponent;
      if ( v55 )
      {
        if ( BYTE4(v55[9].m_BoundComponentHandles.mNode.mNext) & 1 )
        {
          UFG::VehicleAudioComponent::StartSiren((UFG::VehicleAudioComponent *)v55, 1);
          *((_BYTE *)v2 + 481) |= 2u;
        }
      }
    }
    v56 = (UFG::VehicleEffectsComponent *)v2->mpVehicleRenderComponent.m_pSimComponent;
    if ( v56 )
      UFG::VehicleEffectsComponent::TurnOnCopLights(v56);
  }
}

// File Line: 243
// RVA: 0x54E620
void __fastcall UFG::CopUnitComponent::SetScriptedLightsOn(UFG::CopUnitComponent *this, bool bEnabled)
{
  UFG::CopUnitComponent *v2; // rdi
  UFG::VehicleEffectsComponent *v3; // rcx
  bool v4; // bl

  v2 = this;
  v3 = (UFG::VehicleEffectsComponent *)this->mpVehicleRenderComponent.m_pSimComponent;
  v4 = bEnabled;
  if ( v3 )
  {
    if ( bEnabled )
      UFG::VehicleEffectsComponent::TurnOnCopLights(v3);
    else
      UFG::VehicleEffectsComponent::TurnOffCopLights(v3);
    *((_BYTE *)v2 + 0x1E1) &= 0xFBu;
    *((_BYTE *)v2 + 0x1E1) |= 4 * v4;
  }
}

// File Line: 263
// RVA: 0x557160
void __fastcall UFG::CopUnitComponent::TurnOff(UFG::CopUnitComponent *this)
{
  UFG::CopUnitComponent *v1; // rbx
  UFG::SimComponent *v2; // rcx
  UFG::VehicleEffectsComponent *v3; // rcx

  v1 = this;
  if ( *((_BYTE *)this + 480) & 0x20 && this->mpTSActorComponent.m_pSimComponent )
  {
    UFG::SimObjectUtility::DetachHudSymbol(this->m_pSimObject);
    *((_BYTE *)v1 + 480) &= 0xDFu;
  }
  if ( *((_BYTE *)v1 + 481) & 2 )
  {
    v2 = v1->mpVehicleAudioComponent.m_pSimComponent;
    if ( v2 )
    {
      if ( BYTE4(v2[9].m_BoundComponentHandles.mNode.mNext) & 1 )
      {
        UFG::VehicleAudioComponent::StopSiren((UFG::VehicleAudioComponent *)v2, 1);
        *((_BYTE *)v1 + 481) &= 0xFDu;
      }
    }
  }
  v3 = (UFG::VehicleEffectsComponent *)v1->mpVehicleRenderComponent.m_pSimComponent;
  if ( v3 )
  {
    if ( !(*((_BYTE *)v1 + 481) & 4) )
      UFG::VehicleEffectsComponent::TurnOffCopLights(v3);
  }
}

// File Line: 302
// RVA: 0x526190
void __fastcall UFG::CopUnitComponent::DisableHandler(UFG::CopUnitComponent *this)
{
  UFG::CopUnitComponent *v1; // rsi
  UFG::SimObject *v2; // rbx
  UFG::VehicleEffectsComponent *v3; // rdi
  UFG::SimComponentHolder *v4; // rax
  UFG::VehicleOccupantComponent *v5; // rbp
  unsigned int v6; // edi
  unsigned int v7; // er14
  UFG::SimObject *v8; // rax
  UFG::SimObject *v9; // rbx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  unsigned int v12; // er8
  unsigned int v13; // er9
  signed __int64 v14; // rdx
  unsigned int v15; // er8
  unsigned int v16; // er9
  unsigned __int16 v17; // cx
  UFG::HealthComponent *v18; // rax
  unsigned int v19; // er8
  unsigned int v20; // er9
  signed __int64 v21; // rdx
  unsigned int v22; // er8
  unsigned int v23; // er9
  UFG::SimComponent *v24; // rcx
  UFG::VehicleEffectsComponent *v25; // rcx

  v1 = this;
  if ( (unsigned int)(this->mUnitType - 2) <= 1 )
  {
    *((_BYTE *)this + 481) &= 0xFBu;
    v2 = this->m_pSimObject;
    if ( v2 )
      v3 = (UFG::VehicleEffectsComponent *)v2->m_Components.p[32].m_pComponent;
    else
      v3 = 0i64;
    if ( UFG::VehicleEffectsComponent::AreCopLightsOn(v3) )
      UFG::VehicleEffectsComponent::TurnOnDisabledEffect(v3);
    if ( v2 )
    {
      v4 = v2->m_Components.p;
      v5 = (UFG::VehicleOccupantComponent *)v4[30].m_pComponent;
      if ( v5 )
      {
        v6 = 0;
        v7 = UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)v4[30].m_pComponent);
        if ( v7 )
        {
          while ( 1 )
          {
            v8 = UFG::VehicleOccupantComponent::GetOccupant(v5, v6, 0i64);
            v9 = v8;
            if ( !v8 )
              goto LABEL_54;
            v10 = v8->m_Flags;
            if ( (v10 >> 14) & 1 )
            {
              v11 = v8->m_Components.p[16].m_pComponent;
              goto LABEL_31;
            }
            if ( (v10 & 0x8000u) != 0 )
            {
              v11 = v8->m_Components.p[16].m_pComponent;
              goto LABEL_31;
            }
            if ( (v10 >> 13) & 1 )
              break;
            if ( (v10 >> 12) & 1 )
            {
              v15 = (unsigned int)v8[1].vfptr;
              v16 = v8->m_Components.size;
              if ( v15 >= v16 )
              {
LABEL_21:
                v11 = 0i64;
                goto LABEL_31;
              }
              v14 = (signed __int64)&v8->m_Components.p[v15];
              while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::EncounterUnitComponent::_TypeUID & 0xFE000000)
                   || UFG::EncounterUnitComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
              {
                ++v15;
                v14 += 16i64;
                if ( v15 >= v16 )
                {
                  v11 = 0i64;
                  goto LABEL_31;
                }
              }
              goto LABEL_22;
            }
            v11 = UFG::SimObject::GetComponentOfType(v8, UFG::EncounterUnitComponent::_TypeUID);
LABEL_31:
            if ( v11 )
            {
              v17 = v9->m_Flags;
              if ( (v17 >> 14) & 1 )
              {
                v18 = (UFG::HealthComponent *)v9->m_Components.p[6].m_pComponent;
                goto LABEL_52;
              }
              if ( (v17 & 0x8000u) != 0 )
              {
                v18 = (UFG::HealthComponent *)v9->m_Components.p[6].m_pComponent;
                goto LABEL_52;
              }
              if ( (v17 >> 13) & 1 )
              {
                v19 = (unsigned int)v9[1].vfptr;
                v20 = v9->m_Components.size;
                if ( v19 < v20 )
                {
                  v21 = (signed __int64)&v9->m_Components.p[v19];
                  while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                       || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
                  {
                    ++v19;
                    v21 += 16i64;
                    if ( v19 >= v20 )
                      goto LABEL_42;
                  }
                  goto LABEL_43;
                }
LABEL_42:
                v18 = 0i64;
              }
              else if ( (v17 >> 12) & 1 )
              {
                v22 = (unsigned int)v9[1].vfptr;
                v23 = v9->m_Components.size;
                if ( v22 >= v23 )
                  goto LABEL_42;
                v21 = (signed __int64)&v9->m_Components.p[v22];
                while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                     || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
                {
                  ++v22;
                  v21 += 16i64;
                  if ( v22 >= v23 )
                  {
                    v18 = 0i64;
                    goto LABEL_52;
                  }
                }
LABEL_43:
                v18 = *(UFG::HealthComponent **)v21;
              }
              else
              {
                v18 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(v9, UFG::HealthComponent::_TypeUID);
              }
LABEL_52:
              if ( v18 )
              {
                v18->m_bIsInvulnerable = 0;
                UFG::HealthComponent::SetHealth(v18, 0, 0i64);
              }
            }
LABEL_54:
            if ( ++v6 >= v7 )
              goto LABEL_55;
          }
          v12 = (unsigned int)v8[1].vfptr;
          v13 = v8->m_Components.size;
          if ( v12 >= v13 )
            goto LABEL_21;
          v14 = (signed __int64)&v8->m_Components.p[v12];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::EncounterUnitComponent::_TypeUID & 0xFE000000)
               || UFG::EncounterUnitComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
          {
            ++v12;
            v14 += 16i64;
            if ( v12 >= v13 )
              goto LABEL_21;
          }
LABEL_22:
          v11 = *(UFG::SimComponent **)v14;
          goto LABEL_31;
        }
      }
    }
  }
LABEL_55:
  if ( *((_BYTE *)v1 + 480) & 0x20 && v1->mpTSActorComponent.m_pSimComponent )
  {
    UFG::SimObjectUtility::DetachHudSymbol(v1->m_pSimObject);
    *((_BYTE *)v1 + 480) &= 0xDFu;
  }
  if ( *((_BYTE *)v1 + 481) & 2 )
  {
    v24 = v1->mpVehicleAudioComponent.m_pSimComponent;
    if ( v24 )
    {
      if ( BYTE4(v24[9].m_BoundComponentHandles.mNode.mNext) & 1 )
      {
        UFG::VehicleAudioComponent::StopSiren((UFG::VehicleAudioComponent *)v24, 1);
        *((_BYTE *)v1 + 481) &= 0xFDu;
      }
    }
  }
  v25 = (UFG::VehicleEffectsComponent *)v1->mpVehicleRenderComponent.m_pSimComponent;
  if ( v25 )
  {
    if ( !(*((_BYTE *)v1 + 481) & 4) )
      UFG::VehicleEffectsComponent::TurnOffCopLights(v25);
  }
}

// File Line: 348
// RVA: 0x55DF30
void __fastcall UFG::CopUnitComponent::UpdateAliveStatus(UFG::CopUnitComponent *this)
{
  UFG::CopUnitComponent *v1; // rbx
  UFG::PhysicsMoverInterface *v2; // rcx
  UFG::SimComponent *v3; // rax
  char v4; // cl
  bool v5; // dl
  char v6; // dl
  UFG::SimComponent *v7; // rax

  *((_BYTE *)this + 480) &= 0xF7u;
  v1 = this;
  v2 = (UFG::PhysicsMoverInterface *)this->mpMoverComponent.m_pSimComponent;
  if ( !v2 || UFG::PhysicsMoverInterface::GetEngineDamage(v2) < 1.0 )
  {
    v3 = v1->mpHealthComponent.m_pSimComponent;
    v4 = 1;
    v5 = v3 && !BYTE4(v3[1].m_BoundComponentHandles.mNode.mPrev);
    v6 = *((_BYTE *)v1 + 480) ^ (*((_BYTE *)v1 + 480) ^ (*((_BYTE *)v1 + 480) | 8 * v5)) & 8;
    v7 = v1->mpEncounterUnitComponent.m_pSimComponent;
    *((_BYTE *)v1 + 480) = v6;
    if ( !v7 || HIBYTE(v7[2].m_SafePointerList.mNode.mPrev) )
      v4 = 0;
    *((_BYTE *)v1 + 480) = v6 ^ (v6 ^ (v6 | 8 * v4)) & 8;
  }
}

// File Line: 361
// RVA: 0x5635C0
void __fastcall UFG::CopUnitComponent::UpdateVisibleStatus(UFG::CopUnitComponent *this)
{
  UFG::SimComponent *v1; // rdi
  UFG::CopUnitComponent *v2; // rbx
  bool v3; // al

  v1 = this->mpTransformNodeComponent.m_pSimComponent;
  v2 = this;
  v3 = 0;
  if ( v1 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpTransformNodeComponent.m_pSimComponent);
    if ( UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&v1[2].m_BoundComponentHandles, 2.0, 0) )
      v3 = 1;
  }
  *((_BYTE *)v2 + 480) &= 0xEFu;
  *((_BYTE *)v2 + 480) |= 16 * v3;
}

// File Line: 368
// RVA: 0x55AAD0
void __usercall UFG::CopUnitComponent::Update(UFG::CopUnitComponent *this@<rcx>, float deltaTime@<xmm1>, float a3@<xmm0>)
{
  __int64 v3; // rbx
  UFG::StreamedResourceComponent *v4; // rdi
  UFG::CopUnitComponent *v5; // rbp
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rcx
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  unsigned int v13; // er8
  unsigned int v14; // er9
  __int64 v15; // rax
  char v16; // al
  UFG::CopUnitComponent *v17; // rcx
  char v18; // al
  float v19; // xmm6_4
  UFG::CopSystem *v20; // rax
  UFG::SimObjectCharacter *v21; // rax
  UFG::TransformNodeComponent *v22; // rbx
  float v23; // xmm6_4
  float v24; // xmm8_4
  float v25; // xmm7_4
  float *v26; // rbx
  unsigned __int16 v27; // cx
  unsigned int v28; // er8
  unsigned int v29; // er9
  signed __int64 v30; // rdx

  v3 = *(_QWORD *)&this[-1].mpEncounterUnitComponent.m_Changed;
  v4 = 0i64;
  v5 = this;
  if ( !v3 )
    goto LABEL_29;
  v6 = *(_WORD *)(v3 + 76);
  if ( !((v6 >> 14) & 1) )
  {
    if ( (v6 & 0x8000u) != 0 )
    {
      v7 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 368i64);
      if ( !v7 )
        goto LABEL_6;
      v9 = v7->m_TypeUID;
      if ( (v9 ^ UFG::HumanDriverComponent::_TypeUID) & 0xFE000000 )
        goto LABEL_6;
      if ( UFG::HumanDriverComponent::_TypeUID & ~v9 & 0x1FFFFFF )
        v7 = 0i64;
      goto LABEL_28;
    }
    if ( (v6 >> 13) & 1 )
    {
      v10 = *(_DWORD *)(v3 + 128);
      v11 = *(_DWORD *)(v3 + 96);
      if ( v10 < v11 )
      {
        v12 = *(_QWORD *)(v3 + 104) + 16i64 * v10;
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::HumanDriverComponent::_TypeUID & 0xFE000000)
             || UFG::HumanDriverComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
        {
          ++v10;
          v12 += 16i64;
          if ( v10 >= v11 )
          {
            v7 = 0i64;
            goto LABEL_28;
          }
        }
LABEL_19:
        v7 = *(UFG::SimComponent **)v12;
        goto LABEL_28;
      }
    }
    else
    {
      if ( !((v6 >> 12) & 1) )
      {
        v7 = UFG::SimObject::GetComponentOfType(
               *(UFG::SimObject **)&this[-1].mpEncounterUnitComponent.m_Changed,
               UFG::HumanDriverComponent::_TypeUID);
        goto LABEL_28;
      }
      v13 = *(_DWORD *)(v3 + 128);
      v14 = *(_DWORD *)(v3 + 96);
      if ( v13 < v14 )
      {
        v12 = *(_QWORD *)(v3 + 104) + 16i64 * v13;
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::HumanDriverComponent::_TypeUID & 0xFE000000)
             || UFG::HumanDriverComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
        {
          ++v13;
          v12 += 16i64;
          if ( v13 >= v14 )
          {
            v7 = 0i64;
            goto LABEL_28;
          }
        }
        goto LABEL_19;
      }
    }
LABEL_6:
    v7 = 0i64;
    goto LABEL_28;
  }
  v7 = *(UFG::SimComponent **)(*(_QWORD *)(v3 + 104) + 368i64);
  if ( !v7 )
    goto LABEL_6;
  v8 = v7->m_TypeUID;
  if ( (v8 ^ UFG::HumanDriverComponent::_TypeUID) & 0xFE000000 || UFG::HumanDriverComponent::_TypeUID & ~v8 & 0x1FFFFFF )
    goto LABEL_6;
LABEL_28:
  if ( v7 )
    return;
LABEL_29:
  UFG::CopUnitComponent::UpdateAliveStatus((UFG::CopUnitComponent *)((char *)v5 - 64));
  UFG::CopUnitComponent::UpdateVisibleStatus((UFG::CopUnitComponent *)((char *)v5 - 64));
  v15 = *(_QWORD *)&v5[-1].mpEncounterUnitComponent.m_Changed;
  if ( v15 && (*(_WORD *)(v15 + 76) >> 10) & 1 )
    return;
  v16 = v5->mpAIEntityComponent.m_Changed;
  if ( v16 & 4 || !(v16 & 1) )
  {
    v17 = (UFG::CopUnitComponent *)((char *)v5 - 64);
    goto LABEL_36;
  }
  v17 = (UFG::CopUnitComponent *)((char *)v5 - 64);
  if ( !(v16 & 8) )
  {
LABEL_36:
    UFG::CopUnitComponent::TurnOff(v17);
    goto LABEL_37;
  }
  UFG::CopUnitComponent::TurnOn(v17, a3);
LABEL_37:
  v18 = v5->mpAIEntityComponent.m_Changed;
  if ( !(v18 & 4) )
  {
LABEL_50:
    LODWORD(v5->mpAIEntityComponent.m_pSimObject) = 0;
    return;
  }
  if ( v18 & 0x10 )
    v19 = 0.0;
  else
    v19 = deltaTime + *(float *)&v5->mpAIEntityComponent.m_pSimObject;
  *(float *)&v5->mpAIEntityComponent.m_pSimObject = v19;
  if ( v19 > 15.0 )
  {
    if ( v3 )
    {
      v27 = *(_WORD *)(v3 + 76);
      if ( (v27 >> 14) & 1 )
      {
        v4 = *(UFG::StreamedResourceComponent **)(*(_QWORD *)(v3 + 104) + 160i64);
      }
      else if ( (v27 & 0x8000u) == 0 )
      {
        if ( (v27 >> 13) & 1 )
        {
          v4 = *(UFG::StreamedResourceComponent **)(*(_QWORD *)(v3 + 104) + 112i64);
        }
        else if ( (v27 >> 12) & 1 )
        {
          v28 = *(_DWORD *)(v3 + 128);
          v29 = *(_DWORD *)(v3 + 96);
          if ( v28 < v29 )
          {
            v30 = *(_QWORD *)(v3 + 104) + 16i64 * v28;
            while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
                 || UFG::StreamedResourceComponent::_TypeUID & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
            {
              ++v28;
              v30 += 16i64;
              if ( v28 >= v29 )
                goto LABEL_68;
            }
            v4 = *(UFG::StreamedResourceComponent **)v30;
          }
        }
        else
        {
          v4 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)v3,
                                                   UFG::StreamedResourceComponent::_TypeUID);
        }
      }
      else
      {
        v4 = *(UFG::StreamedResourceComponent **)(*(_QWORD *)(v3 + 104) + 160i64);
      }
    }
LABEL_68:
    if ( UFG::StreamedResourceComponent::GetSpawnPriority(v4, 0i64)->mUID != qSymbol_Critical.mUID )
      UFG::Simulation::QueueSimObjectToBeDestroyed(
        &UFG::gSim,
        *(UFG::SimObject **)&v5[-1].mpEncounterUnitComponent.m_Changed);
  }
  else if ( v19 > 5.0 )
  {
    if ( v5->mpMoverComponent.mNext )
    {
      v20 = UFG::CopSystem::Instance();
      if ( !((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v20->vfptr[12].__vecDelDtor)(v20)
        || !v5->mpHealthComponent.mNext )
      {
        v21 = UFG::GetLocalPlayer();
        v22 = (UFG::TransformNodeComponent *)(v21 ? v21->m_Components.p[2].m_pComponent : 0i64);
        UFG::TransformNodeComponent::UpdateWorldTransform(v22);
        v23 = v22->mWorldTransform.v3.x;
        v24 = v22->mWorldTransform.v3.y;
        v25 = v22->mWorldTransform.v3.z;
        v26 = (float *)v5->mpMoverComponent.mNext;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->mpMoverComponent.mNext);
        if ( (float)((float)((float)((float)(v24 - v26[45]) * (float)(v24 - v26[45]))
                           + (float)((float)(v23 - v26[44]) * (float)(v23 - v26[44])))
                   + (float)((float)(v25 - v26[46]) * (float)(v25 - v26[46]))) < 2500.0 )
          goto LABEL_50;
      }
    }
  }
}

// File Line: 451
// RVA: 0x5355E0
bool __fastcall UFG::CopUnitComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(v2, (UFG::qSymbol *)&SimSymX_propset_componentCopUnit.mUID, DEPTH_RECURSE) != 0i64;
}

// File Line: 457
// RVA: 0x544E60
UFG::SimComponent *__fastcall UFG::CopUnitComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned __int16 v7; // cx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x1E8ui64, "CopUnitComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::CopUnitComponent::CopUnitComponent((UFG::CopUnitComponent *)v3, v1->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1->m_pSimObject;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 || (v7 & 0x8000u) != 0 )
    v8 = 17;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v5, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v5;
}

