// File Line: 20
// RVA: 0xB3BE50
void __fastcall hkaSplineCompressedAnimation::TrackCompressionParams::TrackCompressionParams(
        hkaSplineCompressedAnimation::TrackCompressionParams *this)
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
void __fastcall hkaSplineCompressedAnimation::AnimationCompressionParams::AnimationCompressionParams(
        hkaSplineCompressedAnimation::AnimationCompressionParams *this)
{
  this->m_maxFramesPerBlock = 256;
  this->m_enableSampleSingleTracks.m_bool = 0;
}

// File Line: 40
// RVA: 0xB3BEB0
void __fastcall hkaSplineCompressedAnimation::hkaSplineCompressedAnimation(
        hkaSplineCompressedAnimation *this,
        hkaInterleavedUncompressedAnimation *raw)
{
  hkaSplineCompressedAnimation::TrackCompressionParams trackParams; // [rsp+20h] [rbp-28h] BYREF
  hkaSplineCompressedAnimation::AnimationCompressionParams animationParams; // [rsp+50h] [rbp+8h] BYREF

  hkaAnimation::hkaAnimation(this, raw);
  this->vfptr = (hkBaseObjectVtbl *)&hkaSplineCompressedAnimation::`vftable;
  this->m_blockOffsets.m_capacityAndFlags = 0x80000000;
  this->m_blockOffsets.m_data = 0i64;
  this->m_blockOffsets.m_size = 0;
  this->m_floatBlockOffsets.m_data = 0i64;
  this->m_floatBlockOffsets.m_size = 0;
  this->m_floatBlockOffsets.m_capacityAndFlags = 0x80000000;
  this->m_transformOffsets.m_data = 0i64;
  this->m_transformOffsets.m_size = 0;
  this->m_transformOffsets.m_capacityAndFlags = 0x80000000;
  this->m_floatOffsets.m_data = 0i64;
  this->m_floatOffsets.m_size = 0;
  this->m_floatOffsets.m_capacityAndFlags = 0x80000000;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 0x80000000;
  hkaSplineCompressedAnimation::TrackCompressionParams::TrackCompressionParams(&trackParams);
  hkaSplineCompressedAnimation::AnimationCompressionParams::AnimationCompressionParams(&animationParams);
  hkaSplineCompressedAnimation::initialize(this, raw, &trackParams, &animationParams);
}

// File Line: 55
// RVA: 0xB3BF70
void __fastcall hkaSplineCompressedAnimation::hkaSplineCompressedAnimation(
        hkaSplineCompressedAnimation *this,
        hkaInterleavedUncompressedAnimation *raw,
        hkaSplineCompressedAnimation::TrackCompressionParams *trackParams,
        hkaSplineCompressedAnimation::AnimationCompressionParams *animationParams)
{
  hkaAnimation::hkaAnimation(this, raw);
  this->vfptr = (hkBaseObjectVtbl *)&hkaSplineCompressedAnimation::`vftable;
  this->m_blockOffsets.m_capacityAndFlags = 0x80000000;
  this->m_blockOffsets.m_data = 0i64;
  this->m_blockOffsets.m_size = 0;
  this->m_floatBlockOffsets.m_data = 0i64;
  this->m_floatBlockOffsets.m_size = 0;
  this->m_floatBlockOffsets.m_capacityAndFlags = 0x80000000;
  this->m_transformOffsets.m_data = 0i64;
  this->m_transformOffsets.m_size = 0;
  this->m_transformOffsets.m_capacityAndFlags = 0x80000000;
  this->m_floatOffsets.m_data = 0i64;
  this->m_floatOffsets.m_size = 0;
  this->m_floatOffsets.m_capacityAndFlags = 0x80000000;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 0x80000000;
  hkaSplineCompressedAnimation::initialize(this, raw, trackParams, animationParams);
}

// File Line: 68
// RVA: 0xB3C040
void __fastcall hkaSplineCompressedAnimation::hkaSplineCompressedAnimation(
        hkaSplineCompressedAnimation *this,
        hkaInterleavedUncompressedAnimation *raw,
        hkaSplineCompressedAnimation::PerTrackCompressionParams *trackParams,
        hkaSplineCompressedAnimation::AnimationCompressionParams *animationParams)
{
  hkaAnimation::hkaAnimation(this, raw);
  this->vfptr = (hkBaseObjectVtbl *)&hkaSplineCompressedAnimation::`vftable;
  this->m_blockOffsets.m_capacityAndFlags = 0x80000000;
  this->m_blockOffsets.m_data = 0i64;
  this->m_blockOffsets.m_size = 0;
  this->m_floatBlockOffsets.m_data = 0i64;
  this->m_floatBlockOffsets.m_size = 0;
  this->m_floatBlockOffsets.m_capacityAndFlags = 0x80000000;
  this->m_transformOffsets.m_data = 0i64;
  this->m_transformOffsets.m_size = 0;
  this->m_transformOffsets.m_capacityAndFlags = 0x80000000;
  this->m_floatOffsets.m_data = 0i64;
  this->m_floatOffsets.m_size = 0;
  this->m_floatOffsets.m_capacityAndFlags = 0x80000000;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 0x80000000;
  hkaSplineCompressedAnimation::initialize(this, raw, trackParams, animationParams);
}

// File Line: 76
// RVA: 0xB3C850
void __fastcall hkaSplineCompressedAnimation::initialize(
        hkaSplineCompressedAnimation *this,
        hkaInterleavedUncompressedAnimation *raw,
        hkaSplineCompressedAnimation::TrackCompressionParams *trackParams,
        hkaSplineCompressedAnimation::AnimationCompressionParams *animationParams)
{
  int m_size; // eax
  hkaSplineCompressedAnimation::TrackCompressionParams *v9; // rcx
  int m_numberOfTransformTracks; // edi
  int v11; // r9d
  int m_numberOfFloatTracks; // edi
  int v13; // r9d
  int v14; // edx
  __int64 v15; // rcx
  int v16; // edx
  __int64 v17; // rcx
  hkaSplineCompressedAnimation::PerTrackCompressionParams array; // [rsp+30h] [rbp-30h] BYREF
  hkResult result; // [rsp+88h] [rbp+28h] BYREF

  array.m_parameterPalette.m_data = 0i64;
  array.m_parameterPalette.m_size = 0;
  array.m_parameterPalette.m_capacityAndFlags = 0x80000000;
  array.m_trackIndexToPaletteIndex.m_data = 0i64;
  array.m_trackIndexToPaletteIndex.m_size = 0;
  array.m_trackIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  array.m_floatTrackIndexToPaletteIndex.m_data = 0i64;
  array.m_floatTrackIndexToPaletteIndex.m_size = 0;
  array.m_floatTrackIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 28);
  m_size = array.m_parameterPalette.m_size;
  v9 = &array.m_parameterPalette.m_data[array.m_parameterPalette.m_size];
  if ( v9 )
  {
    v9->m_rotationTolerance = trackParams->m_rotationTolerance;
    v9->m_translationTolerance = trackParams->m_translationTolerance;
    v9->m_scaleTolerance = trackParams->m_scaleTolerance;
    v9->m_floatingTolerance = trackParams->m_floatingTolerance;
    *(_DWORD *)&v9->m_rotationDegree = *(_DWORD *)&trackParams->m_rotationDegree;
    *(_DWORD *)&v9->m_scaleDegree = *(_DWORD *)&trackParams->m_scaleDegree;
    *(_DWORD *)&v9->m_rotationQuantizationType.m_storage = *(_DWORD *)&trackParams->m_rotationQuantizationType.m_storage;
    m_size = array.m_parameterPalette.m_size;
  }
  m_numberOfTransformTracks = raw->m_numberOfTransformTracks;
  array.m_parameterPalette.m_size = m_size + 1;
  if ( (array.m_trackIndexToPaletteIndex.m_capacityAndFlags & 0x3FFFFFFF) < m_numberOfTransformTracks )
  {
    v11 = m_numberOfTransformTracks;
    if ( m_numberOfTransformTracks < 2 * (array.m_trackIndexToPaletteIndex.m_capacityAndFlags & 0x3FFFFFFF) )
      v11 = 2 * (array.m_trackIndexToPaletteIndex.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_trackIndexToPaletteIndex, v11, 4);
  }
  array.m_trackIndexToPaletteIndex.m_size = m_numberOfTransformTracks;
  m_numberOfFloatTracks = raw->m_numberOfFloatTracks;
  if ( (array.m_floatTrackIndexToPaletteIndex.m_capacityAndFlags & 0x3FFFFFFF) < m_numberOfFloatTracks )
  {
    v13 = raw->m_numberOfFloatTracks;
    if ( m_numberOfFloatTracks < 2 * (array.m_floatTrackIndexToPaletteIndex.m_capacityAndFlags & 0x3FFFFFFF) )
      v13 = 2 * (array.m_floatTrackIndexToPaletteIndex.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_floatTrackIndexToPaletteIndex, v13, 4);
  }
  v14 = 0;
  array.m_floatTrackIndexToPaletteIndex.m_size = m_numberOfFloatTracks;
  if ( raw->m_numberOfTransformTracks > 0 )
  {
    v15 = 0i64;
    do
    {
      ++v14;
      array.m_trackIndexToPaletteIndex.m_data[v15++] = 0;
    }
    while ( v14 < raw->m_numberOfTransformTracks );
  }
  v16 = 0;
  if ( raw->m_numberOfFloatTracks > 0 )
  {
    v17 = 0i64;
    do
    {
      ++v16;
      array.m_floatTrackIndexToPaletteIndex.m_data[v17++] = 0;
    }
    while ( v16 < raw->m_numberOfFloatTracks );
  }
  hkaSplineCompressedAnimation::initialize(this, raw, &array, animationParams);
  array.m_floatTrackIndexToPaletteIndex.m_size = 0;
  if ( array.m_floatTrackIndexToPaletteIndex.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_floatTrackIndexToPaletteIndex.m_data,
      4 * array.m_floatTrackIndexToPaletteIndex.m_capacityAndFlags);
  array.m_floatTrackIndexToPaletteIndex.m_data = 0i64;
  array.m_floatTrackIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  array.m_trackIndexToPaletteIndex.m_size = 0;
  if ( array.m_trackIndexToPaletteIndex.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_trackIndexToPaletteIndex.m_data,
      4 * array.m_trackIndexToPaletteIndex.m_capacityAndFlags);
  array.m_trackIndexToPaletteIndex.m_data = 0i64;
  array.m_trackIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  array.m_parameterPalette.m_size = 0;
  if ( array.m_parameterPalette.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_parameterPalette.m_data,
      28 * (array.m_parameterPalette.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 103
// RVA: 0xB3CA90
void __fastcall hkaSplineCompressedAnimation::initialize(
        hkaSplineCompressedAnimation *this,
        hkaInterleavedUncompressedAnimation *raw,
        hkaSplineCompressedAnimation::PerTrackCompressionParams *trackParams,
        hkaSplineCompressedAnimation::AnimationCompressionParams *animationParams)
{
  hkaSplineCompressedAnimation *v4; // r13
  char m_bool; // bl
  hkBaseObjectVtbl *vfptr; // rax
  int v8; // eax
  int m_maxFramesPerBlock; // ecx
  int v10; // r12d
  float m_duration; // xmm2_4
  int v12; // r8d
  int v13; // r9d
  int v14; // eax
  int m_numberOfTransformTracks; // ecx
  float v16; // xmm2_4
  float v17; // xmm1_4
  int v18; // r10d
  unsigned int v19; // edx
  hkArray<unsigned char,hkContainerHeapAllocator> *p_m_data; // rsi
  hkArray<unsigned int,hkContainerHeapAllocator> *p_m_blockOffsets; // r15
  int m_size; // edi
  __int64 v23; // rdi
  int m_numFrames; // r15d
  unsigned int v25; // eax
  int v26; // r15d
  __m128i v27; // xmm0
  float v28; // xmm8_4
  __int64 v29; // rdx
  int m_numberOfFloatTracks; // r12d
  int v31; // esi
  int v32; // r14d
  __int64 v33; // r8
  __int64 v34; // r9
  int v35; // esi
  int *m_data; // rax
  int v37; // ecx
  int v38; // esi
  __int64 v39; // r14
  unsigned __int64 v40; // rdi
  __int64 v41; // r12
  int v42; // eax
  int v43; // eax
  int v44; // r9d
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // r9d
  float v49; // xmm0_4
  float v50; // xmm1_4
  int v51; // edx
  int v52; // eax
  float v53; // xmm0_4
  int v54; // eax
  float v55; // xmm0_4
  int v56; // edx
  int v57; // r13d
  __int64 v58; // r12
  __int64 v59; // rbx
  unsigned __int64 v60; // rsi
  __m128 v61; // xmm0
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm3
  float v65; // xmm6_4
  char isStatic; // si
  float *v67; // r8
  int v68; // edi
  int v69; // edx
  hkVector4f *pointsOut; // rcx
  char v71; // al
  float *v72; // rdx
  int v73; // r12d
  int v74; // eax
  int v75; // edx
  __int64 v76; // rax
  int v77; // eax
  int v78; // edi
  int v79; // r9d
  int v80; // edi
  int v81; // r9d
  int v82; // edi
  int v83; // r9d
  int v84; // r9d
  unsigned __int8 *v85; // rax
  hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization v86; // r8d
  int v87; // esi
  char *v88; // rdi
  int v89; // r8d
  int v90; // esi
  int *v91; // rdi
  int v92; // r8d
  __int64 v93; // rdi
  hkOstream *v94; // rax
  int v95; // ebx
  hkOstream *v96; // rax
  hkOstream *v97; // rax
  int v98; // edi
  int v99; // ebx
  hkOstream *v100; // rax
  hkOstream *v101; // rax
  hkOstream *v102; // rax
  hkOstream *v103; // rax
  hkOstream *v104; // rax
  hkOstream *v105; // rax
  int v106; // [rsp+48h] [rbp-80h]
  int numKnotsOut; // [rsp+4Ch] [rbp-7Ch] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> numPointsOut; // [rsp+50h] [rbp-78h] BYREF
  __int64 v109; // [rsp+60h] [rbp-68h] BYREF
  int track[2]; // [rsp+68h] [rbp-60h]
  hkArray<float,hkContainerHeapAllocator> array; // [rsp+70h] [rbp-58h] BYREF
  unsigned __int64 v112; // [rsp+80h] [rbp-48h]
  __int64 v113; // [rsp+88h] [rbp-40h]
  hkErrStream v114; // [rsp+98h] [rbp-30h] BYREF
  hkResult result; // [rsp+B8h] [rbp-10h] BYREF
  int degree[4]; // [rsp+C0h] [rbp-8h]
  int v117; // [rsp+D0h] [rbp+8h]
  hkResult v118; // [rsp+D4h] [rbp+Ch] BYREF
  hkResult v119; // [rsp+D8h] [rbp+10h] BYREF
  hkResult v120; // [rsp+DCh] [rbp+14h] BYREF
  hkResult v121; // [rsp+E0h] [rbp+18h] BYREF
  hkResult v122; // [rsp+E4h] [rbp+1Ch] BYREF
  float tol[4]; // [rsp+E8h] [rbp+20h]
  hkArray<hkVector4f,hkContainerHeapAllocator> out; // [rsp+F8h] [rbp+30h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> qOut; // [rsp+108h] [rbp+40h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> sOut; // [rsp+118h] [rbp+50h] BYREF
  hkVector4f mean; // [rsp+128h] [rbp+60h] BYREF
  float *sampleTimes; // [rsp+138h] [rbp+70h] BYREF
  int v129; // [rsp+140h] [rbp+78h]
  int v130; // [rsp+144h] [rbp+7Ch]
  __int64 v131; // [rsp+148h] [rbp+80h]
  int v132; // [rsp+150h] [rbp+88h]
  int v133; // [rsp+154h] [rbp+8Ch]
  __int64 v134; // [rsp+158h] [rbp+90h]
  int v135; // [rsp+160h] [rbp+98h]
  int v136; // [rsp+164h] [rbp+9Ch]
  __int64 v137; // [rsp+168h] [rbp+A0h]
  char v138; // [rsp+174h] [rbp+ACh] BYREF
  hkVector4f minp; // [rsp+178h] [rbp+B0h] BYREF
  hkVector4f maxp; // [rsp+188h] [rbp+C0h] BYREF
  __int128 v141[3]; // [rsp+198h] [rbp+D0h] BYREF
  hkVector4f v142; // [rsp+1C8h] [rbp+100h] BYREF
  char buf[568]; // [rsp+1D8h] [rbp+110h] BYREF
  hkaSplineCompressedAnimation *v144; // [rsp+458h] [rbp+390h]
  __int64 v145; // [rsp+460h] [rbp+398h]
  hkaSplineCompressedAnimation::PerTrackCompressionParams *v146; // [rsp+468h] [rbp+3A0h]
  char v147; // [rsp+470h] [rbp+3A8h]

  v4 = this;
  this->m_type.m_storage = 3;
  this->m_endian = 0;
  this->m_maxFramesPerBlock = animationParams->m_maxFramesPerBlock;
  m_bool = animationParams->m_enableSampleSingleTracks.m_bool;
  vfptr = raw->vfptr;
  v147 = m_bool;
  v8 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *))vfptr[4].__vecDelDtor)(raw);
  m_maxFramesPerBlock = v4->m_maxFramesPerBlock;
  v10 = 0;
  m_duration = v4->m_duration;
  v12 = v8;
  v4->m_numFrames = v8;
  v13 = m_maxFramesPerBlock - 1;
  v14 = m_maxFramesPerBlock - 3;
  track[0] = 0;
  m_numberOfTransformTracks = v4->m_numberOfTransformTracks;
  HIDWORD(numPointsOut.m_data) = 0;
  v109 = 0i64;
  v16 = m_duration / (float)(v12 - 1);
  v17 = (float)v13 * v16;
  v4->m_frameDuration = v16;
  v4->m_blockDuration = v17;
  v4->m_blockInverseDuration = 1.0 / v17;
  v18 = (v12 + v14) / v13;
  if ( v18 < 1 )
    v18 = 1;
  v19 = (v4->m_numberOfFloatTracks + 4 * m_numberOfTransformTracks + 3) & 0xFFFFFFFC;
  v4->m_numBlocks = v18;
  v4->m_maskAndQuantizationSize = v19;
  p_m_data = &v4->m_data;
  p_m_blockOffsets = &v4->m_blockOffsets;
  array.m_data = (float *)&v4->m_data;
  do
  {
    m_size = v4->m_data.m_size;
    if ( p_m_blockOffsets->m_size == (p_m_blockOffsets->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_blockOffsets, 4);
    p_m_blockOffsets->m_data[p_m_blockOffsets->m_size++] = m_size;
    v23 = v4->m_data.m_size;
    m_numFrames = v4->m_numFrames;
    v25 = m_numFrames - 1;
    v26 = m_numFrames - v10;
    v27 = _mm_cvtsi32_si128(v25);
    if ( v4->m_maxFramesPerBlock < v26 )
      v26 = v4->m_maxFramesPerBlock;
    v28 = (float)(v4->m_duration / _mm_cvtepi32_ps(v27).m128_f32[0]) * (float)(v26 - 1);
    hkaSplineCompressedAnimation::writeZeros(v4->m_maskAndQuantizationSize, p_m_data);
    LODWORD(v29) = 0;
    v109 = v23;
    v106 = 0;
    do
    {
      if ( (_DWORD)v29 )
        m_numberOfFloatTracks = v4->m_numberOfFloatTracks;
      else
        m_numberOfFloatTracks = v4->m_numberOfTransformTracks;
      v31 = 1;
      if ( !(_DWORD)v29 )
        v31 = 3;
      if ( (_DWORD)v29 == 1 )
      {
        v32 = v4->m_data.m_size - v4->m_blockOffsets.m_data[v109];
        if ( v4->m_floatBlockOffsets.m_size == (v4->m_floatBlockOffsets.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v4->m_floatBlockOffsets, 4);
          LODWORD(v29) = v106;
        }
        v4->m_floatBlockOffsets.m_data[v4->m_floatBlockOffsets.m_size++] = v32;
        trackParams = v146;
      }
      v29 = (int)v29;
      v33 = v31;
      v34 = 0i64;
      v113 = 0i64;
      *(_QWORD *)&numPointsOut.m_size = (int)v29;
      *(_QWORD *)track = v31;
      v137 = m_numberOfFloatTracks;
      if ( m_numberOfFloatTracks > 0 )
      {
        while ( 1 )
        {
          if ( !m_bool )
            goto LABEL_28;
          v35 = v4->m_data.m_size - v4->m_blockOffsets.m_data[v109];
          if ( v29 )
            break;
          if ( v4->m_transformOffsets.m_size == (v4->m_transformOffsets.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v4->m_transformOffsets, 4);
            v33 = *(_QWORD *)track;
            v34 = v113;
          }
          v4->m_transformOffsets.m_data[v4->m_transformOffsets.m_size++] = v35;
          m_data = trackParams->m_trackIndexToPaletteIndex.m_data;
LABEL_31:
          v37 = m_data[v34];
          v38 = 0;
          out.m_data = 0i64;
          out.m_size = 0;
          out.m_capacityAndFlags = 0x80000000;
          qOut.m_data = 0i64;
          qOut.m_size = 0;
          v39 = (__int64)&v146->m_parameterPalette.m_data[v37];
          qOut.m_capacityAndFlags = 0x80000000;
          sOut.m_data = 0i64;
          sOut.m_size = 0;
          sOut.m_capacityAndFlags = 0x80000000;
          sampleTimes = 0i64;
          v129 = 0;
          v130 = 0x80000000;
          v131 = 0i64;
          v132 = 0;
          v133 = 0x80000000;
          v134 = 0i64;
          v135 = 0;
          v136 = 0x80000000;
          if ( v33 > 0 )
          {
            v40 = 0i64;
            v41 = v33;
            do
            {
              v42 = *(int *)((_BYTE *)&out.m_capacityAndFlags + v40) & 0x3FFFFFFF;
              if ( v42 >= v26 )
              {
                result.m_enum = HK_SUCCESS;
              }
              else
              {
                v43 = 2 * v42;
                v44 = v26;
                if ( v26 < v43 )
                  v44 = v43;
                hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (char *)&out + v40, v44, 16);
              }
              v45 = *(int *)((char *)&v130 + v40);
              *(int *)((char *)&out.m_size + v40) = v26;
              v46 = v45 & 0x3FFFFFFF;
              if ( v46 >= v26 )
              {
                v121.m_enum = HK_SUCCESS;
              }
              else
              {
                v47 = 2 * v46;
                v48 = v26;
                if ( v26 < v47 )
                  v48 = v47;
                hkArrayUtil::_reserve(&v121, &hkContainerHeapAllocator::s_alloc, &(&sampleTimes)[v40 / 8], v48, 4);
              }
              *(int *)((char *)&v129 + v40) = v26;
              hkaSplineCompressedAnimation::Linspace(
                v26 - 1,
                (hkArray<float,hkContainerHeapAllocator> *)&(&sampleTimes)[2 * v38++],
                0.0,
                v28);
              v40 += 16i64;
              --v41;
            }
            while ( v41 );
            m_bool = v147;
          }
          if ( *(_QWORD *)&numPointsOut.m_size )
          {
            v55 = *(float *)(v39 + 12);
            v56 = v4->m_numberOfFloatTracks;
            degree[0] = *(unsigned __int16 *)(v39 + 22);
            tol[0] = v55;
            hkaSplineCompressedAnimation::deinterleaveFloat(
              *(const float **)(v145 + 72),
              v56,
              v26,
              track[0],
              track[1],
              &out);
          }
          else
          {
            v49 = *(float *)(v39 + 4);
            v50 = *(float *)v39;
            v51 = v4->m_numberOfTransformTracks;
            degree[0] = *(unsigned __int16 *)(v39 + 18);
            v52 = *(unsigned __int16 *)(v39 + 16);
            tol[0] = v49;
            v53 = *(float *)(v39 + 8);
            tol[1] = v50;
            degree[1] = v52;
            v54 = *(unsigned __int16 *)(v39 + 20);
            tol[2] = v53;
            degree[2] = v54;
            hkaSplineCompressedAnimation::deinterleaveTransform(
              *(hkQsTransformf **)(v145 + 56),
              v51,
              v26,
              track[0],
              track[1],
              &out,
              &qOut,
              &sOut);
          }
          v57 = 0;
          v58 = 0i64;
          *(_QWORD *)&array.m_size = 0i64;
          if ( *(__int64 *)track > 0 )
          {
            v59 = v109;
            v112 = 0i64;
            v117 = v26 + 2 * (v26 + 1);
            while ( 1 )
            {
              v60 = 16i64 * v57;
              hkaSplineCompressedAnimation::getMean(
                &mean,
                (hkArray<hkVector4f,hkContainerHeapAllocator> *)((char *)&out + v60));
              hkaSplineCompressedAnimation::getMin(
                &minp,
                (hkArray<hkVector4f,hkContainerHeapAllocator> *)((char *)&out + v60));
              hkaSplineCompressedAnimation::getMax(
                &maxp,
                (hkArray<hkVector4f,hkContainerHeapAllocator> *)((char *)&out + v60));
              if ( v57 == 1 )
              {
                v61 = _mm_mul_ps(mean.m_quad, mean.m_quad);
                v62 = _mm_add_ps(_mm_shuffle_ps(v61, v61, 78), v61);
                v63 = _mm_add_ps(_mm_shuffle_ps(v62, v62, 177), v62);
                v64 = _mm_rsqrt_ps(v63);
                mean.m_quad = _mm_mul_ps(
                                mean.m_quad,
                                _mm_andnot_ps(
                                  _mm_cmple_ps(v63, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v64))));
              }
              v65 = tol[v58];
              v141[0] = 0i64;
              v141[2] = (__int128)_mm_srli_si128(_mm_slli_si128((__m128i)query.m_quad, 4), 4);
              v141[1] = (__int128)qi.m_vec.m_quad;
              isStatic = hkaSplineCompressedAnimation::isStatic(
                           &mean,
                           &minp,
                           &maxp,
                           v65,
                           (hkVector4f *)&v141[v60 / 0x10]);
              if ( *(_QWORD *)&numPointsOut.m_size == 1i64 )
                break;
              if ( *(_QWORD *)&numPointsOut.m_size )
                goto LABEL_55;
              if ( v57 )
              {
                *(_BYTE *)(v59 + *(_QWORD *)array.m_data) = isStatic;
              }
              else
              {
                v71 = hkaSplineCompressedAnimation::packQuantizationTypes(
                        (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)*(unsigned __int8 *)(v39 + 25),
                        (hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization)*(unsigned __int8 *)(v39 + 24),
                        (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)*(unsigned __int8 *)(v39 + 26));
                v72 = array.m_data;
                *(_BYTE *)(++v59 + *(_QWORD *)array.m_data - 1) = v71;
                *(_BYTE *)(v59 + *(_QWORD *)v72) = isStatic;
              }
LABEL_56:
              v67 = 0i64;
              v68 = 3 * v26;
              ++v59;
              v69 = 3 * v26;
              numPointsOut.m_data = 0i64;
              *(_QWORD *)&numPointsOut.m_size = 0x8000000000000000ui64;
              if ( 3 * v26 )
              {
                LODWORD(v109) = 48 * v26;
                pointsOut = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            &hkContainerHeapAllocator::s_alloc,
                                            &v109);
                v69 = (int)v109 / 16;
                v67 = 0i64;
              }
              else
              {
                pointsOut = 0i64;
              }
              v73 = v117;
              v74 = 0x80000000;
              if ( v69 )
                v74 = v69;
              numPointsOut.m_data = pointsOut;
              numPointsOut.m_size = 3 * v26;
              v75 = v117;
              array.m_data = 0i64;
              *(_QWORD *)&array.m_size = 0x8000000000000000ui64;
              numPointsOut.m_capacityAndFlags = v74;
              if ( v117 )
              {
                LODWORD(v109) = 4 * v117;
                v76 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64 *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                        &hkContainerHeapAllocator::s_alloc,
                        &v109,
                        0i64);
                v68 = numPointsOut.m_size;
                pointsOut = numPointsOut.m_data;
                v67 = (float *)v76;
                v75 = (int)v109 / 4;
              }
              array.m_size = v73;
              v77 = 0x80000000;
              if ( v75 )
                v77 = v75;
              array.m_data = v67;
              array.m_capacityAndFlags = v77;
              if ( (isStatic & 0xF0) != 0 )
              {
                hkaCompression::approximateNURBSCurve(
                  v26,
                  (&sampleTimes)[v112 / 8],
                  (&out.m_data)[v112 / 8],
                  degree[*(_QWORD *)&array.m_size],
                  v65,
                  &numKnotsOut,
                  v67,
                  (int *)&numPointsOut,
                  pointsOut);
                v78 = numKnotsOut;
                if ( (array.m_capacityAndFlags & 0x3FFFFFFF) >= numKnotsOut )
                {
                  v119.m_enum = HK_SUCCESS;
                }
                else
                {
                  v79 = numKnotsOut;
                  if ( numKnotsOut < 2 * (array.m_capacityAndFlags & 0x3FFFFFFF) )
                    v79 = 2 * (array.m_capacityAndFlags & 0x3FFFFFFF);
                  hkArrayUtil::_reserve(&v119, &hkContainerHeapAllocator::s_alloc, &array, v79, 4);
                }
                array.m_size = v78;
                v80 = (int)numPointsOut.m_data;
                if ( (numPointsOut.m_capacityAndFlags & 0x3FFFFFFF) >= SLODWORD(numPointsOut.m_data) )
                {
                  v120.m_enum = HK_SUCCESS;
                }
                else
                {
                  v81 = (int)numPointsOut.m_data;
                  if ( SLODWORD(numPointsOut.m_data) < 2 * (numPointsOut.m_capacityAndFlags & 0x3FFFFFFF) )
                    v81 = 2 * (numPointsOut.m_capacityAndFlags & 0x3FFFFFFF);
                  hkArrayUtil::_reserve(&v120, &hkContainerHeapAllocator::s_alloc, &numPointsOut, v81, 16);
                }
                numPointsOut.m_size = v80;
                if ( v80 > v26 )
                {
                  degree[*(_QWORD *)&array.m_size] = 1;
                  hkaCompression::approximateNURBSCurve(
                    v26,
                    (&sampleTimes)[v112 / 8],
                    (&out.m_data)[v112 / 8],
                    1,
                    v65,
                    &numKnotsOut,
                    array.m_data,
                    (int *)&numPointsOut,
                    numPointsOut.m_data);
                  v82 = numKnotsOut;
                  if ( (array.m_capacityAndFlags & 0x3FFFFFFF) >= numKnotsOut )
                  {
                    v122.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v83 = numKnotsOut;
                    if ( numKnotsOut < 2 * (array.m_capacityAndFlags & 0x3FFFFFFF) )
                      v83 = 2 * (array.m_capacityAndFlags & 0x3FFFFFFF);
                    hkArrayUtil::_reserve(&v122, &hkContainerHeapAllocator::s_alloc, &array, v83, 4);
                  }
                  array.m_size = v82;
                  v80 = (int)numPointsOut.m_data;
                  if ( (numPointsOut.m_capacityAndFlags & 0x3FFFFFFF) >= SLODWORD(numPointsOut.m_data) )
                  {
                    v118.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v84 = (int)numPointsOut.m_data;
                    if ( SLODWORD(numPointsOut.m_data) < 2 * (numPointsOut.m_capacityAndFlags & 0x3FFFFFFF) )
                      v84 = 2 * (numPointsOut.m_capacityAndFlags & 0x3FFFFFFF);
                    hkArrayUtil::_reserve(&v118, &hkContainerHeapAllocator::s_alloc, &numPointsOut, v84, 16);
                  }
                  numPointsOut.m_size = v80;
                }
                hkaSplineCompressedAnimation::writeKnots(v144, v80 - 1, array.m_size - v80 - 1, &array);
                v68 = numPointsOut.m_size;
              }
              if ( v57 == 1 )
              {
                hkaSplineCompressedAnimation::writeRotation(
                  v144,
                  isStatic,
                  (hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization)*(unsigned __int8 *)(v39 + 24),
                  &mean,
                  v68 - 1,
                  &numPointsOut);
              }
              else
              {
                if ( (isStatic & 0xF0) != 0 )
                {
                  minp.m_quad = hkaSplineCompressedAnimation::getMin(&v142, &numPointsOut)->m_quad;
                  maxp.m_quad = hkaSplineCompressedAnimation::getMax((hkVector4f *)&v114, &numPointsOut)->m_quad;
                }
                if ( *(_QWORD *)&numPointsOut.m_size )
                {
                  v86 = *(unsigned __int8 *)(v39 + 27);
                }
                else
                {
                  v85 = (unsigned __int8 *)(v39 + 25);
                  if ( v57 )
                    v85 = (unsigned __int8 *)(v39 + 26);
                  v86 = *v85;
                }
                hkaSplineCompressedAnimation::writePoints(
                  v144,
                  isStatic,
                  v86,
                  &mean,
                  &minp,
                  &maxp,
                  v68 - 1,
                  &numPointsOut);
              }
              hkaSplineCompressedAnimation::writeAlign(
                4,
                (hkArray<unsigned char,hkContainerHeapAllocator> *)array.m_data);
              array.m_size = 0;
              if ( array.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  array.m_data,
                  4 * array.m_capacityAndFlags);
              array.m_data = 0i64;
              array.m_capacityAndFlags = 0x80000000;
              numPointsOut.m_size = 0;
              if ( numPointsOut.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  numPointsOut.m_data,
                  16 * numPointsOut.m_capacityAndFlags);
              v112 += 16i64;
              ++v57;
              v58 = *(_QWORD *)&array.m_size + 1i64;
              numPointsOut.m_data = 0i64;
              numPointsOut.m_capacityAndFlags = 0x80000000;
              *(_QWORD *)&array.m_size = v58;
              if ( v58 >= *(__int64 *)track )
              {
                v109 = v59;
                m_bool = v147;
                goto LABEL_109;
              }
            }
            if ( !isStatic )
              isStatic = numPointsOut.m_size;
LABEL_55:
            *(_BYTE *)(v59 + *(_QWORD *)array.m_data) = hkaSplineCompressedAnimation::packMaskAndQuantizationType(
                                                          isStatic,
                                                          (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)*(unsigned __int8 *)(v39 + 27));
            goto LABEL_56;
          }
LABEL_109:
          v87 = 2;
          v88 = &v138;
          do
          {
            v89 = *((_DWORD *)v88 - 4);
            v88 -= 16;
            *((_DWORD *)v88 - 1) = 0;
            if ( v89 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v88 - 12),
                4 * v89);
            --v87;
            *(_QWORD *)(v88 - 12) = 0i64;
            *(_DWORD *)v88 = 0x80000000;
          }
          while ( v87 >= 0 );
          v90 = 2;
          v91 = &mean.m_quad.m128_i32[3];
          do
          {
            v92 = *(v91 - 4);
            v91 -= 4;
            *(v91 - 1) = 0;
            if ( v92 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v91 - 3),
                16 * v92);
            --v90;
            *(_QWORD *)(v91 - 3) = 0i64;
            *v91 = 0x80000000;
          }
          while ( v90 >= 0 );
          ++track[1];
          v4 = v144;
          v29 = *(_QWORD *)&numPointsOut.m_size;
          v33 = *(_QWORD *)track;
          trackParams = v146;
          v34 = v113 + 1;
          v113 = v34;
          if ( v34 >= v137 )
            goto LABEL_118;
        }
        if ( v4->m_floatOffsets.m_size == (v4->m_floatOffsets.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v4->m_floatOffsets, 4);
          v29 = *(_QWORD *)&numPointsOut.m_size;
          v33 = *(_QWORD *)track;
          v34 = v113;
        }
        v4->m_floatOffsets.m_data[v4->m_floatOffsets.m_size++] = v35;
LABEL_28:
        if ( v29 )
          m_data = trackParams->m_floatTrackIndexToPaletteIndex.m_data;
        else
          m_data = trackParams->m_trackIndexToPaletteIndex.m_data;
        goto LABEL_31;
      }
LABEL_118:
      trackParams = v146;
      LODWORD(v29) = v106 + 1;
      v106 = v29;
    }
    while ( (int)v29 < 2 );
    p_m_data = &v4->m_data;
    v10 = v26 + track[0] - 1;
    track[0] = v10;
    hkaSplineCompressedAnimation::writeAlign(16, &v4->m_data);
    ++v109;
    p_m_blockOffsets = &v4->m_blockOffsets;
    ++HIDWORD(numPointsOut.m_data);
  }
  while ( SHIDWORD(numPointsOut.m_data) < v4->m_numBlocks );
  v93 = v145;
  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    907120276i64,
    "Compression");
  hkErrStream::hkErrStream(&v114, buf, 512);
  v94 = hkOstream::operator<<(&v114, "Number of blocks: ");
  hkOstream::operator<<(v94, v4->m_numBlocks);
  hkError::messageReport(-1, buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimationCtor.cpp", 381);
  hkOstream::~hkOstream(&v114);
  hkErrStream::hkErrStream(&v114, buf, 512);
  v95 = ((__int64 (__fastcall *)(hkaSplineCompressedAnimation *))v4->vfptr[5].__first_virtual_table_function__)(v4);
  v96 = hkOstream::operator<<(&v114, "Size of largest block (PlayStation(R)3 SPU): ");
  v97 = hkOstream::operator<<(v96, v95);
  hkOstream::operator<<(v97, " bytes.");
  hkError::messageReport(-1, buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimationCtor.cpp", 382);
  hkOstream::~hkOstream(&v114);
  v98 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v93 + 56i64))(v93);
  v99 = ((__int64 (__fastcall *)(hkaSplineCompressedAnimation *))v4->vfptr[3].__first_virtual_table_function__)(v4);
  hkErrStream::hkErrStream(&v114, buf, 512);
  v100 = hkOstream::operator<<(&v114, "Original Size: ");
  v101 = hkOstream::operator<<(v100, v98);
  v102 = hkOstream::operator<<(v101, " bytes. Compressed Size: ");
  v103 = hkOstream::operator<<(v102, v99);
  hkOstream::operator<<(v103, " bytes.");
  hkError::messageReport(-1, buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimationCtor.cpp", 388);
  hkOstream::~hkOstream(&v114);
  hkErrStream::hkErrStream(&v114, buf, 512);
  v104 = hkOstream::operator<<(&v114, "Compression Ratio: ");
  v105 = hkOstream::operator<<(v104, (float)v98 / (float)v99);
  hkOstream::operator<<(v105, ":1.");
  hkError::messageReport(-1, buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimationCtor.cpp", 389);
  hkOstream::~hkOstream(&v114);
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
}<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
}

// File Line: 404
// RVA: 0xB3D910
void __fastcall hkaSplineCompressedAnimation::deinterleaveTransform(
        hkQsTransformf *xform,
        int numTracks,
        int numFrames,
        int offset,
        int track,
        hkArray<hkVector4f,hkContainerHeapAllocator> *tOut,
        hkArray<hkVector4f,hkContainerHeapAllocator> *qOut,
        hkArray<hkVector4f,hkContainerHeapAllocator> *sOut)
{
  __int64 v9; // r10
  __int64 v10; // r8
  int v11; // eax
  __int64 v12; // rcx

  v9 = numFrames;
  if ( numFrames > 0 )
  {
    v10 = 0i64;
    v11 = track + offset * numTracks;
    do
    {
      v12 = v11;
      v11 += numTracks;
      tOut->m_data[v10++] = xform[v12].m_translation;
      tOut->m_data[v10 - 1] = (hkVector4f)_mm_srli_si128(
                                            _mm_slli_si128(_mm_load_si128((const __m128i *)&tOut->m_data[v10 - 1]), 4),
                                            4);
      qOut->m_data[v10 - 1] = (hkVector4f)xform[v12].m_rotation;
      sOut->m_data[v10 - 1] = xform[v12].m_scale;
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
void __fastcall hkaSplineCompressedAnimation::deinterleaveFloat(
        const float *data,
        int numTracks,
        int numFrames,
        int offset,
        int track,
        hkArray<hkVector4f,hkContainerHeapAllocator> *out)
{
  __int64 v6; // r11
  __int64 v7; // r10
  int v8; // r8d
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
__int64 __fastcall hkaSplineCompressedAnimation::isStatic(
        hkVector4f *mean,
        hkVector4f *minp,
        hkVector4f *maxp,
        float tol,
        hkVector4f *I)
{
  __m128 v5; // xmm4
  unsigned __int8 v6; // r10
  int v7; // r9d
  __m128 v8; // xmm4
  __m128i v9; // xmm0
  int v10; // r8d
  int v11; // ebx
  int v12; // r11d

  v5.m128_f32[0] = tol;
  v6 = 0;
  v7 = 0;
  v8 = _mm_shuffle_ps(v5, v5, 0);
  v9 = (__m128i)_mm_sub_ps(mean->m_quad, maxp->m_quad);
  v10 = 1;
  v11 = _mm_movemask_ps(_mm_cmplt_ps(v8, (__m128)_mm_srli_epi32(
                                                   _mm_slli_epi32((__m128i)_mm_sub_ps(mean->m_quad, I->m_quad), 1u),
                                                   1u)));
  v12 = _mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(mean->m_quad, minp->m_quad), 1u), 1u),
              v8),
            _mm_cmple_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v9, 1u), 1u), v8)));
  do
  {
    if ( (v10 & v12) != 0 )
    {
      if ( (v10 & v11) != 0 )
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
void __fastcall hkaSplineCompressedAnimation::writeRotation(
        hkaSplineCompressedAnimation *this,
        char mask,
        hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type,
        hkVector4f *mean,
        int n,
        hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  __int64 v9; // rsi
  unsigned int v10; // ebx
  __int64 v11; // r15
  __m128 m_quad; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  unsigned int v17; // ebx
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  hkQuaternionf in; // [rsp+20h] [rbp-48h] BYREF

  if ( (mask & 0xF0) != 0 )
  {
    hkaSplineCompressedAnimation::writeAlignQuaternion(type, &this->m_data);
    v9 = 0i64;
    switch ( type )
    {
      case POLAR32:
        v10 = 4;
        break;
      case THREECOMP40:
        v10 = 5;
        break;
      case THREECOMP48:
        v10 = 6;
        break;
      case THREECOMP24:
        v10 = 3;
        break;
      case STRAIGHT16:
        v10 = 2;
        break;
      case UNCOMPRESSED:
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
        m_quad = P->m_data[v9].m_quad;
        v13 = _mm_mul_ps(m_quad, m_quad);
        v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
        v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
        v16 = _mm_rsqrt_ps(v15);
        in.m_vec.m_quad = _mm_mul_ps(
                            m_quad,
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                              _mm_mul_ps(*(__m128 *)_xmm, v16)));
        hkaSplineCompressedAnimation::writeZeros(v10, &this->m_data);
        hkaSplineCompressedAnimation::packQuaternion(type, &in, &this->m_data.m_data[this->m_data.m_size - v10]);
        ++v9;
        --v11;
      }
      while ( v11 );
    }
  }
  else if ( (mask & 0xF) != 0 )
  {
    hkaSplineCompressedAnimation::writeAlignQuaternion(type, &this->m_data);
    switch ( type )
    {
      case POLAR32:
        v17 = 4;
        break;
      case THREECOMP40:
        v17 = 5;
        break;
      case THREECOMP48:
        v17 = 6;
        break;
      case THREECOMP24:
        v17 = 3;
        break;
      case STRAIGHT16:
        v17 = 2;
        break;
      case UNCOMPRESSED:
        v17 = 16;
        break;
      default:
        v17 = 0;
        break;
    }
    v18 = _mm_mul_ps(mean->m_quad, mean->m_quad);
    v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
    v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
    v21 = _mm_rsqrt_ps(v20);
    in.m_vec.m_quad = _mm_mul_ps(
                        mean->m_quad,
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                          _mm_mul_ps(*(__m128 *)_xmm, v21)));
    hkaSplineCompressedAnimation::writeZeros(v17, &this->m_data);
    hkaSplineCompressedAnimation::packQuaternion(type, &in, &this->m_data.m_data[this->m_data.m_size - v17]);
  }
}

// File Line: 575
// RVA: 0xB3C6B0
void __fastcall hkaSplineCompressedAnimation::writePoints(
        hkaSplineCompressedAnimation *this,
        unsigned __int8 mask,
        hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization type,
        hkVector4f *mean,
        hkVector4f *minp,
        hkVector4f *maxp,
        int n,
        hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *p_m_data; // rbp
  int v9; // r13d
  int v11; // ebx
  signed __int64 v12; // r14
  hkVector4f *v13; // rdi
  __int64 v14; // rsi
  float v15; // xmm0_4
  hkVector4f *v16; // rcx
  signed __int64 v17; // rdx
  __int64 v18; // r14
  int v19; // ebx
  hkVector4f *v20; // rdi
  __int64 v21; // rsi
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  char v25; // al
  unsigned __int16 v26; // ax
  __int64 v27; // [rsp+60h] [rbp+8h]
  hkVector4f *maxpa; // [rsp+88h] [rbp+30h]

  p_m_data = &this->m_data;
  v9 = mask;
  hkaSplineCompressedAnimation::writeAlign(4, &this->m_data);
  v11 = 1;
  v12 = (char *)mean - (char *)maxp;
  v13 = maxp;
  v14 = 3i64;
  do
  {
    if ( (__ROL4__(v11, 4) & v9) != 0 )
    {
      hkaSplineCompressedAnimation::writeReal(
        *(float *)((char *)v13->m_quad.m128_f32 + (char *)minp - (char *)maxp),
        p_m_data);
      v15 = v13->m_quad.m128_f32[0];
    }
    else
    {
      if ( (v9 & v11) == 0 )
        goto LABEL_7;
      v15 = *(float *)((char *)v13->m_quad.m128_f32 + v12);
    }
    hkaSplineCompressedAnimation::writeReal(v15, p_m_data);
LABEL_7:
    v11 = __ROL4__(v11, 1);
    v13 = (hkVector4f *)((char *)v13 + 4);
    --v14;
  }
  while ( v14 );
  if ( (v9 & 0xF0) != 0 && n >= 0i64 )
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
        if ( (__ROL4__(v19, 4) & v9) != 0 )
        {
          v22 = *(float *)((char *)v20->m_quad.m128_f32 + v17);
          v23 = v20->m_quad.m128_f32[0];
          v24 = *(float *)((char *)P->m_data[v18].m_quad.m128_f32 + (char *)v20 - (char *)minp);
          if ( type )
          {
            v26 = hkaSplineCompressedAnimation::pack16(v23, v22, v24);
            hkaSplineCompressedAnimation::write16(v26, p_m_data);
          }
          else
          {
            v25 = hkaSplineCompressedAnimation::pack8(v23, v22, v24);
            hkaSplineCompressedAnimation::write8(v25, p_m_data);
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
hkVector4f *__fastcall hkaSplineCompressedAnimation::getMean(
        hkVector4f *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  hkVector4f *m_data; // rax
  __int64 m_size; // r8
  __m128 *p_m_quad; // rax
  __int64 v5; // rdx
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  hkVector4f *v8; // rax
  __m128 v9; // xmm2
  __m128 v10; // xmm0

  m_data = P->m_data;
  m_size = P->m_size;
  *result = (hkVector4f)P->m_data->m_quad;
  if ( m_size > 1 )
  {
    p_m_quad = &m_data[1].m_quad;
    v5 = m_size - 1;
    do
    {
      v6 = *p_m_quad++;
      result->m_quad = _mm_add_ps(v6, result->m_quad);
      --v5;
    }
    while ( v5 );
  }
  v7 = 0i64;
  v7.m128_f32[0] = (float)(int)m_size;
  v8 = result;
  v9 = _mm_shuffle_ps(v7, v7, 0);
  v10 = _mm_rcp_ps(v9);
  result->m_quad = _mm_mul_ps(result->m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v10)), v10));
  return v8;
}

// File Line: 646
// RVA: 0xB3DD90
hkVector4f *__fastcall hkaSplineCompressedAnimation::getMin(
        hkVector4f *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  hkVector4f *m_data; // rax
  __int64 m_size; // rdx
  hkVector4f *v4; // rax
  __int64 v5; // rdx

  m_data = P->m_data;
  m_size = P->m_size;
  *result = (hkVector4f)m_data->m_quad;
  if ( m_size > 1 )
  {
    v4 = m_data + 1;
    v5 = m_size - 1;
    do
    {
      ++v4;
      result->m_quad = _mm_min_ps(result->m_quad, v4[-1].m_quad);
      --v5;
    }
    while ( v5 );
  }
  return result;
}

// File Line: 663
// RVA: 0xB3DDD0
hkVector4f *__fastcall hkaSplineCompressedAnimation::getMax(
        hkVector4f *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *P)
{
  hkVector4f *m_data; // rax
  __int64 m_size; // rdx
  hkVector4f *v4; // rax
  __int64 v5; // rdx

  m_data = P->m_data;
  m_size = P->m_size;
  *result = (hkVector4f)m_data->m_quad;
  if ( m_size > 1 )
  {
    v4 = m_data + 1;
    v5 = m_size - 1;
    do
    {
      ++v4;
      result->m_quad = _mm_max_ps(result->m_quad, v4[-1].m_quad);
      --v5;
    }
    while ( v5 );
  }
  return result;
}

// File Line: 683
// RVA: 0xB3C320
void __fastcall hkaSplineCompressedAnimation::writeKnots(
        hkaSplineCompressedAnimation *this,
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U)
{
  hkArray<unsigned char,hkContainerHeapAllocator> *p_m_data; // rsi
  char v7; // bl
  int v8; // ebp
  __m128 v9; // xmm6
  __m128 v10; // xmm0
  __m128 v11; // xmm6
  __int64 v12; // rbx
  __int64 v13; // rdi
  char v14; // bp

  p_m_data = &this->m_data;
  v7 = p;
  v8 = p + n + 1;
  hkaSplineCompressedAnimation::write16(n, &this->m_data);
  hkaSplineCompressedAnimation::write8(v7, p_m_data);
  v9 = 0i64;
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
  v9.m128_f32[0] = (float)(this->m_numFrames - 1);
  v11 = _mm_mul_ps(
          _mm_shuffle_ps(v9, v9, 0),
          _mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, v10), _mm_div_ps(query.m_quad, v10)));
  if ( v8 >= 0 )
  {
    v12 = 0i64;
    v13 = (unsigned int)(v8 + 1);
    do
    {
      v14 = _mm_cvtsi128_si32(
              _mm_cvttps_epi32(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(U->m_data[v12]), (__m128)LODWORD(U->m_data[v12]), 0), v11),
                  (__m128)xmmword_141A711B0)));
      if ( p_m_data->m_size == (p_m_data->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_data, 1);
      ++v12;
      p_m_data->m_data[p_m_data->m_size++] = v14;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 717
// RVA: 0xB3C110
void __fastcall hkaSplineCompressedAnimation::write8(char i, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  if ( data->m_size == (data->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, data, 1);
  data->m_data[data->m_size++] = i;
}

// File Line: 725
// RVA: 0xB3C160
void __fastcall hkaSplineCompressedAnimation::write16(
        unsigned __int16 i,
        hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  hkaSplineCompressedAnimation::writeZeros(2, data);
  *(_WORD *)&data->m_data[data->m_size - 2] = i;
}

// File Line: 738
// RVA: 0xB3C1A0
void __fastcall hkaSplineCompressedAnimation::writeReal(float f, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  hkaSplineCompressedAnimation::writeZeros(4, data);
  *(float *)&data->m_data[data->m_size - 4] = f;
}

// File Line: 752
// RVA: 0xB3C1E0
void __fastcall hkaSplineCompressedAnimation::writeZeros(
        unsigned int n,
        hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  __int64 v3; // rdi

  if ( (int)n > 0 )
  {
    v3 = n;
    do
    {
      if ( data->m_size == (data->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, data, 1);
      data->m_data[data->m_size++] = 0;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 763
// RVA: 0xB3C240
void __fastcall hkaSplineCompressedAnimation::writeAlign(
        int align,
        hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  int i; // edi

  for ( i = align - 1; (i & data->m_size) != 0; ++data->m_size )
  {
    if ( data->m_size == (data->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, data, 1);
    data->m_data[data->m_size] = 0;
  }
}

// File Line: 778
// RVA: 0xB3C2B0
void __fastcall hkaSplineCompressedAnimation::writeAlignQuaternion(
        hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type,
        hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  const int *i; // rdi

  for ( i = &s_writeAlignQuaternion_mask[type]; (data->m_size & *i) != 0; ++data->m_size )
  {
    if ( data->m_size == (data->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, data, 1);
    data->m_data[data->m_size] = 0;
  }
}

// File Line: 792
// RVA: 0xB3DA50
__int64 __fastcall hkaSplineCompressedAnimation::packQuantizationTypes(
        hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization translation,
        hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization rotation,
        hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization scale)
{
  return (unsigned __int8)(translation | (4 * (rotation | (16 * scale))));
}

// File Line: 804
// RVA: 0xB3DA70
__int64 __fastcall hkaSplineCompressedAnimation::packMaskAndQuantizationType(
        int mask,
        hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization floatQuatization)
{
  return mask | (2 * (unsigned int)(unsigned __int8)floatQuatization);
}

// File Line: 818
// RVA: 0xB3DB70
void __fastcall hkaSplineCompressedAnimation::packQuaternion(
        hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type,
        hkQuaternionf *in,
        char *out)
{
  switch ( type )
  {
    case POLAR32:
      hkaSignedQuaternion::packSignedQuaternion32(in, out);
      break;
    case THREECOMP40:
      hkaSignedQuaternion::packSignedQuaternion40(in, out);
      break;
    case THREECOMP48:
      hkaSignedQuaternion::packSignedQuaternion48(in, out);
      break;
    case THREECOMP24:
      hkaSignedQuaternion::packSignedQuaternion24(in, out);
      break;
    case STRAIGHT16:
      hkaSignedQuaternion::packSignedQuaternion16(in, out);
      break;
    case UNCOMPRESSED:
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

  v3 = _mm_shuffle_ps((__m128)LODWORD(maxp), (__m128)LODWORD(maxp), 0);
  v4 = _mm_shuffle_ps((__m128)LODWORD(minp), (__m128)LODWORD(minp), 0);
  v5 = _mm_sub_ps(v3, v4);
  v6 = _mm_rcp_ps(v5);
  return (unsigned int)_mm_cvtsi128_si32(
                         _mm_cvttps_epi32(
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v5, v6)), v6),
                               _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(val), (__m128)LODWORD(val), 0), v4)),
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
                                   _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(val), (__m128)LODWORD(val), 0), v4)),
                                 _mm_shuffle_ps((__m128)LODWORD(FLOAT_65535_0), (__m128)LODWORD(FLOAT_65535_0), 0)),
                               (__m128)0i64),
                             (__m128)_xmm)));
}

// File Line: 882
// RVA: 0xB3DF50
void __fastcall hkaSplineCompressedAnimation::reverseEndian(int bytes, char **dataInOut)
{
  __int64 v2; // r10
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
        v8 = *dataInOut;
        v9 = (*dataInOut)[1];
        v8[1] = (*dataInOut)[2];
        v8[2] = v9;
        *dataInOut += v2;
        return;
      case 8:
        v10 = *dataInOut;
        v11 = *v10;
        *v10 = v10[7];
        v10[7] = v11;
        v12 = *dataInOut;
        v13 = (*dataInOut)[1];
        v12[1] = (*dataInOut)[6];
        v12[6] = v13;
        v14 = *dataInOut;
        v15 = (*dataInOut)[2];
        v14[2] = (*dataInOut)[5];
        v14[5] = v15;
        v16 = *dataInOut;
        v17 = (*dataInOut)[3];
        v16[3] = (*dataInOut)[4];
        v16[4] = v17;
        break;
    }
  }
  *dataInOut += v2;
}

// File Line: 916
// RVA: 0xB3DC00
void __fastcall hkaSplineCompressedAnimation::handleEndianQuaternion(
        hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type,
        char *dataInOut)
{
  switch ( type )
  {
    case POLAR32:
      hkaSignedQuaternion::handleEndianSignedQuaternion32(dataInOut);
      break;
    case THREECOMP40:
      hkaSignedQuaternion::handleEndianSignedQuaternion40(dataInOut);
      break;
    case THREECOMP48:
      hkaSignedQuaternion::handleEndianSignedQuaternion48(dataInOut);
      break;
    case THREECOMP24:
      hkaSignedQuaternion::handleEndianSignedQuaternion24(dataInOut);
      break;
    case STRAIGHT16:
      hkaSignedQuaternion::handleEndianSignedQuaternion16(dataInOut);
      break;
    case UNCOMPRESSED:
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
  int v2; // r14d
  __int64 v3; // r15
  int v4; // ebp
  char *v5; // rbx
  unsigned int v6; // edi
  int i; // edi
  unsigned int v8; // ecx
  char *dataInOut; // [rsp+40h] [rbp+8h] BYREF

  if ( this->m_endian )
  {
    v2 = 0;
    if ( this->m_numBlocks > 0 )
    {
      v3 = 0i64;
      do
      {
        v4 = 0;
        v5 = &this->m_data.m_data[this->m_blockOffsets.m_data[v3]];
        for ( dataInOut = &v5[this->m_maskAndQuantizationSize]; v4 < this->m_numberOfTransformTracks; v5 += 4 )
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
        for ( i = 0; i < this->m_numberOfFloatTracks; ++i )
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
      while ( v2 < this->m_numBlocks );
    }
    this->m_endian = 0;
  }
}

// File Line: 990
// RVA: 0xB3E000
void __fastcall hkaSplineCompressedAnimation::handleEndianScalar(
        char mask,
        hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization type,
        char **dataInOut)
{
  int v6; // eax

  if ( mask )
  {
    v6 = hkaSplineCompressedAnimation::handleEndianKnots(mask, dataInOut);
    hkaSplineCompressedAnimation::handleEndianScalarControlPoints(mask, v6, type, dataInOut);
    *dataInOut = (char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
  }
}

// File Line: 1009
// RVA: 0xB3E060
void __fastcall hkaSplineCompressedAnimation::handleEndianRotation(
        char mask,
        hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type,
        char **dataInOut)
{
  int v6; // eax

  if ( mask )
  {
    v6 = hkaSplineCompressedAnimation::handleEndianKnots(mask, dataInOut);
    hkaSplineCompressedAnimation::handleEndianRotationControlPoints(mask, v6, type, dataInOut);
    *dataInOut = (char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
  }
}

// File Line: 1028
// RVA: 0xB3E0C0
__int64 __fastcall hkaSplineCompressedAnimation::handleEndianKnots(char mask, char **dataInOut)
{
  __int64 result; // rax

  if ( (mask & 0xF0) == 0 )
    return 0xFFFFFFFFi64;
  hkaSplineCompressedAnimation::reverseEndian(2, dataInOut);
  result = *((unsigned __int16 *)*dataInOut - 1);
  *dataInOut += (int)(result + (unsigned __int8)**dataInOut + 2) + 1;
  return result;
}

// File Line: 1063
// RVA: 0xB3E110
void __fastcall hkaSplineCompressedAnimation::handleEndianScalarControlPoints(
        unsigned __int8 mask,
        int n,
        hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization type,
        char **dataInOut)
{
  int v4; // esi
  __int64 v8; // r15
  int v9; // ebp
  int v10; // ebx
  int v11; // r14d
  __int64 v12; // r14
  __int64 v13; // rbx

  if ( mask )
  {
    v4 = 0;
    v8 = 3i64;
    *dataInOut = (char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
    v9 = 0;
    v10 = 1;
    v11 = mask;
    do
    {
      if ( (__ROL4__(v10, 4) & v11) != 0 )
      {
        hkaSplineCompressedAnimation::reverseEndian(4, dataInOut);
        hkaSplineCompressedAnimation::reverseEndian(4, dataInOut);
        ++v9;
      }
      else if ( (v11 & v10) != 0 )
      {
        hkaSplineCompressedAnimation::reverseEndian(4, dataInOut);
      }
      v10 = __ROL4__(v10, 1);
      --v8;
    }
    while ( v8 );
    if ( v9 && n >= 0 )
    {
      v12 = (unsigned int)(n + 1);
      do
      {
        if ( v9 > 0 )
        {
          v13 = (unsigned int)v9;
          do
          {
            LOBYTE(v4) = type != BITS8;
            hkaSplineCompressedAnimation::reverseEndian(v4 + 1, dataInOut);
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
void __fastcall hkaSplineCompressedAnimation::handleEndianRotationControlPoints(
        char mask,
        int n,
        hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type,
        char **dataInOut)
{
  char *v6; // rax
  __int64 v7; // rbp
  int v8; // eax
  int v9; // esi

  if ( mask )
  {
    switch ( type )
    {
      case POLAR32:
      case UNCOMPRESSED:
        v6 = (char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
        goto LABEL_5;
      case THREECOMP48:
      case STRAIGHT16:
        v6 = (char *)((unsigned __int64)(*dataInOut + 1) & 0xFFFFFFFFFFFFFFFEui64);
LABEL_5:
        *dataInOut = v6;
        break;
      default:
        break;
    }
    if ( (mask & 0xF0) != 0 )
    {
      if ( n >= 0 )
      {
        v7 = (unsigned int)(n + 1);
        do
        {
          hkaSplineCompressedAnimation::handleEndianQuaternion(type, *dataInOut);
          switch ( type )
          {
            case POLAR32:
              v8 = 4;
              break;
            case THREECOMP40:
              v8 = 5;
              break;
            case THREECOMP48:
              v8 = 6;
              break;
            case THREECOMP24:
              v8 = 3;
              break;
            case STRAIGHT16:
              v8 = 2;
              break;
            case UNCOMPRESSED:
              v8 = 16;
              break;
            default:
              v8 = 0;
              break;
          }
          *dataInOut += v8;
          --v7;
        }
        while ( v7 );
      }
    }
    else
    {
      hkaSplineCompressedAnimation::handleEndianQuaternion(type, *dataInOut);
      switch ( type )
      {
        case POLAR32:
          v9 = 4;
          break;
        case THREECOMP40:
          v9 = 5;
          break;
        case THREECOMP48:
          v9 = 6;
          break;
        case THREECOMP24:
          v9 = 3;
          break;
        case STRAIGHT16:
          v9 = 2;
          break;
        case UNCOMPRESSED:
          v9 = 16;
          break;
        default:
          v9 = 0;
          break;
      }
      *dataInOut += v9;
    }
  }
}

// File Line: 1155
// RVA: 0xB3E390
void __fastcall hkaSplineCompressedAnimation::Linspace(
        int m,
        hkArray<float,hkContainerHeapAllocator> *ub,
        float a,
        float b)
{
  float *m_data; // r9
  int v5; // edx
  unsigned int v6; // eax
  __m128 v7; // xmm5
  __m128i si128; // xmm7
  __m128 v9; // xmm0
  __m128 v10; // xmm4
  int v11; // r10d
  __m128 v12; // xmm6
  __m128 v13; // xmm6
  signed int v14; // eax
  float v15; // xmm3_4
  __int64 v16; // rax
  __m128i v17; // xmm0

  m_data = ub->m_data;
  v5 = 1;
  v6 = m - 1;
  *m_data = a;
  m_data[m] = b;
  if ( m > 1 )
  {
    if ( v6 >= 8 )
    {
      v7 = _mm_shuffle_ps((__m128)LODWORD(a), (__m128)LODWORD(a), 0);
      si128 = _mm_load_si128((const __m128i *)&_xmm);
      v9 = _mm_cvtepi32_ps(_mm_shuffle_epi32(_mm_cvtsi32_si128(m), 0));
      v10 = _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(b), (__m128)LODWORD(b), 0), v7);
      v11 = m - (int)v6 % 8;
      v12 = _mm_rcp_ps(v9);
      v13 = _mm_sub_ps(_mm_add_ps(v12, v12), _mm_mul_ps(_mm_mul_ps(v12, v12), v9));
      do
      {
        *(__m128 *)&m_data[v5] = _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_cvtepi32_ps(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v5), 0), si128)),
                                       v13),
                                     v10),
                                   v7);
        v14 = v5 + 4;
        v5 += 8;
        *(__m128 *)&m_data[v14] = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_mul_ps(
                                        _mm_cvtepi32_ps(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v14), 0), si128)),
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
        m_data[v16++] = (float)((float)(_mm_cvtepi32_ps(v17).m128_f32[0] * (float)(1.0 / (float)m)) * v15) + a;
      }
      while ( v5 < m );
    }
  }
}

