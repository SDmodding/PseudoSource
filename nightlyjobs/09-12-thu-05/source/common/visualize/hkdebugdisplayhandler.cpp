// File Line: 19
// RVA: 0xE6D010
hkResult *__fastcall hkDebugDisplayHandler::addGeometry(
        hkDebugDisplayHandler *this,
        hkResult *result,
        hkDisplayGeometry *geometry,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  hkDebugDisplayHandlerVtbl *vfptr; // r10
  hkDisplayGeometry **v9; // [rsp+40h] [rbp-28h] BYREF
  int v10; // [rsp+48h] [rbp-20h]
  int v11; // [rsp+4Ch] [rbp-1Ch]
  hkDisplayGeometry *v12; // [rsp+50h] [rbp-18h] BYREF

  vfptr = this->vfptr;
  v12 = geometry;
  v9 = &v12;
  v11 = -2147483647;
  v10 = 1;
  (*(void (__fastcall **)(hkDebugDisplayHandler *, hkResult *, hkDisplayGeometry ***, hkTransformf *, unsigned __int64, int, unsigned __int64, _DWORD))vfptr->gap8)(
    this,
    result,
    &v9,
    &geometry->m_transform,
    id,
    tag,
    shapeIdHint,
    0);
  v10 = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v9, 8 * v11);
  return result;
}

// File Line: 26
// RVA: 0xE6D0C0
hkResult *__fastcall hkDebugDisplayHandler::updateGeometry(
        hkDebugDisplayHandler *this,
        hkResult *result,
        hkQsTransformf *transform,
        unsigned __int64 id,
        int tag)
{
  hkMatrix4f v9; // [rsp+30h] [rbp-48h] BYREF

  hkMatrix4f::set(&v9, transform);
  this->vfptr->updateGeometry(this, result, &v9, id, tag);
  return result;
}

// File Line: 34
// RVA: 0xE6D120
hkResult *__fastcall hkDebugDisplayHandler::skinGeometry(
        hkDebugDisplayHandler *this,
        hkResult *result,
        unsigned __int64 *ids,
        int numIds,
        hkQsTransformf *poseModel,
        unsigned int numPoseModel,
        hkQsTransformf *worldFromModel,
        int tag)
{
  hkLifoAllocator *Value; // rax
  hkMatrix4f *m_cur; // rbp
  int v12; // r14d
  char *v13; // rcx
  hkMatrix4f *v15; // rbx
  __int64 v16; // rsi
  hkLifoAllocator *v17; // rax
  int v18; // r8d
  hkMatrix4f v20; // [rsp+40h] [rbp-78h] BYREF

  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkMatrix4f *)Value->m_cur;
  v12 = ((numPoseModel << 6) + 127) & 0xFFFFFF80;
  v13 = (char *)m_cur + v12;
  if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    m_cur = (hkMatrix4f *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
  else
    Value->m_cur = v13;
  if ( (int)numPoseModel > 0 )
  {
    v15 = m_cur;
    v16 = numPoseModel;
    do
    {
      hkMatrix4f::set(v15++, poseModel++);
      --v16;
    }
    while ( v16 );
  }
  hkMatrix4f::set(&v20, worldFromModel);
  this->vfptr->skinGeometry(this, result, ids, numIds, m_cur, numPoseModel, &v20, tag);
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v17->m_slabSize || (char *)m_cur + v18 != v17->m_cur || v17->m_firstNonLifoEnd == m_cur )
  {
    hkLifoAllocator::slowBlockFree(v17, (char *)m_cur, v18);
    return result;
  }
  else
  {
    v17->m_cur = m_cur;
    return result;
  }
}

// File Line: 49
// RVA: 0xE6D2C0
// local variable allocation has failed, the output may be wrong!
void __fastcall hkDebugDisplayHandler::displayFrame(
        hkDebugDisplayHandler *this,
        hkQsTransformf *worldFromLocal,
        double size,
        int id)
{
  hkVector4f b; // [rsp+28h] [rbp-41h] BYREF
  hkVector4f from; // [rsp+38h] [rbp-31h] BYREF
  hkVector4f v9; // [rsp+48h] [rbp-21h] BYREF
  hkVector4f v10; // [rsp+58h] [rbp-11h] BYREF
  hkVector4f v11; // [rsp+68h] [rbp-1h] BYREF
  hkVector4f dir; // [rsp+78h] [rbp+Fh] BYREF
  hkVector4f v13; // [rsp+88h] [rbp+1Fh] BYREF
  hkVector4f v14; // [rsp+98h] [rbp+2Fh] BYREF
  int v15; // [rsp+E8h] [rbp+7Fh]

  b.m_quad = 0i64;
  hkVector4f::setTransformedPos(
    (hkVector4f *)&from.m_quad.m128_u16[4],
    worldFromLocal,
    (hkVector4f *)&b.m_quad.m128_u16[4]);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(*(__m128 *)&size, (__m128)0i64), (__m128)0i64);
  hkVector4f::setTransformedPos(&v9, worldFromLocal, &b);
  b.m_quad = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(*(__m128 *)&size, (__m128)0i64));
  hkVector4f::setTransformedPos(&v10, worldFromLocal, &b);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, *(__m128 *)&size), (__m128)0i64);
  hkVector4f::setTransformedPos(&v11, worldFromLocal, &b);
  dir.m_quad = _mm_sub_ps(v9.m_quad, from.m_quad);
  v14.m_quad = _mm_sub_ps(v11.m_quad, from.m_quad);
  v13.m_quad = _mm_sub_ps(v10.m_quad, from.m_quad);
  hkDebugDisplayHandler::displayArrow(this, &from, &dir, hkColor::RED, id, v15);
  hkDebugDisplayHandler::displayArrow(this, &from, &v13, hkColor::GREEN, id, v15);
  hkDebugDisplayHandler::displayArrow(this, &from, &v14, hkColor::BLUE, id, v15);
}

// File Line: 74
// RVA: 0xE6D420
void __fastcall hkDebugDisplayHandler::displayFrame(
        hkDebugDisplayHandler *this,
        hkTransformf *worldFromLocal,
        double size,
        int id)
{
  hkQsTransformf worldFromLocala; // [rsp+30h] [rbp-48h] BYREF

  hkQsTransformf::setFromTransform(&worldFromLocala, worldFromLocal);
  hkDebugDisplayHandler::displayFrame(this, &worldFromLocala, size, id);
}

// File Line: 81
// RVA: 0xE6D480
void __fastcall hkDebugDisplayHandler::displayArrow(
        hkDebugDisplayHandler *this,
        hkVector4f *from,
        hkVector4f *dir,
        unsigned int color,
        int id,
        int tag)
{
  __m128 m_quad; // xmm12
  __m128 v9; // xmm11
  __m128 v10; // xmm9
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm7
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm7
  __m128 v22; // xmm4
  __m128 v23; // xmm4
  int v24; // edi
  int v25; // ebx
  hkDebugDisplayHandlerVtbl *vfptr; // rax
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm7
  __m128 v30; // xmm1
  __m128 v31; // xmm10
  __m128 v32; // xmm2
  __m128 v33; // [rsp+40h] [rbp-C8h] BYREF
  __m128 v34; // [rsp+50h] [rbp-B8h] BYREF
  __m128 v35; // [rsp+60h] [rbp-A8h] BYREF
  __m128 v36; // [rsp+70h] [rbp-98h] BYREF
  __m128 v37[3]; // [rsp+80h] [rbp-88h] BYREF
  unsigned int v38; // [rsp+120h] [rbp+18h] BYREF

  m_quad = dir->m_quad;
  v9 = _mm_mul_ps(m_quad, m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
             + _mm_shuffle_ps(v9, v9, 170).m128_f32[0]) >= 0.00000011920929 )
  {
    v10 = from->m_quad;
    v11 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 196);
    v12 = _mm_shuffle_ps(v11, v11, 241);
    v13 = _mm_shuffle_ps(v11, v11, 206);
    v33 = _mm_add_ps(from->m_quad, m_quad);
    v14 = _mm_mul_ps(v12, v12);
    v15 = _mm_mul_ps(v13, v13);
    v16 = _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170)));
    v17 = _mm_xor_ps(
            _mm_or_ps(_mm_andnot_ps(v16, v12), _mm_and_ps(v13, v16)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v18 = _mm_mul_ps(v17, v17);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v20 = _mm_rsqrt_ps(v19);
    v21 = _mm_mul_ps(
            v17,
            _mm_andnot_ps(
              _mm_cmple_ps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))));
    v22 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), m_quad),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v21));
    v23 = _mm_shuffle_ps(v22, v22, 201);
    v24 = tag;
    v25 = id;
    vfptr = this->vfptr;
    v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v28 = _mm_rsqrt_ps(v27);
    v29 = _mm_mul_ps(
            v21,
            _mm_andnot_ps(
              _mm_cmple_ps(v27, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                  _mm_mul_ps(*(__m128 *)_xmm, v28)),
                v27)));
    v38 = LODWORD(FLOAT_0_14999998);
    v30 = _mm_shuffle_ps((__m128)v38, (__m128)v38, 0);
    v31 = _mm_sub_ps((__m128)0i64, v30);
    v32 = _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_85000002), (__m128)LODWORD(FLOAT_0_85000002), 0),
              _mm_sub_ps(v33, v10)),
            v10);
    v34 = _mm_add_ps(_mm_mul_ps(v30, v29), v32);
    v36 = _mm_add_ps(_mm_mul_ps(v30, v23), v32);
    v37[0] = _mm_add_ps(_mm_mul_ps(v31, v23), v32);
    v35 = _mm_add_ps(_mm_mul_ps(v31, v29), v32);
    vfptr->displayLine(this, (hkResult *)&v38, from, (hkVector4f *)&v33, color, id, tag);
    this->vfptr->displayLine(this, (hkResult *)&v38, (hkVector4f *)&v33, (hkVector4f *)&v34, color, v25, v24);
    this->vfptr->displayLine(this, (hkResult *)&v38, (hkVector4f *)&v33, (hkVector4f *)&v35, color, v25, v24);
    this->vfptr->displayLine(this, (hkResult *)&v38, (hkVector4f *)&v33, (hkVector4f *)&v36, color, v25, v24);
    this->vfptr->displayLine(this, (hkResult *)&v38, (hkVector4f *)&v33, (hkVector4f *)v37, color, v25, v24);
  }
}

// File Line: 111
// RVA: 0xE6D7F0
void __fastcall hkDebugDisplayHandler::displayStar(
        hkDebugDisplayHandler *this,
        hkVector4f *position,
        float scale,
        unsigned int color,
        int id,
        int tag)
{
  __int64 i; // rbx
  __m128 m_quad; // xmm3
  hkDebugDisplayHandlerVtbl *vfptr; // rax
  char v12; // [rsp+40h] [rbp-78h] BYREF
  __m128 v13; // [rsp+50h] [rbp-68h]
  __m128 v14; // [rsp+60h] [rbp-58h] BYREF
  __m128 v15; // [rsp+70h] [rbp-48h] BYREF

  for ( i = 0i64; i < 3; ++i )
  {
    m_quad = position->m_quad;
    vfptr = this->vfptr;
    v13 = 0i64;
    v13.m128_f32[i] = scale;
    v14 = _mm_sub_ps(m_quad, v13);
    v15 = _mm_add_ps(m_quad, v13);
    vfptr->displayLine(this, (hkResult *)&v12, (hkVector4f *)&v15, (hkVector4f *)&v14, color, id, tag);
  }
}

// File Line: 125
// RVA: 0xE6D8C0
void __fastcall hkDebugDisplayHandler::displayModelSpacePose(
        hkDebugDisplayHandler *this,
        __int16 numTransforms,
        const __int16 *parentIndices,
        hkQsTransformf *modelSpacePose,
        hkQsTransformf *worldFromModel,
        unsigned int color,
        int id,
        int tag)
{
  hkDebugDisplayHandler *v8; // rdi
  __int64 v10; // rbx
  hkQsTransformf *v11; // r14
  __m128 v12; // xmm7
  __int16 v13; // ax
  __m128 m_quad; // xmm8
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  hkQuaternionf v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm5
  hkDebugDisplayHandlerVtbl *vfptr; // rax
  hkDebugDisplayHandlerVtbl *v27; // rax
  hkDebugDisplayHandlerVtbl *v28; // rax
  int v29; // eax
  hkVector4f v30; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f v31; // [rsp+50h] [rbp-B0h] BYREF
  int v32; // [rsp+60h] [rbp-A0h]
  hkVector4f direction; // [rsp+70h] [rbp-90h] BYREF
  hkResult v34; // [rsp+80h] [rbp-80h] BYREF
  hkResult v35; // [rsp+84h] [rbp-7Ch] BYREF
  char v36; // [rsp+88h] [rbp-78h] BYREF
  hkVector4f b; // [rsp+90h] [rbp-70h] BYREF
  char v38; // [rsp+A0h] [rbp-60h] BYREF
  hkQuaternionf quat; // [rsp+B0h] [rbp-50h] BYREF
  char v40; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f v41; // [rsp+D0h] [rbp-30h] BYREF
  int v42; // [rsp+198h] [rbp+98h]

  v8 = this;
  LOWORD(this) = 0;
  v42 = 0;
  v32 = numTransforms;
  if ( numTransforms > 0 )
  {
    do
    {
      v10 = (__int16)this;
      v11 = &modelSpacePose[(__int16)this];
      hkVector4f::setTransformedPos(&v30, worldFromModel, &v11->m_translation);
      v12 = (__m128)(unsigned int)FLOAT_1_0;
      v13 = parentIndices[v10];
      if ( v13 == -1 )
      {
        b.m_quad = 0i64;
        hkVector4f::setTransformedPos(&b, worldFromModel, &b);
        v8->vfptr->displayLine(v8, (hkResult *)&v36, &v30, &b, color, id, tag);
        m_quad = v30.m_quad;
      }
      else
      {
        hkVector4f::setTransformedPos(&v41, worldFromModel, &modelSpacePose[v13].m_translation);
        v8->vfptr->displayLine(v8, (hkResult *)&v40, &v30, &v41, color, id, tag);
        m_quad = v30.m_quad;
        v15 = _mm_sub_ps(v30.m_quad, v41.m_quad);
        v16 = _mm_mul_ps(v15, v15);
        v17 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                _mm_shuffle_ps(v16, v16, 170));
        v18 = _mm_rsqrt_ps(v17);
        v12 = _mm_andnot_ps(
                _mm_cmple_ps(v17, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                    _mm_mul_ps(*(__m128 *)_xmm, v18)),
                  v17));
        if ( v12.m128_f32[0] <= 10.0 )
        {
          if ( v12.m128_f32[0] < 0.1 )
            v12 = (__m128)LODWORD(FLOAT_0_1);
        }
        else
        {
          v12 = (__m128)LODWORD(FLOAT_10_0);
        }
      }
      v19 = v11->m_rotation.m_vec.m_quad;
      v20.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
      v12.m128_f32[0] = v12.m128_f32[0] * 0.25;
      v21 = _mm_shuffle_ps(v19, v19, 255);
      v22 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v20.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v20.m_vec.m_quad, v20.m_vec.m_quad, 201), v19));
      v23 = _mm_mul_ps(v20.m_vec.m_quad, v19);
      v24 = _mm_shuffle_ps(worldFromModel->m_rotation.m_vec.m_quad, worldFromModel->m_rotation.m_vec.m_quad, 255);
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 201), _mm_mul_ps(v24, v19)),
              _mm_mul_ps(worldFromModel->m_rotation.m_vec.m_quad, v21));
      quat.m_vec.m_quad = _mm_shuffle_ps(
                            v25,
                            _mm_unpackhi_ps(
                              v25,
                              _mm_sub_ps(
                                _mm_mul_ps(v21, v24),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                                  _mm_shuffle_ps(v23, v23, 170)))),
                            196);
      direction.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v12, (__m128)0i64), (__m128)0i64);
      hkVector4f::setRotatedDir(&v31, &quat, &direction);
      vfptr = v8->vfptr;
      v31.m_quad = _mm_add_ps(v31.m_quad, v30.m_quad);
      vfptr->displayLine(v8, (hkResult *)&v38, &v30, &v31, 2147418112u, id, tag);
      v30.m_quad = m_quad;
      direction.m_quad = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(v12, (__m128)0i64));
      hkVector4f::setRotatedDir(&v31, &quat, &direction);
      v27 = v8->vfptr;
      v31.m_quad = _mm_add_ps(v31.m_quad, v30.m_quad);
      v27->displayLine(v8, &v35, &v30, &v31, 2130771712u, id, tag);
      v30.m_quad = m_quad;
      direction.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v12), (__m128)0i64);
      hkVector4f::setRotatedDir(&v31, &quat, &direction);
      v28 = v8->vfptr;
      v31.m_quad = _mm_add_ps(v31.m_quad, v30.m_quad);
      v28->displayLine(v8, &v34, &v30, &v31, 2130706687u, id, tag);
      WORD1(this) = HIWORD(v42);
      LOWORD(this) = v42 + 1;
      v29 = (__int16)(v42 + 1);
      v42 = (int)this;
    }
    while ( v29 < v32 );
  }
}

// File Line: 189
// RVA: 0xE6DCF0
void __fastcall hkDebugDisplayHandler::displayLocalSpacePose(
        hkDebugDisplayHandler *this,
        int numTransforms,
        const __int16 *parentIndices,
        hkQsTransformf *localSpacePose,
        hkQsTransformf *worldFromModel,
        unsigned int color,
        int id,
        int tag)
{
  __int64 v11; // r14
  hkLifoAllocator *Value; // rax
  hkQsTransformf *m_cur; // rbx
  int v14; // edi
  char *v15; // rcx
  __int64 v16; // rdx
  hkQuaternionf *p_m_rotation; // r9
  signed __int64 v18; // r8
  __int64 v19; // rax
  hkQsTransformf *v20; // rax
  __m128 m_quad; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm6
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm6
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  __m128 v33; // xmm6
  __m128 v34; // xmm3
  __m128 v35; // xmm3
  hkLifoAllocator *v36; // rax
  int v37; // r8d

  v11 = numTransforms;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkQsTransformf *)Value->m_cur;
  v14 = (48 * v11 + 127) & 0xFFFFFF80;
  v15 = (char *)m_cur + v14;
  if ( v14 > Value->m_slabSize || v15 > Value->m_end )
    m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v14);
  else
    Value->m_cur = v15;
  v16 = 0i64;
  if ( (int)v11 > 0 )
  {
    p_m_rotation = &localSpacePose->m_rotation;
    v18 = (char *)m_cur - (char *)localSpacePose;
    do
    {
      v19 = parentIndices[v16];
      if ( (_DWORD)v19 == -1 )
        v20 = &hkQsTransformf_identityStorage;
      else
        v20 = &m_cur[v19];
      m_quad = v20->m_rotation.m_vec.m_quad;
      v22 = p_m_rotation[-1].m_vec.m_quad;
      ++v16;
      p_m_rotation += 3;
      v23 = _mm_mul_ps(m_quad, v22);
      v24 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v22));
      v25 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)),
                  m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v22)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v18) = _mm_add_ps(
                                                                    _mm_add_ps(v26, v26),
                                                                    v20->m_translation.m_quad);
      v27 = p_m_rotation[-3].m_vec.m_quad;
      v28 = v20->m_rotation.m_vec.m_quad;
      v29 = _mm_shuffle_ps(v28, v28, 255);
      v30 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v27);
      v31 = _mm_shuffle_ps(v27, v27, 255);
      v32 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v28);
      v33 = _mm_mul_ps(v28, v27);
      v34 = _mm_sub_ps(v32, v30);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 201), _mm_mul_ps(v27, v29)),
              _mm_mul_ps(v20->m_rotation.m_vec.m_quad, v31));
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v18) = _mm_shuffle_ps(
                                                                    v35,
                                                                    _mm_unpackhi_ps(
                                                                      v35,
                                                                      _mm_sub_ps(
                                                                        _mm_mul_ps(v31, v29),
                                                                        _mm_add_ps(
                                                                          _mm_add_ps(
                                                                            _mm_shuffle_ps(v33, v33, 85),
                                                                            _mm_shuffle_ps(v33, v33, 0)),
                                                                          _mm_shuffle_ps(v33, v33, 170)))),
                                                                    196);
      *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v18) = _mm_mul_ps(
                                                                    p_m_rotation[-2].m_vec.m_quad,
                                                                    v20->m_scale.m_quad);
    }
    while ( v16 < v11 );
  }
  hkDebugDisplayHandler::displayModelSpacePose(this, v11, parentIndices, m_cur, worldFromModel, color, id, tag);
  v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v37 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v36->m_slabSize || (char *)m_cur + v37 != v36->m_cur || v36->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v36, (char *)m_cur, v37);
  else
    v36->m_cur = m_cur;
}

// File Line: 206
// RVA: 0xE6DF50
hkResult *__fastcall hkDebugDisplayHandler::addGeometryLazily(
        hkDebugDisplayHandler *this,
        hkResult *result,
        hkReferencedObject *source,
        hkDisplayGeometryBuilder *builder,
        hkTransformf *transform,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  hkBaseObjectVtbl *vfptr; // rax
  int v11; // edx
  int v12; // edi
  __int64 i; // rbx
  hkReferencedObject *v14; // rcx
  hkResultEnum *v15; // rax
  hkReferencedObject **objects; // [rsp+40h] [rbp-C0h] BYREF
  int numObjects; // [rsp+48h] [rbp-B8h]
  int v19; // [rsp+4Ch] [rbp-B4h]
  char v20; // [rsp+50h] [rbp-B0h] BYREF
  hkErrStream v21; // [rsp+90h] [rbp-70h] BYREF
  char buf[512]; // [rsp+B0h] [rbp-50h] BYREF
  char v23; // [rsp+2D8h] [rbp+1D8h] BYREF

  objects = (hkReferencedObject **)&v20;
  vfptr = builder->vfptr;
  numObjects = 0;
  v19 = -2147483640;
  ((void (__fastcall *)(hkDisplayGeometryBuilder *, hkReferencedObject *, hkReferencedObject ***))vfptr[1].__first_virtual_table_function__)(
    builder,
    source,
    &objects);
  v11 = numObjects;
  v12 = numObjects - 1;
  for ( i = numObjects - 1; i >= 0; --i )
  {
    v14 = objects[i];
    if ( LODWORD(v14[6].vfptr) == 6 && !v14[1].vfptr )
    {
      hkErrStream::hkErrStream(&v21, buf, 512);
      hkOstream::operator<<(&v21, "Unable to build display geometry from source");
      hkError::messageReport(0xFFFFFFFF, buf, "hkDebugDisplayHandler.cpp", 216);
      hkOstream::~hkOstream(&v21);
      hkReferencedObject::removeReference(objects[i]);
      v11 = numObjects - 1;
      numObjects = v11;
      if ( v11 != v12 )
      {
        objects[i] = objects[v11];
        v11 = numObjects;
      }
    }
    --v12;
  }
  result->m_enum = HK_FAILURE;
  if ( v11 > 0 )
  {
    v15 = (hkResultEnum *)(*(__int64 (__fastcall **)(hkDebugDisplayHandler *, char *, hkReferencedObject ***, hkTransformf *, unsigned __int64, int, unsigned __int64, _DWORD))this->vfptr->gap8)(
                            this,
                            &v23,
                            &objects,
                            transform,
                            id,
                            tag,
                            shapeIdHint,
                            0);
    v11 = numObjects;
    result->m_enum = *v15;
  }
  hkReferencedObject::removeReferences(objects, v11, 8);
  numObjects = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, objects, 8 * v19);
  return result;
}

// File Line: 235
// RVA: 0xE6E120
hkResult *__fastcall hkDebugDisplayHandler::addGeometryHash(
        hkDebugDisplayHandler *this,
        hkResult *result,
        hkReferencedObject *source,
        hkDisplayGeometryBuilder *builder,
        const unsigned __int64 *hash,
        unsigned __int64 id,
        int tag)
{
  hkDebugDisplayHandlerVtbl *vfptr; // r10
  __int128 v10[2]; // [rsp+50h] [rbp-28h] BYREF

  vfptr = this->vfptr;
  v10[0] = xmmword_141A712A0;
  v10[1] = (__int128)_mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       (__m128)xmmword_141A712A0);
  vfptr->addGeometryHash(this, result, source, builder, hash, (hkAabb *)v10, 0, (hkTransformf *)&transform, id, tag);
  return result;
}

