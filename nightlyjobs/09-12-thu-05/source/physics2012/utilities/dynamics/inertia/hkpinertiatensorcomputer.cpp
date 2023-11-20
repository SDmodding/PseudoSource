// File Line: 37
// RVA: 0xE0E710
void __fastcall scaleMassProperties_0(hkSimdFloat32 *scale, hkMassProperties *massProperties)
{
  hkMassProperties *v2; // rbx
  float v3; // xmm6_4

  v2 = massProperties;
  v3 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v2->m_mass), (__m128)LODWORD(v2->m_mass), 0))
     * scale->m_real.m128_f32[0];
  hkMatrix3f::mul(&massProperties->m_inertiaTensor, scale);
  v2->m_mass = v3;
}

// File Line: 47
// RVA: 0xE0E360
void __fastcall hkpInertiaTensorComputer::setShapeVolumeMassProperties(hkpShape *shape, float mass, hkpRigidBodyCinfo *bodyInfo)
{
  hkpRigidBodyCinfo *v3; // rbx
  hkVector4f v4; // xmm1
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  hkMassProperties result; // [rsp+20h] [rbp-58h]

  v3 = bodyInfo;
  *(_QWORD *)&result.m_volume = 0i64;
  result.m_centerOfMass = 0i64;
  result.m_inertiaTensor.m_col0 = 0i64;
  result.m_inertiaTensor.m_col1 = 0i64;
  result.m_inertiaTensor.m_col2 = 0i64;
  hkpInertiaTensorComputer::computeShapeVolumeMassProperties((hkcdShape *)&shape->vfptr, mass, &result);
  v4.m_quad = (__m128)result.m_centerOfMass;
  v3->m_mass = result.m_mass;
  v5.m_quad = (__m128)result.m_inertiaTensor.m_col0;
  v3->m_centerOfMass = (hkVector4f)v4.m_quad;
  v6.m_quad = (__m128)result.m_inertiaTensor.m_col1;
  v3->m_inertiaTensor.m_col0 = (hkVector4f)v5.m_quad;
  v7.m_quad = (__m128)result.m_inertiaTensor.m_col2;
  v3->m_inertiaTensor.m_col1 = (hkVector4f)v6.m_quad;
  v3->m_inertiaTensor.m_col2 = (hkVector4f)v7.m_quad;
}

// File Line: 60
// RVA: 0xE0E3E0
void __fastcall hkpInertiaTensorComputer::setMassProperties(hkMassProperties *massProperties, hkpRigidBodyCinfo *bodyInfo)
{
  bodyInfo->m_mass = massProperties->m_mass;
  bodyInfo->m_centerOfMass = massProperties->m_centerOfMass;
  bodyInfo->m_inertiaTensor.m_col0 = massProperties->m_inertiaTensor.m_col0;
  bodyInfo->m_inertiaTensor.m_col1 = massProperties->m_inertiaTensor.m_col1;
  bodyInfo->m_inertiaTensor.m_col2 = massProperties->m_inertiaTensor.m_col2;
}

// File Line: 68
// RVA: 0xE0E450
void __fastcall hkpInertiaTensorComputer::setAndScaleToMass(hkMassProperties *props, hkSimdFloat32 *mass, hkpRigidBodyCinfo *bodyInfo)
{
  __m128 v3; // xmm2
  hkMassProperties *v4; // rax
  __m128 v5; // xmm1
  hkVector4f v6; // xmm0
  hkVector4f *v7; // rcx
  hkSimdFloat32 scale; // [rsp+20h] [rbp-18h]

  v3 = mass->m_real;
  v4 = props;
  v5 = _mm_shuffle_ps((__m128)LODWORD(props->m_mass), (__m128)LODWORD(props->m_mass), 0);
  LODWORD(bodyInfo->m_mass) = *mass;
  scale.m_real = _mm_div_ps(v3, v5);
  v6.m_quad = (__m128)props->m_centerOfMass;
  v7 = &bodyInfo->m_inertiaTensor.m_col0;
  bodyInfo->m_centerOfMass = (hkVector4f)v6.m_quad;
  *v7 = v4->m_inertiaTensor.m_col0;
  v7[1] = v4->m_inertiaTensor.m_col1;
  v7[2] = v4->m_inertiaTensor.m_col2;
  hkMatrix3f::mul(&bodyInfo->m_inertiaTensor, &scale);
}

// File Line: 82
// RVA: 0xE0E420
void __fastcall hkpInertiaTensorComputer::setAndScaleToDensity(hkMassProperties *props, hkSimdFloat32 *density, hkpRigidBodyCinfo *bodyInfo)
{
  hkSimdFloat32 mass; // [rsp+20h] [rbp-18h]

  mass.m_real = _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(props->m_volume), (__m128)LODWORD(props->m_volume), 0),
                  density->m_real);
  hkpInertiaTensorComputer::setAndScaleToMass(props, &mass, bodyInfo);
}

// File Line: 92
// RVA: 0xE0E4C0
void __fastcall hkpInertiaTensorComputer::clipInertia(float maxInertiaRatio, hkpRigidBodyCinfo *bodyInfo)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm4
  __m128 v4; // xmm4
  __m128 v5; // xmm5

  v2 = bodyInfo->m_inertiaTensor.m_col0.m_quad;
  v3 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141AA7620,
           _mm_or_ps(
             _mm_and_ps((__m128)xmmword_141AA7600, bodyInfo->m_inertiaTensor.m_col1.m_quad),
             _mm_andnot_ps((__m128)xmmword_141AA7600, v2))),
         _mm_and_ps(bodyInfo->m_inertiaTensor.m_col2.m_quad, (__m128)xmmword_141AA7620));
  v4 = _mm_max_ps(
         v3,
         _mm_div_ps(
           _mm_max_ps(_mm_shuffle_ps(v3, v3, 170), _mm_max_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0))),
           _mm_shuffle_ps((__m128)LODWORD(maxInertiaRatio), (__m128)LODWORD(maxInertiaRatio), 0)));
  v2.m128_f32[0] = v4.m128_f32[0];
  bodyInfo->m_inertiaTensor.m_col0.m_quad = v2;
  v5 = _mm_andnot_ps((__m128)xmmword_141AA7600, bodyInfo->m_inertiaTensor.m_col1.m_quad);
  bodyInfo->m_inertiaTensor.m_col2.m_quad = _mm_or_ps(
                                              _mm_and_ps((__m128)xmmword_141AA7620, v4),
                                              _mm_andnot_ps(
                                                (__m128)xmmword_141AA7620,
                                                bodyInfo->m_inertiaTensor.m_col2.m_quad));
  bodyInfo->m_inertiaTensor.m_col1.m_quad = _mm_or_ps(_mm_and_ps(v4, (__m128)xmmword_141AA7600), v5);
}

// File Line: 119
// RVA: 0xE0E230
void __fastcall hkpInertiaTensorComputer::computeShapeVolumeMassProperties(hkcdShape *shape, float mass, hkMassProperties *result)
{
  hkMassProperties *v3; // rdi
  hkcdShape *v4; // rbx
  float v5; // xmm7_4
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  float v9; // xmm6_4
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkMassProperties massPropertiesOut; // [rsp+18h] [rbp-69h]
  hkTransformf transform; // [rsp+68h] [rbp-19h]
  hkSimdFloat32 scale; // [rsp+A8h] [rbp+27h]

  v3 = result;
  v4 = shape;
  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  v5 = mass;
  v6 = direction.m_quad;
  massPropertiesOut.m_centerOfMass = 0i64;
  massPropertiesOut.m_inertiaTensor.m_col0 = 0i64;
  massPropertiesOut.m_inertiaTensor.m_col1 = 0i64;
  massPropertiesOut.m_inertiaTensor.m_col2 = 0i64;
  transform.m_translation = 0i64;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  computeRecursiveShapeVolumeMassProperties(
    shape,
    (hkTransformf *)((char *)&transform + 8),
    0.0,
    (hkMassProperties *)((char *)&massPropertiesOut + 8));
  v7 = (__m128)LODWORD(massPropertiesOut.m_volume);
  if ( massPropertiesOut.m_volume != 0.0
    || (computeRecursiveShapeVolumeMassProperties(v4, &transform, 0.0099999998, &massPropertiesOut),
        v7 = (__m128)LODWORD(massPropertiesOut.m_volume),
        massPropertiesOut.m_volume != 0.0) )
  {
    v6.m128_f32[0] = v5;
    v8 = _mm_div_ps(_mm_shuffle_ps(v6, v6, 0), _mm_shuffle_ps(v7, v7, 0));
    v9 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(massPropertiesOut.m_mass), (__m128)LODWORD(massPropertiesOut.m_mass), 0))
       * v8.m128_f32[0];
    scale.m_real = v8;
    hkMatrix3f::mul(&massPropertiesOut.m_inertiaTensor, &scale);
    v3->m_volume = massPropertiesOut.m_volume;
    massPropertiesOut.m_mass = v9;
    v3->m_centerOfMass = massPropertiesOut.m_centerOfMass;
    v10.m_quad = (__m128)massPropertiesOut.m_inertiaTensor.m_col1;
    v3->m_mass = massPropertiesOut.m_mass;
    v11.m_quad = (__m128)massPropertiesOut.m_inertiaTensor.m_col0;
    v3->m_inertiaTensor.m_col1 = (hkVector4f)v10.m_quad;
    v3->m_inertiaTensor.m_col0 = (hkVector4f)v11.m_quad;
    v3->m_inertiaTensor.m_col2 = massPropertiesOut.m_inertiaTensor.m_col2;
  }
}

// File Line: 167
// RVA: 0xE0E750
void __usercall computeRecursiveShapeVolumeMassProperties(hkcdShape *shape@<rcx>, hkTransformf *transform@<rdx>, float minTriangleThickness@<xmm2>, hkMassProperties *massPropertiesOut@<r9>, __m128 *a5@<xmm3>, __m128 *a6@<xmm4>)
{
  __int64 v6; // rax
  hkMassProperties *v7; // rsi
  hkTransformf *v8; // rdi
  hkcdShape *v9; // rbx
  float v10; // xmm6_4
  __m128 v11; // xmm2
  float v12; // xmm2_4
  float v13; // xmm0_4
  hkVector4f v14; // xmm1
  hkBaseObjectVtbl *v15; // rcx
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm7
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm6
  __m128 v25; // xmm4
  __m128 v26; // xmm4
  hkVector4f v27; // xmm0
  hkcdShape *v28; // rcx
  __m128 v29; // xmm2
  hkVector4f v30; // xmm1
  hkVector4f v31; // xmm3
  __m128 v32; // xmm5
  __m128 v33; // xmm4
  __m128 v34; // xmm0
  void *v35; // rbx
  unsigned int i; // esi
  hkcdShape *v37; // rax
  __m128 v38; // xmm7
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm5
  __m128 v44; // xmm8
  float v45; // xmm0_4
  float v46; // xmm6_4
  int v47; // xmm0_4
  int v48; // xmm1_4
  __int128 v49; // xmm0
  __int128 v50; // xmm1
  __int128 v51; // xmm0
  __int128 v52; // xmm1
  __int128 v53; // xmm0
  __int128 v54; // xmm1
  __int128 v55; // xmm0
  __int128 v56; // xmm1
  __int64 mass; // [rsp+20h] [rbp-C8h]
  hkVector4f halfExtents; // [rsp+40h] [rbp-A8h]
  hkResult v59; // [rsp+50h] [rbp-98h]
  char startAxis[24]; // [rsp+60h] [rbp-88h]
  __int128 v61; // [rsp+78h] [rbp-70h]
  __int128 v62; // [rsp+88h] [rbp-60h]
  __int128 v63; // [rsp+98h] [rbp-50h]
  unsigned __int64 v64; // [rsp+A8h] [rbp-40h]
  int v65; // [rsp+B0h] [rbp-38h]
  int v66; // [rsp+B4h] [rbp-34h]
  __int64 v67; // [rsp+B8h] [rbp-30h]
  hkResult v68; // [rsp+C0h] [rbp-28h]
  hkResult v69; // [rsp+C4h] [rbp-24h]
  hkTransformf bTc; // [rsp+C8h] [rbp-20h]
  hkTransformf transforma; // [rsp+108h] [rbp+20h]
  hkSimdFloat32 scale; // [rsp+148h] [rbp+60h]
  hkMassProperties massPropertiesOuta; // [rsp+158h] [rbp+70h]
  hkArray<hkMassElement,hkContainerHeapAllocator> elements; // [rsp+1A8h] [rbp+C0h]
  int v75; // [rsp+1C8h] [rbp+E0h]
  int v76; // [rsp+1CCh] [rbp+E4h]
  __int128 v77; // [rsp+1D8h] [rbp+F0h]
  __int128 v78; // [rsp+1E8h] [rbp+100h]
  __int128 v79; // [rsp+1F8h] [rbp+110h]
  __int128 v80; // [rsp+208h] [rbp+120h]
  __m128 v81; // [rsp+218h] [rbp+130h]
  __m128 v82; // [rsp+228h] [rbp+140h]
  __m128 v83; // [rsp+238h] [rbp+150h]
  __int128 v84; // [rsp+248h] [rbp+160h]
  int v85; // [rsp+258h] [rbp+170h]
  float v86; // [rsp+25Ch] [rbp+174h]
  __int128 v87; // [rsp+268h] [rbp+180h]
  __int128 v88; // [rsp+278h] [rbp+190h]
  __int128 v89; // [rsp+288h] [rbp+1A0h]
  __int128 v90; // [rsp+298h] [rbp+1B0h]
  __int128 v91; // [rsp+2A8h] [rbp+1C0h]
  __int128 v92; // [rsp+2B8h] [rbp+1D0h]
  __int128 v93; // [rsp+2C8h] [rbp+1E0h]
  __int128 v94; // [rsp+2D8h] [rbp+1F0h]
  hkResult result; // [rsp+418h] [rbp+330h]
  hkMassProperties *v96; // [rsp+430h] [rbp+348h]

  v6 = (unsigned __int8)shape->m_type.m_storage;
  v7 = massPropertiesOut;
  v8 = transform;
  v9 = shape;
  v10 = minTriangleThickness;
  *(_OWORD *)&startAxis[8] = 0i64;
  v61 = 0i64;
  v62 = 0i64;
  v63 = 0i64;
  switch ( 0 )
  {
    case 0:
      hkInertiaTensorComputer::computeSphereVolumeMassProperties(
        &result,
        *(float *)&shape[1].m_memSizeAndFlags,
        1.0,
        (hkMassProperties *)&startAxis[16],
        a5,
        a6);
      goto LABEL_22;
    case 1:
      v38 = *(__m128 *)&shape[2].vfptr;
      v39 = _mm_sub_ps(*(__m128 *)&shape[2].m_type.m_storage, v38);
      v40 = _mm_mul_ps(v39, v39);
      v41 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
              _mm_shuffle_ps(v40, v40, 170));
      v42 = _mm_rsqrt_ps(v41);
      v43 = _mm_mul_ps(
              _mm_mul_ps(
                v39,
                _mm_andnot_ps(
                  _mm_cmpleps(v41, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v41), v42)),
                    _mm_mul_ps(*(__m128 *)_xmm, v42)))),
              _mm_shuffle_ps(
                (__m128)*(unsigned int *)&shape[1].m_memSizeAndFlags,
                (__m128)*(unsigned int *)&shape[1].m_memSizeAndFlags,
                0));
      v44 = _mm_add_ps(*(__m128 *)&shape[2].m_type.m_storage, v43);
      *(__m128 *)startAxis = _mm_sub_ps(v38, v43);
      halfExtents.m_quad = v44;
      v45 = hkpCylinderShape::getCylinderRadius((hkpCylinderShape *)shape);
      LODWORD(mass) = (_DWORD)FLOAT_1_0;
      hkInertiaTensorComputer::computeCylinderVolumeMassProperties(
        (hkResult *)&v67 + 1,
        (hkVector4f *)startAxis,
        &halfExtents,
        v45 + *(float *)&v9[1].m_memSizeAndFlags,
        0i64,
        mass,
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 2:
      v13 = *(float *)&shape[1].m_memSizeAndFlags;
      v59.m_enum = LODWORD(minTriangleThickness);
      result.m_enum = LODWORD(v13);
      hkInertiaTensorComputer::computeTriangleSurfaceMassProperties(
        &v68,
        (hkVector4f *)&shape[2],
        (hkVector4f *)&shape[2].m_type,
        (hkVector4f *)&shape[3].m_memSizeAndFlags,
        a6,
        1.0,
        fmaxf(v13, minTriangleThickness),
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 3:
      v11 = _mm_shuffle_ps(
              (__m128)*(unsigned int *)&shape[1].m_memSizeAndFlags,
              (__m128)*(unsigned int *)&shape[1].m_memSizeAndFlags,
              0);
      halfExtents.m_quad = _mm_add_ps(
                             *(__m128 *)&shape[2].vfptr,
                             _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, (__m128)0i64), 196));
      hkInertiaTensorComputer::computeBoxVolumeMassProperties(
        &v59,
        &halfExtents,
        1.0,
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 4:
      LODWORD(mass) = (_DWORD)FLOAT_1_0;
      hkInertiaTensorComputer::computeCapsuleVolumeMassProperties(
        &v69,
        (hkVector4f *)&shape[2],
        (hkVector4f *)&shape[2].m_type,
        *(float *)&shape[1].m_memSizeAndFlags,
        0i64,
        mass,
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 5:
      halfExtents.m_quad.m128_u64[0] = 0i64;
      halfExtents.m_quad.m128_u64[1] = 0x8000000000000000i64;
      hkpConvexVerticesShape::getOriginalVertices(
        (hkpConvexVerticesShape *)shape,
        (hkArray<hkVector4f,hkContainerHeapAllocator> *)&halfExtents);
      v12 = *(float *)&v9[1].m_memSizeAndFlags;
      v64 = halfExtents.m_quad.m128_u64[0];
      v65 = halfExtents.m_quad.m128_i32[2];
      v66 = 16;
      hkInertiaTensorComputer::computeConvexHullMassProperties(
        (hkResult *)&v67,
        (hkStridedVertices *)&v64,
        v12,
        (hkMassProperties *)&startAxis[16]);
      halfExtents.m_quad.m128_i32[2] = 0;
      if ( halfExtents.m_quad.m128_i32[3] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          (void *)halfExtents.m_quad.m128_u64[0],
          16 * halfExtents.m_quad.m128_i32[3]);
LABEL_22:
      if ( *(float *)&startAxis[16] != 0.0 )
      {
        scale.m_real = _mm_shuffle_ps(
                         (__m128)*(unsigned int *)&startAxis[16],
                         (__m128)*(unsigned int *)&startAxis[16],
                         0);
        v46 = COERCE_FLOAT(_mm_shuffle_ps((__m128)*(unsigned int *)&startAxis[20], (__m128)*(unsigned int *)&startAxis[20], 0))
            * scale.m_real.m128_f32[0];
        hkMatrix3f::mul((hkMatrix3f *)&v61, &scale);
        v47 = LODWORD(v7->m_volume);
        v48 = LODWORD(v7->m_mass);
        v84 = 0i64;
        v75 = v47;
        v76 = v48;
        *(float *)&startAxis[20] = v46;
        v49 = (__int128)v7->m_centerOfMass;
        v50 = (__int128)v7->m_inertiaTensor.m_col0;
        elements.m_data = (hkMassElement *)&v75;
        elements.m_capacityAndFlags = -2147483646;
        elements.m_size = 2;
        v77 = v49;
        v51 = (__int128)v7->m_inertiaTensor.m_col1;
        v78 = v50;
        v52 = (__int128)v7->m_inertiaTensor.m_col2;
        v79 = v51;
        v81 = ::transform.m_quad;
        v80 = v52;
        v83 = stru_141A71280.m_quad;
        v85 = *(_DWORD *)&startAxis[16];
        v82 = direction.m_quad;
        v86 = v46;
        v87 = *(_OWORD *)&startAxis[8];
        v88 = v61;
        v89 = v62;
        v53 = (__int128)v8->m_rotation.m_col0;
        v90 = v63;
        v54 = (__int128)v8->m_rotation.m_col1;
        v91 = v53;
        v55 = (__int128)v8->m_rotation.m_col2;
        v92 = v54;
        v56 = (__int128)v8->m_translation;
        v93 = v55;
        v94 = v56;
        hkInertiaTensorComputer::combineMassProperties(&result, &elements, v7);
        elements.m_size = 0;
        if ( elements.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            elements.m_data,
            144 * (elements.m_capacityAndFlags & 0x3FFFFFFF));
      }
      break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 13:
    case 15:
    case 16:
    case 17:
    case 18:
    case 22:
    case 26:
    case 27:
      v35 = shape->vfptr[7].__vecDelDtor((hkBaseObject *)shape, 1073741824u);
      for ( i = (*(__int64 (__fastcall **)(void *))(*(_QWORD *)v35 + 16i64))(v35);
            i != -1;
            i = (*(__int64 (__fastcall **)(void *, _QWORD))(*(_QWORD *)v35 + 24i64))(v35, i) )
      {
        v37 = (hkcdShape *)(*(__int64 (__fastcall **)(void *, _QWORD, hkArray<hkMassElement,hkContainerHeapAllocator> *))(*(_QWORD *)v35 + 40i64))(
                             v35,
                             i,
                             &elements);
        if ( v37 )
          computeRecursiveShapeVolumeMassProperties(v37, v8, minTriangleThickness, v96);
      }
      break;
    case 10:
      bTc.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
      bTc.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
      v14.m_quad = *(__m128 *)&shape[2].m_type.m_storage;
      bTc.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      bTc.m_translation = (hkVector4f)v14.m_quad;
      hkTransformf::setMul(&transforma, transform, &bTc);
      computeRecursiveShapeVolumeMassProperties((hkcdShape *)v9[2].vfptr, &transforma, minTriangleThickness, v7);
      break;
    case 11:
      v15 = shape[2].vfptr;
      massPropertiesOuta.m_centerOfMass = 0i64;
      massPropertiesOuta.m_inertiaTensor.m_col0 = 0i64;
      *(_QWORD *)&massPropertiesOuta.m_volume = 0i64;
      massPropertiesOuta.m_inertiaTensor.m_col1 = 0i64;
      massPropertiesOuta.m_inertiaTensor.m_col2 = 0i64;
      computeRecursiveShapeVolumeMassProperties(
        (hkcdShape *)v15,
        (hkTransformf *)&::transform,
        minTriangleThickness,
        &massPropertiesOuta);
      hkQsTransformf::setFromTransformNoScale((hkQsTransformf *)&transforma, v8);
      v16 = *(__m128 *)&v9[2].m_type.m_storage;
      v17 = _mm_mul_ps(transforma.m_rotation.m_col1.m_quad, v16);
      v18 = _mm_shuffle_ps(transforma.m_rotation.m_col1.m_quad, transforma.m_rotation.m_col1.m_quad, 201);
      v19 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), transforma.m_rotation.m_col1.m_quad),
              _mm_mul_ps(v18, v16));
      v20 = _mm_shuffle_ps(transforma.m_rotation.m_col1.m_quad, transforma.m_rotation.m_col1.m_quad, 255);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                    _mm_shuffle_ps(v17, v17, 170)),
                  transforma.m_rotation.m_col1.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v16)),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v20));
      bTc.m_rotation.m_col0.m_quad = _mm_add_ps(_mm_add_ps(v21, v21), transforma.m_rotation.m_col0.m_quad);
      v22 = *(__m128 *)&v9[3].m_memSizeAndFlags;
      v23 = _mm_shuffle_ps(*(__m128 *)&v9[3].m_memSizeAndFlags, *(__m128 *)&v9[3].m_memSizeAndFlags, 255);
      v24 = _mm_mul_ps(transforma.m_rotation.m_col1.m_quad, v22);
      v25 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), transforma.m_rotation.m_col1.m_quad),
              _mm_mul_ps(*(__m128 *)&v9[3].m_memSizeAndFlags, v18));
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 201), _mm_mul_ps(*(__m128 *)&v9[3].m_memSizeAndFlags, v20)),
              _mm_mul_ps(transforma.m_rotation.m_col1.m_quad, v23));
      v27.m_quad = _mm_mul_ps(*(__m128 *)&v9[4].vfptr, transforma.m_rotation.m_col2.m_quad);
      bTc.m_rotation.m_col1.m_quad = _mm_shuffle_ps(
                                       v26,
                                       _mm_unpackhi_ps(
                                         v26,
                                         _mm_sub_ps(
                                           _mm_mul_ps(v23, v20),
                                           _mm_add_ps(
                                             _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                                             _mm_shuffle_ps(v24, v24, 170)))),
                                       196);
      bTc.m_rotation.m_col2 = (hkVector4f)v27.m_quad;
      transformAndCombineVolumeMassProperties((hkQsTransformf *)&bTc, &massPropertiesOuta, v7);
      break;
    case 14:
      hkTransformf::setMul(&bTc, transform, (hkTransformf *)&shape[3].m_memSizeAndFlags);
      computeRecursiveShapeVolumeMassProperties(*(hkcdShape **)&v9[1].m_type.m_storage, &bTc, minTriangleThickness, v7);
      break;
    case 25:
      *(_QWORD *)startAxis = 0i64;
      if ( *(_DWORD *)&shape[1].m_memSizeAndFlags > 0 )
      {
        v28 = shape + 2;
        halfExtents.m_quad.m128_u64[0] = (unsigned __int64)&v9[2];
        do
        {
          v29 = *(__m128 *)&v28->vfptr;
          v30.m_quad = (__m128)v8->m_rotation.m_col0;
          v31.m_quad = (__m128)v8->m_rotation.m_col2;
          v32 = v8->m_translation.m_quad;
          v33 = _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v8->m_rotation.m_col1.m_quad);
          transforma.m_rotation.m_col1 = v8->m_rotation.m_col1;
          transforma.m_rotation.m_col0 = (hkVector4f)v30.m_quad;
          transforma.m_rotation.m_col2 = (hkVector4f)v31.m_quad;
          v34 = _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v30.m_quad);
          v30.m_quad.m128_i32[0] = *(_DWORD *)(&v28->m_referenceCount + 1);
          transforma.m_translation.m_quad = _mm_add_ps(
                                              v32,
                                              _mm_add_ps(
                                                _mm_add_ps(v33, v34),
                                                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v31.m_quad)));
          hkpSphereShape::hkpSphereShape((hkpSphereShape *)&bTc, v30.m_quad.m128_f32[0]);
          computeRecursiveShapeVolumeMassProperties((hkcdShape *)&bTc, &transforma, v10, v7);
          v28 = (hkcdShape *)(halfExtents.m_quad.m128_u64[0] + 16);
          *(_QWORD *)startAxis = (unsigned int)(*(_DWORD *)startAxis + 1);
          halfExtents.m_quad.m128_u64[0] += 16i64;
        }
        while ( *(_DWORD *)startAxis < *(_DWORD *)&v9[1].m_memSizeAndFlags );
      }
      break;
    case 30:
      computeRecursiveShapeVolumeMassProperties(
        (hkcdShape *)shape[2].vfptr,
        transform,
        minTriangleThickness,
        massPropertiesOut);
      break;
    default:
      return;
  }
}   massPropertiesOut);
      break;
    default:
      return;
  }
}

// File Line: 455
// RVA: 0xE0F150
void __fastcall scaleVolumeMassProperties(hkVector4f *scale, hkMassProperties *massProperties)
{
  hkVector4f v2; // xmm4
  hkVector4f v3; // xmm7
  hkVector4f v4; // xmm9
  float v5; // xmm11_4
  float v6; // xmm12_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  hkVector4f v12; // [rsp+0h] [rbp-A8h]
  hkVector4f v13; // [rsp+10h] [rbp-98h]
  hkVector4f v14; // [rsp+20h] [rbp-88h]

  v2.m_quad = (__m128)massProperties->m_inertiaTensor.m_col0;
  v3.m_quad = (__m128)massProperties->m_inertiaTensor.m_col1;
  v4.m_quad = (__m128)massProperties->m_inertiaTensor.m_col2;
  v5 = scale->m_quad.m128_f32[2];
  v6 = scale->m_quad.m128_f32[1];
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps(v4.m_quad, v4.m_quad, 170);
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85);
  v9 = (float)((float)(v8 + v2.m_quad.m128_f32[0]) - v7) * (float)((float)(v5 * v5) * 0.5);
  v10 = (float)((float)(COERCE_FLOAT(*(_OWORD *)&massProperties->m_inertiaTensor.m_col0) + v7) - v8)
      * (float)((float)(v6 * v6) * 0.5);
  v12.m_quad.m128_f32[0] = v10 + v9;
  v11 = (float)((float)(v8 + v7) - v2.m_quad.m128_f32[0])
      * (float)((float)(scale->m_quad.m128_f32[0] * scale->m_quad.m128_f32[0]) * 0.5);
  v13.m_quad.m128_f32[1] = v11 + v9;
  v14.m_quad.m128_f32[2] = v11 + v10;
  v12.m_quad.m128_f32[1] = (float)(v3.m_quad.m128_f32[0] * scale->m_quad.m128_f32[0]) * v6;
  v13.m_quad.m128_f32[0] = (float)(v3.m_quad.m128_f32[0] * scale->m_quad.m128_f32[0]) * v6;
  v14.m_quad.m128_f32[0] = (float)(v4.m_quad.m128_f32[0] * scale->m_quad.m128_f32[0]) * v5;
  v12.m_quad.m128_f32[2] = (float)(v4.m_quad.m128_f32[0] * scale->m_quad.m128_f32[0]) * v5;
  v14.m_quad.m128_f32[1] = (float)(massProperties->m_inertiaTensor.m_col2.m_quad.m128_f32[1] * v6) * v5;
  v13.m_quad.m128_f32[2] = (float)(massProperties->m_inertiaTensor.m_col2.m_quad.m128_f32[1] * v6) * v5;
  massProperties->m_volume = (float)((float)(v6 * scale->m_quad.m128_f32[0]) * v5) * massProperties->m_volume;
  massProperties->m_centerOfMass.m_quad = _mm_mul_ps(scale->m_quad, massProperties->m_centerOfMass.m_quad);
  massProperties->m_inertiaTensor.m_col1 = (hkVector4f)v13.m_quad;
  massProperties->m_inertiaTensor.m_col0 = (hkVector4f)v12.m_quad;
  massProperties->m_inertiaTensor.m_col2 = (hkVector4f)v14.m_quad;
}

// File Line: 481
// RVA: 0xE0EF10
void __fastcall transformAndCombineVolumeMassProperties(hkQsTransformf *transform, hkMassProperties *newMassProperties, hkMassProperties *massPropertiesOut)
{
  hkMassProperties *v3; // r14
  hkMassProperties *v4; // rdi
  hkQsTransformf *v5; // rsi
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  float v8; // xmm6_4
  int v9; // xmm0_4
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  hkSimdFloat32 v18; // [rsp+20h] [rbp-C8h]
  hkVector4f scale; // [rsp+30h] [rbp-B8h]
  hkArray<hkMassElement,hkContainerHeapAllocator> elements; // [rsp+40h] [rbp-A8h]
  int v21; // [rsp+60h] [rbp-88h]
  int v22; // [rsp+64h] [rbp-84h]
  char v23[24]; // [rsp+68h] [rbp-80h]
  __int128 v24; // [rsp+88h] [rbp-60h]
  __m128 v25; // [rsp+98h] [rbp-50h]
  __m128 v26; // [rsp+A8h] [rbp-40h]
  __m128 v27; // [rsp+B8h] [rbp-30h]
  __int128 v28; // [rsp+C8h] [rbp-20h]
  float v29; // [rsp+D8h] [rbp-10h]
  float v30; // [rsp+DCh] [rbp-Ch]
  __int128 v31; // [rsp+E8h] [rbp+0h]
  __int128 v32; // [rsp+F8h] [rbp+10h]
  hkVector4f v33; // [rsp+108h] [rbp+20h]
  __int128 v34; // [rsp+118h] [rbp+30h]
  char v35[48]; // [rsp+128h] [rbp+40h]
  __int128 v36; // [rsp+158h] [rbp+70h]
  hkRotationf v37; // [rsp+168h] [rbp+80h]
  __int128 v38; // [rsp+198h] [rbp+B0h]
  hkResult result; // [rsp+1E0h] [rbp+F8h]

  v3 = massPropertiesOut;
  v4 = newMassProperties;
  v5 = transform;
  if ( newMassProperties->m_volume != 0.0 )
  {
    result.m_enum = LODWORD(FLOAT_0_001);
    scale.m_quad = (__m128)transform->m_scale;
    v6 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
    if ( (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(scale.m_quad, query.m_quad), 1u), 1u),
              v6)) & 7) != 7 )
      scaleVolumeMassProperties(&scale, newMassProperties);
    v6.m128_f32[0] = v4->m_volume / v4->m_mass;
    v7 = _mm_shuffle_ps(v6, v6, 0);
    v8 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v4->m_mass), (__m128)LODWORD(v4->m_mass), 0)) * v7.m128_f32[0];
    v18.m_real = v7;
    hkMatrix3f::mul(&v4->m_inertiaTensor, &v18);
    v4->m_mass = v8;
    v9 = LODWORD(v3->m_volume);
    v7.m128_i32[0] = LODWORD(v3->m_mass);
    v25 = ::transform.m_quad;
    *(hkVector4f *)v35 = (hkVector4f)::transform.m_quad;
    v21 = v9;
    v22 = v7.m128_i32[0];
    elements.m_capacityAndFlags = -2147483646;
    elements.m_size = 2;
    elements.m_data = (hkMassElement *)&v21;
    v10.m_quad = (__m128)v3->m_centerOfMass;
    v11.m_quad = (__m128)v3->m_inertiaTensor.m_col0;
    v26 = direction.m_quad;
    *(hkVector4f *)&v23[8] = (hkVector4f)v10.m_quad;
    v12.m_quad = (__m128)v3->m_inertiaTensor.m_col1;
    *(hkVector4f *)v23 = (hkVector4f)v11.m_quad;
    v13 = (__int128)v3->m_inertiaTensor.m_col2;
    *(hkVector4f *)&v23[16] = (hkVector4f)v12.m_quad;
    *(hkVector4f *)&v35[16] = (hkVector4f)direction.m_quad;
    v28 = 0i64;
    v36 = 0i64;
    v24 = v13;
    v29 = v4->m_volume;
    v14 = (__int128)v4->m_centerOfMass;
    v27 = stru_141A71280.m_quad;
    *(hkVector4f *)&v35[32] = (hkVector4f)stru_141A71280.m_quad;
    v31 = v14;
    v30 = v4->m_mass;
    v15 = (__int128)v4->m_inertiaTensor.m_col0;
    v33.m_quad = (__m128)v4->m_inertiaTensor.m_col1;
    v16 = (__int128)v5->m_translation;
    v32 = v15;
    v17 = (__int128)v4->m_inertiaTensor.m_col2;
    v38 = v16;
    v34 = v17;
    hkRotationf::set(&v37, &v5->m_rotation);
    *(hkRotationf *)v35 = v37;
    v36 = v38;
    hkInertiaTensorComputer::combineMassProperties(&result, &elements, v3);
    elements.m_size = 0;
    if ( elements.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        elements.m_data,
        144 * (elements.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 532
// RVA: 0xE0F2E0
__m128i *__fastcall hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(hkSimdFloat32 *result, hkArray<hkpConstraintInstance const *,hkContainerHeapAllocator> *constraints, hkpRigidBody *body, hkSimdFloat32 *inertiaFactorHint)
{
  hkArray<hkpConstraintInstance const *,hkContainerHeapAllocator> *v4; // rbx
  int v5; // edx
  hkSimdFloat32 *v6; // r10
  hkpRigidBody *v7; // r9
  int v8; // esi
  __int64 v9; // r8
  hkpConstraintInstance **v10; // rcx
  hkpConstraintInstance *v11; // rdi
  hkpRigidBody *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdi
  __m128 v15; // xmm7
  __m128 i; // xmm8
  __int64 v17; // rcx
  hkpRigidBody *v18; // r8
  __m128i *v19; // rbx
  int v20; // er8
  hkVector4f v21; // xmm5
  __m128 v22; // xmm2
  __m128i v23; // xmm9
  __m128 v24; // xmm6
  __m128 v25; // xmm2
  hkMatrix3f inertia; // [rsp+20h] [rbp-C8h]
  char *array; // [rsp+50h] [rbp-98h]
  int v29; // [rsp+58h] [rbp-90h]
  int v30; // [rsp+5Ch] [rbp-8Ch]
  char v31; // [rsp+60h] [rbp-88h]
  hkSimdFloat32 resulta; // [rsp+C8h] [rbp-20h]
  __m128i *v33; // [rsp+168h] [rbp+80h]
  __int64 vars0; // [rsp+170h] [rbp+88h]
  hkpRigidBody *retaddr; // [rsp+178h] [rbp+90h]
  hkSimdFloat32 *v36; // [rsp+180h] [rbp+98h]

  v36 = result;
  v4 = constraints;
  v5 = 0;
  v6 = inertiaFactorHint;
  v7 = body;
  v30 = -2147483632;
  v29 = 0;
  v8 = v4->m_size - 1;
  array = &v31;
  v9 = v8;
  vars0 = v8;
  if ( v8 >= 0 )
  {
    while ( 1 )
    {
      v10 = v4->m_data;
      v11 = v4->m_data[v9];
      v12 = (hkpRigidBody *)v11->m_entities[0];
      if ( v12 == v7 )
        break;
      if ( (hkpRigidBody *)v11->m_entities[1] == v7 )
        goto LABEL_5;
LABEL_11:
      --v8;
      vars0 = --v9;
      if ( v9 < 0 )
      {
        v6 = v36;
        goto LABEL_13;
      }
    }
    v12 = (hkpRigidBody *)v11->m_entities[1];
LABEL_5:
    if ( v12 )
    {
      v13 = --v4->m_size;
      if ( (_DWORD)v13 != v8 )
      {
        v10[v9] = v10[v13];
        v5 = v29;
      }
      if ( v5 == (v30 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v5 = v29;
        v9 = vars0;
        v7 = retaddr;
      }
      *(_QWORD *)&array[8 * v5] = v11;
      v5 = v29++ + 1;
    }
    goto LABEL_11;
  }
LABEL_13:
  v14 = v5 - 1;
  v15 = 0i64;
  for ( i = 0i64; v14 >= 0; i = _mm_max_ps(resulta.m_real, i) )
  {
    v17 = *(_QWORD *)&array[8 * v14];
    v18 = *(hkpRigidBody **)(v17 + 40);
    if ( v18 == v7 )
      v18 = *(hkpRigidBody **)(v17 + 48);
    hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(&resulta, v4, v18, v6);
    --v14;
    v7 = retaddr;
    v6 = v36;
    v15 = _mm_add_ps(v15, resulta.m_real);
  }
  if ( (unsigned __int8)(retaddr->m_motion.m_type.m_storage - 4) > 1u )
  {
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *, __int64, hkpRigidBody *))retaddr->m_motion.vfptr[3].__first_virtual_table_function__)(
      &retaddr->m_motion,
      &inertia,
      v9,
      v7);
    v21.m_quad = (__m128)inertia.m_col0;
    v22 = _mm_or_ps(
            _mm_andnot_ps(
              (__m128)xmmword_141AA7620,
              _mm_or_ps(
                _mm_andnot_ps((__m128)xmmword_141AA7600, inertia.m_col0.m_quad),
                _mm_and_ps(inertia.m_col1.m_quad, (__m128)xmmword_141AA7600))),
            _mm_and_ps(inertia.m_col2.m_quad, (__m128)xmmword_141AA7620));
    v23 = (__m128i)_mm_max_ps(
                     _mm_shuffle_ps(v22, v22, 170),
                     _mm_max_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)));
    if ( v15.m128_f32[0] == 0.0 )
    {
      v19 = v33;
      _mm_store_si128(v33, v23);
    }
    else
    {
      v24 = _mm_max_ps(_mm_min_ps(v15, _mm_mul_ps((__m128)v23, v36->m_real)), i);
      v25 = _mm_max_ps(v22, v24);
      v21.m_quad.m128_f32[0] = v25.m128_f32[0];
      inertia.m_col0 = (hkVector4f)v21.m_quad;
      inertia.m_col1.m_quad = _mm_or_ps(
                                _mm_and_ps((__m128)xmmword_141AA7600, v25),
                                _mm_andnot_ps((__m128)xmmword_141AA7600, inertia.m_col1.m_quad));
      inertia.m_col2.m_quad = _mm_or_ps(
                                _mm_and_ps((__m128)xmmword_141AA7620, v25),
                                _mm_andnot_ps((__m128)xmmword_141AA7620, inertia.m_col2.m_quad));
      hkpRigidBody::setInertiaLocal(retaddr, &inertia);
      v19 = v33;
      *(__m128 *)v33 = _mm_max_ps(_mm_min_ps(_mm_mul_ps((__m128)v23, v36->m_real), _mm_add_ps(v15, (__m128)v23)), v24);
    }
    v29 = 0;
    if ( v30 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v30);
  }
  else
  {
    v19 = v33;
    v20 = v30;
    v29 = 0;
    *(hkVector4f *)v33 = (hkVector4f)aabbOut.m_quad;
    if ( v20 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, hkpRigidBody *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        array,
        (unsigned int)(8 * v20),
        v7);
  }
  return v19;
}

// File Line: 607
// RVA: 0xE0E570
void __fastcall hkpInertiaTensorComputer::optimizeInertiasOfConstraintTree(hkpConstraintInstance *const *constraints, int numConstraints, hkpRigidBody *rootBody, float inertiaFactorHint)
{
  __int64 v4; // rbx
  hkpRigidBody *v5; // rsi
  hkpConstraintInstance *const *v6; // rdi
  int v7; // er9
  hkLifoAllocator *v8; // rax
  hkpConstraintInstance **v9; // rcx
  int v10; // edx
  char *v11; // r8
  hkpConstraintInstance **v12; // rax
  __int64 v13; // rdx
  int v14; // eax
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // er8
  hkSimdFloat32 inertiaFactorHinta; // [rsp+20h] [rbp-40h]
  hkSimdFloat32 result; // [rsp+30h] [rbp-30h]
  hkArray<hkpConstraintInstance const *,hkContainerHeapAllocator> constraintsa; // [rsp+40h] [rbp-20h]
  void *p; // [rsp+50h] [rbp-10h]
  int v23; // [rsp+58h] [rbp-8h]

  v4 = numConstraints;
  v5 = rootBody;
  v6 = constraints;
  constraintsa.m_capacityAndFlags = 2147483648;
  constraintsa.m_data = 0i64;
  v7 = 0;
  constraintsa.m_size = 0;
  v23 = numConstraints;
  if ( numConstraints )
  {
    v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpConstraintInstance **)v8->m_cur;
    v10 = (8 * v4 + 127) & 0xFFFFFF80;
    v11 = (char *)v9 + v10;
    if ( v10 > v8->m_slabSize || v11 > v8->m_end )
    {
      v12 = (hkpConstraintInstance **)hkLifoAllocator::allocateFromNewSlab(v8, v10);
      v7 = constraintsa.m_size;
      v9 = v12;
    }
    else
    {
      v8->m_cur = v11;
      v7 = constraintsa.m_size;
    }
  }
  else
  {
    v9 = 0i64;
  }
  constraintsa.m_data = v9;
  p = v9;
  v13 = 0i64;
  constraintsa.m_capacityAndFlags = v4 | 0x80000000;
  if ( (signed int)v4 > 0 )
  {
    while ( 1 )
    {
      v9[v7] = v6[++v13 - 1];
      v7 = constraintsa.m_size++ + 1;
      if ( v13 >= v4 )
        break;
      v9 = constraintsa.m_data;
    }
  }
  inertiaFactorHinta.m_real = _mm_shuffle_ps((__m128)LODWORD(inertiaFactorHint), (__m128)LODWORD(inertiaFactorHint), 0);
  hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(&result, &constraintsa, v5, &inertiaFactorHinta);
  v14 = constraintsa.m_size;
  v15 = (char *)p;
  if ( p == constraintsa.m_data )
    v14 = 0;
  constraintsa.m_size = v14;
  v16 = (8 * v23 + 127) & 0xFFFFFF80;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (v16 + 15) & 0xFFFFFFF0;
  if ( v16 > v17->m_slabSize || &v15[v18] != v17->m_cur || v17->m_firstNonLifoEnd == v15 )
    hkLifoAllocator::slowBlockFree(v17, v15, v18);
  else
    v17->m_cur = v15;
  constraintsa.m_size = 0;
  if ( constraintsa.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      constraintsa.m_data,
      8 * constraintsa.m_capacityAndFlags);
}

