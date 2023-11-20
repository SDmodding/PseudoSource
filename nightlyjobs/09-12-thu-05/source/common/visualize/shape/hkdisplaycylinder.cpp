// File Line: 17
// RVA: 0xE73060
void __fastcall hkDisplayCylinder::hkDisplayCylinder(hkDisplayCylinder *this, hkVector4f *top, hkVector4f *bottom, float radius, int numSides, int numHeightSegments)
{
  __m128 v6; // xmm1

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 9;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayCylinder::`vftable;
  this->m_numSides = numSides;
  this->m_numHeightSegments = numHeightSegments;
  this->m_top = (hkVector4f)top->m_quad;
  v6 = bottom->m_quad;
  this->m_radius = radius;
  this->m_bottom.m_quad = v6;
}

// File Line: 33
// RVA: 0xE730F0
void __fastcall hkDisplayCylinder::buildGeometry(hkDisplayCylinder *this)
{
  hkVector4f *v1; // rbx
  _QWORD **v2; // rax
  __int64 v3; // rax
  int v4; // er9
  float v5; // xmm2_4
  int numHeightSegments; // ST20_4

  v1 = (hkVector4f *)this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 48i64);
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable;
    *(_DWORD *)(v3 + 28) = 2147483648;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_DWORD *)(v3 + 24) = 0;
    *(_QWORD *)(v3 + 32) = 0i64;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 44) = 2147483648;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v1[9].m_quad.m128_i32[1];
  v5 = v1[9].m_quad.m128_f32[0];
  v1[1].m_quad.m128_u64[0] = v3;
  numHeightSegments = v1[9].m_quad.m128_i32[2];
  hkGeometryUtils::createCylinderGeometry(v1 + 7, v1 + 8, v5, v4);
}

// File Line: 39
// RVA: 0xE73190
void __fastcall hkDisplayCylinder::getWireframeGeometry(hkDisplayCylinder *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  ;
}

