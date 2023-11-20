// File Line: 13
// RVA: 0xE76D20
void __fastcall hkDisplayGeometry::~hkDisplayGeometry(hkDisplayGeometry *this)
{
  hkDisplayGeometry *v1; // rbx
  hkGeometry *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  v2 = this->m_geometry;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
    v1->m_geometry = 0i64;
  }
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

