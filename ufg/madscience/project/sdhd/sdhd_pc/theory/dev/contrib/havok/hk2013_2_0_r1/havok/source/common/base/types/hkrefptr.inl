// File Line: 61
// RVA: 0x39EAE0
void __fastcall hkRefPtr<hkpCollisionFilter>::~hkRefPtr<hkpCollisionFilter>(hkRefPtr<hkpConvexListFilter> *this)
{
  hkpConvexListFilter *m_pntr; // rcx

  m_pntr = this->m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_pntr = 0i64;
}

