// File Line: 40
// RVA: 0x262960
void __fastcall UFG::NavModulePathing::NavModulePathing(UFG::NavModulePathing *this, UFG::NavComponent *parent)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  this->vfptr = (UFG::NavModulePathingVtbl *)&UFG::NavModulePathing::`vftable;
  *(_QWORD *)&this->m_bGoalRefreshed = 0i64;
  this->m_navComponent = parent;
  this->m_wpPreviousWaypoint.m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y = y;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.z = z;
  this->m_wpPreviousWaypoint.m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_wpPreviousWaypoint.m_navPosition.m_bValid = 0;
  *(_QWORD *)&this->m_wpPreviousWaypoint.m_navPosition.m_packedKey = -1i64;
  this->m_wpPreviousWaypoint.m_navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                                        _mm_unpacklo_ps(
                                                                          (__m128)LODWORD(UFG::qVector3::msZero.x),
                                                                          (__m128)LODWORD(UFG::qVector3::msZero.z)),
                                                                        _mm_unpacklo_ps(
                                                                          (__m128)LODWORD(UFG::qVector3::msZero.y),
                                                                          (__m128)(unsigned int)FLOAT_1_0));
  this->m_wpPreviousWaypoint.m_pNavObject = 0i64;
  *(_WORD *)&this->m_wpPreviousWaypoint.m_stopPoint = 0;
  this->m_wpPreviousWaypoint.m_canSmooth = 1;
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&this->m_PathQueryInput);
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  *(_QWORD *)&this->m_PathQueryOutput.m_id = 0i64;
  this->m_PathQueryOutput.m_status = Status_Undefined;
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathOutput::`vftable;
  this->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
  *(_QWORD *)&this->m_Deferrer[0].mLastPosition.x = 0i64;
  *(_QWORD *)&this->m_Deferrer[0].mLastPosition.z = 0i64;
  *(_QWORD *)&this->m_Deferrer[0].mDistanceTolerance = 0i64;
  this->m_Deferrer[0].mResult = 0;
  *(_QWORD *)&this->m_Deferrer[1].mLastPosition.x = 0i64;
  *(_QWORD *)&this->m_Deferrer[1].mLastPosition.z = 0i64;
  *(_QWORD *)&this->m_Deferrer[1].mDistanceTolerance = 0i64;
  this->m_Deferrer[1].mResult = 0;
  this->m_npInjectedPathSource.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  this->m_npInjectedPathSource.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npInjectedPathSource.m_vPosition.y = v5;
  this->m_npInjectedPathSource.m_vPosition.z = v6;
  this->m_npInjectedPathSource.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npInjectedPathSource.m_bValid = 0;
  this->m_npInjectedPathSource.m_hkvMeshPosition = (hkVector4f)hkvZero_5.m_quad;
  *(_QWORD *)&this->m_npInjectedPathSource.m_packedKey = -1i64;
  this->m_npInjectedPathDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  this->m_npInjectedPathDestination.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npInjectedPathDestination.m_vPosition.y = v7;
  this->m_npInjectedPathDestination.m_vPosition.z = v8;
  this->m_npInjectedPathDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npInjectedPathDestination.m_bValid = 0;
  this->m_npInjectedPathDestination.m_hkvMeshPosition = (hkVector4f)hkvZero_5.m_quad;
  *(_QWORD *)&this->m_npInjectedPathDestination.m_packedKey = -1i64;
  this->m_pPath.m_pNavPath = 0i64;
  this->m_pInjectedPath.m_pNavPath = 0i64;
  this->m_aGoalPoints.p = 0i64;
  *(_QWORD *)&this->m_aGoalPoints.size = 0i64;
  *(_WORD *)&this->m_bInvalidPath = 0;
  v9 = UFG::qRandom(0.0, (unsigned int *)&UFG::qDefaultSeed);
  *(_QWORD *)&this->m_Deferrer[0].mLastPosition.x = 0i64;
  this->m_Deferrer[0].mLastPosition.z = 0.0;
  this->m_Deferrer[0].mTimeSinceLastCheck = v9;
  *(_QWORD *)&this->m_Deferrer[0].mDistanceTolerance = 0i64;
  this->m_Deferrer[0].mResult = 0;
  v10 = UFG::qRandom(0.0, (unsigned int *)&UFG::qDefaultSeed);
  *(_QWORD *)&this->m_Deferrer[1].mLastPosition.x = 0i64;
  this->m_Deferrer[1].mLastPosition.z = 0.0;
  this->m_Deferrer[1].mTimeSinceLastCheck = v10;
  *(_QWORD *)&this->m_Deferrer[1].mDistanceTolerance = 0i64;
  this->m_Deferrer[1].mResult = 0;
}

// File Line: 58
// RVA: 0x262EB0
void __fastcall UFG::NavModulePathing::~NavModulePathing(UFG::NavModulePathing *this)
{
  UFG::NavModulePathing::GoalPoint *p; // rcx
  UFG::NavPath *m_pNavPath; // rcx
  bool v4; // zf
  UFG::NavPath *v5; // rcx
  UFG::NavPath *v6; // rcx

  this->vfptr = (UFG::NavModulePathingVtbl *)&UFG::NavModulePathing::`vftable;
  UFG::NavModulePathing::CancelPendingQuery(this);
  UFG::NavModulePathing::ClearPath(this);
  if ( this->m_bForceGoalAdvance )
  {
    UFG::NavModulePathing::SetupRepathing(this);
    this->m_bForceGoalAdvance = 0;
    if ( !this->m_aGoalPoints.size )
      this->m_bAtDestination = 1;
  }
  p = this->m_aGoalPoints.p;
  if ( p )
    operator delete[](p);
  this->m_aGoalPoints.p = 0i64;
  *(_QWORD *)&this->m_aGoalPoints.size = 0i64;
  m_pNavPath = this->m_pInjectedPath.m_pNavPath;
  if ( m_pNavPath )
  {
    v4 = m_pNavPath->m_uRefCount-- == 1;
    if ( v4 )
      m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
  }
  v5 = this->m_pPath.m_pNavPath;
  if ( v5 )
  {
    v4 = v5->m_uRefCount-- == 1;
    if ( v4 )
      v5->vfptr->__vecDelDtor(v5, 1u);
  }
  v6 = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( v6 )
  {
    v4 = v6->m_uRefCount-- == 1;
    if ( v4 )
      v6->vfptr->__vecDelDtor(v6, 1u);
  }
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  this->m_PathQueryInput.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
}

// File Line: 64
// RVA: 0x265F10
void __fastcall UFG::NavModulePathing::Reset(UFG::NavModulePathing *this)
{
  bool v2; // zf

  UFG::NavModulePathing::CancelPendingQuery(this);
  UFG::NavModulePathing::ClearPath(this);
  if ( this->m_bForceGoalAdvance )
  {
    UFG::NavModulePathing::SetupRepathing(this);
    v2 = this->m_aGoalPoints.size == 0;
    this->m_bForceGoalAdvance = 0;
    if ( v2 )
      this->m_bAtDestination = 1;
  }
}

// File Line: 86
// RVA: 0x263C30
void __fastcall UFG::NavModulePathing::CancelPendingQuery(UFG::NavModulePathing *this)
{
  unsigned int size; // edx
  int v2; // eax
  UFG::NavModulePathing::GoalPoint *i; // rdi
  UFG::FindPathDeferredQuery *p_m_PathQueryInput; // rbx
  UFG::DaemonManager *v5; // rax

  size = this->m_aGoalPoints.size;
  v2 = 0;
  if ( size )
  {
    for ( i = this->m_aGoalPoints.p; (i->m_status & 0xA) == 0; ++i )
    {
      if ( ++v2 >= size )
        return;
    }
    p_m_PathQueryInput = &this->m_PathQueryInput;
    v5 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::CancelQuery(v5, p_m_PathQueryInput);
    i->m_status = STATUS_WAITING_FOR_SCHEDULING;
  }
}

// File Line: 124
// RVA: 0x2634B0
void __fastcall UFG::NavModulePathing::AddGoalPointUid(
        UFG::NavModulePathing *this,
        UFG::HavokNavPosition *npPosition,
        unsigned int goalMode,
        float speed,
        int userId,
        int maxSearchIterations,
        float tolerance)
{
  bool v8; // r12
  unsigned int size; // eax
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::NavModulePathing::GoalPoint *v15; // rdx
  UFG::NavPath *m_pNavPath; // rcx
  bool v17; // zf
  UFG::NavModulePathing::GoalPoint *p; // rcx
  bool m_bValid; // bp
  unsigned int m_packedKey; // r14d
  unsigned int m_aiMeshUid; // r15d
  hkVector4f v22; // xmm6
  float v23; // xmm8_4
  float v24; // xmm10_4
  float v25; // xmm9_4
  UFG::qArray<UFG::NavModulePathing::GoalPoint,0> *p_m_aGoalPoints; // rsi
  __int64 v27; // r13
  unsigned int capacity; // edx
  unsigned int v29; // edi
  unsigned int v30; // edx
  UFG::NavModulePathing *v31; // rcx
  bool v32; // [rsp+B0h] [rbp+18h]

  v8 = goalMode == 1;
  this->m_bGoalRefreshed = 1;
  if ( goalMode <= 1 )
  {
    size = this->m_aGoalPoints.size;
    if ( size )
    {
      x = npPosition->m_vPosition.x;
      y = npPosition->m_vPosition.y;
      z = npPosition->m_vPosition.z;
      v15 = &this->m_aGoalPoints.p[size - 1];
      if ( (float)((float)((float)((float)(x - v15->m_npPosition.m_vPosition.x)
                                 * (float)(x - v15->m_npPosition.m_vPosition.x))
                         + (float)((float)(y - v15->m_npPosition.m_vPosition.y)
                                 * (float)(y - v15->m_npPosition.m_vPosition.y)))
                 + (float)((float)(z - v15->m_npPosition.m_vPosition.z) * (float)(z - v15->m_npPosition.m_vPosition.z))) < UFG::NavModulePathing::ms_fDestinationTolerance )
      {
        v15->m_speed = speed;
        v15->m_maxSearchIterations = maxSearchIterations;
        v15->m_tolerance = tolerance;
        return;
      }
      if ( goalMode == 1 )
      {
        m_pNavPath = this->m_pPath.m_pNavPath;
        if ( m_pNavPath )
        {
          v17 = m_pNavPath->m_uRefCount-- == 1;
          if ( v17 )
            m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
          this->m_pPath.m_pNavPath = 0i64;
        }
        p = this->m_aGoalPoints.p;
        if ( p )
          operator delete[](p);
        this->m_aGoalPoints.p = 0i64;
        *(_QWORD *)&this->m_aGoalPoints.size = 0i64;
      }
    }
    this->m_bAtDestination = 0;
  }
  m_bValid = npPosition->m_bValid;
  m_packedKey = -1;
  m_aiMeshUid = -1;
  v22.m_quad = hkvZero_5.m_quad;
  v23 = npPosition->m_vPosition.x;
  v24 = npPosition->m_vPosition.z;
  v25 = npPosition->m_vPosition.y;
  if ( m_bValid )
  {
    v22.m_quad = (__m128)npPosition->m_hkvMeshPosition;
    m_packedKey = npPosition->m_packedKey;
    m_aiMeshUid = npPosition->m_aiMeshUid;
  }
  else
  {
    m_bValid = 0;
  }
  v17 = goalMode == 2;
  p_m_aGoalPoints = &this->m_aGoalPoints;
  v27 = this->m_aGoalPoints.size;
  capacity = this->m_aGoalPoints.capacity;
  v32 = v17;
  v29 = v27 + 1;
  if ( (int)v27 + 1 > capacity )
  {
    if ( capacity )
      v30 = 2 * capacity;
    else
      v30 = 1;
    for ( ; v30 < v29; v30 *= 2 )
      ;
    if ( v30 - v29 > 0x10000 )
      v30 = v27 + 65537;
    UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::Reallocate(&this->m_aGoalPoints, v30, "qArray.Add");
  }
  p_m_aGoalPoints->size = v29;
  v31 = (UFG::NavModulePathing *)&this->m_aGoalPoints.p[v27];
  LODWORD(v31->m_elapsedTimeTowardGoal) = userId;
  *((float *)&v31->vfptr + 1) = speed;
  LODWORD(v31->m_navComponent) = maxSearchIterations;
  *(float *)&v31->m_bGoalRefreshed = tolerance;
  LODWORD(v31->vfptr) = 1;
  HIDWORD(v31->m_navComponent) = -1;
  *((_BYTE *)&v31->m_navComponent + 9) = v8;
  *((_BYTE *)&v31->m_navComponent + 8) = v32;
  *((_BYTE *)&v31->m_navComponent + 10) = 0;
  v31->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x = v23;
  v31->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y = v25;
  v31->m_wpPreviousWaypoint.m_navPosition.m_vPosition.z = v24;
  if ( m_bValid )
  {
    v31->m_wpPreviousWaypoint.m_navPosition.m_bValid = m_bValid;
    v31->m_wpPreviousWaypoint.m_navPosition.m_hkvMeshPosition = (hkVector4f)v22.m_quad;
    v31->m_wpPreviousWaypoint.m_navPosition.m_packedKey = m_packedKey;
    v31->m_wpPreviousWaypoint.m_navPosition.m_aiMeshUid = m_aiMeshUid;
  }
  else
  {
    v31->m_wpPreviousWaypoint.m_navPosition.m_bValid = 0;
  }
  if ( p_m_aGoalPoints->size > 0x32 && (this->m_aGoalPoints.p->m_status & 0xA) == 0 )
    UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(&this->m_aGoalPoints, 0);
}

// File Line: 187
// RVA: 0x2641A0
bool __fastcall UFG::NavModulePathing::GetCurrGoalPointInfo(
        UFG::NavModulePathing *this,
        UFG::qVector3 *position,
        UFG::qVector3 *direction,
        float *elapsedTime,
        int *uid)
{
  bool result; // al
  UFG::NavModulePathing::GoalPoint *p; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  __int128 x_low; // xmm2
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  __m128 v13; // xmm1
  float v14; // xmm1_4

  if ( !this->m_aGoalPoints.size )
    return 0;
  *elapsedTime = this->m_elapsedTimeTowardGoal;
  p = this->m_aGoalPoints.p;
  y = p->m_npPosition.m_vPosition.y;
  z = p->m_npPosition.m_vPosition.z;
  position->x = p->m_npPosition.m_vPosition.x;
  position->y = y;
  position->z = z;
  *uid = this->m_aGoalPoints.p->m_userId;
  if ( this->m_aGoalPoints.size <= 1 )
  {
    x_low = LODWORD(position->x);
    *(float *)&x_low = *(float *)&x_low - this->m_navComponent->m_navPosition.m_vPosition.x;
    v10 = position->y - this->m_navComponent->m_navPosition.m_vPosition.y;
    v11 = position->z - this->m_navComponent->m_navPosition.m_vPosition.z;
  }
  else
  {
    x_low = LODWORD(this->m_aGoalPoints.p[1].m_npPosition.m_vPosition.x);
    *(float *)&x_low = *(float *)&x_low - position->x;
    v10 = this->m_aGoalPoints.p[1].m_npPosition.m_vPosition.y - position->y;
    v11 = this->m_aGoalPoints.p[1].m_npPosition.m_vPosition.z - position->z;
  }
  v12 = v10;
  direction->z = v11;
  direction->y = v10;
  v13 = (__m128)x_low;
  direction->z = 0.0;
  LODWORD(direction->x) = x_low;
  v13.m128_f32[0] = (float)(*(float *)&x_low * *(float *)&x_low) + (float)(v12 * v12);
  if ( v13.m128_f32[0] == 0.0 )
    v14 = 0.0;
  else
    v14 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
  result = 1;
  direction->z = v14 * 0.0;
  direction->x = *(float *)&x_low * v14;
  direction->y = v12 * v14;
  return result;
}

// File Line: 244
// RVA: 0x263950
char __fastcall UFG::NavModulePathing::AttemptInjectPath(
        UFG::NavModulePathing *this,
        UFG::HavokNavPosition *npPosition,
        UFG::HavokNavPosition *npDestination)
{
  float v4; // xmm2_4
  UFG::NavPath *m_pNavPath; // rcx
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx

  if ( (_S1_29 & 1) != 0 )
  {
    v4 = kfInjectionToleranceSqr;
  }
  else
  {
    _S1_29 |= 1u;
    v4 = FLOAT_2_25;
    kfInjectionToleranceSqr = FLOAT_2_25;
  }
  if ( !this->m_pInjectedPath.m_pNavPath
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(npPosition->m_vPosition.z - this->m_npInjectedPathSource.m_vPosition.z) & _xmm) >= 1.0
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(npDestination->m_vPosition.z - this->m_npInjectedPathDestination.m_vPosition.z) & _xmm) >= 1.0
    || (float)((float)((float)(npPosition->m_vPosition.y - this->m_npInjectedPathSource.m_vPosition.y)
                     * (float)(npPosition->m_vPosition.y - this->m_npInjectedPathSource.m_vPosition.y))
             + (float)((float)(npPosition->m_vPosition.x - this->m_npInjectedPathSource.m_vPosition.x)
                     * (float)(npPosition->m_vPosition.x - this->m_npInjectedPathSource.m_vPosition.x))) >= v4
    || (float)((float)((float)(npDestination->m_vPosition.y - this->m_npInjectedPathDestination.m_vPosition.y)
                     * (float)(npDestination->m_vPosition.y - this->m_npInjectedPathDestination.m_vPosition.y))
             + (float)((float)(npDestination->m_vPosition.x - this->m_npInjectedPathDestination.m_vPosition.x)
                     * (float)(npDestination->m_vPosition.x - this->m_npInjectedPathDestination.m_vPosition.x))) >= v4 )
  {
    return 0;
  }
  UFG::NavPathRefPtr::operator=(&this->m_pPath, &this->m_pInjectedPath);
  m_pNavPath = this->m_pInjectedPath.m_pNavPath;
  if ( m_pNavPath )
  {
    if ( m_pNavPath->m_uRefCount-- == 1 )
      m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
    this->m_pInjectedPath.m_pNavPath = 0i64;
  }
  m_pNavModuleLocal = this->m_navComponent->m_pNavModuleLocal;
  if ( m_pNavModuleLocal )
    m_pNavModuleLocal->vfptr->OnPathChanged(m_pNavModuleLocal);
  return 1;
}

// File Line: 298
// RVA: 0x265B80
void __fastcall UFG::NavModulePathing::RemoveGoalPointsBefore(
        UFG::NavModulePathing *this,
        UFG::NavModulePathing::GoalPoint **pGoal)
{
  UFG::qArray<UFG::NavModulePathing::GoalPoint,0> *p_m_aGoalPoints; // rdi
  __int64 v3; // rax
  signed int size; // r8d
  __int64 v6; // rbx

  p_m_aGoalPoints = &this->m_aGoalPoints;
  v3 = 0i64;
  size = this->m_aGoalPoints.size;
  if ( size > 0 )
  {
    while ( *pGoal != &this->m_aGoalPoints.p[v3] )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (int)v3 >= size )
        return;
    }
    if ( (_DWORD)v3 != -1 )
    {
      if ( (int)v3 > 0 )
      {
        v6 = (unsigned int)v3;
        do
        {
          UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(p_m_aGoalPoints, 0);
          --v6;
        }
        while ( v6 );
      }
      *pGoal = 0i64;
    }
  }
}

// File Line: 355
// RVA: 0x265C10
void __fastcall UFG::NavModulePathing::RemoveObsoleteGoalPoints(UFG::NavModulePathing *this)
{
  signed int size; // r9d
  int v2; // ebx
  signed int v3; // r8d
  __int64 v5; // rdx
  __int64 i; // rbx

  size = this->m_aGoalPoints.size;
  v2 = -1;
  v3 = 0;
  if ( size > 0 )
  {
    v5 = (unsigned int)(size - 1);
    while ( this->m_aGoalPoints.p[v5].m_append )
    {
      ++v3;
      v5 = (unsigned int)(v5 - 1);
      if ( v3 >= size )
        goto LABEL_7;
    }
    v2 = v5;
  }
LABEL_7:
  for ( i = (unsigned int)(v2 - 1);
        (int)i + 1 > 0 && (this->m_aGoalPoints.p[i].m_status & 5) != 0;
        i = (unsigned int)(i - 1) )
  {
    UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(&this->m_aGoalPoints, i);
  }
}

// File Line: 395
// RVA: 0x2663B0
void __fastcall UFG::NavModulePathing::SetupRepathing(UFG::NavModulePathing *this)
{
  UFG::NavPath *m_pNavPath; // r9
  __int64 v3; // rdx
  unsigned int i; // r8d
  __int64 v5; // rax
  __int64 v6; // rcx

  UFG::NavModulePathing::CancelPendingQuery(this);
  m_pNavPath = this->m_pPath.m_pNavPath;
  v3 = 0i64;
  if ( m_pNavPath )
  {
    for ( i = 0; i < m_pNavPath->m_aWaypoints.size; m_pNavPath = this->m_pPath.m_pNavPath )
    {
      v5 = i++;
      m_pNavPath->m_aWaypoints.p[v5].m_goalPoint = 0;
    }
  }
  if ( this->m_aGoalPoints.size )
  {
    do
    {
      v6 = v3;
      v3 = (unsigned int)(v3 + 1);
      this->m_aGoalPoints.p[v6].m_status = STATUS_WAITING_FOR_SCHEDULING;
    }
    while ( (unsigned int)v3 < this->m_aGoalPoints.size );
    this->m_aGoalPoints.p->m_append = 0;
  }
}

// File Line: 434
// RVA: 0x265F50
void __fastcall UFG::NavModulePathing::SchedulePathing(UFG::NavModulePathing *this, UFG::HavokNavPosition *npPosition)
{
  unsigned int size; // r8d
  unsigned int v5; // ecx
  unsigned int v6; // r9d
  unsigned int v7; // eax
  UFG::NavModulePathing::GoalPoint *p; // rsi
  bool m_append; // al
  UFG::allocator::free_link *v10; // rax
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx
  UFG::NavPath *m_pNavPath; // rcx
  UFG::HavokNavPosition *p_m_navPosition; // rdx
  UFG::DaemonManager *v14; // rax
  int v15; // eax
  UFG::NavWaypoint item; // [rsp+30h] [rbp-78h] BYREF
  UFG::NavModulePathing::GoalPoint *pGoal; // [rsp+B0h] [rbp+8h] BYREF
  UFG::allocator::free_link *v18; // [rsp+C0h] [rbp+18h]

  size = this->m_aGoalPoints.size;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  if ( size )
  {
    p = this->m_aGoalPoints.p;
    while ( 1 )
    {
      ++v5;
      if ( (p->m_status & 0xF) != 0 )
        break;
      ++v7;
      ++p;
      if ( v7 >= size )
        goto LABEL_7;
    }
    v6 = v5;
  }
  else
  {
LABEL_7:
    p = 0i64;
  }
  pGoal = p;
  if ( p )
  {
    if ( (p->m_status & 0xA) == 0 )
    {
      m_append = p->m_append;
      if ( !m_append || v6 <= 2 )
      {
        if ( p->m_direct )
        {
          v10 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
          v18 = v10;
          if ( v10 )
          {
            v10->mNext = (UFG::allocator::free_link *)&UFG::NavPath::`vftable;
            v10[2].mNext = 0i64;
            v10[1].mNext = 0i64;
            v10[4].mNext = 0i64;
            v10[3].mNext = 0i64;
            LODWORD(v10[5].mNext) = 0;
          }
          else
          {
            v10 = 0i64;
          }
          UFG::NavPathRefPtr::operator=(&this->m_pPath, (UFG::NavPath *)v10);
          item.m_navPosition.m_vPosition = p->m_npPosition.m_vPosition;
          item.m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
          item.m_navPosition.m_bValid = p->m_npPosition.m_bValid;
          item.m_navPosition.m_hkvMeshPosition = p->m_npPosition.m_hkvMeshPosition;
          item.m_navPosition.m_packedKey = p->m_npPosition.m_packedKey;
          item.m_navPosition.m_aiMeshUid = -1;
          item.m_pNavObject = 0i64;
          *(_WORD *)&item.m_stopPoint = 0;
          item.m_canSmooth = 1;
          UFG::qArray<UFG::NavWaypoint,0>::Insert(&this->m_pPath.m_pNavPath->m_aWaypoints, 0, &item, "qArray.Insert");
          this->m_pPath.m_pNavPath->m_aWaypoints.p[this->m_pPath.m_pNavPath->m_aWaypoints.size - 1].m_goalPoint = 1;
          p->m_status = STATUS_PROCESSED;
          UFG::NavModulePathing::RemoveGoalPointsBefore(this, &pGoal);
          m_pNavModuleLocal = this->m_navComponent->m_pNavModuleLocal;
          if ( m_pNavModuleLocal )
            m_pNavModuleLocal->vfptr->OnPathChanged(m_pNavModuleLocal);
        }
        else if ( m_append || !UFG::NavModulePathing::AttemptInjectPath(this, npPosition, &p->m_npPosition) )
        {
          m_pNavPath = this->m_pPath.m_pNavPath;
          if ( m_pNavPath && m_pNavPath->m_aWaypoints.size && p->m_append )
            p_m_navPosition = &m_pNavPath->m_aWaypoints.p[m_pNavPath->m_aWaypoints.size - 1].m_navPosition;
          else
            p_m_navPosition = npPosition;
          UFG::HavokNavPosition::operator=(&this->m_PathQueryInput.m_npFrom, p_m_navPosition);
          UFG::HavokNavPosition::operator=(&this->m_PathQueryInput.m_npTo, &p->m_npPosition);
          ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_PathQueryInput.m_npFrom.vfptr->Validate)(&this->m_PathQueryInput.m_npFrom);
          ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_PathQueryInput.m_npTo.vfptr->Validate)(&this->m_PathQueryInput.m_npTo);
          this->m_PathQueryInput.m_pNavParams = &this->m_navComponent->m_navParams;
          this->m_PathQueryInput.m_maxSearchIterations = p->m_maxSearchIterations;
          if ( this->m_PathQueryInput.m_npFrom.vfptr->IsMeshPositionValid(&this->m_PathQueryInput.m_npFrom) )
          {
            v14 = UFG::DaemonManager::Instance();
            UFG::DaemonManager::SubmitQuery(v14, &this->m_PathQueryInput, &this->m_PathQueryOutput);
            v15 = 2;
            if ( (p->m_status & 0xC) != 0 )
              v15 = 8;
            p->m_status = v15;
          }
          else
          {
            p->m_status = STATUS_FAILED_RESCHEDULING;
            this->m_bInvalidPath = 1;
          }
        }
        else
        {
          this->m_pPath.m_pNavPath->m_aWaypoints.p[this->m_pPath.m_pNavPath->m_aWaypoints.size - 1].m_goalPoint = 1;
          p->m_status = STATUS_PROCESSED;
          UFG::NavModulePathing::RemoveGoalPointsBefore(this, &pGoal);
        }
      }
    }
  }
}

// File Line: 516
// RVA: 0x2657C0
void __fastcall UFG::NavModulePathing::ReadPathingResults(
        UFG::NavModulePathing *this,
        UFG::HavokNavPosition *npPosition)
{
  unsigned int size; // ecx
  unsigned int v4; // eax
  UFG::NavModulePathing::GoalPoint *p; // r8
  UFG::DaemonOutputStatus m_status; // eax
  __int64 v8; // rdx
  UFG::NavPath *m_pNavPath; // r9
  __int64 v10; // r10
  unsigned int v11; // r11d
  UFG::NavPath *v12; // rcx
  char v13; // r14
  UFG::NavPath *v14; // rcx
  UFG::NavPath *v16; // rcx
  UFG::NavWaypoint *v17; // rax
  bool m_bValid; // al
  float y; // xmm1_4
  hkVector4f v20; // xmm3
  unsigned int m_packedKey; // ecx
  float z; // xmm2_4
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx
  UFG::NavModulePathing::GoalPoint *pGoal; // [rsp+40h] [rbp+8h] BYREF

  size = this->m_aGoalPoints.size;
  v4 = 0;
  if ( size )
  {
    p = this->m_aGoalPoints.p;
    while ( (p->m_status & 0xF) == 0 )
    {
      ++v4;
      ++p;
      if ( v4 >= size )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    p = 0i64;
  }
  pGoal = p;
  if ( p && (p->m_status & 5) == 0 )
  {
    m_status = this->m_PathQueryOutput.m_status;
    if ( m_status == Status_Failed )
    {
      p->m_status = STATUS_FAILED_RESCHEDULING;
      this->m_bInvalidPath = 1;
    }
    else if ( m_status == Status_Completed )
    {
      p->m_status = STATUS_PROCESSED;
      this->m_bInvalidPath = 0;
      v8 = 0i64;
      p->m_resourceTag = ++UFG::NavModulePathing::ms_resourceIndexer;
      m_pNavPath = this->m_PathQueryOutput.m_pPath.m_pNavPath;
      v10 = m_pNavPath->m_aResources.size;
      v11 = UFG::NavModulePathing::ms_resourceIndexer;
      if ( m_pNavPath->m_aResources.size )
      {
        do
          m_pNavPath->m_aResources.p[v8++]->m_tag = v11;
        while ( v8 < v10 );
      }
      v12 = this->m_pPath.m_pNavPath;
      if ( v12 && p->m_append )
      {
        v13 = 0;
        UFG::NavPath::Append(v12, this->m_PathQueryOutput.m_pPath.m_pNavPath);
      }
      else
      {
        v13 = 1;
        UFG::NavPathRefPtr::operator=(&this->m_pPath, &this->m_PathQueryOutput.m_pPath);
      }
      v14 = this->m_PathQueryOutput.m_pPath.m_pNavPath;
      if ( v14 )
      {
        if ( v14->m_uRefCount-- == 1 )
          v14->vfptr->__vecDelDtor(v14, 1u);
        this->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
      }
      if ( v13 )
      {
        UFG::NavModulePathing::RemoveGoalPointsBefore(this, &pGoal);
        v16 = this->m_pPath.m_pNavPath;
        v17 = v16->m_aWaypoints.p;
        if ( !v17->m_goalPoint
          && !v17->m_pNavObject
          && v16->m_aWaypoints.size > 1
          && (float)((float)((float)(v17->m_navPosition.m_vPosition.y - this->m_PathQueryInput.m_npFrom.m_vPosition.y)
                           * (float)(v17->m_navPosition.m_vPosition.y - this->m_PathQueryInput.m_npFrom.m_vPosition.y))
                   + (float)((float)(v17->m_navPosition.m_vPosition.x - this->m_PathQueryInput.m_npFrom.m_vPosition.x)
                           * (float)(v17->m_navPosition.m_vPosition.x - this->m_PathQueryInput.m_npFrom.m_vPosition.x))) < 0.0025000002 )
        {
          UFG::NavModulePathing::PopCurrentWaypoint(this);
        }
        if ( this->m_pPath.m_pNavPath->m_aWaypoints.size > 1 )
          UFG::NavModulePathing::UpdatePathStart(this, npPosition, 1, 1);
        m_bValid = npPosition->m_bValid;
        y = npPosition->m_vPosition.y;
        v20.m_quad = (__m128)npPosition->m_hkvMeshPosition;
        m_packedKey = npPosition->m_packedKey;
        z = npPosition->m_vPosition.z;
        this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x = npPosition->m_vPosition.x;
        this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y = y;
        this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.z = z;
        if ( m_bValid )
        {
          this->m_wpPreviousWaypoint.m_navPosition.m_bValid = m_bValid;
          this->m_wpPreviousWaypoint.m_navPosition.m_hkvMeshPosition = (hkVector4f)v20.m_quad;
          this->m_wpPreviousWaypoint.m_navPosition.m_packedKey = m_packedKey;
          this->m_wpPreviousWaypoint.m_navPosition.m_aiMeshUid = -1;
        }
        else
        {
          this->m_wpPreviousWaypoint.m_navPosition.m_bValid = 0;
        }
        this->m_wpPreviousWaypoint.m_pNavObject = 0i64;
        *(_WORD *)&this->m_wpPreviousWaypoint.m_stopPoint = 0;
        this->m_wpPreviousWaypoint.m_canSmooth = 1;
      }
      this->m_pPath.m_pNavPath->m_aWaypoints.p[this->m_pPath.m_pNavPath->m_aWaypoints.size - 1].m_goalPoint = 1;
      m_pNavModuleLocal = this->m_navComponent->m_pNavModuleLocal;
      if ( m_pNavModuleLocal )
        m_pNavModuleLocal->vfptr->OnPathChanged(m_pNavModuleLocal);
    }
  }
}

// File Line: 603
// RVA: 0x266290
void __fastcall UFG::NavModulePathing::SetInjectedPath(
        UFG::NavModulePathing *this,
        UFG::HavokNavPosition *npSource,
        UFG::HavokNavPosition *npDestination,
        UFG::NavPath *pInjectedPath)
{
  float y; // xmm0_4
  float z; // xmm1_4
  bool m_bValid; // al
  float v9; // xmm0_4
  float v10; // xmm1_4
  bool v11; // al
  UFG::NavPath *m_pNavPath; // rcx

  y = npSource->m_vPosition.y;
  z = npSource->m_vPosition.z;
  this->m_npInjectedPathSource.m_vPosition.x = npSource->m_vPosition.x;
  this->m_npInjectedPathSource.m_vPosition.y = y;
  this->m_npInjectedPathSource.m_vPosition.z = z;
  m_bValid = npSource->m_bValid;
  if ( m_bValid )
  {
    this->m_npInjectedPathSource.m_bValid = m_bValid;
    this->m_npInjectedPathSource.m_hkvMeshPosition = npSource->m_hkvMeshPosition;
    this->m_npInjectedPathSource.m_packedKey = npSource->m_packedKey;
    this->m_npInjectedPathSource.m_aiMeshUid = npSource->m_aiMeshUid;
  }
  else
  {
    this->m_npInjectedPathSource.m_bValid = 0;
  }
  v9 = npDestination->m_vPosition.y;
  v10 = npDestination->m_vPosition.z;
  this->m_npInjectedPathDestination.m_vPosition.x = npDestination->m_vPosition.x;
  this->m_npInjectedPathDestination.m_vPosition.y = v9;
  this->m_npInjectedPathDestination.m_vPosition.z = v10;
  v11 = npDestination->m_bValid;
  if ( v11 )
  {
    this->m_npInjectedPathDestination.m_bValid = v11;
    this->m_npInjectedPathDestination.m_hkvMeshPosition = npDestination->m_hkvMeshPosition;
    this->m_npInjectedPathDestination.m_packedKey = npDestination->m_packedKey;
    this->m_npInjectedPathDestination.m_aiMeshUid = npDestination->m_aiMeshUid;
  }
  else
  {
    this->m_npInjectedPathDestination.m_bValid = 0;
  }
  if ( this->m_pInjectedPath.m_pNavPath != pInjectedPath )
  {
    if ( pInjectedPath )
      ++pInjectedPath->m_uRefCount;
    m_pNavPath = this->m_pInjectedPath.m_pNavPath;
    if ( m_pNavPath )
    {
      if ( m_pNavPath->m_uRefCount-- == 1 )
        m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
    }
    this->m_pInjectedPath.m_pNavPath = pInjectedPath;
  }
}

// File Line: 611
// RVA: 0x2668C0
void __fastcall UFG::NavModulePathing::Update(UFG::NavModulePathing *this, float dt)
{
  UFG::HavokNavPosition *p_m_navPosition; // rdi
  unsigned int size; // edx
  UFG::NavPath *m_pNavPath; // rcx
  UFG::NavModulePathing::GoalPoint *p; // rcx
  UFG::NavPath *v8; // rax

  p_m_navPosition = &this->m_navComponent->m_navPosition;
  this->m_Deferrer[0].mTimeSinceLastCheck = dt + this->m_Deferrer[0].mTimeSinceLastCheck;
  this->m_Deferrer[1].mTimeSinceLastCheck = dt + this->m_Deferrer[1].mTimeSinceLastCheck;
  if ( !this->m_bGoalRefreshed )
    UFG::NavModulePathing::ClearPath(this);
  size = this->m_aGoalPoints.size;
  if ( size )
  {
    m_pNavPath = this->m_pPath.m_pNavPath;
    this->m_elapsedTimeTowardGoal = dt + this->m_elapsedTimeTowardGoal;
    if ( m_pNavPath )
    {
      if ( m_pNavPath->m_aWaypoints.size && this->m_aGoalPoints.p->m_holdingCompletePath && size == 1 )
      {
        if ( m_pNavPath->m_uRefCount-- == 1 )
          ((void (__fastcall *)(UFG::NavPath *))m_pNavPath->vfptr->__vecDelDtor)(m_pNavPath);
        this->m_pPath.m_pNavPath = 0i64;
        p = this->m_aGoalPoints.p;
        if ( p )
          operator delete[](p);
        this->m_aGoalPoints.p = 0i64;
        *(_QWORD *)&this->m_aGoalPoints.size = 0i64;
        this->m_bRequestReplan = 0;
      }
    }
  }
  UFG::NavModulePathing::ReadPathingResults(this, p_m_navPosition);
  UFG::NavModulePathing::RemoveObsoleteGoalPoints(this);
  v8 = this->m_pPath.m_pNavPath;
  if ( !v8 || !v8->m_aWaypoints.size || !this->m_aGoalPoints.size || !this->m_aGoalPoints.p->m_holdingCompletePath )
    UFG::NavModulePathing::UpdatePath(this, p_m_navPosition);
  UFG::NavModulePathing::SchedulePathing(this, p_m_navPosition);
  this->m_bGoalRefreshed = 0;
}

// File Line: 672
// RVA: 0x264F10
bool __fastcall UFG::NavModulePathing::HasPath(UFG::NavModulePathing *this)
{
  UFG::NavPath *m_pNavPath; // rax

  m_pNavPath = this->m_pPath.m_pNavPath;
  return m_pNavPath && m_pNavPath->m_aWaypoints.size;
}

// File Line: 678
// RVA: 0x263CA0
void __fastcall UFG::NavModulePathing::ClearPath(UFG::NavModulePathing *this)
{
  UFG::NavPath *m_pNavPath; // rcx
  UFG::NavModulePathing::GoalPoint *p; // rcx

  m_pNavPath = this->m_pPath.m_pNavPath;
  if ( m_pNavPath )
  {
    if ( m_pNavPath->m_uRefCount-- == 1 )
      m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
    this->m_pPath.m_pNavPath = 0i64;
  }
  if ( !this->m_bForceGoalAdvance )
  {
    UFG::NavModulePathing::CancelPendingQuery(this);
    p = this->m_aGoalPoints.p;
    if ( p )
      operator delete[](p);
    this->m_aGoalPoints.p = 0i64;
    *(_QWORD *)&this->m_aGoalPoints.size = 0i64;
    *(_WORD *)&this->m_bGoalRefreshed = 0;
  }
}

// File Line: 710
// RVA: 0x264320
UFG::NavObject *__fastcall UFG::NavModulePathing::GetNavObject(UFG::NavModulePathing *this)
{
  UFG::NavPath *m_pNavPath; // rax

  m_pNavPath = this->m_pPath.m_pNavPath;
  if ( m_pNavPath && m_pNavPath->m_aWaypoints.size )
    return m_pNavPath->m_aWaypoints.p->m_pNavObject;
  else
    return 0i64;
}

// File Line: 735
// RVA: 0x266EC0
void __fastcall UFG::NavModulePathing::UpdatePath(UFG::NavModulePathing *this, UFG::HavokNavPosition *npPosition)
{
  UFG::NavPath *m_pNavPath; // rax
  UFG::NavPath *v4; // r9
  __int64 v5; // rdx
  unsigned int i; // r8d
  __int64 v7; // rax
  __int64 v8; // rcx

  m_pNavPath = this->m_pPath.m_pNavPath;
  if ( m_pNavPath && m_pNavPath->m_aWaypoints.size && !UFG::NavModulePathing::UpdatePathStart(this, npPosition, 0, 0) )
  {
    UFG::NavModulePathing::CancelPendingQuery(this);
    v4 = this->m_pPath.m_pNavPath;
    v5 = 0i64;
    if ( v4 )
    {
      for ( i = 0; i < v4->m_aWaypoints.size; v4 = this->m_pPath.m_pNavPath )
      {
        v7 = i++;
        v4->m_aWaypoints.p[v7].m_goalPoint = 0;
      }
    }
    if ( this->m_aGoalPoints.size )
    {
      do
      {
        v8 = v5;
        v5 = (unsigned int)(v5 + 1);
        this->m_aGoalPoints.p[v8].m_status = STATUS_WAITING_FOR_SCHEDULING;
      }
      while ( (unsigned int)v5 < this->m_aGoalPoints.size );
      this->m_aGoalPoints.p->m_append = 0;
    }
  }
}

// File Line: 750
// RVA: 0x264F30
bool __fastcall UFG::NavModulePathing::HoldingCompletedPath(UFG::NavModulePathing *this)
{
  UFG::NavPath *m_pNavPath; // rax

  m_pNavPath = this->m_pPath.m_pNavPath;
  return m_pNavPath
      && m_pNavPath->m_aWaypoints.size
      && this->m_aGoalPoints.size
      && this->m_aGoalPoints.p->m_holdingCompletePath;
}

// File Line: 800
// RVA: 0x266F90
char __fastcall UFG::NavModulePathing::UpdatePathStart(
        UFG::NavModulePathing *this,
        UFG::HavokNavPosition *navPosition,
        bool forceRaycast,
        bool keepEnd)
{
  char v8; // bp
  UFG::NavPath *m_pNavPath; // rcx
  char result; // al
  UFG::NavObject *m_pNavObject; // rcx
  UFG::NavWaypoint *p; // r14
  UFG::NavObject *v13; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  float m_fRadius; // xmm0_4
  UFG::NavParams m_navParams; // [rsp+50h] [rbp+8h] BYREF

  v8 = 0;
  UFG::NavModulePathing::CalculateHalfSpace(this);
  while ( UFG::NavModulePathing::CurrentWaypointReached(this, navPosition, forceRaycast, keepEnd) )
  {
    if ( UFG::NavModulePathing::HoldingCompletedPath(this) )
      break;
    v8 = 1;
    UFG::NavModulePathing::PopCurrentWaypoint(this);
  }
  m_pNavPath = this->m_pPath.m_pNavPath;
  if ( m_pNavPath
    && m_pNavPath->m_aWaypoints.size
    && this->m_aGoalPoints.size
    && this->m_aGoalPoints.p->m_holdingCompletePath )
  {
    return 1;
  }
  if ( this->m_bRequestReplan )
  {
    this->m_bRequestReplan = 0;
    return 0;
  }
  if ( !m_pNavPath || !m_pNavPath->m_aWaypoints.size )
    return 1;
  m_pNavObject = m_pNavPath->m_aWaypoints.p->m_pNavObject;
  if ( m_pNavObject )
    m_pNavObject->vfptr->Update(m_pNavObject, this->m_navComponent);
  p = this->m_pPath.m_pNavPath->m_aWaypoints.p;
  v13 = p->m_pNavObject;
  if ( !v13 )
  {
    if ( !v8 && (forceRaycast || UFG::TestDeferrer::IsStale(&this->m_Deferrer[1], &navPosition->m_vPosition)) )
    {
      y = navPosition->m_vPosition.y;
      z = navPosition->m_vPosition.z;
      this->m_Deferrer[1].mLastPosition.x = navPosition->m_vPosition.x;
      this->m_Deferrer[1].mLastPosition.y = y;
      m_fRadius = FLOAT_0_1;
      this->m_Deferrer[1].mLastPosition.z = z;
      this->m_Deferrer[1].mTimeSinceLastCheck = 0.0;
      m_navParams = this->m_navComponent->m_navParams;
      if ( m_navParams.m_fRadius <= 0.1 )
        m_fRadius = m_navParams.m_fRadius;
      m_navParams.m_fRadius = m_fRadius;
      if ( UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
             UFG::NavManager::ms_pInstance,
             navPosition,
             (UFG::HavokNavPosition *)p,
             &m_navParams,
             0i64) )
      {
        return 0;
      }
    }
    return 1;
  }
  result = v13->vfptr->IsValidWaypoint(v13, this->m_navComponent);
  if ( result )
    return 1;
  return result;
}

// File Line: 909
// RVA: 0x263D70
char __fastcall UFG::NavModulePathing::CurrentWaypointReached(
        UFG::NavModulePathing *this,
        UFG::HavokNavPosition *navPosition,
        __int64 forceRaycast,
        __int64 keepEnd)
{
  UFG::NavPath *m_pNavPath; // rdi
  unsigned int size; // eax
  bool IsInsideCurrGoalRadius; // cl
  bool v10; // dl
  UFG::NavWaypoint *p; // rdi
  UFG::NavObject *m_pNavObject; // rsi
  bool IsStale; // al
  float y; // xmm0_4
  float z; // xmm1_4
  float v16; // xmm3_4
  __m128 y_low; // xmm1
  __m128 v18; // xmm2
  float v19; // xmm2_4

  m_pNavPath = this->m_pPath.m_pNavPath;
  if ( !m_pNavPath )
    return 0;
  size = m_pNavPath->m_aWaypoints.size;
  if ( !size )
    return 0;
  if ( size > 1 )
  {
    p = m_pNavPath->m_aWaypoints.p;
    m_pNavObject = p->m_pNavObject;
    if ( m_pNavObject )
    {
      return ((__int64 (__fastcall *)(UFG::NavObject *, UFG::NavComponent *, __int64, __int64))m_pNavObject->vfptr->CurrentWaypointReached)(
               p->m_pNavObject,
               this->m_navComponent,
               forceRaycast,
               keepEnd);
    }
    else
    {
      if ( (_BYTE)forceRaycast || (IsStale = UFG::TestDeferrer::IsStale(this->m_Deferrer, &navPosition->m_vPosition)) )
        IsStale = 1;
      if ( p->m_goalPoint
        || !p->m_canSmooth
        || !IsStale
        || (y = navPosition->m_vPosition.y,
            z = navPosition->m_vPosition.z,
            this->m_Deferrer[0].mLastPosition.x = navPosition->m_vPosition.x,
            this->m_Deferrer[0].mLastPosition.y = y,
            this->m_Deferrer[0].mLastPosition.z = z,
            this->m_Deferrer[0].mTimeSinceLastCheck = 0.0,
            UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
              UFG::NavManager::ms_pInstance,
              navPosition,
              (UFG::HavokNavPosition *)&p[1],
              &this->m_navComponent->m_navParams,
              0i64)) )
      {
        UFG::NavModulePathing::CalculateHalfSpace(this);
        y_low = (__m128)LODWORD(p->m_navPosition.m_vPosition.y);
        v16 = p->m_navPosition.m_vPosition.x - navPosition->m_vPosition.x;
        y_low.m128_f32[0] = y_low.m128_f32[0] - navPosition->m_vPosition.y;
        v18 = y_low;
        v18.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v16 * v16);
        if ( v18.m128_f32[0] == 0.0 )
          v19 = 0.0;
        else
          v19 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
        return (float)((float)((float)(y_low.m128_f32[0] * v19) * this->m_vHalfSpaceNormal.y)
                     + (float)((float)(v19 * v16) * this->m_vHalfSpaceNormal.x)) <= 0.0;
      }
      else
      {
        return 1;
      }
    }
  }
  else
  {
    if ( (_BYTE)keepEnd )
      return 0;
    if ( this->m_bAtDestination )
    {
      return 1;
    }
    else
    {
      IsInsideCurrGoalRadius = UFG::NavModulePathing::IsInsideCurrGoalRadius(this, navPosition);
      v10 = IsInsideCurrGoalRadius && this->m_aGoalPoints.size == 1;
      this->m_bAtDestination = v10;
      if ( v10 )
        this->m_aGoalPoints.p->m_holdingCompletePath = 1;
      return IsInsideCurrGoalRadius;
    }
  }
}

// File Line: 989
// RVA: 0x265360
bool __fastcall UFG::NavModulePathing::IsInsideCurrGoalRadius(
        UFG::NavModulePathing *this,
        UFG::HavokNavPosition *npAgentPosition)
{
  bool result; // al
  float m_tolerance; // xmm2_4
  UFG::NavPath *m_pNavPath; // rcx
  UFG::NavWaypoint *p; // r9
  float v6; // xmm1_4
  float v7; // xmm0_4

  if ( !this->m_aGoalPoints.size )
    return 0;
  m_tolerance = this->m_aGoalPoints.p->m_tolerance;
  if ( m_tolerance <= 0.0 )
    m_tolerance = FLOAT_0_30000001;
  m_pNavPath = this->m_pPath.m_pNavPath;
  p = m_pNavPath->m_aWaypoints.p;
  result = 0;
  v6 = npAgentPosition->m_vPosition.y - p[m_pNavPath->m_aWaypoints.size - 1].m_navPosition.m_vPosition.y;
  v7 = npAgentPosition->m_vPosition.x - p[m_pNavPath->m_aWaypoints.size - 1].m_navPosition.m_vPosition.x;
  if ( (float)((float)(v6 * v6) + (float)(v7 * v7)) < (float)(m_tolerance * m_tolerance) )
    return COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          npAgentPosition->m_vPosition.z
                        - p[m_pNavPath->m_aWaypoints.size - 1].m_navPosition.m_vPosition.z) & _xmm) < 2.0;
  return result;
}

// File Line: 1049
// RVA: 0x2656A0
void __fastcall UFG::NavModulePathing::PopCurrentWaypoint(UFG::NavModulePathing *this)
{
  UFG::NavWaypoint *p; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  bool m_bValid; // al
  UFG::NavPath *m_pNavPath; // rbx
  UFG::NavWaypoint *v7; // rdi
  UFG::NavObject *m_pNavObject; // rcx

  p = this->m_pPath.m_pNavPath->m_aWaypoints.p;
  y = p->m_navPosition.m_vPosition.y;
  z = p->m_navPosition.m_vPosition.z;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x = p->m_navPosition.m_vPosition.x;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y = y;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.z = z;
  m_bValid = p->m_navPosition.m_bValid;
  if ( m_bValid )
  {
    this->m_wpPreviousWaypoint.m_navPosition.m_bValid = m_bValid;
    this->m_wpPreviousWaypoint.m_navPosition.m_hkvMeshPosition = p->m_navPosition.m_hkvMeshPosition;
    this->m_wpPreviousWaypoint.m_navPosition.m_packedKey = p->m_navPosition.m_packedKey;
    this->m_wpPreviousWaypoint.m_navPosition.m_aiMeshUid = p->m_navPosition.m_aiMeshUid;
  }
  else
  {
    this->m_wpPreviousWaypoint.m_navPosition.m_bValid = 0;
  }
  this->m_wpPreviousWaypoint.m_pNavObject = p->m_pNavObject;
  this->m_wpPreviousWaypoint.m_stopPoint = p->m_stopPoint;
  this->m_wpPreviousWaypoint.m_goalPoint = p->m_goalPoint;
  this->m_wpPreviousWaypoint.m_canSmooth = p->m_canSmooth;
  if ( this->m_wpPreviousWaypoint.m_goalPoint )
  {
    UFG::NavPath::RemoveTaggedResources(this->m_pPath.m_pNavPath, this->m_aGoalPoints.p->m_resourceTag);
    UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(&this->m_aGoalPoints, 0);
    this->m_elapsedTimeTowardGoal = 0.0;
  }
  m_pNavPath = this->m_pPath.m_pNavPath;
  v7 = m_pNavPath->m_aWaypoints.p;
  m_pNavObject = v7->m_pNavObject;
  if ( m_pNavObject )
  {
    m_pNavObject->vfptr->__vecDelDtor(m_pNavObject, 1u);
    v7->m_pNavObject = 0i64;
  }
  UFG::qArray<UFG::NavWaypoint,0>::StableDelete(&m_pNavPath->m_aWaypoints, 0);
}

// File Line: 1079
// RVA: 0x263AB0
void __fastcall UFG::NavModulePathing::CalculateHalfSpace(UFG::NavModulePathing *this)
{
  UFG::NavPath *m_pNavPath; // rcx
  unsigned int size; // eax
  UFG::NavWaypoint *p; // rax
  float v5; // xmm1_4
  float v6; // xmm6_4
  __m128 y_low; // xmm7
  __m128 v8; // xmm3
  __m128 v9; // xmm4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  __m128 v14; // xmm4
  float v15; // xmm4_4
  float v16; // xmm2_4
  __m128 v17; // xmm4
  float v18; // xmm1_4
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::NavWaypoint *v21; // rcx

  m_pNavPath = this->m_pPath.m_pNavPath;
  size = m_pNavPath->m_aWaypoints.size;
  if ( size > 1 )
  {
    p = m_pNavPath->m_aWaypoints.p;
    v5 = *(float *)&FLOAT_1_0;
    y_low = (__m128)LODWORD(p->m_navPosition.m_vPosition.y);
    v6 = p->m_navPosition.m_vPosition.x - this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x;
    y_low.m128_f32[0] = y_low.m128_f32[0] - this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y;
    v8 = (__m128)LODWORD(p[1].m_navPosition.m_vPosition.y);
    v9 = y_low;
    v9.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v6 * v6);
    if ( v9.m128_f32[0] == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
    v11 = p[1].m_navPosition.m_vPosition.x - p->m_navPosition.m_vPosition.x;
    v8.m128_f32[0] = v8.m128_f32[0] - p->m_navPosition.m_vPosition.y;
    v12 = v6 * v10;
    v13 = y_low.m128_f32[0] * v10;
    v14 = v8;
    v14.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v11 * v11);
    if ( v14.m128_f32[0] == 0.0 )
      v15 = 0.0;
    else
      v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
    v16 = (float)(v11 * v15) + v12;
    v8.m128_f32[0] = (float)(v8.m128_f32[0] * v15) + v13;
    v17 = v8;
    v17.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v16 * v16);
    if ( v17.m128_f32[0] == 0.0 )
    {
      v18 = 0.0;
      goto LABEL_17;
    }
LABEL_16:
    v18 = v5 / _mm_sqrt_ps(v17).m128_f32[0];
    goto LABEL_17;
  }
  if ( size != 1 )
    return;
  m_pSimObject = this->m_navComponent->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v18 = 0.0;
  v21 = this->m_pPath.m_pNavPath->m_aWaypoints.p;
  v8 = (__m128)LODWORD(v21->m_navPosition.m_vPosition.y);
  v16 = v21->m_navPosition.m_vPosition.x - m_pTransformNodeComponent->mWorldTransform.v3.x;
  v8.m128_f32[0] = v8.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y;
  v17 = v8;
  v17.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v16 * v16);
  if ( v17.m128_f32[0] != 0.0 )
  {
    v5 = *(float *)&FLOAT_1_0;
    goto LABEL_16;
  }
LABEL_17:
  this->m_vHalfSpaceNormal.y = v8.m128_f32[0] * v18;
  this->m_vHalfSpaceNormal.x = v16 * v18;
}

