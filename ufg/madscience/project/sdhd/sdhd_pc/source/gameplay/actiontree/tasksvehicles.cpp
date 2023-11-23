// File Line: 60
// RVA: 0x2FC3C0
void __fastcall VehicleSetDoorsLockedTask::Begin(VehicleSetDoorsLockedTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rcx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
        m_pComponent->mDoorsLocked = LOBYTE(this->m_Track[1].vfptr) != 0;
    }
  }
}

// File Line: 70
// RVA: 0x2E84D0
void __fastcall AiDriverSteeringWobbleTask::Begin(AiDriverSteeringWobbleTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::AiDriverComponent *v6; // rax
  UFG::AiDriverComponent *v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *Texture; // rax
  __int16 v12; // dx
  UFG::AiDriverComponent *v13; // rax
  ITrack *m_Track; // rax
  float v15; // xmm6_4

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    else
      v6 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        m_pPointer,
                                        UFG::AiDriverComponent::_TypeUID)
                                    : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AiDriverComponent::_TypeUID));
    v7 = v6;
    if ( v6 )
      goto LABEL_29;
  }
  v8 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v8 )
    return;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    goto LABEL_17;
  if ( v9 < 0 )
  {
    m_pComponent = v8->m_Components.p[30].m_pComponent;
    goto LABEL_19;
  }
  if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
LABEL_17:
    m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
  else
    m_pComponent = UFG::SimObject::GetComponentOfType(v8, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_19:
  if ( m_pComponent )
  {
    Texture = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
    if ( Texture )
    {
      v12 = Texture->m_Flags;
      if ( (v12 & 0x4000) != 0 || v12 < 0 )
        v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(Texture);
      else
        v13 = (UFG::AiDriverComponent *)((v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           Texture,
                                           UFG::AiDriverComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(Texture, UFG::AiDriverComponent::_TypeUID));
      v7 = v13;
      if ( v13 )
      {
LABEL_29:
        m_Track = this->m_Track;
        if ( BYTE4(m_Track[1].vfptr) )
        {
          v15 = *(float *)&m_Track[1].vfptr;
          UFG::AiDriverComponent::AddSteeringNoise(v7, v15);
          if ( BYTE5(this->m_Track[1].vfptr) )
            UFG::AiDriverComponent::SetSteeringNoiseMin(v7, v15);
        }
        else
        {
          UFG::AiDriverComponent::ClearSteeringNoise(v7);
        }
      }
    }
  }
}

// File Line: 97
// RVA: 0x2E82E0
void __fastcall AiDriverSteeringLockTask::Begin(AiDriverSteeringLockTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::AiDriverComponent *v6; // rax
  UFG::AiDriverComponent *v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *Texture; // rax
  __int16 v12; // dx
  UFG::AiDriverComponent *v13; // rax
  ITrack *m_Track; // rax
  float v15; // xmm6_4
  float v16; // xmm0_4

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    else
      v6 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        m_pPointer,
                                        UFG::AiDriverComponent::_TypeUID)
                                    : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AiDriverComponent::_TypeUID));
    v7 = v6;
    if ( v6 )
      goto LABEL_29;
  }
  v8 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v8 )
    return;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    goto LABEL_17;
  if ( v9 < 0 )
  {
    m_pComponent = v8->m_Components.p[30].m_pComponent;
    goto LABEL_19;
  }
  if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
LABEL_17:
    m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
  else
    m_pComponent = UFG::SimObject::GetComponentOfType(v8, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_19:
  if ( m_pComponent )
  {
    Texture = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
    if ( Texture )
    {
      v12 = Texture->m_Flags;
      if ( (v12 & 0x4000) != 0 || v12 < 0 )
        v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(Texture);
      else
        v13 = (UFG::AiDriverComponent *)((v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           Texture,
                                           UFG::AiDriverComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(Texture, UFG::AiDriverComponent::_TypeUID));
      v7 = v13;
      if ( v13 )
      {
LABEL_29:
        m_Track = this->m_Track;
        if ( BYTE4(m_Track[1].vfptr) )
        {
          v16 = *(float *)&m_Track[1].vfptr;
          if ( BYTE5(m_Track[1].vfptr) )
          {
            v15 = *(float *)&m_Track[1].vfptr;
            v16 = UFG::qRandom(v16 * 2.0, (unsigned int *)&UFG::qDefaultSeed) - v15;
          }
          UFG::AiDriverComponent::SetSteeringLock(v7, v16);
        }
        else
        {
          UFG::AiDriverComponent::ClearSteeringLock(v7);
        }
      }
    }
  }
}

// File Line: 130
// RVA: 0x2E80B0
void __fastcall AiDriverGasBrakeLockTask::Begin(AiDriverGasBrakeLockTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 v5; // r8
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::AiDriverComponent *v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *Texture; // rax
  __int16 v12; // dx
  UFG::AiDriverComponent *v13; // rax
  ITrack *m_Track; // rax
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm0_4

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer
    || ((v5 = m_pPointer->m_Flags, (v5 & 0x4000) != 0) || v5 < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer))
      : (v5 & 0x2000) != 0 || (v5 & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::AiDriverComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::AiDriverComponent::_TypeUID)),
        (v7 = ComponentOfTypeHK) == 0i64) )
  {
    v8 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( !v8 )
      return;
    m_Flags = v8->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      goto LABEL_17;
    if ( m_Flags < 0 )
    {
      m_pComponent = v8->m_Components.p[30].m_pComponent;
      goto LABEL_19;
    }
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_17:
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
    else
      m_pComponent = UFG::SimObject::GetComponentOfType(v8, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_19:
    if ( !m_pComponent )
      return;
    Texture = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
    if ( !Texture )
      return;
    v12 = Texture->m_Flags;
    if ( (v12 & 0x4000) != 0 || v12 < 0 )
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(Texture);
    else
      v13 = (UFG::AiDriverComponent *)((v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                         Texture,
                                         UFG::AiDriverComponent::_TypeUID)
                                     : UFG::SimObject::GetComponentOfType(Texture, UFG::AiDriverComponent::_TypeUID));
    v7 = v13;
    if ( !v13 )
      return;
  }
  m_Track = this->m_Track;
  if ( BYTE4(m_Track[1].vfptr) )
  {
    v15 = *(float *)&m_Track[1].vfptr;
    v16 = 0.0;
    if ( v15 > 0.000099999997 || v15 < -0.000099999997 )
    {
      if ( BYTE5(m_Track[1].vfptr) )
      {
        v17 = UFG::qRandom(*(float *)&m_Track[1].vfptr, (unsigned int *)&UFG::qDefaultSeed);
        if ( v15 <= 0.0 )
        {
          if ( v15 < 0.0 )
            v16 = FLOAT_N1_0;
          v16 = v16 * v17;
        }
        else
        {
          v16 = 1.0 * v17;
        }
      }
      else
      {
        v16 = *(float *)&m_Track[1].vfptr;
      }
    }
    UFG::AiDriverComponent::SetGasBrakeLock(v7, v16);
  }
  else
  {
    UFG::AiDriverComponent::ClearGasBrakeLock(v7);
  }
}

// File Line: 176
// RVA: 0x2FB830
void __fastcall VehicleNISModeTask::Begin(VehicleNISModeTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  this->m_pContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
        LODWORD(ComponentOfTypeHK[14].vfptr) |= 8u;
    }
  }
}

// File Line: 189
// RVA: 0x301760
void __fastcall VehicleNISModeTask::End(VehicleNISModeTask *this)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
        LODWORD(ComponentOfTypeHK[14].vfptr) &= ~8u;
    }
  }
}

// File Line: 205
// RVA: 0x2FAF10
void __fastcall VehicleInteractTask::Begin(VehicleInteractTask *this, ActionContext *pContext)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mVehicleTarget; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimObjectCVBase *v14; // rcx
  UFG::TargetingSystemVehicleComponent *v15; // r14
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::eSimObjectVehicleTypeEnum m_eSimObjectVehicleType; // r12d
  UFG::SimObjectCVBase *v19; // rcx
  UFG::SimObjectVehiclePropertiesComponent *v20; // rax
  VehicleInteractTrack *m_Track; // rax
  __int64 mValue; // rbp
  bool bDriver; // r15
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v26; // rax
  UFG::SimObject *v27; // rcx
  UFG::SimObjectVehicle *v28; // rcx
  UFG::BikePhysicsMoverComponent *v29; // rax
  UFG::SimObjectCVBase *v30; // rcx
  UFG::SimComponent *v31; // rbx
  UFG::AiDriverComponent *v32; // rax
  UFG::SimObjectGame *v33; // rcx
  __int16 v34; // dx
  UFG::CharacterOccupantComponent *v35; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v37; // rax
  UFG::VehicleOccupantComponent *v38; // rcx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v40; // rax
  UFG::CharacterOccupantComponent *v41; // rax
  UFG::CharacterOccupantComponent *v42; // rsi
  UFG::SimObject *v43; // rdx
  UFG::eTargetTypeEnum v44; // ebx
  UFG::qMemoryPool *v45; // rax
  UFG::allocator::free_link *v46; // rax
  UFG::CharacterOccupantComponent *v47; // rax
  UFG::SimObject *v48; // rax
  UFG::VehicleOccupantComponent *v49; // rcx
  __int64 v50; // r8
  UFG::SceneObjectProperties *v51; // rdx
  UFG::qPropertySet *mpConstProperties; // rcx
  float *v53; // rax
  UFG::SimObjectCVBase *v54; // rcx
  UFG::AiDriverComponent *v55; // rax
  UFG::AiDriverComponent *v56; // rsi
  UFG::SimObjectModifier v57; // [rsp+48h] [rbp-50h] BYREF

  this->mContext = pContext;
  p_mVehicleTarget = &this->mVehicleTarget;
  if ( this->mVehicleTarget.m_pPointer )
  {
    mPrev = p_mVehicleTarget->mPrev;
    mNext = this->mVehicleTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mVehicleTarget->mPrev = p_mVehicleTarget;
    this->mVehicleTarget.mNext = &this->mVehicleTarget;
  }
  this->mVehicleTarget.m_pPointer = 0i64;
  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v9 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v9;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v10 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 36i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      if ( p_mVehicleTarget->m_pPointer )
      {
        v11 = p_mVehicleTarget->mPrev;
        v12 = p_mVehicleTarget->mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        p_mVehicleTarget->mPrev = p_mVehicleTarget;
        p_mVehicleTarget->mNext = p_mVehicleTarget;
      }
      p_mVehicleTarget->m_pPointer = v10;
      if ( v10 )
      {
        v13 = v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v13->mNext = p_mVehicleTarget;
        p_mVehicleTarget->mPrev = v13;
        p_mVehicleTarget->mNext = &v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mVehicleTarget;
      }
      v14 = (UFG::SimObjectCVBase *)this->mVehicleTarget.m_pPointer;
      if ( v14 )
      {
        v15 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v14);
        if ( !v15 )
        {
LABEL_20:
          if ( p_mVehicleTarget->m_pPointer )
          {
            v16 = p_mVehicleTarget->mPrev;
            v17 = p_mVehicleTarget->mNext;
            v16->mNext = v17;
            v17->mPrev = v16;
            p_mVehicleTarget->mPrev = p_mVehicleTarget;
            p_mVehicleTarget->mNext = p_mVehicleTarget;
          }
          p_mVehicleTarget->m_pPointer = 0i64;
          return;
        }
        m_eSimObjectVehicleType = eSIM_OBJ_VEHICLE_TYPE_INVALID;
        v19 = (UFG::SimObjectCVBase *)this->mVehicleTarget.m_pPointer;
        if ( v19 )
        {
          v20 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v19);
          if ( v20 )
            m_eSimObjectVehicleType = v20->m_eSimObjectVehicleType;
        }
        m_Track = (VehicleInteractTrack *)this->m_Track;
        mValue = (unsigned __int8)m_Track->m_eTargetType.mValue;
        bDriver = (_DWORD)mValue == 4;
        if ( m_Track->m_bEnter )
        {
          m_pSceneObj = this->mContext->mSimObject.m_pPointer->m_pSceneObj;
          mpWritableProperties = m_pSceneObj->mpWritableProperties;
          if ( !mpWritableProperties )
            mpWritableProperties = m_pSceneObj->mpConstProperties;
          v26 = UFG::qPropertySet::Get<bool>(
                  mpWritableProperties,
                  (UFG::qArray<unsigned long,0> *)&qSymbol_GetInParam_VehicleInteractSkipSettingUpAI,
                  DEPTH_RECURSE);
          if ( v26 )
            LOBYTE(v26) = *v26;
          *((_BYTE *)this + 48) &= ~1u;
          *((_BYTE *)this + 48) |= (unsigned __int8)v26 & 1;
          v27 = v15->m_pTargets[(unsigned __int8)v15->m_pTargetingMap->m_Map.p[mValue]].m_pTarget.m_pPointer;
          if ( v27 && v27 != this->mContext->mSimObject.m_pPointer )
            goto LABEL_20;
          v28 = (UFG::SimObjectVehicle *)this->mVehicleTarget.m_pPointer;
          if ( v28 )
          {
            v29 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v28);
            if ( v29 )
              v29->UFG::PhysicsMoverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor(
                v29,
                1u);
          }
          if ( (_DWORD)mValue == 4 )
          {
            v30 = (UFG::SimObjectCVBase *)this->mVehicleTarget.m_pPointer;
            v31 = v30 ? v30->m_Components.p[23].m_pComponent : 0i64;
            v32 = v30 ? UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v30) : 0i64;
            if ( (!v31 || !v31[3].m_BoundComponentHandles.mNode.mNext) && v32 && (*((_BYTE *)this + 48) & 1) == 0 )
              UFG::VehicleUtility::ClearDriver((UFG::SimObjectVehicle *)this->mVehicleTarget.m_pPointer);
          }
          v33 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
          if ( v33
            && ((v34 = v33->m_Flags, (v34 & 0x4000) == 0)
              ? (v34 >= 0 && (v34 & 0x2000) == 0 && (v34 & 0x1000) == 0
               ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v33, UFG::CharacterOccupantComponent::_TypeUID))
               : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v33,
                                      UFG::CharacterOccupantComponent::_TypeUID)),
                 v35 = (UFG::CharacterOccupantComponent *)ComponentOfType)
              : (v35 = (UFG::CharacterOccupantComponent *)v33->m_Components.p[44].m_pComponent),
                v35) )
          {
            v37 = this->mVehicleTarget.m_pPointer;
            if ( v37 )
            {
              v38 = (UFG::VehicleOccupantComponent *)v37->m_Components.p[30].m_pComponent;
              if ( v38 )
                UFG::VehicleOccupantComponent::RemoveOccupant(v38, v35);
            }
            UFG::Simulation::DestroySimComponent(&UFG::gSim, v35);
            SimulationMemoryPool = UFG::GetSimulationMemoryPool();
            v40 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x88ui64, "CharacterOccupantComponent", 0i64, 1u);
            if ( v40 )
            {
              UFG::CharacterOccupantComponent::CharacterOccupantComponent(
                (UFG::CharacterOccupantComponent *)v40,
                0,
                (UFG::eTargetTypeEnum)mValue);
              v42 = v41;
            }
            else
            {
              v42 = 0i64;
            }
            v43 = this->mContext->mSimObject.m_pPointer;
            if ( (v43->m_Flags & 0x4000) != 0 )
              v44 = eTARGET_TYPE_VEHICLE_ACTION_HIJACK;
            else
              v44 = -1;
          }
          else
          {
            v45 = UFG::GetSimulationMemoryPool();
            v46 = UFG::qMemoryPool::Allocate(v45, 0x88ui64, "CharacterOccupantComponent", 0i64, 1u);
            if ( v46 )
            {
              UFG::CharacterOccupantComponent::CharacterOccupantComponent(
                (UFG::CharacterOccupantComponent *)v46,
                0,
                (UFG::eTargetTypeEnum)mValue);
              v42 = v47;
            }
            else
            {
              v42 = 0i64;
            }
            v43 = this->mContext->mSimObject.m_pPointer;
            if ( (v43->m_Flags & 0x4000) != 0 )
              v44 = eTARGET_TYPE_VEHICLE_ACTION_HIJACK;
            else
              v44 = -1;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v57, v43, 1);
          UFG::SimObjectModifier::AttachComponent(&v57, v42, (unsigned int)v44);
          UFG::SimObjectModifier::Close(&v57);
          UFG::SimObjectModifier::~SimObjectModifier(&v57);
          v48 = this->mVehicleTarget.m_pPointer;
          if ( v48 )
            v49 = (UFG::VehicleOccupantComponent *)v48->m_Components.p[30].m_pComponent;
          else
            v49 = 0i64;
          UFG::VehicleOccupantComponent::AddOccupant(v49, v42, bDriver);
          UFG::TargetingSystemBaseComponent::SetTarget(
            v15,
            (UFG::eTargetTypeEnum)mValue,
            this->mContext->mSimObject.m_pPointer);
          LOBYTE(v50) = 1;
          ((void (__fastcall *)(UFG::TargetingSystemVehicleComponent *, _QWORD, __int64, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD, __int64))v15->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
            v15,
            (unsigned int)mValue,
            v50,
            0i64,
            0,
            0i64,
            0i64,
            0i64,
            -2i64);
          UFG::VehicleUtility::UpdateTargetsForEachVehicleRole((UFG::SimObjectVehicle *)this->mVehicleTarget.m_pPointer);
          if ( UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
          {
            v51 = this->mVehicleTarget.m_pPointer->m_pSceneObj;
            mpConstProperties = v51->mpWritableProperties;
            if ( !mpConstProperties )
              mpConstProperties = v51->mpConstProperties;
            v53 = UFG::qPropertySet::Get<float>(
                    mpConstProperties,
                    (UFG::qArray<unsigned long,0> *)&qSymbol_RadioStation,
                    DEPTH_RECURSE);
            if ( v53 && UFG::RadioFullyControlled::sm_playerRadio )
              UFG::Radio::SetStation(UFG::RadioFullyControlled::sm_playerRadio, (int)*v53);
            UFG::GameStatAction::Vehicle::Mount(
              bDriver,
              m_eSimObjectVehicleType,
              (UFG::eTargetTypeEnum)mValue,
              this->mVehicleTarget.m_pPointer);
          }
        }
        else
        {
          v54 = (UFG::SimObjectCVBase *)this->mVehicleTarget.m_pPointer;
          if ( v54 )
          {
            v55 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v54);
            v56 = v55;
            if ( v55 )
            {
              if ( (_DWORD)mValue == 4
                && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v55->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v55) )
              {
                v56->m_IsAmbient = 0;
              }
            }
          }
          if ( v15->m_pTargets[(unsigned __int8)v15->m_pTargetingMap->m_Map.p[mValue]].m_pTarget.m_pPointer != this->mContext->mSimObject.m_pPointer )
            goto LABEL_20;
          if ( UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
            UFG::GameStatAction::Vehicle::Dismount(
              bDriver,
              m_eSimObjectVehicleType,
              (UFG::eTargetTypeEnum)mValue,
              this->mVehicleTarget.m_pPointer);
        }
        if ( BYTE2(this->m_Track[1].vfptr) )
          VehicleInteractTask::OnEnd(this);
      }
    }
  }
}

// File Line: 473
// RVA: 0x30B710
bool __fastcall VehicleInteractTask::Update(VehicleInteractTask *this, float timeDelta)
{
  return BYTE2(this->m_Track[1].vfptr) == 0;
}

// File Line: 484
// RVA: 0x301720
void __fastcall VehicleInteractTask::End(VehicleInteractTask *this)
{
  if ( !BYTE2(this->m_Track[1].vfptr) )
    VehicleInteractTask::OnEnd(this);
}

// File Line: 496
// RVA: 0x3023A0
void __fastcall VehicleInteractTask::OnEnd(VehicleInteractTask *this)
{
  ITrack *m_Track; // rcx
  UFG::VehicleDriverInterface *v3; // rbx
  UFG::AiDriverComponent *v4; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleOwnershipComponent *ComponentOfTypeHK; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::SimComponentHolder *p; // rax
  float *m_pComponent; // rbx
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  UFG::GameStatTracker *v16; // rax
  UFG::GameStatTracker *v17; // rax
  UFG::GameStatTracker *v18; // rax
  float v19; // xmm2_4
  UFG::GameStatTracker *v20; // rax
  UFG::GameStatTracker *v21; // rax
  UFG::SimObjectVehicle *v22; // rbx
  UFG::ProgressionTracker *v23; // rax
  UFG::Event *v24; // rbx
  UFG::allocator::free_link *v25; // rax
  UFG::Event *v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::Event *v28; // rax
  UFG::allocator::free_link *id; // [rsp+70h] [rbp+8h] BYREF

  if ( this->mVehicleTarget.m_pPointer )
  {
    m_Track = this->m_Track;
    if ( BYTE1(m_Track[1].vfptr) )
    {
      if ( LOBYTE(m_Track[1].vfptr) == 4 )
      {
        if ( UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
        {
          v3 = (UFG::VehicleDriverInterface *)UFG::VehicleUtility::SetPlayerDriver((UFG::SimObjectVehicle *)this->mVehicleTarget.m_pPointer);
          UFG::VehicleDriverInterface::SetDriver(v3, this->mContext->mSimObject.m_pPointer);
          UFG::VehicleDriverInterface::SetDesiredState(v3, (UFG::VehicleState)2);
        }
        else if ( (*((_BYTE *)this + 0x30) & 1) == 0 )
        {
          v4 = UFG::VehicleUtility::SetAIDriver(
                 this->mContext->mSimObject.m_pPointer,
                 (UFG::SimObjectVehicle *)this->mVehicleTarget.m_pPointer,
                 0);
          UFG::VehicleDriverInterface::SetDriver(v4, this->mContext->mSimObject.m_pPointer);
        }
        m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
        if ( m_pPointer )
        {
          m_Flags = m_pPointer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    m_pPointer,
                                                                    UFG::VehicleOwnershipComponent::_TypeUID);
          else
            ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                                                    m_pPointer,
                                                                    UFG::VehicleOwnershipComponent::_TypeUID);
          if ( ComponentOfTypeHK )
          {
            UFG::VehicleOwnershipComponent::TakeOwnsership(ComponentOfTypeHK, this->mVehicleTarget.m_pPointer);
            if ( LocalPlayer == this->mContext->mSimObject.m_pPointer )
            {
              LODWORD(id) = *(_DWORD *)&UFG::SceneObjectProperties::GetArchetypeProperties(this->mVehicleTarget.m_pPointer->m_pSceneObj)->mDebugName[12];
              v8 = UFG::GameStatTracker::Instance();
              UFG::GameStatTracker::SetStat(v8, LastUsedVehicle, (UFG::qSymbol *)&id);
              v9 = UFG::GameStatTracker::Instance();
              UFG::GameStatTracker::SetStat(v9, LastUsedVehicleIsCurrentlyUsed, 1);
              v10 = this->mVehicleTarget.m_pPointer;
              if ( v10 && (p = v10->m_Components.p, (m_pComponent = (float *)p[2].m_pComponent) != 0i64) )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
                v13 = m_pComponent[44];
                v14 = m_pComponent[45];
                v15 = m_pComponent[46];
                v16 = UFG::GameStatTracker::Instance();
                UFG::GameStatTracker::SetStat(v16, LastUsedVehicleDismountLocationX, v13);
                v17 = UFG::GameStatTracker::Instance();
                UFG::GameStatTracker::SetStat(v17, LastUsedVehicleDismountLocationY, v14);
                v18 = UFG::GameStatTracker::Instance();
                v19 = v15;
              }
              else
              {
                v20 = UFG::GameStatTracker::Instance();
                UFG::GameStatTracker::SetStat(v20, LastUsedVehicleDismountLocationX, 0.0);
                v21 = UFG::GameStatTracker::Instance();
                UFG::GameStatTracker::SetStat(v21, LastUsedVehicleDismountLocationY, -1000.0);
                v18 = UFG::GameStatTracker::Instance();
                v19 = 0.0;
              }
              UFG::GameStatTracker::SetStat(v18, LastUsedVehicleDismountLocationZ, v19);
              v22 = (UFG::SimObjectVehicle *)this->mVehicleTarget.m_pPointer;
              v23 = UFG::ProgressionTracker::Instance();
              UFG::ProgressionTracker::SetLastUsedVehicle(v23, v22);
            }
          }
        }
      }
      if ( UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
      {
        v24 = 0i64;
        if ( BYTE4(this->m_Track[1].vfptr) )
        {
          v25 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
          id = v25;
          if ( v25 )
            UFG::AnimatedEvent::AnimatedEvent(
              (UFG::AnimatedEvent *)v25,
              "EVT_MOUNT_VEHICLE",
              &this->mContext->mSimObject);
          else
            v26 = 0i64;
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v26);
        }
        if ( BYTE3(this->m_Track[1].vfptr) )
        {
          v27 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
          id = v27;
          if ( v27 )
          {
            UFG::AnimatedEvent::AnimatedEvent(
              (UFG::AnimatedEvent *)v27,
              "EVT_MOUNT_VEHICLE_CAMERA",
              &this->mContext->mSimObject);
            v24 = v28;
          }
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v24);
        }
      }
    }
    else
    {
      UFG::VehicleUtility::FinishExitingVehicle(
        this->mContext->mSimObject.m_pPointer,
        1,
        BYTE4(m_Track[1].vfptr) != 0,
        BYTE3(m_Track[1].vfptr) != 0);
    }
  }
}

// File Line: 594
// RVA: 0x2FA720
void __fastcall VehicleCruiseControlTask::Begin(VehicleCruiseControlTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *CurrentVehicle; // rax
  UFG::SimObjectGame *v7; // rbx
  __int16 v8; // dx
  UFG::HumanDriverComponent *v9; // rax
  UFG::CruiseControl *mCruiseControl; // rdi
  __int16 v11; // cx
  UFG::SimComponent *v12; // rbx
  UFG::SimComponent *v13; // rax
  UFG::SimObjectGame *v14; // rcx
  __int16 v15; // dx
  UFG::SimComponent *v16; // rcx
  UFG::SimComponent *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // r8
  UFG::SimObjectGame *v22; // r8
  __int16 v23; // cx
  UFG::SimComponent *v24; // rax
  float v25; // xmm1_4

  this->mContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      v7 = CurrentVehicle;
      if ( CurrentVehicle )
      {
        v8 = CurrentVehicle->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 )
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(CurrentVehicle);
        else
          v9 = (UFG::HumanDriverComponent *)((v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                               CurrentVehicle,
                                               UFG::HumanDriverComponent::_TypeUID)
                                           : UFG::SimObject::GetComponentOfType(
                                               CurrentVehicle,
                                               UFG::HumanDriverComponent::_TypeUID));
        if ( v9 )
        {
          mCruiseControl = v9->mCruiseControl;
          if ( mCruiseControl )
          {
            v11 = v7->m_Flags;
            if ( (v11 & 0x4000) == 0 )
            {
              if ( v11 >= 0 )
              {
                if ( (v11 & 0x2000) != 0 )
                  return;
                v13 = (v11 & 0x1000) != 0
                    ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::PhysicsMoverInterface::_TypeUID)
                    : UFG::SimObject::GetComponentOfType(v7, UFG::PhysicsMoverInterface::_TypeUID);
                v12 = v13;
              }
              else
              {
                v12 = v7->m_Components.p[34].m_pComponent;
              }
              if ( v12 )
              {
                v14 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
                if ( v14 )
                {
                  v15 = v14->m_Flags;
                  if ( (v15 & 0x4000) != 0 )
                  {
                    v16 = v14->m_Components.p[20].m_pComponent;
                  }
                  else if ( v15 >= 0 )
                  {
                    v17 = (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0
                        ? UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID)
                        : UFG::SimObject::GetComponentOfType(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
                    v16 = v17;
                  }
                  else
                  {
                    v16 = v14->m_Components.p[20].m_pComponent;
                  }
                  if ( v16 )
                  {
                    v18 = ((__int64 (__fastcall *)(UFG::SimComponent *))v16->vfptr[15].__vecDelDtor)(v16);
                    if ( v18 )
                    {
                      v19 = *(_QWORD *)(v18 + 96);
                      v20 = *(_QWORD *)(v18 + 88);
                      v21 = 56i64 * *(unsigned __int8 *)(v19 + 30);
                      if ( !*(_QWORD *)(v21 + v20 + 40) || !*(_BYTE *)(v21 + v20 + 49) )
                      {
                        mCruiseControl->mIsEnabled = 1;
                        v25 = *((float *)&v12[10].m_BoundComponentHandles.mNode.mPrev + 1);
                        goto LABEL_55;
                      }
                      v22 = *(UFG::SimObjectGame **)(v21 + v20 + 40);
                      if ( v22 )
                      {
                        v23 = v22->m_Flags;
                        if ( (v23 & 0x4000) == 0 )
                        {
                          if ( v23 >= 0 )
                          {
                            if ( (v23 & 0x2000) != 0 )
                              return;
                            v24 = (v23 & 0x1000) != 0
                                ? UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::PhysicsMoverInterface::_TypeUID)
                                : UFG::SimObject::GetComponentOfType(v22, UFG::PhysicsMoverInterface::_TypeUID);
                          }
                          else
                          {
                            v24 = v22->m_Components.p[34].m_pComponent;
                          }
                          if ( v24 )
                          {
                            mCruiseControl->mIsEnabled = 1;
                            v25 = *((float *)&v24[10].m_BoundComponentHandles.mNode.mPrev + 1);
LABEL_55:
                            RandomCondition::SetWeight((RandomCondition *)mCruiseControl, v25);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 649
// RVA: 0x3014F0
void __fastcall VehicleCruiseControlTask::End(VehicleCruiseControlTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *CurrentVehicle; // rax
  UFG::SimObjectGame *v5; // rbx
  __int16 v6; // dx
  UFG::HumanDriverComponent *v7; // rax
  UFG::CruiseControl *mCruiseControl; // rdi
  __int16 v9; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      v5 = CurrentVehicle;
      if ( CurrentVehicle )
      {
        v6 = CurrentVehicle->m_Flags;
        if ( (v6 & 0x4000) != 0 || v6 < 0 )
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(CurrentVehicle);
        else
          v7 = (UFG::HumanDriverComponent *)((v6 & 0x2000) != 0 || (v6 & 0x1000) != 0
                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                               CurrentVehicle,
                                               UFG::HumanDriverComponent::_TypeUID)
                                           : UFG::SimObject::GetComponentOfType(
                                               CurrentVehicle,
                                               UFG::HumanDriverComponent::_TypeUID));
        if ( v7 )
        {
          mCruiseControl = v7->mCruiseControl;
          if ( mCruiseControl )
          {
            v9 = v5->m_Flags;
            if ( (v9 & 0x4000) == 0 )
            {
              if ( v9 >= 0 )
              {
                if ( (v9 & 0x2000) != 0 )
                  return;
                if ( (v9 & 0x1000) != 0 )
                  ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::PhysicsMoverInterface::_TypeUID);
                else
                  ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v5, UFG::PhysicsMoverInterface::_TypeUID);
              }
              else
              {
                ComponentOfTypeHK = v5->m_Components.p[34].m_pComponent;
              }
              if ( ComponentOfTypeHK )
                mCruiseControl->mIsEnabled = 0;
            }
          }
        }
      }
    }
  }
}

// File Line: 688
// RVA: 0x2FB6C0
void __fastcall VehicleMassScaleForCollisionsTask::Begin(
        VehicleMassScaleForCollisionsTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v7; // dx
  UFG::SimComponent *v8; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_m_PMI; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimComponent *v14; // rax
  UFG::PhysicsVehicle *v15; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        v7 = CurrentVehicle->m_Flags;
        if ( (v7 & 0x4000) != 0 )
        {
          v8 = 0i64;
        }
        else if ( v7 >= 0 )
        {
          if ( (v7 & 0x2000) != 0 )
          {
            v8 = 0i64;
          }
          else
          {
            if ( (v7 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    CurrentVehicle,
                                    UFG::PhysicsMoverInterface::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                    CurrentVehicle,
                                    UFG::PhysicsMoverInterface::_TypeUID);
            v8 = ComponentOfTypeHK;
          }
        }
        else
        {
          v8 = CurrentVehicle->m_Components.p[34].m_pComponent;
        }
        p_m_PMI = &this->m_PMI;
        if ( this->m_PMI.m_pPointer )
        {
          mPrev = p_m_PMI->mPrev;
          mNext = this->m_PMI.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_PMI->mPrev = p_m_PMI;
          this->m_PMI.mNext = &this->m_PMI;
        }
        this->m_PMI.m_pPointer = v8;
        if ( v8 )
        {
          v13 = v8->m_SafePointerList.mNode.mPrev;
          v13->mNext = p_m_PMI;
          p_m_PMI->mPrev = v13;
          this->m_PMI.mNext = &v8->m_SafePointerList.mNode;
          v8->m_SafePointerList.mNode.mPrev = p_m_PMI;
        }
        v14 = this->m_PMI.m_pPointer;
        if ( v14 )
        {
          v15 = (UFG::PhysicsVehicle *)v14[10].m_SafePointerList.mNode.mPrev;
          if ( v15 )
            UFG::PhysicsVehicle::SetMassScaleForCollisions(
              v15,
              *(float *)&this->m_Track[1].vfptr,
              *(float *)&this->m_Track[1].vfptr);
        }
      }
    }
  }
}

// File Line: 708
// RVA: 0x301740
void __fastcall VehicleMassScaleForCollisionsTask::End(VehicleMassScaleForCollisionsTask *this)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::PhysicsVehicle *mPrev; // rcx

  m_pPointer = this->m_PMI.m_pPointer;
  if ( m_pPointer )
  {
    mPrev = (UFG::PhysicsVehicle *)m_pPointer[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
      UFG::PhysicsVehicle::ClearMassScaleForCollisions(mPrev);
  }
}

// File Line: 728
// RVA: 0x2FC7A0
void __fastcall VehicleStateTask::Begin(VehicleStateTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::VehicleState vfptr; // ebx
  __int16 m_Flags; // cx
  UFG::VehicleDriverInterface *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  vfptr = (UFG::VehicleState)this->m_Track[1].vfptr;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::VehicleDriverInterface *)m_pPointer->m_Components.p[23].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = (UFG::VehicleDriverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::VehicleDriverInterface::_TypeUID);
      else
        m_pComponent = (UFG::VehicleDriverInterface *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::VehicleDriverInterface::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::VehicleDriverInterface *)m_pPointer->m_Components.p[23].m_pComponent;
    }
    if ( m_pComponent )
      UFG::VehicleDriverInterface::SetDesiredState(m_pComponent, vfptr);
  }
}

// File Line: 742
// RVA: 0x2FAB20
void __fastcall VehicleFlipTask::Begin(VehicleFlipTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  hkpEntity *RigidBody; // rdi
  ITrack *m_Track; // rax
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  float v11; // xmm0_4
  float v12; // xmm4_4
  __m128 v13; // xmm7
  float v14; // xmm0_4
  __m128 v15; // xmm2
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  float v20; // xmm0_4
  float v21; // xmm7_4
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  ITrack *v28; // rax
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  float v32; // xmm0_4
  float v33; // xmm5_4
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm0
  __m128 v38; // xmm8
  hkVector4f v39; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f direction; // [rsp+30h] [rbp-78h] BYREF
  __m128 m_quad; // [rsp+40h] [rbp-68h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = (UFG::PhysicsMoverInterface *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
      {
        RigidBody = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(m_pComponent);
        if ( RigidBody )
        {
          UFG::PhysicsMoverInterface::LockHighLod(m_pComponent, ELODLockMode_UNTIL_AT_REST, 0.0);
          direction.m_quad = (__m128)RigidBody->m_motion.m_angularVelocity;
          hkVector4f::setRotatedInverseDir(
            &v39,
            &RigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1,
            &direction);
          m_Track = this->m_Track;
          v9 = _mm_mul_ps(
                 v39.m_quad,
                 _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)LODWORD(m_Track[1].vfptr), (__m128)LODWORD(m_Track[1].mResourceOwner)),
                   _mm_unpacklo_ps((__m128)HIDWORD(m_Track[1].vfptr), (__m128)0i64)));
          v10 = (__m128)(unsigned int)FLOAT_1_0;
          v39.m_quad = v9;
          v11 = _mm_shuffle_ps(v9, v9, 170).m128_f32[0];
          if ( v11 <= 0.0 )
          {
            if ( v11 >= 0.0 )
              v12 = 0.0;
            else
              v12 = FLOAT_N1_0;
          }
          else
          {
            v12 = *(float *)&FLOAT_1_0;
          }
          v13 = (__m128)*(unsigned int *)&m_Track[1].mBreakPoint;
          v14 = _mm_shuffle_ps(v9, v9, 85).m128_f32[0];
          if ( v14 <= 0.0 )
          {
            if ( v14 >= 0.0 )
              v15 = 0i64;
            else
              v15 = (__m128)LODWORD(FLOAT_N1_0);
          }
          else
          {
            v15 = (__m128)(unsigned int)FLOAT_1_0;
          }
          if ( v9.m128_f32[0] <= 0.0 )
          {
            if ( v9.m128_f32[0] >= 0.0 )
              v10 = 0i64;
            else
              v10 = (__m128)LODWORD(FLOAT_N1_0);
          }
          v10.m128_f32[0] = v10.m128_f32[0] * *((float *)&m_Track[1].mResourceOwner + 1);
          v15.m128_f32[0] = v15.m128_f32[0] * *(float *)&m_Track[1].m_TrackClassNameUID;
          v13.m128_f32[0] = v13.m128_f32[0] * v12;
          v16 = _mm_add_ps(v9, _mm_unpacklo_ps(_mm_unpacklo_ps(v10, v13), _mm_unpacklo_ps(v15, (__m128)0i64)));
          v39.m_quad = v16;
          v17 = _mm_mul_ps(v16, v16);
          v18 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                  _mm_shuffle_ps(v17, v17, 170));
          v19 = _mm_rsqrt_ps(v18);
          v20 = *((float *)&m_Track[1].mMasterRate.text.mOffset + 1);
          v21 = _mm_andnot_ps(
                  _mm_cmple_ps(v18, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                      _mm_mul_ps(v19, *(__m128 *)_xmm)),
                    v18)).m128_f32[0];
          if ( v21 < *(float *)&m_Track[1].mMasterRate.text.mOffset )
            v21 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
          if ( v20 >= 0.0 && v21 > v20 )
            v21 = *((float *)&m_Track[1].mMasterRate.text.mOffset + 1);
          v22 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                  _mm_shuffle_ps(v17, v17, 170));
          v23 = _mm_rsqrt_ps(v22);
          v24 = _mm_cmple_ps(v22, (__m128)0i64);
          v25 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v22), (__m128)0i64);
          v26 = _mm_mul_ps(_mm_mul_ps(v23, v22), v23);
          v27 = _mm_sub_ps((__m128)_xmm, v26);
          v26.m128_f32[0] = v21;
          v39.m_quad = _mm_mul_ps(
                         _mm_or_ps(
                           _mm_and_ps(
                             _mm_mul_ps(_mm_andnot_ps(v24, _mm_mul_ps(v27, _mm_mul_ps(v23, *(__m128 *)_xmm))), v16),
                             v25),
                           _mm_andnot_ps(v25, v16)),
                         _mm_shuffle_ps(v26, v26, 0));
          hkVector4f::setRotatedDir(&direction, &RigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1, &v39);
          hkpEntity::activate(RigidBody);
          ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))RigidBody->m_motion.vfptr[9].__first_virtual_table_function__)(
            &RigidBody->m_motion,
            &direction);
          v28 = this->m_Track;
          m_quad = RigidBody->m_motion.m_linearVelocity.m_quad;
          v29 = _mm_mul_ps(m_quad, m_quad);
          v30 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                  _mm_shuffle_ps(v29, v29, 170));
          v31 = _mm_rsqrt_ps(v30);
          v32 = *((float *)&v28[1].mMasterRate.expression.mOffset + 1);
          v33 = _mm_andnot_ps(
                  _mm_cmple_ps(v30, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                      _mm_mul_ps(v31, *(__m128 *)_xmm)),
                    v30)).m128_f32[0];
          if ( v33 < *(float *)&v28[1].mMasterRate.expression.mOffset )
            v33 = *(float *)&v28[1].mMasterRate.expression.mOffset;
          if ( v32 >= 0.0 && v33 > v32 )
            v33 = *((float *)&v28[1].mMasterRate.expression.mOffset + 1);
          v34 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                  _mm_shuffle_ps(v29, v29, 170));
          v35 = _mm_rsqrt_ps(v34);
          v36 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v34), (__m128)0i64);
          v37 = _mm_mul_ps(_mm_mul_ps(v35, v34), v35);
          v38 = _mm_sub_ps((__m128)_xmm, v37);
          v37.m128_f32[0] = v33;
          m_quad = _mm_mul_ps(
                     _mm_or_ps(
                       _mm_and_ps(
                         _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmple_ps(v34, (__m128)0i64),
                             _mm_mul_ps(v38, _mm_mul_ps(v35, *(__m128 *)_xmm))),
                           m_quad),
                         v36),
                       _mm_andnot_ps(v36, m_quad)),
                     _mm_shuffle_ps(v37, v37, 0));
          hkpEntity::activate(RigidBody);
          RigidBody->m_motion.vfptr[9].__vecDelDtor(&RigidBody->m_motion, (unsigned int)&m_quad);
        }
      }
    }
  }
}uffle_ps(v37, v37, 0));
          hkp

// File Line: 840
// RVA: 0x2FCDB0
void __fastcall VehicleTripRollTask::Begin(VehicleTripRollTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::PhysicsVehicle *RigidBody; // rax
  hkpEntity *v8; // rdi
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  ITrack *m_Track; // rax
  __m128 v13; // xmm5
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm10
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  float v22; // xmm0_4
  float v23; // xmm5_4
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // [rsp+20h] [rbp-A8h] BYREF
  __m128 v36; // [rsp+30h] [rbp-98h] BYREF
  int v37[12]; // [rsp+40h] [rbp-88h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = (UFG::PhysicsMoverInterface *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
      {
        RigidBody = UFG::PhysicsMoverInterface::GetRigidBody(m_pComponent);
        v8 = (hkpEntity *)RigidBody;
        if ( RigidBody )
        {
          v35 = _mm_shuffle_ps(
                  *(__m128 *)&RigidBody->mVerticalVelocityDampingDown,
                  _mm_unpackhi_ps(*(__m128 *)&RigidBody->mVerticalVelocityDampingDown, (__m128)0i64),
                  180);
          v9 = _mm_mul_ps(v35, v35);
          v10 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                  _mm_shuffle_ps(v9, v9, 170));
          v11 = _mm_rsqrt_ps(v10);
          if ( _mm_andnot_ps(
                 _mm_cmple_ps(v10, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                     _mm_mul_ps(*(__m128 *)_xmm, v11)),
                   v10)).m128_f32[0] > 0.001 )
          {
            UFG::PhysicsMoverInterface::LockHighLod(m_pComponent, ELODLockMode_UNTIL_AT_REST, 0.0);
            m_Track = this->m_Track;
            v13 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), _xmm),
                    _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 201), v35));
            v14 = _mm_shuffle_ps(v13, v13, 201);
            v15 = _mm_mul_ps(v14, v14);
            v16 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170));
            v17 = _mm_rsqrt_ps(v16);
            v36 = _mm_mul_ps(
                    v14,
                    _mm_andnot_ps(
                      _mm_cmple_ps(v16, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                        _mm_mul_ps(v17, *(__m128 *)_xmm))));
            v18 = _mm_mul_ps(
                    v35,
                    _mm_shuffle_ps((__m128)HIDWORD(m_Track[1].vfptr), (__m128)HIDWORD(m_Track[1].vfptr), 0));
            v35 = v18;
            v19 = _mm_mul_ps(v18, v18);
            v20 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                    _mm_shuffle_ps(v19, v19, 170));
            v21 = _mm_rsqrt_ps(v20);
            v22 = *((float *)&m_Track[1].mResourceOwner + 1);
            v23 = _mm_andnot_ps(
                    _mm_cmple_ps(v20, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                        _mm_mul_ps(v21, *(__m128 *)_xmm)),
                      v20)).m128_f32[0];
            if ( v23 < *(float *)&m_Track[1].mResourceOwner )
              v23 = *(float *)&m_Track[1].mResourceOwner;
            if ( v22 >= 0.0 && v23 > v22 )
              v23 = *((float *)&m_Track[1].mResourceOwner + 1);
            v24 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                    _mm_shuffle_ps(v19, v19, 170));
            v25 = _mm_rsqrt_ps(v24);
            v26 = _mm_cmple_ps(v24, (__m128)0i64);
            v27 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v24), (__m128)0i64);
            v28 = _mm_mul_ps(_mm_mul_ps(v25, v24), v25);
            v29 = _mm_sub_ps((__m128)_xmm, v28);
            v28.m128_f32[0] = v23;
            v35 = _mm_mul_ps(
                    _mm_or_ps(
                      _mm_and_ps(
                        _mm_mul_ps(_mm_andnot_ps(v26, _mm_mul_ps(v29, _mm_mul_ps(v25, *(__m128 *)_xmm))), v18),
                        v27),
                      _mm_andnot_ps(v27, v18)),
                    _mm_shuffle_ps(v28, v28, 0));
            hkpEntity::activate(v8);
            v8->m_motion.vfptr[9].__vecDelDtor(&v8->m_motion, (unsigned int)&v35);
            ((void (__fastcall *)(hkpMaxSizeMotion *, int *))v8->m_motion.vfptr[3].__first_virtual_table_function__)(
              &v8->m_motion,
              v37);
            v30 = _mm_unpacklo_ps(
                    _mm_unpacklo_ps((__m128)(unsigned int)v37[0], (__m128)(unsigned int)v37[8]),
                    _mm_unpacklo_ps((__m128)(unsigned int)v37[4], (__m128)0i64));
            v31 = _mm_mul_ps(v30, v30);
            v32 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                    _mm_shuffle_ps(v31, v31, 170));
            v33 = _mm_rsqrt_ps(v32);
            v34 = _mm_mul_ps(_mm_mul_ps(v33, v32), v33);
            v34.m128_f32[0] = _mm_andnot_ps(
                                _mm_cmple_ps(v32, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v34), _mm_mul_ps(v33, *(__m128 *)_xmm)),
                                  v32)).m128_f32[0]
                            * *(float *)&this->m_Track[1].vfptr;
            v36 = _mm_mul_ps(v36, _mm_shuffle_ps(v34, v34, 0));
            hkpEntity::activate(v8);
            v8->m_motion.vfptr[12].__vecDelDtor(&v8->m_motion, (unsigned int)&v36);
          }
        }
      }
    }
  }
}

// File Line: 912
// RVA: 0x2FC440
void __fastcall VehicleSpinOutTask::Begin(VehicleSpinOutTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::PhysicsVehicle *RigidBody; // rdi
  ITrack *m_Track; // rax
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  float v14; // xmm0_4
  float v15; // xmm5_4
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  ITrack *v22; // rax
  __m128 v23; // xmm6
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  float v27; // xmm0_4
  float v28; // xmm5_4
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  __m128 v33; // xmm7
  __m128 v34; // [rsp+20h] [rbp-78h] BYREF
  __m128 v35; // [rsp+30h] [rbp-68h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = (UFG::PhysicsMoverInterface *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
      {
        RigidBody = UFG::PhysicsMoverInterface::GetRigidBody(m_pComponent);
        if ( RigidBody )
        {
          UFG::PhysicsMoverInterface::LockHighLod(m_pComponent, ELODLockMode_UNTIL_AT_REST, 0.0);
          m_Track = this->m_Track;
          v9 = (__m128)_mm_slli_si128(_mm_srli_si128(*(__m128i *)&RigidBody->mSuperStopDrag, 4), 4);
          v10 = _mm_mul_ps(
                  _mm_shuffle_ps(_mm_unpacklo_ps(v9, (__m128)0i64), v9, 228),
                  _mm_shuffle_ps((__m128)LODWORD(m_Track[1].vfptr), (__m128)LODWORD(m_Track[1].vfptr), 0));
          v34 = v10;
          v11 = _mm_mul_ps(v10, v10);
          v12 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                  _mm_shuffle_ps(v11, v11, 170));
          v13 = _mm_rsqrt_ps(v12);
          v14 = *((float *)&m_Track[1].mResourceOwner + 1);
          v15 = _mm_andnot_ps(
                  _mm_cmple_ps(v12, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                      _mm_mul_ps(*(__m128 *)_xmm, v13)),
                    v12)).m128_f32[0];
          if ( v15 < *(float *)&m_Track[1].mResourceOwner )
            v15 = *(float *)&m_Track[1].mResourceOwner;
          if ( v14 >= 0.0 && v15 > v14 )
            v15 = *((float *)&m_Track[1].mResourceOwner + 1);
          v16 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                  _mm_shuffle_ps(v11, v11, 170));
          v17 = _mm_rsqrt_ps(v16);
          v18 = _mm_cmple_ps(v16, (__m128)0i64);
          v19 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v16), (__m128)0i64);
          v20 = _mm_mul_ps(_mm_mul_ps(v17, v16), v17);
          v21 = _mm_sub_ps((__m128)_xmm, v20);
          v20.m128_f32[0] = v15;
          v34 = _mm_mul_ps(
                  _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(_mm_andnot_ps(v18, _mm_mul_ps(v21, _mm_mul_ps(v17, *(__m128 *)_xmm))), v10),
                      v19),
                    _mm_andnot_ps(v19, v10)),
                  _mm_shuffle_ps(v20, v20, 0));
          hkpEntity::activate((hkpEntity *)RigidBody);
          (*(void (__fastcall **)(UFG::qVector4 *, __m128 *))(*(_QWORD *)&RigidBody->mVolumeOffset.v1.x + 152i64))(
            &RigidBody->mVolumeOffset.v1,
            &v34);
          v22 = this->m_Track;
          v35 = _mm_shuffle_ps(
                  *(__m128 *)&RigidBody->mVerticalVelocityDampingDown,
                  _mm_unpackhi_ps(*(__m128 *)&RigidBody->mVerticalVelocityDampingDown, (__m128)0i64),
                  180);
          v23 = _mm_mul_ps(v35, _mm_shuffle_ps((__m128)HIDWORD(v22[1].vfptr), (__m128)HIDWORD(v22[1].vfptr), 0));
          v35 = v23;
          v24 = _mm_mul_ps(v23, v23);
          v25 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                  _mm_shuffle_ps(v24, v24, 170));
          v26 = _mm_rsqrt_ps(v25);
          v27 = *(float *)&v22[1].mBreakPoint;
          v28 = _mm_andnot_ps(
                  _mm_cmple_ps(v25, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                      _mm_mul_ps(v26, *(__m128 *)_xmm)),
                    v25)).m128_f32[0];
          if ( v28 < *(float *)&v22[1].m_TrackClassNameUID )
            v28 = *(float *)&v22[1].m_TrackClassNameUID;
          if ( v27 >= 0.0 && v28 > v27 )
            v28 = *(float *)&v22[1].mBreakPoint;
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                  _mm_shuffle_ps(v24, v24, 170));
          v30 = _mm_rsqrt_ps(v29);
          v31 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v29), (__m128)0i64);
          v32 = _mm_mul_ps(_mm_mul_ps(v30, v29), v30);
          v33 = _mm_sub_ps((__m128)_xmm, v32);
          v32.m128_f32[0] = v28;
          v35 = _mm_mul_ps(
                  _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v29, (__m128)0i64),
                          _mm_mul_ps(v33, _mm_mul_ps(v30, *(__m128 *)_xmm))),
                        v23),
                      v31),
                    _mm_andnot_ps(v31, v23)),
                  _mm_shuffle_ps(v32, v32, 0));
          hkpEntity::activate((hkpEntity *)RigidBody);
          (*(void (__fastcall **)(UFG::qVector4 *, __m128 *))(*(_QWORD *)&RigidBody->mVolumeOffset.v1.x + 144i64))(
            &RigidBody->mVolumeOffset.v1,
            &v35);
        }
      }
    }
  }
}

// File Line: 982
// RVA: 0x2FA5F0
void __fastcall VehicleAddSpeedTask::Begin(VehicleAddSpeedTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v7; // rax
  float *m_Track; // rax
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm8_4
  float v12; // xmm1_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        v7 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = v7;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
      {
        if ( BYTE4(this->m_Track[1].mResourceOwner) )
        {
          if ( !UFG::PhysicsMoverInterface::CanApplySpeedBoostRewardFromVehicleTakedown((UFG::PhysicsMoverInterface *)m_pComponent) )
            return;
          HIDWORD(m_pComponent[13].m_pSimObject) = 0;
        }
        m_Track = (float *)this->m_Track;
        v9 = m_Track[15];
        v10 = m_Track[16];
        v11 = m_Track[14];
        v12 = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH((UFG::PhysicsMoverInterface *)m_pComponent)
            + v10;
        if ( v12 >= v11 )
        {
          if ( v9 > 0.0 && v12 > v9 )
            v12 = v9;
        }
        else
        {
          v12 = v11;
        }
        UFG::VehicleUtility::OverrideLinearVelocityMagnitudeKPH(
          (UFG::SimObjectVehicle *)context->mSimObject.m_pPointer,
          v12);
      }
    }
  }
}

// File Line: 1030
// RVA: 0x2FBAC0
void __fastcall VehicleRamTask::Begin(VehicleRamTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::PhysicsMoverInterface *m_pComponent; // rsi
  UFG::SimComponent *v7; // rax
  UFG::PhysicsVehicle *RigidBody; // r14
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // r8
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectCVBase *Texture; // rax
  __int16 v13; // dx
  UFG::AICharacterControllerBaseComponent *v14; // rax
  float *v15; // rbx
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  UFG::PhysicsWheeledVehicle *v17; // rcx
  ITrack *m_Track; // rax
  float v19; // xmm13_4
  float v20; // xmm15_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float x; // xmm12_4
  float y; // xmm10_4
  float z; // xmm11_4
  float v31; // xmm9_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm10_4
  float v37; // xmm5_4
  __m128 z_low; // xmm12
  __m128 v39; // xmm2
  float v40; // xmm14_4
  float v41; // xmm0_4
  float v42; // xmm6_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm8_4
  UFG::SimObject *v46; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v48; // xmm1_4
  float v49; // xmm2_4
  UFG::SimObject *BestTarget; // rbx
  float v51; // xmm12_4
  float v52; // xmm10_4
  float v53; // xmm11_4
  ITrack *v54; // rcx
  float v55; // xmm7_4
  float v56; // xmm6_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v59; // rax
  UFG::qVector3 vTargetingIntention; // [rsp+40h] [rbp-C0h] BYREF
  float v61; // [rsp+50h] [rbp-B0h]
  float v62; // [rsp+54h] [rbp-ACh]
  float v63; // [rsp+58h] [rbp-A8h]
  float value; // [rsp+5Ch] [rbp-A4h]
  float v65; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 vTargetingPosition; // [rsp+68h] [rbp-98h] BYREF
  UFG::qVector3 result; // [rsp+78h] [rbp-88h] BYREF
  UFG::RammingState rs; // [rsp+90h] [rbp-70h] BYREF
  __int64 v69; // [rsp+110h] [rbp+10h]
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePickupsList; // [rsp+118h] [rbp+18h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePropsList; // [rsp+148h] [rbp+48h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,20> closeVehiclesList; // [rsp+180h] [rbp+80h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,80> filteredClosePedsList; // [rsp+230h] [rbp+130h] BYREF
  UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> cachedPedsList; // [rsp+4C0h] [rbp+3C0h] BYREF
  UFG::qFixedArray<UFG::CloseTarget,100> closeTargetsList; // [rsp+C50h] [rbp+B50h] BYREF
  UFG::qFixedArray<UFG::CloseTarget,100> filteredCloseTargetsList; // [rsp+2BA0h] [rbp+2AA0h] BYREF
  float v77; // [rsp+4BD8h] [rbp+4AD8h]
  float v78; // [rsp+4BE0h] [rbp+4AE0h]
  float angle; // [rsp+4BE8h] [rbp+4AE8h]

  v69 = -2i64;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return;
    v7 = (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    m_pComponent = (UFG::PhysicsMoverInterface *)v7;
  }
  else
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !m_pComponent )
    return;
  RigidBody = UFG::PhysicsMoverInterface::GetRigidBody(m_pComponent);
  if ( !RigidBody )
    return;
  v9 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v9 )
    return;
  v10 = v9->m_Flags;
  if ( (v10 & 0x4000) == 0 )
  {
    if ( v10 < 0 )
    {
      ComponentOfType = v9->m_Components.p[30].m_pComponent;
      goto LABEL_21;
    }
    if ( (v10 & 0x2000) == 0 && (v10 & 0x1000) == 0 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(v9, UFG::VehicleOccupantComponent::_TypeUID);
      goto LABEL_21;
    }
  }
  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_21:
  if ( ComponentOfType )
  {
    Texture = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)ComponentOfType);
    if ( Texture )
    {
      v13 = Texture->m_Flags;
      if ( (v13 & 0x4000) != 0 || v13 < 0 )
        v14 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(Texture);
      else
        v14 = (UFG::AICharacterControllerBaseComponent *)((v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
                                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            Texture,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                        : UFG::SimObject::GetComponentOfType(
                                                            Texture,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID));
      v15 = (float *)v14;
      if ( v14 )
      {
        mPhysicsVehicle = m_pComponent->mPhysicsVehicle;
        if ( mPhysicsVehicle )
        {
          v17 = 0i64;
          if ( (*((_BYTE *)mPhysicsVehicle + 604) & 7) != 0 )
            v17 = (UFG::PhysicsWheeledVehicle *)m_pComponent->mPhysicsVehicle;
          if ( v17 )
          {
            if ( (unsigned int)UFG::PhysicsWheeledVehicle::GetNumWheelsOnGround(v17) >= 3 )
            {
              m_Track = this->m_Track;
              v19 = *(float *)&m_Track[1].vfptr;
              v20 = *((float *)&m_Track[1].vfptr + 1);
              v21 = *(float *)&m_Track[1].mResourceOwner;
              v62 = v21;
              v22 = *((float *)&m_Track[1].mResourceOwner + 1);
              v63 = v22;
              v23 = m_pComponent->mForwardSpeed * 3.5999999;
              v77 = *((float *)&m_Track[1].mMasterRate.text.mOffset + 1);
              v61 = *(float *)&m_Track[1].mMasterRate.expression.mOffset;
              v65 = *((float *)&m_Track[1].mMasterRate.expression.mOffset + 1);
              value = m_Track[1].mMasterRate.value;
              v78 = *(&m_Track[1].mMasterRate.value + 1);
              angle = m_Track[1].mTimeBegin;
              if ( v23 >= v19 )
              {
                if ( v20 > v19 )
                {
                  v24 = v22;
                  if ( v23 <= v20 )
                    v24 = (float)((float)(v22 - v21) * (float)((float)(v23 - v19) / (float)(v20 - v19))) + v21;
                }
                else
                {
                  v24 = v21;
                }
                v25 = v24 * 0.27777779;
                v26 = v15[38];
                v27 = v15[39];
                vTargetingIntention.x = v15[37];
                vTargetingIntention.y = v26;
                vTargetingIntention.z = v27;
                UFG::PhysicsMoverInterface::GetFacingDirection(m_pComponent, &result);
                x = vTargetingIntention.x;
                y = v26;
                z = v27;
                v31 = (float)((float)(result.x * vTargetingIntention.x) + (float)(result.y * v26))
                    + (float)(result.z * v27);
                v32 = 0.0;
                if ( v15[36] <= 0.0 )
                {
                  if ( v31 > -0.33000001 )
                  {
                    x = result.x;
                    y = result.y;
                    z = result.z;
LABEL_50:
                    v40 = value;
                    v41 = v40 * v40;
                    v42 = (float)((float)((float)(v23 * v23) * v78) * 0.0771605) + (float)(v40 * v40);
                    if ( (float)(v40 * v40) >= v42 )
                      v43 = v42;
                    else
                      v43 = value * value;
                    if ( v41 <= v42 )
                      v44 = v42;
                    else
                      v44 = value * value;
                    v45 = (float)(v31 * (float)(v42 - v41)) + v41;
                    if ( v45 <= v43 )
                      v45 = v43;
                    if ( v45 >= v44 )
                      v45 = v44;
                    closeTargetsList.size = 0;
                    `eh vector constructor iterator(
                      cachedPedsList.p,
                      0x18ui64,
                      80,
                      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
                    cachedPedsList.size = 0;
                    filteredClosePedsList.size = 0;
                    filteredCloseTargetsList.size = 0;
                    filteredClosePickupsList.size = 0;
                    filteredClosePropsList.size = 0;
                    closeVehiclesList.size = 0;
                    v46 = pContext->mSimObject.m_pPointer;
                    m_pTransformNodeComponent = v46->m_pTransformNodeComponent;
                    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                    UFG::TargetingSystemPedBaseComponent::findCloseTargets(
                      &closeTargetsList,
                      v46,
                      (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                      v45);
                    UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
                      &closeTargetsList,
                      &cachedPedsList,
                      &filteredClosePedsList,
                      &filteredClosePickupsList,
                      &filteredClosePropsList,
                      &closeVehiclesList,
                      &filteredCloseTargetsList);
                    v48 = RigidBody->mTargetTransform.v2.y;
                    v49 = RigidBody->mTargetTransform.v2.z;
                    vTargetingPosition.x = RigidBody->mTargetTransform.v2.x;
                    vTargetingPosition.y = v48;
                    vTargetingPosition.z = v49;
                    BestTarget = UFG::TargetingSystemPedBaseComponent::findBestTarget(
                                   &vTargetingPosition,
                                   &closeVehiclesList,
                                   &vTargetingIntention,
                                   v45,
                                   angle);
                    if ( !BestTarget )
                      v25 = v25 * v77;
                    v51 = x * v25;
                    v52 = y * v25;
                    v53 = z * v25;
                    v54 = this->m_Track;
                    v55 = *(float *)&v54[1].mBreakPoint;
                    v56 = *(float *)&v54[1].mMasterRate.text.mOffset * 0.27777779;
                    UFG::RammingState::RammingState(&rs);
                    if ( rs.mTarget.m_pPointer )
                    {
                      mPrev = rs.mTarget.mPrev;
                      mNext = rs.mTarget.mNext;
                      rs.mTarget.mPrev->mNext = rs.mTarget.mNext;
                      mNext->mPrev = mPrev;
                      rs.mTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&rs;
                      rs.mTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&rs;
                    }
                    rs.mTarget.m_pPointer = BestTarget;
                    if ( BestTarget )
                    {
                      v59 = BestTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                      v59->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&rs;
                      rs.mTarget.mPrev = v59;
                      rs.mTarget.mNext = &BestTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                      BestTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&rs;
                    }
                    rs.mVelocityToAdd.x = v51;
                    rs.mVelocityToAdd.y = v52;
                    rs.mVelocityToAdd.z = v53;
                    rs.mMotionIntentionDirection = vTargetingIntention;
                    rs.mForwardsness = v31;
                    rs.mSwerveImpulse = v65;
                    rs.mNoTargetModifier = v77;
                    rs.mCounterSwerveModifier = v61;
                    rs.mMinForwardSpeedKPH = v19;
                    rs.mMaxForwardSpeedKPH = v20;
                    rs.mMinAddSpeedKPH = v62;
                    rs.mMaxAddSpeedKPH = v63;
                    rs.mForwardSpeedPenaltyPercent = v55;
                    rs.mForwardSpeedPenaltyDecelKPHPS = v56;
                    rs.mTargetMaxDistance = v40;
                    rs.mTargetForwardsVelocityModifier = v78;
                    rs.mTargetAngle = angle;
                    UFG::PhysicsMoverInterface::InitiateRamming(m_pComponent, &rs);
                    UFG::InterestPointUseDetails::~InterestPointUseDetails((ActionContext *)&rs);
                    closeVehiclesList.size = 0;
                    filteredClosePropsList.size = 0;
                    filteredClosePickupsList.size = 0;
                    filteredCloseTargetsList.size = 0;
                    filteredClosePedsList.size = 0;
                    cachedPedsList.size = 0;
                    `eh vector destructor iterator(
                      cachedPedsList.p,
                      0x18ui64,
                      80,
                      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
                    return;
                  }
                }
                else if ( v31 > -0.33000001 )
                {
                  goto LABEL_50;
                }
                if ( v31 <= -0.94999999 )
                  return;
                v33 = (float)(result.x * v26) - (float)(result.y * vTargetingIntention.x);
                v34 = (float)(result.z * vTargetingIntention.x) - (float)(result.x * v27);
                v35 = (float)(result.y * z) - (float)(result.z * v26);
                v36 = (float)(v35 * result.y) - (float)(result.x * v34);
                v37 = (float)(result.x * v33) - (float)(v35 * result.z);
                z_low = (__m128)LODWORD(result.z);
                z_low.m128_f32[0] = (float)(result.z * v34) - (float)(result.y * v33);
                v39 = z_low;
                v39.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v37 * v37))
                                + (float)(v36 * v36);
                if ( v39.m128_f32[0] != 0.0 )
                  v32 = 1.0 / _mm_sqrt_ps(v39).m128_f32[0];
                z = v32 * v36;
                y = v32 * v37;
                x = z_low.m128_f32[0] * v32;
                vTargetingIntention.x = x;
                vTargetingIntention.y = v32 * v37;
                vTargetingIntention.z = z;
                goto LABEL_50;
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1233
// RVA: 0x2FB8B0
void __fastcall VehicleOverrideWheelFrictionMultiplierTask::Begin(
        VehicleOverrideWheelFrictionMultiplierTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  int v3; // ebx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_mPhysicsMoverInterface; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimComponent *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rdi
  int mNext_high; // ebp
  int v16; // ebp

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = 0i64;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = 0i64;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_mPhysicsMoverInterface = &this->mPhysicsMoverInterface;
  if ( this->mPhysicsMoverInterface.m_pPointer )
  {
    mPrev = p_mPhysicsMoverInterface->mPrev;
    mNext = this->mPhysicsMoverInterface.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
    this->mPhysicsMoverInterface.mNext = &this->mPhysicsMoverInterface;
  }
  this->mPhysicsMoverInterface.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v11 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_mPhysicsMoverInterface;
    p_mPhysicsMoverInterface->mPrev = v11;
    this->mPhysicsMoverInterface.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_mPhysicsMoverInterface;
  }
  v12 = this->mPhysicsMoverInterface.m_pPointer;
  if ( v12 )
  {
    v13 = v12[10].m_SafePointerList.mNode.mPrev;
    if ( v13 )
    {
      v14 = 0i64;
      if ( (BYTE4(v13[37].mNext) & 7) != 0 )
        v14 = v12[10].m_SafePointerList.mNode.mPrev;
      if ( v14 )
      {
        if ( ((__int64)v14[68].mNext & 0x40) == 0 )
        {
          mNext_high = HIDWORD(v14[37].mNext);
          LODWORD(v14[68].mNext) |= 0x40u;
          v16 = mNext_high & 7;
          if ( v16 )
          {
            do
              UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(
                (UFG::PhysicsWheeledVehicle *)v14,
                v3++,
                *(float *)&this->m_Track[1].vfptr);
            while ( v3 < v16 );
          }
        }
      }
    }
  }
}

// File Line: 1269
// RVA: 0x30B720
char __fastcall VehicleOverrideWheelFrictionMultiplierTask::Update(
        VehicleOverrideWheelFrictionMultiplierTask *this,
        float timestep)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  int v5; // ebx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rdi
  int v7; // esi

  m_pPointer = this->mPhysicsMoverInterface.m_pPointer;
  if ( !m_pPointer )
    return 1;
  mPrev = m_pPointer[10].m_SafePointerList.mNode.mPrev;
  if ( !mPrev )
    return 1;
  v5 = 0;
  v6 = 0i64;
  if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
    v6 = m_pPointer[10].m_SafePointerList.mNode.mPrev;
  if ( !v6 )
    return 1;
  v7 = HIDWORD(v6[37].mNext) & 7;
  if ( v7 )
  {
    do
      UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(
        (UFG::PhysicsWheeledVehicle *)v6,
        v5++,
        *(float *)&this->m_Track[1].vfptr);
    while ( v5 < v7 );
  }
  return 1;
}

// File Line: 1294
// RVA: 0x3017E0
void __fastcall VehicleOverrideWheelFrictionMultiplierTask::End(VehicleOverrideWheelFrictionMultiplierTask *this)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax

  m_pPointer = this->mPhysicsMoverInterface.m_pPointer;
  if ( m_pPointer )
  {
    mPrev = m_pPointer[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      v3 = 0i64;
      if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
        v3 = mPrev;
      if ( v3 )
        LODWORD(v3[68].mNext) &= ~0x40u;
    }
  }
}

// File Line: 1310
// RVA: 0x2FC2D0
void __fastcall VehicleSetCollisionShouldTriggerExplosionTask::Begin(
        VehicleSetCollisionShouldTriggerExplosionTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_mPhysicsMoverInterface; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rcx
  ITrack *m_Track; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = 0i64;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = 0i64;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_mPhysicsMoverInterface = &this->mPhysicsMoverInterface;
  if ( this->mPhysicsMoverInterface.m_pPointer )
  {
    mPrev = p_mPhysicsMoverInterface->mPrev;
    mNext = this->mPhysicsMoverInterface.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
    this->mPhysicsMoverInterface.mNext = &this->mPhysicsMoverInterface;
  }
  this->mPhysicsMoverInterface.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v10 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_mPhysicsMoverInterface;
    p_mPhysicsMoverInterface->mPrev = v10;
    this->mPhysicsMoverInterface.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_mPhysicsMoverInterface;
  }
  v11 = this->mPhysicsMoverInterface.m_pPointer;
  if ( v11 )
  {
    m_Track = this->m_Track;
    if ( LOBYTE(m_Track[1].vfptr) )
    {
      if ( LOBYTE(m_Track[1].vfptr) == 1 )
        BYTE4(v11[14].vfptr) &= ~0x10u;
    }
    else
    {
      BYTE4(v11[14].vfptr) |= 0x10u;
    }
  }
}

// File Line: 1323
// RVA: 0x30B7D0
bool __fastcall VehicleSetCollisionShouldTriggerExplosionTask::Update(
        VehicleSetCollisionShouldTriggerExplosionTask *this,
        float timestep)
{
  UFG::SimComponent *m_pPointer; // rdx
  ITrack *m_Track; // rax
  int vfptr_low; // ecx
  bool result; // al

  m_pPointer = this->mPhysicsMoverInterface.m_pPointer;
  if ( !m_pPointer )
    return 1;
  m_Track = this->m_Track;
  vfptr_low = LOBYTE(m_Track[1].vfptr);
  if ( !LOBYTE(m_Track[1].vfptr) )
  {
    BYTE4(m_pPointer[14].vfptr) |= 0x10u;
    return 1;
  }
  result = 1;
  if ( vfptr_low == 1 )
    BYTE4(m_pPointer[14].vfptr) &= ~0x10u;
  return result;
}

// File Line: 1331
// RVA: 0x301840
void __fastcall VehicleSetCollisionShouldTriggerExplosionTask::End(VehicleSetCollisionShouldTriggerExplosionTask *this)
{
  UFG::SimComponent *m_pPointer; // rdx
  ITrack *m_Track; // rax

  m_pPointer = this->mPhysicsMoverInterface.m_pPointer;
  if ( m_pPointer )
  {
    m_Track = this->m_Track;
    if ( BYTE1(m_Track[1].vfptr) )
    {
      if ( BYTE1(m_Track[1].vfptr) == 1 )
        BYTE4(m_pPointer[14].vfptr) &= ~0x10u;
    }
    else
    {
      BYTE4(m_pPointer[14].vfptr) |= 0x10u;
    }
  }
}

// File Line: 1355
// RVA: 0x2FB5F0
void __fastcall VehicleLockHighLODTask::Begin(VehicleLockHighLODTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_mPhysicsMoverInterface; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::PhysicsMoverInterface *v11; // rcx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = 0i64;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = 0i64;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_mPhysicsMoverInterface = &this->mPhysicsMoverInterface;
  if ( this->mPhysicsMoverInterface.m_pPointer )
  {
    mPrev = p_mPhysicsMoverInterface->mPrev;
    mNext = this->mPhysicsMoverInterface.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
    this->mPhysicsMoverInterface.mNext = &this->mPhysicsMoverInterface;
  }
  this->mPhysicsMoverInterface.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v10 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_mPhysicsMoverInterface;
    p_mPhysicsMoverInterface->mPrev = v10;
    this->mPhysicsMoverInterface.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_mPhysicsMoverInterface;
  }
  v11 = (UFG::PhysicsMoverInterface *)this->mPhysicsMoverInterface.m_pPointer;
  if ( v11 )
    UFG::PhysicsMoverInterface::LockHighLod(v11, ELODLockMode_FOREVER, 0.0);
}

// File Line: 1369
// RVA: 0x301730
void __fastcall VehicleLockHighLODTask::End(VehicleLockHighLODTask *this)
{
  UFG::PhysicsMoverInterface *m_pPointer; // rcx

  m_pPointer = (UFG::PhysicsMoverInterface *)this->mPhysicsMoverInterface.m_pPointer;
  if ( m_pPointer )
    UFG::PhysicsMoverInterface::UnlockHighLod(m_pPointer);
}

// File Line: 1381
// RVA: 0x2FB9F0
void __fastcall VehiclePreventWheelieTask::Begin(VehiclePreventWheelieTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_mPhysicsMoverInterface; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = 0i64;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = 0i64;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_mPhysicsMoverInterface = &this->mPhysicsMoverInterface;
  if ( this->mPhysicsMoverInterface.m_pPointer )
  {
    mPrev = p_mPhysicsMoverInterface->mPrev;
    mNext = this->mPhysicsMoverInterface.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPhysicsMoverInterface->mPrev = p_mPhysicsMoverInterface;
    this->mPhysicsMoverInterface.mNext = &this->mPhysicsMoverInterface;
  }
  this->mPhysicsMoverInterface.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v10 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_mPhysicsMoverInterface;
    p_mPhysicsMoverInterface->mPrev = v10;
    this->mPhysicsMoverInterface.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_mPhysicsMoverInterface;
  }
  v11 = this->mPhysicsMoverInterface.m_pPointer;
  if ( v11 )
    LODWORD(v11[1].m_pSimObject) |= 0x100u;
}

// File Line: 1395
// RVA: 0x301820
void __fastcall VehiclePreventWheelieTask::End(VehiclePreventWheelieTask *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->mPhysicsMoverInterface.m_pPointer;
  if ( m_pPointer )
    LODWORD(m_pPointer[1].m_pSimObject) &= ~0x100u;
}

// File Line: 1408
// RVA: 0x2FB510
void __fastcall VehicleLightTask::Begin(VehicleLightTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleEffectsComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rdx
  int vfptr_high; // r8d

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::VehicleEffectsComponent *)m_pPointer->m_Components.p[32].m_pComponent;
    goto LABEL_11;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleEffectsComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleEffectsComponent::_TypeUID);
  m_pComponent = (UFG::VehicleEffectsComponent *)ComponentOfTypeHK;
LABEL_11:
  if ( m_pComponent )
  {
    m_Track = this->m_Track;
    vfptr_high = HIDWORD(m_Track[1].vfptr);
    if ( vfptr_high )
    {
      if ( vfptr_high == 1 )
      {
        if ( LOBYTE(m_Track[1].vfptr) )
          UFG::VehicleEffectsComponent::TurnOnTaxiLight(m_pComponent);
        else
          UFG::VehicleEffectsComponent::TurnOffTaxiLight(m_pComponent);
      }
    }
    else if ( LOBYTE(m_Track[1].vfptr) )
    {
      UFG::VehicleEffectsComponent::TurnOnInteriorLight(m_pComponent);
    }
    else
    {
      UFG::VehicleEffectsComponent::TurnOffInteriorLight(m_pComponent);
    }
  }
}

// File Line: 1437
// RVA: 0x2E29E0
void __fastcall VehicleStopTask::VehicleStopTask(VehicleStopTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<VehicleStopTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&VehicleStopTask::`vftable;
  this->m_pPhysicsMI.mPrev = &this->m_pPhysicsMI;
  this->m_pPhysicsMI.mNext = &this->m_pPhysicsMI;
  this->m_pPhysicsMI.m_pPointer = 0i64;
}

// File Line: 1438
// RVA: 0x2E6090
void __fastcall VehicleStopTask::~VehicleStopTask(VehicleStopTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_m_pPhysicsMI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&VehicleStopTask::`vftable;
  p_m_pPhysicsMI = &this->m_pPhysicsMI;
  if ( this->m_pPhysicsMI.m_pPointer )
  {
    mPrev = p_m_pPhysicsMI->mPrev;
    mNext = p_m_pPhysicsMI->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pPhysicsMI->mPrev = p_m_pPhysicsMI;
    p_m_pPhysicsMI->mNext = p_m_pPhysicsMI;
  }
  p_m_pPhysicsMI->m_pPointer = 0i64;
  v5 = p_m_pPhysicsMI->mPrev;
  v6 = p_m_pPhysicsMI->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pPhysicsMI->mPrev = p_m_pPhysicsMI;
  p_m_pPhysicsMI->mNext = p_m_pPhysicsMI;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1441
// RVA: 0x2FCA60
void __fastcall VehicleStopTask::Begin(VehicleStopTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *v3; // rdi
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_m_pPhysicsMI; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // dx
  UFG::CharacterOccupantComponent *v15; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v17; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::SimObjectCVBase *v22; // rcx
  __int16 v23; // dx
  UFG::AiDriverComponent *v24; // rax
  UFG::AiDriverComponent *v25; // rbx
  int v26; // eax
  UFG::SimComponent *v27; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = 0i64;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = 0i64;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pPhysicsMI = &this->m_pPhysicsMI;
  if ( this->m_pPhysicsMI.m_pPointer )
  {
    mPrev = p_m_pPhysicsMI->mPrev;
    mNext = this->m_pPhysicsMI.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pPhysicsMI->mPrev = p_m_pPhysicsMI;
    this->m_pPhysicsMI.mNext = &this->m_pPhysicsMI;
  }
  this->m_pPhysicsMI.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v12 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v12->mNext = p_m_pPhysicsMI;
    p_m_pPhysicsMI->mPrev = v12;
    this->m_pPhysicsMI.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pPhysicsMI;
  }
  if ( !this->m_pPhysicsMI.m_pPointer )
  {
    v13 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v13 )
    {
      v14 = v13->m_Flags;
      if ( (v14 & 0x4000) != 0 )
        v15 = (UFG::CharacterOccupantComponent *)v13->m_Components.p[44].m_pComponent;
      else
        v15 = (UFG::CharacterOccupantComponent *)(v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v13,
                                                    UFG::CharacterOccupantComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    v13,
                                                    UFG::CharacterOccupantComponent::_TypeUID));
      if ( v15 )
      {
        CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v15);
        if ( CurrentVehicle )
        {
          v17 = CurrentVehicle->m_Flags;
          if ( (v17 & 0x4000) == 0 )
          {
            if ( v17 >= 0 )
            {
              if ( (v17 & 0x2000) == 0 )
              {
                if ( (v17 & 0x1000) != 0 )
                  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      CurrentVehicle,
                                      UFG::PhysicsMoverInterface::_TypeUID);
                else
                  ComponentOfType = UFG::SimObject::GetComponentOfType(
                                      CurrentVehicle,
                                      UFG::PhysicsMoverInterface::_TypeUID);
                v3 = ComponentOfType;
              }
            }
            else
            {
              v3 = CurrentVehicle->m_Components.p[34].m_pComponent;
            }
          }
          if ( this->m_pPhysicsMI.m_pPointer )
          {
            v19 = p_m_pPhysicsMI->mPrev;
            v20 = this->m_pPhysicsMI.mNext;
            v19->mNext = v20;
            v20->mPrev = v19;
            p_m_pPhysicsMI->mPrev = p_m_pPhysicsMI;
            this->m_pPhysicsMI.mNext = &this->m_pPhysicsMI;
          }
          this->m_pPhysicsMI.m_pPointer = v3;
          if ( v3 )
          {
            v21 = v3->m_SafePointerList.mNode.mPrev;
            v21->mNext = p_m_pPhysicsMI;
            p_m_pPhysicsMI->mPrev = v21;
            this->m_pPhysicsMI.mNext = &v3->m_SafePointerList.mNode;
            v3->m_SafePointerList.mNode.mPrev = p_m_pPhysicsMI;
          }
        }
      }
    }
  }
  if ( this->m_pPhysicsMI.m_pPointer )
  {
    v22 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
    if ( v22 )
    {
      v23 = v22->m_Flags;
      if ( (v23 & 0x4000) != 0 || v23 < 0 )
        v24 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v22);
      else
        v24 = (UFG::AiDriverComponent *)((v23 & 0x2000) != 0 || (v23 & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::AiDriverComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(v22, UFG::AiDriverComponent::_TypeUID));
      v25 = v24;
      if ( v24 )
      {
        if ( LOBYTE(this->m_Track[1].vfptr) )
        {
          v26 = UFG::qRandom(2u, (unsigned int *)&UFG::qDefaultSeed);
          UFG::AiDriverComponent::SetSteeringLock(v25, (float)(2 * v26 - 1));
        }
        UFG::AiDriverComponent::SetGasBrakeLock(v25, 1.0);
      }
    }
    v27 = this->m_pPhysicsMI.m_pPointer;
    if ( v27 )
      LODWORD(v27[1].m_pSimObject) |= 0x40u;
  }
}

// File Line: 1479
// RVA: 0x30B820
bool __fastcall VehicleStopTask::Update(VehicleStopTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rdx
  bool result; // al

  m_pPointer = this->m_pPhysicsMI.m_pPointer;
  result = 1;
  if ( m_pPointer
    && COERCE_FLOAT(COERCE_UNSIGNED_INT(3.5999999 * *((float *)&m_pPointer[10].m_BoundComponentHandles.mNode.mPrev + 1)) & _xmm) < 1.0
    && *(float *)&m_pPointer[1].m_Flags != 0.0 )
  {
    return 0;
  }
  return result;
}

// File Line: 1496
// RVA: 0x301890
void __fastcall VehicleStopTask::End(VehicleStopTask *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->m_pPhysicsMI.m_pPointer;
  if ( m_pPointer )
    LODWORD(m_pPointer[1].m_pSimObject) &= ~0x40u;
}

// File Line: 1507
// RVA: 0x2E2930
void __fastcall VehicleSteerTask::VehicleSteerTask(VehicleSteerTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<VehicleSteerTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&VehicleSteerTask::`vftable;
  this->m_pPhysicsMI.mPrev = &this->m_pPhysicsMI;
  this->m_pPhysicsMI.mNext = &this->m_pPhysicsMI;
  this->m_pPhysicsMI.m_pPointer = 0i64;
}

// File Line: 1508
// RVA: 0x2E5F90
void __fastcall VehicleSteerTask::~VehicleSteerTask(VehicleSteerTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_m_pPhysicsMI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&VehicleSteerTask::`vftable;
  p_m_pPhysicsMI = &this->m_pPhysicsMI;
  if ( this->m_pPhysicsMI.m_pPointer )
  {
    mPrev = p_m_pPhysicsMI->mPrev;
    mNext = p_m_pPhysicsMI->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pPhysicsMI->mPrev = p_m_pPhysicsMI;
    p_m_pPhysicsMI->mNext = p_m_pPhysicsMI;
  }
  p_m_pPhysicsMI->m_pPointer = 0i64;
  v5 = p_m_pPhysicsMI->mPrev;
  v6 = p_m_pPhysicsMI->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pPhysicsMI->mPrev = p_m_pPhysicsMI;
  p_m_pPhysicsMI->mNext = p_m_pPhysicsMI;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1511
// RVA: 0x2FC840
void __fastcall VehicleSteerTask::Begin(VehicleSteerTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *v3; // rdi
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_m_pPhysicsMI; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // dx
  UFG::CharacterOccupantComponent *v15; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v17; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::SimComponent *v22; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = 0i64;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = 0i64;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pPhysicsMI = &this->m_pPhysicsMI;
  if ( this->m_pPhysicsMI.m_pPointer )
  {
    mPrev = p_m_pPhysicsMI->mPrev;
    mNext = this->m_pPhysicsMI.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pPhysicsMI->mPrev = p_m_pPhysicsMI;
    this->m_pPhysicsMI.mNext = &this->m_pPhysicsMI;
  }
  this->m_pPhysicsMI.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v12 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v12->mNext = p_m_pPhysicsMI;
    p_m_pPhysicsMI->mPrev = v12;
    this->m_pPhysicsMI.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pPhysicsMI;
  }
  if ( !this->m_pPhysicsMI.m_pPointer )
  {
    v13 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v13 )
    {
      v14 = v13->m_Flags;
      if ( (v14 & 0x4000) != 0 )
        v15 = (UFG::CharacterOccupantComponent *)v13->m_Components.p[44].m_pComponent;
      else
        v15 = (UFG::CharacterOccupantComponent *)(v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v13,
                                                    UFG::CharacterOccupantComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    v13,
                                                    UFG::CharacterOccupantComponent::_TypeUID));
      if ( v15 )
      {
        CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v15);
        if ( CurrentVehicle )
        {
          v17 = CurrentVehicle->m_Flags;
          if ( (v17 & 0x4000) == 0 )
          {
            if ( v17 >= 0 )
            {
              if ( (v17 & 0x2000) == 0 )
              {
                if ( (v17 & 0x1000) != 0 )
                  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      CurrentVehicle,
                                      UFG::PhysicsMoverInterface::_TypeUID);
                else
                  ComponentOfType = UFG::SimObject::GetComponentOfType(
                                      CurrentVehicle,
                                      UFG::PhysicsMoverInterface::_TypeUID);
                v3 = ComponentOfType;
              }
            }
            else
            {
              v3 = CurrentVehicle->m_Components.p[34].m_pComponent;
            }
          }
          if ( this->m_pPhysicsMI.m_pPointer )
          {
            v19 = p_m_pPhysicsMI->mPrev;
            v20 = this->m_pPhysicsMI.mNext;
            v19->mNext = v20;
            v20->mPrev = v19;
            p_m_pPhysicsMI->mPrev = p_m_pPhysicsMI;
            this->m_pPhysicsMI.mNext = &this->m_pPhysicsMI;
          }
          this->m_pPhysicsMI.m_pPointer = v3;
          if ( v3 )
          {
            v21 = v3->m_SafePointerList.mNode.mPrev;
            v21->mNext = p_m_pPhysicsMI;
            p_m_pPhysicsMI->mPrev = v21;
            this->m_pPhysicsMI.mNext = &v3->m_SafePointerList.mNode;
            v3->m_SafePointerList.mNode.mPrev = p_m_pPhysicsMI;
          }
        }
      }
    }
  }
  v22 = this->m_pPhysicsMI.m_pPointer;
  if ( v22 )
    LODWORD(v22[1].m_pSimObject) |= 0x80u;
}

// File Line: 1535
// RVA: 0x30B800
char __fastcall VehicleSteerTask::Update(VehicleSteerTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rdx

  m_pPointer = this->m_pPhysicsMI.m_pPointer;
  if ( m_pPointer )
    m_pPointer[1].m_TypeUID = (unsigned int)this->m_Track[1].vfptr;
  return 1;
}

// File Line: 1547
// RVA: 0x301870
void __fastcall VehicleSteerTask::End(VehicleSteerTask *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->m_pPhysicsMI.m_pPointer;
  if ( m_pPointer )
    LODWORD(m_pPointer[1].m_pSimObject) &= ~0x80u;
}

// File Line: 1558
// RVA: 0x2FAAA0
void __fastcall VehicleEngineAutoDeteriorateTask::Begin(
        VehicleEngineAutoDeteriorateTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
        UFG::PhysicsMoverInterface::AutoDeteriorateEngineIfNotAlready(ComponentOfTypeHK);
    }
  }
}

// File Line: 1571
// RVA: 0x2FCD30
void __fastcall VehicleTriggerExplosionTask::Begin(VehicleTriggerExplosionTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
        UFG::PhysicsMoverInterface::TriggerExplosion(ComponentOfTypeHK);
    }
  }
}

// File Line: 1583
// RVA: 0x2FD160
void __fastcall VehicleTurnOnDisabledEffectTask::Begin(VehicleTurnOnDisabledEffectTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *ComponentOfType; // rax
  UFG::VehicleEffectsComponent *m_pComponent; // rbx
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_3;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleEffectsComponent::_TypeUID);
      goto LABEL_10;
    }
LABEL_3:
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleEffectsComponent::_TypeUID);
LABEL_10:
    m_pComponent = (UFG::VehicleEffectsComponent *)ComponentOfType;
    goto LABEL_11;
  }
  m_pComponent = (UFG::VehicleEffectsComponent *)m_pPointer->m_Components.p[32].m_pComponent;
LABEL_11:
  if ( m_pComponent )
  {
    v7 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( !v7
      || ((v8 = v7->m_Flags, (v8 & 0x4000) == 0)
        ? (v8 >= 0
         ? ((v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
          ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CopUnitComponent::_TypeUID))
          : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::CopUnitComponent::_TypeUID)))
         : (ComponentOfTypeHK = v7->m_Components.p[17].m_pComponent))
        : (ComponentOfTypeHK = v7->m_Components.p[17].m_pComponent),
          !ComponentOfTypeHK || UFG::VehicleEffectsComponent::AreCopLightsOn(m_pComponent)) )
    {
      UFG::VehicleEffectsComponent::TurnOnDisabledEffect(m_pComponent);
    }
  }
}

// File Line: 1625
// RVA: 0x2E9970
void __fastcall BikePhysicsEnableConstraintTask::Begin(BikePhysicsEnableConstraintTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *v4; // rdx
  __int16 m_Flags; // cx
  UFG::BikePhysicsMoverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::BikePhysicsMoverComponent> *p_m_pBikePhysicsMoverComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::BikePhysicsMoverComponent *v11; // rcx
  UFG::PhysicsMotorBike *PhysicsBike; // rax
  ITrack *m_Track; // rcx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v4 = 0i64;
    }
    else
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::BikePhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  m_pPointer,
                                                                  UFG::BikePhysicsMoverComponent::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::BikePhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                                  m_pPointer,
                                                                  UFG::BikePhysicsMoverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>((UFG::SimObjectVehicle *)context->mSimObject.m_pPointer);
      }
      v4 = ComponentOfTypeHK;
    }
  }
  else
  {
    v4 = 0i64;
  }
  p_m_pBikePhysicsMoverComponent = &this->m_pBikePhysicsMoverComponent;
  if ( this->m_pBikePhysicsMoverComponent.m_pPointer )
  {
    mPrev = p_m_pBikePhysicsMoverComponent->mPrev;
    mNext = this->m_pBikePhysicsMoverComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pBikePhysicsMoverComponent->mPrev = p_m_pBikePhysicsMoverComponent;
    this->m_pBikePhysicsMoverComponent.mNext = &this->m_pBikePhysicsMoverComponent;
  }
  this->m_pBikePhysicsMoverComponent.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_m_pBikePhysicsMoverComponent;
    p_m_pBikePhysicsMoverComponent->mPrev = v10;
    this->m_pBikePhysicsMoverComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = p_m_pBikePhysicsMoverComponent;
  }
  v11 = (UFG::BikePhysicsMoverComponent *)this->m_pBikePhysicsMoverComponent.m_pPointer;
  if ( v11 )
  {
    PhysicsBike = UFG::BikePhysicsMoverComponent::GetPhysicsBike(v11);
    if ( PhysicsBike )
    {
      m_Track = this->m_Track;
      if ( LOBYTE(m_Track[1].vfptr) )
      {
        if ( LOBYTE(m_Track[1].vfptr) == 1 )
          PhysicsBike->mDisableConstraint = 1;
      }
      else
      {
        PhysicsBike->mDisableConstraint = 0;
      }
    }
  }
}

// File Line: 1651
// RVA: 0x2FE160
void __fastcall BikePhysicsEnableConstraintTask::End(BikePhysicsEnableConstraintTask *this)
{
  UFG::BikePhysicsMoverComponent *m_pPointer; // rcx
  UFG::PhysicsMotorBike *PhysicsBike; // rax
  ITrack *m_Track; // rcx

  m_pPointer = (UFG::BikePhysicsMoverComponent *)this->m_pBikePhysicsMoverComponent.m_pPointer;
  if ( m_pPointer )
  {
    PhysicsBike = UFG::BikePhysicsMoverComponent::GetPhysicsBike(m_pPointer);
    if ( PhysicsBike )
    {
      m_Track = this->m_Track;
      if ( BYTE1(m_Track[1].vfptr) )
      {
        if ( BYTE1(m_Track[1].vfptr) == 1 )
          PhysicsBike->mDisableConstraint = 1;
      }
      else
      {
        PhysicsBike->mDisableConstraint = 0;
      }
    }
  }
}

// File Line: 1673
// RVA: 0x2F0670
void __fastcall MotorBikeStandUpTask::Begin(MotorBikeStandUpTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectVehicle *CurrentVehicle; // rax
  __int16 v6; // dx
  UFG::BikePhysicsMoverComponent *ComponentOfTypeHK; // rax
  UFG::PhysicsMotorBike *PhysicsBike; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        v6 = CurrentVehicle->m_Flags;
        if ( (v6 & 0x4000) == 0 )
        {
          if ( v6 >= 0 )
          {
            if ( (v6 & 0x2000) != 0 || (v6 & 0x1000) != 0 )
              ComponentOfTypeHK = (UFG::BikePhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      CurrentVehicle,
                                                                      UFG::BikePhysicsMoverComponent::_TypeUID);
            else
              ComponentOfTypeHK = (UFG::BikePhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                                      CurrentVehicle,
                                                                      UFG::BikePhysicsMoverComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(CurrentVehicle);
          }
          if ( ComponentOfTypeHK )
          {
            PhysicsBike = UFG::BikePhysicsMoverComponent::GetPhysicsBike(ComponentOfTypeHK);
            if ( PhysicsBike )
              UFG::PhysicsMotorBike::StandUpright(PhysicsBike);
          }
        }
      }
    }
  }
}

// File Line: 1694
// RVA: 0x2E23C0
void __fastcall VehicleDoorPhysicsTask::VehicleDoorPhysicsTask(VehicleDoorPhysicsTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<VehicleDoorPhysicsTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&VehicleDoorPhysicsTask::`vftable;
  this->mContext = 0i64;
}

// File Line: 1698
// RVA: 0x2FA9F0
void __fastcall VehicleDoorPhysicsTask::Begin(VehicleDoorPhysicsTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx

  this->mContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
      {
        mPhysicsVehicle = ComponentOfTypeHK->mPhysicsVehicle;
        if ( mPhysicsVehicle )
        {
          if ( (*((_DWORD *)mPhysicsVehicle + 0x97) & 7) == 4 )
            UFG::PhysicsCar::SetDesiredAttachmentState(
              (UFG::PhysicsCar *)mPhysicsVehicle,
              (UFG::VehicleAttachmentID)LOBYTE(this->m_Track[1].vfptr),
              (UFG::VehicleAttachmentState)BYTE1(this->m_Track[1].vfptr));
        }
      }
    }
  }
}

// File Line: 1720
// RVA: 0x301670
void __fastcall VehicleDoorPhysicsTask::End(VehicleDoorPhysicsTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
      {
        mPrev = ComponentOfTypeHK[10].m_SafePointerList.mNode.mPrev;
        if ( mPrev )
        {
          if ( (HIDWORD(mPrev[37].mNext) & 7) == 4 )
            UFG::PhysicsCar::SetDesiredAttachmentState(
              (UFG::PhysicsCar *)mPrev,
              (UFG::VehicleAttachmentID)LOBYTE(this->m_Track[1].vfptr),
              (UFG::VehicleAttachmentState)BYTE2(this->m_Track[1].vfptr));
        }
      }
    }
  }
}

