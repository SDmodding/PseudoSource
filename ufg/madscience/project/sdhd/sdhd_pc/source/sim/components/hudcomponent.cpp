// File Line: 21
// RVA: 0x1543EE0
__int64 dynamic_initializer_for__UFG::HudComponent::s_HudComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HudComponent::s_HudComponentList__);
}

// File Line: 22
// RVA: 0x52CA40
UFG::ComponentIDDesc *__fastcall UFG::HudComponent::GetDesc(UFG::HudComponent *this)
{
  return &UFG::HudComponent::_TypeIDesc;
}

// File Line: 36
// RVA: 0x517DD0
void __fastcall UFG::HudComponent::HudComponent(
        UFG::HudComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *mPrev; // rax
  char *v8; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  this->mNext = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HudComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HudComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mRootTransformComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&this->mHealthComponent);
  UFG::qString::qString(&this->mSymbolName);
  *(_WORD *)&this->mIsKnockedOut = 0;
  this->mUseCustomFilterDistance = 0;
  this->mCustomFilterDistance = 0.0;
  UFG::qString::qString(&this->mCustomWorldMapCaption);
  this->mBlipGuid = 0;
  mPrev = UFG::HudComponent::s_HudComponentList.mNode.mPrev;
  UFG::HudComponent::s_HudComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&UFG::HudComponent::s_HudComponentList;
  UFG::HudComponent::s_HudComponentList.mNode.mPrev = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  UFG::SimComponent::AddType(this, UFG::HudComponent::_HudComponentTypeUID, "HudComponent");
  if ( properties )
  {
    v8 = UFG::qPropertySet::Get<char const *>(
           properties,
           (UFG::qArray<unsigned long,0> *)&SimSym_HudSymbolName,
           DEPTH_RECURSE);
    UFG::qString::Set(&this->mSymbolName, v8);
  }
  if ( startSuspended )
    this->m_Flags |= 2u;
}

// File Line: 55
// RVA: 0x517CB0
void __fastcall UFG::HudComponent::HudComponent(
        UFG::HudComponent *this,
        unsigned int name_uid,
        const char *symbolName,
        bool useCustomFilterDistance,
        float customFilterDistance,
        const char *customWorldMapCaption)
{
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  this->mNext = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HudComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HudComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mRootTransformComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&this->mHealthComponent);
  UFG::qString::qString(&this->mSymbolName);
  UFG::qString::qString(&this->mCustomWorldMapCaption);
  mPrev = UFG::HudComponent::s_HudComponentList.mNode.mPrev;
  UFG::HudComponent::s_HudComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&UFG::HudComponent::s_HudComponentList;
  UFG::HudComponent::s_HudComponentList.mNode.mPrev = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  UFG::SimComponent::AddType(this, UFG::HudComponent::_HudComponentTypeUID, "HudComponent");
  UFG::qString::Set(&this->mSymbolName, symbolName);
  this->mUseCustomFilterDistance = useCustomFilterDistance;
  this->mCustomFilterDistance = customFilterDistance;
  UFG::qString::Set(&this->mCustomWorldMapCaption, customWorldMapCaption);
  *(_WORD *)&this->mIsKnockedOut = 0;
}

// File Line: 73
// RVA: 0x51BB90
void __fastcall UFG::HudComponent::~HudComponent(UFG::HudComponent *this)
{
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v2; // rbx
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *mPrev; // rcx
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *mNext; // rax
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v5; // rcx
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v6; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HudComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HudComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::HudComponent::s_HudComponentpCurrentIterator )
    UFG::HudComponent::s_HudComponentpCurrentIterator = (UFG::HudComponent *)&this->mPrev[-5].mNext;
  v2 = &this->UFG::qNode<UFG::HudComponent,UFG::HudComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&this->mCustomWorldMapCaption);
  UFG::qString::~qString(&this->mSymbolName);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mRootTransformComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 86
// RVA: 0x5356E0
bool __fastcall UFG::HudComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentHud,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 92
// RVA: 0x5450A0
UFG::HudComponent *__fastcall UFG::HudComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x118ui64, "HudComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = sceneObject->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = sceneObject->mpConstProperties;
    UFG::HudComponent::HudComponent((UFG::HudComponent *)v3, sceneObject->m_NameUID, mpWritableProperties, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, sceneObject->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return (UFG::HudComponent *)v6;
}

// File Line: 102
// RVA: 0x53E1E0
void __fastcall UFG::HudComponent::OnAttach(UFG::HudComponent *this, UFG::SimObject *object)
{
  unsigned int mStringHash32; // eax
  UFG::BasePhysicsSystem *v5; // rbp
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *p_mHealthComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::SimObject *m_pSimObject; // rax
  unsigned int mBlipGuid; // esi
  UFG::qBaseTreeRB *CollisionModel; // rdi
  UFG::UIMapBlip *Icon; // rax
  UFG::SimComponent *m_pSimComponent; // rbx

  this->mBlipGuid = 0;
  if ( this->mSymbolName.mStringHash32 == -1 )
    this->mSymbolName.mStringHash32 = UFG::qStringHash32(this->mSymbolName.mData, 0xFFFFFFFF);
  mStringHash32 = this->mSymbolName.mStringHash32;
  this->mIsHostile = mStringHash32 == -2083396313
                  || mStringHash32 == -1617994565
                  || mStringHash32 == -1188642363
                  || mStringHash32 == -590296049;
  v5 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->mRootTransformComponent,
    object);
  p_mHealthComponent = &this->mHealthComponent;
  if ( this->mHealthComponent.m_pSimComponent )
  {
    mPrev = p_mHealthComponent->mPrev;
    mNext = this->mHealthComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mHealthComponent.m_pSimComponent = 0i64;
LABEL_15:
    this->mHealthComponent.m_pSimObject = 0i64;
    this->mHealthComponent.mNext = &this->mHealthComponent;
    p_mHealthComponent->mPrev = p_mHealthComponent;
    goto LABEL_16;
  }
  if ( this->mHealthComponent.m_pSimObject
    && (p_mHealthComponent->mPrev != p_mHealthComponent || this->mHealthComponent.mNext != &this->mHealthComponent) )
  {
    v9 = p_mHealthComponent->mPrev;
    v10 = this->mHealthComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    goto LABEL_15;
  }
LABEL_16:
  this->mHealthComponent.m_Changed = 1;
  this->mHealthComponent.m_pSimObject = object;
  this->mHealthComponent.m_TypeUID = UFG::HealthComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::BindInternal<UFG::SimObject>(&this->mHealthComponent, object);
  if ( !v5 )
    return;
  if ( !this->mBlipGuid )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      this->mBlipGuid = m_pSimObject->m_Name.mUID;
  }
  mBlipGuid = this->mBlipGuid;
  CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(v5, mBlipGuid);
  if ( !CollisionModel )
  {
    Icon = UFG::UIMapBlipManager::CreateIcon((UFG::UIMapBlipManager *)v5, mBlipGuid, this->mSymbolName.mData, 0.0, 0.0);
    CollisionModel = (UFG::qBaseTreeRB *)Icon;
    if ( !Icon )
      return;
    Icon->mUseCustomFilterDistance = this->mUseCustomFilterDistance;
    Icon->mCustomFilterDistance = this->mCustomFilterDistance;
    UFG::UIMapBlip::SetWorldMapCaption(Icon, this->mCustomWorldMapCaption.mData);
  }
  m_pSimComponent = this->mRootTransformComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    UFG::UIMapBlip::SetPosition(
      (UFG::UIMapBlip *)CollisionModel,
      (UFG::qVector3 *)&m_pSimComponent[2].m_BoundComponentHandles);
  }
}

// File Line: 154
// RVA: 0x5407C0
void __fastcall UFG::HudComponent::OnDetach(UFG::HudComponent *this)
{
  UFG::UIMapBlipManager *v2; // rcx
  UFG::SimObject *m_pSimObject; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_mRootTransformComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *p_mHealthComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  v2 = UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    if ( !this->mBlipGuid )
    {
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
        this->mBlipGuid = m_pSimObject->m_Name.mUID;
    }
    UFG::UIMapBlipManager::RemoveIcon(v2, this->mBlipGuid);
  }
  p_mRootTransformComponent = &this->mRootTransformComponent;
  if ( this->mRootTransformComponent.m_pSimComponent )
  {
    mPrev = p_mRootTransformComponent->mPrev;
    mNext = this->mRootTransformComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mRootTransformComponent.m_pSimComponent = 0i64;
LABEL_12:
    this->mRootTransformComponent.m_pSimObject = 0i64;
    this->mRootTransformComponent.mNext = &this->mRootTransformComponent;
    p_mRootTransformComponent->mPrev = p_mRootTransformComponent;
    goto LABEL_13;
  }
  if ( this->mRootTransformComponent.m_pSimObject
    && (p_mRootTransformComponent->mPrev != p_mRootTransformComponent
     || this->mRootTransformComponent.mNext != &this->mRootTransformComponent) )
  {
    v7 = p_mRootTransformComponent->mPrev;
    v8 = this->mRootTransformComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_12;
  }
LABEL_13:
  this->mRootTransformComponent.m_Changed = 1;
  p_mHealthComponent = &this->mHealthComponent;
  if ( this->mHealthComponent.m_pSimComponent )
  {
    v10 = p_mHealthComponent->mPrev;
    v11 = this->mHealthComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->mHealthComponent.m_pSimComponent = 0i64;
LABEL_19:
    this->mHealthComponent.m_pSimObject = 0i64;
    this->mHealthComponent.mNext = &this->mHealthComponent;
    p_mHealthComponent->mPrev = p_mHealthComponent;
    goto LABEL_20;
  }
  if ( this->mHealthComponent.m_pSimObject
    && (p_mHealthComponent->mPrev != p_mHealthComponent || this->mHealthComponent.mNext != &this->mHealthComponent) )
  {
    v12 = p_mHealthComponent->mPrev;
    v13 = this->mHealthComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_19;
  }
LABEL_20:
  this->mHealthComponent.m_Changed = 1;
}

// File Line: 166
// RVA: 0x55BB20
void __fastcall UFG::HudComponent::Update(UFG::HudComponent *this, float delta_sec)
{
  UFG::BasePhysicsSystem *v3; // rcx
  char *mData; // rax
  UFG::qBaseTreeRB *CollisionModel; // rbp
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::ObjectiveTracker *p_mObjectiveTracker; // rax

  v3 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    if ( !LODWORD(this->mSymbolName.mData) )
    {
      mData = this[-1].mCustomWorldMapCaption.mData;
      if ( mData )
        LODWORD(this->mSymbolName.mData) = *((_DWORD *)mData + 18);
    }
    CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(v3, (unsigned int)this->mSymbolName.mData);
    if ( CollisionModel && this[-1].mCustomWorldMapCaption.mData )
    {
      mPrev = this->m_BoundComponentHandles.mNode.UFG::SimComponent::mPrev;
      if ( mPrev )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_BoundComponentHandles.mNode.UFG::SimComponent::mPrev);
        UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)CollisionModel, (UFG::qVector3 *)&mPrev[11]);
      }
      if ( !LOBYTE(this->mHealthComponent.m_pSimComponent) )
      {
        mNext = this->mRootTransformComponent.mNext;
        if ( mNext )
        {
          if ( BYTE4(mNext[7].mPrev) )
          {
            UFG::HudComponent::HideSymbol((UFG::HudComponent *)((char *)this - 64));
            p_mObjectiveTracker = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
            if ( p_mObjectiveTracker )
              UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
                p_mObjectiveTracker,
                (UFG::qSymbol *)this[-1].mCustomWorldMapCaption.mData + 18,
                0);
            LOBYTE(this->mHealthComponent.m_pSimComponent) = 1;
          }
        }
      }
    }
  }
}

// File Line: 218
// RVA: 0x535A70
void __fastcall UFG::HudComponent::HideSymbol(UFG::HudComponent *this)
{
  UFG::BasePhysicsSystem *v1; // r8
  UFG::SimObject *m_pSimObject; // rax
  UFG::qBaseTreeRB *CollisionModel; // rax

  v1 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    if ( !this->mBlipGuid )
    {
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
        this->mBlipGuid = m_pSimObject->m_Name.mUID;
    }
    CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(v1, this->mBlipGuid);
    if ( CollisionModel )
      UFG::UIMapBlip::SetVisible((UFG::UIMapBlip *)CollisionModel, 0);
  }
}

// File Line: 236
// RVA: 0x533930
bool __fastcall UFG::HudComponent::GetWorldPosition(UFG::HudComponent *this, UFG::qVector3 *pos)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  bool result; // al

  m_pSimComponent = this->mRootTransformComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mRootTransformComponent.m_pSimComponent);
  v4 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v5 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
  pos->x = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
  result = 1;
  pos->y = v4;
  pos->z = v5;
  return result;
}

// File Line: 248
// RVA: 0x52AB90
__int64 __fastcall UFG::HudComponent::GetBlipGuid(UFG::HudComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax

  if ( !this->mBlipGuid )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      this->mBlipGuid = m_pSimObject->m_Name.mUID;
  }
  return this->mBlipGuid;
}

// File Line: 262
// RVA: 0x52DF60
UFG::qBaseTreeRB *__fastcall UFG::HudComponent::GetIcon(UFG::HudComponent *this)
{
  UFG::BasePhysicsSystem *v1; // r8
  UFG::SimObject *m_pSimObject; // rax

  v1 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( !UFG::UIHKScreenHud::mIconManager )
    return 0i64;
  if ( !this->mBlipGuid )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      this->mBlipGuid = m_pSimObject->m_Name.mUID;
  }
  return UFG::BasePhysicsSystem::GetCollisionModel(v1, this->mBlipGuid);
}

