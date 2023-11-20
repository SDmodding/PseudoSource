// File Line: 16
// RVA: 0xBECFE0
void __fastcall hkaiMaterialPainter::hkaiMaterialPainter(hkaiMaterialPainter *this, int material, hkaiVolume *volume)
{
  hkaiVolume *v3; // rdi
  hkaiMaterialPainter *v4; // rbx

  v3 = volume;
  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_material = material;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMaterialPainter::`vftable';
  if ( volume )
  {
    hkReferencedObject::addReference((hkReferencedObject *)&volume->vfptr);
    v4->m_volume.m_pntr = v3;
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
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMaterialPainter::`vftable';
}

// File Line: 23
// RVA: 0xBED040
void __fastcall hkaiMaterialPainter::~hkaiMaterialPainter(hkaiMaterialPainter *this)
{
  hkaiMaterialPainter *v1; // rbx
  hkaiVolume *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMaterialPainter::`vftable';
  v2 = this->m_volume.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_volume.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 27
// RVA: 0xBED080
void __fastcall hkaiMaterialPainter::setVolume(hkaiMaterialPainter *this, hkaiVolume *volume)
{
  hkaiVolume *v2; // rbx
  hkaiMaterialPainter *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = volume;
  v3 = this;
  if ( volume )
    hkReferencedObject::addReference((hkReferencedObject *)&volume->vfptr);
  v4 = (hkReferencedObject *)&v3->m_volume.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_volume.m_pntr = v2;
}

