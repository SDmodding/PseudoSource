// File Line: 51
// RVA: 0x262550
void __fastcall UFG::FindPathDeferredQuery::FindPathDeferredQuery(UFG::FindPathDeferredQuery *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  this->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
  *(_QWORD *)&this->m_daemonType = 0i64;
  this->m_mode = 1;
  this->m_pOutput = 0i64;
  this->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathDeferredQuery::`vftable;
  this->m_npFrom.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->m_npFrom.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npFrom.m_vPosition.y = v1;
  this->m_npFrom.m_vPosition.z = v2;
  this->m_npFrom.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npFrom.m_bValid = 0;
  this->m_npFrom.m_hkvMeshPosition = (hkVector4f)hkvZero_5.m_quad;
  *(_QWORD *)&this->m_npFrom.m_packedKey = -1i64;
  this->m_npTo.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->m_npTo.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npTo.m_vPosition.y = v3;
  this->m_npTo.m_vPosition.z = v4;
  this->m_npTo.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npTo.m_bValid = 0;
  this->m_npTo.m_hkvMeshPosition = (hkVector4f)hkvZero_5.m_quad;
  *(_QWORD *)&this->m_npTo.m_packedKey = -1i64;
  this->m_pNavParams = 0i64;
  this->m_maxSearchIterations = -1;
}

// File Line: 210
// RVA: 0x5195A0
void __fastcall UFG::SpawnTraversalImmediateQuery::SpawnTraversalImmediateQuery(UFG::SpawnTraversalImmediateQuery *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  this->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
  this->m_daemonType = 0;
  *(_QWORD *)&this->m_internalType = 4i64;
  this->m_pOutput = 0i64;
  this->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::SpawnTraversalImmediateQuery::`vftable;
  this->mpNavParams = 0i64;
  this->mSearchOrigin.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->mSearchOrigin.m_vPosition.x = UFG::qVector3::msZero.x;
  this->mSearchOrigin.m_vPosition.y = v1;
  this->mSearchOrigin.m_vPosition.z = v2;
  this->mSearchOrigin.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->mSearchOrigin.m_bValid = 0;
  *(_QWORD *)&this->mSearchOrigin.m_packedKey = -1i64;
  this->mSearchOrigin.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(UFG::qVector3::msZero.x),
                                                     (__m128)LODWORD(UFG::qVector3::msZero.z)),
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(UFG::qVector3::msZero.y),
                                                     (__m128)(unsigned int)FLOAT_1_0));
  v3 = UFG::qVector3::msDirFront.y;
  v4 = UFG::qVector3::msDirFront.z;
  this->mSearchDirection.x = UFG::qVector3::msDirFront.x;
  this->mSearchDirection.y = v3;
  this->mSearchDirection.z = v4;
  this->mSearchRadius = 0.0;
  *(_QWORD *)&this->mRoadCost = -1082130432i64;
}

