// File Line: 35
// RVA: 0x642BC0
void __fastcall UFG::NavGuide::NavGuide(UFG::NavGuide *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  this->vfptr = (UFG::NavGuideVtbl *)&UFG::NavGuide::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_Pos.x = UFG::qVector3::msZero.x;
  this->m_Pos.y = y;
  this->m_Pos.z = z;
  *(_WORD *)&this->m_Active = 0;
  this->m_PathQueryState = PathQueryState_Idle;
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&this->m_PathQueryInput);
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  *(_QWORD *)&this->m_PathQueryOutput.m_id = 0i64;
  this->m_PathQueryOutput.m_status = Status_Undefined;
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathOutput::`vftable;
  this->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
  *(_QWORD *)&this->m_NavParams.m_flags = 65280i64;
  this->m_NavParams.m_fRadius = 2.0;
}

// File Line: 40
// RVA: 0x643D20
void __fastcall UFG::NavGuide::~NavGuide(UFG::NavGuide *this)
{
  UFG::FindPathDeferredQuery *p_m_PathQueryInput; // rdi
  UFG::DaemonManager *v3; // rax
  UFG::FindPathOutput *p_m_PathQueryOutput; // rbx
  UFG::NavPath *m_pNavPath; // rcx

  this->vfptr = (UFG::NavGuideVtbl *)&UFG::NavGuide::`vftable;
  p_m_PathQueryInput = &this->m_PathQueryInput;
  v3 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::CancelQuery(v3, p_m_PathQueryInput);
  p_m_PathQueryOutput = &this->m_PathQueryOutput;
  m_pNavPath = p_m_PathQueryOutput->m_pPath.m_pNavPath;
  if ( m_pNavPath )
  {
    if ( m_pNavPath->m_uRefCount-- == 1 )
      m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
  }
  p_m_PathQueryOutput->vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  p_m_PathQueryInput->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
}

// File Line: 86
// RVA: 0x64D2E0
void __fastcall UFG::NavGuide::FindPath(
        UFG::NavGuide *this,
        UFG::qVector3 *startPos,
        UFG::qVector3 *destPos,
        double destNavRadius)
{
  UFG::DaemonManager *v8; // rax
  __m128 z_low; // xmm2
  __m128 y_low; // xmm3
  __m128 x_low; // xmm4
  double v12; // xmm1_8
  bool m_bValid; // al
  hkVector4f v14; // xmm0
  unsigned int m_aiMeshUid; // eax
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  bool v19; // al
  float y; // xmm1_4
  float z; // xmm0_4
  hkVector4f v22; // xmm0
  unsigned int v23; // eax
  UFG::HavokNavPosition v24; // [rsp+18h] [rbp-49h] BYREF
  UFG::HavokNavPosition v25; // [rsp+58h] [rbp-9h] BYREF

  if ( (unsigned int)(this->m_PathQueryState - 1) <= 1 )
  {
    v8 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::CancelQuery(v8, &this->m_PathQueryInput);
  }
  z_low = (__m128)LODWORD(UFG::qVector3::msDirUp.z);
  y_low = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
  v24.m_bValid = 0;
  *(_QWORD *)&v24.m_packedKey = -1i64;
  y_low.m128_f32[0] = (float)(UFG::qVector3::msDirUp.y * 0.1) + startPos->y;
  z_low.m128_f32[0] = (float)(UFG::qVector3::msDirUp.z * 0.1) + startPos->z;
  x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v24.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  x_low.m128_f32[0] = (float)(UFG::qVector3::msDirUp.x * 0.1) + startPos->x;
  LODWORD(v24.m_vPosition.y) = y_low.m128_i32[0];
  *(_QWORD *)&v12 = LODWORD(this->m_NavParams.m_fRadius);
  LODWORD(v24.m_vPosition.z) = z_low.m128_i32[0];
  LODWORD(v24.m_vPosition.x) = x_low.m128_i32[0];
  v24.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(x_low, z_low),
                                   _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  UFG::HavokNavPosition::Validate(&v24, v12, COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_3_0)), 0.0);
  m_bValid = v24.m_bValid;
  *(float *)&v12 = v24.m_vPosition.y;
  this->m_PathQueryInput.m_npFrom.m_vPosition.x = v24.m_vPosition.x;
  this->m_PathQueryInput.m_npFrom.m_vPosition.z = v24.m_vPosition.z;
  this->m_PathQueryInput.m_npFrom.m_vPosition.y = *(float *)&v12;
  if ( m_bValid )
  {
    v14.m_quad = (__m128)v24.m_hkvMeshPosition;
    this->m_PathQueryInput.m_npFrom.m_bValid = m_bValid;
    this->m_PathQueryInput.m_npFrom.m_packedKey = v24.m_packedKey;
    m_aiMeshUid = v24.m_aiMeshUid;
    this->m_PathQueryInput.m_npFrom.m_hkvMeshPosition = (hkVector4f)v14.m_quad;
    this->m_PathQueryInput.m_npFrom.m_aiMeshUid = m_aiMeshUid;
  }
  else
  {
    this->m_PathQueryInput.m_npFrom.m_bValid = 0;
  }
  v16 = (__m128)LODWORD(UFG::qVector3::msDirUp.z);
  v25.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v25.m_bValid = 0;
  *(_QWORD *)&v25.m_packedKey = -1i64;
  v17 = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
  v18 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v17.m128_f32[0] = (float)(UFG::qVector3::msDirUp.y * 0.1) + destPos->y;
  v18.m128_f32[0] = (float)(UFG::qVector3::msDirUp.x * 0.1) + destPos->x;
  v25.m_vPosition.z = (float)(UFG::qVector3::msDirUp.z * 0.1) + destPos->z;
  v16.m128_f32[0] = v25.m_vPosition.z;
  LODWORD(v25.m_vPosition.y) = v17.m128_i32[0];
  LODWORD(v25.m_vPosition.x) = v18.m128_i32[0];
  v25.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(v18, v16),
                                   _mm_unpacklo_ps(v17, (__m128)(unsigned int)FLOAT_1_0));
  if ( *(float *)&destNavRadius <= 1.0 )
    *(_QWORD *)&destNavRadius = (unsigned int)FLOAT_1_0;
  UFG::HavokNavPosition::Validate(
    &v25,
    destNavRadius,
    COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_7_0)),
    COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_NavParams.m_fRadius)));
  v19 = v25.m_bValid;
  y = v25.m_vPosition.y;
  this->m_PathQueryInput.m_npTo.m_vPosition.x = v25.m_vPosition.x;
  z = v25.m_vPosition.z;
  this->m_PathQueryInput.m_npTo.m_vPosition.y = y;
  this->m_PathQueryInput.m_npTo.m_vPosition.z = z;
  if ( v19 )
  {
    v22.m_quad = (__m128)v25.m_hkvMeshPosition;
    this->m_PathQueryInput.m_npTo.m_bValid = v19;
    this->m_PathQueryInput.m_npTo.m_packedKey = v25.m_packedKey;
    v23 = v25.m_aiMeshUid;
    this->m_PathQueryInput.m_npTo.m_hkvMeshPosition = (hkVector4f)v22.m_quad;
    this->m_PathQueryInput.m_npTo.m_aiMeshUid = v23;
  }
  else
  {
    this->m_PathQueryInput.m_npTo.m_bValid = 0;
  }
  this->m_PathQueryState = PathQueryState_Requested;
}

// File Line: 106
// RVA: 0x6498D0
void __fastcall UFG::NavGuide::ClearPath(UFG::NavGuide *this)
{
  UFG::DaemonManager *v2; // rax
  UFG::NavPath *m_pNavPath; // rsi
  unsigned int size; // eax
  __int64 v5; // rbx

  if ( (unsigned int)(this->m_PathQueryState - 1) <= 1 )
  {
    v2 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::CancelQuery(v2, &this->m_PathQueryInput);
  }
  m_pNavPath = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( m_pNavPath )
  {
    size = m_pNavPath->m_aWaypoints.size;
    if ( size )
    {
      v5 = size;
      do
      {
        UFG::NavPath::RemoveWaypointEnd(m_pNavPath);
        --v5;
      }
      while ( v5 );
    }
  }
  this->m_CurrPathPointIndex = 0;
  this->m_PathQueryState = PathQueryState_Idle;
}

// File Line: 149
// RVA: 0x64ED00
UFG::qVector3 *__fastcall UFG::NavGuide::GetPathSegmentPos(
        UFG::NavGuide *this,
        UFG::qVector3 *result,
        unsigned int pathPointIndex,
        UFG::qVector3 *pos)
{
  __int64 v4; // r11
  UFG::NavPath *m_pNavPath; // r8
  unsigned int size; // r10d
  UFG::NavWaypoint *p; // r8
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  float v11; // xmm3_4
  __m128 y_low; // xmm4
  float v13; // xmm5_4
  __m128 v14; // xmm2
  float v15; // xmm10_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm3_4
  float v20; // xmm2_4

  v4 = pathPointIndex;
  m_pNavPath = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( m_pNavPath )
    size = m_pNavPath->m_aWaypoints.size;
  else
    size = 0;
  p = m_pNavPath->m_aWaypoints.p;
  x = p[v4].m_navPosition.m_vPosition.x;
  y = p[v4].m_navPosition.m_vPosition.y;
  z = p[v4].m_navPosition.m_vPosition.z;
  if ( (_DWORD)v4 == size - 1 )
  {
    result->x = x;
    result->y = y;
    result->z = z;
  }
  else
  {
    y_low = (__m128)LODWORD(p[(unsigned int)(v4 + 1)].m_navPosition.m_vPosition.y);
    v11 = p[(unsigned int)(v4 + 1)].m_navPosition.m_vPosition.x - x;
    y_low.m128_f32[0] = y_low.m128_f32[0] - y;
    v13 = p[(unsigned int)(v4 + 1)].m_navPosition.m_vPosition.z - z;
    v14 = y_low;
    v14.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
    v15 = _mm_sqrt_ps(v14).m128_f32[0];
    if ( v15 >= 0.001 )
    {
      if ( v14.m128_f32[0] == 0.0 )
        v16 = 0.0;
      else
        v16 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
      v17 = y_low.m128_f32[0] * v16;
      v18 = v13 * v16;
      v19 = v11 * v16;
      v20 = (float)((float)((float)(pos->y - y) * v17) + (float)((float)(pos->x - x) * v19))
          + (float)((float)(pos->z - z) * v18);
      if ( v20 <= 0.0 )
        v20 = 0.0;
      if ( v20 >= v15 )
        v20 = v15;
      result->x = (float)(v19 * v20) + x;
      result->y = (float)(v17 * v20) + y;
      result->z = (float)(v18 * v20) + z;
    }
    else
    {
      result->x = x;
      result->y = y;
      result->z = z;
    }
  }
  return result;
}

// File Line: 171
// RVA: 0x64EBD0
UFG::qVector3 *__fastcall UFG::NavGuide::GetPathSegmentDir(
        UFG::NavGuide *this,
        UFG::qVector3 *result,
        unsigned int pathPointIndex)
{
  UFG::NavPath *m_pNavPath; // r8
  unsigned int size; // eax
  UFG::NavWaypoint *p; // r8
  float v7; // xmm2_4
  __m128 y_low; // xmm3
  float v9; // xmm4_4
  __m128 v10; // xmm5
  float y; // xmm1_4
  UFG::qVector3 *v12; // rax
  float z; // xmm0_4
  float v14; // xmm1_4

  m_pNavPath = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( m_pNavPath )
  {
    size = m_pNavPath->m_aWaypoints.size;
    if ( size == 1 )
    {
LABEL_6:
      y = UFG::qVector3::msDirFront.y;
      v12 = result;
      result->x = UFG::qVector3::msDirFront.x;
      z = UFG::qVector3::msDirFront.z;
      result->y = y;
      result->z = z;
      return v12;
    }
  }
  else
  {
    size = 0;
  }
  if ( pathPointIndex == size - 1 )
    --pathPointIndex;
  p = m_pNavPath->m_aWaypoints.p;
  y_low = (__m128)LODWORD(p[pathPointIndex + 1].m_navPosition.m_vPosition.y);
  v7 = p[pathPointIndex + 1].m_navPosition.m_vPosition.x - p[pathPointIndex].m_navPosition.m_vPosition.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - p[pathPointIndex].m_navPosition.m_vPosition.y;
  v9 = p[pathPointIndex + 1].m_navPosition.m_vPosition.z - p[pathPointIndex].m_navPosition.m_vPosition.z;
  v10 = y_low;
  v10.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] < 0.0000010000001 )
    goto LABEL_6;
  v14 = 0.0;
  if ( v10.m128_f32[0] != 0.0 )
    v14 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = result;
  result->x = v7 * v14;
  result->y = y_low.m128_f32[0] * v14;
  result->z = v9 * v14;
  return v12;
}

// File Line: 196
// RVA: 0x662C90
void __fastcall UFG::NavGuide::UpdatePathQuery(UFG::NavGuide *this)
{
  UFG::NavGuide::PathQueryState m_PathQueryState; // eax
  UFG::DaemonManager *v3; // rax
  UFG::DaemonOutputStatus m_status; // ecx
  __int32 v5; // ecx

  m_PathQueryState = this->m_PathQueryState;
  if ( m_PathQueryState == PathQueryState_Requested )
  {
    if ( this->m_PathQueryInput.m_npFrom.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(
           this->m_PathQueryInput.m_npFrom.m_packedKey,
           this->m_PathQueryInput.m_npFrom.m_aiMeshUid)
      && this->m_PathQueryInput.m_npTo.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(
           this->m_PathQueryInput.m_npTo.m_packedKey,
           this->m_PathQueryInput.m_npTo.m_aiMeshUid) )
    {
      this->m_PathQueryInput.m_pNavParams = &this->m_NavParams;
      v3 = UFG::DaemonManager::Instance();
      UFG::DaemonManager::SubmitQuery(v3, &this->m_PathQueryInput, &this->m_PathQueryOutput);
      this->m_PathQueryState = PathQueryState_Processing;
    }
  }
  else if ( m_PathQueryState == PathQueryState_Processing )
  {
    m_status = this->m_PathQueryOutput.m_status;
    if ( m_status )
    {
      v5 = m_status - 3;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          this->m_PathQueryState = PathQueryState_Failed;
          UFG::NavGuide::ClearPath(this);
        }
      }
      else
      {
        this->m_PathQueryState = PathQueryState_Succeeded;
      }
    }
    else
    {
      this->m_PathQueryState = PathQueryState_Idle;
    }
  }
}

// File Line: 241
// RVA: 0x662B60
void __fastcall UFG::NavGuide::UpdatePathPosition(UFG::NavGuide *this, UFG::qVector3 *pos)
{
  float x; // eax
  float y; // xmm7_4
  float z; // xmm8_4
  UFG::NavPath *m_pNavPath; // rax
  unsigned int size; // edi
  unsigned int v8; // esi
  float v9; // xmm6_4
  unsigned int v10; // ebx
  float v11; // xmm9_4
  UFG::qVector3 result; // [rsp+20h] [rbp-58h] BYREF

  x = pos->x;
  y = pos->y;
  z = pos->z;
  this->m_Pos.y = y;
  this->m_Pos.x = x;
  this->m_Pos.z = z;
  if ( this->m_Active )
  {
    m_pNavPath = this->m_PathQueryOutput.m_pPath.m_pNavPath;
    if ( m_pNavPath )
    {
      size = m_pNavPath->m_aWaypoints.size;
      if ( size )
      {
        v8 = 0;
        v9 = FLOAT_3_4028235e38;
        v10 = 0;
        v11 = this->m_Pos.x;
        do
        {
          UFG::NavGuide::GetPathSegmentPos(this, &result, v10, &this->m_Pos);
          if ( (float)((float)((float)((float)(y - result.y) * (float)(y - result.y))
                             + (float)((float)(v11 - result.x) * (float)(v11 - result.x)))
                     + (float)((float)(z - result.z) * (float)(z - result.z))) < v9 )
          {
            v9 = (float)((float)((float)(y - result.y) * (float)(y - result.y))
                       + (float)((float)(v11 - result.x) * (float)(v11 - result.x)))
               + (float)((float)(z - result.z) * (float)(z - result.z));
            v8 = v10;
          }
          ++v10;
        }
        while ( v10 < size );
        this->m_CurrPathPointIndex = v8;
      }
    }
  }
}

