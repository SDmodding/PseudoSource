// File Line: 20
// RVA: 0xE7E690
void __fastcall hkDisplayPlane::hkDisplayPlane(hkDisplayPlane *this, hkVector4f *normal, hkVector4f *perpToNormal, hkVector4f *center, hkVector4f *extent)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 7;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayPlane::`vftable';
  this->m_normal = (hkVector4f)normal->m_quad;
  this->m_center = (hkVector4f)center->m_quad;
  this->m_perpToNormal = (hkVector4f)perpToNormal->m_quad;
  this->m_extent = (hkVector4f)extent->m_quad;
}

// File Line: 26
// RVA: 0xE7E610
void __fastcall hkDisplayPlane::hkDisplayPlane(hkDisplayPlane *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 7;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->m_extent = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayPlane::`vftable';
  this->m_normal = 0i64;
  this->m_center = 0i64;
  this->m_perpToNormal = 0i64;
}

// File Line: 34
// RVA: 0xE7E9F0
hkVector4f *__fastcall hkDisplayPlane::getNormal(hkDisplayPlane *this)
{
  return &this->m_normal;
}

// File Line: 39
// RVA: 0xE7EA00
hkVector4f *__fastcall hkDisplayPlane::getCenter(hkDisplayPlane *this)
{
  return &this->m_center;
}

// File Line: 44
// RVA: 0xE7EA10
hkVector4f *__fastcall hkDisplayPlane::getPerpToNormal(hkDisplayPlane *this)
{
  return &this->m_perpToNormal;
}

// File Line: 49
// RVA: 0xE7EA20
hkVector4f *__fastcall hkDisplayPlane::getExtents(hkDisplayPlane *this)
{
  return &this->m_extent;
}

// File Line: 56
// RVA: 0xE7E9B0
void __fastcall hkDisplayPlane::setParameters(hkDisplayPlane *this, hkVector4f *normal, hkVector4f *perpToNormal, hkVector4f *center, hkVector4f *extent)
{
  this->m_normal = (hkVector4f)normal->m_quad;
  this->m_center = (hkVector4f)center->m_quad;
  this->m_perpToNormal = (hkVector4f)perpToNormal->m_quad;
  this->m_extent = (hkVector4f)extent->m_quad;
}

// File Line: 64
// RVA: 0xE7E720
void __fastcall hkDisplayPlane::buildGeometry(hkDisplayPlane *this)
{
  hkDisplayPlane *v1; // rbx
  _QWORD **v2; // rax
  __int64 geometryOut; // rax

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  geometryOut = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 48i64);
  if ( geometryOut )
  {
    *(_DWORD *)(geometryOut + 8) = 0x1FFFF;
    *(_QWORD *)geometryOut = &hkGeometry::`vftable';
    *(_DWORD *)(geometryOut + 28) = 2147483648;
    *(_QWORD *)(geometryOut + 16) = 0i64;
    *(_DWORD *)(geometryOut + 24) = 0;
    *(_QWORD *)(geometryOut + 32) = 0i64;
    *(_DWORD *)(geometryOut + 40) = 0;
    *(_DWORD *)(geometryOut + 44) = 2147483648;
  }
  else
  {
    geometryOut = 0i64;
  }
  v1->m_geometry = (hkGeometry *)geometryOut;
  hkGeometryUtils::createPlaneGeometry(
    &v1->m_normal,
    &v1->m_perpToNormal,
    &v1->m_center,
    &v1->m_extent,
    (hkGeometry *)geometryOut);
}

// File Line: 72
// RVA: 0xE7E7C0
void __fastcall hkDisplayPlane::getWireframeGeometry(hkDisplayPlane *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  hkArrayBase<hkVector4f> *v3; // rbx
  int v4; // eax
  hkDisplayPlane *v5; // rdi
  int v6; // eax
  int v7; // er9
  hkGeometry geometryOut; // [rsp+30h] [rbp-30h]
  hkResult result; // [rsp+70h] [rbp+10h]

  v3 = lines;
  v4 = lines->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < 12 )
  {
    v6 = 2 * v4;
    v7 = 12;
    if ( v6 > 12 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, a, lines, v7, 16);
  }
  geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  v3->m_size = 12;
  *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
  geometryOut.m_vertices.m_data = 0i64;
  geometryOut.m_vertices.m_size = 0;
  geometryOut.m_vertices.m_capacityAndFlags = 2147483648;
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_size = 0;
  geometryOut.m_triangles.m_capacityAndFlags = 2147483648;
  hkGeometryUtils::createPlaneGeometry(&v5->m_normal, &v5->m_perpToNormal, &v5->m_center, &v5->m_extent, &geometryOut);
  *v3->m_data = (hkVector4f)geometryOut.m_vertices.m_data->m_quad;
  v3->m_data[1] = geometryOut.m_vertices.m_data[1];
  v3->m_data[2] = geometryOut.m_vertices.m_data[1];
  v3->m_data[3] = geometryOut.m_vertices.m_data[2];
  v3->m_data[4] = geometryOut.m_vertices.m_data[2];
  v3->m_data[5] = geometryOut.m_vertices.m_data[3];
  v3->m_data[6] = geometryOut.m_vertices.m_data[3];
  v3->m_data[7] = (hkVector4f)geometryOut.m_vertices.m_data->m_quad;
  v3->m_data[8] = (hkVector4f)geometryOut.m_vertices.m_data->m_quad;
  v3->m_data[9] = geometryOut.m_vertices.m_data[2];
  v3->m_data[10] = geometryOut.m_vertices.m_data[1];
  v3->m_data[11] = geometryOut.m_vertices.m_data[3];
  geometryOut.m_triangles.m_size = 0;
  if ( geometryOut.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometryOut.m_triangles.m_data,
      16 * geometryOut.m_triangles.m_capacityAndFlags);
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_capacityAndFlags = 2147483648;
  geometryOut.m_vertices.m_size = 0;
  if ( geometryOut.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometryOut.m_vertices.m_data,
      16 * geometryOut.m_vertices.m_capacityAndFlags);
}

