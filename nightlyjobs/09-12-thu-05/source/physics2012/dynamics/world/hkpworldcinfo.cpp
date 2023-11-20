// File Line: 22
// RVA: 0xD54DC0
void __fastcall hkpWorldCinfo::hkpWorldCinfo(hkpWorldCinfo *this)
{
  hkpWorldCinfo *v1; // rbx
  hkpCollisionFilter *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldCinfo::`vftable';
  this->m_collisionFilter.m_pntr = 0i64;
  this->m_convexListFilter.m_pntr = 0i64;
  this->m_memoryWatchDog.m_pntr = 0i64;
  v1 = this;
  this->m_gravity = (hkVector4f)_xmm;
  this->m_enableSimulationIslands.m_bool = 1;
  this->m_broadPhaseQuerySize = 1024;
  this->m_mtPostponeAndSortBroadPhaseBorderCallbacks.m_bool = 0;
  this->m_broadPhaseWorldAabb.m_min = (hkVector4f)_xmm;
  this->m_broadPhaseWorldAabb.m_max = (hkVector4f)_xmm;
  v2 = this->m_collisionFilter.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_collisionFilter.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_convexListFilter.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_convexListFilter.m_pntr = 0i64;
  v1->m_broadPhaseNumMarkers = 0;
  v1->m_sizeOfToiEventQueue = 250;
  v1->m_solverTau = 0.60000002;
  v1->m_solverDamp = 1.0;
  v1->m_contactRestingVelocity = 1.0;
  v1->m_solverIterations = 4;
  v1->m_solverMicrosteps = 1;
  v1->m_maxConstraintViolation = 1.8446726e19;
  v1->m_forceCoherentConstraintOrderingInSolver.m_bool = 0;
  v1->m_snapCollisionToConvexEdgeThreshold = 0.52399999;
  v1->m_snapCollisionToConcaveEdgeThreshold = 0.69800001;
  *(_WORD *)&v1->m_enableToiWeldRejection.m_bool = 0;
  v1->m_collisionTolerance = 0.1;
  *(_WORD *)&v1->m_broadPhaseType.m_storage = 0;
  v1->m_toiCollisionResponseRotateNormal = 0.2;
  v1->m_useCompoundSpuElf.m_bool = 0;
  v1->m_processToisMultithreaded.m_bool = 1;
  v1->m_maxSectorsPerMidphaseCollideTask = 2;
  v1->m_maxSectorsPerNarrowphaseCollideTask = 4;
  v1->m_maxEntriesPerToiMidphaseCollideTask = 4;
  *(_QWORD *)&v1->m_maxEntriesPerToiNarrowphaseCollideTask = 12i64;
  v1->m_numToisTillAllowedPenetrationSimplifiedToi = 3.0;
  v1->m_numToisTillAllowedPenetrationToi = 3.0;
  v1->m_numToisTillAllowedPenetrationToiHigher = 4.0;
  v1->m_numToisTillAllowedPenetrationToiForced = 20.0;
  v1->m_deactivationReferenceDistance = 0.02;
  v1->m_expectedMaxLinearVelocity = 200.0;
  v1->m_expectedMinPsiDeltaTime = 0.033333335;
  v1->m_iterativeLinearCastEarlyOutDistance = 0.0099999998;
  v1->m_iterativeLinearCastMaxIterations = 20;
  *(_WORD *)&v1->m_enableDeactivation.m_bool = 513;
  *(_DWORD *)&v1->m_deactivationNumInactiveFramesSelectFlag0 = 0x1000000;
  v1->m_minDesiredIslandSize = 64;
  *(_WORD *)&v1->m_contactPointGeneration.m_storage = 2;
  v1->m_frameMarkerPsiSnap = 0.000099999997;
  v4 = (hkReferencedObject *)&v1->m_memoryWatchDog.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_memoryWatchDog.m_pntr = 0i64;
  *(_WORD *)&v1->m_processActionsInSingleThread.m_bool = 1;
  v1->m_fireCollisionCallbacks.m_bool = 0;
}

// File Line: 87
// RVA: 0xD55110
void __usercall hkpWorldCinfo::setBroadPhaseWorldSize(hkpWorldCinfo *this@<rcx>, __int128 sideLength@<xmm1>, __m128 a3@<xmm0>)
{
  __m128 v3; // xmm2

  v3 = (__m128)sideLength;
  v3.m128_f32[0] = *(float *)&sideLength * -0.5;
  a3.m128_f32[0] = *(float *)&sideLength * 0.5;
  this->m_broadPhaseWorldAabb.m_max.m_quad = _mm_shuffle_ps(a3, a3, 0);
  this->m_broadPhaseWorldAabb.m_min.m_quad = _mm_shuffle_ps(v3, v3, 0);
}

// File Line: 93
// RVA: 0xD54FC0
void __fastcall hkpWorldCinfo::setupSolverInfo(hkpWorldCinfo *this, hkpWorldCinfo::SolverType st)
{
  switch ( st )
  {
    case 1:
      this->m_solverTau = 0.30000001;
      this->m_solverDamp = 0.89999998;
      this->m_solverIterations = 2;
      return;
    case 2:
      this->m_solverTau = 0.60000002;
      this->m_solverDamp = 1.0;
      this->m_solverIterations = 2;
      return;
    case 3:
      this->m_solverIterations = 2;
      goto LABEL_11;
    case 4:
      this->m_solverTau = 0.30000001;
      this->m_solverDamp = 0.89999998;
      this->m_solverIterations = 4;
      return;
    case 5:
      this->m_solverTau = 0.60000002;
      this->m_solverDamp = 1.0;
      this->m_solverIterations = 4;
      return;
    case 6:
      this->m_solverIterations = 4;
      goto LABEL_11;
    case 7:
      this->m_solverTau = 0.30000001;
      this->m_solverDamp = 0.89999998;
      this->m_solverIterations = 8;
      break;
    case 8:
      this->m_solverTau = 0.60000002;
      this->m_solverDamp = 1.0;
      this->m_solverIterations = 8;
      break;
    case 9:
      this->m_solverIterations = 8;
LABEL_11:
      this->m_solverTau = 0.89999998;
      this->m_solverDamp = 1.1;
      break;
    default:
      return;
  }
}

// File Line: 148
// RVA: 0xD55140
void __fastcall hkpWorldCinfo::hkpWorldCinfo(hkpWorldCinfo *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldCinfo::`vftable';
  if ( flag.m_finishing )
  {
    if ( this->m_contactRestingVelocity == 0.0 )
      this->m_contactRestingVelocity = 1.0;
    if ( this->m_maxEntriesPerToiMidphaseCollideTask == -1 )
      this->m_maxEntriesPerToiMidphaseCollideTask = 4;
    if ( this->m_maxEntriesPerToiNarrowphaseCollideTask == -1 )
      this->m_maxEntriesPerToiNarrowphaseCollideTask = 12;
  }
}

