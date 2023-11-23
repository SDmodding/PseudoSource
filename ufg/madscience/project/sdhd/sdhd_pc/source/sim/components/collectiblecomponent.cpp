// File Line: 34
// RVA: 0x15438A0
__int64 dynamic_initializer_for__UFG::CollectibleComponent::msCollectibleComponents__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::CollectibleComponent::msCollectibleComponents.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CollectibleComponent::msCollectibleComponents__);
}

// File Line: 35
// RVA: 0x5323E0
const char *__fastcall UFG::CollectibleComponent::GetTypeName(UFG::CollectibleComponent *this)
{
  return "CollectibleComponent";
}

// File Line: 50
// RVA: 0x516A70
void __fastcall UFG::CollectibleComponent::CollectibleComponent(
        UFG::CollectibleComponent *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj)
{
  unsigned int mUID; // eax
  bool v7; // bp
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rbx
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rax

  UFG::SpawnPointInterface::SpawnPointInterface(this, name, pSimObj);
  mUID = name->mUID;
  v7 = 0;
  this->UFG::qNodeRB<UFG::CollectibleComponent>::mNode.mParent = 0i64;
  this->UFG::qNodeRB<UFG::CollectibleComponent>::mNode.mChild[0] = 0i64;
  this->UFG::qNodeRB<UFG::CollectibleComponent>::mNode.mChild[1] = 0i64;
  this->UFG::qNodeRB<UFG::CollectibleComponent>::mNode.mUID = mUID;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CollectibleComponent::`vftable;
  this->mpObject.mPrev = &this->mpObject;
  this->mpObject.mNext = &this->mpObject;
  this->mpObject.m_pPointer = 0i64;
  this->mpEffectTransform = 0i64;
  this->mType = Collectible_Generic;
  *(_QWORD *)&this->mEffectId = -1i64;
  this->mUnlocksAfter = UFG::gNullQSymbol;
  *(_DWORD *)&this->mProgressionBased = 0;
  UFG::qBaseTreeRB::Add(
    &UFG::CollectibleComponent::msCollectibleComponents.mTree,
    &this->UFG::qNodeRB<UFG::CollectibleComponent>::mNode);
  UFG::SimComponent::AddType(this, UFG::CollectibleComponent::_CollectibleComponentTypeUID, "CollectibleComponent");
  m_pSceneObj = pSimObj->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v10 = UFG::qPropertySet::Get<UFG::qSymbol>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_UnlocksAfter,
          DEPTH_RECURSE);
  if ( v10 && v10->mUID != -1 )
    v7 = 1;
  this->mProgressionBased = v7;
  v11 = UFG::qPropertySet::Get<UFG::qSymbol>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_CollectibleType,
          DEPTH_RECURSE);
  if ( v11 )
  {
    if ( v11->mUID != -1 )
      this->mType = UFG::GameStat::GetMapBoolStatEnum(v11, 1);
  }
}

// File Line: 69
// RVA: 0x51B250
void __fastcall UFG::CollectibleComponent::~CollectibleComponent(UFG::CollectibleComponent *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CollectibleComponent::`vftable;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::CollectibleComponent::msCollectibleComponents,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::CollectibleComponent>);
  p_mpObject = &this->mpObject;
  if ( this->mpObject.m_pPointer )
  {
    mPrev = p_mpObject->mPrev;
    mNext = this->mpObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpObject->mPrev = p_mpObject;
    this->mpObject.mNext = &this->mpObject;
  }
  this->mpObject.m_pPointer = 0i64;
  v5 = p_mpObject->mPrev;
  v6 = this->mpObject.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpObject->mPrev = p_mpObject;
  this->mpObject.mNext = &this->mpObject;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 80
// RVA: 0x540070
void __fastcall UFG::CopSystem::HandleLastCharacterKill(
        UFG::CopSystem *this,
        UFG::EncounterUnitComponent *pEncounterUnit)
{
  this->vfptr[23].__vecDelDtor(this, (unsigned int)pEncounterUnit);
}

// File Line: 91
// RVA: 0x5344A0
void __fastcall UFG::CollectibleComponent::HandleModelSwap(UFG::CollectibleComponent *this, bool status)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::qPropertySet *mNext; // rsi

  if ( this->mPreviousStatus == status )
    goto LABEL_10;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pSceneObj;
  if ( !m_pSimObject )
  {
LABEL_10:
    this->mPreviousStatus = status;
  }
  else
  {
    mNext = (UFG::qPropertySet *)m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
    if ( !mNext )
      mNext = (UFG::qPropertySet *)m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
    if ( UFG::qPropertySet::Get<UFG::qSymbol>(
           mNext,
           (UFG::qArray<unsigned long,0> *)&qSymbol_CollectibleSpawnInfo_Collected,
           DEPTH_RECURSE)->mUID != -1 )
    {
      ((void (__fastcall *)(UFG::CollectibleComponent *))this->vfptr[27].__vecDelDtor)(this);
      ((void (__fastcall *)(UFG::CollectibleComponent *, UFG::qPropertySet *, bool))this->vfptr[26].__vecDelDtor)(
        this,
        mNext,
        status);
    }
    ((void (__fastcall *)(UFG::CollectibleComponent *))this->vfptr[29].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::CollectibleComponent *, UFG::qPropertySet *, bool))this->vfptr[28].__vecDelDtor)(
      this,
      mNext,
      status);
    this->mPreviousStatus = status;
  }
}

// File Line: 117
// RVA: 0x522E40
void __fastcall UFG::CollectibleComponent::Collect(UFG::CollectibleComponent *this, bool status)
{
  UFG::GameStatTracker *v4; // r14
  UFG::SimObject *m_pSimObject; // rbp
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qPropertySet *mpWritableProperties; // rsi
  UFG::qSymbol *Symbol; // rbx
  UFG::OSuiteDBLogger *v9; // r13
  int mUID; // ebx
  int v11; // ebx
  UFG::PersistentData::MapBool *MapBool; // rax
  int TrueCount; // ebx
  int v14; // r8d
  UFG::qSymbol *v15; // rax
  unsigned int v16; // eax
  bool *v17; // rax
  __int64 v18; // rdx
  UFG::CollectibleComponent *v19; // rcx
  bool v20; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  char dest[184]; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qSymbol rewardPropertySetName; // [rsp+F0h] [rbp+8h] BYREF
  UFG::qSymbol name; // [rsp+F8h] [rbp+10h] BYREF
  UFG::qSymbol *p_rewardPropertySetName; // [rsp+100h] [rbp+18h]

  v4 = UFG::GameStatTracker::Instance();
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject && (m_pSceneObj = m_pSimObject->m_pSceneObj) != 0i64 )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
  }
  else
  {
    mpWritableProperties = 0i64;
  }
  name.mUID = m_pSimObject->m_Name.mUID;
  if ( status && !UFG::GameStatTracker::GetStat(v4, this->mType, &name) )
  {
    Symbol = UFG::GameStat::GetSymbol(this->mType);
    v9 = UFG::OSuiteDBLogger::Instance();
    if ( UFG::OSuiteDBLogger::CreateMetric(v9, "Collectible") )
    {
      mUID = Symbol->mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "CollectibleType");
      OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, mUID);
      v11 = name.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "CollectibleName");
      OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, v11);
      MapBool = UFG::GameStatTracker::GetMapBool(v4, this->mType);
      TrueCount = UFG::PersistentData::MapBool::GetTrueCount(MapBool);
      UFG::qSPrintf(dest, 128, "i32_%s", "TotalFound");
      OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, TrueCount);
      UFG::OSuiteDBLogger::SubmitMetric(v9, 1);
    }
  }
  UFG::GameStatTracker::SetStat(v4, this->mType, &name, status);
  if ( status )
  {
    v14 = *UFG::qPropertySet::Get<long>(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&UFG::GameStat::Symbol_StatueUpgradePoint,
             DEPTH_RECURSE);
    if ( v14 > 0 )
      UFG::GameStatTracker::ApplyDelta(v4, StatueUpgradePoint, v14);
    v15 = UFG::qPropertySet::Get<UFG::qSymbol>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&qSymbol_RewardsPropertySet,
            DEPTH_RECURSE);
    if ( v15 )
    {
      v16 = v15->mUID;
      if ( v16 != -1 )
      {
        p_rewardPropertySetName = &rewardPropertySetName;
        rewardPropertySetName.mUID = v16;
        UFG::RewardsHandler::HandleRewards(ShowReward, &rewardPropertySetName, m_pSimObject->m_pSceneObj);
      }
    }
    v17 = UFG::qPropertySet::Get<bool>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&qSymbol_DeleteAfterUse,
            DEPTH_RECURSE);
    v19 = this;
    v20 = !*v17;
    vfptr = this->vfptr;
    if ( !v20 )
    {
      ((void (__fastcall *)(UFG::CollectibleComponent *))vfptr[23].__vecDelDtor)(this);
      return;
    }
    LOBYTE(v18) = 1;
  }
  else
  {
    vfptr = this->vfptr;
    v18 = 0i64;
    v19 = this;
  }
  vfptr[25].__vecDelDtor(v19, v18);
}

// File Line: 180
// RVA: 0x539ED0
bool __fastcall UFG::CollectibleComponent::IsCollected(UFG::CollectibleComponent *this)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::GameStatTracker *v3; // rax

  m_pSimObject = this->m_pSimObject;
  v3 = UFG::GameStatTracker::Instance();
  return UFG::GameStatTracker::GetStat(v3, this->mType, &m_pSimObject->m_Name);
}

// File Line: 187
// RVA: 0x53C2B0
__int64 __fastcall UFG::CollectibleComponent::IsUsable(UFG::CollectibleComponent *this)
{
  return ((__int64 (__fastcall *)(UFG::CollectibleComponent *))this->vfptr[19].__vecDelDtor)(this);
}

// File Line: 192
// RVA: 0x53B1F0
_BOOL8 __fastcall UFG::CollectibleComponent::IsLocked(UFG::CollectibleComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject && (m_pSceneObj = m_pSimObject->m_pSceneObj) != 0i64 )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
  }
  else
  {
    mpWritableProperties = 0i64;
  }
  return *UFG::qPropertySet::Get<bool>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&qSymbol_IsLocked,
            DEPTH_RECURSE);
}

// File Line: 199
// RVA: 0x5349C0
void __fastcall UFG::CollectibleComponent::HandleSpawnObject(
        UFG::CollectibleComponent *this,
        UFG::qPropertySet *pProperties,
        bool status)
{
  UFG::SimObject *pOwner; // rdi
  UFG::qPropertySet *v6; // rcx
  UFG::qSymbol *v7; // rbx
  UFG::SimObject *v8; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpObject; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qMatrix44 *m_pTransformNodeComponent; // rbx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  if ( !pProperties )
    return;
  pOwner = this->m_pSimObject;
  v6 = pProperties;
  if ( !status )
    goto LABEL_5;
  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pProperties,
         (UFG::qArray<unsigned long,0> *)&qSymbol_CollectibleSpawnInfo_Collected,
         DEPTH_RECURSE);
  if ( v7->mUID == -1 )
  {
    v6 = pProperties;
LABEL_5:
    v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
           v6,
           (UFG::qArray<unsigned long,0> *)&qSymbol_CollectibleSpawnInfo,
           DEPTH_RECURSE);
    if ( v7->mUID == -1 )
      return;
  }
  UFG::SimObjectUtility::GenerateUniqueActorName(&result, &pOwner->m_Name);
  v8 = UFG::SpawnInfoInterface::SpawnObject(&result, v7, UnReferenced, 0i64, 0i64, pOwner);
  p_mpObject = &this->mpObject;
  if ( this->mpObject.m_pPointer )
  {
    mPrev = p_mpObject->mPrev;
    mNext = this->mpObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpObject->mPrev = p_mpObject;
    this->mpObject.mNext = &this->mpObject;
  }
  this->mpObject.m_pPointer = v8;
  if ( v8 )
  {
    p_mNode = &v8->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v13 = v8->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v13->mNext = p_mpObject;
    p_mpObject->mPrev = v13;
    this->mpObject.mNext = p_mNode;
    p_mNode->mPrev = p_mpObject;
  }
  if ( pOwner )
  {
    m_pTransformNodeComponent = (UFG::qMatrix44 *)pOwner->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pOwner->m_pTransformNodeComponent);
      UFG::SimObjectUtility::Teleport(this->mpObject.m_pPointer, m_pTransformNodeComponent + 2);
    }
  }
}

// File Line: 233
// RVA: 0x534810
void __fastcall UFG::CollectibleComponent::HandleSpawnEffect(
        UFG::CollectibleComponent *this,
        UFG::qPropertySet *pProperties,
        bool status)
{
  UFG::SimObject *m_pSimObject; // rbp
  UFG::qStaticSymbol *v6; // rdx
  char *v7; // rax
  const char *v8; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  __int16 m_Flags; // cx
  unsigned int v12; // ebx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdx
  unsigned int v14; // eax
  UFG::qVector3 pos; // [rsp+38h] [rbp-50h] BYREF
  UFG::SimObjectModifier v16; // [rsp+48h] [rbp-40h] BYREF

  m_pSimObject = this->m_pSimObject;
  v6 = &qSymbol_CollectibleCollectedFalseEffect;
  if ( status )
    v6 = &qSymbol_CollectibleCollectedTrueEffect;
  v7 = UFG::qPropertySet::Get<char const *>(pProperties, (UFG::qArray<unsigned long,0> *)v6, DEPTH_RECURSE);
  v8 = v7;
  if ( v7 && *v7 )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "ProgressionTrigger.Indicator", 0i64, 1u);
    if ( v10 )
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v10, this->m_NameUID, 0i64, 0);
    this->mpEffectTransform = (UFG::TransformNodeComponent *)v10;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v12 = 2;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v12 = 2;
      }
      else
      {
        v12 = -1;
        if ( (m_Flags & 0x1000) != 0 )
          v12 = 1;
      }
    }
    else
    {
      v12 = 2;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v16, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v16, this->mpEffectTransform, v12);
    UFG::SimObjectModifier::Close(&v16);
    UFG::SimObjectModifier::~SimObjectModifier(&v16);
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
      UFG::TransformNodeComponent::SetParentKeepWorld(
        this->mpEffectTransform,
        m_pTransformNodeComponent,
        eInheritXform_Full);
    v14 = UFG::qStringHashUpper32(v8, -1);
    this->mEffectId = Render::FXManager::CreateEffect(
                        &Render::gFXManager,
                        v14,
                        this->mpEffectTransform,
                        0xFFFFFFFF,
                        0i64);
    *(_QWORD *)&pos.x = 0i64;
    pos.z = 0.0;
    UFG::TransformNodeComponent::SetLocalTranslation(this->mpEffectTransform, &pos);
  }
}

// File Line: 256
// RVA: 0x533C50
void __fastcall UFG::CollectibleComponent::HandleDespawnEffect(UFG::CollectibleComponent *this)
{
  unsigned int mEffectId; // edx
  UFG::TransformNodeComponent *mpEffectTransform; // rdx

  mEffectId = this->mEffectId;
  if ( mEffectId != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, mEffectId, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
    this->mEffectId = -1;
  }
  mpEffectTransform = this->mpEffectTransform;
  if ( mpEffectTransform )
  {
    UFG::Simulation::DestroySimComponent(&UFG::gSim, mpEffectTransform);
    this->mpEffectTransform = 0i64;
  }
}

// File Line: 270
// RVA: 0x533CB0
void __fastcall UFG::CollectibleComponent::HandleDespawnObject(UFG::CollectibleComponent *this)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pPointer = this->mpObject.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pPointer);
    p_mpObject = &this->mpObject;
    if ( this->mpObject.m_pPointer )
    {
      mPrev = p_mpObject->mPrev;
      mNext = this->mpObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpObject->mPrev = p_mpObject;
      this->mpObject.mNext = &this->mpObject;
    }
    this->mpObject.m_pPointer = 0i64;
  }
}

// File Line: 279
// RVA: 0x54FDC0
void __fastcall UFG::CollectibleComponent::Spawn(
        UFG::CollectibleComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rbp
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rbx
  unsigned __int8 v6; // al
  UFG::qPropertySet *mpConstProperties; // rbp
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // rbx
  unsigned __int8 v9; // al

  if ( this->mEnabled || !pSceneObj )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "Skipped spawn for collectible, already spawned [%s]\n");
  }
  else
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "@@@@@@@@@@@@@@@@@@@@@@@@@@@@ - Collectible [%s] ENABLED - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    vfptr = this->vfptr;
    v6 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))this->vfptr[19].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::CollectibleComponent *, UFG::qPropertySet *, _QWORD))vfptr[26].__vecDelDtor)(
      this,
      mpWritableProperties,
      v6);
    mpConstProperties = pSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSceneObj->mpConstProperties;
    v8 = this->vfptr;
    v9 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))this->vfptr[19].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::CollectibleComponent *, UFG::qPropertySet *, _QWORD))v8[28].__vecDelDtor)(
      this,
      mpConstProperties,
      v9);
    this->mEnabled = 1;
  }
}

// File Line: 296
// RVA: 0x5252F0
void __fastcall UFG::CollectibleComponent::Despawn(UFG::CollectibleComponent *this)
{
  bool v1; // zf
  UFG::SimObject *m_pSimObject; // rcx

  v1 = !this->mEnabled;
  m_pSimObject = this->m_pSimObject;
  if ( v1 )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "Skipped spawn for collectible, already spawned [%s]\n");
  }
  else
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "**************************** - Collectible [%s] DISABLED - ****************************\n");
    ((void (__fastcall *)(UFG::CollectibleComponent *))this->vfptr[27].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::CollectibleComponent *))this->vfptr[29].__vecDelDtor)(this);
    this->mEnabled = 0;
  }
}

// File Line: 313
// RVA: 0x52B580
UFG::CollectibleComponent *__fastcall UFG::CollectibleComponent::GetCollectibleComponent(UFG::SimObject *pSimObject)
{
  UFG::SimObject *m_pPointer; // rbx
  unsigned int v2; // r10d
  __int16 m_Flags; // cx
  unsigned int v4; // r8d
  unsigned int v5; // r9d
  __int64 v6; // rdx
  UFG::CollectibleComponent *result; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  unsigned int v10; // r8d
  unsigned int v11; // r9d
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  __int16 v15; // cx
  unsigned int v16; // r8d
  unsigned int v17; // r9d
  __int64 v18; // rdx
  unsigned int v19; // r8d
  unsigned int v20; // r9d
  unsigned int v21; // r8d
  unsigned int v22; // r9d
  unsigned int v23; // r8d
  unsigned int v24; // r9d
  UFG::SceneObjectProperties *mpParent; // rbx

  m_pPointer = pSimObject;
  if ( pSimObject )
  {
    v2 = UFG::CollectibleComponent::_TypeUID;
    while ( 1 )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        break;
      if ( m_Flags < 0 )
      {
        vfptr = (unsigned int)m_pPointer[1].vfptr;
        size = m_pPointer->m_Components.size;
        if ( vfptr >= size )
          goto LABEL_9;
        v6 = (__int64)&m_pPointer->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (v2 & 0xFE000000) || (v2 & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v6 += 16i64;
          if ( vfptr >= size )
          {
            result = 0i64;
            goto LABEL_33;
          }
        }
        goto LABEL_10;
      }
      if ( (m_Flags & 0x2000) != 0 )
      {
        v10 = (unsigned int)m_pPointer[1].vfptr;
        v11 = m_pPointer->m_Components.size;
        if ( v10 >= v11 )
          goto LABEL_9;
        v6 = (__int64)&m_pPointer->m_Components.p[v10];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (v2 & 0xFE000000) || (v2 & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v10;
          v6 += 16i64;
          if ( v10 >= v11 )
          {
            result = 0i64;
            goto LABEL_33;
          }
        }
        goto LABEL_10;
      }
      if ( (m_Flags & 0x1000) != 0 )
      {
        v12 = (unsigned int)m_pPointer[1].vfptr;
        v13 = m_pPointer->m_Components.size;
        if ( v12 >= v13 )
        {
LABEL_9:
          result = 0i64;
          goto LABEL_33;
        }
        v6 = (__int64)&m_pPointer->m_Components.p[v12];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (v2 & 0xFE000000) || (v2 & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v12;
          v6 += 16i64;
          if ( v12 >= v13 )
          {
            result = 0i64;
            goto LABEL_33;
          }
        }
        goto LABEL_10;
      }
      result = (UFG::CollectibleComponent *)UFG::SimObject::GetComponentOfType(m_pPointer, v2);
      v2 = UFG::CollectibleComponent::_TypeUID;
LABEL_33:
      if ( result )
        return result;
      m_pSceneObj = m_pPointer->m_pSceneObj;
      if ( !m_pSceneObj )
        return 0i64;
      m_pPointer = m_pSceneObj->mpOwner.m_pPointer;
      if ( !m_pPointer )
      {
        mpParent = m_pSceneObj->mpParent;
        if ( !mpParent )
          return 0i64;
        m_pPointer = mpParent->m_pSimObject;
        goto LABEL_70;
      }
      v15 = m_pPointer->m_Flags;
      if ( (v15 & 0x4000) != 0 )
      {
        v16 = (unsigned int)m_pPointer[1].vfptr;
        v17 = m_pPointer->m_Components.size;
        if ( v16 >= v17 )
          goto LABEL_42;
        v18 = (__int64)&m_pPointer->m_Components.p[v16];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (v2 & 0xFE000000)
             || (v2 & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v16;
          v18 += 16i64;
          if ( v16 >= v17 )
            goto LABEL_42;
        }
LABEL_43:
        result = *(UFG::CollectibleComponent **)v18;
        goto LABEL_66;
      }
      if ( v15 < 0 )
      {
        v19 = (unsigned int)m_pPointer[1].vfptr;
        v20 = m_pPointer->m_Components.size;
        if ( v19 >= v20 )
          goto LABEL_42;
        v18 = (__int64)&m_pPointer->m_Components.p[v19];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (v2 & 0xFE000000)
             || (v2 & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v19;
          v18 += 16i64;
          if ( v19 >= v20 )
          {
            result = 0i64;
            goto LABEL_66;
          }
        }
        goto LABEL_43;
      }
      if ( (v15 & 0x2000) != 0 )
      {
        v21 = (unsigned int)m_pPointer[1].vfptr;
        v22 = m_pPointer->m_Components.size;
        if ( v21 >= v22 )
          goto LABEL_42;
        v18 = (__int64)&m_pPointer->m_Components.p[v21];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (v2 & 0xFE000000)
             || (v2 & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v21;
          v18 += 16i64;
          if ( v21 >= v22 )
          {
            result = 0i64;
            goto LABEL_66;
          }
        }
        goto LABEL_43;
      }
      if ( (v15 & 0x1000) != 0 )
      {
        v23 = (unsigned int)m_pPointer[1].vfptr;
        v24 = m_pPointer->m_Components.size;
        if ( v23 >= v24 )
        {
LABEL_42:
          result = 0i64;
          goto LABEL_66;
        }
        v18 = (__int64)&m_pPointer->m_Components.p[v23];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (v2 & 0xFE000000)
             || (v2 & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v23;
          v18 += 16i64;
          if ( v23 >= v24 )
          {
            result = 0i64;
            goto LABEL_66;
          }
        }
        goto LABEL_43;
      }
      result = (UFG::CollectibleComponent *)UFG::SimObject::GetComponentOfType(m_pPointer, v2);
      v2 = UFG::CollectibleComponent::_TypeUID;
LABEL_66:
      if ( result )
        return result;
LABEL_70:
      if ( !m_pPointer )
        return 0i64;
    }
    v4 = (unsigned int)m_pPointer[1].vfptr;
    v5 = m_pPointer->m_Components.size;
    if ( v4 >= v5 )
      goto LABEL_9;
    v6 = (__int64)&m_pPointer->m_Components.p[v4];
    while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (v2 & 0xFE000000) || (v2 & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v4;
      v6 += 16i64;
      if ( v4 >= v5 )
        goto LABEL_9;
    }
LABEL_10:
    result = *(UFG::CollectibleComponent **)v6;
    goto LABEL_33;
  }
  return 0i64;
}

// File Line: 355
// RVA: 0x52B550
UFG::qBaseNodeRB *__fastcall UFG::CollectibleComponent::GetCollectibleComponent(UFG::qSymbol *name)
{
  UFG::qBaseTreeRB *v1; // rax

  if ( name->mUID
    && (v1 = UFG::qBaseTreeRB::Get(&UFG::CollectibleComponent::msCollectibleComponents.mTree, name->mUID)) != 0i64 )
  {
    return &v1[-2].mNULL;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 361
// RVA: 0x5354E0
bool __fastcall UFG::CollectibleComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentCollectible,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 367
// RVA: 0x5445A0
UFG::CollectibleComponent *__fastcall UFG::CollectibleComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // edx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v7; // r8
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v9; // edx
  unsigned int v10; // r9d
  unsigned int v11; // edx
  unsigned int v12; // r9d
  unsigned int v13; // edx
  unsigned int v14; // r9d
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v17; // rsi
  UFG::SimObject *v18; // rbx
  UFG::qSymbol *v19; // rax
  __int64 v20; // rax
  __int64 v21; // rbx
  UFG::qPropertySet *mpWritableProperties; // rdi
  UFG::qSymbol *v23; // rax
  UFG::qSymbol *v24; // rcx
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::allocator::free_link *v26; // [rsp+68h] [rbp+10h]

  m_pSimObject = pSceneObj->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_35;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_10;
      }
LABEL_9:
      m_pComponent = p[v7].m_pComponent;
      goto LABEL_33;
    }
    goto LABEL_10;
  }
  if ( m_Flags < 0 )
  {
    v9 = (unsigned int)m_pSimObject[1].vfptr;
    v10 = m_pSimObject->m_Components.size;
    if ( v9 < v10 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = v9;
        if ( (p[v9].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v9].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
        if ( ++v9 >= v10 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v11 = (unsigned int)m_pSimObject[1].vfptr;
    v12 = m_pSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = v11;
        if ( (p[v11].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v11].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
        if ( ++v11 >= v12 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v13 = (unsigned int)m_pSimObject[1].vfptr;
    v14 = m_pSimObject->m_Components.size;
    if ( v13 < v14 )
    {
      p = m_pSimObject->m_Components.p;
      do
      {
        v7 = v13;
        if ( (p[v13].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v13].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
      }
      while ( ++v13 < v14 );
    }
LABEL_10:
    m_pComponent = 0i64;
    goto LABEL_33;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CollectibleComponent::_TypeUID);
LABEL_33:
  if ( m_pComponent )
    return 0i64;
LABEL_35:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v17 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC8ui64, "CollectibleComponent", 0i64, 1u);
  v26 = v17;
  if ( v17 )
  {
    v18 = pSceneObj->m_pSimObject;
    v19 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(
                            pSceneObj,
                            (UFG::qWiseSymbol *)&result);
    UFG::CollectibleComponent::CollectibleComponent((UFG::CollectibleComponent *)v17, v19, v18);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  *(_WORD *)(v21 + 194) = (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v21 + 152i64))(v21);
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  if ( *UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&qSymbol_DeleteAfterUse,
          DEPTH_RECURSE) )
    *(_BYTE *)(v21 + 195) = 1;
  v23 = UFG::qPropertySet::Get<UFG::qSymbol>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_UnlocksAfter,
          DEPTH_RECURSE);
  v24 = &UFG::gNullQSymbol;
  if ( v23 )
    v24 = v23;
  *(UFG::qSymbol *)(v21 + 188) = (UFG::qSymbol)v24->mUID;
  return (UFG::CollectibleComponent *)v21;
}

// File Line: 390
// RVA: 0x560EF0
void __fastcall UFG::CollectibleComponent::UpdateStatus(float deltaTime)
{
  UFG::ProgressionTracker *v1; // r14
  Render::SkinningCacheNode *Head; // rax
  char *p_mNULL; // rbx
  __int64 v4; // rbp
  char v5; // di
  __int64 v6; // rsi
  UFG::qBaseTreeRB *v7; // rax
  __int64 v8; // rax
  UFG::qBaseTreeRB *Next; // rax

  v1 = UFG::ProgressionTracker::Instance();
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::CollectibleComponent::msCollectibleComponents);
  p_mNULL = (char *)&Head[-3].mNode.8;
  if ( !Head )
    p_mNULL = 0i64;
  while ( p_mNULL )
  {
    v4 = *((_QWORD *)p_mNULL + 5);
    v5 = 1;
    if ( *((_DWORD *)p_mNULL + 46) == -1 )
    {
      v6 = *(_QWORD *)(v4 + 88);
      if ( v6 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v4 + 88));
        *((_DWORD *)p_mNULL + 46) = UFG::SectionChooser::GetVisIndexAtPosition((UFG::qVector3 *)(v6 + 176), 0);
      }
    }
    if ( !UFG::SectionChooser::IsSectionVisible_VisIndex(*((_DWORD *)p_mNULL + 46), SCENERY_LAYER_STD, 0) )
    {
      v5 = 0;
      goto LABEL_16;
    }
    if ( p_mNULL[192] )
    {
      v5 = 0;
      v7 = UFG::ProgressionTracker::Find(v1, (UFG::qSymbol *)p_mNULL + 47, 0);
      if ( !v7 || SLODWORD(v7[3].mNULL.mChild[1]) < 1 && SWORD2(v7[5].mRoot.mParent) <= 0 )
        goto LABEL_16;
      v5 = 1;
    }
    if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)p_mNULL + 152i64))(p_mNULL) )
      v5 = p_mNULL[195] == 0;
LABEL_16:
    if ( v5 != p_mNULL[193] )
    {
      v8 = *(_QWORD *)p_mNULL;
      if ( v5 )
        (*(void (__fastcall **)(char *, _QWORD))(v8 + 176))(p_mNULL, *(_QWORD *)(v4 + 80));
      else
        (*(void (__fastcall **)(char *))(v8 + 184))(p_mNULL);
    }
    (*(void (__fastcall **)(char *))(*(_QWORD *)p_mNULL + 144i64))(p_mNULL);
    Next = UFG::qBaseTreeRB::GetNext(
             &UFG::CollectibleComponent::msCollectibleComponents.mTree,
             (UFG::qBaseNodeRB *)(p_mNULL + 112));
    if ( Next )
      p_mNULL = (char *)&Next[-2].mNULL;
    else
      p_mNULL = 0i64;
  }
}

