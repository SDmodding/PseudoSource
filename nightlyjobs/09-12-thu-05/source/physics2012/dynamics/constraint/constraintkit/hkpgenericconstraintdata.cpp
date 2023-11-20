// File Line: 26
// RVA: 0xD51870
void __fastcall hkpGenericConstraintData::hkpGenericConstraintData(hkpGenericConstraintData *this)
{
  hkpGenericConstraintData *v1; // rbx
  hkpBridgeConstraintAtom *v2; // rcx

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  v2 = &this->m_atoms.m_bridgeAtom;
  *(_QWORD *)&v2[-1].m_type.m_storage = &hkpGenericConstraintData::`vftable';
  v2->m_type.m_storage = 1;
  v1->m_scheme.m_data.m_data = 0i64;
  v1->m_scheme.m_data.m_size = 0;
  v1->m_scheme.m_data.m_capacityAndFlags = 2147483648;
  v1->m_scheme.m_commands.m_data = 0i64;
  v1->m_scheme.m_commands.m_size = 0;
  v1->m_scheme.m_commands.m_capacityAndFlags = 2147483648;
  v1->m_scheme.m_modifiers.m_data = 0i64;
  v1->m_scheme.m_modifiers.m_size = 0;
  v1->m_scheme.m_modifiers.m_capacityAndFlags = 2147483648;
  v1->m_scheme.m_motors.m_data = 0i64;
  v1->m_scheme.m_motors.m_size = 0;
  v1->m_scheme.m_motors.m_capacityAndFlags = 2147483648;
  v1->m_scheme.m_info.m_maxSizeOfSchema = 0;
  *(_QWORD *)&v1->m_scheme.m_info.m_numSolverResults = 0i64;
  v1->m_scheme.m_info.m_sizeOfSchemas = 32;
  hkpBridgeConstraintAtom::init(v2, (hkpConstraintData *)&v1->vfptr);
}

// File Line: 33
// RVA: 0xD52640
void __fastcall hkpGenericConstraintData::hkpGenericConstraintData(hkpGenericConstraintData *this, hkFinishLoadedObjectFlag f)
{
  hkpGenericConstraintData *v2; // rbx
  hkFinishLoadedObjectFlag v3; // edx
  int fa; // [rsp+38h] [rbp+10h]

  fa = f.m_finishing;
  v2 = this;
  hkpConstraintData::hkpConstraintData((hkpConstraintData *)&this->vfptr, f);
  v3.m_finishing = fa;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpGenericConstraintData::`vftable';
  if ( fa )
  {
    hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, v2->m_atoms.m_bridgeAtom.m_constraintData);
    v3.m_finishing = fa;
  }
  hkpGenericConstraintDataScheme::hkpGenericConstraintDataScheme(&v2->m_scheme, v3);
  if ( fa )
    hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, (hkpConstraintData *)&v2->vfptr);
}

// File Line: 42
// RVA: 0xD51910
void __fastcall hkpGenericConstraintData::~hkpGenericConstraintData(hkpGenericConstraintData *this)
{
  hkpGenericConstraintData *v1; // rbx
  int v2; // esi
  __int64 v3; // rdi
  int v4; // er8
  int v5; // er8
  int v6; // er8
  int v7; // er8

  this->vfptr = (hkBaseObjectVtbl *)&hkpGenericConstraintData::`vftable';
  v1 = this;
  v2 = 0;
  if ( this->m_scheme.m_motors.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_scheme.m_motors.m_data[v3]->vfptr);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_scheme.m_motors.m_size );
  }
  v4 = v1->m_scheme.m_motors.m_capacityAndFlags;
  v1->m_scheme.m_motors.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_scheme.m_motors.m_data,
      8 * v4);
  v1->m_scheme.m_motors.m_data = 0i64;
  v1->m_scheme.m_motors.m_capacityAndFlags = 2147483648;
  v5 = v1->m_scheme.m_modifiers.m_capacityAndFlags;
  v1->m_scheme.m_modifiers.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_scheme.m_modifiers.m_data,
      8 * v5);
  v1->m_scheme.m_modifiers.m_data = 0i64;
  v1->m_scheme.m_modifiers.m_capacityAndFlags = 2147483648;
  v6 = v1->m_scheme.m_commands.m_capacityAndFlags;
  v1->m_scheme.m_commands.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_scheme.m_commands.m_data,
      4 * v6);
  v1->m_scheme.m_commands.m_data = 0i64;
  v1->m_scheme.m_commands.m_capacityAndFlags = 2147483648;
  v7 = v1->m_scheme.m_data.m_capacityAndFlags;
  v1->m_scheme.m_data.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_scheme.m_data.m_data,
      16 * v7);
  v1->m_scheme.m_data.m_data = 0i64;
  v1->m_scheme.m_data.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 53
// RVA: 0xD525D0
void __fastcall hkpGenericConstraintData::getConstraintInfo(hkpGenericConstraintData *this, hkpConstraintData::ConstraintInfo *info)
{
  info->m_sizeOfAllAtoms = 32;
  info->m_atoms = (hkpConstraintAtom *)&this->m_atoms.m_bridgeAtom.m_type;
  *(_QWORD *)&info->m_maxSizeOfSchema = 0i64;
  *(_QWORD *)&info->m_numSolverResults = 0i64;
  info->m_maxSizeOfSchema = this->m_scheme.m_info.m_maxSizeOfSchema;
  info->m_sizeOfSchemas = this->m_scheme.m_info.m_sizeOfSchemas;
  info->m_numSolverResults = this->m_scheme.m_info.m_numSolverResults;
  info->m_numSolverElemTemps = this->m_scheme.m_info.m_numSolverElemTemps;
}

// File Line: 61
// RVA: 0xD52620
void __fastcall hkpGenericConstraintData::getRuntimeInfo(hkpGenericConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  int v3; // eax

  v3 = this->m_scheme.m_info.m_numSolverResults;
  infoOut->m_numSolverResults = v3;
  infoOut->m_sizeOfExternalRuntime = 8 * v3;
}

// File Line: 68
// RVA: 0xD52570
void __fastcall hkpGenericConstraintData::buildJacobian(hkpGenericConstraintData *this, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryOut *v3; // rbx
  hkpConstraintQueryIn *v4; // rdi
  hkpGenericConstraintData *v5; // rsi

  v3 = out;
  v4 = in;
  v5 = this;
  v4->m_beginConstraints(v4, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  hkpGenericConstraintData::hatchScheme(v5, &v5->m_scheme, v4, v3);
}

// File Line: 77
// RVA: 0xD51A70
hkVector4f *__fastcall hkpGenericConstraintData::getParameters(hkpGenericConstraintData *this, int parameterIndex)
{
  return &this->m_scheme.m_data.m_data[parameterIndex];
}

// File Line: 83
// RVA: 0xD51A90
void __fastcall hkpGenericConstraintData::setParameters(hkpGenericConstraintData *this, int parameterIndex, int numParameters, hkVector4f *newValues)
{
  hkpGenericConstraintData *v4; // r10
  signed __int64 v5; // rcx
  signed __int64 v6; // rdx
  signed __int64 v7; // rax
  signed __int64 v8; // rdx
  __m128 v9; // xmm0

  v4 = this;
  v5 = parameterIndex;
  v6 = parameterIndex + numParameters;
  if ( v5 < v6 )
  {
    v7 = v5;
    v8 = v6 - v5;
    do
    {
      v9 = newValues->m_quad;
      ++v7;
      ++newValues;
      v4->m_scheme.m_data.m_data[v7 - 1].m_quad = v9;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 98
// RVA: 0xD51B00
void __fastcall hkpGenericConstraintData::constrainAllLinearW(hkpGenericConstraintData *this, int **currentCommand, hkVector4f **currentData, hkpGenericConstraintDataScheme *scheme, hkpGenericConstraintDataParameters *vars, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkVector4f v7; // xmm1
  hkp1dLinearBilateralConstraintInfo info; // [rsp+20h] [rbp-38h]

  v7.m_quad = (__m128)vars->m_pivotBw;
  info.m_pivotA = vars->m_pivotAw;
  info.m_pivotB = (hkVector4f)v7.m_quad;
  info.m_constrainedDofW = (hkVector4f)transform.m_quad;
  hk1dLinearBilateralConstraintBuildJacobian(&info, in, out);
  info.m_constrainedDofW = (hkVector4f)direction.m_quad;
  hk1dLinearBilateralConstraintBuildJacobian(&info, in, out);
  info.m_constrainedDofW = (hkVector4f)stru_141A71280.m_quad;
  hk1dLinearBilateralConstraintBuildJacobian(&info, in, out);
  vars->m_currentResult += 3;
}

// File Line: 125
// RVA: 0xD526B0
float __fastcall calcDeltaAngleAroundAxis(int axis, hkpGenericConstraintDataParameters *vars)
{
  __int64 v2; // r8
  __int64 v3; // rcx
  __m128 v4; // xmm3
  __m128 v5; // xmm2
  __m128 v6; // xmm7
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  float result; // xmm0_4

  v2 = axis;
  v3 = hkGenericConstraintDataAxisOrder[axis + 1];
  v4 = *(&vars->m_pivotAw.m_quad + v3 + 5);
  v5 = _mm_mul_ps(*(&vars->m_pivotAw.m_quad + hkGenericConstraintDataAxisOrder[v2 + 2] + 8i64), v4);
  v6 = (__m128)COERCE_UNSIGNED_INT(
                 (float)(COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 170)));
  v7 = _mm_mul_ps(*(&vars->m_pivotAw.m_quad + v3 + 8), v4);
  v8 = _mm_rcp_ps((__m128)COERCE_UNSIGNED_INT(
                            (float)(COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 0)))
                          + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170))));
  v9 = _mm_mul_ps(v8, v6);
  v10 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v9), _mm_cmpltps(*(__m128 *)_xmm, v9));
  v11 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v9), v10), _mm_andnot_ps(v10, v9));
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v12, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v12, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v12, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v12, *(__m128 *)s3))),
          _mm_mul_ps(v11, *(__m128 *)t3));
  v14 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v11, *(__m128 *)_xmm), *(__m128 *)_xmm), v13), v10),
          _mm_andnot_ps(v10, v13));
  v15 = _mm_cmpleps((__m128)0i64, v8);
  LODWORD(result) = *(unsigned __int128 *)&_mm_andnot_ps(
                                             v15,
                                             _mm_add_ps(
                                               _mm_or_ps(_mm_and_ps(*(__m128 *)_xmm, v6), *(__m128 *)_xmm),
                                               v14)) | v14.m128_i32[0] & v15.m128_i32[0];
  return result;
}

// File Line: 327
// RVA: 0xD52890
void __fastcall hkpGenericConstraintData::setAngularMotorW(hkpGenericConstraintData *this, int **currentCommand, hkVector4f **currentData, hkpGenericConstraintDataScheme *scheme, hkpGenericConstraintDataParameters *vars, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkVector4f *v7; // r10
  hkpConstraintMotor *v8; // r15
  __int64 v9; // rdx
  __int64 v10; // rcx
  float v11; // xmm9_4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm7
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm8
  __m128 v19; // xmm4
  __m128 v20; // xmm6
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm6
  float v24; // xmm6_4
  float v25; // xmm1_4
  hkpJacobianSchema *v26; // rsi
  struct hkpConstraintRuntime *v27; // rbx
  hkpJacobianSchema *v28; // r8
  __int64 v29; // rax
  __int64 v30; // r10
  hkpConstraintMotorOutput output; // [rsp+20h] [rbp-98h]
  hkp1dBilateralConstraintStatus statusOut; // [rsp+38h] [rbp-80h]
  hkpConstraintQueryIn *v33; // [rsp+40h] [rbp-78h]
  __int64 v34; // [rsp+48h] [rbp-70h]
  int v35; // [rsp+50h] [rbp-68h]
  unsigned int v36; // [rsp+54h] [rbp-64h]

  ++*currentCommand;
  v7 = *currentData;
  ++*currentData;
  v8 = scheme->m_motors.m_data[v7->m_quad.m128_f32[0]];
  if ( v8 )
  {
    v9 = **currentCommand;
    v10 = hkGenericConstraintDataAxisOrder[v9 + 1];
    v11 = v7->m_quad.m128_f32[2];
    v12 = *(&vars->m_pivotAw.m_quad + v10 + 5);
    v13 = _mm_mul_ps(*(&vars->m_pivotAw.m_quad + hkGenericConstraintDataAxisOrder[v9 + 2] + 8i64), v12);
    v14 = _mm_sub_ps(
            (__m128)0i64,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)));
    v15 = _mm_mul_ps(*(&vars->m_pivotAw.m_quad + v10 + 8), v12);
    v16 = _mm_rcp_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170))));
    v17 = _mm_mul_ps(v16, v14);
    v18 = _mm_cmpleps((__m128)0i64, v16);
    v19 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v17), _mm_cmpltps(*(__m128 *)_xmm, v17));
    v20 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v17), v19), _mm_andnot_ps(v19, v17));
    v21 = _mm_mul_ps(v20, v20);
    v22 = _mm_mul_ps(
            _mm_rcp_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_rcp_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_rcp_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v21, *(__m128 *)s0)), *(__m128 *)t0),
                            _mm_add_ps(v21, *(__m128 *)s1))),
                        *(__m128 *)t1),
                      _mm_add_ps(v21, *(__m128 *)s2))),
                  *(__m128 *)t2),
                _mm_add_ps(v21, *(__m128 *)s3))),
            _mm_mul_ps(v20, *(__m128 *)t3));
    v23 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v20, *(__m128 *)_xmm), *(__m128 *)_xmm), v22), v19),
            _mm_andnot_ps(v19, v22));
    v24 = COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                v18,
                                                _mm_add_ps(
                                                  _mm_or_ps(_mm_and_ps(v14, *(__m128 *)_xmm), *(__m128 *)_xmm),
                                                  v23)) | v23.m128_i32[0] & v18.m128_i32[0])
        + 3.1415927;
    v25 = v24 - v7->m_quad.m128_f32[1];
    if ( v25 >= -3.1415927 )
    {
      if ( v25 > 3.1415927 )
        v11 = v11 + -1.0;
    }
    else
    {
      v11 = v11 + 1.0;
    }
    v7->m_quad.m128_f32[2] = v11;
    v7->m_quad.m128_f32[1] = v24;
    v26 = out->m_jacobianSchemas.m_storage;
    v27 = out->m_constraintRuntime.m_storage;
    v28 = out->m_jacobianSchemas.m_storage;
    v34 = 0i64;
    hk1dAngularVelocityMotorBeginJacobian(&vars->m_pivotAw + v9 + 5, in, (hkp2AngJacobian *)v28, &statusOut);
    v29 = vars->m_currentResult;
    v33 = in;
    v30 = *((_QWORD *)v27 + v29);
    v36 = COERCE_UNSIGNED_INT(v24 + (float)(v11 * 6.2831855)) ^ _xmm[0];
    v35 = 0;
    v34 = v30;
    hkCalcMotorData(v8, (hkpConstraintMotorInput *)&statusOut, &output);
    hk1dAngularVelocityMotorCommitJacobian(
      (hkp1dConstraintMotorInfo *)&output.m_targetPosition,
      in,
      (hkp2AngJacobian *)v26,
      out);
    ++vars->m_currentResult;
  }
  else
  {
    ++vars->m_currentResult;
  }
}

// File Line: 412
// RVA: 0xD52BB0
void __fastcall hkpGenericConstraintData::setLinearMotorW(hkpGenericConstraintData *this, int **currentCommand, hkVector4f **currentData, hkpGenericConstraintDataScheme *scheme, hkpGenericConstraintDataParameters *vars, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkVector4f *v7; // rcx
  hkpConstraintMotor *v8; // r15
  hkpGenericConstraintDataParameters *v9; // rbp
  __m128 v10; // xmm1
  hkpJacobianSchema *v11; // rdi
  struct hkpConstraintRuntime *v12; // rsi
  __m128 v13; // xmm1
  hkpSolverResults v14; // r10
  __m128 v15; // [rsp+30h] [rbp-78h]
  hkpConstraintMotorOutput output; // [rsp+40h] [rbp-68h]
  hkpConstraintMotorInput input; // [rsp+58h] [rbp-50h]

  ++*currentCommand;
  v7 = *currentData;
  ++*currentData;
  v8 = scheme->m_motors.m_data[v7->m_quad.m128_f32[0]];
  if ( v8 )
  {
    v9 = vars;
    v10 = _mm_sub_ps(v9->m_pivotAw.m_quad, v9->m_pivotBw.m_quad);
    v11 = out->m_jacobianSchemas.m_storage;
    v12 = out->m_constraintRuntime.m_storage;
    v15 = *(&vars->m_pivotAw.m_quad + **currentCommand + 2i64);
    v13 = _mm_mul_ps(v10, v15);
    input.m_lastResults = 0i64;
    hk1dLinearVelocityMotorBeginJacobian(
      (hkVector4f *)&v15,
      &vars->m_pivotBw,
      in,
      (hkp1Lin2AngJacobian *)v11,
      (hkp1dBilateralConstraintStatus *)&input.m_effMass);
    v14 = (hkpSolverResults)*((_QWORD *)v12 + vars->m_currentResult);
    LODWORD(input.m_positionError.m_storage) = COERCE_UNSIGNED_INT(
                                                 (float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) ^ _xmm[0];
    input.m_deltaTarget.m_storage = 0.0;
    input.m_stepInfo.m_storage = (hkpConstraintQueryStepInfo *)&in->m_subStepDeltaTime;
    input.m_lastResults = v14;
    hkCalcMotorData(v8, &input, &output);
    hk1dLinearVelocityMotorCommitJacobian(
      (hkp1dConstraintMotorInfo *)&output.m_targetPosition,
      in,
      (hkp1Lin2AngJacobian *)v11,
      out);
    ++v9->m_currentResult;
  }
  else
  {
    ++vars->m_currentResult;
  }
}

// File Line: 483
// RVA: 0xD51BB0
void __fastcall hkpGenericConstraintData::setLinearFrictionW(hkpGenericConstraintData *this, int **currentCommand, hkVector4f **currentData, hkpGenericConstraintDataScheme *scheme, hkpGenericConstraintDataParameters *vars, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpGenericConstraintDataParameters *v7; // rbx
  struct hkpConstraintRuntime *v8; // r9
  hkVector4f v9; // xmm0
  hkVector4f *v10; // rcx
  __int64 v11; // rax
  hkp1dLinearFrictionInfo info; // [rsp+20h] [rbp-38h]

  v7 = vars;
  v8 = out->m_constraintRuntime.m_storage;
  ++*currentCommand;
  v9.m_quad = (__m128)*((_OWORD *)&vars->m_pivotAw + **currentCommand + 2i64);
  v10 = *currentData;
  info.m_pivot.m_quad = _mm_sub_ps(v7->m_pivotAw.m_quad, v7->m_pivotBw.m_quad);
  info.m_constrainedDofW = (hkVector4f)v9.m_quad;
  *currentData = v10 + 1;
  v11 = vars->m_currentResult;
  LODWORD(info.m_maxFrictionForce.m_storage) = v10->m_quad.m128_i32[0];
  info.m_lastSolverResults.m_storage = (hkpSolverResults *)((char *)v8 + 8 * v11);
  hk1dLinearFrictionBuildJacobian(&info, in, out);
  ++v7->m_currentResult;
}

// File Line: 504
// RVA: 0xD51C40
void __fastcall hkpGenericConstraintData::hatchScheme(hkpGenericConstraintData *this, hkpGenericConstraintDataScheme *scheme, hkpConstraintQueryIn *inOrig, hkpConstraintQueryOut *out)
{
  __m128i v4; // xmm2
  __int128 v5; // xmm0
  __int128 v6; // xmm1
  hkVector4f *v7; // rbx
  int *v8; // rdi
  hkpConstraintModifier **v9; // r13
  hkpGenericConstraintDataScheme *v10; // r15
  hkpConstraintQueryOut *v11; // rsi
  hkpConstraintQueryIn *v12; // r14
  __int128 v13; // xmm0
  hkpGenericConstraintData *v14; // r12
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  hkSimdFloat32 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  int v20; // eax
  __m128 *v21; // rax
  signed int *v22; // rdi
  __int64 v23; // rax
  hkVector4f v24; // xmm0
  __int64 v25; // rax
  hkMatrix3f *v26; // r8
  hkMatrix3f *v27; // r8
  __int64 v28; // rcx
  __int64 v29; // rax
  hkVector4f v30; // xmm1
  __int64 v31; // rax
  __int128 v32; // xmm0
  int *v33; // rax
  __int64 v34; // rcx
  float v35; // xmm0_4
  hkVector4f *v36; // rax
  float v37; // xmm3_4
  bool v38; // cf
  bool v39; // zf
  float v40; // xmm1_4
  __int64 v41; // rcx
  __m128 v42; // xmm5
  __m128 v43; // xmm7
  __m128 v44; // xmm4
  __m128 v45; // xmm4
  __m128 v46; // xmm3
  __m128 v47; // xmm5
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  unsigned __int64 *v50; // rax
  __int64 v51; // rax
  __int64 v52; // rdx
  hkVector4f *v53; // rax
  int v54; // xmm0_4
  struct hkpConstraintRuntime *v55; // rax
  float *v56; // rax
  __int64 v57; // r8
  hkp1dAngularBilateralConstraintInfo info; // [rsp+40h] [rbp-88h]
  hkpGenericConstraintDataParameters vars; // [rsp+70h] [rbp-58h]
  hkpConstraintQueryIn in; // [rsp+148h] [rbp+80h]
  hkVector4f *currentData; // [rsp+240h] [rbp+178h]
  int *currentCommand; // [rsp+248h] [rbp+180h]

  v4 = *(__m128i *)&inOrig->m_transformA.m_storage;
  v5 = *(_OWORD *)&inOrig->m_subStepDeltaTime.m_storage;
  v6 = *(_OWORD *)&inOrig->m_frameInvDeltaTime.m_storage;
  v7 = scheme->m_data.m_data;
  v8 = scheme->m_commands.m_data;
  v9 = scheme->m_modifiers.m_data;
  vars.m_rbA = (hkTransformf *)*(_OWORD *)&inOrig->m_transformA.m_storage;
  v10 = scheme;
  v11 = out;
  v12 = inOrig;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v5;
  v13 = *(_OWORD *)&inOrig->m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v6;
  v14 = this;
  vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2] = 0;
  currentData = v7;
  v15 = *(_OWORD *)&inOrig->m_bodyA.m_storage;
  *(_OWORD *)&in.m_rhsFactor.m_storage = v13;
  v16 = *(_OWORD *)&inOrig->m_tau.m_storage;
  *(_OWORD *)&in.m_bodyA.m_storage = v15;
  v17.m_real = (__m128)inOrig->m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_tau.m_storage = v16;
  v18 = *(_OWORD *)&inOrig->m_constraintInstance.m_storage;
  in.m_maxConstraintViolationSqrd = (hkSimdFloat32)v17.m_real;
  v19 = *(_OWORD *)&inOrig->m_accumulatorAIndex.m_storage;
  *(__m128i *)&in.m_transformA.m_storage = v4;
  *(_OWORD *)&in.m_constraintInstance.m_storage = v18;
  vars.m_rbB = (hkTransformf *)_mm_srli_si128(v4, 8);
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = v19;
  while ( 1 )
  {
    v20 = *v8;
    currentCommand = v8;
    switch ( v20 )
    {
      case 0:
        return;
      case 1:
        hkVector4f::setTransformedPos(
          &vars.m_pivotAw,
          (hkTransformf *)vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1],
          v7);
        ++v7;
        currentData = v7;
        ++v8;
        continue;
      case 2:
        hkVector4f::setTransformedPos(
          (hkVector4f *)((char *)&info.m_zeroErrorAxisAinW + 8),
          (hkTransformf *)vars.m_angularBasisBw.m_col0.m_quad.m128_u64[0],
          v7);
        ++v7;
        currentData = v7;
        ++v8;
        continue;
      case 3:
        v21 = (__m128 *)vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1];
        goto LABEL_4;
      case 4:
        v21 = (__m128 *)vars.m_angularBasisBw.m_col0.m_quad.m128_u64[0];
LABEL_4:
        v22 = v8 + 1;
        *(__m128 *)((char *)&info.m_constrainedDofW.m_quad + 16 * *v22 + 8) = _mm_add_ps(
                                                                                _mm_add_ps(
                                                                                  _mm_mul_ps(
                                                                                    _mm_shuffle_ps(
                                                                                      v7->m_quad,
                                                                                      v7->m_quad,
                                                                                      85),
                                                                                    v21[1]),
                                                                                  _mm_mul_ps(
                                                                                    _mm_shuffle_ps(
                                                                                      v7->m_quad,
                                                                                      v7->m_quad,
                                                                                      0),
                                                                                    *v21)),
                                                                                _mm_mul_ps(
                                                                                  _mm_shuffle_ps(
                                                                                    v7->m_quad,
                                                                                    v7->m_quad,
                                                                                    170),
                                                                                  v21[2]));
        goto LABEL_5;
      case 5:
        v23 = v8[1];
        v24.m_quad = v7->m_quad;
        ++v7;
        v8 += 2;
        currentData = v7;
        *(hkVector4f *)((char *)&info.m_constrainedDofW + 16 * v23 + 8) = (hkVector4f)v24.m_quad;
        continue;
      case 6:
        v25 = v8[1];
        *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col1 + 8) = vars.m_pivotAw;
        *(hkVector4f *)&vars.m_rbB = *(hkVector4f *)((char *)&info.m_constrainedDofW + 16 * v25 + 8);
        *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col2 + 8) = *(hkVector4f *)((char *)&info.m_zeroErrorAxisAinW
                                                                                   + 8);
        hk1dLinearBilateralConstraintBuildJacobian(
          (hkp1dLinearBilateralConstraintInfo *)&vars.m_angularBasisBw.m_col1.m_quad.m128_u16[4],
          &in,
          v11);
        ++vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
        v8 += 2;
        continue;
      case 7:
        hkpGenericConstraintData::constrainAllLinearW(v14, &currentCommand, &currentData, v10, &vars, &in, v11);
        ++v8;
        continue;
      case 8:
        v26 = (hkMatrix3f *)v7;
        v7 += 3;
        currentData = v7;
        hkMatrix3f::setMul(
          (hkMatrix3f *)&vars.m_pivotBw.m_quad.m128_u16[4],
          (hkMatrix3f *)vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1],
          v26);
        ++v8;
        continue;
      case 9:
        v27 = (hkMatrix3f *)v7;
        v7 += 3;
        currentData = v7;
        hkMatrix3f::setMul(
          (hkMatrix3f *)&vars.m_linearBasisW.m_col2.m_quad.m128_u16[4],
          (hkMatrix3f *)vars.m_angularBasisBw.m_col0.m_quad.m128_u64[0],
          v27);
        ++v8;
        continue;
      case 10:
        ++v8;
        *(hkVector4f *)((char *)&vars.m_pivotBw + 8) = *(hkVector4f *)vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1];
        *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col0 + 8) = *(hkVector4f *)(vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1]
                                                                                 + 16);
        *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col1 + 8) = *(hkVector4f *)(vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1]
                                                                                 + 32);
        continue;
      case 11:
        ++v8;
        *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col2 + 8) = *(hkVector4f *)vars.m_angularBasisBw.m_col0.m_quad.m128_u64[0];
        *(hkVector4f *)((char *)&vars.m_angularBasisAw.m_col0 + 8) = *(hkVector4f *)(vars.m_angularBasisBw.m_col0.m_quad.m128_u64[0]
                                                                                   + 16);
        *(hkVector4f *)((char *)&vars.m_angularBasisAw.m_col1 + 8) = *(hkVector4f *)(vars.m_angularBasisBw.m_col0.m_quad.m128_u64[0]
                                                                                   + 32);
        continue;
      case 12:
        v28 = v8[1];
        v29 = hkGenericConstraintDataAxisOrder[v28 + 2];
        info.m_constrainedDofW = *(hkVector4f *)((char *)&vars.m_pivotBw
                                               + 16 * hkGenericConstraintDataAxisOrder[v28 + 1]
                                               + 8);
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&vars.m_pivotBw + 16 * v29 + 8);
        info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col2 + 16 * v28 + 8);
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, v11);
        v30.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       info.m_constrainedDofW.m_quad);
        info.m_constrainedDofW = info.m_zeroErrorAxisAinW;
        info.m_zeroErrorAxisAinW = (hkVector4f)v30.m_quad;
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, v11);
        vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2] += 2;
        v8 += 2;
        continue;
      case 13:
        *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col1 + 8) = *(hkVector4f *)((char *)&vars.m_pivotBw + 8);
        *(hkVector4f *)&vars.m_rbB = *(hkVector4f *)((char *)&vars.m_angularBasisAw.m_col0 + 8);
        *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col2 + 8) = *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col1
                                                                                   + 8);
        hk1dAngularBilateralConstraintBuildJacobian(
          (hkp1dAngularBilateralConstraintInfo *)&vars.m_angularBasisBw.m_col1.m_quad.m128_u16[4],
          &in,
          v11);
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col0 + 8);
        info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&vars.m_angularBasisAw.m_col1 + 8);
        info.m_constrainedDofW = *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col1 + 8);
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, v11);
        info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col2 + 8);
        info.m_constrainedDofW = info.m_zeroErrorAxisAinW;
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col2 + 8);
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, v11);
        vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2] += 3;
        ++v8;
        continue;
      case 14:
        hkpGenericConstraintData::setAngularMotorW(v14, &currentCommand, &currentData, v10, &vars, &in, v11);
        v7 = currentData;
        v8 = currentCommand + 1;
        continue;
      case 15:
        hkpGenericConstraintData::setLinearMotorW(v14, &currentCommand, &currentData, v10, &vars, &in, v11);
        v7 = currentData;
        v8 = currentCommand + 1;
        continue;
      case 16:
        v31 = v8[1];
        *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col1 + 8) = vars.m_pivotAw;
        v32 = *(__int128 *)((char *)&info.m_constrainedDofW + 16 * v31 + 8);
        v33 = (int *)v7;
        ++v7;
        *(_OWORD *)&vars.m_rbB = v32;
        currentData = v7;
        *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col2 + 8) = *(hkVector4f *)((char *)&info.m_zeroErrorAxisAinW
                                                                                   + 8);
        *(&vars.m_currentResult + 2) = *v33;
        *(&vars.m_currentResult + 3) = v33[1];
        hk1dLinearLimitBuildJacobian((hkp1dLinearLimitInfo *)&vars.m_angularBasisBw.m_col1.m_quad.m128_u16[4], &in, v11);
        ++vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
        v8 += 2;
        continue;
      case 17:
        v34 = v8[1];
        v22 = v8 + 1;
        info.m_constrainedDofW.m_quad.m128_i32[3] = 1056964608;
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&vars.m_pivotBw + 16 * v34 + 8);
        v35 = calcDeltaAngleAroundAxis(v34, &vars);
        v36 = v7;
        ++v7;
        currentData = v7;
        v37 = v35;
        v38 = v35 < 0.0;
        v39 = v35 == 0.0;
        info.m_constrainedDofW.m_quad.m128_f32[2] = v35;
        info.m_constrainedDofW.m_quad.m128_u64[0] = v36->m_quad.m128_u64[0];
        v40 = v36->m_quad.m128_f32[2];
        if ( v35 < 0.0 )
        {
          if ( v40 > 0.0 && (float)(v40 - v35) > 3.1415927 )
          {
            v37 = v35 + 6.2831855;
            info.m_constrainedDofW.m_quad.m128_f32[2] = v35 + 6.2831855;
          }
          v38 = v37 < 0.0;
          v39 = v37 == 0.0;
        }
        if ( !v38 && !v39 && v40 < 0.0 && (float)(v37 - v40) > 3.1415927 )
        {
          v37 = v37 + -6.2831855;
          info.m_constrainedDofW.m_quad.m128_f32[2] = v37;
        }
        v36->m_quad.m128_f32[2] = v37;
        goto LABEL_27;
      case 18:
        v41 = v8[1];
        v22 = v8 + 1;
        info.m_constrainedDofW.m_quad.m128_i32[3] = 1056964608;
        v41 *= 2i64;
        v42 = *(__m128 *)((char *)&vars.m_pivotBw.m_quad + 8 * v41 + 8);
        v43 = *(__m128 *)((char *)&vars.m_linearBasisW.m_col2.m_quad + 8 * v41 + 8);
        v44 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v42), _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v43));
        v45 = _mm_shuffle_ps(v44, v44, 201);
        v46 = _mm_mul_ps(v45, v45);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 170))) < 0.00000011920929 )
        {
LABEL_5:
          ++v7;
          v8 = v22 + 1;
          currentData = v7;
        }
        else
        {
          v47 = _mm_mul_ps(v42, v43);
          v48 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                  _mm_shuffle_ps(v46, v46, 170));
          v49 = _mm_rsqrt_ps(v48);
          info.m_zeroErrorAxisAinW.m_quad = _mm_mul_ps(
                                              v45,
                                              _mm_andnot_ps(
                                                _mm_cmpleps(v48, (__m128)0i64),
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v49))));
          info.m_constrainedDofW.m_quad.m128_f32[2] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85))
                                                            + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0)))
                                                    + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170));
LABEL_30:
          v50 = (unsigned __int64 *)v7;
          ++v7;
          currentData = v7;
          info.m_constrainedDofW.m_quad.m128_u64[0] = *v50;
LABEL_27:
          hk1dAngularLimitBuildJacobian((hkp1dAngularLimitInfo *)&info, &in, v11);
          ++vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
          v8 = v22 + 1;
        }
        continue;
      case 19:
        v51 = v8[1];
        v52 = v8[2];
        v22 = v8 + 2;
        info.m_constrainedDofW.m_quad.m128_i32[3] = 1056964608;
        hkInternalConstraintUtils_calcRelativeAngle(
          (hkVector4f *)((char *)&vars.m_pivotBw + 16 * v51 + 8),
          (hkVector4f *)((char *)&vars.m_linearBasisW.m_col2 + 16 * v51 + 8),
          (hkVector4f *)((char *)&vars.m_pivotBw + 16 * v52 + 8),
          (hkVector4f *)((char *)&vars.m_linearBasisW.m_col2 + 16 * v52 + 8),
          &info.m_zeroErrorAxisAinW,
          (hkPadSpu<float> *)&info.m_constrainedDofW.m_quad.m128_u16[4]);
        goto LABEL_30;
      case 20:
        info.m_zeroErrorAxisAinW.m_quad.m128_u64[0] = (unsigned __int64)&vars.m_pivotBw.m_quad.m128_u64[2 * v8[1] + 1];
        v53 = v7;
        ++v7;
        currentData = v7;
        v54 = v53->m_quad.m128_i32[0];
        v55 = v11->m_constraintRuntime.m_storage;
        info.m_constrainedDofW.m_quad.m128_u64[0] = __PAIR__(1, v54);
        info.m_zeroErrorAxisAinW.m_quad.m128_u64[1] = (unsigned __int64)v55
                                                    + 8 * vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
        hk1dAngularFrictionBuildJacobian((hkp1dAngularFrictionInfo *)&info, &in, v11);
        ++vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
        v8 += 2;
        continue;
      case 21:
        hkpGenericConstraintData::setLinearFrictionW(v14, &currentCommand, &currentData, v10, &vars, &in, v11);
        v7 = currentData;
        v8 = currentCommand + 1;
        continue;
      case 22:
        v56 = (float *)v7;
        ++v7;
        currentData = v7;
        ++v8;
        in.m_virtMassFactor.m_storage = in.m_virtMassFactor.m_storage * *v56;
        continue;
      case 23:
        ++v8;
        in.m_virtMassFactor.m_storage = v12->m_virtMassFactor.m_storage;
        continue;
      case 24:
        v57 = (unsigned int)v8[1];
        ++v8;
        (*v9)->vfptr->modify(*v9, &vars, v57);
        ++v9;
        break;
      default:
        break;
    }
    ++v8;
  }
}

// File Line: 713
// RVA: 0xD51AF0
hkpGenericConstraintDataScheme *__fastcall hkpGenericConstraintData::getScheme(hkpGenericConstraintData *this)
{
  return &this->m_scheme;
}

// File Line: 718
// RVA: 0xD51AE0
hkBool *__fastcall hkpGenericConstraintData::isValid(hkpGenericConstraintData *this, hkBool *result)
{
  result->m_bool = 1;
  return result;
}

// File Line: 724
// RVA: 0xD52610
signed __int64 __fastcall hkpGenericConstraintData::getType(hkpGenericConstraintData *this)
{
  return 10i64;
}

