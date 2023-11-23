// File Line: 13
// RVA: 0xE76D20
void __fastcall hkDisplayGeometry::~hkDisplayGeometry(hkDisplayGeometry *this)
{
  hkGeometry *m_geometry; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  m_geometry = this->m_geometry;
  if ( m_geometry )
  {
    m_geometry->vfptr->__vecDelDtor(m_geometry, 1u);
    this->m_geometry = 0i64;
  }
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

