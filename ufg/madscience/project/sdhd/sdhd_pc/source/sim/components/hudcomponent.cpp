// File Line: 21
// RVA: 0x1543EE0
__int64 dynamic_initializer_for__UFG::HudComponent::s_HudComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::HudComponent::s_HudComponentList__);
}

// File Line: 22
// RVA: 0x52CA40
UFG::ComponentIDDesc *__fastcall UFG::HudComponent::GetDesc(UFG::HudComponent *this)
{
  return &UFG::HudComponent::_TypeIDesc;
}

// File Line: 36
// RVA: 0x517DD0
void __fastcall UFG::HudComponent::HudComponent(UFG::HudComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  bool v4; // si
  UFG::qPropertySet *v5; // rbp
  UFG::HudComponent *v6; // rdi
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v7; // rbx
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v8; // rax
  char *v9; // rax

  v4 = startSuspended;
  v5 = properties;
  v6 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v7 = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&v6->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HudComponent::`vftable'{for `UFG::SimComponent'};
  v6->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HudComponent::`vftable'{for `UFG::UpdateInterface'};
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v6->mRootTransformComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&v6->mHealthComponent);
  UFG::qString::qString(&v6->mSymbolName);
  *(_WORD *)&v6->mIsKnockedOut = 0;
  v6->mUseCustomFilterDistance = 0;
  v6->mCustomFilterDistance = 0.0;
  UFG::qString::qString(&v6->mCustomWorldMapCaption);
  v6->mBlipGuid = 0;
  v8 = UFG::HudComponent::s_HudComponentList.mNode.mPrev;
  UFG::HudComponent::s_HudComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&v6->mPrev;
  v7->mPrev = v8;
  v6->mNext = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&UFG::HudComponent::s_HudComponentList;
  UFG::HudComponent::s_HudComponentList.mNode.mPrev = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&v6->mPrev;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v6->vfptr, UFG::HudComponent::_HudComponentTypeUID, "HudComponent");
  if ( v5 )
  {
    v9 = UFG::qPropertySet::Get<char const *>(v5, (UFG::qSymbol *)&SimSym_HudSymbolName.mUID, DEPTH_RECURSE);
    UFG::qString::Set(&v6->mSymbolName, v9);
  }
  if ( v4 )
    v6->m_Flags |= 2u;
}

// File Line: 55
// RVA: 0x517CB0
void __fastcall UFG::HudComponent::HudComponent(UFG::HudComponent *this, unsigned int name_uid, const char *symbolName, bool useCustomFilterDistance, float customFilterDistance, const char *customWorldMapCaption)
{
  bool v6; // r14
  const char *v7; // rbp
  UFG::HudComponent *v8; // r15
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v9; // rsi
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v10; // rax

  v6 = useCustomFilterDistance;
  v7 = symbolName;
  v8 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v9 = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&v8->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  v8->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HudComponent::`vftable'{for `UFG::SimComponent'};
  v8->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HudComponent::`vftable'{for `UFG::UpdateInterface'};
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v8->mRootTransformComponent);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&v8->mHealthComponent);
  UFG::qString::qString(&v8->mSymbolName);
  UFG::qString::qString(&v8->mCustomWorldMapCaption);
  v10 = UFG::HudComponent::s_HudComponentList.mNode.mPrev;
  UFG::HudComponent::s_HudComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&v8->mPrev;
  v9->mPrev = v10;
  v8->mNext = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&UFG::HudComponent::s_HudComponentList;
  UFG::HudComponent::s_HudComponentList.mNode.mPrev = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&v8->mPrev;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v8->vfptr, UFG::HudComponent::_HudComponentTypeUID, "HudComponent");
  UFG::qString::Set(&v8->mSymbolName, v7);
  v8->mUseCustomFilterDistance = v6;
  v8->mCustomFilterDistance = customFilterDistance;
  UFG::qString::Set(&v8->mCustomWorldMapCaption, customWorldMapCaption);
  *(_WORD *)&v8->mIsKnockedOut = 0;
}

// File Line: 73
// RVA: 0x51BB90
void __fastcall UFG::HudComponent::~HudComponent(UFG::HudComponent *this)
{
  UFG::HudComponent *v1; // rdi
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v2; // rbx
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v3; // rcx
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v4; // rax
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v5; // rcx
  UFG::qNode<UFG::HudComponent,UFG::HudComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HudComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HudComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::HudComponent::s_HudComponentpCurrentIterator )
    UFG::HudComponent::s_HudComponentpCurrentIterator = (UFG::HudComponent *)&this->mPrev[-5].mNext;
  v2 = (UFG::qNode<UFG::HudComponent,UFG::HudComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&v1->mCustomWorldMapCaption);
  UFG::qString::~qString(&v1->mSymbolName);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->mRootTransformComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 86
// RVA: 0x5356E0
bool __fastcall UFG::HudComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(v2, (UFG::qSymbol *)&SimSymX_propset_componentHud.mUID, DEPTH_RECURSE) != 0i64;
}

// File Line: 92
// RVA: 0x5450A0
UFG::SimComponent *__fastcall UFG::HudComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v1 = sceneObject;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x118ui64, "HudComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::HudComponent::HudComponent((UFG::HudComponent *)v3, v1->m_NameUID, v4, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 102
// RVA: 0x53E1E0
void __usercall UFG::HudComponent::OnAttach(UFG::HudComponent *this@<rcx>, UFG::SimObject *object@<rdx>, float a3@<xmm0>)
{
  UFG::SimObject *v3; // rdi
  UFG::HudComponent *v4; // rbx
  unsigned int v5; // eax
  UFG::BasePhysicsSystem *v6; // rbp
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *v7; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::SimObject *v12; // rax
  unsigned int v13; // esi
  UFG::qBaseTreeRB *v14; // rdi
  UFG::UIMapBlip *v15; // rax
  UFG::SimComponent *v16; // rbx

  v3 = object;
  v4 = this;
  this->mBlipGuid = 0;
  if ( this->mSymbolName.mStringHash32 == -1 )
    this->mSymbolName.mStringHash32 = UFG::qStringHash32(this->mSymbolName.mData, 0xFFFFFFFF);
  v5 = v4->mSymbolName.mStringHash32;
  v4->mIsHostile = v5 == -2083396313 || v5 == -1617994565 || v5 == -1188642363 || v5 == -590296049;
  v6 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&v4->mRootTransformComponent, v3);
  v7 = &v4->mHealthComponent;
  if ( v4->mHealthComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v4->mHealthComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v4->mHealthComponent.m_pSimComponent = 0i64;
LABEL_15:
    v4->mHealthComponent.m_pSimObject = 0i64;
    v4->mHealthComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mHealthComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_16;
  }
  if ( v4->mHealthComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v4->mHealthComponent.mNext != &v4->mHealthComponent) )
  {
    v10 = v7->mPrev;
    v11 = v4->mHealthComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_15;
  }
LABEL_16:
  v4->mHealthComponent.m_Changed = 1;
  v4->mHealthComponent.m_pSimObject = v3;
  v4->mHealthComponent.m_TypeUID = UFG::HealthComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::BindInternal<UFG::SimObject>(&v4->mHealthComponent, v3);
  if ( !v6 )
    return;
  if ( !v4->mBlipGuid )
  {
    v12 = v4->m_pSimObject;
    if ( v12 )
      v4->mBlipGuid = v12->m_Name.mUID;
  }
  v13 = v4->mBlipGuid;
  v14 = UFG::BasePhysicsSystem::GetCollisionModel(v6, v4->mBlipGuid);
  if ( !v14 )
  {
    v15 = UFG::UIMapBlipManager::CreateIcon((UFG::UIMapBlipManager *)v6, v13, v4->mSymbolName.mData, 0.0, a3, 0.0);
    v14 = (UFG::qBaseTreeRB *)v15;
    if ( !v15 )
      return;
    v15->mUseCustomFilterDistance = v4->mUseCustomFilterDistance;
    v15->mCustomFilterDistance = v4->mCustomFilterDistance;
    UFG::UIMapBlip::SetWorldMapCaption(v15, v4->mCustomWorldMapCaption.mData);
  }
  v16 = v4->mRootTransformComponent.m_pSimComponent;
  if ( v16 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
    UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)v14, (UFG::qVector3 *)&v16[2].m_BoundComponentHandles);
  }
}

// File Line: 154
// RVA: 0x5407C0
void __fastcall UFG::HudComponent::OnDetach(UFG::HudComponent *this)
{
  UFG::HudComponent *v1; // rbx
  UFG::UIMapBlipManager *v2; // rcx
  UFG::SimObject *v3; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v4; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *v9; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  v1 = this;
  v2 = UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    if ( !v1->mBlipGuid )
    {
      v3 = v1->m_pSimObject;
      if ( v3 )
        v1->mBlipGuid = v3->m_Name.mUID;
    }
    UFG::UIMapBlipManager::RemoveIcon(v2, v1->mBlipGuid);
  }
  v4 = &v1->mRootTransformComponent;
  if ( v1->mRootTransformComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v1->mRootTransformComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v1->mRootTransformComponent.m_pSimComponent = 0i64;
LABEL_12:
    v1->mRootTransformComponent.m_pSimObject = 0i64;
    v1->mRootTransformComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mRootTransformComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_13;
  }
  if ( v1->mRootTransformComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mRootTransformComponent.mNext != &v1->mRootTransformComponent) )
  {
    v7 = v4->mPrev;
    v8 = v1->mRootTransformComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_12;
  }
LABEL_13:
  v1->mRootTransformComponent.m_Changed = 1;
  v9 = &v1->mHealthComponent;
  if ( v1->mHealthComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v1->mHealthComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v1->mHealthComponent.m_pSimComponent = 0i64;
LABEL_19:
    v1->mHealthComponent.m_pSimObject = 0i64;
    v1->mHealthComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mHealthComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_20;
  }
  if ( v1->mHealthComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v1->mHealthComponent.mNext != &v1->mHealthComponent) )
  {
    v12 = v9->mPrev;
    v13 = v1->mHealthComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_19;
  }
LABEL_20:
  v1->mHealthComponent.m_Changed = 1;
}

// File Line: 166
// RVA: 0x55BB20
void __fastcall UFG::HudComponent::Update(UFG::HudComponent *this, float delta_sec)
{
  UFG::HudComponent *v2; // rbx
  UFG::BasePhysicsSystem *v3; // rcx
  char *v4; // rax
  UFG::qBaseTreeRB *v5; // rbp
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::ObjectiveTracker *v8; // rax

  v2 = this;
  v3 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    if ( !LODWORD(v2->mSymbolName.mData) )
    {
      v4 = v2[-1].mCustomWorldMapCaption.mData;
      if ( v4 )
        LODWORD(v2->mSymbolName.mData) = *((_DWORD *)v4 + 18);
    }
    v5 = UFG::BasePhysicsSystem::GetCollisionModel(v3, (unsigned int)v2->mSymbolName.mData);
    if ( v5 && v2[-1].mCustomWorldMapCaption.mData )
    {
      v6 = v2->m_BoundComponentHandles.mNode.mPrev;
      if ( v6 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_BoundComponentHandles.mNode.mPrev);
        UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)v5, (UFG::qVector3 *)&v6[11]);
      }
      if ( !LOBYTE(v2->mHealthComponent.m_pSimComponent) )
      {
        v7 = v2->mRootTransformComponent.mNext;
        if ( v7 )
        {
          if ( BYTE4(v7[7].mPrev) )
          {
            UFG::HudComponent::HideSymbol((UFG::HudComponent *)((char *)v2 - 64));
            v8 = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
            if ( v8 )
              UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
                v8,
                (UFG::qSymbol *)v2[-1].mCustomWorldMapCaption.mData + 18,
                0);
            LOBYTE(v2->mHealthComponent.m_pSimComponent) = 1;
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
  UFG::SimObject *v2; // rax
  UFG::qBaseTreeRB *v3; // rax

  v1 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    if ( !this->mBlipGuid )
    {
      v2 = this->m_pSimObject;
      if ( v2 )
        this->mBlipGuid = v2->m_Name.mUID;
    }
    v3 = UFG::BasePhysicsSystem::GetCollisionModel(v1, this->mBlipGuid);
    if ( v3 )
      UFG::UIMapBlip::SetVisible((UFG::UIMapBlip *)v3, 0);
  }
}

// File Line: 236
// RVA: 0x533930
char __fastcall UFG::HudComponent::GetWorldPosition(UFG::HudComponent *this, UFG::qVector3 *pos)
{
  UFG::SimComponent *v2; // rbx
  UFG::qVector3 *v3; // rdi
  float v4; // xmm0_4
  float v5; // xmm1_4
  char result; // al

  v2 = this->mRootTransformComponent.m_pSimComponent;
  v3 = pos;
  if ( !v2 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mRootTransformComponent.m_pSimComponent);
  v4 = *((float *)&v2[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v5 = *(float *)&v2[2].m_BoundComponentHandles.mNode.mNext;
  v3->x = *(float *)&v2[2].m_BoundComponentHandles.mNode.mPrev;
  result = 1;
  v3->y = v4;
  v3->z = v5;
  return result;
}

// File Line: 248
// RVA: 0x52AB90
__int64 __fastcall UFG::HudComponent::GetBlipGuid(UFG::HudComponent *this)
{
  UFG::SimObject *v1; // rax

  if ( !this->mBlipGuid )
  {
    v1 = this->m_pSimObject;
    if ( v1 )
      this->mBlipGuid = v1->m_Name.mUID;
  }
  return this->mBlipGuid;
}

// File Line: 262
// RVA: 0x52DF60
UFG::qBaseTreeRB *__fastcall UFG::HudComponent::GetIcon(UFG::HudComponent *this)
{
  UFG::BasePhysicsSystem *v1; // r8
  UFG::SimObject *v3; // rax

  v1 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( !UFG::UIHKScreenHud::mIconManager )
    return 0i64;
  if ( !this->mBlipGuid )
  {
    v3 = this->m_pSimObject;
    if ( v3 )
      this->mBlipGuid = v3->m_Name.mUID;
  }
  return UFG::BasePhysicsSystem::GetCollisionModel(v1, this->mBlipGuid);
}

