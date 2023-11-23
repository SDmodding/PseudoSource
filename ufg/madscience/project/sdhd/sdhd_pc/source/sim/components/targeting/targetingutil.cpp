// File Line: 51
// RVA: 0x569950
UFG::SimObject *__fastcall UFG::getTarget(
        UFG::SimObject *pSimObject,
        UFG::TargetingSystemBaseComponent *pTSBC,
        unsigned int eTargetType)
{
  __int64 v3; // rsi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v11; // rdx
  unsigned int v12; // r8d
  unsigned int v13; // r9d

  v3 = eTargetType;
  if ( pTSBC
    && ((__int64 (__fastcall *)(UFG::TargetingSystemBaseComponent *))pTSBC->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor)(pTSBC) )
  {
    return pTSBC->m_pTargets[(unsigned __int8)pTSBC->m_pTargetingMap->m_Map.p[v3]].m_pTarget.m_pPointer;
  }
  if ( (_DWORD)v3 != 2 )
  {
    if ( pTSBC )
      return pTSBC->m_pTargets[(unsigned __int8)pTSBC->m_pTargetingMap->m_Map.p[v3]].m_pTarget.m_pPointer;
    return 0i64;
  }
  if ( pSimObject )
  {
    m_Flags = pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[15].m_pComponent;
      goto LABEL_26;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = pSimObject->m_Components.p[15].m_pComponent;
      goto LABEL_26;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)pSimObject[1].vfptr;
      size = pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v11 = &pSimObject->m_Components.p[vfptr];
        while ( (v11->m_TypeUID & 0xFE000000) != (UFG::HitReactionComponent::_TypeUID & 0xFE000000)
             || (UFG::HitReactionComponent::_TypeUID & ~v11->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v11;
          if ( vfptr >= size )
            goto LABEL_16;
        }
LABEL_17:
        m_pComponent = v11->m_pComponent;
        goto LABEL_26;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::HitReactionComponent::_TypeUID);
LABEL_26:
        if ( m_pComponent )
          return *(UFG::SimObject **)&m_pComponent[3].m_TypeUID;
        return 0i64;
      }
      v12 = (unsigned int)pSimObject[1].vfptr;
      v13 = pSimObject->m_Components.size;
      if ( v12 < v13 )
      {
        v11 = &pSimObject->m_Components.p[v12];
        while ( (v11->m_TypeUID & 0xFE000000) != (UFG::HitReactionComponent::_TypeUID & 0xFE000000)
             || (UFG::HitReactionComponent::_TypeUID & ~v11->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v12;
          ++v11;
          if ( v12 >= v13 )
          {
            m_pComponent = 0i64;
            goto LABEL_26;
          }
        }
        goto LABEL_17;
      }
    }
LABEL_16:
    m_pComponent = 0i64;
    goto LABEL_26;
  }
  return 0i64;
}

// File Line: 83
// RVA: 0x569B20
UFG::SimObject *__fastcall UFG::getTarget(UFG::SimObject *pSimObject, unsigned int eTargetType)
{
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax
  signed __int16 m_Flags; // cx
  unsigned int v7; // r8d
  unsigned int v8; // r9d
  UFG::SimComponentHolder *i; // rdx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d

  if ( eTargetType == 1 )
    return pSimObject;
  if ( !pSimObject )
    goto LABEL_4;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)pSimObject->m_Components.p[20].m_pComponent;
    return UFG::getTarget(pSimObject, m_pComponent, eTargetType);
  }
  if ( (m_Flags & 0x2000) == 0 )
  {
    if ( (m_Flags & 0x1000) == 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                            pSimObject,
                                                            UFG::TargetingSystemBaseComponent::_TypeUID);
      return UFG::getTarget(pSimObject, m_pComponent, eTargetType);
    }
    vfptr = (unsigned int)pSimObject[1].vfptr;
    size = pSimObject->m_Components.size;
    if ( vfptr >= size )
      goto LABEL_4;
    for ( i = &pSimObject->m_Components.p[vfptr];
          (i->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
       || (UFG::TargetingSystemBaseComponent::_TypeUID & ~i->m_TypeUID & 0x1FFFFFF) != 0;
          ++i )
    {
      if ( ++vfptr >= size )
      {
        m_pComponent = 0i64;
        return UFG::getTarget(pSimObject, m_pComponent, eTargetType);
      }
    }
LABEL_15:
    m_pComponent = (UFG::TargetingSystemBaseComponent *)i->m_pComponent;
    return UFG::getTarget(pSimObject, m_pComponent, eTargetType);
  }
  v7 = (unsigned int)pSimObject[1].vfptr;
  v8 = pSimObject->m_Components.size;
  if ( v7 < v8 )
  {
    for ( i = &pSimObject->m_Components.p[v7];
          (i->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
       || (UFG::TargetingSystemBaseComponent::_TypeUID & ~i->m_TypeUID & 0x1FFFFFF) != 0;
          ++i )
    {
      if ( ++v7 >= v8 )
      {
        m_pComponent = 0i64;
        return UFG::getTarget(pSimObject, m_pComponent, eTargetType);
      }
    }
    goto LABEL_15;
  }
LABEL_4:
  m_pComponent = 0i64;
  return UFG::getTarget(pSimObject, m_pComponent, eTargetType);
}

// File Line: 96
// RVA: 0x569C80
UFG::SimObject *__fastcall UFG::getTarget(ActionContext *pContext, unsigned int eTargetType)
{
  return UFG::getTarget(pContext->mSimObject.m_pPointer, eTargetType);
}

// File Line: 109
// RVA: 0x565C10
__int64 __fastcall UFG::closestJointID(
        Creature *creature,
        int jointLimit,
        UFG::qVector4 *position,
        UFG::qVector4 *vBoneOut)
{
  unsigned int v4; // ebp
  float v5; // xmm8_4
  int m_size; // esi
  int v10; // ebx
  float y; // xmm5_4
  float z; // xmm6_4
  float w; // xmm7_4
  float v14; // xmm3_4
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-88h] BYREF

  v4 = 0;
  v5 = FLOAT_3_4028235e38;
  m_size = creature->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton->m_bones.m_size;
  v10 = 0;
  if ( jointLimit < m_size )
    m_size = jointLimit;
  if ( m_size > 0 )
  {
    do
    {
      Creature::GetTransform(creature, v10, &transform);
      y = transform.v3.y;
      z = transform.v3.z;
      w = transform.v3.w;
      v14 = (float)((float)((float)((float)(transform.v3.y - position->y) * (float)(transform.v3.y - position->y))
                          + (float)((float)(transform.v3.x - position->x) * (float)(transform.v3.x - position->x)))
                  + (float)((float)(transform.v3.z - position->z) * (float)(transform.v3.z - position->z)))
          + (float)((float)(transform.v3.w - position->w) * (float)(transform.v3.w - position->w));
      if ( v14 < v5 )
      {
        vBoneOut->x = transform.v3.x;
        vBoneOut->y = y;
        vBoneOut->z = z;
        v5 = v14;
        v4 = v10;
        vBoneOut->w = w;
      }
      ++v10;
    }
    while ( v10 < m_size );
  }
  return v4;
}

// File Line: 152
// RVA: 0x553240
bool __fastcall UFG::TargetAttach(
        UFG::SimObjectProp *simObject,
        unsigned int targetType,
        UFG::SimObjectProp *pOverrideTarget,
        UFG::SimObject **ppOutSimObjectTarget,
        UFG::qSymbolUC *attachJoint,
        UFG::qSymbolUC *targetAttachJoint,
        float blendInTime,
        bool attachRelative,
        float attachRelativeMaxDistance,
        bool attachToTarget,
        bool addToInventory,
        bool assignTarget,
        unsigned int assignmentTargetType,
        bool lockTarget,
        bool positionOnly,
        bool positionXYOnly,
        bool *managePowerLevel)
{
  UFG::SimObject **v17; // r14
  __int64 v19; // r12
  UFG::SimObjectProp *v20; // rdi
  signed __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *m_pComponent; // rcx
  unsigned int v23; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r9d
  unsigned int size; // r11d
  UFG::SimComponentHolder *p; // rbx
  Creature *mCreature; // r13
  int v30; // r15d
  __int16 v31; // cx
  UFG::TargetingSystemBaseComponent *v32; // rax
  unsigned int v33; // r9d
  unsigned int v34; // r11d
  UFG::SimComponentHolder *v35; // r14
  __int64 v36; // r8
  unsigned int v37; // r9d
  unsigned int v38; // r11d
  int attachmentBoneID; // r12d
  signed __int16 v40; // cx
  UFG::SimComponent *v41; // rcx
  UFG::CharacterAnimationComponent *v42; // rax
  unsigned int v43; // r9d
  unsigned int v44; // r11d
  UFG::SimComponentHolder *v45; // rbx
  Creature *v46; // r14
  signed __int16 v47; // cx
  unsigned int v48; // r8d
  unsigned int v49; // r10d
  UFG::SimComponentHolder *v50; // rdx
  UFG::PowerManagementComponent *v51; // rax
  unsigned int v52; // r8d
  unsigned int v53; // r10d
  unsigned int v54; // r8d
  unsigned int v55; // r10d
  unsigned int v56; // r8d
  unsigned int v57; // r10d
  int v58; // eax
  UFG::qNode<Attachment,Attachment> **v59; // rax
  __int16 v60; // cx
  UFG::WorldContextComponent *v61; // r15
  unsigned int v62; // r8d
  unsigned int v63; // r10d
  __int64 v64; // rdx
  unsigned int v65; // r8d
  unsigned int v66; // r10d
  unsigned int v67; // r8d
  unsigned int v68; // r10d
  UFG::TransformNodeComponent *v69; // rax
  bool useRubberBand; // r12
  UFG::SimObject *v71; // rcx
  __int16 v72; // dx
  UFG::InterestPoint *v73; // r14
  bool PositionSyncRequired; // bl
  bool RotationSyncRequired; // r13
  bool RequiresSync; // al
  __int16 v77; // cx
  UFG::SimComponent *v78; // rcx
  unsigned int v79; // r8d
  unsigned int v80; // r10d
  UFG::SimComponentHolder *v81; // rbx
  __int64 v82; // rdx
  unsigned int v83; // r8d
  unsigned int v84; // r10d
  float v85; // xmm10_4
  float v86; // xmm9_4
  __int128 y_low; // xmm8
  float v88; // xmm6_4
  __m128 v89; // xmm2
  float v90; // xmm7_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector4 v92; // xmm2
  UFG::qVector4 v93; // xmm1
  float v94; // xmm9_4
  float v95; // xmm10_4
  UFG::allocator::free_link *v96; // rax
  int v97; // edx
  Creature *v98; // rcx
  UFG::SimObjectCharacter *v99; // rbx
  __int16 v100; // cx
  UFG::InventoryComponent *v101; // rax
  unsigned int v102; // r8d
  unsigned int v103; // r10d
  UFG::SimComponentHolder *v104; // rsi
  __int64 v105; // rdx
  unsigned int v106; // r8d
  unsigned int v107; // r10d
  unsigned int v108; // r8d
  unsigned int v109; // r10d
  __int64 v110; // rdx
  int boneID; // [rsp+40h] [rbp-C0h]
  UFG::TargetingSystemBaseComponent *v112; // [rsp+48h] [rbp-B8h]
  UFG::qVector4 vBoneOut; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qMatrix44 transform; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v115; // [rsp+A0h] [rbp-60h]
  UFG::qMatrix44 relativePositionWS; // [rsp+B0h] [rbp-50h] BYREF
  bool v117; // [rsp+190h] [rbp+90h]

  v115 = -2i64;
  v17 = ppOutSimObjectTarget;
  v19 = (int)targetType;
  v20 = simObject;
  v117 = 0;
  if ( !simObject )
    return v117;
  m_Flags = simObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)v20->m_Components.p[9].m_pComponent;
    v23 = UFG::CharacterAnimationComponent::_TypeUID;
    if ( !m_pComponent
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)v20->m_Components.p[9].m_pComponent;
    v23 = UFG::CharacterAnimationComponent::_TypeUID;
    if ( !m_pComponent || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_6;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v20);
LABEL_23:
    v23 = UFG::CharacterAnimationComponent::_TypeUID;
    m_pComponent = ComponentOfType;
    goto LABEL_24;
  }
  v23 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( (m_Flags & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            v20,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  mComponentTableEntryCount = v20->mComponentTableEntryCount;
  size = v20->m_Components.size;
  if ( mComponentTableEntryCount >= size )
  {
LABEL_6:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
  p = v20->m_Components.p;
  while ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) != 0 )
  {
    if ( ++mComponentTableEntryCount >= size )
      goto LABEL_6;
  }
  m_pComponent = (UFG::CharacterAnimationComponent *)p[mComponentTableEntryCount].m_pComponent;
LABEL_24:
  if ( m_pComponent )
  {
    mCreature = m_pComponent->mCreature;
    if ( !mCreature )
      return 0;
    v30 = 0;
    boneID = 0;
    if ( attachJoint->mUID != -1 )
    {
      if ( mCreature->mPose.mRigHandle.mData )
      {
        v30 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, attachJoint->mUID);
        v23 = UFG::CharacterAnimationComponent::_TypeUID;
      }
      else
      {
        v30 = -1;
      }
      boneID = v30;
    }
    v31 = v20->m_Flags;
    if ( (v31 & 0x4000) != 0 )
    {
      v32 = (UFG::TargetingSystemBaseComponent *)v20->m_Components.p[20].m_pComponent;
LABEL_54:
      v112 = v32;
      if ( !pOverrideTarget )
      {
        pOverrideTarget = (UFG::SimObjectProp *)UFG::getTarget(v20, v32, (UFG::eTargetTypeEnum)v19);
        v23 = UFG::CharacterAnimationComponent::_TypeUID;
        if ( !pOverrideTarget )
        {
          UFG::qPrintf("WARNING: TargetAttach: Target Not Found! (%s)\n", UFG::TargetTypeEnumNames[v19]);
          if ( managePowerLevel )
            *managePowerLevel = 0;
          return v117;
        }
      }
      if ( v17 )
      {
        *v17 = pOverrideTarget;
        v23 = UFG::CharacterAnimationComponent::_TypeUID;
      }
      attachmentBoneID = 0;
      v40 = pOverrideTarget->m_Flags;
      if ( (v40 & 0x4000) != 0 )
      {
        v41 = pOverrideTarget->m_Components.p[9].m_pComponent;
        if ( v41 && ((v23 ^ v41->m_TypeUID) & 0xFE000000) == 0 && (v23 & ~v41->m_TypeUID & 0x1FFFFFF) == 0 )
          goto LABEL_80;
        goto LABEL_62;
      }
      if ( v40 < 0 )
      {
        v41 = pOverrideTarget->m_Components.p[9].m_pComponent;
        if ( v41 && ((v23 ^ v41->m_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (v23 & ~v41->m_TypeUID & 0x1FFFFFF) != 0 )
            v41 = 0i64;
          goto LABEL_80;
        }
        goto LABEL_62;
      }
      if ( (v40 & 0x2000) != 0 )
      {
        v42 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pOverrideTarget);
      }
      else
      {
        if ( (v40 & 0x1000) != 0 )
        {
          v43 = pOverrideTarget->mComponentTableEntryCount;
          v44 = pOverrideTarget->m_Components.size;
          if ( v43 < v44 )
          {
            v45 = pOverrideTarget->m_Components.p;
            while ( (v45[v43].m_TypeUID & 0xFE000000) != (v23 & 0xFE000000)
                 || (v23 & ~v45[v43].m_TypeUID & 0x1FFFFFF) != 0 )
            {
              if ( ++v43 >= v44 )
                goto LABEL_62;
            }
            v41 = v45[v43].m_pComponent;
LABEL_80:
            if ( v41 )
              v46 = *(Creature **)&v41[2].m_TypeUID;
            else
              v46 = 0i64;
            if ( v41 )
            {
              if ( !v46 )
                return 0;
              if ( v46->mPose.mRigHandle.mData && targetAttachJoint->mUID != -1 )
                attachmentBoneID = Skeleton::GetBoneID(v46->mPose.mRigHandle.mUFGSkeleton, targetAttachJoint->mUID);
            }
            if ( !attachToTarget )
            {
              if ( managePowerLevel )
                *managePowerLevel = 0;
              if ( attachRelative )
              {
                if ( v46 )
                {
                  Creature::GetTransform(v46, attachmentBoneID, &relativePositionWS);
                  v30 = UFG::closestJointID(mCreature, 22, &relativePositionWS.v3, &vBoneOut);
                  if ( attachRelativeMaxDistance >= 0.0 )
                  {
                    v85 = vBoneOut.w - 1.0;
                    v86 = vBoneOut.z - relativePositionWS.v3.z;
                    y_low = LODWORD(vBoneOut.y);
                    *(float *)&y_low = vBoneOut.y - relativePositionWS.v3.y;
                    v88 = vBoneOut.x - relativePositionWS.v3.x;
                    v89 = (__m128)y_low;
                    v89.m128_f32[0] = (float)((float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v88 * v88))
                                            + (float)(v86 * v86))
                                    + (float)(v85 * v85);
                    v90 = 1.0 - (float)(attachRelativeMaxDistance / _mm_sqrt_ps(v89).m128_f32[0]);
                    m_pTransformNodeComponent = pOverrideTarget->m_pTransformNodeComponent;
                    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                    v92 = m_pTransformNodeComponent->mWorldTransform.v1;
                    v93 = m_pTransformNodeComponent->mWorldTransform.v2;
                    transform.v0 = m_pTransformNodeComponent->mWorldTransform.v0;
                    transform.v1 = v92;
                    transform.v2 = v93;
                    transform.v3 = m_pTransformNodeComponent->mWorldTransform.v3;
                    *(float *)&y_low = (float)(*(float *)&y_low * v90)
                                     + _mm_shuffle_ps((__m128)transform.v3, (__m128)transform.v3, 85).m128_f32[0];
                    v94 = (float)(v86 * v90)
                        + _mm_shuffle_ps((__m128)transform.v3, (__m128)transform.v3, 170).m128_f32[0];
                    v95 = (float)(v85 * v90) + m_pTransformNodeComponent->mWorldTransform.v3.w;
                    transform.v3.x = transform.v3.x + (float)(v88 * v90);
                    LODWORD(transform.v3.y) = y_low;
                    transform.v3.z = v94;
                    transform.v3.w = v95;
                    v96 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                    if ( v96 )
                      UFG::TeleportEvent::TeleportEvent(
                        (UFG::TeleportEvent *)v96,
                        &transform,
                        pOverrideTarget->mNode.mUID,
                        0,
                        UFG::TeleportEvent::m_Name,
                        0);
                    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v96);
                  }
                  v97 = attachmentBoneID;
                  v98 = v46;
                }
                else
                {
                  v97 = v30;
                  v98 = mCreature;
                }
                Creature::GetTransform(v98, v97, &relativePositionWS);
                v59 = Creature::AddAttachmentRelative(
                        mCreature,
                        v20,
                        v30,
                        (UFG::SimObjectCVBase *)pOverrideTarget,
                        attachmentBoneID,
                        &relativePositionWS,
                        blendInTime);
              }
              else
              {
                v59 = Creature::AddAttachment(
                        mCreature,
                        v20,
                        v30,
                        (UFG::SimObjectCVBase *)pOverrideTarget,
                        attachmentBoneID,
                        positionOnly,
                        blendInTime);
              }
              goto LABEL_206;
            }
            if ( !managePowerLevel || !*managePowerLevel )
            {
LABEL_121:
              if ( v46 )
              {
                if ( attachRelative )
                {
                  Creature::GetTransform(mCreature, boneID, &transform);
                  v58 = UFG::closestJointID(v46, 22, &transform.v3, &vBoneOut);
                  v59 = Creature::AddAttachmentRelative(
                          v46,
                          pOverrideTarget,
                          v58,
                          (UFG::SimObjectCVBase *)v20,
                          boneID,
                          &transform,
                          blendInTime);
                }
                else
                {
                  v59 = Creature::AddAttachment(
                          v46,
                          pOverrideTarget,
                          attachmentBoneID,
                          (UFG::SimObjectCVBase *)v20,
                          boneID,
                          positionOnly,
                          blendInTime);
                }
LABEL_206:
                v117 = v59 != 0i64;
                if ( v59 )
                  *((_BYTE *)v59 + 25) = positionXYOnly;
LABEL_208:
                if ( attachToTarget )
                {
                  v99 = (UFG::SimObjectCharacter *)pOverrideTarget;
                }
                else
                {
                  v99 = (UFG::SimObjectCharacter *)v20;
                  v20 = pOverrideTarget;
                }
                if ( !v99 )
                {
LABEL_241:
                  if ( v99 == LocalPlayer && assignmentTargetType == 17 )
                    UFG::GameStatAction::Inventory::Equip(v20);
                  if ( v112 )
                  {
                    if ( assignTarget )
                    {
                      UFG::TargetingSystemBaseComponent::AssignTarget(v112, assignmentTargetType, targetType);
                      v110 = assignmentTargetType;
                    }
                    else
                    {
                      v110 = targetType;
                    }
                    if ( lockTarget )
                      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, __int64))v112->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
                        v112,
                        v110,
                        1i64);
                  }
                  return v117;
                }
                v100 = v99->m_Flags;
                if ( (v100 & 0x4000) != 0 )
                {
                  v101 = (UFG::InventoryComponent *)v99->m_Components.p[39].m_pComponent;
LABEL_238:
                  if ( v101 && addToInventory )
                    UFG::InventoryComponent::AddObjectToInventory(v101, v20, 1);
                  goto LABEL_241;
                }
                if ( v100 >= 0 )
                {
                  if ( (v100 & 0x2000) != 0 )
                  {
                    v106 = v99->mComponentTableEntryCount;
                    v107 = v99->m_Components.size;
                    if ( v106 < v107 )
                    {
                      v104 = v99->m_Components.p;
                      do
                      {
                        v105 = v106;
                        if ( (v104[v106].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                          && (UFG::InventoryComponent::_TypeUID & ~v104[v106].m_TypeUID & 0x1FFFFFF) == 0 )
                        {
                          goto LABEL_221;
                        }
                      }
                      while ( ++v106 < v107 );
                    }
                  }
                  else
                  {
                    if ( (v100 & 0x1000) == 0 )
                    {
                      v101 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                          v99,
                                                          UFG::InventoryComponent::_TypeUID);
                      goto LABEL_238;
                    }
                    v108 = v99->mComponentTableEntryCount;
                    v109 = v99->m_Components.size;
                    if ( v108 < v109 )
                    {
                      v104 = v99->m_Components.p;
                      do
                      {
                        v105 = v108;
                        if ( (v104[v108].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                          && (UFG::InventoryComponent::_TypeUID & ~v104[v108].m_TypeUID & 0x1FFFFFF) == 0 )
                        {
                          goto LABEL_221;
                        }
                      }
                      while ( ++v108 < v109 );
                    }
                  }
                }
                else
                {
                  v102 = v99->mComponentTableEntryCount;
                  v103 = v99->m_Components.size;
                  if ( v102 < v103 )
                  {
                    v104 = v99->m_Components.p;
                    while ( 1 )
                    {
                      v105 = v102;
                      if ( (v104[v102].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                        && (UFG::InventoryComponent::_TypeUID & ~v104[v102].m_TypeUID & 0x1FFFFFF) == 0 )
                      {
                        break;
                      }
                      if ( ++v102 >= v103 )
                        goto LABEL_222;
                    }
LABEL_221:
                    v101 = (UFG::InventoryComponent *)v104[v105].m_pComponent;
                    goto LABEL_238;
                  }
                }
LABEL_222:
                v101 = 0i64;
                goto LABEL_238;
              }
              v60 = v20->m_Flags;
              if ( (v60 & 0x4000) != 0 )
              {
                v61 = (UFG::WorldContextComponent *)v20->m_Components.p[28].m_pComponent;
LABEL_148:
                v69 = pOverrideTarget->m_pTransformNodeComponent;
                *(_QWORD *)&vBoneOut.x = v69;
                if ( !v61 || !v69 )
                  goto LABEL_208;
                useRubberBand = 0;
                if ( !ppOutSimObjectTarget )
                  goto LABEL_193;
                v71 = *ppOutSimObjectTarget;
                if ( !*ppOutSimObjectTarget )
                  goto LABEL_193;
                v72 = v71->m_Flags;
                if ( (v72 & 0x4000) != 0 )
                {
                  v73 = (UFG::InterestPoint *)v71->m_Components.p[25].m_pComponent;
                }
                else if ( v72 >= 0 )
                {
                  if ( (v72 & 0x2000) != 0 )
                    v73 = (UFG::InterestPoint *)v71->m_Components.p[10].m_pComponent;
                  else
                    v73 = (UFG::InterestPoint *)((v72 & 0x1000) != 0
                                               ? v71->m_Components.p[3].m_pComponent
                                               : UFG::SimObject::GetComponentOfType(v71, UFG::InterestPoint::_TypeUID));
                }
                else
                {
                  v73 = (UFG::InterestPoint *)v71->m_Components.p[25].m_pComponent;
                }
                if ( !v73 )
                  goto LABEL_193;
                PositionSyncRequired = UFG::InterestPoint::GetPositionSyncRequired(v73);
                RotationSyncRequired = UFG::InterestPoint::GetRotationSyncRequired(v73);
                RequiresSync = UFG::InterestPoint::GetRequiresSync(v73);
                if ( (!PositionSyncRequired || !RotationSyncRequired) && !RequiresSync )
                  goto LABEL_193;
                v77 = v20->m_Flags;
                if ( (v77 & 0x4000) != 0 )
                {
                  v78 = v20->m_Components.p[3].m_pComponent;
                  if ( !v78
                    || ((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v78->m_TypeUID) & 0xFE000000) != 0
                    || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v78->m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    goto LABEL_169;
                  }
LABEL_191:
                  if ( v78 )
                    useRubberBand = LODWORD(v78[3].vfptr) == 4;
LABEL_193:
                  UFG::WorldContextComponent::AttachTo(
                    v61,
                    pOverrideTarget,
                    *(UFG::TransformNodeComponent **)&vBoneOut.x,
                    boneID,
                    blendInTime,
                    positionOnly,
                    positionXYOnly,
                    useRubberBand);
                  v117 = 1;
                  goto LABEL_208;
                }
                if ( v77 < 0 )
                {
                  v78 = v20->m_Components.p[3].m_pComponent;
                  if ( v78
                    && ((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v78->m_TypeUID) & 0xFE000000) == 0 )
                  {
                    if ( (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v78->m_TypeUID & 0x1FFFFFF) != 0 )
                      v78 = 0i64;
                    goto LABEL_191;
                  }
                  goto LABEL_169;
                }
                if ( (v77 & 0x2000) != 0 )
                {
                  v79 = v20->mComponentTableEntryCount;
                  v80 = v20->m_Components.size;
                  if ( v79 < v80 )
                  {
                    v81 = v20->m_Components.p;
                    while ( 1 )
                    {
                      v82 = v79;
                      if ( (v81[v79].m_TypeUID & 0xFE000000) == (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
                        && (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v81[v79].m_TypeUID & 0x1FFFFFF) == 0 )
                      {
                        break;
                      }
                      if ( ++v79 >= v80 )
                        goto LABEL_169;
                    }
LABEL_182:
                    v78 = v81[v82].m_pComponent;
                    goto LABEL_191;
                  }
                }
                else
                {
                  if ( (v77 & 0x1000) == 0 )
                  {
                    v78 = UFG::SimObject::GetComponentOfType(v20, UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                    goto LABEL_191;
                  }
                  v83 = v20->mComponentTableEntryCount;
                  v84 = v20->m_Components.size;
                  if ( v83 < v84 )
                  {
                    v81 = v20->m_Components.p;
                    do
                    {
                      v82 = v83;
                      if ( (v81[v83].m_TypeUID & 0xFE000000) == (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
                        && (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v81[v83].m_TypeUID & 0x1FFFFFF) == 0 )
                      {
                        goto LABEL_182;
                      }
                    }
                    while ( ++v83 < v84 );
                  }
                }
LABEL_169:
                v78 = 0i64;
                goto LABEL_191;
              }
              if ( v60 >= 0 )
              {
                if ( (v60 & 0x2000) != 0 )
                {
                  v65 = v20->mComponentTableEntryCount;
                  v66 = v20->m_Components.size;
                  if ( v65 < v66 )
                  {
                    do
                    {
                      v64 = (__int64)&v20->m_Components.p[v65];
                      if ( (*(_DWORD *)(v64 + 8) & 0xFE000000) == (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                        && (UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) == 0 )
                      {
                        goto LABEL_133;
                      }
                    }
                    while ( ++v65 < v66 );
                  }
                }
                else
                {
                  if ( (v60 & 0x1000) == 0 )
                  {
                    v61 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                          v20,
                                                          UFG::WorldContextComponent::_TypeUID);
                    goto LABEL_148;
                  }
                  v67 = v20->mComponentTableEntryCount;
                  v68 = v20->m_Components.size;
                  if ( v67 < v68 )
                  {
                    do
                    {
                      v64 = (__int64)&v20->m_Components.p[v67];
                      if ( (*(_DWORD *)(v64 + 8) & 0xFE000000) == (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                        && (UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) == 0 )
                      {
                        goto LABEL_133;
                      }
                    }
                    while ( ++v67 < v68 );
                  }
                }
              }
              else
              {
                v62 = v20->mComponentTableEntryCount;
                v63 = v20->m_Components.size;
                if ( v62 < v63 )
                {
                  while ( 1 )
                  {
                    v64 = (__int64)&v20->m_Components.p[v62];
                    if ( (*(_DWORD *)(v64 + 8) & 0xFE000000) == (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                      && (UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) == 0 )
                    {
                      break;
                    }
                    if ( ++v62 >= v63 )
                      goto LABEL_134;
                  }
LABEL_133:
                  v61 = *(UFG::WorldContextComponent **)v64;
                  goto LABEL_148;
                }
              }
LABEL_134:
              v61 = 0i64;
              goto LABEL_148;
            }
            v47 = pOverrideTarget->m_Flags;
            if ( (v47 & 0x4000) != 0 )
            {
              v48 = pOverrideTarget->mComponentTableEntryCount;
              v49 = pOverrideTarget->m_Components.size;
              if ( v48 < v49 )
              {
                while ( 1 )
                {
                  v50 = &pOverrideTarget->m_Components.p[v48];
                  if ( (v50->m_TypeUID & 0xFE000000) == (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                    && (UFG::PowerManagementComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    break;
                  }
                  if ( ++v48 >= v49 )
                    goto LABEL_98;
                }
LABEL_97:
                v51 = (UFG::PowerManagementComponent *)v50->m_pComponent;
                goto LABEL_118;
              }
            }
            else if ( v47 >= 0 )
            {
              if ( (v47 & 0x2000) != 0 )
              {
                v54 = pOverrideTarget->mComponentTableEntryCount;
                v55 = pOverrideTarget->m_Components.size;
                if ( v54 < v55 )
                {
                  do
                  {
                    v50 = &pOverrideTarget->m_Components.p[v54];
                    if ( (v50->m_TypeUID & 0xFE000000) == (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                      && (UFG::PowerManagementComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) == 0 )
                    {
                      goto LABEL_97;
                    }
                  }
                  while ( ++v54 < v55 );
                }
              }
              else
              {
                if ( (v47 & 0x1000) == 0 )
                {
                  v51 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                           pOverrideTarget,
                                                           UFG::PowerManagementComponent::_TypeUID);
LABEL_118:
                  if ( v51 )
                  {
                    UFG::PowerManagementComponent::AddPreventSuspendRefCount(v51);
                    *managePowerLevel = 1;
                  }
                  else
                  {
                    *managePowerLevel = 0;
                  }
                  goto LABEL_121;
                }
                v56 = pOverrideTarget->mComponentTableEntryCount;
                v57 = pOverrideTarget->m_Components.size;
                if ( v56 < v57 )
                {
                  do
                  {
                    v50 = &pOverrideTarget->m_Components.p[v56];
                    if ( (v50->m_TypeUID & 0xFE000000) == (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                      && (UFG::PowerManagementComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) == 0 )
                    {
                      goto LABEL_97;
                    }
                  }
                  while ( ++v56 < v57 );
                }
              }
            }
            else
            {
              v52 = pOverrideTarget->mComponentTableEntryCount;
              v53 = pOverrideTarget->m_Components.size;
              if ( v52 < v53 )
              {
                do
                {
                  v50 = &pOverrideTarget->m_Components.p[v52];
                  if ( (v50->m_TypeUID & 0xFE000000) == (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                    && (UFG::PowerManagementComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    goto LABEL_97;
                  }
                }
                while ( ++v52 < v53 );
              }
            }
LABEL_98:
            v51 = 0i64;
            goto LABEL_118;
          }
LABEL_62:
          v41 = 0i64;
          goto LABEL_80;
        }
        v42 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(pOverrideTarget, v23);
      }
      v41 = v42;
      goto LABEL_80;
    }
    if ( v31 < 0 )
    {
      v32 = (UFG::TargetingSystemBaseComponent *)v20->m_Components.p[20].m_pComponent;
      goto LABEL_54;
    }
    if ( (v31 & 0x2000) != 0 )
    {
      v33 = v20->mComponentTableEntryCount;
      v34 = v20->m_Components.size;
      if ( v33 < v34 )
      {
        v35 = v20->m_Components.p;
        while ( 1 )
        {
          v36 = v33;
          if ( (v35[v33].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::TargetingSystemBaseComponent::_TypeUID & ~v35[v33].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v33 >= v34 )
            goto LABEL_44;
        }
LABEL_43:
        v32 = (UFG::TargetingSystemBaseComponent *)v35[v36].m_pComponent;
LABEL_45:
        v17 = ppOutSimObjectTarget;
        goto LABEL_54;
      }
    }
    else
    {
      if ( (v31 & 0x1000) == 0 )
      {
        v32 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                     v20,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
        v23 = UFG::CharacterAnimationComponent::_TypeUID;
        goto LABEL_54;
      }
      v37 = v20->mComponentTableEntryCount;
      v38 = v20->m_Components.size;
      if ( v37 < v38 )
      {
        v35 = v20->m_Components.p;
        do
        {
          v36 = v37;
          if ( (v35[v37].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::TargetingSystemBaseComponent::_TypeUID & ~v35[v37].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_43;
          }
        }
        while ( ++v37 < v38 );
      }
    }
LABEL_44:
    v32 = 0i64;
    goto LABEL_45;
  }
  return v117;
}

// File Line: 425
// RVA: 0x5531F0
bool __fastcall UFG::TargetAttach(
        ActionContext *context,
        UFG::eTargetTypeEnum targetType,
        UFG::SimObject *pOverrideTarget,
        UFG::SimObject **ppOutSimObjectTarget,
        UFG::qSymbolUC *attachJoint,
        UFG::qSymbolUC *targetAttachJoint,
        float blendInTime,
        bool attachRelative,
        float attachRelativeMaxDistance,
        bool attachToTarget,
        bool addToInventory,
        bool assignTarget,
        UFG::eTargetTypeEnum assignmentTargetType,
        bool lockTarget,
        bool positionOnly,
        bool positionXYOnly,
        bool *managePowerLevel)
{
  return UFG::TargetAttach(
           context->mSimObject.m_pPointer,
           targetType,
           pOverrideTarget,
           ppOutSimObjectTarget,
           attachJoint,
           targetAttachJoint,
           blendInTime,
           attachRelative,
           attachRelativeMaxDistance,
           attachToTarget,
           addToInventory,
           assignTarget,
           assignmentTargetType,
           lockTarget,
           positionOnly,
           positionXYOnly,
           managePowerLevel);
}

// File Line: 472
// RVA: 0x554F50
__int64 __fastcall UFG::TargetDetach(
        UFG::SimObjectProp *simObject,
        unsigned int targetType,
        UFG::SimObjectProp *pOverrideTarget,
        UFG::qSymbolUC *attachJoint,
        UFG::qSymbolUC *targetAttachJoint,
        float blendOutTime,
        bool detachFromTarget,
        bool removeFromInventory,
        bool deleteOnDetach,
        bool releaseTarget,
        bool makeUpright,
        bool fadeAwayOnDetach,
        float disableCollisionDelay,
        float clampVelocity,
        bool managePowerLevel)
{
  unsigned __int8 v15; // bp
  UFG::SimObjectProp *v17; // rdi
  UFG::eTargetTypeEnum v18; // r14d
  signed __int16 m_Flags; // r10
  __int64 v21; // r9
  UFG::SimComponent *m_pComponent; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *v26; // rdx
  Creature *v27; // r12
  int v28; // esi
  int BoneID; // eax
  UFG::TargetingSystemBaseComponent *v30; // rax
  signed __int16 v31; // cx
  unsigned int v32; // r8d
  unsigned int v33; // r10d
  UFG::SimComponentHolder *v34; // rdx
  unsigned int v35; // r8d
  unsigned int v36; // r10d
  UFG::SimObject *Target; // rax
  UFG::TransformNodeComponent *i; // rax
  UFG::SimObject *m_pSimObject; // rcx
  __int16 v40; // cx
  int v41; // ebp
  UFG::CharacterAnimationComponent *v42; // rcx
  UFG::CharacterAnimationComponent *v43; // rax
  unsigned int v44; // r8d
  unsigned int v45; // r10d
  __int64 v46; // rdx
  Creature *mCreature; // rbx
  __int16 v48; // cx
  unsigned int v49; // r8d
  __int64 v50; // rdx
  UFG::PowerManagementComponent *v51; // rax
  unsigned int v52; // r8d
  unsigned int v53; // r8d
  unsigned int v54; // r8d
  UFG::SimObjectCharacter *v55; // r14
  UFG::SimObjectProp *v56; // r15
  __int64 m_pTransformNodeComponent; // r8
  UFG::WorldContextComponent *v58; // rax
  signed __int16 v59; // cx
  unsigned int v60; // r8d
  UFG::SimComponentHolder *v61; // rdx
  unsigned int v62; // r8d
  unsigned int v63; // r8d
  Creature *v64; // rcx
  signed __int16 v65; // cx
  UFG::InventoryComponent *v66; // rax
  UFG::SimComponentHolder *v67; // rdx
  UFG::GameStatTracker *v68; // rax
  unsigned int mUID; // ebx
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qResourceData *ArchetypeProperties; // rax
  __int16 v72; // cx
  __int64 v73; // rdx
  UFG::PropInteractComponent *v74; // rax
  __int64 v75; // rcx
  float v76; // xmm7_4
  float v77; // xmm6_4
  __int16 v78; // cx
  UFG::SimComponent *v79; // rax
  unsigned int v80; // r8d
  __int64 v81; // rdx
  __int16 v82; // cx
  unsigned int v83; // edx
  unsigned int v84; // r8d
  __int64 v85; // rbx
  UFG::RigidBody *v86; // rbx
  unsigned int v87; // edx
  unsigned int v88; // r8d
  unsigned int v89; // edx
  unsigned int v90; // r8d
  unsigned int v91; // edx
  unsigned int v92; // r8d
  __m128 x_low; // xmm2
  float v94; // xmm0_4
  __m128 v95; // xmm2
  UFG::qVector3 result; // [rsp+40h] [rbp-88h] BYREF
  UFG::qVector3 vel; // [rsp+50h] [rbp-78h] BYREF
  UFG::qVector3 v99; // [rsp+60h] [rbp-68h] BYREF
  UFG::TargetingSystemBaseComponent *v100; // [rsp+D0h] [rbp+8h]

  v15 = 0;
  v17 = pOverrideTarget;
  v18 = targetType;
  if ( !simObject )
  {
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    goto LABEL_23;
  }
  m_Flags = simObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    m_pComponent = simObject->m_Components.p[9].m_pComponent;
    if ( m_pComponent
      && ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) == 0
      && (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) == 0 )
    {
      goto LABEL_20;
    }
LABEL_6:
    m_pComponent = 0i64;
    goto LABEL_20;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(simObject);
LABEL_19:
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    m_pComponent = ComponentOfType;
    goto LABEL_20;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            simObject,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_19;
  }
  mComponentTableEntryCount = simObject->mComponentTableEntryCount;
  size = simObject->m_Components.size;
  v21 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( mComponentTableEntryCount >= size )
    goto LABEL_6;
  v26 = &simObject->m_Components.p[mComponentTableEntryCount];
  while ( (v26->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~v26->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    ++v26;
    if ( mComponentTableEntryCount >= size )
    {
      m_pComponent = 0i64;
      goto LABEL_20;
    }
  }
  m_pComponent = v26->m_pComponent;
LABEL_20:
  if ( m_pComponent )
  {
    v27 = *(Creature **)&m_pComponent[2].m_TypeUID;
    goto LABEL_24;
  }
LABEL_23:
  v27 = 0i64;
LABEL_24:
  if ( !v27 )
    return v15;
  v28 = 0;
  if ( attachJoint->mUID != -1 )
  {
    if ( v27->mPose.mRigHandle.mData )
    {
      BoneID = Skeleton::GetBoneID(v27->mPose.mRigHandle.mUFGSkeleton, attachJoint->mUID);
      v21 = UFG::CharacterAnimationComponent::_TypeUID;
      v28 = BoneID;
    }
    else
    {
      v28 = -1;
    }
  }
  if ( !simObject )
    goto LABEL_30;
  v31 = simObject->m_Flags;
  if ( (v31 & 0x4000) != 0 )
  {
    v30 = (UFG::TargetingSystemBaseComponent *)simObject->m_Components.p[20].m_pComponent;
    goto LABEL_51;
  }
  if ( v31 < 0 )
  {
    v30 = (UFG::TargetingSystemBaseComponent *)simObject->m_Components.p[20].m_pComponent;
    goto LABEL_51;
  }
  if ( (v31 & 0x2000) == 0 )
  {
    if ( (v31 & 0x1000) == 0 )
    {
      v30 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                   simObject,
                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
      v21 = UFG::CharacterAnimationComponent::_TypeUID;
      goto LABEL_51;
    }
    v35 = simObject->mComponentTableEntryCount;
    v36 = simObject->m_Components.size;
    if ( v35 >= v36 )
      goto LABEL_30;
    v34 = &simObject->m_Components.p[v35];
    while ( (v34->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
         || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v34->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      ++v35;
      ++v34;
      if ( v35 >= v36 )
      {
        v30 = 0i64;
        goto LABEL_51;
      }
    }
LABEL_42:
    v30 = (UFG::TargetingSystemBaseComponent *)v34->m_pComponent;
    goto LABEL_51;
  }
  v32 = simObject->mComponentTableEntryCount;
  v33 = simObject->m_Components.size;
  if ( v32 < v33 )
  {
    v34 = &simObject->m_Components.p[v32];
    while ( (v34->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
         || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v34->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      ++v32;
      ++v34;
      if ( v32 >= v33 )
      {
        v30 = 0i64;
        goto LABEL_51;
      }
    }
    goto LABEL_42;
  }
LABEL_30:
  v30 = 0i64;
LABEL_51:
  v100 = v30;
  if ( v17
    || (Target = UFG::getTarget(simObject, v30, v18),
        v21 = UFG::CharacterAnimationComponent::_TypeUID,
        (v17 = (UFG::SimObjectProp *)Target) != 0i64) )
  {
    if ( fadeAwayOnDetach )
    {
      for ( i = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                                 v17,
                                                 UFG::RigidBodyComponent::_TypeUID);
            i;
            i = UFG::SimObject::GetComponentOfType(
                  m_pSimObject,
                  UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                  0,
                  i) )
      {
        m_pSimObject = i->m_pSimObject;
        i[1].mWorldTransform.v3.z = 6.0;
      }
      v21 = UFG::CharacterAnimationComponent::_TypeUID;
    }
    v40 = v17->m_Flags;
    v41 = 0;
    if ( (v40 & 0x4000) != 0 )
    {
      v42 = (UFG::CharacterAnimationComponent *)v17->m_Components.p[9].m_pComponent;
      if ( v42
        && (((unsigned int)v21 ^ v42->m_TypeUID) & 0xFE000000) == 0
        && ((unsigned int)v21 & ~v42->m_TypeUID & 0x1FFFFFF) == 0 )
      {
        goto LABEL_79;
      }
      goto LABEL_61;
    }
    if ( v40 < 0 )
    {
      v42 = (UFG::CharacterAnimationComponent *)v17->m_Components.p[9].m_pComponent;
      if ( v42 && (((unsigned int)v21 ^ v42->m_TypeUID) & 0xFE000000) == 0 )
      {
        if ( ((unsigned int)v21 & ~v42->m_TypeUID & 0x1FFFFFF) != 0 )
          v42 = 0i64;
        goto LABEL_79;
      }
      goto LABEL_61;
    }
    if ( (v40 & 0x2000) != 0 )
    {
      v43 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v17);
    }
    else
    {
      if ( (v40 & 0x1000) != 0 )
      {
        v44 = v17->mComponentTableEntryCount;
        v45 = v17->m_Components.size;
        if ( v44 < v45 )
        {
          v46 = (__int64)&v17->m_Components.p[v44];
          while ( (*(_DWORD *)(v46 + 8) & 0xFE000000) != (v21 & 0xFE000000)
               || ((unsigned int)v21 & ~*(_DWORD *)(v46 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v44;
            v46 += 16i64;
            if ( v44 >= v45 )
            {
              v42 = 0i64;
              goto LABEL_79;
            }
          }
          v42 = *(UFG::CharacterAnimationComponent **)v46;
LABEL_79:
          if ( v42 )
            mCreature = v42->mCreature;
          else
            mCreature = 0i64;
          if ( mCreature && targetAttachJoint->mUID != -1 )
          {
            if ( mCreature->mPose.mRigHandle.mData )
              v41 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, targetAttachJoint->mUID);
            else
              v41 = -1;
          }
          if ( !detachFromTarget )
          {
            v55 = (UFG::SimObjectCharacter *)simObject;
            v56 = v17;
            v15 = Creature::RemoveAttachment(v27, simObject, v28, v17);
            if ( mCreature && makeUpright )
            {
              v64 = mCreature;
              goto LABEL_159;
            }
LABEL_160:
            if ( !removeFromInventory || !simObject )
              goto LABEL_189;
            v65 = simObject->m_Flags;
            if ( (v65 & 0x4000) != 0 )
            {
              v66 = (UFG::InventoryComponent *)simObject->m_Components.p[39].m_pComponent;
              goto LABEL_187;
            }
            if ( v65 >= 0 )
            {
              if ( (v65 & 0x2000) != 0 )
              {
                m_pTransformNodeComponent = simObject->mComponentTableEntryCount;
                v21 = simObject->m_Components.size;
                if ( (unsigned int)m_pTransformNodeComponent < (unsigned int)v21 )
                {
                  v67 = &simObject->m_Components.p[(unsigned int)m_pTransformNodeComponent];
                  while ( (v67->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                       || (UFG::InventoryComponent::_TypeUID & ~v67->m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    m_pTransformNodeComponent = (unsigned int)(m_pTransformNodeComponent + 1);
                    ++v67;
                    if ( (unsigned int)m_pTransformNodeComponent >= (unsigned int)v21 )
                    {
                      v66 = 0i64;
                      goto LABEL_187;
                    }
                  }
                  goto LABEL_171;
                }
              }
              else
              {
                if ( (v65 & 0x1000) == 0 )
                {
                  v66 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                     simObject,
                                                     UFG::InventoryComponent::_TypeUID);
LABEL_187:
                  if ( v66 )
                    UFG::InventoryComponent::RemoveObjectFromInventory(v66, v17);
LABEL_189:
                  if ( v55 == LocalPlayer )
                  {
                    v68 = UFG::GameStatTracker::Instance();
                    mUID = UFG::GameStatTracker::GetStat(v68, Equipped)->mValue.mUID;
                    if ( mUID != -1 )
                    {
                      m_pSceneObj = v56->m_pSceneObj;
                      if ( m_pSceneObj )
                      {
                        ArchetypeProperties = UFG::SceneObjectProperties::GetArchetypeProperties(m_pSceneObj);
                        if ( ArchetypeProperties )
                        {
                          if ( mUID == *(_DWORD *)&ArchetypeProperties->mDebugName[12] )
                            UFG::GameStatAction::Inventory::UnEquip(0);
                        }
                      }
                    }
                  }
                  v72 = v17->m_Flags;
                  if ( (v72 & 0x4000) != 0 )
                  {
                    m_pTransformNodeComponent = v17->mComponentTableEntryCount;
                    v21 = v17->m_Components.size;
                    if ( (unsigned int)m_pTransformNodeComponent < (unsigned int)v21 )
                    {
                      v73 = (__int64)&v17->m_Components.p[(unsigned int)m_pTransformNodeComponent];
                      while ( (*(_DWORD *)(v73 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                           || (UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v73 + 8) & 0x1FFFFFF) != 0 )
                      {
                        m_pTransformNodeComponent = (unsigned int)(m_pTransformNodeComponent + 1);
                        v73 += 16i64;
                        if ( (unsigned int)m_pTransformNodeComponent >= (unsigned int)v21 )
                          goto LABEL_201;
                      }
LABEL_202:
                      v74 = *(UFG::PropInteractComponent **)v73;
                      goto LABEL_215;
                    }
                    goto LABEL_201;
                  }
                  if ( v72 >= 0 )
                  {
                    if ( (v72 & 0x2000) != 0 )
                    {
                      v74 = (UFG::PropInteractComponent *)v17->m_Components.p[13].m_pComponent;
                    }
                    else
                    {
                      if ( (v72 & 0x1000) != 0 )
                      {
                        m_pTransformNodeComponent = v17->mComponentTableEntryCount;
                        v21 = v17->m_Components.size;
                        if ( (unsigned int)m_pTransformNodeComponent < (unsigned int)v21 )
                        {
                          v73 = (__int64)&v17->m_Components.p[(unsigned int)m_pTransformNodeComponent];
                          while ( (*(_DWORD *)(v73 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                               || (UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v73 + 8) & 0x1FFFFFF) != 0 )
                          {
                            m_pTransformNodeComponent = (unsigned int)(m_pTransformNodeComponent + 1);
                            v73 += 16i64;
                            if ( (unsigned int)m_pTransformNodeComponent >= (unsigned int)v21 )
                            {
                              v74 = 0i64;
                              goto LABEL_215;
                            }
                          }
                          goto LABEL_202;
                        }
LABEL_201:
                        v74 = 0i64;
                        goto LABEL_215;
                      }
                      v74 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                            v17,
                                                            UFG::PropInteractComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v74 = (UFG::PropInteractComponent *)v17->m_Components.p[33].m_pComponent;
                  }
LABEL_215:
                  if ( v74 )
                    UFG::PropInteractComponent::DetachFromObject(v74, simObject, m_pTransformNodeComponent, v21);
                  if ( deleteOnDetach )
                  {
                    if ( pOverrideTarget )
                    {
                      v18 = targetType;
                    }
                    else
                    {
                      v18 = targetType;
                      if ( targetType > 0x37 || (v75 = 0x800C00001E0000i64, !_bittest64(&v75, (int)targetType)) )
                      {
                        v15 = 0;
                        goto LABEL_279;
                      }
                    }
                    UFG::SimObject::Destroy(v17);
                    goto LABEL_279;
                  }
                  v76 = clampVelocity;
                  v77 = 0.0;
                  if ( clampVelocity < 0.0 )
                    v76 = FLOAT_2_0;
                  v78 = v17->m_Flags;
                  if ( (v78 & 0x4000) == 0 )
                  {
                    if ( v78 >= 0 )
                    {
                      if ( (v78 & 0x2000) != 0 )
                        goto LABEL_240;
                      if ( (v78 & 0x1000) != 0 )
                      {
                        v80 = v17->mComponentTableEntryCount;
                        v21 = v17->m_Components.size;
                        if ( v80 >= (unsigned int)v21 )
                        {
LABEL_236:
                          v79 = 0i64;
                        }
                        else
                        {
                          v81 = (__int64)&v17->m_Components.p[v80];
                          while ( (*(_DWORD *)(v81 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                               || (UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v81 + 8) & 0x1FFFFFF) != 0 )
                          {
                            ++v80;
                            v81 += 16i64;
                            if ( v80 >= (unsigned int)v21 )
                              goto LABEL_236;
                          }
                          v79 = *(UFG::SimComponent **)v81;
                        }
                      }
                      else
                      {
                        v79 = UFG::SimObject::GetComponentOfType(v17, UFG::PhysicsMoverInterface::_TypeUID);
                      }
                    }
                    else
                    {
                      v79 = v17->m_Components.p[34].m_pComponent;
                    }
                    if ( v79 )
                    {
LABEL_278:
                      v18 = targetType;
                      goto LABEL_279;
                    }
                  }
LABEL_240:
                  v82 = v17->m_Flags;
                  if ( (v82 & 0x4000) != 0 )
                  {
                    v83 = v17->mComponentTableEntryCount;
                    v84 = v17->m_Components.size;
                    if ( v83 < v84 )
                    {
                      v21 = UFG::RigidBodyComponent::_TypeUID & 0xFE000000;
                      v85 = (__int64)&v17->m_Components.p[v83];
                      while ( (*(_DWORD *)(v85 + 8) & 0xFE000000) != (_DWORD)v21
                           || (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v85 + 8) & 0x1FFFFFF) != 0 )
                      {
                        ++v83;
                        v85 += 16i64;
                        if ( v83 >= v84 )
                          goto LABEL_246;
                      }
LABEL_247:
                      v86 = *(UFG::RigidBody **)v85;
                      goto LABEL_270;
                    }
                  }
                  else if ( v82 >= 0 )
                  {
                    if ( (v82 & 0x2000) != 0 )
                    {
                      v89 = v17->mComponentTableEntryCount;
                      v90 = v17->m_Components.size;
                      if ( v89 < v90 )
                      {
                        v21 = UFG::RigidBodyComponent::_TypeUID & 0xFE000000;
                        v85 = (__int64)&v17->m_Components.p[v89];
                        while ( (*(_DWORD *)(v85 + 8) & 0xFE000000) != (_DWORD)v21
                             || (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v85 + 8) & 0x1FFFFFF) != 0 )
                        {
                          ++v89;
                          v85 += 16i64;
                          if ( v89 >= v90 )
                          {
                            v86 = 0i64;
                            goto LABEL_270;
                          }
                        }
                        goto LABEL_247;
                      }
                    }
                    else
                    {
                      if ( (v82 & 0x1000) == 0 )
                      {
                        v86 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                  v17,
                                                  UFG::RigidBodyComponent::_TypeUID);
LABEL_270:
                        if ( v86 )
                        {
                          UFG::RigidBody::GetVelocity(v86, &result);
                          x_low = (__m128)LODWORD(result.x);
                          x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                                    + (float)(result.y * result.y))
                                            + (float)(result.z * result.z);
                          v94 = _mm_sqrt_ps(x_low).m128_f32[0];
                          if ( v94 > 0.1 && v94 > v76 )
                          {
                            if ( x_low.m128_f32[0] != 0.0 )
                              v77 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
                            vel.x = (float)(result.x * v77) * v76;
                            vel.y = (float)(result.y * v77) * v76;
                            vel.z = (float)(result.z * v77) * v76;
                            UFG::RigidBody::SetVelocity(v86, &vel);
                          }
                          UFG::RigidBody::GetAngularVelocity(v86, &v99);
                          v95 = (__m128)LODWORD(v99.x);
                          v95.m128_f32[0] = (float)((float)(v95.m128_f32[0] * v95.m128_f32[0]) + (float)(v99.y * v99.y))
                                          + (float)(v99.z * v99.z);
                          if ( _mm_sqrt_ps(v95).m128_f32[0] > 37.699112 )
                          {
                            vel.x = v99.x * 0.2;
                            vel.y = v99.y * 0.2;
                            vel.z = v99.z * 0.2;
                            UFG::RigidBody::SetAngularVelocity(v86, &vel);
                          }
                        }
                        goto LABEL_278;
                      }
                      v91 = v17->mComponentTableEntryCount;
                      v92 = v17->m_Components.size;
                      if ( v91 < v92 )
                      {
                        v21 = UFG::RigidBodyComponent::_TypeUID & 0xFE000000;
                        v85 = (__int64)&v17->m_Components.p[v91];
                        while ( (*(_DWORD *)(v85 + 8) & 0xFE000000) != (_DWORD)v21
                             || (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v85 + 8) & 0x1FFFFFF) != 0 )
                        {
                          ++v91;
                          v85 += 16i64;
                          if ( v91 >= v92 )
                          {
                            v86 = 0i64;
                            goto LABEL_270;
                          }
                        }
                        goto LABEL_247;
                      }
                    }
                  }
                  else
                  {
                    v87 = v17->mComponentTableEntryCount;
                    v88 = v17->m_Components.size;
                    if ( v87 < v88 )
                    {
                      v21 = UFG::RigidBodyComponent::_TypeUID & 0xFE000000;
                      v85 = (__int64)&v17->m_Components.p[v87];
                      while ( (*(_DWORD *)(v85 + 8) & 0xFE000000) != (_DWORD)v21
                           || (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v85 + 8) & 0x1FFFFFF) != 0 )
                      {
                        ++v87;
                        v85 += 16i64;
                        if ( v87 >= v88 )
                        {
                          v86 = 0i64;
                          goto LABEL_270;
                        }
                      }
                      goto LABEL_247;
                    }
                  }
LABEL_246:
                  v86 = 0i64;
                  goto LABEL_270;
                }
                m_pTransformNodeComponent = simObject->mComponentTableEntryCount;
                v21 = simObject->m_Components.size;
                if ( (unsigned int)m_pTransformNodeComponent < (unsigned int)v21 )
                {
                  v67 = &simObject->m_Components.p[(unsigned int)m_pTransformNodeComponent];
                  while ( (v67->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                       || (UFG::InventoryComponent::_TypeUID & ~v67->m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    m_pTransformNodeComponent = (unsigned int)(m_pTransformNodeComponent + 1);
                    ++v67;
                    if ( (unsigned int)m_pTransformNodeComponent >= (unsigned int)v21 )
                    {
                      v66 = 0i64;
                      goto LABEL_187;
                    }
                  }
                  goto LABEL_171;
                }
              }
            }
            else
            {
              m_pTransformNodeComponent = simObject->mComponentTableEntryCount;
              v21 = simObject->m_Components.size;
              if ( (unsigned int)m_pTransformNodeComponent < (unsigned int)v21 )
              {
                v67 = &simObject->m_Components.p[(unsigned int)m_pTransformNodeComponent];
                while ( (v67->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                     || (UFG::InventoryComponent::_TypeUID & ~v67->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  m_pTransformNodeComponent = (unsigned int)(m_pTransformNodeComponent + 1);
                  ++v67;
                  if ( (unsigned int)m_pTransformNodeComponent >= (unsigned int)v21 )
                    goto LABEL_170;
                }
LABEL_171:
                v66 = (UFG::InventoryComponent *)v67->m_pComponent;
                goto LABEL_187;
              }
            }
LABEL_170:
            v66 = 0i64;
            goto LABEL_187;
          }
          if ( !managePowerLevel )
          {
LABEL_121:
            v55 = (UFG::SimObjectCharacter *)v17;
            v56 = simObject;
            if ( mCreature )
            {
              v15 = Creature::RemoveAttachment(mCreature, v17, v41, simObject);
              goto LABEL_154;
            }
            if ( !simObject )
              goto LABEL_124;
            v59 = simObject->m_Flags;
            if ( (v59 & 0x4000) != 0 )
            {
              v58 = (UFG::WorldContextComponent *)simObject->m_Components.p[28].m_pComponent;
              goto LABEL_150;
            }
            if ( v59 >= 0 )
            {
              if ( (v59 & 0x2000) != 0 )
              {
                v62 = simObject->mComponentTableEntryCount;
                v21 = simObject->m_Components.size;
                if ( v62 < (unsigned int)v21 )
                {
                  v61 = &simObject->m_Components.p[v62];
                  while ( (v61->m_TypeUID & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                       || (UFG::WorldContextComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    ++v62;
                    ++v61;
                    if ( v62 >= (unsigned int)v21 )
                    {
                      v58 = 0i64;
                      goto LABEL_150;
                    }
                  }
                  goto LABEL_134;
                }
              }
              else
              {
                if ( (v59 & 0x1000) == 0 )
                {
                  v58 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                        simObject,
                                                        UFG::WorldContextComponent::_TypeUID);
LABEL_150:
                  m_pTransformNodeComponent = (__int64)v17->m_pTransformNodeComponent;
                  if ( v58 && m_pTransformNodeComponent )
                    UFG::WorldContextComponent::DetachFrom(
                      v58,
                      v17,
                      (UFG::TransformNodeComponent *)m_pTransformNodeComponent);
                  v15 = 1;
LABEL_154:
                  if ( makeUpright )
                  {
                    v64 = v27;
LABEL_159:
                    Creature::MakeUpright(v64, blendOutTime);
                    goto LABEL_160;
                  }
                  goto LABEL_160;
                }
                v63 = simObject->mComponentTableEntryCount;
                v21 = simObject->m_Components.size;
                if ( v63 < (unsigned int)v21 )
                {
                  v61 = &simObject->m_Components.p[v63];
                  while ( (v61->m_TypeUID & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                       || (UFG::WorldContextComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    ++v63;
                    ++v61;
                    if ( v63 >= (unsigned int)v21 )
                    {
                      v58 = 0i64;
                      goto LABEL_150;
                    }
                  }
                  goto LABEL_134;
                }
              }
            }
            else
            {
              v60 = simObject->mComponentTableEntryCount;
              v21 = simObject->m_Components.size;
              if ( v60 < (unsigned int)v21 )
              {
                v61 = &simObject->m_Components.p[v60];
                while ( (v61->m_TypeUID & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                     || (UFG::WorldContextComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  ++v60;
                  ++v61;
                  if ( v60 >= (unsigned int)v21 )
                  {
                    v58 = 0i64;
                    goto LABEL_150;
                  }
                }
LABEL_134:
                v58 = (UFG::WorldContextComponent *)v61->m_pComponent;
                goto LABEL_150;
              }
            }
LABEL_124:
            v58 = 0i64;
            goto LABEL_150;
          }
          v48 = v17->m_Flags;
          if ( (v48 & 0x4000) != 0 )
          {
            v49 = v17->mComponentTableEntryCount;
            v21 = v17->m_Components.size;
            if ( v49 < (unsigned int)v21 )
            {
              v50 = (__int64)&v17->m_Components.p[v49];
              while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                   || (UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v49;
                v50 += 16i64;
                if ( v49 >= (unsigned int)v21 )
                  goto LABEL_95;
              }
LABEL_96:
              v51 = *(UFG::PowerManagementComponent **)v50;
              goto LABEL_119;
            }
          }
          else if ( v48 >= 0 )
          {
            if ( (v48 & 0x2000) != 0 )
            {
              v53 = v17->mComponentTableEntryCount;
              v21 = v17->m_Components.size;
              if ( v53 < (unsigned int)v21 )
              {
                v50 = (__int64)&v17->m_Components.p[v53];
                while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                     || (UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v53;
                  v50 += 16i64;
                  if ( v53 >= (unsigned int)v21 )
                  {
                    v51 = 0i64;
                    goto LABEL_119;
                  }
                }
                goto LABEL_96;
              }
            }
            else
            {
              if ( (v48 & 0x1000) == 0 )
              {
                v51 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                         v17,
                                                         UFG::PowerManagementComponent::_TypeUID);
LABEL_119:
                if ( v51 )
                  UFG::PowerManagementComponent::RemovePreventSuspendRefCount(v51);
                goto LABEL_121;
              }
              v54 = v17->mComponentTableEntryCount;
              v21 = v17->m_Components.size;
              if ( v54 < (unsigned int)v21 )
              {
                v50 = (__int64)&v17->m_Components.p[v54];
                while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                     || (UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v54;
                  v50 += 16i64;
                  if ( v54 >= (unsigned int)v21 )
                  {
                    v51 = 0i64;
                    goto LABEL_119;
                  }
                }
                goto LABEL_96;
              }
            }
          }
          else
          {
            v52 = v17->mComponentTableEntryCount;
            v21 = v17->m_Components.size;
            if ( v52 < (unsigned int)v21 )
            {
              v50 = (__int64)&v17->m_Components.p[v52];
              while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                   || (UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v52;
                v50 += 16i64;
                if ( v52 >= (unsigned int)v21 )
                {
                  v51 = 0i64;
                  goto LABEL_119;
                }
              }
              goto LABEL_96;
            }
          }
LABEL_95:
          v51 = 0i64;
          goto LABEL_119;
        }
LABEL_61:
        v42 = 0i64;
        goto LABEL_79;
      }
      v43 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(v17, v21);
    }
    v42 = v43;
    goto LABEL_79;
  }
LABEL_279:
  if ( releaseTarget && v100 )
  {
    LOBYTE(v21) = 1;
    ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))v100->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
      v100,
      (unsigned int)v18,
      0i64,
      v21,
      LODWORD(disableCollisionDelay),
      "TargetDetach",
      0i64,
      0i64);
    UFG::TargetingSystemBaseComponent::ClearTarget(v100, v18);
  }
  return v15;
} v51 = 0i64;
                  goto LABEL_119;
                }
              }
              goto LABEL_96;
            }
          }
LABEL_95:
          v51 = 0i64;
          goto LABEL_119;
        }
LABEL_61:
        v42 = 0i64;
        goto LABEL_79;
      }
      v43 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(v17, v21);
    }
    v42 = v43;
    goto LABEL_79;
  }
LABEL_279:
  if ( releaseTarget && v100 )
  {
    LOBYTE(v21) = 1;
    ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))v100->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
      v100,
      (unsigned int)v18,
      0i64,
      v21,
      LODWORD(disableCollisionDelay),
      "TargetDetach",
      0i64,
      0i64);
    UFG::TargetingSystemBaseComponent::ClearTarget(v100, v18);
  }
  re

// File Line: 732
// RVA: 0x554D20
__int64 __fastcall UFG::TargetDetach(
        ActionContext *context,
        UFG::eTargetTypeEnum targetType,
        UFG::SimObject *pOverrideTarget,
        UFG::qSymbolUC *attachJoint,
        UFG::qSymbolUC *targetAttachJoint,
        float blendOutTime,
        bool detachFromTarget,
        bool removeFromInventory,
        bool deleteOnDetach,
        bool releaseTarget,
        bool makeUpright,
        bool fadeAwayOnDetach,
        float disableCollisionDelay,
        float clampVelocity,
        bool managePowerLevel)
{
  unsigned __int8 v16; // al
  UFG::SimObject *m_pPointer; // r9
  unsigned __int8 v18; // di
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedBaseComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v24; // rdx
  unsigned int v25; // r8d
  unsigned int v26; // r10d

  v16 = UFG::TargetDetach(
          context->mSimObject.m_pPointer,
          targetType,
          pOverrideTarget,
          attachJoint,
          targetAttachJoint,
          blendOutTime,
          detachFromTarget,
          removeFromInventory,
          deleteOnDetach,
          releaseTarget,
          makeUpright,
          fadeAwayOnDetach,
          disableCollisionDelay,
          clampVelocity,
          managePowerLevel);
  m_pPointer = context->mSimObject.m_pPointer;
  v18 = v16;
  if ( !m_pPointer )
    return v18;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = (UFG::TargetingSystemPedBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      goto LABEL_4;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pPointer[1].vfptr;
      size = m_pPointer->m_Components.size;
      if ( vfptr < size )
      {
        v24 = (__int64)&m_pPointer->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v24 += 16i64;
          if ( vfptr >= size )
          {
            m_pComponent = 0i64;
            goto LABEL_26;
          }
        }
LABEL_17:
        m_pComponent = *(UFG::TargetingSystemPedBaseComponent **)v24;
        goto LABEL_26;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                 context->mSimObject.m_pPointer,
                                                                 UFG::TargetingSystemPedBaseComponent::_TypeUID);
        goto LABEL_26;
      }
      v25 = (unsigned int)m_pPointer[1].vfptr;
      v26 = m_pPointer->m_Components.size;
      if ( v25 < v26 )
      {
        v24 = (__int64)&m_pPointer->m_Components.p[v25];
        while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v25;
          v24 += 16i64;
          if ( v25 >= v26 )
          {
            m_pComponent = 0i64;
            goto LABEL_26;
          }
        }
        goto LABEL_17;
      }
    }
LABEL_7:
    m_pComponent = 0i64;
    goto LABEL_26;
  }
  m_pComponent = (UFG::TargetingSystemPedBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
LABEL_4:
  if ( !m_pComponent )
    goto LABEL_7;
  m_TypeUID = m_pComponent->m_TypeUID;
  if ( ((m_TypeUID ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000) != 0
    || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
  {
    goto LABEL_7;
  }
LABEL_26:
  if ( m_pComponent )
    UFG::TargetingSystemPedBaseComponent::UpdateCommon(m_pComponent);
  return v18;
}  }
LABEL_26:
  if ( m_pComponent )
    UFG::TargetingSystemPedBaseComponent::UpdateCommon(m_pComponent);
 

// File Line: 771
// RVA: 0x5564E0
void __fastcall UFG::TargetDetachEffector(
        UFG::SimObject *simObject,
        UFG::CharacterAnimationComponent *animationComponent,
        unsigned int targetType,
        UFG::qSymbolUC *attachEffectorUID,
        float blendTime)
{
  signed __int16 m_Flags; // r10
  Creature *mCreature; // rdi
  __int64 v8; // rsi
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v14; // rdx
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  UFG::SimObject *v17; // rsi
  __int64 v18; // rcx
  int v19; // eax

  if ( !simObject )
    return;
  m_Flags = simObject->m_Flags;
  mCreature = 0i64;
  v8 = targetType;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = simObject->m_Components.p[20].m_pComponent;
      goto LABEL_22;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)simObject[1].vfptr;
      size = simObject->m_Components.size;
      if ( vfptr < size )
      {
        v14 = &simObject->m_Components.p[vfptr];
        while ( (v14->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v14;
          if ( vfptr >= size )
            goto LABEL_12;
        }
LABEL_13:
        m_pComponent = v14->m_pComponent;
        goto LABEL_22;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(simObject, UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_22;
      }
      v15 = (unsigned int)simObject[1].vfptr;
      v16 = simObject->m_Components.size;
      if ( v15 < v16 )
      {
        v14 = &simObject->m_Components.p[v15];
        while ( (v14->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v15;
          ++v14;
          if ( v15 >= v16 )
          {
            m_pComponent = 0i64;
            goto LABEL_22;
          }
        }
        goto LABEL_13;
      }
    }
LABEL_12:
    m_pComponent = 0i64;
    goto LABEL_22;
  }
  m_pComponent = simObject->m_Components.p[20].m_pComponent;
LABEL_22:
  if ( m_pComponent )
  {
    v17 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + v8 + 8)
                             + *(_QWORD *)&m_pComponent[1].m_TypeUID
                             + 40);
    if ( animationComponent )
      mCreature = animationComponent->mCreature;
    if ( mCreature )
    {
      v18 = (__int64)&mCreature->mPoseDrivers.mNode.mNext[-1];
      if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v18 != &mCreature->m_SafePointerList )
      {
        while ( *(_DWORD *)(v18 + 44) != attachEffectorUID->mUID )
        {
          v18 = *(_QWORD *)(v18 + 24) - 16i64;
          if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v18 == &mCreature->m_SafePointerList )
            return;
        }
        v19 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v18 + 112i64))(v18);
        Creature::RemoveAttachment(mCreature, simObject, v19, v17);
      }
    }
  }
}

// File Line: 808
// RVA: 0x5548C0
void __fastcall UFG::TargetAttachEffector(
        UFG::SimObject *simObject,
        UFG::CharacterAnimationComponent *animationComponent,
        unsigned int targetType,
        UFG::qSymbolUC *attachEffectorUID,
        UFG::qSymbolUC *baseJointUID,
        UFG::qSymbolUC *adjustJointUID,
        float blendTime,
        bool onlyEnablePostPhysics)
{
  __int64 v9; // rdi
  signed __int16 m_Flags; // r10
  __int64 v13; // rsi
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v18; // rdx
  unsigned int v19; // r8d
  unsigned int v20; // r9d
  UFG::SimObjectProp *v21; // r14
  __int16 v22; // cx
  UFG::CharacterAnimationComponent *v23; // rdi
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int v26; // r9d
  UFG::SimComponentHolder *v27; // rbx
  Creature *mCreature; // rbp
  Creature *v29; // r15
  __int64 v30; // rbx
  UFG::allocator::free_link *v31; // rax
  __int64 v32; // rax
  int v33; // edi
  int BoneID; // eax

  if ( !simObject )
    return;
  v9 = targetType;
  m_Flags = simObject->m_Flags;
  v13 = 0i64;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = simObject->m_Components.p[20].m_pComponent;
      goto LABEL_23;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)simObject[1].vfptr;
      size = simObject->m_Components.size;
      if ( vfptr < size )
      {
        p = simObject->m_Components.p;
        while ( 1 )
        {
          v18 = vfptr;
          if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::TargetingSystemBaseComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++vfptr >= size )
            goto LABEL_14;
        }
LABEL_13:
        m_pComponent = p[v18].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(simObject, UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_23;
      }
      v19 = (unsigned int)simObject[1].vfptr;
      v20 = simObject->m_Components.size;
      if ( v19 < v20 )
      {
        p = simObject->m_Components.p;
        do
        {
          v18 = v19;
          if ( (p[v19].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::TargetingSystemBaseComponent::_TypeUID & ~p[v19].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_13;
          }
        }
        while ( ++v19 < v20 );
      }
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
  m_pComponent = simObject->m_Components.p[20].m_pComponent;
LABEL_23:
  if ( !m_pComponent )
    return;
  v21 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + v9 + 8)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
  if ( !v21 )
    return;
  v22 = v21->m_Flags;
  if ( (v22 & 0x4000) != 0 )
  {
    v23 = (UFG::CharacterAnimationComponent *)v21->m_Components.p[9].m_pComponent;
    if ( !v23
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ v23->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~v23->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_29;
    }
  }
  else
  {
    if ( v22 >= 0 )
    {
      if ( (v22 & 0x2000) != 0 )
      {
        ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v21);
      }
      else
      {
        if ( (v22 & 0x1000) != 0 )
        {
          mComponentTableEntryCount = v21->mComponentTableEntryCount;
          v26 = v21->m_Components.size;
          if ( mComponentTableEntryCount < v26 )
          {
            v27 = v21->m_Components.p;
            while ( (v27[mComponentTableEntryCount].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                 || (UFG::CharacterAnimationComponent::_TypeUID & ~v27[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) != 0 )
            {
              if ( ++mComponentTableEntryCount >= v26 )
                goto LABEL_29;
            }
            v23 = (UFG::CharacterAnimationComponent *)v27[mComponentTableEntryCount].m_pComponent;
            goto LABEL_47;
          }
          goto LABEL_29;
        }
        ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                v21,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
      }
      v23 = ComponentOfType;
      goto LABEL_47;
    }
    v23 = (UFG::CharacterAnimationComponent *)v21->m_Components.p[9].m_pComponent;
    if ( !v23 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v23->m_TypeUID) & 0xFE000000) != 0 )
    {
LABEL_29:
      v23 = 0i64;
      goto LABEL_47;
    }
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v23->m_TypeUID & 0x1FFFFFF) != 0 )
      v23 = 0i64;
  }
LABEL_47:
  if ( v23 )
  {
    mCreature = animationComponent->mCreature;
    v29 = v23->mCreature;
    if ( mCreature )
    {
      if ( v29 )
      {
        if ( v29->mPose.mRigHandle.mData )
        {
          if ( mCreature->mPose.mRigHandle.mData )
          {
            v30 = (__int64)&mCreature->mPoseDrivers.mNode.mNext[-1];
            if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v30 != &mCreature->m_SafePointerList )
            {
              while ( *(_DWORD *)(v30 + 44) != attachEffectorUID->mUID )
              {
                v30 = *(_QWORD *)(v30 + 24) - 16i64;
                if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v30 == &mCreature->m_SafePointerList )
                  return;
              }
              v31 = UFG::qMalloc(0x160ui64, "TargetAttachEffectorTask.Attachment", 0i64);
              if ( v31 )
              {
                AttachmentCreatureEffectorToCreatureReverse::AttachmentCreatureEffectorToCreatureReverse((AttachmentCreatureEffectorToCreatureReverse *)v31);
                v13 = v32;
              }
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v13 + 208),
                v23);
              *(_QWORD *)(v13 + 232) = v30;
              *(_DWORD *)(v13 + 240) = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v30 + 112i64))(v30);
              v33 = -1;
              if ( mCreature->mPose.mRigHandle.mData )
                BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, adjustJointUID->mUID);
              else
                BoneID = -1;
              *(_DWORD *)(v13 + 244) = BoneID;
              if ( v29->mPose.mRigHandle.mData )
                v33 = Skeleton::GetBoneID(v29->mPose.mRigHandle.mUFGSkeleton, baseJointUID->mUID);
              *(_DWORD *)(v13 + 248) = v33;
              *(_DWORD *)(v13 + 256) = 1065353216;
              Attachment::SetBlendIn((Attachment *)v13, blendTime);
              *(_BYTE *)(v13 + 252) = onlyEnablePostPhysics;
              *(_DWORD *)(v13 + 32) = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v30 + 112i64))(v30);
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v13 + 40),
                (UFG::SimComponent *)simObject);
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v13 + 64),
                (UFG::SimComponent *)mCreature);
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v13 + 88),
                (UFG::SimComponent *)v21);
              if ( Creature::AddAttachment(mCreature, (Attachment *)v13) != (UFG::qNode<Attachment,Attachment> **)v13 )
                (**(void (__fastcall ***)(__int64, __int64))v13)(v13, 1i64);
            }
          }
        }
      }
    }
  }
}

// File Line: 885
// RVA: 0x5542A0
__int64 __fastcall UFG::TargetAttachConstraint(
        UFG::SimObjectProp *simObject,
        UFG::eTargetTypeEnum targetType,
        UFG::qSymbolUC *attachJoint,
        UFG::qSymbolUC *targetAttachJoint,
        bool attachRelative,
        bool assignTarget,
        unsigned int assignmentTargetType,
        bool lockTarget)
{
  unsigned __int8 v8; // r14
  __int64 v11; // r13
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *v18; // rdx
  __int64 v19; // rax
  bool v20; // zf
  signed __int16 v21; // cx
  UFG::TargetingSystemBaseComponent *v22; // rdi
  unsigned int v23; // r8d
  unsigned int v24; // r10d
  UFG::SimComponentHolder *v25; // rdx
  unsigned int v26; // r8d
  unsigned int v27; // r10d
  UFG::SimObjectProp *Target; // rax
  UFG::SimObject *v29; // rsi
  __int16 v30; // cx
  int BoneID; // r12d
  UFG::CharacterAnimationComponent *v32; // rcx
  UFG::CharacterAnimationComponent *v33; // rax
  unsigned int v34; // r8d
  unsigned int v35; // r10d
  __int64 v36; // rdx
  Creature *mCreature; // rbp
  UFG::RagdollComponent *v38; // r15
  UFG::SimComponent *v39; // rax
  UFG::SimComponent *v40; // rbx
  UFG::Ragdoll *mRagdoll; // rcx
  hkpRigidBody *v42; // rsi
  UFG::Ragdoll *mPrev; // rcx
  hkpRigidBody *v44; // rbx
  UFG::Constraint *v45; // rax
  unsigned int v46; // r8d
  UFG::qVector3 v48; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-58h] BYREF
  UFG::qVector3 pivotWorldConstraint; // [rsp+60h] [rbp-48h] BYREF
  int skeletonBoneID; // [rsp+B0h] [rbp+8h]

  v8 = 0;
  v11 = targetType;
  if ( !simObject )
    return v8;
  m_Flags = simObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = simObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = simObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_6;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(simObject);
LABEL_23:
    m_pComponent = ComponentOfType;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            simObject,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  mComponentTableEntryCount = simObject->mComponentTableEntryCount;
  size = simObject->m_Components.size;
  if ( mComponentTableEntryCount >= size )
  {
LABEL_6:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
  v18 = &simObject->m_Components.p[mComponentTableEntryCount];
  while ( (v18->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    ++v18;
    if ( mComponentTableEntryCount >= size )
    {
      m_pComponent = 0i64;
      goto LABEL_24;
    }
  }
  m_pComponent = v18->m_pComponent;
LABEL_24:
  if ( !m_pComponent )
    return v8;
  v19 = *(_QWORD *)&m_pComponent[2].m_TypeUID;
  v20 = *(_QWORD *)(v19 + 440) == 0i64;
  *(_QWORD *)&v48.x = v19;
  if ( v20 )
    skeletonBoneID = -1;
  else
    skeletonBoneID = Skeleton::GetBoneID(*(Skeleton **)(v19 + 480), attachJoint->mUID);
  v21 = simObject->m_Flags;
  if ( (v21 & 0x4000) != 0 )
  {
    v22 = (UFG::TargetingSystemBaseComponent *)simObject->m_Components.p[20].m_pComponent;
    goto LABEL_48;
  }
  if ( v21 < 0 )
  {
    v22 = (UFG::TargetingSystemBaseComponent *)simObject->m_Components.p[20].m_pComponent;
    goto LABEL_48;
  }
  if ( (v21 & 0x2000) != 0 )
  {
    v23 = simObject->mComponentTableEntryCount;
    v24 = simObject->m_Components.size;
    if ( v23 < v24 )
    {
      v25 = &simObject->m_Components.p[v23];
      while ( (v25->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v25->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v23;
        ++v25;
        if ( v23 >= v24 )
          goto LABEL_38;
      }
LABEL_39:
      v22 = (UFG::TargetingSystemBaseComponent *)v25->m_pComponent;
      goto LABEL_48;
    }
    goto LABEL_38;
  }
  if ( (v21 & 0x1000) != 0 )
  {
    v26 = simObject->mComponentTableEntryCount;
    v27 = simObject->m_Components.size;
    if ( v26 < v27 )
    {
      v25 = &simObject->m_Components.p[v26];
      while ( (v25->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v25->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v26;
        ++v25;
        if ( v26 >= v27 )
        {
          v22 = 0i64;
          goto LABEL_48;
        }
      }
      goto LABEL_39;
    }
LABEL_38:
    v22 = 0i64;
    goto LABEL_48;
  }
  v22 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                               simObject,
                                               UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_48:
  Target = (UFG::SimObjectProp *)UFG::getTarget(simObject, v22, (UFG::eTargetTypeEnum)v11);
  v29 = Target;
  if ( !Target )
  {
    UFG::qPrintf("WARNING: TargetAttachConstraint: Target Not Found! (%s)\n", UFG::TargetTypeEnumNames[v11]);
    return v8;
  }
  v30 = Target->m_Flags;
  BoneID = 0;
  if ( (v30 & 0x4000) == 0 )
  {
    if ( v30 < 0 )
    {
      v32 = (UFG::CharacterAnimationComponent *)Target->m_Components.p[9].m_pComponent;
      if ( v32 && ((UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000) == 0 )
      {
        if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
          v32 = 0i64;
        goto LABEL_71;
      }
      goto LABEL_53;
    }
    if ( (v30 & 0x2000) != 0 )
    {
      v33 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(Target);
    }
    else
    {
      if ( (v30 & 0x1000) != 0 )
      {
        v34 = Target->mComponentTableEntryCount;
        v35 = Target->m_Components.size;
        if ( v34 < v35 )
        {
          v36 = (__int64)&Target->m_Components.p[v34];
          while ( (*(_DWORD *)(v36 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v36 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v34;
            v36 += 16i64;
            if ( v34 >= v35 )
            {
              v32 = 0i64;
              goto LABEL_71;
            }
          }
          v32 = *(UFG::CharacterAnimationComponent **)v36;
          goto LABEL_71;
        }
        goto LABEL_53;
      }
      v33 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  Target,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    v32 = v33;
    goto LABEL_71;
  }
  v32 = (UFG::CharacterAnimationComponent *)Target->m_Components.p[9].m_pComponent;
  if ( !v32
    || ((UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000) != 0
    || (UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
  {
LABEL_53:
    v32 = 0i64;
  }
LABEL_71:
  if ( v32 )
    mCreature = v32->mCreature;
  else
    mCreature = 0i64;
  if ( mCreature )
  {
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, targetAttachJoint->mUID);
    v38 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(simObject, UFG::RagdollComponent::_TypeUID);
    v39 = UFG::SimObject::GetComponentOfType(v29, UFG::RagdollComponent::_TypeUID);
    v40 = v39;
    if ( v38 && v39 )
    {
      mRagdoll = v38->mRagdoll;
      v42 = mRagdoll ? UFG::Ragdoll::GetRigidBody(mRagdoll, skeletonBoneID) : 0i64;
      mPrev = (UFG::Ragdoll *)v40[1].m_BoundComponentHandles.mNode.mPrev;
      v44 = mPrev ? UFG::Ragdoll::GetRigidBody(mPrev, BoneID) : 0i64;
      if ( v42 && v44 )
      {
        Creature::GetTranslation(*(Creature **)&v48.x, &result, skeletonBoneID);
        Creature::GetTranslation(mCreature, &v48, BoneID);
        pivotWorldConstraint.x = result.x + (float)((float)(v48.x - result.x) * 0.5);
        pivotWorldConstraint.z = result.z + (float)((float)(v48.z - result.z) * 0.5);
        pivotWorldConstraint.y = (float)((float)(v48.y - result.y) * 0.5) + result.y;
        v45 = UFG::CreateConstraint_Util(v42, v44, &pivotWorldConstraint);
        UFG::RagdollComponent::AddConstraint(v38, v45);
        v8 = 1;
      }
    }
  }
  if ( v22 && v8 )
  {
    if ( assignTarget )
    {
      v46 = v11;
      LODWORD(v11) = assignmentTargetType;
      UFG::TargetingSystemBaseComponent::AssignTarget(v22, assignmentTargetType, v46);
    }
    if ( lockTarget )
      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, __int64))v22->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
        v22,
        (unsigned int)v11,
        1i64);
  }
  return v8;
}

// File Line: 986
// RVA: 0x555FC0
char __fastcall UFG::TargetDetachConstraint(
        UFG::SimObjectProp *simObject,
        UFG::eTargetTypeEnum targetType,
        UFG::qSymbolUC *attachJoint,
        UFG::qSymbolUC *targetAttachJoint)
{
  hkpRigidBody *RigidBody; // rbp
  __int64 v7; // r14
  signed __int16 m_Flags; // r10
  UFG::SimComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v12; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v16; // rdx
  __int64 v17; // rcx
  int BoneID; // r15d
  UFG::TargetingSystemBaseComponent *v19; // rax
  signed __int16 v20; // cx
  unsigned int v21; // r8d
  unsigned int v22; // r9d
  UFG::SimComponentHolder *v23; // rdx
  unsigned int v24; // r8d
  unsigned int v25; // r9d
  UFG::SimObjectProp *Target; // rax
  UFG::SimObject *v27; // rsi
  __int16 v28; // cx
  int v29; // r14d
  UFG::CharacterAnimationComponent *v30; // rbx
  UFG::CharacterAnimationComponent *v31; // rax
  unsigned int v32; // edx
  unsigned int v33; // r8d
  __int64 v34; // rbx
  Creature *mCreature; // rcx
  UFG::RagdollComponent *v36; // rbx
  UFG::SimComponent *v37; // rax
  UFG::SimComponent *v38; // rsi
  UFG::Ragdoll *mRagdoll; // rcx
  hkpRigidBody *v40; // rdi
  UFG::Ragdoll *mPrev; // rcx

  RigidBody = 0i64;
  v7 = targetType;
  if ( !simObject )
    goto LABEL_26;
  m_Flags = simObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = simObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    m_TypeUID = m_pComponent->m_TypeUID;
    if ( ((m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = simObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    v12 = m_pComponent->m_TypeUID;
    if ( ((v12 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_6;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v12 & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(simObject);
LABEL_23:
    m_pComponent = ComponentOfType;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            simObject,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  mComponentTableEntryCount = simObject->mComponentTableEntryCount;
  size = simObject->m_Components.size;
  if ( mComponentTableEntryCount >= size )
  {
LABEL_6:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
  v16 = &simObject->m_Components.p[mComponentTableEntryCount];
  while ( (v16->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~v16->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    ++v16;
    if ( mComponentTableEntryCount >= size )
    {
      m_pComponent = 0i64;
      goto LABEL_24;
    }
  }
  m_pComponent = v16->m_pComponent;
LABEL_24:
  if ( m_pComponent )
  {
    v17 = *(_QWORD *)&m_pComponent[2].m_TypeUID;
    goto LABEL_27;
  }
LABEL_26:
  v17 = 0i64;
LABEL_27:
  if ( !v17 )
    return 0;
  if ( *(_QWORD *)(v17 + 440) )
    BoneID = Skeleton::GetBoneID(*(Skeleton **)(v17 + 480), attachJoint->mUID);
  else
    BoneID = -1;
  if ( !simObject )
    goto LABEL_32;
  v20 = simObject->m_Flags;
  if ( (v20 & 0x4000) != 0 )
  {
    v19 = (UFG::TargetingSystemBaseComponent *)simObject->m_Components.p[20].m_pComponent;
    goto LABEL_53;
  }
  if ( v20 < 0 )
  {
    v19 = (UFG::TargetingSystemBaseComponent *)simObject->m_Components.p[20].m_pComponent;
    goto LABEL_53;
  }
  if ( (v20 & 0x2000) != 0 )
  {
    v21 = simObject->mComponentTableEntryCount;
    v22 = simObject->m_Components.size;
    if ( v21 < v22 )
    {
      v23 = &simObject->m_Components.p[v21];
      while ( (v23->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v23->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v21;
        ++v23;
        if ( v21 >= v22 )
        {
          v19 = 0i64;
          goto LABEL_53;
        }
      }
LABEL_44:
      v19 = (UFG::TargetingSystemBaseComponent *)v23->m_pComponent;
      goto LABEL_53;
    }
    goto LABEL_32;
  }
  if ( (v20 & 0x1000) != 0 )
  {
    v24 = simObject->mComponentTableEntryCount;
    v25 = simObject->m_Components.size;
    if ( v24 < v25 )
    {
      v23 = &simObject->m_Components.p[v24];
      while ( (v23->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v23->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v24;
        ++v23;
        if ( v24 >= v25 )
        {
          v19 = 0i64;
          goto LABEL_53;
        }
      }
      goto LABEL_44;
    }
LABEL_32:
    v19 = 0i64;
    goto LABEL_53;
  }
  v19 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                               simObject,
                                               UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_53:
  Target = (UFG::SimObjectProp *)UFG::getTarget(simObject, v19, (UFG::eTargetTypeEnum)v7);
  v27 = Target;
  if ( !Target )
  {
    UFG::qPrintf("WARNING: TargetDetachConstraint: Target Not Found! (%s)\n", UFG::TargetTypeEnumNames[v7]);
    return 0;
  }
  v28 = Target->m_Flags;
  v29 = 0;
  if ( (v28 & 0x4000) != 0 )
  {
    v30 = (UFG::CharacterAnimationComponent *)Target->m_Components.p[9].m_pComponent;
    if ( v30
      && ((UFG::CharacterAnimationComponent::_TypeUID ^ v30->m_TypeUID) & 0xFE000000) == 0
      && (UFG::CharacterAnimationComponent::_TypeUID & ~v30->m_TypeUID & 0x1FFFFFF) == 0 )
    {
      goto LABEL_76;
    }
    goto LABEL_58;
  }
  if ( v28 < 0 )
  {
    v30 = (UFG::CharacterAnimationComponent *)Target->m_Components.p[9].m_pComponent;
    if ( v30 && ((UFG::CharacterAnimationComponent::_TypeUID ^ v30->m_TypeUID) & 0xFE000000) == 0 )
    {
      if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v30->m_TypeUID & 0x1FFFFFF) != 0 )
        v30 = 0i64;
      goto LABEL_76;
    }
LABEL_58:
    v30 = 0i64;
    goto LABEL_76;
  }
  if ( (v28 & 0x2000) != 0 )
  {
    v31 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(Target);
LABEL_75:
    v30 = v31;
    goto LABEL_76;
  }
  if ( (v28 & 0x1000) == 0 )
  {
    v31 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                Target,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_75;
  }
  v32 = Target->mComponentTableEntryCount;
  v33 = Target->m_Components.size;
  if ( v32 >= v33 )
    goto LABEL_58;
  v34 = (__int64)&Target->m_Components.p[v32];
  while ( (*(_DWORD *)(v34 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v34 + 8) & 0x1FFFFFF) != 0 )
  {
    ++v32;
    v34 += 16i64;
    if ( v32 >= v33 )
    {
      v30 = 0i64;
      goto LABEL_76;
    }
  }
  v30 = *(UFG::CharacterAnimationComponent **)v34;
LABEL_76:
  if ( v30 )
    mCreature = v30->mCreature;
  else
    mCreature = 0i64;
  if ( mCreature && mCreature->mPose.mRigHandle.mData )
    v29 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, targetAttachJoint->mUID);
  if ( !v30 )
    return 0;
  v36 = simObject
      ? (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(simObject, UFG::RagdollComponent::_TypeUID)
      : 0i64;
  v37 = UFG::SimObject::GetComponentOfType(v27, UFG::RagdollComponent::_TypeUID);
  v38 = v37;
  if ( !v36 || !v37 )
    return 0;
  mRagdoll = v36->mRagdoll;
  v40 = mRagdoll ? UFG::Ragdoll::GetRigidBody(mRagdoll, BoneID) : 0i64;
  mPrev = (UFG::Ragdoll *)v38[1].m_BoundComponentHandles.mNode.mPrev;
  if ( mPrev )
    RigidBody = UFG::Ragdoll::GetRigidBody(mPrev, v29);
  if ( !v40 || !RigidBody )
    return 0;
  UFG::RagdollComponent::RemoveConstraint(v36, v40, RigidBody);
  return 1;
}

// File Line: 1064
// RVA: 0x5514D0
void __fastcall UFG::SteerToTarget(
        UFG::SimObjectProp *pMe,
        UFG::SimObjectProp *pTarget,
        UFG::qSymbolUC *targetAttachJoint,
        float fMaxRotationRadians)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *v12; // rdx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  UFG::AimingBaseComponent *v14; // r14
  char v15; // r12
  signed __int16 v16; // cx
  UFG::SimComponent *v17; // rcx
  unsigned int v18; // r8d
  unsigned int v19; // r9d
  unsigned int v20; // r11d
  UFG::SimComponentHolder *v21; // rdx
  unsigned int v22; // r9d
  unsigned int v23; // r11d
  float y; // xmm6_4
  float x; // xmm7_4
  signed __int16 v26; // cx
  unsigned int v27; // r9d
  unsigned int v28; // r11d
  UFG::SimComponentHolder *v29; // rdx
  unsigned int v30; // r9d
  unsigned int v31; // r11d
  unsigned int v32; // r9d
  unsigned int v33; // r11d
  char v34; // si
  UFG::TransformNodeComponent *v35; // rsi
  float z; // xmm8_4
  signed __int16 v37; // cx
  UFG::SimComponent *v38; // rcx
  UFG::CharacterAnimationComponent *v39; // rax
  unsigned int v40; // r8d
  unsigned int v41; // r10d
  UFG::SimComponentHolder *v42; // rdi
  UFG::SimComponentHolder *v43; // rdx
  Creature *v44; // rdi
  int BoneID; // eax
  float v46; // xmm2_4
  signed __int16 v47; // cx
  unsigned int v48; // r9d
  unsigned int v49; // r11d
  UFG::SimComponentHolder *v50; // rdx
  UFG::RigidBody *v51; // rax
  unsigned int v52; // r9d
  unsigned int v53; // r11d
  unsigned int v54; // r9d
  unsigned int v55; // r11d
  unsigned int v56; // r9d
  unsigned int v57; // r11d
  __m128 v58; // xmm1
  float v59; // xmm3_4
  signed __int16 v60; // cx
  UFG::SimComponent *v61; // rdi
  unsigned int v62; // r9d
  unsigned int v63; // r11d
  UFG::SimComponentHolder *v64; // rdx
  unsigned int v65; // r9d
  unsigned int v66; // r11d
  signed __int16 v67; // dx
  UFG::SimComponent *v68; // rcx
  unsigned int v69; // r8d
  unsigned int v70; // r10d
  UFG::SimComponentHolder *p; // rbx
  __int64 v72; // rdx
  unsigned int v73; // r8d
  unsigned int v74; // r10d
  unsigned int v75; // r8d
  unsigned int v76; // r10d
  float v77; // xmm6_4
  __m128 m_NameUID; // xmm7
  __m128 v79; // xmm2
  float v80; // xmm1_4
  float v81; // xmm6_4
  float v82; // xmm7_4
  signed __int16 v83; // cx
  UFG::SimComponent *v84; // rcx
  unsigned int v85; // r9d
  unsigned int v86; // r11d
  UFG::SimComponentHolder *v87; // rbx
  __int64 v88; // rdx
  unsigned int v89; // r9d
  unsigned int v90; // r11d
  float v91; // xmm6_4
  float v92; // xmm7_4
  float v93; // xmm1_4
  float v94; // xmm2_4
  float v95; // xmm8_4
  float v96; // xmm10_4
  float v97; // xmm5_4
  float v98; // xmm11_4
  float v99; // xmm9_4
  int v100; // xmm0_4
  float v101; // xmm1_4
  float v102; // xmm4_4
  float v103; // xmm2_4
  __m128 y_low; // xmm3
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm2_4
  Creature *mCreature; // rdi
  __m128 v109; // xmm4
  __m128 v110; // xmm5
  __m128 v111; // xmm6
  __m128 v112; // xmm6
  __m128 v113; // xmm3
  UFG::qVector3 dest; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qVector3 v115; // [rsp+30h] [rbp-98h] BYREF
  hkQuaternionf v116; // [rsp+40h] [rbp-88h] BYREF
  UFG::qVector3 source; // [rsp+50h] [rbp-78h] BYREF
  float v118; // [rsp+5Ch] [rbp-6Ch]
  UFG::qMatrix44 transform; // [rsp+60h] [rbp-68h] BYREF
  UFG::CharacterAnimationComponent *v120; // [rsp+148h] [rbp+80h]
  float v121; // [rsp+160h] [rbp+98h]
  float v122; // [rsp+168h] [rbp+A0h]
  float radians; // [rsp+170h] [rbp+A8h]
  void *retaddr; // [rsp+178h] [rbp+B0h]
  char v125; // [rsp+180h] [rbp+B8h]
  float *v126; // [rsp+188h] [rbp+C0h]

  if ( !pMe )
    return;
  *(_QWORD *)&transform.v0.z = -2i64;
  if ( !pTarget && !(_BYTE)retaddr )
    return;
  m_Flags = pMe->m_Flags;
  if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pMe);
LABEL_20:
      v120 = ComponentOfType;
      goto LABEL_21;
    }
    if ( (m_Flags & 0x1000) == 0 )
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              pMe,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
      goto LABEL_20;
    }
    mComponentTableEntryCount = pMe->mComponentTableEntryCount;
    size = pMe->m_Components.size;
    if ( mComponentTableEntryCount < size )
    {
      while ( 1 )
      {
        v12 = &pMe->m_Components.p[mComponentTableEntryCount];
        if ( (v12->m_TypeUID & 0xFE000000) == (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
          && (UFG::CharacterAnimationComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++mComponentTableEntryCount >= size )
          goto LABEL_8;
      }
      ComponentOfType = (UFG::CharacterAnimationComponent *)v12->m_pComponent;
      goto LABEL_20;
    }
    goto LABEL_8;
  }
  m_pComponent = pMe->m_Components.p[9].m_pComponent;
  v120 = (UFG::CharacterAnimationComponent *)m_pComponent;
  if ( !m_pComponent
    || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
    || (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
  {
LABEL_8:
    v120 = 0i64;
  }
LABEL_21:
  m_pTransformNodeComponent = pMe->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v14 = 0i64;
  v15 = 0;
  v16 = pMe->m_Flags;
  if ( (v16 & 0x4000) == 0 && v16 >= 0 )
  {
    if ( (v16 & 0x2000) != 0 )
    {
      v19 = pMe->mComponentTableEntryCount;
      v20 = pMe->m_Components.size;
      v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
      if ( v19 < v20 )
      {
        while ( 1 )
        {
          v21 = &pMe->m_Components.p[v19];
          if ( (v21->m_TypeUID & 0xFE000000) == (UFG::AICharacterControllerBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::AICharacterControllerBaseComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v19 >= v20 )
            goto LABEL_25;
        }
LABEL_33:
        v17 = v21->m_pComponent;
        goto LABEL_41;
      }
    }
    else
    {
      if ( (v16 & 0x1000) == 0 )
      {
        v17 = UFG::SimObject::GetComponentOfType(pMe, UFG::AICharacterControllerBaseComponent::_TypeUID);
        v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
        goto LABEL_41;
      }
      v22 = pMe->mComponentTableEntryCount;
      v23 = pMe->m_Components.size;
      v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
      if ( v22 < v23 )
      {
        while ( 1 )
        {
          v21 = &pMe->m_Components.p[v22];
          if ( (v21->m_TypeUID & 0xFE000000) == (UFG::AICharacterControllerBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::AICharacterControllerBaseComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_33;
          }
          if ( ++v22 >= v23 )
            goto LABEL_25;
        }
      }
    }
    goto LABEL_25;
  }
  v17 = pMe->m_Components.p[21].m_pComponent;
  v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
  if ( !v17
    || ((UFG::AICharacterControllerBaseComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000) != 0
    || (UFG::AICharacterControllerBaseComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
  {
LABEL_25:
    v17 = 0i64;
  }
LABEL_41:
  if ( v17 && LOBYTE(v17[2].m_Flags) )
  {
    y = *(float *)&v17[2].m_pSimObject + m_pTransformNodeComponent->mWorldTransform.v3.y;
    x = *(float *)(&v17[2].m_SimObjIndex + 1) + m_pTransformNodeComponent->mWorldTransform.v3.x;
    v15 = 1;
  }
  else
  {
    y = v116.m_vec.m_quad.m128_f32[1];
    x = v116.m_vec.m_quad.m128_f32[0];
  }
  if ( !v126 )
  {
    if ( !v125 )
      goto LABEL_73;
    v26 = pMe->m_Flags;
    if ( (v26 & 0x4000) != 0 )
    {
      v14 = (UFG::AimingBaseComponent *)pMe->m_Components.p[47].m_pComponent;
      goto LABEL_71;
    }
    if ( v26 >= 0 )
    {
      if ( (v26 & 0x2000) != 0 )
      {
        v30 = pMe->mComponentTableEntryCount;
        v31 = pMe->m_Components.size;
        if ( v30 < v31 )
        {
          do
          {
            v29 = &pMe->m_Components.p[v30];
            if ( (v29->m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
              && (UFG::AimingBaseComponent::_TypeUID & ~v29->m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_56;
            }
          }
          while ( ++v30 < v31 );
        }
      }
      else
      {
        if ( (v26 & 0x1000) == 0 )
        {
          v14 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(pMe, UFG::AimingBaseComponent::_TypeUID);
          v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
LABEL_71:
          if ( v14 )
          {
            x = v14->m_vAimIntentionTargetPosition.x;
            y = v14->m_vAimIntentionTargetPosition.y;
            v34 = 1;
            goto LABEL_230;
          }
LABEL_73:
          if ( v15 )
            goto LABEL_229;
          if ( !pTarget )
          {
LABEL_140:
            if ( !(_BYTE)retaddr )
              return;
            v60 = pMe->m_Flags;
            if ( (v60 & 0x4000) != 0 )
            {
              v61 = pMe->m_Components.p[20].m_pComponent;
              if ( !v61
                || ((UFG::TargetingSystemPedPlayerComponent::_TypeUID ^ v61->m_TypeUID) & 0xFE000000) != 0
                || (UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
              {
                goto LABEL_145;
              }
LABEL_165:
              if ( v61 )
              {
                if ( (unsigned int)(LODWORD(v61[53].m_pSimObject) - 3) > 1 )
                {
LABEL_197:
                  v81 = *(float *)&v61[42].m_pSimObject;
                  v82 = *(float *)(&v61[42].m_SimObjIndex + 1);
                  goto LABEL_227;
                }
                v67 = pMe->m_Flags;
                if ( (v67 & 0x4000) != 0 )
                {
                  v68 = pMe->m_Components.p[47].m_pComponent;
                  if ( !v68
                    || ((UFG::AimingPlayerComponent::_TypeUID ^ v68->m_TypeUID) & 0xFE000000) != 0
                    || (UFG::AimingPlayerComponent::_TypeUID & ~v68->m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    goto LABEL_171;
                  }
LABEL_195:
                  if ( v68 )
                  {
                    v77 = *(float *)&v68[9].m_Flags;
                    m_NameUID = (__m128)v68[9].m_NameUID;
                    v79 = m_NameUID;
                    v79.m128_f32[0] = (float)((float)(m_NameUID.m128_f32[0] * m_NameUID.m128_f32[0]) + (float)(v77 * v77))
                                    + (float)(*(float *)(&v68[9].m_SimObjIndex + 1)
                                            * *(float *)(&v68[9].m_SimObjIndex + 1));
                    v80 = UFG::AimingPlayerComponent::ms_fFreeAimFocusRange / _mm_sqrt_ps(v79).m128_f32[0];
                    y = (float)(v77 * v80) + *(float *)&v68[9].m_SafePointerList.mNode.mPrev;
                    x = (float)(m_NameUID.m128_f32[0] * v80) + *((float *)&v68[9].vfptr + 1);
                    goto LABEL_229;
                  }
                  goto LABEL_197;
                }
                if ( v67 >= 0 )
                {
                  if ( (v67 & 0x2000) != 0 )
                  {
                    v73 = pMe->mComponentTableEntryCount;
                    v74 = pMe->m_Components.size;
                    if ( v73 < v74 )
                    {
                      p = pMe->m_Components.p;
                      do
                      {
                        v72 = v73;
                        if ( (p[v73].m_TypeUID & 0xFE000000) == (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
                          && (UFG::AimingPlayerComponent::_TypeUID & ~p[v73].m_TypeUID & 0x1FFFFFF) == 0 )
                        {
                          goto LABEL_179;
                        }
                      }
                      while ( ++v73 < v74 );
                    }
                  }
                  else
                  {
                    if ( (v67 & 0x1000) == 0 )
                    {
                      v68 = UFG::SimObject::GetComponentOfType(pMe, UFG::AimingPlayerComponent::_TypeUID);
                      goto LABEL_195;
                    }
                    v75 = pMe->mComponentTableEntryCount;
                    v76 = pMe->m_Components.size;
                    if ( v75 < v76 )
                    {
                      p = pMe->m_Components.p;
                      do
                      {
                        v72 = v75;
                        if ( (p[v75].m_TypeUID & 0xFE000000) == (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
                          && (UFG::AimingPlayerComponent::_TypeUID & ~p[v75].m_TypeUID & 0x1FFFFFF) == 0 )
                        {
                          goto LABEL_179;
                        }
                      }
                      while ( ++v75 < v76 );
                    }
                  }
                }
                else
                {
                  v69 = pMe->mComponentTableEntryCount;
                  v70 = pMe->m_Components.size;
                  if ( v69 < v70 )
                  {
                    p = pMe->m_Components.p;
                    while ( 1 )
                    {
                      v72 = v69;
                      if ( (p[v69].m_TypeUID & 0xFE000000) == (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
                        && (UFG::AimingPlayerComponent::_TypeUID & ~p[v69].m_TypeUID & 0x1FFFFFF) == 0 )
                      {
                        break;
                      }
                      if ( ++v69 >= v70 )
                        goto LABEL_171;
                    }
LABEL_179:
                    v68 = p[v72].m_pComponent;
                    goto LABEL_195;
                  }
                }
LABEL_171:
                v68 = 0i64;
                goto LABEL_195;
              }
              v83 = pMe->m_Flags;
              if ( (v83 & 0x4000) != 0 )
              {
                v84 = pMe->m_Components.p[21].m_pComponent;
                if ( v84 && ((v18 ^ v84->m_TypeUID) & 0xFE000000) == 0 && (v18 & ~v84->m_TypeUID & 0x1FFFFFF) == 0 )
                  goto LABEL_224;
                goto LABEL_202;
              }
              if ( v83 < 0 )
              {
                v84 = pMe->m_Components.p[21].m_pComponent;
                if ( v84 && ((v18 ^ v84->m_TypeUID) & 0xFE000000) == 0 )
                {
                  if ( (v18 & ~v84->m_TypeUID & 0x1FFFFFF) != 0 )
                    v84 = 0i64;
                  goto LABEL_224;
                }
                goto LABEL_202;
              }
              if ( (v83 & 0x2000) != 0 )
              {
                v85 = pMe->mComponentTableEntryCount;
                v86 = pMe->m_Components.size;
                if ( v85 >= v86 )
                {
LABEL_202:
                  v84 = 0i64;
LABEL_224:
                  if ( v84 )
                  {
                    v81 = *(float *)&v84[2].m_TypeUID;
                    x = m_pTransformNodeComponent->mWorldTransform.v3.x
                      + *((float *)&v84[2].m_SafePointerList.mNode.mNext + 1);
LABEL_228:
                    y = v81 + m_pTransformNodeComponent->mWorldTransform.v3.y;
                    goto LABEL_229;
                  }
                  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                  v81 = m_pTransformNodeComponent->mWorldTransform.v0.y;
                  v82 = m_pTransformNodeComponent->mWorldTransform.v0.x;
LABEL_227:
                  x = v82 + m_pTransformNodeComponent->mWorldTransform.v3.x;
                  goto LABEL_228;
                }
                v87 = pMe->m_Components.p;
                while ( 1 )
                {
                  v88 = v85;
                  if ( (v87[v85].m_TypeUID & 0xFE000000) == (v18 & 0xFE000000)
                    && (v18 & ~v87[v85].m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    break;
                  }
                  if ( ++v85 >= v86 )
                    goto LABEL_202;
                }
              }
              else
              {
                if ( (v83 & 0x1000) == 0 )
                {
                  v84 = UFG::SimObject::GetComponentOfType(pMe, v18);
                  goto LABEL_224;
                }
                v89 = pMe->mComponentTableEntryCount;
                v90 = pMe->m_Components.size;
                if ( v89 >= v90 )
                  goto LABEL_202;
                v87 = pMe->m_Components.p;
                while ( 1 )
                {
                  v88 = v89;
                  if ( (v87[v89].m_TypeUID & 0xFE000000) == (v18 & 0xFE000000)
                    && (v18 & ~v87[v89].m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    break;
                  }
                  if ( ++v89 >= v90 )
                    goto LABEL_202;
                }
              }
              v84 = v87[v88].m_pComponent;
              goto LABEL_224;
            }
            if ( v60 < 0 )
            {
              v61 = pMe->m_Components.p[20].m_pComponent;
              if ( !v61 || ((UFG::TargetingSystemPedPlayerComponent::_TypeUID ^ v61->m_TypeUID) & 0xFE000000) != 0 )
                goto LABEL_145;
              if ( (UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
                v61 = 0i64;
              goto LABEL_165;
            }
            if ( (v60 & 0x2000) != 0 )
            {
              v62 = pMe->mComponentTableEntryCount;
              v63 = pMe->m_Components.size;
              if ( v62 < v63 )
              {
                while ( 1 )
                {
                  v64 = &pMe->m_Components.p[v62];
                  if ( (v64->m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedPlayerComponent::_TypeUID & 0xFE000000)
                    && (UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v64->m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    break;
                  }
                  if ( ++v62 >= v63 )
                    goto LABEL_145;
                }
LABEL_157:
                v61 = v64->m_pComponent;
                goto LABEL_165;
              }
            }
            else
            {
              if ( (v60 & 0x1000) == 0 )
              {
                v61 = UFG::SimObject::GetComponentOfType(pMe, UFG::TargetingSystemPedPlayerComponent::_TypeUID);
                v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                goto LABEL_165;
              }
              v65 = pMe->mComponentTableEntryCount;
              v66 = pMe->m_Components.size;
              if ( v65 < v66 )
              {
                do
                {
                  v64 = &pMe->m_Components.p[v65];
                  if ( (v64->m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedPlayerComponent::_TypeUID & 0xFE000000)
                    && (UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v64->m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    goto LABEL_157;
                  }
                }
                while ( ++v65 < v66 );
              }
            }
LABEL_145:
            v61 = 0i64;
            goto LABEL_165;
          }
          v35 = pTarget->m_pTransformNodeComponent;
          if ( v35 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(pTarget->m_pTransformNodeComponent);
            x = v35->mWorldTransform.v3.x;
            y = v35->mWorldTransform.v3.y;
            z = v35->mWorldTransform.v3.z;
            if ( targetAttachJoint->mUID == -1 )
              goto LABEL_106;
            v37 = pTarget->m_Flags;
            if ( (v37 & 0x4000) != 0 )
            {
              v38 = pTarget->m_Components.p[9].m_pComponent;
              if ( v38
                && ((UFG::CharacterAnimationComponent::_TypeUID ^ v38->m_TypeUID) & 0xFE000000) == 0
                && (UFG::CharacterAnimationComponent::_TypeUID & ~v38->m_TypeUID & 0x1FFFFFF) == 0 )
              {
                goto LABEL_99;
              }
              goto LABEL_81;
            }
            if ( v37 < 0 )
            {
              v38 = pTarget->m_Components.p[9].m_pComponent;
              if ( v38 && ((UFG::CharacterAnimationComponent::_TypeUID ^ v38->m_TypeUID) & 0xFE000000) == 0 )
              {
                if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v38->m_TypeUID & 0x1FFFFFF) != 0 )
                  v38 = 0i64;
                goto LABEL_99;
              }
              goto LABEL_81;
            }
            if ( (v37 & 0x2000) != 0 )
            {
              v39 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pTarget);
            }
            else
            {
              if ( (v37 & 0x1000) != 0 )
              {
                v40 = pTarget->mComponentTableEntryCount;
                v41 = pTarget->m_Components.size;
                if ( v40 < v41 )
                {
                  v42 = pTarget->m_Components.p;
                  while ( 1 )
                  {
                    v43 = &v42[v40];
                    if ( (v43->m_TypeUID & 0xFE000000) == (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                      && (UFG::CharacterAnimationComponent::_TypeUID & ~v43->m_TypeUID & 0x1FFFFFF) == 0 )
                    {
                      break;
                    }
                    if ( ++v40 >= v41 )
                      goto LABEL_81;
                  }
                  v38 = v43->m_pComponent;
                  goto LABEL_99;
                }
LABEL_81:
                v38 = 0i64;
                goto LABEL_99;
              }
              v39 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                          pTarget,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
            v38 = v39;
LABEL_99:
            if ( v38 )
              v44 = *(Creature **)&v38[2].m_TypeUID;
            else
              v44 = 0i64;
            if ( v44 )
            {
              if ( v44->mPose.mRigHandle.mData )
              {
                BoneID = Skeleton::GetBoneID(v44->mPose.mRigHandle.mUFGSkeleton, targetAttachJoint->mUID);
                if ( BoneID >= 0 )
                {
                  Creature::GetTransform(v44, BoneID, &transform);
                  x = source.z;
                  y = v118;
                  z = transform.v0.x;
                }
              }
            }
LABEL_106:
            v46 = fsqrt(
                    (float)((float)((float)(x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                  * (float)(x - m_pTransformNodeComponent->mWorldTransform.v3.x))
                          + (float)((float)(y - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                  * (float)(y - m_pTransformNodeComponent->mWorldTransform.v3.y)))
                  + (float)((float)(z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                          * (float)(z - m_pTransformNodeComponent->mWorldTransform.v3.z)));
            if ( v122 < 0.0 || v46 <= v122 )
              goto LABEL_229;
LABEL_139:
            v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
            goto LABEL_140;
          }
          v47 = pTarget->m_Flags;
          if ( (v47 & 0x4000) != 0 )
          {
            v48 = pTarget->mComponentTableEntryCount;
            v49 = pTarget->m_Components.size;
            if ( v48 < v49 )
            {
              while ( 1 )
              {
                v50 = &pTarget->m_Components.p[v48];
                if ( (v50->m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                  && (UFG::RigidBodyComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  break;
                }
                if ( ++v48 >= v49 )
                  goto LABEL_116;
              }
LABEL_115:
              v51 = (UFG::RigidBody *)v50->m_pComponent;
LABEL_136:
              if ( !v51 )
                goto LABEL_140;
              UFG::RigidBody::GetTransform(v51, &transform);
              x = source.z;
              y = v118;
              v58 = (__m128)LODWORD(v118);
              v58.m128_f32[0] = (float)((float)((float)(v118 - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                              * (float)(v118 - m_pTransformNodeComponent->mWorldTransform.v3.y))
                                      + (float)((float)(source.z - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                              * (float)(source.z - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                              + (float)((float)(transform.v0.x - m_pTransformNodeComponent->mWorldTransform.v3.z)
                                      * (float)(transform.v0.x - m_pTransformNodeComponent->mWorldTransform.v3.z));
              LODWORD(v59) = _mm_sqrt_ps(v58).m128_u32[0];
              if ( v122 < 0.0 || v59 <= v122 )
                goto LABEL_229;
              goto LABEL_139;
            }
          }
          else if ( v47 >= 0 )
          {
            if ( (v47 & 0x2000) != 0 )
            {
              v54 = pTarget->mComponentTableEntryCount;
              v55 = pTarget->m_Components.size;
              if ( v54 < v55 )
              {
                do
                {
                  v50 = &pTarget->m_Components.p[v54];
                  if ( (v50->m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                    && (UFG::RigidBodyComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    goto LABEL_115;
                  }
                }
                while ( ++v54 < v55 );
              }
            }
            else
            {
              if ( (v47 & 0x1000) == 0 )
              {
                v51 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(pTarget, UFG::RigidBodyComponent::_TypeUID);
                v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                goto LABEL_136;
              }
              v56 = pTarget->mComponentTableEntryCount;
              v57 = pTarget->m_Components.size;
              if ( v56 < v57 )
              {
                do
                {
                  v50 = &pTarget->m_Components.p[v56];
                  if ( (v50->m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                    && (UFG::RigidBodyComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    goto LABEL_115;
                  }
                }
                while ( ++v56 < v57 );
              }
            }
          }
          else
          {
            v52 = pTarget->mComponentTableEntryCount;
            v53 = pTarget->m_Components.size;
            if ( v52 < v53 )
            {
              do
              {
                v50 = &pTarget->m_Components.p[v52];
                if ( (v50->m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                  && (UFG::RigidBodyComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_115;
                }
              }
              while ( ++v52 < v53 );
            }
          }
LABEL_116:
          v51 = 0i64;
          goto LABEL_136;
        }
        v32 = pMe->mComponentTableEntryCount;
        v33 = pMe->m_Components.size;
        if ( v32 < v33 )
        {
          do
          {
            v29 = &pMe->m_Components.p[v32];
            if ( (v29->m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
              && (UFG::AimingBaseComponent::_TypeUID & ~v29->m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_56;
            }
          }
          while ( ++v32 < v33 );
        }
      }
    }
    else
    {
      v27 = pMe->mComponentTableEntryCount;
      v28 = pMe->m_Components.size;
      if ( v27 < v28 )
      {
        while ( 1 )
        {
          v29 = &pMe->m_Components.p[v27];
          if ( (v29->m_TypeUID & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
            && (UFG::AimingBaseComponent::_TypeUID & ~v29->m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v27 >= v28 )
            goto LABEL_57;
        }
LABEL_56:
        v14 = (UFG::AimingBaseComponent *)v29->m_pComponent;
        goto LABEL_71;
      }
    }
LABEL_57:
    v14 = 0i64;
    goto LABEL_71;
  }
  x = *v126;
  y = v126[1];
LABEL_229:
  v34 = 0;
LABEL_230:
  v91 = y - m_pTransformNodeComponent->mWorldTransform.v3.y;
  v92 = x - m_pTransformNodeComponent->mWorldTransform.v3.x;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v93 = m_pTransformNodeComponent->mWorldTransform.v0.y;
  v94 = m_pTransformNodeComponent->mWorldTransform.v0.z;
  dest.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  dest.y = v93;
  dest.z = v94;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v95 = m_pTransformNodeComponent->mWorldTransform.v1.x;
  v96 = m_pTransformNodeComponent->mWorldTransform.v1.y;
  v115.x = v95;
  v115.y = v96;
  v97 = 0.0;
  dest.z = 0.0;
  v98 = 0.0;
  v115.z = 0.0;
  v99 = radians;
  *(float *)&v100 = radians;
  if ( radians < 0.0 )
    v100 = LODWORD(radians) ^ _xmm[0];
  if ( *(float *)&v100 >= 0.001 )
  {
    source.x = dest.x;
    source.y = dest.y;
    source.z = 0.0;
    v116.m_vec.m_quad.m128_f32[0] = v95;
    *(unsigned __int64 *)((char *)v116.m_vec.m_quad.m128_u64 + 4) = LODWORD(v96);
    UFG::qRotateVectorZ(&dest, &source, radians);
    UFG::qRotateVectorZ(&v115, (UFG::qVector3 *)&v116, v99);
    v97 = dest.z;
    v98 = v115.z;
    v96 = v115.y;
    v95 = v115.x;
  }
  v101 = (float)(v92 * v92) + (float)(v91 * v91);
  v102 = *(float *)&FLOAT_1_0;
  if ( v101 == 0.0 )
    v103 = 0.0;
  else
    v103 = 1.0 / fsqrt(v101);
  y_low = (__m128)LODWORD(dest.y);
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(dest.x * dest.x))
                    + (float)(v97 * v97);
  v105 = 0.0;
  if ( y_low.m128_f32[0] != 0.0 )
    v105 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
  v106 = (float)((float)((float)(dest.x * v105) * (float)(v92 * v103))
               + (float)((float)(v103 * v91) * (float)(dest.y * v105)))
       + (float)((float)(v103 * 0.0) * (float)(v105 * v97));
  if ( v106 <= -1.0 )
  {
    v106 = FLOAT_N1_0;
  }
  else if ( v106 >= 1.0 )
  {
    goto LABEL_244;
  }
  v102 = v106;
LABEL_244:
  v107 = acosf(v102);
  if ( v107 <= 0.0 )
    v107 = 0.0;
  if ( v107 >= v121 )
    v107 = v121;
  if ( (float)((float)((float)(v95 * v92) + (float)(v96 * v91)) + (float)(v98 * 0.0)) < 0.0 )
    LODWORD(v107) ^= _xmm[0];
  mCreature = v120->mCreature;
  if ( mCreature )
  {
    if ( (_S46 & 1) == 0 )
    {
      _S46 |= 1u;
      UP.m_quad = _xmm;
    }
    hkQuaternionf::setAxisAngle(&v116, &UP, v107);
    Creature::GetPositionhkQ(mCreature, (hkQsTransformf *)&transform);
    v109 = _mm_shuffle_ps((__m128)transform.v1, (__m128)transform.v1, 255);
    v110 = _mm_shuffle_ps(v116.m_vec.m_quad, v116.m_vec.m_quad, 255);
    v111 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v116.m_vec.m_quad, v116.m_vec.m_quad, 201), (__m128)transform.v1),
             _mm_mul_ps(_mm_shuffle_ps((__m128)transform.v1, (__m128)transform.v1, 201), v116.m_vec.m_quad));
    v112 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v111, v111, 201), _mm_mul_ps(v116.m_vec.m_quad, v109)),
             _mm_mul_ps((__m128)transform.v1, v110));
    v113 = _mm_mul_ps(v116.m_vec.m_quad, (__m128)transform.v1);
    transform.v1 = (UFG::qVector4)_mm_shuffle_ps(
                                    v112,
                                    _mm_unpackhi_ps(
                                      v112,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v110, v109),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
                                          _mm_shuffle_ps(v113, v113, 170)))),
                                    196);
    Creature::SetPositionhkQ(mCreature, (hkQsTransformf *)&transform);
  }
  if ( v34 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::qTranspose(&transform, &m_pTransformNodeComponent->mWorldTransform);
    UFG::AimingBaseComponent::UpdateLocalAimDirection(v14, &transform, &v14->m_vAimPosition);
  }
}

