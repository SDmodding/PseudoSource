// File Line: 30
// RVA: 0xCFA7F0
void __fastcall hkpConvexShape::hkpConvexShape(hkpConvexShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape *v2; // rbx

  v2 = this;
  hkpShape::hkpShape((hkpShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpConvexShape::`vftable';
  v2->m_type.m_storage = 23;
}

// File Line: 35
// RVA: 0xCFA820
float __fastcall hkpConvexShape::getMaximumProjection(hkpConvexShape *this, hkVector4f *direction)
{
  hkVector4f *v2; // rbx
  hkpConvexShape *v3; // rdi
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  float v8; // xmm5_4
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v12; // [rsp+20h] [rbp-18h]

  v2 = direction;
  v3 = this;
  ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, __m128 *))this->vfptr[4].__vecDelDtor)(this, direction, &v12);
  v4 = v2->m_quad;
  v5 = v4;
  v6 = _mm_mul_ps(v4, v4);
  v7 = _mm_mul_ps(v5, v12);
  v8 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 0)))
     + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v10 = _mm_rsqrt_ps(v9);
  return (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v3->m_radius), (__m128)LODWORD(v3->m_radius), 0))
               * COERCE_FLOAT(
                   _mm_andnot_ps(
                     _mm_cmpleps(v9, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                         _mm_mul_ps(*(__m128 *)_xmm, v10)),
                       v9))))
       + v8;
}

// File Line: 46
// RVA: 0xCFA740
void __fastcall hkpConvexShape::castRayWithCollector(hkpConvexShape *this, hkpShapeRayCastInput *inputLocal, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkBaseObjectVtbl *v4; // rax
  hkpCdBody *v5; // rdi
  hkpRayHitCollector *v6; // rbx
  __m128 *v7; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  hkpRayHitCollectorVtbl *v11; // rax
  __m128 v12; // [rsp+20h] [rbp-58h]
  float v13; // [rsp+30h] [rbp-48h]
  int v14; // [rsp+34h] [rbp-44h]
  int v15; // [rsp+40h] [rbp-38h]
  int v16; // [rsp+60h] [rbp-18h]
  char v17; // [rsp+80h] [rbp+8h]

  v4 = this->vfptr;
  v5 = cdBody;
  v6 = collector;
  v13 = collector->m_earlyOutHitFraction;
  v14 = -1;
  v16 = 0;
  v15 = -1;
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkpConvexShape *, char *, hkpShapeRayCastInput *, __m128 *))v4[2].__first_virtual_table_function__)(
                   this,
                   &v17,
                   inputLocal,
                   &v12) )
  {
    v7 = (__m128 *)v5->m_motion;
    v8 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v7[1]);
    v9 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), *v7);
    v10 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v7[2]);
    v11 = v6->vfptr;
    v12 = _mm_add_ps(_mm_add_ps(v8, v9), v10);
    v11->addRayHit(v6, v5, (hkpShapeRayCastCollectorOutput *)&v12);
  }
}

// File Line: 62
// RVA: 0xCFA730
signed __int64 __fastcall hkpConvexShape::weldContactPoint(hkpConvexShape *this, unsigned __int16 *featurePoints, char *numFeaturePoints, hkVector4f *contactPointWs)
{
  return 2i64;
}

// File Line: 67
// RVA: 0xCFA6E0
void __fastcall hkpConvexShape::getCentre(hkpConvexShape *this, hkVector4f *centreOut, __int64 a3)
{
  hkVector4f *v3; // rbx
  __m128 v4; // xmm0
  __m128 v5; // [rsp+20h] [rbp-28h]
  __m128 v6; // [rsp+30h] [rbp-18h]

  v3 = centreOut;
  ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, __int64, __m128 *))this->vfptr[2].__vecDelDtor)(
    this,
    &transform,
    a3,
    &v5);
  v4 = _mm_add_ps(v5, v6);
  *v3 = (hkVector4f)v4;
  v3->m_quad = _mm_mul_ps(v4, (__m128)xmmword_141A711B0);
}

// File Line: 79
// RVA: 0xCFA8D0
void __fastcall hkpConvexTransformShapeBase::hkpConvexTransformShapeBase(hkpConvexTransformShapeBase *this, hkcdShapeType::ShapeTypeEnum type, float radius, hkpConvexShape *childShape, hkpShapeContainer::ReferencePolicy ref)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = type;
  *(_WORD *)&this->m_dispatchType.m_storage = 4;
  this->m_shapeInfoCodecType.m_storage = 0;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexTransformShapeBase::`vftable';
  this->m_userData = 0i64;
  this->m_childShape.m_childShape = (hkpShape *)&childShape->vfptr;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable';
  if ( ref == 1 )
    hkReferencedObject::addReference((hkReferencedObject *)&childShape->vfptr);
}

