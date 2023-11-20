// File Line: 136
// RVA: 0x14BD1A0
__int64 dynamic_initializer_for__gTransformSpaceEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gTransformSpaceEnum, gTransformSpaceStringList, 4, 0i64);
  return atexit(dynamic_atexit_destructor_for__gTransformSpaceEnum__);
}

// File Line: 140
// RVA: 0x14BD140
__int64 dynamic_initializer_for__gTransformFloatParamRotEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gTransformFloatParamRotEnum,
    gTransformFloatParamRotStringList,
    3,
    0i64);
  return atexit(dynamic_atexit_destructor_for__gTransformFloatParamRotEnum__);
}

// File Line: 144
// RVA: 0x14BD170
__int64 dynamic_initializer_for__gTransformFloatParamTransEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gTransformFloatParamTransEnum,
    gTransformFloatParamTransStringList,
    3,
    0i64);
  return atexit(dynamic_atexit_destructor_for__gTransformFloatParamTransEnum__);
}

// File Line: 190
// RVA: 0x3A9C90
int GetUnitsTime_Frames_Ticks_Str(...)
{
  __m128 v3; // xmm2
  float v4; // xmm3_4
  signed int v5; // ecx
  signed int v6; // ecx

  v3 = (__m128)timeSeconds;
  v3.m128_f32[0] = *(float *)&timeSeconds * 30.0;
  v4 = *(float *)&timeSeconds * 30.0;
  v5 = (signed int)(float)(*(float *)&timeSeconds * 30.0);
  if ( v5 != 0x80000000 && (float)v5 != v3.m128_f32[0] )
    v4 = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] - v4) * 4800.0) * 0.033333335;
  v6 = (signed int)v3.m128_f32[0];
  if ( (signed int)v3.m128_f32[0] != 0x80000000 && (float)v6 != v3.m128_f32[0] )
    v3.m128_f32[0] = (float)(v6 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
  UFG::qSPrintf(buff, buffSize, "%0.f:%0.f", v4, v3.m128_f32[0]);
}

// File Line: 199
// RVA: 0x3A9D40
int GetUnitsTime_Minutes_Seconds_Ticks_Str(...)
{
  __m128 v3; // xmm2
  float v4; // xmm3_4
  signed int v5; // ecx
  float v6; // xmm1_4
  signed int v7; // ecx
  signed int v8; // ecx

  v3 = (__m128)timeSeconds;
  v4 = *(float *)&timeSeconds * 0.016666668;
  v5 = (signed int)(float)(*(float *)&timeSeconds * 0.016666668);
  if ( v5 != 0x80000000 && (float)v5 != v4 )
    v4 = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps((__m128)timeSeconds, (__m128)timeSeconds)) & 1));
  v3.m128_f32[0] = *(float *)&timeSeconds - (float)(v4 * 60.0);
  v6 = v3.m128_f32[0];
  v7 = (signed int)v3.m128_f32[0];
  if ( (signed int)v3.m128_f32[0] != 0x80000000 && (float)v7 != v3.m128_f32[0] )
    v6 = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
  v3.m128_f32[0] = (float)(v3.m128_f32[0] - v6) * 4800.0;
  v8 = (signed int)v3.m128_f32[0];
  if ( (signed int)v3.m128_f32[0] != 0x80000000 && (float)v8 != v3.m128_f32[0] )
    v3.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
  UFG::qSPrintf(buff, buffSize, "%0.f:%0.f:%0.f", v4, v6, v3.m128_f32[0]);
}

// File Line: 209
// RVA: 0x3A9E30
int GetUnitsTime_SMPTE_Str(...)
{
  __m128 v3; // xmm2
  float v4; // xmm3_4
  signed int v5; // ecx
  float v6; // xmm1_4
  signed int v7; // ecx
  signed int v8; // ecx

  v3 = (__m128)timeSeconds;
  v4 = *(float *)&timeSeconds * 0.016666668;
  v5 = (signed int)(float)(*(float *)&timeSeconds * 0.016666668);
  if ( v5 != 0x80000000 && (float)v5 != v4 )
    v4 = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps((__m128)timeSeconds, (__m128)timeSeconds)) & 1));
  v3.m128_f32[0] = *(float *)&timeSeconds - (float)(v4 * 60.0);
  v6 = v3.m128_f32[0];
  v7 = (signed int)v3.m128_f32[0];
  if ( (signed int)v3.m128_f32[0] != 0x80000000 && (float)v7 != v3.m128_f32[0] )
    v6 = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
  v3.m128_f32[0] = (float)(v3.m128_f32[0] - v6) * 30.0;
  v8 = (signed int)v3.m128_f32[0];
  if ( (signed int)v3.m128_f32[0] != 0x80000000 && (float)v8 != v3.m128_f32[0] )
    v3.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
  UFG::qSPrintf(buff, buffSize, "%0.f:%0.f:%0.f", v4, v6, v3.m128_f32[0]);
}

// File Line: 219
// RVA: 0x3A9C00
void __fastcall GetUnitsTime(float timeSeconds, char *buff, int buffSize, UnitsTime timeUnits)
{
  int v4; // er10
  const char *v5; // r8

  v4 = buffSize;
  switch ( timeUnits )
  {
    case 1:
      timeSeconds = timeSeconds * 30.0;
      v5 = "%0.f";
      goto LABEL_5;
    case 2:
      timeSeconds = timeSeconds * 30.0;
      goto $LN1_12;
    case 3:
      GetUnitsTime_Frames_Ticks_Str(timeSeconds, buff, buffSize);
      break;
    case 4:
      GetUnitsTime_Minutes_Seconds_Ticks_Str(timeSeconds, buff, buffSize);
      break;
    case 5:
      GetUnitsTime_SMPTE_Str(timeSeconds, buff, buffSize);
      break;
    default:
$LN1_12:
      v5 = "%0.3f";
LABEL_5:
      UFG::qSPrintf(buff, v4, v5, timeSeconds);
      break;
  }
}

// File Line: 272
// RVA: 0x14BF6F0
const char *dynamic_initializer_for__sTimePlotPointFactoryList__()
{
  const char *result; // rax

  result = TimePlotPoint::sClassName;
  sTimePlotPointFactoryList[0].mClassName = TimePlotPoint::sClassName;
  return result;
}

// File Line: 277
// RVA: 0x14BD110
__int64 dynamic_initializer_for__gTimePlotPointFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gTimePlotPointFactory,
    sTimePlotPointFactoryList,
    sTimePlotPointFactoryListNum);
  return atexit(dynamic_atexit_destructor_for__gTimePlotPointFactory__);
}

// File Line: 280
// RVA: 0x14B9A10
__int64 dynamic_initializer_for__TimePlotPoint::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TimePlotPoint", 0xFFFFFFFF);
  TimePlotPoint::sClassNameUID = result;
  return result;
}

// File Line: 294
// RVA: 0x14B99F0
__int64 dynamic_initializer_for__TimePlot::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TimePlot", 0xFFFFFFFF);
  TimePlot::sClassNameUID = result;
  return result;
}

// File Line: 415
// RVA: 0x3A4A20
void __fastcall BlendSlerp(UFG::qMatrix44 *dest, UFG::qMatrix44 *sourceA, UFG::qMatrix44 *sourceB, float weight)
{
  UFG::qMatrix44 *v4; // rdi
  UFG::qMatrix44 *v5; // rbx
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm0
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  hkQsTransformf v21; // [rsp+20h] [rbp-E8h]
  hkQsTransformf v22; // [rsp+50h] [rbp-B8h]
  hkQsTransformf v23; // [rsp+80h] [rbp-88h]
  hkTransformf transform; // [rsp+B0h] [rbp-58h]

  v4 = sourceB;
  v5 = dest;
  if ( weight < 1.0 )
  {
    if ( weight > 0.0 )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &sourceA->v0.x);
      hkQsTransformf::setFromTransformNoScale(&v21, &transform);
      hkTransformf::set4x4ColumnMajor(&transform, &v4->v0.x);
      hkQsTransformf::setFromTransformNoScale(&v23, &transform);
      v12.m128_f32[0] = weight;
      v13 = _mm_mul_ps(v23.m_rotation.m_vec.m_quad, v21.m_rotation.m_vec.m_quad);
      v14 = _mm_shuffle_ps(v12, v12, 0);
      v22.m_scale.m_quad = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(v23.m_scale.m_quad, v21.m_scale.m_quad), v14),
                             v21.m_scale.m_quad);
      v22.m_translation.m_quad = _mm_add_ps(
                                   _mm_mul_ps(_mm_sub_ps(v23.m_translation.m_quad, v21.m_translation.m_quad), v14),
                                   v21.m_translation.m_quad);
      v15 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v16 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v14),
                v23.m_rotation.m_vec.m_quad),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v14), v21.m_rotation.m_vec.m_quad));
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18);
      v20 = _mm_rsqrt_ps(v19);
      v22.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v20)),
                                      v16);
      hkQsTransformf::get4x4ColumnMajor(&v22, &v5->v0.x);
    }
    else
    {
      v9 = sourceA->v1;
      v10 = sourceA->v2;
      v11 = sourceA->v3;
      dest->v0 = sourceA->v0;
      dest->v1 = v9;
      dest->v2 = v10;
      dest->v3 = v11;
    }
  }
  else
  {
    v6 = sourceB->v1;
    v7 = sourceB->v2;
    v8 = sourceB->v3;
    dest->v0 = sourceB->v0;
    dest->v1 = v6;
    dest->v2 = v7;
    dest->v3 = v8;
  }
}

// File Line: 456
// RVA: 0x3B66B0
void __fastcall constrainPos(UFG::qVector3 *constrainedPos, UFG::qVector3 *sourcePos, UFG::qVector3 *origin, UFG::qVector3 *axis, const float length, const bool syncToClosestEndpoint)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4

  v6 = origin->x;
  v7 = origin->y;
  v8 = origin->z;
  v9 = (float)((float)((float)(sourcePos->y - v7) * axis->y) + (float)((float)(sourcePos->x - origin->x) * axis->x))
     + (float)((float)(sourcePos->z - v8) * axis->z);
  if ( v9 <= 0.0 )
    v9 = 0.0;
  if ( v9 >= length )
    v9 = length;
  if ( syncToClosestEndpoint )
  {
    if ( (float)(v9 / length) < 0.5 )
      v9 = 0.0;
    else
      v9 = length;
  }
  constrainedPos->z = v8;
  constrainedPos->x = v6;
  constrainedPos->y = v7;
  v10 = (float)(axis->z * v9) + v8;
  v11 = (float)(axis->y * v9) + v7;
  constrainedPos->x = (float)(axis->x * v9) + v6;
  constrainedPos->y = v11;
  constrainedPos->z = v10;
}

