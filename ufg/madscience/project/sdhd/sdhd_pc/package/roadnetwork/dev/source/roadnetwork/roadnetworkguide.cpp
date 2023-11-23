// File Line: 70
// RVA: 0xD1E70
void __fastcall UFG::RoadNetworkLocation::Advance(
        UFG::RoadNetworkLocation *this,
        float advanceDist,
        UFG::RoadNetworkLane *nextLane,
        UFG::RoadNetworkLane *laneAfterNext)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  __int64 mOffset; // rcx
  __int64 mLaneIndex; // r8
  __int64 v11; // rax
  float m_LaneT; // xmm6_4
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rsi
  __int64 v16; // rax
  UFG::RoadNetworkConnection *v17; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v20; // rax
  UFG::RoadNetworkLane *v21; // rsi
  __int64 v22; // rax
  UFG::RoadNetworkConnection *v23; // rcx
  float v24; // xmm10_4
  UFG::qBezierPathMemImaged *v25; // rbx
  unsigned int v26; // eax
  UFG::qBezierSplineMemImaged *v27; // rax
  __m128 y_low; // xmm2
  int v29; // xmm8_4
  float v30; // xmm7_4
  UFG::qVector3 *Pos; // rax
  __m128 v32; // xmm2
  float x; // xmm0_4
  float z; // xmm1_4
  UFG::qVector3 *v35; // rax
  __m128 v36; // xmm2
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm9_4
  unsigned int i; // r14d
  UFG::RoadNetworkLane *v41; // rcx
  float v42; // xmm6_4
  __int64 v43; // rax
  __int64 v44; // rdx
  __int64 v45; // rcx
  __int64 v46; // rax
  __int64 v47; // rdx
  __int64 v48; // rsi
  __int64 v49; // rax
  UFG::RoadNetworkConnection *v50; // rcx
  UFG::qBezierPathMemImaged *v51; // rbx
  unsigned int v52; // eax
  UFG::qBezierSplineMemImaged *v53; // rax
  __m128 v54; // xmm2
  float v55; // xmm1_4
  UFG::qVector3 result; // [rsp+8h] [rbp-79h] BYREF
  UFG::qVector3 v57; // [rsp+18h] [rbp-69h] BYREF
  UFG::qVector3 v58; // [rsp+28h] [rbp-59h] BYREF
  float splineT; // [rsp+E8h] [rbp+67h] BYREF

  m_CurrentLane = this->m_CurrentLane;
  if ( m_CurrentLane )
  {
    mOffset = m_CurrentLane->mNode.mOffset;
    if ( m_CurrentLane->mNode.mOffset )
      mOffset += (__int64)m_CurrentLane;
    mLaneIndex = m_CurrentLane->mLaneIndex;
    v11 = *(_QWORD *)(mOffset + 48);
    m_LaneT = this->m_LaneT;
    if ( v11 )
      v13 = v11 + mOffset + 48;
    else
      v13 = 0i64;
    v14 = *(_QWORD *)(v13 + 8 * mLaneIndex);
    if ( v14 )
      v15 = v14 + v13 + 8 * mLaneIndex;
    else
      v15 = 0i64;
    v16 = *(_QWORD *)v15;
    if ( *(_QWORD *)v15 )
      v16 += v15;
    v17 = *(UFG::RoadNetworkConnection **)(v16 + 32);
    if ( v17 )
      v17 = (UFG::RoadNetworkConnection *)((char *)v17 + v16 + 32);
    Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                          v17,
                                          *(unsigned __int16 *)(v15 + 38));
    SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, m_LaneT, &splineT);
    v20 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           (UFG::RoadNetworkConnection *)Path,
                                           SplineParameters);
    UFG::RoadNetworkLane::GetOffsetPos(&result, v20, splineT, *(float *)(v15 + 40));
    v21 = this->m_CurrentLane;
    v22 = v21->mNode.mOffset;
    if ( v21->mNode.mOffset )
      v22 += (__int64)v21;
    v23 = *(UFG::RoadNetworkConnection **)(v22 + 32);
    if ( v23 )
      v23 = (UFG::RoadNetworkConnection *)((char *)v23 + v22 + 32);
    v24 = *(float *)&FLOAT_1_0;
    v25 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v23, v21->mPathIndex);
    v26 = UFG::qBezierPathMemImaged::GetSplineParameters(v25, 1.0, &splineT);
    v27 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           (UFG::RoadNetworkConnection *)v25,
                                           v26);
    UFG::RoadNetworkLane::GetOffsetPos(&v57, v27, splineT, v21->mOffset);
    y_low = (__m128)LODWORD(v57.y);
    v29 = LODWORD(advanceDist) ^ _xmm[0];
    y_low.m128_f32[0] = (float)((float)((float)(v57.y - result.y) * (float)(v57.y - result.y))
                              + (float)((float)(v57.x - result.x) * (float)(v57.x - result.x)))
                      + (float)((float)(v57.z - result.z) * (float)(v57.z - result.z));
    v30 = _mm_sqrt_ps(y_low).m128_f32[0] - advanceDist;
    if ( v30 > 0.0 )
      goto LABEL_26;
    if ( !nextLane )
      goto LABEL_25;
    if ( this->m_CurrentLane == nextLane )
      goto LABEL_25;
    *(float *)&v29 = v30;
    this->m_CurrentLane = nextLane;
    this->m_LaneT = 0.0;
    Pos = UFG::RoadNetworkLane::GetPos(nextLane, &v58, 1.0);
    v32 = (__m128)LODWORD(Pos->y);
    x = Pos->x;
    z = Pos->z;
    LODWORD(v57.y) = v32.m128_i32[0];
    v57.x = x;
    v57.z = z;
    v32.m128_f32[0] = (float)((float)((float)(v32.m128_f32[0] - result.y) * (float)(v32.m128_f32[0] - result.y))
                            + (float)((float)(x - result.x) * (float)(x - result.x)))
                    + (float)((float)(z - result.z) * (float)(z - result.z));
    v30 = _mm_sqrt_ps(v32).m128_f32[0] - advanceDist;
    if ( v30 > 0.0 )
      goto LABEL_26;
    if ( !laneAfterNext )
      goto LABEL_25;
    if ( this->m_CurrentLane == laneAfterNext )
      goto LABEL_25;
    *(float *)&v29 = v30;
    this->m_CurrentLane = laneAfterNext;
    v35 = UFG::RoadNetworkLane::GetPos(laneAfterNext, &v58, 1.0);
    v36 = (__m128)LODWORD(v35->y);
    v37 = v35->x;
    v38 = v35->z;
    LODWORD(v57.y) = v36.m128_i32[0];
    v57.x = v37;
    v57.z = v38;
    v36.m128_f32[0] = (float)((float)((float)(v36.m128_f32[0] - result.y) * (float)(v36.m128_f32[0] - result.y))
                            + (float)((float)(v37 - result.x) * (float)(v37 - result.x)))
                    + (float)((float)(v38 - result.z) * (float)(v38 - result.z));
    v30 = _mm_sqrt_ps(v36).m128_f32[0] - advanceDist;
    if ( v30 > 0.0 )
    {
LABEL_26:
      v39 = this->m_LaneT;
      for ( i = 0; i < 0xA; ++i )
      {
        v41 = this->m_CurrentLane;
        v42 = (float)((float)(*(float *)&v29 / (float)(*(float *)&v29 - v30)) * (float)(v24 - v39)) + v39;
        this->m_LaneT = v42;
        v43 = v41->mNode.mOffset;
        if ( v41->mNode.mOffset )
          v43 += (__int64)v41;
        v44 = v41->mLaneIndex;
        v45 = *(_QWORD *)(v43 + 48);
        if ( v45 )
          v45 += v43 + 48;
        v46 = *(_QWORD *)(v45 + 8 * v44);
        v47 = v45 + 8 * v44;
        if ( v46 )
          v48 = v46 + v47;
        else
          v48 = 0i64;
        v49 = *(_QWORD *)v48;
        if ( *(_QWORD *)v48 )
          v49 += v48;
        v50 = *(UFG::RoadNetworkConnection **)(v49 + 32);
        if ( v50 )
          v50 = (UFG::RoadNetworkConnection *)((char *)v50 + v49 + 32);
        v51 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v50,
                                             *(unsigned __int16 *)(v48 + 38));
        v52 = UFG::qBezierPathMemImaged::GetSplineParameters(v51, v42, &splineT);
        v53 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                               (UFG::RoadNetworkConnection *)v51,
                                               v52);
        UFG::RoadNetworkLane::GetOffsetPos(&v58, v53, splineT, *(float *)(v48 + 40));
        v54 = (__m128)LODWORD(v58.y);
        v54.m128_f32[0] = (float)((float)((float)(v58.y - result.y) * (float)(v58.y - result.y))
                                + (float)((float)(v58.x - result.x) * (float)(v58.x - result.x)))
                        + (float)((float)(v58.z - result.z) * (float)(v58.z - result.z));
        v55 = _mm_sqrt_ps(v54).m128_f32[0] - advanceDist;
        if ( COERCE_FLOAT(LODWORD(v55) & _xmm) < 0.1 )
          break;
        if ( v55 <= 0.0 )
        {
          v39 = this->m_LaneT;
          *(float *)&v29 = v55;
        }
        else
        {
          v24 = this->m_LaneT;
          v30 = v55;
        }
      }
    }
    else
    {
LABEL_25:
      this->m_LaneT = 1.0;
    }
  }
}  *(float *)&v29 = v55;
        }
        else
        {
          v24 = this->m_LaneT;
          v30 = v55;
        }
      }
    }
    else
    {
LABEL_25:
      this->m_Lan

// File Line: 136
// RVA: 0xDEE30
_BOOL8 __fastcall UFG::RoadNetworkLocation::IsValid(UFG::RoadNetworkLocation *this)
{
  return this->m_CurrentLane != 0i64;
}

// File Line: 142
// RVA: 0xD29C0
void __fastcall UFG::RoadNetworkLocation::AttachToNetwork(
        UFG::RoadNetworkLocation *this,
        UFG::RoadNetworkResource *roadNetwork,
        UFG::qVector3 *spawnPos,
        UFG::qVector3 *spawnHeading,
        unsigned int type)
{
  UFG::RoadNetworkNode *ClosestNode; // rax
  float v9; // xmm0_4
  UFG::qVector3 result; // [rsp+30h] [rbp-18h] BYREF
  float nearestT; // [rsp+50h] [rbp+8h] BYREF
  UFG::RoadNetworkLane *nearestLane; // [rsp+58h] [rbp+10h] BYREF

  this->m_CurrentLane = 0i64;
  this->m_LaneT = 0.0;
  if ( roadNetwork )
  {
    nearestLane = 0i64;
    nearestT = 0.0;
    ClosestNode = UFG::RoadNetworkResource::GetClosestNode(roadNetwork, spawnPos, type, 0i64, 0i64);
    if ( spawnHeading )
      UFG::RoadNetworkNode::GetNearestPos(ClosestNode, &result, spawnPos, spawnHeading, &nearestLane, &nearestT);
    else
      UFG::RoadNetworkNode::GetNearestPos(ClosestNode, &result, spawnPos, &nearestLane, &nearestT);
    if ( nearestLane )
    {
      v9 = nearestT;
      this->m_CurrentLane = nearestLane;
      this->m_LaneT = v9;
    }
  }
}

// File Line: 178
// RVA: 0xD8740
float __fastcall UFG::RoadNetworkLocation::GetDistanceAlongSpline(UFG::RoadNetworkLocation *this)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rdx
  UFG::RoadNetworkConnection *v3; // rcx
  char *v4; // rax
  unsigned int mPathIndex; // r8d
  __int64 v6; // rdx

  m_CurrentLane = this->m_CurrentLane;
  v3 = 0i64;
  if ( m_CurrentLane->mNode.mOffset )
    v4 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  else
    v4 = 0i64;
  mPathIndex = m_CurrentLane->mPathIndex;
  v6 = *((_QWORD *)v4 + 4);
  if ( v6 )
    v3 = (UFG::RoadNetworkConnection *)&v4[v6 + 32];
  return *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v3, mPathIndex)->mNode.mOffset + 1) * this->m_LaneT;
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
  UFG::RoadNetworkLane *m_CurrentLane; // rbx
  __int64 mOffset; // rax
  float v5; // xmm6_4
  bool IsReversedInNode; // al
  int v7; // r8d
  int v8; // ecx
  int v9; // r8d
  int v10; // eax

  m_CurrentLane = this->m_CurrentLane;
  if ( !m_CurrentLane )
    return 0;
  mOffset = m_CurrentLane->mNode.mOffset;
  if ( !m_CurrentLane->mNode.mOffset || !(UFG::RoadNetworkLane *)((char *)m_CurrentLane + mOffset) )
    return 0;
  v5 = *(float *)&FLOAT_1_0;
  if ( (float)*((unsigned __int8 *)&m_CurrentLane->mOffset + mOffset) >= 1.0 )
    v5 = (float)*((unsigned __int8 *)&m_CurrentLane->mOffset + mOffset);
  IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(m_CurrentLane);
  v7 = 1;
  if ( IsReversedInNode )
    v7 = -1;
  v8 = 0;
  v9 = m_CurrentLane->mLaneIndex + left_right * v7;
  v10 = (int)v5 - 1;
  if ( v9 > 0 )
    v8 = v9;
  if ( v8 < v10 )
    v10 = v8;
  return v9 == v10;
}

// File Line: 207
// RVA: 0xDC720
void __fastcall UFG::RoadNetworkLocation::GetVectors(
        UFG::RoadNetworkLocation *this,
        UFG::qVector3 *pos,
        UFG::qVector3 *direction)
{
  UFG::RoadNetworkLane *m_CurrentLane; // r9
  UFG::RoadNetworkLane *v5; // rcx
  char *v8; // rax
  __int64 v9; // rdx
  __int64 mLaneIndex; // r8
  char *v11; // rdx
  __int64 v12; // rax
  char *v13; // r8

  m_CurrentLane = this->m_CurrentLane;
  v5 = 0i64;
  if ( m_CurrentLane->mNode.mOffset )
    v8 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 6);
  mLaneIndex = m_CurrentLane->mLaneIndex;
  if ( v9 )
    v11 = &v8[v9 + 48];
  else
    v11 = 0i64;
  v12 = *(_QWORD *)&v11[8 * mLaneIndex];
  v13 = &v11[8 * mLaneIndex];
  if ( v12 )
    v5 = (UFG::RoadNetworkLane *)&v13[v12];
  UFG::RoadNetworkLane::GetPosAndTangent(v5, this->m_LaneT, pos, direction);
}

// File Line: 213
// RVA: 0xDB400
UFG::qVector3 *__fastcall UFG::RoadNetworkLocation::GetPos(UFG::RoadNetworkLocation *this, UFG::qVector3 *result)
{
  UFG::RoadNetworkLane *m_CurrentLane; // r8
  UFG::RoadNetworkLane *v4; // rcx
  char *v6; // rax
  __int64 v7; // rdx
  __int64 mLaneIndex; // r10
  char *v9; // rdx
  __int64 v10; // rax

  m_CurrentLane = this->m_CurrentLane;
  v4 = 0i64;
  if ( m_CurrentLane->mNode.mOffset )
    v6 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  else
    v6 = 0i64;
  v7 = *((_QWORD *)v6 + 6);
  mLaneIndex = m_CurrentLane->mLaneIndex;
  if ( v7 )
    v9 = &v6[v7 + 48];
  else
    v9 = 0i64;
  v10 = *(_QWORD *)&v9[8 * mLaneIndex];
  if ( v10 )
    v4 = (UFG::RoadNetworkLane *)&v9[8 * mLaneIndex + v10];
  UFG::RoadNetworkLane::GetPos(v4, result, this->m_LaneT);
  return result;
}

// File Line: 219
// RVA: 0xDB780
UFG::RoadNetworkNode *__fastcall UFG::RoadNetworkLocation::GetRoadNetworkNode(UFG::RoadNetworkLocation *this)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rax

  m_CurrentLane = this->m_CurrentLane;
  if ( m_CurrentLane->mNode.mOffset )
    return (UFG::RoadNetworkNode *)((char *)m_CurrentLane + m_CurrentLane->mNode.mOffset);
  else
    return 0i64;
}

// File Line: 232
// RVA: 0xDBFE0
UFG::qVector3 *__fastcall UFG::RoadNetworkLocation::GetTangent(UFG::RoadNetworkLocation *this, UFG::qVector3 *result)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  UFG::RoadNetworkNode *v5; // rcx

  m_CurrentLane = this->m_CurrentLane;
  if ( m_CurrentLane->mNode.mOffset )
    v5 = (UFG::RoadNetworkNode *)((char *)m_CurrentLane + m_CurrentLane->mNode.mOffset);
  else
    v5 = 0i64;
  UFG::RoadNetworkNode::GetTangent(v5, result, m_CurrentLane->mLaneIndex, this->m_LaneT);
  return result;
}

// File Line: 238
// RVA: 0xD3210
void __fastcall UFG::RoadNetworkLocation::ChangeLane(UFG::RoadNetworkLocation *this, unsigned int direction)
{
  UFG::RoadNetworkLane *m_CurrentLane; // r14
  char *v3; // rbx
  char *v5; // rsi
  int v6; // edi
  bool IsReversedInNode; // r8
  int v8; // eax
  __int64 v9; // rdx
  __int64 v10; // rax
  char *v11; // rcx
  __int64 v12; // rax
  char *v13; // rdx
  UFG::RoadNetworkLane *v14; // rax
  __int64 mOffset; // rcx
  char *v16; // rdx
  char *v17; // rcx
  __int64 v18; // rax
  char *v19; // rax
  char *v20; // rcx
  __int64 v21; // rax

  m_CurrentLane = this->m_CurrentLane;
  v3 = 0i64;
  v5 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  if ( !m_CurrentLane->mNode.mOffset )
    v5 = 0i64;
  if ( *(_WORD *)v5 != 1 )
  {
    v6 = -1;
    if ( direction == 1 )
      v6 = 1;
    IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(m_CurrentLane);
    if ( IsReversedInNode )
      v6 = -v6;
    v8 = 0;
    v9 = (unsigned int)(unsigned __int8)v5[40] - 1;
    if ( v6 + m_CurrentLane->mLaneIndex > 0 )
      v8 = v6 + m_CurrentLane->mLaneIndex;
    if ( v8 < (int)v9 )
      v9 = (unsigned int)v8;
    v10 = *((_QWORD *)v5 + 6);
    if ( v10 )
      v11 = &v5[v10 + 48];
    else
      v11 = 0i64;
    v12 = *(_QWORD *)&v11[8 * v9];
    v13 = &v11[8 * v9];
    if ( v12 )
    {
      v14 = (UFG::RoadNetworkLane *)&v13[v12];
      if ( v14 )
      {
        this->m_CurrentLane = v14;
        mOffset = v14->mStartGate.mOffset;
        if ( mOffset )
          v16 = (char *)&v14->mStartGate + mOffset;
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
          v3 = &v20[v21 + 8];
        if ( (v16 != v3) != IsReversedInNode )
          this->m_LaneT = 1.0 - this->m_LaneT;
      }
    }
  }
}

// File Line: 301
// RVA: 0xD49C0
float __fastcall UFG::RoadNetworkLocation::FindLaneTWithCustomSearch(
        UFG::RoadNetworkLocation *this,
        UFG::qVector3 *position,
        UFG::RoadNetworkLane *nextLane)
{
  float m_LaneT; // xmm11_4
  UFG::RoadNetworkLane *m_CurrentLane; // rcx
  __int64 mOffset; // rax
  unsigned int mPathIndex; // edx
  UFG::RoadNetworkConnection *v10; // rcx
  float v11; // xmm6_4
  float v12; // xmm14_4
  float v13; // xmm7_4
  float v14; // xmm0_4
  float v15; // xmm13_4
  char v16; // bp
  UFG::RoadNetworkLane *v17; // rcx
  __int64 v18; // rax
  __int64 mLaneIndex; // rdx
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rdx
  __int64 v23; // rdi
  __int64 v24; // rax
  UFG::RoadNetworkConnection *v25; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v28; // rax
  float v29; // xmm9_4
  int v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm1_4
  float y; // xmm5_4
  float x; // xmm4_4
  float z; // xmm9_4
  __int64 v36; // rax
  float v37; // xmm7_4
  UFG::RoadNetworkConnection *v38; // rcx
  UFG::RoadNetworkLane *v39; // rax
  UFG::RoadNetworkLane *v40; // rcx
  __int64 v41; // rax
  unsigned int v42; // edx
  UFG::RoadNetworkConnection *v43; // rcx
  UFG::qVector3 positiona; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector3 tangent; // [rsp+30h] [rbp-C8h] BYREF
  float splineT; // [rsp+100h] [rbp+8h] BYREF

  m_LaneT = this->m_LaneT;
  m_CurrentLane = this->m_CurrentLane;
  mOffset = m_CurrentLane->mNode.mOffset;
  if ( m_CurrentLane->mNode.mOffset )
    mOffset += (__int64)m_CurrentLane;
  mPathIndex = m_CurrentLane->mPathIndex;
  v10 = *(UFG::RoadNetworkConnection **)(mOffset + 32);
  if ( v10 )
    v10 = (UFG::RoadNetworkConnection *)((char *)v10 + mOffset + 32);
  v11 = *(float *)&FLOAT_1_0;
  v12 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v10, mPathIndex)->mNode.mOffset + 1);
  v13 = 1.0 / v12;
  v14 = (float)(1.0 / v12) + this->m_LaneT;
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
    return m_LaneT;
  while ( 1 )
  {
    v17 = this->m_CurrentLane;
    this->m_LaneT = v11;
    v18 = v17->mNode.mOffset;
    if ( v17->mNode.mOffset )
      v18 += (__int64)v17;
    mLaneIndex = v17->mLaneIndex;
    v20 = *(_QWORD *)(v18 + 48);
    if ( v20 )
      v20 += v18 + 48;
    v21 = *(_QWORD *)(v20 + 8 * mLaneIndex);
    v22 = v20 + 8 * mLaneIndex;
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
    Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                          v25,
                                          *(unsigned __int16 *)(v23 + 38));
    SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, v11, &splineT);
    v28 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           (UFG::RoadNetworkConnection *)Path,
                                           SplineParameters);
    v29 = *(float *)(v23 + 40);
    UFG::qBezierSplineMemImaged::GetPositionAndTangent(v28, splineT, &positiona, &tangent);
    if ( v29 == 0.0 )
    {
      z = positiona.z;
      y = positiona.y;
      x = positiona.x;
    }
    else
    {
      v30 = LODWORD(tangent.x) ^ _xmm[0];
      v31 = (float)(*(float *)&v30 * *(float *)&v30) + (float)(tangent.y * tangent.y);
      if ( v31 == 0.0 )
        v32 = 0.0;
      else
        v32 = 1.0 / fsqrt(v31);
      y = positiona.y + (float)((float)(*(float *)&v30 * v32) * v29);
      positiona.y = y;
      x = positiona.x + (float)((float)(tangent.y * v32) * v29);
      positiona.x = x;
      z = positiona.z + (float)((float)(v32 * 0.0) * v29);
      positiona.z = z;
    }
    if ( (float)((float)((float)((float)(position->y - y) * tangent.y) + (float)((float)(position->x - x) * tangent.x))
               + (float)(tangent.z * (float)(position->z - z))) < 0.0 )
    {
      v13 = v13 * 0.5;
      v11 = v13 + m_LaneT;
    }
    else
    {
      m_LaneT = v11;
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
    if ( m_LaneT >= 1.0 )
    {
      if ( !nextLane || v16 )
        return m_LaneT;
      this->m_CurrentLane = nextLane;
      v36 = nextLane->mNode.mOffset;
      v16 = 1;
      m_LaneT = 0.0;
      v37 = v13 * v12;
      if ( nextLane->mNode.mOffset )
        v36 += (__int64)nextLane;
      v38 = *(UFG::RoadNetworkConnection **)(v36 + 32);
      if ( v38 )
        v38 = (UFG::RoadNetworkConnection *)((char *)v38 + v36 + 32);
      v39 = UFG::qBezierPathCollectionMemImaged::GetPath(v38, nextLane->mPathIndex);
      v40 = this->m_CurrentLane;
      v11 = v37 / *((float *)&v39->mNode.mOffset + 1);
      v41 = v40->mNode.mOffset;
      if ( v40->mNode.mOffset )
        v41 += (__int64)v40;
      v42 = v40->mPathIndex;
      v43 = *(UFG::RoadNetworkConnection **)(v41 + 32);
      if ( v43 )
        v43 = (UFG::RoadNetworkConnection *)((char *)v43 + v41 + 32);
      v13 = v37 / *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v43, v42)->mNode.mOffset + 1);
    }
    if ( !this->m_CurrentLane )
      break;
    if ( v13 <= v15 )
      return m_LaneT;
  }
  this->m_LaneT = 0.0;
  return m_LaneT;
}

// File Line: 409
// RVA: 0xCF850
void __fastcall UFG::RoadNetworkGuide::RoadNetworkGuide(UFG::RoadNetworkGuide *this)
{
  this->mPrev = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  this->mNext = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  UFG::qSafePointerNode<UFG::RoadNetworkGuide>::qSafePointerNode<UFG::RoadNetworkGuide>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::RoadNetworkGuide>Vtbl *)&UFG::RoadNetworkGuide::`vftable;
  this->m_TargetLocation.m_LaneT = 0.0;
  this->m_TargetLocation.m_CurrentLane = 0i64;
  this->m_CurrentLocation.m_LaneT = 0.0;
  this->m_CurrentLocation.m_CurrentLane = 0i64;
  this->m_NextLane = 0i64;
  this->m_LaneAfterNext = 0i64;
  this->m_FrontBoundary = 4.0;
  *(_QWORD *)&this->m_RearBoundary = 1082130432i64;
  *(_QWORD *)&this->m_SpeedLimit = 1099222221i64;
  *(_QWORD *)&this->m_NextGuideDistance = 0i64;
  this->m_NextGuide.mPrev = &this->m_NextGuide;
  this->m_NextGuide.mNext = &this->m_NextGuide;
  this->m_NextGuide.m_pPointer = 0i64;
  *(_WORD *)&this->m_Attached = 0;
  this->m_AdvanceDistance = 5.0;
}

// File Line: 415
// RVA: 0xD27F0
void __fastcall UFG::RoadNetworkGuide::AttachToNetwork(
        UFG::RoadNetworkGuide *this,
        UFG::SimObject *simObj,
        UFG::RoadNetworkNode *node,
        const unsigned int lane,
        float laneT)
{
  float *v5; // rsi
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mPrev; // r10
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mNext; // rax
  __int64 mOffset; // rax
  char *v11; // rcx
  char *v12; // rdx
  UFG::RoadNetworkLane *v13; // rcx
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  UFG::RoadNetworkLane *v15; // rcx
  __int64 v16; // rax
  char *v17; // rax
  __int64 mLaneIndex; // rdx
  __int64 v19; // rcx
  float m_LaneT; // xmm6_4
  char *v21; // rcx
  __int64 v22; // rax
  char *v23; // r14
  char *v24; // rax
  __int64 v25; // rcx
  UFG::RoadNetworkConnection *v26; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v29; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::RoadNetworkLane *v32; // rax
  _WORD *v33; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-28h] BYREF

  v5 = 0i64;
  if ( this->m_Attached )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
    this->mNext = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
    this->m_NextLane = 0i64;
    this->m_Attached = 0;
  }
  this->m_CurrentLocation.m_LaneT = laneT;
  mOffset = node->mLane.mOffset;
  if ( mOffset )
    v11 = (char *)&node->mLane + mOffset;
  else
    v11 = 0i64;
  v12 = &v11[8 * lane];
  v13 = (UFG::RoadNetworkLane *)&v12[*(_QWORD *)v12];
  if ( !*(_QWORD *)v12 )
    v13 = 0i64;
  this->m_CurrentLocation.m_CurrentLane = v13;
  this->m_Attached = 1;
  UFG::RoadNetworkLane::AddCarGuide(v13, this, 1);
  *(_QWORD *)&this->m_TargetLocation.m_LaneT = *(_QWORD *)&this->m_CurrentLocation.m_LaneT;
  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  this->m_SimObj = simObj;
  this->m_TargetLocation.m_CurrentLane = m_CurrentLane;
  v15 = m_CurrentLane;
  v16 = m_CurrentLane->mNode.mOffset;
  if ( v16 )
    v17 = (char *)v15 + v16;
  else
    v17 = 0i64;
  mLaneIndex = v15->mLaneIndex;
  v19 = *((_QWORD *)v17 + 6);
  m_LaneT = this->m_CurrentLocation.m_LaneT;
  if ( v19 )
    v21 = &v17[v19 + 48];
  else
    v21 = 0i64;
  v22 = *(_QWORD *)&v21[8 * mLaneIndex];
  v23 = &v21[8 * mLaneIndex + v22];
  if ( !v22 )
    v23 = 0i64;
  if ( *(_QWORD *)v23 )
    v24 = &v23[*(_QWORD *)v23];
  else
    v24 = 0i64;
  v25 = *((_QWORD *)v24 + 4);
  if ( v25 )
    v26 = (UFG::RoadNetworkConnection *)&v24[v25 + 32];
  else
    v26 = 0i64;
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v26, *((unsigned __int16 *)v23 + 19));
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, m_LaneT, &laneT);
  v29 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v29, laneT, *((float *)v23 + 10));
  y = result.y;
  this->m_Position.x = result.x;
  z = result.z;
  this->m_Position.y = y;
  this->m_Position.z = z;
  v32 = this->m_CurrentLocation.m_CurrentLane;
  this->m_Parked = 0;
  if ( v32->mNode.mOffset )
    v33 = (_WORD *)((char *)v32 + v32->mNode.mOffset);
  else
    v33 = 0i64;
  if ( !*v33 )
  {
    if ( v32->mNode.mOffset )
      v5 = (float *)((char *)v32 + v32->mNode.mOffset);
    this->m_SpeedLimit = v5[41];
  }
}

// File Line: 455
// RVA: 0xD2FD0
bool __fastcall UFG::RoadNetworkGuide::CanChangeLane(UFG::RoadNetworkGuide *this, unsigned int laneChangeDir)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rsi
  char *v3; // rdi
  char *v4; // r8
  UFG::RoadNetworkLane *v5; // rax
  char *v6; // rax
  int v8; // ebx

  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  v3 = 0i64;
  v4 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  if ( !m_CurrentLane->mNode.mOffset )
    v4 = 0i64;
  v5 = this->m_TargetLocation.m_CurrentLane;
  if ( v5->mNode.mOffset )
    v6 = (char *)v5 + v5->mNode.mOffset;
  else
    v6 = 0i64;
  if ( v4 != v6 )
    return 0;
  if ( m_CurrentLane->mNode.mOffset )
    v3 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  if ( !m_CurrentLane || !v3 || *(_WORD *)v3 == 1 )
    return 0;
  if ( !laneChangeDir )
    return 1;
  v8 = -1;
  if ( laneChangeDir == 1 )
    v8 = 1;
  if ( UFG::RoadNetworkLane::IsReversedInNode(m_CurrentLane) )
    v8 = -v8;
  return v8 + (unsigned int)m_CurrentLane->mLaneIndex < (unsigned __int8)v3[40];
}

// File Line: 481
// RVA: 0xD3180
void __fastcall UFG::RoadNetworkGuide::ChangeLane(UFG::RoadNetworkGuide *this, unsigned int direction)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  __int64 mOffset; // rcx
  UFG::RoadNetworkLane *v6; // rax
  char *v7; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mPrev; // rcx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mNext; // rax
  UFG::RoadNetworkLane *v10; // rcx

  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  mOffset = m_CurrentLane->mNode.mOffset;
  if ( m_CurrentLane->mNode.mOffset )
    mOffset += (__int64)m_CurrentLane;
  v6 = this->m_TargetLocation.m_CurrentLane;
  if ( v6->mNode.mOffset )
    v7 = (char *)v6 + v6->mNode.mOffset;
  else
    v7 = 0i64;
  if ( (char *)mOffset == v7 )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
    this->mNext = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
    UFG::RoadNetworkLocation::ChangeLane(&this->m_CurrentLocation, direction);
    UFG::RoadNetworkLocation::ChangeLane(&this->m_TargetLocation, direction);
    v10 = this->m_CurrentLocation.m_CurrentLane;
    if ( v10 )
      UFG::RoadNetworkLane::AddCarGuide(v10, this, 1);
    this->m_NextLane = 0i64;
  }
}

// File Line: 504
// RVA: 0xD3350
char __fastcall UFG::RoadNetworkGuide::ChangeLaneIfRoom(UFG::RoadNetworkGuide *this, unsigned int direction)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rsi
  __int64 mOffset; // rax
  UFG::RoadNetworkLane *v6; // rbx
  char *v7; // r15
  int v8; // eax
  UFG::RoadNetworkLane *v9; // r12
  bool v10; // zf
  __int64 v11; // rax
  _WORD *v12; // rax
  __int64 v13; // rsi
  unsigned int v14; // edx
  bool IsReversedInNode; // al
  int v16; // ecx
  __int64 v17; // rax
  char *v18; // rcx
  char *v19; // rdx
  UFG::RoadNetworkLane *v20; // rdx
  UFG::RoadNetworkLane *v21; // r12
  _WORD *v22; // rax
  bool v23; // al
  int v24; // ecx
  __int64 v25; // rax
  char *v26; // rcx
  __int64 v27; // rax
  unsigned int v28; // edx
  _WORD *v29; // rax
  int v30; // r14d
  __int64 v31; // rsi
  unsigned int v32; // edx
  bool v33; // al
  int v34; // ecx
  __int64 v35; // rax
  char *v36; // rcx
  char *v37; // rdx
  UFG::RoadNetworkLane *v38; // rdx
  UFG::RoadNetworkLane *v39; // r12
  _WORD *v40; // rax
  __int64 v41; // rax
  char *v42; // rcx
  __int64 v43; // rax
  _WORD *v44; // rax
  __int64 v45; // rsi
  int v46; // r14d
  bool v47; // al
  int mLaneIndex; // esi
  __int64 v49; // rax
  char *v50; // rcx
  __int64 v51; // rax
  _WORD *v52; // rax
  __int64 v53; // rsi
  bool v54; // al
  int v55; // esi
  int v56; // ecx
  __int64 v57; // rax
  char *v58; // rcx
  __int64 v59; // rax

  if ( !direction )
    return 0;
  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  mOffset = m_CurrentLane->mNode.mOffset;
  v6 = 0i64;
  v7 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  if ( !m_CurrentLane->mNode.mOffset )
    v7 = 0i64;
  if ( direction > 2 )
  {
    v8 = UFG::qRandom(2, &UFG::qDefaultSeed);
    v9 = this->m_CurrentLocation.m_CurrentLane;
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
        IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(this->m_CurrentLocation.m_CurrentLane);
        v16 = -1;
        if ( IsReversedInNode )
          v16 = 1;
        v14 = v16 + v9->mLaneIndex;
      }
      v17 = *((_QWORD *)v7 + 6);
      if ( v17 )
        v18 = &v7[v17 + 48];
      else
        v18 = 0i64;
      v19 = &v18[8 * v14];
      if ( *(_QWORD *)v19 )
        v20 = (UFG::RoadNetworkLane *)&v19[*(_QWORD *)v19];
      else
        v20 = 0i64;
      if ( !UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(this, v20) )
      {
        v21 = this->m_CurrentLocation.m_CurrentLane;
        if ( v21->mNode.mOffset )
          v22 = (_WORD *)((char *)v21 + v21->mNode.mOffset);
        else
          v22 = 0i64;
        if ( *v22 != 1 )
        {
          v23 = UFG::RoadNetworkLane::IsReversedInNode(this->m_CurrentLocation.m_CurrentLane);
          v24 = 1;
          if ( v23 )
            v24 = -1;
          v13 = v24 + (unsigned int)v21->mLaneIndex;
        }
        v25 = *((_QWORD *)v7 + 6);
        if ( v25 )
          v26 = &v7[v25 + 48];
        else
          v26 = 0i64;
        v27 = *(_QWORD *)&v26[8 * v13];
        if ( v27 )
          v6 = (UFG::RoadNetworkLane *)&v26[8 * v13 + v27];
        if ( UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(this, v6) )
        {
LABEL_35:
          v28 = 1;
LABEL_36:
          UFG::RoadNetworkGuide::ChangeLane(this, v28);
          return 1;
        }
        return 0;
      }
    }
    else
    {
      if ( v11 )
        v29 = (_WORD *)((char *)v9 + v11);
      else
        v29 = 0i64;
      v30 = -1;
      v31 = 0xFFFFFFFFi64;
      if ( *v29 == 1 )
      {
        v32 = -1;
      }
      else
      {
        v33 = UFG::RoadNetworkLane::IsReversedInNode(this->m_CurrentLocation.m_CurrentLane);
        v34 = 1;
        if ( v33 )
          v34 = -1;
        v32 = v34 + v9->mLaneIndex;
      }
      v35 = *((_QWORD *)v7 + 6);
      if ( v35 )
        v36 = &v7[v35 + 48];
      else
        v36 = 0i64;
      v37 = &v36[8 * v32];
      if ( *(_QWORD *)v37 )
        v38 = (UFG::RoadNetworkLane *)&v37[*(_QWORD *)v37];
      else
        v38 = 0i64;
      if ( UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(this, v38) )
        goto LABEL_35;
      v39 = this->m_CurrentLocation.m_CurrentLane;
      if ( v39->mNode.mOffset )
        v40 = (_WORD *)((char *)v39 + v39->mNode.mOffset);
      else
        v40 = 0i64;
      if ( *v40 != 1 )
      {
        if ( UFG::RoadNetworkLane::IsReversedInNode(this->m_CurrentLocation.m_CurrentLane) )
          v30 = 1;
        v31 = v30 + (unsigned int)v39->mLaneIndex;
      }
      v41 = *((_QWORD *)v7 + 6);
      if ( v41 )
        v42 = &v7[v41 + 48];
      else
        v42 = 0i64;
      v43 = *(_QWORD *)&v42[8 * v31];
      if ( v43 )
        v6 = (UFG::RoadNetworkLane *)&v42[8 * v31 + v43];
      if ( !UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(this, v6) )
        return 0;
    }
    v28 = 2;
    goto LABEL_36;
  }
  if ( direction == 2 )
  {
    if ( mOffset )
      v44 = (_WORD *)((char *)m_CurrentLane + mOffset);
    else
      v44 = 0i64;
    if ( *v44 == 1 )
    {
      v45 = 0xFFFFFFFFi64;
    }
    else
    {
      v46 = -1;
      v47 = UFG::RoadNetworkLane::IsReversedInNode(m_CurrentLane);
      mLaneIndex = m_CurrentLane->mLaneIndex;
      if ( v47 )
        v46 = 1;
      v45 = (unsigned int)(v46 + mLaneIndex);
    }
    v49 = *((_QWORD *)v7 + 6);
    if ( v49 )
      v50 = &v7[v49 + 48];
    else
      v50 = 0i64;
    v51 = *(_QWORD *)&v50[8 * v45];
    if ( v51 )
      v6 = (UFG::RoadNetworkLane *)&v50[8 * v45 + v51];
    if ( UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(this, v6) )
    {
      UFG::RoadNetworkGuide::ChangeLane(this, 2u);
      return 1;
    }
  }
  else
  {
    if ( mOffset )
      v52 = (_WORD *)((char *)m_CurrentLane + mOffset);
    else
      v52 = 0i64;
    if ( *v52 == 1 )
    {
      v53 = 0xFFFFFFFFi64;
    }
    else
    {
      v54 = UFG::RoadNetworkLane::IsReversedInNode(m_CurrentLane);
      v55 = m_CurrentLane->mLaneIndex;
      v56 = 1;
      if ( v54 )
        v56 = -1;
      v53 = (unsigned int)(v56 + v55);
    }
    v57 = *((_QWORD *)v7 + 6);
    if ( v57 )
      v58 = &v7[v57 + 48];
    else
      v58 = 0i64;
    v59 = *(_QWORD *)&v58[8 * v53];
    if ( v59 )
      v6 = (UFG::RoadNetworkLane *)&v58[8 * v53 + v59];
    if ( UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(this, v6) )
    {
      UFG::RoadNetworkGuide::ChangeLane(this, 1u);
      return 1;
    }
  }
  return 0;
}

// File Line: 598
// RVA: 0xD5EF0
__int64 __fastcall UFG::RoadNetworkGuide::GetChangeLaneIndex(UFG::RoadNetworkGuide *this, unsigned int direction)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rdi
  _WORD *mOffset; // rax
  int v5; // ebx
  UFG::RoadNetworkLane *v6; // rcx

  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  mOffset = (_WORD *)m_CurrentLane->mNode.mOffset;
  if ( m_CurrentLane->mNode.mOffset )
    mOffset = (_WORD *)((char *)mOffset + (_QWORD)m_CurrentLane);
  if ( *mOffset == 1 )
    return 0xFFFFFFFFi64;
  v5 = -1;
  v6 = this->m_CurrentLocation.m_CurrentLane;
  if ( direction == 1 )
    v5 = 1;
  if ( UFG::RoadNetworkLane::IsReversedInNode(v6) )
    v5 = -v5;
  return v5 + (unsigned int)m_CurrentLane->mLaneIndex;
}

// File Line: 620
// RVA: 0xE0CA0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkGuide::TryGetPossibleSharedDestination(
        UFG::RoadNetworkGuide *this,
        unsigned int laneIndex,
        unsigned __int8 laneFlags)
{
  UFG::RoadNetworkLane *m_NextLane; // rax
  __int64 mOffset; // rcx
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rsi
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  char *v10; // rax
  __int64 v11; // rcx
  char *v12; // rcx
  char *v13; // rdx
  char *v14; // rdi
  __int64 v15; // rax
  char *v16; // rbx
  int v17; // edx
  __int64 *v18; // rbx
  __int64 v19; // r9
  char *v20; // rcx
  char *v21; // r8
  char *v22; // rax
  __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rcx
  __int64 v26; // r8
  UFG::qArray<unsigned long,0> laneIDs; // [rsp+28h] [rbp-20h] BYREF

  m_NextLane = this->m_NextLane;
  if ( !m_NextLane )
    return 0i64;
  mOffset = m_NextLane->mEndGate.mOffset;
  v6 = mOffset ? (__int64)&m_NextLane->mEndGate + mOffset : 0i64;
  v7 = *(_QWORD *)(v6 + 8);
  if ( !v7 )
    return 0i64;
  v8 = v7 + v6 + 8;
  if ( !v8 )
    return 0i64;
  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  if ( m_CurrentLane->mNode.mOffset )
    v10 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  else
    v10 = 0i64;
  v11 = *((_QWORD *)v10 + 6);
  if ( v11 )
    v12 = &v10[v11 + 48];
  else
    v12 = 0i64;
  v13 = &v12[8 * laneIndex];
  v14 = &v13[*(_QWORD *)v13];
  if ( !*(_QWORD *)v13 )
    v14 = 0i64;
  v15 = *((_QWORD *)v14 + 13);
  if ( !v15 )
    return 0i64;
  v16 = &v14[v15 + 104];
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
      v24 = v23 ? (__int64)&v22[v23 + 16] : 0i64;
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
  UFG::qSafePointer<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *p_m_NextGuide; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::RoadNetworkLane *m_CurrentLane; // r15
  __int64 mOffset; // rcx
  float v7; // xmm13_4
  __int64 v8; // rax
  UFG::RoadNetworkConnection *v9; // rcx
  UFG::RoadNetworkLane *Path; // rax
  UFG::RoadNetworkGuide *p_mNext; // rbx
  float v12; // xmm12_4
  UFG::RoadNetworkLane *v13; // rax
  __int64 v14; // rcx
  unsigned int mPathIndex; // edx
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
  char *v26; // rcx
  char *v27; // rax
  __int64 v28; // rcx
  UFG::RoadNetworkLane *v29; // r14
  __int64 v30; // rdi
  __int64 v31; // rcx
  __int64 v32; // rax
  unsigned int v33; // edx
  UFG::RoadNetworkConnection *v34; // rcx
  float v35; // xmm6_4
  __int64 v36; // rax
  float v37; // xmm7_4
  UFG::RoadNetworkConnection *v38; // rcx
  UFG::qBezierPathMemImaged *v39; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v41; // rax
  __int64 v42; // rax
  UFG::RoadNetworkConnection *v43; // rcx
  UFG::qBezierPathMemImaged *v44; // rbx
  unsigned int v45; // eax
  UFG::qBezierSplineMemImaged *v46; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v47; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v48; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v49; // rax
  __int64 v50; // rax
  unsigned int *v51; // rcx
  __int64 v52; // r13
  __int64 v53; // rax
  char *v54; // rcx
  char *v55; // rax
  __int64 v56; // rcx
  UFG::RoadNetworkLane *v57; // r14
  __int64 v58; // rdi
  __int64 v59; // rcx
  __int64 v60; // rax
  unsigned int v61; // edx
  UFG::RoadNetworkConnection *v62; // rcx
  float v63; // xmm8_4
  __int64 v64; // rax
  float v65; // xmm9_4
  UFG::RoadNetworkConnection *v66; // rcx
  UFG::qBezierPathMemImaged *v67; // rbx
  unsigned int v68; // eax
  UFG::qBezierSplineMemImaged *v69; // rcx
  float v70; // xmm6_4
  int v71; // xmm3_4
  float v72; // xmm1_4
  float v73; // xmm2_4
  float y; // xmm1_4
  UFG::qVector3 *v75; // rax
  float z; // xmm2_4
  __int64 v77; // rax
  UFG::RoadNetworkConnection *v78; // rcx
  UFG::qBezierPathMemImaged *v79; // rbx
  unsigned int v80; // eax
  UFG::qBezierSplineMemImaged *v81; // rcx
  float v82; // xmm6_4
  int v83; // xmm2_4
  float v84; // xmm1_4
  float v85; // xmm1_4
  float v86; // xmm4_4
  float v87; // xmm5_4
  float x; // xmm3_4
  UFG::qVector3 *v89; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v90; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v91; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v92; // rax
  UFG::RoadNetworkLane *v93; // rax
  __int64 v94; // rcx
  UFG::qOffset64<UFG::RoadNetworkConnection *> *p_mNextConnection; // rax
  unsigned int *v96; // r14
  __int64 v97; // rdi
  __int64 v98; // r15
  __int64 v99; // rax
  char *v100; // rcx
  char *v101; // rax
  __int64 v102; // rcx
  char *v103; // rbx
  __int64 v104; // rbx
  __int64 v105; // rax
  __int64 v106; // rcx
  unsigned int v107; // edx
  __int64 v108; // rax
  UFG::RoadNetworkConnection *v109; // rcx
  float v110; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v111; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v112; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *v113; // rax
  unsigned int *v114; // [rsp+20h] [rbp-E0h]
  UFG::qVector3 position; // [rsp+28h] [rbp-D8h] BYREF
  UFG::qVector3 result; // [rsp+38h] [rbp-C8h] BYREF
  UFG::qVector3 tangent; // [rsp+48h] [rbp-B8h] BYREF
  UFG::qVector3 v118; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qVector3 v119; // [rsp+68h] [rbp-98h] BYREF
  UFG::qVector3 v120; // [rsp+74h] [rbp-8Ch] BYREF
  float splineT; // [rsp+168h] [rbp+68h] BYREF
  float t; // [rsp+170h] [rbp+70h] BYREF
  __int64 v124; // [rsp+178h] [rbp+78h]

  p_m_NextGuide = &this->m_NextGuide;
  if ( this->m_NextGuide.m_pPointer )
  {
    mPrev = p_m_NextGuide->mPrev;
    mNext = this->m_NextGuide.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_NextGuide->mPrev = p_m_NextGuide;
    this->m_NextGuide.mNext = &this->m_NextGuide;
  }
  this->m_NextGuide.m_pPointer = 0i64;
  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  if ( m_CurrentLane )
  {
    mOffset = m_CurrentLane->mNode.mOffset;
    v7 = FLOAT_3_4028235e38;
    if ( m_CurrentLane->mNode.mOffset )
      mOffset += (__int64)m_CurrentLane;
    v8 = *(_QWORD *)(mOffset + 32);
    if ( v8 )
      v9 = (UFG::RoadNetworkConnection *)(v8 + mOffset + 32);
    else
      v9 = 0i64;
    Path = UFG::qBezierPathCollectionMemImaged::GetPath(v9, m_CurrentLane->mPathIndex);
    p_mNext = (UFG::RoadNetworkGuide *)&m_CurrentLane->mCars.mNode.mNext[-2].mNext;
    v12 = *((float *)&Path->mNode.mOffset + 1) * this->m_CurrentLocation.m_LaneT;
    if ( p_mNext != (UFG::RoadNetworkGuide *)&m_CurrentLane->mStartConnection )
    {
      while ( 1 )
      {
        if ( p_mNext != this )
        {
          v13 = p_mNext->m_CurrentLocation.m_CurrentLane;
          v14 = v13->mNode.mOffset;
          if ( v13->mNode.mOffset )
            v14 += (__int64)v13;
          mPathIndex = v13->mPathIndex;
          v16 = *(_QWORD *)(v14 + 32);
          v17 = v16 ? (UFG::RoadNetworkConnection *)(v16 + v14 + 32) : 0i64;
          v18 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v17, mPathIndex)->mNode.mOffset + 1)
              * p_mNext->m_CurrentLocation.m_LaneT;
          if ( v18 > v12 )
            break;
        }
        p_mNext = (UFG::RoadNetworkGuide *)&p_mNext->mNext[-2].mNext;
        if ( p_mNext == (UFG::RoadNetworkGuide *)&m_CurrentLane->mStartConnection )
          goto LABEL_24;
      }
      if ( p_m_NextGuide->m_pPointer )
      {
        v19 = p_m_NextGuide->mPrev;
        v20 = p_m_NextGuide->mNext;
        v19->mNext = v20;
        v20->mPrev = v19;
        p_m_NextGuide->mPrev = p_m_NextGuide;
        p_m_NextGuide->mNext = p_m_NextGuide;
      }
      p_m_NextGuide->m_pPointer = p_mNext;
      if ( p_mNext )
      {
        v21 = p_mNext->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::RoadNetworkGuide>::mPrev;
        v21->mNext = p_m_NextGuide;
        p_m_NextGuide->mPrev = v21;
        p_m_NextGuide->mNext = &p_mNext->m_SafePointerList.mNode;
        p_mNext->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::RoadNetworkGuide>::mPrev = p_m_NextGuide;
      }
      v7 = v18;
    }
LABEL_24:
    v22 = m_CurrentLane->mStartConnection.mOffset;
    if ( v22 )
      v23 = (unsigned int *)((char *)&m_CurrentLane->mStartConnection + v22);
    else
      v23 = 0i64;
    if ( *v23 )
    {
      v24 = 0i64;
      v124 = *v23;
      do
      {
        v25 = *((_QWORD *)v23 + 1);
        if ( v25 )
          v26 = (char *)v23 + v25 + 8;
        else
          v26 = 0i64;
        v27 = &v26[v24];
        v28 = *(_QWORD *)&v26[v24];
        if ( v28 )
          v29 = (UFG::RoadNetworkLane *)&v27[v28];
        else
          v29 = 0i64;
        if ( m_CurrentLane != v29 )
        {
          v30 = (__int64)&v29->mCars.mNode.mNext[-2].mNext;
          if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v30 != &v29->mStartConnection )
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
              if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v30 == &v29->mStartConnection )
                goto LABEL_57;
            }
            v36 = v29->mNode.mOffset;
            v37 = *(float *)(v30 + 56);
            if ( v29->mNode.mOffset )
              v36 += (__int64)v29;
            v38 = *(UFG::RoadNetworkConnection **)(v36 + 32);
            if ( v38 )
              v38 = (UFG::RoadNetworkConnection *)((char *)v38 + v36 + 32);
            v39 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v38, v29->mPathIndex);
            SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(v39, v37, &splineT);
            v41 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                   (UFG::RoadNetworkConnection *)v39,
                                                   SplineParameters);
            UFG::RoadNetworkLane::GetOffsetPos(&result, v41, splineT, v29->mOffset);
            v42 = m_CurrentLane->mNode.mOffset;
            if ( m_CurrentLane->mNode.mOffset )
              v42 += (__int64)m_CurrentLane;
            v43 = *(UFG::RoadNetworkConnection **)(v42 + 32);
            if ( v43 )
              v43 = (UFG::RoadNetworkConnection *)((char *)v43 + v42 + 32);
            v44 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                 v43,
                                                 m_CurrentLane->mPathIndex);
            v45 = UFG::qBezierPathMemImaged::GetSplineParameters(v44, v37, &t);
            v46 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                   (UFG::RoadNetworkConnection *)v44,
                                                   v45);
            UFG::RoadNetworkLane::GetOffsetPos(&position, v46, t, m_CurrentLane->mOffset);
            if ( (float)((float)((float)((float)(result.y - position.y) * (float)(result.y - position.y))
                               + (float)((float)(result.x - position.x) * (float)(result.x - position.x)))
                       + (float)((float)(result.z - position.z) * (float)(result.z - position.z))) < 10.240001
              && v35 < v7 )
            {
              if ( p_m_NextGuide->m_pPointer )
              {
                v47 = p_m_NextGuide->mPrev;
                v48 = p_m_NextGuide->mNext;
                v47->mNext = v48;
                v48->mPrev = v47;
                p_m_NextGuide->mPrev = p_m_NextGuide;
                p_m_NextGuide->mNext = p_m_NextGuide;
              }
              p_m_NextGuide->m_pPointer = (UFG::RoadNetworkGuide *)v30;
              v49 = *(UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> **)(v30 + 8);
              v7 = v35;
              v49->mNext = p_m_NextGuide;
              p_m_NextGuide->mPrev = v49;
              p_m_NextGuide->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)(v30 + 8);
              *(_QWORD *)(v30 + 8) = p_m_NextGuide;
            }
          }
        }
LABEL_57:
        v24 += 8i64;
        --v124;
      }
      while ( v124 );
    }
    v50 = m_CurrentLane->mEndConnection.mOffset;
    if ( v50 )
      v51 = (unsigned int *)((char *)&m_CurrentLane->mEndConnection + v50);
    else
      v51 = 0i64;
    v114 = v51;
    if ( *v51 )
    {
      v52 = 0i64;
      v124 = *v51;
      do
      {
        v53 = *((_QWORD *)v51 + 1);
        if ( v53 )
          v54 = (char *)v51 + v53 + 8;
        else
          v54 = 0i64;
        v55 = &v54[v52];
        v56 = *(_QWORD *)&v54[v52];
        if ( v56 )
          v57 = (UFG::RoadNetworkLane *)&v55[v56];
        else
          v57 = 0i64;
        if ( m_CurrentLane != v57 )
        {
          v58 = (__int64)&v57->mCars.mNode.mNext[-2].mNext;
          if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v58 != &v57->mStartConnection )
          {
            while ( 1 )
            {
              v59 = *(_QWORD *)(v58 + 64);
              v60 = *(_QWORD *)v59;
              if ( *(_QWORD *)v59 )
                v60 += v59;
              v61 = *(unsigned __int16 *)(v59 + 38);
              v62 = *(UFG::RoadNetworkConnection **)(v60 + 32);
              if ( v62 )
                v62 = (UFG::RoadNetworkConnection *)((char *)v62 + v60 + 32);
              v63 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v62, v61)->mNode.mOffset + 1)
                  * *(float *)(v58 + 56);
              if ( v63 > v12 )
              {
                v64 = v57->mNode.mOffset;
                v65 = *(float *)(v58 + 56);
                if ( v57->mNode.mOffset )
                  v64 += (__int64)v57;
                v66 = *(UFG::RoadNetworkConnection **)(v64 + 32);
                if ( v66 )
                  v66 = (UFG::RoadNetworkConnection *)((char *)v66 + v64 + 32);
                v67 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v66, v57->mPathIndex);
                v68 = UFG::qBezierPathMemImaged::GetSplineParameters(v67, v65, &splineT);
                v69 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                       (UFG::RoadNetworkConnection *)v67,
                                                       v68);
                v70 = v57->mOffset;
                if ( v70 == 0.0 )
                {
                  v75 = UFG::qBezierSplineMemImaged::GetPosition(v69, &v119, splineT);
                  z = v75->z;
                  y = v75->y;
                  position.x = v75->x;
                  position.z = z;
                }
                else
                {
                  UFG::qBezierSplineMemImaged::GetPositionAndTangent(v69, splineT, &position, &tangent);
                  v71 = LODWORD(tangent.x) ^ _xmm[0];
                  v72 = (float)(*(float *)&v71 * *(float *)&v71) + (float)(tangent.y * tangent.y);
                  if ( v72 == 0.0 )
                    v73 = 0.0;
                  else
                    v73 = 1.0 / fsqrt(v72);
                  position.x = position.x + (float)((float)(v73 * tangent.y) * v70);
                  y = position.y + (float)((float)(*(float *)&v71 * v73) * v70);
                  position.z = position.z + (float)((float)(v73 * 0.0) * v70);
                }
                v77 = m_CurrentLane->mNode.mOffset;
                position.y = y;
                if ( v77 )
                  v77 += (__int64)m_CurrentLane;
                v78 = *(UFG::RoadNetworkConnection **)(v77 + 32);
                if ( v78 )
                  v78 = (UFG::RoadNetworkConnection *)((char *)v78 + v77 + 32);
                v79 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                     v78,
                                                     m_CurrentLane->mPathIndex);
                v80 = UFG::qBezierPathMemImaged::GetSplineParameters(v79, v65, &t);
                v81 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                       (UFG::RoadNetworkConnection *)v79,
                                                       v80);
                v82 = m_CurrentLane->mOffset;
                if ( v82 == 0.0 )
                {
                  v89 = UFG::qBezierSplineMemImaged::GetPosition(v81, &v120, t);
                  v86 = v89->y;
                  v87 = v89->z;
                  x = v89->x;
                }
                else
                {
                  UFG::qBezierSplineMemImaged::GetPositionAndTangent(v81, t, &result, &v118);
                  v83 = LODWORD(v118.x) ^ _xmm[0];
                  v84 = (float)(*(float *)&v83 * *(float *)&v83) + (float)(v118.y * v118.y);
                  v85 = v84 == 0.0 ? 0.0 : 1.0 / fsqrt(v84);
                  v86 = result.y + (float)((float)(*(float *)&v83 * v85) * v82);
                  v87 = result.z + (float)((float)(v85 * 0.0) * v82);
                  x = result.x + (float)((float)(v85 * v118.y) * v82);
                }
                result.z = v87;
                result.y = v86;
                result.x = x;
                if ( (float)((float)((float)((float)(position.x - x) * (float)(position.x - x))
                                   + (float)((float)(position.y - v86) * (float)(position.y - v86)))
                           + (float)((float)(position.z - v87) * (float)(position.z - v87))) < 10.240001 )
                  break;
              }
              v58 = *(_QWORD *)(v58 + 32) - 24i64;
              if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v58 == &v57->mStartConnection )
                goto LABEL_103;
            }
            if ( v63 < v7 )
            {
              if ( p_m_NextGuide->m_pPointer )
              {
                v90 = p_m_NextGuide->mPrev;
                v91 = p_m_NextGuide->mNext;
                v90->mNext = v91;
                v91->mPrev = v90;
                p_m_NextGuide->mPrev = p_m_NextGuide;
                p_m_NextGuide->mNext = p_m_NextGuide;
              }
              p_m_NextGuide->m_pPointer = (UFG::RoadNetworkGuide *)v58;
              v92 = *(UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> **)(v58 + 8);
              v7 = v63;
              v92->mNext = p_m_NextGuide;
              p_m_NextGuide->mPrev = v92;
              p_m_NextGuide->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)(v58 + 8);
              *(_QWORD *)(v58 + 8) = p_m_NextGuide;
            }
          }
        }
LABEL_103:
        v51 = v114;
        v52 += 8i64;
        --v124;
      }
      while ( v124 );
    }
    if ( !this->m_NextGuide.m_pPointer )
    {
      v93 = this->m_CurrentLocation.m_CurrentLane;
      v94 = v93->mNextConnection.mOffset;
      p_mNextConnection = &v93->mNextConnection;
      if ( v94 )
      {
        v96 = (unsigned int *)((char *)p_mNextConnection + v94);
        if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)((char *)p_mNextConnection + v94) )
        {
          if ( *v96 )
          {
            v97 = 0i64;
            v98 = *v96;
            do
            {
              v99 = *((_QWORD *)v96 + 1);
              if ( v99 )
                v100 = (char *)v96 + v99 + 8;
              else
                v100 = 0i64;
              v101 = &v100[v97];
              v102 = *(_QWORD *)&v100[v97];
              if ( v102 )
                v103 = &v101[v102];
              else
                v103 = 0i64;
              if ( (char *)(*((_QWORD *)v103 + 15) - 24i64) != v103 + 88 )
              {
                v104 = *((_QWORD *)v103 + 15) - 24i64;
                if ( v104 )
                {
                  v105 = *(_QWORD *)(v104 + 64);
                  v106 = *(_QWORD *)v105;
                  if ( *(_QWORD *)v105 )
                    v106 += v105;
                  v107 = *(unsigned __int16 *)(v105 + 38);
                  v108 = *(_QWORD *)(v106 + 32);
                  if ( v108 )
                    v109 = (UFG::RoadNetworkConnection *)(v108 + v106 + 32);
                  else
                    v109 = 0i64;
                  v110 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v109, v107)->mNode.mOffset + 1)
                       * *(float *)(v104 + 56);
                  if ( v110 < v7 )
                  {
                    if ( p_m_NextGuide->m_pPointer )
                    {
                      v111 = p_m_NextGuide->mPrev;
                      v112 = p_m_NextGuide->mNext;
                      v111->mNext = v112;
                      v112->mPrev = v111;
                      p_m_NextGuide->mPrev = p_m_NextGuide;
                      p_m_NextGuide->mNext = p_m_NextGuide;
                    }
                    p_m_NextGuide->m_pPointer = (UFG::RoadNetworkGuide *)v104;
                    v113 = *(UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> **)(v104 + 8);
                    v7 = v110;
                    v113->mNext = p_m_NextGuide;
                    p_m_NextGuide->mPrev = v113;
                    p_m_NextGuide->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RoadNetworkGuide>,UFG::qSafePointerNodeList> *)(v104 + 8);
                    *(_QWORD *)(v104 + 8) = p_m_NextGuide;
                  }
                }
              }
              v97 += 8i64;
              --v98;
            }
            while ( v98 );
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
  UFG::RoadNetworkLane *m_CurrentLane; // r8
  char *v5; // rcx
  UFG::RoadNetworkLane *v6; // r9

  v2 = 0i64;
  if ( whichLanes )
    *whichLanes = 0;
  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  v5 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  if ( !m_CurrentLane->mNode.mOffset )
    v5 = 0i64;
  v6 = this->m_TargetLocation.m_CurrentLane;
  if ( v6->mNode.mOffset )
    v2 = (char *)v6 + v6->mNode.mOffset;
  return v5 == v2 && UFG::RoadNetworkLane::LaneChangeAvailable(m_CurrentLane, whichLanes);
}

// File Line: 787
// RVA: 0xD8270
void __fastcall UFG::RoadNetworkGuide::GetCornerRays(
        UFG::RoadNetworkGuide *this,
        UFG::qVector3 *corners,
        UFG::qVector3 *p_left)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  float v7; // xmm15_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  __m128 z_low; // xmm13
  UFG::RoadNetworkLane *v11; // rax
  UFG::RoadNetworkConnection *v12; // r8
  char *v13; // rcx
  __int64 mLaneIndex; // r9
  __int64 v15; // rax
  float m_LaneT; // xmm8_4
  char *v17; // rdx
  __int64 v18; // rax
  char *v19; // r9
  char *v20; // rax
  unsigned int v21; // edx
  __int64 v22; // rax
  UFG::qBezierPathMemImaged *Path; // rax
  UFG::RoadNetworkConnection *v24; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v26; // rax
  __m128 x_low; // xmm2
  float v28; // xmm1_4
  float v29; // xmm14_4
  __m128 v30; // xmm9
  float v31; // xmm12_4
  __m128 v32; // xmm2
  float v33; // xmm7_4
  float v34; // xmm14_4
  float v35; // xmm9_4
  int v36; // xmm0_4
  float v37; // xmm12_4
  float v38; // xmm8_4
  float v39; // xmm7_4
  float v40; // xmm6_4
  float m_FrontBoundary; // xmm0_4
  float v42; // xmm10_4
  float v43; // xmm11_4
  float v44; // xmm13_4
  UFG::qVector3 result; // [rsp+20h] [rbp-B8h] BYREF
  float splineT; // [rsp+E0h] [rbp+8h] BYREF

  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  v7 = this->m_ObjectWidth * 0.5;
  v8 = *(float *)&FLOAT_1_0;
  v9 = 0.0;
  z_low = 0i64;
  if ( m_CurrentLane
    && m_CurrentLane->mNode.mOffset
    && (UFG::RoadNetworkLane *)((char *)m_CurrentLane + m_CurrentLane->mNode.mOffset) )
  {
    v11 = this->m_CurrentLocation.m_CurrentLane;
    v12 = 0i64;
    if ( v11->mNode.mOffset )
      v13 = (char *)v11 + v11->mNode.mOffset;
    else
      v13 = 0i64;
    mLaneIndex = v11->mLaneIndex;
    v15 = *((_QWORD *)v13 + 6);
    m_LaneT = this->m_CurrentLocation.m_LaneT;
    if ( v15 )
      v17 = &v13[v15 + 48];
    else
      v17 = 0i64;
    v18 = *(_QWORD *)&v17[8 * mLaneIndex];
    v19 = &v17[8 * mLaneIndex];
    if ( v18 )
      v20 = &v19[v18];
    else
      v20 = 0i64;
    v21 = *((unsigned __int16 *)v20 + 19);
    v22 = *((_QWORD *)v13 + 4);
    if ( v22 )
      v12 = (UFG::RoadNetworkConnection *)&v13[v22 + 32];
    Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v12, v21);
    splineT = 0.0;
    v24 = (UFG::RoadNetworkConnection *)Path;
    SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, m_LaneT, &splineT);
    v26 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v24, SplineParameters);
    UFG::qBezierSplineMemImaged::GetTangent(v26, &result, splineT);
    z_low = (__m128)LODWORD(result.z);
    x_low = (__m128)LODWORD(result.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y))
                      + (float)(z_low.m128_f32[0] * z_low.m128_f32[0]);
    if ( x_low.m128_f32[0] == 0.0 )
      v28 = 0.0;
    else
      v28 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
    v8 = result.x * v28;
    v9 = result.y * v28;
    z_low.m128_f32[0] = result.z * v28;
  }
  v30 = z_low;
  v29 = v9 - (float)(z_low.m128_f32[0] * 0.0);
  v30.m128_f32[0] = (float)(z_low.m128_f32[0] * 0.0) - v8;
  v32 = v30;
  v31 = (float)(v8 * 0.0) - (float)(v9 * 0.0);
  v32.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v29 * v29)) + (float)(v31 * v31);
  if ( v32.m128_f32[0] == 0.0 )
    v33 = 0.0;
  else
    v33 = 1.0 / _mm_sqrt_ps(v32).m128_f32[0];
  v34 = v29 * v33;
  v35 = v30.m128_f32[0] * v33;
  v36 = LODWORD(this->m_RearBoundary) ^ _xmm[0];
  v37 = v31 * v33;
  v38 = v8 * *(float *)&v36;
  v39 = v9 * *(float *)&v36;
  v40 = z_low.m128_f32[0] * *(float *)&v36;
  m_FrontBoundary = this->m_FrontBoundary;
  v42 = v8 * m_FrontBoundary;
  v43 = v9 * m_FrontBoundary;
  v44 = z_low.m128_f32[0] * m_FrontBoundary;
  corners->x = (float)(v34 * v7) + v42;
  corners->y = (float)(v35 * v7) + v43;
  corners->z = (float)(v37 * v7) + v44;
  corners[1].x = v42 - (float)(v34 * v7);
  corners[1].y = v43 - (float)(v35 * v7);
  corners[1].z = v44 - (float)(v37 * v7);
  corners[2].x = (float)(v34 * v7) + v38;
  corners[2].y = (float)(v35 * v7) + v39;
  corners[2].z = (float)(v37 * v7) + v40;
  corners[3].x = v38 - (float)(v34 * v7);
  corners[3].y = v39 - (float)(v35 * v7);
  corners[3].z = v40 - (float)(v37 * v7);
  if ( p_left )
  {
    p_left->x = v34;
    p_left->y = v35;
    p_left->z = v37;
  }
}

// File Line: 814
// RVA: 0xD8AD0
float __fastcall UFG::RoadNetworkGuide::GetGap(UFG::RoadNetworkGuide *this, UFG::RoadNetworkGuide *otherGuide)
{
  float v2; // xmm6_4
  __m128 y_low; // xmm7
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
  UFG::qVector3 p_left; // [rsp+20h] [rbp-81h] BYREF
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
  UFG::qVector3 corners; // [rsp+58h] [rbp-49h] BYREF
  float v29; // [rsp+64h] [rbp-3Dh]
  float v30; // [rsp+68h] [rbp-39h]
  float v31; // [rsp+6Ch] [rbp-35h]
  float v32; // [rsp+70h] [rbp-31h]
  float v33; // [rsp+74h] [rbp-2Dh]
  float v34; // [rsp+78h] [rbp-29h]
  float v35; // [rsp+7Ch] [rbp-25h]
  float v36; // [rsp+80h] [rbp-21h]
  float v37; // [rsp+84h] [rbp-1Dh]

  y_low = (__m128)LODWORD(otherGuide->m_Position.y);
  v2 = otherGuide->m_Position.x - this->m_Position.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->m_Position.y;
  v5 = otherGuide->m_Position.z - this->m_Position.z;
  v6 = y_low;
  v6.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v2 * v2)) + (float)(v5 * v5);
  v7 = _mm_sqrt_ps(v6).m128_f32[0];
  if ( v7 < 0.1 )
    return 0.0;
  v9 = 0.0;
  v10 = v2 * (float)(1.0 / v7);
  v11 = y_low.m128_f32[0] * (float)(1.0 / v7);
  v12 = 0.0;
  v13 = 0.0;
  v14 = v5 * (float)(1.0 / v7);
  UFG::RoadNetworkGuide::GetCornerRays(this, (UFG::qVector3 *)&p_left.z, &p_left);
  UFG::RoadNetworkGuide::GetCornerRays(otherGuide, &corners, 0i64);
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
    return v15;
  return v9;
}

// File Line: 850
// RVA: 0xE1300
void __fastcall UFG::RoadNetworkGuide::UpdateCurvature(UFG::RoadNetworkGuide *this)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rcx
  UFG::RoadNetworkConnection *v3; // rdi
  char *v4; // rax
  __int64 mLaneIndex; // rdx
  __int64 v6; // rcx
  float m_LaneT; // xmm6_4
  char *v8; // rcx
  __int64 v9; // rax
  char *v10; // rsi
  char *v11; // rax
  __int64 v12; // rcx
  UFG::RoadNetworkConnection *v13; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v16; // rax
  float v17; // xmm8_4
  float v18; // xmm7_4
  int v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  UFG::RoadNetworkLane *v22; // rcx
  char *v23; // rax
  __int64 v24; // rdx
  __int64 v25; // rcx
  float v26; // xmm8_4
  char *v27; // rcx
  __int64 v28; // rax
  char *v29; // rsi
  char *v30; // rax
  __int64 v31; // rcx
  UFG::qBezierPathMemImaged *v32; // rbx
  unsigned int v33; // eax
  UFG::qBezierSplineMemImaged *v34; // rax
  float v35; // xmm8_4
  int v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm1_4
  float x; // xmm0_4
  float y; // xmm3_4
  float z; // xmm4_4
  float v42; // xmm6_4
  float v43; // xmm0_4
  UFG::qVector3 v44; // [rsp+8h] [rbp-39h] BYREF
  UFG::qVector3 position; // [rsp+18h] [rbp-29h] BYREF
  UFG::qVector3 tangent; // [rsp+28h] [rbp-19h] BYREF
  UFG::qVector3 v2; // [rsp+38h] [rbp-9h] BYREF
  UFG::qVector3 v48; // [rsp+48h] [rbp+7h] BYREF
  float splineT; // [rsp+A8h] [rbp+67h] BYREF

  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  v3 = 0i64;
  if ( m_CurrentLane->mNode.mOffset )
    v4 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  else
    v4 = 0i64;
  mLaneIndex = m_CurrentLane->mLaneIndex;
  v6 = *((_QWORD *)v4 + 6);
  m_LaneT = this->m_CurrentLocation.m_LaneT;
  if ( v6 )
    v8 = &v4[v6 + 48];
  else
    v8 = 0i64;
  v9 = *(_QWORD *)&v8[8 * mLaneIndex];
  v10 = &v8[8 * mLaneIndex + v9];
  if ( !v9 )
    v10 = 0i64;
  if ( *(_QWORD *)v10 )
    v11 = &v10[*(_QWORD *)v10];
  else
    v11 = 0i64;
  v12 = *((_QWORD *)v11 + 4);
  if ( v12 )
    v13 = (UFG::RoadNetworkConnection *)&v11[v12 + 32];
  else
    v13 = 0i64;
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v13, *((unsigned __int16 *)v10 + 19));
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, m_LaneT, &splineT);
  v16 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  v17 = *((float *)v10 + 10);
  UFG::qBezierSplineMemImaged::GetPositionAndTangent(v16, splineT, &position, &tangent);
  v18 = *(float *)&FLOAT_1_0;
  if ( v17 != 0.0 )
  {
    v19 = LODWORD(tangent.x) ^ _xmm[0];
    v20 = (float)(*(float *)&v19 * *(float *)&v19) + (float)(tangent.y * tangent.y);
    if ( v20 == 0.0 )
      v21 = 0.0;
    else
      v21 = 1.0 / fsqrt(v20);
    position.x = position.x + (float)((float)(v21 * tangent.y) * v17);
    position.y = position.y + (float)((float)(*(float *)&v19 * v21) * v17);
    position.z = position.z + (float)((float)(v21 * 0.0) * v17);
  }
  v22 = this->m_TargetLocation.m_CurrentLane;
  if ( v22->mNode.mOffset )
    v23 = (char *)v22 + v22->mNode.mOffset;
  else
    v23 = 0i64;
  v24 = v22->mLaneIndex;
  v25 = *((_QWORD *)v23 + 6);
  v26 = this->m_TargetLocation.m_LaneT;
  if ( v25 )
    v27 = &v23[v25 + 48];
  else
    v27 = 0i64;
  v28 = *(_QWORD *)&v27[8 * v24];
  v29 = &v27[8 * v24 + v28];
  if ( !v28 )
    v29 = 0i64;
  if ( *(_QWORD *)v29 )
    v30 = &v29[*(_QWORD *)v29];
  else
    v30 = 0i64;
  v31 = *((_QWORD *)v30 + 4);
  if ( v31 )
    v3 = (UFG::RoadNetworkConnection *)&v30[v31 + 32];
  v32 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v3, *((unsigned __int16 *)v29 + 19));
  v33 = UFG::qBezierPathMemImaged::GetSplineParameters(v32, v26, &splineT);
  v34 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)v32,
                                         v33);
  v35 = *((float *)v29 + 10);
  UFG::qBezierSplineMemImaged::GetPositionAndTangent(v34, splineT, &v44, &v48);
  if ( v35 == 0.0 )
  {
    z = v44.z;
    y = v44.y;
    x = v44.x;
  }
  else
  {
    v36 = LODWORD(v48.x) ^ _xmm[0];
    v37 = (float)(*(float *)&v36 * *(float *)&v36) + (float)(v48.y * v48.y);
    if ( v37 == 0.0 )
      v38 = 0.0;
    else
      v38 = 1.0 / fsqrt(v37);
    x = v44.x + (float)((float)(v48.y * v38) * v35);
    v44.x = x;
    y = v44.y + (float)((float)(*(float *)&v36 * v38) * v35);
    z = v44.z + (float)((float)(v38 * 0.0) * v35);
    v44.y = y;
    v44.z = z;
  }
  v2.x = x - position.x;
  v2.y = y - position.y;
  v2.z = z - position.z;
  v42 = UFG::qAngleBetween(&tangent, &v2);
  v43 = UFG::qAngleBetween(&tangent, &v48);
  if ( (float)(this->m_AdvanceDistance - this->m_FrontBoundary) >= 1.0 )
    v18 = this->m_AdvanceDistance - this->m_FrontBoundary;
  if ( v42 <= v43 )
    v42 = v43;
  this->m_Curvature = v42 / v18;
}

// File Line: 863
// RVA: 0xE0E20
void __fastcall UFG::RoadNetworkGuide::Update(UFG::RoadNetworkGuide *this, UFG::qVector3 *newPos)
{
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  float *v4; // rsi
  float y; // xmm0_4
  float z; // xmm1_4
  float LaneTWithCustomSearch; // xmm0_4
  UFG::RoadNetworkLane *m_LaneAfterNext; // r9
  UFG::RoadNetworkLane *m_NextLane; // r8
  float m_AdvanceDistance; // xmm1_4
  UFG::RoadNetworkLane *v11; // r9
  float *v12; // r8
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mPrev; // rcx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mNext; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v15; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v16; // rax
  UFG::RoadNetworkGuide *m_pPointer; // rdx

  if ( !this->m_Parked )
  {
    m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
    if ( m_CurrentLane )
    {
      if ( m_CurrentLane->mNode.mOffset )
        v4 = (float *)((char *)m_CurrentLane + m_CurrentLane->mNode.mOffset);
      else
        v4 = 0i64;
      y = newPos->y;
      z = newPos->z;
      this->m_Position.x = newPos->x;
      this->m_Position.y = y;
      this->m_Position.z = z;
      if ( this->m_CurrentLocation.m_CurrentLane )
      {
        LaneTWithCustomSearch = UFG::RoadNetworkLocation::FindLaneTWithCustomSearch(
                                  &this->m_CurrentLocation,
                                  newPos,
                                  this->m_NextLane);
        if ( this->m_CurrentLocation.m_CurrentLane )
          this->m_CurrentLocation.m_LaneT = LaneTWithCustomSearch;
      }
      m_LaneAfterNext = this->m_LaneAfterNext;
      m_NextLane = this->m_NextLane;
      m_AdvanceDistance = this->m_AdvanceDistance;
      *(_QWORD *)&this->m_TargetLocation.m_LaneT = *(_QWORD *)&this->m_CurrentLocation.m_LaneT;
      this->m_TargetLocation.m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
      UFG::RoadNetworkLocation::Advance(&this->m_TargetLocation, m_AdvanceDistance, m_NextLane, m_LaneAfterNext);
      UFG::RoadNetworkGuide::UpdateCurvature(this);
      v11 = this->m_CurrentLocation.m_CurrentLane;
      if ( !v11 )
        this->m_Attached = 0;
      if ( v11->mNode.mOffset )
        v12 = (float *)((char *)v11 + v11->mNode.mOffset);
      else
        v12 = 0i64;
      if ( !v11 || v12 != v4 )
      {
        this->m_NextLane = 0i64;
        mPrev = this->mPrev;
        mNext = this->mNext;
        v15 = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        this->mPrev = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
        this->mNext = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
        if ( v11 )
        {
          v15->mPrev = v15;
          this->mNext = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
          v16 = v11->mCars.mNode.mNext;
          v11->mCars.mNode.mNext = v15;
          this->mNext = v16;
          v15->mPrev = &v11->mCars.mNode;
          v16->mPrev = v15;
        }
        if ( !*(_WORD *)v12 )
          this->m_SpeedLimit = v12[41];
      }
      UFG::RoadNetworkGuide::FindNextGuide(this);
      m_pPointer = this->m_NextGuide.m_pPointer;
      this->m_NextGuideDistance = 3.4028235e38;
      if ( m_pPointer )
        this->m_NextGuideDistance = UFG::RoadNetworkGuide::GetGap(this, m_pPointer);
      UFG::RoadNetworkGuide::UpdateStopPointDistance(this);
    }
  }
}

// File Line: 923
// RVA: 0xDDCE0
char __fastcall UFG::RoadNetworkGuide::IsBlockedInOpposingLanes(
        UFG::RoadNetworkGuide *this,
        UFG::RoadNetworkLane *roadLane)
{
  UFG::RoadNetworkLane *v2; // rdi
  bool IsPermissive; // al
  UFG::RoadNetworkLane *m_CurrentLane; // r8
  bool v6; // r9
  float m_LaneT; // xmm11_4
  __int64 mOffset; // rcx
  __int64 v9; // rax
  unsigned int mPathIndex; // edx
  UFG::RoadNetworkLane *Path; // rax
  float v12; // xmm0_4
  UFG::RoadNetworkLane *v13; // rax
  char *v14; // rax
  char *v15; // rcx
  bool v16; // r13
  __int64 v17; // rdx
  __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // rcx
  UFG::RoadNetworkLane *v22; // rbp
  int v23; // ecx
  __int64 p_mNext; // rax
  bool v25; // al
  __int64 v26; // rcx
  bool v27; // r12
  char *v28; // r14
  unsigned int v29; // r15d
  unsigned int v30; // edi
  __int64 v31; // rsi
  __int64 v32; // rax
  char *v33; // rcx
  char *v34; // rax
  __int64 v35; // rcx
  char *v36; // rdx
  __int64 v37; // rbx
  float v38; // xmm6_4
  __int64 v39; // rax
  UFG::RoadNetworkConnection *v40; // rcx
  unsigned int v41; // edx
  float v42; // xmm7_4
  __int64 v43; // r8
  __int16 v44; // cx
  UFG::SimComponent *ComponentOfType; // rax
  bool v46; // zf
  UFG::SimObjectGame *v47; // rcx
  __int64 i; // [rsp+20h] [rbp-C8h]
  bool v50; // [rsp+F0h] [rbp+8h]
  int v52; // [rsp+100h] [rbp+18h]
  unsigned int mNumOpposingLanes; // [rsp+108h] [rbp+20h]

  v2 = roadLane;
  IsPermissive = UFG::RoadNetworkLane::IsPermissive(roadLane, 1);
  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  v6 = IsPermissive;
  v50 = IsPermissive;
  m_LaneT = this->m_CurrentLocation.m_LaneT;
  if ( m_CurrentLane )
  {
    mOffset = m_CurrentLane->mNode.mOffset;
    if ( m_CurrentLane->mNode.mOffset )
      mOffset += (__int64)m_CurrentLane;
    v9 = *(_QWORD *)(mOffset + 32);
    mPathIndex = m_CurrentLane->mPathIndex;
    if ( v9 )
      Path = UFG::qBezierPathCollectionMemImaged::GetPath((UFG::RoadNetworkConnection *)(v9 + mOffset + 32), mPathIndex);
    else
      Path = UFG::qBezierPathCollectionMemImaged::GetPath(0i64, mPathIndex);
    v6 = v50;
    v12 = *((float *)&Path->mNode.mOffset + 1);
  }
  else
  {
    v12 = 0.0;
  }
  v13 = this->m_CurrentLocation.m_CurrentLane;
  if ( v13->mNode.mOffset )
    v14 = (char *)v13 + v13->mNode.mOffset;
  else
    v14 = 0i64;
  if ( v2->mNode.mOffset )
    v15 = (char *)v2 + v2->mNode.mOffset;
  else
    v15 = 0i64;
  v16 = *((_DWORD *)v14 + 6) == *((_DWORD *)v15 + 6);
  mNumOpposingLanes = (unsigned __int8)v2->mNumOpposingLanes;
  v52 = 0;
  if ( !v2->mNumOpposingLanes )
    return 0;
  v17 = 0i64;
  for ( i = 0i64; ; i += 8i64 )
  {
    v18 = v2->mOpposingLanes.mOffset;
    v19 = v18 ? (__int64)&v2->mOpposingLanes + v18 : 0i64;
    v20 = v19 + v17;
    v21 = *(_QWORD *)(v19 + v17);
    v22 = v21 ? (UFG::RoadNetworkLane *)(v21 + v20) : 0i64;
    v23 = 0;
    p_mNext = (__int64)&v22->mCars.mNode.mNext[-2].mNext;
    if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)p_mNext != &v22->mStartConnection )
      break;
LABEL_30:
    if ( v6 && v22->mStatus.mValue == 2 )
    {
      v25 = UFG::RoadNetworkLane::IsPermissive(v22, 1);
      v26 = v22->mPrevConnection.mOffset;
      v27 = v25;
      if ( v26 )
      {
        v28 = (char *)&v22->mPrevConnection + v26;
        if ( v28 )
        {
          v29 = *(_DWORD *)v28;
          v30 = 0;
          if ( *(_DWORD *)v28 )
          {
            v31 = 0i64;
            do
            {
              v32 = *((_QWORD *)v28 + 1);
              if ( v32 )
                v33 = &v28[v32 + 8];
              else
                v33 = 0i64;
              v34 = &v33[v31];
              v35 = *(_QWORD *)&v33[v31];
              if ( v35 )
                v36 = &v34[v35];
              else
                v36 = 0i64;
              if ( (char *)(*((_QWORD *)v36 + 15) - 24i64) == v36 + 88 )
                goto LABEL_67;
              v37 = *((_QWORD *)v36 + 14) - 24i64;
              if ( *((_QWORD *)v36 + 14) == 24i64 || *(UFG::RoadNetworkLane **)(v37 + 80) != v22 )
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
                v39 += (__int64)v36;
              v40 = *(UFG::RoadNetworkConnection **)(v39 + 32);
              v41 = *((unsigned __int16 *)v36 + 19);
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
              if ( (v44 & 0x4000) != 0 )
                goto LABEL_67;
              if ( v44 >= 0 )
              {
                if ( (v44 & 0x2000) != 0 )
                  goto LABEL_67;
                v46 = (v44 & 0x1000) == 0;
                v47 = *(UFG::SimObjectGame **)(v37 + 72);
                if ( v46 )
                  ComponentOfType = UFG::SimObject::GetComponentOfType(v47, UFG::PhysicsMoverInterface::_TypeUID);
                else
                  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v47, UFG::PhysicsMoverInterface::_TypeUID);
              }
              else
              {
                ComponentOfType = *(UFG::SimComponent **)(*(_QWORD *)(v43 + 104) + 544i64);
              }
              if ( ComponentOfType
                && *((float *)&ComponentOfType[10].m_BoundComponentHandles.mNode.mPrev + 1) >= 0.40000001
                && (!v27 || v16 || (float)((float)(1.0 - m_LaneT) * v12) > v42) )
              {
                return 1;
              }
LABEL_67:
              ++v30;
              v31 += 8i64;
            }
            while ( v30 < v29 );
          }
          v2 = roadLane;
        }
      }
      v6 = v50;
    }
    v17 = i + 8;
    if ( ++v52 >= mNumOpposingLanes )
      return 0;
  }
  while ( (unsigned int)++v23 <= 2 && (!v6 || v16 && m_LaneT >= 0.40000001 || *(float *)(p_mNext + 56) > 0.60000002) )
  {
    p_mNext = *(_QWORD *)(p_mNext + 32) - 24i64;
    if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)p_mNext == &v22->mStartConnection )
      goto LABEL_30;
  }
  return 1;
}

// File Line: 998
// RVA: 0xDD9F0
char __fastcall UFG::RoadNetworkGuide::IsBlockedInMergeLanes(
        UFG::RoadNetworkGuide *this,
        UFG::RoadNetworkLane *roadLane)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **p_mNext; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v5; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mPrev; // rcx
  float v7; // xmm6_4
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v8; // rax
  __int64 v9; // r8
  __int64 v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rdi
  __int64 v13; // rax
  UFG::RoadNetworkConnection *v14; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v17; // rax
  unsigned int mNumMergeOutLanes; // r13d
  unsigned int v20; // r15d
  __int64 v21; // r12
  __int64 mOffset; // rax
  char *v23; // rcx
  char *v24; // rax
  __int64 v25; // rcx
  char *v26; // rax
  char *v27; // rbp
  __int64 v28; // rdi
  __int64 v29; // rcx
  __int64 v30; // rax
  __int64 v31; // rdx
  __int64 v32; // rcx
  float v33; // xmm6_4
  __int64 v34; // rax
  __int64 v35; // rdx
  __int64 v36; // rsi
  __int64 v37; // rax
  UFG::RoadNetworkConnection *v38; // rcx
  UFG::qBezierPathMemImaged *v39; // rbx
  unsigned int v40; // eax
  UFG::qBezierSplineMemImaged *v41; // rax
  int v42; // r8d
  __int64 v43; // r10
  __int64 i; // r9
  char *v45; // rax
  char *v46; // rcx
  __int64 v47; // rax
  char *v48; // rdx
  UFG::qVector3 result; // [rsp+20h] [rbp-58h] BYREF
  float splineT; // [rsp+88h] [rbp+10h] BYREF

  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&roadLane->mCars.mNode.mNext[-2].mNext != &roadLane->mStartConnection )
  {
    p_mNext = &roadLane->mCars.mNode.mNext[-2].mNext;
    if ( roadLane->mCars.mNode.mNext != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)24
      && p_mNext != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)this )
    {
      v5 = p_mNext[8];
      mPrev = v5->mPrev;
      if ( v5->mPrev )
        mPrev = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)((char *)mPrev + (_QWORD)v5);
      v7 = *((float *)p_mNext + 14);
      v8 = mPrev[3].mPrev;
      v9 = WORD2(v5[2].mPrev);
      if ( v8 )
        v10 = (__int64)&mPrev[3] + (_QWORD)v8;
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
      Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                            v14,
                                            *(unsigned __int16 *)(v12 + 38));
      SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, v7, &splineT);
      v17 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             (UFG::RoadNetworkConnection *)Path,
                                             SplineParameters);
      UFG::RoadNetworkLane::GetOffsetPos(&result, v17, splineT, *(float *)(v12 + 40));
      if ( UFG::RoadNetworkGuide::IsBlocking(this, &result) )
        return 1;
    }
  }
  mNumMergeOutLanes = (unsigned __int8)roadLane->mNumMergeOutLanes;
  v20 = 0;
  if ( roadLane->mNumMergeOutLanes )
  {
    v21 = 0i64;
    while ( 1 )
    {
      mOffset = roadLane->mMergeOutLanes.mOffset;
      v23 = mOffset ? (char *)&roadLane->mMergeOutLanes + mOffset : 0i64;
      v24 = &v23[v21];
      v25 = *(_QWORD *)&v23[v21];
      v26 = v25 ? &v24[v25] : 0i64;
      v27 = v26 + 88;
      v28 = *((_QWORD *)v26 + 15) - 24i64;
      if ( (char *)v28 != v26 + 88 )
        break;
LABEL_40:
      ++v20;
      v21 += 8i64;
      if ( v20 >= mNumMergeOutLanes )
        goto LABEL_41;
    }
    while ( 1 )
    {
      v29 = *(_QWORD *)(v28 + 64);
      v30 = *(_QWORD *)v29;
      if ( *(_QWORD *)v29 )
        v30 += v29;
      v31 = *(unsigned __int16 *)(v29 + 36);
      v32 = *(_QWORD *)(v30 + 48);
      v33 = *(float *)(v28 + 56);
      if ( v32 )
        v32 += v30 + 48;
      v34 = *(_QWORD *)(v32 + 8 * v31);
      v35 = v32 + 8 * v31;
      if ( v34 )
        v36 = v34 + v35;
      else
        v36 = 0i64;
      v37 = *(_QWORD *)v36;
      if ( *(_QWORD *)v36 )
        v37 += v36;
      v38 = *(UFG::RoadNetworkConnection **)(v37 + 32);
      if ( v38 )
        v38 = (UFG::RoadNetworkConnection *)((char *)v38 + v37 + 32);
      v39 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v38,
                                           *(unsigned __int16 *)(v36 + 38));
      v40 = UFG::qBezierPathMemImaged::GetSplineParameters(v39, v33, &splineT);
      v41 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             (UFG::RoadNetworkConnection *)v39,
                                             v40);
      UFG::RoadNetworkLane::GetOffsetPos(&result, v41, splineT, *(float *)(v36 + 40));
      if ( UFG::RoadNetworkGuide::IsBlocking(this, &result) )
        return 1;
      v28 = *(_QWORD *)(v28 + 32) - 24i64;
      if ( (char *)v28 == v27 )
        goto LABEL_40;
    }
  }
LABEL_41:
  v42 = 0;
  if ( roadLane->mNumMergeInLanes )
  {
    v43 = roadLane->mMergeInLanes.mOffset;
    for ( i = 0i64; ; i += 8i64 )
    {
      v45 = v43 ? (char *)&roadLane->mMergeInLanes + v43 : 0i64;
      v46 = &v45[i];
      v47 = *(_QWORD *)&v45[i];
      v48 = v47 ? &v46[v47] : 0i64;
      if ( (char *)(*((_QWORD *)v48 + 15) - 24i64) != v48 + 88
        && (v48[55] == 2 || *((_QWORD *)v48 + 14) != 24i64 && *(float *)(*((_QWORD *)v48 + 14) - 24i64 + 56) > 0.2) )
      {
        break;
      }
      if ( ++v42 >= (unsigned int)(unsigned __int8)roadLane->mNumMergeInLanes )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 1040
// RVA: 0xDE100
bool __fastcall UFG::RoadNetworkGuide::IsBlocking(UFG::RoadNetworkGuide *this, UFG::qVector3 *pos)
{
  float Value; // xmm6_4
  UFG::SimObjectGame *m_SimObj; // rcx
  __int16 m_Flags; // r8
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  float LinearVelocityMagnitude; // xmm0_4
  UFG::RoadNetworkLane *m_CurrentLane; // rdx
  UFG::RoadNetworkConnection *v10; // rcx
  char *v11; // rax
  __int64 mLaneIndex; // r8
  __int64 v13; // rdx
  float m_LaneT; // xmm7_4
  char *v15; // rdx
  __int64 v16; // rax
  char *v17; // rdi
  char *v18; // rax
  __int64 v19; // rdx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v22; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-38h] BYREF
  float splineT; // [rsp+60h] [rbp+8h] BYREF

  Value = FLOAT_100_0;
  m_SimObj = (UFG::SimObjectGame *)this->m_SimObj;
  if ( !m_SimObj )
    goto LABEL_11;
  m_Flags = m_SimObj->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_11;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      goto LABEL_11;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_SimObj,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                          m_SimObj,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_SimObj->m_Components.p[34].m_pComponent;
  }
  if ( ComponentOfTypeHK )
  {
    LinearVelocityMagnitude = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitude(ComponentOfTypeHK);
    Value = UFG::LinearGraph<float>::GetValue(&stru_142091488, LinearVelocityMagnitude);
  }
LABEL_11:
  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  v10 = 0i64;
  if ( m_CurrentLane->mNode.mOffset )
    v11 = (char *)m_CurrentLane + m_CurrentLane->mNode.mOffset;
  else
    v11 = 0i64;
  mLaneIndex = m_CurrentLane->mLaneIndex;
  v13 = *((_QWORD *)v11 + 6);
  m_LaneT = this->m_CurrentLocation.m_LaneT;
  if ( v13 )
    v15 = &v11[v13 + 48];
  else
    v15 = 0i64;
  v16 = *(_QWORD *)&v15[8 * mLaneIndex];
  v17 = &v15[8 * mLaneIndex + v16];
  if ( !v16 )
    v17 = 0i64;
  if ( *(_QWORD *)v17 )
    v18 = &v17[*(_QWORD *)v17];
  else
    v18 = 0i64;
  v19 = *((_QWORD *)v18 + 4);
  if ( v19 )
    v10 = (UFG::RoadNetworkConnection *)&v18[v19 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v10, *((unsigned __int16 *)v17 + 19));
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, m_LaneT, &splineT);
  v22 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v22, splineT, *((float *)v17 + 10));
  return Value > (float)((float)((float)((float)(result.x - pos->x) * (float)(result.x - pos->x))
                               + (float)((float)(result.y - pos->y) * (float)(result.y - pos->y)))
                       + (float)((float)(result.z - pos->z) * (float)(result.z - pos->z)));
}

// File Line: 1057
// RVA: 0xDE2B0
__int64 __fastcall UFG::RoadNetworkGuide::IsClearAfterIntersection(
        UFG::RoadNetworkGuide *this,
        UFG::RoadNetworkLane *lane)
{
  __int64 mOffset; // rax
  unsigned __int8 v5; // bl
  char *v6; // rax
  __int64 v7; // rdx
  char *v8; // rax
  __int64 v9; // rcx
  char *v10; // rdx
  __int64 v11; // rsi
  __int64 v12; // rcx
  __int64 v13; // rax
  unsigned int v14; // edx
  __int64 v15; // rcx
  UFG::RoadNetworkConnection *v16; // rcx
  float v17; // xmm0_4

  mOffset = lane->mNextConnection.mOffset;
  v5 = 1;
  if ( mOffset )
  {
    v6 = (char *)&lane->mNextConnection + mOffset;
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
                  && (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&lane->mCars.mNode.mNext[-2].mNext != &lane->mStartConnection
                  && lane->mCars.mNode.mNext != (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)24 )
                {
                  return &lane->mCars.mNode.mNext[-2].mNext == (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)this;
                }
              }
              else
              {
                return 0;
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
  UFG::RoadNetworkLane *m_CurrentLane; // rbp
  UFG::RoadNetworkLane *m_NextLane; // r14
  UFG::RoadNetworkConnection *v4; // rbx
  UFG::RoadNetworkLane *v5; // rsi
  _WORD *v6; // rax
  bool v7; // r15
  __m128 y_low; // xmm2
  UFG::RoadNetworkLane *v9; // rax
  _WORD *v10; // rdx
  bool v11; // r14
  char IsBlockedInMergeLanes; // bp
  UFG::RoadNetworkLane *v13; // rcx
  char *v14; // rax
  __int64 mLaneIndex; // rdx
  __int64 v16; // rcx
  float m_LaneT; // xmm6_4
  char *v18; // rcx
  __int64 v19; // rax
  char *v20; // rsi
  char *v21; // rax
  __int64 v22; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v25; // rax
  float x; // xmm1_4
  __m128 v27; // xmm0
  float z; // xmm2_4
  float v29; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 v31; // [rsp+30h] [rbp-38h] BYREF
  float splineT; // [rsp+70h] [rbp+8h] BYREF

  if ( !this->m_Attached )
  {
    this->m_StopPointDistance = 0.0;
    return;
  }
  this->m_StopPointDistance = 3.4028235e38;
  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  if ( m_CurrentLane )
  {
    m_NextLane = this->m_NextLane;
    if ( m_NextLane )
    {
      v4 = 0i64;
      v5 = 0i64;
      UFG::RoadNetworkLane::GetPos(m_CurrentLane, &result, m_CurrentLane->mStopPoint);
      if ( m_NextLane->mNode.mOffset )
        v6 = (_WORD *)((char *)m_NextLane + m_NextLane->mNode.mOffset);
      else
        v6 = 0i64;
      v7 = *v6 == 1;
      if ( *v6 == 1 )
      {
        if ( !v6[1] )
          return;
        if ( m_NextLane->mStatus.mValue != 2 )
        {
          y_low = (__m128)LODWORD(result.y);
          y_low.m128_f32[0] = (float)((float)((float)(result.y - this->m_Position.y)
                                            * (float)(result.y - this->m_Position.y))
                                    + (float)((float)(result.x - this->m_Position.x)
                                            * (float)(result.x - this->m_Position.x)))
                            + (float)((float)(result.z - this->m_Position.z) * (float)(result.z - this->m_Position.z));
          this->m_StopPointDistance = (float)(_mm_sqrt_ps(y_low).m128_f32[0] - this->m_FrontBoundary) - 1.0;
          return;
        }
        v5 = m_NextLane;
      }
      v9 = this->m_CurrentLocation.m_CurrentLane;
      v10 = (_WORD *)((char *)v9 + v9->mNode.mOffset);
      if ( !v9->mNode.mOffset )
        v10 = 0i64;
      v11 = *v10 == 1;
      if ( *v10 == 1 )
        v5 = m_CurrentLane;
      if ( v5 )
      {
        IsBlockedInMergeLanes = UFG::RoadNetworkGuide::IsBlockedInMergeLanes(this, v5);
        if ( IsBlockedInMergeLanes
          || (IsBlockedInMergeLanes = UFG::RoadNetworkGuide::IsBlockedInOpposingLanes(this, v5)) != 0
          || !(unsigned __int8)UFG::RoadNetworkGuide::IsClearAfterIntersection(this, v5) )
        {
          if ( v11 && IsBlockedInMergeLanes )
          {
            v13 = this->m_TargetLocation.m_CurrentLane;
            if ( v13->mNode.mOffset )
              v14 = (char *)v13 + v13->mNode.mOffset;
            else
              v14 = 0i64;
            mLaneIndex = v13->mLaneIndex;
            v16 = *((_QWORD *)v14 + 6);
            m_LaneT = this->m_TargetLocation.m_LaneT;
            if ( v16 )
              v18 = &v14[v16 + 48];
            else
              v18 = 0i64;
            v19 = *(_QWORD *)&v18[8 * mLaneIndex];
            v20 = &v18[8 * mLaneIndex + v19];
            if ( !v19 )
              v20 = 0i64;
            if ( *(_QWORD *)v20 )
              v21 = &v20[*(_QWORD *)v20];
            else
              v21 = 0i64;
            v22 = *((_QWORD *)v21 + 4);
            if ( v22 )
              v4 = (UFG::RoadNetworkConnection *)&v21[v22 + 32];
            Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                  v4,
                                                  *((unsigned __int16 *)v20 + 19));
            SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, m_LaneT, &splineT);
            v25 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                   (UFG::RoadNetworkConnection *)Path,
                                                   SplineParameters);
            UFG::RoadNetworkLane::GetOffsetPos(&v31, v25, splineT, *((float *)v20 + 10));
            x = v31.x;
            v27 = (__m128)LODWORD(v31.y);
            z = v31.z;
          }
          else
          {
            z = result.z;
            v27 = (__m128)LODWORD(result.y);
            x = result.x;
          }
          v27.m128_f32[0] = (float)((float)((float)(v27.m128_f32[0] - this->m_Position.y)
                                          * (float)(v27.m128_f32[0] - this->m_Position.y))
                                  + (float)((float)(x - this->m_Position.x) * (float)(x - this->m_Position.x)))
                          + (float)((float)(z - this->m_Position.z) * (float)(z - this->m_Position.z));
          v29 = _mm_sqrt_ps(v27).m128_f32[0] - this->m_FrontBoundary;
          this->m_StopPointDistance = v29;
          if ( v7 )
            this->m_StopPointDistance = v29 - 1.0;
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
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mPrev; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mNext; // rax

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  this->mNext = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  this->m_NextLane = 0i64;
  this->m_Attached = 0;
}

// File Line: 1177
// RVA: 0xDF7D0
void __fastcall UFG::RoadNetworkGuide::Park(UFG::RoadNetworkGuide *this)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mPrev; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mNext; // rax

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  this->mNext = &this->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  this->m_NextLane = 0i64;
  this->m_Parked = 1;
}

// File Line: 1185
// RVA: 0xDE910
bool __fastcall UFG::RoadNetworkGuide::IsSpaceToInsertIntoLane(UFG::RoadNetworkGuide *this, UFG::RoadNetworkLane *lane)
{
  float m_LaneT; // xmm7_4
  UFG::RoadNetworkConnection *v3; // rsi
  float *v5; // rbp
  float *v6; // r13
  float m_FrontBoundary; // xmm10_4
  float m_RearBoundary; // xmm9_4
  char *v9; // rax
  __int64 v10; // rcx
  unsigned int mPathIndex; // edx
  UFG::RoadNetworkConnection *v12; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v15; // rax
  UFG::qOffset64<UFG::RoadNetworkConnection *> *p_mStartConnection; // r12
  float *p_mNext; // rdi
  int v18; // r15d
  float z; // xmm5_4
  __m128 y_low; // xmm3
  float x; // xmm4_4
  float v22; // xmm6_4
  char *v23; // rax
  __int64 v24; // rcx
  UFG::RoadNetworkConnection *v25; // rcx
  UFG::qBezierPathMemImaged *v26; // rbx
  unsigned int v27; // eax
  UFG::qBezierSplineMemImaged *v28; // rax
  __m128 v29; // xmm2
  __int64 v31; // rbx
  __int64 v32; // rax
  __int64 v33; // rcx
  unsigned int v34; // edx
  __int64 v35; // rax
  UFG::RoadNetworkConnection *v36; // rcx
  UFG::RoadNetworkLane *v37; // rax
  __int64 v38; // rcx
  float v39; // xmm6_4
  __int64 v40; // rax
  unsigned int v41; // edx
  __int64 v42; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qVector3 v44; // [rsp+30h] [rbp-98h] BYREF
  float splineT; // [rsp+D0h] [rbp+8h] BYREF

  m_LaneT = this->m_CurrentLocation.m_LaneT;
  v3 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  m_FrontBoundary = this->m_FrontBoundary;
  m_RearBoundary = this->m_RearBoundary;
  if ( lane->mNode.mOffset )
    v9 = (char *)lane + lane->mNode.mOffset;
  else
    v9 = 0i64;
  v10 = *((_QWORD *)v9 + 4);
  mPathIndex = lane->mPathIndex;
  if ( v10 )
    v12 = (UFG::RoadNetworkConnection *)&v9[v10 + 32];
  else
    v12 = 0i64;
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v12, mPathIndex);
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, m_LaneT, &splineT);
  v15 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v15, splineT, lane->mOffset);
  p_mStartConnection = &lane->mStartConnection;
  p_mNext = (float *)&lane->mCars.mNode.mPrev[-2].mNext;
  v18 = 0;
  if ( p_mNext == (float *)&lane->mStartConnection )
    return 1;
  z = result.z;
  y_low = (__m128)LODWORD(result.y);
  x = result.x;
  while ( 1 )
  {
    v22 = p_mNext[14];
    ++v18;
    if ( v22 < m_LaneT )
      break;
    if ( lane->mNode.mOffset )
      v23 = (char *)lane + lane->mNode.mOffset;
    else
      v23 = 0i64;
    v24 = *((_QWORD *)v23 + 4);
    if ( v24 )
      v25 = (UFG::RoadNetworkConnection *)&v23[v24 + 32];
    else
      v25 = 0i64;
    v26 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v25, lane->mPathIndex);
    v27 = UFG::qBezierPathMemImaged::GetSplineParameters(v26, v22, &splineT);
    v28 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           (UFG::RoadNetworkConnection *)v26,
                                           v27);
    UFG::RoadNetworkLane::GetOffsetPos(&v44, v28, splineT, lane->mOffset);
    x = result.x;
    y_low = (__m128)LODWORD(result.y);
    z = result.z;
    v29 = (__m128)LODWORD(result.y);
    v29.m128_f32[0] = (float)((float)((float)(result.y - v44.y) * (float)(result.y - v44.y))
                            + (float)((float)(result.x - v44.x) * (float)(result.x - v44.x)))
                    + (float)((float)(result.z - v44.z) * (float)(result.z - v44.z));
    if ( (float)(_mm_sqrt_ps(v29).m128_f32[0] - (float)(m_FrontBoundary + p_mNext[25])) < (float)(m_FrontBoundary + 2.5) )
      return 0;
    v5 = p_mNext;
    p_mNext = (float *)(*((_QWORD *)p_mNext + 3) - 24i64);
    if ( p_mNext == (float *)p_mStartConnection )
      goto LABEL_21;
  }
  v6 = p_mNext;
LABEL_21:
  if ( !v18 )
    return 1;
  if ( !v5 )
  {
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v6[30]) * (float)(y_low.m128_f32[0] - v6[30]))
                              + (float)((float)(x - v6[29]) * (float)(x - v6[29])))
                      + (float)((float)(z - v6[31]) * (float)(z - v6[31]));
    return (float)(_mm_sqrt_ps(y_low).m128_f32[0] - (float)(m_RearBoundary + v6[24])) > (float)(m_RearBoundary + 2.5);
  }
  v31 = *((_QWORD *)v5 + 3) - 24i64;
  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v31 == p_mStartConnection || *((_QWORD *)v5 + 3) == 24i64 )
    return 1;
  v32 = *((_QWORD *)v5 + 8);
  if ( *(_QWORD *)v32 )
    v33 = v32 + *(_QWORD *)v32;
  else
    v33 = 0i64;
  v34 = *(unsigned __int16 *)(v32 + 38);
  v35 = *(_QWORD *)(v33 + 32);
  if ( v35 )
    v36 = (UFG::RoadNetworkConnection *)(v35 + v33 + 32);
  else
    v36 = 0i64;
  v37 = UFG::qBezierPathCollectionMemImaged::GetPath(v36, v34);
  v38 = *(_QWORD *)(v31 + 64);
  v39 = (float)(*((float *)&v37->mNode.mOffset + 1) * v5[14]) - v5[25];
  if ( *(_QWORD *)v38 )
    v40 = v38 + *(_QWORD *)v38;
  else
    v40 = 0i64;
  v41 = *(unsigned __int16 *)(v38 + 38);
  v42 = *(_QWORD *)(v40 + 32);
  if ( v42 )
    v3 = (UFG::RoadNetworkConnection *)(v42 + v40 + 32);
  return (float)(v39
               - (float)((float)(*(float *)(v31 + 56)
                               * *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v3, v41)->mNode.mOffset + 1))
                       + *(float *)(v31 + 96))) >= (float)((float)(m_RearBoundary + m_FrontBoundary) + 5.0);
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
  UFG::RoadNetworkLane *m_CurrentLane; // rax
  __int64 mOffset; // rcx
  UFG::qOffset64<UFG::RoadNetworkConnection *> *p_mNextConnection; // rax

  m_CurrentLane = this->m_CurrentLocation.m_CurrentLane;
  mOffset = m_CurrentLane->mNextConnection.mOffset;
  p_mNextConnection = &m_CurrentLane->mNextConnection;
  if ( mOffset )
    return (UFG::RoadNetworkConnection *)((char *)p_mNextConnection + mOffset);
  else
    return 0i64;
}

