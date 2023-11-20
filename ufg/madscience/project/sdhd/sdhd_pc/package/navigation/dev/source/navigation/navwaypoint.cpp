// File Line: 15
// RVA: 0x262CD0
void __fastcall UFG::NavWaypoint::NavWaypoint(UFG::NavWaypoint *this)
{
  float v1; // xmm2_4
  float v2; // xmm0_4

  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v1 = UFG::qVector3::msZero.z;
  v2 = UFG::qVector3::msZero.x;
  this->m_navPosition.m_vPosition.y = UFG::qVector3::msZero.y;
  this->m_navPosition.m_vPosition.z = v1;
  this->m_navPosition.m_vPosition.x = v2;
  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_navPosition.m_bValid = 0;
  *(_QWORD *)&this->m_navPosition.m_packedKey = -1i64;
  this->m_navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(UFG::qVector3::msZero.x),
                                                     (__m128)LODWORD(UFG::qVector3::msZero.z)),
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(UFG::qVector3::msZero.y),
                                                     (__m128)(unsigned int)FLOAT_1_0));
  this->m_pNavObject = 0i64;
  *(_WORD *)&this->m_stopPoint = 0;
  this->m_canSmooth = 1;
}

// File Line: 25
// RVA: 0x262BE0
void __fastcall UFG::NavWaypoint::NavWaypoint(UFG::NavWaypoint *this, UFG::qVector3 *vPosition)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v2 = vPosition->y;
  v3 = vPosition->z;
  this->m_navPosition.m_vPosition.x = vPosition->x;
  this->m_navPosition.m_vPosition.y = v2;
  this->m_navPosition.m_vPosition.z = v3;
  this->m_navPosition.m_bValid = 0;
  *(_QWORD *)&this->m_navPosition.m_packedKey = -1i64;
  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(vPosition->x),
                                                     (__m128)LODWORD(vPosition->z)),
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(vPosition->y),
                                                     (__m128)(unsigned int)FLOAT_1_0));
  this->m_pNavObject = 0i64;
  *(_WORD *)&this->m_stopPoint = 0;
  this->m_canSmooth = 1;
}

// File Line: 44
// RVA: 0x262C60
void __fastcall UFG::NavWaypoint::NavWaypoint(UFG::NavWaypoint *this, UFG::qVector3 *vPosition, UFG::NavObject *pObject)
{
  float v3; // xmm1_4
  float v4; // xmm0_4

  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v3 = vPosition->y;
  v4 = vPosition->z;
  this->m_navPosition.m_vPosition.x = vPosition->x;
  this->m_navPosition.m_vPosition.y = v3;
  this->m_navPosition.m_vPosition.z = v4;
  this->m_navPosition.m_bValid = 0;
  *(_QWORD *)&this->m_navPosition.m_packedKey = -1i64;
  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(vPosition->x),
                                                     (__m128)LODWORD(vPosition->z)),
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(vPosition->y),
                                                     (__m128)(unsigned int)FLOAT_1_0));
  this->m_pNavObject = pObject;
  *(_WORD *)&this->m_stopPoint = 0;
  this->m_canSmooth = 1;
}

