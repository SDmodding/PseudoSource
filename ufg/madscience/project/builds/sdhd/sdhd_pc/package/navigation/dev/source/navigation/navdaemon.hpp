// File Line: 33
// RVA: 0xE3AB0
void __fastcall UFG::FindPathImmediateQuery::FindPathImmediateQuery(UFG::FindPathImmediateQuery *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  this->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable';
  *(_QWORD *)&this->m_daemonType = 0i64;
  this->m_mode = 0;
  this->m_pOutput = 0i64;
  this->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathImmediateQuery::`vftable';
  this->m_npFrom.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->m_npFrom.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npFrom.m_vPosition.y = v1;
  this->m_npFrom.m_vPosition.z = v2;
  this->m_npFrom.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
  this->m_npFrom.m_bValid = 0;
  this->m_npFrom.m_hkvMeshPosition = (hkVector4f)hkvZero_0.m_quad;
  *(_QWORD *)&this->m_npFrom.m_packedKey = -1i64;
  this->m_npTo.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->m_npTo.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npTo.m_vPosition.y = v3;
  this->m_npTo.m_vPosition.z = v4;
  this->m_npTo.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
  this->m_npTo.m_bValid = 0;
  this->m_npTo.m_hkvMeshPosition = (hkVector4f)hkvZero_0.m_quad;
  *(_QWORD *)&this->m_npTo.m_packedKey = -1i64;
  this->m_pNavParams = 0i64;
  this->m_maxSearchIterations = -1;
}

// File Line: 92
// RVA: 0x3401A0
void __fastcall UFG::FindPathMultiDestPrioritizedImmediateQuery::AddDestination(UFG::FindPathMultiDestPrioritizedImmediateQuery *this, UFG::HavokNavPosition *npPosition, float fPriority)
{
  __int64 v3; // rbp
  UFG::qArray<UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination,0> *v4; // rsi
  UFG::HavokNavPosition *v5; // rdi
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  float v9; // eax
  float v10; // xmm1_4
  signed __int64 v11; // rcx
  bool v12; // al

  v3 = this->m_aPrioritizedDestinations.size;
  v4 = &this->m_aPrioritizedDestinations;
  v5 = npPosition;
  v6 = this->m_aPrioritizedDestinations.capacity;
  v7 = v3 + 1;
  if ( (signed int)v3 + 1 > v6 )
  {
    if ( v6 )
      v8 = 2 * v6;
    else
      v8 = 1;
    for ( ; v8 < v7; v8 *= 2 )
      ;
    if ( v8 - v7 > 0x10000 )
      v8 = v3 + 65537;
    UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0>::Reallocate(
      (UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0> *)&this->m_aPrioritizedDestinations,
      v8,
      "qArray.Add");
  }
  v4->size = v7;
  v9 = v5->m_vPosition.x;
  v10 = v5->m_vPosition.z;
  v11 = (signed __int64)&v4->p[v3];
  *(float *)(v11 + 12) = v5->m_vPosition.y;
  *(float *)(v11 + 16) = v10;
  *(float *)(v11 + 8) = v9;
  v12 = v5->m_bValid;
  if ( v12 )
  {
    *(_BYTE *)(v11 + 24) = v12;
    *(hkVector4f *)(v11 + 32) = v5->m_hkvMeshPosition;
    *(_DWORD *)(v11 + 48) = v5->m_packedKey;
    *(_DWORD *)(v11 + 52) = v5->m_aiMeshUid;
  }
  else
  {
    *(_BYTE *)(v11 + 24) = 0;
  }
  *(float *)(v11 + 64) = fPriority;
}

// File Line: 167
// RVA: 0x3410B0
void __fastcall UFG::FleeTraversalImmediateQuery::AddThreat(UFG::FleeTraversalImmediateQuery *this, UFG::HavokNavPosition *navPosition, float radius)
{
  __int64 v3; // rbp
  UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0> *v4; // rsi
  UFG::HavokNavPosition *v5; // rdi
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  float v9; // eax
  float v10; // xmm1_4
  signed __int64 v11; // rcx
  bool v12; // al

  v3 = this->mThreats.size;
  v4 = &this->mThreats;
  v5 = navPosition;
  v6 = this->mThreats.capacity;
  v7 = v3 + 1;
  if ( (signed int)v3 + 1 > v6 )
  {
    if ( v6 )
      v8 = 2 * v6;
    else
      v8 = 1;
    for ( ; v8 < v7; v8 *= 2 )
      ;
    if ( v8 - v7 > 0x10000 )
      v8 = v3 + 65537;
    UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0>::Reallocate(&this->mThreats, v8, "qArray.Add");
  }
  v4->size = v7;
  v9 = v5->m_vPosition.x;
  v10 = v5->m_vPosition.z;
  v11 = (signed __int64)&v4->p[v3];
  *(float *)(v11 + 12) = v5->m_vPosition.y;
  *(float *)(v11 + 16) = v10;
  *(float *)(v11 + 8) = v9;
  v12 = v5->m_bValid;
  if ( v12 )
  {
    *(_BYTE *)(v11 + 24) = v12;
    *(hkVector4f *)(v11 + 32) = v5->m_hkvMeshPosition;
    *(_DWORD *)(v11 + 48) = v5->m_packedKey;
    *(_DWORD *)(v11 + 52) = v5->m_aiMeshUid;
  }
  else
  {
    *(_BYTE *)(v11 + 24) = 0;
  }
  *(float *)(v11 + 64) = radius;
}

