// File Line: 98
// RVA: 0x1483CA0
__int64 dynamic_initializer_for__floatInputSignalEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&floatInputSignalEnum, gFloatInputSignalStringList, 43, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__floatInputSignalEnum__);
}

// File Line: 109
// RVA: 0x273E80
float __fastcall getSignalFromDirection(UFG::qVector3 *desiredDirection, UFG::qVector3 *currentFacing, float threshold)
{
  float y; // xmm6_4
  float z; // xmm7_4
  int v6; // xmm9_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm9_4

  y = currentFacing->y;
  z = currentFacing->z;
  v6 = LODWORD(currentFacing->x) ^ _xmm[0];
  v7 = UFG::qAngleBetween(desiredDirection, currentFacing);
  v8 = v7;
  v9 = (float)((float)(*(float *)&v6 * desiredDirection->y) + (float)(y * desiredDirection->x))
     + (float)(z * desiredDirection->z);
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
      return v8 + 6.2831855;
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

  result = UFG::qStringHashUpper32("PoseDriverTest_Signal", -1);
  uPoseDriverTest_SignalUID = result;
  return result;
}

// File Line: 141
// RVA: 0x273F50
float __fastcall getSignalValue(
        UFG::SimObjectCVBase *pSimObject,
        FloatInputSignal floatInputSignal,
        float timeDelta,
        float activeRange,
        UFG::qVector3 *relativeStartVector)
{
  __int64 v5; // rdi
  float v8; // xmm6_4
  signed __int16 m_Flags; // cx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::AICharacterControllerBaseComponent *v12; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  signed __int16 v14; // cx
  UFG::AICharacterControllerBaseComponent *v15; // rax
  UFG::qVector3 *p_mMotionIntentionDirection; // rcx
  signed __int16 v17; // cx
  UFG::AICharacterControllerBaseComponent *v18; // rax
  signed __int16 v19; // cx
  UFG::AICharacterControllerBaseComponent *v20; // rax
  float mCurrentRotationSignal; // xmm0_4
  bool v22; // cc
  signed __int16 v23; // cx
  UFG::AimingBaseComponent *m_pComponent; // rax
  signed __int16 v25; // cx
  UFG::AimingBaseComponent *v26; // rax
  signed __int16 v27; // cx
  UFG::AimingBaseComponent *v28; // rax
  signed __int16 v29; // cx
  UFG::AimingBaseComponent *v30; // rax
  UFG::TransformNodeComponent *v31; // rdi
  UFG::TransformNodeComponent *v32; // rdi
  signed __int16 v33; // cx
  UFG::CharacterAnimationComponent *v34; // rax
  Creature *mCreature; // rcx
  float y; // xmm1_4
  float z; // xmm0_4
  __int64 v38; // rdi
  UFG::TransformNodeComponent *v39; // rsi
  signed __int16 v40; // cx
  UFG::SimComponent *v41; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v43; // rdx
  signed __int16 v44; // cx
  UFG::CharacterOccupantComponent *v45; // rax
  UFG::VehicleOccupantComponent *CurrentVehicle; // rax
  UFG::TransformNodeComponent *mPrev; // rbx
  float v48; // xmm5_4
  __m128 y_low; // xmm4
  __m128 v50; // xmm1
  float v51; // xmm2_4
  float v52; // xmm0_4
  signed __int16 v53; // cx
  UFG::CharacterOccupantComponent *v54; // rax
  UFG::SimObjectGame *v55; // rax
  __int16 v56; // dx
  UFG::SimComponent *v57; // rax
  float v58; // xmm2_4
  signed __int16 v59; // cx
  UFG::SimComponent *v60; // rdx
  UFG::SimComponent *v61; // rax
  __int64 v62; // rdi
  __int64 v63; // rdi
  UFG::TransformNodeComponent *v64; // rbx
  float v65; // xmm3_4
  __m128 v66; // xmm4
  float v67; // xmm5_4
  __m128 v68; // xmm2
  float v69; // xmm1_4
  float v70; // xmm0_4
  signed __int16 v71; // cx
  UFG::SimComponent *v72; // rdx
  UFG::SimComponent *v73; // rax
  UFG::SimObject *v74; // rcx
  signed __int16 v75; // cx
  UFG::SimComponent *v76; // rax
  signed __int16 v77; // cx
  UFG::SimObjectCharacterPropertiesComponent *v78; // rax
  UFG::InputActionData *v79; // rcx
  UFG::InputActionData *v80; // rcx
  UFG::InputActionData *v81; // rcx
  UFG::InputActionData *v82; // rcx
  UFG::InputActionData *v83; // rcx
  UFG::InputActionData *v84; // rcx
  UFG::InputActionData *v85; // rcx
  signed __int16 v86; // cx
  signed __int16 v87; // cx
  UFG::SimComponent *v88; // rax
  signed __int16 v89; // cx
  UFG::SimComponent *v90; // rax
  signed __int16 v91; // cx
  UFG::SimComponent *v92; // rax
  UFG::SimObjectGame *mNext; // rdi
  signed __int16 v94; // cx
  UFG::SimComponent *v95; // rdx
  UFG::SimComponent *v96; // rax
  signed __int16 v97; // cx
  UFG::SimComponent *v98; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  unsigned int v100; // esi
  UFG::SimObject *ChildAsSimObject; // rax
  __int16 v102; // dx
  UFG::SimComponent *v103; // rax
  __int16 v104; // cx
  signed __int16 v105; // cx
  UFG::CharacterAnimationComponent *v106; // rax
  Creature *v107; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *v108; // rax
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  __int64 v110; // rax
  float v111; // xmm0_4
  signed __int16 v112; // cx
  UFG::SimComponent *v113; // rax
  float v114; // xmm1_4
  float v115; // xmm0_4
  float x; // xmm1_4
  float v117; // xmm0_4
  signed __int16 v118; // cx
  UFG::CharacterAnimationComponent *v119; // rax
  signed __int16 v120; // cx
  UFG::CharacterAnimationComponent *v121; // rdi
  UFG::SimComponent *v122; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v123; // rax
  Creature *v124; // rcx
  float v125; // xmm7_4
  __m128 mPrev_high; // xmm6
  float v127; // xmm7_4
  UFG::TransformNodeComponent *v128; // rbx
  float v129; // xmm1_4
  float v130; // xmm0_4
  UFG::qVector3 v132; // [rsp+28h] [rbp-51h] BYREF
  UFG::qVector3 desiredDirection; // [rsp+38h] [rbp-41h] BYREF
  UFG::qVector3 v134; // [rsp+48h] [rbp-31h] BYREF
  UFG::qMatrix44 transform; // [rsp+58h] [rbp-21h] BYREF
  int v136; // [rsp+E0h] [rbp+67h]
  UFG::qVector3 *currentFacing; // [rsp+F8h] [rbp+7Fh]

  v8 = 0.0;
  v136 = v5;
  switch ( floatInputSignal )
  {
    case FIS_MOTION_INTENTION_DIRECTION:
      if ( pSimObject )
      {
        m_Flags = pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(pSimObject);
        }
        else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           pSimObject,
                                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                           pSimObject,
                                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        v12 = ComponentOfTypeHK;
        if ( ComponentOfTypeHK )
        {
          m_pTransformNodeComponent = pSimObject->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          return getSignalFromDirection(
                   &v12->m_Intention.mMotionIntentionDirection,
                   (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform,
                   activeRange);
        }
      }
      return v8;
    case FIS_MOTION_INTENTION_DIRECTION_RELATIVE_TO_START:
      if ( pSimObject )
      {
        v14 = pSimObject->m_Flags;
        if ( (v14 & 0x4000) != 0 || v14 < 0 )
          v15 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(pSimObject);
        else
          v15 = (UFG::AICharacterControllerBaseComponent *)((v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
                                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              pSimObject,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                          : UFG::SimObject::GetComponentOfType(
                                                              pSimObject,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID));
        if ( v15 )
        {
          p_mMotionIntentionDirection = &v15->m_Intention.mMotionIntentionDirection;
          return getSignalFromDirection(p_mMotionIntentionDirection, currentFacing, activeRange);
        }
      }
      return v8;
    case FIS_MOTION_INTENTION_SPEED:
      if ( pSimObject )
      {
        v17 = pSimObject->m_Flags;
        if ( (v17 & 0x4000) != 0 || v17 < 0 )
          v18 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(pSimObject);
        else
          v18 = (UFG::AICharacterControllerBaseComponent *)((v17 & 0x2000) != 0 || (v17 & 0x1000) != 0
                                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              pSimObject,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                          : UFG::SimObject::GetComponentOfType(
                                                              pSimObject,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID));
        if ( v18 )
          return v18->m_Intention.mMotionIntentionSpeed;
      }
      return v8;
    case FIS_MOTION_ROTATION_SPEED:
      if ( pSimObject )
      {
        v19 = pSimObject->m_Flags;
        if ( (v19 & 0x4000) != 0 || v19 < 0 )
          v20 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(pSimObject);
        else
          v20 = (UFG::AICharacterControllerBaseComponent *)((v19 & 0x2000) != 0 || (v19 & 0x1000) != 0
                                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              pSimObject,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                          : UFG::SimObject::GetComponentOfType(
                                                              pSimObject,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID));
        if ( v20 && sKillRotSpeed )
        {
          mCurrentRotationSignal = v20->m_Intention.mCurrentRotationSignal;
          v22 = mCurrentRotationSignal <= 0.0;
          if ( mCurrentRotationSignal < 0.0 )
          {
            mCurrentRotationSignal = mCurrentRotationSignal + 6.2831855;
            v22 = mCurrentRotationSignal <= 0.0;
          }
          if ( !v22 )
          {
            v8 = mCurrentRotationSignal;
            if ( mCurrentRotationSignal >= 6.2831855 )
              return FLOAT_6_2831855;
          }
        }
      }
      return v8;
    case FIS_AIM_INTENTION_DIRECTION_XY:
      if ( pSimObject )
      {
        v23 = pSimObject->m_Flags;
        if ( (v23 & 0x4000) != 0 )
          m_pComponent = (UFG::AimingBaseComponent *)pSimObject->m_Components.p[47].m_pComponent;
        else
          m_pComponent = (UFG::AimingBaseComponent *)(v23 < 0 || (v23 & 0x2000) != 0 || (v23 & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        pSimObject,
                                                        UFG::AimingBaseComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        pSimObject,
                                                        UFG::AimingBaseComponent::_TypeUID));
        if ( m_pComponent )
          return UFG::AimingBaseComponent::GetLocalAimDirectionXY(m_pComponent);
      }
      return v8;
    case FIS_AIM_INTENTION_DIRECTION_XZ:
      if ( pSimObject )
      {
        v25 = pSimObject->m_Flags;
        if ( (v25 & 0x4000) != 0 )
          v26 = (UFG::AimingBaseComponent *)pSimObject->m_Components.p[47].m_pComponent;
        else
          v26 = (UFG::AimingBaseComponent *)(v25 < 0 || (v25 & 0x2000) != 0 || (v25 & 0x1000) != 0
                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                               pSimObject,
                                               UFG::AimingBaseComponent::_TypeUID)
                                           : UFG::SimObject::GetComponentOfType(
                                               pSimObject,
                                               UFG::AimingBaseComponent::_TypeUID));
        if ( v26 )
          return UFG::AimingBaseComponent::GetLocalAimDirectionXZ(v26);
      }
      return v8;
    case FIS_AIM_INTENTION_DIRECTION_XY_RELATIVE_TO_COVER:
      if ( pSimObject )
      {
        v27 = pSimObject->m_Flags;
        if ( (v27 & 0x4000) != 0 )
          v28 = (UFG::AimingBaseComponent *)pSimObject->m_Components.p[47].m_pComponent;
        else
          v28 = (UFG::AimingBaseComponent *)(v27 < 0 || (v27 & 0x2000) != 0 || (v27 & 0x1000) != 0
                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                               pSimObject,
                                               UFG::AimingBaseComponent::_TypeUID)
                                           : UFG::SimObject::GetComponentOfType(
                                               pSimObject,
                                               UFG::AimingBaseComponent::_TypeUID));
        if ( v28 )
          return UFG::AimingBaseComponent::GetLocalAimDirectionXYRelCover(v28);
      }
      return v8;
    case FIS_AIM_INTENTION_DIRECTION_XY_RELATIVE_TO_SYNCBONE:
      if ( pSimObject )
      {
        v29 = pSimObject->m_Flags;
        if ( (v29 & 0x4000) != 0 )
          v30 = (UFG::AimingBaseComponent *)pSimObject->m_Components.p[47].m_pComponent;
        else
          v30 = (UFG::AimingBaseComponent *)(v29 < 0 || (v29 & 0x2000) != 0 || (v29 & 0x1000) != 0
                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                               pSimObject,
                                               UFG::AimingBaseComponent::_TypeUID)
                                           : UFG::SimObject::GetComponentOfType(
                                               pSimObject,
                                               UFG::AimingBaseComponent::_TypeUID));
        if ( v30 )
          return UFG::AimingBaseComponent::GetLocalAimDirectionXYRelSyncBone(v30);
      }
      return v8;
    case FIS_FACING_DIRECTION_RELATIVE_TO_START:
    case FIS_FACING_DIRECTION_RELATIVE_TO_SYNCBONE_START:
      if ( pSimObject )
        v31 = pSimObject->m_pTransformNodeComponent;
      else
        v31 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v31);
      p_mMotionIntentionDirection = (UFG::qVector3 *)&v31->mWorldTransform;
      return getSignalFromDirection(p_mMotionIntentionDirection, currentFacing, activeRange);
    case FIS_FACING_DIRECTION_RELATIVE_TO_SYNCBONE:
      if ( pSimObject )
        v32 = pSimObject->m_pTransformNodeComponent;
      else
        v32 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v32);
      if ( pSimObject )
      {
        v33 = pSimObject->m_Flags;
        if ( (v33 & 0x4000) != 0 || v33 < 0 )
        {
          v34 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(pSimObject);
        }
        else if ( (v33 & 0x2000) != 0 )
        {
          v34 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)pSimObject);
        }
        else
        {
          v34 = (UFG::CharacterAnimationComponent *)((v33 & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       pSimObject,
                                                       UFG::CharacterAnimationComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       pSimObject,
                                                       UFG::CharacterAnimationComponent::_TypeUID));
        }
        if ( v34 )
        {
          mCreature = v34->mCreature;
          if ( mCreature )
          {
            Creature::GetTransform(mCreature, 3, &transform);
            y = transform.v0.y;
            currentFacing->x = transform.v0.x;
            z = transform.v0.z;
            currentFacing->y = y;
            currentFacing->z = z;
          }
        }
      }
      return getSignalFromDirection((UFG::qVector3 *)&v32->mWorldTransform, currentFacing, activeRange);
    case FIS_FACING_DIRECTION_RELATIVE_TO_POI_USE_TARGET:
      v38 = 0i64;
      if ( pSimObject )
      {
        v40 = pSimObject->m_Flags;
        v39 = pSimObject->m_pTransformNodeComponent;
        if ( (v40 & 0x4000) != 0 )
        {
          v41 = pSimObject->m_Components.p[20].m_pComponent;
        }
        else if ( v40 >= 0 )
        {
          if ( (v40 & 0x2000) != 0 || (v40 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                pSimObject,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(
                                pSimObject,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
          v41 = ComponentOfType;
        }
        else
        {
          v41 = pSimObject->m_Components.p[20].m_pComponent;
        }
        if ( v41 )
        {
          v43 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v41[1].m_Flags + 34i64)
                          + *(_QWORD *)&v41[1].m_TypeUID
                          + 40);
          if ( v43 )
            v38 = *(_QWORD *)(v43 + 88);
        }
      }
      else
      {
        v39 = 0i64;
      }
      if ( v39 && v38 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v39);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v38);
        return getSignalFromDirection((UFG::qVector3 *)&v39->mWorldTransform, (UFG::qVector3 *)(v38 + 128), activeRange);
      }
      return v8;
    case BIKE_LEAN_ANGLE:
      if ( pSimObject )
      {
        v44 = pSimObject->m_Flags;
        if ( (v44 & 0x4000) != 0 )
          v45 = (UFG::CharacterOccupantComponent *)pSimObject->m_Components.p[44].m_pComponent;
        else
          v45 = (UFG::CharacterOccupantComponent *)(v44 < 0 || (v44 & 0x2000) != 0 || (v44 & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      pSimObject,
                                                      UFG::CharacterOccupantComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      pSimObject,
                                                      UFG::CharacterOccupantComponent::_TypeUID));
        if ( v45 )
        {
          CurrentVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(v45);
          if ( CurrentVehicle )
          {
            mPrev = (UFG::TransformNodeComponent *)CurrentVehicle->mpDriver.mPrev;
            UFG::TransformNodeComponent::UpdateWorldTransform(mPrev);
            y_low = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
            v48 = (float)((float)(UFG::qVector3::msDirUp.y * mPrev->mWorldTransform.v2.y)
                        + (float)(UFG::qVector3::msDirUp.x * mPrev->mWorldTransform.v2.x))
                + (float)(UFG::qVector3::msDirUp.z * mPrev->mWorldTransform.v2.z);
            y_low.m128_f32[0] = (float)((float)(UFG::qVector3::msDirUp.y * mPrev->mWorldTransform.v1.y)
                                      + (float)(UFG::qVector3::msDirUp.x * mPrev->mWorldTransform.v1.x))
                              + (float)(UFG::qVector3::msDirUp.z * mPrev->mWorldTransform.v1.z);
            v50 = y_low;
            v50.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v48 * v48);
            if ( v50.m128_f32[0] == 0.0 )
              v51 = 0.0;
            else
              v51 = 1.0 / _mm_sqrt_ps(v50).m128_f32[0];
            v52 = atan2f(v51 * y_low.m128_f32[0], v51 * v48);
            if ( v52 < 0.0 )
              return v52 + 6.2831855;
            return v52;
          }
        }
      }
      return v8;
    case FIS_VEHICLE_SPEED_HIGH:
      if ( !pSimObject )
        return v8;
      v53 = pSimObject->m_Flags;
      if ( (v53 & 0x4000) != 0 )
        v54 = (UFG::CharacterOccupantComponent *)pSimObject->m_Components.p[44].m_pComponent;
      else
        v54 = (UFG::CharacterOccupantComponent *)(v53 < 0 || (v53 & 0x2000) != 0 || (v53 & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    pSimObject,
                                                    UFG::CharacterOccupantComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    pSimObject,
                                                    UFG::CharacterOccupantComponent::_TypeUID));
      if ( !v54 )
        return v8;
      v55 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v54);
      if ( !v55 )
        return v8;
      v56 = v55->m_Flags;
      if ( (v56 & 0x4000) != 0 )
        return v8;
      if ( v56 >= 0 )
      {
        if ( (v56 & 0x2000) != 0 )
          return v8;
        if ( (v56 & 0x1000) != 0 )
          v57 = UFG::SimObjectGame::GetComponentOfTypeHK(v55, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v57 = UFG::SimObject::GetComponentOfType(v55, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v57 = v55->m_Components.p[34].m_pComponent;
      }
      if ( v57 )
      {
        v58 = (float)((float)(3.5999999 * *((float *)&v57[10].m_BoundComponentHandles.mNode.mPrev + 1)) - s_fSpeedLowKPH)
            / (float)(s_fSpeedHighKPH - s_fSpeedLowKPH);
        if ( v58 > 0.0 )
        {
          v8 = *(float *)&FLOAT_1_0;
          if ( v58 < 1.0 )
            return (float)((float)(3.5999999 * *((float *)&v57[10].m_BoundComponentHandles.mNode.mPrev + 1))
                         - s_fSpeedLowKPH)
                 / (float)(s_fSpeedHighKPH - s_fSpeedLowKPH);
        }
      }
      return v8;
    case POINT_AT_TARGET_DIRECTION_XY:
      if ( pSimObject )
      {
        v59 = pSimObject->m_Flags;
        if ( (v59 & 0x4000) != 0 )
        {
          v60 = pSimObject->m_Components.p[20].m_pComponent;
        }
        else if ( v59 >= 0 )
        {
          v61 = (v59 & 0x2000) != 0 || (v59 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
          v60 = v61;
        }
        else
        {
          v60 = pSimObject->m_Components.p[20].m_pComponent;
        }
        if ( v60 )
        {
          v62 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v60[1].m_Flags + 45i64)
                          + *(_QWORD *)&v60[1].m_TypeUID
                          + 40);
          if ( v62 )
          {
            v63 = *(_QWORD *)(v62 + 88);
            if ( v63 )
            {
              v64 = pSimObject->m_pTransformNodeComponent;
              if ( v64 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v64);
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v63);
                v66 = (__m128)*(unsigned int *)(v63 + 180);
                v65 = *(float *)(v63 + 176) - v64->mWorldTransform.v3.x;
                v66.m128_f32[0] = v66.m128_f32[0] - v64->mWorldTransform.v3.y;
                v67 = *(float *)(v63 + 184) - v64->mWorldTransform.v3.z;
                v68 = v66;
                v68.m128_f32[0] = (float)((float)(v66.m128_f32[0] * v66.m128_f32[0]) + (float)(v65 * v65))
                                + (float)(v67 * v67);
                if ( v68.m128_f32[0] != 0.0 )
                  v8 = 1.0 / _mm_sqrt_ps(v68).m128_f32[0];
                desiredDirection.z = v8 * v67;
                desiredDirection.x = v8 * v65;
                desiredDirection.y = v8 * v66.m128_f32[0];
                UFG::TransformNodeComponent::UpdateWorldTransform(v64);
                v69 = v64->mWorldTransform.v0.y;
                v132.x = v64->mWorldTransform.v0.x;
                v70 = v64->mWorldTransform.v0.z;
                v132.y = v69;
                v132.z = v70;
                return getSignalFromDirection(&desiredDirection, &v132, activeRange);
              }
            }
          }
        }
      }
      return v8;
    case TARGET_GRAPPLE_MOTION_INTENTION_DIRECTION:
      if ( pSimObject )
      {
        v71 = pSimObject->m_Flags;
        if ( (v71 & 0x4000) != 0 )
        {
          v72 = pSimObject->m_Components.p[20].m_pComponent;
        }
        else if ( v71 >= 0 )
        {
          v73 = (v71 & 0x2000) != 0 || (v71 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
          v72 = v73;
        }
        else
        {
          v72 = pSimObject->m_Components.p[20].m_pComponent;
        }
        if ( v72 )
        {
          v74 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v72[1].m_Flags + 31i64)
                                   + *(_QWORD *)&v72[1].m_TypeUID
                                   + 40);
          if ( v74 )
            return getSignalValue(v74, FIS_MOTION_INTENTION_DIRECTION, timeDelta, activeRange, v5, &v134);
        }
      }
      return v8;
    case FIS_STRUGGLE:
      if ( pSimObject )
      {
        v75 = pSimObject->m_Flags;
        if ( (v75 & 0x4000) != 0 || v75 < 0 || (v75 & 0x2000) != 0 || (v75 & 0x1000) != 0 )
          v76 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          v76 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( v76 )
          return *(float *)&v76[1].m_TypeUID;
      }
      return v8;
    case FIS_STRUGGLE_TARGET:
    case FIS_USER_SIGNAL0_TARGET:
    case FIS_USER_SIGNAL1_TARGET:
      mNext = 0i64;
      if ( !pSimObject )
        goto LABEL_298;
      v94 = pSimObject->m_Flags;
      if ( (v94 & 0x4000) != 0 )
      {
        v95 = pSimObject->m_Components.p[20].m_pComponent;
      }
      else if ( v94 >= 0 )
      {
        if ( (v94 & 0x2000) != 0 || (v94 & 0x1000) != 0 )
          v96 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v96 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
        v95 = v96;
      }
      else
      {
        v95 = pSimObject->m_Components.p[20].m_pComponent;
      }
      if ( v95 )
      {
        mNext = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v95[1].m_Flags + 31i64)
                                       + *(_QWORD *)&v95[1].m_TypeUID
                                       + 40);
      }
      else
      {
        v97 = pSimObject->m_Flags;
        if ( (v97 & 0x4000) != 0 )
        {
          v98 = pSimObject->m_Components.p[25].m_pComponent;
        }
        else if ( v97 >= 0 )
        {
          if ( (v97 & 0x2000) != 0 )
          {
            v98 = pSimObject->m_Components.p[10].m_pComponent;
          }
          else if ( (v97 & 0x1000) != 0 )
          {
            v98 = pSimObject->m_Components.p[3].m_pComponent;
          }
          else
          {
            v98 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          v98 = pSimObject->m_Components.p[25].m_pComponent;
        }
        if ( !v98 )
        {
LABEL_298:
          m_pSceneObj = pSimObject->m_pSceneObj;
          v100 = 0;
          if ( !m_pSceneObj->mChildren.mCount )
            return v8;
          while ( 1 )
          {
            ChildAsSimObject = UFG::SceneObjectProperties::GetChildAsSimObject(m_pSceneObj, v100);
            if ( ChildAsSimObject )
            {
              v102 = ChildAsSimObject->m_Flags;
              if ( (v102 & 0x4000) != 0 )
              {
                v103 = ChildAsSimObject->m_Components.p[25].m_pComponent;
              }
              else if ( v102 >= 0 )
              {
                if ( (v102 & 0x2000) != 0 )
                  v103 = ChildAsSimObject->m_Components.p[10].m_pComponent;
                else
                  v103 = (v102 & 0x1000) != 0
                       ? ChildAsSimObject->m_Components.p[3].m_pComponent
                       : UFG::SimObject::GetComponentOfType(ChildAsSimObject, UFG::InterestPoint::_TypeUID);
              }
              else
              {
                v103 = ChildAsSimObject->m_Components.p[25].m_pComponent;
              }
              if ( v103 )
              {
                mNext = (UFG::SimObjectGame *)v103[5].m_BoundComponentHandles.mNode.mNext;
                if ( mNext )
                  goto LABEL_313;
              }
            }
            m_pSceneObj = pSimObject->m_pSceneObj;
            if ( ++v100 >= m_pSceneObj->mChildren.mCount )
              goto LABEL_312;
          }
        }
        mNext = (UFG::SimObjectGame *)v98[5].m_BoundComponentHandles.mNode.mNext;
      }
LABEL_312:
      if ( !mNext )
        return v8;
LABEL_313:
      v104 = mNext->m_Flags;
      if ( (v104 & 0x4000) != 0 || v104 < 0 || (v104 & 0x2000) != 0 || (v104 & 0x1000) != 0 )
        v76 = UFG::SimObjectGame::GetComponentOfTypeHK(mNext, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      else
        v76 = UFG::SimObject::GetComponentOfType(mNext, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      if ( v76 )
      {
        switch ( v136 )
        {
          case 21:
            return *(float *)&v76[1].m_TypeUID;
          case 34:
            return *(float *)&v76[1].m_NameUID;
          case 35:
            return *(float *)&v76[1].m_Flags;
        }
      }
      return v8;
    case FIS_LOCOMOTION_WALK_SCALE:
      if ( pSimObject )
      {
        v77 = pSimObject->m_Flags;
        if ( (v77 & 0x4000) != 0 || v77 < 0 )
          v78 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(pSimObject);
        else
          v78 = (UFG::SimObjectCharacterPropertiesComponent *)((v77 & 0x2000) != 0 || (v77 & 0x1000) != 0
                                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 pSimObject,
                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                             : UFG::SimObject::GetComponentOfType(
                                                                 pSimObject,
                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
        if ( v78 )
          return v78->m_CharacterStats[3].m_fStat;
      }
      return v8;
    case FIS_LEFT_THUMBSTICK_X:
      v79 = UFG::ActionDef_LeftThumbStick.mDataPerController[UFG::gActiveControllerNum];
      if ( v79 )
        return v79->mAxisPositionX;
      return v8;
    case FIS_LEFT_THUMBSTICK_Y:
      v80 = UFG::ActionDef_LeftThumbStick.mDataPerController[UFG::gActiveControllerNum];
      if ( v80 )
        return v80->mAxisPositionY;
      return v8;
    case FIS_RIGHT_THUMBSTICK_X:
      v81 = UFG::ActionDef_RightThumbStick.mDataPerController[UFG::gActiveControllerNum];
      if ( v81 )
        return v81->mAxisPositionX;
      return v8;
    case FIS_RIGHT_THUMBSTICK_Y:
      v82 = UFG::ActionDef_RightThumbStick.mDataPerController[UFG::gActiveControllerNum];
      if ( v82 )
        return v82->mAxisPositionY;
      return v8;
    case FIS_LEFT_TRIGGER:
      v83 = UFG::ActionDef_Focus.mDataPerController[UFG::gActiveControllerNum];
      if ( v83 )
        return v83->mAxisRawX[0];
      return v8;
    case FIS_RIGHT_TRIGGER:
      v84 = UFG::ActionDef_Sprint.mDataPerController[UFG::gActiveControllerNum];
      if ( v84 )
        return v84->mAxisRawX[0];
      return v8;
    case FIS_Y_BUTTON:
      v85 = UFG::ActionDef_Action.mDataPerController[UFG::gActiveControllerNum];
      if ( v85 && v85->mActionTrue && v85->mOnSeconds <= 0.0 )
        return *(float *)&FLOAT_1_0;
      return v8;
    case FIS_USER_SIGNAL0:
      if ( pSimObject )
      {
        v86 = pSimObject->m_Flags;
        if ( (v86 & 0x4000) != 0 || v86 < 0 || (v86 & 0x2000) != 0 || (v86 & 0x1000) != 0 )
          v76 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          v76 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( v76 )
          return *(float *)&v76[1].m_NameUID;
      }
      return v8;
    case FIS_USER_SIGNAL1:
      if ( pSimObject )
      {
        v87 = pSimObject->m_Flags;
        if ( (v87 & 0x4000) != 0 || v87 < 0 || (v87 & 0x2000) != 0 || (v87 & 0x1000) != 0 )
          v88 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          v88 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( v88 )
          return *(float *)&v88[1].m_Flags;
      }
      return v8;
    case FIS_USER_SIGNAL2:
      if ( pSimObject )
      {
        v89 = pSimObject->m_Flags;
        if ( (v89 & 0x4000) != 0 || v89 < 0 || (v89 & 0x2000) != 0 || (v89 & 0x1000) != 0 )
          v90 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          v90 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( v90 )
          return *(float *)(&v90[1].m_SimObjIndex + 1);
      }
      return v8;
    case FIS_USER_SIGNAL3:
      if ( pSimObject )
      {
        v91 = pSimObject->m_Flags;
        if ( (v91 & 0x4000) != 0 || v91 < 0 || (v91 & 0x2000) != 0 || (v91 & 0x1000) != 0 )
          v92 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          v92 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( v92 )
          return *(float *)&v92[1].m_pSimObject;
      }
      return v8;
    case FIS_POSEDRIVERTEST_SIGNAL:
      if ( !pSimObject )
        return v8;
      v105 = pSimObject->m_Flags;
      if ( (v105 & 0x4000) != 0 || v105 < 0 )
      {
        v106 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(pSimObject);
      }
      else if ( (v105 & 0x2000) != 0 )
      {
        v106 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)pSimObject);
      }
      else
      {
        v106 = (UFG::CharacterAnimationComponent *)((v105 & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      pSimObject,
                                                      UFG::CharacterAnimationComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      pSimObject,
                                                      UFG::CharacterAnimationComponent::_TypeUID));
      }
      if ( !v106 )
        return v8;
      v107 = v106->mCreature;
      if ( !v107 )
        return v8;
      v108 = v107->mPoseDrivers.mNode.mNext;
      p_m_SafePointerList = &v107->m_SafePointerList;
      v110 = (__int64)&v108[-1];
      if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v110 == p_m_SafePointerList )
        return v8;
      while ( *(_DWORD *)(v110 + 44) != uPoseDriverTest_SignalUID )
      {
        v110 = *(_QWORD *)(v110 + 24) - 16i64;
        if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v110 == p_m_SafePointerList )
          return v8;
      }
      v111 = (float)(*(float *)(v110 + 140) - *(float *)(v110 + 136)) * sSpringSignalRange;
      if ( v111 <= -0.25 )
      {
        v111 = FLOAT_N0_25;
      }
      else if ( v111 >= 0.25 )
      {
        return 0.25 + 0.5;
      }
      return v111 + 0.5;
    case FIS_AIM_INTENTION_DIRECTION_XY_RELATIVE_TO_START:
      if ( pSimObject )
      {
        v112 = pSimObject->m_Flags;
        if ( (v112 & 0x4000) != 0 )
          v113 = pSimObject->m_Components.p[47].m_pComponent;
        else
          v113 = v112 < 0 || (v112 & 0x2000) != 0 || (v112 & 0x1000) != 0
               ? UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::AimingBaseComponent::_TypeUID)
               : UFG::SimObject::GetComponentOfType(pSimObject, UFG::AimingBaseComponent::_TypeUID);
        if ( v113 )
        {
          v114 = *(float *)&v113[2].m_SafePointerList.mNode.mNext;
          v132.x = *((float *)&v113[2].m_SafePointerList.mNode.mPrev + 1);
          v115 = *((float *)&v113[2].m_SafePointerList.mNode.mNext + 1);
          v132.y = v114;
          x = currentFacing->x;
          v132.z = v115;
          v117 = currentFacing->y;
          desiredDirection.x = x;
          desiredDirection.z = currentFacing->z;
          desiredDirection.y = v117;
          return getSignalFromDirection(&v132, &desiredDirection, activeRange);
        }
      }
      return v8;
    case SIM_TIME_SCALE:
      return UFG::Metrics::msInstance.mSimTimeScaleInGame;
    case RAGDOLL_COM_BALANCE_MAG:
    case RAGDOLL_COM_BALANCE_XY_DIR:
      if ( pSimObject )
      {
        v118 = pSimObject->m_Flags;
        if ( (v118 & 0x4000) != 0 || v118 < 0 )
        {
          v119 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(pSimObject);
        }
        else if ( (v118 & 0x2000) != 0 )
        {
          v119 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)pSimObject);
        }
        else
        {
          v119 = (UFG::CharacterAnimationComponent *)((v118 & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        pSimObject,
                                                        UFG::CharacterAnimationComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        pSimObject,
                                                        UFG::CharacterAnimationComponent::_TypeUID));
        }
        v120 = pSimObject->m_Flags;
        v121 = v119;
        if ( (v120 & 0x4000) != 0 )
          v122 = pSimObject->m_Components.p[42].m_pComponent;
        else
          v122 = v120 < 0 || (v120 & 0x2000) != 0 || (v120 & 0x1000) != 0
               ? UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::RagdollComponent::_TypeUID)
               : UFG::SimObject::GetComponentOfType(pSimObject, UFG::RagdollComponent::_TypeUID);
        if ( v121 && v122 )
        {
          v123 = v122[1].m_BoundComponentHandles.mNode.mPrev;
          v124 = v121->mCreature;
          v125 = *(float *)&v123[4].mPrev;
          mPrev_high = (__m128)HIDWORD(v123[4].mPrev);
          if ( v124 )
            Creature::GetTransform(v124, 0, &transform);
          v127 = v125 - transform.v3.x;
          mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - transform.v3.y;
          v132.z = 0.0;
          v132.x = v127;
          LODWORD(v132.y) = mPrev_high.m128_i32[0];
          if ( floatInputSignal == RAGDOLL_COM_BALANCE_XY_DIR )
          {
            v128 = pSimObject->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v128);
            v129 = v128->mWorldTransform.v0.y;
            v130 = v128->mWorldTransform.v0.x;
            desiredDirection.z = v128->mWorldTransform.v0.z;
            desiredDirection.x = v130;
            desiredDirection.y = v129;
            return getSignalFromDirection(&v132, &desiredDirection, activeRange);
          }
          else
          {
            mPrev_high.m128_f32[0] = (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(v127 * v127);
            LODWORD(v8) = _mm_sqrt_ps(mPrev_high).m128_u32[0];
          }
        }
      }
      return v8;
    default:
      return v8;
  }
}0] - transform.v3.y;
          v132.z = 0.0;
          v132.x = v127;
          LODWORD(v132.y) = mPrev_high.m128_i32[0];
          if ( floatInputSignal == RAGDOLL_COM_BALANCE_XY_DIR )
          {
            v128 = pSimObject->m_pTransformNodeComponent;
            UFG::

// File Line: 663
// RVA: 0x275950
void __fastcall setSignalValue(ActionContext *context, FloatInputSignal floatInputSignal, float signal)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v6; // rcx
  __int16 v7; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::SimObjectGame *v16; // rcx
  __int16 v17; // dx
  UFG::SimComponent *v18; // rax
  UFG::SimObjectGame *v19; // rcx
  __int16 v20; // dx
  UFG::SimComponent *v21; // rax

  switch ( floatInputSignal )
  {
    case FIS_STRUGGLE:
      m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) == 0 )
          goto LABEL_5;
        goto LABEL_8;
      }
      return;
    case FIS_STRUGGLE_TARGET:
      v6 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( !v6 )
        return;
      v7 = v6->m_Flags;
      if ( (v7 & 0x4000) != 0 )
      {
        m_pComponent = v6->m_Components.p[20].m_pComponent;
      }
      else if ( v7 >= 0 )
      {
        v9 = (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = v9;
      }
      else
      {
        m_pComponent = v6->m_Components.p[20].m_pComponent;
      }
      if ( !m_pComponent )
        return;
      m_pPointer = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 31i64)
                                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                          + 40);
      if ( !m_pPointer )
        return;
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        goto LABEL_8;
LABEL_5:
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::SimObjectSignalMemoryComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                              m_pPointer,
                              UFG::SimObjectSignalMemoryComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        *(float *)&ComponentOfTypeHK[1].m_TypeUID = signal;
      return;
    case FIS_USER_SIGNAL0:
      v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) != 0 || v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v10, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( ComponentOfType )
          *(float *)&ComponentOfType[1].m_NameUID = signal;
      }
      return;
    case FIS_USER_SIGNAL1:
      v13 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v13 )
      {
        v14 = v13->m_Flags;
        if ( (v14 & 0x4000) != 0 || v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          v15 = UFG::SimObject::GetComponentOfType(v13, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( v15 )
          *(float *)&v15[1].m_Flags = signal;
      }
      return;
    case FIS_USER_SIGNAL2:
      v16 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v16 )
      {
        v17 = v16->m_Flags;
        if ( (v17 & 0x4000) != 0 || v17 < 0 || (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
          v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          v18 = UFG::SimObject::GetComponentOfType(v16, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( v18 )
          *(float *)(&v18[1].m_SimObjIndex + 1) = signal;
      }
      return;
    case FIS_USER_SIGNAL3:
      v19 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v19 )
      {
        v20 = v19->m_Flags;
        if ( (v20 & 0x4000) != 0 || v20 < 0 || (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0 )
          v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        else
          v21 = UFG::SimObject::GetComponentOfType(v19, UFG::SimObjectSignalMemoryComponent::_TypeUID);
        if ( v21 )
          *(float *)&v21[1].m_pSimObject = signal;
      }
      return;
    default:
      return;
  }
}

