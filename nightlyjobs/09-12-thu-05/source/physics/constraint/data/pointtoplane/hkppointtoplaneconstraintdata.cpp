// File Line: 16
// RVA: 0xD46DF0
void __fastcall hkpPointToPlaneConstraintData::hkpPointToPlaneConstraintData(hkpPointToPlaneConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPointToPlaneConstraintData::`vftable;
  this->m_atoms.m_transforms.m_type.m_storage = 2;
  this->m_atoms.m_lin.m_type.m_storage = 7;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_translation = 0i64;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = 0i64;
  this->m_atoms.m_lin.m_axisIndex = 0;
}

// File Line: 27
// RVA: 0xD46E90
void __fastcall hkpPointToPlaneConstraintData::setInWorldSpace(hkpPointToPlaneConstraintData *this, hkTransformf *bodyATransform, hkTransformf *bodyBTransform, hkVector4f *pivotW, hkVector4f *planeNormalW)
{
  hkTransformf *v5; // rdi
  hkpPointToPlaneConstraintData *v6; // rbp
  hkVector4f *v7; // rbx
  int v8; // esi
  signed __int64 v9; // rbx
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm7
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm1

  v5 = bodyBTransform;
  v6 = this;
  v7 = pivotW;
  hkVector4f::setTransformedInversePos(&this->m_atoms.m_transforms.m_transformA.m_translation, bodyATransform, pivotW);
  hkVector4f::setTransformedInversePos(&v6->m_atoms.m_transforms.m_transformB.m_translation, v5, v7);
  v6->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v6->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v6->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v8 = (unsigned __int8)v6->m_atoms.m_lin.m_axisIndex;
  v9 = 16i64 * (unsigned __int8)v6->m_atoms.m_lin.m_axisIndex;
  hkVector4f::setRotatedInverseDir(
    (hkVector4f *)((char *)&v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 + v9),
    (hkMatrix3f *)&v5->m_rotation.m_col0,
    planeNormalW);
  v10 = _mm_shuffle_ps(
          *(__m128 *)((char *)&v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + v9),
          _mm_unpackhi_ps(
            *(__m128 *)((char *)&v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + v9),
            (__m128)0i64),
          196);
  v11 = _mm_shuffle_ps(v10, v10, 241);
  v12 = _mm_shuffle_ps(v10, v10, 206);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_mul_ps(v11, v11);
  v15 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)));
  v16 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v15, v11), _mm_and_ps(v12, v15)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
              _mm_mul_ps(*(__m128 *)_xmm, v19))),
          v16);
  *(&v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + (v8 + 1) % 3) = v20;
  v21 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(v20, v20, 201),
            *(__m128 *)((char *)&v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + v9)),
          _mm_mul_ps(
            _mm_shuffle_ps(
              *(__m128 *)((char *)&v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + v9),
              *(__m128 *)((char *)&v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + v9),
              201),
            v20));
  *(&v6->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + (v8 + 2) % 3) = _mm_shuffle_ps(v21, v21, 201);
}

// File Line: 44
// RVA: 0xD47080
void __fastcall hkpPointToPlaneConstraintData::setInBodySpace(hkpPointToPlaneConstraintData *this, hkVector4f *pivotA, hkVector4f *pivotB, hkVector4f *planeNormalB)
{
  __m128 v4; // xmm6
  int v5; // er10
  signed __int64 v6; // r8
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm2
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm1

  this->m_atoms.m_transforms.m_transformA.m_translation = (hkVector4f)pivotA->m_quad;
  this->m_atoms.m_transforms.m_transformB.m_translation = (hkVector4f)pivotB->m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_transforms.m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v4 = planeNormalB->m_quad;
  v5 = (unsigned __int8)this->m_atoms.m_lin.m_axisIndex;
  v6 = 2i64 * (unsigned __int8)this->m_atoms.m_lin.m_axisIndex;
  *(hkVector4f *)((char *)&this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0 + 8 * v6) = (hkVector4f)planeNormalB->m_quad;
  v7 = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, (__m128)0i64), 196);
  v8 = _mm_shuffle_ps(v7, v7, 241);
  v9 = _mm_shuffle_ps(v7, v7, 206);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_mul_ps(v8, v8);
  v12 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)));
  v13 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v12, v8), _mm_and_ps(v9, v12)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16))),
          v13);
  *(&this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + (v5 + 1) % 3) = v17;
  v18 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(v17, v17, 201),
            *(__m128 *)((char *)&this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + 8 * v6)),
          _mm_mul_ps(
            _mm_shuffle_ps(
              *(__m128 *)((char *)&this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + 8 * v6),
              *(__m128 *)((char *)&this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + 8 * v6),
              201),
            v17));
  *(&this->m_atoms.m_transforms.m_transformB.m_rotation.m_col0.m_quad + (v5 + 2) % 3) = _mm_shuffle_ps(v18, v18, 201);
}

// File Line: 62
// RVA: 0xD472B0
void __fastcall hkpPointToPlaneConstraintData::getConstraintInfo(hkpPointToPlaneConstraintData *this, hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil((hkpConstraintAtom *)&this->m_atoms.m_transforms.m_type, 160, infoOut);
}

// File Line: 67
// RVA: 0xD472D0
void __fastcall hkpPointToPlaneConstraintData::getRuntimeInfo(hkpPointToPlaneConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  if ( wantRuntime.m_bool )
  {
    infoOut->m_numSolverResults = 1;
    infoOut->m_sizeOfExternalRuntime = 8;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 83
// RVA: 0xD47240
hkBool *__fastcall hkpPointToPlaneConstraintData::isValid(hkpPointToPlaneConstraintData *this, hkBool *result)
{
  hkpPointToPlaneConstraintData *v2; // rdi
  hkBool *v3; // rbx
  hkBool *v4; // rax

  v2 = this;
  v3 = result;
  if ( hkRotationf::isOrthonormal(&this->m_atoms.m_transforms.m_transformA.m_rotation, 0.0000099999997)
    && hkRotationf::isOrthonormal(&v2->m_atoms.m_transforms.m_transformB.m_rotation, 0.0000099999997) )
  {
    v3->m_bool = 1;
    v4 = v3;
  }
  else
  {
    v3->m_bool = 0;
    v4 = v3;
  }
  return v4;
}

// File Line: 89
// RVA: 0xD47230
signed __int64 __fastcall hkpPointToPlaneConstraintData::getType(hkpPointToPlaneConstraintData *this)
{
  return 14i64;
}

