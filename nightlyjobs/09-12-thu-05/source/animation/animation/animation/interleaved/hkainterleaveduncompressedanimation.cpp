// File Line: 16
// RVA: 0xB271F0
void __fastcall hkaInterleavedUncompressedAnimation::hkaInterleavedUncompressedAnimation(hkaInterleavedUncompressedAnimation *this, hkaAnimation *that)
{
  hkaAnimation *v2; // rbp
  hkaInterleavedUncompressedAnimation *v3; // rdi
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int v7; // er13
  int v8; // ebx
  int v9; // ecx
  int v10; // er9
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // er9
  int i; // ebx
  int v16; // eax
  signed __int64 v17; // r9
  __int64 v18; // rcx
  hkQsTransformf *v19; // rax
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  hkResult result; // [rsp+90h] [rbp+8h]

  v2 = that;
  v3 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, that);
  v4 = 0;
  v3->vfptr = (hkBaseObjectVtbl *)&hkaInterleavedUncompressedAnimation::`vftable';
  v3->m_transforms.m_data = 0i64;
  v3->m_transforms.m_size = 0;
  v3->m_transforms.m_capacityAndFlags = 2147483648;
  v3->m_floats.m_data = 0i64;
  v3->m_floats.m_size = 0;
  v3->m_floats.m_capacityAndFlags = 2147483648;
  v3->m_type.m_storage = 1;
  v5 = ((__int64 (__fastcall *)(hkaAnimation *))v2->vfptr[4].__vecDelDtor)(v2);
  v6 = v3->m_transforms.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = v5;
  v8 = v3->m_numberOfTransformTracks * v5;
  if ( v6 < v8 )
  {
    v9 = 2 * v6;
    v10 = v3->m_numberOfTransformTracks * v5;
    if ( v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_transforms,
      v10,
      48);
  }
  v3->m_transforms.m_size = v8;
  v11 = v7 * v3->m_numberOfFloatTracks;
  v12 = v3->m_floats.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < v11 )
  {
    v13 = 2 * v12;
    v14 = v7 * v3->m_numberOfFloatTracks;
    if ( v11 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_floats, v14, 4);
  }
  v3->m_floats.m_size = v11;
  for ( i = 0; i < v7; ++i )
  {
    v16 = v3->m_numberOfFloatTracks;
    if ( v16 )
      v17 = (signed __int64)&v3->m_floats.m_data[i * v16];
    else
      v17 = 0i64;
    ((void (__fastcall *)(hkaAnimation *, hkBaseObjectVtbl *, hkQsTransformf *, signed __int64))v2->vfptr[1].__first_virtual_table_function__)(
      v2,
      v2->vfptr,
      &v3->m_transforms.m_data[v3->m_numberOfTransformTracks * i],
      v17);
  }
  if ( v3->m_transforms.m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      v19 = v3->m_transforms.m_data;
      ++v4;
      ++v18;
      v20 = *((__m128 *)&v19[v18] - 2);
      v21 = _mm_mul_ps(v20, v20);
      v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
      v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22);
      v24 = _mm_rsqrt_ps(v23);
      *((__m128 *)&v19[v18] - 2) = _mm_mul_ps(
                                     v20,
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                                       _mm_mul_ps(*(__m128 *)_xmm, v24)));
    }
    while ( v4 < v3->m_transforms.m_size );
  }
}

// File Line: 45
// RVA: 0xB27420
void __fastcall hkaInterleavedUncompressedAnimation::hkaInterleavedUncompressedAnimation(hkaInterleavedUncompressedAnimation *this, hkaInterleavedUncompressedAnimation *that)
{
  hkaInterleavedUncompressedAnimation *v2; // rdi
  hkaInterleavedUncompressedAnimation *v3; // rbx
  signed __int64 v4; // rsi
  int v5; // eax
  __int64 v6; // rax
  hkQsTransformf *v7; // r8
  __int64 v8; // rdx
  signed __int64 v9; // rax
  char *v10; // rcx
  __int128 v11; // xmm0
  signed __int64 v12; // rax
  float *v13; // r11
  float *v14; // r10
  signed __int64 v15; // rdx
  signed __int64 v16; // rcx
  signed __int64 v17; // r8
  unsigned __int64 v18; // r9
  int v19; // eax
  signed __int64 v20; // r10
  signed __int64 v21; // rcx
  signed __int64 v22; // rdx
  int v23; // eax
  int v24; // [rsp+30h] [rbp+8h]

  v2 = that;
  v3 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, (hkaAnimation *)&that->vfptr);
  v4 = 0i64;
  v3->vfptr = (hkBaseObjectVtbl *)&hkaInterleavedUncompressedAnimation::`vftable';
  v3->m_transforms.m_data = 0i64;
  v3->m_transforms.m_size = 0;
  v3->m_transforms.m_capacityAndFlags = 2147483648;
  v3->m_floats.m_data = 0i64;
  v3->m_floats.m_size = 0;
  v3->m_floats.m_capacityAndFlags = 2147483648;
  v5 = v3->m_transforms.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v2->m_transforms.m_size )
  {
    if ( v3->m_transforms.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        48 * v5);
    v24 = 48 * v2->m_transforms.m_size;
    v3->m_transforms.m_data = (hkQsTransformf *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                  &v24);
    v3->m_transforms.m_capacityAndFlags = v24 / 48;
  }
  v6 = v2->m_transforms.m_size;
  v7 = v3->m_transforms.m_data;
  v3->m_transforms.m_size = v6;
  v8 = v6;
  if ( (signed int)v6 > 0 )
  {
    v9 = (signed __int64)&v7->m_rotation;
    v10 = (char *)((char *)v2->m_transforms.m_data - (char *)v7);
    do
    {
      v11 = *(_OWORD *)&v10[v9 - 16];
      v9 += 48i64;
      *(_OWORD *)(v9 - 64) = v11;
      *(_OWORD *)(v9 - 48) = *(_OWORD *)&v10[v9 - 48];
      *(_OWORD *)(v9 - 32) = *(_OWORD *)&v10[v9 - 32];
      --v8;
    }
    while ( v8 );
  }
  if ( (v3->m_floats.m_capacityAndFlags & 0x3FFFFFFF) < v2->m_floats.m_size )
  {
    if ( v3->m_floats.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_floats.m_data,
        4 * v3->m_floats.m_capacityAndFlags);
    v24 = 4 * v2->m_floats.m_size;
    v3->m_floats.m_data = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                     &v24);
    v3->m_floats.m_capacityAndFlags = v24 / 4;
  }
  v12 = v2->m_floats.m_size;
  v13 = v3->m_floats.m_data;
  v3->m_floats.m_size = v12;
  v14 = v2->m_floats.m_data;
  v15 = v12;
  if ( v12 >= 4 )
  {
    v16 = (signed __int64)(v13 + 1);
    v17 = (char *)v14 - (char *)v13;
    v18 = ((unsigned __int64)(v12 - 4) >> 2) + 1;
    v4 = 4 * v18;
    do
    {
      v19 = *(_DWORD *)(v16 + v17 - 4);
      v16 += 16i64;
      *(_DWORD *)(v16 - 20) = v19;
      *(_DWORD *)(v16 - 16) = *(_DWORD *)(v16 + v17 - 16);
      *(_DWORD *)(v16 - 12) = *(_DWORD *)(v16 + v17 - 12);
      *(_DWORD *)(v16 - 8) = *(_DWORD *)(v16 + v17 - 8);
      --v18;
    }
    while ( v18 );
  }
  if ( v4 < v15 )
  {
    v20 = (char *)v14 - (char *)v13;
    v21 = (signed __int64)&v13[v4];
    v22 = v15 - v4;
    do
    {
      v23 = *(_DWORD *)(v21 + v20);
      v21 += 4i64;
      *(_DWORD *)(v21 - 4) = v23;
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 51
// RVA: 0xB27F20
signed __int64 __fastcall hkaInterleavedUncompressedAnimation::getSizeInBytes(hkaInterleavedUncompressedAnimation *this)
{
  return 4 * ((unsigned int)this->m_floats.m_size + 12i64 * (unsigned int)this->m_transforms.m_size) + 88;
}

// File Line: 56
// RVA: 0xB27F40
__int64 __fastcall hkaInterleavedUncompressedAnimation::getNumOriginalFrames(hkaInterleavedUncompressedAnimation *this)
{
  int v1; // er8
  __int64 result; // rax

  v1 = this->m_numberOfTransformTracks;
  if ( v1 )
    result = (unsigned int)(this->m_transforms.m_size / v1);
  else
    result = (unsigned int)(this->m_floats.m_size / this->m_numberOfFloatTracks);
  return result;
}

// File Line: 71
// RVA: 0xB27620
void __fastcall hkaInterleavedUncompressedAnimation::sampleTracks(hkaInterleavedUncompressedAnimation *this, float time, hkQsTransformf *transformTracksOut, float *floatTracksOut)
{
  int v4; // ST20_4

  v4 = this->m_numberOfFloatTracks;
  ((void (__fastcall *)(hkaInterleavedUncompressedAnimation *, hkBaseObjectVtbl *, _QWORD, hkQsTransformf *, int, float *))this->vfptr[2].__vecDelDtor)(
    this,
    this->vfptr,
    (unsigned int)this->m_numberOfTransformTracks,
    transformTracksOut,
    v4,
    floatTracksOut);
}

// File Line: 76
// RVA: 0xB27650
void __fastcall hkaInterleavedUncompressedAnimation::samplePartialTracks(hkaInterleavedUncompressedAnimation *this, float time, unsigned int maxNumTransformTracks, hkQsTransformf *transformTracksOut, unsigned int maxNumFloatTracks, float *floatTracksOut)
{
  hkaInterleavedUncompressedAnimation *v6; // rbx
  hkQsTransformf *v7; // rbp
  unsigned int v8; // edi
  _QWORD *v9; // rax
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  unsigned int v15; // edx
  unsigned int v16; // er9
  signed __int64 v17; // r8
  int v18; // eax
  _OWORD *v19; // rcx
  signed __int64 v20; // r10
  float *v21; // r8
  int v22; // eax
  float *v23; // r8
  int v24; // eax
  signed int v25; // eax
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
  unsigned int v39; // ST20_4
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  hkaAnimation::DataChunk dataChunks; // [rsp+40h] [rbp-48h]
  float v46; // [rsp+98h] [rbp+10h]

  v6 = this;
  v7 = transformTracksOut;
  v8 = maxNumTransformTracks;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v9[1];
  v12 = v9;
  if ( (unsigned __int64)v11 < v9[3] )
  {
    *v11 = "TtsamplePose";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  if ( time < v6->m_duration )
  {
    v46 = time;
    v25 = (unsigned __int64)((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *, unsigned __int64, _QWORD *))v6->vfptr[4].__vecDelDtor)(
                              v6,
                              v10,
                              v12)
        - 1;
    v27 = 0i64;
    v28 = _mm_shuffle_ps((__m128)LODWORD(v6->m_duration), (__m128)LODWORD(v6->m_duration), 0);
    v29 = _mm_rcp_ps(v28);
    v27.m128_f32[0] = (float)v25;
    v30 = v25 - 1;
    v31 = (__m128i)_mm_and_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(v27, v27, 0),
                       _mm_mul_ps(
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v29)), v29),
                         _mm_shuffle_ps((__m128)LODWORD(v46), (__m128)LODWORD(v46), 0))),
                     _mm_cmpltps((__m128)0i64, v28));
    v32 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v31, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v33 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u));
    v34 = _mm_or_ps(
            _mm_andnot_ps(v33, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v31, v32)), v32)),
            _mm_and_ps((__m128)v31, v33));
    v35 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v34));
    if ( v35 <= v30 )
    {
      v37 = _mm_sub_ps((__m128)v31, v34);
      v38 = _mm_cmpltps(v37, query.m_quad);
      v36 = fmax(
              0.0,
              COERCE_FLOAT(v37.m128_i32[0] & v38.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v38, query.m_quad)));
    }
    else
    {
      v36 = *(float *)&FLOAT_1_0;
      v35 = v30;
    }
    v39 = 3;
    ((void (__fastcall *)(hkaInterleavedUncompressedAnimation *, _QWORD, __int64, hkaAnimation::DataChunk *, unsigned int))v6->vfptr[5].__vecDelDtor)(
      v6,
      v35,
      v26,
      &dataChunks,
      v39);
    hkaInterleavedUncompressedAnimation::samplePartialWithDataChunks(
      v35,
      v36,
      v8,
      v7,
      maxNumFloatTracks,
      floatTracksOut,
      &dataChunks,
      3);
  }
  else
  {
    v15 = 0;
    v16 = 0;
    if ( v8 )
    {
      v17 = (signed __int64)&v7->m_scale;
      do
      {
        v17 += 48i64;
        v18 = v16++ + v6->m_transforms.m_size - v6->m_numberOfTransformTracks;
        v19 = (_OWORD *)v6->m_transforms.m_data[v18].m_translation.m_quad.m128_f32;
        *(_OWORD *)(v17 - 80) = *v19;
        *(_OWORD *)(v17 - 64) = v19[1];
        *(_OWORD *)(v17 - 48) = v19[2];
      }
      while ( v16 < v8 );
    }
    v20 = 0i64;
    if ( (signed int)maxNumFloatTracks >= 4 )
    {
      v21 = floatTracksOut + 2;
      v20 = 4i64 * (((maxNumFloatTracks - 4) >> 2) + 1);
      do
      {
        v21 += 4;
        *(v21 - 6) = v6->m_floats.m_data[v15 + v6->m_floats.m_size - v6->m_numberOfFloatTracks];
        *(v21 - 5) = v6->m_floats.m_data[v15 + v6->m_floats.m_size - v6->m_numberOfFloatTracks + 1];
        *(v21 - 4) = v6->m_floats.m_data[v15 + v6->m_floats.m_size - v6->m_numberOfFloatTracks + 2];
        v22 = v15 + v6->m_floats.m_size - v6->m_numberOfFloatTracks + 3;
        v15 += 4;
        *(v21 - 3) = v6->m_floats.m_data[v22];
      }
      while ( v15 < maxNumFloatTracks - 3 );
    }
    if ( v15 < maxNumFloatTracks )
    {
      v23 = &floatTracksOut[v20];
      do
      {
        ++v23;
        v24 = v15++ + v6->m_floats.m_size - v6->m_numberOfFloatTracks;
        *(v23 - 1) = v6->m_floats.m_data[v24];
      }
      while ( v15 < maxNumFloatTracks );
    }
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  v42 = v40;
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v43 = __rdtsc();
    v44 = (signed __int64)(v41 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v42[1] = v44;
  }
}

// File Line: 120
// RVA: 0xB27990
void __usercall hkaInterleavedUncompressedAnimation::sampleIndividualTransformTracks(hkaInterleavedUncompressedAnimation *this@<rcx>, float time@<xmm1>, const __int16 *tracks@<r8>, unsigned int numTracks@<r9d>, __m128 a5@<xmm6>, hkQsTransformf *transformTracksOut)
{
  __int64 v6; // rsi
  const __int16 *v7; // rbx
  hkaInterleavedUncompressedAnimation *v8; // rdi
  signed int v9; // eax
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  unsigned int v12; // eax
  __m128 v13; // xmm1
  __m128i v14; // xmm5
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  unsigned int v18; // er11
  float v19; // xmm0_4
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm6
  __int64 v23; // r9
  __m128 *v24; // r8
  __int16 v25; // cx
  __int64 v26; // r10
  signed __int64 v27; // rdx
  __m128 v28; // xmm1
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
  float v40; // [rsp+58h] [rbp+10h]

  v40 = time;
  v6 = numTracks;
  v7 = tracks;
  v8 = this;
  v9 = (unsigned __int64)((__int64 (*)(void))this->vfptr[4].__vecDelDtor)() - 1;
  v10 = 0i64;
  v11 = _mm_shuffle_ps((__m128)LODWORD(v8->m_duration), (__m128)LODWORD(v8->m_duration), 0);
  v10.m128_f32[0] = (float)v9;
  v12 = v9 - 1;
  v13 = _mm_rcp_ps(v11);
  v14 = (__m128i)_mm_and_ps(
                   _mm_cmpltps((__m128)0i64, v11),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v13)), v13),
                       _mm_shuffle_ps((__m128)LODWORD(v40), (__m128)LODWORD(v40), 0)),
                     _mm_shuffle_ps(v10, v10, 0)));
  v15 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v14, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v16 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v14, 1u), 1u));
  v17 = _mm_or_ps(
          _mm_andnot_ps(v16, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v14, v15)), v15)),
          _mm_and_ps(v16, (__m128)v14));
  v18 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v17));
  if ( v18 <= v12 )
  {
    v20 = _mm_sub_ps((__m128)v14, v17);
    v21 = _mm_cmpltps(v20, query.m_quad);
    v19 = fmax(
            0.0,
            COERCE_FLOAT(v20.m128_i32[0] & v21.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v21, query.m_quad)));
  }
  else
  {
    v19 = *(float *)&FLOAT_1_0;
    v18 = v12;
  }
  a5.m128_f32[0] = v19;
  v22 = _mm_shuffle_ps(a5, a5, 0);
  if ( (_DWORD)v6 )
  {
    v23 = v6;
    v24 = &transformTracksOut->m_rotation.m_vec.m_quad;
    do
    {
      v25 = *v7;
      if ( *v7 >= 0 )
      {
        v26 = v8->m_numberOfTransformTracks;
        if ( v25 < (signed int)v26 )
        {
          v27 = (signed __int64)&v8->m_transforms.m_data[v18 * (unsigned int)v26];
          v28 = *(__m128 *)(v27 + 48i64 * v25 + 32);
          v29 = *(__m128 *)(v27 + 48i64 * v25 + 16);
          v30 = v25 + v26;
          v31 = *(__m128 *)(48 * v30 + v27 + 16);
          v32 = _mm_add_ps(
                  _mm_mul_ps(_mm_sub_ps(*(__m128 *)(48 * v30 + v27), *(__m128 *)(v27 + 48i64 * v25)), v22),
                  *(__m128 *)(v27 + 48i64 * v25));
          v24[1] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)(48 * v30 + v27 + 32), v28), v22), v28);
          v24[-1] = v32;
          v33 = _mm_mul_ps(v31, v29);
          v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
          v35 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32(
                                  (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v34), (__m128)0i64),
                                  0x1Fu),
                                0x1Fu),
                      v22),
                    v31),
                  _mm_mul_ps(_mm_sub_ps(query.m_quad, v22), v29));
          v36 = _mm_mul_ps(v35, v35);
          v37 = _mm_add_ps(_mm_shuffle_ps(v36, v36, 78), v36);
          v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 177), v37);
          v39 = _mm_rsqrt_ps(v38);
          *v24 = _mm_mul_ps(
                   v35,
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                     _mm_mul_ps(*(__m128 *)_xmm, v39)));
        }
      }
      ++v7;
      v24 += 3;
      --v23;
    }
    while ( v23 );
  }
}

// File Line: 152
// RVA: 0xB27BE0
void __fastcall hkaInterleavedUncompressedAnimation::sampleIndividualFloatTracks(hkaInterleavedUncompressedAnimation *this, float time, const __int16 *tracks, unsigned int numTracks, float *floatTracksOut)
{
  unsigned int v5; // esi
  const __int16 *v6; // rbx
  hkaInterleavedUncompressedAnimation *v7; // rdi
  signed int v8; // eax
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
  signed int v23; // er10
  signed __int64 v24; // rdx
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  float v27; // [rsp+58h] [rbp+10h]
  float v28; // [rsp+58h] [rbp+10h]

  v27 = time;
  v5 = numTracks;
  v6 = tracks;
  v7 = this;
  v8 = (unsigned __int64)((__int64 (*)(void))this->vfptr[4].__vecDelDtor)() - 1;
  v9 = 0i64;
  v10 = _mm_shuffle_ps((__m128)LODWORD(v7->m_duration), (__m128)LODWORD(v7->m_duration), 0);
  v9.m128_f32[0] = (float)v8;
  v11 = v8 - 1;
  v12 = _mm_rcp_ps(v10);
  v13 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_shuffle_ps(v9, v9, 0),
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v12)), v12),
                       _mm_shuffle_ps((__m128)LODWORD(v27), (__m128)LODWORD(v27), 0))),
                   _mm_cmpltps((__m128)0i64, v10));
  v14 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v13, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v15 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v13, 1u), 1u));
  v16 = _mm_or_ps(
          _mm_andnot_ps(v15, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v13, v14)), v14)),
          _mm_and_ps((__m128)v13, v15));
  v17 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v16));
  if ( v17 <= v11 )
  {
    v18 = _mm_sub_ps((__m128)v13, v16);
    v19 = _mm_cmpltps(v18, query.m_quad);
    v28 = fmax(
            0.0,
            COERCE_FLOAT(v18.m128_i32[0] & v19.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v19, query.m_quad)));
  }
  else
  {
    v17 = v11;
    v28 = *(float *)&FLOAT_1_0;
  }
  v20 = 0i64;
  LODWORD(v21) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(v28), (__m128)LODWORD(v28), 0);
  if ( v5 )
  {
    do
    {
      v22 = *v6;
      if ( *v6 >= 0 )
      {
        v23 = v7->m_numberOfFloatTracks;
        if ( v22 < v23 )
        {
          v24 = (signed __int64)&v7->m_floats.m_data[v17 * v23];
          v25 = (__m128)*(unsigned int *)(v24 + 4i64 * v22);
          v25.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v25, v25, 0);
          v26 = (__m128)*(unsigned int *)(v24 + 4i64 * (v23 + v22));
          floatTracksOut[v20] = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)) - v25.m128_f32[0]) * v21)
                              + v25.m128_f32[0];
        }
      }
      v20 = (unsigned int)(v20 + 1);
      ++v6;
    }
    while ( (unsigned int)v20 < v5 );
  }
}

// File Line: 184
// RVA: 0xB27F60
signed __int64 __fastcall hkaInterleavedUncompressedAnimation::getNumDataChunks(hkaInterleavedUncompressedAnimation *this, unsigned int frame, float delta)
{
  signed __int64 result; // rax

  result = 1i64;
  if ( this->m_numberOfTransformTracks > 0 )
    result = 2i64;
  if ( this->m_numberOfFloatTracks > 0 )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 201
// RVA: 0xB27F90
void __fastcall hkaInterleavedUncompressedAnimation::getDataChunks(hkaInterleavedUncompressedAnimation *this, unsigned int frame, float delta, hkaAnimation::DataChunk *dataChunks)
{
  int v4; // eax
  unsigned int v5; // er11
  hkaInterleavedUncompressedAnimation *v6; // r10
  signed int v7; // edx
  int v8; // ecx
  int v9; // er8
  __int64 v10; // rdx
  const char *v11; // rcx

  dataChunks->m_data = (const char *)this;
  dataChunks->m_size = 88;
  v4 = this->m_numberOfTransformTracks;
  v5 = frame;
  v6 = this;
  v7 = 1;
  if ( v4 > 0 )
  {
    dataChunks[1].m_data = (const char *)&this->m_transforms.m_data[v5 * v4];
    v7 = 2;
    dataChunks[1].m_size = 96 * v4;
  }
  v8 = this->m_numberOfFloatTracks;
  if ( v8 > 0 )
  {
    v9 = 2 * v8;
    v10 = v7;
    v11 = (const char *)&v6->m_floats.m_data[v5 * v8];
    dataChunks[v10].m_size = 4 * v9;
    dataChunks[v10].m_data = v11;
  }
}

// File Line: 225
// RVA: 0xB28010
__int64 __fastcall hkaInterleavedUncompressedAnimation::getMaxSizeOfCombinedDataChunks(hkaInterleavedUncompressedAnimation *this)
{
  return 96 * (this->m_numberOfTransformTracks + 1) + ((8 * this->m_numberOfFloatTracks + 31) & 0xFFFFFFF0);
}

// File Line: 242
// RVA: 0xB28040
void __fastcall hkaInterleavedUncompressedAnimation::samplePartialWithDataChunks(unsigned int frameIndex, float deltaR, unsigned int maxNumTransformTracks, hkQsTransformf *transformTracksOut, unsigned int maxNumFloatTracks, float *floatTracksOut, hkaAnimation::DataChunk *dataChunks, int numDataChunks)
{
  hkQsTransformf *v8; // rdi
  __int64 v9; // rbx
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  signed int v15; // eax
  const char *v16; // r9
  __m128 v17; // xmm6
  __int64 v18; // rcx
  const char *v19; // r8
  __m128 *v20; // rcx
  signed __int64 v21; // rax
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
  float *v37; // rdx
  __int64 v38; // r9
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx

  v8 = transformTracksOut;
  v9 = maxNumTransformTracks;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtSampleInterleavedChunk";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = 1;
  v16 = dataChunks->m_data;
  v17 = _mm_shuffle_ps((__m128)LODWORD(deltaR), (__m128)LODWORD(deltaR), 0);
  v18 = *((signed int *)dataChunks->m_data + 6);
  if ( (signed int)v18 > 0 )
  {
    v19 = dataChunks[1].m_data;
    v20 = (__m128 *)&v19[48 * v18];
    if ( (_DWORD)v9 )
    {
      v21 = (signed __int64)&v8->m_rotation;
      v22 = v9;
      do
      {
        v23 = v20[2];
        v24 = v20[1];
        v25 = *v20;
        v21 += 48i64;
        v19 += 48;
        v20 += 3;
        v26 = _mm_mul_ps(v24, *((__m128 *)v19 - 2));
        v27 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v25, *((__m128 *)v19 - 3)), v17), *((__m128 *)v19 - 3));
        *(__m128 *)(v21 - 32) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v23, *((__m128 *)v19 - 1)), v17), *((__m128 *)v19 - 1));
        *(__m128 *)(v21 - 64) = v27;
        v28 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
        v29 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(
                                (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28), (__m128)0i64),
                                0x1Fu),
                              0x1Fu),
                    v17),
                  v20[-2]),
                _mm_mul_ps(_mm_sub_ps(query.m_quad, v17), *((__m128 *)v19 - 2)));
        v30 = _mm_mul_ps(v29, v29);
        v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 78), v30);
        v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v31);
        v33 = _mm_rsqrt_ps(v32);
        *(__m128 *)(v21 - 48) = _mm_mul_ps(
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
  v34 = *((signed int *)v16 + 7);
  if ( (signed int)v34 > 0 )
  {
    v35 = dataChunks[v15].m_data;
    v36 = &v35[4 * v34];
    if ( maxNumFloatTracks )
    {
      v37 = floatTracksOut;
      v38 = maxNumFloatTracks;
      do
      {
        v39 = (__m128)*(unsigned int *)v35;
        ++v37;
        v40 = (__m128)*(unsigned int *)v36;
        v35 += 4;
        v36 += 4;
        v39.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v39, v39, 0);
        *(v37 - 1) = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)) - v39.m128_f32[0]) * v17.m128_f32[0])
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
    v44 = (signed __int64)(v42 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v41[1] = v44;
  }
}

// File Line: 285
// RVA: 0xB27D80
void __fastcall hkaInterleavedUncompressedAnimation::transformTrack(hkaInterleavedUncompressedAnimation *this, int track, hkQsTransformf *transform)
{
  __int64 v3; // r11
  int v4; // er10
  hkaInterleavedUncompressedAnimation *v5; // r9
  signed __int64 v6; // rdi
  int v7; // eax
  hkQuaternionf v8; // xmm2
  hkQsTransformf *v9; // rdx
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm7
  __m128 v13; // xmm8
  __m128 v14; // xmm1
  signed __int64 v15; // rcx
  __m128 v16; // xmm4
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  hkQuaternionf v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm7
  __m128 v26; // xmm3

  v3 = track;
  v4 = 0;
  v5 = this;
  v6 = 0i64;
  v7 = this->m_transforms.m_size / this->m_numberOfTransformTracks;
  if ( v7 > 0 )
  {
    do
    {
      v8.m_vec.m_quad = (__m128)transform->m_rotation;
      v9 = v5->m_transforms.m_data;
      v10 = _mm_shuffle_ps(transform->m_rotation.m_vec.m_quad, v8.m_vec.m_quad, 255);
      v11 = v9[v3 + v6 * v5->m_numberOfTransformTracks].m_translation.m_quad;
      v12 = v9[v3 + v6 * v5->m_numberOfTransformTracks].m_rotation.m_vec.m_quad;
      v13 = v9[v3 + v6 * v5->m_numberOfTransformTracks].m_scale.m_quad;
      v14 = _mm_mul_ps(transform->m_rotation.m_vec.m_quad, v11);
      v15 = (signed int)v3 + v4 * v5->m_numberOfTransformTracks;
      v16 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v8.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v8.m_vec.m_quad, v8.m_vec.m_quad, 201), v11));
      v17 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v10);
      v18 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v10, v10), (__m128)xmmword_141A711B0), v11);
      v19 = _mm_shuffle_ps(v12, v12, 255);
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170)),
                  v8.m_vec.m_quad),
                v18),
              v17);
      v9[v15].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v20, v20), transform->m_translation.m_quad);
      v21.m_vec.m_quad = (__m128)transform->m_rotation;
      v22 = _mm_shuffle_ps(transform->m_rotation.m_vec.m_quad, transform->m_rotation.m_vec.m_quad, 255);
      v23 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v21.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(transform->m_rotation.m_vec.m_quad, v21.m_vec.m_quad, 201), v12));
      v24 = _mm_mul_ps(v12, v22);
      v25 = _mm_mul_ps(v12, v21.m_vec.m_quad);
      v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 201), v24), _mm_mul_ps(v19, v21.m_vec.m_quad));
      v9[v15].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                          v26,
                                          _mm_unpackhi_ps(
                                            v26,
                                            _mm_sub_ps(
                                              _mm_mul_ps(v19, v22),
                                              _mm_add_ps(
                                                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                                                _mm_shuffle_ps(v25, v25, 170)))),
                                          196);
      ++v6;
      ++v4;
      v9[v15].m_scale.m_quad = _mm_mul_ps(transform->m_scale.m_quad, v13);
    }
    while ( v6 < v7 );
  }
}

