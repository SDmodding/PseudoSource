// File Line: 16
// RVA: 0xE7EF80
void __fastcall hkDisplayTaperedCapsule::hkDisplayTaperedCapsule(
        hkDisplayTaperedCapsule *this,
        hkVector4f *top,
        hkVector4f *bottom,
        float topRadius,
        float bottomRadius,
        int numSides,
        int numHeightSegments)
{
  __m128 m_quad; // xmm1

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_TAPERED_CAPSULE;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayTaperedCapsule::`vftable;
  this->m_numSides = numSides;
  this->m_numHeightSegments = numHeightSegments;
  this->m_top = (hkVector4f)top->m_quad;
  m_quad = bottom->m_quad;
  this->m_topRadius = topRadius;
  this->m_bottomRadius = bottomRadius;
  this->m_bottom.m_quad = m_quad;
}

// File Line: 24
// RVA: 0xE7F020
void __fastcall hkDisplayTaperedCapsule::buildGeometry(hkDisplayTaperedCapsule *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  float m_bottomRadius; // xmm3_4
  float m_topRadius; // xmm2_4

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
  m_bottomRadius = this->m_bottomRadius;
  m_topRadius = this->m_topRadius;
  this->m_geometry = (hkGeometry *)v3;
  hkGeometryUtils::createTaperedCapsuleGeometry(&this->m_top, &this->m_bottom, m_topRadius, m_bottomRadius);
}

// File Line: 31
// RVA: 0xE7F0E0
void __fastcall hkDisplayTaperedCapsule::getWireframeGeometry(
        hkDisplayTaperedCapsule *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *alloc)
{
  ;
}

