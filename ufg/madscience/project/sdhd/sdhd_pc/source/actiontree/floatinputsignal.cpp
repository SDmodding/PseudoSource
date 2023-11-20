// File Line: 98
// RVA: 0x1483CA0
__int64 dynamic_initializer_for__floatInputSignalEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&floatInputSignalEnum, gFloatInputSignalStringList, 43, 0i64);
  return atexit(dynamic_atexit_destructor_for__floatInputSignalEnum__);
}

// File Line: 109
// RVA: 0x273E80
float __fastcall getSignalFromDirection(UFG::qVector3 *desiredDirection, UFG::qVector3 *currentFacing, float threshold)
{
  float v3; // xmm6_4
  float v4; // xmm7_4
  UFG::qVector3 *v5; // rbx
  int v6; // xmm9_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm9_4

  v3 = currentFacing->y;
  v4 = currentFacing->z;
  v5 = desiredDirection;
  v6 = LODWORD(currentFacing->x) ^ _xmm[0];
  v7 = UFG::qAngleBetween(desiredDirection, currentFacing);
  v8 = v7;
  v9 = (float)((float)(*(float *)&v6 * v5->y) + (float)(v3 * v5->x)) + (float)(v4 * v5->z);
  if ( v7 >= threshold )
    return 0.0;
  if ( v7 <= 0.0 )
  {
    v8 = 0.0;
  }
  else if ( v7 >= 6.2831855 )
  {
    v8 = FLOAT_6_2831855;
  }
  if ( v9 < 0.0 )
    v8 = 6.2831855 - v8;
  if ( v8 <= 0.0 )
  {
    v8 = 0.0;
LABEL_13:
    if ( v8 < 0.0 )
      v8 = v8 + 6.2831855;
    return v8;
  }
  if ( v8 < 6.2831855 )
    goto LABEL_13;
  return FLOAT_6_2831855;
}

// File Line: 139
// RVA: 0x148A560
__int64 dynamic_initializer_for__uPoseDriverTest_SignalUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PoseDriverTest_Signal", 0xFFFFFFFF);
  uPoseDriverTest_SignalUID = result;
  return result;
}

// File Line: 141
// RVA: 0x273F50
float __usercall getSignalValue@<xmm0>(UFG::SimObject *pSimObject@<rcx>, FloatInputSignal floatInputSignal@<edx>, float timeDelta@<xmm2>, float activeRange@<xmm3>, __int64 a5@<rdi>, UFG::qVector3 *relativeStartVector)
{
  UFG::SimObjectCVBase *v6; // rbx
  FloatInputSignal v7; // esi
  float v8; // xmm6_4
  float v9; // xmm8_4
  unsigned __int16 v10; // cx
  UFG::AICharacterControllerBaseComponent *v11; // rax
  UFG::AICharacterControllerBaseComponent *v12; // rdi
  UFG::TransformNodeComponent *v13; // rbx
  unsigned __int16 v14; // cx
  UFG::AICharacterControllerBaseComponent *v15; // rax
  UFG::qVector3 *v16; // rcx
  unsigned __int16 v17; // cx
  UFG::AICharacterControllerBaseComponent *v18; // rax
  unsigned __int16 v19; // cx
  UFG::AICharacterControllerBaseComponent *v20; // rax
  float v21; // xmm0_4
  bool v22; // cf
  bool v23; // zf
  unsigned __int16 v24; // cx
  UFG::AimingBaseComponent *v25; // rax
  unsigned __int16 v26; // cx
  UFG::AimingBaseComponent *v27; // rax
  unsigned __int16 v28; // cx
  UFG::AimingBaseComponent *v29; // rax
  unsigned __int16 v30; // cx
  UFG::AimingBaseComponent *v31; // rax
  UFG::TransformNodeComponent *v32; // rdi
  UFG::TransformNodeComponent *v33; // rdi
  unsigned __int16 v34; // cx
  UFG::CharacterAnimationComponent *v35; // rax
  Creature *v36; // rcx
  float v37; // xmm1_4
  float v38; // xmm0_4
  __int64 v39; // rdi
  UFG::TransformNodeComponent *v40; // rsi
  unsigned __int16 v41; // cx
  UFG::SimComponent *v42; // rdx
  UFG::SimComponent *v43; // rax
  __int64 v44; // rdx
  unsigned __int16 v45; // cx
  UFG::CharacterOccupantComponent *v46; // rax
  UFG::VehicleOccupantComponent *v47; // rax
  float *v48; // rbx
  float v49; // xmm5_4
  __m128 v50; // xmm4
  __m128 v51; // xmm1
  float v52; // xmm2_4
  float v53; // xmm0_4
  unsigned __int16 v54; // cx
  UFG::CharacterOccupantComponent *v55; // rax
  UFG::SimObjectGame *v56; // rax
  unsigned __int16 v57; // dx
  UFG::SimComponent *v58; // rax
  float v59; // xmm2_4
  unsigned __int16 v60; // cx
  UFG::SimComponent *v61; // rdx
  UFG::SimComponent *v62; // rax
  __int64 v63; // rdi
  __int64 v64; // rdi
  UFG::TransformNodeComponent *v65; // rbx
  float v66; // xmm3_4
  __m128 v67; // xmm4
  float v68; // xmm5_4
  __m128 v69; // xmm2
  float v70; // xmm1_4
  float v71; // xmm0_4
  unsigned __int16 v72; // cx
  UFG::SimComponent *v73; // rdx
  UFG::SimComponent *v74; // rax
  UFG::SimObject *v75; // rcx
  unsigned __int16 v76; // cx
  UFG::SimComponent *v77; // rax
  unsigned __int16 v78; // cx
  UFG::SimObjectCharacterPropertiesComponent *v79; // rax
  UFG::InputActionData *v80; // rcx
  UFG::InputActionData *v81; // rcx
  UFG::InputActionData *v82; // rcx
  UFG::InputActionData *v83; // rcx
  UFG::InputActionData *v84; // rcx
  UFG::InputActionData *v85; // rcx
  UFG::InputActionData *v86; // rcx
  unsigned __int16 v87; // cx
  unsigned __int16 v88; // cx
  UFG::SimComponent *v89; // rax
  unsigned __int16 v90; // cx
  UFG::SimComponent *v91; // rax
  unsigned __int16 v92; // cx
  UFG::SimComponent *v93; // rax
  UFG::SimObjectGame *v94; // rdi
  unsigned __int16 v95; // cx
  UFG::SimComponent *v96; // rdx
  UFG::SimComponent *v97; // rax
  unsigned __int16 v98; // cx
  UFG::SimComponent *v99; // rax
  UFG::SceneObjectProperties *v100; // rax
  unsigned int v101; // esi
  UFG::SimObject *v102; // rax
  unsigned __int16 v103; // dx
  UFG::SimComponent *v104; // rax
  unsigned __int16 v105; // cx
  unsigned __int16 v106; // cx
  UFG::CharacterAnimationComponent *v107; // rax
  Creature *v108; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *v109; // rax
  signed __int64 v110; // rcx
  signed __int64 v111; // rax
  float v112; // xmm0_4
  unsigned __int16 v113; // cx
  UFG::SimComponent *v114; // rax
  float v115; // xmm1_4
  float v116; // xmm0_4
  float v117; // xmm1_4
  float v118; // xmm0_4
  unsigned __int16 v119; // cx
  UFG::CharacterAnimationComponent *v120; // rax
  unsigned __int16 v121; // cx
  UFG::CharacterAnimationComponent *v122; // rdi
  UFG::SimComponent *v123; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v124; // rax
  Creature *v125; // rcx
  float v126; // xmm7_4
  __m128 v127; // xmm6
  float v128; // xmm7_4
  UFG::TransformNodeComponent *v129; // rbx
  float v130; // xmm1_4
  float v131; // xmm0_4
  UFG::qVector3 v133; // [rsp+28h] [rbp-51h]
  UFG::qVector3 desiredDirection; // [rsp+38h] [rbp-41h]
  int v135; // [rsp+48h] [rbp-31h]
  UFG::qMatrix44 transform; // [rsp+58h] [rbp-21h]
  __int64 v137; // [rsp+E0h] [rbp+67h]
  UFG::qVector3 *currentFacing; // [rsp+F8h] [rbp+7Fh]

  v6 = (UFG::SimObjectCVBase *)pSimObject;
  v7 = floatInputSignal;
  v8 = 0.0;
  v9 = activeRange;
  v137 = a5;
  switch ( floatInputSignal )
  {
    case 1:
      if ( pSimObject )
      {
        v10 = pSimObject->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
          {
            v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v6->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
          else if ( (v10 >> 12) & 1 )
          {
            v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v6->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
          else
          {
            v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v6->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
        }
        else
        {
          v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
        }
        v12 = v11;
        if ( v11 )
        {
          v13 = v6->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(v13);
          v8 = getSignalFromDirection(
                 &v12->m_Intention.mMotionIntentionDirection,
                 (UFG::qVector3 *)&v13->mWorldTransform,
                 activeRange);
        }
      }
      return v8;
    case 2:
      if ( pSimObject )
      {
        v14 = pSimObject->m_Flags;
        if ( (v14 >> 14) & 1 )
        {
          v15 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
        }
        else if ( (v14 & 0x8000u) == 0 )
        {
          if ( (v14 >> 13) & 1 )
            v15 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v6->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          else
            v15 = (UFG::AICharacterControllerBaseComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  (UFG::SimObjectGame *)&v6->vfptr,
                                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
        }
        else
        {
          v15 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
        }
        if ( v15 )
        {
          v16 = &v15->m_Intention.mMotionIntentionDirection;
          return getSignalFromDirection(v16, currentFacing, activeRange);
        }
      }
      return v8;
    case 3:
      if ( pSimObject )
      {
        v17 = pSimObject->m_Flags;
        if ( (v17 >> 14) & 1 )
        {
          v18 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
        }
        else if ( (v17 & 0x8000u) == 0 )
        {
          if ( (v17 >> 13) & 1 )
            v18 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v6->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          else
            v18 = (UFG::AICharacterControllerBaseComponent *)((v17 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  (UFG::SimObjectGame *)&v6->vfptr,
                                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
        }
        else
        {
          v18 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
        }
        if ( v18 )
          v8 = v18->m_Intention.mMotionIntentionSpeed;
      }
      return v8;
    case 4:
      if ( pSimObject )
      {
        v19 = pSimObject->m_Flags;
        if ( (v19 >> 14) & 1 )
        {
          v20 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
        }
        else if ( (v19 & 0x8000u) == 0 )
        {
          if ( (v19 >> 13) & 1 )
            v20 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v6->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          else
            v20 = (UFG::AICharacterControllerBaseComponent *)((v19 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  (UFG::SimObjectGame *)&v6->vfptr,
                                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
        }
        else
        {
          v20 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
        }
        if ( v20 && sKillRotSpeed )
        {
          v21 = v20->m_Intention.mCurrentRotationSignal;
          v22 = v21 < 0.0;
          v23 = v21 == 0.0;
          if ( v21 < 0.0 )
          {
            v21 = v21 + 6.2831855;
            v22 = v21 < 0.0;
            v23 = v21 == 0.0;
          }
          if ( !v22 && !v23 )
          {
            v8 = v21;
            if ( v21 >= 6.2831855 )
              v8 = FLOAT_6_2831855;
          }
        }
      }
      return v8;
    case 5:
      if ( pSimObject )
      {
        v24 = pSimObject->m_Flags;
        if ( (v24 >> 14) & 1 )
        {
          v25 = (UFG::AimingBaseComponent *)v6->m_Components.p[47].m_pComponent;
        }
        else if ( (v24 & 0x8000u) == 0 )
        {
          if ( (v24 >> 13) & 1 )
            v25 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v6->vfptr,
                                                UFG::AimingBaseComponent::_TypeUID);
          else
            v25 = (UFG::AimingBaseComponent *)((v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v6->vfptr,
                                                                   UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AimingBaseComponent::_TypeUID));
        }
        else
        {
          v25 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v6->vfptr,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
        if ( v25 )
          v8 = UFG::AimingBaseComponent::GetLocalAimDirectionXY(v25);
      }
      return v8;
    case 6:
      if ( pSimObject )
      {
        v26 = pSimObject->m_Flags;
        if ( (v26 >> 14) & 1 )
        {
          v27 = (UFG::AimingBaseComponent *)v6->m_Components.p[47].m_pComponent;
        }
        else if ( (v26 & 0x8000u) == 0 )
        {
          if ( (v26 >> 13) & 1 )
            v27 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v6->vfptr,
                                                UFG::AimingBaseComponent::_TypeUID);
          else
            v27 = (UFG::AimingBaseComponent *)((v26 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v6->vfptr,
                                                                   UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AimingBaseComponent::_TypeUID));
        }
        else
        {
          v27 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v6->vfptr,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
        if ( v27 )
          v8 = UFG::AimingBaseComponent::GetLocalAimDirectionXZ(v27);
      }
      return v8;
    case 7:
      if ( pSimObject )
      {
        v28 = pSimObject->m_Flags;
        if ( (v28 >> 14) & 1 )
        {
          v29 = (UFG::AimingBaseComponent *)v6->m_Components.p[47].m_pComponent;
        }
        else if ( (v28 & 0x8000u) == 0 )
        {
          if ( (v28 >> 13) & 1 )
            v29 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v6->vfptr,
                                                UFG::AimingBaseComponent::_TypeUID);
          else
            v29 = (UFG::AimingBaseComponent *)((v28 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v6->vfptr,
                                                                   UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AimingBaseComponent::_TypeUID));
        }
        else
        {
          v29 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v6->vfptr,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
        if ( v29 )
          v8 = UFG::AimingBaseComponent::GetLocalAimDirectionXYRelCover(v29);
      }
      return v8;
    case 8:
      if ( pSimObject )
      {
        v30 = pSimObject->m_Flags;
        if ( (v30 >> 14) & 1 )
        {
          v31 = (UFG::AimingBaseComponent *)v6->m_Components.p[47].m_pComponent;
        }
        else if ( (v30 & 0x8000u) == 0 )
        {
          if ( (v30 >> 13) & 1 )
            v31 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v6->vfptr,
                                                UFG::AimingBaseComponent::_TypeUID);
          else
            v31 = (UFG::AimingBaseComponent *)((v30 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v6->vfptr,
                                                                   UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AimingBaseComponent::_TypeUID));
        }
        else
        {
          v31 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v6->vfptr,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
        if ( v31 )
          v8 = UFG::AimingBaseComponent::GetLocalAimDirectionXYRelSyncBone(v31);
      }
      return v8;
    case 9:
    case 11:
      if ( pSimObject )
        v32 = pSimObject->m_pTransformNodeComponent;
      else
        v32 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v32);
      v16 = (UFG::qVector3 *)&v32->mWorldTransform;
      return getSignalFromDirection(v16, currentFacing, activeRange);
    case 10:
      if ( pSimObject )
        v33 = pSimObject->m_pTransformNodeComponent;
      else
        v33 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v33);
      if ( v6 )
      {
        v34 = v6->m_Flags;
        if ( (v34 >> 14) & 1 )
        {
          v35 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
        }
        else if ( (v34 & 0x8000u) == 0 )
        {
          if ( (v34 >> 13) & 1 )
            v35 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v6);
          else
            v35 = (UFG::CharacterAnimationComponent *)((v34 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v6->vfptr,
                                                                           UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
        }
        else
        {
          v35 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
        }
        if ( v35 )
        {
          v36 = v35->mCreature;
          if ( v36 )
          {
            Creature::GetTransform(v36, 3, &transform);
            v37 = transform.v0.y;
            currentFacing->x = transform.v0.x;
            v38 = transform.v0.z;
            currentFacing->y = v37;
            currentFacing->z = v38;
          }
        }
      }
      return getSignalFromDirection((UFG::qVector3 *)&v33->mWorldTransform, currentFacing, activeRange);
    case 12:
      v39 = 0i64;
      if ( pSimObject )
      {
        v41 = pSimObject->m_Flags;
        v40 = v6->m_pTransformNodeComponent;
        if ( (v41 >> 14) & 1 )
        {
          v42 = v6->m_Components.p[20].m_pComponent;
        }
        else if ( (v41 & 0x8000u) == 0 )
        {
          if ( (v41 >> 13) & 1 )
          {
            v43 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v41 >> 12) & 1 )
          {
            v43 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v43 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v6->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v42 = v43;
        }
        else
        {
          v42 = v6->m_Components.p[20].m_pComponent;
        }
        if ( v42 )
        {
          v44 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v42[1].m_Flags + 34i64)
                          + *(_QWORD *)&v42[1].m_TypeUID
                          + 40);
          if ( v44 )
            v39 = *(_QWORD *)(v44 + 88);
        }
      }
      else
      {
        v40 = 0i64;
      }
      if ( v40 && v39 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v40);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v39);
        v8 = getSignalFromDirection((UFG::qVector3 *)&v40->mWorldTransform, (UFG::qVector3 *)(v39 + 128), activeRange);
      }
      return v8;
    case 15:
      if ( pSimObject )
      {
        v45 = pSimObject->m_Flags;
        if ( (v45 >> 14) & 1 )
        {
          v46 = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent;
        }
        else if ( (v45 & 0x8000u) == 0 )
        {
          if ( (v45 >> 13) & 1 )
            v46 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v6->vfptr,
                                                       UFG::CharacterOccupantComponent::_TypeUID);
          else
            v46 = (UFG::CharacterOccupantComponent *)((v45 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v6->vfptr,
                                                                          UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
        }
        else
        {
          v46 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v6->vfptr,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        if ( v46 )
        {
          v47 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v46);
          if ( v47 )
          {
            v48 = (float *)v47->mpDriver.mPrev;
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v47->mpDriver.mPrev);
            v50 = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
            v49 = (float)((float)(UFG::qVector3::msDirUp.y * v48[41]) + (float)(UFG::qVector3::msDirUp.x * v48[40]))
                + (float)(UFG::qVector3::msDirUp.z * v48[42]);
            v50.m128_f32[0] = (float)((float)(UFG::qVector3::msDirUp.y * v48[37])
                                    + (float)(UFG::qVector3::msDirUp.x * v48[36]))
                            + (float)(UFG::qVector3::msDirUp.z * v48[38]);
            v51 = v50;
            v51.m128_f32[0] = (float)(v50.m128_f32[0] * v50.m128_f32[0]) + (float)(v49 * v49);
            if ( v51.m128_f32[0] == 0.0 )
              v52 = 0.0;
            else
              v52 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v51));
            v53 = atan2f(v52 * v50.m128_f32[0], v52 * v49);
            if ( v53 < 0.0 )
              v53 = v53 + 6.2831855;
            v8 = v53;
          }
        }
      }
      return v8;
    case 17:
      if ( !pSimObject )
        return v8;
      v54 = pSimObject->m_Flags;
      if ( (v54 >> 14) & 1 )
      {
        v55 = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent;
      }
      else if ( (v54 & 0x8000u) == 0 )
      {
        if ( (v54 >> 13) & 1 )
          v55 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v6->vfptr,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        else
          v55 = (UFG::CharacterOccupantComponent *)((v54 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        (UFG::SimObjectGame *)&v6->vfptr,
                                                                        UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
      }
      else
      {
        v55 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v6->vfptr,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( !v55 )
        return v8;
      v56 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v55);
      if ( !v56 )
        return v8;
      v57 = v56->m_Flags;
      if ( (v57 >> 14) & 1 )
        return v8;
      if ( (v57 & 0x8000u) == 0 )
      {
        if ( (v57 >> 13) & 1 )
          return v8;
        if ( (v57 >> 12) & 1 )
          v58 = UFG::SimObjectGame::GetComponentOfTypeHK(v56, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v58 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v56->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v58 = v56->m_Components.p[34].m_pComponent;
      }
      if ( v58 )
      {
        v59 = (float)((float)(3.5999999 * *((float *)&v58[10].m_BoundComponentHandles.mNode.mPrev + 1)) - s_fSpeedLowKPH)
            / (float)(s_fSpeedHighKPH - s_fSpeedLowKPH);
        if ( v59 > 0.0 )
        {
          v8 = *(float *)&FLOAT_1_0;
          if ( v59 < 1.0 )
            v8 = (float)((float)(3.5999999 * *((float *)&v58[10].m_BoundComponentHandles.mNode.mPrev + 1))
                       - s_fSpeedLowKPH)
               / (float)(s_fSpeedHighKPH - s_fSpeedLowKPH);
        }
      }
      return v8;
    case 18:
      if ( pSimObject )
      {
        v60 = pSimObject->m_Flags;
        if ( (v60 >> 14) & 1 )
        {
          v61 = v6->m_Components.p[20].m_pComponent;
        }
        else if ( (v60 & 0x8000u) == 0 )
        {
          if ( (v60 >> 13) & 1 )
            v62 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v62 = (v60 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v6->vfptr,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v6->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
          v61 = v62;
        }
        else
        {
          v61 = v6->m_Components.p[20].m_pComponent;
        }
        if ( v61 )
        {
          v63 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v61[1].m_Flags + 45i64)
                          + *(_QWORD *)&v61[1].m_TypeUID
                          + 40);
          if ( v63 )
          {
            v64 = *(_QWORD *)(v63 + 88);
            if ( v64 )
            {
              v65 = v6->m_pTransformNodeComponent;
              if ( v65 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v65);
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v64);
                v67 = (__m128)*(unsigned int *)(v64 + 180);
                v66 = *(float *)(v64 + 176) - v65->mWorldTransform.v3.x;
                v67.m128_f32[0] = v67.m128_f32[0] - v65->mWorldTransform.v3.y;
                v68 = *(float *)(v64 + 184) - v65->mWorldTransform.v3.z;
                v69 = v67;
                v69.m128_f32[0] = (float)((float)(v67.m128_f32[0] * v67.m128_f32[0]) + (float)(v66 * v66))
                                + (float)(v68 * v68);
                if ( v69.m128_f32[0] != 0.0 )
                  v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v69));
                desiredDirection.z = v8 * v68;
                desiredDirection.x = v8 * v66;
                desiredDirection.y = v8 * v67.m128_f32[0];
                UFG::TransformNodeComponent::UpdateWorldTransform(v65);
                v70 = v65->mWorldTransform.v0.y;
                v133.x = v65->mWorldTransform.v0.x;
                v71 = v65->mWorldTransform.v0.z;
                v133.y = v70;
                v133.z = v71;
                v8 = getSignalFromDirection(&desiredDirection, &v133, v9);
              }
            }
          }
        }
      }
      return v8;
    case 19:
      if ( pSimObject )
      {
        v72 = pSimObject->m_Flags;
        if ( (v72 >> 14) & 1 )
        {
          v73 = v6->m_Components.p[20].m_pComponent;
        }
        else if ( (v72 & 0x8000u) == 0 )
        {
          if ( (v72 >> 13) & 1 )
            v74 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v74 = (v72 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v6->vfptr,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v6->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
          v73 = v74;
        }
        else
        {
          v73 = v6->m_Components.p[20].m_pComponent;
        }
        if ( v73 )
        {
          v75 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v73[1].m_Flags + 31i64)
                                   + *(_QWORD *)&v73[1].m_TypeUID
                                   + 40);
          if ( v75 )
            v8 = getSignalValue(v75, FIS_MOTION_INTENTION_DIRECTION, timeDelta, activeRange, a5, (UFG::qVector3 *)&v135);
        }
      }
      return v8;
    case 20:
      if ( pSimObject )
      {
        v76 = pSimObject->m_Flags;
        if ( (v76 >> 14) & 1 )
        {
          v77 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v76 & 0x8000u) == 0 )
        {
          if ( (v76 >> 13) & 1 )
            v77 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v77 = (v76 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v6->vfptr,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v6->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v77 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v77 )
          goto LABEL_228;
      }
      return v8;
    case 21:
    case 34:
    case 35:
      v94 = 0i64;
      if ( !pSimObject )
        goto LABEL_329;
      v95 = pSimObject->m_Flags;
      if ( (v95 >> 14) & 1 )
      {
        v96 = v6->m_Components.p[20].m_pComponent;
      }
      else if ( (v95 & 0x8000u) == 0 )
      {
        if ( (v95 >> 13) & 1 )
        {
          v97 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v95 >> 12) & 1 )
        {
          v97 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v97 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v6->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v96 = v97;
      }
      else
      {
        v96 = v6->m_Components.p[20].m_pComponent;
      }
      if ( v96 )
      {
        v94 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v96[1].m_Flags + 31i64)
                                     + *(_QWORD *)&v96[1].m_TypeUID
                                     + 40);
      }
      else
      {
        v98 = v6->m_Flags;
        if ( (v98 >> 14) & 1 )
        {
          v99 = v6->m_Components.p[25].m_pComponent;
        }
        else if ( (v98 & 0x8000u) == 0 )
        {
          if ( (v98 >> 13) & 1 )
          {
            v99 = v6->m_Components.p[10].m_pComponent;
          }
          else if ( (v98 >> 12) & 1 )
          {
            v99 = v6->m_Components.p[3].m_pComponent;
          }
          else
          {
            v99 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          v99 = v6->m_Components.p[25].m_pComponent;
        }
        if ( !v99 )
        {
LABEL_329:
          v100 = v6->m_pSceneObj;
          v101 = 0;
          if ( v100->mChildren.mCount <= 0 )
            return v8;
          while ( 1 )
          {
            v102 = UFG::SceneObjectProperties::GetChildAsSimObject(v100, v101);
            if ( v102 )
            {
              v103 = v102->m_Flags;
              if ( (v103 >> 14) & 1 )
              {
                v104 = v102->m_Components.p[25].m_pComponent;
              }
              else if ( (v103 & 0x8000u) == 0 )
              {
                if ( (v103 >> 13) & 1 )
                  v104 = v102->m_Components.p[10].m_pComponent;
                else
                  v104 = (v103 >> 12) & 1 ? v102->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                     v102,
                                                                                     UFG::InterestPoint::_TypeUID);
              }
              else
              {
                v104 = v102->m_Components.p[25].m_pComponent;
              }
              if ( v104 )
              {
                v94 = (UFG::SimObjectGame *)v104[5].m_BoundComponentHandles.mNode.mNext;
                if ( v94 )
                  goto LABEL_344;
              }
            }
            v100 = v6->m_pSceneObj;
            if ( ++v101 >= v100->mChildren.mCount )
              goto LABEL_343;
          }
        }
        v94 = (UFG::SimObjectGame *)v99[5].m_BoundComponentHandles.mNode.mNext;
      }
LABEL_343:
      if ( !v94 )
        return v8;
LABEL_344:
      v105 = v94->m_Flags;
      if ( (v105 >> 14) & 1 )
      {
        v77 = UFG::SimObjectGame::GetComponentOfTypeHK(v94, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      }
      else if ( (v105 & 0x8000u) == 0 )
      {
        if ( (v105 >> 13) & 1 )
        {
          v77 = UFG::SimObjectGame::GetComponentOfTypeHK(v94, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v105 >> 12) & 1 )
        {
          v77 = UFG::SimObjectGame::GetComponentOfTypeHK(v94, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v77 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v94->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
      }
      else
      {
        v77 = UFG::SimObjectGame::GetComponentOfTypeHK(v94, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      }
      if ( v77 )
      {
        switch ( (_DWORD)v137 )
        {
          case 0x15:
LABEL_228:
            v8 = *(float *)&v77[1].m_TypeUID;
            break;
          case 0x22:
            goto LABEL_268;
          case 0x23:
            v8 = *(float *)&v77[1].m_Flags;
            break;
        }
      }
      return v8;
    case 22:
      if ( pSimObject )
      {
        v78 = pSimObject->m_Flags;
        if ( (v78 >> 14) & 1 )
        {
          v79 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v6);
        }
        else if ( (v78 & 0x8000u) == 0 )
        {
          if ( (v78 >> 13) & 1 )
            v79 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v6->vfptr,
                                                                  UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          else
            v79 = (UFG::SimObjectCharacterPropertiesComponent *)((v78 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                     (UFG::SimObjectGame *)&v6->vfptr,
                                                                                     UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
        }
        else
        {
          v79 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v6);
        }
        if ( v79 )
          v8 = v79->m_CharacterStats[3].m_fStat;
      }
      return v8;
    case 23:
      v80 = UFG::ActionDef_LeftThumbStick.mDataPerController[UFG::gActiveControllerNum];
      if ( v80 )
        v8 = v80->mAxisPositionX;
      return v8;
    case 24:
      v81 = UFG::ActionDef_LeftThumbStick.mDataPerController[UFG::gActiveControllerNum];
      if ( v81 )
        v8 = v81->mAxisPositionY;
      return v8;
    case 25:
      v82 = UFG::ActionDef_RightThumbStick.mDataPerController[UFG::gActiveControllerNum];
      if ( v82 )
        v8 = v82->mAxisPositionX;
      return v8;
    case 26:
      v83 = UFG::ActionDef_RightThumbStick.mDataPerController[UFG::gActiveControllerNum];
      if ( v83 )
        v8 = v83->mAxisPositionY;
      return v8;
    case 27:
      v84 = UFG::ActionDef_Focus.mDataPerController[UFG::gActiveControllerNum];
      if ( v84 )
        v8 = v84->mAxisRawX[0];
      return v8;
    case 28:
      v85 = UFG::ActionDef_Sprint.mDataPerController[UFG::gActiveControllerNum];
      if ( v85 )
        v8 = v85->mAxisRawX[0];
      return v8;
    case 29:
      v86 = UFG::ActionDef_Action.mDataPerController[UFG::gActiveControllerNum];
      if ( v86 && v86->mActionTrue && v86->mOnSeconds <= 0.0 )
        v8 = *(float *)&FLOAT_1_0;
      return v8;
    case 30:
      if ( pSimObject )
      {
        v87 = pSimObject->m_Flags;
        if ( (v87 >> 14) & 1 )
        {
          v77 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v87 & 0x8000u) == 0 )
        {
          if ( (v87 >> 13) & 1 )
            v77 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v77 = (v87 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v6->vfptr,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v6->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v77 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v77 )
LABEL_268:
          v8 = *(float *)&v77[1].m_NameUID;
      }
      return v8;
    case 31:
      if ( pSimObject )
      {
        v88 = pSimObject->m_Flags;
        if ( (v88 >> 14) & 1 )
        {
          v89 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v88 & 0x8000u) == 0 )
        {
          if ( (v88 >> 13) & 1 )
            v89 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v89 = (v88 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v6->vfptr,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v6->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v89 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v89 )
          v8 = *(float *)&v89[1].m_Flags;
      }
      return v8;
    case 32:
      if ( pSimObject )
      {
        v90 = pSimObject->m_Flags;
        if ( (v90 >> 14) & 1 )
        {
          v91 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v90 & 0x8000u) == 0 )
        {
          if ( (v90 >> 13) & 1 )
            v91 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v91 = (v90 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v6->vfptr,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v6->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v91 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v91 )
          v8 = *(float *)(&v91[1].m_SimObjIndex + 1);
      }
      return v8;
    case 33:
      if ( pSimObject )
      {
        v92 = pSimObject->m_Flags;
        if ( (v92 >> 14) & 1 )
        {
          v93 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v92 & 0x8000u) == 0 )
        {
          if ( (v92 >> 13) & 1 )
            v93 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v6->vfptr,
                    UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v93 = (v92 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v6->vfptr,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v6->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v93 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v6->vfptr,
                  UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v93 )
          v8 = *(float *)&v93[1].m_pSimObject;
      }
      return v8;
    case 36:
      if ( !pSimObject )
        return v8;
      v106 = pSimObject->m_Flags;
      if ( (v106 >> 14) & 1 )
      {
        v107 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
      }
      else if ( (v106 & 0x8000u) == 0 )
      {
        if ( (v106 >> 13) & 1 )
          v107 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v6);
        else
          v107 = (UFG::CharacterAnimationComponent *)((v106 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v6->vfptr,
                                                                           UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
      }
      else
      {
        v107 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
      }
      if ( !v107 )
        return v8;
      v108 = v107->mCreature;
      if ( !v108 )
        return v8;
      v109 = v108->mPoseDrivers.mNode.mNext;
      v110 = (signed __int64)&v108->m_SafePointerList;
      v111 = (signed __int64)&v109[-1];
      if ( v111 == v110 )
        return v8;
      while ( *(_DWORD *)(v111 + 44) != uPoseDriverTest_SignalUID )
      {
        v111 = *(_QWORD *)(v111 + 24) - 16i64;
        if ( v111 == v110 )
          return v8;
      }
      v112 = (float)(*(float *)(v111 + 140) - *(float *)(v111 + 136)) * sSpringSignalRange;
      if ( v112 <= -0.25 )
      {
        v112 = FLOAT_N0_25;
      }
      else if ( v112 >= 0.25 )
      {
        return 0.25 + 0.5;
      }
      return v112 + 0.5;
    case 39:
      if ( pSimObject )
      {
        v113 = pSimObject->m_Flags;
        if ( (v113 >> 14) & 1 )
        {
          v114 = v6->m_Components.p[47].m_pComponent;
        }
        else if ( (v113 & 0x8000u) == 0 )
        {
          if ( (v113 >> 13) & 1 )
            v114 = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)&v6->vfptr,
                     UFG::AimingBaseComponent::_TypeUID);
          else
            v114 = (v113 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v6->vfptr,
                                        UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                (UFG::SimObject *)&v6->vfptr,
                                                                                UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v114 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v6->vfptr,
                   UFG::AimingBaseComponent::_TypeUID);
        }
        if ( v114 )
        {
          v115 = *(float *)&v114[2].m_SafePointerList.mNode.mNext;
          v133.x = *((float *)&v114[2].m_SafePointerList.mNode.mPrev + 1);
          v116 = *((float *)&v114[2].m_SafePointerList.mNode.mNext + 1);
          v133.y = v115;
          v117 = currentFacing->x;
          v133.z = v116;
          v118 = currentFacing->y;
          desiredDirection.x = v117;
          desiredDirection.z = currentFacing->z;
          desiredDirection.y = v118;
          v8 = getSignalFromDirection(&v133, &desiredDirection, activeRange);
        }
      }
      return v8;
    case 40:
      return UFG::Metrics::msInstance.mSimTimeScaleInGame;
    case 41:
    case 42:
      if ( pSimObject )
      {
        v119 = pSimObject->m_Flags;
        if ( (v119 >> 14) & 1 )
        {
          v120 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
        }
        else if ( (v119 & 0x8000u) == 0 )
        {
          if ( (v119 >> 13) & 1 )
            v120 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v6);
          else
            v120 = (UFG::CharacterAnimationComponent *)((v119 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v6->vfptr,
                                                                             UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
        }
        else
        {
          v120 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
        }
        v121 = v6->m_Flags;
        v122 = v120;
        if ( (v121 >> 14) & 1 )
        {
          v123 = v6->m_Components.p[42].m_pComponent;
        }
        else if ( (v121 & 0x8000u) == 0 )
        {
          if ( (v121 >> 13) & 1 )
            v123 = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)&v6->vfptr,
                     UFG::RagdollComponent::_TypeUID);
          else
            v123 = (v121 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v6->vfptr,
                                        UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                             (UFG::SimObject *)&v6->vfptr,
                                                                             UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v123 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v6->vfptr,
                   UFG::RagdollComponent::_TypeUID);
        }
        if ( v122 && v123 )
        {
          v124 = v123[1].m_BoundComponentHandles.mNode.mPrev;
          v125 = v122->mCreature;
          v126 = *(float *)&v124[4].mPrev;
          v127 = (__m128)HIDWORD(v124[4].mPrev);
          if ( v125 )
            Creature::GetTransform(v125, 0, &transform);
          v128 = v126 - transform.v3.x;
          v127.m128_f32[0] = v127.m128_f32[0] - transform.v3.y;
          v133.z = 0.0;
          v133.x = v128;
          LODWORD(v133.y) = v127.m128_i32[0];
          if ( v7 == 42 )
          {
            v129 = v6->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v129);
            v130 = v129->mWorldTransform.v0.y;
            v131 = v129->mWorldTransform.v0.x;
            desiredDirection.z = v129->mWorldTransform.v0.z;
            desiredDirection.x = v131;
            desiredDirection.y = v130;
            v8 = getSignalFromDirection(&v133, &desiredDirection, activeRange);
          }
          else
          {
            v127.m128_f32[0] = (float)(v127.m128_f32[0] * v127.m128_f32[0]) + (float)(v128 * v128);
            LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v127);
          }
        }
      }
      return v8;
    default:
      return v8;
  }
};
          }
        }
      }
      return v8;
    default:
      return v8;
  }
}

// File Line: 663
// RVA: 0x275950
void __fastcall setSignalValue(ActionContext *context, FloatInputSignal floatInputSignal, float signal)
{
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rdx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::SimObjectGame *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rax
  UFG::SimObjectGame *v19; // rcx
  unsigned __int16 v20; // dx
  UFG::SimComponent *v21; // rax

  switch ( floatInputSignal )
  {
    case 20:
      v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v3 )
      {
        v4 = v3->m_Flags;
        if ( !((v4 >> 14) & 1) )
          goto LABEL_5;
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        goto LABEL_12;
      }
      break;
    case 21:
      v6 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
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
            v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v6,
                                    UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v6->vfptr,
                                                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
          v8 = v9;
        }
        else
        {
          v8 = v6->m_Components.p[20].m_pComponent;
        }
        if ( v8 )
        {
          v3 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + 31i64)
                                      + *(_QWORD *)&v8[1].m_TypeUID
                                      + 40);
          if ( v3 )
          {
            v4 = v3->m_Flags;
            if ( (v4 >> 14) & 1 )
            {
              v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
            }
            else
            {
LABEL_5:
              if ( (v4 & 0x8000u) == 0 )
              {
                if ( (v4 >> 13) & 1 )
                {
                  v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
                }
                else if ( (v4 >> 12) & 1 )
                {
                  v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
                }
                else
                {
                  v5 = UFG::SimObject::GetComponentOfType(
                         (UFG::SimObject *)&v3->vfptr,
                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
                }
              }
              else
              {
                v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
              }
            }
LABEL_12:
            if ( v5 )
              *(float *)&v5[1].m_TypeUID = signal;
          }
        }
      }
      break;
    case 30:
      v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v10,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v10->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v12 )
          *(float *)&v12[1].m_NameUID = signal;
      }
      break;
    case 31:
      v13 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v13 )
      {
        v14 = v13->m_Flags;
        if ( (v14 >> 14) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v14 & 0x8000u) == 0 )
        {
          if ( (v14 >> 13) & 1 )
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v15 = (v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v13,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v13->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v15 )
          *(float *)&v15[1].m_Flags = signal;
      }
      break;
    case 32:
      v16 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v16 )
      {
        v17 = v16->m_Flags;
        if ( (v17 >> 14) & 1 )
        {
          v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v17 & 0x8000u) == 0 )
        {
          if ( (v17 >> 13) & 1 )
            v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v18 = (v17 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v16,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v16->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v18 )
          *(float *)(&v18[1].m_SimObjIndex + 1) = signal;
      }
      break;
    case 33:
      v19 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v19 )
      {
        v20 = v19->m_Flags;
        if ( (v20 >> 14) & 1 )
        {
          v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else if ( (v20 & 0x8000u) == 0 )
        {
          if ( (v20 >> 13) & 1 )
            v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::SimObjectSignalMemoryComponent::_TypeUID);
          else
            v21 = (v20 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v19,
                                      UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v19->vfptr,
                                                                                         UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        else
        {
          v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        }
        if ( v21 )
          *(float *)&v21[1].m_pSimObject = signal;
      }
      break;
    default:
      return;
  }
}

