// File Line: 19
// RVA: 0xE6D010
hkResult *__fastcall hkDebugDisplayHandler::addGeometry(hkDebugDisplayHandler *this, hkResult *result, hkDisplayGeometry *geometry, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint)
{
  hkDebugDisplayHandlerVtbl *v6; // r10
  int v7; // ST38_4
  hkResult *v8; // rbx
  int v9; // ST28_4
  hkDisplayGeometry **v11; // [rsp+40h] [rbp-28h]
  int v12; // [rsp+48h] [rbp-20h]
  int v13; // [rsp+4Ch] [rbp-1Ch]
  hkDisplayGeometry *v14; // [rsp+50h] [rbp-18h]

  v6 = this->vfptr;
  v7 = 0;
  v14 = geometry;
  v11 = &v14;
  v8 = result;
  v9 = tag;
  v13 = -2147483647;
  v12 = 1;
  (*(void (__fastcall **)(hkDebugDisplayHandler *, hkResult *, hkDisplayGeometry ***, hkTransformf *, unsigned __int64, int, unsigned __int64, int))v6->gap8)(
    this,
    result,
    &v11,
    &geometry->m_transform,
    id,
    v9,
    shapeIdHint,
    v7);
  v12 = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v11,
      8 * v13);
  return v8;
}

// File Line: 26
// RVA: 0xE6D0C0
hkResult *__fastcall hkDebugDisplayHandler::updateGeometry(hkDebugDisplayHandler *this, hkResult *result, hkQsTransformf *transform, unsigned __int64 id, int tag)
{
  hkDebugDisplayHandler *v5; // rdi
  hkResult *v6; // rsi
  unsigned __int64 v7; // rbx
  int v8; // ST20_4
  hkMatrix4f v10; // [rsp+30h] [rbp-48h]

  v5 = this;
  v6 = result;
  v7 = id;
  hkMatrix4f::set(&v10, transform);
  v8 = tag;
  v5->vfptr->updateGeometry(v5, v6, &v10, v7, v8);
  return v6;
}

// File Line: 34
// RVA: 0xE6D120
hkResult *__fastcall hkDebugDisplayHandler::skinGeometry(hkDebugDisplayHandler *this, hkResult *result, unsigned __int64 *ids, int numIds, hkQsTransformf *poseModel, int numPoseModel, hkQsTransformf *worldFromModel, int tag)
{
  hkDebugDisplayHandler *v8; // r13
  hkResult *v9; // r12
  hkLifoAllocator *v10; // rax
  hkMatrix4f *v11; // rbp
  int v12; // er14
  char *v13; // rcx
  hkQsTransformf *v14; // rdi
  hkMatrix4f *v15; // rbx
  __int64 v16; // rsi
  hkLifoAllocator *v17; // rax
  int v18; // er8
  hkResult *v19; // rax
  hkMatrix4f v20; // [rsp+40h] [rbp-78h]
  unsigned __int64 *v21; // [rsp+D0h] [rbp+18h]
  unsigned int v22; // [rsp+D8h] [rbp+20h]

  v22 = numIds;
  v21 = ids;
  v8 = this;
  v9 = result;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkMatrix4f *)v10->m_cur;
  v12 = ((numPoseModel << 6) + 127) & 0xFFFFFF80;
  v13 = (char *)v11 + v12;
  if ( v12 > v10->m_slabSize || v13 > v10->m_end )
    v11 = (hkMatrix4f *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
  else
    v10->m_cur = v13;
  if ( numPoseModel > 0 )
  {
    v14 = poseModel;
    v15 = v11;
    v16 = (unsigned int)numPoseModel;
    do
    {
      hkMatrix4f::set(v15, v14);
      ++v14;
      ++v15;
      --v16;
    }
    while ( v16 );
  }
  hkMatrix4f::set(&v20, worldFromModel);
  v8->vfptr->skinGeometry(v8, v9, v21, v22, v11, numPoseModel, &v20, tag);
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v17->m_slabSize || (char *)v11 + v18 != v17->m_cur || v17->m_firstNonLifoEnd == v11 )
  {
    hkLifoAllocator::slowBlockFree(v17, v11, v18);
    v19 = v9;
  }
  else
  {
    v17->m_cur = v11;
    v19 = v9;
  }
  return v19;
}

// File Line: 49
// RVA: 0xE6D2C0
int hkDebugDisplayHandler::displayFrame(...)
{
  hkDebugDisplayHandler *v4; // rsi
  int v5; // edi
  hkQsTransformf *v6; // rbx
  hkVector4f b; // [rsp+28h] [rbp-41h]
  hkVector4f from; // [rsp+38h] [rbp-31h]
  hkVector4f v9; // [rsp+48h] [rbp-21h]
  hkVector4f v10; // [rsp+58h] [rbp-11h]
  hkVector4f v11; // [rsp+68h] [rbp-1h]
  hkVector4f dir; // [rsp+78h] [rbp+Fh]
  hkVector4f v13; // [rsp+88h] [rbp+1Fh]
  hkVector4f v14; // [rsp+98h] [rbp+2Fh]
  int v15; // [rsp+E8h] [rbp+7Fh]

  v4 = this;
  v5 = id;
  b.m_quad = 0i64;
  v6 = worldFromLocal;
  hkVector4f::setTransformedPos((hkVector4f *)((char *)&from + 8), worldFromLocal, (hkVector4f *)((char *)&b + 8));
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)size, (__m128)0i64), (__m128)0i64);
  hkVector4f::setTransformedPos(&v9, v6, &b);
  b.m_quad = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps((__m128)size, (__m128)0i64));
  hkVector4f::setTransformedPos(&v10, v6, &b);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, (__m128)size), (__m128)0i64);
  hkVector4f::setTransformedPos(&v11, v6, &b);
  dir.m_quad = _mm_sub_ps(v9.m_quad, from.m_quad);
  v14.m_quad = _mm_sub_ps(v11.m_quad, from.m_quad);
  v13.m_quad = _mm_sub_ps(v10.m_quad, from.m_quad);
  hkDebugDisplayHandler::displayArrow(v4, &from, &dir, hkColor::RED, v5, v15);
  hkDebugDisplayHandler::displayArrow(v4, &from, &v13, hkColor::GREEN, v5, v15);
  hkDebugDisplayHandler::displayArrow(v4, &from, &v14, hkColor::BLUE, v5, v15);
}

// File Line: 74
// RVA: 0xE6D420
void __fastcall hkDebugDisplayHandler::displayFrame(hkDebugDisplayHandler *this, hkTransformf *worldFromLocal, float size, int id, int tag)
{
  hkDebugDisplayHandler *v5; // rdi
  int v6; // ebx
  hkQsTransformf worldFromLocala; // [rsp+30h] [rbp-48h]

  v5 = this;
  v6 = id;
  hkQsTransformf::setFromTransform(&worldFromLocala, worldFromLocal);
  hkDebugDisplayHandler::displayFrame(v5, &worldFromLocala, size, v6, tag);
}

// File Line: 81
// RVA: 0xE6D480
void __fastcall hkDebugDisplayHandler::displayArrow(hkDebugDisplayHandler *this, hkVector4f *from, hkVector4f *dir, unsigned int color, int id, int tag)
{
  __m128 v6; // xmm12
  unsigned int v7; // ebp
  hkDebugDisplayHandler *v8; // rsi
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
  hkDebugDisplayHandlerVtbl *v26; // rax
  int v27; // ST30_4
  int v28; // ST28_4
  __m128 v29; // xmm3
  unsigned int v30; // ST20_4
  __m128 v31; // xmm1
  __m128 v32; // xmm7
  __m128 v33; // xmm1
  __m128 v34; // xmm10
  __m128 v35; // xmm2
  __int64 v36; // ST30_8
  __int64 v37; // ST28_8
  __int64 v38; // ST20_8
  __int64 v39; // ST30_8
  __int64 v40; // ST28_8
  __int64 v41; // ST20_8
  __int64 v42; // ST30_8
  __int64 v43; // ST28_8
  __int64 v44; // ST20_8
  __int64 v45; // ST30_8
  __int64 v46; // ST28_8
  __int64 v47; // ST20_8
  __m128 v48; // [rsp+40h] [rbp-C8h]
  __m128 v49; // [rsp+50h] [rbp-B8h]
  __m128 v50; // [rsp+60h] [rbp-A8h]
  __m128 v51; // [rsp+70h] [rbp-98h]
  __m128 v52; // [rsp+80h] [rbp-88h]
  unsigned int v53; // [rsp+120h] [rbp+18h]

  v6 = dir->m_quad;
  v7 = color;
  v8 = this;
  v9 = _mm_mul_ps(v6, v6);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170))) >= 0.00000011920929 )
  {
    v10 = from->m_quad;
    v11 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, (__m128)0i64), 196);
    v12 = _mm_shuffle_ps(v11, v11, 241);
    v13 = _mm_shuffle_ps(v11, v11, 206);
    v48 = _mm_add_ps(from->m_quad, v6);
    v14 = _mm_mul_ps(v12, v12);
    v15 = _mm_mul_ps(v13, v13);
    v16 = _mm_cmpltps(
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
              _mm_cmpleps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))));
    v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v21));
    v23 = _mm_shuffle_ps(v22, v22, 201);
    v24 = tag;
    v25 = id;
    v26 = this->vfptr;
    v27 = tag;
    v28 = id;
    v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v30 = color;
    v31 = _mm_rsqrt_ps(v29);
    v32 = _mm_mul_ps(
            v21,
            _mm_andnot_ps(
              _mm_cmpleps(v29, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v29), v31)),
                  _mm_mul_ps(*(__m128 *)_xmm, v31)),
                v29)));
    v53 = LODWORD(FLOAT_0_14999998);
    v33 = _mm_shuffle_ps((__m128)v53, (__m128)v53, 0);
    v34 = _mm_sub_ps((__m128)0i64, v33);
    v35 = _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_85000002), (__m128)LODWORD(FLOAT_0_85000002), 0),
              _mm_sub_ps(v48, v10)),
            v10);
    v49 = _mm_add_ps(_mm_mul_ps(v33, v32), v35);
    v51 = _mm_add_ps(_mm_mul_ps(v33, v23), v35);
    v52 = _mm_add_ps(_mm_mul_ps(v34, v23), v35);
    v50 = _mm_add_ps(_mm_mul_ps(v34, v32), v35);
    v26->displayLine(this, (hkResult *)&v53, from, (hkVector4f *)&v48, v30, v28, v27);
    LODWORD(v36) = v24;
    LODWORD(v37) = v25;
    LODWORD(v38) = v7;
    v8->vfptr->displayLine(v8, (hkResult *)&v53, (hkVector4f *)&v48, (hkVector4f *)&v49, v38, v37, v36);
    LODWORD(v39) = v24;
    LODWORD(v40) = v25;
    LODWORD(v41) = v7;
    v8->vfptr->displayLine(v8, (hkResult *)&v53, (hkVector4f *)&v48, (hkVector4f *)&v50, v41, v40, v39);
    LODWORD(v42) = v24;
    LODWORD(v43) = v25;
    LODWORD(v44) = v7;
    v8->vfptr->displayLine(v8, (hkResult *)&v53, (hkVector4f *)&v48, (hkVector4f *)&v51, v44, v43, v42);
    LODWORD(v45) = v24;
    LODWORD(v46) = v25;
    LODWORD(v47) = v7;
    v8->vfptr->displayLine(v8, (hkResult *)&v53, (hkVector4f *)&v48, (hkVector4f *)&v52, v47, v46, v45);
  }
}

// File Line: 111
// RVA: 0xE6D7F0
void __fastcall hkDebugDisplayHandler::displayStar(hkDebugDisplayHandler *this, hkVector4f *position, float scale, unsigned int color, int id, int tag)
{
  unsigned int v6; // esi
  hkVector4f *v7; // rbp
  hkDebugDisplayHandler *v8; // rdi
  signed __int64 v9; // rbx
  __m128 v10; // xmm3
  hkDebugDisplayHandlerVtbl *v11; // rax
  __int64 v12; // [rsp+20h] [rbp-98h]
  __int64 v13; // [rsp+28h] [rbp-90h]
  __int64 v14[2]; // [rsp+30h] [rbp-88h]
  char v15; // [rsp+40h] [rbp-78h]
  __m128 v16; // [rsp+50h] [rbp-68h]
  __m128 v17; // [rsp+60h] [rbp-58h]
  __m128 v18; // [rsp+70h] [rbp-48h]

  v6 = color;
  v7 = position;
  v8 = this;
  v9 = 0i64;
  do
  {
    v10 = v7->m_quad;
    v11 = v8->vfptr;
    v16 = 0i64;
    v16.m128_f32[v9] = scale;
    LODWORD(v14[0]) = tag;
    LODWORD(v13) = id;
    LODWORD(v12) = v6;
    v17 = _mm_sub_ps(v10, v16);
    v18 = _mm_add_ps(v10, v16);
    v11->displayLine(v8, (hkResult *)&v15, (hkVector4f *)&v18, (hkVector4f *)&v17, v12, v13, v14[0]);
    ++v9;
  }
  while ( v9 < 3 );
}

// File Line: 125
// RVA: 0xE6D8C0
void __fastcall hkDebugDisplayHandler::displayModelSpacePose(hkDebugDisplayHandler *this, int numTransforms, const __int16 *parentIndices, hkQsTransformf *modelSpacePose, hkQsTransformf *worldFromModel, unsigned int color, int id, int tag)
{
  hkDebugDisplayHandler *v8; // rdi
  hkQsTransformf *v9; // r13
  __int64 v10; // rbx
  __m128 *v11; // r14
  __m128 v12; // xmm7
  __int16 v13; // ax
  __m128 v14; // xmm8
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
  hkDebugDisplayHandlerVtbl *v26; // rax
  hkDebugDisplayHandlerVtbl *v27; // rax
  __int64 v28; // ST30_8
  __int64 v29; // ST28_8
  __int64 v30; // ST20_8
  hkDebugDisplayHandlerVtbl *v31; // rax
  __int64 v32; // ST30_8
  __int64 v33; // ST28_8
  __int64 v34; // ST20_8
  int v35; // eax
  __int64 v36; // [rsp+20h] [rbp-E0h]
  __int64 v37; // [rsp+20h] [rbp-E0h]
  __int64 v38; // [rsp+28h] [rbp-D8h]
  __int64 v39; // [rsp+28h] [rbp-D8h]
  __int64 v40[2]; // [rsp+30h] [rbp-D0h]
  __int64 v41; // [rsp+30h] [rbp-D0h]
  hkVector4f v42; // [rsp+40h] [rbp-C0h]
  hkVector4f v43; // [rsp+50h] [rbp-B0h]
  int v44; // [rsp+60h] [rbp-A0h]
  hkVector4f direction; // [rsp+70h] [rbp-90h]
  char v46; // [rsp+80h] [rbp-80h]
  char v47; // [rsp+84h] [rbp-7Ch]
  char v48; // [rsp+88h] [rbp-78h]
  hkVector4f b; // [rsp+90h] [rbp-70h]
  char v50; // [rsp+A0h] [rbp-60h]
  hkQuaternionf quat; // [rsp+B0h] [rbp-50h]
  char v52; // [rsp+C0h] [rbp-40h]
  hkVector4f v53; // [rsp+D0h] [rbp-30h]
  int v54; // [rsp+198h] [rbp+98h]
  const __int16 *v55; // [rsp+1A0h] [rbp+A0h]

  v55 = parentIndices;
  v8 = this;
  LOWORD(this) = 0;
  v54 = 0;
  v9 = modelSpacePose;
  v44 = (signed __int16)numTransforms;
  if ( (signed __int16)numTransforms > 0 )
  {
    do
    {
      v10 = (signed __int16)this;
      v11 = &v9[(signed __int16)this].m_translation.m_quad;
      hkVector4f::setTransformedPos(&v42, worldFromModel, &v9[(signed __int16)this].m_translation);
      v12 = (__m128)(unsigned int)FLOAT_1_0;
      v13 = v55[v10];
      if ( v13 == -1 )
      {
        b.m_quad = 0i64;
        hkVector4f::setTransformedPos(&b, worldFromModel, &b);
        LODWORD(v40[0]) = tag;
        LODWORD(v38) = id;
        LODWORD(v36) = color;
        v8->vfptr->displayLine(v8, (hkResult *)&v48, &v42, &b, v36, v38, v40[0]);
        v14 = v42.m_quad;
      }
      else
      {
        hkVector4f::setTransformedPos(&v53, worldFromModel, &v9[v13].m_translation);
        LODWORD(v40[0]) = tag;
        LODWORD(v38) = id;
        LODWORD(v36) = color;
        v8->vfptr->displayLine(v8, (hkResult *)&v52, &v42, &v53, v36, v38, v40[0]);
        v14 = v42.m_quad;
        v15 = _mm_sub_ps(v42.m_quad, v53.m_quad);
        v16 = _mm_mul_ps(v15, v15);
        v17 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                _mm_shuffle_ps(v16, v16, 170));
        v18 = _mm_rsqrt_ps(v17);
        v12 = _mm_andnot_ps(
                _mm_cmpleps(v17, (__m128)0i64),
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
      v19 = v11[1];
      v20.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
      v12.m128_f32[0] = v12.m128_f32[0] * 0.25;
      v21 = _mm_shuffle_ps(v11[1], v11[1], 255);
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
      hkVector4f::setRotatedDir(&v43, &quat, &direction);
      v26 = v8->vfptr;
      LODWORD(v41) = tag;
      v43.m_quad = _mm_add_ps(v43.m_quad, v42.m_quad);
      LODWORD(v39) = id;
      LODWORD(v37) = 2147418112;
      v26->displayLine(v8, (hkResult *)&v50, &v42, &v43, v37, v39, v41);
      v42.m_quad = v14;
      direction.m_quad = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(v12, (__m128)0i64));
      hkVector4f::setRotatedDir(&v43, &quat, &direction);
      v27 = v8->vfptr;
      LODWORD(v28) = tag;
      LODWORD(v29) = id;
      v43.m_quad = _mm_add_ps(v43.m_quad, v42.m_quad);
      LODWORD(v30) = 2130771712;
      v27->displayLine(v8, (hkResult *)&v47, &v42, &v43, v30, v29, v28);
      v42.m_quad = v14;
      direction.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v12), (__m128)0i64);
      hkVector4f::setRotatedDir(&v43, &quat, &direction);
      v31 = v8->vfptr;
      LODWORD(v32) = tag;
      v43.m_quad = _mm_add_ps(v43.m_quad, v42.m_quad);
      LODWORD(v33) = id;
      LODWORD(v34) = 2130706687;
      v31->displayLine(v8, (hkResult *)&v46, &v42, &v43, v34, v33, v32);
      WORD1(this) = HIWORD(v54);
      LOWORD(this) = v54 + 1;
      v35 = (signed __int16)(v54 + 1);
      v54 = (signed int)this;
    }
    while ( v35 < v44 );
  }
}

// File Line: 189
// RVA: 0xE6DCF0
void __fastcall hkDebugDisplayHandler::displayLocalSpacePose(hkDebugDisplayHandler *this, int numTransforms, const __int16 *parentIndices, hkQsTransformf *localSpacePose, hkQsTransformf *worldFromModel, unsigned int color, int id, int tag)
{
  hkDebugDisplayHandler *v8; // r15
  hkQsTransformf *v9; // rbp
  const __int16 *v10; // rsi
  __int64 v11; // r14
  hkLifoAllocator *v12; // rax
  hkQsTransformf *v13; // rbx
  int v14; // edi
  char *v15; // rcx
  __int64 v16; // rdx
  signed __int64 v17; // r9
  signed __int64 v18; // r8
  __int64 v19; // rax
  hkQsTransformf *v20; // rax
  __m128 v21; // xmm2
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
  int v37; // er8

  v8 = this;
  v9 = localSpacePose;
  v10 = parentIndices;
  v11 = numTransforms;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkQsTransformf *)v12->m_cur;
  v14 = (48 * v11 + 127) & 0xFFFFFF80;
  v15 = (char *)v13 + v14;
  if ( v14 > v12->m_slabSize || v15 > v12->m_end )
    v13 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
  else
    v12->m_cur = v15;
  v16 = 0i64;
  if ( (signed int)v11 > 0 )
  {
    v17 = (signed __int64)&v9->m_rotation;
    v18 = (char *)v13 - (char *)v9;
    do
    {
      v19 = v10[v16];
      if ( (_DWORD)v19 == -1 )
        v20 = &hkQsTransformf_identityStorage;
      else
        v20 = &v13[v19];
      v21 = v20->m_rotation.m_vec.m_quad;
      v22 = *(__m128 *)(v17 - 16);
      ++v16;
      v17 += 48i64;
      v23 = _mm_mul_ps(v20->m_rotation.m_vec.m_quad, v22);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v21), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v22));
      v25 = _mm_shuffle_ps(v20->m_rotation.m_vec.m_quad, v21, 255);
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)),
                  v21),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v22)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
      *(__m128 *)(v18 + v17 - 64) = _mm_add_ps(_mm_add_ps(v26, v26), v20->m_translation.m_quad);
      v27 = *(__m128 *)(v17 - 48);
      v28 = v20->m_rotation.m_vec.m_quad;
      v29 = _mm_shuffle_ps(v20->m_rotation.m_vec.m_quad, v20->m_rotation.m_vec.m_quad, 255);
      v30 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v27);
      v31 = _mm_shuffle_ps(*(__m128 *)(v17 - 48), *(__m128 *)(v17 - 48), 255);
      v32 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v28);
      v33 = _mm_mul_ps(v28, v27);
      v34 = _mm_sub_ps(v32, v30);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 201), _mm_mul_ps(*(__m128 *)(v17 - 48), v29)),
              _mm_mul_ps(v20->m_rotation.m_vec.m_quad, v31));
      *(__m128 *)(v18 + v17 - 48) = _mm_shuffle_ps(
                                      v35,
                                      _mm_unpackhi_ps(
                                        v35,
                                        _mm_sub_ps(
                                          _mm_mul_ps(v31, v29),
                                          _mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                                            _mm_shuffle_ps(v33, v33, 170)))),
                                      196);
      *(__m128 *)(v18 + v17 - 32) = _mm_mul_ps(*(__m128 *)(v17 - 32), v20->m_scale.m_quad);
    }
    while ( v16 < v11 );
  }
  hkDebugDisplayHandler::displayModelSpacePose(v8, v11, v10, v13, worldFromModel, color, id, tag);
  v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v37 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v36->m_slabSize || (char *)v13 + v37 != v36->m_cur || v36->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v36, v13, v37);
  else
    v36->m_cur = v13;
}

// File Line: 206
// RVA: 0xE6DF50
hkResult *__fastcall hkDebugDisplayHandler::addGeometryLazily(hkDebugDisplayHandler *this, hkResult *result, hkReferencedObject *source, hkDisplayGeometryBuilder *builder, hkTransformf *transform, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint)
{
  hkResult *v8; // rsi
  hkBaseObjectVtbl *v9; // rax
  hkDebugDisplayHandler *v10; // r14
  int v11; // edx
  int v12; // edi
  __int64 i; // rbx
  hkReferencedObject *v14; // rcx
  int v15; // ST38_4
  int v16; // ST28_4
  hkResultEnum *v17; // rax
  hkReferencedObject **objects; // [rsp+40h] [rbp-C0h]
  int numObjects; // [rsp+48h] [rbp-B8h]
  int v21; // [rsp+4Ch] [rbp-B4h]
  char v22; // [rsp+50h] [rbp-B0h]
  hkErrStream v23; // [rsp+90h] [rbp-70h]
  char buf; // [rsp+B0h] [rbp-50h]
  char v25; // [rsp+2D8h] [rbp+1D8h]

  v8 = result;
  objects = (hkReferencedObject **)&v22;
  v9 = builder->vfptr;
  v10 = this;
  numObjects = 0;
  v21 = -2147483640;
  ((void (__fastcall *)(hkDisplayGeometryBuilder *, hkReferencedObject *, hkReferencedObject ***))v9[1].__first_virtual_table_function__)(
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
      hkErrStream::hkErrStream(&v23, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v23.vfptr, "Unable to build display geometry from source");
      hkError::messageReport(-1, &buf, "hkDebugDisplayHandler.cpp", 216);
      hkOstream::~hkOstream((hkOstream *)&v23.vfptr);
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
  v8->m_enum = 1;
  if ( v11 > 0 )
  {
    v15 = 0;
    v16 = tag;
    v17 = (hkResultEnum *)(*(__int64 (__fastcall **)(hkDebugDisplayHandler *, char *, hkReferencedObject ***, hkTransformf *, unsigned __int64, int, unsigned __int64, int))v10->vfptr->gap8)(
                            v10,
                            &v25,
                            &objects,
                            transform,
                            id,
                            v16,
                            shapeIdHint,
                            v15);
    v11 = numObjects;
    v8->m_enum = *v17;
  }
  hkReferencedObject::removeReferences(objects, v11, 8);
  numObjects = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      objects,
      8 * v21);
  return v8;
}

// File Line: 235
// RVA: 0xE6E120
hkResult *__fastcall hkDebugDisplayHandler::addGeometryHash(hkDebugDisplayHandler *this, hkResult *result, hkReferencedObject *source, hkDisplayGeometryBuilder *builder, const unsigned __int64 *hash, unsigned __int64 id, int tag)
{
  hkDebugDisplayHandlerVtbl *v7; // r10
  hkResult *v8; // rbx
  int v9; // ST48_4
  int v10; // ST30_4
  __int128 v12; // [rsp+50h] [rbp-28h]
  __m128 v13; // [rsp+60h] [rbp-18h]

  v7 = this->vfptr;
  v8 = result;
  v12 = xmmword_141A712A0;
  v9 = tag;
  v13 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  v10 = 0;
  ((void (__fastcall *)(hkDebugDisplayHandler *, hkResult *, hkReferencedObject *, hkDisplayGeometryBuilder *, const unsigned __int64 *, __int128 *, int, hkVector4f *, unsigned __int64, int, _QWORD, _QWORD, unsigned __int64, unsigned __int64))v7->addGeometryHash)(
    this,
    result,
    source,
    builder,
    hash,
    &v12,
    v10,
    &transform,
    id,
    v9,
    xmmword_141A712A0,
    *((_QWORD *)&xmmword_141A712A0 + 1),
    v13.m128_u64[0],
    v13.m128_u64[1]);
  return v8;
}

