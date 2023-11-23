// File Line: 16
// RVA: 0xBECFE0
void __fastcall hkaiMaterialPainter::hkaiMaterialPainter(hkaiMaterialPainter *this, int material, hkaiVolume *volume)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_material = material;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMaterialPainter::`vftable;
  if ( volume )
  {
    hkReferencedObject::addReference(volume);
    this->m_volume.m_pntr = volume;
  }
  else
  {
    this->m_volume.m_pntr = 0i64;
  }
}

// File Line: 21
// RVA: 0xBECFC0
void __fastcall hkaiMaterialPainter::hkaiMaterialPainter(hkaiMaterialPainter *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMaterialPainter::`vftable;
}

// File Line: 23
// RVA: 0xBED040
void __fastcall hkaiMaterialPainter::~hkaiMaterialPainter(hkaiMaterialPainter *this)
{
  hkaiVolume *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiMaterialPainter::`vftable;
  m_pntr = this->m_volume.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_volume.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 27
// RVA: 0xBED080
void __fastcall hkaiMaterialPainter::setVolume(hkaiMaterialPainter *this, hkaiVolume *volume)
{
  hkaiVolume *m_pntr; // rcx

  if ( volume )
    hkReferencedObject::addReference(volume);
  m_pntr = this->m_volume.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_volume.m_pntr = volume;
}

