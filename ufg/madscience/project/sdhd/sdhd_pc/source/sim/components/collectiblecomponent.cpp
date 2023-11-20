// File Line: 34
// RVA: 0x15438A0
__int64 dynamic_initializer_for__UFG::CollectibleComponent::msCollectibleComponents__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::CollectibleComponent::msCollectibleComponents.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::CollectibleComponent::msCollectibleComponents__);
}

// File Line: 35
// RVA: 0x5323E0
const char *__fastcall UFG::CollectibleComponent::GetTypeName(UFG::CollectibleComponent *this)
{
  return "CollectibleComponent";
}

// File Line: 50
// RVA: 0x516A70
void __fastcall UFG::CollectibleComponent::CollectibleComponent(UFG::CollectibleComponent *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v3; // rdi
  UFG::qSymbol *v4; // rbx
  UFG::CollectibleComponent *v5; // rsi
  unsigned int v6; // eax
  signed __int64 v7; // rdx
  char v8; // bp
  UFG::SceneObjectProperties *v9; // rax
  UFG::qPropertySet *v10; // rbx
  UFG::qSymbol *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // [rsp+58h] [rbp+10h]

  v3 = pSimObj;
  v4 = name;
  v5 = this;
  UFG::SpawnPointInterface::SpawnPointInterface((UFG::SpawnPointInterface *)&this->vfptr, name, pSimObj);
  v6 = v4->mUID;
  v7 = (signed __int64)&v5->mNode;
  v8 = 0;
  *(_QWORD *)v7 = 0i64;
  *(_QWORD *)(v7 + 8) = 0i64;
  *(_QWORD *)(v7 + 16) = 0i64;
  *(_DWORD *)(v7 + 24) = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CollectibleComponent::`vftable';
  v13 = &v5->mpObject;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v5->mpObject.m_pPointer = 0i64;
  v5->mpEffectTransform = 0i64;
  v5->mType = 2;
  *(_QWORD *)&v5->mEffectId = -1i64;
  v5->mUnlocksAfter = UFG::gNullQSymbol;
  *(_DWORD *)&v5->mProgressionBased = 0;
  UFG::qBaseTreeRB::Add(&UFG::CollectibleComponent::msCollectibleComponents.mTree, &v5->mNode);
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::CollectibleComponent::_CollectibleComponentTypeUID,
    "CollectibleComponent");
  v9 = v3->m_pSceneObj;
  v10 = v9->mpWritableProperties;
  if ( !v10 )
    v10 = v9->mpConstProperties;
  v11 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&SimSym_UnlocksAfter.mUID, DEPTH_RECURSE);
  if ( v11 && v11->mUID != -1 )
    v8 = 1;
  v5->mProgressionBased = v8;
  v12 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&SimSym_CollectibleType.mUID, DEPTH_RECURSE);
  if ( v12 )
  {
    if ( v12->mUID != -1 )
      v5->mType = UFG::GameStat::GetMapBoolStatEnum(v12, 1);
  }
}

// File Line: 69
// RVA: 0x51B250
void __fastcall UFG::CollectibleComponent::~CollectibleComponent(UFG::CollectibleComponent *this)
{
  UFG::CollectibleComponent *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CollectibleComponent::`vftable';
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::CollectibleComponent::msCollectibleComponents,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->mNode);
  v2 = &v1->mpObject;
  if ( v1->mpObject.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mpObject.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mpObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpObject.mPrev;
  }
  v1->mpObject.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mpObject.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mpObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpObject.mPrev;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 80
// RVA: 0x540070
void __fastcall UFG::CopSystem::HandleLastCharacterKill(UFG::CopSystem *this, UFG::EncounterUnitComponent *pEncounterUnit)
{
  this->vfptr[23].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)this, (unsigned int)pEncounterUnit);
}

// File Line: 91
// RVA: 0x5344A0
void __fastcall UFG::CollectibleComponent::HandleModelSwap(UFG::CollectibleComponent *this, bool status)
{
  bool v2; // di
  UFG::CollectibleComponent *v3; // rbx
  UFG::SimObject *v4; // rax
  UFG::qPropertySet *v5; // rsi

  v2 = status;
  v3 = this;
  if ( this->mPreviousStatus == status )
    goto LABEL_13;
  v4 = this->m_pSimObject;
  if ( v4 )
    v4 = (UFG::SimObject *)v4->m_pSceneObj;
  if ( v4 )
  {
    v5 = (UFG::qPropertySet *)v4[1].m_SafePointerList.mNode.mNext;
    if ( !v5 )
      v5 = (UFG::qPropertySet *)v4[1].m_SafePointerWithCallbackList.mNode.mPrev;
    if ( UFG::qPropertySet::Get<UFG::qSymbol>(
           v5,
           (UFG::qSymbol *)&qSymbol_CollectibleSpawnInfo_Collected.mUID,
           DEPTH_RECURSE)->mUID != -1 )
    {
      ((void (__fastcall *)(UFG::CollectibleComponent *))v3->vfptr[27].__vecDelDtor)(v3);
      ((void (__fastcall *)(UFG::CollectibleComponent *, UFG::qPropertySet *, bool))v3->vfptr[26].__vecDelDtor)(
        v3,
        v5,
        v2);
    }
    ((void (__fastcall *)(UFG::CollectibleComponent *))v3->vfptr[29].__vecDelDtor)(v3);
    ((void (__fastcall *)(UFG::CollectibleComponent *, UFG::qPropertySet *, bool))v3->vfptr[28].__vecDelDtor)(
      v3,
      v5,
      v2);
    v3->mPreviousStatus = v2;
  }
  else
  {
LABEL_13:
    this->mPreviousStatus = status;
  }
}

// File Line: 117
// RVA: 0x522E40
void __fastcall UFG::CollectibleComponent::Collect(UFG::CollectibleComponent *this, bool status)
{
  bool v2; // r15
  UFG::CollectibleComponent *v3; // rdi
  UFG::GameStatTracker *v4; // r14
  UFG::SimObject *v5; // rbp
  UFG::SceneObjectProperties *v6; // rcx
  UFG::qPropertySet *v7; // rsi
  UFG::qSymbol *v8; // rbx
  UFG::OSuiteDBLogger *v9; // r13
  int v10; // ebx
  int v11; // ebx
  UFG::PersistentData::MapBool *v12; // rax
  int v13; // ebx
  int v14; // er8
  UFG::qSymbol *v15; // rax
  unsigned int v16; // eax
  bool *v17; // rax
  __int64 v18; // rdx
  UFG::CollectibleComponent *v19; // rcx
  bool v20; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v21; // rax
  char dest; // [rsp+30h] [rbp-B8h]
  UFG::qSymbol rewardPropertySetName; // [rsp+F0h] [rbp+8h]
  UFG::qSymbol name; // [rsp+F8h] [rbp+10h]
  UFG::qSymbol *v25; // [rsp+100h] [rbp+18h]

  v2 = status;
  v3 = this;
  v4 = UFG::GameStatTracker::Instance();
  v5 = v3->m_pSimObject;
  if ( v5 && (v6 = v5->m_pSceneObj) != 0i64 )
  {
    v7 = v6->mpWritableProperties;
    if ( !v7 )
      v7 = v6->mpConstProperties;
  }
  else
  {
    v7 = 0i64;
  }
  name.mUID = v5->m_Name.mUID;
  if ( v2 && !UFG::GameStatTracker::GetStat(v4, v3->mType, &name) )
  {
    v8 = UFG::GameStat::GetSymbol(v3->mType);
    v9 = UFG::OSuiteDBLogger::Instance();
    if ( UFG::OSuiteDBLogger::CreateMetric(v9, "Collectible") )
    {
      v10 = v8->mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "CollectibleType", -2i64);
      OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v10);
      v11 = name.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "CollectibleName");
      OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v11);
      v12 = UFG::GameStatTracker::GetMapBool(v4, v3->mType);
      v13 = UFG::PersistentData::MapBool::GetTrueCount(v12);
      UFG::qSPrintf(&dest, 128, "i32_%s", "TotalFound");
      OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v13);
      UFG::OSuiteDBLogger::SubmitMetric(v9, 1);
    }
  }
  UFG::GameStatTracker::SetStat(v4, v3->mType, &name, v2);
  if ( v2 == 1 )
  {
    v14 = *UFG::qPropertySet::Get<long>(
             v7,
             (UFG::qSymbol *)&UFG::GameStat::Symbol_StatueUpgradePoint.mUID,
             DEPTH_RECURSE);
    if ( v14 > 0 )
      UFG::GameStatTracker::ApplyDelta(v4, StatueUpgradePoint, v14);
    v15 = UFG::qPropertySet::Get<UFG::qSymbol>(v7, (UFG::qSymbol *)&qSymbol_RewardsPropertySet.mUID, DEPTH_RECURSE);
    if ( v15 )
    {
      v16 = v15->mUID;
      if ( v16 != -1 )
      {
        v25 = &rewardPropertySetName;
        rewardPropertySetName.mUID = v16;
        UFG::RewardsHandler::HandleRewards(0, (__int64)&rewardPropertySetName, v5->m_pSceneObj);
      }
    }
    v17 = UFG::qPropertySet::Get<bool>(v7, (UFG::qSymbol *)&qSymbol_DeleteAfterUse.mUID, DEPTH_RECURSE);
    v19 = v3;
    v20 = *v17 == 0;
    v21 = v3->vfptr;
    if ( !v20 )
    {
      ((void (__fastcall *)(UFG::CollectibleComponent *))v21[23].__vecDelDtor)(v3);
      return;
    }
    LOBYTE(v18) = 1;
  }
  else
  {
    v21 = v3->vfptr;
    v18 = 0i64;
    v19 = v3;
  }
  v21[25].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v19->vfptr, v18);
}

// File Line: 180
// RVA: 0x539ED0
bool __fastcall UFG::CollectibleComponent::IsCollected(UFG::CollectibleComponent *this)
{
  UFG::SimObject *v1; // rbx
  UFG::CollectibleComponent *v2; // rdi
  UFG::GameStatTracker *v3; // rax

  v1 = this->m_pSimObject;
  v2 = this;
  v3 = UFG::GameStatTracker::Instance();
  return UFG::GameStatTracker::GetStat(v3, v2->mType, &v1->m_Name);
}

// File Line: 187
// RVA: 0x53C2B0
__int64 __fastcall UFG::CollectibleComponent::IsUsable(UFG::CollectibleComponent *this)
{
  return ((__int64 (*)(void))this->vfptr[19].__vecDelDtor)();
}

// File Line: 192
// RVA: 0x53B1F0
_BOOL8 __fastcall UFG::CollectibleComponent::IsLocked(UFG::CollectibleComponent *this)
{
  UFG::SimObject *v1; // rax
  UFG::SceneObjectProperties *v2; // rax
  UFG::qPropertySet *v3; // rcx

  v1 = this->m_pSimObject;
  if ( v1 && (v2 = v1->m_pSceneObj) != 0i64 )
  {
    v3 = v2->mpWritableProperties;
    if ( !v3 )
      v3 = v2->mpConstProperties;
  }
  else
  {
    v3 = 0i64;
  }
  return *UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_IsLocked.mUID, DEPTH_RECURSE);
}

// File Line: 199
// RVA: 0x5349C0
void __fastcall UFG::CollectibleComponent::HandleSpawnObject(UFG::CollectibleComponent *this, UFG::qPropertySet *pProperties, bool status)
{
  UFG::SimObject *pOwner; // rdi
  UFG::CollectibleComponent *v4; // rbp
  UFG::qPropertySet *v5; // rsi
  UFG::qPropertySet *v6; // rcx
  UFG::qSymbol *v7; // rbx
  UFG::SimObject *v8; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qMatrix44 *v14; // rbx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  if ( !pProperties )
    return;
  pOwner = this->m_pSimObject;
  v4 = this;
  v5 = pProperties;
  v6 = pProperties;
  if ( !status )
    goto LABEL_5;
  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pProperties,
         (UFG::qSymbol *)&qSymbol_CollectibleSpawnInfo_Collected.mUID,
         DEPTH_RECURSE);
  if ( v7->mUID == -1 )
  {
    v6 = v5;
LABEL_5:
    v7 = UFG::qPropertySet::Get<UFG::qSymbol>(v6, (UFG::qSymbol *)&qSymbol_CollectibleSpawnInfo.mUID, DEPTH_RECURSE);
    if ( v7->mUID == -1 )
      return;
  }
  UFG::SimObjectUtility::GenerateUniqueActorName(&result, &pOwner->m_Name);
  v8 = UFG::SpawnInfoInterface::SpawnObject(&result, v7, 0, 0i64, 0i64, pOwner);
  v9 = &v4->mpObject;
  if ( v4->mpObject.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v4->mpObject.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v4->mpObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mpObject.mPrev;
  }
  v4->mpObject.m_pPointer = v8;
  if ( v8 )
  {
    v12 = &v8->m_SafePointerList;
    v13 = v8->m_SafePointerList.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v13;
    v4->mpObject.mNext = &v12->mNode;
    v12->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  if ( pOwner )
  {
    v14 = (UFG::qMatrix44 *)pOwner->m_pTransformNodeComponent;
    if ( v14 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pOwner->m_pTransformNodeComponent);
      UFG::SimObjectUtility::Teleport(v4->mpObject.m_pPointer, v14 + 2);
    }
  }
}

// File Line: 233
// RVA: 0x534810
void __fastcall UFG::CollectibleComponent::HandleSpawnEffect(UFG::CollectibleComponent *this, UFG::qPropertySet *pProperties, bool status)
{
  UFG::qPropertySet *v3; // rax
  UFG::CollectibleComponent *v4; // rdi
  UFG::SimObject *v5; // rbp
  UFG::qStaticSymbol *v6; // rdx
  char *v7; // rax
  const char *v8; // rsi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  unsigned __int16 v11; // cx
  unsigned int v12; // ebx
  UFG::TransformNodeComponent *v13; // rdx
  unsigned int v14; // eax
  UFG::qVector3 pos; // [rsp+38h] [rbp-50h]
  UFG::SimObjectModifier v16; // [rsp+48h] [rbp-40h]

  v3 = pProperties;
  v4 = this;
  v5 = this->m_pSimObject;
  v6 = &qSymbol_CollectibleCollectedFalseEffect;
  if ( status )
    v6 = &qSymbol_CollectibleCollectedTrueEffect;
  v7 = UFG::qPropertySet::Get<char const *>(v3, (UFG::qSymbol *)&v6->mUID, DEPTH_RECURSE);
  v8 = v7;
  if ( v7 && *v7 )
  {
    v9 = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(v9, 0x110ui64, "ProgressionTrigger.Indicator", 0i64, 1u);
    if ( v10 )
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v10, v4->m_NameUID, 0i64, 0);
    v4->mpEffectTransform = (UFG::TransformNodeComponent *)v10;
    v11 = v5->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = 2;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v12 = 2;
      }
      else
      {
        v12 = -1;
        if ( (v11 >> 12) & 1 )
          v12 = 1;
      }
    }
    else
    {
      v12 = 2;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v16, v5, 1);
    UFG::SimObjectModifier::AttachComponent(&v16, (UFG::SimComponent *)&v4->mpEffectTransform->vfptr, v12);
    UFG::SimObjectModifier::Close(&v16);
    UFG::SimObjectModifier::~SimObjectModifier(&v16);
    v13 = v5->m_pTransformNodeComponent;
    if ( v13 )
      UFG::TransformNodeComponent::SetParentKeepWorld(v4->mpEffectTransform, v13, 0);
    v14 = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
    v4->mEffectId = Render::FXManager::CreateEffect(&Render::gFXManager, v14, v4->mpEffectTransform, 0xFFFFFFFF, 0i64);
    *(_QWORD *)&pos.x = 0i64;
    pos.z = 0.0;
    UFG::TransformNodeComponent::SetLocalTranslation(v4->mpEffectTransform, &pos);
  }
}

// File Line: 256
// RVA: 0x533C50
void __fastcall UFG::CollectibleComponent::HandleDespawnEffect(UFG::CollectibleComponent *this)
{
  unsigned int v1; // edx
  UFG::CollectibleComponent *v2; // rbx
  UFG::SimComponent *v3; // rdx

  v1 = this->mEffectId;
  v2 = this;
  if ( v1 != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, v1, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
    v2->mEffectId = -1;
  }
  v3 = (UFG::SimComponent *)&v2->mpEffectTransform->vfptr;
  if ( v3 )
  {
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v3);
    v2->mpEffectTransform = 0i64;
  }
}

// File Line: 270
// RVA: 0x533CB0
void __fastcall UFG::CollectibleComponent::HandleDespawnObject(UFG::CollectibleComponent *this)
{
  UFG::SimObject *v1; // rdx
  UFG::CollectibleComponent *v2; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this->mpObject.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v1);
    v3 = &v2->mpObject;
    if ( v2->mpObject.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v2->mpObject.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v2->mpObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpObject.mPrev;
    }
    v2->mpObject.m_pPointer = 0i64;
  }
}

// File Line: 279
// RVA: 0x54FDC0
void __fastcall UFG::CollectibleComponent::Spawn(UFG::CollectibleComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rsi
  UFG::CollectibleComponent *v3; // rdi
  UFG::qPropertySet *v4; // rbp
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v5; // rbx
  unsigned __int8 v6; // al
  UFG::qPropertySet *v7; // rbp
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // rbx
  unsigned __int8 v9; // al

  v2 = pSceneObj;
  v3 = this;
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
    v4 = v2->mpWritableProperties;
    if ( !v4 )
      v4 = v2->mpConstProperties;
    v5 = v3->vfptr;
    v6 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v3->vfptr[19].__vecDelDtor)(v3);
    ((void (__fastcall *)(UFG::CollectibleComponent *, UFG::qPropertySet *, _QWORD))v5[26].__vecDelDtor)(v3, v4, v6);
    v7 = v2->mpWritableProperties;
    if ( !v7 )
      v7 = v2->mpConstProperties;
    v8 = v3->vfptr;
    v9 = ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v3->vfptr[19].__vecDelDtor)(v3);
    ((void (__fastcall *)(UFG::CollectibleComponent *, UFG::qPropertySet *, _QWORD))v8[28].__vecDelDtor)(v3, v7, v9);
    v3->mEnabled = 1;
  }
}

// File Line: 296
// RVA: 0x5252F0
void __fastcall UFG::CollectibleComponent::Despawn(UFG::CollectibleComponent *this)
{
  bool v1; // zf
  UFG::CollectibleComponent *v2; // rbx
  UFG::SimObject *v3; // rcx

  v1 = this->mEnabled == 0;
  v2 = this;
  v3 = this->m_pSimObject;
  if ( v1 )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "Skipped spawn for collectible, already spawned [%s]\n");
  }
  else
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "**************************** - Collectible [%s] DISABLED - ****************************\n");
    ((void (__fastcall *)(UFG::CollectibleComponent *))v2->vfptr[27].__vecDelDtor)(v2);
    ((void (__fastcall *)(UFG::CollectibleComponent *))v2->vfptr[29].__vecDelDtor)(v2);
    v2->mEnabled = 0;
  }
}

// File Line: 313
// RVA: 0x52B580
UFG::CollectibleComponent *__fastcall UFG::CollectibleComponent::GetCollectibleComponent(UFG::SimObject *pSimObject)
{
  UFG::SimObject *v1; // rbx
  unsigned int v2; // er10
  unsigned __int16 v3; // cx
  unsigned int v4; // er8
  unsigned int v5; // er9
  signed __int64 v6; // rdx
  UFG::CollectibleComponent *result; // rax
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned int v10; // er8
  unsigned int v11; // er9
  unsigned int v12; // er8
  unsigned int v13; // er9
  UFG::SceneObjectProperties *v14; // rax
  unsigned __int16 v15; // cx
  unsigned int v16; // er8
  unsigned int v17; // er9
  signed __int64 v18; // rdx
  unsigned int v19; // er8
  unsigned int v20; // er9
  unsigned int v21; // er8
  unsigned int v22; // er9
  unsigned int v23; // er8
  unsigned int v24; // er9
  UFG::SceneObjectProperties *v25; // rbx

  v1 = pSimObject;
  if ( pSimObject )
  {
    v2 = UFG::CollectibleComponent::_TypeUID;
    if ( !pSimObject )
      goto LABEL_34;
    while ( 1 )
    {
      v3 = v1->m_Flags;
      if ( (v3 >> 14) & 1 )
        break;
      if ( (v3 & 0x8000u) != 0 )
      {
        v8 = (unsigned int)v1[1].vfptr;
        v9 = v1->m_Components.size;
        if ( v8 >= v9 )
          goto LABEL_9;
        v6 = (signed __int64)&v1->m_Components.p[v8];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (v2 & 0xFE000000) || v2 & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
        {
          ++v8;
          v6 += 16i64;
          if ( v8 >= v9 )
          {
            result = 0i64;
            goto LABEL_33;
          }
        }
        goto LABEL_10;
      }
      if ( (v3 >> 13) & 1 )
      {
        v10 = (unsigned int)v1[1].vfptr;
        v11 = v1->m_Components.size;
        if ( v10 >= v11 )
          goto LABEL_9;
        v6 = (signed __int64)&v1->m_Components.p[v10];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (v2 & 0xFE000000) || v2 & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
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
      if ( (v3 >> 12) & 1 )
      {
        v12 = (unsigned int)v1[1].vfptr;
        v13 = v1->m_Components.size;
        if ( v12 >= v13 )
        {
LABEL_9:
          result = 0i64;
          goto LABEL_33;
        }
        v6 = (signed __int64)&v1->m_Components.p[v12];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (v2 & 0xFE000000) || v2 & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
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
      result = (UFG::CollectibleComponent *)UFG::SimObject::GetComponentOfType(v1, v2);
      v2 = UFG::CollectibleComponent::_TypeUID;
LABEL_33:
      if ( result )
        return result;
LABEL_34:
      v14 = v1->m_pSceneObj;
      if ( !v14 )
        return 0i64;
      v1 = v14->mpOwner.m_pPointer;
      if ( !v1 )
      {
        v25 = v14->mpParent;
        if ( !v25 )
          return 0i64;
        v1 = v25->m_pSimObject;
        goto LABEL_70;
      }
      v15 = v1->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = (unsigned int)v1[1].vfptr;
        v17 = v1->m_Components.size;
        if ( v16 >= v17 )
          goto LABEL_42;
        v18 = (signed __int64)&v1->m_Components.p[v16];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (v2 & 0xFE000000) || v2 & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
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
      if ( (v15 & 0x8000u) != 0 )
      {
        v19 = (unsigned int)v1[1].vfptr;
        v20 = v1->m_Components.size;
        if ( v19 >= v20 )
          goto LABEL_42;
        v18 = (signed __int64)&v1->m_Components.p[v19];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (v2 & 0xFE000000) || v2 & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
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
      if ( (v15 >> 13) & 1 )
      {
        v21 = (unsigned int)v1[1].vfptr;
        v22 = v1->m_Components.size;
        if ( v21 >= v22 )
          goto LABEL_42;
        v18 = (signed __int64)&v1->m_Components.p[v21];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (v2 & 0xFE000000) || v2 & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
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
      if ( (v15 >> 12) & 1 )
      {
        v23 = (unsigned int)v1[1].vfptr;
        v24 = v1->m_Components.size;
        if ( v23 >= v24 )
        {
LABEL_42:
          result = 0i64;
          goto LABEL_66;
        }
        v18 = (signed __int64)&v1->m_Components.p[v23];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (v2 & 0xFE000000) || v2 & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
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
      result = (UFG::CollectibleComponent *)UFG::SimObject::GetComponentOfType(v1, v2);
      v2 = UFG::CollectibleComponent::_TypeUID;
LABEL_66:
      if ( result )
        return result;
LABEL_70:
      if ( !v1 )
        return 0i64;
    }
    v4 = (unsigned int)v1[1].vfptr;
    v5 = v1->m_Components.size;
    if ( v4 >= v5 )
      goto LABEL_9;
    v6 = (signed __int64)&v1->m_Components.p[v4];
    while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (v2 & 0xFE000000) || v2 & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
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
  UFG::qBaseNodeRB *result; // rax

  if ( name->mUID
    && (v1 = UFG::qBaseTreeRB::Get(&UFG::CollectibleComponent::msCollectibleComponents.mTree, name->mUID)) != 0i64 )
  {
    result = &v1[-2].mNULL;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 361
// RVA: 0x5354E0
bool __fastcall UFG::CollectibleComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentCollectible.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 367
// RVA: 0x5445A0
UFG::CollectibleComponent *__fastcall UFG::CollectibleComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  unsigned int v4; // edx
  unsigned int v5; // er9
  UFG::SimComponentHolder *v6; // rbx
  signed __int64 v7; // r8
  UFG::SimComponent *v8; // rax
  unsigned int v9; // edx
  unsigned int v10; // er9
  unsigned int v11; // edx
  unsigned int v12; // er9
  unsigned int v13; // edx
  unsigned int v14; // er9
  UFG::qMemoryPool *v16; // rax
  UFG::allocator::free_link *v17; // rsi
  UFG::SimObject *v18; // rbx
  UFG::qSymbol *v19; // rax
  __int64 v20; // rax
  __int64 v21; // rbx
  UFG::qPropertySet *v22; // rdi
  UFG::qSymbol *v23; // rax
  UFG::qSymbol *v24; // rcx
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v26; // [rsp+68h] [rbp+10h]

  v1 = pSceneObj;
  v2 = pSceneObj->m_pSimObject;
  if ( !v2 )
    goto LABEL_35;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = (unsigned int)v2[1].vfptr;
    v5 = v2->m_Components.size;
    if ( v4 < v5 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v4;
        if ( (v6[v4].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v4].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v4 >= v5 )
          goto LABEL_10;
      }
LABEL_9:
      v8 = v6[v7].m_pComponent;
      goto LABEL_33;
    }
    goto LABEL_10;
  }
  if ( (v3 & 0x8000u) != 0 )
  {
    v9 = (unsigned int)v2[1].vfptr;
    v10 = v2->m_Components.size;
    if ( v9 < v10 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v9;
        if ( (v6[v9].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v9].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
        if ( ++v9 >= v10 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (v3 >> 13) & 1 )
  {
    v11 = (unsigned int)v2[1].vfptr;
    v12 = v2->m_Components.size;
    if ( v11 < v12 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v11;
        if ( (v6[v11].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v11].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
        if ( ++v11 >= v12 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (v3 >> 12) & 1 )
  {
    v13 = (unsigned int)v2[1].vfptr;
    v14 = v2->m_Components.size;
    if ( v13 < v14 )
    {
      v6 = v2->m_Components.p;
      do
      {
        v7 = v13;
        if ( (v6[v13].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v13].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
      }
      while ( ++v13 < v14 );
    }
LABEL_10:
    v8 = 0i64;
    goto LABEL_33;
  }
  v8 = UFG::SimObject::GetComponentOfType(v2, UFG::CollectibleComponent::_TypeUID);
LABEL_33:
  if ( v8 )
    return 0i64;
LABEL_35:
  v16 = UFG::GetSimulationMemoryPool();
  v17 = UFG::qMemoryPool::Allocate(v16, 0xC8ui64, "CollectibleComponent", 0i64, 1u);
  v26 = v17;
  if ( v17 )
  {
    v18 = v1->m_pSimObject;
    v19 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::CollectibleComponent::CollectibleComponent((UFG::CollectibleComponent *)v17, v19, v18);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  *(_WORD *)(v21 + 194) = (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v21 + 152i64))(v21);
  v22 = v1->mpWritableProperties;
  if ( !v22 )
    v22 = v1->mpConstProperties;
  if ( *UFG::qPropertySet::Get<bool>(v22, (UFG::qSymbol *)&qSymbol_DeleteAfterUse.mUID, DEPTH_RECURSE) )
    *(_BYTE *)(v21 + 195) = 1;
  v23 = UFG::qPropertySet::Get<UFG::qSymbol>(v22, (UFG::qSymbol *)&SimSym_UnlocksAfter.mUID, DEPTH_RECURSE);
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
  Render::SkinningCacheNode *v2; // rax
  signed __int64 v3; // rbx
  __int64 v4; // rbp
  char v5; // di
  __int64 v6; // rsi
  UFG::qBaseTreeRB *v7; // rax
  __int64 v8; // rax
  UFG::qBaseTreeRB *v9; // rax

  v1 = UFG::ProgressionTracker::Instance();
  v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::CollectibleComponent::msCollectibleComponents);
  v3 = (signed __int64)&v2[-3].mNode.8;
  if ( !v2 )
    v3 = 0i64;
  while ( v3 )
  {
    v4 = *(_QWORD *)(v3 + 40);
    v5 = 1;
    if ( *(_DWORD *)(v3 + 184) == -1 )
    {
      v6 = *(_QWORD *)(v4 + 88);
      if ( v6 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v4 + 88));
        *(_DWORD *)(v3 + 184) = UFG::SectionChooser::GetVisIndexAtPosition((UFG::qVector3 *)(v6 + 176), 0);
      }
    }
    if ( !UFG::SectionChooser::IsSectionVisible_VisIndex(*(_DWORD *)(v3 + 184), SCENERY_LAYER_STD, 0) )
    {
      v5 = 0;
      goto LABEL_17;
    }
    if ( *(_BYTE *)(v3 + 192) )
    {
      v5 = 0;
      v7 = UFG::ProgressionTracker::Find(v1, (UFG::qSymbol *)(v3 + 188), 0);
      if ( !v7 || SLODWORD(v7[3].mNULL.mChild[1]) < 1 && SWORD2(v7[5].mRoot.mParent) <= 0 )
        goto LABEL_17;
      v5 = 1;
    }
    if ( (*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)v3 + 152i64))(v3) )
    {
      v5 = 1;
      if ( *(_BYTE *)(v3 + 195) )
        v5 = 0;
    }
LABEL_17:
    if ( v5 != *(_BYTE *)(v3 + 193) )
    {
      v8 = *(_QWORD *)v3;
      if ( v5 )
        (*(void (__fastcall **)(signed __int64, _QWORD))(v8 + 176))(v3, *(_QWORD *)(v4 + 80));
      else
        (*(void (__fastcall **)(signed __int64))(v8 + 184))(v3);
    }
    (*(void (__fastcall **)(signed __int64))(*(_QWORD *)v3 + 144i64))(v3);
    v9 = UFG::qBaseTreeRB::GetNext(
           &UFG::CollectibleComponent::msCollectibleComponents.mTree,
           (UFG::qBaseNodeRB *)(v3 + 112));
    if ( v9 )
      v3 = (signed __int64)&v9[-2].mNULL;
    else
      v3 = 0i64;
  }
}

