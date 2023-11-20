// File Line: 23
// RVA: 0xB2D690
void __fastcall hkaQuantizedAnimation::sampleIndividualTransformTracks(hkaQuantizedAnimation *this, float time, const __int16 *tracks, unsigned int numTracks)
{
  ;
}

// File Line: 28
// RVA: 0xB2D6A0
void __fastcall hkaQuantizedAnimation::sampleIndividualFloatTracks(hkaQuantizedAnimation *this, float time, const __int16 *tracks, unsigned int numTracks)
{
  ;
}

// File Line: 33
// RVA: 0xB2D6B0
__int64 __fastcall hkaQuantizedAnimation::getNumOriginalFrames(hkaQuantizedAnimation *this)
{
  return *((unsigned __int16 *)this->m_data.m_data + 3);
}

// File Line: 39
// RVA: 0xB2EAD0
void __fastcall hkaQuantizedAnimation::sampleStaticScalars(float *poseOut, int numPoseOut, const unsigned __int16 *elements, const float *values, int n)
{
  unsigned __int16 v5; // r11
  int v6; // ebx
  signed __int64 v7; // r10
  float v8; // eax

  if ( n > 0 )
  {
    v5 = *elements;
    v6 = 0;
    v7 = 0i64;
    if ( n - 1 > 0 )
    {
      do
      {
        if ( v5 >= numPoseOut )
          break;
        v8 = values[v7++];
        ++v6;
        poseOut[v5] = v8;
        v5 = elements[v7];
      }
      while ( v7 < n - 1 );
    }
    if ( v5 < numPoseOut )
      poseOut[v5] = values[v6];
  }
}

// File Line: 68
// RVA: 0xB2EB50
void __fastcall hkaQuantizedAnimation::sampleDynamicScalars(float *poseOut, int numPoseOut, const unsigned __int16 *elements, const float *minimums, const float *spans, const unsigned __int16 *values, int n)
{
  hkaCompression::sampleDynamicScalarsInternal(poseOut, numPoseOut, elements, minimums, spans, values, n);
}

// File Line: 76
// RVA: 0xB2EB60
void __fastcall hkaQuantizedAnimation::sampleRotations(hkQuaternionf *poseOut, int numPoseOut, const unsigned __int16 *elements, const unsigned __int16 *values, int n)
{
  int v5; // er15
  int v6; // edx
  const unsigned __int16 *v7; // r12
  hkQuaternionf *v8; // r13
  int v9; // ebp
  int v10; // er14
  signed int v11; // eax
  unsigned __int16 v12; // cx
  const unsigned __int16 *v13; // r12
  int v14; // ebx
  int v15; // edi
  int v16; // esi
  __int64 v17; // rbx
  __int64 i; // rsi
  signed int v19; // edi
  int v20; // ecx
  unsigned __int16 v21; // [rsp+30h] [rbp-98h]
  __int64 v22; // [rsp+38h] [rbp-90h]
  hkVector4f dst0; // [rsp+40h] [rbp-88h]
  __int64 v24; // [rsp+50h] [rbp-78h]
  hkVector4f dst1; // [rsp+60h] [rbp-68h]
  hkVector4f dst2; // [rsp+70h] [rbp-58h]
  hkVector4f dst3; // [rsp+80h] [rbp-48h]
  const unsigned __int16 *v28; // [rsp+E0h] [rbp+18h]
  const unsigned __int16 *v29; // [rsp+E8h] [rbp+20h]

  v29 = values;
  v28 = elements;
  v5 = numPoseOut;
  v6 = n;
  v7 = elements;
  v8 = poseOut;
  if ( n > 0 )
  {
    v9 = 0;
    v10 = 0;
    v11 = (n & 0xFFFFFFFC) - 4;
    if ( v11 > 0 )
    {
      v12 = elements[3];
      v22 = 0i64;
      v24 = v11;
      v21 = v12;
      if ( v11 > 0i64 )
      {
        v13 = elements + 2;
        do
        {
          if ( v12 >= v5 )
            break;
          v14 = *(v13 - 2);
          v15 = *(v13 - 1);
          v16 = *v13;
          hkaQuantizedQuaternion::unpackQuaternions48(&dst0, &dst1, &dst2, &dst3, &values[v10]);
          values = v29;
          v13 += 4;
          v9 += 4;
          v10 += 12;
          v22 += 4i64;
          v8[v14].m_vec = (hkVector4f)dst0.m_quad;
          v8[v15].m_vec = (hkVector4f)dst1.m_quad;
          v8[v16].m_vec = (hkVector4f)dst2.m_quad;
          v8[v21].m_vec = (hkVector4f)dst3.m_quad;
          v12 = v13[1];
          v21 = v13[1];
        }
        while ( v22 < v24 );
        v7 = v28;
        v6 = n;
      }
    }
    v17 = v9;
    for ( i = v6; v17 < i; v10 += 12 )
    {
      v19 = 0;
      do
      {
        if ( v17 >= i )
          break;
        v20 = v7[v17];
        if ( v20 >= v5 )
          return;
        hkaSignedQuaternion::unpackSignedQuaternion48(
          (const char *)&values[v10 + (signed __int64)v19],
          &v8[(unsigned __int16)v20]);
        values = v29;
        v19 += 3;
        ++v9;
        ++v17;
      }
      while ( v19 < 12 );
      values = v29;
    }
  }
}

// File Line: 154
// RVA: 0xB2CB30
void __fastcall hkaQuantizedAnimation::sampleFullPose(hkaQuantizedAnimation *this, hkQsTransformf *bonesOut, float *floatsOut, float *boneWeightsOut, float *floatWeightsOut, float time, bool useSlerp, float frameSteppingTolerance)
{
  hkaQuantizedAnimation::sampleFullPose(
    this->m_data.m_data,
    *((unsigned __int16 *)this->m_data.m_data + 1),
    *((unsigned __int16 *)this->m_data.m_data + 2),
    bonesOut,
    floatsOut,
    boneWeightsOut,
    floatWeightsOut,
    this->m_skeleton->m_referencePose.m_data,
    this->m_skeleton->m_referenceFloats.m_data,
    time,
    useSlerp,
    frameSteppingTolerance);
}

// File Line: 162
// RVA: 0xB2CBC0
void __fastcall hkaQuantizedAnimation::sampleFullPose(hkaQuantizedAnimation *this, int numBones, int numFloats, hkQsTransformf *bonesOut, float *floatsOut, float *boneWeightsOut, float *floatWeightsOut, float time, bool useSlerp, float frameSteppingTolerance)
{
  hkaQuantizedAnimation::sampleFullPose(
    this->m_data.m_data,
    numBones,
    numFloats,
    bonesOut,
    floatsOut,
    boneWeightsOut,
    floatWeightsOut,
    this->m_skeleton->m_referencePose.m_data,
    this->m_skeleton->m_referenceFloats.m_data,
    time,
    useSlerp,
    frameSteppingTolerance);
}

// File Line: 168
// RVA: 0xB2CC40
void __fastcall hkaQuantizedAnimation::sampleFullPose(hkaQuantizedAnimation *this, int numBones, int numFloats, hkQsTransformf *bonesOut, float *floatsOut, float *boneWeightsOut, float *floatWeightsOut, hkQsTransformf *bonesScratch0, hkQsTransformf *bonesScratch1, float *floatsScratch0, float *floatsScratch1, float time, bool useSlerp, float frameSteppingTolerance)
{
  hkaQuantizedAnimation::sampleFullPose(
    this->m_data.m_data,
    numBones,
    numFloats,
    bonesOut,
    floatsOut,
    boneWeightsOut,
    floatWeightsOut,
    this->m_skeleton->m_referencePose.m_data,
    this->m_skeleton->m_referenceFloats.m_data,
    bonesScratch0,
    bonesScratch1,
    floatsScratch0,
    floatsScratch1,
    time,
    useSlerp,
    frameSteppingTolerance);
}

// File Line: 174
// RVA: 0xB2D6C0
void __fastcall hkaQuantizedAnimation::sampleFullPose(const char *headerData, int numBones, int numFloats, hkQsTransformf *bonesOut, float *floatsOut, float *boneWeightsOut, float *floatWeightsOut, hkQsTransformf *referencePose, const float *referenceFloats, float time, bool useSlerp, float frameSteppingTolerance)
{
  float *floatsScratch1; // r14
  const char *v13; // r15
  unsigned int v14; // edx
  signed int v15; // edi
  unsigned int v16; // edx
  hkQsTransformf *bonesScratch1; // r13
  signed int v18; // esi
  unsigned int v19; // eax
  float *floatsScratch0; // r12
  signed int v21; // ebx
  unsigned int v22; // eax
  signed int v23; // ebp
  int v24; // [rsp+80h] [rbp-68h]
  int v25; // [rsp+84h] [rbp-64h]
  int v26; // [rsp+88h] [rbp-60h]
  hkQsTransformf *bonesScratch0; // [rsp+90h] [rbp-58h]
  int v28; // [rsp+F0h] [rbp+8h]
  int numBonesa; // [rsp+F8h] [rbp+10h]
  int numFloatsa; // [rsp+100h] [rbp+18h]
  hkQsTransformf *bonesOuta; // [rsp+108h] [rbp+20h]

  bonesOuta = bonesOut;
  numFloatsa = numFloats;
  numBonesa = numBones;
  floatsScratch1 = 0i64;
  v13 = headerData;
  v14 = (*((unsigned __int16 *)headerData + 1) + 3) & 0xFFFFFFFC;
  if ( v14 )
  {
    v28 = 48 * v14;
    bonesScratch0 = (hkQsTransformf *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                        &v28);
    v14 = v28 / 48;
  }
  else
  {
    bonesScratch0 = 0i64;
  }
  v15 = 2147483648;
  if ( v14 )
    v15 = v14;
  v16 = (*((unsigned __int16 *)v13 + 1) + 3) & 0xFFFFFFFC;
  if ( v16 )
  {
    v24 = 48 * v16;
    bonesScratch1 = (hkQsTransformf *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                        &v24);
    v16 = v24 / 48;
  }
  else
  {
    bonesScratch1 = 0i64;
  }
  v18 = 2147483648;
  if ( v16 )
    v18 = v16;
  v19 = (*((unsigned __int16 *)v13 + 2) + 3) & 0xFFFFFFFC;
  if ( v19 )
  {
    v25 = 4 * v19;
    floatsScratch0 = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                &v25);
    v19 = v25 / 4;
  }
  else
  {
    floatsScratch0 = 0i64;
  }
  v21 = 2147483648;
  if ( v19 )
    v21 = v19;
  v22 = (*((unsigned __int16 *)v13 + 2) + 3) & 0xFFFFFFFC;
  if ( v22 )
  {
    v26 = 4 * v22;
    floatsScratch1 = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                &v26);
    v22 = v26 / 4;
  }
  v23 = 2147483648;
  if ( v22 )
    v23 = v22;
  hkaQuantizedAnimation::sampleFullPose(
    v13,
    numBonesa,
    numFloatsa,
    bonesOuta,
    floatsOut,
    boneWeightsOut,
    floatWeightsOut,
    referencePose,
    referenceFloats,
    bonesScratch0,
    bonesScratch1,
    floatsScratch0,
    floatsScratch1,
    time,
    useSlerp,
    frameSteppingTolerance);
  if ( v23 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      floatsScratch1,
      4 * v23);
  if ( v21 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      floatsScratch0,
      4 * v21);
  if ( v18 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      bonesScratch1,
      48 * (v18 & 0x3FFFFFFF));
  if ( v15 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      bonesScratch0,
      48 * (v15 & 0x3FFFFFFF));
}

// File Line: 187
// RVA: 0xB2D9B0
void __fastcall hkaQuantizedAnimation::sampleFullPose(const char *headerData, int numBones, int numFloats, hkQsTransformf *bonesOut, float *floatsOut, float *boneWeightsOut, float *floatWeightsOut, hkQsTransformf *referencePose, const float *referenceFloats, hkQsTransformf *bonesScratch0, hkQsTransformf *bonesScratch1, float *floatsScratch0, float *floatsScratch1, float time, bool useSlerp, float frameSteppingTolerance)
{
  __m128 v16; // xmm1
  const char *v17; // r10
  hkQsTransformf *v18; // r11
  unsigned int v19; // er9
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  signed int v24; // ecx
  float delta; // xmm4_4
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm1

  v16 = _mm_shuffle_ps((__m128)*((unsigned int *)headerData + 2), (__m128)*((unsigned int *)headerData + 2), 0);
  v17 = headerData;
  v18 = bonesOut;
  v19 = *((unsigned __int16 *)headerData + 3) - 2;
  v20 = _mm_rcp_ps(v16);
  v21 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v20)), v20);
  v22 = 0i64;
  v22.m128_f32[0] = (float)(*((unsigned __int16 *)headerData + 3) - 1);
  v23 = _mm_mul_ps(
          v21,
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0)));
  v24 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v23));
  if ( v24 <= v19 )
  {
    v26 = 0i64;
    v26.m128_f32[0] = (float)v24;
    v19 = v24;
    v27 = _mm_sub_ps(v23, _mm_shuffle_ps(v26, v26, 0));
    v28 = _mm_cmpltps(v27, query.m_quad);
    delta = fmax(
              0.0,
              COERCE_FLOAT(v27.m128_i32[0] & v28.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v28, query.m_quad)));
  }
  else
  {
    delta = *(float *)&FLOAT_1_0;
  }
  hkaQuantizedAnimation::sampleFullPose(
    v17,
    &v17[*(unsigned __int16 *)v17 + v19 * *((unsigned __int16 *)v17 + 14)],
    &v17[*(unsigned __int16 *)v17 + *((unsigned __int16 *)v17 + 14) * (v19 + 1)],
    numBones,
    numFloats,
    v18,
    floatsOut,
    boneWeightsOut,
    floatWeightsOut,
    referencePose,
    referenceFloats,
    bonesScratch0,
    bonesScratch1,
    floatsScratch0,
    floatsScratch1,
    delta,
    useSlerp,
    frameSteppingTolerance);
}

// File Line: 218
// RVA: 0xB2DB50
void __fastcall hkaQuantizedAnimation::sampleFullPose(const char *headerData, const char *frameData0, const char *frameData1, int numBones, int numFloats, hkQsTransformf *bonesOut, float *floatsOut, float *boneWeightsOut, float *floatWeightsOut, hkQsTransformf *referencePose, const float *referenceFloats, hkQsTransformf *bonesScratch0, hkQsTransformf *bonesScratch1, float *floatsScratch0, float *floatsScratch1, float delta, bool useSlerp, float frameSteppingTolerance)
{
  int v18; // esi
  unsigned __int16 *v19; // rbx
  unsigned __int16 *v20; // rdi
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r9
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  float v26; // xmm8_4
  hkQsTransformf *v27; // r12
  hkQsTransformf *v28; // r13
  hkQsTransformf *v29; // rcx
  float *v30; // r14
  int v31; // er15
  float v32; // xmm7_4
  hkQsTransformf *v33; // rbx
  signed int v34; // eax
  int v35; // ebp
  float *v36; // rcx
  hkQuaternionf *v37; // r15
  int v38; // er12
  int v39; // er13
  __int64 n; // rdi
  __int64 v41; // rsi
  int v42; // ebx
  float *v43; // ST48_8
  hkQuaternionf *v44; // ST40_8
  int v45; // ebx
  unsigned __int16 *v46; // rsi
  __int64 v47; // r15
  __int64 v48; // r14
  __int64 v49; // rbp
  unsigned __int16 *v50; // rsi
  int v51; // ebx
  __int64 v52; // rdx
  int v53; // eax
  int v54; // edi
  signed __int64 v55; // r10
  int v56; // er9
  unsigned int *v57; // rcx
  float *v58; // rdx
  unsigned int v59; // eax
  __int64 v60; // r8
  __m128i v61; // xmm2
  __m128 v62; // xmm2
  __int128 *v63; // rcx
  __m128 v64; // xmm1
  __m128 v65; // xmm2
  float *v66; // r8
  __int128 *v67; // rdx
  __int64 v68; // r9
  __m128 v69; // xmm0
  __m128 v70; // xmm0
  __m128 v71; // xmm1
  unsigned int *v72; // r10
  unsigned int *v73; // rdx
  float *v74; // r8
  unsigned int v75; // eax
  __int64 v76; // r9
  __m128i v77; // xmm2
  __m128 v78; // xmm2
  __m128 v79; // xmm0
  __m128 v80; // xmm2
  float *v81; // rax
  __int64 v82; // rdx
  __m128 v83; // xmm0
  __m128 v84; // xmm1
  _QWORD *v85; // rax
  _QWORD *v86; // rcx
  _QWORD *v87; // r8
  unsigned __int64 v88; // rax
  signed __int64 v89; // rcx
  unsigned __int16 *values[2]; // [rsp+50h] [rbp-88h]
  unsigned __int16 *v91; // [rsp+E0h] [rbp+8h]
  signed int v92; // [rsp+E8h] [rbp+10h]
  float *poseOut; // [rsp+F0h] [rbp+18h]
  int v94; // [rsp+F8h] [rbp+20h]
  signed int frameSteppingTolerancea; // [rsp+168h] [rbp+90h]

  v94 = numBones;
  v91 = (unsigned __int16 *)headerData;
  v18 = numBones;
  v19 = (unsigned __int16 *)frameData1;
  v20 = (unsigned __int16 *)frameData0;
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "TtQuantizedSampleFullPose";
    v24 = __rdtsc();
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
  v26 = frameSteppingTolerance;
  v27 = bonesScratch1;
  v28 = bonesScratch0;
  v29 = referencePose;
  v30 = floatsOut;
  v31 = 0;
  values[1] = v19;
  v32 = 1.0 - frameSteppingTolerance;
  v33 = bonesOut;
  v34 = 0;
  v92 = 0;
  values[0] = v20;
  do
  {
    if ( v34 )
    {
      if ( delta > v26 )
      {
        v35 = numFloats;
        if ( delta < v32 )
        {
          hkaSampleAndCombineUtils::copyReferencePose(v27, floatsScratch1, v29, v18, referenceFloats, numFloats);
          v36 = (float *)v27;
          v37 = (hkQuaternionf *)v27;
          v30 = floatsScratch1;
        }
        else
        {
          hkaSampleAndCombineUtils::copyReferencePose(v33, v30, v29, v18, referenceFloats, numFloats);
          v36 = (float *)v33;
          v37 = (hkQuaternionf *)v33;
        }
        frameSteppingTolerancea = 1;
        goto LABEL_14;
      }
    }
    else
    {
      if ( delta <= v26 )
      {
        v35 = numFloats;
        hkaSampleAndCombineUtils::copyReferencePose(v33, v30, v29, v18, referenceFloats, numFloats);
        frameSteppingTolerancea = 0;
        v36 = (float *)v33;
        v37 = (hkQuaternionf *)v33;
LABEL_14:
        v38 = 3 * v18;
        v39 = 3 * v18;
        n = v91[15];
        v41 = v91[17];
        v42 = v91[6] + v91[8];
        v38 *= 4;
        v43 = v30;
        v44 = v37;
        poseOut = v36;
        hkaQuantizedAnimation::sampleStaticScalars(
          v36,
          v38,
          (unsigned __int16 *)((char *)v91 + n),
          (const float *)((char *)v91 + v41),
          v42);
        LODWORD(n) = n + 2 * v42;
        v45 = v41 + 4 * v42;
        v46 = v91;
        hkaQuantizedAnimation::sampleRotations(
          v37,
          v39,
          (unsigned __int16 *)((char *)v91 + (signed int)n),
          (unsigned __int16 *)((char *)v91 + v45),
          v91[7]);
        hkaQuantizedAnimation::sampleStaticScalars(
          v30,
          v35,
          (unsigned __int16 *)((char *)v46 + (signed int)(n + 2 * v46[7])),
          (const float *)((char *)v46 + ((v45 + 6 * v46[7] + 15) & 0xFFFFFFFFFFFFFFF0ui64)),
          v46[9]);
        v47 = v91[16];
        v48 = v91[18];
        v49 = v91[19];
        LODWORD(n) = v46[10] + v46[12];
        v50 = values[frameSteppingTolerancea];
        hkaQuantizedAnimation::sampleDynamicScalars(
          poseOut,
          v38,
          (unsigned __int16 *)((char *)v91 + v47),
          (const float *)((char *)v91 + v48),
          (const float *)((char *)v91 + v49),
          values[frameSteppingTolerancea],
          n);
        v51 = n;
        LODWORD(v47) = 2 * n + v47;
        LODWORD(n) = 4 * n;
        hkaQuantizedAnimation::sampleRotations(
          v44,
          v39,
          (unsigned __int16 *)((char *)v91 + (signed int)v47),
          &v50[v51],
          v91[11]);
        v52 = (signed int)n + (signed int)v49 + 15;
        v53 = n + v48 + 15;
        v54 = numFloats;
        hkaQuantizedAnimation::sampleDynamicScalars(
          v43,
          numFloats,
          (unsigned __int16 *)((char *)&v91[v91[11]] + (signed int)v47),
          (const float *)((char *)v91 + (v53 & 0xFFFFFFFFFFFFFFF0ui64)),
          (const float *)((char *)v91 + (v52 & 0xFFFFFFFFFFFFFFF0ui64)),
          &v50[2 * v91[11] + v91[11] + v51],
          v91[13]);
        v33 = bonesOut;
        v18 = v94;
        v34 = v92;
        v30 = floatsOut;
        v29 = referencePose;
        v27 = bonesScratch1;
        v28 = bonesScratch0;
        v31 = 0;
        goto LABEL_16;
      }
      if ( delta < v32 )
      {
        v35 = numFloats;
        hkaSampleAndCombineUtils::copyReferencePose(v28, floatsScratch0, v29, v18, referenceFloats, numFloats);
        v30 = floatsScratch0;
        frameSteppingTolerancea = 0;
        v36 = (float *)v28;
        v37 = (hkQuaternionf *)v28;
        goto LABEL_14;
      }
    }
    v54 = numFloats;
LABEL_16:
    v92 = ++v34;
  }
  while ( v34 < 2 );
  if ( delta > v26 && delta < v32 )
  {
    *(__m128 *)values = _mm_shuffle_ps((__m128)LODWORD(delta), (__m128)LODWORD(delta), 0);
    hkaBlender::blend(v33, v28, v27, (hkSimdFloat32 *)values, v18, 0, (hkaBlender::ROTATION_MODE)(useSlerp != 0));
    hkaBlender::blend(v30, floatsScratch0, floatsScratch1, (hkSimdFloat32 *)values, v54, 0);
  }
  v55 = (signed __int64)(v91 + 20);
  v56 = 0;
  if ( v18 - 4 > 0 )
  {
    v57 = (unsigned int *)(v91 + 20);
    v58 = boneWeightsOut;
    v59 = ((unsigned int)(v18 - 5) >> 2) + 1;
    v60 = v59;
    v56 = 4 * v59;
    do
    {
      v58 += 4;
      v61 = _mm_unpacklo_epi8((__m128i)*v57, (__m128i)0i64);
      ++v57;
      v62 = (__m128)_mm_cmpeq_epi32(_mm_unpacklo_epi16(v61, (__m128i)0i64), (__m128i)0i64);
      *((__m128 *)v58 - 1) = _mm_or_ps(_mm_andnot_ps(v62, query.m_quad), _mm_and_ps((__m128)0i64, v62));
      --v60;
    }
    while ( v60 );
  }
  v63 = &`hkVector4f::getComponent'::`2'::indexToMask;
  v64 = (__m128)_mm_cmpeq_epi32(
                  _mm_unpacklo_epi16(
                    _mm_unpacklo_epi8((__m128i)*(unsigned int *)(v56 + v55), (__m128i)0i64),
                    (__m128i)0i64),
                  (__m128i)0i64);
  v65 = _mm_or_ps(_mm_andnot_ps(v64, query.m_quad), _mm_and_ps((__m128)0i64, v64));
  if ( v56 < v18 )
  {
    v66 = &boneWeightsOut[v56];
    v67 = &`hkVector4f::getComponent'::`2'::indexToMask;
    v68 = (unsigned int)(v18 - v56);
    do
    {
      v69 = (__m128)*v67;
      ++v66;
      ++v67;
      v70 = _mm_and_ps(v69, v65);
      v71 = _mm_or_ps(_mm_shuffle_ps(v70, v70, 78), v70);
      *((_DWORD *)v66 - 1) = *(unsigned __int128 *)&_mm_shuffle_ps(v71, v71, 177) | v71.m128_i32[0];
      --v68;
    }
    while ( v68 );
  }
  v72 = (unsigned int *)(v18 + v55);
  if ( v54 - 4 > 0 )
  {
    v73 = v72;
    v74 = floatWeightsOut;
    v75 = ((unsigned int)(v54 - 5) >> 2) + 1;
    v76 = v75;
    v31 = 4 * v75;
    do
    {
      v74 += 4;
      v77 = _mm_unpacklo_epi8((__m128i)*v73, (__m128i)0i64);
      ++v73;
      v78 = (__m128)_mm_cmpeq_epi32(_mm_unpacklo_epi16(v77, (__m128i)0i64), (__m128i)0i64);
      *((__m128 *)v74 - 1) = _mm_or_ps(_mm_andnot_ps(v78, query.m_quad), _mm_and_ps((__m128)0i64, v78));
      --v76;
    }
    while ( v76 );
  }
  v79 = (__m128)_mm_cmpeq_epi32(
                  _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)v72[v31 / 4u], (__m128i)0i64), (__m128i)0i64),
                  (__m128i)0i64);
  v80 = _mm_or_ps(_mm_andnot_ps(v79, query.m_quad), _mm_and_ps((__m128)0i64, v79));
  if ( v31 < v54 )
  {
    v81 = &floatWeightsOut[v31];
    v82 = (unsigned int)(v54 - v31);
    do
    {
      ++v81;
      ++v63;
      v83 = _mm_and_ps(v80, (__m128)*(v63 - 1));
      v84 = _mm_or_ps(_mm_shuffle_ps(v83, v83, 78), v83);
      *((_DWORD *)v81 - 1) = *(unsigned __int128 *)&_mm_shuffle_ps(v84, v84, 177) | v84.m128_i32[0];
      --v82;
    }
    while ( v82 );
  }
  v85 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v86 = (_QWORD *)v85[1];
  v87 = v85;
  if ( (unsigned __int64)v86 < v85[3] )
  {
    *v86 = "Et";
    v88 = __rdtsc();
    v89 = (signed __int64)(v86 + 2);
    *(_DWORD *)(v89 - 8) = v88;
    v87[1] = v89;
  }
}

// File Line: 502
// RVA: 0xB2CD00
void __fastcall hkaQuantizedAnimation::sampleTracks(hkaQuantizedAnimation *this, float time, hkQsTransformf *transformTracksOut, float *floatTracksOut)
{
  char *v4; // rax
  unsigned int v5; // er12
  int v6; // er15
  float *v7; // rbx
  unsigned int v8; // esi
  unsigned int v9; // ebp
  hkQsTransformf *v10; // rdi
  hkaQuantizedAnimation *v11; // r14
  int v12; // edx
  unsigned int v13; // eax
  signed int v14; // er13
  int v15; // eax
  signed int v16; // esi
  float *floatWeightsOut; // rcx
  unsigned int v18; // eax
  int v19; // ebp
  float *v20; // r14
  hkQsTransformf *v21; // r11
  unsigned int v22; // er9
  signed __int64 v23; // r10
  float *v24; // rdx
  hkVector4f *v25; // rcx
  unsigned int v26; // eax
  __int64 v27; // r8
  hkQsTransformf *v28; // rax
  hkQsTransformf *v29; // rax
  hkQsTransformf *v30; // rax
  hkQsTransformf *v31; // rax
  float *v32; // rdx
  hkVector4f *v33; // rcx
  __int64 v34; // r8
  hkQsTransformf *v35; // rax
  float *v36; // rdi
  __int64 v37; // r11
  signed __int64 v38; // r9
  float *v39; // rcx
  __int64 v40; // rdx
  unsigned int v41; // eax
  __int64 v42; // r8
  float *v43; // rcx
  int v44; // [rsp+50h] [rbp-78h]
  int v45; // [rsp+54h] [rbp-74h]
  int v46; // [rsp+58h] [rbp-70h]
  hkQsTransformf *bonesOut; // [rsp+60h] [rbp-68h]
  float *floatsOut; // [rsp+68h] [rbp-60h]
  float *boneWeightsOut; // [rsp+70h] [rbp-58h]
  int v50; // [rsp+78h] [rbp-50h]
  int numFloats; // [rsp+7Ch] [rbp-4Ch]
  int v52; // [rsp+80h] [rbp-48h]
  float *v53; // [rsp+88h] [rbp-40h]
  int v54; // [rsp+D0h] [rbp+8h]

  v4 = this->m_data.m_data;
  v5 = 0;
  v6 = *((unsigned __int16 *)v4 + 1);
  v7 = floatTracksOut;
  numFloats = *((unsigned __int16 *)v4 + 2);
  v8 = (v6 + 3) & 0xFFFFFFFC;
  v9 = (numFloats + 3) & 0xFFFFFFFC;
  v10 = transformTracksOut;
  v11 = this;
  v12 = v8;
  if ( v8 )
  {
    v54 = 48 * v8;
    bonesOut = (hkQsTransformf *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                   (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                   &v54);
    v12 = v54 / 48;
  }
  else
  {
    bonesOut = 0i64;
  }
  v13 = 2147483648;
  if ( v12 )
    v13 = v12;
  v52 = v13;
  if ( v8 )
  {
    v45 = 4 * v8;
    boneWeightsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                &v45);
    v8 = v45 / 4;
  }
  else
  {
    boneWeightsOut = 0i64;
  }
  v14 = 2147483648;
  v15 = v9;
  if ( v8 )
    v14 = v8;
  if ( v9 )
  {
    v46 = 4 * v9;
    floatsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                           (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                           &v46);
    v15 = v46 / 4;
  }
  else
  {
    floatsOut = 0i64;
  }
  v16 = 2147483648;
  if ( v15 )
    v16 = v15;
  if ( v9 )
  {
    v44 = 4 * v9;
    floatWeightsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                 &v44);
    v9 = v44 / 4;
  }
  else
  {
    floatWeightsOut = 0i64;
  }
  v18 = 2147483648;
  if ( v9 )
    v18 = v9;
  v19 = numFloats;
  v50 = v18;
  v53 = floatWeightsOut;
  hkaQuantizedAnimation::sampleFullPose(
    v11,
    v6,
    numFloats,
    bonesOut,
    floatsOut,
    boneWeightsOut,
    floatWeightsOut,
    time,
    0,
    0.001);
  v20 = boneWeightsOut;
  v21 = bonesOut;
  v22 = 0;
  v23 = 0i64;
  if ( v6 >= 4 )
  {
    v24 = boneWeightsOut + 2;
    v25 = &bonesOut[1].m_scale;
    v26 = ((unsigned int)(v6 - 4) >> 2) + 1;
    v27 = v26;
    v22 = 4 * v26;
    v23 = 4i64 * v26;
    do
    {
      if ( *(v24 - 2) > 0.0 )
      {
        v28 = v10;
        ++v10;
        v28->m_translation = (hkVector4f)v25[-5].m_quad;
        v28->m_rotation.m_vec = (hkVector4f)v25[-4].m_quad;
        v28->m_scale = (hkVector4f)v25[-3].m_quad;
      }
      if ( *(v24 - 1) > 0.0 )
      {
        v29 = v10;
        ++v10;
        v29->m_translation = (hkVector4f)v25[-2].m_quad;
        v29->m_rotation.m_vec = (hkVector4f)v25[-1].m_quad;
        v29->m_scale = (hkVector4f)v25->m_quad;
      }
      if ( *v24 > 0.0 )
      {
        v30 = v10;
        ++v10;
        v30->m_translation = (hkVector4f)v25[1].m_quad;
        v30->m_rotation.m_vec = (hkVector4f)v25[2].m_quad;
        v30->m_scale = (hkVector4f)v25[3].m_quad;
      }
      if ( v24[1] > 0.0 )
      {
        v31 = v10;
        ++v10;
        v31->m_translation = (hkVector4f)v25[4].m_quad;
        v31->m_rotation.m_vec = (hkVector4f)v25[5].m_quad;
        v31->m_scale = (hkVector4f)v25[6].m_quad;
      }
      v24 += 4;
      v25 += 12;
      --v27;
    }
    while ( v27 );
  }
  if ( v22 < v6 )
  {
    v32 = &v20[v23];
    v33 = &v21[v23].m_scale;
    v34 = v6 - v22;
    do
    {
      if ( *v32 > 0.0 )
      {
        v35 = v10;
        ++v10;
        v35->m_translation = (hkVector4f)v33[-2].m_quad;
        v35->m_rotation.m_vec = (hkVector4f)v33[-1].m_quad;
        v35->m_scale = (hkVector4f)v33->m_quad;
      }
      ++v32;
      v33 += 3;
      --v34;
    }
    while ( v34 );
  }
  v36 = floatsOut;
  v37 = (__int64)v53;
  v38 = 0i64;
  if ( v19 >= 4 )
  {
    v39 = floatsOut + 1;
    v40 = (char *)v53 - (char *)floatsOut;
    v41 = ((unsigned int)(v19 - 4) >> 2) + 1;
    v42 = v41;
    v5 = 4 * v41;
    v38 = 4i64 * v41;
    do
    {
      if ( *(float *)((char *)v39 + v40 - 4) > 0.0 )
      {
        ++v7;
        *(v7 - 1) = *(v39 - 1);
      }
      if ( *(float *)((char *)v39 + v40) > 0.0 )
      {
        ++v7;
        *(v7 - 1) = *v39;
      }
      if ( *(float *)((char *)v39 + v40 + 4) > 0.0 )
      {
        ++v7;
        *(v7 - 1) = v39[1];
      }
      if ( *(float *)((char *)v39 + v40 + 8) > 0.0 )
      {
        ++v7;
        *(v7 - 1) = v39[2];
      }
      v39 += 4;
      --v42;
    }
    while ( v42 );
  }
  if ( v5 < v19 )
  {
    v43 = &v36[v38];
    v38 = v19 - v5;
    do
    {
      if ( *(float *)((char *)v43 + v37 - (_QWORD)v36) > 0.0 )
      {
        ++v7;
        *(v7 - 1) = *v43;
      }
      ++v43;
      --v38;
    }
    while ( v38 );
  }
  if ( v50 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v37,
      (unsigned int)(4 * v50),
      v38);
  if ( v16 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, float *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v36,
      (unsigned int)(4 * v16),
      v38);
  if ( v14 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, float *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v20,
      (unsigned int)(4 * v14),
      v38);
  if ( v52 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkQsTransformf *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      bonesOut,
      48 * (v52 & 0x3FFFFFFFu),
      v38);
}

// File Line: 547
// RVA: 0xB2D1A0
void __fastcall hkaQuantizedAnimation::samplePartialTracks(hkaQuantizedAnimation *this, float time, unsigned int maxNumTransformTracks, hkQsTransformf *transformTracksOut, unsigned int maxNumFloatTracks, float *floatTracksOut)
{
  char *v6; // rax
  unsigned int v7; // er14
  unsigned int v8; // er13
  unsigned int v9; // er12
  hkQsTransformf *v10; // rbx
  unsigned int v11; // ebp
  unsigned int v12; // edi
  unsigned int v13; // esi
  hkaQuantizedAnimation *v14; // r15
  int v15; // edx
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  signed int v19; // edi
  float *floatWeightsOut; // rcx
  unsigned int v21; // eax
  float *v22; // rsi
  float *v23; // r15
  hkQsTransformf *v24; // r11
  signed __int64 v25; // r9
  unsigned int v26; // ecx
  __int64 v27; // r10
  float *v28; // r8
  hkVector4f *v29; // rdx
  hkQsTransformf *v30; // rax
  hkQsTransformf *v31; // rax
  hkQsTransformf *v32; // rax
  hkQsTransformf *v33; // rax
  float *v34; // r8
  hkVector4f *v35; // rdx
  hkQsTransformf *v36; // rax
  unsigned int v37; // er10
  __int64 v38; // rbx
  float *v39; // rdx
  unsigned int v40; // ecx
  __int64 v41; // r11
  float *v42; // r8
  int v43; // [rsp+50h] [rbp-78h]
  int v44; // [rsp+54h] [rbp-74h]
  hkQsTransformf *bonesOut; // [rsp+58h] [rbp-70h]
  int v46; // [rsp+60h] [rbp-68h]
  float *boneWeightsOut; // [rsp+68h] [rbp-60h]
  int v48; // [rsp+70h] [rbp-58h]
  int v49; // [rsp+74h] [rbp-54h]
  float *v50; // [rsp+78h] [rbp-50h]
  int v51; // [rsp+80h] [rbp-48h]
  float *floatsOut; // [rsp+88h] [rbp-40h]
  int v53; // [rsp+D0h] [rbp+8h]

  v6 = this->m_data.m_data;
  v7 = 0;
  v8 = *((unsigned __int16 *)v6 + 1);
  v9 = *((unsigned __int16 *)v6 + 2);
  v10 = transformTracksOut;
  v11 = maxNumTransformTracks;
  v12 = (v8 + 3) & 0xFFFFFFFC;
  v13 = (v9 + 3) & 0xFFFFFFFC;
  v14 = this;
  v15 = v12;
  if ( v12 )
  {
    v53 = 48 * v12;
    bonesOut = (hkQsTransformf *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                   (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                   &v53);
    v15 = v53 / 48;
  }
  else
  {
    bonesOut = 0i64;
  }
  v16 = 2147483648;
  if ( v15 )
    v16 = v15;
  v49 = v16;
  if ( v12 )
  {
    v46 = 4 * v12;
    boneWeightsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                &v46);
    v12 = v46 / 4;
  }
  else
  {
    boneWeightsOut = 0i64;
  }
  v17 = 2147483648;
  if ( v12 )
    v17 = v12;
  v48 = v17;
  v18 = (v9 + 3) & 0xFFFFFFFC;
  if ( v13 )
  {
    v44 = 4 * v13;
    floatsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                           (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                           &v44);
    v18 = v44 / 4;
  }
  else
  {
    floatsOut = 0i64;
  }
  v19 = 2147483648;
  if ( v18 )
    v19 = v18;
  if ( v13 )
  {
    v43 = 4 * v13;
    floatWeightsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                 &v43);
    v13 = v43 / 4;
  }
  else
  {
    floatWeightsOut = 0i64;
  }
  v21 = 2147483648;
  if ( v13 )
    v21 = v13;
  v22 = floatsOut;
  v51 = v21;
  v50 = floatWeightsOut;
  hkaQuantizedAnimation::sampleFullPose(
    v14,
    v8,
    v9,
    bonesOut,
    floatsOut,
    boneWeightsOut,
    floatWeightsOut,
    time,
    0,
    0.001);
  v23 = boneWeightsOut;
  v24 = bonesOut;
  v25 = 0i64;
  v26 = 0;
  v27 = 0i64;
  if ( (signed int)v8 < 4 )
  {
LABEL_36:
    if ( (unsigned int)v25 < v8 )
    {
      v34 = &v23[v27];
      v35 = &v24[v27].m_scale;
      do
      {
        if ( v26 >= v11 )
          break;
        if ( *v34 > 0.0 )
        {
          v36 = v10;
          ++v10;
          v36->m_translation = (hkVector4f)v35[-2].m_quad;
          ++v26;
          v36->m_rotation.m_vec = (hkVector4f)v35[-1].m_quad;
          v36->m_scale = (hkVector4f)v35->m_quad;
        }
        v25 = (unsigned int)(v25 + 1);
        ++v34;
        v35 += 3;
      }
      while ( (unsigned int)v25 < v8 );
    }
  }
  else
  {
    v28 = boneWeightsOut + 2;
    v29 = &bonesOut[1].m_scale;
    while ( v26 < v11 )
    {
      if ( *(v28 - 2) > 0.0 )
      {
        v30 = v10;
        ++v10;
        v30->m_translation = (hkVector4f)v29[-5].m_quad;
        ++v26;
        v30->m_rotation.m_vec = (hkVector4f)v29[-4].m_quad;
        v30->m_scale = (hkVector4f)v29[-3].m_quad;
      }
      if ( v26 >= v11 )
        break;
      if ( *(v28 - 1) > 0.0 )
      {
        v31 = v10;
        ++v10;
        v31->m_translation = (hkVector4f)v29[-2].m_quad;
        ++v26;
        v31->m_rotation.m_vec = (hkVector4f)v29[-1].m_quad;
        v31->m_scale = (hkVector4f)v29->m_quad;
      }
      if ( v26 >= v11 )
        break;
      if ( *v28 > 0.0 )
      {
        v32 = v10;
        ++v10;
        v32->m_translation = (hkVector4f)v29[1].m_quad;
        ++v26;
        v32->m_rotation.m_vec = (hkVector4f)v29[2].m_quad;
        v32->m_scale = (hkVector4f)v29[3].m_quad;
      }
      if ( v26 >= v11 )
        break;
      if ( v28[1] > 0.0 )
      {
        v33 = v10;
        ++v10;
        v33->m_translation = (hkVector4f)v29[4].m_quad;
        ++v26;
        v33->m_rotation.m_vec = (hkVector4f)v29[5].m_quad;
        v33->m_scale = (hkVector4f)v29[6].m_quad;
      }
      v25 = (unsigned int)(v25 + 4);
      v27 += 4i64;
      v28 += 4;
      v29 += 12;
      if ( (unsigned int)v25 >= v8 - 3 )
        goto LABEL_36;
    }
  }
  v37 = maxNumFloatTracks;
  v38 = (__int64)v50;
  v39 = floatTracksOut;
  v40 = 0;
  v41 = 0i64;
  if ( (signed int)v9 < 4 )
  {
LABEL_57:
    if ( v7 < v9 )
    {
      v25 = (signed __int64)&v22[v41];
      do
      {
        if ( v40 >= v37 )
          break;
        if ( *(float *)(v38 - (_QWORD)v22 + v25) > 0.0 )
        {
          ++v39;
          ++v40;
          *(v39 - 1) = *(float *)v25;
        }
        ++v7;
        v25 += 4i64;
      }
      while ( v7 < v9 );
    }
  }
  else
  {
    v42 = v22 + 1;
    v25 = (char *)v50 - (char *)v22;
    while ( v40 < v37 )
    {
      if ( *(float *)((char *)v42 + v25 - 4) > 0.0 )
      {
        ++v39;
        ++v40;
        *(v39 - 1) = *(v42 - 1);
      }
      if ( v40 >= v37 )
        break;
      if ( *(float *)((char *)v42 + v25) > 0.0 )
      {
        ++v39;
        ++v40;
        *(v39 - 1) = *v42;
      }
      if ( v40 >= v37 )
        break;
      if ( *(float *)((char *)v42 + v25 + 4) > 0.0 )
      {
        ++v39;
        ++v40;
        *(v39 - 1) = v42[1];
      }
      if ( v40 >= v37 )
        break;
      if ( *(float *)((char *)v42 + v25 + 8) > 0.0 )
      {
        ++v39;
        ++v40;
        *(v39 - 1) = v42[2];
      }
      v7 += 4;
      v41 += 4i64;
      v42 += 4;
      if ( v7 >= v9 - 3 )
        goto LABEL_57;
    }
  }
  if ( v51 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v38,
      (unsigned int)(4 * v51),
      v25);
  if ( v19 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, float *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v22,
      (unsigned int)(4 * v19),
      v25);
  if ( v48 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, float *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v23,
      (unsigned int)(4 * v48),
      v25);
  if ( v49 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkQsTransformf *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      bonesOut,
      48 * (v49 & 0x3FFFFFFFu),
      v25);
}igned int)(4 * v48),
      v25);
  if ( v49 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkQsTransformf 

// File Line: 590
// RVA: 0xB2E200
signed __int64 __fastcall hkaQuantizedAnimation::getNumDataChunks(hkaQuantizedAnimation *this, unsigned int frame, float delta)
{
  return 4i64;
}

// File Line: 595
// RVA: 0xB2E210
void __fastcall hkaQuantizedAnimation::getDataChunks(hkaQuantizedAnimation *this, unsigned int frame, float delta, hkaAnimation::DataChunk *chunks)
{
  char *v4; // r8
  unsigned int v5; // er10
  __int64 v6; // r11
  unsigned int v7; // eax
  char *v8; // r11

  v4 = this->m_data.m_data;
  v5 = *((unsigned __int16 *)v4 + 14);
  v6 = *(unsigned __int16 *)v4;
  chunks->m_data = (const char *)this;
  chunks->m_size = 88;
  v7 = *(unsigned __int16 *)v4;
  chunks[1].m_data = v4;
  chunks[1].m_size = v7;
  v8 = &v4[v6];
  chunks[2].m_size = v5;
  chunks[2].m_data = &v8[frame * v5];
  chunks[3].m_size = v5;
  chunks[3].m_data = &v8[v5 * (frame + 1)];
}

// File Line: 612
// RVA: 0xB2E270
signed __int64 __fastcall hkaQuantizedAnimation::getMaxSizeOfCombinedDataChunks(hkaQuantizedAnimation *this)
{
  return 2 * ((*((unsigned __int16 *)this->m_data.m_data + 14) + 15) & 0xFFFFFFF0)
       + ((*(unsigned __int16 *)this->m_data.m_data + 15) & 0xFFFFFFF0)
       + 96i64;
}

// File Line: 622
// RVA: 0xB2E2A0
signed __int64 __fastcall hkaQuantizedAnimation::getMaxDecompressionTempBytes(hkaQuantizedAnimation *this)
{
  return 148 * ((this->m_skeleton->m_bones.m_size + 3) & 0xFFFFFFFC)
       + 16i64 * ((this->m_skeleton->m_floatSlots.m_size + 3) & 0xFFFFFFFC);
}

// File Line: 641
// RVA: 0xB2E2D0
void __fastcall hkaQuantizedAnimation::samplePartialWithDataChunks(unsigned int frameIndex, float frameDelta, unsigned int maxNumTransformTracks, unsigned int maxNumFloatTracks, hkQsTransformf *referenceTransforms, const float *referenceFloats, hkaAnimation::DataChunk *dataChunks, int numDataChunks, hkQsTransformf *transformTracksOut, float *floatTracksOut)
{
  const char *v10; // rbp
  const char *v11; // r14
  const char *v12; // r15
  unsigned int v13; // er13
  unsigned int v14; // er12
  unsigned int v15; // esi
  unsigned int v16; // ebx
  unsigned int v17; // edi
  hkLifoAllocator *v18; // rax
  int v19; // edx
  char *v20; // rcx
  hkLifoAllocator *v21; // rax
  char *v22; // rcx
  hkLifoAllocator *v23; // rax
  char *v24; // rcx
  hkLifoAllocator *v25; // rax
  int v26; // er8
  char *v27; // rcx
  hkLifoAllocator *v28; // rax
  float *floatsOut; // rbx
  int v30; // edi
  char *v31; // rcx
  hkLifoAllocator *v32; // rax
  char *v33; // rcx
  hkLifoAllocator *v34; // rax
  char *v35; // rcx
  hkLifoAllocator *v36; // rax
  float *floatWeightsOut; // rdx
  char *v38; // rcx
  hkQsTransformf *v39; // r8
  unsigned int v40; // er11
  unsigned int v41; // er10
  unsigned int v42; // ecx
  __int64 v43; // rbx
  float *v44; // r9
  hkVector4f *v45; // rdx
  hkQsTransformf *v46; // rax
  hkQsTransformf *v47; // rax
  hkQsTransformf *v48; // rax
  hkQsTransformf *v49; // rax
  float *v50; // r9
  hkVector4f *v51; // rdx
  hkQsTransformf *v52; // rax
  float *v53; // rdx
  unsigned int v54; // ecx
  __int64 v55; // r10
  float *v56; // r8
  signed __int64 v57; // r9
  float *v58; // r8
  hkLifoAllocator *v59; // rax
  int v60; // ebx
  hkLifoAllocator *v61; // rax
  hkLifoAllocator *v62; // rax
  hkLifoAllocator *v63; // rax
  hkLifoAllocator *v64; // rax
  int v65; // er8
  hkLifoAllocator *v66; // rax
  int v67; // ebx
  hkLifoAllocator *v68; // rax
  hkLifoAllocator *v69; // rax
  unsigned int numFloats; // [rsp+90h] [rbp-88h]
  float *floatsScratch1; // [rsp+98h] [rbp-80h]
  float *floatsScratch0; // [rsp+A0h] [rbp-78h]
  hkQsTransformf *bonesScratch1; // [rsp+A8h] [rbp-70h]
  hkQsTransformf *bonesOut; // [rsp+B0h] [rbp-68h]
  hkQsTransformf *bonesScratch0; // [rsp+B8h] [rbp-60h]
  float *boneWeightsOut; // [rsp+C0h] [rbp-58h]
  _BYTE *p; // [rsp+C8h] [rbp-50h]
  signed int v78; // [rsp+D0h] [rbp-48h]
  float *v79; // [rsp+D8h] [rbp-40h]
  int dataChunksa; // [rsp+150h] [rbp+38h]

  v10 = dataChunks[1].m_data;
  v11 = dataChunks[2].m_data;
  v12 = dataChunks[3].m_data;
  v13 = *((unsigned __int16 *)v10 + 1);
  v14 = maxNumFloatTracks;
  v15 = maxNumTransformTracks;
  v16 = (v13 + 3) & 0xFFFFFFFC;
  v17 = (*((unsigned __int16 *)v10 + 2) + 3) & 0xFFFFFFFC;
  numFloats = *((unsigned __int16 *)v10 + 2);
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  bonesOut = (hkQsTransformf *)v18->m_cur;
  v19 = (48 * v16 + 127) & 0xFFFFFF80;
  dataChunksa = (48 * v16 + 127) & 0xFFFFFF80;
  v20 = (char *)bonesOut + v19;
  if ( v19 > v18->m_slabSize || v20 > v18->m_end )
    bonesOut = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v18, v19);
  else
    v18->m_cur = v20;
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  bonesScratch0 = (hkQsTransformf *)v21->m_cur;
  v22 = (char *)bonesScratch0 + dataChunksa;
  if ( dataChunksa > v21->m_slabSize || v22 > v21->m_end )
    bonesScratch0 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v21, dataChunksa);
  else
    v21->m_cur = v22;
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  bonesScratch1 = (hkQsTransformf *)v23->m_cur;
  v24 = (char *)bonesScratch1 + dataChunksa;
  if ( dataChunksa > v23->m_slabSize || v24 > v23->m_end )
    bonesScratch1 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v23, dataChunksa);
  else
    v23->m_cur = v24;
  v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (4 * v16 + 127) & 0xFFFFFF80;
  v78 = (4 * v16 + 127) & 0xFFFFFF80;
  boneWeightsOut = (float *)v25->m_cur;
  v27 = (char *)boneWeightsOut + v26;
  if ( v26 > v25->m_slabSize || v27 > v25->m_end )
    boneWeightsOut = (float *)hkLifoAllocator::allocateFromNewSlab(v25, v26);
  else
    v25->m_cur = v27;
  v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  floatsOut = (float *)v28->m_cur;
  v30 = (4 * v17 + 127) & 0xFFFFFF80;
  v79 = floatsOut;
  v31 = (char *)floatsOut + v30;
  if ( v30 > v28->m_slabSize || v31 > v28->m_end )
  {
    floatsOut = (float *)hkLifoAllocator::allocateFromNewSlab(v28, v30);
    v79 = floatsOut;
  }
  else
  {
    v28->m_cur = v31;
  }
  v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v33 = (char *)v32->m_cur + v30;
  floatsScratch0 = (float *)v32->m_cur;
  if ( v30 > v32->m_slabSize || v33 > v32->m_end )
    floatsScratch0 = (float *)hkLifoAllocator::allocateFromNewSlab(v32, v30);
  else
    v32->m_cur = v33;
  v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (char *)v34->m_cur + v30;
  floatsScratch1 = (float *)v34->m_cur;
  if ( v30 > v34->m_slabSize || v35 > v34->m_end )
    floatsScratch1 = (float *)hkLifoAllocator::allocateFromNewSlab(v34, v30);
  else
    v34->m_cur = v35;
  v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  floatWeightsOut = (float *)v36->m_cur;
  v38 = (char *)floatWeightsOut + v30;
  p = v36->m_cur;
  if ( v30 > v36->m_slabSize || v38 > v36->m_end )
  {
    floatWeightsOut = (float *)hkLifoAllocator::allocateFromNewSlab(v36, v30);
    p = floatWeightsOut;
  }
  else
  {
    v36->m_cur = v38;
  }
  hkaQuantizedAnimation::sampleFullPose(
    v10,
    v11,
    v12,
    v13,
    numFloats,
    bonesOut,
    floatsOut,
    boneWeightsOut,
    floatWeightsOut,
    referenceTransforms,
    referenceFloats,
    bonesScratch0,
    bonesScratch1,
    floatsScratch0,
    floatsScratch1,
    frameDelta,
    1,
    0.001);
  v39 = transformTracksOut;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0i64;
  if ( (signed int)v13 < 4 )
  {
LABEL_48:
    if ( v41 < v13 )
    {
      v50 = &boneWeightsOut[v43];
      v51 = &bonesOut[v43].m_scale;
      do
      {
        if ( v42 >= v15 )
          break;
        if ( *v50 > 0.0 )
        {
          v52 = v39;
          ++v39;
          v52->m_translation = (hkVector4f)v51[-2].m_quad;
          ++v42;
          v52->m_rotation.m_vec = (hkVector4f)v51[-1].m_quad;
          v52->m_scale = (hkVector4f)v51->m_quad;
        }
        ++v41;
        ++v50;
        v51 += 3;
      }
      while ( v41 < v13 );
    }
  }
  else
  {
    v44 = boneWeightsOut + 2;
    v45 = &bonesOut[1].m_scale;
    while ( v42 < v15 )
    {
      if ( *(v44 - 2) > 0.0 )
      {
        v46 = v39;
        ++v39;
        v46->m_translation = (hkVector4f)v45[-5].m_quad;
        ++v42;
        v46->m_rotation.m_vec = (hkVector4f)v45[-4].m_quad;
        v46->m_scale = (hkVector4f)v45[-3].m_quad;
      }
      if ( v42 >= v15 )
        break;
      if ( *(v44 - 1) > 0.0 )
      {
        v47 = v39;
        ++v39;
        v47->m_translation = (hkVector4f)v45[-2].m_quad;
        ++v42;
        v47->m_rotation.m_vec = (hkVector4f)v45[-1].m_quad;
        v47->m_scale = (hkVector4f)v45->m_quad;
      }
      if ( v42 >= v15 )
        break;
      if ( *v44 > 0.0 )
      {
        v48 = v39;
        ++v39;
        v48->m_translation = (hkVector4f)v45[1].m_quad;
        ++v42;
        v48->m_rotation.m_vec = (hkVector4f)v45[2].m_quad;
        v48->m_scale = (hkVector4f)v45[3].m_quad;
      }
      if ( v42 >= v15 )
        break;
      if ( v44[1] > 0.0 )
      {
        v49 = v39;
        ++v39;
        v49->m_translation = (hkVector4f)v45[4].m_quad;
        ++v42;
        v49->m_rotation.m_vec = (hkVector4f)v45[5].m_quad;
        v49->m_scale = (hkVector4f)v45[6].m_quad;
      }
      v41 += 4;
      v43 += 4i64;
      v44 += 4;
      v45 += 12;
      if ( v41 >= v13 - 3 )
        goto LABEL_48;
    }
  }
  v53 = floatTracksOut;
  v54 = 0;
  v55 = 0i64;
  if ( (signed int)numFloats < 4 )
  {
LABEL_69:
    if ( v40 < numFloats )
    {
      v58 = &v79[v55];
      do
      {
        if ( v54 >= v14 )
          break;
        if ( *(float *)((char *)v58 + p - (_BYTE *)v79) > 0.0 )
        {
          ++v53;
          ++v54;
          *(v53 - 1) = *v58;
        }
        ++v40;
        ++v58;
      }
      while ( v40 < numFloats );
    }
  }
  else
  {
    v56 = v79 + 1;
    v57 = p - (_BYTE *)v79;
    while ( v54 < v14 )
    {
      if ( *(float *)((char *)v56 + v57 - 4) > 0.0 )
      {
        ++v53;
        ++v54;
        *(v53 - 1) = *(v56 - 1);
      }
      if ( v54 >= v14 )
        break;
      if ( *(float *)((char *)v56 + v57) > 0.0 )
      {
        ++v53;
        ++v54;
        *(v53 - 1) = *v56;
      }
      if ( v54 >= v14 )
        break;
      if ( *(float *)((char *)v56 + v57 + 4) > 0.0 )
      {
        ++v53;
        ++v54;
        *(v53 - 1) = v56[1];
      }
      if ( v54 >= v14 )
        break;
      if ( *(float *)((char *)v56 + v57 + 8) > 0.0 )
      {
        ++v53;
        ++v54;
        *(v53 - 1) = v56[2];
      }
      v40 += 4;
      v55 += 4i64;
      v56 += 4;
      if ( v40 >= numFloats - 3 )
        goto LABEL_69;
    }
  }
  v59 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v60 = (v30 + 15) & 0xFFFFFFF0;
  if ( v30 > v59->m_slabSize || &p[v60] != v59->m_cur || v59->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v59, p, v60);
  else
    v59->m_cur = p;
  v61 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v30 > v61->m_slabSize || (char *)floatsScratch1 + v60 != v61->m_cur || v61->m_firstNonLifoEnd == floatsScratch1 )
    hkLifoAllocator::slowBlockFree(v61, floatsScratch1, v60);
  else
    v61->m_cur = floatsScratch1;
  v62 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v30 > v62->m_slabSize || (char *)floatsScratch0 + v60 != v62->m_cur || v62->m_firstNonLifoEnd == floatsScratch0 )
    hkLifoAllocator::slowBlockFree(v62, floatsScratch0, v60);
  else
    v62->m_cur = floatsScratch0;
  v63 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v30 > v63->m_slabSize || (char *)v79 + v60 != v63->m_cur || v63->m_firstNonLifoEnd == v79 )
    hkLifoAllocator::slowBlockFree(v63, v79, v60);
  else
    v63->m_cur = v79;
  v64 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v65 = (v78 + 15) & 0xFFFFFFF0;
  if ( v78 > v64->m_slabSize || (char *)boneWeightsOut + v65 != v64->m_cur || v64->m_firstNonLifoEnd == boneWeightsOut )
    hkLifoAllocator::slowBlockFree(v64, boneWeightsOut, v65);
  else
    v64->m_cur = boneWeightsOut;
  v66 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v67 = (dataChunksa + 15) & 0xFFFFFFF0;
  if ( dataChunksa > v66->m_slabSize
    || (char *)bonesScratch1 + v67 != v66->m_cur
    || v66->m_firstNonLifoEnd == bonesScratch1 )
  {
    hkLifoAllocator::slowBlockFree(v66, bonesScratch1, v67);
  }
  else
  {
    v66->m_cur = bonesScratch1;
  }
  v68 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( dataChunksa > v68->m_slabSize
    || (char *)bonesScratch0 + v67 != v68->m_cur
    || v68->m_firstNonLifoEnd == bonesScratch0 )
  {
    hkLifoAllocator::slowBlockFree(v68, bonesScratch0, v67);
  }
  else
  {
    v68->m_cur = bonesScratch0;
  }
  v69 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( dataChunksa > v69->m_slabSize || (char *)bonesOut + v67 != v69->m_cur || v69->m_firstNonLifoEnd == bonesOut )
    hkLifoAllocator::slowBlockFree(v69, bonesOut, v67);
  else
    v69->m_cur = bonesOut;
}>m_firstNonLifoEnd == bonesOut )
    hkLifoAllocator::slowBlockFree(v69, bonesOut, v67);
  else
    v69->m_cur = bonesOut;
}

// File Line: 694
// RVA: 0xB2EAA0
char __fastcall hkaQuantizedAnimation::requiresSkeleton(hkaQuantizedAnimation *this)
{
  return 1;
}

// File Line: 699
// RVA: 0xB2EAB0
hkaSkeleton *__fastcall hkaQuantizedAnimation::getSkeleton(hkaQuantizedAnimation *this)
{
  return this->m_skeleton;
}

// File Line: 704
// RVA: 0xB2EAC0
void __fastcall hkaQuantizedAnimation::setSkeleton(hkaQuantizedAnimation *this, hkaSkeleton *skeleton)
{
  this->m_skeleton = skeleton;
}

