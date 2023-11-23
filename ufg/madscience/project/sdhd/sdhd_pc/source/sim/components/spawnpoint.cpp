// File Line: 90
// RVA: 0x1552400
__int64 UFG::_dynamic_initializer_for__gTrapDetachSpawnPoint__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NP_Park_Gardner_03-SP0003:spawn", 0xFFFFFFFF);
  UFG::gTrapDetachSpawnPoint = result;
  return result;
}

// File Line: 96
// RVA: 0x154D6D0
__int64 dynamic_initializer_for__UFG::SpawnPoint::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::SpawnPoint::AccessComponentDesc();
  *(_DWORD *)&UFG::SpawnPoint::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::SpawnPoint::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::SpawnPoint::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 98
// RVA: 0x154D890
__int64 dynamic_initializer_for__UFG::SpawnPoint::msSpawnPoints__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SpawnPoint::msSpawnPoints.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SpawnPoint::msSpawnPoints__);
}

// File Line: 102
// RVA: 0x154D8C0
__int64 dynamic_initializer_for__UFG::SpawnPoint::msSpawnPointsWithPendingLinks__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SpawnPoint::msSpawnPointsWithPendingLinks__);
}

// File Line: 140
// RVA: 0x57D120
void __fastcall UFG::SpawnPoint::SpawnPoint(UFG::SpawnPoint *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  unsigned int mUID; // eax

  UFG::SpawnPointInterface::SpawnPointInterface(this, name, pSimObj);
  this->mPrev = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
  this->mNext = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
  mUID = name->mUID;
  this->UFG::qNodeRB<UFG::SpawnPoint>::mNode.mParent = 0i64;
  this->UFG::qNodeRB<UFG::SpawnPoint>::mNode.mChild[0] = 0i64;
  this->UFG::qNodeRB<UFG::SpawnPoint>::mNode.mChild[1] = 0i64;
  this->UFG::qNodeRB<UFG::SpawnPoint>::mNode.mUID = mUID;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPoint::`vftable;
  this->mpSpawn.mPrev = &this->mpSpawn;
  this->mpSpawn.mNext = &this->mpSpawn;
  this->mpSpawn.m_pPointer = 0i64;
  this->mPendingLinks.mNode.mPrev = &this->mPendingLinks.mNode;
  this->mPendingLinks.mNode.mNext = &this->mPendingLinks.mNode;
  UFG::SimComponent::AddType(this, UFG::SpawnPoint::_SpawnPointTypeUID, "SpawnPoint");
  *(_WORD *)&this->mThugPoint = 0;
  this->mSpawnZoneIndex = -1;
}

// File Line: 152
// RVA: 0x583FA0
char __fastcall UFG::SpawnPoint::Initialize(UFG::SpawnPoint *this, UFG::SimObject *pSimObj)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *v3; // rdi
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  bool v6; // zf
  UFG::SimObject *v7; // rax
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::SceneObjectProperties *v9; // rdi
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *mpConstProperties; // rcx
  int *v12; // rax
  int v13; // ebp
  UFG::PedSpawnManager *Instance; // rax

  m_pSimObject = this->m_pSimObject;
  v3 = 0i64;
  once_5 = 0;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  v6 = (this->mFlags & 0x10000) == 0;
  this->mpSceneObj = m_pSceneObj;
  if ( !v6 )
    UFG::qBaseTreeRB::Add(&UFG::SpawnPoint::msSpawnPoints.mTree, &this->UFG::qNodeRB<UFG::SpawnPoint>::mNode);
  v7 = this->m_pSimObject;
  if ( v7 )
    v3 = v7->m_pSceneObj;
  ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(v3, 0);
  v9 = ChildAsSceneObject;
  if ( ChildAsSceneObject )
  {
    mpWritableProperties = ChildAsSceneObject->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = ChildAsSceneObject->mpConstProperties;
    UFG::SpawnInfoInterface::GetSpawnPriority(mpWritableProperties, &this->mSpawnPriority);
    mpConstProperties = v9->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = v9->mpConstProperties;
    v12 = PropertyUtils::Get<long>(mpConstProperties, (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnChance, DEPTH_LOCAL);
    if ( v12 )
      v13 = *v12;
    else
      v13 = 100;
    if ( UFG::SpawnInfoInterface::IsCharacter(v9) && this->mSpawnPriority )
    {
      Instance = UFG::PedSpawnManager::GetInstance();
      this->mSpawnZoneIndex = UFG::PedSpawnManager::RegisterActiveSpawnPoint(Instance, this, v9);
      this->mSkipSpawnChancePercent = (int)(float)(100.0
                                                 - (float)((float)v13
                                                         * UFG::PedSpawnManager::msPedDensityScaleSpawnPointAdjust));
    }
    else
    {
      this->mSkipSpawnChancePercent = 100 - v13;
    }
  }
  UFG::SpawnPoint::FillPendingLinks(this);
  return 1;
}

// File Line: 215
// RVA: 0x57DEB0
void __fastcall UFG::SpawnPoint::~SpawnPoint(UFG::SpawnPoint *this)
{
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *mPrev; // rcx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSpawn; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v9; // rcx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v10; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPoint::`vftable;
  if ( (this->mFlags & 0x10000) != 0 )
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::SpawnPoint::msSpawnPoints,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::SpawnPoint>);
  UFG::qList<UFG::PendingLink,UFG::PendingLink,1,0>::DeleteNodes(&this->mPendingLinks);
  mPrev = this->mPendingLinks.mNode.mPrev;
  mNext = this->mPendingLinks.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPendingLinks.mNode.mPrev = &this->mPendingLinks.mNode;
  this->mPendingLinks.mNode.mNext = &this->mPendingLinks.mNode;
  p_mpSpawn = &this->mpSpawn;
  if ( this->mpSpawn.m_pPointer )
  {
    v5 = p_mpSpawn->mPrev;
    v6 = this->mpSpawn.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    p_mpSpawn->mPrev = p_mpSpawn;
    this->mpSpawn.mNext = &this->mpSpawn;
  }
  this->mpSpawn.m_pPointer = 0i64;
  v7 = p_mpSpawn->mPrev;
  v8 = this->mpSpawn.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_mpSpawn->mPrev = p_mpSpawn;
  this->mpSpawn.mNext = &this->mpSpawn;
  v9 = this->mPrev;
  v10 = this->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mPrev = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
  this->mNext = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 224
// RVA: 0x582730
UFG::qBaseNodeRB **__fastcall UFG::SpawnPoint::GetNamed(UFG::qSymbol *name)
{
  UFG::qBaseTreeRB *v1; // rax

  if ( name->mUID && (v1 = UFG::qBaseTreeRB::Get(&UFG::SpawnPoint::msSpawnPoints.mTree, name->mUID)) != 0i64 )
    return &v1[-2].mRoot.mChild[1];
  else
    return 0i64;
}

// File Line: 235
// RVA: 0x586DE0
void __fastcall UFG::SpawnPoint::OnDetach(UFG::SpawnPoint *this)
{
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *mPrev; // rdx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *mNext; // rax
  UFG::qList<UFG::PendingLink,UFG::PendingLink,1,0> *p_mPendingLinks; // rdi
  UFG::PendingLink *v4; // rbx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v6; // rdx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v7; // rax
  UFG::PedSpawnManager *Instance; // rax
  UFG::SimObject *m_pSimObject; // rax
  unsigned int v10; // r15d
  unsigned int i; // ebp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *SceneObj; // rax
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::SceneObjectProperties *v14; // rsi
  UFG::SimObjectCharacter *v15; // rbx
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v17; // rax
  __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSymbol symbol; // [rsp+40h] [rbp+8h] BYREF

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mPendingLinks = &this->mPendingLinks;
  this->mPrev = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
  this->mNext = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
  v4 = (UFG::PendingLink *)this->mPendingLinks.mNode.mNext;
  if ( v4 != (UFG::PendingLink *)&this->mPendingLinks )
  {
    do
    {
      v6 = v4->mPrev;
      v7 = v4->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v4->mPrev = v4;
      v4->mNext = v4;
      UFG::PendingLink::~PendingLink(v4);
      operator delete[](v4);
      v4 = (UFG::PendingLink *)p_mPendingLinks->mNode.mNext;
    }
    while ( v4 != (UFG::PendingLink *)p_mPendingLinks );
  }
  this->mIsLinkPending = 0;
  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::UnRegisterActiveSpawnPoint(Instance, this, this->mpSceneObj);
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pSceneObj;
  v10 = (unsigned int)m_pSimObject->m_UnboundComponentHandles.mNode.mNext;
  for ( i = 0; i < v10; ++i )
  {
    SceneObj = UFG::SimComponent::GetSceneObj(this);
    ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject((UFG::SceneObjectProperties *)SceneObj, i);
    v14 = ChildAsSceneObject;
    if ( ChildAsSceneObject )
      v15 = (UFG::SimObjectCharacter *)ChildAsSceneObject->m_pSimObject;
    else
      v15 = 0i64;
    if ( v15 )
    {
      mpWritableProperties = ChildAsSceneObject->mpWritableProperties;
      LOBYTE(symbol.mUID) = 0;
      if ( !mpWritableProperties )
        mpWritableProperties = ChildAsSceneObject->mpConstProperties;
      v17 = UFG::qPropertySet::Get<bool>(
              mpWritableProperties,
              (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPoint_DeleteTargetOnDetach,
              DEPTH_RECURSE);
      if ( v17 && *v17 )
      {
        UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v15);
      }
      else
      {
        m_Flags = v15->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)v15->m_Components.p[10].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = (UFG::StreamedResourceComponent *)v15->m_Components.p[7].m_pComponent;
          }
          else
          {
            if ( (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v15,
                                    UFG::StreamedResourceComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v15, UFG::StreamedResourceComponent::_TypeUID);
            m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
          }
        }
        else
        {
          m_pComponent = (UFG::StreamedResourceComponent *)v15->m_Components.p[10].m_pComponent;
        }
        if ( m_pComponent )
        {
          symbol.mUID = m_pComponent->mActivePriority.mUID;
          UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(m_pComponent, &qSymbol_Low);
          UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(m_pComponent, &symbol);
        }
        UFG::SpawnInfoInterface::SetOwner(v15, 0i64);
        UFG::SimObjectUtility::ConditionSimObjectForAmbientWorld(v15);
        if ( (unsigned int)UFG::SimObjectPropertiesComponent::GetChildType(v14) == 1 )
          UFG::PedSpawnManager::ReleaseOwnership(v15, 4u, 0);
      }
    }
  }
}

// File Line: 313
// RVA: 0x58BBE0
void __fastcall UFG::SpawnPoint::SetupSpawnTarget(UFG::SpawnPoint *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::qPropertySet *mNext; // rbx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol targetNameOut; // [rsp+30h] [rbp+8h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pSceneObj;
  mNext = (UFG::qPropertySet *)m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
  if ( !mNext )
    mNext = (UFG::qPropertySet *)m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
  if ( UFG::qPropertySet::Get<UFG::qSymbol>(
         mNext,
         (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnTargetType,
         DEPTH_RECURSE) )
  {
    targetNameOut.mUID = -1;
    if ( UFG::GameplayUtil::ChooseSpawnTarget(&targetNameOut, mNext) )
    {
      PropertySet = UFG::PropertySetManager::GetPropertySet(&targetNameOut);
      if ( PropertySet )
        UFG::SpawnPoint::SetNewSpawnTarget(this, PropertySet);
    }
  }
}

// File Line: 335
// RVA: 0x58BFD0
UFG::SimObjectCharacter *__fastcall UFG::SpawnPoint::Spawn(
        UFG::SpawnPoint *this,
        bool skip_poi_links,
        bool from_skookum)
{
  char v3; // si
  UFG::Event *v5; // r15
  UFG::SimObjectCharacter *SimObject; // rdi
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *mPrev; // r9
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *mNext; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::SceneObjectProperties *v11; // rcx
  UFG::SceneObjectProperties *ChildAsSceneObject; // rsi
  bool v13; // r13
  UFG::SpawnInfoInterface::SpawnPriority m_NameUID; // r12d
  bool v15; // r14
  UFG::qPropertySet *mpWritableProperties; // rbx
  UFG::qSymbol *SpawnPriority; // rax
  unsigned int mUID; // eax
  UFG::ObjectResourceManager *v19; // rax
  int mSkipSpawnChancePercent; // r14d
  char *v21; // rax
  UFG::qPropertySet *RandomPropSetFromCurrentTrafficSet; // rbx
  UFG::ObjectResourceManager *v23; // rax
  UFG::qSymbol *v24; // rax
  UFG::TransformNodeComponent *mpXformNode; // r14
  UFG::allocator::free_link *v26; // r12
  unsigned int v27; // ebx
  UFG::Event *v28; // rax
  UFG::SceneObjectProperties *v29; // rbx
  UFG::SimObject *v30; // rdx
  UFG::SceneObjectProperties *v31; // rdx
  UFG::qPropertySet *ArchetypeProperties; // rax
  UFG::SimObject *v33; // rcx
  UFG::SceneObjectProperties *v34; // r9
  UFG::qPropertySet *WritablePersistentProperties; // rax
  __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSymbol *v39; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  char v41; // r14
  UFG::PedSpawnManager *Instance; // rax
  UFG::qBaseNodeRB *v43; // rax
  UFG::SceneObjectProperties *v44; // rbx
  UFG::SimObject *v45; // rax
  UFG::SceneObjectProperties *v46; // rdx
  UFG::SceneObjectProperties *v47; // rbx
  UFG::SimObject *v48; // rax
  UFG::SceneObjectProperties *v49; // rdx
  UFG::SimObjectGame *v50; // rax
  __int16 v51; // cx
  UFG::SimComponent *v52; // rax
  UFG::SimObjectCharacter *v53; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::allocator::free_link *v55; // r14
  unsigned int v56; // ebx
  UFG::Event *v57; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSpawn; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v59; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v60; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v61; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp-68h] BYREF
  UFG::qWiseSymbol v64; // [rsp+44h] [rbp-64h] BYREF
  __int64 v65; // [rsp+48h] [rbp-60h]
  UFG::allocator::free_link *v66; // [rsp+50h] [rbp-58h]
  UFG::qSymbol v67; // [rsp+B0h] [rbp+8h] BYREF
  bool v68; // [rsp+B8h] [rbp+10h]
  bool called_from_script; // [rsp+C0h] [rbp+18h]
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+C8h] [rbp+20h] BYREF

  called_from_script = from_skookum;
  v68 = skip_poi_links;
  v65 = -2i64;
  v3 = skip_poi_links;
  v5 = 0i64;
  SimObject = 0i64;
  if ( skip_poi_links )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
    this->mNext = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
    this->mIsLinkPending = 0;
  }
  if ( !this->mpSpawn.m_pPointer )
    UFG::SpawnPoint::SetupSpawnTarget(this);
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  if ( m_pSceneObj->mChildren.mCount )
  {
    if ( m_pSimObject )
      v11 = m_pSimObject->m_pSceneObj;
    else
      v11 = 0i64;
    ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(v11, 0);
    if ( !ChildAsSceneObject )
      goto LABEL_96;
    UFG::qSymbol::qSymbol(&result, 0x1B810511u);
    UFG::SceneObjectProperties::operator UFG::qSymbol const(ChildAsSceneObject, (UFG::qWiseSymbol *)&v67);
    v13 = 0;
    m_NameUID = ChildAsSceneObject->m_NameUID;
    pPriority = m_NameUID;
    SimObject = (UFG::SimObjectCharacter *)UFG::Simulation::GetSimObject(&UFG::gSim, m_NameUID);
    v15 = ChildAsSceneObject->m_pSimObject == 0i64;
    if ( SimObject && !ChildAsSceneObject->m_pSimObject )
    {
      v13 = 1;
      goto LABEL_44;
    }
    mpWritableProperties = ChildAsSceneObject->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = ChildAsSceneObject->mpConstProperties;
    SpawnPriority = UFG::SpawnInfoInterface::GetSpawnPriority(
                      mpWritableProperties,
                      (UFG::SpawnInfoInterface::SpawnPriority *)&v67);
    if ( v15 )
    {
      if ( SpawnPriority )
      {
        mUID = SpawnPriority->mUID;
        if ( mUID == qSymbol_Low.mUID || mUID == qSymbol_Medium.mUID )
        {
          v19 = UFG::ObjectResourceManager::Instance();
          if ( !UFG::ObjectResourceManager::CanSpawnAmbient(v19, mpWritableProperties, 0i64, 0) )
            goto LABEL_43;
        }
      }
    }
    else if ( SimObject )
    {
LABEL_43:
      SimObject = (UFG::SimObjectCharacter *)ChildAsSceneObject->m_pSimObject;
      v13 = ChildAsSceneObject->mpOwner.m_pPointer == 0i64;
      goto LABEL_44;
    }
    mSkipSpawnChancePercent = this->mSkipSpawnChancePercent;
    if ( mSkipSpawnChancePercent
      && (int)UFG::qRandom(0x64u, (unsigned int *)&UFG::qDefaultSeed) < mSkipSpawnChancePercent )
    {
      v21 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&mpWritableProperties->mName);
      UFG::qPrintf("spawn chance pruning: %s\n", v21);
    }
    else if ( PropertyUtils::Get<bool>(
                ChildAsSceneObject,
                (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnFromCurrentTrafficSet) )
    {
      RandomPropSetFromCurrentTrafficSet = UFG::WheeledVehicleManager::ChooseAmbientParkedVehicle(
                                             UFG::WheeledVehicleManager::m_Instance,
                                             0);
      if ( RandomPropSetFromCurrentTrafficSet
        || (v23 = UFG::ObjectResourceManager::Instance(),
            (RandomPropSetFromCurrentTrafficSet = UFG::ObjectResourceManager::GetRandomPropSetFromCurrentTrafficSet(v23)) != 0i64) )
      {
        if ( !UFG::SimObjectUtility::IsClassType(RandomPropSetFromCurrentTrafficSet, &qSymbol_Boat_17) )
        {
          v24 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v64, m_NameUID);
          SimObject = (UFG::SimObjectCharacter *)UFG::SpawnInfoInterface::SpawnObject(
                                                   v24,
                                                   RandomPropSetFromCurrentTrafficSet,
                                                   (UFG::SpawnInfoInterface::SpawnPriority)v67.mUID,
                                                   0i64,
                                                   0i64,
                                                   0i64);
          mpXformNode = this->mpXformNode;
          v26 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
          v66 = v26;
          if ( v26 )
          {
            v27 = SimObject->mNode.mUID;
            UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
            UFG::TeleportEvent::TeleportEvent(
              (UFG::TeleportEvent *)v26,
              &mpXformNode->mWorldTransform,
              v27,
              0,
              UFG::TeleportEvent::m_Name,
              0);
          }
          else
          {
            v28 = 0i64;
          }
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v28);
          UFG::SceneObjectProperties::SetParent(ChildAsSceneObject, 0i64);
          v29 = SimObject->m_pSceneObj;
          v30 = this->m_pSimObject;
          if ( v30 )
            v31 = v30->m_pSceneObj;
          else
            v31 = 0i64;
          UFG::SceneObjectProperties::SetParent(SimObject->m_pSceneObj, v31);
          ChildAsSceneObject->vfptr->__vecDelDtor(ChildAsSceneObject, 1u);
          ChildAsSceneObject = v29;
          m_NameUID = pPriority;
        }
      }
    }
    else
    {
      ArchetypeProperties = (UFG::qPropertySet *)UFG::SceneObjectProperties::GetArchetypeProperties(ChildAsSceneObject);
      v33 = this->m_pSimObject;
      if ( v33 )
        v34 = v33->m_pSceneObj;
      else
        v34 = 0i64;
      SimObject = (UFG::SimObjectCharacter *)UFG::SpawnInfoInterface::ActivateObject(
                                               ChildAsSceneObject,
                                               (UFG::SpawnInfoInterface::SpawnPriority)v67.mUID,
                                               0i64,
                                               v34,
                                               ArchetypeProperties,
                                               2u,
                                               called_from_script);
    }
LABEL_44:
    if ( SimObject )
    {
      if ( !v13 )
      {
        m_pTransformNodeComponent = SimObject->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          v55 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
          v66 = v55;
          if ( v55 )
          {
            v56 = SimObject->mNode.mUID;
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
            UFG::TeleportEvent::TeleportEvent(
              (UFG::TeleportEvent *)v55,
              &m_pTransformNodeComponent->mWorldTransform,
              v56,
              0,
              UFG::TeleportEvent::m_Name,
              0);
            v5 = v57;
          }
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v5);
        }
        goto LABEL_96;
      }
    }
    else
    {
      WritablePersistentProperties = UFG::SceneObjectProperties::GetWritablePersistentProperties(ChildAsSceneObject);
      SimObject = (UFG::SimObjectCharacter *)UFG::Simulation::GetSimObject(
                                               &UFG::gSim,
                                               &WritablePersistentProperties->mName);
      if ( !SimObject )
        goto LABEL_96;
    }
    m_Flags = SimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                SimObject,
                                UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(SimObject, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
    {
      v39 = (UFG::qSymbol *)PropertyUtils::Get<UFG::qSymbol>(
                              ChildAsSceneObject,
                              (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority);
      UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(m_pComponent, v39);
      UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(m_pComponent, &qSymbol_Low);
    }
    UFG::SceneObjectProperties::GetArchetypeProperties(ChildAsSceneObject);
    mpConstProperties = ChildAsSceneObject->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = ChildAsSceneObject->mpConstProperties;
    UFG::SpawnInfoInterface::GetSpawnPriority(mpConstProperties, &pPriority);
    if ( UFG::SpawnInfoInterface::IsCharacter(ChildAsSceneObject) )
    {
      v41 = UFG::PedSpawnManager::AquireOwnership(SimObject, pPriority >= Reserved, 0, this->mSpawnZoneIndex);
      if ( v41 )
      {
        Instance = UFG::PedSpawnManager::GetInstance();
        UFG::PedSpawnManager::SetSuspendOption(Instance, SimObject, SuspendAllowed);
      }
      v43 = UFG::Simulation::GetSimObject(&UFG::gSim, m_NameUID);
      SimObject = (UFG::SimObjectCharacter *)v43;
      if ( !v43 )
        goto LABEL_96;
      v44 = (UFG::SceneObjectProperties *)v43[2].mChild[1];
      if ( v44 != ChildAsSceneObject )
      {
        UFG::SceneObjectProperties::SetParent(ChildAsSceneObject, 0i64);
        v45 = this->m_pSimObject;
        if ( v45 )
          v46 = v45->m_pSceneObj;
        else
          v46 = 0i64;
        UFG::SceneObjectProperties::SetParent(v44, v46);
        ChildAsSceneObject->vfptr->__vecDelDtor(ChildAsSceneObject, 1u);
        ChildAsSceneObject = v44;
      }
      if ( v41 )
        goto LABEL_96;
    }
    else
    {
      PropertyUtils::Get<bool>(ChildAsSceneObject, (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnFromCurrentTrafficSet);
      v47 = SimObject->m_pSceneObj;
      if ( v47 != ChildAsSceneObject )
      {
        UFG::SceneObjectProperties::SetParent(ChildAsSceneObject, 0i64);
        v48 = this->m_pSimObject;
        if ( v48 )
          v49 = v48->m_pSceneObj;
        else
          v49 = 0i64;
        UFG::SceneObjectProperties::SetParent(v47, v49);
        ChildAsSceneObject->vfptr->__vecDelDtor(ChildAsSceneObject, 1u);
        ChildAsSceneObject = v47;
      }
    }
    v50 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, m_NameUID);
    SimObject = (UFG::SimObjectCharacter *)v50;
    if ( v50 )
    {
      v51 = v50->m_Flags;
      if ( (v51 & 0x4000) != 0 )
      {
        v52 = v50->m_Components.p[23].m_pComponent;
      }
      else if ( v51 >= 0 )
      {
        v52 = (v51 & 0x2000) != 0 || (v51 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v50, UFG::VehicleDriverInterface::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v50, UFG::VehicleDriverInterface::_TypeUID);
      }
      else
      {
        v52 = v50->m_Components.p[23].m_pComponent;
      }
      if ( !v52
        || (v53 = (UFG::SimObjectCharacter *)v52[3].m_BoundComponentHandles.mNode.mNext) == 0i64
        || !UFG::IsAnyLocalPlayer(v53) )
      {
        UFG::SpawnInfoInterface::ReinitializeSpawnedObject(
          (UFG::SpawnInfoInterface *)&this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>,
          SimObject,
          pPriority,
          ChildAsSceneObject,
          called_from_script);
      }
    }
LABEL_96:
    v3 = v68;
  }
  UFG::SpawnInfoInterface::SetOwner(SimObject, this->m_pSimObject);
  p_mpSpawn = &this->mpSpawn;
  if ( this->mpSpawn.m_pPointer )
  {
    v59 = p_mpSpawn->mPrev;
    v60 = this->mpSpawn.mNext;
    v59->mNext = v60;
    v60->mPrev = v59;
    p_mpSpawn->mPrev = p_mpSpawn;
    this->mpSpawn.mNext = &this->mpSpawn;
  }
  this->mpSpawn.m_pPointer = SimObject;
  if ( SimObject )
  {
    v61 = SimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v61->mNext = p_mpSpawn;
    p_mpSpawn->mPrev = v61;
    this->mpSpawn.mNext = &SimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    SimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpSpawn;
  }
  if ( !v3 )
    UFG::SpawnPoint::UpdateLinks(this, 0);
  return SimObject;
}ev = p_mpSpawn;
  }
  if ( !v3 )
    UFG::SpawnPoint::UpdateLinks(this, 0);
  return SimObject;
}

// File Line: 740
// RVA: 0x58B980
char __fastcall UFG::SpawnPoint::SetNewSpawnTarget(UFG::SpawnPoint *this, UFG::qPropertySet *target_property_set)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::SceneObjectProperties *ChildAsSceneObject; // rdi
  UFG::qPropertySet *WritableProperties; // rbx
  UFG::qResourceData *ArchetypeProperties; // rax

  if ( this->mpSpawn.m_pPointer )
    return 0;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(m_pSceneObj, 0);
  UFG::SceneObjectProperties::UninstantiateChildObjects(ChildAsSceneObject);
  WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(ChildAsSceneObject);
  ArchetypeProperties = UFG::SceneObjectProperties::GetArchetypeProperties(ChildAsSceneObject);
  UFG::qPropertySet::RemoveParent(
    WritableProperties,
    (UFG::qArray<unsigned long,0> *)&ArchetypeProperties->mDebugName[12]);
  UFG::qPropertySet::AddParent(WritableProperties, target_property_set);
  UFG::SceneObjectProperties::InstantiateChildObjects(ChildAsSceneObject, 0);
  return 1;
}

// File Line: 796
// RVA: 0x58DBD0
void __fastcall UFG::SpawnPoint::UpdateAll(float delta_sec)
{
  Render::SkinningCacheNode *Head; // rax
  UFG::SpawnPoint *p_mCachedBufferPtr; // rbx
  int v3; // ecx
  UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *v4; // rax
  UFG::qBaseTreeRB *Next; // rax

  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SpawnPoint::msSpawnPoints);
  if ( Head )
    p_mCachedBufferPtr = (UFG::SpawnPoint *)&Head[-4].mCachedBufferPtr;
  else
    p_mCachedBufferPtr = 0i64;
  while ( p_mCachedBufferPtr )
  {
    v3 = -1;
    v4 = (UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *)&UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mNext[-7];
    if ( (UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *)&UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mNext[-7] != &UFG::SpawnPoint::msSpawnPointsWithPendingLinks - 7 )
    {
      while ( 1 )
      {
        ++v3;
        if ( v4 == (UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *)p_mCachedBufferPtr )
          break;
        v4 = (UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *)&v4[7].mNode.mNext[-7];
        if ( v4 == &UFG::SpawnPoint::msSpawnPointsWithPendingLinks - 7 )
          goto LABEL_11;
      }
      if ( v3 != -1 )
        UFG::SpawnPoint::UpdateLinks(p_mCachedBufferPtr, 1);
    }
LABEL_11:
    Next = UFG::qBaseTreeRB::GetNext(
             &UFG::SpawnPoint::msSpawnPoints.mTree,
             &p_mCachedBufferPtr->UFG::qNodeRB<UFG::SpawnPoint>::mNode);
    if ( Next )
      p_mCachedBufferPtr = (UFG::SpawnPoint *)&Next[-2].mRoot.mChild[1];
    else
      p_mCachedBufferPtr = 0i64;
  }
}

// File Line: 810
// RVA: 0x580D70
void __fastcall UFG::SpawnPoint::FillPendingLinks(UFG::SpawnPoint *this)
{
  UFG::qList<UFG::PendingLink,UFG::PendingLink,1,0> *p_mPendingLinks; // rdi
  UFG::PendingLink *mNext; // rbx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *mPrev; // rcx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v5; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rbp
  unsigned int mNumElements; // r12d
  unsigned int i; // esi
  char *ValuePtr; // rax
  UFG::qPropertySet *v13; // rbx
  UFG::qSymbol *v14; // r14
  UFG::qSymbol *v15; // r15
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rdx
  UFG::qSymbol *v18; // rax
  UFG::qSymbol *v19; // rax
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v20; // rax

  p_mPendingLinks = &this->mPendingLinks;
  mNext = (UFG::PendingLink *)this->mPendingLinks.mNode.mNext;
  if ( mNext != (UFG::PendingLink *)&this->mPendingLinks )
  {
    do
    {
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::PendingLink::~PendingLink(mNext);
      operator delete[](mNext);
      mNext = (UFG::PendingLink *)p_mPendingLinks->mNode.mNext;
    }
    while ( mNext != (UFG::PendingLink *)p_mPendingLinks );
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_pSceneObj = m_pSimObject->m_pSceneObj;
    if ( m_pSceneObj )
    {
      v8 = PropertyUtils::Get<UFG::qPropertyList>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_Links);
      v9 = v8;
      if ( v8 )
      {
        mNumElements = v8->mNumElements;
        if ( mNumElements )
        {
          for ( i = 0; i < mNumElements; ++i )
          {
            ValuePtr = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, i);
            if ( !ValuePtr || (v13 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
              v13 = 0i64;
            v14 = UFG::qPropertySet::Get<UFG::qSymbol>(
                    v13,
                    (UFG::qArray<unsigned long,0> *)&SimSym_LinkEntity,
                    DEPTH_RECURSE);
            v15 = UFG::qPropertySet::Get<UFG::qSymbol>(
                    v13,
                    (UFG::qArray<unsigned long,0> *)&SimSym_LinkObjective,
                    DEPTH_RECURSE);
            v16 = UFG::qMalloc(0x60ui64, "PendingLink", 0x800ui64);
            v17 = v16;
            if ( v16 )
            {
              v16->mNext = v16;
              v16[1].mNext = v16;
              LODWORD(v16[2].mNext) = -1;
              v16[3].mNext = v16 + 3;
              v16[4].mNext = v16 + 3;
              v16[5].mNext = 0i64;
              LODWORD(v16[6].mNext) = -1;
              v16[7].mNext = v16 + 7;
              v16[8].mNext = v16 + 7;
              v16[9].mNext = 0i64;
              v16[10].mNext = 0i64;
            }
            else
            {
              v17 = 0i64;
            }
            v17[11].mNext = (UFG::allocator::free_link *)v13;
            v18 = &UFG::gNullQSymbol;
            if ( v14 )
              v18 = v14;
            LODWORD(v17[2].mNext) = (UFG::qSymbol)v18->mUID;
            v19 = &UFG::gNullQSymbol;
            if ( v15 )
              v19 = v15;
            LODWORD(v17[6].mNext) = (UFG::qSymbol)v19->mUID;
            v20 = p_mPendingLinks->mNode.mPrev;
            v20->mNext = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v17;
            v17->mNext = (UFG::allocator::free_link *)v20;
            v17[1].mNext = (UFG::allocator::free_link *)p_mPendingLinks;
            p_mPendingLinks->mNode.mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v17;
          }
        }
      }
    }
  }
}

// File Line: 841
// RVA: 0x5902A0
__int64 __fastcall UFG::SpawnPoint::UpdateLinks(UFG::SpawnPoint *this, bool calledByUpdate)
{
  unsigned __int8 v3; // r12
  char v4; // al
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *mNext; // rsi
  UFG::SceneObjectProperties *m_pSceneObj; // rdi
  unsigned __int64 v7; // rax
  __int64 mPrevNameHash; // rdx
  unsigned __int64 v9; // rax
  UFG::qBaseNodeRB *SimObject; // r8
  UFG::qBaseNodeRB *p_mNext; // rdx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *mParent; // rcx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *mPrev; // rax
  UFG::qBaseNodeRB *v14; // rax
  UFG::SimObject *v15; // rcx
  UFG::InterestPoint *ComponentOfType; // rax
  UFG::SimObjectGame *ParentObject; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v20; // rbx
  int m_pSimObject; // eax
  bool v22; // bp
  unsigned __int64 v23; // rax
  __int64 v24; // rdx
  unsigned __int64 v25; // rax
  UFG::qBaseNodeRB *v26; // r8
  UFG::qBaseNodeRB *v27; // rdx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v28; // rcx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v29; // rax
  UFG::qBaseNodeRB *v30; // rax
  UFG::SimObjectGame *v31; // rcx
  __int16 v32; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v34; // rax
  UFG::SimObjectGame *v35; // rcx
  __int16 v36; // dx
  UFG::SimComponent *v37; // rax
  unsigned int *v38; // rdi
  bool *v39; // rax
  __int64 *p_symbol; // rcx
  char v41; // bl
  bool *v42; // rax
  __int64 *v43; // rcx
  char v44; // bp
  UFG::qStaticSymbol *v45; // rbx
  UFG::qSymbol *v46; // rax
  UFG::ePOIUseType EnumFromSymbol; // r15d
  UFG::InterestPointUserComponent *v48; // r14
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v49; // rcx
  UFG::SimComponent *v50; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::TeleportEvent *v52; // rbp
  unsigned int v53; // edi
  UFG::TransformNodeComponent *v54; // rbx
  char *v55; // rax
  UFG::qBaseTreeRB *v56; // rax
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v57; // rcx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v58; // rcx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v59; // rax
  char v61; // [rsp+A0h] [rbp+8h]
  bool v62; // [rsp+A8h] [rbp+10h]
  UFG::allocator::free_link *symbol; // [rsp+B0h] [rbp+18h] BYREF
  UFG::qSymbol skipIntoLabel; // [rsp+B8h] [rbp+20h] BYREF

  v62 = calledByUpdate;
  v3 = 0;
  v4 = 0;
  v61 = 0;
  mNext = this->mPendingLinks.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)&this->mPendingLinks )
  {
    while ( 1 )
    {
      m_pSceneObj = this->m_pSimObject->m_pSceneObj;
      if ( mNext[4].mNext )
        goto LABEL_28;
      LODWORD(v7) = mNext[3].mPrev;
      if ( m_pSceneObj )
      {
        mPrevNameHash = m_pSceneObj->mPrevNameHash;
        if ( (_DWORD)mPrevNameHash )
        {
          v9 = 21
             * ((((mPrevNameHash | ((unsigned __int64)(unsigned int)v7 << 32)) << 18)
               + ~(mPrevNameHash | ((unsigned __int64)(unsigned int)v7 << 32))) ^ ((((mPrevNameHash | ((unsigned __int64)(unsigned int)v7 << 32)) << 18)
                                                                                  + ~(mPrevNameHash | ((unsigned __int64)(unsigned int)v7 << 32))) >> 31));
          v7 = (65 * (v9 ^ (v9 >> 11))) ^ ((65 * (v9 ^ (v9 >> 11))) >> 22);
        }
      }
      SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, v7);
      p_mNext = (UFG::qBaseNodeRB *)&mNext[3].mNext;
      if ( mNext[4].mNext )
      {
        mParent = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)p_mNext->mParent;
        mPrev = mNext[4].mPrev;
        mParent->mNext = mPrev;
        mPrev->mPrev = mParent;
        p_mNext->mParent = p_mNext;
        mNext[4].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)((char *)mNext + 56);
      }
      mNext[4].mNext = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)SimObject;
      if ( SimObject )
      {
        v14 = SimObject->mChild[0];
        v14->mChild[0] = p_mNext;
        p_mNext->mParent = v14;
        mNext[4].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)SimObject->mChild;
        SimObject->mChild[0] = p_mNext;
      }
      v15 = (UFG::SimObject *)mNext[4].mNext;
      if ( v15 )
      {
        ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v15, UFG::InterestPoint::_TypeUID);
        mNext[5].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)ComponentOfType;
        if ( !ComponentOfType )
          goto LABEL_86;
        ParentObject = (UFG::SimObjectGame *)UFG::InterestPoint::GetParentObject(ComponentOfType);
        if ( ParentObject )
        {
          m_Flags = ParentObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  ParentObject,
                                  UFG::PowerManagementComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  ParentObject,
                                  UFG::PowerManagementComponent::_TypeUID);
          v20 = ComponentOfTypeHK;
          if ( ComponentOfTypeHK )
          {
            m_pSimObject = (int)ComponentOfTypeHK[1].m_pSimObject;
            v22 = m_pSimObject != 0;
            if ( m_pSimObject )
              UFG::PowerManagementComponent::gotoResuming((UFG::PowerManagementComponent *)v20);
            if ( *(float *)&v20[1].m_BoundComponentHandles.mNode.mPrev < 3.4028235e38 )
              LODWORD(v20[1].m_BoundComponentHandles.mNode.mPrev) = 1092616192;
            if ( v22 )
            {
LABEL_26:
              v4 = 1;
              v61 = 1;
              goto LABEL_87;
            }
          }
        }
      }
      if ( mNext[4].mNext )
      {
LABEL_28:
        LODWORD(v23) = mNext[1].mPrev;
        if ( m_pSceneObj )
        {
          v24 = m_pSceneObj->mPrevNameHash;
          if ( (_DWORD)v24 )
          {
            v25 = 21
                * ((((v24 | ((unsigned __int64)(unsigned int)v23 << 32)) << 18)
                  + ~(v24 | ((unsigned __int64)(unsigned int)v23 << 32))) ^ ((((v24 | ((unsigned __int64)(unsigned int)v23 << 32)) << 18)
                                                                            + ~(v24 | ((unsigned __int64)(unsigned int)v23 << 32))) >> 31));
            v23 = (65 * (v25 ^ (v25 >> 11))) ^ ((65 * (v25 ^ (v25 >> 11))) >> 22);
          }
        }
        if ( !mNext[2].mNext )
        {
          v26 = UFG::Simulation::GetSimObject(&UFG::gSim, v23);
          v27 = (UFG::qBaseNodeRB *)&mNext[1].mNext;
          if ( mNext[2].mNext )
          {
            v28 = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v27->mParent;
            v29 = mNext[2].mPrev;
            v28->mNext = v29;
            v29->mPrev = v28;
            v27->mParent = v27;
            mNext[2].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)((char *)mNext + 24);
          }
          mNext[2].mNext = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v26;
          if ( v26 )
          {
            v30 = v26->mChild[0];
            v30->mChild[0] = v27;
            v27->mParent = v30;
            mNext[2].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v26->mChild;
            v26->mChild[0] = v27;
          }
        }
      }
      v31 = (UFG::SimObjectGame *)mNext[2].mNext;
      if ( !v31 || !mNext[4].mNext )
        goto LABEL_26;
      v32 = v31->m_Flags;
      if ( (v32 & 0x4000) != 0 )
      {
        m_pComponent = v31->m_Components.p[7].m_pComponent;
      }
      else if ( v32 >= 0 )
      {
        if ( (v32 & 0x2000) != 0 )
        {
          m_pComponent = v31->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v32 & 0x1000) != 0 )
            v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::ActionTreeComponent::_TypeUID);
          else
            v34 = UFG::SimObject::GetComponentOfType(v31, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = v34;
        }
      }
      else
      {
        m_pComponent = v31->m_Components.p[7].m_pComponent;
      }
      v35 = (UFG::SimObjectGame *)mNext[2].mNext;
      if ( v35 )
      {
        v36 = v35->m_Flags;
        if ( (v36 & 0x4000) != 0 )
        {
          v35 = (UFG::SimObjectGame *)v35->m_Components.p[19].m_pComponent;
        }
        else if ( v36 >= 0 )
        {
          if ( (v36 & 0x2000) != 0 || (v36 & 0x1000) != 0 )
            v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::AIActionTreeComponent::_TypeUID);
          else
            v37 = UFG::SimObject::GetComponentOfType(v35, UFG::AIActionTreeComponent::_TypeUID);
          v35 = (UFG::SimObjectGame *)v37;
        }
        else
        {
          v35 = (UFG::SimObjectGame *)v35->m_Components.p[19].m_pComponent;
        }
      }
      if ( (m_pComponent->m_Flags & 2) != 0
        || ((__int64)v35->m_SafePointerWithCallbackList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext & 2) != 0 )
      {
        goto LABEL_26;
      }
      if ( !mNext[5].mPrev )
      {
        if ( UFG::SimObject::GetComponentOfType((UFG::SimObject *)mNext[4].mNext, UFG::AIEntityComponent::_TypeUID) )
        {
          if ( (_S11_8 & 1) == 0 )
          {
            _S11_8 |= 1u;
            UFG::qSymbol::create_from_string(&defaultFormationId, "default-formation-GroupOf2");
            atexit(UFG::SpawnPoint::UpdateLinks_::_58_::_dynamic_atexit_destructor_for__defaultFormationId__);
          }
          if ( defaultFormationId.mUID )
            v56 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, defaultFormationId.mUID);
          else
            v56 = 0i64;
          UFG::GroupComponent::JoinGroup(
            (UFG::SimObjectGame *)mNext[2].mNext,
            (UFG::SimObjectGame *)mNext[4].mNext,
            (UFG::PedFormationProfile *)v56);
          v3 = 1;
        }
        goto LABEL_86;
      }
      v38 = UFG::qPropertySet::Get<unsigned long>(
              (UFG::qPropertySet *)mNext[5].mNext,
              (UFG::qArray<unsigned long,0> *)&SimSym_LinkParam,
              DEPTH_RECURSE);
      LOBYTE(symbol) = 0;
      v39 = UFG::qPropertySet::Get<bool>(
              (UFG::qPropertySet *)mNext[5].mNext,
              (UFG::qArray<unsigned long,0> *)&qSymbol_NoInterrupt,
              DEPTH_RECURSE);
      p_symbol = (__int64 *)&symbol;
      if ( v39 )
        p_symbol = (__int64 *)v39;
      v41 = *(_BYTE *)p_symbol;
      LOBYTE(symbol) = 0;
      v42 = UFG::qPropertySet::Get<bool>(
              (UFG::qPropertySet *)mNext[5].mNext,
              (UFG::qArray<unsigned long,0> *)&qSymbol_Exclusive,
              DEPTH_RECURSE);
      v43 = (__int64 *)&symbol;
      if ( v42 )
        v43 = (__int64 *)v42;
      v44 = *(_BYTE *)v43;
      v45 = &UFG::POIUseTypeEnumSymbols[(v41 != 0) + 2];
      v46 = UFG::qPropertySet::Get<UFG::qSymbol>(
              (UFG::qPropertySet *)mNext[5].mNext,
              (UFG::qArray<unsigned long,0> *)&qSymbol_PoiUseType,
              DEPTH_RECURSE);
      if ( v46 )
        v45 = (UFG::qStaticSymbol *)v46;
      LODWORD(symbol) = (UFG::qStaticSymbol)v45->mUID;
      EnumFromSymbol = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                       &UFG::gPOIUseTypeEnum,
                                       (UFG::qSymbol *)&symbol);
      v48 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)mNext[2].mNext,
                                                 UFG::InterestPointUserComponent::_TypeUID);
      if ( !v48 )
        goto LABEL_86;
      v49 = mNext[5].mPrev;
      if ( BYTE1(v49[26].mNext) )
      {
        if ( v49[23].mNext != mNext[2].mNext
          || v49[33].mNext != (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)this->m_pSimObject )
        {
          goto LABEL_86;
        }
      }
      UFG::InterestPointUserComponent::SetLinkObject(v48, this->m_pSimObject, EnumFromSymbol, v44);
      UFG::InterestPoint::SetLinkObject((UFG::InterestPoint *)mNext[5].mPrev, this->m_pSimObject);
      v50 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)mNext[2].mNext, UFG::ActiveAIEntityComponent::_TypeUID);
      skipIntoLabel.mUID = UFG::gNullQSymbol.mUID;
      if ( v50 )
      {
        if ( v38 && *v38 == 1 )
        {
          v51 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
          v52 = (UFG::TeleportEvent *)v51;
          symbol = v51;
          if ( v51 )
          {
            v53 = (unsigned int)mNext[2].mNext[4].mPrev;
            v54 = (UFG::TransformNodeComponent *)mNext[5].mPrev[6].mNext;
            UFG::TransformNodeComponent::UpdateWorldTransform(v54);
            UFG::TeleportEvent::TeleportEvent(v52, &v54->mWorldTransform, v53, 0, UFG::TeleportEvent::m_Name, 0);
          }
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v51);
          skipIntoLabel.mUID = qSymbol_Link.mUID;
        }
        UFG::InterestPointUserComponent::UsePOI(
          v48,
          (UFG::InterestPoint *)mNext[5].mPrev,
          EnumFromSymbol,
          &skipIntoLabel);
        v3 = 1;
LABEL_86:
        v4 = v61;
        goto LABEL_87;
      }
      v55 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&mNext[2].mNext[4].mNext);
      UFG::qPrintf(
        "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\source\\sim\\components\\spawnpoint.cpp(993) : : Linking: %s failed"
        " because: %s %s\n",
        v55,
        &customCaption,
        "ActiveAIEntityComponent is null");
      v4 = 1;
      v61 = 1;
LABEL_87:
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)&this->mPendingLinks )
      {
        calledByUpdate = v62;
        break;
      }
    }
  }
  if ( this->mIsLinkPending || !v4 )
  {
    if ( v3 )
    {
      this->mIsLinkPending = 0;
      v58 = this->mPrev;
      v59 = this->mNext;
      v58->mNext = v59;
      v59->mPrev = v58;
      this->mPrev = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
      this->mNext = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
    }
  }
  else if ( !calledByUpdate )
  {
    this->mIsLinkPending = 1;
    v57 = UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mPrev;
    UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mPrev->mNext = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
    this->mPrev = v57;
    this->mNext = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&UFG::SpawnPoint::msSpawnPointsWithPendingLinks;
    UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mPrev = &this->UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint>;
  }
  return v3;
}

// File Line: 1075
// RVA: 0x58B5C0
UFG::SimObject *__fastcall Scaleform::GFx::InteractiveObject::GetResourceMovieDef(UFG::SpawnPoint *this)
{
  return this->mpSpawn.m_pPointer;
}

// File Line: 1090
// RVA: 0x58A900
UFG::SpawnPoint *__fastcall UFG::SpawnPoint::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdi
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v6; // rax
  char *MemImagePtr; // rbp
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // r15
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v12; // rax
  UFG::SpawnPoint *v13; // rax
  UFG::SpawnPoint *v14; // rbx
  UFG::SimObject *v15; // rax
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::allocator::free_link *pPriority; // [rsp+70h] [rbp+8h] BYREF
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+18h] BYREF

  m_pSceneObj = 0i64;
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_SpawnPoint::sPropertyName,
         DEPTH_RECURSE);
  if ( v6 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v6);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE0ui64, "SpawnPoint", 0i64, 1u);
  pPriority = v10;
  if ( v10 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v12 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, pSceneObj->m_NameUID);
    UFG::SpawnPoint::SpawnPoint((UFG::SpawnPoint *)v10, v12, m_pSimObject);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v14->mThugPoint = MemImagePtr[1];
  if ( !UFG::SpawnPoint::Initialize(v14, pSceneObj->m_pSimObject) )
    return 0i64;
  LODWORD(pPriority) = 0;
  v15 = v14->m_pSimObject;
  if ( v15 )
    m_pSceneObj = v15->m_pSceneObj;
  ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(m_pSceneObj, 0);
  if ( ChildAsSceneObject )
  {
    mpConstProperties = ChildAsSceneObject->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = ChildAsSceneObject->mpConstProperties;
    UFG::SpawnInfoInterface::GetSpawnPriority(mpConstProperties, (UFG::SpawnInfoInterface::SpawnPriority *)&pPriority);
  }
  if ( !((unsigned __int8)*MemImagePtr | ((int)pPriority >= 1)) )
    UFG::SpawnPoint::Spawn(v14, 0, 0);
  return v14;
}

// File Line: 1160
// RVA: 0x585480
char __fastcall UFG::SpawnPoint::IsSheltered(UFG::SpawnPoint *this)
{
  UFG::SimObject *m_pSimObject; // rax
  unsigned int v2; // ebx
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::SimObject *v6; // rax
  UFG::SceneObjectProperties *v7; // rcx
  unsigned int mCount; // edi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *SceneObj; // rax
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v12; // rax

  m_pSimObject = this->m_pSimObject;
  v2 = 0;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  if ( PropertyUtils::Get<UFG::qPropertyList>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_Links) )
    return 1;
  v6 = this->m_pSimObject;
  if ( v6 )
    v7 = v6->m_pSceneObj;
  else
    v7 = 0i64;
  mCount = v7->mChildren.mCount;
  if ( !mCount )
    return 0;
  while ( 1 )
  {
    SceneObj = UFG::SimComponent::GetSceneObj(this);
    ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject((UFG::SceneObjectProperties *)SceneObj, v2);
    if ( ChildAsSceneObject )
      break;
    if ( ++v2 >= mCount )
      return 0;
  }
  mpWritableProperties = ChildAsSceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = ChildAsSceneObject->mpConstProperties;
  v12 = PropertyUtils::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&qSymbol_Sheltered,
          DEPTH_RECURSE);
  return v12 && *v12;
}

