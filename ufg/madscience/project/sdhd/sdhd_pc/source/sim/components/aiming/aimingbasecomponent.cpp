// File Line: 75
// RVA: 0x1543D20
__int64 dynamic_initializer_for__UFG::AimingBaseComponent::s_AimingBaseComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AimingBaseComponent::s_AimingBaseComponentList__);
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
void __fastcall UFG::AimingBaseComponent::AimingBaseComponent(
        UFG::AimingBaseComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent>;
  this->mNext = &this->UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingBaseComponent::`vftable{for `UFG::UpdateInterface};
  this->m_fAimPositionDistance = 1.0;
  this->m_fAimTransitionRadPerS = 3.0;
  this->m_fAimTransitionMultiplier = 1.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vAimOriginPosition.x = UFG::qVector3::msZero.x;
  this->m_vAimOriginPosition.y = y;
  this->m_vAimOriginPosition.z = z;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  this->m_vAimIntentionTargetPosition.x = UFG::qVector3::msZero.x;
  this->m_vAimIntentionTargetPosition.y = v8;
  this->m_vAimIntentionTargetPosition.z = v9;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  this->m_vAimPosition.x = UFG::qVector3::msZero.x;
  this->m_vAimPosition.y = v10;
  this->m_vAimPosition.z = v11;
  v12 = UFG::qVector3::msAxisX.y;
  v13 = UFG::qVector3::msAxisX.z;
  this->m_vAimIntention.x = UFG::qVector3::msAxisX.x;
  this->m_vAimIntention.y = v12;
  this->m_vAimIntention.z = v13;
  v14 = UFG::qVector3::msAxisX.y;
  v15 = UFG::qVector3::msAxisX.z;
  this->m_vAimDirectionLS.x = UFG::qVector3::msAxisX.x;
  this->m_vAimDirectionLS.y = v14;
  this->m_vAimDirectionLS.z = v15;
  this->m_Accuracy.m_fAccuracyOverride = -1.0;
  this->m_Accuracy.m_bEnsureMiss = 0;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyUnclamped = 0i64;
  *(_QWORD *)&this->m_Accuracy.m_fAccuracyMaximum = 1065353216i64;
  this->m_AccuracyModifierTaskList.mNode.mPrev = &this->m_AccuracyModifierTaskList.mNode;
  this->m_AccuracyModifierTaskList.mNode.mNext = &this->m_AccuracyModifierTaskList.mNode;
  this->m_AimingSoftLockDisableList.mNode.mPrev = &this->m_AimingSoftLockDisableList.mNode;
  this->m_AimingSoftLockDisableList.mNode.mNext = &this->m_AimingSoftLockDisableList.mNode;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_TransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>(&this->m_pTargetingSystemPedBaseComponent);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->m_CharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>(&this->m_CharacterOccupantComponent);
  mPrev = UFG::AimingBaseComponent::s_AimingBaseComponentList.mNode.mPrev;
  UFG::AimingBaseComponent::s_AimingBaseComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *)&UFG::AimingBaseComponent::s_AimingBaseComponentList;
  UFG::AimingBaseComponent::s_AimingBaseComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent>;
  UFG::SimComponent::AddType(this, UFG::AimingBaseComponent::_AimingBaseComponentTypeUID, "AimingBaseComponent");
  if ( startSuspended )
    this->m_Flags |= 2u;
}

// File Line: 128
// RVA: 0x51A860
void __fastcall UFG::AimingBaseComponent::~AimingBaseComponent(UFG::AimingBaseComponent *this)
{
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v2; // rbx
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *mPrev; // rcx
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *mNext; // rax
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v5; // rcx
  UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent> *v6; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AimingBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::AimingBaseComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::AimingBaseComponent::s_AimingBaseComponentpCurrentIterator )
    UFG::AimingBaseComponent::s_AimingBaseComponentpCurrentIterator = (UFG::AimingBaseComponent *)&this->mPrev[-5].mNext;
  v2 = &this->UFG::qNode<UFG::AimingBaseComponent,UFG::AimingBaseComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_CharacterOccupantComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_CharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTargetingSystemPedBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->m_TransformNodeComponent);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&this->m_AimingSoftLockDisableList);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&this->m_AccuracyModifierTaskList);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 135
// RVA: 0x53CDB0
void __fastcall UFG::AimingBaseComponent::OnAttach(UFG::AimingBaseComponent *this, UFG::SimObject *pObject)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *p_m_pTargetingSystemPedBaseComponent; // rcx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_m_CharacterAnimationComponent; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *p_m_CharacterOccupantComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  int BoneID; // edx
  __int64 v21; // rcx
  UFG::SimObject *m_pSimObject; // r8
  __int16 m_Flags; // cx
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  UFG::allocator::free_link *v27; // [rsp+40h] [rbp+8h]

  p_m_pTargetingSystemPedBaseComponent = &this->m_pTargetingSystemPedBaseComponent;
  m_pComponent = 0i64;
  if ( p_m_pTargetingSystemPedBaseComponent->m_pSimComponent )
  {
    mPrev = p_m_pTargetingSystemPedBaseComponent->mPrev;
    mNext = p_m_pTargetingSystemPedBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemPedBaseComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_m_pTargetingSystemPedBaseComponent->m_pSimObject = 0i64;
    p_m_pTargetingSystemPedBaseComponent->mNext = p_m_pTargetingSystemPedBaseComponent;
    p_m_pTargetingSystemPedBaseComponent->mPrev = p_m_pTargetingSystemPedBaseComponent;
    goto LABEL_8;
  }
  if ( p_m_pTargetingSystemPedBaseComponent->m_pSimObject
    && (p_m_pTargetingSystemPedBaseComponent->mPrev != p_m_pTargetingSystemPedBaseComponent
     || p_m_pTargetingSystemPedBaseComponent->mNext != p_m_pTargetingSystemPedBaseComponent) )
  {
    v8 = p_m_pTargetingSystemPedBaseComponent->mPrev;
    v9 = p_m_pTargetingSystemPedBaseComponent->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pTargetingSystemPedBaseComponent->m_Changed = 1;
  p_m_pTargetingSystemPedBaseComponent->m_pSimObject = pObject;
  p_m_pTargetingSystemPedBaseComponent->m_TypeUID = UFG::TargetingSystemPedBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::BindInternal<UFG::SimObject>(
    p_m_pTargetingSystemPedBaseComponent,
    pObject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->m_TransformNodeComponent,
    pObject);
  p_m_CharacterAnimationComponent = &this->m_CharacterAnimationComponent;
  if ( this->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v11 = p_m_CharacterAnimationComponent->mPrev;
    v12 = this->m_CharacterAnimationComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    this->m_CharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_CharacterAnimationComponent.m_pSimObject = 0i64;
    this->m_CharacterAnimationComponent.mNext = &this->m_CharacterAnimationComponent;
    p_m_CharacterAnimationComponent->mPrev = p_m_CharacterAnimationComponent;
    goto LABEL_15;
  }
  if ( this->m_CharacterAnimationComponent.m_pSimObject
    && (p_m_CharacterAnimationComponent->mPrev != p_m_CharacterAnimationComponent
     || this->m_CharacterAnimationComponent.mNext != &this->m_CharacterAnimationComponent) )
  {
    v13 = p_m_CharacterAnimationComponent->mPrev;
    v14 = this->m_CharacterAnimationComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_14;
  }
LABEL_15:
  this->m_CharacterAnimationComponent.m_Changed = 1;
  this->m_CharacterAnimationComponent.m_pSimObject = pObject;
  this->m_CharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_CharacterAnimationComponent,
    pObject);
  p_m_CharacterOccupantComponent = &this->m_CharacterOccupantComponent;
  if ( this->m_CharacterOccupantComponent.m_pSimComponent )
  {
    v16 = p_m_CharacterOccupantComponent->mPrev;
    v17 = this->m_CharacterOccupantComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    this->m_CharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_CharacterOccupantComponent.m_pSimObject = 0i64;
    this->m_CharacterOccupantComponent.mNext = &this->m_CharacterOccupantComponent;
    p_m_CharacterOccupantComponent->mPrev = p_m_CharacterOccupantComponent;
    goto LABEL_22;
  }
  if ( this->m_CharacterOccupantComponent.m_pSimObject
    && (p_m_CharacterOccupantComponent->mPrev != p_m_CharacterOccupantComponent
     || this->m_CharacterOccupantComponent.mNext != &this->m_CharacterOccupantComponent) )
  {
    v18 = p_m_CharacterOccupantComponent->mPrev;
    v19 = this->m_CharacterOccupantComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_21;
  }
LABEL_22:
  this->m_CharacterOccupantComponent.m_Changed = 1;
  this->m_CharacterOccupantComponent.m_pSimObject = pObject;
  this->m_CharacterOccupantComponent.m_TypeUID = UFG::CharacterOccupantComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_CharacterOccupantComponent,
    pObject);
  BoneID = -1;
  this->m_iAimOriginBoneID = -1;
  if ( this->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v21 = *(_QWORD *)&this->m_CharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
    if ( v21 )
    {
      if ( *(_QWORD *)(v21 + 440) )
        BoneID = Skeleton::GetBoneID(
                   *(Skeleton **)(v21 + 480),
                   UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_BoneUIDAimOrigin.mUID);
      this->m_iAimOriginBoneID = BoneID;
    }
  }
  if ( this->m_iAimOriginBoneID < 0 )
    this->m_iAimOriginBoneID = 0;
  UFG::AimingBaseComponent::ms_fAimDirectionYawClamp = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fAimDirectionYawClamp;
  UFG::AimingBaseComponent::ms_fAimDirectionYawReset = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fAimDirectionYawReset;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          p = m_pSimObject->m_Components.p;
          while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
          {
            if ( ++vfptr >= size )
              goto LABEL_45;
          }
          m_pComponent = p[vfptr].m_pComponent;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(this->m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
LABEL_45:
    if ( m_pComponent )
    {
      v27 = UFG::qMalloc(8ui64, UFG::gGlobalNewName, 0i64);
      m_pComponent[2].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v27;
      v27->mNext = (UFG::allocator::free_link *)&this->m_vAimIntention;
    }
  }
}

// File Line: 172
// RVA: 0x53F960
void __fastcall UFG::AimingBaseComponent::OnDetach(UFG::AimingBaseComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v7; // rdx
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *p_m_pTargetingSystemPedBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_m_TransformNodeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_m_CharacterAnimationComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rax
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *p_m_CharacterOccupantComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_14:
          m_pComponent = 0i64;
        }
        else
        {
          v7 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v7 += 16i64;
            if ( vfptr >= size )
              goto LABEL_14;
          }
          m_pComponent = *(UFG::SimComponent **)v7;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
    {
      operator delete[](m_pComponent[2].m_BoundComponentHandles.mNode.mPrev);
      m_pComponent[2].m_BoundComponentHandles.mNode.mPrev = 0i64;
    }
  }
  p_m_pTargetingSystemPedBaseComponent = &this->m_pTargetingSystemPedBaseComponent;
  if ( this->m_pTargetingSystemPedBaseComponent.m_pSimComponent )
  {
    mPrev = p_m_pTargetingSystemPedBaseComponent->mPrev;
    mNext = this->m_pTargetingSystemPedBaseComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pTargetingSystemPedBaseComponent.m_pSimComponent = 0i64;
LABEL_25:
    this->m_pTargetingSystemPedBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemPedBaseComponent.mNext = &this->m_pTargetingSystemPedBaseComponent;
    p_m_pTargetingSystemPedBaseComponent->mPrev = p_m_pTargetingSystemPedBaseComponent;
    goto LABEL_26;
  }
  if ( this->m_pTargetingSystemPedBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemPedBaseComponent->mPrev != p_m_pTargetingSystemPedBaseComponent
     || this->m_pTargetingSystemPedBaseComponent.mNext != &this->m_pTargetingSystemPedBaseComponent) )
  {
    v11 = p_m_pTargetingSystemPedBaseComponent->mPrev;
    v12 = this->m_pTargetingSystemPedBaseComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    goto LABEL_25;
  }
LABEL_26:
  this->m_pTargetingSystemPedBaseComponent.m_Changed = 1;
  p_m_TransformNodeComponent = &this->m_TransformNodeComponent;
  if ( this->m_TransformNodeComponent.m_pSimComponent )
  {
    v14 = p_m_TransformNodeComponent->mPrev;
    v15 = this->m_TransformNodeComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    this->m_TransformNodeComponent.m_pSimComponent = 0i64;
LABEL_32:
    this->m_TransformNodeComponent.m_pSimObject = 0i64;
    this->m_TransformNodeComponent.mNext = &this->m_TransformNodeComponent;
    p_m_TransformNodeComponent->mPrev = p_m_TransformNodeComponent;
    goto LABEL_33;
  }
  if ( this->m_TransformNodeComponent.m_pSimObject
    && (p_m_TransformNodeComponent->mPrev != p_m_TransformNodeComponent
     || this->m_TransformNodeComponent.mNext != &this->m_TransformNodeComponent) )
  {
    v16 = p_m_TransformNodeComponent->mPrev;
    v17 = this->m_TransformNodeComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    goto LABEL_32;
  }
LABEL_33:
  this->m_TransformNodeComponent.m_Changed = 1;
  p_m_CharacterAnimationComponent = &this->m_CharacterAnimationComponent;
  if ( this->m_CharacterAnimationComponent.m_pSimComponent )
  {
    v19 = p_m_CharacterAnimationComponent->mPrev;
    v20 = this->m_CharacterAnimationComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    this->m_CharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_39:
    this->m_CharacterAnimationComponent.m_pSimObject = 0i64;
    this->m_CharacterAnimationComponent.mNext = &this->m_CharacterAnimationComponent;
    p_m_CharacterAnimationComponent->mPrev = p_m_CharacterAnimationComponent;
    goto LABEL_40;
  }
  if ( this->m_CharacterAnimationComponent.m_pSimObject
    && (p_m_CharacterAnimationComponent->mPrev != p_m_CharacterAnimationComponent
     || this->m_CharacterAnimationComponent.mNext != &this->m_CharacterAnimationComponent) )
  {
    v21 = p_m_CharacterAnimationComponent->mPrev;
    v22 = this->m_CharacterAnimationComponent.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    goto LABEL_39;
  }
LABEL_40:
  this->m_CharacterAnimationComponent.m_Changed = 1;
  p_m_CharacterOccupantComponent = &this->m_CharacterOccupantComponent;
  if ( this->m_CharacterOccupantComponent.m_pSimComponent )
  {
    v24 = p_m_CharacterOccupantComponent->mPrev;
    v25 = this->m_CharacterOccupantComponent.mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    this->m_CharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_46:
    this->m_CharacterOccupantComponent.m_pSimObject = 0i64;
    this->m_CharacterOccupantComponent.mNext = &this->m_CharacterOccupantComponent;
    p_m_CharacterOccupantComponent->mPrev = p_m_CharacterOccupantComponent;
    goto LABEL_47;
  }
  if ( this->m_CharacterOccupantComponent.m_pSimObject
    && (p_m_CharacterOccupantComponent->mPrev != p_m_CharacterOccupantComponent
     || this->m_CharacterOccupantComponent.mNext != &this->m_CharacterOccupantComponent) )
  {
    v26 = p_m_CharacterOccupantComponent->mPrev;
    v27 = this->m_CharacterOccupantComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    goto LABEL_46;
  }
LABEL_47:
  this->m_CharacterOccupantComponent.m_Changed = 1;
}v27 = this->m_CharacterOccupantComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    goto LABEL_46;
  }
LABEL_47:
  this->m_CharacterOccupantComponent.m_Changed 

// File Line: 190
// RVA: 0x52A750
void __fastcall UFG::AimingBaseComponent::GetAimDirection(
        UFG::AimingBaseComponent *this,
        UFG::qVector3 *vAimDirection,
        UFG::qMatrix44 *pXform)
{
  float v5; // xmm2_4
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  float x; // xmm2_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm4_4

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
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    x = this->m_vAimDirectionLS.x;
    v11 = (float)(x * m_pSimComponent->mWorldTransform.v0.z)
        + (float)(this->m_vAimDirectionLS.y * m_pSimComponent->mWorldTransform.v1.z);
    v12 = (float)(x * m_pSimComponent->mWorldTransform.v0.y)
        + (float)(this->m_vAimDirectionLS.y * m_pSimComponent->mWorldTransform.v1.y);
    v13 = this->m_vAimDirectionLS.z * m_pSimComponent->mWorldTransform.v2.y;
    v14 = this->m_vAimDirectionLS.z * m_pSimComponent->mWorldTransform.v2.z;
    vAimDirection->x = (float)((float)(this->m_vAimDirectionLS.y * m_pSimComponent->mWorldTransform.v1.x)
                             + (float)(this->m_vAimDirectionLS.x * m_pSimComponent->mWorldTransform.v0.x))
                     + (float)(this->m_vAimDirectionLS.z * m_pSimComponent->mWorldTransform.v2.x);
    vAimDirection->z = v11 + v14;
    vAimDirection->y = v12 + v13;
  }
}

// File Line: 205
// RVA: 0x532FC0
void __fastcall UFG::AimingBaseComponent::GetWeaponProjectileDirection(
        UFG::AimingBaseComponent *this,
        UFG::qVector3 *vWeaponProjectileDirection)
{
  float z; // xmm7_4
  float x; // xmm10_4
  float v6; // xmm8_4
  __m128 y_low; // xmm9
  float y; // xmm11_4
  float v9; // xmm12_4
  __int64 v10; // rax
  float v11; // xmm6_4
  bool IsAnyLocalPlayer; // al
  UFG::SimObjectWeaponPropertiesComponent *v13; // rcx
  float v14; // xmm3_4
  __m128 v15; // xmm2
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  __m128 v19; // xmm7
  float v20; // xmm8_4
  float v21; // xmm7_4
  __m128 v22; // xmm2
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+20h] [rbp-88h] BYREF

  z = UFG::qVector3::msZero.z;
  x = this->m_vAimIntentionTargetPosition.x;
  v6 = UFG::qVector3::msZero.x;
  y_low = (__m128)LODWORD(UFG::qVector3::msZero.y);
  y = this->m_vAimIntentionTargetPosition.y;
  v9 = this->m_vAimIntentionTargetPosition.z;
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(this, &vWeaponProjectileSpawnPosition);
  v10 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pTargetingSystemPedBaseComponent.m_pSimComponent->vfptr[19].__vecDelDtor)(this->m_pTargetingSystemPedBaseComponent.m_pSimComponent);
  v11 = 0.0;
  if ( !v10 || (unsigned int)(*(_DWORD *)(v10 + 3432) - 1) > 1 )
  {
    if ( LOBYTE(this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev)
      && (IsAnyLocalPlayer = UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject),
          (v13 = *(UFG::SimObjectWeaponPropertiesComponent **)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID) != 0i64) )
    {
      v14 = UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileSpeed(v13, !IsAnyLocalPlayer);
    }
    else
    {
      v14 = 0.0;
    }
    v15 = (__m128)LODWORD(this->m_vAimOriginPosition.y);
    v15.m128_f32[0] = v15.m128_f32[0] - this->m_vAimIntentionTargetPosition.y;
    v16 = this->m_vAimOriginPosition.x - this->m_vAimIntentionTargetPosition.x;
    v17 = this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z;
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent;
    v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v16 * v16)) + (float)(v17 * v17);
    v19 = _mm_sqrt_ps(v15);
    v19.m128_f32[0] = v19.m128_f32[0] / v14;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    y_low = v19;
    v6 = v19.m128_f32[0] * m_pSimComponent->mWorldVelocity.x;
    y_low.m128_f32[0] = v19.m128_f32[0] * m_pSimComponent->mWorldVelocity.y;
    z = v19.m128_f32[0] * m_pSimComponent->mWorldVelocity.z;
  }
  v20 = (float)(v6 + x) - vWeaponProjectileSpawnPosition.x;
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] + y) - vWeaponProjectileSpawnPosition.y;
  v21 = (float)(z + v9) - vWeaponProjectileSpawnPosition.z;
  v22 = y_low;
  v22.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v20 * v20)) + (float)(v21 * v21);
  if ( v22.m128_f32[0] != 0.0 )
    v11 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
  vWeaponProjectileDirection->x = v20 * v11;
  vWeaponProjectileDirection->y = y_low.m128_f32[0] * v11;
  vWeaponProjectileDirection->z = v21 * v11;
}

// File Line: 247
// RVA: 0x5331B0
void __fastcall UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(
        UFG::AimingBaseComponent *this,
        UFG::qVector3 *vWeaponProjectileSpawnPosition)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::SimObjectWeaponPropertiesComponent *v5; // rsi
  UFG::SimObjectProp *v6; // rcx
  __int16 v7; // dx
  UFG::CharacterAnimationComponent *v8; // rcx
  unsigned int v9; // r8d
  unsigned int m_TypeUID; // edx
  unsigned int v11; // eax
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int v14; // r10d
  __int64 v15; // rdx
  Creature *mCreature; // rbx
  int ProjectileSpawnBoneID; // eax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SimComponent *v20; // rsi
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *m_pComponent; // rbx
  unsigned int v24; // edx
  unsigned int v25; // r9d
  __int64 v26; // rbx
  unsigned int vfptr; // edx
  unsigned int size; // r9d
  unsigned int v29; // edx
  unsigned int v30; // r9d
  float Radius; // xmm7_4
  float Height; // xmm0_4
  UFG::SimComponent *v33; // rbx
  __m128 vfptr_low; // xmm3
  float v35; // xmm4_4
  __m128 v36; // xmm2
  float v37; // xmm7_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-68h] BYREF

  m_pSimComponent = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( !LOBYTE(m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev) )
  {
    v20 = this->m_TransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v20);
    m_pSimObject = this->m_pSimObject;
    if ( !m_pSimObject )
    {
LABEL_59:
      v39 = *((float *)&v20[2].m_BoundComponentHandles.mNode.mPrev + 1);
      v40 = *(float *)&v20[2].m_BoundComponentHandles.mNode.mNext;
      vWeaponProjectileSpawnPosition->x = *(float *)&v20[2].m_BoundComponentHandles.mNode.mPrev;
      vWeaponProjectileSpawnPosition->y = v39;
      vWeaponProjectileSpawnPosition->z = v40;
      return;
    }
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pSimObject->m_Components.p[27].m_pComponent;
      goto LABEL_57;
    }
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v26 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v26 += 16i64;
            if ( vfptr >= size )
            {
              m_pComponent = 0i64;
              goto LABEL_57;
            }
          }
          goto LABEL_41;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pSimObject,
                                                             UFG::CharacterPhysicsComponent::_TypeUID);
LABEL_57:
          if ( m_pComponent )
          {
            Radius = UFG::CharacterPhysicsComponent::GetRadius(m_pComponent);
            Height = UFG::CharacterPhysicsComponent::GetHeight(m_pComponent, m_pComponent->mCollisionModelType);
            v33 = this->m_TransformNodeComponent.m_pSimComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v33);
            vfptr_low = (__m128)LODWORD(v33[2].vfptr);
            v35 = *((float *)&v33[2].vfptr + 1);
            v36 = vfptr_low;
            v36.m128_f32[0] = (float)(vfptr_low.m128_f32[0] * vfptr_low.m128_f32[0]) + (float)(v35 * v35);
            v37 = Radius / _mm_sqrt_ps(v36).m128_f32[0];
            v36.m128_f32[0] = (float)(v37 * vfptr_low.m128_f32[0])
                            + *(float *)&v20[2].m_BoundComponentHandles.mNode.mPrev;
            v38 = (float)(v37 * v35) + *((float *)&v20[2].m_BoundComponentHandles.mNode.mPrev + 1);
            vWeaponProjectileSpawnPosition->z = (float)((float)(v37 * 0.0)
                                                      + *(float *)&v20[2].m_BoundComponentHandles.mNode.mNext)
                                              + (float)(Height * 0.5);
            LODWORD(vWeaponProjectileSpawnPosition->x) = v36.m128_i32[0];
            vWeaponProjectileSpawnPosition->y = v38;
            return;
          }
          goto LABEL_59;
        }
        v29 = (unsigned int)m_pSimObject[1].vfptr;
        v30 = m_pSimObject->m_Components.size;
        if ( v29 < v30 )
        {
          v26 = (__int64)&m_pSimObject->m_Components.p[v29];
          while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v29;
            v26 += 16i64;
            if ( v29 >= v30 )
            {
              m_pComponent = 0i64;
              goto LABEL_57;
            }
          }
          goto LABEL_41;
        }
      }
    }
    else
    {
      v24 = (unsigned int)m_pSimObject[1].vfptr;
      v25 = m_pSimObject->m_Components.size;
      if ( v24 < v25 )
      {
        v26 = (__int64)&m_pSimObject->m_Components.p[v24];
        while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
             || (UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v24;
          v26 += 16i64;
          if ( v24 >= v25 )
            goto LABEL_40;
        }
LABEL_41:
        m_pComponent = *(UFG::CharacterPhysicsComponent **)v26;
        goto LABEL_57;
      }
    }
LABEL_40:
    m_pComponent = 0i64;
    goto LABEL_57;
  }
  v5 = *(UFG::SimObjectWeaponPropertiesComponent **)&m_pSimComponent[8].m_TypeUID;
  if ( v5 )
    v6 = (UFG::SimObjectProp *)v5->m_pSimObject;
  else
    v6 = 0i64;
  if ( !v6 )
    goto LABEL_30;
  v7 = v6->m_Flags;
  if ( (v7 & 0x4000) == 0 )
  {
    if ( v7 < 0 )
    {
      v8 = (UFG::CharacterAnimationComponent *)v6->m_Components.p[9].m_pComponent;
      if ( v8 )
      {
        m_TypeUID = v8->m_TypeUID;
        v9 = UFG::CharacterAnimationComponent::_TypeUID;
        v11 = UFG::CharacterAnimationComponent::_TypeUID ^ m_TypeUID;
        goto LABEL_9;
      }
LABEL_11:
      v8 = 0i64;
      goto LABEL_27;
    }
    if ( (v7 & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v6);
    }
    else
    {
      if ( (v7 & 0x1000) != 0 )
      {
        mComponentTableEntryCount = v6->mComponentTableEntryCount;
        v14 = v6->m_Components.size;
        if ( mComponentTableEntryCount < v14 )
        {
          v15 = (__int64)&v6->m_Components.p[mComponentTableEntryCount];
          while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            v15 += 16i64;
            if ( mComponentTableEntryCount >= v14 )
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
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              v6,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    v8 = ComponentOfType;
    goto LABEL_27;
  }
  v8 = (UFG::CharacterAnimationComponent *)v6->m_Components.p[9].m_pComponent;
  if ( !v8 )
    goto LABEL_11;
  v9 = UFG::CharacterAnimationComponent::_TypeUID;
  m_TypeUID = v8->m_TypeUID;
  v11 = m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID;
LABEL_9:
  if ( (v11 & 0xFE000000) != 0 || (v9 & ~m_TypeUID & 0x1FFFFFF) != 0 )
    goto LABEL_11;
LABEL_27:
  if ( !v8 )
  {
LABEL_30:
    *(_QWORD *)&vWeaponProjectileSpawnPosition->x = 0i64;
    vWeaponProjectileSpawnPosition->z = 0.0;
    return;
  }
  mCreature = v8->mCreature;
  if ( mCreature )
  {
    ProjectileSpawnBoneID = UFG::SimObjectWeaponPropertiesComponent::GetProjectileSpawnBoneID(v5);
    Creature::GetTransform(mCreature, ProjectileSpawnBoneID, &transform);
    y = transform.v3.y;
    vWeaponProjectileSpawnPosition->x = transform.v3.x;
    z = transform.v3.z;
    vWeaponProjectileSpawnPosition->y = y;
    vWeaponProjectileSpawnPosition->z = z;
  }
}

// File Line: 321
// RVA: 0x5338E0
double __fastcall UFG::AimingBaseComponent::GetWeaponProjectileSpeed(UFG::AimingBaseComponent *this)
{
  bool IsAnyLocalPlayer; // al
  UFG::SimObjectWeaponPropertiesComponent *v3; // rcx
  double result; // xmm0_8

  if ( !LOBYTE(this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev) )
    return 0.0;
  IsAnyLocalPlayer = UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject);
  v3 = *(UFG::SimObjectWeaponPropertiesComponent **)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
  if ( !v3 )
    return 0.0;
  *(float *)&result = UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileSpeed(v3, !IsAnyLocalPlayer);
  return result;
}

// File Line: 338
// RVA: 0x52F860
float __fastcall UFG::AimingBaseComponent::GetRadialInaccuracyAtAimPosition(UFG::AimingBaseComponent *this)
{
  float v2; // xmm0_4
  __m128 y_low; // xmm3

  v2 = ((float (__fastcall *)(UFG::AimingBaseComponent *))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[19].__vecDelDtor)(this);
  y_low = (__m128)LODWORD(this->m_vAimOriginPosition.y);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.y)
                                    * (float)(y_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.y))
                            + (float)((float)(this->m_vAimOriginPosition.x - this->m_vAimIntentionTargetPosition.x)
                                    * (float)(this->m_vAimOriginPosition.x - this->m_vAimIntentionTargetPosition.x)))
                    + (float)((float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z)
                            * (float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z));
  return _mm_sqrt_ps(y_low).m128_f32[0] * tanf(v2);
}

// File Line: 348
// RVA: 0x52E290
float __fastcall UFG::AimingBaseComponent::GetLocalAimDirectionXY(UFG::AimingBaseComponent *this)
{
  float x; // xmm3_4
  __m128 y_low; // xmm4
  __m128 v3; // xmm1
  float v4; // xmm2_4
  float result; // xmm0_4
  bool v6; // cc

  x = this->m_vAimDirectionLS.x;
  y_low = (__m128)LODWORD(this->m_vAimDirectionLS.y);
  v3 = y_low;
  v3.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
  if ( v3.m128_f32[0] == 0.0 )
    v4 = 0.0;
  else
    v4 = 1.0 / _mm_sqrt_ps(v3).m128_f32[0];
  result = atan2f(COERCE_FLOAT(COERCE_UNSIGNED_INT(v4 * y_low.m128_f32[0]) ^ _xmm[0]), v4 * x);
  v6 = result <= 0.0;
  if ( result < 0.0 )
  {
    result = result + 6.2831855;
    v6 = result <= 0.0;
  }
  if ( v6 )
    return 0.0;
  if ( result >= 6.2831855 )
    return FLOAT_6_2831855;
  return result;
}

// File Line: 367
// RVA: 0x52E730
float __fastcall UFG::AimingBaseComponent::GetLocalAimDirectionXZ(UFG::AimingBaseComponent *this)
{
  __m128 y_low; // xmm2
  float result; // xmm0_4
  bool v3; // cc

  y_low = (__m128)LODWORD(this->m_vAimDirectionLS.y);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                    + (float)(this->m_vAimDirectionLS.x * this->m_vAimDirectionLS.x);
  result = atan2f(this->m_vAimDirectionLS.z, _mm_sqrt_ps(y_low).m128_f32[0]);
  v3 = result <= 0.0;
  if ( result < 0.0 )
  {
    result = result + 6.2831855;
    v3 = result <= 0.0;
  }
  if ( v3 )
    return 0.0;
  if ( result >= 6.2831855 )
    return FLOAT_6_2831855;
  return result;
}

// File Line: 386
// RVA: 0x52E330
float __fastcall UFG::AimingBaseComponent::GetLocalAimDirectionXYRelCover(UFG::AimingBaseComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  signed __int16 m_Flags; // dx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v6; // rdx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v8; // r8d
  unsigned int v9; // r9d
  unsigned int v10; // r8d
  unsigned int v11; // r9d
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rdi
  UFG::SimComponent *m_pSimComponent; // rbx
  _DWORD *v16; // rax
  int v17; // xmm3_4
  int v18; // xmm1_4
  float v19; // xmm6_4
  float result; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-38h] BYREF
  char v22[20]; // [rsp+2Ch] [rbp-2Ch] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !m_pSimObject )
    return 0.0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    mComponentTableEntryCount = m_pSimObject->mComponentTableEntryCount;
    size = m_pSimObject->m_Components.size;
    v6 = (UFG::SimComponentHolder *)mComponentTableEntryCount;
    if ( mComponentTableEntryCount < size )
    {
      v6 = &m_pSimObject->m_Components.p[mComponentTableEntryCount];
      while ( (v6->m_TypeUID & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
           || (UFG::AICoverComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++mComponentTableEntryCount;
        ++v6;
        if ( mComponentTableEntryCount >= size )
          goto LABEL_8;
      }
LABEL_9:
      m_pComponent = v6->m_pComponent;
      goto LABEL_32;
    }
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      v10 = m_pSimObject->mComponentTableEntryCount;
      v11 = m_pSimObject->m_Components.size;
      v6 = (UFG::SimComponentHolder *)v10;
      if ( v10 < v11 )
      {
        v6 = &m_pSimObject->m_Components.p[v10];
        while ( (v6->m_TypeUID & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
             || (UFG::AICoverComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v10;
          ++v6;
          if ( v10 >= v11 )
          {
            m_pComponent = 0i64;
            goto LABEL_32;
          }
        }
        goto LABEL_9;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AICoverComponent::_TypeUID);
        goto LABEL_32;
      }
      v12 = m_pSimObject->mComponentTableEntryCount;
      v13 = m_pSimObject->m_Components.size;
      v6 = (UFG::SimComponentHolder *)v12;
      if ( v12 < v13 )
      {
        v6 = &m_pSimObject->m_Components.p[v12];
        while ( (v6->m_TypeUID & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
             || (UFG::AICoverComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v12;
          ++v6;
          if ( v12 >= v13 )
          {
            m_pComponent = 0i64;
            goto LABEL_32;
          }
        }
        goto LABEL_9;
      }
    }
  }
  else
  {
    v8 = m_pSimObject->mComponentTableEntryCount;
    v9 = m_pSimObject->m_Components.size;
    v6 = (UFG::SimComponentHolder *)v8;
    if ( v8 < v9 )
    {
      v6 = &m_pSimObject->m_Components.p[v8];
      while ( (v6->m_TypeUID & 0xFE000000) != (UFG::AICoverComponent::_TypeUID & 0xFE000000)
           || (UFG::AICoverComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v8;
        ++v6;
        if ( v8 >= v9 )
        {
          m_pComponent = 0i64;
          goto LABEL_32;
        }
      }
      goto LABEL_9;
    }
  }
LABEL_8:
  m_pComponent = 0i64;
LABEL_32:
  if ( !m_pComponent )
    return 0.0;
  mNext = m_pComponent[1].m_BoundComponentHandles.mNode.mNext;
  if ( !mNext
    || !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::SimComponentHolder *))mNext->mPrev[1].mPrev)(
          mNext,
          v6) )
  {
    return 0.0;
  }
  m_pSimComponent = this->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
  v16 = (_DWORD *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, char *))mNext->mPrev[10].mPrev)(
                    mNext,
                    v22);
  v17 = v16[2] ^ _xmm[0];
  v18 = v16[1] ^ _xmm[0];
  LODWORD(v2.x) = *v16 ^ _xmm[0];
  LODWORD(v2.y) = v18;
  LODWORD(v2.z) = v17;
  v19 = UFG::qHeadingDifference2D((UFG::qVector3 *)&m_pSimComponent[2], &v2);
  result = UFG::AimingBaseComponent::GetLocalAimDirectionXY(this) + v19;
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
    return FLOAT_6_2831855;
  return result;
}

// File Line: 419
// RVA: 0x52E630
float __fastcall UFG::AimingBaseComponent::GetLocalAimDirectionXYRelSyncBone(UFG::AimingBaseComponent *this)
{
  __int64 rcx1; // rcx
  UFG::SimComponent *m_pSimComponent; // rbx
  float v4; // xmm6_4
  float result; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-68h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+30h] [rbp-58h] BYREF

  rcx1 = *(_QWORD *)&this->m_CharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
  if ( !rcx1 )
    return 0.0;
  SkeletalPose::GetPositionWS((SkeletalPose *)(rcx1 + 240), 3, &matrixWS);
  m_pSimComponent = this->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
  v2.x = matrixWS.v0.x;
  v2.y = matrixWS.v0.y;
  v2.z = matrixWS.v0.z;
  v4 = UFG::qHeadingDifference2D((UFG::qVector3 *)&m_pSimComponent[2], &v2);
  result = UFG::AimingBaseComponent::GetLocalAimDirectionXY(this) + v4;
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
    return FLOAT_6_2831855;
  return result;
}

// File Line: 451
// RVA: 0x530470
void __fastcall UFG::AimingBaseComponent::GetTargetNormalAimPosition(
        UFG::AimingBaseComponent *this,
        UFG::qVector3 *vTargetNormalAimPosition,
        unsigned int eTargetType,
        UFG::qMatrix44 *pXform)
{
  UFG::TargetingSystemPedBaseComponent *m_pSimComponent; // rcx
  UFG::qVector3 *v6; // rdi
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v8; // r10
  UFG::SimObjectProp *m_pPointer; // rbx
  UFG::SubTargetingProfile *SubTargetingProfileForTarget; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  UFG::qMatrix44 *p_mWorldTransform; // r8
  UFG::TransformNodeComponent *v16; // rbx
  UFG::qVector3 vDefaultTargetablePosWS; // [rsp+20h] [rbp-58h] BYREF
  UFG::qMatrix44 matSimObject; // [rsp+30h] [rbp-48h] BYREF

  m_pSimComponent = (UFG::TargetingSystemPedBaseComponent *)this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  v6 = vTargetNormalAimPosition;
  m_pTargets = m_pSimComponent->m_pTargets;
  v8 = (unsigned __int8)m_pSimComponent->m_pTargetingMap->m_Map.p[eTargetType];
  m_pPointer = (UFG::SimObjectProp *)m_pTargets[v8].m_pTarget.m_pPointer;
  if ( m_pPointer )
  {
    SubTargetingProfileForTarget = UFG::TargetingSystemPedBaseComponent::GetSubTargetingProfileForTarget(
                                     m_pSimComponent,
                                     m_pTargets[v8].m_pTarget.m_pPointer,
                                     eTargetType);
    if ( SubTargetingProfileForTarget
      && UFG::SubTargetingProfile::FindDefaultTargetablePosWS(
           SubTargetingProfileForTarget,
           &vDefaultTargetablePosWS,
           m_pPointer) )
    {
      y = vDefaultTargetablePosWS.y;
      v6->x = vDefaultTargetablePosWS.x;
      z = vDefaultTargetablePosWS.z;
      v6->y = y;
      v6->z = z;
    }
    else
    {
      UFG::TargetingSystemBaseComponent::FindMatrix(m_pPointer->m_pTransformNodeComponent, m_pPointer, &matSimObject);
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
      p_mWorldTransform = pXform;
    }
    else
    {
      v16 = (UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v16);
      p_mWorldTransform = &v16->mWorldTransform;
      vTargetNormalAimPosition = v6;
    }
    UFG::AimingBaseComponent::getNeutralAimPosition(this, vTargetNormalAimPosition, p_mWorldTransform);
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
void __fastcall UFG::AimingBaseComponent::AddAccuracyModifierTask(
        UFG::AimingBaseComponent *this,
        AccuracyModifierTask *pAccuracyModifierTask)
{
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *v2; // rdx
  UFG::qList<AccuracyModifierTask,AimingSystemAccuracyModifierList,0,0> *p_m_AccuracyModifierTaskList; // rcx
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *mPrev; // rax

  v2 = &pAccuracyModifierTask->UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList>;
  p_m_AccuracyModifierTaskList = &this->m_AccuracyModifierTaskList;
  mPrev = p_m_AccuracyModifierTaskList->mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &p_m_AccuracyModifierTaskList->mNode;
  p_m_AccuracyModifierTaskList->mNode.mPrev = v2;
}

// File Line: 525
// RVA: 0x5605C0
void __fastcall UFG::AimingBaseComponent::UpdateLocalAimDirection(
        UFG::AimingBaseComponent *this,
        UFG::qMatrix44 *matToLocal,
        UFG::qVector3 *vAimAtPosition)
{
  float v3; // xmm3_4
  __m128 y_low; // xmm5
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

  y_low = (__m128)LODWORD(vAimAtPosition->y);
  v3 = 0.0;
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->m_vAimOriginPosition.y;
  v5 = vAimAtPosition->z - this->m_vAimOriginPosition.z;
  v7 = y_low;
  v6 = vAimAtPosition->x - this->m_vAimOriginPosition.x;
  v7.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v6 * v6)) + (float)(v5 * v5);
  if ( v7.m128_f32[0] != 0.0 )
    v3 = 1.0 / _mm_sqrt_ps(v7).m128_f32[0];
  v8 = v5 * v3;
  v9 = y_low.m128_f32[0] * v3;
  v10 = v3 * v6;
  v11 = (float)((float)((float)(y_low.m128_f32[0] * v3) * matToLocal->v1.x)
              + (float)((float)(v3 * v6) * matToLocal->v0.x))
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
__int64 __fastcall UFG::AimingBaseComponent::couldShootSomeoneUnintendedHelper(
        UFG::AimingBaseComponent *this,
        UFG::qVector3 *vMyPosition,
        float fMaxDistance,
        float fAccuracyRad,
        UFG::qVector3 *vProjectileSpawnPos)
{
  UFG::AimingBaseComponent *v7; // rsi
  __int64 v8; // rbx
  UFG::qVector3 *v9; // r13
  char v10; // r12
  UFG::qVector3 *v11; // rdi
  __int64 v12; // rbx
  UFG::SimObject *v13; // rax
  UFG::TransformNodeComponent *MeshShape; // rax
  UFG::qMatrix44 *v15; // rsi
  float v16; // xmm0_4
  __m128 x_low; // xmm1
  UFG::HealthComponent *HealthComponent; // rax
  UFG::SimObjectCharacterPropertiesComponent *SimObjectCharacterPropertiesComponent; // rax
  UFG::eFactionClassEnum v20; // esi
  UFG::GameStatTracker *v21; // rax
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  float v24; // xmm1_4
  float v25; // xmm8_4
  float v26; // xmm7_4
  unsigned __int8 v27; // r8
  __int64 i; // rax
  _QWORD *v29; // rdx
  __int64 v30; // rcx
  _QWORD *v31; // rax
  __int64 v32; // rdx
  _QWORD *v33; // rcx
  UFG::qMatrix44 *pXform[2]; // [rsp+30h] [rbp-91h] BYREF
  UFG::qVector3 ray_pos_p; // [rsp+40h] [rbp-81h] BYREF
  UFG::qVector3 seg_pos_p; // [rsp+50h] [rbp-71h] BYREF
  UFG::qVector3 v2[4]; // [rsp+60h] [rbp-61h] BYREF
  _QWORD v39[16]; // [rsp+90h] [rbp-31h] BYREF
  UFG::qVector3 *retaddr; // [rsp+118h] [rbp+57h]
  UFG::eNearbyCharacterType character_type; // [rsp+128h] [rbp+67h] BYREF
  UFG::eFactionClassEnum source; // [rsp+130h] [rbp+6Fh]
  char v44; // [rsp+138h] [rbp+77h]

  pXform[1] = (UFG::qMatrix44 *)-2i64;
  v7 = this;
  *(_QWORD *)&v2[0].z = v39;
  *(_QWORD *)&v2[1].y = v39;
  UFG::NearbyCharacterManager::GetNearbyCharacters(
    UFG::NearbyCharacterManager::s_pInstance,
    (UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> *)&v2[0].z,
    character_type,
    vMyPosition);
  v8 = *(_QWORD *)&v2[1].y - 16i64;
  if ( (UFG::qVector3 *)(*(_QWORD *)&v2[1].y - 16i64) != (UFG::qVector3 *)&seg_pos_p.z )
  {
    v9 = vProjectileSpawnPos;
    v10 = v44;
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
            MeshShape = (UFG::TransformNodeComponent *)hkMemoryMeshBody::getMeshShape((hkMemoryMeshBody *)v12);
            v15 = (UFG::qMatrix44 *)MeshShape;
            if ( MeshShape )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(MeshShape);
              pXform[0] = v15 + 2;
              v16 = vMyPosition->y - v15[2].v3.y;
              x_low = (__m128)LODWORD(vMyPosition->x);
              x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - v15[2].v3.x)
                                                * (float)(x_low.m128_f32[0] - v15[2].v3.x))
                                        + (float)(v16 * v16))
                                + (float)((float)(vMyPosition->z - v15[2].v3.z) * (float)(vMyPosition->z - v15[2].v3.z));
              if ( fMaxDistance >= _mm_sqrt_ps(x_low).m128_f32[0] )
              {
                HealthComponent = UFG::AIEntityComponent::GetHealthComponent((UFG::AIEntityComponent *)v12);
                if ( !HealthComponent || !HealthComponent->m_bIsKnockedOut )
                {
                  SimObjectCharacterPropertiesComponent = UFG::AIEntityComponent::GetSimObjectCharacterPropertiesComponent((UFG::AIEntityComponent *)v12);
                  v20 = SimObjectCharacterPropertiesComponent
                      ? SimObjectCharacterPropertiesComponent->m_eFactionClass
                      : FACTION_INDIFFERENT;
                  v21 = UFG::FactionInterface::Get();
                  if ( (unsigned int)UFG::FactionInterface::GetStanding(&v21->mFactionInterface, source, v20) != 2
                    && (v10 || !UFG::IsHostage(*(UFG::SimObjectGame **)(v12 + 40))) )
                  {
                    *(float *)&character_type = 0.0;
                    if ( UFG::SimObjectUtility::GetObjectCapsuleApproximation(
                           *(UFG::SimObject **)(v12 + 40),
                           pXform,
                           (UFG::qVector3 *)&seg_pos_p.z,
                           (UFG::qVector3 *)&ray_pos_p.z,
                           (float *)&character_type) )
                    {
                      UFG::qNearestRaySeg(
                        retaddr,
                        (UFG::qVector3 *)this,
                        (UFG::qVector3 *)&seg_pos_p.z,
                        (UFG::qVector3 *)&ray_pos_p.z,
                        &ray_pos_p,
                        &seg_pos_p);
                      v22 = (__m128)LODWORD(ray_pos_p.x);
                      v22.m128_f32[0] = ray_pos_p.x - seg_pos_p.x;
                      v23 = v22;
                      v23.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0])
                                              + (float)((float)(ray_pos_p.y - seg_pos_p.y)
                                                      * (float)(ray_pos_p.y - seg_pos_p.y)))
                                      + (float)((float)(ray_pos_p.z - seg_pos_p.z) * (float)(ray_pos_p.z - seg_pos_p.z));
                      v24 = *(float *)&character_type / _mm_sqrt_ps(v23).m128_f32[0];
                      v25 = (float)((float)((float)(ray_pos_p.z - seg_pos_p.z) * v24) + seg_pos_p.z) - retaddr->z;
                      v26 = (float)((float)((float)(ray_pos_p.y - seg_pos_p.y) * v24) + seg_pos_p.y) - retaddr->y;
                      v2[0].x = (float)((float)((float)(ray_pos_p.x - seg_pos_p.x) * v24) + seg_pos_p.x) - retaddr->x;
                      v2[0].y = v26;
                      v2[0].z = v25;
                      if ( fAccuracyRad >= UFG::qAngleBetween((UFG::qVector3 *)this, v2) )
                      {
                        v27 = 1;
                        goto LABEL_24;
                      }
                    }
                  }
                }
              }
            }
            v7 = (UFG::AimingBaseComponent *)v39[13];
          }
        }
      }
      v8 = (__int64)v11;
    }
    while ( v11 != (UFG::qVector3 *)&seg_pos_p.z );
  }
  v27 = 0;
LABEL_24:
  for ( i = *(_QWORD *)&v2[1].y - 16i64;
        (UFG::qVector3 *)(*(_QWORD *)&v2[1].y - 16i64) != (UFG::qVector3 *)&seg_pos_p.z;
        i = *(_QWORD *)&v2[1].y - 16i64 )
  {
    v29 = (_QWORD *)(i + 16);
    v30 = *(_QWORD *)(i + 16);
    v31 = *(_QWORD **)(i + 24);
    *(_QWORD *)(v30 + 8) = v31;
    *v31 = v30;
    *v29 = v29;
    v29[1] = v29;
  }
  v32 = *(_QWORD *)&v2[0].z;
  v33 = *(_QWORD **)&v2[1].y;
  *(_QWORD *)(*(_QWORD *)&v2[0].z + 8i64) = *(_QWORD *)&v2[1].y;
  *v33 = v32;
  return v27;
}

// File Line: 734
// RVA: 0x523CE0
bool __fastcall UFG::AimingBaseComponent::CouldShootSomeoneUnintended(
        UFG::AimingBaseComponent *this,
        const bool bIncludePedestrians,
        bool bIncludeHostages)
{
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v7; // rsi
  __int64 v8; // rax
  float v9; // xmm6_4
  UFG::TransformNodeComponent *v10; // rbx
  unsigned int uMyFactionClassEnum; // r15d
  UFG::qVector4 *v12; // rbp
  double v13; // xmm0_8
  UFG::SimObject *pIntendedTargetSimObject; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 y_low; // xmm2
  float v17; // xmm1_4
  bool result; // al
  UFG::qVector3 vWeaponProjectileDirection; // [rsp+50h] [rbp-58h] BYREF
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+60h] [rbp-48h] BYREF

  m_pSimComponent = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return 0;
  v7 = *(_QWORD *)&m_pSimComponent[5].m_Flags;
  if ( !v7 )
    return 0;
  if ( LOBYTE(m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev)
    && (v8 = *(_QWORD *)&m_pSimComponent[8].m_TypeUID) != 0 )
  {
    v9 = *(float *)(*(_QWORD *)(*(_QWORD *)(v8 + 176) + 8i64 * *(unsigned int *)(v8 + 172) + 8) + 40i64);
  }
  else
  {
    v9 = *(float *)&FLOAT_1_0;
  }
  v10 = (UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v10);
  uMyFactionClassEnum = *(_DWORD *)(v7 + 200);
  v12 = &v10->mWorldTransform.v3;
  v13 = ((double (__fastcall *)(UFG::AimingBaseComponent *))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[19].__vecDelDtor)(this);
  UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(this, &vWeaponProjectileSpawnPosition);
  UFG::AimingBaseComponent::GetWeaponProjectileDirection(this, &vWeaponProjectileDirection);
  pIntendedTargetSimObject = *(UFG::SimObject **)(56i64
                                                * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[1].m_Flags
                                                                     + 30i64)
                                                + *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[1].m_TypeUID
                                                + 40);
  if ( !pIntendedTargetSimObject )
    return 0;
  m_pTransformNodeComponent = pIntendedTargetSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y_low = (__m128)LODWORD(v12->y);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                    * (float)(y_low.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y))
                            + (float)((float)(v12->x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                    * (float)(v12->x - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                    + (float)((float)(v12->z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                            * (float)(v12->z - m_pTransformNodeComponent->mWorldTransform.v3.z));
  v17 = _mm_sqrt_ps(y_low).m128_f32[0] + 2.0;
  if ( v9 >= v17 )
    v9 = v17;
  result = UFG::AimingBaseComponent::couldShootSomeoneUnintendedHelper(
             this,
             (UFG::qVector3 *)v12,
             v9,
             *(const float *)&v13,
             &vWeaponProjectileSpawnPosition,
             &vWeaponProjectileDirection,
             0,
             uMyFactionClassEnum,
             bIncludeHostages,
             pIntendedTargetSimObject);
  if ( !result && bIncludePedestrians )
    return UFG::AimingBaseComponent::couldShootSomeoneUnintendedHelper(
             this,
             (UFG::qVector3 *)v12,
             v9,
             *(const float *)&v13,
             &vWeaponProjectileSpawnPosition,
             &vWeaponProjectileDirection,
             1u,
             uMyFactionClassEnum,
             bIncludeHostages,
             pIntendedTargetSimObject);
  return result;
}

// File Line: 1098
// RVA: 0x565B10
void __fastcall UFG::AimingBaseComponent::clampAimIntentionTargetPositionDistance(UFG::AimingBaseComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v2; // rax
  float y; // xmm7_4
  float x; // xmm6_4
  float z; // xmm8_4
  __m128 y_low; // xmm4
  float v7; // xmm3_4
  float v8; // xmm5_4
  __m128 v9; // xmm2
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4

  m_pSimComponent = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( LOBYTE(m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev) )
  {
    y_low = (__m128)LODWORD(this->m_vAimIntentionTargetPosition.y);
    v2 = *(_QWORD *)&m_pSimComponent[8].m_TypeUID;
    y = this->m_vAimOriginPosition.y;
    x = this->m_vAimOriginPosition.x;
    z = this->m_vAimOriginPosition.z;
    y_low.m128_f32[0] = y_low.m128_f32[0] - y;
    v7 = this->m_vAimIntentionTargetPosition.x - x;
    v8 = this->m_vAimIntentionTargetPosition.z - z;
    v9 = y_low;
    v9.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v7 * v7)) + (float)(v8 * v8);
    LODWORD(v10) = _mm_sqrt_ps(v9).m128_u32[0];
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
      this->m_vAimIntentionTargetPosition.x = x + (float)(v13 * v7);
      this->m_vAimIntentionTargetPosition.y = y + (float)(v13 * y_low.m128_f32[0]);
      this->m_vAimIntentionTargetPosition.z = z + (float)(v13 * v8);
    }
  }
}

// File Line: 1118
// RVA: 0x570150
void __fastcall UFG::AimingBaseComponent::updateAimOriginPosition(
        UFG::AimingBaseComponent *this,
        UFG::qMatrix44 *matXform)
{
  __int64 v3; // rax
  __int64 v4; // rcx
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  UFG::SimComponent *m_pSimComponent; // rax
  Creature *v9; // rcx
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-78h] BYREF

  v3 = *(_QWORD *)&this->m_pTargetingSystemPedBaseComponent.m_pSimComponent[8].m_TypeUID;
  if ( !v3
    || (v4 = *(_QWORD *)(*(_QWORD *)(v3 + 176) + 8i64 * *(unsigned int *)(v3 + 172) + 8),
        *(_DWORD *)(v4 + 100) == UFG::gNullQSymbolUC.mUID) )
  {
    if ( (_S58 & 1) == 0 )
    {
      _S58 |= 1u;
      *(_QWORD *)&s_vXformOffset.x = 0i64;
      s_vXformOffset.z = FLOAT_1_5;
    }
    v12 = s_vXformOffset.y + matXform->v3.y;
    v13 = s_vXformOffset.z + matXform->v3.z;
    this->m_vAimOriginPosition.x = s_vXformOffset.x + matXform->v3.x;
    this->m_vAimOriginPosition.y = v12;
    this->m_vAimOriginPosition.z = v13;
  }
  else
  {
    v5 = *(float *)(v4 + 460);
    v6 = *(float *)(v4 + 464);
    v7 = *(float *)(v4 + 468);
    m_pSimComponent = this->m_CharacterAnimationComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      v9 = *(Creature **)&m_pSimComponent[2].m_TypeUID;
      if ( v9 )
      {
        Creature::GetTransform(v9, this->m_iAimOriginBoneID, &transform);
        v10 = (float)((float)((float)(transform.v1.y * v6) + (float)(transform.v0.y * v5)) + (float)(transform.v2.y * v7))
            + transform.v3.y;
        v11 = (float)((float)((float)(transform.v1.z * v6) + (float)(transform.v0.z * v5)) + (float)(transform.v2.z * v7))
            + transform.v3.z;
        this->m_vAimOriginPosition.x = (float)((float)((float)(transform.v1.x * v6) + (float)(transform.v0.x * v5))
                                             + (float)(transform.v2.x * v7))
                                     + transform.v3.x;
        this->m_vAimOriginPosition.y = v10;
        this->m_vAimOriginPosition.z = v11;
      }
    }
  }
}

// File Line: 1144
// RVA: 0x56F930
void __fastcall UFG::AimingBaseComponent::updateAimIntention(UFG::AimingBaseComponent *this, const float fDeltaS)
{
  float v2; // xmm2_4
  __m128 y_low; // xmm3
  float v4; // xmm4_4
  float v5; // xmm6_4
  __m128 v6; // xmm5

  y_low = (__m128)LODWORD(this->m_vAimIntentionTargetPosition.y);
  v2 = 0.0;
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->m_vAimOriginPosition.y;
  v4 = this->m_vAimIntentionTargetPosition.z - this->m_vAimOriginPosition.z;
  v6 = y_low;
  v5 = this->m_vAimIntentionTargetPosition.x - this->m_vAimOriginPosition.x;
  v6.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5)) + (float)(v4 * v4);
  if ( v6.m128_f32[0] != 0.0 )
    v2 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
  this->m_vAimIntention.y = y_low.m128_f32[0] * v2;
  this->m_vAimIntention.z = v4 * v2;
  this->m_vAimIntention.x = v2 * v5;
}

// File Line: 1219
// RVA: 0x5658D0
void __fastcall UFG::AimingBaseComponent::clampAimIntention(UFG::AimingBaseComponent *this, UFG::qMatrix44 *matXform)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  __m128 y_low; // xmm4
  float z; // xmm5_4
  __m128 v13; // xmm2
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm7_4
  __m128 v18; // xmm5
  float v19; // xmm4_4
  __m128 v20; // xmm2
  UFG::qVector3 v2; // [rsp+20h] [rbp-88h] BYREF
  UFG::qVector3 v22; // [rsp+30h] [rbp-78h] BYREF
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-68h] BYREF

  x = matXform->v0.x;
  y = matXform->v0.y;
  v6 = 0.0;
  v22.z = 0.0;
  v22.x = x;
  v7 = this->m_vAimIntention.x;
  v22.y = y;
  v8 = this->m_vAimIntention.y;
  v2.x = v7;
  v2.y = v8;
  v2.z = 0.0;
  v9 = UFG::qAngleBetween(&v22, &v2);
  if ( v9 <= UFG::AimingBaseComponent::ms_fAimDirectionYawReset )
  {
    if ( v9 > UFG::AimingBaseComponent::ms_fAimDirectionYawClamp )
    {
      v14 = v9 - UFG::AimingBaseComponent::ms_fAimDirectionYawClamp;
      if ( v14 > 0.0 )
      {
        if ( (float)((float)((float)(matXform->v1.y * v2.y) + (float)(matXform->v1.x * v2.x)) + (float)(v2.z * 0.0)) > 0.0 )
          LODWORD(v14) ^= _xmm[0];
        UFG::qRotationMatrixZ(&dest, v14);
        v15 = this->m_vAimIntention.x;
        v18 = (__m128)LODWORD(v15);
        v16 = this->m_vAimIntention.y;
        v17 = (float)((float)(v15 * dest.v0.x) + (float)(v16 * dest.v1.x))
            + (float)(this->m_vAimIntention.z * dest.v2.x);
        v18.m128_f32[0] = (float)((float)(v15 * dest.v0.y) + (float)(v16 * dest.v1.y))
                        + (float)(this->m_vAimIntention.z * dest.v2.y);
        v20 = v18;
        v19 = (float)((float)(v15 * dest.v0.z) + (float)(v16 * dest.v1.z))
            + (float)(this->m_vAimIntention.z * dest.v2.z);
        v20.m128_f32[0] = (float)((float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v17 * v17)) + (float)(v19 * v19);
        if ( v20.m128_f32[0] != 0.0 )
          v6 = 1.0 / _mm_sqrt_ps(v20).m128_f32[0];
        this->m_vAimIntention.x = v6 * v17;
        this->m_vAimIntention.y = v18.m128_f32[0] * v6;
        this->m_vAimIntention.z = v19 * v6;
      }
    }
  }
  else
  {
    v10 = matXform->v0.x;
    y_low = (__m128)LODWORD(matXform->v0.y);
    z = matXform->v0.z;
    v13 = y_low;
    v13.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v10 * v10)) + (float)(z * z);
    if ( v13.m128_f32[0] != 0.0 )
      v6 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
    this->m_vAimIntention.x = v10 * v6;
    this->m_vAimIntention.y = y_low.m128_f32[0] * v6;
    this->m_vAimIntention.z = z * v6;
  }
}

// File Line: 1257
// RVA: 0x56F270
void __fastcall UFG::AimingBaseComponent::updateAimDirection(
        UFG::AimingBaseComponent *this,
        const float fDeltaS,
        UFG::qMatrix44 *matXform)
{
  float y; // xmm3_4
  float x; // xmm2_4
  float z; // xmm4_4
  float v7; // xmm8_4
  float v8; // xmm10_4
  float v9; // xmm9_4
  float v10; // xmm13_4
  UFG::SimComponent *m_pSimComponent; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rsi
  float v13; // xmm0_4
  __int16 v14; // cx
  UFG::VehicleOccupantComponent *mPrev; // rbp
  float v16; // xmm6_4
  UFG::SimComponent *ComponentOfType; // rbx
  unsigned int v18; // edx
  unsigned int v19; // r8d
  __int64 v20; // rbx
  unsigned int v21; // edx
  unsigned int v22; // r8d
  int v23; // edx
  __int64 v24; // rcx
  float v25; // xmm0_4
  float v26; // xmm6_4
  float v27; // xmm2_4
  float v28; // xmm7_4
  int mNext_high; // edx
  __int64 v30; // rcx
  float v31; // xmm0_4
  float v32; // xmm11_4
  float v33; // xmm12_4
  UFG::qVector3 *p_m_vAimDirectionLS; // rbx
  float v35; // xmm7_4
  float v36; // xmm11_4
  float v37; // xmm12_4
  float v38; // xmm2_4
  float v39; // xmm10_4
  float v40; // xmm14_4
  __m128 y_low; // xmm2
  float v42; // xmm9_4
  float v43; // xmm5_4
  float v44; // xmm1_4
  float v45; // xmm5_4
  __m128 z_low; // xmm3
  float v47; // xmm4_4
  __m128 v48; // xmm2
  float v49; // xmm6_4
  float v50; // xmm3_4
  __m128 x_low; // xmm4
  float v52; // xmm5_4
  __m128 v53; // xmm2
  UFG::qVector3 axis; // [rsp+20h] [rbp-F8h] BYREF
  UFG::qQuaternion v55; // [rsp+30h] [rbp-E8h] BYREF
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-D8h] BYREF

  UFG::qTranspose(&dest, matXform);
  UFG::AimingBaseComponent::UpdateLocalAimDirection(this, &dest, &this->m_vAimPosition);
  y = this->m_vAimIntention.y;
  x = this->m_vAimIntention.x;
  z = this->m_vAimIntention.z;
  v7 = 0.0;
  v8 = (float)((float)(dest.v0.x * x) + (float)(dest.v1.x * y)) + (float)(dest.v2.x * z);
  v9 = (float)((float)(dest.v0.y * x) + (float)(dest.v1.y * y)) + (float)(dest.v2.y * z);
  v10 = (float)((float)(dest.v0.z * x) + (float)(dest.v1.z * y)) + (float)(dest.v2.z * z);
  if ( !this->m_CharacterOccupantComponent.m_pSimComponent )
    goto LABEL_35;
  m_pSimComponent = this->m_CharacterOccupantComponent.m_pSimComponent;
  if ( !m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev )
    goto LABEL_35;
  mNext = m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev[2].mNext;
  if ( !mNext )
    goto LABEL_35;
  v13 = atan2f(v9, v8);
  v14 = WORD2(mNext[4].mNext);
  mPrev = (UFG::VehicleOccupantComponent *)m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev;
  v16 = v13;
  if ( (v14 & 0x4000) == 0 )
  {
    if ( v14 < 0 )
    {
      ComponentOfType = (UFG::SimComponent *)mNext[6].mNext[3].mPrev;
      if ( !ComponentOfType
        || ((UFG::SimObjectVehiclePropertiesComponent::_TypeUID ^ ComponentOfType->m_TypeUID) & 0xFE000000) != 0 )
      {
        goto LABEL_8;
      }
      if ( (UFG::SimObjectVehiclePropertiesComponent::_TypeUID & ~ComponentOfType->m_TypeUID & 0x1FFFFFF) != 0 )
        ComponentOfType = 0i64;
      goto LABEL_30;
    }
    if ( (v14 & 0x2000) != 0 )
    {
      v18 = (unsigned int)mNext[8].mPrev;
      v19 = (unsigned int)mNext[6].mPrev;
      if ( v18 < v19 )
      {
        v20 = (__int64)&mNext[6].mNext[v18];
        while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectVehiclePropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectVehiclePropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v18;
          v20 += 16i64;
          if ( v18 >= v19 )
          {
            ComponentOfType = 0i64;
            goto LABEL_30;
          }
        }
LABEL_21:
        ComponentOfType = *(UFG::SimComponent **)v20;
        goto LABEL_30;
      }
    }
    else
    {
      if ( (v14 & 0x1000) == 0 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)mNext,
                            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
        goto LABEL_30;
      }
      v21 = (unsigned int)mNext[8].mPrev;
      v22 = (unsigned int)mNext[6].mPrev;
      if ( v21 < v22 )
      {
        v20 = (__int64)&mNext[6].mNext[v21];
        while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectVehiclePropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectVehiclePropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v21;
          v20 += 16i64;
          if ( v21 >= v22 )
          {
            ComponentOfType = 0i64;
            goto LABEL_30;
          }
        }
        goto LABEL_21;
      }
    }
LABEL_8:
    ComponentOfType = 0i64;
    goto LABEL_30;
  }
  ComponentOfType = (UFG::SimComponent *)mNext[6].mNext[3].mPrev;
  if ( !ComponentOfType
    || ((UFG::SimObjectVehiclePropertiesComponent::_TypeUID ^ ComponentOfType->m_TypeUID) & 0xFE000000) != 0
    || (UFG::SimObjectVehiclePropertiesComponent::_TypeUID & ~ComponentOfType->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    goto LABEL_8;
  }
LABEL_30:
  if ( v13 >= 0.0 )
  {
    mNext_high = HIDWORD(this->m_CharacterOccupantComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    if ( (mNext_high & 1) != 0 )
      goto LABEL_35;
    if ( !UFG::VehicleOccupantComponent::GetOccupant(mPrev, mNext_high + 1, 0i64) )
      goto LABEL_35;
    v30 = HIDWORD(this->m_CharacterOccupantComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    if ( LODWORD(ComponentOfType[2].m_BoundComponentHandles.mNode.mPrev) <= (unsigned int)v30 )
      goto LABEL_35;
    v25 = *((float *)&ComponentOfType[2].m_BoundComponentHandles.mNode.mNext->mPrev + 2 * v30);
    if ( v25 >= v16 )
      goto LABEL_35;
  }
  else
  {
    v23 = HIDWORD(this->m_CharacterOccupantComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    if ( (v23 & 1) == 0 )
      goto LABEL_35;
    if ( !UFG::VehicleOccupantComponent::GetOccupant(mPrev, v23 - 1, 0i64) )
      goto LABEL_35;
    v24 = HIDWORD(this->m_CharacterOccupantComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext);
    if ( LODWORD(ComponentOfType[2].m_BoundComponentHandles.mNode.mPrev) <= (unsigned int)v24 )
      goto LABEL_35;
    v25 = *((float *)&ComponentOfType[2].m_BoundComponentHandles.mNode.mNext->mPrev + 2 * v24 + 1);
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
  p_m_vAimDirectionLS = &this->m_vAimDirectionLS;
  v35 = v28 * v10;
  v36 = v32 * v8;
  v37 = v33 * v9;
  v38 = (float)((float)(v37 * this->m_vAimDirectionLS.y) + (float)(v36 * this->m_vAimDirectionLS.x))
      + (float)(v35 * this->m_vAimDirectionLS.z);
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
  v40 = fDeltaS * this->m_fAimTransitionRadPerS;
  if ( this->m_pSimObject == LocalPlayer )
  {
    v26 = *(float *)&FLOAT_1_0;
    if ( UFG::Metrics::IsTimeScaled(&UFG::Metrics::msInstance) )
      v40 = v40 * UFG::AimingBaseComponent::ms_fAimTransitionSlowModeMultiplier;
  }
  y_low = (__m128)LODWORD(this->m_vAimOriginPosition.y);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.y)
                                    * (float)(y_low.m128_f32[0] - this->m_vAimIntentionTargetPosition.y))
                            + (float)((float)(this->m_vAimOriginPosition.x - this->m_vAimIntentionTargetPosition.x)
                                    * (float)(this->m_vAimOriginPosition.x - this->m_vAimIntentionTargetPosition.x)))
                    + (float)((float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z)
                            * (float)(this->m_vAimOriginPosition.z - this->m_vAimIntentionTargetPosition.z));
  LODWORD(v42) = _mm_sqrt_ps(y_low).m128_u32[0];
  if ( this->m_fAimTransitionRadPerS < 0.0 || v39 <= v40 )
  {
    this->m_fAimTransitionRadPerS = 2.0;
    this->m_fAimTransitionMultiplier = 1.0;
    p_m_vAimDirectionLS->x = v36;
    this->m_vAimDirectionLS.y = v37;
    this->m_vAimDirectionLS.z = v35;
    this->m_fAimPositionDistance = v42;
  }
  else
  {
    z_low = (__m128)LODWORD(this->m_vAimDirectionLS.z);
    v43 = this->m_vAimDirectionLS.y;
    v44 = v43 * v36;
    v45 = (float)(v43 * v35) - (float)(z_low.m128_f32[0] * v37);
    z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v36) - (float)(p_m_vAimDirectionLS->x * v35);
    v47 = (float)(p_m_vAimDirectionLS->x * v37) - v44;
    v48 = z_low;
    v48.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v45 * v45)) + (float)(v47 * v47);
    if ( v48.m128_f32[0] == 0.0 )
      v49 = 0.0;
    else
      v49 = v26 / _mm_sqrt_ps(v48).m128_f32[0];
    axis.x = v45 * v49;
    axis.y = z_low.m128_f32[0] * v49;
    axis.z = v47 * v49;
    UFG::qQuaternion::Set(&v55, (float)((float)(v39 - v40) * 0.30000001) + v40, &axis);
    UFG::qQuaternion::Rotate(&v55, &this->m_vAimDirectionLS);
    v50 = this->m_vAimDirectionLS.y;
    x_low = (__m128)LODWORD(p_m_vAimDirectionLS->x);
    v52 = this->m_vAimDirectionLS.z;
    v53 = x_low;
    v53.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v50 * v50)) + (float)(v52 * v52);
    if ( v53.m128_f32[0] != 0.0 )
      v7 = 1.0 / _mm_sqrt_ps(v53).m128_f32[0];
    p_m_vAimDirectionLS->x = v7 * x_low.m128_f32[0];
    this->m_vAimDirectionLS.y = v7 * v50;
    this->m_vAimDirectionLS.z = v7 * v52;
    this->m_fAimPositionDistance = (float)((float)(v42 - this->m_fAimPositionDistance) * (float)(v40 / v39))
                                 + this->m_fAimPositionDistance;
    this->m_fAimTransitionRadPerS = this->m_fAimTransitionMultiplier * this->m_fAimTransitionRadPerS;
  }
}

// File Line: 1362
// RVA: 0x570310
void __fastcall UFG::AimingBaseComponent::updateAimPosition(UFG::AimingBaseComponent *this, UFG::qMatrix44 *matXform)
{
  float m_fAimPositionDistance; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  UFG::qVector3 vAimDirection; // [rsp+20h] [rbp-18h] BYREF

  UFG::AimingBaseComponent::GetAimDirection(this, &vAimDirection, matXform);
  m_fAimPositionDistance = this->m_fAimPositionDistance;
  v4 = (float)(vAimDirection.y * m_fAimPositionDistance) + this->m_vAimOriginPosition.y;
  v5 = (float)(vAimDirection.z * m_fAimPositionDistance) + this->m_vAimOriginPosition.z;
  this->m_vAimPosition.x = (float)(vAimDirection.x * m_fAimPositionDistance) + this->m_vAimOriginPosition.x;
  this->m_vAimPosition.y = v4;
  this->m_vAimPosition.z = v5;
}

// File Line: 1378
// RVA: 0x568780
void __fastcall UFG::AimingBaseComponent::getNeutralAimPosition(
        UFG::AimingBaseComponent *this,
        UFG::qVector3 *vNeutralAimPosition,
        UFG::qMatrix44 *matXform)
{
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v4; // rax
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm3_4

  m_pSimComponent = this->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( LOBYTE(m_pSimComponent[8].m_BoundComponentHandles.mNode.mPrev)
    && (v4 = *(_QWORD *)&m_pSimComponent[8].m_TypeUID) != 0 )
  {
    v5 = *(float *)(*(_QWORD *)(*(_QWORD *)(v4 + 176) + 8i64 * *(unsigned int *)(v4 + 172) + 8) + 40i64);
  }
  else
  {
    v5 = *(float *)&FLOAT_1_0;
  }
  v6 = (float)(matXform->v0.y * v5) + this->m_vAimOriginPosition.y;
  v7 = (float)(matXform->v0.z * v5) + this->m_vAimOriginPosition.z;
  vNeutralAimPosition->x = (float)(matXform->v0.x * v5) + this->m_vAimOriginPosition.x;
  vNeutralAimPosition->y = v6;
  vNeutralAimPosition->z = v7;
}

// File Line: 1391
// RVA: 0x569120
void __fastcall UFG::AimingBaseComponent::getPredictedPositionOffset(
        UFG::AimingBaseComponent *this,
        UFG::qVector3 *vPredictedPositionOffset,
        UFG::SimObject *pSimObject,
        float fWeaponProjectileSpeed,
        float fAimIntentionTargetDistance)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  float v8; // xmm1_4
  float v9; // xmm0_4

  if ( fWeaponProjectileSpeed <= 0.0 )
    goto LABEL_6;
  m_pTransformNodeComponent = 0i64;
  if ( pSimObject )
    m_pTransformNodeComponent = pSimObject->m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_TransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v8 = (float)(m_pTransformNodeComponent->mWorldVelocity.y - m_pSimComponent->mWorldVelocity.y)
       * (float)(fAimIntentionTargetDistance / fWeaponProjectileSpeed);
    v9 = (float)(m_pTransformNodeComponent->mWorldVelocity.z - m_pSimComponent->mWorldVelocity.z)
       * (float)(fAimIntentionTargetDistance / fWeaponProjectileSpeed);
    vPredictedPositionOffset->x = (float)(m_pTransformNodeComponent->mWorldVelocity.x - m_pSimComponent->mWorldVelocity.x)
                                * (float)(fAimIntentionTargetDistance / fWeaponProjectileSpeed);
    vPredictedPositionOffset->y = v8;
    vPredictedPositionOffset->z = v9;
  }
  else
  {
LABEL_6:
    *(_QWORD *)&vPredictedPositionOffset->x = 0i64;
    vPredictedPositionOffset->z = 0.0;
  }
}

// File Line: 1418
// RVA: 0x521750
void __fastcall UFG::AimingBaseComponent::ApplyAccuracyModifiers(
        UFG::AimingBaseComponent *this,
        bool bApplyToTargeter,
        float *fAccuracyModifierInstant,
        float *fAccuracyModifierContinuous)
{
  UEL::ParametersBase *v4; // r14
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // r10
  UEL::ParametersBase *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v14; // rdx

  v4 = UEL::gCurrentParameters;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_14:
          m_pComponent = 0i64;
        }
        else
        {
          v14 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v14 += 16i64;
            if ( vfptr >= size )
              goto LABEL_14;
          }
          m_pComponent = *(UEL::ParametersBase **)v14;
        }
      }
      else
      {
        m_pComponent = (UEL::ParametersBase *)UFG::SimObject::GetComponentOfType(
                                                m_pSimObject,
                                                UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
      UEL::gCurrentParameters = m_pComponent + 88;
  }
  UFG::AimingBaseComponent::Accuracy::ApplyAccuracyModifiers(
    &this->m_Accuracy,
    this,
    bApplyToTargeter,
    fAccuracyModifierInstant,
    fAccuracyModifierContinuous);
  UEL::gCurrentParameters = v4;
}

// File Line: 1430
// RVA: 0x521620
void __fastcall UFG::AimingBaseComponent::Accuracy::ApplyAccuracyModifiers(
        UFG::AimingBaseComponent::Accuracy *this,
        UFG::AimingBaseComponent *pABC,
        const bool bApplyToTargeter,
        float *fAccuracyModifierInstant,
        float *fAccuracyModifierContinuous)
{
  UFG::qVector3 *p_m_vAimDirectionLS; // r15
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> **p_mNext; // rbx
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *v9; // rdi
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *mPrev; // rax
  bool v11; // bp
  __int64 v12; // rcx
  float v13; // xmm0_4
  __int64 v14; // [rsp+30h] [rbp-38h] BYREF
  __int16 v15; // [rsp+44h] [rbp-24h]

  p_m_vAimDirectionLS = &pABC->m_vAimDirectionLS;
  p_mNext = &pABC->m_AccuracyModifierTaskList.mNode.mNext[-3].mNext;
  if ( p_mNext != (UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> **)&pABC->m_vAimDirectionLS )
  {
    do
    {
      v9 = p_mNext[3];
      if ( (BYTE1(v9[5].mPrev) != 0) == bApplyToTargeter )
      {
        mPrev = v9[4].mPrev;
        v11 = LOBYTE(v9[5].mPrev) != 0;
        if ( mPrev
          && (v12 = (__int64)&v9[4] + (_QWORD)mPrev) != 0
          && ((*(void (__fastcall **)(__int64, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v12 + 24i64))(
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
            v13 = (float)(int)v14;
        }
        else
        {
          v13 = *(float *)&v9[4].mNext;
        }
        if ( v11 )
        {
          *fAccuracyModifierContinuous = v13 + *fAccuracyModifierContinuous;
        }
        else if ( ((_BYTE)p_mNext[8] & 1) != 0 )
        {
          *fAccuracyModifierInstant = v13 + *fAccuracyModifierInstant;
          *((_BYTE *)p_mNext + 64) |= 2u;
        }
      }
      p_mNext = &p_mNext[6][-3].mNext;
    }
    while ( p_mNext != (UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> **)p_m_vAimDirectionLS );
  }
}

// File Line: 1483
// RVA: 0x520840
void __fastcall UFG::AimingBaseComponent::AddAimingSoftLockDisableTask(
        UFG::AimingBaseComponent *this,
        AimingSoftLockDisableTask *pAimingSoftLockDisableTask)
{
  UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList> *v2; // rdx
  UFG::qList<AimingSoftLockDisableTask,AimingSoftLockDisableList,0,0> *p_m_AimingSoftLockDisableList; // rcx
  UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList> *mPrev; // rax

  v2 = &pAimingSoftLockDisableTask->UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList>;
  p_m_AimingSoftLockDisableList = &this->m_AimingSoftLockDisableList;
  mPrev = p_m_AimingSoftLockDisableList->mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &p_m_AimingSoftLockDisableList->mNode;
  p_m_AimingSoftLockDisableList->mNode.mPrev = v2;
}

