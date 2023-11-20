// File Line: 40
// RVA: 0x262960
void __fastcall UFG::NavModulePathing::NavModulePathing(UFG::NavModulePathing *this, UFG::NavComponent *parent)
{
  UFG::NavModulePathing *v2; // rbx
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  signed __int64 v11; // [rsp+58h] [rbp+10h]

  v2 = this;
  this->vfptr = (UFG::NavModulePathingVtbl *)&UFG::NavModulePathing::`vftable;
  *(_QWORD *)&this->m_bGoalRefreshed = 0i64;
  this->m_navComponent = parent;
  this->m_wpPreviousWaypoint.m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y = v3;
  this->m_wpPreviousWaypoint.m_navPosition.m_vPosition.z = v4;
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
  v11 = (signed __int64)&v2->m_PathQueryOutput;
  *(_OWORD *)v11 = (unsigned __int64)&UFG::DaemonQueryOutput::`vftable;
  *(_DWORD *)(v11 + 16) = 0;
  *(_QWORD *)v11 = &UFG::FindPathOutput::`vftable;
  v2->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
  *(_QWORD *)&v2->m_Deferrer[0].mLastPosition.x = 0i64;
  *(_QWORD *)&v2->m_Deferrer[0].mLastPosition.z = 0i64;
  *(_QWORD *)&v2->m_Deferrer[0].mDistanceTolerance = 0i64;
  v2->m_Deferrer[0].mResult = 0;
  *(_QWORD *)&v2->m_Deferrer[1].mLastPosition.x = 0i64;
  *(_QWORD *)&v2->m_Deferrer[1].mLastPosition.z = 0i64;
  *(_QWORD *)&v2->m_Deferrer[1].mDistanceTolerance = 0i64;
  v2->m_Deferrer[1].mResult = 0;
  v2->m_npInjectedPathSource.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  v2->m_npInjectedPathSource.m_vPosition.x = UFG::qVector3::msZero.x;
  v2->m_npInjectedPathSource.m_vPosition.y = v5;
  v2->m_npInjectedPathSource.m_vPosition.z = v6;
  v2->m_npInjectedPathSource.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v2->m_npInjectedPathSource.m_bValid = 0;
  v2->m_npInjectedPathSource.m_hkvMeshPosition = (hkVector4f)hkvZero_5.m_quad;
  *(_QWORD *)&v2->m_npInjectedPathSource.m_packedKey = -1i64;
  v2->m_npInjectedPathDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  v2->m_npInjectedPathDestination.m_vPosition.x = UFG::qVector3::msZero.x;
  v2->m_npInjectedPathDestination.m_vPosition.y = v7;
  v2->m_npInjectedPathDestination.m_vPosition.z = v8;
  v2->m_npInjectedPathDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v2->m_npInjectedPathDestination.m_bValid = 0;
  v2->m_npInjectedPathDestination.m_hkvMeshPosition = (hkVector4f)hkvZero_5.m_quad;
  *(_QWORD *)&v2->m_npInjectedPathDestination.m_packedKey = -1i64;
  v2->m_pPath.m_pNavPath = 0i64;
  v2->m_pInjectedPath.m_pNavPath = 0i64;
  v2->m_aGoalPoints.p = 0i64;
  *(_QWORD *)&v2->m_aGoalPoints.size = 0i64;
  *(_WORD *)&v2->m_bInvalidPath = 0;
  v9 = UFG::qRandom(0.0, &UFG::qDefaultSeed);
  *(_QWORD *)&v2->m_Deferrer[0].mLastPosition.x = 0i64;
  v2->m_Deferrer[0].mLastPosition.z = 0.0;
  v2->m_Deferrer[0].mTimeSinceLastCheck = v9;
  *(_QWORD *)&v2->m_Deferrer[0].mDistanceTolerance = 0i64;
  v2->m_Deferrer[0].mResult = 0;
  v10 = UFG::qRandom(0.0, &UFG::qDefaultSeed);
  *(_QWORD *)&v2->m_Deferrer[1].mLastPosition.x = 0i64;
  v2->m_Deferrer[1].mLastPosition.z = 0.0;
  v2->m_Deferrer[1].mTimeSinceLastCheck = v10;
  *(_QWORD *)&v2->m_Deferrer[1].mDistanceTolerance = 0i64;
  v2->m_Deferrer[1].mResult = 0;
}

// File Line: 58
// RVA: 0x262EB0
void __fastcall UFG::NavModulePathing::~NavModulePathing(UFG::NavModulePathing *this)
{
  UFG::NavModulePathing *v1; // rbx
  UFG::NavModulePathing::GoalPoint *v2; // rcx
  UFG::NavPath *v3; // rcx
  bool v4; // zf
  UFG::NavPath *v5; // rcx
  UFG::NavPath *v6; // rcx

  v1 = this;
  this->vfptr = (UFG::NavModulePathingVtbl *)&UFG::NavModulePathing::`vftable;
  UFG::NavModulePathing::CancelPendingQuery(this);
  UFG::NavModulePathing::ClearPath(v1);
  if ( v1->m_bForceGoalAdvance )
  {
    UFG::NavModulePathing::SetupRepathing(v1);
    v1->m_bForceGoalAdvance = 0;
    if ( !v1->m_aGoalPoints.size )
      v1->m_bAtDestination = 1;
  }
  v2 = v1->m_aGoalPoints.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_aGoalPoints.p = 0i64;
  *(_QWORD *)&v1->m_aGoalPoints.size = 0i64;
  v3 = v1->m_pInjectedPath.m_pNavPath;
  if ( v3 )
  {
    v4 = v3->m_uRefCount-- == 1;
    if ( v4 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  v5 = v1->m_pPath.m_pNavPath;
  if ( v5 )
  {
    v4 = v5->m_uRefCount-- == 1;
    if ( v4 )
      v5->vfptr->__vecDelDtor(v5, 1u);
  }
  v6 = v1->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( v6 )
  {
    v4 = v6->m_uRefCount-- == 1;
    if ( v4 )
      v6->vfptr->__vecDelDtor(v6, 1u);
  }
  v1->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  v1->m_PathQueryInput.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
}

// File Line: 64
// RVA: 0x265F10
void __fastcall UFG::NavModulePathing::Reset(UFG::NavModulePathing *this)
{
  UFG::NavModulePathing *v1; // rbx
  bool v2; // zf

  v1 = this;
  UFG::NavModulePathing::CancelPendingQuery(this);
  UFG::NavModulePathing::ClearPath(v1);
  if ( v1->m_bForceGoalAdvance )
  {
    UFG::NavModulePathing::SetupRepathing(v1);
    v2 = v1->m_aGoalPoints.size == 0;
    v1->m_bForceGoalAdvance = 0;
    if ( v2 )
      v1->m_bAtDestination = 1;
  }
}

// File Line: 86
// RVA: 0x263C30
void __fastcall UFG::NavModulePathing::CancelPendingQuery(UFG::NavModulePathing *this)
{
  unsigned int v1; // edx
  unsigned int v2; // eax
  UFG::NavModulePathing::GoalPoint *v3; // rdi
  UFG::DaemonQueryInput *v4; // rbx
  UFG::DaemonManager *v5; // rax

  v1 = this->m_aGoalPoints.size;
  v2 = 0;
  if ( v1 )
  {
    v3 = this->m_aGoalPoints.p;
    while ( !(v3->m_status & 0xA) )
    {
      ++v2;
      ++v3;
      if ( v2 >= v1 )
        return;
    }
    v4 = (UFG::DaemonQueryInput *)&this->m_PathQueryInput.vfptr;
    v5 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::CancelQuery(v5, v4);
    v3->m_status = 1;
  }
}

// File Line: 124
// RVA: 0x2634B0
void __fastcall UFG::NavModulePathing::AddGoalPointUid(UFG::NavModulePathing *this, UFG::HavokNavPosition *npPosition, UFG::AiPathGoalMode goalMode, float speed, int userId, int maxSearchIterations, float tolerance)
{
  UFG::AiPathGoalMode v7; // esi
  bool v8; // r12
  UFG::HavokNavPosition *v9; // rdi
  UFG::NavModulePathing *v10; // rbx
  unsigned int v11; // eax
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  UFG::NavModulePathing::GoalPoint *v15; // rdx
  UFG::NavPath *v16; // rcx
  bool v17; // zf
  UFG::NavModulePathing::GoalPoint *v18; // rcx
  bool v19; // bp
  unsigned int v20; // er14
  unsigned int v21; // er15
  __m128 v22; // xmm6
  float v23; // xmm8_4
  float v24; // xmm10_4
  float v25; // xmm9_4
  UFG::qArray<UFG::NavModulePathing::GoalPoint,0> *v26; // rsi
  __int64 v27; // r13
  unsigned int v28; // edx
  unsigned int v29; // edi
  unsigned int v30; // edx
  UFG::NavModulePathing *v31; // rcx
  bool v32; // [rsp+B0h] [rbp+18h]

  v7 = goalMode;
  v8 = goalMode == 1;
  v9 = npPosition;
  v10 = this;
  this->m_bGoalRefreshed = 1;
  if ( goalMode == AiGoal_Replace || v8 )
  {
    v11 = this->m_aGoalPoints.size;
    if ( v11 )
    {
      v12 = npPosition->m_vPosition.x;
      v13 = npPosition->m_vPosition.y;
      v14 = npPosition->m_vPosition.z;
      v15 = &this->m_aGoalPoints.p[v11 - 1];
      if ( (float)((float)((float)((float)(v12 - v15->m_npPosition.m_vPosition.x)
                                 * (float)(v12 - v15->m_npPosition.m_vPosition.x))
                         + (float)((float)(v13 - v15->m_npPosition.m_vPosition.y)
                                 * (float)(v13 - v15->m_npPosition.m_vPosition.y)))
                 + (float)((float)(v14 - v15->m_npPosition.m_vPosition.z)
                         * (float)(v14 - v15->m_npPosition.m_vPosition.z))) < UFG::NavModulePathing::ms_fDestinationTolerance )
      {
        v15->m_speed = speed;
        v15->m_maxSearchIterations = maxSearchIterations;
        v15->m_tolerance = tolerance;
        return;
      }
      if ( v8 )
      {
        v16 = this->m_pPath.m_pNavPath;
        if ( v16 )
        {
          v17 = v16->m_uRefCount-- == 1;
          if ( v17 )
            v16->vfptr->__vecDelDtor(v16, 1u);
          v10->m_pPath.m_pNavPath = 0i64;
        }
        v18 = v10->m_aGoalPoints.p;
        if ( v18 )
          operator delete[](v18);
        v10->m_aGoalPoints.p = 0i64;
        *(_QWORD *)&v10->m_aGoalPoints.size = 0i64;
      }
    }
    v10->m_bAtDestination = 0;
  }
  v19 = v9->m_bValid;
  v20 = -1;
  v21 = -1;
  v22 = hkvZero_5.m_quad;
  v23 = v9->m_vPosition.x;
  v24 = v9->m_vPosition.z;
  v25 = v9->m_vPosition.y;
  if ( v19 )
  {
    v22 = v9->m_hkvMeshPosition.m_quad;
    v20 = v9->m_packedKey;
    v21 = v9->m_aiMeshUid;
  }
  else
  {
    v19 = 0;
  }
  v17 = v7 == 2;
  v26 = &v10->m_aGoalPoints;
  v27 = v10->m_aGoalPoints.size;
  v28 = v10->m_aGoalPoints.capacity;
  v32 = v17;
  v29 = v27 + 1;
  if ( (signed int)v27 + 1 > v28 )
  {
    if ( v28 )
      v30 = 2 * v28;
    else
      v30 = 1;
    for ( ; v30 < v29; v30 *= 2 )
      ;
    if ( v30 - v29 > 0x10000 )
      v30 = v27 + 65537;
    UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::Reallocate(&v10->m_aGoalPoints, v30, "qArray.Add");
  }
  v26->size = v29;
  v31 = (UFG::NavModulePathing *)&v10->m_aGoalPoints.p[v27];
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
  if ( v19 )
  {
    v31->m_wpPreviousWaypoint.m_navPosition.m_bValid = v19;
    v31->m_wpPreviousWaypoint.m_navPosition.m_hkvMeshPosition.m_quad = v22;
    v31->m_wpPreviousWaypoint.m_navPosition.m_packedKey = v20;
    v31->m_wpPreviousWaypoint.m_navPosition.m_aiMeshUid = v21;
  }
  else
  {
    v31->m_wpPreviousWaypoint.m_navPosition.m_bValid = 0;
  }
  if ( v26->size > 0x32 && !(v10->m_aGoalPoints.p->m_status & 0xA) )
    UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(&v10->m_aGoalPoints, 0);
}

// File Line: 187
// RVA: 0x2641A0
char __fastcall UFG::NavModulePathing::GetCurrGoalPointInfo(UFG::NavModulePathing *this, UFG::qVector3 *position, UFG::qVector3 *direction, float *elapsedTime, int *uid)
{
  char result; // al
  UFG::NavModulePathing::GoalPoint *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4
  __int128 v9; // xmm2
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  __m128 v13; // xmm1
  float v14; // xmm1_4

  if ( !this->m_aGoalPoints.size )
    return 0;
  *elapsedTime = this->m_elapsedTimeTowardGoal;
  v6 = this->m_aGoalPoints.p;
  v7 = v6->m_npPosition.m_vPosition.y;
  v8 = v6->m_npPosition.m_vPosition.z;
  position->x = v6->m_npPosition.m_vPosition.x;
  position->y = v7;
  position->z = v8;
  *uid = this->m_aGoalPoints.p->m_userId;
  if ( this->m_aGoalPoints.size <= 1 )
  {
    v9 = LODWORD(position->x);
    *(float *)&v9 = *(float *)&v9 - this->m_navComponent->m_navPosition.m_vPosition.x;
    v10 = position->y - this->m_navComponent->m_navPosition.m_vPosition.y;
    v11 = position->z - this->m_navComponent->m_navPosition.m_vPosition.z;
  }
  else
  {
    v9 = LODWORD(this->m_aGoalPoints.p[1].m_npPosition.m_vPosition.x);
    *(float *)&v9 = *(float *)&v9 - position->x;
    v10 = this->m_aGoalPoints.p[1].m_npPosition.m_vPosition.y - position->y;
    v11 = this->m_aGoalPoints.p[1].m_npPosition.m_vPosition.z - position->z;
  }
  v12 = v10;
  direction->z = v11;
  direction->y = v10;
  v13 = (__m128)v9;
  direction->z = 0.0;
  LODWORD(direction->x) = v9;
  v13.m128_f32[0] = (float)(*(float *)&v9 * *(float *)&v9) + (float)(v12 * v12);
  if ( v13.m128_f32[0] == 0.0 )
    v14 = 0.0;
  else
    v14 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
  result = 1;
  direction->z = v14 * 0.0;
  direction->x = *(float *)&v9 * v14;
  direction->y = v12 * v14;
  return result;
}

// File Line: 244
// RVA: 0x263950
char __fastcall UFG::NavModulePathing::AttemptInjectPath(UFG::NavModulePathing *this, UFG::HavokNavPosition *npPosition, UFG::HavokNavPosition *npDestination)
{
  UFG::NavModulePathing *v3; // rbx
  float v4; // xmm2_4
  UFG::NavPath *v5; // rcx
  bool v6; // zf
  UFG::NavModuleLocal *v7; // rcx

  v3 = this;
  if ( _S1_29 & 1 )
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
  v5 = v3->m_pInjectedPath.m_pNavPath;
  if ( v5 )
  {
    v6 = v5->m_uRefCount-- == 1;
    if ( v6 )
      v5->vfptr->__vecDelDtor(v5, 1u);
    v3->m_pInjectedPath.m_pNavPath = 0i64;
  }
  v7 = v3->m_navComponent->m_pNavModuleLocal;
  if ( v7 )
    ((void (__cdecl *)(UFG::NavModuleLocal *))v7->vfptr->OnPathChanged)(v7);
  return 1;
}

// File Line: 298
// RVA: 0x265B80
void __fastcall UFG::NavModulePathing::RemoveGoalPointsBefore(UFG::NavModulePathing *this, UFG::NavModulePathing::GoalPoint **pGoal)
{
  UFG::qArray<UFG::NavModulePathing::GoalPoint,0> *v2; // rdi
  __int64 v3; // rax
  UFG::NavModulePathing::GoalPoint **v4; // rsi
  signed int v5; // er8
  __int64 v6; // rbx

  v2 = &this->m_aGoalPoints;
  v3 = 0i64;
  v4 = pGoal;
  v5 = this->m_aGoalPoints.size;
  if ( v5 > 0 )
  {
    while ( *pGoal != &this->m_aGoalPoints.p[v3] )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (signed int)v3 >= v5 )
        return;
    }
    if ( (_DWORD)v3 != -1 )
    {
      if ( (signed int)v3 > 0 )
      {
        v6 = (unsigned int)v3;
        do
        {
          UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(v2, 0);
          --v6;
        }
        while ( v6 );
      }
      *v4 = 0i64;
    }
  }
}

// File Line: 355
// RVA: 0x265C10
void __fastcall UFG::NavModulePathing::RemoveObsoleteGoalPoints(UFG::NavModulePathing *this)
{
  signed int v1; // er9
  signed int v2; // ebx
  signed int v3; // er8
  UFG::NavModulePathing *v4; // rsi
  __int64 v5; // rdx
  __int64 i; // rbx

  v1 = this->m_aGoalPoints.size;
  v2 = -1;
  v3 = 0;
  v4 = this;
  if ( v1 > 0 )
  {
    v5 = (unsigned int)(v1 - 1);
    while ( this->m_aGoalPoints.p[v5].m_append )
    {
      ++v3;
      v5 = (unsigned int)(v5 - 1);
      if ( v3 >= v1 )
        goto LABEL_7;
    }
    v2 = v5;
  }
LABEL_7:
  for ( i = (unsigned int)(v2 - 1); (signed int)i + 1 > 0 && v4->m_aGoalPoints.p[i].m_status & 5; i = (unsigned int)(i - 1) )
    UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(&v4->m_aGoalPoints, i);
}

// File Line: 395
// RVA: 0x2663B0
void __fastcall UFG::NavModulePathing::SetupRepathing(UFG::NavModulePathing *this)
{
  UFG::NavModulePathing *v1; // rbx
  UFG::NavPath *v2; // r9
  signed __int64 v3; // rdx
  unsigned int i; // er8
  __int64 v5; // rax
  signed __int64 v6; // rcx

  v1 = this;
  UFG::NavModulePathing::CancelPendingQuery(this);
  v2 = v1->m_pPath.m_pNavPath;
  v3 = 0i64;
  if ( v2 )
  {
    for ( i = 0; i < v2->m_aWaypoints.size; v2 = v1->m_pPath.m_pNavPath )
    {
      v5 = i++;
      v2->m_aWaypoints.p[v5].m_goalPoint = 0;
    }
  }
  if ( v1->m_aGoalPoints.size )
  {
    do
    {
      v6 = v3;
      v3 = (unsigned int)(v3 + 1);
      v1->m_aGoalPoints.p[v6].m_status = 1;
    }
    while ( (unsigned int)v3 < v1->m_aGoalPoints.size );
    v1->m_aGoalPoints.p->m_append = 0;
  }
}

// File Line: 434
// RVA: 0x265F50
void __fastcall UFG::NavModulePathing::SchedulePathing(UFG::NavModulePathing *this, UFG::HavokNavPosition *npPosition)
{
  UFG::HavokNavPosition *v2; // rbx
  UFG::NavModulePathing *v3; // rdi
  unsigned int v4; // er8
  unsigned int v5; // ecx
  unsigned int v6; // er9
  unsigned int v7; // eax
  UFG::NavModulePathing::GoalPoint *v8; // rsi
  bool v9; // al
  UFG::allocator::free_link *v10; // rax
  UFG::NavModuleLocal *v11; // rcx
  UFG::NavPath *v12; // rcx
  UFG::HavokNavPosition *v13; // rdx
  UFG::DaemonManager *v14; // rax
  signed int v15; // eax
  UFG::NavWaypoint item; // [rsp+30h] [rbp-78h]
  UFG::NavModulePathing::GoalPoint *pGoal; // [rsp+B0h] [rbp+8h]
  UFG::allocator::free_link *v18; // [rsp+C0h] [rbp+18h]

  v2 = npPosition;
  v3 = this;
  v4 = this->m_aGoalPoints.size;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  if ( v4 )
  {
    v8 = v3->m_aGoalPoints.p;
    while ( 1 )
    {
      ++v5;
      if ( v8->m_status & 0xF )
        break;
      ++v7;
      ++v8;
      if ( v7 >= v4 )
        goto LABEL_7;
    }
    v6 = v5;
  }
  else
  {
LABEL_7:
    v8 = 0i64;
  }
  pGoal = v8;
  if ( v8 )
  {
    if ( !(v8->m_status & 0xA) )
    {
      v9 = v8->m_append;
      if ( !v9 || v6 <= 2 )
      {
        if ( v8->m_direct )
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
          UFG::NavPathRefPtr::operator=(&v3->m_pPath, (UFG::NavPath *)v10);
          item.m_navPosition.m_vPosition.x = v8->m_npPosition.m_vPosition.x;
          item.m_navPosition.m_vPosition.y = v8->m_npPosition.m_vPosition.y;
          item.m_navPosition.m_vPosition.z = v8->m_npPosition.m_vPosition.z;
          item.m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
          item.m_navPosition.m_bValid = v8->m_npPosition.m_bValid;
          item.m_navPosition.m_hkvMeshPosition = v8->m_npPosition.m_hkvMeshPosition;
          item.m_navPosition.m_packedKey = v8->m_npPosition.m_packedKey;
          item.m_navPosition.m_aiMeshUid = -1;
          item.m_pNavObject = 0i64;
          *(_WORD *)&item.m_stopPoint = 0;
          item.m_canSmooth = 1;
          UFG::qArray<UFG::NavWaypoint,0>::Insert(&v3->m_pPath.m_pNavPath->m_aWaypoints, 0, &item, "qArray.Insert");
          v3->m_pPath.m_pNavPath->m_aWaypoints.p[v3->m_pPath.m_pNavPath->m_aWaypoints.size - 1].m_goalPoint = 1;
          v8->m_status = 16;
          UFG::NavModulePathing::RemoveGoalPointsBefore(v3, &pGoal);
          v11 = v3->m_navComponent->m_pNavModuleLocal;
          if ( v11 )
            ((void (__cdecl *)(UFG::NavModuleLocal *))v11->vfptr->OnPathChanged)(v11);
        }
        else if ( v9 || !UFG::NavModulePathing::AttemptInjectPath(v3, npPosition, &v8->m_npPosition) )
        {
          v12 = v3->m_pPath.m_pNavPath;
          if ( v12 && v12->m_aWaypoints.size > 0 && v8->m_append )
            v13 = &v12->m_aWaypoints.p[v12->m_aWaypoints.size - 1].m_navPosition;
          else
            v13 = v2;
          UFG::HavokNavPosition::operator=(&v3->m_PathQueryInput.m_npFrom, v13);
          UFG::HavokNavPosition::operator=(&v3->m_PathQueryInput.m_npTo, &v8->m_npPosition);
          ((void (__fastcall *)(UFG::HavokNavPosition *))v3->m_PathQueryInput.m_npFrom.vfptr->Validate)(&v3->m_PathQueryInput.m_npFrom);
          ((void (__fastcall *)(UFG::HavokNavPosition *))v3->m_PathQueryInput.m_npTo.vfptr->Validate)(&v3->m_PathQueryInput.m_npTo);
          v3->m_PathQueryInput.m_pNavParams = &v3->m_navComponent->m_navParams;
          v3->m_PathQueryInput.m_maxSearchIterations = v8->m_maxSearchIterations;
          if ( v3->m_PathQueryInput.m_npFrom.vfptr->IsMeshPositionValid((UFG::NavPositionBase *)&v3->m_PathQueryInput.m_npFrom.vfptr) )
          {
            v14 = UFG::DaemonManager::Instance();
            UFG::DaemonManager::SubmitQuery(
              v14,
              (UFG::DaemonQueryInput *)&v3->m_PathQueryInput.vfptr,
              (UFG::DaemonQueryOutput *)&v3->m_PathQueryOutput.vfptr);
            v15 = 2;
            if ( v8->m_status & 0xC )
              v15 = 8;
            v8->m_status = v15;
          }
          else
          {
            v8->m_status = 4;
            v3->m_bInvalidPath = 1;
          }
        }
        else
        {
          v3->m_pPath.m_pNavPath->m_aWaypoints.p[v3->m_pPath.m_pNavPath->m_aWaypoints.size - 1].m_goalPoint = 1;
          v8->m_status = 16;
          UFG::NavModulePathing::RemoveGoalPointsBefore(v3, &pGoal);
        }
      }
    }
  }
}

// File Line: 516
// RVA: 0x2657C0
void __fastcall UFG::NavModulePathing::ReadPathingResults(UFG::NavModulePathing *this, UFG::HavokNavPosition *npPosition)
{
  UFG::NavModulePathing *v2; // rbx
  unsigned int v3; // ecx
  unsigned int v4; // eax
  UFG::HavokNavPosition *v5; // rbp
  UFG::NavModulePathing::GoalPoint *v6; // r8
  UFG::DaemonOutputStatus v7; // eax
  __int64 v8; // rdx
  UFG::NavPath *v9; // r9
  __int64 v10; // r10
  unsigned int v11; // er11
  UFG::NavPath *v12; // rcx
  char v13; // r14
  UFG::NavPath *v14; // rcx
  bool v15; // zf
  UFG::NavPath *v16; // rcx
  UFG::NavWaypoint *v17; // rax
  bool v18; // al
  float v19; // xmm1_4
  hkVector4f v20; // xmm3
  unsigned int v21; // ecx
  float v22; // xmm2_4
  UFG::NavModuleLocal *v23; // rcx
  UFG::NavModulePathing::GoalPoint *pGoal; // [rsp+40h] [rbp+8h]

  v2 = this;
  v3 = this->m_aGoalPoints.size;
  v4 = 0;
  v5 = npPosition;
  if ( v3 )
  {
    v6 = v2->m_aGoalPoints.p;
    while ( !(v6->m_status & 0xF) )
    {
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v6 = 0i64;
  }
  pGoal = v6;
  if ( v6 && !(v6->m_status & 5) )
  {
    v7 = v2->m_PathQueryOutput.m_status;
    if ( v7 == 4 )
    {
      v6->m_status = 4;
      v2->m_bInvalidPath = 1;
    }
    else if ( v7 == 3 )
    {
      v6->m_status = 16;
      v2->m_bInvalidPath = 0;
      v8 = 0i64;
      v6->m_resourceTag = ++UFG::NavModulePathing::ms_resourceIndexer;
      v9 = v2->m_PathQueryOutput.m_pPath.m_pNavPath;
      v10 = v9->m_aResources.size;
      v11 = UFG::NavModulePathing::ms_resourceIndexer;
      if ( v10 > 0 )
      {
        do
          v9->m_aResources.p[++v8 - 1]->m_tag = v11;
        while ( v8 < v10 );
      }
      v12 = v2->m_pPath.m_pNavPath;
      if ( v12 && v6->m_append )
      {
        v13 = 0;
        UFG::NavPath::Append(v12, v2->m_PathQueryOutput.m_pPath.m_pNavPath);
      }
      else
      {
        v13 = 1;
        UFG::NavPathRefPtr::operator=(&v2->m_pPath, &v2->m_PathQueryOutput.m_pPath);
      }
      v14 = v2->m_PathQueryOutput.m_pPath.m_pNavPath;
      if ( v14 )
      {
        v15 = v14->m_uRefCount-- == 1;
        if ( v15 )
          v14->vfptr->__vecDelDtor(v14, 1u);
        v2->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
      }
      if ( v13 )
      {
        UFG::NavModulePathing::RemoveGoalPointsBefore(v2, &pGoal);
        v16 = v2->m_pPath.m_pNavPath;
        v17 = v16->m_aWaypoints.p;
        if ( !v17->m_goalPoint
          && !v17->m_pNavObject
          && v16->m_aWaypoints.size > 1
          && (float)((float)((float)(v17->m_navPosition.m_vPosition.y - v2->m_PathQueryInput.m_npFrom.m_vPosition.y)
                           * (float)(v17->m_navPosition.m_vPosition.y - v2->m_PathQueryInput.m_npFrom.m_vPosition.y))
                   + (float)((float)(v17->m_navPosition.m_vPosition.x - v2->m_PathQueryInput.m_npFrom.m_vPosition.x)
                           * (float)(v17->m_navPosition.m_vPosition.x - v2->m_PathQueryInput.m_npFrom.m_vPosition.x))) < 0.0025000002 )
        {
          UFG::NavModulePathing::PopCurrentWaypoint(v2);
        }
        if ( v2->m_pPath.m_pNavPath->m_aWaypoints.size > 1 )
          UFG::NavModulePathing::UpdatePathStart(v2, v5, 1, 1);
        v18 = v5->m_bValid;
        v19 = v5->m_vPosition.y;
        v20.m_quad = (__m128)v5->m_hkvMeshPosition;
        v21 = v5->m_packedKey;
        v22 = v5->m_vPosition.z;
        v2->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x = v5->m_vPosition.x;
        v2->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y = v19;
        v2->m_wpPreviousWaypoint.m_navPosition.m_vPosition.z = v22;
        if ( v18 )
        {
          v2->m_wpPreviousWaypoint.m_navPosition.m_bValid = v18;
          v2->m_wpPreviousWaypoint.m_navPosition.m_hkvMeshPosition = (hkVector4f)v20.m_quad;
          v2->m_wpPreviousWaypoint.m_navPosition.m_packedKey = v21;
          v2->m_wpPreviousWaypoint.m_navPosition.m_aiMeshUid = -1;
        }
        else
        {
          v2->m_wpPreviousWaypoint.m_navPosition.m_bValid = 0;
        }
        v2->m_wpPreviousWaypoint.m_pNavObject = 0i64;
        *(_WORD *)&v2->m_wpPreviousWaypoint.m_stopPoint = 0;
        v2->m_wpPreviousWaypoint.m_canSmooth = 1;
      }
      v2->m_pPath.m_pNavPath->m_aWaypoints.p[v2->m_pPath.m_pNavPath->m_aWaypoints.size - 1].m_goalPoint = 1;
      v23 = v2->m_navComponent->m_pNavModuleLocal;
      if ( v23 )
        ((void (*)(void))v23->vfptr->OnPathChanged)();
    }
  }
}

// File Line: 603
// RVA: 0x266290
void __fastcall UFG::NavModulePathing::SetInjectedPath(UFG::NavModulePathing *this, UFG::HavokNavPosition *npSource, UFG::HavokNavPosition *npDestination, UFG::NavPath *pInjectedPath)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  UFG::NavPath *v6; // rdi
  UFG::NavModulePathing *v7; // rbx
  bool v8; // al
  float v9; // xmm0_4
  float v10; // xmm1_4
  bool v11; // al
  UFG::NavPath *v12; // rcx
  bool v13; // zf

  v4 = npSource->m_vPosition.y;
  v5 = npSource->m_vPosition.z;
  this->m_npInjectedPathSource.m_vPosition.x = npSource->m_vPosition.x;
  v6 = pInjectedPath;
  v7 = this;
  this->m_npInjectedPathSource.m_vPosition.y = v4;
  this->m_npInjectedPathSource.m_vPosition.z = v5;
  v8 = npSource->m_bValid;
  if ( v8 )
  {
    this->m_npInjectedPathSource.m_bValid = v8;
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
    v12 = this->m_pInjectedPath.m_pNavPath;
    if ( v12 )
    {
      v13 = v12->m_uRefCount-- == 1;
      if ( v13 )
        v12->vfptr->__vecDelDtor(v12, 1u);
    }
    v7->m_pInjectedPath.m_pNavPath = v6;
  }
}

// File Line: 611
// RVA: 0x2668C0
void __fastcall UFG::NavModulePathing::Update(UFG::NavModulePathing *this, float dt)
{
  UFG::HavokNavPosition *v2; // rdi
  UFG::NavModulePathing *v3; // rbx
  unsigned int v4; // edx
  UFG::NavPath *v5; // rcx
  bool v6; // zf
  UFG::NavModulePathing::GoalPoint *v7; // rcx
  UFG::NavPath *v8; // rax

  v2 = &this->m_navComponent->m_navPosition;
  v3 = this;
  this->m_Deferrer[0].mTimeSinceLastCheck = dt + this->m_Deferrer[0].mTimeSinceLastCheck;
  this->m_Deferrer[1].mTimeSinceLastCheck = dt + this->m_Deferrer[1].mTimeSinceLastCheck;
  if ( !this->m_bGoalRefreshed )
    UFG::NavModulePathing::ClearPath(this);
  v4 = v3->m_aGoalPoints.size;
  if ( v4 )
  {
    v5 = v3->m_pPath.m_pNavPath;
    v3->m_elapsedTimeTowardGoal = dt + v3->m_elapsedTimeTowardGoal;
    if ( v5 )
    {
      if ( v5->m_aWaypoints.size && v3->m_aGoalPoints.p->m_holdingCompletePath && v4 == 1 )
      {
        v6 = v5->m_uRefCount-- == 1;
        if ( v6 )
          ((void (*)(void))v5->vfptr->__vecDelDtor)();
        v3->m_pPath.m_pNavPath = 0i64;
        v7 = v3->m_aGoalPoints.p;
        if ( v7 )
          operator delete[](v7);
        v3->m_aGoalPoints.p = 0i64;
        *(_QWORD *)&v3->m_aGoalPoints.size = 0i64;
        v3->m_bRequestReplan = 0;
      }
    }
  }
  UFG::NavModulePathing::ReadPathingResults(v3, v2);
  UFG::NavModulePathing::RemoveObsoleteGoalPoints(v3);
  v8 = v3->m_pPath.m_pNavPath;
  if ( !v8 || !v8->m_aWaypoints.size || !v3->m_aGoalPoints.size || !v3->m_aGoalPoints.p->m_holdingCompletePath )
    UFG::NavModulePathing::UpdatePath(v3, v2);
  UFG::NavModulePathing::SchedulePathing(v3, v2);
  v3->m_bGoalRefreshed = 0;
}

// File Line: 672
// RVA: 0x264F10
bool __fastcall UFG::NavModulePathing::HasPath(UFG::NavModulePathing *this)
{
  UFG::NavPath *v1; // rax

  v1 = this->m_pPath.m_pNavPath;
  return v1 && v1->m_aWaypoints.size;
}

// File Line: 678
// RVA: 0x263CA0
void __fastcall UFG::NavModulePathing::ClearPath(UFG::NavModulePathing *this)
{
  UFG::NavModulePathing *v1; // rbx
  UFG::NavPath *v2; // rcx
  bool v3; // zf
  UFG::NavModulePathing::GoalPoint *v4; // rcx

  v1 = this;
  v2 = this->m_pPath.m_pNavPath;
  if ( v2 )
  {
    v3 = v2->m_uRefCount-- == 1;
    if ( v3 )
      v2->vfptr->__vecDelDtor(v2, 1u);
    v1->m_pPath.m_pNavPath = 0i64;
  }
  if ( !v1->m_bForceGoalAdvance )
  {
    UFG::NavModulePathing::CancelPendingQuery(v1);
    v4 = v1->m_aGoalPoints.p;
    if ( v4 )
      operator delete[](v4);
    v1->m_aGoalPoints.p = 0i64;
    *(_QWORD *)&v1->m_aGoalPoints.size = 0i64;
    *(_WORD *)&v1->m_bGoalRefreshed = 0;
  }
}

// File Line: 710
// RVA: 0x264320
UFG::NavObject *__fastcall UFG::NavModulePathing::GetNavObject(UFG::NavModulePathing *this)
{
  UFG::NavPath *v1; // rax
  UFG::NavObject *result; // rax

  v1 = this->m_pPath.m_pNavPath;
  if ( v1 && v1->m_aWaypoints.size )
    result = v1->m_aWaypoints.p->m_pNavObject;
  else
    result = 0i64;
  return result;
}

// File Line: 735
// RVA: 0x266EC0
void __fastcall UFG::NavModulePathing::UpdatePath(UFG::NavModulePathing *this, UFG::HavokNavPosition *npPosition)
{
  UFG::NavPath *v2; // rax
  UFG::NavModulePathing *v3; // rbx
  UFG::NavPath *v4; // r9
  signed __int64 v5; // rdx
  unsigned int i; // er8
  __int64 v7; // rax
  signed __int64 v8; // rcx

  v2 = this->m_pPath.m_pNavPath;
  v3 = this;
  if ( v2 && v2->m_aWaypoints.size && !UFG::NavModulePathing::UpdatePathStart(this, npPosition, 0, 0) )
  {
    UFG::NavModulePathing::CancelPendingQuery(v3);
    v4 = v3->m_pPath.m_pNavPath;
    v5 = 0i64;
    if ( v4 )
    {
      for ( i = 0; i < v4->m_aWaypoints.size; v4 = v3->m_pPath.m_pNavPath )
      {
        v7 = i++;
        v4->m_aWaypoints.p[v7].m_goalPoint = 0;
      }
    }
    if ( v3->m_aGoalPoints.size )
    {
      do
      {
        v8 = v5;
        v5 = (unsigned int)(v5 + 1);
        v3->m_aGoalPoints.p[v8].m_status = 1;
      }
      while ( (unsigned int)v5 < v3->m_aGoalPoints.size );
      v3->m_aGoalPoints.p->m_append = 0;
    }
  }
}

// File Line: 750
// RVA: 0x264F30
bool __fastcall UFG::NavModulePathing::HoldingCompletedPath(UFG::NavModulePathing *this)
{
  UFG::NavPath *v1; // rax

  v1 = this->m_pPath.m_pNavPath;
  return v1 && v1->m_aWaypoints.size && this->m_aGoalPoints.size && this->m_aGoalPoints.p->m_holdingCompletePath;
}

// File Line: 800
// RVA: 0x266F90
char __fastcall UFG::NavModulePathing::UpdatePathStart(UFG::NavModulePathing *this, UFG::HavokNavPosition *navPosition, bool forceRaycast, bool keepEnd)
{
  bool v4; // r14
  bool v5; // si
  UFG::HavokNavPosition *v6; // rdi
  UFG::NavModulePathing *v7; // rbx
  char v8; // bp
  UFG::NavPath *v9; // rcx
  char result; // al
  UFG::NavObject *v11; // rcx
  UFG::HavokNavPosition *v12; // r14
  UFG::NavPositionBaseVtbl *v13; // rcx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  UFG::NavParams v17; // [rsp+50h] [rbp+8h]

  v4 = keepEnd;
  v5 = forceRaycast;
  v6 = navPosition;
  v7 = this;
  v8 = 0;
  UFG::NavModulePathing::CalculateHalfSpace(this);
  while ( UFG::NavModulePathing::CurrentWaypointReached(v7, v6, v5, v4) )
  {
    if ( UFG::NavModulePathing::HoldingCompletedPath(v7) )
      break;
    v8 = 1;
    UFG::NavModulePathing::PopCurrentWaypoint(v7);
  }
  v9 = v7->m_pPath.m_pNavPath;
  if ( v9 && v9->m_aWaypoints.size && v7->m_aGoalPoints.size && v7->m_aGoalPoints.p->m_holdingCompletePath )
    return 1;
  if ( v7->m_bRequestReplan )
  {
    v7->m_bRequestReplan = 0;
    return 0;
  }
  if ( !v9 || !v9->m_aWaypoints.size )
    return 1;
  v11 = v9->m_aWaypoints.p->m_pNavObject;
  if ( v11 )
    v11->vfptr->Update(v11, v7->m_navComponent);
  v12 = &v7->m_pPath.m_pNavPath->m_aWaypoints.p->m_navPosition;
  v13 = v12[1].vfptr;
  if ( !v13 )
  {
    if ( !v8 && (v5 || UFG::TestDeferrer::IsStale(&v7->m_Deferrer[1], &v6->m_vPosition)) )
    {
      v14 = v6->m_vPosition.y;
      v15 = v6->m_vPosition.z;
      v7->m_Deferrer[1].mLastPosition.x = v6->m_vPosition.x;
      v7->m_Deferrer[1].mLastPosition.y = v14;
      v16 = FLOAT_0_1;
      v7->m_Deferrer[1].mLastPosition.z = v15;
      v7->m_Deferrer[1].mTimeSinceLastCheck = 0.0;
      v17 = v7->m_navComponent->m_navParams;
      if ( v17.m_fRadius <= 0.1 )
        v16 = v17.m_fRadius;
      v17.m_fRadius = v16;
      if ( UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(UFG::NavManager::ms_pInstance, v6, v12, &v17, 0i64) )
        return 0;
    }
    return 1;
  }
  result = (*((__int64 (__fastcall **)(UFG::NavPositionBaseVtbl *, UFG::NavComponent *))v13->Validate + 5))(
             v13,
             v7->m_navComponent);
  if ( result )
    return 1;
  return result;
}

// File Line: 909
// RVA: 0x263D70
char __fastcall UFG::NavModulePathing::CurrentWaypointReached(UFG::NavModulePathing *this, UFG::HavokNavPosition *navPosition, __int64 forceRaycast, __int64 keepEnd)
{
  UFG::NavPath *v4; // rdi
  UFG::HavokNavPosition *v5; // rbp
  UFG::NavModulePathing *v6; // rbx
  unsigned int v7; // eax
  char result; // al
  bool v9; // cl
  bool v10; // dl
  UFG::NavWaypoint *v11; // rdi
  UFG::NavObject *v12; // rsi
  bool v13; // al
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  float v19; // xmm2_4

  v4 = this->m_pPath.m_pNavPath;
  v5 = navPosition;
  v6 = this;
  if ( !v4 )
    return 0;
  v7 = v4->m_aWaypoints.size;
  if ( !v7 )
    return 0;
  if ( v7 > 1 )
  {
    v11 = v4->m_aWaypoints.p;
    v12 = v11->m_pNavObject;
    if ( v12 )
    {
      result = ((__int64 (__fastcall *)(UFG::NavObject *, UFG::NavComponent *, __int64, __int64))v12->vfptr->CurrentWaypointReached)(
                 v11->m_pNavObject,
                 this->m_navComponent,
                 forceRaycast,
                 keepEnd);
    }
    else
    {
      if ( (_BYTE)forceRaycast || (v13 = UFG::TestDeferrer::IsStale(this->m_Deferrer, &navPosition->m_vPosition)) != 0 )
        v13 = 1;
      if ( v11->m_goalPoint
        || !v11->m_canSmooth
        || !v13
        || (v14 = v5->m_vPosition.y,
            v15 = v5->m_vPosition.z,
            v6->m_Deferrer[0].mLastPosition.x = v5->m_vPosition.x,
            v6->m_Deferrer[0].mLastPosition.y = v14,
            v6->m_Deferrer[0].mLastPosition.z = v15,
            v6->m_Deferrer[0].mTimeSinceLastCheck = 0.0,
            UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
              UFG::NavManager::ms_pInstance,
              v5,
              (UFG::HavokNavPosition *)&v11[1],
              &v6->m_navComponent->m_navParams,
              0i64)) )
      {
        UFG::NavModulePathing::CalculateHalfSpace(v6);
        v17 = (__m128)LODWORD(v11->m_navPosition.m_vPosition.y);
        v16 = v11->m_navPosition.m_vPosition.x - v5->m_vPosition.x;
        v17.m128_f32[0] = v17.m128_f32[0] - v5->m_vPosition.y;
        v18 = v17;
        v18.m128_f32[0] = (float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16);
        if ( v18.m128_f32[0] == 0.0 )
          v19 = 0.0;
        else
          v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
        result = (float)((float)((float)(v17.m128_f32[0] * v19) * v6->m_vHalfSpaceNormal.y)
                       + (float)((float)(v19 * v16) * v6->m_vHalfSpaceNormal.x)) <= 0.0;
      }
      else
      {
        result = 1;
      }
    }
  }
  else
  {
    if ( (_BYTE)keepEnd )
      return 0;
    if ( this->m_bAtDestination )
    {
      result = 1;
    }
    else
    {
      v9 = UFG::NavModulePathing::IsInsideCurrGoalRadius(this, navPosition);
      v10 = v9 && v6->m_aGoalPoints.size == 1;
      v6->m_bAtDestination = v10;
      if ( v10 )
        v6->m_aGoalPoints.p->m_holdingCompletePath = 1;
      result = v9;
    }
  }
  return result;
}

// File Line: 989
// RVA: 0x265360
char __fastcall UFG::NavModulePathing::IsInsideCurrGoalRadius(UFG::NavModulePathing *this, UFG::HavokNavPosition *npAgentPosition)
{
  char result; // al
  float v3; // xmm2_4
  UFG::NavPath *v4; // rcx
  UFG::NavWaypoint *v5; // r9
  float v6; // xmm1_4
  float v7; // xmm0_4

  if ( !this->m_aGoalPoints.size )
    return 0;
  v3 = this->m_aGoalPoints.p->m_tolerance;
  if ( v3 <= 0.0 )
    v3 = FLOAT_0_30000001;
  v4 = this->m_pPath.m_pNavPath;
  v5 = v4->m_aWaypoints.p;
  result = 0;
  v6 = npAgentPosition->m_vPosition.y - v5[v4->m_aWaypoints.size - 1].m_navPosition.m_vPosition.y;
  v7 = npAgentPosition->m_vPosition.x - v5[v4->m_aWaypoints.size - 1].m_navPosition.m_vPosition.x;
  if ( (float)((float)(v6 * v6) + (float)(v7 * v7)) < (float)(v3 * v3) )
  {
    result = 0;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(npAgentPosition->m_vPosition.z - v5[v4->m_aWaypoints.size - 1].m_navPosition.m_vPosition.z) & _xmm) < 2.0 )
      result = 1;
  }
  return result;
}

// File Line: 1049
// RVA: 0x2656A0
void __fastcall UFG::NavModulePathing::PopCurrentWaypoint(UFG::NavModulePathing *this)
{
  UFG::NavModulePathing *v1; // rbx
  UFG::NavWaypoint *v2; // rcx
  float v3; // xmm0_4
  float v4; // xmm1_4
  bool v5; // al
  UFG::NavPath *v6; // rbx
  UFG::NavWaypoint *v7; // rdi
  UFG::NavObject *v8; // rcx

  v1 = this;
  v2 = this->m_pPath.m_pNavPath->m_aWaypoints.p;
  v3 = v2->m_navPosition.m_vPosition.y;
  v4 = v2->m_navPosition.m_vPosition.z;
  v1->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x = v2->m_navPosition.m_vPosition.x;
  v1->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y = v3;
  v1->m_wpPreviousWaypoint.m_navPosition.m_vPosition.z = v4;
  v5 = v2->m_navPosition.m_bValid;
  if ( v5 )
  {
    v1->m_wpPreviousWaypoint.m_navPosition.m_bValid = v5;
    v1->m_wpPreviousWaypoint.m_navPosition.m_hkvMeshPosition = v2->m_navPosition.m_hkvMeshPosition;
    v1->m_wpPreviousWaypoint.m_navPosition.m_packedKey = v2->m_navPosition.m_packedKey;
    v1->m_wpPreviousWaypoint.m_navPosition.m_aiMeshUid = v2->m_navPosition.m_aiMeshUid;
  }
  else
  {
    v1->m_wpPreviousWaypoint.m_navPosition.m_bValid = 0;
  }
  v1->m_wpPreviousWaypoint.m_pNavObject = v2->m_pNavObject;
  v1->m_wpPreviousWaypoint.m_stopPoint = v2->m_stopPoint;
  v1->m_wpPreviousWaypoint.m_goalPoint = v2->m_goalPoint;
  v1->m_wpPreviousWaypoint.m_canSmooth = v2->m_canSmooth;
  if ( v1->m_wpPreviousWaypoint.m_goalPoint )
  {
    UFG::NavPath::RemoveTaggedResources(v1->m_pPath.m_pNavPath, v1->m_aGoalPoints.p->m_resourceTag);
    UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(&v1->m_aGoalPoints, 0);
    v1->m_elapsedTimeTowardGoal = 0.0;
  }
  v6 = v1->m_pPath.m_pNavPath;
  v7 = v6->m_aWaypoints.p;
  v8 = v7->m_pNavObject;
  if ( v8 )
  {
    v8->vfptr->__vecDelDtor(v8, 1u);
    v7->m_pNavObject = 0i64;
  }
  UFG::qArray<UFG::NavWaypoint,0>::StableDelete(&v6->m_aWaypoints, 0);
}

// File Line: 1079
// RVA: 0x263AB0
void __fastcall UFG::NavModulePathing::CalculateHalfSpace(UFG::NavModulePathing *this)
{
  UFG::NavModulePathing *v1; // rbx
  UFG::NavPath *v2; // rcx
  unsigned int v3; // eax
  UFG::NavWaypoint *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm6_4
  __m128 v7; // xmm7
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
  UFG::SimObject *v19; // rcx
  UFG::TransformNodeComponent *v20; // rdi
  UFG::NavWaypoint *v21; // rcx

  v1 = this;
  v2 = this->m_pPath.m_pNavPath;
  v3 = v2->m_aWaypoints.size;
  if ( v3 > 1 )
  {
    v4 = v2->m_aWaypoints.p;
    v5 = *(float *)&FLOAT_1_0;
    v7 = (__m128)LODWORD(v4->m_navPosition.m_vPosition.y);
    v6 = v4->m_navPosition.m_vPosition.x - v1->m_wpPreviousWaypoint.m_navPosition.m_vPosition.x;
    v7.m128_f32[0] = v7.m128_f32[0] - v1->m_wpPreviousWaypoint.m_navPosition.m_vPosition.y;
    v8 = (__m128)LODWORD(v4[1].m_navPosition.m_vPosition.y);
    v9 = v7;
    v9.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v6 * v6);
    if ( v9.m128_f32[0] == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
    v11 = v4[1].m_navPosition.m_vPosition.x - v4->m_navPosition.m_vPosition.x;
    v8.m128_f32[0] = v8.m128_f32[0] - v4->m_navPosition.m_vPosition.y;
    v12 = v6 * v10;
    v13 = v7.m128_f32[0] * v10;
    v14 = v8;
    v14.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v11 * v11);
    if ( v14.m128_f32[0] == 0.0 )
      v15 = 0.0;
    else
      v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
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
    v18 = v5 / COERCE_FLOAT(_mm_sqrt_ps(v17));
    goto LABEL_17;
  }
  if ( v3 != 1 )
    return;
  v19 = v1->m_navComponent->m_pSimObject;
  if ( v19 )
    v20 = v19->m_pTransformNodeComponent;
  else
    v20 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v20);
  v18 = 0.0;
  v21 = v1->m_pPath.m_pNavPath->m_aWaypoints.p;
  v8 = (__m128)LODWORD(v21->m_navPosition.m_vPosition.y);
  v16 = v21->m_navPosition.m_vPosition.x - v20->mWorldTransform.v3.x;
  v8.m128_f32[0] = v8.m128_f32[0] - v20->mWorldTransform.v3.y;
  v17 = v8;
  v17.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v16 * v16);
  if ( v17.m128_f32[0] != 0.0 )
  {
    v5 = *(float *)&FLOAT_1_0;
    goto LABEL_16;
  }
LABEL_17:
  v1->m_vHalfSpaceNormal.y = v8.m128_f32[0] * v18;
  v1->m_vHalfSpaceNormal.x = v16 * v18;
}

