// File Line: 517
// RVA: 0xDC7500
void __fastcall `anonymous namespace::hkpStaticCompoundShape_RayHitCollectorWrapper::addRayHit(
        hkpStaticCompoundShape_RayHitCollectorWrapper *this,
        hkpCdBody *cdBody,
        hkpShapeRayCastCollectorOutput *hitInfo)
{
  hkpStaticCompoundShape_Internals::RayCastQuery *m_query; // rax
  __m128 v4; // xmm1
  hkpCdBody *m_instanceCdBody; // rcx
  hkpStaticCompoundShape_Internals *m_owner; // r13
  hkpCdBody *v9; // rdi
  hkpCdBody *v10; // rax
  unsigned int m_shapeKey; // esi
  int v12; // ebp
  int v13; // r14d
  hkpCdBody *v14; // rcx
  int v15; // r14d
  hkpCdBody *v16; // rcx
  hkpStaticCompoundShape_Internals::RayCastQuery *v17; // r8
  hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter; // rcx
  __int64 v19; // r9
  hkpStaticCompoundShape::Instance *m_instance; // r8
  int v21; // eax
  bool v22; // zf
  hkpStaticCompoundShape::Instance *v23; // rax
  __m128 m_quad; // xmm7
  hkReferencedObject m_translation; // xmm0
  __m128 v26; // xmm5
  __m128 *m_motion; // rax
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm6
  __m128 v33; // xmm1
  __m128 v34; // xmm6
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm4
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm6
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm4
  __m128 v45[2]; // [rsp+30h] [rbp-298h] BYREF
  hkErrStream v46; // [rsp+50h] [rbp-278h] BYREF
  char buf[512]; // [rsp+80h] [rbp-248h] BYREF
  char v48; // [rsp+2D0h] [rbp+8h] BYREF

  m_query = this->m_query;
  v4 = *(__m128 *)&hitInfo->m_hitFraction;
  m_instanceCdBody = this->m_instanceCdBody;
  m_owner = m_query->m_owner;
  v9 = cdBody;
  v45[0] = hitInfo->m_normal.m_quad;
  v45[1] = v4;
  v10 = cdBody;
  if ( cdBody != m_instanceCdBody )
  {
    while ( v10 )
    {
      v9 = v10;
      v10 = v10->m_parent;
      if ( v10 == m_instanceCdBody )
        goto LABEL_8;
    }
    hkErrStream::hkErrStream(&v46, buf, 512);
    hkOstream::operator<<(&v46, "Parent hkpCdBody not found");
    if ( (unsigned int)hkError::messageError(
                         0x68A784Au,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Physics2012/Internal/Collide/StaticCompound/hkpStaticCom"
                         "poundShape_Internals.inl",
                         547) )
      __debugbreak();
    hkOstream::~hkOstream(&v46);
  }
LABEL_8:
  m_shapeKey = v9->m_shapeKey;
  v12 = 0;
  if ( m_shapeKey == -1 )
    m_shapeKey = 0;
  v13 = this->m_instanceId << m_owner->m_numBitsForChildShapeKey;
  v14 = this->m_instanceCdBody;
  v14->m_shape = v9->m_shape;
  v15 = m_shapeKey | v13;
  v14->m_shapeKey = v15;
  v16 = this->m_instanceCdBody;
  v9->m_shape = v16->m_shape;
  *(_QWORD *)&v9->m_shapeKey = *(_QWORD *)&v16->m_shapeKey;
  v9->m_motion = v16->m_motion;
  v9->m_parent = v16->m_parent;
  v17 = this->m_query;
  m_rayShapeCollectionFilter = v17->m_input.m_rayShapeCollectionFilter;
  if ( !m_rayShapeCollectionFilter )
    goto LABEL_30;
  v19 = (__int64)&v17->m_owner->hkpShapeContainer;
  if ( !v17->m_owner )
    v19 = 0i64;
  if ( *(_BYTE *)m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                   m_rayShapeCollectionFilter,
                   (hkBool *)&v48,
                   &v17->m_input,
                   (hkpShapeContainer *)v19,
                   v15) )
  {
LABEL_30:
    if ( this->m_checkDisabledKeys.m_bool )
    {
      m_instance = this->m_instance;
      if ( (m_instance->m_transform.m_translation.m_quad.m128_i8[12] & 0x10) != 0 )
        return;
      if ( m_shapeKey >= 0x25 )
      {
        if ( (m_instance->m_transform.m_translation.m_quad.m128_i8[12] & 0x40) != 0 )
        {
          v22 = !hkpShapeKeyTable::exists(&m_owner->m_disabledLargeShapeKeyTable, v15);
          goto LABEL_24;
        }
      }
      else if ( (m_instance->m_transform.m_translation.m_quad.m128_i8[12] & 0x20) != 0 )
      {
        if ( m_shapeKey >= 0xD )
          v21 = (1 << (m_shapeKey - 13)) & m_instance->m_transform.m_scale.m_quad.m128_i32[3];
        else
          v21 = (1 << (m_shapeKey + 11)) & m_instance->m_transform.m_translation.m_quad.m128_i32[3];
        v22 = (v21 & 0xC0FFFFFF) == 0;
LABEL_24:
        LOBYTE(v12) = v22;
        if ( !v12 )
          return;
      }
    }
    if ( this->m_fixNormals.m_bool )
    {
      v23 = this->m_instance;
      m_quad = v23->m_transform.m_rotation.m_vec.m_quad;
      m_translation = (hkReferencedObject)v23->m_transform.m_translation;
      v26 = v23->m_transform.m_scale.m_quad;
      m_motion = (__m128 *)cdBody->m_motion;
      v28 = m_motion[2];
      v29 = *m_motion;
      v46.hkReferencedObject = m_translation;
      v30 = _mm_unpacklo_ps(v29, m_motion[1]);
      v31 = _mm_movelh_ps(v30, v28);
      v32 = _mm_mul_ps(_mm_shuffle_ps(v45[0], v45[0], 85), _mm_shuffle_ps(_mm_movehl_ps(v31, v30), v28, 212));
      v33 = _mm_rcp_ps(v26);
      v34 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(v32, _mm_mul_ps(_mm_shuffle_ps(v45[0], v45[0], 0), v31)),
                _mm_mul_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v29, m_motion[1]), v28, 228),
                  _mm_shuffle_ps(v45[0], v45[0], 170))),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v33)), v33));
      v35 = _mm_mul_ps(v34, v34);
      v36 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
              _mm_shuffle_ps(v35, v35, 170));
      v37 = _mm_rsqrt_ps(v36);
      v38 = _mm_cmple_ps(v36, (__m128)0i64);
      v39 = _mm_mul_ps(_mm_mul_ps(v37, v36), v37);
      v40 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v41 = _mm_mul_ps(
              v34,
              _mm_andnot_ps(v38, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v39), _mm_mul_ps(*(__m128 *)_xmm, v37))));
      v42 = _mm_mul_ps(m_quad, v41);
      v43 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v41));
      v44 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                    _mm_shuffle_ps(v42, v42, 170)),
                  m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v40, v40), (__m128)xmmword_141A711B0), v41)),
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v40));
      v45[0] = _mm_add_ps(v44, v44);
      v45[0] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v45[0], v45[0], 85), m_motion[1]),
                   _mm_mul_ps(_mm_shuffle_ps(v45[0], v45[0], 0), *m_motion)),
                 _mm_mul_ps(_mm_shuffle_ps(v45[0], v45[0], 170), m_motion[2]));
    }
    this->m_childCollector->vfptr->addRayHit(this->m_childCollector, cdBody, (hkpShapeRayCastCollectorOutput *)v45);
  }
}

