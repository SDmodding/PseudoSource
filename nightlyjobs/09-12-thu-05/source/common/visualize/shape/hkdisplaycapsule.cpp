// File Line: 16
// RVA: 0xE723C0
void __fastcall hkDisplayCapsule::hkDisplayCapsule(
        hkDisplayCapsule *this,
        hkVector4f *top,
        hkVector4f *bottom,
        float radius,
        int numSides,
        int numHeightSegments)
{
  __m128 m_quad; // xmm1

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_CAPSULE;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayCapsule::`vftable;
  this->m_numSides = numSides;
  this->m_numHeightSegments = numHeightSegments;
  this->m_top = (hkVector4f)top->m_quad;
  m_quad = bottom->m_quad;
  this->m_radius = radius;
  this->m_bottom.m_quad = m_quad;
}

// File Line: 23
// RVA: 0xE72450
void __fastcall hkDisplayCapsule::buildGeometry(hkDisplayCapsule *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  int m_numHeightSegments; // r9d
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
  m_numHeightSegments = this->m_numHeightSegments;
  m_radius = this->m_radius;
  this->m_geometry = (hkGeometry *)v3;
  hkGeometryUtils::createCapsuleGeometry(&this->m_top, &this->m_bottom, m_radius, m_numHeightSegments);
}

// File Line: 30
// RVA: 0xE72500
void __fastcall hkDisplayCapsule::getWireframeGeometry(
        hkDisplayCapsule *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  ;
}

