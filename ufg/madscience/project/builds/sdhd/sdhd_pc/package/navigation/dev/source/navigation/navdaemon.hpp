// File Line: 33
// RVA: 0xE3AB0
void __fastcall UFG::FindPathImmediateQuery::FindPathImmediateQuery(UFG::FindPathImmediateQuery *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  this->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
  *(_QWORD *)&this->m_daemonType = 0i64;
  this->m_mode = Mode_Immediate;
  this->m_pOutput = 0i64;
  this->vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathImmediateQuery::`vftable;
  this->m_npFrom.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_npFrom.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npFrom.m_vPosition.y = y;
  this->m_npFrom.m_vPosition.z = z;
  this->m_npFrom.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npFrom.m_bValid = 0;
  this->m_npFrom.m_hkvMeshPosition = (hkVector4f)hkvZero_0.m_quad;
  *(_QWORD *)&this->m_npFrom.m_packedKey = -1i64;
  this->m_npTo.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->m_npTo.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npTo.m_vPosition.y = v3;
  this->m_npTo.m_vPosition.z = v4;
  this->m_npTo.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npTo.m_bValid = 0;
  this->m_npTo.m_hkvMeshPosition = (hkVector4f)hkvZero_0.m_quad;
  *(_QWORD *)&this->m_npTo.m_packedKey = -1i64;
  this->m_pNavParams = 0i64;
  this->m_maxSearchIterations = -1;
}

// File Line: 92
// RVA: 0x3401A0
void __fastcall UFG::FindPathMultiDestPrioritizedImmediateQuery::AddDestination(
        UFG::FindPathMultiDestPrioritizedImmediateQuery *this,
        UFG::HavokNavPosition *npPosition,
        float fPriority)
{
  __int64 size; // rbp
  UFG::qArray<UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination,0> *p_m_aPrioritizedDestinations; // rsi
  unsigned int capacity; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  float x; // eax
  float z; // xmm1_4
  hkVector4f *v11; // rcx
  bool m_bValid; // al

  size = this->m_aPrioritizedDestinations.size;
  p_m_aPrioritizedDestinations = &this->m_aPrioritizedDestinations;
  capacity = this->m_aPrioritizedDestinations.capacity;
  v7 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v8 = 2 * capacity;
    else
      v8 = 1;
    for ( ; v8 < v7; v8 *= 2 )
      ;
    if ( v8 - v7 > 0x10000 )
      v8 = size + 65537;
    UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0>::Reallocate(
      (UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0> *)&this->m_aPrioritizedDestinations,
      v8,
      "qArray.Add");
  }
  p_m_aPrioritizedDestinations->size = v7;
  x = npPosition->m_vPosition.x;
  z = npPosition->m_vPosition.z;
  v11 = (hkVector4f *)&p_m_aPrioritizedDestinations->p[size];
  v11->m_quad.m128_i32[3] = LODWORD(npPosition->m_vPosition.y);
  v11[1].m_quad.m128_f32[0] = z;
  v11->m_quad.m128_f32[2] = x;
  m_bValid = npPosition->m_bValid;
  if ( m_bValid )
  {
    v11[1].m_quad.m128_i8[8] = m_bValid;
    v11[2] = npPosition->m_hkvMeshPosition;
    v11[3].m_quad.m128_i32[0] = npPosition->m_packedKey;
    v11[3].m_quad.m128_i32[1] = npPosition->m_aiMeshUid;
  }
  else
  {
    v11[1].m_quad.m128_i8[8] = 0;
  }
  v11[4].m_quad.m128_f32[0] = fPriority;
}

// File Line: 167
// RVA: 0x3410B0
void __fastcall UFG::FleeTraversalImmediateQuery::AddThreat(
        UFG::FleeTraversalImmediateQuery *this,
        UFG::HavokNavPosition *navPosition,
        float radius)
{
  __int64 size; // rbp
  UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0> *p_mThreats; // rsi
  unsigned int capacity; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  float x; // eax
  float z; // xmm1_4
  hkVector4f *v11; // rcx
  bool m_bValid; // al

  size = this->mThreats.size;
  p_mThreats = &this->mThreats;
  capacity = this->mThreats.capacity;
  v7 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v8 = 2 * capacity;
    else
      v8 = 1;
    for ( ; v8 < v7; v8 *= 2 )
      ;
    if ( v8 - v7 > 0x10000 )
      v8 = size + 65537;
    UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0>::Reallocate(&this->mThreats, v8, "qArray.Add");
  }
  p_mThreats->size = v7;
  x = navPosition->m_vPosition.x;
  z = navPosition->m_vPosition.z;
  v11 = (hkVector4f *)&p_mThreats->p[size];
  v11->m_quad.m128_i32[3] = LODWORD(navPosition->m_vPosition.y);
  v11[1].m_quad.m128_f32[0] = z;
  v11->m_quad.m128_f32[2] = x;
  m_bValid = navPosition->m_bValid;
  if ( m_bValid )
  {
    v11[1].m_quad.m128_i8[8] = m_bValid;
    v11[2] = navPosition->m_hkvMeshPosition;
    v11[3].m_quad.m128_i32[0] = navPosition->m_packedKey;
    v11[3].m_quad.m128_i32[1] = navPosition->m_aiMeshUid;
  }
  else
  {
    v11[1].m_quad.m128_i8[8] = 0;
  }
  v11[4].m_quad.m128_f32[0] = radius;
}

