// File Line: 37
// RVA: 0xD7B450
void __fastcall hkpPoweredChainData::hkpPoweredChainData(hkpPoweredChainData *this)
{
  hkpBridgeAtoms *p_m_atoms; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  p_m_atoms = &this->m_atoms;
  *(_QWORD *)&p_m_atoms[-1].m_bridgeAtom.m_type.m_storage = &hkpPoweredChainData::`vftable;
  p_m_atoms->m_bridgeAtom.m_type.m_storage = 1;
  this->m_infos.m_data = 0i64;
  this->m_infos.m_size = 0;
  this->m_infos.m_capacityAndFlags = 0x80000000;
  this->m_tau = 0.60000002;
  this->m_damping = 1.0;
  this->m_cfmLinAdd = 0.000000011920929;
  this->m_cfmLinMul = 1.0;
  this->m_cfmAngAdd = 0.000000011920929;
  this->m_cfmAngMul = 1.0;
  this->m_maxErrorDistance = 0.1;
  hkpBridgeConstraintAtom::init(&p_m_atoms->m_bridgeAtom, this);
}

// File Line: 49
// RVA: 0xD7C1A0
void __fastcall hkpPoweredChainData::hkpPoweredChainData(hkpPoweredChainData *this, hkFinishLoadedObjectFlag f)
{
  hkpConstraintData::hkpConstraintData(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkpPoweredChainData::`vftable;
  if ( f.m_finishing )
  {
    hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this->m_atoms.m_bridgeAtom.m_constraintData);
    if ( f.m_finishing )
      hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this);
  }
}

// File Line: 58
// RVA: 0xD7B4E0
void __fastcall hkpPoweredChainData::~hkpPoweredChainData(hkpPoweredChainData *this)
{
  int v1; // ebp
  __int64 v3; // r14
  __int64 v4; // rbx
  __int64 v5; // rdi
  hkReferencedObject *v6; // rcx
  int m_capacityAndFlags; // eax

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPoweredChainData::`vftable;
  if ( this->m_infos.m_size > 0 )
  {
    v3 = 64i64;
    do
    {
      v4 = v3;
      v5 = 3i64;
      do
      {
        v6 = *(hkReferencedObject **)((char *)this->m_infos.m_data->m_pivotInA.m_quad.m128_u64 + v4);
        if ( v6 )
          hkReferencedObject::removeReference(v6);
        v4 += 8i64;
        --v5;
      }
      while ( v5 );
      ++v1;
      v3 += 96i64;
    }
    while ( v1 < this->m_infos.m_size );
  }
  m_capacityAndFlags = this->m_infos.m_capacityAndFlags;
  this->m_infos.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_infos.m_data,
      96 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_infos.m_data = 0i64;
  this->m_infos.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 73
// RVA: 0xD7B5C0
__int64 __fastcall hkpPoweredChainData::getType(hkpPoweredChainData *this)
{
  return 102i64;
}

// File Line: 79
// RVA: 0xD7B5D0
void __fastcall hkpPoweredChainData::addConstraintInfoInBodySpace(
        hkpPoweredChainData *this,
        hkVector4f *pivotInA,
        hkVector4f *pivotInB,
        hkQuaternionf *aTc,
        hkpConstraintMotor *xMotor,
        hkpConstraintMotor *yMotor,
        hkpConstraintMotor *zMotor)
{
  hkArray<hkpPoweredChainData::ConstraintInfo,hkContainerHeapAllocator> *p_m_infos; // rdi
  __int64 m_size; // rcx
  hkQuaternionf *v12; // rbx

  p_m_infos = &this->m_infos;
  if ( this->m_infos.m_size == (this->m_infos.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_infos->m_data, 96);
  m_size = p_m_infos->m_size;
  p_m_infos->m_size = m_size + 1;
  v12 = (hkQuaternionf *)&p_m_infos->m_data[m_size];
  *v12 = (hkQuaternionf)pivotInA->m_quad;
  v12[1] = (hkQuaternionf)pivotInB->m_quad;
  v12[2] = (hkQuaternionf)aTc->m_vec.m_quad;
  v12[4].m_vec.m_quad.m128_u64[0] = (unsigned __int64)xMotor;
  hkReferencedObject::addReference(xMotor);
  v12[4].m_vec.m_quad.m128_u64[1] = (unsigned __int64)yMotor;
  hkReferencedObject::addReference(yMotor);
  v12[5].m_vec.m_quad.m128_u64[0] = (unsigned __int64)zMotor;
  hkReferencedObject::addReference(zMotor);
  v12[5].m_vec.m_quad.m128_i8[8] = 0;
  v12[3] = (hkQuaternionf)qi.m_vec.m_quad;
}

// File Line: 101
// RVA: 0xD7C100
void __fastcall hkpPoweredChainData::getConstraintInfo(
        hkpPoweredChainData *this,
        hkpConstraintData::ConstraintInfo *info)
{
  int m_size; // r8d

  info->m_sizeOfSchemas = 32;
  info->m_atoms = &this->m_atoms.m_bridgeAtom;
  info->m_sizeOfAllAtoms = 32;
  *(_QWORD *)&info->m_numSolverResults = 0i64;
  info->m_maxSizeOfSchema = 0;
  m_size = this->m_infos.m_size;
  info->m_numSolverResults = 6 * m_size;
  info->m_numSolverElemTemps = 6 * m_size;
  info->m_sizeOfSchemas = ((240 * m_size + 36 * (m_size + 1) + 1056 * m_size + 47) & 0xFFFFFFF0) + 32;
}

// File Line: 126
// RVA: 0xD7C170
void __fastcall hkpPoweredChainData::getRuntimeInfo(
        hkpPoweredChainData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  int m_size; // edx

  m_size = this->m_infos.m_size;
  infoOut->m_numSolverResults = 6 * m_size;
  infoOut->m_sizeOfExternalRuntime = ((m_size + 3) & 0xFFFFFFFC) + (m_size << 6);
}

// File Line: 139
// RVA: 0xD7B6A0
void __fastcall hkpPoweredChainData::enableMotor(
        hkpConstraintChainInstance *instance,
        int constraintIndex,
        char motorIndex)
{
  char *v3; // r10

  v3 = (char *)instance->m_internal->m_runtime + 48 * LODWORD(instance->m_data[3].vfptr);
  v3[constraintIndex] &= ~(3 << (2 * motorIndex));
}

// File Line: 154
// RVA: 0xD7B6F0
void __fastcall hkpPoweredChainData::disableMotor(
        hkpConstraintChainInstance *instance,
        int constraintIndex,
        char motorIndex)
{
  char *v3; // r10

  v3 = (char *)instance->m_internal->m_runtime + 48 * LODWORD(instance->m_data[3].vfptr);
  v3[constraintIndex] = (2 << (2 * motorIndex)) | v3[constraintIndex] & ~(3 << (2 * motorIndex));
}

// File Line: 172
// RVA: 0xD7C200
void __fastcall estimateAngleToLs(hkQuaternionf *from, hkQuaternionf *to, hkVector4f *angleOut)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm3
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm1

  v3 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(to->m_vec.m_quad, to->m_vec.m_quad, 201), from->m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(from->m_vec.m_quad, from->m_vec.m_quad, 201), to->m_vec.m_quad));
  v4 = _mm_shuffle_ps(v3, v3, 201);
  *angleOut = (hkVector4f)v4;
  v5 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(to->m_vec.m_quad, to->m_vec.m_quad, 255), from->m_vec.m_quad), v4);
  *angleOut = (hkVector4f)v5;
  v6 = _mm_sub_ps(v5, _mm_mul_ps(_mm_shuffle_ps(from->m_vec.m_quad, from->m_vec.m_quad, 255), to->m_vec.m_quad));
  v7 = _mm_add_ps(v6, v6);
  *angleOut = (hkVector4f)v7;
  v8 = _mm_mul_ps(from->m_vec.m_quad, to->m_vec.m_quad);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  angleOut->m_quad = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9), 0x1Fu),
                                 0x1Fu),
                       v7);
}

// File Line: 181
// RVA: 0xD7C280
void __fastcall hk1dAngularVelocityMotorCommitJacobianInMotorInfo(
        hkp1dConstraintMotorInfo *info,
        hkpConstraintQueryIn *in,
        hkp2AngJacobian *jac,
        hkp1dMotorSolverInfo *motorInfoOut)
{
  motorInfoOut->m_maxImpulsePerSubstep = info->m_maxForce.m_storage * in->m_microStepDeltaTime.m_storage;
  motorInfoOut->m_minImpulsePerSubstep = info->m_minForce.m_storage * in->m_microStepDeltaTime.m_storage;
  motorInfoOut->m_velocity = info->m_targetVelocity.m_storage;
  motorInfoOut->m_tau = info->m_tau.m_storage;
  motorInfoOut->m_damping = info->m_damping.m_storage;
  jac->m_angular[1].m_quad.m128_f32[3] = in->m_subStepInvDeltaTime.m_storage * info->m_targetPosition.m_storage;
}

// File Line: 201
// RVA: 0xD7B740
void __fastcall hkpPoweredChainData::buildJacobian(
        hkpPoweredChainData *this,
        hkpConstraintQueryOut *inNotValid,
        hkpConstraintQueryOut *out)
{
  hkpConstraintQueryIn *v4; // rsi
  struct hkpConstraintRuntime *m_storage; // rax
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  char *v9; // r8
  __int128 v10; // xmm0
  int v11; // edx
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  hkSimdFloat32 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  hkpConstraintInstance *v18; // rbx
  int v19; // ecx
  int v20; // r13d
  hkpVelocityAccumulator *v21; // r15
  int v22; // r9d
  void *(__fastcall *vecDelDtor)(hkBaseObject *, unsigned int); // r10
  char *v24; // r9
  hkpJacobianSchema *v25; // rcx
  hkp1Lin2AngJacobian *LinearJacobians; // rax
  hkpJacobianSchema *v27; // rcx
  hkp2AngJacobian *AngularJacobians; // rax
  __int64 v29; // rdi
  __int64 v30; // r9
  hkp2AngJacobian *v31; // r12
  __int64 v32; // rsi
  hkTransformf *v33; // rcx
  int v34; // r8d
  __int64 v35; // r13
  int v36; // ebx
  unsigned int v37; // ebx
  hkpVelocityAccumulatorOffset *v38; // r9
  hkpPoweredChainData::ConstraintInfo *m_data; // rdx
  hkp1Lin2AngJacobian *v40; // rbx
  __m128 v41; // xmm1
  __m128 v42; // xmm1
  hkpPoweredChainData::ConstraintInfo *v43; // r8
  __m128 m_quad; // xmm6
  __m128 v45; // xmm9
  __m128 v46; // xmm2
  __int64 m_size; // rdx
  __m128 v48; // xmm4
  __int64 v49; // r9
  __m128 v50; // xmm5
  unsigned __int64 v51; // rax
  __m128 v52; // xmm3
  __m128 v53; // xmm1
  __m128 v54; // xmm6
  __m128 v55; // xmm3
  __m128 v56; // xmm10
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm5
  __m128 v61; // xmm4
  __m128 v62; // xmm3
  __m128 v63; // xmm8
  __m128 v64; // xmm7
  __m128 v65; // xmm8
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  __m128 v68; // xmm8
  __m128 v69; // xmm1
  __m128 v70; // xmm9
  __m128 v71; // xmm7
  __m128 v72; // xmm7
  __m128 v73; // xmm3
  __m128 v74; // xmm7
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  bool v77; // zf
  __m128 v78; // xmm6
  __m128 v79; // xmm3
  __m128 v80; // xmm1
  __m128 v81; // xmm8
  __m128 v82; // xmm0
  __m128 v83; // xmm7
  __m128 v84; // xmm4
  __m128 v85; // xmm1
  __m128 v86; // xmm0
  __m128 v87; // xmm3
  __m128 v88; // xmm2
  __m128 v89; // xmm0
  __int64 v90; // rdi
  __int64 v91; // r15
  __int64 v92; // rsi
  __m128 *v93; // r13
  hkBaseObjectVtbl *vfptr; // r8
  hkConstraintInternal *m_internal; // rax
  __int64 v96; // rax
  __int64 v97; // rbx
  float v98; // xmm1_4
  hkpPoweredChainData::ConstraintInfo *v99; // rcx
  hkp3dAngularMotorSolverInfo *v100; // rax
  char *v101; // r10
  __int64 v102; // rdx
  __int64 v103; // r8
  char v104; // cl
  float m_tau; // xmm0_4
  float m_damping; // xmm1_4
  float m_cfmLinAdd; // xmm0_4
  float m_cfmLinMul; // xmm1_4
  float m_cfmAngAdd; // xmm0_4
  float m_cfmAngMul; // xmm1_4
  hkpConstraintInstance *v111; // [rsp+30h] [rbp-C8h]
  __int64 v112; // [rsp+38h] [rbp-C0h]
  hkQuaternionf qi; // [rsp+40h] [rbp-B8h] BYREF
  __int64 v114; // [rsp+50h] [rbp-A8h]
  hkpVelocityAccumulator *v115; // [rsp+58h] [rbp-A0h]
  hkp1Lin2AngJacobian *jac; // [rsp+60h] [rbp-98h]
  __int64 v117; // [rsp+68h] [rbp-90h]
  hkpConstraintMotorOutput output; // [rsp+70h] [rbp-88h] BYREF
  hkQuaternionf v119; // [rsp+88h] [rbp-70h] BYREF
  hkpConstraintMotorInput statusOut; // [rsp+98h] [rbp-60h] BYREF
  hkpConstraintQueryIn in; // [rsp+B8h] [rbp-40h] BYREF
  hkpPoweredChainBuildJacobianParams v122; // [rsp+148h] [rbp+50h] BYREF
  __m128 v123; // [rsp+198h] [rbp+A0h]
  __m128 v124; // [rsp+1A8h] [rbp+B0h]
  hkpVelocityAccumulatorOffset *v125; // [rsp+1B8h] [rbp+C0h] BYREF
  int v126; // [rsp+1C0h] [rbp+C8h]
  int v127; // [rsp+1C4h] [rbp+CCh]
  char v128[128]; // [rsp+1C8h] [rbp+D0h] BYREF
  hkVector4f posA; // [rsp+248h] [rbp+150h] BYREF
  hkVector4f posB; // [rsp+258h] [rbp+160h] BYREF
  hkVector4f directionOfConstraint; // [rsp+268h] [rbp+170h] BYREF
  hkp3dAngularMotorSolverInfo *array; // [rsp+278h] [rbp+180h] BYREF
  int v133; // [rsp+280h] [rbp+188h]
  int v134; // [rsp+284h] [rbp+18Ch]
  char v135; // [rsp+288h] [rbp+190h] BYREF
  void *retaddr; // [rsp+B38h] [rbp+A40h] BYREF
  hkpConstraintQueryIn *v137; // [rsp+B40h] [rbp+A48h]
  int v139; // [rsp+B50h] [rbp+A58h]

  v4 = (hkpConstraintQueryIn *)inNotValid;
  v4->m_beginConstraints(v4, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  m_storage = out->m_constraintRuntime.m_storage;
  v7 = *(_OWORD *)&v4->m_subStepDeltaTime.m_storage;
  v8 = *(_OWORD *)&v4->m_frameInvDeltaTime.m_storage;
  v127 = -2147483616;
  *(_QWORD *)&output.m_tau.m_storage = m_storage;
  v9 = v128;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v7;
  v10 = *(_OWORD *)&v4->m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v8;
  v125 = (hkpVelocityAccumulatorOffset *)v128;
  v11 = 0;
  v12 = *(_OWORD *)&v4->m_bodyA.m_storage;
  *(_OWORD *)&in.m_rhsFactor.m_storage = v10;
  v13 = *(_OWORD *)&v4->m_transformA.m_storage;
  v126 = 0;
  *(_OWORD *)&in.m_transformA.m_storage = v13;
  v14.m_real = (__m128)v4->m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_bodyA.m_storage = v12;
  v15 = *(_OWORD *)&v4->m_tau.m_storage;
  in.m_maxConstraintViolationSqrd = (hkSimdFloat32)v14.m_real;
  v16 = *(_OWORD *)&v4->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&in.m_tau.m_storage = v15;
  v17 = *(_OWORD *)&v4->m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = v16;
  out->m_constraintRuntime.m_storage = 0i64;
  v18 = v4->m_constraintInstance.m_storage;
  v111 = v18;
  in.m_violatedConstraints.m_storage = (hkpViolatedConstraintArray *)*((_QWORD *)&v17 + 1);
  in.m_constraintInstance.m_storage = 0i64;
  v19 = -v18->m_entities[0]->m_solverData;
  v20 = *(_DWORD *)&v18[1].m_memSizeAndFlags - 1;
  array = (hkp3dAngularMotorSolverInfo *)&v135;
  v133 = 0;
  v134 = -2147483616;
  v21 = (hkpVelocityAccumulator *)((char *)v4->m_bodyA.m_storage + v19);
  v139 = v20;
  v115 = v21;
  if ( v20 > 32 )
  {
    v22 = v20;
    if ( v20 < 64 )
      v22 = 64;
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v22, 64);
    v11 = v126;
    v9 = (char *)v125;
  }
  v133 = v20;
  vecDelDtor = v18[1].vfptr->__vecDelDtor;
  v24 = &v9[4 * v11];
  in.m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v21 + *((unsigned int *)vecDelDtor + 60));
  if ( v24 )
  {
    *(_DWORD *)v24 = LODWORD(in.m_bodyB.m_storage) - (_DWORD)v21;
    v11 = v126;
  }
  v25 = out->m_jacobianSchemas.m_storage;
  in.m_transformB.m_storage = (hkTransformf *)((char *)vecDelDtor + 368);
  LODWORD(in.m_virtMassFactor.m_storage) = (_DWORD)FLOAT_1_0;
  in.m_rhsFactor.m_storage = in.m_subStepInvDeltaTime.m_storage;
  v126 = v11 + 1;
  LinearJacobians = hkJacobianPoweredChainSchema_getLinearJacobians(v25);
  v27 = out->m_jacobianSchemas.m_storage;
  jac = LinearJacobians;
  AngularJacobians = hkJacobianPoweredChainSchema_getAngularJacobians(v27, v20);
  v29 = 0i64;
  v30 = v20;
  v31 = AngularJacobians;
  v114 = 0i64;
  if ( v20 > 0 )
  {
    v32 = 0i64;
    v112 = -40i64;
    v117 = 0i64;
    LODWORD(retaddr) = 0;
    do
    {
      v33 = in.m_transformB.m_storage;
      v34 = v126;
      in.m_bodyA.m_storage = in.m_bodyB.m_storage;
      in.m_transformA.m_storage = in.m_transformB.m_storage;
      v35 = *((_QWORD *)&v18[1].vfptr->__first_virtual_table_function__ + v29);
      v36 = (_DWORD)v21 + *(_DWORD *)(v35 + 240);
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v21 + *(unsigned int *)(v35 + 240));
      v37 = v36 - (_DWORD)v21;
      if ( v126 == (v127 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v125, 4);
        v33 = in.m_transformA.m_storage;
        v34 = v126;
      }
      v38 = &v125[v34];
      if ( v38 )
      {
        v38->m_offset = v37;
        v33 = in.m_transformA.m_storage;
        v34 = v126;
      }
      m_data = this->m_infos.m_data;
      v40 = jac;
      in.m_transformB.m_storage = (hkTransformf *)(v35 + 368);
      v126 = v34 + 1;
      v41 = *(__m128 *)((char *)&m_data->m_pivotInA.m_quad + v32);
      posA.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v33->m_rotation.m_col1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v33->m_rotation.m_col0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v33->m_rotation.m_col2.m_quad)),
                      v33->m_translation.m_quad);
      v42 = *(__m128 *)((char *)&m_data->m_pivotInB.m_quad + v32);
      posB.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), *(__m128 *)(v35 + 384)),
                          _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), *(__m128 *)(v35 + 368))),
                        _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), *(__m128 *)(v35 + 400))),
                      *(__m128 *)(v35 + 416));
      hkStabilizedBallSocketConstraintBuildJacobian_noSchema(&posA, &posB, this->m_maxErrorDistance, &in, jac);
      jac = v40 + 3;
      hkQuaternionf::set(&v119, &in.m_transformA.m_storage->m_rotation);
      hkQuaternionf::set(&qi, &in.m_transformB.m_storage->m_rotation);
      v43 = this->m_infos.m_data;
      if ( *(&v43->m_switchBodies.m_bool + v32) )
      {
        m_quad = v119.m_vec.m_quad;
        v45 = qi.m_vec.m_quad;
        v119.m_vec.m_quad = qi.m_vec.m_quad;
        qi.m_vec.m_quad = m_quad;
      }
      else
      {
        v45 = v119.m_vec.m_quad;
        m_quad = qi.m_vec.m_quad;
      }
      v46 = *(__m128 *)((char *)&v43->m_bTc.m_vec.m_quad + v32);
      m_size = this->m_infos.m_size;
      v48 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v49 = (int)retaddr + 12i64 * (_DWORD)m_size;
      v50 = _mm_shuffle_ps(v46, v46, 255);
      v51 = (m_size + 3) & 0xFFFFFFFFFFFFFFFCui64;
      v52 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v46));
      v53 = _mm_mul_ps(v50, m_quad);
      v54 = _mm_mul_ps(m_quad, v46);
      v55 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v52, v52, 201), _mm_mul_ps(v48, v46)), v53);
      qi.m_vec.m_quad = _mm_shuffle_ps(
                          v55,
                          _mm_unpackhi_ps(
                            v55,
                            _mm_sub_ps(
                              _mm_mul_ps(v50, v48),
                              _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                                _mm_shuffle_ps(v54, v54, 170)))),
                          196);
      v56 = *(__m128 *)(v51 + *(_QWORD *)&output.m_tau.m_storage + 4 * v49);
      v57 = _mm_mul_ps(v56, v56);
      v58 = _mm_add_ps(_mm_shuffle_ps(v57, v57, 78), v57);
      if ( (float)(_mm_shuffle_ps(v58, v58, 177).m128_f32[0] + v58.m128_f32[0]) == 0.0 )
        v56 = *(__m128 *)((char *)&v43->m_aTc.m_vec.m_quad + v32);
      v59 = *(__m128 *)((char *)&v43->m_aTc.m_vec.m_quad + v32);
      v60 = _mm_shuffle_ps(v45, v45, 255);
      v61 = _mm_shuffle_ps(v45, v45, 201);
      *(__m128 *)(v51 + *(_QWORD *)&output.m_tau.m_storage + 4 * v49) = v59;
      v62 = _mm_shuffle_ps(v59, v59, 255);
      v63 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v45), _mm_mul_ps(v59, v61));
      v64 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v45);
      v65 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v63, v63, 201), _mm_mul_ps(v60, v59)), _mm_mul_ps(v62, v45));
      v66 = _mm_mul_ps(v45, v59);
      v67 = _mm_shuffle_ps(v56, v56, 255);
      v68 = _mm_shuffle_ps(
              v65,
              _mm_unpackhi_ps(
                v65,
                _mm_sub_ps(
                  _mm_mul_ps(v62, v60),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                    _mm_shuffle_ps(v66, v66, 170)))),
              196);
      v69 = _mm_mul_ps(v67, v45);
      v70 = _mm_mul_ps(v45, v56);
      v71 = _mm_sub_ps(v64, _mm_mul_ps(v56, v61));
      v72 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v71, v71, 201), _mm_mul_ps(v60, v56)), v69);
      v73 = _mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 255);
      v74 = _mm_shuffle_ps(
              v72,
              _mm_unpackhi_ps(
                v72,
                _mm_sub_ps(
                  _mm_mul_ps(v67, v60),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                    _mm_shuffle_ps(v70, v70, 170)))),
              196);
      v75 = _mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 201);
      v76 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), qi.m_vec.m_quad), _mm_mul_ps(v75, v68));
      v77 = *(&this->m_infos.m_data->m_switchBodies.m_bool + v32) == 0;
      v78 = _mm_sub_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v68, v68, 255), qi.m_vec.m_quad), _mm_shuffle_ps(v76, v76, 201)),
              _mm_mul_ps(v73, v68));
      v79 = _mm_mul_ps(v73, v74);
      v80 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 255), qi.m_vec.m_quad);
      v81 = _mm_mul_ps(v68, qi.m_vec.m_quad);
      v82 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), qi.m_vec.m_quad), _mm_mul_ps(v75, v74));
      v83 = _mm_mul_ps(v74, qi.m_vec.m_quad);
      v84 = _mm_add_ps(_mm_shuffle_ps(v81, v81, 78), v81);
      v85 = _mm_sub_ps(_mm_add_ps(v80, _mm_shuffle_ps(v82, v82, 201)), v79);
      v86 = _mm_add_ps(_mm_shuffle_ps(v83, v83, 78), v83);
      v87 = _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v86, v86, 177), v86), 0x1Fu),
                        0x1Fu),
              _mm_add_ps(v85, v85));
      v88 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v84, v84, 177), v84), 0x1Fu),
                          0x1Fu),
                _mm_add_ps(v78, v78)),
              v87);
      v124 = v87;
      v123 = v88;
      if ( !v77 )
      {
        v89 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
        v124 = _mm_xor_ps(v89, v87);
        v123 = _mm_xor_ps(v89, v88);
      }
      hkRotationf::set((hkRotationf *)&v122, &qi);
      v90 = v29 << 6;
      v91 = v32 + 64;
      v92 = 0i64;
      v93 = (__m128 *)&v122;
      do
      {
        vfptr = this->vfptr;
        m_internal = v111->m_internal;
        directionOfConstraint.m_quad = *v93;
        v96 = (__int64)vfptr[9].__vecDelDtor(this, (unsigned int)m_internal->m_runtime);
        statusOut.m_lastResults = 0i64;
        v97 = v96;
        hk1dAngularVelocityMotorBeginJacobian(&directionOfConstraint, &in, v31, &statusOut);
        v98 = v124.m128_f32[v92];
        LODWORD(statusOut.m_deltaTarget.m_storage) = v123.m128_i32[v92];
        statusOut.m_positionError.m_storage = v98;
        statusOut.m_stepInfo.m_storage = &in;
        v99 = this->m_infos.m_data;
        statusOut.m_lastResults = *(hkpSolverResults *)(v91 + v112 + v97);
        hkCalcMotorData(*(hkpConstraintMotor **)((char *)v99->m_pivotInA.m_quad.m128_u64 + v91), &statusOut, &output);
        v100 = array;
        ++v92;
        ++v31;
        v91 += 8i64;
        ++v93;
        *(float *)((char *)&array->m_motorInfos[0].m_maxImpulsePerSubstep + v90) = in.m_microStepDeltaTime.m_storage
                                                                                 * output.m_maxForce.m_storage;
        v90 += 20i64;
        *(float *)((char *)v100 + v90 - 12) = output.m_minForce.m_storage * in.m_microStepDeltaTime.m_storage;
        *(float *)((char *)v100 + v90 - 8) = output.m_targetVelocity.m_storage;
        *(float *)((char *)v100 + v90 - 4) = output.m_maxForce.m_storage;
        *(float *)(&v100->m_broken + v90) = output.m_minForce.m_storage;
        v31[-1].m_angular[1].m_quad.m128_f32[3] = in.m_subStepInvDeltaTime.m_storage * output.m_targetPosition.m_storage;
      }
      while ( v92 < 3 );
      v20 = v139;
      LODWORD(retaddr) = (_DWORD)retaddr + 4;
      v112 -= 48i64;
      v18 = v111;
      v21 = v115;
      v29 = v114 + 1;
      v32 = v117 + 96;
      v114 = v29;
      v117 += 96i64;
      v30 = v139;
    }
    while ( v29 < v139 );
    v4 = v137;
  }
  v101 = (char *)v18->m_internal->m_runtime + 48 * this->m_infos.m_size;
  v102 = 0i64;
  if ( v30 > 0 )
  {
    v103 = 0i64;
    do
    {
      v104 = v101[v102++];
      array[v103++].m_broken = v104;
    }
    while ( v102 < v30 );
  }
  m_tau = this->m_tau;
  m_damping = this->m_damping;
  v122.m_accumulators = v125;
  v122.m_chainTau = m_tau;
  m_cfmLinAdd = this->m_cfmLinAdd;
  v122.m_chainDamping = m_damping;
  v122.m_numConstraints = v20;
  m_cfmLinMul = this->m_cfmLinMul;
  v122.m_cfm.m_linAdd = m_cfmLinAdd;
  m_cfmAngAdd = this->m_cfmAngAdd;
  v122.m_accumsBase = v21;
  v122.m_motorsState = array;
  v122.m_maxTorqueHysterisys = 0.0;
  v122.m_cfm.m_linMul = m_cfmLinMul;
  m_cfmAngMul = this->m_cfmAngMul;
  v122.m_cfm.m_angAdd = m_cfmAngAdd;
  v122.m_childConstraintStatusWriteBackBuffer = v101;
  v122.m_jacobiansEnd = v31;
  v122.m_cfm.m_angMul = m_cfmAngMul;
  hkPoweredChainBuildJacobian(&v122, v4, inNotValid);
  v133 = 0;
  if ( v134 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v134 << 6);
  v126 = 0;
  if ( v127 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v125, 4 * v127);
}

