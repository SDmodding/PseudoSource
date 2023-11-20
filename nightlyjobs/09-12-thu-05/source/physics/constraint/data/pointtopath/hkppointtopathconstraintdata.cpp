// File Line: 24
// RVA: 0xD4A9C0
void __fastcall hkpPointToPathConstraintData::hkpPointToPathConstraintData(hkpPointToPathConstraintData *this)
{
  hkpPointToPathConstraintData *v1; // rbx
  hkpBridgeConstraintAtom *v2; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v1 = this;
  this->m_userData = 0i64;
  v2 = &this->m_atoms.m_bridgeAtom;
  *(_QWORD *)&v2[-1].m_type.m_storage = &hkpPointToPathConstraintData::`vftable';
  v2->m_type.m_storage = 1;
  v1->m_path = 0i64;
  v1->m_maxFrictionForce = 0.0;
  v1->m_angularConstrainedDOF.m_storage = 1;
  v1->m_transform_OS_KS[0].m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v1->m_transform_OS_KS[0].m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v1->m_transform_OS_KS[0].m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v1->m_transform_OS_KS[0].m_translation = 0i64;
  v1->m_transform_OS_KS[1].m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v1->m_transform_OS_KS[1].m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v1->m_transform_OS_KS[1].m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v1->m_transform_OS_KS[1].m_translation = 0i64;
  hkpBridgeConstraintAtom::init(v2, (hkpConstraintData *)&v1->vfptr);
}

// File Line: 32
// RVA: 0xD4AA70
void __fastcall hkpPointToPathConstraintData::~hkpPointToPathConstraintData(hkpPointToPathConstraintData *this)
{
  hkpPointToPathConstraintData *v1; // rbx
  hkpParametricCurve *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPointToPathConstraintData::`vftable';
  v2 = this->m_path;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 40
// RVA: 0xD4AD70
void __fastcall hkpPointToPathConstraintData::setPath(hkpPointToPathConstraintData *this, hkpParametricCurve *path)
{
  hkpParametricCurve *v2; // rbx
  hkpPointToPathConstraintData *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = path;
  v3 = this;
  if ( path )
    hkReferencedObject::addReference((hkReferencedObject *)&path->vfptr);
  v4 = (hkReferencedObject *)&v3->m_path->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_path = v2;
}

// File Line: 53
// RVA: 0xD4AE10
void __fastcall hkpPointToPathConstraintData::getConstraintInfo(hkpPointToPathConstraintData *this, hkpConstraintData::ConstraintInfo *info)
{
  info->m_sizeOfAllAtoms = 32;
  info->m_maxSizeOfSchema = 0;
  info->m_sizeOfSchemas = 400;
  info->m_numSolverResults = 8;
  info->m_numSolverElemTemps = 8;
  info->m_atoms = (hkpConstraintAtom *)&this->m_atoms.m_bridgeAtom.m_type;
}

// File Line: 72
// RVA: 0xD4AE50
void __fastcall hkpPointToPathConstraintData::getRuntimeInfo(hkpPointToPathConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = 8;
  infoOut->m_sizeOfExternalRuntime = 68;
}

// File Line: 80
// RVA: 0xD4ADB0
void __fastcall hkpPointToPathConstraintData::calcPivot(hkpPointToPathConstraintData *this, hkTransformf *transformBodyA, hkVector4f *pivotOut)
{
  hkVector4f::setTransformedPos(pivotOut, transformBodyA, &this->m_transform_OS_KS[0].m_translation);
}

// File Line: 85
// RVA: 0xD4AE70
void __fastcall hkpPointToPathConstraintData::buildJacobian(hkpPointToPathConstraintData *this, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryOut *v3; // r14
  hkpConstraintQueryIn *v4; // rsi
  hkpPointToPathConstraintData *v5; // rdi
  hkpParametricCurve *v6; // rcx
  struct hkpConstraintRuntime *v7; // rbx
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __int128 v12; // xmm1
  __int64 v13; // rdx
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  hkVector4f v16; // xmm10
  __int64 v17; // rdx
  hkVector4f v18; // xmm8
  __m128i v19; // xmm11
  __m128 v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm9
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __int128 v30; // xmm1
  hkVector4f v31; // xmm9
  __m128 v32; // xmm0
  __m128 v33; // xmm6
  hkVector4f v34; // xmm6
  hkVector4f v35; // xmm1
  float v36; // xmm2_4
  hkVector4f v37; // xmm7
  __m128 v38; // xmm6
  __int64 v39; // rdx
  __int128 v40; // xmm1
  int v41; // xmm0_4
  hkpParametricCurve *v42; // rcx
  hkBaseObjectVtbl *v43; // rbx
  hkpParametricCurve *v44; // rcx
  hkBaseObjectVtbl *v45; // rbx
  __m128 v46; // [rsp+20h] [rbp-E0h]
  hkp1dLinearFrictionInfo info; // [rsp+30h] [rbp-D0h]
  int v48; // [rsp+60h] [rbp-A0h]
  int v49; // [rsp+64h] [rbp-9Ch]
  hkTransformf v50; // [rsp+70h] [rbp-90h]
  hkTransformf v51; // [rsp+B0h] [rbp-50h]
  hkp1dLinearBilateralConstraintInfo v52; // [rsp+F0h] [rbp-10h]
  int v53; // [rsp+1A0h] [rbp+A0h]

  v3 = out;
  v4 = in;
  v5 = this;
  v4->m_beginConstraints(v4, out, (hkpSolverResults *)out->m_constraintRuntime.m_storage, 8);
  hkTransformf::setMul(&v50, v4->m_transformB.m_storage, &v5->m_transform_OS_KS[1]);
  hkTransformf::setMul(&v51, v4->m_transformA.m_storage, v5->m_transform_OS_KS);
  v6 = v5->m_path;
  v7 = v3->m_constraintRuntime.m_storage;
  v8 = _mm_sub_ps(v51.m_translation.m_quad, v50.m_translation.m_quad);
  v9 = _mm_unpacklo_ps(v50.m_rotation.m_col0.m_quad, v50.m_rotation.m_col1.m_quad);
  v10 = _mm_movelh_ps(v9, v50.m_rotation.m_col2.m_quad);
  v11 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v10);
  v46 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v8, v8, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v50.m_rotation.m_col2.m_quad, 212)),
            v11),
          _mm_mul_ps(
            _mm_shuffle_ps(v8, v8, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(v50.m_rotation.m_col0.m_quad, v50.m_rotation.m_col1.m_quad),
              v50.m_rotation.m_col2.m_quad,
              228)));
  v12 = *((unsigned int *)v7 + 16);
  ((void (__fastcall *)(hkpParametricCurve *, __int64, __m128 *, __m128 *))v6->vfptr[2].__vecDelDtor)(
    v6,
    v13,
    &v46,
    &v46);
  v14 = v46;
  v15 = v46;
  *((_DWORD *)v7 + 16) = v11.m128_i32[0];
  v16.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v50.m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v15, v14, 0), v50.m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v50.m_rotation.m_col2.m_quad)),
                 v50.m_translation.m_quad);
  ((void (__fastcall *)(hkpParametricCurve *, __int64, __m128 *))v5->m_path->vfptr[2].__first_virtual_table_function__)(
    v5->m_path,
    v17,
    &v46);
  v18.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v50.m_rotation.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v50.m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v50.m_rotation.m_col2.m_quad));
  v19 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v20 = _mm_shuffle_ps(v18.m_quad, _mm_unpackhi_ps(v18.m_quad, (__m128)0i64), 196);
  v21 = _mm_shuffle_ps(v20, v20, 241);
  v22 = _mm_shuffle_ps(v20, v20, 206);
  v23 = _mm_mul_ps(v22, v22);
  v24 = _mm_mul_ps(v21, v21);
  v25 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
            _mm_shuffle_ps(v23, v23, 170)));
  v26 = _mm_xor_ps(_mm_or_ps(_mm_andnot_ps(v25, v21), _mm_and_ps(v22, v25)), (__m128)v19);
  v27 = _mm_mul_ps(v26, v26);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_rsqrt_ps(v28);
  v30 = *((unsigned int *)v7 + 16);
  v31.m_quad = _mm_mul_ps(
                 v26,
                 _mm_andnot_ps(
                   _mm_cmpleps(v28, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                     _mm_mul_ps(*(__m128 *)_xmm, v29))));
  v32 = _mm_mul_ps(_mm_shuffle_ps(v18.m_quad, v18.m_quad, 201), v31.m_quad);
  v33 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31.m_quad, v31.m_quad, 201), v18.m_quad), v32);
  v34.m_quad = _mm_shuffle_ps(v33, v33, 201);
  ((void (*)(void))v5->m_path->vfptr[4].__vecDelDtor)();
  v35.m_quad = (__m128)v51.m_translation;
  v36 = v5->m_maxFrictionForce;
  v53 = v32.m128_i32[0] ^ _xmm[0];
  v37.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)(unsigned int)(v32.m128_i32[0] ^ _xmm[0]),
                     (__m128)(unsigned int)(v32.m128_i32[0] ^ _xmm[0]),
                     0),
                   v18.m_quad),
                 v51.m_translation.m_quad);
  if ( v36 > 0.0 )
  {
    info.m_maxFrictionForce.m_storage = v36;
    info.m_constrainedDofW = (hkVector4f)v18.m_quad;
    info.m_pivot = (hkVector4f)v37.m_quad;
    info.m_lastSolverResults.m_storage = (hkpSolverResults *)v7;
    hk1dLinearFrictionBuildJacobian(&info, v4, v3);
    v35.m_quad = (__m128)v51.m_translation;
  }
  v52.m_pivotA = (hkVector4f)v35.m_quad;
  v52.m_pivotB = (hkVector4f)v16.m_quad;
  v52.m_constrainedDofW = (hkVector4f)v31.m_quad;
  hk1dLinearBilateralConstraintBuildJacobian(&v52, v4, v3);
  v52.m_constrainedDofW = (hkVector4f)v34.m_quad;
  hk1dLinearBilateralConstraintBuildJacobian(&v52, v4, v3);
  if ( v5->m_angularConstrainedDOF.m_storage > 1 )
  {
    *(hkVector4f *)&info.m_maxFrictionForce.m_storage = v51.m_rotation.m_col2;
    info.m_constrainedDofW = v51.m_rotation.m_col1;
    info.m_pivot = (hkVector4f)v18.m_quad;
    hk1dAngularBilateralConstraintBuildJacobian((hkp1dAngularBilateralConstraintInfo *)&info, v4, v3);
    v38 = (__m128)_mm_shuffle_epi32(v19, 0);
    *(hkVector4f *)&info.m_maxFrictionForce.m_storage = v51.m_rotation.m_col1;
    info.m_constrainedDofW.m_quad = _mm_xor_ps(v51.m_rotation.m_col2.m_quad, v38);
    hk1dAngularBilateralConstraintBuildJacobian((hkp1dAngularBilateralConstraintInfo *)&info, v4, v3);
    if ( v5->m_angularConstrainedDOF.m_storage == 3 )
    {
      v40 = *((unsigned int *)v7 + 16);
      ((void (__fastcall *)(hkpParametricCurve *, __int64, __m128 *))v5->m_path->vfptr[4].__first_virtual_table_function__)(
        v5->m_path,
        v39,
        &v46);
      info.m_pivot = v51.m_rotation.m_col2;
      info.m_constrainedDofW = v51.m_rotation.m_col0;
      *(__m128 *)&info.m_maxFrictionForce.m_storage = _mm_xor_ps(
                                                        _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps(v46, v46, 85),
                                                              v50.m_rotation.m_col1.m_quad),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps(v46, v46, 0),
                                                              v50.m_rotation.m_col0.m_quad)),
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps(v46, v46, 170),
                                                            v50.m_rotation.m_col2.m_quad)),
                                                        v38);
      hk1dAngularBilateralConstraintBuildJacobian((hkp1dAngularBilateralConstraintInfo *)&info, v4, v3);
    }
  }
  if ( !*(_BYTE *)v5->m_path->vfptr[5].__vecDelDtor((hkBaseObject *)&v5->m_path->vfptr, (unsigned int)&v53) )
  {
    v41 = v51.m_translation.m_quad.m128_i32[0];
    v42 = v5->m_path;
    info.m_constrainedDofW = (hkVector4f)v37.m_quad;
    info.m_pivot = v51.m_translation;
    v43 = v42->vfptr;
    ((void (*)(void))v42->vfptr[3].__vecDelDtor)();
    ((void (__fastcall *)(hkpParametricCurve *))v43[4].__vecDelDtor)(v5->m_path);
    v44 = v5->m_path;
    v48 = v41;
    v45 = v44->vfptr;
    ((void (*)(void))v44->vfptr[3].__first_virtual_table_function__)();
    ((void (__fastcall *)(hkpParametricCurve *))v45[4].__vecDelDtor)(v5->m_path);
    *(hkVector4f *)&info.m_maxFrictionForce.m_storage = (hkVector4f)v18.m_quad;
    v49 = v41;
    hk1dLinearLimitBuildJacobian((hkp1dLinearLimitInfo *)&info, v4, v3);
  }
}

// File Line: 209
// RVA: 0xD4ADE0
hkBool *__fastcall hkpPointToPathConstraintData::isValid(hkpPointToPathConstraintData *this, hkBool *result)
{
  hkBool *v2; // rax

  if ( this->m_path && this->m_angularConstrainedDOF.m_storage )
  {
    result->m_bool = 1;
    v2 = result;
  }
  else
  {
    result->m_bool = 0;
    v2 = result;
  }
  return v2;
}

// File Line: 216
// RVA: 0xD4ADD0
signed __int64 __fastcall hkpPointToPathConstraintData::getType(hkpPointToPathConstraintData *this)
{
  return 3i64;
}

// File Line: 222
// RVA: 0xD4AAB0
void __fastcall hkpPointToPathConstraintData::setInWorldSpace(hkpPointToPathConstraintData *this, hkTransformf *ws_T_Aos, hkTransformf *ws_T_Ros, hkVector4f *pivotWs)
{
  hkVector4f *v4; // r14
  hkTransformf *v5; // rsi
  hkTransformf *v6; // r15
  hkpPointToPathConstraintData *v7; // rdi
  hkReferencedObject *v8; // rcx
  hkpParametricCurve *v9; // rcx
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __int64 v13; // rdx
  __int64 v14; // rdx
  __int64 v15; // rdx
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  hkVector4f v18; // xmm1
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm1
  hkVector4f v21; // [rsp+20h] [rbp-C8h]
  hkVector4f v22; // [rsp+30h] [rbp-B8h]
  hkVector4f v23; // [rsp+40h] [rbp-A8h]
  hkTransformf v24; // [rsp+50h] [rbp-98h]
  __m128 v25; // [rsp+98h] [rbp-50h]
  __m128 v26; // [rsp+A8h] [rbp-40h]
  hkTransformf v27; // [rsp+B8h] [rbp-30h]
  hkTransformf v28; // [rsp+F8h] [rbp+10h]
  hkReferencedObject *v29; // [rsp+188h] [rbp+A0h]
  hkTransformf *bTc; // [rsp+190h] [rbp+A8h]

  v4 = pivotWs;
  v5 = ws_T_Ros;
  v6 = ws_T_Aos;
  v7 = this;
  if ( v29 )
    hkReferencedObject::addReference(v29);
  v8 = (hkReferencedObject *)&v7->m_path->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v7->m_path = (hkpParametricCurve *)v29;
  v7->m_transform_OS_KS[1].m_rotation.m_col0 = bTc->m_rotation.m_col0;
  v7->m_transform_OS_KS[1].m_rotation.m_col1 = bTc->m_rotation.m_col1;
  v7->m_transform_OS_KS[1].m_rotation.m_col2 = bTc->m_rotation.m_col2;
  v7->m_transform_OS_KS[1].m_translation = bTc->m_translation;
  hkTransformf::setMul((hkTransformf *)((char *)&v24 + 40), v5, bTc);
  v9 = v7->m_path;
  v10 = _mm_unpacklo_ps(
          *(__m128 *)((char *)&v24.m_rotation.m_col2.m_quad + 8),
          *(__m128 *)((char *)&v24.m_translation.m_quad + 8));
  v11 = _mm_sub_ps(v4->m_quad, v26);
  v12 = _mm_movelh_ps(v10, v25);
  v21.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v10), v25, 212)),
                   _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v12)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     _mm_unpackhi_ps(
                       *(__m128 *)((char *)&v24.m_rotation.m_col2.m_quad + 8),
                       *(__m128 *)((char *)&v24.m_translation.m_quad + 8)),
                     v25,
                     228),
                   _mm_shuffle_ps(v11, v11, 170)));
  ((void (__fastcall *)(hkpParametricCurve *, __int64, hkVector4f *, hkVector4f *))v9->vfptr[2].__vecDelDtor)(
    v9,
    v13,
    &v21,
    &v21);
  ((void (__fastcall *)(hkpParametricCurve *, __int64, hkVector4f *))v7->m_path->vfptr[2].__first_virtual_table_function__)(
    v7->m_path,
    v14,
    &v22);
  ((void (__fastcall *)(hkpParametricCurve *, __int64, hkVector4f *))v7->m_path->vfptr[4].__first_virtual_table_function__)(
    v7->m_path,
    v15,
    &v23);
  v24.m_rotation.m_col1 = (hkVector4f)v23.m_quad;
  v24.m_rotation.m_col0 = (hkVector4f)v22.m_quad;
  v16 = _mm_mul_ps(_mm_shuffle_ps(v24.m_rotation.m_col1.m_quad, v24.m_rotation.m_col1.m_quad, 201), v22.m_quad);
  *(hkVector4f *)((char *)&v24.m_rotation.m_col1 + 8) = (hkVector4f)v21.m_quad;
  v17 = _mm_sub_ps(v16, _mm_mul_ps(_mm_shuffle_ps(v22.m_quad, v22.m_quad, 201), v23.m_quad));
  v24.m_rotation.m_col2.m_quad = _mm_shuffle_ps(v17, v17, 201);
  hkTransformf::setMul(&v28, bTc, &v24);
  hkTransformf::setMul(&v24, v5, &v28);
  hkTransformf::setMulInverseMul(&v27, v6, &v24);
  v18.m_quad = (__m128)v27.m_rotation.m_col1;
  v7->m_transform_OS_KS[0].m_rotation.m_col0 = v27.m_rotation.m_col0;
  v19.m_quad = (__m128)v27.m_rotation.m_col2;
  v7->m_transform_OS_KS[0].m_rotation.m_col1 = (hkVector4f)v18.m_quad;
  v20.m_quad = (__m128)v27.m_translation;
  v7->m_transform_OS_KS[0].m_rotation.m_col2 = (hkVector4f)v19.m_quad;
  v7->m_transform_OS_KS[0].m_translation = (hkVector4f)v20.m_quad;
}

// File Line: 267
// RVA: 0xD4ACA0
void __fastcall hkpPointToPathConstraintData::setInBodySpace(hkpPointToPathConstraintData *this, hkVector4f *pivotA, hkVector4f *pivotB, hkpParametricCurve *path)
{
  hkpParametricCurve *v4; // rdi
  hkVector4f *v5; // rsi
  hkVector4f *v6; // rbp
  hkpPointToPathConstraintData *v7; // rbx
  hkReferencedObject *v8; // rcx

  v4 = path;
  v5 = pivotB;
  v6 = pivotA;
  v7 = this;
  if ( path )
    hkReferencedObject::addReference((hkReferencedObject *)&path->vfptr);
  v8 = (hkReferencedObject *)&v7->m_path->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v7->m_path = v4;
  v7->m_transform_OS_KS[0].m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v7->m_transform_OS_KS[0].m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v7->m_transform_OS_KS[0].m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v7->m_transform_OS_KS[0].m_translation = 0i64;
  v7->m_transform_OS_KS[1].m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v7->m_transform_OS_KS[1].m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v7->m_transform_OS_KS[1].m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v7->m_transform_OS_KS[1].m_translation = 0i64;
  v7->m_transform_OS_KS[0].m_translation = (hkVector4f)v6->m_quad;
  v7->m_transform_OS_KS[1].m_translation = (hkVector4f)v5->m_quad;
}

