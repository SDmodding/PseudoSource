// File Line: 37
// RVA: 0x1543E00
__int64 dynamic_initializer_for__UFG::CopUnitComponent::s_CopUnitComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CopUnitComponent::s_CopUnitComponentList__);
}

// File Line: 38
// RVA: 0x532690
__int64 __fastcall UFG::FacialActionTreeComponent::GetTypeSize(UFG::FacialActionTreeComponent *this)
{
  return 488i64;
}

// File Line: 55
// RVA: 0x516DA0
void __fastcall UFG::CopUnitComponent::CopUnitComponent(UFG::CopUnitComponent *this, unsigned int name_uid)
{
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent>;
  this->mNext = &this->UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CopUnitComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CopUnitComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::TSActorComponent,0>::RebindingComponentHandle<UFG::TSActorComponent,0>(&this->mpTSActorComponent);
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0>::RebindingComponentHandle<UFG::VehicleAudioComponent,0>(&this->mpVehicleAudioComponent);
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>(&this->mpVehicleRenderComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&this->mpHealthComponent);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>(&this->mpMoverComponent);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mpTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->mpAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0>::RebindingComponentHandle<UFG::EncounterUnitComponent,0>(&this->mpEncounterUnitComponent);
  *(_QWORD *)&this->mAutoKillTimer = 0i64;
  *((_BYTE *)this + 480) = 0;
  *((_BYTE *)this + 481) &= 0xF8u;
  mPrev = UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mPrev;
  UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *)&UFG::CopUnitComponent::s_CopUnitComponentList;
  UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent>;
  UFG::SimComponent::AddType(this, UFG::CopUnitComponent::_CopUnitComponentTypeUID, "CopUnitComponent");
}

// File Line: 62
// RVA: 0x51B430
void __fastcall UFG::CopUnitComponent::~CopUnitComponent(UFG::CopUnitComponent *this)
{
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v2; // rbx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *mPrev; // rcx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *mNext; // rax
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v5; // rcx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v6; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CopUnitComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CopUnitComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::CopUnitComponent::s_CopUnitComponentpCurrentIterator )
    UFG::CopUnitComponent::s_CopUnitComponentpCurrentIterator = (UFG::CopUnitComponent *)&this->mPrev[-5].mNext;
  v2 = &this->UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mpEncounterUnitComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mpAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mpTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mpMoverComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mpHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mpVehicleRenderComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mpVehicleAudioComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mpTSActorComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 66
// RVA: 0x1549AC0
__int64 UFG::_dynamic_initializer_for__gsymUsableByCopSystem__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("UsableByCopSystem", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymUsableByCopSystem, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymUsableByCopSystem__);
}

// File Line: 69
// RVA: 0x53D670
void __fastcall UFG::CopUnitComponent::OnAttach(UFG::CopUnitComponent *this, UFG::SimObject *pObject)
{
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v7; // rax
  bool v8; // cl
  char v9; // al
  UFG::RebindingComponentHandle<UFG::TSActorComponent,0> *p_mpTSActorComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *p_mpVehicleAudioComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *p_mpVehicleRenderComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *p_mpHealthComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *p_mpMoverComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v32; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_mpAIEntityComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *p_mpEncounterUnitComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v42; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v43; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v44; // rax
  UFG::SimComponent *m_pSimComponent; // rax
  SSActorClass *v46; // rax
  SSClass *i_superclass_p; // rcx
  signed __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v51; // rdx

  m_pComponent = 0i64;
  if ( !pObject || (m_pSceneObj = pObject->m_pSceneObj) == 0i64 )
  {
    mpWritableProperties = 0i64;
LABEL_6:
    if ( !mpWritableProperties )
      goto LABEL_9;
    goto LABEL_7;
  }
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v7 = UFG::qPropertySet::Get<bool>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&UFG::gsymUsableByCopSystem,
         DEPTH_RECURSE);
  if ( v7 )
  {
    v8 = *v7;
    goto LABEL_10;
  }
LABEL_9:
  v8 = 0;
LABEL_10:
  v9 = *((_BYTE *)this + 480);
  *((_BYTE *)this + 481) &= 0xF8u;
  p_mpTSActorComponent = &this->mpTSActorComponent;
  *((_BYTE *)this + 480) = v9 & 0x1D | (2 * v8);
  if ( this->mpTSActorComponent.m_pSimComponent )
  {
    mPrev = p_mpTSActorComponent->mPrev;
    mNext = this->mpTSActorComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mpTSActorComponent.m_pSimComponent = 0i64;
LABEL_16:
    this->mpTSActorComponent.m_pSimObject = 0i64;
    this->mpTSActorComponent.mNext = &this->mpTSActorComponent;
    p_mpTSActorComponent->mPrev = p_mpTSActorComponent;
    goto LABEL_17;
  }
  if ( this->mpTSActorComponent.m_pSimObject
    && (p_mpTSActorComponent->mPrev != p_mpTSActorComponent
     || this->mpTSActorComponent.mNext != &this->mpTSActorComponent) )
  {
    v13 = p_mpTSActorComponent->mPrev;
    v14 = this->mpTSActorComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_16;
  }
LABEL_17:
  this->mpTSActorComponent.m_Changed = 1;
  this->mpTSActorComponent.m_pSimObject = pObject;
  this->mpTSActorComponent.m_TypeUID = UFG::TSActorComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TSActorComponent,0>::BindInternal<UFG::SimObject>(
    &this->mpTSActorComponent,
    pObject);
  p_mpVehicleAudioComponent = &this->mpVehicleAudioComponent;
  if ( this->mpVehicleAudioComponent.m_pSimComponent )
  {
    v16 = p_mpVehicleAudioComponent->mPrev;
    v17 = this->mpVehicleAudioComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    this->mpVehicleAudioComponent.m_pSimComponent = 0i64;
LABEL_23:
    this->mpVehicleAudioComponent.m_pSimObject = 0i64;
    this->mpVehicleAudioComponent.mNext = &this->mpVehicleAudioComponent;
    p_mpVehicleAudioComponent->mPrev = p_mpVehicleAudioComponent;
    goto LABEL_24;
  }
  if ( this->mpVehicleAudioComponent.m_pSimObject
    && (p_mpVehicleAudioComponent->mPrev != p_mpVehicleAudioComponent
     || this->mpVehicleAudioComponent.mNext != &this->mpVehicleAudioComponent) )
  {
    v18 = p_mpVehicleAudioComponent->mPrev;
    v19 = this->mpVehicleAudioComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_23;
  }
LABEL_24:
  this->mpVehicleAudioComponent.m_Changed = 1;
  this->mpVehicleAudioComponent.m_pSimObject = pObject;
  this->mpVehicleAudioComponent.m_TypeUID = UFG::VehicleAudioComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0>::BindInternal<UFG::SimObject>(
    &this->mpVehicleAudioComponent,
    pObject);
  p_mpVehicleRenderComponent = &this->mpVehicleRenderComponent;
  if ( this->mpVehicleRenderComponent.m_pSimComponent )
  {
    v21 = p_mpVehicleRenderComponent->mPrev;
    v22 = this->mpVehicleRenderComponent.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    this->mpVehicleRenderComponent.m_pSimComponent = 0i64;
LABEL_30:
    this->mpVehicleRenderComponent.m_pSimObject = 0i64;
    this->mpVehicleRenderComponent.mNext = &this->mpVehicleRenderComponent;
    p_mpVehicleRenderComponent->mPrev = p_mpVehicleRenderComponent;
    goto LABEL_31;
  }
  if ( this->mpVehicleRenderComponent.m_pSimObject
    && (p_mpVehicleRenderComponent->mPrev != p_mpVehicleRenderComponent
     || this->mpVehicleRenderComponent.mNext != &this->mpVehicleRenderComponent) )
  {
    v23 = p_mpVehicleRenderComponent->mPrev;
    v24 = this->mpVehicleRenderComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    goto LABEL_30;
  }
LABEL_31:
  this->mpVehicleRenderComponent.m_Changed = 1;
  this->mpVehicleRenderComponent.m_pSimObject = pObject;
  this->mpVehicleRenderComponent.m_TypeUID = UFG::VehicleEffectsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::BindInternal<UFG::SimObject>(
    &this->mpVehicleRenderComponent,
    pObject);
  p_mpHealthComponent = &this->mpHealthComponent;
  if ( this->mpHealthComponent.m_pSimComponent )
  {
    v26 = p_mpHealthComponent->mPrev;
    v27 = this->mpHealthComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    this->mpHealthComponent.m_pSimComponent = 0i64;
LABEL_37:
    this->mpHealthComponent.m_pSimObject = 0i64;
    this->mpHealthComponent.mNext = &this->mpHealthComponent;
    p_mpHealthComponent->mPrev = p_mpHealthComponent;
    goto LABEL_38;
  }
  if ( this->mpHealthComponent.m_pSimObject
    && (p_mpHealthComponent->mPrev != p_mpHealthComponent || this->mpHealthComponent.mNext != &this->mpHealthComponent) )
  {
    v28 = p_mpHealthComponent->mPrev;
    v29 = this->mpHealthComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    goto LABEL_37;
  }
LABEL_38:
  this->mpHealthComponent.m_Changed = 1;
  this->mpHealthComponent.m_pSimObject = pObject;
  this->mpHealthComponent.m_TypeUID = UFG::HealthComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::BindInternal<UFG::SimObject>(&this->mpHealthComponent, pObject);
  p_mpMoverComponent = &this->mpMoverComponent;
  if ( this->mpMoverComponent.m_pSimComponent )
  {
    v31 = p_mpMoverComponent->mPrev;
    v32 = this->mpMoverComponent.mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    this->mpMoverComponent.m_pSimComponent = 0i64;
LABEL_44:
    this->mpMoverComponent.m_pSimObject = 0i64;
    this->mpMoverComponent.mNext = &this->mpMoverComponent;
    p_mpMoverComponent->mPrev = p_mpMoverComponent;
    goto LABEL_45;
  }
  if ( this->mpMoverComponent.m_pSimObject
    && (p_mpMoverComponent->mPrev != p_mpMoverComponent || this->mpMoverComponent.mNext != &this->mpMoverComponent) )
  {
    v33 = p_mpMoverComponent->mPrev;
    v34 = this->mpMoverComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    goto LABEL_44;
  }
LABEL_45:
  this->mpMoverComponent.m_Changed = 1;
  this->mpMoverComponent.m_pSimObject = pObject;
  this->mpMoverComponent.m_TypeUID = UFG::PhysicsMoverInterface::_TypeUID;
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::BindInternal<UFG::SimObject>(
    &this->mpMoverComponent,
    pObject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->mpTransformNodeComponent,
    pObject);
  p_mpAIEntityComponent = &this->mpAIEntityComponent;
  if ( this->mpAIEntityComponent.m_pSimComponent )
  {
    v36 = p_mpAIEntityComponent->mPrev;
    v37 = this->mpAIEntityComponent.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    this->mpAIEntityComponent.m_pSimComponent = 0i64;
LABEL_51:
    this->mpAIEntityComponent.m_pSimObject = 0i64;
    this->mpAIEntityComponent.mNext = &this->mpAIEntityComponent;
    p_mpAIEntityComponent->mPrev = p_mpAIEntityComponent;
    goto LABEL_52;
  }
  if ( this->mpAIEntityComponent.m_pSimObject
    && (p_mpAIEntityComponent->mPrev != p_mpAIEntityComponent
     || this->mpAIEntityComponent.mNext != &this->mpAIEntityComponent) )
  {
    v38 = p_mpAIEntityComponent->mPrev;
    v39 = this->mpAIEntityComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    goto LABEL_51;
  }
LABEL_52:
  this->mpAIEntityComponent.m_Changed = 1;
  this->mpAIEntityComponent.m_pSimObject = pObject;
  this->mpAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    &this->mpAIEntityComponent,
    pObject);
  p_mpEncounterUnitComponent = &this->mpEncounterUnitComponent;
  if ( this->mpEncounterUnitComponent.m_pSimComponent )
  {
    v41 = p_mpEncounterUnitComponent->mPrev;
    v42 = this->mpEncounterUnitComponent.mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    this->mpEncounterUnitComponent.m_pSimComponent = 0i64;
LABEL_58:
    this->mpEncounterUnitComponent.m_pSimObject = 0i64;
    this->mpEncounterUnitComponent.mNext = &this->mpEncounterUnitComponent;
    p_mpEncounterUnitComponent->mPrev = p_mpEncounterUnitComponent;
    goto LABEL_59;
  }
  if ( this->mpEncounterUnitComponent.m_pSimObject
    && (p_mpEncounterUnitComponent->mPrev != p_mpEncounterUnitComponent
     || this->mpEncounterUnitComponent.mNext != &this->mpEncounterUnitComponent) )
  {
    v43 = p_mpEncounterUnitComponent->mPrev;
    v44 = this->mpEncounterUnitComponent.mNext;
    v43->mNext = v44;
    v44->mPrev = v43;
    goto LABEL_58;
  }
LABEL_59:
  this->mpEncounterUnitComponent.m_Changed = 1;
  this->mpEncounterUnitComponent.m_pSimObject = pObject;
  this->mpEncounterUnitComponent.m_TypeUID = UFG::EncounterUnitComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0>::BindInternal<UFG::SimObject>(
    &this->mpEncounterUnitComponent,
    pObject);
  m_pSimComponent = this->mpTSActorComponent.m_pSimComponent;
  if ( m_pSimComponent
    && ((v46 = (SSActorClass *)m_pSimComponent[1].m_SafePointerList.mNode.mNext,
         UFG::SkookumMgr::mspCharacterClass == v46)
     || (i_superclass_p = v46->i_superclass_p) != 0i64
     && SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspCharacterClass)) )
  {
    this->mUnitType = F5_1Pt2_512;
  }
  else if ( pObject )
  {
    m_Flags = pObject->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          goto LABEL_80;
        if ( (m_Flags & 0x1000) != 0 )
        {
          vfptr = (unsigned int)pObject[1].vfptr;
          size = pObject->m_Components.size;
          if ( vfptr < size )
          {
            v51 = &pObject->m_Components.p[vfptr];
            while ( (v51->m_TypeUID & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                 || (UFG::PhysicsMoverInterface::_TypeUID & ~v51->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              ++v51;
              if ( vfptr >= size )
                goto LABEL_78;
            }
            m_pComponent = v51->m_pComponent;
          }
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(pObject, UFG::PhysicsMoverInterface::_TypeUID);
        }
      }
      else
      {
        m_pComponent = pObject->m_Components.p[34].m_pComponent;
      }
LABEL_78:
      if ( m_pComponent )
        this->mUnitType = 3 - (LODWORD(m_pComponent[12].m_BoundComponentHandles.mNode.mNext) != 0);
    }
  }
LABEL_80:
  UFG::CopUnitComponent::UpdateAliveStatus(this);
}

// File Line: 111
// RVA: 0x540080
void __fastcall UFG::CopUnitComponent::OnDetach(UFG::CopUnitComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TSActorComponent,0> *p_mpTSActorComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::VehicleAudioComponent,0> *p_mpVehicleAudioComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *p_mpVehicleRenderComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *p_mpHealthComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *p_mpMoverComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_mpTransformNodeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_mpAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *p_mpEncounterUnitComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax

  *((_BYTE *)this + 481) &= ~4u;
  UFG::CopUnitComponent::TurnOff(this);
  p_mpTSActorComponent = &this->mpTSActorComponent;
  if ( this->mpTSActorComponent.m_pSimComponent )
  {
    mPrev = p_mpTSActorComponent->mPrev;
    mNext = this->mpTSActorComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mpTSActorComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->mpTSActorComponent.m_pSimObject = 0i64;
    this->mpTSActorComponent.mNext = &this->mpTSActorComponent;
    p_mpTSActorComponent->mPrev = p_mpTSActorComponent;
    goto LABEL_8;
  }
  if ( this->mpTSActorComponent.m_pSimObject
    && (p_mpTSActorComponent->mPrev != p_mpTSActorComponent
     || this->mpTSActorComponent.mNext != &this->mpTSActorComponent) )
  {
    v5 = p_mpTSActorComponent->mPrev;
    v6 = this->mpTSActorComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_mpVehicleAudioComponent = &this->mpVehicleAudioComponent;
  this->mpTSActorComponent.m_Changed = 1;
  if ( this->mpVehicleAudioComponent.m_pSimComponent )
  {
    v8 = p_mpVehicleAudioComponent->mPrev;
    v9 = this->mpVehicleAudioComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->mpVehicleAudioComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mpVehicleAudioComponent.m_pSimObject = 0i64;
    this->mpVehicleAudioComponent.mNext = &this->mpVehicleAudioComponent;
    p_mpVehicleAudioComponent->mPrev = p_mpVehicleAudioComponent;
    goto LABEL_15;
  }
  if ( this->mpVehicleAudioComponent.m_pSimObject
    && (p_mpVehicleAudioComponent->mPrev != p_mpVehicleAudioComponent
     || this->mpVehicleAudioComponent.mNext != &this->mpVehicleAudioComponent) )
  {
    v10 = p_mpVehicleAudioComponent->mPrev;
    v11 = this->mpVehicleAudioComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->mpVehicleAudioComponent.m_Changed = 1;
  p_mpVehicleRenderComponent = &this->mpVehicleRenderComponent;
  if ( this->mpVehicleRenderComponent.m_pSimComponent )
  {
    v13 = p_mpVehicleRenderComponent->mPrev;
    v14 = this->mpVehicleRenderComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->mpVehicleRenderComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->mpVehicleRenderComponent.m_pSimObject = 0i64;
    this->mpVehicleRenderComponent.mNext = &this->mpVehicleRenderComponent;
    p_mpVehicleRenderComponent->mPrev = p_mpVehicleRenderComponent;
    goto LABEL_22;
  }
  if ( this->mpVehicleRenderComponent.m_pSimObject
    && (p_mpVehicleRenderComponent->mPrev != p_mpVehicleRenderComponent
     || this->mpVehicleRenderComponent.mNext != &this->mpVehicleRenderComponent) )
  {
    v15 = p_mpVehicleRenderComponent->mPrev;
    v16 = this->mpVehicleRenderComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->mpVehicleRenderComponent.m_Changed = 1;
  p_mpHealthComponent = &this->mpHealthComponent;
  if ( this->mpHealthComponent.m_pSimComponent )
  {
    v18 = p_mpHealthComponent->mPrev;
    v19 = this->mpHealthComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->mpHealthComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->mpHealthComponent.m_pSimObject = 0i64;
    this->mpHealthComponent.mNext = &this->mpHealthComponent;
    p_mpHealthComponent->mPrev = p_mpHealthComponent;
    goto LABEL_29;
  }
  if ( this->mpHealthComponent.m_pSimObject
    && (p_mpHealthComponent->mPrev != p_mpHealthComponent || this->mpHealthComponent.mNext != &this->mpHealthComponent) )
  {
    v20 = p_mpHealthComponent->mPrev;
    v21 = this->mpHealthComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->mpHealthComponent.m_Changed = 1;
  p_mpMoverComponent = &this->mpMoverComponent;
  if ( this->mpMoverComponent.m_pSimComponent )
  {
    v23 = p_mpMoverComponent->mPrev;
    v24 = this->mpMoverComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->mpMoverComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->mpMoverComponent.m_pSimObject = 0i64;
    this->mpMoverComponent.mNext = &this->mpMoverComponent;
    p_mpMoverComponent->mPrev = p_mpMoverComponent;
    goto LABEL_36;
  }
  if ( this->mpMoverComponent.m_pSimObject
    && (p_mpMoverComponent->mPrev != p_mpMoverComponent || this->mpMoverComponent.mNext != &this->mpMoverComponent) )
  {
    v25 = p_mpMoverComponent->mPrev;
    v26 = this->mpMoverComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->mpMoverComponent.m_Changed = 1;
  p_mpTransformNodeComponent = &this->mpTransformNodeComponent;
  if ( this->mpTransformNodeComponent.m_pSimComponent )
  {
    v28 = p_mpTransformNodeComponent->mPrev;
    v29 = this->mpTransformNodeComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    this->mpTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_42:
    this->mpTransformNodeComponent.m_pSimObject = 0i64;
    this->mpTransformNodeComponent.mNext = &this->mpTransformNodeComponent;
    p_mpTransformNodeComponent->mPrev = p_mpTransformNodeComponent;
    goto LABEL_43;
  }
  if ( this->mpTransformNodeComponent.m_pSimObject
    && (p_mpTransformNodeComponent->mPrev != p_mpTransformNodeComponent
     || this->mpTransformNodeComponent.mNext != &this->mpTransformNodeComponent) )
  {
    v30 = p_mpTransformNodeComponent->mPrev;
    v31 = this->mpTransformNodeComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  this->mpTransformNodeComponent.m_Changed = 1;
  p_mpAIEntityComponent = &this->mpAIEntityComponent;
  if ( this->mpAIEntityComponent.m_pSimComponent )
  {
    v33 = p_mpAIEntityComponent->mPrev;
    v34 = this->mpAIEntityComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    this->mpAIEntityComponent.m_pSimComponent = 0i64;
LABEL_49:
    this->mpAIEntityComponent.m_pSimObject = 0i64;
    this->mpAIEntityComponent.mNext = &this->mpAIEntityComponent;
    p_mpAIEntityComponent->mPrev = p_mpAIEntityComponent;
    goto LABEL_50;
  }
  if ( this->mpAIEntityComponent.m_pSimObject
    && (p_mpAIEntityComponent->mPrev != p_mpAIEntityComponent
     || this->mpAIEntityComponent.mNext != &this->mpAIEntityComponent) )
  {
    v35 = p_mpAIEntityComponent->mPrev;
    v36 = this->mpAIEntityComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  this->mpAIEntityComponent.m_Changed = 1;
  p_mpEncounterUnitComponent = &this->mpEncounterUnitComponent;
  if ( this->mpEncounterUnitComponent.m_pSimComponent )
  {
    v38 = p_mpEncounterUnitComponent->mPrev;
    v39 = this->mpEncounterUnitComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    this->mpEncounterUnitComponent.m_pSimComponent = 0i64;
LABEL_56:
    this->mpEncounterUnitComponent.m_pSimObject = 0i64;
    this->mpEncounterUnitComponent.mNext = &this->mpEncounterUnitComponent;
    p_mpEncounterUnitComponent->mPrev = p_mpEncounterUnitComponent;
    goto LABEL_57;
  }
  if ( this->mpEncounterUnitComponent.m_pSimObject
    && (p_mpEncounterUnitComponent->mPrev != p_mpEncounterUnitComponent
     || this->mpEncounterUnitComponent.mNext != &this->mpEncounterUnitComponent) )
  {
    v40 = p_mpEncounterUnitComponent->mPrev;
    v41 = this->mpEncounterUnitComponent.mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
    goto LABEL_56;
  }
LABEL_57:
  this->mpEncounterUnitComponent.m_Changed = 1;
  *((_BYTE *)this + 480) &= ~8u;
}

// File Line: 129
// RVA: 0x5571E0
void __fastcall UFG::CopUnitComponent::TurnOn(UFG::CopUnitComponent *this)
{
  UFG::CopSystem *v2; // rax
  char v3; // r15
  bool v4; // r14
  char v5; // dl
  UFG::SimComponent *v6; // rsi
  UFG::TSActorComponent *m_pSimComponent; // rcx
  SSActorClass *i_class_p; // rcx
  SSClass *i_superclass_p; // rcx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  unsigned int v13; // r8d
  unsigned int v14; // r9d
  __int64 v15; // rdx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  unsigned int v18; // r8d
  unsigned int v19; // r9d
  UFG::CopSystem *v20; // rax
  char v21; // al
  UFG::SimObject *v22; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v24; // dx
  unsigned int v25; // r8d
  unsigned int v26; // r9d
  __int64 v27; // rdx
  unsigned int v28; // r8d
  unsigned int v29; // r9d
  unsigned int v30; // r8d
  unsigned int v31; // r9d
  char v32; // di
  UFG::CopSystem *v33; // rax
  char v34; // al
  char v35; // bp
  char v36; // dl
  const char *v37; // rdx
  UFG::SimObject *v38; // rcx
  __int16 v39; // dx
  unsigned int v40; // r8d
  unsigned int v41; // r9d
  __int64 v42; // rdx
  unsigned int v43; // r8d
  unsigned int v44; // r9d
  unsigned int v45; // r8d
  unsigned int v46; // r9d
  unsigned int v47; // r8d
  unsigned int v48; // r9d
  UFG::BasePhysicsSystem *v49; // rcx
  UFG::SimObject *v50; // rax
  UFG::qBaseTreeRB *CollisionModel; // rdi
  UFG::CopSystem *v52; // rax
  float v53; // xmm0_4
  UFG::CopSystem *v54; // rax
  float v55; // xmm0_4
  UFG::SimComponent *v56; // rcx
  UFG::VehicleEffectsComponent *v57; // rcx
  UFG::qColour color; // [rsp+30h] [rbp-28h] BYREF

  v2 = UFG::CopSystem::Instance();
  v3 = ((unsigned int (__fastcall *)(UFG::CopSystem *))v2->vfptr[89].__vecDelDtor)(v2) == 0;
  v4 = *((_BYTE *)this + 480) >> 7 != v3;
  v5 = (v3 << 7) | *((_BYTE *)this + 480) & 0x7F;
  v6 = 0i64;
  *((_BYTE *)this + 480) = v5;
  if ( (v5 & 0x20) == 0 )
  {
    m_pSimComponent = (UFG::TSActorComponent *)this->mpTSActorComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      i_class_p = (SSActorClass *)UFG::TSActorComponent::GetActor(m_pSimComponent)->i_class_p;
      if ( UFG::SkookumMgr::mspCharacterClass == i_class_p
        || (i_superclass_p = i_class_p->i_superclass_p) != 0i64
        && SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspCharacterClass) )
      {
        m_pSimObject = this->m_pSimObject;
        if ( !m_pSimObject )
        {
LABEL_7:
          m_pComponent = 0i64;
LABEL_33:
          *((_BYTE *)this + 480) &= ~0x40u;
          *((_BYTE *)this + 480) |= (m_pComponent != 0i64) << 6;
          v20 = UFG::CopSystem::Instance();
          v21 = ((__int64 (__fastcall *)(UFG::CopSystem *))v20->vfptr[16].__vecDelDtor)(v20);
          *((_BYTE *)this + 481) &= ~1u;
          *((_BYTE *)this + 481) |= v21 == 0;
          *((_BYTE *)this + 480) |= 0x20u;
          goto LABEL_34;
        }
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[44].m_pComponent;
          goto LABEL_33;
        }
        if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            vfptr = (unsigned int)m_pSimObject[1].vfptr;
            size = m_pSimObject->m_Components.size;
            if ( vfptr >= size )
              goto LABEL_7;
            v15 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                 || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v15 += 16i64;
              if ( vfptr >= size )
              {
                m_pComponent = 0i64;
                goto LABEL_33;
              }
            }
          }
          else
          {
            if ( (m_Flags & 0x1000) == 0 )
            {
              m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
              goto LABEL_33;
            }
            v18 = (unsigned int)m_pSimObject[1].vfptr;
            v19 = m_pSimObject->m_Components.size;
            if ( v18 >= v19 )
              goto LABEL_7;
            v15 = (__int64)&m_pSimObject->m_Components.p[v18];
            while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
                 || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v18;
              v15 += 16i64;
              if ( v18 >= v19 )
              {
                m_pComponent = 0i64;
                goto LABEL_33;
              }
            }
          }
        }
        else
        {
          v13 = (unsigned int)m_pSimObject[1].vfptr;
          v14 = m_pSimObject->m_Components.size;
          if ( v13 >= v14 )
            goto LABEL_7;
          v15 = (__int64)&m_pSimObject->m_Components.p[v13];
          while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v13;
            v15 += 16i64;
            if ( v13 >= v14 )
            {
              m_pComponent = 0i64;
              goto LABEL_33;
            }
          }
        }
        m_pComponent = *(UFG::SimComponent **)v15;
        goto LABEL_33;
      }
    }
  }
LABEL_34:
  if ( (*((_BYTE *)this + 480) & 0x20) == 0 || !this->mpTSActorComponent.m_pSimComponent )
    goto LABEL_117;
  v22 = this->m_pSimObject;
  if ( !v22 )
    goto LABEL_37;
  v24 = v22->m_Flags;
  if ( (v24 & 0x4000) != 0 )
  {
    ComponentOfType = v22->m_Components.p[44].m_pComponent;
    goto LABEL_63;
  }
  if ( v24 < 0 )
  {
    v25 = (unsigned int)v22[1].vfptr;
    v26 = v22->m_Components.size;
    if ( v25 < v26 )
    {
      v27 = (__int64)&v22->m_Components.p[v25];
      while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v25;
        v27 += 16i64;
        if ( v25 >= v26 )
        {
          ComponentOfType = 0i64;
          goto LABEL_63;
        }
      }
LABEL_47:
      ComponentOfType = *(UFG::SimComponent **)v27;
      goto LABEL_63;
    }
    goto LABEL_37;
  }
  if ( (v24 & 0x2000) != 0 )
  {
    v28 = (unsigned int)v22[1].vfptr;
    v29 = v22->m_Components.size;
    if ( v28 < v29 )
    {
      v27 = (__int64)&v22->m_Components.p[v28];
      while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v28;
        v27 += 16i64;
        if ( v28 >= v29 )
        {
          ComponentOfType = 0i64;
          goto LABEL_63;
        }
      }
      goto LABEL_47;
    }
LABEL_37:
    ComponentOfType = 0i64;
    goto LABEL_63;
  }
  if ( (v24 & 0x1000) != 0 )
  {
    v30 = (unsigned int)v22[1].vfptr;
    v31 = v22->m_Components.size;
    if ( v30 < v31 )
    {
      v27 = (__int64)&v22->m_Components.p[v30];
      while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v30;
        v27 += 16i64;
        if ( v30 >= v31 )
        {
          ComponentOfType = 0i64;
          goto LABEL_63;
        }
      }
      goto LABEL_47;
    }
    goto LABEL_37;
  }
  ComponentOfType = UFG::SimObject::GetComponentOfType(v22, UFG::CharacterOccupantComponent::_TypeUID);
LABEL_63:
  v32 = ComponentOfType == 0i64;
  v33 = UFG::CopSystem::Instance();
  v34 = ((__int64 (__fastcall *)(UFG::CopSystem *))v33->vfptr[16].__vecDelDtor)(v33);
  v35 = v34;
  v36 = (*((_BYTE *)this + 480) & 0x40) != 0;
  if ( v32 != v36 )
  {
    if ( !v4 )
      goto LABEL_68;
LABEL_69:
    UFG::SimObjectUtility::DetachHudSymbol(this->m_pSimObject);
    if ( v3 )
    {
      if ( v32 )
        v37 = "cop_foot_patrol_symbol";
      else
        v37 = "cop_vehicle_patrol_symbol";
    }
    else
    {
      v37 = "cop_foot_symbol";
      if ( !v32 )
        v37 = "cop_symbol";
    }
    UFG::SimObjectUtility::AttachHudSymbol(this->m_pSimObject, v37, 0, 0.0, &customCaption);
    goto LABEL_76;
  }
  if ( v4 )
    goto LABEL_69;
  if ( v34 == (*((_BYTE *)this + 481) & 1) )
    goto LABEL_77;
LABEL_68:
  if ( v32 != v36 )
    goto LABEL_69;
LABEL_76:
  *((_BYTE *)this + 480) &= ~0x40u;
  *((_BYTE *)this + 481) &= ~1u;
  *((_BYTE *)this + 480) |= (v32 & 1) << 6;
  *((_BYTE *)this + 481) |= v35 & 1;
LABEL_77:
  v38 = this->m_pSimObject;
  if ( !v38 )
    goto LABEL_117;
  v39 = v38->m_Flags;
  if ( (v39 & 0x4000) != 0 )
  {
    v40 = (unsigned int)v38[1].vfptr;
    v41 = v38->m_Components.size;
    if ( v40 < v41 )
    {
      v42 = (__int64)&v38->m_Components.p[v40];
      while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || (UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v40;
        v42 += 16i64;
        if ( v40 >= v41 )
          goto LABEL_108;
      }
LABEL_85:
      v6 = *(UFG::SimComponent **)v42;
    }
  }
  else
  {
    if ( v39 < 0 )
    {
      v43 = (unsigned int)v38[1].vfptr;
      v44 = v38->m_Components.size;
      if ( v43 >= v44 )
        goto LABEL_108;
      v42 = (__int64)&v38->m_Components.p[v43];
      while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || (UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v43;
        v42 += 16i64;
        if ( v43 >= v44 )
          goto LABEL_108;
      }
      goto LABEL_85;
    }
    if ( (v39 & 0x2000) != 0 )
    {
      v45 = (unsigned int)v38[1].vfptr;
      v46 = v38->m_Components.size;
      if ( v45 >= v46 )
        goto LABEL_108;
      v42 = (__int64)&v38->m_Components.p[v45];
      while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || (UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v45;
        v42 += 16i64;
        if ( v45 >= v46 )
          goto LABEL_108;
      }
      goto LABEL_85;
    }
    if ( (v39 & 0x1000) == 0 )
    {
      v6 = UFG::SimObject::GetComponentOfType(v38, UFG::HudComponent::_TypeUID);
      goto LABEL_108;
    }
    v47 = (unsigned int)v38[1].vfptr;
    v48 = v38->m_Components.size;
    if ( v47 < v48 )
    {
      v42 = (__int64)&v38->m_Components.p[v47];
      while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || (UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v47;
        v42 += 16i64;
        if ( v47 >= v48 )
          goto LABEL_108;
      }
      goto LABEL_85;
    }
  }
LABEL_108:
  if ( v6 )
  {
    v49 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
    if ( UFG::UIHKScreenHud::mIconManager )
    {
      if ( !LODWORD(v6[4].m_SafePointerList.mNode.mNext) )
      {
        v50 = v6->m_pSimObject;
        if ( v50 )
          LODWORD(v6[4].m_SafePointerList.mNode.mNext) = v50->m_Name.mUID;
      }
      CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(v49, (unsigned int)v6[4].m_SafePointerList.mNode.mNext);
      if ( CollisionModel )
      {
        if ( *((char *)this + 480) >= 0 )
        {
          v54 = UFG::CopSystem::Instance();
          v55 = ((float (__fastcall *)(UFG::CopSystem *, bool, UFG::SimComponent *))v54->vfptr[17].__vecDelDtor)(
                  v54,
                  (*((_BYTE *)this + 480) & 0x40) != 0,
                  this->mpEncounterUnitComponent.m_pSimComponent);
          UFG::UIMapBlip::SetRange((UFG::UIMapBlip *)CollisionModel, 1, v55);
        }
        else
        {
          v52 = UFG::CopSystem::Instance();
          v53 = ((float (__fastcall *)(UFG::CopSystem *, bool, UFG::SimComponent *))v52->vfptr[17].__vecDelDtor)(
                  v52,
                  (*((_BYTE *)this + 480) & 0x40) != 0,
                  this->mpEncounterUnitComponent.m_pSimComponent);
          color.b = 1.0;
          color.r = FLOAT_0_12;
          color.g = FLOAT_0_57999998;
          color.a = FLOAT_0_25;
          UFG::UIMapBlip::SetRange((UFG::UIMapBlip *)CollisionModel, 1, v53, &color, 1.0);
        }
      }
    }
  }
LABEL_117:
  if ( *((char *)this + 480) >= 0 )
  {
    if ( (*((_BYTE *)this + 481) & 2) == 0 )
    {
      v56 = this->mpVehicleAudioComponent.m_pSimComponent;
      if ( v56 )
      {
        if ( (BYTE4(v56[9].m_BoundComponentHandles.mNode.mNext) & 1) != 0 )
        {
          UFG::VehicleAudioComponent::StartSiren((UFG::VehicleAudioComponent *)v56, 1);
          *((_BYTE *)this + 481) |= 2u;
        }
      }
    }
    v57 = (UFG::VehicleEffectsComponent *)this->mpVehicleRenderComponent.m_pSimComponent;
    if ( v57 )
      UFG::VehicleEffectsComponent::TurnOnCopLights(v57);
  }
}

// File Line: 243
// RVA: 0x54E620
void __fastcall UFG::CopUnitComponent::SetScriptedLightsOn(UFG::CopUnitComponent *this, bool bEnabled)
{
  UFG::VehicleEffectsComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::VehicleEffectsComponent *)this->mpVehicleRenderComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( bEnabled )
      UFG::VehicleEffectsComponent::TurnOnCopLights(m_pSimComponent);
    else
      UFG::VehicleEffectsComponent::TurnOffCopLights(m_pSimComponent);
    *((_BYTE *)this + 0x1E1) &= ~4u;
    *((_BYTE *)this + 0x1E1) |= 4 * bEnabled;
  }
}

// File Line: 263
// RVA: 0x557160
void __fastcall UFG::CopUnitComponent::TurnOff(UFG::CopUnitComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::VehicleEffectsComponent *v3; // rcx

  if ( (*((_BYTE *)this + 480) & 0x20) != 0 && this->mpTSActorComponent.m_pSimComponent )
  {
    UFG::SimObjectUtility::DetachHudSymbol(this->m_pSimObject);
    *((_BYTE *)this + 480) &= ~0x20u;
  }
  if ( (*((_BYTE *)this + 481) & 2) != 0 )
  {
    m_pSimComponent = this->mpVehicleAudioComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      if ( (BYTE4(m_pSimComponent[9].m_BoundComponentHandles.mNode.mNext) & 1) != 0 )
      {
        UFG::VehicleAudioComponent::StopSiren((UFG::VehicleAudioComponent *)m_pSimComponent, 1);
        *((_BYTE *)this + 481) &= ~2u;
      }
    }
  }
  v3 = (UFG::VehicleEffectsComponent *)this->mpVehicleRenderComponent.m_pSimComponent;
  if ( v3 )
  {
    if ( (*((_BYTE *)this + 481) & 4) == 0 )
      UFG::VehicleEffectsComponent::TurnOffCopLights(v3);
  }
}

// File Line: 302
// RVA: 0x526190
void __fastcall UFG::CopUnitComponent::DisableHandler(UFG::CopUnitComponent *this)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::VehicleEffectsComponent *m_pComponent; // rdi
  UFG::SimComponentHolder *p; // rax
  UFG::VehicleOccupantComponent *v5; // rbp
  unsigned int v6; // edi
  unsigned int NumberOfOccupants; // r14d
  UFG::SimObject *Occupant; // rax
  UFG::SimObject *v9; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  __int64 v14; // rdx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int16 v17; // cx
  UFG::HealthComponent *v18; // rax
  unsigned int v19; // r8d
  unsigned int v20; // r9d
  __int64 v21; // rdx
  unsigned int v22; // r8d
  unsigned int v23; // r9d
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::VehicleEffectsComponent *v25; // rcx

  if ( (unsigned int)(this->mUnitType - 2) <= 1 )
  {
    *((_BYTE *)this + 481) &= ~4u;
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pComponent = (UFG::VehicleEffectsComponent *)m_pSimObject->m_Components.p[32].m_pComponent;
    else
      m_pComponent = 0i64;
    if ( UFG::VehicleEffectsComponent::AreCopLightsOn(m_pComponent) )
      UFG::VehicleEffectsComponent::TurnOnDisabledEffect(m_pComponent);
    if ( m_pSimObject )
    {
      p = m_pSimObject->m_Components.p;
      v5 = (UFG::VehicleOccupantComponent *)p[30].m_pComponent;
      if ( v5 )
      {
        v6 = 0;
        NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)p[30].m_pComponent);
        if ( NumberOfOccupants )
        {
          while ( 1 )
          {
            Occupant = UFG::VehicleOccupantComponent::GetOccupant(v5, v6, 0i64);
            v9 = Occupant;
            if ( !Occupant )
              goto LABEL_54;
            m_Flags = Occupant->m_Flags;
            if ( (m_Flags & 0x4000) != 0 )
            {
              ComponentOfType = Occupant->m_Components.p[16].m_pComponent;
              goto LABEL_31;
            }
            if ( m_Flags < 0 )
            {
              ComponentOfType = Occupant->m_Components.p[16].m_pComponent;
              goto LABEL_31;
            }
            if ( (m_Flags & 0x2000) != 0 )
              break;
            if ( (m_Flags & 0x1000) != 0 )
            {
              vfptr = (unsigned int)Occupant[1].vfptr;
              size = Occupant->m_Components.size;
              if ( vfptr >= size )
              {
LABEL_21:
                ComponentOfType = 0i64;
                goto LABEL_31;
              }
              v14 = (__int64)&Occupant->m_Components.p[vfptr];
              while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::EncounterUnitComponent::_TypeUID & 0xFE000000)
                   || (UFG::EncounterUnitComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
              {
                ++vfptr;
                v14 += 16i64;
                if ( vfptr >= size )
                {
                  ComponentOfType = 0i64;
                  goto LABEL_31;
                }
              }
              goto LABEL_22;
            }
            ComponentOfType = UFG::SimObject::GetComponentOfType(Occupant, UFG::EncounterUnitComponent::_TypeUID);
LABEL_31:
            if ( ComponentOfType )
            {
              v17 = v9->m_Flags;
              if ( (v17 & 0x4000) != 0 )
              {
                v18 = (UFG::HealthComponent *)v9->m_Components.p[6].m_pComponent;
                goto LABEL_52;
              }
              if ( v17 < 0 )
              {
                v18 = (UFG::HealthComponent *)v9->m_Components.p[6].m_pComponent;
                goto LABEL_52;
              }
              if ( (v17 & 0x2000) != 0 )
              {
                v19 = (unsigned int)v9[1].vfptr;
                v20 = v9->m_Components.size;
                if ( v19 < v20 )
                {
                  v21 = (__int64)&v9->m_Components.p[v19];
                  while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                       || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) != 0 )
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
              else if ( (v17 & 0x1000) != 0 )
              {
                v22 = (unsigned int)v9[1].vfptr;
                v23 = v9->m_Components.size;
                if ( v22 >= v23 )
                  goto LABEL_42;
                v21 = (__int64)&v9->m_Components.p[v22];
                while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
                     || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) != 0 )
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
            if ( ++v6 >= NumberOfOccupants )
              goto LABEL_55;
          }
          v12 = (unsigned int)Occupant[1].vfptr;
          v13 = Occupant->m_Components.size;
          if ( v12 >= v13 )
            goto LABEL_21;
          v14 = (__int64)&Occupant->m_Components.p[v12];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::EncounterUnitComponent::_TypeUID & 0xFE000000)
               || (UFG::EncounterUnitComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v12;
            v14 += 16i64;
            if ( v12 >= v13 )
              goto LABEL_21;
          }
LABEL_22:
          ComponentOfType = *(UFG::SimComponent **)v14;
          goto LABEL_31;
        }
      }
    }
  }
LABEL_55:
  if ( (*((_BYTE *)this + 480) & 0x20) != 0 && this->mpTSActorComponent.m_pSimComponent )
  {
    UFG::SimObjectUtility::DetachHudSymbol(this->m_pSimObject);
    *((_BYTE *)this + 480) &= ~0x20u;
  }
  if ( (*((_BYTE *)this + 481) & 2) != 0 )
  {
    m_pSimComponent = this->mpVehicleAudioComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      if ( (BYTE4(m_pSimComponent[9].m_BoundComponentHandles.mNode.mNext) & 1) != 0 )
      {
        UFG::VehicleAudioComponent::StopSiren((UFG::VehicleAudioComponent *)m_pSimComponent, 1);
        *((_BYTE *)this + 481) &= ~2u;
      }
    }
  }
  v25 = (UFG::VehicleEffectsComponent *)this->mpVehicleRenderComponent.m_pSimComponent;
  if ( v25 )
  {
    if ( (*((_BYTE *)this + 481) & 4) == 0 )
      UFG::VehicleEffectsComponent::TurnOffCopLights(v25);
  }
}

// File Line: 348
// RVA: 0x55DF30
void __fastcall UFG::CopUnitComponent::UpdateAliveStatus(UFG::CopUnitComponent *this)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx
  UFG::SimComponent *v3; // rax
  char v4; // cl
  bool v5; // dl
  char v6; // dl
  UFG::SimComponent *v7; // rax

  *((_BYTE *)this + 480) &= ~8u;
  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mpMoverComponent.m_pSimComponent;
  if ( !m_pSimComponent || UFG::PhysicsMoverInterface::GetEngineDamage(m_pSimComponent) < 1.0 )
  {
    v3 = this->mpHealthComponent.m_pSimComponent;
    v4 = 1;
    v5 = v3 && !BYTE4(v3[1].m_BoundComponentHandles.mNode.mPrev);
    v6 = *((_BYTE *)this + 480) ^ (*((_BYTE *)this + 480) ^ (*((_BYTE *)this + 480) | (8 * v5))) & 8;
    v7 = this->mpEncounterUnitComponent.m_pSimComponent;
    *((_BYTE *)this + 480) = v6;
    if ( !v7 || HIBYTE(v7[2].m_SafePointerList.mNode.mPrev) )
      v4 = 0;
    *((_BYTE *)this + 480) = v6 ^ (v6 ^ (v6 | (8 * v4))) & 8;
  }
}

// File Line: 361
// RVA: 0x5635C0
void __fastcall UFG::CopUnitComponent::UpdateVisibleStatus(UFG::CopUnitComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rdi
  bool v3; // al

  m_pSimComponent = this->mpTransformNodeComponent.m_pSimComponent;
  v3 = 0;
  if ( m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpTransformNodeComponent.m_pSimComponent);
    if ( UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&m_pSimComponent[2].m_BoundComponentHandles, 2.0, 0) )
      v3 = 1;
  }
  *((_BYTE *)this + 480) &= ~0x10u;
  *((_BYTE *)this + 480) |= 16 * v3;
}

// File Line: 368
// RVA: 0x55AAD0
void __fastcall UFG::CopUnitComponent::Update(UFG::CopUnitComponent *this, float deltaTime)
{
  __int64 v2; // rbx
  UFG::StreamedResourceComponent *v3; // rdi
  __int16 v5; // dx
  UFG::SimComponent *ComponentOfType; // rcx
  unsigned int v7; // edx
  unsigned int m_TypeUID; // edx
  unsigned int v9; // r8d
  unsigned int v10; // r9d
  __int64 v11; // rdx
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  __int64 v14; // rax
  char m_Changed; // al
  UFG::CopUnitComponent *v16; // rcx
  char v17; // al
  float v18; // xmm6_4
  UFG::CopSystem *v19; // rax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::TransformNodeComponent *v21; // rbx
  float x; // xmm6_4
  float y; // xmm8_4
  float z; // xmm7_4
  UFG::TransformNodeComponent *mNext; // rbx
  __int16 v26; // cx
  unsigned int v27; // r8d
  unsigned int v28; // r9d
  __int64 v29; // rdx

  v2 = *(_QWORD *)&this[-1].mpEncounterUnitComponent.m_Changed;
  v3 = 0i64;
  if ( !v2 )
    goto LABEL_29;
  v5 = *(_WORD *)(v2 + 76);
  if ( (v5 & 0x4000) == 0 )
  {
    if ( v5 < 0 )
    {
      ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v2 + 104) + 368i64);
      if ( !ComponentOfType )
        goto LABEL_6;
      m_TypeUID = ComponentOfType->m_TypeUID;
      if ( ((m_TypeUID ^ UFG::HumanDriverComponent::_TypeUID) & 0xFE000000) != 0 )
        goto LABEL_6;
      if ( (UFG::HumanDriverComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
        ComponentOfType = 0i64;
      goto LABEL_28;
    }
    if ( (v5 & 0x2000) != 0 )
    {
      v9 = *(_DWORD *)(v2 + 128);
      v10 = *(_DWORD *)(v2 + 96);
      if ( v9 < v10 )
      {
        v11 = *(_QWORD *)(v2 + 104) + 16i64 * v9;
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::HumanDriverComponent::_TypeUID & 0xFE000000)
             || (UFG::HumanDriverComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v9;
          v11 += 16i64;
          if ( v9 >= v10 )
          {
            ComponentOfType = 0i64;
            goto LABEL_28;
          }
        }
LABEL_19:
        ComponentOfType = *(UFG::SimComponent **)v11;
        goto LABEL_28;
      }
    }
    else
    {
      if ( (v5 & 0x1000) == 0 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            *(UFG::SimObject **)&this[-1].mpEncounterUnitComponent.m_Changed,
                            UFG::HumanDriverComponent::_TypeUID);
        goto LABEL_28;
      }
      v12 = *(_DWORD *)(v2 + 128);
      v13 = *(_DWORD *)(v2 + 96);
      if ( v12 < v13 )
      {
        v11 = *(_QWORD *)(v2 + 104) + 16i64 * v12;
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::HumanDriverComponent::_TypeUID & 0xFE000000)
             || (UFG::HumanDriverComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v12;
          v11 += 16i64;
          if ( v12 >= v13 )
          {
            ComponentOfType = 0i64;
            goto LABEL_28;
          }
        }
        goto LABEL_19;
      }
    }
LABEL_6:
    ComponentOfType = 0i64;
    goto LABEL_28;
  }
  ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v2 + 104) + 368i64);
  if ( !ComponentOfType )
    goto LABEL_6;
  v7 = ComponentOfType->m_TypeUID;
  if ( ((v7 ^ UFG::HumanDriverComponent::_TypeUID) & 0xFE000000) != 0
    || (UFG::HumanDriverComponent::_TypeUID & ~v7 & 0x1FFFFFF) != 0 )
  {
    goto LABEL_6;
  }
LABEL_28:
  if ( ComponentOfType )
    return;
LABEL_29:
  UFG::CopUnitComponent::UpdateAliveStatus((UFG::CopUnitComponent *)((char *)this - 64));
  UFG::CopUnitComponent::UpdateVisibleStatus((UFG::CopUnitComponent *)((char *)this - 64));
  v14 = *(_QWORD *)&this[-1].mpEncounterUnitComponent.m_Changed;
  if ( v14 && (*(_WORD *)(v14 + 76) & 0x400) != 0 )
    return;
  m_Changed = this->mpAIEntityComponent.m_Changed;
  if ( (m_Changed & 4) != 0 || (m_Changed & 1) == 0 )
  {
    v16 = (UFG::CopUnitComponent *)((char *)this - 64);
    goto LABEL_36;
  }
  v16 = (UFG::CopUnitComponent *)((char *)this - 64);
  if ( (m_Changed & 8) == 0 )
  {
LABEL_36:
    UFG::CopUnitComponent::TurnOff(v16);
    goto LABEL_37;
  }
  UFG::CopUnitComponent::TurnOn(v16);
LABEL_37:
  v17 = this->mpAIEntityComponent.m_Changed;
  if ( (v17 & 4) == 0 )
  {
LABEL_50:
    LODWORD(this->mpAIEntityComponent.m_pSimObject) = 0;
    return;
  }
  if ( (v17 & 0x10) != 0 )
    v18 = 0.0;
  else
    v18 = deltaTime + *(float *)&this->mpAIEntityComponent.m_pSimObject;
  *(float *)&this->mpAIEntityComponent.m_pSimObject = v18;
  if ( v18 > 15.0 )
  {
    if ( v2 )
    {
      v26 = *(_WORD *)(v2 + 76);
      if ( (v26 & 0x4000) != 0 )
      {
        v3 = *(UFG::StreamedResourceComponent **)(*(_QWORD *)(v2 + 104) + 160i64);
      }
      else if ( v26 >= 0 )
      {
        if ( (v26 & 0x2000) != 0 )
        {
          v3 = *(UFG::StreamedResourceComponent **)(*(_QWORD *)(v2 + 104) + 112i64);
        }
        else if ( (v26 & 0x1000) != 0 )
        {
          v27 = *(_DWORD *)(v2 + 128);
          v28 = *(_DWORD *)(v2 + 96);
          if ( v27 < v28 )
          {
            v29 = *(_QWORD *)(v2 + 104) + 16i64 * v27;
            while ( (*(_DWORD *)(v29 + 8) & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
                 || (UFG::StreamedResourceComponent::_TypeUID & ~*(_DWORD *)(v29 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v27;
              v29 += 16i64;
              if ( v27 >= v28 )
                goto LABEL_68;
            }
            v3 = *(UFG::StreamedResourceComponent **)v29;
          }
        }
        else
        {
          v3 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)v2,
                                                   UFG::StreamedResourceComponent::_TypeUID);
        }
      }
      else
      {
        v3 = *(UFG::StreamedResourceComponent **)(*(_QWORD *)(v2 + 104) + 160i64);
      }
    }
LABEL_68:
    if ( UFG::StreamedResourceComponent::GetSpawnPriority(v3, 0i64)->mUID != qSymbol_Critical.mUID )
      UFG::Simulation::QueueSimObjectToBeDestroyed(
        &UFG::gSim,
        *(UFG::SimObject **)&this[-1].mpEncounterUnitComponent.m_Changed);
  }
  else if ( v18 > 5.0 )
  {
    if ( this->mpMoverComponent.mNext )
    {
      v19 = UFG::CopSystem::Instance();
      if ( !((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v19->vfptr[12].__vecDelDtor)(v19)
        || !this->mpHealthComponent.mNext )
      {
        LocalPlayer = UFG::GetLocalPlayer();
        v21 = LocalPlayer ? (UFG::TransformNodeComponent *)LocalPlayer->m_Components.p[2].m_pComponent : 0i64;
        UFG::TransformNodeComponent::UpdateWorldTransform(v21);
        x = v21->mWorldTransform.v3.x;
        y = v21->mWorldTransform.v3.y;
        z = v21->mWorldTransform.v3.z;
        mNext = (UFG::TransformNodeComponent *)this->mpMoverComponent.mNext;
        UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
        if ( (float)((float)((float)((float)(y - mNext->mWorldTransform.v3.y) * (float)(y - mNext->mWorldTransform.v3.y))
                           + (float)((float)(x - mNext->mWorldTransform.v3.x) * (float)(x - mNext->mWorldTransform.v3.x)))
                   + (float)((float)(z - mNext->mWorldTransform.v3.z) * (float)(z - mNext->mWorldTransform.v3.z))) < 2500.0 )
          goto LABEL_50;
      }
    }
  }
}

// File Line: 451
// RVA: 0x5355E0
bool __fastcall UFG::CopUnitComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentCopUnit,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 457
// RVA: 0x544E60
UFG::CopUnitComponent *__fastcall UFG::CopUnitComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x1E8ui64, "CopUnitComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::CopUnitComponent::CopUnitComponent((UFG::CopUnitComponent *)v3, pSceneObj->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v8 = 17;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v5, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return (UFG::CopUnitComponent *)v5;
}

