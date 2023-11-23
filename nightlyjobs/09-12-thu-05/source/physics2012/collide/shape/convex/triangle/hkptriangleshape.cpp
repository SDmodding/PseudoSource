// File Line: 33
// RVA: 0xD09FF0
void __fastcall hkpTriangleShape::hkpTriangleShape(hkpTriangleShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape::hkpConvexShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpTriangleShape::`vftable;
  this->m_type.m_storage = 2;
}

// File Line: 39
// RVA: 0xD0B3D0
void __fastcall hkpTriangleShape::getFirstVertex(hkpTriangleShape *this, hkVector4f *v)
{
  *v = this->m_vertexA;
}

// File Line: 46
// RVA: 0xD0A020
void __fastcall hkpTriangleShape::getSupportingVertex(
        hkpTriangleShape *this,
        hkVector4f *direction,
        hkcdVertex *supportingVertexOut)
{
  hkVector4f v3; // xmm3
  hkVector4f v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __int64 v10; // r8
  __m128 v11; // xmm2

  v3.m_quad = (__m128)this->m_vertexC;
  v5.m_quad = (__m128)this->m_vertexA;
  v6 = _mm_unpackhi_ps(v5.m_quad, this->m_vertexB.m_quad);
  v7 = _mm_unpacklo_ps(v5.m_quad, this->m_vertexB.m_quad);
  v8 = _mm_movelh_ps(v7, v3.m_quad);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_shuffle_ps(direction->m_quad, direction->m_quad, 85),
             _mm_shuffle_ps(_mm_movehl_ps(v8, v7), v3.m_quad, 212)),
           _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 0), v8)),
         _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 170), _mm_shuffle_ps(v6, v3.m_quad, 228)));
  v10 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v9, v9, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v9, v9, 85),
                                                                       _mm_shuffle_ps(v9, v9, 0))),
                                                                   v9),
                                                                 (__m128)xmmword_141A81E40))];
  *supportingVertexOut = *((hkcdVertex *)&this->m_vertexA + v10);
  v11 = _mm_mul_ps(this->m_extrusion.m_quad, direction->m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
             + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) > 0.0 )
  {
    LODWORD(v10) = v10 + 3;
    supportingVertexOut->m_quad = _mm_add_ps(this->m_extrusion.m_quad, supportingVertexOut->m_quad);
  }
  supportingVertexOut->m_quad.m128_i32[3] = v10 | 0x3F000000;
}

// File Line: 68
// RVA: 0xD0A110
void __fastcall hkpTriangleShape::convertVertexIdsToVertices(
        hkpTriangleShape *this,
        const unsigned __int16 *ids,
        int numIds,
        hkcdVertex *verticesOut)
{
  int i; // r8d
  __int64 v5; // rax
  __m128 v6; // xmm1
  __m128 v7; // xmm0

  for ( i = numIds - 1; i >= 0; verticesOut[-1].m_quad.m128_i32[3] = *(ids - 1) | 0x3F000000 )
  {
    v5 = *ids;
    ++verticesOut;
    ++ids;
    v6 = *(&this->m_vertexA.m_quad + mod3Table[v5].m_storage);
    verticesOut[-1] = (hkcdVertex)v6;
    v7 = (__m128)LODWORD(addExtrusionTable[*(ids - 1)]);
    verticesOut[-1].m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), this->m_extrusion.m_quad), v6);
    --i;
  }
}

// File Line: 80
// RVA: 0xD0A820
void __fastcall hkpTriangleShape::getCentre(hkpTriangleShape *this, hkVector4f *centreOut)
{
  __m128 v2; // xmm0
  __m128 v3; // xmm1

  v2 = _mm_add_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  *centreOut = (hkVector4f)v2;
  v3 = _mm_add_ps(this->m_vertexC.m_quad, v2);
  *centreOut = (hkVector4f)v3;
  centreOut->m_quad = _mm_mul_ps(v3, (__m128)xmmword_141A711C0);
}

// File Line: 88
// RVA: 0xD0B3E0
__int64 __fastcall getSingleEdgeBitcode(unsigned __int16 triangleEdgesBitcode, char edgeIndex)
{
  return (triangleEdgesBitcode >> (5 * edgeIndex)) & 0x1F;
}

// File Line: 99
// RVA: 0xD0B400
void __fastcall calcAntiClockwiseTriangleNormal(
        hkVector4f *vertex0,
        hkVector4f *vertex1,
        hkVector4f *vertex2,
        hkVector4f *normal)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm5
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2

  v4 = _mm_sub_ps(vertex2->m_quad, vertex1->m_quad);
  v5 = _mm_sub_ps(vertex1->m_quad, vertex0->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  normal->m_quad = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmple_ps(v9, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                         _mm_mul_ps(*(__m128 *)_xmm, v10))),
                     v7);
}

// File Line: 115
// RVA: 0xD0A180
__int64 __fastcall hkpTriangleShape::weldContactPoint(
        hkpTriangleShape *this,
        unsigned __int16 *featurePoints,
        unsigned __int64 numFeaturePoints,
        hkVector4f *contactPointWs,
        hkTransformf *thisObjTransform,
        hkpConvexShape *collidingShape,
        hkTransformf *collidingTransform,
        hkVector4f *separatingNormalInOut)
{
  __int64 m_storage; // r11
  char *v10; // rbx
  __int64 result; // rax
  __int64 v14; // r9
  unsigned __int8 v15; // al
  __int64 v16; // rdx
  __int64 v17; // rsi
  __int64 v18; // rbp
  __m128 m_quad; // xmm5
  hkVector4f v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm13
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm13
  __m128 v27; // xmm1
  __m128 v28; // xmm8
  __m128 v29; // xmm8
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm8
  __m128 v34; // xmm6
  __m128 v35; // xmm9
  __m128 v36; // xmm10
  int v37; // eax
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm10
  float v42; // xmm1_4
  hkpWeldingUtility::SinCosTableEntry *v43; // rdx
  __m128 v45; // xmm4
  __m128 v46; // xmm0
  __m128 v47; // xmm4
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 v52; // xmm7
  __m128 v53; // xmm6
  __m128 v54; // xmm6
  __m128 v55; // xmm2
  unsigned int *v56; // r8
  int v57; // ecx
  unsigned __int64 v58; // rdx
  __m128 v59; // xmm1
  __m128 v60; // xmm5
  __m128 v61; // xmm0
  __m128 v62; // xmm5
  __m128 v63; // xmm1
  __m128 v64; // xmm3
  __m128 v65; // xmm2
  __m128 v66; // xmm5
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm4
  __m128 v70; // xmm1
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm4
  hkVector4f b; // [rsp+20h] [rbp-A8h] BYREF

  m_storage = (unsigned __int8)this->m_weldingType.m_storage;
  v10 = (char *)numFeaturePoints;
  if ( (_DWORD)m_storage == 6 )
    return 2i64;
  v14 = *featurePoints;
  v15 = *(_BYTE *)numFeaturePoints;
  v16 = mod3Table[v14].m_storage;
  if ( *(_BYTE *)numFeaturePoints > 1u )
  {
    v17 = featurePoints[1];
    numFeaturePoints = (unsigned int)mod3Table[v17].m_storage;
    if ( v15 == 3 )
    {
      v18 = featurePoints[2];
      if ( (_DWORD)v14 + (_DWORD)v17 + (_DWORD)v18 == 3 )
        return 2i64;
      if ( (_DWORD)numFeaturePoints == (_DWORD)v16 )
        numFeaturePoints = (unsigned int)mod3Table[v18].m_storage;
      *v10 = 2;
      *featurePoints = v16;
      featurePoints[1] = numFeaturePoints;
    }
    if ( dword_14210E064[v16] != (_DWORD)numFeaturePoints )
      LODWORD(v16) = numFeaturePoints;
  }
  m_quad = separatingNormalInOut->m_quad;
  v20.m_quad = (__m128)thisObjTransform->m_rotation.m_col2;
  v21 = _mm_unpacklo_ps(thisObjTransform->m_rotation.m_col0.m_quad, thisObjTransform->m_rotation.m_col1.m_quad);
  v22 = _mm_movelh_ps(v21, v20.m_quad);
  v23 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), _mm_shuffle_ps(_mm_movehl_ps(v22, v21), v20.m_quad, 212));
  v24 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v22);
  v25 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  v26 = _mm_add_ps(
          _mm_add_ps(v23, v24),
          _mm_mul_ps(
            _mm_shuffle_ps(m_quad, m_quad, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(thisObjTransform->m_rotation.m_col0.m_quad, thisObjTransform->m_rotation.m_col1.m_quad),
              v20.m_quad,
              228)));
  v27 = _mm_sub_ps(this->m_vertexC.m_quad, this->m_vertexB.m_quad);
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v25), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v27));
  v29 = _mm_shuffle_ps(v28, v28, 201);
  v30 = _mm_mul_ps(v29, v29);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_rsqrt_ps(v31);
  v33 = _mm_mul_ps(
          v29,
          _mm_andnot_ps(
            _mm_cmple_ps(v31, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
              _mm_mul_ps(*(__m128 *)_xmm, v32))));
  v34 = _mm_mul_ps(v33, v26);
  v35 = _mm_mul_ps(
          (__m128)_mm_srli_epi32(
                    _mm_slli_epi32(
                      (__m128i)_mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                                 _mm_shuffle_ps(v34, v34, 170)),
                      1u),
                    1u),
          _mm_shuffle_ps(m_quad, m_quad, 255));
  v36 = _mm_sub_ps(*(&this->m_vertexA.m_quad + dword_14210E064[(int)v16]), *(&this->m_vertexA.m_quad + (int)v16));
  v37 = (this->m_weldingInfo >> (5 * v16)) & 0x1F;
  v38 = _mm_mul_ps(v36, v36);
  v39 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v40 = _mm_rsqrt_ps(v39);
  v41 = _mm_mul_ps(
          v36,
          _mm_andnot_ps(
            _mm_cmple_ps(v39, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)),
              _mm_mul_ps(*(__m128 *)_xmm, v40))));
  if ( (_DWORD)m_storage == 5 )
  {
    v56 = (unsigned int *)&hkpWeldingUtility::m_sinCosTable[v37];
    v57 = 4
        * _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v56[4], (__m128)v56[2]),
                _mm_unpacklo_ps((__m128)v56[3], (__m128)*v56)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                _mm_shuffle_ps(v34, v34, 170))));
    v58 = (0x1111111100002243ui64 >> v57) & 0xF;
    if ( ((0x1111111100002243ui64 >> v57) & 0xF) == 0 )
      goto LABEL_26;
    if ( (_DWORD)v58 == 2 )
      return 0i64;
    if ( (_DWORD)v58 == 4 )
    {
LABEL_26:
      if ( *v10 != 1 )
      {
        v59 = (__m128)v56[(int)v58];
        v60 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v41), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v33));
        v61 = (__m128)v56[(int)v58 + 1];
        v62 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), _mm_shuffle_ps(v61, v61, 0)),
                _mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), v33));
        v63 = _mm_mul_ps(v62, v62);
        v64 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                _mm_shuffle_ps(v63, v63, 170));
        v65 = _mm_rsqrt_ps(v64);
        v66 = _mm_mul_ps(
                v62,
                _mm_andnot_ps(
                  _mm_cmple_ps(v64, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v65, v64), v65)),
                    _mm_mul_ps(*(__m128 *)_xmm, v65))));
        v67 = _mm_mul_ps(v41, v26);
        v68 = _mm_mul_ps(v66, v26);
        v69 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                    _mm_shuffle_ps(v67, v67, 170)),
                  v41),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                    _mm_shuffle_ps(v68, v68, 170)),
                  v66));
        v70 = _mm_mul_ps(v69, v69);
        v71 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                _mm_shuffle_ps(v70, v70, 170));
        v72 = _mm_rsqrt_ps(v71);
        v73 = _mm_mul_ps(
                v69,
                _mm_andnot_ps(
                  _mm_cmple_ps(v71, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v72, v71), v72)),
                    _mm_mul_ps(*(__m128 *)_xmm, v72))));
        v52 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v73, v73, 85), thisObjTransform->m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), thisObjTransform->m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v73, v73, 170), thisObjTransform->m_rotation.m_col2.m_quad));
        goto $RETURN_ACCEPT_CONTACT_POINT_MODIFIED;
      }
      return 0i64;
    }
    return 2i64;
  }
  if ( v37 == 31 )
    return 2i64;
  v42 = (float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
      + _mm_shuffle_ps(v34, v34, 170).m128_f32[0];
  v43 = &hkpWeldingUtility::m_sinCosTable[v37];
  if ( !((_DWORD)m_storage ? v42 > *(&v43->m_cosAccept0 + (int)m_storage) : v42 < v43->m_cosAccept0) )
    return 2i64;
  v45 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v41), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v33));
  v46 = (__m128)*((unsigned int *)&v43->m_sinAccept0 + (int)m_storage);
  v47 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), _mm_shuffle_ps(v46, v46, 0)),
          _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)*((unsigned int *)&v43->m_cosAccept0 + m_storage),
              (__m128)*((unsigned int *)&v43->m_cosAccept0 + m_storage),
              0),
            v33));
  v48 = _mm_mul_ps(v47, v47);
  v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)), _mm_shuffle_ps(v48, v48, 170));
  v50 = _mm_rsqrt_ps(v49);
  v51 = _mm_mul_ps(
          v47,
          _mm_andnot_ps(
            _mm_cmple_ps(v49, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
              _mm_mul_ps(*(__m128 *)_xmm, v50))));
  v52 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), thisObjTransform->m_rotation.m_col0.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v51, v51, 85), thisObjTransform->m_rotation.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v51, v51, 170), thisObjTransform->m_rotation.m_col2.m_quad));
  if ( !this->m_isExtruded )
  {
    ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, unsigned __int64, hkTransformf *))collidingShape->vfptr[5].__vecDelDtor)(
      collidingShape,
      &b,
      numFeaturePoints,
      thisObjTransform);
    hkVector4f::setTransformedPos(&b, collidingTransform, &b);
    v55 = _mm_mul_ps(_mm_sub_ps(contactPointWs->m_quad, b.m_quad), v52);
    if ( (float)((float)(_mm_shuffle_ps(v55, v55, 85).m128_f32[0] + _mm_shuffle_ps(v55, v55, 0).m128_f32[0])
               + _mm_shuffle_ps(v55, v55, 170).m128_f32[0]) < 0.0 )
      goto $RETURN_ACCEPT_CONTACT_POINT_MODIFIED;
    return 0i64;
  }
  v53 = (__m128)LODWORD(flipNormalBasedOnWeldingTypeTable[m_storage]);
  hkVector4f::setTransformedInversePos(&b, thisObjTransform, contactPointWs);
  v54 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v33), _mm_sub_ps(b.m_quad, this->m_vertexA.m_quad));
  v35 = _mm_min_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
            _mm_shuffle_ps(v54, v54, 170)),
          v35);
$RETURN_ACCEPT_CONTACT_POINT_MODIFIED:
  result = 1i64;
  separatingNormalInOut->m_quad = _mm_shuffle_ps(v52, _mm_unpackhi_ps(v52, v35), 196);
  return result;
}

// File Line: 279
// RVA: 0xD0A8F0
void __fastcall hkpTriangleShape::getAabb(
        hkpTriangleShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  __m128 v7; // xmm6
  hkVector4f v8; // xmm3
  __m128 v9; // xmm2
  hkVector4f v10; // xmm2
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm3
  hkVector4f v13; // [rsp+20h] [rbp-48h] BYREF
  hkVector4f v14; // [rsp+30h] [rbp-38h] BYREF
  hkVector4f v15; // [rsp+40h] [rbp-28h] BYREF

  v7 = _mm_shuffle_ps(
         (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
         (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
         0);
  hkVector4f::setTransformedPos(&v13, localToWorld, &this->m_vertexA);
  hkVector4f::setTransformedPos(&v14, localToWorld, &this->m_vertexB);
  hkVector4f::setTransformedPos(&v15, localToWorld, &this->m_vertexC);
  v8.m_quad = _mm_max_ps(_mm_max_ps(v13.m_quad, v14.m_quad), v15.m_quad);
  v9 = _mm_min_ps(v13.m_quad, v14.m_quad);
  out->m_max = (hkVector4f)v8.m_quad;
  v10.m_quad = _mm_min_ps(v9, v15.m_quad);
  out->m_min = (hkVector4f)v10.m_quad;
  v11.m_quad = _mm_min_ps(v10.m_quad, _mm_add_ps(this->m_extrusion.m_quad, v10.m_quad));
  out->m_min = (hkVector4f)v11.m_quad;
  v12.m_quad = _mm_max_ps(v8.m_quad, _mm_add_ps(this->m_extrusion.m_quad, v8.m_quad));
  out->m_max = (hkVector4f)v12.m_quad;
  out->m_max.m_quad = _mm_add_ps(v7, v12.m_quad);
  out->m_min.m_quad = _mm_sub_ps(v11.m_quad, v7);
}

// File Line: 304
// RVA: 0xD0A850
hkSphere *__fastcall hkpTriangleShape::getCollisionSpheres(hkpTriangleShape *this, hkSphere *sphereBuffer)
{
  hkSphere *result; // rax
  __m128 v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm1

  result = sphereBuffer;
  v3 = _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0);
  sphereBuffer->m_pos.m_quad = _mm_shuffle_ps(this->m_vertexA.m_quad, _mm_unpackhi_ps(this->m_vertexA.m_quad, v3), 196);
  sphereBuffer[1].m_pos.m_quad = _mm_shuffle_ps(
                                   this->m_vertexB.m_quad,
                                   _mm_unpackhi_ps(this->m_vertexB.m_quad, v3),
                                   196);
  sphereBuffer[2].m_pos.m_quad = _mm_shuffle_ps(
                                   this->m_vertexC.m_quad,
                                   _mm_unpackhi_ps(this->m_vertexC.m_quad, v3),
                                   196);
  if ( this->m_isExtruded )
  {
    v4 = _mm_add_ps(this->m_vertexA.m_quad, this->m_extrusion.m_quad);
    sphereBuffer[3].m_pos.m_quad = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, v3), 196);
    v5 = _mm_add_ps(this->m_extrusion.m_quad, this->m_vertexB.m_quad);
    sphereBuffer[4].m_pos.m_quad = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, v3), 196);
    v6 = _mm_add_ps(this->m_extrusion.m_quad, this->m_vertexC.m_quad);
    sphereBuffer[5].m_pos.m_quad = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, v3), 196);
  }
  return result;
}

// File Line: 347
// RVA: 0xD0A9C0
hkBool *__fastcall hkpTriangleShape::castRay(
        hkpTriangleShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkVector4f v12; // xmm11
  __m128 v13; // xmm5
  hkVector4f v14; // xmm12
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm14
  __m128 v18; // xmm0
  __m128 v19; // xmm7
  __m128 v20; // xmm7
  __m128 v21; // xmm1
  __m128i v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm8
  __m128 v27; // xmm9
  __m128 v28; // xmm8
  BOOL v29; // esi
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  __m128 v32; // xmm12
  __m128 v33; // xmm11
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm5
  __m128 v39; // xmm13
  __m128 v40; // xmm12
  __m128 v41; // xmm5
  __m128 v42; // xmm13
  __m128 v43; // xmm12
  __m128 v44; // xmm7
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm5
  __m128 v48; // xmm4
  __m128 v49; // xmm2
  char v50; // al
  hkVector4f v51; // xmm6
  __int64 m_shapeKeyIndex; // rax
  _QWORD *v53; // r8
  _QWORD *v54; // rcx
  unsigned __int64 v55; // rax
  _QWORD *v56; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcTriangle";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  v12.m_quad = (__m128)this->m_vertexA;
  v13 = _mm_sub_ps(input->m_to.m_quad, input->m_from.m_quad);
  v14.m_quad = (__m128)this->m_vertexC;
  v15 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196);
  v16 = _mm_sub_ps(this->m_vertexB.m_quad, v12.m_quad);
  v17 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0);
  v18 = _mm_sub_ps(v14.m_quad, v12.m_quad);
  v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v18));
  v20 = _mm_shuffle_ps(v19, v19, 201);
  v21 = _mm_mul_ps(_mm_sub_ps(input->m_from.m_quad, v12.m_quad), v20);
  v22 = (__m128i)_mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                   _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_mul_ps(v15, v20);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = _mm_rcp_ps(v24);
  v26 = _mm_add_ps(v24, (__m128)v22);
  v27 = _mm_sub_ps(
          (__m128)0i64,
          _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v24)), v25), (__m128)v22));
  v28 = _mm_andnot_ps(
          _mm_and_ps(
            _mm_or_ps(_mm_cmpeq_ps(v26, (__m128)0i64), _mm_cmpneq_ps((__m128)v22, (__m128)0i64)),
            _mm_cmple_ps((__m128)0i64, _mm_mul_ps(v26, (__m128)v22))),
          _mm_cmplt_ps(
            v27,
            _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0)));
  if ( _mm_movemask_ps(v28) )
  {
    v30 = _mm_add_ps(_mm_mul_ps(v15, v27), input->m_from.m_quad);
    v31 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v22, 0x1Fu), 0x1Fu), v20);
    v32 = _mm_sub_ps(v14.m_quad, v30);
    v33 = _mm_sub_ps(v12.m_quad, v30);
    v34 = _mm_sub_ps(this->m_vertexB.m_quad, v30);
    v35 = _mm_shuffle_ps(v32, v32, 201);
    v36 = _mm_shuffle_ps(v34, v34, 201);
    v37 = _mm_shuffle_ps(v33, v33, 201);
    v38 = _mm_sub_ps(_mm_mul_ps(v33, v36), _mm_mul_ps(v34, v37));
    v39 = _mm_sub_ps(_mm_mul_ps(v34, v35), _mm_mul_ps(v32, v36));
    v40 = _mm_sub_ps(_mm_mul_ps(v32, v37), _mm_mul_ps(v33, v35));
    v41 = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v20);
    v42 = _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v20);
    v43 = _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v20);
    v44 = _mm_mul_ps(v20, v20);
    v45 = _mm_shuffle_ps(v43, v44, 68);
    v46 = _mm_shuffle_ps(v41, v42, 68);
    v47 = _mm_add_ps(
            _mm_shuffle_ps(_mm_shuffle_ps(v41, v42, 238), _mm_shuffle_ps(v43, v44, 238), 136),
            _mm_add_ps(_mm_shuffle_ps(v46, v45, 221), _mm_shuffle_ps(v46, v45, 136)));
    v48 = _mm_shuffle_ps(v47, v47, 255);
    v49 = _mm_rsqrt_ps(v48);
    v50 = _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v48), v17), v47), v28)) & 7;
    v29 = v50 == 7;
    v51.m_quad = _mm_mul_ps(
                   v31,
                   _mm_andnot_ps(
                     _mm_cmple_ps(v48, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                       _mm_mul_ps(*(__m128 *)_xmm, v49))));
    if ( v50 == 7 )
    {
      m_shapeKeyIndex = results->m_shapeKeyIndex;
      LODWORD(results->m_hitFraction) = v27.m128_i32[0];
      results->m_normal = (hkVector4f)v51.m_quad;
      results->m_shapeKeys[m_shapeKeyIndex] = -1;
    }
  }
  else
  {
    v29 = 0;
  }
  v53 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v54 = (_QWORD *)v53[1];
  if ( (unsigned __int64)v54 < v53[3] )
  {
    *v54 = "Et";
    v55 = __rdtsc();
    v56 = v54 + 2;
    *((_DWORD *)v56 - 2) = v55;
    v53[1] = v56;
  }
  result->m_bool = v29;
  return result;
}

// File Line: 422
// RVA: 0xD0AD30
hkVector4fComparison *__fastcall hkpTriangleShape::castRayBundle(
        hkpTriangleShape *this,
        hkVector4fComparison *result,
        hkpShapeRayBundleCastInput *input,
        hkpShapeRayBundleCastOutput *results,
        hkVector4fComparison *mask)
{
  _QWORD *Value; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm6
  __m128 v14; // xmm7
  __m128 v15; // xmm4
  __m128 v16; // xmm8
  __m128 v17; // xmm15
  __m128 v18; // xmm9
  __m128 v19; // xmm12
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm14
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm6
  __m128 v26; // xmm14
  __m128 m_quad; // xmm1
  __m128 v28; // xmm1
  __m128 v29; // xmm14
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm10
  __m128 v36; // xmm15
  __m128 v37; // xmm8
  __m128 v38; // xmm4
  __m128 v39; // xmm9
  __m128 v40; // xmm7
  __m128 v41; // xmm10
  __m128 v42; // xmm13
  __m128 v43; // xmm11
  hkVector4f v44; // xmm2
  __m128 v45; // xmm12
  __m128 v46; // xmm6
  __m128 v47; // xmm7
  __m128 v48; // xmm4
  __m128 v49; // xmm8
  __m128 v50; // xmm3
  __m128 v51; // xmm0
  hkVector4f v52; // xmm7
  __m128 v53; // xmm1
  __m128 v54; // xmm0
  __m128 v55; // xmm0
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm14
  __m128 v59; // xmm0
  __m128 v60; // xmm5
  __m128 v61; // xmm2
  __m128 v62; // xmm4
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm8
  int v66; // ecx
  hkVector4f *v67; // rdx
  __m128 *v68; // r8
  __int64 v69; // r9
  __m128 m_mask; // xmm0
  int v71; // r10d
  hkVector4f v72; // xmm0
  _QWORD *v73; // r8
  _QWORD *v74; // rcx
  unsigned __int64 v75; // rax
  _QWORD *v76; // rcx
  __m128 v78; // [rsp+20h] [rbp-1A8h]
  __m128 v79; // [rsp+20h] [rbp-1A8h]
  __m128 v80; // [rsp+20h] [rbp-1A8h]
  __m128 v81; // [rsp+30h] [rbp-198h]
  __m128 v82; // [rsp+30h] [rbp-198h]
  __m128 v83; // [rsp+30h] [rbp-198h]
  __m128 v84; // [rsp+40h] [rbp-188h]
  __m128 v85; // [rsp+50h] [rbp-178h]
  __m128 v86; // [rsp+60h] [rbp-168h]
  __m128 v87; // [rsp+70h] [rbp-158h] BYREF
  __m128 v88; // [rsp+80h] [rbp-148h]
  __m128 v89; // [rsp+90h] [rbp-138h]
  __m128 v90; // [rsp+A0h] [rbp-128h]
  __m128 v91; // [rsp+B0h] [rbp-118h]
  __m128 v92; // [rsp+C0h] [rbp-108h]
  __m128 v93; // [rsp+D0h] [rbp-F8h]
  __int128 v94[14]; // [rsp+E0h] [rbp-E8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtrayBundleTriangle";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  v13.m_quad = (__m128)this->m_vertexA;
  v14 = 0i64;
  v15 = 0i64;
  v16 = 0i64;
  v17 = _mm_sub_ps(input->m_to.m_vertices[1].m_quad, input->m_from.m_vertices[1].m_quad);
  v18 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(
            (__m128)LODWORD(results->m_outputs[0].m_hitFraction),
            (__m128)LODWORD(results->m_outputs[2].m_hitFraction)),
          _mm_unpacklo_ps(
            (__m128)LODWORD(results->m_outputs[1].m_hitFraction),
            (__m128)LODWORD(results->m_outputs[3].m_hitFraction)));
  v81 = _mm_sub_ps(input->m_to.m_vertices[0].m_quad, input->m_from.m_vertices[0].m_quad);
  v19 = _mm_sub_ps(input->m_to.m_vertices[2].m_quad, input->m_from.m_vertices[2].m_quad);
  v20 = _mm_sub_ps(this->m_vertexC.m_quad, v13.m_quad);
  v21 = _mm_sub_ps(this->m_vertexB.m_quad, v13.m_quad);
  v91 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 85);
  v90 = v18;
  v87 = v18;
  v78 = v17;
  v22 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v21);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v20);
  v24 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 0);
  v25 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 170);
  v26 = _mm_sub_ps(v22, v23);
  m_quad = input->m_from.m_vertices[0].m_quad;
  v93 = v24;
  v28 = _mm_sub_ps(m_quad, v24);
  v29 = _mm_shuffle_ps(v26, v26, 201);
  v30 = _mm_sub_ps(input->m_from.m_vertices[1].m_quad, v91);
  v31 = _mm_sub_ps(input->m_from.m_vertices[2].m_quad, v25);
  v88 = _mm_shuffle_ps(v29, v29, 0);
  v84 = _mm_shuffle_ps(v29, v29, 85);
  v85 = _mm_shuffle_ps(v29, v29, 170);
  v92 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v84, v30), _mm_mul_ps(v88, v28)), _mm_mul_ps(v85, v31));
  v32 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v84, v17), _mm_mul_ps(v88, v81)), _mm_mul_ps(v85, v19));
  v33 = _mm_rcp_ps(v32);
  v34 = _mm_add_ps(v32, v92);
  v35 = _mm_xor_ps(
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
          _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v33, v32)), v33), v92));
  v89 = v35;
  v36 = _mm_and_ps(
          _mm_andnot_ps(
            _mm_and_ps(
              _mm_or_ps(_mm_cmpeq_ps((__m128)0i64, v34), _mm_cmpneq_ps((__m128)0i64, v92)),
              _mm_cmple_ps((__m128)0i64, _mm_mul_ps(v34, v92))),
            _mm_cmplt_ps(v35, v18)),
          mask->m_mask);
  *result = (hkVector4fComparison)v36;
  if ( _mm_movemask_ps(v36) )
  {
    v37 = _mm_add_ps(_mm_mul_ps(v78, v35), input->m_from.m_vertices[1].m_quad);
    v38 = _mm_add_ps(_mm_mul_ps(v19, v35), input->m_from.m_vertices[2].m_quad);
    v39 = _mm_sub_ps(v37, v91);
    v79 = v37;
    v40 = _mm_add_ps(_mm_mul_ps(v81, v35), input->m_from.m_vertices[0].m_quad);
    v41 = _mm_sub_ps(v38, v25);
    v42 = _mm_mul_ps(v29, v29);
    v82 = v40;
    v43 = _mm_sub_ps(v40, v93);
    v86 = v38;
    v44.m_quad = (__m128)this->m_vertexB;
    v45 = _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                _mm_shuffle_ps(v42, v42, 170))),
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0));
    v46 = _mm_sub_ps(v40, _mm_shuffle_ps(v44.m_quad, v44.m_quad, 0));
    v47 = _mm_sub_ps(v37, _mm_shuffle_ps(v44.m_quad, v44.m_quad, 85));
    v48 = _mm_sub_ps(v38, _mm_shuffle_ps(v44.m_quad, v44.m_quad, 170));
    v49 = _mm_and_ps(
            _mm_cmple_ps(
              v45,
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v46, _mm_sub_ps(_mm_mul_ps(v84, v41), _mm_mul_ps(v85, v39))),
                  _mm_mul_ps(v47, _mm_sub_ps(_mm_mul_ps(v85, v43), _mm_mul_ps(v88, v41)))),
                _mm_mul_ps(v48, _mm_sub_ps(_mm_mul_ps(v88, v39), _mm_mul_ps(v84, v43))))),
            v36);
    v50 = _mm_sub_ps(_mm_mul_ps(v88, v47), _mm_mul_ps(v84, v46));
    v51 = _mm_mul_ps(v85, v47);
    v52.m_quad = (__m128)this->m_vertexC;
    v53 = _mm_sub_ps(_mm_mul_ps(v84, v48), v51);
    v83 = _mm_sub_ps(v82, _mm_shuffle_ps(v52.m_quad, v52.m_quad, 0));
    v80 = _mm_sub_ps(v79, _mm_shuffle_ps(v52.m_quad, v52.m_quad, 85));
    v54 = _mm_sub_ps(v86, _mm_shuffle_ps(v52.m_quad, v52.m_quad, 170));
    v14 = 0i64;
    v55 = _mm_and_ps(
            _mm_cmple_ps(
              v45,
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v43, _mm_sub_ps(_mm_mul_ps(v54, v84), _mm_mul_ps(v80, v85))),
                  _mm_mul_ps(v39, _mm_sub_ps(_mm_mul_ps(v83, v85), _mm_mul_ps(v54, v88)))),
                _mm_mul_ps(v41, _mm_sub_ps(_mm_mul_ps(v80, v88), _mm_mul_ps(v83, v84))))),
            _mm_and_ps(
              _mm_cmple_ps(
                v45,
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v83, v53),
                    _mm_mul_ps(v80, _mm_sub_ps(_mm_mul_ps(v85, v46), _mm_mul_ps(v88, v48)))),
                  _mm_mul_ps(v54, v50))),
              v49));
    *result = (hkVector4fComparison)v55;
    v87 = _mm_or_ps(_mm_and_ps(v55, v89), _mm_andnot_ps(v55, v90));
    v56 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
            _mm_shuffle_ps(v42, v42, 170));
    v57 = _mm_rsqrt_ps(v56);
    v58 = _mm_mul_ps(
            v29,
            _mm_andnot_ps(
              _mm_cmple_ps(v56, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v57, v56), v57)),
                _mm_mul_ps(*(__m128 *)_xmm, v57))));
    v59 = (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)v92, 0x1Fu), 0x1Fu);
    v15 = _mm_or_ps(
            _mm_andnot_ps(result->m_mask, (__m128)0i64),
            _mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v58, v58, 0), v59), result->m_mask));
    v60 = _mm_or_ps(
            _mm_andnot_ps(result->m_mask, (__m128)0i64),
            _mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v58, v58, 85), v59), result->m_mask));
    v16 = _mm_or_ps(
            _mm_andnot_ps(result->m_mask, (__m128)0i64),
            _mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v58, v58, 170), v59), result->m_mask));
  }
  else
  {
    v60 = 0i64;
  }
  v61 = v15;
  v62 = _mm_shuffle_ps(v15, v60, 238);
  v63 = _mm_shuffle_ps(v61, v60, 68);
  v64 = _mm_shuffle_ps(v16, v14, 68);
  v65 = _mm_shuffle_ps(v16, v14, 238);
  v66 = 1;
  v67 = (hkVector4f *)v94;
  v68 = &v87;
  v69 = 4i64;
  v94[0] = (__int128)_mm_shuffle_ps(v63, v64, 136);
  v94[1] = (__int128)_mm_shuffle_ps(v63, v64, 221);
  v94[2] = (__int128)_mm_shuffle_ps(v62, v65, 136);
  m_mask = result->m_mask;
  v94[3] = (__int128)_mm_shuffle_ps(v62, v65, 221);
  v71 = _mm_movemask_ps(m_mask);
  do
  {
    if ( (v66 & v71) != 0 )
    {
      v72.m_quad = v67->m_quad;
      LODWORD(results->m_outputs[0].m_hitFraction) = v68->m128_i32[0];
      results->m_outputs[0].m_normal = (hkVector4f)v72.m_quad;
      results->m_outputs[0].m_shapeKeys[results->m_outputs[0].m_shapeKeyIndex] = -1;
    }
    v66 = __ROL4__(v66, 1);
    v68 = (__m128 *)((char *)v68 + 4);
    ++v67;
    results = (hkpShapeRayBundleCastOutput *)((char *)results + 80);
    --v69;
  }
  while ( v69 );
  v73 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v74 = (_QWORD *)v73[1];
  if ( (unsigned __int64)v74 < v73[3] )
  {
    *v74 = "Et";
    v75 = __rdtsc();
    v76 = v74 + 2;
    *((_DWORD *)v76 - 2) = v75;
    v73[1] = v76;
  }
  return result;
}

