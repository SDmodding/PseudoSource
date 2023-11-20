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
  return atexit(dynamic_atexit_destructor_for__UFG::SpawnPoint::msSpawnPoints__);
}

// File Line: 102
// RVA: 0x154D8C0
__int64 dynamic_initializer_for__UFG::SpawnPoint::msSpawnPointsWithPendingLinks__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SpawnPoint::msSpawnPointsWithPendingLinks__);
}

// File Line: 140
// RVA: 0x57D120
void __fastcall UFG::SpawnPoint::SpawnPoint(UFG::SpawnPoint *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::qSymbol *v3; // rbx
  UFG::SpawnPoint *v4; // rdi
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::PendingLink,UFG::PendingLink,1,0> *v7; // [rsp+48h] [rbp+10h]

  v3 = name;
  v4 = this;
  UFG::SpawnPointInterface::SpawnPointInterface((UFG::SpawnPointInterface *)&this->vfptr, name, pSimObj);
  v5 = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  LODWORD(v5) = (UFG::qSymbol)v3->mUID;
  v4->mNode.mParent = 0i64;
  v4->mNode.mChild[0] = 0i64;
  v4->mNode.mChild[1] = 0i64;
  v4->mNode.mUID = (unsigned int)v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPoint::`vftable;
  v6 = &v4->mpSpawn;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v4->mpSpawn.m_pPointer = 0i64;
  v7 = &v4->mPendingLinks;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v4->vfptr, UFG::SpawnPoint::_SpawnPointTypeUID, "SpawnPoint");
  *(_WORD *)&v4->mThugPoint = 0;
  v4->mSpawnZoneIndex = -1;
}

// File Line: 152
// RVA: 0x583FA0
char __fastcall UFG::SpawnPoint::Initialize(UFG::SpawnPoint *this, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v2; // rax
  UFG::SceneObjectProperties *v3; // rdi
  UFG::SpawnPoint *v4; // rbx
  UFG::SceneObjectProperties *v5; // rax
  bool v6; // zf
  UFG::SimObject *v7; // rax
  UFG::SceneObjectProperties *v8; // rax
  UFG::SceneObjectProperties *v9; // rdi
  UFG::qPropertySet *v10; // rcx
  UFG::qPropertySet *v11; // rcx
  int *v12; // rax
  signed int v13; // ebp
  UFG::PedSpawnManager *v14; // rax

  v2 = this->m_pSimObject;
  v3 = 0i64;
  v4 = this;
  once_5 = 0;
  if ( v2 )
    v5 = v2->m_pSceneObj;
  else
    v5 = 0i64;
  v6 = (this->mFlags & 0x10000) == 0;
  this->mpSceneObj = v5;
  if ( !v6 )
    UFG::qBaseTreeRB::Add(&UFG::SpawnPoint::msSpawnPoints.mTree, &this->mNode);
  v7 = v4->m_pSimObject;
  if ( v7 )
    v3 = v7->m_pSceneObj;
  v8 = UFG::SceneObjectProperties::GetChildAsSceneObject(v3, 0);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8->mpWritableProperties;
    if ( !v10 )
      v10 = v8->mpConstProperties;
    UFG::SpawnInfoInterface::GetSpawnPriority(v10, &v4->mSpawnPriority);
    v11 = v9->mpWritableProperties;
    if ( !v11 )
      v11 = v9->mpConstProperties;
    v12 = PropertyUtils::Get<long>(v11, (UFG::qSymbol *)&qSymbol_SpawnChance.mUID, 0);
    if ( v12 )
      v13 = *v12;
    else
      v13 = 100;
    if ( UFG::SpawnInfoInterface::IsCharacter(v9) && v4->mSpawnPriority )
    {
      v14 = UFG::PedSpawnManager::GetInstance();
      v4->mSpawnZoneIndex = UFG::PedSpawnManager::RegisterActiveSpawnPoint(v14, v4, v9);
      v4->mSkipSpawnChancePercent = (signed int)(float)(100.0
                                                      - (float)((float)v13
                                                              * UFG::PedSpawnManager::msPedDensityScaleSpawnPointAdjust));
    }
    else
    {
      v4->mSkipSpawnChancePercent = 100 - v13;
    }
  }
  UFG::SpawnPoint::FillPendingLinks(v4);
  return 1;
}

// File Line: 215
// RVA: 0x57DEB0
void __fastcall UFG::SpawnPoint::~SpawnPoint(UFG::SpawnPoint *this)
{
  UFG::SpawnPoint *v1; // rdi
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v2; // rcx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v3; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v9; // rdx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v10; // rcx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPoint::`vftable;
  if ( this->mFlags & 0x10000 )
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::SpawnPoint::msSpawnPoints,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->mNode);
  UFG::qList<UFG::PendingLink,UFG::PendingLink,1,0>::DeleteNodes(&v1->mPendingLinks);
  v2 = v1->mPendingLinks.mNode.mPrev;
  v3 = v1->mPendingLinks.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPendingLinks.mNode.mPrev = &v1->mPendingLinks.mNode;
  v1->mPendingLinks.mNode.mNext = &v1->mPendingLinks.mNode;
  v4 = &v1->mpSpawn;
  if ( v1->mpSpawn.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v1->mpSpawn.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->mpSpawn.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpSpawn.mPrev;
  }
  v1->mpSpawn.m_pPointer = 0i64;
  v7 = v4->mPrev;
  v8 = v1->mpSpawn.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->mpSpawn.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpSpawn.mPrev;
  v9 = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&v1->mPrev;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 224
// RVA: 0x582730
UFG::qBaseNodeRB **__fastcall UFG::SpawnPoint::GetNamed(UFG::qSymbol *name)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::qBaseNodeRB **result; // rax

  if ( name->mUID && (v1 = UFG::qBaseTreeRB::Get(&UFG::SpawnPoint::msSpawnPoints.mTree, name->mUID)) != 0i64 )
    result = &v1[-2].mRoot.mChild[1];
  else
    result = 0i64;
  return result;
}

// File Line: 235
// RVA: 0x586DE0
void __fastcall UFG::SpawnPoint::OnDetach(UFG::SpawnPoint *this)
{
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v1; // rdx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v2; // rax
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v3; // r8
  UFG::qList<UFG::PendingLink,UFG::PendingLink,1,0> *v4; // rdi
  UFG::PendingLink *v5; // rbx
  UFG::SpawnPoint *v6; // r14
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v7; // rdx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v8; // rax
  UFG::PedSpawnManager *v9; // rax
  UFG::SimObject *v10; // rax
  unsigned int v11; // er15
  unsigned int v12; // ebp
  UFG::SceneObjectProperties *v13; // rax
  UFG::SceneObjectProperties *v14; // rax
  UFG::SceneObjectProperties *v15; // rsi
  UFG::SimObjectGame *v16; // rbx
  UFG::qPropertySet *v17; // rcx
  bool *v18; // rax
  unsigned __int16 v19; // cx
  UFG::StreamedResourceComponent *v20; // rdi
  UFG::SimComponent *v21; // rax
  UFG::qSymbol symbol; // [rsp+40h] [rbp+8h]

  v1 = this->mPrev;
  v2 = this->mNext;
  v3 = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&this->mPrev;
  v1->mNext = v2;
  v2->mPrev = v1;
  v4 = &this->mPendingLinks;
  v3->mPrev = v3;
  v3->mNext = v3;
  v5 = (UFG::PendingLink *)this->mPendingLinks.mNode.mNext;
  v6 = this;
  if ( v5 != (UFG::PendingLink *)&this->mPendingLinks )
  {
    do
    {
      v7 = v5->mPrev;
      v8 = v5->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v5->mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)&v5->mPrev;
      v5->mNext = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)&v5->mPrev;
      UFG::PendingLink::~PendingLink(v5);
      operator delete[](v5);
      v5 = (UFG::PendingLink *)v4->mNode.mNext;
    }
    while ( v5 != (UFG::PendingLink *)v4 );
  }
  v6->mIsLinkPending = 0;
  v9 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::UnRegisterActiveSpawnPoint(v9, v6, v6->mpSceneObj);
  v10 = v6->m_pSimObject;
  if ( v10 )
    v10 = (UFG::SimObject *)v10->m_pSceneObj;
  v11 = (unsigned int)v10->m_UnboundComponentHandles.mNode.mNext;
  v12 = 0;
  if ( v11 )
  {
    do
    {
      v13 = UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&v6->vfptr);
      v14 = UFG::SceneObjectProperties::GetChildAsSceneObject(v13, v12);
      v15 = v14;
      if ( v14 )
        v16 = (UFG::SimObjectGame *)v14->m_pSimObject;
      else
        v16 = 0i64;
      if ( v16 )
      {
        v17 = v14->mpWritableProperties;
        LOBYTE(symbol.mUID) = 0;
        if ( !v17 )
          v17 = v14->mpConstProperties;
        v18 = UFG::qPropertySet::Get<bool>(
                v17,
                (UFG::qSymbol *)&qSymbol_SpawnPoint_DeleteTargetOnDetach.mUID,
                DEPTH_RECURSE);
        if ( v18 && *v18 == 1 )
        {
          UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)&v16->vfptr);
        }
        else
        {
          v19 = v16->m_Flags;
          if ( (v19 >> 14) & 1 )
          {
            v20 = (UFG::StreamedResourceComponent *)v16->m_Components.p[10].m_pComponent;
          }
          else if ( (v19 & 0x8000u) == 0 )
          {
            if ( (v19 >> 13) & 1 )
            {
              v20 = (UFG::StreamedResourceComponent *)v16->m_Components.p[7].m_pComponent;
            }
            else
            {
              if ( (v19 >> 12) & 1 )
                v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::StreamedResourceComponent::_TypeUID);
              else
                v21 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v16->vfptr,
                        UFG::StreamedResourceComponent::_TypeUID);
              v20 = (UFG::StreamedResourceComponent *)v21;
            }
          }
          else
          {
            v20 = (UFG::StreamedResourceComponent *)v16->m_Components.p[10].m_pComponent;
          }
          if ( v20 )
          {
            symbol.mUID = v20->mActivePriority.mUID;
            UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v20, (UFG::qSymbol *)&qSymbol_Low.mUID);
            UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v20, &symbol);
          }
          UFG::SpawnInfoInterface::SetOwner((UFG::SimObject *)&v16->vfptr, 0i64);
          UFG::SimObjectUtility::ConditionSimObjectForAmbientWorld((UFG::SimObject *)&v16->vfptr);
          if ( (unsigned int)UFG::SimObjectPropertiesComponent::GetChildType(v15) == 1 )
            UFG::PedSpawnManager::ReleaseOwnership((UFG::SimObject *)&v16->vfptr, 4u, 0);
        }
      }
      ++v12;
    }
    while ( v12 < v11 );
  }
}

// File Line: 313
// RVA: 0x58BBE0
void __fastcall UFG::SpawnPoint::SetupSpawnTarget(UFG::SpawnPoint *this)
{
  UFG::SimObject *v1; // rax
  UFG::SpawnPoint *v2; // rdi
  UFG::qPropertySet *v3; // rbx
  UFG::qPropertySet *v4; // rax
  UFG::qSymbol targetNameOut; // [rsp+30h] [rbp+8h]

  v1 = this->m_pSimObject;
  v2 = this;
  if ( v1 )
    v1 = (UFG::SimObject *)v1->m_pSceneObj;
  v3 = (UFG::qPropertySet *)v1[1].m_SafePointerList.mNode.mNext;
  if ( !v3 )
    v3 = (UFG::qPropertySet *)v1[1].m_SafePointerWithCallbackList.mNode.mPrev;
  if ( UFG::qPropertySet::Get<UFG::qSymbol>(v3, (UFG::qSymbol *)&qSymbol_SpawnTargetType.mUID, DEPTH_RECURSE) )
  {
    targetNameOut.mUID = -1;
    if ( UFG::GameplayUtil::ChooseSpawnTarget(&targetNameOut, v3) )
    {
      v4 = UFG::PropertySetManager::GetPropertySet(&targetNameOut);
      if ( v4 )
        UFG::SpawnPoint::SetNewSpawnTarget(v2, v4);
    }
  }
}

// File Line: 335
// RVA: 0x58BFD0
UFG::SimObjectGame *__fastcall UFG::SpawnPoint::Spawn(UFG::SpawnPoint *this, bool skip_poi_links, bool from_skookum)
{
  char v3; // si
  UFG::SpawnPoint *v4; // rbp
  UFG::Event *v5; // r15
  UFG::SimObjectGame *v6; // rdi
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v7; // r10
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v8; // r9
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::SceneObjectProperties *v11; // rcx
  UFG::SceneObjectProperties *v12; // rcx
  UFG::SceneObjectProperties *v13; // rsi
  char v14; // r13
  UFG::SpawnInfoInterface::SpawnPriority v15; // er12
  bool v16; // r14
  UFG::qPropertySet *v17; // rbx
  UFG::qSymbol *v18; // rax
  unsigned int v19; // eax
  UFG::ObjectResourceManager *v20; // rax
  signed int v21; // er14
  char *v22; // rax
  UFG::qPropertySet *v23; // rbx
  UFG::ObjectResourceManager *v24; // rax
  UFG::qSymbol *v25; // rax
  UFG::TransformNodeComponent *v26; // r14
  UFG::allocator::free_link *v27; // r12
  unsigned int v28; // ebx
  UFG::Event *v29; // rax
  UFG::SceneObjectProperties *v30; // rbx
  UFG::SimObject *v31; // rdx
  UFG::SceneObjectProperties *v32; // rdx
  UFG::qPropertySet *v33; // rax
  UFG::SimObject *v34; // rcx
  UFG::SceneObjectProperties *v35; // r9
  UFG::qPropertySet *v36; // rax
  unsigned __int16 v37; // cx
  UFG::StreamedResourceComponent *v38; // rbx
  UFG::SimComponent *v39; // rax
  UFG::qSymbol *v40; // rax
  UFG::qPropertySet *v41; // rcx
  char v42; // r14
  UFG::PedSpawnManager *v43; // rax
  UFG::qBaseNodeRB *v44; // rax
  UFG::SceneObjectProperties *v45; // rbx
  UFG::SimObject *v46; // rax
  UFG::SceneObjectProperties *v47; // rdx
  UFG::SceneObjectProperties *v48; // rbx
  UFG::SimObject *v49; // rax
  UFG::SceneObjectProperties *v50; // rdx
  UFG::SimObjectGame *v51; // rax
  unsigned __int16 v52; // cx
  UFG::SimComponent *v53; // rax
  UFG::SimObject *v54; // rcx
  UFG::TransformNodeComponent *v55; // rsi
  UFG::allocator::free_link *v56; // r14
  unsigned int v57; // ebx
  UFG::Event *v58; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v59; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v60; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v61; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v62; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp-68h]
  UFG::qWiseSymbol v65; // [rsp+44h] [rbp-64h]
  __int64 v66; // [rsp+48h] [rbp-60h]
  UFG::allocator::free_link *v67; // [rsp+50h] [rbp-58h]
  UFG::qSymbol v68; // [rsp+B0h] [rbp+8h]
  bool v69; // [rsp+B8h] [rbp+10h]
  bool called_from_script; // [rsp+C0h] [rbp+18h]
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+C8h] [rbp+20h]

  called_from_script = from_skookum;
  v69 = skip_poi_links;
  v66 = -2i64;
  v3 = skip_poi_links;
  v4 = this;
  v5 = 0i64;
  v6 = 0i64;
  if ( skip_poi_links )
  {
    v7 = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&this->mPrev;
    v8 = this->mPrev;
    v9 = this->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = v7;
    v7->mNext = v7;
    this->mIsLinkPending = 0;
  }
  if ( !this->mpSpawn.m_pPointer )
    UFG::SpawnPoint::SetupSpawnTarget(this);
  v10 = v4->m_pSimObject;
  if ( v10 )
    v11 = v10->m_pSceneObj;
  else
    v11 = 0i64;
  if ( v11->mChildren.mCount > 0 )
  {
    if ( v10 )
      v12 = v10->m_pSceneObj;
    else
      v12 = 0i64;
    v13 = UFG::SceneObjectProperties::GetChildAsSceneObject(v12, 0);
    if ( !v13 )
      goto LABEL_98;
    UFG::qSymbol::qSymbol(&result, 0x1B810511u);
    UFG::SceneObjectProperties::operator UFG::qSymbol const(v13, &v68);
    v14 = 0;
    v15 = v13->m_NameUID;
    pPriority = v15;
    v6 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v15);
    v16 = v13->m_pSimObject == 0i64;
    if ( v6 && v16 )
    {
      v14 = 1;
      goto LABEL_45;
    }
    v17 = v13->mpWritableProperties;
    if ( !v17 )
      v17 = v13->mpConstProperties;
    v18 = UFG::SpawnInfoInterface::GetSpawnPriority(v17, (UFG::SpawnInfoInterface::SpawnPriority *)&v68);
    if ( v16 )
    {
      if ( v18 )
      {
        v19 = v18->mUID;
        if ( v19 == qSymbol_Low.mUID || v19 == qSymbol_Medium.mUID )
        {
          v20 = UFG::ObjectResourceManager::Instance();
          if ( !UFG::ObjectResourceManager::CanSpawnAmbient(v20, v17, 0i64, 0) )
          {
LABEL_43:
            v6 = (UFG::SimObjectGame *)v13->m_pSimObject;
            v14 = 0;
            if ( !v13->mpOwner.m_pPointer )
              v14 = 1;
            goto LABEL_45;
          }
        }
      }
    }
    else if ( v6 )
    {
      goto LABEL_43;
    }
    v21 = v4->mSkipSpawnChancePercent;
    if ( v21 && (signed int)UFG::qRandom(100, &UFG::qDefaultSeed) < v21 )
    {
      v22 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v17->mName);
      UFG::qPrintf("spawn chance pruning: %s\n", v22);
    }
    else if ( PropertyUtils::Get<bool>(v13, (UFG::qSymbol *)&qSymbol_SpawnFromCurrentTrafficSet.mUID) != 0i64 )
    {
      v23 = UFG::WheeledVehicleManager::ChooseAmbientParkedVehicle(UFG::WheeledVehicleManager::m_Instance, 0);
      if ( v23
        || (v24 = UFG::ObjectResourceManager::Instance(),
            (v23 = UFG::ObjectResourceManager::GetRandomPropSetFromCurrentTrafficSet(v24)) != 0i64) )
      {
        if ( !UFG::SimObjectUtility::IsClassType(v23, (UFG::qSymbol *)&qSymbol_Boat_17.mUID) )
        {
          v25 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v65, v15);
          v6 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::SpawnObject(
                                       v25,
                                       v23,
                                       (UFG::SpawnInfoInterface::SpawnPriority)v68.mUID,
                                       0i64,
                                       0i64,
                                       0i64);
          v26 = v4->mpXformNode;
          v27 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
          v67 = v27;
          if ( v27 )
          {
            v28 = v6->mNode.mUID;
            UFG::TransformNodeComponent::UpdateWorldTransform(v26);
            UFG::TeleportEvent::TeleportEvent(
              (UFG::TeleportEvent *)v27,
              &v26->mWorldTransform,
              v28,
              0,
              UFG::TeleportEvent::m_Name,
              0);
          }
          else
          {
            v29 = 0i64;
          }
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v29);
          UFG::SceneObjectProperties::SetParent(v13, 0i64);
          v30 = v6->m_pSceneObj;
          v31 = v4->m_pSimObject;
          if ( v31 )
            v32 = v31->m_pSceneObj;
          else
            v32 = 0i64;
          UFG::SceneObjectProperties::SetParent(v6->m_pSceneObj, v32);
          v13->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v13->vfptr, 1u);
          v13 = v30;
          v15 = pPriority;
        }
      }
    }
    else
    {
      v33 = (UFG::qPropertySet *)UFG::SceneObjectProperties::GetArchetypeProperties(v13);
      v34 = v4->m_pSimObject;
      if ( v34 )
        v35 = v34->m_pSceneObj;
      else
        v35 = 0i64;
      v6 = (UFG::SimObjectGame *)UFG::SpawnInfoInterface::ActivateObject(
                                   v13,
                                   (UFG::SpawnInfoInterface::SpawnPriority)v68.mUID,
                                   0i64,
                                   v35,
                                   v33,
                                   2u,
                                   called_from_script);
    }
LABEL_45:
    if ( v6 )
    {
      if ( !v14 )
        goto LABEL_94;
    }
    else
    {
      v36 = UFG::SceneObjectProperties::GetWritablePersistentProperties(v13);
      v6 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, &v36->mName);
      v14 = 1;
      if ( !v6 )
        goto LABEL_98;
    }
    v37 = v6->m_Flags;
    if ( (v37 >> 14) & 1 )
    {
      v38 = (UFG::StreamedResourceComponent *)v6->m_Components.p[10].m_pComponent;
    }
    else if ( (v37 & 0x8000u) == 0 )
    {
      if ( (v37 >> 13) & 1 )
      {
        v38 = (UFG::StreamedResourceComponent *)v6->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v37 >> 12) & 1 )
          v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::StreamedResourceComponent::_TypeUID);
        else
          v39 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v6->vfptr,
                  UFG::StreamedResourceComponent::_TypeUID);
        v38 = (UFG::StreamedResourceComponent *)v39;
      }
    }
    else
    {
      v38 = (UFG::StreamedResourceComponent *)v6->m_Components.p[10].m_pComponent;
    }
    if ( v38 )
    {
      v40 = (UFG::qSymbol *)PropertyUtils::Get<UFG::qSymbol>(v13, (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID);
      UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v38, v40);
      UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v38, (UFG::qSymbol *)&qSymbol_Low.mUID);
    }
    UFG::SceneObjectProperties::GetArchetypeProperties(v13);
    v41 = v13->mpWritableProperties;
    if ( !v41 )
      v41 = v13->mpConstProperties;
    UFG::SpawnInfoInterface::GetSpawnPriority(v41, &pPriority);
    if ( UFG::SpawnInfoInterface::IsCharacter(v13) )
    {
      v42 = UFG::PedSpawnManager::AquireOwnership(
              (UFG::SimObject *)&v6->vfptr,
              (signed int)pPriority >= 1,
              0,
              v4->mSpawnZoneIndex);
      if ( v42 )
      {
        v43 = UFG::PedSpawnManager::GetInstance();
        UFG::PedSpawnManager::SetSuspendOption(v43, (UFG::SimObject *)&v6->vfptr, 0);
      }
      v44 = UFG::Simulation::GetSimObject(&UFG::gSim, v15);
      v6 = (UFG::SimObjectGame *)v44;
      if ( !v44 )
        goto LABEL_98;
      v45 = (UFG::SceneObjectProperties *)v44[2].mChild[1];
      if ( v45 != v13 )
      {
        UFG::SceneObjectProperties::SetParent(v13, 0i64);
        v46 = v4->m_pSimObject;
        if ( v46 )
          v47 = v46->m_pSceneObj;
        else
          v47 = 0i64;
        UFG::SceneObjectProperties::SetParent(v45, v47);
        v13->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v13->vfptr, 1u);
        v13 = v45;
      }
      if ( v42 )
      {
LABEL_93:
        if ( !v14 )
        {
LABEL_94:
          v55 = v6->m_pTransformNodeComponent;
          if ( v55 )
          {
            v56 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
            v67 = v56;
            if ( v56 )
            {
              v57 = v6->mNode.mUID;
              UFG::TransformNodeComponent::UpdateWorldTransform(v55);
              UFG::TeleportEvent::TeleportEvent(
                (UFG::TeleportEvent *)v56,
                &v55->mWorldTransform,
                v57,
                0,
                UFG::TeleportEvent::m_Name,
                0);
              v5 = v58;
            }
            UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v5);
          }
        }
LABEL_98:
        v3 = v69;
        goto LABEL_99;
      }
    }
    else
    {
      PropertyUtils::Get<bool>(v13, (UFG::qSymbol *)&qSymbol_SpawnFromCurrentTrafficSet.mUID);
      v48 = v6->m_pSceneObj;
      if ( v48 != v13 )
      {
        UFG::SceneObjectProperties::SetParent(v13, 0i64);
        v49 = v4->m_pSimObject;
        if ( v49 )
          v50 = v49->m_pSceneObj;
        else
          v50 = 0i64;
        UFG::SceneObjectProperties::SetParent(v48, v50);
        v13->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v13->vfptr, 1u);
        v13 = v48;
      }
    }
    v51 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v15);
    v6 = v51;
    if ( !v51 )
      goto LABEL_98;
    v52 = v51->m_Flags;
    if ( (v52 >> 14) & 1 )
    {
      v53 = v51->m_Components.p[23].m_pComponent;
    }
    else if ( (v52 & 0x8000u) == 0 )
    {
      if ( (v52 >> 13) & 1 )
      {
        v53 = UFG::SimObjectGame::GetComponentOfTypeHK(v51, UFG::VehicleDriverInterface::_TypeUID);
      }
      else if ( (v52 >> 12) & 1 )
      {
        v53 = UFG::SimObjectGame::GetComponentOfTypeHK(v51, UFG::VehicleDriverInterface::_TypeUID);
      }
      else
      {
        v53 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v51->vfptr, UFG::VehicleDriverInterface::_TypeUID);
      }
    }
    else
    {
      v53 = v51->m_Components.p[23].m_pComponent;
    }
    if ( !v53
      || (v54 = (UFG::SimObject *)v53[3].m_BoundComponentHandles.mNode.mNext) == 0i64
      || !UFG::IsAnyLocalPlayer(v54) )
    {
      UFG::SpawnInfoInterface::ReinitializeSpawnedObject(
        (UFG::SpawnInfoInterface *)&v4->mPrev,
        (UFG::SimObject *)&v6->vfptr,
        pPriority,
        v13,
        called_from_script);
    }
    goto LABEL_93;
  }
LABEL_99:
  UFG::SpawnInfoInterface::SetOwner((UFG::SimObject *)&v6->vfptr, v4->m_pSimObject);
  v59 = &v4->mpSpawn;
  if ( v4->mpSpawn.m_pPointer )
  {
    v60 = v59->mPrev;
    v61 = v4->mpSpawn.mNext;
    v60->mNext = v61;
    v61->mPrev = v60;
    v59->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v59->mPrev;
    v4->mpSpawn.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mpSpawn.mPrev;
  }
  v4->mpSpawn.m_pPointer = (UFG::SimObject *)&v6->vfptr;
  if ( v6 )
  {
    v62 = v6->m_SafePointerList.mNode.mPrev;
    v62->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v59->mPrev;
    v59->mPrev = v62;
    v4->mpSpawn.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v59->mPrev;
  }
  if ( !v3 )
    UFG::SpawnPoint::UpdateLinks(v4, 0);
  return v6;
}

// File Line: 740
// RVA: 0x58B980
char __fastcall UFG::SpawnPoint::SetNewSpawnTarget(UFG::SpawnPoint *this, UFG::qPropertySet *target_property_set)
{
  UFG::qPropertySet *v2; // rsi
  UFG::SimObject *v3; // rax
  UFG::SceneObjectProperties *v4; // rcx
  UFG::SceneObjectProperties *v5; // rdi
  UFG::qPropertySet *v6; // rbx
  UFG::qResourceData *v7; // rax

  v2 = target_property_set;
  if ( this->mpSpawn.m_pPointer )
    return 0;
  v3 = this->m_pSimObject;
  if ( v3 )
    v4 = v3->m_pSceneObj;
  else
    v4 = 0i64;
  v5 = UFG::SceneObjectProperties::GetChildAsSceneObject(v4, 0);
  UFG::SceneObjectProperties::UninstantiateChildObjects(v5);
  v6 = UFG::SceneObjectProperties::GetWritableProperties(v5);
  v7 = UFG::SceneObjectProperties::GetArchetypeProperties(v5);
  UFG::qPropertySet::RemoveParent(v6, (UFG::qSymbol *)&v7->mDebugName[12]);
  UFG::qPropertySet::AddParent(v6, v2);
  UFG::SceneObjectProperties::InstantiateChildObjects(v5, 0);
  return 1;
}

// File Line: 796
// RVA: 0x58DBD0
void __fastcall UFG::SpawnPoint::UpdateAll(float delta_sec)
{
  Render::SkinningCacheNode *v1; // rax
  UFG::SpawnPoint *v2; // rbx
  signed int v3; // ecx
  UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *v4; // rax
  UFG::qBaseTreeRB *v5; // rax

  v1 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SpawnPoint::msSpawnPoints);
  if ( v1 )
    v2 = (UFG::SpawnPoint *)&v1[-4].mCachedBufferPtr;
  else
    v2 = 0i64;
  while ( v2 )
  {
    v3 = -1;
    v4 = (UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *)&UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mNext[-7];
    if ( (UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *)&UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mNext[-7] != &UFG::SpawnPoint::msSpawnPointsWithPendingLinks - 7 )
    {
      while ( 1 )
      {
        ++v3;
        if ( v4 == (UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *)v2 )
          break;
        v4 = (UFG::qList<UFG::SpawnPoint,UFG::SpawnPoint,1,0> *)&v4[7].mNode.mNext[-7];
        if ( v4 == &UFG::SpawnPoint::msSpawnPointsWithPendingLinks - 7 )
          goto LABEL_11;
      }
      if ( v3 != -1 )
        UFG::SpawnPoint::UpdateLinks(v2, 1);
    }
LABEL_11:
    v5 = UFG::qBaseTreeRB::GetNext(&UFG::SpawnPoint::msSpawnPoints.mTree, &v2->mNode);
    if ( v5 )
      v2 = (UFG::SpawnPoint *)&v5[-2].mRoot.mChild[1];
    else
      v2 = 0i64;
  }
}

// File Line: 810
// RVA: 0x580D70
void __fastcall UFG::SpawnPoint::FillPendingLinks(UFG::SpawnPoint *this)
{
  UFG::SpawnPoint *v1; // rsi
  UFG::qList<UFG::PendingLink,UFG::PendingLink,1,0> *v2; // rdi
  UFG::PendingLink *v3; // rbx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v4; // rcx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v5; // rax
  UFG::SimObject *v6; // rax
  UFG::SceneObjectProperties *v7; // rcx
  UFG::qPropertySet *v8; // rax
  UFG::qPropertyList *v9; // rbp
  unsigned int v10; // er12
  unsigned int v11; // esi
  char *v12; // rax
  UFG::qPropertySet *v13; // rbx
  UFG::qSymbol *v14; // r14
  UFG::qSymbol *v15; // r15
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rdx
  UFG::qSymbol *v18; // rax
  UFG::qSymbol *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // [rsp+78h] [rbp+10h]
  UFG::allocator::free_link *v22; // [rsp+78h] [rbp+10h]

  v1 = this;
  v2 = &this->mPendingLinks;
  v3 = (UFG::PendingLink *)this->mPendingLinks.mNode.mNext;
  if ( v3 != (UFG::PendingLink *)&this->mPendingLinks )
  {
    do
    {
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)&v3->mPrev;
      UFG::PendingLink::~PendingLink(v3);
      operator delete[](v3);
      v3 = (UFG::PendingLink *)v2->mNode.mNext;
    }
    while ( v3 != (UFG::PendingLink *)v2 );
  }
  v6 = v1->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_pSceneObj;
    if ( v7 )
    {
      v8 = PropertyUtils::Get<UFG::qPropertyList>(v7, (UFG::qSymbol *)&SimSym_Links.mUID);
      v9 = (UFG::qPropertyList *)v8;
      if ( v8 )
      {
        v10 = v8->mValues.mOffset;
        if ( v10 )
        {
          v11 = 0;
          if ( v10 )
          {
            do
            {
              v12 = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
              if ( !v12 || (v13 = (UFG::qPropertySet *)&v12[*(_QWORD *)v12], !*(_QWORD *)v12) )
                v13 = 0i64;
              v14 = UFG::qPropertySet::Get<UFG::qSymbol>(v13, (UFG::qSymbol *)&SimSym_LinkEntity.mUID, DEPTH_RECURSE);
              v15 = UFG::qPropertySet::Get<UFG::qSymbol>(v13, (UFG::qSymbol *)&SimSym_LinkObjective.mUID, DEPTH_RECURSE);
              v16 = UFG::qMalloc(0x60ui64, "PendingLink", 0x800ui64);
              v17 = v16;
              if ( v16 )
              {
                v16->mNext = v16;
                v16[1].mNext = v16;
                LODWORD(v16[2].mNext) = -1;
                v21 = v16 + 3;
                v21->mNext = v21;
                v21[1].mNext = v21;
                v16[5].mNext = 0i64;
                LODWORD(v16[6].mNext) = -1;
                v22 = v16 + 7;
                v22->mNext = v22;
                v22[1].mNext = v22;
                v22[2].mNext = 0i64;
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
              v20 = (UFG::allocator::free_link *)v2->mNode.mPrev;
              v20[1].mNext = v17;
              v17->mNext = v20;
              v17[1].mNext = (UFG::allocator::free_link *)v2;
              v2->mNode.mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v17;
              ++v11;
            }
            while ( v11 < v10 );
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
  UFG::SpawnPoint *v2; // r13
  unsigned __int8 v3; // r12
  char v4; // al
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v5; // rsi
  UFG::SceneObjectProperties *v6; // rdi
  unsigned __int64 v7; // rax
  __int64 v8; // rdx
  unsigned __int64 v9; // rax
  UFG::qBaseNodeRB *v10; // r8
  UFG::qBaseNodeRB *v11; // rdx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v12; // rcx
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v13; // rax
  UFG::qBaseNodeRB *v14; // rax
  UFG::SimObject *v15; // rcx
  UFG::InterestPoint *v16; // rax
  UFG::SimObjectGame *v17; // rax
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  UFG::SimComponent *v20; // rbx
  int v21; // eax
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
  unsigned __int16 v32; // dx
  UFG::SimComponent *v33; // rbx
  UFG::SimComponent *v34; // rax
  UFG::SimObjectGame *v35; // rcx
  unsigned __int16 v36; // dx
  UFG::SimComponent *v37; // rax
  unsigned int *v38; // rdi
  bool *v39; // rax
  UFG::qSymbol *v40; // rcx
  char v41; // bl
  bool *v42; // rax
  UFG::qSymbol *v43; // rcx
  char v44; // bp
  UFG::qStaticSymbol *v45; // rbx
  UFG::qSymbol *v46; // rax
  UFG::ePOIUseType v47; // er15
  UFG::InterestPointUserComponent *v48; // r14
  UFG::qNode<UFG::PendingLink,UFG::PendingLink> *v49; // rcx
  UFG::SimComponent *v50; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::TeleportEvent *v52; // rbp
  unsigned int v53; // edi
  UFG::TransformNodeComponent *v54; // rbx
  char *v55; // rax
  UFG::qBaseTreeRB *v56; // rax
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v57; // rdx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v58; // rcx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v59; // rdx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v60; // rcx
  UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *v61; // rax
  char v63; // [rsp+A0h] [rbp+8h]
  bool v64; // [rsp+A8h] [rbp+10h]
  UFG::qSymbol symbol; // [rsp+B0h] [rbp+18h]
  UFG::qSymbol skipIntoLabel; // [rsp+B8h] [rbp+20h]

  v64 = calledByUpdate;
  v2 = this;
  v3 = 0;
  v4 = 0;
  v63 = 0;
  v5 = this->mPendingLinks.mNode.mNext;
  if ( v5 != (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)&this->mPendingLinks )
  {
    while ( 1 )
    {
      v6 = v2->m_pSimObject->m_pSceneObj;
      if ( v5[4].mNext )
        goto LABEL_101;
      LODWORD(v7) = v5[3].mPrev;
      if ( v6 )
      {
        v8 = v6->mPrevNameHash;
        if ( (_DWORD)v8 )
        {
          v9 = 21
             * ((((v8 | ((unsigned __int64)(unsigned int)v7 << 32)) << 18)
               + ~(v8 | ((unsigned __int64)(unsigned int)v7 << 32))) ^ ((((v8 | ((unsigned __int64)(unsigned int)v7 << 32)) << 18)
                                                                       + ~(v8 | ((unsigned __int64)(unsigned int)v7 << 32))) >> 31));
          v7 = 65 * (v9 ^ (v9 >> 11)) ^ (65 * (v9 ^ (v9 >> 11)) >> 22);
        }
      }
      v10 = UFG::Simulation::GetSimObject(&UFG::gSim, v7);
      v11 = (UFG::qBaseNodeRB *)&v5[3].mNext;
      if ( v5[4].mNext )
      {
        v12 = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v11->mParent;
        v13 = v5[4].mPrev;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mParent = v11;
        v5[4].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)((char *)v5 + 56);
      }
      v5[4].mNext = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v10;
      if ( v10 )
      {
        v14 = v10->mChild[0];
        v14->mChild[0] = v11;
        v11->mParent = v14;
        v5[4].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v10->mChild;
        v10->mChild[0] = v11;
      }
      v15 = (UFG::SimObject *)v5[4].mNext;
      if ( v15 )
      {
        v16 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v15, UFG::InterestPoint::_TypeUID);
        v5[5].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v16;
        if ( !v16 )
          goto LABEL_89;
        v17 = (UFG::SimObjectGame *)UFG::InterestPoint::GetParentObject(v16);
        if ( v17 )
        {
          v18 = v17->m_Flags;
          if ( (v18 >> 14) & 1 )
          {
            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::PowerManagementComponent::_TypeUID);
          }
          else if ( (v18 & 0x8000u) == 0 )
          {
            if ( (v18 >> 13) & 1 )
              v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::PowerManagementComponent::_TypeUID);
            else
              v19 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v17,
                                        UFG::PowerManagementComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v17->vfptr,
                                                                                     UFG::PowerManagementComponent::_TypeUID);
          }
          else
          {
            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::PowerManagementComponent::_TypeUID);
          }
          v20 = v19;
          if ( v19 )
          {
            v21 = (int)v19[1].m_pSimObject;
            v22 = v21 != 0;
            if ( v21 )
              UFG::PowerManagementComponent::gotoResuming((UFG::PowerManagementComponent *)v20);
            if ( *(float *)&v20[1].m_BoundComponentHandles.mNode.mPrev < 3.4028235e38 )
              LODWORD(v20[1].m_BoundComponentHandles.mNode.mPrev) = 1092616192;
            if ( v22 )
            {
LABEL_28:
              v4 = 1;
              v63 = 1;
              goto LABEL_90;
            }
          }
        }
      }
      if ( v5[4].mNext )
      {
LABEL_101:
        LODWORD(v23) = v5[1].mPrev;
        if ( v6 )
        {
          v24 = v6->mPrevNameHash;
          if ( (_DWORD)v24 )
          {
            v25 = 21
                * ((((v24 | ((unsigned __int64)(unsigned int)v23 << 32)) << 18)
                  + ~(v24 | ((unsigned __int64)(unsigned int)v23 << 32))) ^ ((((v24 | ((unsigned __int64)(unsigned int)v23 << 32)) << 18)
                                                                            + ~(v24 | ((unsigned __int64)(unsigned int)v23 << 32))) >> 31));
            v23 = 65 * (v25 ^ (v25 >> 11)) ^ (65 * (v25 ^ (v25 >> 11)) >> 22);
          }
        }
        if ( !v5[2].mNext )
        {
          v26 = UFG::Simulation::GetSimObject(&UFG::gSim, v23);
          v27 = (UFG::qBaseNodeRB *)&v5[1].mNext;
          if ( v5[2].mNext )
          {
            v28 = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v27->mParent;
            v29 = v5[2].mPrev;
            v28->mNext = v29;
            v29->mPrev = v28;
            v27->mParent = v27;
            v5[2].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)((char *)v5 + 24);
          }
          v5[2].mNext = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v26;
          if ( v26 )
          {
            v30 = v26->mChild[0];
            v30->mChild[0] = v27;
            v27->mParent = v30;
            v5[2].mPrev = (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v26->mChild;
            v26->mChild[0] = v27;
          }
        }
      }
      v31 = (UFG::SimObjectGame *)v5[2].mNext;
      if ( !v31 || !v5[4].mNext )
        goto LABEL_28;
      v32 = v31->m_Flags;
      if ( (v32 >> 14) & 1 )
      {
        v33 = v31->m_Components.p[7].m_pComponent;
      }
      else if ( (v32 & 0x8000u) == 0 )
      {
        if ( (v32 >> 13) & 1 )
        {
          v33 = v31->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v32 >> 12) & 1 )
            v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::ActionTreeComponent::_TypeUID);
          else
            v34 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v31->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v33 = v34;
        }
      }
      else
      {
        v33 = v31->m_Components.p[7].m_pComponent;
      }
      v35 = (UFG::SimObjectGame *)v5[2].mNext;
      if ( v35 )
      {
        v36 = v35->m_Flags;
        if ( (v36 >> 14) & 1 )
        {
          v35 = (UFG::SimObjectGame *)v35->m_Components.p[19].m_pComponent;
        }
        else if ( (v36 & 0x8000u) == 0 )
        {
          if ( (v36 >> 13) & 1 )
          {
            v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::AIActionTreeComponent::_TypeUID);
          }
          else if ( (v36 >> 12) & 1 )
          {
            v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::AIActionTreeComponent::_TypeUID);
          }
          else
          {
            v37 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v35->vfptr,
                    UFG::AIActionTreeComponent::_TypeUID);
          }
          v35 = (UFG::SimObjectGame *)v37;
        }
        else
        {
          v35 = (UFG::SimObjectGame *)v35->m_Components.p[19].m_pComponent;
        }
      }
      if ( (LOBYTE(v33->m_Flags) >> 1) & 1 || (LOBYTE(v35->m_SafePointerWithCallbackList.mNode.mNext) >> 1) & 1 )
        goto LABEL_28;
      if ( !v5[5].mPrev )
      {
        if ( UFG::SimObject::GetComponentOfType((UFG::SimObject *)v5[4].mNext, UFG::AIEntityComponent::_TypeUID) )
        {
          if ( !(_S11_8 & 1) )
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
            (UFG::SimObject *)v5[2].mNext,
            (UFG::SimObject *)v5[4].mNext,
            (UFG::PedFormationProfile *)v56);
          v3 = 1;
        }
        goto LABEL_89;
      }
      v38 = UFG::qPropertySet::Get<unsigned long>(
              (UFG::qPropertySet *)v5[5].mNext,
              (UFG::qSymbol *)&SimSym_LinkParam.mUID,
              DEPTH_RECURSE);
      LOBYTE(symbol.mUID) = 0;
      v39 = UFG::qPropertySet::Get<bool>(
              (UFG::qPropertySet *)v5[5].mNext,
              (UFG::qSymbol *)&qSymbol_NoInterrupt.mUID,
              DEPTH_RECURSE);
      v40 = &symbol;
      if ( v39 )
        v40 = (UFG::qSymbol *)v39;
      v41 = v40->mUID;
      LOBYTE(symbol.mUID) = 0;
      v42 = UFG::qPropertySet::Get<bool>(
              (UFG::qPropertySet *)v5[5].mNext,
              (UFG::qSymbol *)&qSymbol_Exclusive.mUID,
              DEPTH_RECURSE);
      v43 = &symbol;
      if ( v42 )
        v43 = (UFG::qSymbol *)v42;
      v44 = v43->mUID;
      v45 = &UFG::POIUseTypeEnumSymbols[(v41 != 0) + 2];
      v46 = UFG::qPropertySet::Get<UFG::qSymbol>(
              (UFG::qPropertySet *)v5[5].mNext,
              (UFG::qSymbol *)&qSymbol_PoiUseType.mUID,
              DEPTH_RECURSE);
      if ( v46 )
        v45 = (UFG::qStaticSymbol *)v46;
      symbol.mUID = v45->mUID;
      v47 = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gPOIUseTypeEnum, &symbol);
      v48 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)v5[2].mNext,
                                                 UFG::InterestPointUserComponent::_TypeUID);
      if ( !v48 )
        goto LABEL_89;
      v49 = v5[5].mPrev;
      if ( BYTE1(v49[26].mNext) )
      {
        if ( v49[23].mNext != v5[2].mNext
          || v49[33].mNext != (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)v2->m_pSimObject )
        {
          goto LABEL_89;
        }
      }
      UFG::InterestPointUserComponent::SetLinkObject(v48, v2->m_pSimObject, v47, v44);
      UFG::InterestPoint::SetLinkObject((UFG::InterestPoint *)v5[5].mPrev, v2->m_pSimObject);
      v50 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v5[2].mNext, UFG::ActiveAIEntityComponent::_TypeUID);
      skipIntoLabel.mUID = UFG::gNullQSymbol.mUID;
      if ( v50 )
      {
        if ( v38 && *v38 == 1 )
        {
          v51 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
          v52 = (UFG::TeleportEvent *)v51;
          *(_QWORD *)&symbol.mUID = v51;
          if ( v51 )
          {
            v53 = (unsigned int)v5[2].mNext[4].mPrev;
            v54 = (UFG::TransformNodeComponent *)v5[5].mPrev[6].mNext;
            UFG::TransformNodeComponent::UpdateWorldTransform(v54);
            UFG::TeleportEvent::TeleportEvent(v52, &v54->mWorldTransform, v53, 0, UFG::TeleportEvent::m_Name, 0);
          }
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v51);
          skipIntoLabel.mUID = qSymbol_Link.mUID;
        }
        UFG::InterestPointUserComponent::UsePOI(v48, (UFG::InterestPoint *)v5[5].mPrev, v47, &skipIntoLabel);
        v3 = 1;
LABEL_89:
        v4 = v63;
        goto LABEL_90;
      }
      v55 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5[2].mNext[4].mNext);
      UFG::qPrintf(
        "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\source\\sim\\components\\spawnpoint.cpp(993) : : Linking: %s failed"
        " because: %s %s\n",
        v55,
        &customWorldMapCaption,
        "ActiveAIEntityComponent is null");
      v4 = 1;
      v63 = 1;
LABEL_90:
      v5 = v5->mNext;
      if ( v5 == (UFG::qNode<UFG::PendingLink,UFG::PendingLink> *)&v2->mPendingLinks )
      {
        calledByUpdate = v64;
        break;
      }
    }
  }
  if ( v2->mIsLinkPending || !v4 )
  {
    if ( v3 )
    {
      v2->mIsLinkPending = 0;
      v59 = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&v2->mPrev;
      v60 = v2->mPrev;
      v61 = v2->mNext;
      v60->mNext = v61;
      v61->mPrev = v60;
      v59->mPrev = v59;
      v59->mNext = v59;
    }
  }
  else if ( !calledByUpdate )
  {
    v2->mIsLinkPending = 1;
    v57 = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&v2->mPrev;
    v58 = UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mPrev;
    UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mPrev->mNext = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&v2->mPrev;
    v57->mPrev = v58;
    v57->mNext = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&UFG::SpawnPoint::msSpawnPointsWithPendingLinks;
    UFG::SpawnPoint::msSpawnPointsWithPendingLinks.mNode.mPrev = (UFG::qNode<UFG::SpawnPoint,UFG::SpawnPoint> *)&v2->mPrev;
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
UFG::SpawnPoint *__fastcall UFG::SpawnPoint::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bl
  UFG::SceneObjectProperties *v3; // r14
  UFG::SceneObjectProperties *v4; // rdi
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax
  char *v7; // rbp
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // r15
  UFG::SimObject *v11; // rbx
  UFG::qSymbol *v12; // rax
  UFG::SpawnPoint *v13; // rax
  UFG::SpawnPoint *v14; // rbx
  UFG::SimObject *v15; // rax
  UFG::SceneObjectProperties *v16; // rax
  UFG::qPropertySet *v17; // rcx
  UFG::allocator::free_link *pPriority; // [rsp+70h] [rbp+8h]
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+18h]

  v2 = required;
  v3 = pSceneObj;
  v4 = 0i64;
  v5 = pSceneObj->mpWritableProperties;
  if ( !v5 )
    v5 = v3->mpConstProperties;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v5,
         (UFG::qSymbol *)&component_SpawnPoint::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v6);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0xE0ui64, "SpawnPoint", 0i64, 1u);
  pPriority = v10;
  if ( v10 )
  {
    v11 = v3->m_pSimObject;
    v12 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v3->m_NameUID);
    UFG::SpawnPoint::SpawnPoint((UFG::SpawnPoint *)v10, v12, v11);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v14->mThugPoint = v7[1];
  if ( !UFG::SpawnPoint::Initialize(v14, v3->m_pSimObject) )
    return 0i64;
  LODWORD(pPriority) = 0;
  v15 = v14->m_pSimObject;
  if ( v15 )
    v4 = v15->m_pSceneObj;
  v16 = UFG::SceneObjectProperties::GetChildAsSceneObject(v4, 0);
  if ( v16 )
  {
    v17 = v16->mpWritableProperties;
    if ( !v17 )
      v17 = v16->mpConstProperties;
    UFG::SpawnInfoInterface::GetSpawnPriority(v17, (UFG::SpawnInfoInterface::SpawnPriority *)&pPriority);
  }
  if ( !((unsigned __int8)*v7 | ((signed int)pPriority >= 1)) )
    UFG::SpawnPoint::Spawn(v14, 0, 0);
  return v14;
}

// File Line: 1160
// RVA: 0x585480
char __fastcall UFG::SpawnPoint::IsSheltered(UFG::SpawnPoint *this)
{
  UFG::SimObject *v1; // rax
  unsigned int v2; // ebx
  UFG::SpawnPoint *v3; // rsi
  UFG::SceneObjectProperties *v4; // rcx
  char result; // al
  UFG::SimObject *v6; // rax
  UFG::SceneObjectProperties *v7; // rcx
  unsigned int v8; // edi
  UFG::SceneObjectProperties *v9; // rax
  UFG::SceneObjectProperties *v10; // rax
  UFG::qPropertySet *v11; // rcx
  bool *v12; // rax

  v1 = this->m_pSimObject;
  v2 = 0;
  v3 = this;
  if ( v1 )
    v4 = v1->m_pSceneObj;
  else
    v4 = 0i64;
  if ( PropertyUtils::Get<UFG::qPropertyList>(v4, (UFG::qSymbol *)&SimSym_Links.mUID) )
    return 1;
  v6 = v3->m_pSimObject;
  if ( v6 )
    v7 = v6->m_pSceneObj;
  else
    v7 = 0i64;
  v8 = v7->mChildren.mCount;
  if ( !v8 )
    goto LABEL_12;
  while ( 1 )
  {
    v9 = UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&v3->vfptr);
    v10 = UFG::SceneObjectProperties::GetChildAsSceneObject(v9, v2);
    if ( v10 )
      break;
    if ( ++v2 >= v8 )
      goto LABEL_12;
  }
  v11 = v10->mpWritableProperties;
  if ( !v11 )
    v11 = v10->mpConstProperties;
  v12 = PropertyUtils::Get<bool>(v11, (UFG::qSymbol *)&qSymbol_Sheltered.mUID, DEPTH_RECURSE);
  if ( v12 )
    result = *v12;
  else
LABEL_12:
    result = 0;
  return result;
}

