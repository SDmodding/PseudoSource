// File Line: 30
// RVA: 0xCFA7F0
void __fastcall hkpConvexShape::hkpConvexShape(hkpConvexShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexShape::`vftable;
  this->m_type.m_storage = 23;
}

// File Line: 35
// RVA: 0xCFA820
float __fastcall hkpConvexShape::getMaximumProjection(hkpConvexShape *this, hkVector4f *direction)
{
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  float v6; // xmm5_4
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v10; // [rsp+20h] [rbp-18h] BYREF

  ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, __m128 *))this->vfptr[4].__vecDelDtor)(this, direction, &v10);
  v4 = _mm_mul_ps(direction->m_quad, direction->m_quad);
  v5 = _mm_mul_ps(direction->m_quad, v10);
  v6 = (float)(_mm_shuffle_ps(v5, v5, 85).m128_f32[0] + _mm_shuffle_ps(v5, v5, 0).m128_f32[0])
     + _mm_shuffle_ps(v5, v5, 170).m128_f32[0];
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v8 = _mm_rsqrt_ps(v7);
  return (float)(_mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0).m128_f32[0]
               * _mm_andnot_ps(
                   _mm_cmple_ps(v7, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)),
                       _mm_mul_ps(*(__m128 *)_xmm, v8)),
                     v7)).m128_f32[0])
       + v6;
}

// File Line: 46
// RVA: 0xCFA740
void __fastcall hkpConvexShape::castRayWithCollector(
        hkpConvexShape *this,
        hkpShapeRayCastInput *inputLocal,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkBaseObjectVtbl *vfptr; // rax
  __m128 *m_motion; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  hkpRayHitCollectorVtbl *v11; // rax
  __m128 v12; // [rsp+20h] [rbp-58h] BYREF
  float m_earlyOutHitFraction; // [rsp+30h] [rbp-48h]
  int v14; // [rsp+34h] [rbp-44h]
  int v15; // [rsp+40h] [rbp-38h]
  int v16; // [rsp+60h] [rbp-18h]
  char v17; // [rsp+80h] [rbp+8h] BYREF

  vfptr = this->vfptr;
  m_earlyOutHitFraction = collector->m_earlyOutHitFraction;
  v14 = -1;
  v16 = 0;
  v15 = -1;
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkpConvexShape *, char *, hkpShapeRayCastInput *, __m128 *))vfptr[2].__first_virtual_table_function__)(
                   this,
                   &v17,
                   inputLocal,
                   &v12) )
  {
    m_motion = (__m128 *)cdBody->m_motion;
    v8 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), m_motion[1]);
    v9 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), *m_motion);
    v10 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), m_motion[2]);
    v11 = collector->vfptr;
    v12 = _mm_add_ps(_mm_add_ps(v8, v9), v10);
    v11->addRayHit(collector, cdBody, (hkpShapeRayCastCollectorOutput *)&v12);
  }
}

// File Line: 62
// RVA: 0xCFA730
__int64 __fastcall hkpConvexShape::weldContactPoint(
        hkpConvexShape *this,
        unsigned __int16 *featurePoints,
        char *numFeaturePoints,
        hkVector4f *contactPointWs)
{
  return 2i64;
}

// File Line: 67
// RVA: 0xCFA6E0
void __fastcall hkpConvexShape::getCentre(hkpConvexShape *this, hkVector4f *centreOut, __int64 a3)
{
  __m128 v4; // xmm0
  __m128 v5[2]; // [rsp+20h] [rbp-28h] BYREF

  ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, __int64, __m128 *))this->vfptr[2].__vecDelDtor)(
    this,
    &transform,
    a3,
    v5);
  v4 = _mm_add_ps(v5[0], v5[1]);
  *centreOut = (hkVector4f)v4;
  centreOut->m_quad = _mm_mul_ps(v4, (__m128)xmmword_141A711B0);
}

// File Line: 79
// RVA: 0xCFA8D0
void __fastcall hkpConvexTransformShapeBase::hkpConvexTransformShapeBase(
        hkpConvexTransformShapeBase *this,
        hkcdShapeType::ShapeTypeEnum type,
        float radius,
        hkpConvexShape *childShape,
        hkpShapeContainer::ReferencePolicy ref)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = type;
  *(_WORD *)&this->m_dispatchType.m_storage = 4;
  this->m_shapeInfoCodecType.m_storage = 0;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexTransformShapeBase::`vftable;
  this->m_userData = 0i64;
  this->m_childShape.m_childShape = childShape;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  if ( ref == REFERENCE_POLICY_INCREMENT )
    hkReferencedObject::addReference(childShape);
}

