// File Line: 37
// RVA: 0xD7B450
void __fastcall hkpPoweredChainData::hkpPoweredChainData(hkpPoweredChainData *this)
{
  hkpPoweredChainData *v1; // rbx
  hkpBridgeConstraintAtom *v2; // rcx

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  v2 = &this->m_atoms.m_bridgeAtom;
  *(_QWORD *)&v2[-1].m_type.m_storage = &hkpPoweredChainData::`vftable';
  v2->m_type.m_storage = 1;
  v1->m_infos.m_data = 0i64;
  v1->m_infos.m_size = 0;
  v1->m_infos.m_capacityAndFlags = 2147483648;
  v1->m_tau = 0.60000002;
  v1->m_damping = 1.0;
  v1->m_cfmLinAdd = 0.000000011920929;
  v1->m_cfmLinMul = 1.0;
  v1->m_cfmAngAdd = 0.000000011920929;
  v1->m_cfmAngMul = 1.0;
  v1->m_maxErrorDistance = 0.1;
  hkpBridgeConstraintAtom::init(v2, (hkpConstraintData *)&v1->vfptr);
}

// File Line: 49
// RVA: 0xD7C1A0
void __fastcall hkpPoweredChainData::hkpPoweredChainData(hkpPoweredChainData *this, hkFinishLoadedObjectFlag f)
{
  hkpPoweredChainData *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = f.m_finishing;
  v2 = this;
  hkpConstraintData::hkpConstraintData((hkpConstraintData *)&this->vfptr, f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpPoweredChainData::`vftable';
  if ( v3 )
  {
    hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, v2->m_atoms.m_bridgeAtom.m_constraintData);
    if ( v3 )
      hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, (hkpConstraintData *)&v2->vfptr);
  }
}

// File Line: 58
// RVA: 0xD7B4E0
void __fastcall hkpPoweredChainData::~hkpPoweredChainData(hkpPoweredChainData *this)
{
  int v1; // ebp
  hkpPoweredChainData *v2; // rsi
  signed __int64 v3; // r14
  signed __int64 v4; // rbx
  signed __int64 v5; // rdi
  hkReferencedObject *v6; // rcx
  int v7; // eax

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPoweredChainData::`vftable';
  v2 = this;
  if ( this->m_infos.m_size > 0 )
  {
    v3 = 64i64;
    do
    {
      v4 = v3;
      v5 = 3i64;
      do
      {
        v6 = *(hkReferencedObject **)((char *)v2->m_infos.m_data->m_pivotInA.m_quad.m128_u64 + v4);
        if ( v6 )
          hkReferencedObject::removeReference(v6);
        v4 += 8i64;
        --v5;
      }
      while ( v5 );
      ++v1;
      v3 += 96i64;
    }
    while ( v1 < v2->m_infos.m_size );
  }
  v7 = v2->m_infos.m_capacityAndFlags;
  v2->m_infos.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_infos.m_data,
      96 * (v7 & 0x3FFFFFFF));
  v2->m_infos.m_data = 0i64;
  v2->m_infos.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 73
// RVA: 0xD7B5C0
signed __int64 __fastcall hkpPoweredChainData::getType(hkpPoweredChainData *this)
{
  return 102i64;
}

// File Line: 79
// RVA: 0xD7B5D0
void __fastcall hkpPoweredChainData::addConstraintInfoInBodySpace(hkpPoweredChainData *this, hkVector4f *pivotInA, hkVector4f *pivotInB, hkQuaternionf *aTc, hkpConstraintMotor *xMotor, hkpConstraintMotor *yMotor, hkpConstraintMotor *zMotor)
{
  signed int *v7; // rdi
  hkQuaternionf *v8; // rsi
  hkVector4f *v9; // rbp
  hkVector4f *v10; // r14
  __int64 v11; // rcx
  signed __int64 v12; // rbx

  v7 = (signed int *)&this->m_infos;
  v8 = aTc;
  v9 = pivotInB;
  v10 = pivotInA;
  if ( this->m_infos.m_size == (this->m_infos.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 96);
  v11 = v7[2];
  v7[2] = v11 + 1;
  v12 = *(_QWORD *)v7 + 96 * v11;
  *(hkVector4f *)v12 = (hkVector4f)v10->m_quad;
  *(hkVector4f *)(v12 + 16) = (hkVector4f)v9->m_quad;
  *(hkQuaternionf *)(v12 + 32) = (hkQuaternionf)v8->m_vec.m_quad;
  *(_QWORD *)(v12 + 64) = xMotor;
  hkReferencedObject::addReference((hkReferencedObject *)&xMotor->vfptr);
  *(_QWORD *)(v12 + 72) = yMotor;
  hkReferencedObject::addReference((hkReferencedObject *)&yMotor->vfptr);
  *(_QWORD *)(v12 + 80) = zMotor;
  hkReferencedObject::addReference((hkReferencedObject *)&zMotor->vfptr);
  *(_BYTE *)(v12 + 88) = 0;
  *(hkQuaternionf *)(v12 + 48) = (hkQuaternionf)qi.m_vec.m_quad;
}

// File Line: 101
// RVA: 0xD7C100
void __fastcall hkpPoweredChainData::getConstraintInfo(hkpPoweredChainData *this, hkpConstraintData::ConstraintInfo *info)
{
  int v2; // er8

  info->m_sizeOfSchemas = 32;
  info->m_atoms = (hkpConstraintAtom *)&this->m_atoms.m_bridgeAtom.m_type;
  info->m_sizeOfAllAtoms = 32;
  *(_QWORD *)&info->m_numSolverResults = 0i64;
  info->m_maxSizeOfSchema = 0;
  v2 = this->m_infos.m_size;
  info->m_numSolverResults = 6 * v2;
  info->m_numSolverElemTemps = 6 * v2;
  info->m_sizeOfSchemas = ((240 * v2 + 36 * (v2 + 1) + 1056 * v2 + 47) & 0xFFFFFFF0) + 32;
}

// File Line: 126
// RVA: 0xD7C170
void __fastcall hkpPoweredChainData::getRuntimeInfo(hkpPoweredChainData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  int v3; // edx

  v3 = this->m_infos.m_size;
  infoOut->m_numSolverResults = 6 * v3;
  infoOut->m_sizeOfExternalRuntime = ((v3 + 3) & 0xFFFFFFFC) + (v3 << 6);
}

// File Line: 139
// RVA: 0xD7B6A0
void __fastcall hkpPoweredChainData::enableMotor(hkpConstraintChainInstance *instance, int constraintIndex, int motorIndex)
{
  char *v3; // r10

  v3 = (char *)instance->m_internal->m_runtime + 48 * LODWORD(instance->m_data[3].vfptr);
  v3[constraintIndex] &= ~(3 << 2 * motorIndex);
}

// File Line: 154
// RVA: 0xD7B6F0
void __fastcall hkpPoweredChainData::disableMotor(hkpConstraintChainInstance *instance, int constraintIndex, int motorIndex)
{
  char *v3; // r10

  v3 = (char *)instance->m_internal->m_runtime + 48 * LODWORD(instance->m_data[3].vfptr);
  v3[constraintIndex] = (2 << 2 * motorIndex) | v3[constraintIndex] & ~(3 << 2 * motorIndex);
}

// File Line: 172
// RVA: 0xD7C200
void __fastcall estimateAngleToLs(hkQuaternionf *from, hkQuaternionf *to, hkVector4f *angleOut)
{
  __m128 v3; // xmm2
  hkVector4f v4; // xmm2
  hkVector4f v5; // xmm3
  __m128 v6; // xmm3
  hkVector4f v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm1

  v3 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(to->m_vec.m_quad, to->m_vec.m_quad, 201), from->m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(from->m_vec.m_quad, from->m_vec.m_quad, 201), to->m_vec.m_quad));
  v4.m_quad = _mm_shuffle_ps(v3, v3, 201);
  *angleOut = (hkVector4f)v4.m_quad;
  v5.m_quad = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(to->m_vec.m_quad, to->m_vec.m_quad, 255), from->m_vec.m_quad),
                v4.m_quad);
  *angleOut = (hkVector4f)v5.m_quad;
  v6 = _mm_sub_ps(v5.m_quad, _mm_mul_ps(_mm_shuffle_ps(from->m_vec.m_quad, from->m_vec.m_quad, 255), to->m_vec.m_quad));
  v7.m_quad = _mm_add_ps(v6, v6);
  *angleOut = (hkVector4f)v7.m_quad;
  v8 = _mm_mul_ps(from->m_vec.m_quad, to->m_vec.m_quad);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  angleOut->m_quad = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9), 0x1Fu),
                                 0x1Fu),
                       v7.m_quad);
}

// File Line: 181
// RVA: 0xD7C280
void __fastcall hk1dAngularVelocityMotorCommitJacobianInMotorInfo(hkp1dConstraintMotorInfo *info, hkpConstraintQueryIn *in, hkp2AngJacobian *jac, hkp1dMotorSolverInfo *motorInfoOut)
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
void __fastcall hkpPoweredChainData::buildJacobian(hkpPoweredChainData *this, hkpConstraintQueryIn *inNotValid, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryOut *v3; // rdi
  hkpConstraintQueryIn *v4; // rsi
  hkpPoweredChainData *v5; // r14
  struct hkpConstraintRuntime *v6; // rax
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
  int v20; // er13
  unsigned __int64 v21; // r15
  int v22; // er9
  void *(__fastcall *v23)(hkBaseObject *, unsigned int); // r10
  char *v24; // r9
  hkpJacobianSchema *v25; // rcx
  hkp1Lin2AngJacobian *v26; // rax
  hkpJacobianSchema *v27; // rcx
  hkp2AngJacobian *v28; // rax
  __int64 v29; // rdi
  __int64 v30; // r9
  hkp2AngJacobian *v31; // r12
  __int64 v32; // rsi
  hkTransformf *v33; // rcx
  int v34; // er8
  __int64 v35; // r13
  int v36; // ebx
  int v37; // ebx
  char *v38; // r9
  hkpPoweredChainData::ConstraintInfo *v39; // rdx
  hkp1Lin2AngJacobian *v40; // rbx
  __m128 v41; // xmm1
  __m128 v42; // xmm1
  hkpPoweredChainData::ConstraintInfo *v43; // r8
  __m128 v44; // xmm6
  __m128 v45; // xmm9
  __m128 v46; // xmm2
  __int64 v47; // rdx
  __m128 v48; // xmm4
  signed __int64 v49; // r9
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
  __m128 v62; // xmm0
  __m128 v63; // xmm3
  __m128 v64; // xmm8
  __m128 v65; // xmm7
  __m128 v66; // xmm8
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm8
  __m128 v70; // xmm1
  __m128 v71; // xmm9
  __m128 v72; // xmm7
  __m128 v73; // xmm7
  __m128 v74; // xmm3
  __m128 v75; // xmm7
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  bool v78; // zf
  __m128 v79; // xmm6
  __m128 v80; // xmm3
  __m128 v81; // xmm1
  __m128 v82; // xmm8
  __m128 v83; // xmm0
  __m128 v84; // xmm7
  __m128 v85; // xmm4
  __m128 v86; // xmm1
  __m128 v87; // xmm0
  __m128 v88; // xmm3
  __m128 v89; // xmm2
  __m128 v90; // xmm1
  __int64 v91; // rdi
  signed __int64 v92; // r15
  signed __int64 v93; // rsi
  __m128i *v94; // r13
  hkBaseObjectVtbl *v95; // r8
  hkConstraintInternal *v96; // rax
  __int64 v97; // rax
  __int64 v98; // rbx
  int v99; // xmm1_4
  hkpPoweredChainData::ConstraintInfo *v100; // rcx
  __int64 v101; // rax
  signed __int64 v102; // r10
  __int64 v103; // rdx
  __int64 v104; // r8
  char v105; // cl
  float v106; // xmm0_4
  float v107; // xmm1_4
  int v108; // xmm0_4
  float v109; // xmm1_4
  float v110; // xmm0_4
  int v111; // xmm1_4
  hkpConstraintInstance *v112; // [rsp+30h] [rbp-C8h]
  signed __int64 v113; // [rsp+38h] [rbp-C0h]
  hkQuaternionf qi; // [rsp+40h] [rbp-B8h]
  __int64 v115; // [rsp+50h] [rbp-A8h]
  hkpVelocityAccumulator *v116; // [rsp+58h] [rbp-A0h]
  hkp1Lin2AngJacobian *jac; // [rsp+60h] [rbp-98h]
  __int64 v118; // [rsp+68h] [rbp-90h]
  hkpConstraintMotorOutput output; // [rsp+70h] [rbp-88h]
  hkQuaternionf v120; // [rsp+88h] [rbp-70h]
  hkp1dBilateralConstraintStatus statusOut; // [rsp+98h] [rbp-60h]
  hkpConstraintQueryIn *v122; // [rsp+A0h] [rbp-58h]
  __int64 v123; // [rsp+A8h] [rbp-50h]
  int v124; // [rsp+B0h] [rbp-48h]
  int v125; // [rsp+B4h] [rbp-44h]
  hkpConstraintQueryIn in; // [rsp+B8h] [rbp-40h]
  hkRotationf v127; // [rsp+148h] [rbp+50h]
  char *v128; // [rsp+178h] [rbp+80h]
  int v129; // [rsp+180h] [rbp+88h]
  __int64 v130; // [rsp+188h] [rbp+90h]
  hkp2AngJacobian *v131; // [rsp+190h] [rbp+98h]
  __m128 v132; // [rsp+198h] [rbp+A0h]
  __m128 v133; // [rsp+1A8h] [rbp+B0h]
  char *v134; // [rsp+1B8h] [rbp+C0h]
  int v135; // [rsp+1C0h] [rbp+C8h]
  int v136; // [rsp+1C4h] [rbp+CCh]
  char v137; // [rsp+1C8h] [rbp+D0h]
  hkVector4f posA; // [rsp+248h] [rbp+150h]
  hkVector4f posB; // [rsp+258h] [rbp+160h]
  hkVector4f directionOfConstraint; // [rsp+268h] [rbp+170h]
  char *array; // [rsp+278h] [rbp+180h]
  int v142; // [rsp+280h] [rbp+188h]
  int v143; // [rsp+284h] [rbp+18Ch]
  char v144; // [rsp+288h] [rbp+190h]
  void *retaddr; // [rsp+B38h] [rbp+A40h]
  hkpConstraintQueryIn *v146; // [rsp+B40h] [rbp+A48h]
  hkpConstraintQueryOut *outa; // [rsp+B48h] [rbp+A50h]
  int v148; // [rsp+B50h] [rbp+A58h]

  outa = (hkpConstraintQueryOut *)inNotValid;
  v3 = out;
  v4 = inNotValid;
  v5 = this;
  v4->m_beginConstraints(v4, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  v6 = v3->m_constraintRuntime.m_storage;
  v7 = *(_OWORD *)&v4->m_subStepDeltaTime.m_storage;
  v8 = *(_OWORD *)&v4->m_frameInvDeltaTime.m_storage;
  v136 = -2147483616;
  *(_QWORD *)&output.m_tau.m_storage = v6;
  v9 = &v137;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v7;
  v10 = *(_OWORD *)&v4->m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v8;
  v134 = &v137;
  v11 = 0;
  v12 = *(_OWORD *)&v4->m_bodyA.m_storage;
  *(_OWORD *)&in.m_rhsFactor.m_storage = v10;
  v13 = *(_OWORD *)&v4->m_transformA.m_storage;
  v135 = 0;
  *(_OWORD *)&in.m_transformA.m_storage = v13;
  v14.m_real = (__m128)v4->m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_bodyA.m_storage = v12;
  v15 = *(_OWORD *)&v4->m_tau.m_storage;
  in.m_maxConstraintViolationSqrd = (hkSimdFloat32)v14.m_real;
  v16 = *(_OWORD *)&v4->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&in.m_tau.m_storage = v15;
  v17 = *(_OWORD *)&v4->m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = v16;
  v3->m_constraintRuntime.m_storage = 0i64;
  v18 = v4->m_constraintInstance.m_storage;
  v112 = v18;
  *(_OWORD *)&in.m_constraintInstance.m_storage = v17;
  in.m_constraintInstance.m_storage = 0i64;
  v19 = -v18->m_entities[0]->m_solverData;
  v20 = *(_DWORD *)&v18[1].m_memSizeAndFlags - 1;
  array = &v144;
  v142 = 0;
  v143 = -2147483616;
  v21 = (unsigned __int64)v4->m_bodyA.m_storage + v19;
  v148 = v20;
  v116 = (hkpVelocityAccumulator *)((char *)v4->m_bodyA.m_storage + v19);
  if ( v20 > 32 )
  {
    v22 = v20;
    if ( v20 < 64 )
      v22 = 64;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v22,
      64);
    v11 = v135;
    v9 = v134;
  }
  v142 = v20;
  v23 = v18[1].vfptr->__vecDelDtor;
  v24 = &v9[4 * v11];
  in.m_bodyB.m_storage = (hkpVelocityAccumulator *)(v21 + *((unsigned int *)v23 + 60));
  if ( v24 )
  {
    *(_DWORD *)v24 = LODWORD(in.m_bodyB.m_storage) - v21;
    v11 = v135;
  }
  v25 = v3->m_jacobianSchemas.m_storage;
  in.m_transformB.m_storage = (hkTransformf *)((char *)v23 + 368);
  LODWORD(in.m_virtMassFactor.m_storage) = (_DWORD)FLOAT_1_0;
  in.m_rhsFactor.m_storage = in.m_subStepInvDeltaTime.m_storage;
  v135 = v11 + 1;
  v26 = hkJacobianPoweredChainSchema_getLinearJacobians(v25);
  v27 = v3->m_jacobianSchemas.m_storage;
  jac = v26;
  v28 = hkJacobianPoweredChainSchema_getAngularJacobians(v27, v20);
  v29 = 0i64;
  v30 = v20;
  v31 = v28;
  v115 = 0i64;
  if ( v20 > 0 )
  {
    v32 = 0i64;
    v113 = -40i64;
    v118 = 0i64;
    LODWORD(retaddr) = 0;
    do
    {
      v33 = in.m_transformB.m_storage;
      v34 = v135;
      in.m_bodyA.m_storage = in.m_bodyB.m_storage;
      in.m_transformA.m_storage = in.m_transformB.m_storage;
      v35 = *((_QWORD *)&v18[1].vfptr->__first_virtual_table_function__ + v29);
      v36 = v21 + *(_DWORD *)(v35 + 240);
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)(v21 + *(unsigned int *)(v35 + 240));
      v37 = v36 - v21;
      if ( v135 == (v136 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v134, 4);
        v33 = in.m_transformA.m_storage;
        v34 = v135;
      }
      v38 = &v134[4 * v34];
      if ( v38 )
      {
        *(_DWORD *)v38 = v37;
        v33 = in.m_transformA.m_storage;
        v34 = v135;
      }
      v39 = v5->m_infos.m_data;
      v40 = jac;
      in.m_transformB.m_storage = (hkTransformf *)(v35 + 368);
      v135 = v34 + 1;
      v41 = *(__m128 *)((char *)&v39->m_pivotInA.m_quad + v32);
      posA.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v33->m_rotation.m_col1.m_quad),
                          _mm_mul_ps(
                            _mm_shuffle_ps(*(__m128 *)((char *)&v39->m_pivotInA.m_quad + v32), v41, 0),
                            v33->m_rotation.m_col0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v33->m_rotation.m_col2.m_quad)),
                      v33->m_translation.m_quad);
      v42 = *(__m128 *)((char *)&v39->m_pivotInB.m_quad + v32);
      posB.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), *(__m128 *)(v35 + 384)),
                          _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), *(__m128 *)(v35 + 368))),
                        _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), *(__m128 *)(v35 + 400))),
                      *(__m128 *)(v35 + 416));
      hkStabilizedBallSocketConstraintBuildJacobian_noSchema(&posA, &posB, v5->m_maxErrorDistance, &in, jac);
      jac = v40 + 3;
      hkQuaternionf::set(&v120, &in.m_transformA.m_storage->m_rotation);
      hkQuaternionf::set(&qi, &in.m_transformB.m_storage->m_rotation);
      v43 = v5->m_infos.m_data;
      if ( *(&v43->m_switchBodies.m_bool + v32) )
      {
        v44 = v120.m_vec.m_quad;
        v45 = qi.m_vec.m_quad;
        v120.m_vec.m_quad = qi.m_vec.m_quad;
        qi.m_vec.m_quad = v44;
      }
      else
      {
        v45 = v120.m_vec.m_quad;
        v44 = qi.m_vec.m_quad;
      }
      v46 = *(__m128 *)((char *)&v43->m_bTc.m_vec.m_quad + v32);
      v47 = v5->m_infos.m_size;
      v48 = _mm_shuffle_ps(v44, v44, 255);
      v49 = (signed int)retaddr + 12i64 * (_DWORD)v47;
      v50 = _mm_shuffle_ps(
              *(__m128 *)((char *)&v43->m_bTc.m_vec.m_quad + v32),
              *(__m128 *)((char *)&v43->m_bTc.m_vec.m_quad + v32),
              255);
      v51 = (v47 + 3) & 0xFFFFFFFFFFFFFFFCui64;
      v52 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v43->m_bTc.m_vec.m_quad + v32), v46, 201), v44),
              _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v46));
      v53 = _mm_mul_ps(v50, v44);
      v54 = _mm_mul_ps(v44, v46);
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
      if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 177)) + v58.m128_f32[0]) == 0.0 )
        v56 = *(__m128 *)((char *)&v43->m_aTc.m_vec.m_quad + v32);
      v59 = *(__m128 *)((char *)&v43->m_aTc.m_vec.m_quad + v32);
      v60 = _mm_shuffle_ps(v45, v45, 255);
      v61 = _mm_shuffle_ps(v45, v45, 201);
      v62 = _mm_mul_ps(*(__m128 *)((char *)&v43->m_aTc.m_vec.m_quad + v32), v61);
      *(hkQuaternionf *)(v51 + *(_QWORD *)&output.m_tau.m_storage + 4 * v49) = *(hkQuaternionf *)((char *)&v43->m_aTc
                                                                                                + v32);
      v63 = _mm_shuffle_ps(v59, v59, 255);
      v64 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v45), v62);
      v65 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v45);
      v66 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v64, v64, 201), _mm_mul_ps(v60, v59)), _mm_mul_ps(v63, v45));
      v67 = _mm_mul_ps(v45, v59);
      v68 = _mm_shuffle_ps(v56, v56, 255);
      v69 = _mm_shuffle_ps(
              v66,
              _mm_unpackhi_ps(
                v66,
                _mm_sub_ps(
                  _mm_mul_ps(v63, v60),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                    _mm_shuffle_ps(v67, v67, 170)))),
              196);
      v70 = _mm_mul_ps(v68, v45);
      v71 = _mm_mul_ps(v45, v56);
      v72 = _mm_sub_ps(v65, _mm_mul_ps(v56, v61));
      v73 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v72, v72, 201), _mm_mul_ps(v60, v56)), v70);
      v74 = _mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 255);
      v75 = _mm_shuffle_ps(
              v73,
              _mm_unpackhi_ps(
                v73,
                _mm_sub_ps(
                  _mm_mul_ps(v68, v60),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                    _mm_shuffle_ps(v71, v71, 170)))),
              196);
      v76 = _mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 201);
      v77 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), qi.m_vec.m_quad), _mm_mul_ps(v76, v69));
      v78 = *(&v5->m_infos.m_data->m_switchBodies.m_bool + v32) == 0;
      v79 = _mm_sub_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v69, v69, 255), qi.m_vec.m_quad), _mm_shuffle_ps(v77, v77, 201)),
              _mm_mul_ps(v74, v69));
      v80 = _mm_mul_ps(v74, v75);
      v81 = _mm_mul_ps(_mm_shuffle_ps(v75, v75, 255), qi.m_vec.m_quad);
      v82 = _mm_mul_ps(v69, qi.m_vec.m_quad);
      v83 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), qi.m_vec.m_quad), _mm_mul_ps(v76, v75));
      v84 = _mm_mul_ps(v75, qi.m_vec.m_quad);
      v85 = _mm_add_ps(_mm_shuffle_ps(v82, v82, 78), v82);
      v86 = _mm_sub_ps(_mm_add_ps(v81, _mm_shuffle_ps(v83, v83, 201)), v80);
      v87 = _mm_add_ps(_mm_shuffle_ps(v84, v84, 78), v84);
      v88 = _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v87, v87, 177), v87), 0x1Fu),
                        0x1Fu),
              _mm_add_ps(v86, v86));
      v89 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v85, v85, 177), v85), 0x1Fu),
                          0x1Fu),
                _mm_add_ps(v79, v79)),
              v88);
      v133 = v88;
      v132 = v89;
      if ( !v78 )
      {
        v90 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
        v133 = _mm_xor_ps(v90, v88);
        v132 = _mm_xor_ps(v90, v89);
      }
      hkRotationf::set(&v127, &qi);
      v91 = v29 << 6;
      v92 = v32 + 64;
      v93 = 0i64;
      v94 = (__m128i *)&v127;
      do
      {
        v95 = v5->vfptr;
        v96 = v112->m_internal;
        _mm_store_si128((__m128i *)&directionOfConstraint, *v94);
        v97 = (__int64)v95[9].__vecDelDtor((hkBaseObject *)&v5->vfptr, (unsigned int)v96->m_runtime);
        v123 = 0i64;
        v98 = v97;
        hk1dAngularVelocityMotorBeginJacobian(&directionOfConstraint, &in, v31, &statusOut);
        v99 = v133.m128_i32[v93];
        v124 = v132.m128_i32[v93];
        v125 = v99;
        v122 = &in;
        v100 = v5->m_infos.m_data;
        v123 = *(_QWORD *)(v92 + v113 + v98);
        hkCalcMotorData(
          *(hkpConstraintMotor **)((char *)v100->m_pivotInA.m_quad.m128_u64 + v92),
          (hkpConstraintMotorInput *)&statusOut,
          &output);
        v101 = (__int64)array;
        ++v93;
        ++v31;
        v92 += 8i64;
        ++v94;
        *(float *)&array[v91 + 4] = in.m_microStepDeltaTime.m_storage * output.m_maxForce.m_storage;
        v91 += 20i64;
        *(float *)(v91 + v101 - 12) = output.m_minForce.m_storage * in.m_microStepDeltaTime.m_storage;
        *(float *)(v91 + v101 - 8) = output.m_targetVelocity.m_storage;
        *(float *)(v91 + v101 - 4) = output.m_maxForce.m_storage;
        *(float *)(v91 + v101) = output.m_minForce.m_storage;
        v31[-1].m_angular[1].m_quad.m128_f32[3] = in.m_subStepInvDeltaTime.m_storage * output.m_targetPosition.m_storage;
      }
      while ( v93 < 3 );
      v20 = v148;
      LODWORD(retaddr) = (_DWORD)retaddr + 4;
      v113 -= 48i64;
      v18 = v112;
      v21 = (unsigned __int64)v116;
      v29 = v115 + 1;
      v32 = v118 + 96;
      v115 = v29;
      v118 += 96i64;
      v30 = v148;
    }
    while ( v29 < v148 );
    v4 = v146;
  }
  v102 = (signed __int64)v18->m_internal->m_runtime + 48 * v5->m_infos.m_size;
  v103 = 0i64;
  if ( v30 > 0 )
  {
    v104 = 0i64;
    do
    {
      v105 = *(_BYTE *)(v103++ + v102);
      array[v104] = v105;
      v104 += 64i64;
    }
    while ( v103 < v30 );
  }
  v106 = v5->m_tau;
  v107 = v5->m_damping;
  v127.m_col2.m_quad.m128_u64[0] = (unsigned __int64)v134;
  *(unsigned __int64 *)((char *)v127.m_col0.m_quad.m128_u64 + 4) = __PAIR__(LODWORD(v107), LODWORD(v106));
  v108 = LODWORD(v5->m_cfmLinAdd);
  v127.m_col0.m_quad.m128_i32[0] = v20;
  v109 = v5->m_cfmLinMul;
  v127.m_col0.m_quad.m128_i32[3] = v108;
  v110 = v5->m_cfmAngAdd;
  v127.m_col2.m_quad.m128_u64[1] = v21;
  v128 = array;
  v129 = 0;
  v127.m_col1.m_quad.m128_u64[0] = __PAIR__(LODWORD(v110), LODWORD(v109));
  v111 = LODWORD(v5->m_cfmAngMul);
  v130 = v102;
  v131 = v31;
  v127.m_col1.m_quad.m128_i32[2] = v111;
  hkPoweredChainBuildJacobian((hkpPoweredChainBuildJacobianParams *)&v127, v4, outa);
  v142 = 0;
  if ( v143 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v143 << 6);
  v135 = 0;
  if ( v136 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v134,
      4 * v136);
}

