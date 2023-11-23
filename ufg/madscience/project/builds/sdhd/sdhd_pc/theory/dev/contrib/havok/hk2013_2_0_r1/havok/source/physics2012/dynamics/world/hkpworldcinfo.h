// File Line: 586
// RVA: 0x9DDB0
void __fastcall hkpWorldCinfo::~hkpWorldCinfo(hkpWorldCinfo *this)
{
  hkWorldMemoryAvailableWatchDog *m_pntr; // rcx
  hkpConvexListFilter *v3; // rcx
  hkpCollisionFilter *v4; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldCinfo::`vftable;
  m_pntr = this->m_memoryWatchDog.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_memoryWatchDog.m_pntr = 0i64;
  v3 = this->m_convexListFilter.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_convexListFilter.m_pntr = 0i64;
  v4 = this->m_collisionFilter.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_collisionFilter.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

