// File Line: 15
// RVA: 0x262CD0
void __fastcall UFG::NavWaypoint::NavWaypoint(UFG::NavWaypoint *this)
{
  float z; // xmm2_4
  float x; // xmm0_4

  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->m_navPosition.m_vPosition.y = UFG::qVector3::msZero.y;
  this->m_navPosition.m_vPosition.z = z;
  this->m_navPosition.m_vPosition.x = x;
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
  float y; // xmm1_4
  float z; // xmm0_4

  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = vPosition->y;
  z = vPosition->z;
  this->m_navPosition.m_vPosition.x = vPosition->x;
  this->m_navPosition.m_vPosition.y = y;
  this->m_navPosition.m_vPosition.z = z;
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
void __fastcall UFG::NavWaypoint::NavWaypoint(
        UFG::NavWaypoint *this,
        UFG::qVector3 *vPosition,
        UFG::NavObject *pObject)
{
  float y; // xmm1_4
  float z; // xmm0_4

  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = vPosition->y;
  z = vPosition->z;
  this->m_navPosition.m_vPosition.x = vPosition->x;
  this->m_navPosition.m_vPosition.y = y;
  this->m_navPosition.m_vPosition.z = z;
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

