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
  NISActorNode *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // [rsp+48h] [rbp+10h]

  v1 = this;
  ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&NISActorNode::`vftable;
  v2 = &v1->mRightHandEquipSlot;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mRightHandEquipSlot.m_pPointer = 0i64;
  v3 = &v1->mLeftHandEquipSlot;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->mLeftHandEquipSlot.m_pPointer = 0i64;
  v4 = &v1->mHatEquipSlot;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->mHatEquipSlot.m_pPointer = 0i64;
  v5 = &v1->mGlassesEquipSlot;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mGlassesEquipSlot.m_pPointer = 0i64;
  v6 = &v1->mStowed1HSlot;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->mStowed1HSlot.m_pPointer = 0i64;
  v7 = &v1->mStowed2HSlot;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mStowed2HSlot.m_pPointer = 0i64;
  *(_QWORD *)&v1->mCachedRootPosition.x = 0i64;
  *(_QWORD *)&v1->mCachedRootPosition.z = 0i64;
  *(_QWORD *)&v1->mCachedHipsPosition.y = 0i64;
  *(_QWORD *)&v1->mActorID.mUID = -1i64;
  *(_DWORD *)&v1->mResetActorOnStart = 65537;
  *(_DWORD *)&v1->mDisableCharacterCollision = 257;
  v1->mCachedPositions = 0;
}

// File Line: 150
// RVA: 0x3E56B0
void __fastcall NISActorNode::SetupActor(NISActorNode *this, const bool bHighDef)
{
  bool v2; // si
  NISActorNode *v3; // rbx
  UFG::qBaseNodeRB *v4; // rax
  UFG::SimObject *v5; // rdi

  v2 = bHighDef;
  v3 = this;
  if ( !this->mPreloaded )
  {
    v4 = UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
    v5 = (UFG::SimObject *)v4;
    if ( v4 )
    {
      v3->mDeleteActorOnEnd = 0;
      NISActorNode::SaveEquippedItems(v3, (UFG::SimObject *)v4);
      if ( v2 )
      {
        v3->mDowngradeModelOnCleanup = 1;
        UFG::SimObjectUtility::UpgradeModelResolution(v5);
      }
    }
    else
    {
      UFG::SpawnInfoInterface::SpawnObject(&v3->mActorID, &v3->mPropertySet, 0, 0i64, 0i64, 0i64);
      v3->mDeleteActorOnEnd = 1;
    }
    *(_WORD *)&v3->mPreloaded = 1;
  }
}

// File Line: 205
// RVA: 0x3E3850
void __fastcall NISActorNode::Play(NISActorNode *this)
{
  NISActorNode *v1; // rdi
  UFG::qBaseNodeRB *v2; // rax
  UFG::SimObjectGame *v3; // rbx
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rax

  v1 = this;
  v2 = UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
  v3 = (UFG::SimObjectGame *)v2;
  if ( v2 )
  {
    NISActorNode::setupActorForNIS(v1, (UFG::SimObject *)v2);
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[7].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = v3->m_Components.p[6].m_pComponent;
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v5 = v3->m_Components.p[7].m_pComponent;
    }
    if ( v5 )
    {
      LOBYTE(v5[2].m_pSimObject) = 1;
      ActionController::Play((ActionController *)&v5[3], (ActionNodePlayable *)&v1->vfptr);
    }
  }
}

// File Line: 224
// RVA: 0x3E8050
void __fastcall NISActorNode::setupActorForNIS(NISActorNode *this, UFG::SimObject *simActorObject)
{
  UFG::SimObjectCVBase *v2; // rbx
  NISActorNode *v3; // rsi
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rbp
  char *v7; // rax
  bool v8; // di
  UFG::PedSpawnManager *v9; // rax
  unsigned __int16 v10; // cx
  UFG::RagdollComponent *v11; // rax
  unsigned __int16 v12; // cx
  UFG::ActionTreeComponent *v13; // rax
  __int64 v14; // rax
  signed __int64 v15; // rcx
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rcx
  UFG::SimComponent *v18; // rax
  __int64 v19; // rcx
  UFG::RigidBody *v20; // rax
  unsigned int v21; // edi
  unsigned __int16 v22; // cx
  UFG::CharacterPhysicsComponent *v23; // rax
  unsigned __int16 v24; // cx
  UFG::SimComponent *v25; // rax
  UFG::SceneObjectProperties *v26; // rsi
  UFG::qMemoryPool *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::SimComponent *v29; // rax
  unsigned __int16 v30; // cx
  unsigned __int16 v31; // cx
  UFG::CharacterAnimationComponent *v32; // rax
  UFG::CharacterAnimationComponent *v33; // rdi
  unsigned __int16 v34; // cx
  UFG::SimComponent *v35; // rcx
  UFG::SimComponent *v36; // rax
  unsigned __int16 v37; // cx
  UFG::AnimationLODComponent *v38; // rsi
  UFG::SimComponent *v39; // rax
  unsigned __int16 v40; // cx
  UFG::FacialActionTreeComponent *v41; // rax
  Creature *v42; // rcx
  unsigned __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  unsigned __int16 v45; // cx
  UFG::SimComponent *v46; // rax
  unsigned __int16 v47; // cx
  UFG::CompositeLookComponent *v48; // rax
  UFG::SimObjectModifier v49; // [rsp+38h] [rbp-40h]
  unsigned int v50; // [rsp+88h] [rbp+10h]
  UFG::allocator::free_link *v51; // [rsp+90h] [rbp+18h]

  if ( !simActorObject )
    return;
  v2 = (UFG::SimObjectCVBase *)simActorObject;
  v3 = this;
  v50 = this->mPropertySet.mUID;
  v4 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&v50);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_Ragdoll::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v7 = 0i64;
  v8 = v7 != 0i64;
  v9 = UFG::PedSpawnManager::GetInstance();
  if ( !UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
          v9,
          Active,
          (UFG::SimObject *)&v2->vfptr,
          "d:\\ufg\\madscience\\project\\builds\\sdhd\\sdhd_pc\\source\\nis\\nisnodes.cpp",
          238) )
    UFG::SimObject::Restore((UFG::SimObject *)&v2->vfptr);
  if ( v3->mResetActorOnStart )
    UFG::SimObjectUtility::ResetState((UFG::SimObject *)&v2->vfptr, 0, 0);
  v10 = v2->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = (UFG::RagdollComponent *)v2->m_Components.p[42].m_pComponent;
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
    {
      v11 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                       (UFG::SimObjectGame *)&v2->vfptr,
                                       UFG::RagdollComponent::_TypeUID);
    }
    else if ( (v10 >> 12) & 1 )
    {
      v11 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                       (UFG::SimObjectGame *)&v2->vfptr,
                                       UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      v11 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                       (UFG::SimObject *)&v2->vfptr,
                                       UFG::RagdollComponent::_TypeUID);
    }
  }
  else
  {
    v11 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                     (UFG::SimObjectGame *)&v2->vfptr,
                                     UFG::RagdollComponent::_TypeUID);
  }
  if ( !v11 )
  {
    if ( !v8 )
      goto LABEL_22;
    v11 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire((UFG::SimObject *)&v2->vfptr);
  }
  UFG::RagdollComponent::SetCollisionState(v11, CS_KEYFRAMED_NO_COLLISION);
LABEL_22:
  v12 = v2->m_Flags;
  if ( (v12 >> 14) & 1 )
  {
    v13 = (UFG::ActionTreeComponent *)v2->m_Components.p[7].m_pComponent;
  }
  else if ( (v12 & 0x8000u) == 0 )
  {
    if ( (v12 >> 13) & 1 )
    {
      v13 = (UFG::ActionTreeComponent *)v2->m_Components.p[6].m_pComponent;
    }
    else if ( (v12 >> 12) & 1 )
    {
      v13 = (UFG::ActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v2->vfptr,
                                          UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v13 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v2->vfptr,
                                          UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v13 = (UFG::ActionTreeComponent *)v2->m_Components.p[7].m_pComponent;
  }
  if ( v13 )
    UFG::ActionTreeComponent::Reset(v13);
  v14 = v3->mParent.mOffset;
  if ( v14 )
  {
    v15 = (signed __int64)&v3->mParent + v14;
    if ( v15 )
    {
      if ( *(_BYTE *)(v15 + 105) )
      {
        v16 = v2->m_Flags;
        if ( (v16 >> 14) & 1 )
        {
          v17 = v2->m_Components.p[27].m_pComponent;
        }
        else
        {
          if ( (v16 & 0x8000u) == 0 )
          {
            if ( (v16 >> 13) & 1 )
            {
              v18 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v2->vfptr,
                      UFG::CharacterPhysicsComponent::_TypeUID);
            }
            else if ( (v16 >> 12) & 1 )
            {
              v18 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v2->vfptr,
                      UFG::CharacterPhysicsComponent::_TypeUID);
            }
            else
            {
              v18 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v2->vfptr,
                      UFG::CharacterPhysicsComponent::_TypeUID);
            }
          }
          else
          {
            v18 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v2->vfptr,
                    UFG::CharacterPhysicsComponent::_TypeUID);
          }
          v17 = v18;
        }
        if ( v17 )
        {
          LODWORD(v17[9].m_SafePointerList.mNode.mPrev) = 0;
          v17[9].m_NameUID = v17[9].m_NameUID & 0xFFFFFFEF | 1;
        }
        else
        {
          v19 = v2->m_Flags;
          if ( ((unsigned __int16)v19 >> 14) & 1 )
          {
            v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v2->vfptr,
                                      UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v19 & 0x8000u) == 0i64 )
          {
            if ( ((unsigned __int16)v19 >> 13) & 1 )
            {
              v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v2->vfptr,
                                        UFG::RigidBodyComponent::_TypeUID);
            }
            else if ( ((unsigned __int16)v19 >> 12) & 1 )
            {
              v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v2->vfptr,
                                        UFG::RigidBodyComponent::_TypeUID);
            }
            else
            {
              v20 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v2->vfptr,
                                        UFG::RigidBodyComponent::_TypeUID);
            }
          }
          else
          {
            v20 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v2->vfptr,
                                      UFG::RigidBodyComponent::_TypeUID);
          }
          if ( v20 )
            UFG::RigidBody::SetMotionType(v20, 0x100u);
        }
      }
    }
  }
  v21 = 6;
  if ( v3->mDisableCharacterCollision )
  {
    v22 = v2->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v23 = (UFG::CharacterPhysicsComponent *)v2->m_Components.p[27].m_pComponent;
    }
    else if ( (v22 & 0x8000u) == 0 )
    {
      if ( (v22 >> 13) & 1 )
        v23 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v2->vfptr,
                                                  UFG::CharacterPhysicsComponent::_TypeUID);
      else
        v23 = (UFG::CharacterPhysicsComponent *)((v22 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v2->vfptr,
                                                                     UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterPhysicsComponent::_TypeUID));
    }
    else
    {
      v23 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v2->vfptr,
                                                UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v23 )
      UFG::CharacterPhysicsComponent::SetCollisionModel(v23, CP_DISABLED);
  }
  v24 = v2->m_Flags;
  if ( (v24 >> 14) & 1 )
  {
    v25 = v2->m_Components.p[7].m_pComponent;
  }
  else if ( (v24 & 0x8000u) == 0 )
  {
    if ( (v24 >> 13) & 1 )
    {
      v25 = v2->m_Components.p[6].m_pComponent;
    }
    else if ( (v24 >> 12) & 1 )
    {
      v25 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v25 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v25 = v2->m_Components.p[7].m_pComponent;
  }
  if ( !v25 )
  {
    v26 = v2->m_pSceneObj;
    v27 = UFG::GetSimulationMemoryPool();
    v28 = UFG::qMemoryPool::Allocate(v27, 0x560ui64, "NISActorNode::setupActorForNIS", 0i64, 1u);
    v51 = v28;
    if ( v28 )
    {
      UFG::ActionTreeComponent::ActionTreeComponent((UFG::ActionTreeComponent *)v28, v26, 0, 0i64);
      v6 = v29;
    }
    v30 = v2->m_Flags;
    if ( (v30 >> 14) & 1 )
    {
      v21 = 7;
    }
    else if ( (v30 & 0x8000u) == 0 )
    {
      if ( !((v30 >> 13) & 1) )
        v21 = -1;
    }
    else
    {
      v21 = 7;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v49, (UFG::SimObject *)&v2->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v49, v6, v21);
    UFG::SimObjectModifier::Close(&v49);
    UFG::SimObjectModifier::~SimObjectModifier(&v49);
  }
  v31 = v2->m_Flags;
  if ( (v31 >> 14) & 1 )
  {
    v32 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
  }
  else if ( (v31 & 0x8000u) == 0 )
  {
    if ( (v31 >> 13) & 1 )
    {
      v32 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v2);
    }
    else if ( (v31 >> 12) & 1 )
    {
      v32 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v2->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      v32 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v2->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    v32 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
  }
  v33 = v32;
  if ( v32 )
  {
    v32->mEnableUpdateTransforms = 1;
    v32->mUpdatedFromNIS = 1;
  }
  v34 = v2->m_Flags;
  if ( (v34 >> 14) & 1 )
  {
    v35 = v2->m_Components.p[28].m_pComponent;
  }
  else
  {
    if ( (v34 & 0x8000u) == 0 )
    {
      if ( (v34 >> 13) & 1 )
      {
        v36 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v2->vfptr,
                UFG::WorldContextComponent::_TypeUID);
      }
      else if ( (v34 >> 12) & 1 )
      {
        v36 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v2->vfptr,
                UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v36 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::WorldContextComponent::_TypeUID);
      }
    }
    else
    {
      v36 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::WorldContextComponent::_TypeUID);
    }
    v35 = v36;
  }
  if ( v35 )
    ((void (*)(void))v35->vfptr[8].__vecDelDtor)();
  v37 = v2->m_Flags;
  if ( (v37 >> 14) & 1 )
  {
    v38 = (UFG::AnimationLODComponent *)v2->m_Components.p[13].m_pComponent;
  }
  else if ( (v37 & 0x8000u) == 0 )
  {
    if ( (v37 >> 13) & 1 )
    {
      v39 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::AnimationLODComponent::_TypeUID);
    }
    else if ( (v37 >> 12) & 1 )
    {
      v39 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::AnimationLODComponent::_TypeUID);
    }
    else
    {
      v39 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AnimationLODComponent::_TypeUID);
    }
    v38 = (UFG::AnimationLODComponent *)v39;
  }
  else
  {
    v38 = (UFG::AnimationLODComponent *)v2->m_Components.p[13].m_pComponent;
  }
  if ( v38 )
  {
    UFG::AnimationLODComponent::MakeHighLOD(v38);
    ((void (__fastcall *)(UFG::AnimationLODComponent *))v38->vfptr[8].__vecDelDtor)(v38);
  }
  v40 = v2->m_Flags;
  if ( (v40 >> 14) & 1 )
  {
    v41 = (UFG::FacialActionTreeComponent *)v2->m_Components.p[31].m_pComponent;
  }
  else
  {
    if ( (v40 & 0x8000u) != 0 || (v40 >> 13) & 1 )
      goto LABEL_136;
    if ( (v40 >> 12) & 1 )
      v41 = (UFG::FacialActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v2->vfptr,
                                                UFG::FacialActionTreeComponent::_TypeUID);
    else
      v41 = (UFG::FacialActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v2->vfptr,
                                                UFG::FacialActionTreeComponent::_TypeUID);
  }
  if ( v41 )
  {
    UFG::FacialActionTreeComponent::Disable(v41);
    if ( v33 )
    {
      v42 = v33->mCreature;
      if ( v42 )
        Creature::KillBlendTree(v42);
    }
  }
LABEL_136:
  v43 = v2->m_Flags;
  if ( !((v43 >> 14) & 1) )
  {
    if ( (v43 & 0x8000u) != 0 )
    {
      v44 = v2->m_Components.p[34].m_pComponent;
      goto LABEL_143;
    }
    if ( !((v43 >> 13) & 1) )
    {
      if ( (v43 >> 12) & 1 )
        v44 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v2->vfptr,
                UFG::PhysicsMoverInterface::_TypeUID);
      else
        v44 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_143:
      if ( v44 )
        LODWORD(v44[14].vfptr) |= 8u;
      goto LABEL_145;
    }
  }
LABEL_145:
  v45 = v2->m_Flags;
  if ( (v45 >> 14) & 1 )
  {
    v46 = v2->m_Components.p[17].m_pComponent;
  }
  else if ( (v45 & 0x8000u) == 0 )
  {
    if ( (v45 >> 13) & 1 )
    {
      v46 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::CopUnitComponent::_TypeUID);
    }
    else if ( (v45 >> 12) & 1 )
    {
      v46 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::CopUnitComponent::_TypeUID);
    }
    else
    {
      v46 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CopUnitComponent::_TypeUID);
    }
  }
  else
  {
    v46 = v2->m_Components.p[17].m_pComponent;
  }
  if ( v46 )
    LOBYTE(v46[7].m_Flags) &= 0xFDu;
  v47 = v2->m_Flags;
  if ( (v47 >> 14) & 1 )
  {
    v48 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::CompositeLookComponent::_TypeUID);
  }
  else if ( (v47 & 0x8000u) == 0 )
  {
    if ( (v47 >> 13) & 1 )
    {
      v48 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v2->vfptr,
                                             UFG::CompositeLookComponent::_TypeUID);
    }
    else if ( (v47 >> 12) & 1 )
    {
      v48 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v2->vfptr,
                                             UFG::CompositeLookComponent::_TypeUID);
    }
    else
    {
      v48 = (UFG::CompositeLookComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v2->vfptr,
                                             UFG::CompositeLookComponent::_TypeUID);
    }
  }
  else
  {
    v48 = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::CompositeLookComponent::_TypeUID);
  }
  if ( v48 )
    UFG::CompositeLookComponent::ForceVisibleTransparency(v48);
}

// File Line: 388
// RVA: 0x3E7A80
void __fastcall NISActorNode::nodeCleanup(NISActorNode *this)
{
  NISActorNode *v1; // rsi
  UFG::SimObjectCVBase *v2; // rbx
  UFG::PedSpawnManager *v3; // rax
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax
  __int64 v6; // rax
  signed __int64 v7; // rcx
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  UFG::RigidBody *v12; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v13; // rcx
  const char *v14; // rax
  UFG::CollisionMeshData *v15; // rdx
  unsigned __int16 v16; // cx
  UFG::CharacterPhysicsComponent *v17; // rdi
  UFG::SimComponent *v18; // rax
  unsigned __int16 v19; // cx
  UFG::CharacterAnimationComponent *v20; // rax
  Creature *v21; // rcx
  unsigned __int16 v22; // cx
  UFG::SimComponent *v23; // rcx
  UFG::SimComponent *v24; // rax
  unsigned __int16 v25; // cx
  UFG::SimComponent *v26; // rcx
  UFG::SimComponent *v27; // rax
  unsigned __int16 v28; // cx
  UFG::FacialActionTreeComponent *v29; // rax
  unsigned __int16 v30; // cx
  UFG::SimComponent *v31; // rax
  unsigned __int16 v32; // cx
  UFG::SimComponent *v33; // rax
  UFG::qReflectHandleBase v34; // [rsp+38h] [rbp-30h]

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
  if ( !v2 )
    return;
  v3 = UFG::PedSpawnManager::GetInstance();
  if ( !UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
          v3,
          Active,
          (UFG::SimObject *)&v2->vfptr,
          "d:\\ufg\\madscience\\project\\builds\\sdhd\\sdhd_pc\\source\\nis\\nisnodes.cpp",
          396) )
    UFG::SimObject::Restore((UFG::SimObject *)&v2->vfptr);
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v2->m_Components.p[7].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
    {
      v5 = v2->m_Components.p[6].m_pComponent;
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)&v2->vfptr,
             UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v5 = v2->m_Components.p[7].m_pComponent;
  }
  if ( v5 )
  {
    LOBYTE(v5[2].m_pSimObject) = 0;
    if ( v1->mResetActorOnEnd )
      ActionController::Stop((ActionController *)&v5[3]);
  }
  v6 = v1->mParent.mOffset;
  if ( v6 )
  {
    v7 = (signed __int64)&v1->mParent + v6;
    if ( v7 )
    {
      if ( *(_BYTE *)(v7 + 105) )
      {
        v8 = v2->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = v2->m_Components.p[27].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v2->vfptr,
                   UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v2->vfptr,
                   UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else
          {
            v9 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v2->vfptr,
                   UFG::CharacterPhysicsComponent::_TypeUID);
          }
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v2->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
        if ( v9 )
        {
          LODWORD(v9[9].m_SafePointerList.mNode.mPrev) = 1092416963;
          v9[9].m_NameUID &= 0xFFFFFFFE;
        }
        else
        {
          v10 = v2->m_Flags;
          if ( (v10 >> 14) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v2->vfptr,
                    UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v10 & 0x8000u) == 0 )
          {
            if ( (v10 >> 13) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v2->vfptr,
                      UFG::RigidBodyComponent::_TypeUID);
            }
            else if ( (v10 >> 12) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v2->vfptr,
                      UFG::RigidBodyComponent::_TypeUID);
            }
            else
            {
              v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RigidBodyComponent::_TypeUID);
            }
          }
          else
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v2->vfptr,
                    UFG::RigidBodyComponent::_TypeUID);
          }
          v12 = (UFG::RigidBody *)v11;
          if ( v11 )
          {
            UFG::qReflectHandleBase::qReflectHandleBase(&v34);
            v14 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v13);
            v34.mTypeUID = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
            v15 = v12->mCollisionMeshData;
            if ( v15 )
              UFG::qReflectHandleBase::operator=(&v34, (UFG::qReflectHandleBase *)&v15->mObjectProperties.mPrev);
            if ( v34.mData && LODWORD(v34.mData[2].mBaseNode.mChildren[1]) == 2 )
              UFG::RigidBody::SetMotionType(v12, 0x80u);
            UFG::qReflectHandleBase::~qReflectHandleBase(&v34);
          }
        }
      }
    }
  }
  if ( v1->mDisableCharacterCollision )
  {
    v16 = v2->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v17 = (UFG::CharacterPhysicsComponent *)v2->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v16 & 0x8000u) == 0 )
      {
        if ( (v16 >> 13) & 1 )
          v18 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v2->vfptr,
                  UFG::CharacterPhysicsComponent::_TypeUID);
        else
          v18 = (v16 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)&v2->vfptr,
                                    UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                  (UFG::SimObject *)&v2->vfptr,
                                                                                  UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v2->vfptr,
                UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v17 = (UFG::CharacterPhysicsComponent *)v18;
    }
    if ( v17 )
    {
      UFG::CharacterPhysicsComponent::SetCollisionModel(v17, CP_WALK);
      UFG::CharacterPhysicsComponent::PlaceOnGroundAfterNIS(v17);
    }
  }
  v19 = v2->m_Flags;
  if ( (v19 >> 14) & 1 )
  {
    v20 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
  }
  else if ( (v19 & 0x8000u) == 0 )
  {
    if ( (v19 >> 13) & 1 )
    {
      v20 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v2);
    }
    else if ( (v19 >> 12) & 1 )
    {
      v20 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v2->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      v20 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v2->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    v20 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
  }
  if ( v20 )
    v20->mUpdatedFromNIS = 0;
  if ( v1->mResetActorOnEnd )
  {
    if ( v20 )
    {
      v21 = v20->mCreature;
      if ( v21 )
        Creature::KillBlendTree(v21);
    }
    UFG::SimObjectUtility::ResetState((UFG::SimObject *)&v2->vfptr, 0, 0);
  }
  v22 = v2->m_Flags;
  if ( (v22 >> 14) & 1 )
  {
    v23 = v2->m_Components.p[28].m_pComponent;
  }
  else
  {
    if ( (v22 & 0x8000u) == 0 )
    {
      if ( (v22 >> 13) & 1 )
      {
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v2->vfptr,
                UFG::WorldContextComponent::_TypeUID);
      }
      else if ( (v22 >> 12) & 1 )
      {
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v2->vfptr,
                UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v24 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::WorldContextComponent::_TypeUID);
      }
    }
    else
    {
      v24 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::WorldContextComponent::_TypeUID);
    }
    v23 = v24;
  }
  if ( v23 )
    ((void (*)(void))v23->vfptr[9].__vecDelDtor)();
  v25 = v2->m_Flags;
  if ( (v25 >> 14) & 1 )
  {
    v26 = v2->m_Components.p[13].m_pComponent;
  }
  else if ( (v25 & 0x8000u) == 0 )
  {
    if ( (v25 >> 13) & 1 )
    {
      v27 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::AnimationLODComponent::_TypeUID);
    }
    else if ( (v25 >> 12) & 1 )
    {
      v27 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v2->vfptr,
              UFG::AnimationLODComponent::_TypeUID);
    }
    else
    {
      v27 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AnimationLODComponent::_TypeUID);
    }
    v26 = v27;
  }
  else
  {
    v26 = v2->m_Components.p[13].m_pComponent;
  }
  if ( v26 )
    ((void (*)(void))v26->vfptr[9].__vecDelDtor)();
  v28 = v2->m_Flags;
  if ( (v28 >> 14) & 1 )
  {
    v29 = (UFG::FacialActionTreeComponent *)v2->m_Components.p[31].m_pComponent;
  }
  else
  {
    if ( (v28 & 0x8000u) != 0 || (v28 >> 13) & 1 )
      goto LABEL_108;
    if ( (v28 >> 12) & 1 )
      v29 = (UFG::FacialActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v2->vfptr,
                                                UFG::FacialActionTreeComponent::_TypeUID);
    else
      v29 = (UFG::FacialActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v2->vfptr,
                                                UFG::FacialActionTreeComponent::_TypeUID);
  }
  if ( v29 )
    UFG::FacialActionTreeComponent::Enable(v29);
LABEL_108:
  v30 = v2->m_Flags;
  if ( !((v30 >> 14) & 1) )
  {
    if ( (v30 & 0x8000u) != 0 )
    {
      v31 = v2->m_Components.p[34].m_pComponent;
      goto LABEL_115;
    }
    if ( !((v30 >> 13) & 1) )
    {
      if ( (v30 >> 12) & 1 )
        v31 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v2->vfptr,
                UFG::PhysicsMoverInterface::_TypeUID);
      else
        v31 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_115:
      if ( v31 )
        LODWORD(v31[14].vfptr) &= 0xFFFFFFF7;
      goto LABEL_117;
    }
  }
LABEL_117:
  v32 = v2->m_Flags;
  if ( (v32 >> 14) & 1 )
  {
    v33 = v2->m_Components.p[17].m_pComponent;
  }
  else if ( (v32 & 0x8000u) == 0 )
  {
    if ( (v32 >> 13) & 1 )
    {
      v33 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::CopUnitComponent::_TypeUID);
    }
    else if ( (v32 >> 12) & 1 )
    {
      v33 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::CopUnitComponent::_TypeUID);
    }
    else
    {
      v33 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CopUnitComponent::_TypeUID);
    }
  }
  else
  {
    v33 = v2->m_Components.p[17].m_pComponent;
  }
  if ( v33 )
    LOBYTE(v33[7].m_Flags) |= 2u;
  NISActorNode::RestoreEquippedItems(v1, (UFG::SimObject *)&v2->vfptr);
  if ( v1->mDeleteActorOnEnd )
    UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v2->vfptr);
}

// File Line: 518
// RVA: 0x3E5040
void __fastcall NISActorNode::SetPlayTime(NISActorNode *this, float timeAbsolute, bool fixedTimeMode)
{
  bool v3; // si
  UFG::SimObjectGame *v4; // rax
  UFG::SimObjectCVBase *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::CharacterAnimationComponent *v9; // rax
  UFG::CharacterAnimationComponent *v10; // rbx
  Creature *v11; // rdi

  v3 = fixedTimeMode;
  if ( this->mIsPlaying )
  {
    v4 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
    v5 = (UFG::SimObjectCVBase *)v4;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v4->m_Components.p[7].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = v4->m_Components.p[6].m_pComponent;
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::ActionTreeComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::ActionTreeComponent::_TypeUID);
        }
      }
      else
      {
        v7 = v4->m_Components.p[7].m_pComponent;
      }
      if ( v7 )
        TimePlotPoint::SetTimeValue((UFG::TimeOfDayManager *)&v7[3], timeAbsolute);
      v8 = v5->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
        }
        else if ( (v8 >> 12) & 1 )
        {
          v9 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v5->vfptr,
                                                     UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v9 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v5->vfptr,
                                                     UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
      }
      v10 = v9;
      if ( v9 )
      {
        v11 = v9->mCreature;
        if ( v11 )
        {
          Creature::SetPoseOnFrameBoundaries(v9->mCreature, v3);
          Creature::SetBlendTreePlayTime(v11, timeAbsolute);
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
  NISActorNode *v2; // rbx
  UFG::SimObjectGame *v3; // rax
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  bool v7; // al

  v2 = this;
  this->mIsPlaying = 0;
  v3 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[7].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = v3->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v4 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v5 = v6;
      }
    }
    else
    {
      v5 = v3->m_Components.p[7].m_pComponent;
    }
    if ( v5 )
    {
      v7 = v5[3].m_SafePointerList.mNode.mNext == (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v2;
      v2->mIsPlaying = v7;
      if ( v7 )
        ((void (*)(void))v5->vfptr[15].__vecDelDtor)();
    }
  }
}

// File Line: 572
// RVA: 0x3E7620
void __fastcall NISActorNode::UpdateTransforms(NISActorNode *this, float deltaTime)
{
  NISActorNode *v2; // rdi
  UFG::SimObjectCVBase *v3; // rax
  UFG::SimObjectGame *v4; // rbx
  unsigned __int16 v5; // cx
  UFG::CharacterAnimationComponent *v6; // rax
  UFG::CharacterAnimationComponent *v7; // rsi
  Creature *v8; // rcx
  hkQsTransformf *v9; // rax
  float v10; // xmm8_4
  __int128 v11; // xmm9
  float v12; // xmm10_4
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  hkQsTransformf *v15; // rax
  unsigned __int16 v16; // cx
  UFG::CompositeDrawableComponent *v17; // rax
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-A8h]
  UFG::qMatrix44 d; // [rsp+30h] [rbp-98h]

  v2 = this;
  if ( this->mIsPlaying )
  {
    v3 = (UFG::SimObjectCVBase *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mActorID);
    v4 = (UFG::SimObjectGame *)&v3->vfptr;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
        else
          v6 = (UFG::CharacterAnimationComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v3->vfptr,
                                                                       UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
      }
      v7 = v6;
      if ( v6 )
      {
        v8 = v6->mCreature;
        if ( v8 )
        {
          v9 = SkeletalPose::GetRoot(&v8->mPose);
          v10 = v9->m_translation.m_quad.m128_f32[0];
          v11 = v9->m_translation.m_quad.m128_u32[1];
          v12 = v9->m_translation.m_quad.m128_f32[2];
          Creature::GetTranslation(v7->mCreature, &result, 1);
          if ( v2->mCachedPositions && deltaTime > 0.0 )
          {
            v14 = (__m128)LODWORD(result.y);
            v13 = (__m128)v11;
            v14.m128_f32[0] = result.y - v2->mCachedHipsPosition.y;
            v13.m128_f32[0] = (float)((float)((float)(*(float *)&v11 - v2->mCachedRootPosition.y)
                                            * (float)(*(float *)&v11 - v2->mCachedRootPosition.y))
                                    + (float)((float)(v10 - v2->mCachedRootPosition.x)
                                            * (float)(v10 - v2->mCachedRootPosition.x)))
                            + (float)((float)(v12 - v2->mCachedRootPosition.z) * (float)(v12 - v2->mCachedRootPosition.z));
            if ( (float)(COERCE_FLOAT(_mm_sqrt_ps(v13)) * (float)(1.0 / deltaTime)) <= gMetersPerSecondBeforeTeleportCalled )
            {
              v14.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0])
                                      + (float)((float)(result.x - v2->mCachedHipsPosition.x)
                                              * (float)(result.x - v2->mCachedHipsPosition.x)))
                              + (float)((float)(result.z - v2->mCachedHipsPosition.z)
                                      * (float)(result.z - v2->mCachedHipsPosition.z));
              if ( (float)(COERCE_FLOAT(_mm_sqrt_ps(v14)) * (float)(1.0 / deltaTime)) > gMetersPerSecondBeforeClothReset )
              {
                v16 = v4->m_Flags;
                if ( (v16 >> 14) & 1 )
                {
                  v17 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
                }
                else if ( (v16 & 0x8000u) == 0 )
                {
                  if ( (v16 >> 13) & 1 )
                  {
                    v17 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[9].m_pComponent;
                  }
                  else if ( (v16 >> 12) & 1 )
                  {
                    v17 = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v4,
                                                               UFG::CompositeDrawableComponent::_TypeUID);
                  }
                  else
                  {
                    v17 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v4->vfptr,
                                                               UFG::CompositeDrawableComponent::_TypeUID);
                  }
                }
                else
                {
                  v17 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
                }
                if ( v17 )
                  UFG::CompositeDrawableComponent::TeleportEventHandler(v17, 0i64);
              }
            }
            else
            {
              v15 = SkeletalPose::GetRoot(&v7->mCreature->mPose);
              hkQsTransformf::get4x4ColumnMajor(v15, &d.v0.x);
              UFG::SimObjectUtility::Teleport((UFG::SimObject *)&v4->vfptr, &d);
            }
          }
          v18 = result.x;
          v19 = result.y;
          v2->mCachedPositions = 1;
          v2->mCachedRootPosition.x = v10;
          LODWORD(v2->mCachedRootPosition.y) = v11;
          v2->mCachedRootPosition.z = v12;
          v2->mCachedHipsPosition.x = v18;
          v20 = result.z;
          v2->mCachedHipsPosition.y = v19;
          v2->mCachedHipsPosition.z = v20;
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
void __fastcall NISActorNode::SaveEquippedItems(NISActorNode *this, UFG::SimObject *simActorObject)
{
  NISActorNode *v2; // rbp
  unsigned __int16 v3; // cx
  UFG::SimObjectGame *v4; // rbx
  UFG::SimComponent *v5; // rsi
  UFG::SimComponent *v6; // rax
  unsigned __int16 v7; // cx
  UFG::InventoryComponent *v8; // r14
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // rbx
  UFG::SimObject *v16; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v20; // rdi
  UFG::SimObject *v21; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::SimObject *v25; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v26; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::SimObject *v30; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  unsigned int v35; // eax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v36; // r8
  UFG::SimObject *v37; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v40; // rax
  UFG::SimObject *v41; // rcx
  UFG::SimObject *v42; // rcx
  UFG::SimObject *v43; // r8
  unsigned __int16 v44; // cx
  UFG::SimComponent *v45; // rax
  bool v46; // zf
  UFG::SimObjectGame *v47; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v48; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v49; // rax
  UFG::SimObject *v50; // rcx
  UFG::SimObject *v51; // r8
  unsigned __int16 v52; // cx
  UFG::SimComponent *v53; // rax
  UFG::SimObjectGame *v54; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v55; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v56; // rax
  UFG::SimObject *v57; // rcx
  UFG::SimObject *v58; // rcx
  UFG::SimObject *v59; // rcx

  if ( simActorObject )
  {
    v2 = this;
    v3 = simActorObject->m_Flags;
    v4 = (UFG::SimObjectGame *)simActorObject;
    if ( (simActorObject->m_Flags >> 14) & 1 )
    {
      v5 = simActorObject->m_Components.p[20].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)simActorObject,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)simActorObject,
                                UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                 simActorObject,
                                                                                 UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = simActorObject->m_Components.p[20].m_pComponent;
    }
    v7 = v4->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::InventoryComponent *)v4->m_Components.p[39].m_pComponent;
    }
    else
    {
      if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID);
        else
          v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::InventoryComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID);
      }
      v8 = (UFG::InventoryComponent *)v9;
    }
    if ( v5 && v8 )
    {
      v10 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(0)
                                                    + *(_QWORD *)&v5[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v5[1].m_TypeUID
                               + 40);
      v11 = &v2->mRightHandEquipSlot;
      if ( v2->mRightHandEquipSlot.m_pPointer )
      {
        v12 = v11->mPrev;
        v13 = v2->mRightHandEquipSlot.mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
        v2->mRightHandEquipSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mRightHandEquipSlot.mPrev;
      }
      v2->mRightHandEquipSlot.m_pPointer = v10;
      if ( v10 )
      {
        v14 = v10->m_SafePointerList.mNode.mPrev;
        v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
        v11->mPrev = v14;
        v2->mRightHandEquipSlot.mNext = &v10->m_SafePointerList.mNode;
        v10->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      }
      v15 = &v2->mLeftHandEquipSlot;
      v16 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_LEFT_HAND)
                                                    + *(_QWORD *)&v5[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v5[1].m_TypeUID
                               + 40);
      if ( v2->mLeftHandEquipSlot.m_pPointer )
      {
        v17 = v15->mPrev;
        v18 = v2->mLeftHandEquipSlot.mNext;
        v17->mNext = v18;
        v18->mPrev = v17;
        v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
        v2->mLeftHandEquipSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mLeftHandEquipSlot.mPrev;
      }
      v2->mLeftHandEquipSlot.m_pPointer = v16;
      if ( v16 )
      {
        v19 = v16->m_SafePointerList.mNode.mPrev;
        v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
        v15->mPrev = v19;
        v2->mLeftHandEquipSlot.mNext = &v16->m_SafePointerList.mNode;
        v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      }
      v20 = &v2->mHatEquipSlot;
      v21 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_HAT)
                                                    + *(_QWORD *)&v5[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v5[1].m_TypeUID
                               + 40);
      if ( v2->mHatEquipSlot.m_pPointer )
      {
        v22 = v20->mPrev;
        v23 = v2->mHatEquipSlot.mNext;
        v22->mNext = v23;
        v23->mPrev = v22;
        v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v2->mHatEquipSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mHatEquipSlot.mPrev;
      }
      v2->mHatEquipSlot.m_pPointer = v21;
      if ( v21 )
      {
        v24 = v21->m_SafePointerList.mNode.mPrev;
        v24->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v20->mPrev = v24;
        v2->mHatEquipSlot.mNext = &v21->m_SafePointerList.mNode;
        v21->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
      }
      v25 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_GLASSES)
                                                    + *(_QWORD *)&v5[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v5[1].m_TypeUID
                               + 40);
      v26 = &v2->mGlassesEquipSlot;
      if ( v2->mGlassesEquipSlot.m_pPointer )
      {
        v27 = v26->mPrev;
        v28 = v2->mGlassesEquipSlot.mNext;
        v27->mNext = v28;
        v28->mPrev = v27;
        v26->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
        v2->mGlassesEquipSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mGlassesEquipSlot.mPrev;
      }
      v2->mGlassesEquipSlot.m_pPointer = v25;
      if ( v25 )
      {
        v29 = v25->m_SafePointerList.mNode.mPrev;
        v29->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
        v26->mPrev = v29;
        v2->mGlassesEquipSlot.mNext = &v25->m_SafePointerList.mNode;
        v25->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v26->mPrev;
      }
      v30 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_STOWED_1H)
                                                    + *(_QWORD *)&v5[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v5[1].m_TypeUID
                               + 40);
      v31 = &v2->mStowed1HSlot;
      if ( v2->mStowed1HSlot.m_pPointer )
      {
        v32 = v31->mPrev;
        v33 = v2->mStowed1HSlot.mNext;
        v32->mNext = v33;
        v33->mPrev = v32;
        v31->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v31->mPrev;
        v2->mStowed1HSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mStowed1HSlot.mPrev;
      }
      v2->mStowed1HSlot.m_pPointer = v30;
      if ( v30 )
      {
        v34 = v30->m_SafePointerList.mNode.mPrev;
        v34->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v31->mPrev;
        v31->mPrev = v34;
        v2->mStowed1HSlot.mNext = &v30->m_SafePointerList.mNode;
        v30->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v31->mPrev;
      }
      v35 = UFG::InventoryComponent::GetSlotTarget(eINVENTORY_EQUIP_SLOT_STOWED_2H);
      v36 = &v2->mStowed2HSlot;
      v37 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(v35 + *(_QWORD *)&v5[1].m_Flags + 8i64)
                               + *(_QWORD *)&v5[1].m_TypeUID
                               + 40);
      if ( v2->mStowed2HSlot.m_pPointer )
      {
        v38 = v36->mPrev;
        v39 = v2->mStowed2HSlot.mNext;
        v38->mNext = v39;
        v39->mPrev = v38;
        v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v36->mPrev;
        v2->mStowed2HSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mStowed2HSlot.mPrev;
      }
      v2->mStowed2HSlot.m_pPointer = v37;
      if ( v37 )
      {
        v40 = v37->m_SafePointerList.mNode.mPrev;
        v40->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v36->mPrev;
        v36->mPrev = v40;
        v2->mStowed2HSlot.mNext = &v37->m_SafePointerList.mNode;
        v37->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v36->mPrev;
      }
      UFG::InventoryComponent::UnEquip(v8, 0, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_LEFT_HAND, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_HAT, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_GLASSES, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_STOWED_1H, 0);
      UFG::InventoryComponent::UnEquip(v8, eINVENTORY_EQUIP_SLOT_STOWED_2H, 0);
      v41 = v2->mRightHandEquipSlot.m_pPointer;
      if ( v41 )
        UFG::SimObject::Suspend(v41);
      v42 = v2->mLeftHandEquipSlot.m_pPointer;
      if ( v42 )
      {
        UFG::SimObject::Suspend(v42);
        v43 = v2->mLeftHandEquipSlot.m_pPointer;
        if ( v43 )
        {
          v44 = v43->m_Flags;
          if ( !((v44 >> 14) & 1) && (v44 & 0x8000u) == 0 )
          {
            if ( (v44 >> 13) & 1 )
            {
              v45 = v43->m_Components.p[11].m_pComponent;
            }
            else
            {
              v46 = ((v44 >> 12) & 1) == 0;
              v47 = (UFG::SimObjectGame *)v2->mLeftHandEquipSlot.m_pPointer;
              v45 = v46 ? UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v47->vfptr,
                            UFG::InventoryItemComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v47,
                                                                       UFG::InventoryItemComponent::_TypeUID);
            }
            if ( v45 && LODWORD(v45[1].m_pSimObject) == 106 )
            {
              UFG::Simulation::DestroySimObject(&UFG::gSim, v2->mLeftHandEquipSlot.m_pPointer);
              if ( v2->mLeftHandEquipSlot.m_pPointer )
              {
                v48 = v15->mPrev;
                v49 = v2->mLeftHandEquipSlot.mNext;
                v48->mNext = v49;
                v49->mPrev = v48;
                v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
                v2->mLeftHandEquipSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mLeftHandEquipSlot.mPrev;
              }
              v2->mLeftHandEquipSlot.m_pPointer = 0i64;
            }
          }
        }
      }
      v50 = v2->mHatEquipSlot.m_pPointer;
      if ( v50 )
      {
        UFG::SimObject::Suspend(v50);
        v51 = v2->mHatEquipSlot.m_pPointer;
        if ( v51 )
        {
          v52 = v51->m_Flags;
          if ( !((v52 >> 14) & 1) && (v52 & 0x8000u) == 0 )
          {
            if ( (v52 >> 13) & 1 )
            {
              v53 = v51->m_Components.p[11].m_pComponent;
            }
            else
            {
              v46 = ((v52 >> 12) & 1) == 0;
              v54 = (UFG::SimObjectGame *)v2->mHatEquipSlot.m_pPointer;
              v53 = v46 ? UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v54->vfptr,
                            UFG::InventoryItemComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v54,
                                                                       UFG::InventoryItemComponent::_TypeUID);
            }
            if ( v53 && LODWORD(v53[1].m_pSimObject) == 111 )
            {
              UFG::Simulation::DestroySimObject(&UFG::gSim, v2->mHatEquipSlot.m_pPointer);
              if ( v2->mHatEquipSlot.m_pPointer )
              {
                v55 = v20->mPrev;
                v56 = v2->mHatEquipSlot.mNext;
                v55->mNext = v56;
                v56->mPrev = v55;
                v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
                v2->mHatEquipSlot.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mHatEquipSlot.mPrev;
              }
              v2->mHatEquipSlot.m_pPointer = 0i64;
            }
          }
        }
      }
      v57 = v2->mGlassesEquipSlot.m_pPointer;
      if ( v57 )
        UFG::SimObject::Suspend(v57);
      v58 = v2->mStowed1HSlot.m_pPointer;
      if ( v58 )
        UFG::SimObject::Suspend(v58);
      v59 = v2->mStowed2HSlot.m_pPointer;
      if ( v59 )
        UFG::SimObject::Suspend(v59);
    }
  }
}

// File Line: 710
// RVA: 0x3E48A0
void __fastcall NISActorNode::RestoreEquippedItems(NISActorNode *this, UFG::SimObject *simActorObject)
{
  NISActorNode *v2; // rbx
  unsigned __int16 v3; // cx
  UFG::InventoryComponent *v4; // rdi
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  UFG::SimObject *v7; // rcx
  UFG::SimObject *v8; // rcx
  UFG::SimObject *v9; // rcx
  UFG::SimObject *v10; // rcx
  UFG::SimObject *v11; // rcx

  if ( simActorObject )
  {
    v2 = this;
    v3 = simActorObject->m_Flags;
    if ( (simActorObject->m_Flags >> 14) & 1 )
    {
      v4 = (UFG::InventoryComponent *)simActorObject->m_Components.p[39].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)simActorObject,
                 UFG::InventoryComponent::_TypeUID);
        else
          v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  (UFG::SimObjectGame *)simActorObject,
                                  UFG::InventoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                         simActorObject,
                                                                         UFG::InventoryComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)simActorObject,
               UFG::InventoryComponent::_TypeUID);
      }
      v4 = (UFG::InventoryComponent *)v5;
    }
    if ( v4 )
    {
      v6 = v2->mRightHandEquipSlot.m_pPointer;
      if ( v6 )
      {
        UFG::SimObject::Restore(v6);
        UFG::InventoryComponent::Equip(v4, v2->mRightHandEquipSlot.m_pPointer, 1, 0);
      }
      v7 = v2->mLeftHandEquipSlot.m_pPointer;
      if ( v7 )
      {
        UFG::SimObject::Restore(v7);
        UFG::InventoryComponent::Equip(v4, v2->mLeftHandEquipSlot.m_pPointer, 1, eINVENTORY_EQUIP_SLOT_LEFT_HAND);
      }
      v8 = v2->mHatEquipSlot.m_pPointer;
      if ( v8 )
      {
        UFG::SimObject::Restore(v8);
        UFG::InventoryComponent::Equip(v4, v2->mHatEquipSlot.m_pPointer);
      }
      v9 = v2->mGlassesEquipSlot.m_pPointer;
      if ( v9 )
      {
        UFG::SimObject::Restore(v9);
        UFG::InventoryComponent::Equip(v4, v2->mGlassesEquipSlot.m_pPointer);
      }
      v10 = v2->mStowed1HSlot.m_pPointer;
      if ( v10 )
      {
        UFG::SimObject::Restore(v10);
        UFG::InventoryComponent::Equip(v4, v2->mStowed1HSlot.m_pPointer, 1, eINVENTORY_EQUIP_SLOT_STOWED_1H);
      }
      v11 = v2->mStowed2HSlot.m_pPointer;
      if ( v11 )
      {
        UFG::SimObject::Restore(v11);
        UFG::InventoryComponent::Equip(v4, v2->mStowed2HSlot.m_pPointer, 1, eINVENTORY_EQUIP_SLOT_STOWED_2H);
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
  return atexit(dynamic_atexit_destructor_for__gNISActorFactory__);
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
  NISNode *v1; // rdi
  char *v2; // rbx
  char *v3; // rax
  UFG::qOffset64<TrackGroup *> *v4; // rcx
  signed __int64 v5; // rax

  v1 = this;
  ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&NISNode::`vftable;
  v1->mIsPlaceHolder = 0;
  v1->mPlaceHolderMessage.mOffset = 1i64;
  BinString::Set(&v1->mPlaceHolderMessage, &customWorldMapCaption);
  *(_DWORD *)&v1->mCanSkip = 16843009;
  *(_DWORD *)&v1->mDisableHUD = 1;
  *(_DWORD *)&v1->mAllowLetterbox = 16842753;
  *(_QWORD *)&v1->mTimeBeforeCanSkip = 1065353216i64;
  v2 = 0i64;
  v1->mPostNISTOD = -1.0;
  v1->mTODTime = -1.0;
  v1->mWeatherWetness = -1.0;
  v1->mGI_Irradiance = 1.0;
  v1->mFadeOutDuration = -1.0;
  v1->mFadeInDuration = -1.0;
  v1->mWeatherType.mValue = 0;
  v1->mAnimationGroupName.mOffset = 1i64;
  BinString::Set(&v1->mAnimationGroupName, &customWorldMapCaption);
  v1->mFacialAnimGroupName.mOffset = 1i64;
  BinString::Set(&v1->mFacialAnimGroupName, &customWorldMapCaption);
  v1->mExtraFacialAnimGroupName.mOffset = 1i64;
  BinString::Set(&v1->mExtraFacialAnimGroupName, &customWorldMapCaption);
  v1->mPostNISMarkerName.mOffset = 1i64;
  BinString::Set(&v1->mPostNISMarkerName, &customWorldMapCaption);
  v1->mLightLayerDisableName.mOffset = 1i64;
  BinString::Set(&v1->mLightLayerDisableName, &customWorldMapCaption);
  v1->mTODEnvSetting.mOffset = 1i64;
  BinString::Set(&v1->mTODEnvSetting, &customWorldMapCaption);
  v1->mSoundbank.mOffset = 1i64;
  BinString::Set(&v1->mSoundbank, &customWorldMapCaption);
  v1->mNISName.mOffset = 1i64;
  BinString::Set(&v1->mNISName, &customWorldMapCaption);
  v1->mPrimaryCameraAnimationTrack = 0i64;
  v1->mLightGroupObject = 0i64;
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
  v4 = &v1->mTracksAction;
  if ( v3 )
    v5 = v3 - (char *)v4;
  else
    v5 = 0i64;
  v4->mOffset = v5;
  if ( v5 )
    v2 = (char *)v4 + v5;
  (*(void (__fastcall **)(char *, NISNode *))(*(_QWORD *)v2 + 64i64))(v2, v1);
  UFG::qMemSet(v1->m_audioTagId, 0, 0x10u);
  UFG::qMemSet(v1->m_audioTagUID, 0, 0x10u);
}

// File Line: 896
// RVA: 0x3E0D70
void __fastcall NISNode::~NISNode(NISNode *this)
{
  NISNode *v1; // rbx
  __int64 v2; // rax
  char *v3; // rcx
  NISLightGroup *v4; // rdi
  char *v5; // rcx
  char *v6; // rcx
  char *v7; // rcx
  char *v8; // rcx
  char *v9; // rcx
  char *v10; // rcx
  char *v11; // rcx
  char *v12; // rcx
  char *v13; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISNode::`vftable;
  v2 = this->mTracksAction.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mTracksAction + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)v3 + 8i64))(v3, 1i64);
  }
  v4 = v1->mLightGroupObject;
  if ( v4 )
  {
    NISLightGroup::~NISLightGroup(v1->mLightGroupObject);
    operator delete[](v4);
  }
  if ( !(~LOBYTE(v1->mNISName.mOffset) & 1) )
  {
    if ( v1->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)&v1->mNISName + (v1->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  if ( !(~LOBYTE(v1->mSoundbank.mOffset) & 1) )
  {
    if ( v1->mSoundbank.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v6 = (char *)&v1->mSoundbank + (v1->mSoundbank.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v6 != BinString::sEmptyString )
        operator delete[](v6);
    }
  }
  if ( !(~LOBYTE(v1->mTODEnvSetting.mOffset) & 1) )
  {
    if ( v1->mTODEnvSetting.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v7 = (char *)&v1->mTODEnvSetting + (v1->mTODEnvSetting.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 != BinString::sEmptyString )
        operator delete[](v7);
    }
  }
  if ( !(~LOBYTE(v1->mLightLayerDisableName.mOffset) & 1) )
  {
    if ( v1->mLightLayerDisableName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v8 = (char *)&v1->mLightLayerDisableName + (v1->mLightLayerDisableName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v8 != BinString::sEmptyString )
        operator delete[](v8);
    }
  }
  if ( !(~LOBYTE(v1->mPostNISMarkerName.mOffset) & 1) )
  {
    if ( v1->mPostNISMarkerName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v9 = (char *)&v1->mPostNISMarkerName + (v1->mPostNISMarkerName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v9 != BinString::sEmptyString )
        operator delete[](v9);
    }
  }
  if ( !(~LOBYTE(v1->mExtraFacialAnimGroupName.mOffset) & 1) )
  {
    if ( v1->mExtraFacialAnimGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v10 = (char *)&v1->mExtraFacialAnimGroupName + (v1->mExtraFacialAnimGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v10 != BinString::sEmptyString )
        operator delete[](v10);
    }
  }
  if ( !(~LOBYTE(v1->mFacialAnimGroupName.mOffset) & 1) )
  {
    if ( v1->mFacialAnimGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v11 = (char *)&v1->mFacialAnimGroupName + (v1->mFacialAnimGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v11 != BinString::sEmptyString )
        operator delete[](v11);
    }
  }
  if ( !(~LOBYTE(v1->mAnimationGroupName.mOffset) & 1) )
  {
    if ( v1->mAnimationGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v12 = (char *)&v1->mAnimationGroupName + (v1->mAnimationGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v12 != BinString::sEmptyString )
        operator delete[](v12);
    }
  }
  if ( !(~LOBYTE(v1->mPlaceHolderMessage.mOffset) & 1) )
  {
    if ( v1->mPlaceHolderMessage.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v13 = (char *)&v1->mPlaceHolderMessage + (v1->mPlaceHolderMessage.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v13 != BinString::sEmptyString )
        operator delete[](v13);
    }
  }
  ActionNodeImplementation::~ActionNodeImplementation((ActionNodeImplementation *)&v1->vfptr);
}

// File Line: 902
// RVA: 0x3E61E0
void __fastcall NISNode::Trim(NISNode *this, bool force)
{
  NISNode *v2; // rbx
  __int64 v3; // rax
  _DWORD *v4; // rcx

  v2 = this;
  ActionNodeImplementation::Trim((ActionNodeImplementation *)&this->vfptr, force);
  v3 = v2->mTracksAction.mOffset;
  if ( v3 )
  {
    v4 = (_DWORD *)((char *)&v2->mTracksAction + v3);
    if ( v4 )
    {
      if ( !(v4[4] & 0x7FFFFFFF) )
      {
        (*(void (__fastcall **)(_DWORD *, signed __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
        v2->mTracksAction.mOffset = 0i64;
      }
    }
  }
}

// File Line: 920
// RVA: 0x3E4FB0
void __fastcall NISNode::Serialize(NISNode *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  IActionTreeSerializer *v3; // r8
  Expression::IMemberMap *v4; // rdx

  v2 = this->mTracksAction.mOffset;
  v3 = serializer;
  if ( v2 )
  {
    v4 = (Expression::IMemberMap *)((char *)&this->mTracksAction + v2);
    if ( v4 )
      IActionTreeSerializer::PushObjectToSerialize(v3, v4);
  }
}

// File Line: 989
// RVA: 0x3E47B0
void __fastcall NISNode::ResolveReferences(NISNode *this)
{
  NISNode *v1; // rdi
  __int64 v2; // rax
  signed __int64 v3; // rcx
  signed __int64 v4; // r14
  unsigned int i; // ebx
  __int64 v6; // rax
  signed __int64 v7; // rcx
  char *v8; // rcx
  CameraAnimationTrack *v9; // rsi

  v1 = this;
  this->mPrimaryCameraAnimationTrack = 0i64;
  ActionNode::ResolveReferences((ActionNode *)&this->vfptr);
  v2 = v1->mTracksAction.mOffset;
  if ( v2 )
  {
    v3 = (signed __int64)&v1->mTracksAction + v2;
    if ( v3 )
    {
      v4 = v3 + *(_QWORD *)(v3 + 24) + 24i64;
      for ( i = 0; ; ++i )
      {
        v6 = v1->mTracksAction.mOffset;
        v7 = (signed __int64)(v6 ? (UFG::qOffset64<TrackGroup *> *)((char *)&v1->mTracksAction + v6) : 0i64);
        if ( i >= (*(_DWORD *)(v7 + 16) & 0x7FFFFFFFu) )
          break;
        v8 = (char *)(v4 + 8i64 * i);
        v9 = (CameraAnimationTrack *)&v8[*(_QWORD *)v8];
        v9->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v8[*(_QWORD *)v8], (unsigned int)v1);
        if ( CameraAnimationTrack::sClassNameUID == v9->vfptr->GetClassNameUID((Expression::IMemberMap *)&v9->vfptr)
          && !v1->mPrimaryCameraAnimationTrack )
        {
          v1->mPrimaryCameraAnimationTrack = v9;
        }
      }
    }
  }
}

// File Line: 1100
// RVA: 0x3E5570
void __fastcall NISNode::SetPlayTime(NISNode *this, float timeAbsolute, bool fixedTimeMode)
{
  bool v3; // bp
  NISNode *v4; // rsi
  UFG::SimObject *v5; // rcx
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rbx
  Creature *v8; // rdi
  NISLightGroup *v9; // rax
  UFG::SimObject *v10; // rcx
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rbx
  Creature *v13; // rdi
  __int64 v14; // rax
  _DWORD *v15; // rdi
  __int64 v16; // rbx
  signed __int64 v17; // rsi

  v3 = fixedTimeMode;
  v4 = this;
  v5 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v5 )
  {
    v6 = UFG::SimObject::GetComponentOfType(v5, UFG::CameraAnimationComponent::_TypeUID);
    v7 = v6;
    if ( v6 )
    {
      v8 = *(Creature **)&v6[2].m_TypeUID;
      if ( v8 )
      {
        Creature::SetPoseOnFrameBoundaries(*(Creature **)&v6[2].m_TypeUID, v3);
        Creature::SetBlendTreePlayTime(v8, timeAbsolute);
      }
      ((void (__fastcall *)(UFG::SimComponent *))v7->vfptr[16].__vecDelDtor)(v7);
    }
  }
  v9 = v4->mLightGroupObject;
  if ( v9 )
  {
    v10 = v9->mSimObject.m_pPointer;
    if ( v10 )
    {
      v11 = UFG::SimObject::GetComponentOfType(v10, UFG::LightGroupAnimationComponent::_TypeUID);
      v12 = v11;
      if ( v11 )
      {
        v13 = *(Creature **)&v11[2].m_TypeUID;
        if ( v13 )
        {
          Creature::SetPoseOnFrameBoundaries(*(Creature **)&v11[2].m_TypeUID, v3);
          Creature::SetBlendTreePlayTime(v13, timeAbsolute);
          ((void (__fastcall *)(UFG::SimComponent *))v12->vfptr[16].__vecDelDtor)(v12);
        }
      }
    }
  }
  v14 = ((__int64 (__fastcall *)(NISNode *))v4->vfptr[1].GetResourcePath)(v4);
  v15 = (_DWORD *)v14;
  if ( v14 )
  {
    v16 = 0i64;
    v17 = v14 + *(_QWORD *)(v14 + 8) + 8i64;
    if ( *(_DWORD *)v14 & 0x7FFFFFFF )
    {
      do
      {
        NISActorNode::SetPlayTime((NISActorNode *)(*(_QWORD *)(v17 + 8 * v16) + v17 + 8 * v16), timeAbsolute, v3);
        v16 = (unsigned int)(v16 + 1);
      }
      while ( (unsigned int)v16 < (*v15 & 0x7FFFFFFFu) );
    }
  }
}

