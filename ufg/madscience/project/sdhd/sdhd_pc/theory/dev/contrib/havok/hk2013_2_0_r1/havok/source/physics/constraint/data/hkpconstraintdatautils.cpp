// File Line: 53
// RVA: 0x486AE0
void __fastcall hkpConstraintDataUtils::convertToPowered(
        hkpLimitedHingeConstraintData *data,
        hkpConstraintMotor *motor,
        hkBool enableMotors)
{
  int v5; // eax
  hkErrStream v6; // [rsp+20h] [rbp-228h] BYREF
  __int64 v7; // [rsp+38h] [rbp-210h]
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  v7 = -2i64;
  v5 = ((__int64 (__fastcall *)(hkpLimitedHingeConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data);
  if ( v5 == 2 )
  {
    hkpLimitedHingeConstraintData::setMotor(data, motor);
    hkpLimitedHingeConstraintData::setMotorEnabled(data, 0i64, enableMotors);
  }
  else if ( v5 == 7 )
  {
    hkpRagdollConstraintData::setTwistMotor((hkpRagdollConstraintData *)data, motor);
    hkpRagdollConstraintData::setPlaneMotor((hkpRagdollConstraintData *)data, motor);
    hkpRagdollConstraintData::setConeMotor((hkpRagdollConstraintData *)data, motor);
    hkpRagdollConstraintData::setMotorsEnabled((hkpRagdollConstraintData *)data, 0i64, enableMotors);
  }
  else
  {
    hkErrStream::hkErrStream(&v6, buf, 512);
    hkOstream::operator<<(&v6, "Cannot convert constraint data to a powered constraint.");
    hkError::messageWarning(
      -1413866700,
      buf,
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\c"
      "onstraint\\data\\hkpconstraintdatautils.cpp",
      76);
    hkOstream::~hkOstream(&v6);
  }
}

// File Line: 83
// RVA: 0x486BD0
hkpConstraintData *__fastcall hkpConstraintDataUtils::createLimited(hkpConstraintData *data)
{
  int v2; // eax
  _QWORD **v4; // rax
  hkpRagdollLimitsData *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  _QWORD **Value; // rax
  hkpHingeLimitsData *v9; // rax
  __int64 v10; // rax
  hkErrStream v11; // [rsp+20h] [rbp-228h] BYREF
  __int64 v12; // [rsp+38h] [rbp-210h]
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  v12 = -2i64;
  v2 = ((__int64 (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data);
  if ( v2 == 2 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpHingeLimitsData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 176i64);
    if ( v9 )
    {
      hkpHingeLimitsData::hkpHingeLimitsData(v9);
      v7 = v10;
    }
    else
    {
      v7 = 0i64;
    }
    *(hkReferencedObject *)(v7 + 48) = data[2].hkReferencedObject;
    *(_OWORD *)(v7 + 64) = *(_OWORD *)&data[2].m_userData;
    *(_OWORD *)(v7 + 80) = *(_OWORD *)&data[3].m_memSizeAndFlags;
    *(_OWORD *)(v7 + 96) = *(_OWORD *)&data[4].m_userData;
    *(_OWORD *)(v7 + 112) = *(_OWORD *)&data[5].m_memSizeAndFlags;
    *(hkReferencedObject *)(v7 + 128) = data[6].hkReferencedObject;
    *(_DWORD *)(v7 + 144) = *(_DWORD *)&data[10].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 148) = *(_DWORD *)(&data[10].m_referenceCount + 1);
    *(_DWORD *)(v7 + 152) = data[10].m_userData;
    *(_DWORD *)(v7 + 156) = HIDWORD(data[10].m_userData);
    *(_QWORD *)(v7 + 160) = data[11].vfptr;
    *(_QWORD *)(v7 + 168) = *(_QWORD *)&data[11].m_memSizeAndFlags;
    return (hkpConstraintData *)v7;
  }
  if ( v2 == 7 )
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkpRagdollLimitsData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v4[11] + 8i64))(v4[11], 240i64);
    if ( v5 )
    {
      hkpRagdollLimitsData::hkpRagdollLimitsData(v5);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    *(hkReferencedObject *)(v7 + 48) = data[2].hkReferencedObject;
    *(_OWORD *)(v7 + 64) = *(_OWORD *)&data[2].m_userData;
    *(_OWORD *)(v7 + 80) = *(_OWORD *)&data[3].m_memSizeAndFlags;
    *(_OWORD *)(v7 + 96) = *(_OWORD *)&data[4].m_userData;
    *(_OWORD *)(v7 + 112) = *(_OWORD *)&data[5].m_memSizeAndFlags;
    *(hkReferencedObject *)(v7 + 128) = data[6].hkReferencedObject;
    *(_DWORD *)(v7 + 144) = data[12].m_userData;
    *(_DWORD *)(v7 + 148) = HIDWORD(data[12].m_userData);
    *(_DWORD *)(v7 + 152) = data[13].vfptr;
    *(_DWORD *)(v7 + 156) = HIDWORD(data[13].vfptr);
    *(_DWORD *)(v7 + 160) = *(_DWORD *)&data[13].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 164) = *(_DWORD *)(&data[13].m_referenceCount + 1);
    *(_DWORD *)(v7 + 168) = data[13].m_userData;
    *(_DWORD *)(v7 + 172) = HIDWORD(data[13].m_userData);
    *(_DWORD *)(v7 + 208) = *(_DWORD *)&data[15].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 212) = *(_DWORD *)(&data[15].m_referenceCount + 1);
    *(_DWORD *)(v7 + 216) = data[15].m_userData;
    *(_DWORD *)(v7 + 220) = HIDWORD(data[15].m_userData);
    *(_DWORD *)(v7 + 224) = data[16].vfptr;
    *(_DWORD *)(v7 + 228) = HIDWORD(data[16].vfptr);
    *(_DWORD *)(v7 + 232) = *(_DWORD *)&data[16].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 236) = *(_DWORD *)(&data[16].m_referenceCount + 1);
    *(_DWORD *)(v7 + 176) = data[14].vfptr;
    *(_DWORD *)(v7 + 180) = HIDWORD(data[14].vfptr);
    *(_DWORD *)(v7 + 184) = *(_DWORD *)&data[14].m_memSizeAndFlags;
    *(_DWORD *)(v7 + 188) = *(_DWORD *)(&data[14].m_referenceCount + 1);
    *(_DWORD *)(v7 + 192) = data[14].m_userData;
    *(_DWORD *)(v7 + 196) = HIDWORD(data[14].m_userData);
    *(_DWORD *)(v7 + 200) = data[15].vfptr;
    *(_DWORD *)(v7 + 204) = HIDWORD(data[15].vfptr);
    hkpRagdollLimitsData::setConeLimitStabilization((hkpRagdollLimitsData *)v7, (hkBool)(BYTE6(data[14].vfptr) != 0));
    return (hkpConstraintData *)v7;
  }
  if ( (unsigned int)(v2 - 18) > 1 )
  {
    hkErrStream::hkErrStream(&v11, buf, 512);
    hkOstream::operator<<(&v11, "Unsupported constraint type. Cannot generate limits constraints.");
    hkError::messageWarning(
      -1413818406,
      buf,
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\c"
      "onstraint\\data\\hkpconstraintdatautils.cpp",
      133);
    hkOstream::~hkOstream(&v11);
  }
  else
  {
    hkReferencedObject::addReference(0i64);
  }
  return 0i64;
}

// File Line: 142
// RVA: 0x4878A0
hkResult *__fastcall hkpConstraintDataUtils::getConstraintPivots(
        hkResult *result,
        hkpConstraintData *data,
        hkVector4f *pivotInAOut,
        hkVector4f *pivotInBOut)
{
  hkVector4f v8; // xmm1
  hkErrStream v10; // [rsp+20h] [rbp-228h] BYREF
  __int64 v11; // [rsp+38h] [rbp-210h]
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  v11 = -2i64;
  switch ( ((unsigned int (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data) )
  {
    case 0u:
      *pivotInAOut = (hkVector4f)data[2].hkReferencedObject;
      v8.m_quad = *(__m128 *)&data[2].m_userData;
      goto LABEL_4;
    case 1u:
    case 2u:
    case 7u:
    case 0x17u:
    case 0x18u:
      *pivotInAOut = (hkVector4f)data[4].hkReferencedObject;
      v8.m_quad = *(__m128 *)&data[6].m_userData;
LABEL_4:
      *pivotInBOut = (hkVector4f)v8.m_quad;
      result->m_enum = HK_SUCCESS;
      break;
    default:
      hkErrStream::hkErrStream(&v10, buf, 512);
      hkOstream::operator<<(&v10, "Unsupported type of constraint in getConstraintPivots");
      hkError::messageWarning(
        -1413824709,
        buf,
        "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\"
        "constraint\\data\\hkpconstraintdatautils.cpp",
        195);
      hkOstream::~hkOstream(&v10);
      *pivotInAOut = 0i64;
      *pivotInBOut = 0i64;
      result->m_enum = HK_FAILURE;
      break;
  }
  return result;
}

// File Line: 207
// RVA: 0x487780
hkResult *__fastcall hkpConstraintDataUtils::getConstraintMotors(
        hkResult *result,
        hkpRagdollConstraintData *data,
        hkpConstraintMotor **motor0,
        hkpConstraintMotor **motor1,
        hkpConstraintMotor **motor2)
{
  int v9; // eax
  hkErrStream v11; // [rsp+20h] [rbp-228h] BYREF
  __int64 v12; // [rsp+38h] [rbp-210h]
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  v12 = -2i64;
  v9 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data);
  if ( v9 == 2 )
  {
    *motor0 = (hkpConstraintMotor *)data->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
    *motor1 = 0i64;
    *motor2 = 0i64;
    goto LABEL_6;
  }
  if ( v9 == 7 )
  {
    *motor0 = hkpRagdollConstraintData::getTwistMotor(data);
    *motor1 = hkpRagdollConstraintData::getConeMotor(data);
    *motor2 = hkpRagdollConstraintData::getPlaneMotor(data);
LABEL_6:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  *motor2 = 0i64;
  *motor1 = 0i64;
  *motor0 = 0i64;
  hkErrStream::hkErrStream(&v11, buf, 512);
  hkOstream::operator<<(&v11, "This type of constraint does not have motors");
  hkError::messageWarning(
    -1413815757,
    buf,
    "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\con"
    "straint\\data\\hkpconstraintdatautils.cpp",
    232);
  hkOstream::~hkOstream(&v11);
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 242
// RVA: 0x487BC0
hkResult *__fastcall hkpConstraintDataUtils::loosenConstraintLimits(
        hkResult *result,
        hkpConstraintData *data,
        hkTransformf *bodyATransform,
        hkTransformf *bodyBTransform)
{
  int v8; // eax
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm7
  __m128 v14; // xmm10
  __m128 v15; // xmm9
  __m128 v16; // xmm7
  __m128 v17; // xmm6
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  float v24; // xmm3_4
  __int64 v25; // rax
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __int64 v28; // rax
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  float m_storage; // xmm1_4
  __m128 v32; // xmm1
  __m128 v33; // xmm13
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm9
  __m128 v39; // xmm7
  __m128 v40; // xmm6
  __m128 v41; // xmm2
  __m128 v42; // xmm5
  __m128 v43; // xmm4
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  hkReferencedObject v46; // xmm1
  __m128 v47; // xmm3
  float v48; // xmm2_4
  hkVector4f twistAxisAinWorld; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f twistAxisBinWorld; // [rsp+50h] [rbp-98h] BYREF
  hkErrStream axisOut; // [rsp+60h] [rbp-88h] BYREF
  __int64 v53; // [rsp+78h] [rbp-70h]
  hkVector4f planeAxisAinWorld; // [rsp+88h] [rbp-60h] BYREF
  char buf[648]; // [rsp+98h] [rbp-50h] BYREF
  hkPadSpu<float> angleOut; // [rsp+330h] [rbp+248h] BYREF

  v53 = -2i64;
  v8 = ((__int64 (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data);
  if ( v8 == 2 )
  {
    v32 = *(__m128 *)&data[2].m_userData;
    v33 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), bodyATransform->m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), bodyATransform->m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), bodyATransform->m_rotation.m_col2.m_quad));
    v34 = *(__m128 *)&data[5].m_memSizeAndFlags;
    v35 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), bodyBTransform->m_rotation.m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), bodyBTransform->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), bodyBTransform->m_rotation.m_col2.m_quad)),
            v33);
    v36 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
            _mm_shuffle_ps(v35, v35, 170));
    v37 = _mm_cmplt_ps(v36, query.m_quad);
    v38 = _mm_max_ps(g_vectorfConstants[0], _mm_or_ps(_mm_andnot_ps(v37, query.m_quad), _mm_and_ps(v37, v36)));
    v39 = _mm_andnot_ps(*(__m128 *)_xmm, v38);
    v40 = _mm_cmplt_ps(v39, *(__m128 *)_xmm);
    v41 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v39), *(__m128 *)_xmm);
    v42 = _mm_cmplt_ps(*(__m128 *)_xmm, v39);
    v43 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v41), v42), _mm_andnot_ps(v42, v39));
    v44 = _mm_or_ps(_mm_andnot_ps(v42, _mm_mul_ps(v39, v39)), _mm_and_ps(v42, v41));
    v45 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v44, *(__m128 *)coeff4), *(__m128 *)coeff3), v44),
                          *(__m128 *)coeff2),
                        v44),
                      *(__m128 *)coeff1),
                    v44),
                  *(__m128 *)coeff0),
                v44),
              v43),
            v43);
    v46 = data[6].hkReferencedObject;
    v47 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)v46, (__m128)v46, 0), bodyBTransform->m_rotation.m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v46, (__m128)v46, 85), bodyBTransform->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v46, (__m128)v46, 170), bodyBTransform->m_rotation.m_col2.m_quad)),
            v33);
    LODWORD(v48) = COERCE_UNSIGNED_INT(
                     1.5707964
                   - COERCE_FLOAT((_mm_andnot_ps(
                                     v40,
                                     _mm_or_ps(
                                       _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v45, v45)), v42),
                                       _mm_andnot_ps(v42, v45))).m128_u32[0] | v40.m128_i32[0] & v39.m128_i32[0]) ^ v38.m128_i32[0] & _xmm[0])) ^ (_mm_cmplt_ps(_mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170)), (__m128)0i64).m128_u32[0] >> 31 << 31);
    if ( v48 < 0.0 )
      *(float *)(&data[10].m_referenceCount + 1) = fminf(*(float *)(&data[10].m_referenceCount + 1), v48 - 0.0099999998);
    else
      *(float *)&data[10].m_userData = fmaxf(*(float *)&data[10].m_userData, v48 + 0.0099999998);
LABEL_13:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  if ( v8 == 7 )
  {
    v9 = *((__m128 *)&data[2].hkReferencedObject + BYTE3(data[14].vfptr));
    twistAxisAinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), bodyATransform->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), bodyATransform->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), bodyATransform->m_rotation.m_col2.m_quad));
    v10 = *((__m128 *)&data[4].m_userData + BYTE4(data[14].vfptr));
    twistAxisBinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), bodyBTransform->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), bodyBTransform->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), bodyBTransform->m_rotation.m_col2.m_quad));
    v11 = *((__m128 *)&data[4].m_userData + *((unsigned __int8 *)&data[15].m_referenceCount + 2));
    v12 = *((__m128 *)&data[2].hkReferencedObject + HIBYTE(data[15].m_referenceCount));
    v13 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), bodyATransform->m_rotation.m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), bodyATransform->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), bodyATransform->m_rotation.m_col2.m_quad)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), bodyBTransform->m_rotation.m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), bodyBTransform->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), bodyBTransform->m_rotation.m_col2.m_quad)));
    v14 = _mm_mul_ps(twistAxisBinWorld.m_quad, twistAxisAinWorld.m_quad);
    v15 = _mm_movelh_ps(
            _mm_unpacklo_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170))),
            _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad));
    v16 = _mm_andnot_ps(*(__m128 *)_xmm, v15);
    v17 = _mm_cmplt_ps(v16, *(__m128 *)_xmm);
    v18 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v16), *(__m128 *)_xmm);
    v19 = _mm_cmplt_ps(*(__m128 *)_xmm, v16);
    v20 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v18), v19), _mm_andnot_ps(v19, v16));
    v21 = _mm_or_ps(_mm_andnot_ps(v19, _mm_mul_ps(v16, v16)), _mm_and_ps(v19, v18));
    v22 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v21, *(__m128 *)coeff4), *(__m128 *)coeff3), v21),
                          *(__m128 *)coeff2),
                        v21),
                      *(__m128 *)coeff1),
                    v21),
                  *(__m128 *)coeff0),
                v21),
              v20),
            v20);
    v23 = _mm_sub_ps(
            *(__m128 *)_xmm,
            _mm_xor_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  v17,
                  _mm_or_ps(_mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v22, v22)), v19), _mm_andnot_ps(v19, v22))),
                _mm_and_ps(v17, v16)),
              _mm_and_ps(*(__m128 *)_xmm, v15)));
    angleOut.m_storage = *(float *)(&data[14].m_referenceCount + 1);
    *(float *)(&data[14].m_referenceCount + 1) = fmaxf(angleOut.m_storage, v23.m128_f32[0] + 0.0099999998);
    v24 = _mm_shuffle_ps(v23, v23, 85).m128_f32[0];
    if ( v24 > 1.5707964 )
    {
      angleOut.m_storage = *(float *)&data[15].m_userData;
      *(float *)&data[15].m_userData = fminf(
                                         angleOut.m_storage,
                                         COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - 1.5707964) ^ _xmm[0]) - 0.0099999998);
    }
    else
    {
      LODWORD(angleOut.m_storage) = *(hkPadSpu<float> *)((char *)&data[15].m_userData + 4);
      *((float *)&data[15].m_userData + 1) = fmaxf(angleOut.m_storage, (float)(1.5707964 - v24) + 0.0099999998);
    }
    v25 = 2i64 * BYTE3(data[12].m_userData);
    v26 = *((__m128 *)&data[2].hkReferencedObject + BYTE3(data[12].m_userData));
    twistAxisAinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), bodyATransform->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), bodyATransform->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), bodyATransform->m_rotation.m_col2.m_quad));
    v27 = *(__m128 *)(&data[4].m_userData + v25);
    twistAxisBinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), bodyBTransform->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), bodyBTransform->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), bodyBTransform->m_rotation.m_col2.m_quad));
    v28 = 2i64 * BYTE4(data[12].m_userData);
    v29 = *((__m128 *)&data[2].hkReferencedObject + BYTE4(data[12].m_userData));
    planeAxisAinWorld.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), bodyATransform->m_rotation.m_col0.m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), bodyATransform->m_rotation.m_col1.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), bodyATransform->m_rotation.m_col2.m_quad));
    v30 = *(__m128 *)(&data[4].m_userData + v28);
    *(__m128 *)&axisOut.m_memSizeAndFlags = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(v30, v30, 0),
                                                  bodyBTransform->m_rotation.m_col0.m_quad),
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(v30, v30, 85),
                                                  bodyBTransform->m_rotation.m_col1.m_quad)),
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(v30, v30, 170),
                                                bodyBTransform->m_rotation.m_col2.m_quad));
    hkInternalConstraintUtils_calcRelativeAngle(
      &twistAxisAinWorld,
      &twistAxisBinWorld,
      &planeAxisAinWorld,
      (hkVector4f *)&axisOut.m_memSizeAndFlags,
      (hkVector4f *)&axisOut,
      &angleOut);
    m_storage = angleOut.m_storage;
    if ( angleOut.m_storage < 0.0 )
    {
      angleOut.m_storage = *(float *)&data[13].vfptr;
      *(float *)&data[13].vfptr = fminf(angleOut.m_storage, m_storage - 0.0099999998);
    }
    else
    {
      LODWORD(angleOut.m_storage) = *(hkPadSpu<float> *)((char *)&data[13].vfptr + 4);
      *((float *)&data[13].vfptr + 1) = fmaxf(angleOut.m_storage, m_storage + 0.0099999998);
    }
    goto LABEL_13;
  }
  hkErrStream::hkErrStream(&axisOut, buf, 512);
  hkOstream::operator<<(&axisOut, "This type of constraint is not supported for loosening.");
  hkError::messageWarning(
    2052067984,
    buf,
    "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\contrib\\havok\\hk2013_2_0_r1\\havok\\source\\physics\\con"
    "straint\\data\\hkpconstraintdatautils.cpp",
    368);
  hkOstream::~hkOstream(&axisOut);
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 618
// RVA: 0x4879E0
hkpConstraintData *__fastcall hkpConstraintDataUtils::getPivotA(hkpConstraintData *data)
{
  hkpConstraintData *m_userData; // rbx
  unsigned int v2; // eax

  m_userData = data;
  v2 = ((__int64 (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data);
  while ( 2 )
  {
    switch ( v2 )
    {
      case 0u:
      case 8u:
      case 0xFu:
        return m_userData + 2;
      case 1u:
      case 2u:
      case 6u:
      case 7u:
      case 9u:
      case 0xEu:
      case 0x17u:
      case 0x18u:
        return m_userData + 4;
      case 0xCu:
        m_userData = (hkpConstraintData *)m_userData[2].m_userData;
        goto LABEL_5;
      case 0xDu:
        m_userData = hkpMalleableConstraintData::getWrappedConstraintData((hkpMalleableConstraintData *)m_userData);
LABEL_5:
        v2 = ((__int64 (__fastcall *)(hkpConstraintData *))m_userData->vfptr[1].__first_virtual_table_function__)(m_userData);
        if ( v2 > 0x18 )
          return (hkpConstraintData *)&aabbOut;
        continue;
      default:
        return (hkpConstraintData *)&aabbOut;
    }
  }
}

// File Line: 665
// RVA: 0x487AD0
hkVector4f *__fastcall hkpConstraintDataUtils::getPivotB(hkpConstraintData *data)
{
  hkpConstraintData *m_userData; // rbx
  unsigned int v2; // eax

  m_userData = data;
  v2 = ((__int64 (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data);
  while ( 2 )
  {
    switch ( v2 )
    {
      case 0u:
      case 8u:
      case 0xFu:
        return (hkVector4f *)&m_userData[2].m_userData;
      case 1u:
      case 2u:
      case 6u:
      case 7u:
      case 9u:
      case 0xEu:
      case 0x17u:
      case 0x18u:
        return (hkVector4f *)&m_userData[6].m_userData;
      case 0xCu:
        m_userData = (hkpConstraintData *)m_userData[2].m_userData;
        goto LABEL_5;
      case 0xDu:
        m_userData = hkpMalleableConstraintData::getWrappedConstraintData((hkpMalleableConstraintData *)m_userData);
LABEL_5:
        v2 = ((__int64 (__fastcall *)(hkpConstraintData *))m_userData->vfptr[1].__first_virtual_table_function__)(m_userData);
        if ( v2 > 0x18 )
          return &aabbOut;
        continue;
      default:
        return &aabbOut;
    }
  }
}

// File Line: 858
// RVA: 0x486190
hkpConstraintData *__fastcall hkpConstraintDataUtils::cloneIfCanHaveMotors(hkpConstraintData *data)
{
  int v2; // eax
  int v3; // eax
  _QWORD **Value; // rax
  hkpRagdollConstraintData *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  _QWORD *v9; // rdi
  __int64 v10; // rsi
  _QWORD **v11; // rax
  hkpPrismaticConstraintData *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rcx
  _QWORD **v15; // rax
  hkpLimitedHingeConstraintData *v16; // rax
  __int64 v17; // rax
  __int64 v18; // rcx

  v2 = ((__int64 (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data) - 2;
  if ( v2 )
  {
    v3 = v2 - 4;
    if ( v3 )
    {
      if ( v3 != 1 )
        return 0i64;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (hkpRagdollConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                         Value[11],
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
        (hkpRagdollConstraintData::Atoms *)&data[1].m_memSizeAndFlags);
      *(_QWORD *)(v8 + 16) = data->m_userData;
      v9 = (_QWORD *)(v8 + 256);
      v10 = 3i64;
      do
      {
        if ( *v9 )
          *v9 = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)*v9 + 24i64))(*v9);
        ++v9;
        --v10;
      }
      while ( v10 );
    }
    else
    {
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkpPrismaticConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v11[11] + 8i64))(
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
        (hkpPrismaticConstraintData::Atoms *)&data[1].m_memSizeAndFlags);
      *(_QWORD *)(v8 + 16) = data->m_userData;
      v14 = *(_QWORD *)(v8 + 192);
      if ( v14 )
        *(_QWORD *)(v8 + 192) = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 24i64))(v14);
    }
  }
  else
  {
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v15[11] + 8i64))(
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
      (hkpLimitedHingeConstraintData::Atoms *)&data[1].m_memSizeAndFlags);
    *(_QWORD *)(v8 + 16) = data->m_userData;
    v18 = *(_QWORD *)(v8 + 208);
    if ( v18 )
      *(_QWORD *)(v8 + 208) = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v18 + 24i64))(v18);
  }
  return (hkpConstraintData *)v8;
}

// File Line: 956
// RVA: 0x486EF0
hkpConstraintData *__fastcall hkpConstraintDataUtils::deepClone(hkpConstraintData *data)
{
  _QWORD **Value; // rax
  hkpBallAndSocketConstraintData *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rsi
  hkpConstraintData *result; // rax
  _QWORD **v7; // rax
  hkpFixedConstraintData *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rsi
  int v11; // r8d
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
  hkpParametricCurve *m_userData; // rdi
  hkReferencedObject *v45; // rbx
  _QWORD **v46; // rax
  hkpPrismaticConstraintData *v47; // rax
  __int64 v48; // rax
  _QWORD **v49; // rax
  hkpRagdollConstraintData *v50; // rax
  __int64 v51; // rax
  hkpConstraintMotor *TwistMotor; // rax
  hkpConstraintMotor *ConeMotor; // rax
  hkpConstraintMotor *PlaneMotor; // rax

  switch ( ((unsigned int (__fastcall *)(hkpConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data) )
  {
    case 0u:
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v3 = (hkpBallAndSocketConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                               Value[11],
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
      hkString::memCpy((void *)(v5 + 32), &data[1].m_memSizeAndFlags, 80);
      return (hkpConstraintData *)v5;
    case 1u:
      v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v17 = (hkpHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 224i64);
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
      v38 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v37[11] + 8i64))(
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
      hkString::memCpy((void *)(v10 + 32), &data[1].m_memSizeAndFlags, 264);
      v40 = *(hkReferencedObject **)(v10 + 208);
      if ( v40 )
        goto LABEL_47;
      goto LABEL_11;
    case 3u:
      v41 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v42 = (hkpPointToPathConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v41[11] + 8i64))(
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
      hkString::memCpy((void *)(v10 + 32), &data[1].m_memSizeAndFlags, 32);
      m_userData = (hkpParametricCurve *)data[2].m_userData;
      v45 = (hkReferencedObject *)((__int64 (__fastcall *)(hkpParametricCurve *))m_userData->vfptr[6].__first_virtual_table_function__)(m_userData);
      hkpPointToPathConstraintData::setPath((hkpPointToPathConstraintData *)v10, m_userData);
      hkReferencedObject::removeReference(v45);
      goto LABEL_11;
    case 6u:
      v46 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v47 = (hkpPrismaticConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v46[11] + 8i64))(
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
      hkString::memCpy((void *)(v10 + 32), &data[1].m_memSizeAndFlags, 248);
      v40 = *(hkReferencedObject **)(v10 + 192);
      if ( v40 )
LABEL_47:
        hkReferencedObject::addReference(v40);
      goto LABEL_11;
    case 7u:
      v49 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v50 = (hkpRagdollConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v49[11] + 8i64))(
                                          v49[11],
                                          416i64);
      if ( v50 )
      {
        hkpRagdollConstraintData::hkpRagdollConstraintData(v50);
        v10 = v51;
      }
      else
      {
        v10 = 0i64;
      }
      hkString::memCpy((void *)(v10 + 32), &data[1].m_memSizeAndFlags, 384);
      if ( hkpRagdollConstraintData::getTwistMotor((hkpRagdollConstraintData *)v10) )
      {
        TwistMotor = hkpRagdollConstraintData::getTwistMotor((hkpRagdollConstraintData *)v10);
        hkReferencedObject::addReference(TwistMotor);
      }
      if ( hkpRagdollConstraintData::getConeMotor((hkpRagdollConstraintData *)v10) )
      {
        ConeMotor = hkpRagdollConstraintData::getConeMotor((hkpRagdollConstraintData *)v10);
        hkReferencedObject::addReference(ConeMotor);
      }
      if ( hkpRagdollConstraintData::getPlaneMotor((hkpRagdollConstraintData *)v10) )
      {
        PlaneMotor = hkpRagdollConstraintData::getPlaneMotor((hkpRagdollConstraintData *)v10);
        hkReferencedObject::addReference(PlaneMotor);
      }
      goto LABEL_11;
    case 8u:
      v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (hkpStiffSpringConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(
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
      v23 = (hkpWheelConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v22[11] + 8i64))(v22[11], 400i64);
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
      v26 = (hkpPointToPlaneConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(
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
      v29 = (hkpPulleyConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v28[11] + 8i64))(v28[11], 144i64);
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
      v32 = (hkpHingeLimitsData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v31[11] + 8i64))(v31[11], 176i64);
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
      v35 = (hkpRagdollLimitsData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v34[11] + 8i64))(v34[11], 240i64);
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
      v8 = (hkpFixedConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v7[11] + 8i64))(v7[11], 224i64);
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
      hkString::memCpy((void *)(v10 + 32), &data[1].m_memSizeAndFlags, v11);
LABEL_11:
      result = (hkpConstraintData *)v10;
      break;
    case 0x18u:
      v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkpDeformableFixedConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v12[11] + 8i64))(
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
      hkString::memCpy(&v15[1].m_memSizeAndFlags, &data[1].m_memSizeAndFlags, 336);
      result = v15;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

