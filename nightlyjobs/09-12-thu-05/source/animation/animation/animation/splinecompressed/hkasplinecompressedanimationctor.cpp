// File Line: 20
// RVA: 0xB3BE50
void __fastcall hkaSplineCompressedAnimation::TrackCompressionParams::TrackCompressionParams(hkaSplineCompressedAnimation::TrackCompressionParams *this)
{
  this->m_floatingTolerance = 0.001;
  this->m_scaleTolerance = 0.001;
  this->m_translationTolerance = 0.001;
  this->m_rotationTolerance = 0.001;
  *(_DWORD *)&this->m_scaleDegree = 196611;
  *(_DWORD *)&this->m_rotationDegree = 196611;
  *(_DWORD *)&this->m_rotationQuantizationType.m_storage = 16843009;
}

// File Line: 32
// RVA: 0xB3BE90
void __fastcall hkaSplineCompressedAnimation::AnimationCompressionParams::AnimationCompressionParams(hkaSplineCompressedAnimation::AnimationCompressionParams *this)
{
  this->m_maxFramesPerBlock = 256;
  this->m_enableSampleSingleTracks.m_bool = 0;
}

// File Line: 40
// RVA: 0xB3BEB0
void __fastcall hkaSplineCompressedAnimation::hkaSplineCompressedAnimation(hkaSplineCompressedAnimation *this, hkaInterleavedUncompressedAnimation *raw)
{
  hkaInterleavedUncompressedAnimation *v2; // rbx
  hkaSplineCompressedAnimation *v3; // rdi
  hkaSplineCompressedAnimation::TrackCompressionParams trackParams; // [rsp+20h] [rbp-28h]
  hkaSplineCompressedAnimation::AnimationCompressionParams animationParams; // [rsp+50h] [rbp+8h]

  v2 = raw;
  v3 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, (hkaAnimation *)&raw->vfptr);
  v3->vfptr = (hkBaseObjectVtbl *)&hkaSplineCompressedAnimation::`vftable;
  v3->m_blockOffsets.m_capacityAndFlags = 2147483648;
  v3->m_blockOffsets.m_data = 0i64;
  v3->m_blockOffsets.m_size = 0;
  v3->m_floatBlockOffsets.m_data = 0i64;
  v3->m_floatBlockOffsets.m_size = 0;
  v3->m_floatBlockOffsets.m_capacityAndFlags = 2147483648;
  v3->m_transformOffsets.m_data = 0i64;
  v3->m_transformOffsets.m_size = 0;
  v3->m_transformOffsets.m_capacityAndFlags = 2147483648;
  v3->m_floatOffsets.m_data = 0i64;
  v3->m_floatOffsets.m_size = 0;
  v3->m_floatOffsets.m_capacityAndFlags = 2147483648;
  v3->m_data.m_data = 0i64;
  v3->m_data.m_size = 0;
  v3->m_data.m_capacityAndFlags = 2147483648;
  hkaSplineCompressedAnimation::TrackCompressionParams::TrackCompressionParams(&trackParams);
  hkaSplineCompressedAnimation::AnimationCompressionParams::AnimationCompressionParams(&animationParams);
  hkaSplineCompressedAnimation::initialize(v3, v2, &trackParams, &animationParams);
}

// File Line: 55
// RVA: 0xB3BF70
void __fastcall hkaSplineCompressedAnimation::hkaSplineCompressedAnimation(hkaSplineCompressedAnimation *this, hkaInterleavedUncompressedAnimation *raw, hkaSplineCompressedAnimation::TrackCompressionParams *trackParams, hkaSplineCompressedAnimation::AnimationCompressionParams *animationParams)
{
  hkaSplineCompressedAnimation::AnimationCompressionParams *v4; // rbx
  hkaSplineCompressedAnimation::TrackCompressionParams *v5; // rdi
  hkaInterleavedUncompressedAnimation *v6; // rsi
  hkaSplineCompressedAnimation *v7; // r14

  v4 = animationParams;
  v5 = trackParams;
  v6 = raw;
  v7 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, (hkaAnimation *)&raw->vfptr);
  v7->vfptr = (hkBaseObjectVtbl *)&hkaSplineCompressedAnimation::`vftable;
  v7->m_blockOffsets.m_capacityAndFlags = 2147483648;
  v7->m_blockOffsets.m_data = 0i64;
  v7->m_blockOffsets.m_size = 0;
  v7->m_floatBlockOffsets.m_data = 0i64;
  v7->m_floatBlockOffsets.m_size = 0;
  v7->m_floatBlockOffsets.m_capacityAndFlags = 2147483648;
  v7->m_transformOffsets.m_data = 0i64;
  v7->m_transformOffsets.m_size = 0;
  v7->m_transformOffsets.m_capacityAndFlags = 2147483648;
  v7->m_floatOffsets.m_data = 0i64;
  v7->m_floatOffsets.m_size = 0;
  v7->m_floatOffsets.m_capacityAndFlags = 2147483648;
  v7->m_data.m_data = 0i64;
  v7->m_data.m_size = 0;
  v7->m_data.m_capacityAndFlags = 2147483648;
  hkaSplineCompressedAnimation::initialize(v7, v6, v5, v4);
}

// File Line: 68
// RVA: 0xB3C040
void __fastcall hkaSplineCompressedAnimation::hkaSplineCompressedAnimation(hkaSplineCompressedAnimation *this, hkaInterleavedUncompressedAnimation *raw, hkaSplineCompressedAnimation::PerTrackCompressionParams *trackParams, hkaSplineCompressedAnimation::AnimationCompressionParams *animationParams)
{
  hkaSplineCompressedAnimation::AnimationCompressionParams *v4; // rbx
  hkaSplineCompressedAnimation::PerTrackCompressionParams *v5; // rdi
  hkaInterleavedUncompressedAnimation *v6; // rsi
  hkaSplineCompressedAnimation *v7; // r14

  v4 = animationParams;
  v5 = trackParams;
  v6 = raw;
  v7 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, (hkaAnimation *)&raw->vfptr);
  v7->vfptr = (hkBaseObjectVtbl *)&hkaSplineCompressedAnimation::`vftable;
  v7->m_blockOffsets.m_capacityAndFlags = 2147483648;
  v7->m_blockOffsets.m_data = 0i64;
  v7->m_blockOffsets.m_size = 0;
  v7->m_floatBlockOffsets.m_data = 0i64;
  v7->m_floatBlockOffsets.m_size = 0;
  v7->m_floatBlockOffsets.m_capacityAndFlags = 2147483648;
  v7->m_transformOffsets.m_data = 0i64;
  v7->m_transformOffsets.m_size = 0;
  v7->m_transformOffsets.m_capacityAndFlags = 2147483648;
  v7->m_floatOffsets.m_data = 0i64;
  v7->m_floatOffsets.m_size = 0;
  v7->m_floatOffsets.m_capacityAndFlags = 2147483648;
  v7->m_data.m_data = 0i64;
  v7->m_data.m_size = 0;
  v7->m_data.m_capacityAndFlags = 2147483648;
  hkaSplineCompressedAnimation::initialize(v7, v6, v5, v4);
}

// File Line: 76
// RVA: 0xB3C850
void __fastcall hkaSplineCompressedAnimation::initialize(hkaSplineCompressedAnimation *this, hkaInterleavedUncompressedAnimation *raw, hkaSplineCompressedAnimation::TrackCompressionParams *trackParams, hkaSplineCompressedAnimation::AnimationCompressionParams *animationParams)
{
  hkaSplineCompressedAnimation::TrackCompressionParams *v4; // rdi
  hkaInterleavedUncompressedAnimation *v5; // rbx
  hkaSplineCompressedAnimation *v6; // r14
  hkaSplineCompressedAnimation::AnimationCompressionParams *v7; // rsi
  int v8; // eax
  char *v9; // rcx
  int v10; // edi
  int v11; // er9
  int v12; // edi
  int v13; // er9
  int v14; // edx
  __int64 v15; // rcx
  int v16; // edx
  __int64 v17; // rcx
  char *array; // [rsp+30h] [rbp-30h]
  int v19; // [rsp+38h] [rbp-28h]
  int v20; // [rsp+3Ch] [rbp-24h]
  char *v21; // [rsp+40h] [rbp-20h]
  int v22; // [rsp+48h] [rbp-18h]
  int v23; // [rsp+4Ch] [rbp-14h]
  char *v24; // [rsp+50h] [rbp-10h]
  int v25; // [rsp+58h] [rbp-8h]
  int v26; // [rsp+5Ch] [rbp-4h]
  hkResult result; // [rsp+88h] [rbp+28h]

  v4 = trackParams;
  v5 = raw;
  v6 = this;
  v7 = animationParams;
  array = 0i64;
  v19 = 0;
  v20 = 2147483648;
  v21 = 0i64;
  v22 = 0;
  v23 = 2147483648;
  v24 = 0i64;
  v25 = 0;
  v26 = 2147483648;
  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 28);
  v8 = v19;
  v9 = &array[28 * v19];
  if ( v9 )
  {
    *(float *)v9 = v4->m_rotationTolerance;
    *((_DWORD *)v9 + 1) = LODWORD(v4->m_translationTolerance);
    *((_DWORD *)v9 + 2) = LODWORD(v4->m_scaleTolerance);
    *((_DWORD *)v9 + 3) = LODWORD(v4->m_floatingTolerance);
    *((_DWORD *)v9 + 4) = *(_DWORD *)&v4->m_rotationDegree;
    *((_DWORD *)v9 + 5) = *(_DWORD *)&v4->m_scaleDegree;
    *((_DWORD *)v9 + 6) = *(_DWORD *)&v4->m_rotationQuantizationType.m_storage;
    v8 = v19;
  }
  v10 = v5->m_numberOfTransformTracks;
  v19 = v8 + 1;
  if ( (v23 & 0x3FFFFFFF) < v10 )
  {
    v11 = v10;
    if ( v10 < 2 * (v23 & 0x3FFFFFFF) )
      v11 = 2 * (v23 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v21, v11, 4);
  }
  v22 = v10;
  v12 = v5->m_numberOfFloatTracks;
  if ( (v26 & 0x3FFFFFFF) < v12 )
  {
    v13 = v5->m_numberOfFloatTracks;
    if ( v12 < 2 * (v26 & 0x3FFFFFFF) )
      v13 = 2 * (v26 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v24, v13, 4);
  }
  v14 = 0;
  v25 = v12;
  if ( v5->m_numberOfTransformTracks > 0 )
  {
    v15 = 0i64;
    do
    {
      ++v14;
      v15 += 4i64;
      *(_DWORD *)&v21[v15 - 4] = 0;
    }
    while ( v14 < v5->m_numberOfTransformTracks );
  }
  v16 = 0;
  if ( v5->m_numberOfFloatTracks > 0 )
  {
    v17 = 0i64;
    do
    {
      ++v16;
      v17 += 4i64;
      *(_DWORD *)&v24[v17 - 4] = 0;
    }
    while ( v16 < v5->m_numberOfFloatTracks );
  }
  hkaSplineCompressedAnimation::initialize(
    v6,
    v5,
    (hkaSplineCompressedAnimation::PerTrackCompressionParams *)&array,
    v7);
  v25 = 0;
  if ( v26 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v24,
      4 * v26);
  v24 = 0i64;
  v26 = 2147483648;
  v22 = 0;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v21,
      4 * v23);
  v21 = 0i64;
  v23 = 2147483648;
  v19 = 0;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      28 * (v20 & 0x3FFFFFFF));
}

// File Line: 103
// RVA: 0xB3CA90
void __fastcall hkaSplineCompressedAnimation::initialize(hkaSplineCompressedAnimation *this, hkaInterleavedUncompressedAnimation *raw, hkaSplineCompressedAnimation::PerTrackCompressionParams *trackParams, hkaSplineCompressedAnimation::AnimationCompressionParams *animationParams)
{
  hkaSplineCompressedAnimation *v4; // r13
  hkaSplineCompressedAnimation::PerTrackCompressionParams *v5; // r14
  hkaInterleavedUncompressedAnimation *v6; // rdi
  char v7; // bl
  hkBaseObjectVtbl *v8; // rax
  int v9; // eax
  int v10; // ecx
  int v11; // er12
  float v12; // xmm2_4
  int v13; // er8
  int v14; // er9
  int v15; // eax
  int v16; // ecx
  float v17; // xmm2_4
  float v18; // xmm1_4
  int v19; // er10
  unsigned int v20; // edx
  hkArray<unsigned char,hkContainerHeapAllocator> *v21; // rsi
  hkArray<unsigned int,hkContainerHeapAllocator> *v22; // r15
  int v23; // edi
  __int64 v24; // rdi
  int v25; // er15
  unsigned int v26; // eax
  int v27; // er15
  __m128i v28; // xmm0
  float v29; // xmm8_4
  __int64 v30; // rdx
  int v31; // er12
  signed int v32; // esi
  int v33; // er14
  __int64 v34; // r8
  __int64 v35; // r9
  int v36; // esi
  int *v37; // rax
  int v38; // ecx
  int v39; // esi
  signed __int64 v40; // r14
  unsigned __int64 v41; // rdi
  __int64 v42; // r12
  int v43; // eax
  int v44; // eax
  int v45; // er9
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // er9
  float v50; // xmm0_4
  int v51; // xmm1_4
  int v52; // edx
  int v53; // eax
  int v54; // xmm0_4
  int v55; // eax
  float v56; // xmm0_4
  int v57; // edx
  int v58; // er13
  __int64 v59; // r12
  __int64 v60; // rbx
  signed __int64 v61; // rsi
  __m128 v62; // xmm0
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128 v65; // xmm3
  float v66; // xmm6_4
  float v67; // xmm3_4
  char v68; // si
  char v69; // al
  float *v70; // r8
  int v71; // edi
  int v72; // edx
  hkVector4f *pointsOut; // rcx
  char v74; // al
  float *v75; // rdx
  int v76; // er12
  unsigned int v77; // eax
  int v78; // edx
  __int64 v79; // rax
  unsigned int v80; // eax
  int v81; // edi
  int v82; // er9
  int v83; // edi
  int v84; // er9
  int v85; // edi
  int v86; // er9
  int v87; // er9
  unsigned __int8 *v88; // rax
  hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization v89; // er8
  signed int v90; // esi
  char *v91; // rdi
  int v92; // er8
  signed int v93; // esi
  int *v94; // rdi
  int v95; // er8
  hkOstream *v96; // rax
  int v97; // ebx
  hkOstream *v98; // rax
  hkOstream *v99; // rax
  int v100; // edi
  int v101; // ebx
  hkOstream *v102; // rax
  hkOstream *v103; // rax
  hkOstream *v104; // rax
  hkOstream *v105; // rax
  hkOstream *v106; // rax
  hkOstream *v107; // rax
  int v108; // [rsp+48h] [rbp-80h]
  int numKnotsOut; // [rsp+4Ch] [rbp-7Ch]
  int numPointsOut[2]; // [rsp+50h] [rbp-78h]
  __int64 v111; // [rsp+58h] [rbp-70h]
  __int64 v112; // [rsp+60h] [rbp-68h]
  int track[2]; // [rsp+68h] [rbp-60h]
  float *array; // [rsp+70h] [rbp-58h]
  __int64 v115; // [rsp+78h] [rbp-50h]
  unsigned __int64 v116; // [rsp+80h] [rbp-48h]
  __int64 v117; // [rsp+88h] [rbp-40h]
  hkVector4f v118; // [rsp+98h] [rbp-30h]
  hkResult result; // [rsp+B8h] [rbp-10h]
  int degree; // [rsp+C0h] [rbp-8h]
  int v121; // [rsp+C4h] [rbp-4h]
  int v122; // [rsp+C8h] [rbp+0h]
  int v123; // [rsp+D0h] [rbp+8h]
  hkResult v124; // [rsp+D4h] [rbp+Ch]
  hkResult v125; // [rsp+D8h] [rbp+10h]
  hkResult v126; // [rsp+DCh] [rbp+14h]
  hkResult v127; // [rsp+E0h] [rbp+18h]
  hkResult v128; // [rsp+E4h] [rbp+1Ch]
  float tol; // [rsp+E8h] [rbp+20h]
  int v130; // [rsp+ECh] [rbp+24h]
  int v131; // [rsp+F0h] [rbp+28h]
  hkArray<hkVector4f,hkContainerHeapAllocator> out; // [rsp+F8h] [rbp+30h]
  hkArray<hkVector4f,hkContainerHeapAllocator> qOut; // [rsp+108h] [rbp+40h]
  hkArray<hkVector4f,hkContainerHeapAllocator> sOut; // [rsp+118h] [rbp+50h]
  hkVector4f mean; // [rsp+128h] [rbp+60h]
  float *sampleTimes; // [rsp+138h] [rbp+70h]
  int v137; // [rsp+140h] [rbp+78h]
  int v138; // [rsp+144h] [rbp+7Ch]
  __int64 v139; // [rsp+148h] [rbp+80h]
  int v140; // [rsp+150h] [rbp+88h]
  int v141; // [rsp+154h] [rbp+8Ch]
  __int64 v142; // [rsp+158h] [rbp+90h]
  int v143; // [rsp+160h] [rbp+98h]
  int v144; // [rsp+164h] [rbp+9Ch]
  __int64 v145; // [rsp+168h] [rbp+A0h]
  char v146; // [rsp+174h] [rbp+ACh]
  hkVector4f minp; // [rsp+178h] [rbp+B0h]
  hkVector4f maxp; // [rsp+188h] [rbp+C0h]
  __int128 v149; // [rsp+198h] [rbp+D0h]
  __m128 v150; // [rsp+1A8h] [rbp+E0h]
  __int128 v151; // [rsp+1B8h] [rbp+F0h]
  hkVector4f v152; // [rsp+1C8h] [rbp+100h]
  char buf; // [rsp+1D8h] [rbp+110h]
  hkaSplineCompressedAnimation *v154; // [rsp+458h] [rbp+390h]
  hkaInterleavedUncompressedAnimation *v155; // [rsp+460h] [rbp+398h]
  hkaSplineCompressedAnimation::PerTrackCompressionParams *v156; // [rsp+468h] [rbp+3A0h]
  char v157; // [rsp+470h] [rbp+3A8h]

  v4 = this;
  this->m_type.m_storage = 3;
  v5 = trackParams;
  this->m_endian = 0;
  v6 = raw;
  this->m_maxFramesPerBlock = animationParams->m_maxFramesPerBlock;
  v7 = animationParams->m_enableSampleSingleTracks.m_bool;
  v8 = raw->vfptr;
  v157 = animationParams->m_enableSampleSingleTracks.m_bool;
  v9 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *))v8[4].__vecDelDtor)(raw);
  v10 = v4->m_maxFramesPerBlock;
  v11 = 0;
  v12 = v4->m_duration;
  v13 = v9;
  v4->m_numFrames = v9;
  v14 = v10 - 1;
  v15 = v10 - 3;
  track[0] = 0;
  v16 = v4->m_numberOfTransformTracks;
  numPointsOut[1] = 0;
  v112 = 0i64;
  v17 = v12 / (float)(v13 - 1);
  v18 = (float)v14 * v17;
  v4->m_frameDuration = v17;
  v4->m_blockDuration = v18;
  v4->m_blockInverseDuration = 1.0 / v18;
  v19 = (v13 + v15) / v14;
  if ( v19 < 1 )
    v19 = 1;
  v20 = (v4->m_numberOfFloatTracks + 4 * v16 + 3) & 0xFFFFFFFC;
  v4->m_numBlocks = v19;
  v4->m_maskAndQuantizationSize = v20;
  if ( v19 > 0 )
  {
    v21 = &v4->m_data;
    v22 = &v4->m_blockOffsets;
    array = (float *)&v4->m_data;
    do
    {
      v23 = v4->m_data.m_size;
      if ( v22->m_size == (v22->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v22, 4);
      v22->m_data[v22->m_size++] = v23;
      v24 = v4->m_data.m_size;
      v25 = v4->m_numFrames;
      v26 = v25 - 1;
      v27 = v25 - v11;
      v28 = _mm_cvtsi32_si128(v26);
      if ( v4->m_maxFramesPerBlock < v27 )
        v27 = v4->m_maxFramesPerBlock;
      v29 = (float)(v4->m_duration / COERCE_FLOAT(_mm_cvtepi32_ps(v28))) * (float)(v27 - 1);
      hkaSplineCompressedAnimation::writeZeros(v4->m_maskAndQuantizationSize, v21);
      LODWORD(v30) = 0;
      v112 = v24;
      v108 = 0;
      do
      {
        if ( (_DWORD)v30 )
          v31 = v4->m_numberOfFloatTracks;
        else
          v31 = v4->m_numberOfTransformTracks;
        v32 = 1;
        if ( !(_DWORD)v30 )
          v32 = 3;
        if ( (_DWORD)v30 == 1 )
        {
          v33 = v4->m_data.m_size - v4->m_blockOffsets.m_data[v112];
          if ( v4->m_floatBlockOffsets.m_size == (v4->m_floatBlockOffsets.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v4->m_floatBlockOffsets,
              4);
            LODWORD(v30) = v108;
          }
          v4->m_floatBlockOffsets.m_data[v4->m_floatBlockOffsets.m_size++] = v33;
          v5 = v156;
        }
        v30 = (signed int)v30;
        v34 = v32;
        v35 = 0i64;
        v117 = 0i64;
        v111 = (signed int)v30;
        *(_QWORD *)track = v32;
        v145 = v31;
        if ( v31 > 0 )
        {
          while ( 1 )
          {
            if ( !v7 )
              goto LABEL_28;
            v36 = v4->m_data.m_size - v4->m_blockOffsets.m_data[v112];
            if ( v30 )
              break;
            if ( v4->m_transformOffsets.m_size == (v4->m_transformOffsets.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v4->m_transformOffsets,
                4);
              v34 = *(_QWORD *)track;
              v35 = v117;
            }
            v4->m_transformOffsets.m_data[v4->m_transformOffsets.m_size++] = v36;
            v37 = v5->m_trackIndexToPaletteIndex.m_data;
LABEL_31:
            v38 = v37[v35];
            v39 = 0;
            out.m_data = 0i64;
            out.m_size = 0;
            out.m_capacityAndFlags = 2147483648;
            qOut.m_data = 0i64;
            qOut.m_size = 0;
            v40 = (signed __int64)&v156->m_parameterPalette.m_data[v38];
            qOut.m_capacityAndFlags = 2147483648;
            sOut.m_data = 0i64;
            sOut.m_size = 0;
            sOut.m_capacityAndFlags = 2147483648;
            sampleTimes = 0i64;
            v137 = 0;
            v138 = 2147483648;
            v139 = 0i64;
            v140 = 0;
            v141 = 2147483648;
            v142 = 0i64;
            v143 = 0;
            v144 = 2147483648;
            if ( v34 > 0 )
            {
              v41 = 0i64;
              v42 = v34;
              do
              {
                v43 = *(int *)((_BYTE *)&out.m_capacityAndFlags + v41) & 0x3FFFFFFF;
                if ( v43 >= v27 )
                {
                  result.m_enum = 0;
                }
                else
                {
                  v44 = 2 * v43;
                  v45 = v27;
                  if ( v27 < v44 )
                    v45 = v44;
                  hkArrayUtil::_reserve(
                    &result,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    (char *)&out + v41,
                    v45,
                    16);
                }
                v46 = *(int *)((char *)&v138 + v41);
                *(int *)((char *)&out.m_size + v41) = v27;
                v47 = v46 & 0x3FFFFFFF;
                if ( v47 >= v27 )
                {
                  v127.m_enum = 0;
                }
                else
                {
                  v48 = 2 * v47;
                  v49 = v27;
                  if ( v27 < v48 )
                    v49 = v48;
                  hkArrayUtil::_reserve(
                    &v127,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    &(&sampleTimes)[v41 / 8],
                    v49,
                    4);
                }
                *(int *)((char *)&v137 + v41) = v27;
                hkaSplineCompressedAnimation::Linspace(
                  v27 - 1,
                  (hkArray<float,hkContainerHeapAllocator> *)&(&sampleTimes)[2 * v39++],
                  0.0,
                  v29);
                v41 += 16i64;
                --v42;
              }
              while ( v42 );
              v7 = v157;
            }
            if ( v111 )
            {
              v56 = *(float *)(v40 + 12);
              v57 = v4->m_numberOfFloatTracks;
              degree = *(unsigned __int16 *)(v40 + 22);
              tol = v56;
              hkaSplineCompressedAnimation::deinterleaveFloat(v155->m_floats.m_data, v57, v27, track[0], track[1], &out);
            }
            else
            {
              v50 = *(float *)(v40 + 4);
              v51 = *(_DWORD *)v40;
              v52 = v4->m_numberOfTransformTracks;
              degree = *(unsigned __int16 *)(v40 + 18);
              v53 = *(unsigned __int16 *)(v40 + 16);
              tol = v50;
              v54 = *(_DWORD *)(v40 + 8);
              v130 = v51;
              v121 = v53;
              v55 = *(unsigned __int16 *)(v40 + 20);
              v131 = v54;
              v122 = v55;
              hkaSplineCompressedAnimation::deinterleaveTransform(
                v155->m_transforms.m_data,
                v52,
                v27,
                track[0],
                track[1],
                &out,
                &qOut,
                &sOut);
            }
            v58 = 0;
            v59 = 0i64;
            v115 = 0i64;
            if ( *(_QWORD *)track > 0i64 )
            {
              v60 = v112;
              v116 = 0i64;
              v123 = v27 + 2 * (v27 + 1);
              while ( 1 )
              {
                v61 = 16i64 * v58;
                hkaSplineCompressedAnimation::getMean(
                  &mean,
                  (hkArray<hkVector4f,hkContainerHeapAllocator> *)((char *)&out + v61));
                hkaSplineCompressedAnimation::getMin(
                  &minp,
                  (hkArray<hkVector4f,hkContainerHeapAllocator> *)((char *)&out + v61));
                hkaSplineCompressedAnimation::getMax(
                  &maxp,
                  (hkArray<hkVector4f,hkContainerHeapAllocator> *)((char *)&out + v61));
                if ( v58 == 1 )
                {
                  v62 = _mm_mul_ps(mean.m_quad, mean.m_quad);
                  v63 = _mm_add_ps(_mm_shuffle_ps(v62, v62, 78), v62);
                  v64 = _mm_add_ps(_mm_shuffle_ps(v63, v63, 177), v63);
                  v65 = _mm_rsqrt_ps(v64);
                  mean.m_quad = _mm_mul_ps(
                                  mean.m_quad,
                                  _mm_andnot_ps(
                                    _mm_cmpleps(v64, (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v65, v64), v65)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v65))));
                }
                v66 = *(&tol + v59);
                v67 = *(&tol + v59);
                v149 = 0i64;
                _mm_store_si128((__m128i *)&v151, _mm_srli_si128(_mm_slli_si128((__m128i)query.m_quad, 4), 4));
                v150 = qi.m_vec.m_quad;
                v68 = hkaSplineCompressedAnimation::isStatic(
                        &mean,
                        &minp,
                        &maxp,
                        v67,
                        (hkVector4f *)((char *)&v149 + v61));
                if ( v111 == 1 )
                  break;
                if ( v111 )
                  goto LABEL_55;
                if ( v58 )
                {
                  *(_BYTE *)(v60 + *(_QWORD *)array) = v68;
                }
                else
                {
                  v74 = hkaSplineCompressedAnimation::packQuantizationTypes(
                          (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)*(unsigned __int8 *)(v40 + 25),
                          (hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization)*(unsigned __int8 *)(v40 + 24),
                          (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)*(unsigned __int8 *)(v40 + 26));
                  v75 = array;
                  *(_BYTE *)(++v60 + *(_QWORD *)array - 1) = v74;
                  *(_BYTE *)(v60 + *(_QWORD *)v75) = v68;
                }
LABEL_56:
                v70 = 0i64;
                v71 = 3 * v27;
                ++v60;
                v72 = 3 * v27;
                *(_QWORD *)numPointsOut = 0i64;
                v111 = 0x8000000000000000i64;
                if ( 3 * v27 )
                {
                  LODWORD(v112) = 48 * v27;
                  pointsOut = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                              (int *)&v112);
                  v72 = (signed int)v112 / 16;
                  v70 = 0i64;
                }
                else
                {
                  pointsOut = 0i64;
                }
                v76 = v123;
                v77 = 2147483648;
                if ( v72 )
                  v77 = v72;
                *(_QWORD *)numPointsOut = pointsOut;
                LODWORD(v111) = 3 * v27;
                v78 = v123;
                array = 0i64;
                v115 = 0x8000000000000000i64;
                HIDWORD(v111) = v77;
                if ( v123 )
                {
                  LODWORD(v112) = 4 * v123;
                  v79 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64 *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                          &hkContainerHeapAllocator::s_alloc,
                          &v112,
                          0i64);
                  v71 = v111;
                  pointsOut = *(hkVector4f **)numPointsOut;
                  v70 = (float *)v79;
                  v78 = (signed int)v112 / 4;
                }
                LODWORD(v115) = v76;
                v80 = 2147483648;
                if ( v78 )
                  v80 = v78;
                array = v70;
                HIDWORD(v115) = v80;
                if ( v68 & 0xF0 )
                {
                  hkaCompression::approximateNURBSCurve(
                    v27,
                    (&sampleTimes)[v116 / 8],
                    (&out.m_data)[v116 / 8],
                    *(&degree + v115),
                    v66,
                    &numKnotsOut,
                    v70,
                    numPointsOut,
                    pointsOut);
                  v81 = numKnotsOut;
                  if ( (HIDWORD(v115) & 0x3FFFFFFF) >= numKnotsOut )
                  {
                    v125.m_enum = 0;
                  }
                  else
                  {
                    v82 = numKnotsOut;
                    if ( numKnotsOut < 2 * (HIDWORD(v115) & 0x3FFFFFFF) )
                      v82 = 2 * (HIDWORD(v115) & 0x3FFFFFFF);
                    hkArrayUtil::_reserve(
                      &v125,
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      &array,
                      v82,
                      4);
                  }
                  LODWORD(v115) = v81;
                  v83 = numPointsOut[0];
                  if ( (HIDWORD(v111) & 0x3FFFFFFF) >= numPointsOut[0] )
                  {
                    v126.m_enum = 0;
                  }
                  else
                  {
                    v84 = numPointsOut[0];
                    if ( numPointsOut[0] < 2 * (HIDWORD(v111) & 0x3FFFFFFF) )
                      v84 = 2 * (HIDWORD(v111) & 0x3FFFFFFF);
                    hkArrayUtil::_reserve(
                      &v126,
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      numPointsOut,
                      v84,
                      16);
                  }
                  LODWORD(v111) = v83;
                  if ( v83 > v27 )
                  {
                    *(&degree + v115) = 1;
                    hkaCompression::approximateNURBSCurve(
                      v27,
                      (&sampleTimes)[v116 / 8],
                      (&out.m_data)[v116 / 8],
                      1,
                      v66,
                      &numKnotsOut,
                      array,
                      numPointsOut,
                      *(hkVector4f **)numPointsOut);
                    v85 = numKnotsOut;
                    if ( (HIDWORD(v115) & 0x3FFFFFFF) >= numKnotsOut )
                    {
                      v128.m_enum = 0;
                    }
                    else
                    {
                      v86 = numKnotsOut;
                      if ( numKnotsOut < 2 * (HIDWORD(v115) & 0x3FFFFFFF) )
                        v86 = 2 * (HIDWORD(v115) & 0x3FFFFFFF);
                      hkArrayUtil::_reserve(
                        &v128,
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        v86,
                        4);
                    }
                    LODWORD(v115) = v85;
                    v83 = numPointsOut[0];
                    if ( (HIDWORD(v111) & 0x3FFFFFFF) >= numPointsOut[0] )
                    {
                      v124.m_enum = 0;
                    }
                    else
                    {
                      v87 = numPointsOut[0];
                      if ( numPointsOut[0] < 2 * (HIDWORD(v111) & 0x3FFFFFFF) )
                        v87 = 2 * (HIDWORD(v111) & 0x3FFFFFFF);
                      hkArrayUtil::_reserve(
                        &v124,
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        numPointsOut,
                        v87,
                        16);
                    }
                    LODWORD(v111) = v83;
                  }
                  hkaSplineCompressedAnimation::writeKnots(
                    v154,
                    v83 - 1,
                    v115 - v83 - 1,
                    (hkArray<float,hkContainerHeapAllocator> *)&array);
                  v71 = v111;
                }
                if ( v58 == 1 )
                {
                  hkaSplineCompressedAnimation::writeRotation(
                    v154,
                    v68,
                    (hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization)*(unsigned __int8 *)(v40 + 24),
                    &mean,
                    v71 - 1,
                    (hkArray<hkVector4f,hkContainerHeapAllocator> *)numPointsOut);
                }
                else
                {
                  if ( v68 & 0xF0 )
                  {
                    minp.m_quad = hkaSplineCompressedAnimation::getMin(
                                    &v152,
                                    (hkArray<hkVector4f,hkContainerHeapAllocator> *)numPointsOut)->m_quad;
                    maxp.m_quad = hkaSplineCompressedAnimation::getMax(
                                    &v118,
                                    (hkArray<hkVector4f,hkContainerHeapAllocator> *)numPointsOut)->m_quad;
                  }
                  if ( v111 )
                  {
                    v89 = *(unsigned __int8 *)(v40 + 27);
                  }
                  else
                  {
                    v88 = (unsigned __int8 *)(v40 + 25);
                    if ( v58 )
                      v88 = (unsigned __int8 *)(v40 + 26);
                    v89 = *v88;
                  }
                  hkaSplineCompressedAnimation::writePoints(
                    v154,
                    v68,
                    v89,
                    &mean,
                    &minp,
                    &maxp,
                    v71 - 1,
                    (hkArray<hkVector4f,hkContainerHeapAllocator> *)numPointsOut);
                }
                hkaSplineCompressedAnimation::writeAlign(4, (hkArray<unsigned char,hkContainerHeapAllocator> *)array);
                LODWORD(v115) = 0;
                if ( v115 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    array,
                    4 * HIDWORD(v115));
                array = 0i64;
                HIDWORD(v115) = 2147483648;
                LODWORD(v111) = 0;
                if ( v111 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    *(void **)numPointsOut,
                    16 * HIDWORD(v111));
                v116 += 16i64;
                ++v58;
                v59 = v115 + 1;
                *(_QWORD *)numPointsOut = 0i64;
                HIDWORD(v111) = 2147483648;
                v115 = v59;
                if ( v59 >= *(_QWORD *)track )
                {
                  v112 = v60;
                  v7 = v157;
                  goto LABEL_109;
                }
              }
              if ( !v68 )
                v68 = v111;
LABEL_55:
              v69 = hkaSplineCompressedAnimation::packMaskAndQuantizationType(
                      v68,
                      (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)*(unsigned __int8 *)(v40 + 27));
              *(_BYTE *)(v60 + *(_QWORD *)array) = v69;
              goto LABEL_56;
            }
LABEL_109:
            v90 = 2;
            v91 = &v146;
            do
            {
              v92 = *((_DWORD *)v91 - 4);
              v91 -= 16;
              *((_DWORD *)v91 - 1) = 0;
              if ( v92 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  *(void **)(v91 - 12),
                  4 * v92);
              --v90;
              *(_QWORD *)(v91 - 12) = 0i64;
              *(_DWORD *)v91 = 2147483648;
            }
            while ( v90 >= 0 );
            v93 = 2;
            v94 = &mean.m_quad.m128_i32[3];
            do
            {
              v95 = *(v94 - 4);
              v94 -= 4;
              *(v94 - 1) = 0;
              if ( v95 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  *(void **)(v94 - 3),
                  16 * v95);
              --v93;
              *(_QWORD *)(v94 - 3) = 0i64;
              *v94 = 2147483648;
            }
            while ( v93 >= 0 );
            ++track[1];
            v4 = v154;
            v30 = v111;
            v34 = *(_QWORD *)track;
            v5 = v156;
            v35 = v117 + 1;
            v117 = v35;
            if ( v35 >= v145 )
              goto LABEL_118;
          }
          if ( v4->m_floatOffsets.m_size == (v4->m_floatOffsets.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v4->m_floatOffsets,
              4);
            v30 = v111;
            v34 = *(_QWORD *)track;
            v35 = v117;
          }
          v4->m_floatOffsets.m_data[v4->m_floatOffsets.m_size++] = v36;
LABEL_28:
          if ( v30 )
            v37 = v5->m_floatTrackIndexToPaletteIndex.m_data;
          else
            v37 = v5->m_trackIndexToPaletteIndex.m_data;
          goto LABEL_31;
        }
LABEL_118:
        v5 = v156;
        LODWORD(v30) = v108 + 1;
        v108 = v30;
      }
      while ( (signed int)v30 < 2 );
      v21 = &v4->m_data;
      v11 = v27 + track[0] - 1;
      track[0] = v27 + track[0] - 1;
      hkaSplineCompressedAnimation::writeAlign(16, &v4->m_data);
      ++v112;
      v22 = &v4->m_blockOffsets;
      ++numPointsOut[1];
    }
    while ( numPointsOut[1] < v4->m_numBlocks );
    v6 = v155;
  }
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    907120276i64,
    "Compression");
  hkErrStream::hkErrStream((hkErrStream *)&v118, &buf, 512);
  v96 = hkOstream::operator<<((hkOstream *)&v118, "Number of blocks: ");
  hkOstream::operator<<(v96, v4->m_numBlocks);
  hkError::messageReport(-1, &buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimationCtor.cpp", 381);
  hkOstream::~hkOstream((hkOstream *)&v118);
  hkErrStream::hkErrStream((hkErrStream *)&v118, &buf, 512);
  v97 = ((__int64 (__fastcall *)(hkaSplineCompressedAnimation *))v4->vfptr[5].__first_virtual_table_function__)(v4);
  v98 = hkOstream::operator<<((hkOstream *)&v118, "Size of largest block (PlayStation(R)3 SPU): ");
  v99 = hkOstream::operator<<(v98, v97);
  hkOstream::operator<<(v99, " bytes.");
  hkError::messageReport(-1, &buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimationCtor.cpp", 382);
  hkOstream::~hkOstream((hkOstream *)&v118);
  v100 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *))v6->vfptr[3].__first_virtual_table_function__)(v6);
  v101 = ((__int64 (__fastcall *)(hkaSplineCompressedAnimation *))v4->vfptr[3].__first_virtual_table_function__)(v4);
  hkErrStream::hkErrStream((hkErrStream *)&v118, &buf, 512);
  v102 = hkOstream::operator<<((hkOstream *)&v118, "Original Size: ");
  v103 = hkOstream::operator<<(v102, v100);
  v104 = hkOstream::operator<<(v103, " bytes. Compressed Size: ");
  v105 = hkOstream::operator<<(v104, v101);
  hkOstream::operator<<(v105, " bytes.");
  hkError::messageReport(-1, &buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimationCtor.cpp", 388);
  hkOstream::~hkOstream((hkOstream *)&v118);
  hkErrStream::hkErrStream((hkErrStream *)&v118, &buf, 512);
  v106 = hkOstream::operator<<((hkOstream *)&v118, "Compression Ratio: ");
  v107 = hkOstream::operator<<(v106, (float)v100 / (float)v101);
  hkOstream::operator<<(v107, ":1.");
  hkError::messageReport(-1, &buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimationCtor.cpp", 389);
  hkOstream::~hkOstream((hkOstream *)&v118);
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
}

// File Line: 404
// RVA: 0xB3D910
void __fastcall hkaSplineCompressedAnimation::deinterleaveTransform(hkQsTransformf *xform, int numTracks, int numFrames, int offset, int track, hkArray<hkVector4f,hkContainerHeapAllocator> *tOut, hkArray<hkVector4f,hkContainerHeapAllocator> *qOut, hkArray<hkVector4f,hkContainerHeapAllocator> *sOut)
{
  hkQsTransformf *v8; // rdi
  __int64 v9; // r10
  __int64 v10; // r8
  int v11; // eax
  __int64 v12; // rcx

  v8 = xform;
  v9 = numFrames;
  if ( numFrames > 0 )
  {
    v10 = 0i64;
    v11 = track + offset * numTracks;
    do
    {
      v12 = v11;
      v11 += numTracks;
      ++v10;
      tOut->m_data[v10 - 1] = v8[v12].m_translation;
      tOut->m_data[v10 - 1] = (hkVector4f)_mm_srli_si128(
                                            _mm_slli_si128(_mm_load_si128((const __m128i *)&tOut->m_data[v10 - 1]), 4),
                                            4);
      qOut->m_data[v10 - 1] = (hkVector4f)v8[v12].m_rotation;
      sOut->m_data[v10 - 1] = v8[v12].m_scale;
      sOut->m_data[v10 - 1] = (hkVector4f)_mm_srli_si128(
                                            _mm_slli_si128(_mm_load_si128((const __m128i *)&sOut->m_data[v10 - 1]), 4),
                                            4);
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 431
// RVA: 0xB3D9E0
void __fastcall hkaSplineCompressedAnimation::deinterleaveFloat(const float *data, int numTracks, int numFrames, int offset, int track, hkArray<hkVector4f,hkContainerHeapAllocator> *out)
{
  __int64 v6; // r11
  __int64 v7; // r10
  int v8; // er8
  __int64 v9; // rax
  float v10; // xmm1_4
  hkVector4f v11; // xmm0

  v6 = numFrames;
  if ( numFrames > 0 )
  {
    v7 = 0i64;
    v8 = track + offset * numTracks;
    do
    {
      v9 = v8;
      v8 += numTracks;
      ++v7;
      v10 = data[v9];
      out->m_data[v7 - 1] = 0i64;
      v11.m_quad = (__m128)out->m_data[v7 - 1];
      v11.m_quad.m128_f32[0] = v10;
      out->m_data[v7 - 1] = (hkVector4f)v11.m_quad;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 451
// RVA: 0xB3DC70
__int64 __usercall hkaSplineCompressedAnimation::isStatic@<rax>(hkVector4f *mean@<rcx>, hkVector4f *minp@<rdx>, hkVector4f *maxp@<r8>, float tol@<xmm3>, __m128 a5@<xmm4>, hkVector4f *I)
{
  unsigned __int8 v6; // r10
  signed int v7; // er9
  __m128 v8; // xmm4
  __m128i v9; // xmm0
  signed int v10; // er8
  int v11; // ebx
  int v12; // er11

  a5.m128_f32[0] = tol;
  v6 = 0;
  v7 = 0;
  v8 = _mm_shuffle_ps(a5, a5, 0);
  v9 = (__m128i)_mm_sub_ps(mean->m_quad, maxp->m_quad);
  v10 = 1;
  v11 = _mm_movemask_ps(_mm_cmpltps(v8, (__m128)_mm_srli_epi32(
                                                  _mm_slli_epi32((__m128i)_mm_sub_ps(mean->m_quad, I->m_quad), 1u),
                                                  1u)));
  v12 = _mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(mean->m_quad, minp->m_quad), 1u), 1u),
              v8),
            _mm_cmpleps((__m128)_mm_srli_epi32(_mm_slli_epi32(v9, 1u), 1u), v8)));
  do
  {
    if ( v10 & v12 )
    {
      if ( v10 & v11 )
        v6 |= 1 << v7;
    }
    else
    {
      v6 |= 1 << (v7 + 4);
    }
    v10 = __ROL4__(v10, 1);
    ++v7;
  }
  while ( v7 < 4 );
  return v6;
}

// File Line: 526
// RVA: 0xB3C430
void __fastcall hkaSplineCompressedAnimation::writeRotation(hkaSplineCompressedAnimation *this, char mask, hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type, hkVector4f *mean, int n, hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  hkVector4f *v6; // r15
  hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization v7; // edi
  hkaSplineCompressedAnimation *v8; // rbp
  __int64 v9; // rsi
  int v10; // ebx
  signed __int64 v11; // r15
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  int v17; // ebx
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  hkQuaternionf in; // [rsp+20h] [rbp-48h]

  v6 = mean;
  v7 = type;
  v8 = this;
  if ( mask & 0xF0 )
  {
    hkaSplineCompressedAnimation::writeAlignQuaternion(type, &this->m_data);
    v9 = 0i64;
    switch ( v7 )
    {
      case 0:
        v10 = 4;
        break;
      case 1:
        v10 = 5;
        break;
      case 2:
        v10 = 6;
        break;
      case 3:
        v10 = 3;
        break;
      case 4:
        v10 = 2;
        break;
      case 5:
        v10 = 16;
        break;
      default:
        v10 = 0;
        break;
    }
    if ( n >= 0i64 )
    {
      v11 = n + 1i64;
      do
      {
        v12 = P->m_data[v9].m_quad;
        v13 = _mm_mul_ps(v12, v12);
        v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
        v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
        v16 = _mm_rsqrt_ps(v15);
        in.m_vec.m_quad = _mm_mul_ps(
                            v12,
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                              _mm_mul_ps(*(__m128 *)_xmm, v16)));
        hkaSplineCompressedAnimation::writeZeros(v10, &v8->m_data);
        hkaSplineCompressedAnimation::packQuaternion(v7, &in, &v8->m_data.m_data[v8->m_data.m_size - v10]);
        ++v9;
        --v11;
      }
      while ( v11 );
    }
  }
  else if ( mask & 0xF )
  {
    hkaSplineCompressedAnimation::writeAlignQuaternion(type, &this->m_data);
    switch ( v7 )
    {
      case 0:
        v17 = 4;
        break;
      case 1:
        v17 = 5;
        break;
      case 2:
        v17 = 6;
        break;
      case 3:
        v17 = 3;
        break;
      case 4:
        v17 = 2;
        break;
      case 5:
        v17 = 16;
        break;
      default:
        v17 = 0;
        break;
    }
    v18 = _mm_mul_ps(v6->m_quad, v6->m_quad);
    v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
    v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
    v21 = _mm_rsqrt_ps(v20);
    in.m_vec.m_quad = _mm_mul_ps(
                        v6->m_quad,
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                          _mm_mul_ps(*(__m128 *)_xmm, v21)));
    hkaSplineCompressedAnimation::writeZeros(v17, &v8->m_data);
    hkaSplineCompressedAnimation::packQuaternion(v7, &in, &v8->m_data.m_data[v8->m_data.m_size - v17]);
  }
}

// File Line: 575
// RVA: 0xB3C6B0
void __fastcall hkaSplineCompressedAnimation::writePoints(hkaSplineCompressedAnimation *this, char mask, hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization type, hkVector4f *mean, hkVector4f *minp, hkVector4f *maxp, int n, hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *v8; // rbp
  int v9; // er13
  hkVector4f *v10; // r14
  signed int v11; // ebx
  signed __int64 v12; // r14
  hkVector4f *v13; // rdi
  signed __int64 v14; // rsi
  float v15; // xmm0_4
  hkVector4f *v16; // rcx
  signed __int64 v17; // rdx
  __int64 v18; // r14
  signed int v19; // ebx
  hkVector4f *v20; // rdi
  signed __int64 v21; // rsi
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  char v25; // al
  unsigned __int16 v26; // ax
  signed __int64 v27; // [rsp+60h] [rbp+8h]
  hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization v28; // [rsp+70h] [rbp+18h]
  hkVector4f *maxpa; // [rsp+88h] [rbp+30h]

  v28 = type;
  v8 = &this->m_data;
  v9 = (unsigned __int8)mask;
  v10 = mean;
  hkaSplineCompressedAnimation::writeAlign(4, &this->m_data);
  v11 = 1;
  v12 = (char *)v10 - (char *)maxp;
  v13 = maxp;
  v14 = 3i64;
  do
  {
    if ( __ROL4__(v11, 4) & v9 )
    {
      hkaSplineCompressedAnimation::writeReal(
        *(float *)((char *)v13->m_quad.m128_f32 + (char *)minp - (char *)maxp),
        v8);
      v15 = v13->m_quad.m128_f32[0];
    }
    else
    {
      if ( !(v9 & v11) )
        goto LABEL_7;
      v15 = *(float *)((char *)v13->m_quad.m128_f32 + v12);
    }
    hkaSplineCompressedAnimation::writeReal(v15, v8);
LABEL_7:
    v11 = __ROL4__(v11, 1);
    v13 = (hkVector4f *)((char *)v13 + 4);
    --v14;
  }
  while ( v14 );
  if ( v9 & 0xF0 && n >= 0i64 )
  {
    v16 = minp;
    v17 = (char *)maxp - (char *)minp;
    v18 = 0i64;
    maxpa = (hkVector4f *)((char *)maxp - (char *)minp);
    v27 = n + 1i64;
    do
    {
      v19 = 1;
      v20 = v16;
      v21 = 3i64;
      do
      {
        if ( __ROL4__(v19, 4) & v9 )
        {
          v22 = *(float *)((char *)v20->m_quad.m128_f32 + v17);
          v23 = v20->m_quad.m128_f32[0];
          v24 = *(float *)((char *)P->m_data[v18].m_quad.m128_f32 + (char *)v20 - (char *)minp);
          if ( v28 )
          {
            v26 = hkaSplineCompressedAnimation::pack16(v23, v22, v24);
            hkaSplineCompressedAnimation::write16(v26, v8);
          }
          else
          {
            v25 = hkaSplineCompressedAnimation::pack8(v23, v22, v24);
            hkaSplineCompressedAnimation::write8(v25, v8);
          }
          v17 = (signed __int64)maxpa;
        }
        v19 = __ROL4__(v19, 1);
        v20 = (hkVector4f *)((char *)v20 + 4);
        --v21;
      }
      while ( v21 );
      v16 = minp;
      ++v18;
      --v27;
    }
    while ( v27 );
  }
}

// File Line: 626
// RVA: 0xB3DD20
hkVector4f *__fastcall hkaSplineCompressedAnimation::getMean(hkVector4f *result, hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  hkVector4f *v2; // rax
  signed __int64 v3; // r8
  __m128 *v4; // rax
  signed __int64 v5; // rdx
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  hkVector4f *v8; // rax
  __m128 v9; // xmm2
  __m128 v10; // xmm0

  v2 = P->m_data;
  v3 = P->m_size;
  _mm_store_si128((__m128i *)result, (__m128i)P->m_data->m_quad);
  if ( v3 > 1 )
  {
    v4 = &v2[1].m_quad;
    v5 = v3 - 1;
    do
    {
      v6 = *v4;
      ++v4;
      result->m_quad = _mm_add_ps(v6, result->m_quad);
      --v5;
    }
    while ( v5 );
  }
  v7 = 0i64;
  v7.m128_f32[0] = (float)(signed int)v3;
  v8 = result;
  v9 = _mm_shuffle_ps(v7, v7, 0);
  v10 = _mm_rcp_ps(v9);
  result->m_quad = _mm_mul_ps(result->m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v10)), v10));
  return v8;
}

// File Line: 646
// RVA: 0xB3DD90
hkVector4f *__fastcall hkaSplineCompressedAnimation::getMin(hkVector4f *result, hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  __m128i *v2; // rax
  signed __int64 v3; // rdx
  signed __int64 v4; // rax
  signed __int64 v5; // rdx

  v2 = (__m128i *)P->m_data;
  v3 = P->m_size;
  _mm_store_si128((__m128i *)result, *v2);
  if ( v3 > 1 )
  {
    v4 = (signed __int64)v2[1].m128i_i64;
    v5 = v3 - 1;
    do
    {
      v4 += 16i64;
      result->m_quad = _mm_min_ps(result->m_quad, *(__m128 *)(v4 - 16));
      --v5;
    }
    while ( v5 );
  }
  return result;
}

// File Line: 663
// RVA: 0xB3DDD0
hkVector4f *__fastcall hkaSplineCompressedAnimation::getMax(hkVector4f *result, hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  __m128i *v2; // rax
  signed __int64 v3; // rdx
  signed __int64 v4; // rax
  signed __int64 v5; // rdx

  v2 = (__m128i *)P->m_data;
  v3 = P->m_size;
  _mm_store_si128((__m128i *)result, *v2);
  if ( v3 > 1 )
  {
    v4 = (signed __int64)v2[1].m128i_i64;
    v5 = v3 - 1;
    do
    {
      v4 += 16i64;
      result->m_quad = _mm_max_ps(result->m_quad, *(__m128 *)(v4 - 16));
      --v5;
    }
    while ( v5 );
  }
  return result;
}

// File Line: 683
// RVA: 0xB3C320
void __fastcall hkaSplineCompressedAnimation::writeKnots(hkaSplineCompressedAnimation *this, int n, int p, hkArray<float,hkContainerHeapAllocator> *U)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *v4; // rsi
  hkaSplineCompressedAnimation *v5; // rdi
  hkArray<float,hkContainerHeapAllocator> *v6; // r14
  char v7; // bl
  int v8; // ebp
  __m128 v9; // xmm6
  __m128 v10; // xmm0
  __m128 v11; // xmm6
  __int64 v12; // rbx
  __int64 v13; // rdi
  char v14; // bp

  v4 = &this->m_data;
  v5 = this;
  v6 = U;
  v7 = p;
  v8 = p + n + 1;
  hkaSplineCompressedAnimation::write16(n, &this->m_data);
  hkaSplineCompressedAnimation::write8(v7, v4);
  v9 = 0i64;
  v10 = _mm_shuffle_ps((__m128)LODWORD(v5->m_duration), (__m128)LODWORD(v5->m_duration), 0);
  v9.m128_f32[0] = (float)(v5->m_numFrames - 1);
  v11 = _mm_mul_ps(
          _mm_shuffle_ps(v9, v9, 0),
          _mm_andnot_ps(_mm_cmpeqps((__m128)0i64, v10), _mm_div_ps(query.m_quad, v10)));
  if ( v8 >= 0 )
  {
    v12 = 0i64;
    v13 = (unsigned int)(v8 + 1);
    do
    {
      v14 = _mm_cvtsi128_si32(
              _mm_cvttps_epi32(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v6->m_data[v12]), (__m128)LODWORD(v6->m_data[v12]), 0), v11),
                  (__m128)xmmword_141A711B0)));
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 1);
      ++v12;
      v4->m_data[v4->m_size++] = v14;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 717
// RVA: 0xB3C110
void __fastcall hkaSplineCompressedAnimation::write8(char i, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *v2; // rbx
  char v3; // di

  v2 = data;
  v3 = i;
  if ( data->m_size == (data->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, data, 1);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 725
// RVA: 0xB3C160
void __fastcall hkaSplineCompressedAnimation::write16(unsigned __int16 i, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  unsigned __int16 v2; // di
  hkArray<unsigned char,hkContainerHeapAllocator> *v3; // rbx

  v2 = i;
  v3 = data;
  hkaSplineCompressedAnimation::writeZeros(2, data);
  *(_WORD *)&v3->m_data[v3->m_size - 2] = v2;
}

// File Line: 738
// RVA: 0xB3C1A0
void __fastcall hkaSplineCompressedAnimation::writeReal(float f, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *v2; // rbx

  v2 = data;
  hkaSplineCompressedAnimation::writeZeros(4, data);
  *(float *)&v2->m_data[v2->m_size - 4] = f;
}

// File Line: 752
// RVA: 0xB3C1E0
void __fastcall hkaSplineCompressedAnimation::writeZeros(int n, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *v2; // rbx
  __int64 v3; // rdi

  if ( n > 0 )
  {
    v2 = data;
    v3 = (unsigned int)n;
    do
    {
      if ( v2->m_size == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 1);
      v2->m_data[v2->m_size++] = 0;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 763
// RVA: 0xB3C240
void __fastcall hkaSplineCompressedAnimation::writeAlign(int align, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  int v2; // edi
  hkArray<unsigned char,hkContainerHeapAllocator> *i; // rbx

  v2 = align - 1;
  for ( i = data; v2 & i->m_size; ++i->m_size )
  {
    if ( i->m_size == (i->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, i, 1);
    i->m_data[i->m_size] = 0;
  }
}

// File Line: 778
// RVA: 0xB3C2B0
void __fastcall hkaSplineCompressedAnimation::writeAlignQuaternion(hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *v2; // rbx
  const int *v3; // rdi

  v2 = data;
  v3 = &s_writeAlignQuaternion_mask[type];
  if ( data->m_size & *v3 )
  {
    do
    {
      if ( v2->m_size == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 1);
      v2->m_data[v2->m_size++] = 0;
    }
    while ( v2->m_size & *v3 );
  }
}

// File Line: 792
// RVA: 0xB3DA50
__int64 __fastcall hkaSplineCompressedAnimation::packQuantizationTypes(hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization translation, hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization rotation, hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization scale)
{
  return (unsigned __int8)(translation | 4 * (rotation | 16 * scale));
}

// File Line: 804
// RVA: 0xB3DA70
__int64 __fastcall hkaSplineCompressedAnimation::packMaskAndQuantizationType(int mask, hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization floatQuatization)
{
  return mask | 2 * (unsigned int)(unsigned __int8)floatQuatization;
}

// File Line: 818
// RVA: 0xB3DB70
void __fastcall hkaSplineCompressedAnimation::packQuaternion(hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type, hkQuaternionf *in, char *out)
{
  switch ( type )
  {
    case 0:
      hkaSignedQuaternion::packSignedQuaternion32(in, out);
      break;
    case 1:
      hkaSignedQuaternion::packSignedQuaternion40(in, out);
      break;
    case 2:
      hkaSignedQuaternion::packSignedQuaternion48(in, out);
      break;
    case 3:
      hkaSignedQuaternion::packSignedQuaternion24(in, out);
      break;
    case 4:
      hkaSignedQuaternion::packSignedQuaternion16(in, out);
      break;
    case 5:
      hkaSignedQuaternion::packSignedQuaternion128(in, out);
      break;
    default:
      return;
  }
}

// File Line: 843
// RVA: 0xB3DA80
__int64 __fastcall hkaSplineCompressedAnimation::pack8(float minp, float maxp, float val)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  float v8; // [rsp+18h] [rbp+18h]

  v8 = val;
  v3 = _mm_shuffle_ps((__m128)LODWORD(maxp), (__m128)LODWORD(maxp), 0);
  v4 = _mm_shuffle_ps((__m128)LODWORD(minp), (__m128)LODWORD(minp), 0);
  v5 = _mm_sub_ps(v3, v4);
  v6 = _mm_rcp_ps(v5);
  return (unsigned int)_mm_cvtsi128_si32(
                         _mm_cvttps_epi32(
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v5, v6)), v6),
                               _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v8), (__m128)LODWORD(v8), 0), v4)),
                             (__m128)xmmword_141A71160)));
}

// File Line: 863
// RVA: 0xB3DAF0
__int64 __fastcall hkaSplineCompressedAnimation::pack16(float minp, float maxp, float val)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  float v8; // [rsp+18h] [rbp+18h]

  v8 = val;
  v3 = _mm_shuffle_ps((__m128)LODWORD(maxp), (__m128)LODWORD(maxp), 0);
  v4 = _mm_shuffle_ps((__m128)LODWORD(minp), (__m128)LODWORD(minp), 0);
  v5 = _mm_sub_ps(v3, v4);
  v6 = _mm_rcp_ps(v5);
  return (unsigned int)_mm_cvtsi128_si32(
                         _mm_cvttps_epi32(
                           _mm_min_ps(
                             _mm_max_ps(
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v5, v6)), v6),
                                   _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v8), (__m128)LODWORD(v8), 0), v4)),
                                 _mm_shuffle_ps((__m128)LODWORD(FLOAT_65535_0), (__m128)LODWORD(FLOAT_65535_0), 0)),
                               (__m128)0i64),
                             (__m128)_xmm)));
}

// File Line: 882
// RVA: 0xB3DF50
void __fastcall hkaSplineCompressedAnimation::reverseEndian(int bytes, char **dataInOut)
{
  __int64 v2; // r10
  char **v3; // r11
  char *v4; // r9
  char v5; // r8
  char *v6; // rdx
  char v7; // cl
  char *v8; // rdx
  char v9; // cl
  char *v10; // rdx
  char v11; // cl
  char *v12; // rdx
  char v13; // cl
  char *v14; // rdx
  char v15; // cl
  char *v16; // rdx
  char v17; // cl

  v2 = bytes;
  v3 = dataInOut;
  if ( bytes != 1 )
  {
    switch ( bytes )
    {
      case 2:
        v4 = *dataInOut;
        v5 = **dataInOut;
        *v4 = (*dataInOut)[1];
        v4[1] = v5;
        *dataInOut += 2;
        return;
      case 4:
        v6 = *dataInOut;
        v7 = *v6;
        *v6 = v6[3];
        v6[3] = v7;
        v8 = *v3;
        v9 = (*v3)[1];
        v8[1] = (*v3)[2];
        v8[2] = v9;
        *v3 += v2;
        return;
      case 8:
        v10 = *dataInOut;
        v11 = *v10;
        *v10 = v10[7];
        v10[7] = v11;
        v12 = *v3;
        v13 = (*v3)[1];
        v12[1] = (*v3)[6];
        v12[6] = v13;
        v14 = *v3;
        v15 = (*v3)[2];
        v14[2] = (*v3)[5];
        v14[5] = v15;
        v16 = *v3;
        v17 = (*v3)[3];
        v16[3] = (*v3)[4];
        v16[4] = v17;
        break;
    }
  }
  *v3 += v2;
}

// File Line: 916
// RVA: 0xB3DC00
void __fastcall hkaSplineCompressedAnimation::handleEndianQuaternion(hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type, char *dataInOut)
{
  switch ( type )
  {
    case 0:
      hkaSignedQuaternion::handleEndianSignedQuaternion32(dataInOut);
      break;
    case 1:
      hkaSignedQuaternion::handleEndianSignedQuaternion40(dataInOut);
      break;
    case 2:
      hkaSignedQuaternion::handleEndianSignedQuaternion48(dataInOut);
      break;
    case 3:
      hkaSignedQuaternion::handleEndianSignedQuaternion24(dataInOut);
      break;
    case 4:
      hkaSignedQuaternion::handleEndianSignedQuaternion16(dataInOut);
      break;
    case 5:
      hkaSignedQuaternion::handleEndianSignedQuaternion128(dataInOut);
      break;
    default:
      return;
  }
}

// File Line: 934
// RVA: 0xB3DE10
void __fastcall hkaSplineCompressedAnimation::handleEndian(hkaSplineCompressedAnimation *this)
{
  hkaSplineCompressedAnimation *v1; // rsi
  int v2; // er14
  __int64 v3; // r15
  int v4; // ebp
  char *v5; // rbx
  unsigned int v6; // edi
  int i; // edi
  unsigned int v8; // ecx
  char *dataInOut; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( this->m_endian )
  {
    v2 = 0;
    if ( this->m_numBlocks > 0 )
    {
      v3 = 0i64;
      do
      {
        v4 = 0;
        v5 = &v1->m_data.m_data[v1->m_blockOffsets.m_data[v3]];
        for ( dataInOut = &v5[v1->m_maskAndQuantizationSize]; v4 < v1->m_numberOfTransformTracks; v5 += 4 )
        {
          v6 = (unsigned __int8)*v5;
          hkaSplineCompressedAnimation::handleEndianScalar(
            v5[1],
            (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)(*v5 & 3),
            &dataInOut);
          hkaSplineCompressedAnimation::handleEndianRotation(
            v5[2],
            (hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization)((v6 >> 2) & 0xF),
            &dataInOut);
          hkaSplineCompressedAnimation::handleEndianScalar(
            v5[3],
            (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)(v6 >> 6),
            &dataInOut);
          ++v4;
        }
        for ( i = 0; i < v1->m_numberOfFloatTracks; ++i )
        {
          v8 = (unsigned __int8)*v5++;
          hkaSplineCompressedAnimation::handleEndianScalar(
            v8 & 0xF9,
            (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)((v8 >> 1) & 3),
            &dataInOut);
        }
        ++v2;
        ++v3;
      }
      while ( v2 < v1->m_numBlocks );
    }
    v1->m_endian = 0;
  }
}

// File Line: 990
// RVA: 0xB3E000
void __fastcall hkaSplineCompressedAnimation::handleEndianScalar(char mask, hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization type, char **dataInOut)
{
  hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization v3; // esi
  char **v4; // rdi
  char v5; // bl
  int v6; // eax

  if ( mask )
  {
    v3 = type;
    v4 = dataInOut;
    v5 = mask;
    v6 = hkaSplineCompressedAnimation::handleEndianKnots(mask, dataInOut);
    hkaSplineCompressedAnimation::handleEndianScalarControlPoints(v5, v6, v3, v4);
    *v4 = (char *)((unsigned __int64)(*v4 + 3) & 0xFFFFFFFFFFFFFFFCui64);
  }
}

// File Line: 1009
// RVA: 0xB3E060
void __fastcall hkaSplineCompressedAnimation::handleEndianRotation(char mask, hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type, char **dataInOut)
{
  hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization v3; // esi
  char **v4; // rdi
  char v5; // bl
  int v6; // eax

  if ( mask )
  {
    v3 = type;
    v4 = dataInOut;
    v5 = mask;
    v6 = hkaSplineCompressedAnimation::handleEndianKnots(mask, dataInOut);
    hkaSplineCompressedAnimation::handleEndianRotationControlPoints(v5, v6, v3, v4);
    *v4 = (char *)((unsigned __int64)(*v4 + 3) & 0xFFFFFFFFFFFFFFFCui64);
  }
}

// File Line: 1028
// RVA: 0xB3E0C0
signed __int64 __fastcall hkaSplineCompressedAnimation::handleEndianKnots(char mask, char **dataInOut)
{
  char **v2; // rbx
  signed __int64 result; // rax

  v2 = dataInOut;
  if ( !(mask & 0xF0) )
    return 0xFFFFFFFFi64;
  hkaSplineCompressedAnimation::reverseEndian(2, dataInOut);
  result = *((unsigned __int16 *)*v2 - 1);
  *v2 += (signed int)(result + (unsigned __int8)**v2 + 2) + 1;
  return result;
}

// File Line: 1063
// RVA: 0xB3E110
void __fastcall hkaSplineCompressedAnimation::handleEndianScalarControlPoints(char mask, int n, hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization type, char **dataInOut)
{
  int v4; // esi
  char **v5; // rdi
  hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization v6; // er12
  int v7; // er13
  signed __int64 v8; // r15
  unsigned int v9; // ebp
  signed int v10; // ebx
  int v11; // er14
  __int64 v12; // r14
  __int64 v13; // rbx

  if ( mask )
  {
    v4 = 0;
    v5 = dataInOut;
    v6 = type;
    v7 = n;
    v8 = 3i64;
    *dataInOut = (char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
    v9 = 0;
    v10 = 1;
    v11 = (unsigned __int8)mask;
    do
    {
      if ( __ROL4__(v10, 4) & v11 )
      {
        hkaSplineCompressedAnimation::reverseEndian(4, v5);
        hkaSplineCompressedAnimation::reverseEndian(4, v5);
        ++v9;
      }
      else if ( v11 & v10 )
      {
        hkaSplineCompressedAnimation::reverseEndian(4, v5);
      }
      v10 = __ROL4__(v10, 1);
      --v8;
    }
    while ( v8 );
    if ( v9 && v7 >= 0 )
    {
      v12 = (unsigned int)(v7 + 1);
      do
      {
        if ( (signed int)v9 > 0 )
        {
          v13 = v9;
          do
          {
            LOBYTE(v4) = v6 != 0;
            hkaSplineCompressedAnimation::reverseEndian(v4 + 1, v5);
            --v13;
          }
          while ( v13 );
        }
        --v12;
      }
      while ( v12 );
    }
  }
}

// File Line: 1119
// RVA: 0xB3E210
void __fastcall hkaSplineCompressedAnimation::handleEndianRotationControlPoints(char mask, int n, hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type, char **dataInOut)
{
  hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization v4; // edi
  char **v5; // rbx
  char *v6; // rax
  __int64 v7; // rbp
  signed int v8; // eax
  signed int v9; // esi

  if ( mask )
  {
    v4 = type;
    v5 = dataInOut;
    switch ( type )
    {
      case 0:
      case 5:
        v6 = (char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
        goto LABEL_5;
      case 2:
      case 4:
        v6 = (char *)((unsigned __int64)(*dataInOut + 1) & 0xFFFFFFFFFFFFFFFEui64);
LABEL_5:
        *dataInOut = v6;
        break;
      default:
        break;
    }
    if ( mask & 0xF0 )
    {
      if ( n >= 0 )
      {
        v7 = (unsigned int)(n + 1);
        do
        {
          hkaSplineCompressedAnimation::handleEndianQuaternion(v4, *v5);
          switch ( v4 )
          {
            case 0:
              v8 = 4;
              break;
            case 1:
              v8 = 5;
              break;
            case 2:
              v8 = 6;
              break;
            case 3:
              v8 = 3;
              break;
            case 4:
              v8 = 2;
              break;
            case 5:
              v8 = 16;
              break;
            default:
              v8 = 0;
              break;
          }
          *v5 += v8;
          --v7;
        }
        while ( v7 );
      }
    }
    else
    {
      hkaSplineCompressedAnimation::handleEndianQuaternion(type, *dataInOut);
      switch ( v4 )
      {
        case 0:
          v9 = 4;
          break;
        case 1:
          v9 = 5;
          break;
        case 2:
          v9 = 6;
          break;
        case 3:
          v9 = 3;
          break;
        case 4:
          v9 = 2;
          break;
        case 5:
          v9 = 16;
          break;
        default:
          v9 = 0;
          break;
      }
      *v5 += v9;
    }
  }
}

// File Line: 1155
// RVA: 0xB3E390
void __fastcall hkaSplineCompressedAnimation::Linspace(int m, hkArray<float,hkContainerHeapAllocator> *ub, float a, float b)
{
  float *v4; // r9
  int v5; // edx
  int v6; // eax
  __m128 v7; // xmm5
  __m128i v8; // xmm7
  __m128 v9; // xmm0
  __m128 v10; // xmm4
  int v11; // er10
  __m128 v12; // xmm6
  __m128 v13; // xmm6
  signed int v14; // eax
  float v15; // xmm3_4
  signed __int64 v16; // rax
  __m128i v17; // xmm0

  v4 = ub->m_data;
  v5 = 1;
  v6 = m - 1;
  *v4 = a;
  v4[m] = b;
  if ( m > 1 )
  {
    if ( (unsigned int)v6 >= 8 )
    {
      v7 = _mm_shuffle_ps((__m128)LODWORD(a), (__m128)LODWORD(a), 0);
      v8 = _mm_load_si128((const __m128i *)&_xmm);
      v9 = _mm_cvtepi32_ps(_mm_shuffle_epi32(_mm_cvtsi32_si128(m), 0));
      v10 = _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(b), (__m128)LODWORD(b), 0), v7);
      v11 = m - v6 % 8;
      v12 = _mm_rcp_ps(v9);
      v13 = _mm_sub_ps(_mm_add_ps(v12, v12), _mm_mul_ps(_mm_mul_ps(v12, v12), v9));
      do
      {
        *(__m128 *)&v4[v5] = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_cvtepi32_ps(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v5), 0), v8)),
                                   v13),
                                 v10),
                               v7);
        v14 = v5 + 4;
        v5 += 8;
        *(__m128 *)&v4[v14] = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v14), 0), v8)),
                                    v13),
                                  v10),
                                v7);
      }
      while ( v5 < v11 );
    }
    if ( v5 < m )
    {
      v15 = b - a;
      v16 = v5;
      do
      {
        v17 = _mm_cvtsi32_si128(v5++);
        ++v16;
        v4[v16 - 1] = (float)((float)(COERCE_FLOAT(_mm_cvtepi32_ps(v17)) * (float)(1.0 / (float)m)) * v15) + a;
      }
      while ( v5 < m );
    }
  }
}

