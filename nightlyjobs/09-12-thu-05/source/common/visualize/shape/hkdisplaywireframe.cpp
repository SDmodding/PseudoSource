// File Line: 13
// RVA: 0xE72290
void __fastcall hkDisplayWireframe::hkDisplayWireframe(hkDisplayWireframe *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = 12;
  this->m_geometry = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayWireframe::`vftable;
  this->m_lines.m_data = 0i64;
  this->m_lines.m_size = 0;
  this->m_lines.m_capacityAndFlags = 2147483648;
  this->m_geometry = 0i64;
}

// File Line: 18
// RVA: 0xE72300
void __fastcall hkDisplayWireframe::getWireframeGeometry(hkDisplayWireframe *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  hkArrayBase<hkVector4f>::_append(lines, a, this->m_lines.m_data, this->m_lines.m_size);
}

