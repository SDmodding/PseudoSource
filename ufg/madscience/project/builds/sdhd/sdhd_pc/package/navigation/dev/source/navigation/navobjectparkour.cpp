// File Line: 33
// RVA: 0xE4F20
void __fastcall UFG::NavObjectParkour::NavObjectParkour(UFG::NavObjectParkour *this, UFG::qVector3 *vStartEdgeA, UFG::qVector3 *vStartEdgeB, UFG::qVector3 *vEndEdgeA, UFG::qVector3 *vEndEdgeB, bool isDropDown)
{
  UFG::qVector3 *v6; // rbp
  UFG::qVector3 *v7; // rdi
  UFG::qVector3 *v8; // rbx
  UFG::NavObjectParkour *v9; // r14
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qVector3 vPosition; // [rsp+28h] [rbp-30h]

  v6 = vEndEdgeA;
  v7 = vStartEdgeB;
  v8 = vStartEdgeA;
  v9 = this;
  this->vfptr = (UFG::NavObjectVtbl *)&UFG::NavObject::`vftable;
  this->vfptr = (UFG::NavObjectVtbl *)&UFG::NavObjectParkour::`vftable;
  v10 = (float)(vEndEdgeB->z + vEndEdgeA->z) * 0.5;
  v11 = (float)(vEndEdgeB->y + vEndEdgeA->y) * 0.5;
  vPosition.x = (float)(vEndEdgeA->x + vEndEdgeB->x) * 0.5;
  vPosition.y = v11;
  vPosition.z = v10;
  UFG::NavWaypoint::NavWaypoint(&this->m_waypoint, &vPosition);
  v12 = v8->y;
  v13 = v8->z;
  v9->m_vStartEdgeA.x = v8->x;
  v9->m_vStartEdgeA.y = v12;
  v9->m_vStartEdgeA.z = v13;
  v14 = v7->y;
  v15 = v7->z;
  v9->m_vStartEdgeB.x = v7->x;
  v9->m_vStartEdgeB.y = v14;
  v9->m_vStartEdgeB.z = v15;
  v16 = v6->y;
  v17 = v6->z;
  v9->m_vEndEdgeA.x = v6->x;
  v9->m_vEndEdgeA.y = v16;
  v9->m_vEndEdgeA.z = v17;
  v18 = vEndEdgeB->y;
  v19 = vEndEdgeB->z;
  v9->m_vEndEdgeB.x = vEndEdgeB->x;
  v9->m_vEndEdgeB.y = v18;
  v9->m_vEndEdgeB.z = v19;
  v9->m_bIsDropDown = isDropDown;
  *(_DWORD *)&v9->m_bFireVaultCommand = 0x1000000;
  v9->m_bHasExtraRoom = 0;
}

// File Line: 57
// RVA: 0xE95C0
_BOOL8 __fastcall UFG::NavObjectParkour::CurrentWaypointReached(UFG::NavObjectParkour *this, UFG::NavComponent *navComponent)
{
  return this->m_bVaultCompleted;
}

// File Line: 62
// RVA: 0xEF840
bool __fastcall UFG::NavObjectParkour::IsValidWaypoint(UFG::NavObjectParkour *this, UFG::NavComponent *navComponent)
{
  UFG::NavComponent *v2; // rdi
  UFG::NavObjectParkour *v3; // rbx
  UFG::qVector4 *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v10; // [rsp+30h] [rbp-18h]
  float v11; // [rsp+34h] [rbp-14h]
  float v12; // [rsp+38h] [rbp-10h]
  UFG::NavParams v13; // [rsp+50h] [rbp+8h]

  v2 = navComponent;
  v3 = this;
  if ( *(_WORD *)&this->m_bFireVaultCommand )
    return 1;
  v4 = UFG::NavComponent::GetCurrentPosition(navComponent);
  if ( (float)((float)((float)(v4->y - v3->m_waypoint.m_navPosition.m_vPosition.y)
                     * (float)(v4->y - v3->m_waypoint.m_navPosition.m_vPosition.y))
             + (float)((float)(v4->x - v3->m_waypoint.m_navPosition.m_vPosition.x)
                     * (float)(v4->x - v3->m_waypoint.m_navPosition.m_vPosition.x))) < 0.16000001 )
    return 1;
  v5 = v3->m_vStartEdgeB.x;
  v6 = v3->m_vStartEdgeA.y;
  v13 = v2->m_navParams;
  v7 = (float)(v6 + v3->m_vStartEdgeB.y) * 0.5;
  v8 = v3->m_vStartEdgeA.z + v3->m_vStartEdgeB.z;
  v10 = (float)(v5 + v3->m_vStartEdgeA.x) * 0.5;
  v11 = v7;
  v12 = v8 * 0.5;
  v13.m_fRadius = 0.0;
  return UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
           UFG::NavManager::ms_pInstance,
           &v2->m_navPosition,
           (UFG::qVector3 *)&v10,
           &v13,
           0i64) == 0;
}

// File Line: 89
// RVA: 0xEF590
bool __fastcall UFG::NavObjectParkour::IsInVaultingPosition(UFG::NavObjectParkour *this, UFG::qVector3 *vPosition)
{
  UFG::qVector3 *v2; // rdi
  UFG::NavObjectParkour *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm3_4
  __m128 v8; // xmm4
  __m128 v9; // xmm6
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  bool v14; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-48h]

  v2 = vPosition;
  v3 = this;
  UFG::NavObjectParkour::GetNormal(this, &result);
  v8 = (__m128)LODWORD(result.y);
  v4 = 0.0;
  v5 = (float)(result.x * 0.40000001) + v3->m_vStartEdgeA.x;
  v6 = (float)(result.y * 0.40000001) + v3->m_vStartEdgeA.y;
  v7 = (float)((float)(result.x * 0.40000001) + v3->m_vStartEdgeB.x) - v5;
  v8.m128_f32[0] = (float)((float)(result.y * 0.40000001) + v3->m_vStartEdgeB.y) - v6;
  v9 = v8;
  v9.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7);
  if ( v9.m128_f32[0] != 0.0 )
    v4 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
  v10 = v7 * v4;
  v11 = v8.m128_f32[0] * v4;
  v12 = (float)((float)(v2->y - v6) * v11) + (float)((float)(v2->x - v5) * v10);
  v14 = 0;
  if ( v12 >= -0.050000001 && v12 <= (float)(COERCE_FLOAT(_mm_sqrt_ps(v9)) + 0.050000001) )
  {
    v13 = (float)((float)(v2->x - (float)((float)(v10 * v12) + v5)) * result.x)
        + (float)((float)(v2->y - (float)((float)(v11 * v12) + v6)) * result.y);
    if ( v13 <= 20.0 && v13 >= -3.0 )
      v14 = 1;
  }
  return v14;
}

// File Line: 138
// RVA: 0xED0D0
UFG::qVector3 *__fastcall UFG::NavObjectParkour::GetNormal(UFG::NavObjectParkour *this, UFG::qVector3 *result)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm5_4
  float v6; // xmm4_4
  __m128 v7; // xmm8
  float v8; // xmm7_4
  float v9; // xmm6_4
  __m128 v10; // xmm3
  UFG::qVector3 *v11; // rax

  v2 = this->m_vStartEdgeA.z - this->m_vStartEdgeB.z;
  v7 = (__m128)LODWORD(UFG::qVector3::msAxisZ.x);
  v7.m128_f32[0] = UFG::qVector3::msAxisZ.x * v2;
  v3 = UFG::qVector3::msAxisZ.y * v2;
  v4 = 0.0;
  v5 = this->m_vStartEdgeA.x - this->m_vStartEdgeB.x;
  v6 = this->m_vStartEdgeA.y - this->m_vStartEdgeB.y;
  v7.m128_f32[0] = v7.m128_f32[0] - (float)(UFG::qVector3::msAxisZ.z * v5);
  v8 = (float)(UFG::qVector3::msAxisZ.z * v6) - v3;
  v9 = (float)(UFG::qVector3::msAxisZ.y * v5) - (float)(UFG::qVector3::msAxisZ.x * v6);
  v10 = v7;
  v10.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] != 0.0 )
    v4 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v11 = result;
  result->x = v8 * v4;
  result->y = v7.m128_f32[0] * v4;
  result->z = v9 * v4;
  return v11;
}

// File Line: 158
// RVA: 0xF3750
void __fastcall UFG::NavObjectParkour::UpdateControl(UFG::NavObjectParkour *this, UFG::NavComponent *navComponent)
{
  UFG::NavComponent *v2; // r14
  UFG::NavObjectParkour *v3; // rdi
  UFG::SimObject *v4; // rcx
  UFG::SimComponent *v5; // rsi
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::NavModuleControllerPedestrian *v8; // rbx
  float v9; // xmm0_4
  UFG::qVector3 *v10; // rbx
  unsigned __int8 v11; // bl
  unsigned __int8 v12; // r15
  unsigned __int8 v13; // al
  bool v14; // bl
  UFG::qVector3 result; // [rsp+30h] [rbp-48h]
  UFG::qVector3 closest_point; // [rsp+40h] [rbp-38h]
  UFG::qVector3 v17; // [rsp+50h] [rbp-28h]

  v2 = navComponent;
  v3 = this;
  if ( *(_WORD *)&this->m_bFireVaultCommand )
  {
    v4 = navComponent->m_pSimObject;
    if ( v4 )
      v5 = UFG::SimObject::GetComponentOfType(v4, UFG::AICharacterControllerBaseComponent::_TypeUID);
    else
      v5 = 0i64;
    UFG::NavObjectParkour::GetNormal(v3, &result);
    v6 = result.y;
    v7 = result.z;
    HIDWORD(v5[2].m_SafePointerList.mNode.mNext) = LODWORD(result.x);
    *(float *)&v5[2].m_TypeUID = v6;
    *(float *)&v5[2].m_NameUID = v7;
    v8 = (UFG::NavModuleControllerPedestrian *)v2->m_pNavModuleController;
    v9 = UFG::NavComponent::GetDesiredSpeed(v2);
    UFG::NavModuleControllerPedestrian::SetIntentionSpeed(v8, (Intention *)&v5[2], v9);
    if ( v3->m_bIsDropDown )
    {
      UFG::AICharacterControllerBaseComponent::DoParkour(
        (UFG::AICharacterControllerBaseComponent *)v5,
        &result,
        "Invalid",
        0,
        (Intention *)&v5[2],
        1);
      v3->m_bVaulting = 1;
      v10 = (UFG::qVector3 *)UFG::NavComponent::GetCurrentPosition(v2);
      UFG::qGetClosestPointOnSegment(&closest_point, &v3->m_vStartEdgeA, &v3->m_vStartEdgeB, v10);
      UFG::qGetClosestPointOnSegment(&v17, &v3->m_vEndEdgeA, &v3->m_vEndEdgeB, v10);
      if ( (float)((float)((float)((float)(v10->y - v17.y) * (float)(v10->y - v17.y))
                         + (float)((float)(v10->x - v17.x) * (float)(v10->x - v17.x)))
                 + (float)((float)(v10->z - v17.z) * (float)(v10->z - v17.z))) < (float)((float)((float)((float)(v10->y - closest_point.y) * (float)(v10->y - closest_point.y))
                                                                                               + (float)((float)(v10->x - closest_point.x) * (float)(v10->x - closest_point.x)))
                                                                                       + (float)((float)(v10->z - closest_point.z)
                                                                                               * (float)(v10->z - closest_point.z))) )
        *(_WORD *)&v3->m_bVaulting = 256;
    }
    else
    {
      v11 = UFG::AICharacterControllerBaseComponent::IsPerformingAction(
              (UFG::AICharacterControllerBaseComponent *)v5,
              "Vault");
      v12 = UFG::AICharacterControllerBaseComponent::IsPerformingAction(
              (UFG::AICharacterControllerBaseComponent *)v5,
              "Fall");
      v13 = UFG::AICharacterControllerBaseComponent::IsPerformingAction(
              (UFG::AICharacterControllerBaseComponent *)v5,
              "Land");
      v14 = (v11 || v12) && !v13;
      if ( v3->m_bFireVaultCommand && !v14 )
        UFG::AICharacterControllerBaseComponent::DoParkour(
          (UFG::AICharacterControllerBaseComponent *)v5,
          &result,
          "Vault",
          0x7Fu,
          (Intention *)&v5[2],
          v2->m_bIsSloppyFreeRunner == 0);
      if ( v3->m_bVaulting && !v14 )
        v3->m_bVaultCompleted = 1;
      v3->m_bVaulting = v14;
    }
  }
}

// File Line: 245
// RVA: 0xF2C70
void __fastcall UFG::NavObjectParkour::Update(UFG::NavObjectParkour *this, UFG::NavComponent *navComponent)
{
  UFG::NavComponent *v2; // rdi
  UFG::NavObjectParkour *v3; // rbx
  UFG::SimObject *v4; // rcx
  UFG::qVector3 *v5; // rsi
  float v6; // xmm0_4
  float v7; // xmm1_4
  __int64 v8; // rax
  __int64 v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm2_4
  char v12; // al
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm9_4
  float v16; // xmm10_4
  float v17; // xmm11_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm12_4
  __m128 v22; // xmm13
  float v23; // xmm14_4
  float v24; // xmm0_4
  float v25; // xmm12_4
  float v26; // xmm14_4
  __m128 v27; // xmm2
  float v28; // xmm5_4
  float v29; // xmm15_4
  float v30; // xmm12_4
  float v31; // xmm13_4
  float v32; // xmm14_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm8_4
  UFG::NavModuleLocal *v39; // r14
  float v40; // xmm4_4
  float v41; // xmm0_4
  float v42; // xmm6_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm10_4
  float v46; // xmm11_4
  float v47; // xmm5_4
  float v48; // xmm2_4
  float v49; // xmm7_4
  __int128 v50; // xmm3
  __m128 v51; // xmm1
  float v52; // xmm4_4
  int v53; // xmm0_4
  __m128 v54; // xmm1
  float v55; // xmm0_4
  float v56; // xmm0_4
  float v57; // xmm2_4
  float v58; // xmm8_4
  float v59; // xmm4_4
  __m128 v60; // xmm1
  __m128 v61; // xmm5
  float v62; // xmm1_4
  UFG::NavWaypoint *v63; // rdx
  float v64; // xmm0_4
  float v65; // xmm1_4
  bool v66; // al
  UFG::qVector3 vEnd; // [rsp+40h] [rbp-98h]
  UFG::qVector3 result; // [rsp+50h] [rbp-88h]
  UFG::qVector2 vOutRadiusCenter; // [rsp+60h] [rbp-78h]
  __int64 v70; // [rsp+68h] [rbp-70h]
  UFG::qVector2 vOutRadiusTangent; // [rsp+70h] [rbp-68h]
  UFG::NavWaypoint v72; // [rsp+78h] [rbp-60h]
  UFG::qVector2 vPointB; // [rsp+198h] [rbp+C0h]
  float fOutRadius; // [rsp+1A0h] [rbp+C8h]
  UFG::qVector2 vPointADirection; // [rsp+1A8h] [rbp+D0h]
  UFG::qVector2 vPointA; // [rsp+1B0h] [rbp+D8h]

  v70 = -2i64;
  v2 = navComponent;
  v3 = this;
  v4 = navComponent->m_pSimObject;
  if ( v4 )
    UFG::SimObject::GetComponentOfType(v4, UFG::AICharacterControllerBaseComponent::_TypeUID);
  v5 = (UFG::qVector3 *)UFG::NavComponent::GetCurrentPosition(v2);
  v3->m_bFireVaultCommand = 0;
  if ( v3->m_bVaulting )
  {
    v6 = UFG::NavComponent::GetDesiredSpeed(v2);
    v7 = *(float *)&FLOAT_1_0;
    if ( v6 >= 1.0 )
      v7 = v6;
    v3->m_fSpeed = v7;
    UFG::NavObjectParkour::GetNormal(v3, &result);
    UFG::NavWaypoint::NavWaypoint(&v72);
    v9 = v8;
    v10 = *(float *)(v8 + 12);
    v11 = *(float *)(v8 + 16);
    v3->m_waypoint.m_navPosition.m_vPosition.x = *(float *)(v8 + 8);
    v3->m_waypoint.m_navPosition.m_vPosition.y = v10;
    v3->m_waypoint.m_navPosition.m_vPosition.z = v11;
    v12 = *(_BYTE *)(v8 + 24);
    if ( v12 )
    {
      v3->m_waypoint.m_navPosition.m_bValid = v12;
      v3->m_waypoint.m_navPosition.m_hkvMeshPosition = *(hkVector4f *)(v9 + 32);
      v3->m_waypoint.m_navPosition.m_packedKey = *(_DWORD *)(v9 + 48);
      v3->m_waypoint.m_navPosition.m_aiMeshUid = *(_DWORD *)(v9 + 52);
    }
    else
    {
      v3->m_waypoint.m_navPosition.m_bValid = 0;
    }
    v3->m_waypoint.m_pNavObject = *(UFG::NavObject **)(v9 + 64);
    v3->m_waypoint.m_stopPoint = *(_BYTE *)(v9 + 72);
    v3->m_waypoint.m_goalPoint = *(_BYTE *)(v9 + 73);
    v3->m_waypoint.m_canSmooth = *(_BYTE *)(v9 + 74);
    _((AMD_HD3D *)&v72);
    v13 = (float)(result.y * 3.0) + v5->y;
    v14 = (float)(result.z * 3.0) + v5->z;
    v3->m_waypoint.m_navPosition.m_vPosition.x = (float)(result.x * 3.0) + v5->x;
    v3->m_waypoint.m_navPosition.m_vPosition.y = v13;
    v3->m_waypoint.m_navPosition.m_vPosition.z = v14;
    v3->m_waypoint.m_navPosition.m_bValid = 0;
    v3->m_waypoint.m_stopPoint = 0;
    v3->m_waypoint.m_canSmooth = 0;
  }
  else
  {
    UFG::NavObjectParkour::GetNormal(v3, &result);
    v15 = result.x;
    v16 = result.y;
    v22 = (__m128)LODWORD(result.y);
    v17 = result.z;
    v18 = (float)(result.x * 0.40000001) + v3->m_vStartEdgeA.x;
    v19 = (float)(result.y * 0.40000001) + v3->m_vStartEdgeA.y;
    v20 = (float)(result.z * 0.40000001) + v3->m_vStartEdgeA.z;
    v21 = (float)(result.x * 0.40000001) + v3->m_vStartEdgeB.x;
    v22.m128_f32[0] = (float)(result.y * 0.40000001) + v3->m_vStartEdgeB.y;
    v23 = (float)(result.z * 0.40000001) + v3->m_vStartEdgeB.z;
    if ( v3->m_bFirstRun )
    {
      v3->m_bFirstRun = 0;
      vEnd.x = (float)(v21 + v18) * 0.5;
      vEnd.y = (float)(v22.m128_f32[0] + v19) * 0.5;
      vEnd.z = (float)(v23 + v20) * 0.5;
      result.x = vEnd.x - v15;
      result.y = vEnd.y - v16;
      result.z = vEnd.z - v17;
      v3->m_bHasExtraRoom = UFG::NavComponent::AIRayCastHits(v2, &vEnd, &result);
    }
    v24 = UFG::NavComponent::GetDesiredSpeed(v2);
    vPointB.x = v24;
    v3->m_fSpeed = v24;
    v25 = v21 - v18;
    v22.m128_f32[0] = v22.m128_f32[0] - v19;
    v26 = v23 - v20;
    v27 = v22;
    v27.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v25 * v25)) + (float)(v26 * v26);
    LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v27);
    v29 = *(float *)&FLOAT_1_0;
    v30 = v25 * (float)(1.0 / v28);
    v31 = v22.m128_f32[0] * (float)(1.0 / v28);
    v32 = v26 * (float)(1.0 / v28);
    v33 = (float)(v31 * (float)(v5->y - v19)) + (float)(v30 * (float)(v5->x - v18));
    v34 = v2->m_navParams.m_fRadius;
    if ( v34 >= (float)(v28 * 0.5) )
      v34 = v28 * 0.5;
    v35 = v28 - v34;
    if ( v33 <= v34 )
      v33 = v34;
    if ( v33 >= v35 )
      v33 = v35;
    v36 = v18 + (float)(v30 * v33);
    v37 = v19 + (float)(v31 * v33);
    v38 = v20 + (float)(v32 * v33);
    v39 = v2->m_pNavModuleLocal;
    ((void (__fastcall *)(UFG::NavModuleLocal *))v39->vfptr->GetTurningRadius)(v2->m_pNavModuleLocal);
    v40 = v34;
    if ( v3->m_bHasExtraRoom )
    {
      v36 = v36 - v15;
      v37 = v37 - v16;
      v38 = v38 - v17;
    }
    vEnd.z = v38;
    vEnd.y = v37;
    vEnd.x = v36;
    vPointB.x = v5->x;
    v41 = vPointB.x;
    vPointB.y = v5->y;
    vPointADirection.x = v15;
    vPointADirection.y = v16;
    vPointA.x = v36;
    vPointA.y = v37;
    v42 = 0.0;
    UFG::NavModuleLocal::GetPointDirectionRadius(
      &vPointA,
      &vPointADirection,
      &vPointB,
      v40,
      &vOutRadiusCenter,
      &vOutRadiusTangent,
      &fOutRadius,
      0.0);
    ((void (__fastcall *)(UFG::NavModuleLocal *))v39->vfptr->GetMaxSpeedForRadius)(v39);
    v3->m_fSpeed = v41;
    v43 = v5->z;
    v44 = (float)(vOutRadiusTangent.y * 2.0) + v5->y;
    vOutRadiusCenter.x = (float)(vOutRadiusTangent.x * 2.0) + v5->x;
    vOutRadiusCenter.y = v44;
    *(float *)&v70 = v43;
    if ( UFG::NavObjectParkour::IsInVaultingPosition(v3, v5) )
    {
      v45 = (float)(v16 * 2.0) + v5->y;
      v46 = (float)(v17 * 2.0) + v5->z;
      vOutRadiusCenter.x = (float)(v15 * 2.0) + v5->x;
      vOutRadiusCenter.y = v45;
      *(float *)&v70 = v46;
      v3->m_bFireVaultCommand = 1;
    }
    UFG::NavComponent::AIRayCastHits(v2, (UFG::qVector3 *)&vOutRadiusCenter, (UFG::qVector3 *)&v72);
    v47 = v5->x;
    v48 = *(float *)&v72.m_navPosition.vfptr - v5->x;
    v49 = v5->y;
    v50 = HIDWORD(v72.m_navPosition.vfptr);
    *(float *)&v50 = *((float *)&v72.m_navPosition.vfptr + 1) - v49;
    v51 = (__m128)v50;
    v51.m128_f32[0] = (float)(*(float *)&v50 * *(float *)&v50) + (float)(v48 * v48);
    LODWORD(v52) = (unsigned __int128)_mm_sqrt_ps(v51);
    *(float *)&v53 = v52;
    if ( v52 < 0.0 )
      v53 = LODWORD(v52) ^ _xmm[0];
    if ( *(float *)&v53 < 0.001 )
    {
      v48 = vOutRadiusCenter.x - v47;
      v50 = LODWORD(vOutRadiusCenter.y);
      *(float *)&v50 = vOutRadiusCenter.y - v49;
      v54 = (__m128)v50;
      v54.m128_f32[0] = (float)(*(float *)&v50 * *(float *)&v50) + (float)(v48 * v48);
      LODWORD(v52) = (unsigned __int128)_mm_sqrt_ps(v54);
    }
    v55 = FLOAT_0_1;
    if ( (float)(v52 - 0.1) >= 0.1 )
      v55 = v52 - 0.1;
    v56 = v55 / v52;
    v57 = (float)(v48 * v56) + v47;
    *(float *)&v50 = (float)(*(float *)&v50 * v56) + v49;
    v58 = v5->z;
    v59 = v57 - v47;
    v60 = (__m128)v50;
    v60.m128_f32[0] = *(float *)&v50 - v49;
    v61 = v60;
    v61.m128_f32[0] = (float)(v60.m128_f32[0] * v60.m128_f32[0]) + (float)(v59 * v59);
    if ( v61.m128_f32[0] != 0.0 )
      v42 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v61));
    v62 = (float)((float)((float)(v60.m128_f32[0] * v42) * v2->m_vForward.y)
                + (float)((float)(v59 * v42) * v2->m_vForward.x))
        * v3->m_fSpeed;
    if ( v62 >= 1.0 )
      v29 = v62;
    v3->m_fSpeed = v29;
    v63 = v2->m_pNavModulePathing->m_pPath.m_pNavPath->m_aWaypoints.p;
    v64 = v63->m_navPosition.m_vPosition.y;
    v65 = v63->m_navPosition.m_vPosition.z;
    v3->m_waypoint.m_navPosition.m_vPosition.x = v63->m_navPosition.m_vPosition.x;
    v3->m_waypoint.m_navPosition.m_vPosition.y = v64;
    v3->m_waypoint.m_navPosition.m_vPosition.z = v65;
    v66 = v63->m_navPosition.m_bValid;
    if ( v66 )
    {
      v3->m_waypoint.m_navPosition.m_bValid = v66;
      v3->m_waypoint.m_navPosition.m_hkvMeshPosition = v63->m_navPosition.m_hkvMeshPosition;
      v3->m_waypoint.m_navPosition.m_packedKey = v63->m_navPosition.m_packedKey;
      v3->m_waypoint.m_navPosition.m_aiMeshUid = v63->m_navPosition.m_aiMeshUid;
    }
    else
    {
      v3->m_waypoint.m_navPosition.m_bValid = 0;
    }
    v3->m_waypoint.m_pNavObject = v63->m_pNavObject;
    v3->m_waypoint.m_stopPoint = v63->m_stopPoint;
    v3->m_waypoint.m_goalPoint = v63->m_goalPoint;
    v3->m_waypoint.m_navPosition.m_vPosition.x = v57;
    LODWORD(v3->m_waypoint.m_navPosition.m_vPosition.y) = v50;
    v3->m_waypoint.m_navPosition.m_vPosition.z = v58;
    v3->m_waypoint.m_navPosition.m_bValid = 0;
    v3->m_waypoint.m_stopPoint = 0;
    v3->m_waypoint.m_canSmooth = 0;
    if ( v3->m_bFireVaultCommand && !v3->m_bIsDropDown )
      v3->m_fSpeed = 0.0;
  }
}

