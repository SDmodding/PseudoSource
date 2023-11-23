// File Line: 22
// RVA: 0xD54DC0
void __fastcall hkpWorldCinfo::hkpWorldCinfo(hkpWorldCinfo *this)
{
  hkpCollisionFilter *m_pntr; // rcx
  hkpConvexListFilter *v3; // rcx
  hkWorldMemoryAvailableWatchDog *v4; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldCinfo::`vftable;
  this->m_collisionFilter.m_pntr = 0i64;
  this->m_convexListFilter.m_pntr = 0i64;
  this->m_memoryWatchDog.m_pntr = 0i64;
  this->m_gravity = (hkVector4f)_xmm;
  this->m_enableSimulationIslands.m_bool = 1;
  this->m_broadPhaseQuerySize = 1024;
  this->m_mtPostponeAndSortBroadPhaseBorderCallbacks.m_bool = 0;
  this->m_broadPhaseWorldAabb.m_min = (hkVector4f)_xmm;
  this->m_broadPhaseWorldAabb.m_max = (hkVector4f)_xmm;
  m_pntr = this->m_collisionFilter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_collisionFilter.m_pntr = 0i64;
  v3 = this->m_convexListFilter.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_convexListFilter.m_pntr = 0i64;
  this->m_broadPhaseNumMarkers = 0;
  this->m_sizeOfToiEventQueue = 250;
  this->m_solverTau = 0.60000002;
  this->m_solverDamp = 1.0;
  this->m_contactRestingVelocity = 1.0;
  this->m_solverIterations = 4;
  this->m_solverMicrosteps = 1;
  this->m_maxConstraintViolation = 1.8446726e19;
  this->m_forceCoherentConstraintOrderingInSolver.m_bool = 0;
  this->m_snapCollisionToConvexEdgeThreshold = 0.52399999;
  this->m_snapCollisionToConcaveEdgeThreshold = 0.69800001;
  *(_WORD *)&this->m_enableToiWeldRejection.m_bool = 0;
  this->m_collisionTolerance = 0.1;
  *(_WORD *)&this->m_broadPhaseType.m_storage = 0;
  this->m_toiCollisionResponseRotateNormal = 0.2;
  this->m_useCompoundSpuElf.m_bool = 0;
  this->m_processToisMultithreaded.m_bool = 1;
  this->m_maxSectorsPerMidphaseCollideTask = 2;
  this->m_maxSectorsPerNarrowphaseCollideTask = 4;
  this->m_maxEntriesPerToiMidphaseCollideTask = 4;
  *(_QWORD *)&this->m_maxEntriesPerToiNarrowphaseCollideTask = 12i64;
  this->m_numToisTillAllowedPenetrationSimplifiedToi = 3.0;
  this->m_numToisTillAllowedPenetrationToi = 3.0;
  this->m_numToisTillAllowedPenetrationToiHigher = 4.0;
  this->m_numToisTillAllowedPenetrationToiForced = 20.0;
  this->m_deactivationReferenceDistance = 0.02;
  this->m_expectedMaxLinearVelocity = 200.0;
  this->m_expectedMinPsiDeltaTime = 0.033333335;
  this->m_iterativeLinearCastEarlyOutDistance = 0.0099999998;
  this->m_iterativeLinearCastMaxIterations = 20;
  *(_WORD *)&this->m_enableDeactivation.m_bool = 513;
  *(_DWORD *)&this->m_deactivationNumInactiveFramesSelectFlag0 = 0x1000000;
  this->m_minDesiredIslandSize = 64;
  *(_WORD *)&this->m_contactPointGeneration.m_storage = 2;
  this->m_frameMarkerPsiSnap = 0.000099999997;
  v4 = this->m_memoryWatchDog.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_memoryWatchDog.m_pntr = 0i64;
  *(_WORD *)&this->m_processActionsInSingleThread.m_bool = 1;
  this->m_fireCollisionCallbacks.m_bool = 0;
}

// File Line: 87
// RVA: 0xD55110
// local variable allocation has failed, the output may be wrong!
void __fastcall hkpWorldCinfo::setBroadPhaseWorldSize(hkpWorldCinfo *this, double sideLength)
{
  __m128 v2; // xmm0
  __m128 v3; // xmm2

  v3 = *(__m128 *)&sideLength;
  v3.m128_f32[0] = *(float *)&sideLength * -0.5;
  v2.m128_f32[0] = *(float *)&sideLength * 0.5;
  this->m_broadPhaseWorldAabb.m_max.m_quad = _mm_shuffle_ps(v2, v2, 0);
  this->m_broadPhaseWorldAabb.m_min.m_quad = _mm_shuffle_ps(v3, v3, 0);
}

// File Line: 93
// RVA: 0xD54FC0
void __fastcall hkpWorldCinfo::setupSolverInfo(hkpWorldCinfo *this, hkpWorldCinfo::SolverType st)
{
  switch ( st )
  {
    case SOLVER_TYPE_2ITERS_SOFT:
      this->m_solverTau = 0.30000001;
      this->m_solverDamp = 0.89999998;
      this->m_solverIterations = 2;
      return;
    case SOLVER_TYPE_2ITERS_MEDIUM:
      this->m_solverTau = 0.60000002;
      this->m_solverDamp = 1.0;
      this->m_solverIterations = 2;
      return;
    case SOLVER_TYPE_2ITERS_HARD:
      this->m_solverIterations = 2;
      goto LABEL_11;
    case SOLVER_TYPE_4ITERS_SOFT:
      this->m_solverTau = 0.30000001;
      this->m_solverDamp = 0.89999998;
      this->m_solverIterations = 4;
      return;
    case SOLVER_TYPE_4ITERS_MEDIUM:
      this->m_solverTau = 0.60000002;
      this->m_solverDamp = 1.0;
      this->m_solverIterations = 4;
      return;
    case SOLVER_TYPE_4ITERS_HARD:
      this->m_solverIterations = 4;
      goto LABEL_11;
    case SOLVER_TYPE_8ITERS_SOFT:
      this->m_solverTau = 0.30000001;
      this->m_solverDamp = 0.89999998;
      this->m_solverIterations = 8;
      return;
    case SOLVER_TYPE_8ITERS_MEDIUM:
      this->m_solverTau = 0.60000002;
      this->m_solverDamp = 1.0;
      this->m_solverIterations = 8;
      return;
    case SOLVER_TYPE_8ITERS_HARD:
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
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldCinfo::`vftable;
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

