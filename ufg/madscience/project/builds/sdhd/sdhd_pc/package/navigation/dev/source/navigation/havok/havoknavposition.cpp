// File Line: 9
// RVA: 0xF3FB0
void __fastcall UFG::HavokNavPosition::Validate(UFG::HavokNavPosition *this, float fToleranceXY, float fToleranceZ, float fRadius)
{
  UFG::HavokNavPosition *v4; // rbx
  hkVector4f hkvNewPosition; // [rsp+20h] [rbp-28h]

  v4 = this;
  UFG::HavokNavPosition::FindClosestMeshPosition(this, fToleranceXY, fToleranceZ);
  if ( fRadius > 0.0
    && UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(&v4->m_hkvMeshPosition, &hkvNewPosition, fRadius) )
  {
    v4->m_hkvMeshPosition = (hkVector4f)hkvNewPosition.m_quad;
  }
}

// File Line: 25
// RVA: 0xEAAA0
void __fastcall UFG::HavokNavPosition::FindClosestMeshPosition(UFG::HavokNavPosition *this, float fToleranceXY, float fToleranceZ)
{
  unsigned int v3; // er8
  UFG::HavokNavPosition *v4; // rbx
  unsigned int *v5; // rax
  unsigned int v6; // eax
  hkVector4f hkvPoint; // [rsp+40h] [rbp-18h]

  v3 = this->m_packedKey;
  v4 = this;
  v5 = &this->m_aiMeshUid;
  hkvPoint.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)LODWORD(this->m_vPosition.x), (__m128)LODWORD(this->m_vPosition.z)),
                      _mm_unpacklo_ps((__m128)LODWORD(this->m_vPosition.y), (__m128)(unsigned int)FLOAT_1_0));
  if ( v3 == -1 )
  {
    v6 = UFG::HavokAIUtilGame::FindClosestMeshPosition2d(
           &hkvPoint,
           fToleranceXY,
           fToleranceZ,
           &this->m_hkvMeshPosition,
           v5);
    v4->m_bValid = 1;
    v4->m_packedKey = v6;
    if ( v6 == -1 )
      v4->m_hkvMeshPosition = 0i64;
  }
  else
  {
    this->m_packedKey = UFG::HavokAIUtilGame::FindClosestMeshPosition2dCoherent(
                          &hkvPoint,
                          &this->m_hkvMeshPosition,
                          v3,
                          *v5,
                          fToleranceXY,
                          fToleranceZ,
                          &this->m_hkvMeshPosition,
                          &this->m_aiMeshUid);
    v4->m_bValid = 1;
  }
}

// File Line: 47
// RVA: 0xECFB0
__int64 __fastcall UFG::HavokNavPosition::GetMeshMaterialFlags(UFG::HavokNavPosition *this)
{
  UFG::HavokNavPosition *v1; // rbx
  hkaiNavMeshQueryMediator *v2; // rax
  unsigned int v3; // er8
  signed __int64 v4; // rdx
  int v5; // er8
  __int64 v6; // r9
  int v7; // edx
  int v8; // eax
  int v10; // er10
  unsigned int *v11; // rdx

  v1 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr->IsMeshPositionValid)() )
    return 0i64;
  if ( !UFG::NavManager::ms_pInstance )
    return 0i64;
  v2 = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  if ( !v2 )
    return 0i64;
  v3 = v1->m_packedKey;
  v4 = 3i64 * (v3 >> 22);
  v5 = v3 & 0x3FFFFF;
  v6 = *((_QWORD *)v2[1].vfptr[2].__vecDelDtor + 2 * v4);
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

