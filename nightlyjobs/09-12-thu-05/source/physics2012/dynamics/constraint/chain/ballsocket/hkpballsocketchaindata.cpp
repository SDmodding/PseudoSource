// File Line: 31
// RVA: 0xD752C0
void __fastcall hkpBallSocketChainData::hkpBallSocketChainData(hkpBallSocketChainData *this)
{
  hkpBridgeAtoms *p_m_atoms; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  p_m_atoms = &this->m_atoms;
  *(_QWORD *)&p_m_atoms[-1].m_bridgeAtom.m_type.m_storage = &hkpBallSocketChainData::`vftable;
  p_m_atoms->m_bridgeAtom.m_type.m_storage = 1;
  this->m_infos.m_data = 0i64;
  this->m_infos.m_size = 0;
  this->m_infos.m_capacityAndFlags = 0x80000000;
  this->m_useStabilizedCode = 0;
  this->m_tau = 0.60000002;
  this->m_damping = 1.0;
  this->m_cfm = 0.000000011920929;
  this->m_maxErrorDistance = 0.1;
  hkpBridgeConstraintAtom::init(&p_m_atoms->m_bridgeAtom, this);
}

// File Line: 38
// RVA: 0xD75CF0
void __fastcall hkpBallSocketChainData::hkpBallSocketChainData(
        hkpBallSocketChainData *this,
        hkFinishLoadedObjectFlag f)
{
  hkpConstraintData::hkpConstraintData(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkpBallSocketChainData::`vftable;
  if ( f.m_finishing )
  {
    hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this->m_atoms.m_bridgeAtom.m_constraintData);
    if ( f.m_finishing )
      hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this);
  }
}

// File Line: 47
// RVA: 0xD75340
void __fastcall hkpBallSocketChainData::~hkpBallSocketChainData(hkpBallSocketChainData *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpBallSocketChainData::`vftable;
  m_capacityAndFlags = this->m_infos.m_capacityAndFlags;
  this->m_infos.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_infos.m_data,
      32 * m_capacityAndFlags);
  this->m_infos.m_data = 0i64;
  this->m_infos.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 52
// RVA: 0xD753B0
__int64 __fastcall hkpBallSocketChainData::getType(hkpBallSocketChainData *this)
{
  return 101i64;
}

// File Line: 57
// RVA: 0xD753C0
void __fastcall hkpBallSocketChainData::addConstraintInfoInBodySpace(
        hkpBallSocketChainData *this,
        hkVector4f *pivotInA,
        hkVector4f *pivotInB)
{
  hkArray<hkpBallSocketChainData::ConstraintInfo,hkContainerHeapAllocator> *p_m_infos; // rbx
  hkVector4f *p_m_pivotInA; // rcx

  p_m_infos = &this->m_infos;
  if ( this->m_infos.m_size == (this->m_infos.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_infos->m_data, 32);
  p_m_pivotInA = &p_m_infos->m_data[p_m_infos->m_size++].m_pivotInA;
  *p_m_pivotInA = (hkVector4f)pivotInA->m_quad;
  p_m_pivotInA[1] = (hkVector4f)pivotInB->m_quad;
}

// File Line: 64
// RVA: 0xD75440
void __fastcall hkpBallSocketChainData::useStabilizedCode(hkpBallSocketChainData *this, bool useIt)
{
  this->m_useStabilizedCode = useIt;
}

// File Line: 72
// RVA: 0xD75C60
void __fastcall hkpBallSocketChainData::getConstraintInfo(
        hkpBallSocketChainData *this,
        hkpConstraintData::ConstraintInfo *info)
{
  int m_size; // eax

  info->m_sizeOfSchemas = 32;
  info->m_atoms = &this->m_atoms.m_bridgeAtom;
  info->m_sizeOfAllAtoms = 32;
  *(_QWORD *)&info->m_numSolverResults = 0i64;
  info->m_maxSizeOfSchema = 0;
  m_size = this->m_infos.m_size;
  info->m_numSolverResults = 3 * m_size;
  info->m_numSolverElemTemps = 3 * m_size;
  info->m_sizeOfSchemas = ((288 * m_size + 20 * m_size + 67) & 0xFFFFFFF0) + 32;
}

// File Line: 94
// RVA: 0xD75CC0
void __fastcall hkpBallSocketChainData::getRuntimeInfo(
        hkpBallSocketChainData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  int v3; // eax

  if ( wantRuntime.m_bool )
  {
    v3 = 3 * this->m_infos.m_size;
    infoOut->m_numSolverResults = v3;
    infoOut->m_sizeOfExternalRuntime = 8 * v3;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 117
// RVA: 0xD75450
void __fastcall hkpBallSocketChainData::buildJacobian(
        hkpBallSocketChainData *this,
        hkpConstraintQueryIn *inChain,
        hkpConstraintQueryOut *out)
{
  if ( this->m_useStabilizedCode )
    hkpBallSocketChainData::buildJacobian_Stabilized(this, inChain, out);
  else
    hkpBallSocketChainData::buildJacobian_Unstabilized(this, inChain, out);
}

// File Line: 129
// RVA: 0xD75470
void __fastcall hkpBallSocketChainData::buildJacobian_Unstabilized(
        hkpBallSocketChainData *this,
        hkpConstraintQueryIn *inChain,
        hkpConstraintQueryOut *out)
{
  hkpConstraintQueryOut *v3; // rbx
  hkpConstraintQueryIn *v4; // r14
  __int64 v6; // r15
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  hkSimdFloat32 v11; // xmm0
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  hkpConstraintInstance *m_storage; // r13
  hkBaseObjectVtbl *vfptr; // rax
  int v17; // esi
  void *(__fastcall *vecDelDtor)(hkBaseObject *, unsigned int); // rcx
  __int64 v19; // rax
  hkpVelocityAccumulator *accumBase; // rdi
  hkTransformf *v21; // rax
  hkpJacobianSchema *v22; // rcx
  hkp1Lin2AngJacobian *jacobiansEnd; // rax
  __int64 v24; // r10
  hkp1Lin2AngJacobian *v25; // r14
  hkTransformf *v26; // rcx
  int v27; // r8d
  __int64 v28; // rsi
  int v29; // ebx
  unsigned int v30; // ebx
  hkpVelocityAccumulatorOffset *v31; // r9
  hkpBallSocketChainData::ConstraintInfo *m_data; // rdx
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  hkVector4f posB; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v36; // [rsp+60h] [rbp-A0h]
  hkpConstraintQueryIn in; // [rsp+70h] [rbp-90h] BYREF
  hkVector4f posA; // [rsp+100h] [rbp+0h] BYREF
  hkpVelocityAccumulatorOffset *array; // [rsp+110h] [rbp+10h] BYREF
  int v40; // [rsp+118h] [rbp+18h]
  int v41; // [rsp+11Ch] [rbp+1Ch]
  int v42; // [rsp+120h] [rbp+20h] BYREF
  int v43; // [rsp+1F0h] [rbp+F0h]
  __int64 v46; // [rsp+208h] [rbp+108h]

  v3 = out;
  v4 = inChain;
  v4->m_beginConstraints(v4, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  v41 = -2147483616;
  v6 = 0i64;
  v7 = *(_OWORD *)&v4->m_subStepDeltaTime.m_storage;
  v8 = *(_OWORD *)&v4->m_frameInvDeltaTime.m_storage;
  v40 = 0;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v7;
  v9 = *(_OWORD *)&v4->m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v8;
  array = (hkpVelocityAccumulatorOffset *)&v42;
  v10 = *(_OWORD *)&v4->m_bodyA.m_storage;
  *(_OWORD *)&in.m_rhsFactor.m_storage = v9;
  *(_OWORD *)&in.m_transformA.m_storage = *(_OWORD *)&v4->m_transformA.m_storage;
  v11.m_real = (__m128)v4->m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_bodyA.m_storage = v10;
  v12 = *(_OWORD *)&v4->m_tau.m_storage;
  in.m_maxConstraintViolationSqrd = (hkSimdFloat32)v11.m_real;
  v13 = *(_OWORD *)&v4->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&in.m_tau.m_storage = v12;
  v14 = *(_OWORD *)&v4->m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = v13;
  v3->m_constraintRuntime.m_storage = 0i64;
  m_storage = v4->m_constraintInstance.m_storage;
  in.m_violatedConstraints.m_storage = (hkpViolatedConstraintArray *)*((_QWORD *)&v14 + 1);
  in.m_constraintInstance.m_storage = 0i64;
  vfptr = m_storage[1].vfptr;
  v17 = *(_DWORD *)&m_storage[1].m_memSizeAndFlags - 1;
  v43 = v17;
  vecDelDtor = vfptr->__vecDelDtor;
  v19 = *((unsigned int *)vfptr->__vecDelDtor + 60);
  accumBase = (hkpVelocityAccumulator *)((char *)v4->m_bodyA.m_storage - m_storage->m_entities[0]->m_solverData);
  v40 = 1;
  LODWORD(in.m_virtMassFactor.m_storage) = (_DWORD)FLOAT_1_0;
  in.m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)accumBase + v19);
  v42 = v19;
  v21 = (hkTransformf *)((char *)vecDelDtor + 368);
  v22 = v3->m_jacobianSchemas.m_storage;
  in.m_transformB.m_storage = v21;
  in.m_rhsFactor.m_storage = in.m_subStepInvDeltaTime.m_storage;
  jacobiansEnd = hkJacobianBallSocketChainSchema_getJacobians(v22);
  v36 = v17;
  if ( v17 > 0 )
  {
    v24 = 0i64;
    v25 = jacobiansEnd;
    v46 = 0i64;
    do
    {
      v26 = in.m_transformB.m_storage;
      v27 = v40;
      in.m_bodyA.m_storage = in.m_bodyB.m_storage;
      in.m_transformA.m_storage = in.m_transformB.m_storage;
      v28 = *((_QWORD *)&m_storage[1].vfptr->__first_virtual_table_function__ + v6);
      v29 = (_DWORD)accumBase + *(_DWORD *)(v28 + 240);
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)accumBase + *(unsigned int *)(v28 + 240));
      v30 = v29 - (_DWORD)accumBase;
      if ( v40 == (v41 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 4);
        v26 = in.m_transformA.m_storage;
        v27 = v40;
        v24 = v46;
      }
      v31 = &array[v27];
      if ( v31 )
      {
        v31->m_offset = v30;
        v26 = in.m_transformA.m_storage;
        v27 = v40;
      }
      m_data = this->m_infos.m_data;
      v40 = v27 + 1;
      in.m_transformB.m_storage = (hkTransformf *)(v28 + 368);
      v33 = *(__m128 *)((char *)&m_data->m_pivotInA.m_quad + v24);
      posA.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v26->m_rotation.m_col1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v26->m_rotation.m_col0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v26->m_rotation.m_col2.m_quad)),
                      v26->m_translation.m_quad);
      v34 = *(__m128 *)((char *)&m_data->m_pivotInB.m_quad + v24);
      posB.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), *(__m128 *)(v28 + 384)),
                          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), *(__m128 *)(v28 + 368))),
                        _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), *(__m128 *)(v28 + 400))),
                      *(__m128 *)(v28 + 416));
      hkBallSocketConstraintBuildJacobian_noSchema_Proj(&posA, &posB, &in, v25);
      v24 = v46 + 32;
      ++v6;
      v25 += 3;
      v46 += 32i64;
    }
    while ( v6 < v36 );
    v3 = out;
    v17 = v43;
    posB.m_quad.m128_u64[0] = (unsigned __int64)v25;
    v4 = inChain;
    jacobiansEnd = (hkp1Lin2AngJacobian *)posB.m_quad.m128_u64[0];
  }
  hkBallSocketChainBuildJacobian(v17, this->m_tau, this->m_damping, this->m_cfm, array, accumBase, jacobiansEnd, v4, v3);
  v40 = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v41);
}

// File Line: 241
// RVA: 0xD75790
void __fastcall hkpBallSocketChainData::buildJacobian_Stabilized(
        hkpBallSocketChainData *this,
        hkpConstraintQueryIn *inChain,
        hkpConstraintQueryIn *out)
{
  hkpConstraintQueryIn *v3; // rbx
  hkpConstraintQueryIn *v4; // rsi
  __int64 v6; // r12
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  hkSimdFloat32 v11; // xmm0
  __int128 v12; // xmm1
  __int128 cfm; // xmm0
  __int128 damping; // xmm1
  hkpConstraintInstance *m_storage; // r13
  float m_tau; // xmm3_4
  hkBaseObjectVtbl *vfptr; // rax
  int v18; // r14d
  void *(__fastcall *vecDelDtor)(hkBaseObject *, unsigned int); // rcx
  __int64 v20; // rax
  hkpVelocityAccumulator *v21; // rdi
  hkTransformf *v22; // rax
  hkpJacobianSchema *v23; // rcx
  hkpJacobianSchema *v24; // rax
  __int64 v25; // rsi
  hkTransformf *v26; // rcx
  int v27; // r8d
  __int64 v28; // r14
  int v29; // ebx
  unsigned int v30; // ebx
  hkpVelocityAccumulatorOffset *v31; // r9
  hkpBallSocketChainData::ConstraintInfo *m_data; // rdx
  hkVector4f v33; // xmm1
  hkVector4f v34; // xmm0
  hkVector4f v35; // xmm1
  __m128 m_quad; // xmm1
  __m128 v37; // xmm1
  float virtualMassFactor; // [rsp+30h] [rbp-C8h]
  hkpBallSocketConstraintAtom v39; // [rsp+50h] [rbp-A8h] BYREF
  hkpSetupStabilizationAtom atom; // [rsp+60h] [rbp-98h] BYREF
  hkpConstraintQueryOut outa; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f vLocalArmB; // [rsp+88h] [rbp-70h] BYREF
  hkSimdFloat32 maxAngularImpulse; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f vLocalArmA; // [rsp+A8h] [rbp-50h] BYREF
  hkpConstraintQueryIn in; // [rsp+B8h] [rbp-40h] BYREF
  hkSimdFloat32 maxLinearImpulse; // [rsp+148h] [rbp+50h] BYREF
  hkpVelocityAccumulatorOffset *array; // [rsp+158h] [rbp+60h] BYREF
  int v48; // [rsp+160h] [rbp+68h]
  int v49; // [rsp+164h] [rbp+6Ch]
  hkpVelocityAccumulatorOffset accumulatorsIn; // [rsp+168h] [rbp+70h] BYREF
  hkTransformf baseB; // [rsp+1E8h] [rbp+F0h] BYREF
  hkTransformf baseA; // [rsp+228h] [rbp+130h] BYREF
  void *retaddr; // [rsp+2C8h] [rbp+1D0h] BYREF
  hkpConstraintQueryIn *v54; // [rsp+2D0h] [rbp+1D8h]
  int v56; // [rsp+2E0h] [rbp+1E8h]

  v3 = out;
  v4 = inChain;
  inChain->m_beginConstraints(
    inChain,
    (hkpConstraintQueryOut *)out,
    *(hkpSolverResults **)&out->m_subStepInvDeltaTime.m_storage,
    8);
  v49 = -2147483616;
  v6 = 0i64;
  v7 = *(_OWORD *)&v4->m_subStepDeltaTime.m_storage;
  v8 = *(_OWORD *)&v4->m_frameInvDeltaTime.m_storage;
  v48 = 0;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v7;
  v9 = *(_OWORD *)&v4->m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v8;
  array = &accumulatorsIn;
  v10 = *(_OWORD *)&v4->m_bodyA.m_storage;
  *(_OWORD *)&in.m_rhsFactor.m_storage = v9;
  *(_OWORD *)&in.m_transformA.m_storage = *(_OWORD *)&v4->m_transformA.m_storage;
  v11.m_real = (__m128)v4->m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_bodyA.m_storage = v10;
  v12 = *(_OWORD *)&v4->m_tau.m_storage;
  in.m_maxConstraintViolationSqrd = (hkSimdFloat32)v11.m_real;
  cfm = *(_OWORD *)&v4->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&in.m_tau.m_storage = v12;
  damping = *(_OWORD *)&v4->m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = cfm;
  *(_QWORD *)&v3->m_subStepInvDeltaTime.m_storage = 0i64;
  m_storage = v4->m_constraintInstance.m_storage;
  m_tau = this->m_tau;
  virtualMassFactor = v4->m_virtMassFactor.m_storage;
  *(float *)&cfm = this->m_cfm;
  *(_OWORD *)&in.m_constraintInstance.m_storage = damping;
  *(float *)&damping = this->m_damping;
  in.m_constraintInstance.m_storage = 0i64;
  vfptr = m_storage[1].vfptr;
  v18 = *(_DWORD *)&m_storage[1].m_memSizeAndFlags - 1;
  v56 = v18;
  vecDelDtor = vfptr->__vecDelDtor;
  v20 = *((unsigned int *)vfptr->__vecDelDtor + 60);
  v21 = (hkpVelocityAccumulator *)((char *)v4->m_bodyA.m_storage - m_storage->m_entities[0]->m_solverData);
  v48 = 1;
  in.m_virtMassFactor.m_storage = 1.0;
  outa.m_constraintRuntime.m_storage = 0i64;
  in.m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v21 + v20);
  accumulatorsIn.m_offset = v20;
  v22 = (hkTransformf *)((char *)vecDelDtor + 368);
  v23 = *(hkpJacobianSchema **)&v3->m_subStepDeltaTime.m_storage;
  in.m_transformB.m_storage = v22;
  in.m_rhsFactor.m_storage = in.m_subStepInvDeltaTime.m_storage;
  outa.m_jacobianSchemas.m_storage = *(hkpJacobianSchema **)&v3->m_subStepDeltaTime.m_storage;
  outa.m_constraintRuntime.m_storage = *(struct hkpConstraintRuntime **)&v3->m_frameInvDeltaTime.m_storage;
  v24 = hkJacobianStabilizedBallSocketChainSchema_init(
          v23,
          v18,
          &accumulatorsIn,
          m_tau,
          *(float *)&damping,
          *(float *)&cfm,
          virtualMassFactor);
  outa.m_jacobianSchemas.m_storage = v24;
  outa.m_constraintRuntimeInMainMemory.m_storage = (void *)v18;
  if ( v18 > 0 )
  {
    v25 = 0i64;
    do
    {
      v26 = in.m_transformB.m_storage;
      v27 = v48;
      in.m_bodyA.m_storage = in.m_bodyB.m_storage;
      in.m_transformA.m_storage = in.m_transformB.m_storage;
      v28 = *((_QWORD *)&m_storage[1].vfptr->__first_virtual_table_function__ + v6);
      v29 = (_DWORD)v21 + *(_DWORD *)(v28 + 240);
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v21 + *(unsigned int *)(v28 + 240));
      v30 = v29 - (_DWORD)v21;
      if ( v48 == (v49 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 4);
        v26 = in.m_transformA.m_storage;
        v27 = v48;
      }
      v31 = &array[v27];
      if ( v31 )
      {
        v31->m_offset = v30;
        v26 = in.m_transformA.m_storage;
        v27 = v48;
      }
      m_data = this->m_infos.m_data;
      v48 = v27 + 1;
      in.m_transformB.m_storage = (hkTransformf *)(v28 + 368);
      atom.m_type.m_storage = 23;
      baseA.m_rotation.m_col0 = v26->m_rotation.m_col0;
      v33.m_quad = (__m128)v26->m_rotation.m_col1;
      atom.m_maxLinImpulse = 3.40282e38;
      atom.m_maxAngImpulse = 3.40282e38;
      atom.m_maxAngle = 1.8446726e19;
      baseA.m_rotation.m_col1 = (hkVector4f)v33.m_quad;
      v34.m_quad = (__m128)v26->m_rotation.m_col2;
      atom.m_enabled.m_bool = 1;
      *(_DWORD *)&v39.m_type.m_storage = 65541;
      LODWORD(retaddr) = 1065353216;
      baseA.m_rotation.m_col2 = (hkVector4f)v34.m_quad;
      baseA.m_translation = v26->m_translation;
      baseB.m_rotation.m_col0 = *(hkVector4f *)(v28 + 368);
      baseB.m_rotation.m_col1 = *(hkVector4f *)(v28 + 384);
      baseB.m_rotation.m_col2 = *(hkVector4f *)(v28 + 400);
      v35.m_quad = *(__m128 *)(v28 + 416);
      maxAngularImpulse.m_real = (__m128)xmmword_141A712A0;
      maxLinearImpulse.m_real = (__m128)xmmword_141A712A0;
      baseB.m_translation = (hkVector4f)v35.m_quad;
      vLocalArmA.m_quad = 0i64;
      vLocalArmB.m_quad = 0i64;
      m_quad = m_data[v25].m_pivotInA.m_quad;
      baseA.m_translation.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v26->m_rotation.m_col1.m_quad),
                                         _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v26->m_rotation.m_col0.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v26->m_rotation.m_col2.m_quad)),
                                     v26->m_translation.m_quad);
      v37 = m_data[v25].m_pivotInB.m_quad;
      baseB.m_translation.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), *(__m128 *)(v28 + 384)),
                                         _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), *(__m128 *)(v28 + 368))),
                                       _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), *(__m128 *)(v28 + 400))),
                                     *(__m128 *)(v28 + 416));
      hkUFloat8::operator=(&v39.m_velocityStabilizationFactor, (const float *)&retaddr);
      v39.m_enableLinearImpulseLimit.m_bool = 0;
      *(_QWORD *)&v39.m_breachImpulse = 2139095022i64;
      v39.m_solvingMethod.m_storage = 0;
      setupStabilizationFromAtom_outOfLine(
        &atom,
        &in,
        &baseA,
        &baseB,
        &vLocalArmA,
        &vLocalArmB,
        &maxAngularImpulse,
        &maxLinearImpulse,
        &outa);
      buildSchemaFromBallSocketAtom(
        &v39,
        &in,
        &baseA,
        &baseB,
        &vLocalArmA,
        &vLocalArmB,
        &maxAngularImpulse,
        &maxLinearImpulse,
        &outa);
      ++v6;
      ++v25;
    }
    while ( v6 < (__int64)outa.m_constraintRuntimeInMainMemory.m_storage );
    v24 = outa.m_jacobianSchemas.m_storage;
    v4 = v54;
    v3 = inChain;
    v18 = v56;
  }
  hkStabilizedBallSocketChainBuildJacobian(
    v18,
    this->m_tau,
    this->m_damping,
    this->m_cfm,
    array,
    v21,
    (hkpChainLinkData *)v24,
    v4,
    (hkpConstraintQueryOut *)v3);
  v48 = 0;
  if ( v49 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v49);
}

