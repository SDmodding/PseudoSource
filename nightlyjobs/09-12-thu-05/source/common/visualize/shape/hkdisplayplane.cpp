// File Line: 20
// RVA: 0xE7E690
void __fastcall hkDisplayPlane::hkDisplayPlane(
        hkDisplayPlane *this,
        hkVector4f *normal,
        hkVector4f *perpToNormal,
        hkVector4f *center,
        hkVector4f *extent)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_PLANE;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayPlane::`vftable;
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
  this->m_type = HK_DISPLAY_PLANE;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->m_extent = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayPlane::`vftable;
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
void __fastcall hkDisplayPlane::setParameters(
        hkDisplayPlane *this,
        hkVector4f *normal,
        hkVector4f *perpToNormal,
        hkVector4f *center,
        hkVector4f *extent)
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
  _QWORD **Value; // rax
  __int64 geometryOut; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  geometryOut = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( geometryOut )
  {
    *(_DWORD *)(geometryOut + 8) = 0x1FFFF;
    *(_QWORD *)geometryOut = &hkGeometry::`vftable;
    *(_DWORD *)(geometryOut + 28) = 0x80000000;
    *(_QWORD *)(geometryOut + 16) = 0i64;
    *(_DWORD *)(geometryOut + 24) = 0;
    *(_QWORD *)(geometryOut + 32) = 0i64;
    *(_DWORD *)(geometryOut + 40) = 0;
    *(_DWORD *)(geometryOut + 44) = 0x80000000;
  }
  else
  {
    geometryOut = 0i64;
  }
  this->m_geometry = (hkGeometry *)geometryOut;
  hkGeometryUtils::createPlaneGeometry(
    &this->m_normal,
    &this->m_perpToNormal,
    &this->m_center,
    &this->m_extent,
    (hkGeometry *)geometryOut);
}

// File Line: 72
// RVA: 0xE7E7C0
void __fastcall hkDisplayPlane::getWireframeGeometry(
        hkDisplayPlane *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  int v5; // r9d
  hkGeometry geometryOut; // [rsp+30h] [rbp-30h] BYREF
  hkResult result; // [rsp+70h] [rbp+10h] BYREF

  if ( (lines->m_capacityAndFlags & 0x3FFFFFFFu) < 0xC )
  {
    v5 = 12;
    if ( 2 * (lines->m_capacityAndFlags & 0x3FFFFFFF) > 12 )
      v5 = 2 * (lines->m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, a, (const void **)&lines->m_data, v5, 16);
  }
  geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  lines->m_size = 12;
  *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
  geometryOut.m_vertices.m_data = 0i64;
  geometryOut.m_vertices.m_size = 0;
  geometryOut.m_vertices.m_capacityAndFlags = 0x80000000;
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_size = 0;
  geometryOut.m_triangles.m_capacityAndFlags = 0x80000000;
  hkGeometryUtils::createPlaneGeometry(
    &this->m_normal,
    &this->m_perpToNormal,
    &this->m_center,
    &this->m_extent,
    &geometryOut);
  *lines->m_data = (hkVector4f)geometryOut.m_vertices.m_data->m_quad;
  lines->m_data[1] = geometryOut.m_vertices.m_data[1];
  lines->m_data[2] = geometryOut.m_vertices.m_data[1];
  lines->m_data[3] = geometryOut.m_vertices.m_data[2];
  lines->m_data[4] = geometryOut.m_vertices.m_data[2];
  lines->m_data[5] = geometryOut.m_vertices.m_data[3];
  lines->m_data[6] = geometryOut.m_vertices.m_data[3];
  lines->m_data[7] = (hkVector4f)geometryOut.m_vertices.m_data->m_quad;
  lines->m_data[8] = (hkVector4f)geometryOut.m_vertices.m_data->m_quad;
  lines->m_data[9] = geometryOut.m_vertices.m_data[2];
  lines->m_data[10] = geometryOut.m_vertices.m_data[1];
  lines->m_data[11] = geometryOut.m_vertices.m_data[3];
  geometryOut.m_triangles.m_size = 0;
  if ( geometryOut.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      geometryOut.m_triangles.m_data,
      16 * geometryOut.m_triangles.m_capacityAndFlags);
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_capacityAndFlags = 0x80000000;
  geometryOut.m_vertices.m_size = 0;
  if ( geometryOut.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      geometryOut.m_vertices.m_data,
      16 * geometryOut.m_vertices.m_capacityAndFlags);
}

