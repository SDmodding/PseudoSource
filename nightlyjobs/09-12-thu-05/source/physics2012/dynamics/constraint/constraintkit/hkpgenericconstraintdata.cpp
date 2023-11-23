// File Line: 26
// RVA: 0xD51870
void __fastcall hkpGenericConstraintData::hkpGenericConstraintData(hkpGenericConstraintData *this)
{
  hkpBridgeAtoms *p_m_atoms; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  p_m_atoms = &this->m_atoms;
  *(_QWORD *)&p_m_atoms[-1].m_bridgeAtom.m_type.m_storage = &hkpGenericConstraintData::`vftable;
  p_m_atoms->m_bridgeAtom.m_type.m_storage = 1;
  this->m_scheme.m_data.m_data = 0i64;
  this->m_scheme.m_data.m_size = 0;
  this->m_scheme.m_data.m_capacityAndFlags = 0x80000000;
  this->m_scheme.m_commands.m_data = 0i64;
  this->m_scheme.m_commands.m_size = 0;
  this->m_scheme.m_commands.m_capacityAndFlags = 0x80000000;
  this->m_scheme.m_modifiers.m_data = 0i64;
  this->m_scheme.m_modifiers.m_size = 0;
  this->m_scheme.m_modifiers.m_capacityAndFlags = 0x80000000;
  this->m_scheme.m_motors.m_data = 0i64;
  this->m_scheme.m_motors.m_size = 0;
  this->m_scheme.m_motors.m_capacityAndFlags = 0x80000000;
  this->m_scheme.m_info.m_maxSizeOfSchema = 0;
  *(_QWORD *)&this->m_scheme.m_info.m_numSolverResults = 0i64;
  this->m_scheme.m_info.m_sizeOfSchemas = 32;
  hkpBridgeConstraintAtom::init(&p_m_atoms->m_bridgeAtom, this);
}

// File Line: 33
// RVA: 0xD52640
void __fastcall hkpGenericConstraintData::hkpGenericConstraintData(
        hkpGenericConstraintData *this,
        hkFinishLoadedObjectFlag f)
{
  int m_finishing; // edx

  hkpConstraintData::hkpConstraintData(this, f);
  m_finishing = f.m_finishing;
  this->vfptr = (hkBaseObjectVtbl *)&hkpGenericConstraintData::`vftable;
  if ( f.m_finishing )
  {
    hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this->m_atoms.m_bridgeAtom.m_constraintData);
    m_finishing = f.m_finishing;
  }
  hkpGenericConstraintDataScheme::hkpGenericConstraintDataScheme(&this->m_scheme, (hkFinishLoadedObjectFlag)m_finishing);
  if ( f.m_finishing )
    hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this);
}

// File Line: 42
// RVA: 0xD51910
void __fastcall hkpGenericConstraintData::~hkpGenericConstraintData(hkpGenericConstraintData *this)
{
  int v2; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpGenericConstraintData::`vftable;
  v2 = 0;
  if ( this->m_scheme.m_motors.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_scheme.m_motors.m_data[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_scheme.m_motors.m_size );
  }
  m_capacityAndFlags = this->m_scheme.m_motors.m_capacityAndFlags;
  this->m_scheme.m_motors.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_scheme.m_motors.m_data,
      8 * m_capacityAndFlags);
  this->m_scheme.m_motors.m_data = 0i64;
  this->m_scheme.m_motors.m_capacityAndFlags = 0x80000000;
  v5 = this->m_scheme.m_modifiers.m_capacityAndFlags;
  this->m_scheme.m_modifiers.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_scheme.m_modifiers.m_data,
      8 * v5);
  this->m_scheme.m_modifiers.m_data = 0i64;
  this->m_scheme.m_modifiers.m_capacityAndFlags = 0x80000000;
  v6 = this->m_scheme.m_commands.m_capacityAndFlags;
  this->m_scheme.m_commands.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_scheme.m_commands.m_data,
      4 * v6);
  this->m_scheme.m_commands.m_data = 0i64;
  this->m_scheme.m_commands.m_capacityAndFlags = 0x80000000;
  v7 = this->m_scheme.m_data.m_capacityAndFlags;
  this->m_scheme.m_data.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_scheme.m_data.m_data,
      16 * v7);
  this->m_scheme.m_data.m_data = 0i64;
  this->m_scheme.m_data.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 53
// RVA: 0xD525D0
void __fastcall hkpGenericConstraintData::getConstraintInfo(
        hkpGenericConstraintData *this,
        hkpConstraintData::ConstraintInfo *info)
{
  info->m_sizeOfAllAtoms = 32;
  info->m_atoms = &this->m_atoms.m_bridgeAtom;
  *(_QWORD *)&info->m_maxSizeOfSchema = 0i64;
  *(_QWORD *)&info->m_numSolverResults = 0i64;
  info->m_maxSizeOfSchema = this->m_scheme.m_info.m_maxSizeOfSchema;
  info->m_sizeOfSchemas = this->m_scheme.m_info.m_sizeOfSchemas;
  info->m_numSolverResults = this->m_scheme.m_info.m_numSolverResults;
  info->m_numSolverElemTemps = this->m_scheme.m_info.m_numSolverElemTemps;
}

// File Line: 61
// RVA: 0xD52620
void __fastcall hkpGenericConstraintData::getRuntimeInfo(
        hkpGenericConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  int m_numSolverResults; // eax

  m_numSolverResults = this->m_scheme.m_info.m_numSolverResults;
  infoOut->m_numSolverResults = m_numSolverResults;
  infoOut->m_sizeOfExternalRuntime = 8 * m_numSolverResults;
}

// File Line: 68
// RVA: 0xD52570
void __fastcall hkpGenericConstraintData::buildJacobian(
        hkpGenericConstraintData *this,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  in->m_beginConstraints(in, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  hkpGenericConstraintData::hatchScheme(this, &this->m_scheme, in, out);
}

// File Line: 77
// RVA: 0xD51A70
hkVector4f *__fastcall hkpGenericConstraintData::getParameters(hkpGenericConstraintData *this, int parameterIndex)
{
  return &this->m_scheme.m_data.m_data[parameterIndex];
}

// File Line: 83
// RVA: 0xD51A90
void __fastcall hkpGenericConstraintData::setParameters(
        hkpGenericConstraintData *this,
        int parameterIndex,
        int numParameters,
        hkVector4f *newValues)
{
  __int64 v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // rax
  __int64 v8; // rdx
  __m128 m_quad; // xmm0

  v5 = parameterIndex;
  v6 = parameterIndex + numParameters;
  if ( v5 < v6 )
  {
    v7 = v5;
    v8 = v6 - v5;
    do
    {
      m_quad = newValues->m_quad;
      ++v7;
      ++newValues;
      this->m_scheme.m_data.m_data[v7 - 1].m_quad = m_quad;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 98
// RVA: 0xD51B00
void __fastcall hkpGenericConstraintData::constrainAllLinearW(
        hkpGenericConstraintData *this,
        int **currentCommand,
        hkVector4f **currentData,
        hkpGenericConstraintDataScheme *scheme,
        hkpGenericConstraintDataParameters *vars,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkVector4f v7; // xmm1
  hkp1dLinearBilateralConstraintInfo info; // [rsp+20h] [rbp-38h] BYREF

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
  v4 = *(&vars->m_angularBasisAw.m_col0.m_quad + v3);
  v5 = _mm_mul_ps(*(&vars->m_angularBasisBw.m_col0.m_quad + hkGenericConstraintDataAxisOrder[v2 + 2]), v4);
  v6 = (__m128)COERCE_UNSIGNED_INT(
                 (float)(_mm_shuffle_ps(v5, v5, 85).m128_f32[0] + _mm_shuffle_ps(v5, v5, 0).m128_f32[0])
               + _mm_shuffle_ps(v5, v5, 170).m128_f32[0]);
  v7 = _mm_mul_ps(*(&vars->m_angularBasisBw.m_col0.m_quad + v3), v4);
  v8 = _mm_rcp_ps((__m128)COERCE_UNSIGNED_INT(
                            (float)(_mm_shuffle_ps(v7, v7, 85).m128_f32[0] + _mm_shuffle_ps(v7, v7, 0).m128_f32[0])
                          + _mm_shuffle_ps(v7, v7, 170).m128_f32[0]));
  v9 = _mm_mul_ps(v8, v6);
  v10 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v9), _mm_cmplt_ps(*(__m128 *)_xmm, v9));
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
  v15 = _mm_cmple_ps((__m128)0i64, v8);
  LODWORD(result) = _mm_andnot_ps(v15, _mm_add_ps(_mm_or_ps(_mm_and_ps(*(__m128 *)_xmm, v6), *(__m128 *)_xmm), v14)).m128_u32[0] | v14.m128_i32[0] & v15.m128_i32[0];
  return result;
}

// File Line: 327
// RVA: 0xD52890
void __fastcall hkpGenericConstraintData::setAngularMotorW(
        hkpGenericConstraintData *this,
        int **currentCommand,
        hkVector4f **currentData,
        hkpGenericConstraintDataScheme *scheme,
        hkpGenericConstraintDataParameters *vars,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  __int128 v7; // xmm8
  hkVector4f *v8; // r10
  hkpConstraintMotor *v9; // r15
  __int64 v10; // rdx
  __int64 v11; // rcx
  float v12; // xmm9_4
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm7
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm6
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm0
  __m128 v24; // xmm6
  float v25; // xmm6_4
  float v26; // xmm1_4
  hkpJacobianSchema *m_storage; // rsi
  struct hkpConstraintRuntime *v28; // rbx
  hkpJacobianSchema *v29; // r8
  __int64 m_currentResult; // rax
  hkpSolverResults v31; // r10
  hkpConstraintMotorOutput output; // [rsp+20h] [rbp-98h] BYREF
  hkpConstraintMotorInput statusOut; // [rsp+38h] [rbp-80h] BYREF
  __int128 v34; // [rsp+70h] [rbp-48h]

  ++*currentCommand;
  v8 = (*currentData)++;
  v9 = scheme->m_motors.m_data[v8->m_quad.m128_f32[0]];
  if ( v9 )
  {
    v10 = **currentCommand;
    v11 = hkGenericConstraintDataAxisOrder[v10 + 1];
    v34 = v7;
    v12 = v8->m_quad.m128_f32[2];
    v13 = *(&vars->m_angularBasisAw.m_col0.m_quad + v11);
    v14 = _mm_mul_ps(*(&vars->m_angularBasisBw.m_col0.m_quad + hkGenericConstraintDataAxisOrder[v10 + 2]), v13);
    v15 = _mm_sub_ps(
            (__m128)0i64,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170)));
    v16 = _mm_mul_ps(*(&vars->m_angularBasisBw.m_col0.m_quad + v11), v13);
    v17 = _mm_rcp_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                _mm_shuffle_ps(v16, v16, 170))));
    v18 = _mm_mul_ps(v17, v15);
    v19 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v18), _mm_cmplt_ps(*(__m128 *)_xmm, v18));
    v20 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v18), v19), _mm_andnot_ps(v19, v18));
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
    v23 = _mm_cmple_ps((__m128)0i64, v17);
    v24 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v20, *(__m128 *)_xmm), *(__m128 *)_xmm), v22), v19),
            _mm_andnot_ps(v19, v22));
    v25 = COERCE_FLOAT(_mm_andnot_ps(v23, _mm_add_ps(_mm_or_ps(_mm_and_ps(v15, *(__m128 *)_xmm), *(__m128 *)_xmm), v24)).m128_u32[0] | v24.m128_i32[0] & v23.m128_i32[0])
        + 3.1415927;
    v26 = v25 - v8->m_quad.m128_f32[1];
    if ( v26 >= -3.1415927 )
    {
      if ( v26 > 3.1415927 )
        v12 = v12 + -1.0;
    }
    else
    {
      v12 = v12 + 1.0;
    }
    v8->m_quad.m128_f32[2] = v12;
    v8->m_quad.m128_f32[1] = v25;
    m_storage = out->m_jacobianSchemas.m_storage;
    v28 = out->m_constraintRuntime.m_storage;
    v29 = out->m_jacobianSchemas.m_storage;
    statusOut.m_lastResults = 0i64;
    hk1dAngularVelocityMotorBeginJacobian(&vars->m_angularBasisAw.m_col0 + v10, in, (hkp2AngJacobian *)v29, &statusOut);
    m_currentResult = vars->m_currentResult;
    statusOut.m_stepInfo.m_storage = in;
    v31 = (hkpSolverResults)*((_QWORD *)v28 + m_currentResult);
    LODWORD(statusOut.m_positionError.m_storage) = COERCE_UNSIGNED_INT(v25 + (float)(v12 * 6.2831855)) ^ _xmm[0];
    statusOut.m_deltaTarget.m_storage = 0.0;
    statusOut.m_lastResults = v31;
    hkCalcMotorData(v9, &statusOut, &output);
    hk1dAngularVelocityMotorCommitJacobian(&output, in, (hkp2AngJacobian *)m_storage, out);
    ++vars->m_currentResult;
  }
  else
  {
    ++vars->m_currentResult;
  }
}

// File Line: 412
// RVA: 0xD52BB0
void __fastcall hkpGenericConstraintData::setLinearMotorW(
        hkpGenericConstraintData *this,
        int **currentCommand,
        hkVector4f **currentData,
        hkpGenericConstraintDataScheme *scheme,
        hkpGenericConstraintDataParameters *vars,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkVector4f *v7; // rcx
  hkpConstraintMotor *v8; // r15
  __m128 v9; // xmm1
  hkpJacobianSchema *m_storage; // rdi
  struct hkpConstraintRuntime *v11; // rsi
  __m128 v12; // xmm1
  hkpSolverResults v13; // r10
  hkVector4f v14; // [rsp+30h] [rbp-78h] BYREF
  hkpConstraintMotorOutput output; // [rsp+40h] [rbp-68h] BYREF
  hkpConstraintMotorInput input; // [rsp+58h] [rbp-50h] BYREF

  ++*currentCommand;
  v7 = (*currentData)++;
  v8 = scheme->m_motors.m_data[v7->m_quad.m128_f32[0]];
  if ( v8 )
  {
    v9 = _mm_sub_ps(vars->m_pivotAw.m_quad, vars->m_pivotBw.m_quad);
    m_storage = out->m_jacobianSchemas.m_storage;
    v11 = out->m_constraintRuntime.m_storage;
    v14.m_quad = (__m128)*((_OWORD *)&vars->m_linearBasisW.m_col0 + **currentCommand);
    v12 = _mm_mul_ps(v9, v14.m_quad);
    input.m_lastResults = 0i64;
    hk1dLinearVelocityMotorBeginJacobian(&v14, &vars->m_pivotBw, in, (hkp1Lin2AngJacobian *)m_storage, &input);
    v13 = (hkpSolverResults)*((_QWORD *)v11 + vars->m_currentResult);
    LODWORD(input.m_positionError.m_storage) = COERCE_UNSIGNED_INT(
                                                 (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0]
                                                       + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
                                               + _mm_shuffle_ps(v12, v12, 170).m128_f32[0]) ^ _xmm[0];
    input.m_deltaTarget.m_storage = 0.0;
    input.m_stepInfo.m_storage = in;
    input.m_lastResults = v13;
    hkCalcMotorData(v8, &input, &output);
    hk1dLinearVelocityMotorCommitJacobian(&output, in, (hkp1Lin2AngJacobian *)m_storage, out);
  }
  ++vars->m_currentResult;
}

// File Line: 483
// RVA: 0xD51BB0
void __fastcall hkpGenericConstraintData::setLinearFrictionW(
        hkpGenericConstraintData *this,
        int **currentCommand,
        hkVector4f **currentData,
        hkpGenericConstraintDataScheme *scheme,
        hkpGenericConstraintDataParameters *vars,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  struct hkpConstraintRuntime *m_storage; // r9
  hkVector4f v8; // xmm0
  hkVector4f *v9; // rcx
  __int64 m_currentResult; // rax
  hkp1dLinearFrictionInfo info; // [rsp+20h] [rbp-38h] BYREF

  m_storage = out->m_constraintRuntime.m_storage;
  v8.m_quad = (__m128)*((_OWORD *)&vars->m_linearBasisW.m_col0 + *++*currentCommand);
  v9 = *currentData;
  info.m_pivot.m_quad = _mm_sub_ps(vars->m_pivotAw.m_quad, vars->m_pivotBw.m_quad);
  info.m_constrainedDofW = (hkVector4f)v8.m_quad;
  *currentData = v9 + 1;
  m_currentResult = vars->m_currentResult;
  LODWORD(info.m_maxFrictionForce.m_storage) = v9->m_quad.m128_i32[0];
  info.m_lastSolverResults.m_storage = (hkpSolverResults *)((char *)m_storage + 8 * m_currentResult);
  hk1dLinearFrictionBuildJacobian(&info, in, out);
  ++vars->m_currentResult;
}

// File Line: 504
// RVA: 0xD51C40
void __fastcall hkpGenericConstraintData::hatchScheme(
        hkpGenericConstraintData *this,
        hkpGenericConstraintDataScheme *scheme,
        hkpConstraintQueryIn *inOrig,
        hkpConstraintQueryOut *out)
{
  __m128i v4; // xmm2
  __int128 v5; // xmm0
  __int128 v6; // xmm1
  hkVector4f *m_data; // rbx
  int *v8; // rdi
  hkpConstraintModifier **v9; // r13
  __int128 v13; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  hkSimdFloat32 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  int v20; // eax
  __m128 *v21; // rax
  int *v22; // rdi
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
  bool v38; // cc
  float v39; // xmm1_4
  __int64 v40; // rcx
  __m128 v41; // xmm5
  __m128 v42; // xmm7
  __m128 v43; // xmm4
  __m128 v44; // xmm4
  __m128 v45; // xmm3
  __m128 v46; // xmm5
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  unsigned __int64 *v49; // rax
  __int64 v50; // rax
  __int64 v51; // rdx
  hkVector4f *v52; // rax
  unsigned int v53; // xmm0_4
  struct hkpConstraintRuntime *m_storage; // rax
  float *v55; // rax
  __int64 v56; // r8
  hkp1dAngularBilateralConstraintInfo info; // [rsp+40h] [rbp-88h] BYREF
  hkpGenericConstraintDataParameters vars; // [rsp+70h] [rbp-58h] BYREF
  hkpConstraintQueryIn in; // [rsp+148h] [rbp+80h] BYREF
  hkVector4f *currentData; // [rsp+240h] [rbp+178h] BYREF
  int *currentCommand[3]; // [rsp+248h] [rbp+180h] BYREF

  v4 = *(__m128i *)&inOrig->m_transformA.m_storage;
  v5 = *(_OWORD *)&inOrig->m_subStepDeltaTime.m_storage;
  v6 = *(_OWORD *)&inOrig->m_frameInvDeltaTime.m_storage;
  m_data = scheme->m_data.m_data;
  v8 = scheme->m_commands.m_data;
  v9 = scheme->m_modifiers.m_data;
  vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1] = (unsigned __int64)inOrig->m_transformA.m_storage;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v5;
  v13 = *(_OWORD *)&inOrig->m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v6;
  vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2] = 0;
  currentData = m_data;
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
  vars.m_angularBasisBw.m_col0.m_quad.m128_u64[0] = _mm_srli_si128(v4, 8).m128i_u64[0];
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = v19;
  while ( 1 )
  {
    v20 = *v8;
    currentCommand[0] = v8;
    switch ( v20 )
    {
      case 0:
        return;
      case 1:
        hkVector4f::setTransformedPos(
          &vars.m_pivotAw,
          (hkTransformf *)vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1],
          m_data++);
        currentData = m_data;
        ++v8;
        continue;
      case 2:
        hkVector4f::setTransformedPos(
          (hkVector4f *)&info.m_zeroErrorAxisAinW.m_quad.m128_u16[4],
          (hkTransformf *)vars.m_angularBasisBw.m_col0.m_quad.m128_u64[0],
          m_data++);
        currentData = m_data;
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
                                                                                      m_data->m_quad,
                                                                                      m_data->m_quad,
                                                                                      85),
                                                                                    v21[1]),
                                                                                  _mm_mul_ps(
                                                                                    _mm_shuffle_ps(
                                                                                      m_data->m_quad,
                                                                                      m_data->m_quad,
                                                                                      0),
                                                                                    *v21)),
                                                                                _mm_mul_ps(
                                                                                  _mm_shuffle_ps(
                                                                                    m_data->m_quad,
                                                                                    m_data->m_quad,
                                                                                    170),
                                                                                  v21[2]));
        goto LABEL_5;
      case 5:
        v23 = v8[1];
        v24.m_quad = m_data->m_quad;
        ++m_data;
        v8 += 2;
        currentData = m_data;
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
          out);
        ++vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
        v8 += 2;
        continue;
      case 7:
        hkpGenericConstraintData::constrainAllLinearW(this, currentCommand, &currentData, scheme, &vars, &in, out);
        ++v8;
        continue;
      case 8:
        v26 = (hkMatrix3f *)m_data;
        m_data += 3;
        currentData = m_data;
        hkMatrix3f::setMul(
          (hkMatrix3f *)&vars.m_pivotBw.m_quad.m128_u16[4],
          (hkMatrix3f *)vars.m_angularBasisAw.m_col2.m_quad.m128_u64[1],
          v26);
        ++v8;
        continue;
      case 9:
        v27 = (hkMatrix3f *)m_data;
        m_data += 3;
        currentData = m_data;
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
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, out);
        v30.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       info.m_constrainedDofW.m_quad);
        info.m_constrainedDofW = info.m_zeroErrorAxisAinW;
        info.m_zeroErrorAxisAinW = (hkVector4f)v30.m_quad;
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, out);
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
          out);
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col0 + 8);
        info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&vars.m_angularBasisAw.m_col1 + 8);
        info.m_constrainedDofW = *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col1 + 8);
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, out);
        info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&vars.m_linearBasisW.m_col2 + 8);
        info.m_constrainedDofW = info.m_zeroErrorAxisAinW;
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col2 + 8);
        hk1dAngularBilateralConstraintBuildJacobian(&info, &in, out);
        vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2] += 3;
        ++v8;
        continue;
      case 14:
        hkpGenericConstraintData::setAngularMotorW(this, currentCommand, &currentData, scheme, &vars, &in, out);
        m_data = currentData;
        v8 = currentCommand[0] + 1;
        continue;
      case 15:
        hkpGenericConstraintData::setLinearMotorW(this, currentCommand, &currentData, scheme, &vars, &in, out);
        m_data = currentData;
        v8 = currentCommand[0] + 1;
        continue;
      case 16:
        v31 = v8[1];
        *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col1 + 8) = vars.m_pivotAw;
        v32 = *(__int128 *)((char *)&info.m_constrainedDofW + 16 * v31 + 8);
        v33 = (int *)m_data++;
        *(_OWORD *)&vars.m_rbB = v32;
        currentData = m_data;
        *(hkVector4f *)((char *)&vars.m_angularBasisBw.m_col2 + 8) = *(hkVector4f *)((char *)&info.m_zeroErrorAxisAinW
                                                                                   + 8);
        *(&vars.m_currentResult + 2) = *v33;
        *(&vars.m_currentResult + 3) = v33[1];
        hk1dLinearLimitBuildJacobian((hkp1dLinearLimitInfo *)&vars.m_angularBasisBw.m_col1.m_quad.m128_u16[4], &in, out);
        ++vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
        v8 += 2;
        continue;
      case 17:
        v34 = v8[1];
        v22 = v8 + 1;
        info.m_constrainedDofW.m_quad.m128_i32[3] = 1056964608;
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&vars.m_pivotBw + 16 * v34 + 8);
        v35 = calcDeltaAngleAroundAxis(v34, &vars);
        v36 = m_data++;
        currentData = m_data;
        v37 = v35;
        v38 = v35 <= 0.0;
        info.m_constrainedDofW.m_quad.m128_f32[2] = v35;
        info.m_constrainedDofW.m_quad.m128_u64[0] = v36->m_quad.m128_u64[0];
        v39 = v36->m_quad.m128_f32[2];
        if ( v35 < 0.0 )
        {
          if ( v39 > 0.0 && (float)(v39 - v35) > 3.1415927 )
          {
            v37 = v35 + 6.2831855;
            info.m_constrainedDofW.m_quad.m128_f32[2] = v35 + 6.2831855;
          }
          v38 = v37 <= 0.0;
        }
        if ( !v38 && v39 < 0.0 && (float)(v37 - v39) > 3.1415927 )
        {
          v37 = v37 + -6.2831855;
          info.m_constrainedDofW.m_quad.m128_f32[2] = v37;
        }
        v36->m_quad.m128_f32[2] = v37;
        goto LABEL_27;
      case 18:
        v40 = v8[1];
        v22 = v8 + 1;
        info.m_constrainedDofW.m_quad.m128_i32[3] = 1056964608;
        v40 *= 2i64;
        v41 = *(__m128 *)((char *)&vars.m_pivotBw.m_quad + 8 * v40 + 8);
        v42 = *(__m128 *)((char *)&vars.m_linearBasisW.m_col2.m_quad + 8 * v40 + 8);
        v43 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v41), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v42));
        v44 = _mm_shuffle_ps(v43, v43, 201);
        v45 = _mm_mul_ps(v44, v44);
        if ( (float)((float)(_mm_shuffle_ps(v45, v45, 85).m128_f32[0] + _mm_shuffle_ps(v45, v45, 0).m128_f32[0])
                   + _mm_shuffle_ps(v45, v45, 170).m128_f32[0]) < 0.00000011920929 )
        {
LABEL_5:
          ++m_data;
          v8 = v22 + 1;
          currentData = m_data;
        }
        else
        {
          v46 = _mm_mul_ps(v41, v42);
          v47 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                  _mm_shuffle_ps(v45, v45, 170));
          v48 = _mm_rsqrt_ps(v47);
          info.m_zeroErrorAxisAinW.m_quad = _mm_mul_ps(
                                              v44,
                                              _mm_andnot_ps(
                                                _mm_cmple_ps(v47, (__m128)0i64),
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v48))));
          info.m_constrainedDofW.m_quad.m128_f32[2] = (float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0]
                                                            + _mm_shuffle_ps(v46, v46, 0).m128_f32[0])
                                                    + _mm_shuffle_ps(v46, v46, 170).m128_f32[0];
LABEL_30:
          v49 = (unsigned __int64 *)m_data++;
          currentData = m_data;
          info.m_constrainedDofW.m_quad.m128_u64[0] = *v49;
LABEL_27:
          hk1dAngularLimitBuildJacobian((hkp1dAngularLimitInfo *)&info, &in, out);
          ++vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
          v8 = v22 + 1;
        }
        break;
      case 19:
        v50 = v8[1];
        v51 = v8[2];
        v22 = v8 + 2;
        info.m_constrainedDofW.m_quad.m128_i32[3] = 1056964608;
        hkInternalConstraintUtils_calcRelativeAngle(
          (hkVector4f *)&vars.m_pivotBw.m_quad.m128_u16[8 * v50 + 4],
          (hkVector4f *)&vars.m_linearBasisW.m_col2.m_quad.m128_u16[8 * v50 + 4],
          (hkVector4f *)&vars.m_pivotBw.m_quad.m128_u16[8 * v51 + 4],
          (hkVector4f *)&vars.m_linearBasisW.m_col2.m_quad.m128_u16[8 * v51 + 4],
          &info.m_zeroErrorAxisAinW,
          (hkPadSpu<float> *)&info.m_constrainedDofW.m_quad.m128_u16[4]);
        goto LABEL_30;
      case 20:
        info.m_zeroErrorAxisAinW.m_quad.m128_u64[0] = (unsigned __int64)&vars.m_pivotBw.m_quad.m128_u64[2 * v8[1] + 1];
        v52 = m_data++;
        currentData = m_data;
        v53 = v52->m_quad.m128_i32[0];
        m_storage = out->m_constraintRuntime.m_storage;
        info.m_constrainedDofW.m_quad.m128_u64[0] = v53 | 0x100000000i64;
        info.m_zeroErrorAxisAinW.m_quad.m128_u64[1] = (unsigned __int64)m_storage
                                                    + 8 * vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
        hk1dAngularFrictionBuildJacobian((hkp1dAngularFrictionInfo *)&info, &in, out);
        ++vars.m_angularBasisBw.m_col0.m_quad.m128_i32[2];
        v8 += 2;
        continue;
      case 21:
        hkpGenericConstraintData::setLinearFrictionW(this, currentCommand, &currentData, scheme, &vars, &in, out);
        m_data = currentData;
        v8 = currentCommand[0] + 1;
        continue;
      case 22:
        v55 = (float *)m_data++;
        currentData = m_data;
        ++v8;
        in.m_virtMassFactor.m_storage = in.m_virtMassFactor.m_storage * *v55;
        continue;
      case 23:
        ++v8;
        in.m_virtMassFactor.m_storage = inOrig->m_virtMassFactor.m_storage;
        continue;
      case 24:
        v56 = (unsigned int)v8[1];
        ++v8;
        (*v9)->vfptr->modify(*v9, &vars, v56);
        ++v9;
        goto LABEL_41;
      default:
LABEL_41:
        ++v8;
        break;
    }
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
__int64 __fastcall hkpGenericConstraintData::getType(hkpGenericConstraintData *this)
{
  return 10i64;
}

