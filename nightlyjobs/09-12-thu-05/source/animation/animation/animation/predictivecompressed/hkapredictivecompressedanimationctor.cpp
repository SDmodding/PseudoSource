// File Line: 58
// RVA: 0xB389A0
void __fastcall hkaPredictiveCompressedAnimationUtil::Remapper::Remapper(hkaPredictiveCompressedAnimationUtil::Remapper *this, hkaSkeleton *s, hkaAnimationBinding *b, hkaPredictiveCompressedAnimation::CompressionParams *params)
{
  hkaInterleavedUncompressedAnimation *v4; // rax
  hkaPredictiveCompressedAnimationUtil::Remapper *v5; // rbx
  __int64 v6; // rcx
  int v7; // ebp
  unsigned int v8; // esi
  hkaSkeleton *v9; // r14
  __int64 v10; // r15
  int *v11; // rdi
  unsigned int v12; // eax
  __int64 v13; // rcx
  __int64 v14; // rax
  __int64 v15; // r14
  int *v16; // rdi
  __int64 v17; // rcx
  hkaAnimationBinding *v18; // rax
  int v19; // esi
  int v20; // er14
  __int64 v21; // r15
  signed __int64 v22; // rdi
  signed int v23; // edx
  signed __int64 v24; // rcx
  int v25; // edi
  __int64 v26; // r8
  __int64 v27; // rdi
  hkStringPtr v28; // [rsp+20h] [rbp-28h]
  __int16 v29; // [rsp+28h] [rbp-20h]
  __int16 v30; // [rsp+2Ah] [rbp-1Eh]
  int v31; // [rsp+50h] [rbp+8h]

  this->m_skel = s;
  this->m_binding = b;
  v4 = (hkaInterleavedUncompressedAnimation *)b->m_animation.m_pntr;
  v5 = this;
  this->m_params = params;
  this->m_anim = v4;
  v6 = s->m_bones.m_size;
  v7 = 0;
  v8 = 2147483648;
  v9 = s;
  v5->m_transformTrackFromBone.m_data = 0i64;
  v5->m_transformTrackFromBone.m_size = 0;
  v5->m_transformTrackFromBone.m_capacityAndFlags = 2147483648;
  v10 = v6;
  if ( (_DWORD)v6 )
  {
    v31 = 4 * v6;
    v11 = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                   &v31);
    LODWORD(v6) = v31 / 4;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = 2147483648;
  v5->m_transformTrackFromBone.m_data = v11;
  if ( (_DWORD)v6 )
    v12 = v6;
  v5->m_transformTrackFromBone.m_size = v10;
  v13 = v10;
  v5->m_transformTrackFromBone.m_capacityAndFlags = v12;
  if ( (signed int)v10 > 0 )
  {
    while ( v13 )
    {
      *v11 = -1;
      ++v11;
      --v13;
    }
  }
  v14 = v9->m_floatSlots.m_size;
  v5->m_floatTrackFromSlot.m_data = 0i64;
  v5->m_floatTrackFromSlot.m_size = 0;
  v5->m_floatTrackFromSlot.m_capacityAndFlags = 2147483648;
  v15 = v14;
  if ( (_DWORD)v14 )
  {
    v31 = 4 * v14;
    v16 = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                   &v31);
    LODWORD(v14) = v31 / 4;
  }
  else
  {
    v16 = 0i64;
  }
  v5->m_floatTrackFromSlot.m_data = v16;
  v5->m_floatTrackFromSlot.m_size = v15;
  if ( (_DWORD)v14 )
    v8 = v14;
  v17 = v15;
  v5->m_floatTrackFromSlot.m_capacityAndFlags = v8;
  if ( (signed int)v15 > 0 )
  {
    while ( v17 )
    {
      *v16 = -1;
      ++v16;
      --v17;
    }
  }
  v18 = v5->m_binding;
  if ( v18->m_partitionIndices.m_size <= 0 )
  {
    v25 = 0;
    if ( v18->m_transformTrackToBoneIndices.m_size > 0 )
    {
      v26 = 0i64;
      do
      {
        ++v26;
        v5->m_transformTrackFromBone.m_data[v5->m_binding->m_transformTrackToBoneIndices.m_data[v26 - 1]] = v25++;
      }
      while ( v25 < v5->m_binding->m_transformTrackToBoneIndices.m_size );
    }
  }
  else
  {
    v19 = 0;
    v20 = 0;
    v21 = 0i64;
    do
    {
      v22 = (signed __int64)&v5->m_skel->m_partitions.m_data[v5->m_binding->m_partitionIndices.m_data[v21]];
      hkStringPtr::hkStringPtr(&v28, (hkStringPtr *)v22);
      v29 = *(_WORD *)(v22 + 8);
      v23 = v29;
      v30 = *(_WORD *)(v22 + 10);
      if ( v29 <= (signed __int16)(v30 + v29 - 1) )
      {
        v24 = v29;
        do
        {
          ++v23;
          ++v24;
          v5->m_transformTrackFromBone.m_data[v24 - 1] = v19++;
        }
        while ( v23 <= (signed __int16)(v29 + v30 - 1) );
      }
      hkStringPtr::~hkStringPtr(&v28);
      ++v20;
      ++v21;
    }
    while ( v20 < v5->m_binding->m_partitionIndices.m_size );
  }
  if ( v5->m_binding->m_floatTrackToFloatSlotIndices.m_size > 0 )
  {
    v27 = 0i64;
    do
    {
      ++v27;
      v5->m_floatTrackFromSlot.m_data[v5->m_binding->m_floatTrackToFloatSlotIndices.m_data[v27 - 1]] = v7++;
    }
    while ( v7 < v5->m_binding->m_floatTrackToFloatSlotIndices.m_size );
  }
}

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
  int v9[3]; // [rsp+0h] [rbp-24h]
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
                         (__m128i)_mm_cmpltps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255), (__m128)0i64),
                         0x1Fu),
                       0x1Fu),
             v3.m_vec.m_quad);
      v5 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v3.m_vec.m_quad, 1u), 1u);
      v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
      v7 = (__m128i)_mm_add_ps(_mm_shuffle_ps(v6, v6, 177), v6);
      v8 = _mm_cmpeqps((__m128)v7, (__m128)0i64);
      v10 = _mm_mul_ps(
              v4,
              _mm_or_ps(
                _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v7, 0x1Fu), 0x1Fu), (__m128)_xmm), v8),
                _mm_andnot_ps(v8, _mm_div_ps(query.m_quad, (__m128)v7))));
      result = *(float *)&v9[channel];
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
float __fastcall hkaPredictiveCompressedAnimationUtil::Remapper::getDynamicTolerance(hkaPredictiveCompressedAnimationUtil::Remapper *this, int channel)
{
  hkaPredictiveCompressedAnimationUtil::Remapper *v2; // r8
  __int64 v3; // rcx
  int v4; // er9
  __int64 v5; // rdx
  hkaPredictiveCompressedAnimation::CompressionParams *v6; // r9
  unsigned int v7; // edx
  float result; // xmm0_4
  bool v9; // sf
  unsigned __int8 v10; // of
  hkaPredictiveCompressedAnimation::CompressionParams *v11; // r9
  unsigned int v12; // edx
  unsigned int v13; // edx
  hkaPredictiveCompressedAnimation::CompressionParams *v14; // r9
  __int64 v15; // rcx

  v2 = this;
  v3 = this->m_skel->m_bones.m_size;
  if ( channel >= 9 * (signed int)v3 )
  {
    v14 = v2->m_params;
    v15 = v2->m_floatTrackFromSlot.m_data[channel - 9 * v3];
    if ( v14->m_floatTrackIndexToPaletteIndex.m_size <= (signed int)v15 )
      result = v14->m_parameterPalette.m_data->m_dynamicFloatTolerance;
    else
      result = v14->m_parameterPalette.m_data[v14->m_floatTrackIndexToPaletteIndex.m_data[v15]].m_dynamicFloatTolerance;
  }
  else
  {
    v4 = channel % 9;
    v5 = v2->m_transformTrackFromBone.m_data[channel / 9];
    if ( v4 >= 3 )
    {
      v10 = __OFSUB__(v4, 6);
      v9 = v4 - 6 < 0;
      v11 = v2->m_params;
      if ( v9 ^ v10 )
      {
        if ( v11->m_trackIndexToPaletteIndex.m_size <= (signed int)v5 )
          v12 = 0;
        else
          v12 = v11->m_trackIndexToPaletteIndex.m_data[v5];
        result = v11->m_parameterPalette.m_data[v12].m_dynamicRotationTolerance;
      }
      else
      {
        if ( v11->m_trackIndexToPaletteIndex.m_size <= (signed int)v5 )
          v13 = 0;
        else
          v13 = v11->m_trackIndexToPaletteIndex.m_data[v5];
        result = v11->m_parameterPalette.m_data[v13].m_dynamicScaleTolerance;
      }
    }
    else
    {
      v6 = v2->m_params;
      if ( v6->m_trackIndexToPaletteIndex.m_size <= (signed int)v5 )
        v7 = 0;
      else
        v7 = v6->m_trackIndexToPaletteIndex.m_data[v5];
      result = v6->m_parameterPalette.m_data[v7].m_dynamicTranslationTolerance;
    }
  }
  return result;
}

// File Line: 257
// RVA: 0xB38FF0
void __fastcall hkaPredictiveCompressedAnimationUtil::Remapper::frameValue(hkaPredictiveCompressedAnimationUtil::Remapper *this, int frame, int channel)
{
  hkaPredictiveCompressedAnimationUtil::Remapper *v3; // r10
  __int64 v4; // rcx
  __int128 v5; // xmm0

  v3 = this;
  v4 = this->m_skel->m_bones.m_size;
  if ( channel >= 9 * (signed int)v4 )
    v5 = LODWORD(v3->m_anim->m_floats.m_data[frame * (signed __int64)v3->m_anim->m_numberOfFloatTracks
                                           + v3->m_floatTrackFromSlot.m_data[channel - 9 * v4]]);
  else
    hkaPredictiveCompressedAnimationUtil::Remapper::getTransformChannel(
      &v3->m_anim->m_transforms.m_data[frame * v3->m_anim->m_numberOfTransformTracks
                                     + v3->m_transformTrackFromBone.m_data[channel / 9]],
      channel % 9);
}

// File Line: 309
// RVA: 0xB36530
void __fastcall hkaPredictiveCompressedAnimation::hkaPredictiveCompressedAnimation(hkaPredictiveCompressedAnimation *this, hkaAnimationBinding *binding, hkaSkeleton *skeleton)
{
  hkaAnimationBinding *v3; // rdi
  hkaSkeleton *v4; // rbx
  hkaPredictiveCompressedAnimation *v5; // rsi
  hkaPredictiveCompressedAnimation::CompressionParams params; // [rsp+20h] [rbp-38h]

  v3 = binding;
  v4 = skeleton;
  v5 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, binding->m_animation.m_pntr);
  v5->vfptr = (hkBaseObjectVtbl *)&hkaPredictiveCompressedAnimation::`vftable;
  v5->m_compressedData.m_capacityAndFlags = 2147483648;
  v5->m_compressedData.m_data = 0i64;
  v5->m_compressedData.m_size = 0;
  v5->m_intData.m_data = 0i64;
  v5->m_intData.m_size = 0;
  v5->m_intData.m_capacityAndFlags = 2147483648;
  v5->m_floatData.m_data = 0i64;
  v5->m_floatData.m_size = 0;
  v5->m_floatData.m_capacityAndFlags = 2147483648;
  hkaPredictiveCompressedAnimation::CompressionParams::CompressionParams(&params);
  hkaPredictiveCompressedAnimation::build(v5, v3, v4, &params);
  hkaPredictiveCompressedAnimation::CompressionParams::~CompressionParams(&params);
}

// File Line: 316
// RVA: 0xB365D0
void __fastcall hkaPredictiveCompressedAnimation::hkaPredictiveCompressedAnimation(hkaPredictiveCompressedAnimation *this, hkaAnimationBinding *binding, hkaSkeleton *skeleton, hkaPredictiveCompressedAnimation::CompressionParams *params)
{
  hkaAnimationBinding *v4; // rsi
  hkaPredictiveCompressedAnimation::CompressionParams *v5; // rbx
  hkaSkeleton *v6; // rdi
  hkaPredictiveCompressedAnimation *v7; // r14

  v4 = binding;
  v5 = params;
  v6 = skeleton;
  v7 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, binding->m_animation.m_pntr);
  v7->vfptr = (hkBaseObjectVtbl *)&hkaPredictiveCompressedAnimation::`vftable;
  v7->m_compressedData.m_capacityAndFlags = 2147483648;
  v7->m_compressedData.m_data = 0i64;
  v7->m_compressedData.m_size = 0;
  v7->m_intData.m_data = 0i64;
  v7->m_intData.m_size = 0;
  v7->m_intData.m_capacityAndFlags = 2147483648;
  v7->m_floatData.m_data = 0i64;
  v7->m_floatData.m_size = 0;
  v7->m_floatData.m_capacityAndFlags = 2147483648;
  hkaPredictiveCompressedAnimation::build(v7, v4, v6, v5);
}

// File Line: 325
// RVA: 0xB36670
void __fastcall hkaPredictiveCompressedAnimation::hkaPredictiveCompressedAnimation(hkaPredictiveCompressedAnimation *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaPredictiveCompressedAnimation::`vftable;
  if ( flag.m_finishing )
    hkaPredictiveCompressedAnimation::computeMaxCompressedBytesPerFrame(this);
}

// File Line: 337
// RVA: 0xB366A0
void __usercall hkaPredictiveCompressedAnimation::build(hkaPredictiveCompressedAnimation *this@<rcx>, hkaAnimationBinding *binding@<rdx>, hkaSkeleton *skeleton@<r8>, hkaPredictiveCompressedAnimation::CompressionParams *params@<r9>, __int64 a5@<rbx>)
{
  hkaSkeleton *v5; // rbx
  __int64 v6; // r8
  hkaSkeleton *v7; // r13
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
  signed __int64 v19; // rdx
  __int64 v20; // rcx
  _DWORD *v21; // rax
  hkaInterleavedUncompressedAnimation *v22; // r12
  signed int v23; // er14
  __int64 v24; // r15
  unsigned __int64 v25; // rdx
  int v26; // er8
  int v27; // ebx
  int v28; // er9
  __int64 v29; // rsi
  __m128 *v30; // rdi
  int *v31; // rdx
  bool v32; // zf
  float v33; // xmm0_4
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  int v36; // er8
  hkaPredictiveCompressedAnimation::CompressionParams *v37; // rsi
  int v38; // er9
  int v39; // ebx
  __int64 v40; // r14
  _DWORD *v41; // r15
  __int64 v42; // rdi
  int *v43; // rcx
  bool v44; // zf
  __int64 v45; // rcx
  float v46; // xmm0_4
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
  signed int v58; // eax
  float v59; // xmm0_4
  __m128 v60; // xmm1
  int v61; // ecx
  int *v62; // r12
  int v63; // er11
  int *v64; // rbx
  __int64 v65; // r9
  int v66; // er10
  _DWORD *v67; // r8
  bool v68; // zf
  signed int v69; // eax
  _DWORD *v70; // rax
  signed __int64 v71; // rcx
  unsigned int v72; // er10
  int v73; // ecx
  int v74; // er8
  __int16 v75; // bx
  int v76; // er9
  int v77; // er14
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
  int v93; // er15
  int *v94; // r10
  int v95; // ebx
  bool v96; // zf
  __int64 v97; // rcx
  int *v98; // r9
  float *v99; // r14
  int v100; // eax
  int v101; // er8
  __int64 v102; // rcx
  unsigned int v103; // edx
  float v104; // xmm0_4
  unsigned int v105; // edx
  unsigned int v106; // edx
  char v107; // cl
  int v108; // ecx
  float v109; // xmm7_4
  float v110; // xmm6_4
  int v111; // ecx
  int v112; // ecx
  int v113; // ecx
  bool v114; // sf
  int v115; // ebx
  float *v116; // rsi
  __int64 v117; // rcx
  int *v118; // rcx
  signed __int64 v119; // rax
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
  hkBaseObjectVtbl *v132; // rax
  signed int v133; // er15
  int v134; // eax
  int v135; // er14
  int v136; // eax
  int v137; // edx
  __int64 v138; // rdi
  int v139; // er9
  __int64 v140; // r12
  __int64 v141; // rsi
  int *v142; // rbx
  int v143; // er8
  int v144; // eax
  signed __int64 v145; // rcx
  __int64 v146; // rdx
  __int64 v147; // rax
  __int64 v148; // r9
  int v149; // er12
  _DWORD *v150; // rbx
  int v151; // er8
  int v152; // esi
  __int64 v153; // r14
  __m128 *v154; // r15
  int *v155; // rcx
  signed __int64 v156; // rax
  unsigned int v157; // xmm0_4
  __m128 v158; // xmm1
  __m128i v159; // xmm1
  __m128 v160; // xmm2
  __m128 v161; // xmm4
  int v162; // edi
  int v163; // eax
  int v164; // ecx
  signed __int64 v165; // r15
  hkaPredictiveCompressedAnimation *v166; // r8
  int v167; // er13
  hkArray<unsigned char,hkContainerHeapAllocator> *v168; // rsi
  int v169; // er14
  int v170; // ecx
  unsigned int v171; // ebx
  int v172; // ecx
  unsigned int v173; // ebx
  char *v174; // rcx
  signed int v175; // edx
  char *v176; // rax
  __int64 v177; // rbx
  char *v178; // r11
  signed __int64 v179; // r10
  __int64 *v180; // rdx
  char *v181; // r8
  __int64 v182; // r9
  __int64 v183; // rax
  __int64 v184; // rbx
  int v185; // er9
  int v186; // eax
  int v187; // eax
  int v188; // eax
  int v189; // ecx
  int v190; // ebx
  int v191; // ecx
  int v192; // er9
  int v193; // ecx
  int v194; // esi
  int v195; // ecx
  __int64 v196; // rdi
  int *v197; // rbx
  int v198; // er8
  hkBaseObjectVtbl *v199; // rax
  int v200; // er9
  int v201; // eax
  int v202; // eax
  int v203; // er9
  int v204; // eax
  int v205; // eax
  int v206; // ecx
  int v207; // ecx
  __int64 v208; // rdx
  __int64 v209; // r10
  int v210; // er14
  signed int v211; // ebx
  int v212; // er15
  int v213; // esi
  __int64 v214; // r8
  int v215; // er12
  __int64 v216; // r9
  int *v217; // r13
  bool v218; // zf
  int v219; // ebx
  int v220; // edi
  hkOstream *v221; // rax
  hkOstream *v222; // rax
  hkOstream *v223; // rax
  hkOstream *v224; // rax
  hkOstream *v225; // rax
  hkOstream *v226; // rax
  int v227; // edx
  int v228; // ebx
  int v229; // edi
  hkOstream *v230; // rax
  hkOstream *v231; // rax
  hkOstream *v232; // rax
  hkOstream *v233; // rax
  hkOstream *v234; // rax
  hkOstream *v235; // rax
  hkOstream *v236; // rax
  hkaInterleavedUncompressedAnimation *v237; // rbx
  int v238; // eax
  hkOstream *v239; // rax
  hkOstream *v240; // rax
  hkOstream *v241; // rax
  hkOstream *v242; // rax
  hkOstream *v243; // rax
  hkOstream *v244; // rax
  hkOstream *v245; // rax
  hkOstream *v246; // rax
  int v247; // ecx
  hkArray<unsigned char,hkContainerHeapAllocator> *v248; // rdx
  float v249; // eax
  hkArrayBase<unsigned short> v250; // [rsp+30h] [rbp-C8h]
  _WORD *array; // [rsp+40h] [rbp-B8h]
  int v252; // [rsp+48h] [rbp-B0h]
  int v253; // [rsp+4Ch] [rbp-ACh]
  unsigned int v254; // [rsp+50h] [rbp-A8h]
  int v255; // [rsp+54h] [rbp-A4h]
  hkArrayBase<float> v256; // [rsp+58h] [rbp-A0h]
  hkArrayBase<float> v257; // [rsp+68h] [rbp-90h]
  hkArrayBase<float> v258; // [rsp+78h] [rbp-80h]
  int v259; // [rsp+88h] [rbp-70h]
  int v260; // [rsp+8Ch] [rbp-6Ch]
  hkArrayBase<unsigned short> v261; // [rsp+98h] [rbp-60h]
  hkArrayBase<unsigned short> arr; // [rsp+A8h] [rbp-50h]
  __int64 v263; // [rsp+B8h] [rbp-40h]
  _DWORD *v264; // [rsp+C0h] [rbp-38h]
  int nframes[2]; // [rsp+C8h] [rbp-30h]
  hkResult v266[2]; // [rsp+D0h] [rbp-28h]
  hkResult v267[2]; // [rsp+D8h] [rbp-20h]
  int v268; // [rsp+E0h] [rbp-18h]
  hkArrayBase<unsigned short> v269; // [rsp+E8h] [rbp-10h]
  hkArrayBase<unsigned short> v270; // [rsp+F8h] [rbp+0h]
  hkArrayBase<unsigned short> v271; // [rsp+108h] [rbp+10h]
  __m128 *v272; // [rsp+118h] [rbp+20h]
  hkArrayBase<unsigned short> v273; // [rsp+120h] [rbp+28h]
  hkArrayBase<unsigned short> v274; // [rsp+130h] [rbp+38h]
  int v275; // [rsp+140h] [rbp+48h]
  int v276; // [rsp+144h] [rbp+4Ch]
  hkaPredictiveCompressedAnimationUtil::Remapper v277; // [rsp+148h] [rbp+50h]
  __int64 v278; // [rsp+188h] [rbp+90h]
  hkResult result; // [rsp+190h] [rbp+98h]
  hkErrStream v280; // [rsp+198h] [rbp+A0h]
  int v281; // [rsp+1B0h] [rbp+B8h]
  int v282; // [rsp+1B4h] [rbp+BCh]
  __int64 v283; // [rsp+1B8h] [rbp+C0h]
  hkaPredictiveBlockCompression::Block buf; // [rsp+1C8h] [rbp+D0h]
  hkaPredictiveCompressedAnimation *retaddr; // [rsp+468h] [rbp+370h]
  __int64 v286; // [rsp+478h] [rbp+380h]

  v286 = a5;
  v5 = skeleton;
  this->m_type.m_storage = 5;
  hkaPredictiveCompressedAnimationUtil::Remapper::Remapper(&v277, skeleton, binding, params);
  v7 = v277.m_skel;
  v8 = v277.m_skel->m_floatSlots.m_size + 9 * v277.m_skel->m_bones.m_size;
  v9 = v8;
  if ( v8 )
  {
    v275 = 48 * v8;
    v10 = (__m128 *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __int64, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                      &hkContainerHeapAllocator::s_alloc,
                      &v275,
                      v6,
                      0i64);
    v8 = v275 / 48;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 2147483648;
  v272 = v10;
  if ( v8 )
    v11 = v8;
  v12 = v9;
  v281 = v11;
  if ( (signed int)v9 > 0 )
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
  v14 = 9 * v7->m_bones.m_size;
  v32 = v7->m_floatSlots.m_size + v14 == 0;
  v15 = v7->m_floatSlots.m_size + v14;
  v16 = v15;
  if ( v32 )
  {
    v17 = 0i64;
  }
  else
  {
    v276 = 4 * v15;
    v17 = (_DWORD *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __m128 *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                      &hkContainerHeapAllocator::s_alloc,
                      &v276,
                      v10,
                      0i64);
    v15 = v276 / 4;
  }
  v18 = 2147483648;
  v264 = v17;
  if ( v15 )
    v18 = v15;
  v19 = 1i64;
  v282 = v18;
  v20 = v16;
  if ( (signed int)v16 > 0 )
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
  v22 = v277.m_anim;
  if ( !v5->m_referenceFloats.m_size && v277.m_anim->m_numberOfFloatTracks > 0 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&v258.m_size, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v258.m_size,
      "Your skeleton does not have reference floats but your animation does have float tracks.  Predictive compression re"
      "quires reference floats.  You must re-export your assets.  Compression will proceed assuming zero for all reference floats.");
    hkError::messageWarning(
      -1413818222,
      (const char *)&buf,
      "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
      347);
    hkOstream::~hkOstream((hkOstream *)&v258.m_size);
  }
  v23 = 0;
  v24 = 0i64;
  if ( (signed int)v22->vfptr[4].__vecDelDtor((hkBaseObject *)&v22->vfptr, v19) > 0 )
  {
    do
    {
      v26 = v7->m_bones.m_size;
      v27 = 0;
      v28 = 9 * v26;
      v29 = 0i64;
      if ( 9 * v26 + v7->m_floatSlots.m_size > 0 )
      {
        v30 = v272;
        do
        {
          if ( v27 >= v28 )
          {
            v31 = v277.m_floatTrackFromSlot.m_data;
            v32 = v277.m_floatTrackFromSlot.m_data[v29 - 9i64 * v26] == -1;
          }
          else
          {
            v31 = v277.m_floatTrackFromSlot.m_data;
            v32 = v277.m_transformTrackFromBone.m_data[v27 / 9] == -1;
          }
          if ( !v32 )
          {
            if ( v27 >= v28 )
              v33 = v22->m_floats.m_data[v24 * v22->m_numberOfFloatTracks + v31[v29 - 9i64 * v26]];
            else
              v33 = hkaPredictiveCompressedAnimationUtil::Remapper::getTransformChannel(
                      &v22->m_transforms.m_data[v23 * v22->m_numberOfTransformTracks
                                              + v277.m_transformTrackFromBone.m_data[v27 / 9]],
                      v27 % 9);
            *(float *)&v286 = v33;
            v34 = _mm_shuffle_ps((__m128)LODWORD(v33), (__m128)LODWORD(v33), 0);
            v35 = _mm_max_ps(v34, v30[1]);
            *v30 = _mm_min_ps(v34, *v30);
            v30[1] = v35;
          }
          v26 = v7->m_bones.m_size;
          ++v27;
          v28 = 9 * v26;
          ++v29;
          v30 += 3;
        }
        while ( v27 < 9 * v26 + v7->m_floatSlots.m_size );
      }
      ++v23;
      ++v24;
    }
    while ( v23 < ((signed int (__fastcall *)(hkaInterleavedUncompressedAnimation *))v22->vfptr[4].__vecDelDtor)(v22) );
  }
  v36 = v7->m_bones.m_size;
  v37 = v277.m_params;
  v38 = 9 * v36;
  v39 = 0;
  v40 = 0i64;
  if ( 9 * v36 + v7->m_floatSlots.m_size > 0 )
  {
    v41 = v264;
    v42 = (__int64)&v272[1];
    do
    {
      if ( v39 >= v38 )
      {
        v25 = (unsigned __int64)v277.m_floatTrackFromSlot.m_data;
        v43 = v277.m_transformTrackFromBone.m_data;
        v44 = v277.m_floatTrackFromSlot.m_data[v40 - 9i64 * v36] == -1;
      }
      else
      {
        v43 = v277.m_transformTrackFromBone.m_data;
        v25 = (unsigned __int64)v277.m_floatTrackFromSlot.m_data;
        v44 = v277.m_transformTrackFromBone.m_data[v39 / 9] == -1;
      }
      if ( !v44 )
      {
        if ( v39 >= v38 )
        {
          v49 = *(signed int *)(v25 + 4 * (v40 - 9i64 * v36));
          if ( v37->m_floatTrackIndexToPaletteIndex.m_size <= (signed int)v49 )
            v50 = 0;
          else
            v50 = v37->m_floatTrackIndexToPaletteIndex.m_data[v49];
          v46 = v37->m_parameterPalette.m_data[v50].m_staticFloatTolerance;
        }
        else
        {
          v45 = v43[v39 / 9];
          if ( v39 % 9 >= 3 )
          {
            if ( v39 % 9 >= 6 )
            {
              if ( v37->m_trackIndexToPaletteIndex.m_size <= (signed int)v45 )
                v48 = 0;
              else
                v48 = v37->m_trackIndexToPaletteIndex.m_data[v45];
              v46 = v37->m_parameterPalette.m_data[v48].m_staticScaleTolerance;
            }
            else
            {
              if ( v37->m_trackIndexToPaletteIndex.m_size <= (signed int)v45 )
                v47 = 0;
              else
                v47 = v37->m_trackIndexToPaletteIndex.m_data[v45];
              v46 = v37->m_parameterPalette.m_data[v47].m_staticRotationTolerance;
            }
          }
          else if ( v37->m_trackIndexToPaletteIndex.m_size <= (signed int)v45 )
          {
            v46 = v37->m_parameterPalette.m_data->m_staticTranslationTolerance;
          }
          else
          {
            v46 = v37->m_parameterPalette.m_data[v37->m_trackIndexToPaletteIndex.m_data[v45]].m_staticTranslationTolerance;
          }
        }
        v51 = *(__m128 *)v42;
        v52 = *(__m128 *)(v42 - 16);
        *(float *)&v286 = v46;
        v255 = 947913728;
        v53 = _mm_sub_ps(v51, v52);
        v54 = _mm_max_ps(
                _mm_shuffle_ps((__m128)LODWORD(v46), (__m128)LODWORD(v46), 0),
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)0x38800400u, (__m128)0x38800400u, 0),
                  _mm_mul_ps(v53, (__m128)xmmword_141A711B0)));
        *(__m128 *)(v42 + 16) = v54;
        v55 = 9 * v7->m_bones.m_size;
        if ( v39 >= v55 )
        {
          if ( v7->m_referenceFloats.m_size > v39 - v55 )
            v56 = v7->m_referenceFloats.m_data[v39 - v55];
          else
            v56 = 0.0;
        }
        else
        {
          v56 = hkaPredictiveCompressedAnimationUtil::Remapper::getTransformChannel(
                  &v7->m_referencePose.m_data[v39 / 9],
                  v39 % 9);
        }
        *(float *)&v286 = v56;
        LODWORD(v57) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(v56), (__m128)LODWORD(v56), 0);
        if ( v53.m128_f32[0] >= (float)(v54.m128_f32[0] + v54.m128_f32[0]) )
          v58 = 2;
        else
          v58 = fmax(
                  COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v51.m128_f32[0] - v57)) >> 1),
                  COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v52.m128_f32[0] - v57)) >> 1)) < v54.m128_f32[0];
        v41[v40] = v58;
        v59 = hkaPredictiveCompressedAnimationUtil::Remapper::getDynamicTolerance(&v277, v39);
        v268 = 947913728;
        v60 = _mm_sub_ps(*(__m128 *)v42, *(__m128 *)(v42 - 16));
        *(float *)&v286 = v59;
        *(__m128 *)(v42 + 16) = _mm_max_ps(
                                  _mm_shuffle_ps((__m128)(unsigned int)v286, (__m128)(unsigned int)v286, 0),
                                  _mm_mul_ps(
                                    _mm_mul_ps(v60, (__m128)xmmword_141A711B0),
                                    _mm_shuffle_ps((__m128)0x38800400u, (__m128)0x38800400u, 0)));
      }
      v36 = v7->m_bones.m_size;
      ++v39;
      v38 = 9 * v36;
      ++v40;
      v42 += 48i64;
    }
    while ( v39 < 9 * v36 + v7->m_floatSlots.m_size );
  }
  v61 = v7->m_bones.m_size;
  v62 = v277.m_transformTrackFromBone.m_data;
  v63 = 0;
  if ( v61 > 0 )
  {
    v25 = (unsigned __int64)v264;
    v64 = v277.m_floatTrackFromSlot.m_data;
    v65 = 0i64;
    v66 = 0;
    v67 = v264 + 3;
    do
    {
      if ( v66 >= 9 * v61 )
      {
        v68 = v64[v65 - 9i64 * v61] == -1;
      }
      else
      {
        v25 = (unsigned __int64)v264;
        v68 = v62[v66 / 9] == -1;
      }
      if ( !v68 )
      {
        v69 = 0;
        if ( *v67 == 1 )
          v69 = 1;
        if ( v67[1] == 1 )
          ++v69;
        if ( *(_DWORD *)(v25 + 4 * v65 + 20) == 1 )
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
      v61 = v7->m_bones.m_size;
      ++v63;
      v66 += 9;
      v65 += 9i64;
      v67 += 9;
    }
    while ( v63 < v61 );
  }
  v72 = 2147483648;
  array = 0i64;
  v252 = 0;
  v253 = 2147483648;
  v73 = v7->m_bones.m_size;
  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  v78 = 0i64;
  if ( v73 > 0 )
  {
    v79 = v277.m_floatTrackFromSlot.m_data;
    v80 = 0;
    do
    {
      if ( v80 >= 9 * v73 )
      {
        v81 = v79[9 * (v78 - v73)] == -1;
      }
      else
      {
        v25 = (unsigned int)((signed int)((unsigned __int64)(954437177i64 * v80) >> 32) >> 1);
        v81 = v62[v80 / 9] == -1;
      }
      v82 = v76++;
      v75 |= (!v81 != 0) << v82;
      if ( v76 == 16 )
      {
        if ( v74 == (v72 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
          v74 = v252;
        }
        v76 = 0;
        array[v74] = v75;
        v72 = v253;
        v74 = v252 + 1;
        v75 = 0;
        ++v252;
      }
      v73 = v7->m_bones.m_size;
      ++v77;
      v80 += 9;
      ++v78;
    }
    while ( v77 < v73 );
    v37 = v277.m_params;
    if ( v76 > 0 )
    {
      if ( v74 == (v72 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
        v74 = v252;
      }
      v76 = 0;
      array[v74] = v75;
      v72 = v253;
      v74 = v252 + 1;
      v75 = 0;
      ++v252;
    }
  }
  v83 = 0;
  if ( v7->m_floatSlots.m_size > 0 )
  {
    v84 = v277.m_floatTrackFromSlot.m_data;
    do
    {
      v85 = v7->m_bones.m_size;
      v25 = (unsigned int)(9 * v85 + v83);
      if ( (signed int)v25 >= 9 * (signed int)v85 )
      {
        v86 = v84[(signed int)v25 - 9 * v85] == -1;
      }
      else
      {
        v25 = (unsigned int)((signed int)((unsigned __int64)(954437177i64 * (signed int)v25) >> 32) >> 1);
        v86 = v62[(signed int)(v25 + ((unsigned int)v25 >> 31))] == -1;
      }
      v87 = v76++;
      v75 |= (!v86 != 0) << v87;
      if ( v76 == 16 )
      {
        if ( v74 == (v72 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
          v74 = v252;
        }
        v76 = 0;
        array[v74] = v75;
        v72 = v253;
        v74 = v252 + 1;
        v75 = 0;
        ++v252;
      }
      ++v83;
    }
    while ( v83 < v7->m_floatSlots.m_size );
    v37 = v277.m_params;
  }
  if ( v76 > 0 )
  {
    if ( v74 == (v72 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
      v74 = v252;
    }
    array[v74] = v75;
    ++v252;
  }
  v88 = retaddr;
  v250.m_data = 0i64;
  v250.m_size = 0;
  v250.m_capacityAndFlags = 2147483648;
  v270.m_data = 0i64;
  v270.m_size = 0;
  retaddr->m_firstFloatBlockScaleAndOffsetIndex = 0;
  v270.m_capacityAndFlags = 2147483648;
  v271.m_data = 0i64;
  v271.m_size = 0;
  v271.m_capacityAndFlags = 2147483648;
  v273.m_data = 0i64;
  v273.m_size = 0;
  v273.m_capacityAndFlags = 2147483648;
  v274.m_data = 0i64;
  v274.m_size = 0;
  v274.m_capacityAndFlags = 2147483648;
  v269.m_data = 0i64;
  v269.m_size = 0;
  v269.m_capacityAndFlags = 2147483648;
  v256.m_data = 0i64;
  v256.m_size = 0;
  v256.m_capacityAndFlags = 2147483648;
  v257.m_data = 0i64;
  v257.m_size = 0;
  v257.m_capacityAndFlags = 2147483648;
  v258.m_data = (float *)0x8000000000000000i64;
  v89 = v7->m_bones.m_size;
  v90 = 0;
  v91 = 0;
  v92 = 0i64;
  v93 = 0;
  LODWORD(v286) = 0;
  if ( v89 > 0 )
  {
    while ( 1 )
    {
      v94 = v277.m_transformTrackFromBone.m_data;
      v95 = 9 * v93;
      if ( 9 * v93 >= 9 * v89 )
      {
        v96 = v277.m_floatTrackFromSlot.m_data[v95 - 9i64 * v89] == -1;
      }
      else
      {
        v25 = (unsigned int)((signed int)((unsigned __int64)(954437177i64 * v95) >> 32) >> 1);
        v96 = v277.m_transformTrackFromBone.m_data[v95 / 9] == -1;
      }
      if ( !v96 )
        break;
LABEL_170:
      v89 = v7->m_bones.m_size;
      LODWORD(v286) = ++v93;
      if ( v93 >= v89 )
      {
        v88 = retaddr;
        goto LABEL_172;
      }
    }
    v97 = v95;
    v98 = &v264[v95];
    v25 = 9i64;
    *(_QWORD *)&v267[0].m_enum = v95;
    *(_QWORD *)&v266[0].m_enum = &v264[v95];
    *(_QWORD *)nframes = 9i64;
    v99 = v272[3 * v95 + 1].m128_f32;
    while ( 1 )
    {
      v100 = *v98;
      LODWORD(v263) = v100;
      if ( v100 == 2 )
        break;
      if ( !v100 )
      {
        v120 = (float)(*(v99 - 4) + *v99) * 0.5;
        if ( LODWORD(v258.m_data) == (HIDWORD(v258.m_data) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v258, 4);
        v258.m_data[SLODWORD(v258.m_data)] = v120;
        ++LODWORD(v258.m_data);
        v121 = v273.m_size;
        if ( v273.m_size == (v273.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v273, 2);
          v121 = v273.m_size;
        }
        v273.m_data[v121] = v95 % 9 + 12 * (v95 / 9) + v95 % 9 / 3;
        ++v273.m_size;
        v92 = (unsigned int)v269.m_size;
LABEL_161:
        v93 = v286;
        if ( v95 < 9 * v7->m_bones.m_size
          && (unsigned int)(v95 % 9 - 3) <= 2
          && (!(_DWORD)v92 || v269.m_data[(signed int)v92 - 1] != (_DWORD)v286) )
        {
          if ( (_DWORD)v92 == (v269.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v269, 2);
            LODWORD(v92) = v269.m_size;
          }
          v269.m_data[(signed int)v92] = v93;
          v92 = (unsigned int)(v269.m_size++ + 1);
        }
        v25 = *(_QWORD *)nframes;
        v97 = *(_QWORD *)&v267[0].m_enum;
        v98 = *(int **)&v266[0].m_enum;
        goto LABEL_169;
      }
LABEL_160:
      if ( v100 != 1 )
        goto LABEL_161;
LABEL_169:
      v94 = v277.m_transformTrackFromBone.m_data;
      ++v97;
      ++v98;
      ++v95;
      v99 += 12;
      --v25;
      *(_QWORD *)&v267[0].m_enum = v97;
      *(_QWORD *)&v266[0].m_enum = v98;
      *(_QWORD *)nframes = v25;
      if ( !v25 )
        goto LABEL_170;
    }
    if ( v95 >= 9 * v7->m_bones.m_size
      || (v101 = v95 % 9, (unsigned int)(v95 % 9 - 3) > 2)
      || ((v102 = v94[v95 / 9], v101 >= 3) ? (v101 >= 6 ? (v37->m_trackIndexToPaletteIndex.m_size <= (signed int)v102 ? (v106 = 0) : (v106 = v37->m_trackIndexToPaletteIndex.m_data[v102]),
                                                           v104 = v37->m_parameterPalette.m_data[v106].m_dynamicScaleTolerance) : (v37->m_trackIndexToPaletteIndex.m_size <= (signed int)v102 ? (v105 = 0) : (v105 = v37->m_trackIndexToPaletteIndex.m_data[v102]), v104 = v37->m_parameterPalette.m_data[v105].m_dynamicRotationTolerance)) : (v37->m_trackIndexToPaletteIndex.m_size <= (signed int)v102 ? (v103 = 0) : (v103 = v37->m_trackIndexToPaletteIndex.m_data[v102]), v104 = v37->m_parameterPalette.m_data[v103].m_dynamicTranslationTolerance),
          v104 != 0.0) )
    {
      v109 = v99[4] + v99[4];
      v110 = (float)(*(v99 - 4) + *v99) * 0.5;
      if ( v256.m_size == (v256.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v256, 4);
      v256.m_data[v256.m_size] = v109;
      v111 = v257.m_size;
      ++v256.m_size;
      if ( v257.m_size == (v257.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v257, 4);
        v111 = v257.m_size;
      }
      v257.m_data[v111] = v110;
      ++v257.m_size;
      if ( ++v91 != 16 )
        goto LABEL_155;
      v112 = v250.m_size;
      if ( v250.m_size == (v250.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v250, 2);
        v112 = v250.m_size;
      }
      v250.m_data[v112] = v90;
      v90 = 0;
    }
    else
    {
      *v98 = 3;
      v107 = v91;
      *((__m128 *)v99 - 1) = g_vectorfConstants[0];
      v255 = 947913728;
      ++v91;
      LODWORD(v263) = 3;
      *(hkVector4f *)v99 = (hkVector4f)query.m_quad;
      v90 |= 1 << v107;
      *((__m128 *)v99 + 1) = _mm_max_ps(
                               aabbOut.m_quad,
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps(query.m_quad, *(__m128 *)((char *)v99 - 16)),
                                   (__m128)xmmword_141A711B0),
                                 _mm_shuffle_ps((__m128)0x38800400u, (__m128)0x38800400u, 0)));
      if ( v91 != 16 )
      {
LABEL_155:
        v113 = v270.m_size;
        if ( v270.m_size == (v270.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v270, 2);
          v113 = v270.m_size;
        }
        v270.m_data[v113] = v95 % 9 + 12 * (v95 / 9) + v95 % 9 / 3;
        ++v270.m_size;
        v92 = (unsigned int)v269.m_size;
        v98 = *(int **)&v266[0].m_enum;
        v93 = v286;
        v25 = *(_QWORD *)nframes;
        if ( !(v270.m_size % 16) )
          retaddr->m_firstFloatBlockScaleAndOffsetIndex = v256.m_size;
        v100 = v263;
        v97 = *(_QWORD *)&v267[0].m_enum;
        goto LABEL_160;
      }
      v108 = v250.m_size;
      if ( v250.m_size == (v250.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v250, 2);
        v108 = v250.m_size;
      }
      v250.m_data[v108] = v90;
      v90 = 0;
    }
    ++v250.m_size;
    v91 = 0;
    goto LABEL_155;
  }
LABEL_172:
  v32 = v7->m_floatSlots.m_size == 0;
  v114 = v7->m_floatSlots.m_size < 0;
  LODWORD(v286) = v270.m_size;
  v115 = 0;
  if ( !v114 && !v32 )
  {
    v116 = (float *)v272;
    do
    {
      v117 = v7->m_bones.m_size;
      v92 = (unsigned int)(v115 + 9 * v117);
      if ( (signed int)v92 >= 9 * (signed int)v117 )
      {
        v119 = (signed int)v92 - 9 * v117;
        v118 = v277.m_floatTrackFromSlot.m_data;
      }
      else
      {
        v118 = v277.m_transformTrackFromBone.m_data;
        v25 = (unsigned int)((signed int)((unsigned __int64)(954437177i64 * (signed int)v92) >> 32) >> 1);
        v119 = (signed int)v92 / 9;
      }
      if ( v118[v119] != -1 )
      {
        v122 = v264[(signed int)v92];
        if ( v122 == 2 )
        {
          v123 = v116[12 * (signed int)v92 + 8] + v116[12 * (signed int)v92 + 8];
          v124 = (float)(v116[12 * (signed int)v92 + 4] + v116[12 * (signed int)v92]) * 0.5;
          if ( v256.m_size == (v256.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v256, 4);
          v256.m_data[v256.m_size] = v123;
          v125 = v257.m_size;
          ++v256.m_size;
          if ( v257.m_size == (v257.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v257, 4);
            v125 = v257.m_size;
          }
          v257.m_data[v125] = v124;
          ++v257.m_size;
          if ( ++v91 == 16 )
          {
            v126 = v250.m_size;
            if ( v250.m_size == (v250.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v250, 2);
              v126 = v250.m_size;
            }
            v91 = 0;
            v250.m_data[v126] = v90;
            ++v250.m_size;
            v90 = 0;
          }
          v127 = v271.m_size;
          if ( v271.m_size == (v271.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v271, 2);
            v127 = v271.m_size;
          }
          v271.m_data[v127] = v115;
          ++v271.m_size;
        }
        else if ( !v122 )
        {
          v128 = (float)(v116[12 * (signed int)v92 + 4] + v116[12 * (signed int)v92]) * 0.5;
          if ( LODWORD(v258.m_data) == (HIDWORD(v258.m_data) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v258, 4);
          v258.m_data[SLODWORD(v258.m_data)] = v128;
          v129 = v274.m_size;
          ++LODWORD(v258.m_data);
          if ( v274.m_size == (v274.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v274, 2);
            v129 = v274.m_size;
          }
          v274.m_data[v129] = v115;
          ++v274.m_size;
        }
      }
      ++v115;
    }
    while ( v115 < v7->m_floatSlots.m_size );
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
        goto LABEL_210;
    }
    if ( v250.m_size == (v250.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v250, 2);
    v250.m_data[v250.m_size] = v90;
    ++v250.m_size;
  }
LABEL_210:
  v131 = v277.m_anim;
  *(_QWORD *)v88->m_intArrayOffsets = -1i64;
  *(_QWORD *)&v88->m_intArrayOffsets[2] = -1i64;
  *(_QWORD *)&v88->m_intArrayOffsets[4] = -1i64;
  *(_QWORD *)&v88->m_intArrayOffsets[6] = -1i64;
  v88->m_intArrayOffsets[8] = -1;
  *(_QWORD *)v88->m_floatArrayOffsets = -1i64;
  arr.m_capacityAndFlags = 2147483648;
  v88->m_floatArrayOffsets[2] = -1;
  arr.m_data = 0i64;
  arr.m_size = 0;
  v261.m_data = 0i64;
  v261.m_size = 0;
  v261.m_capacityAndFlags = 2147483648;
  v132 = v131->vfptr;
  v268 = 0;
  v133 = 0;
  v255 = 0;
  if ( ((signed int (__fastcall *)(hkaInterleavedUncompressedAnimation *, unsigned __int64, __int64))v132[4].__vecDelDtor)(
         v131,
         v25,
         v92) > 0 )
  {
    do
    {
      v134 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *))v131->vfptr[4].__vecDelDtor)(v131);
      v135 = 16;
      v260 = 2147483648;
      v136 = v134 - v133;
      if ( v136 < 16 )
        v135 = v136;
      v137 = 0;
      nframes[0] = v135;
      v138 = 0i64;
      *(_QWORD *)&v258.m_size = 0i64;
      v259 = 0;
      if ( v135 <= 0 )
      {
        result.m_enum = 0;
      }
      else
      {
        v139 = v135;
        if ( v135 < 0 )
          v139 = 0;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          &v258.m_size,
          v139,
          16);
        v137 = v259;
        v138 = *(_QWORD *)&v258.m_size;
      }
      v140 = v135;
      v278 = v135;
      v141 = v137 - v135 - 1;
      if ( v137 - v135 - 1 >= 0 )
      {
        v142 = (int *)(16 * v141 + 16i64 * v135 + 12 + v138);
        do
        {
          v143 = *v142;
          *(v142 - 1) = 0;
          if ( v143 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              *(void **)(v142 - 3),
              2 * (v143 & 0x3FFFFFFF));
          *(_QWORD *)(v142 - 3) = 0i64;
          *v142 = 2147483648;
          v142 -= 4;
          --v141;
        }
        while ( v141 >= 0 );
        v137 = v259;
        v138 = *(_QWORD *)&v258.m_size;
      }
      v144 = v135 - v137;
      v145 = v138 + 16i64 * v137;
      v146 = v135 - v137;
      if ( v144 > 0 )
      {
        do
        {
          if ( v145 )
          {
            *(_QWORD *)v145 = 0i64;
            *(_DWORD *)(v145 + 8) = 0;
            *(_DWORD *)(v145 + 12) = 2147483648;
          }
          v145 += 16i64;
          --v146;
        }
        while ( v146 );
        v138 = *(_QWORD *)&v258.m_size;
      }
      v259 = v135;
      if ( v135 > 0 )
      {
        v147 = 0i64;
        v148 = v135;
        v283 = v135;
        v263 = 0i64;
        v149 = v133;
        do
        {
          v146 = (unsigned int)v7->m_bones.m_size;
          v150 = (_DWORD *)(v147 + v138);
          v151 = 9 * v146;
          v152 = 0;
          v153 = 0i64;
          if ( 9 * (signed int)v146 + v7->m_floatSlots.m_size > 0 )
          {
            v154 = v272 + 2;
            do
            {
              if ( v152 >= v151 )
              {
                v156 = v153 - 9i64 * (signed int)v146;
                v155 = v277.m_floatTrackFromSlot.m_data;
              }
              else
              {
                v155 = v277.m_transformTrackFromBone.m_data;
                v156 = v152 / 9;
              }
              if ( v155[v156] != -1 && (unsigned int)(v264[v153] - 2) <= 1 )
              {
                *(float *)&v157 = hkaPredictiveCompressedAnimationUtil::Remapper::frameValue(&v277, v149, v152);
                v158 = *v154;
                v254 = v157;
                v159 = (__m128i)_mm_add_ps(v158, v158);
                v160 = _mm_cmpeqps((__m128)0i64, (__m128)v159);
                v161 = _mm_mul_ps(
                         _mm_or_ps(
                           _mm_and_ps(
                             _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v159, 0x1Fu), 0x1Fu), (__m128)_xmm),
                             v160),
                           _mm_andnot_ps(v160, _mm_div_ps(query.m_quad, (__m128)v159))),
                         _mm_sub_ps(
                           _mm_shuffle_ps((__m128)v254, (__m128)v254, 0),
                           _mm_mul_ps(_mm_add_ps(v154[-2], v154[-1]), (__m128)xmmword_141A711B0)));
                v162 = _mm_cvtsi128_si32(
                         _mm_cvttps_epi32(
                           _mm_add_ps(
                             _mm_xor_ps(
                               (__m128)_mm_slli_epi32(
                                         _mm_srli_epi32((__m128i)_mm_cmpltps(v161, (__m128)0i64), 0x1Fu),
                                         0x1Fu),
                               (__m128)xmmword_141A711B0),
                             v161)));
                if ( v162 >= -8191 )
                {
                  if ( v162 > 0x1FFF )
                    LOWORD(v162) = 0x1FFF;
                }
                else
                {
                  LOWORD(v162) = -8191;
                }
                if ( v150[2] == (v150[3] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v150, 2);
                *(_WORD *)(*(_QWORD *)v150 + 2i64 * (signed int)v150[2]++) = v162;
              }
              v146 = (unsigned int)v7->m_bones.m_size;
              ++v152;
              v151 = 9 * v146;
              ++v153;
              v154 += 3;
            }
            while ( v152 < 9 * (signed int)v146 + v7->m_floatSlots.m_size );
            v138 = *(_QWORD *)&v258.m_size;
            v148 = v283;
          }
          ++v149;
          v147 = v263 + 16;
          v283 = --v148;
          v263 += 16i64;
        }
        while ( v148 );
        v140 = v278;
      }
      v164 = 0;
      v165 = 0i64;
      v254 = *(_DWORD *)(v138 + 8);
      v163 = v254;
      LODWORD(v263) = 0;
      v278 = (signed int)v254;
      if ( (signed int)v254 > 0 )
      {
        v166 = retaddr;
        v167 = nframes[0];
        v168 = &retaddr->m_compressedData;
        while ( 1 )
        {
          v169 = 16;
          if ( v163 < 16 )
            v169 = v163;
          if ( (signed int)v286 >= v165 && (signed int)v286 < v169 + v164 )
          {
            v170 = v261.m_size;
            v171 = v166->m_compressedData.m_size - v268;
            if ( v261.m_size == (v261.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v261, 2);
              v170 = v261.m_size;
            }
            v261.m_data[v170] = v171;
            v172 = v261.m_size + 1;
            v173 = v171 >> 16;
            v261.m_size = v172;
            if ( v172 == (v261.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v261, 2);
              v172 = v261.m_size;
            }
            v261.m_data[v172] = v173;
            ++v261.m_size;
            v138 = *(_QWORD *)&v258.m_size;
          }
          if ( v167 < 16 || v169 < 16 )
          {
            v174 = (char *)&buf;
            v175 = 31;
            do
            {
              v176 = v174;
              v174 += 16;
              --v175;
              *(_OWORD *)v176 = 0i64;
            }
            while ( v175 >= 0 );
          }
          v177 = v169;
          if ( v169 > 0 )
          {
            v178 = (char *)&buf;
            v179 = 2 * v165;
            do
            {
              if ( v140 > 0 )
              {
                v180 = (__int64 *)v138;
                v181 = v178;
                v182 = v140;
                do
                {
                  v183 = *v180;
                  v181 += 2;
                  v180 += 2;
                  *((_WORD *)v181 - 1) = *(_WORD *)(v179 + v183);
                  --v182;
                }
                while ( v182 );
              }
              v179 += 2i64;
              v178 += 32;
              --v177;
            }
            while ( v177 );
          }
          v184 = retaddr->m_compressedData.m_size;
          v185 = v184 + 528;
          v186 = retaddr->m_compressedData.m_capacityAndFlags & 0x3FFFFFFF;
          if ( v186 >= (signed int)v184 + 528 )
          {
            v266[0].m_enum = 0;
          }
          else
          {
            v187 = 2 * v186;
            if ( v185 < v187 )
              v185 = v187;
            hkArrayUtil::_reserve(v266, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v168, v185, 1);
          }
          retaddr->m_compressedData.m_size += 528;
          v188 = (unsigned __int64)hkaPredictiveBlockCompression::encodeBlock(&buf, v167, v169, &v168->m_data[v184]);
          v189 = retaddr->m_compressedData.m_capacityAndFlags & 0x3FFFFFFF;
          v190 = v188 - LODWORD(v168->m_data);
          if ( v189 >= v190 )
          {
            v267[0].m_enum = 0;
          }
          else
          {
            v191 = 2 * v189;
            v192 = v188 - LODWORD(v168->m_data);
            if ( v190 < v191 )
              v192 = v191;
            hkArrayUtil::_reserve(v267, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v168, v192, 1);
          }
          v165 += 16i64;
          v164 = v263 + 16;
          v163 = v254 - 16;
          retaddr->m_compressedData.m_size = v190;
          LODWORD(v263) = v164;
          v254 = v163;
          if ( v165 >= v278 )
            break;
          v138 = *(_QWORD *)&v258.m_size;
          v166 = retaddr;
        }
        v7 = v277.m_skel;
      }
      v88 = retaddr;
      v193 = arr.m_size;
      v194 = retaddr->m_compressedData.m_size;
      v268 = retaddr->m_compressedData.m_size;
      if ( arr.m_size == (arr.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &arr, 2);
        v193 = arr.m_size;
      }
      arr.m_data[v193] = v194;
      v195 = arr.m_size + 1;
      arr.m_size = v195;
      if ( v195 == (arr.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &arr, 2);
        v195 = arr.m_size;
      }
      arr.m_data[v195] = HIWORD(v194);
      ++arr.m_size;
      v196 = v259 - 1;
      if ( v259 - 1 >= 0 )
      {
        v197 = (int *)(16i64 * (v259 - 1) + *(_QWORD *)&v258.m_size + 12i64);
        do
        {
          v198 = *v197;
          *(v197 - 1) = 0;
          if ( v198 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              *(void **)(v197 - 3),
              2 * (v198 & 0x3FFFFFFF));
          *(_QWORD *)(v197 - 3) = 0i64;
          *v197 = 2147483648;
          v197 -= 4;
          --v196;
        }
        while ( v196 >= 0 );
      }
      v259 = 0;
      if ( v260 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          *(void **)&v258.m_size,
          16 * v260);
      v131 = v277.m_anim;
      *(_QWORD *)&v258.m_size = 0i64;
      v199 = v277.m_anim->vfptr;
      v260 = 2147483648;
      v255 += 15;
      v133 = v255;
    }
    while ( v133 < (signed int)v199[4].__vecDelDtor((hkBaseObject *)&v277.m_anim->vfptr, v146) );
  }
  hkaPredictiveCompressedAnimation::addArray(v88, &arr, 0);
  hkaPredictiveCompressedAnimation::addArray(v88, &v261, FIRST_FLOAT_BLOCK_OFFSETS);
  hkaPredictiveCompressedAnimation::addArray(v88, (hkArrayBase<unsigned short> *)&array, IS_ANIMATED_BITMAP);
  hkaPredictiveCompressedAnimation::addArray(v88, &v250, IS_FIXED_RANGE_BITMAP);
  hkaPredictiveCompressedAnimation::addArray(v88, &v270, DYNAMIC_BONE_TRACK_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v271, DYNAMIC_FLOAT_TRACK_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v273, STATIC_BONE_TRACK_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v274, STATIC_FLOAT_TRACK_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v269, RENORM_QUATERNION_INDEX);
  hkaPredictiveCompressedAnimation::addArray(v88, &v258, 0);
  hkaPredictiveCompressedAnimation::addArray(v88, &v256, DYNAMIC_SCALES);
  hkaPredictiveCompressedAnimation::addArray(v88, &v257, DYNAMIC_OFFSETS);
  v200 = v88->m_intData.m_size + 8;
  v201 = v88->m_intData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v201 < v200 )
  {
    v202 = 2 * v201;
    if ( v200 < v202 )
      v200 = v202;
    hkArrayUtil::_reserve(
      (hkResult *)&v286,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v88->m_intData,
      v200,
      2);
  }
  v88->m_intData.m_size += 8;
  v203 = v88->m_floatData.m_size + 4;
  v204 = v88->m_floatData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v204 < v203 )
  {
    v205 = 2 * v204;
    if ( v203 < v205 )
      v203 = v205;
    hkArrayUtil::_reserve(
      (hkResult *)&v286,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v88->m_floatData,
      v203,
      4);
  }
  v88->m_floatData.m_size += 4;
  v206 = v88->m_intData.m_size;
  if ( v206 < (v88->m_intData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v88->m_intData, 2, 0i64, v206);
  v207 = v88->m_floatData.m_size;
  if ( v207 < (v88->m_floatData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v88->m_floatData,
      4,
      0i64,
      v207);
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    840219356i64,
    "Compression");
  v209 = v7->m_bones.m_size;
  v210 = 0;
  v211 = 9 * v209 + v7->m_floatSlots.m_size;
  v212 = 0;
  *(_QWORD *)&v258.m_size = 0i64;
  *(_QWORD *)&v259 = 0i64;
  v213 = 0;
  v214 = 0i64;
  v215 = 0;
  v216 = 0i64;
  if ( v211 > 0 )
  {
    v217 = v277.m_transformTrackFromBone.m_data;
    do
    {
      if ( (signed int)v214 >= 9 * (signed int)v209 )
      {
        v218 = v277.m_floatTrackFromSlot.m_data[v216 - 9 * v209] == -1;
      }
      else
      {
        v208 = (unsigned int)v214 / 9;
        v218 = v217[v208] == -1;
      }
      if ( !v218 )
      {
        ++*(&v258.m_size + (signed int)v264[v216]);
        ++v213;
      }
      v214 = (unsigned int)(v214 + 1);
      ++v216;
    }
    while ( (signed int)v214 < v211 );
    v215 = v259;
    v210 = v258.m_capacityAndFlags;
    v212 = v258.m_size;
    v7 = v277.m_skel;
  }
  v219 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *, __int64, __int64, __int64))v277.m_anim->vfptr[3].__first_virtual_table_function__)(
           v277.m_anim,
           v208,
           v214,
           v216);
  v220 = ((__int64 (__fastcall *)(hkaPredictiveCompressedAnimation *))retaddr->vfptr[3].__first_virtual_table_function__)(retaddr);
  hkErrStream::hkErrStream(&v280, &buf, 512);
  v221 = hkOstream::operator<<((hkOstream *)&v280.vfptr, "Compression: ");
  v222 = hkOstream::operator<<(v221, v219);
  v223 = hkOstream::operator<<(v222, " -> ");
  v224 = hkOstream::operator<<(v223, v220);
  v225 = hkOstream::operator<<(v224, " (");
  v226 = hkOstream::operator<<(v225, (float)v219 / (float)v220);
  hkOstream::operator<<(v226, ":1)");
  hkError::messageReport(
    -1,
    (const char *)&buf,
    "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
    690);
  hkOstream::~hkOstream((hkOstream *)&v280.vfptr);
  hkErrStream::hkErrStream(&v280, &buf, 512);
  v227 = v7->m_bones.m_size;
  v228 = v7->m_floatSlots.m_size;
  v229 = v227 + v228 + 8 * v227;
  v230 = hkOstream::operator<<((hkOstream *)&v280.vfptr, v227);
  v231 = hkOstream::operator<<(v230, " bones, ");
  v232 = hkOstream::operator<<(v231, v228);
  v233 = hkOstream::operator<<(v232, " floats, ");
  v234 = hkOstream::operator<<(v233, v213);
  v235 = hkOstream::operator<<(v234, "/");
  v236 = hkOstream::operator<<(v235, v229);
  hkOstream::operator<<(v236, " animated channels");
  hkError::messageReport(
    -1,
    (const char *)&buf,
    "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
    692);
  hkOstream::~hkOstream((hkOstream *)&v280.vfptr);
  hkErrStream::hkErrStream(&v280, &buf, 512);
  v237 = v277.m_anim;
  v238 = ((__int64 (__fastcall *)(hkaInterleavedUncompressedAnimation *))v277.m_anim->vfptr[4].__vecDelDtor)(v277.m_anim);
  v239 = hkOstream::operator<<((hkOstream *)&v280.vfptr, v238);
  hkOstream::operator<<(v239, " frames");
  hkError::messageReport(
    -1,
    (const char *)&buf,
    "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
    693);
  hkOstream::~hkOstream((hkOstream *)&v280.vfptr);
  hkErrStream::hkErrStream(&v280, &buf, 512);
  v240 = hkOstream::operator<<((hkOstream *)&v280.vfptr, v212);
  v241 = hkOstream::operator<<(v240, " static, ");
  v242 = hkOstream::operator<<(v241, v210);
  v243 = hkOstream::operator<<(v242, " reference, ");
  v244 = hkOstream::operator<<(v243, v215);
  v245 = hkOstream::operator<<(v244, " ranged, ");
  v246 = hkOstream::operator<<(v245, v260);
  hkOstream::operator<<(v246, " fixed channels");
  hkError::messageReport(
    -1,
    (const char *)&buf,
    "Animation\\PredictiveCompressed\\hkaPredictiveCompressedAnimationCtor.cpp",
    694);
  hkOstream::~hkOstream((hkOstream *)&v280.vfptr);
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
  v247 = retaddr->m_compressedData.m_size;
  v248 = &retaddr->m_compressedData;
  if ( v247 < (retaddr->m_compressedData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v248, 1, 0i64, v247);
  retaddr->m_numFrames = (__int64)v237->vfptr[4].__vecDelDtor((hkBaseObject *)&v237->vfptr, (unsigned int)v248);
  retaddr->m_numFloatSlots = v7->m_floatSlots.m_size;
  retaddr->m_numBones = v7->m_bones.m_size;
  v249 = v237->m_duration;
  retaddr->m_skeleton = v7;
  retaddr->m_duration = v249;
  retaddr->m_numberOfTransformTracks = v237->m_numberOfTransformTracks;
  retaddr->m_numberOfFloatTracks = v237->m_numberOfFloatTracks;
  hkaPredictiveCompressedAnimation::computeMaxCompressedBytesPerFrame(retaddr);
  v261.m_size = 0;
  if ( v261.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v261.m_data,
      2 * (v261.m_capacityAndFlags & 0x3FFFFFFF));
  v261.m_data = 0i64;
  v261.m_capacityAndFlags = 2147483648;
  arr.m_size = 0;
  if ( arr.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      arr.m_data,
      2 * (arr.m_capacityAndFlags & 0x3FFFFFFF));
  arr.m_data = 0i64;
  arr.m_capacityAndFlags = 2147483648;
  LODWORD(v258.m_data) = 0;
  if ( SHIDWORD(v258.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v258.m_data,
      4 * HIDWORD(v258.m_data));
  v258.m_data = 0i64;
  HIDWORD(v258.m_data) = 2147483648;
  v257.m_size = 0;
  if ( v257.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v257.m_data,
      4 * v257.m_capacityAndFlags);
  v257.m_data = 0i64;
  v257.m_capacityAndFlags = 2147483648;
  v256.m_size = 0;
  if ( v256.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v256.m_data,
      4 * v256.m_capacityAndFlags);
  v256.m_data = 0i64;
  v256.m_capacityAndFlags = 2147483648;
  v269.m_size = 0;
  if ( v269.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v269.m_data,
      2 * (v269.m_capacityAndFlags & 0x3FFFFFFF));
  v269.m_data = 0i64;
  v269.m_capacityAndFlags = 2147483648;
  v274.m_size = 0;
  if ( v274.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v274.m_data,
      2 * (v274.m_capacityAndFlags & 0x3FFFFFFF));
  v274.m_data = 0i64;
  v274.m_capacityAndFlags = 2147483648;
  v273.m_size = 0;
  if ( v273.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v273.m_data,
      2 * (v273.m_capacityAndFlags & 0x3FFFFFFF));
  v273.m_data = 0i64;
  v273.m_capacityAndFlags = 2147483648;
  v271.m_size = 0;
  if ( v271.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v271.m_data,
      2 * (v271.m_capacityAndFlags & 0x3FFFFFFF));
  v271.m_data = 0i64;
  v271.m_capacityAndFlags = 2147483648;
  v270.m_size = 0;
  if ( v270.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v270.m_data,
      2 * (v270.m_capacityAndFlags & 0x3FFFFFFF));
  v270.m_data = 0i64;
  v270.m_capacityAndFlags = 2147483648;
  v250.m_size = 0;
  if ( v250.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v250.m_data,
      2 * (v250.m_capacityAndFlags & 0x3FFFFFFF));
  v250.m_data = 0i64;
  v250.m_capacityAndFlags = 2147483648;
  v252 = 0;
  if ( v253 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      2 * (v253 & 0x3FFFFFFF));
  array = 0i64;
  v253 = 2147483648;
  if ( v282 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v264,
      4 * v282);
  if ( v281 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v272,
      48 * (v281 & 0x3FFFFFFF));
  hkaPredictiveCompressedAnimationUtil::Remapper::~Remapper(&v277);
}ta = 0i64;
  v273.m_capacityAndFlags = 2147483648;
  v271.m_size = 0;
  if ( v271.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v271.m_data,
      2 * (v271.m_capacityAndFlags & 0x3FFFFFFF));
  v271.m_data = 0i64;
  v271.m_capacityAndF

// File Line: 713
// RVA: 0xB38880
void __fastcall hkaPredictiveCompressedAnimation::computeMaxCompressedBytesPerFrame(hkaPredictiveCompressedAnimation *this)
{
  int v1; // er11
  hkaPredictiveCompressedAnimation *v2; // r10
  __int64 v3; // rdx
  int v4; // eax
  __int64 v5; // rdi
  unsigned __int16 *v6; // rsi
  int v7; // ebx
  signed __int64 v8; // r9
  signed __int64 v9; // rcx
  int v10; // er8
  int v11; // eax

  v1 = 0;
  v2 = this;
  this->m_maxCompressedBytesPerFrame = 0;
  v3 = 0i64;
  v4 = (this->m_intArrayOffsets[1] - this->m_intArrayOffsets[0]) / 2;
  v5 = v4;
  if ( v4 > 0 )
  {
    v6 = this->m_intData.m_data;
    v7 = 0;
    v8 = 2i64;
    do
    {
      v9 = (signed __int64)&v6[v2->m_intArrayOffsets[0]];
      v10 = *(unsigned __int16 *)(v9 + 4 * v3) | (*(unsigned __int16 *)(v8 + v9) << 16);
      v11 = v10 - v1;
      if ( v11 > v7 )
      {
        v7 = (*(unsigned __int16 *)(v9 + 4 * v3) | (*(unsigned __int16 *)(v8 + v9) << 16)) - v1;
        v2->m_maxCompressedBytesPerFrame = v11;
      }
      ++v3;
      v8 += 4i64;
      v1 = v10;
    }
    while ( v3 < v5 );
  }
}

// File Line: 736
// RVA: 0xB38910
void __fastcall hkaPredictiveCompressedAnimation::addArray(hkaPredictiveCompressedAnimation *this, hkArrayBase<unsigned short> *arr, hkaPredictiveCompressedAnimation::IntArrayID idx)
{
  int v3; // eax
  hkArrayBase<unsigned short> *v4; // rcx

  v3 = this->m_intData.m_size;
  v4 = (hkArrayBase<unsigned short> *)&this->m_intData.m_data;
  *((_DWORD *)&v4[1].m_data + (signed int)idx) = v3;
  hkArrayBase<unsigned short>::_append(
    v4,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    arr->m_data,
    arr->m_size);
}

// File Line: 744
// RVA: 0xB38940
void __fastcall hkaPredictiveCompressedAnimation::addArray(hkaPredictiveCompressedAnimation *this, hkArrayBase<float> *arr, hkaPredictiveCompressedAnimation::FloatArrayID idx)
{
  int v3; // eax
  hkArrayBase<float> *v4; // rcx

  v3 = this->m_floatData.m_size;
  v4 = (hkArrayBase<float> *)&this->m_floatData.m_data;
  *((_DWORD *)&v4[1].m_data + (signed int)idx) = v3;
  hkArrayBase<float>::_append(
    v4,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    arr->m_data,
    arr->m_size);
}

