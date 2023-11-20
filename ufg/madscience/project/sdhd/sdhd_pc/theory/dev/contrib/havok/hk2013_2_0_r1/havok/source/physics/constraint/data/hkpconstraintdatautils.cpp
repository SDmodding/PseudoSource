// File Line: 53
// RVA: 0x486AE0
void __fastcall hkpConstraintDataUtils::convertToPowered(hkpConstraintData *data, hkpConstraintMotor *motor, hkBool enableMotors)
{
  hkpConstraintMotor *v3; // rdi
  hkpLimitedHingeConstraintData *v4; // rbx
  int v5; // eax
  hkErrStream v6; // [rsp+20h] [rbp-228h]
  __int64 v7; // [rsp+38h] [rbp-210h]
  char buf; // [rsp+40h] [rbp-208h]
  char v9; // [rsp+260h] [rbp+18h]

  v9 = enableMotors.m_bool;
  v7 = -2i64;
  v3 = motor;
  v4 = (hkpLimitedHingeConstraintData *)data;
  v5 = ((__int64 (*)(void))data->vfptr[1].__first_virtual_table_function__)();
  if ( v5 == 2 )
  {
    hkpLimitedHingeConstraintData::setMotor(v4, v3);
    hkpLimitedHingeConstraintData::setMotorEnabled(v4, 0i64, (hkBool)v9);
  }
  else if ( v5 == 7 )
  {
    hkpRagdollConstraintData::setTwistMotor((hkpRagdollConstraintData *)v4, v3);
    hkpRagdollConstraintData::setPlaneMotor((hkpRagdollConstraintData *)v4, v3);
    hkpRagdollConstraintData::setConeMotor((hkpRagdollConstraintData *)v4, v3);
    hkpRagdollConstraintData::setMotorsEnabled((hkpRagdollConstraintData *)v4, 0i64, (hkBool)v9);
  }
  else
  {
    hkErrStream::hkErrStream(&v6, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v6.vfptr, "Cannot convert constraint data to a powered constraint.");
    hkError::messageWarning(
      -1413866700,
      &buf,
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\c"
      "onstraint\\data\\hkpconstraintdatautils.cpp",
      76);
    hkOstream::~hkOstream((hkOstream *)&v6.vfptr);
  }
}

// File Line: 83
// RVA: 0x486BD0
hkpConstraintData *__fastcall hkpConstraintDataUtils::createLimited(hkpConstraintData *data)
{
  hkpConstraintData *v1; // rdi
  int v2; // eax
  _QWORD **v4; // rax
  hkpRagdollLimitsData *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  _QWORD **v8; // rax
  hkpHingeLimitsData *v9; // rax
  __int64 v10; // rax
  hkErrStream v11; // [rsp+20h] [rbp-228h]
  __int64 v12; // [rsp+38h] [rbp-210h]
  char buf; // [rsp+40h] [rbp-208h]

  v12 = -2i64;
  v1 = data;
  v2 = ((__int64 (*)(void))data->vfptr[1].__first_virtual_table_function__)();
  if ( v2 == 2 )
  {
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpHingeLimitsData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 176i64);
    if ( v9 )
    {
      hkpHingeLimitsData::hkpHingeLimitsData(v9);
      v7 = v10;
    }
    else
    {
      v7 = 0i64;
    }
    *(_OWORD *)(v7 + 48) = *(_OWORD *)&v1[2].vfptr;
    *(_OWORD *)(v7 + 64) = *(_OWORD *)&v1[2].m_userData;
    *(_OWORD *)(v7 + 80) = *(_OWORD *)&v1[3].m_memSizeAndFlags;
    *(_OWORD *)(v7 + 96) = *(_OWORD *)&v1[4].m_userData;
    *(_OWORD *)(v7 + 112) = *(_OWORD *)&v1[5].m_memSizeAndFlags;
    *(_OWORD *)(v7 + 128) = *(_OWORD *)&v1[6].vfptr;
    *(_DWORD *)(v7 + 144) = *(_DWORD *)&v1[10].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 148) = *(_DWORD *)(&v1[10].m_referenceCount + 1);
    *(_DWORD *)(v7 + 152) = v1[10].m_userData;
    *(_DWORD *)(v7 + 156) = HIDWORD(v1[10].m_userData);
    *(_QWORD *)(v7 + 160) = v1[11].vfptr;
    *(_QWORD *)(v7 + 168) = *(_QWORD *)&v1[11].m_memSizeAndFlags;
    return (hkpConstraintData *)v7;
  }
  if ( v2 == 7 )
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkpRagdollLimitsData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 240i64);
    if ( v5 )
    {
      hkpRagdollLimitsData::hkpRagdollLimitsData(v5);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    *(_OWORD *)(v7 + 48) = *(_OWORD *)&v1[2].vfptr;
    *(_OWORD *)(v7 + 64) = *(_OWORD *)&v1[2].m_userData;
    *(_OWORD *)(v7 + 80) = *(_OWORD *)&v1[3].m_memSizeAndFlags;
    *(_OWORD *)(v7 + 96) = *(_OWORD *)&v1[4].m_userData;
    *(_OWORD *)(v7 + 112) = *(_OWORD *)&v1[5].m_memSizeAndFlags;
    *(_OWORD *)(v7 + 128) = *(_OWORD *)&v1[6].vfptr;
    *(_DWORD *)(v7 + 144) = v1[12].m_userData;
    *(_DWORD *)(v7 + 148) = HIDWORD(v1[12].m_userData);
    *(_DWORD *)(v7 + 152) = v1[13].vfptr;
    *(_DWORD *)(v7 + 156) = HIDWORD(v1[13].vfptr);
    *(_DWORD *)(v7 + 160) = *(_DWORD *)&v1[13].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 164) = *(_DWORD *)(&v1[13].m_referenceCount + 1);
    *(_DWORD *)(v7 + 168) = v1[13].m_userData;
    *(_DWORD *)(v7 + 172) = HIDWORD(v1[13].m_userData);
    *(_DWORD *)(v7 + 208) = *(_DWORD *)&v1[15].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 212) = *(_DWORD *)(&v1[15].m_referenceCount + 1);
    *(_DWORD *)(v7 + 216) = v1[15].m_userData;
    *(_DWORD *)(v7 + 220) = HIDWORD(v1[15].m_userData);
    *(_DWORD *)(v7 + 224) = v1[16].vfptr;
    *(_DWORD *)(v7 + 228) = HIDWORD(v1[16].vfptr);
    *(_DWORD *)(v7 + 232) = *(_DWORD *)&v1[16].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 236) = *(_DWORD *)(&v1[16].m_referenceCount + 1);
    *(_DWORD *)(v7 + 176) = v1[14].vfptr;
    *(_DWORD *)(v7 + 180) = HIDWORD(v1[14].vfptr);
    *(_DWORD *)(v7 + 184) = *(_DWORD *)&v1[14].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 188) = *(_DWORD *)(&v1[14].m_referenceCount + 1);
    *(_DWORD *)(v7 + 192) = v1[14].m_userData;
    *(_DWORD *)(v7 + 196) = HIDWORD(v1[14].m_userData);
    *(_DWORD *)(v7 + 200) = v1[15].vfptr;
    *(_DWORD *)(v7 + 204) = HIDWORD(v1[15].vfptr);
    hkpRagdollLimitsData::setConeLimitStabilization((hkpRagdollLimitsData *)v7, (hkBool)(BYTE6(v1[14].vfptr) != 0));
    return (hkpConstraintData *)v7;
  }
  if ( (unsigned int)(v2 - 18) > 1 )
  {
    hkErrStream::hkErrStream(&v11, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v11.vfptr, "Unsupported constraint type. Cannot generate limits constraints.");
    hkError::messageWarning(
      -1413818406,
      &buf,
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\c"
      "onstraint\\data\\hkpconstraintdatautils.cpp",
      133);
    hkOstream::~hkOstream((hkOstream *)&v11.vfptr);
  }
  else
  {
    hkReferencedObject::addReference(0i64);
  }
  return 0i64;
}

// File Line: 142
// RVA: 0x4878A0
hkResult *__fastcall hkpConstraintDataUtils::getConstraintPivots(hkResult *result, hkpConstraintData *data, hkVector4f *pivotInAOut, hkVector4f *pivotInBOut)
{
  hkVector4f *v4; // rdi
  hkVector4f *v5; // rsi
  hkpConstraintData *v6; // rbx
  hkResult *v7; // r14
  hkVector4f v8; // xmm1
  hkErrStream v10; // [rsp+20h] [rbp-228h]
  __int64 v11; // [rsp+38h] [rbp-210h]
  char buf; // [rsp+40h] [rbp-208h]

  v11 = -2i64;
  v4 = pivotInBOut;
  v5 = pivotInAOut;
  v6 = data;
  v7 = result;
  switch ( ((unsigned int (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data) )
  {
    case 0u:
      *v5 = *(hkVector4f *)&v6[2].vfptr;
      v8.m_quad = *(__m128 *)&v6[2].m_userData;
      goto LABEL_4;
    case 1u:
    case 2u:
    case 7u:
    case 0x17u:
    case 0x18u:
      *v5 = *(hkVector4f *)&v6[4].vfptr;
      v8.m_quad = *(__m128 *)&v6[6].m_userData;
LABEL_4:
      *v4 = (hkVector4f)v8.m_quad;
      v7->m_enum = 0;
      break;
    default:
      hkErrStream::hkErrStream(&v10, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v10.vfptr, "Unsupported type of constraint in getConstraintPivots");
      hkError::messageWarning(
        -1413824709,
        &buf,
        "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\"
        "constraint\\data\\hkpconstraintdatautils.cpp",
        195);
      hkOstream::~hkOstream((hkOstream *)&v10.vfptr);
      *v5 = 0i64;
      *v4 = 0i64;
      v7->m_enum = 1;
      break;
  }
  return v7;
}

// File Line: 207
// RVA: 0x487780
hkResult *__fastcall hkpConstraintDataUtils::getConstraintMotors(hkResult *result, hkpConstraintData *data, hkpConstraintMotor **motor0, hkpConstraintMotor **motor1, hkpConstraintMotor **motor2)
{
  hkpConstraintMotor **v5; // r14
  hkpConstraintMotor **v6; // r15
  hkpRagdollConstraintData *v7; // rsi
  hkResult *v8; // rdi
  int v9; // eax
  hkErrStream v11; // [rsp+20h] [rbp-228h]
  __int64 v12; // [rsp+38h] [rbp-210h]
  char buf; // [rsp+40h] [rbp-208h]

  v12 = -2i64;
  v5 = motor1;
  v6 = motor0;
  v7 = (hkpRagdollConstraintData *)data;
  v8 = result;
  v9 = ((__int64 (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data);
  if ( v9 == 2 )
  {
    *v6 = (hkpConstraintMotor *)v7->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
    *v5 = 0i64;
    *motor2 = 0i64;
    goto LABEL_6;
  }
  if ( v9 == 7 )
  {
    *v6 = hkpRagdollConstraintData::getTwistMotor(v7);
    *v5 = hkpRagdollConstraintData::getConeMotor(v7);
    *motor2 = hkpRagdollConstraintData::getPlaneMotor(v7);
LABEL_6:
    v8->m_enum = 0;
    return v8;
  }
  *motor2 = 0i64;
  *v5 = 0i64;
  *v6 = 0i64;
  hkErrStream::hkErrStream(&v11, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v11.vfptr, "This type of constraint does not have motors");
  hkError::messageWarning(
    -1413815757,
    &buf,
    "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\con"
    "straint\\data\\hkpconstraintdatautils.cpp",
    232);
  hkOstream::~hkOstream((hkOstream *)&v11.vfptr);
  v8->m_enum = 1;
  return v8;
}

// File Line: 242
// RVA: 0x487BC0
hkResult *__fastcall hkpConstraintDataUtils::loosenConstraintLimits(hkResult *result, hkpConstraintData *data, hkTransformf *bodyATransform, hkTransformf *bodyBTransform)
{
  hkTransformf *v4; // rsi
  hkTransformf *v5; // r14
  __m128 *v6; // rbx
  hkResult *v7; // rdi
  int v8; // eax
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm10
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm7
  __m128 v15; // xmm10
  __m128 v16; // xmm9
  __m128 v17; // xmm7
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  float v25; // xmm3_4
  signed __int64 v26; // rax
  __m128 v27; // xmm2
  __m128 v28; // xmm2
  signed __int64 v29; // rax
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  float v32; // xmm1_4
  __m128 v33; // xmm1
  __m128 v34; // xmm13
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm9
  __m128 v40; // xmm7
  __m128 v41; // xmm6
  __m128 v42; // xmm2
  __m128 v43; // xmm5
  __m128 v44; // xmm4
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  float v49; // xmm2_4
  hkVector4f twistAxisAinWorld; // [rsp+40h] [rbp-A8h]
  hkVector4f twistAxisBinWorld; // [rsp+50h] [rbp-98h]
  hkErrStream axisOut; // [rsp+60h] [rbp-88h]
  __int64 v54; // [rsp+78h] [rbp-70h]
  hkVector4f planeAxisAinWorld; // [rsp+88h] [rbp-60h]
  char buf; // [rsp+98h] [rbp-50h]
  hkPadSpu<float> angleOut; // [rsp+330h] [rbp+248h]

  v54 = -2i64;
  v4 = bodyBTransform;
  v5 = bodyATransform;
  v6 = (__m128 *)data;
  v7 = result;
  v8 = ((__int64 (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data);
  if ( v8 == 2 )
  {
    v33 = v6[4];
    v34 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v5->m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v6[4], v33, 0), v5->m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v5->m_rotation.m_col2.m_quad));
    v35 = v6[8];
    v36 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v4->m_rotation.m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v6[8], v35, 85), v4->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), v4->m_rotation.m_col2.m_quad)),
            v34);
    v37 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
            _mm_shuffle_ps(v36, v36, 170));
    v38 = _mm_cmpltps(v37, query.m_quad);
    v39 = _mm_max_ps(g_vectorfConstants[0], _mm_or_ps(_mm_andnot_ps(v38, query.m_quad), _mm_and_ps(v38, v37)));
    v40 = _mm_andnot_ps(*(__m128 *)_xmm, v39);
    v41 = _mm_cmpltps(v40, *(__m128 *)_xmm);
    v42 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v40), *(__m128 *)_xmm);
    v43 = _mm_cmpltps(*(__m128 *)_xmm, v40);
    v44 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v42), v43), _mm_andnot_ps(v43, v40));
    v45 = _mm_or_ps(_mm_andnot_ps(v43, _mm_mul_ps(v40, v40)), _mm_and_ps(v43, v42));
    v46 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v45, *(__m128 *)coeff4), *(__m128 *)coeff3), v45),
                          *(__m128 *)coeff2),
                        v45),
                      *(__m128 *)coeff1),
                    v45),
                  *(__m128 *)coeff0),
                v45),
              v44),
            v44);
    v47 = v6[9];
    v48 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v4->m_rotation.m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v6[9], v47, 85), v4->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v4->m_rotation.m_col2.m_quad)),
            v34);
    LODWORD(v49) = COERCE_UNSIGNED_INT(
                     1.5707964
                   - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                            v41,
                                                            _mm_or_ps(
                                                              _mm_and_ps(
                                                                _mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v46, v46)),
                                                                v43),
                                                              _mm_andnot_ps(v43, v46))) | v41.m128_i32[0] & v40.m128_i32[0]) ^ v39.m128_i32[0] & _xmm[0])) ^ ((unsigned int)*(_OWORD *)&_mm_cmpltps(_mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)), _mm_shuffle_ps(v48, v48, 170)), (__m128)0i64) >> 31 << 31);
    if ( v49 < 0.0 )
    {
      LODWORD(angleOut.m_storage) = v6[15].m128_u32[3];
      v6[15].m128_f32[3] = fminf(angleOut.m_storage, v49 - 0.0099999998);
    }
    else
    {
      angleOut.m_storage = v6[16].m128_f32[0];
      v6[16].m128_f32[0] = fmaxf(angleOut.m_storage, v49 + 0.0099999998);
    }
LABEL_13:
    v7->m_enum = 0;
    return v7;
  }
  if ( v8 == 7 )
  {
    v9 = v6[(unsigned __int8)v6[21].m128_i8[3] + 3];
    twistAxisAinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v5->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v6[(unsigned __int8)v6[21].m128_i8[3] + 3], v9, 85),
                                     v5->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v5->m_rotation.m_col2.m_quad));
    v10 = v6[(unsigned __int8)v6[21].m128_i8[4] + 7];
    v11 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v4->m_rotation.m_col0.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v6[(unsigned __int8)v6[21].m128_i8[4] + 7], v10, 85),
                v4->m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v4->m_rotation.m_col2.m_quad));
    twistAxisBinWorld.m_quad = v11;
    v12 = v6[(unsigned __int8)v6[23].m128_i8[4] + 7];
    v13 = v6[(unsigned __int8)v6[23].m128_i8[3] + 3];
    v14 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v5->m_rotation.m_col0.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(v6[(unsigned __int8)v6[23].m128_i8[3] + 3], v13, 85),
                  v5->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v5->m_rotation.m_col2.m_quad)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v4->m_rotation.m_col0.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(v6[(unsigned __int8)v6[23].m128_i8[4] + 7], v12, 85),
                  v4->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v4->m_rotation.m_col2.m_quad)));
    v15 = _mm_mul_ps(v11, twistAxisAinWorld.m_quad);
    v16 = _mm_movelh_ps(
            _mm_unpacklo_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170))),
            _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad));
    v17 = _mm_andnot_ps(*(__m128 *)_xmm, v16);
    v18 = _mm_cmpltps(v17, *(__m128 *)_xmm);
    v19 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v17), *(__m128 *)_xmm);
    v20 = _mm_cmpltps(*(__m128 *)_xmm, v17);
    v21 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v19), v20), _mm_andnot_ps(v20, v17));
    v22 = _mm_or_ps(_mm_andnot_ps(v20, _mm_mul_ps(v17, v17)), _mm_and_ps(v20, v19));
    v23 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v22, *(__m128 *)coeff4), *(__m128 *)coeff3), v22),
                          *(__m128 *)coeff2),
                        v22),
                      *(__m128 *)coeff1),
                    v22),
                  *(__m128 *)coeff0),
                v22),
              v21),
            v21);
    v24 = _mm_sub_ps(
            *(__m128 *)_xmm,
            _mm_xor_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  v18,
                  _mm_or_ps(_mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v23, v23)), v20), _mm_andnot_ps(v20, v23))),
                _mm_and_ps(v18, v17)),
              _mm_and_ps(*(__m128 *)_xmm, v16)));
    LODWORD(angleOut.m_storage) = v6[21].m128_u32[3];
    v6[21].m128_f32[3] = fmaxf(angleOut.m_storage, v24.m128_f32[0] + 0.0099999998);
    LODWORD(v25) = (unsigned __int128)_mm_shuffle_ps(v24, v24, 85);
    if ( v25 > 1.5707964 )
    {
      angleOut.m_storage = *(float *)&v6[23].m128_u16[4];
      v6[23].m128_f32[2] = fminf(
                             angleOut.m_storage,
                             COERCE_FLOAT(COERCE_UNSIGNED_INT(v25 - 1.5707964) ^ _xmm[0]) - 0.0099999998);
    }
    else
    {
      LODWORD(angleOut.m_storage) = v6[23].m128_u32[3];
      v6[23].m128_f32[3] = fmaxf(angleOut.m_storage, (float)(1.5707964 - v25) + 0.0099999998);
    }
    v26 = (unsigned __int8)v6[19].m128_i8[3];
    v27 = v6[(unsigned __int8)v6[19].m128_i8[3] + 3];
    twistAxisAinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v5->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v6[(unsigned __int8)v6[19].m128_i8[3] + 3], v27, 85),
                                     v5->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v5->m_rotation.m_col2.m_quad));
    v28 = v6[v26 + 7];
    twistAxisBinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v4->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(v6[v26 + 7], v28, 85), v4->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v4->m_rotation.m_col2.m_quad));
    v29 = (unsigned __int8)v6[19].m128_i8[4];
    v30 = v6[(unsigned __int8)v6[19].m128_i8[4] + 3];
    planeAxisAinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v5->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v6[(unsigned __int8)v6[19].m128_i8[4] + 3], v30, 85),
                                     v5->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v5->m_rotation.m_col2.m_quad));
    v31 = v6[v29 + 7];
    *(__m128 *)&axisOut.m_memSizeAndFlags = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v4->m_rotation.m_col0.m_quad),
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(v6[v29 + 7], v31, 85),
                                                  v4->m_rotation.m_col1.m_quad)),
                                              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v4->m_rotation.m_col2.m_quad));
    hkInternalConstraintUtils_calcRelativeAngle(
      &twistAxisAinWorld,
      &twistAxisBinWorld,
      &planeAxisAinWorld,
      (hkVector4f *)&axisOut.m_memSizeAndFlags,
      (hkVector4f *)&axisOut,
      &angleOut);
    v32 = angleOut.m_storage;
    if ( angleOut.m_storage < 0.0 )
    {
      angleOut.m_storage = *(float *)&v6[19].m128_u16[4];
      v6[19].m128_f32[2] = fminf(angleOut.m_storage, v32 - 0.0099999998);
    }
    else
    {
      LODWORD(angleOut.m_storage) = v6[19].m128_u32[3];
      v6[19].m128_f32[3] = fmaxf(angleOut.m_storage, v32 + 0.0099999998);
    }
    goto LABEL_13;
  }
  hkErrStream::hkErrStream(&axisOut, &buf, 512);
  hkOstream::operator<<((hkOstream *)&axisOut.vfptr, "This type of constraint is not supported for loosening.");
  hkError::messageWarning(
    2052067984,
    &buf,
    "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\con"
    "straint\\data\\hkpconstraintdatautils.cpp",
    368);
  hkOstream::~hkOstream((hkOstream *)&axisOut.vfptr);
  v7->m_enum = 1;
  return v7;
}

// File Line: 618
// RVA: 0x4879E0
hkpConstraintData *__fastcall hkpConstraintDataUtils::getPivotA(hkpConstraintData *data)
{
  hkpConstraintData *v1; // rbx
  unsigned int v2; // eax

  v1 = data;
  v2 = ((__int64 (*)(void))data->vfptr[1].__first_virtual_table_function__)();
  while ( 1 )
  {
    switch ( v2 )
    {
      case 0u:
      case 8u:
      case 0xFu:
        return v1 + 2;
      case 1u:
      case 2u:
      case 6u:
      case 7u:
      case 9u:
      case 0xEu:
      case 0x17u:
      case 0x18u:
        return v1 + 4;
      case 0xCu:
        v1 = (hkpConstraintData *)v1[2].m_userData;
        goto LABEL_5;
      case 0xDu:
        v1 = hkpMalleableConstraintData::getWrappedConstraintData((hkpMalleableConstraintData *)v1);
LABEL_5:
        v2 = ((__int64 (__fastcall *)(hkpConstraintData *))v1->vfptr[1].__first_virtual_table_function__)(v1);
        if ( v2 > 0x18 )
          return (hkpConstraintData *)&aabbOut;
        break;
      default:
        return (hkpConstraintData *)&aabbOut;
    }
  }
}

// File Line: 665
// RVA: 0x487AD0
hkVector4f *__fastcall hkpConstraintDataUtils::getPivotB(hkpConstraintData *data)
{
  hkpConstraintData *v1; // rbx
  unsigned int v2; // eax

  v1 = data;
  v2 = ((__int64 (*)(void))data->vfptr[1].__first_virtual_table_function__)();
  while ( 1 )
  {
    switch ( v2 )
    {
      case 0u:
      case 8u:
      case 0xFu:
        return (hkVector4f *)&v1[2].m_userData;
      case 1u:
      case 2u:
      case 6u:
      case 7u:
      case 9u:
      case 0xEu:
      case 0x17u:
      case 0x18u:
        return (hkVector4f *)&v1[6].m_userData;
      case 0xCu:
        v1 = (hkpConstraintData *)v1[2].m_userData;
        goto LABEL_5;
      case 0xDu:
        v1 = hkpMalleableConstraintData::getWrappedConstraintData((hkpMalleableConstraintData *)v1);
LABEL_5:
        v2 = ((__int64 (__fastcall *)(hkpConstraintData *))v1->vfptr[1].__first_virtual_table_function__)(v1);
        if ( v2 > 0x18 )
          return &aabbOut;
        break;
      default:
        return &aabbOut;
    }
  }
}

// File Line: 858
// RVA: 0x486190
hkpConstraintData *__fastcall hkpConstraintDataUtils::cloneIfCanHaveMotors(hkpConstraintData *data)
{
  hkpConstraintData *v1; // rdi
  int v2; // eax
  int v3; // eax
  _QWORD **v5; // rax
  hkpRagdollConstraintData *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  signed __int64 v9; // rdi
  signed __int64 v10; // rsi
  _QWORD **v11; // rax
  hkpPrismaticConstraintData *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rcx
  _QWORD **v15; // rax
  hkpLimitedHingeConstraintData *v16; // rax
  __int64 v17; // rax
  __int64 v18; // rcx

  v1 = data;
  v2 = (unsigned __int64)((__int64 (__cdecl *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data)
     - 2;
  if ( v2 )
  {
    v3 = v2 - 4;
    if ( v3 )
    {
      if ( v3 != 1 )
        return 0i64;
      v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (hkpRagdollConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(
                                         v5[11],
                                         416i64);
      if ( v6 )
      {
        hkpRagdollConstraintData::hkpRagdollConstraintData(v6);
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      hkpRagdollConstraintData::Atoms::operator=(
        (hkpRagdollConstraintData::Atoms *)(v8 + 32),
        (hkpRagdollConstraintData::Atoms *)&v1[1].m_memSizeAndFlags);
      *(_QWORD *)(v8 + 16) = v1->m_userData;
      v9 = v8 + 256;
      v10 = 3i64;
      do
      {
        if ( *(_QWORD *)v9 )
          *(_QWORD *)v9 = (*(__int64 (**)(void))(**(_QWORD **)v9 + 24i64))();
        v9 += 8i64;
        --v10;
      }
      while ( v10 );
    }
    else
    {
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkpPrismaticConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                            v11[11],
                                            288i64);
      if ( v12 )
      {
        hkpPrismaticConstraintData::hkpPrismaticConstraintData(v12);
        v8 = v13;
      }
      else
      {
        v8 = 0i64;
      }
      hkpPrismaticConstraintData::Atoms::operator=(
        (hkpPrismaticConstraintData::Atoms *)(v8 + 32),
        (hkpPrismaticConstraintData::Atoms *)&v1[1].m_memSizeAndFlags);
      *(_QWORD *)(v8 + 16) = v1->m_userData;
      v14 = *(_QWORD *)(v8 + 192);
      if ( v14 )
        *(_QWORD *)(v8 + 192) = (*(__int64 (**)(void))(*(_QWORD *)v14 + 24i64))();
    }
  }
  else
  {
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                             v15[11],
                                             304i64);
    if ( v16 )
    {
      hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v16);
      v8 = v17;
    }
    else
    {
      v8 = 0i64;
    }
    hkpLimitedHingeConstraintData::Atoms::operator=(
      (hkpLimitedHingeConstraintData::Atoms *)(v8 + 32),
      (hkpLimitedHingeConstraintData::Atoms *)&v1[1].m_memSizeAndFlags);
    *(_QWORD *)(v8 + 16) = v1->m_userData;
    v18 = *(_QWORD *)(v8 + 208);
    if ( v18 )
      *(_QWORD *)(v8 + 208) = (*(__int64 (**)(void))(*(_QWORD *)v18 + 24i64))();
  }
  return (hkpConstraintData *)v8;
}

// File Line: 956
// RVA: 0x486EF0
hkpConstraintData *__fastcall hkpConstraintDataUtils::deepClone(hkpConstraintData *data)
{
  hkpConstraintData *v1; // rbx
  _QWORD **v2; // rax
  hkpBallAndSocketConstraintData *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rsi
  hkpConstraintData *result; // rax
  _QWORD **v7; // rax
  hkpFixedConstraintData *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rsi
  int v11; // er8
  _QWORD **v12; // rax
  hkpDeformableFixedConstraintData *v13; // rax
  hkpConstraintData *v14; // rax
  hkpConstraintData *v15; // rsi
  _QWORD **v16; // rax
  hkpHingeConstraintData *v17; // rax
  __int64 v18; // rax
  _QWORD **v19; // rax
  hkpStiffSpringConstraintData *v20; // rax
  __int64 v21; // rax
  _QWORD **v22; // rax
  hkpWheelConstraintData *v23; // rax
  __int64 v24; // rax
  _QWORD **v25; // rax
  hkpPointToPlaneConstraintData *v26; // rax
  __int64 v27; // rax
  _QWORD **v28; // rax
  hkpPulleyConstraintData *v29; // rax
  __int64 v30; // rax
  _QWORD **v31; // rax
  hkpHingeLimitsData *v32; // rax
  __int64 v33; // rax
  _QWORD **v34; // rax
  hkpRagdollLimitsData *v35; // rax
  __int64 v36; // rax
  _QWORD **v37; // rax
  hkpLimitedHingeConstraintData *v38; // rax
  __int64 v39; // rax
  hkReferencedObject *v40; // rcx
  _QWORD **v41; // rax
  hkpPointToPathConstraintData *v42; // rax
  __int64 v43; // rax
  hkpParametricCurve *v44; // rdi
  hkReferencedObject *v45; // rbx
  _QWORD **v46; // rax
  hkpPrismaticConstraintData *v47; // rax
  __int64 v48; // rax
  hkReferencedObject *v49; // rcx
  _QWORD **v50; // rax
  hkpRagdollConstraintData *v51; // rax
  __int64 v52; // rax
  hkpConstraintMotor *v53; // rax
  hkpConstraintMotor *v54; // rax
  hkpConstraintMotor *v55; // rax

  v1 = data;
  switch ( ((unsigned int (__cdecl *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data) )
  {
    case 0u:
      v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v3 = (hkpBallAndSocketConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                               v2[11],
                                               112i64);
      if ( v3 )
      {
        hkpBallAndSocketConstraintData::hkpBallAndSocketConstraintData(v3);
        v5 = v4;
      }
      else
      {
        v5 = 0i64;
      }
      hkString::memCpy((void *)(v5 + 32), &v1[1].m_memSizeAndFlags, 80);
      return (hkpConstraintData *)v5;
    case 1u:
      v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v17 = (hkpHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(
                                        v16[11],
                                        224i64);
      if ( v17 )
      {
        hkpHingeConstraintData::hkpHingeConstraintData(v17);
        v10 = v18;
      }
      else
      {
        v10 = 0i64;
      }
      goto LABEL_9;
    case 2u:
      v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v37[11] + 8i64))(
                                               v37[11],
                                               304i64);
      if ( v38 )
      {
        hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v38);
        v10 = v39;
      }
      else
      {
        v10 = 0i64;
      }
      hkString::memCpy((void *)(v10 + 32), &v1[1].m_memSizeAndFlags, 264);
      v40 = *(hkReferencedObject **)(v10 + 208);
      if ( v40 )
        hkReferencedObject::addReference(v40);
      goto LABEL_11;
    case 3u:
      v41 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v42 = (hkpPointToPathConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v41[11] + 8i64))(
                                              v41[11],
                                              208i64);
      if ( v42 )
      {
        hkpPointToPathConstraintData::hkpPointToPathConstraintData(v42);
        v10 = v43;
      }
      else
      {
        v10 = 0i64;
      }
      hkString::memCpy((void *)(v10 + 32), &v1[1].m_memSizeAndFlags, 32);
      v44 = (hkpParametricCurve *)v1[2].m_userData;
      v45 = (hkReferencedObject *)((__int64 (__fastcall *)(unsigned __int64))v44->vfptr[6].__first_virtual_table_function__)(v1[2].m_userData);
      hkpPointToPathConstraintData::setPath((hkpPointToPathConstraintData *)v10, v44);
      hkReferencedObject::removeReference(v45);
      goto LABEL_11;
    case 6u:
      v46 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v47 = (hkpPrismaticConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v46[11] + 8i64))(
                                            v46[11],
                                            288i64);
      if ( v47 )
      {
        hkpPrismaticConstraintData::hkpPrismaticConstraintData(v47);
        v10 = v48;
      }
      else
      {
        v10 = 0i64;
      }
      hkString::memCpy((void *)(v10 + 32), &v1[1].m_memSizeAndFlags, 248);
      v49 = *(hkReferencedObject **)(v10 + 192);
      if ( v49 )
        hkReferencedObject::addReference(v49);
      goto LABEL_11;
    case 7u:
      v50 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v51 = (hkpRagdollConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v50[11] + 8i64))(
                                          v50[11],
                                          416i64);
      if ( v51 )
      {
        hkpRagdollConstraintData::hkpRagdollConstraintData(v51);
        v10 = v52;
      }
      else
      {
        v10 = 0i64;
      }
      hkString::memCpy((void *)(v10 + 32), &v1[1].m_memSizeAndFlags, 384);
      if ( hkpRagdollConstraintData::getTwistMotor((hkpRagdollConstraintData *)v10) )
      {
        v53 = hkpRagdollConstraintData::getTwistMotor((hkpRagdollConstraintData *)v10);
        hkReferencedObject::addReference((hkReferencedObject *)&v53->vfptr);
      }
      if ( hkpRagdollConstraintData::getConeMotor((hkpRagdollConstraintData *)v10) )
      {
        v54 = hkpRagdollConstraintData::getConeMotor((hkpRagdollConstraintData *)v10);
        hkReferencedObject::addReference((hkReferencedObject *)&v54->vfptr);
      }
      if ( hkpRagdollConstraintData::getPlaneMotor((hkpRagdollConstraintData *)v10) )
      {
        v55 = hkpRagdollConstraintData::getPlaneMotor((hkpRagdollConstraintData *)v10);
        hkReferencedObject::addReference((hkReferencedObject *)&v55->vfptr);
      }
      goto LABEL_11;
    case 8u:
      v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (hkpStiffSpringConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(
                                              v19[11],
                                              112i64);
      if ( v20 )
      {
        hkpStiffSpringConstraintData::hkpStiffSpringConstraintData(v20);
        v10 = v21;
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 76;
      goto LABEL_10;
    case 9u:
      v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v23 = (hkpWheelConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(
                                        v22[11],
                                        400i64);
      if ( v23 )
      {
        hkpWheelConstraintData::hkpWheelConstraintData(v23);
        v10 = v24;
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 336;
      goto LABEL_10;
    case 0xEu:
      v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (hkpPointToPlaneConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(
                                               v25[11],
                                               192i64);
      if ( v26 )
      {
        hkpPointToPlaneConstraintData::hkpPointToPlaneConstraintData(v26);
        v10 = v27;
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 160;
      goto LABEL_10;
    case 0xFu:
      v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v29 = (hkpPulleyConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(
                                         v28[11],
                                         144i64);
      if ( v29 )
      {
        hkpPulleyConstraintData::hkpPulleyConstraintData(v29);
        v10 = v30;
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 112;
      goto LABEL_10;
    case 0x12u:
      v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v32 = (hkpHingeLimitsData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v31[11] + 8i64))(
                                    v31[11],
                                    176i64);
      if ( v32 )
      {
        hkpHingeLimitsData::hkpHingeLimitsData(v32);
        v10 = v33;
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 144;
      goto LABEL_10;
    case 0x13u:
      v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v35 = (hkpRagdollLimitsData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v34[11] + 8i64))(
                                      v34[11],
                                      240i64);
      if ( v35 )
      {
        hkpRagdollLimitsData::hkpRagdollLimitsData(v35);
        v10 = v36;
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 208;
      goto LABEL_10;
    case 0x17u:
      v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v8 = (hkpFixedConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(
                                       v7[11],
                                       224i64);
      if ( v8 )
      {
        hkpFixedConstraintData::hkpFixedConstraintData(v8);
        v10 = v9;
      }
      else
      {
        v10 = 0i64;
      }
LABEL_9:
      v11 = 192;
LABEL_10:
      hkString::memCpy((void *)(v10 + 32), &v1[1].m_memSizeAndFlags, v11);
LABEL_11:
      result = (hkpConstraintData *)v10;
      break;
    case 0x18u:
      v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpDeformableFixedConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                                  v12[11],
                                                  368i64);
      if ( v13 )
      {
        hkpDeformableFixedConstraintData::hkpDeformableFixedConstraintData(v13);
        v15 = v14;
      }
      else
      {
        v15 = 0i64;
      }
      hkString::memCpy(&v15[1].m_memSizeAndFlags, &v1[1].m_memSizeAndFlags, 336);
      result = v15;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

