// File Line: 16
// RVA: 0xB271F0
void __fastcall hkaInterleavedUncompressedAnimation::hkaInterleavedUncompressedAnimation(
        hkaInterleavedUncompressedAnimation *this,
        hkaAnimation *that)
{
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int v7; // r13d
  int v8; // ebx
  int v9; // ecx
  int v10; // r9d
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  int i; // ebx
  int m_numberOfFloatTracks; // eax
  float *v17; // r9
  __int64 v18; // rcx
  hkQsTransformf *m_data; // rax
  __m128 m_quad; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  hkResult result; // [rsp+90h] [rbp+8h] BYREF

  hkaAnimation::hkaAnimation(this, that);
  v4 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaInterleavedUncompressedAnimation::`vftable;
  this->m_transforms.m_data = 0i64;
  this->m_transforms.m_size = 0;
  this->m_transforms.m_capacityAndFlags = 0x80000000;
  this->m_floats.m_data = 0i64;
  this->m_floats.m_size = 0;
  this->m_floats.m_capacityAndFlags = 0x80000000;
  this->m_type.m_storage = 1;
  v5 = ((__int64 (__fastcall *)(hkaAnimation *))that->vfptr[4].__vecDelDtor)(that);
  v6 = this->m_transforms.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = v5;
  v8 = this->m_numberOfTransformTracks * v5;
  if ( v6 < v8 )
  {
    v9 = 2 * v6;
    v10 = this->m_numberOfTransformTracks * v5;
    if ( v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_transforms, v10, 48);
  }
  this->m_transforms.m_size = v8;
  v11 = v7 * this->m_numberOfFloatTracks;
  v12 = this->m_floats.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < v11 )
  {
    v13 = 2 * v12;
    v14 = v7 * this->m_numberOfFloatTracks;
    if ( v11 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_floats, v14, 4);
  }
  this->m_floats.m_size = v11;
  for ( i = 0; i < v7; ++i )
  {
    m_numberOfFloatTracks = this->m_numberOfFloatTracks;
    if ( m_numberOfFloatTracks )
      v17 = &this->m_floats.m_data[i * m_numberOfFloatTracks];
    else
      v17 = 0i64;
    ((void (__fastcall *)(hkaAnimation *, hkBaseObjectVtbl *, hkQsTransformf *, float *))that->vfptr[1].__first_virtual_table_function__)(
      that,
      that->vfptr,
      &this->m_transforms.m_data[this->m_numberOfTransformTracks * i],
      v17);
  }
  if ( this->m_transforms.m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      m_data = this->m_transforms.m_data;
      ++v4;
      m_quad = m_data[v18++].m_rotation.m_vec.m_quad;
      v21 = _mm_mul_ps(m_quad, m_quad);
      v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
      v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22);
      v24 = _mm_rsqrt_ps(v23);
      m_data[v18 - 1].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                                  m_quad,
                                                  _mm_mul_ps(
                                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                                                    _mm_mul_ps(*(__m128 *)_xmm, v24)));
    }
    while ( v4 < this->m_transforms.m_size );
  }
}

// File Line: 45
// RVA: 0xB27420
void __fastcall hkaInterleavedUncompressedAnimation::hkaInterleavedUncompressedAnimation(
        hkaInterleavedUncompressedAnimation *this,
        hkaInterleavedUncompressedAnimation *that)
{
  __int64 v4; // rsi
  int v5; // eax
  __int64 m_size; // rax
  hkQsTransformf *m_data; // r8
  __int64 v8; // rdx
  hkQuaternionf *p_m_rotation; // rax
  char *v10; // rcx
  hkQuaternionf v11; // xmm0
  __int64 v12; // rax
  float *v13; // r11
  float *v14; // r10
  __int64 v15; // rdx
  float *v16; // rcx
  signed __int64 v17; // r8
  unsigned __int64 v18; // r9
  int v19; // eax
  signed __int64 v20; // r10
  float *v21; // rcx
  __int64 v22; // rdx
  int v23; // eax
  int v24; // [rsp+30h] [rbp+8h] BYREF

  hkaAnimation::hkaAnimation(this, that);
  v4 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkaInterleavedUncompressedAnimation::`vftable;
  this->m_transforms.m_data = 0i64;
  this->m_transforms.m_size = 0;
  this->m_transforms.m_capacityAndFlags = 0x80000000;
  this->m_floats.m_data = 0i64;
  this->m_floats.m_size = 0;
  this->m_floats.m_capacityAndFlags = 0x80000000;
  v5 = this->m_transforms.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < that->m_transforms.m_size )
  {
    if ( this->m_transforms.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 48 * v5);
    v24 = 48 * that->m_transforms.m_size;
    this->m_transforms.m_data = (hkQsTransformf *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                    &hkContainerHeapAllocator::s_alloc,
                                                    &v24);
    this->m_transforms.m_capacityAndFlags = v24 / 48;
  }
  m_size = that->m_transforms.m_size;
  m_data = this->m_transforms.m_data;
  this->m_transforms.m_size = m_size;
  v8 = m_size;
  if ( (int)m_size > 0 )
  {
    p_m_rotation = &m_data->m_rotation;
    v10 = (char *)((char *)that->m_transforms.m_data - (char *)m_data);
    do
    {
      v11.m_vec.m_quad = *(__m128 *)((char *)&p_m_rotation[-1] + (_QWORD)v10);
      p_m_rotation += 3;
      p_m_rotation[-4] = (hkQuaternionf)v11.m_vec.m_quad;
      p_m_rotation[-3] = *(hkQuaternionf *)((char *)p_m_rotation + (_QWORD)v10 - 48);
      p_m_rotation[-2] = *(hkQuaternionf *)((char *)p_m_rotation + (_QWORD)v10 - 32);
      --v8;
    }
    while ( v8 );
  }
  if ( (this->m_floats.m_capacityAndFlags & 0x3FFFFFFF) < that->m_floats.m_size )
  {
    if ( this->m_floats.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_floats.m_data,
        4 * this->m_floats.m_capacityAndFlags);
    v24 = 4 * that->m_floats.m_size;
    this->m_floats.m_data = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerHeapAllocator::s_alloc,
                                       &v24);
    this->m_floats.m_capacityAndFlags = v24 / 4;
  }
  v12 = that->m_floats.m_size;
  v13 = this->m_floats.m_data;
  this->m_floats.m_size = v12;
  v14 = that->m_floats.m_data;
  v15 = v12;
  if ( v12 >= 4 )
  {
    v16 = v13 + 1;
    v17 = (char *)v14 - (char *)v13;
    v18 = ((unsigned __int64)(v12 - 4) >> 2) + 1;
    v4 = 4 * v18;
    do
    {
      v19 = *(_DWORD *)((char *)v16 + v17 - 4);
      v16 += 4;
      *((_DWORD *)v16 - 5) = v19;
      *(v16 - 4) = *(float *)((char *)v16 + v17 - 16);
      *(v16 - 3) = *(float *)((char *)v16 + v17 - 12);
      *(v16 - 2) = *(float *)((char *)v16 + v17 - 8);
      --v18;
    }
    while ( v18 );
  }
  if ( v4 < v15 )
  {
    v20 = (char *)v14 - (char *)v13;
    v21 = &v13[v4];
    v22 = v15 - v4;
    do
    {
      v23 = *(_DWORD *)((char *)v21++ + v20);
      *((_DWORD *)v21 - 1) = v23;
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 51
// RVA: 0xB27F20
__int64 __fastcall hkaInterleavedUncompressedAnimation::getSizeInBytes(hkaInterleavedUncompressedAnimation *this)
{
  return 4 * ((unsigned int)this->m_floats.m_size + 12i64 * (unsigned int)this->m_transforms.m_size) + 88;
}

// File Line: 56
// RVA: 0xB27F40
__int64 __fastcall hkaInterleavedUncompressedAnimation::getNumOriginalFrames(hkaInterleavedUncompressedAnimation *this)
{
  int m_numberOfTransformTracks; // r8d

  m_numberOfTransformTracks = this->m_numberOfTransformTracks;
  if ( m_numberOfTransformTracks )
    return (unsigned int)(this->m_transforms.m_size / m_numberOfTransformTracks);
  else
    return (unsigned int)(this->m_floats.m_size / this->m_numberOfFloatTracks);
}

// File Line: 71
// RVA: 0xB27620
void __fastcall hkaInterleavedUncompressedAnimation::sampleTracks(
        hkaInterleavedUncompressedAnimation *this,
        float time,
        hkQsTransformf *transformTracksOut,
        float *floatTracksOut)
{
  ((void (__fastcall *)(hkaInterleavedUncompressedAnimation *, hkBaseObjectVtbl *, _QWORD, hkQsTransformf *, int, float *))this->vfptr[2].__vecDelDtor)(
    this,
    this->vfptr,
    (unsigned int)this->m_numberOfTransformTracks,
    transformTracksOut,
    this->m_numberOfFloatTracks,
    floatTracksOut);
}

// File Line: 76
// RVA: 0xB27650
void __fastcall hkaInterleavedUncompressedAnimation::samplePartialTracks(
        hkaInterleavedUncompressedAnimation *this,
        float time,
        unsigned int maxNumTransformTracks,
        hkQsTransformf *transformTracksOut,
        int maxNumFloatTracks,
        float *floatTracksOut)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  unsigned int v15; // edx
  unsigned int v16; // r9d
  hkVector4f *p_m_scale; // r8
  unsigned int v18; // eax
  hkQsTransformf *v19; // rcx
  __int64 v20; // r10
  float *v21; // r8
  unsigned int v22; // eax
  float *v23; // r8
  unsigned int v24; // eax
  int v25; // eax
  __int64 v26; // r8
  __m128 v27; // xmm5
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  unsigned int v30; // eax
  __m128i v31; // xmm5
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  unsigned int v35; // esi
  float v36; // xmm6_4
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  _QWORD *v39; // rax
  _QWORD *v40; // rcx
  _QWORD *v41; // r8
  unsigned __int64 v42; // rax
  _QWORD *v43; // rcx
  hkaAnimation::DataChunk dataChunks; // [rsp+40h] [rbp-48h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtsamplePose";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  if ( time < this->m_duration )
  {
    v25 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *, unsigned __int64, _QWORD *))this->vfptr[4].__vecDelDtor)(
            this,
            v10,
            v12)
        - 1;
    v27 = 0i64;
    v28 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
    v29 = _mm_rcp_ps(v28);
    v27.m128_f32[0] = (float)v25;
    v30 = v25 - 1;
    v31 = (__m128i)_mm_and_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(v27, v27, 0),
                       _mm_mul_ps(
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v29)), v29),
                         _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0))),
                     _mm_cmplt_ps((__m128)0i64, v28));
    v32 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v31, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v33 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u));
    v34 = _mm_or_ps(
            _mm_andnot_ps(v33, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v31, v32)), v32)),
            _mm_and_ps((__m128)v31, v33));
    v35 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v34));
    if ( v35 <= v30 )
    {
      v37 = _mm_sub_ps((__m128)v31, v34);
      v38 = _mm_cmplt_ps(v37, query.m_quad);
      v36 = fmax(0.0, COERCE_FLOAT(v37.m128_i32[0] & v38.m128_i32[0] | _mm_andnot_ps(v38, query.m_quad).m128_u32[0]));
    }
    else
    {
      v36 = *(float *)&FLOAT_1_0;
      v35 = v30;
    }
    ((void (__fastcall *)(hkaInterleavedUncompressedAnimation *, _QWORD, __int64, hkaAnimation::DataChunk *, int))this->vfptr[5].__vecDelDtor)(
      this,
      v35,
      v26,
      &dataChunks,
      3);
    hkaInterleavedUncompressedAnimation::samplePartialWithDataChunks(
      v35,
      v36,
      maxNumTransformTracks,
      transformTracksOut,
      maxNumFloatTracks,
      floatTracksOut,
      &dataChunks,
      3);
  }
  else
  {
    v15 = 0;
    v16 = 0;
    if ( maxNumTransformTracks )
    {
      p_m_scale = &transformTracksOut->m_scale;
      do
      {
        p_m_scale += 3;
        v18 = v16 + this->m_transforms.m_size - this->m_numberOfTransformTracks;
        ++v16;
        v19 = &this->m_transforms.m_data[v18];
        p_m_scale[-5] = v19->m_translation;
        p_m_scale[-4] = v19->m_rotation.m_vec;
        p_m_scale[-3] = v19->m_scale;
      }
      while ( v16 < maxNumTransformTracks );
    }
    v20 = 0i64;
    if ( maxNumFloatTracks >= 4 )
    {
      v21 = floatTracksOut + 2;
      v20 = 4i64 * (((unsigned int)(maxNumFloatTracks - 4) >> 2) + 1);
      do
      {
        v21 += 4;
        *(v21 - 6) = this->m_floats.m_data[v15 + this->m_floats.m_size - this->m_numberOfFloatTracks];
        *(v21 - 5) = this->m_floats.m_data[v15 + this->m_floats.m_size - this->m_numberOfFloatTracks + 1];
        *(v21 - 4) = this->m_floats.m_data[v15 + this->m_floats.m_size - this->m_numberOfFloatTracks + 2];
        v22 = v15 + this->m_floats.m_size - this->m_numberOfFloatTracks + 3;
        v15 += 4;
        *(v21 - 3) = this->m_floats.m_data[v22];
      }
      while ( v15 < maxNumFloatTracks - 3 );
    }
    if ( v15 < maxNumFloatTracks )
    {
      v23 = &floatTracksOut[v20];
      do
      {
        ++v23;
        v24 = v15 + this->m_floats.m_size - this->m_numberOfFloatTracks;
        ++v15;
        *(v23 - 1) = this->m_floats.m_data[v24];
      }
      while ( v15 < maxNumFloatTracks );
    }
  }
  v39 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v40 = (_QWORD *)v39[1];
  v41 = v39;
  if ( (unsigned __int64)v40 < v39[3] )
  {
    *v40 = "Et";
    v42 = __rdtsc();
    v43 = v40 + 2;
    *((_DWORD *)v43 - 2) = v42;
    v41[1] = v43;
  }
}

// File Line: 120
// RVA: 0xB27990
void __fastcall hkaInterleavedUncompressedAnimation::sampleIndividualTransformTracks(
        hkaInterleavedUncompressedAnimation *this,
        float time,
        __int16 *tracks,
        unsigned int numTracks,
        hkQsTransformf *transformTracksOut)
{
  __m128 v5; // xmm6
  __int64 v6; // rsi
  int v9; // eax
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  unsigned int v12; // eax
  __m128 v13; // xmm1
  __m128i v14; // xmm5
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm4
  unsigned int v18; // r11d
  float v19; // xmm0_4
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm6
  __int64 v23; // r9
  hkQuaternionf *p_m_rotation; // r8
  __int16 v25; // cx
  __int64 m_numberOfTransformTracks; // r10
  hkQsTransformf *v27; // rdx
  __m128 m_quad; // xmm1
  __m128 v29; // xmm5
  __int64 v30; // rax
  __m128 v31; // xmm4
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm2

  v6 = numTracks;
  v9 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *))this->vfptr[4].__vecDelDtor)(this) - 1;
  v10 = 0i64;
  v11 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
  v10.m128_f32[0] = (float)v9;
  v12 = v9 - 1;
  v13 = _mm_rcp_ps(v11);
  v14 = (__m128i)_mm_and_ps(
                   _mm_cmplt_ps((__m128)0i64, v11),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v13)), v13),
                       _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0)),
                     _mm_shuffle_ps(v10, v10, 0)));
  v15 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v14, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v16 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v14, 1u), 1u));
  v17 = _mm_or_ps(
          _mm_andnot_ps(v16, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v14, v15)), v15)),
          _mm_and_ps(v16, (__m128)v14));
  v18 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v17));
  if ( v18 <= v12 )
  {
    v20 = _mm_sub_ps((__m128)v14, v17);
    v21 = _mm_cmplt_ps(v20, query.m_quad);
    v19 = fmax(0.0, COERCE_FLOAT(v20.m128_i32[0] & v21.m128_i32[0] | _mm_andnot_ps(v21, query.m_quad).m128_u32[0]));
  }
  else
  {
    v19 = *(float *)&FLOAT_1_0;
    v18 = v12;
  }
  v5.m128_f32[0] = v19;
  v22 = _mm_shuffle_ps(v5, v5, 0);
  if ( (_DWORD)v6 )
  {
    v23 = v6;
    p_m_rotation = &transformTracksOut->m_rotation;
    do
    {
      v25 = *tracks;
      if ( *tracks >= 0 )
      {
        m_numberOfTransformTracks = this->m_numberOfTransformTracks;
        if ( v25 < (int)m_numberOfTransformTracks )
        {
          v27 = &this->m_transforms.m_data[v18 * (unsigned int)m_numberOfTransformTracks];
          m_quad = v27[v25].m_scale.m_quad;
          v29 = v27[v25].m_rotation.m_vec.m_quad;
          v30 = v25 + m_numberOfTransformTracks;
          v31 = v27[v30].m_rotation.m_vec.m_quad;
          v32 = _mm_add_ps(
                  _mm_mul_ps(_mm_sub_ps(v27[v30].m_translation.m_quad, v27[v25].m_translation.m_quad), v22),
                  v27[v25].m_translation.m_quad);
          p_m_rotation[1].m_vec.m_quad = _mm_add_ps(
                                           _mm_mul_ps(_mm_sub_ps(v27[v30].m_scale.m_quad, m_quad), v22),
                                           m_quad);
          p_m_rotation[-1] = (hkQuaternionf)v32;
          v33 = _mm_mul_ps(v31, v29);
          v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
          v35 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32(
                                  (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v34), (__m128)0i64),
                                  0x1Fu),
                                0x1Fu),
                      v22),
                    v31),
                  _mm_mul_ps(_mm_sub_ps(query.m_quad, v22), v29));
          v36 = _mm_mul_ps(v35, v35);
          v37 = _mm_add_ps(_mm_shuffle_ps(v36, v36, 78), v36);
          v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 177), v37);
          v39 = _mm_rsqrt_ps(v38);
          p_m_rotation->m_vec.m_quad = _mm_mul_ps(
                                         v35,
                                         _mm_mul_ps(
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                                           _mm_mul_ps(*(__m128 *)_xmm, v39)));
        }
      }
      ++tracks;
      p_m_rotation += 3;
      --v23;
    }
    while ( v23 );
  }
}

// File Line: 152
// RVA: 0xB27BE0
void __fastcall hkaInterleavedUncompressedAnimation::sampleIndividualFloatTracks(
        hkaInterleavedUncompressedAnimation *this,
        float time,
        __int16 *tracks,
        unsigned int numTracks,
        float *floatTracksOut)
{
  int v8; // eax
  __m128 v9; // xmm5
  __m128 v10; // xmm4
  unsigned int v11; // eax
  __m128 v12; // xmm1
  __m128i v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  unsigned int v17; // ebp
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __int64 v20; // r9
  float v21; // xmm2_4
  __int16 v22; // r8
  int m_numberOfFloatTracks; // r10d
  float *v24; // rdx
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  float v28; // [rsp+58h] [rbp+10h]

  v8 = ((__int64 (*)(void))this->vfptr[4].__vecDelDtor)() - 1;
  v9 = 0i64;
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
  v9.m128_f32[0] = (float)v8;
  v11 = v8 - 1;
  v12 = _mm_rcp_ps(v10);
  v13 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_shuffle_ps(v9, v9, 0),
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v12)), v12),
                       _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0))),
                   _mm_cmplt_ps((__m128)0i64, v10));
  v14 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v13, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v15 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v13, 1u), 1u));
  v16 = _mm_or_ps(
          _mm_andnot_ps(v15, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v13, v14)), v14)),
          _mm_and_ps((__m128)v13, v15));
  v17 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v16));
  if ( v17 <= v11 )
  {
    v18 = _mm_sub_ps((__m128)v13, v16);
    v19 = _mm_cmplt_ps(v18, query.m_quad);
    v28 = fmax(0.0, COERCE_FLOAT(v18.m128_i32[0] & v19.m128_i32[0] | _mm_andnot_ps(v19, query.m_quad).m128_u32[0]));
  }
  else
  {
    v17 = v11;
    v28 = *(float *)&FLOAT_1_0;
  }
  v20 = 0i64;
  for ( LODWORD(v21) = _mm_shuffle_ps((__m128)LODWORD(v28), (__m128)LODWORD(v28), 0).m128_u32[0];
        (unsigned int)v20 < numTracks;
        ++tracks )
  {
    v22 = *tracks;
    if ( *tracks >= 0 )
    {
      m_numberOfFloatTracks = this->m_numberOfFloatTracks;
      if ( v22 < m_numberOfFloatTracks )
      {
        v24 = &this->m_floats.m_data[v17 * m_numberOfFloatTracks];
        v25 = (__m128)LODWORD(v24[v22]);
        v25.m128_f32[0] = _mm_shuffle_ps(v25, v25, 0).m128_f32[0];
        v26 = (__m128)LODWORD(v24[m_numberOfFloatTracks + v22]);
        floatTracksOut[v20] = (float)((float)(_mm_shuffle_ps(v26, v26, 0).m128_f32[0] - v25.m128_f32[0]) * v21)
                            + v25.m128_f32[0];
      }
    }
    v20 = (unsigned int)(v20 + 1);
  }
}

// File Line: 184
// RVA: 0xB27F60
__int64 __fastcall hkaInterleavedUncompressedAnimation::getNumDataChunks(
        hkaInterleavedUncompressedAnimation *this,
        unsigned int frame,
        float delta)
{
  __int64 result; // rax

  result = 1i64;
  if ( this->m_numberOfTransformTracks > 0 )
    result = 2i64;
  if ( this->m_numberOfFloatTracks > 0 )
    return (unsigned int)(result + 1);
  return result;
}

// File Line: 201
// RVA: 0xB27F90
void __fastcall hkaInterleavedUncompressedAnimation::getDataChunks(
        hkaInterleavedUncompressedAnimation *this,
        unsigned int frame,
        float delta,
        hkaAnimation::DataChunk *dataChunks)
{
  int m_numberOfTransformTracks; // eax
  int v7; // edx
  int m_numberOfFloatTracks; // ecx
  int v9; // r8d
  __int64 v10; // rdx
  const char *v11; // rcx

  dataChunks->m_data = (const char *)this;
  dataChunks->m_size = 88;
  m_numberOfTransformTracks = this->m_numberOfTransformTracks;
  v7 = 1;
  if ( m_numberOfTransformTracks > 0 )
  {
    dataChunks[1].m_data = (const char *)&this->m_transforms.m_data[frame * m_numberOfTransformTracks];
    v7 = 2;
    dataChunks[1].m_size = 96 * m_numberOfTransformTracks;
  }
  m_numberOfFloatTracks = this->m_numberOfFloatTracks;
  if ( m_numberOfFloatTracks > 0 )
  {
    v9 = 2 * m_numberOfFloatTracks;
    v10 = v7;
    v11 = (const char *)&this->m_floats.m_data[frame * m_numberOfFloatTracks];
    dataChunks[v10].m_size = 4 * v9;
    dataChunks[v10].m_data = v11;
  }
}

// File Line: 225
// RVA: 0xB28010
__int64 __fastcall hkaInterleavedUncompressedAnimation::getMaxSizeOfCombinedDataChunks(
        hkaInterleavedUncompressedAnimation *this)
{
  return 96 * (this->m_numberOfTransformTracks + 1) + ((8 * this->m_numberOfFloatTracks + 31) & 0xFFFFFFF0);
}

// File Line: 242
// RVA: 0xB28040
void __fastcall hkaInterleavedUncompressedAnimation::samplePartialWithDataChunks(
        unsigned int frameIndex,
        float deltaR,
        unsigned int maxNumTransformTracks,
        hkQsTransformf *transformTracksOut,
        unsigned int maxNumFloatTracks,
        float *floatTracksOut,
        hkaAnimation::DataChunk *dataChunks,
        int numDataChunks)
{
  __int64 v9; // rbx
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int v15; // eax
  const char *m_data; // r9
  __m128 v17; // xmm6
  __int64 v18; // rcx
  const char *v19; // r8
  __m128 *v20; // rcx
  hkQuaternionf *p_m_rotation; // rax
  __int64 v22; // r10
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __int64 v34; // r8
  const char *v35; // rcx
  const char *v36; // r8
  __int64 v38; // r9
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx

  v9 = maxNumTransformTracks;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtSampleInterleavedChunk";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  v15 = 1;
  m_data = dataChunks->m_data;
  v17 = _mm_shuffle_ps((__m128)LODWORD(deltaR), (__m128)LODWORD(deltaR), 0);
  v18 = *((int *)dataChunks->m_data + 6);
  if ( (int)v18 > 0 )
  {
    v19 = dataChunks[1].m_data;
    v20 = (__m128 *)&v19[48 * v18];
    if ( (_DWORD)v9 )
    {
      p_m_rotation = &transformTracksOut->m_rotation;
      v22 = v9;
      do
      {
        v23 = v20[2];
        v24 = v20[1];
        v25 = *v20;
        p_m_rotation += 3;
        v19 += 48;
        v20 += 3;
        v26 = _mm_mul_ps(v24, *((__m128 *)v19 - 2));
        v27 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v25, *((__m128 *)v19 - 3)), v17), *((__m128 *)v19 - 3));
        p_m_rotation[-2].m_vec.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_sub_ps(v23, *((__m128 *)v19 - 1)), v17),
                                          *((__m128 *)v19 - 1));
        p_m_rotation[-4] = (hkQuaternionf)v27;
        v28 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
        v29 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(
                                (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28), (__m128)0i64),
                                0x1Fu),
                              0x1Fu),
                    v17),
                  v20[-2]),
                _mm_mul_ps(_mm_sub_ps(query.m_quad, v17), *((__m128 *)v19 - 2)));
        v30 = _mm_mul_ps(v29, v29);
        v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 78), v30);
        v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v31);
        v33 = _mm_rsqrt_ps(v32);
        p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                          v29,
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                                            _mm_mul_ps(*(__m128 *)_xmm, v33)));
        --v22;
      }
      while ( v22 );
    }
    v15 = 2;
  }
  v34 = *((int *)m_data + 7);
  if ( (int)v34 > 0 )
  {
    v35 = dataChunks[v15].m_data;
    v36 = &v35[4 * v34];
    if ( maxNumFloatTracks )
    {
      v38 = maxNumFloatTracks;
      do
      {
        v39 = (__m128)*(unsigned int *)v35;
        ++floatTracksOut;
        v40 = (__m128)*(unsigned int *)v36;
        v35 += 4;
        v36 += 4;
        v39.m128_f32[0] = _mm_shuffle_ps(v39, v39, 0).m128_f32[0];
        *(floatTracksOut - 1) = (float)((float)(_mm_shuffle_ps(v40, v40, 0).m128_f32[0] - v39.m128_f32[0])
                                      * v17.m128_f32[0])
                              + v39.m128_f32[0];
        --v38;
      }
      while ( v38 );
    }
  }
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "Et";
    v43 = __rdtsc();
    v44 = v42 + 2;
    *((_DWORD *)v44 - 2) = v43;
    v41[1] = v44;
  }
}

// File Line: 285
// RVA: 0xB27D80
void __fastcall hkaInterleavedUncompressedAnimation::transformTrack(
        hkaInterleavedUncompressedAnimation *this,
        int track,
        hkQsTransformf *transform)
{
  __int64 v3; // r11
  int v4; // r10d
  __int64 v6; // rdi
  int v7; // eax
  __int64 v8; // rbx
  hkQuaternionf v9; // xmm2
  hkQsTransformf *m_data; // rdx
  __int64 m_numberOfTransformTracks; // rax
  int v12; // ecx
  __m128 v13; // xmm5
  __int64 v14; // rax
  __m128 m_quad; // xmm6
  __m128 v16; // xmm7
  __m128 v17; // xmm8
  __m128 v18; // xmm1
  __int64 v19; // rcx
  __m128 v20; // xmm4
  __m128 v21; // xmm4
  __m128 v22; // xmm0
  __m128 v23; // xmm5
  __m128 v24; // xmm3
  hkQuaternionf v25; // xmm2
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm7
  __m128 v30; // xmm3

  v3 = track;
  v4 = 0;
  v6 = 0i64;
  v7 = this->m_transforms.m_size / this->m_numberOfTransformTracks;
  v8 = v7;
  if ( v7 > 0 )
  {
    do
    {
      v9.m_vec.m_quad = (__m128)transform->m_rotation;
      m_data = this->m_transforms.m_data;
      m_numberOfTransformTracks = this->m_numberOfTransformTracks;
      v12 = v4 * m_numberOfTransformTracks;
      v13 = _mm_shuffle_ps(v9.m_vec.m_quad, v9.m_vec.m_quad, 255);
      v14 = v3 + v6 * m_numberOfTransformTracks;
      m_quad = m_data[v14].m_translation.m_quad;
      v16 = m_data[v14].m_rotation.m_vec.m_quad;
      v17 = m_data[v14].m_scale.m_quad;
      v18 = _mm_mul_ps(v9.m_vec.m_quad, m_quad);
      v19 = (int)v3 + v12;
      v20 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v9.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v9.m_vec.m_quad, v9.m_vec.m_quad, 201), m_quad));
      v21 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v13);
      v22 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), m_quad);
      v23 = _mm_shuffle_ps(v16, v16, 255);
      v24 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                    _mm_shuffle_ps(v18, v18, 170)),
                  v9.m_vec.m_quad),
                v22),
              v21);
      m_data[v19].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v24, v24), transform->m_translation.m_quad);
      v25.m_vec.m_quad = (__m128)transform->m_rotation;
      v26 = _mm_shuffle_ps(v25.m_vec.m_quad, v25.m_vec.m_quad, 255);
      v27 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v25.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v25.m_vec.m_quad, v25.m_vec.m_quad, 201), v16));
      v28 = _mm_mul_ps(v16, v26);
      v29 = _mm_mul_ps(v16, v25.m_vec.m_quad);
      v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 201), v28), _mm_mul_ps(v23, v25.m_vec.m_quad));
      m_data[v19].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                              v30,
                                              _mm_unpackhi_ps(
                                                v30,
                                                _mm_sub_ps(
                                                  _mm_mul_ps(v23, v26),
                                                  _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_shuffle_ps(v29, v29, 85),
                                                      _mm_shuffle_ps(v29, v29, 0)),
                                                    _mm_shuffle_ps(v29, v29, 170)))),
                                              196);
      ++v6;
      ++v4;
      m_data[v19].m_scale.m_quad = _mm_mul_ps(transform->m_scale.m_quad, v17);
    }
    while ( v6 < v8 );
  }
}

