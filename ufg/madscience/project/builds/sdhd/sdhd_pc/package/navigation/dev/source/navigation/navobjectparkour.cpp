// File Line: 33
// RVA: 0xE4F20
void __fastcall UFG::NavObjectParkour::NavObjectParkour(
        UFG::NavObjectParkour *this,
        UFG::qVector3 *vStartEdgeA,
        UFG::qVector3 *vStartEdgeB,
        UFG::qVector3 *vEndEdgeA,
        UFG::qVector3 *vEndEdgeB,
        bool isDropDown)
{
  float v10; // xmm3_4
  float v11; // xmm2_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qVector3 vPosition; // [rsp+28h] [rbp-30h] BYREF

  this->vfptr = (UFG::NavObjectVtbl *)&UFG::NavObject::`vftable;
  this->vfptr = (UFG::NavObjectVtbl *)&UFG::NavObjectParkour::`vftable;
  v10 = (float)(vEndEdgeB->z + vEndEdgeA->z) * 0.5;
  v11 = (float)(vEndEdgeB->y + vEndEdgeA->y) * 0.5;
  vPosition.x = (float)(vEndEdgeA->x + vEndEdgeB->x) * 0.5;
  vPosition.y = v11;
  vPosition.z = v10;
  UFG::NavWaypoint::NavWaypoint(&this->m_waypoint, &vPosition);
  y = vStartEdgeA->y;
  z = vStartEdgeA->z;
  this->m_vStartEdgeA.x = vStartEdgeA->x;
  this->m_vStartEdgeA.y = y;
  this->m_vStartEdgeA.z = z;
  v14 = vStartEdgeB->y;
  v15 = vStartEdgeB->z;
  this->m_vStartEdgeB.x = vStartEdgeB->x;
  this->m_vStartEdgeB.y = v14;
  this->m_vStartEdgeB.z = v15;
  v16 = vEndEdgeA->y;
  v17 = vEndEdgeA->z;
  this->m_vEndEdgeA.x = vEndEdgeA->x;
  this->m_vEndEdgeA.y = v16;
  this->m_vEndEdgeA.z = v17;
  v18 = vEndEdgeB->y;
  v19 = vEndEdgeB->z;
  this->m_vEndEdgeB.x = vEndEdgeB->x;
  this->m_vEndEdgeB.y = v18;
  this->m_vEndEdgeB.z = v19;
  this->m_bIsDropDown = isDropDown;
  *(_DWORD *)&this->m_bFireVaultCommand = 0x1000000;
  this->m_bHasExtraRoom = 0;
}

// File Line: 57
// RVA: 0xE95C0
_BOOL8 __fastcall UFG::NavObjectParkour::CurrentWaypointReached(
        UFG::NavObjectParkour *this,
        UFG::NavComponent *navComponent)
{
  return this->m_bVaultCompleted;
}

// File Line: 62
// RVA: 0xEF840
bool __fastcall UFG::NavObjectParkour::IsValidWaypoint(UFG::NavObjectParkour *this, UFG::NavComponent *navComponent)
{
  UFG::qVector4 *CurrentPosition; // rax
  float x; // xmm1_4
  float y; // xmm2_4
  int v7; // xmm2_4
  float v8; // xmm3_4
  int v10[6]; // [rsp+30h] [rbp-18h] BYREF
  UFG::NavParams m_navParams; // [rsp+50h] [rbp+8h] BYREF

  if ( *(_WORD *)&this->m_bFireVaultCommand )
    return 1;
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(navComponent);
  if ( (float)((float)((float)(CurrentPosition->y - this->m_waypoint.m_navPosition.m_vPosition.y)
                     * (float)(CurrentPosition->y - this->m_waypoint.m_navPosition.m_vPosition.y))
             + (float)((float)(CurrentPosition->x - this->m_waypoint.m_navPosition.m_vPosition.x)
                     * (float)(CurrentPosition->x - this->m_waypoint.m_navPosition.m_vPosition.x))) < 0.16000001 )
    return 1;
  x = this->m_vStartEdgeB.x;
  y = this->m_vStartEdgeA.y;
  m_navParams = navComponent->m_navParams;
  *(float *)&v7 = (float)(y + this->m_vStartEdgeB.y) * 0.5;
  v8 = this->m_vStartEdgeA.z + this->m_vStartEdgeB.z;
  *(float *)v10 = (float)(x + this->m_vStartEdgeA.x) * 0.5;
  v10[1] = v7;
  *(float *)&v10[2] = v8 * 0.5;
  m_navParams.m_fRadius = 0.0;
  return !UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
            UFG::NavManager::ms_pInstance,
            &navComponent->m_navPosition,
            (UFG::qVector3 *)v10,
            &m_navParams,
            0i64);
}

// File Line: 89
// RVA: 0xEF590
bool __fastcall UFG::NavObjectParkour::IsInVaultingPosition(UFG::NavObjectParkour *this, UFG::qVector3 *vPosition)
{
  float v4; // xmm1_4
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm3_4
  __m128 y_low; // xmm4
  __m128 v9; // xmm6
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  bool v14; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-48h] BYREF

  UFG::NavObjectParkour::GetNormal(this, &result);
  y_low = (__m128)LODWORD(result.y);
  v4 = 0.0;
  v5 = (float)(result.x * 0.40000001) + this->m_vStartEdgeA.x;
  v6 = (float)(result.y * 0.40000001) + this->m_vStartEdgeA.y;
  v7 = (float)((float)(result.x * 0.40000001) + this->m_vStartEdgeB.x) - v5;
  y_low.m128_f32[0] = (float)((float)(result.y * 0.40000001) + this->m_vStartEdgeB.y) - v6;
  v9 = y_low;
  v9.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v7 * v7);
  if ( v9.m128_f32[0] != 0.0 )
    v4 = 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
  v10 = v7 * v4;
  v11 = y_low.m128_f32[0] * v4;
  v12 = (float)((float)(vPosition->y - v6) * v11) + (float)((float)(vPosition->x - v5) * v10);
  v14 = 0;
  if ( v12 >= -0.050000001 && v12 <= (float)(_mm_sqrt_ps(v9).m128_f32[0] + 0.050000001) )
  {
    v13 = (float)((float)(vPosition->x - (float)((float)(v10 * v12) + v5)) * result.x)
        + (float)((float)(vPosition->y - (float)((float)(v11 * v12) + v6)) * result.y);
    if ( v13 <= 20.0 && v13 >= -3.0 )
      return 1;
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
  __m128 x_low; // xmm8
  float v8; // xmm7_4
  float v9; // xmm6_4
  __m128 v10; // xmm3
  UFG::qVector3 *v11; // rax

  v2 = this->m_vStartEdgeA.z - this->m_vStartEdgeB.z;
  x_low = (__m128)LODWORD(UFG::qVector3::msAxisZ.x);
  x_low.m128_f32[0] = UFG::qVector3::msAxisZ.x * v2;
  v3 = UFG::qVector3::msAxisZ.y * v2;
  v4 = 0.0;
  v5 = this->m_vStartEdgeA.x - this->m_vStartEdgeB.x;
  v6 = this->m_vStartEdgeA.y - this->m_vStartEdgeB.y;
  x_low.m128_f32[0] = x_low.m128_f32[0] - (float)(UFG::qVector3::msAxisZ.z * v5);
  v8 = (float)(UFG::qVector3::msAxisZ.z * v6) - v3;
  v9 = (float)(UFG::qVector3::msAxisZ.y * v5) - (float)(UFG::qVector3::msAxisZ.x * v6);
  v10 = x_low;
  v10.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] != 0.0 )
    v4 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v11 = result;
  result->x = v8 * v4;
  result->y = x_low.m128_f32[0] * v4;
  result->z = v9 * v4;
  return v11;
}

// File Line: 158
// RVA: 0xF3750
void __fastcall UFG::NavObjectParkour::UpdateControl(UFG::NavObjectParkour *this, UFG::NavComponent *navComponent)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rsi
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::NavModuleControllerPedestrian *m_pNavModuleController; // rbx
  float DesiredSpeed; // xmm0_4
  UFG::qVector3 *CurrentPosition; // rbx
  unsigned __int8 IsPerformingAction; // bl
  unsigned __int8 v12; // r15
  unsigned __int8 v13; // al
  bool v14; // bl
  UFG::qVector3 result; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector3 closest_point; // [rsp+40h] [rbp-38h] BYREF
  UFG::qVector3 v17; // [rsp+50h] [rbp-28h] BYREF

  if ( *(_WORD *)&this->m_bFireVaultCommand )
  {
    m_pSimObject = navComponent->m_pSimObject;
    if ( m_pSimObject )
      ComponentOfType = UFG::SimObject::GetComponentOfType(
                          m_pSimObject,
                          UFG::AICharacterControllerBaseComponent::_TypeUID);
    else
      ComponentOfType = 0i64;
    UFG::NavObjectParkour::GetNormal(this, &result);
    y = result.y;
    z = result.z;
    HIDWORD(ComponentOfType[2].m_SafePointerList.mNode.mNext) = LODWORD(result.x);
    *(float *)&ComponentOfType[2].m_TypeUID = y;
    *(float *)&ComponentOfType[2].m_NameUID = z;
    m_pNavModuleController = (UFG::NavModuleControllerPedestrian *)navComponent->m_pNavModuleController;
    DesiredSpeed = UFG::NavComponent::GetDesiredSpeed(navComponent);
    UFG::NavModuleControllerPedestrian::SetIntentionSpeed(
      m_pNavModuleController,
      (Intention *)&ComponentOfType[2],
      DesiredSpeed);
    if ( this->m_bIsDropDown )
    {
      UFG::AICharacterControllerBaseComponent::DoParkour(
        (UFG::AICharacterControllerBaseComponent *)ComponentOfType,
        &result,
        "Invalid",
        0,
        (Intention *)&ComponentOfType[2],
        1);
      this->m_bVaulting = 1;
      CurrentPosition = (UFG::qVector3 *)UFG::NavComponent::GetCurrentPosition(navComponent);
      UFG::qGetClosestPointOnSegment(&closest_point, &this->m_vStartEdgeA, &this->m_vStartEdgeB, CurrentPosition);
      UFG::qGetClosestPointOnSegment(&v17, &this->m_vEndEdgeA, &this->m_vEndEdgeB, CurrentPosition);
      if ( (float)((float)((float)((float)(CurrentPosition->y - v17.y) * (float)(CurrentPosition->y - v17.y))
                         + (float)((float)(CurrentPosition->x - v17.x) * (float)(CurrentPosition->x - v17.x)))
                 + (float)((float)(CurrentPosition->z - v17.z) * (float)(CurrentPosition->z - v17.z))) < (float)((float)((float)((float)(CurrentPosition->y - closest_point.y) * (float)(CurrentPosition->y - closest_point.y)) + (float)((float)(CurrentPosition->x - closest_point.x) * (float)(CurrentPosition->x - closest_point.x))) + (float)((float)(CurrentPosition->z - closest_point.z) * (float)(CurrentPosition->z - closest_point.z))) )
        *(_WORD *)&this->m_bVaulting = 256;
    }
    else
    {
      IsPerformingAction = UFG::AICharacterControllerBaseComponent::IsPerformingAction(
                             (UFG::AICharacterControllerBaseComponent *)ComponentOfType,
                             "Vault");
      v12 = UFG::AICharacterControllerBaseComponent::IsPerformingAction(
              (UFG::AICharacterControllerBaseComponent *)ComponentOfType,
              "Fall");
      v13 = UFG::AICharacterControllerBaseComponent::IsPerformingAction(
              (UFG::AICharacterControllerBaseComponent *)ComponentOfType,
              "Land");
      v14 = (IsPerformingAction || v12) && !v13;
      if ( this->m_bFireVaultCommand && !v14 )
        UFG::AICharacterControllerBaseComponent::DoParkour(
          (UFG::AICharacterControllerBaseComponent *)ComponentOfType,
          &result,
          "Vault",
          0x7Fu,
          (Intention *)&ComponentOfType[2],
          !navComponent->m_bIsSloppyFreeRunner);
      if ( this->m_bVaulting && !v14 )
        this->m_bVaultCompleted = 1;
      this->m_bVaulting = v14;
    }
  }
}

// File Line: 245
// RVA: 0xF2C70
void __fastcall UFG::NavObjectParkour::Update(UFG::NavObjectParkour *this, UFG::NavComponent *navComponent)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qVector2 *CurrentPosition; // rsi
  float DesiredSpeed; // xmm0_4
  float v7; // xmm1_4
  __int64 v8; // rax
  __int64 v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm2_4
  char v12; // al
  float v13; // xmm2_4
  float v14; // xmm1_4
  float x; // xmm9_4
  float y; // xmm10_4
  float z; // xmm11_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm12_4
  __m128 y_low; // xmm13
  float v23; // xmm14_4
  float v24; // xmm12_4
  float v25; // xmm14_4
  __m128 v26; // xmm2
  float v27; // xmm5_4
  float v28; // xmm15_4
  float v29; // xmm12_4
  float v30; // xmm13_4
  float v31; // xmm14_4
  float v32; // xmm1_4
  float m_fRadius; // xmm0_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm8_4
  UFG::NavModuleLocal *m_pNavModuleLocal; // r14
  double v39; // xmm0_8
  float v40; // xmm6_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm10_4
  float v44; // xmm11_4
  float v45; // xmm5_4
  float v46; // xmm2_4
  float v47; // xmm7_4
  __int128 vfptr_high; // xmm3
  __m128 v49; // xmm1
  float v50; // xmm4_4
  int v51; // xmm0_4
  __m128 v52; // xmm1
  float v53; // xmm0_4
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm8_4
  float v57; // xmm4_4
  __m128 v58; // xmm1
  __m128 v59; // xmm5
  float v60; // xmm1_4
  UFG::NavWaypoint *p; // rdx
  float v62; // xmm0_4
  float v63; // xmm1_4
  bool m_bValid; // al
  UFG::qVector3 vEnd; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-88h] BYREF
  UFG::qVector2 vOutRadiusCenter; // [rsp+60h] [rbp-78h] BYREF
  __int64 v68; // [rsp+68h] [rbp-70h]
  UFG::qVector2 vOutRadiusTangent; // [rsp+70h] [rbp-68h] BYREF
  UFG::NavWaypoint v70; // [rsp+78h] [rbp-60h] BYREF
  UFG::qVector2 vPointB; // [rsp+198h] [rbp+C0h] BYREF
  float fOutRadius; // [rsp+1A0h] [rbp+C8h] BYREF
  UFG::qVector2 vPointADirection; // [rsp+1A8h] [rbp+D0h] BYREF
  UFG::qVector2 vPointA; // [rsp+1B0h] [rbp+D8h] BYREF

  v68 = -2i64;
  m_pSimObject = navComponent->m_pSimObject;
  if ( m_pSimObject )
    UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AICharacterControllerBaseComponent::_TypeUID);
  CurrentPosition = (UFG::qVector2 *)UFG::NavComponent::GetCurrentPosition(navComponent);
  this->m_bFireVaultCommand = 0;
  if ( this->m_bVaulting )
  {
    DesiredSpeed = UFG::NavComponent::GetDesiredSpeed(navComponent);
    v7 = *(float *)&FLOAT_1_0;
    if ( DesiredSpeed >= 1.0 )
      v7 = DesiredSpeed;
    this->m_fSpeed = v7;
    UFG::NavObjectParkour::GetNormal(this, &result);
    UFG::NavWaypoint::NavWaypoint(&v70);
    v9 = v8;
    v10 = *(float *)(v8 + 12);
    v11 = *(float *)(v8 + 16);
    this->m_waypoint.m_navPosition.m_vPosition.x = *(float *)(v8 + 8);
    this->m_waypoint.m_navPosition.m_vPosition.y = v10;
    this->m_waypoint.m_navPosition.m_vPosition.z = v11;
    v12 = *(_BYTE *)(v8 + 24);
    if ( v12 )
    {
      this->m_waypoint.m_navPosition.m_bValid = v12;
      this->m_waypoint.m_navPosition.m_hkvMeshPosition = *(hkVector4f *)(v9 + 32);
      this->m_waypoint.m_navPosition.m_packedKey = *(_DWORD *)(v9 + 48);
      this->m_waypoint.m_navPosition.m_aiMeshUid = *(_DWORD *)(v9 + 52);
    }
    else
    {
      this->m_waypoint.m_navPosition.m_bValid = 0;
    }
    this->m_waypoint.m_pNavObject = *(UFG::NavObject **)(v9 + 64);
    this->m_waypoint.m_stopPoint = *(_BYTE *)(v9 + 72);
    this->m_waypoint.m_goalPoint = *(_BYTE *)(v9 + 73);
    this->m_waypoint.m_canSmooth = *(_BYTE *)(v9 + 74);
    _((AMD_HD3D *)&v70);
    v13 = (float)(result.y * 3.0) + CurrentPosition->y;
    v14 = (float)(result.z * 3.0) + CurrentPosition[1].x;
    this->m_waypoint.m_navPosition.m_vPosition.x = (float)(result.x * 3.0) + CurrentPosition->x;
    this->m_waypoint.m_navPosition.m_vPosition.y = v13;
    this->m_waypoint.m_navPosition.m_vPosition.z = v14;
    this->m_waypoint.m_navPosition.m_bValid = 0;
    this->m_waypoint.m_stopPoint = 0;
    this->m_waypoint.m_canSmooth = 0;
  }
  else
  {
    UFG::NavObjectParkour::GetNormal(this, &result);
    x = result.x;
    y = result.y;
    y_low = (__m128)LODWORD(result.y);
    z = result.z;
    v18 = (float)(result.x * 0.40000001) + this->m_vStartEdgeA.x;
    v19 = (float)(result.y * 0.40000001) + this->m_vStartEdgeA.y;
    v20 = (float)(result.z * 0.40000001) + this->m_vStartEdgeA.z;
    v21 = (float)(result.x * 0.40000001) + this->m_vStartEdgeB.x;
    y_low.m128_f32[0] = (float)(result.y * 0.40000001) + this->m_vStartEdgeB.y;
    v23 = (float)(result.z * 0.40000001) + this->m_vStartEdgeB.z;
    if ( this->m_bFirstRun )
    {
      this->m_bFirstRun = 0;
      vEnd.x = (float)(v21 + v18) * 0.5;
      vEnd.y = (float)(y_low.m128_f32[0] + v19) * 0.5;
      vEnd.z = (float)(v23 + v20) * 0.5;
      result.x = vEnd.x - x;
      result.y = vEnd.y - y;
      result.z = vEnd.z - z;
      this->m_bHasExtraRoom = UFG::NavComponent::AIRayCastHits(navComponent, &vEnd, &result);
    }
    vPointB.x = UFG::NavComponent::GetDesiredSpeed(navComponent);
    this->m_fSpeed = vPointB.x;
    v24 = v21 - v18;
    y_low.m128_f32[0] = y_low.m128_f32[0] - v19;
    v25 = v23 - v20;
    v26 = y_low;
    v26.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v24 * v24)) + (float)(v25 * v25);
    v27 = _mm_sqrt_ps(v26).m128_f32[0];
    v28 = *(float *)&FLOAT_1_0;
    v29 = v24 * (float)(1.0 / v27);
    v30 = y_low.m128_f32[0] * (float)(1.0 / v27);
    v31 = v25 * (float)(1.0 / v27);
    v32 = (float)(v30 * (float)(CurrentPosition->y - v19)) + (float)(v29 * (float)(CurrentPosition->x - v18));
    m_fRadius = navComponent->m_navParams.m_fRadius;
    if ( m_fRadius >= (float)(v27 * 0.5) )
      m_fRadius = v27 * 0.5;
    v34 = v27 - m_fRadius;
    if ( v32 <= m_fRadius )
      v32 = m_fRadius;
    if ( v32 >= v34 )
      v32 = v34;
    v35 = v18 + (float)(v29 * v32);
    v36 = v19 + (float)(v30 * v32);
    v37 = v20 + (float)(v31 * v32);
    m_pNavModuleLocal = navComponent->m_pNavModuleLocal;
    v39 = ((double (__fastcall *)(UFG::NavModuleLocal *))m_pNavModuleLocal->vfptr->GetTurningRadius)(m_pNavModuleLocal);
    if ( this->m_bHasExtraRoom )
    {
      v35 = v35 - x;
      v36 = v36 - y;
      v37 = v37 - z;
    }
    vEnd.z = v37;
    vEnd.y = v36;
    vEnd.x = v35;
    vPointB = *CurrentPosition;
    vPointADirection.x = x;
    vPointADirection.y = y;
    vPointA.x = v35;
    vPointA.y = v36;
    v40 = 0.0;
    UFG::NavModuleLocal::GetPointDirectionRadius(
      &vPointA,
      &vPointADirection,
      &vPointB,
      *(float *)&v39,
      &vOutRadiusCenter,
      &vOutRadiusTangent,
      &fOutRadius,
      0.0);
    this->m_fSpeed = ((float (__fastcall *)(UFG::NavModuleLocal *))m_pNavModuleLocal->vfptr->GetMaxSpeedForRadius)(m_pNavModuleLocal);
    v41 = CurrentPosition[1].x;
    v42 = (float)(vOutRadiusTangent.y * 2.0) + CurrentPosition->y;
    vOutRadiusCenter.x = (float)(vOutRadiusTangent.x * 2.0) + CurrentPosition->x;
    vOutRadiusCenter.y = v42;
    *(float *)&v68 = v41;
    if ( UFG::NavObjectParkour::IsInVaultingPosition(this, (UFG::qVector3 *)CurrentPosition) )
    {
      v43 = (float)(y * 2.0) + CurrentPosition->y;
      v44 = (float)(z * 2.0) + CurrentPosition[1].x;
      vOutRadiusCenter.x = (float)(x * 2.0) + CurrentPosition->x;
      vOutRadiusCenter.y = v43;
      *(float *)&v68 = v44;
      this->m_bFireVaultCommand = 1;
    }
    UFG::NavComponent::AIRayCastHits(navComponent, (UFG::qVector3 *)&vOutRadiusCenter, (UFG::qVector3 *)&v70);
    v45 = CurrentPosition->x;
    v46 = *(float *)&v70.m_navPosition.vfptr - CurrentPosition->x;
    v47 = CurrentPosition->y;
    vfptr_high = HIDWORD(v70.m_navPosition.vfptr);
    *(float *)&vfptr_high = *((float *)&v70.m_navPosition.vfptr + 1) - v47;
    v49 = (__m128)vfptr_high;
    v49.m128_f32[0] = (float)(*(float *)&vfptr_high * *(float *)&vfptr_high) + (float)(v46 * v46);
    v50 = _mm_sqrt_ps(v49).m128_f32[0];
    *(float *)&v51 = v50;
    if ( v50 < 0.0 )
      v51 = LODWORD(v50) ^ _xmm[0];
    if ( *(float *)&v51 < 0.001 )
    {
      v46 = vOutRadiusCenter.x - v45;
      vfptr_high = LODWORD(vOutRadiusCenter.y);
      *(float *)&vfptr_high = vOutRadiusCenter.y - v47;
      v52 = (__m128)vfptr_high;
      v52.m128_f32[0] = (float)(*(float *)&vfptr_high * *(float *)&vfptr_high) + (float)(v46 * v46);
      LODWORD(v50) = _mm_sqrt_ps(v52).m128_u32[0];
    }
    v53 = FLOAT_0_1;
    if ( (float)(v50 - 0.1) >= 0.1 )
      v53 = v50 - 0.1;
    v54 = v53 / v50;
    v55 = (float)(v46 * v54) + v45;
    *(float *)&vfptr_high = (float)(*(float *)&vfptr_high * v54) + v47;
    v56 = CurrentPosition[1].x;
    v57 = v55 - v45;
    v58 = (__m128)vfptr_high;
    v58.m128_f32[0] = *(float *)&vfptr_high - v47;
    v59 = v58;
    v59.m128_f32[0] = (float)(v58.m128_f32[0] * v58.m128_f32[0]) + (float)(v57 * v57);
    if ( v59.m128_f32[0] != 0.0 )
      v40 = 1.0 / _mm_sqrt_ps(v59).m128_f32[0];
    v60 = (float)((float)((float)(v58.m128_f32[0] * v40) * navComponent->m_vForward.y)
                + (float)((float)(v57 * v40) * navComponent->m_vForward.x))
        * this->m_fSpeed;
    if ( v60 >= 1.0 )
      v28 = v60;
    this->m_fSpeed = v28;
    p = navComponent->m_pNavModulePathing->m_pPath.m_pNavPath->m_aWaypoints.p;
    v62 = p->m_navPosition.m_vPosition.y;
    v63 = p->m_navPosition.m_vPosition.z;
    this->m_waypoint.m_navPosition.m_vPosition.x = p->m_navPosition.m_vPosition.x;
    this->m_waypoint.m_navPosition.m_vPosition.y = v62;
    this->m_waypoint.m_navPosition.m_vPosition.z = v63;
    m_bValid = p->m_navPosition.m_bValid;
    if ( m_bValid )
    {
      this->m_waypoint.m_navPosition.m_bValid = m_bValid;
      this->m_waypoint.m_navPosition.m_hkvMeshPosition = p->m_navPosition.m_hkvMeshPosition;
      this->m_waypoint.m_navPosition.m_packedKey = p->m_navPosition.m_packedKey;
      this->m_waypoint.m_navPosition.m_aiMeshUid = p->m_navPosition.m_aiMeshUid;
    }
    else
    {
      this->m_waypoint.m_navPosition.m_bValid = 0;
    }
    this->m_waypoint.m_pNavObject = p->m_pNavObject;
    this->m_waypoint.m_stopPoint = p->m_stopPoint;
    this->m_waypoint.m_goalPoint = p->m_goalPoint;
    this->m_waypoint.m_navPosition.m_vPosition.x = v55;
    LODWORD(this->m_waypoint.m_navPosition.m_vPosition.y) = vfptr_high;
    this->m_waypoint.m_navPosition.m_vPosition.z = v56;
    this->m_waypoint.m_navPosition.m_bValid = 0;
    this->m_waypoint.m_stopPoint = 0;
    this->m_waypoint.m_canSmooth = 0;
    if ( this->m_bFireVaultCommand && !this->m_bIsDropDown )
      this->m_fSpeed = 0.0;
  }
}

