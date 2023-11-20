// File Line: 51
// RVA: 0x569950
UFG::SimObject *__fastcall UFG::getTarget(UFG::SimObject *pSimObject, UFG::TargetingSystemBaseComponent *pTSBC, UFG::eTargetTypeEnum eTargetType)
{
  __int64 v3; // rsi
  UFG::TargetingSystemBaseComponent *v4; // rdi
  UFG::SimObject *v5; // rbx
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  unsigned int v9; // er8
  unsigned int v10; // er9
  signed __int64 v11; // rdx
  unsigned int v12; // er8
  unsigned int v13; // er9

  v3 = (unsigned int)eTargetType;
  v4 = pTSBC;
  v5 = pSimObject;
  if ( pTSBC && ((__int64 (__fastcall *)(UFG::TargetingSystemBaseComponent *))pTSBC->vfptr[15].__vecDelDtor)(pTSBC) )
    return v4->m_pTargets[(unsigned __int8)v4->m_pTargetingMap->m_Map.p[v3]].m_pTarget.m_pPointer;
  if ( (_DWORD)v3 != 2 )
  {
    if ( v4 )
      return v4->m_pTargets[(unsigned __int8)v4->m_pTargetingMap->m_Map.p[v3]].m_pTarget.m_pPointer;
    return 0i64;
  }
  if ( v5 )
  {
    v7 = v5->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v5->m_Components.p[15].m_pComponent;
      goto LABEL_26;
    }
    if ( (v7 & 0x8000u) != 0 )
    {
      v8 = v5->m_Components.p[15].m_pComponent;
      goto LABEL_26;
    }
    if ( (v7 >> 13) & 1 )
    {
      v9 = (unsigned int)v5[1].vfptr;
      v10 = v5->m_Components.size;
      if ( v9 < v10 )
      {
        v11 = (signed __int64)&v5->m_Components.p[v9];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::HitReactionComponent::_TypeUID & 0xFE000000)
             || UFG::HitReactionComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
        {
          ++v9;
          v11 += 16i64;
          if ( v9 >= v10 )
            goto LABEL_16;
        }
LABEL_17:
        v8 = *(UFG::SimComponent **)v11;
        goto LABEL_26;
      }
    }
    else
    {
      if ( !((v7 >> 12) & 1) )
      {
        v8 = UFG::SimObject::GetComponentOfType(v5, UFG::HitReactionComponent::_TypeUID);
LABEL_26:
        if ( v8 )
          return *(UFG::SimObject **)&v8[3].m_TypeUID;
        return 0i64;
      }
      v12 = (unsigned int)v5[1].vfptr;
      v13 = v5->m_Components.size;
      if ( v12 < v13 )
      {
        v11 = (signed __int64)&v5->m_Components.p[v12];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::HitReactionComponent::_TypeUID & 0xFE000000)
             || UFG::HitReactionComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
        {
          ++v12;
          v11 += 16i64;
          if ( v12 >= v13 )
          {
            v8 = 0i64;
            goto LABEL_26;
          }
        }
        goto LABEL_17;
      }
    }
LABEL_16:
    v8 = 0i64;
    goto LABEL_26;
  }
  return 0i64;
}

// File Line: 83
// RVA: 0x569B20
UFG::SimObject *__fastcall UFG::getTarget(UFG::SimObject *pSimObject, UFG::eTargetTypeEnum eTargetType)
{
  UFG::eTargetTypeEnum v2; // edi
  UFG::SimObject *v3; // rbx
  UFG::TargetingSystemBaseComponent *v5; // rax
  unsigned __int16 v6; // cx
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx
  unsigned int v10; // er8
  unsigned int v11; // er9

  v2 = eTargetType;
  v3 = pSimObject;
  if ( eTargetType == 1 )
    return pSimObject;
  if ( !pSimObject )
    goto LABEL_4;
  v6 = pSimObject->m_Flags;
  if ( (v6 >> 14) & 1 || (v6 & 0x8000u) != 0 )
  {
    v5 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    return UFG::getTarget(v3, v5, v2);
  }
  if ( !((v6 >> 13) & 1) )
  {
    if ( !((v6 >> 12) & 1) )
    {
      v5 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                  v3,
                                                  UFG::TargetingSystemBaseComponent::_TypeUID);
      return UFG::getTarget(v3, v5, v2);
    }
    v10 = (unsigned int)v3[1].vfptr;
    v11 = v3->m_Components.size;
    if ( v10 >= v11 )
      goto LABEL_4;
    v9 = (signed __int64)&v3->m_Components.p[v10];
    while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
         || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
    {
      ++v10;
      v9 += 16i64;
      if ( v10 >= v11 )
      {
        v5 = 0i64;
        return UFG::getTarget(v3, v5, v2);
      }
    }
LABEL_15:
    v5 = *(UFG::TargetingSystemBaseComponent **)v9;
    return UFG::getTarget(v3, v5, v2);
  }
  v7 = (unsigned int)v3[1].vfptr;
  v8 = v3->m_Components.size;
  if ( v7 < v8 )
  {
    v9 = (signed __int64)&v3->m_Components.p[v7];
    while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
         || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
    {
      ++v7;
      v9 += 16i64;
      if ( v7 >= v8 )
      {
        v5 = 0i64;
        return UFG::getTarget(v3, v5, v2);
      }
    }
    goto LABEL_15;
  }
LABEL_4:
  v5 = 0i64;
  return UFG::getTarget(v3, v5, v2);
}

// File Line: 96
// RVA: 0x569C80
UFG::SimObject *__fastcall UFG::getTarget(ActionContext *pContext, UFG::eTargetTypeEnum eTargetType)
{
  return UFG::getTarget(pContext->mSimObject.m_pPointer, eTargetType);
}

// File Line: 109
// RVA: 0x565C10
__int64 __fastcall UFG::closestJointID(Creature *creature, int jointLimit, UFG::qVector4 *position, UFG::qVector4 *vBoneOut)
{
  unsigned int v4; // ebp
  float v5; // xmm8_4
  UFG::qVector4 *v6; // rdi
  int v7; // esi
  UFG::qVector4 *v8; // r14
  Creature *v9; // r15
  int v10; // ebx
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-88h]

  v4 = 0;
  v5 = FLOAT_3_4028235e38;
  v6 = vBoneOut;
  v7 = creature->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton->m_bones.m_size;
  v8 = position;
  v9 = creature;
  v10 = 0;
  if ( jointLimit < v7 )
    v7 = jointLimit;
  if ( v7 > 0 )
  {
    do
    {
      Creature::GetTransform(v9, v10, &transform);
      v11 = transform.v3.y;
      v12 = transform.v3.z;
      v13 = transform.v3.w;
      v14 = (float)((float)((float)((float)(transform.v3.y - v8->y) * (float)(transform.v3.y - v8->y))
                          + (float)((float)(transform.v3.x - v8->x) * (float)(transform.v3.x - v8->x)))
                  + (float)((float)(transform.v3.z - v8->z) * (float)(transform.v3.z - v8->z)))
          + (float)((float)(transform.v3.w - v8->w) * (float)(transform.v3.w - v8->w));
      if ( v14 < v5 )
      {
        v6->x = transform.v3.x;
        v6->y = v11;
        v6->z = v12;
        v5 = v14;
        v4 = v10;
        v6->w = v13;
      }
      ++v10;
    }
    while ( v10 < v7 );
  }
  return v4;
}

// File Line: 152
// RVA: 0x553240
bool __fastcall UFG::TargetAttach(UFG::SimObject *simObject, UFG::eTargetTypeEnum targetType, UFG::SimObject *pOverrideTarget, UFG::SimObject **ppOutSimObjectTarget, UFG::qSymbolUC *attachJoint, UFG::qSymbolUC *targetAttachJoint, float blendInTime, bool attachRelative, float attachRelativeMaxDistance, bool attachToTarget, bool addToInventory, bool assignTarget, UFG::eTargetTypeEnum assignmentTargetType, bool lockTarget, bool positionOnly, bool positionXYOnly, bool *managePowerLevel)
{
  UFG::SimObject **v17; // r14
  UFG::SimObjectProp *v18; // rsi
  __int64 v19; // r12
  UFG::SimObjectProp *v20; // rdi
  unsigned __int16 v21; // cx
  UFG::CharacterAnimationComponent *v22; // rcx
  unsigned int v23; // edx
  UFG::CharacterAnimationComponent *v24; // rax
  unsigned int v25; // er9
  unsigned int v26; // er11
  UFG::SimComponentHolder *v27; // rbx
  Creature *v28; // r13
  signed __int64 v30; // r15
  unsigned __int16 v31; // cx
  UFG::TargetingSystemBaseComponent *v32; // rax
  unsigned int v33; // er9
  unsigned int v34; // er11
  UFG::SimComponentHolder *v35; // r14
  signed __int64 v36; // r8
  unsigned int v37; // er9
  unsigned int v38; // er11
  int attachmentBoneID; // er12
  unsigned __int16 v40; // cx
  UFG::CharacterAnimationComponent *v41; // rcx
  UFG::CharacterAnimationComponent *v42; // rax
  unsigned int v43; // er9
  unsigned int v44; // er11
  UFG::SimComponentHolder *v45; // rbx
  Creature *v46; // r14
  unsigned __int16 v47; // cx
  unsigned int v48; // er8
  unsigned int v49; // er10
  signed __int64 v50; // rdx
  UFG::PowerManagementComponent *v51; // rax
  unsigned int v52; // er8
  unsigned int v53; // er10
  unsigned int v54; // er8
  unsigned int v55; // er10
  unsigned int v56; // er8
  unsigned int v57; // er10
  int v58; // eax
  UFG::qNode<Attachment,Attachment> **v59; // rax
  unsigned __int16 v60; // cx
  unsigned int v61; // er8
  unsigned int v62; // er10
  signed __int64 v63; // rdx
  unsigned int v64; // er8
  unsigned int v65; // er10
  unsigned int v66; // er8
  unsigned int v67; // er10
  UFG::TransformNodeComponent *v68; // rax
  bool useRubberBand; // r12
  UFG::SimObject *v70; // rcx
  unsigned __int16 v71; // dx
  UFG::InterestPoint *v72; // r14
  bool v73; // bl
  bool v74; // r13
  bool v75; // al
  unsigned __int16 v76; // cx
  UFG::SimComponent *v77; // rcx
  unsigned int v78; // er8
  unsigned int v79; // er10
  UFG::SimComponentHolder *v80; // rbx
  signed __int64 v81; // rdx
  unsigned int v82; // er8
  unsigned int v83; // er10
  float v84; // xmm10_4
  float v85; // xmm9_4
  __int128 v86; // xmm8
  float v87; // xmm6_4
  __m128 v88; // xmm2
  float v89; // xmm7_4
  UFG::TransformNodeComponent *v90; // rbx
  UFG::qVector4 v91; // xmm2
  UFG::qVector4 v92; // xmm1
  float v93; // xmm9_4
  float v94; // xmm10_4
  UFG::allocator::free_link *v95; // rax
  int v96; // edx
  Creature *v97; // rcx
  UFG::SimObjectCharacter *v98; // rbx
  unsigned __int16 v99; // cx
  UFG::InventoryComponent *v100; // rax
  unsigned int v101; // er8
  unsigned int v102; // er10
  UFG::SimComponentHolder *v103; // rsi
  signed __int64 v104; // rdx
  unsigned int v105; // er8
  unsigned int v106; // er10
  unsigned int v107; // er8
  unsigned int v108; // er10
  __int64 v109; // rdx
  int boneID; // [rsp+40h] [rbp-C0h]
  UFG::TargetingSystemBaseComponent *v111; // [rsp+48h] [rbp-B8h]
  UFG::qVector4 vBoneOut; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 transform; // [rsp+60h] [rbp-A0h]
  __int64 v114; // [rsp+A0h] [rbp-60h]
  UFG::qMatrix44 relativePositionWS; // [rsp+B0h] [rbp-50h]
  bool v116; // [rsp+190h] [rbp+90h]
  UFG::eTargetTypeEnum eAssignTargetFrom; // [rsp+198h] [rbp+98h]
  UFG::SimObject **v118; // [rsp+1A8h] [rbp+A8h]

  v118 = ppOutSimObjectTarget;
  eAssignTargetFrom = targetType;
  v114 = -2i64;
  v17 = ppOutSimObjectTarget;
  v18 = (UFG::SimObjectProp *)pOverrideTarget;
  v19 = targetType;
  v20 = (UFG::SimObjectProp *)simObject;
  v116 = 0;
  if ( !simObject )
    return v116;
  v21 = simObject->m_Flags;
  if ( (v21 >> 14) & 1 )
  {
    v22 = (UFG::CharacterAnimationComponent *)v20->m_Components.p[9].m_pComponent;
    v23 = UFG::CharacterAnimationComponent::_TypeUID;
    if ( !v22
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v22->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( (v21 & 0x8000u) != 0 )
  {
    v22 = (UFG::CharacterAnimationComponent *)v20->m_Components.p[9].m_pComponent;
    v23 = UFG::CharacterAnimationComponent::_TypeUID;
    if ( !v22 || (UFG::CharacterAnimationComponent::_TypeUID ^ v22->m_TypeUID) & 0xFE000000 )
      goto LABEL_6;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF )
      v22 = 0i64;
    goto LABEL_24;
  }
  if ( (v21 >> 13) & 1 )
  {
    v24 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v20);
LABEL_23:
    v23 = UFG::CharacterAnimationComponent::_TypeUID;
    v22 = v24;
    goto LABEL_24;
  }
  v23 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( !((v21 >> 12) & 1) )
  {
    v24 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v20->vfptr,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  v25 = v20->mComponentTableEntryCount;
  v26 = v20->m_Components.size;
  if ( v25 >= v26 )
  {
LABEL_6:
    v22 = 0i64;
    goto LABEL_24;
  }
  v27 = v20->m_Components.p;
  while ( (v27[v25].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~v27[v25].m_TypeUID & 0x1FFFFFF )
  {
    if ( ++v25 >= v26 )
      goto LABEL_6;
  }
  v22 = (UFG::CharacterAnimationComponent *)v27[v25].m_pComponent;
LABEL_24:
  if ( v22 )
  {
    v28 = v22->mCreature;
    if ( !v28 )
      return 0;
    v30 = 0i64;
    boneID = 0;
    if ( attachJoint->mUID != -1 )
    {
      if ( v28->mPose.mRigHandle.mData )
      {
        v30 = (unsigned int)Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, attachJoint->mUID);
        v23 = UFG::CharacterAnimationComponent::_TypeUID;
      }
      else
      {
        v30 = 0xFFFFFFFFi64;
      }
      boneID = v30;
    }
    v31 = v20->m_Flags;
    if ( (v31 >> 14) & 1 )
    {
      v32 = (UFG::TargetingSystemBaseComponent *)v20->m_Components.p[20].m_pComponent;
LABEL_54:
      v111 = v32;
      if ( !v18 )
      {
        v18 = (UFG::SimObjectProp *)UFG::getTarget((UFG::SimObject *)&v20->vfptr, v32, (UFG::eTargetTypeEnum)v19);
        v23 = UFG::CharacterAnimationComponent::_TypeUID;
        if ( !v18 )
        {
          UFG::qPrintf("WARNING: TargetAttach: Target Not Found! (%s)\n", UFG::TargetTypeEnumNames[v19]);
          if ( managePowerLevel )
            *managePowerLevel = 0;
          return v116;
        }
      }
      if ( v17 )
      {
        *v17 = (UFG::SimObject *)&v18->vfptr;
        v23 = UFG::CharacterAnimationComponent::_TypeUID;
      }
      attachmentBoneID = 0;
      v40 = v18->m_Flags;
      if ( (v40 >> 14) & 1 )
      {
        v41 = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
        if ( v41 && !((v23 ^ v41->m_TypeUID) & 0xFE000000) && !(v23 & ~v41->m_TypeUID & 0x1FFFFFF) )
          goto LABEL_80;
        goto LABEL_62;
      }
      if ( (v40 & 0x8000u) != 0 )
      {
        v41 = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
        if ( v41 && !((v23 ^ v41->m_TypeUID) & 0xFE000000) )
        {
          if ( v23 & ~v41->m_TypeUID & 0x1FFFFFF )
            v41 = 0i64;
          goto LABEL_80;
        }
        goto LABEL_62;
      }
      if ( (v40 >> 13) & 1 )
      {
        v42 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v18);
      }
      else
      {
        if ( (v40 >> 12) & 1 )
        {
          v43 = v18->mComponentTableEntryCount;
          v44 = v18->m_Components.size;
          if ( v43 < v44 )
          {
            v45 = v18->m_Components.p;
            while ( (v45[v43].m_TypeUID & 0xFE000000) != (v23 & 0xFE000000) || v23 & ~v45[v43].m_TypeUID & 0x1FFFFFF )
            {
              if ( ++v43 >= v44 )
                goto LABEL_62;
            }
            v41 = (UFG::CharacterAnimationComponent *)v45[v43].m_pComponent;
LABEL_80:
            if ( v41 )
              v46 = v41->mCreature;
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
                  v30 = (unsigned int)UFG::closestJointID(v28, 22, &relativePositionWS.v3, &vBoneOut);
                  if ( attachRelativeMaxDistance >= 0.0 )
                  {
                    v84 = vBoneOut.w - 1.0;
                    v85 = vBoneOut.z - relativePositionWS.v3.z;
                    v86 = LODWORD(vBoneOut.y);
                    *(float *)&v86 = vBoneOut.y - relativePositionWS.v3.y;
                    v87 = vBoneOut.x - relativePositionWS.v3.x;
                    v88 = (__m128)v86;
                    v88.m128_f32[0] = (float)((float)((float)(*(float *)&v86 * *(float *)&v86) + (float)(v87 * v87))
                                            + (float)(v85 * v85))
                                    + (float)(v84 * v84);
                    v89 = 1.0 - (float)(attachRelativeMaxDistance / COERCE_FLOAT(_mm_sqrt_ps(v88)));
                    v90 = v18->m_pTransformNodeComponent;
                    UFG::TransformNodeComponent::UpdateWorldTransform(v18->m_pTransformNodeComponent);
                    v91 = v90->mWorldTransform.v1;
                    v92 = v90->mWorldTransform.v2;
                    transform.v0 = v90->mWorldTransform.v0;
                    transform.v1 = v91;
                    transform.v2 = v92;
                    transform.v3 = v90->mWorldTransform.v3;
                    *(float *)&v86 = (float)(*(float *)&v86 * v89)
                                   + COERCE_FLOAT(_mm_shuffle_ps((__m128)transform.v3, (__m128)transform.v3, 85));
                    v93 = (float)(v85 * v89)
                        + COERCE_FLOAT(_mm_shuffle_ps((__m128)transform.v3, (__m128)transform.v3, 170));
                    v94 = (float)(v84 * v89) + v90->mWorldTransform.v3.w;
                    transform.v3.x = transform.v3.x + (float)(v87 * v89);
                    LODWORD(transform.v3.y) = v86;
                    transform.v3.z = v93;
                    transform.v3.w = v94;
                    v95 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                    if ( v95 )
                      UFG::TeleportEvent::TeleportEvent(
                        (UFG::TeleportEvent *)v95,
                        &transform,
                        v18->mNode.mUID,
                        0,
                        UFG::TeleportEvent::m_Name,
                        0);
                    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v95);
                  }
                  v96 = attachmentBoneID;
                  v97 = v46;
                }
                else
                {
                  v96 = v30;
                  v97 = v28;
                }
                Creature::GetTransform(v97, v96, &relativePositionWS);
                v59 = Creature::AddAttachmentRelative(
                        v28,
                        (UFG::SimObject *)&v20->vfptr,
                        v30,
                        (UFG::SimObject *)&v18->vfptr,
                        attachmentBoneID,
                        &relativePositionWS,
                        blendInTime);
              }
              else
              {
                v59 = Creature::AddAttachment(
                        v28,
                        (UFG::SimObject *)&v20->vfptr,
                        v30,
                        (UFG::SimObject *)&v18->vfptr,
                        attachmentBoneID,
                        positionOnly,
                        blendInTime);
              }
              goto LABEL_207;
            }
            v30 = (signed __int64)managePowerLevel;
            if ( !managePowerLevel || !*managePowerLevel )
            {
LABEL_121:
              if ( v46 )
              {
                if ( attachRelative )
                {
                  Creature::GetTransform(v28, boneID, &transform);
                  v58 = UFG::closestJointID(v46, 22, &transform.v3, &vBoneOut);
                  v59 = Creature::AddAttachmentRelative(
                          v46,
                          (UFG::SimObject *)&v18->vfptr,
                          v58,
                          (UFG::SimObject *)&v20->vfptr,
                          boneID,
                          &transform,
                          blendInTime);
                }
                else
                {
                  v59 = Creature::AddAttachment(
                          v46,
                          (UFG::SimObject *)&v18->vfptr,
                          attachmentBoneID,
                          (UFG::SimObject *)&v20->vfptr,
                          boneID,
                          positionOnly,
                          blendInTime);
                }
LABEL_207:
                v116 = v59 != 0i64;
                if ( v59 )
                  *((_BYTE *)v59 + 25) = positionXYOnly;
LABEL_209:
                if ( attachToTarget )
                {
                  v98 = (UFG::SimObjectCharacter *)v18;
                }
                else
                {
                  v98 = (UFG::SimObjectCharacter *)v20;
                  v20 = v18;
                }
                if ( !v98 )
                {
LABEL_242:
                  if ( v98 == LocalPlayer && assignmentTargetType == 17 )
                    UFG::GameStatAction::Inventory::Equip((UFG::SimObject *)&v20->vfptr);
                  if ( v111 )
                  {
                    if ( assignTarget )
                    {
                      UFG::TargetingSystemBaseComponent::AssignTarget(v111, assignmentTargetType, eAssignTargetFrom);
                      v109 = (unsigned int)assignmentTargetType;
                    }
                    else
                    {
                      v109 = (unsigned int)eAssignTargetFrom;
                    }
                    if ( lockTarget )
                      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, signed __int64))v111->vfptr[14].__vecDelDtor)(
                        v111,
                        v109,
                        1i64);
                  }
                  return v116;
                }
                v99 = v98->m_Flags;
                if ( (v99 >> 14) & 1 )
                {
                  v100 = (UFG::InventoryComponent *)v98->m_Components.p[39].m_pComponent;
LABEL_239:
                  if ( v100 && addToInventory )
                    UFG::InventoryComponent::AddObjectToInventory(v100, (UFG::SimObject *)&v20->vfptr, 1, v30);
                  goto LABEL_242;
                }
                if ( (v99 & 0x8000u) == 0 )
                {
                  if ( (v99 >> 13) & 1 )
                  {
                    v105 = v98->mComponentTableEntryCount;
                    v106 = v98->m_Components.size;
                    if ( v105 < v106 )
                    {
                      v103 = v98->m_Components.p;
                      do
                      {
                        v104 = v105;
                        if ( (v103[v105].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                          && !(UFG::InventoryComponent::_TypeUID & ~v103[v105].m_TypeUID & 0x1FFFFFF) )
                        {
                          goto LABEL_222;
                        }
                      }
                      while ( ++v105 < v106 );
                    }
                  }
                  else
                  {
                    if ( !((v99 >> 12) & 1) )
                    {
                      v100 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v98->vfptr,
                                                          UFG::InventoryComponent::_TypeUID);
                      goto LABEL_239;
                    }
                    v107 = v98->mComponentTableEntryCount;
                    v108 = v98->m_Components.size;
                    if ( v107 < v108 )
                    {
                      v103 = v98->m_Components.p;
                      do
                      {
                        v104 = v107;
                        if ( (v103[v107].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                          && !(UFG::InventoryComponent::_TypeUID & ~v103[v107].m_TypeUID & 0x1FFFFFF) )
                        {
                          goto LABEL_222;
                        }
                      }
                      while ( ++v107 < v108 );
                    }
                  }
                }
                else
                {
                  v101 = v98->mComponentTableEntryCount;
                  v102 = v98->m_Components.size;
                  if ( v101 < v102 )
                  {
                    v103 = v98->m_Components.p;
                    while ( 1 )
                    {
                      v104 = v101;
                      if ( (v103[v101].m_TypeUID & 0xFE000000) == (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                        && !(UFG::InventoryComponent::_TypeUID & ~v103[v101].m_TypeUID & 0x1FFFFFF) )
                      {
                        break;
                      }
                      if ( ++v101 >= v102 )
                        goto LABEL_223;
                    }
LABEL_222:
                    v100 = (UFG::InventoryComponent *)v103[v104].m_pComponent;
                    goto LABEL_239;
                  }
                }
LABEL_223:
                v100 = 0i64;
                goto LABEL_239;
              }
              v60 = v20->m_Flags;
              if ( (v60 >> 14) & 1 )
              {
                v30 = (signed __int64)v20->m_Components.p[28].m_pComponent;
LABEL_148:
                v68 = v18->m_pTransformNodeComponent;
                *(_QWORD *)&vBoneOut.x = v18->m_pTransformNodeComponent;
                if ( !v30 || !v68 )
                  goto LABEL_209;
                useRubberBand = 0;
                if ( !v118 )
                  goto LABEL_194;
                v70 = *v118;
                if ( !*v118 )
                  goto LABEL_194;
                v71 = v70->m_Flags;
                if ( (v71 >> 14) & 1 )
                {
                  v72 = (UFG::InterestPoint *)v70->m_Components.p[25].m_pComponent;
                }
                else if ( (v71 & 0x8000u) == 0 )
                {
                  if ( (v71 >> 13) & 1 )
                    v72 = (UFG::InterestPoint *)v70->m_Components.p[10].m_pComponent;
                  else
                    v72 = (UFG::InterestPoint *)((v71 >> 12) & 1 ? v70->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(v70, UFG::InterestPoint::_TypeUID));
                }
                else
                {
                  v72 = (UFG::InterestPoint *)v70->m_Components.p[25].m_pComponent;
                }
                if ( !v72 )
                  goto LABEL_194;
                v73 = UFG::InterestPoint::GetPositionSyncRequired(v72);
                v74 = UFG::InterestPoint::GetRotationSyncRequired(v72);
                v75 = UFG::InterestPoint::GetRequiresSync(v72);
                if ( (!v73 || !v74) && !v75 )
                  goto LABEL_194;
                v76 = v20->m_Flags;
                if ( (v76 >> 14) & 1 )
                {
                  v77 = v20->m_Components.p[3].m_pComponent;
                  if ( v77
                    && !((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v77->m_TypeUID) & 0xFE000000)
                    && !(UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v77->m_TypeUID & 0x1FFFFFF) )
                  {
LABEL_191:
                    if ( v77 )
                    {
                      useRubberBand = 0;
                      if ( LODWORD(v77[3].vfptr) == 4 )
                        useRubberBand = 1;
                    }
LABEL_194:
                    UFG::WorldContextComponent::AttachTo(
                      (UFG::WorldContextComponent *)v30,
                      (UFG::SimObject *)&v18->vfptr,
                      *(UFG::TransformNodeComponent **)&vBoneOut.x,
                      boneID,
                      blendInTime,
                      positionOnly,
                      positionXYOnly,
                      useRubberBand);
                    v116 = 1;
                    goto LABEL_209;
                  }
LABEL_169:
                  v77 = 0i64;
                  goto LABEL_191;
                }
                if ( (v76 & 0x8000u) != 0 )
                {
                  v77 = v20->m_Components.p[3].m_pComponent;
                  if ( v77 && !((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v77->m_TypeUID) & 0xFE000000) )
                  {
                    if ( UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v77->m_TypeUID & 0x1FFFFFF )
                      v77 = 0i64;
                    goto LABEL_191;
                  }
                  goto LABEL_169;
                }
                if ( (v76 >> 13) & 1 )
                {
                  v78 = v20->mComponentTableEntryCount;
                  v79 = v20->m_Components.size;
                  if ( v78 >= v79 )
                    goto LABEL_169;
                  v80 = v20->m_Components.p;
                  while ( 1 )
                  {
                    v81 = v78;
                    if ( (v80[v78].m_TypeUID & 0xFE000000) == (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
                      && !(UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v80[v78].m_TypeUID & 0x1FFFFFF) )
                    {
                      break;
                    }
                    if ( ++v78 >= v79 )
                      goto LABEL_169;
                  }
                }
                else
                {
                  if ( !((v76 >> 12) & 1) )
                  {
                    v77 = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v20->vfptr,
                            UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                    goto LABEL_191;
                  }
                  v82 = v20->mComponentTableEntryCount;
                  v83 = v20->m_Components.size;
                  if ( v82 >= v83 )
                    goto LABEL_169;
                  v80 = v20->m_Components.p;
                  while ( 1 )
                  {
                    v81 = v82;
                    if ( (v80[v82].m_TypeUID & 0xFE000000) == (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
                      && !(UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v80[v82].m_TypeUID & 0x1FFFFFF) )
                    {
                      break;
                    }
                    if ( ++v82 >= v83 )
                      goto LABEL_169;
                  }
                }
                v77 = v80[v81].m_pComponent;
                goto LABEL_191;
              }
              if ( (v60 & 0x8000u) == 0 )
              {
                if ( (v60 >> 13) & 1 )
                {
                  v64 = v20->mComponentTableEntryCount;
                  v65 = v20->m_Components.size;
                  if ( v64 < v65 )
                  {
                    do
                    {
                      v63 = (signed __int64)&v20->m_Components.p[v64];
                      if ( (*(_DWORD *)(v63 + 8) & 0xFE000000) == (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                        && !(UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v63 + 8) & 0x1FFFFFF) )
                      {
                        goto LABEL_133;
                      }
                    }
                    while ( ++v64 < v65 );
                  }
                }
                else
                {
                  if ( !((v60 >> 12) & 1) )
                  {
                    v30 = (signed __int64)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v20->vfptr,
                                            UFG::WorldContextComponent::_TypeUID);
                    goto LABEL_148;
                  }
                  v66 = v20->mComponentTableEntryCount;
                  v67 = v20->m_Components.size;
                  if ( v66 < v67 )
                  {
                    do
                    {
                      v63 = (signed __int64)&v20->m_Components.p[v66];
                      if ( (*(_DWORD *)(v63 + 8) & 0xFE000000) == (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                        && !(UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v63 + 8) & 0x1FFFFFF) )
                      {
                        goto LABEL_133;
                      }
                    }
                    while ( ++v66 < v67 );
                  }
                }
              }
              else
              {
                v61 = v20->mComponentTableEntryCount;
                v62 = v20->m_Components.size;
                if ( v61 < v62 )
                {
                  while ( 1 )
                  {
                    v63 = (signed __int64)&v20->m_Components.p[v61];
                    if ( (*(_DWORD *)(v63 + 8) & 0xFE000000) == (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                      && !(UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v63 + 8) & 0x1FFFFFF) )
                    {
                      break;
                    }
                    if ( ++v61 >= v62 )
                      goto LABEL_134;
                  }
LABEL_133:
                  v30 = *(_QWORD *)v63;
                  goto LABEL_148;
                }
              }
LABEL_134:
              v30 = 0i64;
              goto LABEL_148;
            }
            v47 = v18->m_Flags;
            if ( (v47 >> 14) & 1 )
            {
              v48 = v18->mComponentTableEntryCount;
              v49 = v18->m_Components.size;
              if ( v48 < v49 )
              {
                while ( 1 )
                {
                  v50 = (signed __int64)&v18->m_Components.p[v48];
                  if ( (*(_DWORD *)(v50 + 8) & 0xFE000000) == (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                    && !(UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) )
                  {
                    break;
                  }
                  if ( ++v48 >= v49 )
                    goto LABEL_98;
                }
LABEL_97:
                v51 = *(UFG::PowerManagementComponent **)v50;
                goto LABEL_118;
              }
            }
            else if ( (v47 & 0x8000u) == 0 )
            {
              if ( (v47 >> 13) & 1 )
              {
                v54 = v18->mComponentTableEntryCount;
                v55 = v18->m_Components.size;
                if ( v54 < v55 )
                {
                  do
                  {
                    v50 = (signed __int64)&v18->m_Components.p[v54];
                    if ( (*(_DWORD *)(v50 + 8) & 0xFE000000) == (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                      && !(UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) )
                    {
                      goto LABEL_97;
                    }
                  }
                  while ( ++v54 < v55 );
                }
              }
              else
              {
                if ( !((v47 >> 12) & 1) )
                {
                  v51 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)&v18->vfptr,
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
                v56 = v18->mComponentTableEntryCount;
                v57 = v18->m_Components.size;
                if ( v56 < v57 )
                {
                  do
                  {
                    v50 = (signed __int64)&v18->m_Components.p[v56];
                    if ( (*(_DWORD *)(v50 + 8) & 0xFE000000) == (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                      && !(UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) )
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
              v52 = v18->mComponentTableEntryCount;
              v53 = v18->m_Components.size;
              if ( v52 < v53 )
              {
                do
                {
                  v50 = (signed __int64)&v18->m_Components.p[v52];
                  if ( (*(_DWORD *)(v50 + 8) & 0xFE000000) == (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                    && !(UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) )
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
        v42 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v18->vfptr, v23);
      }
      v41 = v42;
      goto LABEL_80;
    }
    if ( (v31 & 0x8000u) != 0 )
    {
      v32 = (UFG::TargetingSystemBaseComponent *)v20->m_Components.p[20].m_pComponent;
      goto LABEL_54;
    }
    if ( (v31 >> 13) & 1 )
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
            && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v35[v33].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v33 >= v34 )
            goto LABEL_44;
        }
LABEL_43:
        v32 = (UFG::TargetingSystemBaseComponent *)v35[v36].m_pComponent;
LABEL_45:
        v17 = v118;
        goto LABEL_54;
      }
    }
    else
    {
      if ( !((v31 >> 12) & 1) )
      {
        v32 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v20->vfptr,
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
            && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v35[v37].m_TypeUID & 0x1FFFFFF) )
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
  return v116;
}

// File Line: 425
// RVA: 0x5531F0
bool __fastcall UFG::TargetAttach(ActionContext *context, UFG::eTargetTypeEnum targetType, UFG::SimObject *pOverrideTarget, UFG::SimObject **ppOutSimObjectTarget, UFG::qSymbolUC *attachJoint, UFG::qSymbolUC *targetAttachJoint, float blendInTime, bool attachRelative, float attachRelativeMaxDistance, bool attachToTarget, bool addToInventory, bool assignTarget, UFG::eTargetTypeEnum assignmentTargetType, bool lockTarget, bool positionOnly, bool positionXYOnly, bool *managePowerLevel)
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
__int64 __fastcall UFG::TargetDetach(UFG::SimObject *simObject, UFG::eTargetTypeEnum targetType, UFG::SimObject *pOverrideTarget, UFG::qSymbolUC *attachJoint, UFG::qSymbolUC *targetAttachJoint, float blendOutTime, bool detachFromTarget, bool removeFromInventory, bool deleteOnDetach, bool releaseTarget, bool makeUpright, bool fadeAwayOnDetach, float disableCollisionDelay, float clampVelocity, bool managePowerLevel)
{
  unsigned __int8 v15; // bp
  UFG::qSymbolUC *v16; // rbx
  UFG::SimObjectProp *v17; // rdi
  UFG::eTargetTypeEnum v18; // er14
  UFG::SimObject *v19; // r13
  unsigned __int16 v20; // r10
  __int64 v21; // r9
  UFG::SimComponent *v22; // rcx
  UFG::CharacterAnimationComponent *v23; // rax
  unsigned int v24; // er8
  unsigned int v25; // er10
  UFG::SimComponentHolder *v26; // rdx
  Creature *v27; // r12
  signed __int64 v28; // rdx
  int v29; // esi
  int v30; // eax
  UFG::TargetingSystemBaseComponent *v31; // rax
  unsigned __int16 v32; // cx
  unsigned int v33; // er8
  unsigned int v34; // er10
  unsigned int v35; // er8
  unsigned int v36; // er10
  UFG::SimObject *v37; // rax
  UFG::TransformNodeComponent *i; // rax
  UFG::SimObject *v39; // rcx
  unsigned __int16 v40; // cx
  int v41; // ebp
  UFG::CharacterAnimationComponent *v42; // rcx
  UFG::CharacterAnimationComponent *v43; // rax
  unsigned int v44; // er8
  unsigned int v45; // er10
  Creature *v46; // rbx
  unsigned __int16 v47; // cx
  unsigned int v48; // er8
  UFG::PowerManagementComponent *v49; // rax
  unsigned int v50; // er8
  unsigned int v51; // er8
  unsigned int v52; // er8
  UFG::SimObjectCharacter *v53; // r14
  __int64 v54; // r15
  __int64 v55; // r8
  UFG::WorldContextComponent *v56; // rax
  unsigned __int16 v57; // cx
  unsigned int v58; // er8
  unsigned int v59; // er8
  unsigned int v60; // er8
  Creature *v61; // rcx
  unsigned __int16 v62; // cx
  UFG::InventoryComponent *v63; // rax
  signed __int64 v64; // rdx
  UFG::GameStatTracker *v65; // rax
  unsigned int v66; // ebx
  UFG::SceneObjectProperties *v67; // rcx
  UFG::qResourceData *v68; // rax
  unsigned __int16 v69; // cx
  signed __int64 v70; // rdx
  UFG::PropInteractComponent *v71; // rax
  signed __int64 v72; // rcx
  float v73; // xmm7_4
  float v74; // xmm6_4
  unsigned __int16 v75; // cx
  UFG::SimComponent *v76; // rax
  unsigned int v77; // er8
  signed __int64 v78; // rdx
  unsigned __int16 v79; // cx
  unsigned int v80; // edx
  unsigned int v81; // er8
  signed __int64 v82; // rbx
  UFG::RigidBody *v83; // rbx
  unsigned int v84; // edx
  unsigned int v85; // er8
  unsigned int v86; // edx
  unsigned int v87; // er8
  unsigned int v88; // edx
  unsigned int v89; // er8
  __m128 v90; // xmm2
  float v91; // xmm0_4
  __m128 v92; // xmm2
  UFG::qVector3 result; // [rsp+40h] [rbp-88h]
  UFG::qVector3 vel; // [rsp+50h] [rbp-78h]
  UFG::qVector3 v96; // [rsp+60h] [rbp-68h]
  UFG::TargetingSystemBaseComponent *v97; // [rsp+D0h] [rbp+8h]
  UFG::eTargetTypeEnum v98; // [rsp+D8h] [rbp+10h]
  UFG::SimObject *v99; // [rsp+E0h] [rbp+18h]

  v99 = pOverrideTarget;
  v98 = targetType;
  v15 = 0;
  v16 = attachJoint;
  v17 = (UFG::SimObjectProp *)pOverrideTarget;
  v18 = targetType;
  v19 = simObject;
  if ( !simObject )
  {
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    goto LABEL_23;
  }
  v20 = simObject->m_Flags;
  if ( (v20 >> 14) & 1 || (v20 & 0x8000u) != 0 )
  {
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    v22 = simObject->m_Components.p[9].m_pComponent;
    if ( v22
      && !(((unsigned int)v21 ^ v22->m_TypeUID) & 0xFE000000)
      && !((unsigned int)v21 & ~v22->m_TypeUID & 0x1FFFFFF) )
    {
      goto LABEL_20;
    }
LABEL_6:
    v22 = 0i64;
    goto LABEL_20;
  }
  if ( (v20 >> 13) & 1 )
  {
    v23 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)simObject);
LABEL_19:
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    v22 = (UFG::SimComponent *)&v23->vfptr;
    goto LABEL_20;
  }
  if ( !((v20 >> 12) & 1) )
  {
    v23 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                simObject,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_19;
  }
  v24 = (unsigned int)simObject[1].vfptr;
  v25 = simObject->m_Components.size;
  v21 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( v24 >= v25 )
    goto LABEL_6;
  v26 = &simObject->m_Components.p[v24];
  while ( (v26->m_TypeUID & 0xFE000000) != (v21 & 0xFE000000) || (unsigned int)v21 & ~v26->m_TypeUID & 0x1FFFFFF )
  {
    ++v24;
    ++v26;
    if ( v24 >= v25 )
    {
      v22 = 0i64;
      goto LABEL_20;
    }
  }
  v22 = v26->m_pComponent;
LABEL_20:
  if ( v22 )
  {
    v27 = *(Creature **)&v22[2].m_TypeUID;
    goto LABEL_24;
  }
LABEL_23:
  v27 = 0i64;
LABEL_24:
  if ( !v27 )
    return v15;
  v28 = v16->mUID;
  v29 = 0;
  if ( (_DWORD)v28 != -1 )
  {
    if ( v27->mPose.mRigHandle.mData )
    {
      v30 = Skeleton::GetBoneID(v27->mPose.mRigHandle.mUFGSkeleton, v28);
      v21 = UFG::CharacterAnimationComponent::_TypeUID;
      v29 = v30;
    }
    else
    {
      v29 = -1;
    }
  }
  if ( !v19 )
    goto LABEL_30;
  v32 = v19->m_Flags;
  if ( (v32 >> 14) & 1 )
  {
    v31 = (UFG::TargetingSystemBaseComponent *)v19->m_Components.p[20].m_pComponent;
    goto LABEL_51;
  }
  if ( (v32 & 0x8000u) != 0 )
  {
    v31 = (UFG::TargetingSystemBaseComponent *)v19->m_Components.p[20].m_pComponent;
    goto LABEL_51;
  }
  if ( !((v32 >> 13) & 1) )
  {
    if ( !((v32 >> 12) & 1) )
    {
      v31 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                   v19,
                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
      v21 = UFG::CharacterAnimationComponent::_TypeUID;
      goto LABEL_51;
    }
    v35 = (unsigned int)v19[1].vfptr;
    v36 = v19->m_Components.size;
    v28 = v35;
    if ( v35 >= v36 )
      goto LABEL_30;
    v28 = (signed __int64)&v19->m_Components.p[v35];
    while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
         || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
    {
      ++v35;
      v28 += 16i64;
      if ( v35 >= v36 )
      {
        v31 = 0i64;
        goto LABEL_51;
      }
    }
LABEL_42:
    v31 = *(UFG::TargetingSystemBaseComponent **)v28;
    goto LABEL_51;
  }
  v33 = (unsigned int)v19[1].vfptr;
  v34 = v19->m_Components.size;
  v28 = v33;
  if ( v33 < v34 )
  {
    v28 = (signed __int64)&v19->m_Components.p[v33];
    while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
         || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
    {
      ++v33;
      v28 += 16i64;
      if ( v33 >= v34 )
      {
        v31 = 0i64;
        goto LABEL_51;
      }
    }
    goto LABEL_42;
  }
LABEL_30:
  v31 = 0i64;
LABEL_51:
  v97 = v31;
  if ( v17
    || (v37 = UFG::getTarget(v19, v31, v18),
        v21 = UFG::CharacterAnimationComponent::_TypeUID,
        (v17 = (UFG::SimObjectProp *)v37) != 0i64) )
  {
    if ( fadeAwayOnDetach )
    {
      for ( i = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v17->vfptr,
                                                 UFG::RigidBodyComponent::_TypeUID);
            i;
            i = UFG::SimObject::GetComponentOfType(
                  v39,
                  UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                  0,
                  (UFG::SimComponent *)&i->vfptr) )
      {
        v39 = i->m_pSimObject;
        i[1].mWorldTransform.v3.z = 6.0;
      }
      v21 = UFG::CharacterAnimationComponent::_TypeUID;
    }
    v40 = v17->m_Flags;
    v41 = 0;
    if ( (v40 >> 14) & 1 )
    {
      v42 = (UFG::CharacterAnimationComponent *)v17->m_Components.p[9].m_pComponent;
      if ( v42 )
      {
        v28 = v42->m_TypeUID;
        if ( !(((unsigned int)v21 ^ v42->m_TypeUID) & 0xFE000000) )
        {
          v28 = (unsigned int)v21 & ~(_DWORD)v28;
          if ( !(v28 & 0x1FFFFFF) )
            goto LABEL_79;
        }
      }
      goto LABEL_61;
    }
    if ( (v40 & 0x8000u) != 0 )
    {
      v42 = (UFG::CharacterAnimationComponent *)v17->m_Components.p[9].m_pComponent;
      if ( v42 )
      {
        v28 = v42->m_TypeUID;
        if ( !(((unsigned int)v21 ^ v42->m_TypeUID) & 0xFE000000) )
        {
          v28 = (unsigned int)v21 & ~(_DWORD)v28;
          if ( v28 & 0x1FFFFFF )
            v42 = 0i64;
          goto LABEL_79;
        }
      }
      goto LABEL_61;
    }
    if ( (v40 >> 13) & 1 )
    {
      v43 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v17);
    }
    else
    {
      if ( (v40 >> 12) & 1 )
      {
        v44 = v17->mComponentTableEntryCount;
        v45 = v17->m_Components.size;
        v28 = v44;
        if ( v44 < v45 )
        {
          v28 = (signed __int64)&v17->m_Components.p[v44];
          while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (v21 & 0xFE000000)
               || (unsigned int)v21 & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
          {
            ++v44;
            v28 += 16i64;
            if ( v44 >= v45 )
            {
              v42 = 0i64;
              goto LABEL_79;
            }
          }
          v42 = *(UFG::CharacterAnimationComponent **)v28;
LABEL_79:
          if ( v42 )
            v46 = v42->mCreature;
          else
            v46 = 0i64;
          if ( v46 )
          {
            v28 = targetAttachJoint->mUID;
            if ( (_DWORD)v28 != -1 )
            {
              if ( v46->mPose.mRigHandle.mData )
                v41 = Skeleton::GetBoneID(v46->mPose.mRigHandle.mUFGSkeleton, v28);
              else
                v41 = -1;
            }
          }
          if ( !detachFromTarget )
          {
            v53 = (UFG::SimObjectCharacter *)v19;
            v54 = (__int64)v17;
            v15 = Creature::RemoveAttachment(v27, v19, v29, (UFG::SimObject *)&v17->vfptr);
            if ( v46 && makeUpright )
            {
              v61 = v46;
              goto LABEL_159;
            }
LABEL_160:
            if ( !removeFromInventory || !v19 )
              goto LABEL_189;
            v62 = v19->m_Flags;
            if ( (v62 >> 14) & 1 )
            {
              v63 = (UFG::InventoryComponent *)v19->m_Components.p[39].m_pComponent;
              goto LABEL_187;
            }
            if ( (v62 & 0x8000u) == 0 )
            {
              if ( (v62 >> 13) & 1 )
              {
                v55 = LODWORD(v19[1].vfptr);
                v21 = v19->m_Components.size;
                if ( (unsigned int)v55 < (unsigned int)v21 )
                {
                  v64 = (signed __int64)&v19->m_Components.p[(unsigned int)v55];
                  while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                       || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
                  {
                    v55 = (unsigned int)(v55 + 1);
                    v64 += 16i64;
                    if ( (unsigned int)v55 >= (unsigned int)v21 )
                    {
                      v63 = 0i64;
                      goto LABEL_187;
                    }
                  }
                  goto LABEL_171;
                }
              }
              else
              {
                if ( !((v62 >> 12) & 1) )
                {
                  v63 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                     v19,
                                                     UFG::InventoryComponent::_TypeUID);
LABEL_187:
                  if ( v63 )
                    UFG::InventoryComponent::RemoveObjectFromInventory(v63, (UFG::SimObject *)&v17->vfptr, v54);
LABEL_189:
                  if ( v53 == LocalPlayer )
                  {
                    v65 = UFG::GameStatTracker::Instance();
                    v66 = UFG::GameStatTracker::GetStat(v65, Equipped)->mValue.mUID;
                    if ( v66 != -1 )
                    {
                      v67 = *(UFG::SceneObjectProperties **)(v54 + 80);
                      if ( v67 )
                      {
                        v68 = UFG::SceneObjectProperties::GetArchetypeProperties(v67);
                        if ( v68 )
                        {
                          if ( v66 == *(_DWORD *)&v68->mDebugName[12] )
                            UFG::GameStatAction::Inventory::UnEquip(0);
                        }
                      }
                    }
                  }
                  v69 = v17->m_Flags;
                  if ( (v69 >> 14) & 1 )
                  {
                    v55 = v17->mComponentTableEntryCount;
                    v21 = v17->m_Components.size;
                    if ( (unsigned int)v55 < (unsigned int)v21 )
                    {
                      v70 = (signed __int64)&v17->m_Components.p[(unsigned int)v55];
                      while ( (*(_DWORD *)(v70 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                           || UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v70 + 8) & 0x1FFFFFF )
                      {
                        v55 = (unsigned int)(v55 + 1);
                        v70 += 16i64;
                        if ( (unsigned int)v55 >= (unsigned int)v21 )
                          goto LABEL_201;
                      }
LABEL_202:
                      v71 = *(UFG::PropInteractComponent **)v70;
                      goto LABEL_215;
                    }
                    goto LABEL_201;
                  }
                  if ( (v69 & 0x8000u) == 0 )
                  {
                    if ( (v69 >> 13) & 1 )
                    {
                      v71 = (UFG::PropInteractComponent *)v17->m_Components.p[13].m_pComponent;
                    }
                    else
                    {
                      if ( (v69 >> 12) & 1 )
                      {
                        v55 = v17->mComponentTableEntryCount;
                        v21 = v17->m_Components.size;
                        if ( (unsigned int)v55 < (unsigned int)v21 )
                        {
                          v70 = (signed __int64)&v17->m_Components.p[(unsigned int)v55];
                          while ( (*(_DWORD *)(v70 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                               || UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v70 + 8) & 0x1FFFFFF )
                          {
                            v55 = (unsigned int)(v55 + 1);
                            v70 += 16i64;
                            if ( (unsigned int)v55 >= (unsigned int)v21 )
                            {
                              v71 = 0i64;
                              goto LABEL_215;
                            }
                          }
                          goto LABEL_202;
                        }
LABEL_201:
                        v71 = 0i64;
                        goto LABEL_215;
                      }
                      v71 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v17->vfptr,
                                                            UFG::PropInteractComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v71 = (UFG::PropInteractComponent *)v17->m_Components.p[33].m_pComponent;
                  }
LABEL_215:
                  if ( v71 )
                    UFG::PropInteractComponent::DetachFromObject(v71, v19, v55, v21);
                  if ( deleteOnDetach )
                  {
                    if ( v99 )
                    {
                      v18 = v98;
                    }
                    else
                    {
                      v18 = v98;
                      if ( (unsigned int)v98 > 0x37 || (v72 = 0x800C00001E0000i64, !_bittest64(&v72, v98)) )
                      {
                        v15 = 0;
                        goto LABEL_279;
                      }
                    }
                    UFG::SimObject::Destroy((UFG::SimObject *)&v17->vfptr);
                    goto LABEL_279;
                  }
                  v73 = clampVelocity;
                  v74 = 0.0;
                  if ( clampVelocity < 0.0 )
                    v73 = FLOAT_2_0;
                  v75 = v17->m_Flags;
                  if ( !((v75 >> 14) & 1) )
                  {
                    if ( (v75 & 0x8000u) == 0 )
                    {
                      if ( (v75 >> 13) & 1 )
                        goto LABEL_240;
                      if ( (v75 >> 12) & 1 )
                      {
                        v77 = v17->mComponentTableEntryCount;
                        v21 = v17->m_Components.size;
                        if ( v77 >= (unsigned int)v21 )
                        {
LABEL_236:
                          v76 = 0i64;
                        }
                        else
                        {
                          v78 = (signed __int64)&v17->m_Components.p[v77];
                          while ( (*(_DWORD *)(v78 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                               || UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v78 + 8) & 0x1FFFFFF )
                          {
                            ++v77;
                            v78 += 16i64;
                            if ( v77 >= (unsigned int)v21 )
                              goto LABEL_236;
                          }
                          v76 = *(UFG::SimComponent **)v78;
                        }
                      }
                      else
                      {
                        v76 = UFG::SimObject::GetComponentOfType(
                                (UFG::SimObject *)&v17->vfptr,
                                UFG::PhysicsMoverInterface::_TypeUID);
                      }
                    }
                    else
                    {
                      v76 = v17->m_Components.p[34].m_pComponent;
                    }
                    if ( v76 )
                    {
LABEL_278:
                      v18 = v98;
                      goto LABEL_279;
                    }
                  }
LABEL_240:
                  v79 = v17->m_Flags;
                  if ( (v79 >> 14) & 1 )
                  {
                    v80 = v17->mComponentTableEntryCount;
                    v81 = v17->m_Components.size;
                    if ( v80 < v81 )
                    {
                      v21 = UFG::RigidBodyComponent::_TypeUID & 0xFE000000;
                      v82 = (signed __int64)&v17->m_Components.p[v80];
                      while ( (*(_DWORD *)(v82 + 8) & 0xFE000000) != (_DWORD)v21
                           || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v82 + 8) & 0x1FFFFFF )
                      {
                        ++v80;
                        v82 += 16i64;
                        if ( v80 >= v81 )
                          goto LABEL_246;
                      }
LABEL_247:
                      v83 = *(UFG::RigidBody **)v82;
                      goto LABEL_270;
                    }
                  }
                  else if ( (v79 & 0x8000u) == 0 )
                  {
                    if ( (v79 >> 13) & 1 )
                    {
                      v86 = v17->mComponentTableEntryCount;
                      v87 = v17->m_Components.size;
                      if ( v86 < v87 )
                      {
                        v21 = UFG::RigidBodyComponent::_TypeUID & 0xFE000000;
                        v82 = (signed __int64)&v17->m_Components.p[v86];
                        while ( (*(_DWORD *)(v82 + 8) & 0xFE000000) != (_DWORD)v21
                             || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v82 + 8) & 0x1FFFFFF )
                        {
                          ++v86;
                          v82 += 16i64;
                          if ( v86 >= v87 )
                          {
                            v83 = 0i64;
                            goto LABEL_270;
                          }
                        }
                        goto LABEL_247;
                      }
                    }
                    else
                    {
                      if ( !((v79 >> 12) & 1) )
                      {
                        v83 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v17->vfptr,
                                                  UFG::RigidBodyComponent::_TypeUID);
LABEL_270:
                        if ( v83 )
                        {
                          UFG::RigidBody::GetVelocity(v83, &result);
                          v90 = (__m128)LODWORD(result.x);
                          v90.m128_f32[0] = (float)((float)(v90.m128_f32[0] * v90.m128_f32[0])
                                                  + (float)(result.y * result.y))
                                          + (float)(result.z * result.z);
                          LODWORD(v91) = (unsigned __int128)_mm_sqrt_ps(v90);
                          if ( v91 > 0.1 && v91 > v73 )
                          {
                            if ( v90.m128_f32[0] != 0.0 )
                              v74 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v90));
                            vel.x = (float)(result.x * v74) * v73;
                            vel.y = (float)(result.y * v74) * v73;
                            vel.z = (float)(result.z * v74) * v73;
                            UFG::RigidBody::SetVelocity(v83, &vel);
                          }
                          UFG::RigidBody::GetAngularVelocity(v83, &v96);
                          v92 = (__m128)LODWORD(v96.x);
                          v92.m128_f32[0] = (float)((float)(v92.m128_f32[0] * v92.m128_f32[0]) + (float)(v96.y * v96.y))
                                          + (float)(v96.z * v96.z);
                          if ( COERCE_FLOAT(_mm_sqrt_ps(v92)) > 37.699112 )
                          {
                            vel.x = v96.x * 0.2;
                            vel.y = v96.y * 0.2;
                            vel.z = v96.z * 0.2;
                            UFG::RigidBody::SetAngularVelocity(v83, &vel);
                          }
                        }
                        goto LABEL_278;
                      }
                      v88 = v17->mComponentTableEntryCount;
                      v89 = v17->m_Components.size;
                      if ( v88 < v89 )
                      {
                        v21 = UFG::RigidBodyComponent::_TypeUID & 0xFE000000;
                        v82 = (signed __int64)&v17->m_Components.p[v88];
                        while ( (*(_DWORD *)(v82 + 8) & 0xFE000000) != (_DWORD)v21
                             || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v82 + 8) & 0x1FFFFFF )
                        {
                          ++v88;
                          v82 += 16i64;
                          if ( v88 >= v89 )
                          {
                            v83 = 0i64;
                            goto LABEL_270;
                          }
                        }
                        goto LABEL_247;
                      }
                    }
                  }
                  else
                  {
                    v84 = v17->mComponentTableEntryCount;
                    v85 = v17->m_Components.size;
                    if ( v84 < v85 )
                    {
                      v21 = UFG::RigidBodyComponent::_TypeUID & 0xFE000000;
                      v82 = (signed __int64)&v17->m_Components.p[v84];
                      while ( (*(_DWORD *)(v82 + 8) & 0xFE000000) != (_DWORD)v21
                           || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v82 + 8) & 0x1FFFFFF )
                      {
                        ++v84;
                        v82 += 16i64;
                        if ( v84 >= v85 )
                        {
                          v83 = 0i64;
                          goto LABEL_270;
                        }
                      }
                      goto LABEL_247;
                    }
                  }
LABEL_246:
                  v83 = 0i64;
                  goto LABEL_270;
                }
                v55 = LODWORD(v19[1].vfptr);
                v21 = v19->m_Components.size;
                if ( (unsigned int)v55 < (unsigned int)v21 )
                {
                  v64 = (signed __int64)&v19->m_Components.p[(unsigned int)v55];
                  while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                       || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
                  {
                    v55 = (unsigned int)(v55 + 1);
                    v64 += 16i64;
                    if ( (unsigned int)v55 >= (unsigned int)v21 )
                    {
                      v63 = 0i64;
                      goto LABEL_187;
                    }
                  }
                  goto LABEL_171;
                }
              }
            }
            else
            {
              v55 = LODWORD(v19[1].vfptr);
              v21 = v19->m_Components.size;
              if ( (unsigned int)v55 < (unsigned int)v21 )
              {
                v64 = (signed __int64)&v19->m_Components.p[(unsigned int)v55];
                while ( (*(_DWORD *)(v64 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                     || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF )
                {
                  v55 = (unsigned int)(v55 + 1);
                  v64 += 16i64;
                  if ( (unsigned int)v55 >= (unsigned int)v21 )
                    goto LABEL_170;
                }
LABEL_171:
                v63 = *(UFG::InventoryComponent **)v64;
                goto LABEL_187;
              }
            }
LABEL_170:
            v63 = 0i64;
            goto LABEL_187;
          }
          if ( !managePowerLevel )
          {
LABEL_121:
            v53 = (UFG::SimObjectCharacter *)v17;
            v54 = (__int64)v19;
            if ( v46 )
            {
              v15 = Creature::RemoveAttachment(v46, (UFG::SimObject *)&v17->vfptr, v41, v19);
              goto LABEL_154;
            }
            if ( !v19 )
              goto LABEL_124;
            v57 = v19->m_Flags;
            if ( (v57 >> 14) & 1 )
            {
              v56 = (UFG::WorldContextComponent *)v19->m_Components.p[28].m_pComponent;
              goto LABEL_150;
            }
            if ( (v57 & 0x8000u) == 0 )
            {
              if ( (v57 >> 13) & 1 )
              {
                v59 = (unsigned int)v19[1].vfptr;
                v21 = v19->m_Components.size;
                v28 = v59;
                if ( v59 < (unsigned int)v21 )
                {
                  v28 = (signed __int64)&v19->m_Components.p[v59];
                  while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                       || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
                  {
                    ++v59;
                    v28 += 16i64;
                    if ( v59 >= (unsigned int)v21 )
                    {
                      v56 = 0i64;
                      goto LABEL_150;
                    }
                  }
                  goto LABEL_134;
                }
              }
              else
              {
                if ( !((v57 >> 12) & 1) )
                {
                  v56 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                        v19,
                                                        UFG::WorldContextComponent::_TypeUID);
LABEL_150:
                  v55 = (__int64)v17->m_pTransformNodeComponent;
                  if ( v56 && v55 )
                    UFG::WorldContextComponent::DetachFrom(
                      v56,
                      (UFG::SimObject *)&v17->vfptr,
                      (UFG::TransformNodeComponent *)v55);
                  v15 = 1;
LABEL_154:
                  if ( makeUpright )
                  {
                    v61 = v27;
LABEL_159:
                    Creature::MakeUpright(v61, blendOutTime, v28);
                    goto LABEL_160;
                  }
                  goto LABEL_160;
                }
                v60 = (unsigned int)v19[1].vfptr;
                v21 = v19->m_Components.size;
                v28 = v60;
                if ( v60 < (unsigned int)v21 )
                {
                  v28 = (signed __int64)&v19->m_Components.p[v60];
                  while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                       || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
                  {
                    ++v60;
                    v28 += 16i64;
                    if ( v60 >= (unsigned int)v21 )
                    {
                      v56 = 0i64;
                      goto LABEL_150;
                    }
                  }
                  goto LABEL_134;
                }
              }
            }
            else
            {
              v58 = (unsigned int)v19[1].vfptr;
              v21 = v19->m_Components.size;
              v28 = v58;
              if ( v58 < (unsigned int)v21 )
              {
                v28 = (signed __int64)&v19->m_Components.p[v58];
                while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                     || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
                {
                  ++v58;
                  v28 += 16i64;
                  if ( v58 >= (unsigned int)v21 )
                  {
                    v56 = 0i64;
                    goto LABEL_150;
                  }
                }
LABEL_134:
                v56 = *(UFG::WorldContextComponent **)v28;
                goto LABEL_150;
              }
            }
LABEL_124:
            v56 = 0i64;
            goto LABEL_150;
          }
          v47 = v17->m_Flags;
          if ( (v47 >> 14) & 1 )
          {
            v48 = v17->mComponentTableEntryCount;
            v21 = v17->m_Components.size;
            v28 = v48;
            if ( v48 < (unsigned int)v21 )
            {
              v28 = (signed __int64)&v17->m_Components.p[v48];
              while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                   || UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
              {
                ++v48;
                v28 += 16i64;
                if ( v48 >= (unsigned int)v21 )
                  goto LABEL_95;
              }
LABEL_96:
              v49 = *(UFG::PowerManagementComponent **)v28;
              goto LABEL_119;
            }
          }
          else if ( (v47 & 0x8000u) == 0 )
          {
            if ( (v47 >> 13) & 1 )
            {
              v51 = v17->mComponentTableEntryCount;
              v21 = v17->m_Components.size;
              v28 = v51;
              if ( v51 < (unsigned int)v21 )
              {
                v28 = (signed __int64)&v17->m_Components.p[v51];
                while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                     || UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
                {
                  ++v51;
                  v28 += 16i64;
                  if ( v51 >= (unsigned int)v21 )
                  {
                    v49 = 0i64;
                    goto LABEL_119;
                  }
                }
                goto LABEL_96;
              }
            }
            else
            {
              if ( !((v47 >> 12) & 1) )
              {
                v49 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v17->vfptr,
                                                         UFG::PowerManagementComponent::_TypeUID);
LABEL_119:
                if ( v49 )
                  UFG::PowerManagementComponent::RemovePreventSuspendRefCount(v49);
                goto LABEL_121;
              }
              v52 = v17->mComponentTableEntryCount;
              v21 = v17->m_Components.size;
              v28 = v52;
              if ( v52 < (unsigned int)v21 )
              {
                v28 = (signed __int64)&v17->m_Components.p[v52];
                while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                     || UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
                {
                  ++v52;
                  v28 += 16i64;
                  if ( v52 >= (unsigned int)v21 )
                  {
                    v49 = 0i64;
                    goto LABEL_119;
                  }
                }
                goto LABEL_96;
              }
            }
          }
          else
          {
            v50 = v17->mComponentTableEntryCount;
            v21 = v17->m_Components.size;
            v28 = v50;
            if ( v50 < (unsigned int)v21 )
            {
              v28 = (signed __int64)&v17->m_Components.p[v50];
              while ( (*(_DWORD *)(v28 + 8) & 0xFE000000) != (UFG::PowerManagementComponent::_TypeUID & 0xFE000000)
                   || UFG::PowerManagementComponent::_TypeUID & ~*(_DWORD *)(v28 + 8) & 0x1FFFFFF )
              {
                ++v50;
                v28 += 16i64;
                if ( v50 >= (unsigned int)v21 )
                {
                  v49 = 0i64;
                  goto LABEL_119;
                }
              }
              goto LABEL_96;
            }
          }
LABEL_95:
          v49 = 0i64;
          goto LABEL_119;
        }
LABEL_61:
        v42 = 0i64;
        goto LABEL_79;
      }
      v43 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, v21);
    }
    v42 = v43;
    goto LABEL_79;
  }
LABEL_279:
  if ( releaseTarget && v97 )
  {
    LOBYTE(v21) = 1;
    ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))v97->vfptr[14].__vecDelDtor)(
      v97,
      (unsigned int)v18,
      0i64,
      v21,
      LODWORD(disableCollisionDelay),
      "TargetDetach",
      0i64,
      0i64);
    UFG::TargetingSystemBaseComponent::ClearTarget(v97, v18);
  }
  return v15;
}
      0i64);
    UFG::TargetingSystemBaseComponent::ClearTarget(v97, v18);
  }
  return v15;
}

// File Line: 732
// RVA: 0x554D20
__int64 __fastcall UFG::TargetDetach(ActionContext *context, UFG::eTargetTypeEnum targetType, UFG::SimObject *pOverrideTarget, UFG::qSymbolUC *attachJoint, UFG::qSymbolUC *targetAttachJoint, float blendOutTime, bool detachFromTarget, bool removeFromInventory, bool deleteOnDetach, bool releaseTarget, bool makeUpright, bool fadeAwayOnDetach, float disableCollisionDelay, float clampVelocity, bool managePowerLevel)
{
  ActionContext *v15; // rbx
  unsigned __int8 v16; // al
  UFG::SimObject *v17; // r9
  unsigned __int8 v18; // di
  unsigned __int16 v19; // dx
  UFG::TargetingSystemPedBaseComponent *v20; // rcx
  unsigned int v21; // edx
  unsigned int v22; // er8
  unsigned int v23; // er10
  signed __int64 v24; // rdx
  unsigned int v25; // er8
  unsigned int v26; // er10

  v15 = context;
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
  v17 = v15->mSimObject.m_pPointer;
  v18 = v16;
  if ( !v17 )
    return v18;
  v19 = v17->m_Flags;
  if ( !((v19 >> 14) & 1) )
  {
    if ( (v19 & 0x8000u) != 0 )
    {
      v20 = (UFG::TargetingSystemPedBaseComponent *)v17->m_Components.p[20].m_pComponent;
      goto LABEL_4;
    }
    if ( (v19 >> 13) & 1 )
    {
      v22 = (unsigned int)v17[1].vfptr;
      v23 = v17->m_Components.size;
      if ( v22 < v23 )
      {
        v24 = (signed __int64)&v17->m_Components.p[v22];
        while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
        {
          ++v22;
          v24 += 16i64;
          if ( v22 >= v23 )
          {
            v20 = 0i64;
            goto LABEL_26;
          }
        }
LABEL_17:
        v20 = *(UFG::TargetingSystemPedBaseComponent **)v24;
        goto LABEL_26;
      }
    }
    else
    {
      if ( !((v19 >> 12) & 1) )
      {
        v20 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                        v15->mSimObject.m_pPointer,
                                                        UFG::TargetingSystemPedBaseComponent::_TypeUID);
        goto LABEL_26;
      }
      v25 = (unsigned int)v17[1].vfptr;
      v26 = v17->m_Components.size;
      if ( v25 < v26 )
      {
        v24 = (signed __int64)&v17->m_Components.p[v25];
        while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
        {
          ++v25;
          v24 += 16i64;
          if ( v25 >= v26 )
          {
            v20 = 0i64;
            goto LABEL_26;
          }
        }
        goto LABEL_17;
      }
    }
LABEL_7:
    v20 = 0i64;
    goto LABEL_26;
  }
  v20 = (UFG::TargetingSystemPedBaseComponent *)v17->m_Components.p[20].m_pComponent;
LABEL_4:
  if ( !v20 )
    goto LABEL_7;
  v21 = v20->m_TypeUID;
  if ( (v21 ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000
    || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v21 & 0x1FFFFFF )
  {
    goto LABEL_7;
  }
LABEL_26:
  if ( v20 )
    UFG::TargetingSystemPedBaseComponent::UpdateCommon(v20);
  return v18;
}

// File Line: 771
// RVA: 0x5564E0
void __fastcall UFG::TargetDetachEffector(UFG::SimObject *simObject, UFG::CharacterAnimationComponent *animationComponent, UFG::eTargetTypeEnum targetType, UFG::qSymbolUC *attachEffectorUID, float blendTime)
{
  unsigned __int16 v5; // r10
  Creature *v6; // rdi
  UFG::qSymbolUC *v7; // r14
  __int64 v8; // rsi
  UFG::CharacterAnimationComponent *v9; // rbp
  UFG::SimObject *v10; // rbx
  UFG::SimComponent *v11; // rax
  unsigned int v12; // er8
  unsigned int v13; // er9
  UFG::SimComponentHolder *v14; // rdx
  unsigned int v15; // er8
  unsigned int v16; // er9
  UFG::SimObject *v17; // rsi
  signed __int64 v18; // rcx
  int v19; // eax

  if ( !simObject )
    return;
  v5 = simObject->m_Flags;
  v6 = 0i64;
  v7 = attachEffectorUID;
  v8 = (unsigned int)targetType;
  v9 = animationComponent;
  v10 = simObject;
  if ( !((v5 >> 14) & 1) )
  {
    if ( (v5 & 0x8000u) != 0 )
    {
      v11 = simObject->m_Components.p[20].m_pComponent;
      goto LABEL_22;
    }
    if ( (v5 >> 13) & 1 )
    {
      v12 = (unsigned int)simObject[1].vfptr;
      v13 = simObject->m_Components.size;
      if ( v12 < v13 )
      {
        v14 = &simObject->m_Components.p[v12];
        while ( (v14->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF )
        {
          ++v12;
          ++v14;
          if ( v12 >= v13 )
            goto LABEL_12;
        }
LABEL_13:
        v11 = v14->m_pComponent;
        goto LABEL_22;
      }
    }
    else
    {
      if ( !((v5 >> 12) & 1) )
      {
        v11 = UFG::SimObject::GetComponentOfType(simObject, UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_22;
      }
      v15 = (unsigned int)simObject[1].vfptr;
      v16 = simObject->m_Components.size;
      if ( v15 < v16 )
      {
        v14 = &simObject->m_Components.p[v15];
        while ( (v14->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF )
        {
          ++v15;
          ++v14;
          if ( v15 >= v16 )
          {
            v11 = 0i64;
            goto LABEL_22;
          }
        }
        goto LABEL_13;
      }
    }
LABEL_12:
    v11 = 0i64;
    goto LABEL_22;
  }
  v11 = simObject->m_Components.p[20].m_pComponent;
LABEL_22:
  if ( v11 )
  {
    v17 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v11[1].m_Flags + v8 + 8)
                             + *(_QWORD *)&v11[1].m_TypeUID
                             + 40);
    if ( v9 )
      v6 = v9->mCreature;
    if ( v6 )
    {
      v18 = (signed __int64)&v6->mPoseDrivers.mNode.mNext[-1];
      if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v18 != &v6->m_SafePointerList )
      {
        while ( *(_DWORD *)(v18 + 44) != v7->mUID )
        {
          v18 = *(_QWORD *)(v18 + 24) - 16i64;
          if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v18 == &v6->m_SafePointerList )
            return;
        }
        v19 = (*(__int64 (**)(void))(*(_QWORD *)v18 + 112i64))();
        Creature::RemoveAttachment(v6, v10, v19, v17);
      }
    }
  }
}

// File Line: 808
// RVA: 0x5548C0
void __fastcall UFG::TargetAttachEffector(UFG::SimObject *simObject, UFG::CharacterAnimationComponent *animationComponent, UFG::eTargetTypeEnum targetType, UFG::qSymbolUC *attachEffectorUID, UFG::qSymbolUC *baseJointUID, UFG::qSymbolUC *adjustJointUID, float blendTime, const bool onlyEnablePostPhysics)
{
  UFG::qSymbolUC *v8; // r12
  __int64 v9; // rdi
  UFG::CharacterAnimationComponent *v10; // rbp
  UFG::SimObject *v11; // r13
  unsigned __int16 v12; // r10
  __int64 v13; // rsi
  UFG::SimComponent *v14; // rax
  unsigned int v15; // er8
  unsigned int v16; // er9
  UFG::SimComponentHolder *v17; // rbx
  signed __int64 v18; // rdx
  unsigned int v19; // er8
  unsigned int v20; // er9
  UFG::SimObjectProp *v21; // r14
  unsigned __int16 v22; // cx
  UFG::CharacterAnimationComponent *v23; // rdi
  UFG::CharacterAnimationComponent *v24; // rax
  unsigned int v25; // er8
  unsigned int v26; // er9
  UFG::SimComponentHolder *v27; // rbx
  Creature *v28; // rbp
  Creature *v29; // r15
  signed __int64 v30; // rbx
  UFG::allocator::free_link *v31; // rax
  __int64 v32; // rax
  signed int v33; // edi
  signed int v34; // eax

  if ( !simObject )
    return;
  v8 = attachEffectorUID;
  v9 = (unsigned int)targetType;
  v10 = animationComponent;
  v11 = simObject;
  v12 = simObject->m_Flags;
  v13 = 0i64;
  if ( !((v12 >> 14) & 1) )
  {
    if ( (v12 & 0x8000u) != 0 )
    {
      v14 = simObject->m_Components.p[20].m_pComponent;
      goto LABEL_23;
    }
    if ( (v12 >> 13) & 1 )
    {
      v15 = (unsigned int)simObject[1].vfptr;
      v16 = simObject->m_Components.size;
      if ( v15 < v16 )
      {
        v17 = simObject->m_Components.p;
        while ( 1 )
        {
          v18 = v15;
          if ( (v17[v15].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
            && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v17[v15].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v15 >= v16 )
            goto LABEL_14;
        }
LABEL_13:
        v14 = v17[v18].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( !((v12 >> 12) & 1) )
      {
        v14 = UFG::SimObject::GetComponentOfType(simObject, UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_23;
      }
      v19 = (unsigned int)simObject[1].vfptr;
      v20 = simObject->m_Components.size;
      if ( v19 < v20 )
      {
        v17 = simObject->m_Components.p;
        do
        {
          v18 = v19;
          if ( (v17[v19].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
            && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v17[v19].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_13;
          }
        }
        while ( ++v19 < v20 );
      }
    }
LABEL_14:
    v14 = 0i64;
    goto LABEL_23;
  }
  v14 = simObject->m_Components.p[20].m_pComponent;
LABEL_23:
  if ( !v14 )
    return;
  v21 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v14[1].m_Flags + v9 + 8)
                               + *(_QWORD *)&v14[1].m_TypeUID
                               + 40);
  if ( !v21 )
    return;
  v22 = v21->m_Flags;
  if ( (v22 >> 14) & 1 )
  {
    v23 = (UFG::CharacterAnimationComponent *)v21->m_Components.p[9].m_pComponent;
    if ( !v23
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v23->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v23->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_29;
    }
  }
  else
  {
    if ( (v22 & 0x8000u) == 0 )
    {
      if ( (v22 >> 13) & 1 )
      {
        v24 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v21);
      }
      else
      {
        if ( (v22 >> 12) & 1 )
        {
          v25 = v21->mComponentTableEntryCount;
          v26 = v21->m_Components.size;
          if ( v25 < v26 )
          {
            v27 = v21->m_Components.p;
            while ( (v27[v25].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                 || UFG::CharacterAnimationComponent::_TypeUID & ~v27[v25].m_TypeUID & 0x1FFFFFF )
            {
              if ( ++v25 >= v26 )
                goto LABEL_29;
            }
            v23 = (UFG::CharacterAnimationComponent *)v27[v25].m_pComponent;
            goto LABEL_47;
          }
          goto LABEL_29;
        }
        v24 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v21->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      v23 = v24;
      goto LABEL_47;
    }
    v23 = (UFG::CharacterAnimationComponent *)v21->m_Components.p[9].m_pComponent;
    if ( !v23 || (UFG::CharacterAnimationComponent::_TypeUID ^ v23->m_TypeUID) & 0xFE000000 )
    {
LABEL_29:
      v23 = 0i64;
      goto LABEL_47;
    }
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v23->m_TypeUID & 0x1FFFFFF )
      v23 = 0i64;
  }
LABEL_47:
  if ( v23 )
  {
    v28 = v10->mCreature;
    v29 = v23->mCreature;
    if ( v28 )
    {
      if ( v29 )
      {
        if ( v29->mPose.mRigHandle.mData )
        {
          if ( v28->mPose.mRigHandle.mData )
          {
            v30 = (signed __int64)&v28->mPoseDrivers.mNode.mNext[-1];
            if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v30 != &v28->m_SafePointerList )
            {
              while ( *(_DWORD *)(v30 + 44) != v8->mUID )
              {
                v30 = *(_QWORD *)(v30 + 24) - 16i64;
                if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v30 == &v28->m_SafePointerList )
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
                (UFG::SimComponent *)&v23->vfptr);
              *(_QWORD *)(v13 + 232) = v30;
              *(_DWORD *)(v13 + 240) = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v30 + 112i64))(v30);
              v33 = -1;
              if ( v28->mPose.mRigHandle.mData )
                v34 = Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, adjustJointUID->mUID);
              else
                v34 = -1;
              *(_DWORD *)(v13 + 244) = v34;
              if ( v29->mPose.mRigHandle.mData )
                v33 = Skeleton::GetBoneID(v29->mPose.mRigHandle.mUFGSkeleton, baseJointUID->mUID);
              *(_DWORD *)(v13 + 248) = v33;
              *(_DWORD *)(v13 + 256) = 1065353216;
              Attachment::SetBlendIn((Attachment *)v13, blendTime);
              *(_BYTE *)(v13 + 252) = onlyEnablePostPhysics;
              *(_DWORD *)(v13 + 32) = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v30 + 112i64))(v30);
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v13 + 40),
                (UFG::SimComponent *)v11);
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v13 + 64),
                (UFG::SimComponent *)v28);
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v13 + 88),
                (UFG::SimComponent *)v21);
              if ( Creature::AddAttachment(v28, (Attachment *)v13) != (UFG::qNode<Attachment,Attachment> **)v13 )
                (**(void (__fastcall ***)(__int64, signed __int64))v13)(v13, 1i64);
            }
          }
        }
      }
    }
  }
}hment(v28, (Attachment *)v13) != (UFG::qNode<Attachment,Attachment> **)v13 )
                (**(void (_

// File Line: 885
// RVA: 0x5542A0
__int64 __fastcall UFG::TargetAttachConstraint(UFG::SimObject *simObject, UFG::eTargetTypeEnum targetType, UFG::qSymbolUC *attachJoint, UFG::qSymbolUC *targetAttachJoint, bool attachRelative, bool assignTarget, UFG::eTargetTypeEnum assignmentTargetType, bool lockTarget)
{
  unsigned __int8 v8; // r14
  UFG::qSymbolUC *v9; // r15
  UFG::qSymbolUC *v10; // rdi
  __int64 v11; // r13
  UFG::SimObjectProp *v12; // rbx
  unsigned __int16 v13; // cx
  UFG::CharacterAnimationComponent *v14; // rcx
  UFG::CharacterAnimationComponent *v15; // rax
  unsigned int v16; // er8
  unsigned int v17; // er10
  signed __int64 v18; // rdx
  Creature *v19; // rax
  bool v20; // zf
  unsigned __int16 v21; // cx
  UFG::TargetingSystemBaseComponent *v22; // rdi
  unsigned int v23; // er8
  unsigned int v24; // er10
  signed __int64 v25; // rdx
  unsigned int v26; // er8
  unsigned int v27; // er10
  UFG::SimObjectProp *v28; // rax
  UFG::SimObject *v29; // rsi
  unsigned __int16 v30; // cx
  int v31; // er12
  UFG::CharacterAnimationComponent *v32; // rcx
  UFG::CharacterAnimationComponent *v33; // rax
  unsigned int v34; // er8
  unsigned int v35; // er10
  signed __int64 v36; // rdx
  Creature *v37; // rbp
  UFG::RagdollComponent *v38; // r15
  UFG::SimComponent *v39; // rax
  UFG::SimComponent *v40; // rbx
  UFG::Ragdoll *v41; // rcx
  hkpRigidBody *v42; // rsi
  UFG::Ragdoll *v43; // rcx
  hkpRigidBody *v44; // rbx
  UFG::Constraint *v45; // rax
  UFG::eTargetTypeEnum v46; // er8
  UFG::qVector3 v48; // [rsp+40h] [rbp-68h]
  UFG::qVector3 result; // [rsp+50h] [rbp-58h]
  UFG::qVector3 pivotWorldConstraint; // [rsp+60h] [rbp-48h]
  signed int skeletonBoneID; // [rsp+B0h] [rbp+8h]

  v8 = 0;
  v9 = targetAttachJoint;
  v10 = attachJoint;
  v11 = targetType;
  v12 = (UFG::SimObjectProp *)simObject;
  if ( !simObject )
    return v8;
  v13 = simObject->m_Flags;
  if ( (v13 >> 14) & 1 )
  {
    v14 = (UFG::CharacterAnimationComponent *)v12->m_Components.p[9].m_pComponent;
    if ( !v14
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v14->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( (v13 & 0x8000u) != 0 )
  {
    v14 = (UFG::CharacterAnimationComponent *)v12->m_Components.p[9].m_pComponent;
    if ( !v14 || (UFG::CharacterAnimationComponent::_TypeUID ^ v14->m_TypeUID) & 0xFE000000 )
      goto LABEL_6;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF )
      v14 = 0i64;
    goto LABEL_24;
  }
  if ( (v13 >> 13) & 1 )
  {
    v15 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v12);
LABEL_23:
    v14 = v15;
    goto LABEL_24;
  }
  if ( !((v13 >> 12) & 1) )
  {
    v15 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v12->vfptr,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  v16 = v12->mComponentTableEntryCount;
  v17 = v12->m_Components.size;
  if ( v16 >= v17 )
  {
LABEL_6:
    v14 = 0i64;
    goto LABEL_24;
  }
  v18 = (signed __int64)&v12->m_Components.p[v16];
  while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
  {
    ++v16;
    v18 += 16i64;
    if ( v16 >= v17 )
    {
      v14 = 0i64;
      goto LABEL_24;
    }
  }
  v14 = *(UFG::CharacterAnimationComponent **)v18;
LABEL_24:
  if ( !v14 )
    return v8;
  v19 = v14->mCreature;
  v20 = v19->mPose.mRigHandle.mData == 0i64;
  *(_QWORD *)&v48.x = v14->mCreature;
  if ( v20 )
    skeletonBoneID = -1;
  else
    skeletonBoneID = Skeleton::GetBoneID(v19->mPose.mRigHandle.mUFGSkeleton, v10->mUID);
  v21 = v12->m_Flags;
  if ( (v21 >> 14) & 1 )
  {
    v22 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
    goto LABEL_48;
  }
  if ( (v21 & 0x8000u) != 0 )
  {
    v22 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
    goto LABEL_48;
  }
  if ( (v21 >> 13) & 1 )
  {
    v23 = v12->mComponentTableEntryCount;
    v24 = v12->m_Components.size;
    if ( v23 < v24 )
    {
      v25 = (signed __int64)&v12->m_Components.p[v23];
      while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF )
      {
        ++v23;
        v25 += 16i64;
        if ( v23 >= v24 )
          goto LABEL_38;
      }
LABEL_39:
      v22 = *(UFG::TargetingSystemBaseComponent **)v25;
      goto LABEL_48;
    }
    goto LABEL_38;
  }
  if ( (v21 >> 12) & 1 )
  {
    v26 = v12->mComponentTableEntryCount;
    v27 = v12->m_Components.size;
    if ( v26 < v27 )
    {
      v25 = (signed __int64)&v12->m_Components.p[v26];
      while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF )
      {
        ++v26;
        v25 += 16i64;
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
                                               (UFG::SimObject *)&v12->vfptr,
                                               UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_48:
  v28 = (UFG::SimObjectProp *)UFG::getTarget((UFG::SimObject *)&v12->vfptr, v22, (UFG::eTargetTypeEnum)v11);
  v29 = (UFG::SimObject *)&v28->vfptr;
  if ( !v28 )
  {
    UFG::qPrintf("WARNING: TargetAttachConstraint: Target Not Found! (%s)\n", UFG::TargetTypeEnumNames[v11]);
    return v8;
  }
  v30 = v28->m_Flags;
  v31 = 0;
  if ( !((v30 >> 14) & 1) )
  {
    if ( (v30 & 0x8000u) != 0 )
    {
      v32 = (UFG::CharacterAnimationComponent *)v28->m_Components.p[9].m_pComponent;
      if ( v32 && !((UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000) )
      {
        if ( UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF )
          v32 = 0i64;
        goto LABEL_71;
      }
      goto LABEL_53;
    }
    if ( (v30 >> 13) & 1 )
    {
      v33 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v28);
    }
    else
    {
      if ( (v30 >> 12) & 1 )
      {
        v34 = v28->mComponentTableEntryCount;
        v35 = v28->m_Components.size;
        if ( v34 < v35 )
        {
          v36 = (signed __int64)&v28->m_Components.p[v34];
          while ( (*(_DWORD *)(v36 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v36 + 8) & 0x1FFFFFF )
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
                                                  (UFG::SimObject *)&v28->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    v32 = v33;
    goto LABEL_71;
  }
  v32 = (UFG::CharacterAnimationComponent *)v28->m_Components.p[9].m_pComponent;
  if ( !v32
    || (UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000
    || UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF )
  {
LABEL_53:
    v32 = 0i64;
  }
LABEL_71:
  if ( v32 )
    v37 = v32->mCreature;
  else
    v37 = 0i64;
  if ( v37 )
  {
    if ( v37->mPose.mRigHandle.mData )
      v31 = Skeleton::GetBoneID(v37->mPose.mRigHandle.mUFGSkeleton, v9->mUID);
    v38 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                     (UFG::SimObject *)&v12->vfptr,
                                     UFG::RagdollComponent::_TypeUID);
    v39 = UFG::SimObject::GetComponentOfType(v29, UFG::RagdollComponent::_TypeUID);
    v40 = v39;
    if ( v38 && v39 )
    {
      v41 = v38->mRagdoll;
      v42 = v41 ? UFG::Ragdoll::GetRigidBody(v41, skeletonBoneID) : 0i64;
      v43 = (UFG::Ragdoll *)v40[1].m_BoundComponentHandles.mNode.mPrev;
      v44 = v43 ? UFG::Ragdoll::GetRigidBody(v43, v31) : 0i64;
      if ( v42 && v44 )
      {
        Creature::GetTranslation(*(Creature **)&v48.x, &result, skeletonBoneID);
        Creature::GetTranslation(v37, &v48, v31);
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
      v46 = (signed int)v11;
      LODWORD(v11) = assignmentTargetType;
      UFG::TargetingSystemBaseComponent::AssignTarget(v22, assignmentTargetType, v46);
    }
    if ( lockTarget )
      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, signed __int64))v22->vfptr[14].__vecDelDtor)(
        v22,
        (unsigned int)v11,
        1i64);
  }
  return v8;
}

// File Line: 986
// RVA: 0x555FC0
char __fastcall UFG::TargetDetachConstraint(UFG::SimObject *simObject, UFG::eTargetTypeEnum targetType, UFG::qSymbolUC *attachJoint, UFG::qSymbolUC *targetAttachJoint)
{
  hkpRigidBody *v4; // rbp
  UFG::qSymbolUC *v5; // r12
  UFG::qSymbolUC *v6; // rbx
  __int64 v7; // r14
  UFG::SimObject *v8; // rdi
  unsigned __int16 v9; // r10
  UFG::SimComponent *v10; // rcx
  unsigned int v11; // edx
  unsigned int v12; // edx
  UFG::CharacterAnimationComponent *v13; // rax
  unsigned int v14; // er8
  unsigned int v15; // er9
  UFG::SimComponentHolder *v16; // rdx
  __int64 v17; // rcx
  int v18; // er15
  UFG::TargetingSystemBaseComponent *v19; // rax
  unsigned __int16 v20; // cx
  unsigned int v21; // er8
  unsigned int v22; // er9
  signed __int64 v23; // rdx
  unsigned int v24; // er8
  unsigned int v25; // er9
  UFG::SimObjectProp *v26; // rax
  UFG::SimObject *v27; // rsi
  unsigned __int16 v28; // cx
  int v29; // er14
  UFG::CharacterAnimationComponent *v30; // rbx
  UFG::CharacterAnimationComponent *v31; // rax
  unsigned int v32; // edx
  unsigned int v33; // er8
  signed __int64 v34; // rbx
  Creature *v35; // rcx
  UFG::RagdollComponent *v36; // rbx
  UFG::SimComponent *v37; // rax
  UFG::SimComponent *v38; // rsi
  UFG::Ragdoll *v39; // rcx
  hkpRigidBody *v40; // rdi
  UFG::Ragdoll *v41; // rcx

  v4 = 0i64;
  v5 = targetAttachJoint;
  v6 = attachJoint;
  v7 = targetType;
  v8 = simObject;
  if ( !simObject )
    goto LABEL_26;
  v9 = simObject->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = simObject->m_Components.p[9].m_pComponent;
    if ( !v10 )
      goto LABEL_6;
    v11 = v10->m_TypeUID;
    if ( (v11 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v11 & 0x1FFFFFF )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( (v9 & 0x8000u) != 0 )
  {
    v10 = simObject->m_Components.p[9].m_pComponent;
    if ( !v10 )
      goto LABEL_6;
    v12 = v10->m_TypeUID;
    if ( (v12 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000 )
      goto LABEL_6;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v12 & 0x1FFFFFF )
      v10 = 0i64;
    goto LABEL_24;
  }
  if ( (v9 >> 13) & 1 )
  {
    v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)simObject);
LABEL_23:
    v10 = (UFG::SimComponent *)&v13->vfptr;
    goto LABEL_24;
  }
  if ( !((v9 >> 12) & 1) )
  {
    v13 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                simObject,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  v14 = (unsigned int)simObject[1].vfptr;
  v15 = simObject->m_Components.size;
  if ( v14 >= v15 )
  {
LABEL_6:
    v10 = 0i64;
    goto LABEL_24;
  }
  v16 = &simObject->m_Components.p[v14];
  while ( (v16->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~v16->m_TypeUID & 0x1FFFFFF )
  {
    ++v14;
    ++v16;
    if ( v14 >= v15 )
    {
      v10 = 0i64;
      goto LABEL_24;
    }
  }
  v10 = v16->m_pComponent;
LABEL_24:
  if ( v10 )
  {
    v17 = *(_QWORD *)&v10[2].m_TypeUID;
    goto LABEL_27;
  }
LABEL_26:
  v17 = 0i64;
LABEL_27:
  if ( v17 )
  {
    if ( *(_QWORD *)(v17 + 440) )
      v18 = Skeleton::GetBoneID(*(Skeleton **)(v17 + 480), v6->mUID);
    else
      v18 = -1;
    if ( !v8 )
      goto LABEL_32;
    v20 = v8->m_Flags;
    if ( (v20 >> 14) & 1 )
    {
      v19 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
      goto LABEL_53;
    }
    if ( (v20 & 0x8000u) != 0 )
    {
      v19 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
      goto LABEL_53;
    }
    if ( (v20 >> 13) & 1 )
    {
      v21 = (unsigned int)v8[1].vfptr;
      v22 = v8->m_Components.size;
      if ( v21 < v22 )
      {
        v23 = (signed __int64)&v8->m_Components.p[v21];
        while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
        {
          ++v21;
          v23 += 16i64;
          if ( v21 >= v22 )
          {
            v19 = 0i64;
            goto LABEL_53;
          }
        }
LABEL_44:
        v19 = *(UFG::TargetingSystemBaseComponent **)v23;
        goto LABEL_53;
      }
    }
    else
    {
      if ( !((v20 >> 12) & 1) )
      {
        v19 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                     v8,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_53:
        v26 = (UFG::SimObjectProp *)UFG::getTarget(v8, v19, (UFG::eTargetTypeEnum)v7);
        v27 = (UFG::SimObject *)&v26->vfptr;
        if ( !v26 )
        {
          UFG::qPrintf("WARNING: TargetDetachConstraint: Target Not Found! (%s)\n", UFG::TargetTypeEnumNames[v7]);
          return 0;
        }
        v28 = v26->m_Flags;
        v29 = 0;
        if ( (v28 >> 14) & 1 )
        {
          v30 = (UFG::CharacterAnimationComponent *)v26->m_Components.p[9].m_pComponent;
          if ( v30
            && !((UFG::CharacterAnimationComponent::_TypeUID ^ v30->m_TypeUID) & 0xFE000000)
            && !(UFG::CharacterAnimationComponent::_TypeUID & ~v30->m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_76;
          }
          goto LABEL_58;
        }
        if ( (v28 & 0x8000u) != 0 )
        {
          v30 = (UFG::CharacterAnimationComponent *)v26->m_Components.p[9].m_pComponent;
          if ( v30 && !((UFG::CharacterAnimationComponent::_TypeUID ^ v30->m_TypeUID) & 0xFE000000) )
          {
            if ( UFG::CharacterAnimationComponent::_TypeUID & ~v30->m_TypeUID & 0x1FFFFFF )
              v30 = 0i64;
            goto LABEL_76;
          }
          goto LABEL_58;
        }
        if ( (v28 >> 13) & 1 )
        {
          v31 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v26);
        }
        else
        {
          if ( (v28 >> 12) & 1 )
          {
            v32 = v26->mComponentTableEntryCount;
            v33 = v26->m_Components.size;
            if ( v32 < v33 )
            {
              v34 = (signed __int64)&v26->m_Components.p[v32];
              while ( (*(_DWORD *)(v34 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                   || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v34 + 8) & 0x1FFFFFF )
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
                v35 = v30->mCreature;
              else
                v35 = 0i64;
              if ( v35 && v35->mPose.mRigHandle.mData )
                v29 = Skeleton::GetBoneID(v35->mPose.mRigHandle.mUFGSkeleton, v5->mUID);
              if ( v30 )
              {
                v36 = (UFG::RagdollComponent *)(v8 ? UFG::SimObject::GetComponentOfType(
                                                       v8,
                                                       UFG::RagdollComponent::_TypeUID) : 0i64);
                v37 = UFG::SimObject::GetComponentOfType(v27, UFG::RagdollComponent::_TypeUID);
                v38 = v37;
                if ( v36 )
                {
                  if ( v37 )
                  {
                    v39 = v36->mRagdoll;
                    v40 = v39 ? UFG::Ragdoll::GetRigidBody(v39, v18) : 0i64;
                    v41 = (UFG::Ragdoll *)v38[1].m_BoundComponentHandles.mNode.mPrev;
                    if ( v41 )
                      v4 = UFG::Ragdoll::GetRigidBody(v41, v29);
                    if ( v40 && v4 )
                    {
                      UFG::RagdollComponent::RemoveConstraint(v36, v40, v4);
                      return 1;
                    }
                  }
                }
              }
              return 0;
            }
LABEL_58:
            v30 = 0i64;
            goto LABEL_76;
          }
          v31 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v26->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        v30 = v31;
        goto LABEL_76;
      }
      v24 = (unsigned int)v8[1].vfptr;
      v25 = v8->m_Components.size;
      if ( v24 < v25 )
      {
        v23 = (signed __int64)&v8->m_Components.p[v24];
        while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
        {
          ++v24;
          v23 += 16i64;
          if ( v24 >= v25 )
          {
            v19 = 0i64;
            goto LABEL_53;
          }
        }
        goto LABEL_44;
      }
    }
LABEL_32:
    v19 = 0i64;
    goto LABEL_53;
  }
  return 0;
}

// File Line: 1064
// RVA: 0x5514D0
void __fastcall UFG::SteerToTarget(UFG::SimObject *pMe, UFG::SimObject *pTarget, UFG::qSymbolUC *targetAttachJoint, float fMaxRotationRadians)
{
  UFG::qSymbolUC *v4; // r13
  UFG::SimObjectProp *v5; // rdi
  UFG::SimObjectProp *v6; // rbx
  unsigned __int16 v7; // cx
  __int64 v8; // r8
  UFG::CharacterAnimationComponent *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // er10
  signed __int64 v12; // rdx
  UFG::TransformNodeComponent *v13; // r15
  UFG::AimingBaseComponent *v14; // r14
  char v15; // r12
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rcx
  unsigned int v18; // er8
  unsigned int v19; // er9
  unsigned int v20; // er11
  signed __int64 v21; // rdx
  unsigned int v22; // er9
  unsigned int v23; // er11
  float v24; // xmm6_4
  float v25; // xmm7_4
  unsigned __int16 v26; // cx
  unsigned int v27; // er9
  unsigned int v28; // er11
  signed __int64 v29; // rdx
  unsigned int v30; // er9
  unsigned int v31; // er11
  unsigned int v32; // er9
  unsigned int v33; // er11
  char v34; // si
  float *v35; // rsi
  float v36; // xmm8_4
  unsigned __int16 v37; // cx
  UFG::CharacterAnimationComponent *v38; // rcx
  UFG::CharacterAnimationComponent *v39; // rax
  unsigned int v40; // er8
  unsigned int v41; // er10
  UFG::SimComponentHolder *v42; // rdi
  signed __int64 v43; // rdx
  Creature *v44; // rdi
  int v45; // eax
  float v46; // xmm2_4
  unsigned __int16 v47; // cx
  unsigned int v48; // er9
  unsigned int v49; // er11
  signed __int64 v50; // rdx
  UFG::RigidBody *v51; // rax
  unsigned int v52; // er9
  unsigned int v53; // er11
  unsigned int v54; // er9
  unsigned int v55; // er11
  unsigned int v56; // er9
  unsigned int v57; // er11
  __m128 v58; // xmm1
  float v59; // xmm3_4
  unsigned __int16 v60; // cx
  UFG::SimComponent *v61; // rdi
  unsigned int v62; // er9
  unsigned int v63; // er11
  signed __int64 v64; // rdx
  unsigned int v65; // er9
  unsigned int v66; // er11
  unsigned __int16 v67; // dx
  UFG::SimComponent *v68; // rcx
  unsigned int v69; // er8
  unsigned int v70; // er10
  UFG::SimComponentHolder *v71; // rbx
  signed __int64 v72; // rdx
  unsigned int v73; // er8
  unsigned int v74; // er10
  unsigned int v75; // er8
  unsigned int v76; // er10
  float v77; // xmm6_4
  __m128 v78; // xmm7
  __m128 v79; // xmm2
  float v80; // xmm1_4
  float v81; // xmm6_4
  float v82; // xmm7_4
  unsigned __int16 v83; // cx
  UFG::SimComponent *v84; // rcx
  unsigned int v85; // er9
  unsigned int v86; // er11
  UFG::SimComponentHolder *v87; // rbx
  signed __int64 v88; // rdx
  unsigned int v89; // er9
  unsigned int v90; // er11
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
  __m128 v104; // xmm13
  __m128 v105; // xmm3
  float v106; // xmm1_4
  float v107; // xmm2_4
  float v108; // xmm2_4
  Creature *v109; // rdi
  __m128 v110; // xmm4
  __m128 v111; // xmm5
  __m128 v112; // xmm6
  __m128 v113; // xmm6
  __m128 v114; // xmm3
  UFG::qVector3 dest; // [rsp+20h] [rbp-A8h]
  UFG::qVector3 v116; // [rsp+30h] [rbp-98h]
  hkQuaternionf v117; // [rsp+40h] [rbp-88h]
  UFG::qVector3 source; // [rsp+50h] [rbp-78h]
  float v119; // [rsp+5Ch] [rbp-6Ch]
  UFG::qMatrix44 transform; // [rsp+60h] [rbp-68h]
  __int64 v121; // [rsp+148h] [rbp+80h]
  float v122; // [rsp+160h] [rbp+98h]
  float v123; // [rsp+168h] [rbp+A0h]
  float radians; // [rsp+170h] [rbp+A8h]
  void *retaddr; // [rsp+178h] [rbp+B0h]
  char v126; // [rsp+180h] [rbp+B8h]
  float *v127; // [rsp+188h] [rbp+C0h]

  if ( !pMe )
    return;
  *(_QWORD *)&transform.v0.z = -2i64;
  v4 = targetAttachJoint;
  v5 = (UFG::SimObjectProp *)pTarget;
  v6 = (UFG::SimObjectProp *)pMe;
  if ( !pTarget && !(_BYTE)retaddr )
    return;
  v7 = pMe->m_Flags;
  if ( !((v7 >> 14) & 1) && (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
    {
      v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v6);
LABEL_20:
      v121 = (__int64)v9;
      goto LABEL_21;
    }
    if ( !((v7 >> 12) & 1) )
    {
      v9 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v6->vfptr,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
      goto LABEL_20;
    }
    v10 = v6->mComponentTableEntryCount;
    v11 = v6->m_Components.size;
    if ( v10 < v11 )
    {
      while ( 1 )
      {
        v12 = (signed __int64)&v6->m_Components.p[v10];
        if ( (*(_DWORD *)(v12 + 8) & 0xFE000000) == (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
          && !(UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v10 >= v11 )
          goto LABEL_8;
      }
      v9 = *(UFG::CharacterAnimationComponent **)v12;
      goto LABEL_20;
    }
    goto LABEL_8;
  }
  v8 = (__int64)v6->m_Components.p[9].m_pComponent;
  v121 = v8;
  if ( !v8
    || (UFG::CharacterAnimationComponent::_TypeUID ^ *(_DWORD *)(v8 + 24)) & 0xFE000000
    || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v8 + 24) & 0x1FFFFFF )
  {
LABEL_8:
    v121 = 0i64;
  }
LABEL_21:
  v13 = v6->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6->m_pTransformNodeComponent);
  v14 = 0i64;
  v15 = 0;
  v16 = v6->m_Flags;
  if ( !((v16 >> 14) & 1) && (v16 & 0x8000u) == 0 )
  {
    if ( (v16 >> 13) & 1 )
    {
      v19 = v6->mComponentTableEntryCount;
      v20 = v6->m_Components.size;
      v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
      if ( v19 < v20 )
      {
        while ( 1 )
        {
          v21 = (signed __int64)&v6->m_Components.p[v19];
          if ( (*(_DWORD *)(v21 + 8) & 0xFE000000) == (UFG::AICharacterControllerBaseComponent::_TypeUID & 0xFE000000)
            && !(UFG::AICharacterControllerBaseComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v19 >= v20 )
            goto LABEL_25;
        }
LABEL_33:
        v17 = *(UFG::SimComponent **)v21;
        goto LABEL_41;
      }
    }
    else
    {
      if ( !((v16 >> 12) & 1) )
      {
        v17 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v6->vfptr,
                UFG::AICharacterControllerBaseComponent::_TypeUID);
        v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
        goto LABEL_41;
      }
      v22 = v6->mComponentTableEntryCount;
      v23 = v6->m_Components.size;
      v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
      if ( v22 < v23 )
      {
        while ( 1 )
        {
          v21 = (signed __int64)&v6->m_Components.p[v22];
          if ( (*(_DWORD *)(v21 + 8) & 0xFE000000) == (UFG::AICharacterControllerBaseComponent::_TypeUID & 0xFE000000)
            && !(UFG::AICharacterControllerBaseComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) )
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
  v17 = v6->m_Components.p[21].m_pComponent;
  v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
  if ( !v17
    || (UFG::AICharacterControllerBaseComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000
    || UFG::AICharacterControllerBaseComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF )
  {
LABEL_25:
    v17 = 0i64;
  }
LABEL_41:
  if ( v17 && LOBYTE(v17[2].m_Flags) )
  {
    v24 = *(float *)&v17[2].m_pSimObject + v13->mWorldTransform.v3.y;
    v25 = *(float *)(&v17[2].m_SimObjIndex + 1) + v13->mWorldTransform.v3.x;
    v15 = 1;
  }
  else
  {
    v24 = v117.m_vec.m_quad.m128_f32[1];
    v25 = v117.m_vec.m_quad.m128_f32[0];
  }
  if ( !v127 )
  {
    if ( !v126 )
      goto LABEL_73;
    v26 = v6->m_Flags;
    if ( (v26 >> 14) & 1 )
    {
      v14 = (UFG::AimingBaseComponent *)v6->m_Components.p[47].m_pComponent;
      goto LABEL_71;
    }
    if ( (v26 & 0x8000u) == 0 )
    {
      if ( (v26 >> 13) & 1 )
      {
        v30 = v6->mComponentTableEntryCount;
        v31 = v6->m_Components.size;
        if ( v30 < v31 )
        {
          do
          {
            v29 = (signed __int64)&v6->m_Components.p[v30];
            if ( (*(_DWORD *)(v29 + 8) & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
              && !(UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v29 + 8) & 0x1FFFFFF) )
            {
              goto LABEL_56;
            }
          }
          while ( ++v30 < v31 );
        }
      }
      else
      {
        if ( !((v26 >> 12) & 1) )
        {
          v14 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v6->vfptr,
                                              UFG::AimingBaseComponent::_TypeUID);
          v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
LABEL_71:
          if ( v14 )
          {
            v25 = v14->m_vAimIntentionTargetPosition.x;
            v24 = v14->m_vAimIntentionTargetPosition.y;
            v34 = 1;
            goto LABEL_230;
          }
LABEL_73:
          if ( v15 )
            goto LABEL_229;
          if ( !v5 )
          {
LABEL_140:
            if ( !(_BYTE)retaddr )
              return;
            v60 = v6->m_Flags;
            if ( (v60 >> 14) & 1 )
            {
              v61 = v6->m_Components.p[20].m_pComponent;
              if ( !v61
                || (UFG::TargetingSystemPedPlayerComponent::_TypeUID ^ v61->m_TypeUID) & 0xFE000000
                || UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF )
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
                v67 = v6->m_Flags;
                if ( (v67 >> 14) & 1 )
                {
                  v68 = v6->m_Components.p[47].m_pComponent;
                  if ( !v68
                    || (UFG::AimingPlayerComponent::_TypeUID ^ v68->m_TypeUID) & 0xFE000000
                    || UFG::AimingPlayerComponent::_TypeUID & ~v68->m_TypeUID & 0x1FFFFFF )
                  {
                    goto LABEL_171;
                  }
LABEL_195:
                  if ( v68 )
                  {
                    v77 = *(float *)&v68[9].m_Flags;
                    v78 = (__m128)v68[9].m_NameUID;
                    v79 = v78;
                    v79.m128_f32[0] = (float)((float)(v78.m128_f32[0] * v78.m128_f32[0]) + (float)(v77 * v77))
                                    + (float)(*(float *)(&v68[9].m_SimObjIndex + 1)
                                            * *(float *)(&v68[9].m_SimObjIndex + 1));
                    v80 = UFG::AimingPlayerComponent::ms_fFreeAimFocusRange / COERCE_FLOAT(_mm_sqrt_ps(v79));
                    v24 = (float)(v77 * v80) + *(float *)&v68[9].m_SafePointerList.mNode.mPrev;
                    v25 = (float)(v78.m128_f32[0] * v80) + *((float *)&v68[9].vfptr + 1);
                    goto LABEL_229;
                  }
                  goto LABEL_197;
                }
                if ( (v67 & 0x8000u) == 0 )
                {
                  if ( (v67 >> 13) & 1 )
                  {
                    v73 = v6->mComponentTableEntryCount;
                    v74 = v6->m_Components.size;
                    if ( v73 < v74 )
                    {
                      v71 = v6->m_Components.p;
                      do
                      {
                        v72 = v73;
                        if ( (v71[v73].m_TypeUID & 0xFE000000) == (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
                          && !(UFG::AimingPlayerComponent::_TypeUID & ~v71[v73].m_TypeUID & 0x1FFFFFF) )
                        {
                          goto LABEL_179;
                        }
                      }
                      while ( ++v73 < v74 );
                    }
                  }
                  else
                  {
                    if ( !((v67 >> 12) & 1) )
                    {
                      v68 = UFG::SimObject::GetComponentOfType(
                              (UFG::SimObject *)&v6->vfptr,
                              UFG::AimingPlayerComponent::_TypeUID);
                      goto LABEL_195;
                    }
                    v75 = v6->mComponentTableEntryCount;
                    v76 = v6->m_Components.size;
                    if ( v75 < v76 )
                    {
                      v71 = v6->m_Components.p;
                      do
                      {
                        v72 = v75;
                        if ( (v71[v75].m_TypeUID & 0xFE000000) == (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
                          && !(UFG::AimingPlayerComponent::_TypeUID & ~v71[v75].m_TypeUID & 0x1FFFFFF) )
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
                  v69 = v6->mComponentTableEntryCount;
                  v70 = v6->m_Components.size;
                  if ( v69 < v70 )
                  {
                    v71 = v6->m_Components.p;
                    while ( 1 )
                    {
                      v72 = v69;
                      if ( (v71[v69].m_TypeUID & 0xFE000000) == (UFG::AimingPlayerComponent::_TypeUID & 0xFE000000)
                        && !(UFG::AimingPlayerComponent::_TypeUID & ~v71[v69].m_TypeUID & 0x1FFFFFF) )
                      {
                        break;
                      }
                      if ( ++v69 >= v70 )
                        goto LABEL_171;
                    }
LABEL_179:
                    v68 = v71[v72].m_pComponent;
                    goto LABEL_195;
                  }
                }
LABEL_171:
                v68 = 0i64;
                goto LABEL_195;
              }
              v83 = v6->m_Flags;
              if ( (v83 >> 14) & 1 )
              {
                v84 = v6->m_Components.p[21].m_pComponent;
                if ( v84 && !((v18 ^ v84->m_TypeUID) & 0xFE000000) && !(v18 & ~v84->m_TypeUID & 0x1FFFFFF) )
                  goto LABEL_224;
                goto LABEL_202;
              }
              if ( (v83 & 0x8000u) != 0 )
              {
                v84 = v6->m_Components.p[21].m_pComponent;
                if ( v84 && !((v18 ^ v84->m_TypeUID) & 0xFE000000) )
                {
                  if ( v18 & ~v84->m_TypeUID & 0x1FFFFFF )
                    v84 = 0i64;
                  goto LABEL_224;
                }
                goto LABEL_202;
              }
              if ( (v83 >> 13) & 1 )
              {
                v85 = v6->mComponentTableEntryCount;
                v86 = v6->m_Components.size;
                if ( v85 >= v86 )
                {
LABEL_202:
                  v84 = 0i64;
LABEL_224:
                  if ( v84 )
                  {
                    v81 = *(float *)&v84[2].m_TypeUID;
                    v25 = v13->mWorldTransform.v3.x + *((float *)&v84[2].m_SafePointerList.mNode.mNext + 1);
LABEL_228:
                    v24 = v81 + v13->mWorldTransform.v3.y;
                    goto LABEL_229;
                  }
                  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
                  v81 = v13->mWorldTransform.v0.y;
                  v82 = v13->mWorldTransform.v0.x;
LABEL_227:
                  v25 = v82 + v13->mWorldTransform.v3.x;
                  goto LABEL_228;
                }
                v87 = v6->m_Components.p;
                while ( 1 )
                {
                  v88 = v85;
                  if ( (v87[v85].m_TypeUID & 0xFE000000) == (v18 & 0xFE000000)
                    && !(v18 & ~v87[v85].m_TypeUID & 0x1FFFFFF) )
                  {
                    break;
                  }
                  if ( ++v85 >= v86 )
                    goto LABEL_202;
                }
              }
              else
              {
                if ( !((v83 >> 12) & 1) )
                {
                  v84 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, v18);
                  goto LABEL_224;
                }
                v89 = v6->mComponentTableEntryCount;
                v90 = v6->m_Components.size;
                if ( v89 >= v90 )
                  goto LABEL_202;
                v87 = v6->m_Components.p;
                while ( 1 )
                {
                  v88 = v89;
                  if ( (v87[v89].m_TypeUID & 0xFE000000) == (v18 & 0xFE000000)
                    && !(v18 & ~v87[v89].m_TypeUID & 0x1FFFFFF) )
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
            if ( (v60 & 0x8000u) != 0 )
            {
              v61 = v6->m_Components.p[20].m_pComponent;
              if ( !v61 || (UFG::TargetingSystemPedPlayerComponent::_TypeUID ^ v61->m_TypeUID) & 0xFE000000 )
                goto LABEL_145;
              if ( UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF )
                v61 = 0i64;
              goto LABEL_165;
            }
            if ( (v60 >> 13) & 1 )
            {
              v62 = v6->mComponentTableEntryCount;
              v63 = v6->m_Components.size;
              if ( v62 < v63 )
              {
                while ( 1 )
                {
                  v64 = (signed __int64)&v6->m_Components.p[v62];
                  if ( (*(_DWORD *)(v64 + 8) & 0xFE000000) == (UFG::TargetingSystemPedPlayerComponent::_TypeUID & 0xFE000000)
                    && !(UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) )
                  {
                    break;
                  }
                  if ( ++v62 >= v63 )
                    goto LABEL_145;
                }
LABEL_157:
                v61 = *(UFG::SimComponent **)v64;
                goto LABEL_165;
              }
            }
            else
            {
              if ( !((v60 >> 12) & 1) )
              {
                v61 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v6->vfptr,
                        UFG::TargetingSystemPedPlayerComponent::_TypeUID);
                v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                goto LABEL_165;
              }
              v65 = v6->mComponentTableEntryCount;
              v66 = v6->m_Components.size;
              if ( v65 < v66 )
              {
                do
                {
                  v64 = (signed __int64)&v6->m_Components.p[v65];
                  if ( (*(_DWORD *)(v64 + 8) & 0xFE000000) == (UFG::TargetingSystemPedPlayerComponent::_TypeUID & 0xFE000000)
                    && !(UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~*(_DWORD *)(v64 + 8) & 0x1FFFFFF) )
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
          v35 = (float *)v5->m_pTransformNodeComponent;
          if ( v35 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v5->m_pTransformNodeComponent);
            v25 = v35[44];
            v24 = v35[45];
            v36 = v35[46];
            if ( v4->mUID == -1 )
              goto LABEL_106;
            v37 = v5->m_Flags;
            if ( (v37 >> 14) & 1 )
            {
              v38 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
              if ( v38
                && !((UFG::CharacterAnimationComponent::_TypeUID ^ v38->m_TypeUID) & 0xFE000000)
                && !(UFG::CharacterAnimationComponent::_TypeUID & ~v38->m_TypeUID & 0x1FFFFFF) )
              {
                goto LABEL_99;
              }
              goto LABEL_81;
            }
            if ( (v37 & 0x8000u) != 0 )
            {
              v38 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
              if ( v38 && !((UFG::CharacterAnimationComponent::_TypeUID ^ v38->m_TypeUID) & 0xFE000000) )
              {
                if ( UFG::CharacterAnimationComponent::_TypeUID & ~v38->m_TypeUID & 0x1FFFFFF )
                  v38 = 0i64;
                goto LABEL_99;
              }
              goto LABEL_81;
            }
            if ( (v37 >> 13) & 1 )
            {
              v39 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v5);
            }
            else
            {
              if ( (v37 >> 12) & 1 )
              {
                v40 = v5->mComponentTableEntryCount;
                v41 = v5->m_Components.size;
                if ( v40 < v41 )
                {
                  v42 = v5->m_Components.p;
                  while ( 1 )
                  {
                    v43 = (signed __int64)&v42[v40];
                    if ( (*(_DWORD *)(v43 + 8) & 0xFE000000) == (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                      && !(UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v43 + 8) & 0x1FFFFFF) )
                    {
                      break;
                    }
                    if ( ++v40 >= v41 )
                      goto LABEL_81;
                  }
                  v38 = *(UFG::CharacterAnimationComponent **)v43;
                  goto LABEL_99;
                }
LABEL_81:
                v38 = 0i64;
                goto LABEL_99;
              }
              v39 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v5->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
            v38 = v39;
LABEL_99:
            if ( v38 )
              v44 = v38->mCreature;
            else
              v44 = 0i64;
            if ( v44 )
            {
              if ( v44->mPose.mRigHandle.mData )
              {
                v45 = Skeleton::GetBoneID(v44->mPose.mRigHandle.mUFGSkeleton, v4->mUID);
                if ( v45 >= 0 )
                {
                  Creature::GetTransform(v44, v45, &transform);
                  v25 = source.z;
                  v24 = v119;
                  v36 = transform.v0.x;
                }
              }
            }
LABEL_106:
            v46 = fsqrt(
                    (float)((float)((float)(v25 - v13->mWorldTransform.v3.x) * (float)(v25 - v13->mWorldTransform.v3.x))
                          + (float)((float)(v24 - v13->mWorldTransform.v3.y) * (float)(v24 - v13->mWorldTransform.v3.y)))
                  + (float)((float)(v36 - v13->mWorldTransform.v3.z) * (float)(v36 - v13->mWorldTransform.v3.z)));
            if ( v123 < 0.0 || v46 <= v123 )
              goto LABEL_229;
LABEL_139:
            v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
            goto LABEL_140;
          }
          v47 = v5->m_Flags;
          if ( (v47 >> 14) & 1 )
          {
            v48 = v5->mComponentTableEntryCount;
            v49 = v5->m_Components.size;
            if ( v48 < v49 )
            {
              while ( 1 )
              {
                v50 = (signed __int64)&v5->m_Components.p[v48];
                if ( (*(_DWORD *)(v50 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                  && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v48 >= v49 )
                  goto LABEL_116;
              }
LABEL_115:
              v51 = *(UFG::RigidBody **)v50;
LABEL_136:
              if ( !v51 )
                goto LABEL_140;
              UFG::RigidBody::GetTransform(v51, &transform);
              v25 = source.z;
              v24 = v119;
              v58 = (__m128)LODWORD(v119);
              v58.m128_f32[0] = (float)((float)((float)(v119 - v13->mWorldTransform.v3.y)
                                              * (float)(v119 - v13->mWorldTransform.v3.y))
                                      + (float)((float)(source.z - v13->mWorldTransform.v3.x)
                                              * (float)(source.z - v13->mWorldTransform.v3.x)))
                              + (float)((float)(transform.v0.x - v13->mWorldTransform.v3.z)
                                      * (float)(transform.v0.x - v13->mWorldTransform.v3.z));
              LODWORD(v59) = (unsigned __int128)_mm_sqrt_ps(v58);
              if ( v123 < 0.0 || v59 <= v123 )
                goto LABEL_229;
              goto LABEL_139;
            }
          }
          else if ( (v47 & 0x8000u) == 0 )
          {
            if ( (v47 >> 13) & 1 )
            {
              v54 = v5->mComponentTableEntryCount;
              v55 = v5->m_Components.size;
              if ( v54 < v55 )
              {
                do
                {
                  v50 = (signed __int64)&v5->m_Components.p[v54];
                  if ( (*(_DWORD *)(v50 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                    && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) )
                  {
                    goto LABEL_115;
                  }
                }
                while ( ++v54 < v55 );
              }
            }
            else
            {
              if ( !((v47 >> 12) & 1) )
              {
                v51 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v5->vfptr,
                                          UFG::RigidBodyComponent::_TypeUID);
                v18 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                goto LABEL_136;
              }
              v56 = v5->mComponentTableEntryCount;
              v57 = v5->m_Components.size;
              if ( v56 < v57 )
              {
                do
                {
                  v50 = (signed __int64)&v5->m_Components.p[v56];
                  if ( (*(_DWORD *)(v50 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                    && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) )
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
            v52 = v5->mComponentTableEntryCount;
            v53 = v5->m_Components.size;
            if ( v52 < v53 )
            {
              do
              {
                v50 = (signed __int64)&v5->m_Components.p[v52];
                if ( (*(_DWORD *)(v50 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                  && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF) )
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
        v32 = v6->mComponentTableEntryCount;
        v33 = v6->m_Components.size;
        if ( v32 < v33 )
        {
          do
          {
            v29 = (signed __int64)&v6->m_Components.p[v32];
            if ( (*(_DWORD *)(v29 + 8) & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
              && !(UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v29 + 8) & 0x1FFFFFF) )
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
      v27 = v6->mComponentTableEntryCount;
      v28 = v6->m_Components.size;
      if ( v27 < v28 )
      {
        while ( 1 )
        {
          v29 = (signed __int64)&v6->m_Components.p[v27];
          if ( (*(_DWORD *)(v29 + 8) & 0xFE000000) == (UFG::AimingBaseComponent::_TypeUID & 0xFE000000)
            && !(UFG::AimingBaseComponent::_TypeUID & ~*(_DWORD *)(v29 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v27 >= v28 )
            goto LABEL_57;
        }
LABEL_56:
        v14 = *(UFG::AimingBaseComponent **)v29;
        goto LABEL_71;
      }
    }
LABEL_57:
    v14 = 0i64;
    goto LABEL_71;
  }
  v25 = *v127;
  v24 = v127[1];
LABEL_229:
  v34 = 0;
LABEL_230:
  v91 = v24 - v13->mWorldTransform.v3.y;
  v92 = v25 - v13->mWorldTransform.v3.x;
  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
  v93 = v13->mWorldTransform.v0.y;
  v94 = v13->mWorldTransform.v0.z;
  dest.x = v13->mWorldTransform.v0.x;
  dest.y = v93;
  dest.z = v94;
  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
  v95 = v13->mWorldTransform.v1.x;
  v96 = v13->mWorldTransform.v1.y;
  v116.x = v13->mWorldTransform.v1.x;
  v116.y = v96;
  v97 = 0.0;
  dest.z = 0.0;
  v98 = 0.0;
  v116.z = 0.0;
  v99 = radians;
  *(float *)&v100 = radians;
  if ( radians < 0.0 )
    v100 = LODWORD(radians) ^ _xmm[0];
  if ( *(float *)&v100 >= 0.001 )
  {
    source.x = dest.x;
    source.y = dest.y;
    source.z = 0.0;
    v117.m_vec.m_quad.m128_f32[0] = v95;
    *(unsigned __int64 *)((char *)v117.m_vec.m_quad.m128_u64 + 4) = LODWORD(v96);
    UFG::qRotateVectorZ(&dest, &source, radians);
    UFG::qRotateVectorZ(&v116, (UFG::qVector3 *)&v117, v99);
    v97 = dest.z;
    v98 = v116.z;
    v96 = v116.y;
    v95 = v116.x;
  }
  v101 = (float)(v92 * v92) + (float)(v91 * v91);
  v102 = *(float *)&FLOAT_1_0;
  if ( v101 == 0.0 )
    v103 = 0.0;
  else
    v103 = 1.0 / fsqrt(v101);
  v104 = (__m128)LODWORD(dest.y);
  v105 = v104;
  v105.m128_f32[0] = (float)((float)(v104.m128_f32[0] * v104.m128_f32[0]) + (float)(dest.x * dest.x))
                   + (float)(v97 * v97);
  v106 = 0.0;
  if ( v105.m128_f32[0] != 0.0 )
    v106 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v105));
  v107 = (float)((float)((float)(dest.x * v106) * (float)(v92 * v103))
               + (float)((float)(v103 * v91) * (float)(dest.y * v106)))
       + (float)((float)(v103 * 0.0) * (float)(v106 * v97));
  if ( v107 <= -1.0 )
  {
    v107 = FLOAT_N1_0;
  }
  else if ( v107 >= 1.0 )
  {
    goto LABEL_244;
  }
  v102 = v107;
LABEL_244:
  v108 = acosf(v102);
  if ( v108 <= 0.0 )
    v108 = 0.0;
  if ( v108 >= v122 )
    v108 = v122;
  if ( (float)((float)((float)(v95 * v92) + (float)(v96 * v91)) + (float)(v98 * 0.0)) < 0.0 )
    LODWORD(v108) ^= _xmm[0];
  v109 = *(Creature **)(v121 + 152);
  if ( v109 )
  {
    if ( !(_S46 & 1) )
    {
      _S46 |= 1u;
      UP.m_quad = _xmm;
    }
    hkQuaternionf::setAxisAngle(&v117, &UP, v108);
    Creature::GetPositionhkQ(v109, (hkQsTransformf *)&transform);
    v110 = _mm_shuffle_ps((__m128)transform.v1, (__m128)transform.v1, 255);
    v111 = _mm_shuffle_ps(v117.m_vec.m_quad, v117.m_vec.m_quad, 255);
    v112 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v117.m_vec.m_quad, v117.m_vec.m_quad, 201), (__m128)transform.v1),
             _mm_mul_ps(_mm_shuffle_ps((__m128)transform.v1, (__m128)transform.v1, 201), v117.m_vec.m_quad));
    v113 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v112, v112, 201), _mm_mul_ps(v117.m_vec.m_quad, v110)),
             _mm_mul_ps((__m128)transform.v1, v111));
    v114 = _mm_mul_ps(v117.m_vec.m_quad, (__m128)transform.v1);
    transform.v1 = (UFG::qVector4)_mm_shuffle_ps(
                                    v113,
                                    _mm_unpackhi_ps(
                                      v113,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v111, v110),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                                          _mm_shuffle_ps(v114, v114, 170)))),
                                    196);
    Creature::SetPositionhkQ(v109, (hkQsTransformf *)&transform);
  }
  if ( v34 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v13);
    UFG::qTranspose(&transform, &v13->mWorldTransform);
    UFG::AimingBaseComponent::UpdateLocalAimDirection(v14, &transform, &v14->m_vAimPosition);
  }
}

