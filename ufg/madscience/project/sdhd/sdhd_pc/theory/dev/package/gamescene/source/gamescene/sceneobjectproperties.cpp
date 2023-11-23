// File Line: 48
// RVA: 0x23E2A0
__int64 __fastcall UFG::PhantomVolumeComponent::GetTypeSize(
        UFG::qReflectInventory<UFG::PhysicsSurfaceProperties> *this)
{
  return 168i64;
}

// File Line: 94
// RVA: 0x237B30
void __fastcall UFG::SceneObjectProperties::SceneObjectProperties(
        UFG::SceneObjectProperties *this,
        UFG::qSymbol *name,
        UFG::SceneLayerResource *pLayerResource,
        UFG::qPropertySet *pLocalProperties,
        UFG::SceneObjectProperties *pParent,
        bool isChild)
{
  UFG::qPropertySet *ContainedSet; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v12; // rax

  UFG::SimComponent::SimComponent(this, name->mUID);
  this->mPrev = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  this->mNext = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneObjectProperties::`vftable;
  this->mpOwner.mPrev = &this->mpOwner;
  this->mpOwner.mNext = &this->mpOwner;
  this->mpOwner.m_pPointer = 0i64;
  this->mpLayerResource = pLayerResource;
  this->mpParent = 0i64;
  *(_QWORD *)&this->mChildren.mCount = 0i64;
  this->mChildren.mppArray = 0i64;
  this->mDeleteChildSimObjectOnDestruct = 1;
  this->mLastTeleportFrame = 0;
  this->mPrevNameHash = 0;
  this->mChildIndex = -1;
  UFG::SimComponent::AddType(this, UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID, "SceneObjectProperties");
  if ( isChild )
  {
    this->mpConstProperties = 0i64;
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&pLocalProperties->mName, "ChildProperties");
    this->mpWritableProperties = ContainedSet;
    UFG::qPropertySet::CopyFrom(ContainedSet, pLocalProperties, 1);
    mpWritableProperties = this->mpWritableProperties;
  }
  else if ( pLocalProperties )
  {
    this->mpConstProperties = pLocalProperties;
    this->mpWritableProperties = 0i64;
    mpWritableProperties = pLocalProperties;
  }
  else
  {
    v12 = UFG::qPropertySet::CreateContainedSet(name, "SceneObject_PropertySet");
    this->mpWritableProperties = v12;
    this->mpConstProperties = 0i64;
    mpWritableProperties = v12;
  }
  UFG::qPropertySet::AddRef(mpWritableProperties);
  UFG::SceneObjectProperties::SetParent(this, pParent);
  if ( this->mpParent )
    this->m_Flags &= ~8u;
  else
    this->m_Flags |= 8u;
}

// File Line: 142
// RVA: 0x237CA0
void __fastcall UFG::SceneObjectProperties::SceneObjectProperties(
        UFG::SceneObjectProperties *this,
        UFG::qPropertySet *pParentPropertySet,
        UFG::SceneLayerResource *pLayerResource)
{
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v6; // rsi
  UFG::SceneLayerResource *mpLayerResource; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *p_mNode; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, 0);
  v6 = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  this->mPrev = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  this->mNext = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneObjectProperties::`vftable;
  this->mpOwner.mPrev = &this->mpOwner;
  this->mpOwner.mNext = &this->mpOwner;
  this->mpOwner.m_pPointer = 0i64;
  this->mpLayerResource = pLayerResource;
  this->mpParent = 0i64;
  *(_QWORD *)&this->mChildren.mCount = 0i64;
  this->mChildren.mppArray = 0i64;
  this->mDeleteChildSimObjectOnDestruct = 1;
  this->mPrevNameHash = 0;
  this->mChildIndex = -1;
  UFG::SimComponent::AddType(this, UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID, "SceneObjectProperties");
  if ( this->mpParent )
    this->m_Flags &= ~8u;
  else
    this->m_Flags |= 8u;
  this->mpConstProperties = pParentPropertySet;
  UFG::qPropertySet::AddRef(pParentPropertySet);
  this->mpWritableProperties = 0i64;
  this->m_NameUID = pParentPropertySet->mName.mUID;
  mpLayerResource = this->mpLayerResource;
  if ( mpLayerResource )
  {
    p_mNode = &mpLayerResource->mObjects.mNode;
    mPrev = p_mNode->mPrev;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    this->mNext = p_mNode;
    p_mNode->mPrev = v6;
  }
  UFG::SceneObjectProperties::InstantiateChildObjects(this, 0);
}

// File Line: 161
// RVA: 0x14753A0
__int64 UFG::_dynamic_initializer_for__gLocalPropertySet__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("WritableSceneObjProperties", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gLocalPropertySet, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gLocalPropertySet__);
}

// File Line: 165
// RVA: 0x23E2F0
UFG::qPropertySet *__fastcall UFG::SceneObjectProperties::GetWritableProperties(UFG::SceneObjectProperties *this)
{
  UFG::qPropertySet *result; // rax
  UFG::qPropertySet *ContainedSet; // rax

  result = this->mpWritableProperties;
  if ( !result )
  {
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gLocalPropertySet, "WritableSceneObjProperties");
    this->mpWritableProperties = ContainedSet;
    UFG::qPropertySet::AddRef(ContainedSet);
    UFG::PSWrapper::AppendParentLocal(this->mpWritableProperties, this->mpConstProperties);
    return this->mpWritableProperties;
  }
  return result;
}

// File Line: 183
// RVA: 0x23E2D0
UFG::qPropertySet *__fastcall UFG::SceneObjectProperties::GetWritablePersistentProperties(
        UFG::SceneObjectProperties *this)
{
  UFG::qPropertySet *result; // rax

  result = this->mpConstProperties;
  if ( !result )
    return this->mpWritableProperties;
  return result;
}

// File Line: 197
// RVA: 0x23BFE0
UFG::qResourceData *__fastcall UFG::SceneObjectProperties::GetArchetypeProperties(UFG::SceneObjectProperties *this)
{
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpConstProperties = this->mpConstProperties;
  if ( !mpConstProperties )
    mpConstProperties = this->mpWritableProperties;
  if ( !(unsigned int)UFG::qPropertySet::NumParents(mpConstProperties) )
    return 0i64;
  mpWritableProperties = this->mpConstProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = this->mpWritableProperties;
  return UFG::qPropertySet::GetParentFromIdx(mpWritableProperties, 0);
}

// File Line: 228
// RVA: 0x23C030
UFG::qSymbol *__fastcall UFG::SceneObjectProperties::GetArchetypePropertiesName(UFG::SceneObjectProperties *this)
{
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qResourceData *ParentFromIdx; // rax

  mpConstProperties = this->mpConstProperties;
  if ( !mpConstProperties )
    mpConstProperties = this->mpWritableProperties;
  if ( !(unsigned int)UFG::qPropertySet::NumParents(mpConstProperties) )
    return &UFG::gNullQSymbol;
  mpWritableProperties = this->mpConstProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = this->mpWritableProperties;
  ParentFromIdx = UFG::qPropertySet::GetParentFromIdx(mpWritableProperties, 0);
  if ( ParentFromIdx )
    return (UFG::qSymbol *)&ParentFromIdx->mDebugName[12];
  else
    return &UFG::gNullQSymbol;
}

// File Line: 248
// RVA: 0x23D8C0
UFG::SceneLayerResource *__fastcall UFG::SceneObjectProperties::GetLayer(UFG::SceneObjectProperties *this)
{
  UFG::SceneLayerResource *result; // rax

  result = this->mpLayerResource;
  if ( result )
    return (UFG::SceneLayerResource *)result->mpRuntimeSceneLayer;
  return result;
}

// File Line: 310
// RVA: 0x2386D0
void __fastcall UFG::SceneObjectProperties::~SceneObjectProperties(UFG::SceneObjectProperties *this)
{
  qSetLogical<UFG::SceneObjectProperties,UFG::qSymbol> *p_mChildren; // rsi
  unsigned int mCount; // r8d
  UFG::SceneObjectProperties **mppArray; // rcx
  UFG::SceneObjectProperties *v5; // rbx
  unsigned int v6; // r8d
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SceneObjectProperties **v8; // rcx
  int v9; // r8d
  UFG::SimObject *v10; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mPrev; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mNext; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpOwner; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v20; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v21; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneObjectProperties::`vftable;
  p_mChildren = &this->mChildren;
  mCount = this->mChildren.mCount;
  if ( mCount )
  {
    mppArray = this->mChildren.mppArray;
    v5 = *mppArray;
    v6 = mCount - 1;
    p_mChildren->mCount = v6;
    UFG::qMemMove(mppArray, (char *)mppArray + 8, 8 * v6);
    while ( v5 )
    {
      v5->mpParent = 0i64;
      m_pSimObject = v5->m_pSimObject;
      if ( m_pSimObject )
      {
        if ( this->mDeleteChildSimObjectOnDestruct )
        {
          if ( (this->m_Flags & 8) != 0 )
            v5->m_Flags |= 8u;
          UFG::SimObject::Destroy(m_pSimObject);
        }
      }
      else
      {
        v5->vfptr->__vecDelDtor(v5, 1u);
      }
      if ( !p_mChildren->mCount )
        break;
      v8 = p_mChildren->mppArray;
      v5 = *v8;
      v9 = p_mChildren->mCount - 1;
      p_mChildren->mCount = v9;
      UFG::qMemMove(v8, (char *)v8 + 8, 8 * v9);
    }
  }
  UFG::SceneObjectProperties::SetParent(this, 0i64);
  v10 = this->m_pSimObject;
  if ( v10 )
    v10->m_pSceneObj = 0i64;
  if ( this->mpLayerResource )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
    this->mNext = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  }
  mpWritableProperties = this->mpWritableProperties;
  if ( mpWritableProperties )
  {
    UFG::qPropertySet::ReleaseRef(mpWritableProperties);
    this->mpWritableProperties = 0i64;
  }
  mpConstProperties = this->mpConstProperties;
  if ( mpConstProperties )
  {
    UFG::qPropertySet::ReleaseRef(mpConstProperties);
    this->mpConstProperties = 0i64;
  }
  operator delete[](p_mChildren->mppArray);
  p_mpOwner = &this->mpOwner;
  if ( this->mpOwner.m_pPointer )
  {
    v16 = p_mpOwner->mPrev;
    v17 = this->mpOwner.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_mpOwner->mPrev = p_mpOwner;
    this->mpOwner.mNext = &this->mpOwner;
  }
  this->mpOwner.m_pPointer = 0i64;
  v18 = p_mpOwner->mPrev;
  v19 = this->mpOwner.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  p_mpOwner->mPrev = p_mpOwner;
  this->mpOwner.mNext = &this->mpOwner;
  v20 = this->mPrev;
  v21 = this->mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  this->mPrev = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  this->mNext = &this->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 426
// RVA: 0x23A450
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::Create(
        UFG::qSymbol *objName,
        UFG::SceneLayer *pOwnerLayer,
        UFG::qPropertySet *parentSet)
{
  UFG::SceneObjectProperties *v5; // rbx
  UFG::SceneLayerResource *p_mNext; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SceneObjectProperties *v9; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *ContainedSet; // rax
  UFG::SceneLayerResource *mpLayerResource; // rdx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *p_mNode; // rdx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mPrev; // rax

  v5 = 0i64;
  p_mNext = 0i64;
  if ( pOwnerLayer && (UFG::qBox *)&pOwnerLayer->mLayerResources.mNode.mNext[-6].mNext != &pOwnerLayer[-1].mBox )
    p_mNext = (UFG::SceneLayerResource *)&pOwnerLayer->mLayerResources.mNode.mNext[-6].mNext;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA8ui64, "SceneObjectProperties", 0i64, 1u);
  if ( v8 )
  {
    UFG::SceneObjectProperties::SceneObjectProperties((UFG::SceneObjectProperties *)v8, objName, p_mNext, 0i64, 0i64, 0);
    v5 = v9;
  }
  mpWritableProperties = v5->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gLocalPropertySet, "WritableSceneObjProperties");
    v5->mpWritableProperties = ContainedSet;
    UFG::qPropertySet::AddRef(ContainedSet);
    UFG::PSWrapper::AppendParentLocal(v5->mpWritableProperties, v5->mpConstProperties);
    mpWritableProperties = v5->mpWritableProperties;
  }
  UFG::PSWrapper::AppendParentLocal(mpWritableProperties, parentSet);
  mpLayerResource = v5->mpLayerResource;
  if ( mpLayerResource )
  {
    p_mNode = &mpLayerResource->mObjects.mNode;
    mPrev = p_mNode->mPrev;
    mPrev->mNext = &v5->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
    v5->mPrev = mPrev;
    v5->mNext = p_mNode;
    p_mNode->mPrev = &v5->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  }
  UFG::SceneObjectProperties::InstantiateChildObjects(v5, 0);
  return v5;
}

// File Line: 450
// RVA: 0x23A580
UFG::allocator::free_link *__fastcall UFG::SceneObjectProperties::Create(
        unsigned int prevNameUID,
        UFG::qPropertySet *parentSet,
        unsigned int child_index)
{
  unsigned __int64 v6; // rdx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  UFG::qPropertySet *ContainedSet; // rax
  UFG::qPropertySet *mNext; // rcx
  UFG::qPropertySet *v12; // rax
  UFG::allocator::free_link *v13; // r8
  UFG::allocator::free_link *v14; // r8
  UFG::allocator::free_link *v15; // rcx
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+8h] BYREF
  UFG::allocator::free_link *v18; // [rsp+78h] [rbp+10h]
  UFG::allocator::free_link *v19; // [rsp+88h] [rbp+20h]

  v6 = ~(prevNameUID | ((unsigned __int64)parentSet->mName.mUID << 32))
     + ((prevNameUID | ((unsigned __int64)parentSet->mName.mUID << 32)) << 18);
  UFG::qSymbol::qSymbol(
    &result,
    (65 * ((21 * (v6 ^ (v6 >> 31))) ^ ((21 * (v6 ^ (v6 >> 31))) >> 11))) ^ ((65
                                                                           * ((21 * (v6 ^ (v6 >> 31))) ^ ((21 * (v6 ^ (v6 >> 31))) >> 11))) >> 22));
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA8ui64, "SceneObjectProperties", 0i64, 1u);
  v9 = v8;
  v18 = v8;
  if ( v8 )
  {
    UFG::SimComponent::SimComponent((UFG::SimComponent *)v8, result.mUID);
    v9[8].mNext = v9 + 8;
    v9[9].mNext = v9 + 8;
    v9->mNext = (UFG::allocator::free_link *)&UFG::SceneObjectProperties::`vftable;
    v9[10].mNext = v9 + 10;
    v9[11].mNext = v9 + 10;
    v9[12].mNext = 0i64;
    v9[13].mNext = 0i64;
    v9[14].mNext = 0i64;
    v19 = v9 + 15;
    v9[15].mNext = 0i64;
    v9[16].mNext = 0i64;
    LOBYTE(v9[17].mNext) = 1;
    HIDWORD(v9[17].mNext) = 0;
    LODWORD(v9[20].mNext) = 0;
    HIDWORD(v9[20].mNext) = -1;
    UFG::SimComponent::AddType(
      (UFG::SimComponent *)v9,
      UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID,
      "SceneObjectProperties");
    ContainedSet = UFG::qPropertySet::CreateContainedSet((UFG::qSymbol *)&result, "SceneObject_PropertySet");
    v9[18].mNext = (UFG::allocator::free_link *)ContainedSet;
    v9[19].mNext = 0i64;
    UFG::qPropertySet::AddRef(ContainedSet);
    UFG::SceneObjectProperties::SetParent((UFG::SceneObjectProperties *)v9, 0i64);
    if ( v9[14].mNext )
      LOWORD(v9[4].mNext) &= ~8u;
    else
      LOWORD(v9[4].mNext) |= 8u;
  }
  else
  {
    v9 = 0i64;
  }
  mNext = (UFG::qPropertySet *)v9[18].mNext;
  if ( !mNext )
  {
    v12 = UFG::qPropertySet::CreateContainedSet(&UFG::gLocalPropertySet, "WritableSceneObjProperties");
    v9[18].mNext = (UFG::allocator::free_link *)v12;
    UFG::qPropertySet::AddRef(v12);
    UFG::PSWrapper::AppendParentLocal((UFG::qPropertySet *)v9[18].mNext, (UFG::qPropertySet *)v9[19].mNext);
    mNext = (UFG::qPropertySet *)v9[18].mNext;
  }
  UFG::PSWrapper::AppendParentLocal(mNext, parentSet);
  LODWORD(v9[20].mNext) = prevNameUID;
  HIDWORD(v9[20].mNext) = child_index;
  v13 = v9[13].mNext;
  if ( v13 )
  {
    v14 = v13 + 18;
    v15 = v14->mNext;
    v15[1].mNext = v9 + 8;
    v9[8].mNext = v15;
    v9[9].mNext = v14;
    v14->mNext = v9 + 8;
  }
  UFG::SceneObjectProperties::InstantiateChildObjects((UFG::SceneObjectProperties *)v9, prevNameUID);
  return v9;
}

// File Line: 487
// RVA: 0x23A420
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::Create(
        UFG::qSymbol *objName,
        UFG::SceneLayer *pOwnerLayer,
        UFG::qSymbol *parentSetName)
{
  UFG::qPropertySet *PropertySet; // rax

  PropertySet = UFG::PropertySetManager::GetPropertySet(parentSetName);
  return UFG::SceneObjectProperties::Create(objName, pOwnerLayer, PropertySet);
}

// File Line: 503
// RVA: 0x239AA0
UFG::SimObject *__fastcall UFG::SceneObjectProperties::Activate(
        UFG::SceneObjectProperties *this,
        unsigned int instantiateFlags,
        UFG::qMatrix44 *pXFormOverride,
        UFG::TransformNodeComponent *parentTransform)
{
  UFG::qPropertySet *v8; // rax
  UFG::qPropertySet *mpWritableProperties; // rdi
  UFG::qSymbol *v10; // rax
  UFG::SimObject *SimObject; // rax
  UFG::qSymbol *v12; // rax
  UFG::SimObject *v13; // rdi
  UFG::qWiseSymbol result; // [rsp+20h] [rbp-18h] BYREF
  UFG::qWiseSymbol v16; // [rsp+24h] [rbp-14h] BYREF
  UFG::qSymbol v17; // [rsp+40h] [rbp+8h] BYREF

  if ( this->m_pSimObject )
    return 0i64;
  if ( !instantiateFlags )
    return 0i64;
  v8 = PropertyUtils::Get<unsigned long>(this, (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
  if ( !v8 || (instantiateFlags & v8->mFlags) == 0 )
    return 0i64;
  v17.mUID = UFG::gNullQSymbol.mUID;
  if ( UFG::SceneObjectProperties::mspSimObjectFactoryFunc )
  {
    mpWritableProperties = this->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = this->mpConstProperties;
    v10 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, this->m_NameUID);
    SimObject = UFG::SceneObjectProperties::mspSimObjectFactoryFunc(mpWritableProperties, v10, &v17);
  }
  else
  {
    v12 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v16, this->m_NameUID);
    SimObject = UFG::Simulation::CreateSimObject(&UFG::gSim, v12);
  }
  v13 = SimObject;
  SimObject->m_pSceneObj = this;
  ((void (__fastcall *)(UFG::SimObject *, UFG::SceneObjectProperties *, __int64))SimObject->vfptr[1].__vecDelDtor)(
    SimObject,
    this,
    0xFFFFFFFFi64);
  UFG::SimObject::StartDeferringAttachment(v13);
  UFG::SceneObjectProperties::mspActivateFunc(this, pXFormOverride, &v17, parentTransform);
  UFG::SimObject::EndDeferringAttachment(v13);
  UFG::SceneObjectProperties::ActivateChildObjects(this);
  return v13;
}

// File Line: 548
// RVA: 0x239BC0
__int64 __fastcall UFG::SceneObjectProperties::ActivateChildObjects(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties **mppArray; // rbx
  unsigned int v2; // edi
  UFG::SceneObjectProperties **i; // rsi

  mppArray = this->mChildren.mppArray;
  v2 = 0;
  for ( i = &mppArray[this->mChildren.mCount]; mppArray < i; ++mppArray )
  {
    if ( UFG::SceneObjectProperties::Activate(*mppArray, 1u, 0i64, 0i64) )
      ++v2;
  }
  return v2;
}

// File Line: 574
// RVA: 0x23EA50
__int64 __fastcall UFG::SceneObjectProperties::InstantiateChildObjects(
        UFG::SceneObjectProperties *this,
        unsigned int prevNameUID)
{
  unsigned int v2; // ebx
  unsigned int v4; // esi
  UFG::qPropertySet *mpWritableProperties; // rcx
  char *ValuePtr; // rax
  __int64 v7; // rcx
  UFG::qPropertyList *v8; // r9
  unsigned int mNumElements; // ecx
  UFG::qPropertySet *mpConstProperties; // rax
  char *v11; // rax
  UFG::qPropertySet *v12; // rsi
  char *v13; // rbx
  UFG::qSymbol *ParentFromIdx; // rax
  unsigned int mUID; // eax
  unsigned __int64 v16; // rax
  char *v17; // rbx
  UFG::qSymbol *v18; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::SceneObjectProperties *v21; // rax
  UFG::SceneObjectProperties *v22; // rbx
  unsigned int v23; // eax
  int v24; // esi
  UFG::SceneLayerResource *mpLayerResource; // rcx
  unsigned int v27; // [rsp+30h] [rbp-D0h]
  unsigned int v28; // [rsp+34h] [rbp-CCh]
  UFG::qPropertySet *owningSet; // [rsp+38h] [rbp-C8h] BYREF
  UFG::qSymbol v30; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qPropertyList *v31; // [rsp+48h] [rbp-B8h]
  UFG::qWiseSymbol v32; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qWiseSymbol v33; // [rsp+54h] [rbp-ACh] BYREF
  UFG::qSymbol result; // [rsp+58h] [rbp-A8h] BYREF
  __int64 v35; // [rsp+60h] [rbp-A0h]
  UFG::allocator::free_link *v36; // [rsp+68h] [rbp-98h]
  char dest[2]; // [rsp+70h] [rbp-90h] BYREF
  _WORD Dst[511]; // [rsp+72h] [rbp-8Eh] BYREF
  bool v39; // [rsp+4A0h] [rbp+3A0h]
  UFG::qSymbol name; // [rsp+4B0h] [rbp+3B0h] BYREF
  unsigned int v42; // [rsp+4B8h] [rbp+3B8h]

  v35 = -2i64;
  v2 = prevNameUID;
  v4 = 0;
  owningSet = 0i64;
  mpWritableProperties = this->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = this->mpConstProperties;
  ValuePtr = UFG::qPropertySet::GetValuePtr(
               mpWritableProperties,
               0x19u,
               SimSym_SimObjChildren.mUID,
               DEPTH_RECURSE,
               &owningSet);
  if ( !ValuePtr )
    return 0i64;
  v7 = *(_QWORD *)ValuePtr;
  if ( !*(_QWORD *)ValuePtr )
    return 0i64;
  v8 = (UFG::qPropertyList *)&ValuePtr[v7];
  v31 = (UFG::qPropertyList *)&ValuePtr[v7];
  if ( !&ValuePtr[v7] )
    return 0i64;
  mNumElements = v8->mNumElements;
  v28 = mNumElements;
  if ( !mNumElements )
    return 0i64;
  mpConstProperties = this->mpConstProperties;
  if ( !mpConstProperties )
    mpConstProperties = this->mpWritableProperties;
  v39 = mpConstProperties == owningSet;
  v42 = 0;
  v27 = mNumElements;
  do
  {
    v11 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v4);
    if ( v11 && *(_QWORD *)v11 )
      v12 = (UFG::qPropertySet *)&v11[*(_QWORD *)v11];
    else
      v12 = 0i64;
    name.mUID = -1;
    if ( v2 )
    {
      name.mUID = v12->mName.mUID;
      v13 = UFG::qPropertySet::Get<char const *>(v12, (UFG::qArray<unsigned long,0> *)&SimSym_NameRoot, DEPTH_RECURSE);
      if ( v13 )
      {
        strcpy(dest, ":");
        memset(Dst, 0, sizeof(Dst));
        UFG::qStringCopy(&dest[1], 0x7FFFFFFF, v13, -1);
        ParentFromIdx = (UFG::qSymbol *)this->mpConstProperties;
        if ( !ParentFromIdx )
        {
          if ( this->mpParent )
            ParentFromIdx = (UFG::qSymbol *)this->mpWritableProperties;
          else
            ParentFromIdx = (UFG::qSymbol *)UFG::qPropertySet::GetParentFromIdx(this->mpWritableProperties, 0);
        }
        mUID = UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&result, ParentFromIdx + 16, dest)->mUID;
        name.mUID = mUID;
      }
      else
      {
        mUID = name.mUID;
      }
      v16 = 21
          * ((((prevNameUID | ((unsigned __int64)mUID << 32)) << 18) + ~(prevNameUID | ((unsigned __int64)mUID << 32))) ^ ((((prevNameUID | ((unsigned __int64)mUID << 32)) << 18) + ~(prevNameUID | ((unsigned __int64)mUID << 32))) >> 31));
      name.mUID = UFG::qSymbol::qSymbol(&v33, (65 * (v16 ^ (v16 >> 11))) ^ ((65 * (v16 ^ (v16 >> 11))) >> 22))->mUID;
    }
    else if ( v39 )
    {
      name.mUID = v12->mName.mUID;
    }
    else
    {
      v17 = UFG::qPropertySet::Get<char const *>(v12, (UFG::qArray<unsigned long,0> *)&SimSym_NameRoot, DEPTH_RECURSE);
      strcpy(dest, ":");
      memset(Dst, 0, sizeof(Dst));
      UFG::qStringCopy(&dest[1], 0x7FFFFFFF, v17, -1);
      v18 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v32, this->m_NameUID);
      name.mUID = UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&v30, v18, dest)->mUID;
    }
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v20 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA8ui64, "SceneObjectProperties", 0i64, 1u);
    v36 = v20;
    if ( v20 )
    {
      UFG::SceneObjectProperties::SceneObjectProperties(
        (UFG::SceneObjectProperties *)v20,
        &name,
        this->mpLayerResource,
        v12,
        this,
        1);
      v22 = v21;
    }
    else
    {
      v22 = 0i64;
    }
    v23 = prevNameUID;
    v22->mPrevNameHash = prevNameUID;
    v24 = v42;
    v22->mChildIndex = v42;
    mpLayerResource = v22->mpLayerResource;
    if ( mpLayerResource )
    {
      UFG::SceneLayerResource::AddSOP(mpLayerResource, v22);
      v23 = prevNameUID;
    }
    UFG::SceneObjectProperties::InstantiateChildObjects(v22, v23);
    v4 = v24 + 1;
    v42 = v4;
    v2 = prevNameUID;
    v8 = v31;
  }
  while ( v4 < v28 );
  if ( this->m_pSimObject )
    UFG::SceneObjectProperties::ActivateChildObjects(this);
  return v27;
}

// File Line: 683
// RVA: 0x2464C0
void __fastcall UFG::SceneObjectProperties::UninstantiateChildObjects(UFG::SceneObjectProperties *this)
{
  unsigned int mCount; // r8d
  UFG::SceneObjectProperties **mppArray; // rcx
  unsigned int v4; // r8d
  UFG::SceneObjectProperties *v5; // rbx
  unsigned int v6; // r8d
  UFG::SceneObjectProperties **v7; // rcx
  unsigned int v8; // r8d

  mCount = this->mChildren.mCount;
  if ( mCount )
  {
    mppArray = this->mChildren.mppArray;
    v4 = mCount - 1;
    v5 = *mppArray;
    this->mChildren.mCount = v4;
    UFG::qMemMove(mppArray, (char *)mppArray + 8, 8 * v4);
    while ( v5 )
    {
      v5->vfptr->__vecDelDtor(v5, 1u);
      v6 = this->mChildren.mCount;
      if ( !v6 )
        break;
      v7 = this->mChildren.mppArray;
      v8 = v6 - 1;
      v5 = *v7;
      this->mChildren.mCount = v8;
      UFG::qMemMove(v7, (char *)v7 + 8, 8 * v8);
    }
  }
}

// File Line: 697
// RVA: 0x23ACC0
void __fastcall UFG::SceneObjectProperties::Deactivate(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties::Deactivate(this, 3);
}

// File Line: 702
// RVA: 0x23AE00
void __fastcall UFG::SceneObjectProperties::DeactivateDeferred(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties::Deactivate(this, 4);
}

// File Line: 712
// RVA: 0x23AB70
void __fastcall UFG::SceneObjectProperties::Deactivate(UFG::SceneObjectProperties *this, char createObjectFlags)
{
  UFG::SimObject *m_pSimObject; // rbp
  char v5; // bl
  UFG::qPropertySet *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::SceneObjectProperties *mpParent; // rax
  __int64 v10; // rax
  UFG::SceneObjectProperties **v11; // rbx
  UFG::SceneObjectProperties **j; // rsi
  __int64 mCount; // rax
  UFG::SceneObjectProperties **mppArray; // rbx
  UFG::SceneObjectProperties **i; // rsi

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return;
  v5 = 0;
  if ( (m_pSimObject->m_Flags & 0x8000u) == 0 )
  {
    v6 = PropertyUtils::Get<unsigned long>(this, (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
    if ( v6 && (v6->mFlags & 4) != 0 )
    {
      v7 = PropertyUtils::Get<unsigned long>(this, (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
      if ( !v7 || (v7->mFlags & 4) == 0 || (createObjectFlags & 4) == 0 )
        goto LABEL_9;
    }
    else if ( (createObjectFlags & 4) == 0 )
    {
      mCount = this->mChildren.mCount;
      if ( (_DWORD)mCount )
      {
        mppArray = this->mChildren.mppArray;
        for ( i = &mppArray[mCount]; mppArray < i; ++mppArray )
          UFG::SceneObjectProperties::Deactivate(*mppArray, 3u);
      }
      goto LABEL_22;
    }
    v10 = this->mChildren.mCount;
    if ( (_DWORD)v10 )
    {
      v11 = this->mChildren.mppArray;
      for ( j = &v11[v10]; v11 < j; ++v11 )
        UFG::SceneObjectProperties::Deactivate(*v11, 4u);
    }
LABEL_22:
    UFG::SceneObjectProperties::mspDeactivateFunc(this);
    UFG::SimObject::Destroy(m_pSimObject);
    return;
  }
  v5 = 1;
LABEL_9:
  v8 = PropertyUtils::Get<unsigned long>(this, (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
  if ( v8 && (v8->mFlags & 4) != 0 || v5 )
  {
    UFG::SceneObjectProperties::OnOrphaned(this);
    mpParent = this->mpParent;
    if ( mpParent )
      mpParent->mDeleteChildSimObjectOnDestruct = 0;
  }
}

// File Line: 775
// RVA: 0x243330
void __fastcall UFG::SceneObjectProperties::OnOrphaned(UFG::SceneObjectProperties *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx

  this->m_Flags |= 8u;
  if ( this->mpParent )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        if ( m_pTransformNodeComponent->mParent )
          UFG::TransformNodeComponent::SetParentKeepWorld(m_pTransformNodeComponent, 0i64, eInheritXform_Full);
      }
    }
    this->mpLayerResource = 0i64;
  }
  else
  {
    this->mpLayerResource = 0i64;
  }
}

// File Line: 801
// RVA: 0x243810
void __fastcall UFG::SceneObjectProperties::OnTeleportEvent(UFG::SceneObjectProperties *this, UFG::Event *event_p)
{
  this->mLastTeleportFrame = UFG::Metrics::msInstance.mSimFrameCount;
}

// File Line: 813
// RVA: 0x23BFB0
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::GetAncestor(
        UFG::SceneObjectProperties *this,
        unsigned int ancestorLevel)
{
  UFG::SceneObjectProperties *result; // rax

  if ( !ancestorLevel )
    return 0i64;
  result = this->mpParent;
  if ( !result )
    return 0i64;
  while ( ancestorLevel != 1 )
  {
    result = result->mpParent;
    --ancestorLevel;
    if ( !result )
      return 0i64;
  }
  return result;
}

// File Line: 835
// RVA: 0x23D3A0
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::GetChildAsSceneObject(
        UFG::SceneObjectProperties *this,
        unsigned int index)
{
  if ( index >= this->mChildren.mCount )
    return 0i64;
  else
    return this->mChildren.mppArray[index];
}

// File Line: 847
// RVA: 0x23D3C0
UFG::SimObject *__fastcall UFG::SceneObjectProperties::GetChildAsSimObject(
        UFG::SceneObjectProperties *this,
        unsigned int index)
{
  if ( index >= this->mChildren.mCount )
    return 0i64;
  else
    return this->mChildren.mppArray[index]->m_pSimObject;
}

// File Line: 859
// RVA: 0x245540
void __fastcall UFG::SceneObjectProperties::SetParent(
        UFG::SceneObjectProperties *this,
        UFG::SceneObjectProperties *pParent)
{
  UFG::SceneObjectProperties *mpParent; // rax
  UFG::SceneObjectProperties *v5; // r14
  unsigned int mCount; // eax
  UFG::SceneObjectProperties **mppArray; // rbx
  UFG::SceneObjectProperties **v8; // r15
  UFG::SceneObjectProperties **v9; // rcx
  UFG::qSymbol v10; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF

  mpParent = this->mpParent;
  if ( mpParent != pParent )
  {
    if ( mpParent )
    {
      UFG::SceneObjectProperties::operator UFG::qSymbol const(this, &result);
      v5 = this->mpParent;
      mCount = v5->mChildren.mCount;
      if ( mCount )
      {
        mppArray = v5->mChildren.mppArray;
        v8 = &mppArray[mCount - 1];
        if ( mppArray <= v8 )
        {
          while ( 1 )
          {
            UFG::SceneObjectProperties::operator UFG::qSymbol const(*mppArray, &v10);
            if ( result.mUID == v10.mUID )
              break;
            if ( ++mppArray > v8 )
              goto LABEL_8;
          }
          v9 = v5->mChildren.mppArray;
          UFG::qMemMove(
            &v9[(unsigned int)(mppArray - v9)],
            (char *)&v9[(unsigned int)(mppArray - v9) + 1],
            8 * (--v5->mChildren.mCount - (mppArray - v9)));
        }
      }
    }
LABEL_8:
    this->mpParent = pParent;
    if ( pParent )
    {
      this->m_Flags &= ~8u;
      qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
        &pParent->mChildren,
        this,
        "SceneObjectProperties::mChildren");
    }
    else
    {
      this->m_Flags |= 8u;
    }
  }
}

// File Line: 884
// RVA: 0x23BD00
UFG::SceneLayer *__fastcall UFG::SceneObjectProperties::FindOwnerLayer(UFG::SceneObjectProperties *this)
{
  UFG::SimObject *m_pPointer; // rcx

  if ( this->mpLayerResource )
    return (UFG::SceneLayer *)this->mpLayerResource->mpRuntimeSceneLayer;
  while ( 1 )
  {
    m_pPointer = this->mpOwner.m_pPointer;
    if ( !m_pPointer )
      break;
    this = m_pPointer->m_pSceneObj;
    if ( !this )
      break;
    if ( this->mpLayerResource )
      return (UFG::SceneLayer *)this->mpLayerResource->mpRuntimeSceneLayer;
  }
  return 0i64;
}

