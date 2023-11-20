// File Line: 70
// RVA: 0xD1E70
void __fastcall UFG::RoadNetworkLocation::Advance(UFG::RoadNetworkLocation *this, float advanceDist, UFG::RoadNetworkLane *nextLane, UFG::RoadNetworkLane *laneAfterNext)
{
  UFG::RoadNetworkLane *v4; // rax
  UFG::RoadNetworkLane *v5; // r15
  UFG::RoadNetworkLane *v6; // r14
  float v7; // xmm12_4
  UFG::RoadNetworkLocation *v8; // rdi
  __int64 v9; // rcx
  __int64 v10; // r8
  __int64 v11; // rax
  float v12; // xmm6_4
  signed __int64 v13; // rdx
  __int64 v14; // rax
  signed __int64 v15; // rsi
  __int64 v16; // rax
  UFG::RoadNetworkConnection *v17; // rcx
  UFG::qBezierPathMemImaged *v18; // rax
  UFG::RoadNetworkConnection *v19; // rbx
  unsigned int v20; // eax
  UFG::qBezierSplineMemImaged *v21; // rax
  UFG::RoadNetworkLane *v22; // rsi
  __int64 v23; // rax
  UFG::RoadNetworkConnection *v24; // rcx
  UFG::qBezierPathMemImaged *v25; // rax
  float v26; // xmm10_4
  UFG::RoadNetworkConnection *v27; // rbx
  unsigned int v28; // eax
  UFG::qBezierSplineMemImaged *v29; // rax
  __m128 v30; // xmm2
  int v31; // xmm8_4
  float v32; // xmm7_4
  UFG::qVector3 *v33; // rax
  __m128 v34; // xmm2
  float v35; // xmm0_4
  float v36; // xmm1_4
  UFG::qVector3 *v37; // rax
  __m128 v38; // xmm2
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm9_4
  unsigned int v42; // er14
  UFG::RoadNetworkLane *v43; // rcx
  float v44; // xmm6_4
  __int64 v45; // rax
  __int64 v46; // rdx
  __int64 v47; // rcx
  __int64 v48; // rax
  signed __int64 v49; // rdx
  signed __int64 v50; // rsi
  __int64 v51; // rax
  UFG::RoadNetworkConnection *v52; // rcx
  UFG::qBezierPathMemImaged *v53; // rax
  UFG::RoadNetworkConnection *v54; // rbx
  unsigned int v55; // eax
  UFG::qBezierSplineMemImaged *v56; // rax
  __m128 v57; // xmm2
  float v58; // xmm1_4
  UFG::qVector3 result; // [rsp+8h] [rbp-79h]
  UFG::qVector3 v60; // [rsp+18h] [rbp-69h]
  UFG::qVector3 v61; // [rsp+28h] [rbp-59h]
  float splineT; // [rsp+E8h] [rbp+67h]

  v4 = this->m_CurrentLane;
  v5 = laneAfterNext;
  v6 = nextLane;
  v7 = advanceDist;
  v8 = this;
  if ( v4 )
  {
    v9 = v4->mNode.mOffset;
    if ( v4->mNode.mOffset )
      v9 += (__int64)v4;
    v10 = v4->mLaneIndex;
    v11 = *(_QWORD *)(v9 + 48);
    v12 = v8->m_LaneT;
    if ( v11 )
      v13 = v11 + v9 + 48;
    else
      v13 = 0i64;
    v14 = *(_QWORD *)(v13 + 8 * v10);
    if ( v14 )
      v15 = v14 + v13 + 8 * v10;
    else
      v15 = 0i64;
    v16 = *(_QWORD *)v15;
    if ( *(_QWORD *)v15 )
      v16 += v15;
    v17 = *(UFG::RoadNetworkConnection **)(v16 + 32);
    if ( v17 )
      v17 = (UFG::RoadNetworkConnection *)((char *)v17 + v16 + 32);
    v18 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         v17,
                                         *(unsigned __int16 *)(v15 + 38));
    v19 = (UFG::RoadNetworkConnection *)v18;
    v20 = UFG::qBezierPathMemImaged::GetSplineParameters(v18, v12, &splineT);
    v21 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v19, v20);
    UFG::RoadNetworkLane::GetOffsetPos(&result, v21, splineT, *(float *)(v15 + 40));
    v22 = v8->m_CurrentLane;
    v23 = v22->mNode.mOffset;
    if ( v22->mNode.mOffset )
      v23 += (__int64)v22;
    v24 = *(UFG::RoadNetworkConnection **)(v23 + 32);
    if ( v24 )
      v24 = (UFG::RoadNetworkConnection *)((char *)v24 + v23 + 32);
    v25 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v24, v22->mPathIndex);
    v26 = *(float *)&FLOAT_1_0;
    v27 = (UFG::RoadNetworkConnection *)v25;
    v28 = UFG::qBezierPathMemImaged::GetSplineParameters(v25, 1.0, &splineT);
    v29 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v27, v28);
    UFG::RoadNetworkLane::GetOffsetPos(&v60, v29, splineT, v22->mOffset);
    v30 = (__m128)LODWORD(v60.y);
    v31 = LODWORD(advanceDist) ^ _xmm[0];
    v30.m128_f32[0] = (float)((float)((float)(v60.y - result.y) * (float)(v60.y - result.y))
                            + (float)((float)(v60.x - result.x) * (float)(v60.x - result.x)))
                    + (float)((float)(v60.z - result.z) * (float)(v60.z - result.z));
    v32 = COERCE_FLOAT(_mm_sqrt_ps(v30)) - advanceDist;
    if ( v32 > 0.0 )
      goto LABEL_45;
    if ( !v6 )
      goto LABEL_46;
    if ( v8->m_CurrentLane == v6 )
      goto LABEL_46;
    *(float *)&v31 = v32;
    v8->m_CurrentLane = v6;
    v8->m_LaneT = 0.0;
    v33 = UFG::RoadNetworkLane::GetPos(v6, &v61, 1.0);
    v34 = (__m128)LODWORD(v33->y);
    v35 = v33->x;
    v36 = v33->z;
    LODWORD(v60.y) = v34.m128_i32[0];
    v60.x = v35;
    v60.z = v36;
    v34.m128_f32[0] = (float)((float)((float)(v34.m128_f32[0] - result.y) * (float)(v34.m128_f32[0] - result.y))
                            + (float)((float)(v35 - result.x) * (float)(v35 - result.x)))
                    + (float)((float)(v36 - result.z) * (float)(v36 - result.z));
    v32 = COERCE_FLOAT(_mm_sqrt_ps(v34)) - v7;
    if ( v32 > 0.0 )
      goto LABEL_45;
    if ( !v5 )
      goto LABEL_46;
    if ( v8->m_CurrentLane == v5 )
      goto LABEL_46;
    *(float *)&v31 = v32;
    v8->m_CurrentLane = v5;
    v37 = UFG::RoadNetworkLane::GetPos(v5, &v61, 1.0);
    v38 = (__m128)LODWORD(v37->y);
    v39 = v37->x;
    v40 = v37->z;
    LODWORD(v60.y) = v38.m128_i32[0];
    v60.x = v39;
    v60.z = v40;
    v38.m128_f32[0] = (float)((float)((float)(v38.m128_f32[0] - result.y) * (float)(v38.m128_f32[0] - result.y))
                            + (float)((float)(v39 - result.x) * (float)(v39 - result.x)))
                    + (float)((float)(v40 - result.z) * (float)(v40 - result.z));
    v32 = COERCE_FLOAT(_mm_sqrt_ps(v38)) - v7;
    if ( v32 > 0.0 )
    {
LABEL_45:
      v41 = v8->m_LaneT;
      v42 = 0;
      do
      {
        v43 = v8->m_CurrentLane;
        v44 = (float)((float)(*(float *)&v31 / (float)(*(float *)&v31 - v32)) * (float)(v26 - v41)) + v41;
        v8->m_LaneT = v44;
        v45 = v43->mNode.mOffset;
        if ( v43->mNode.mOffset )
          v45 += (__int64)v43;
        v46 = v43->mLaneIndex;
        v47 = *(_QWORD *)(v45 + 48);
        if ( v47 )
          v47 += v45 + 48;
        v48 = *(_QWORD *)(v47 + 8 * v46);
        v49 = v47 + 8 * v46;
        if ( v48 )
          v50 = v48 + v49;
        else
          v50 = 0i64;
        v51 = *(_QWORD *)v50;
        if ( *(_QWORD *)v50 )
          v51 += v50;
        v52 = *(UFG::RoadNetworkConnection **)(v51 + 32);
        if ( v52 )
          v52 = (UFG::RoadNetworkConnection *)((char *)v52 + v51 + 32);
        v53 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v52,
                                             *(unsigned __int16 *)(v50 + 38));
        v54 = (UFG::RoadNetworkConnection *)v53;
        v55 = UFG::qBezierPathMemImaged::GetSplineParameters(v53, v44, &splineT);
        v56 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v54, v55);
        UFG::RoadNetworkLane::GetOffsetPos(&v61, v56, splineT, *(float *)(v50 + 40));
        v57 = (__m128)LODWORD(v61.y);
        v57.m128_f32[0] = (float)((float)((float)(v61.y - result.y) * (float)(v61.y - result.y))
                                + (float)((float)(v61.x - result.x) * (float)(v61.x - result.x)))
                        + (float)((float)(v61.z - result.z) * (float)(v61.z - result.z));
        v58 = COERCE_FLOAT(_mm_sqrt_ps(v57)) - v7;
        if ( COERCE_FLOAT(LODWORD(v58) & _xmm) < 0.1 )
          break;
        if ( v58 <= 0.0 )
        {
          v41 = v8->m_LaneT;
          *(float *)&v31 = v58;
        }
        else
        {
          v26 = v8->m_LaneT;
          v32 = v58;
        }
        ++v42;
      }
      while ( v42 < 0xA );
    }
    else
    {
LABEL_46:
      v8->m_LaneT = 1.0;
    }
  }
}

// File Line: 136
// RVA: 0xDEE30
_BOOL8 __fastcall UFG::RoadNetworkLocation::IsValid(UFG::RoadNetworkLocation *this)
{
  return this->m_CurrentLane != 0i64;
}

// File Line: 142
// RVA: 0xD29C0
void __fastcall UFG::RoadNetworkLocation::AttachToNetwork(UFG::RoadNetworkLocation *this, UFG::RoadNetworkResource *roadNetwork, UFG::qVector3 *spawnPos, UFG::qVector3 *spawnHeading, unsigned int type)
{
  UFG::RoadNetworkLocation *v5; // rbx
  UFG::qVector3 *v6; // rsi
  UFG::qVector3 *v7; // rdi
  UFG::RoadNetworkNode *v8; // rax
  float v9; // xmm0_4
  UFG::qVector3 result; // [rsp+30h] [rbp-18h]
  float nearestT; // [rsp+50h] [rbp+8h]
  UFG::RoadNetworkLane *nearestLane; // [rsp+58h] [rbp+10h]

  v5 = this;
  v6 = spawnHeading;
  v7 = spawnPos;
  this->m_CurrentLane = 0i64;
  this->m_LaneT = 0.0;
  if ( roadNetwork )
  {
    nearestLane = 0i64;
    nearestT = 0.0;
    v8 = UFG::RoadNetworkResource::GetClosestNode(roadNetwork, spawnPos, type, 0i64, 0i64);
    if ( v6 )
      UFG::RoadNetworkNode::GetNearestPos(v8, &result, v7, v6, &nearestLane, &nearestT);
    else
      UFG::RoadNetworkNode::GetNearestPos(v8, &result, v7, &nearestLane, &nearestT);
    if ( nearestLane )
    {
      v9 = nearestT;
      v5->m_CurrentLane = nearestLane;
      v5->m_LaneT = v9;
    }
  }
}

// File Line: 178
// RVA: 0xD8740
float __fastcall UFG::RoadNetworkLocation::GetDistanceAlongSpline(UFG::RoadNetworkLocation *this)
{
  UFG::RoadNetworkLane *v1; // rdx
  UFG::RoadNetworkLocation *v2; // rbx
  UFG::RoadNetworkConnection *v3; // rcx
  char *v4; // rax
  unsigned int v5; // er8
  __int64 v6; // rdx

  v1 = this->m_CurrentLane;
  v2 = this;
  v3 = 0i64;
  if ( v1->mNode.mOffset )
    v4 = (char *)v1 + v1->mNode.mOffset;
  else
    v4 = 0i64;
  v5 = v1->mPathIndex;
  v6 = *((_QWORD *)v4 + 4);
  if ( v6 )
    v3 = (UFG::RoadNetworkConnection *)&v4[v6 + 32];
  return *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v3, v5)->mNode.mOffset + 1) * v2->m_LaneT;
}

// File Line: 184
// RVA: 0xD96A0
float __fastcall UFG::RoadNetworkLocation::GetLaneOffset(UFG::RoadNetworkLocation *this)
{
  return this->m_CurrentLane->mOffset;
}

// File Line: 190
// RVA: 0xD3090
bool __fastcall UFG::RoadNetworkLocation::CanReachLane(UFG::RoadNetworkLocation *this, int left_right)
{
  UFG::RoadNetworkLane *v2; // rbx
  int v3; // edi
  __int64 v4; // rax
  float v5; // xmm6_4
  bool v6; // al
  signed int v7; // er8
  int v8; // ecx
  int v9; // er8
  int v10; // eax

  v2 = this->m_CurrentLane;
  v3 = left_right;
  if ( !v2 )
    return 0;
  v4 = v2->mNode.mOffset;
  if ( !v2->mNode.mOffset || !(UFG::RoadNetworkLane *)((char *)v2 + v4) )
    return 0;
  v5 = *(float *)&FLOAT_1_0;
  if ( (float)*((unsigned __int8 *)&v2->mOffset + v4) >= 1.0 )
    v5 = (float)*((unsigned __int8 *)&v2->mOffset + v4);
  v6 = UFG::RoadNetworkLane::IsReversedInNode(v2);
  v7 = 1;
  if ( v6 )
    v7 = -1;
  v8 = 0;
  v9 = v2->mLaneIndex + v3 * v7;
  v10 = (signed int)v5 - 1;
  if ( v9 > 0 )
    v8 = v9;
  if ( v8 < v10 )
    v10 = v8;
  return v9 == v10;
}

// File Line: 207
// RVA: 0xDC720
void __fastcall UFG::RoadNetworkLocation::GetVectors(UFG::RoadNetworkLocation *this, UFG::qVector3 *pos, UFG::qVector3 *direction)
{
  UFG::RoadNetworkLane *v3; // r9
  UFG::RoadNetworkLocation *v4; // r10
  UFG::RoadNetworkLane *v5; // rcx
  UFG::qVector3 *v6; // r11
  UFG::qVector3 *v7; // rbx
  char *v8; // rax
  __int64 v9; // rdx
  __int64 v10; // r8
  signed __int64 v11; // rdx
  __int64 v12; // rax
  signed __int64 v13; // r8

  v3 = this->m_CurrentLane;
  v4 = this;
  v5 = 0i64;
  v6 = direction;
  v7 = pos;
  if ( v3->mNode.mOffset )
    v8 = (char *)v3 + v3->mNode.mOffset;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 6);
  v10 = v3->mLaneIndex;
  if ( v9 )
    v11 = (signed __int64)&v8[v9 + 48];
  else
    v11 = 0i64;
  v12 = *(_QWORD *)(v11 + 8 * v10);
  v13 = v11 + 8 * v10;
  if ( v12 )
    v5 = (UFG::RoadNetworkLane *)(v12 + v13);
  UFG::RoadNetworkLane::GetPosAndTangent(v5, v4->m_LaneT, v7, v6);
}

// File Line: 213
// RVA: 0xDB400
UFG::qVector3 *__fastcall UFG::RoadNetworkLocation::GetPos(UFG::RoadNetworkLocation *this, UFG::qVector3 *result)
{
  UFG::RoadNetworkLane *v2; // r8
  UFG::RoadNetworkLocation *v3; // r9
  UFG::RoadNetworkLane *v4; // rcx
  UFG::qVector3 *v5; // rbx
  char *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // r10
  signed __int64 v9; // rdx
  __int64 v10; // rax

  v2 = this->m_CurrentLane;
  v3 = this;
  v4 = 0i64;
  v5 = result;
  if ( v2->mNode.mOffset )
    v6 = (char *)v2 + v2->mNode.mOffset;
  else
    v6 = 0i64;
  v7 = *((_QWORD *)v6 + 6);
  v8 = v2->mLaneIndex;
  if ( v7 )
    v9 = (signed __int64)&v6[v7 + 48];
  else
    v9 = 0i64;
  v10 = *(_QWORD *)(v9 + 8 * v8);
  if ( v10 )
    v4 = (UFG::RoadNetworkLane *)(v10 + v9 + 8 * v8);
  UFG::RoadNetworkLane::GetPos(v4, v5, v3->m_LaneT);
  return v5;
}

// File Line: 219
// RVA: 0xDB780
UFG::RoadNetworkNode *__fastcall UFG::RoadNetworkLocation::GetRoadNetworkNode(UFG::RoadNetworkLocation *this)
{
  UFG::RoadNetworkLane *v1; // rax
  UFG::RoadNetworkNode *result; // rax

  v1 = this->m_CurrentLane;
  if ( v1->mNode.mOffset )
    result = (UFG::RoadNetworkNode *)((char *)v1 + v1->mNode.mOffset);
  else
    result = 0i64;
  return result;
}

// File Line: 232
// RVA: 0xDBFE0
UFG::qVector3 *__fastcall UFG::RoadNetworkLocation::GetTangent(UFG::RoadNetworkLocation *this, UFG::qVector3 *result)
{
  UFG::RoadNetworkLane *v2; // rax
  UFG::qVector3 *v3; // rbx
  UFG::RoadNetworkLocation *v4; // r9
  UFG::RoadNetworkNode *v5; // rcx

  v2 = this->m_CurrentLane;
  v3 = result;
  v4 = this;
  if ( v2->mNode.mOffset )
    v5 = (UFG::RoadNetworkNode *)((char *)v2 + v2->mNode.mOffset);
  else
    v5 = 0i64;
  UFG::RoadNetworkNode::GetTangent(v5, result, v2->mLaneIndex, v4->m_LaneT);
  return v3;
}

// File Line: 238
// RVA: 0xD3210
void __fastcall UFG::RoadNetworkLocation::ChangeLane(UFG::RoadNetworkLocation *this, unsigned int direction)
{
  UFG::RoadNetworkLane *v2; // r14
  signed __int64 v3; // rbx
  UFG::RoadNetworkLocation *v4; // rbp
  char *v5; // rsi
  int v6; // edi
  bool v7; // r8
  int v8; // eax
  __int64 v9; // rdx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  __int64 v12; // rax
  signed __int64 v13; // rdx
  UFG::RoadNetworkLane *v14; // rax
  __int64 v15; // rcx
  signed __int64 v16; // rdx
  char *v17; // rcx
  __int64 v18; // rax
  char *v19; // rax
  char *v20; // rcx
  __int64 v21; // rax

  v2 = this->m_CurrentLane;
  v3 = 0i64;
  v4 = this;
  v5 = (char *)v2 + v2->mNode.mOffset;
  if ( !v2->mNode.mOffset )
    v5 = 0i64;
  if ( *(_WORD *)v5 != 1 )
  {
    v6 = -1;
    if ( direction == 1 )
      v6 = 1;
    v7 = UFG::RoadNetworkLane::IsReversedInNode(v2);
    if ( v7 )
      v6 = -v6;
    v8 = 0;
    v9 = (unsigned int)(unsigned __int8)v5[40] - 1;
    if ( v6 + v2->mLaneIndex > 0 )
      v8 = v6 + v2->mLaneIndex;
    if ( v8 < (signed int)v9 )
      v9 = (unsigned int)v8;
    v10 = *((_QWORD *)v5 + 6);
    if ( v10 )
      v11 = (signed __int64)&v5[v10 + 48];
    else
      v11 = 0i64;
    v12 = *(_QWORD *)(v11 + 8 * v9);
    v13 = v11 + 8 * v9;
    if ( v12 )
    {
      v14 = (UFG::RoadNetworkLane *)(v13 + v12);
      if ( v14 )
      {
        v4->m_CurrentLane = v14;
        v15 = v14->mStartGate.mOffset;
        if ( v15 )
          v16 = (signed __int64)&v14->mStartGate + v15;
        else
          v16 = 0i64;
        if ( v14->mNode.mOffset )
          v17 = (char *)v14 + v14->mNode.mOffset;
        else
          v17 = 0i64;
        v18 = *((_QWORD *)v17 + 6);
        if ( v18 )
          v19 = &v17[v18 + 48];
        else
          v19 = 0i64;
        if ( *(_QWORD *)v19 )
          v20 = &v19[*(_QWORD *)v19];
        else
          v20 = 0i64;
        v21 = *((_QWORD *)v20 + 1);
        if ( v21 )
          v3 = (signed __int64)&v20[v21 + 8];
        if ( (v16 != v3) != v7 )
          v4->m_LaneT = 1.0 - v4->m_LaneT;
      }
    }
  }
}

// File Line: 301
// RVA: 0xD49C0
float __fastcall UFG::RoadNetworkLocation::FindLaneTWithCustomSearch(UFG::RoadNetworkLocation *this, UFG::qVector3 *position, UFG::RoadNetworkLane *nextLane)
{
  UFG::RoadNetworkLocation *v3; // rsi
  UFG::RoadNetworkLane *v4; // r14
  UFG::qVector3 *v5; // r15
  float v6; // xmm11_4
  UFG::RoadNetworkLane *v7; // rcx
  __int64 v8; // rax
  unsigned int v9; // edx
  UFG::RoadNetworkConnection *v10; // rcx
  float v11; // xmm6_4
  float v12; // xmm14_4
  float v13; // xmm7_4
  float v14; // xmm0_4
  float v15; // xmm13_4
  char v16; // bp
  UFG::RoadNetworkLane *v17; // rcx
  __int64 v18; // rax
  __int64 v19; // rdx
  __int64 v20; // rcx
  __int64 v21; // rax
  signed __int64 v22; // rdx
  signed __int64 v23; // rdi
  __int64 v24; // rax
  UFG::RoadNetworkConnection *v25; // rcx
  UFG::qBezierPathMemImaged *v26; // rax
  UFG::RoadNetworkConnection *v27; // rbx
  unsigned int v28; // eax
  UFG::qBezierSplineMemImaged *v29; // rax
  float v30; // xmm9_4
  int v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm5_4
  float v36; // xmm0_4
  float v37; // xmm4_4
  float v38; // xmm1_4
  float v39; // xmm9_4
  __int64 v40; // rax
  float v41; // xmm7_4
  UFG::RoadNetworkConnection *v42; // rcx
  UFG::RoadNetworkLane *v43; // rax
  UFG::RoadNetworkLane *v44; // rcx
  __int64 v45; // rax
  unsigned int v46; // edx
  UFG::RoadNetworkConnection *v47; // rcx
  UFG::qVector3 positiona; // [rsp+20h] [rbp-D8h]
  UFG::qVector3 tangent; // [rsp+30h] [rbp-C8h]
  float splineT; // [rsp+100h] [rbp+8h]

  v3 = this;
  v4 = nextLane;
  v5 = position;
  v6 = this->m_LaneT;
  v7 = this->m_CurrentLane;
  v8 = v7->mNode.mOffset;
  if ( v7->mNode.mOffset )
    v8 += (__int64)v7;
  v9 = v7->mPathIndex;
  v10 = *(UFG::RoadNetworkConnection **)(v8 + 32);
  if ( v10 )
    v10 = (UFG::RoadNetworkConnection *)((char *)v10 + v8 + 32);
  v11 = *(float *)&FLOAT_1_0;
  v12 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v10, v9)->mNode.mOffset + 1);
  v13 = 1.0 / v12;
  v14 = (float)(1.0 / v12) + v3->m_LaneT;
  v15 = (float)(1.0 / v12) * 0.039999999;
  if ( v14 <= 0.0 )
  {
    v14 = 0.0;
    goto LABEL_9;
  }
  if ( v14 < 1.0 )
LABEL_9:
    v11 = v14;
  v16 = 0;
  if ( v13 <= v15 )
    return v6;
  while ( 1 )
  {
    v17 = v3->m_CurrentLane;
    v3->m_LaneT = v11;
    v18 = v17->mNode.mOffset;
    if ( v17->mNode.mOffset )
      v18 += (__int64)v17;
    v19 = v17->mLaneIndex;
    v20 = *(_QWORD *)(v18 + 48);
    if ( v20 )
      v20 += v18 + 48;
    v21 = *(_QWORD *)(v20 + 8 * v19);
    v22 = v20 + 8 * v19;
    if ( v21 )
      v23 = v21 + v22;
    else
      v23 = 0i64;
    v24 = *(_QWORD *)v23;
    if ( *(_QWORD *)v23 )
      v24 += v23;
    v25 = *(UFG::RoadNetworkConnection **)(v24 + 32);
    if ( v25 )
      v25 = (UFG::RoadNetworkConnection *)((char *)v25 + v24 + 32);
    v26 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         v25,
                                         *(unsigned __int16 *)(v23 + 38));
    v27 = (UFG::RoadNetworkConnection *)v26;
    v28 = UFG::qBezierPathMemImaged::GetSplineParameters(v26, v11, &splineT);
    v29 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v27, v28);
    v30 = *(float *)(v23 + 40);
    UFG::qBezierSplineMemImaged::GetPositionAndTangent(v29, splineT, &positiona, &tangent);
    if ( v30 == 0.0 )
    {
      v39 = positiona.z;
      v35 = positiona.y;
      v37 = positiona.x;
    }
    else
    {
      v31 = LODWORD(tangent.x) ^ _xmm[0];
      v32 = (float)(*(float *)&v31 * *(float *)&v31) + (float)(tangent.y * tangent.y);
      if ( v32 == 0.0 )
        v33 = 0.0;
      else
        v33 = 1.0 / fsqrt(v32);
      v34 = (float)(*(float *)&v31 * v33) * v30;
      v35 = positiona.y + v34;
      v36 = (float)(tangent.y * v33) * v30;
      positiona.y = positiona.y + v34;
      v37 = positiona.x + v36;
      v38 = (float)(v33 * 0.0) * v30;
      positiona.x = positiona.x + v36;
      v39 = positiona.z + v38;
      positiona.z = positiona.z + v38;
    }
    if ( (float)((float)((float)((float)(v5->y - v35) * tangent.y) + (float)((float)(v5->x - v37) * tangent.x))
               + (float)(tangent.z * (float)(v5->z - v39))) < 0.0 )
    {
      v13 = v13 * 0.5;
      v11 = v13 + v6;
    }
    else
    {
      v6 = v11;
      v11 = v11 + v13;
    }
    if ( v11 <= 0.0 )
    {
      v11 = 0.0;
    }
    else if ( v11 >= 1.0 )
    {
      v11 = *(float *)&FLOAT_1_0;
    }
    if ( v6 >= 1.0 )
    {
      if ( !v4 || v16 )
        return v6;
      v3->m_CurrentLane = v4;
      v40 = v4->mNode.mOffset;
      v16 = 1;
      v6 = 0.0;
      v41 = v13 * v12;
      if ( v4->mNode.mOffset )
        v40 += (__int64)v4;
      v42 = *(UFG::RoadNetworkConnection **)(v40 + 32);
      if ( v42 )
        v42 = (UFG::RoadNetworkConnection *)((char *)v42 + v40 + 32);
      v43 = UFG::qBezierPathCollectionMemImaged::GetPath(v42, v4->mPathIndex);
      v44 = v3->m_CurrentLane;
      v11 = v41 / *((float *)&v43->mNode.mOffset + 1);
      v45 = v44->mNode.mOffset;
      if ( v44->mNode.mOffset )
        v45 += (__int64)v44;
      v46 = v44->mPathIndex;
      v47 = *(UFG::RoadNetworkConnection **)(v45 + 32);
      if ( v47 )
        v47 = (UFG::RoadNetworkConnection *)((char *)v47 + v45 + 32);
      v13 = v41 / *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v47, v46)->mNode.mOffset + 1);
    }
    if ( !v3->m_CurrentLane )
      break;
    if ( v13 <= v15 )
      return v6;
  }
  v3->m_LaneT = 0.0;
  return v6;
}

// File Line: 409
// RVA: 0xCF850
void __fastcall UFG::RoadNetworkGuide::RoadNetworkGuide(UFG::RoadNetworkGuide *this)
{
  UFG::RoadNetworkGuide *v1; // rbx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v2; // rax
  UFG::qSafePointer<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qSafePointerNode<UFG::RoadNetworkGuide>::qSafePointerNode<UFG::RoadNetworkGuide>((UFG::qSafePointerNode<UFG::RoadNetworkGuide> *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::RoadNetworkGuide>Vtbl *)&UFG::RoadNetworkGuide::`vftable';
  v1->m_TargetLocation.m_LaneT = 0.0;
  v1->m_TargetLocation.m_CurrentLane = 0i64;
  v1->m_CurrentLocation.m_LaneT = 0.0;
  v1->m_CurrentLocation.m_CurrentLane = 0i64;
  v1->m_NextLane = 0i64;
  v1->m_LaneAfterNext = 0i64;
  v1->m_FrontBoundary = 4.0;
  *(_QWORD *)&v1->m_RearBoundary = 1082130432i64;
  *(_QWORD *)&v1->m_SpeedLimit = 1099222221i64;
  *(_QWORD *)&v1->m_NextGuideDistance = 0i64;
  v3 = &v1->m_NextGuide;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->m_NextGuide.m_pPointer = 0i64;
  *(_WORD *)&v1->m_Attached = 0;
  v1->m_AdvanceDistance = 5.0;
}

// File Line: 415
// RVA: 0xD27F0
void __fastcall UFG::RoadNetworkGuide::AttachToNetwork(UFG::RoadNetworkGuide *this, UFG::SimObject *simObj, UFG::RoadNetworkNode *node, const unsigned int lane, const float laneT)
{
  float *v5; // rsi
  UFG::SimObject *v6; // rbx
  UFG::RoadNetworkGuide *v7; // rdi
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v8; // r10
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v9; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v10; // r11
  __int64 v11; // rax
  char *v12; // rcx
  __int64 v13; // rax
  UFG::RoadNetworkLane *v14; // rcx
  UFG::RoadNetworkLane *v15; // rax
  UFG::RoadNetworkLane *v16; // rcx
  __int64 v17; // rax
  char *v18; // rax
  __int64 v19; // rdx
  __int64 v20; // rcx
  float v21; // xmm6_4
  signed __int64 v22; // rcx
  __int64 v23; // rax
  signed __int64 v24; // r14
  signed __int64 v25; // rax
  __int64 v26; // rcx
  UFG::RoadNetworkConnection *v27; // rcx
  UFG::qBezierPathMemImaged *v28; // rax
  UFG::RoadNetworkConnection *v29; // rbx
  unsigned int v30; // eax
  UFG::qBezierSplineMemImaged *v31; // rax
  float v32; // xmm1_4
  float v33; // xmm0_4
  UFG::RoadNetworkLane *v34; // rax
  _WORD *v35; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-28h]

  v5 = 0i64;
  v6 = simObj;
  v7 = this;
  if ( this->m_Attached )
  {
    v8 = this->mPrev;
    v9 = this->mNext;
    v10 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)&this->mPrev;
    v8->mNext = v9;
    v9->mPrev = v8;
    v10->mPrev = v10;
    v10->mNext = v10;
    this->m_NextLane = 0i64;
    this->m_Attached = 0;
  }
  this->m_CurrentLocation.m_LaneT = laneT;
  v11 = node->mLane.mOffset;
  if ( v11 )
    v12 = (char *)&node->mLane + v11;
  else
    v12 = 0i64;
  v13 = *(_QWORD *)&v12[8 * lane];
  v14 = (UFG::RoadNetworkLane *)&v12[8 * lane + v13];
  if ( !v13 )
    v14 = 0i64;
  v7->m_CurrentLocation.m_CurrentLane = v14;
  v7->m_Attached = 1;
  UFG::RoadNetworkLane::AddCarGuide(v14, v7, 1);
  *(_QWORD *)&v7->m_TargetLocation.m_LaneT = *(_QWORD *)&v7->m_CurrentLocation.m_LaneT;
  v15 = v7->m_CurrentLocation.m_CurrentLane;
  v7->m_SimObj = v6;
  v7->m_TargetLocation.m_CurrentLane = v15;
  v16 = v15;
  v17 = v15->mNode.mOffset;
  if ( v17 )
    v18 = (char *)v16 + v17;
  else
    v18 = 0i64;
  v19 = v16->mLaneIndex;
  v20 = *((_QWORD *)v18 + 6);
  v21 = v7->m_CurrentLocation.m_LaneT;
  if ( v20 )
    v22 = (signed __int64)&v18[v20 + 48];
  else
    v22 = 0i64;
  v23 = *(_QWORD *)(v22 + 8 * v19);
  v24 = v23 + v22 + 8 * v19;
  if ( !v23 )
    v24 = 0i64;
  if ( *(_QWORD *)v24 )
    v25 = v24 + *(_QWORD *)v24;
  else
    v25 = 0i64;
  v26 = *(_QWORD *)(v25 + 32);
  if ( v26 )
    v27 = (UFG::RoadNetworkConnection *)(v25 + v26 + 32);
  else
    v27 = 0i64;
  v28 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v27, *(unsigned __int16 *)(v24 + 38));
  v29 = (UFG::RoadNetworkConnection *)v28;
  v30 = UFG::qBezierPathMemImaged::GetSplineParameters(v28, v21, (float *)&laneT);
  v31 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v29, v30);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v31, laneT, *(float *)(v24 + 40));
  v32 = result.y;
  v7->m_Position.x = result.x;
  v33 = result.z;
  v7->m_Position.y = v32;
  v7->m_Position.z = v33;
  v34 = v7->m_CurrentLocation.m_CurrentLane;
  v7->m_Parked = 0;
  if ( v34->mNode.mOffset )
    v35 = (_WORD *)((char *)v34 + v34->mNode.mOffset);
  else
    v35 = 0i64;
  if ( !*v35 )
  {
    if ( v34->mNode.mOffset )
      v5 = (float *)((char *)v34 + v34->mNode.mOffset);
    v7->m_SpeedLimit = v5[41];
  }
}

// File Line: 455
// RVA: 0xD2FD0
bool __fastcall UFG::RoadNetworkGuide::CanChangeLane(UFG::RoadNetworkGuide *this, unsigned int laneChangeDir)
{
  UFG::RoadNetworkLane *v2; // rsi
  char *v3; // rdi
  char *v4; // r8
  UFG::RoadNetworkLane *v5; // rax
  char *v6; // rax
  int v8; // ebx

  v2 = this->m_CurrentLocation.m_CurrentLane;
  v3 = 0i64;
  v4 = (char *)v2 + v2->mNode.mOffset;
  if ( !v2->mNode.mOffset )
    v4 = 0i64;
  v5 = this->m_TargetLocation.m_CurrentLane;
  if ( v5->mNode.mOffset )
    v6 = (char *)v5 + v5->mNode.mOffset;
  else
    v6 = 0i64;
  if ( v4 != v6 )
    return 0;
  if ( v2->mNode.mOffset )
    v3 = (char *)v2 + v2->mNode.mOffset;
  if ( !v2 || !v3 || *(_WORD *)v3 == 1 )
    return 0;
  if ( !laneChangeDir )
    return 1;
  v8 = -1;
  if ( laneChangeDir == 1 )
    v8 = 1;
  if ( UFG::RoadNetworkLane::IsReversedInNode(v2) )
    v8 = -v8;
  return v8 + (unsigned int)v2->mLaneIndex < (unsigned __int8)v3[40];
}

// File Line: 481
// RVA: 0xD3180
void __fastcall UFG::RoadNetworkGuide::ChangeLane(UFG::RoadNetworkGuide *this, unsigned int direction)
{
  UFG::RoadNetworkLane *v2; // rax
  UFG::RoadNetworkGuide *v3; // rbx
  unsigned int v4; // edi
  __int64 v5; // rcx
  UFG::RoadNetworkLane *v6; // rax
  char *v7; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v8; // rcx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v9; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v10; // rdx
  UFG::RoadNetworkLane *v11; // rcx

  v2 = this->m_CurrentLocation.m_CurrentLane;
  v3 = this;
  v4 = direction;
  v5 = v2->mNode.mOffset;
  if ( v2->mNode.mOffset )
    v5 += (__int64)v2;
  v6 = v3->m_TargetLocation.m_CurrentLane;
  if ( v6->mNode.mOffset )
    v7 = (char *)v6 + v6->mNode.mOffset;
  else
    v7 = 0i64;
  if ( (char *)v5 == v7 )
  {
    v8 = v3->mPrev;
    v9 = v3->mNext;
    v10 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)&v3->mPrev;
    v8->mNext = v9;
    v9->mPrev = v8;
    v10->mPrev = v10;
    v10->mNext = v10;
    UFG::RoadNetworkLocation::ChangeLane(&v3->m_CurrentLocation, v4);
    UFG::RoadNetworkLocation::ChangeLane(&v3->m_TargetLocation, v4);
    v11 = v3->m_CurrentLocation.m_CurrentLane;
    if ( v11 )
      UFG::RoadNetworkLane::AddCarGuide(v11, v3, 1);
    v3->m_NextLane = 0i64;
  }
}

// File Line: 504
// RVA: 0xD3350
char __fastcall UFG::RoadNetworkGuide::ChangeLaneIfRoom(UFG::RoadNetworkGuide *this, unsigned int direction)
{
  UFG::RoadNetworkGuide *v2; // rdi
  UFG::RoadNetworkLane *v4; // rsi
  __int64 v5; // rax
  UFG::RoadNetworkLane *v6; // rbx
  char *v7; // r15
  int v8; // eax
  UFG::RoadNetworkLane *v9; // r12
  bool v10; // zf
  __int64 v11; // rax
  _WORD *v12; // rax
  signed __int64 v13; // rsi
  unsigned int v14; // edx
  bool v15; // al
  signed int v16; // ecx
  __int64 v17; // rax
  signed __int64 v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // rdx
  __int64 v21; // rax
  UFG::RoadNetworkLane *v22; // rdx
  UFG::RoadNetworkLane *v23; // r12
  _WORD *v24; // rax
  bool v25; // al
  signed int v26; // ecx
  __int64 v27; // rax
  signed __int64 v28; // rcx
  __int64 v29; // rax
  unsigned int v30; // edx
  _WORD *v31; // rax
  signed int v32; // er14
  signed __int64 v33; // rsi
  unsigned int v34; // edx
  bool v35; // al
  signed int v36; // ecx
  __int64 v37; // rax
  signed __int64 v38; // rcx
  __int64 v39; // rax
  signed __int64 v40; // rdx
  __int64 v41; // rax
  UFG::RoadNetworkLane *v42; // rdx
  UFG::RoadNetworkLane *v43; // r12
  _WORD *v44; // rax
  __int64 v45; // rax
  signed __int64 v46; // rcx
  __int64 v47; // rax
  _WORD *v48; // rax
  signed __int64 v49; // rsi
  signed int v50; // er14
  bool v51; // al
  int v52; // esi
  __int64 v53; // rax
  signed __int64 v54; // rcx
  __int64 v55; // rax
  _WORD *v56; // rax
  signed __int64 v57; // rsi
  bool v58; // al
  int v59; // esi
  signed int v60; // ecx
  __int64 v61; // rax
  signed __int64 v62; // rcx
  __int64 v63; // rax

  v2 = this;
  if ( !direction )
    return 0;
  v4 = this->m_CurrentLocation.m_CurrentLane;
  v5 = v4->mNode.mOffset;
  v6 = 0i64;
  v7 = (char *)v4 + v4->mNode.mOffset;
  if ( !v4->mNode.mOffset )
    v7 = 0i64;
  if ( direction > 2 )
  {
    v8 = UFG::qRandom(2, &UFG::qDefaultSeed);
    v9 = v2->m_CurrentLocation.m_CurrentLane;
    v10 = v8 == 1;
    v11 = v9->mNode.mOffset;
    if ( v10 )
    {
      if ( v11 )
        v12 = (_WORD *)((char *)v9 + v11);
      else
        v12 = 0i64;
      v13 = 0xFFFFFFFFi64;
      if ( *v12 == 1 )
      {
        v14 = -1;
      }
      else
      {
        v15 = UFG::RoadNetworkLane::IsReversedInNode(v2->m_CurrentLocation.m_CurrentLane);
        v16 = -1;
        if ( v15 )
          v16 = 1;
        v14 = v16 + v9->mLaneIndex;
      }
      v17 = *((_QWORD *)v7 + 6);
      if ( v17 )
        v18 = (signed __int64)&v7[v17 + 48];
      else
        v18 = 0i64;
      v19 = v14;
      v20 = v18 + 8 * v19;
      v21 = *(_QWORD *)(v18 + 8 * v19);
      if ( v21 )
        v22 = (UFG::RoadNetworkLane *)(v21 + v20);
      else
        v22 = 0i64;
      if ( !UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(v2, v22) )
      {
        v23 = v2->m_CurrentLocation.m_CurrentLane;
        if ( v23->mNode.mOffset )
          v24 = (_WORD *)((char *)v23 + v23->mNode.mOffset);
        else
          v24 = 0i64;
        if ( *v24 != 1 )
        {
          v25 = UFG::RoadNetworkLane::IsReversedInNode(v2->m_CurrentLocation.m_CurrentLane);
          v26 = 1;
          if ( v25 )
            v26 = -1;
          v13 = v26 + (unsigned int)v23->mLaneIndex;
        }
        v27 = *((_QWORD *)v7 + 6);
        if ( v27 )
          v28 = (signed __int64)&v7[v27 + 48];
        else
          v28 = 0i64;
        v29 = *(_QWORD *)(v28 + 8 * v13);
        if ( v29 )
          v6 = (UFG::RoadNetworkLane *)(v28 + 8 * v13 + v29);
        if ( UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(v2, v6) )
        {
LABEL_35:
          v30 = 1;
LABEL_36:
          UFG::RoadNetworkGuide::ChangeLane(v2, v30);
          return 1;
        }
        return 0;
      }
    }
    else
    {
      if ( v11 )
        v31 = (_WORD *)((char *)v9 + v11);
      else
        v31 = 0i64;
      v32 = -1;
      v33 = 0xFFFFFFFFi64;
      if ( *v31 == 1 )
      {
        v34 = -1;
      }
      else
      {
        v35 = UFG::RoadNetworkLane::IsReversedInNode(v2->m_CurrentLocation.m_CurrentLane);
        v36 = 1;
        if ( v35 )
          v36 = -1;
        v34 = v36 + v9->mLaneIndex;
      }
      v37 = *((_QWORD *)v7 + 6);
      if ( v37 )
        v38 = (signed __int64)&v7[v37 + 48];
      else
        v38 = 0i64;
      v39 = v34;
      v40 = v38 + 8 * v39;
      v41 = *(_QWORD *)(v38 + 8 * v39);
      if ( v41 )
        v42 = (UFG::RoadNetworkLane *)(v41 + v40);
      else
        v42 = 0i64;
      if ( UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(v2, v42) )
        goto LABEL_35;
      v43 = v2->m_CurrentLocation.m_CurrentLane;
      if ( v43->mNode.mOffset )
        v44 = (_WORD *)((char *)v43 + v43->mNode.mOffset);
      else
        v44 = 0i64;
      if ( *v44 != 1 )
      {
        if ( UFG::RoadNetworkLane::IsReversedInNode(v2->m_CurrentLocation.m_CurrentLane) )
          v32 = 1;
        v33 = v32 + (unsigned int)v43->mLaneIndex;
      }
      v45 = *((_QWORD *)v7 + 6);
      if ( v45 )
        v46 = (signed __int64)&v7[v45 + 48];
      else
        v46 = 0i64;
      v47 = *(_QWORD *)(v46 + 8 * v33);
      if ( v47 )
        v6 = (UFG::RoadNetworkLane *)(v46 + 8 * v33 + v47);
      if ( !UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(v2, v6) )
        return 0;
    }
    v30 = 2;
    goto LABEL_36;
  }
  if ( direction == 2 )
  {
    if ( v5 )
      v48 = (_WORD *)((char *)v4 + v5);
    else
      v48 = 0i64;
    if ( *v48 == 1 )
    {
      v49 = 0xFFFFFFFFi64;
    }
    else
    {
      v50 = -1;
      v51 = UFG::RoadNetworkLane::IsReversedInNode(v4);
      v52 = v4->mLaneIndex;
      if ( v51 )
        v50 = 1;
      v49 = (unsigned int)(v50 + v52);
    }
    v53 = *((_QWORD *)v7 + 6);
    if ( v53 )
      v54 = (signed __int64)&v7[v53 + 48];
    else
      v54 = 0i64;
    v55 = *(_QWORD *)(v54 + 8 * v49);
    if ( v55 )
      v6 = (UFG::RoadNetworkLane *)(v54 + 8 * v49 + v55);
    if ( UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(v2, v6) )
    {
      UFG::RoadNetworkGuide::ChangeLane(v2, 2u);
      return 1;
    }
  }
  else
  {
    if ( v5 )
      v56 = (_WORD *)((char *)v4 + v5);
    else
      v56 = 0i64;
    if ( *v56 == 1 )
    {
      v57 = 0xFFFFFFFFi64;
    }
    else
    {
      v58 = UFG::RoadNetworkLane::IsReversedInNode(v4);
      v59 = v4->mLaneIndex;
      v60 = 1;
      if ( v58 )
        v60 = -1;
      v57 = (unsigned int)(v60 + v59);
    }
    v61 = *((_QWORD *)v7 + 6);
    if ( v61 )
      v62 = (signed __int64)&v7[v61 + 48];
    else
      v62 = 0i64;
    v63 = *(_QWORD *)(v62 + 8 * v57);
    if ( v63 )
      v6 = (UFG::RoadNetworkLane *)(v62 + 8 * v57 + v63);
    if ( UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(v2, v6) )
    {
      UFG::RoadNetworkGuide::ChangeLane(v2, 1u);
      return 1;
    }
  }
  return 0;
}

// File Line: 598
// RVA: 0xD5EF0
signed __int64 __fastcall UFG::RoadNetworkGuide::GetChangeLaneIndex(UFG::RoadNetworkGuide *this, unsigned int direction)
{
  UFG::RoadNetworkLane *v2; // rdi
  _WORD *v3; // rax
  int v5; // ebx
  UFG::RoadNetworkLane *v6; // rcx

  v2 = this->m_CurrentLocation.m_CurrentLane;
  v3 = (_WORD *)v2->mNode.mOffset;
  if ( v2->mNode.mOffset )
    v3 = (_WORD *)((char *)v3 + (_QWORD)v2);
  if ( *v3 == 1 )
    return 0xFFFFFFFFi64;
  v5 = -1;
  v6 = this->m_CurrentLocation.m_CurrentLane;
  if ( direction == 1 )
    v5 = 1;
  if ( UFG::RoadNetworkLane::IsReversedInNode(v6) )
    v5 = -v5;
  return v5 + (unsigned int)v2->mLaneIndex;
}

// File Line: 620
// RVA: 0xE0CA0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkGuide::TryGetPossibleSharedDestination(UFG::RoadNetworkGuide *this, unsigned int laneIndex, unsigned int laneFlags)
{
  UFG::RoadNetworkGuide *v3; // r9
  UFG::RoadNetworkLane *v4; // rax
  __int64 v5; // rcx
  signed __int64 v6; // rax
  __int64 v7; // rcx
  signed __int64 v8; // rsi
  UFG::RoadNetworkLane *v9; // rax
  char *v10; // rax
  __int64 v11; // rcx
  signed __int64 v12; // rcx
  _QWORD *v13; // rdx
  char *v14; // rdi
  __int64 v15; // rax
  signed __int64 v16; // rbx
  int v17; // edx
  __int64 *v18; // rbx
  __int64 v19; // r9
  char *v20; // rcx
  char *v21; // r8
  char *v22; // rax
  __int64 v23; // rcx
  signed __int64 v24; // rax
  __int64 v25; // rcx
  signed __int64 v26; // r8
  UFG::qArray<unsigned long,0> laneIDs; // [rsp+28h] [rbp-20h]

  v3 = this;
  v4 = this->m_NextLane;
  if ( !v4 )
    return 0i64;
  v5 = v4->mEndGate.mOffset;
  v6 = (signed __int64)(v5 ? (UFG::qOffset64<UFG::RoadNetworkGate *> *)((char *)&v4->mEndGate + v5) : 0i64);
  v7 = *(_QWORD *)(v6 + 8);
  if ( !v7 )
    return 0i64;
  v8 = v7 + v6 + 8;
  if ( !v8 )
    return 0i64;
  v9 = v3->m_CurrentLocation.m_CurrentLane;
  if ( v9->mNode.mOffset )
    v10 = (char *)v9 + v9->mNode.mOffset;
  else
    v10 = 0i64;
  v11 = *((_QWORD *)v10 + 6);
  if ( v11 )
    v12 = (signed __int64)&v10[v11 + 48];
  else
    v12 = 0i64;
  v13 = (_QWORD *)(v12 + 8i64 * laneIndex);
  v14 = (char *)v13 + *v13;
  if ( !*v13 )
    v14 = 0i64;
  v15 = *((_QWORD *)v14 + 13);
  if ( !v15 )
    return 0i64;
  v16 = (signed __int64)&v14[v15 + 104];
  if ( !v16 )
    return 0i64;
  laneIDs.p = 0i64;
  *(_QWORD *)&laneIDs.size = 0i64;
  UFG::RoadNetworkConnection::GetValidLanes((UFG::RoadNetworkConnection *)&v14[v15 + 104], laneFlags, &laneIDs);
  v17 = 0;
  if ( laneIDs.size )
  {
    v18 = (__int64 *)(v16 + 8);
    v19 = *v18;
    while ( 1 )
    {
      v20 = (char *)v18 + v19;
      if ( !v19 )
        v20 = 0i64;
      v21 = &v20[8 * v17];
      v22 = *(_QWORD *)v21 ? &v21[*(_QWORD *)v21] : 0i64;
      v23 = *((_QWORD *)v22 + 2);
      v24 = (signed __int64)(v23 ? &v22[v23 + 16] : 0i64);
      v25 = *(_QWORD *)(v24 + 8);
      if ( v25 )
      {
        v26 = v25 + v24 + 8;
        if ( v26 )
        {
          if ( *(_DWORD *)(v26 + 24) == *(_DWORD *)(v8 + 24) )
            break;
        }
      }
      if ( ++v17 >= laneIDs.size )
        goto LABEL_31;
    }
  }
  else
  {
LABEL_31:
    v14 = 0i64;
  }
  if ( laneIDs.p )
    operator delete[](laneIDs.p);
  laneIDs.p = 0i64;
  *(_QWORD *)&laneIDs.size = 0i64;
  return (UFG::RoadNetworkLane *)v14;
}

// File Line: 650
// RVA: 0xD4D90
void __fastcall UFG::RoadNetworkGuide::FindNextGuide(UFG::RoadNetworkGuide *this)
{
  UFG::qSafePointer<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v1; // rsi
  UFG::RoadNetworkGuide *v2; // r14
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v4; // rax
  signed __int64 v5; // r15
  __int64 v6; // rcx
  float v7; // xmm13_4
  __int64 v8; // rax
  UFG::RoadNetworkConnection *v9; // rcx
  UFG::RoadNetworkLane *v10; // rax
  signed __int64 v11; // rbx
  float v12; // xmm12_4
  __int64 v13; // rax
  __int64 v14; // rcx
  unsigned int v15; // edx
  __int64 v16; // rax
  UFG::RoadNetworkConnection *v17; // rcx
  float v18; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v21; // rax
  __int64 v22; // rax
  unsigned int *v23; // r13
  __int64 v24; // r12
  __int64 v25; // rax
  signed __int64 v26; // rcx
  signed __int64 v27; // rax
  __int64 v28; // rcx
  signed __int64 v29; // r14
  signed __int64 v30; // rdi
  __int64 v31; // rcx
  __int64 v32; // rax
  unsigned int v33; // edx
  UFG::RoadNetworkConnection *v34; // rcx
  float v35; // xmm6_4
  __int64 v36; // rax
  float v37; // xmm7_4
  UFG::RoadNetworkConnection *v38; // rcx
  UFG::qBezierPathMemImaged *v39; // rax
  UFG::RoadNetworkConnection *v40; // rbx
  unsigned int v41; // eax
  UFG::qBezierSplineMemImaged *v42; // rax
  __int64 v43; // rax
  UFG::RoadNetworkConnection *v44; // rcx
  UFG::qBezierPathMemImaged *v45; // rax
  UFG::RoadNetworkConnection *v46; // rbx
  unsigned int v47; // eax
  UFG::qBezierSplineMemImaged *v48; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v49; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v50; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v51; // rax
  __int64 v52; // rax
  unsigned int *v53; // rcx
  __int64 v54; // r13
  __int64 v55; // rax
  signed __int64 v56; // rcx
  signed __int64 v57; // rax
  __int64 v58; // rcx
  signed __int64 v59; // r14
  signed __int64 v60; // rdi
  __int64 v61; // rcx
  __int64 v62; // rax
  unsigned int v63; // edx
  UFG::RoadNetworkConnection *v64; // rcx
  float v65; // xmm8_4
  __int64 v66; // rax
  float v67; // xmm9_4
  UFG::RoadNetworkConnection *v68; // rcx
  UFG::qBezierPathMemImaged *v69; // rax
  UFG::RoadNetworkConnection *v70; // rbx
  unsigned int v71; // eax
  UFG::qBezierSplineMemImaged *v72; // rcx
  float v73; // xmm6_4
  int v74; // xmm3_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  float v77; // xmm1_4
  UFG::qVector3 *v78; // rax
  float v79; // xmm2_4
  __int64 v80; // rax
  UFG::RoadNetworkConnection *v81; // rcx
  UFG::qBezierPathMemImaged *v82; // rax
  UFG::RoadNetworkConnection *v83; // rbx
  unsigned int v84; // eax
  UFG::qBezierSplineMemImaged *v85; // rcx
  float v86; // xmm6_4
  int v87; // xmm2_4
  float v88; // xmm1_4
  float v89; // xmm1_4
  float v90; // xmm4_4
  float v91; // xmm5_4
  float v92; // xmm3_4
  UFG::qVector3 *v93; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v94; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v95; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v96; // rax
  UFG::RoadNetworkLane *v97; // rax
  __int64 v98; // rcx
  signed __int64 v99; // rax
  unsigned int *v100; // r14
  __int64 v101; // rdi
  __int64 v102; // r15
  __int64 v103; // rax
  signed __int64 v104; // rcx
  signed __int64 v105; // rax
  __int64 v106; // rcx
  signed __int64 v107; // rbx
  signed __int64 v108; // rbx
  __int64 v109; // rax
  __int64 v110; // rcx
  unsigned int v111; // edx
  __int64 v112; // rax
  UFG::RoadNetworkConnection *v113; // rcx
  float v114; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v115; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v116; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v117; // rax
  unsigned int *v118; // [rsp+20h] [rbp-E0h]
  UFG::qVector3 position; // [rsp+28h] [rbp-D8h]
  UFG::qVector3 result; // [rsp+38h] [rbp-C8h]
  UFG::qVector3 tangent; // [rsp+48h] [rbp-B8h]
  UFG::qVector3 v122; // [rsp+58h] [rbp-A8h]
  UFG::qVector3 v123; // [rsp+68h] [rbp-98h]
  UFG::qVector3 v124; // [rsp+74h] [rbp-8Ch]
  UFG::RoadNetworkGuide *v125; // [rsp+160h] [rbp+60h]
  float splineT; // [rsp+168h] [rbp+68h]
  float t; // [rsp+170h] [rbp+70h]
  __int64 v128; // [rsp+178h] [rbp+78h]

  v125 = this;
  v1 = &this->m_NextGuide;
  v2 = this;
  if ( this->m_NextGuide.m_pPointer )
  {
    v3 = v1->mPrev;
    v4 = this->m_NextGuide.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->m_NextGuide.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&this->m_NextGuide.mPrev;
  }
  this->m_NextGuide.m_pPointer = 0i64;
  v5 = (signed __int64)this->m_CurrentLocation.m_CurrentLane;
  if ( v5 )
  {
    v6 = *(_QWORD *)v5;
    v7 = FLOAT_3_4028235e38;
    if ( *(_QWORD *)v5 )
      v6 += v5;
    v8 = *(_QWORD *)(v6 + 32);
    if ( v8 )
      v9 = (UFG::RoadNetworkConnection *)(v8 + v6 + 32);
    else
      v9 = 0i64;
    v10 = UFG::qBezierPathCollectionMemImaged::GetPath(v9, *(unsigned __int16 *)(v5 + 38));
    v11 = *(_QWORD *)(v5 + 120) - 24i64;
    v12 = *((float *)&v10->mNode.mOffset + 1) * v2->m_CurrentLocation.m_LaneT;
    if ( v11 != v5 + 88 )
    {
      while ( 1 )
      {
        if ( (UFG::RoadNetworkGuide *)v11 != v2 )
        {
          v13 = *(_QWORD *)(v11 + 64);
          v14 = *(_QWORD *)v13;
          if ( *(_QWORD *)v13 )
            v14 += v13;
          v15 = *(unsigned __int16 *)(v13 + 38);
          v16 = *(_QWORD *)(v14 + 32);
          v17 = (UFG::RoadNetworkConnection *)(v16 ? v16 + v14 + 32 : 0i64);
          v18 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v17, v15)->mNode.mOffset + 1)
              * *(float *)(v11 + 56);
          if ( v18 > v12 )
            break;
        }
        v11 = *(_QWORD *)(v11 + 32) - 24i64;
        if ( v11 == v5 + 88 )
          goto LABEL_24;
      }
      if ( v1->m_pPointer )
      {
        v19 = v1->mPrev;
        v20 = v1->mNext;
        v19->mNext = v20;
        v20->mPrev = v19;
        v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
        v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
      }
      v1->m_pPointer = (UFG::RoadNetworkGuide *)v11;
      if ( v11 )
      {
        v21 = *(UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> **)(v11 + 8);
        v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
        v1->mPrev = v21;
        v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)(v11 + 8);
        *(_QWORD *)(v11 + 8) = v1;
      }
      v7 = v18;
    }
LABEL_24:
    v22 = *(_QWORD *)(v5 + 88);
    if ( v22 )
      v23 = (unsigned int *)(v22 + v5 + 88);
    else
      v23 = 0i64;
    if ( *v23 )
    {
      v24 = 0i64;
      v128 = *v23;
      do
      {
        v25 = *((_QWORD *)v23 + 1);
        if ( v25 )
          v26 = (signed __int64)v23 + v25 + 8;
        else
          v26 = 0i64;
        v27 = v24 + v26;
        v28 = *(_QWORD *)(v24 + v26);
        if ( v28 )
          v29 = v28 + v27;
        else
          v29 = 0i64;
        if ( v5 != v29 )
        {
          v30 = *(_QWORD *)(v29 + 120) - 24i64;
          if ( v30 != v29 + 88 )
          {
            while ( 1 )
            {
              v31 = *(_QWORD *)(v30 + 64);
              v32 = *(_QWORD *)v31;
              if ( *(_QWORD *)v31 )
                v32 += v31;
              v33 = *(unsigned __int16 *)(v31 + 38);
              v34 = *(UFG::RoadNetworkConnection **)(v32 + 32);
              if ( v34 )
                v34 = (UFG::RoadNetworkConnection *)((char *)v34 + v32 + 32);
              v35 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v34, v33)->mNode.mOffset + 1)
                  * *(float *)(v30 + 56);
              if ( v35 > v12 )
                break;
              v30 = *(_QWORD *)(v30 + 32) - 24i64;
              if ( v30 == v29 + 88 )
                goto LABEL_57;
            }
            v36 = *(_QWORD *)v29;
            v37 = *(float *)(v30 + 56);
            if ( *(_QWORD *)v29 )
              v36 += v29;
            v38 = *(UFG::RoadNetworkConnection **)(v36 + 32);
            if ( v38 )
              v38 = (UFG::RoadNetworkConnection *)((char *)v38 + v36 + 32);
            v39 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                 v38,
                                                 *(unsigned __int16 *)(v29 + 38));
            v40 = (UFG::RoadNetworkConnection *)v39;
            v41 = UFG::qBezierPathMemImaged::GetSplineParameters(v39, v37, &splineT);
            v42 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v40, v41);
            UFG::RoadNetworkLane::GetOffsetPos(&result, v42, splineT, *(float *)(v29 + 40));
            v43 = *(_QWORD *)v5;
            if ( *(_QWORD *)v5 )
              v43 += v5;
            v44 = *(UFG::RoadNetworkConnection **)(v43 + 32);
            if ( v44 )
              v44 = (UFG::RoadNetworkConnection *)((char *)v44 + v43 + 32);
            v45 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                 v44,
                                                 *(unsigned __int16 *)(v5 + 38));
            v46 = (UFG::RoadNetworkConnection *)v45;
            v47 = UFG::qBezierPathMemImaged::GetSplineParameters(v45, v37, &t);
            v48 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v46, v47);
            UFG::RoadNetworkLane::GetOffsetPos(&position, v48, t, *(float *)(v5 + 40));
            if ( (float)((float)((float)((float)(result.y - position.y) * (float)(result.y - position.y))
                               + (float)((float)(result.x - position.x) * (float)(result.x - position.x)))
                       + (float)((float)(result.z - position.z) * (float)(result.z - position.z))) < 10.240001
              && v35 < v7 )
            {
              if ( v1->m_pPointer )
              {
                v49 = v1->mPrev;
                v50 = v1->mNext;
                v49->mNext = v50;
                v50->mPrev = v49;
                v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
                v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
              }
              v1->m_pPointer = (UFG::RoadNetworkGuide *)v30;
              v51 = *(UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> **)(v30 + 8);
              v7 = v35;
              v51->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
              v1->mPrev = v51;
              v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)(v30 + 8);
              *(_QWORD *)(v30 + 8) = v1;
            }
          }
        }
LABEL_57:
        v24 += 8i64;
        --v128;
      }
      while ( v128 );
    }
    v52 = *(_QWORD *)(v5 + 96);
    if ( v52 )
      v53 = (unsigned int *)(v52 + v5 + 96);
    else
      v53 = 0i64;
    v118 = v53;
    if ( *v53 )
    {
      v54 = 0i64;
      v128 = *v53;
      do
      {
        v55 = *((_QWORD *)v53 + 1);
        if ( v55 )
          v56 = (signed __int64)v53 + v55 + 8;
        else
          v56 = 0i64;
        v57 = v56 + v54;
        v58 = *(_QWORD *)(v56 + v54);
        if ( v58 )
          v59 = v58 + v57;
        else
          v59 = 0i64;
        if ( v5 != v59 )
        {
          v60 = *(_QWORD *)(v59 + 120) - 24i64;
          if ( v60 != v59 + 88 )
          {
            while ( 1 )
            {
              v61 = *(_QWORD *)(v60 + 64);
              v62 = *(_QWORD *)v61;
              if ( *(_QWORD *)v61 )
                v62 += v61;
              v63 = *(unsigned __int16 *)(v61 + 38);
              v64 = *(UFG::RoadNetworkConnection **)(v62 + 32);
              if ( v64 )
                v64 = (UFG::RoadNetworkConnection *)((char *)v64 + v62 + 32);
              v65 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v64, v63)->mNode.mOffset + 1)
                  * *(float *)(v60 + 56);
              if ( v65 > v12 )
              {
                v66 = *(_QWORD *)v59;
                v67 = *(float *)(v60 + 56);
                if ( *(_QWORD *)v59 )
                  v66 += v59;
                v68 = *(UFG::RoadNetworkConnection **)(v66 + 32);
                if ( v68 )
                  v68 = (UFG::RoadNetworkConnection *)((char *)v68 + v66 + 32);
                v69 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                     v68,
                                                     *(unsigned __int16 *)(v59 + 38));
                v70 = (UFG::RoadNetworkConnection *)v69;
                v71 = UFG::qBezierPathMemImaged::GetSplineParameters(v69, v67, &splineT);
                v72 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v70, v71);
                v73 = *(float *)(v59 + 40);
                if ( v73 == 0.0 )
                {
                  v78 = UFG::qBezierSplineMemImaged::GetPosition(v72, &v123, splineT);
                  v79 = v78->z;
                  v77 = v78->y;
                  position.x = v78->x;
                  position.z = v79;
                }
                else
                {
                  UFG::qBezierSplineMemImaged::GetPositionAndTangent(v72, splineT, &position, &tangent);
                  v74 = LODWORD(tangent.x) ^ _xmm[0];
                  v75 = (float)(*(float *)&v74 * *(float *)&v74) + (float)(tangent.y * tangent.y);
                  if ( v75 == 0.0 )
                    v76 = 0.0;
                  else
                    v76 = 1.0 / fsqrt(v75);
                  position.x = position.x + (float)((float)(v76 * tangent.y) * v73);
                  v77 = position.y + (float)((float)(*(float *)&v74 * v76) * v73);
                  position.z = position.z + (float)((float)(v76 * 0.0) * v73);
                }
                v80 = *(_QWORD *)v5;
                position.y = v77;
                if ( v80 )
                  v80 += v5;
                v81 = *(UFG::RoadNetworkConnection **)(v80 + 32);
                if ( v81 )
                  v81 = (UFG::RoadNetworkConnection *)((char *)v81 + v80 + 32);
                v82 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                     v81,
                                                     *(unsigned __int16 *)(v5 + 38));
                v83 = (UFG::RoadNetworkConnection *)v82;
                v84 = UFG::qBezierPathMemImaged::GetSplineParameters(v82, v67, &t);
                v85 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v83, v84);
                v86 = *(float *)(v5 + 40);
                if ( v86 == 0.0 )
                {
                  v93 = UFG::qBezierSplineMemImaged::GetPosition(v85, &v124, t);
                  v90 = v93->y;
                  v91 = v93->z;
                  v92 = v93->x;
                }
                else
                {
                  UFG::qBezierSplineMemImaged::GetPositionAndTangent(v85, t, &result, &v122);
                  v87 = LODWORD(v122.x) ^ _xmm[0];
                  v88 = (float)(*(float *)&v87 * *(float *)&v87) + (float)(v122.y * v122.y);
                  v89 = v88 == 0.0 ? 0.0 : 1.0 / fsqrt(v88);
                  v90 = result.y + (float)((float)(*(float *)&v87 * v89) * v86);
                  v91 = result.z + (float)((float)(v89 * 0.0) * v86);
                  v92 = result.x + (float)((float)(v89 * v122.y) * v86);
                }
                result.z = v91;
                result.y = v90;
                result.x = v92;
                if ( (float)((float)((float)((float)(position.x - v92) * (float)(position.x - v92))
                                   + (float)((float)(position.y - v90) * (float)(position.y - v90)))
                           + (float)((float)(position.z - v91) * (float)(position.z - v91))) < 10.240001 )
                  break;
              }
              v60 = *(_QWORD *)(v60 + 32) - 24i64;
              if ( v60 == v59 + 88 )
                goto LABEL_103;
            }
            if ( v65 < v7 )
            {
              if ( v1->m_pPointer )
              {
                v94 = v1->mPrev;
                v95 = v1->mNext;
                v94->mNext = v95;
                v95->mPrev = v94;
                v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
                v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
              }
              v1->m_pPointer = (UFG::RoadNetworkGuide *)v60;
              v96 = *(UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> **)(v60 + 8);
              v7 = v65;
              v96->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
              v1->mPrev = v96;
              v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)(v60 + 8);
              *(_QWORD *)(v60 + 8) = v1;
            }
          }
        }
LABEL_103:
        v53 = v118;
        v54 += 8i64;
        --v128;
      }
      while ( v128 );
    }
    if ( !v125->m_NextGuide.m_pPointer )
    {
      v97 = v125->m_CurrentLocation.m_CurrentLane;
      v98 = v97->mNextConnection.mOffset;
      v99 = (signed __int64)&v97->mNextConnection;
      if ( v98 )
      {
        v100 = (unsigned int *)(v98 + v99);
        if ( v98 + v99 )
        {
          if ( *v100 )
          {
            v101 = 0i64;
            v102 = *v100;
            do
            {
              v103 = *((_QWORD *)v100 + 1);
              if ( v103 )
                v104 = (signed __int64)v100 + v103 + 8;
              else
                v104 = 0i64;
              v105 = v101 + v104;
              v106 = *(_QWORD *)(v101 + v104);
              if ( v106 )
                v107 = v106 + v105;
              else
                v107 = 0i64;
              if ( *(_QWORD *)(v107 + 120) - 24i64 != v107 + 88 )
              {
                v108 = *(_QWORD *)(v107 + 120) - 24i64;
                if ( v108 )
                {
                  v109 = *(_QWORD *)(v108 + 64);
                  v110 = *(_QWORD *)v109;
                  if ( *(_QWORD *)v109 )
                    v110 += v109;
                  v111 = *(unsigned __int16 *)(v109 + 38);
                  v112 = *(_QWORD *)(v110 + 32);
                  if ( v112 )
                    v113 = (UFG::RoadNetworkConnection *)(v112 + v110 + 32);
                  else
                    v113 = 0i64;
                  v114 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v113, v111)->mNode.mOffset + 1)
                       * *(float *)(v108 + 56);
                  if ( v114 < v7 )
                  {
                    if ( v1->m_pPointer )
                    {
                      v115 = v1->mPrev;
                      v116 = v1->mNext;
                      v115->mNext = v116;
                      v116->mPrev = v115;
                      v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
                      v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
                    }
                    v1->m_pPointer = (UFG::RoadNetworkGuide *)v108;
                    v117 = *(UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> **)(v108 + 8);
                    v7 = v114;
                    v117->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)&v1->mPrev;
                    v1->mPrev = v117;
                    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)(v108 + 8);
                    *(_QWORD *)(v108 + 8) = v1;
                  }
                }
              }
              v101 += 8i64;
              --v102;
            }
            while ( v102 );
          }
        }
      }
    }
  }
}

// File Line: 771
// RVA: 0xDF310
bool __fastcall UFG::RoadNetworkGuide::LaneChangeAvailable(UFG::RoadNetworkGuide *this, unsigned int *whichLanes)
{
  char *v2; // rax
  UFG::RoadNetworkGuide *v3; // r10
  UFG::RoadNetworkLane *v4; // r8
  char *v5; // rcx
  UFG::RoadNetworkLane *v6; // r9
  bool result; // al

  v2 = 0i64;
  v3 = this;
  if ( whichLanes )
    *whichLanes = 0;
  v4 = this->m_CurrentLocation.m_CurrentLane;
  v5 = (char *)v4 + v4->mNode.mOffset;
  if ( !v4->mNode.mOffset )
    v5 = 0i64;
  v6 = v3->m_TargetLocation.m_CurrentLane;
  if ( v6->mNode.mOffset )
    v2 = (char *)v6 + v6->mNode.mOffset;
  if ( v5 == v2 )
    result = UFG::RoadNetworkLane::LaneChangeAvailable(v4, whichLanes);
  else
    result = 0;
  return result;
}

// File Line: 787
// RVA: 0xD8270
void __fastcall UFG::RoadNetworkGuide::GetCornerRays(UFG::RoadNetworkGuide *this, UFG::qVector3 *corners, UFG::qVector3 *p_left)
{
  UFG::RoadNetworkLane *v3; // rax
  UFG::qVector3 *v4; // rsi
  UFG::qVector3 *v5; // rbp
  UFG::RoadNetworkGuide *v6; // rdi
  float v7; // xmm15_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  __m128 v10; // xmm13
  UFG::RoadNetworkLane *v11; // rax
  UFG::RoadNetworkConnection *v12; // r8
  char *v13; // rcx
  __int64 v14; // r9
  __int64 v15; // rax
  float v16; // xmm8_4
  signed __int64 v17; // rdx
  __int64 v18; // rax
  signed __int64 v19; // r9
  signed __int64 v20; // rax
  unsigned int v21; // edx
  __int64 v22; // rax
  UFG::qBezierPathMemImaged *v23; // rax
  UFG::RoadNetworkConnection *v24; // rbx
  unsigned int v25; // eax
  UFG::qBezierSplineMemImaged *v26; // rax
  __m128 v27; // xmm10
  __m128 v28; // xmm2
  float v29; // xmm1_4
  float v30; // xmm14_4
  __m128 v31; // xmm9
  float v32; // xmm12_4
  __m128 v33; // xmm2
  float v34; // xmm7_4
  float v35; // xmm14_4
  float v36; // xmm9_4
  int v37; // xmm0_4
  float v38; // xmm12_4
  float v39; // xmm8_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm0_4
  float v43; // xmm10_4
  float v44; // xmm11_4
  float v45; // xmm13_4
  UFG::qVector3 result; // [rsp+20h] [rbp-B8h]
  float splineT; // [rsp+E0h] [rbp+8h]

  v3 = this->m_CurrentLocation.m_CurrentLane;
  v4 = p_left;
  v5 = corners;
  v6 = this;
  v7 = this->m_ObjectWidth * 0.5;
  v8 = *(float *)&FLOAT_1_0;
  v9 = 0.0;
  v10 = 0i64;
  if ( v3 && v3->mNode.mOffset && (UFG::RoadNetworkLane *)((char *)v3 + v3->mNode.mOffset) )
  {
    v11 = this->m_CurrentLocation.m_CurrentLane;
    v12 = 0i64;
    if ( v11->mNode.mOffset )
      v13 = (char *)v11 + v11->mNode.mOffset;
    else
      v13 = 0i64;
    v14 = v11->mLaneIndex;
    v15 = *((_QWORD *)v13 + 6);
    v16 = v6->m_CurrentLocation.m_LaneT;
    if ( v15 )
      v17 = (signed __int64)&v13[v15 + 48];
    else
      v17 = 0i64;
    v18 = *(_QWORD *)(v17 + 8 * v14);
    v19 = v17 + 8 * v14;
    if ( v18 )
      v20 = v19 + v18;
    else
      v20 = 0i64;
    v21 = *(unsigned __int16 *)(v20 + 38);
    v22 = *((_QWORD *)v13 + 4);
    if ( v22 )
      v12 = (UFG::RoadNetworkConnection *)&v13[v22 + 32];
    v23 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v12, v21);
    splineT = 0.0;
    v24 = (UFG::RoadNetworkConnection *)v23;
    v25 = UFG::qBezierPathMemImaged::GetSplineParameters(v23, v16, &splineT);
    v26 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v24, v25);
    UFG::qBezierSplineMemImaged::GetTangent(v26, &result, splineT);
    v27 = (__m128)LODWORD(result.x);
    v10 = (__m128)LODWORD(result.z);
    v28 = v27;
    v28.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(result.y * result.y))
                    + (float)(v10.m128_f32[0] * v10.m128_f32[0]);
    if ( v28.m128_f32[0] == 0.0 )
      v29 = 0.0;
    else
      v29 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
    v8 = result.x * v29;
    v9 = result.y * v29;
    v10.m128_f32[0] = result.z * v29;
  }
  v31 = v10;
  v30 = v9 - (float)(v10.m128_f32[0] * 0.0);
  v31.m128_f32[0] = (float)(v10.m128_f32[0] * 0.0) - v8;
  v33 = v31;
  v32 = (float)(v8 * 0.0) - (float)(v9 * 0.0);
  v33.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30)) + (float)(v32 * v32);
  if ( v33.m128_f32[0] == 0.0 )
    v34 = 0.0;
  else
    v34 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v33));
  v35 = v30 * v34;
  v36 = v31.m128_f32[0] * v34;
  v37 = LODWORD(v6->m_RearBoundary) ^ _xmm[0];
  v38 = v32 * v34;
  v39 = v8 * *(float *)&v37;
  v40 = v9 * *(float *)&v37;
  v41 = v10.m128_f32[0] * *(float *)&v37;
  v42 = v6->m_FrontBoundary;
  v43 = v8 * v42;
  v44 = v9 * v42;
  v45 = v10.m128_f32[0] * v42;
  v5->x = (float)(v35 * v7) + v43;
  v5->y = (float)(v36 * v7) + v44;
  v5->z = (float)(v38 * v7) + v45;
  v5[1].x = v43 - (float)(v35 * v7);
  v5[1].y = v44 - (float)(v36 * v7);
  v5[1].z = v45 - (float)(v38 * v7);
  v5[2].x = (float)(v35 * v7) + v39;
  v5[2].y = (float)(v36 * v7) + v40;
  v5[2].z = (float)(v38 * v7) + v41;
  v5[3].x = v39 - (float)(v35 * v7);
  v5[3].y = v40 - (float)(v36 * v7);
  v5[3].z = v41 - (float)(v38 * v7);
  if ( v4 )
  {
    v4->x = v35;
    v4->y = v36;
    v4->z = v38;
  }
}

// File Line: 814
// RVA: 0xD8AD0
float __fastcall UFG::RoadNetworkGuide::GetGap(UFG::RoadNetworkGuide *this, UFG::RoadNetworkGuide *otherGuide)
{
  float v2; // xmm6_4
  UFG::RoadNetworkGuide *v3; // rbx
  __m128 v4; // xmm7
  float v5; // xmm8_4
  __m128 v6; // xmm2
  float v7; // xmm11_4
  float v9; // xmm12_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm10_4
  float v13; // xmm9_4
  float v14; // xmm8_4
  float v15; // xmm11_4
  UFG::qVector3 p_left; // [rsp+20h] [rbp-81h]
  float v17; // [rsp+2Ch] [rbp-75h]
  float v18; // [rsp+30h] [rbp-71h]
  float v19; // [rsp+34h] [rbp-6Dh]
  float v20; // [rsp+38h] [rbp-69h]
  float v21; // [rsp+3Ch] [rbp-65h]
  float v22; // [rsp+40h] [rbp-61h]
  float v23; // [rsp+44h] [rbp-5Dh]
  float v24; // [rsp+48h] [rbp-59h]
  float v25; // [rsp+4Ch] [rbp-55h]
  float v26; // [rsp+50h] [rbp-51h]
  float v27; // [rsp+54h] [rbp-4Dh]
  UFG::qVector3 corners; // [rsp+58h] [rbp-49h]
  float v29; // [rsp+64h] [rbp-3Dh]
  float v30; // [rsp+68h] [rbp-39h]
  float v31; // [rsp+6Ch] [rbp-35h]
  float v32; // [rsp+70h] [rbp-31h]
  float v33; // [rsp+74h] [rbp-2Dh]
  float v34; // [rsp+78h] [rbp-29h]
  float v35; // [rsp+7Ch] [rbp-25h]
  float v36; // [rsp+80h] [rbp-21h]
  float v37; // [rsp+84h] [rbp-1Dh]

  v4 = (__m128)LODWORD(otherGuide->m_Position.y);
  v2 = otherGuide->m_Position.x - this->m_Position.x;
  v3 = otherGuide;
  v4.m128_f32[0] = v4.m128_f32[0] - this->m_Position.y;
  v5 = otherGuide->m_Position.z - this->m_Position.z;
  v6 = v4;
  v6.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v2 * v2)) + (float)(v5 * v5);
  LODWORD(v7) = (unsigned __int128)_mm_sqrt_ps(v6);
  if ( v7 < 0.1 )
    return 0.0;
  v9 = 0.0;
  v10 = v2 * (float)(1.0 / v7);
  v11 = v4.m128_f32[0] * (float)(1.0 / v7);
  v12 = 0.0;
  v13 = 0.0;
  v14 = v5 * (float)(1.0 / v7);
  UFG::RoadNetworkGuide::GetCornerRays(this, (UFG::qVector3 *)((char *)&p_left + 8), &p_left);
  UFG::RoadNetworkGuide::GetCornerRays(v3, &corners, 0i64);
  if ( (float)((float)((float)(v17 * v11) + (float)(p_left.z * v10)) + (float)(v18 * v14)) >= 0.0 )
    v12 = (float)((float)(v17 * v11) + (float)(p_left.z * v10)) + (float)(v18 * v14);
  if ( (float)((float)((float)(corners.y * v11) + (float)(corners.x * v10)) + (float)(corners.z * v14)) <= 0.0 )
    v13 = (float)((float)(corners.y * v11) + (float)(corners.x * v10)) + (float)(corners.z * v14);
  if ( v12 <= (float)((float)((float)(v20 * v11) + (float)(v19 * v10)) + (float)(v21 * v14)) )
    v12 = (float)((float)(v20 * v11) + (float)(v19 * v10)) + (float)(v21 * v14);
  if ( v13 >= (float)((float)((float)(v30 * v11) + (float)(v29 * v10)) + (float)(v31 * v14)) )
    v13 = (float)((float)(v30 * v11) + (float)(v29 * v10)) + (float)(v31 * v14);
  if ( v12 <= (float)((float)((float)(v23 * v11) + (float)(v22 * v10)) + (float)(v24 * v14)) )
    v12 = (float)((float)(v23 * v11) + (float)(v22 * v10)) + (float)(v24 * v14);
  if ( v13 >= (float)((float)((float)(v33 * v11) + (float)(v32 * v10)) + (float)(v34 * v14)) )
    v13 = (float)((float)(v33 * v11) + (float)(v32 * v10)) + (float)(v34 * v14);
  if ( v12 <= (float)((float)((float)(v26 * v11) + (float)(v25 * v10)) + (float)(v27 * v14)) )
    v12 = (float)((float)(v26 * v11) + (float)(v25 * v10)) + (float)(v27 * v14);
  if ( v13 >= (float)((float)((float)(v36 * v11) + (float)(v35 * v10)) + (float)(v37 * v14)) )
    v13 = (float)((float)(v36 * v11) + (float)(v35 * v10)) + (float)(v37 * v14);
  v15 = (float)(v7 - v12) + v13;
  if ( v15 >= 0.0 )
    v9 = v15;
  return v9;
}

// File Line: 850
// RVA: 0xE1300
void __fastcall UFG::RoadNetworkGuide::UpdateCurvature(UFG::RoadNetworkGuide *this)
{
  UFG::RoadNetworkGuide *v1; // r14
  UFG::RoadNetworkLane *rcx1; // rcx
  UFG::RoadNetworkConnection *v3; // rdi
  char *v4; // rax
  __int64 v5; // rdx
  __int64 v6; // rcx
  float v7; // xmm6_4
  signed __int64 v8; // rcx
  __int64 v9; // rax
  signed __int64 v10; // rsi
  signed __int64 v11; // rax
  __int64 v12; // rcx
  UFG::RoadNetworkConnection *v13; // rcx
  UFG::qBezierPathMemImaged *v14; // rax
  UFG::RoadNetworkConnection *v15; // rbx
  unsigned int v16; // eax
  UFG::qBezierSplineMemImaged *v17; // rax
  float v18; // xmm8_4
  float v19; // xmm7_4
  int v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  UFG::RoadNetworkLane *v23; // rcx
  char *v24; // rax
  __int64 v25; // rdx
  __int64 v26; // rcx
  float v27; // xmm8_4
  signed __int64 v28; // rcx
  __int64 v29; // rax
  signed __int64 v30; // rsi
  signed __int64 v31; // rax
  __int64 v32; // rcx
  UFG::qBezierPathMemImaged *v33; // rax
  UFG::RoadNetworkConnection *v34; // rbx
  unsigned int v35; // eax
  UFG::qBezierSplineMemImaged *v36; // rax
  float v37; // xmm8_4
  int v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm6_4
  float v47; // xmm0_4
  UFG::qVector3 v48; // [rsp+8h] [rbp-39h]
  UFG::qVector3 position; // [rsp+18h] [rbp-29h]
  UFG::qVector3 tangent; // [rsp+28h] [rbp-19h]
  UFG::qVector3 v2; // [rsp+38h] [rbp-9h]
  UFG::qVector3 v52; // [rsp+48h] [rbp+7h]
  float splineT; // [rsp+A8h] [rbp+67h]

  v1 = this;
  rcx1 = this->m_CurrentLocation.m_CurrentLane;
  v3 = 0i64;
  if ( rcx1->mNode.mOffset )
    v4 = (char *)rcx1 + rcx1->mNode.mOffset;
  else
    v4 = 0i64;
  v5 = rcx1->mLaneIndex;
  v6 = *((_QWORD *)v4 + 6);
  v7 = v1->m_CurrentLocation.m_LaneT;
  if ( v6 )
    v8 = (signed __int64)&v4[v6 + 48];
  else
    v8 = 0i64;
  v9 = *(_QWORD *)(v8 + 8 * v5);
  v10 = v9 + v8 + 8 * v5;
  if ( !v9 )
    v10 = 0i64;
  if ( *(_QWORD *)v10 )
    v11 = v10 + *(_QWORD *)v10;
  else
    v11 = 0i64;
  v12 = *(_QWORD *)(v11 + 32);
  if ( v12 )
    v13 = (UFG::RoadNetworkConnection *)(v11 + v12 + 32);
  else
    v13 = 0i64;
  v14 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v13, *(unsigned __int16 *)(v10 + 38));
  v15 = (UFG::RoadNetworkConnection *)v14;
  v16 = UFG::qBezierPathMemImaged::GetSplineParameters(v14, v7, &splineT);
  v17 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v15, v16);
  v18 = *(float *)(v10 + 40);
  UFG::qBezierSplineMemImaged::GetPositionAndTangent(v17, splineT, &position, &tangent);
  v19 = *(float *)&FLOAT_1_0;
  if ( v18 != 0.0 )
  {
    v20 = LODWORD(tangent.x) ^ _xmm[0];
    v21 = (float)(*(float *)&v20 * *(float *)&v20) + (float)(tangent.y * tangent.y);
    if ( v21 == 0.0 )
      v22 = 0.0;
    else
      v22 = 1.0 / fsqrt(v21);
    position.x = position.x + (float)((float)(v22 * tangent.y) * v18);
    position.y = position.y + (float)((float)(*(float *)&v20 * v22) * v18);
    position.z = position.z + (float)((float)(v22 * 0.0) * v18);
  }
  v23 = v1->m_TargetLocation.m_CurrentLane;
  if ( v23->mNode.mOffset )
    v24 = (char *)v23 + v23->mNode.mOffset;
  else
    v24 = 0i64;
  v25 = v23->mLaneIndex;
  v26 = *((_QWORD *)v24 + 6);
  v27 = v1->m_TargetLocation.m_LaneT;
  if ( v26 )
    v28 = (signed __int64)&v24[v26 + 48];
  else
    v28 = 0i64;
  v29 = *(_QWORD *)(v28 + 8 * v25);
  v30 = v29 + v28 + 8 * v25;
  if ( !v29 )
    v30 = 0i64;
  if ( *(_QWORD *)v30 )
    v31 = v30 + *(_QWORD *)v30;
  else
    v31 = 0i64;
  v32 = *(_QWORD *)(v31 + 32);
  if ( v32 )
    v3 = (UFG::RoadNetworkConnection *)(v32 + v31 + 32);
  v33 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v3, *(unsigned __int16 *)(v30 + 38));
  v34 = (UFG::RoadNetworkConnection *)v33;
  v35 = UFG::qBezierPathMemImaged::GetSplineParameters(v33, v27, &splineT);
  v36 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v34, v35);
  v37 = *(float *)(v30 + 40);
  UFG::qBezierSplineMemImaged::GetPositionAndTangent(v36, splineT, &v48, &v52);
  if ( v37 == 0.0 )
  {
    v45 = v48.z;
    v44 = v48.y;
    v41 = v48.x;
  }
  else
  {
    v38 = LODWORD(v52.x) ^ _xmm[0];
    v39 = (float)(*(float *)&v38 * *(float *)&v38) + (float)(v52.y * v52.y);
    if ( v39 == 0.0 )
      v40 = 0.0;
    else
      v40 = 1.0 / fsqrt(v39);
    v41 = v48.x + (float)((float)(v52.y * v40) * v37);
    v48.x = v48.x + (float)((float)(v52.y * v40) * v37);
    v42 = (float)(*(float *)&v38 * v40) * v37;
    v43 = (float)(v40 * 0.0) * v37;
    v44 = v48.y + v42;
    v45 = v48.z + v43;
    v48.y = v48.y + v42;
    v48.z = v48.z + v43;
  }
  v2.x = v41 - position.x;
  v2.y = v44 - position.y;
  v2.z = v45 - position.z;
  v46 = UFG::qAngleBetween(&tangent, &v2);
  v47 = UFG::qAngleBetween(&tangent, &v52);
  if ( (float)(v1->m_AdvanceDistance - v1->m_FrontBoundary) >= 1.0 )
    v19 = v1->m_AdvanceDistance - v1->m_FrontBoundary;
  if ( v46 <= v47 )
    v46 = v47;
  v1->m_Curvature = v46 / v19;
}

// File Line: 863
// RVA: 0xE0E20
void __fastcall UFG::RoadNetworkGuide::Update(UFG::RoadNetworkGuide *this, UFG::qVector3 *newPos)
{
  UFG::RoadNetworkGuide *v2; // rbx
  UFG::RoadNetworkLane *v3; // rax
  float *v4; // rsi
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::RoadNetworkLane *v8; // r9
  UFG::RoadNetworkLane *v9; // r8
  float v10; // xmm1_4
  _QWORD *v11; // rcx
  UFG::RoadNetworkLane *v12; // r9
  float *v13; // r8
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v14; // rcx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v15; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v16; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v17; // rax
  UFG::RoadNetworkGuide *v18; // rdx

  v2 = this;
  if ( !this->m_Parked )
  {
    v3 = this->m_CurrentLocation.m_CurrentLane;
    if ( v3 )
    {
      if ( v3->mNode.mOffset )
        v4 = (float *)((char *)v3 + v3->mNode.mOffset);
      else
        v4 = 0i64;
      v5 = newPos->y;
      v6 = newPos->z;
      this->m_Position.x = newPos->x;
      this->m_Position.y = v5;
      this->m_Position.z = v6;
      if ( this->m_CurrentLocation.m_CurrentLane )
      {
        v7 = UFG::RoadNetworkLocation::FindLaneTWithCustomSearch(&this->m_CurrentLocation, newPos, this->m_NextLane);
        if ( v2->m_CurrentLocation.m_CurrentLane )
          v2->m_CurrentLocation.m_LaneT = v7;
      }
      v8 = v2->m_LaneAfterNext;
      v9 = v2->m_NextLane;
      v10 = v2->m_AdvanceDistance;
      v11 = (_QWORD *)&v2->m_TargetLocation.m_LaneT;
      *v11 = *(_QWORD *)&v2->m_CurrentLocation.m_LaneT;
      v11[1] = v2->m_CurrentLocation.m_CurrentLane;
      UFG::RoadNetworkLocation::Advance(&v2->m_TargetLocation, v10, v9, v8);
      UFG::RoadNetworkGuide::UpdateCurvature(v2);
      v12 = v2->m_CurrentLocation.m_CurrentLane;
      if ( !v12 )
        v2->m_Attached = 0;
      if ( v12->mNode.mOffset )
        v13 = (float *)((char *)v12 + v12->mNode.mOffset);
      else
        v13 = 0i64;
      if ( !v12 || v13 != v4 )
      {
        v2->m_NextLane = 0i64;
        v14 = v2->mPrev;
        v15 = v2->mNext;
        v16 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)&v2->mPrev;
        v14->mNext = v15;
        v15->mPrev = v14;
        v16->mPrev = v16;
        v16->mNext = v16;
        if ( v12 )
        {
          v16->mPrev = v16;
          v2->mNext = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)&v2->mPrev;
          v17 = v12->mCars.mNode.mNext;
          v12->mCars.mNode.mNext = v16;
          v2->mNext = v17;
          v16->mPrev = &v12->mCars.mNode;
          v17->mPrev = v16;
        }
        if ( !*(_WORD *)v13 )
          v2->m_SpeedLimit = v13[41];
      }
      UFG::RoadNetworkGuide::FindNextGuide(v2);
      v18 = v2->m_NextGuide.m_pPointer;
      v2->m_NextGuideDistance = 3.4028235e38;
      if ( v18 )
        v2->m_NextGuideDistance = UFG::RoadNetworkGuide::GetGap(v2, v18);
      UFG::RoadNetworkGuide::UpdateStopPointDistance(v2);
    }
  }
}

// File Line: 923
// RVA: 0xDDCE0
char __fastcall UFG::RoadNetworkGuide::IsBlockedInOpposingLanes(UFG::RoadNetworkGuide *this, UFG::RoadNetworkLane *roadLane)
{
  UFG::RoadNetworkLane *v2; // rdi
  UFG::RoadNetworkGuide *v3; // rbx
  bool v4; // al
  UFG::RoadNetworkLane *v5; // r8
  bool v6; // r9
  float v7; // xmm11_4
  __int64 v8; // rcx
  __int64 v9; // rax
  unsigned int v10; // edx
  UFG::RoadNetworkLane *v11; // rax
  float v12; // xmm0_4
  UFG::RoadNetworkLane *v13; // rax
  char *v14; // rax
  char *v15; // rcx
  bool v16; // r13
  signed __int64 v17; // rdx
  __int64 v18; // rax
  signed __int64 v19; // rcx
  signed __int64 v20; // rax
  __int64 v21; // rcx
  UFG::RoadNetworkLane *v22; // rbp
  int v23; // ecx
  signed __int64 v24; // rax
  bool v25; // al
  __int64 v26; // rcx
  bool v27; // r12
  signed __int64 v28; // r14
  unsigned int v29; // er15
  unsigned int v30; // edi
  __int64 v31; // rsi
  __int64 v32; // rax
  signed __int64 v33; // rcx
  signed __int64 v34; // rax
  __int64 v35; // rcx
  signed __int64 v36; // rdx
  signed __int64 v37; // rbx
  float v38; // xmm6_4
  __int64 v39; // rax
  UFG::RoadNetworkConnection *v40; // rcx
  unsigned int v41; // edx
  float v42; // xmm7_4
  __int64 v43; // r8
  unsigned __int16 v44; // cx
  UFG::SimComponent *v45; // rax
  bool v46; // zf
  UFG::SimObjectGame *v47; // rcx
  __int64 v49; // [rsp+20h] [rbp-C8h]
  bool v50; // [rsp+F0h] [rbp+8h]
  UFG::RoadNetworkLane *v51; // [rsp+F8h] [rbp+10h]
  unsigned int v52; // [rsp+100h] [rbp+18h]
  unsigned int v53; // [rsp+108h] [rbp+20h]

  v51 = roadLane;
  v2 = roadLane;
  v3 = this;
  v4 = UFG::RoadNetworkLane::IsPermissive(roadLane, 1);
  v5 = v3->m_CurrentLocation.m_CurrentLane;
  v6 = v4;
  v50 = v4;
  v7 = v3->m_CurrentLocation.m_LaneT;
  if ( v5 )
  {
    v8 = v5->mNode.mOffset;
    if ( v5->mNode.mOffset )
      v8 += (__int64)v5;
    v9 = *(_QWORD *)(v8 + 32);
    v10 = v5->mPathIndex;
    if ( v9 )
      v11 = UFG::qBezierPathCollectionMemImaged::GetPath((UFG::RoadNetworkConnection *)(v9 + v8 + 32), v10);
    else
      v11 = UFG::qBezierPathCollectionMemImaged::GetPath(0i64, v10);
    v6 = v50;
    v12 = *((float *)&v11->mNode.mOffset + 1);
  }
  else
  {
    v12 = 0.0;
  }
  v13 = v3->m_CurrentLocation.m_CurrentLane;
  if ( v13->mNode.mOffset )
    v14 = (char *)v13 + v13->mNode.mOffset;
  else
    v14 = 0i64;
  if ( v2->mNode.mOffset )
    v15 = (char *)v2 + v2->mNode.mOffset;
  else
    v15 = 0i64;
  v16 = *((_DWORD *)v14 + 6) == *((_DWORD *)v15 + 6);
  v53 = (unsigned __int8)v2->mNumOpposingLanes;
  v52 = 0;
  if ( !v2->mNumOpposingLanes )
    return 0;
  v17 = 0i64;
  v49 = 0i64;
  while ( 1 )
  {
    v18 = v2->mOpposingLanes.mOffset;
    v19 = (signed __int64)(v18 ? (UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkLane *> *> *)((char *)&v2->mOpposingLanes
                                                                                            + v18) : 0i64);
    v20 = v19 + v17;
    v21 = *(_QWORD *)(v19 + v17);
    v22 = (UFG::RoadNetworkLane *)(v21 ? v21 + v20 : 0i64);
    v23 = 0;
    v24 = (signed __int64)&v22->mCars.mNode.mNext[-2].mNext;
    if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v24 != &v22->mStartConnection )
      break;
LABEL_30:
    if ( v6 && v22->mStatus.mValue == 2 )
    {
      v25 = UFG::RoadNetworkLane::IsPermissive(v22, 1);
      v26 = v22->mPrevConnection.mOffset;
      v27 = v25;
      if ( v26 )
      {
        v28 = (signed __int64)&v22->mPrevConnection + v26;
        if ( v28 )
        {
          v29 = *(_DWORD *)v28;
          v30 = 0;
          if ( *(_DWORD *)v28 )
          {
            v31 = 0i64;
            do
            {
              v32 = *(_QWORD *)(v28 + 8);
              if ( v32 )
                v33 = v32 + v28 + 8;
              else
                v33 = 0i64;
              v34 = v33 + v31;
              v35 = *(_QWORD *)(v33 + v31);
              if ( v35 )
                v36 = v35 + v34;
              else
                v36 = 0i64;
              if ( *(_QWORD *)(v36 + 120) - 24i64 == v36 + 88 )
                goto LABEL_67;
              v37 = *(_QWORD *)(v36 + 112) - 24i64;
              if ( *(_QWORD *)(v36 + 112) == 24i64 || *(UFG::RoadNetworkLane **)(v37 + 80) != v22 )
                goto LABEL_67;
              v38 = *(float *)(v37 + 56);
              if ( v38 <= 0.0 )
              {
                v38 = 0.0;
              }
              else if ( v38 >= 1.0 )
              {
                v38 = *(float *)&FLOAT_1_0;
              }
              v39 = *(_QWORD *)v36;
              if ( *(_QWORD *)v36 )
                v39 += v36;
              v40 = *(UFG::RoadNetworkConnection **)(v39 + 32);
              v41 = *(unsigned __int16 *)(v36 + 38);
              if ( v40 )
                v40 = (UFG::RoadNetworkConnection *)((char *)v40 + v39 + 32);
              v42 = (float)(1.0 - v38)
                  * *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v40, v41)->mNode.mOffset + 1);
              if ( v42 > 20.0 )
                goto LABEL_67;
              v43 = *(_QWORD *)(v37 + 72);
              if ( !v43 )
                goto LABEL_67;
              v44 = *(_WORD *)(v43 + 76);
              if ( (v44 >> 14) & 1 )
                goto LABEL_67;
              if ( (v44 & 0x8000u) == 0 )
              {
                if ( (v44 >> 13) & 1 )
                  goto LABEL_67;
                v46 = ((v44 >> 12) & 1) == 0;
                v47 = *(UFG::SimObjectGame **)(v37 + 72);
                if ( v46 )
                  v45 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v47->vfptr,
                          UFG::PhysicsMoverInterface::_TypeUID);
                else
                  v45 = UFG::SimObjectGame::GetComponentOfTypeHK(v47, UFG::PhysicsMoverInterface::_TypeUID);
              }
              else
              {
                v45 = *(UFG::SimComponent **)(*(_QWORD *)(v43 + 104) + 544i64);
              }
              if ( v45
                && *((float *)&v45[10].m_BoundComponentHandles.mNode.mPrev + 1) >= 0.40000001
                && (!v27 || v16 || (float)((float)(1.0 - v7) * v12) > v42) )
              {
                return 1;
              }
LABEL_67:
              ++v30;
              v31 += 8i64;
            }
            while ( v30 < v29 );
          }
          v2 = v51;
        }
      }
      v6 = v50;
    }
    v17 = v49 + 8;
    ++v52;
    v49 += 8i64;
    if ( v52 >= v53 )
      return 0;
  }
  while ( (unsigned int)++v23 <= 2 && (!v6 || v16 && v7 >= 0.40000001 || *(float *)(v24 + 56) > 0.60000002) )
  {
    v24 = *(_QWORD *)(v24 + 32) - 24i64;
    if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v24 == &v22->mStartConnection )
      goto LABEL_30;
  }
  return 1;
}

// File Line: 998
// RVA: 0xDD9F0
char __fastcall UFG::RoadNetworkGuide::IsBlockedInMergeLanes(UFG::RoadNetworkGuide *this, UFG::RoadNetworkLane *roadLane)
{
  UFG::RoadNetworkLane *v2; // r14
  UFG::RoadNetworkGuide *v3; // rsi
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **v4; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v5; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v6; // rcx
  float v7; // xmm6_4
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v8; // rax
  __int64 v9; // r8
  signed __int64 v10; // rdx
  __int64 v11; // rax
  signed __int64 v12; // rdi
  __int64 v13; // rax
  UFG::RoadNetworkConnection *v14; // rcx
  UFG::qBezierPathMemImaged *v15; // rax
  UFG::RoadNetworkConnection *v16; // rbx
  unsigned int v17; // eax
  UFG::qBezierSplineMemImaged *v18; // rax
  unsigned int v20; // er13
  unsigned int v21; // er15
  __int64 v22; // r12
  __int64 v23; // rax
  signed __int64 v24; // rcx
  signed __int64 v25; // rax
  __int64 v26; // rcx
  signed __int64 v27; // rax
  signed __int64 v28; // rbp
  signed __int64 v29; // rdi
  __int64 v30; // rcx
  __int64 v31; // rax
  __int64 v32; // rdx
  __int64 v33; // rcx
  float v34; // xmm6_4
  __int64 v35; // rax
  signed __int64 v36; // rdx
  signed __int64 v37; // rsi
  __int64 v38; // rax
  UFG::RoadNetworkConnection *v39; // rcx
  UFG::qBezierPathMemImaged *v40; // rax
  UFG::RoadNetworkConnection *v41; // rbx
  unsigned int v42; // eax
  UFG::qBezierSplineMemImaged *v43; // rax
  unsigned int v44; // er8
  __int64 v45; // r10
  __int64 v46; // r9
  signed __int64 v47; // rax
  signed __int64 v48; // rcx
  __int64 v49; // rax
  signed __int64 v50; // rdx
  UFG::qVector3 result; // [rsp+20h] [rbp-58h]
  UFG::RoadNetworkGuide *v52; // [rsp+80h] [rbp+8h]
  float splineT; // [rsp+88h] [rbp+10h]

  v52 = this;
  v2 = roadLane;
  v3 = this;
  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&roadLane->mCars.mNode.mNext[-2].mNext != &roadLane->mStartConnection )
  {
    v4 = &roadLane->mCars.mNode.mNext[-2].mNext;
    if ( roadLane->mCars.mNode.mNext != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)24
      && v4 != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)this )
    {
      v5 = v4[8];
      v6 = v5->mPrev;
      if ( v5->mPrev )
        v6 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)((char *)v6 + (_QWORD)v5);
      v7 = *((float *)v4 + 14);
      v8 = v6[3].mPrev;
      v9 = WORD2(v5[2].mPrev);
      if ( v8 )
        v10 = (signed __int64)&v6[3] + (_QWORD)v8;
      else
        v10 = 0i64;
      v11 = *(_QWORD *)(v10 + 8 * v9);
      if ( v11 )
        v12 = v11 + v10 + 8 * v9;
      else
        v12 = 0i64;
      v13 = *(_QWORD *)v12;
      if ( *(_QWORD *)v12 )
        v13 += v12;
      v14 = *(UFG::RoadNetworkConnection **)(v13 + 32);
      if ( v14 )
        v14 = (UFG::RoadNetworkConnection *)((char *)v14 + v13 + 32);
      v15 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v14,
                                           *(unsigned __int16 *)(v12 + 38));
      v16 = (UFG::RoadNetworkConnection *)v15;
      v17 = UFG::qBezierPathMemImaged::GetSplineParameters(v15, v7, &splineT);
      v18 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v16, v17);
      UFG::RoadNetworkLane::GetOffsetPos(&result, v18, splineT, *(float *)(v12 + 40));
      if ( UFG::RoadNetworkGuide::IsBlocking(v3, &result) )
        return 1;
    }
  }
  v20 = (unsigned __int8)v2->mNumMergeOutLanes;
  v21 = 0;
  if ( v2->mNumMergeOutLanes )
  {
    v22 = 0i64;
    while ( 1 )
    {
      v23 = v2->mMergeOutLanes.mOffset;
      v24 = (signed __int64)(v23 ? (UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkLane *> *> *)((char *)&v2->mMergeOutLanes
                                                                                              + v23) : 0i64);
      v25 = v22 + v24;
      v26 = *(_QWORD *)(v22 + v24);
      v27 = v26 ? v26 + v25 : 0i64;
      v28 = v27 + 88;
      v29 = *(_QWORD *)(v27 + 120) - 24i64;
      if ( v29 != v27 + 88 )
        break;
LABEL_40:
      ++v21;
      v22 += 8i64;
      if ( v21 >= v20 )
        goto LABEL_41;
    }
    while ( 1 )
    {
      v30 = *(_QWORD *)(v29 + 64);
      v31 = *(_QWORD *)v30;
      if ( *(_QWORD *)v30 )
        v31 += v30;
      v32 = *(unsigned __int16 *)(v30 + 36);
      v33 = *(_QWORD *)(v31 + 48);
      v34 = *(float *)(v29 + 56);
      if ( v33 )
        v33 += v31 + 48;
      v35 = *(_QWORD *)(v33 + 8 * v32);
      v36 = v33 + 8 * v32;
      if ( v35 )
        v37 = v35 + v36;
      else
        v37 = 0i64;
      v38 = *(_QWORD *)v37;
      if ( *(_QWORD *)v37 )
        v38 += v37;
      v39 = *(UFG::RoadNetworkConnection **)(v38 + 32);
      if ( v39 )
        v39 = (UFG::RoadNetworkConnection *)((char *)v39 + v38 + 32);
      v40 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v39,
                                           *(unsigned __int16 *)(v37 + 38));
      v41 = (UFG::RoadNetworkConnection *)v40;
      v42 = UFG::qBezierPathMemImaged::GetSplineParameters(v40, v34, &splineT);
      v43 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v41, v42);
      UFG::RoadNetworkLane::GetOffsetPos(&result, v43, splineT, *(float *)(v37 + 40));
      if ( UFG::RoadNetworkGuide::IsBlocking(v52, &result) )
        break;
      v29 = *(_QWORD *)(v29 + 32) - 24i64;
      if ( v29 == v28 )
        goto LABEL_40;
    }
  }
  else
  {
LABEL_41:
    v44 = 0;
    if ( !v2->mNumMergeInLanes )
      return 0;
    v45 = v2->mMergeInLanes.mOffset;
    v46 = 0i64;
    while ( 1 )
    {
      v47 = (signed __int64)(v45 ? (UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkLane *> *> *)((char *)&v2->mMergeInLanes
                                                                                              + v45) : 0i64);
      v48 = v46 + v47;
      v49 = *(_QWORD *)(v46 + v47);
      v50 = v49 ? v49 + v48 : 0i64;
      if ( *(_QWORD *)(v50 + 120) - 24i64 != v50 + 88
        && (*(_BYTE *)(v50 + 55) == 2
         || *(_QWORD *)(v50 + 112) != 24i64 && *(float *)(*(_QWORD *)(v50 + 112) - 24i64 + 56) > 0.2) )
      {
        break;
      }
      ++v44;
      v46 += 8i64;
      if ( v44 >= (unsigned __int8)v2->mNumMergeInLanes )
        return 0;
    }
  }
  return 1;
}

// File Line: 1040
// RVA: 0xDE100
bool __fastcall UFG::RoadNetworkGuide::IsBlocking(UFG::RoadNetworkGuide *this, UFG::qVector3 *pos)
{
  float v2; // xmm6_4
  UFG::RoadNetworkGuide *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  UFG::qVector3 *v5; // rsi
  unsigned __int16 v6; // r8
  UFG::PhysicsMoverInterface *v7; // rax
  float v8; // xmm0_4
  UFG::RoadNetworkLane *v9; // rdx
  UFG::RoadNetworkConnection *v10; // rcx
  char *v11; // rax
  __int64 v12; // r8
  __int64 v13; // rdx
  float v14; // xmm7_4
  signed __int64 v15; // rdx
  __int64 v16; // rax
  signed __int64 v17; // rdi
  signed __int64 v18; // rax
  __int64 v19; // rdx
  UFG::qBezierPathMemImaged *v20; // rax
  UFG::RoadNetworkConnection *v21; // rbx
  unsigned int v22; // eax
  UFG::qBezierSplineMemImaged *v23; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-38h]
  float splineT; // [rsp+60h] [rbp+8h]

  v2 = FLOAT_100_0;
  v3 = this;
  v4 = (UFG::SimObjectGame *)this->m_SimObj;
  v5 = pos;
  if ( !v4 )
    goto LABEL_11;
  v6 = v4->m_Flags;
  if ( (v6 >> 14) & 1 )
    goto LABEL_11;
  if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
      goto LABEL_11;
    if ( (v6 >> 12) & 1 )
      v7 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v4,
                                           UFG::PhysicsMoverInterface::_TypeUID);
    else
      v7 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v4->vfptr,
                                           UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v7 = (UFG::PhysicsMoverInterface *)v4->m_Components.p[34].m_pComponent;
  }
  if ( v7 )
  {
    v8 = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitude(v7);
    v2 = UFG::LinearGraph<float>::GetValue(&stru_142091488, v8);
  }
LABEL_11:
  v9 = v3->m_CurrentLocation.m_CurrentLane;
  v10 = 0i64;
  if ( v9->mNode.mOffset )
    v11 = (char *)v9 + v9->mNode.mOffset;
  else
    v11 = 0i64;
  v12 = v9->mLaneIndex;
  v13 = *((_QWORD *)v11 + 6);
  v14 = v3->m_CurrentLocation.m_LaneT;
  if ( v13 )
    v15 = (signed __int64)&v11[v13 + 48];
  else
    v15 = 0i64;
  v16 = *(_QWORD *)(v15 + 8 * v12);
  v17 = v16 + v15 + 8 * v12;
  if ( !v16 )
    v17 = 0i64;
  if ( *(_QWORD *)v17 )
    v18 = v17 + *(_QWORD *)v17;
  else
    v18 = 0i64;
  v19 = *(_QWORD *)(v18 + 32);
  if ( v19 )
    v10 = (UFG::RoadNetworkConnection *)(v19 + v18 + 32);
  v20 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v10, *(unsigned __int16 *)(v17 + 38));
  v21 = (UFG::RoadNetworkConnection *)v20;
  v22 = UFG::qBezierPathMemImaged::GetSplineParameters(v20, v14, &splineT);
  v23 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v21, v22);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v23, splineT, *(float *)(v17 + 40));
  return v2 > (float)((float)((float)((float)(result.x - v5->x) * (float)(result.x - v5->x))
                            + (float)((float)(result.y - v5->y) * (float)(result.y - v5->y)))
                    + (float)((float)(result.z - v5->z) * (float)(result.z - v5->z)));
}

// File Line: 1057
// RVA: 0xDE2B0
__int64 __fastcall UFG::RoadNetworkGuide::IsClearAfterIntersection(UFG::RoadNetworkGuide *this, UFG::RoadNetworkLane *lane)
{
  __int64 v2; // rax
  UFG::RoadNetworkLane *v3; // rdi
  UFG::RoadNetworkGuide *v4; // rbp
  unsigned __int8 v5; // bl
  char *v6; // rax
  __int64 v7; // rdx
  char *v8; // rax
  __int64 v9; // rcx
  char *v10; // rdx
  signed __int64 v11; // rsi
  __int64 v12; // rcx
  __int64 v13; // rax
  unsigned int v14; // edx
  __int64 v15; // rcx
  UFG::RoadNetworkConnection *v16; // rcx
  float v17; // xmm0_4

  v2 = lane->mNextConnection.mOffset;
  v3 = lane;
  v4 = this;
  v5 = 1;
  if ( v2 )
  {
    v6 = (char *)&lane->mNextConnection + v2;
    if ( v6 )
    {
      v7 = *((_QWORD *)v6 + 1);
      v8 = v7 ? &v6[v7 + 8] : 0i64;
      v9 = *(_QWORD *)v8;
      if ( *(_QWORD *)v8 )
      {
        v10 = &v8[v9];
        if ( &v8[v9] )
        {
          if ( (char *)(*((_QWORD *)v10 + 15) - 24i64) != v10 + 88 )
          {
            v11 = *((_QWORD *)v10 + 15) - 24i64;
            if ( *((_QWORD *)v10 + 15) != 24i64 )
            {
              v12 = *(_QWORD *)(v11 + 64);
              if ( *(_QWORD *)v12 )
                v13 = v12 + *(_QWORD *)v12;
              else
                v13 = 0i64;
              v14 = *(unsigned __int16 *)(v12 + 38);
              v15 = *(_QWORD *)(v13 + 32);
              if ( v15 )
                v16 = (UFG::RoadNetworkConnection *)(v13 + v15 + 32);
              else
                v16 = 0i64;
              v17 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v16, v14)->mNode.mOffset + 1)
                  * *(float *)(v11 + 56);
              if ( v17 >= 10.0 )
              {
                if ( v17 <= 20.0
                  && (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&v3->mCars.mNode.mNext[-2].mNext != &v3->mStartConnection
                  && v3->mCars.mNode.mNext != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)24 )
                {
                  v5 = 1;
                  if ( (UFG::RoadNetworkGuide *)&v3->mCars.mNode.mNext[-2].mNext != v4 )
                    v5 = 0;
                }
              }
              else
              {
                v5 = 0;
              }
            }
          }
        }
      }
    }
  }
  return v5;
}

// File Line: 1089
// RVA: 0xE1960
void __fastcall UFG::RoadNetworkGuide::UpdateStopPointDistance(UFG::RoadNetworkGuide *this)
{
  UFG::RoadNetworkGuide *v1; // rdi
  UFG::RoadNetworkLane *v2; // rbp
  UFG::RoadNetworkLane *v3; // r14
  UFG::RoadNetworkConnection *v4; // rbx
  UFG::RoadNetworkLane *v5; // rsi
  _WORD *v6; // rax
  bool v7; // r15
  __m128 v8; // xmm2
  UFG::RoadNetworkLane *v9; // rax
  _WORD *v10; // rdx
  bool v11; // r14
  char v12; // bp
  UFG::RoadNetworkLane *v13; // rcx
  char *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rcx
  float v17; // xmm6_4
  signed __int64 v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // rsi
  signed __int64 v21; // rax
  __int64 v22; // rcx
  UFG::qBezierPathMemImaged *v23; // rax
  UFG::RoadNetworkConnection *v24; // rbx
  unsigned int v25; // eax
  UFG::qBezierSplineMemImaged *v26; // rax
  float v27; // xmm1_4
  __m128 v28; // xmm0
  float v29; // xmm2_4
  float v30; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-48h]
  UFG::qVector3 v32; // [rsp+30h] [rbp-38h]
  float splineT; // [rsp+70h] [rbp+8h]

  v1 = this;
  if ( !this->m_Attached )
  {
    this->m_StopPointDistance = 0.0;
    return;
  }
  this->m_StopPointDistance = 3.4028235e38;
  v2 = this->m_CurrentLocation.m_CurrentLane;
  if ( v2 )
  {
    v3 = this->m_NextLane;
    if ( v3 )
    {
      v4 = 0i64;
      v5 = 0i64;
      UFG::RoadNetworkLane::GetPos(v2, &result, v2->mStopPoint);
      if ( v3->mNode.mOffset )
        v6 = (_WORD *)((char *)v3 + v3->mNode.mOffset);
      else
        v6 = 0i64;
      v7 = *v6 == 1;
      if ( *v6 == 1 )
      {
        if ( !v6[1] )
          return;
        if ( v3->mStatus.mValue != 2 )
        {
          v8 = (__m128)LODWORD(result.y);
          v8.m128_f32[0] = (float)((float)((float)(result.y - v1->m_Position.y) * (float)(result.y - v1->m_Position.y))
                                 + (float)((float)(result.x - v1->m_Position.x) * (float)(result.x - v1->m_Position.x)))
                         + (float)((float)(result.z - v1->m_Position.z) * (float)(result.z - v1->m_Position.z));
          v1->m_StopPointDistance = (float)(COERCE_FLOAT(_mm_sqrt_ps(v8)) - v1->m_FrontBoundary) - 1.0;
          return;
        }
        v5 = v3;
      }
      v9 = v1->m_CurrentLocation.m_CurrentLane;
      v10 = (_WORD *)((char *)v9 + v9->mNode.mOffset);
      if ( !v9->mNode.mOffset )
        v10 = 0i64;
      v11 = *v10 == 1;
      if ( *v10 == 1 )
        v5 = v2;
      if ( v5 )
      {
        v12 = UFG::RoadNetworkGuide::IsBlockedInMergeLanes(v1, v5);
        if ( v12
          || (v12 = UFG::RoadNetworkGuide::IsBlockedInOpposingLanes(v1, v5)) != 0
          || !(unsigned __int8)UFG::RoadNetworkGuide::IsClearAfterIntersection(v1, v5) )
        {
          if ( v11 && v12 )
          {
            v13 = v1->m_TargetLocation.m_CurrentLane;
            if ( v13->mNode.mOffset )
              v14 = (char *)v13 + v13->mNode.mOffset;
            else
              v14 = 0i64;
            v15 = v13->mLaneIndex;
            v16 = *((_QWORD *)v14 + 6);
            v17 = v1->m_TargetLocation.m_LaneT;
            if ( v16 )
              v18 = (signed __int64)&v14[v16 + 48];
            else
              v18 = 0i64;
            v19 = *(_QWORD *)(v18 + 8 * v15);
            v20 = v19 + v18 + 8 * v15;
            if ( !v19 )
              v20 = 0i64;
            if ( *(_QWORD *)v20 )
              v21 = v20 + *(_QWORD *)v20;
            else
              v21 = 0i64;
            v22 = *(_QWORD *)(v21 + 32);
            if ( v22 )
              v4 = (UFG::RoadNetworkConnection *)(v22 + v21 + 32);
            v23 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                 v4,
                                                 *(unsigned __int16 *)(v20 + 38));
            v24 = (UFG::RoadNetworkConnection *)v23;
            v25 = UFG::qBezierPathMemImaged::GetSplineParameters(v23, v17, &splineT);
            v26 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v24, v25);
            UFG::RoadNetworkLane::GetOffsetPos(&v32, v26, splineT, *(float *)(v20 + 40));
            v27 = v32.x;
            v28 = (__m128)LODWORD(v32.y);
            v29 = v32.z;
          }
          else
          {
            v29 = result.z;
            v28 = (__m128)LODWORD(result.y);
            v27 = result.x;
          }
          v28.m128_f32[0] = (float)((float)((float)(v28.m128_f32[0] - v1->m_Position.y)
                                          * (float)(v28.m128_f32[0] - v1->m_Position.y))
                                  + (float)((float)(v27 - v1->m_Position.x) * (float)(v27 - v1->m_Position.x)))
                          + (float)((float)(v29 - v1->m_Position.z) * (float)(v29 - v1->m_Position.z));
          v30 = COERCE_FLOAT(_mm_sqrt_ps(v28)) - v1->m_FrontBoundary;
          v1->m_StopPointDistance = v30;
          if ( v7 )
            v1->m_StopPointDistance = v30 - 1.0;
        }
      }
    }
  }
}

// File Line: 1153
// RVA: 0xDF610
_BOOL8 __fastcall UFG::RoadNetworkGuide::NavigationInfoNeeded(UFG::RoadNetworkGuide *this)
{
  return this->m_NextLane == 0i64;
}

// File Line: 1163
// RVA: 0xE0840
void __fastcall UFG::RoadNetworkGuide::SetLaneAfterNext(UFG::RoadNetworkGuide *this, UFG::RoadNetworkLane *roadLane)
{
  this->m_LaneAfterNext = roadLane;
}

// File Line: 1168
// RVA: 0xDFFD0
void __fastcall UFG::RoadNetworkGuide::RemoveFromNetwork(UFG::RoadNetworkGuide *this)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v1; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v2; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v3; // r8

  v1 = this->mPrev;
  v2 = this->mNext;
  v3 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)&this->mPrev;
  v1->mNext = v2;
  v2->mPrev = v1;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->m_NextLane = 0i64;
  this->m_Attached = 0;
}

// File Line: 1177
// RVA: 0xDF7D0
void __fastcall UFG::RoadNetworkGuide::Park(UFG::RoadNetworkGuide *this)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v1; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v2; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v3; // r8

  v1 = this->mPrev;
  v2 = this->mNext;
  v3 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)&this->mPrev;
  v1->mNext = v2;
  v2->mPrev = v1;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->m_NextLane = 0i64;
  this->m_Parked = 1;
}

// File Line: 1185
// RVA: 0xDE910
bool __fastcall UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(UFG::RoadNetworkGuide *this, UFG::RoadNetworkLane *lane)
{
  float v2; // xmm7_4
  UFG::RoadNetworkConnection *v3; // rsi
  UFG::RoadNetworkLane *v4; // r14
  signed __int64 v5; // rbp
  float *v6; // r13
  float v7; // xmm10_4
  float v8; // xmm9_4
  float v9; // xmm11_4
  float v10; // xmm8_4
  char *v11; // rax
  __int64 v12; // rcx
  unsigned int v13; // edx
  UFG::RoadNetworkConnection *v14; // rcx
  UFG::qBezierPathMemImaged *v15; // rax
  UFG::RoadNetworkConnection *v16; // rbx
  unsigned int v17; // eax
  UFG::qBezierSplineMemImaged *v18; // rax
  signed __int64 v19; // r12
  signed __int64 v20; // rdi
  int v21; // er15
  float v22; // xmm5_4
  __m128 v23; // xmm3
  float v24; // xmm4_4
  float v25; // xmm6_4
  char *v26; // rax
  __int64 v27; // rcx
  UFG::RoadNetworkConnection *v28; // rcx
  UFG::qBezierPathMemImaged *v29; // rax
  UFG::RoadNetworkConnection *v30; // rbx
  unsigned int v31; // eax
  UFG::qBezierSplineMemImaged *v32; // rax
  __m128 v33; // xmm2
  signed __int64 v35; // rbx
  __int64 v36; // rax
  __int64 v37; // rcx
  unsigned int v38; // edx
  __int64 v39; // rax
  UFG::RoadNetworkConnection *v40; // rcx
  UFG::RoadNetworkLane *v41; // rax
  __int64 v42; // rcx
  float v43; // xmm6_4
  __int64 v44; // rax
  unsigned int v45; // edx
  __int64 v46; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-A8h]
  UFG::qVector3 v48; // [rsp+30h] [rbp-98h]
  float splineT; // [rsp+D0h] [rbp+8h]

  v2 = this->m_CurrentLocation.m_LaneT;
  v3 = 0i64;
  v4 = lane;
  v5 = 0i64;
  v6 = 0i64;
  v7 = this->m_FrontBoundary;
  v8 = this->m_RearBoundary;
  v9 = this->m_FrontBoundary + 2.5;
  v10 = (float)(this->m_RearBoundary + v7) + 5.0;
  if ( lane->mNode.mOffset )
    v11 = (char *)lane + lane->mNode.mOffset;
  else
    v11 = 0i64;
  v12 = *((_QWORD *)v11 + 4);
  v13 = lane->mPathIndex;
  if ( v12 )
    v14 = (UFG::RoadNetworkConnection *)&v11[v12 + 32];
  else
    v14 = 0i64;
  v15 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v14, v13);
  v16 = (UFG::RoadNetworkConnection *)v15;
  v17 = UFG::qBezierPathMemImaged::GetSplineParameters(v15, v2, &splineT);
  v18 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v16, v17);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v18, splineT, v4->mOffset);
  v19 = (signed __int64)&v4->mStartConnection;
  v20 = (signed __int64)&v4->mCars.mNode.mPrev[-2].mNext;
  v21 = 0;
  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v20 == &v4->mStartConnection )
    return 1;
  v22 = result.z;
  v23 = (__m128)LODWORD(result.y);
  v24 = result.x;
  while ( 1 )
  {
    v25 = *(float *)(v20 + 56);
    ++v21;
    if ( v25 < v2 )
      break;
    if ( v4->mNode.mOffset )
      v26 = (char *)v4 + v4->mNode.mOffset;
    else
      v26 = 0i64;
    v27 = *((_QWORD *)v26 + 4);
    if ( v27 )
      v28 = (UFG::RoadNetworkConnection *)&v26[v27 + 32];
    else
      v28 = 0i64;
    v29 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v28, v4->mPathIndex);
    v30 = (UFG::RoadNetworkConnection *)v29;
    v31 = UFG::qBezierPathMemImaged::GetSplineParameters(v29, v25, &splineT);
    v32 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v30, v31);
    UFG::RoadNetworkLane::GetOffsetPos(&v48, v32, splineT, v4->mOffset);
    v24 = result.x;
    v23 = (__m128)LODWORD(result.y);
    v22 = result.z;
    v33 = (__m128)LODWORD(result.y);
    v33.m128_f32[0] = (float)((float)((float)(result.y - v48.y) * (float)(result.y - v48.y))
                            + (float)((float)(result.x - v48.x) * (float)(result.x - v48.x)))
                    + (float)((float)(result.z - v48.z) * (float)(result.z - v48.z));
    if ( (float)(COERCE_FLOAT(_mm_sqrt_ps(v33)) - (float)(v7 + *(float *)(v20 + 100))) < v9 )
      return 0;
    v5 = v20;
    v20 = *(_QWORD *)(v20 + 24) - 24i64;
    if ( v20 == v19 )
      goto LABEL_21;
  }
  v6 = (float *)v20;
LABEL_21:
  if ( !v21 )
    return 1;
  if ( !v5 )
  {
    v23.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] - v6[30]) * (float)(v23.m128_f32[0] - v6[30]))
                            + (float)((float)(v24 - v6[29]) * (float)(v24 - v6[29])))
                    + (float)((float)(v22 - v6[31]) * (float)(v22 - v6[31]));
    return (float)(COERCE_FLOAT(_mm_sqrt_ps(v23)) - (float)(v8 + v6[24])) > (float)(v8 + 2.5);
  }
  v35 = *(_QWORD *)(v5 + 24) - 24i64;
  if ( v35 == v19 || *(_QWORD *)(v5 + 24) == 24i64 )
    return 1;
  v36 = *(_QWORD *)(v5 + 64);
  if ( *(_QWORD *)v36 )
    v37 = v36 + *(_QWORD *)v36;
  else
    v37 = 0i64;
  v38 = *(unsigned __int16 *)(v36 + 38);
  v39 = *(_QWORD *)(v37 + 32);
  if ( v39 )
    v40 = (UFG::RoadNetworkConnection *)(v39 + v37 + 32);
  else
    v40 = 0i64;
  v41 = UFG::qBezierPathCollectionMemImaged::GetPath(v40, v38);
  v42 = *(_QWORD *)(v35 + 64);
  v43 = (float)(*((float *)&v41->mNode.mOffset + 1) * *(float *)(v5 + 56)) - *(float *)(v5 + 100);
  if ( *(_QWORD *)v42 )
    v44 = v42 + *(_QWORD *)v42;
  else
    v44 = 0i64;
  v45 = *(unsigned __int16 *)(v42 + 38);
  v46 = *(_QWORD *)(v44 + 32);
  if ( v46 )
    v3 = (UFG::RoadNetworkConnection *)(v46 + v44 + 32);
  return (float)(v43
               - (float)((float)(*(float *)(v35 + 56)
                               * *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v3, v45)->mNode.mOffset + 1))
                       + *(float *)(v35 + 96))) >= v10;
}

// File Line: 1253
// RVA: 0xDE450
_BOOL8 __fastcall UFG::RoadNetworkGuide::IsCurrentLocationValid(UFG::RoadNetworkGuide *this)
{
  return this->m_CurrentLocation.m_CurrentLane != 0i64;
}

// File Line: 1258
// RVA: 0xDABB0
UFG::RoadNetworkConnection *__fastcall UFG::RoadNetworkGuide::GetNextConnection(UFG::RoadNetworkGuide *this)
{
  UFG::RoadNetworkLane *v1; // rax
  __int64 v2; // rcx
  signed __int64 v3; // rax
  UFG::RoadNetworkConnection *result; // rax

  v1 = this->m_CurrentLocation.m_CurrentLane;
  v2 = v1->mNextConnection.mOffset;
  v3 = (signed __int64)&v1->mNextConnection;
  if ( v2 )
    result = (UFG::RoadNetworkConnection *)(v2 + v3);
  else
    result = 0i64;
  return result;
}

