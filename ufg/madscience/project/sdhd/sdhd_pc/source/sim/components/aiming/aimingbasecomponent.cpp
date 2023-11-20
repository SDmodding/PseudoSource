// File Line: 75
// RVA: 0x1543D20
__int64 dynamic_initializer_for__UFG::AimingBaseComponent::s_AimingBaseComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AimingBaseComponent::s_AimingBaseComponentList__);
}

// File Line: 76
// RVA: 0x1542F20
__int64 dynamic_initializer_for__UFG::AimingBaseComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::AimingBaseComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::AimingBaseComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::AimingBaseComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::AimingBaseComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 101
// RVA: 0x515510
void __fastcall UFG::AimingBaseComponent::AimingBaseComponent(UFG::AimingBaseComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  bool v4; // di
  UFG::AimingBaseComponent *v5; // rsi
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v6; // rbx
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::qList<AccuracyModifierTask,AimingSystemAccuracyModifierList,0,0> *v17; // ST28_8
  UFG::qList<AimingSoftLockDisableTask,AimingSoftLockDisableList,0,0> *v18; // ST28_8
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v19; // rax

  v4 = startSuspended;
  v5 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  v6 = (UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingBaseComponent::`vftable{for `UFG::SimComponent};
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingBaseComponent::`vftable{for `UFG::UpdateInterface};
  v5->m_fAimPositionDistance = 1.0;
  v5->m_fAimTransitionRadPerS = 3.0;
  v5->m_fAimTransitionMultiplier = 1.0;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  v5->m_vAimOriginPosition.x = UFG::qVector3::msZero.x;
  v5->m_vAimOriginPosition.y = v7;
  v5->m_vAimOriginPosition.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v5->m_vAimIntentionTargetPosition.x = UFG::qVector3::msZero.x;
  v5->m_vAimIntentionTargetPosition.y = v9;
  v5->m_vAimIntentionTargetPosition.z = v10;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  v5->m_vAimPosition.x = UFG::qVector3::msZero.x;
  v5->m_vAimPosition.y = v11;
  v5->m_vAimPosition.z = v12;
  v13 = UFG::qVector3::msAxisX.y;
  v14 = UFG::qVector3::msAxisX.z;
  v5->m_vAimIntention.x = UFG::qVector3::msAxisX.x;
  v5->m_vAimIntention.y = v13;
  v5->m_vAimIntention.z = v14;
  v15 = UFG::qVector3::msAxisX.y;
  v16 = UFG::qVector3::msAxisX.z;
  v5->m_vAimDirectionLS.x = UFG::qVector3::msAxisX.x;
  v5->m_vAimDirectionLS.y = v15;
  v5->m_vAimDirectionLS.z = v16;
  v5->m_Accuracy.m_fAccuracyOverride = -1.0;
  v5->m_Accuracy.m_bEnsureMiss = 0;
  *(_QWORD *)&v5->m_Accuracy.m_fAccuracyUnclamped = 0i64;
  *(_QWORD *)&v5->m_Accuracy.m_fAccuracyMaximum = 1065353216i64;
  v17 = &v5->m_AccuracyModifierTaskList;
  v17->mNode.mPrev = &v17->mNode;
  v17->mNode.mNext = &v17->mNode;
  v18 = &v5->m_AimingSoftLockDisableList;
  v18->mNode.mPrev = &v18->mNode;
  v18->mNode.mNext = &v18->mNode;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v5->m_TransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>(&v5->m_pTargetingSystemPedBaseComponent);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v5->m_CharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>(&v5->m_CharacterOccupantComponent);
  v19 = UFG::AimingBaseComponent::s_AimingBaseComponentList.mNode.mPrev;
  UFG::AimingBaseComponent::s_AimingBaseComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *)&v5->mPrev;
  v6->mPrev = v19;
  v5->mNext = (UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *)&UFG::AimingBaseComponent::s_AimingBaseComponentList;
  UFG::AimingBaseComponent::s_AimingBaseComponentList.mNode.mPrev = (UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::AimingBaseComponent::_AimingBaseComponentTypeUID,
    "AimingBaseComponent");
  if ( v4 )
    v5->m_Flags |= 2u;
}

// File Line: 128
// RVA: 0x51A860
void __fastcall UFG::AimingBaseComponent::~AimingBaseComponent(UFG::AimingBaseComponent *this)
{
  UFG::AimingBaseComponent *v1; // rdi
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v2; // rbx
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v3; // rcx
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v4; // rax
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v5; // rcx
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingBaseComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingBaseComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::AimingBaseComponent::s_AimingBaseComponentpCurrentIterator )
    UFG::AimingBaseComponent::s_AimingBaseComponentpCurrentIterator = (UFG::AimingBaseComponent *)&this->mPrev[-5].mNext;
  v2 = (UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_CharacterOccupantComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_CharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTargetingSystemPedBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->m_TransformNodeComponent);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&v1->m_AimingSoftLockDisableList);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&v1->m_AccuracyModifierTaskList);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 135
// RVA: 0x53CDB0
void __fastcall UFG::AimingBaseComponent::OnAttach(UFG::AimingBaseComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *v2; // rbp
  UFG::AimingBaseComponent *v3; // rsi
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *v4; // rcx
  UFG::SimComponent *v5; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v10; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *v15; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  signed int v20; // edx
  __int64 v21; // rcx
  UFG::SimObject *v22; // r8
  unsigned __int16 v23; // cx
  unsigned int v24; // ecx
  unsigned int v25; // er9
  UFG::SimComponentHolder *v26; // rbx
  UFG::allocator::free_link *v27; // [rsp+40h] [rbp+8h]

  v2 = pObject;
  v3 = this;
  v4 = &this->m_pTargetingSystemPedBaseComponent;
  v5 = 0i64;
  if ( v4->m_pSimComponent )
  {
    v6 = v4->mPrev;
    v7 = v4->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v4->m_pSimComponent = 0i64;
LABEL_7:
    v4->m_pSimObject = 0i64;
    v4->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v4->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v4->mNext != v4) )
  {
    v8 = v4->mPrev;
    v9 = v4->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v4->m_Changed = 1;
  v4->m_pSimObject = v2;
  v4->m_TypeUID = UFG::TargetingSystemPedBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::BindInternal<UFG::SimObject>(v4, v2);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&v3->m_TransformNodeComponent, v2);
  v10 = &v3->m_CharacterAnimationComponent;
  if ( v3->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v11 = v10->mPrev;
    v12 = v3->m_CharacterAnimationComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v3->m_CharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_14:
    v3->m_CharacterAnimationComponent.m_pSimObject = 0i64;
    v3->m_CharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_CharacterAnimationComponent.mPrev;
    v10->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v10->mPrev;
    goto LABEL_15;
  }
  if ( v3->m_CharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v10->mPrev != v10
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->m_CharacterAnimationComponent.mNext != &v3->m_CharacterAnimationComponent) )
  {
    v13 = v10->mPrev;
    v14 = v3->m_CharacterAnimationComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_14;
  }
LABEL_15:
  v3->m_CharacterAnimationComponent.m_Changed = 1;
  v3->m_CharacterAnimationComponent.m_pSimObject = v2;
  v3->m_CharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_CharacterAnimationComponent,
    v2);
  v15 = &v3->m_CharacterOccupantComponent;
  if ( v3->m_CharacterOccupantComponent.m_pSimComponent )
  {
    v16 = v15->mPrev;
    v17 = v3->m_CharacterOccupantComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v3->m_CharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_21:
    v3->m_CharacterOccupantComponent.m_pSimObject = 0i64;
    v3->m_CharacterOccupantComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_CharacterOccupantComponent.mPrev;
    v15->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v15->mPrev;
    goto LABEL_22;
  }
  if ( v3->m_CharacterOccupantComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v15->mPrev != v15
     || (UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v3->m_CharacterOccupantComponent.mNext != &v3->m_CharacterOccupantComponent) )
  {
    v18 = v15->mPrev;
    v19 = v3->m_CharacterOccupantComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_21;
  }
LABEL_22:
  v3->m_CharacterOccupantComponent.m_Changed = 1;
  v3->m_CharacterOccupantComponent.m_pSimObject = v2;
  v3->m_CharacterOccupantComponent.m_TypeUID = UFG::CharacterOccupantComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_CharacterOccupantComponent,
    v2);
  v20 = -1;
  v3->m_iAimOriginBoneID = -1;
  if ( v3->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v21 = *(_QWORD *)&v3->m_CharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
    if ( v21 )
    {
      if ( *(_QWORD *)(v21 + 440) )
        v20 = Skeleton::GetBoneID(
                *(Skeleton **)(v21 + 480),
                UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_BoneUIDAimOrigin.mUID);
      v3->m_iAimOriginBoneID = v20;
    }
  }
  if ( v3->m_iAimOriginBoneID < 0 )
    v3->m_iAimOriginBoneID = 0;
  UFG::AimingBaseComponent::ms_fAimDirectionYawClamp = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fAimDirectionYawClamp;
  UFG::AimingBaseComponent::ms_fAimDirectionYawReset = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fAimDirectionYawReset;
  v22 = v3->m_pSimObject;
  if ( v22 )
  {
    v23 = v22->m_Flags;
    if ( (v23 >> 14) & 1 )
    {
      v5 = v22->m_Components.p->m_pComponent;
    }
    else if ( (v23 & 0x8000u) == 0 )
    {
      if ( (v23 >> 13) & 1 )
      {
        v5 = v22->m_Components.p->m_pComponent;
      }
      else if ( (v23 >> 12) & 1 )
      {
        v24 = (unsigned int)v22[1].vfptr;
        v25 = v22->m_Components.size;
        if ( v24 < v25 )
        {
          v26 = v22->m_Components.p;
          while ( (v26[v24].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~v26[v24].m_TypeUID & 0x1FFFFFF )
          {
            if ( ++v24 >= v25 )
              goto LABEL_45;
          }
          v5 = v26[v24].m_pComponent;
        }
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType(v3->m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v5 = v22->m_Components.p->m_pComponent;
    }
LABEL_45:
    if ( v5 )
    {
      v27 = UFG::qMalloc(8ui64, UFG::gGlobalNewName, 0i64);
      v5[2].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v27;
      v27->mNext = (UFG::allocator::free_link *)&v3->m_vAimIntention;
    }
  }
}s.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase

// File Line: 172
// RVA: 0x53F960
void __fastcall UFG::AimingBaseComponent::OnDetach(UFG::AimingBaseComponent *this)
{
  UFG::AimingBaseComponent *v1; // rdi
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rbx
  unsigned int v5; // er8
  unsigned int v6; // er9
  signed __int64 v7; // rdx
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rax
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *v23; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rax

  v1 = this;
  v2 = this->m_pSimObject;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p->m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = v2->m_Components.p->m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = (unsigned int)v2[1].vfptr;
        v6 = v2->m_Components.size;
        if ( v5 >= v6 )
        {
LABEL_14:
          v4 = 0i64;
        }
        else
        {
          v7 = (signed __int64)&v2->m_Components.p[v5];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v5;
            v7 += 16i64;
            if ( v5 >= v6 )
              goto LABEL_14;
          }
          v4 = *(UFG::SimComponent **)v7;
        }
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(v2, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v2->m_Components.p->m_pComponent;
    }
    if ( v4 )
    {
      operator delete[](v4[2].m_BoundComponentHandles.mNode.mPrev);
      v4[2].m_BoundComponentHandles.mNode.mPrev = 0i64;
    }
  }
  v8 = &v1->m_pTargetingSystemPedBaseComponent;
  if ( v1->m_pTargetingSystemPedBaseComponent.m_pSimComponent )
  {
    v9 = v8->mPrev;
    v10 = v1->m_pTargetingSystemPedBaseComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v1->m_pTargetingSystemPedBaseComponent.m_pSimComponent = 0i64;
LABEL_25:
    v1->m_pTargetingSystemPedBaseComponent.m_pSimObject = 0i64;
    v1->m_pTargetingSystemPedBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pTargetingSystemPedBaseComponent.mPrev;
    v8->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v8->mPrev;
    goto LABEL_26;
  }
  if ( v1->m_pTargetingSystemPedBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v8->mPrev != v8
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v1->m_pTargetingSystemPedBaseComponent.mNext != &v1->m_pTargetingSystemPedBaseComponent) )
  {
    v11 = v8->mPrev;
    v12 = v1->m_pTargetingSystemPedBaseComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_25;
  }
LABEL_26:
  v1->m_pTargetingSystemPedBaseComponent.m_Changed = 1;
  v13 = &v1->m_TransformNodeComponent;
  if ( v1->m_TransformNodeComponent.m_pSimComponent )
  {
    v14 = v13->mPrev;
    v15 = v1->m_TransformNodeComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v1->m_TransformNodeComponent.m_pSimComponent = 0i64;
LABEL_32:
    v1->m_TransformNodeComponent.m_pSimObject = 0i64;
    v1->m_TransformNodeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_TransformNodeComponent.mPrev;
    v13->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v13->mPrev;
    goto LABEL_33;
  }
  if ( v1->m_TransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v13->mPrev != v13
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->m_TransformNodeComponent.mNext != &v1->m_TransformNodeComponent) )
  {
    v16 = v13->mPrev;
    v17 = v1->m_TransformNodeComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    goto LABEL_32;
  }
LABEL_33:
  v1->m_TransformNodeComponent.m_Changed = 1;
  v18 = &v1->m_CharacterAnimationComponent;
  if ( v1->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v19 = v18->mPrev;
    v20 = v1->m_CharacterAnimationComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v1->m_CharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_39:
    v1->m_CharacterAnimationComponent.m_pSimObject = 0i64;
    v1->m_CharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_CharacterAnimationComponent.mPrev;
    v18->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v18->mPrev;
    goto LABEL_40;
  }
  if ( v1->m_CharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v18->mPrev != v18
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v1->m_CharacterAnimationComponent.mNext != &v1->m_CharacterAnimationComponent) )
  {
    v21 = v18->mPrev;
    v22 = v1->m_CharacterAnimationComponent.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    goto LABEL_39;
  }
LABEL_40:
  v1->m_CharacterAnimationComponent.m_Changed = 1;
  v23 = &v1->m_CharacterOccupantComponent;
  if ( v1->m_CharacterOccupantComponent.m_pSimComponent )
  {
    v24 = v23->mPrev;
    v25 = v1->m_CharacterOccupantComponent.mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    v1->m_CharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_46:
    v1->m_CharacterOccupantComponent.m_pSimObject = 0i64;
    v1->m_CharacterOccupantComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_CharacterOccupantComponent.mPrev;
    v23->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v23->mPrev;
    goto LABEL_47;
  }
  if ( v1->m_CharacterOccupantComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v23->mPrev != v23
     || (UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v1->m_CharacterOccupantComponent.mNext != &v1->m_CharacterOccupantComponent) )
  {
    v26 = v23->mPrev;
    v27 = v1->m_CharacterOccupantComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    goto LABEL_46;
  }
LABEL_47:
  v1->m_CharacterOccupantComponent.m_Changed = 1;
}
    v27 = v1->m_CharacterOccupantComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    goto LABEL_46;
 

// File Line: 190
// RVA: 0x52A750
void __fastcall UFG::AimingBaseComponent::GetAimDirection(UFG::AimingBaseComponent *this, UFG::qVector3 *vAimDirection, UFG::qMatrix44 *pXform)
{
  UFG::qVector3 *v3; // rsi
  UFG::AimingBaseComponent *v4; // rdi
  float v5; // xmm2_4
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float *v9; // rbx
  float v10; // xmm6_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm4_4

  v3 = vAimDirection;
  v4 = this;
  if ( pXform )
  {
    v5 = (float)(this->m_vAimDirectionLS.x * pXform->v0.y) + (float)(this->m_vAimDirectionLS.y * pXform->v1.y);
    v6 = (float)(this->m_vAimDirectionLS.x * pXform->v0.z) + (float)(this->m_vAimDirectionLS.y * pXform->v1.z);
    v7 = this->m_vAimDirectionLS.z * pXform->v2.y;
    v8 = this->m_vAimDirectionLS.z * pXform->v2.z;
    vAimDirection->x = (float)((float)(this->m_vAimDirectionLS.y * pXform->v1.x)
                             + (float)(this->m_vAimDirectionLS.x * pXform->v0.x))
                     + (float)(this->m_vAimDirectionLS.z * pXform->v2.x);
    vAimDirection->y = v5 + v7;
    vAimDirection->z = v6 + v8;
  }
  else
  {
    v9 = (float *)this->m_TransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent);
    v10 = v4->m_vAimDirectionLS.x;
    v11 = v10;
    v12 = (float)(v10 * v9[34]) + (float)(v4->m_vAimDirectionLS.y * v9[38]);
    v13 = (float)(v11 * v9[33]) + (float)(v4->m_vAimDirectionLS.y * v9[37]);
    v14 = v4->m_vAimDirectionLS.z * v9[41];
    v15 = v4->m_vAimDirectionLS.z * v9[42];
    v3->x = (float)((float)(v4->m_vAimDirectionLS.y * v9[36]) + (float)(v4->m_vAimDirectionLS.x * v9[32]))
          + (float)(v4->m_vAimDirectionLS.z * v9[40]);
    v3->z = v12 + v15;
    v3->y = v13 + v14;
  }
}

// File Line: 205
// RVA: 0x532FC0
void __fastcall UFG::AimingBaseComponent::GetWeaponProjectileDirection(UFG::AimingBaseComponent *this, UFG::qVector3 *vWeaponProjectileDirection)
{
  float v2; // xmm7_4
  UFG::qVector3 *v3; // rdi
  UFG::AimingBaseComponent *v4; // rbx
  float v5; // xmm10_4
  float v6; // xmm8_4
  __m128 v7; // xmm9
  float v8; // xmm11_4
  float v9; // xmm12_4
  __int64 v10; // rax
  float v11; // xmm6_4
  bool v12; // al
  UFG::SimObjectWeaponPropertiesComponent *v13; // rcx
  float v14; // xmm3_4
  __m128 v15; // xmm2
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::TransformNodeComponent *v18; // rbx
  __m128 v19; // xmm7
  float v20; // xmm8_4
  float v21; // xmm7_4
  __m128 v22; // xmm2
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+20h] [rbp-88h]

  v2 = UFG::qVector3::msZero.z;
  v3 = vWeaponProjectileDirection;
  v4 = this;
  v5 = this->m_vAimIntentionTargetPosition.x;
  v6 = UFG::qVector3::msZero.x;
  v7 = (__m128)LODWORD(UFG::qVector3::msZero.y);
  v8 = this->m_vAimIntentionTargetPosition.y;
  v9 = this->m_vAimIntentionTargetPosition.z;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(this, &vWeaponProjectileSpawnPosition);
  v10 = ((__int64 (*)(void))v4->m_pTargetingSystemPedBaseComponent.m_pSimComponent->vfptr[19].__vecDelDtor)();
  v11 = 0.0;
  if ( !v10 || (unsigned int)(*(_DWORD *)(v10 + 3432) - 1) > 1 )
  {
    if ( LOBYTE(v4->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev)
      && (v12 = UFG::IsAnyLocalPlayer(v4->m_pSimObject),
          (v13 = *(UFG::SimObjectWeaponPropertiesComponent **)&v4->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID) != 0i64) )
    {
      v14 = UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileSpeed(v13, v12 == 0);
    }
    else
    {
      v14 = 0.0;
    }
    v15 = (__m128)LODWORD(v4->m_vAimOriginPosition.y);
    v15.m128_f32[0] = v15.m128_f32[0] - v4->m_vAimIntentionTargetPosition.y;
    v16 = v4->m_vAimOriginPosition.x - v4->m_vAimIntentionTargetPosition.x;
    v17 = v4->m_vAimOriginPosition.z - v4->m_vAimIntentionTargetPosition.z;
    v18 = (UFG::TransformNodeComponent *)v4->m_TransformNodeComponent.m_pSimComponent;
    v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v16 * v16)) + (float)(v17 * v17);
    v19 = _mm_sqrt_ps(v15);
    v19.m128_f32[0] = v19.m128_f32[0] / v14;
    UFG::TransformNodeComponent::UpdateWorldTransform(v18);
    v7 = v19;
    v6 = v19.m128_f32[0] * v18->mWorldVelocity.x;
    v7.m128_f32[0] = v19.m128_f32[0] * v18->mWorldVelocity.y;
    v2 = v19.m128_f32[0] * v18->mWorldVelocity.z;
  }
  v20 = (float)(v6 + v5) - vWeaponProjectileSpawnPosition.x;
  v7.m128_f32[0] = (float)(v7.m128_f32[0] + v8) - vWeaponProjectileSpawnPosition.y;
  v21 = (float)(v2 + v9) - vWeaponProjectileSpawnPosition.z;
  v22 = v7;
  v22.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v20 * v20)) + (float)(v21 * v21);
  if ( v22.m128_f32[0] != 0.0 )
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v22));
  v3->x = v20 * v11;
  v3->y = v7.m128_f32[0] * v11;
  v3->z = v21 * v11;
}

// File Line: 247
// RVA: 0x5331B0
void __fastcall UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(UFG::AimingBaseComponent *this, UFG::qVector3 *vWeaponProjectileSpawnPosition)
{
  UFG::SimComponent *v2; // rax
  UFG::qVector3 *v3; // rdi
  UFG::AimingBaseComponent *v4; // rbp
  UFG::SimObjectWeaponPropertiesComponent *v5; // rsi
  UFG::SimObjectProp *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::CharacterAnimationComponent *v8; // rcx
  unsigned int v9; // er8
  unsigned int v10; // edx
  unsigned int v11; // eax
  UFG::CharacterAnimationComponent *v12; // rax
  unsigned int v13; // er8
  unsigned int v14; // er10
  signed __int64 v15; // rdx
  Creature *v16; // rbx
  int v17; // eax
  float v18; // xmm1_4
  float v19; // xmm0_4
  UFG::SimComponent *v20; // rsi
  UFG::SimObject *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::CharacterPhysicsComponent *v23; // rbx
  unsigned int v24; // edx
  unsigned int v25; // er9
  signed __int64 v26; // rbx
  unsigned int v27; // edx
  unsigned int v28; // er9
  unsigned int v29; // edx
  unsigned int v30; // er9
  float v31; // xmm7_4
  float v32; // xmm0_4
  UFG::SimComponent *v33; // rbx
  __m128 v34; // xmm3
  float v35; // xmm4_4
  __m128 v36; // xmm2
  float v37; // xmm7_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-68h]

  v2 = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  v3 = vWeaponProjectileSpawnPosition;
  v4 = this;
  if ( !LOBYTE(v2[8].m_BoundComponentHandles.mNode.mPrev) )
  {
    v20 = this->m_TransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent);
    v21 = v4->m_pSimObject;
    if ( !v21 )
    {
LABEL_59:
      v39 = *((float *)&v20[2].m_BoundComponentHandles.mNode.mPrev + 1);
      v40 = *(float *)&v20[2].m_BoundComponentHandles.mNode.mNext;
      v3->x = *(float *)&v20[2].m_BoundComponentHandles.mNode.mPrev;
      v3->y = v39;
      v3->z = v40;
      return;
    }
    v22 = v21->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v23 = (UFG::CharacterPhysicsComponent *)v21->m_Components.p[27].m_pComponent;
      goto LABEL_57;
    }
    if ( (v22 & 0x8000u) == 0 )
    {
      if ( (v22 >> 13) & 1 )
      {
        v27 = (unsigned int)v21[1].vfptr;
        v28 = v21->m_Components.size;
        if ( v27 < v28 )
        {
          v26 = (signed __int64)&v21->m_Components.p[v27];
          while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF )
          {
            ++v27;
            v26 += 16i64;
            if ( v27 >= v28 )
            {
              v23 = 0i64;
              goto LABEL_57;
            }
          }
          goto LABEL_41;
        }
      }
      else
      {
        if ( !((v22 >> 12) & 1) )
        {
          v23 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                    v21,
                                                    UFG::CharacterPhysicsComponent::_TypeUID);
LABEL_57:
          if ( v23 )
          {
            v31 = UFG::CharacterPhysicsComponent::GetRadius(v23);
            v32 = UFG::CharacterPhysicsComponent::GetHeight(v23, v23->mCollisionModelType);
            v33 = v4->m_TransformNodeComponent.m_pSimComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4->m_TransformNodeComponent.m_pSimComponent);
            v34 = (__m128)LODWORD(v33[2].vfptr);
            v35 = *((float *)&v33[2].vfptr + 1);
            v36 = v34;
            v36.m128_f32[0] = (float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v35 * v35);
            v37 = v31 / COERCE_FLOAT(_mm_sqrt_ps(v36));
            v36.m128_f32[0] = (float)(v37 * v34.m128_f32[0]) + *(float *)&v20[2].m_BoundComponentHandles.mNode.mPrev;
            v38 = (float)(v37 * v35) + *((float *)&v20[2].m_BoundComponentHandles.mNode.mPrev + 1);
            v3->z = (float)((float)(v37 * 0.0) + *(float *)&v20[2].m_BoundComponentHandles.mNode.mNext)
                  + (float)(v32 * 0.5);
            LODWORD(v3->x) = v36.m128_i32[0];
            v3->y = v38;
            return;
          }
          goto LABEL_59;
        }
        v29 = (unsigned int)v21[1].vfptr;
        v30 = v21->m_Components.size;
        if ( v29 < v30 )
        {
          v26 = (signed __int64)&v21->m_Components.p[v29];
          while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF )
          {
            ++v29;
            v26 += 16i64;
            if ( v29 >= v30 )
            {
              v23 = 0i64;
              goto LABEL_57;
            }
          }
          goto LABEL_41;
        }
      }
    }
    else
    {
      v24 = (unsigned int)v21[1].vfptr;
      v25 = v21->m_Components.size;
      if ( v24 < v25 )
      {
        v26 = (signed __int64)&v21->m_Components.p[v24];
        while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
             || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF )
        {
          ++v24;
          v26 += 16i64;
          if ( v24 >= v25 )
            goto LABEL_40;
        }
LABEL_41:
        v23 = *(UFG::CharacterPhysicsComponent **)v26;
        goto LABEL_57;
      }
    }
LABEL_40:
    v23 = 0i64;
    goto LABEL_57;
  }
  v5 = *(UFG::SimObjectWeaponPropertiesComponent **)&v2[8].m_TypeUID;
  if ( v5 )
    v6 = (UFG::SimObjectProp *)v5->m_pSimObject;
  else
    v6 = 0i64;
  if ( !v6 )
    goto LABEL_30;
  v7 = v6->m_Flags;
  if ( !((v7 >> 14) & 1) )
  {
    if ( (v7 & 0x8000u) != 0 )
    {
      v8 = (UFG::CharacterAnimationComponent *)v6->m_Components.p[9].m_pComponent;
      if ( v8 )
      {
        v10 = v8->m_TypeUID;
        v9 = UFG::CharacterAnimationComponent::_TypeUID;
        v11 = UFG::CharacterAnimationComponent::_TypeUID ^ v8->m_TypeUID;
        goto LABEL_9;
      }
LABEL_11:
      v8 = 0i64;
      goto LABEL_27;
    }
    if ( (v7 >> 13) & 1 )
    {
      v12 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v6);
    }
    else
    {
      if ( (v7 >> 12) & 1 )
      {
        v13 = v6->mComponentTableEntryCount;
        v14 = v6->m_Components.size;
        if ( v13 < v14 )
        {
          v15 = (signed __int64)&v6->m_Components.p[v13];
          while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF )
          {
            ++v13;
            v15 += 16i64;
            if ( v13 >= v14 )
            {
              v8 = 0i64;
              goto LABEL_27;
            }
          }
          v8 = *(UFG::CharacterAnimationComponent **)v15;
          goto LABEL_27;
        }
        goto LABEL_11;
      }
      v12 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v6->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    v8 = v12;
    goto LABEL_27;
  }
  v8 = (UFG::CharacterAnimationComponent *)v6->m_Components.p[9].m_pComponent;
  if ( !v8 )
    goto LABEL_11;
  v9 = UFG::CharacterAnimationComponent::_TypeUID;
  v10 = v8->m_TypeUID;
  v11 = v10 ^ UFG::CharacterAnimationComponent::_TypeUID;
LABEL_9:
  if ( v11 & 0xFE000000 || v9 & ~v10 & 0x1FFFFFF )
    goto LABEL_11;
LABEL_27:
  if ( !v8 )
  {
LABEL_30:
    *(_QWORD *)&v3->x = 0i64;
    v3->z = 0.0;
    return;
  }
  v16 = v8->mCreature;
  if ( v16 )
  {
    v17 = UFG::SimObjectWeaponPropertiesComponent::GetProjectileSpawnBoneID(v5);
    Creature::GetTransform(v16, v17, &transform);
    v18 = transform.v3.y;
    v3->x = transform.v3.x;
    v19 = transform.v3.z;
    v3->y = v18;
    v3->z = v19;
  }
} = UFG::SimObjectWeaponPropertiesComponent::GetProje

// File Line: 321
// RVA: 0x5338E0
void __fastcall UFG::AimingBaseComponent::GetWeaponProjectileSpeed(UFG::AimingBaseComponent *this)
{
  UFG::AimingBaseComponent *v1; // rbx
  bool v2; // al
  UFG::SimObjectWeaponPropertiesComponent *v3; // rcx

  v1 = this;
  if ( LOBYTE(this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev) )
  {
    v2 = UFG::IsAnyLocalPlayer(this->m_pSimObject);
    v3 = *(UFG::SimObjectWeaponPropertiesComponent **)&v1->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
    if ( v3 )
      UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileSpeed(v3, v2 == 0);
  }
}

// File Line: 338
// RVA: 0x52F860
float __usercall UFG::AimingBaseComponent::GetRadialInaccuracyAtAimPosition@<xmm0>(UFG::AimingBaseComponent *this@<rcx>, float a2@<xmm0>)
{
  UFG::AimingBaseComponent *v2; // rbx
  __m128 v3; // xmm3

  v2 = this;
  ((void (*)(void))this->vfptr[19].__vecDelDtor)();
  v3 = (__m128)LODWORD(v2->m_vAimOriginPosition.y);
  v3.m128_f32[0] = (float)((float)((float)(v3.m128_f32[0] - v2->m_vAimIntentionTargetPosition.y)
                                 * (float)(v3.m128_f32[0] - v2->m_vAimIntentionTargetPosition.y))
                         + (float)((float)(v2->m_vAimOriginPosition.x - v2->m_vAimIntentionTargetPosition.x)
                                 * (float)(v2->m_vAimOriginPosition.x - v2->m_vAimIntentionTargetPosition.x)))
                 + (float)((float)(v2->m_vAimOriginPosition.z - v2->m_vAimIntentionTargetPosition.z)
                         * (float)(v2->m_vAimOriginPosition.z - v2->m_vAimIntentionTargetPosition.z));
  return COERCE_FLOAT(_mm_sqrt_ps(v3)) * tanf(a2);
}

// File Line: 348
// RVA: 0x52E290
float __fastcall UFG::AimingBaseComponent::GetLocalAimDirectionXY(UFG::AimingBaseComponent *this)
{
  float v1; // xmm3_4
  __m128 v2; // xmm4
  __m128 v3; // xmm1
  float v4; // xmm2_4
  float result; // xmm0_4
  bool v6; // cf
  bool v7; // zf

  v1 = this->m_vAimDirectionLS.x;
  v2 = (__m128)LODWORD(this->m_vAimDirectionLS.y);
  v3 = v2;
  v3.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v1 * v1);
  if ( v3.m128_f32[0] == 0.0 )
    v4 = 0.0;
  else
    v4 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v3));
  result = atan2f(COERCE_FLOAT(COERCE_UNSIGNED_INT(v4 * v2.m128_f32[0]) ^ _xmm[0]), v4 * v1);
  v6 = result < 0.0;
  v7 = result == 0.0;
  if ( result < 0.0 )
  {
    result = result + 6.2831855;
    v6 = result < 0.0;
    v7 = result == 0.0;
  }
  if ( v6 || v7 )
    return 0.0;
  if ( result >= 6.2831855 )
    result = FLOAT_6_2831855;
  return result;
}

// File Line: 367
// RVA: 0x52E730
float __fastcall UFG::AimingBaseComponent::GetLocalAimDirectionXZ(UFG::AimingBaseComponent *this)
{
  __m128 v1; // xmm2
  float result; // xmm0_4
  bool v3; // cf
  bool v4; // zf

  v1 = (__m128)LODWORD(this->m_vAimDirectionLS.y);
  v1.m128_f32[0] = (float)(v1.m128_f32[0] * v1.m128_f32[0])
                 + (float)(this->m_vAimDirectionLS.x * this->m_vAimDirectionLS.x);
  result = atan2f(this->m_vAimDirectionLS.z, COERCE_FLOAT(_mm_sqrt_ps(v1)));
  v3 = result < 0.0;
  v4 = result == 0.0;
  if ( result < 0.0 )
  {
    result = result + 6.2831855;
    v3 = result < 0.0;
    v4 = result == 0.0;
  }
  if ( v3 || v4 )
    return 0.0;
  if ( result >= 6.2831855 )
    result = FLOAT_6_2831855;
  return result;
}

// File Line: 386
// RVA: 0x52E330
float __fastcall UFG::AimingBaseComponent::GetLocalAimDirectionXYRelCover(UFG::AimingBaseComponent *this)
{
  UFG::AimingBaseComponent *v1; // rsi
  UFG::SimObjectGame *rcx1; // rcx
  unsigned __int16 v3; // dx
  unsigned int v4; // er8
  unsigned int v5; // er9
  UFG::SimComponentHolder *v6; // rdx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned int v10; // er8
  unsigned int v11; // er9
  unsigned int v12; // er8
  unsigned int v13; // er9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rdi
  UFG::SimComponent *v15; // rbx
  _DWORD *v16; // rax
  int v17; // xmm3_4
  int v18; // xmm1_4
  float v19; // xmm6_4
  float result; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-38h]
  char v22; // [rsp+2Ch] [rbp-2Ch]

  v1 = this;
  rcx1 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !rcx1 )
    return 0.0;
  v3 = rcx1->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = rcx1->mComponentTableEntryCount;
    v5 = rcx1->m_Components.size;
    v6 = (UFG::SimComponentHolder *)v4;
    if ( v4 < v5 )
    {
      v6 = &rcx1->m_Components.p[v4];
      while ( (v6->m_TypeUID & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
           || UFG::AICoverComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF )
      {
        ++v4;
        ++v6;
        if ( v4 >= v5 )
          goto LABEL_8;
      }
LABEL_9:
      v7 = v6->m_pComponent;
      goto LABEL_32;
    }
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
    {
      v10 = rcx1->mComponentTableEntryCount;
      v11 = rcx1->m_Components.size;
      v6 = (UFG::SimComponentHolder *)v10;
      if ( v10 < v11 )
      {
        v6 = &rcx1->m_Components.p[v10];
        while ( (v6->m_TypeUID & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
             || UFG::AICoverComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF )
        {
          ++v10;
          ++v6;
          if ( v10 >= v11 )
          {
            v7 = 0i64;
            goto LABEL_32;
          }
        }
        goto LABEL_9;
      }
    }
    else
    {
      if ( !((v3 >> 12) & 1) )
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&rcx1->vfptr, UFG::AICoverComponent::_TypeUID);
        goto LABEL_32;
      }
      v12 = rcx1->mComponentTableEntryCount;
      v13 = rcx1->m_Components.size;
      v6 = (UFG::SimComponentHolder *)v12;
      if ( v12 < v13 )
      {
        v6 = &rcx1->m_Components.p[v12];
        while ( (v6->m_TypeUID & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
             || UFG::AICoverComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF )
        {
          ++v12;
          ++v6;
          if ( v12 >= v13 )
          {
            v7 = 0i64;
            goto LABEL_32;
          }
        }
        goto LABEL_9;
      }
    }
  }
  else
  {
    v8 = rcx1->mComponentTableEntryCount;
    v9 = rcx1->m_Components.size;
    v6 = (UFG::SimComponentHolder *)v8;
    if ( v8 < v9 )
    {
      v6 = &rcx1->m_Components.p[v8];
      while ( (v6->m_TypeUID & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
           || UFG::AICoverComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF )
      {
        ++v8;
        ++v6;
        if ( v8 >= v9 )
        {
          v7 = 0i64;
          goto LABEL_32;
        }
      }
      goto LABEL_9;
    }
  }
LABEL_8:
  v7 = 0i64;
LABEL_32:
  if ( !v7 )
    return 0.0;
  v14 = v7[1].m_BoundComponentHandles.mNode.mNext;
  if ( !v14
    || !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::SimComponentHolder *))v14->mPrev[1].mPrev)(
          v14,
          v6) )
  {
    return 0.0;
  }
  v15 = v1->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v15);
  v16 = (_DWORD *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, char *))v14->mPrev[10].mPrev)(
                    v14,
                    &v22);
  v17 = v16[2] ^ _xmm[0];
  v18 = v16[1] ^ _xmm[0];
  LODWORD(v2.x) = *v16 ^ _xmm[0];
  LODWORD(v2.y) = v18;
  LODWORD(v2.z) = v17;
  v19 = UFG::qHeadingDifference2D((UFG::qVector3 *)&v15[2], &v2);
  result = UFG::AimingBaseComponent::GetLocalAimDirectionXY(v1) + v19;
  if ( result >= 0.0 )
  {
    if ( result > 6.2831855 )
      result = result + -6.2831855;
  }
  else
  {
    result = result + 6.2831855;
  }
  if ( result <= 0.0 )
    return 0.0;
  if ( result >= 6.2831855 )
    result = FLOAT_6_2831855;
  return result;
}

// File Line: 419
// RVA: 0x52E630
float __fastcall UFG::AimingBaseComponent::GetLocalAimDirectionXYRelSyncBone(UFG::AimingBaseComponent *this)
{
  UFG::AimingBaseComponent *v1; // rdi
  __int64 rcx1; // rcx
  UFG::SimComponent *v3; // rbx
  float v4; // xmm6_4
  float result; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-68h]
  UFG::qMatrix44 matrixWS; // [rsp+30h] [rbp-58h]

  v1 = this;
  rcx1 = *(_QWORD *)&this->m_CharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
  if ( !rcx1 )
    return 0.0;
  SkeletalPose::GetPositionWS((SkeletalPose *)(rcx1 + 240), 3, &matrixWS);
  v3 = v1->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_TransformNodeComponent.m_pSimComponent);
  v2.x = matrixWS.v0.x;
  v2.y = matrixWS.v0.y;
  v2.z = matrixWS.v0.z;
  v4 = UFG::qHeadingDifference2D((UFG::qVector3 *)&v3[2], &v2);
  result = UFG::AimingBaseComponent::GetLocalAimDirectionXY(v1) + v4;
  if ( result >= 0.0 )
  {
    if ( result > 6.2831855 )
      result = result + -6.2831855;
  }
  else
  {
    result = result + 6.2831855;
  }
  if ( result <= 0.0 )
    return 0.0;
  if ( result >= 6.2831855 )
    result = FLOAT_6_2831855;
  return result;
}

// File Line: 451
// RVA: 0x530470
void __fastcall UFG::AimingBaseComponent::GetTargetNormalAimPosition(UFG::AimingBaseComponent *this, UFG::qVector3 *vTargetNormalAimPosition, __int64 eTargetType, UFG::qMatrix44 *pXform)
{
  UFG::AimingBaseComponent *v4; // rsi
  UFG::TargetingSystemPedBaseComponent *v5; // rcx
  UFG::qVector3 *v6; // rdi
  UFG::TargetingSimObject *v7; // rax
  signed __int64 v8; // r10
  UFG::SimObject *v9; // rbx
  UFG::SubTargetingProfile *v10; // rax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  UFG::qMatrix44 *v15; // r8
  UFG::SimComponent *v16; // rbx
  UFG::qVector3 vDefaultTargetablePosWS; // [rsp+20h] [rbp-58h]
  UFG::qMatrix44 matSimObject; // [rsp+30h] [rbp-48h]

  v4 = this;
  v5 = (UFG::TargetingSystemPedBaseComponent *)this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  eTargetType = (unsigned int)eTargetType;
  v6 = vTargetNormalAimPosition;
  v7 = v5->m_pTargets;
  v8 = (unsigned __int8)v5->m_pTargetingMap->m_Map.p[(unsigned int)eTargetType];
  v9 = v7[v8].m_pTarget.m_pPointer;
  if ( v9 )
  {
    v10 = UFG::TargetingSystemPedBaseComponent::GetSubTargetingProfileForTarget(
            v5,
            v7[v8].m_pTarget.m_pPointer,
            eTargetType);
    if ( v10 && UFG::SubTargetingProfile::FindDefaultTargetablePosWS(v10, &vDefaultTargetablePosWS, v9) )
    {
      v11 = vDefaultTargetablePosWS.y;
      v6->x = vDefaultTargetablePosWS.x;
      v12 = vDefaultTargetablePosWS.z;
      v6->y = v11;
      v6->z = v12;
    }
    else
    {
      UFG::TargetingSystemBaseComponent::FindMatrix(v9->m_pTransformNodeComponent, v9, &matSimObject);
      v13 = matSimObject.v3.y;
      v6->x = matSimObject.v3.x;
      v14 = matSimObject.v3.z;
      v6->y = v13;
      v6->z = v14;
    }
  }
  else
  {
    if ( pXform )
    {
      v15 = pXform;
    }
    else
    {
      v16 = v4->m_TransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4->m_TransformNodeComponent.m_pSimComponent);
      v15 = (UFG::qMatrix44 *)&v16[2];
      vTargetNormalAimPosition = v6;
    }
    UFG::AimingBaseComponent::getNeutralAimPosition(v4, vTargetNormalAimPosition, v15);
  }
}

// File Line: 491
// RVA: 0x541DF0
void __fastcall UFG::AimingBaseComponent::OnTargetChanged(UFG::AimingBaseComponent *this)
{
  __int64 v1; // rax
  float v2; // xmm1_4

  *(_QWORD *)&this->m_Accuracy.m_fAccuracyMaximum = 1065353216i64;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyUnclamped = 0i64;
  v1 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
  if ( v1 )
  {
    v2 = *(float *)(*(_QWORD *)(*(_QWORD *)(v1 + 176) + 8i64 * *(unsigned int *)(v1 + 172) + 8) + 160i64);
    if ( v2 <= 0.0 )
    {
      v2 = 0.0;
    }
    else if ( v2 >= 1.0 )
    {
      LODWORD(this->m_Accuracy.m_fAccuracyUnclamped) = (_DWORD)FLOAT_1_0;
      return;
    }
    this->m_Accuracy.m_fAccuracyUnclamped = v2;
  }
}

// File Line: 518
// RVA: 0x520800
void __fastcall UFG::AimingBaseComponent::AddAccuracyModifierTask(UFG::AimingBaseComponent *this, AccuracyModifierTask *pAccuracyModifierTask)
{
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *v2; // rdx
  UFG::qList<AccuracyModifierTask,AimingSystemAccuracyModifierList,0,0> *v3; // rcx
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *v4; // rax

  v2 = (UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *)&pAccuracyModifierTask->mPrev;
  v3 = &this->m_AccuracyModifierTaskList;
  v4 = v3->mNode.mPrev;
  v4->mNext = v2;
  v2->mPrev = v4;
  v2->mNext = &v3->mNode;
  v3->mNode.mPrev = v2;
}

// File Line: 525
// RVA: 0x5605C0
void __fastcall UFG::AimingBaseComponent::UpdateLocalAimDirection(UFG::AimingBaseComponent *this, UFG::qMatrix44 *matToLocal, UFG::qVector3 *vAimAtPosition)
{
  float v3; // xmm3_4
  __m128 v4; // xmm5
  float v5; // xmm6_4
  float v6; // xmm7_4
  __m128 v7; // xmm2
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm2_4

  v4 = (__m128)LODWORD(vAimAtPosition->y);
  v3 = 0.0;
  v4.m128_f32[0] = v4.m128_f32[0] - this->m_vAimOriginPosition.y;
  v5 = vAimAtPosition->z - this->m_vAimOriginPosition.z;
  v7 = v4;
  v6 = vAimAtPosition->x - this->m_vAimOriginPosition.x;
  v7.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v6 * v6)) + (float)(v5 * v5);
  if ( v7.m128_f32[0] != 0.0 )
    v3 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v7));
  v8 = v5 * v3;
  v9 = v4.m128_f32[0] * v3;
  v10 = v3 * v6;
  v11 = (float)((float)((float)(v4.m128_f32[0] * v3) * matToLocal->v1.x) + (float)((float)(v3 * v6) * matToLocal->v0.x))
      + (float)(v8 * matToLocal->v2.x);
  v12 = v8;
  v13 = (float)(v9 * matToLocal->v1.z) + (float)(v10 * matToLocal->v0.z);
  v14 = v8 * matToLocal->v2.z;
  v15 = v12 * matToLocal->v2.y;
  v16 = (float)(v9 * matToLocal->v1.y) + (float)(v10 * matToLocal->v0.y);
  this->m_vAimDirectionLS.x = v11;
  this->m_vAimDirectionLS.y = v16 + v15;
  this->m_vAimDirectionLS.z = v13 + v14;
}

// File Line: 553
// RVA: 0x565D30
__int64 __fastcall UFG::AimingBaseComponent::couldShootSomeoneUnintendedHelper(UFG::AimingBaseComponent *this, UFG::qVector3 *vMyPosition, const float fMaxDistance, const float fAccuracyRad, UFG::qVector3 *vProjectileSpawnPos)
{
  float v5; // xmm9_4
  UFG::qVector3 *v6; // r15
  UFG::AimingBaseComponent *v7; // rsi
  __int64 v8; // rbx
  UFG::qVector3 *v9; // r13
  char v10; // r12
  UFG::qVector3 *v11; // rdi
  __int64 v12; // rbx
  UFG::SimObject *v13; // rax
  UFG::TransformNodeComponent *v14; // rax
  UFG::qMatrix44 *v15; // rsi
  float v16; // xmm0_4
  __m128 v17; // xmm1
  UFG::SimComponent *v18; // rax
  UFG::SimComponent *v19; // rax
  UFG::eFactionClassEnum v20; // esi
  UFG::GameStatTracker *v21; // rax
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  float v24; // xmm1_4
  unsigned int v25; // xmm8_4
  unsigned int v26; // xmm7_4
  unsigned __int8 v27; // r8
  __int64 i; // rax
  _QWORD *v29; // rdx
  __int64 v30; // rcx
  _QWORD *v31; // rax
  __int64 v32; // rdx
  __int64 *v33; // rcx
  UFG::qMatrix44 *pXform; // [rsp+30h] [rbp-91h]
  __int64 v36; // [rsp+38h] [rbp-89h]
  UFG::qVector3 ray_pos_p; // [rsp+40h] [rbp-81h]
  UFG::qVector3 seg_pos_p; // [rsp+50h] [rbp-71h]
  __int128 v2; // [rsp+60h] [rbp-61h]
  __int64 *v40; // [rsp+70h] [rbp-51h]
  __int64 v41; // [rsp+90h] [rbp-31h]
  UFG::AimingBaseComponent *v42; // [rsp+F8h] [rbp+37h]
  UFG::qVector3 *retaddr; // [rsp+118h] [rbp+57h]
  UFG::qVector3 *ray_dir; // [rsp+120h] [rbp+5Fh]
  UFG::eNearbyCharacterType character_type; // [rsp+128h] [rbp+67h]
  UFG::eFactionClassEnum source; // [rsp+130h] [rbp+6Fh]
  char v47; // [rsp+138h] [rbp+77h]

  ray_dir = (UFG::qVector3 *)this;
  v36 = -2i64;
  v5 = fMaxDistance;
  v6 = vMyPosition;
  v7 = this;
  *((_QWORD *)&v2 + 1) = &v41;
  v40 = &v41;
  UFG::NearbyCharacterManager::GetNearbyCharacters(
    UFG::NearbyCharacterManager::s_pInstance,
    (UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> *)((char *)&v2 + 8),
    character_type,
    vMyPosition);
  v8 = (__int64)(v40 - 2);
  if ( v40 - 2 != (__int64 *)&seg_pos_p.z )
  {
    v9 = vProjectileSpawnPos;
    v10 = v47;
    do
    {
      v11 = (UFG::qVector3 *)(*(_QWORD *)(v8 + 24) - 16i64);
      v12 = *(_QWORD *)(v8 + 48);
      if ( v12 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v12 + 112i64))(v12) )
        {
          v13 = *(UFG::SimObject **)(v12 + 40);
          if ( v13 != v7->m_pSimObject && v13 != (UFG::SimObject *)v9 )
          {
            v14 = (UFG::TransformNodeComponent *)hkMemoryMeshBody::getMeshShape((hkMemoryMeshBody *)v12);
            v15 = (UFG::qMatrix44 *)v14;
            if ( v14 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v14);
              pXform = v15 + 2;
              v16 = v6->y - v15[2].v3.y;
              v17 = (__m128)LODWORD(v6->x);
              v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] - v15[2].v3.x)
                                              * (float)(v17.m128_f32[0] - v15[2].v3.x))
                                      + (float)(v16 * v16))
                              + (float)((float)(v6->z - v15[2].v3.z) * (float)(v6->z - v15[2].v3.z));
              if ( v5 >= COERCE_FLOAT(_mm_sqrt_ps(v17)) )
              {
                v18 = UFG::AIEntityComponent::GetHealthComponent((UFG::AIEntityComponent *)v12);
                if ( !v18 || !BYTE4(v18[1].m_BoundComponentHandles.mNode.mPrev) )
                {
                  v19 = UFG::AIEntityComponent::GetSimObjectCharacterPropertiesComponent((UFG::AIEntityComponent *)v12);
                  v20 = v19 ? LODWORD(v19[3].m_SafePointerList.mNode.mPrev) : 1;
                  v21 = UFG::FactionInterface::Get();
                  if ( (unsigned int)UFG::FactionInterface::GetStanding(&v21->mFactionInterface, source, v20) != 2
                    && (v10 || !UFG::IsHostage(*(UFG::SimObject **)(v12 + 40))) )
                  {
                    *(float *)&character_type = 0.0;
                    if ( UFG::SimObjectUtility::GetObjectCapsuleApproximation(
                           *(UFG::SimObject **)(v12 + 40),
                           &pXform,
                           (UFG::qVector3 *)((char *)&seg_pos_p + 8),
                           (UFG::qVector3 *)((char *)&ray_pos_p + 8),
                           (float *)&character_type) )
                    {
                      UFG::qNearestRaySeg(
                        retaddr,
                        ray_dir,
                        (UFG::qVector3 *)((char *)&seg_pos_p + 8),
                        (UFG::qVector3 *)((char *)&ray_pos_p + 8),
                        &ray_pos_p,
                        &seg_pos_p);
                      v22 = (__m128)LODWORD(ray_pos_p.x);
                      v22.m128_f32[0] = ray_pos_p.x - seg_pos_p.x;
                      v23 = v22;
                      v23.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0])
                                              + (float)((float)(ray_pos_p.y - seg_pos_p.y)
                                                      * (float)(ray_pos_p.y - seg_pos_p.y)))
                                      + (float)((float)(ray_pos_p.z - seg_pos_p.z) * (float)(ray_pos_p.z - seg_pos_p.z));
                      v24 = *(float *)&character_type / COERCE_FLOAT(_mm_sqrt_ps(v23));
                      *(float *)&v25 = (float)((float)((float)(ray_pos_p.z - seg_pos_p.z) * v24) + seg_pos_p.z)
                                     - retaddr->z;
                      *(float *)&v26 = (float)((float)((float)(ray_pos_p.y - seg_pos_p.y) * v24) + seg_pos_p.y)
                                     - retaddr->y;
                      *(float *)&v2 = (float)((float)((float)(ray_pos_p.x - seg_pos_p.x) * v24) + seg_pos_p.x)
                                    - retaddr->x;
                      *(_QWORD *)((char *)&v2 + 4) = __PAIR__(v25, v26);
                      if ( fAccuracyRad >= UFG::qAngleBetween(ray_dir, (UFG::qVector3 *)&v2) )
                      {
                        v27 = 1;
                        goto LABEL_24;
                      }
                    }
                  }
                }
              }
            }
            v7 = v42;
          }
        }
      }
      v8 = (__int64)v11;
    }
    while ( v11 != (UFG::qVector3 *)&seg_pos_p.z );
  }
  v27 = 0;
LABEL_24:
  for ( i = (__int64)(v40 - 2); v40 - 2 != (__int64 *)&seg_pos_p.z; i = (__int64)(v40 - 2) )
  {
    v29 = (_QWORD *)(i + 16);
    v30 = *(_QWORD *)(i + 16);
    v31 = *(_QWORD **)(i + 24);
    *(_QWORD *)(v30 + 8) = v31;
    *v31 = v30;
    *v29 = v29;
    v29[1] = v29;
  }
  v32 = *((_QWORD *)&v2 + 1);
  v33 = v40;
  *(_QWORD *)(*((_QWORD *)&v2 + 1) + 8i64) = v40;
  *v33 = v32;
  return v27;
}

// File Line: 734
// RVA: 0x523CE0
bool __usercall UFG::AimingBaseComponent::CouldShootSomeoneUnintended@<al>(UFG::AimingBaseComponent *this@<rcx>, const bool bIncludePedestrians@<dl>, const bool bIncludeHostages@<r8b>, float a4@<xmm0>)
{
  UFG::SimComponent *v4; // rax
  bool v5; // r14
  bool v6; // r12
  UFG::AimingBaseComponent *v7; // rdi
  __int64 v8; // rsi
  __int64 v9; // rax
  float v10; // xmm6_4
  UFG::SimComponent *v11; // rbx
  unsigned int uMyFactionClassEnum; // er15
  signed __int64 v13; // rbp
  UFG::SimObject *pIntendedTargetSimObject; // rsi
  float *v15; // rbx
  __m128 v16; // xmm2
  float v17; // xmm1_4
  bool result; // al
  UFG::qVector3 vWeaponProjectileDirection; // [rsp+50h] [rbp-58h]
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+60h] [rbp-48h]

  v4 = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  v5 = bIncludeHostages;
  v6 = bIncludePedestrians;
  v7 = this;
  if ( !v4 )
    return 0;
  v8 = *(_QWORD *)&v4[5].m_Flags;
  if ( !v8 )
    return 0;
  if ( LOBYTE(v4[8].m_BoundComponentHandles.mNode.mPrev) && (v9 = *(_QWORD *)&v4[8].m_TypeUID) != 0 )
    v10 = *(float *)(*(_QWORD *)(*(_QWORD *)(v9 + 176) + 8i64 * *(unsigned int *)(v9 + 172) + 8) + 40i64);
  else
    v10 = *(float *)&FLOAT_1_0;
  v11 = this->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent);
  uMyFactionClassEnum = *(_DWORD *)(v8 + 200);
  v13 = (signed __int64)&v11[2].m_BoundComponentHandles;
  ((void (__fastcall *)(UFG::AimingBaseComponent *))v7->vfptr[19].__vecDelDtor)(v7);
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(v7, &vWeaponProjectileSpawnPosition);
  UFG::AimingBaseComponent::GetWeaponProjectileDirection(v7, &vWeaponProjectileDirection);
  pIntendedTargetSimObject = *(UFG::SimObject **)(56i64
                                                * *(unsigned __int8 *)(*(_QWORD *)&v7->m_pTargetingSystemPedBaseComponent.m_pSimComponent[1].m_Flags
                                                                     + 30i64)
                                                + *(_QWORD *)&v7->m_pTargetingSystemPedBaseComponent.m_pSimComponent[1].m_TypeUID
                                                + 40);
  if ( !pIntendedTargetSimObject )
    return 0;
  v15 = (float *)pIntendedTargetSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(pIntendedTargetSimObject->m_pTransformNodeComponent);
  v16 = (__m128)*(unsigned int *)(v13 + 4);
  v16.m128_f32[0] = (float)((float)((float)(v16.m128_f32[0] - v15[45]) * (float)(v16.m128_f32[0] - v15[45]))
                          + (float)((float)(*(float *)v13 - v15[44]) * (float)(*(float *)v13 - v15[44])))
                  + (float)((float)(*(float *)(v13 + 8) - v15[46]) * (float)(*(float *)(v13 + 8) - v15[46]));
  v17 = COERCE_FLOAT(_mm_sqrt_ps(v16)) + 2.0;
  if ( v10 >= v17 )
    v10 = v17;
  result = UFG::AimingBaseComponent::couldShootSomeoneUnintendedHelper(
             v7,
             (UFG::qVector3 *)v13,
             v10,
             a4,
             &vWeaponProjectileSpawnPosition,
             &vWeaponProjectileDirection,
             0,
             uMyFactionClassEnum,
             v5,
             pIntendedTargetSimObject);
  if ( !result && v6 )
    result = UFG::AimingBaseComponent::couldShootSomeoneUnintendedHelper(
               v7,
               (UFG::qVector3 *)v13,
               v10,
               a4,
               &vWeaponProjectileSpawnPosition,
               &vWeaponProjectileDirection,
               1u,
               uMyFactionClassEnum,
               v5,
               pIntendedTargetSimObject);
  return result;
}

// File Line: 1098
// RVA: 0x565B10
void __fastcall UFG::AimingBaseComponent::clampAimIntentionTargetPositionDistance(UFG::AimingBaseComponent *this)
{
  UFG::SimComponent *v1; // rax
  __int64 v2; // rax
  float v3; // xmm7_4
  float v4; // xmm6_4
  float v5; // xmm8_4
  __m128 v6; // xmm4
  float v7; // xmm3_4
  float v8; // xmm5_4
  __m128 v9; // xmm2
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4

  v1 = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( LOBYTE(v1[8].m_BoundComponentHandles.mNode.mPrev) )
  {
    v6 = (__m128)LODWORD(this->m_vAimIntentionTargetPosition.y);
    v2 = *(_QWORD *)&v1[8].m_TypeUID;
    v3 = this->m_vAimOriginPosition.y;
    v4 = this->m_vAimOriginPosition.x;
    v5 = this->m_vAimOriginPosition.z;
    v6.m128_f32[0] = v6.m128_f32[0] - v3;
    v7 = this->m_vAimIntentionTargetPosition.x - v4;
    v8 = this->m_vAimIntentionTargetPosition.z - v5;
    v9 = v6;
    v9.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v7 * v7)) + (float)(v8 * v8);
    LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v9);
    if ( v2 )
      v11 = *(float *)(*(_QWORD *)(*(_QWORD *)(v2 + 176) + 8i64 * *(unsigned int *)(v2 + 172) + 8) + 40i64);
    else
      v11 = *(float *)&FLOAT_1_0;
    v12 = FLOAT_0_001;
    if ( v11 > 0.001 )
      v12 = v11;
    if ( v10 > v12 )
    {
      v13 = v11 / v10;
      this->m_vAimIntentionTargetPosition.x = v4 + (float)(v13 * v7);
      this->m_vAimIntentionTargetPosition.y = v3 + (float)(v13 * v6.m128_f32[0]);
      this->m_vAimIntentionTargetPosition.z = v5 + (float)(v13 * v8);
    }
  }
}

// File Line: 1118
// RVA: 0x570150
void __fastcall UFG::AimingBaseComponent::updateAimOriginPosition(UFG::AimingBaseComponent *this, UFG::qMatrix44 *matXform)
{
  UFG::AimingBaseComponent *v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rcx
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  UFG::SimComponent *v8; // rax
  Creature *v9; // rcx
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-78h]

  v2 = this;
  v3 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
  if ( v3
    && (v4 = *(_QWORD *)(*(_QWORD *)(v3 + 176) + 8i64 * *(unsigned int *)(v3 + 172) + 8),
        *(_DWORD *)(v4 + 100) != UFG::gNullQSymbolUC.mUID) )
  {
    v5 = *(float *)(v4 + 460);
    v6 = *(float *)(v4 + 464);
    v7 = *(float *)(v4 + 468);
    v8 = v2->m_CharacterAnimationComponent.m_pSimComponent;
    if ( v8 )
    {
      v9 = *(Creature **)&v8[2].m_TypeUID;
      if ( v9 )
      {
        Creature::GetTransform(v9, v2->m_iAimOriginBoneID, &transform);
        v10 = (float)((float)((float)(transform.v1.y * v6) + (float)(transform.v0.y * v5)) + (float)(transform.v2.y * v7))
            + transform.v3.y;
        v11 = (float)((float)((float)(transform.v1.z * v6) + (float)(transform.v0.z * v5)) + (float)(transform.v2.z * v7))
            + transform.v3.z;
        v2->m_vAimOriginPosition.x = (float)((float)((float)(transform.v1.x * v6) + (float)(transform.v0.x * v5))
                                           + (float)(transform.v2.x * v7))
                                   + transform.v3.x;
        v2->m_vAimOriginPosition.y = v10;
        v2->m_vAimOriginPosition.z = v11;
      }
    }
  }
  else
  {
    if ( !(_S58 & 1) )
    {
      _S58 |= 1u;
      *(_QWORD *)&s_vXformOffset.x = 0i64;
      s_vXformOffset.z = FLOAT_1_5;
    }
    v12 = s_vXformOffset.y + matXform->v3.y;
    v13 = s_vXformOffset.z + matXform->v3.z;
    v2->m_vAimOriginPosition.x = s_vXformOffset.x + matXform->v3.x;
    v2->m_vAimOriginPosition.y = v12;
    v2->m_vAimOriginPosition.z = v13;
  }
}

// File Line: 1144
// RVA: 0x56F930
void __fastcall UFG::AimingBaseComponent::updateAimIntention(UFG::AimingBaseComponent *this, const float fDeltaS)
{
  float v2; // xmm2_4
  __m128 v3; // xmm3
  float v4; // xmm4_4
  float v5; // xmm6_4
  __m128 v6; // xmm5

  v3 = (__m128)LODWORD(this->m_vAimIntentionTargetPosition.y);
  v2 = 0.0;
  v3.m128_f32[0] = v3.m128_f32[0] - this->m_vAimOriginPosition.y;
  v4 = this->m_vAimIntentionTargetPosition.z - this->m_vAimOriginPosition.z;
  v6 = v3;
  v5 = this->m_vAimIntentionTargetPosition.x - this->m_vAimOriginPosition.x;
  v6.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) + (float)(v5 * v5)) + (float)(v4 * v4);
  if ( v6.m128_f32[0] != 0.0 )
    v2 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
  this->m_vAimIntention.y = v3.m128_f32[0] * v2;
  this->m_vAimIntention.z = v4 * v2;
  this->m_vAimIntention.x = v2 * v5;
}

// File Line: 1219
// RVA: 0x5658D0
void __fastcall UFG::AimingBaseComponent::clampAimIntention(UFG::AimingBaseComponent *this, UFG::qMatrix44 *matXform)
{
  float xmm0_4_1; // xmm0_4
  float v3; // xmm1_4
  UFG::qMatrix44 *v4; // rdi
  UFG::AimingBaseComponent *v5; // rbx
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  __m128 v11; // xmm4
  float v12; // xmm5_4
  __m128 v13; // xmm2
  float v14; // xmm2_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm7_4
  float v18; // xmm4_4
  __m128 v19; // xmm5
  float v20; // xmm4_4
  __m128 v21; // xmm2
  UFG::qVector3 v2; // [rsp+20h] [rbp-88h]
  float v23; // [rsp+30h] [rbp-78h]
  float v24; // [rsp+34h] [rbp-74h]
  int v25; // [rsp+38h] [rbp-70h]
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-68h]

  xmm0_4_1 = matXform->v0.x;
  v3 = matXform->v0.y;
  v4 = matXform;
  v5 = this;
  v6 = 0.0;
  v25 = 0;
  v23 = xmm0_4_1;
  v7 = this->m_vAimIntention.x;
  v24 = v3;
  v8 = this->m_vAimIntention.y;
  v2.x = v7;
  v2.y = v8;
  v2.z = 0.0;
  v9 = UFG::qAngleBetween((UFG::qVector3 *)&v23, &v2);
  if ( v9 <= UFG::AimingBaseComponent::ms_fAimDirectionYawReset )
  {
    if ( v9 > UFG::AimingBaseComponent::ms_fAimDirectionYawClamp )
    {
      v14 = v9 - UFG::AimingBaseComponent::ms_fAimDirectionYawClamp;
      if ( v14 > 0.0 )
      {
        if ( (float)((float)((float)(v4->v1.y * v2.y) + (float)(v4->v1.x * v2.x)) + (float)(v2.z * 0.0)) > 0.0 )
          LODWORD(v14) ^= _xmm[0];
        UFG::qRotationMatrixZ(&dest, v14);
        v15 = v5->m_vAimIntention.y;
        v16 = v5->m_vAimIntention.x;
        v19 = (__m128)LODWORD(v5->m_vAimIntention.x);
        v17 = (float)((float)(v16 * dest.v0.x) + (float)(v5->m_vAimIntention.y * dest.v1.x))
            + (float)(v5->m_vAimIntention.z * dest.v2.x);
        v18 = (float)(v16 * dest.v0.z) + (float)(v15 * dest.v1.z);
        v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * dest.v0.y) + (float)(v15 * dest.v1.y))
                        + (float)(v5->m_vAimIntention.z * dest.v2.y);
        v21 = v19;
        v20 = v18 + (float)(v5->m_vAimIntention.z * dest.v2.z);
        v21.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v17 * v17)) + (float)(v20 * v20);
        if ( v21.m128_f32[0] != 0.0 )
          v6 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v21));
        v5->m_vAimIntention.x = v6 * v17;
        v5->m_vAimIntention.y = v19.m128_f32[0] * v6;
        v5->m_vAimIntention.z = v20 * v6;
      }
    }
  }
  else
  {
    v10 = v4->v0.x;
    v11 = (__m128)LODWORD(v4->v0.y);
    v12 = v4->v0.z;
    v13 = v11;
    v13.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10)) + (float)(v12 * v12);
    if ( v13.m128_f32[0] != 0.0 )
      v6 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
    v5->m_vAimIntention.x = v10 * v6;
    v5->m_vAimIntention.y = v11.m128_f32[0] * v6;
    v5->m_vAimIntention.z = v12 * v6;
  }
}

// File Line: 1257
// RVA: 0x56F270
void __fastcall UFG::AimingBaseComponent::updateAimDirection(UFG::AimingBaseComponent *this, const float fDeltaS, UFG::qMatrix44 *matXform)
{
  UFG::AimingBaseComponent *v3; // rdi
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm8_4
  float v8; // xmm10_4
  float v9; // xmm9_4
  float v10; // xmm13_4
  UFG::SimComponent *v11; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rsi
  float v13; // xmm0_4
  unsigned __int16 v14; // cx
  UFG::VehicleOccupantComponent *v15; // rbp
  float v16; // xmm6_4
  UFG::SimComponent *v17; // rbx
  unsigned int v18; // edx
  unsigned int v19; // er8
  signed __int64 v20; // rbx
  unsigned int v21; // edx
  unsigned int v22; // er8
  int v23; // edx
  __int64 v24; // rcx
  float v25; // xmm0_4
  float v26; // xmm6_4
  float v27; // xmm2_4
  float v28; // xmm7_4
  int v29; // edx
  __int64 v30; // rcx
  float v31; // xmm0_4
  float v32; // xmm11_4
  float v33; // xmm12_4
  float *v34; // rbx
  float v35; // xmm7_4
  float v36; // xmm11_4
  float v37; // xmm12_4
  float v38; // xmm2_4
  float v39; // xmm10_4
  float v40; // xmm14_4
  __m128 v41; // xmm2
  float v42; // xmm9_4
  float v43; // xmm5_4
  __m128 v44; // xmm3
  float v45; // xmm4_4
  __m128 v46; // xmm2
  float v47; // xmm6_4
  float v48; // xmm3_4
  __m128 v49; // xmm4
  float v50; // xmm5_4
  __m128 v51; // xmm2
  UFG::qVector3 axis; // [rsp+20h] [rbp-F8h]
  UFG::qQuaternion v53; // [rsp+30h] [rbp-E8h]
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-D8h]

  v3 = this;
  UFG::qTranspose(&dest, matXform);
  UFG::AimingBaseComponent::UpdateLocalAimDirection(v3, &dest, &v3->m_vAimPosition);
  v4 = v3->m_vAimIntention.y;
  v5 = v3->m_vAimIntention.x;
  v6 = v3->m_vAimIntention.z;
  v7 = 0.0;
  v8 = (float)((float)(dest.v0.x * v5) + (float)(dest.v1.x * v4)) + (float)(dest.v2.x * v6);
  v9 = (float)((float)(dest.v0.y * v5) + (float)(dest.v1.y * v4)) + (float)(dest.v2.y * v6);
  v10 = (float)((float)(dest.v0.z * v5) + (float)(dest.v1.z * v4)) + (float)(dest.v2.z * v6);
  if ( !v3->m_CharacterOccupantComponent.m_pSimComponent )
    goto LABEL_35;
  v11 = v3->m_CharacterOccupantComponent.m_pSimComponent;
  if ( !v11[1].m_BoundComponentHandles.mNode.mPrev )
    goto LABEL_35;
  v12 = v11[1].m_BoundComponentHandles.mNode.mPrev[2].mNext;
  if ( !v12 )
    goto LABEL_35;
  v13 = atan2f(v9, v8);
  v14 = WORD2(v12[4].mNext);
  v15 = (UFG::VehicleOccupantComponent *)v11[1].m_BoundComponentHandles.mNode.mPrev;
  v16 = v13;
  if ( !((v14 >> 14) & 1) )
  {
    if ( (v14 & 0x8000u) != 0 )
    {
      v17 = (UFG::SimComponent *)v12[6].mNext[3].mPrev;
      if ( !v17 || (UFG::SimObjectVehiclePropertiesComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000 )
        goto LABEL_8;
      if ( UFG::SimObjectVehiclePropertiesComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF )
        v17 = 0i64;
      goto LABEL_30;
    }
    if ( (v14 >> 13) & 1 )
    {
      v18 = (unsigned int)v12[8].mPrev;
      v19 = (unsigned int)v12[6].mPrev;
      if ( v18 < v19 )
      {
        v20 = (signed __int64)&v12[6].mNext[v18];
        while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectVehiclePropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectVehiclePropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF )
        {
          ++v18;
          v20 += 16i64;
          if ( v18 >= v19 )
          {
            v17 = 0i64;
            goto LABEL_30;
          }
        }
LABEL_21:
        v17 = *(UFG::SimComponent **)v20;
        goto LABEL_30;
      }
    }
    else
    {
      if ( !((v14 >> 12) & 1) )
      {
        v17 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)v12,
                UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
        goto LABEL_30;
      }
      v21 = (unsigned int)v12[8].mPrev;
      v22 = (unsigned int)v12[6].mPrev;
      if ( v21 < v22 )
      {
        v20 = (signed __int64)&v12[6].mNext[v21];
        while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectVehiclePropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectVehiclePropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF )
        {
          ++v21;
          v20 += 16i64;
          if ( v21 >= v22 )
          {
            v17 = 0i64;
            goto LABEL_30;
          }
        }
        goto LABEL_21;
      }
    }
LABEL_8:
    v17 = 0i64;
    goto LABEL_30;
  }
  v17 = (UFG::SimComponent *)v12[6].mNext[3].mPrev;
  if ( !v17
    || (UFG::SimObjectVehiclePropertiesComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000
    || UFG::SimObjectVehiclePropertiesComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF )
  {
    goto LABEL_8;
  }
LABEL_30:
  if ( v13 >= 0.0 )
  {
    v29 = HIDWORD(v3->m_CharacterOccupantComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    if ( v29 & 1 )
      goto LABEL_35;
    if ( !UFG::VehicleOccupantComponent::GetOccupant(v15, v29 + 1, 0i64) )
      goto LABEL_35;
    v30 = HIDWORD(v3->m_CharacterOccupantComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    if ( LODWORD(v17[2].m_BoundComponentHandles.mNode.mPrev) <= (unsigned int)v30 )
      goto LABEL_35;
    v25 = *((float *)&v17[2].m_BoundComponentHandles.mNode.mNext->mPrev + 2 * v30);
    if ( v25 >= v16 )
      goto LABEL_35;
  }
  else
  {
    v23 = HIDWORD(v3->m_CharacterOccupantComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    if ( !(v23 & 1) )
      goto LABEL_35;
    if ( !UFG::VehicleOccupantComponent::GetOccupant(v15, v23 - 1, 0i64) )
      goto LABEL_35;
    v24 = HIDWORD(v3->m_CharacterOccupantComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    if ( LODWORD(v17[2].m_BoundComponentHandles.mNode.mPrev) <= (unsigned int)v24 )
      goto LABEL_35;
    v25 = *((float *)&v17[2].m_BoundComponentHandles.mNode.mNext->mPrev + 2 * v24 + 1);
    if ( v25 <= v16 )
      goto LABEL_35;
  }
  if ( v25 == v16 )
  {
LABEL_35:
    v26 = *(float *)&FLOAT_1_0;
    goto LABEL_36;
  }
  v31 = tanf(v25);
  v26 = *(float *)&FLOAT_1_0;
  v8 = fsqrt((float)(v9 * v9) + (float)(v8 * v8)) / fsqrt((float)(v31 * v31) + 1.0);
  v9 = v8 * v31;
LABEL_36:
  v27 = (float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v10 * v10);
  if ( v27 == 0.0 )
    v28 = 0.0;
  else
    v28 = v26 / fsqrt(v27);
  v32 = v28;
  v33 = v28;
  v34 = &v3->m_vAimDirectionLS.x;
  v35 = v28 * v10;
  v36 = v32 * v8;
  v37 = v33 * v9;
  v38 = (float)((float)(v37 * v3->m_vAimDirectionLS.y) + (float)(v36 * v3->m_vAimDirectionLS.x))
      + (float)(v35 * v3->m_vAimDirectionLS.z);
  if ( v38 > v26 || v38 < -1.0 )
  {
    v39 = 0.0;
    goto LABEL_53;
  }
  if ( v38 <= -1.0 )
  {
    v38 = FLOAT_N1_0;
    goto LABEL_51;
  }
  if ( v38 < v26 )
  {
LABEL_51:
    v39 = acosf(v38);
    goto LABEL_53;
  }
  v39 = acosf(v26);
LABEL_53:
  v40 = fDeltaS * v3->m_fAimTransitionRadPerS;
  if ( (UFG::SimObjectCharacter *)v3->m_pSimObject == LocalPlayer )
  {
    v26 = *(float *)&FLOAT_1_0;
    if ( UFG::Metrics::IsTimeScaled(&UFG::Metrics::msInstance) )
      v40 = v40 * UFG::AimingBaseComponent::ms_fAimTransitionSlowModeMultiplier;
  }
  v41 = (__m128)LODWORD(v3->m_vAimOriginPosition.y);
  v41.m128_f32[0] = (float)((float)((float)(v41.m128_f32[0] - v3->m_vAimIntentionTargetPosition.y)
                                  * (float)(v41.m128_f32[0] - v3->m_vAimIntentionTargetPosition.y))
                          + (float)((float)(v3->m_vAimOriginPosition.x - v3->m_vAimIntentionTargetPosition.x)
                                  * (float)(v3->m_vAimOriginPosition.x - v3->m_vAimIntentionTargetPosition.x)))
                  + (float)((float)(v3->m_vAimOriginPosition.z - v3->m_vAimIntentionTargetPosition.z)
                          * (float)(v3->m_vAimOriginPosition.z - v3->m_vAimIntentionTargetPosition.z));
  LODWORD(v42) = (unsigned __int128)_mm_sqrt_ps(v41);
  if ( v3->m_fAimTransitionRadPerS < 0.0 || v39 <= v40 )
  {
    v3->m_fAimTransitionRadPerS = 2.0;
    v3->m_fAimTransitionMultiplier = 1.0;
    *v34 = v36;
    v3->m_vAimDirectionLS.y = v37;
    v3->m_vAimDirectionLS.z = v35;
    v3->m_fAimPositionDistance = v42;
  }
  else
  {
    v44 = (__m128)LODWORD(v3->m_vAimDirectionLS.z);
    v43 = (float)(v3->m_vAimDirectionLS.y * v35) - (float)(v44.m128_f32[0] * v37);
    v44.m128_f32[0] = (float)(v44.m128_f32[0] * v36) - (float)(*v34 * v35);
    v45 = (float)(*v34 * v37) - (float)(v3->m_vAimDirectionLS.y * v36);
    v46 = v44;
    v46.m128_f32[0] = (float)((float)(v44.m128_f32[0] * v44.m128_f32[0]) + (float)(v43 * v43)) + (float)(v45 * v45);
    if ( v46.m128_f32[0] == 0.0 )
      v47 = 0.0;
    else
      v47 = v26 / COERCE_FLOAT(_mm_sqrt_ps(v46));
    axis.x = v43 * v47;
    axis.y = v44.m128_f32[0] * v47;
    axis.z = v45 * v47;
    UFG::qQuaternion::Set(&v53, (float)((float)(v39 - v40) * 0.30000001) + v40, &axis);
    UFG::qQuaternion::Rotate(&v53, &v3->m_vAimDirectionLS);
    v48 = v3->m_vAimDirectionLS.y;
    v49 = (__m128)*(unsigned int *)v34;
    v50 = v3->m_vAimDirectionLS.z;
    v51 = v49;
    v51.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v48 * v48)) + (float)(v50 * v50);
    if ( v51.m128_f32[0] != 0.0 )
      v7 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v51));
    *v34 = v7 * v49.m128_f32[0];
    v3->m_vAimDirectionLS.y = v7 * v48;
    v3->m_vAimDirectionLS.z = v7 * v50;
    v3->m_fAimPositionDistance = (float)((float)(v42 - v3->m_fAimPositionDistance) * (float)(v40 / v39))
                               + v3->m_fAimPositionDistance;
    v3->m_fAimTransitionRadPerS = v3->m_fAimTransitionMultiplier * v3->m_fAimTransitionRadPerS;
  }
}

// File Line: 1362
// RVA: 0x570310
void __fastcall UFG::AimingBaseComponent::updateAimPosition(UFG::AimingBaseComponent *this, UFG::qMatrix44 *matXform)
{
  UFG::AimingBaseComponent *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  UFG::qVector3 vAimDirection; // [rsp+20h] [rbp-18h]

  v2 = this;
  UFG::AimingBaseComponent::GetAimDirection(this, &vAimDirection, matXform);
  v3 = v2->m_fAimPositionDistance;
  v4 = (float)(vAimDirection.y * v3) + v2->m_vAimOriginPosition.y;
  v5 = (float)(vAimDirection.z * v3) + v2->m_vAimOriginPosition.z;
  v2->m_vAimPosition.x = (float)(vAimDirection.x * v3) + v2->m_vAimOriginPosition.x;
  v2->m_vAimPosition.y = v4;
  v2->m_vAimPosition.z = v5;
}

// File Line: 1378
// RVA: 0x568780
void __fastcall UFG::AimingBaseComponent::getNeutralAimPosition(UFG::AimingBaseComponent *this, UFG::qVector3 *vNeutralAimPosition, UFG::qMatrix44 *matXform)
{
  UFG::SimComponent *v3; // rax
  __int64 v4; // rax
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm3_4

  v3 = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( LOBYTE(v3[8].m_BoundComponentHandles.mNode.mPrev) && (v4 = *(_QWORD *)&v3[8].m_TypeUID) != 0 )
    v5 = *(float *)(*(_QWORD *)(*(_QWORD *)(v4 + 176) + 8i64 * *(unsigned int *)(v4 + 172) + 8) + 40i64);
  else
    v5 = *(float *)&FLOAT_1_0;
  v6 = (float)(matXform->v0.y * v5) + this->m_vAimOriginPosition.y;
  v7 = (float)(matXform->v0.z * v5) + this->m_vAimOriginPosition.z;
  vNeutralAimPosition->x = (float)(matXform->v0.x * v5) + this->m_vAimOriginPosition.x;
  vNeutralAimPosition->y = v6;
  vNeutralAimPosition->z = v7;
}

// File Line: 1391
// RVA: 0x569120
void __fastcall UFG::AimingBaseComponent::getPredictedPositionOffset(UFG::AimingBaseComponent *this, UFG::qVector3 *vPredictedPositionOffset, UFG::SimObject *pSimObject, const float fWeaponProjectileSpeed, const float fAimIntentionTargetDistance)
{
  UFG::qVector3 *v5; // rdi
  UFG::TransformNodeComponent *v6; // rsi
  float *v7; // rbx
  float v8; // xmm1_4
  float v9; // xmm0_4

  v5 = vPredictedPositionOffset;
  if ( fWeaponProjectileSpeed <= 0.0 )
    goto LABEL_9;
  v6 = 0i64;
  if ( pSimObject )
    v6 = pSimObject->m_pTransformNodeComponent;
  if ( v6 )
  {
    v7 = (float *)this->m_TransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    v8 = (float)(v6->mWorldVelocity.y - v7[65]) * (float)(fAimIntentionTargetDistance / fWeaponProjectileSpeed);
    v9 = (float)(v6->mWorldVelocity.z - v7[66]) * (float)(fAimIntentionTargetDistance / fWeaponProjectileSpeed);
    v5->x = (float)(v6->mWorldVelocity.x - v7[64]) * (float)(fAimIntentionTargetDistance / fWeaponProjectileSpeed);
    v5->y = v8;
    v5->z = v9;
  }
  else
  {
LABEL_9:
    *(_QWORD *)&vPredictedPositionOffset->x = 0i64;
    vPredictedPositionOffset->z = 0.0;
  }
}

// File Line: 1418
// RVA: 0x521750
void __fastcall UFG::AimingBaseComponent::ApplyAccuracyModifiers(UFG::AimingBaseComponent *this, const bool bApplyToTargeter, float *fAccuracyModifierInstant, float *fAccuracyModifierContinuous)
{
  UEL::ParametersBase *v4; // r14
  UFG::AimingBaseComponent *v5; // rbx
  UFG::SimObject *v6; // rcx
  float *v7; // rdi
  float *v8; // rsi
  bool v9; // bp
  unsigned __int16 v10; // r10
  UEL::ParametersBase *v11; // rax
  unsigned int v12; // er8
  unsigned int v13; // er9
  signed __int64 v14; // rdx

  v4 = UEL::gCurrentParameters;
  v5 = this;
  v6 = this->m_pSimObject;
  v7 = fAccuracyModifierContinuous;
  v8 = fAccuracyModifierInstant;
  v9 = bApplyToTargeter;
  if ( v6 )
  {
    v10 = v6->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = (UEL::ParametersBase *)v6->m_Components.p->m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = (UEL::ParametersBase *)v6->m_Components.p->m_pComponent;
      }
      else if ( (v10 >> 12) & 1 )
      {
        v12 = (unsigned int)v6[1].vfptr;
        v13 = v6->m_Components.size;
        if ( v12 >= v13 )
        {
LABEL_14:
          v11 = 0i64;
        }
        else
        {
          v14 = (signed __int64)&v6->m_Components.p[v12];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
          {
            ++v12;
            v14 += 16i64;
            if ( v12 >= v13 )
              goto LABEL_14;
          }
          v11 = *(UEL::ParametersBase **)v14;
        }
      }
      else
      {
        v11 = (UEL::ParametersBase *)UFG::SimObject::GetComponentOfType(v6, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v11 = (UEL::ParametersBase *)v6->m_Components.p->m_pComponent;
    }
    if ( v11 )
      UEL::gCurrentParameters = v11 + 88;
  }
  UFG::AimingBaseComponent::Accuracy::ApplyAccuracyModifiers(&v5->m_Accuracy, v5, v9, v8, v7);
  UEL::gCurrentParameters = v4;
}

// File Line: 1430
// RVA: 0x521620
void __fastcall UFG::AimingBaseComponent::Accuracy::ApplyAccuracyModifiers(UFG::AimingBaseComponent::Accuracy *this, UFG::AimingBaseComponent *pABC, const bool bApplyToTargeter, float *fAccuracyModifierInstant, float *fAccuracyModifierContinuous)
{
  UFG::qVector3 *v5; // r15
  float *v6; // r14
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> **v7; // rbx
  bool v8; // r12
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *v9; // rdi
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *v10; // rax
  bool v11; // bp
  signed __int64 v12; // rcx
  float v13; // xmm0_4
  __int64 v14; // [rsp+30h] [rbp-38h]
  __int16 v15; // [rsp+44h] [rbp-24h]

  v5 = &pABC->m_vAimDirectionLS;
  v6 = fAccuracyModifierInstant;
  v7 = &pABC->m_AccuracyModifierTaskList.mNode.mNext[-3].mNext;
  v8 = bApplyToTargeter;
  if ( v7 != (UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> **)&pABC->m_vAimDirectionLS )
  {
    do
    {
      v9 = v7[3];
      if ( (BYTE1(v9[5].mPrev) != 0) == v8 )
      {
        v10 = v9[4].mPrev;
        v11 = LOBYTE(v9[5].mPrev) != 0;
        if ( v10
          && (v12 = (signed __int64)&v9[4] + (_QWORD)v10) != 0
          && ((*(void (__fastcall **)(signed __int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v12 + 24i64))(
                v12,
                &v14,
                UEL::gCurrentParameters,
                0i64,
                UEL::gCurrentStringBuilder),
              v15) )
        {
          if ( v15 == 4 )
            v13 = *(float *)&v14;
          else
            v13 = (float)(signed int)v14;
        }
        else
        {
          v13 = *(float *)&v9[4].mNext;
        }
        if ( v11 )
        {
          *fAccuracyModifierContinuous = v13 + *fAccuracyModifierContinuous;
        }
        else if ( (_BYTE)v7[8] & 1 )
        {
          *v6 = v13 + *v6;
          *((_BYTE *)v7 + 64) |= 2u;
        }
      }
      v7 = &v7[6][-3].mNext;
    }
    while ( v7 != (UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> **)v5 );
  }
}

// File Line: 1483
// RVA: 0x520840
void __fastcall UFG::AimingBaseComponent::AddAimingSoftLockDisableTask(UFG::AimingBaseComponent *this, AimingSoftLockDisableTask *pAimingSoftLockDisableTask)
{
  UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList> *v2; // rdx
  UFG::qList<AimingSoftLockDisableTask,AimingSoftLockDisableList,0,0> *v3; // rcx
  UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList> *v4; // rax

  v2 = (UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList> *)&pAimingSoftLockDisableTask->mPrev;
  v3 = &this->m_AimingSoftLockDisableList;
  v4 = v3->mNode.mPrev;
  v4->mNext = v2;
  v2->mPrev = v4;
  v2->mNext = &v3->mNode;
  v3->mNode.mPrev = v2;
}

