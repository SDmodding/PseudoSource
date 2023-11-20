// File Line: 35
// RVA: 0x642BC0
void __fastcall UFG::NavGuide::NavGuide(UFG::NavGuide *this)
{
  UFG::NavGuide *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  signed __int64 v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::NavGuideVtbl *)&UFG::NavGuide::`vftable;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->m_Pos.x = UFG::qVector3::msZero.x;
  this->m_Pos.y = v2;
  this->m_Pos.z = v3;
  *(_WORD *)&this->m_Active = 0;
  this->m_PathQueryState = 0;
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&this->m_PathQueryInput);
  v4 = (signed __int64)&v1->m_PathQueryOutput;
  *(_OWORD *)v4 = (unsigned __int64)&UFG::DaemonQueryOutput::`vftable;
  *(_DWORD *)(v4 + 16) = 0;
  *(_QWORD *)v4 = &UFG::FindPathOutput::`vftable;
  v1->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
  *(_QWORD *)&v1->m_NavParams.m_flags = 65280i64;
  v1->m_NavParams.m_fRadius = 2.0;
}

// File Line: 40
// RVA: 0x643D20
void __fastcall UFG::NavGuide::~NavGuide(UFG::NavGuide *this)
{
  UFG::NavGuide *v1; // rbx
  UFG::DaemonQueryInput *v2; // rdi
  UFG::DaemonManager *v3; // rax
  UFG::FindPathOutput *v4; // rbx
  UFG::NavPath *v5; // rcx
  bool v6; // zf

  v1 = this;
  this->vfptr = (UFG::NavGuideVtbl *)&UFG::NavGuide::`vftable;
  v2 = (UFG::DaemonQueryInput *)&this->m_PathQueryInput.vfptr;
  v3 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::CancelQuery(v3, v2);
  v4 = &v1->m_PathQueryOutput;
  v5 = v4->m_pPath.m_pNavPath;
  if ( v5 )
  {
    v6 = v5->m_uRefCount-- == 1;
    if ( v6 )
      v5->vfptr->__vecDelDtor(v5, 1u);
  }
  v4->vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  v2->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
}

// File Line: 86
// RVA: 0x64D2E0
void __fastcall UFG::NavGuide::FindPath(UFG::NavGuide *this, UFG::qVector3 *startPos, UFG::qVector3 *destPos, float destNavRadius)
{
  UFG::qVector3 *v4; // rsi
  UFG::qVector3 *v5; // r14
  UFG::NavGuide *v6; // rdi
  float v7; // xmm6_4
  UFG::DaemonManager *v8; // rax
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  float v12; // xmm1_4
  bool v13; // al
  float v14; // xmm1_4
  hkVector4f v15; // xmm0
  unsigned int v16; // eax
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  bool v20; // al
  float v21; // xmm1_4
  float v22; // xmm0_4
  hkVector4f v23; // xmm0
  unsigned int v24; // eax
  UFG::HavokNavPosition v25; // [rsp+18h] [rbp-49h]
  UFG::HavokNavPosition v26; // [rsp+58h] [rbp-9h]

  v4 = destPos;
  v5 = startPos;
  v6 = this;
  v7 = destNavRadius;
  if ( (unsigned int)(this->m_PathQueryState - 1) <= 1 )
  {
    v8 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::CancelQuery(v8, (UFG::DaemonQueryInput *)&v6->m_PathQueryInput.vfptr);
  }
  v9 = (__m128)LODWORD(UFG::qVector3::msDirUp.z);
  v10 = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
  v25.m_bValid = 0;
  *(_QWORD *)&v25.m_packedKey = -1i64;
  v10.m128_f32[0] = (float)(UFG::qVector3::msDirUp.y * 0.1) + v5->y;
  v9.m128_f32[0] = (float)(UFG::qVector3::msDirUp.z * 0.1) + v5->z;
  v11 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v25.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v11.m128_f32[0] = (float)(UFG::qVector3::msDirUp.x * 0.1) + v5->x;
  LODWORD(v25.m_vPosition.y) = v10.m128_i32[0];
  v12 = v6->m_NavParams.m_fRadius;
  LODWORD(v25.m_vPosition.z) = v9.m128_i32[0];
  LODWORD(v25.m_vPosition.x) = v11.m128_i32[0];
  v25.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(v11, v9),
                                   _mm_unpacklo_ps(v10, (__m128)(unsigned int)FLOAT_1_0));
  UFG::HavokNavPosition::Validate(&v25, v12, 3.0, 0.0);
  v13 = v25.m_bValid;
  v14 = v25.m_vPosition.y;
  v6->m_PathQueryInput.m_npFrom.m_vPosition.x = v25.m_vPosition.x;
  v6->m_PathQueryInput.m_npFrom.m_vPosition.z = v25.m_vPosition.z;
  v6->m_PathQueryInput.m_npFrom.m_vPosition.y = v14;
  if ( v13 )
  {
    v15.m_quad = (__m128)v25.m_hkvMeshPosition;
    v6->m_PathQueryInput.m_npFrom.m_bValid = v13;
    v6->m_PathQueryInput.m_npFrom.m_packedKey = v25.m_packedKey;
    v16 = v25.m_aiMeshUid;
    v6->m_PathQueryInput.m_npFrom.m_hkvMeshPosition = (hkVector4f)v15.m_quad;
    v6->m_PathQueryInput.m_npFrom.m_aiMeshUid = v16;
  }
  else
  {
    v6->m_PathQueryInput.m_npFrom.m_bValid = 0;
  }
  v17 = (__m128)LODWORD(UFG::qVector3::msDirUp.z);
  v26.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v26.m_bValid = 0;
  *(_QWORD *)&v26.m_packedKey = -1i64;
  v18 = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
  v19 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v18.m128_f32[0] = (float)(UFG::qVector3::msDirUp.y * 0.1) + v4->y;
  v19.m128_f32[0] = (float)(UFG::qVector3::msDirUp.x * 0.1) + v4->x;
  v26.m_vPosition.z = (float)(UFG::qVector3::msDirUp.z * 0.1) + v4->z;
  v17.m128_f32[0] = v26.m_vPosition.z;
  LODWORD(v26.m_vPosition.y) = v18.m128_i32[0];
  LODWORD(v26.m_vPosition.x) = v19.m128_i32[0];
  v26.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(v19, v17),
                                   _mm_unpacklo_ps(v18, (__m128)(unsigned int)FLOAT_1_0));
  if ( v7 <= 1.0 )
    v7 = *(float *)&FLOAT_1_0;
  UFG::HavokNavPosition::Validate(&v26, v7, 7.0, v6->m_NavParams.m_fRadius);
  v20 = v26.m_bValid;
  v21 = v26.m_vPosition.y;
  v6->m_PathQueryInput.m_npTo.m_vPosition.x = v26.m_vPosition.x;
  v22 = v26.m_vPosition.z;
  v6->m_PathQueryInput.m_npTo.m_vPosition.y = v21;
  v6->m_PathQueryInput.m_npTo.m_vPosition.z = v22;
  if ( v20 )
  {
    v23.m_quad = (__m128)v26.m_hkvMeshPosition;
    v6->m_PathQueryInput.m_npTo.m_bValid = v20;
    v6->m_PathQueryInput.m_npTo.m_packedKey = v26.m_packedKey;
    v24 = v26.m_aiMeshUid;
    v6->m_PathQueryInput.m_npTo.m_hkvMeshPosition = (hkVector4f)v23.m_quad;
    v6->m_PathQueryInput.m_npTo.m_aiMeshUid = v24;
  }
  else
  {
    v6->m_PathQueryInput.m_npTo.m_bValid = 0;
  }
  v6->m_PathQueryState = 1;
}

// File Line: 106
// RVA: 0x6498D0
void __fastcall UFG::NavGuide::ClearPath(UFG::NavGuide *this)
{
  UFG::NavGuide *v1; // rdi
  UFG::DaemonManager *v2; // rax
  UFG::NavPath *v3; // rsi
  unsigned int v4; // eax
  __int64 v5; // rbx

  v1 = this;
  if ( (unsigned int)(this->m_PathQueryState - 1) <= 1 )
  {
    v2 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::CancelQuery(v2, (UFG::DaemonQueryInput *)&v1->m_PathQueryInput.vfptr);
  }
  v3 = v1->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( v3 )
  {
    v4 = v3->m_aWaypoints.size;
    if ( v4 )
    {
      v5 = v4;
      do
      {
        UFG::NavPath::RemoveWaypointEnd(v3);
        --v5;
      }
      while ( v5 );
    }
  }
  v1->m_CurrPathPointIndex = 0;
  v1->m_PathQueryState = 0;
}

// File Line: 149
// RVA: 0x64ED00
UFG::qVector3 *__fastcall UFG::NavGuide::GetPathSegmentPos(UFG::NavGuide *this, UFG::qVector3 *result, unsigned int pathPointIndex, UFG::qVector3 *pos)
{
  __int64 v4; // r11
  UFG::NavPath *v5; // r8
  unsigned int v6; // er10
  UFG::NavWaypoint *v7; // r8
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm8_4
  float v11; // xmm3_4
  __m128 v12; // xmm4
  float v13; // xmm5_4
  __m128 v14; // xmm2
  float v15; // xmm10_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm3_4
  float v20; // xmm2_4

  v4 = pathPointIndex;
  v5 = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( v5 )
    v6 = v5->m_aWaypoints.size;
  else
    v6 = 0;
  v7 = v5->m_aWaypoints.p;
  v8 = v7[v4].m_navPosition.m_vPosition.x;
  v9 = v7[v4].m_navPosition.m_vPosition.y;
  v10 = v7[v4].m_navPosition.m_vPosition.z;
  if ( (_DWORD)v4 == v6 - 1 )
  {
    result->x = v8;
    result->y = v9;
    result->z = v10;
  }
  else
  {
    v12 = (__m128)LODWORD(v7[(unsigned int)(v4 + 1)].m_navPosition.m_vPosition.y);
    v11 = v7[(unsigned int)(v4 + 1)].m_navPosition.m_vPosition.x - v8;
    v12.m128_f32[0] = v12.m128_f32[0] - v9;
    v13 = v7[(unsigned int)(v4 + 1)].m_navPosition.m_vPosition.z - v10;
    v14 = v12;
    v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
    LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v14);
    if ( v15 >= 0.001 )
    {
      if ( v14.m128_f32[0] == 0.0 )
        v16 = 0.0;
      else
        v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
      v17 = v12.m128_f32[0] * v16;
      v18 = v13 * v16;
      v19 = v11 * v16;
      v20 = (float)((float)((float)(pos->y - v9) * v17) + (float)((float)(pos->x - v8) * v19))
          + (float)((float)(pos->z - v10) * v18);
      if ( v20 <= 0.0 )
        v20 = 0.0;
      if ( v20 >= v15 )
        v20 = v15;
      result->x = (float)(v19 * v20) + v8;
      result->y = (float)(v17 * v20) + v9;
      result->z = (float)(v18 * v20) + v10;
    }
    else
    {
      result->x = v8;
      result->y = v9;
      result->z = v10;
    }
  }
  return result;
}

// File Line: 171
// RVA: 0x64EBD0
UFG::qVector3 *__fastcall UFG::NavGuide::GetPathSegmentDir(UFG::NavGuide *this, UFG::qVector3 *result, unsigned int pathPointIndex)
{
  unsigned int v3; // er10
  UFG::NavPath *v4; // r8
  unsigned int v5; // eax
  UFG::NavWaypoint *v6; // r8
  float v7; // xmm2_4
  __m128 v8; // xmm3
  float v9; // xmm4_4
  __m128 v10; // xmm5
  float v11; // xmm1_4
  UFG::qVector3 *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4

  v3 = pathPointIndex;
  v4 = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( v4 )
  {
    v5 = v4->m_aWaypoints.size;
    if ( v5 == 1 )
    {
      v14 = UFG::qVector3::msDirFront.y;
      v12 = result;
      result->x = UFG::qVector3::msDirFront.x;
      v15 = UFG::qVector3::msDirFront.z;
      result->y = v14;
      result->z = v15;
      return v12;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v3 == v5 - 1 )
    --v3;
  v6 = v4->m_aWaypoints.p;
  v8 = (__m128)LODWORD(v6[v3 + 1].m_navPosition.m_vPosition.y);
  v7 = v6[v3 + 1].m_navPosition.m_vPosition.x - v6[v3].m_navPosition.m_vPosition.x;
  v8.m128_f32[0] = v8.m128_f32[0] - v6[v3].m_navPosition.m_vPosition.y;
  v9 = v6[v3 + 1].m_navPosition.m_vPosition.z - v6[v3].m_navPosition.m_vPosition.z;
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] >= 0.0000010000001 )
  {
    v16 = 0.0;
    if ( v10.m128_f32[0] != 0.0 )
      v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
    v12 = result;
    result->x = v7 * v16;
    result->y = v8.m128_f32[0] * v16;
    result->z = v9 * v16;
  }
  else
  {
    v11 = UFG::qVector3::msDirFront.y;
    v12 = result;
    result->x = UFG::qVector3::msDirFront.x;
    v13 = UFG::qVector3::msDirFront.z;
    result->y = v11;
    result->z = v13;
  }
  return v12;
}

// File Line: 196
// RVA: 0x662C90
void __fastcall UFG::NavGuide::UpdatePathQuery(UFG::NavGuide *this)
{
  UFG::NavGuide::PathQueryState v1; // eax
  UFG::NavGuide *v2; // rsi
  UFG::DaemonManager *v3; // rax
  UFG::DaemonOutputStatus v4; // ecx
  int v5; // ecx

  v1 = this->m_PathQueryState;
  v2 = this;
  if ( v1 == 1 )
  {
    if ( this->m_PathQueryInput.m_npFrom.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(
           this->m_PathQueryInput.m_npFrom.m_packedKey,
           this->m_PathQueryInput.m_npFrom.m_aiMeshUid)
      && v2->m_PathQueryInput.m_npTo.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(
           v2->m_PathQueryInput.m_npTo.m_packedKey,
           v2->m_PathQueryInput.m_npTo.m_aiMeshUid) )
    {
      v2->m_PathQueryInput.m_pNavParams = &v2->m_NavParams;
      v3 = UFG::DaemonManager::Instance();
      UFG::DaemonManager::SubmitQuery(
        v3,
        (UFG::DaemonQueryInput *)&v2->m_PathQueryInput.vfptr,
        (UFG::DaemonQueryOutput *)&v2->m_PathQueryOutput.vfptr);
      v2->m_PathQueryState = 2;
    }
  }
  else if ( v1 == 2 )
  {
    v4 = this->m_PathQueryOutput.m_status;
    if ( v4 )
    {
      v5 = v4 - 3;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          v2->m_PathQueryState = 4;
          UFG::NavGuide::ClearPath(v2);
        }
      }
      else
      {
        v2->m_PathQueryState = 3;
      }
    }
    else
    {
      v2->m_PathQueryState = 0;
    }
  }
}

// File Line: 241
// RVA: 0x662B60
void __fastcall UFG::NavGuide::UpdatePathPosition(UFG::NavGuide *this, UFG::qVector3 *pos)
{
  float v2; // eax
  float v3; // xmm7_4
  float v4; // xmm8_4
  UFG::NavGuide *v5; // rbp
  UFG::NavPath *v6; // rax
  unsigned int v7; // edi
  unsigned int v8; // esi
  float v9; // xmm6_4
  unsigned int v10; // ebx
  float v11; // xmm9_4
  UFG::qVector3 result; // [rsp+20h] [rbp-58h]

  v2 = pos->x;
  v3 = pos->y;
  v4 = pos->z;
  this->m_Pos.y = v3;
  this->m_Pos.x = v2;
  v5 = this;
  this->m_Pos.z = v4;
  if ( this->m_Active )
  {
    v6 = this->m_PathQueryOutput.m_pPath.m_pNavPath;
    if ( v6 )
    {
      v7 = v6->m_aWaypoints.size;
      if ( v7 )
      {
        v8 = 0;
        v9 = FLOAT_3_4028235e38;
        v10 = 0;
        if ( v7 )
        {
          v11 = this->m_Pos.x;
          do
          {
            UFG::NavGuide::GetPathSegmentPos(v5, &result, v10, &v5->m_Pos);
            if ( (float)((float)((float)((float)(v3 - result.y) * (float)(v3 - result.y))
                               + (float)((float)(v11 - result.x) * (float)(v11 - result.x)))
                       + (float)((float)(v4 - result.z) * (float)(v4 - result.z))) < v9 )
            {
              v9 = (float)((float)((float)(v3 - result.y) * (float)(v3 - result.y))
                         + (float)((float)(v11 - result.x) * (float)(v11 - result.x)))
                 + (float)((float)(v4 - result.z) * (float)(v4 - result.z));
              v8 = v10;
            }
            ++v10;
          }
          while ( v10 < v7 );
        }
        v5->m_CurrPathPointIndex = v8;
      }
    }
  }
}

