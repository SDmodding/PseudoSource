// File Line: 45
// RVA: 0xD3A7F0
void __fastcall selectIfGT3(hkVector4f *result, hkSimdFloat32 *selectIf, hkVector4f *greaterV, hkSimdFloat32 *than)
{
  __m128 v4; // xmm1

  v4 = _mm_cmplt_ps(than->m_real, greaterV->m_quad);
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
  if ( (bitSet & 8) != 0 )
    *signMask = (hkVector4fComparison)xmmword_141A86110;
  else
    *signMask = 0i64;
}

// File Line: 74
// RVA: 0xD3A870
void __fastcall setEdgeFeatureBitSetFromAxisMap(
        hkVector4f *axisMapAp,
        hkVector4f *axisMapBp,
        int featureIndexA,
        int featureIndexB,
        hkpFeatureContactPoint *fcp)
{
  __m128 m_quad; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm3

  m_quad = axisMapAp->m_quad;
  v6 = axisMapBp->m_quad;
  switch ( featureIndexA )
  {
    case 1:
      v7 = _mm_shuffle_ps(_mm_unpacklo_ps(m_quad, (__m128)0i64), m_quad, 228);
      break;
    case 2:
      v7 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 180);
      break;
    case 3:
      v7 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)m_quad, 4), 4);
      break;
    default:
      v7 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)m_quad, 4), 4);
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
  fcp->m_featureIdA = featureIndexA | (16 * (_mm_movemask_ps(_mm_cmplt_ps(v7, (__m128)0i64)) | 0xF8));
  fcp->m_featureIdB = featureIndexB + (~(16 * _mm_movemask_ps(_mm_cmplt_ps(v8, (__m128)0i64))) & 0x70);
}

// File Line: 91
// RVA: 0xD3A940
__int64 __fastcall calcFaceFeatureBitSetFromAxisMap(hkVector4f *axisMap, hkVector4fComparison *normalSign)
{
  __int64 result; // rax

  result = 16 * (_mm_movemask_ps(_mm_cmplt_ps(axisMap->m_quad, (__m128)0i64)) & 7u);
  if ( _mm_movemask_ps(normalSign->m_mask) )
    return (unsigned int)result | 8;
  return result;
}

// File Line: 99
// RVA: 0xD3A970
void __fastcall setTerminalsFromVertex(int *bitSetEdgeTerminals, int bitSet, int planeAxis)
{
  bool v5; // bl
  bool v6; // r10
  bool v7; // r11
  int v8; // r8d
  int v9; // ecx
  int v10; // r8d
  int v11; // edx

  v5 = ((bitSet >> 4) & 1) == 0;
  v6 = ((bitSet >> 4) & 4) == 0;
  v7 = ((bitSet >> 4) & 2) == 0;
  if ( planeAxis )
  {
    v8 = 1 << (2 * (v7 + 2 * v6));
    v9 = *bitSetEdgeTerminals;
    if ( ((2 * v8) & v9) == 0 )
      *bitSetEdgeTerminals = v9 + v8;
  }
  if ( planeAxis != 1 )
  {
    v10 = 1 << (2 * (v5 + 2 * (v6 + 2)));
    if ( ((2 * v10) & *bitSetEdgeTerminals) == 0 )
      *bitSetEdgeTerminals += v10;
  }
  if ( planeAxis != 2 )
  {
    v11 = 1 << (2 * (v5 + 8 + 2 * v7));
    if ( ((2 * v11) & *bitSetEdgeTerminals) == 0 )
      *bitSetEdgeTerminals += v11;
  }
}

// File Line: 143
// RVA: 0xD3AA30
void __fastcall setTerminalsFromEdge(int *bitSetEdgeTerminals, int bitSet)
{
  char v2; // r9
  int v4; // eax
  bool v5; // cl
  bool v6; // dl
  bool v7; // al
  int v8; // r9d
  char v9; // al
  int v10; // edx

  v2 = bitSet;
  v4 = bitSet >> 4;
  v5 = ((bitSet >> 4) & 1) == 0;
  v6 = ((bitSet >> 4) & 4) == 0;
  v7 = (v4 & 2) == 0;
  v8 = v2 & 0xF;
  if ( v8 )
  {
    if ( v8 == 1 )
      v9 = v5 + 2 * (v6 + 2);
    else
      v9 = v5 + 8 + 2 * v7;
  }
  else
  {
    v9 = v7 + 2 * v6;
  }
  v10 = 1 << (2 * v9);
  if ( ((2 * v10) & *bitSetEdgeTerminals) == 0 )
    *bitSetEdgeTerminals += v10;
}

// File Line: 188
// RVA: 0xD3A550
void __fastcall hkpBoxBoxCollisionDetection::checkCompleteness(
        hkpBoxBoxCollisionDetection *this,
        hkpBoxBoxManifold *manifold,
        int planeMaskA,
        int planeMaskB)
{
  unsigned __int8 m_numPoints; // r10
  __int64 v6; // rsi
  int v7; // eax
  __int64 v8; // rdi
  int v9; // r8d
  __int64 v10; // rbp
  hkpBoxBoxManifold *v11; // rbx
  unsigned __int8 m_featureIdA; // cl
  bool v13; // r11
  bool v14; // dl
  bool v15; // r10
  int v16; // r9d
  int v17; // edx
  char v18; // cl
  bool v19; // r11
  bool v20; // dl
  bool v21; // r10
  int v22; // r9d
  int v23; // edx
  int v24; // edx
  int v25; // edx
  bool v26; // r9
  bool v27; // cl
  bool v28; // dl
  char v29; // cl
  int v30; // edx
  int v31; // edx
  bool v32; // r9
  bool v33; // cl
  bool v34; // dl
  int v35; // edx

  m_numPoints = manifold->m_numPoints;
  if ( m_numPoints < 3u )
    return;
  if ( manifold->m_faceVertexFeatureCount >= 4u )
  {
    manifold->m_isComplete = 1;
    return;
  }
  v6 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[(__int64)planeMaskA >> 4];
  v7 = 0;
  v8 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[(__int64)planeMaskB >> 4];
  v9 = 0;
  v10 = m_numPoints;
  v11 = manifold;
  do
  {
    m_featureIdA = v11->m_contactPoints[0].m_featureIdA;
    if ( v11->m_contactPoints[0].m_featureIdA > 2u )
    {
      if ( m_featureIdA > 6u )
      {
        v25 = (int)m_featureIdA >> 4;
        v26 = (v25 & 1) == 0;
        v27 = (v25 & 4) == 0;
        v28 = (v25 & 2) == 0;
        if ( (v11->m_contactPoints[0].m_featureIdA & 0xF) != 0 )
        {
          if ( (v11->m_contactPoints[0].m_featureIdA & 0xF) == 1 )
            v29 = v26 + 2 * (v27 + 2);
          else
            v29 = v26 + 2 * (v28 + 4);
        }
        else
        {
          v29 = v28 + 2 * v27;
        }
        v30 = 1 << (2 * v29);
        if ( ((2 * v30) & v7) == 0 )
          v7 += v30;
        v31 = (int)(unsigned __int8)v11->m_contactPoints[0].m_featureIdB >> 4;
        v32 = (v31 & 1) == 0;
        v33 = (v31 & 4) == 0;
        v34 = (v31 & 2) == 0;
        if ( (v11->m_contactPoints[0].m_featureIdB & 0xF) != 0 )
        {
          if ( (v11->m_contactPoints[0].m_featureIdB & 0xF) == 1 )
            v18 = v32 + 2 * (v33 + 2);
          else
            v18 = v32 + 2 * (v34 + 4);
        }
        else
        {
          v18 = v34 + 2 * v33;
        }
        goto LABEL_36;
      }
      v19 = (v11->m_contactPoints[0].m_featureIdB & 0x10) == 0;
      v20 = (v11->m_contactPoints[0].m_featureIdB & 0x40) == 0;
      v21 = (v11->m_contactPoints[0].m_featureIdB & 0x20) == 0;
      if ( v6 )
      {
        v22 = 1 << (2 * (v21 + 2 * v20));
        if ( ((2 * v22) & v7) == 0 )
          v7 += v22;
      }
      if ( v6 != 1 )
      {
        v23 = 1 << (2 * (v19 + 2 * (v20 + 2)));
        if ( ((2 * v23) & v7) == 0 )
          v7 += v23;
      }
      if ( v6 != 2 )
      {
        v24 = 1 << (2 * (v19 + 2 * (v21 + 4)));
        if ( ((2 * v24) & v7) == 0 )
          v7 += v24;
      }
    }
    else
    {
      v13 = (v11->m_contactPoints[0].m_featureIdB & 0x10) == 0;
      v14 = (v11->m_contactPoints[0].m_featureIdB & 0x40) == 0;
      v15 = (v11->m_contactPoints[0].m_featureIdB & 0x20) == 0;
      if ( v8 )
      {
        v16 = 1 << (2 * (v15 + 2 * v14));
        if ( ((2 * v16) & v9) == 0 )
          v9 += v16;
      }
      if ( v8 != 1 )
      {
        v17 = 1 << (2 * (v13 + 2 * (v14 + 2)));
        if ( ((2 * v17) & v9) == 0 )
          v9 += v17;
      }
      if ( v8 != 2 )
      {
        v18 = v13 + 2 * (v15 + 4);
LABEL_36:
        v35 = 1 << (2 * v18);
        if ( ((2 * v35) & v9) == 0 )
          v9 += v35;
      }
    }
    v11 = (hkpBoxBoxManifold *)((char *)v11 + 4);
    --v10;
  }
  while ( v10 );
  manifold->m_isComplete = (v7 & 0x555555) == 0 && (v9 & 0x555555) == 0;
}

// File Line: 453
// RVA: 0xD3AAA0
__int64 __fastcall getMaxPlaneMask3(hkVector4f *vAbs, int *axisOut)
{
  int v2; // ecx

  v2 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                              _mm_and_ps(
                                                                _mm_cmple_ps(
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
void __fastcall hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(
        hkpBoxBoxCollisionDetection *this,
        hkpBoxBoxManifold *manifold,
        hkpFeatureContactPoint *fcp,
        hkSimdFloat32 *closestPointDist)
{
  int v6; // eax
  __int64 v9; // rdx
  int m_featureIdB; // eax
  hkSimdFloat32 v11; // xmm9
  hkVector4f v12; // xmm6
  hkVector4f v13; // xmm7
  hkTransformf *m_wTa; // rax
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  int v18; // edx
  float v19; // xmm4_4
  __m128 v20; // xmm3
  float v21; // xmm4_4
  __int64 v22; // r8
  hkpBoxBoxManifold *v23; // rcx
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  int v26; // eax
  __int64 v27; // r14
  hkpProcessCdPoint *m_storage; // rbp
  unsigned int v29; // edx
  __int64 v30; // rcx
  hkTransformf *m_wTb; // rax
  unsigned int m_contactPointId; // eax
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm6
  int m_featureIdA; // ecx
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  unsigned __int16 v40; // ax
  hkpBoxBoxCollisionDetection::hkpFeaturePointCache fpp; // [rsp+40h] [rbp-B8h] BYREF

  v6 = (unsigned __int8)manifold->m_numPoints - 1;
  v9 = v6;
  if ( v6 < 0 )
  {
LABEL_5:
    fpp.m_featureIndexA = (unsigned __int8)fcp->m_featureIdA;
    m_featureIdB = (unsigned __int8)fcp->m_featureIdB;
    memset(&fpp, 0, 32);
    fpp.m_normalIsFlipped = 0i64;
    fpp.m_featureIndexB = m_featureIdB;
    if ( !hkpBoxBoxCollisionDetection::isValidEdgeEdge(this, &fpp) )
      return;
    v11.m_real = (__m128)fpp.m_distance;
    if ( fpp.m_distance.m_real.m128_f32[0] < (float)(_mm_shuffle_ps(
                                                       (__m128)LODWORD(FLOAT_0_99900001),
                                                       (__m128)LODWORD(FLOAT_0_99900001),
                                                       0).m128_f32[0]
                                                   * closestPointDist->m_real.m128_f32[0]) )
      return;
    v12.m_quad = (__m128)fpp.m_vA;
    v13.m_quad = (__m128)fpp.m_vB;
    if ( fcp->m_featureIdA <= 6u )
    {
      if ( fcp->m_featureIdA > 2u )
      {
        m_wTa = this->m_wTa;
        v15 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 85);
        v16 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 0);
        v17 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 170);
      }
      else
      {
        m_wTa = this->m_wTb;
        v15 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 85);
        v16 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 0);
        v17 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 170);
      }
      v18 = 0;
      v19 = _mm_shuffle_ps(this->m_tolerance4.m_quad, this->m_tolerance4.m_quad, 0).m128_f32[0];
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v15, m_wTa->m_rotation.m_col1.m_quad),
                  _mm_mul_ps(v16, m_wTa->m_rotation.m_col0.m_quad)),
                _mm_mul_ps(v17, m_wTa->m_rotation.m_col2.m_quad)),
              m_wTa->m_translation.m_quad);
      v21 = (float)(v19 * v19) + 0.00000011920929;
      if ( manifold->m_numPoints )
      {
        v22 = 0i64;
        v23 = manifold;
        do
        {
          if ( v23->m_contactPoints[0].m_featureIdA <= 6u )
          {
            v24 = _mm_sub_ps(v20, this->m_result->m_contactPoints[v22].m_contact.m_position.m_quad);
            v25 = _mm_mul_ps(v24, v24);
            if ( (float)((float)(_mm_shuffle_ps(v25, v25, 85).m128_f32[0] + _mm_shuffle_ps(v25, v25, 0).m128_f32[0])
                       + _mm_shuffle_ps(v25, v25, 170).m128_f32[0]) <= v21 )
              return;
          }
          ++v18;
          v23 = (hkpBoxBoxManifold *)((char *)v23 + 4);
          ++v22;
        }
        while ( v18 < (unsigned __int8)manifold->m_numPoints );
      }
    }
    if ( manifold->m_numPoints >= 8u )
      return;
    v26 = hkpBoxBoxManifold::addPoint(manifold, this->m_bodyA, this->m_bodyB, fcp);
    v27 = v26;
    if ( v26 < 0 )
      return;
    m_storage = this->m_result->m_firstFreeContactPoint.m_storage;
    if ( fpp.m_featureIndexA > 2 )
    {
      m_contactPointId = fcp->m_contactPointId;
      v33 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 85);
      v34 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 0);
      v35 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 170);
      if ( fpp.m_featureIndexA > 6 )
      {
        m_storage->m_contactPointId = m_contactPointId;
        m_storage->m_contact.m_position.m_quad = _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_mul_ps(v33, this->m_wTa->m_rotation.m_col1.m_quad),
                                                       _mm_mul_ps(v34, this->m_wTa->m_rotation.m_col0.m_quad)),
                                                     _mm_mul_ps(v35, this->m_wTa->m_rotation.m_col2.m_quad)),
                                                   this->m_wTa->m_translation.m_quad);
        v38 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 85),
                    this->m_wTa->m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 0), this->m_wTa->m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 170), this->m_wTa->m_rotation.m_col2.m_quad));
        m_storage->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, v11.m_real), 196);
LABEL_24:
        if ( manifold->m_numPoints > 1u
          && (v39 = _mm_mul_ps(
                      this->m_result->m_firstFreeContactPoint.m_storage[-1].m_contact.m_separatingNormal.m_quad,
                      m_storage->m_contact.m_separatingNormal.m_quad),
              (float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0])
                    + _mm_shuffle_ps(v39, v39, 170).m128_f32[0]) <= 0.0)
          || (v40 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                      this->m_contactMgr,
                      this->m_bodyA,
                      this->m_bodyB,
                      this->m_env,
                      this->m_result,
                      0i64,
                      m_storage),
              manifold->m_contactPoints[v27].m_contactPointId = v40,
              v40 == 0xFFFF) )
        {
          hkpBoxBoxManifold::removePoint(manifold, v27);
        }
        else
        {
          ++this->m_result->m_firstFreeContactPoint.m_storage;
          fcp->m_contactPointId = manifold->m_contactPoints[v27].m_contactPointId;
          m_storage->m_contactPointId = manifold->m_contactPoints[v27].m_contactPointId;
          if ( fcp->m_featureIdA <= 6u )
            ++manifold->m_faceVertexFeatureCount;
        }
        return;
      }
      m_featureIdA = (unsigned __int8)fcp->m_featureIdA;
      m_storage->m_contactPointId = m_contactPointId;
      v30 = m_featureIdA - 4;
      m_storage->m_contact.m_position.m_quad = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(v33, this->m_wTa->m_rotation.m_col1.m_quad),
                                                     _mm_mul_ps(v34, this->m_wTa->m_rotation.m_col0.m_quad)),
                                                   _mm_mul_ps(v35, this->m_wTa->m_rotation.m_col2.m_quad)),
                                                 this->m_wTa->m_translation.m_quad);
      m_wTb = this->m_wTb;
    }
    else
    {
      v29 = (unsigned __int8)fcp->m_featureIdA;
      m_storage->m_contactPointId = fcp->m_contactPointId;
      v30 = v29;
      m_storage->m_contact.m_position.m_quad = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps(v13.m_quad, v13.m_quad, 85),
                                                       this->m_wTb->m_rotation.m_col1.m_quad),
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps(v13.m_quad, v13.m_quad, 0),
                                                       this->m_wTb->m_rotation.m_col0.m_quad)),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(v13.m_quad, v13.m_quad, 170),
                                                     this->m_wTb->m_rotation.m_col2.m_quad)),
                                                 this->m_wTb->m_translation.m_quad);
      m_wTb = this->m_wTa;
    }
    v37 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        _mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&fpp.m_normalIsFlipped), (__m128i)0i64),
                        0x1Fu),
                      0x1Fu),
            *(&m_wTb->m_rotation.m_col0.m_quad + v30));
    m_storage->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v37, _mm_unpackhi_ps(v37, v11.m_real), 196);
    goto LABEL_24;
  }
  while ( manifold->m_contactPoints[v9].m_featureIdA != fcp->m_featureIdA
       || manifold->m_contactPoints[v9].m_featureIdB != fcp->m_featureIdB )
  {
    if ( --v9 < 0 )
      goto LABEL_5;
  }
}

// File Line: 605
// RVA: 0xD39BA0
void __fastcall hkpBoxBoxCollisionDetection::tryToAddPointOnEdge(
        hkpBoxBoxCollisionDetection *this,
        hkpBoxBoxManifold *manifold,
        int edgeA,
        int edgeB,
        char nextVertA,
        char nextVertB,
        hkVector4f *normalA,
        hkVector4f *normalB,
        hkSimdFloat32 *closestPointDist)
{
  __m128 m_quad; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  hkSimdFloat32 *v15; // rsi
  int v16; // edi
  hkpFeatureContactPoint fcp; // [rsp+50h] [rbp+18h] BYREF

  fcp.m_contactPointId = 0;
  m_quad = normalA->m_quad;
  v12 = normalB->m_quad;
  switch ( edgeA )
  {
    case 1:
      v13 = _mm_shuffle_ps(_mm_unpacklo_ps(m_quad, (__m128)0i64), m_quad, 228);
      break;
    case 2:
      v13 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 180);
      break;
    case 3:
      v13 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)m_quad, 4), 4);
      break;
    default:
      v13 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)m_quad, 4), 4);
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
  fcp.m_featureIdA = edgeA | (16 * (_mm_movemask_ps(_mm_cmplt_ps(v13, (__m128)0i64)) | 0xF8));
  fcp.m_featureIdB = edgeB + (~(16 * _mm_movemask_ps(_mm_cmplt_ps(v14, (__m128)0i64))) & 0x70);
  hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(this, manifold, &fcp, closestPointDist);
  v16 = 1 << (nextVertA + 4);
  fcp.m_featureIdA ^= v16;
  hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(this, manifold, &fcp, v15);
  fcp.m_featureIdB ^= 1 << (nextVertB + 4);
  hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(this, manifold, &fcp, v15);
  fcp.m_featureIdA ^= v16;
  hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper(this, manifold, &fcp, v15);
}

// File Line: 752
// RVA: 0xD38DC0
hkResult *__fastcall hkpBoxBoxCollisionDetection::checkIntersection(
        hkpBoxBoxCollisionDetection *this,
        hkResult *result,
        hkVector4f *tolerance)
{
  __m128 v3; // xmm5
  __m128i si128; // xmm6
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
  __m128 v30; // xmm11
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm11
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  hkVector4f v40; // xmm11
  __m128 v41; // xmm2
  __m128 v42; // xmm8
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  hkVector4f v46; // xmm1
  __m128 v47; // xmm9
  __m128 v48; // xmm0
  __m128 v49; // xmm13
  __m128 v50; // xmm6
  __m128 v51; // xmm0
  __m128 v53; // [rsp+0h] [rbp-138h]
  __m128 v54; // [rsp+10h] [rbp-128h]
  __m128 v55; // [rsp+20h] [rbp-118h]
  __m128 v56; // [rsp+30h] [rbp-108h]
  __m128 v57; // [rsp+40h] [rbp-F8h]
  __m128 v58; // [rsp+50h] [rbp-E8h]
  __m128 v59; // [rsp+60h] [rbp-D8h]

  v3 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_999_99994), (__m128)LODWORD(FLOAT_999_99994), 0);
  si128 = _mm_load_si128((const __m128i *)&this->m_dinA);
  v5 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_aTb), 1u), 1u);
  v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_aTb.m_rotation.m_col2), 1u), 1u);
  v7.m_quad = (__m128)this->m_radiusA;
  v8 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_aTb.m_rotation.m_col1), 1u), 1u);
  v9 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_N9_9999998e16), (__m128)LODWORD(FLOAT_N9_9999998e16), 0);
  v10 = _mm_sub_ps(
          (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(this->m_radiusB.m_quad, this->m_radiusB.m_quad, 85), v8),
                _mm_mul_ps(_mm_shuffle_ps(this->m_radiusB.m_quad, this->m_radiusB.m_quad, 0), v5)),
              _mm_mul_ps(_mm_shuffle_ps(this->m_radiusB.m_quad, this->m_radiusB.m_quad, 170), v6)),
            v7.m_quad));
  if ( _mm_movemask_ps(_mm_cmplt_ps(tolerance->m_quad, v10)) )
  {
    result->m_enum = HK_FAILURE;
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
    if ( _mm_movemask_ps(_mm_cmplt_ps(tolerance->m_quad, v19)) )
    {
      result->m_enum = HK_FAILURE;
    }
    else
    {
      this->m_sepDist[1].m_quad = v19;
      v20.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
      v21.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
      v22 = _mm_shuffle_ps(v13, v6, 228);
      v23 = _mm_shuffle_ps((__m128)si128, (__m128)si128, 85);
      v24 = _mm_unpacklo_ps(v21.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
      v25 = _mm_shuffle_ps(_mm_unpackhi_ps(v21.m_quad, this->m_aTb.m_rotation.m_col1.m_quad), v20.m_quad, 228);
      v57 = _mm_movelh_ps(v24, v20.m_quad);
      v26 = _mm_mul_ps(v57, v57);
      v27 = _mm_shuffle_ps(_mm_movehl_ps(v57, v24), v20.m_quad, 212);
      v53 = _mm_movelh_ps(v14, v6);
      v54 = _mm_mul_ps(v27, v27);
      v28.m_quad = (__m128)this->m_radiusB;
      v29 = _mm_shuffle_ps(_mm_movehl_ps(v53, v14), v6, 212);
      v55 = v27;
      v56 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 90);
      v58 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 65);
      v59 = _mm_shuffle_ps(this->m_dinA.m_quad, this->m_dinA.m_quad, 170);
      v30 = _mm_mul_ps(v25, v25);
      v31 = _mm_max_ps(_mm_add_ps(v30, v54), (__m128)xmmword_141A712D0);
      v32 = _mm_rsqrt_ps(v31);
      v33 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v32), v32)),
              _mm_mul_ps(*(__m128 *)_xmm, v32));
      v34 = _mm_mul_ps(
              _mm_sub_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_sub_ps(_mm_mul_ps(v59, v55), _mm_mul_ps(v25, v23)), 1u),
                          1u),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v22, v16), _mm_mul_ps(v29, v18)),
                    _mm_mul_ps(_mm_shuffle_ps(v53, v53, 90), v58)),
                  _mm_mul_ps(_mm_shuffle_ps(v53, v53, 65), v56))),
              v33);
      if ( _mm_movemask_ps(_mm_cmplt_ps(this->m_tolerance4.m_quad, v34)) )
        goto LABEL_6;
      v35 = _mm_cmplt_ps(v3, v33);
      v36 = _mm_shuffle_ps(this->m_dinA.m_quad, this->m_dinA.m_quad, 0);
      this->m_sepDist[2].m_quad = _mm_or_ps(_mm_and_ps(v9, v35), _mm_andnot_ps(v35, v34));
      v37 = _mm_max_ps(_mm_add_ps(v30, v26), (__m128)xmmword_141A712D0);
      v38 = _mm_rsqrt_ps(v37);
      v39 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v38), v38));
      v40.m_quad = (__m128)this->m_tolerance4;
      v41 = _mm_mul_ps(v39, _mm_mul_ps(*(__m128 *)_xmm, v38));
      v42 = _mm_mul_ps(
              _mm_sub_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_sub_ps(_mm_mul_ps(v25, v36), _mm_mul_ps(v59, v57)), 1u),
                          1u),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v22, v17), _mm_mul_ps(v53, v18)),
                    _mm_mul_ps(_mm_shuffle_ps(v29, v29, 90), v58)),
                  _mm_mul_ps(_mm_shuffle_ps(v29, v29, 65), v56))),
              v41);
      if ( _mm_movemask_ps(_mm_cmplt_ps(v40.m_quad, v42)) )
        goto LABEL_6;
      v43 = _mm_cmplt_ps(v3, v41);
      v44 = _mm_and_ps(v9, v43);
      v45 = _mm_andnot_ps(v43, v42);
      v46.m_quad = (__m128)this->m_radiusB;
      this->m_sepDist[3].m_quad = _mm_or_ps(v45, v44);
      v47 = _mm_max_ps(_mm_add_ps(v26, v54), (__m128)xmmword_141A712D0);
      v48 = _mm_rsqrt_ps(v47);
      v49 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v47, v48), v48)),
              _mm_mul_ps(*(__m128 *)_xmm, v48));
      v50 = _mm_mul_ps(
              _mm_sub_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_sub_ps(_mm_mul_ps(v23, v57), _mm_mul_ps(v36, v55)), 1u),
                          1u),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 210), _mm_shuffle_ps(v46.m_quad, v46.m_quad, 201)),
                    _mm_add_ps(_mm_mul_ps(v29, v17), _mm_mul_ps(v53, v16))),
                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), _mm_shuffle_ps(v46.m_quad, v46.m_quad, 210)))),
              v49);
      if ( _mm_movemask_ps(_mm_cmplt_ps(v40.m_quad, v50)) )
      {
LABEL_6:
        result->m_enum = HK_FAILURE;
      }
      else
      {
        result->m_enum = HK_SUCCESS;
        v51 = _mm_cmplt_ps(v3, v49);
        this->m_sepDist[4].m_quad = _mm_or_ps(_mm_andnot_ps(v51, v50), _mm_and_ps(v51, v9));
      }
    }
  }
  return result;
}ult->m_enum = HK_SUCCESS;
        v51 = _mm_cmplt_ps(v3, v49);
        this->m_sepDist[4].m_quad = _mm_or_ps(_mm_andnot_ps(v51, v50), _mm_and_ps(v51, v9));
      }
    }

// File Line: 994
// RVA: 0xD394F0
__int64 __fastcall hkpBoxBoxCollisionDetection::findClosestPoint(
        hkpBoxBoxCollisionDetection *this,
        hkpBoxBoxManifold *manifold,
        hkpFeatureContactPoint *fcp,
        __m128i *fpp)
{
  int v8; // r12d
  __m128i v9; // xmm3
  __m128 m_quad; // xmm5
  __m128i si128; // xmm6
  hkVector4f *v12; // rax
  __int64 v13; // rcx
  __m128i v14; // xmm4
  __m128 v15; // xmm2
  __m128i v16; // xmm1
  __m128 v17; // xmm2
  __m128i v18; // xmm2
  __m128i v19; // xmm1
  __m128i v20; // xmm0
  __m128i v21; // xmm2
  __m128i v22; // xmm4
  __m128i v23; // xmm3
  __m128i v24; // xmm3
  __m128i v25; // xmm0
  unsigned int v26; // r15d
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  hkVector4fComparison v29; // xmm2
  hkVector4f v30; // xmm0
  hkVector4f v31; // xmm3
  hkVector4fComparison v32; // xmm0
  int v33; // edx
  int v34; // eax
  __int64 v35; // rcx
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  hkVector4fComparison v39; // xmm2
  __m128 v40; // xmm2
  hkVector4f v41; // xmm1
  hkVector4f v42; // xmm5
  __m128 v43; // xmm5
  hkVector4f v44; // xmm3
  hkVector4f v45; // xmm1
  __m128 v46; // xmm4
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  hkVector4fComparison v49; // xmm0
  int v50; // edx
  int v51; // eax
  __int64 v52; // rcx
  __m128 v53; // xmm0
  __m128 v54; // xmm1
  int v56; // edx
  unsigned int v57; // r8d
  hkVector4f v58; // xmm3
  __m128 v59; // xmm2
  __m128 v60; // xmm2
  __m128 v61; // xmm1
  __m128 v62; // xmm5
  __m128 v63; // xmm1
  hkVector4f v64; // xmm5
  __m128 v65; // xmm4
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm0
  hkVector4f v69; // xmm2
  hkVector4f v70; // xmm1
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  int v73; // ecx
  int v74; // eax
  __int64 v75; // rcx
  __m128 v76; // xmm1
  hkMatrix3f v77; // [rsp+20h] [rbp-78h] BYREF

  v8 = 8;
  while ( 1 )
  {
    v9 = (__m128i)xmmword_141A720C0;
    m_quad = this->m_sepDist[0].m_quad;
    si128 = _mm_load_si128((const __m128i *)&xmmword_141A720B0);
    v12 = &this->m_sepDist[1];
    v13 = 4i64;
    v14 = (__m128i)xmmword_141A720C0;
    do
    {
      v15 = v12->m_quad;
      v9 = _mm_add_epi32(v9, si128);
      ++v12;
      v16 = (__m128i)_mm_cmplt_ps(m_quad, v15);
      v17 = _mm_max_ps(v15, m_quad);
      m_quad = v17;
      v14 = _mm_or_si128(_mm_and_si128(v9, v16), _mm_andnot_si128(v16, v14));
      --v13;
    }
    while ( v13 );
    v18 = (__m128i)_mm_cmpeq_ps(
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
      fcp->m_featureIdA = v26;
      fpp[5].m128i_i32[0] = v26;
      hkMatrix3f::setTranspose(&v77, &this->m_aTb.m_rotation);
      v27 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v26], this->m_dinA.m_quad);
      v28 = _mm_or_ps(_mm_shuffle_ps(v27, v27, 78), v27);
      v29.m_mask = _mm_cmplt_ps(_mm_or_ps(_mm_shuffle_ps(v28, v28, 177), v28), (__m128)0i64);
      fpp[3] = (__m128i)v29.m_mask;
      v30.m_quad = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(_mm_cmpeq_epi32((__m128i)0i64, (__m128i)v29.m_mask), 0x1Fu),
                               0x1Fu),
                     this->m_radiusB.m_quad);
      fpp[1] = (__m128i)v30.m_quad;
      v31.m_quad = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_xor_ps(
                                              (__m128)_mm_slli_epi32(
                                                        _mm_srli_epi32(
                                                          (__m128i)_mm_cmple_ps(this->m_dinB.m_quad, (__m128)0i64),
                                                          0x1Fu),
                                                        0x1Fu),
                                              _mm_xor_ps(
                                                (__m128)_mm_slli_epi32(
                                                          _mm_srli_epi32((__m128i)v29.m_mask, 0x1Fu),
                                                          0x1Fu),
                                                (__m128)_xmm)),
                                            *(&v77.m_col0.m_quad + (int)v26)),
                                 0x1Fu),
                               0x1Fu),
                     v30.m_quad);
      fpp[1] = (__m128i)v31.m_quad;
      v32.m_mask = (__m128)fpp[3];
      v33 = 16 * (_mm_movemask_ps(_mm_cmplt_ps((__m128)fpp[1], (__m128)0i64)) & 7);
      *(__m128 *)fpp = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_shuffle_ps(v31.m_quad, v31.m_quad, 85),
                               this->m_aTb.m_rotation.m_col1.m_quad),
                             _mm_mul_ps(_mm_shuffle_ps(v31.m_quad, v31.m_quad, 0), this->m_aTb.m_rotation.m_col0.m_quad)),
                           _mm_mul_ps(_mm_shuffle_ps(v31.m_quad, v31.m_quad, 170), this->m_aTb.m_rotation.m_col2.m_quad)),
                         this->m_aTb.m_translation.m_quad);
      if ( _mm_movemask_ps(v32.m_mask) )
        LOBYTE(v33) = v33 | 8;
      fcp->m_featureIdB = v33;
      v34 = (unsigned __int8)manifold->m_numPoints - 1;
      v35 = v34;
      if ( v34 >= 0 )
      {
        while ( manifold->m_contactPoints[v35].m_featureIdA != fcp->m_featureIdA
             || manifold->m_contactPoints[v35].m_featureIdB != (_BYTE)v33 )
        {
          if ( --v35 < 0 )
            goto LABEL_11;
        }
        return 1i64;
      }
LABEL_11:
      if ( (_mm_movemask_ps(
              _mm_cmplt_ps(
                (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(fpp), 1u), 1u),
                this->m_keepRadiusA.m_quad)) & 7) == 7 )
      {
        v53 = _mm_and_ps(
                _mm_sub_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128(fpp + 3), 0x1Fu), 0x1Fu),
                    *(__m128 *)fpp),
                  this->m_radiusA.m_quad),
                (__m128)`hkVector4f::getComponent::`2::indexToMask[fpp[5].m128i_i32[0]]);
        goto LABEL_22;
      }
      goto LABEL_43;
    }
    if ( v26 > 6 )
      break;
    fcp->m_featureIdA = v26;
    fpp[5].m128i_i32[0] = v26;
    v36 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v26 - 4], this->m_dinB.m_quad);
    v37 = *(&this->m_aTb.m_rotation.m_col0.m_quad + (int)(v26 - 4));
    v38 = _mm_or_ps(_mm_shuffle_ps(v36, v36, 78), v36);
    v39.m_mask = _mm_cmplt_ps(_mm_or_ps(_mm_shuffle_ps(v38, v38, 177), v38), (__m128)0i64);
    fpp[3] = (__m128i)v39.m_mask;
    v40 = (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)v39.m_mask, 0x1Fu), 0x1Fu);
    v41.m_quad = _mm_xor_ps(this->m_radiusA.m_quad, v40);
    *(hkVector4f *)fpp = (hkVector4f)v41.m_quad;
    v42.m_quad = _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(
                               (__m128i)_mm_add_ps(
                                          _mm_xor_ps(
                                            (__m128)_mm_slli_epi32(
                                                      _mm_srli_epi32(
                                                        (__m128i)_mm_cmple_ps(this->m_dinB.m_quad, (__m128)0i64),
                                                        0x1Fu),
                                                      0x1Fu),
                                            _mm_xor_ps((__m128)_xmm_b727c5acb727c5acb727c5acb727c5ac, v40)),
                                          v37),
                               0x1Fu),
                             0x1Fu),
                   v41.m_quad);
    *(hkVector4f *)fpp = (hkVector4f)v42.m_quad;
    v43 = _mm_sub_ps(v42.m_quad, this->m_aTb.m_translation.m_quad);
    v44.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
    v45.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
    v46 = _mm_unpackhi_ps(v45.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
    v47 = _mm_unpacklo_ps(v45.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
    v48 = _mm_movelh_ps(v47, v44.m_quad);
    v49.m_mask = (__m128)fpp[3];
    v50 = 16 * (_mm_movemask_ps(_mm_cmplt_ps(*(__m128 *)fpp, (__m128)0i64)) & 7);
    fpp[1] = (__m128i)_mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_shuffle_ps(v43, v43, 85),
                            _mm_shuffle_ps(_mm_movehl_ps(v48, v47), v44.m_quad, 212)),
                          _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v48)),
                        _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), _mm_shuffle_ps(v46, v44.m_quad, 228)));
    if ( _mm_movemask_ps(v49.m_mask) )
      LOBYTE(v50) = v50 | 8;
    fcp->m_featureIdB = v50;
    v51 = (unsigned __int8)manifold->m_numPoints - 1;
    v52 = v51;
    if ( v51 >= 0 )
    {
      while ( manifold->m_contactPoints[v52].m_featureIdA != fcp->m_featureIdA
           || manifold->m_contactPoints[v52].m_featureIdB != (_BYTE)v50 )
      {
        if ( --v52 < 0 )
          goto LABEL_20;
      }
      return 1i64;
    }
LABEL_20:
    if ( (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(fpp + 1), 1u), 1u),
              this->m_keepRadiusB.m_quad)) & 7) == 7 )
    {
      v53 = _mm_and_ps(
              _mm_sub_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(_mm_cmpeq_epi32(_mm_load_si128(fpp + 3), (__m128i)0i64), 0x1Fu),
                            0x1Fu),
                  (__m128)fpp[1]),
                this->m_radiusB.m_quad),
              (__m128)`hkVector4f::getComponent::`2::indexToMask[fpp[5].m128i_i32[0] - 4]);
LABEL_22:
      v54 = _mm_or_ps(_mm_shuffle_ps(v53, v53, 78), v53);
      fpp[4] = (__m128i)_mm_or_ps(_mm_shuffle_ps(v54, v54, 177), v54);
      return 2i64;
    }
LABEL_43:
    --v8;
    v76 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v26 & 3];
    this->m_sepDist[(unsigned __int64)v26 >> 2].m_quad = _mm_or_ps(
                                                           _mm_and_ps(v76, (__m128)xmmword_141A712F0),
                                                           _mm_andnot_ps(
                                                             v76,
                                                             this->m_sepDist[(unsigned __int64)v26 >> 2].m_quad));
    if ( v8 <= 0 )
      return 0i64;
  }
  v56 = (v26 - 8) & 3;
  fpp[5].m128i_i32[1] = v56;
  v57 = (v26 - 8) >> 2;
  fpp[5].m128i_i32[0] = v57;
  v58.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
  v59 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              *(&this->m_aTb.m_rotation.m_col0.m_quad + v56),
              *(&this->m_aTb.m_rotation.m_col0.m_quad + v56),
              201),
            *(&transform.m_quad + v57)),
          _mm_mul_ps(
            _mm_shuffle_ps(*(&transform.m_quad + v57), *(&transform.m_quad + v57), 201),
            *(&this->m_aTb.m_rotation.m_col0.m_quad + v56)));
  v60 = _mm_shuffle_ps(v59, v59, 201);
  v61 = _mm_mul_ps(this->m_dinA.m_quad, v60);
  v62 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)), _mm_shuffle_ps(v61, v61, 170));
  v63 = _mm_unpacklo_ps(this->m_aTb.m_rotation.m_col0.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
  v64.m_quad = _mm_xor_ps(
                 (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps(v62, (__m128)0i64), 0x1Fu), 0x1Fu),
                 v60);
  v65 = _mm_shuffle_ps(
          _mm_unpackhi_ps(this->m_aTb.m_rotation.m_col0.m_quad, this->m_aTb.m_rotation.m_col1.m_quad),
          v58.m_quad,
          228);
  v66 = _mm_movelh_ps(v63, v58.m_quad);
  *(hkVector4f *)fpp = (hkVector4f)v64.m_quad;
  v67 = _mm_mul_ps(_mm_shuffle_ps(v64.m_quad, v64.m_quad, 85), _mm_shuffle_ps(_mm_movehl_ps(v66, v63), v58.m_quad, 212));
  v68 = _mm_mul_ps(_mm_shuffle_ps(v64.m_quad, v64.m_quad, 0), v66);
  v69.m_quad = (__m128)*fpp;
  v70.m_quad = _mm_add_ps(_mm_add_ps(v67, v68), _mm_mul_ps(_mm_shuffle_ps(v64.m_quad, v64.m_quad, 170), v65));
  fpp[1] = (__m128i)v70.m_quad;
  if ( v57 == 1 )
  {
    v71 = _mm_shuffle_ps(_mm_unpacklo_ps(v69.m_quad, (__m128)0i64), v69.m_quad, 228);
  }
  else if ( (v26 - 8) >> 2 == 2 )
  {
    v71 = _mm_shuffle_ps(v69.m_quad, _mm_unpackhi_ps(v69.m_quad, (__m128)0i64), 180);
  }
  else if ( (v26 - 8) >> 2 == 3 )
  {
    v71 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v69.m_quad, 4), 4);
  }
  else
  {
    v71 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v69.m_quad, 4), 4);
  }
  switch ( v56 )
  {
    case 1:
      v72 = _mm_shuffle_ps(_mm_unpacklo_ps(v70.m_quad, (__m128)0i64), v70.m_quad, 228);
      break;
    case 2:
      v72 = _mm_shuffle_ps(v70.m_quad, _mm_unpackhi_ps(v70.m_quad, (__m128)0i64), 180);
      break;
    case 3:
      v72 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v70.m_quad, 4), 4);
      break;
    default:
      v72 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)v70.m_quad, 4), 4);
      break;
  }
  v73 = (unsigned __int8)(v57 | (16 * (_mm_movemask_ps(_mm_cmplt_ps(v71, (__m128)0i64)) | 0xF8)));
  fcp->m_featureIdA = v73;
  fcp->m_featureIdB = v56 + (~(16 * _mm_movemask_ps(_mm_cmplt_ps(v72, (__m128)0i64))) & 0x70);
  fpp[5].m128i_i32[0] = v73;
  fpp[5].m128i_i32[1] = (unsigned __int8)fcp->m_featureIdB;
  v74 = (unsigned __int8)manifold->m_numPoints - 1;
  v75 = v74;
  if ( v74 < 0 )
  {
LABEL_42:
    if ( hkpBoxBoxCollisionDetection::isValidEdgeEdge(this, (hkpBoxBoxCollisionDetection::hkpFeaturePointCache *)fpp) )
      return 2i64;
    goto LABEL_43;
  }
  while ( manifold->m_contactPoints[v75].m_featureIdA != fcp->m_featureIdA
       || manifold->m_contactPoints[v75].m_featureIdB != fcp->m_featureIdB )
  {
    if ( --v75 < 0 )
      goto LABEL_42;
  }
  return 1i64;
}

// File Line: 1130
// RVA: 0xD3A110
bool __fastcall hkpBoxBoxCollisionDetection::isValidEdgeEdge(
        hkpBoxBoxCollisionDetection *this,
        hkpBoxBoxCollisionDetection::hkpFeaturePointCache *fpp)
{
  hkVector4f v2; // xmm3
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
  int v18; // edx
  int v19; // ecx
  int v20; // eax
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
  bool result; // al
  __m128 v38; // xmm1
  int v39; // eax
  float v40; // xmm8_4
  __m128 v41; // xmm4
  float v42; // xmm0_4
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  hkVector4f v46; // xmm6
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
  hkSimdFloat32 v58; // xmm3

  v2.m_quad = (__m128)this->m_radiusA;
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
          *(&this->m_aTb.m_rotation.m_col0.m_quad + (fpp->m_featureIndexB & 0xF)));
  v14 = _mm_and_ps(v10, v2.m_quad);
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
  v21 = _mm_shuffle_ps(
          (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_edgeEndpointTolerance),
          (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_edgeEndpointTolerance),
          0).m128_f32[0];
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
  v44 = _mm_and_ps(v7, v43);
  v45 = _mm_or_ps(_mm_shuffle_ps(v44, v44, 78), v44);
  v46.m_quad = _mm_or_ps(
                 _mm_and_ps(_mm_add_ps(_mm_or_ps(_mm_shuffle_ps(v45, v45, 177), v45), _mm_mul_ps(v41, v22)), v43),
                 _mm_andnot_ps(v43, v7));
  v47 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v22, (__m128)xmmword_141A711B0), v43), _mm_andnot_ps(v43, (__m128)0i64));
  v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v47), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v13));
  v49 = _mm_shuffle_ps(v48, v48, 201);
  v50 = _mm_mul_ps(v49, v49);
  v51 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)), _mm_shuffle_ps(v50, v50, 170));
  v52 = _mm_rsqrt_ps(v51);
  v53 = _mm_andnot_ps(
          _mm_cmple_ps(v51, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)), _mm_mul_ps(*(__m128 *)_xmm, v52)));
  v54 = _mm_mul_ps(v49, v53);
  if ( (float)(v53.m128_f32[0] * v51.m128_f32[0]) < this->m_boundaryTolerance.m_real.m128_f32[0] )
    return 0;
  v55 = _mm_mul_ps(v54, v6);
  v56 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32(
                      (__m128i)_mm_cmplt_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                                   _mm_shuffle_ps(v55, v55, 170)),
                                 (__m128)0i64),
                      0x1Fu),
                    0x1Fu),
          v54);
  v57 = _mm_mul_ps(v56, v17);
  v58.m_real = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                 _mm_shuffle_ps(v57, v57, 170));
  if ( v58.m_real.m128_f32[0] > _mm_shuffle_ps(this->m_tolerance4.m_quad, this->m_tolerance4.m_quad, 0).m128_f32[0] )
    return 0;
  fpp->m_vA = (hkVector4f)v46.m_quad;
  fpp->m_distance = (hkSimdFloat32)v58.m_real;
  result = 1;
  fpp->m_nA.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v56);
  return result;
}

// File Line: 1434
// RVA: 0xD392C0
hkBool *__fastcall hkpBoxBoxCollisionDetection::calculateClosestPoint(
        hkpBoxBoxCollisionDetection *this,
        hkBool *result,
        hkContactPoint *contact)
{
  __m128 m_quad; // xmm5
  hkVector4f v7; // xmm3
  hkVector4f v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  hkVector4f v11; // xmm3
  __m128 v12; // xmm2
  hkTransformf *m_wTa; // rax
  __m128 v14; // xmm2
  hkpBoxBoxCollisionDetection::hkpFeaturePointCache fpp; // [rsp+20h] [rbp-A8h] BYREF
  hkpBoxBoxManifold manifold; // [rsp+80h] [rbp-48h] BYREF
  hkpFeatureContactPoint fcp; // [rsp+D0h] [rbp+8h] BYREF
  hkResult resulta; // [rsp+E8h] [rbp+20h] BYREF

  hkpBoxBoxManifold::hkpBoxBoxManifold(&manifold);
  m_quad = this->m_aTb.m_translation.m_quad;
  this->m_dinA.m_quad = m_quad;
  v7.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
  v8.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
  fcp.m_contactPointId = 0;
  memset(&fpp.m_nA, 0, 32);
  v9 = _mm_unpacklo_ps(v8.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
  v10 = _mm_movelh_ps(v9, v7.m_quad);
  this->m_dinB.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(m_quad, m_quad, 85),
                              _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v7.m_quad, 212)),
                            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v10)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(m_quad, m_quad, 170),
                            _mm_shuffle_ps(
                              _mm_unpackhi_ps(v8.m_quad, this->m_aTb.m_rotation.m_col1.m_quad),
                              v7.m_quad,
                              228)));
  if ( hkpBoxBoxCollisionDetection::checkIntersection(this, &resulta, &this->m_tolerance4)->m_enum
    || hkpBoxBoxCollisionDetection::findClosestPoint(this, &manifold, &fcp, &fpp) != 2 )
  {
    result->m_bool = 0;
  }
  else
  {
    if ( fpp.m_featureIndexA > 2 )
    {
      m_wTa = this->m_wTa;
      v11.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 85),
                           m_wTa->m_rotation.m_col1.m_quad),
                         _mm_mul_ps(
                           _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 0),
                           m_wTa->m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 170),
                         m_wTa->m_rotation.m_col2.m_quad)),
                     m_wTa->m_translation.m_quad);
      if ( fpp.m_featureIndexA > 6 )
        v12 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 85), m_wTa->m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 0), m_wTa->m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 170), m_wTa->m_rotation.m_col2.m_quad));
      else
        v12 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            _mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&fpp.m_normalIsFlipped), (__m128i)0i64),
                            0x1Fu),
                          0x1Fu),
                *(&this->m_wTb[-1].m_rotation.m_col0.m_quad + (unsigned __int8)fcp.m_featureIdA));
    }
    else
    {
      v11.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 85),
                           this->m_wTb->m_rotation.m_col1.m_quad),
                         _mm_mul_ps(
                           _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 0),
                           this->m_wTb->m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 170),
                         this->m_wTb->m_rotation.m_col2.m_quad)),
                     this->m_wTb->m_translation.m_quad);
      v12 = _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32(
                          _mm_cmpeq_epi32(_mm_load_si128((const __m128i *)&fpp.m_normalIsFlipped), (__m128i)0i64),
                          0x1Fu),
                        0x1Fu),
              *(&this->m_wTa->m_rotation.m_col0.m_quad + (unsigned __int8)fcp.m_featureIdA));
    }
    v14 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, fpp.m_distance.m_real), 196);
    if ( fcp.m_featureIdA > 2u )
      v11.m_quad = _mm_sub_ps(v11.m_quad, _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v14));
    contact->m_position = (hkVector4f)v11.m_quad;
    result->m_bool = 1;
    contact->m_separatingNormal.m_quad = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, _mm_shuffle_ps(v14, v14, 255)), 196);
  }
  return result;
}

// File Line: 1472
// RVA: 0xD37480
void __fastcall hkpBoxBoxCollisionDetection::calcManifold(
        hkpBoxBoxCollisionDetection *this,
        hkpBoxBoxManifold *manifold)
{
  __m128 m_quad; // xmm6
  int v3; // r14d
  int v6; // r15d
  hkVector4f v7; // xmm4
  hkVector4f v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm8
  hkpBoxBoxManifold *v13; // r14
  hkpBoxBoxManifold *v14; // rbx
  __int64 m_featureIdA; // rcx
  unsigned __int8 v16; // al
  __m128i v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  __m128 v20; // xmm7
  __m128 v21; // xmm4
  __m128i v22; // xmm2
  hkpProcessCollisionOutput *v23; // rax
  __m128 *v24; // rdx
  __int64 v25; // rax
  __int64 v26; // rcx
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm3
  __m128 v30; // xmm5
  unsigned __int8 v31; // al
  __m128i v32; // xmm9
  hkVector4f v33; // xmm3
  hkVector4f v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm7
  __m128 v39; // xmm5
  __m128i v40; // xmm6
  hkpProcessCollisionOutput *v41; // rax
  __m128 *v42; // rdx
  __int64 v43; // rax
  __m128 v44; // xmm9
  __int64 v45; // rcx
  __m128 v46; // xmm6
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  int m_featureIdB; // eax
  hkpProcessCollisionOutput *m_result; // rax
  hkVector4f v52; // xmm1
  hkVector4f v53; // xmm0
  __m128 *p_m_quad; // rcx
  hkTransformf *m_wTa; // rax
  __m128 v56; // xmm2
  hkVector4f v57; // xmm1
  __m128 v58; // xmm0
  __m128 v59; // xmm2
  int v60; // ebx
  hkVector4f v61; // xmm6
  hkVector4f v62; // xmm4
  hkVector4f v63; // xmm1
  __m128 v64; // xmm5
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  unsigned int m_manifoldNormalB; // ecx
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  hkVector4f *p_qin; // r8
  __m128 v71; // xmm8
  hkpFeatureContactPoint ClosestPoint; // eax
  int m_featureIndexA; // r13d
  hkVector4fComparison v74; // xmm7
  hkVector4f v75; // xmm9
  hkpFeatureContactPoint v76; // r15d
  hkVector4f v77; // xmm3
  unsigned __int8 m_enum; // r9
  int v79; // ecx
  hkVector4f v80; // xmm1
  __m128i v81; // xmm2
  hkVector4f v82; // xmm1
  __m128 v83; // xmm6
  float v84; // xmm8_4
  unsigned __int64 v85; // rdx
  hkpBoxBoxManifold *v86; // r15
  __int64 v87; // rbx
  hkpProcessCollisionOutput *v88; // rdx
  __m128 v89; // xmm2
  hkpProcessCdPoint *m_storage; // rcx
  hkVector4f v91; // xmm5
  hkVector4f v92; // xmm1
  __m128 v93; // xmm6
  __m128 v94; // xmm1
  __m128 v95; // xmm2
  hkVector4f v96; // xmm8
  hkVector4f v97; // xmm6
  hkTransformf *m_wTb; // rax
  __m128 v99; // xmm3
  __m128 v100; // xmm0
  __m128 v101; // xmm1
  int v102; // edx
  float v103; // xmm4_4
  __m128 v104; // xmm3
  float v105; // xmm4_4
  __int64 v106; // r8
  hkpBoxBoxManifold *v107; // rcx
  __m128 v108; // xmm2
  __m128 v109; // xmm2
  int v110; // eax
  __int64 v111; // r14
  hkpProcessCdPoint *v112; // rbx
  unsigned int v113; // edx
  __m128 v114; // xmm7
  __m128 v115; // xmm1
  __m128 v116; // xmm0
  __m128 v117; // xmm6
  int m_enum_low; // ecx
  __m128 v119; // xmm7
  __m128 v120; // xmm2
  __m128 v121; // xmm2
  unsigned __int16 v122; // ax
  unsigned __int8 m_numPoints; // cl
  __int64 v124; // r10
  hkTransformf *v125; // rax
  hkVector4f *p_m_separatingNormal; // rdx
  __m128 v127; // xmm9
  __m128 v128; // xmm6
  __m128 v129; // xmm7
  __m128 v130; // xmm10
  hkTransformf *v131; // rax
  __m128 v132; // xmm2
  __m128 v133; // xmm4
  __m128 v134; // xmm3
  __m128 v135; // xmm6
  __m128 v136; // xmm8
  __m128 v137; // xmm1
  __m128 v138; // xmm0
  __m128i v139; // xmm13
  __m128 v140; // xmm5
  __m128i v141; // xmm12
  __m128 v142; // xmm4
  int v143; // r11d
  float v144; // xmm3_4
  unsigned __int8 v145; // r9
  int v146; // ecx
  __m128 v147; // xmm6
  hkpProcessCdPoint *v148; // r14
  __m128 v149; // xmm4
  __m128 v150; // xmm2
  __m128 v151; // xmm4
  int v152; // eax
  __m128 v153; // xmm5
  __m128 v154; // xmm1
  float v155; // xmm0_4
  __m128 v156; // xmm4
  __m128 v157; // xmm0
  int v158; // r8d
  __m128 v159; // xmm1
  __m128 v160; // xmm0
  __m128 v161; // xmm2
  int v162; // ecx
  __m128 v163; // xmm13
  __int64 v164; // rax
  __m128 v165; // xmm0
  hkpFeatureContactPoint v166; // ebx
  const unsigned __int16 *v167; // r13
  unsigned __int16 v168; // cx
  int v169; // r9d
  unsigned __int8 v170; // dl
  __int64 v171; // rcx
  __m128i v172; // xmm7
  __m128 v173; // xmm8
  __m128 v174; // xmm10
  __m128 v175; // xmm12
  __m128 v176; // xmm8
  __m128i v177; // xmm6
  __m128 v178; // xmm1
  __m128 v179; // xmm0
  __m128 v180; // xmm9
  hkTransformf *v181; // rax
  __m128 v182; // xmm0
  __m128 v183; // xmm3
  __m128 v184; // xmm1
  int v185; // edx
  float v186; // xmm4_4
  __m128 v187; // xmm3
  float v188; // xmm4_4
  __int64 v189; // r8
  hkpBoxBoxManifold *v190; // rcx
  __m128 v191; // xmm2
  __m128 v192; // xmm2
  int v193; // eax
  __int64 v194; // r15
  unsigned int v195; // edx
  __m128 v196; // xmm7
  __m128 v197; // xmm1
  __m128 v198; // xmm0
  __m128 v199; // xmm6
  int v200; // ecx
  __m128 v201; // xmm7
  __m128 v202; // xmm2
  __m128 v203; // xmm2
  int v204; // ecx
  const unsigned __int16 *v205; // r13
  unsigned __int16 v206; // ax
  int v207; // r9d
  unsigned __int8 v208; // dl
  __int64 v209; // rcx
  __m128i v210; // xmm8
  unsigned __int16 v211; // ax
  hkVector4f v212; // xmm3
  hkVector4f v213; // xmm1
  __m128 v214; // xmm4
  __m128 v215; // xmm1
  __m128 v216; // xmm2
  __m128 v217; // xmm6
  __m128 v218; // xmm5
  __m128i v219; // xmm7
  __m128 v220; // xmm8
  __m128 v221; // xmm1
  __m128 v222; // xmm0
  __m128 v223; // xmm9
  hkTransformf *v224; // rax
  __m128 v225; // xmm3
  __m128 v226; // xmm0
  __m128 v227; // xmm1
  int v228; // edx
  float v229; // xmm4_4
  __m128 v230; // xmm3
  float v231; // xmm4_4
  __int64 v232; // r8
  hkpBoxBoxManifold *v233; // rcx
  __m128 v234; // xmm2
  __m128 v235; // xmm2
  int v236; // eax
  __int64 v237; // r15
  hkpProcessCdPoint *v238; // r14
  unsigned int v239; // edx
  __int64 v240; // rcx
  hkTransformf *v241; // rax
  __m128 v242; // xmm1
  __m128 v243; // xmm0
  __m128 v244; // xmm6
  int v245; // ecx
  __m128 v246; // xmm1
  __m128 v247; // xmm2
  __m128 v248; // xmm2
  unsigned __int16 v249; // ax
  int planeMaskB; // [rsp+40h] [rbp-C0h]
  hkpFeatureContactPoint v251; // [rsp+44h] [rbp-BCh]
  unsigned __int8 v252; // [rsp+48h] [rbp-B8h]
  hkVector4f qin; // [rsp+50h] [rbp-B0h] BYREF
  hkpBoxBoxCollisionDetection::hkpFeaturePointCache fpp; // [rsp+60h] [rbp-A0h] BYREF
  hkResult result; // [rsp+1A0h] [rbp+A0h] BYREF
  hkpFeatureContactPoint v256; // [rsp+1A8h] [rbp+A8h] BYREF
  int planeMaskA; // [rsp+1B0h] [rbp+B0h]
  hkpFeatureContactPoint fcp; // [rsp+1B8h] [rbp+B8h] BYREF

  m_quad = this->m_aTb.m_translation.m_quad;
  v3 = 0;
  v6 = 0;
  this->m_dinA.m_quad = m_quad;
  v7.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
  v8.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
  v9 = _mm_unpackhi_ps(v8.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
  v10 = _mm_unpacklo_ps(v8.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
  v11 = _mm_movelh_ps(v10, v7.m_quad);
  this->m_dinB.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(_mm_movehl_ps(v11, v10), v7.m_quad, 212),
                              _mm_shuffle_ps(m_quad, m_quad, 85)),
                            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v11)),
                          _mm_mul_ps(_mm_shuffle_ps(v9, v7.m_quad, 228), _mm_shuffle_ps(m_quad, m_quad, 170)));
  v12 = (__m128)xmmword_141A712A0;
  if ( manifold->m_numPoints )
  {
    v13 = manifold;
    while ( 1 )
    {
      v14 = v13;
      ++v6;
      v13 = (hkpBoxBoxManifold *)((char *)v13 + 4);
      m_featureIdA = (unsigned __int8)v14->m_contactPoints[0].m_featureIdA;
      if ( (unsigned __int8)v14->m_contactPoints[0].m_featureIdA > 2u )
      {
        if ( (unsigned __int8)v14->m_contactPoints[0].m_featureIdA > 6u )
        {
          m_featureIdB = (unsigned __int8)v14->m_contactPoints[0].m_featureIdB;
          fpp.m_featureIndexA = (unsigned __int8)v14->m_contactPoints[0].m_featureIdA;
          fpp.m_featureIndexB = m_featureIdB;
          if ( !hkpBoxBoxCollisionDetection::isValidEdgeEdge(this, &fpp) )
            goto LABEL_17;
          m_result = this->m_result;
          v52.m_quad = (__m128)fpp.m_vA;
          v12 = _mm_min_ps(v12, fpp.m_distance.m_real);
          v53.m_quad = (__m128)fpp.m_vA;
          p_m_quad = &m_result->m_firstFreeContactPoint.m_storage->m_contact.m_position.m_quad;
          ++m_result->m_firstFreeContactPoint.m_storage;
          p_m_quad[2].m128_i32[0] = v14->m_contactPoints[0].m_contactPointId;
          m_wTa = this->m_wTa;
          v56 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v53.m_quad, v53.m_quad, 85), m_wTa->m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v53.m_quad, v52.m_quad, 0), m_wTa->m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v52.m_quad, v52.m_quad, 170), m_wTa->m_rotation.m_col2.m_quad));
          v57.m_quad = (__m128)fpp.m_nA;
          v58 = _mm_shuffle_ps(fpp.m_nA.m_quad, fpp.m_nA.m_quad, 0);
          *p_m_quad = _mm_add_ps(v56, m_wTa->m_translation.m_quad);
          v59 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v57.m_quad, v57.m_quad, 85), this->m_wTa->m_rotation.m_col1.m_quad),
                    _mm_mul_ps(v58, this->m_wTa->m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v57.m_quad, v57.m_quad, 170), this->m_wTa->m_rotation.m_col2.m_quad));
          p_m_quad[1] = _mm_shuffle_ps(v59, _mm_unpackhi_ps(v59, fpp.m_distance.m_real), 196);
        }
        else
        {
          v31 = v14->m_contactPoints[0].m_featureIdB;
          if ( (v31 & 8) != 0 )
            v32 = (__m128i)xmmword_141A86110;
          else
            v32 = 0i64;
          v33.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
          v34.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
          v35 = _mm_unpackhi_ps(v34.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
          v36 = _mm_unpacklo_ps(v34.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
          v37 = _mm_movelh_ps(v36, v33.m_quad);
          v38 = _mm_mul_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(hkVector4fComparison_maskToComparison_373[(v31 >> 4) & 7], 0x1Fu),
                              0x1Fu),
                    query.m_quad),
                  this->m_radiusA.m_quad);
          v39 = _mm_sub_ps(v38, this->m_aTb.m_translation.m_quad);
          v40 = (__m128i)_mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_shuffle_ps(_mm_movehl_ps(v37, v36), v33.m_quad, 212),
                               _mm_shuffle_ps(v39, v39, 85)),
                             _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), v37)),
                           _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), _mm_shuffle_ps(v35, v33.m_quad, 228)));
          if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v40, 1u), 1u), this->m_keepRadiusB.m_quad)) & 7) != 7 )
          {
LABEL_17:
            v13 = (hkpBoxBoxManifold *)((char *)v13 - 4);
            --v6;
            if ( v13->m_contactPoints[0].m_featureIdA <= 6u )
              --manifold->m_faceVertexFeatureCount;
            ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkpConstraintOwner *))this->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
              this->m_contactMgr,
              v13->m_contactPoints[0].m_contactPointId,
              this->m_result->m_constraintOwner.m_storage);
            hkpBoxBoxManifold::removePoint(manifold, v6);
            goto LABEL_20;
          }
          v41 = this->m_result;
          v42 = &v41->m_firstFreeContactPoint.m_storage->m_contact.m_position.m_quad;
          ++v41->m_firstFreeContactPoint.m_storage;
          v43 = m_featureIdA - 4;
          v44 = (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v32, (__m128i)0i64), 0x1Fu), 0x1Fu);
          v45 = (unsigned __int8)v14->m_contactPoints[0].m_featureIdA - 4;
          v46 = _mm_and_ps(
                  _mm_sub_ps(_mm_xor_ps((__m128)v40, v44), this->m_radiusB.m_quad),
                  (__m128)`hkVector4f::getComponent::`2::indexToMask[v43]);
          v42[2].m128_i32[0] = v14->m_contactPoints[0].m_contactPointId;
          v47 = _mm_or_ps(_mm_shuffle_ps(v46, v46, 78), v46);
          v48 = _mm_or_ps(_mm_shuffle_ps(v47, v47, 177), v47);
          v12 = _mm_min_ps(v12, v48);
          *v42 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), this->m_wTa->m_rotation.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), this->m_wTa->m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), this->m_wTa->m_rotation.m_col2.m_quad)),
                   this->m_wTa->m_translation.m_quad);
          v49 = _mm_xor_ps(*(&this->m_wTb->m_rotation.m_col0.m_quad + v45), v44);
          v42[1] = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, v48), 196);
        }
      }
      else
      {
        v16 = v14->m_contactPoints[0].m_featureIdB;
        if ( (v16 & 8) != 0 )
          v17 = (__m128i)xmmword_141A86110;
        else
          v17 = 0i64;
        v18 = _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(hkVector4fComparison_maskToComparison_373[(v16 >> 4) & 7], 0x1Fu),
                            0x1Fu),
                  query.m_quad),
                this->m_radiusB.m_quad);
        v19 = _mm_shuffle_ps(v18, v18, 85);
        v20 = _mm_shuffle_ps(v18, v18, 0);
        v21 = _mm_shuffle_ps(v18, v18, 170);
        v22 = (__m128i)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(v20, this->m_aTb.m_rotation.m_col0.m_quad),
                             _mm_mul_ps(v19, this->m_aTb.m_rotation.m_col1.m_quad)),
                           _mm_mul_ps(this->m_aTb.m_rotation.m_col2.m_quad, v21)),
                         this->m_aTb.m_translation.m_quad);
        if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v22, 1u), 1u), this->m_keepRadiusA.m_quad)) & 7) != 7 )
          goto LABEL_17;
        v23 = this->m_result;
        v24 = &v23->m_firstFreeContactPoint.m_storage->m_contact.m_position.m_quad;
        ++v23->m_firstFreeContactPoint.m_storage;
        v25 = (int)m_featureIdA;
        v26 = (unsigned __int8)v14->m_contactPoints[0].m_featureIdA;
        v27 = _mm_and_ps(
                _mm_sub_ps(
                  _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v17, 0x1Fu), 0x1Fu), (__m128)v22),
                  this->m_radiusA.m_quad),
                (__m128)`hkVector4f::getComponent::`2::indexToMask[v25]);
        v24[2].m128_i32[0] = v14->m_contactPoints[0].m_contactPointId;
        v28 = _mm_or_ps(_mm_shuffle_ps(v27, v27, 78), v27);
        v29 = _mm_or_ps(_mm_shuffle_ps(v28, v28, 177), v28);
        v12 = _mm_min_ps(v12, v29);
        *v24 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(this->m_wTb->m_rotation.m_col1.m_quad, v19),
                     _mm_mul_ps(this->m_wTb->m_rotation.m_col0.m_quad, v20)),
                   _mm_mul_ps(this->m_wTb->m_rotation.m_col2.m_quad, v21)),
                 this->m_wTb->m_translation.m_quad);
        v30 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v17, (__m128i)0i64), 0x1Fu), 0x1Fu),
                *(&this->m_wTa->m_rotation.m_col0.m_quad + v26));
        v24[1] = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, v29), 196);
      }
LABEL_20:
      if ( v6 >= (unsigned __int8)manifold->m_numPoints )
      {
        v3 = 0;
        break;
      }
    }
  }
  if ( manifold->m_numPoints >= 2u )
  {
    v61.m_quad = (__m128)manifold->m_manifoldNormalA;
    if ( _mm_shuffle_ps(v61.m_quad, v61.m_quad, 255).m128_f32[0] < 0.0 )
    {
      m_manifoldNormalB = manifold->m_manifoldNormalB;
      result.m_enum = LODWORD(FLOAT_0_0085937502);
      qin.m_quad.m128_i32[0] = m_manifoldNormalB;
      v60 = 0;
      qin.m_quad.m128_i32[1] = m_manifoldNormalB >> 8;
      qin.m_quad.m128_i32[2] = HIWORD(m_manifoldNormalB);
      qin.m_quad.m128_i32[3] = HIBYTE(m_manifoldNormalB);
      v68 = _mm_mul_ps(
              _mm_cvtepi32_ps(_mm_sub_epi32(_mm_and_si128(_mm_load_si128((const __m128i *)&_xmm), (__m128i)qin.m_quad), (__m128i)_xmm)),
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0085937502), (__m128)LODWORD(FLOAT_0_0085937502), 0));
      v69 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v68, v68, 85), this->m_aTb.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v68, v68, 0), this->m_aTb.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v68, v68, 170), this->m_aTb.m_rotation.m_col2.m_quad)),
              manifold->m_manifoldNormalA.m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v69, v69, 85).m128_f32[0] + _mm_shuffle_ps(v69, v69, 0).m128_f32[0])
                 + _mm_shuffle_ps(v69, v69, 170).m128_f32[0]) < _mm_shuffle_ps(
                                                                  (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_manifoldConsistencyCheckAngularCosTolerance),
                                                                  (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_manifoldConsistencyCheckAngularCosTolerance),
                                                                  0).m128_f32[0] )
        v60 = 1;
      if ( !v60 && manifold->m_isComplete )
        return;
    }
    else
    {
      v62.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
      v63.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
      v64 = _mm_unpackhi_ps(v63.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
      v65 = _mm_unpacklo_ps(v63.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
      v66 = _mm_movelh_ps(v65, v62.m_quad);
      qin.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(_mm_movehl_ps(v66, v65), v62.m_quad, 212),
                         _mm_shuffle_ps(v61.m_quad, v61.m_quad, 85)),
                       _mm_mul_ps(_mm_shuffle_ps(v61.m_quad, v61.m_quad, 0), v66)),
                     _mm_mul_ps(_mm_shuffle_ps(v61.m_quad, v61.m_quad, 170), _mm_shuffle_ps(v64, v62.m_quad, 228)));
      manifold->m_manifoldNormalA.m_quad = _mm_shuffle_ps(
                                             v61.m_quad,
                                             _mm_unpackhi_ps(v61.m_quad, g_vectorfConstants[0]),
                                             196);
      manifold->m_manifoldNormalB = hkVector4UtilImpl<float>::packQuaternionIntoInt32(&qin);
      v60 = 1;
    }
  }
  else
  {
    v60 = 1;
    manifold->m_manifoldNormalA = (hkVector4f)_mm_srli_si128(
                                                _mm_slli_si128(
                                                  _mm_load_si128((const __m128i *)&manifold->m_manifoldNormalA),
                                                  4),
                                                4);
  }
  if ( manifold->m_numPoints )
  {
    p_qin = &qin;
    result.m_enum = LODWORD(FLOAT_0_050000001);
    v71 = _mm_sub_ps(
            v12,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0),
              _mm_shuffle_ps(this->m_tolerance4.m_quad, this->m_tolerance4.m_quad, 0)));
    qin.m_quad = _mm_shuffle_ps(v71, _mm_unpackhi_ps(v71, (__m128)xmmword_141A712A0), 196);
  }
  else
  {
    p_qin = &this->m_tolerance4;
  }
  if ( hkpBoxBoxCollisionDetection::checkIntersection(this, &result, p_qin)->m_enum )
    return;
  memset(&fpp.m_nA, 0, 48);
  HIWORD(result.m_enum) = 0;
  ClosestPoint = (hkpFeatureContactPoint)hkpBoxBoxCollisionDetection::findClosestPoint(
                                           this,
                                           manifold,
                                           (hkpFeatureContactPoint *)&result,
                                           &fpp);
  m_featureIndexA = fpp.m_featureIndexA;
  v74.m_mask = (__m128)fpp.m_normalIsFlipped;
  v75.m_quad = (__m128)fpp.m_nA;
  v76 = ClosestPoint;
  v256 = ClosestPoint;
  if ( !v60 || !*(_DWORD *)&ClosestPoint )
  {
LABEL_57:
    m_enum = result.m_enum;
    goto LABEL_58;
  }
  v77.m_quad = (__m128)manifold->m_manifoldNormalA;
  m_enum = result.m_enum;
  v79 = 0;
  v80.m_quad = v77.m_quad;
  v81 = _mm_cmpeq_epi32((__m128i)fpp.m_normalIsFlipped.m_mask, (__m128i)0i64);
  if ( _mm_shuffle_ps(v77.m_quad, v77.m_quad, 255).m128_f32[0] < 0.0 )
    v79 = 1;
  if ( fpp.m_featureIndexA > 2 )
  {
    if ( fpp.m_featureIndexA > 6 )
    {
      if ( ClosestPoint == 2 )
        v80.m_quad = (__m128)fpp.m_nA;
    }
    else
    {
      v80.m_quad = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(_mm_srli_epi32(v81, 0x1Fu), 0x1Fu),
                     *((__m128 *)&this->m_bodyA + LOBYTE(result.m_enum)));
    }
  }
  else
  {
    v80.m_quad = _mm_xor_ps(
                   (__m128)_mm_slli_epi32(_mm_srli_epi32(v81, 0x1Fu), 0x1Fu),
                   *(&transform.m_quad + LOBYTE(result.m_enum)));
  }
  v82.m_quad = _mm_shuffle_ps(v80.m_quad, _mm_unpackhi_ps(v80.m_quad, v77.m_quad), 196);
  manifold->m_manifoldNormalA = (hkVector4f)v82.m_quad;
  if ( v79 )
  {
    v83 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v82.m_quad, v82.m_quad, 85), this->m_wTa->m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v82.m_quad, v82.m_quad, 0), this->m_wTa->m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v82.m_quad, v82.m_quad, 170), this->m_wTa->m_rotation.m_col2.m_quad));
    LODWORD(v84) = _mm_shuffle_ps(
                     (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_contactNormalAngularCosTolerance),
                     (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_contactNormalAngularCosTolerance),
                     0).m128_u32[0];
    if ( manifold->m_numPoints )
    {
      v86 = manifold;
      v85 = (__int64)((unsigned __int128)(((char *)this->m_result->m_firstFreeContactPoint.m_storage
                                         - (char *)this->m_result
                                         - 16)
                                        * (__int128)0x2AAAAAAAAAAAAAABi64) >> 64) >> 3;
      v87 = (int)(v85 + (v85 >> 63) - (unsigned __int8)manifold->m_numPoints);
      do
      {
        v88 = this->m_result;
        v89 = _mm_mul_ps(v88->m_contactPoints[v87].m_contact.m_separatingNormal.m_quad, v83);
        if ( (float)((float)(_mm_shuffle_ps(v89, v89, 85).m128_f32[0] + _mm_shuffle_ps(v89, v89, 0).m128_f32[0])
                   + _mm_shuffle_ps(v89, v89, 170).m128_f32[0]) >= v84 )
        {
          ++v3;
          v86 = (hkpBoxBoxManifold *)((char *)v86 + 4);
          ++v87;
        }
        else
        {
          m_storage = v88->m_firstFreeContactPoint.m_storage;
          v88->m_contactPoints[v87].m_contact.m_position = v88->m_firstFreeContactPoint.m_storage[-1].m_contact.m_position;
          v88->m_contactPoints[v87].m_contact.m_separatingNormal = m_storage[-1].m_contact.m_separatingNormal;
          v88->m_contactPoints[v87].m_contactPointId = m_storage[-1].m_contactPointId;
          v88->m_contactPoints[v87].m_padding[0] = m_storage[-1].m_padding[0];
          v88->m_contactPoints[v87].m_padding[1] = m_storage[-1].m_padding[1];
          v88->m_contactPoints[v87].m_padding[2] = m_storage[-1].m_padding[2];
          if ( v86->m_contactPoints[0].m_featureIdA <= 6u )
            --manifold->m_faceVertexFeatureCount;
          ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkpConstraintOwner *))this->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
            this->m_contactMgr,
            v86->m_contactPoints[0].m_contactPointId,
            this->m_result->m_constraintOwner.m_storage);
          hkpBoxBoxManifold::removePoint(manifold, v3);
          --this->m_result->m_firstFreeContactPoint.m_storage;
        }
      }
      while ( v3 < (unsigned __int8)manifold->m_numPoints );
      m_enum = result.m_enum;
      v76 = v256;
    }
    if ( manifold->m_numPoints < 2u )
    {
      manifold->m_manifoldNormalA = (hkVector4f)_mm_srli_si128(
                                                  _mm_slli_si128(
                                                    _mm_load_si128((const __m128i *)&manifold->m_manifoldNormalA),
                                                    4),
                                                  4);
      goto LABEL_58;
    }
    v91.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
    v92.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
    v93 = _mm_unpackhi_ps(v92.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
    v94 = _mm_unpacklo_ps(v92.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
    v95 = _mm_movelh_ps(v94, v91.m_quad);
    qin.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(_mm_movehl_ps(v95, v94), v91.m_quad, 212),
                       _mm_shuffle_ps(manifold->m_manifoldNormalA.m_quad, manifold->m_manifoldNormalA.m_quad, 85)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(manifold->m_manifoldNormalA.m_quad, manifold->m_manifoldNormalA.m_quad, 0),
                       v95)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(v93, v91.m_quad, 228),
                     _mm_shuffle_ps(manifold->m_manifoldNormalA.m_quad, manifold->m_manifoldNormalA.m_quad, 170)));
    manifold->m_manifoldNormalB = hkVector4UtilImpl<float>::packQuaternionIntoInt32(&qin);
    manifold->m_manifoldNormalA.m_quad = _mm_shuffle_ps(
                                           manifold->m_manifoldNormalA.m_quad,
                                           _mm_unpackhi_ps(manifold->m_manifoldNormalA.m_quad, g_vectorfConstants[0]),
                                           196);
    goto LABEL_57;
  }
LABEL_58:
  if ( v76 != 2 )
    return;
  v96.m_quad = (__m128)fpp.m_vB;
  v97.m_quad = (__m128)fpp.m_vA;
  if ( m_enum > 6u )
    goto LABEL_68;
  if ( m_enum > 2u )
  {
    m_wTb = this->m_wTa;
    v99 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 85);
    v100 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 0);
    v101 = _mm_shuffle_ps(fpp.m_vA.m_quad, fpp.m_vA.m_quad, 170);
  }
  else
  {
    m_wTb = this->m_wTb;
    v99 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 85);
    v100 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 0);
    v101 = _mm_shuffle_ps(fpp.m_vB.m_quad, fpp.m_vB.m_quad, 170);
  }
  v102 = 0;
  v103 = _mm_shuffle_ps(this->m_tolerance4.m_quad, this->m_tolerance4.m_quad, 0).m128_f32[0];
  v104 = _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(v99, m_wTb->m_rotation.m_col1.m_quad),
               _mm_mul_ps(v100, m_wTb->m_rotation.m_col0.m_quad)),
             _mm_mul_ps(v101, m_wTb->m_rotation.m_col2.m_quad)),
           m_wTb->m_translation.m_quad);
  v105 = (float)(v103 * v103) + 0.00000011920929;
  if ( !manifold->m_numPoints )
  {
LABEL_68:
    if ( manifold->m_numPoints >= 8u )
      return;
    v110 = hkpBoxBoxManifold::addPoint(manifold, this->m_bodyA, this->m_bodyB, (hkpFeatureContactPoint *)&result);
    v111 = v110;
    if ( v110 >= 0 )
    {
      v112 = this->m_result->m_firstFreeContactPoint.m_storage;
      if ( m_featureIndexA > 2 )
      {
        v115 = _mm_shuffle_ps(v97.m_quad, v97.m_quad, 85);
        v116 = _mm_shuffle_ps(v97.m_quad, v97.m_quad, 0);
        v117 = _mm_shuffle_ps(v97.m_quad, v97.m_quad, 170);
        if ( m_featureIndexA > 6 )
        {
          v112->m_contactPointId = HIWORD(result.m_enum);
          v112->m_contact.m_position.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(v115, this->m_wTa->m_rotation.m_col1.m_quad),
                                                    _mm_mul_ps(v116, this->m_wTa->m_rotation.m_col0.m_quad)),
                                                  _mm_mul_ps(v117, this->m_wTa->m_rotation.m_col2.m_quad)),
                                                this->m_wTa->m_translation.m_quad);
          v120 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v75.m_quad, v75.m_quad, 85), this->m_wTa->m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v75.m_quad, v75.m_quad, 0), this->m_wTa->m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v75.m_quad, v75.m_quad, 170), this->m_wTa->m_rotation.m_col2.m_quad));
          v112->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                        v120,
                                                        _mm_unpackhi_ps(v120, fpp.m_distance.m_real),
                                                        196);
        }
        else
        {
          m_enum_low = LOBYTE(result.m_enum);
          v112->m_contactPointId = HIWORD(result.m_enum);
          v112->m_contact.m_position.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(v115, this->m_wTa->m_rotation.m_col1.m_quad),
                                                    _mm_mul_ps(v116, this->m_wTa->m_rotation.m_col0.m_quad)),
                                                  _mm_mul_ps(v117, this->m_wTa->m_rotation.m_col2.m_quad)),
                                                this->m_wTa->m_translation.m_quad);
          v119 = _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(_mm_cmpeq_epi32((__m128i)v74.m_mask, (__m128i)0i64), 0x1Fu),
                             0x1Fu),
                   *(&this->m_wTb[-1].m_rotation.m_col0.m_quad + m_enum_low));
          v112->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                        v119,
                                                        _mm_unpackhi_ps(v119, fpp.m_distance.m_real),
                                                        196);
        }
      }
      else
      {
        v113 = LOBYTE(result.m_enum);
        v112->m_contactPointId = HIWORD(result.m_enum);
        v112->m_contact.m_position.m_quad = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(v96.m_quad, v96.m_quad, 85),
                                                    this->m_wTb->m_rotation.m_col1.m_quad),
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(v96.m_quad, v96.m_quad, 0),
                                                    this->m_wTb->m_rotation.m_col0.m_quad)),
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(v96.m_quad, v96.m_quad, 170),
                                                  this->m_wTb->m_rotation.m_col2.m_quad)),
                                              this->m_wTb->m_translation.m_quad);
        v114 = _mm_xor_ps(
                 (__m128)_mm_slli_epi32(
                           _mm_srli_epi32(_mm_cmpeq_epi32((__m128i)v74.m_mask, (__m128i)0i64), 0x1Fu),
                           0x1Fu),
                 *(&this->m_wTa->m_rotation.m_col0.m_quad + v113));
        v112->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                      v114,
                                                      _mm_unpackhi_ps(v114, fpp.m_distance.m_real),
                                                      196);
      }
      if ( manifold->m_numPoints > 1u )
      {
        v121 = _mm_mul_ps(
                 this->m_result->m_firstFreeContactPoint.m_storage[-1].m_contact.m_separatingNormal.m_quad,
                 v112->m_contact.m_separatingNormal.m_quad);
        if ( (float)((float)(_mm_shuffle_ps(v121, v121, 85).m128_f32[0] + _mm_shuffle_ps(v121, v121, 0).m128_f32[0])
                   + _mm_shuffle_ps(v121, v121, 170).m128_f32[0]) <= 0.0 )
        {
          hkpBoxBoxManifold::removePoint(manifold, v110);
          return;
        }
      }
      v122 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
               this->m_contactMgr,
               this->m_bodyA,
               this->m_bodyB,
               this->m_env,
               this->m_result,
               0i64,
               v112);
      manifold->m_contactPoints[v111].m_contactPointId = v122;
      if ( v122 == 0xFFFF )
      {
        hkpBoxBoxManifold::removePoint(manifold, v111);
      }
      else
      {
        ++this->m_result->m_firstFreeContactPoint.m_storage;
        HIWORD(result.m_enum) = manifold->m_contactPoints[v111].m_contactPointId;
        v112->m_contactPointId = HIWORD(result.m_enum);
        if ( LOBYTE(result.m_enum) <= 6u )
          ++manifold->m_faceVertexFeatureCount;
      }
    }
    fcp = (hkpFeatureContactPoint)result.m_enum;
    m_numPoints = manifold->m_numPoints;
    if ( !m_numPoints )
      return;
    v124 = m_numPoints;
    v125 = this->m_wTa;
    p_m_separatingNormal = &this->m_result->m_contactPoints[(int)((char *)this->m_result->m_firstFreeContactPoint.m_storage
                                                                - (char *)this->m_result
                                                                - 16)
                                                          / 48
                                                          - m_numPoints].m_contact.m_separatingNormal;
    v127 = v125->m_rotation.m_col2.m_quad;
    v128 = p_m_separatingNormal->m_quad;
    v129 = _mm_unpacklo_ps(v125->m_rotation.m_col0.m_quad, v125->m_rotation.m_col1.m_quad);
    v130 = _mm_shuffle_ps(_mm_unpackhi_ps(v125->m_rotation.m_col0.m_quad, v125->m_rotation.m_col1.m_quad), v127, 228);
    v131 = this->m_wTb;
    v132 = v131->m_rotation.m_col2.m_quad;
    v133 = _mm_shuffle_ps(v128, v128, 85);
    v134 = _mm_shuffle_ps(p_m_separatingNormal->m_quad, p_m_separatingNormal->m_quad, 0);
    v135 = _mm_shuffle_ps(v128, v128, 170);
    v136 = _mm_movelh_ps(v129, v127);
    v137 = _mm_unpacklo_ps(v131->m_rotation.m_col0.m_quad, v131->m_rotation.m_col1.m_quad);
    v138 = _mm_movelh_ps(v137, v132);
    v139 = (__m128i)_mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v138, v137), v132, 212), v133),
                        _mm_mul_ps(v138, v134)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          _mm_unpackhi_ps(v131->m_rotation.m_col0.m_quad, v131->m_rotation.m_col1.m_quad),
                          v132,
                          228),
                        v135));
    v140 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v139, 1u), 1u);
    v141 = (__m128i)_mm_xor_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v136, v129), v127, 212), v133),
                          _mm_mul_ps(v136, v134)),
                        _mm_mul_ps(v130, v135)),
                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v142 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v141, 1u), 1u);
    LODWORD(v131) = _mm_movemask_ps(
                      _mm_and_ps(
                        _mm_cmple_ps(
                          _mm_max_ps(
                            _mm_shuffle_ps(v142, v142, 170),
                            _mm_max_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0))),
                          v142),
                        (__m128)xmmword_141A86090));
    v143 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[(int)v131];
    v144 = _mm_shuffle_ps(
             (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_coplanerAngularCosTolerance),
             (__m128)LODWORD(hkpBoxBoxCollisionDetection::m_coplanerAngularCosTolerance),
             0).m128_f32[0];
    planeMaskA = 16 * (1 << hkVector4Comparison_maskToLastIndex[(int)v131]);
    v145 = hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                 _mm_and_ps(
                                                   _mm_cmple_ps(
                                                     _mm_max_ps(
                                                       _mm_shuffle_ps(v140, v140, 170),
                                                       _mm_max_ps(
                                                         _mm_shuffle_ps(v140, v140, 85),
                                                         _mm_shuffle_ps(v140, v140, 0))),
                                                     v140),
                                                   (__m128)xmmword_141A86090))];
    v146 = 0;
    v147 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v143];
    LODWORD(v148) = 16 * (1 << v145);
    v149 = _mm_and_ps(v142, v147);
    planeMaskB = (int)v148;
    v150 = _mm_or_ps(_mm_shuffle_ps(v149, v149, 78), v149);
    v151 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v145];
    v152 = 0;
    v153 = _mm_and_ps(v140, v151);
    v154 = _mm_or_ps(_mm_shuffle_ps(v153, v153, 78), v153);
    LODWORD(v155) = _mm_shuffle_ps(v150, v150, 177).m128_u32[0] | v150.m128_i32[0];
    if ( COERCE_FLOAT(_mm_shuffle_ps(v154, v154, 177).m128_u32[0] | v154.m128_i32[0]) < v144 )
      v146 = 1;
    if ( v155 < v144 )
      v152 = 1;
    if ( v152 | v146 )
      return;
    v156 = _mm_and_ps(v151, this->m_dinB.m_quad);
    v251.m_contactPointId = 0;
    v157 = _mm_and_ps(this->m_dinA.m_quad, v147);
    v158 = 16 * (_mm_movemask_ps(_mm_cmplt_ps((__m128)v139, (__m128)0i64)) & 7);
    v256 = (hkpFeatureContactPoint)v158;
    v159 = _mm_or_ps(_mm_shuffle_ps(v157, v157, 78), v157);
    v160 = _mm_or_ps(_mm_shuffle_ps(v156, v156, 78), v156);
    v161 = _mm_cmplt_ps(_mm_or_ps(_mm_shuffle_ps(v160, v160, 177), v160), (__m128)0i64);
    if ( _mm_movemask_ps(_mm_cmplt_ps(_mm_or_ps(_mm_shuffle_ps(v159, v159, 177), v159), (__m128)0i64)) )
    {
      v158 |= 8u;
      v256 = (hkpFeatureContactPoint)v158;
    }
    fcp.m_featureIdB = v158;
    v162 = 16 * (_mm_movemask_ps(_mm_cmplt_ps((__m128)v141, (__m128)0i64)) & 7);
    v252 = v162;
    if ( _mm_movemask_ps(v161) )
    {
      LOBYTE(v162) = v162 | 8;
      v252 = v162;
    }
    v163 = query.m_quad;
    v251.m_featureIdB = v162;
    fcp.m_featureIdA = v143;
    v251.m_featureIdA = v145 + 4;
    v164 = v124;
    do
    {
      v165 = p_m_separatingNormal->m_quad;
      p_m_separatingNormal += 3;
      v163 = _mm_min_ps(v163, _mm_shuffle_ps(v165, v165, 255));
      --v164;
    }
    while ( v164 );
    v166 = fcp;
    v167 = cycleMask;
    while ( 1 )
    {
      v168 = *v167;
      if ( ((unsigned __int16)v148 & *v167) == 0 )
      {
        v169 = (unsigned __int8)manifold->m_numPoints;
        fcp = v166;
        v170 = v168 ^ v158 | v166.m_featureIdB & 0xF;
        fcp.m_featureIdB = v170;
        v171 = v169 - 1;
        if ( v169 - 1 < 0 )
        {
LABEL_100:
          if ( (v170 & 8) != 0 )
            v172 = (__m128i)xmmword_141A86110;
          else
            v172 = 0i64;
          v173 = _mm_mul_ps(
                   _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(hkVector4fComparison_maskToComparison_373[(v170 >> 4) & 7], 0x1Fu),
                               0x1Fu),
                     query.m_quad),
                   this->m_radiusB.m_quad);
          v174 = _mm_shuffle_ps(v173, v173, 85);
          v175 = _mm_shuffle_ps(v173, v173, 0);
          v176 = _mm_shuffle_ps(v173, v173, 170);
          v177 = (__m128i)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(v175, this->m_aTb.m_rotation.m_col0.m_quad),
                                _mm_mul_ps(v174, this->m_aTb.m_rotation.m_col1.m_quad)),
                              _mm_mul_ps(this->m_aTb.m_rotation.m_col2.m_quad, v176)),
                            this->m_aTb.m_translation.m_quad);
          if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v177, 1u), 1u), this->m_keepRadiusA.m_quad)) & 7) != 7 )
            goto LABEL_138;
          v178 = _mm_and_ps(
                   _mm_sub_ps(
                     _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v172, 0x1Fu), 0x1Fu), (__m128)v177),
                     this->m_radiusA.m_quad),
                   (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)v166.m_featureIdA]);
          v179 = _mm_or_ps(_mm_shuffle_ps(v178, v178, 78), v178);
          v180 = _mm_or_ps(_mm_shuffle_ps(v179, v179, 177), v179);
          if ( v180.m128_f32[0] < (float)(v163.m128_f32[0] - 0.00000011920929) )
            goto LABEL_138;
          if ( v166.m_featureIdA <= 6u )
          {
            if ( v166.m_featureIdA > 2u )
            {
              v181 = this->m_wTa;
              v183 = _mm_mul_ps(_mm_shuffle_ps((__m128)v177, (__m128)v177, 85), v181->m_rotation.m_col1.m_quad);
              v184 = _mm_mul_ps(_mm_shuffle_ps((__m128)v177, (__m128)v177, 170), v181->m_rotation.m_col2.m_quad);
              v182 = _mm_shuffle_ps((__m128)v177, (__m128)v177, 0);
            }
            else
            {
              v181 = this->m_wTb;
              v182 = v175;
              v183 = _mm_mul_ps(v181->m_rotation.m_col1.m_quad, v174);
              v184 = _mm_mul_ps(v181->m_rotation.m_col2.m_quad, v176);
            }
            v185 = 0;
            v186 = _mm_shuffle_ps(this->m_tolerance4.m_quad, this->m_tolerance4.m_quad, 0).m128_f32[0];
            v187 = _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(v183, _mm_mul_ps(v182, v181->m_rotation.m_col0.m_quad)), v184),
                     v181->m_translation.m_quad);
            v188 = (float)(v186 * v186) + 0.00000011920929;
            if ( v169 > 0 )
            {
              v189 = 0i64;
              v190 = manifold;
              while ( 1 )
              {
                if ( v190->m_contactPoints[0].m_featureIdA <= 6u )
                {
                  v191 = _mm_sub_ps(v187, this->m_result->m_contactPoints[v189].m_contact.m_position.m_quad);
                  v192 = _mm_mul_ps(v191, v191);
                  if ( (float)((float)(_mm_shuffle_ps(v192, v192, 85).m128_f32[0]
                                     + _mm_shuffle_ps(v192, v192, 0).m128_f32[0])
                             + _mm_shuffle_ps(v192, v192, 170).m128_f32[0]) <= v188 )
                    break;
                }
                ++v185;
                v190 = (hkpBoxBoxManifold *)((char *)v190 + 4);
                ++v189;
                if ( v185 >= v169 )
                  goto LABEL_114;
              }
LABEL_138:
              LOBYTE(v158) = v256.m_featureIdA;
              goto LABEL_125;
            }
          }
LABEL_114:
          if ( (unsigned __int8)v169 >= 8u )
            goto LABEL_138;
          v193 = hkpBoxBoxManifold::addPoint(manifold, this->m_bodyA, this->m_bodyB, &fcp);
          v194 = v193;
          if ( v193 >= 0 )
          {
            v148 = this->m_result->m_firstFreeContactPoint.m_storage;
            if ( (unsigned __int8)v166.m_featureIdA > 2u )
            {
              v197 = _mm_shuffle_ps((__m128)v177, (__m128)v177, 85);
              v198 = _mm_shuffle_ps((__m128)v177, (__m128)v177, 0);
              v199 = _mm_shuffle_ps((__m128)v177, (__m128)v177, 170);
              if ( (unsigned __int8)v166.m_featureIdA > 6u )
              {
                v148->m_contactPointId = fcp.m_contactPointId;
                v148->m_contact.m_position.m_quad = _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_mul_ps(v197, this->m_wTa->m_rotation.m_col1.m_quad),
                                                          _mm_mul_ps(v198, this->m_wTa->m_rotation.m_col0.m_quad)),
                                                        _mm_mul_ps(v199, this->m_wTa->m_rotation.m_col2.m_quad)),
                                                      this->m_wTa->m_translation.m_quad);
                v202 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 85),
                             this->m_wTa->m_rotation.m_col1.m_quad),
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 0),
                             this->m_wTa->m_rotation.m_col0.m_quad)),
                         _mm_mul_ps(
                           _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 170),
                           this->m_wTa->m_rotation.m_col2.m_quad));
                v148->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v202, _mm_unpackhi_ps(v202, v180), 196);
              }
              else
              {
                v200 = (unsigned __int8)fcp.m_featureIdA;
                v148->m_contactPointId = fcp.m_contactPointId;
                v148->m_contact.m_position.m_quad = _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_mul_ps(v197, this->m_wTa->m_rotation.m_col1.m_quad),
                                                          _mm_mul_ps(v198, this->m_wTa->m_rotation.m_col0.m_quad)),
                                                        _mm_mul_ps(v199, this->m_wTa->m_rotation.m_col2.m_quad)),
                                                      this->m_wTa->m_translation.m_quad);
                v201 = _mm_xor_ps(
                         (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v172, (__m128i)0i64), 0x1Fu), 0x1Fu),
                         *(&this->m_wTb[-1].m_rotation.m_col0.m_quad + v200));
                v148->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v201, _mm_unpackhi_ps(v201, v180), 196);
              }
            }
            else
            {
              v195 = (unsigned __int8)fcp.m_featureIdA;
              v148->m_contactPointId = fcp.m_contactPointId;
              v148->m_contact.m_position.m_quad = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(this->m_wTb->m_rotation.m_col1.m_quad, v174),
                                                        _mm_mul_ps(this->m_wTb->m_rotation.m_col0.m_quad, v175)),
                                                      _mm_mul_ps(this->m_wTb->m_rotation.m_col2.m_quad, v176)),
                                                    this->m_wTb->m_translation.m_quad);
              v196 = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v172, (__m128i)0i64), 0x1Fu), 0x1Fu),
                       *(&this->m_wTa->m_rotation.m_col0.m_quad + v195));
              v148->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v196, _mm_unpackhi_ps(v196, v180), 196);
            }
            if ( manifold->m_numPoints <= 1u
              || (v203 = _mm_mul_ps(
                           this->m_result->m_firstFreeContactPoint.m_storage[-1].m_contact.m_separatingNormal.m_quad,
                           v148->m_contact.m_separatingNormal.m_quad),
                  (float)((float)(_mm_shuffle_ps(v203, v203, 85).m128_f32[0] + _mm_shuffle_ps(v203, v203, 0).m128_f32[0])
                        + _mm_shuffle_ps(v203, v203, 170).m128_f32[0]) > 0.0) )
            {
              v211 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                       this->m_contactMgr,
                       this->m_bodyA,
                       this->m_bodyB,
                       this->m_env,
                       this->m_result,
                       0i64,
                       v148);
              manifold->m_contactPoints[v194].m_contactPointId = v211;
              if ( v211 != 0xFFFF )
              {
                LOBYTE(v158) = v256.m_featureIdA;
                ++this->m_result->m_firstFreeContactPoint.m_storage;
                v148->m_contactPointId = manifold->m_contactPoints[v194].m_contactPointId;
                LOWORD(v148) = planeMaskB;
                if ( fcp.m_featureIdA <= 6u )
                  ++manifold->m_faceVertexFeatureCount;
                goto LABEL_125;
              }
            }
            hkpBoxBoxManifold::removePoint(manifold, v194);
            LOWORD(v148) = planeMaskB;
          }
        }
        else
        {
          while ( manifold->m_contactPoints[v171].m_featureIdA != v166.m_featureIdA
               || manifold->m_contactPoints[v171].m_featureIdB != v170 )
          {
            if ( --v171 < 0 )
              goto LABEL_100;
          }
        }
        LOBYTE(v158) = v256.m_featureIdA;
      }
LABEL_125:
      if ( (__int64)++v167 >= (__int64)&unk_141A85FFE )
      {
        v204 = planeMaskA;
        v205 = cycleMask;
        while ( 1 )
        {
          v206 = *v205;
          if ( ((unsigned __int16)v204 & *v205) == 0 )
            break;
LABEL_166:
          if ( (__int64)++v205 >= (__int64)&unk_141A85FFE )
          {
            if ( manifold->m_faceVertexFeatureCount < 4u )
              hkpBoxBoxCollisionDetection::checkCompleteness(this, manifold, v204, planeMaskB);
            else
              manifold->m_isComplete = 1;
            return;
          }
        }
        v207 = (unsigned __int8)manifold->m_numPoints;
        v256 = v251;
        v208 = v252 ^ v206 | v251.m_featureIdB & 0xF;
        v256.m_featureIdB = v208;
        v209 = v207 - 1;
        if ( v207 - 1 >= 0 )
        {
          while ( manifold->m_contactPoints[v209].m_featureIdA != v251.m_featureIdA
               || manifold->m_contactPoints[v209].m_featureIdB != v208 )
          {
            if ( --v209 < 0 )
              goto LABEL_132;
          }
          goto LABEL_165;
        }
LABEL_132:
        if ( (v252 ^ (unsigned __int8)v206) & 8 | v251.m_featureIdB & 8 )
          v210 = (__m128i)xmmword_141A86110;
        else
          v210 = 0i64;
        v212.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
        v213.m_quad = (__m128)this->m_aTb.m_rotation.m_col0;
        v214 = _mm_unpackhi_ps(v213.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
        v215 = _mm_unpacklo_ps(v213.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
        v216 = _mm_movelh_ps(v215, v212.m_quad);
        v217 = _mm_mul_ps(
                 _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(hkVector4fComparison_maskToComparison_373[(v208 >> 4) & 7], 0x1Fu),
                             0x1Fu),
                   query.m_quad),
                 this->m_radiusA.m_quad);
        v218 = _mm_sub_ps(v217, this->m_aTb.m_translation.m_quad);
        v219 = (__m128i)_mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(_mm_movehl_ps(v216, v215), v212.m_quad, 212),
                              _mm_shuffle_ps(v218, v218, 85)),
                            _mm_mul_ps(_mm_shuffle_ps(v218, v218, 0), v216)),
                          _mm_mul_ps(_mm_shuffle_ps(v218, v218, 170), _mm_shuffle_ps(v214, v212.m_quad, 228)));
        if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v219, 1u), 1u), this->m_keepRadiusB.m_quad)) & 7) != 7 )
          goto LABEL_165;
        v220 = (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_cmpeq_epi32(v210, (__m128i)0i64), 0x1Fu), 0x1Fu);
        v221 = _mm_and_ps(
                 _mm_sub_ps(_mm_xor_ps(v220, (__m128)v219), this->m_radiusB.m_quad),
                 (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)v251.m_featureIdA - 4]);
        v222 = _mm_or_ps(_mm_shuffle_ps(v221, v221, 78), v221);
        v223 = _mm_or_ps(_mm_shuffle_ps(v222, v222, 177), v222);
        if ( v223.m128_f32[0] < (float)(v163.m128_f32[0] - 0.00000011920929) )
          goto LABEL_165;
        if ( v251.m_featureIdA <= 6u )
        {
          if ( v251.m_featureIdA > 2u )
          {
            v224 = this->m_wTa;
            v225 = _mm_shuffle_ps(v217, v217, 85);
            v226 = _mm_shuffle_ps(v217, v217, 0);
            v227 = _mm_shuffle_ps(v217, v217, 170);
          }
          else
          {
            v224 = this->m_wTb;
            v225 = _mm_shuffle_ps((__m128)v219, (__m128)v219, 85);
            v226 = _mm_shuffle_ps((__m128)v219, (__m128)v219, 0);
            v227 = _mm_shuffle_ps((__m128)v219, (__m128)v219, 170);
          }
          v228 = 0;
          v229 = _mm_shuffle_ps(this->m_tolerance4.m_quad, this->m_tolerance4.m_quad, 0).m128_f32[0];
          v230 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(v225, v224->m_rotation.m_col1.m_quad),
                       _mm_mul_ps(v226, v224->m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(v227, v224->m_rotation.m_col2.m_quad)),
                   v224->m_translation.m_quad);
          v231 = (float)(v229 * v229) + 0.00000011920929;
          if ( v207 > 0 )
          {
            v232 = 0i64;
            v233 = manifold;
            do
            {
              if ( v233->m_contactPoints[0].m_featureIdA <= 6u )
              {
                v234 = _mm_sub_ps(v230, this->m_result->m_contactPoints[v232].m_contact.m_position.m_quad);
                v235 = _mm_mul_ps(v234, v234);
                if ( (float)((float)(_mm_shuffle_ps(v235, v235, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v235, v235, 0).m128_f32[0])
                           + _mm_shuffle_ps(v235, v235, 170).m128_f32[0]) <= v231 )
                  goto LABEL_165;
              }
              ++v228;
              v233 = (hkpBoxBoxManifold *)((char *)v233 + 4);
              ++v232;
            }
            while ( v228 < v207 );
          }
        }
        if ( (unsigned __int8)v207 >= 8u
          || (v236 = hkpBoxBoxManifold::addPoint(manifold, this->m_bodyA, this->m_bodyB, &v256), v237 = v236, v236 < 0) )
        {
LABEL_165:
          v204 = planeMaskA;
          goto LABEL_166;
        }
        v238 = this->m_result->m_firstFreeContactPoint.m_storage;
        if ( (unsigned __int8)v251.m_featureIdA <= 2u )
        {
          v239 = (unsigned __int8)v256.m_featureIdA;
          v238->m_contactPointId = v256.m_contactPointId;
          v240 = v239;
          v238->m_contact.m_position.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps((__m128)v219, (__m128)v219, 85),
                                                      this->m_wTb->m_rotation.m_col1.m_quad),
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps((__m128)v219, (__m128)v219, 0),
                                                      this->m_wTb->m_rotation.m_col0.m_quad)),
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps((__m128)v219, (__m128)v219, 170),
                                                    this->m_wTb->m_rotation.m_col2.m_quad)),
                                                this->m_wTb->m_translation.m_quad);
          v241 = this->m_wTa;
          goto LABEL_157;
        }
        v242 = _mm_shuffle_ps(v217, v217, 85);
        v243 = _mm_shuffle_ps(v217, v217, 0);
        v244 = _mm_shuffle_ps(v217, v217, 170);
        if ( (unsigned __int8)v251.m_featureIdA > 6u )
        {
          v238->m_contactPointId = v256.m_contactPointId;
          v238->m_contact.m_position.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(v242, this->m_wTa->m_rotation.m_col1.m_quad),
                                                    _mm_mul_ps(v243, this->m_wTa->m_rotation.m_col0.m_quad)),
                                                  _mm_mul_ps(v244, this->m_wTa->m_rotation.m_col2.m_quad)),
                                                this->m_wTa->m_translation.m_quad);
          v247 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps((__m128)0i64, (__m128)0i64, 85), this->m_wTa->m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps((__m128)0i64, (__m128)0i64, 0), this->m_wTa->m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps((__m128)0i64, (__m128)0i64, 170), this->m_wTa->m_rotation.m_col2.m_quad));
          v238->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v247, _mm_unpackhi_ps(v247, v223), 196);
        }
        else
        {
          v245 = (unsigned __int8)v256.m_featureIdA;
          v238->m_contactPointId = v256.m_contactPointId;
          v240 = v245 - 4;
          v238->m_contact.m_position.m_quad = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(v242, this->m_wTa->m_rotation.m_col1.m_quad),
                                                    _mm_mul_ps(v243, this->m_wTa->m_rotation.m_col0.m_quad)),
                                                  _mm_mul_ps(v244, this->m_wTa->m_rotation.m_col2.m_quad)),
                                                this->m_wTa->m_translation.m_quad);
          v241 = this->m_wTb;
LABEL_157:
          v246 = _mm_xor_ps(*(&v241->m_rotation.m_col0.m_quad + v240), v220);
          v238->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v246, _mm_unpackhi_ps(v246, v223), 196);
        }
        if ( manifold->m_numPoints <= 1u
          || (v248 = _mm_mul_ps(
                       this->m_result->m_firstFreeContactPoint.m_storage[-1].m_contact.m_separatingNormal.m_quad,
                       v238->m_contact.m_separatingNormal.m_quad),
              (float)((float)(_mm_shuffle_ps(v248, v248, 85).m128_f32[0] + _mm_shuffle_ps(v248, v248, 0).m128_f32[0])
                    + _mm_shuffle_ps(v248, v248, 170).m128_f32[0]) > 0.0) )
        {
          v249 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                   this->m_contactMgr,
                   this->m_bodyA,
                   this->m_bodyB,
                   this->m_env,
                   this->m_result,
                   0i64,
                   v238);
          manifold->m_contactPoints[v237].m_contactPointId = v249;
          if ( v249 != 0xFFFF )
          {
            v204 = planeMaskA;
            ++this->m_result->m_firstFreeContactPoint.m_storage;
            v238->m_contactPointId = manifold->m_contactPoints[v237].m_contactPointId;
            if ( v256.m_featureIdA <= 6u )
              ++manifold->m_faceVertexFeatureCount;
            goto LABEL_166;
          }
        }
        hkpBoxBoxManifold::removePoint(manifold, v237);
        goto LABEL_165;
      }
    }
  }
  v106 = 0i64;
  v107 = manifold;
  while ( 1 )
  {
    if ( v107->m_contactPoints[0].m_featureIdA <= 6u )
    {
      v108 = _mm_sub_ps(v104, this->m_result->m_contactPoints[v106].m_contact.m_position.m_quad);
      v109 = _mm_mul_ps(v108, v108);
      if ( (float)((float)(_mm_shuffle_ps(v109, v109, 85).m128_f32[0] + _mm_shuffle_ps(v109, v109, 0).m128_f32[0])
                 + _mm_shuffle_ps(v109, v109, 170).m128_f32[0]) <= v105 )
        break;
    }
    ++v102;
    v107 = (hkpBoxBoxManifold *)((char *)v107 + 4);
    ++v106;
    if ( v102 >= (unsigned __int8)manifold->m_numPoints )
      goto LABEL_68;
  }
}

