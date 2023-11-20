// File Line: 45
// RVA: 0xD3A7F0
void __fastcall selectIfGT3(hkVector4f *result, hkSimdFloat32 *selectIf, hkVector4f *greaterV, hkSimdFloat32 *than)
{
  __m128 v4; // xmm1

  v4 = _mm_cmpltps(than->m_real, greaterV->m_quad);
  result->m_quad = _mm_or_ps(_mm_and_ps(selectIf->m_real, v4), _mm_andnot_ps(v4, result->m_quad));
}

// File Line: 55
// RVA: 0xD3A810
void __fastcall getAxisMapFromFeatureBitSet(int bitSet, hkVector4f *v)
{
  v->m_quad = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(hkVector4fComparison_maskToComparison_373[(bitSet >> 4) & 7], 0x1Fu),
                          0x1Fu),
                query.m_quad);
}

// File Line: 62
// RVA: 0xD3A850
void __fastcall getNormalSignFromFeatureBitSet(char bitSet, hkVector4fComparison *signMask)
{
  if ( bitSet & 8 )
    *signMask = (hkVector4fComparison)xmmword_141A86110;
  else
    *signMask = 0i64;
}

// File Line: 74
// RVA: 0xD3A870
void __fastcall setEdgeFeatureBitSetFromAxisMap(hkVector4f *axisMapAp, hkVector4f *axisMapBp, int featureIndexA, int featureIndexB, hkpFeatureContactPoint *fcp)
{
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm3

  v5 = axisMapAp->m_quad;
  v6 = axisMapBp->m_quad;
  switch ( featureIndexA )
  {
    case 1:
      v7 = _mm_shuffle_ps(_mm_unpacklo_ps(v5, (__m128)0i64), v5, 228);
      break;
    case 2:
      v7 = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, (__m128)0i64), 180);
      break;
    case 3:
      v7 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v5, 4), 4);
      break;
    default:
      v7 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v5, 4), 4);
      break;
  }
  switch ( featureIndexB )
  {
    case 1:
      v8 = _mm_shuffle_ps(_mm_unpacklo_ps(v6, (__m128)0i64), v6, 228);
      break;
    case 2:
      v8 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, (__m128)0i64), 180);
      break;
    case 3:
      v8 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v6, 4), 4);
      break;
    default:
      v8 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v6, 4), 4);
      break;
  }
  fcp->m_featureIdA = featureIndexA | 16 * (_mm_movemask_ps(_mm_cmpltps(v7, (__m128)0i64)) | 0xF8);
  fcp->m_featureIdB = featureIndexB + (~(16 * _mm_movemask_ps(_mm_cmpltps(v8, (__m128)0i64))) & 0x70);
}

// File Line: 91
// RVA: 0xD3A940
__int64 __fastcall calcFaceFeatureBitSetFromAxisMap(hkVector4f *axisMap, hkVector4fComparison *normalSign)
{
  __int64 result; // rax

  result = 16 * (_mm_movemask_ps(_mm_cmpltps(axisMap->m_quad, (__m128)0i64)) & 7u);
  if ( _mm_movemask_ps(normalSign->m_mask) )
    result = (unsigned int)result | 8;
  return result;
}

// File Line: 99
// RVA: 0xD3A970
void __fastcall setTerminalsFromVertex(int *bitSetEdgeTerminals, int bitSet, int planeAxis)
{
  int v3; // edi
  int *v4; // r9
  char v5; // bl
  char v6; // r10
  char v7; // r11
  signed int v8; // er8
  int v9; // ecx
  signed int v10; // er8
  signed int v11; // edx

  v3 = planeAxis;
  v4 = bitSetEdgeTerminals;
  v5 = ~(unsigned __int8)(bitSet >> 4) & 1;
  v6 = ~(unsigned __int8)((unsigned int)(bitSet >> 4) >> 2) & 1;
  v7 = ~(unsigned __int8)((unsigned int)(bitSet >> 4) >> 1) & 1;
  if ( planeAxis )
  {
    v8 = 1 << 2 * (v7 + 2 * v6);
    v9 = *bitSetEdgeTerminals;
    if ( !(2 * v8 & v9) )
      *v4 = v9 + v8;
  }
  if ( v3 != 1 )
  {
    v10 = 1 << 2 * (v5 + 2 * (v6 + 2));
    if ( !(2 * v10 & *v4) )
      *v4 += v10;
  }
  if ( v3 != 2 )
  {
    v11 = 1 << 2 * (v5 + 8 + 2 * v7);
    if ( !(2 * v11 & *v4) )
      *v4 += v11;
  }
}

// File Line: 143
// RVA: 0xD3AA30
void __fastcall setTerminalsFromEdge(int *bitSetEdgeTerminals, int bitSet)
{
  char v2; // r9
  unsigned int v3; // edx
  int *v4; // r8
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // er9
  int v10; // eax
  signed int v11; // edx

  v2 = bitSet;
  v3 = bitSet >> 4;
  v4 = bitSetEdgeTerminals;
  v5 = v3;
  v6 = ~(_BYTE)v3 & 1;
  v7 = ~(unsigned __int8)(v3 >> 2) & 1;
  v8 = ~(unsigned __int8)(v5 >> 1) & 1;
  v9 = v2 & 0xF;
  if ( v9 )
  {
    if ( v9 == 1 )
      v10 = v6 + 2 * (v7 + 2);
    else
      v10 = v6 + 8 + 2 * v8;
  }
  else
  {
    v10 = v8 + 2 * v7;
  }
  v11 = 1 << 2 * v10;
  if ( !(2 * v11 & *v4) )
    *v4 += v11;
}

// File Line: 188
// RVA: 0xD3A550
void __fastcall hkpBoxBoxCollisionDetection::checkCompleteness(hkpBoxBoxCollisionDetection *this, hkpBoxBoxManifold *manifold, int planeMaskA, int planeMaskB)
{
  unsigned __int8 v4; // r10
  hkpBoxBoxManifold *v5; // r14
  __int64 v6; // rsi
  int v7; // eax
  __int64 v8; // rdi
  int v9; // er8
  __int64 v10; // rbp
  hkpBoxBoxManifold *v11; // rbx
  unsigned __int8 v12; // cl
  int v13; // er11
  char v14; // dl
  int v15; // er10
  signed int v16; // er9
  signed int v17; // edx
  int v18; // ecx
  char v19; // r11
  char v20; // dl
  char v21; // r10
  signed int v22; // er9
  signed int v23; // edx
  signed int v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // edx
  int v27; // er9
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  signed int v31; // edx
  unsigned int v32; // edx
  int v33; // er9
  int v34; // ecx
  int v35; // edx
  signed int v36; // edx

  v4 = manifold->m_numPoints;
  v5 = manifold;
  if ( v4 >= 3u )
  {
    if ( manifold->m_faceVertexFeatureCount >= 4u )
    {
      manifold->m_isComplete = 1;
      return;
    }
    v6 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[(signed __int64)planeMaskA >> 4];
    v7 = 0;
    v8 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[(signed __int64)planeMaskB >> 4];
    v9 = 0;
    if ( (signed int)v4 > 0 )
    {
      v10 = v4;
      v11 = manifold;
      do
      {
        v12 = v11->m_contactPoints[0].m_featureIdA;
        if ( v11->m_contactPoints[0].m_featureIdA > 2u )
        {
          if ( v12 <= 6u )
          {
            v19 = ~((unsigned __int8)v11->m_contactPoints[0].m_featureIdB >> 4) & 1;
            v20 = ~((unsigned __int8)v11->m_contactPoints[0].m_featureIdB >> 6) & 1;
            v21 = ~((unsigned __int8)v11->m_contactPoints[0].m_featureIdB >> 5) & 1;
            if ( v6 )
            {
              v22 = 1 << 2 * (v21 + 2 * v20);
              if ( !(2 * v22 & v7) )
                v7 += v22;
            }
            if ( v6 != 1 )
            {
              v23 = 1 << 2 * (v19 + 2 * (v20 + 2));
              if ( !(2 * v23 & v7) )
                v7 += v23;
            }
            if ( v6 != 2 )
            {
              v24 = 1 << 2 * (v19 + 2 * (v21 + 4));
              if ( !(2 * v24 & v7) )
                v7 += v24;
            }
            goto LABEL_39;
          }
          v25 = (signed int)v12 >> 4;
          v26 = v25;
          v27 = ~(_BYTE)v25 & 1;
          v28 = ~(unsigned __int8)(v25 >> 2) & 1;
          v29 = ~(unsigned __int8)(v26 >> 1) & 1;
          if ( v11->m_contactPoints[0].m_featureIdA & 0xF )
          {
            if ( (v11->m_contactPoints[0].m_featureIdA & 0xF) == 1 )
              v30 = v27 + 2 * (v28 + 2);
            else
              v30 = v27 + 2 * (v29 + 4);
          }
          else
          {
            v30 = v29 + 2 * v28;
          }
          v31 = 1 << 2 * v30;
          if ( !(2 * v31 & v7) )
            v7 += v31;
          v32 = (signed int)(unsigned __int8)v11->m_contactPoints[0].m_featureIdB >> 4;
          v33 = ~(_BYTE)v32 & 1;
          v34 = ~(unsigned __int8)(v32 >> 2) & 1;
          v35 = ~(unsigned __int8)(v32 >> 1) & 1;
          if ( v11->m_contactPoints[0].m_featureIdB & 0xF )
          {
            if ( (v11->m_contactPoints[0].m_featureIdB & 0xF) == 1 )
              v18 = v33 + 2 * (v34 + 2);
            else
              v18 = v33 + 2 * (v35 + 4);
          }
          else
          {
            v18 = v35 + 2 * v34;
          }
        }
        else
        {
          v13 = ~((unsigned __int8)v11->m_contactPoints[0].m_featureIdB >> 4) & 1;
          v14 = ~((unsigned __int8)v11->m_contactPoints[0].m_featureIdB >> 6) & 1;
          v15 = ~((unsigned __int8)v11->m_contactPoints[0].m_featureIdB >> 5) & 1;
          if ( v8 )
          {
            v16 = 1 << 2 * (v15 + 2 * v14);
            if ( !(2 * v16 & v9) )
              v9 += v16;
          }
          if ( v8 != 1 )
          {
            v17 = 1 << 2 * (v13 + 2 * (v14 + 2));
            if ( !(2 * v17 & v9) )
              v9 += v17;
          }
          if ( v8 == 2 )
            goto LABEL_39;
          v18 = v13 + 2 * (v15 + 4);
        }
        v36 = 1 << 2 * v18;
        if ( !(2 * v36 & v9) )
          v9 += v36;
LABEL_39:
        v11 = (hkpBoxBoxManifold *)((char *)v11 + 4);
        --v10;
      }
      while ( v10 );
    }
    v5->m_isComplete = (v7 & 0x555555) <= 0 && (v9 & 0x555555) <= 0;
  }
}

// File Line: 453
// RVA: 0xD3AAA0
__int64 __fastcall getMaxPlaneMask3(hkVector4f *vAbs, int *axisOut)
{
  int v2; // ecx

  v2 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                              _mm_and_ps(
                                                                _mm_cmpleps(
                                                                  _mm_max_ps(
                                                                    _mm_shuffle_ps(vAbs->m_quad, vAbs->m_quad, 170),
                                                                    _mm_max_ps(
                                                                      _mm_shuffle_ps(vAbs->m_quad, vAbs->m_quad, 85),
                                                                      _mm_shuffle_ps(vAbs->m_quad, vAbs->m_quad, 0))),
                                                                  vAbs->m_quad),
                                                                (__m128)xmmword_141A86090))];
  *axisOut = v2;
  return (unsigned int)(16 * (1 << v2));
}

// File Line: 579
// RVA: 0xD39D20
void __fastcall hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(hkpBoxBoxCollisionDetection *this, hkpBoxBoxManifold *manifold, hkpFeatureContactPoint *fcp, hkSimdFloat32 *closestPointDist)
{
  hkpBoxBoxManifold *v4; // rbx
  hkSimdFloat32 *v5; // rbp
  int v6; // eax
  hkpFeatureContactPoint *v7; // rsi
  hkpBoxBoxCollisionDetection *v8; // rdi
  __int64 v9; // rdx
  int v10; // eax
  hkSimdFloat32 v11; // xmm9
  hkVector4f v12; // xmm6
  hkVector4f v13; // xmm7
  __m128 *v14; // rax
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  int v18; // er9
  int v19; // edx
  float v20; // xmm4_4
  __m128 v21; // xmm3
  float v22; // xmm4_4
  __int64 v23; // r8
  hkpBoxBoxManifold *v24; // rcx
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  int v27; // eax
  __int64 v28; // r14
  __m128 *v29; // rbp
  unsigned int v30; // edx
  __int64 v31; // rcx
  hkTransformf *v32; // rax
  int v33; // eax
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm6
  int v37; // ecx
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm2
  unsigned __int16 v41; // ax
  hkpBoxBoxCollisionDetection::hkpFeaturePointCache fpp; // [rsp+40h] [rbp-B8h]

  v4 = manifold;
  v5 = closestPointDist;
  v6 = (unsigned __int8)manifold->m_numPoints - 1;
  v7 = fcp;
  v8 = this;
  v9 = v6;
  if ( v6 < 0 )
  {
LABEL_4:
    fpp.m_featureIndexA = (unsigned __int8)fcp->m_featureIdA;
    v10 = (unsigned __int8)fcp->m_featureIdB;
    fpp.m_vA = 0i64;
    fpp.m_vB = 0i64;
    fpp.m_normalIsFlipped = 0i64;
    fpp.m_featureIndexB = v10;
    if ( !hkpBoxBoxCollisionDetection::isValidEdgeEdge(this, &fpp) )
      return;
    v11.m_real = (__m128)fpp.m_distance;
    if ( fpp.m_distance.m_real.m128_f32[0] < (float)(COERCE_FLOAT(
                                                       _mm_shuffle_ps(
                                                         (__m128)LODWORD(FLOAT_0_99900001),
                                                         (__m128)LODWORD(FLOAT_0_99900001),
                                                         0))
                                                   * v5->m_real.m128_f32[0]) )
      return;
    v12.m_quad = (__m128)fpp.m_vA;
    v13.m_quad = (__m128)fpp.m_vB;
    if ( v7->m_featureIdA <= 6u )
    {
      if ( v7->m_featureIdA > 2u )
      {
        v14 = &v8->m_wTa->m_rotation.m_col0.m_quad;
        v15 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 85);
        v16 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 0);
        v17 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 170);
      }
      else
      {
        v14 = &v8->m_wTb->m_rotation.m_col0.m_quad;
        v15 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 85);
        v16 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 0);
        v17 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 170);
      }
      v18 = (unsigned __int8)v4->m_numPoints;
      v19 = 0;
      LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(v8->m_tolerance4.m_quad, v8->m_tolerance4.m_quad, 0);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, v14[1]), _mm_mul_ps(v16, *v14)), _mm_mul_ps(v17, v14[2])),
              v14[3]);
      v22 = (float)(v20 * v20) + 0.00000011920929;
      if ( v18 > 0 )
      {
        v23 = 0i64;
        v24 = v4;
        do
        {
          if ( v24->m_contactPoints[0].m_featureIdA <= 6u )
          {
            v25 = _mm_sub_ps(v21, v8->m_result->m_contactPoints[v23].m_contact.m_position.m_quad);
            v26 = _mm_mul_ps(v25, v25);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170))) <= v22 )
              return;
          }
          ++v19;
          v24 = (hkpBoxBoxManifold *)((char *)v24 + 4);
          ++v23;
        }
        while ( v19 < v18 );
      }
    }
    if ( v4->m_numPoints >= 8u )
      return;
    v27 = hkpBoxBoxManifold::addPoint(v4, v8->m_bodyA, v8->m_bodyB, v7);
    v28 = v27;
    if ( v27 < 0 )
      return;
    v29 = (__m128 *)v8->m_result->m_firstFreeContactPoint.m_storage;
    if ( fpp.m_featureIndexA > 2 )
    {
      v33 = v7->m_contactPointId;
      v34 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 85);
      v35 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 0);
      v36 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 170);
      if ( fpp.m_featureIndexA > 6 )
      {
        v29[2].m128_i32[0] = v33;
        *v29 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v34, v8->m_wTa->m_rotation.m_col1.m_quad),
                     _mm_mul_ps(v35, v8->m_wTa->m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(v36, v8->m_wTa->m_rotation.m_col2.m_quad)),
                 v8->m_wTa->m_translation.m_quad);
        v39 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 85), v8->m_wTa->m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 0), v8->m_wTa->m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 170), v8->m_wTa->m_rotation.m_col2.m_quad));
        v29[1] = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, v11.m_real), 196);
LABEL_23:
        if ( (v4->m_numPoints <= 1u
           || (v40 = _mm_mul_ps(
                       v8->m_result->m_firstFreeContactPoint.m_storage[-1].m_contact.m_separatingNormal.m_quad,
                       v29[1]),
               (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170))) > 0.0))
          && (v41 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, __m128 *))v8->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                      v8->m_contactMgr,
                      v8->m_bodyA,
                      v8->m_bodyB,
                      v8->m_env,
                      v8->m_result,
                      0i64,
                      v29),
              v4->m_contactPoints[v28].m_contactPointId = v41,
              v41 != -1) )
        {
          ++v8->m_result->m_firstFreeContactPoint.m_storage;
          v7->m_contactPointId = v4->m_contactPoints[v28].m_contactPointId;
          v29[2].m128_i32[0] = v4->m_contactPoints[v28].m_contactPointId;
          if ( v7->m_featureIdA <= 6u )
            ++v4->m_faceVertexFeatureCount;
        }
        else
        {
          hkpBoxBoxManifold::removePoint(v4, v28);
        }
        return;
      }
      v37 = (unsigned __int8)v7->m_featureIdA;
      v29[2].m128_i32[0] = v33;
      v31 = v37 - 4;
      *v29 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(v34, v8->m_wTa->m_rotation.m_col1.m_quad),
                   _mm_mul_ps(v35, v8->m_wTa->m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(v36, v8->m_wTa->m_rotation.m_col2.m_quad)),
               v8->m_wTa->m_translation.m_quad);
      v32 = v8->m_wTb;
    }
    else
    {
      v30 = (unsigned __int8)v7->m_featureIdA;
      v29[2].m128_i32[0] = v7->m_contactPointId;
      v31 = v30;
      *v29 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 85), v8->m_wTb->m_rotation.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 0), v8->m_wTb->m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 170), v8->m_wTb->m_rotation.m_col2.m_quad)),
               v8->m_wTb->m_translation.m_quad);
      v32 = v8->m_wTa;
    }
    v38 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        _mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&fpp.m_normalIsFlipped), (__m128i)0i64),
                        0x1Fu),
                      0x1Fu),
            *(&v32->m_rotation.m_col0.m_quad + v31));
    v29[1] = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, v11.m_real), 196);
    goto LABEL_23;
  }
  while ( *(_WORD *)&v4->m_contactPoints[v9].m_featureIdA != *(_WORD *)&fcp->m_featureIdA )
  {
    if ( --v9 < 0 )
      goto LABEL_4;
  }
}

// File Line: 605
// RVA: 0xD39BA0
void __fastcall hkpBoxBoxCollisionDetection::tryToAddPointOnEdge(hkpBoxBoxCollisionDetection *this, hkpBoxBoxManifold *manifold, int edgeA, int edgeB, int nextVertA, int nextVertB, hkVector4f *normalA, hkVector4f *normalB, hkSimdFloat32 *closestPointDist)
{
  hkpBoxBoxManifold *v9; // rbp
  hkpBoxBoxCollisionDetection *v10; // r14
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  hkSimdFloat32 *v15; // rsi
  signed int v16; // edi
  hkpFeatureContactPoint fcp; // [rsp+50h] [rbp+18h]

  v9 = manifold;
  fcp.m_contactPointId = 0;
  v10 = this;
  v11 = normalA->m_quad;
  v12 = normalB->m_quad;
  switch ( edgeA )
  {
    case 1:
      v13 = _mm_shuffle_ps(_mm_unpacklo_ps(v11, (__m128)0i64), v11, 228);
      break;
    case 2:
      v13 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, (__m128)0i64), 180);
      break;
    case 3:
      v13 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v11, 4), 4);
      break;
    default:
      v13 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v11, 4), 4);
      break;
  }
  switch ( edgeB )
  {
    case 1:
      v14 = _mm_shuffle_ps(_mm_unpacklo_ps(v12, (__m128)0i64), v12, 228);
      break;
    case 2:
      v14 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, (__m128)0i64), 180);
      break;
    case 3:
      v14 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v12, 4), 4);
      break;
    default:
      v14 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v12, 4), 4);
      break;
  }
  v15 = closestPointDist;
  fcp.m_featureIdA = edgeA | 16 * (_mm_movemask_ps(_mm_cmpltps(v13, (__m128)0i64)) | 0xF8);
  fcp.m_featureIdB = edgeB + (~(16 * _mm_movemask_ps(_mm_cmpltps(v14, (__m128)0i64))) & 0x70);
  hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(this, manifold, &fcp, closestPointDist);
  v16 = 1 << (nextVertA + 4);
  fcp.m_featureIdA ^= v16;
  hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(v10, v9, &fcp, v15);
  fcp.m_featureIdB ^= 1 << (nextVertB + 4);
  hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(v10, v9, &fcp, v15);
  fcp.m_featureIdA ^= v16;
  hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(v10, v9, &fcp, v15);
}

// File Line: 752
// RVA: 0xD38DC0
hkResult *__fastcall hkpBoxBoxCollisionDetection::checkIntersection(hkpBoxBoxCollisionDetection *this, hkResult *result, hkVector4f *tolerance)
{
  __m128 v3; // xmm5
  __m128i v4; // xmm6
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  hkVector4f v7; // xmm7
  __m128 v8; // xmm8
  __m128 v9; // xmm10
  __m128 v10; // xmm1
  __m128i v11; // xmm2
  __m128 v12; // xmm13
  __m128 v13; // xmm4
  __m128 v14; // xmm13
  __m128 v15; // xmm1
  __m128 v16; // xmm15
  __m128 v17; // xmm14
  __m128 v18; // xmm7
  __m128 v19; // xmm2
  hkVector4f v20; // xmm2
  hkVector4f v21; // xmm8
  __m128 v22; // xmm4
  __m128 v23; // xmm6
  __m128 v24; // xmm1
  __m128 v25; // xmm8
  __m128 v26; // xmm9
  __m128 v27; // xmm11
  hkVector4f v28; // xmm0
  __m128 v29; // xmm12
  __m128 v30; // xmm2
  __m128 v31; // xmm11
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // ST70_16
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm11
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  hkVector4f v43; // xmm11
  __m128 v44; // xmm2
  __m128 v45; // xmm8
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  hkVector4f v49; // xmm1
  __m128 v50; // xmm9
  __m128 v51; // xmm0
  __m128 v52; // xmm13
  __m128 v53; // xmm6
  __m128 v54; // xmm5
  __m128 v56; // [rsp+0h] [rbp-138h]
  __m128 v57; // [rsp+10h] [rbp-128h]
  __m128 v58; // [rsp+20h] [rbp-118h]
  __m128 v59; // [rsp+30h] [rbp-108h]
  __m128 v60; // [rsp+40h] [rbp-F8h]
  __m128 v61; // [rsp+50h] [rbp-E8h]
  __m128 v62; // [rsp+60h] [rbp-D8h]

  v3 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_999_99994), (__m128)LODWORD(FLOAT_999_99994), 0);
  v4 = _mm_load_si128((const __m128i *)&this->m_dinA);
  v5 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_aTb), 1u), 1u);
  v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_aTb.m_rotation.m_col2), 1u), 1u);
  v7.m_quad = (__m128)this->m_radiusA;
  v8 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_aTb.m_rotation.m_col1), 1u), 1u);
  v9 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_N9_9999998e16), (__m128)LODWORD(FLOAT_N9_9999998e16), 0);
  v10 = _mm_sub_ps(
          (__m128)_mm_srli_epi32(_mm_slli_epi32(v4, 1u), 1u),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(this->m_radiusB.m_quad, this->m_radiusB.m_quad, 85), v8),
                _mm_mul_ps(_mm_shuffle_ps(this->m_radiusB.m_quad, this->m_radiusB.m_quad, 0), v5)),
              _mm_mul_ps(_mm_shuffle_ps(this->m_radiusB.m_quad, this->m_radiusB.m_quad, 170), v6)),
            v7.m_quad));
  if ( _mm_movemask_ps(_mm_cmpltps(tolerance->m_quad, v10)) )
  {
    result->m_enum = 1;
  }
  else
  {
    v11 = _mm_load_si128((const __m128i *)&this->m_dinB);
    this->m_sepDist[0].m_quad = v10;
    v12 = v5;
    v13 = _mm_unpackhi_ps(v5, v8);
    v14 = _mm_unpacklo_ps(v12, v8);
    v15 = _mm_movelh_ps(v14, v6);
    v16 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 85);
    v17 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 0);
    v18 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 170);
    v19 = _mm_sub_ps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v15, v17), _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v15, v14), v6, 212), v16)),
                _mm_mul_ps(_mm_shuffle_ps(v13, v6, 228), v18)),
              this->m_radiusB.m_quad));
    if ( _mm_movemask_ps(_mm_cmpltps(tolerance->m_quad, v19)) )
    {
      result->m_enum = 1;
    }
    else
    {
      this->m_sepDist[1].m_quad = v19;
      v20.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
      v21.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
      v22 = _mm_shuffle_ps(v13, v6, 228);
      v23 = _mm_shuffle_ps((__m128)v4, (__m128)v4, 85);
      v24 = _mm_unpacklo_ps(v21.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
      v25 = _mm_shuffle_ps(_mm_unpackhi_ps(v21.m_quad, this->m_aTb.m_rotation.m_col1.m_quad), v20.m_quad, 228);
      v60 = _mm_movelh_ps(v24, v20.m_quad);
      v26 = _mm_mul_ps(v60, v60);
      v27 = _mm_shuffle_ps(_mm_movehl_ps(v60, v24), v20.m_quad, 212);
      v56 = _mm_movelh_ps(v14, v6);
      v57 = _mm_mul_ps(v27, v27);
      v28.m_quad = (__m128)this->m_radiusB;
      v29 = _mm_shuffle_ps(_mm_movehl_ps(v56, v14), v6, 212);
      v58 = v27;
      v30 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 65);
      v59 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 90);
      v61 = v30;
      v62 = _mm_shuffle_ps(this->m_dinA.m_quad, this->m_dinA.m_quad, 170);
      v31 = _mm_mul_ps(v25, v25);
      v32 = _mm_max_ps(_mm_add_ps(v31, v57), (__m128)xmmword_141A712D0);
      v33 = _mm_rsqrt_ps(v32);
      v34 = _mm_sub_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(_mm_mul_ps(v62, v58), _mm_mul_ps(v25, v23)), 1u),
                        1u),
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v22, v16), _mm_mul_ps(v29, v18)),
                  _mm_mul_ps(_mm_shuffle_ps(v56, v56, 90), v30)),
                _mm_mul_ps(_mm_shuffle_ps(v56, v56, 65), v59)));
      v35 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v33), v33)),
              _mm_mul_ps(*(__m128 *)_xmm, v33));
      v36 = v35;
      v37 = _mm_mul_ps(v34, v35);
      if ( _mm_movemask_ps(_mm_cmpltps(this->m_tolerance4.m_quad, v37)) )
        goto LABEL_13;
      v38 = _mm_cmpltps(v3, v36);
      v39 = _mm_shuffle_ps(this->m_dinA.m_quad, this->m_dinA.m_quad, 0);
      this->m_sepDist[2].m_quad = _mm_or_ps(_mm_and_ps(v9, v38), _mm_andnot_ps(v38, v37));
      v40 = _mm_max_ps(_mm_add_ps(v31, v26), (__m128)xmmword_141A712D0);
      v41 = _mm_rsqrt_ps(v40);
      v42 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v41), v41));
      v43.m_quad = (__m128)this->m_tolerance4;
      v44 = _mm_mul_ps(v42, _mm_mul_ps(*(__m128 *)_xmm, v41));
      v45 = _mm_mul_ps(
              _mm_sub_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_sub_ps(_mm_mul_ps(v25, v39), _mm_mul_ps(v62, v60)), 1u),
                          1u),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v22, v17), _mm_mul_ps(v56, v18)),
                    _mm_mul_ps(_mm_shuffle_ps(v29, v29, 90), v61)),
                  _mm_mul_ps(_mm_shuffle_ps(v29, v29, 65), v59))),
              v44);
      if ( _mm_movemask_ps(_mm_cmpltps(this->m_tolerance4.m_quad, v45)) )
        goto LABEL_13;
      v46 = _mm_cmpltps(v3, v44);
      v47 = _mm_and_ps(v9, v46);
      v48 = _mm_andnot_ps(v46, v45);
      v49.m_quad = (__m128)this->m_radiusB;
      this->m_sepDist[3].m_quad = _mm_or_ps(v48, v47);
      v50 = _mm_max_ps(_mm_add_ps(v26, v57), (__m128)xmmword_141A712D0);
      v51 = _mm_rsqrt_ps(v50);
      v52 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v51), v51)),
              _mm_mul_ps(*(__m128 *)_xmm, v51));
      v53 = _mm_mul_ps(
              _mm_sub_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_sub_ps(_mm_mul_ps(v23, v60), _mm_mul_ps(v39, v58)), 1u),
                          1u),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 210), _mm_shuffle_ps(v49.m_quad, v49.m_quad, 201)),
                    _mm_add_ps(_mm_mul_ps(v29, v17), _mm_mul_ps(v56, v16))),
                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), _mm_shuffle_ps(v49.m_quad, v49.m_quad, 210)))),
              v52);
      if ( _mm_movemask_ps(_mm_cmpltps(v43.m_quad, v53)) )
      {
LABEL_13:
        result->m_enum = 1;
      }
      else
      {
        v54 = _mm_cmpltps(v3, v52);
        result->m_enum = 0;
        this->m_sepDist[4].m_quad = _mm_or_ps(_mm_andnot_ps(v54, v53), _mm_and_ps(v54, v9));
      }
    }
  }
  return result;
}        v54 = _mm_cmpltps(v3, v52);
        result->m_enum = 0;
        this->m_sepDist[4].m_quad = _mm_or_ps(_mm_andnot_ps(v54, v53), _mm_and_ps(v54, v9));
     

// File Line: 994
// RVA: 0xD394F0
signed __int64 __fastcall hkpBoxBoxCollisionDetection::findClosestPoint(hkpBoxBoxCollisionDetection *this, hkpBoxBoxManifold *manifold, hkpFeatureContactPoint *fcp, hkpBoxBoxCollisionDetection::hkpFeaturePointCache *fpp)
{
  hkpBoxBoxCollisionDetection::hkpFeaturePointCache *v4; // rbp
  hkpFeatureContactPoint *v5; // rsi
  hkpBoxBoxManifold *v6; // rdi
  hkpBoxBoxCollisionDetection *v7; // r14
  signed int v8; // er12
  __m128i v9; // xmm3
  __m128 v10; // xmm5
  __m128i v11; // xmm6
  __m128 *v12; // rax
  signed __int64 v13; // rcx
  __m128i v14; // xmm4
  __m128 v15; // xmm2
  __m128i v16; // xmm1
  __m128 v17; // xmm2
  __m128i v18; // xmm2
  __m128i v19; // xmm1
  __m128i v20; // xmm0
  __m128i v21; // xmm2
  __m128i v22; // xmm4
  __m128i v23; // xmm1
  __m128i v24; // xmm3
  __m128i v25; // xmm1
  unsigned int v26; // er15
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128i v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  int v33; // edx
  int v34; // eax
  __int64 v35; // rcx
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128i v39; // xmm2
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm5
  __m128 v43; // xmm5
  __m128 v44; // xmm3
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm0
  int v48; // edx
  int v49; // eax
  __int64 v50; // rcx
  __m128 v51; // xmm0
  __m128 v52; // xmm1
  int v54; // edx
  unsigned int v55; // er8
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm2
  __m128 v59; // xmm1
  __m128 v60; // xmm5
  __m128 v61; // xmm1
  __m128 v62; // xmm5
  __m128 v63; // xmm4
  __m128 v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm0
  __m128i v67; // xmm2
  __m128i v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm1
  int v71; // ecx
  int v72; // eax
  __int64 v73; // rcx
  __m128 v74; // xmm0
  hkMatrix3f v75; // [rsp+20h] [rbp-78h]

  v4 = fpp;
  v5 = fcp;
  v6 = manifold;
  v7 = this;
  v8 = 8;
  while ( 1 )
  {
    v9 = (__m128i)xmmword_141A720C0;
    v10 = v7->m_sepDist[0].m_quad;
    v11 = _mm_load_si128((const __m128i *)&xmmword_141A720B0);
    v12 = &v7->m_sepDist[1].m_quad;
    v13 = 4i64;
    v14 = (__m128i)xmmword_141A720C0;
    do
    {
      v15 = *v12;
      v9 = _mm_add_epi32(v9, v11);
      ++v12;
      v16 = (__m128i)_mm_cmpltps(v10, v15);
      v17 = _mm_max_ps(v15, v10);
      v10 = v17;
      v14 = _mm_or_si128(_mm_and_si128(v9, v16), _mm_andnot_si128(v16, v14));
      --v13;
    }
    while ( v13 );
    v18 = (__m128i)_mm_cmpeqps(
                     _mm_max_ps(
                       _mm_shuffle_ps(v17, v17, 170),
                       _mm_max_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0))),
                     v17);
    v19 = _mm_or_si128(_mm_andnot_si128(v18, (__m128i)0i64), _mm_and_si128(v14, v18));
    v20 = _mm_shuffle_epi32(v19, 0);
    v21 = _mm_shuffle_epi32(v19, 85);
    v22 = _mm_shuffle_epi32(v19, 170);
    v23 = _mm_cmpgt_epi32(v20, v21);
    v24 = _mm_or_si128(_mm_and_si128(v23, v20), _mm_andnot_si128(v23, v21));
    v25 = _mm_cmpgt_epi32(v24, v22);
    v26 = _mm_cvtsi128_si32(_mm_or_si128(_mm_and_si128(v25, v24), _mm_andnot_si128(v25, v22)));
    if ( v26 <= 2 )
    {
      v5->m_featureIdA = v26;
      v4->m_featureIndexA = v26;
      hkMatrix3f::setTranspose(&v75, (hkMatrix3f *)&v7->m_aTb.m_rotation.m_col0);
      v27 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v26], v7->m_dinA.m_quad);
      v28 = _mm_or_ps(_mm_shuffle_ps(v27, v27, 78), v27);
      v29 = (__m128i)_mm_cmpltps(_mm_or_ps(_mm_shuffle_ps(v28, v28, 177), v28), (__m128)0i64);
      _mm_store_si128((__m128i *)&v4->m_normalIsFlipped, v29);
      v30 = _mm_xor_ps(
              (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32((__m128i)0i64, v29), 0x1Fu), 0x1Fu),
              v7->m_radiusB.m_quad);
      v4->m_vB.m_quad = v30;
      v31 = _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32(
                          (__m128i)_mm_add_ps(
                                     _mm_xor_ps(
                                       (__m128)_mm_slli_epi32(
                                                 _mm_srli_epi32(
                                                   (__m128i)_mm_cmpleps(v7->m_dinB.m_quad, (__m128)0i64),
                                                   0x1Fu),
                                                 0x1Fu),
                                       _mm_xor_ps(
                                         (__m128)_mm_slli_epi32(_mm_srli_epi32(v29, 0x1Fu), 0x1Fu),
                                         (__m128)_xmm)),
                                     *(&v75.m_col0.m_quad + (signed int)v26)),
                          0x1Fu),
                        0x1Fu),
              v30);
      v4->m_vB.m_quad = v31;
      v32 = v4->m_normalIsFlipped.m_mask;
      v33 = 16 * (_mm_movemask_ps(_mm_cmpltps(v4->m_vB.m_quad, (__m128)0i64)) & 7);
      v4->m_vA.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v7->m_aTb.m_rotation.m_col1.m_quad),
                              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v7->m_aTb.m_rotation.m_col0.m_quad)),
                            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v7->m_aTb.m_rotation.m_col2.m_quad)),
                          v7->m_aTb.m_translation.m_quad);
      if ( _mm_movemask_ps(v32) )
        LOBYTE(v33) = v33 | 8;
      v5->m_featureIdB = v33;
      v34 = (unsigned __int8)v6->m_numPoints - 1;
      v35 = v34;
      if ( v34 >= 0 )
      {
        while ( v6->m_contactPoints[v35].m_featureIdA != v5->m_featureIdA
             || v6->m_contactPoints[v35].m_featureIdB != (_BYTE)v33 )
        {
          if ( --v35 < 0 )
            goto LABEL_11;
        }
        return 1i64;
      }
LABEL_11:
      if ( (_mm_movemask_ps(
              _mm_cmpltps(
                (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)v4), 1u), 1u),
                v7->m_keepRadiusA.m_quad)) & 7) == 7 )
      {
        v51 = _mm_and_ps(
                _mm_sub_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(_mm_load_si128((const __m128i *)&v4->m_normalIsFlipped), 0x1Fu),
                              0x1Fu),
                    v4->m_vA.m_quad),
                  v7->m_radiusA.m_quad),
                (__m128)`hkVector4f::getComponent::`2::indexToMask[v4->m_featureIndexA]);
        goto LABEL_22;
      }
      goto LABEL_44;
    }
    if ( v26 > 6 )
      break;
    v5->m_featureIdA = v26;
    v4->m_featureIndexA = v26;
    v36 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v26 - 4], v7->m_dinB.m_quad);
    v37 = *((__m128 *)&v7->m_bodyA + (signed int)(v26 - 4) + 4i64);
    v38 = _mm_or_ps(_mm_shuffle_ps(v36, v36, 78), v36);
    v39 = (__m128i)_mm_cmpltps(_mm_or_ps(_mm_shuffle_ps(v38, v38, 177), v38), (__m128)0i64);
    _mm_store_si128((__m128i *)&v4->m_normalIsFlipped, v39);
    v40 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v39, 0x1Fu), 0x1Fu);
    v41 = _mm_xor_ps(v7->m_radiusA.m_quad, v40);
    v4->m_vA.m_quad = v41;
    v42 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_add_ps(
                                   _mm_xor_ps(
                                     (__m128)_mm_slli_epi32(
                                               _mm_srli_epi32(
                                                 (__m128i)_mm_cmpleps(v7->m_dinB.m_quad, (__m128)0i64),
                                                 0x1Fu),
                                               0x1Fu),
                                     _mm_xor_ps((__m128)_xmm_b727c5acb727c5acb727c5acb727c5ac, v40)),
                                   v37),
                        0x1Fu),
                      0x1Fu),
            v41);
    v4->m_vA.m_quad = v42;
    v43 = _mm_sub_ps(v42, v7->m_aTb.m_translation.m_quad);
    v44 = v7->m_aTb.m_rotation.m_col2.m_quad;
    v45 = _mm_unpacklo_ps(v7->m_aTb.m_rotation.m_col0.m_quad, v7->m_aTb.m_rotation.m_col1.m_quad);
    v46 = _mm_movelh_ps(v45, v44);
    v47 = v4->m_normalIsFlipped.m_mask;
    v48 = 16 * (_mm_movemask_ps(_mm_cmpltps(v4->m_vA.m_quad, (__m128)0i64)) & 7);
    v4->m_vB.m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(_mm_movehl_ps(v46, v45), v44, 212)),
                          _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v46)),
                        _mm_mul_ps(
                          _mm_shuffle_ps(v43, v43, 170),
                          _mm_shuffle_ps(
                            _mm_unpackhi_ps(v7->m_aTb.m_rotation.m_col0.m_quad, v7->m_aTb.m_rotation.m_col1.m_quad),
                            v44,
                            228)));
    if ( _mm_movemask_ps(v47) )
      LOBYTE(v48) = v48 | 8;
    v5->m_featureIdB = v48;
    v49 = (unsigned __int8)v6->m_numPoints - 1;
    v50 = v49;
    if ( v49 >= 0 )
    {
      while ( v6->m_contactPoints[v50].m_featureIdA != v5->m_featureIdA
           || v6->m_contactPoints[v50].m_featureIdB != (_BYTE)v48 )
      {
        if ( --v50 < 0 )
          goto LABEL_20;
      }
      return 1i64;
    }
LABEL_20:
    if ( (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v4->m_vB), 1u), 1u),
              v7->m_keepRadiusB.m_quad)) & 7) == 7 )
    {
      v51 = _mm_and_ps(
              _mm_sub_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              _mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&v4->m_normalIsFlipped), (__m128i)0i64),
                              0x1Fu),
                            0x1Fu),
                  v4->m_vB.m_quad),
                v7->m_radiusB.m_quad),
              (__m128)`hkVector4f::getComponent::`2::indexToMask[v4->m_featureIndexA - 4i64]);
LABEL_22:
      v52 = _mm_or_ps(_mm_shuffle_ps(v51, v51, 78), v51);
      v4->m_distance.m_real = _mm_or_ps(_mm_shuffle_ps(v52, v52, 177), v52);
      return 2i64;
    }
LABEL_44:
    --v8;
    v74 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v26 & 3];
    v7->m_sepDist[(unsigned __int64)v26 >> 2] = (hkVector4f)_mm_or_ps(
                                                              _mm_and_ps(v74, (__m128)xmmword_141A712F0),
                                                              _mm_andnot_ps(
                                                                v74,
                                                                v7->m_sepDist[(unsigned __int64)v26 >> 2].m_quad));
    if ( v8 <= 0 )
      return 0i64;
  }
  v54 = (v26 - 8) & 3;
  v4->m_featureIndexB = v54;
  v55 = (v26 - 8) >> 2;
  v4->m_featureIndexA = v55;
  v56 = v7->m_aTb.m_rotation.m_col2.m_quad;
  v57 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(*((__m128 *)&v7->m_bodyA + v54 + 4i64), *((__m128 *)&v7->m_bodyA + v54 + 4i64), 201),
            *(&transform.m_quad + v55)),
          _mm_mul_ps(
            _mm_shuffle_ps(*(&transform.m_quad + v55), *(&transform.m_quad + v55), 201),
            *((__m128 *)&v7->m_bodyA + v54 + 4i64)));
  v58 = _mm_shuffle_ps(v57, v57, 201);
  v59 = _mm_mul_ps(v7->m_dinA.m_quad, v58);
  v60 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)), _mm_shuffle_ps(v59, v59, 170));
  v61 = _mm_unpacklo_ps(v7->m_aTb.m_rotation.m_col0.m_quad, v7->m_aTb.m_rotation.m_col1.m_quad);
  v62 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(v60, (__m128)0i64), 0x1Fu), 0x1Fu), v58);
  v63 = _mm_shuffle_ps(
          _mm_unpackhi_ps(v7->m_aTb.m_rotation.m_col0.m_quad, v7->m_aTb.m_rotation.m_col1.m_quad),
          v56,
          228);
  v64 = _mm_movelh_ps(v61, v56);
  v4->m_vA.m_quad = v62;
  v65 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(_mm_movehl_ps(v64, v61), v56, 212));
  v66 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v64);
  v67 = (__m128i)v4->m_vA;
  v68 = (__m128i)_mm_add_ps(_mm_add_ps(v65, v66), _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), v63));
  v4->m_vB = (hkVector4f)v68;
  switch ( v55 )
  {
    case 1u:
      v69 = _mm_shuffle_ps(_mm_unpacklo_ps((__m128)v67, (__m128)0i64), (__m128)v67, 228);
      break;
    case 2u:
      v69 = _mm_shuffle_ps((__m128)v67, _mm_unpackhi_ps((__m128)v67, (__m128)0i64), 180);
      break;
    case 3u:
      v69 = (__m128)_mm_srli_si128(_mm_slli_si128(v67, 4), 4);
      break;
    default:
      v69 = (__m128)_mm_slli_si128(_mm_srli_si128(v67, 4), 4);
      break;
  }
  switch ( v54 )
  {
    case 1:
      v70 = _mm_shuffle_ps(_mm_unpacklo_ps((__m128)v68, (__m128)0i64), (__m128)v68, 228);
      break;
    case 2:
      v70 = _mm_shuffle_ps((__m128)v68, _mm_unpackhi_ps((__m128)v68, (__m128)0i64), 180);
      break;
    case 3:
      v70 = (__m128)_mm_srli_si128(_mm_slli_si128(v68, 4), 4);
      break;
    default:
      v70 = (__m128)_mm_slli_si128(_mm_srli_si128(v68, 4), 4);
      break;
  }
  v71 = (unsigned __int8)(v55 | 16 * (_mm_movemask_ps(_mm_cmpltps(v69, (__m128)0i64)) | 0xF8));
  v5->m_featureIdA = v71;
  v5->m_featureIdB = v54 + (~(16 * _mm_movemask_ps(_mm_cmpltps(v70, (__m128)0i64))) & 0x70);
  v4->m_featureIndexA = v71;
  v4->m_featureIndexB = (unsigned __int8)v5->m_featureIdB;
  v72 = (unsigned __int8)v6->m_numPoints - 1;
  v73 = v72;
  if ( v72 < 0 )
  {
LABEL_43:
    if ( hkpBoxBoxCollisionDetection::isValidEdgeEdge(v7, v4) )
      return 2i64;
    goto LABEL_44;
  }
  while ( v6->m_contactPoints[v73].m_featureIdA != v5->m_featureIdA
       || v6->m_contactPoints[v73].m_featureIdB != v5->m_featureIdB )
  {
    if ( --v73 < 0 )
      goto LABEL_43;
  }
  return 1i64;
}

// File Line: 1130
// RVA: 0xD3A110
char __fastcall hkpBoxBoxCollisionDetection::isValidEdgeEdge(hkpBoxBoxCollisionDetection *this, hkpBoxBoxCollisionDetection::hkpFeaturePointCache *fpp)
{
  hkVector4f v2; // xmm3
  hkpBoxBoxCollisionDetection *v3; // r10
  hkpBoxBoxCollisionDetection::hkpFeaturePointCache *v4; // r9
  hkVector4f v5; // xmm0
  __m128 v6; // xmm15
  __m128 v7; // xmm11
  __int64 v8; // r11
  __m128 v9; // xmm4
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm5
  __m128 v14; // xmm0
  __m128 v15; // xmm13
  __m128 v16; // xmm1
  __m128 v17; // xmm13
  signed int v18; // edx
  signed int v19; // ecx
  signed int v20; // eax
  float v21; // xmm8_4
  __m128 v22; // xmm3
  float v23; // xmm7_4
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm12
  __m128 v28; // xmm10
  __m128 v29; // xmm1
  __m128 v30; // xmm12
  __m128 v31; // xmm0
  __m128 v32; // xmm10
  __m128 v33; // xmm2
  __m128 v34; // xmm14
  __m128 v35; // xmm6
  __m128 v36; // xmm4
  char result; // al
  __m128 v38; // xmm1
  signed int v39; // eax
  float v40; // xmm8_4
  __m128 v41; // xmm4
  float v42; // xmm0_4
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __m128 v46; // xmm6
  __m128 v47; // xmm3
  __m128 v48; // xmm5
  __m128 v49; // xmm5
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm5
  __m128 v55; // xmm1
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm3

  v2.m_quad = (__m128)this->m_radiusA;
  v3 = this;
  v4 = fpp;
  v5.m_quad = (__m128)this->m_radiusB;
  v6 = _mm_xor_ps(
         (__m128)_mm_slli_epi32(
                   _mm_srli_epi32(hkVector4fComparison_maskToComparison_373[(fpp->m_featureIndexA >> 4) & 7], 0x1Fu),
                   0x1Fu),
         query.m_quad);
  v7 = _mm_mul_ps(v6, v2.m_quad);
  v8 = fpp->m_featureIndexA & 0xF;
  v9 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[fpp->m_featureIndexB & 0xF], v5.m_quad);
  v10 = (__m128)`hkVector4f::getComponent::`2::indexToMask[fpp->m_featureIndexA & 0xF];
  v11 = _mm_mul_ps(
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(hkVector4fComparison_maskToComparison_373[(fpp->m_featureIndexB >> 4) & 7], 0x1Fu),
                      0x1Fu),
            query.m_quad),
          v5.m_quad);
  v12 = _mm_or_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v13 = _mm_mul_ps(
          _mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v12, v12, 177), v12), (__m128)xmmword_141A710D0),
          *((__m128 *)&this->m_bodyA + (fpp->m_featureIndexB & 0xF) + 4i64));
  v14 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[fpp->m_featureIndexA & 0xF], v2.m_quad);
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), this->m_aTb.m_rotation.m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), this->m_aTb.m_rotation.m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), this->m_aTb.m_rotation.m_col2.m_quad));
  v16 = _mm_or_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v17 = _mm_sub_ps(_mm_add_ps(v15, this->m_aTb.m_translation.m_quad), v7);
  v18 = 0;
  v19 = 0;
  v20 = 0;
  LODWORD(v21) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_edgeEndpointTolerance),
                                      (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_edgeEndpointTolerance),
                                      0);
  v22 = _mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v16, v16, 177), v16), _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A710D0));
  v23 = 1.0 - v21;
  v24 = _mm_and_ps(v13, v10);
  v25 = _mm_or_ps(_mm_shuffle_ps(v24, v24, 78), v24);
  v26 = _mm_or_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v27 = _mm_or_ps(_mm_shuffle_ps(v25, v25, 177), v25);
  v28 = _mm_or_ps(_mm_shuffle_ps(v26, v26, 177), v26);
  v29 = _mm_mul_ps(v17, v13);
  v30 = _mm_mul_ps(v27, v22);
  v31 = _mm_and_ps(v17, v10);
  v32 = _mm_mul_ps(_mm_mul_ps(v28, v28), (__m128)xmmword_141A710F0);
  v33 = _mm_or_ps(_mm_shuffle_ps(v31, v31, 78), v31);
  v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v35 = (__m128)_mm_srli_epi32(
                  _mm_slli_epi32((__m128i)_mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v22, v22), v32), _mm_mul_ps(v30, v30)), 1u),
                  1u);
  v36 = _mm_sub_ps(
          _mm_mul_ps(_mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v33, v33, 177), v33), v22), v32),
          _mm_mul_ps(v34, v30));
  if ( v36.m128_f32[0] >= (float)(v35.m128_f32[0] * (float)(1.0 - v21)) )
    v19 = 1;
  if ( v36.m128_f32[0] <= (float)(v35.m128_f32[0] * v21) )
    v20 = 1;
  if ( v20 | v19 )
    return 0;
  v38 = _mm_rcp_ps(v35);
  v39 = 0;
  v40 = v21 * v32.m128_f32[0];
  v41 = _mm_mul_ps(v36, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v38)), v38));
  v42 = (float)(v41.m128_f32[0] * v30.m128_f32[0]) - v34.m128_f32[0];
  if ( v42 >= (float)(v23 * v32.m128_f32[0]) )
    v39 = 1;
  if ( v42 <= v40 )
    v18 = 1;
  if ( v18 | v39 )
    return 0;
  v43 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v8];
  v44 = _mm_and_ps(v7, (__m128)`hkVector4f::getComponent::`2::indexToMask[v8]);
  v45 = _mm_or_ps(_mm_shuffle_ps(v44, v44, 78), v44);
  v46 = _mm_or_ps(
          _mm_and_ps(_mm_add_ps(_mm_or_ps(_mm_shuffle_ps(v45, v45, 177), v45), _mm_mul_ps(v41, v22)), v43),
          _mm_andnot_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v8], v7));
  v47 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v22, (__m128)xmmword_141A711B0), v43), _mm_andnot_ps(v43, (__m128)0i64));
  v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v47), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v13));
  v49 = _mm_shuffle_ps(v48, v48, 201);
  v50 = _mm_mul_ps(v49, v49);
  v51 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)), _mm_shuffle_ps(v50, v50, 170));
  v52 = _mm_rsqrt_ps(v51);
  v53 = _mm_andnot_ps(
          _mm_cmpleps(v51, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)), _mm_mul_ps(*(__m128 *)_xmm, v52)));
  v54 = _mm_mul_ps(v49, v53);
  if ( (float)(v53.m128_f32[0] * v51.m128_f32[0]) < v3->m_boundaryTolerance.m_real.m128_f32[0] )
    return 0;
  v55 = _mm_mul_ps(v54, v6);
  v56 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32(
                      (__m128i)_mm_cmpltps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                                   _mm_shuffle_ps(v55, v55, 170)),
                                 (__m128)0i64),
                      0x1Fu),
                    0x1Fu),
          v54);
  v57 = _mm_mul_ps(v56, v17);
  v58 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)), _mm_shuffle_ps(v57, v57, 170));
  if ( v58.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps(v3->m_tolerance4.m_quad, v3->m_tolerance4.m_quad, 0)) )
    return 0;
  v4->m_vA.m_quad = v46;
  v4->m_distance.m_real = v58;
  result = 1;
  v4->m_nA.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v56);
  return result;
}

// File Line: 1434
// RVA: 0xD392C0
hkBool *__fastcall hkpBoxBoxCollisionDetection::calculateClosestPoint(hkpBoxBoxCollisionDetection *this, hkBool *result, hkContactPoint *contact)
{
  hkpBoxBoxCollisionDetection *v3; // rdi
  hkContactPoint *v4; // rsi
  hkBool *v5; // rbx
  __m128 v6; // xmm5
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 *v13; // rax
  __m128 v14; // xmm2
  hkpBoxBoxCollisionDetection::hkpFeaturePointCache fpp; // [rsp+20h] [rbp-A8h]
  hkpBoxBoxManifold manifold; // [rsp+80h] [rbp-48h]
  hkpFeatureContactPoint fcp; // [rsp+D0h] [rbp+8h]
  hkResult resulta; // [rsp+E8h] [rbp+20h]

  v3 = this;
  v4 = contact;
  v5 = result;
  hkpBoxBoxManifold::hkpBoxBoxManifold(&manifold);
  v6 = v3->m_aTb.m_translation.m_quad;
  v3->m_dinA.m_quad = v6;
  v7 = v3->m_aTb.m_rotation.m_col2.m_quad;
  v8 = v3->m_aTb.m_rotation.m_col0.m_quad;
  fcp.m_contactPointId = 0;
  fpp.m_nA = 0i64;
  fpp.m_normalIsFlipped = 0i64;
  v9 = _mm_unpacklo_ps(v8, v3->m_aTb.m_rotation.m_col1.m_quad);
  v10 = _mm_movelh_ps(v9, v7);
  v3->m_dinB.m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v7, 212)),
                          _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), v10)),
                        _mm_mul_ps(
                          _mm_shuffle_ps(v6, v6, 170),
                          _mm_shuffle_ps(_mm_unpackhi_ps(v8, v3->m_aTb.m_rotation.m_col1.m_quad), v7, 228)));
  if ( hkpBoxBoxCollisionDetection::checkIntersection(v3, &resulta, &v3->m_tolerance4)->m_enum
    || hkpBoxBoxCollisionDetection::findClosestPoint(v3, &manifold, &fcp, &fpp) != 2 )
  {
    v5->m_bool = 0;
  }
  else
  {
    if ( fpp.m_featureIndexA > 2 )
    {
      v13 = &v3->m_wTa->m_rotation.m_col0.m_quad;
      v11 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 85), v13[1]),
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 0), *v13)),
                _mm_mul_ps(_mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 170), v13[2])),
              v13[3]);
      if ( fpp.m_featureIndexA > 6 )
        v12 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 85), v13[1]),
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 0), *v13)),
                _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 170), v13[2]));
      else
        v12 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            _mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&fpp.m_normalIsFlipped), (__m128i)0i64),
                            0x1Fu),
                          0x1Fu),
                *(&v3->m_wTb->m_rotation.m_col0.m_quad + (unsigned __int8)fcp.m_featureIdA - 4i64));
    }
    else
    {
      v11 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 85), v3->m_wTb->m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 0), v3->m_wTb->m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 170), v3->m_wTb->m_rotation.m_col2.m_quad)),
              v3->m_wTb->m_translation.m_quad);
      v12 = _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32(
                          _mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&fpp.m_normalIsFlipped), (__m128i)0i64),
                          0x1Fu),
                        0x1Fu),
              *(&v3->m_wTa->m_rotation.m_col0.m_quad + (unsigned __int8)fcp.m_featureIdA));
    }
    v14 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, fpp.m_distance.m_real), 196);
    if ( fcp.m_featureIdA > 2u )
      v11 = _mm_sub_ps(v11, _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v14));
    v4->m_position.m_quad = v11;
    v5->m_bool = 1;
    v4->m_separatingNormal.m_quad = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, _mm_shuffle_ps(v14, v14, 255)), 196);
  }
  return v5;
}

// File Line: 1472
// RVA: 0xD37480
void __fastcall hkpBoxBoxCollisionDetection::calcManifold(hkpBoxBoxCollisionDetection *this, hkpBoxBoxManifold *manifold)
{
  __m128 v2; // xmm6
  int v3; // er14
  hkpBoxBoxManifold *v4; // rsi
  hkpBoxBoxCollisionDetection *v5; // rdi
  int v6; // er15
  hkVector4f v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm8
  hkpBoxBoxManifold *v11; // r14
  hkpBoxBoxManifold *v12; // rbx
  __int64 v13; // rcx
  unsigned __int8 v14; // al
  __m128i v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 v18; // xmm7
  __m128 v19; // xmm4
  __m128i v20; // xmm2
  __m128 **v21; // rax
  __m128 *v22; // rdx
  __int64 v23; // rax
  __int64 v24; // rcx
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm5
  unsigned __int8 v29; // al
  __m128i v30; // xmm9
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm7
  __m128 v35; // xmm5
  __m128i v36; // xmm6
  __m128 **v37; // rax
  __m128 *v38; // rdx
  signed __int64 v39; // rax
  __m128 v40; // xmm9
  __int64 v41; // rcx
  __m128 v42; // xmm6
  __m128 v43; // xmm0
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  int v46; // eax
  __m128 **v47; // rax
  hkVector4f v48; // xmm1
  hkVector4f v49; // xmm0
  __m128 *v50; // rcx
  __m128 *v51; // rax
  __m128 v52; // xmm2
  hkVector4f v53; // xmm1
  __m128 v54; // xmm0
  __m128 v55; // xmm2
  signed int v56; // ebx
  __m128 v57; // xmm6
  __m128 v58; // xmm4
  __m128 v59; // xmm1
  __m128 v60; // xmm2
  unsigned int v61; // ecx
  __m128 v62; // xmm2
  __m128 v63; // xmm3
  hkVector4f *v64; // r8
  __m128 v65; // xmm8
  hkpFeatureContactPoint v66; // eax
  int v67; // er13
  hkVector4fComparison v68; // xmm7
  hkVector4f v69; // xmm9
  hkpFeatureContactPoint v70; // er15
  __m128 v71; // xmm3
  unsigned __int8 v72; // r9
  signed int v73; // ecx
  hkVector4f v74; // xmm1
  __m128i v75; // xmm2
  __m128 v76; // xmm1
  int v77; // er8
  __m128 v78; // xmm6
  float v79; // xmm8_4
  unsigned __int64 v80; // rdx
  hkpBoxBoxManifold *v81; // r15
  signed __int64 v82; // rbx
  hkpProcessCollisionOutput *v83; // rdx
  __m128 v84; // xmm2
  hkpProcessCdPoint *v85; // rcx
  __m128 v86; // xmm3
  __m128 v87; // xmm5
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  hkVector4f v90; // xmm8
  hkVector4f v91; // xmm6
  __m128 *v92; // rax
  __m128 v93; // xmm3
  __m128 v94; // xmm0
  __m128 v95; // xmm1
  int v96; // er9
  int v97; // edx
  float v98; // xmm4_4
  __m128 v99; // xmm3
  float v100; // xmm4_4
  __int64 v101; // r8
  hkpBoxBoxManifold *v102; // rcx
  __m128 v103; // xmm2
  __m128 v104; // xmm2
  int v105; // eax
  __int64 v106; // r14
  __m128 *v107; // rbx
  unsigned int v108; // edx
  __m128 v109; // xmm7
  __m128 v110; // xmm1
  __m128 v111; // xmm0
  __m128 v112; // xmm6
  int v113; // ecx
  __m128 v114; // xmm7
  __m128 v115; // xmm2
  __m128 v116; // xmm2
  unsigned __int16 v117; // ax
  unsigned __int8 v118; // cl
  hkpProcessCollisionOutput *v119; // r8
  __int64 v120; // r10
  hkTransformf *v121; // rax
  __m128 *v122; // rdx
  __m128 v123; // xmm9
  __m128 v124; // xmm6
  __m128 v125; // xmm7
  __m128 v126; // xmm10
  hkTransformf *v127; // rax
  __m128 v128; // xmm2
  __m128 v129; // xmm4
  __m128 v130; // xmm3
  __m128 v131; // xmm6
  __m128 v132; // xmm8
  __m128 v133; // xmm1
  __m128 v134; // xmm0
  __m128i v135; // xmm13
  __m128 v136; // xmm5
  __m128i v137; // xmm12
  __m128 v138; // xmm4
  int v139; // er11
  float v140; // xmm3_4
  char v141; // r9
  signed int v142; // ecx
  __m128 v143; // xmm6
  __m128 *v144; // r14
  __m128 v145; // xmm4
  __m128 v146; // xmm2
  __m128 v147; // xmm4
  signed int v148; // eax
  __m128 v149; // xmm5
  __m128 v150; // xmm1
  float v151; // xmm0_4
  __m128 v152; // xmm4
  __m128 v153; // xmm0
  int v154; // er8
  __m128 v155; // xmm1
  __m128 v156; // xmm0
  __m128 v157; // xmm2
  int v158; // ecx
  __m128 v159; // xmm13
  __int64 v160; // rax
  __m128 v161; // xmm0
  hkpFeatureContactPoint v162; // ebx
  const unsigned __int16 *v163; // r13
  unsigned __int16 v164; // cx
  int v165; // er9
  unsigned __int8 v166; // dl
  __int64 v167; // rcx
  __m128i v168; // xmm7
  __m128 v169; // xmm8
  __m128 v170; // xmm10
  __m128 v171; // xmm12
  __m128 v172; // xmm8
  __m128i v173; // xmm6
  __m128 v174; // xmm1
  __m128 v175; // xmm0
  __m128 v176; // xmm9
  __m128 *v177; // rax
  __m128 v178; // xmm0
  __m128 v179; // xmm3
  __m128 v180; // xmm1
  int v181; // edx
  float v182; // xmm4_4
  __m128 v183; // xmm3
  float v184; // xmm4_4
  __int64 v185; // r8
  hkpBoxBoxManifold *v186; // rcx
  __m128 v187; // xmm2
  __m128 v188; // xmm2
  int v189; // eax
  __int64 v190; // r15
  unsigned int v191; // edx
  __m128 v192; // xmm7
  __m128 v193; // xmm1
  __m128 v194; // xmm0
  __m128 v195; // xmm6
  int v196; // ecx
  __m128 v197; // xmm7
  __m128 v198; // xmm2
  __m128 v199; // xmm2
  int v200; // ecx
  const unsigned __int16 *v201; // r13
  unsigned __int16 v202; // ax
  int v203; // er9
  unsigned __int8 v204; // dl
  __int64 v205; // rcx
  __m128i v206; // xmm8
  unsigned __int16 v207; // ax
  __m128 v208; // xmm3
  __m128 v209; // xmm1
  __m128 v210; // xmm2
  __m128 v211; // xmm6
  __m128 v212; // xmm5
  __m128i v213; // xmm7
  __m128 v214; // xmm8
  __m128 v215; // xmm1
  __m128 v216; // xmm0
  __m128 v217; // xmm9
  __m128 *v218; // rax
  __m128 v219; // xmm3
  __m128 v220; // xmm0
  __m128 v221; // xmm1
  int v222; // edx
  float v223; // xmm4_4
  __m128 v224; // xmm3
  float v225; // xmm4_4
  __int64 v226; // r8
  hkpBoxBoxManifold *v227; // rcx
  __m128 v228; // xmm2
  __m128 v229; // xmm2
  int v230; // eax
  __int64 v231; // r15
  __m128 *v232; // r14
  unsigned int v233; // edx
  __int64 v234; // rcx
  hkTransformf *v235; // rax
  __m128 v236; // xmm1
  __m128 v237; // xmm0
  __m128 v238; // xmm6
  int v239; // ecx
  __m128 v240; // xmm1
  __m128 v241; // xmm2
  __m128 v242; // xmm2
  unsigned __int16 v243; // ax
  int planeMaskB; // [rsp+40h] [rbp-C0h]
  hkpFeatureContactPoint v245; // [rsp+44h] [rbp-BCh]
  char v246; // [rsp+48h] [rbp-B8h]
  hkVector4f qin; // [rsp+50h] [rbp-B0h]
  hkpBoxBoxCollisionDetection::hkpFeaturePointCache fpp; // [rsp+60h] [rbp-A0h]
  hkResult result; // [rsp+1A0h] [rbp+A0h]
  hkpFeatureContactPoint v250; // [rsp+1A8h] [rbp+A8h]
  int planeMaskA; // [rsp+1B0h] [rbp+B0h]
  hkpFeatureContactPoint fcp; // [rsp+1B8h] [rbp+B8h]

  v2 = this->m_aTb.m_translation.m_quad;
  v3 = 0;
  v4 = manifold;
  v5 = this;
  v6 = 0;
  this->m_dinA.m_quad = v2;
  v7.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
  v8 = _mm_unpacklo_ps(this->m_aTb.m_rotation.m_col0.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
  v9 = _mm_movelh_ps(v8, v7.m_quad);
  this->m_dinB.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(_mm_movehl_ps(v9, v8), v7.m_quad, 212),
                              _mm_shuffle_ps(v2, v2, 85)),
                            _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), v9)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(
                              _mm_unpackhi_ps(
                                this->m_aTb.m_rotation.m_col0.m_quad,
                                this->m_aTb.m_rotation.m_col1.m_quad),
                              v7.m_quad,
                              228),
                            _mm_shuffle_ps(v2, v2, 170)));
  v10 = (__m128)xmmword_141A712A0;
  if ( manifold->m_numPoints )
  {
    v11 = manifold;
    while ( 1 )
    {
      v12 = v11;
      ++v6;
      v11 = (hkpBoxBoxManifold *)((char *)v11 + 4);
      v13 = (unsigned __int8)v12->m_contactPoints[0].m_featureIdA;
      if ( (signed int)v13 > 2 )
      {
        if ( (signed int)v13 > 6 )
        {
          v46 = (unsigned __int8)v12->m_contactPoints[0].m_featureIdB;
          fpp.m_featureIndexA = (unsigned __int8)v12->m_contactPoints[0].m_featureIdA;
          fpp.m_featureIndexB = v46;
          if ( !hkpBoxBoxCollisionDetection::isValidEdgeEdge(v5, &fpp) )
            goto LABEL_17;
          v47 = (__m128 **)v5->m_result;
          v48.m_quad = (__m128)fpp.m_vA;
          v10 = _mm_min_ps(v10, fpp.m_distance.m_real);
          v49.m_quad = (__m128)fpp.m_vA;
          v50 = *v47;
          *v47 += 3;
          v50[2].m128_i32[0] = v12->m_contactPoints[0].m_contactPointId;
          v51 = &v5->m_wTa->m_rotation.m_col0.m_quad;
          v52 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v49.m_quad, 85), v51[1]),
                    _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v48.m_quad, 0), *v51)),
                  _mm_mul_ps(_mm_shuffle_ps(v48.m_quad, v48.m_quad, 170), v51[2]));
          v53.m_quad = (__m128)fpp.m_nA;
          v54 = _mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 0);
          *v50 = _mm_add_ps(v52, v51[3]);
          v55 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v53.m_quad, v53.m_quad, 85), v5->m_wTa->m_rotation.m_col1.m_quad),
                    _mm_mul_ps(v54, v5->m_wTa->m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v53.m_quad, v53.m_quad, 170), v5->m_wTa->m_rotation.m_col2.m_quad));
          v50[1] = _mm_shuffle_ps(v55, _mm_unpackhi_ps(v55, fpp.m_distance.m_real), 196);
        }
        else
        {
          v29 = v12->m_contactPoints[0].m_featureIdB;
          if ( v29 & 8 )
            v30 = (__m128i)xmmword_141A86110;
          else
            v30 = 0i64;
          v31 = v5->m_aTb.m_rotation.m_col2.m_quad;
          v32 = _mm_unpacklo_ps(v5->m_aTb.m_rotation.m_col0.m_quad, v5->m_aTb.m_rotation.m_col1.m_quad);
          v33 = _mm_movelh_ps(v32, v31);
          v34 = _mm_mul_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(
                                *(__m128i *)&hkVector4fComparison_maskToComparison_373[4
                                                                                     * (((unsigned int)v29 >> 4) & 7)],
                                0x1Fu),
                              0x1Fu),
                    query.m_quad),
                  v5->m_radiusA.m_quad);
          v35 = _mm_sub_ps(v34, v5->m_aTb.m_translation.m_quad);
          v36 = (__m128i)_mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v33, v32), v31, 212), _mm_shuffle_ps(v35, v35, 85)),
                             _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v33)),
                           _mm_mul_ps(
                             _mm_shuffle_ps(v35, v35, 170),
                             _mm_shuffle_ps(
                               _mm_unpackhi_ps(v5->m_aTb.m_rotation.m_col0.m_quad, v5->m_aTb.m_rotation.m_col1.m_quad),
                               v31,
                               228)));
          if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32(v36, 1u), 1u), v5->m_keepRadiusB.m_quad)) & 7) != 7 )
          {
LABEL_17:
            v11 = (hkpBoxBoxManifold *)((char *)v11 - 4);
            --v6;
            if ( v11->m_contactPoints[0].m_featureIdA <= 6u )
              --v4->m_faceVertexFeatureCount;
            ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
              v5->m_contactMgr,
              v11->m_contactPoints[0].m_contactPointId,
              v5->m_result->m_constraintOwner.m_storage);
            hkpBoxBoxManifold::removePoint(v4, v6);
            goto LABEL_20;
          }
          v37 = (__m128 **)v5->m_result;
          v38 = *v37;
          *v37 += 3;
          v39 = v13 - 4;
          v40 = (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v30, (__m128i)0i64), 0x1Fu), 0x1Fu);
          v41 = (unsigned __int8)v12->m_contactPoints[0].m_featureIdA - 4;
          v42 = _mm_and_ps(
                  _mm_sub_ps(_mm_xor_ps((__m128)v36, v40), v5->m_radiusB.m_quad),
                  (__m128)`hkVector4f::getComponent::`2::indexToMask[v39]);
          v38[2].m128_i32[0] = v12->m_contactPoints[0].m_contactPointId;
          v43 = _mm_or_ps(_mm_shuffle_ps(v42, v42, 78), v42);
          v44 = _mm_or_ps(_mm_shuffle_ps(v43, v43, 177), v43);
          v10 = _mm_min_ps(v10, v44);
          *v38 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v5->m_wTa->m_rotation.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v5->m_wTa->m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v5->m_wTa->m_rotation.m_col2.m_quad)),
                   v5->m_wTa->m_translation.m_quad);
          v45 = _mm_xor_ps(*(&v5->m_wTb->m_rotation.m_col0.m_quad + v41), v40);
          v38[1] = _mm_shuffle_ps(v45, _mm_unpackhi_ps(v45, v44), 196);
        }
      }
      else
      {
        v14 = v12->m_contactPoints[0].m_featureIdB;
        if ( v14 & 8 )
          v15 = (__m128i)xmmword_141A86110;
        else
          v15 = 0i64;
        v16 = _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              *(__m128i *)&hkVector4fComparison_maskToComparison_373[4 * (((unsigned int)v14 >> 4) & 7)],
                              0x1Fu),
                            0x1Fu),
                  query.m_quad),
                v5->m_radiusB.m_quad);
        v17 = _mm_shuffle_ps(v16, v16, 85);
        v18 = _mm_shuffle_ps(v16, v16, 0);
        v19 = _mm_shuffle_ps(v16, v16, 170);
        v20 = (__m128i)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(v18, v5->m_aTb.m_rotation.m_col0.m_quad),
                             _mm_mul_ps(v17, v5->m_aTb.m_rotation.m_col1.m_quad)),
                           _mm_mul_ps(v5->m_aTb.m_rotation.m_col2.m_quad, v19)),
                         v5->m_aTb.m_translation.m_quad);
        if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32(v20, 1u), 1u), v5->m_keepRadiusA.m_quad)) & 7) != 7 )
          goto LABEL_17;
        v21 = (__m128 **)v5->m_result;
        v22 = *v21;
        *v21 += 3;
        v23 = (signed int)v13;
        v24 = (unsigned __int8)v12->m_contactPoints[0].m_featureIdA;
        v25 = _mm_and_ps(
                _mm_sub_ps(
                  _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v15, 0x1Fu), 0x1Fu), (__m128)v20),
                  v5->m_radiusA.m_quad),
                (__m128)`hkVector4f::getComponent::`2::indexToMask[v23]);
        v22[2].m128_i32[0] = v12->m_contactPoints[0].m_contactPointId;
        v26 = _mm_or_ps(_mm_shuffle_ps(v25, v25, 78), v25);
        v27 = _mm_or_ps(_mm_shuffle_ps(v26, v26, 177), v26);
        v10 = _mm_min_ps(v10, v27);
        *v22 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v5->m_wTb->m_rotation.m_col1.m_quad, v17),
                     _mm_mul_ps(v5->m_wTb->m_rotation.m_col0.m_quad, v18)),
                   _mm_mul_ps(v5->m_wTb->m_rotation.m_col2.m_quad, v19)),
                 v5->m_wTb->m_translation.m_quad);
        v28 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v15, (__m128i)0i64), 0x1Fu), 0x1Fu),
                *(&v5->m_wTa->m_rotation.m_col0.m_quad + v24));
        v22[1] = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, v27), 196);
      }
LABEL_20:
      if ( v6 >= (unsigned __int8)v4->m_numPoints )
      {
        v3 = 0;
        break;
      }
    }
  }
  if ( v4->m_numPoints >= 2u )
  {
    v57 = v4->m_manifoldNormalA.m_quad;
    if ( COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 255)) < 0.0 )
    {
      v61 = v4->m_manifoldNormalB;
      result.m_enum = LODWORD(FLOAT_0_0085937502);
      qin.m_quad.m128_i32[0] = v61;
      v56 = 0;
      qin.m_quad.m128_i32[1] = v61 >> 8;
      qin.m_quad.m128_i32[2] = v61 >> 16;
      qin.m_quad.m128_i32[3] = v61 >> 24;
      v62 = _mm_mul_ps(
              _mm_cvtepi32_ps(_mm_sub_epi32(_mm_and_si128(_mm_load_si128((const __m128i *)&_xmm), (__m128i)qin.m_quad), (__m128i)_xmm)),
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0085937502), (__m128)LODWORD(FLOAT_0_0085937502), 0));
      v63 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), v5->m_aTb.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v5->m_aTb.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), v5->m_aTb.m_rotation.m_col2.m_quad)),
              v4->m_manifoldNormalA.m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170))) < COERCE_FLOAT(
                                                                    _mm_shuffle_ps(
                                                                      (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_manifoldConsistencyCheckAngularCosTolerance),
                                                                      (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_manifoldConsistencyCheckAngularCosTolerance),
                                                                      0)) )
        v56 = 1;
      if ( !v56 && v4->m_isComplete )
        return;
    }
    else
    {
      v58 = v5->m_aTb.m_rotation.m_col2.m_quad;
      v59 = _mm_unpacklo_ps(v5->m_aTb.m_rotation.m_col0.m_quad, v5->m_aTb.m_rotation.m_col1.m_quad);
      v60 = _mm_movelh_ps(v59, v58);
      qin.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v60, v59), v58, 212), _mm_shuffle_ps(v57, v57, 85)),
                       _mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), v60)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(v57, v57, 170),
                       _mm_shuffle_ps(
                         _mm_unpackhi_ps(v5->m_aTb.m_rotation.m_col0.m_quad, v5->m_aTb.m_rotation.m_col1.m_quad),
                         v58,
                         228)));
      v4->m_manifoldNormalA.m_quad = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, g_vectorfConstants[0]), 196);
      v4->m_manifoldNormalB = hkVector4UtilImpl<float>::packQuaternionIntoInt32(&qin);
      v56 = 1;
    }
  }
  else
  {
    v56 = 1;
    _mm_store_si128(
      (__m128i *)&v4->m_manifoldNormalA,
      _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&v4->m_manifoldNormalA), 4), 4));
  }
  if ( v4->m_numPoints )
  {
    v64 = &qin;
    result.m_enum = LODWORD(FLOAT_0_050000001);
    v65 = _mm_sub_ps(
            v10,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0),
              _mm_shuffle_ps(v5->m_tolerance4.m_quad, v5->m_tolerance4.m_quad, 0)));
    qin.m_quad = _mm_shuffle_ps(v65, _mm_unpackhi_ps(v65, (__m128)xmmword_141A712A0), 196);
  }
  else
  {
    v64 = &v5->m_tolerance4;
  }
  if ( hkpBoxBoxCollisionDetection::checkIntersection(v5, &result, v64)->m_enum )
    return;
  fpp.m_nA = 0i64;
  fpp.m_distance = 0i64;
  fpp.m_normalIsFlipped = 0i64;
  HIWORD(result.m_enum) = 0;
  v66 = (hkpFeatureContactPoint)hkpBoxBoxCollisionDetection::findClosestPoint(
                                  v5,
                                  v4,
                                  (hkpFeatureContactPoint *)&result,
                                  &fpp);
  v67 = fpp.m_featureIndexA;
  v68.m_mask = (__m128)fpp.m_normalIsFlipped;
  v69.m_quad = (__m128)fpp.m_nA;
  v70 = v66;
  v250 = v66;
  if ( !v56 || !*(_DWORD *)&v66 )
  {
LABEL_57:
    v72 = result.m_enum;
    goto LABEL_58;
  }
  v71 = v4->m_manifoldNormalA.m_quad;
  v72 = result.m_enum;
  v73 = 0;
  v74.m_quad = (__m128)v4->m_manifoldNormalA;
  v75 = _mm_cmpeq_epi32((__m128i)fpp.m_normalIsFlipped.m_mask, (__m128i)0i64);
  if ( COERCE_FLOAT(_mm_shuffle_ps(v71, v71, 255)) < 0.0 )
    v73 = 1;
  if ( fpp.m_featureIndexA > 2 )
  {
    if ( fpp.m_featureIndexA > 6 )
    {
      if ( v66 == 2 )
        v74.m_quad = (__m128)fpp.m_nA;
    }
    else
    {
      v74.m_quad = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(_mm_srli_epi32(v75, 0x1Fu), 0x1Fu),
                     *((__m128 *)&v5->m_bodyA + LOBYTE(result.m_enum)));
    }
  }
  else
  {
    v74.m_quad = _mm_xor_ps(
                   (__m128)_mm_slli_epi32(_mm_srli_epi32(v75, 0x1Fu), 0x1Fu),
                   *(&transform.m_quad + LOBYTE(result.m_enum)));
  }
  v76 = _mm_shuffle_ps(v74.m_quad, _mm_unpackhi_ps(v74.m_quad, v71), 196);
  v4->m_manifoldNormalA.m_quad = v76;
  if ( v73 )
  {
    v77 = (unsigned __int8)v4->m_numPoints;
    v78 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v76, v76, 85), v5->m_wTa->m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v76, v76, 0), v5->m_wTa->m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v76, v76, 170), v5->m_wTa->m_rotation.m_col2.m_quad));
    LODWORD(v79) = (unsigned __int128)_mm_shuffle_ps(
                                        (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_contactNormalAngularCosTolerance),
                                        (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_contactNormalAngularCosTolerance),
                                        0);
    if ( v77 > 0 )
    {
      v81 = v4;
      v80 = (signed __int64)((unsigned __int128)((_QWORD)((char *)v5->m_result->m_firstFreeContactPoint.m_storage
                                                        - (char *)v5->m_result
                                                        - 16)
                                               * (signed __int128)3074457345618258603i64) >> 64) >> 3;
      v82 = (signed int)(v80 + (v80 >> 63) - v77);
      do
      {
        v83 = v5->m_result;
        v84 = _mm_mul_ps(v83->m_contactPoints[v82].m_contact.m_separatingNormal.m_quad, v78);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 170))) >= v79 )
        {
          ++v3;
          v81 = (hkpBoxBoxManifold *)((char *)v81 + 4);
          ++v82;
        }
        else
        {
          v85 = v83->m_firstFreeContactPoint.m_storage;
          v83->m_contactPoints[v82].m_contact.m_position = v83->m_firstFreeContactPoint.m_storage[-1].m_contact.m_position;
          v83->m_contactPoints[v82].m_contact.m_separatingNormal = v85[-1].m_contact.m_separatingNormal;
          v83->m_contactPoints[v82].m_contactPointId = v85[-1].m_contactPointId;
          v83->m_contactPoints[v82].m_padding[0] = v85[-1].m_padding[0];
          v83->m_contactPoints[v82].m_padding[1] = v85[-1].m_padding[1];
          v83->m_contactPoints[v82].m_padding[2] = v85[-1].m_padding[2];
          if ( v81->m_contactPoints[0].m_featureIdA <= 6u )
            --v4->m_faceVertexFeatureCount;
          ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
            v5->m_contactMgr,
            v81->m_contactPoints[0].m_contactPointId,
            v5->m_result->m_constraintOwner.m_storage);
          hkpBoxBoxManifold::removePoint(v4, v3);
          --v5->m_result->m_firstFreeContactPoint.m_storage;
        }
      }
      while ( v3 < (unsigned __int8)v4->m_numPoints );
      v72 = result.m_enum;
      v70 = v250;
    }
    if ( v4->m_numPoints < 2u )
    {
      _mm_store_si128(
        (__m128i *)&v4->m_manifoldNormalA,
        _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&v4->m_manifoldNormalA), 4), 4));
      goto LABEL_58;
    }
    v86 = v4->m_manifoldNormalA.m_quad;
    v87 = v5->m_aTb.m_rotation.m_col2.m_quad;
    v88 = _mm_unpacklo_ps(v5->m_aTb.m_rotation.m_col0.m_quad, v5->m_aTb.m_rotation.m_col1.m_quad);
    v89 = _mm_movelh_ps(v88, v87);
    qin.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v89, v88), v87, 212), _mm_shuffle_ps(v86, v86, 85)),
                     _mm_mul_ps(_mm_shuffle_ps(v4->m_manifoldNormalA.m_quad, v86, 0), v89)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(
                       _mm_unpackhi_ps(v5->m_aTb.m_rotation.m_col0.m_quad, v5->m_aTb.m_rotation.m_col1.m_quad),
                       v87,
                       228),
                     _mm_shuffle_ps(v86, v86, 170)));
    v4->m_manifoldNormalB = hkVector4UtilImpl<float>::packQuaternionIntoInt32(&qin);
    v4->m_manifoldNormalA.m_quad = _mm_shuffle_ps(
                                     v4->m_manifoldNormalA.m_quad,
                                     _mm_unpackhi_ps(v4->m_manifoldNormalA.m_quad, g_vectorfConstants[0]),
                                     196);
    goto LABEL_57;
  }
LABEL_58:
  if ( v70 != 2 )
    return;
  v90.m_quad = (__m128)fpp.m_vB;
  v91.m_quad = (__m128)fpp.m_vA;
  if ( v72 > 6u )
    goto LABEL_68;
  if ( v72 > 2u )
  {
    v92 = &v5->m_wTa->m_rotation.m_col0.m_quad;
    v93 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 85);
    v94 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 0);
    v95 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 170);
  }
  else
  {
    v92 = &v5->m_wTb->m_rotation.m_col0.m_quad;
    v93 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 85);
    v94 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 0);
    v95 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 170);
  }
  v96 = (unsigned __int8)v4->m_numPoints;
  v97 = 0;
  LODWORD(v98) = (unsigned __int128)_mm_shuffle_ps(v5->m_tolerance4.m_quad, v5->m_tolerance4.m_quad, 0);
  v99 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v93, v92[1]), _mm_mul_ps(v94, *v92)), _mm_mul_ps(v95, v92[2])),
          v92[3]);
  v100 = (float)(v98 * v98) + 0.00000011920929;
  if ( v96 <= 0 )
  {
LABEL_68:
    if ( v4->m_numPoints >= 8u )
      return;
    v105 = hkpBoxBoxManifold::addPoint(v4, v5->m_bodyA, v5->m_bodyB, (hkpFeatureContactPoint *)&result);
    v106 = v105;
    if ( v105 >= 0 )
    {
      v107 = (__m128 *)v5->m_result->m_firstFreeContactPoint.m_storage;
      if ( v67 > 2 )
      {
        v110 = _mm_shuffle_ps(v91.m_quad, v91.m_quad, 85);
        v111 = _mm_shuffle_ps(v91.m_quad, v91.m_quad, 0);
        v112 = _mm_shuffle_ps(v91.m_quad, v91.m_quad, 170);
        if ( v67 > 6 )
        {
          v107[2].m128_i32[0] = HIWORD(result.m_enum);
          *v107 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(v110, v5->m_wTa->m_rotation.m_col1.m_quad),
                        _mm_mul_ps(v111, v5->m_wTa->m_rotation.m_col0.m_quad)),
                      _mm_mul_ps(v112, v5->m_wTa->m_rotation.m_col2.m_quad)),
                    v5->m_wTa->m_translation.m_quad);
          v115 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v69.m_quad, v69.m_quad, 85), v5->m_wTa->m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v69.m_quad, v69.m_quad, 0), v5->m_wTa->m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v69.m_quad, v69.m_quad, 170), v5->m_wTa->m_rotation.m_col2.m_quad));
          v107[1] = _mm_shuffle_ps(v115, _mm_unpackhi_ps(v115, fpp.m_distance.m_real), 196);
        }
        else
        {
          v113 = LOBYTE(result.m_enum);
          v107[2].m128_i32[0] = HIWORD(result.m_enum);
          *v107 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(v110, v5->m_wTa->m_rotation.m_col1.m_quad),
                        _mm_mul_ps(v111, v5->m_wTa->m_rotation.m_col0.m_quad)),
                      _mm_mul_ps(v112, v5->m_wTa->m_rotation.m_col2.m_quad)),
                    v5->m_wTa->m_translation.m_quad);
          v114 = _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(_mm_cmpeq_epi32((__m128i)v68.m_mask, (__m128i)0i64), 0x1Fu),
                             0x1Fu),
                   *(&v5->m_wTb->m_rotation.m_col0.m_quad + v113 - 4));
          v107[1] = _mm_shuffle_ps(v114, _mm_unpackhi_ps(v114, fpp.m_distance.m_real), 196);
        }
      }
      else
      {
        v108 = LOBYTE(result.m_enum);
        v107[2].m128_i32[0] = HIWORD(result.m_enum);
        *v107 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v90.m_quad, v90.m_quad, 85), v5->m_wTb->m_rotation.m_col1.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v90.m_quad, v90.m_quad, 0), v5->m_wTb->m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v90.m_quad, v90.m_quad, 170), v5->m_wTb->m_rotation.m_col2.m_quad)),
                  v5->m_wTb->m_translation.m_quad);
        v109 = _mm_xor_ps(
                 (__m128)_mm_slli_epi32(
                           _mm_srli_epi32(_mm_cmpeq_epi32((__m128i)v68.m_mask, (__m128i)0i64), 0x1Fu),
                           0x1Fu),
                 *(&v5->m_wTa->m_rotation.m_col0.m_quad + v108));
        v107[1] = _mm_shuffle_ps(v109, _mm_unpackhi_ps(v109, fpp.m_distance.m_real), 196);
      }
      if ( v4->m_numPoints > 1u )
      {
        v116 = _mm_mul_ps(
                 v5->m_result->m_firstFreeContactPoint.m_storage[-1].m_contact.m_separatingNormal.m_quad,
                 v107[1]);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v116, v116, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v116, v116, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v116, v116, 170))) <= 0.0 )
        {
          hkpBoxBoxManifold::removePoint(v4, v105);
          return;
        }
      }
      v117 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, __m128 *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
               v5->m_contactMgr,
               v5->m_bodyA,
               v5->m_bodyB,
               v5->m_env,
               v5->m_result,
               0i64,
               v107);
      v4->m_contactPoints[v106].m_contactPointId = v117;
      if ( v117 == -1 )
      {
        hkpBoxBoxManifold::removePoint(v4, v106);
      }
      else
      {
        ++v5->m_result->m_firstFreeContactPoint.m_storage;
        HIWORD(result.m_enum) = v4->m_contactPoints[v106].m_contactPointId;
        v107[2].m128_i32[0] = HIWORD(result.m_enum);
        if ( LOBYTE(result.m_enum) <= 6u )
          ++v4->m_faceVertexFeatureCount;
      }
    }
    fcp = (hkpFeatureContactPoint)result.m_enum;
    v118 = v4->m_numPoints;
    if ( v118 < 1u )
      return;
    v119 = v5->m_result;
    v120 = v118;
    v121 = v5->m_wTa;
    v122 = &v119->m_contactPoints[(signed int)(((signed __int64)((unsigned __int128)((_QWORD)((char *)v119->m_firstFreeContactPoint.m_storage
                                                                                            - (char *)v119
                                                                                            - 16)
                                                                                   * (signed __int128)3074457345618258603i64) >> 64) >> 3)
                                             + ((unsigned __int64)((unsigned __int128)((_QWORD)((char *)v119->m_firstFreeContactPoint.m_storage
                                                                                              - (char *)v119
                                                                                              - 16)
                                                                                     * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                             - v118)].m_contact.m_separatingNormal.m_quad;
    v123 = v121->m_rotation.m_col2.m_quad;
    v124 = *v122;
    v125 = _mm_unpacklo_ps(v121->m_rotation.m_col0.m_quad, v121->m_rotation.m_col1.m_quad);
    v126 = _mm_shuffle_ps(_mm_unpackhi_ps(v121->m_rotation.m_col0.m_quad, v121->m_rotation.m_col1.m_quad), v123, 228);
    v127 = v5->m_wTb;
    v128 = v127->m_rotation.m_col2.m_quad;
    v129 = _mm_shuffle_ps(v124, v124, 85);
    v130 = _mm_shuffle_ps(*v122, *v122, 0);
    v131 = _mm_shuffle_ps(v124, v124, 170);
    v132 = _mm_movelh_ps(v125, v123);
    v133 = _mm_unpacklo_ps(v127->m_rotation.m_col0.m_quad, v127->m_rotation.m_col1.m_quad);
    v134 = _mm_movelh_ps(v133, v128);
    v135 = (__m128i)_mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v134, v133), v128, 212), v129),
                        _mm_mul_ps(v134, v130)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          _mm_unpackhi_ps(v127->m_rotation.m_col0.m_quad, v127->m_rotation.m_col1.m_quad),
                          v128,
                          228),
                        v131));
    v136 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v135, 1u), 1u);
    v137 = (__m128i)_mm_xor_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v132, v125), v123, 212), v129),
                          _mm_mul_ps(v132, v130)),
                        _mm_mul_ps(v126, v131)),
                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v138 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v137, 1u), 1u);
    LODWORD(v127) = _mm_movemask_ps(
                      _mm_and_ps(
                        _mm_cmpleps(
                          _mm_max_ps(
                            _mm_shuffle_ps(v138, v138, 170),
                            _mm_max_ps(_mm_shuffle_ps(v138, v138, 85), _mm_shuffle_ps(v138, v138, 0))),
                          v138),
                        (__m128)xmmword_141A86090));
    v139 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[(signed int)v127];
    LODWORD(v140) = (unsigned __int128)_mm_shuffle_ps(
                                         (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_coplanerAngularCosTolerance),
                                         (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_coplanerAngularCosTolerance),
                                         0);
    planeMaskA = 16 * (1 << hkVector4Comparison_maskToLastIndex[(signed int)v127]);
    LODWORD(v127) = _mm_movemask_ps(
                      _mm_and_ps(
                        _mm_cmpleps(
                          _mm_max_ps(
                            _mm_shuffle_ps(v136, v136, 170),
                            _mm_max_ps(_mm_shuffle_ps(v136, v136, 85), _mm_shuffle_ps(v136, v136, 0))),
                          v136),
                        (__m128)xmmword_141A86090));
    v141 = hkVector4Comparison_maskToLastIndex[(signed int)v127];
    v142 = 0;
    v143 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v139];
    LODWORD(v144) = 16 * (1 << hkVector4Comparison_maskToLastIndex[(signed int)v127]);
    v145 = _mm_and_ps(v138, v143);
    planeMaskB = 16 * (1 << hkVector4Comparison_maskToLastIndex[(signed int)v127]);
    v146 = _mm_or_ps(_mm_shuffle_ps(v145, v145, 78), v145);
    v147 = (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)hkVector4Comparison_maskToLastIndex[(signed int)v127]];
    v148 = 0;
    v149 = _mm_and_ps(v136, v147);
    v150 = _mm_or_ps(_mm_shuffle_ps(v149, v149, 78), v149);
    LODWORD(v151) = *(unsigned __int128 *)&_mm_shuffle_ps(v146, v146, 177) | v146.m128_i32[0];
    if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v150, v150, 177) | v150.m128_i32[0]) < v140 )
      v142 = 1;
    if ( v151 < v140 )
      v148 = 1;
    if ( v148 | v142 )
      return;
    v152 = _mm_and_ps(v147, v5->m_dinB.m_quad);
    v245.m_contactPointId = 0;
    v153 = _mm_and_ps(v5->m_dinA.m_quad, v143);
    v154 = 16 * (_mm_movemask_ps(_mm_cmpltps((__m128)v135, (__m128)0i64)) & 7);
    v250 = (hkpFeatureContactPoint)v154;
    v155 = _mm_or_ps(_mm_shuffle_ps(v153, v153, 78), v153);
    v156 = _mm_or_ps(_mm_shuffle_ps(v152, v152, 78), v152);
    v157 = _mm_cmpltps(_mm_or_ps(_mm_shuffle_ps(v156, v156, 177), v156), (__m128)0i64);
    if ( _mm_movemask_ps(_mm_cmpltps(_mm_or_ps(_mm_shuffle_ps(v155, v155, 177), v155), (__m128)0i64)) )
    {
      v154 |= 8u;
      v250 = (hkpFeatureContactPoint)v154;
    }
    fcp.m_featureIdB = v154;
    v158 = 16 * (_mm_movemask_ps(_mm_cmpltps((__m128)v137, (__m128)0i64)) & 7);
    v246 = v158;
    if ( _mm_movemask_ps(v157) )
    {
      LOBYTE(v158) = v158 | 8;
      v246 = v158;
    }
    v159 = query.m_quad;
    v245.m_featureIdB = v158;
    fcp.m_featureIdA = v139;
    v245.m_featureIdA = v141 + 4;
    if ( (signed int)v120 > 0 )
    {
      v160 = v120;
      do
      {
        v161 = *v122;
        v122 += 3;
        v159 = _mm_min_ps(v159, _mm_shuffle_ps(v161, v161, 255));
        --v160;
      }
      while ( v160 );
    }
    v162 = fcp;
    v163 = cycleMask;
    while ( 1 )
    {
      v164 = *v163;
      if ( !((unsigned __int16)v144 & *v163) )
      {
        v165 = (unsigned __int8)v4->m_numPoints;
        fcp = v162;
        v166 = v164 ^ v154 | v162.m_featureIdB & 0xF;
        fcp.m_featureIdB = v164 ^ v154 | v162.m_featureIdB & 0xF;
        v167 = v165 - 1;
        if ( v165 - 1 < 0 )
        {
LABEL_101:
          if ( v166 & 8 )
            v168 = (__m128i)xmmword_141A86110;
          else
            v168 = 0i64;
          v169 = _mm_mul_ps(
                   _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 *(__m128i *)&hkVector4fComparison_maskToComparison_373[4
                                                                                      * (((unsigned int)v166 >> 4) & 7)],
                                 0x1Fu),
                               0x1Fu),
                     query.m_quad),
                   v5->m_radiusB.m_quad);
          v170 = _mm_shuffle_ps(v169, v169, 85);
          v171 = _mm_shuffle_ps(v169, v169, 0);
          v172 = _mm_shuffle_ps(v169, v169, 170);
          v173 = (__m128i)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(v171, v5->m_aTb.m_rotation.m_col0.m_quad),
                                _mm_mul_ps(v170, v5->m_aTb.m_rotation.m_col1.m_quad)),
                              _mm_mul_ps(v5->m_aTb.m_rotation.m_col2.m_quad, v172)),
                            v5->m_aTb.m_translation.m_quad);
          if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32(v173, 1u), 1u), v5->m_keepRadiusA.m_quad)) & 7) != 7 )
            goto LABEL_139;
          v174 = _mm_and_ps(
                   _mm_sub_ps(
                     _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v168, 0x1Fu), 0x1Fu), (__m128)v173),
                     v5->m_radiusA.m_quad),
                   (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)v162.m_featureIdA]);
          v175 = _mm_or_ps(_mm_shuffle_ps(v174, v174, 78), v174);
          v176 = _mm_or_ps(_mm_shuffle_ps(v175, v175, 177), v175);
          if ( v176.m128_f32[0] < (float)(v159.m128_f32[0] - 0.00000011920929) )
            goto LABEL_139;
          if ( v162.m_featureIdA <= 6u )
          {
            if ( v162.m_featureIdA > 2u )
            {
              v177 = &v5->m_wTa->m_rotation.m_col0.m_quad;
              v179 = _mm_mul_ps(_mm_shuffle_ps((__m128)v173, (__m128)v173, 85), v177[1]);
              v180 = _mm_mul_ps(_mm_shuffle_ps((__m128)v173, (__m128)v173, 170), v177[2]);
              v178 = _mm_shuffle_ps((__m128)v173, (__m128)v173, 0);
            }
            else
            {
              v177 = &v5->m_wTb->m_rotation.m_col0.m_quad;
              v178 = v171;
              v179 = _mm_mul_ps(v177[1], v170);
              v180 = _mm_mul_ps(v177[2], v172);
            }
            v181 = 0;
            LODWORD(v182) = (unsigned __int128)_mm_shuffle_ps(v5->m_tolerance4.m_quad, v5->m_tolerance4.m_quad, 0);
            v183 = _mm_add_ps(_mm_add_ps(_mm_add_ps(v179, _mm_mul_ps(v178, *v177)), v180), v177[3]);
            v184 = (float)(v182 * v182) + 0.00000011920929;
            if ( v165 > 0 )
            {
              v185 = 0i64;
              v186 = v4;
              while ( 1 )
              {
                if ( v186->m_contactPoints[0].m_featureIdA <= 6u )
                {
                  v187 = _mm_sub_ps(v183, v5->m_result->m_contactPoints[v185].m_contact.m_position.m_quad);
                  v188 = _mm_mul_ps(v187, v187);
                  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v188, v188, 85))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v188, v188, 0)))
                             + COERCE_FLOAT(_mm_shuffle_ps(v188, v188, 170))) <= v184 )
                    break;
                }
                ++v181;
                v186 = (hkpBoxBoxManifold *)((char *)v186 + 4);
                ++v185;
                if ( v181 >= v165 )
                  goto LABEL_115;
              }
LABEL_139:
              LOBYTE(v154) = v250.m_featureIdA;
              goto LABEL_126;
            }
          }
LABEL_115:
          if ( (unsigned __int8)v165 >= 8u )
            goto LABEL_139;
          v189 = hkpBoxBoxManifold::addPoint(v4, v5->m_bodyA, v5->m_bodyB, &fcp);
          v190 = v189;
          if ( v189 >= 0 )
          {
            v144 = (__m128 *)v5->m_result->m_firstFreeContactPoint.m_storage;
            if ( (signed int)(unsigned __int8)v162.m_featureIdA > 2 )
            {
              v193 = _mm_shuffle_ps((__m128)v173, (__m128)v173, 85);
              v194 = _mm_shuffle_ps((__m128)v173, (__m128)v173, 0);
              v195 = _mm_shuffle_ps((__m128)v173, (__m128)v173, 170);
              if ( (signed int)(unsigned __int8)v162.m_featureIdA > 6 )
              {
                v144[2].m128_i32[0] = fcp.m_contactPointId;
                *v144 = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(v193, v5->m_wTa->m_rotation.m_col1.m_quad),
                              _mm_mul_ps(v194, v5->m_wTa->m_rotation.m_col0.m_quad)),
                            _mm_mul_ps(v195, v5->m_wTa->m_rotation.m_col2.m_quad)),
                          v5->m_wTa->m_translation.m_quad);
                v198 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 85),
                             v5->m_wTa->m_rotation.m_col1.m_quad),
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 0),
                             v5->m_wTa->m_rotation.m_col0.m_quad)),
                         _mm_mul_ps(
                           _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 170),
                           v5->m_wTa->m_rotation.m_col2.m_quad));
                v144[1] = _mm_shuffle_ps(v198, _mm_unpackhi_ps(v198, v176), 196);
              }
              else
              {
                v196 = (unsigned __int8)fcp.m_featureIdA;
                v144[2].m128_i32[0] = fcp.m_contactPointId;
                *v144 = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(v193, v5->m_wTa->m_rotation.m_col1.m_quad),
                              _mm_mul_ps(v194, v5->m_wTa->m_rotation.m_col0.m_quad)),
                            _mm_mul_ps(v195, v5->m_wTa->m_rotation.m_col2.m_quad)),
                          v5->m_wTa->m_translation.m_quad);
                v197 = _mm_xor_ps(
                         (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v168, (__m128i)0i64), 0x1Fu), 0x1Fu),
                         *(&v5->m_wTb->m_rotation.m_col0.m_quad + v196 - 4));
                v144[1] = _mm_shuffle_ps(v197, _mm_unpackhi_ps(v197, v176), 196);
              }
            }
            else
            {
              v191 = (unsigned __int8)fcp.m_featureIdA;
              v144[2].m128_i32[0] = fcp.m_contactPointId;
              *v144 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(v5->m_wTb->m_rotation.m_col1.m_quad, v170),
                            _mm_mul_ps(v5->m_wTb->m_rotation.m_col0.m_quad, v171)),
                          _mm_mul_ps(v5->m_wTb->m_rotation.m_col2.m_quad, v172)),
                        v5->m_wTb->m_translation.m_quad);
              v192 = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v168, (__m128i)0i64), 0x1Fu), 0x1Fu),
                       *(&v5->m_wTa->m_rotation.m_col0.m_quad + v191));
              v144[1] = _mm_shuffle_ps(v192, _mm_unpackhi_ps(v192, v176), 196);
            }
            if ( v4->m_numPoints <= 1u
              || (v199 = _mm_mul_ps(
                           v5->m_result->m_firstFreeContactPoint.m_storage[-1].m_contact.m_separatingNormal.m_quad,
                           v144[1]),
                  (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v199, v199, 85))
                                + COERCE_FLOAT(_mm_shuffle_ps(v199, v199, 0)))
                        + COERCE_FLOAT(_mm_shuffle_ps(v199, v199, 170))) > 0.0) )
            {
              v207 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, __m128 *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                       v5->m_contactMgr,
                       v5->m_bodyA,
                       v5->m_bodyB,
                       v5->m_env,
                       v5->m_result,
                       0i64,
                       v144);
              v4->m_contactPoints[v190].m_contactPointId = v207;
              if ( v207 != -1 )
              {
                LOBYTE(v154) = v250.m_featureIdA;
                ++v5->m_result->m_firstFreeContactPoint.m_storage;
                v144[2].m128_i32[0] = v4->m_contactPoints[v190].m_contactPointId;
                LOWORD(v144) = planeMaskB;
                if ( fcp.m_featureIdA <= 6u )
                  ++v4->m_faceVertexFeatureCount;
                goto LABEL_126;
              }
            }
            hkpBoxBoxManifold::removePoint(v4, v190);
            LOWORD(v144) = planeMaskB;
          }
        }
        else
        {
          while ( v4->m_contactPoints[v167].m_featureIdA != v162.m_featureIdA
               || v4->m_contactPoints[v167].m_featureIdB != v166 )
          {
            if ( --v167 < 0 )
              goto LABEL_101;
          }
        }
        LOBYTE(v154) = v250.m_featureIdA;
      }
LABEL_126:
      ++v163;
      if ( (signed __int64)v163 >= (signed __int64)&unk_141A85FFE )
      {
        v200 = planeMaskA;
        v201 = cycleMask;
        while ( 1 )
        {
          v202 = *v201;
          if ( !((unsigned __int16)v200 & *v201) )
            break;
LABEL_167:
          ++v201;
          if ( (signed __int64)v201 >= (signed __int64)&unk_141A85FFE )
          {
            if ( v4->m_faceVertexFeatureCount < 4u )
              hkpBoxBoxCollisionDetection::checkCompleteness(v5, v4, v200, planeMaskB);
            else
              v4->m_isComplete = 1;
            return;
          }
        }
        v203 = (unsigned __int8)v4->m_numPoints;
        v250 = v245;
        v204 = v246 ^ v202 | v245.m_featureIdB & 0xF;
        v250.m_featureIdB = v246 ^ v202 | v245.m_featureIdB & 0xF;
        v205 = v203 - 1;
        if ( v203 - 1 >= 0 )
        {
          while ( v4->m_contactPoints[v205].m_featureIdA != v245.m_featureIdA
               || v4->m_contactPoints[v205].m_featureIdB != v204 )
          {
            if ( --v205 < 0 )
              goto LABEL_133;
          }
          goto LABEL_166;
        }
LABEL_133:
        if ( v204 & 8 )
          v206 = (__m128i)xmmword_141A86110;
        else
          v206 = 0i64;
        v208 = v5->m_aTb.m_rotation.m_col2.m_quad;
        v209 = _mm_unpacklo_ps(v5->m_aTb.m_rotation.m_col0.m_quad, v5->m_aTb.m_rotation.m_col1.m_quad);
        v210 = _mm_movelh_ps(v209, v208);
        v211 = _mm_mul_ps(
                 _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(
                               *(__m128i *)&hkVector4fComparison_maskToComparison_373[4
                                                                                    * (((unsigned int)v204 >> 4) & 7)],
                               0x1Fu),
                             0x1Fu),
                   query.m_quad),
                 v5->m_radiusA.m_quad);
        v212 = _mm_sub_ps(v211, v5->m_aTb.m_translation.m_quad);
        v213 = (__m128i)_mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(_mm_movehl_ps(v210, v209), v208, 212),
                              _mm_shuffle_ps(v212, v212, 85)),
                            _mm_mul_ps(_mm_shuffle_ps(v212, v212, 0), v210)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(v212, v212, 170),
                            _mm_shuffle_ps(
                              _mm_unpackhi_ps(v5->m_aTb.m_rotation.m_col0.m_quad, v5->m_aTb.m_rotation.m_col1.m_quad),
                              v208,
                              228)));
        if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32(v213, 1u), 1u), v5->m_keepRadiusB.m_quad)) & 7) != 7 )
          goto LABEL_166;
        v214 = (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v206, (__m128i)0i64), 0x1Fu), 0x1Fu);
        v215 = _mm_and_ps(
                 _mm_sub_ps(_mm_xor_ps(v214, (__m128)v213), v5->m_radiusB.m_quad),
                 (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)v245.m_featureIdA - 4i64]);
        v216 = _mm_or_ps(_mm_shuffle_ps(v215, v215, 78), v215);
        v217 = _mm_or_ps(_mm_shuffle_ps(v216, v216, 177), v216);
        if ( v217.m128_f32[0] < (float)(v159.m128_f32[0] - 0.00000011920929) )
          goto LABEL_166;
        if ( v245.m_featureIdA <= 6u )
        {
          if ( v245.m_featureIdA > 2u )
          {
            v218 = &v5->m_wTa->m_rotation.m_col0.m_quad;
            v219 = _mm_shuffle_ps(v211, v211, 85);
            v220 = _mm_shuffle_ps(v211, v211, 0);
            v221 = _mm_shuffle_ps(v211, v211, 170);
          }
          else
          {
            v218 = &v5->m_wTb->m_rotation.m_col0.m_quad;
            v219 = _mm_shuffle_ps((__m128)v213, (__m128)v213, 85);
            v220 = _mm_shuffle_ps((__m128)v213, (__m128)v213, 0);
            v221 = _mm_shuffle_ps((__m128)v213, (__m128)v213, 170);
          }
          v222 = 0;
          LODWORD(v223) = (unsigned __int128)_mm_shuffle_ps(v5->m_tolerance4.m_quad, v5->m_tolerance4.m_quad, 0);
          v224 = _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v219, v218[1]), _mm_mul_ps(v220, *v218)), _mm_mul_ps(v221, v218[2])),
                   v218[3]);
          v225 = (float)(v223 * v223) + 0.00000011920929;
          if ( v203 > 0 )
          {
            v226 = 0i64;
            v227 = v4;
            do
            {
              if ( v227->m_contactPoints[0].m_featureIdA <= 6u )
              {
                v228 = _mm_sub_ps(v224, v5->m_result->m_contactPoints[v226].m_contact.m_position.m_quad);
                v229 = _mm_mul_ps(v228, v228);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v229, v229, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v229, v229, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v229, v229, 170))) <= v225 )
                  goto LABEL_166;
              }
              ++v222;
              v227 = (hkpBoxBoxManifold *)((char *)v227 + 4);
              ++v226;
            }
            while ( v222 < v203 );
          }
        }
        if ( (unsigned __int8)v203 >= 8u )
          goto LABEL_166;
        v230 = hkpBoxBoxManifold::addPoint(v4, v5->m_bodyA, v5->m_bodyB, &v250);
        v231 = v230;
        if ( v230 < 0 )
        {
LABEL_166:
          v200 = planeMaskA;
          goto LABEL_167;
        }
        v232 = (__m128 *)v5->m_result->m_firstFreeContactPoint.m_storage;
        if ( (signed int)(unsigned __int8)v245.m_featureIdA <= 2 )
        {
          v233 = (unsigned __int8)v250.m_featureIdA;
          v232[2].m128_i32[0] = v250.m_contactPointId;
          v234 = v233;
          *v232 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v213, (__m128)v213, 85), v5->m_wTb->m_rotation.m_col1.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v213, (__m128)v213, 0), v5->m_wTb->m_rotation.m_col0.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps((__m128)v213, (__m128)v213, 170), v5->m_wTb->m_rotation.m_col2.m_quad)),
                    v5->m_wTb->m_translation.m_quad);
          v235 = v5->m_wTa;
          goto LABEL_158;
        }
        v236 = _mm_shuffle_ps(v211, v211, 85);
        v237 = _mm_shuffle_ps(v211, v211, 0);
        v238 = _mm_shuffle_ps(v211, v211, 170);
        if ( (signed int)(unsigned __int8)v245.m_featureIdA > 6 )
        {
          v232[2].m128_i32[0] = v250.m_contactPointId;
          *v232 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(v236, v5->m_wTa->m_rotation.m_col1.m_quad),
                        _mm_mul_ps(v237, v5->m_wTa->m_rotation.m_col0.m_quad)),
                      _mm_mul_ps(v238, v5->m_wTa->m_rotation.m_col2.m_quad)),
                    v5->m_wTa->m_translation.m_quad);
          v241 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps((__m128)0i64, (__m128)0i64, 85), v5->m_wTa->m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps((__m128)0i64, (__m128)0i64, 0), v5->m_wTa->m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps((__m128)0i64, (__m128)0i64, 170), v5->m_wTa->m_rotation.m_col2.m_quad));
          v232[1] = _mm_shuffle_ps(v241, _mm_unpackhi_ps(v241, v217), 196);
        }
        else
        {
          v239 = (unsigned __int8)v250.m_featureIdA;
          v232[2].m128_i32[0] = v250.m_contactPointId;
          v234 = v239 - 4;
          *v232 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(v236, v5->m_wTa->m_rotation.m_col1.m_quad),
                        _mm_mul_ps(v237, v5->m_wTa->m_rotation.m_col0.m_quad)),
                      _mm_mul_ps(v238, v5->m_wTa->m_rotation.m_col2.m_quad)),
                    v5->m_wTa->m_translation.m_quad);
          v235 = v5->m_wTb;
LABEL_158:
          v240 = _mm_xor_ps(*(&v235->m_rotation.m_col0.m_quad + v234), v214);
          v232[1] = _mm_shuffle_ps(v240, _mm_unpackhi_ps(v240, v217), 196);
        }
        if ( v4->m_numPoints <= 1u
          || (v242 = _mm_mul_ps(
                       v5->m_result->m_firstFreeContactPoint.m_storage[-1].m_contact.m_separatingNormal.m_quad,
                       v232[1]),
              (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v242, v242, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v242, v242, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v242, v242, 170))) > 0.0) )
        {
          v243 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, __m128 *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                   v5->m_contactMgr,
                   v5->m_bodyA,
                   v5->m_bodyB,
                   v5->m_env,
                   v5->m_result,
                   0i64,
                   v232);
          v4->m_contactPoints[v231].m_contactPointId = v243;
          if ( v243 != -1 )
          {
            v200 = planeMaskA;
            ++v5->m_result->m_firstFreeContactPoint.m_storage;
            v232[2].m128_i32[0] = v4->m_contactPoints[v231].m_contactPointId;
            if ( v250.m_featureIdA <= 6u )
              ++v4->m_faceVertexFeatureCount;
            goto LABEL_167;
          }
        }
        hkpBoxBoxManifold::removePoint(v4, v231);
        goto LABEL_166;
      }
    }
  }
  v101 = 0i64;
  v102 = v4;
  while ( 1 )
  {
    if ( v102->m_contactPoints[0].m_featureIdA <= 6u )
    {
      v103 = _mm_sub_ps(v99, v5->m_result->m_contactPoints[v101].m_contact.m_position.m_quad);
      v104 = _mm_mul_ps(v103, v103);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 170))) <= v100 )
        break;
    }
    ++v97;
    v102 = (hkpBoxBoxManifold *)((char *)v102 + 4);
    ++v101;
    if ( v97 >= v96 )
      goto LABEL_68;
  }
}e_function__)(
                   v5->m_contactMgr,
                   v5->m_bodyA,
 

