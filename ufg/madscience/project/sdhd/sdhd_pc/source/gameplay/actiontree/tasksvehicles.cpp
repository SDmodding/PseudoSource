// File Line: 60
// RVA: 0x2FC3C0
void __fastcall VehicleSetDoorsLockedTask::Begin(VehicleSetDoorsLockedTask *this, ActionContext *context)
{
  VehicleSetDoorsLockedTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rcx
  UFG::PhysicsMoverInterface *v6; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          return;
        if ( (v4 >> 12) & 1 )
          v6 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v3,
                                               UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::PhysicsMoverInterface::_TypeUID);
        v5 = v6;
      }
      else
      {
        v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
      }
      if ( v5 )
        v5->mDoorsLocked = LOBYTE(v2->m_Track[1].vfptr) != 0;
    }
  }
}

// File Line: 70
// RVA: 0x2E84D0
void __fastcall AiDriverSteeringWobbleTask::Begin(AiDriverSteeringWobbleTask *this, ActionContext *context)
{
  AiDriverSteeringWobbleTask *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::AiDriverComponent *v6; // rax
  UFG::AiDriverComponent *v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::SimObjectCVBase *v11; // rax
  unsigned __int16 v12; // dx
  UFG::AiDriverComponent *v13; // rax
  ITrack *v14; // rax
  float v15; // xmm6_4

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      else
        v6 = (UFG::AiDriverComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v3->vfptr,
                                                           UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v3->vfptr,
                                                                                                 UFG::AiDriverComponent::_TypeUID));
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v7 = v6;
    if ( v6 )
      goto LABEL_40;
  }
  v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
      else
        v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v10 = v8->m_Components.p[30].m_pComponent;
    }
    if ( v10 )
    {
      v11 = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v10);
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 >> 14) & 1 )
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        else if ( (v12 & 0x8000u) == 0 )
        {
          if ( (v12 >> 13) & 1 )
            v13 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v11->vfptr,
                                              UFG::AiDriverComponent::_TypeUID);
          else
            v13 = (UFG::AiDriverComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v11->vfptr,
                                                                 UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::AiDriverComponent::_TypeUID));
        }
        else
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        v7 = v13;
        if ( v13 )
        {
LABEL_40:
          v14 = v2->m_Track;
          if ( BYTE4(v14[1].vfptr) )
          {
            v15 = *(float *)&v14[1].vfptr;
            UFG::AiDriverComponent::AddSteeringNoise(v7, *(float *)&v14[1].vfptr);
            if ( BYTE5(v2->m_Track[1].vfptr) )
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
}

// File Line: 97
// RVA: 0x2E82E0
void __fastcall AiDriverSteeringLockTask::Begin(AiDriverSteeringLockTask *this, ActionContext *context)
{
  AiDriverSteeringLockTask *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::AiDriverComponent *v6; // rax
  UFG::AiDriverComponent *v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::SimObjectCVBase *v11; // rax
  unsigned __int16 v12; // dx
  UFG::AiDriverComponent *v13; // rax
  ITrack *v14; // rax
  float v15; // xmm6_4
  float v16; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      else
        v6 = (UFG::AiDriverComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v3->vfptr,
                                                           UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v3->vfptr,
                                                                                                 UFG::AiDriverComponent::_TypeUID));
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v7 = v6;
    if ( v6 )
      goto LABEL_41;
  }
  v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
      else
        v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v10 = v8->m_Components.p[30].m_pComponent;
    }
    if ( v10 )
    {
      v11 = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v10);
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 >> 14) & 1 )
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        else if ( (v12 & 0x8000u) == 0 )
        {
          if ( (v12 >> 13) & 1 )
            v13 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v11->vfptr,
                                              UFG::AiDriverComponent::_TypeUID);
          else
            v13 = (UFG::AiDriverComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v11->vfptr,
                                                                 UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::AiDriverComponent::_TypeUID));
        }
        else
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        v7 = v13;
        if ( v13 )
        {
LABEL_41:
          v14 = v2->m_Track;
          if ( BYTE4(v14[1].vfptr) )
          {
            v16 = *(float *)&v14[1].vfptr;
            if ( BYTE5(v14[1].vfptr) )
            {
              v15 = *(float *)&v14[1].vfptr;
              v16 = UFG::qRandom(v16 * 2.0, &UFG::qDefaultSeed) - v15;
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
}

// File Line: 130
// RVA: 0x2E80B0
void __fastcall AiDriverGasBrakeLockTask::Begin(AiDriverGasBrakeLockTask *this, ActionContext *context)
{
  AiDriverGasBrakeLockTask *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::AiDriverComponent *v6; // rax
  UFG::AiDriverComponent *v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::SimObjectCVBase *v11; // rax
  unsigned __int16 v12; // dx
  UFG::AiDriverComponent *v13; // rax
  ITrack *v14; // rax
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      else
        v6 = (UFG::AiDriverComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v3->vfptr,
                                                           UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v3->vfptr,
                                                                                                 UFG::AiDriverComponent::_TypeUID));
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v7 = v6;
    if ( v6 )
      goto LABEL_48;
  }
  v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID);
      else
        v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::VehicleOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v10 = v8->m_Components.p[30].m_pComponent;
    }
    if ( v10 )
    {
      v11 = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v10);
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 >> 14) & 1 )
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        else if ( (v12 & 0x8000u) == 0 )
        {
          if ( (v12 >> 13) & 1 )
            v13 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v11->vfptr,
                                              UFG::AiDriverComponent::_TypeUID);
          else
            v13 = (UFG::AiDriverComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v11->vfptr,
                                                                 UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::AiDriverComponent::_TypeUID));
        }
        else
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        v7 = v13;
        if ( v13 )
        {
LABEL_48:
          v14 = v2->m_Track;
          if ( BYTE4(v14[1].vfptr) )
          {
            v15 = *(float *)&v14[1].vfptr;
            v16 = 0.0;
            if ( v15 > 0.000099999997 || v15 < -0.000099999997 )
            {
              if ( BYTE5(v14[1].vfptr) )
              {
                v17 = UFG::qRandom(*(float *)&v14[1].vfptr, &UFG::qDefaultSeed);
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
                v16 = *(float *)&v14[1].vfptr;
              }
            }
            UFG::AiDriverComponent::SetGasBrakeLock(v7, v16);
          }
          else
          {
            UFG::AiDriverComponent::ClearGasBrakeLock(v7);
          }
        }
      }
    }
  }
}

// File Line: 176
// RVA: 0x2FB830
void __fastcall VehicleNISModeTask::Begin(VehicleNISModeTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax

  this->m_pContext = context;
  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( !((v3 >> 14) & 1) )
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          return;
        if ( (v3 >> 12) & 1 )
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v4 = v2->m_Components.p[34].m_pComponent;
      }
      if ( v4 )
        LODWORD(v4[14].vfptr) |= 8u;
    }
  }
}

// File Line: 189
// RVA: 0x301760
void __fastcall VehicleNISModeTask::End(VehicleNISModeTask *this)
{
  UFG::SimObjectGame *v1; // r8
  unsigned __int16 v2; // cx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( !((v2 >> 14) & 1) )
    {
      if ( (v2 & 0x8000u) == 0 )
      {
        if ( (v2 >> 13) & 1 )
          return;
        if ( (v2 >> 12) & 1 )
          v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v3 = v1->m_Components.p[34].m_pComponent;
      }
      if ( v3 )
        LODWORD(v3[14].vfptr) &= 0xFFFFFFF7;
    }
  }
}

// File Line: 205
// RVA: 0x2FAF10
void __fastcall VehicleInteractTask::Begin(VehicleInteractTask *this, ActionContext *pContext)
{
  VehicleInteractTask *v2; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v3; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rdx
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimObjectCVBase *v14; // rcx
  UFG::TargetingSystemVehicleComponent *v15; // r14
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::eSimObjectVehicleTypeEnum v18; // er12
  UFG::SimObjectCVBase *v19; // rcx
  UFG::SimObjectVehiclePropertiesComponent *v20; // rax
  VehicleInteractTrack *v21; // rax
  __int64 v22; // rbp
  bool bDriver; // r15
  UFG::SceneObjectProperties *v24; // rax
  UFG::qPropertySet *v25; // rcx
  bool *v26; // rax
  UFG::SimObject *v27; // rcx
  UFG::SimObjectVehicle *v28; // rcx
  UFG::BikePhysicsMoverComponent *v29; // rax
  UFG::SimObjectCVBase *v30; // rcx
  UFG::SimComponent *v31; // rbx
  UFG::AiDriverComponent *v32; // rax
  UFG::SimObjectGame *v33; // rcx
  unsigned __int16 v34; // dx
  UFG::CharacterOccupantComponent *v35; // rbx
  UFG::SimComponent *v36; // rax
  UFG::SimObject *v37; // rax
  UFG::VehicleOccupantComponent *v38; // rcx
  UFG::qMemoryPool *v39; // rax
  UFG::allocator::free_link *v40; // rax
  UFG::CharacterOccupantComponent *v41; // rax
  UFG::CharacterOccupantComponent *v42; // rsi
  UFG::SimObject *v43; // rdx
  UFG::eTargetTypeEnum v44; // ebx
  UFG::qMemoryPool *v45; // rax
  UFG::allocator::free_link *v46; // rax
  UFG::CharacterOccupantComponent *v47; // rax
  UFG::SimObject *v48; // rdx
  UFG::eTargetTypeEnum v49; // ebx
  UFG::SimObject *v50; // rax
  UFG::VehicleOccupantComponent *v51; // rcx
  __int64 v52; // r8
  UFG::SceneObjectProperties *v53; // rdx
  UFG::qPropertySet *v54; // rcx
  float *v55; // rax
  UFG::SimObjectCVBase *v56; // rcx
  UFG::AiDriverComponent *v57; // rax
  UFG::AiDriverComponent *v58; // rsi
  __int64 check_null; // [rsp+20h] [rbp-78h]
  UFG::SimObjectModifier v60; // [rsp+48h] [rbp-50h]

  v2 = this;
  this->mContext = pContext;
  v3 = &this->mVehicleTarget;
  if ( this->mVehicleTarget.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = this->mVehicleTarget.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    this->mVehicleTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mVehicleTarget.mPrev;
  }
  this->mVehicleTarget.m_pPointer = 0i64;
  v6 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v6->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = v9;
    }
    else
    {
      v8 = v6->m_Components.p[20].m_pComponent;
    }
    if ( v8 )
    {
      v10 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + 36i64)
                               + *(_QWORD *)&v8[1].m_TypeUID
                               + 40);
      if ( v3->m_pPointer )
      {
        v11 = v3->mPrev;
        v12 = v3->mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
        v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      }
      v3->m_pPointer = v10;
      if ( v10 )
      {
        v13 = v10->m_SafePointerList.mNode.mPrev;
        v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
        v3->mPrev = v13;
        v3->mNext = &v10->m_SafePointerList.mNode;
        v10->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      }
      v14 = (UFG::SimObjectCVBase *)v2->mVehicleTarget.m_pPointer;
      if ( v14 )
      {
        v15 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v14);
        if ( !v15 )
        {
LABEL_21:
          if ( v3->m_pPointer )
          {
            v16 = v3->mPrev;
            v17 = v3->mNext;
            v16->mNext = v17;
            v17->mPrev = v16;
            v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
            v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
          }
          v3->m_pPointer = 0i64;
          return;
        }
        v18 = 0;
        v19 = (UFG::SimObjectCVBase *)v2->mVehicleTarget.m_pPointer;
        if ( v19 )
        {
          v20 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v19);
          if ( v20 )
            v18 = v20->m_eSimObjectVehicleType;
        }
        v21 = (VehicleInteractTrack *)v2->m_Track;
        v22 = (unsigned __int8)v21->m_eTargetType.mValue;
        bDriver = (_DWORD)v22 == 4;
        if ( v21->m_bEnter )
        {
          v24 = v2->mContext->mSimObject.m_pPointer->m_pSceneObj;
          v25 = v24->mpWritableProperties;
          if ( !v25 )
            v25 = v24->mpConstProperties;
          v26 = UFG::qPropertySet::Get<bool>(
                  v25,
                  (UFG::qSymbol *)&qSymbol_GetInParam_VehicleInteractSkipSettingUpAI.mUID,
                  DEPTH_RECURSE);
          if ( v26 )
            LOBYTE(v26) = *v26;
          *((_BYTE *)v2 + 48) &= 0xFEu;
          *((_BYTE *)v2 + 48) |= (unsigned __int8)v26 & 1;
          v27 = v15->m_pTargets[(unsigned __int8)v15->m_pTargetingMap->m_Map.p[v22]].m_pTarget.m_pPointer;
          if ( v27 && v27 != v2->mContext->mSimObject.m_pPointer )
            goto LABEL_21;
          v28 = (UFG::SimObjectVehicle *)v2->mVehicleTarget.m_pPointer;
          if ( v28 )
          {
            v29 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v28);
            if ( v29 )
              v29->vfptr[14].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v29->vfptr, 1u);
          }
          if ( bDriver )
          {
            v30 = (UFG::SimObjectCVBase *)v2->mVehicleTarget.m_pPointer;
            v31 = v30 ? v30->m_Components.p[23].m_pComponent : 0i64;
            v32 = v30 ? UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v30) : 0i64;
            if ( (!v31 || !v31[3].m_BoundComponentHandles.mNode.mNext) && v32 && !(*((_BYTE *)v2 + 48) & 1) )
              UFG::VehicleUtility::ClearDriver((UFG::SimObjectVehicle *)v2->mVehicleTarget.m_pPointer);
          }
          v33 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
          if ( v33
            && ((v34 = v33->m_Flags, !((v34 >> 14) & 1)) ? ((v34 & 0x8000u) == 0 ? (!((v34 >> 13) & 1) ? (!((v34 >> 12) & 1) ? (v36 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v33->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::CharacterOccupantComponent::_TypeUID))) : (v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::CharacterOccupantComponent::_TypeUID))) : (v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::CharacterOccupantComponent::_TypeUID)),
                                                            v35 = (UFG::CharacterOccupantComponent *)v36) : (v35 = (UFG::CharacterOccupantComponent *)v33->m_Components.p[44].m_pComponent),
                v35) )
          {
            v37 = v2->mVehicleTarget.m_pPointer;
            if ( v37 )
            {
              v38 = (UFG::VehicleOccupantComponent *)v37->m_Components.p[30].m_pComponent;
              if ( v38 )
                UFG::VehicleOccupantComponent::RemoveOccupant(v38, v35);
            }
            UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&v35->vfptr);
            v39 = UFG::GetSimulationMemoryPool();
            v40 = UFG::qMemoryPool::Allocate(v39, 0x88ui64, "CharacterOccupantComponent", 0i64, 1u);
            if ( v40 )
            {
              UFG::CharacterOccupantComponent::CharacterOccupantComponent(
                (UFG::CharacterOccupantComponent *)v40,
                0,
                (UFG::eTargetTypeEnum)v22);
              v42 = v41;
            }
            else
            {
              v42 = 0i64;
            }
            v43 = v2->mContext->mSimObject.m_pPointer;
            if ( (v43->m_Flags >> 14) & 1 )
              v44 = eTARGET_TYPE_VEHICLE_ACTION_HIJACK;
            else
              v44 = -1;
            UFG::SimObjectModifier::SimObjectModifier(&v60, v43, 1);
            UFG::SimObjectModifier::AttachComponent(&v60, (UFG::SimComponent *)&v42->vfptr, (unsigned int)v44);
            UFG::SimObjectModifier::Close(&v60);
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
                (UFG::eTargetTypeEnum)v22);
              v42 = v47;
            }
            else
            {
              v42 = 0i64;
            }
            v48 = v2->mContext->mSimObject.m_pPointer;
            if ( (v48->m_Flags >> 14) & 1 )
              v49 = eTARGET_TYPE_VEHICLE_ACTION_HIJACK;
            else
              v49 = -1;
            UFG::SimObjectModifier::SimObjectModifier(&v60, v48, 1);
            UFG::SimObjectModifier::AttachComponent(&v60, (UFG::SimComponent *)&v42->vfptr, (unsigned int)v49);
            UFG::SimObjectModifier::Close(&v60);
          }
          UFG::SimObjectModifier::~SimObjectModifier(&v60);
          v50 = v2->mVehicleTarget.m_pPointer;
          if ( v50 )
            v51 = (UFG::VehicleOccupantComponent *)v50->m_Components.p[30].m_pComponent;
          else
            v51 = 0i64;
          UFG::VehicleOccupantComponent::AddOccupant(v51, v42, bDriver);
          UFG::TargetingSystemBaseComponent::SetTarget(
            (UFG::TargetingSystemBaseComponent *)&v15->vfptr,
            (UFG::eTargetTypeEnum)v22,
            v2->mContext->mSimObject.m_pPointer);
          LODWORD(check_null) = 0;
          LOBYTE(v52) = 1;
          ((void (__fastcall *)(UFG::TargetingSystemVehicleComponent *, _QWORD, __int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD, signed __int64))v15->vfptr[14].__vecDelDtor)(
            v15,
            (unsigned int)v22,
            v52,
            0i64,
            check_null,
            0i64,
            0i64,
            0i64,
            -2i64);
          UFG::VehicleUtility::UpdateTargetsForEachVehicleRole((UFG::SimObjectVehicle *)v2->mVehicleTarget.m_pPointer);
          if ( UFG::IsAnyLocalPlayer(v2->mContext->mSimObject.m_pPointer) )
          {
            v53 = v2->mVehicleTarget.m_pPointer->m_pSceneObj;
            v54 = v53->mpWritableProperties;
            if ( !v54 )
              v54 = v53->mpConstProperties;
            v55 = UFG::qPropertySet::Get<float>(v54, (UFG::qSymbol *)&qSymbol_RadioStation.mUID, DEPTH_RECURSE);
            if ( v55 && UFG::RadioFullyControlled::sm_playerRadio )
              UFG::Radio::SetStation((UFG::Radio *)&UFG::RadioFullyControlled::sm_playerRadio->vfptr, (signed int)*v55);
            UFG::GameStatAction::Vehicle::Mount(bDriver, v18, (UFG::eTargetTypeEnum)v22, v2->mVehicleTarget.m_pPointer);
          }
        }
        else
        {
          v56 = (UFG::SimObjectCVBase *)v2->mVehicleTarget.m_pPointer;
          if ( v56 )
          {
            v57 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v56);
            v58 = v57;
            if ( v57 )
            {
              if ( bDriver
                && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v57->vfptr[16].__vecDelDtor)(v57) )
              {
                v58->m_IsAmbient = 0;
              }
            }
          }
          if ( v15->m_pTargets[(unsigned __int8)v15->m_pTargetingMap->m_Map.p[v22]].m_pTarget.m_pPointer != v2->mContext->mSimObject.m_pPointer )
            goto LABEL_21;
          if ( UFG::IsAnyLocalPlayer(v2->mContext->mSimObject.m_pPointer) )
            UFG::GameStatAction::Vehicle::Dismount(
              bDriver,
              v18,
              (UFG::eTargetTypeEnum)v22,
              v2->mVehicleTarget.m_pPointer);
        }
        if ( BYTE2(v2->m_Track[1].vfptr) )
          VehicleInteractTask::OnEnd(v2);
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
  JUMPOUT(BYTE2(this->m_Track[1].vfptr), 0, VehicleInteractTask::OnEnd);
}

// File Line: 496
// RVA: 0x3023A0
void __fastcall VehicleInteractTask::OnEnd(VehicleInteractTask *this)
{
  VehicleInteractTask *v1; // rdi
  ITrack *v2; // rcx
  UFG::VehicleDriverInterface *v3; // rbx
  UFG::AiDriverComponent *v4; // rax
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::VehicleOwnershipComponent *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::SimComponentHolder *v11; // rax
  float *v12; // rbx
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
  UFG::qSymbol id; // [rsp+70h] [rbp+8h]

  v1 = this;
  if ( this->mVehicleTarget.m_pPointer )
  {
    v2 = this->m_Track;
    if ( BYTE1(v2[1].vfptr) )
    {
      if ( LOBYTE(v2[1].vfptr) == 4 )
      {
        if ( UFG::IsAnyLocalPlayer(v1->mContext->mSimObject.m_pPointer) )
        {
          v3 = (UFG::VehicleDriverInterface *)UFG::VehicleUtility::SetPlayerDriver((UFG::SimObjectVehicle *)v1->mVehicleTarget.m_pPointer);
          UFG::VehicleDriverInterface::SetDriver(v3, v1->mContext->mSimObject.m_pPointer);
          UFG::VehicleDriverInterface::SetDesiredState(v3, (UFG::VehicleState)2);
        }
        else if ( !(*((_BYTE *)v1 + 0x30) & 1) )
        {
          v4 = UFG::VehicleUtility::SetAIDriver(
                 v1->mContext->mSimObject.m_pPointer,
                 (UFG::SimObjectVehicle *)v1->mVehicleTarget.m_pPointer,
                 0);
          UFG::VehicleDriverInterface::SetDriver(
            (UFG::VehicleDriverInterface *)&v4->vfptr,
            v1->mContext->mSimObject.m_pPointer);
        }
        v5 = (UFG::SimObjectGame *)v1->mContext->mSimObject.m_pPointer;
        if ( v5 )
        {
          v6 = v5->m_Flags;
          if ( (v6 >> 14) & 1 )
          {
            v7 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v5,
                                                     UFG::VehicleOwnershipComponent::_TypeUID);
          }
          else if ( (v6 & 0x8000u) == 0 )
          {
            if ( (v6 >> 13) & 1 )
              v7 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v5,
                                                       UFG::VehicleOwnershipComponent::_TypeUID);
            else
              v7 = (UFG::VehicleOwnershipComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v5,
                                                                         UFG::VehicleOwnershipComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::VehicleOwnershipComponent::_TypeUID));
          }
          else
          {
            v7 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v5,
                                                     UFG::VehicleOwnershipComponent::_TypeUID);
          }
          if ( v7 )
          {
            UFG::VehicleOwnershipComponent::TakeOwnsership(v7, v1->mVehicleTarget.m_pPointer);
            if ( LocalPlayer == (UFG::SimObjectCharacter *)v1->mContext->mSimObject.m_pPointer )
            {
              id.mUID = *(_DWORD *)&UFG::SceneObjectProperties::GetArchetypeProperties(v1->mVehicleTarget.m_pPointer->m_pSceneObj)->mDebugName[12];
              v8 = UFG::GameStatTracker::Instance();
              UFG::GameStatTracker::SetStat(v8, LastUsedVehicle, &id);
              v9 = UFG::GameStatTracker::Instance();
              UFG::GameStatTracker::SetStat(v9, LastUsedVehicleIsCurrentlyUsed, 1);
              v10 = v1->mVehicleTarget.m_pPointer;
              if ( v10 && (v11 = v10->m_Components.p, (v12 = (float *)v11[2].m_pComponent) != 0i64) )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11[2].m_pComponent);
                v13 = v12[44];
                v14 = v12[45];
                v15 = v12[46];
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
              v22 = (UFG::SimObjectVehicle *)v1->mVehicleTarget.m_pPointer;
              v23 = UFG::ProgressionTracker::Instance();
              UFG::ProgressionTracker::SetLastUsedVehicle(v23, v22);
            }
          }
        }
      }
      if ( UFG::IsAnyLocalPlayer(v1->mContext->mSimObject.m_pPointer) )
      {
        v24 = 0i64;
        if ( BYTE4(v1->m_Track[1].vfptr) )
        {
          v25 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
          *(_QWORD *)&id.mUID = v25;
          if ( v25 )
            UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v25, "EVT_MOUNT_VEHICLE", &v1->mContext->mSimObject);
          else
            v26 = 0i64;
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v26);
        }
        if ( BYTE3(v1->m_Track[1].vfptr) )
        {
          v27 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
          *(_QWORD *)&id.mUID = v27;
          if ( v27 )
          {
            UFG::AnimatedEvent::AnimatedEvent(
              (UFG::AnimatedEvent *)v27,
              "EVT_MOUNT_VEHICLE_CAMERA",
              &v1->mContext->mSimObject);
            v24 = v28;
          }
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v24);
        }
      }
    }
    else
    {
      UFG::VehicleUtility::FinishExitingVehicle(
        v1->mContext->mSimObject.m_pPointer,
        1,
        BYTE4(v2[1].vfptr) != 0,
        BYTE3(v2[1].vfptr) != 0);
    }
  }
}

// File Line: 594
// RVA: 0x2FA720
void __fastcall VehicleCruiseControlTask::Begin(VehicleCruiseControlTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // rsi
  unsigned __int16 v4; // r8
  UFG::CharacterOccupantComponent *v5; // rax
  UFG::SimObjectCVBase *v6; // rax
  UFG::SimObjectGame *v7; // rbx
  unsigned __int16 v8; // dx
  UFG::HumanDriverComponent *v9; // rax
  UFG::CruiseControl *v10; // rdi
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rbx
  UFG::SimComponent *v13; // rax
  UFG::SimObjectGame *v14; // rcx
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rcx
  UFG::SimComponent *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rax
  signed __int64 v21; // r8
  UFG::SimObjectGame *v22; // r8
  unsigned __int16 v23; // cx
  UFG::SimComponent *v24; // rax
  float v25; // xmm1_4

  this->mContext = pContext;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = pContext;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::CharacterOccupantComponent *)v2->m_Components.p[44].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v2,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v5 = (UFG::CharacterOccupantComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v2,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v2,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v5);
      v7 = (UFG::SimObjectGame *)&v6->vfptr;
      if ( v6 )
      {
        v8 = v6->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v6);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            v9 = (UFG::HumanDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v6->vfptr,
                                                UFG::HumanDriverComponent::_TypeUID);
          else
            v9 = (UFG::HumanDriverComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v6->vfptr,
                                                                  UFG::HumanDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::HumanDriverComponent::_TypeUID));
        }
        else
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v6);
        }
        if ( v9 )
        {
          v10 = v9->mCruiseControl;
          if ( v10 )
          {
            v11 = v7->m_Flags;
            if ( !((v11 >> 14) & 1) )
            {
              if ( (v11 & 0x8000u) == 0 )
              {
                if ( (v11 >> 13) & 1 )
                  return;
                v13 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v7,
                                          UFG::PhysicsMoverInterface::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                    (UFG::SimObject *)&v7->vfptr,
                                                                                    UFG::PhysicsMoverInterface::_TypeUID);
                v12 = v13;
              }
              else
              {
                v12 = v7->m_Components.p[34].m_pComponent;
              }
              if ( v12 )
              {
                v14 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
                if ( v14 )
                {
                  v15 = v14->m_Flags;
                  if ( (v15 >> 14) & 1 )
                  {
                    v16 = v14->m_Components.p[20].m_pComponent;
                  }
                  else if ( (v15 & 0x8000u) == 0 )
                  {
                    if ( (v15 >> 13) & 1 )
                      v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
                    else
                      v17 = (v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v14,
                                                UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v14->vfptr,
                                                                                                 UFG::TargetingSystemBaseComponent::_TypeUID);
                    v16 = v17;
                  }
                  else
                  {
                    v16 = v14->m_Components.p[20].m_pComponent;
                  }
                  if ( v16 )
                  {
                    v18 = ((__int64 (*)(void))v16->vfptr[15].__vecDelDtor)();
                    if ( v18 )
                    {
                      v19 = *(_QWORD *)(v18 + 96);
                      v20 = *(_QWORD *)(v18 + 88);
                      v21 = 56i64 * *(unsigned __int8 *)(v19 + 30);
                      if ( !*(_QWORD *)(v21 + v20 + 40) || !*(_BYTE *)(v21 + v20 + 49) )
                      {
                        v10->mIsEnabled = 1;
                        v25 = *((float *)&v12[10].m_BoundComponentHandles.mNode.mPrev + 1);
                        goto LABEL_59;
                      }
                      v22 = *(UFG::SimObjectGame **)(v21 + v20 + 40);
                      if ( v22 )
                      {
                        v23 = v22->m_Flags;
                        if ( !((v23 >> 14) & 1) )
                        {
                          if ( (v23 & 0x8000u) == 0 )
                          {
                            if ( (v23 >> 13) & 1 )
                              return;
                            v24 = (v23 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v22,
                                                      UFG::PhysicsMoverInterface::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                (UFG::SimObject *)&v22->vfptr,
                                                                                                UFG::PhysicsMoverInterface::_TypeUID);
                          }
                          else
                          {
                            v24 = v22->m_Components.p[34].m_pComponent;
                          }
                          if ( v24 )
                          {
                            v10->mIsEnabled = 1;
                            v25 = *((float *)&v24[10].m_BoundComponentHandles.mNode.mPrev + 1);
LABEL_59:
                            RandomCondition::SetWeight((RandomCondition *)v10, v25);
                            return;
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
}      }
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
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::CharacterOccupantComponent *v3; // rax
  UFG::SimObjectCVBase *v4; // rax
  UFG::SimObjectGame *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::HumanDriverComponent *v7; // rax
  UFG::CruiseControl *v8; // rdi
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::CharacterOccupantComponent *)v1->m_Components.p[44].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
        v3 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v1,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v3 = (UFG::CharacterOccupantComponent *)((v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v1,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v3 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v1,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v3 )
    {
      v4 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v3);
      v5 = (UFG::SimObjectGame *)&v4->vfptr;
      if ( v4 )
      {
        v6 = v4->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v4);
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
            v7 = (UFG::HumanDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v4->vfptr,
                                                UFG::HumanDriverComponent::_TypeUID);
          else
            v7 = (UFG::HumanDriverComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v4->vfptr,
                                                                  UFG::HumanDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::HumanDriverComponent::_TypeUID));
        }
        else
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v4);
        }
        if ( v7 )
        {
          v8 = v7->mCruiseControl;
          if ( v8 )
          {
            v9 = v5->m_Flags;
            if ( !((v9 >> 14) & 1) )
            {
              if ( (v9 & 0x8000u) == 0 )
              {
                if ( (v9 >> 13) & 1 )
                  return;
                if ( (v9 >> 12) & 1 )
                  v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::PhysicsMoverInterface::_TypeUID);
                else
                  v10 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v5->vfptr,
                          UFG::PhysicsMoverInterface::_TypeUID);
              }
              else
              {
                v10 = v5->m_Components.p[34].m_pComponent;
              }
              if ( v10 )
                v8->mIsEnabled = 0;
            }
          }
        }
      }
    }
  }
}

// File Line: 688
// RVA: 0x2FB6C0
void __fastcall VehicleMassScaleForCollisionsTask::Begin(VehicleMassScaleForCollisionsTask *this, ActionContext *pContext)
{
  VehicleMassScaleForCollisionsTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterOccupantComponent *v5; // rax
  UFG::SimObjectGame *v6; // rax
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rdx
  UFG::SimComponent *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimComponent *v14; // rax
  UFG::PhysicsVehicle *v15; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::CharacterOccupantComponent *)v3->m_Components.p[44].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v3,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v5 = (UFG::CharacterOccupantComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v3,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v3,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v5);
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = 0i64;
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = 0i64;
          }
          else
          {
            if ( (v7 >> 12) & 1 )
              v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::PhysicsMoverInterface::_TypeUID);
            else
              v9 = UFG::SimObject::GetComponentOfType(
                     (UFG::SimObject *)&v6->vfptr,
                     UFG::PhysicsMoverInterface::_TypeUID);
            v8 = v9;
          }
        }
        else
        {
          v8 = v6->m_Components.p[34].m_pComponent;
        }
        v10 = &v2->m_PMI;
        if ( v2->m_PMI.m_pPointer )
        {
          v11 = v10->mPrev;
          v12 = v2->m_PMI.mNext;
          v11->mNext = v12;
          v12->mPrev = v11;
          v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
          v2->m_PMI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_PMI.mPrev;
        }
        v2->m_PMI.m_pPointer = v8;
        if ( v8 )
        {
          v13 = v8->m_SafePointerList.mNode.mPrev;
          v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
          v10->mPrev = v13;
          v2->m_PMI.mNext = &v8->m_SafePointerList.mNode;
          v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
        }
        v14 = v2->m_PMI.m_pPointer;
        if ( v14 )
        {
          v15 = (UFG::PhysicsVehicle *)v14[10].m_SafePointerList.mNode.mPrev;
          if ( v15 )
            UFG::PhysicsVehicle::SetMassScaleForCollisions(
              v15,
              *(float *)&v2->m_Track[1].vfptr,
              *(float *)&v2->m_Track[1].vfptr);
        }
      }
    }
  }
}

// File Line: 708
// RVA: 0x301740
void __fastcall VehicleMassScaleForCollisionsTask::End(VehicleMassScaleForCollisionsTask *this)
{
  UFG::SimComponent *v1; // rcx

  v1 = this->m_PMI.m_pPointer;
  if ( v1 )
    JUMPOUT(v1[10].m_SafePointerList.mNode.mPrev, 0i64, UFG::PhysicsVehicle::ClearMassScaleForCollisions);
}

// File Line: 728
// RVA: 0x2FC7A0
void __fastcall VehicleStateTask::Begin(VehicleStateTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  UFG::VehicleState v3; // ebx
  unsigned __int16 v4; // cx
  UFG::VehicleDriverInterface *v5; // rax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = (UFG::VehicleState)this->m_Track[1].vfptr;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::VehicleDriverInterface *)v2->m_Components.p[23].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::VehicleDriverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v2,
                                              UFG::VehicleDriverInterface::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::VehicleDriverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v2,
                                              UFG::VehicleDriverInterface::_TypeUID);
      }
      else
      {
        v5 = (UFG::VehicleDriverInterface *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v2->vfptr,
                                              UFG::VehicleDriverInterface::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::VehicleDriverInterface *)v2->m_Components.p[23].m_pComponent;
    }
    if ( v5 )
      UFG::VehicleDriverInterface::SetDesiredState(v5, v3);
  }
}

// File Line: 742
// RVA: 0x2FAB20
void __fastcall VehicleFlipTask::Begin(VehicleFlipTask *this, ActionContext *context)
{
  VehicleFlipTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rbx
  UFG::SimComponent *v6; // rax
  UFG::PhysicsVehicle *v7; // rdi
  ITrack *v8; // rax
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
  hkVector4f v39; // [rsp+20h] [rbp-88h]
  hkVector4f direction; // [rsp+30h] [rbp-78h]
  __m128 v41; // [rsp+40h] [rbp-68h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          return;
        if ( (v4 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v5 = (UFG::PhysicsMoverInterface *)v6;
      }
      else
      {
        v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
      }
      if ( v5 )
      {
        v7 = UFG::PhysicsMoverInterface::GetRigidBody(v5);
        if ( v7 )
        {
          UFG::PhysicsMoverInterface::LockHighLod(v5, ELODLockMode_UNTIL_AT_REST, 0.0);
          direction.m_quad = *(__m128 *)&v7->mSuperStopDrag;
          hkVector4f::setRotatedInverseDir(&v39, (hkQuaternionf *)&v7->mReorientActionRoll, &direction);
          v8 = v2->m_Track;
          v9 = _mm_mul_ps(
                 v39.m_quad,
                 _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)LODWORD(v8[1].vfptr), (__m128)LODWORD(v8[1].mResourceOwner)),
                   _mm_unpacklo_ps((__m128)HIDWORD(v8[1].vfptr), (__m128)0i64)));
          v10 = (__m128)(unsigned int)FLOAT_1_0;
          v39.m_quad = v9;
          LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(v9, v9, 170);
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
          v13 = (__m128)*(unsigned int *)&v8[1].mBreakPoint;
          LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(v9, v9, 85);
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
          v10.m128_f32[0] = v10.m128_f32[0] * *((float *)&v8[1].mResourceOwner + 1);
          v15.m128_f32[0] = v15.m128_f32[0] * *(float *)&v8[1].m_TrackClassNameUID;
          v13.m128_f32[0] = v13.m128_f32[0] * v12;
          v16 = _mm_add_ps(v9, _mm_unpacklo_ps(_mm_unpacklo_ps(v10, v13), _mm_unpacklo_ps(v15, (__m128)0i64)));
          v39.m_quad = v16;
          v17 = _mm_mul_ps(v16, v16);
          v18 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                  _mm_shuffle_ps(v17, v17, 170));
          v19 = _mm_rsqrt_ps(v18);
          v20 = *((float *)&v8[1].mMasterRate.text.mOffset + 1);
          LODWORD(v21) = (unsigned __int128)_mm_andnot_ps(
                                              _mm_cmpleps(v18, (__m128)0i64),
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                                  _mm_mul_ps(v19, *(__m128 *)_xmm)),
                                                v18));
          if ( v21 < *(float *)&v8[1].mMasterRate.text.mOffset )
            v21 = *(float *)&v8[1].mMasterRate.text.mOffset;
          if ( v20 >= 0.0 && v21 > v20 )
            v21 = *((float *)&v8[1].mMasterRate.text.mOffset + 1);
          v22 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                  _mm_shuffle_ps(v17, v17, 170));
          v23 = _mm_rsqrt_ps(v22);
          v24 = _mm_cmpleps(v22, (__m128)0i64);
          v25 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v22), (__m128)0i64);
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
          hkVector4f::setRotatedDir(&direction, (hkQuaternionf *)&v7->mReorientActionRoll, &v39);
          hkpEntity::activate((hkpEntity *)v7);
          (*(void (__fastcall **)(UFG::qVector4 *, hkVector4f *))(*(_QWORD *)&v7->mVolumeOffset.v1.x + 152i64))(
            &v7->mVolumeOffset.v1,
            &direction);
          v28 = v2->m_Track;
          v41 = *(__m128 *)&v7->mVerticalVelocityDampingDown;
          v29 = _mm_mul_ps(v41, v41);
          v30 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                  _mm_shuffle_ps(v29, v29, 170));
          v31 = _mm_rsqrt_ps(v30);
          v32 = *((float *)&v28[1].mMasterRate.expression.mOffset + 1);
          LODWORD(v33) = (unsigned __int128)_mm_andnot_ps(
                                              _mm_cmpleps(v30, (__m128)0i64),
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                                                  _mm_mul_ps(v31, *(__m128 *)_xmm)),
                                                v30));
          if ( v33 < *(float *)&v28[1].mMasterRate.expression.mOffset )
            v33 = *(float *)&v28[1].mMasterRate.expression.mOffset;
          if ( v32 >= 0.0 && v33 > v32 )
            v33 = *((float *)&v28[1].mMasterRate.expression.mOffset + 1);
          v34 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                  _mm_shuffle_ps(v29, v29, 170));
          v35 = _mm_rsqrt_ps(v34);
          v36 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v34), (__m128)0i64);
          v37 = _mm_mul_ps(_mm_mul_ps(v35, v34), v35);
          v38 = _mm_sub_ps((__m128)_xmm, v37);
          v37.m128_f32[0] = v33;
          v41 = _mm_mul_ps(
                  _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(_mm_cmpleps(v34, (__m128)0i64), _mm_mul_ps(v38, _mm_mul_ps(v35, *(__m128 *)_xmm))),
                        v41),
                      v36),
                    _mm_andnot_ps(v36, v41)),
                  _mm_shuffle_ps(v37, v37, 0));
          hkpEntity::activate((hkpEntity *)v7);
          (*(void (__fastcall **)(UFG::qVector4 *, __m128 *))(*(_QWORD *)&v7->mVolumeOffset.v1.x + 144i64))(
            &v7->mVolumeOffset.v1,
            &v41);
        }
      }
    }
  }
}          (*(

// File Line: 840
// RVA: 0x2FCDB0
void __fastcall VehicleTripRollTask::Begin(VehicleTripRollTask *this, ActionContext *context)
{
  VehicleTripRollTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rbx
  UFG::SimComponent *v6; // rax
  UFG::PhysicsVehicle *v7; // rax
  hkpEntity *v8; // rdi
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm2
  ITrack *v13; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm10
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  float v23; // xmm0_4
  float v24; // xmm5_4
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm3
  __m128 v33; // xmm4
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // [rsp+20h] [rbp-A8h]
  __m128 v37; // [rsp+30h] [rbp-98h]
  unsigned int v38; // [rsp+40h] [rbp-88h]
  unsigned int v39; // [rsp+50h] [rbp-78h]
  unsigned int v40; // [rsp+60h] [rbp-68h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          return;
        if ( (v4 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v5 = (UFG::PhysicsMoverInterface *)v6;
      }
      else
      {
        v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
      }
      if ( v5 )
      {
        v7 = UFG::PhysicsMoverInterface::GetRigidBody(v5);
        v8 = (hkpEntity *)v7;
        if ( v7 )
        {
          v9 = _mm_shuffle_ps(
                 *(__m128 *)&v7->mVerticalVelocityDampingDown,
                 _mm_unpackhi_ps(*(__m128 *)&v7->mVerticalVelocityDampingDown, (__m128)0i64),
                 180);
          v36 = v9;
          v10 = _mm_mul_ps(v9, v9);
          v11 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                  _mm_shuffle_ps(v10, v10, 170));
          v12 = _mm_rsqrt_ps(v11);
          if ( COERCE_FLOAT(
                 _mm_andnot_ps(
                   _mm_cmpleps(v11, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                       _mm_mul_ps(*(__m128 *)_xmm, v12)),
                     v11))) > 0.001 )
          {
            UFG::PhysicsMoverInterface::LockHighLod(v5, ELODLockMode_UNTIL_AT_REST, 0.0);
            v13 = v2->m_Track;
            v14 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), _xmm),
                    _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 201), v36));
            v15 = _mm_shuffle_ps(v14, v14, 201);
            v16 = _mm_mul_ps(v15, v15);
            v17 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                    _mm_shuffle_ps(v16, v16, 170));
            v18 = _mm_rsqrt_ps(v17);
            v37 = _mm_mul_ps(
                    v15,
                    _mm_andnot_ps(
                      _mm_cmpleps(v17, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                        _mm_mul_ps(v18, *(__m128 *)_xmm))));
            v19 = _mm_mul_ps(v36, _mm_shuffle_ps((__m128)HIDWORD(v13[1].vfptr), (__m128)HIDWORD(v13[1].vfptr), 0));
            v36 = v19;
            v20 = _mm_mul_ps(v19, v19);
            v21 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                    _mm_shuffle_ps(v20, v20, 170));
            v22 = _mm_rsqrt_ps(v21);
            v23 = *((float *)&v13[1].mResourceOwner + 1);
            LODWORD(v24) = (unsigned __int128)_mm_andnot_ps(
                                                _mm_cmpleps(v21, (__m128)0i64),
                                                _mm_mul_ps(
                                                  _mm_mul_ps(
                                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                                    _mm_mul_ps(v22, *(__m128 *)_xmm)),
                                                  v21));
            if ( v24 < *(float *)&v13[1].mResourceOwner )
              v24 = *(float *)&v13[1].mResourceOwner;
            if ( v23 >= 0.0 && v24 > v23 )
              v24 = *((float *)&v13[1].mResourceOwner + 1);
            v25 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                    _mm_shuffle_ps(v20, v20, 170));
            v26 = _mm_rsqrt_ps(v25);
            v27 = _mm_cmpleps(v25, (__m128)0i64);
            v28 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v25), (__m128)0i64);
            v29 = _mm_mul_ps(_mm_mul_ps(v26, v25), v26);
            v30 = _mm_sub_ps((__m128)_xmm, v29);
            v29.m128_f32[0] = v24;
            v36 = _mm_mul_ps(
                    _mm_or_ps(
                      _mm_and_ps(
                        _mm_mul_ps(_mm_andnot_ps(v27, _mm_mul_ps(v30, _mm_mul_ps(v26, *(__m128 *)_xmm))), v19),
                        v28),
                      _mm_andnot_ps(v28, v19)),
                    _mm_shuffle_ps(v29, v29, 0));
            hkpEntity::activate(v8);
            v8->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v8->m_motion.vfptr, (unsigned int)&v36);
            ((void (__fastcall *)(hkpMaxSizeMotion *, unsigned int *))v8->m_motion.vfptr[3].__first_virtual_table_function__)(
              &v8->m_motion,
              &v38);
            v31 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)v38, (__m128)v40), _mm_unpacklo_ps((__m128)v39, (__m128)0i64));
            v32 = _mm_mul_ps(v31, v31);
            v33 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                    _mm_shuffle_ps(v32, v32, 170));
            v34 = _mm_rsqrt_ps(v33);
            v35 = _mm_mul_ps(_mm_mul_ps(v34, v33), v34);
            v35.m128_f32[0] = COERCE_FLOAT(
                                _mm_andnot_ps(
                                  _mm_cmpleps(v33, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v35), _mm_mul_ps(v34, *(__m128 *)_xmm)),
                                    v33)))
                            * *(float *)&v2->m_Track[1].vfptr;
            v37 = _mm_mul_ps(v37, _mm_shuffle_ps(v35, v35, 0));
            hkpEntity::activate(v8);
            v8->m_motion.vfptr[12].__vecDelDtor((hkBaseObject *)&v8->m_motion.vfptr, (unsigned int)&v37);
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
  VehicleSpinOutTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rbx
  UFG::SimComponent *v6; // rax
  UFG::PhysicsVehicle *v7; // rdi
  ITrack *v8; // rax
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  __m128 v11; // xmm6
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  float v15; // xmm0_4
  float v16; // xmm5_4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  ITrack *v23; // rax
  __m128 v24; // xmm6
  __m128 v25; // xmm6
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  float v29; // xmm0_4
  float v30; // xmm5_4
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm7
  __m128 v36; // [rsp+20h] [rbp-78h]
  __m128 v37; // [rsp+30h] [rbp-68h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          return;
        if ( (v4 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v5 = (UFG::PhysicsMoverInterface *)v6;
      }
      else
      {
        v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
      }
      if ( v5 )
      {
        v7 = UFG::PhysicsMoverInterface::GetRigidBody(v5);
        if ( v7 )
        {
          UFG::PhysicsMoverInterface::LockHighLod(v5, ELODLockMode_UNTIL_AT_REST, 0.0);
          v8 = v2->m_Track;
          v9 = (__m128)_mm_slli_si128(_mm_srli_si128(*(__m128i *)&v7->mSuperStopDrag, 4), 4);
          v10 = _mm_shuffle_ps(_mm_unpacklo_ps(v9, (__m128)0i64), v9, 228);
          v36 = v10;
          v11 = _mm_mul_ps(v10, _mm_shuffle_ps((__m128)LODWORD(v8[1].vfptr), (__m128)LODWORD(v8[1].vfptr), 0));
          v36 = v11;
          v12 = _mm_mul_ps(v11, v11);
          v13 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                  _mm_shuffle_ps(v12, v12, 170));
          v14 = _mm_rsqrt_ps(v13);
          v15 = *((float *)&v8[1].mResourceOwner + 1);
          LODWORD(v16) = (unsigned __int128)_mm_andnot_ps(
                                              _mm_cmpleps(v13, (__m128)0i64),
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v14)),
                                                v13));
          if ( v16 < *(float *)&v8[1].mResourceOwner )
            v16 = *(float *)&v8[1].mResourceOwner;
          if ( v15 >= 0.0 && v16 > v15 )
            v16 = *((float *)&v8[1].mResourceOwner + 1);
          v17 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                  _mm_shuffle_ps(v12, v12, 170));
          v18 = _mm_rsqrt_ps(v17);
          v19 = _mm_cmpleps(v17, (__m128)0i64);
          v20 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v17), (__m128)0i64);
          v21 = _mm_mul_ps(_mm_mul_ps(v18, v17), v18);
          v22 = _mm_sub_ps((__m128)_xmm, v21);
          v21.m128_f32[0] = v16;
          v36 = _mm_mul_ps(
                  _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(_mm_andnot_ps(v19, _mm_mul_ps(v22, _mm_mul_ps(v18, *(__m128 *)_xmm))), v11),
                      v20),
                    _mm_andnot_ps(v20, v11)),
                  _mm_shuffle_ps(v21, v21, 0));
          hkpEntity::activate((hkpEntity *)v7);
          (*(void (__fastcall **)(UFG::qVector4 *, __m128 *))(*(_QWORD *)&v7->mVolumeOffset.v1.x + 152i64))(
            &v7->mVolumeOffset.v1,
            &v36);
          v23 = v2->m_Track;
          v24 = _mm_shuffle_ps(
                  *(__m128 *)&v7->mVerticalVelocityDampingDown,
                  _mm_unpackhi_ps(*(__m128 *)&v7->mVerticalVelocityDampingDown, (__m128)0i64),
                  180);
          v37 = v24;
          v25 = _mm_mul_ps(v24, _mm_shuffle_ps((__m128)HIDWORD(v23[1].vfptr), (__m128)HIDWORD(v23[1].vfptr), 0));
          v37 = v25;
          v26 = _mm_mul_ps(v25, v25);
          v27 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                  _mm_shuffle_ps(v26, v26, 170));
          v28 = _mm_rsqrt_ps(v27);
          v29 = *(float *)&v23[1].mBreakPoint;
          LODWORD(v30) = (unsigned __int128)_mm_andnot_ps(
                                              _mm_cmpleps(v27, (__m128)0i64),
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                                                  _mm_mul_ps(v28, *(__m128 *)_xmm)),
                                                v27));
          if ( v30 < *(float *)&v23[1].m_TrackClassNameUID )
            v30 = *(float *)&v23[1].m_TrackClassNameUID;
          if ( v29 >= 0.0 && v30 > v29 )
            v30 = *(float *)&v23[1].mBreakPoint;
          v31 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                  _mm_shuffle_ps(v26, v26, 170));
          v32 = _mm_rsqrt_ps(v31);
          v33 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v31), (__m128)0i64);
          v34 = _mm_mul_ps(_mm_mul_ps(v32, v31), v32);
          v35 = _mm_sub_ps((__m128)_xmm, v34);
          v34.m128_f32[0] = v30;
          v37 = _mm_mul_ps(
                  _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(_mm_cmpleps(v31, (__m128)0i64), _mm_mul_ps(v35, _mm_mul_ps(v32, *(__m128 *)_xmm))),
                        v25),
                      v33),
                    _mm_andnot_ps(v33, v25)),
                  _mm_shuffle_ps(v34, v34, 0));
          hkpEntity::activate((hkpEntity *)v7);
          (*(void (__fastcall **)(UFG::qVector4 *, __m128 *))(*(_QWORD *)&v7->mVolumeOffset.v1.x + 144i64))(
            &v7->mVolumeOffset.v1,
            &v37);
        }
      }
    }
  }
}

// File Line: 982
// RVA: 0x2FA5F0
void __fastcall VehicleAddSpeedTask::Begin(VehicleAddSpeedTask *this, ActionContext *context)
{
  VehicleAddSpeedTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  float *v8; // rax
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm8_4
  float v12; // xmm1_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( !((v5 >> 14) & 1) )
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          return;
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v6 = v7;
      }
      else
      {
        v6 = v3->m_Components.p[34].m_pComponent;
      }
      if ( v6 )
      {
        if ( BYTE4(v2->m_Track[1].mResourceOwner) )
        {
          if ( !UFG::PhysicsMoverInterface::CanApplySpeedBoostRewardFromVehicleTakedown((UFG::PhysicsMoverInterface *)v6) )
            return;
          HIDWORD(v6[13].m_pSimObject) = 0;
        }
        v8 = (float *)v2->m_Track;
        v9 = v8[15];
        v10 = v8[16];
        v11 = v8[14];
        v12 = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH((UFG::PhysicsMoverInterface *)v6) + v10;
        if ( v12 >= v11 )
        {
          if ( v9 > 0.0 && v12 > v9 )
            v12 = v9;
        }
        else
        {
          v12 = v11;
        }
        UFG::VehicleUtility::OverrideLinearVelocityMagnitudeKPH((UFG::SimObjectVehicle *)v4->mSimObject.m_pPointer, v12);
      }
    }
  }
}

// File Line: 1030
// RVA: 0x2FBAC0
void __fastcall VehicleRamTask::Begin(VehicleRamTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rdi
  VehicleRamTask *v3; // r15
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::PhysicsMoverInterface *v6; // rsi
  UFG::SimComponent *v7; // rax
  UFG::PhysicsVehicle *v8; // r14
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectCVBase *v12; // rax
  unsigned __int16 v13; // dx
  UFG::AICharacterControllerBaseComponent *v14; // rax
  float *v15; // rbx
  UFG::PhysicsVehicle *v16; // rax
  UFG::PhysicsWheeledVehicle *v17; // rcx
  float *v18; // rax
  float v19; // xmm13_4
  float v20; // xmm15_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm12_4
  float v29; // xmm10_4
  float v30; // xmm11_4
  float v31; // xmm9_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm10_4
  float v37; // xmm5_4
  __m128 v38; // xmm12
  __m128 v39; // xmm2
  float v40; // xmm14_4
  float v41; // xmm0_4
  float v42; // xmm6_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm8_4
  UFG::SimObject *v46; // rdi
  UFG::TransformNodeComponent *v47; // rbx
  float v48; // xmm1_4
  float v49; // xmm2_4
  UFG::SimObject *v50; // rbx
  float v51; // xmm12_4
  float v52; // xmm10_4
  float v53; // xmm11_4
  ITrack *v54; // rcx
  float v55; // xmm7_4
  float v56; // xmm6_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v57; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v58; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v59; // rax
  UFG::qVector3 vTargetingIntention; // [rsp+40h] [rbp-C0h]
  float v61; // [rsp+50h] [rbp-B0h]
  float v62; // [rsp+54h] [rbp-ACh]
  float v63; // [rsp+58h] [rbp-A8h]
  float v64; // [rsp+5Ch] [rbp-A4h]
  float v65; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 vTargetingPosition; // [rsp+68h] [rbp-98h]
  UFG::qVector3 result; // [rsp+78h] [rbp-88h]
  UFG::RammingState rs; // [rsp+90h] [rbp-70h]
  __int64 v69; // [rsp+110h] [rbp+10h]
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePickupsList; // [rsp+118h] [rbp+18h]
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePropsList; // [rsp+148h] [rbp+48h]
  UFG::qFixedArray<UFG::CloseTarget *,20> closeVehiclesList; // [rsp+180h] [rbp+80h]
  UFG::qFixedArray<UFG::CloseTarget *,80> filteredClosePedsList; // [rsp+230h] [rbp+130h]
  UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> cachedPedsList; // [rsp+4C0h] [rbp+3C0h]
  UFG::qFixedArray<UFG::CloseTarget,100> closeTargetsList; // [rsp+C50h] [rbp+B50h]
  UFG::qFixedArray<UFG::CloseTarget,100> filteredCloseTargetsList; // [rsp+2BA0h] [rbp+2AA0h]
  float v77; // [rsp+4BD8h] [rbp+4AD8h]
  float v78; // [rsp+4BE0h] [rbp+4AE0h]
  float angle; // [rsp+4BE8h] [rbp+4AE8h]

  v69 = -2i64;
  v2 = pContext;
  v3 = this;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( !((v5 >> 14) & 1) )
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          return;
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::PhysicsMoverInterface::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v6 = (UFG::PhysicsMoverInterface *)v7;
      }
      else
      {
        v6 = (UFG::PhysicsMoverInterface *)v4->m_Components.p[34].m_pComponent;
      }
      if ( v6 )
      {
        v8 = UFG::PhysicsMoverInterface::GetRigidBody(v6);
        if ( v8 )
        {
          v9 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
          if ( v9 )
          {
            v10 = v9->m_Flags;
            if ( (v10 >> 14) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::VehicleOccupantComponent::_TypeUID);
            }
            else if ( (v10 & 0x8000u) == 0 )
            {
              if ( (v10 >> 13) & 1 )
                v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::VehicleOccupantComponent::_TypeUID);
              else
                v11 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v9,
                                          UFG::VehicleOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v9->vfptr,
                                                                                       UFG::VehicleOccupantComponent::_TypeUID);
            }
            else
            {
              v11 = v9->m_Components.p[30].m_pComponent;
            }
            if ( v11 )
            {
              v12 = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v11);
              if ( v12 )
              {
                v13 = v12->m_Flags;
                if ( (v13 >> 14) & 1 )
                {
                  v14 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v12);
                }
                else if ( (v13 & 0x8000u) == 0 )
                {
                  if ( (v13 >> 13) & 1 )
                    v14 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v12->vfptr,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
                  else
                    v14 = (UFG::AICharacterControllerBaseComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                          (UFG::SimObjectGame *)&v12->vfptr,
                                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
                }
                else
                {
                  v14 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v12);
                }
                v15 = (float *)v14;
                if ( v14 )
                {
                  v16 = v6->mPhysicsVehicle;
                  if ( v16 )
                  {
                    v17 = 0i64;
                    if ( *((_BYTE *)v16 + 604) & 7 )
                      v17 = (UFG::PhysicsWheeledVehicle *)v6->mPhysicsVehicle;
                    if ( v17 )
                    {
                      if ( (unsigned int)UFG::PhysicsWheeledVehicle::GetNumWheelsOnGround(v17) >= 3 )
                      {
                        v18 = (float *)v3->m_Track;
                        v19 = v18[14];
                        v20 = v18[15];
                        v21 = v18[16];
                        v62 = v18[16];
                        v22 = v18[17];
                        v63 = v18[17];
                        v23 = v6->mForwardSpeed * 3.5999999;
                        v77 = v18[21];
                        v61 = v18[22];
                        v65 = v18[23];
                        v64 = v18[24];
                        v78 = v18[25];
                        angle = v18[26];
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
                          UFG::PhysicsMoverInterface::GetFacingDirection(v6, &result);
                          v28 = vTargetingIntention.x;
                          v29 = v26;
                          v30 = v27;
                          v31 = (float)((float)(result.x * vTargetingIntention.x) + (float)(result.y * v26))
                              + (float)(result.z * v27);
                          v32 = 0.0;
                          if ( v15[36] <= 0.0 )
                          {
                            if ( v31 > -0.33000001 )
                            {
                              v28 = result.x;
                              v29 = result.y;
                              v30 = result.z;
LABEL_53:
                              v40 = v64;
                              v41 = v40 * v40;
                              v42 = (float)((float)((float)(v23 * v23) * v78) * 0.0771605) + (float)(v40 * v40);
                              if ( (float)(v40 * v40) >= v42 )
                                v43 = v42;
                              else
                                v43 = v64 * v64;
                              if ( v41 <= v42 )
                                v44 = v42;
                              else
                                v44 = v64 * v64;
                              v45 = (float)(v31 * (float)(v42 - v41)) + v41;
                              if ( v45 <= v43 )
                                v45 = v43;
                              if ( v45 >= v44 )
                                v45 = v44;
                              closeTargetsList.size = 0;
                              `eh vector constructor iterator'(
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
                              v46 = v2->mSimObject.m_pPointer;
                              v47 = v46->m_pTransformNodeComponent;
                              UFG::TransformNodeComponent::UpdateWorldTransform(v46->m_pTransformNodeComponent);
                              UFG::TargetingSystemPedBaseComponent::findCloseTargets(
                                &closeTargetsList,
                                v46,
                                (UFG::qVector3 *)&v47->mWorldTransform.v3,
                                v45);
                              UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
                                &closeTargetsList,
                                &cachedPedsList,
                                &filteredClosePedsList,
                                &filteredClosePickupsList,
                                &filteredClosePropsList,
                                &closeVehiclesList,
                                &filteredCloseTargetsList);
                              v48 = v8->mTargetTransform.v2.y;
                              v49 = v8->mTargetTransform.v2.z;
                              vTargetingPosition.x = v8->mTargetTransform.v2.x;
                              vTargetingPosition.y = v48;
                              vTargetingPosition.z = v49;
                              v50 = UFG::TargetingSystemPedBaseComponent::findBestTarget(
                                      &vTargetingPosition,
                                      &closeVehiclesList,
                                      &vTargetingIntention,
                                      v45,
                                      angle);
                              if ( !v50 )
                                v25 = v25 * v77;
                              v51 = v28 * v25;
                              v52 = v29 * v25;
                              v53 = v30 * v25;
                              v54 = v3->m_Track;
                              v55 = *(float *)&v54[1].mBreakPoint;
                              v56 = *(float *)&v54[1].mMasterRate.text.mOffset * 0.27777779;
                              UFG::RammingState::RammingState(&rs);
                              if ( rs.mTarget.m_pPointer )
                              {
                                v57 = rs.mTarget.mPrev;
                                v58 = rs.mTarget.mNext;
                                rs.mTarget.mPrev->mNext = rs.mTarget.mNext;
                                v58->mPrev = v57;
                                rs.mTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&rs;
                                rs.mTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&rs;
                              }
                              rs.mTarget.m_pPointer = v50;
                              if ( v50 )
                              {
                                v59 = v50->m_SafePointerList.mNode.mPrev;
                                v59->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&rs;
                                rs.mTarget.mPrev = v59;
                                rs.mTarget.mNext = &v50->m_SafePointerList.mNode;
                                v50->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&rs;
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
                              UFG::PhysicsMoverInterface::InitiateRamming(v6, &rs);
                              UFG::InterestPointUseDetails::~InterestPointUseDetails((ActionContext *)&rs);
                              closeVehiclesList.size = 0;
                              filteredClosePropsList.size = 0;
                              filteredClosePickupsList.size = 0;
                              filteredCloseTargetsList.size = 0;
                              filteredClosePedsList.size = 0;
                              cachedPedsList.size = 0;
                              `eh vector destructor iterator'(
                                cachedPedsList.p,
                                0x18ui64,
                                80,
                                (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
                              return;
                            }
                          }
                          else if ( v31 > -0.33000001 )
                          {
                            goto LABEL_53;
                          }
                          if ( v31 <= -0.94999999 )
                            return;
                          v33 = (float)(result.x * v26) - (float)(result.y * vTargetingIntention.x);
                          v34 = (float)(result.z * vTargetingIntention.x) - (float)(result.x * v27);
                          v35 = (float)(result.y * v30) - (float)(result.z * v26);
                          v36 = (float)(v35 * result.y) - (float)(result.x * v34);
                          v37 = (float)(result.x * v33) - (float)(v35 * result.z);
                          v38 = (__m128)LODWORD(result.z);
                          v38.m128_f32[0] = (float)(result.z * v34) - (float)(result.y * v33);
                          v39 = v38;
                          v39.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v37 * v37))
                                          + (float)(v36 * v36);
                          if ( v39.m128_f32[0] != 0.0 )
                            v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v39));
                          v30 = v32 * v36;
                          v29 = v32 * v37;
                          v28 = v38.m128_f32[0] * v32;
                          vTargetingIntention.x = v28;
                          vTargetingIntention.y = v32 * v37;
                          vTargetingIntention.z = v30;
                          goto LABEL_53;
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

// File Line: 1233
// RVA: 0x2FB8B0
void __fastcall VehicleOverrideWheelFrictionMultiplierTask::Begin(VehicleOverrideWheelFrictionMultiplierTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  int v3; // ebx
  VehicleOverrideWheelFrictionMultiplierTask *v4; // rsi
  UFG::SimComponent *v5; // r8
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimComponent *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rdi
  int v15; // ebp
  int v16; // ebp

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = 0;
  v4 = this;
  if ( v2 )
  {
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = 0i64;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v5 = 0i64;
      }
      else
      {
        if ( (v6 >> 12) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v5 = v7;
      }
    }
    else
    {
      v5 = v2->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = &v4->mPhysicsMoverInterface;
  if ( v4->mPhysicsMoverInterface.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v4->mPhysicsMoverInterface.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v4->mPhysicsMoverInterface.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPhysicsMoverInterface.mPrev;
  }
  v4->mPhysicsMoverInterface.m_pPointer = v5;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v4->mPhysicsMoverInterface.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v12 = v4->mPhysicsMoverInterface.m_pPointer;
  if ( v12 )
  {
    v13 = v12[10].m_SafePointerList.mNode.mPrev;
    if ( v13 )
    {
      v14 = 0i64;
      if ( BYTE4(v13[37].mNext) & 7 )
        v14 = v12[10].m_SafePointerList.mNode.mPrev;
      if ( v14 )
      {
        if ( !((LODWORD(v14[68].mNext) >> 6) & 1) )
        {
          v15 = HIDWORD(v14[37].mNext);
          LODWORD(v14[68].mNext) |= 0x40u;
          v16 = v15 & 7;
          if ( v16 > 0 )
          {
            do
              UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(
                (UFG::PhysicsWheeledVehicle *)v14,
                v3++,
                *(float *)&v4->m_Track[1].vfptr);
            while ( v3 < v16 );
          }
        }
      }
    }
  }
}

// File Line: 1269
// RVA: 0x30B720
char __fastcall VehicleOverrideWheelFrictionMultiplierTask::Update(VehicleOverrideWheelFrictionMultiplierTask *this, float timestep)
{
  UFG::SimComponent *v2; // rax
  VehicleOverrideWheelFrictionMultiplierTask *v3; // rbp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  int v5; // ebx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rdi
  int v7; // esi

  v2 = this->mPhysicsMoverInterface.m_pPointer;
  v3 = this;
  if ( !v2 )
    return 1;
  v4 = v2[10].m_SafePointerList.mNode.mPrev;
  if ( !v4 )
    return 1;
  v5 = 0;
  v6 = 0i64;
  if ( BYTE4(v4[37].mNext) & 7 )
    v6 = v2[10].m_SafePointerList.mNode.mPrev;
  if ( !v6 )
    return 1;
  v7 = HIDWORD(v6[37].mNext) & 7;
  if ( v7 > 0 )
  {
    do
      UFG::PhysicsWheeledVehicle::SetWheelFrictionMultiplier(
        (UFG::PhysicsWheeledVehicle *)v6,
        v5++,
        *(float *)&v3->m_Track[1].vfptr);
    while ( v5 < v7 );
  }
  return 1;
}

// File Line: 1294
// RVA: 0x3017E0
void __fastcall VehicleOverrideWheelFrictionMultiplierTask::End(VehicleOverrideWheelFrictionMultiplierTask *this)
{
  UFG::SimComponent *v1; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax

  v1 = this->mPhysicsMoverInterface.m_pPointer;
  if ( v1 )
  {
    v2 = v1[10].m_SafePointerList.mNode.mPrev;
    if ( v2 )
    {
      v3 = 0i64;
      if ( BYTE4(v2[37].mNext) & 7 )
        v3 = v2;
      if ( v3 )
        LODWORD(v3[68].mNext) &= 0xFFFFFFBF;
    }
  }
}

// File Line: 1310
// RVA: 0x2FC2D0
void __fastcall VehicleSetCollisionShouldTriggerExplosionTask::Begin(VehicleSetCollisionShouldTriggerExplosionTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  VehicleSetCollisionShouldTriggerExplosionTask *v3; // rbx
  UFG::SimComponent *v4; // rdx
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rcx
  ITrack *v12; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = this;
  if ( v2 )
  {
    v5 = v2->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = 0i64;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = 0i64;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v4 = v6;
      }
    }
    else
    {
      v4 = v2->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v3->mPhysicsMoverInterface;
  if ( v3->mPhysicsMoverInterface.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v3->mPhysicsMoverInterface.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v3->mPhysicsMoverInterface.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPhysicsMoverInterface.mPrev;
  }
  v3->mPhysicsMoverInterface.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v3->mPhysicsMoverInterface.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = v3->mPhysicsMoverInterface.m_pPointer;
  if ( v11 )
  {
    v12 = v3->m_Track;
    if ( LOBYTE(v12[1].vfptr) )
    {
      if ( LOBYTE(v12[1].vfptr) == 1 )
        BYTE4(v11[14].vfptr) &= 0xEFu;
    }
    else
    {
      BYTE4(v11[14].vfptr) |= 0x10u;
    }
  }
}

// File Line: 1323
// RVA: 0x30B7D0
bool __fastcall VehicleSetCollisionShouldTriggerExplosionTask::Update(VehicleSetCollisionShouldTriggerExplosionTask *this, float timestep)
{
  UFG::SimComponent *v2; // rdx
  ITrack *v3; // rax
  int v4; // ecx
  bool result; // al

  v2 = this->mPhysicsMoverInterface.m_pPointer;
  if ( !v2 )
    return 1;
  v3 = this->m_Track;
  v4 = LOBYTE(v3[1].vfptr);
  if ( !LOBYTE(v3[1].vfptr) )
  {
    BYTE4(v2[14].vfptr) |= 0x10u;
    return 1;
  }
  result = 1;
  if ( v4 == 1 )
    BYTE4(v2[14].vfptr) &= 0xEFu;
  return result;
}

// File Line: 1331
// RVA: 0x301840
void __fastcall VehicleSetCollisionShouldTriggerExplosionTask::End(VehicleSetCollisionShouldTriggerExplosionTask *this)
{
  UFG::SimComponent *v1; // rdx
  ITrack *v2; // rax

  v1 = this->mPhysicsMoverInterface.m_pPointer;
  if ( v1 )
  {
    v2 = this->m_Track;
    if ( BYTE1(v2[1].vfptr) )
    {
      if ( BYTE1(v2[1].vfptr) == 1 )
        BYTE4(v1[14].vfptr) &= 0xEFu;
    }
    else
    {
      BYTE4(v1[14].vfptr) |= 0x10u;
    }
  }
}

// File Line: 1355
// RVA: 0x2FB5F0
void __fastcall VehicleLockHighLODTask::Begin(VehicleLockHighLODTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  VehicleLockHighLODTask *v3; // rbx
  UFG::SimComponent *v4; // rdx
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::PhysicsMoverInterface *v11; // rcx

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = this;
  if ( v2 )
  {
    v5 = v2->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = 0i64;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = 0i64;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v4 = v6;
      }
    }
    else
    {
      v4 = v2->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v3->mPhysicsMoverInterface;
  if ( v3->mPhysicsMoverInterface.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v3->mPhysicsMoverInterface.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v3->mPhysicsMoverInterface.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPhysicsMoverInterface.mPrev;
  }
  v3->mPhysicsMoverInterface.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v3->mPhysicsMoverInterface.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = (UFG::PhysicsMoverInterface *)v3->mPhysicsMoverInterface.m_pPointer;
  if ( v11 )
    UFG::PhysicsMoverInterface::LockHighLod(v11, 0, 0.0);
}

// File Line: 1369
// RVA: 0x301730
void __fastcall VehicleLockHighLODTask::End(VehicleLockHighLODTask *this)
{
  JUMPOUT(this->mPhysicsMoverInterface.m_pPointer, 0i64, UFG::PhysicsMoverInterface::UnlockHighLod);
}

// File Line: 1381
// RVA: 0x2FB9F0
void __fastcall VehiclePreventWheelieTask::Begin(VehiclePreventWheelieTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  VehiclePreventWheelieTask *v3; // rbx
  UFG::SimComponent *v4; // rdx
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = this;
  if ( v2 )
  {
    v5 = v2->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = 0i64;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = 0i64;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v4 = v6;
      }
    }
    else
    {
      v4 = v2->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v3->mPhysicsMoverInterface;
  if ( v3->mPhysicsMoverInterface.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v3->mPhysicsMoverInterface.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v3->mPhysicsMoverInterface.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPhysicsMoverInterface.mPrev;
  }
  v3->mPhysicsMoverInterface.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v3->mPhysicsMoverInterface.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = v3->mPhysicsMoverInterface.m_pPointer;
  if ( v11 )
    LODWORD(v11[1].m_pSimObject) |= 0x100u;
}

// File Line: 1395
// RVA: 0x301820
void __fastcall VehiclePreventWheelieTask::End(VehiclePreventWheelieTask *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->mPhysicsMoverInterface.m_pPointer;
  if ( v1 )
    LODWORD(v1[1].m_pSimObject) &= 0xFFFFFEFF;
}

// File Line: 1408
// RVA: 0x2FB510
void __fastcall VehicleLightTask::Begin(VehicleLightTask *this, ActionContext *context)
{
  VehicleLightTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::VehicleEffectsComponent *v6; // rcx
  ITrack *v7; // rdx
  int v8; // er8

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
  }
  else
  {
    if ( (v4 & 0x8000u) != 0 )
    {
      v6 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent;
      goto LABEL_12;
    }
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleEffectsComponent::_TypeUID);
    }
  }
  v6 = (UFG::VehicleEffectsComponent *)v5;
LABEL_12:
  if ( v6 )
  {
    v7 = v2->m_Track;
    v8 = HIDWORD(v7[1].vfptr);
    if ( v8 )
    {
      if ( v8 == 1 )
      {
        if ( LOBYTE(v7[1].vfptr) )
          UFG::VehicleEffectsComponent::TurnOnTaxiLight(v6);
        else
          UFG::VehicleEffectsComponent::TurnOffTaxiLight(v6);
      }
    }
    else if ( LOBYTE(v7[1].vfptr) )
    {
      UFG::VehicleEffectsComponent::TurnOnInteriorLight(v6);
    }
    else
    {
      UFG::VehicleEffectsComponent::TurnOffInteriorLight(v6);
    }
  }
}

// File Line: 1437
// RVA: 0x2E29E0
void __fastcall VehicleStopTask::VehicleStopTask(VehicleStopTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<VehicleStopTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&VehicleStopTask::`vftable';
  v2 = &this->m_pPhysicsMI;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pPhysicsMI.m_pPointer = 0i64;
}

// File Line: 1438
// RVA: 0x2E6090
void __fastcall VehicleStopTask::~VehicleStopTask(VehicleStopTask *this)
{
  VehicleStopTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&VehicleStopTask::`vftable';
  v2 = &this->m_pPhysicsMI;
  if ( this->m_pPhysicsMI.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 1441
// RVA: 0x2FCA60
void __fastcall VehicleStopTask::Begin(VehicleStopTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  UFG::SimComponent *v3; // rdi
  ActionContext *v4; // rbp
  VehicleStopTask *v5; // rsi
  UFG::SimComponent *v6; // r8
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v9; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::CharacterOccupantComponent *v15; // rax
  UFG::SimObjectGame *v16; // rax
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::SimObjectCVBase *v22; // rcx
  unsigned __int16 v23; // dx
  UFG::AiDriverComponent *v24; // rax
  UFG::AiDriverComponent *v25; // rbx
  int v26; // eax
  UFG::SimComponent *v27; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = pContext;
  v5 = this;
  if ( v2 )
  {
    v7 = v2->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = 0i64;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v6 = 0i64;
      }
      else
      {
        if ( (v7 >> 12) & 1 )
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v6 = v8;
      }
    }
    else
    {
      v6 = v2->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    v6 = 0i64;
  }
  v9 = &v5->m_pPhysicsMI;
  if ( v5->m_pPhysicsMI.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v5->m_pPhysicsMI.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v5->m_pPhysicsMI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pPhysicsMI.mPrev;
  }
  v5->m_pPhysicsMI.m_pPointer = v6;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v5->m_pPhysicsMI.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  if ( !v5->m_pPhysicsMI.m_pPointer )
  {
    v13 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( v13 )
    {
      v14 = v13->m_Flags;
      if ( (v14 >> 14) & 1 )
      {
        v15 = (UFG::CharacterOccupantComponent *)v13->m_Components.p[44].m_pComponent;
      }
      else if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
          v15 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v13,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        else
          v15 = (UFG::CharacterOccupantComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v13,
                                                                        UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
      }
      else
      {
        v15 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v13,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( v15 )
      {
        v16 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v15);
        if ( v16 )
        {
          v17 = v16->m_Flags;
          if ( !((v17 >> 14) & 1) )
          {
            if ( (v17 & 0x8000u) == 0 )
            {
              if ( !((v17 >> 13) & 1) )
              {
                if ( (v17 >> 12) & 1 )
                  v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::PhysicsMoverInterface::_TypeUID);
                else
                  v18 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v16->vfptr,
                          UFG::PhysicsMoverInterface::_TypeUID);
                v3 = v18;
              }
            }
            else
            {
              v3 = v16->m_Components.p[34].m_pComponent;
            }
          }
          if ( v5->m_pPhysicsMI.m_pPointer )
          {
            v19 = v9->mPrev;
            v20 = v5->m_pPhysicsMI.mNext;
            v19->mNext = v20;
            v20->mPrev = v19;
            v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
            v5->m_pPhysicsMI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pPhysicsMI.mPrev;
          }
          v5->m_pPhysicsMI.m_pPointer = v3;
          if ( v3 )
          {
            v21 = v3->m_SafePointerList.mNode.mPrev;
            v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
            v9->mPrev = v21;
            v5->m_pPhysicsMI.mNext = &v3->m_SafePointerList.mNode;
            v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
          }
        }
      }
    }
  }
  if ( v5->m_pPhysicsMI.m_pPointer )
  {
    v22 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
    if ( v22 )
    {
      v23 = v22->m_Flags;
      if ( (v23 >> 14) & 1 )
      {
        v24 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v22);
      }
      else if ( (v23 & 0x8000u) == 0 )
      {
        if ( (v23 >> 13) & 1 )
          v24 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v22->vfptr,
                                            UFG::AiDriverComponent::_TypeUID);
        else
          v24 = (UFG::AiDriverComponent *)((v23 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v22->vfptr,
                                                               UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v22->vfptr,
                                                                                                     UFG::AiDriverComponent::_TypeUID));
      }
      else
      {
        v24 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v22);
      }
      v25 = v24;
      if ( v24 )
      {
        if ( LOBYTE(v5->m_Track[1].vfptr) )
        {
          v26 = UFG::qRandom(2, &UFG::qDefaultSeed);
          UFG::AiDriverComponent::SetSteeringLock(v25, (float)(2 * v26 - 1));
        }
        UFG::AiDriverComponent::SetGasBrakeLock(v25, 1.0);
      }
    }
    v27 = v5->m_pPhysicsMI.m_pPointer;
    if ( v27 )
      LODWORD(v27[1].m_pSimObject) |= 0x40u;
  }
}

// File Line: 1479
// RVA: 0x30B820
char __fastcall VehicleStopTask::Update(VehicleStopTask *this, float timestep)
{
  UFG::SimComponent *v2; // rdx
  char result; // al

  v2 = this->m_pPhysicsMI.m_pPointer;
  result = 1;
  if ( v2
    && COERCE_FLOAT(COERCE_UNSIGNED_INT(3.5999999 * *((float *)&v2[10].m_BoundComponentHandles.mNode.mPrev + 1)) & _xmm) < 1.0
    && *(float *)&v2[1].m_Flags != 0.0 )
  {
    result = 0;
  }
  return result;
}

// File Line: 1496
// RVA: 0x301890
void __fastcall VehicleStopTask::End(VehicleStopTask *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->m_pPhysicsMI.m_pPointer;
  if ( v1 )
    LODWORD(v1[1].m_pSimObject) &= 0xFFFFFFBF;
}

// File Line: 1507
// RVA: 0x2E2930
void __fastcall VehicleSteerTask::VehicleSteerTask(VehicleSteerTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<VehicleSteerTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&VehicleSteerTask::`vftable';
  v2 = &this->m_pPhysicsMI;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pPhysicsMI.m_pPointer = 0i64;
}

// File Line: 1508
// RVA: 0x2E5F90
void __fastcall VehicleSteerTask::~VehicleSteerTask(VehicleSteerTask *this)
{
  VehicleSteerTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&VehicleSteerTask::`vftable';
  v2 = &this->m_pPhysicsMI;
  if ( this->m_pPhysicsMI.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 1511
// RVA: 0x2FC840
void __fastcall VehicleSteerTask::Begin(VehicleSteerTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  UFG::SimComponent *v3; // rdi
  ActionContext *v4; // rsi
  VehicleSteerTask *v5; // rbp
  UFG::SimComponent *v6; // r8
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v9; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::CharacterOccupantComponent *v15; // rax
  UFG::SimObjectGame *v16; // rax
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::SimComponent *v22; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = pContext;
  v5 = this;
  if ( v2 )
  {
    v7 = v2->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = 0i64;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v6 = 0i64;
      }
      else
      {
        if ( (v7 >> 12) & 1 )
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v6 = v8;
      }
    }
    else
    {
      v6 = v2->m_Components.p[34].m_pComponent;
    }
  }
  else
  {
    v6 = 0i64;
  }
  v9 = &v5->m_pPhysicsMI;
  if ( v5->m_pPhysicsMI.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v5->m_pPhysicsMI.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v5->m_pPhysicsMI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pPhysicsMI.mPrev;
  }
  v5->m_pPhysicsMI.m_pPointer = v6;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v5->m_pPhysicsMI.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  if ( !v5->m_pPhysicsMI.m_pPointer )
  {
    v13 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( v13 )
    {
      v14 = v13->m_Flags;
      if ( (v14 >> 14) & 1 )
      {
        v15 = (UFG::CharacterOccupantComponent *)v13->m_Components.p[44].m_pComponent;
      }
      else if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
          v15 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v13,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        else
          v15 = (UFG::CharacterOccupantComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v13,
                                                                        UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
      }
      else
      {
        v15 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v13,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( v15 )
      {
        v16 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v15);
        if ( v16 )
        {
          v17 = v16->m_Flags;
          if ( !((v17 >> 14) & 1) )
          {
            if ( (v17 & 0x8000u) == 0 )
            {
              if ( !((v17 >> 13) & 1) )
              {
                if ( (v17 >> 12) & 1 )
                  v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::PhysicsMoverInterface::_TypeUID);
                else
                  v18 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v16->vfptr,
                          UFG::PhysicsMoverInterface::_TypeUID);
                v3 = v18;
              }
            }
            else
            {
              v3 = v16->m_Components.p[34].m_pComponent;
            }
          }
          if ( v5->m_pPhysicsMI.m_pPointer )
          {
            v19 = v9->mPrev;
            v20 = v5->m_pPhysicsMI.mNext;
            v19->mNext = v20;
            v20->mPrev = v19;
            v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
            v5->m_pPhysicsMI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pPhysicsMI.mPrev;
          }
          v5->m_pPhysicsMI.m_pPointer = v3;
          if ( v3 )
          {
            v21 = v3->m_SafePointerList.mNode.mPrev;
            v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
            v9->mPrev = v21;
            v5->m_pPhysicsMI.mNext = &v3->m_SafePointerList.mNode;
            v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
          }
        }
      }
    }
  }
  v22 = v5->m_pPhysicsMI.m_pPointer;
  if ( v22 )
    LODWORD(v22[1].m_pSimObject) |= 0x80u;
}

// File Line: 1535
// RVA: 0x30B800
char __fastcall VehicleSteerTask::Update(VehicleSteerTask *this, float timestep)
{
  UFG::SimComponent *v2; // rdx

  v2 = this->m_pPhysicsMI.m_pPointer;
  if ( v2 )
    v2[1].m_TypeUID = (unsigned int)this->m_Track[1].vfptr;
  return 1;
}

// File Line: 1547
// RVA: 0x301870
void __fastcall VehicleSteerTask::End(VehicleSteerTask *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->m_pPhysicsMI.m_pPointer;
  if ( v1 )
    LODWORD(v1[1].m_pSimObject) &= 0xFFFFFF7F;
}

// File Line: 1558
// RVA: 0x2FAAA0
void __fastcall VehicleEngineAutoDeteriorateTask::Begin(VehicleEngineAutoDeteriorateTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::PhysicsMoverInterface *v4; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( !((v3 >> 14) & 1) )
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          return;
        if ( (v3 >> 12) & 1 )
          v4 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v2,
                                               UFG::PhysicsMoverInterface::_TypeUID);
        else
          v4 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v4 = (UFG::PhysicsMoverInterface *)v2->m_Components.p[34].m_pComponent;
      }
      if ( v4 )
        UFG::PhysicsMoverInterface::AutoDeteriorateEngineIfNotAlready(v4);
    }
  }
}

// File Line: 1571
// RVA: 0x2FCD30
void __fastcall VehicleTriggerExplosionTask::Begin(VehicleTriggerExplosionTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::PhysicsMoverInterface *v4; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( !((v3 >> 14) & 1) )
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          return;
        if ( (v3 >> 12) & 1 )
          v4 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v2,
                                               UFG::PhysicsMoverInterface::_TypeUID);
        else
          v4 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v4 = (UFG::PhysicsMoverInterface *)v2->m_Components.p[34].m_pComponent;
      }
      if ( v4 )
        UFG::PhysicsMoverInterface::TriggerExplosion(v4);
    }
  }
}

// File Line: 1583
// RVA: 0x2FD160
void __fastcall VehicleTurnOnDisabledEffectTask::Begin(VehicleTurnOnDisabledEffectTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // rdi
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::VehicleEffectsComponent *v6; // rbx
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = pContext;
  if ( !v2 )
    return;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleEffectsComponent::_TypeUID);
LABEL_11:
    v6 = (UFG::VehicleEffectsComponent *)v5;
    goto LABEL_12;
  }
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::VehicleEffectsComponent::_TypeUID);
    }
    goto LABEL_11;
  }
  v6 = (UFG::VehicleEffectsComponent *)v2->m_Components.p[32].m_pComponent;
LABEL_12:
  if ( v6 )
  {
    v7 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
    if ( !v7
      || ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::CopUnitComponent::_TypeUID)) : (v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CopUnitComponent::_TypeUID))) : (v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CopUnitComponent::_TypeUID))) : (v9 = v7->m_Components.p[17].m_pComponent)) : (v9 = v7->m_Components.p[17].m_pComponent),
          !v9 || UFG::VehicleEffectsComponent::AreCopLightsOn(v6)) )
    {
      UFG::VehicleEffectsComponent::TurnOnDisabledEffect(v6);
    }
  }
}

// File Line: 1625
// RVA: 0x2E9970
void __fastcall BikePhysicsEnableConstraintTask::Begin(BikePhysicsEnableConstraintTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  BikePhysicsEnableConstraintTask *v3; // rbx
  UFG::BikePhysicsMoverComponent *v4; // rdx
  unsigned __int16 v5; // cx
  UFG::BikePhysicsMoverComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::BikePhysicsMoverComponent> *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::BikePhysicsMoverComponent *v11; // rcx
  UFG::PhysicsMotorBike *v12; // rax
  ITrack *v13; // rcx

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = this;
  if ( v2 )
  {
    v5 = v2->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = 0i64;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::BikePhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v2,
                                                   UFG::BikePhysicsMoverComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::BikePhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v2,
                                                   UFG::BikePhysicsMoverComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::BikePhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v2->vfptr,
                                                   UFG::BikePhysicsMoverComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>((UFG::SimObjectVehicle *)context->mSimObject.m_pPointer);
      }
      v4 = v6;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v3->m_pBikePhysicsMoverComponent;
  if ( v3->m_pBikePhysicsMoverComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v3->m_pBikePhysicsMoverComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v3->m_pBikePhysicsMoverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pBikePhysicsMoverComponent.mPrev;
  }
  v3->m_pBikePhysicsMoverComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v3->m_pBikePhysicsMoverComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = (UFG::BikePhysicsMoverComponent *)v3->m_pBikePhysicsMoverComponent.m_pPointer;
  if ( v11 )
  {
    v12 = UFG::BikePhysicsMoverComponent::GetPhysicsBike(v11);
    if ( v12 )
    {
      v13 = v3->m_Track;
      if ( LOBYTE(v13[1].vfptr) )
      {
        if ( LOBYTE(v13[1].vfptr) == 1 )
          v12->mDisableConstraint = 1;
      }
      else
      {
        v12->mDisableConstraint = 0;
      }
    }
  }
}

// File Line: 1651
// RVA: 0x2FE160
void __fastcall BikePhysicsEnableConstraintTask::End(BikePhysicsEnableConstraintTask *this)
{
  BikePhysicsEnableConstraintTask *v1; // rbx
  UFG::BikePhysicsMoverComponent *v2; // rcx
  UFG::PhysicsMotorBike *v3; // rax
  ITrack *v4; // rcx

  v1 = this;
  v2 = (UFG::BikePhysicsMoverComponent *)this->m_pBikePhysicsMoverComponent.m_pPointer;
  if ( v2 )
  {
    v3 = UFG::BikePhysicsMoverComponent::GetPhysicsBike(v2);
    if ( v3 )
    {
      v4 = v1->m_Track;
      if ( BYTE1(v4[1].vfptr) )
      {
        if ( BYTE1(v4[1].vfptr) == 1 )
          v3->mDisableConstraint = 1;
      }
      else
      {
        v3->mDisableConstraint = 0;
      }
    }
  }
}

// File Line: 1673
// RVA: 0x2F0670
void __fastcall MotorBikeStandUpTask::Begin(MotorBikeStandUpTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::SimObjectVehicle *v5; // rax
  unsigned __int16 v6; // dx
  UFG::BikePhysicsMoverComponent *v7; // rax
  UFG::PhysicsMotorBike *v8; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CharacterOccupantComponent *)v2->m_Components.p[44].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v2,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v4 = (UFG::CharacterOccupantComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v2,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v2,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v4 )
    {
      v5 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v4);
      if ( v5 )
      {
        v6 = v5->m_Flags;
        if ( !((v6 >> 14) & 1) )
        {
          if ( (v6 & 0x8000u) == 0 )
          {
            if ( (v6 >> 13) & 1 )
            {
              v7 = (UFG::BikePhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v5->vfptr,
                                                       UFG::BikePhysicsMoverComponent::_TypeUID);
            }
            else if ( (v6 >> 12) & 1 )
            {
              v7 = (UFG::BikePhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v5->vfptr,
                                                       UFG::BikePhysicsMoverComponent::_TypeUID);
            }
            else
            {
              v7 = (UFG::BikePhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v5->vfptr,
                                                       UFG::BikePhysicsMoverComponent::_TypeUID);
            }
          }
          else
          {
            v7 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v5);
          }
          if ( v7 )
          {
            v8 = UFG::BikePhysicsMoverComponent::GetPhysicsBike(v7);
            if ( v8 )
              UFG::PhysicsMotorBike::StandUpright(v8);
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
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<VehicleDoorPhysicsTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&VehicleDoorPhysicsTask::`vftable';
  this->mContext = 0i64;
}

// File Line: 1698
// RVA: 0x2FA9F0
void __fastcall VehicleDoorPhysicsTask::Begin(VehicleDoorPhysicsTask *this, ActionContext *pContext)
{
  VehicleDoorPhysicsTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rax
  UFG::PhysicsVehicle *v6; // rcx

  v2 = this;
  this->mContext = pContext;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          return;
        if ( (v4 >> 12) & 1 )
          v5 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v3,
                                               UFG::PhysicsMoverInterface::_TypeUID);
        else
          v5 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
      }
      if ( v5 )
      {
        v6 = v5->mPhysicsVehicle;
        if ( v6 )
        {
          if ( (*((_DWORD *)v6 + 0x97) & 7) == 4 )
            UFG::PhysicsCar::SetDesiredAttachmentState(
              (UFG::PhysicsCar *)v6,
              (UFG::VehicleAttachmentID)LOBYTE(v2->m_Track[1].vfptr),
              (UFG::VehicleAttachmentState)BYTE1(v2->m_Track[1].vfptr));
        }
      }
    }
  }
}

// File Line: 1720
// RVA: 0x301670
void __fastcall VehicleDoorPhysicsTask::End(VehicleDoorPhysicsTask *this)
{
  VehicleDoorPhysicsTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( !((v3 >> 14) & 1) )
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          return;
        if ( (v3 >> 12) & 1 )
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v4 = v2->m_Components.p[34].m_pComponent;
      }
      if ( v4 )
      {
        v5 = v4[10].m_SafePointerList.mNode.mPrev;
        if ( v5 )
        {
          if ( (HIDWORD(v5[37].mNext) & 7) == 4 )
            UFG::PhysicsCar::SetDesiredAttachmentState(
              (UFG::PhysicsCar *)v5,
              (UFG::VehicleAttachmentID)LOBYTE(v1->m_Track[1].vfptr),
              (UFG::VehicleAttachmentState)BYTE2(v1->m_Track[1].vfptr));
        }
      }
    }
  }
}

