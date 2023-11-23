// File Line: 70
// RVA: 0x14C9FE0
__int64 dynamic_initializer_for__NISActorNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NISActorNode", 0xFFFFFFFF);
  NISActorNode::sClassNameUID = result;
  return result;
}

// File Line: 96
// RVA: 0x3DFD60
void __fastcall NISActorNode::NISActorNode(NISActorNode *this)
{
  ActionNodeImplementation::ActionNodeImplementation(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISActorNode::`vftable;
  this->mRightHandEquipSlot.mPrev = &this->mRightHandEquipSlot;
  this->mRightHandEquipSlot.mNext = &this->mRightHandEquipSlot;
  this->mRightHandEquipSlot.m_pPointer = 0i64;
  this->mLeftHandEquipSlot.mPrev = &this->mLeftHandEquipSlot;
  this->mLeftHandEquipSlot.mNext = &this->mLeftHandEquipSlot;
  this->mLeftHandEquipSlot.m_pPointer = 0i64;
  this->mHatEquipSlot.mPrev = &this->mHatEquipSlot;
  this->mHatEquipSlot.mNext = &this->mHatEquipSlot;
  this->mHatEquipSlot.m_pPointer = 0i64;
  this->mGlassesEquipSlot.mPrev = &this->mGlassesEquipSlot;
  this->mGlassesEquipSlot.mNext = &this->mGlassesEquipSlot;
  this->mGlassesEquipSlot.m_pPointer = 0i64;
  this->mStowed1HSlot.mPrev = &this->mStowed1HSlot;
  this->mStowed1HSlot.mNext = &this->mStowed1HSlot;
  this->mStowed1HSlot.m_pPointer = 0i64;
  this->mStowed2HSlot.mPrev = &this->mStowed2HSlot;
  this->mStowed2HSlot.mNext = &this->mStowed2HSlot;
  this->mStowed2HSlot.m_pPointer = 0i64;
  *(_QWORD *)&this->mCachedRootPosition.x = 0i64;
  *(_QWORD *)&this->mCachedRootPosition.z = 0i64;
  *(_QWORD *)&this->mCachedHipsPosition.y = 0i64;
  *(_QWORD *)&this->mActorID.mUID = -1i64;
  *(_DWORD *)&this->mResetActorOnStart = 65537;
  *(_DWORD *)&this->mDisableCharacterCollision = 257;
  this->mCachedPositions = 0;
}

// File Line: 150
// RVA: 0x3E56B0
void __fastcall NISActorNode::SetupActor(NISActorNode *this, const bool bHighDef)
{
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::SimObject *v5; // rdi

  if ( !this->mPreloaded )
  {
    SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
    v5 = (UFG::SimObject *)SimObject;
    if ( SimObject )
    {
      this->mDeleteActorOnEnd = 0;
      NISActorNode::SaveEquippedItems(this, (UFG::SimObjectGame *)SimObject);
      if ( bHighDef )
      {
        this->mDowngradeModelOnCleanup = 1;
        UFG::SimObjectUtility::UpgradeModelResolution(v5);
      }
    }
    else
    {
      UFG::SpawnInfoInterface::SpawnObject(&this->mActorID, &this->mPropertySet, UnReferenced, 0i64, 0i64, 0i64);
      this->mDeleteActorOnEnd = 1;
    }
    *(_WORD *)&this->mPreloaded = 1;
  }
}

// File Line: 205
// RVA: 0x3E3850
void __fastcall NISActorNode::Play(NISActorNode *this)
{
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::SimObjectGame *v3; // rbx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax

  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
  v3 = (UFG::SimObjectGame *)SimObject;
  if ( SimObject )
  {
    NISActorNode::setupActorForNIS(this, (UFG::SimObject *)SimObject);
    m_Flags = v3->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v3->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = v3->m_Components.p[6].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v3, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = v3->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
    {
      LOBYTE(m_pComponent[2].m_pSimObject) = 1;
      ActionController::Play((ActionController *)&m_pComponent[3], this);
    }
  }
}

// File Line: 224
// RVA: 0x3E8050
void __fastcall NISActorNode::setupActorForNIS(NISActorNode *this, UFG::SimObjectCVBase *simActorObject)
{
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rbp
  char *MemImagePtr; // rax
  bool v8; // di
  UFG::PedSpawnManager *Instance; // rax
  signed __int16 m_Flags; // cx
  UFG::RagdollComponent *m_pComponent; // rax
  signed __int16 v12; // cx
  UFG::ActionTreeComponent *ComponentOfTypeHK; // rax
  __int64 mOffset; // rax
  char *v15; // rcx
  signed __int16 v16; // cx
  UFG::SimComponent *v17; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v19; // rcx
  UFG::RigidBody *v20; // rax
  unsigned int v21; // edi
  signed __int16 v22; // cx
  UFG::CharacterPhysicsComponent *v23; // rax
  signed __int16 v24; // cx
  UFG::SimComponent *v25; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::SimComponent *v29; // rax
  signed __int16 v30; // cx
  signed __int16 v31; // cx
  UFG::CharacterAnimationComponent *v32; // rax
  UFG::CharacterAnimationComponent *v33; // rdi
  signed __int16 v34; // cx
  UFG::SimComponent *v35; // rcx
  UFG::SimComponent *v36; // rax
  signed __int16 v37; // cx
  UFG::AnimationLODComponent *v38; // rsi
  UFG::SimComponent *v39; // rax
  signed __int16 v40; // cx
  UFG::FacialActionTreeComponent *v41; // rax
  Creature *mCreature; // rcx
  signed __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  signed __int16 v45; // cx
  UFG::SimComponent *v46; // rax
  signed __int16 v47; // cx
  UFG::CompositeLookComponent *v48; // rax
  UFG::SimObjectModifier v49; // [rsp+38h] [rbp-40h] BYREF
  UFG::qSymbol v50; // [rsp+88h] [rbp+10h] BYREF
  UFG::allocator::free_link *v51; // [rsp+90h] [rbp+18h]

  if ( !simActorObject )
    return;
  v50.mUID = this->mPropertySet.mUID;
  PropertySet = UFG::PropertySetManager::FindPropertySet(&v50);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&component_Ragdoll::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    MemImagePtr = 0i64;
  v8 = MemImagePtr != 0i64;
  Instance = UFG::PedSpawnManager::GetInstance();
  if ( !UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
          Instance,
          Active,
          simActorObject,
          "d:\\ufg\\madscience\\project\\builds\\sdhd\\sdhd_pc\\source\\nis\\nisnodes.cpp",
          238) )
    UFG::SimObject::Restore(simActorObject);
  if ( this->mResetActorOnStart )
    UFG::SimObjectUtility::ResetState(simActorObject, 0, 0);
  m_Flags = simActorObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::RagdollComponent *)simActorObject->m_Components.p[42].m_pComponent;
  }
  else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
  {
    m_pComponent = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              simActorObject,
                                              UFG::RagdollComponent::_TypeUID);
  }
  else
  {
    m_pComponent = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                              simActorObject,
                                              UFG::RagdollComponent::_TypeUID);
  }
  if ( !m_pComponent )
  {
    if ( !v8 )
      goto LABEL_21;
    m_pComponent = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire(simActorObject);
  }
  UFG::RagdollComponent::SetCollisionState(m_pComponent, CS_KEYFRAMED_NO_COLLISION);
LABEL_21:
  v12 = simActorObject->m_Flags;
  if ( (v12 & 0x4000) != 0 )
  {
    ComponentOfTypeHK = (UFG::ActionTreeComponent *)simActorObject->m_Components.p[7].m_pComponent;
  }
  else if ( v12 >= 0 )
  {
    if ( (v12 & 0x2000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActionTreeComponent *)simActorObject->m_Components.p[6].m_pComponent;
    }
    else if ( (v12 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        simActorObject,
                                                        UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                        simActorObject,
                                                        UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = (UFG::ActionTreeComponent *)simActorObject->m_Components.p[7].m_pComponent;
  }
  if ( ComponentOfTypeHK )
    UFG::ActionTreeComponent::Reset(ComponentOfTypeHK);
  mOffset = this->mParent.mOffset;
  if ( mOffset )
  {
    v15 = (char *)&this->mParent + mOffset;
    if ( v15 )
    {
      if ( v15[105] )
      {
        v16 = simActorObject->m_Flags;
        if ( (v16 & 0x4000) != 0 )
        {
          v17 = simActorObject->m_Components.p[27].m_pComponent;
        }
        else
        {
          if ( v16 < 0 || (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                simActorObject,
                                UFG::CharacterPhysicsComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(
                                simActorObject,
                                UFG::CharacterPhysicsComponent::_TypeUID);
          v17 = ComponentOfType;
        }
        if ( v17 )
        {
          LODWORD(v17[9].m_SafePointerList.mNode.mPrev) = 0;
          v17[9].m_NameUID = v17[9].m_NameUID & 0xFFFFFFEE | 1;
        }
        else
        {
          v19 = simActorObject->m_Flags;
          if ( (v19 & 0x4000) != 0 || (v19 & 0x8000u) != 0i64 || (v19 & 0x2000) != 0 || (v19 & 0x1000) != 0 )
            v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                      simActorObject,
                                      UFG::RigidBodyComponent::_TypeUID);
          else
            v20 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                      simActorObject,
                                      UFG::RigidBodyComponent::_TypeUID);
          if ( v20 )
            UFG::RigidBody::SetMotionType(v20, 0x100u);
        }
      }
    }
  }
  v21 = 6;
  if ( this->mDisableCharacterCollision )
  {
    v22 = simActorObject->m_Flags;
    if ( (v22 & 0x4000) != 0 )
      v23 = (UFG::CharacterPhysicsComponent *)simActorObject->m_Components.p[27].m_pComponent;
    else
      v23 = (UFG::CharacterPhysicsComponent *)(v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 simActorObject,
                                                 UFG::CharacterPhysicsComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 simActorObject,
                                                 UFG::CharacterPhysicsComponent::_TypeUID));
    if ( v23 )
      UFG::CharacterPhysicsComponent::SetCollisionModel(v23, CP_DISABLED);
  }
  v24 = simActorObject->m_Flags;
  if ( (v24 & 0x4000) != 0 )
  {
    v25 = simActorObject->m_Components.p[7].m_pComponent;
  }
  else if ( v24 >= 0 )
  {
    if ( (v24 & 0x2000) != 0 )
    {
      v25 = simActorObject->m_Components.p[6].m_pComponent;
    }
    else if ( (v24 & 0x1000) != 0 )
    {
      v25 = UFG::SimObjectGame::GetComponentOfTypeHK(simActorObject, UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v25 = UFG::SimObject::GetComponentOfType(simActorObject, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v25 = simActorObject->m_Components.p[7].m_pComponent;
  }
  if ( !v25 )
  {
    m_pSceneObj = simActorObject->m_pSceneObj;
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v28 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x560ui64, "NISActorNode::setupActorForNIS", 0i64, 1u);
    v51 = v28;
    if ( v28 )
    {
      UFG::ActionTreeComponent::ActionTreeComponent((UFG::ActionTreeComponent *)v28, m_pSceneObj, 0, 0i64);
      v6 = v29;
    }
    v30 = simActorObject->m_Flags;
    if ( (v30 & 0x4000) != 0 )
    {
      v21 = 7;
    }
    else if ( v30 >= 0 )
    {
      if ( (v30 & 0x2000) == 0 )
        v21 = -1;
    }
    else
    {
      v21 = 7;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v49, simActorObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v49, v6, v21);
    UFG::SimObjectModifier::Close(&v49);
    UFG::SimObjectModifier::~SimObjectModifier(&v49);
  }
  v31 = simActorObject->m_Flags;
  if ( (v31 & 0x4000) != 0 || v31 < 0 )
  {
    v32 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(simActorObject);
  }
  else if ( (v31 & 0x2000) != 0 )
  {
    v32 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)simActorObject);
  }
  else if ( (v31 & 0x1000) != 0 )
  {
    v32 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                simActorObject,
                                                UFG::CharacterAnimationComponent::_TypeUID);
  }
  else
  {
    v32 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                simActorObject,
                                                UFG::CharacterAnimationComponent::_TypeUID);
  }
  v33 = v32;
  if ( v32 )
  {
    v32->mEnableUpdateTransforms = 1;
    v32->mUpdatedFromNIS = 1;
  }
  v34 = simActorObject->m_Flags;
  if ( (v34 & 0x4000) != 0 )
  {
    v35 = simActorObject->m_Components.p[28].m_pComponent;
  }
  else
  {
    if ( v34 < 0 || (v34 & 0x2000) != 0 || (v34 & 0x1000) != 0 )
      v36 = UFG::SimObjectGame::GetComponentOfTypeHK(simActorObject, UFG::WorldContextComponent::_TypeUID);
    else
      v36 = UFG::SimObject::GetComponentOfType(simActorObject, UFG::WorldContextComponent::_TypeUID);
    v35 = v36;
  }
  if ( v35 )
    ((void (__fastcall *)(UFG::SimComponent *))v35->vfptr[8].__vecDelDtor)(v35);
  v37 = simActorObject->m_Flags;
  if ( (v37 & 0x4000) != 0 )
  {
    v38 = (UFG::AnimationLODComponent *)simActorObject->m_Components.p[13].m_pComponent;
  }
  else if ( v37 >= 0 )
  {
    if ( (v37 & 0x2000) != 0 || (v37 & 0x1000) != 0 )
      v39 = UFG::SimObjectGame::GetComponentOfTypeHK(simActorObject, UFG::AnimationLODComponent::_TypeUID);
    else
      v39 = UFG::SimObject::GetComponentOfType(simActorObject, UFG::AnimationLODComponent::_TypeUID);
    v38 = (UFG::AnimationLODComponent *)v39;
  }
  else
  {
    v38 = (UFG::AnimationLODComponent *)simActorObject->m_Components.p[13].m_pComponent;
  }
  if ( v38 )
  {
    UFG::AnimationLODComponent::MakeHighLOD(v38);
    ((void (__fastcall *)(UFG::AnimationLODComponent *))v38->vfptr[8].__vecDelDtor)(v38);
  }
  v40 = simActorObject->m_Flags;
  if ( (v40 & 0x4000) != 0 )
  {
    v41 = (UFG::FacialActionTreeComponent *)simActorObject->m_Components.p[31].m_pComponent;
  }
  else
  {
    if ( v40 < 0 || (v40 & 0x2000) != 0 )
      goto LABEL_128;
    if ( (v40 & 0x1000) != 0 )
      v41 = (UFG::FacialActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                simActorObject,
                                                UFG::FacialActionTreeComponent::_TypeUID);
    else
      v41 = (UFG::FacialActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                simActorObject,
                                                UFG::FacialActionTreeComponent::_TypeUID);
  }
  if ( v41 )
  {
    UFG::FacialActionTreeComponent::Disable(v41);
    if ( v33 )
    {
      mCreature = v33->mCreature;
      if ( mCreature )
        Creature::KillBlendTree(mCreature);
    }
  }
LABEL_128:
  v43 = simActorObject->m_Flags;
  if ( (v43 & 0x4000) == 0 )
  {
    if ( v43 < 0 )
    {
      v44 = simActorObject->m_Components.p[34].m_pComponent;
      goto LABEL_135;
    }
    if ( (v43 & 0x2000) == 0 )
    {
      if ( (v43 & 0x1000) != 0 )
        v44 = UFG::SimObjectGame::GetComponentOfTypeHK(simActorObject, UFG::PhysicsMoverInterface::_TypeUID);
      else
        v44 = UFG::SimObject::GetComponentOfType(simActorObject, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_135:
      if ( v44 )
        LODWORD(v44[14].vfptr) |= 8u;
    }
  }
  v45 = simActorObject->m_Flags;
  if ( (v45 & 0x4000) != 0 )
  {
    v46 = simActorObject->m_Components.p[17].m_pComponent;
  }
  else if ( v45 >= 0 )
  {
    if ( (v45 & 0x2000) != 0 || (v45 & 0x1000) != 0 )
      v46 = UFG::SimObjectGame::GetComponentOfTypeHK(simActorObject, UFG::CopUnitComponent::_TypeUID);
    else
      v46 = UFG::SimObject::GetComponentOfType(simActorObject, UFG::CopUnitComponent::_TypeUID);
  }
  else
  {
    v46 = simActorObject->m_Components.p[17].m_pComponent;
  }
  if ( v46 )
    LOBYTE(v46[7].m_Flags) &= ~2u;
  v47 = simActorObject->m_Flags;
  if ( (v47 & 0x4000) != 0 || v47 < 0 || (v47 & 0x2000) != 0 || (v47 & 0x1000) != 0 )
    v48 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           simActorObject,
                                           UFG::CompositeLookComponent::_TypeUID);
  else
    v48 = (UFG::CompositeLookComponent *)UFG::SimObject::GetComponentOfType(
                                           simActorObject,
                                           UFG::CompositeLookComponent::_TypeUID);
  if ( v48 )
    UFG::CompositeLookComponent::ForceVisibleTransparency(v48);
}

// File Line: 388
// RVA: 0x3E7A80
void __fastcall NISActorNode::nodeCleanup(NISActorNode *this)
{
  UFG::SimObjectCVBase *SimObject; // rbx
  UFG::PedSpawnManager *Instance; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  __int64 mOffset; // rax
  char *v7; // rcx
  __int16 v8; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v10; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::RigidBody *v12; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v13; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  __int16 v16; // cx
  UFG::CharacterPhysicsComponent *v17; // rdi
  UFG::SimComponent *v18; // rax
  __int16 v19; // cx
  UFG::CharacterAnimationComponent *v20; // rax
  Creature *mCreature; // rcx
  __int16 v22; // cx
  UFG::SimComponent *v23; // rcx
  UFG::SimComponent *v24; // rax
  __int16 v25; // cx
  UFG::SimComponent *v26; // rcx
  UFG::SimComponent *v27; // rax
  __int16 v28; // cx
  UFG::FacialActionTreeComponent *v29; // rax
  __int16 v30; // cx
  UFG::SimComponent *v31; // rax
  __int16 v32; // cx
  UFG::SimComponent *v33; // rax
  UFG::qReflectHandleBase v34; // [rsp+38h] [rbp-30h] BYREF

  SimObject = (UFG::SimObjectCVBase *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
  if ( !SimObject )
    return;
  Instance = UFG::PedSpawnManager::GetInstance();
  if ( !UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
          Instance,
          Active,
          SimObject,
          "d:\\ufg\\madscience\\project\\builds\\sdhd\\sdhd_pc\\source\\nis\\nisnodes.cpp",
          396) )
    UFG::SimObject::Restore(SimObject);
  m_Flags = SimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = SimObject->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = SimObject->m_Components.p[6].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(SimObject, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = SimObject->m_Components.p[7].m_pComponent;
  }
  if ( m_pComponent )
  {
    LOBYTE(m_pComponent[2].m_pSimObject) = 0;
    if ( this->mResetActorOnEnd )
      ActionController::Stop((ActionController *)&m_pComponent[3]);
  }
  mOffset = this->mParent.mOffset;
  if ( mOffset )
  {
    v7 = (char *)&this->mParent + mOffset;
    if ( v7 )
    {
      if ( v7[105] )
      {
        v8 = SimObject->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          ComponentOfTypeHK = SimObject->m_Components.p[27].m_pComponent;
        }
        else if ( v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                SimObject,
                                UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(SimObject, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        if ( ComponentOfTypeHK )
        {
          LODWORD(ComponentOfTypeHK[9].m_SafePointerList.mNode.mPrev) = 1092416963;
          ComponentOfTypeHK[9].m_NameUID &= ~1u;
        }
        else
        {
          v10 = SimObject->m_Flags;
          if ( (v10 & 0x4000) != 0 || v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::RigidBodyComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(SimObject, UFG::RigidBodyComponent::_TypeUID);
          v12 = (UFG::RigidBody *)ComponentOfType;
          if ( ComponentOfType )
          {
            UFG::qReflectHandleBase::qReflectHandleBase(&v34);
            TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v13);
            v34.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
            mCollisionMeshData = v12->mCollisionMeshData;
            if ( mCollisionMeshData )
              UFG::qReflectHandleBase::operator=(&v34, &mCollisionMeshData->mObjectProperties);
            if ( v34.mData && LODWORD(v34.mData[2].mBaseNode.mChildren[1]) == 2 )
              UFG::RigidBody::SetMotionType(v12, 0x80u);
            UFG::qReflectHandleBase::~qReflectHandleBase(&v34);
          }
        }
      }
    }
  }
  if ( this->mDisableCharacterCollision )
  {
    v16 = SimObject->m_Flags;
    if ( (v16 & 0x4000) != 0 )
    {
      v17 = (UFG::CharacterPhysicsComponent *)SimObject->m_Components.p[27].m_pComponent;
    }
    else
    {
      v18 = v16 < 0 || (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::CharacterPhysicsComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(SimObject, UFG::CharacterPhysicsComponent::_TypeUID);
      v17 = (UFG::CharacterPhysicsComponent *)v18;
    }
    if ( v17 )
    {
      UFG::CharacterPhysicsComponent::SetCollisionModel(v17, CP_WALK);
      UFG::CharacterPhysicsComponent::PlaceOnGroundAfterNIS(v17);
    }
  }
  v19 = SimObject->m_Flags;
  if ( (v19 & 0x4000) != 0 || v19 < 0 )
  {
    v20 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(SimObject);
  }
  else if ( (v19 & 0x2000) != 0 )
  {
    v20 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)SimObject);
  }
  else if ( (v19 & 0x1000) != 0 )
  {
    v20 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                SimObject,
                                                UFG::CharacterAnimationComponent::_TypeUID);
  }
  else
  {
    v20 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                SimObject,
                                                UFG::CharacterAnimationComponent::_TypeUID);
  }
  if ( v20 )
    v20->mUpdatedFromNIS = 0;
  if ( this->mResetActorOnEnd )
  {
    if ( v20 )
    {
      mCreature = v20->mCreature;
      if ( mCreature )
        Creature::KillBlendTree(mCreature);
    }
    UFG::SimObjectUtility::ResetState(SimObject, 0, 0);
  }
  v22 = SimObject->m_Flags;
  if ( (v22 & 0x4000) != 0 )
  {
    v23 = SimObject->m_Components.p[28].m_pComponent;
  }
  else
  {
    if ( v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
      v24 = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::WorldContextComponent::_TypeUID);
    else
      v24 = UFG::SimObject::GetComponentOfType(SimObject, UFG::WorldContextComponent::_TypeUID);
    v23 = v24;
  }
  if ( v23 )
    ((void (__fastcall *)(UFG::SimComponent *))v23->vfptr[9].__vecDelDtor)(v23);
  v25 = SimObject->m_Flags;
  if ( (v25 & 0x4000) != 0 )
  {
    v26 = SimObject->m_Components.p[13].m_pComponent;
  }
  else if ( v25 >= 0 )
  {
    if ( (v25 & 0x2000) != 0 || (v25 & 0x1000) != 0 )
      v27 = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::AnimationLODComponent::_TypeUID);
    else
      v27 = UFG::SimObject::GetComponentOfType(SimObject, UFG::AnimationLODComponent::_TypeUID);
    v26 = v27;
  }
  else
  {
    v26 = SimObject->m_Components.p[13].m_pComponent;
  }
  if ( v26 )
    ((void (__fastcall *)(UFG::SimComponent *))v26->vfptr[9].__vecDelDtor)(v26);
  v28 = SimObject->m_Flags;
  if ( (v28 & 0x4000) != 0 )
  {
    v29 = (UFG::FacialActionTreeComponent *)SimObject->m_Components.p[31].m_pComponent;
  }
  else
  {
    if ( v28 < 0 || (v28 & 0x2000) != 0 )
      goto LABEL_101;
    if ( (v28 & 0x1000) != 0 )
      v29 = (UFG::FacialActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                SimObject,
                                                UFG::FacialActionTreeComponent::_TypeUID);
    else
      v29 = (UFG::FacialActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                SimObject,
                                                UFG::FacialActionTreeComponent::_TypeUID);
  }
  if ( v29 )
    UFG::FacialActionTreeComponent::Enable(v29);
LABEL_101:
  v30 = SimObject->m_Flags;
  if ( (v30 & 0x4000) == 0 )
  {
    if ( v30 < 0 )
    {
      v31 = SimObject->m_Components.p[34].m_pComponent;
      goto LABEL_108;
    }
    if ( (v30 & 0x2000) == 0 )
    {
      if ( (v30 & 0x1000) != 0 )
        v31 = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::PhysicsMoverInterface::_TypeUID);
      else
        v31 = UFG::SimObject::GetComponentOfType(SimObject, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_108:
      if ( v31 )
        LODWORD(v31[14].vfptr) &= ~8u;
    }
  }
  v32 = SimObject->m_Flags;
  if ( (v32 & 0x4000) != 0 )
  {
    v33 = SimObject->m_Components.p[17].m_pComponent;
  }
  else if ( v32 >= 0 )
  {
    if ( (v32 & 0x2000) != 0 || (v32 & 0x1000) != 0 )
      v33 = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::CopUnitComponent::_TypeUID);
    else
      v33 = UFG::SimObject::GetComponentOfType(SimObject, UFG::CopUnitComponent::_TypeUID);
  }
  else
  {
    v33 = SimObject->m_Components.p[17].m_pComponent;
  }
  if ( v33 )
    LOBYTE(v33[7].m_Flags) |= 2u;
  NISActorNode::RestoreEquippedItems(this, SimObject);
  if ( this->mDeleteActorOnEnd )
    UFG::Simulation::DestroySimObject(&UFG::gSim, SimObject);
}

// File Line: 518
// RVA: 0x3E5040
void __fastcall NISActorNode::SetPlayTime(NISActorNode *this, float timeAbsolute, bool fixedTimeMode)
{
  UFG::SimObjectGame *SimObject; // rax
  UFG::SimObjectCVBase *v5; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  __int16 v8; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  UFG::CharacterAnimationComponent *v10; // rbx
  Creature *mCreature; // rdi

  if ( this->mIsPlaying )
  {
    SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
    v5 = (UFG::SimObjectCVBase *)SimObject;
    if ( SimObject )
    {
      m_Flags = SimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = SimObject->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = SimObject->m_Components.p[6].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::ActionTreeComponent::_TypeUID);
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(SimObject, UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = SimObject->m_Components.p[7].m_pComponent;
      }
      if ( m_pComponent )
        TimePlotPoint::SetTimeValue((UFG::TimeOfDayManager *)&m_pComponent[3], timeAbsolute);
      v8 = v5->m_Flags;
      if ( (v8 & 0x4000) != 0 || v8 < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
      }
      else if ( (v8 & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
      }
      else if ( (v8 & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v5,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v5,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      v10 = ComponentOfTypeHK;
      if ( ComponentOfTypeHK )
      {
        mCreature = ComponentOfTypeHK->mCreature;
        if ( mCreature )
        {
          Creature::SetPoseOnFrameBoundaries(ComponentOfTypeHK->mCreature, fixedTimeMode);
          Creature::SetBlendTreePlayTime(mCreature, timeAbsolute);
          ((void (__fastcall *)(UFG::CharacterAnimationComponent *))v10->vfptr[16].__vecDelDtor)(v10);
        }
      }
    }
  }
}

// File Line: 554
// RVA: 0x3E66A0
void __fastcall NISActorNode::Update(NISActorNode *this, float deltaTime)
{
  UFG::SimObjectGame *SimObject; // rax
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v7; // al

  this->mIsPlaying = 0;
  SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
  if ( SimObject )
  {
    m_Flags = SimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = SimObject->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = SimObject->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::ActionTreeComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(SimObject, UFG::ActionTreeComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = SimObject->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = m_pComponent[3].m_SafePointerList.mNode.mNext == (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)this;
      this->mIsPlaying = v7;
      if ( v7 )
        ((void (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent);
    }
  }
}

// File Line: 572
// RVA: 0x3E7620
void __fastcall NISActorNode::UpdateTransforms(NISActorNode *this, float deltaTime)
{
  UFG::SimObjectCVBase *SimObject; // rax
  UFG::SimObjectGame *v4; // rbx
  __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *v6; // rax
  UFG::CharacterAnimationComponent *v7; // rsi
  Creature *mCreature; // rcx
  hkQsTransformf *Root; // rax
  float v10; // xmm8_4
  __int128 v11; // xmm9
  float v12; // xmm10_4
  __m128 v13; // xmm2
  __m128 y_low; // xmm3
  hkQsTransformf *v15; // rax
  __int16 v16; // cx
  UFG::CompositeDrawableComponent *m_pComponent; // rax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qMatrix44 d; // [rsp+30h] [rbp-98h] BYREF

  if ( this->mIsPlaying )
  {
    SimObject = (UFG::SimObjectCVBase *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
    v4 = SimObject;
    if ( SimObject )
    {
      m_Flags = SimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(SimObject);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)SimObject);
      }
      else
      {
        v6 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    SimObject,
                                                    UFG::CharacterAnimationComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    SimObject,
                                                    UFG::CharacterAnimationComponent::_TypeUID));
      }
      v7 = v6;
      if ( v6 )
      {
        mCreature = v6->mCreature;
        if ( mCreature )
        {
          Root = SkeletalPose::GetRoot(&mCreature->mPose);
          v10 = Root->m_translation.m_quad.m128_f32[0];
          v11 = Root->m_translation.m_quad.m128_u32[1];
          v12 = Root->m_translation.m_quad.m128_f32[2];
          Creature::GetTranslation(v7->mCreature, &result, 1);
          if ( this->mCachedPositions && deltaTime > 0.0 )
          {
            y_low = (__m128)LODWORD(result.y);
            v13 = (__m128)v11;
            y_low.m128_f32[0] = result.y - this->mCachedHipsPosition.y;
            v13.m128_f32[0] = (float)((float)((float)(*(float *)&v11 - this->mCachedRootPosition.y)
                                            * (float)(*(float *)&v11 - this->mCachedRootPosition.y))
                                    + (float)((float)(v10 - this->mCachedRootPosition.x)
                                            * (float)(v10 - this->mCachedRootPosition.x)))
                            + (float)((float)(v12 - this->mCachedRootPosition.z)
                                    * (float)(v12 - this->mCachedRootPosition.z));
            if ( (float)(_mm_sqrt_ps(v13).m128_f32[0] * (float)(1.0 / deltaTime)) <= gMetersPerSecondBeforeTeleportCalled )
            {
              y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                                        + (float)((float)(result.x - this->mCachedHipsPosition.x)
                                                * (float)(result.x - this->mCachedHipsPosition.x)))
                                + (float)((float)(result.z - this->mCachedHipsPosition.z)
                                        * (float)(result.z - this->mCachedHipsPosition.z));
              if ( (float)(_mm_sqrt_ps(y_low).m128_f32[0] * (float)(1.0 / deltaTime)) > gMetersPerSecondBeforeClothReset )
              {
                v16 = v4->m_Flags;
                if ( (v16 & 0x4000) != 0 )
                {
                  m_pComponent = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
                }
                else if ( v16 >= 0 )
                {
                  if ( (v16 & 0x2000) != 0 )
                  {
                    m_pComponent = (UFG::CompositeDrawableComponent *)v4->m_Components.p[9].m_pComponent;
                  }
                  else if ( (v16 & 0x1000) != 0 )
                  {
                    m_pComponent = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v4,
                                                                        UFG::CompositeDrawableComponent::_TypeUID);
                  }
                  else
                  {
                    m_pComponent = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                                        v4,
                                                                        UFG::CompositeDrawableComponent::_TypeUID);
                  }
                }
                else
                {
                  m_pComponent = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
                }
                if ( m_pComponent )
                  UFG::CompositeDrawableComponent::TeleportEventHandler(m_pComponent, 0i64);
              }
            }
            else
            {
              v15 = SkeletalPose::GetRoot(&v7->mCreature->mPose);
              hkQsTransformf::get4x4ColumnMajor(v15, &d.v0.x);
              UFG::SimObjectUtility::Teleport(v4, &d);
            }
          }
          x = result.x;
          y = result.y;
          this->mCachedPositions = 1;
          this->mCachedRootPosition.x = v10;
          LODWORD(this->mCachedRootPosition.y) = v11;
          this->mCachedRootPosition.z = v12;
          this->mCachedHipsPosition.x = x;
          z = result.z;
          this->mCachedHipsPosition.y = y;
          this->mCachedHipsPosition.z = z;
        }
      }
    }
  }
  else
  {
    this->mCachedPositions = 0;
  }
}

// File Line: 633
// RVA: 0x3E4A30
void __fastcall NISActorNode::SaveEquippedItems(NISActorNode *this, UFG::SimObjectGame *simActorObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *v6; // rax
  signed __int16 v7; // cx
  UFG::InventoryComponent *v8; // r14
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mRightHandEquipSlot; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLeftHandEquipSlot; // rbx
  UFG::SimObject *v16; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mHatEquipSlot; // rdi
  UFG::SimObject *v21; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::SimObject *v25; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mGlassesEquipSlot; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::SimObject *v30; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mStowed1HSlot; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  unsigned int SlotTarget; // eax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mStowed2HSlot; // r8
  UFG::SimObject *v37; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v40; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObject *v42; // rcx
  UFG::SimObject *v43; // r8
  __int16 v44; // cx
  UFG::SimComponent *v45; // rax
  bool v46; // zf
  UFG::SimObjectGame *v47; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v48; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v49; // rax
  UFG::SimObject *v50; // rcx
  UFG::SimObject *v51; // r8
  __int16 v52; // cx
  UFG::SimComponent *v53; // rax
  UFG::SimObjectGame *v54; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v55; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v56; // rax
  UFG::SimObject *v57; // rcx
  UFG::SimObject *v58; // rcx
  UFG::SimObject *v59; // rcx

  if ( simActorObject )
  {
    m_Flags = simActorObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = simActorObject->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(simActorObject, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(simActorObject, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = simActorObject->m_Components.p[20].m_pComponent;
    }
    v7 = simActorObject->m_Flags;
    if ( (v7 & 0x4000) != 0 )
    {
      v8 = (UFG::InventoryComponent *)simActorObject->m_Components.p[39].m_pComponent;
    }
    else
    {
      v9 = v7 < 0 || (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(simActorObject, UFG::InventoryComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(simActorObject, UFG::InventoryComponent::_TypeUID);
      v8 = (UFG::InventoryComponent *)v9;
    }
    if ( m_pComponent && v8 )
    {
      v10 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_RIGHT_HAND)
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      p_mRightHandEquipSlot = &this->mRightHandEquipSlot;
      if ( this->mRightHandEquipSlot.m_pPointer )
      {
        mPrev = p_mRightHandEquipSlot->mPrev;
        mNext = this->mRightHandEquipSlot.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mRightHandEquipSlot->mPrev = p_mRightHandEquipSlot;
        this->mRightHandEquipSlot.mNext = &this->mRightHandEquipSlot;
      }
      this->mRightHandEquipSlot.m_pPointer = v10;
      if ( v10 )
      {
        v14 = v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v14->mNext = p_mRightHandEquipSlot;
        p_mRightHandEquipSlot->mPrev = v14;
        this->mRightHandEquipSlot.mNext = &v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mRightHandEquipSlot;
      }
      p_mLeftHandEquipSlot = &this->mLeftHandEquipSlot;
      v16 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_LEFT_HAND)
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      if ( this->mLeftHandEquipSlot.m_pPointer )
      {
        v17 = p_mLeftHandEquipSlot->mPrev;
        v18 = this->mLeftHandEquipSlot.mNext;
        v17->mNext = v18;
        v18->mPrev = v17;
        p_mLeftHandEquipSlot->mPrev = p_mLeftHandEquipSlot;
        this->mLeftHandEquipSlot.mNext = &this->mLeftHandEquipSlot;
      }
      this->mLeftHandEquipSlot.m_pPointer = v16;
      if ( v16 )
      {
        v19 = v16->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v19->mNext = p_mLeftHandEquipSlot;
        p_mLeftHandEquipSlot->mPrev = v19;
        this->mLeftHandEquipSlot.mNext = &v16->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v16->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mLeftHandEquipSlot;
      }
      p_mHatEquipSlot = &this->mHatEquipSlot;
      v21 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_HAT)
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      if ( this->mHatEquipSlot.m_pPointer )
      {
        v22 = p_mHatEquipSlot->mPrev;
        v23 = this->mHatEquipSlot.mNext;
        v22->mNext = v23;
        v23->mPrev = v22;
        p_mHatEquipSlot->mPrev = p_mHatEquipSlot;
        this->mHatEquipSlot.mNext = &this->mHatEquipSlot;
      }
      this->mHatEquipSlot.m_pPointer = v21;
      if ( v21 )
      {
        v24 = v21->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v24->mNext = p_mHatEquipSlot;
        p_mHatEquipSlot->mPrev = v24;
        this->mHatEquipSlot.mNext = &v21->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v21->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mHatEquipSlot;
      }
      v25 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_GLASSES)
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      p_mGlassesEquipSlot = &this->mGlassesEquipSlot;
      if ( this->mGlassesEquipSlot.m_pPointer )
      {
        v27 = p_mGlassesEquipSlot->mPrev;
        v28 = this->mGlassesEquipSlot.mNext;
        v27->mNext = v28;
        v28->mPrev = v27;
        p_mGlassesEquipSlot->mPrev = p_mGlassesEquipSlot;
        this->mGlassesEquipSlot.mNext = &this->mGlassesEquipSlot;
      }
      this->mGlassesEquipSlot.m_pPointer = v25;
      if ( v25 )
      {
        v29 = v25->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v29->mNext = p_mGlassesEquipSlot;
        p_mGlassesEquipSlot->mPrev = v29;
        this->mGlassesEquipSlot.mNext = &v25->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v25->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mGlassesEquipSlot;
      }
      v30 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_STOWED_1H)
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      p_mStowed1HSlot = &this->mStowed1HSlot;
      if ( this->mStowed1HSlot.m_pPointer )
      {
        v32 = p_mStowed1HSlot->mPrev;
        v33 = this->mStowed1HSlot.mNext;
        v32->mNext = v33;
        v33->mPrev = v32;
        p_mStowed1HSlot->mPrev = p_mStowed1HSlot;
        this->mStowed1HSlot.mNext = &this->mStowed1HSlot;
      }
      this->mStowed1HSlot.m_pPointer = v30;
      if ( v30 )
      {
        v34 = v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v34->mNext = p_mStowed1HSlot;
        p_mStowed1HSlot->mPrev = v34;
        this->mStowed1HSlot.mNext = &v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mStowed1HSlot;
      }
      SlotTarget = UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_STOWED_2H);
      p_mStowed2HSlot = &this->mStowed2HSlot;
      v37 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(SlotTarget + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      if ( this->mStowed2HSlot.m_pPointer )
      {
        v38 = p_mStowed2HSlot->mPrev;
        v39 = this->mStowed2HSlot.mNext;
        v38->mNext = v39;
        v39->mPrev = v38;
        p_mStowed2HSlot->mPrev = p_mStowed2HSlot;
        this->mStowed2HSlot.mNext = &this->mStowed2HSlot;
      }
      this->mStowed2HSlot.m_pPointer = v37;
      if ( v37 )
      {
        v40 = v37->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v40->mNext = p_mStowed2HSlot;
        p_mStowed2HSlot->mPrev = v40;
        this->mStowed2HSlot.mNext = &v37->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v37->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mStowed2HSlot;
      }
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_RIGHT_HAND, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_LEFT_HAND, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_HAT, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_GLASSES, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_STOWED_1H, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_STOWED_2H, 0);
      m_pPointer = this->mRightHandEquipSlot.m_pPointer;
      if ( m_pPointer )
        UFG::SimObject::Suspend(m_pPointer);
      v42 = this->mLeftHandEquipSlot.m_pPointer;
      if ( v42 )
      {
        UFG::SimObject::Suspend(v42);
        v43 = this->mLeftHandEquipSlot.m_pPointer;
        if ( v43 )
        {
          v44 = v43->m_Flags;
          if ( (v44 & 0x4000) == 0 && v44 >= 0 )
          {
            if ( (v44 & 0x2000) != 0 )
            {
              v45 = v43->m_Components.p[11].m_pComponent;
            }
            else
            {
              v46 = (v44 & 0x1000) == 0;
              v47 = (UFG::SimObjectGame *)this->mLeftHandEquipSlot.m_pPointer;
              v45 = v46
                  ? UFG::SimObject::GetComponentOfType(v47, UFG::InventoryItemComponent::_TypeUID)
                  : UFG::SimObjectGame::GetComponentOfTypeHK(v47, UFG::InventoryItemComponent::_TypeUID);
            }
            if ( v45 && LODWORD(v45[1].m_pSimObject) == 106 )
            {
              UFG::Simulation::DestroySimObject(&UFG::gSim, this->mLeftHandEquipSlot.m_pPointer);
              if ( this->mLeftHandEquipSlot.m_pPointer )
              {
                v48 = p_mLeftHandEquipSlot->mPrev;
                v49 = this->mLeftHandEquipSlot.mNext;
                v48->mNext = v49;
                v49->mPrev = v48;
                p_mLeftHandEquipSlot->mPrev = p_mLeftHandEquipSlot;
                this->mLeftHandEquipSlot.mNext = &this->mLeftHandEquipSlot;
              }
              this->mLeftHandEquipSlot.m_pPointer = 0i64;
            }
          }
        }
      }
      v50 = this->mHatEquipSlot.m_pPointer;
      if ( v50 )
      {
        UFG::SimObject::Suspend(v50);
        v51 = this->mHatEquipSlot.m_pPointer;
        if ( v51 )
        {
          v52 = v51->m_Flags;
          if ( (v52 & 0x4000) == 0 && v52 >= 0 )
          {
            if ( (v52 & 0x2000) != 0 )
            {
              v53 = v51->m_Components.p[11].m_pComponent;
            }
            else
            {
              v46 = (v52 & 0x1000) == 0;
              v54 = (UFG::SimObjectGame *)this->mHatEquipSlot.m_pPointer;
              v53 = v46
                  ? UFG::SimObject::GetComponentOfType(v54, UFG::InventoryItemComponent::_TypeUID)
                  : UFG::SimObjectGame::GetComponentOfTypeHK(v54, UFG::InventoryItemComponent::_TypeUID);
            }
            if ( v53 && LODWORD(v53[1].m_pSimObject) == 111 )
            {
              UFG::Simulation::DestroySimObject(&UFG::gSim, this->mHatEquipSlot.m_pPointer);
              if ( this->mHatEquipSlot.m_pPointer )
              {
                v55 = p_mHatEquipSlot->mPrev;
                v56 = this->mHatEquipSlot.mNext;
                v55->mNext = v56;
                v56->mPrev = v55;
                p_mHatEquipSlot->mPrev = p_mHatEquipSlot;
                this->mHatEquipSlot.mNext = &this->mHatEquipSlot;
              }
              this->mHatEquipSlot.m_pPointer = 0i64;
            }
          }
        }
      }
      v57 = this->mGlassesEquipSlot.m_pPointer;
      if ( v57 )
        UFG::SimObject::Suspend(v57);
      v58 = this->mStowed1HSlot.m_pPointer;
      if ( v58 )
        UFG::SimObject::Suspend(v58);
      v59 = this->mStowed2HSlot.m_pPointer;
      if ( v59 )
        UFG::SimObject::Suspend(v59);
    }
  }
}

// File Line: 710
// RVA: 0x3E48A0
void __fastcall NISActorNode::RestoreEquippedItems(NISActorNode *this, UFG::SimObjectGame *simActorObject)
{
  signed __int16 m_Flags; // cx
  UFG::InventoryComponent *m_pComponent; // rdi
  UFG::SimComponent *v5; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObject *v7; // rcx
  UFG::SimObject *v8; // rcx
  UFG::SimObject *v9; // rcx
  UFG::SimObject *v10; // rcx
  UFG::SimObject *v11; // rcx

  if ( simActorObject )
  {
    m_Flags = simActorObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InventoryComponent *)simActorObject->m_Components.p[39].m_pComponent;
    }
    else
    {
      v5 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(simActorObject, UFG::InventoryComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(simActorObject, UFG::InventoryComponent::_TypeUID);
      m_pComponent = (UFG::InventoryComponent *)v5;
    }
    if ( m_pComponent )
    {
      m_pPointer = this->mRightHandEquipSlot.m_pPointer;
      if ( m_pPointer )
      {
        UFG::SimObject::Restore(m_pPointer);
        UFG::InventoryComponent::Equip(
          m_pComponent,
          this->mRightHandEquipSlot.m_pPointer,
          1,
          eINVENTORY_EQUIP_SLOT_RIGHT_HAND);
      }
      v7 = this->mLeftHandEquipSlot.m_pPointer;
      if ( v7 )
      {
        UFG::SimObject::Restore(v7);
        UFG::InventoryComponent::Equip(
          m_pComponent,
          this->mLeftHandEquipSlot.m_pPointer,
          1,
          eINVENTORY_EQUIP_SLOT_LEFT_HAND);
      }
      v8 = this->mHatEquipSlot.m_pPointer;
      if ( v8 )
      {
        UFG::SimObject::Restore(v8);
        UFG::InventoryComponent::Equip(m_pComponent, this->mHatEquipSlot.m_pPointer);
      }
      v9 = this->mGlassesEquipSlot.m_pPointer;
      if ( v9 )
      {
        UFG::SimObject::Restore(v9);
        UFG::InventoryComponent::Equip(m_pComponent, this->mGlassesEquipSlot.m_pPointer);
      }
      v10 = this->mStowed1HSlot.m_pPointer;
      if ( v10 )
      {
        UFG::SimObject::Restore(v10);
        UFG::InventoryComponent::Equip(m_pComponent, this->mStowed1HSlot.m_pPointer, 1, eINVENTORY_EQUIP_SLOT_STOWED_1H);
      }
      v11 = this->mStowed2HSlot.m_pPointer;
      if ( v11 )
      {
        UFG::SimObject::Restore(v11);
        UFG::InventoryComponent::Equip(m_pComponent, this->mStowed2HSlot.m_pPointer, 1, eINVENTORY_EQUIP_SLOT_STOWED_2H);
      }
    }
  }
}

// File Line: 757
// RVA: 0x14D1220
const char *dynamic_initializer_for__sNISActorFactoryList__()
{
  const char *result; // rax

  result = NISActorNode::sClassName;
  sNISActorFactoryList[0].mClassName = NISActorNode::sClassName;
  return result;
}

// File Line: 763
// RVA: 0x14CF0B0
__int64 dynamic_initializer_for__gNISActorFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gNISActorFactory, sNISActorFactoryList, sNISActorFactoryListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gNISActorFactory__);
}

// File Line: 770
// RVA: 0x14CA060
__int64 dynamic_initializer_for__NISNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NISNode", 0xFFFFFFFF);
  NISNode::sClassNameUID = result;
  return result;
}

// File Line: 843
// RVA: 0x3E02F0
void __fastcall NISNode::NISNode(NISNode *this)
{
  char *v2; // rbx
  char *v3; // rax
  UFG::qOffset64<TrackGroup *> *p_mTracksAction; // rcx
  __int64 v5; // rax

  ActionNodeImplementation::ActionNodeImplementation(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISNode::`vftable;
  this->mIsPlaceHolder = 0;
  this->mPlaceHolderMessage.mOffset = 1i64;
  BinString::Set(&this->mPlaceHolderMessage, &customCaption);
  *(_DWORD *)&this->mCanSkip = 16843009;
  *(_DWORD *)&this->mDisableHUD = 1;
  *(_DWORD *)&this->mAllowLetterbox = 16842753;
  *(_QWORD *)&this->mTimeBeforeCanSkip = 1065353216i64;
  v2 = 0i64;
  this->mPostNISTOD = -1.0;
  this->mTODTime = -1.0;
  this->mWeatherWetness = -1.0;
  this->mGI_Irradiance = 1.0;
  this->mFadeOutDuration = -1.0;
  this->mFadeInDuration = -1.0;
  this->mWeatherType.mValue = 0;
  this->mAnimationGroupName.mOffset = 1i64;
  BinString::Set(&this->mAnimationGroupName, &customCaption);
  this->mFacialAnimGroupName.mOffset = 1i64;
  BinString::Set(&this->mFacialAnimGroupName, &customCaption);
  this->mExtraFacialAnimGroupName.mOffset = 1i64;
  BinString::Set(&this->mExtraFacialAnimGroupName, &customCaption);
  this->mPostNISMarkerName.mOffset = 1i64;
  BinString::Set(&this->mPostNISMarkerName, &customCaption);
  this->mLightLayerDisableName.mOffset = 1i64;
  BinString::Set(&this->mLightLayerDisableName, &customCaption);
  this->mTODEnvSetting.mOffset = 1i64;
  BinString::Set(&this->mTODEnvSetting, &customCaption);
  this->mSoundbank.mOffset = 1i64;
  BinString::Set(&this->mSoundbank, &customCaption);
  this->mNISName.mOffset = 1i64;
  BinString::Set(&this->mNISName, &customCaption);
  this->mPrimaryCameraAnimationTrack = 0i64;
  this->mLightGroupObject = 0i64;
  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "ActionNodeImplementation.mTracksAction", 0i64, 1u);
  if ( v3 )
  {
    *(_QWORD *)v3 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v3 + 1) = 0i64;
    *(_QWORD *)v3 = &TrackGroup::`vftable;
    *((_DWORD *)v3 + 4) = 0;
    *((_QWORD *)v3 + 3) = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  p_mTracksAction = &this->mTracksAction;
  if ( v3 )
    v5 = v3 - (char *)p_mTracksAction;
  else
    v5 = 0i64;
  p_mTracksAction->mOffset = v5;
  if ( v5 )
    v2 = (char *)p_mTracksAction + v5;
  (*(void (__fastcall **)(char *, NISNode *))(*(_QWORD *)v2 + 64i64))(v2, this);
  UFG::qMemSet(this->m_audioTagId, 0, 0x10u);
  UFG::qMemSet(this->m_audioTagUID, 0, 0x10u);
}

// File Line: 896
// RVA: 0x3E0D70
void __fastcall NISNode::~NISNode(NISNode *this)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  NISLightGroup *mLightGroupObject; // rdi
  char *v5; // rcx
  char *v6; // rcx
  char *v7; // rcx
  char *v8; // rcx
  char *v9; // rcx
  char *v10; // rcx
  char *v11; // rcx
  char *v12; // rcx
  char *v13; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&NISNode::`vftable;
  mOffset = this->mTracksAction.mOffset;
  if ( mOffset )
  {
    v3 = (char *)&this->mTracksAction + mOffset;
    if ( v3 )
      (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v3 + 8i64))(v3, 1i64);
  }
  mLightGroupObject = this->mLightGroupObject;
  if ( mLightGroupObject )
  {
    NISLightGroup::~NISLightGroup(this->mLightGroupObject);
    operator delete[](mLightGroupObject);
  }
  if ( (this->mNISName.mOffset & 1) != 0 && (this->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v5 = (char *)&this->mNISName + (this->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v5 != BinString::sEmptyString )
      operator delete[](v5);
  }
  if ( (this->mSoundbank.mOffset & 1) != 0 && (this->mSoundbank.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v6 = (char *)&this->mSoundbank + (this->mSoundbank.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v6 != BinString::sEmptyString )
      operator delete[](v6);
  }
  if ( (this->mTODEnvSetting.mOffset & 1) != 0 && (this->mTODEnvSetting.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v7 = (char *)&this->mTODEnvSetting + (this->mTODEnvSetting.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v7 != BinString::sEmptyString )
      operator delete[](v7);
  }
  if ( (this->mLightLayerDisableName.mOffset & 1) != 0
    && (this->mLightLayerDisableName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v8 = (char *)&this->mLightLayerDisableName + (this->mLightLayerDisableName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v8 != BinString::sEmptyString )
      operator delete[](v8);
  }
  if ( (this->mPostNISMarkerName.mOffset & 1) != 0 && (this->mPostNISMarkerName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v9 = (char *)&this->mPostNISMarkerName + (this->mPostNISMarkerName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v9 != BinString::sEmptyString )
      operator delete[](v9);
  }
  if ( (this->mExtraFacialAnimGroupName.mOffset & 1) != 0
    && (this->mExtraFacialAnimGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v10 = (char *)&this->mExtraFacialAnimGroupName + (this->mExtraFacialAnimGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v10 != BinString::sEmptyString )
      operator delete[](v10);
  }
  if ( (this->mFacialAnimGroupName.mOffset & 1) != 0
    && (this->mFacialAnimGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v11 = (char *)&this->mFacialAnimGroupName + (this->mFacialAnimGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v11 != BinString::sEmptyString )
      operator delete[](v11);
  }
  if ( (this->mAnimationGroupName.mOffset & 1) != 0 && (this->mAnimationGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v12 = (char *)&this->mAnimationGroupName + (this->mAnimationGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v12 != BinString::sEmptyString )
      operator delete[](v12);
  }
  if ( (this->mPlaceHolderMessage.mOffset & 1) != 0 && (this->mPlaceHolderMessage.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v13 = (char *)&this->mPlaceHolderMessage + (this->mPlaceHolderMessage.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v13 != BinString::sEmptyString )
      operator delete[](v13);
  }
  ActionNodeImplementation::~ActionNodeImplementation(this);
}

// File Line: 902
// RVA: 0x3E61E0
void __fastcall NISNode::Trim(NISNode *this, bool force)
{
  __int64 mOffset; // rax
  _DWORD *v4; // rcx

  ActionNodeImplementation::Trim(this, force);
  mOffset = this->mTracksAction.mOffset;
  if ( mOffset )
  {
    v4 = (_DWORD *)((char *)&this->mTracksAction + mOffset);
    if ( v4 )
    {
      if ( (v4[4] & 0x7FFFFFFF) == 0 )
      {
        (*(void (__fastcall **)(_DWORD *, __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
        this->mTracksAction.mOffset = 0i64;
      }
    }
  }
}

// File Line: 920
// RVA: 0x3E4FB0
void __fastcall NISNode::Serialize(NISNode *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  Expression::IMemberMap *v4; // rdx

  mOffset = this->mTracksAction.mOffset;
  if ( mOffset )
  {
    v4 = (Expression::IMemberMap *)((char *)&this->mTracksAction + mOffset);
    if ( v4 )
      IActionTreeSerializer::PushObjectToSerialize(serializer, v4);
  }
}

// File Line: 989
// RVA: 0x3E47B0
void __fastcall NISNode::ResolveReferences(NISNode *this)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  char *v4; // r14
  unsigned int i; // ebx
  __int64 v6; // rax
  char *v7; // rcx
  CameraAnimationTrack *v8; // rsi

  this->mPrimaryCameraAnimationTrack = 0i64;
  ActionNode::ResolveReferences(this);
  mOffset = this->mTracksAction.mOffset;
  if ( mOffset )
  {
    v3 = (char *)&this->mTracksAction + mOffset;
    if ( v3 )
    {
      v4 = &v3[*((_QWORD *)v3 + 3) + 24];
      for ( i = 0; ; ++i )
      {
        v6 = this->mTracksAction.mOffset;
        v7 = v6 ? (char *)&this->mTracksAction + v6 : 0i64;
        if ( i >= (*((_DWORD *)v7 + 4) & 0x7FFFFFFFu) )
          break;
        v8 = (CameraAnimationTrack *)&v4[8 * i + *(_QWORD *)&v4[8 * i]];
        v8->vfptr[1].__vecDelDtor(v8, (unsigned int)this);
        if ( CameraAnimationTrack::sClassNameUID == v8->vfptr->GetClassNameUID(v8)
          && !this->mPrimaryCameraAnimationTrack )
        {
          this->mPrimaryCameraAnimationTrack = v8;
        }
      }
    }
  }
}

// File Line: 1100
// RVA: 0x3E5570
void __fastcall NISNode::SetPlayTime(NISNode *this, float timeAbsolute, bool fixedTimeMode)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v7; // rbx
  Creature *v8; // rdi
  NISLightGroup *mLightGroupObject; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rbx
  Creature *v13; // rdi
  __int64 v14; // rax
  _DWORD *v15; // rdi
  __int64 v16; // rbx
  __int64 v17; // rsi

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CameraAnimationComponent::_TypeUID);
    v7 = ComponentOfType;
    if ( ComponentOfType )
    {
      v8 = *(Creature **)&ComponentOfType[2].m_TypeUID;
      if ( v8 )
      {
        Creature::SetPoseOnFrameBoundaries(*(Creature **)&ComponentOfType[2].m_TypeUID, fixedTimeMode);
        Creature::SetBlendTreePlayTime(v8, timeAbsolute);
      }
      ((void (__fastcall *)(UFG::SimComponent *))v7->vfptr[16].__vecDelDtor)(v7);
    }
  }
  mLightGroupObject = this->mLightGroupObject;
  if ( mLightGroupObject )
  {
    m_pPointer = mLightGroupObject->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      v11 = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::LightGroupAnimationComponent::_TypeUID);
      v12 = v11;
      if ( v11 )
      {
        v13 = *(Creature **)&v11[2].m_TypeUID;
        if ( v13 )
        {
          Creature::SetPoseOnFrameBoundaries(*(Creature **)&v11[2].m_TypeUID, fixedTimeMode);
          Creature::SetBlendTreePlayTime(v13, timeAbsolute);
          ((void (__fastcall *)(UFG::SimComponent *))v12->vfptr[16].__vecDelDtor)(v12);
        }
      }
    }
  }
  v14 = ((__int64 (__fastcall *)(NISNode *))this->vfptr[1].GetResourcePath)(this);
  v15 = (_DWORD *)v14;
  if ( v14 )
  {
    v16 = 0i64;
    v17 = v14 + *(_QWORD *)(v14 + 8) + 8i64;
    if ( (*(_DWORD *)v14 & 0x7FFFFFFF) != 0 )
    {
      do
      {
        NISActorNode::SetPlayTime(
          (NISActorNode *)(*(_QWORD *)(v17 + 8 * v16) + v17 + 8 * v16),
          timeAbsolute,
          fixedTimeMode);
        v16 = (unsigned int)(v16 + 1);
      }
      while ( (unsigned int)v16 < (*v15 & 0x7FFFFFFFu) );
    }
  }
}

