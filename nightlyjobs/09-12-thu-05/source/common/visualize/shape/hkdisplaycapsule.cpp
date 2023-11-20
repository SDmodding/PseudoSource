// File Line: 16
// RVA: 0xE723C0
void __fastcall hkDisplayCapsule::hkDisplayCapsule(hkDisplayCapsule *this, hkVector4f *top, hkVector4f *bottom, float radius, int numSides, int numHeightSegments)
{
  __m128 v6; // xmm1

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 8;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayCapsule::`vftable';
  this->m_numSides = numSides;
  this->m_numHeightSegments = numHeightSegments;
  this->m_top = (hkVector4f)top->m_quad;
  v6 = bottom->m_quad;
  this->m_radius = radius;
  this->m_bottom.m_quad = v6;
}

// File Line: 23
// RVA: 0xE72450
void __fastcall hkDisplayCapsule::buildGeometry(hkDisplayCapsule *this)
{
  hkVector4f *v1; // rbx
  _QWORD **v2; // rax
  __int64 v3; // rax
  int v4; // er9
  float v5; // xmm2_4
  int thetaSamples; // ST20_4

  v1 = (hkVector4f *)this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 48i64);
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable';
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
  v4 = v1[9].m_quad.m128_i32[2];
  v5 = v1[9].m_quad.m128_f32[0];
  v1[1].m_quad.m128_u64[0] = v3;
  thetaSamples = v1[9].m_quad.m128_i32[1];
  hkGeometryUtils::createCapsuleGeometry(v1 + 7, v1 + 8, v5, v4);
}

// File Line: 30
// RVA: 0xE72500
void __fastcall hkDisplayCapsule::getWireframeGeometry(hkDisplayCapsule *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  ;
}

