// File Line: 33
// RVA: 0xD09FF0
void __fastcall hkpTriangleShape::hkpTriangleShape(hkpTriangleShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpTriangleShape *v2; // rbx

  v2 = this;
  hkpConvexShape::hkpConvexShape((hkpConvexShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpTriangleShape::`vftable;
  v2->m_type.m_storage = 2;
}

// File Line: 39
// RVA: 0xD0B3D0
void __fastcall hkpTriangleShape::getFirstVertex(hkpTriangleShape *this, hkVector4f *v)
{
  *v = this->m_vertexA;
}

// File Line: 46
// RVA: 0xD0A020
void __fastcall hkpTriangleShape::getSupportingVertex(hkpTriangleShape *this, hkVector4f *direction, hkcdVertex *supportingVertexOut)
{
  hkVector4f v3; // xmm3
  hkcdVertex *v4; // r10
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __int64 v8; // r8
  __m128 v9; // xmm2

  v3.m_quad = (__m128)this->m_vertexC;
  v4 = supportingVertexOut;
  v5 = _mm_unpacklo_ps(this->m_vertexA.m_quad, this->m_vertexB.m_quad);
  v6 = _mm_movelh_ps(v5, v3.m_quad);
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_shuffle_ps(direction->m_quad, direction->m_quad, 85),
             _mm_shuffle_ps(_mm_movehl_ps(v6, v5), v3.m_quad, 212)),
           _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 0), v6)),
         _mm_mul_ps(
           _mm_shuffle_ps(direction->m_quad, direction->m_quad, 170),
           _mm_shuffle_ps(_mm_unpackhi_ps(this->m_vertexA.m_quad, this->m_vertexB.m_quad), v3.m_quad, 228)));
  v8 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                              _mm_and_ps(
                                                                _mm_cmpleps(
                                                                  _mm_max_ps(
                                                                    _mm_shuffle_ps(v7, v7, 170),
                                                                    _mm_max_ps(
                                                                      _mm_shuffle_ps(v7, v7, 85),
                                                                      _mm_shuffle_ps(v7, v7, 0))),
                                                                  v7),
                                                                (__m128)xmmword_141A81E40))];
  *v4 = *(hkcdVertex *)&(&this->vfptr)[2 * (v8 + 3)];
  v9 = _mm_mul_ps(this->m_extrusion.m_quad, direction->m_quad);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170))) > 0.0 )
  {
    LODWORD(v8) = v8 + 3;
    v4->m_quad = _mm_add_ps(this->m_extrusion.m_quad, v4->m_quad);
  }
  v4->m_quad.m128_i32[3] = v8 | 0x3F000000;
}

// File Line: 68
// RVA: 0xD0A110
void __fastcall hkpTriangleShape::convertVertexIdsToVertices(hkpTriangleShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  int i; // er8
  __int64 v5; // rax
  __m128 v6; // xmm1
  __m128 v7; // xmm0

  for ( i = numIds - 1; i >= 0; verticesOut[-1].m_quad.m128_i32[3] = *(ids - 1) | 0x3F000000 )
  {
    v5 = *ids;
    ++verticesOut;
    ++ids;
    v6 = *(__m128 *)&(&this->vfptr)[2 * (mod3Table[v5].m_storage + 3i64)];
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
  hkVector4f v2; // xmm0
  hkVector4f v3; // xmm1

  v2.m_quad = _mm_add_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  *centreOut = (hkVector4f)v2.m_quad;
  v3.m_quad = _mm_add_ps(this->m_vertexC.m_quad, v2.m_quad);
  *centreOut = (hkVector4f)v3.m_quad;
  centreOut->m_quad = _mm_mul_ps(v3.m_quad, (__m128)xmmword_141A711C0);
}

// File Line: 88
// RVA: 0xD0B3E0
__int64 __fastcall getSingleEdgeBitcode(unsigned __int16 triangleEdgesBitcode, int edgeIndex)
{
  return ((unsigned int)triangleEdgesBitcode >> 5 * edgeIndex) & 0x1F;
}

// File Line: 99
// RVA: 0xD0B400
void __fastcall calcAntiClockwiseTriangleNormal(hkVector4f *vertex0, hkVector4f *vertex1, hkVector4f *vertex2, hkVector4f *normal)
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
                       _mm_cmpleps(v9, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                         _mm_mul_ps(*(__m128 *)_xmm, v10))),
                     v7);
}

// File Line: 115
// RVA: 0xD0A180
signed __int64 __fastcall hkpTriangleShape::weldContactPoint(hkpTriangleShape *this, unsigned __int16 *featurePoints, char *numFeaturePoints, hkVector4f *contactPointWs, hkTransformf *thisObjTransform, hkpConvexShape *collidingShape, hkTransformf *collidingTransform, hkVector4f *separatingNormalInOut)
{
  __int64 v8; // r11
  hkVector4f *v9; // r14
  char *v10; // rbx
  unsigned __int16 *v11; // r10
  hkpTriangleShape *v12; // rdi
  signed __int64 result; // rax
  __int64 v14; // r9
  char v15; // al
  __int64 v16; // rdx
  __int64 v17; // rsi
  __int64 v18; // rbp
  __m128 v19; // xmm5
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
  bool v44; // cl
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
  hkpWeldingUtility::SinCosTableEntry *v56; // r8
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
  hkVector4f b; // [rsp+20h] [rbp-A8h]

  v8 = (unsigned __int8)this->m_weldingType.m_storage;
  v9 = contactPointWs;
  v10 = numFeaturePoints;
  v11 = featurePoints;
  v12 = this;
  if ( (_DWORD)v8 == 6 )
    return 2i64;
  v14 = *featurePoints;
  v15 = *numFeaturePoints;
  v16 = mod3Table[v14].m_storage;
  if ( (unsigned __int8)*numFeaturePoints > 1u )
  {
    v17 = v11[1];
    numFeaturePoints = (char *)(unsigned int)mod3Table[v17].m_storage;
    if ( v15 == 3 )
    {
      v18 = v11[2];
      if ( (_DWORD)v14 + (_DWORD)v17 + (_DWORD)v18 == 3 )
        return 2i64;
      if ( (_DWORD)numFeaturePoints == (_DWORD)v16 )
        numFeaturePoints = (char *)(unsigned int)mod3Table[v18].m_storage;
      *v10 = 2;
      *v11 = v16;
      v11[1] = (unsigned __int16)numFeaturePoints;
    }
    if ( dword_14210E064[v16] != (_DWORD)numFeaturePoints )
      LODWORD(v16) = (_DWORD)numFeaturePoints;
  }
  v19 = separatingNormalInOut->m_quad;
  v20.m_quad = (__m128)thisObjTransform->m_rotation.m_col2;
  v21 = _mm_unpacklo_ps(thisObjTransform->m_rotation.m_col0.m_quad, thisObjTransform->m_rotation.m_col1.m_quad);
  v22 = _mm_movelh_ps(v21, v20.m_quad);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(_mm_movehl_ps(v22, v21), v20.m_quad, 212));
  v24 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v22);
  v25 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  v26 = _mm_add_ps(
          _mm_add_ps(v23, v24),
          _mm_mul_ps(
            _mm_shuffle_ps(v19, v19, 170),
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
            _mm_cmpleps(v31, (__m128)0i64),
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
          _mm_shuffle_ps(v19, v19, 255));
  v36 = _mm_sub_ps(
          *(__m128 *)&(&this->vfptr)[2 * (dword_14210E064[(signed int)v16] + 3i64)],
          *(__m128 *)&(&this->vfptr)[2 * ((signed int)v16 + 3i64)]);
  v37 = (this->m_weldingInfo >> 5 * v16) & 0x1F;
  v38 = _mm_mul_ps(v36, v36);
  v39 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v40 = _mm_rsqrt_ps(v39);
  v41 = _mm_mul_ps(
          v36,
          _mm_andnot_ps(
            _mm_cmpleps(v39, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)),
              _mm_mul_ps(*(__m128 *)_xmm, v40))));
  if ( (_DWORD)v8 == 5 )
  {
    v56 = &hkpWeldingUtility::m_sinCosTable[v37];
    v57 = 4
        * _mm_movemask_ps(
            _mm_cmpleps(
              _mm_unpacklo_ps(
                _mm_unpacklo_ps(
                  (__m128)LODWORD(v56->m_cosAccept1),
                  (__m128)LODWORD(hkpWeldingUtility::m_sinCosTable[v37].m_cosSnap0)),
                _mm_unpacklo_ps(
                  (__m128)LODWORD(hkpWeldingUtility::m_sinCosTable[v37].m_cosSnap1),
                  (__m128)LODWORD(hkpWeldingUtility::m_sinCosTable[v37].m_cosAccept0))),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                _mm_shuffle_ps(v34, v34, 170))));
    v58 = (0x1111111100002243ui64 >> v57) & 0xF;
    if ( !((0x1111111100002243ui64 >> v57) & 0xF) )
      goto LABEL_31;
    if ( (_DWORD)v58 == 2 )
      return 0i64;
    if ( (_DWORD)v58 == 4 )
    {
LABEL_31:
      if ( *v10 != 1 )
      {
        v59 = (__m128)*((unsigned int *)&v56->m_cosAccept0 + (signed int)v58);
        v60 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v41), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v33));
        v61 = (__m128)*((unsigned int *)&v56->m_cosAccept0 + (signed int)v58 + 1);
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
                  _mm_cmpleps(v64, (__m128)0i64),
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
                  _mm_cmpleps(v71, (__m128)0i64),
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
  v42 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170));
  v43 = &hkpWeldingUtility::m_sinCosTable[v37];
  v44 = (_DWORD)v8 ? v42 > *(&v43->m_cosAccept0 + (signed int)v8) : v42 < v43->m_cosAccept0;
  if ( !v44 )
    return 2i64;
  v45 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v41), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v33));
  v46 = (__m128)*((unsigned int *)&v43->m_cosAccept0 + (signed int)v8 + 1);
  v47 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), _mm_shuffle_ps(v46, v46, 0)),
          _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)*((unsigned int *)&v43->m_cosAccept0 + v8),
              (__m128)*((unsigned int *)&v43->m_cosAccept0 + v8),
              0),
            v33));
  v48 = _mm_mul_ps(v47, v47);
  v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)), _mm_shuffle_ps(v48, v48, 170));
  v50 = _mm_rsqrt_ps(v49);
  v51 = _mm_mul_ps(
          v47,
          _mm_andnot_ps(
            _mm_cmpleps(v49, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
              _mm_mul_ps(*(__m128 *)_xmm, v50))));
  v52 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), thisObjTransform->m_rotation.m_col0.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v51, v51, 85), thisObjTransform->m_rotation.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v51, v51, 170), thisObjTransform->m_rotation.m_col2.m_quad));
  if ( !v12->m_isExtruded )
  {
    ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, char *, hkTransformf *))collidingShape->vfptr[5].__vecDelDtor)(
      collidingShape,
      &b,
      numFeaturePoints,
      thisObjTransform);
    hkVector4f::setTransformedPos(&b, collidingTransform, &b);
    v55 = _mm_mul_ps(_mm_sub_ps(v9->m_quad, b.m_quad), v52);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 170))) < 0.0 )
      goto $RETURN_ACCEPT_CONTACT_POINT_MODIFIED;
    return 0i64;
  }
  v53 = (__m128)LODWORD(flipNormalBasedOnWeldingTypeTable[v8]);
  hkVector4f::setTransformedInversePos(&b, thisObjTransform, v9);
  v54 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v33), _mm_sub_ps(b.m_quad, v12->m_vertexA.m_quad));
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
void __fastcall hkpTriangleShape::getAabb(hkpTriangleShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkpTriangleShape *v4; // rdi
  hkAabb *v5; // rsi
  hkTransformf *v6; // rbx
  __m128 v7; // xmm6
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // [rsp+20h] [rbp-48h]
  hkVector4f v14; // [rsp+30h] [rbp-38h]
  hkVector4f v15; // [rsp+40h] [rbp-28h]

  v4 = this;
  v5 = out;
  v6 = localToWorld;
  v7 = _mm_shuffle_ps(
         (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
         (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
         0);
  hkVector4f::setTransformedPos((hkVector4f *)&v13, localToWorld, &this->m_vertexA);
  hkVector4f::setTransformedPos(&v14, v6, &v4->m_vertexB);
  hkVector4f::setTransformedPos(&v15, v6, &v4->m_vertexC);
  v8 = _mm_max_ps(_mm_max_ps(v13, v14.m_quad), v15.m_quad);
  v9 = _mm_min_ps(v13, v14.m_quad);
  v5->m_max.m_quad = v8;
  v10 = _mm_min_ps(v9, v15.m_quad);
  v5->m_min.m_quad = v10;
  v11 = _mm_min_ps(v10, _mm_add_ps(v4->m_extrusion.m_quad, v10));
  v5->m_min.m_quad = v11;
  v12 = _mm_max_ps(v8, _mm_add_ps(v4->m_extrusion.m_quad, v8));
  v5->m_max.m_quad = v12;
  v5->m_max.m_quad = _mm_add_ps(v7, v12);
  v5->m_min.m_quad = _mm_sub_ps(v11, v7);
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
hkBool *__fastcall hkpTriangleShape::castRay(hkpTriangleShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpTriangleShape *v4; // rsi
  hkpShapeRayCastOutput *v5; // rbx
  hkpShapeRayCastInput *v6; // rbp
  hkBool *v7; // rdi
  _QWORD *v8; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm11
  __m128 v13; // xmm5
  __m128 v14; // xmm12
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
  __m128 v26; // xmm3
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
  __m128 v51; // xmm6
  __int64 v52; // rax
  _QWORD *v53; // r8
  _QWORD *v54; // rcx
  unsigned __int64 v55; // rax
  signed __int64 v56; // rcx

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcTriangle";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v4->m_vertexA.m_quad;
  v13 = _mm_sub_ps(v6->m_to.m_quad, v6->m_from.m_quad);
  v14 = v4->m_vertexC.m_quad;
  v15 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196);
  v16 = _mm_sub_ps(v4->m_vertexB.m_quad, v12);
  v17 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0);
  v18 = _mm_sub_ps(v14, v12);
  v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v18));
  v20 = _mm_shuffle_ps(v19, v19, 201);
  v21 = _mm_mul_ps(_mm_sub_ps(v6->m_from.m_quad, v12), v20);
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
            _mm_or_ps(_mm_cmpeqps(v26, (__m128)0i64), _mm_cmpneqps((__m128)v22, (__m128)0i64)),
            _mm_cmpleps((__m128)0i64, _mm_mul_ps(v26, (__m128)v22))),
          _mm_cmpltps(v27, _mm_shuffle_ps((__m128)LODWORD(v5->m_hitFraction), (__m128)LODWORD(v5->m_hitFraction), 0)));
  if ( _mm_movemask_ps(v28) )
  {
    v30 = _mm_add_ps(_mm_mul_ps(v15, v27), v6->m_from.m_quad);
    v31 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v22, 0x1Fu), 0x1Fu), v20);
    v32 = _mm_sub_ps(v14, v30);
    v33 = _mm_sub_ps(v12, v30);
    v34 = _mm_sub_ps(v4->m_vertexB.m_quad, v30);
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
    v50 = _mm_movemask_ps(_mm_and_ps(_mm_cmpleps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v48), v17), v47), v28)) & 7;
    v29 = v50 == 7;
    v51 = _mm_mul_ps(
            v31,
            _mm_andnot_ps(
              _mm_cmpleps(v48, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                _mm_mul_ps(*(__m128 *)_xmm, v49))));
    if ( v50 == 7 )
    {
      v52 = v5->m_shapeKeyIndex;
      LODWORD(v5->m_hitFraction) = v27.m128_i32[0];
      v5->m_normal.m_quad = v51;
      v5->m_shapeKeys[v52] = -1;
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
    v56 = (signed __int64)(v54 + 2);
    *(_DWORD *)(v56 - 8) = v55;
    v53[1] = v56;
  }
  v7->m_bool = v29 != 0;
  return v7;
}

// File Line: 422
// RVA: 0xD0AD30
hkVector4fComparison *__fastcall hkpTriangleShape::castRayBundle(hkpTriangleShape *this, hkVector4fComparison *result, hkpShapeRayBundleCastInput *input, hkpShapeRayBundleCastOutput *results, hkVector4fComparison *mask)
{
  hkpTriangleShape *v5; // rbp
  hkpShapeRayBundleCastOutput *v6; // rbx
  hkpShapeRayBundleCastInput *v7; // rsi
  hkVector4fComparison *v8; // rdi
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 v13; // xmm6
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
  __m128 v27; // xmm1
  __m128 v28; // xmm1
  __m128 v29; // xmm14
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm10
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm10
  __m128 v37; // xmm15
  __m128 v38; // xmm8
  __m128 v39; // xmm4
  __m128 v40; // xmm9
  __m128 v41; // ST20_16
  __m128 v42; // xmm7
  __m128 v43; // xmm10
  __m128 v44; // xmm13
  __m128 v45; // ST30_16
  __m128 v46; // xmm11
  __m128 v47; // ST60_16
  __m128 v48; // xmm2
  __m128 v49; // xmm12
  __m128 v50; // xmm6
  __m128 v51; // xmm7
  __m128 v52; // xmm4
  __m128 v53; // xmm8
  __m128 v54; // xmm3
  __m128 v55; // xmm0
  __m128 v56; // xmm7
  __m128 v57; // xmm2
  __m128 v58; // ST30_16
  __m128 v59; // ST20_16
  __m128 v60; // xmm7
  __m128 v61; // xmm2
  __m128 v62; // xmm11
  __m128 v63; // xmm0
  __m128 v64; // xmm1
  __m128 v65; // xmm2
  __m128 v66; // xmm14
  __m128 v67; // xmm0
  __m128 v68; // xmm5
  __m128 v69; // xmm2
  __m128 v70; // xmm4
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm8
  signed int v74; // ecx
  __m128 *v75; // rdx
  __m128 *v76; // r8
  signed __int64 v77; // r9
  __m128 v78; // xmm0
  int v79; // er10
  __m128 v80; // xmm0
  _QWORD *v81; // r8
  _QWORD *v82; // rcx
  unsigned __int64 v83; // rax
  signed __int64 v84; // rcx
  __m128 v86; // [rsp+20h] [rbp-1A8h]
  __m128 v87; // [rsp+30h] [rbp-198h]
  __m128 v88; // [rsp+40h] [rbp-188h]
  __m128 v89; // [rsp+50h] [rbp-178h]
  __m128 v90; // [rsp+70h] [rbp-158h]
  __m128 v91; // [rsp+80h] [rbp-148h]
  __m128 v92; // [rsp+90h] [rbp-138h]
  __m128 v93; // [rsp+A0h] [rbp-128h]
  __m128 v94; // [rsp+B0h] [rbp-118h]
  __m128i v95; // [rsp+C0h] [rbp-108h]
  __m128 v96; // [rsp+D0h] [rbp-F8h]
  __m128 v97; // [rsp+E0h] [rbp-E8h]
  __m128 v98; // [rsp+F0h] [rbp-D8h]
  __m128 v99; // [rsp+100h] [rbp-C8h]
  __m128 v100; // [rsp+110h] [rbp-B8h]

  v5 = this;
  v6 = results;
  v7 = input;
  v8 = result;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtrayBundleTriangle";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = v5->m_vertexA.m_quad;
  v14 = 0i64;
  v15 = 0i64;
  v16 = 0i64;
  v17 = _mm_sub_ps(v7->m_to.m_vertices[1].m_quad, v7->m_from.m_vertices[1].m_quad);
  v18 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(
            (__m128)LODWORD(v6->m_outputs[0].m_hitFraction),
            (__m128)LODWORD(v6->m_outputs[2].m_hitFraction)),
          _mm_unpacklo_ps(
            (__m128)LODWORD(v6->m_outputs[1].m_hitFraction),
            (__m128)LODWORD(v6->m_outputs[3].m_hitFraction)));
  v87 = _mm_sub_ps(v7->m_to.m_vertices[0].m_quad, v7->m_from.m_vertices[0].m_quad);
  v19 = _mm_sub_ps(v7->m_to.m_vertices[2].m_quad, v7->m_from.m_vertices[2].m_quad);
  v20 = _mm_sub_ps(v5->m_vertexC.m_quad, v13);
  v21 = _mm_sub_ps(v5->m_vertexB.m_quad, v13);
  v94 = _mm_shuffle_ps(v13, v13, 85);
  v93 = v18;
  v90 = v18;
  v86 = v17;
  v22 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v21);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v20);
  v24 = _mm_shuffle_ps(v13, v13, 0);
  v25 = _mm_shuffle_ps(v13, v13, 170);
  v26 = _mm_sub_ps(v22, v23);
  v27 = v7->m_from.m_vertices[0].m_quad;
  v96 = v24;
  v28 = _mm_sub_ps(v27, v24);
  v29 = _mm_shuffle_ps(v26, v26, 201);
  v30 = _mm_sub_ps(v7->m_from.m_vertices[1].m_quad, v94);
  v31 = _mm_sub_ps(v7->m_from.m_vertices[2].m_quad, v25);
  v32 = _mm_shuffle_ps(v29, v29, 85);
  v91 = _mm_shuffle_ps(v29, v29, 0);
  v88 = v32;
  v89 = _mm_shuffle_ps(v29, v29, 170);
  v95 = (__m128i)_mm_add_ps(_mm_add_ps(_mm_mul_ps(v32, v30), _mm_mul_ps(v91, v28)), _mm_mul_ps(v89, v31));
  v33 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v32, v17), _mm_mul_ps(v91, v87)), _mm_mul_ps(v89, v19));
  v34 = _mm_rcp_ps(v33);
  v35 = _mm_add_ps(v33, (__m128)v95);
  v36 = _mm_xor_ps(
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
          _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v33)), v34), (__m128)v95));
  v92 = v36;
  v37 = _mm_and_ps(
          _mm_andnot_ps(
            _mm_and_ps(
              _mm_or_ps(_mm_cmpeqps((__m128)0i64, v35), _mm_cmpneqps((__m128)0i64, (__m128)v95)),
              _mm_cmpleps((__m128)0i64, _mm_mul_ps(v35, (__m128)v95))),
            _mm_cmpltps(v36, v18)),
          mask->m_mask);
  *v8 = (hkVector4fComparison)v37;
  if ( _mm_movemask_ps(v37) )
  {
    v38 = _mm_add_ps(_mm_mul_ps(v86, v36), v7->m_from.m_vertices[1].m_quad);
    v39 = _mm_add_ps(_mm_mul_ps(v19, v36), v7->m_from.m_vertices[2].m_quad);
    v40 = _mm_sub_ps(v38, v94);
    v41 = v38;
    v42 = _mm_add_ps(_mm_mul_ps(v87, v36), v7->m_from.m_vertices[0].m_quad);
    v43 = _mm_sub_ps(v39, v25);
    v44 = _mm_mul_ps(v29, v29);
    v45 = v42;
    v46 = _mm_sub_ps(v42, v96);
    v47 = v39;
    v48 = v5->m_vertexB.m_quad;
    v49 = _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                _mm_shuffle_ps(v44, v44, 170))),
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0));
    v50 = _mm_sub_ps(v42, _mm_shuffle_ps(v48, v48, 0));
    v51 = _mm_sub_ps(v38, _mm_shuffle_ps(v5->m_vertexB.m_quad, v48, 85));
    v52 = _mm_sub_ps(v39, _mm_shuffle_ps(v48, v48, 170));
    v53 = _mm_and_ps(
            _mm_cmpleps(
              v49,
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v50, _mm_sub_ps(_mm_mul_ps(v88, v43), _mm_mul_ps(v89, v40))),
                  _mm_mul_ps(v51, _mm_sub_ps(_mm_mul_ps(v89, v46), _mm_mul_ps(v91, v43)))),
                _mm_mul_ps(v52, _mm_sub_ps(_mm_mul_ps(v91, v40), _mm_mul_ps(v88, v46))))),
            v37);
    v54 = _mm_sub_ps(_mm_mul_ps(v91, v51), _mm_mul_ps(v88, v50));
    v55 = _mm_mul_ps(v89, v51);
    v56 = v5->m_vertexC.m_quad;
    v57 = _mm_sub_ps(v45, _mm_shuffle_ps(v56, v56, 0));
    v58 = v57;
    v59 = _mm_sub_ps(v41, _mm_shuffle_ps(v5->m_vertexC.m_quad, v56, 85));
    v60 = _mm_sub_ps(v47, _mm_shuffle_ps(v5->m_vertexC.m_quad, v5->m_vertexC.m_quad, 170));
    v61 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(v57, _mm_sub_ps(_mm_mul_ps(v88, v52), v55)),
              _mm_mul_ps(v59, _mm_sub_ps(_mm_mul_ps(v89, v50), _mm_mul_ps(v91, v52)))),
            _mm_mul_ps(v60, v54));
    v62 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(v46, _mm_sub_ps(_mm_mul_ps(v60, v88), _mm_mul_ps(v59, v89))),
              _mm_mul_ps(v40, _mm_sub_ps(_mm_mul_ps(v58, v89), _mm_mul_ps(v60, v91)))),
            _mm_mul_ps(v43, _mm_sub_ps(_mm_mul_ps(v59, v91), _mm_mul_ps(v58, v88))));
    v14 = 0i64;
    v63 = _mm_and_ps(_mm_cmpleps(v49, v62), _mm_and_ps(_mm_cmpleps(v49, v61), v53));
    *v8 = (hkVector4fComparison)v63;
    v90 = _mm_or_ps(_mm_and_ps(v63, v92), _mm_andnot_ps(v63, v93));
    v64 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
            _mm_shuffle_ps(v44, v44, 170));
    v65 = _mm_rsqrt_ps(v64);
    v66 = _mm_mul_ps(
            v29,
            _mm_andnot_ps(
              _mm_cmpleps(v64, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v65, v64), v65)),
                _mm_mul_ps(*(__m128 *)_xmm, v65))));
    v67 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v95, 0x1Fu), 0x1Fu);
    v15 = _mm_or_ps(
            _mm_andnot_ps(v8->m_mask, (__m128)0i64),
            _mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v66, v66, 0), v67), v8->m_mask));
    v68 = _mm_or_ps(
            _mm_andnot_ps(v8->m_mask, (__m128)0i64),
            _mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v66, v66, 85), v67), v8->m_mask));
    v16 = _mm_or_ps(
            _mm_andnot_ps(v8->m_mask, (__m128)0i64),
            _mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v66, v66, 170), v67), v8->m_mask));
  }
  else
  {
    v68 = 0i64;
  }
  v69 = v15;
  v70 = _mm_shuffle_ps(v15, v68, 238);
  v71 = _mm_shuffle_ps(v69, v68, 68);
  v72 = _mm_shuffle_ps(v16, v14, 68);
  v73 = _mm_shuffle_ps(v16, v14, 238);
  v74 = 1;
  v75 = &v97;
  v76 = &v90;
  v77 = 4i64;
  v97 = _mm_shuffle_ps(v71, v72, 136);
  v98 = _mm_shuffle_ps(v71, v72, 221);
  v99 = _mm_shuffle_ps(v70, v73, 136);
  v78 = v8->m_mask;
  v100 = _mm_shuffle_ps(v70, v73, 221);
  v79 = _mm_movemask_ps(v78);
  do
  {
    if ( v74 & v79 )
    {
      v80 = *v75;
      v6->m_outputs[0].m_hitFraction = *(float *)v76->m128_u64;
      v6->m_outputs[0].m_normal.m_quad = v80;
      v6->m_outputs[0].m_shapeKeys[v6->m_outputs[0].m_shapeKeyIndex] = -1;
    }
    v74 = __ROL4__(v74, 1);
    v76 = (__m128 *)((char *)v76 + 4);
    ++v75;
    v6 = (hkpShapeRayBundleCastOutput *)((char *)v6 + 80);
    --v77;
  }
  while ( v77 );
  v81 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v82 = (_QWORD *)v81[1];
  if ( (unsigned __int64)v82 < v81[3] )
  {
    *v82 = "Et";
    v83 = __rdtsc();
    v84 = (signed __int64)(v82 + 2);
    *(_DWORD *)(v84 - 8) = v83;
    v81[1] = v84;
  }
  return v8;
}

