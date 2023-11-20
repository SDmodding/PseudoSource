// File Line: 27
// RVA: 0x154DA80
__int64 dynamic_initializer_for__UFG::PowerManagementComponent::s_PowerManagementComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PowerManagementComponent::s_PowerManagementComponentList__);
}

// File Line: 28
// RVA: 0x582A20
const char *__fastcall UFG::PowerManagementComponent::GetTypeName(UFG::PowerManagementComponent *this)
{
  return "PowerManagementComponent";
}

// File Line: 36
// RVA: 0x1554430
__int64 UFG::_dynamic_initializer_for__sSuspendDistance__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PowerManagement_SuspendDistance", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSuspendDistance, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSuspendDistance__);
}

// File Line: 47
// RVA: 0x58A400
UFG::SimComponent *__fastcall UFG::PowerManagementComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObjectProperties)
{
  UFG::SceneObjectProperties *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h]

  v1 = pSceneObjectProperties;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x88ui64, "PowerManagementComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::PowerManagementComponent::PowerManagementComponent((UFG::PowerManagementComponent *)v3, v1);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return v5;
}

// File Line: 61
// RVA: 0x57CEF0
void __fastcall UFG::PowerManagementComponent::PowerManagementComponent(UFG::PowerManagementComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rbp
  UFG::PowerManagementComponent *v3; // rsi
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v4; // rdi
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v5; // rax
  UFG::qPropertySet *v6; // rcx
  float *v7; // rax
  float v8; // xmm1_4
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0> *v9; // [rsp+58h] [rbp+10h]

  v2 = pSceneObj;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, pSceneObj->m_NameUID);
  v4 = (UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  UFG::qSafePointerNode<UFG::PowerManagementComponent>::qSafePointerNode<UFG::PowerManagementComponent>((UFG::qSafePointerNode<UFG::PowerManagementComponent> *)&v3->vfptr);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PowerManagementComponent::`vftable'{for `UFG::SimComponent'};
  v3->vfptr = (UFG::qSafePointerNode<UFG::PowerManagementComponent>Vtbl *)&UFG::PowerManagementComponent::`vftable'{for `UFG::qSafePointerNode<UFG::PowerManagementComponent>'};
  v3->m_ePowerStateEnum = 0;
  v3->m_fSuspendDistanceSquared = -1.0;
  v3->m_fPreventSuspendTimeS = -1.0;
  v3->m_cPreventSuspendRefCount = 0;
  v9 = &v3->m_PowerManagedResourceList;
  v9->mNode.mPrev = &v9->mNode;
  v9->mNode.mNext = &v9->mNode;
  v5 = UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mPrev;
  UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *)&UFG::PowerManagementComponent::s_PowerManagementComponentList;
  UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mPrev = (UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::PowerManagementComponent::_PowerManagementComponentTypeUID,
    "PowerManagementComponent");
  v6 = v2->mpWritableProperties;
  if ( !v6 )
    v6 = v2->mpConstProperties;
  v7 = PropertyUtils::Get<float>(v6, (UFG::qSymbol *)&sSuspendDistance.mUID, DEPTH_RECURSE);
  if ( v7 )
    v8 = *v7;
  else
    v8 = FLOAT_N1_0;
  v3->m_fSuspendDistanceSquared = v8;
  if ( v8 >= 0.0 )
    v3->m_fSuspendDistanceSquared = v8 * v8;
}

// File Line: 87
// RVA: 0x57DDB0
void __fastcall UFG::PowerManagementComponent::~PowerManagementComponent(UFG::PowerManagementComponent *this)
{
  UFG::PowerManagementComponent *v1; // rsi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v3; // rdi
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v4; // rcx
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v5; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v6; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v9; // rcx
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PowerManagementComponent::`vftable'{for `UFG::SimComponent'};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<UFG::PowerManagementComponent>Vtbl *)&UFG::PowerManagementComponent::`vftable'{for `UFG::qSafePointerNode<UFG::PowerManagementComponent>'};
  if ( this == UFG::PowerManagementComponent::s_PowerManagementComponentpCurrentIterator )
    UFG::PowerManagementComponent::s_PowerManagementComponentpCurrentIterator = (UFG::PowerManagementComponent *)&this->mPrev[-6].mNext;
  v3 = (UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *)&this->mPrev;
  v4 = this->mPrev;
  v5 = v3->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&v1->m_PowerManagedResourceList);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::PowerManagementComponent>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  v6 = &v2->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(v6);
  v7 = v6->mNode.mPrev;
  v8 = v6->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v9 = v3->mPrev;
  v10 = v3->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v3->mPrev = v3;
  v3->mNext = v3;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 94
// RVA: 0x586810
void __fastcall UFG::PowerManagementComponent::OnAttach(UFG::PowerManagementComponent *this, UFG::SimObject *pSimObject)
{
  UFG::PowerManagementComponent *v2; // rbx
  char *v3; // rax

  v2 = this;
  if ( this->m_fSuspendDistanceSquared < 0.0 )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qPrintf(
      "WARNING: PowerManagementComponent for object '%s' is set negative (%f) - This will waste some memory and some CPU "
      "cycles.  Perhaps we can remove this component entirely from the property set?  Suspending.\n",
      v3,
      v2->m_fSuspendDistanceSquared);
    ((void (__fastcall *)(UFG::PowerManagementComponent *))v2->vfptr[8].__vecDelDtor)(v2);
  }
}

// File Line: 180
// RVA: 0x58DAE0
void __fastcall UFG::PowerManagementComponent::UpdateAll(float fDeltaS)
{
  UFG::TransformNodeComponent *v1; // rbx
  UFG::qVector3 *v2; // rsi
  UFG::PowerManagementComponent *v3; // rbx
  UFG::qList<UFG::PowerManagementComponent,UFG::PowerManagementComponent,1,0> *v4; // rdi
  UFG::PowerManagementComponent::ePowerStateEnum v5; // ecx
  int v6; // ecx

  if ( LocalPlayer )
  {
    v1 = LocalPlayer->m_pTransformNodeComponent;
    if ( v1 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
      v2 = (UFG::qVector3 *)&v1->mWorldTransform.v3;
      v3 = (UFG::PowerManagementComponent *)&UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mNext[-6].mNext;
      if ( &UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> **)((char *)&UFG::PowerManagementComponent::s_PowerManagementComponentList - 88) )
      {
        do
        {
          v4 = (UFG::qList<UFG::PowerManagementComponent,UFG::PowerManagementComponent,1,0> *)&v3->mNext[-6].mNext;
          if ( (v3->m_Flags & 3) == 1 )
          {
            v5 = v3->m_ePowerStateEnum;
            if ( v5 )
            {
              v6 = v5 - 1;
              if ( v6 )
              {
                if ( v6 == 2 && UFG::PowerManagementComponent::areResourcesAvailable(v3) )
                  UFG::PowerManagementComponent::gotoResumed(v3);
              }
              else
              {
                UFG::PowerManagementComponent::updatePowerStateSuspended(v3, v2);
              }
            }
            else
            {
              UFG::PowerManagementComponent::updatePowerStateNormal(v3, v2, fDeltaS);
            }
          }
          v3 = (UFG::PowerManagementComponent *)v4;
        }
        while ( v4 != (UFG::qList<UFG::PowerManagementComponent,UFG::PowerManagementComponent,1,0> *)((char *)&UFG::PowerManagementComponent::s_PowerManagementComponentList - 88) );
      }
    }
  }
}

// File Line: 202
// RVA: 0x5926B0
void __fastcall UFG::PowerManagementComponent::updatePowerStateNormal(UFG::PowerManagementComponent *this, UFG::qVector3 *posPlayer, const float fDeltaS)
{
  UFG::qVector3 *v3; // rsi
  UFG::PowerManagementComponent *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm0_4
  UFG::SimObject *v7; // rax
  UFG::TransformNodeComponent *v8; // rdi
  float v9; // xmm8_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::SimObject *v15; // rcx

  v3 = posPlayer;
  v4 = this;
  if ( this->m_cPreventSuspendRefCount <= 0 )
  {
    v5 = this->m_fPreventSuspendTimeS;
    if ( v5 >= 0.0 )
    {
      if ( v5 >= 3.4028235e38 )
        return;
      v6 = v5 - fDeltaS;
      this->m_fPreventSuspendTimeS = v6;
      if ( v6 > 0.0 )
        return;
      this->m_fPreventSuspendTimeS = -1.0;
    }
    v7 = this->m_pSimObject;
    if ( v7 )
    {
      v8 = v7->m_pTransformNodeComponent;
      if ( v8 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        v9 = v3->x - v8->mWorldTransform.v3.x;
        v10 = v3->y - v8->mWorldTransform.v3.y;
        v11 = v3->z - v8->mWorldTransform.v3.z;
        NISManager::GetInstance();
        if ( (float)((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v11 * v11)) >= v4->m_fSuspendDistanceSquared )
        {
          v12 = (UFG::SimObjectGame *)v4->m_pSimObject;
          if ( v12
            && ((v13 = v12->m_Flags, !((v13 >> 14) & 1)) ? ((v13 & 0x8000u) == 0 ? (!((v13 >> 13) & 1) ? (!((v13 >> 12) & 1) ? (v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::CompositeDrawableComponent::_TypeUID)) : (v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CompositeDrawableComponent::_TypeUID))) : (v14 = v12->m_Components.p[9].m_pComponent)) : (v14 = v12->m_Components.p[14].m_pComponent)) : (v14 = v12->m_Components.p[14].m_pComponent),
                v14) )
          {
            v15 = v14[19].m_pSimObject;
          }
          else
          {
            v15 = 0i64;
          }
          if ( v15 && LOBYTE(v15->vfptr) > 1u )
          {
            if ( UFG::PowerManagementComponent::areResourcesAvailable(v4) )
              UFG::PowerManagementComponent::gotoSuspended(v4);
          }
        }
      }
    }
  }
}

// File Line: 318
// RVA: 0x592850
void __fastcall UFG::PowerManagementComponent::updatePowerStateSuspended(UFG::PowerManagementComponent *this, UFG::qVector3 *posPlayer)
{
  UFG::qVector3 *v2; // rsi
  UFG::PowerManagementComponent *v3; // rbx
  UFG::SimObject *v4; // rax
  float *v5; // rdi
  float v6; // xmm6_4
  float v7; // xmm7_4

  v2 = posPlayer;
  v3 = this;
  if ( this->m_cPreventSuspendRefCount <= 0 )
  {
    v4 = this->m_pSimObject;
    if ( v4 )
    {
      v5 = (float *)v4->m_pTransformNodeComponent;
      if ( v5 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v4->m_pTransformNodeComponent);
        v6 = v3->m_fSuspendDistanceSquared;
        v7 = (float)((float)((float)(v2->y - v5[45]) * (float)(v2->y - v5[45]))
                   + (float)((float)(v2->x - v5[44]) * (float)(v2->x - v5[44])))
           + (float)((float)(v2->z - v5[46]) * (float)(v2->z - v5[46]));
        if ( NISManager::GetInstance()->mState )
          v6 = v6 * 10.0;
        if ( v7 < v6 )
          UFG::PowerManagementComponent::gotoResuming(v3);
      }
    }
  }
  else
  {
    UFG::PowerManagementComponent::gotoResuming(this);
  }
}

// File Line: 362
// RVA: 0x591BB0
char __fastcall UFG::PowerManagementComponent::areResourcesAvailable(UFG::PowerManagementComponent *this)
{
  UFG::PowerManagementComponent *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::BaseAnimationComponent *v4; // rax
  char result; // al
  char v6; // di
  signed __int64 v7; // rsi
  _QWORD *v8; // rcx
  signed __int64 v9; // rbx
  char v10; // al

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::BaseAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::BaseAnimationComponent::_TypeUID)) : (v4 = (UFG::BaseAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::BaseAnimationComponent::_TypeUID))) : (v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[8].m_pComponent)) : (v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[9].m_pComponent)) : (v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[9].m_pComponent),
        v4) )
  {
    result = UFG::BaseAnimationComponent::AreResourcesAvailable(v4);
    v6 = result;
    if ( !result )
      return result;
  }
  else
  {
    v6 = 1;
  }
  v7 = (signed __int64)&v1->m_fPreventSuspendTimeS;
  v8 = &v1->m_PowerManagedResourceList.mNode.mNext[-1].mNext;
  if ( v8 != (_QWORD *)&v1->m_fPreventSuspendTimeS )
  {
    do
    {
      v9 = v8[2] - 8i64;
      v10 = (*(__int64 (**)(void))(*v8 + 16i64))();
      v8 = (_QWORD *)v9;
      v6 &= v10;
    }
    while ( v9 != v7 );
  }
  return v6;
}

// File Line: 393
// RVA: 0x592310
void __fastcall UFG::PowerManagementComponent::gotoSuspended(UFG::PowerManagementComponent *this)
{
  UFG::PowerManagementComponent *v1; // rsi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::BaseAnimationComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::TransformNodeComponent *v13; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v14; // rcx
  const char *v15; // rax
  __int64 v16; // rdx
  float v17; // eax
  signed __int64 v18; // rcx
  signed __int64 v19; // rbx
  UFG::qReflectHandleBase v20; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[7].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      else
      {
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v4 = v5;
      }
    }
    else
    {
      v4 = v2->m_Components.p[7].m_pComponent;
    }
    if ( v4 )
      ((void (__cdecl *)(UFG::SimComponent *))v4->vfptr[8].__vecDelDtor)(v4);
  }
  v6 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::BaseAnimationComponent *)v6->m_Components.p[9].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::BaseAnimationComponent *)v6->m_Components.p[8].m_pComponent;
      }
      else
      {
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::BaseAnimationComponent::_TypeUID);
        v8 = (UFG::BaseAnimationComponent *)v9;
      }
    }
    else
    {
      v8 = (UFG::BaseAnimationComponent *)v6->m_Components.p[9].m_pComponent;
    }
    if ( v8 )
    {
      ((void (__fastcall *)(UFG::BaseAnimationComponent *))v8->vfptr[8].__vecDelDtor)(v8);
      Creature::UnbindResources(v8->mCreature);
      UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks(v8);
    }
  }
  v10 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID);
      else
        v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID);
    }
    v13 = (UFG::TransformNodeComponent *)v12;
    if ( v12 )
    {
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v20);
        v15 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v14);
        v20.mTypeUID = UFG::qStringHash64(v15, 0xFFFFFFFFFFFFFFFFui64);
        v16 = *(_QWORD *)&v13->mWorldTransform.v2.x;
        if ( v16 )
          UFG::qReflectHandleBase::operator=(&v20, (UFG::qReflectHandleBase *)(v16 + 224));
        if ( LODWORD(v20.mData[2].mBaseNode.mNeighbours[0]) == 2 )
        {
          v17 = v13->mWorldVelocity.z;
          if ( LOBYTE(v17) & 2 )
          {
            if ( !(LOBYTE(v17) & 1) )
              ((void (__fastcall *)(UFG::TransformNodeComponent *))v13->vfptr[16].__vecDelDtor)(v13);
          }
        }
        v13 = UFG::SimObject::GetComponentOfType(
                v13->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v13->vfptr);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v20);
      }
      while ( v13 );
    }
  }
  v18 = (signed __int64)&v1->m_PowerManagedResourceList.mNode.mNext[-1].mNext;
  if ( (UFG::PowerManagementComponent *)v18 != (UFG::PowerManagementComponent *)&v1->m_fPreventSuspendTimeS )
  {
    do
    {
      v19 = *(_QWORD *)(v18 + 16) - 8i64;
      (**(void (__cdecl ***)(signed __int64))v18)(v18);
      v18 = v19;
    }
    while ( (UFG::PowerManagementComponent *)v19 != (UFG::PowerManagementComponent *)&v1->m_fPreventSuspendTimeS );
  }
  v1->m_ePowerStateEnum = 1;
}

// File Line: 443
// RVA: 0x592120
void __fastcall UFG::PowerManagementComponent::gotoResuming(UFG::PowerManagementComponent *this)
{
  UFG::PowerManagementComponent *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::BaseAnimationComponent *v4; // rax
  _QWORD *v5; // rcx
  signed __int64 v6; // rbx
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::TransformNodeComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  __int64 v13; // rdx
  float v14; // eax
  UFG::qReflectHandleBase v15; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[9].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[8].m_pComponent;
      else
        v4 = (UFG::BaseAnimationComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v2,
                                                                UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::BaseAnimationComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[9].m_pComponent;
    }
    if ( v4 )
      UFG::BaseAnimationComponent::RebindResources(v4);
  }
  v5 = &v1->m_PowerManagedResourceList.mNode.mNext[-1].mNext;
  if ( v5 != (_QWORD *)&v1->m_fPreventSuspendTimeS )
  {
    do
    {
      v6 = v5[2] - 8i64;
      (*(void (__cdecl **)(_QWORD *))(*v5 + 8i64))(v5);
      v5 = (_QWORD *)v6;
    }
    while ( (UFG::PowerManagementComponent *)v6 != (UFG::PowerManagementComponent *)&v1->m_fPreventSuspendTimeS );
  }
  v7 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
      else
        v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
    }
    v10 = (UFG::TransformNodeComponent *)v9;
    if ( v9 )
    {
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v15);
        v12 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
        v15.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
        v13 = *(_QWORD *)&v10->mWorldTransform.v2.x;
        if ( v13 )
          UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)(v13 + 224));
        if ( LODWORD(v15.mData[2].mBaseNode.mNeighbours[0]) == 2 )
        {
          v14 = v10->mWorldVelocity.z;
          if ( !(LOBYTE(v14) & 2) || LOBYTE(v14) & 1 )
          {
            LOBYTE(v13) = 1;
            v10->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v10->vfptr, v13);
          }
        }
        v10 = UFG::SimObject::GetComponentOfType(
                v10->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v10->vfptr);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
      }
      while ( v10 );
    }
  }
  v1->m_ePowerStateEnum = 3;
}

// File Line: 486
// RVA: 0x591EE0
void __fastcall UFG::PowerManagementComponent::gotoResumed(UFG::PowerManagementComponent *this)
{
  UFG::PowerManagementComponent *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rcx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::TransformNodeComponent *v13; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v14; // rcx
  const char *v15; // rax
  __int64 v16; // rdx
  float v17; // eax
  UFG::qReflectHandleBase v18; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[7].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      else
      {
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v4 = v5;
      }
    }
    else
    {
      v4 = v2->m_Components.p[7].m_pComponent;
    }
    if ( v4 )
      ((void (__cdecl *)(UFG::SimComponent *))v4->vfptr[9].__vecDelDtor)(v4);
  }
  v6 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v6->m_Components.p[9].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = v6->m_Components.p[8].m_pComponent;
      }
      else
      {
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::BaseAnimationComponent::_TypeUID);
        v8 = v9;
      }
    }
    else
    {
      v8 = v6->m_Components.p[9].m_pComponent;
    }
    if ( v8 )
      ((void (__cdecl *)(UFG::SimComponent *))v8->vfptr[9].__vecDelDtor)(v8);
  }
  v10 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID);
      else
        v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID);
    }
    v13 = (UFG::TransformNodeComponent *)v12;
    if ( v12 )
    {
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v18);
        v15 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v14);
        v18.mTypeUID = UFG::qStringHash64(v15, 0xFFFFFFFFFFFFFFFFui64);
        v16 = *(_QWORD *)&v13->mWorldTransform.v2.x;
        if ( v16 )
          UFG::qReflectHandleBase::operator=(&v18, (UFG::qReflectHandleBase *)(v16 + 224));
        if ( LODWORD(v18.mData[2].mBaseNode.mNeighbours[0]) == 2 )
        {
          v17 = v13->mWorldVelocity.z;
          if ( !(LOBYTE(v17) & 2) || LOBYTE(v17) & 1 )
          {
            LOBYTE(v16) = 1;
            v13->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v13->vfptr, v16);
          }
        }
        v13 = UFG::SimObject::GetComponentOfType(
                v13->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v13->vfptr);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
      }
      while ( v13 );
    }
  }
  v1->m_ePowerStateEnum = 0;
}

// File Line: 529
// RVA: 0x58B340
void __fastcall UFG::PowerManagementComponent::Reset(UFG::PowerManagementComponent *this)
{
  UFG::PowerManagementComponent *v1; // rbx

  v1 = this;
  if ( this->m_ePowerStateEnum )
  {
    UFG::PowerManagementComponent::gotoResuming(this);
    UFG::PowerManagementComponent::gotoResumed(v1);
    v1->m_fPreventSuspendTimeS = -1.0;
  }
  else
  {
    this->m_fPreventSuspendTimeS = -1.0;
  }
}

// File Line: 549
// RVA: 0x57F050
void __fastcall UFG::PowerManagementComponent::AllowSuspend(UFG::PowerManagementComponent *this)
{
  this->m_fPreventSuspendTimeS = -1.0;
}

// File Line: 563
// RVA: 0x588900
void __fastcall UFG::PowerManagementComponent::PreventSuspendIndefinitely(UFG::PowerManagementComponent *this)
{
  UFG::PowerManagementComponent *v1; // rbx

  v1 = this;
  if ( this->m_ePowerStateEnum )
  {
    UFG::PowerManagementComponent::gotoResuming(this);
    v1->m_fPreventSuspendTimeS = 3.4028235e38;
  }
  else
  {
    this->m_fPreventSuspendTimeS = 3.4028235e38;
  }
}

// File Line: 583
// RVA: 0x588930
void __fastcall UFG::PowerManagementComponent::PreventSuspendTemporarily(UFG::PowerManagementComponent *this, const float fTimeS)
{
  UFG::PowerManagementComponent *v2; // rbx

  v2 = this;
  if ( this->m_ePowerStateEnum )
    UFG::PowerManagementComponent::gotoResuming(this);
  if ( v2->m_fPreventSuspendTimeS < 3.4028235e38 )
    v2->m_fPreventSuspendTimeS = fTimeS;
}

// File Line: 610
// RVA: 0x5885F0
void __fastcall UFG::PowerManagementComponent::PermanentlySuspend(UFG::PowerManagementComponent *this)
{
  UFG::PowerManagementComponent *v1; // rbx

  v1 = this;
  if ( (unsigned int)(this->m_ePowerStateEnum - 1) <= 1 )
  {
    this->m_ePowerStateEnum = 2;
  }
  else
  {
    UFG::PowerManagementComponent::gotoSuspended(this);
    v1->m_ePowerStateEnum = 2;
  }
}

// File Line: 626
// RVA: 0x57EF40
void __fastcall UFG::PowerManagementComponent::AddPowerManagedResource(UFG::PowerManagementComponent *this, UFG::PowerManagedResource *pPowerManagedResource)
{
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v2; // rax
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v3; // rdx
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0> *v4; // rcx

  v2 = this->m_PowerManagedResourceList.mNode.mPrev;
  v3 = (UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *)&pPowerManagedResource->mPrev;
  v4 = &this->m_PowerManagedResourceList;
  v2->mNext = v3;
  v3->mPrev = v2;
  v3->mNext = &v4->mNode;
  v4->mNode.mPrev = v3;
}

// File Line: 633
// RVA: 0x57EF60
void __fastcall UFG::PowerManagementComponent::AddPreventSuspendRefCount(UFG::PowerManagementComponent *this)
{
  signed int v1; // edx

  v1 = this->m_cPreventSuspendRefCount;
  if ( v1 < 255 )
    this->m_cPreventSuspendRefCount = v1 + 1;
}

// File Line: 646
// RVA: 0x58AFD0
void __fastcall UFG::PowerManagementComponent::RemovePreventSuspendRefCount(UFG::PowerManagementComponent *this)
{
  char v1; // al

  v1 = this->m_cPreventSuspendRefCount;
  if ( v1 > 0 )
    this->m_cPreventSuspendRefCount = v1 - 1;
}

