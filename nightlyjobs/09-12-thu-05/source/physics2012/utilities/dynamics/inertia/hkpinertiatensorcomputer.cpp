// File Line: 37
// RVA: 0xE0E710
void __fastcall scaleMassProperties_0(hkSimdFloat32 *scale, hkMassProperties *massProperties)
{
  float v3; // xmm6_4

  v3 = _mm_shuffle_ps((__m128)LODWORD(massProperties->m_mass), (__m128)LODWORD(massProperties->m_mass), 0).m128_f32[0]
     * scale->m_real.m128_f32[0];
  hkMatrix3f::mul(&massProperties->m_inertiaTensor, scale);
  massProperties->m_mass = v3;
}

// File Line: 47
// RVA: 0xE0E360
void __fastcall hkpInertiaTensorComputer::setShapeVolumeMassProperties(
        hkpShape *shape,
        float mass,
        hkpRigidBodyCinfo *bodyInfo)
{
  hkVector4f v4; // xmm1
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  hkMassProperties result; // [rsp+20h] [rbp-58h] BYREF

  *(_QWORD *)&result.m_volume = 0i64;
  memset(&result.m_centerOfMass, 0, 64);
  hkpInertiaTensorComputer::computeShapeVolumeMassProperties(shape, mass, &result);
  v4.m_quad = (__m128)result.m_centerOfMass;
  bodyInfo->m_mass = result.m_mass;
  v5.m_quad = (__m128)result.m_inertiaTensor.m_col0;
  bodyInfo->m_centerOfMass = (hkVector4f)v4.m_quad;
  v6.m_quad = (__m128)result.m_inertiaTensor.m_col1;
  bodyInfo->m_inertiaTensor.m_col0 = (hkVector4f)v5.m_quad;
  v7.m_quad = (__m128)result.m_inertiaTensor.m_col2;
  bodyInfo->m_inertiaTensor.m_col1 = (hkVector4f)v6.m_quad;
  bodyInfo->m_inertiaTensor.m_col2 = (hkVector4f)v7.m_quad;
}

// File Line: 60
// RVA: 0xE0E3E0
void __fastcall hkpInertiaTensorComputer::setMassProperties(
        hkMassProperties *massProperties,
        hkpRigidBodyCinfo *bodyInfo)
{
  bodyInfo->m_mass = massProperties->m_mass;
  bodyInfo->m_centerOfMass = massProperties->m_centerOfMass;
  bodyInfo->m_inertiaTensor = massProperties->m_inertiaTensor;
}

// File Line: 68
// RVA: 0xE0E450
void __fastcall hkpInertiaTensorComputer::setAndScaleToMass(
        hkMassProperties *props,
        hkSimdFloat32 *mass,
        hkpRigidBodyCinfo *bodyInfo)
{
  __m128 m_real; // xmm2
  __m128 v4; // xmm1
  hkSimdFloat32 scale; // [rsp+20h] [rbp-18h] BYREF

  m_real = mass->m_real;
  v4 = _mm_shuffle_ps((__m128)LODWORD(props->m_mass), (__m128)LODWORD(props->m_mass), 0);
  LODWORD(bodyInfo->m_mass) = *(hkSimdFloat32 *)mass->m_real.m128_f32;
  scale.m_real = _mm_div_ps(m_real, v4);
  bodyInfo->m_centerOfMass = props->m_centerOfMass;
  bodyInfo->m_inertiaTensor = props->m_inertiaTensor;
  hkMatrix3f::mul(&bodyInfo->m_inertiaTensor, &scale);
}

// File Line: 82
// RVA: 0xE0E420
void __fastcall hkpInertiaTensorComputer::setAndScaleToDensity(
        hkMassProperties *props,
        hkSimdFloat32 *density,
        hkpRigidBodyCinfo *bodyInfo)
{
  hkSimdFloat32 mass; // [rsp+20h] [rbp-18h] BYREF

  mass.m_real = _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(props->m_volume), (__m128)LODWORD(props->m_volume), 0),
                  density->m_real);
  hkpInertiaTensorComputer::setAndScaleToMass(props, &mass, bodyInfo);
}

// File Line: 92
// RVA: 0xE0E4C0
void __fastcall hkpInertiaTensorComputer::clipInertia(float maxInertiaRatio, hkpRigidBodyCinfo *bodyInfo)
{
  __m128 m_quad; // xmm3
  __m128 v3; // xmm4
  __m128 v4; // xmm4
  __m128 v5; // xmm5

  m_quad = bodyInfo->m_inertiaTensor.m_col0.m_quad;
  v3 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141AA7620,
           _mm_or_ps(
             _mm_and_ps((__m128)xmmword_141AA7600, bodyInfo->m_inertiaTensor.m_col1.m_quad),
             _mm_andnot_ps((__m128)xmmword_141AA7600, m_quad))),
         _mm_and_ps(bodyInfo->m_inertiaTensor.m_col2.m_quad, (__m128)xmmword_141AA7620));
  v4 = _mm_max_ps(
         v3,
         _mm_div_ps(
           _mm_max_ps(_mm_shuffle_ps(v3, v3, 170), _mm_max_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0))),
           _mm_shuffle_ps((__m128)LODWORD(maxInertiaRatio), (__m128)LODWORD(maxInertiaRatio), 0)));
  m_quad.m128_f32[0] = v4.m128_f32[0];
  bodyInfo->m_inertiaTensor.m_col0.m_quad = m_quad;
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
void __fastcall hkpInertiaTensorComputer::computeShapeVolumeMassProperties(
        hkcdShape *shape,
        float mass,
        hkMassProperties *result)
{
  __m128 m_quad; // xmm1
  __m128 m_volume_low; // xmm0
  __m128 v8; // xmm1
  float v9; // xmm6_4
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkMassProperties massPropertiesOut; // [rsp+18h] [rbp-69h] BYREF
  hkTransformf transform; // [rsp+68h] [rbp-19h] BYREF
  hkSimdFloat32 scale; // [rsp+A8h] [rbp+27h] BYREF

  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  m_quad = direction.m_quad;
  memset(&massPropertiesOut.m_centerOfMass, 0, 64);
  transform.m_translation = 0i64;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  computeRecursiveShapeVolumeMassProperties(
    shape,
    (hkTransformf *)&transform.m_rotation.m_col0.m_quad.m128_u16[4],
    0.0,
    (hkMassProperties *)(&massPropertiesOut.m_mass + 1));
  m_volume_low = (__m128)LODWORD(massPropertiesOut.m_volume);
  if ( massPropertiesOut.m_volume != 0.0
    || (computeRecursiveShapeVolumeMassProperties(shape, &transform, 0.0099999998, &massPropertiesOut),
        m_volume_low = (__m128)LODWORD(massPropertiesOut.m_volume),
        massPropertiesOut.m_volume != 0.0) )
  {
    m_quad.m128_f32[0] = mass;
    v8 = _mm_div_ps(_mm_shuffle_ps(m_quad, m_quad, 0), _mm_shuffle_ps(m_volume_low, m_volume_low, 0));
    v9 = _mm_shuffle_ps((__m128)LODWORD(massPropertiesOut.m_mass), (__m128)LODWORD(massPropertiesOut.m_mass), 0).m128_f32[0]
       * v8.m128_f32[0];
    scale.m_real = v8;
    hkMatrix3f::mul(&massPropertiesOut.m_inertiaTensor, &scale);
    result->m_volume = massPropertiesOut.m_volume;
    massPropertiesOut.m_mass = v9;
    result->m_centerOfMass = massPropertiesOut.m_centerOfMass;
    v10.m_quad = (__m128)massPropertiesOut.m_inertiaTensor.m_col1;
    result->m_mass = massPropertiesOut.m_mass;
    v11.m_quad = (__m128)massPropertiesOut.m_inertiaTensor.m_col0;
    result->m_inertiaTensor.m_col1 = (hkVector4f)v10.m_quad;
    result->m_inertiaTensor.m_col0 = (hkVector4f)v11.m_quad;
    result->m_inertiaTensor.m_col2 = massPropertiesOut.m_inertiaTensor.m_col2;
  }
}

// File Line: 167
// RVA: 0xE0E750
void __fastcall computeRecursiveShapeVolumeMassProperties(
        hkpCylinderShape *shape,
        hkTransformf *transform,
        float minTriangleThickness,
        hkMassProperties *massPropertiesOut)
{
  int m_storage; // eax
  __m128 v9; // xmm2
  float v10; // xmm2_4
  float m_radius; // xmm0_4
  hkVector4f v12; // xmm1
  hkBaseObjectVtbl *v13; // rcx
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm7
  __m128 v19; // xmm2
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm6
  __m128 v23; // xmm4
  __m128 v24; // xmm4
  hkVector4f v25; // xmm0
  hkcdShape *p_m_vertexA; // rcx
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  hkVector4f v30; // xmm5
  __m128 v31; // xmm4
  __m128 v32; // xmm0
  void *v33; // rbx
  unsigned int i; // esi
  hkcdShape *v35; // rax
  hkReferencedObject m_vertexA; // xmm7
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm5
  __m128 v42; // xmm8
  float CylinderRadius; // xmm0_4
  float v44; // xmm6_4
  float m_volume; // xmm0_4
  float m_mass; // xmm1_4
  hkVector4f v47; // xmm0
  hkVector4f v48; // xmm1
  hkVector4f v49; // xmm0
  hkVector4f v50; // xmm1
  hkVector4f v51; // xmm0
  hkVector4f v52; // xmm1
  hkVector4f v53; // xmm0
  hkVector4f v54; // xmm1
  hkMassProperties *mass; // [rsp+20h] [rbp-C8h]
  hkVector4f halfExtents; // [rsp+40h] [rbp-A8h] BYREF
  hkResult v57; // [rsp+50h] [rbp-98h] BYREF
  _BYTE startAxis[24]; // [rsp+60h] [rbp-88h] BYREF
  hkMatrix3f v59; // [rsp+78h] [rbp-70h] BYREF
  hkStridedVertices v60; // [rsp+A8h] [rbp-40h] BYREF
  hkResult v61; // [rsp+B8h] [rbp-30h] BYREF
  hkResult v62; // [rsp+BCh] [rbp-2Ch] BYREF
  hkResult v63; // [rsp+C0h] [rbp-28h] BYREF
  hkResult v64; // [rsp+C4h] [rbp-24h] BYREF
  hkTransformf bTc; // [rsp+C8h] [rbp-20h] BYREF
  hkTransformf transforma; // [rsp+108h] [rbp+20h] BYREF
  hkSimdFloat32 scale; // [rsp+148h] [rbp+60h] BYREF
  hkMassProperties massPropertiesOuta; // [rsp+158h] [rbp+70h] BYREF
  hkArray<hkMassElement,hkContainerHeapAllocator> elements; // [rsp+1A8h] [rbp+C0h] BYREF
  int v70[4]; // [rsp+1C8h] [rbp+E0h] BYREF
  __m128 m_quad; // [rsp+1D8h] [rbp+F0h]
  __m128 v72; // [rsp+1E8h] [rbp+100h]
  __m128 v73; // [rsp+1F8h] [rbp+110h]
  __m128 v74; // [rsp+208h] [rbp+120h]
  __m128 v75; // [rsp+218h] [rbp+130h]
  __m128 v76; // [rsp+228h] [rbp+140h]
  __m128 v77; // [rsp+238h] [rbp+150h]
  __int128 v78; // [rsp+248h] [rbp+160h]
  int v79; // [rsp+258h] [rbp+170h]
  float v80; // [rsp+25Ch] [rbp+174h]
  __int128 v81; // [rsp+268h] [rbp+180h]
  hkVector4f v82; // [rsp+278h] [rbp+190h]
  hkVector4f v83; // [rsp+288h] [rbp+1A0h]
  hkVector4f v84; // [rsp+298h] [rbp+1B0h]
  __m128 v85; // [rsp+2A8h] [rbp+1C0h]
  __m128 v86; // [rsp+2B8h] [rbp+1D0h]
  __m128 v87; // [rsp+2C8h] [rbp+1E0h]
  __m128 v88; // [rsp+2D8h] [rbp+1F0h]
  hkResult result; // [rsp+418h] [rbp+330h] BYREF
  hkMassProperties *v90; // [rsp+430h] [rbp+348h]

  m_storage = (unsigned __int8)shape->m_type.m_storage;
  *(_OWORD *)&startAxis[8] = 0i64;
  memset(&v59, 0, sizeof(v59));
  switch ( m_storage )
  {
    case 0:
      hkInertiaTensorComputer::computeSphereVolumeMassProperties(
        &result,
        shape->m_radius,
        1.0,
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 1:
      m_vertexA = (hkReferencedObject)shape->m_vertexA;
      v37 = _mm_sub_ps(shape->m_vertexB.m_quad, (__m128)m_vertexA);
      v38 = _mm_mul_ps(v37, v37);
      v39 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      v40 = _mm_rsqrt_ps(v39);
      v41 = _mm_mul_ps(
              _mm_mul_ps(
                v37,
                _mm_andnot_ps(
                  _mm_cmple_ps(v39, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)),
                    _mm_mul_ps(*(__m128 *)_xmm, v40)))),
              _mm_shuffle_ps((__m128)LODWORD(shape->m_radius), (__m128)LODWORD(shape->m_radius), 0));
      v42 = _mm_add_ps(shape->m_vertexB.m_quad, v41);
      *(__m128 *)startAxis = _mm_sub_ps((__m128)m_vertexA, v41);
      halfExtents.m_quad = v42;
      CylinderRadius = hkpCylinderShape::getCylinderRadius(shape);
      LODWORD(mass) = (_DWORD)FLOAT_1_0;
      hkInertiaTensorComputer::computeCylinderVolumeMassProperties(
        &v62,
        (hkVector4f *)startAxis,
        &halfExtents,
        CylinderRadius + shape->m_radius,
        mass,
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 2:
      m_radius = shape->m_radius;
      v57.m_enum = LODWORD(minTriangleThickness);
      result.m_enum = LODWORD(m_radius);
      hkInertiaTensorComputer::computeTriangleSurfaceMassProperties(
        &v63,
        &shape->m_vertexA,
        &shape->m_vertexB,
        &shape->m_perpendicular1,
        1.0,
        fmaxf(m_radius, minTriangleThickness),
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 3:
      v9 = _mm_shuffle_ps((__m128)LODWORD(shape->m_radius), (__m128)LODWORD(shape->m_radius), 0);
      halfExtents.m_quad = _mm_add_ps(
                             shape->m_vertexA.m_quad,
                             _mm_shuffle_ps(v9, _mm_unpackhi_ps(v9, (__m128)0i64), 196));
      hkInertiaTensorComputer::computeBoxVolumeMassProperties(
        &v57,
        &halfExtents,
        1.0,
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 4:
      LODWORD(mass) = (_DWORD)FLOAT_1_0;
      hkInertiaTensorComputer::computeCapsuleVolumeMassProperties(
        &v64,
        &shape->m_vertexA,
        &shape->m_vertexB,
        shape->m_radius,
        mass,
        (hkMassProperties *)&startAxis[16]);
      goto LABEL_22;
    case 5:
      halfExtents.m_quad.m128_u64[0] = 0i64;
      halfExtents.m_quad.m128_u64[1] = 0x8000000000000000ui64;
      hkpConvexVerticesShape::getOriginalVertices(
        (hkpConvexVerticesShape *)shape,
        (hkArray<hkVector4f,hkContainerHeapAllocator> *)&halfExtents);
      v10 = shape->m_radius;
      v60.m_vertices = (const float *)halfExtents.m_quad.m128_u64[0];
      v60.m_numVertices = halfExtents.m_quad.m128_i32[2];
      v60.m_striding = 16;
      hkInertiaTensorComputer::computeConvexHullMassProperties(&v61, &v60, v10, (hkMassProperties *)&startAxis[16]);
      halfExtents.m_quad.m128_i32[2] = 0;
      if ( halfExtents.m_quad.m128_i32[3] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          (void *)halfExtents.m_quad.m128_u64[0],
          16 * halfExtents.m_quad.m128_i32[3]);
LABEL_22:
      if ( *(float *)&startAxis[16] != 0.0 )
      {
        scale.m_real = _mm_shuffle_ps(
                         (__m128)*(unsigned int *)&startAxis[16],
                         (__m128)*(unsigned int *)&startAxis[16],
                         0);
        v44 = _mm_shuffle_ps((__m128)*(unsigned int *)&startAxis[20], (__m128)*(unsigned int *)&startAxis[20], 0).m128_f32[0]
            * scale.m_real.m128_f32[0];
        hkMatrix3f::mul(&v59, &scale);
        m_volume = massPropertiesOut->m_volume;
        m_mass = massPropertiesOut->m_mass;
        v78 = 0i64;
        *(float *)v70 = m_volume;
        *(float *)&v70[1] = m_mass;
        *(float *)&startAxis[20] = v44;
        v47.m_quad = (__m128)massPropertiesOut->m_centerOfMass;
        v48.m_quad = (__m128)massPropertiesOut->m_inertiaTensor.m_col0;
        elements.m_data = (hkMassElement *)v70;
        elements.m_capacityAndFlags = -2147483646;
        elements.m_size = 2;
        m_quad = v47.m_quad;
        v49.m_quad = (__m128)massPropertiesOut->m_inertiaTensor.m_col1;
        v72 = v48.m_quad;
        v50.m_quad = (__m128)massPropertiesOut->m_inertiaTensor.m_col2;
        v73 = v49.m_quad;
        v75 = ::transform.m_quad;
        v74 = v50.m_quad;
        v77 = stru_141A71280.m_quad;
        v79 = *(_DWORD *)&startAxis[16];
        v76 = direction.m_quad;
        v80 = v44;
        v81 = *(_OWORD *)&startAxis[8];
        v82.m_quad = (__m128)v59.m_col0;
        v83.m_quad = (__m128)v59.m_col1;
        v51.m_quad = (__m128)transform->m_rotation.m_col0;
        v84.m_quad = (__m128)v59.m_col2;
        v52.m_quad = (__m128)transform->m_rotation.m_col1;
        v85 = v51.m_quad;
        v53.m_quad = (__m128)transform->m_rotation.m_col2;
        v86 = v52.m_quad;
        v54.m_quad = (__m128)transform->m_translation;
        v87 = v53.m_quad;
        v88 = v54.m_quad;
        hkInertiaTensorComputer::combineMassProperties(&result, &elements, massPropertiesOut);
        elements.m_size = 0;
        if ( elements.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
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
      v33 = shape->vfptr[7].__vecDelDtor(shape, 0x140000000ui64);
      for ( i = (*(__int64 (__fastcall **)(void *))(*(_QWORD *)v33 + 16i64))(v33);
            i != -1;
            i = (*(__int64 (__fastcall **)(void *, _QWORD))(*(_QWORD *)v33 + 24i64))(v33, i) )
      {
        v35 = (hkcdShape *)(*(__int64 (__fastcall **)(void *, _QWORD, hkArray<hkMassElement,hkContainerHeapAllocator> *))(*(_QWORD *)v33 + 40i64))(
                             v33,
                             i,
                             &elements);
        if ( v35 )
          computeRecursiveShapeVolumeMassProperties(v35, transform, minTriangleThickness, v90);
      }
      break;
    case 10:
      bTc.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
      bTc.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
      v12.m_quad = (__m128)shape->m_vertexB;
      bTc.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      bTc.m_translation = (hkVector4f)v12.m_quad;
      hkTransformf::setMul(&transforma, transform, &bTc);
      computeRecursiveShapeVolumeMassProperties(
        (hkcdShape *)shape->m_vertexA.m_quad.m128_u64[0],
        &transforma,
        minTriangleThickness,
        massPropertiesOut);
      break;
    case 11:
      v13 = (hkBaseObjectVtbl *)shape->m_vertexA.m_quad.m128_u64[0];
      memset(&massPropertiesOuta.m_centerOfMass, 0, 64);
      *(_QWORD *)&massPropertiesOuta.m_volume = 0i64;
      computeRecursiveShapeVolumeMassProperties(
        (hkcdShape *)v13,
        (hkTransformf *)&::transform,
        minTriangleThickness,
        &massPropertiesOuta);
      hkQsTransformf::setFromTransformNoScale((hkQsTransformf *)&transforma, transform);
      v14 = shape->m_vertexB.m_quad;
      v15 = _mm_mul_ps(transforma.m_rotation.m_col1.m_quad, v14);
      v16 = _mm_shuffle_ps(transforma.m_rotation.m_col1.m_quad, transforma.m_rotation.m_col1.m_quad, 201);
      v17 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), transforma.m_rotation.m_col1.m_quad),
              _mm_mul_ps(v16, v14));
      v18 = _mm_shuffle_ps(transforma.m_rotation.m_col1.m_quad, transforma.m_rotation.m_col1.m_quad, 255);
      v19 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  transforma.m_rotation.m_col1.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v18, v18), (__m128)xmmword_141A711B0), v14)),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v18));
      bTc.m_rotation.m_col0.m_quad = _mm_add_ps(_mm_add_ps(v19, v19), transforma.m_rotation.m_col0.m_quad);
      v20 = shape->m_perpendicular1.m_quad;
      v21 = _mm_shuffle_ps(v20, v20, 255);
      v22 = _mm_mul_ps(transforma.m_rotation.m_col1.m_quad, v20);
      v23 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), transforma.m_rotation.m_col1.m_quad),
              _mm_mul_ps(v20, v16));
      v24 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(v20, v18)),
              _mm_mul_ps(transforma.m_rotation.m_col1.m_quad, v21));
      v25.m_quad = _mm_mul_ps(shape->m_perpendicular2.m_quad, transforma.m_rotation.m_col2.m_quad);
      bTc.m_rotation.m_col1.m_quad = _mm_shuffle_ps(
                                       v24,
                                       _mm_unpackhi_ps(
                                         v24,
                                         _mm_sub_ps(
                                           _mm_mul_ps(v21, v18),
                                           _mm_add_ps(
                                             _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                                             _mm_shuffle_ps(v22, v22, 170)))),
                                       196);
      bTc.m_rotation.m_col2 = (hkVector4f)v25.m_quad;
      transformAndCombineVolumeMassProperties((hkQsTransformf *)&bTc, &massPropertiesOuta, massPropertiesOut);
      break;
    case 14:
      hkTransformf::setMul(&bTc, transform, (hkTransformf *)&shape->m_perpendicular1);
      computeRecursiveShapeVolumeMassProperties(
        *(hkcdShape **)&shape->m_cylRadius,
        &bTc,
        minTriangleThickness,
        massPropertiesOut);
      break;
    case 25:
      *(_QWORD *)startAxis = 0i64;
      if ( SLODWORD(shape->m_radius) > 0 )
      {
        p_m_vertexA = (hkcdShape *)&shape->m_vertexA;
        halfExtents.m_quad.m128_u64[0] = (unsigned __int64)&shape->m_vertexA;
        do
        {
          v27 = (__m128)p_m_vertexA->hkReferencedObject;
          v28 = transform->m_rotation.m_col0.m_quad;
          v29 = transform->m_rotation.m_col2.m_quad;
          v30.m_quad = (__m128)transform->m_translation;
          v31 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), transform->m_rotation.m_col1.m_quad);
          transforma.m_rotation.m_col1 = transform->m_rotation.m_col1;
          transforma.m_rotation.m_col0.m_quad = v28;
          transforma.m_rotation.m_col2.m_quad = v29;
          v32 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v28);
          v28.m128_i32[0] = *(_DWORD *)(&p_m_vertexA->m_referenceCount + 1);
          transforma.m_translation.m_quad = _mm_add_ps(
                                              v30.m_quad,
                                              _mm_add_ps(
                                                _mm_add_ps(v31, v32),
                                                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v29)));
          hkpSphereShape::hkpSphereShape((hkpSphereShape *)&bTc, v28.m128_f32[0]);
          computeRecursiveShapeVolumeMassProperties(
            (hkcdShape *)&bTc,
            &transforma,
            minTriangleThickness,
            massPropertiesOut);
          p_m_vertexA = (hkcdShape *)(halfExtents.m_quad.m128_u64[0] + 16);
          *(_QWORD *)startAxis = (unsigned int)(*(_DWORD *)startAxis + 1);
          halfExtents.m_quad.m128_u64[0] += 16i64;
        }
        while ( *(int *)startAxis < SLODWORD(shape->m_radius) );
      }
      break;
    case 30:
      computeRecursiveShapeVolumeMassProperties(
        (hkcdShape *)shape->m_vertexA.m_quad.m128_u64[0],
        transform,
        minTriangleThickness,
        massPropertiesOut);
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
  _BYTE v12[48]; // [rsp+0h] [rbp-A8h]

  v2.m_quad = (__m128)massProperties->m_inertiaTensor.m_col0;
  v3.m_quad = (__m128)massProperties->m_inertiaTensor.m_col1;
  v4.m_quad = (__m128)massProperties->m_inertiaTensor.m_col2;
  v5 = scale->m_quad.m128_f32[2];
  v6 = scale->m_quad.m128_f32[1];
  v7 = _mm_shuffle_ps(v4.m_quad, v4.m_quad, 170).m128_f32[0];
  v8 = _mm_shuffle_ps(v3.m_quad, v3.m_quad, 85).m128_f32[0];
  v9 = (float)((float)(v8 + v2.m_quad.m128_f32[0]) - v7) * (float)((float)(v5 * v5) * 0.5);
  v10 = (float)((float)(v2.m_quad.m128_f32[0] + v7) - v8) * (float)((float)(v6 * v6) * 0.5);
  *(float *)v12 = v10 + v9;
  v11 = (float)((float)(v8 + v7) - v2.m_quad.m128_f32[0])
      * (float)((float)(scale->m_quad.m128_f32[0] * scale->m_quad.m128_f32[0]) * 0.5);
  *(float *)&v12[20] = v11 + v9;
  *(float *)&v12[40] = v11 + v10;
  *(float *)&v12[4] = (float)(v3.m_quad.m128_f32[0] * scale->m_quad.m128_f32[0]) * v6;
  *(float *)&v12[16] = *(float *)&v12[4];
  *(float *)&v12[32] = (float)(v4.m_quad.m128_f32[0] * scale->m_quad.m128_f32[0]) * v5;
  *(float *)&v12[8] = *(float *)&v12[32];
  *(float *)&v12[36] = (float)(massProperties->m_inertiaTensor.m_col2.m_quad.m128_f32[1] * v6) * v5;
  *(float *)&v12[24] = *(float *)&v12[36];
  massProperties->m_volume = (float)((float)(v6 * scale->m_quad.m128_f32[0]) * v5) * massProperties->m_volume;
  massProperties->m_centerOfMass.m_quad = _mm_mul_ps(scale->m_quad, massProperties->m_centerOfMass.m_quad);
  massProperties->m_inertiaTensor = *(hkMatrix3f *)v12;
}

// File Line: 481
// RVA: 0xE0EF10
void __fastcall transformAndCombineVolumeMassProperties(
        hkQsTransformf *transform,
        hkMassProperties *newMassProperties,
        hkMassProperties *massPropertiesOut)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm1
  float v8; // xmm6_4
  float m_volume; // xmm0_4
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm0
  hkVector4f v13; // xmm1
  hkVector4f v14; // xmm0
  hkVector4f v15; // xmm1
  hkVector4f v16; // xmm0
  hkVector4f v17; // xmm1
  hkSimdFloat32 v18; // [rsp+20h] [rbp-C8h] BYREF
  hkVector4f scale; // [rsp+30h] [rbp-B8h] BYREF
  hkArray<hkMassElement,hkContainerHeapAllocator> elements; // [rsp+40h] [rbp-A8h] BYREF
  int v21[2]; // [rsp+60h] [rbp-88h] BYREF
  __m256i v22; // [rsp+68h] [rbp-80h]
  __m128 v23; // [rsp+88h] [rbp-60h]
  __m128 m_quad; // [rsp+98h] [rbp-50h]
  __m128 v25; // [rsp+A8h] [rbp-40h]
  __m128 v26; // [rsp+B8h] [rbp-30h]
  __int128 v27; // [rsp+C8h] [rbp-20h]
  float v28; // [rsp+D8h] [rbp-10h]
  float m_mass; // [rsp+DCh] [rbp-Ch]
  __m128 v30; // [rsp+E8h] [rbp+0h]
  __m128 v31; // [rsp+F8h] [rbp+10h]
  hkVector4f v32; // [rsp+108h] [rbp+20h]
  __m128 v33; // [rsp+118h] [rbp+30h]
  hkRotationf v34; // [rsp+128h] [rbp+40h]
  __m128 v35; // [rsp+158h] [rbp+70h]
  hkRotationf v36; // [rsp+168h] [rbp+80h] BYREF
  __m128 v37; // [rsp+198h] [rbp+B0h]
  hkResult result; // [rsp+1E0h] [rbp+F8h] BYREF

  if ( newMassProperties->m_volume != 0.0 )
  {
    result.m_enum = LODWORD(FLOAT_0_001);
    scale.m_quad = (__m128)transform->m_scale;
    v6 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
    if ( (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(scale.m_quad, query.m_quad), 1u), 1u),
              v6)) & 7) != 7 )
      scaleVolumeMassProperties(&scale, newMassProperties);
    v6.m128_f32[0] = newMassProperties->m_volume / newMassProperties->m_mass;
    v7 = _mm_shuffle_ps(v6, v6, 0);
    v8 = _mm_shuffle_ps((__m128)LODWORD(newMassProperties->m_mass), (__m128)LODWORD(newMassProperties->m_mass), 0).m128_f32[0]
       * v7.m128_f32[0];
    v18.m_real = v7;
    hkMatrix3f::mul(&newMassProperties->m_inertiaTensor, &v18);
    newMassProperties->m_mass = v8;
    m_volume = massPropertiesOut->m_volume;
    v7.m128_i32[0] = LODWORD(massPropertiesOut->m_mass);
    m_quad = ::transform.m_quad;
    v34.m_col0 = (hkVector4f)::transform.m_quad;
    *(float *)v21 = m_volume;
    v21[1] = v7.m128_i32[0];
    elements.m_capacityAndFlags = -2147483646;
    elements.m_size = 2;
    elements.m_data = (hkMassElement *)v21;
    v10.m_quad = (__m128)massPropertiesOut->m_centerOfMass;
    v11.m_quad = (__m128)massPropertiesOut->m_inertiaTensor.m_col0;
    v25 = direction.m_quad;
    *(hkVector4f *)&v22.m256i_u64[1] = (hkVector4f)v10.m_quad;
    v12.m_quad = (__m128)massPropertiesOut->m_inertiaTensor.m_col1;
    *(hkVector4f *)v22.m256i_i8 = (hkVector4f)v11.m_quad;
    v13.m_quad = (__m128)massPropertiesOut->m_inertiaTensor.m_col2;
    *(hkVector4f *)&v22.m256i_u64[2] = (hkVector4f)v12.m_quad;
    v34.m_col1 = (hkVector4f)direction.m_quad;
    v27 = 0i64;
    v35 = 0i64;
    v23 = v13.m_quad;
    v28 = newMassProperties->m_volume;
    v14.m_quad = (__m128)newMassProperties->m_centerOfMass;
    v26 = stru_141A71280.m_quad;
    v34.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v30 = v14.m_quad;
    m_mass = newMassProperties->m_mass;
    v15.m_quad = (__m128)newMassProperties->m_inertiaTensor.m_col0;
    v32.m_quad = (__m128)newMassProperties->m_inertiaTensor.m_col1;
    v16.m_quad = (__m128)transform->m_translation;
    v31 = v15.m_quad;
    v17.m_quad = (__m128)newMassProperties->m_inertiaTensor.m_col2;
    v37 = v16.m_quad;
    v33 = v17.m_quad;
    hkRotationf::set(&v36, &transform->m_rotation);
    v34 = v36;
    v35 = v37;
    hkInertiaTensorComputer::combineMassProperties(&result, &elements, massPropertiesOut);
    elements.m_size = 0;
    if ( elements.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        elements.m_data,
        144 * (elements.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 532
// RVA: 0xE0F2E0
hkSimdFloat32 *__fastcall hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(
        hkSimdFloat32 *result,
        hkArray<hkpConstraintInstance const *,hkContainerHeapAllocator> *constraints,
        hkpRigidBody *body,
        hkSimdFloat32 *inertiaFactorHint)
{
  int v5; // edx
  int v8; // esi
  __int64 v9; // r8
  hkpConstraintInstance **m_data; // rcx
  hkpConstraintInstance *v11; // rdi
  hkpRigidBody *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdi
  __m128 v15; // xmm7
  __m128 i; // xmm8
  __int64 v17; // rcx
  hkpRigidBody *v18; // r8
  __m128 *v19; // rbx
  int v20; // r8d
  hkVector4f v21; // xmm5
  __m128 v22; // xmm2
  __m128 v23; // xmm9
  __m128 v24; // xmm6
  __m128 v25; // xmm2
  hkMatrix3f inertia; // [rsp+20h] [rbp-C8h] BYREF
  char *array; // [rsp+50h] [rbp-98h] BYREF
  int v29; // [rsp+58h] [rbp-90h]
  int v30; // [rsp+5Ch] [rbp-8Ch]
  char v31; // [rsp+60h] [rbp-88h] BYREF
  hkSimdFloat32 resulta; // [rsp+C8h] [rbp-20h] BYREF
  __m128 *v33; // [rsp+168h] [rbp+80h]
  __int64 vars0; // [rsp+170h] [rbp+88h]
  hkpRigidBody *retaddr; // [rsp+178h] [rbp+90h]

  v5 = 0;
  v30 = -2147483632;
  v29 = 0;
  v8 = constraints->m_size - 1;
  array = &v31;
  v9 = v8;
  vars0 = v8;
  if ( v8 >= 0 )
  {
    while ( 1 )
    {
      m_data = constraints->m_data;
      v11 = constraints->m_data[v9];
      v12 = (hkpRigidBody *)v11->m_entities[0];
      if ( v12 == body )
        break;
      if ( v11->m_entities[1] == body )
        goto LABEL_5;
LABEL_11:
      --v8;
      vars0 = --v9;
      if ( v9 < 0 )
      {
        inertiaFactorHint = result;
        goto LABEL_13;
      }
    }
    v12 = (hkpRigidBody *)v11->m_entities[1];
LABEL_5:
    if ( v12 )
    {
      v13 = --constraints->m_size;
      if ( (_DWORD)v13 != v8 )
      {
        m_data[v9] = m_data[v13];
        v5 = v29;
      }
      if ( v5 == (v30 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
        v5 = v29;
        v9 = vars0;
        body = retaddr;
      }
      *(_QWORD *)&array[8 * v5] = v11;
      v5 = ++v29;
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
    if ( v18 == body )
      v18 = *(hkpRigidBody **)(v17 + 48);
    hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(&resulta, constraints, v18, inertiaFactorHint);
    --v14;
    body = retaddr;
    inertiaFactorHint = result;
    v15 = _mm_add_ps(v15, resulta.m_real);
  }
  if ( (unsigned __int8)(retaddr->m_motion.m_type.m_storage - 4) > 1u )
  {
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *, __int64, hkpRigidBody *))retaddr->m_motion.hkpEntity::vfptr[3].__first_virtual_table_function__)(
      &retaddr->m_motion,
      &inertia,
      v9,
      body);
    v21.m_quad = (__m128)inertia.m_col0;
    v22 = _mm_or_ps(
            _mm_andnot_ps(
              (__m128)xmmword_141AA7620,
              _mm_or_ps(
                _mm_andnot_ps((__m128)xmmword_141AA7600, inertia.m_col0.m_quad),
                _mm_and_ps(inertia.m_col1.m_quad, (__m128)xmmword_141AA7600))),
            _mm_and_ps(inertia.m_col2.m_quad, (__m128)xmmword_141AA7620));
    v23 = _mm_max_ps(
            _mm_shuffle_ps(v22, v22, 170),
            _mm_max_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)));
    if ( v15.m128_f32[0] == 0.0 )
    {
      v19 = v33;
      *v33 = v23;
    }
    else
    {
      v24 = _mm_max_ps(_mm_min_ps(v15, _mm_mul_ps(v23, result->m_real)), i);
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
      *v33 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(v23, result->m_real), _mm_add_ps(v15, v23)), v24);
    }
    v29 = 0;
    if ( v30 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v30);
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
        body);
  }
  return (hkSimdFloat32 *)v19;
}

// File Line: 607
// RVA: 0xE0E570
void __fastcall hkpInertiaTensorComputer::optimizeInertiasOfConstraintTree(
        hkpConstraintInstance *const *constraints,
        int numConstraints,
        hkpRigidBody *rootBody,
        float inertiaFactorHint)
{
  __int64 v4; // rbx
  int m_size; // r9d
  hkLifoAllocator *Value; // rax
  hkpConstraintInstance **m_cur; // rcx
  int v10; // edx
  char *v11; // r8
  __int64 v12; // rax
  __int64 v13; // rdx
  int v14; // eax
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // r8d
  hkSimdFloat32 inertiaFactorHinta; // [rsp+20h] [rbp-40h] BYREF
  hkSimdFloat32 result; // [rsp+30h] [rbp-30h] BYREF
  hkArray<hkpConstraintInstance const *,hkContainerHeapAllocator> constraintsa; // [rsp+40h] [rbp-20h] BYREF
  void *p; // [rsp+50h] [rbp-10h]
  int v23; // [rsp+58h] [rbp-8h]

  v4 = numConstraints;
  constraintsa.m_capacityAndFlags = 0x80000000;
  constraintsa.m_data = 0i64;
  m_size = 0;
  constraintsa.m_size = 0;
  v23 = numConstraints;
  if ( numConstraints )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpConstraintInstance **)Value->m_cur;
    v10 = (8 * v4 + 127) & 0xFFFFFF80;
    v11 = (char *)m_cur + v10;
    if ( v10 > Value->m_slabSize || v11 > Value->m_end )
    {
      v12 = hkLifoAllocator::allocateFromNewSlab(Value, v10);
      m_size = constraintsa.m_size;
      m_cur = (hkpConstraintInstance **)v12;
    }
    else
    {
      Value->m_cur = v11;
      m_size = constraintsa.m_size;
    }
  }
  else
  {
    m_cur = 0i64;
  }
  constraintsa.m_data = m_cur;
  p = m_cur;
  v13 = 0i64;
  constraintsa.m_capacityAndFlags = v4 | 0x80000000;
  if ( (int)v4 > 0 )
  {
    while ( 1 )
    {
      m_cur[m_size] = constraints[v13++];
      m_size = ++constraintsa.m_size;
      if ( v13 >= v4 )
        break;
      m_cur = constraintsa.m_data;
    }
  }
  inertiaFactorHinta.m_real = _mm_shuffle_ps((__m128)LODWORD(inertiaFactorHint), (__m128)LODWORD(inertiaFactorHint), 0);
  hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(&result, &constraintsa, rootBody, &inertiaFactorHinta);
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
      &hkContainerHeapAllocator::s_alloc,
      constraintsa.m_data,
      8 * constraintsa.m_capacityAndFlags);
}

