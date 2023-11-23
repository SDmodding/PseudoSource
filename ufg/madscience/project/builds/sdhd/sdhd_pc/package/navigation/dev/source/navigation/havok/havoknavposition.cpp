// File Line: 9
// RVA: 0xF3FB0
void __fastcall UFG::HavokNavPosition::Validate(
        UFG::HavokNavPosition *this,
        double fToleranceXY,
        double fToleranceZ,
        double fRadius)
{
  hkVector4f hkvNewPosition; // [rsp+20h] [rbp-28h] BYREF

  UFG::HavokNavPosition::FindClosestMeshPosition(this, fToleranceXY, fToleranceZ);
  if ( *(float *)&fRadius > 0.0 )
  {
    if ( UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(&this->m_hkvMeshPosition, &hkvNewPosition, fRadius) )
      this->m_hkvMeshPosition = (hkVector4f)hkvNewPosition.m_quad;
  }
}

// File Line: 25
// RVA: 0xEAAA0
void __fastcall UFG::HavokNavPosition::FindClosestMeshPosition(
        UFG::HavokNavPosition *this,
        double fToleranceXY,
        double fToleranceZ)
{
  unsigned int m_packedKey; // r8d
  unsigned int *p_m_aiMeshUid; // rax
  unsigned int ClosestMeshPosition2d; // eax
  hkVector4f hkvPoint; // [rsp+40h] [rbp-18h] BYREF

  m_packedKey = this->m_packedKey;
  p_m_aiMeshUid = &this->m_aiMeshUid;
  hkvPoint.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)LODWORD(this->m_vPosition.x), (__m128)LODWORD(this->m_vPosition.z)),
                      _mm_unpacklo_ps((__m128)LODWORD(this->m_vPosition.y), (__m128)(unsigned int)FLOAT_1_0));
  if ( m_packedKey == -1 )
  {
    ClosestMeshPosition2d = UFG::HavokAIUtilGame::FindClosestMeshPosition2d(
                              &hkvPoint,
                              fToleranceXY,
                              fToleranceZ,
                              &this->m_hkvMeshPosition,
                              p_m_aiMeshUid);
    this->m_bValid = 1;
    this->m_packedKey = ClosestMeshPosition2d;
    if ( ClosestMeshPosition2d == -1 )
      this->m_hkvMeshPosition = 0i64;
  }
  else
  {
    this->m_packedKey = UFG::HavokAIUtilGame::FindClosestMeshPosition2dCoherent(
                          &hkvPoint,
                          &this->m_hkvMeshPosition,
                          m_packedKey,
                          *p_m_aiMeshUid,
                          *(float *)&fToleranceXY,
                          *(float *)&fToleranceZ,
                          &this->m_hkvMeshPosition,
                          &this->m_aiMeshUid);
    this->m_bValid = 1;
  }
}

// File Line: 47
// RVA: 0xECFB0
__int64 __fastcall UFG::HavokNavPosition::GetMeshMaterialFlags(UFG::HavokNavPosition *this)
{
  hkaiNavMeshQueryMediator *DynamicQueryMediator; // rax
  unsigned int m_packedKey; // r8d
  __int64 v4; // rdx
  int v5; // r8d
  __int64 v6; // r9
  int v7; // edx
  int v8; // eax
  int v10; // r10d
  unsigned int *v11; // rdx

  if ( !this->vfptr->IsMeshPositionValid(this) )
    return 0i64;
  if ( !UFG::NavManager::ms_pInstance )
    return 0i64;
  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  if ( !DynamicQueryMediator )
    return 0i64;
  m_packedKey = this->m_packedKey;
  v4 = 3i64 * (m_packedKey >> 22);
  v5 = m_packedKey & 0x3FFFFF;
  v6 = *((_QWORD *)DynamicQueryMediator[1].vfptr[2].__vecDelDtor + 2 * v4);
  if ( !v6 )
    return 0i64;
  v7 = *(_DWORD *)(v6 + 72);
  if ( !v7 )
    return 0i64;
  v8 = *(_DWORD *)(v6 + 24);
  if ( v5 >= v8 )
    return *(unsigned int *)(*(_QWORD *)(v6 + 384) + 4i64 * v7 * (v5 - v8));
  if ( *(_DWORD *)(v6 + 232) )
    v10 = *(_DWORD *)(*(_QWORD *)(v6 + 224) + 4i64 * v5);
  else
    v10 = v5;
  if ( v10 == -1 )
    v11 = (unsigned int *)(*(_QWORD *)(v6 + 64) + 4i64 * v5 * v7);
  else
    v11 = (unsigned int *)(*(_QWORD *)(v6 + 352) + 4i64 * v7 * v10);
  return *v11;
}

