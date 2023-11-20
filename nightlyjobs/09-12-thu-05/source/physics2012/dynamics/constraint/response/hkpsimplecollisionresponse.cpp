// File Line: 30
// RVA: 0xD92860
void __fastcall hkpSimpleCollisionResponse::solveSingleContact(hkContactPoint *cp, float time, hkpSimpleConstraintUtilCollideParams *params, hkpMotion *bodyA)
{
  hkVector4f v4; // xmm2
  hkMotionState *v5; // rdi
  hkContactPoint *v6; // r14
  hkpMotion *v7; // r12
  hkpSimpleConstraintUtilCollideParams *v8; // rsi
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  hkBaseObjectVtbl *v11; // rax
  __int64 v12; // rax
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm6
  __m128 v24; // xmm5
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm2
  __int64 v29; // rax
  __m128 v30; // xmm7
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __int64 v35; // rax
  __int64 v36; // r8
  hkpBodyVelocity velB; // [rsp+40h] [rbp-98h]
  hkpBodyVelocity velA; // [rsp+60h] [rbp-78h]
  __m128 v39; // [rsp+88h] [rbp-50h]
  hkpBodyVelocity v40; // [rsp+98h] [rbp-40h]
  hkMatrix3f directions; // [rsp+B8h] [rbp-20h]
  hkpSimpleConstraintInfoInitInput v42; // [rsp+E8h] [rbp+10h]
  hkpSimpleConstraintInfoInitInput bodyAa; // [rsp+148h] [rbp+70h]
  hkpSimpleConstraintInfo out; // [rsp+1A8h] [rbp+D0h]
  unsigned int v45; // [rsp+3B0h] [rbp+2D8h]
  char *retaddr; // [rsp+3C8h] [rbp+2F0h]
  __int64 *v47; // [rsp+3D0h] [rbp+2F8h]
  float v48[6]; // [rsp+3D8h] [rbp+300h]

  v48[0] = time;
  v4.m_quad = (__m128)bodyA->m_motionState.m_sweptTransform.m_centerOfMass0;
  v5 = &bodyA->m_motionState;
  v6 = cp;
  v7 = bodyA;
  v8 = params;
  v9 = _mm_shuffle_ps(
         bodyA->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
         bodyA->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
         255);
  bodyAa.m_invMasses = bodyA->m_inertiaAndMassInv;
  v10 = _mm_shuffle_ps((__m128)v45, (__m128)v45, 0);
  v11 = bodyA->vfptr;
  bodyAa.m_massRelPos.m_quad = _mm_sub_ps(
                                 cp->m_position.m_quad,
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_mul_ps(_mm_sub_ps(v10, _mm_shuffle_ps(v4.m_quad, v4.m_quad, 255)), v9),
                                     _mm_sub_ps(bodyA->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad, v4.m_quad)),
                                   v4.m_quad));
  v11[6].__vecDelDtor((hkBaseObject *)&bodyA->vfptr, (unsigned int)&bodyAa.m_invInertia.m_col2.m_quad.m128_u32[2]);
  v12 = *(_QWORD *)retaddr;
  v42.m_invMasses = (hkVector4f)*((_OWORD *)retaddr + 13);
  v13 = *((__m128 *)retaddr + 6);
  v14 = *((__m128 *)retaddr + 7);
  bodyAa.m_transform = &v5->m_transform;
  v42.m_massRelPos.m_quad = _mm_sub_ps(
                              v6->m_position.m_quad,
                              _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps(v10, _mm_shuffle_ps(v13, v13, 255)),
                                    _mm_shuffle_ps(v14, v14, 255)),
                                  _mm_sub_ps(*((__m128 *)retaddr + 7), v13)),
                                v13));
  (*(void (__fastcall **)(char *, hkMatrix3f *))(v12 + 96))(retaddr, &v42.m_invInertia);
  v15.m_quad = (__m128)v7->m_linearVelocity;
  v42.m_transform = (hkTransformf *)(retaddr + 32);
  v16.m_quad = (__m128)v7->m_angularVelocity;
  v17 = v5->m_sweptTransform.m_centerOfMass1.m_quad;
  velA.m_linear = (hkVector4f)v15.m_quad;
  v18 = _mm_shuffle_ps(v17, v17, 255);
  v19.m_quad = (__m128)*((_OWORD *)retaddr + 14);
  velA.m_angular = (hkVector4f)v16.m_quad;
  v20.m_quad = (__m128)*((_OWORD *)retaddr + 15);
  velB.m_linear = (hkVector4f)v19.m_quad;
  v21 = v5->m_sweptTransform.m_centerOfMass1.m_quad;
  velB.m_angular = (hkVector4f)v20.m_quad;
  v22 = _mm_shuffle_ps(*((__m128 *)retaddr + 7), *((__m128 *)retaddr + 7), 255);
  *(__m128 *)((char *)&velA.m_angular.m_quad + 8) = _mm_mul_ps(
                                                      _mm_sub_ps(v21, v5->m_sweptTransform.m_centerOfMass0.m_quad),
                                                      v18);
  v39 = _mm_mul_ps(v5->m_deltaAngle.m_quad, v18);
  v40.m_linear.m_quad = _mm_mul_ps(_mm_sub_ps(*((__m128 *)retaddr + 7), *((__m128 *)retaddr + 6)), v22);
  v40.m_angular.m_quad = _mm_mul_ps(*((__m128 *)retaddr + 11), v22);
  directions.m_col0 = v6->m_separatingNormal;
  v23 = _mm_shuffle_ps(directions.m_col0.m_quad, _mm_unpackhi_ps(directions.m_col0.m_quad, (__m128)0i64), 196);
  v24 = _mm_shuffle_ps(v23, v23, 241);
  v25 = _mm_shuffle_ps(v23, v23, 206);
  v26 = _mm_mul_ps(v25, v25);
  v27 = _mm_mul_ps(v24, v24);
  v28 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
            _mm_shuffle_ps(v27, v27, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
            _mm_shuffle_ps(v26, v26, 170)));
  v29 = *v47;
  v30 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v28, v24), _mm_and_ps(v25, v28)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v31 = _mm_mul_ps(v30, v30);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v33 = _mm_rsqrt_ps(v32);
  directions.m_col1.m_quad = _mm_mul_ps(
                               v30,
                               _mm_andnot_ps(
                                 _mm_cmpleps(v32, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v33))));
  v34 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(directions.m_col1.m_quad, directions.m_col1.m_quad, 201), directions.m_col0.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(directions.m_col0.m_quad, directions.m_col0.m_quad, 201), directions.m_col1.m_quad));
  directions.m_col2.m_quad = _mm_shuffle_ps(v34, v34, 201);
  (*(void (__fastcall **)(__int64 *, hkContactPoint *, hkpSimpleConstraintInfoInitInput *, hkpBodyVelocity *, hkpSimpleConstraintInfoInitInput *, hkpBodyVelocity *))(v29 + 112))(
    v47,
    v6,
    &bodyAa,
    &velA,
    &v42,
    &velB);
  hkSimpleConstraintUtil_InitInfo(&bodyAa, &v42, &directions, &out);
  v21.m128_f32[0] = hkSimpleConstraintUtil_Collide(&out, v8, &velA, &velB);
  v35 = *v47;
  **(_DWORD **)v48 = v21.m128_i32[0];
  (*(void (__fastcall **)(__int64 *, hkContactPoint *, __int64, hkpSimpleConstraintInfoInitInput *, hkpBodyVelocity *, hkpSimpleConstraintInfoInitInput *, hkpBodyVelocity *))(v35 + 120))(
    v47,
    v6,
    v36,
    &bodyAa,
    &velA,
    &v42,
    &velB);
  hkSimpleConstraintUtil_getPointVelocity(
    &out,
    (hkpBodyVelocity *)((char *)&velA + 24),
    &velB,
    (hkVector4f *)((char *)&velA.m_linear + 8));
  hkSimpleConstraintUtil_getPointVelocity(&out, &velA, &v40, (hkVector4f *)((char *)&velB.m_angular + 8));
  v34.m128_i32[0] = velB.m_angular.m_quad.m128_i32[2];
  *(float *)(*(_QWORD *)v48 + 4i64) = velA.m_linear.m_quad.m128_f32[2];
  *(_DWORD *)(*(_QWORD *)v48 + 8i64) = v34.m128_i32[0];
  if ( v7->m_type.m_storage != 5 )
  {
    v7->vfptr[9].__vecDelDtor((hkBaseObject *)&v7->vfptr, (unsigned int)&velA);
    ((void (__fastcall *)(hkpMotion *, hkVector4f *))v7->vfptr[9].__first_virtual_table_function__)(v7, &velA.m_angular);
  }
  if ( retaddr[16] != 5 )
  {
    (*(void (__fastcall **)(char *, hkpBodyVelocity *))(*(_QWORD *)retaddr + 144i64))(retaddr, &velB);
    (*(void (__fastcall **)(char *, hkVector4f *))(*(_QWORD *)retaddr + 152i64))(retaddr, &velB.m_angular);
  }
}

// File Line: 130
// RVA: 0xD92C50
void __fastcall hkpSimpleCollisionResponse::solveSingleContact2(hkpSimpleContactConstraintData *constraintData, hkContactPoint *cp, hkpSimpleConstraintUtilCollideParams *params, hkpRigidBody *rigidBodyA)
{
  __int64 v4; // rsi
  hkVector4f *v5; // r13
  __int64 v6; // rdi
  hkMatrix3f *v7; // r12
  signed __int64 v8; // r15
  hkContactPoint *v9; // rax
  hkMatrix3f *v10; // r14
  hkVector4f v11; // xmm4
  hkVector4f v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  hkVector4f v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __int64 v20; // rdi
  hkVector4f *v21; // rbx
  __m128 v22; // xmm6
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __int64 v28; // rax
  __m128 v29; // xmm7
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __int64 v34; // r8
  hkVector4f *v35; // rdi
  __int64 v36; // rax
  hkVector4f v37; // xmm0
  signed __int64 v38; // r15
  hkVector4f v39; // xmm0
  __int64 v40; // rax
  __m128 *v41; // rax
  __m128 v42; // xmm1
  __int128 v43; // [rsp+40h] [rbp-80h]
  hkMatrix3f v44; // [rsp+50h] [rbp-70h]
  hkMatrix3f aTb; // [rsp+80h] [rbp-40h]
  hkMatrix3f directions; // [rsp+B0h] [rbp-10h]
  hkpSimpleConstraintInfoInitInput v47; // [rsp+E0h] [rbp+20h]
  hkpSimpleConstraintInfoInitInput v48; // [rsp+140h] [rbp+80h]
  hkpSimpleConstraintInfo out; // [rsp+1A0h] [rbp+E0h]
  __int64 *v50; // [rsp+3C0h] [rbp+300h]
  hkVector4f *v51; // [rsp+3C8h] [rbp+308h]
  hkpSimpleConstraintUtilCollideParams *paramsa; // [rsp+3D0h] [rbp+310h]
  __int64 v53; // [rsp+3D8h] [rbp+318h]
  __int64 v54; // [rsp+3E0h] [rbp+320h]
  hkVector4f *v55; // [rsp+3E8h] [rbp+328h]
  hkVector4f *vars0; // [rsp+3F0h] [rbp+330h]
  float *retaddr; // [rsp+3F8h] [rbp+338h]

  v4 = (__int64)v55;
  v5 = vars0;
  v6 = v54;
  *((_QWORD *)&v43 + 1) = 2i64;
  *(_QWORD *)&v43 = rigidBodyA;
  v7 = &v44;
  v8 = 2i64;
  v9 = cp;
  v10 = &v47.m_invInertia;
  do
  {
    v11.m_quad = *(__m128 *)(v4 + 96);
    v12.m_quad = *(__m128 *)(v4 + 64);
    v13 = v9->m_position.m_quad;
    v10[1].m_col0 = *(hkVector4f *)(v4 + 48);
    v14 = _mm_sub_ps(v13, *(__m128 *)(v4 + 112));
    v7->m_col0 = *(hkVector4f *)(v4 + 16);
    v15.m_quad = *(__m128 *)(v4 + 80);
    v10[-1].m_col2.m_quad = v14;
    v44.m_col1 = (hkVector4f)v15.m_quad;
    v44.m_col0 = (hkVector4f)v12.m_quad;
    v16 = _mm_unpacklo_ps(v12.m_quad, v15.m_quad);
    v17 = _mm_movelh_ps(v16, v11.m_quad);
    v44.m_col2 = (hkVector4f)v11.m_quad;
    v7->m_col1.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(*(__m128 *)(v4 + 32), *(__m128 *)(v4 + 32), 85),
                              _mm_shuffle_ps(_mm_movehl_ps(v17, v16), v11.m_quad, 212)),
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v4 + 32), *(__m128 *)(v4 + 32), 0), v17)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(*(__m128 *)(v4 + 32), *(__m128 *)(v4 + 32), 170),
                            _mm_shuffle_ps(_mm_unpackhi_ps(v12.m_quad, v15.m_quad), v11.m_quad, 228)));
    hkMatrix3f::transpose(&v44);
    v18 = *(__m128 *)(v4 + 48);
    v19 = _mm_shuffle_ps(*(__m128 *)(v4 + 48), v18, 85);
    aTb.m_col2.m_quad = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v44.m_col2.m_quad);
    aTb.m_col0.m_quad = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v44.m_col0.m_quad);
    aTb.m_col1.m_quad = _mm_mul_ps(v19, v44.m_col1.m_quad);
    hkMatrix3f::setMul(v10, &aTb, (hkMatrix3f *)(v4 + 64));
    v10 += 2;
    v7 = (hkMatrix3f *)((char *)v7 + 32);
    v4 = (__int64)v5;
    v10[-1].m_col1.m_quad.m128_u64[0] = v43 + 368;
    v9 = (hkContactPoint *)v51;
    *(_QWORD *)&v43 = v6;
    --v8;
  }
  while ( v8 );
  v20 = (__int64)v50;
  v21 = v51;
  directions.m_col0 = (hkVector4f)v51[1].m_quad;
  v22 = _mm_shuffle_ps(directions.m_col0.m_quad, _mm_unpackhi_ps(directions.m_col0.m_quad, (__m128)0i64), 196);
  v23 = _mm_shuffle_ps(v22, v22, 241);
  v24 = _mm_shuffle_ps(v22, v22, 206);
  v25 = _mm_mul_ps(v24, v24);
  v26 = _mm_mul_ps(v23, v23);
  v27 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
            _mm_shuffle_ps(v26, v26, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170)));
  v28 = *v50;
  v29 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v27, v23), _mm_and_ps(v24, v27)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v30 = _mm_mul_ps(v29, v29);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_rsqrt_ps(v31);
  directions.m_col1.m_quad = _mm_mul_ps(
                               v29,
                               _mm_andnot_ps(
                                 _mm_cmpleps(v31, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v32))));
  v33 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(directions.m_col1.m_quad, directions.m_col1.m_quad, 201), directions.m_col0.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(directions.m_col0.m_quad, directions.m_col0.m_quad, 201), directions.m_col1.m_quad));
  directions.m_col2.m_quad = _mm_shuffle_ps(v33, v33, 201);
  (*(void (__fastcall **)(__int64 *, hkVector4f *, hkpSimpleConstraintInfoInitInput *, hkMatrix3f *, hkpSimpleConstraintInfoInitInput *, hkVector4f *))(v28 + 184))(
    v50,
    v51,
    &v47,
    &v44,
    &v48,
    &v44.m_col2);
  hkSimpleConstraintUtil_InitInfo(&v47, &v48, &directions, &out);
  *retaddr = hkSimpleConstraintUtil_Collide(&out, paramsa, (hkpBodyVelocity *)&v44, (hkpBodyVelocity *)&v44.m_col2);
  (*(void (__fastcall **)(__int64, hkVector4f *, __int64, hkpSimpleConstraintInfoInitInput *, hkMatrix3f *, hkpSimpleConstraintInfoInitInput *, hkVector4f *))(*(_QWORD *)v20 + 192i64))(
    v20,
    v21,
    v34,
    &v47,
    &v44,
    &v48,
    &v44.m_col2);
  v35 = v55;
  v36 = v53;
  v37.m_quad = (__m128)v44.m_col0;
  v55[1] = v44.m_col0;
  v38 = 2i64;
  if ( *(_BYTE *)(v36 + 352) != 5 )
  {
    *(hkVector4f *)(v36 + 560) = (hkVector4f)v37.m_quad;
    *(hkVector4f *)(v36 + 576) = v44.m_col1;
  }
  v39.m_quad = (__m128)v44.m_col2;
  v40 = v54;
  v5[1] = v44.m_col2;
  if ( *(_BYTE *)(v40 + 352) != 5 )
  {
    *(hkVector4f *)(v40 + 560) = (hkVector4f)v39.m_quad;
    *(_OWORD *)(v40 + 576) = v43;
  }
  v41 = &v44.m_col1.m_quad;
  do
  {
    v42 = *v41;
    v41 += 2;
    v35[2].m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), v35[5].m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v35[4].m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v35[6].m_quad));
    v35 = v5;
    --v38;
  }
  while ( v38 );
}

