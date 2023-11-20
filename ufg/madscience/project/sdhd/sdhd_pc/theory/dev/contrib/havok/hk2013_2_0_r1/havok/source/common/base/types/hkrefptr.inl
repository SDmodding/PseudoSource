// File Line: 61
// RVA: 0x39EAE0
void __fastcall hkRefPtr<hkpCollisionFilter>::~hkRefPtr<hkpCollisionFilter>(hkRefPtr<hkpConvexListFilter> *this)
{
  hkRefPtr<hkpConvexListFilter> *v1; // rbx
  hkpConvexListFilter *v2; // rcx

  v1 = this;
  v2 = this->m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_pntr = 0i64;
}

