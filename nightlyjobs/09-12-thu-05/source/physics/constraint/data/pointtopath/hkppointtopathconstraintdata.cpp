// File Line: 24
// RVA: 0xD4A9C0
void __fastcall hkpPointToPathConstraintData::hkpPointToPathConstraintData(hkpPointToPathConstraintData *this)
{
  hkpBridgeAtoms *p_m_atoms; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  p_m_atoms = &this->m_atoms;
  *(_QWORD *)&p_m_atoms[-1].m_bridgeAtom.m_type.m_storage = &hkpPointToPathConstraintData::`vftable;
  p_m_atoms->m_bridgeAtom.m_type.m_storage = 1;
  this->m_path = 0i64;
  this->m_maxFrictionForce = 0.0;
  this->m_angularConstrainedDOF.m_storage = 1;
  this->m_transform_OS_KS[0].m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform_OS_KS[0].m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform_OS_KS[0].m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform_OS_KS[0].m_translation = 0i64;
  this->m_transform_OS_KS[1].m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform_OS_KS[1].m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform_OS_KS[1].m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform_OS_KS[1].m_translation = 0i64;
  hkpBridgeConstraintAtom::init(&p_m_atoms->m_bridgeAtom, this);
}

// File Line: 32
// RVA: 0xD4AA70
void __fastcall hkpPointToPathConstraintData::~hkpPointToPathConstraintData(hkpPointToPathConstraintData *this)
{
  hkpParametricCurve *m_path; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpPointToPathConstraintData::`vftable;
  m_path = this->m_path;
  if ( m_path )
    hkReferencedObject::removeReference(m_path);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 40
// RVA: 0xD4AD70
void __fastcall hkpPointToPathConstraintData::setPath(hkpPointToPathConstraintData *this, hkpParametricCurve *path)
{
  hkpParametricCurve *m_path; // rcx

  if ( path )
    hkReferencedObject::addReference(path);
  m_path = this->m_path;
  if ( m_path )
    hkReferencedObject::removeReference(m_path);
  this->m_path = path;
}

// File Line: 53
// RVA: 0xD4AE10
void __fastcall hkpPointToPathConstraintData::getConstraintInfo(
        hkpPointToPathConstraintData *this,
        hkpConstraintData::ConstraintInfo *info)
{
  info->m_sizeOfAllAtoms = 32;
  info->m_maxSizeOfSchema = 0;
  info->m_sizeOfSchemas = 400;
  info->m_numSolverResults = 8;
  info->m_numSolverElemTemps = 8;
  info->m_atoms = &this->m_atoms.m_bridgeAtom;
}

// File Line: 72
// RVA: 0xD4AE50
void __fastcall hkpPointToPathConstraintData::getRuntimeInfo(
        hkpPointToPathConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 8;
  infoOut->m_sizeOfExternalRuntime = 68;
}

// File Line: 80
// RVA: 0xD4ADB0
void __fastcall hkpPointToPathConstraintData::calcPivot(
        hkpPointToPathConstraintData *this,
        hkTransformf *transformBodyA,
        hkVector4f *pivotOut)
{
  hkVector4f::setTransformedPos(pivotOut, transformBodyA, &this->m_transform_OS_KS[0].m_translation);
}

// File Line: 85
// RVA: 0xD4AE70
void __fastcall hkpPointToPathConstraintData::buildJacobian(
        hkpPointToPathConstraintData *this,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkpParametricCurve *m_path; // rcx
  struct hkpConstraintRuntime *m_storage; // rbx
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __int64 v11; // rdx
  double v12; // xmm0_8
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  hkVector4f v15; // xmm10
  __int64 v16; // rdx
  hkVector4f v17; // xmm8
  __m128i inserted; // xmm11
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128 v25; // xmm9
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  hkVector4f v29; // xmm9
  __m128 v30; // xmm6
  hkVector4f v31; // xmm6
  hkVector4f v32; // xmm1
  float m_maxFrictionForce; // xmm2_4
  hkVector4f v34; // xmm7
  __m128 v35; // xmm6
  __int64 v36; // rdx
  hkpParametricCurve *v37; // rcx
  hkBaseObjectVtbl *vfptr; // rbx
  float v39; // xmm0_4
  hkpParametricCurve *v40; // rcx
  hkBaseObjectVtbl *v41; // rbx
  float v42; // xmm0_4
  __m128 v43; // [rsp+20h] [rbp-E0h] BYREF
  hkp1dLinearLimitInfo info; // [rsp+30h] [rbp-D0h] BYREF
  hkTransformf v45; // [rsp+70h] [rbp-90h] BYREF
  hkTransformf v46; // [rsp+B0h] [rbp-50h] BYREF
  hkp1dLinearBilateralConstraintInfo v47; // [rsp+F0h] [rbp-10h] BYREF
  int v48; // [rsp+1A0h] [rbp+A0h] BYREF

  in->m_beginConstraints(in, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  hkTransformf::setMul(&v45, in->m_transformB.m_storage, &this->m_transform_OS_KS[1]);
  hkTransformf::setMul(&v46, in->m_transformA.m_storage, this->m_transform_OS_KS);
  m_path = this->m_path;
  m_storage = out->m_constraintRuntime.m_storage;
  v8 = _mm_sub_ps(v46.m_translation.m_quad, v45.m_translation.m_quad);
  v9 = _mm_unpacklo_ps(v45.m_rotation.m_col0.m_quad, v45.m_rotation.m_col1.m_quad);
  v10 = _mm_movelh_ps(v9, v45.m_rotation.m_col2.m_quad);
  v43 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v8, v8, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v45.m_rotation.m_col2.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v10)),
          _mm_mul_ps(
            _mm_shuffle_ps(v8, v8, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(v45.m_rotation.m_col0.m_quad, v45.m_rotation.m_col1.m_quad),
              v45.m_rotation.m_col2.m_quad,
              228)));
  v12 = ((double (__fastcall *)(hkpParametricCurve *, __int64, __m128 *, __m128 *))m_path->vfptr[2].__vecDelDtor)(
          m_path,
          v11,
          &v43,
          &v43);
  v13 = v43;
  v14 = v43;
  *((_DWORD *)m_storage + 16) = LODWORD(v12);
  v15.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v45.m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v14, v13, 0), v45.m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v45.m_rotation.m_col2.m_quad)),
                 v45.m_translation.m_quad);
  ((void (__fastcall *)(hkpParametricCurve *, __int64, __m128 *))this->m_path->vfptr[2].__first_virtual_table_function__)(
    this->m_path,
    v16,
    &v43);
  v17.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), v45.m_rotation.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v45.m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), v45.m_rotation.m_col2.m_quad));
  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v19 = _mm_shuffle_ps(v17.m_quad, _mm_unpackhi_ps(v17.m_quad, (__m128)0i64), 196);
  v20 = _mm_shuffle_ps(v19, v19, 241);
  v21 = _mm_shuffle_ps(v19, v19, 206);
  v22 = _mm_mul_ps(v21, v21);
  v23 = _mm_mul_ps(v20, v20);
  v24 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
            _mm_shuffle_ps(v23, v23, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
            _mm_shuffle_ps(v22, v22, 170)));
  v25 = _mm_xor_ps(_mm_or_ps(_mm_andnot_ps(v24, v20), _mm_and_ps(v21, v24)), (__m128)inserted);
  v26 = _mm_mul_ps(v25, v25);
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v28 = _mm_rsqrt_ps(v27);
  v29.m_quad = _mm_mul_ps(
                 v25,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v27, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                     _mm_mul_ps(*(__m128 *)_xmm, v28))));
  v30 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v29.m_quad, v29.m_quad, 201), v17.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 201), v29.m_quad));
  v31.m_quad = _mm_shuffle_ps(v30, v30, 201);
  *(float *)&v12 = ((float (__fastcall *)(hkpParametricCurve *))this->m_path->vfptr[4].__vecDelDtor)(this->m_path);
  v32.m_quad = (__m128)v46.m_translation;
  m_maxFrictionForce = this->m_maxFrictionForce;
  v48 = LODWORD(v12) ^ _xmm[0];
  v34.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)(unsigned int)(LODWORD(v12) ^ _xmm[0]),
                     (__m128)(unsigned int)(LODWORD(v12) ^ _xmm[0]),
                     0),
                   v17.m_quad),
                 v46.m_translation.m_quad);
  if ( m_maxFrictionForce > 0.0 )
  {
    info.m_constrainedDofW.m_quad.m128_f32[0] = m_maxFrictionForce;
    info.m_pivotB = (hkVector4f)v17.m_quad;
    info.m_pivotA = (hkVector4f)v34.m_quad;
    info.m_constrainedDofW.m_quad.m128_u64[1] = (unsigned __int64)m_storage;
    hk1dLinearFrictionBuildJacobian((hkp1dLinearFrictionInfo *)&info, in, out);
    v32.m_quad = (__m128)v46.m_translation;
  }
  v47.m_pivotA = (hkVector4f)v32.m_quad;
  v47.m_pivotB = (hkVector4f)v15.m_quad;
  v47.m_constrainedDofW = (hkVector4f)v29.m_quad;
  hk1dLinearBilateralConstraintBuildJacobian(&v47, in, out);
  v47.m_constrainedDofW = (hkVector4f)v31.m_quad;
  hk1dLinearBilateralConstraintBuildJacobian(&v47, in, out);
  if ( this->m_angularConstrainedDOF.m_storage > 1 )
  {
    info.m_constrainedDofW = v46.m_rotation.m_col2;
    info.m_pivotB = v46.m_rotation.m_col1;
    info.m_pivotA = (hkVector4f)v17.m_quad;
    hk1dAngularBilateralConstraintBuildJacobian((hkp1dAngularBilateralConstraintInfo *)&info, in, out);
    v35 = (__m128)_mm_shuffle_epi32(inserted, 0);
    info.m_constrainedDofW = v46.m_rotation.m_col1;
    info.m_pivotB.m_quad = _mm_xor_ps(v46.m_rotation.m_col2.m_quad, v35);
    hk1dAngularBilateralConstraintBuildJacobian((hkp1dAngularBilateralConstraintInfo *)&info, in, out);
    if ( this->m_angularConstrainedDOF.m_storage == 3 )
    {
      ((void (__fastcall *)(hkpParametricCurve *, __int64, __m128 *))this->m_path->vfptr[4].__first_virtual_table_function__)(
        this->m_path,
        v36,
        &v43);
      info.m_pivotA = v46.m_rotation.m_col2;
      info.m_pivotB = v46.m_rotation.m_col0;
      info.m_constrainedDofW.m_quad = _mm_xor_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), v45.m_rotation.m_col1.m_quad),
                                            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v45.m_rotation.m_col0.m_quad)),
                                          _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), v45.m_rotation.m_col2.m_quad)),
                                        v35);
      hk1dAngularBilateralConstraintBuildJacobian((hkp1dAngularBilateralConstraintInfo *)&info, in, out);
    }
  }
  if ( !*(_BYTE *)this->m_path->vfptr[5].__vecDelDtor(this->m_path, &v48) )
  {
    v37 = this->m_path;
    info.m_pivotB = (hkVector4f)v34.m_quad;
    info.m_pivotA = v46.m_translation;
    vfptr = v37->vfptr;
    ((void (__fastcall *)(hkpParametricCurve *))v37->vfptr[3].__vecDelDtor)(v37);
    v39 = ((float (__fastcall *)(hkpParametricCurve *))vfptr[4].__vecDelDtor)(this->m_path);
    v40 = this->m_path;
    info.m_min.m_storage = v39;
    v41 = v40->vfptr;
    v40->vfptr[3].__first_virtual_table_function__(v40);
    v42 = ((float (__fastcall *)(hkpParametricCurve *))v41[4].__vecDelDtor)(this->m_path);
    info.m_constrainedDofW = (hkVector4f)v17.m_quad;
    info.m_max.m_storage = v42;
    hk1dLinearLimitBuildJacobian(&info, in, out);
  }
}

// File Line: 209
// RVA: 0xD4ADE0
hkBool *__fastcall hkpPointToPathConstraintData::isValid(hkpPointToPathConstraintData *this, hkBool *result)
{
  if ( this->m_path && this->m_angularConstrainedDOF.m_storage )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 216
// RVA: 0xD4ADD0
__int64 __fastcall hkpPointToPathConstraintData::getType(hkpPointToPathConstraintData *this)
{
  return 3i64;
}

// File Line: 222
// RVA: 0xD4AAB0
void __fastcall hkpPointToPathConstraintData::setInWorldSpace(
        hkpPointToPathConstraintData *this,
        hkTransformf *ws_T_Aos,
        hkTransformf *ws_T_Ros,
        hkVector4f *pivotWs)
{
  hkpParametricCurve *m_path; // rcx
  hkpParametricCurve *v9; // rcx
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __int64 v13; // rdx
  __int64 v14; // rdx
  __int64 v15; // rdx
  __m128 v16; // xmm2
  hkVector4f v17; // xmm1
  hkVector4f v18; // xmm0
  hkVector4f v19; // xmm1
  __m128 v20; // [rsp+20h] [rbp-C8h] BYREF
  __m128 v21; // [rsp+30h] [rbp-B8h] BYREF
  __m128 v22; // [rsp+40h] [rbp-A8h] BYREF
  char v23[72]; // [rsp+50h] [rbp-98h] BYREF
  __m128 v24; // [rsp+98h] [rbp-50h]
  __m128 v25; // [rsp+A8h] [rbp-40h]
  hkTransformf v26; // [rsp+B8h] [rbp-30h] BYREF
  hkTransformf v27; // [rsp+F8h] [rbp+10h] BYREF
  hkpParametricCurve *v28; // [rsp+188h] [rbp+A0h]
  hkTransformf *bTc; // [rsp+190h] [rbp+A8h]

  if ( v28 )
    hkReferencedObject::addReference(v28);
  m_path = this->m_path;
  if ( m_path )
    hkReferencedObject::removeReference(m_path);
  this->m_path = v28;
  this->m_transform_OS_KS[1].m_rotation.m_col0 = bTc->m_rotation.m_col0;
  this->m_transform_OS_KS[1].m_rotation.m_col1 = bTc->m_rotation.m_col1;
  this->m_transform_OS_KS[1].m_rotation.m_col2 = bTc->m_rotation.m_col2;
  this->m_transform_OS_KS[1].m_translation = bTc->m_translation;
  hkTransformf::setMul((hkTransformf *)&v23[40], ws_T_Ros, bTc);
  v9 = this->m_path;
  v10 = _mm_unpacklo_ps(*(__m128 *)&v23[40], *(__m128 *)&v23[56]);
  v11 = _mm_sub_ps(pivotWs->m_quad, v25);
  v12 = _mm_movelh_ps(v10, v24);
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v10), v24, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v12)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(*(__m128 *)&v23[40], *(__m128 *)&v23[56]), v24, 228),
            _mm_shuffle_ps(v11, v11, 170)));
  ((void (__fastcall *)(hkpParametricCurve *, __int64, __m128 *, __m128 *))v9->vfptr[2].__vecDelDtor)(
    v9,
    v13,
    &v20,
    &v20);
  ((void (__fastcall *)(hkpParametricCurve *, __int64, __m128 *))this->m_path->vfptr[2].__first_virtual_table_function__)(
    this->m_path,
    v14,
    &v21);
  ((void (__fastcall *)(hkpParametricCurve *, __int64, __m128 *))this->m_path->vfptr[4].__first_virtual_table_function__)(
    this->m_path,
    v15,
    &v22);
  *(_QWORD *)&v23[16] = v22.m128_u64[0];
  *(__m128 *)v23 = v21;
  *(_QWORD *)&v23[24] = v20.m128_u64[0];
  v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v21), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v22));
  *(__m128 *)&v23[32] = _mm_shuffle_ps(v16, v16, 201);
  hkTransformf::setMul(&v27, bTc, (hkTransformf *)v23);
  hkTransformf::setMul((hkTransformf *)v23, ws_T_Ros, &v27);
  hkTransformf::setMulInverseMul(&v26, ws_T_Aos, (hkTransformf *)v23);
  v17.m_quad = (__m128)v26.m_rotation.m_col1;
  this->m_transform_OS_KS[0].m_rotation.m_col0 = v26.m_rotation.m_col0;
  v18.m_quad = (__m128)v26.m_rotation.m_col2;
  this->m_transform_OS_KS[0].m_rotation.m_col1 = (hkVector4f)v17.m_quad;
  v19.m_quad = (__m128)v26.m_translation;
  this->m_transform_OS_KS[0].m_rotation.m_col2 = (hkVector4f)v18.m_quad;
  this->m_transform_OS_KS[0].m_translation = (hkVector4f)v19.m_quad;
}

// File Line: 267
// RVA: 0xD4ACA0
void __fastcall hkpPointToPathConstraintData::setInBodySpace(
        hkpPointToPathConstraintData *this,
        hkVector4f *pivotA,
        hkVector4f *pivotB,
        hkpParametricCurve *path)
{
  hkpParametricCurve *m_path; // rcx

  if ( path )
    hkReferencedObject::addReference(path);
  m_path = this->m_path;
  if ( m_path )
    hkReferencedObject::removeReference(m_path);
  this->m_path = path;
  this->m_transform_OS_KS[0].m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform_OS_KS[0].m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform_OS_KS[0].m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform_OS_KS[0].m_translation = 0i64;
  this->m_transform_OS_KS[1].m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform_OS_KS[1].m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform_OS_KS[1].m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform_OS_KS[1].m_translation = 0i64;
  this->m_transform_OS_KS[0].m_translation = (hkVector4f)pivotA->m_quad;
  this->m_transform_OS_KS[1].m_translation = (hkVector4f)pivotB->m_quad;
}

