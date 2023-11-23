// File Line: 27
// RVA: 0x154DA80
__int64 dynamic_initializer_for__UFG::PowerManagementComponent::s_PowerManagementComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PowerManagementComponent::s_PowerManagementComponentList__);
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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSuspendDistance__);
}

// File Line: 47
// RVA: 0x58A400
UFG::PowerManagementComponent *__fastcall UFG::PowerManagementComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObjectProperties)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x88ui64, "PowerManagementComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::PowerManagementComponent::PowerManagementComponent((UFG::PowerManagementComponent *)v3, pSceneObjectProperties);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, pSceneObjectProperties->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return (UFG::PowerManagementComponent *)v5;
}

// File Line: 61
// RVA: 0x57CEF0
void __fastcall UFG::PowerManagementComponent::PowerManagementComponent(
        UFG::PowerManagementComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *mPrev; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  float *v6; // rax
  float v7; // xmm1_4

  UFG::SimComponent::SimComponent(this, pSceneObj->m_NameUID);
  this->mPrev = &this->UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent>;
  this->mNext = &this->UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent>;
  UFG::qSafePointerNode<UFG::PowerManagementComponent>::qSafePointerNode<UFG::PowerManagementComponent>(&this->UFG::qSafePointerNode<UFG::PowerManagementComponent>);
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PowerManagementComponent::`vftable{for `UFG::SimComponent};
  this->UFG::qSafePointerNode<UFG::PowerManagementComponent>::vfptr = (UFG::qSafePointerNode<UFG::PowerManagementComponent>Vtbl *)&UFG::PowerManagementComponent::`vftable{for `UFG::qSafePointerNode<UFG::PowerManagementComponent>};
  this->m_ePowerStateEnum = ePOWER_STATE_NORMAL;
  this->m_fSuspendDistanceSquared = -1.0;
  this->m_fPreventSuspendTimeS = -1.0;
  this->m_cPreventSuspendRefCount = 0;
  this->m_PowerManagedResourceList.mNode.mPrev = &this->m_PowerManagedResourceList.mNode;
  this->m_PowerManagedResourceList.mNode.mNext = &this->m_PowerManagedResourceList.mNode;
  mPrev = UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mPrev;
  UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *)&UFG::PowerManagementComponent::s_PowerManagementComponentList;
  UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mPrev = &this->UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::PowerManagementComponent::_PowerManagementComponentTypeUID,
    "PowerManagementComponent");
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v6 = PropertyUtils::Get<float>(mpWritableProperties, (UFG::qArray<unsigned long,0> *)&sSuspendDistance, DEPTH_RECURSE);
  if ( v6 )
    v7 = *v6;
  else
    v7 = FLOAT_N1_0;
  this->m_fSuspendDistanceSquared = v7;
  if ( v7 >= 0.0 )
    this->m_fSuspendDistanceSquared = v7 * v7;
}

// File Line: 87
// RVA: 0x57DDB0
void __fastcall UFG::PowerManagementComponent::~PowerManagementComponent(UFG::PowerManagementComponent *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v3; // rdi
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *mPrev; // rcx
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *mNext; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v9; // rcx
  UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v10; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PowerManagementComponent::`vftable{for `UFG::SimComponent};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<UFG::PowerManagementComponent>;
  this->UFG::qSafePointerNode<UFG::PowerManagementComponent>::vfptr = (UFG::qSafePointerNode<UFG::PowerManagementComponent>Vtbl *)&UFG::PowerManagementComponent::`vftable{for `UFG::qSafePointerNode<UFG::PowerManagementComponent>};
  if ( this == UFG::PowerManagementComponent::s_PowerManagementComponentpCurrentIterator )
    UFG::PowerManagementComponent::s_PowerManagementComponentpCurrentIterator = (UFG::PowerManagementComponent *)&this->mPrev[-6].mNext;
  v3 = &this->UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent>;
  mPrev = this->mPrev;
  mNext = v3->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&this->m_PowerManagedResourceList);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::PowerManagementComponent>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  p_m_SafePointerList = &v2->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(p_m_SafePointerList);
  v7 = p_m_SafePointerList->mNode.mPrev;
  v8 = p_m_SafePointerList->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_m_SafePointerList->mNode.mPrev = &p_m_SafePointerList->mNode;
  p_m_SafePointerList->mNode.mNext = &p_m_SafePointerList->mNode;
  v9 = v3->mPrev;
  v10 = v3->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v3->mPrev = v3;
  v3->mNext = v3;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 94
// RVA: 0x586810
void __fastcall UFG::PowerManagementComponent::OnAttach(
        UFG::PowerManagementComponent *this,
        UFG::SimObject *pSimObject)
{
  char *v3; // rax

  if ( this->m_fSuspendDistanceSquared < 0.0 )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qPrintf(
      "WARNING: PowerManagementComponent for object %s is set negative (%f) - This will waste some memory and some CPU "
      "cycles.  Perhaps we can remove this component entirely from the property set?  Suspending.\n",
      v3,
      this->m_fSuspendDistanceSquared);
    ((void (__fastcall *)(UFG::PowerManagementComponent *))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[8].__vecDelDtor)(this);
  }
}

// File Line: 180
// RVA: 0x58DAE0
void __fastcall UFG::PowerManagementComponent::UpdateAll(float fDeltaS)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector3 *v2; // rsi
  UFG::PowerManagementComponent *p_mNext; // rbx
  UFG::qList<UFG::PowerManagementComponent,UFG::PowerManagementComponent,1,0> *v4; // rdi
  UFG::PowerManagementComponent::ePowerStateEnum m_ePowerStateEnum; // ecx
  __int32 v6; // ecx

  if ( LocalPlayer )
  {
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
      v2 = (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3;
      p_mNext = (UFG::PowerManagementComponent *)&UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mNext[-6].mNext;
      if ( &UFG::PowerManagementComponent::s_PowerManagementComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::PowerManagementComponent,UFG::PowerManagementComponent> **)((char *)&UFG::PowerManagementComponent::s_PowerManagementComponentList - 88) )
      {
        do
        {
          v4 = (UFG::qList<UFG::PowerManagementComponent,UFG::PowerManagementComponent,1,0> *)&p_mNext->mNext[-6].mNext;
          if ( (p_mNext->m_Flags & 3) == 1 )
          {
            m_ePowerStateEnum = p_mNext->m_ePowerStateEnum;
            if ( m_ePowerStateEnum )
            {
              v6 = m_ePowerStateEnum - 1;
              if ( v6 )
              {
                if ( v6 == 2 && UFG::PowerManagementComponent::areResourcesAvailable(p_mNext) )
                  UFG::PowerManagementComponent::gotoResumed(p_mNext);
              }
              else
              {
                UFG::PowerManagementComponent::updatePowerStateSuspended(p_mNext, v2);
              }
            }
            else
            {
              UFG::PowerManagementComponent::updatePowerStateNormal(p_mNext, v2, fDeltaS);
            }
          }
          p_mNext = (UFG::PowerManagementComponent *)v4;
        }
        while ( v4 != (UFG::qList<UFG::PowerManagementComponent,UFG::PowerManagementComponent,1,0> *)((char *)&UFG::PowerManagementComponent::s_PowerManagementComponentList - 88) );
      }
    }
  }
}

// File Line: 202
// RVA: 0x5926B0
void __fastcall UFG::PowerManagementComponent::updatePowerStateNormal(
        UFG::PowerManagementComponent *this,
        UFG::qVector3 *posPlayer,
        const float fDeltaS)
{
  float m_fPreventSuspendTimeS; // xmm0_4
  float v6; // xmm0_4
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float v9; // xmm8_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  UFG::SimObjectGame *v12; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v15; // rcx

  if ( this->m_cPreventSuspendRefCount <= 0 )
  {
    m_fPreventSuspendTimeS = this->m_fPreventSuspendTimeS;
    if ( m_fPreventSuspendTimeS >= 0.0 )
    {
      if ( m_fPreventSuspendTimeS >= 3.4028235e38 )
        return;
      v6 = m_fPreventSuspendTimeS - fDeltaS;
      this->m_fPreventSuspendTimeS = v6;
      if ( v6 > 0.0 )
        return;
      this->m_fPreventSuspendTimeS = -1.0;
    }
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v9 = posPlayer->x - m_pTransformNodeComponent->mWorldTransform.v3.x;
        v10 = posPlayer->y - m_pTransformNodeComponent->mWorldTransform.v3.y;
        v11 = posPlayer->z - m_pTransformNodeComponent->mWorldTransform.v3.z;
        NISManager::GetInstance();
        if ( (float)((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v11 * v11)) >= this->m_fSuspendDistanceSquared )
        {
          v12 = (UFG::SimObjectGame *)this->m_pSimObject;
          if ( v12
            && ((m_Flags = v12->m_Flags, (m_Flags & 0x4000) == 0)
              ? (m_Flags >= 0
               ? ((m_Flags & 0x2000) == 0
                ? ((m_Flags & 0x1000) == 0
                 ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::CompositeDrawableComponent::_TypeUID))
                 : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v12,
                                        UFG::CompositeDrawableComponent::_TypeUID)))
                : (ComponentOfType = v12->m_Components.p[9].m_pComponent))
               : (ComponentOfType = v12->m_Components.p[14].m_pComponent))
              : (ComponentOfType = v12->m_Components.p[14].m_pComponent),
                ComponentOfType) )
          {
            v15 = ComponentOfType[19].m_pSimObject;
          }
          else
          {
            v15 = 0i64;
          }
          if ( v15 && LOBYTE(v15->vfptr) > 1u )
          {
            if ( UFG::PowerManagementComponent::areResourcesAvailable(this) )
              UFG::PowerManagementComponent::gotoSuspended(this);
          }
        }
      }
    }
  }
}

// File Line: 318
// RVA: 0x592850
void __fastcall UFG::PowerManagementComponent::updatePowerStateSuspended(
        UFG::PowerManagementComponent *this,
        UFG::qVector3 *posPlayer)
{
  UFG::SimObject *m_pSimObject; // rax
  float *m_pTransformNodeComponent; // rdi
  float m_fSuspendDistanceSquared; // xmm6_4
  float v7; // xmm7_4

  if ( this->m_cPreventSuspendRefCount <= 0 )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_pTransformNodeComponent = (float *)m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject->m_pTransformNodeComponent);
        m_fSuspendDistanceSquared = this->m_fSuspendDistanceSquared;
        v7 = (float)((float)((float)(posPlayer->y - m_pTransformNodeComponent[45])
                           * (float)(posPlayer->y - m_pTransformNodeComponent[45]))
                   + (float)((float)(posPlayer->x - m_pTransformNodeComponent[44])
                           * (float)(posPlayer->x - m_pTransformNodeComponent[44])))
           + (float)((float)(posPlayer->z - m_pTransformNodeComponent[46])
                   * (float)(posPlayer->z - m_pTransformNodeComponent[46]));
        if ( NISManager::GetInstance()->mState )
          m_fSuspendDistanceSquared = m_fSuspendDistanceSquared * 10.0;
        if ( v7 < m_fSuspendDistanceSquared )
          UFG::PowerManagementComponent::gotoResuming(this);
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
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::BaseAnimationComponent *ComponentOfType; // rax
  char result; // al
  char v6; // di
  float *p_m_fPreventSuspendTimeS; // rsi
  UFG::PowerManagementComponent *p_mNext; // rcx
  __int64 v9; // rbx
  char v10; // al

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject
    && ((m_Flags = m_pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) == 0
        ? ((m_Flags & 0x1000) == 0
         ? (ComponentOfType = (UFG::BaseAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pSimObject,
                                                               UFG::BaseAnimationComponent::_TypeUID))
         : (ComponentOfType = (UFG::BaseAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               m_pSimObject,
                                                               UFG::BaseAnimationComponent::_TypeUID)))
        : (ComponentOfType = (UFG::BaseAnimationComponent *)m_pSimObject->m_Components.p[8].m_pComponent))
       : (ComponentOfType = (UFG::BaseAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent))
      : (ComponentOfType = (UFG::BaseAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent),
        ComponentOfType) )
  {
    result = UFG::BaseAnimationComponent::AreResourcesAvailable(ComponentOfType);
    v6 = result;
    if ( !result )
      return result;
  }
  else
  {
    v6 = 1;
  }
  p_m_fPreventSuspendTimeS = &this->m_fPreventSuspendTimeS;
  p_mNext = (UFG::PowerManagementComponent *)&this->m_PowerManagedResourceList.mNode.mNext[-1].mNext;
  if ( p_mNext != (UFG::PowerManagementComponent *)&this->m_fPreventSuspendTimeS )
  {
    do
    {
      v9 = (__int64)&p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::m_SafePointerList.mNode.mNext[-1].mNext;
      v10 = ((__int64 (__fastcall *)(UFG::PowerManagementComponent *))p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[2].__vecDelDtor)(p_mNext);
      p_mNext = (UFG::PowerManagementComponent *)v9;
      v6 &= v10;
    }
    while ( (float *)v9 != p_m_fPreventSuspendTimeS );
  }
  return v6;
}

// File Line: 393
// RVA: 0x592310
void __fastcall UFG::PowerManagementComponent::gotoSuspended(UFG::PowerManagementComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  __int16 v7; // dx
  UFG::BaseAnimationComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *ComponentOfType; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v14; // rcx
  const char *TypeName; // rax
  __int64 v16; // rdx
  float z; // eax
  UFG::PowerManagementComponent *p_mNext; // rcx
  UFG::PowerManagementComponent *v19; // rbx
  UFG::qReflectHandleBase v20; // [rsp+28h] [rbp-30h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
      }
      else
      {
        v5 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::ActionTreeComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
        m_pComponent = v5;
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
      ((void (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[8].__vecDelDtor)(m_pComponent);
  }
  v6 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 & 0x4000) != 0 )
    {
      v8 = (UFG::BaseAnimationComponent *)v6->m_Components.p[9].m_pComponent;
    }
    else if ( v7 >= 0 )
    {
      if ( (v7 & 0x2000) != 0 )
      {
        v8 = (UFG::BaseAnimationComponent *)v6->m_Components.p[8].m_pComponent;
      }
      else
      {
        v9 = (v7 & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::BaseAnimationComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(v6, UFG::BaseAnimationComponent::_TypeUID);
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
  v10 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 & 0x4000) != 0 || v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::TransformNodeComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v20);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v14);
        v20.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        v16 = *(_QWORD *)&ComponentOfType->mWorldTransform.v2.x;
        if ( v16 )
          UFG::qReflectHandleBase::operator=(&v20, (UFG::qReflectHandleBase *)(v16 + 224));
        if ( LODWORD(v20.mData[2].mBaseNode.mNeighbours[0]) == 2 )
        {
          z = ComponentOfType->mWorldVelocity.z;
          if ( (LOBYTE(z) & 2) != 0 && (LOBYTE(z) & 1) == 0 )
            ((void (__fastcall *)(UFG::TransformNodeComponent *))ComponentOfType->vfptr[16].__vecDelDtor)(ComponentOfType);
        }
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            ComponentOfType->m_pSimObject,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            ComponentOfType);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v20);
      }
      while ( ComponentOfType );
    }
  }
  p_mNext = (UFG::PowerManagementComponent *)&this->m_PowerManagedResourceList.mNode.mNext[-1].mNext;
  if ( p_mNext != (UFG::PowerManagementComponent *)&this->m_fPreventSuspendTimeS )
  {
    do
    {
      v19 = (UFG::PowerManagementComponent *)&p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::m_SafePointerList.mNode.mNext[-1].mNext;
      ((void (__fastcall *)(UFG::PowerManagementComponent *))p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr->__vecDelDtor)(p_mNext);
      p_mNext = v19;
    }
    while ( v19 != (UFG::PowerManagementComponent *)&this->m_fPreventSuspendTimeS );
  }
  this->m_ePowerStateEnum = ePOWER_STATE_SUSPENDED;
}

// File Line: 443
// RVA: 0x592120
void __fastcall UFG::PowerManagementComponent::gotoResuming(UFG::PowerManagementComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::BaseAnimationComponent *m_pComponent; // rax
  UFG::PowerManagementComponent *p_mNext; // rcx
  UFG::PowerManagementComponent *v6; // rbx
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *ComponentOfType; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *TypeName; // rax
  __int64 v13; // rdx
  float z; // eax
  UFG::qReflectHandleBase v15; // [rsp+28h] [rbp-30h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::BaseAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::BaseAnimationComponent *)m_pSimObject->m_Components.p[8].m_pComponent;
      else
        m_pComponent = (UFG::BaseAnimationComponent *)((m_Flags & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pSimObject,
                                                         UFG::BaseAnimationComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         m_pSimObject,
                                                         UFG::BaseAnimationComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::BaseAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
    }
    if ( m_pComponent )
      UFG::BaseAnimationComponent::RebindResources(m_pComponent);
  }
  p_mNext = (UFG::PowerManagementComponent *)&this->m_PowerManagedResourceList.mNode.mNext[-1].mNext;
  if ( p_mNext != (UFG::PowerManagementComponent *)&this->m_fPreventSuspendTimeS )
  {
    do
    {
      v6 = (UFG::PowerManagementComponent *)&p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::m_SafePointerList.mNode.mNext[-1].mNext;
      ((void (__fastcall *)(UFG::PowerManagementComponent *))p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[1].__vecDelDtor)(p_mNext);
      p_mNext = v6;
    }
    while ( v6 != (UFG::PowerManagementComponent *)&this->m_fPreventSuspendTimeS );
  }
  v7 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::TransformNodeComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v15);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
        v15.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        v13 = *(_QWORD *)&ComponentOfType->mWorldTransform.v2.x;
        if ( v13 )
          UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)(v13 + 224));
        if ( LODWORD(v15.mData[2].mBaseNode.mNeighbours[0]) == 2 )
        {
          z = ComponentOfType->mWorldVelocity.z;
          if ( (LOBYTE(z) & 2) == 0 || (LOBYTE(z) & 1) != 0 )
          {
            LOBYTE(v13) = 1;
            ComponentOfType->vfptr[15].__vecDelDtor(ComponentOfType, v13);
          }
        }
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            ComponentOfType->m_pSimObject,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            ComponentOfType);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
      }
      while ( ComponentOfType );
    }
  }
  this->m_ePowerStateEnum = ePOWER_STATE_RESUMING;
}

// File Line: 486
// RVA: 0x591EE0
void __fastcall UFG::PowerManagementComponent::gotoResumed(UFG::PowerManagementComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  __int16 v7; // dx
  UFG::SimComponent *v8; // rcx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *ComponentOfType; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v14; // rcx
  const char *TypeName; // rax
  __int64 v16; // rdx
  float z; // eax
  UFG::qReflectHandleBase v18; // [rsp+28h] [rbp-30h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
      }
      else
      {
        v5 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::ActionTreeComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
        m_pComponent = v5;
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
      ((void (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[9].__vecDelDtor)(m_pComponent);
  }
  v6 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 & 0x4000) != 0 )
    {
      v8 = v6->m_Components.p[9].m_pComponent;
    }
    else if ( v7 >= 0 )
    {
      if ( (v7 & 0x2000) != 0 )
      {
        v8 = v6->m_Components.p[8].m_pComponent;
      }
      else
      {
        v9 = (v7 & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::BaseAnimationComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(v6, UFG::BaseAnimationComponent::_TypeUID);
        v8 = v9;
      }
    }
    else
    {
      v8 = v6->m_Components.p[9].m_pComponent;
    }
    if ( v8 )
      ((void (__fastcall *)(UFG::SimComponent *))v8->vfptr[9].__vecDelDtor)(v8);
  }
  v10 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 & 0x4000) != 0 || v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::TransformNodeComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v18);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v14);
        v18.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        v16 = *(_QWORD *)&ComponentOfType->mWorldTransform.v2.x;
        if ( v16 )
          UFG::qReflectHandleBase::operator=(&v18, (UFG::qReflectHandleBase *)(v16 + 224));
        if ( LODWORD(v18.mData[2].mBaseNode.mNeighbours[0]) == 2 )
        {
          z = ComponentOfType->mWorldVelocity.z;
          if ( (LOBYTE(z) & 2) == 0 || (LOBYTE(z) & 1) != 0 )
          {
            LOBYTE(v16) = 1;
            ComponentOfType->vfptr[15].__vecDelDtor(ComponentOfType, v16);
          }
        }
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            ComponentOfType->m_pSimObject,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            ComponentOfType);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
      }
      while ( ComponentOfType );
    }
  }
  this->m_ePowerStateEnum = ePOWER_STATE_NORMAL;
}

// File Line: 529
// RVA: 0x58B340
void __fastcall UFG::PowerManagementComponent::Reset(UFG::PowerManagementComponent *this)
{
  if ( this->m_ePowerStateEnum )
  {
    UFG::PowerManagementComponent::gotoResuming(this);
    UFG::PowerManagementComponent::gotoResumed(this);
    this->m_fPreventSuspendTimeS = -1.0;
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
  if ( this->m_ePowerStateEnum )
  {
    UFG::PowerManagementComponent::gotoResuming(this);
    this->m_fPreventSuspendTimeS = 3.4028235e38;
  }
  else
  {
    this->m_fPreventSuspendTimeS = 3.4028235e38;
  }
}

// File Line: 583
// RVA: 0x588930
void __fastcall UFG::PowerManagementComponent::PreventSuspendTemporarily(
        UFG::PowerManagementComponent *this,
        float fTimeS)
{
  if ( this->m_ePowerStateEnum )
    UFG::PowerManagementComponent::gotoResuming(this);
  if ( this->m_fPreventSuspendTimeS < 3.4028235e38 )
    this->m_fPreventSuspendTimeS = fTimeS;
}

// File Line: 610
// RVA: 0x5885F0
void __fastcall UFG::PowerManagementComponent::PermanentlySuspend(UFG::PowerManagementComponent *this)
{
  if ( (unsigned int)(this->m_ePowerStateEnum - 1) <= 1 )
  {
    this->m_ePowerStateEnum = ePOWER_STATE_SUSPENDED_PERMANENTLY;
  }
  else
  {
    UFG::PowerManagementComponent::gotoSuspended(this);
    this->m_ePowerStateEnum = ePOWER_STATE_SUSPENDED_PERMANENTLY;
  }
}

// File Line: 626
// RVA: 0x57EF40
void __fastcall UFG::PowerManagementComponent::AddPowerManagedResource(
        UFG::PowerManagementComponent *this,
        UFG::PowerManagedResource *pPowerManagedResource)
{
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mPrev; // rax
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v3; // rdx
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0> *p_m_PowerManagedResourceList; // rcx

  mPrev = this->m_PowerManagedResourceList.mNode.mPrev;
  v3 = &pPowerManagedResource->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  p_m_PowerManagedResourceList = &this->m_PowerManagedResourceList;
  mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = &p_m_PowerManagedResourceList->mNode;
  p_m_PowerManagedResourceList->mNode.mPrev = v3;
}

// File Line: 633
// RVA: 0x57EF60
void __fastcall UFG::PowerManagementComponent::AddPreventSuspendRefCount(UFG::PowerManagementComponent *this)
{
  ++this->m_cPreventSuspendRefCount;
}

// File Line: 646
// RVA: 0x58AFD0
void __fastcall UFG::PowerManagementComponent::RemovePreventSuspendRefCount(UFG::PowerManagementComponent *this)
{
  char m_cPreventSuspendRefCount; // al

  m_cPreventSuspendRefCount = this->m_cPreventSuspendRefCount;
  if ( m_cPreventSuspendRefCount > 0 )
    this->m_cPreventSuspendRefCount = m_cPreventSuspendRefCount - 1;
}

