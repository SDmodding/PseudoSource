// File Line: 517
// RVA: 0xDC7500
void __fastcall `anonymous namespace::hkpStaticCompoundShape_RayHitCollectorWrapper::addRayHit(hkpStaticCompoundShape_RayHitCollectorWrapper *this, hkpCdBody *cdBody, hkpShapeRayCastCollectorOutput *hitInfo)
{
  hkpStaticCompoundShape_Internals::RayCastQuery *v3; // rax
  __int128 v4; // xmm1
  hkpStaticCompoundShape_RayHitCollectorWrapper *v5; // rbx
  hkpCdBody *v6; // rcx
  hkpStaticCompoundShape_Internals *v7; // r13
  hkpCdBody *v8; // r15
  hkpCdBody *v9; // rdi
  hkpCdBody *v10; // rax
  unsigned int v11; // esi
  int v12; // ebp
  int v13; // er14
  hkpCdBody *v14; // rcx
  int v15; // er14
  hkpCdBody *v16; // rcx
  hkpStaticCompoundShape_Internals::RayCastQuery *v17; // r8
  hkpRayShapeCollectionFilter *v18; // rcx
  signed __int64 v19; // r9
  hkpStaticCompoundShape::Instance *v20; // r8
  int v21; // eax
  int v22; // eax
  bool v23; // zf
  __m128 *v24; // rax
  __m128 v25; // xmm7
  __m128 v26; // xmm0
  __m128 v27; // xmm5
  __m128 *v28; // rax
  __m128 v29; // xmm3
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm6
  __m128 v34; // xmm1
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm0
  __m128 v41; // xmm3
  __m128 v42; // xmm6
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm4
  hkVector4f v46; // [rsp+30h] [rbp-298h]
  __int128 v47; // [rsp+40h] [rbp-288h]
  hkErrStream v48; // [rsp+50h] [rbp-278h]
  char buf; // [rsp+80h] [rbp-248h]
  char v50; // [rsp+2D0h] [rbp+8h]

  v3 = this->m_query;
  v4 = *(_OWORD *)&hitInfo->m_hitFraction;
  v5 = this;
  v6 = this->m_instanceCdBody;
  v7 = v3->m_owner;
  v8 = cdBody;
  v9 = cdBody;
  v46.m_quad = (__m128)hitInfo->m_normal;
  v47 = v4;
  v10 = cdBody;
  if ( cdBody != v6 )
  {
    while ( v10 )
    {
      v9 = v10;
      v10 = v10->m_parent;
      if ( v10 == v6 )
        goto LABEL_8;
    }
    hkErrStream::hkErrStream(&v48, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v48.vfptr, "Parent hkpCdBody not found");
    if ( (unsigned int)hkError::messageError(
                         109738058,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Physics2012/Internal/Collide/StaticCompound/hkpStaticCom"
                         "poundShape_Internals.inl",
                         547) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v48.vfptr);
  }
LABEL_8:
  v11 = v9->m_shapeKey;
  v12 = 0;
  if ( v11 == -1 )
    v11 = 0;
  v13 = v5->m_instanceId << v7->m_numBitsForChildShapeKey;
  v14 = v5->m_instanceCdBody;
  v14->m_shape = v9->m_shape;
  v15 = v11 | v13;
  v14->m_shapeKey = v15;
  v16 = v5->m_instanceCdBody;
  v9->m_shape = v16->m_shape;
  *(_QWORD *)&v9->m_shapeKey = *(_QWORD *)&v16->m_shapeKey;
  v9->m_motion = v16->m_motion;
  v9->m_parent = v16->m_parent;
  v17 = v5->m_query;
  v18 = v17->m_input.m_rayShapeCollectionFilter;
  if ( !v18 )
    goto LABEL_30;
  v19 = (signed __int64)&v17->m_owner->vfptr;
  if ( !v17->m_owner )
    v19 = 0i64;
  if ( *(_BYTE *)v18->vfptr->isCollisionEnabled(v18, (hkBool *)&v50, &v17->m_input, (hkpShapeContainer *)v19, v15) )
  {
LABEL_30:
    if ( v5->m_checkDisabledKeys.m_bool )
    {
      v20 = v5->m_instance;
      v21 = v20->m_transform.m_translation.m_quad.m128_i32[3] & 0x7F;
      if ( v20->m_transform.m_translation.m_quad.m128_i8[12] & 0x10 )
        return;
      if ( v11 >= 0x25 )
      {
        if ( v21 & 0x40 )
        {
          v23 = hkpShapeKeyTable::exists(&v7->m_disabledLargeShapeKeyTable, v15) == 0;
          goto LABEL_24;
        }
      }
      else if ( v21 & 0x20 )
      {
        if ( v11 >= 0xD )
          v22 = (1 << (v11 - 13)) & v20->m_transform.m_scale.m_quad.m128_i32[3];
        else
          v22 = (1 << (v11 + 11)) & v20->m_transform.m_translation.m_quad.m128_i32[3];
        v23 = (v22 & 0xC0FFFFFF) == 0;
LABEL_24:
        LOBYTE(v12) = v23;
        if ( !v12 )
          return;
        goto LABEL_25;
      }
    }
LABEL_25:
    if ( v5->m_fixNormals.m_bool )
    {
      v24 = &v5->m_instance->m_transform.m_translation.m_quad;
      v25 = v24[1];
      v26 = *v24;
      v27 = v24[2];
      v28 = (__m128 *)v8->m_motion;
      v29 = v28[2];
      v30 = *v28;
      *(__m128 *)&v48.vfptr = v26;
      v31 = _mm_unpacklo_ps(v30, v28[1]);
      v32 = _mm_movelh_ps(v31, v29);
      v33 = _mm_mul_ps(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 85), _mm_shuffle_ps(_mm_movehl_ps(v32, v31), v29, 212));
      v34 = _mm_rcp_ps(v27);
      v35 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(v33, _mm_mul_ps(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 0), v32)),
                _mm_mul_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v30, v28[1]), v29, 228),
                  _mm_shuffle_ps(v46.m_quad, v46.m_quad, 170))),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v34)), v34));
      v36 = _mm_mul_ps(v35, v35);
      v37 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
              _mm_shuffle_ps(v36, v36, 170));
      v38 = _mm_rsqrt_ps(v37);
      v39 = _mm_cmpleps(v37, (__m128)0i64);
      v40 = _mm_mul_ps(_mm_mul_ps(v38, v37), v38);
      v41 = _mm_shuffle_ps(v25, v25, 255);
      v42 = _mm_mul_ps(
              v35,
              _mm_andnot_ps(v39, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v40), _mm_mul_ps(*(__m128 *)_xmm, v38))));
      v43 = _mm_mul_ps(v25, v42);
      v44 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v25), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v42));
      v45 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                    _mm_shuffle_ps(v43, v43, 170)),
                  v25),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v41, v41), (__m128)xmmword_141A711B0), v42)),
              _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v41));
      v46.m_quad = _mm_add_ps(v45, v45);
      v46.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 85), v28[1]),
                       _mm_mul_ps(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 0), *v28)),
                     _mm_mul_ps(_mm_shuffle_ps(v46.m_quad, v46.m_quad, 170), v28[2]));
    }
    v5->m_childCollector->vfptr->addRayHit(v5->m_childCollector, v8, (hkpShapeRayCastCollectorOutput *)&v46);
  }
}

