// File Line: 29
// RVA: 0xD7AD60
void __fastcall hkpStiffSpringChainData::hkpStiffSpringChainData(hkpStiffSpringChainData *this)
{
  hkpStiffSpringChainData *v1; // rbx
  hkpBridgeConstraintAtom *v2; // rcx

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  v2 = &this->m_atoms.m_bridgeAtom;
  *(_QWORD *)&v2[-1].m_type.m_storage = &hkpStiffSpringChainData::`vftable;
  v2->m_type.m_storage = 1;
  v1->m_infos.m_data = 0i64;
  v1->m_infos.m_size = 0;
  v1->m_infos.m_capacityAndFlags = 2147483648;
  v1->m_tau = 0.60000002;
  v1->m_damping = 1.0;
  v1->m_cfm = 0.000000011920929;
  hkpBridgeConstraintAtom::init(v2, (hkpConstraintData *)&v1->vfptr);
}

// File Line: 34
// RVA: 0xD7B360
void __fastcall hkpStiffSpringChainData::hkpStiffSpringChainData(hkpStiffSpringChainData *this, hkFinishLoadedObjectFlag f)
{
  hkpStiffSpringChainData *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = f.m_finishing;
  v2 = this;
  hkpConstraintData::hkpConstraintData((hkpConstraintData *)&this->vfptr, f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpStiffSpringChainData::`vftable;
  if ( v3 )
  {
    hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, v2->m_atoms.m_bridgeAtom.m_constraintData);
    if ( v3 )
      hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, (hkpConstraintData *)&v2->vfptr);
  }
}

// File Line: 43
// RVA: 0xD7ADD0
void __fastcall hkpStiffSpringChainData::~hkpStiffSpringChainData(hkpStiffSpringChainData *this)
{
  hkpStiffSpringChainData *v1; // rbx
  int v2; // eax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStiffSpringChainData::`vftable;
  v2 = this->m_infos.m_capacityAndFlags;
  this->m_infos.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_infos.m_data,
      48 * (v2 & 0x3FFFFFFF));
  v1->m_infos.m_data = 0i64;
  v1->m_infos.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 47
// RVA: 0xD7AE40
signed __int64 __fastcall hkpStiffSpringChainData::getType(hkpStiffSpringChainData *this)
{
  return 100i64;
}

// File Line: 53
// RVA: 0xD7AE50
void __fastcall hkpStiffSpringChainData::addConstraintInfoInBodySpace(hkpStiffSpringChainData *this, hkVector4f *pivotInA, hkVector4f *pivotInB, float springLength)
{
  signed int *v4; // rbx
  hkVector4f *v5; // rdi
  hkVector4f *v6; // rsi
  __int64 v7; // rcx
  signed __int64 v8; // rdx
  __m128 v9; // xmm1

  v4 = (signed int *)&this->m_infos;
  v5 = pivotInB;
  v6 = pivotInA;
  if ( this->m_infos.m_size == (this->m_infos.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 48);
  v7 = v4[2];
  v4[2] = v7 + 1;
  v8 = *(_QWORD *)v4 + 48 * v7;
  *(hkVector4f *)v8 = (hkVector4f)v6->m_quad;
  v9 = v5->m_quad;
  *(float *)(v8 + 32) = springLength;
  *(__m128 *)(v8 + 16) = v9;
}

// File Line: 62
// RVA: 0xD7B2F0
void __fastcall hkpStiffSpringChainData::getConstraintInfo(hkpStiffSpringChainData *this, hkpConstraintData::ConstraintInfo *info)
{
  int v2; // ecx

  info->m_sizeOfSchemas = 32;
  info->m_sizeOfAllAtoms = 32;
  info->m_atoms = (hkpConstraintAtom *)&this->m_atoms.m_bridgeAtom.m_type;
  *(_QWORD *)&info->m_numSolverResults = 0i64;
  info->m_maxSizeOfSchema = 0;
  v2 = this->m_infos.m_size;
  info->m_numSolverResults = v2;
  info->m_numSolverElemTemps = v2;
  info->m_sizeOfSchemas = ((80 * v2 + 67) & 0xFFFFFFF0) + 32;
}

// File Line: 84
// RVA: 0xD7B330
void __fastcall hkpStiffSpringChainData::getRuntimeInfo(hkpStiffSpringChainData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  int v3; // eax

  if ( wantRuntime.m_bool )
  {
    v3 = this->m_infos.m_size;
    infoOut->m_numSolverResults = v3;
    infoOut->m_sizeOfExternalRuntime = 8 * v3;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 104
// RVA: 0xD7AEE0
void __fastcall hkpStiffSpringChainData::buildJacobian(hkpStiffSpringChainData *this, hkpConstraintQueryIn *inNotValid, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryOut *v3; // r13
  hkpConstraintQueryIn *v4; // rsi
  hkpStiffSpringChainData *v5; // rbx
  __int64 v6; // r12
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  hkSimdFloat32 v11; // xmm0
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  hkSimdFloat32 v14; // xmm1
  hkpConstraintInstance *v15; // r15
  hkBaseObjectVtbl *v16; // rax
  int v17; // er14
  void *(__fastcall *v18)(hkBaseObject *, unsigned int); // rcx
  __int64 v19; // rax
  hkpVelocityAccumulator *accumBase; // rdi
  hkpVelocityAccumulator *v21; // rax
  hkTransformf *v22; // rax
  hkpJacobianSchema *v23; // rcx
  hkp1Lin2AngJacobian *jacobiansEnd; // rax
  signed __int64 v25; // r10
  hkp1Lin2AngJacobian *v26; // r13
  __m128 *v27; // rcx
  int v28; // er8
  __int64 v29; // r14
  int v30; // ebx
  int v31; // ebx
  int *v32; // r9
  hkpStiffSpringChainData::ConstraintInfo *v33; // rdx
  __m128 v34; // xmm1
  hkVector4f v35; // xmm5
  __m128 v36; // xmm1
  hkVector4f v37; // xmm2
  __m128 v38; // xmm5
  __m128 v39; // xmm1
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  hkp1Lin2AngJacobian *v45; // ST58_8
  signed __int64 v46; // [rsp+50h] [rbp-A8h]
  __int64 v47; // [rsp+60h] [rbp-98h]
  hkpConstraintQueryIn in; // [rsp+70h] [rbp-88h]
  int v49; // [rsp+100h] [rbp+8h]
  int v50; // [rsp+104h] [rbp+Ch]
  int v51; // [rsp+108h] [rbp+10h]
  hkp1dLinearBilateralConstraintInfo info; // [rsp+188h] [rbp+90h]
  hkpStiffSpringChainData *retaddr; // [rsp+238h] [rbp+140h]
  hkpStiffSpringChainData *v54; // [rsp+240h] [rbp+148h]
  hkpConstraintQueryIn *v55; // [rsp+248h] [rbp+150h]
  int v56; // [rsp+250h] [rbp+158h]

  v55 = inNotValid;
  v54 = this;
  v3 = out;
  v4 = inNotValid;
  v5 = this;
  v4->m_beginConstraints(v4, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  v50 = -2147483616;
  v6 = 0i64;
  v7 = *(_OWORD *)&v4->m_subStepDeltaTime.m_storage;
  v8 = *(_OWORD *)&v4->m_frameInvDeltaTime.m_storage;
  v49 = 0;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v7;
  v9 = *(_OWORD *)&v4->m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_subStepInvDeltaTime.m_storage = v8;
  in.m_beginConstraints = (void (__fastcall *)(hkpConstraintQueryIn *, hkpConstraintQueryOut *, hkpSolverResults *, int))&v51;
  v10 = *(_OWORD *)&v4->m_bodyA.m_storage;
  *(_OWORD *)&in.m_invNumStepsTimesMicroSteps.m_storage = v9;
  *(_OWORD *)&in.m_bodyB.m_storage = *(_OWORD *)&v4->m_transformA.m_storage;
  v11.m_real = (__m128)v4->m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_frictionRhsFactor.m_storage = v10;
  v12 = *(_OWORD *)&v4->m_tau.m_storage;
  *(hkSimdFloat32 *)(&in.m_damping + 1) = (hkSimdFloat32)v11.m_real;
  v13 = *(_OWORD *)&v4->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&in.m_transformB.m_storage = v12;
  v14.m_real = *(__m128 *)&v4->m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_violatedConstraints.m_storage = v13;
  v3->m_constraintRuntime.m_storage = 0i64;
  v15 = v4->m_constraintInstance.m_storage;
  *(hkSimdFloat32 *)((char *)&in.m_maxConstraintViolationSqrd + 8) = (hkSimdFloat32)v14.m_real;
  in.m_maxConstraintViolationSqrd.m_real.m128_u64[1] = 0i64;
  v16 = v15[1].vfptr;
  v17 = *(_DWORD *)&v15[1].m_memSizeAndFlags - 1;
  v56 = *(_DWORD *)&v15[1].m_memSizeAndFlags - 1;
  v18 = v16->__vecDelDtor;
  v19 = *((unsigned int *)v16->__vecDelDtor + 60);
  accumBase = (hkpVelocityAccumulator *)((char *)v4->m_bodyA.m_storage - v15->m_entities[0]->m_solverData);
  v49 = 1;
  LODWORD(in.m_maxConstraintViolationSqrd.m_storage) = (_DWORD)FLOAT_1_0;
  v21 = (hkpVelocityAccumulator *)((char *)accumBase + v19);
  in.m_bodyA.m_storage = v21;
  v51 = (_DWORD)v21 - (_DWORD)accumBase;
  v22 = (hkTransformf *)((char *)v18 + 368);
  v23 = v3->m_jacobianSchemas.m_storage;
  in.m_transformA.m_storage = v22;
  in.m_invNumStepsTimesMicroSteps.m_storage = in.m_subStepInvDeltaTime.m_storage;
  jacobiansEnd = hkJacobianStiffSpringChainSchema_getJacobians(v23);
  v47 = v17;
  if ( v17 > 0 )
  {
    v25 = 0i64;
    v26 = jacobiansEnd;
    v46 = 0i64;
    do
    {
      v27 = &in.m_transformA.m_storage->m_rotation.m_col0.m_quad;
      v28 = v49;
      *(_QWORD *)&in.m_frictionRhsFactor.m_storage = in.m_bodyA.m_storage;
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)in.m_transformA.m_storage;
      v29 = *((_QWORD *)&v15[1].vfptr->__first_virtual_table_function__ + v6);
      v30 = (_DWORD)accumBase + *(_DWORD *)(v29 + 240);
      in.m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)accumBase + *(unsigned int *)(v29 + 240));
      v31 = v30 - (_DWORD)accumBase;
      if ( v49 == (v50 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &in.m_beginConstraints,
          4);
        v27 = (__m128 *)in.m_bodyB.m_storage;
        v28 = v49;
        v25 = v46;
      }
      v32 = (int *)((char *)in.m_beginConstraints + 4 * v28);
      if ( v32 )
      {
        *v32 = v31;
        v27 = (__m128 *)in.m_bodyB.m_storage;
        v28 = v49;
      }
      v33 = retaddr->m_infos.m_data;
      v49 = v28 + 1;
      in.m_transformA.m_storage = (hkTransformf *)(v29 + 368);
      v34 = *(__m128 *)((char *)&v33->m_pivotInA.m_quad + v25);
      v35.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v27[1]),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v33->m_pivotInA.m_quad + v25), v34, 0), *v27)),
                       _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v27[2])),
                     v27[3]);
      info.m_pivotA = (hkVector4f)v35.m_quad;
      v36 = *(__m128 *)((char *)&v33->m_pivotInB.m_quad + v25);
      v37.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), *(__m128 *)(v29 + 384)),
                         _mm_mul_ps(
                           _mm_shuffle_ps(*(__m128 *)((char *)&v33->m_pivotInB.m_quad + v25), v36, 0),
                           *(__m128 *)(v29 + 368))),
                       _mm_mul_ps(_mm_shuffle_ps(v36, v36, 170), *(__m128 *)(v29 + 400))),
                     *(__m128 *)(v29 + 416));
      v38 = _mm_sub_ps(v35.m_quad, v37.m_quad);
      info.m_pivotB = (hkVector4f)v37.m_quad;
      v39 = _mm_mul_ps(v38, v38);
      v40 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
              _mm_shuffle_ps(v39, v39, 170));
      v41 = _mm_rsqrt_ps(v40);
      v42 = _mm_andnot_ps(
              _mm_cmpleps(v40, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                _mm_mul_ps(v41, *(__m128 *)_xmm)));
      v43 = _mm_mul_ps(v42, v40);
      v44 = _mm_cmpltps((__m128)0i64, v43);
      info.m_constrainedDofW.m_quad = _mm_or_ps(
                                        _mm_and_ps(_mm_mul_ps(v38, v42), v44),
                                        _mm_andnot_ps(v44, transform.m_quad));
      hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(
        &info,
        &in,
        v26,
        *(float *)((char *)&v33->m_springLength + v25) - fmax(v43.m128_f32[0], 0.0));
      ++v6;
      v25 = v46 + 48;
      ++v26;
      v46 += 48i64;
    }
    while ( v6 < v47 );
    v4 = (hkpConstraintQueryIn *)v54;
    v5 = retaddr;
    v17 = v56;
    v45 = v26;
    v3 = (hkpConstraintQueryOut *)v55;
    jacobiansEnd = v45;
  }
  hkStiffSpringChainBuildJacobian(
    v17,
    v5->m_tau,
    v5->m_damping,
    v5->m_cfm,
    (hkpVelocityAccumulatorOffset *)in.m_beginConstraints,
    accumBase,
    jacobiansEnd,
    v4,
    v3);
  v49 = 0;
  if ( v50 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      in.m_beginConstraints,
      4 * v50);
}
    v3);
  v49 = 0;
  if ( v50 >= 0 )
    hkContainerHeapA

