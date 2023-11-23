// File Line: 17
// RVA: 0xE73060
void __fastcall hkDisplayCylinder::hkDisplayCylinder(
        hkDisplayCylinder *this,
        hkVector4f *top,
        hkVector4f *bottom,
        float radius,
        int numSides,
        int numHeightSegments)
{
  __m128 m_quad; // xmm1

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_CYLINDER;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayCylinder::`vftable;
  this->m_numSides = numSides;
  this->m_numHeightSegments = numHeightSegments;
  this->m_top = (hkVector4f)top->m_quad;
  m_quad = bottom->m_quad;
  this->m_radius = radius;
  this->m_bottom.m_quad = m_quad;
}

// File Line: 33
// RVA: 0xE730F0
void __fastcall hkDisplayCylinder::buildGeometry(hkDisplayCylinder *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  int m_numSides; // r9d
  float m_radius; // xmm2_4

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable;
    *(_DWORD *)(v3 + 28) = 0x80000000;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_DWORD *)(v3 + 24) = 0;
    *(_QWORD *)(v3 + 32) = 0i64;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 44) = 0x80000000;
  }
  else
  {
    v3 = 0i64;
  }
  m_numSides = this->m_numSides;
  m_radius = this->m_radius;
  this->m_geometry = (hkGeometry *)v3;
  hkGeometryUtils::createCylinderGeometry(&this->m_top, &this->m_bottom, m_radius, m_numSides);
}

// File Line: 39
// RVA: 0xE73190
void __fastcall hkDisplayCylinder::getWireframeGeometry(
        hkDisplayCylinder *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  ;
}

