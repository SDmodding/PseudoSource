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
  v1->mNext = (UFG::allocator::free_link *)&UFG::RoadnetworkLookahead::`vftable';
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
char __fastcall UFG::LookAheadOnRoadNetwork(UFG::RoadLaneLookAhead *start_conditions, float distance, UFG::RoadLaneLookAheadResult *result)
{
  UFG::RoadLaneLookAheadResult *v3; // r12
  UFG::RoadLaneLookAhead *v4; // r13
  float v5; // xmm9_4
  UFG::RoadNetworkLane *v6; // rax
  UFG::RoadNetworkNode *v7; // rcx
  __m128 v8; // xmm1
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  char v13; // al
  float v14; // xmm8_4
  float v15; // xmm1_4
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
  __int64 v26; // rax
  signed __int64 v27; // r8
  unsigned int v28; // er15
  __int64 v29; // r10
  __int64 v30; // r9
  char *v31; // rcx
  __int64 v32; // r11
  signed __int64 v33; // rax
  signed __int64 v34; // rdx
  __int64 v35; // rax
  __int64 v36; // rdx
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm3_4
  __int64 v40; // rax
  signed __int64 v41; // r8
  __int64 v42; // r10
  __int64 v43; // r9
  char *v44; // rcx
  __int64 v45; // r11
  signed __int64 v46; // rax
  signed __int64 v47; // rdx
  __int64 v48; // rax
  __int64 v49; // rdx
  float v50; // xmm2_4
  float v51; // xmm1_4
  unsigned int v52; // er14
  unsigned int v53; // edi
  float v54; // xmm6_4
  char *v55; // rbx
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
  UFG::qVector3 tangent; // [rsp+20h] [rbp-B8h]
  UFG::qVector3 v79; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 pos; // [rsp+40h] [rbp-98h]
  UFG::qVector3 v81; // [rsp+50h] [rbp-88h]
  UFG::qVector3 resulta; // [rsp+60h] [rbp-78h]
  UFG::RoadNetworkLane *v83; // [rsp+70h] [rbp-68h]
  char v84[248]; // [rsp+78h] [rbp-60h]

  v3 = result;
  v4 = start_conditions;
  v5 = distance;
  UFG::RoadNetworkLane::GetNearestPoint(
    start_conditions->mStartLane,
    &resulta,
    &start_conditions->mPosVehicle,
    &start_conditions->mStartT);
  v6 = v4->mStartLane;
  if ( v6->mNode.mOffset )
    v7 = (UFG::RoadNetworkNode *)((char *)v6 + v6->mNode.mOffset);
  else
    v7 = 0i64;
  UFG::RoadNetworkNode::GetTangent(v7, &v81, v6->mLaneIndex, v4->mStartT);
  v8 = (__m128)LODWORD(v4->mPosVehicle.y);
  v9 = v81.y;
  v8.m128_f32[0] = (float)((float)(v8.m128_f32[0] - resulta.y) * (float)(v8.m128_f32[0] - resulta.y))
                 + (float)((float)(v4->mPosVehicle.x - resulta.x) * (float)(v4->mPosVehicle.x - resulta.x));
  LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v8);
  v8.m128_i32[0] = LODWORD(v81.z);
  v3->mfDistanceToLane = v10;
  v11 = (float)((float)(v9 * v4->mVecVehicle.y) + (float)(v81.x * v4->mVecVehicle.x))
      + (float)(v8.m128_f32[0] * v4->mVecVehicle.z);
  v3->mfDot = v11;
  v3->mForwards = v11 > 0.0;
  v12 = UFG::RoadNetworkLane::GetLength(v4->mStartLane);
  v13 = v3->mForwards;
  v14 = *(float *)&FLOAT_1_0;
  v15 = v4->mStartT;
  if ( v13 )
    v16 = 1.0 - v15;
  else
    v16 = v4->mStartT;
  v17 = v16 * v12;
  if ( v17 <= v5 )
  {
    v24 = v4->mStartLane;
    for ( i = v5 - v17; ; i = i - v66 )
    {
      if ( v13 )
      {
        UFG::RoadNetworkLane::GetPosAndTangent(v24, 1.0, &pos, &tangent);
        v26 = v24->mNextConnection.mOffset;
        if ( !v26 || (v27 = (signed __int64)&v24->mNextConnection + v26) == 0 )
        {
          v67 = pos.y + (float)(tangent.y * i);
          v68 = pos.z + (float)(tangent.z * i);
          v3->mFinalPos.x = pos.x + (float)(tangent.x * i);
          v3->mFinalPos.y = v67;
          v3->mFinalPos.z = v68;
          return 1;
        }
        v28 = *(_DWORD *)v27;
        if ( *(_DWORD *)v27 )
        {
          v29 = *(_QWORD *)(v27 + 8);
          v30 = 0i64;
          v31 = v84;
          v32 = v28;
          do
          {
            if ( v29 )
              v33 = v27 + v29 + 8;
            else
              v33 = 0i64;
            v34 = v30 + v33;
            v35 = *(_QWORD *)(v30 + v33);
            if ( v35 )
              v35 += v34;
            v36 = *(_QWORD *)(v35 + 88);
            *((_QWORD *)v31 - 1) = v35;
            if ( v36 )
              v36 += v35 + 88;
            v31 += 16;
            v30 += 8i64;
            *(v31 - 16) = v36 == v27;
            --v32;
          }
          while ( v32 );
        }
        v37 = tangent.z;
        v38 = tangent.y;
        v39 = tangent.x;
      }
      else
      {
        UFG::RoadNetworkLane::GetPosAndTangent(v24, 0.0, &pos, &tangent);
        v39 = tangent.x * -1.0;
        v38 = tangent.y * -1.0;
        tangent.x = tangent.x * -1.0;
        tangent.y = tangent.y * -1.0;
        v37 = tangent.z * -1.0;
        tangent.z = tangent.z * -1.0;
        v40 = v24->mPrevConnection.mOffset;
        if ( !v40 || (v41 = (signed __int64)&v24->mPrevConnection + v40) == 0 )
        {
          v75 = (float)(v38 * i) + pos.y;
          v76 = (float)(v37 * i) + pos.z;
          v3->mFinalPos.x = (float)(v39 * i) + pos.x;
          v3->mFinalPos.y = v75;
          v3->mFinalPos.z = v76;
          return 1;
        }
        v28 = *(_DWORD *)v41;
        if ( *(_DWORD *)v41 )
        {
          v42 = *(_QWORD *)(v41 + 8);
          v43 = 0i64;
          v44 = v84;
          v45 = v28;
          do
          {
            if ( v42 )
              v46 = v41 + v42 + 8;
            else
              v46 = 0i64;
            v47 = v43 + v46;
            v48 = *(_QWORD *)(v43 + v46);
            if ( v48 )
              v48 += v47;
            v49 = *(_QWORD *)(v48 + 96);
            *((_QWORD *)v44 - 1) = v48;
            if ( v49 )
              v49 += v48 + 96;
            v44 += 16;
            v43 += 8i64;
            *(v44 - 16) = v49 != v41;
            --v45;
          }
          while ( v45 );
        }
      }
      v50 = (float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)(v37 * v37);
      if ( v50 == 0.0 )
        v51 = 0.0;
      else
        v51 = 1.0 / fsqrt(v50);
      v52 = 0;
      v53 = 0;
      v54 = FLOAT_N2_0;
      tangent.x = v39 * v51;
      tangent.y = v38 * v51;
      tangent.z = v37 * v51;
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
            v64 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v63));
          v65 = (float)((float)((float)(v61.m128_f32[0] * v64) * v4->mVecVehicle.y)
                      + (float)((float)(v60 * v64) * v4->mVecVehicle.x))
              + (float)((float)(v62 * v64) * v4->mVecVehicle.z);
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
      v24 = *(&v83 + 2 * v52);
      v66 = UFG::RoadNetworkLane::GetLength(*(&v83 + 2 * v52));
      v13 = v84[16 * v52];
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
          v3->mFinalPos.z = v74;
          v3->mFinalPos.y = v73;
          LODWORD(v3->mFinalPos.x) = (_DWORD)v72;
          return 1;
        }
        v70 = i / v66;
        if ( v13 )
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
  if ( v12 >= 0.001 )
  {
    v18 = v5 / v12;
    if ( v13 )
    {
      v19 = v18 + v15;
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
      v20 = v15 - v18;
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
    v21 = UFG::RoadNetworkLane::GetPos(v4->mStartLane, &pos, v14);
    v22 = v21->y;
    v23 = v21->z;
    *(float *)&v21 = v21->x;
    v3->mFinalPos.z = v23;
    v3->mFinalPos.y = v22;
    LODWORD(v3->mFinalPos.x) = (_DWORD)v21;
    return 1;
  }
  UFG::RoadNetworkLane::GetPos(v4->mStartLane, &pos, 0.0);
  return 1;
}

// File Line: 267
// RVA: 0x4CAD10
void __fastcall UFG::RoadnetworkLookahead::Process(UFG::RoadnetworkLookahead *this, UFG::qVector3 *viewerPosition, UFG::qVector3 *_viewerDirection, UFG::qVector3 *_viewerCameraDirection, UFG::qVector3 *_viewerVelocity, float deltaTime, bool enabled)
{
  float v7; // xmm2_4
  float v8; // xmm1_4
  UFG::RoadnetworkLookahead *v9; // rbx
  int *v10; // rbp
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm12_4
  __int128 v16; // xmm11
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
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  UFG::CharacterOccupantComponent *v31; // rdi
  UFG::SimObject *v32; // rax
  UFG::SimObject *v33; // rdi
  UFG::SimComponentHolder *v34; // rdi
  UFG::SimComponent *v35; // rsi
  UFG::SimComponent *v36; // rdi
  UFG::RoadNetworkGuide *v37; // rsi
  UFG::RoadNetworkLocation *v38; // rax
  UFG::RoadNetworkLocation *v39; // rax
  float v40; // xmm0_4
  int v41; // xmm1_4
  int v42; // xmm0_4
  int v43; // xmm1_4
  int v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // [rsp+20h] [rbp-128h]
  UFG::RoadLaneLookAheadResult result; // [rsp+28h] [rbp-120h]
  UFG::qVector3 pos; // [rsp+40h] [rbp-108h]
  UFG::qVector3 direction; // [rsp+4Ch] [rbp-FCh]
  UFG::RoadNetworkLane *v61; // [rsp+58h] [rbp-F0h]
  float v62; // [rsp+60h] [rbp-E8h]
  int v63; // [rsp+64h] [rbp-E4h]
  int v64; // [rsp+68h] [rbp-E0h]
  int v65; // [rsp+6Ch] [rbp-DCh]
  int v66; // [rsp+70h] [rbp-D8h]
  int v67; // [rsp+74h] [rbp-D4h]
  int v68; // [rsp+78h] [rbp-D0h]
  float fy; // [rsp+150h] [rbp+8h]
  float fx; // [rsp+158h] [rbp+10h]
  float v71; // [rsp+160h] [rbp+18h]
  float v72; // [rsp+168h] [rbp+20h]
  float _viewerVelocitya; // [rsp+170h] [rbp+28h]

  v7 = _viewerDirection->y;
  v8 = viewerPosition->z;
  v9 = this;
  v72 = _viewerCameraDirection->x;
  fy = _viewerDirection->y;
  v10 = (int *)_viewerDirection;
  v11 = _viewerDirection->x;
  v71 = _viewerCameraDirection->y;
  v57 = _viewerCameraDirection->z;
  v12 = viewerPosition->y;
  fx = v11;
  v13 = 0.0;
  v14 = 0.0;
  v15 = _viewerVelocity->x;
  v16 = LODWORD(_viewerVelocity->y);
  this->mViewerPosition.x = viewerPosition->x;
  this->mViewerPosition.y = v12;
  this->mViewerPosition.z = v8;
  this->mViewerDirection.x = v11;
  this->mViewerDirection.z = 0.0;
  this->mViewerDirection.y = v7;
  this->mViewerVelocity.x = v15;
  LODWORD(this->mViewerVelocity.y) = v16;
  this->mViewerVelocity.z = 0.0;
  v17 = UFG::qVector3::msZero.x;
  v18 = UFG::qVector3::msZero.y;
  v19 = UFG::qVector3::msZero.z;
  UFG::StreamFileWrapper::SetSupressCaching_HighSpeed(0);
  v20 = LocalPlayer;
  if ( v9->mEnabled
    && enabled
    && LocalPlayer->m_Components.p[44].m_pComponent
    && (v21 = (__m128)v16,
        v21.m128_f32[0] = (float)(*(float *)&v16 * *(float *)&v16) + (float)(v15 * v15),
        COERCE_FLOAT(_mm_sqrt_ps(v21)) < 100.0) )
  {
    v22 = v15 * v11;
    v23 = 0.0;
    v24 = (float)(*(float *)&v16 * fy) + v22;
    if ( UFG::MAX_LOOKAHEAD_SPEED != UFG::MIN_LOOKAHEAD_SPEED )
    {
      if ( v24 <= UFG::MIN_LOOKAHEAD_SPEED )
        v25 = UFG::MIN_LOOKAHEAD_SPEED;
      else
        v25 = (float)(*(float *)&v16 * fy) + v22;
      if ( v25 >= UFG::MAX_LOOKAHEAD_SPEED )
        v25 = UFG::MAX_LOOKAHEAD_SPEED;
      v23 = (float)((float)(v25 - UFG::MIN_LOOKAHEAD_SPEED) * UFG::MAX_LOOKAHEAD_DIST)
          / (float)(UFG::MAX_LOOKAHEAD_SPEED - UFG::MIN_LOOKAHEAD_SPEED);
    }
    _viewerVelocitya = atan2f(fy, fx);
    v26 = _viewerVelocitya - v9->mfCurrentAngle;
    if ( v26 >= -3.1415927 )
    {
      if ( v26 >= 3.1415927 )
        v26 = v26 + -6.2831855;
    }
    else
    {
      v26 = v26 + 6.2831855;
    }
    v27 = v9->mCurrentLookaheadDistance;
    if ( v23 <= v27 )
    {
      v28 = (float)((float)(COERCE_FLOAT(LODWORD(v26) & _xmm) * 0.31830987) * (float)(v27 - v23)) * 2.0;
      if ( v28 < 0.0 )
        v28 = 0.0;
      v9->mCurrentLookaheadDistance = v27 - (float)((float)(deltaTime * 29.999998) * v28);
    }
    else
    {
      v9->mCurrentLookaheadDistance = v23;
    }
    if ( v24 < 0.0 )
    {
      v29 = v21.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v21));
      LODWORD(v30) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)((float)(*(float *)&v16 * v29) * v71) + (float)((float)(v15 * v29) * v72))
                             + (float)((float)(v29 * 0.0) * v57))
                     * (float)((float)((float)((float)(*(float *)&v16 * v29) * fy) + (float)((float)(v15 * v29) * fx))
                             + (float)((float)(v29 * 0.0) * 0.0))) ^ _xmm[0];
      if ( v30 > 0.80000001 )
        v9->mCurrentLookaheadDistance = (1.0
                                       - (float)((float)(v30 - 0.80000001) * 5.0000005)
                                       * 0.02
                                       * (float)(deltaTime * 29.999998))
                                      * v9->mCurrentLookaheadDistance;
    }
    if ( v9->mCurrentLookaheadDistance > 0.0 )
    {
      if ( (v20->m_Flags >> 14) & 1 )
      {
        v31 = (UFG::CharacterOccupantComponent *)v20->m_Components.p[44].m_pComponent;
        UFG::StreamFileWrapper::SetSupressCaching_HighSpeed(1);
        if ( v31 )
        {
          v32 = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v31);
          v33 = v32;
          if ( v32 )
          {
            if ( !UFG::SimObjectUtility::IsBoat(v32) )
            {
              v34 = v33->m_Components.p;
              v35 = v34[24].m_pComponent;
              if ( v35 )
              {
                v36 = v34[2].m_pComponent;
                v37 = (UFG::RoadNetworkGuide *)&v35[5].m_BoundComponentHandles.mNode.mNext;
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v36);
                if ( (unsigned __int8)UFG::RoadNetworkGuide::IsCurrentLocationValid(v37) )
                {
                  v38 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v37);
                  if ( (unsigned __int8)UFG::RoadNetworkLocation::IsValid(v38) )
                  {
                    v39 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v37);
                    UFG::RoadNetworkLocation::GetVectors(v39, &pos, &direction);
                    v61 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v37)->m_CurrentLane;
                    v40 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v37)->m_LaneT;
                    v63 = *v10;
                    v41 = v10[2];
                    v62 = v40;
                    v42 = v10[1];
                    v65 = v41;
                    v43 = HIDWORD(v36[2].m_BoundComponentHandles.mNode.mPrev);
                    v64 = v42;
                    v66 = (int)v36[2].m_BoundComponentHandles.mNode.mPrev;
                    v44 = (int)v36[2].m_BoundComponentHandles.mNode.mNext;
                    v67 = v43;
                    v45 = v9->mCurrentLookaheadDistance;
                    v68 = v44;
                    UFG::LookAheadOnRoadNetwork((UFG::RoadLaneLookAhead *)&pos, v45, &result);
                    if ( result.mfDistanceToLane < 10.0 )
                    {
                      v17 = result.mFinalPos.x;
                      v18 = result.mFinalPos.y;
                      v19 = result.mFinalPos.z;
                      v14 = (float)(10.0 - result.mfDistanceToLane) * 0.1;
                    }
                    v46 = *((float *)&v36[2].m_BoundComponentHandles.mNode.mPrev + 1);
                    v47 = *(float *)&v36[2].m_BoundComponentHandles.mNode.mNext;
                    UFG::gDBG_posVehicle.x = *(float *)&v36[2].m_BoundComponentHandles.mNode.mPrev;
                    UFG::gDBG_posVehicle.y = v46;
                    UFG::gDBG_posLaneNearestPosition = pos;
                    UFG::gDBG_posVehicle.z = v47;
                    UFG::gDBG_final_pos.x = result.mFinalPos.x;
                    UFG::gDBG_final_pos.y = result.mFinalPos.y;
                    UFG::gDBG_final_pos.z = result.mFinalPos.z;
                  }
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
    v9->mCurrentLookaheadDistance = 0.0;
  }
  v48 = v9->mCurrentLookaheadDistance;
  v49 = v48;
  v50 = (float)(v48 * v9->mViewerDirection.z) + v9->mViewerPosition.z;
  v51 = (float)(v49 * v9->mViewerDirection.x) + v9->mViewerPosition.x;
  v52 = (float)(v9->mCurrentLookaheadDistance * v9->mViewerDirection.y) + v9->mViewerPosition.y;
  v9->mCurrentLookaheadPos.z = v50;
  v9->mCurrentLookaheadPos.x = v51;
  v9->mCurrentLookaheadPos.y = v52;
  UFG::gDBG_lookahead_original.x = v51;
  UFG::gDBG_lookahead_original.y = v52;
  UFG::gDBG_lookahead_original.z = v50;
  if ( v14 > 0.0 )
  {
    v53 = v9->mCurrentLookaheadPos.y + (float)((float)(v18 - v9->mCurrentLookaheadPos.y) * v14);
    v54 = v9->mCurrentLookaheadPos.z + (float)((float)(v19 - v9->mCurrentLookaheadPos.z) * v14);
    v9->mCurrentLookaheadPos.x = v9->mCurrentLookaheadPos.x + (float)((float)(v17 - v9->mCurrentLookaheadPos.x) * v14);
    v9->mCurrentLookaheadPos.y = v53;
    v9->mCurrentLookaheadPos.z = v54;
  }
  v55 = v9->mCurrentLookaheadPos.y;
  v56 = v9->mCurrentLookaheadPos.z;
  UFG::gDBG_lookahead_modified.x = v9->mCurrentLookaheadPos.x;
  UFG::gDBG_lookahead_modified.y = v55;
  UFG::gDBG_lookahead_modified.z = v56;
  v9->mfCurrentAngle = v13;
}

// File Line: 419
// RVA: 0x4CA0D0
void __fastcall UFG::RoadnetworkLookahead::DebugDraw(UFG::RoadnetworkLookahead *this, Render::View *pView)
{
  Render::View *v2; // rbx
  unsigned int v3; // eax

  v2 = pView;
  v3 = _S5_10;
  if ( !(_S5_10 & 1) )
  {
    v3 = _S5_10 | 1;
    _S5_10 |= 1u;
    drawinfoWhite.mColour1 = UFG::qColour::White;
    drawinfoWhite.mColour2 = UFG::qColour::White;
    drawinfoWhite.mScale = 1.0;
    drawinfoWhite.mAlphaBlend = 662883558;
    *(_WORD *)&drawinfoWhite.mDepthBuffer = 256;
    drawinfoWhite.mDepthBias = 0;
    drawinfoWhite.mPreDrawCallback = 0i64;
  }
  if ( !(v3 & 2) )
  {
    v3 |= 2u;
    _S5_10 = v3;
    drawinfoRed.mColour1 = UFG::qColour::Red;
    drawinfoRed.mColour2 = UFG::qColour::Red;
    drawinfoRed.mScale = 1.0;
    drawinfoRed.mAlphaBlend = 662883558;
    *(_WORD *)&drawinfoRed.mDepthBuffer = 256;
    drawinfoRed.mDepthBias = 0;
    drawinfoRed.mPreDrawCallback = 0i64;
  }
  if ( !(v3 & 4) )
  {
    v3 |= 4u;
    _S5_10 = v3;
    drawinfoBlue.mColour1 = UFG::qColour::Blue;
    drawinfoBlue.mColour2 = UFG::qColour::Blue;
    drawinfoBlue.mScale = 1.0;
    drawinfoBlue.mAlphaBlend = 662883558;
    *(_WORD *)&drawinfoBlue.mDepthBuffer = 256;
    drawinfoBlue.mDepthBias = 0;
    drawinfoBlue.mPreDrawCallback = 0i64;
  }
  if ( !(v3 & 8) )
  {
    _S5_10 = v3 | 8;
    drawinfoGreen.mColour1 = UFG::qColour::Green;
    drawinfoGreen.mColour2 = UFG::qColour::Green;
    drawinfoGreen.mScale = 1.0;
    drawinfoGreen.mAlphaBlend = 662883558;
    *(_WORD *)&drawinfoGreen.mDepthBuffer = 256;
    drawinfoGreen.mDepthBias = 0;
    drawinfoGreen.mPreDrawCallback = 0i64;
  }
  Render::View::DrawSegment(pView, &UFG::gDBG_posVehicle, &UFG::gDBG_posLaneNearestPosition, &drawinfoRed);
  Render::View::DrawSegment(v2, &UFG::gDBG_posVehicle, &UFG::gDBG_final_pos, &drawinfoWhite);
  Render::View::DrawCross(v2, &UFG::gDBG_final_pos, &drawinfoWhite);
  Render::View::DrawCross(v2, &UFG::gDBG_lookahead_original, &drawinfoBlue);
  Render::View::DrawCross(v2, &UFG::gDBG_lookahead_modified, &drawinfoGreen);
}

