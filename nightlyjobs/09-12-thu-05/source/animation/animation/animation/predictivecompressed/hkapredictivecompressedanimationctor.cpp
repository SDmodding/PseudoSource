// File Line: 58
// RVA: 0xB389A0
void __fastcall hkaPredictiveCompressedAnimationUtil::Remapper::Remapper(
        hkaPredictiveCompressedAnimationUtil::Remapper *this,
        hkaSkeleton *s,
        hkaAnimationBinding *b,
        hkaPredictiveCompressedAnimation::CompressionParams *params)
{
  hkaInterleavedUncompressedAnimation *m_pntr; // rax
  __int64 m_size; // rcx
  int v7; // ebp
  int v8; // esi
  __int64 v10; // r15
  int *v11; // rdi
  int v12; // eax
  __int64 v13; // rcx
  __int64 v14; // rax
  __int64 v15; // r14
  int *v16; // rdi
  __int64 v17; // rcx
  hkaAnimationBinding *m_binding; // rax
  int v19; // esi
  int v20; // r14d
  __int64 v21; // r15
  hkaSkeleton::Partition *v22; // rdi
  int v23; // edx
  __int64 v24; // rcx
  int v25; // edi
  __int64 v26; // r8
  __int64 v27; // rdi
  hkStringPtr v28; // [rsp+20h] [rbp-28h] BYREF
  __int16 m_startBoneIndex; // [rsp+28h] [rbp-20h]
  __int16 m_numBones; // [rsp+2Ah] [rbp-1Eh]
  int v31; // [rsp+50h] [rbp+8h] BYREF

  this->m_skel = s;
  this->m_binding = b;
  m_pntr = (hkaInterleavedUncompressedAnimation *)b->m_animation.m_pntr;
  this->m_params = params;
  this->m_anim = m_pntr;
  m_size = s->m_bones.m_size;
  v7 = 0;
  v8 = 0x80000000;
  this->m_transformTrackFromBone.m_data = 0i64;
  this->m_transformTrackFromBone.m_size = 0;
  this->m_transformTrackFromBone.m_capacityAndFlags = 0x80000000;
  v10 = m_size;
  if ( (_DWORD)m_size )
  {
    v31 = 4 * m_size;
    v11 = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v31);
    LODWORD(m_size) = v31 / 4;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = 0x80000000;
  this->m_transformTrackFromBone.m_data = v11;
  if ( (_DWORD)m_size )
    v12 = m_size;
  this->m_transformTrackFromBone.m_size = v10;
  v13 = v10;
  this->m_transformTrackFromBone.m_capacityAndFlags = v12;
  if ( (int)v10 > 0 )
  {
    while ( v13 )
    {
      *v11++ = -1;
      --v13;
    }
  }
  v14 = s->m_floatSlots.m_size;
  this->m_floatTrackFromSlot.m_data = 0i64;
  this->m_floatTrackFromSlot.m_size = 0;
  this->m_floatTrackFromSlot.m_capacityAndFlags = 0x80000000;
  v15 = v14;
  if ( (_DWORD)v14 )
  {
    v31 = 4 * v14;
    v16 = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v31);
    LODWORD(v14) = v31 / 4;
  }
  else
  {
    v16 = 0i64;
  }
  this->m_floatTrackFromSlot.m_data = v16;
  this->m_floatTrackFromSlot.m_size = v15;
  if ( (_DWORD)v14 )
    v8 = v14;
  v17 = v15;
  this->m_floatTrackFromSlot.m_capacityAndFlags = v8;
  if ( (int)v15 > 0 )
  {
    while ( v17 )
    {
      *v16++ = -1;
      --v17;
    }
  }
  m_binding = this->m_binding;
  if ( m_binding->m_partitionIndices.m_size <= 0 )
  {
    v25 = 0;
    if ( m_binding->m_transformTrackToBoneIndices.m_size > 0 )
    {
      v26 = 0i64;
      do
        this->m_transformTrackFromBone.m_data[this->m_binding->m_transformTrackToBoneIndices.m_data[v26++]] = v25++;
      while ( v25 < this->m_binding->m_transformTrackToBoneIndices.m_size );
    }
  }
  else
  {
    v19 = 0;
    v20 = 0;
    v21 = 0i64;
    do
    {
      v22 = &this->m_skel->m_partitions.m_data[this->m_binding->m_partitionIndices.m_data[v21]];
      hkStringPtr::hkStringPtr(&v28, &v22->m_name);
      m_startBoneIndex = v22->m_startBoneIndex;
      v23 = m_startBoneIndex;
      m_numBones = v22->m_numBones;
      if ( m_startBoneIndex <= (__int16)(m_numBones + m_startBoneIndex - 1) )
      {
        v24 = m_startBoneIndex;
        do
        {
          ++v23;
          this->m_transformTrackFromBone.m_data[v24++] = v19++;
        }
        while ( v23 <= (__int16)(m_startBoneIndex + m_numBones - 1) );
      }
      hkStringPtr::~hkStringPtr(&v28);
      ++v20;
      ++v21;
    }
    while ( v20 < this->m_binding->m_partitionIndices.m_size );
  }
  if ( this->m_binding->m_floatTrackToFloatSlotIndices.m_size > 0 )
  {
    v27 = 0i64;
    do
      this->m_floatTrackFromSlot.m_data[this->m_binding->m_floatTrackToFloatSlotIndices.m_data[v27++]] = v7++;
    while ( v7 < this->m_binding->m_floatTrackToFloatSlotIndices.m_size );
  }
}binding->m_floatTrackToFloatSlot

// File Line: 134
// RVA: 0xB39190
float __fastcall hkaPredictiveCompressedAnimationUtil::Remapper::getTransformChannel(hkQsTransformf *t, int channel)
{
  float result; // xmm0_4
  hkQuaternionf v3; // xmm1
  __m128 v4; // xmm4
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  __m128i v7; // xmm2
  __m128 v8; // xmm1
  float v9[3]; // [rsp+0h] [rbp-24h]
  __m128 v10; // [rsp+Ch] [rbp-18h]

  switch ( channel )
  {
    case 0:
    case 1:
    case 2:
      result = t->m_translation.m_quad.m128_f32[channel];
      break;
    case 3:
    case 4:
    case 5:
      v3.m_vec.m_quad = (__m128)t->m_rotation;
      v4 = _mm_xor_ps(
             (__m128)_mm_slli_epi32(
                       _mm_srli_epi32(
                         (__m128i)_mm_cmplt_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255), (__m128)0i64),
                         0x1Fu),
                       0x1Fu),
             v3.m_vec.m_quad);
      v5 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v3.m_vec.m_quad, 1u), 1u);
      v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
      v7 = (__m128i)_mm_add_ps(_mm_shuffle_ps(v6, v6, 177), v6);
      v8 = _mm_cmpeq_ps((__m128)v7, (__m128)0i64);
      v10 = _mm_mul_ps(
              v4,
              _mm_or_ps(
                _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v7, 0x1Fu), 0x1Fu), (__m128)_xmm), v8),
                _mm_andnot_ps(v8, _mm_div_ps(query.m_quad, (__m128)v7))));
      result = v9[channel];
      break;
    case 6:
    case 7:
    case 8:
      result = t->m_translation.m_quad.m128_f32[channel + 2];
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}

// File Line: 199
// RVA: 0xB39090
float __fastcall hkaPredictiveCompressedAnimationUtil::Remapper::getDynamicTolerance(
        hkaPredictiveCompressedAnimationUtil::Remapper *this,
        int channel)
{
  __int64 m_size; // rcx
  int v4; // r9d
  __int64 v5; // rdx
  hkaPredictiveCompressedAnimation::CompressionParams *v6; // r9
  unsigned int v7; // edx
  bool v9; // cc
  hkaPredictiveCompressedAnimation::CompressionParams *v10; // r9
  unsigned int v11; // edx
  unsigned int v12; // edx
  hkaPredictiveCompressedAnimation::CompressionParams *m_params; // r9
  __int64 v14; // rcx

  m_size = this->m_skel->m_bones.m_size;
  if ( channel >= 9 * (int)m_size )
  {
    m_params = this->m_params;
    v14 = this->m_floatTrackFromSlot.m_data[channel - 9 * m_size];
    if ( m_params->m_floatTrackIndexToPaletteIndex.m_size <= (int)v14 )
      return m_params->m_parameterPalette.m_data->m_dynamicFloatTolerance;
    else
      return m_params->m_parameterPalette.m_data[m_params->m_floatTrackIndexToPaletteIndex.m_data[v14]].m_dynamicFloatTolerance;
  }
  else
  {
    v4 = channel % 9;
    v5 = this->m_transformTrackFromBone.m_data[channel / 9];
    if ( v4 >= 3 )
    {
      v9 = v4 < 6;
      v10 = this->m_params;
      if ( v9 )
      {
        if ( v10->m_trackIndexToPaletteIndex.m_size <= (int)v5 )
          v11 = 0;
        else
          v11 = v10->m_trackIndexToPaletteIndex.m_data[v5];
        return v10->m_parameterPalette.m_data[v11].m_dynamicRotationTolerance;
      }
      else
      {
        if ( v10->m_trackIndexToPaletteIndex.m_size <= (int)v5 )
          v12 = 0;
        else
          v12 = v10->m_trackIndexToPaletteIndex.m_data[v5];
        return v10->m_parameterPalette.m_data[v12].m_dynamicScaleTolerance;
      }
    }
    else
    {
      v6 = this->m_params;
      if ( v6->m_trackIndexToPaletteIndex.m_size <= (int)v5 )
        v7 = 0;
      else
        v7 = v6->m_trackIndexToPaletteIndex.m_data[v5];
      return v6->m_parameterPalette.m_data[v7].m_dynamicTranslationTolerance;
    }
  }
}

// File Line: 257
// RVA: 0xB38FF0
double __fastcall hkaPredictiveCompressedAnimationUtil::Remapper::frameValue(
        hkaPredictiveCompressedAnimationUtil::Remapper *this,
        int frame,
        int channel)
{
  __int64 m_size; // rcx
  double result; // xmm0_8

  m_size = this->m_skel->m_bones.m_size;
  if ( channel >= 9 * (int)m_size )
    *(_QWORD *)&result = LODWORD(this->m_anim->m_floats.m_data[frame * (__int64)this->m_anim->m_numberOfFloatTracks
                                                             + this->m_floatTrackFromSlot.m_data[channel - 9 * m_size]]);
  else
    *(float *)&result = hkaPredictiveCompressedAnimationUtil::Remapper::getTransformChannel(
                          &this->m_anim->m_transforms.m_data[frame * this->m_anim->m_numberOfTransformTracks
                                                           + this->m_transformTrackFromBone.m_data[channel / 9]],
                          channel % 9);
  return result;
}

// File Line: 309
// RVA: 0xB36530
void __fastcall hkaPredictiveCompressedAnimation::hkaPredictiveCompressedAnimation(
        hkaPredictiveCompressedAnimation *this,
        hkaAnimationBinding *binding,
        hkaSkeleton *skeleton)
{
  hkaPredictiveCompressedAnimation::CompressionParams params; // [rsp+20h] [rbp-38h] BYREF

  hkaAnimation::hkaAnimation(this, binding->m_animation.m_pntr);
  this->vfptr = (hkBaseObjectVtbl *)&hkaPredictiveCompressedAnimation::`vftable;
  this->m_compressedData.m_capacityAndFlags = 0x80000000;
  this->m_compressedData.m_data = 0i64;
  this->m_compressedData.m_size = 0;
  this->m_intData.m_data = 0i64;
  this->m_intData.m_size = 0;
  this->m_intData.m_capacityAndFlags = 0x80000000;
  this->m_floatData.m_data = 0i64;
  this->m_floatData.m_size = 0;
  this->m_floatData.m_capacityAndFlags = 0x80000000;
  hkaPredictiveCompressedAnimation::CompressionParams::CompressionParams(&params);
  hkaPredictiveCompressedAnimation::build(this, binding, skeleton, &params);
  hkaPredictiveCompressedAnimation::CompressionParams::~CompressionParams(&params);
}

// File Line: 316
// RVA: 0xB365D0
void __fastcall hkaPredictiveCompressedAnimation::hkaPredictiveCompressedAnimation(
        hkaPredictiveCompressedAnimation *this,
        hkaAnimationBinding *binding,
        hkaSkeleton *skeleton,
        hkaPredictiveCompressedAnimation::CompressionParams *params)
{
  hkaAnimation::hkaAnimation(this, binding->m_animation.m_pntr);
  this->vfptr = (hkBaseObjectVtbl *)&hkaPredictiveCompressedAnimation::`vftable;
  this->m_compressedData.m_capacityAndFlags = 0x80000000;
  this->m_compressedData.m_data = 0i64;
  this->m_compressedData.m_size = 0;
  this->m_intData.m_data = 0i64;
  this->m_intData.m_size = 0;
  this->m_intData.m_capacityAndFlags = 0x80000000;
  this->m_floatData.m_data = 0i64;
  this->m_floatData.m_size = 0;
  this->m_floatData.m_capacityAndFlags = 0x80000000;
  hkaPredictiveCompressedAnimation::build(this, binding, skeleton, params);
}

// File Line: 325
// RVA: 0xB36670
void __fastcall hkaPredictiveCompressedAnimation::hkaPredictiveCompressedAnimation(
        hkaPredictiveCompressedAnimation *this,
        hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaPredictiveCompressedAnimation::`vftable;
  if ( flag.m_finishing )
    hkaPredictiveCompressedAnimation::computeMaxCompressedBytesPerFrame(this);
}

// File Line: 337
// RVA: 0xB366A0
void __fastcall hkaPredictiveCompressedAnimation::build(
        hkaPredictiveCompressedAnimation *this,
        hkaAnimationBinding *binding,
        hkaSkeleton *skeleton,
        hkaPredictiveCompressedAnimation::CompressionParams *params)
{
  __int64 v4; // rbx
  __int64 v6; // r8
  hkaSkeleton *m_skel; // r13
  int v8; // edx
  __int64 v9; // rdi
  __m128 *v10; // r8
  unsigned int v11; // eax
  __int64 v12; // rcx
  __m128 *v13; // rax
  int v14; // eax
  int v15; // eax
  __int64 v16; // rdi
  _DWORD *v17; // r8
  unsigned int v18; // ecx
  __int64 v19; // rdx
  __int64 v20; // rcx
  _DWORD *v21; // rax
  hkaInterleavedUncompressedAnimation *m_anim; // r12
  int v23; // r14d
  __int64 v24; // r15
  __int64 m_data; // rdx
  int m_size; // r8d
  int v27; // ebx
  int v28; // r9d
  __int64 v29; // rsi
  __m128 *v30; // rdi
  bool v31; // zf
  float TransformChannel; // xmm0_4
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  int v36; // r8d
  hkaPredictiveCompressedAnimation::CompressionParams *m_params; // rsi
  int v38; // r9d
  int v39; // ebx
  __int64 v40; // r14
  _DWORD *v41; // r15
  __m128 *v42; // rdi
  int *v43; // rcx
  bool v44; // zf
  __int64 v45; // rcx
  float m_staticFloatTolerance; // xmm0_4
  unsigned int v47; // edx
  unsigned int v48; // edx
  __int64 v49; // rcx
  unsigned int v50; // edx
  __m128 v51; // xmm6
  __m128 v52; // xmm8
  __m128 v53; // xmm9
  __m128 v54; // xmm7
  int v55; // ecx
  float v56; // xmm0_4
  float v57; // xmm1_4
  int v58; // eax
  float DynamicTolerance; // xmm0_4
  __m128 v60; // xmm1
  int v61; // ecx
  int *v62; // r12
  int v63; // r11d
  int *v64; // rbx
  __int64 v65; // r9
  int v66; // r10d
  _DWORD *v67; // r8
  bool v68; // zf
  int v69; // eax
  _DWORD *v70; // rax
  __int64 v71; // rcx
  int m_capacityAndFlags; // r10d
  int v73; // ecx
  int v74; // r8d
  unsigned __int16 v75; // bx
  int v76; // r9d
  int v77; // r14d
  __int64 v78; // r15
  int *v79; // rsi
  int v80; // edi
  bool v81; // zf
  char v82; // cl
  int v83; // edi
  int *v84; // rsi
  __int64 v85; // rcx
  bool v86; // zf
  char v87; // cl
  hkaPredictiveCompressedAnimation *v88; // r14
  int v89; // ecx
  unsigned __int16 v90; // r12
  int v91; // edi
  __int64 v92; // r8
  int v93; // r15d
  int *v94; // r10
  int v95; // ebx
  bool v96; // zf
  __int64 v97; // rcx
  int *v98; // r9
  __m128 *v99; // r14
  int v100; // eax
  int v101; // r8d
  __int64 v102; // rcx
  unsigned int v103; // edx
  float m_dynamicScaleTolerance; // xmm0_4
  unsigned int v105; // edx
  unsigned int v106; // edx
  char v107; // cl
  int v108; // ecx
  float v109; // xmm7_4
  float v110; // xmm6_4
  int v111; // ecx
  int v112; // ecx
  int v113; // ecx
  bool v114; // cc
  int v115; // ebx
  float *v116; // rsi
  __int64 v117; // rcx
  int *v118; // rcx
  __int64 v119; // rax
  float v120; // xmm6_4
  int v121; // ecx
  int v122; // ecx
  float v123; // xmm7_4
  float v124; // xmm6_4
  int v125; // ecx
  int v126; // ecx
  int v127; // ecx
  float v128; // xmm6_4
  int v129; // ecx
  char v130; // cl
  hkaInterleavedUncompressedAnimation *v131; // rbx
  hkBaseObjectVtbl *vfptr; // rax
  int v133; // r15d
  int v134; // eax
  int v135; // r14d
  int v136; // eax
  int v137; // edx
  __int64 v138; // rdi
  __int64 v139; // r12
  __int64 v140; // rsi
  int *v141; // rbx
  int v142; // r8d
  int v143; // eax
  __int64 v144; // rcx
  __int64 v145; // rdx
  __int64 v146; // rax
  __int64 v147; // r9
  int v148; // r12d
  _DWORD *v149; // rbx
  int v150; // r8d
  int v151; // esi
  __int64 v152; // r14
  __m128 *v153; // r15
  int *v154; // rcx
  __int64 v155; // rax
  unsigned int v156; // xmm0_4
  __m128 v157; // xmm1
  __m128i v158; // xmm1
  __m128 v159; // xmm2
  __m128 v160; // xmm4
  int v161; // edi
  int v162; // eax
  int v163; // ecx
  __int64 v164; // r15
  hkaPredictiveCompressedAnimation *v165; // r8
  int v166; // r13d
  hkArray<unsigned char,hkContainerHeapAllocator> *p_m_compressedData; // rsi
  int v168; // r14d
  int v169; // ecx
  unsigned int v170; // ebx
  int v171; // ecx
  unsigned int v172; // ebx
  hkaPredictiveBlockCompression::Block *p_buf; // rcx
  int i; // edx
  hkaPredictiveBlockCompression::Block *v175; // rax
  __int64 v176; // rbx
  hkaPredictiveBlockCompression::Block *v177; // r11
  __int64 v178; // r10
  __int64 *v179; // rdx
  hkaPredictiveBlockCompression::Block *v180; // r8
  __int64 v181; // r9
  __int64 v182; // rax
  __int64 v183; // rbx
  int v184; // r9d
  int v185; // eax
  int v186; // eax
  unsigned int v187; // eax
  int v188; // ecx
  int v189; // ebx
  int v190; // ecx
  int v191; // r9d
  int v192; // ecx
  int v193; // esi
  int v194; // ecx
  __int64 v195; // rdi
  int *v196; // rbx
  int v197; // r8d
  hkBaseObjectVtbl *v198; // rax
  int v199; // r9d
  int v200; // eax
  int v201; // eax
  int v202; // r9d
  int v203; // eax
  int v204; // eax
  int v205; // ecx
  int v206; // ecx
  __int64 v207; // rdx
  __int64 v208; // r10
  int v209; // r14d
  int v210; // ebx
  int v211; // r15d
  int v212; // esi
  __int64 v213; // r8
  int v214; // r12d
  __int64 v215; // r9
  int *v216; // r13
  bool v217; // zf
  int v218; // ebx
  int v219; // edi
  hkOstream *v220; // rax
  hkOstream *v221; // rax
  hkOstream *v222; // rax
  hkOstream *v223; // rax
  hkOstream *v224; // rax
  hkOstream *v225; // rax
  int v226; // edx
  int v227; // ebx
  int v228; // edi
  hkOstream *v229; // rax
  hkOstream *v230; // rax
  hkOstream *v231; // rax
  hkOstream *v232; // rax
  hkOstream *v233; // rax
  hkOstream *v234; // rax
  hkOstream *v235; // rax
  hkaInterleavedUncompressedAnimation *v236; // rbx
  int v237; // eax
  hkOstream *v238; // rax
  hkOstream *v239; // rax
  hkOstream *v240; // rax
  hkOstream *v241; // rax
  hkOstream *v242; // rax
  hkOstream *v243; // rax
  hkOstream *v244; // rax
  hkOstream *v245; // rax
  int v246; // ecx
  hkArray<unsigned char,hkContainerHeapAllocator> *v247; // rdx
  float m_duration; // eax
  hkArrayBase<unsigned short> v249; // [rsp+30h] [rbp-C8h] BYREF
  hkArrayBase<unsigned short> array; // [rsp+40h] [rbp-B8h] BYREF
  unsigned int v251; // [rsp+50h] [rbp-A8h]
  int v252; // [rsp+54h] [rbp-A4h]
  hkArrayBase<float> v253; // [rsp+58h] [rbp-A0h] BYREF
  hkArrayBase<float> v254; // [rsp+68h] [rbp-90h] BYREF
  hkArrayBase<float> v255; // [rsp+78h] [rbp-80h] BYREF
  __int64 v256; // [rsp+88h] [rbp-70h]
  hkArrayBase<unsigned short> v257; // [rsp+98h] [rbp-60h] BYREF
  hkArrayBase<unsigned short> arr; // [rsp+A8h] [rbp-50h] BYREF
  __int64 v259; // [rsp+B8h] [rbp-40h]
  _DWORD *v260; // [rsp+C0h] [rbp-38h]
  int nframes[2]; // [rsp+C8h] [rbp-30h]
  hkResult v262[2]; // [rsp+D0h] [rbp-28h] BYREF
  hkResult v263[2]; // [rsp+D8h] [rbp-20h] BYREF
  int v264; // [rsp+E0h] [rbp-18h]
  hkArrayBase<unsigned short> v265; // [rsp+E8h] [rbp-10h] BYREF
  hkArrayBase<unsigned short> v266; // [rsp+F8h] [rbp+0h] BYREF
  hkArrayBase<unsigned short> v267; // [rsp+108h] [rbp+10h] BYREF
  __m128 *v268; // [rsp+118h] [rbp+20h]
  hkArrayBase<unsigned short> v269; // [rsp+120h] [rbp+28h] BYREF
  hkArrayBase<unsigned short> v270; // [rsp+130h] [rbp+38h] BYREF
  int v271; // [rsp+140h] [rbp+48h] BYREF
  int v272; // [rsp+144h] [rbp+4Ch] BYREF
  hkaPredictiveCompressedAnimationUtil::Remapper v273; // [rsp+148h] [rbp+50h] BYREF
  __int64 v274; // [rsp+188h] [rbp+90h]
  hkResult result; // [rsp+190h] [rbp+98h] BYREF
  hkErrStream v276; // [rsp+198h] [rbp+A0h] BYREF
  int v277; // [rsp+1B0h] [rbp+B8h]
  int v278; // [rsp+1B4h] [rbp+BCh]
  __int64 v279; // [rsp+1B8h] [rbp+C0h]
  hkaPredictiveBlockCompression::Block buf; // [rsp+1C8h] [rbp+D0h] BYREF
  hkaPredictiveCompressedAnimation *retaddr; // [rsp+468h] [rbp+370h]
  __int64 v282; // [rsp+478h] [rbp+380h] BYREF

  v282 = v4;
  this->m_type.m_storage = 5;
  hkaPredictiveCompressedAnimationUtil::Remapper::Remapper(&v273, skeleton, binding, params);
  m_skel = v273.m_skel;
  v8 = v273.m_skel->m_floatSlots.m_size + 9 * v273.m_skel->m_bones.m_size;
  v9 = v8;
  if ( v8 )
  {
    v271 = 48 * v8;
    v10 = (__m128 *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __int64, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                      &hkContainerHeapAllocator::s_alloc,
                      &v271,
                      v6,
                      0i64);
    v8 = v271 / 48;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 0x80000000;
  v268 = v10;
  if ( v8 )
    v11 = v8;
  v12 = v9;
  v277 = v11;
  if ( (int)v9 > 0 )
  {
    v13 = v10;
    do
    {
      if ( v13 )
      {
        *v13 = (__m128)xmmword_141A712A0;
        v13[1] = (__m128)xmmword_141A712F0;
        v13[2] = 0i64;
      }
      v13 += 3;
      --v12;
    }
    while ( v12 );
  }
  v14 = 9 * m_skel->m_bones.m_size;
  v31 = m_skel->m_floatSlots.m_size + v14 == 0;
  v15 = m_skel->m_floatSlots.m_size + v14;
  v16 = v15;
  if ( v31 )
  {
    v17 = 0i64;
  }
  else
  {
    v272 = 4 * v15;
    v17 = (_DWORD *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __m128 *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                      &hkContainerHeapAllocator::s_alloc,
                      &v272,
                      v10,
                      0i64);
    v15 = v272 / 4;
  }
  v18 = 0x80000000;
  v260 = v17;
  if ( v15 )
    v18 = v15;
  v19 = 1i64;
  v278 = v18;
  v20 = v16;
  if ( (int)v16 > 0 )
  {
    v21 = v17;
    do
    {
      if ( v21 )
        *v21 = 1;
      ++v21;
      --v20;
    }
    while ( v20 );
  }
  m_anim = v273.m_anim;
  if ( !skeleton->m_referenceFloats.m_size && v273.m_anim->m_numberOfFloatTracks > 0 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&v255.m_size, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v255.m_size,
      "Your skeleton does not have reference floats but your animation does have float tracks.  Predictive compression re"
      "quires reference floats.  You must re-export your assets.  Compression will proceed assuming zero for all reference floats.");
    hkError::messageWarning(
      -1413818222,
      (const char *)&buf,
      "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
      347);
    hkOstream::~hkOstream((hkOstream *)&v255.m_size);
  }
  v23 = 0;
  v24 = 0i64;
  if ( (__int64)m_anim->vfptr[4].__vecDelDtor(m_anim, v19) > 0 )
  {
    do
    {
      m_size = m_skel->m_bones.m_size;
      v27 = 0;
      v28 = 9 * m_size;
      v29 = 0i64;
      if ( 9 * m_size + m_skel->m_floatSlots.m_size > 0 )
      {
        v30 = v268;
        do
        {
          if ( v27 >= v28 )
            v31 = v273.m_floatTrackFromSlot.m_data[v29 - 9i64 * m_size] == -1;
          else
            v31 = v273.m_transformTrackFromBone.m_data[v27 / 9] == -1;
          if ( !v31 )
          {
            if ( v27 >= v28 )
              TransformChannel = m_anim->m_floats.m_data[v24 * m_anim->m_numberOfFloatTracks
                                                       + v273.m_floatTrackFromSlot.m_data[v29 - 9i64 * m_size]];
            else
              TransformChannel = hkaPredictiveCompressedAnimationUtil::Remapper::getTransformChannel(
                                   &m_anim->m_transforms.m_data[v23 * m_anim->m_numberOfTransformTracks
                                                              + v273.m_transformTrackFromBone.m_data[v27 / 9]],
                                   v27 % 9);
            *(float *)&v282 = TransformChannel;
            v33 = _mm_shuffle_ps((__m128)LODWORD(TransformChannel), (__m128)LODWORD(TransformChannel), 0);
            v34 = _mm_min_ps(v33, *v30);
            v35 = _mm_max_ps(v33, v30[1]);
            *v30 = v34;
            v30[1] = v35;
          }
          m_size = m_skel->m_bones.m_size;
          ++v27;
          v28 = 9 * m_size;
          ++v29;
          v30 += 3;
        }
        while ( v27 < 9 * m_size + m_skel->m_floatSlots.m_size );
      }
      ++v23;
      ++v24;
    }
    while ( v23 < ((int (__fastcall *)(hkaInterleavedUncompressedAnimation *))m_anim->vfptr[4].__vecDelDtor)(m_anim) );
  }
  v36 = m_skel->m_bones.m_size;
  m_params = v273.m_params;
  v38 = 9 * v36;
  v39 = 0;
  v40 = 0i64;
  if ( 9 * v36 + m_skel->m_floatSlots.m_size > 0 )
  {
    v41 = v260;
    v42 = v268 + 1;
    do
    {
      if ( v39 >= v38 )
      {
        m_data = (__int64)v273.m_floatTrackFromSlot.m_data;
        v43 = v273.m_transformTrackFromBone.m_data;
        v44 = v273.m_floatTrackFromSlot.m_data[v40 - 9i64 * v36] == -1;
      }
      else
      {
        v43 = v273.m_transformTrackFromBone.m_data;
        m_data = (__int64)v273.m_floatTrackFromSlot.m_data;
        v44 = v273.m_transformTrackFromBone.m_data[v39 / 9] == -1;
      }
      if ( !v44 )
      {
        if ( v39 >= v38 )
        {
          v49 = *(int *)(m_data + 4 * (v40 - 9i64 * v36));
          if ( m_params->m_floatTrackIndexToPaletteIndex.m_size <= (int)v49 )
            v50 = 0;
          else
            v50 = m_params->m_floatTrackIndexToPaletteIndex.m_data[v49];
          m_staticFloatTolerance = m_params->m_parameterPalette.m_data[v50].m_staticFloatTolerance;
        }
        else
        {
          v45 = v43[v39 / 9];
          if ( v39 % 9 >= 3 )
          {
            if ( v39 % 9 >= 6 )
            {
              if ( m_params->m_trackIndexToPaletteIndex.m_size <= (int)v45 )
                v48 = 0;
              else
                v48 = m_params->m_trackIndexToPaletteIndex.m_data[v45];
              m_staticFloatTolerance = m_params->m_parameterPalette.m_data[v48].m_staticScaleTolerance;
            }
            else
            {
              if ( m_params->m_trackIndexToPaletteIndex.m_size <= (int)v45 )
                v47 = 0;
              else
                v47 = m_params->m_trackIndexToPaletteIndex.m_data[v45];
              m_staticFloatTolerance = m_params->m_parameterPalette.m_data[v47].m_staticRotationTolerance;
            }
          }
          else if ( m_params->m_trackIndexToPaletteIndex.m_size <= (int)v45 )
          {
            m_staticFloatTolerance = m_params->m_parameterPalette.m_data->m_staticTranslationTolerance;
          }
          else
          {
            m_staticFloatTolerance = m_params->m_parameterPalette.m_data[m_params->m_trackIndexToPaletteIndex.m_data[v45]].m_staticTranslationTolerance;
          }
        }
        v51 = *v42;
        v52 = v42[-1];
        *(float *)&v282 = m_staticFloatTolerance;
        v252 = 947913728;
        v53 = _mm_sub_ps(v51, v52);
        v54 = _mm_max_ps(
                _mm_shuffle_ps((__m128)LODWORD(m_staticFloatTolerance), (__m128)LODWORD(m_staticFloatTolerance), 0),
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)0x38800400u, (__m128)0x38800400u, 0),
                  _mm_mul_ps(v53, (__m128)xmmword_141A711B0)));
        v42[1] = v54;
        v55 = 9 * m_skel->m_bones.m_size;
        if ( v39 >= v55 )
        {
          if ( m_skel->m_referenceFloats.m_size > v39 - v55 )
            v56 = m_skel->m_referenceFloats.m_data[v39 - v55];
          else
            v56 = 0.0;
        }
        else
        {
          v56 = hkaPredictiveCompressedAnimationUtil::Remapper::getTransformChannel(
                  &m_skel->m_referencePose.m_data[v39 / 9],
                  v39 % 9);
        }
        *(float *)&v282 = v56;
        LODWORD(v57) = _mm_shuffle_ps((__m128)LODWORD(v56), (__m128)LODWORD(v56), 0).m128_u32[0];
        if ( v53.m128_f32[0] >= (float)(v54.m128_f32[0] + v54.m128_f32[0]) )
          v58 = 2;
        else
          v58 = fmax(
                  COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v51.m128_f32[0] - v57)) >> 1),
                  COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v52.m128_f32[0] - v57)) >> 1)) < v54.m128_f32[0];
        v41[v40] = v58;
        DynamicTolerance = hkaPredictiveCompressedAnimationUtil::Remapper::getDynamicTolerance(&v273, v39);
        v264 = 947913728;
        v60 = _mm_sub_ps(*v42, v42[-1]);
        *(float *)&v282 = DynamicTolerance;
        v42[1] = _mm_max_ps(
                   _mm_shuffle_ps((__m128)LODWORD(DynamicTolerance), (__m128)LODWORD(DynamicTolerance), 0),
                   _mm_mul_ps(
                     _mm_mul_ps(v60, (__m128)xmmword_141A711B0),
                     _mm_shuffle_ps((__m128)0x38800400u, (__m128)0x38800400u, 0)));
      }
      v36 = m_skel->m_bones.m_size;
      ++v39;
      v38 = 9 * v36;
      ++v40;
      v42 += 3;
    }
    while ( v39 < 9 * v36 + m_skel->m_floatSlots.m_size );
  }
  v61 = m_skel->m_bones.m_size;
  v62 = v273.m_transformTrackFromBone.m_data;
  v63 = 0;
  if ( v61 > 0 )
  {
    m_data = (__int64)v260;
    v64 = v273.m_floatTrackFromSlot.m_data;
    v65 = 0i64;
    v66 = 0;
    v67 = v260 + 3;
    do
    {
      if ( v66 >= 9 * v61 )
      {
        v68 = v64[v65 - 9i64 * v61] == -1;
      }
      else
      {
        m_data = (__int64)v260;
        v68 = v62[v66 / 9] == -1;
      }
      if ( !v68 )
      {
        v69 = *v67 == 1;
        if ( v67[1] == 1 )
          ++v69;
        if ( *(_DWORD *)(m_data + 4 * v65 + 20) == 1 )
          ++v69;
        if ( (unsigned int)(v69 - 1) <= 1 )
        {
          v70 = v67;
          v71 = 3i64;
          do
          {
            if ( *v70 == 1 )
              *v70 = 0;
            ++v70;
            --v71;
          }
          while ( v71 );
        }
      }
      v61 = m_skel->m_bones.m_size;
      ++v63;
      v66 += 9;
      v65 += 9i64;
      v67 += 9;
    }
    while ( v63 < v61 );
  }
  m_capacityAndFlags = 0x80000000;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v73 = m_skel->m_bones.m_size;
  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  v78 = 0i64;
  if ( v73 > 0 )
  {
    v79 = v273.m_floatTrackFromSlot.m_data;
    v80 = 0;
    do
    {
      if ( v80 >= 9 * v73 )
      {
        v81 = v79[9 * (v78 - v73)] == -1;
      }
      else
      {
        m_data = (unsigned int)((int)((unsigned __int64)(954437177i64 * v80) >> 32) >> 1);
        v81 = v62[v80 / 9] == -1;
      }
      v82 = v76++;
      v75 |= !v81 << v82;
      if ( v76 == 16 )
      {
        if ( v74 == (m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 2);
          v74 = array.m_size;
        }
        v76 = 0;
        array.m_data[v74] = v75;
        m_capacityAndFlags = array.m_capacityAndFlags;
        v74 = array.m_size + 1;
        v75 = 0;
        ++array.m_size;
      }
      v73 = m_skel->m_bones.m_size;
      ++v77;
      v80 += 9;
      ++v78;
    }
    while ( v77 < v73 );
    m_params = v273.m_params;
    if ( v76 > 0 )
    {
      if ( v74 == (m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 2);
        v74 = array.m_size;
      }
      v76 = 0;
      array.m_data[v74] = v75;
      m_capacityAndFlags = array.m_capacityAndFlags;
      v74 = array.m_size + 1;
      v75 = 0;
      ++array.m_size;
    }
  }
  v83 = 0;
  if ( m_skel->m_floatSlots.m_size > 0 )
  {
    v84 = v273.m_floatTrackFromSlot.m_data;
    do
    {
      v85 = m_skel->m_bones.m_size;
      m_data = (unsigned int)(9 * v85 + v83);
      if ( (int)m_data >= 9 * (int)v85 )
      {
        v86 = v84[(int)m_data - 9 * v85] == -1;
      }
      else
      {
        m_data = (unsigned int)((int)((unsigned __int64)(954437177i64 * (int)m_data) >> 32) >> 1);
        v86 = v62[(int)(m_data + ((unsigned int)m_data >> 31))] == -1;
      }
      v87 = v76++;
      v75 |= !v86 << v87;
      if ( v76 == 16 )
      {
        if ( v74 == (m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 2);
          v74 = array.m_size;
        }
        v76 = 0;
        array.m_data[v74] = v75;
        m_capacityAndFlags = array.m_capacityAndFlags;
        v74 = array.m_size + 1;
        v75 = 0;
        ++array.m_size;
      }
      ++v83;
    }
    while ( v83 < m_skel->m_floatSlots.m_size );
    m_params = v273.m_params;
  }
  if ( v76 > 0 )
  {
    if ( v74 == (m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 2);
      v74 = array.m_size;
    }
    array.m_data[v74] = v75;
    ++array.m_size;
  }
  v88 = retaddr;
  v249.m_data = 0i64;
  v249.m_size = 0;
  v249.m_capacityAndFlags = 0x80000000;
  v266.m_data = 0i64;
  v266.m_size = 0;
  retaddr->m_firstFloatBlockScaleAndOffsetIndex = 0;
  v266.m_capacityAndFlags = 0x80000000;
  v267.m_data = 0i64;
  v267.m_size = 0;
  v267.m_capacityAndFlags = 0x80000000;
  v269.m_data = 0i64;
  v269.m_size = 0;
  v269.m_capacityAndFlags = 0x80000000;
  v270.m_data = 0i64;
  v270.m_size = 0;
  v270.m_capacityAndFlags = 0x80000000;
  v265.m_data = 0i64;
  v265.m_size = 0;
  v265.m_capacityAndFlags = 0x80000000;
  v253.m_data = 0i64;
  v253.m_size = 0;
  v253.m_capacityAndFlags = 0x80000000;
  v254.m_data = 0i64;
  v254.m_size = 0;
  v254.m_capacityAndFlags = 0x80000000;
  v255.m_data = (float *)0x8000000000000000i64;
  v89 = m_skel->m_bones.m_size;
  v90 = 0;
  v91 = 0;
  v92 = 0i64;
  v93 = 0;
  LODWORD(v282) = 0;
  if ( v89 > 0 )
  {
    while ( 1 )
    {
      v94 = v273.m_transformTrackFromBone.m_data;
      v95 = 9 * v93;
      if ( 9 * v93 >= 9 * v89 )
      {
        v96 = v273.m_floatTrackFromSlot.m_data[v95 - 9i64 * v89] == -1;
      }
      else
      {
        m_data = (unsigned int)((int)((unsigned __int64)(954437177i64 * v95) >> 32) >> 1);
        v96 = v273.m_transformTrackFromBone.m_data[v95 / 9] == -1;
      }
      if ( !v96 )
        break;
LABEL_168:
      v89 = m_skel->m_bones.m_size;
      LODWORD(v282) = ++v93;
      if ( v93 >= v89 )
      {
        v88 = retaddr;
        goto LABEL_170;
      }
    }
    v97 = v95;
    v98 = &v260[v95];
    m_data = 9i64;
    *(_QWORD *)&v263[0].m_enum = v95;
    *(_QWORD *)&v262[0].m_enum = v98;
    *(_QWORD *)nframes = 9i64;
    v99 = &v268[3 * v95 + 1];
    while ( 1 )
    {
      v100 = *v98;
      LODWORD(v259) = v100;
      if ( v100 == 2 )
        break;
      if ( !v100 )
      {
        v120 = (float)(v99[-1].m128_f32[0] + v99->m128_f32[0]) * 0.5;
        if ( LODWORD(v255.m_data) == (HIDWORD(v255.m_data) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v255, 4);
        v255.m_data[SLODWORD(v255.m_data)] = v120;
        ++LODWORD(v255.m_data);
        v121 = v269.m_size;
        if ( v269.m_size == (v269.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v269, 2);
          v121 = v269.m_size;
        }
        v269.m_data[v121] = v95 % 9 + 12 * (v95 / 9) + v95 % 9 / 3;
        ++v269.m_size;
        v92 = (unsigned int)v265.m_size;
LABEL_159:
        v93 = v282;
        if ( v95 < 9 * m_skel->m_bones.m_size
          && (unsigned int)(v95 % 9 - 3) <= 2
          && (!(_DWORD)v92 || v265.m_data[(int)v92 - 1] != (_DWORD)v282) )
        {
          if ( (_DWORD)v92 == (v265.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v265, 2);
            LODWORD(v92) = v265.m_size;
          }
          v265.m_data[(int)v92] = v93;
          v92 = (unsigned int)++v265.m_size;
        }
        m_data = *(_QWORD *)nframes;
        v97 = *(_QWORD *)&v263[0].m_enum;
        v98 = *(int **)&v262[0].m_enum;
        goto LABEL_167;
      }
LABEL_158:
      if ( v100 != 1 )
        goto LABEL_159;
LABEL_167:
      v94 = v273.m_transformTrackFromBone.m_data;
      ++v97;
      ++v98;
      ++v95;
      v99 += 3;
      --m_data;
      *(_QWORD *)&v263[0].m_enum = v97;
      *(_QWORD *)&v262[0].m_enum = v98;
      *(_QWORD *)nframes = m_data;
      if ( !m_data )
        goto LABEL_168;
    }
    if ( v95 < 9 * m_skel->m_bones.m_size
      && (v101 = v95 % 9, (unsigned int)(v95 % 9 - 3) <= 2)
      && ((v102 = v94[v95 / 9], v101 >= 3)
        ? (v101 >= 6
         ? (m_params->m_trackIndexToPaletteIndex.m_size <= (int)v102
          ? (v106 = 0)
          : (v106 = m_params->m_trackIndexToPaletteIndex.m_data[v102]),
            m_dynamicScaleTolerance = m_params->m_parameterPalette.m_data[v106].m_dynamicScaleTolerance)
         : (m_params->m_trackIndexToPaletteIndex.m_size <= (int)v102
          ? (v105 = 0)
          : (v105 = m_params->m_trackIndexToPaletteIndex.m_data[v102]),
            m_dynamicScaleTolerance = m_params->m_parameterPalette.m_data[v105].m_dynamicRotationTolerance))
        : (m_params->m_trackIndexToPaletteIndex.m_size <= (int)v102
         ? (v103 = 0)
         : (v103 = m_params->m_trackIndexToPaletteIndex.m_data[v102]),
           m_dynamicScaleTolerance = m_params->m_parameterPalette.m_data[v103].m_dynamicTranslationTolerance),
          m_dynamicScaleTolerance == 0.0) )
    {
      *v98 = 3;
      v107 = v91;
      v99[-1] = g_vectorfConstants[0];
      v252 = 947913728;
      ++v91;
      LODWORD(v259) = 3;
      *(hkVector4f *)v99 = (hkVector4f)query.m_quad;
      v90 |= 1 << v107;
      v99[1] = _mm_max_ps(
                 aabbOut.m_quad,
                 _mm_mul_ps(
                   _mm_mul_ps(_mm_sub_ps(query.m_quad, v99[-1]), (__m128)xmmword_141A711B0),
                   _mm_shuffle_ps((__m128)0x38800400u, (__m128)0x38800400u, 0)));
      if ( v91 != 16 )
      {
LABEL_153:
        v113 = v266.m_size;
        if ( v266.m_size == (v266.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v266, 2);
          v113 = v266.m_size;
        }
        v266.m_data[v113] = v95 % 9 + 12 * (v95 / 9) + v95 % 9 / 3;
        ++v266.m_size;
        v92 = (unsigned int)v265.m_size;
        v98 = *(int **)&v262[0].m_enum;
        v93 = v282;
        m_data = *(_QWORD *)nframes;
        if ( !(v266.m_size % 16) )
          retaddr->m_firstFloatBlockScaleAndOffsetIndex = v253.m_size;
        v100 = v259;
        v97 = *(_QWORD *)&v263[0].m_enum;
        goto LABEL_158;
      }
      v108 = v249.m_size;
      if ( v249.m_size == (v249.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v249, 2);
        v108 = v249.m_size;
      }
      v249.m_data[v108] = v90;
      v90 = 0;
    }
    else
    {
      v109 = v99[1].m128_f32[0] + v99[1].m128_f32[0];
      v110 = (float)(v99[-1].m128_f32[0] + v99->m128_f32[0]) * 0.5;
      if ( v253.m_size == (v253.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v253, 4);
      v253.m_data[v253.m_size] = v109;
      v111 = v254.m_size;
      ++v253.m_size;
      if ( v254.m_size == (v254.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v254, 4);
        v111 = v254.m_size;
      }
      v254.m_data[v111] = v110;
      ++v254.m_size;
      if ( ++v91 != 16 )
        goto LABEL_153;
      v112 = v249.m_size;
      if ( v249.m_size == (v249.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v249, 2);
        v112 = v249.m_size;
      }
      v249.m_data[v112] = v90;
      v90 = 0;
    }
    ++v249.m_size;
    v91 = 0;
    goto LABEL_153;
  }
LABEL_170:
  v114 = m_skel->m_floatSlots.m_size <= 0;
  LODWORD(v282) = v266.m_size;
  v115 = 0;
  if ( !v114 )
  {
    v116 = (float *)v268;
    do
    {
      v117 = m_skel->m_bones.m_size;
      v92 = (unsigned int)(v115 + 9 * v117);
      if ( (int)v92 >= 9 * (int)v117 )
      {
        v119 = (int)v92 - 9 * v117;
        v118 = v273.m_floatTrackFromSlot.m_data;
      }
      else
      {
        v118 = v273.m_transformTrackFromBone.m_data;
        m_data = (unsigned int)((int)((unsigned __int64)(954437177i64 * (int)v92) >> 32) >> 1);
        v119 = (int)v92 / 9;
      }
      if ( v118[v119] != -1 )
      {
        v122 = v260[(int)v92];
        if ( v122 == 2 )
        {
          v123 = v116[12 * (int)v92 + 8] + v116[12 * (int)v92 + 8];
          v124 = (float)(v116[12 * (int)v92 + 4] + v116[12 * (int)v92]) * 0.5;
          if ( v253.m_size == (v253.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v253, 4);
          v253.m_data[v253.m_size] = v123;
          v125 = v254.m_size;
          ++v253.m_size;
          if ( v254.m_size == (v254.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v254, 4);
            v125 = v254.m_size;
          }
          v254.m_data[v125] = v124;
          ++v254.m_size;
          if ( ++v91 == 16 )
          {
            v126 = v249.m_size;
            if ( v249.m_size == (v249.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v249, 2);
              v126 = v249.m_size;
            }
            v91 = 0;
            v249.m_data[v126] = v90;
            ++v249.m_size;
            v90 = 0;
          }
          v127 = v267.m_size;
          if ( v267.m_size == (v267.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v267, 2);
            v127 = v267.m_size;
          }
          v267.m_data[v127] = v115;
          ++v267.m_size;
        }
        else if ( !v122 )
        {
          v128 = (float)(v116[12 * (int)v92 + 4] + v116[12 * (int)v92]) * 0.5;
          if ( LODWORD(v255.m_data) == (HIDWORD(v255.m_data) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v255, 4);
          v255.m_data[SLODWORD(v255.m_data)] = v128;
          v129 = v270.m_size;
          ++LODWORD(v255.m_data);
          if ( v270.m_size == (v270.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v270, 2);
            v129 = v270.m_size;
          }
          v270.m_data[v129] = v115;
          ++v270.m_size;
        }
      }
      ++v115;
    }
    while ( v115 < m_skel->m_floatSlots.m_size );
  }
  if ( v91 > 0 )
  {
    while ( 1 )
    {
      v130 = v91++;
      v90 |= 1 << v130;
      if ( v91 == 16 )
        break;
      if ( v91 <= 0 )
        goto LABEL_208;
    }
    if ( v249.m_size == (v249.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v249, 2);
    v249.m_data[v249.m_size++] = v90;
  }
LABEL_208:
  v131 = v273.m_anim;
  *(_QWORD *)v88->m_intArrayOffsets = -1i64;
  *(_QWORD *)&v88->m_intArrayOffsets[2] = -1i64;
  *(_QWORD *)&v88->m_intArrayOffsets[4] = -1i64;
  *(_QWORD *)&v88->m_intArrayOffsets[6] = -1i64;
  v88->m_intArrayOffsets[8] = -1;
  *(_QWORD *)v88->m_floatArrayOffsets = -1i64;
  arr.m_capacityAndFlags = 0x80000000;
  v88->m_floatArrayOffsets[2] = -1;
  arr.m_data = 0i64;
  arr.m_size = 0;
  v257.m_data = 0i64;
  v257.m_size = 0;
  v257.m_capacityAndFlags = 0x80000000;
  vfptr = v131->vfptr;
  v264 = 0;
  v133 = 0;
  v252 = 0;
  if ( ((int (__fastcall *)(hkaInterleavedUncompressedAnimation *, __int64, __int64))vfptr[4].__vecDelDtor)(
         v131,
         m_data,
         v92) > 0 )
  {
    do
    {
      v134 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *))v131->vfptr[4].__vecDelDtor)(v131);
      v135 = 16;
      HIDWORD(v256) = 0x80000000;
      v136 = v134 - v133;
      if ( v136 < 16 )
        v135 = v136;
      v137 = 0;
      nframes[0] = v135;
      v138 = 0i64;
      *(_QWORD *)&v255.m_size = 0i64;
      LODWORD(v256) = 0;
      if ( v135 <= 0 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &v255.m_size, v135, 16);
        v137 = v256;
        v138 = *(_QWORD *)&v255.m_size;
      }
      v139 = v135;
      v274 = v135;
      v140 = v137 - v135 - 1;
      if ( v137 - v135 - 1 >= 0 )
      {
        v141 = (int *)(16 * v140 + 16i64 * v135 + 12 + v138);
        do
        {
          v142 = *v141;
          *(v141 - 1) = 0;
          if ( v142 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              *(void **)(v141 - 3),
              2 * (v142 & 0x3FFFFFFF));
          *(_QWORD *)(v141 - 3) = 0i64;
          *v141 = 0x80000000;
          v141 -= 4;
          --v140;
        }
        while ( v140 >= 0 );
        v137 = v256;
        v138 = *(_QWORD *)&v255.m_size;
      }
      v143 = v135 - v137;
      v144 = v138 + 16i64 * v137;
      v145 = v135 - v137;
      if ( v143 > 0 )
      {
        do
        {
          if ( v144 )
          {
            *(_QWORD *)v144 = 0i64;
            *(_DWORD *)(v144 + 8) = 0;
            *(_DWORD *)(v144 + 12) = 0x80000000;
          }
          v144 += 16i64;
          --v145;
        }
        while ( v145 );
        v138 = *(_QWORD *)&v255.m_size;
      }
      LODWORD(v256) = v135;
      if ( v135 > 0 )
      {
        v146 = 0i64;
        v147 = v135;
        v279 = v135;
        v259 = 0i64;
        v148 = v133;
        do
        {
          v145 = (unsigned int)m_skel->m_bones.m_size;
          v149 = (_DWORD *)(v146 + v138);
          v150 = 9 * v145;
          v151 = 0;
          v152 = 0i64;
          if ( 9 * (int)v145 + m_skel->m_floatSlots.m_size > 0 )
          {
            v153 = v268 + 2;
            do
            {
              if ( v151 >= v150 )
              {
                v155 = v152 - 9i64 * (int)v145;
                v154 = v273.m_floatTrackFromSlot.m_data;
              }
              else
              {
                v154 = v273.m_transformTrackFromBone.m_data;
                v155 = v151 / 9;
              }
              if ( v154[v155] != -1 && (unsigned int)(v260[v152] - 2) <= 1 )
              {
                *(float *)&v156 = hkaPredictiveCompressedAnimationUtil::Remapper::frameValue(&v273, v148, v151);
                v157 = *v153;
                v251 = v156;
                v158 = (__m128i)_mm_add_ps(v157, v157);
                v159 = _mm_cmpeq_ps((__m128)0i64, (__m128)v158);
                v160 = _mm_mul_ps(
                         _mm_or_ps(
                           _mm_and_ps(
                             _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v158, 0x1Fu), 0x1Fu), (__m128)_xmm),
                             v159),
                           _mm_andnot_ps(v159, _mm_div_ps(query.m_quad, (__m128)v158))),
                         _mm_sub_ps(
                           _mm_shuffle_ps((__m128)v251, (__m128)v251, 0),
                           _mm_mul_ps(_mm_add_ps(v153[-2], v153[-1]), (__m128)xmmword_141A711B0)));
                v161 = _mm_cvtsi128_si32(
                         _mm_cvttps_epi32(
                           _mm_add_ps(
                             _mm_xor_ps(
                               (__m128)_mm_slli_epi32(
                                         _mm_srli_epi32((__m128i)_mm_cmplt_ps(v160, (__m128)0i64), 0x1Fu),
                                         0x1Fu),
                               (__m128)xmmword_141A711B0),
                             v160)));
                if ( v161 >= -8191 )
                {
                  if ( v161 > 0x1FFF )
                    LOWORD(v161) = 0x1FFF;
                }
                else
                {
                  LOWORD(v161) = -8191;
                }
                if ( v149[2] == (v149[3] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v149, 2);
                *(_WORD *)(*(_QWORD *)v149 + 2i64 * (int)v149[2]++) = v161;
              }
              v145 = (unsigned int)m_skel->m_bones.m_size;
              ++v151;
              v150 = 9 * v145;
              ++v152;
              v153 += 3;
            }
            while ( v151 < 9 * (int)v145 + m_skel->m_floatSlots.m_size );
            v138 = *(_QWORD *)&v255.m_size;
            v147 = v279;
          }
          ++v148;
          v146 = v259 + 16;
          v279 = --v147;
          v259 += 16i64;
        }
        while ( v147 );
        v139 = v274;
      }
      v163 = 0;
      v164 = 0i64;
      v251 = *(_DWORD *)(v138 + 8);
      v162 = v251;
      LODWORD(v259) = 0;
      v274 = (int)v251;
      if ( (int)v251 > 0 )
      {
        v165 = retaddr;
        v166 = nframes[0];
        p_m_compressedData = &retaddr->m_compressedData;
        while ( 1 )
        {
          v168 = 16;
          if ( v162 < 16 )
            v168 = v162;
          if ( (int)v282 >= v164 && (int)v282 < v168 + v163 )
          {
            v169 = v257.m_size;
            v170 = v165->m_compressedData.m_size - v264;
            if ( v257.m_size == (v257.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v257, 2);
              v169 = v257.m_size;
            }
            v257.m_data[v169] = v170;
            v171 = v257.m_size + 1;
            v172 = HIWORD(v170);
            v257.m_size = v171;
            if ( v171 == (v257.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v257, 2);
              v171 = v257.m_size;
            }
            v257.m_data[v171] = v172;
            ++v257.m_size;
            v138 = *(_QWORD *)&v255.m_size;
          }
          if ( v166 < 16 || v168 < 16 )
          {
            p_buf = &buf;
            for ( i = 31; i >= 0; --i )
            {
              v175 = p_buf;
              p_buf = (hkaPredictiveBlockCompression::Block *)((char *)p_buf + 16);
              *(_OWORD *)&v175->data[0][0] = 0i64;
            }
          }
          v176 = v168;
          if ( v168 > 0 )
          {
            v177 = &buf;
            v178 = 2 * v164;
            do
            {
              if ( v139 > 0 )
              {
                v179 = (__int64 *)v138;
                v180 = v177;
                v181 = v139;
                do
                {
                  v182 = *v179;
                  v180 = (hkaPredictiveBlockCompression::Block *)((char *)v180 + 2);
                  v179 += 2;
                  v180[-1].data[15][15] = *(_WORD *)(v178 + v182);
                  --v181;
                }
                while ( v181 );
              }
              v178 += 2i64;
              v177 = (hkaPredictiveBlockCompression::Block *)((char *)v177 + 32);
              --v176;
            }
            while ( v176 );
          }
          v183 = retaddr->m_compressedData.m_size;
          v184 = v183 + 528;
          v185 = retaddr->m_compressedData.m_capacityAndFlags & 0x3FFFFFFF;
          if ( v185 >= (int)v183 + 528 )
          {
            v262[0].m_enum = HK_SUCCESS;
          }
          else
          {
            v186 = 2 * v185;
            if ( v184 < v186 )
              v184 = v186;
            hkArrayUtil::_reserve(v262, &hkContainerHeapAllocator::s_alloc, p_m_compressedData, v184, 1);
          }
          retaddr->m_compressedData.m_size += 528;
          v187 = (unsigned int)hkaPredictiveBlockCompression::encodeBlock(
                                 &buf,
                                 v166,
                                 v168,
                                 &p_m_compressedData->m_data[v183]);
          v188 = retaddr->m_compressedData.m_capacityAndFlags & 0x3FFFFFFF;
          v189 = v187 - LODWORD(p_m_compressedData->m_data);
          if ( v188 >= v189 )
          {
            v263[0].m_enum = HK_SUCCESS;
          }
          else
          {
            v190 = 2 * v188;
            v191 = v187 - LODWORD(p_m_compressedData->m_data);
            if ( v189 < v190 )
              v191 = v190;
            hkArrayUtil::_reserve(v263, &hkContainerHeapAllocator::s_alloc, p_m_compressedData, v191, 1);
          }
          v164 += 16i64;
          v163 = v259 + 16;
          v162 = v251 - 16;
          retaddr->m_compressedData.m_size = v189;
          LODWORD(v259) = v163;
          v251 = v162;
          if ( v164 >= v274 )
            break;
          v138 = *(_QWORD *)&v255.m_size;
          v165 = retaddr;
        }
        m_skel = v273.m_skel;
      }
      v88 = retaddr;
      v192 = arr.m_size;
      v193 = retaddr->m_compressedData.m_size;
      v264 = v193;
      if ( arr.m_size == (arr.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &arr, 2);
        v192 = arr.m_size;
      }
      arr.m_data[v192] = v193;
      v194 = arr.m_size + 1;
      arr.m_size = v194;
      if ( v194 == (arr.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &arr, 2);
        v194 = arr.m_size;
      }
      arr.m_data[v194] = HIWORD(v193);
      ++arr.m_size;
      v195 = (int)v256 - 1;
      if ( (int)v256 - 1 >= 0 )
      {
        v196 = (int *)(16i64 * ((int)v256 - 1) + *(_QWORD *)&v255.m_size + 12i64);
        do
        {
          v197 = *v196;
          *(v196 - 1) = 0;
          if ( v197 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              *(void **)(v196 - 3),
              2 * (v197 & 0x3FFFFFFF));
          *(_QWORD *)(v196 - 3) = 0i64;
          *v196 = 0x80000000;
          v196 -= 4;
          --v195;
        }
        while ( v195 >= 0 );
      }
      LODWORD(v256) = 0;
      if ( v256 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          *(void **)&v255.m_size,
          16 * HIDWORD(v256));
      v131 = v273.m_anim;
      *(_QWORD *)&v255.m_size = 0i64;
      v198 = v273.m_anim->vfptr;
      HIDWORD(v256) = 0x80000000;
      v252 += 15;
      v133 = v252;
    }
    while ( v133 < (__int64)v198[4].__vecDelDtor(v273.m_anim, v145) );
  }
  hkaPredictiveCompressedAnimation::addArray(v88, &arr, BLOCK_OFFSETS);
  hkaPredictiveCompressedAnimation::addArray(v88, &v257, FIRST_FLOAT_BLOCK_OFFSETS);
  hkaPredictiveCompressedAnimation::addArray(v88, &array, IS_ANIMATED_BITMAP);
  hkaPredictiveCompressedAnimation::addArray(v88, &v249, IS_FIXED_RANGE_BITMAP);
  hkaPredictiveCompressedAnimation::addArray(v88, &v266, DYNAMIC_BONE_TRACK_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v267, DYNAMIC_FLOAT_TRACK_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v269, STATIC_BONE_TRACK_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v270, STATIC_FLOAT_TRACK_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v265, RENORM_QUATERNION_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v255, STATIC_VALUES);
  hkaPredictiveCompressedAnimation::addArray(v88, &v253, DYNAMIC_SCALES);
  hkaPredictiveCompressedAnimation::addArray(v88, &v254, DYNAMIC_OFFSETS);
  v199 = v88->m_intData.m_size + 8;
  v200 = v88->m_intData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v200 < v199 )
  {
    v201 = 2 * v200;
    if ( v199 < v201 )
      v199 = v201;
    hkArrayUtil::_reserve((hkResult *)&v282, &hkContainerHeapAllocator::s_alloc, &v88->m_intData, v199, 2);
  }
  v88->m_intData.m_size += 8;
  v202 = v88->m_floatData.m_size + 4;
  v203 = v88->m_floatData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v203 < v202 )
  {
    v204 = 2 * v203;
    if ( v202 < v204 )
      v202 = v204;
    hkArrayUtil::_reserve((hkResult *)&v282, &hkContainerHeapAllocator::s_alloc, &v88->m_floatData, v202, 4);
  }
  v88->m_floatData.m_size += 4;
  v205 = v88->m_intData.m_size;
  if ( v205 < (v88->m_intData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, &v88->m_intData, 2, 0i64, v205);
  v206 = v88->m_floatData.m_size;
  if ( v206 < (v88->m_floatData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, &v88->m_floatData, 4, 0i64, v206);
  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    840219356i64,
    "Compression");
  v208 = m_skel->m_bones.m_size;
  v209 = 0;
  v210 = 9 * v208 + m_skel->m_floatSlots.m_size;
  v211 = 0;
  *(_QWORD *)&v255.m_size = 0i64;
  v256 = 0i64;
  v212 = 0;
  v213 = 0i64;
  v214 = 0;
  v215 = 0i64;
  if ( v210 > 0 )
  {
    v216 = v273.m_transformTrackFromBone.m_data;
    do
    {
      if ( (int)v213 >= 9 * (int)v208 )
      {
        v217 = v273.m_floatTrackFromSlot.m_data[v215 - 9 * v208] == -1;
      }
      else
      {
        v207 = (unsigned int)v213 / 9;
        v217 = v216[v207] == -1;
      }
      if ( !v217 )
      {
        ++*(&v255.m_size + (int)v260[v215]);
        ++v212;
      }
      v213 = (unsigned int)(v213 + 1);
      ++v215;
    }
    while ( (int)v213 < v210 );
    v214 = v256;
    v209 = v255.m_capacityAndFlags;
    v211 = v255.m_size;
    m_skel = v273.m_skel;
  }
  v218 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *, __int64, __int64, __int64))v273.m_anim->vfptr[3].__first_virtual_table_function__)(
           v273.m_anim,
           v207,
           v213,
           v215);
  v219 = ((__int64 (__fastcall *)(hkaPredictiveCompressedAnimation *))retaddr->vfptr[3].__first_virtual_table_function__)(retaddr);
  hkErrStream::hkErrStream(&v276, &buf, 512);
  v220 = hkOstream::operator<<(&v276, "Compression: ");
  v221 = hkOstream::operator<<(v220, v218);
  v222 = hkOstream::operator<<(v221, " -> ");
  v223 = hkOstream::operator<<(v222, v219);
  v224 = hkOstream::operator<<(v223, " (");
  v225 = hkOstream::operator<<(v224, (float)v218 / (float)v219);
  hkOstream::operator<<(v225, ":1)");
  hkError::messageReport(
    -1,
    (const char *)&buf,
    "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
    690);
  hkOstream::~hkOstream(&v276);
  hkErrStream::hkErrStream(&v276, &buf, 512);
  v226 = m_skel->m_bones.m_size;
  v227 = m_skel->m_floatSlots.m_size;
  v228 = v226 + v227 + 8 * v226;
  v229 = hkOstream::operator<<(&v276, v226);
  v230 = hkOstream::operator<<(v229, " bones, ");
  v231 = hkOstream::operator<<(v230, v227);
  v232 = hkOstream::operator<<(v231, " floats, ");
  v233 = hkOstream::operator<<(v232, v212);
  v234 = hkOstream::operator<<(v233, "/");
  v235 = hkOstream::operator<<(v234, v228);
  hkOstream::operator<<(v235, " animated channels");
  hkError::messageReport(
    -1,
    (const char *)&buf,
    "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
    692);
  hkOstream::~hkOstream(&v276);
  hkErrStream::hkErrStream(&v276, &buf, 512);
  v236 = v273.m_anim;
  v237 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *))v273.m_anim->vfptr[4].__vecDelDtor)(v273.m_anim);
  v238 = hkOstream::operator<<(&v276, v237);
  hkOstream::operator<<(v238, " frames");
  hkError::messageReport(
    -1,
    (const char *)&buf,
    "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
    693);
  hkOstream::~hkOstream(&v276);
  hkErrStream::hkErrStream(&v276, &buf, 512);
  v239 = hkOstream::operator<<(&v276, v211);
  v240 = hkOstream::operator<<(v239, " static, ");
  v241 = hkOstream::operator<<(v240, v209);
  v242 = hkOstream::operator<<(v241, " reference, ");
  v243 = hkOstream::operator<<(v242, v214);
  v244 = hkOstream::operator<<(v243, " ranged, ");
  v245 = hkOstream::operator<<(v244, SHIDWORD(v256));
  hkOstream::operator<<(v245, " fixed channels");
  hkError::messageReport(
    -1,
    (const char *)&buf,
    "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
    694);
  hkOstream::~hkOstream(&v276);
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
  v246 = retaddr->m_compressedData.m_size;
  v247 = &retaddr->m_compressedData;
  if ( v246 < (retaddr->m_compressedData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, v247, 1, 0i64, v246);
  retaddr->m_numFrames = (int)v236->vfptr[4].__vecDelDtor(v236, (unsigned int)v247);
  retaddr->m_numFloatSlots = m_skel->m_floatSlots.m_size;
  retaddr->m_numBones = m_skel->m_bones.m_size;
  m_duration = v236->m_duration;
  retaddr->m_skeleton = m_skel;
  retaddr->m_duration = m_duration;
  retaddr->m_numberOfTransformTracks = v236->m_numberOfTransformTracks;
  retaddr->m_numberOfFloatTracks = v236->m_numberOfFloatTracks;
  hkaPredictiveCompressedAnimation::computeMaxCompressedBytesPerFrame(retaddr);
  v257.m_size = 0;
  if ( v257.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v257.m_data,
      2 * (v257.m_capacityAndFlags & 0x3FFFFFFF));
  v257.m_data = 0i64;
  v257.m_capacityAndFlags = 0x80000000;
  arr.m_size = 0;
  if ( arr.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      arr.m_data,
      2 * (arr.m_capacityAndFlags & 0x3FFFFFFF));
  arr.m_data = 0i64;
  arr.m_capacityAndFlags = 0x80000000;
  LODWORD(v255.m_data) = 0;
  if ( SHIDWORD(v255.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v255.m_data,
      4 * HIDWORD(v255.m_data));
  v255.m_data = (float *)0x8000000000000000i64;
  v254.m_size = 0;
  if ( v254.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v254.m_data,
      4 * v254.m_capacityAndFlags);
  v254.m_data = 0i64;
  v254.m_capacityAndFlags = 0x80000000;
  v253.m_size = 0;
  if ( v253.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v253.m_data,
      4 * v253.m_capacityAndFlags);
  v253.m_data = 0i64;
  v253.m_capacityAndFlags = 0x80000000;
  v265.m_size = 0;
  if ( v265.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v265.m_data,
      2 * (v265.m_capacityAndFlags & 0x3FFFFFFF));
  v265.m_data = 0i64;
  v265.m_capacityAndFlags = 0x80000000;
  v270.m_size = 0;
  if ( v270.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v270.m_data,
      2 * (v270.m_capacityAndFlags & 0x3FFFFFFF));
  v270.m_data = 0i64;
  v270.m_capacityAndFlags = 0x80000000;
  v269.m_size = 0;
  if ( v269.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v269.m_data,
      2 * (v269.m_capacityAndFlags & 0x3FFFFFFF));
  v269.m_data = 0i64;
  v269.m_capacityAndFlags = 0x80000000;
  v267.m_size = 0;
  if ( v267.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v267.m_data,
      2 * (v267.m_capacityAndFlags & 0x3FFFFFFF));
  v267.m_data = 0i64;
  v267.m_capacityAndFlags = 0x80000000;
  v266.m_size = 0;
  if ( v266.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v266.m_data,
      2 * (v266.m_capacityAndFlags & 0x3FFFFFFF));
  v266.m_data = 0i64;
  v266.m_capacityAndFlags = 0x80000000;
  v249.m_size = 0;
  if ( v249.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v249.m_data,
      2 * (v249.m_capacityAndFlags & 0x3FFFFFFF));
  v249.m_data = 0i64;
  v249.m_capacityAndFlags = 0x80000000;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      2 * (array.m_capacityAndFlags & 0x3FFFFFFF));
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  if ( v278 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v260, 4 * v278);
  if ( v277 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v268, 48 * (v277 & 0x3FFFFFFF));
  hkaPredictiveCompressedAnimationUtil::Remapper::~Remapper(&v273);
}   2 * (v269.m_capacityAndFlags & 0x3FFFFFFF));
  v269.m_data = 0i64;
  v269.m_capacityAndFlags = 0x80000000;
  v267.m_size = 0;
  if ( v267.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v267.m_data,
      2 * (v267.m_capacityAndFlags & 0x3FFFFFFF));
  v267.m_data = 0i64;
  v267.m_capacityAndFlags = 0x80000000;
  v266.m_size = 0;
  if ( v266.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v266.m_data,
      2 * (v266.m_capacityAndFlags & 0x3FFFFFFF));
  v266.m_data = 0i64;
  v266.m_capacityAndFlags = 0x80000000;
  v249.m_size = 0;
  if ( v249.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v249.m_data,
      2 * (v249.m_capacityAndFlags & 0x3FFFFFFF));
  v249.m_data = 0i64;
  v249.m_capacityAndFlags = 0x80000000;
  array.m_size = 0;
  if ( 

// File Line: 713
// RVA: 0xB38880
void __fastcall hkaPredictiveCompressedAnimation::computeMaxCompressedBytesPerFrame(
        hkaPredictiveCompressedAnimation *this)
{
  int v1; // r11d
  __int64 v3; // rdx
  int v4; // eax
  unsigned __int16 *m_data; // rsi
  int v6; // ebx
  __int64 v7; // r9
  unsigned __int16 *v8; // rcx
  int v9; // r8d

  v1 = 0;
  this->m_maxCompressedBytesPerFrame = 0;
  v3 = 0i64;
  v4 = (this->m_intArrayOffsets[1] - this->m_intArrayOffsets[0]) / 2;
  if ( v4 > 0 )
  {
    m_data = this->m_intData.m_data;
    v6 = 0;
    v7 = 1i64;
    do
    {
      v8 = &m_data[this->m_intArrayOffsets[0]];
      v9 = v8[2 * v3] | (v8[v7] << 16);
      if ( v9 - v1 > v6 )
      {
        v6 = (v8[2 * v3] | (v8[v7] << 16)) - v1;
        this->m_maxCompressedBytesPerFrame = v9 - v1;
      }
      ++v3;
      v7 += 2i64;
      v1 = v9;
    }
    while ( v3 < v4 );
  }
}

// File Line: 736
// RVA: 0xB38910
void __fastcall hkaPredictiveCompressedAnimation::addArray(
        hkaPredictiveCompressedAnimation *this,
        hkArrayBase<unsigned short> *arr,
        int idx)
{
  int m_size; // eax
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_intData; // rcx

  m_size = this->m_intData.m_size;
  p_m_intData = &this->m_intData;
  *((_DWORD *)&p_m_intData[1].m_data + idx) = m_size;
  hkArrayBase<unsigned short>::_append(p_m_intData, &hkContainerHeapAllocator::s_alloc, arr->m_data, arr->m_size);
}

// File Line: 744
// RVA: 0xB38940
void __fastcall hkaPredictiveCompressedAnimation::addArray(
        hkaPredictiveCompressedAnimation *this,
        hkArrayBase<float> *arr,
        int idx)
{
  int m_size; // eax
  hkArray<float,hkContainerHeapAllocator> *p_m_floatData; // rcx

  m_size = this->m_floatData.m_size;
  p_m_floatData = &this->m_floatData;
  *((_DWORD *)&p_m_floatData[1].m_data + idx) = m_size;
  hkArrayBase<float>::_append(p_m_floatData, &hkContainerHeapAllocator::s_alloc, arr->m_data, arr->m_size);
}

