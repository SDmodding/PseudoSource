// File Line: 586
// RVA: 0x9DDB0
void __fastcall hkpWorldCinfo::~hkpWorldCinfo(hkpWorldCinfo *this)
{
  hkpWorldCinfo *v1; // rbx
  hkWorldMemoryAvailableWatchDog *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldCinfo::`vftable;
  v2 = this->m_memoryWatchDog.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_memoryWatchDog.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_convexListFilter.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_convexListFilter.m_pntr = 0i64;
  v4 = (hkReferencedObject *)&v1->m_collisionFilter.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_collisionFilter.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

