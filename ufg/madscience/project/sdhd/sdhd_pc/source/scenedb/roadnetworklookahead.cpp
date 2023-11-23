// File Line: 44
// RVA: 0x4CA070
UFG::allocator::free_link *__fastcall UFG::CreateRoadNetworkLookahead()
{
  UFG::allocator::free_link *v0; // rax
  UFG::allocator::free_link *v1; // rbx

  v0 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  UFG::SectionChooser::Lookahead::Lookahead((UFG::SectionChooser::Lookahead *)v0);
  v1->mNext = (UFG::allocator::free_link *)&UFG::RoadnetworkLookahead::`vftable;
  LODWORD(v1[8].mNext) = 0;
  return v1;
}

// File Line: 49
// RVA: 0x15306A0
void UFG::_dynamic_initializer_for__gDBG_final_pos__()
{
  UFG::gDBG_final_pos = UFG::qVector3::msZero;
}

// File Line: 50
// RVA: 0x15307A0
void UFG::_dynamic_initializer_for__gDBG_posVehicle__()
{
  UFG::gDBG_posVehicle = UFG::qVector3::msZero;
}

// File Line: 51
// RVA: 0x1530760
void UFG::_dynamic_initializer_for__gDBG_posLaneNearestPosition__()
{
  UFG::gDBG_posLaneNearestPosition = UFG::qVector3::msZero;
}

// File Line: 52
// RVA: 0x1530720
void UFG::_dynamic_initializer_for__gDBG_lookahead_original__()
{
  UFG::gDBG_lookahead_original = UFG::qVector3::msZero;
}

// File Line: 53
// RVA: 0x15306E0
void UFG::_dynamic_initializer_for__gDBG_lookahead_modified__()
{
  UFG::gDBG_lookahead_modified = UFG::qVector3::msZero;
}

// File Line: 90
// RVA: 0x4CA680
char __fastcall UFG::LookAheadOnRoadNetwork(
        UFG::RoadLaneLookAhead *start_conditions,
        float distance,
        UFG::RoadLaneLookAheadResult *result)
{
  UFG::RoadNetworkLane *mStartLane; // rax
  UFG::RoadNetworkNode *v7; // rcx
  __m128 y_low; // xmm1
  float y; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float Length; // xmm0_4
  char mForwards; // al
  float v14; // xmm8_4
  float mStartT; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm2_4
  float v18; // xmm9_4
  float v19; // xmm9_4
  float v20; // xmm1_4
  UFG::qVector3 *v21; // rax
  float v22; // xmm0_4
  float v23; // xmm1_4
  UFG::RoadNetworkLane *v24; // rdi
  float i; // xmm9_4
  __int64 mOffset; // rax
  char *v27; // r8
  unsigned int v28; // r15d
  __int64 v29; // r10
  __int64 v30; // r9
  _OWORD *v31; // rcx
  __int64 v32; // r11
  char *v33; // rax
  char *v34; // rdx
  __int64 v35; // rax
  char *v36; // rdx
  float z; // xmm5_4
  float v38; // xmm4_4
  float x; // xmm3_4
  __int64 v40; // rax
  char *v41; // r8
  __int64 v42; // r10
  __int64 v43; // r9
  _OWORD *v44; // rcx
  __int64 v45; // r11
  char *v46; // rax
  char *v47; // rdx
  __int64 v48; // rax
  char *v49; // rdx
  float v50; // xmm2_4
  float v51; // xmm1_4
  unsigned int v52; // r14d
  unsigned int v53; // edi
  float v54; // xmm6_4
  _BYTE *v55; // rbx
  char v56; // si
  float v57; // xmm3_4
  __int64 v58; // rax
  UFG::RoadNetworkNode *v59; // rcx
  float v60; // xmm3_4
  __m128 v61; // xmm2
  float v62; // xmm4_4
  __m128 v63; // xmm5
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm0_4
  float v69; // xmm2_4
  float v70; // xmm9_4
  float v71; // xmm1_4
  UFG::qVector3 *v72; // rax
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm4_4
  float v76; // xmm5_4
  UFG::qVector3 tangent; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qVector3 v79; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector3 pos; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 v81; // [rsp+50h] [rbp-88h] BYREF
  UFG::qVector3 resulta; // [rsp+60h] [rbp-78h] BYREF
  _BYTE v84[248]; // [rsp+78h] [rbp-60h] BYREF

  UFG::RoadNetworkLane::GetNearestPoint(
    start_conditions->mStartLane,
    &resulta,
    &start_conditions->mPosVehicle,
    &start_conditions->mStartT);
  mStartLane = start_conditions->mStartLane;
  if ( mStartLane->mNode.mOffset )
    v7 = (UFG::RoadNetworkNode *)((char *)mStartLane + mStartLane->mNode.mOffset);
  else
    v7 = 0i64;
  UFG::RoadNetworkNode::GetTangent(v7, &v81, mStartLane->mLaneIndex, start_conditions->mStartT);
  y_low = (__m128)LODWORD(start_conditions->mPosVehicle.y);
  y = v81.y;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - resulta.y) * (float)(y_low.m128_f32[0] - resulta.y))
                    + (float)((float)(start_conditions->mPosVehicle.x - resulta.x)
                            * (float)(start_conditions->mPosVehicle.x - resulta.x));
  LODWORD(v10) = _mm_sqrt_ps(y_low).m128_u32[0];
  y_low.m128_i32[0] = LODWORD(v81.z);
  result->mfDistanceToLane = v10;
  v11 = (float)((float)(y * start_conditions->mVecVehicle.y) + (float)(v81.x * start_conditions->mVecVehicle.x))
      + (float)(y_low.m128_f32[0] * start_conditions->mVecVehicle.z);
  result->mfDot = v11;
  result->mForwards = v11 > 0.0;
  Length = UFG::RoadNetworkLane::GetLength(start_conditions->mStartLane);
  mForwards = result->mForwards;
  v14 = *(float *)&FLOAT_1_0;
  mStartT = start_conditions->mStartT;
  if ( mForwards )
    v16 = 1.0 - mStartT;
  else
    v16 = start_conditions->mStartT;
  v17 = v16 * Length;
  if ( v17 <= distance )
  {
    v24 = start_conditions->mStartLane;
    for ( i = distance - v17; ; i = i - v66 )
    {
      if ( mForwards )
      {
        UFG::RoadNetworkLane::GetPosAndTangent(v24, 1.0, &pos, &tangent);
        mOffset = v24->mNextConnection.mOffset;
        if ( !mOffset || (v27 = (char *)&v24->mNextConnection + mOffset) == 0i64 )
        {
          v67 = pos.y + (float)(tangent.y * i);
          v68 = pos.z + (float)(tangent.z * i);
          result->mFinalPos.x = pos.x + (float)(tangent.x * i);
          result->mFinalPos.y = v67;
          result->mFinalPos.z = v68;
          return 1;
        }
        v28 = *(_DWORD *)v27;
        if ( *(_DWORD *)v27 )
        {
          v29 = *((_QWORD *)v27 + 1);
          v30 = 0i64;
          v31 = v84;
          v32 = v28;
          do
          {
            if ( v29 )
              v33 = &v27[v29 + 8];
            else
              v33 = 0i64;
            v34 = &v33[v30];
            v35 = *(_QWORD *)&v33[v30];
            if ( v35 )
              v35 += (__int64)v34;
            v36 = *(char **)(v35 + 88);
            *((_QWORD *)v31 - 1) = v35;
            if ( v36 )
              v36 += v35 + 88;
            ++v31;
            v30 += 8i64;
            *((_BYTE *)v31 - 16) = v36 == v27;
            --v32;
          }
          while ( v32 );
        }
        z = tangent.z;
        v38 = tangent.y;
        x = tangent.x;
      }
      else
      {
        UFG::RoadNetworkLane::GetPosAndTangent(v24, 0.0, &pos, &tangent);
        x = tangent.x * -1.0;
        v38 = tangent.y * -1.0;
        tangent.x = tangent.x * -1.0;
        tangent.y = tangent.y * -1.0;
        z = tangent.z * -1.0;
        tangent.z = tangent.z * -1.0;
        v40 = v24->mPrevConnection.mOffset;
        if ( !v40 || (v41 = (char *)&v24->mPrevConnection + v40) == 0i64 )
        {
          v75 = (float)(v38 * i) + pos.y;
          v76 = (float)(z * i) + pos.z;
          result->mFinalPos.x = (float)(x * i) + pos.x;
          result->mFinalPos.y = v75;
          result->mFinalPos.z = v76;
          return 1;
        }
        v28 = *(_DWORD *)v41;
        if ( *(_DWORD *)v41 )
        {
          v42 = *((_QWORD *)v41 + 1);
          v43 = 0i64;
          v44 = v84;
          v45 = v28;
          do
          {
            if ( v42 )
              v46 = &v41[v42 + 8];
            else
              v46 = 0i64;
            v47 = &v46[v43];
            v48 = *(_QWORD *)&v46[v43];
            if ( v48 )
              v48 += (__int64)v47;
            v49 = *(char **)(v48 + 96);
            *((_QWORD *)v44 - 1) = v48;
            if ( v49 )
              v49 += v48 + 96;
            ++v44;
            v43 += 8i64;
            *((_BYTE *)v44 - 16) = v49 != v41;
            --v45;
          }
          while ( v45 );
        }
      }
      v50 = (float)((float)(x * x) + (float)(v38 * v38)) + (float)(z * z);
      if ( v50 == 0.0 )
        v51 = 0.0;
      else
        v51 = 1.0 / fsqrt(v50);
      v52 = 0;
      v53 = 0;
      v54 = FLOAT_N2_0;
      tangent.x = x * v51;
      tangent.y = v38 * v51;
      tangent.z = z * v51;
      if ( v28 )
      {
        v55 = v84;
        do
        {
          v56 = *v55;
          if ( *v55 )
            v57 = *(float *)&FLOAT_1_0;
          else
            v57 = 0.0;
          v58 = *((_QWORD *)v55 - 1);
          v59 = *(UFG::RoadNetworkNode **)v58;
          if ( *(_QWORD *)v58 )
            v59 = (UFG::RoadNetworkNode *)((char *)v59 + v58);
          UFG::RoadNetworkNode::GetTangent(v59, &v79, *(unsigned __int16 *)(v58 + 36), v57);
          v60 = v79.x;
          v61 = (__m128)LODWORD(v79.y);
          v62 = v79.z;
          if ( !v56 )
          {
            v60 = v79.x * -1.0;
            v61.m128_f32[0] = v79.y * -1.0;
            v62 = v79.z * -1.0;
            v79.x = v79.x * -1.0;
            v79.y = v79.y * -1.0;
            v79.z = v79.z * -1.0;
          }
          v63 = v61;
          v63.m128_f32[0] = (float)((float)(v61.m128_f32[0] * v61.m128_f32[0]) + (float)(v60 * v60))
                          + (float)(v62 * v62);
          if ( v63.m128_f32[0] == 0.0 )
            v64 = 0.0;
          else
            v64 = 1.0 / _mm_sqrt_ps(v63).m128_f32[0];
          v65 = (float)((float)((float)(v61.m128_f32[0] * v64) * start_conditions->mVecVehicle.y)
                      + (float)((float)(v60 * v64) * start_conditions->mVecVehicle.x))
              + (float)((float)(v62 * v64) * start_conditions->mVecVehicle.z);
          if ( v65 > v54 )
          {
            v52 = v53;
            v54 = v65;
          }
          ++v53;
          v55 += 16;
        }
        while ( v53 < v28 );
      }
      if ( v54 < 0.707 )
        i = i * (float)((float)(v54 + 1.0) * 0.5858230814294083);
      v24 = *(UFG::RoadNetworkLane **)&v84[16 * v52 - 8];
      v66 = UFG::RoadNetworkLane::GetLength(v24);
      mForwards = v84[16 * v52];
      if ( i < v66 )
      {
        if ( v66 < 0.001 )
        {
          v69 = 0.0;
LABEL_86:
          v72 = UFG::RoadNetworkLane::GetPos(v24, &v79, v69);
          v73 = v72->y;
          v74 = v72->z;
          *(float *)&v72 = v72->x;
          result->mFinalPos.z = v74;
          result->mFinalPos.y = v73;
          LODWORD(result->mFinalPos.x) = (_DWORD)v72;
          return 1;
        }
        v70 = i / v66;
        if ( mForwards )
        {
          if ( v70 <= 0.0 )
          {
            v70 = 0.0;
          }
          else if ( v70 >= 1.0 )
          {
            goto LABEL_85;
          }
          v14 = v70;
        }
        else
        {
          v71 = 1.0 - v70;
          if ( (float)(1.0 - v70) <= 0.0 )
          {
            v71 = 0.0;
          }
          else if ( v71 >= 1.0 )
          {
            goto LABEL_85;
          }
          v14 = v71;
        }
LABEL_85:
        v69 = v14;
        goto LABEL_86;
      }
    }
  }
  if ( Length >= 0.001 )
  {
    v18 = distance / Length;
    if ( mForwards )
    {
      v19 = v18 + mStartT;
      if ( v19 <= 0.0 )
      {
        v19 = 0.0;
      }
      else if ( v19 >= 1.0 )
      {
        goto LABEL_21;
      }
      v14 = v19;
    }
    else
    {
      v20 = mStartT - v18;
      if ( v20 <= 0.0 )
      {
        v20 = 0.0;
      }
      else if ( v20 >= 1.0 )
      {
        goto LABEL_21;
      }
      v14 = v20;
    }
LABEL_21:
    v21 = UFG::RoadNetworkLane::GetPos(start_conditions->mStartLane, &pos, v14);
    v22 = v21->y;
    v23 = v21->z;
    *(float *)&v21 = v21->x;
    result->mFinalPos.z = v23;
    result->mFinalPos.y = v22;
    LODWORD(result->mFinalPos.x) = (_DWORD)v21;
    return 1;
  }
  UFG::RoadNetworkLane::GetPos(start_conditions->mStartLane, &pos, 0.0);
  return 1;
}

// File Line: 267
// RVA: 0x4CAD10
void __fastcall UFG::RoadnetworkLookahead::Process(
        UFG::RoadnetworkLookahead *this,
        UFG::qVector3 *viewerPosition,
        UFG::qVector3 *_viewerDirection,
        UFG::qVector3 *_viewerCameraDirection,
        UFG::qVector3 *_viewerVelocity,
        float deltaTime,
        bool enabled)
{
  float y; // xmm2_4
  float z; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm12_4
  __int128 y_low; // xmm11
  float v17; // xmm13_4
  float v18; // xmm14_4
  float v19; // xmm15_4
  UFG::SimObjectCharacter *v20; // rdi
  __m128 v21; // xmm10
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm8_4
  float v25; // xmm6_4
  float v26; // xmm1_4
  float mCurrentLookaheadDistance; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  UFG::CharacterOccupantComponent *m_pComponent; // rdi
  UFG::SimObject *CurrentVehicle; // rax
  UFG::SimObject *v33; // rdi
  UFG::SimComponentHolder *p; // rdi
  UFG::SimComponent *v35; // rsi
  UFG::TransformNodeComponent *v36; // rdi
  UFG::RoadNetworkGuide *p_mNext; // rsi
  UFG::RoadNetworkLocation *Name; // rax
  UFG::RoadNetworkLocation *v39; // rax
  float m_LaneT; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // [rsp+20h] [rbp-128h]
  UFG::RoadLaneLookAheadResult result; // [rsp+28h] [rbp-120h] BYREF
  UFG::RoadLaneLookAhead pos; // [rsp+40h] [rbp-108h] BYREF
  float fy; // [rsp+150h] [rbp+8h]
  float fx; // [rsp+158h] [rbp+10h]
  float v61; // [rsp+160h] [rbp+18h]
  float x; // [rsp+168h] [rbp+20h]
  float _viewerVelocitya; // [rsp+170h] [rbp+28h]

  y = _viewerDirection->y;
  z = viewerPosition->z;
  x = _viewerCameraDirection->x;
  fy = y;
  v11 = _viewerDirection->x;
  v61 = _viewerCameraDirection->y;
  v56 = _viewerCameraDirection->z;
  v12 = viewerPosition->y;
  fx = v11;
  v13 = 0.0;
  v14 = 0.0;
  v15 = _viewerVelocity->x;
  y_low = LODWORD(_viewerVelocity->y);
  this->mViewerPosition.x = viewerPosition->x;
  this->mViewerPosition.y = v12;
  this->mViewerPosition.z = z;
  this->mViewerDirection.x = v11;
  this->mViewerDirection.z = 0.0;
  this->mViewerDirection.y = y;
  this->mViewerVelocity.x = v15;
  LODWORD(this->mViewerVelocity.y) = y_low;
  this->mViewerVelocity.z = 0.0;
  v17 = UFG::qVector3::msZero.x;
  v18 = UFG::qVector3::msZero.y;
  v19 = UFG::qVector3::msZero.z;
  UFG::StreamFileWrapper::SetSupressCaching_HighSpeed(0);
  v20 = LocalPlayer;
  if ( this->mEnabled
    && enabled
    && LocalPlayer->m_Components.p[44].m_pComponent
    && (v21 = (__m128)y_low,
        v21.m128_f32[0] = (float)(*(float *)&y_low * *(float *)&y_low) + (float)(v15 * v15),
        _mm_sqrt_ps(v21).m128_f32[0] < 100.0) )
  {
    v22 = v15 * v11;
    v23 = 0.0;
    v24 = (float)(*(float *)&y_low * y) + v22;
    if ( UFG::MAX_LOOKAHEAD_SPEED != UFG::MIN_LOOKAHEAD_SPEED )
    {
      if ( v24 <= UFG::MIN_LOOKAHEAD_SPEED )
        v25 = UFG::MIN_LOOKAHEAD_SPEED;
      else
        v25 = (float)(*(float *)&y_low * y) + v22;
      if ( v25 >= UFG::MAX_LOOKAHEAD_SPEED )
        v25 = UFG::MAX_LOOKAHEAD_SPEED;
      v23 = (float)((float)(v25 - UFG::MIN_LOOKAHEAD_SPEED) * UFG::MAX_LOOKAHEAD_DIST)
          / (float)(UFG::MAX_LOOKAHEAD_SPEED - UFG::MIN_LOOKAHEAD_SPEED);
    }
    _viewerVelocitya = atan2f(y, fx);
    v26 = _viewerVelocitya - this->mfCurrentAngle;
    if ( v26 >= -3.1415927 )
    {
      if ( v26 >= 3.1415927 )
        v26 = v26 + -6.2831855;
    }
    else
    {
      v26 = v26 + 6.2831855;
    }
    mCurrentLookaheadDistance = this->mCurrentLookaheadDistance;
    if ( v23 <= mCurrentLookaheadDistance )
    {
      v28 = (float)((float)(COERCE_FLOAT(LODWORD(v26) & _xmm) * 0.31830987) * (float)(mCurrentLookaheadDistance - v23))
          * 2.0;
      if ( v28 < 0.0 )
        v28 = 0.0;
      this->mCurrentLookaheadDistance = mCurrentLookaheadDistance - (float)((float)(deltaTime * 29.999998) * v28);
    }
    else
    {
      this->mCurrentLookaheadDistance = v23;
    }
    if ( v24 < 0.0 )
    {
      v29 = v21.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v21).m128_f32[0];
      LODWORD(v30) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)((float)(*(float *)&y_low * v29) * v61) + (float)((float)(v15 * v29) * x))
                             + (float)((float)(v29 * 0.0) * v56))
                     * (float)((float)((float)((float)(*(float *)&y_low * v29) * fy) + (float)((float)(v15 * v29) * fx))
                             + (float)((float)(v29 * 0.0) * 0.0))) ^ _xmm[0];
      if ( v30 > 0.80000001 )
        this->mCurrentLookaheadDistance = (1.0
                                         - (float)((float)(v30 - 0.80000001) * 5.0000005)
                                         * 0.02
                                         * (float)(deltaTime * 29.999998))
                                        * this->mCurrentLookaheadDistance;
    }
    if ( this->mCurrentLookaheadDistance > 0.0 && (v20->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterOccupantComponent *)v20->m_Components.p[44].m_pComponent;
      UFG::StreamFileWrapper::SetSupressCaching_HighSpeed(1);
      if ( m_pComponent )
      {
        CurrentVehicle = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
        v33 = CurrentVehicle;
        if ( CurrentVehicle )
        {
          if ( !UFG::SimObjectUtility::IsBoat(CurrentVehicle) )
          {
            p = v33->m_Components.p;
            v35 = p[24].m_pComponent;
            if ( v35 )
            {
              v36 = (UFG::TransformNodeComponent *)p[2].m_pComponent;
              p_mNext = (UFG::RoadNetworkGuide *)&v35[5].m_BoundComponentHandles.mNode.mNext;
              UFG::TransformNodeComponent::UpdateWorldTransform(v36);
              if ( UFG::RoadNetworkGuide::IsCurrentLocationValid(p_mNext) )
              {
                Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
                if ( UFG::RoadNetworkLocation::IsValid(Name) )
                {
                  v39 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
                  UFG::RoadNetworkLocation::GetVectors(v39, &pos.mPosLaneNearestPosition, &pos.mVecLaneNearestTangent);
                  pos.mStartLane = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_CurrentLane;
                  m_LaneT = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_LaneT;
                  pos.mVecVehicle.x = _viewerDirection->x;
                  v41 = _viewerDirection->z;
                  pos.mStartT = m_LaneT;
                  v42 = _viewerDirection->y;
                  pos.mVecVehicle.z = v41;
                  v43 = v36->mWorldTransform.v3.y;
                  pos.mVecVehicle.y = v42;
                  pos.mPosVehicle.x = v36->mWorldTransform.v3.x;
                  v44 = v36->mWorldTransform.v3.z;
                  pos.mPosVehicle.y = v43;
                  v45 = this->mCurrentLookaheadDistance;
                  pos.mPosVehicle.z = v44;
                  UFG::LookAheadOnRoadNetwork(&pos, v45, &result);
                  if ( result.mfDistanceToLane < 10.0 )
                  {
                    v17 = result.mFinalPos.x;
                    v18 = result.mFinalPos.y;
                    v19 = result.mFinalPos.z;
                    v14 = (float)(10.0 - result.mfDistanceToLane) * 0.1;
                  }
                  v46 = v36->mWorldTransform.v3.y;
                  v47 = v36->mWorldTransform.v3.z;
                  UFG::gDBG_posVehicle.x = v36->mWorldTransform.v3.x;
                  UFG::gDBG_posVehicle.y = v46;
                  UFG::gDBG_posLaneNearestPosition = pos.mPosLaneNearestPosition;
                  UFG::gDBG_posVehicle.z = v47;
                  UFG::gDBG_final_pos = result.mFinalPos;
                }
              }
            }
          }
        }
      }
    }
    v13 = _viewerVelocitya;
  }
  else
  {
    this->mCurrentLookaheadDistance = 0.0;
  }
  v48 = this->mCurrentLookaheadDistance;
  v49 = (float)(v48 * this->mViewerDirection.z) + this->mViewerPosition.z;
  v50 = (float)(v48 * this->mViewerDirection.x) + this->mViewerPosition.x;
  v51 = (float)(this->mCurrentLookaheadDistance * this->mViewerDirection.y) + this->mViewerPosition.y;
  this->mCurrentLookaheadPos.z = v49;
  this->mCurrentLookaheadPos.x = v50;
  this->mCurrentLookaheadPos.y = v51;
  UFG::gDBG_lookahead_original.x = v50;
  UFG::gDBG_lookahead_original.y = v51;
  UFG::gDBG_lookahead_original.z = v49;
  if ( v14 > 0.0 )
  {
    v52 = this->mCurrentLookaheadPos.y + (float)((float)(v18 - this->mCurrentLookaheadPos.y) * v14);
    v53 = this->mCurrentLookaheadPos.z + (float)((float)(v19 - this->mCurrentLookaheadPos.z) * v14);
    this->mCurrentLookaheadPos.x = this->mCurrentLookaheadPos.x
                                 + (float)((float)(v17 - this->mCurrentLookaheadPos.x) * v14);
    this->mCurrentLookaheadPos.y = v52;
    this->mCurrentLookaheadPos.z = v53;
  }
  v54 = this->mCurrentLookaheadPos.y;
  v55 = this->mCurrentLookaheadPos.z;
  UFG::gDBG_lookahead_modified.x = this->mCurrentLookaheadPos.x;
  UFG::gDBG_lookahead_modified.y = v54;
  UFG::gDBG_lookahead_modified.z = v55;
  this->mfCurrentAngle = v13;
}

// File Line: 419
// RVA: 0x4CA0D0
void __fastcall UFG::RoadnetworkLookahead::DebugDraw(UFG::RoadnetworkLookahead *this, Render::View *pView)
{
  unsigned int v3; // eax

  v3 = _S5_10;
  if ( (_S5_10 & 1) == 0 )
  {
    v3 = _S5_10 | 1;
    _S5_10 |= 1u;
    drawinfoWhite.mColour1 = UFG::qColour::White;
    drawinfoWhite.mColour2 = UFG::qColour::White;
    drawinfoWhite.mScale = 1.0;
    drawinfoWhite.mAlphaBlend = AlphaState_none;
    *(_WORD *)&drawinfoWhite.mDepthBuffer = 256;
    drawinfoWhite.mDepthBias = 0;
    drawinfoWhite.mPreDrawCallback = 0i64;
  }
  if ( (v3 & 2) == 0 )
  {
    v3 |= 2u;
    _S5_10 = v3;
    drawinfoRed.mColour1 = UFG::qColour::Red;
    drawinfoRed.mColour2 = UFG::qColour::Red;
    drawinfoRed.mScale = 1.0;
    drawinfoRed.mAlphaBlend = AlphaState_none;
    *(_WORD *)&drawinfoRed.mDepthBuffer = 256;
    drawinfoRed.mDepthBias = 0;
    drawinfoRed.mPreDrawCallback = 0i64;
  }
  if ( (v3 & 4) == 0 )
  {
    v3 |= 4u;
    _S5_10 = v3;
    drawinfoBlue.mColour1 = UFG::qColour::Blue;
    drawinfoBlue.mColour2 = UFG::qColour::Blue;
    drawinfoBlue.mScale = 1.0;
    drawinfoBlue.mAlphaBlend = AlphaState_none;
    *(_WORD *)&drawinfoBlue.mDepthBuffer = 256;
    drawinfoBlue.mDepthBias = 0;
    drawinfoBlue.mPreDrawCallback = 0i64;
  }
  if ( (v3 & 8) == 0 )
  {
    _S5_10 = v3 | 8;
    drawinfoGreen.mColour1 = UFG::qColour::Green;
    drawinfoGreen.mColour2 = UFG::qColour::Green;
    drawinfoGreen.mScale = 1.0;
    drawinfoGreen.mAlphaBlend = AlphaState_none;
    *(_WORD *)&drawinfoGreen.mDepthBuffer = 256;
    drawinfoGreen.mDepthBias = 0;
    drawinfoGreen.mPreDrawCallback = 0i64;
  }
  Render::View::DrawSegment(pView, &UFG::gDBG_posVehicle, &UFG::gDBG_posLaneNearestPosition, &drawinfoRed);
  Render::View::DrawSegment(pView, &UFG::gDBG_posVehicle, &UFG::gDBG_final_pos, &drawinfoWhite);
  Render::View::DrawCross(pView, &UFG::gDBG_final_pos, &drawinfoWhite);
  Render::View::DrawCross(pView, &UFG::gDBG_lookahead_original, &drawinfoBlue);
  Render::View::DrawCross(pView, &UFG::gDBG_lookahead_modified, &drawinfoGreen);
}

