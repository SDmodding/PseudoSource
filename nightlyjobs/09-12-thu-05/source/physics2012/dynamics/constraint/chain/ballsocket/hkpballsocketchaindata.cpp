// File Line: 31
// RVA: 0xD752C0
void __fastcall hkpBallSocketChainData::hkpBallSocketChainData(hkpBallSocketChainData *this)
{
  hkpBallSocketChainData *v1; // rbx
  hkpBridgeConstraintAtom *v2; // rcx

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  v2 = &this->m_atoms.m_bridgeAtom;
  *(_QWORD *)&v2[-1].m_type.m_storage = &hkpBallSocketChainData::`vftable;
  v2->m_type.m_storage = 1;
  v1->m_infos.m_data = 0i64;
  v1->m_infos.m_size = 0;
  v1->m_infos.m_capacityAndFlags = 2147483648;
  v1->m_useStabilizedCode = 0;
  v1->m_tau = 0.60000002;
  v1->m_damping = 1.0;
  v1->m_cfm = 0.000000011920929;
  v1->m_maxErrorDistance = 0.1;
  hkpBridgeConstraintAtom::init(v2, (hkpConstraintData *)&v1->vfptr);
}

// File Line: 38
// RVA: 0xD75CF0
void __fastcall hkpBallSocketChainData::hkpBallSocketChainData(hkpBallSocketChainData *this, hkFinishLoadedObjectFlag f)
{
  hkpBallSocketChainData *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = f.m_finishing;
  v2 = this;
  hkpConstraintData::hkpConstraintData((hkpConstraintData *)&this->vfptr, f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpBallSocketChainData::`vftable;
  if ( v3 )
  {
    hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, v2->m_atoms.m_bridgeAtom.m_constraintData);
    if ( v3 )
      hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, (hkpConstraintData *)&v2->vfptr);
  }
}

// File Line: 47
// RVA: 0xD75340
void __fastcall hkpBallSocketChainData::~hkpBallSocketChainData(hkpBallSocketChainData *this)
{
  hkpBallSocketChainData *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBallSocketChainData::`vftable;
  v2 = this->m_infos.m_capacityAndFlags;
  this->m_infos.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_infos.m_data,
      32 * v2);
  v1->m_infos.m_data = 0i64;
  v1->m_infos.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 52
// RVA: 0xD753B0
signed __int64 __fastcall hkpBallSocketChainData::getType(hkpBallSocketChainData *this)
{
  return 101i64;
}

// File Line: 57
// RVA: 0xD753C0
void __fastcall hkpBallSocketChainData::addConstraintInfoInBodySpace(hkpBallSocketChainData *this, hkVector4f *pivotInA, hkVector4f *pivotInB)
{
  hkArray<hkpBallSocketChainData::ConstraintInfo,hkContainerHeapAllocator> *v3; // rbx
  hkVector4f *v4; // rdi
  hkVector4f *v5; // rsi
  __m128 *v6; // rcx

  v3 = &this->m_infos;
  v4 = pivotInB;
  v5 = pivotInA;
  if ( this->m_infos.m_size == (this->m_infos.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 32);
  v6 = &v3->m_data[v3->m_size++].m_pivotInA.m_quad;
  *v6 = v5->m_quad;
  v6[1] = v4->m_quad;
}

// File Line: 64
// RVA: 0xD75440
void __fastcall hkpBallSocketChainData::useStabilizedCode(hkpBallSocketChainData *this, bool useIt)
{
  this->m_useStabilizedCode = useIt;
}

// File Line: 72
// RVA: 0xD75C60
void __fastcall hkpBallSocketChainData::getConstraintInfo(hkpBallSocketChainData *this, hkpConstraintData::ConstraintInfo *info)
{
  int v2; // eax

  info->m_sizeOfSchemas = 32;
  info->m_atoms = (hkpConstraintAtom *)&this->m_atoms.m_bridgeAtom.m_type;
  info->m_sizeOfAllAtoms = 32;
  *(_QWORD *)&info->m_numSolverResults = 0i64;
  info->m_maxSizeOfSchema = 0;
  v2 = this->m_infos.m_size;
  info->m_numSolverResults = 3 * v2;
  info->m_numSolverElemTemps = 3 * v2;
  info->m_sizeOfSchemas = ((288 * v2 + 20 * v2 + 67) & 0xFFFFFFF0) + 32;
}

// File Line: 94
// RVA: 0xD75CC0
void __fastcall hkpBallSocketChainData::getRuntimeInfo(hkpBallSocketChainData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
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
void __fastcall hkpBallSocketChainData::buildJacobian(hkpBallSocketChainData *this, hkpConstraintQueryIn *inChain, hkpConstraintQueryOut *out)
{
  JUMPOUT(this->m_useStabilizedCode, 0, hkpBallSocketChainData::buildJacobian_Unstabilized);
  hkpBallSocketChainData::buildJacobian_Stabilized(this, inChain, out);
}

// File Line: 129
// RVA: 0xD75470
void __fastcall hkpBallSocketChainData::buildJacobian_Unstabilized(hkpBallSocketChainData *this, hkpConstraintQueryIn *inChain, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryOut *v3; // rbx
  hkpConstraintQueryIn *v4; // r14
  hkpBallSocketChainData *v5; // r12
  __int64 v6; // r15
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  hkSimdFloat32 v11; // xmm0
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  hkpConstraintInstance *v15; // r13
  hkBaseObjectVtbl *v16; // rax
  int v17; // esi
  void *(__fastcall *v18)(hkBaseObject *, unsigned int); // rcx
  __int64 v19; // rax
  hkpVelocityAccumulator *accumBase; // rdi
  hkpVelocityAccumulator *v21; // rax
  hkTransformf *v22; // rax
  hkpJacobianSchema *v23; // rcx
  hkp1Lin2AngJacobian *jacobiansEnd; // rax
  signed __int64 v25; // r10
  hkp1Lin2AngJacobian *v26; // r14
  hkTransformf *v27; // rcx
  int v28; // er8
  __int64 v29; // rsi
  int v30; // ebx
  int v31; // ebx
  hkpVelocityAccumulatorOffset *v32; // r9
  hkpBallSocketChainData::ConstraintInfo *v33; // rdx
  __m128 v34; // xmm1
  __m128 v35; // xmm1
  hkVector4f posB; // [rsp+50h] [rbp-B0h]
  __int64 v37; // [rsp+60h] [rbp-A0h]
  hkpConstraintQueryIn in; // [rsp+70h] [rbp-90h]
  hkVector4f posA; // [rsp+100h] [rbp+0h]
  hkpVelocityAccumulatorOffset *array; // [rsp+110h] [rbp+10h]
  int v41; // [rsp+118h] [rbp+18h]
  int v42; // [rsp+11Ch] [rbp+1Ch]
  int v43; // [rsp+120h] [rbp+20h]
  int v44; // [rsp+1F0h] [rbp+F0h]
  hkpConstraintQueryIn *v45; // [rsp+1F8h] [rbp+F8h]
  hkpConstraintQueryOut *v46; // [rsp+200h] [rbp+100h]
  signed __int64 v47; // [rsp+208h] [rbp+108h]

  v46 = out;
  v45 = inChain;
  v3 = out;
  v4 = inChain;
  v5 = this;
  v4->m_beginConstraints(v4, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  v42 = -2147483616;
  v6 = 0i64;
  v7 = *(_OWORD *)&v4->m_subStepDeltaTime.m_storage;
  v8 = *(_OWORD *)&v4->m_frameInvDeltaTime.m_storage;
  v41 = 0;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v7;
  v9 = *(_OWORD *)&v4->m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v8;
  array = (hkpVelocityAccumulatorOffset *)&v43;
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
  v15 = v4->m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_constraintInstance.m_storage = v14;
  in.m_constraintInstance.m_storage = 0i64;
  v16 = v15[1].vfptr;
  v17 = *(_DWORD *)&v15[1].m_memSizeAndFlags - 1;
  v44 = *(_DWORD *)&v15[1].m_memSizeAndFlags - 1;
  v18 = v16->__vecDelDtor;
  v19 = *((unsigned int *)v16->__vecDelDtor + 60);
  accumBase = (hkpVelocityAccumulator *)((char *)v4->m_bodyA.m_storage - v15->m_entities[0]->m_solverData);
  v41 = 1;
  LODWORD(in.m_virtMassFactor.m_storage) = (_DWORD)FLOAT_1_0;
  v21 = (hkpVelocityAccumulator *)((char *)accumBase + v19);
  in.m_bodyB.m_storage = v21;
  v43 = (_DWORD)v21 - (_DWORD)accumBase;
  v22 = (hkTransformf *)((char *)v18 + 368);
  v23 = v3->m_jacobianSchemas.m_storage;
  in.m_transformB.m_storage = v22;
  in.m_rhsFactor.m_storage = in.m_subStepInvDeltaTime.m_storage;
  jacobiansEnd = hkJacobianBallSocketChainSchema_getJacobians(v23);
  v37 = v17;
  if ( v17 > 0 )
  {
    v25 = 0i64;
    v26 = jacobiansEnd;
    v47 = 0i64;
    do
    {
      v27 = in.m_transformB.m_storage;
      v28 = v41;
      in.m_bodyA.m_storage = in.m_bodyB.m_storage;
      in.m_transformA.m_storage = in.m_transformB.m_storage;
      v29 = *((_QWORD *)&v15[1].vfptr->__first_virtual_table_function__ + v6);
      v30 = (_DWORD)accumBase + *(_DWORD *)(v29 + 240);
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)accumBase + *(unsigned int *)(v29 + 240));
      v31 = v30 - (_DWORD)accumBase;
      if ( v41 == (v42 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
        v27 = in.m_transformA.m_storage;
        v28 = v41;
        v25 = v47;
      }
      v32 = &array[v28];
      if ( v32 )
      {
        v32->m_offset = v31;
        v27 = in.m_transformA.m_storage;
        v28 = v41;
      }
      v33 = v5->m_infos.m_data;
      v41 = v28 + 1;
      in.m_transformB.m_storage = (hkTransformf *)(v29 + 368);
      v34 = *(__m128 *)((char *)&v33->m_pivotInA.m_quad + v25);
      posA.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v27->m_rotation.m_col1.m_quad),
                          _mm_mul_ps(
                            _mm_shuffle_ps(*(__m128 *)((char *)&v33->m_pivotInA.m_quad + v25), v34, 0),
                            v27->m_rotation.m_col0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v27->m_rotation.m_col2.m_quad)),
                      v27->m_translation.m_quad);
      v35 = *(__m128 *)((char *)&v33->m_pivotInB.m_quad + v25);
      posB.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), *(__m128 *)(v29 + 384)),
                          _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), *(__m128 *)(v29 + 368))),
                        _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), *(__m128 *)(v29 + 400))),
                      *(__m128 *)(v29 + 416));
      hkBallSocketConstraintBuildJacobian_noSchema_Proj(&posA, &posB, &in, v26);
      v25 = v47 + 32;
      ++v6;
      v26 += 3;
      v47 += 32i64;
    }
    while ( v6 < v37 );
    v3 = v46;
    v17 = v44;
    posB.m_quad.m128_u64[0] = (unsigned __int64)v26;
    v4 = v45;
    jacobiansEnd = (hkp1Lin2AngJacobian *)posB.m_quad.m128_u64[0];
  }
  hkBallSocketChainBuildJacobian(v17, v5->m_tau, v5->m_damping, v5->m_cfm, array, accumBase, jacobiansEnd, v4, v3);
  v41 = 0;
  if ( v42 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v42);
}

// File Line: 241
// RVA: 0xD75790
void __fastcall hkpBallSocketChainData::buildJacobian_Stabilized(hkpBallSocketChainData *this, hkpConstraintQueryIn *inChain, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryOut *v3; // rbx
  hkpConstraintQueryIn *v4; // rsi
  hkpBallSocketChainData *v5; // r15
  __int64 v6; // r12
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  hkSimdFloat32 v11; // xmm0
  __int128 v12; // xmm1
  __int128 cfm; // xmm0
  __int128 damping; // xmm1
  hkpConstraintInstance *v15; // r13
  float v16; // xmm3_4
  float virtualMassFactor; // ST30_4
  hkBaseObjectVtbl *v18; // rax
  int v19; // er14
  void *(__fastcall *v20)(hkBaseObject *, unsigned int); // rcx
  __int64 v21; // rax
  hkpVelocityAccumulator *v22; // rdi
  hkpVelocityAccumulator *v23; // rax
  hkTransformf *v24; // rax
  hkpJacobianSchema *v25; // rcx
  hkpJacobianSchema *v26; // rax
  __int64 v27; // rsi
  hkTransformf *v28; // rcx
  int v29; // er8
  __int64 v30; // r14
  int v31; // ebx
  int v32; // ebx
  hkpVelocityAccumulatorOffset *v33; // r9
  hkpBallSocketChainData::ConstraintInfo *v34; // rdx
  hkVector4f v35; // xmm1
  hkVector4f v36; // xmm0
  hkVector4f v37; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  hkpBallSocketConstraintAtom v40; // [rsp+50h] [rbp-A8h]
  hkpSetupStabilizationAtom atom; // [rsp+60h] [rbp-98h]
  hkpConstraintQueryOut outa; // [rsp+70h] [rbp-88h]
  hkVector4f vLocalArmB; // [rsp+88h] [rbp-70h]
  hkSimdFloat32 maxAngularImpulse; // [rsp+98h] [rbp-60h]
  hkVector4f vLocalArmA; // [rsp+A8h] [rbp-50h]
  hkpConstraintQueryIn in; // [rsp+B8h] [rbp-40h]
  hkSimdFloat32 maxLinearImpulse; // [rsp+148h] [rbp+50h]
  hkpVelocityAccumulatorOffset *array; // [rsp+158h] [rbp+60h]
  int v49; // [rsp+160h] [rbp+68h]
  int v50; // [rsp+164h] [rbp+6Ch]
  hkpVelocityAccumulatorOffset accumulatorsIn; // [rsp+168h] [rbp+70h]
  hkTransformf baseB; // [rsp+1E8h] [rbp+F0h]
  hkTransformf baseA; // [rsp+228h] [rbp+130h]
  signed int retaddr; // [rsp+2C8h] [rbp+1D0h]
  hkpConstraintQueryIn *v55; // [rsp+2D0h] [rbp+1D8h]
  hkpConstraintQueryIn *v56; // [rsp+2D8h] [rbp+1E0h]
  int v57; // [rsp+2E0h] [rbp+1E8h]

  v56 = inChain;
  v3 = out;
  v4 = inChain;
  v5 = this;
  inChain->m_beginConstraints(inChain, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  v50 = -2147483616;
  v6 = 0i64;
  v7 = *(_OWORD *)&v4->m_subStepDeltaTime.m_storage;
  v8 = *(_OWORD *)&v4->m_frameInvDeltaTime.m_storage;
  v49 = 0;
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
  v3->m_constraintRuntime.m_storage = 0i64;
  v15 = v4->m_constraintInstance.m_storage;
  v16 = v5->m_tau;
  virtualMassFactor = v4->m_virtMassFactor.m_storage;
  *(float *)&cfm = v5->m_cfm;
  *(_OWORD *)&in.m_constraintInstance.m_storage = damping;
  *(float *)&damping = v5->m_damping;
  in.m_constraintInstance.m_storage = 0i64;
  v18 = v15[1].vfptr;
  v19 = *(_DWORD *)&v15[1].m_memSizeAndFlags - 1;
  v57 = *(_DWORD *)&v15[1].m_memSizeAndFlags - 1;
  v20 = v18->__vecDelDtor;
  v21 = *((unsigned int *)v18->__vecDelDtor + 60);
  v22 = (hkpVelocityAccumulator *)((char *)v4->m_bodyA.m_storage - v15->m_entities[0]->m_solverData);
  v49 = 1;
  v23 = (hkpVelocityAccumulator *)((char *)v22 + v21);
  in.m_virtMassFactor.m_storage = 1.0;
  outa.m_constraintRuntime.m_storage = 0i64;
  in.m_bodyB.m_storage = v23;
  accumulatorsIn.m_offset = (_DWORD)v23 - (_DWORD)v22;
  v24 = (hkTransformf *)((char *)v20 + 368);
  v25 = v3->m_jacobianSchemas.m_storage;
  in.m_transformB.m_storage = v24;
  in.m_rhsFactor.m_storage = in.m_subStepInvDeltaTime.m_storage;
  outa.m_jacobianSchemas.m_storage = v3->m_jacobianSchemas.m_storage;
  outa.m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)v3->m_constraintRuntimeInMainMemory.m_storage;
  v26 = hkJacobianStabilizedBallSocketChainSchema_init(
          v25,
          v19,
          &accumulatorsIn,
          v16,
          *(float *)&damping,
          *(float *)&cfm,
          virtualMassFactor);
  outa.m_jacobianSchemas.m_storage = v26;
  outa.m_constraintRuntimeInMainMemory.m_storage = (void *)v19;
  if ( v19 > 0 )
  {
    v27 = 0i64;
    do
    {
      v28 = in.m_transformB.m_storage;
      v29 = v49;
      in.m_bodyA.m_storage = in.m_bodyB.m_storage;
      in.m_transformA.m_storage = in.m_transformB.m_storage;
      v30 = *((_QWORD *)&v15[1].vfptr->__first_virtual_table_function__ + v6);
      v31 = (_DWORD)v22 + *(_DWORD *)(v30 + 240);
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v22 + *(unsigned int *)(v30 + 240));
      v32 = v31 - (_DWORD)v22;
      if ( v49 == (v50 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
        v28 = in.m_transformA.m_storage;
        v29 = v49;
      }
      v33 = &array[v29];
      if ( v33 )
      {
        v33->m_offset = v32;
        v28 = in.m_transformA.m_storage;
        v29 = v49;
      }
      v34 = v5->m_infos.m_data;
      v49 = v29 + 1;
      in.m_transformB.m_storage = (hkTransformf *)(v30 + 368);
      atom.m_type.m_storage = 23;
      baseA.m_rotation.m_col0 = v28->m_rotation.m_col0;
      v35.m_quad = (__m128)v28->m_rotation.m_col1;
      atom.m_maxLinImpulse = 3.40282e38;
      atom.m_maxAngImpulse = 3.40282e38;
      atom.m_maxAngle = 1.8446726e19;
      baseA.m_rotation.m_col1 = (hkVector4f)v35.m_quad;
      v36.m_quad = (__m128)v28->m_rotation.m_col2;
      atom.m_enabled.m_bool = 1;
      *(_DWORD *)&v40.m_type.m_storage = 65541;
      retaddr = 1065353216;
      baseA.m_rotation.m_col2 = (hkVector4f)v36.m_quad;
      baseA.m_translation = v28->m_translation;
      baseB.m_rotation.m_col0 = *(hkVector4f *)(v30 + 368);
      baseB.m_rotation.m_col1 = *(hkVector4f *)(v30 + 384);
      baseB.m_rotation.m_col2 = *(hkVector4f *)(v30 + 400);
      v37.m_quad = *(__m128 *)(v30 + 416);
      maxAngularImpulse.m_real = (__m128)xmmword_141A712A0;
      _mm_store_si128((__m128i *)&maxLinearImpulse, (__m128i)xmmword_141A712A0);
      baseB.m_translation = (hkVector4f)v37.m_quad;
      vLocalArmA.m_quad = 0i64;
      vLocalArmB.m_quad = 0i64;
      v38 = v34[v27].m_pivotInA.m_quad;
      baseA.m_translation.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), v28->m_rotation.m_col1.m_quad),
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v34[v27].m_pivotInA.m_quad, v38, 0),
                                           v28->m_rotation.m_col0.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v28->m_rotation.m_col2.m_quad)),
                                     v28->m_translation.m_quad);
      v39 = v34[v27].m_pivotInB.m_quad;
      baseB.m_translation.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), *(__m128 *)(v30 + 384)),
                                         _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), *(__m128 *)(v30 + 368))),
                                       _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), *(__m128 *)(v30 + 400))),
                                     *(__m128 *)(v30 + 416));
      hkUFloat8::operator=(&v40.m_velocityStabilizationFactor, (const float *)&retaddr);
      v40.m_enableLinearImpulseLimit.m_bool = 0;
      *(_QWORD *)&v40.m_breachImpulse = 2139095022i64;
      v40.m_solvingMethod.m_storage = 0;
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
        &v40,
        &in,
        &baseA,
        &baseB,
        &vLocalArmA,
        &vLocalArmB,
        &maxAngularImpulse,
        &maxLinearImpulse,
        &outa);
      ++v6;
      ++v27;
    }
    while ( v6 < (_QWORD)outa.m_constraintRuntimeInMainMemory.m_storage );
    v26 = outa.m_jacobianSchemas.m_storage;
    v4 = v55;
    v3 = (hkpConstraintQueryOut *)v56;
    v19 = v57;
  }
  hkStabilizedBallSocketChainBuildJacobian(
    v19,
    v5->m_tau,
    v5->m_damping,
    v5->m_cfm,
    array,
    v22,
    (hkpChainLinkData *)v26,
    v4,
    v3);
  v49 = 0;
  if ( v50 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v50);
}

