// File Line: 23
// RVA: 0xB2D690
void __fastcall hkaQuantizedAnimation::sampleIndividualTransformTracks(
        hkaQuantizedAnimation *this,
        float time,
        const __int16 *tracks,
        unsigned int numTracks)
{
  ;
}

// File Line: 28
// RVA: 0xB2D6A0
void __fastcall hkaQuantizedAnimation::sampleIndividualFloatTracks(
        hkaQuantizedAnimation *this,
        float time,
        const __int16 *tracks,
        unsigned int numTracks)
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
void __fastcall hkaQuantizedAnimation::sampleStaticScalars(
        float *poseOut,
        int numPoseOut,
        unsigned __int16 *elements,
        const float *values,
        int n)
{
  unsigned __int16 v5; // r11
  int v6; // ebx
  __int64 i; // r10
  float v8; // eax

  if ( n > 0 )
  {
    v5 = *elements;
    v6 = 0;
    for ( i = 0i64; i < n - 1; v5 = elements[i] )
    {
      if ( v5 >= numPoseOut )
        break;
      v8 = values[i++];
      ++v6;
      poseOut[v5] = v8;
    }
    if ( v5 < numPoseOut )
      poseOut[v5] = values[v6];
  }
}

// File Line: 68
// RVA: 0xB2EB50
// attributes: thunk
void __fastcall hkaQuantizedAnimation::sampleDynamicScalars(
        float *poseOut,
        int numPoseOut,
        const unsigned __int16 *elements,
        const float *minimums,
        const float *spans,
        const unsigned __int16 *values,
        int n)
{
  hkaCompression::sampleDynamicScalarsInternal(poseOut, numPoseOut, elements, minimums, spans, values, n);
}

// File Line: 76
// RVA: 0xB2EB60
void __fastcall hkaQuantizedAnimation::sampleRotations(
        hkQuaternionf *poseOut,
        int numPoseOut,
        const unsigned __int16 *elements,
        const unsigned __int16 *values,
        int n)
{
  int v6; // edx
  const unsigned __int16 *v7; // r12
  int v9; // ebp
  int v10; // r14d
  signed int v11; // eax
  unsigned __int16 v12; // cx
  const unsigned __int16 *v13; // r12
  int v14; // ebx
  int v15; // edi
  int v16; // esi
  __int64 v17; // rbx
  __int64 i; // rsi
  int j; // edi
  int v20; // ecx
  unsigned __int16 v21; // [rsp+30h] [rbp-98h]
  __int64 v22; // [rsp+38h] [rbp-90h]
  hkVector4f dst0; // [rsp+40h] [rbp-88h] BYREF
  __int64 v24; // [rsp+50h] [rbp-78h]
  hkVector4f dst1; // [rsp+60h] [rbp-68h] BYREF
  hkVector4f dst2; // [rsp+70h] [rbp-58h] BYREF
  hkVector4f dst3; // [rsp+80h] [rbp-48h] BYREF
  const unsigned __int16 *v29; // [rsp+E8h] [rbp+20h]

  v29 = values;
  v6 = n;
  v7 = elements;
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
      if ( v11 > 0 )
      {
        v13 = elements + 2;
        do
        {
          if ( v12 >= numPoseOut )
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
          poseOut[v14].m_vec = (hkVector4f)dst0.m_quad;
          poseOut[v15].m_vec = (hkVector4f)dst1.m_quad;
          poseOut[v16].m_vec = (hkVector4f)dst2.m_quad;
          poseOut[v21].m_vec = (hkVector4f)dst3.m_quad;
          v12 = v13[1];
          v21 = v12;
        }
        while ( v22 < v24 );
        v7 = elements;
        v6 = n;
      }
    }
    v17 = v9;
    for ( i = v6; v17 < i; v10 += 12 )
    {
      for ( j = 0; j < 12; j += 3 )
      {
        if ( v17 >= i )
          break;
        v20 = v7[v17];
        if ( v20 >= numPoseOut )
          return;
        hkaSignedQuaternion::unpackSignedQuaternion48(
          (const char *)&values[v10 + (__int64)j],
          &poseOut[(unsigned __int16)v20]);
        values = v29;
        ++v9;
        ++v17;
      }
      values = v29;
    }
  }
}

// File Line: 154
// RVA: 0xB2CB30
void __fastcall hkaQuantizedAnimation::sampleFullPose(
        hkaQuantizedAnimation *this,
        hkQsTransformf *bonesOut,
        float *floatsOut,
        float *boneWeightsOut,
        float *floatWeightsOut,
        float time,
        bool useSlerp,
        float frameSteppingTolerance)
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
void __fastcall hkaQuantizedAnimation::sampleFullPose(
        hkaQuantizedAnimation *this,
        int numBones,
        int numFloats,
        hkQsTransformf *bonesOut,
        float *floatsOut,
        float *boneWeightsOut,
        float *floatWeightsOut,
        float time,
        bool useSlerp,
        float frameSteppingTolerance)
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
void __fastcall hkaQuantizedAnimation::sampleFullPose(
        hkaQuantizedAnimation *this,
        int numBones,
        int numFloats,
        hkQsTransformf *bonesOut,
        float *floatsOut,
        float *boneWeightsOut,
        float *floatWeightsOut,
        hkQsTransformf *bonesScratch0,
        hkQsTransformf *bonesScratch1,
        float *floatsScratch0,
        float *floatsScratch1,
        float time,
        bool useSlerp,
        float frameSteppingTolerance)
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
void __fastcall hkaQuantizedAnimation::sampleFullPose(
        const char *headerData,
        int numBones,
        int numFloats,
        hkQsTransformf *bonesOut,
        float *floatsOut,
        float *boneWeightsOut,
        float *floatWeightsOut,
        hkQsTransformf *referencePose,
        const float *referenceFloats,
        float time,
        bool useSlerp,
        float frameSteppingTolerance)
{
  float *floatsScratch1; // r14
  unsigned int v14; // edx
  int v15; // edi
  unsigned int v16; // edx
  hkQsTransformf *bonesScratch1; // r13
  int v18; // esi
  unsigned int v19; // eax
  float *floatsScratch0; // r12
  int v21; // ebx
  unsigned int v22; // eax
  int v23; // ebp
  int v24; // [rsp+80h] [rbp-68h] BYREF
  int v25; // [rsp+84h] [rbp-64h] BYREF
  int v26; // [rsp+88h] [rbp-60h] BYREF
  hkQsTransformf *bonesScratch0; // [rsp+90h] [rbp-58h]
  int v28; // [rsp+F0h] [rbp+8h] BYREF
  int numBonesa; // [rsp+F8h] [rbp+10h]
  int numFloatsa; // [rsp+100h] [rbp+18h]
  hkQsTransformf *bonesOuta; // [rsp+108h] [rbp+20h]

  bonesOuta = bonesOut;
  numFloatsa = numFloats;
  numBonesa = numBones;
  floatsScratch1 = 0i64;
  v14 = (*((unsigned __int16 *)headerData + 1) + 3) & 0xFFFFFFFC;
  if ( v14 )
  {
    v28 = 48 * v14;
    bonesScratch0 = (hkQsTransformf *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                        &hkContainerTempAllocator::s_alloc,
                                        &v28);
    v14 = v28 / 48;
  }
  else
  {
    bonesScratch0 = 0i64;
  }
  v15 = 0x80000000;
  if ( v14 )
    v15 = v14;
  v16 = (*((unsigned __int16 *)headerData + 1) + 3) & 0xFFFFFFFC;
  if ( v16 )
  {
    v24 = 48 * v16;
    bonesScratch1 = (hkQsTransformf *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                        &hkContainerTempAllocator::s_alloc,
                                        &v24);
    v16 = v24 / 48;
  }
  else
  {
    bonesScratch1 = 0i64;
  }
  v18 = 0x80000000;
  if ( v16 )
    v18 = v16;
  v19 = (*((unsigned __int16 *)headerData + 2) + 3) & 0xFFFFFFFC;
  if ( v19 )
  {
    v25 = 4 * v19;
    floatsScratch0 = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerTempAllocator::s_alloc,
                                &v25);
    v19 = v25 / 4;
  }
  else
  {
    floatsScratch0 = 0i64;
  }
  v21 = 0x80000000;
  if ( v19 )
    v21 = v19;
  v22 = (*((unsigned __int16 *)headerData + 2) + 3) & 0xFFFFFFFC;
  if ( v22 )
  {
    v26 = 4 * v22;
    floatsScratch1 = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerTempAllocator::s_alloc,
                                &v26);
    v22 = v26 / 4;
  }
  v23 = 0x80000000;
  if ( v22 )
    v23 = v22;
  hkaQuantizedAnimation::sampleFullPose(
    headerData,
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
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, floatsScratch1, 4 * v23);
  if ( v21 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, floatsScratch0, 4 * v21);
  if ( v18 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      bonesScratch1,
      48 * (v18 & 0x3FFFFFFF));
  if ( v15 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      bonesScratch0,
      48 * (v15 & 0x3FFFFFFF));
}

// File Line: 187
// RVA: 0xB2D9B0
void __fastcall hkaQuantizedAnimation::sampleFullPose(
        const char *headerData,
        int numBones,
        int numFloats,
        hkQsTransformf *bonesOut,
        float *floatsOut,
        float *boneWeightsOut,
        float *floatWeightsOut,
        hkQsTransformf *referencePose,
        const float *referenceFloats,
        hkQsTransformf *bonesScratch0,
        hkQsTransformf *bonesScratch1,
        float *floatsScratch0,
        float *floatsScratch1,
        float time,
        bool useSlerp,
        float frameSteppingTolerance)
{
  __m128 v16; // xmm1
  unsigned int v19; // r9d
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  int v24; // ecx
  float delta; // xmm4_4
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm1

  v16 = _mm_shuffle_ps((__m128)*((unsigned int *)headerData + 2), (__m128)*((unsigned int *)headerData + 2), 0);
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
    v28 = _mm_cmplt_ps(v27, query.m_quad);
    delta = fmax(0.0, COERCE_FLOAT(v27.m128_i32[0] & v28.m128_i32[0] | _mm_andnot_ps(v28, query.m_quad).m128_u32[0]));
  }
  else
  {
    delta = *(float *)&FLOAT_1_0;
  }
  hkaQuantizedAnimation::sampleFullPose(
    headerData,
    &headerData[*(unsigned __int16 *)headerData + v19 * *((unsigned __int16 *)headerData + 14)],
    &headerData[*(unsigned __int16 *)headerData + *((unsigned __int16 *)headerData + 14) * (v19 + 1)],
    numBones,
    numFloats,
    bonesOut,
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
void __fastcall hkaQuantizedAnimation::sampleFullPose(
        char *headerData,
        const char *frameData0,
        const char *frameData1,
        int numBones,
        int numFloats,
        hkQsTransformf *bonesOut,
        float *floatsOut,
        float *boneWeightsOut,
        float *floatWeightsOut,
        hkQsTransformf *referencePose,
        const float *referenceFloats,
        hkQsTransformf *bonesScratch0,
        hkQsTransformf *bonesScratch1,
        float *floatsScratch0,
        float *floatsScratch1,
        float delta,
        bool useSlerp,
        float frameSteppingTolerance)
{
  int v18; // esi
  _QWORD *Value; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r9
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  hkQsTransformf *v27; // r12
  hkQsTransformf *v28; // r13
  hkQsTransformf *v29; // rcx
  float *v30; // r14
  int v31; // r15d
  float v32; // xmm7_4
  hkQsTransformf *v33; // rbx
  int v34; // eax
  int v35; // ebp
  float *v36; // rcx
  hkQuaternionf *v37; // r15
  int v38; // r12d
  int v39; // r13d
  __int64 n; // rdi
  __int64 v41; // rsi
  int v42; // ebx
  int v43; // ebx
  unsigned __int16 *v44; // rsi
  __int64 v45; // r15
  __int64 v46; // r14
  __int64 v47; // rbp
  const unsigned __int16 *v48; // rsi
  int v49; // ebx
  __int64 v50; // rdx
  int v51; // eax
  int v52; // edi
  const char *v53; // r10
  int v54; // r9d
  const char *v55; // rcx
  float *v56; // rdx
  unsigned int v57; // eax
  __int64 v58; // r8
  __m128i v59; // xmm2
  __m128 v60; // xmm2
  __int128 *v61; // rcx
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  float *v64; // r8
  __int128 *v65; // rdx
  __int64 v66; // r9
  __m128 v67; // xmm0
  __m128 v68; // xmm0
  __m128 v69; // xmm1
  const char *v70; // r10
  const char *v71; // rdx
  float *v72; // r8
  unsigned int v73; // eax
  __int64 v74; // r9
  __m128i v75; // xmm2
  __m128 v76; // xmm2
  __m128 v77; // xmm0
  __m128 v78; // xmm2
  float *v79; // rax
  __int64 v80; // rdx
  __m128 v81; // xmm0
  __m128 v82; // xmm1
  _QWORD *v83; // rax
  _QWORD *v84; // rcx
  _QWORD *v85; // r8
  unsigned __int64 v86; // rax
  _QWORD *v87; // rcx
  hkQuaternionf *v88; // [rsp+40h] [rbp-98h]
  float *v89; // [rsp+48h] [rbp-90h]
  unsigned __int16 *values[2]; // [rsp+50h] [rbp-88h] BYREF
  int v92; // [rsp+E8h] [rbp+10h]
  float *poseOut; // [rsp+F0h] [rbp+18h]
  int frameSteppingTolerancea; // [rsp+168h] [rbp+90h]

  v18 = numBones;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)Value[1];
  v23 = Value;
  if ( (unsigned __int64)v22 < Value[3] )
  {
    *v22 = "TtQuantizedSampleFullPose";
    v24 = __rdtsc();
    v25 = v22 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v23[1] = v25;
  }
  v27 = bonesScratch1;
  v28 = bonesScratch0;
  v29 = referencePose;
  v30 = floatsOut;
  v31 = 0;
  values[1] = (unsigned __int16 *)frameData1;
  v32 = 1.0 - frameSteppingTolerance;
  v33 = bonesOut;
  v34 = 0;
  v92 = 0;
  values[0] = (unsigned __int16 *)frameData0;
  do
  {
    if ( v34 )
    {
      if ( delta > frameSteppingTolerance )
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
      if ( delta <= frameSteppingTolerance )
      {
        v35 = numFloats;
        hkaSampleAndCombineUtils::copyReferencePose(v33, v30, v29, v18, referenceFloats, numFloats);
        frameSteppingTolerancea = 0;
        v36 = (float *)v33;
        v37 = (hkQuaternionf *)v33;
LABEL_14:
        v38 = 3 * v18;
        v39 = 3 * v18;
        n = *((unsigned __int16 *)headerData + 15);
        v41 = *((unsigned __int16 *)headerData + 17);
        v42 = *((unsigned __int16 *)headerData + 6) + *((unsigned __int16 *)headerData + 8);
        v38 *= 4;
        v89 = v30;
        v88 = v37;
        poseOut = v36;
        hkaQuantizedAnimation::sampleStaticScalars(
          v36,
          v38,
          (const unsigned __int16 *)&headerData[n],
          (const float *)&headerData[v41],
          v42);
        LODWORD(n) = n + 2 * v42;
        v43 = v41 + 4 * v42;
        v44 = (unsigned __int16 *)headerData;
        hkaQuantizedAnimation::sampleRotations(
          v37,
          v39,
          (const unsigned __int16 *)&headerData[(int)n],
          (const unsigned __int16 *)&headerData[v43],
          *((unsigned __int16 *)headerData + 7));
        hkaQuantizedAnimation::sampleStaticScalars(
          v30,
          v35,
          (unsigned __int16 *)((char *)v44 + (int)(n + 2 * v44[7])),
          (const float *)((char *)v44 + ((v43 + 6 * v44[7] + 15) & 0xFFFFFFFFFFFFFFF0ui64)),
          v44[9]);
        v45 = *((unsigned __int16 *)headerData + 16);
        v46 = *((unsigned __int16 *)headerData + 18);
        v47 = *((unsigned __int16 *)headerData + 19);
        LODWORD(n) = v44[10] + v44[12];
        v48 = values[frameSteppingTolerancea];
        hkaQuantizedAnimation::sampleDynamicScalars(
          poseOut,
          v38,
          (const unsigned __int16 *)&headerData[v45],
          (const float *)&headerData[v46],
          (const float *)&headerData[v47],
          v48,
          n);
        v49 = n;
        LODWORD(v45) = 2 * n + v45;
        LODWORD(n) = 4 * n;
        hkaQuantizedAnimation::sampleRotations(
          v88,
          v39,
          (const unsigned __int16 *)&headerData[(int)v45],
          &v48[v49],
          *((unsigned __int16 *)headerData + 11));
        v50 = (int)n + (int)v47 + 15;
        v51 = n + v46 + 15;
        v52 = numFloats;
        hkaQuantizedAnimation::sampleDynamicScalars(
          v89,
          numFloats,
          (const unsigned __int16 *)&headerData[2 * *((unsigned __int16 *)headerData + 11) + (int)v45],
          (const float *)&headerData[v51 & 0xFFFFFFFFFFFFFFF0ui64],
          (const float *)&headerData[v50 & 0xFFFFFFFFFFFFFFF0ui64],
          &v48[2 * *((unsigned __int16 *)headerData + 11) + *((unsigned __int16 *)headerData + 11) + v49],
          *((unsigned __int16 *)headerData + 13));
        v33 = bonesOut;
        v18 = numBones;
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
    v52 = numFloats;
LABEL_16:
    v92 = ++v34;
  }
  while ( v34 < 2 );
  if ( delta > frameSteppingTolerance && delta < v32 )
  {
    *(__m128 *)values = _mm_shuffle_ps((__m128)LODWORD(delta), (__m128)LODWORD(delta), 0);
    hkaBlender::blend(v33, v28, v27, (hkSimdFloat32 *)values, v18, NORMAL, (hkaBlender::ROTATION_MODE)useSlerp);
    hkaBlender::blend(v30, floatsScratch0, floatsScratch1, (hkSimdFloat32 *)values, v52, NORMAL);
  }
  v53 = headerData + 40;
  v54 = 0;
  if ( v18 - 4 > 0 )
  {
    v55 = headerData + 40;
    v56 = boneWeightsOut;
    v57 = ((unsigned int)(v18 - 5) >> 2) + 1;
    v58 = v57;
    v54 = 4 * v57;
    do
    {
      v56 += 4;
      v59 = _mm_unpacklo_epi8((__m128i)*(unsigned int *)v55, (__m128i)0i64);
      v55 += 4;
      v60 = (__m128)_mm_cmpeq_epi32(_mm_unpacklo_epi16(v59, (__m128i)0i64), (__m128i)0i64);
      *((__m128 *)v56 - 1) = _mm_or_ps(_mm_andnot_ps(v60, query.m_quad), _mm_and_ps((__m128)0i64, v60));
      --v58;
    }
    while ( v58 );
  }
  v61 = &`hkVector4f::getComponent::`2::indexToMask;
  v62 = (__m128)_mm_cmpeq_epi32(
                  _mm_unpacklo_epi16(
                    _mm_unpacklo_epi8((__m128i)*(unsigned int *)&v53[v54], (__m128i)0i64),
                    (__m128i)0i64),
                  (__m128i)0i64);
  v63 = _mm_or_ps(_mm_andnot_ps(v62, query.m_quad), _mm_and_ps((__m128)0i64, v62));
  if ( v54 < v18 )
  {
    v64 = &boneWeightsOut[v54];
    v65 = &`hkVector4f::getComponent::`2::indexToMask;
    v66 = (unsigned int)(v18 - v54);
    do
    {
      v67 = (__m128)*v65;
      ++v64;
      ++v65;
      v68 = _mm_and_ps(v67, v63);
      v69 = _mm_or_ps(_mm_shuffle_ps(v68, v68, 78), v68);
      *((_DWORD *)v64 - 1) = _mm_shuffle_ps(v69, v69, 177).m128_u32[0] | v69.m128_i32[0];
      --v66;
    }
    while ( v66 );
  }
  v70 = &v53[v18];
  if ( v52 - 4 > 0 )
  {
    v71 = v70;
    v72 = floatWeightsOut;
    v73 = ((unsigned int)(v52 - 5) >> 2) + 1;
    v74 = v73;
    v31 = 4 * v73;
    do
    {
      v72 += 4;
      v75 = _mm_unpacklo_epi8((__m128i)*(unsigned int *)v71, (__m128i)0i64);
      v71 += 4;
      v76 = (__m128)_mm_cmpeq_epi32(_mm_unpacklo_epi16(v75, (__m128i)0i64), (__m128i)0i64);
      *((__m128 *)v72 - 1) = _mm_or_ps(_mm_andnot_ps(v76, query.m_quad), _mm_and_ps((__m128)0i64, v76));
      --v74;
    }
    while ( v74 );
  }
  v77 = (__m128)_mm_cmpeq_epi32(
                  _mm_unpacklo_epi16(
                    _mm_unpacklo_epi8((__m128i)*(unsigned int *)&v70[v31], (__m128i)0i64),
                    (__m128i)0i64),
                  (__m128i)0i64);
  v78 = _mm_or_ps(_mm_andnot_ps(v77, query.m_quad), _mm_and_ps((__m128)0i64, v77));
  if ( v31 < v52 )
  {
    v79 = &floatWeightsOut[v31];
    v80 = (unsigned int)(v52 - v31);
    do
    {
      ++v79;
      v81 = _mm_and_ps(v78, *((__m128 *)++v61 - 1));
      v82 = _mm_or_ps(_mm_shuffle_ps(v81, v81, 78), v81);
      *((_DWORD *)v79 - 1) = _mm_shuffle_ps(v82, v82, 177).m128_u32[0] | v82.m128_i32[0];
      --v80;
    }
    while ( v80 );
  }
  v83 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v84 = (_QWORD *)v83[1];
  v85 = v83;
  if ( (unsigned __int64)v84 < v83[3] )
  {
    *v84 = "Et";
    v86 = __rdtsc();
    v87 = v84 + 2;
    *((_DWORD *)v87 - 2) = v86;
    v85[1] = v87;
  }
}

// File Line: 502
// RVA: 0xB2CD00
void __fastcall hkaQuantizedAnimation::sampleTracks(
        hkaQuantizedAnimation *this,
        float time,
        hkQsTransformf *transformTracksOut,
        float *floatTracksOut)
{
  char *m_data; // rax
  unsigned int v5; // r12d
  int v6; // r15d
  unsigned int v8; // esi
  unsigned int v9; // ebp
  int v12; // edx
  unsigned int v13; // eax
  int v14; // r13d
  int v15; // eax
  int v16; // esi
  float *floatWeightsOut; // rcx
  unsigned int v18; // eax
  int v19; // ebp
  float *v20; // r14
  hkQsTransformf *v21; // r11
  unsigned int v22; // r9d
  __int64 v23; // r10
  float *v24; // rdx
  hkVector4f *p_m_scale; // rcx
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
  __int64 v38; // r9
  float *v39; // rcx
  signed __int64 v40; // rdx
  unsigned int v41; // eax
  __int64 v42; // r8
  float *v43; // rcx
  int v44; // [rsp+50h] [rbp-78h] BYREF
  int v45; // [rsp+54h] [rbp-74h] BYREF
  int v46; // [rsp+58h] [rbp-70h] BYREF
  hkQsTransformf *bonesOut; // [rsp+60h] [rbp-68h]
  float *floatsOut; // [rsp+68h] [rbp-60h]
  float *boneWeightsOut; // [rsp+70h] [rbp-58h]
  int v50; // [rsp+78h] [rbp-50h]
  int numFloats; // [rsp+7Ch] [rbp-4Ch]
  int v52; // [rsp+80h] [rbp-48h]
  float *v53; // [rsp+88h] [rbp-40h]
  int v54; // [rsp+D0h] [rbp+8h] BYREF

  m_data = this->m_data.m_data;
  v5 = 0;
  v6 = *((unsigned __int16 *)m_data + 1);
  numFloats = *((unsigned __int16 *)m_data + 2);
  v8 = (v6 + 3) & 0xFFFFFFFC;
  v9 = (numFloats + 3) & 0xFFFFFFFC;
  v12 = v8;
  if ( v8 )
  {
    v54 = 48 * v8;
    bonesOut = (hkQsTransformf *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                   &hkContainerTempAllocator::s_alloc,
                                   &v54);
    v12 = v54 / 48;
  }
  else
  {
    bonesOut = 0i64;
  }
  v13 = 0x80000000;
  if ( v12 )
    v13 = v12;
  v52 = v13;
  if ( v8 )
  {
    v45 = 4 * v8;
    boneWeightsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerTempAllocator::s_alloc,
                                &v45);
    v8 = v45 / 4;
  }
  else
  {
    boneWeightsOut = 0i64;
  }
  v14 = 0x80000000;
  v15 = v9;
  if ( v8 )
    v14 = v8;
  if ( v9 )
  {
    v46 = 4 * v9;
    floatsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v46);
    v15 = v46 / 4;
  }
  else
  {
    floatsOut = 0i64;
  }
  v16 = 0x80000000;
  if ( v15 )
    v16 = v15;
  if ( v9 )
  {
    v44 = 4 * v9;
    floatWeightsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                 &hkContainerTempAllocator::s_alloc,
                                 &v44);
    v9 = v44 / 4;
  }
  else
  {
    floatWeightsOut = 0i64;
  }
  v18 = 0x80000000;
  if ( v9 )
    v18 = v9;
  v19 = numFloats;
  v50 = v18;
  v53 = floatWeightsOut;
  hkaQuantizedAnimation::sampleFullPose(
    this,
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
    p_m_scale = &bonesOut[1].m_scale;
    v26 = ((unsigned int)(v6 - 4) >> 2) + 1;
    v27 = v26;
    v22 = 4 * v26;
    v23 = 4i64 * v26;
    do
    {
      if ( *(v24 - 2) > 0.0 )
      {
        v28 = transformTracksOut++;
        v28->m_translation = (hkVector4f)p_m_scale[-5].m_quad;
        v28->m_rotation.m_vec = (hkVector4f)p_m_scale[-4].m_quad;
        v28->m_scale = (hkVector4f)p_m_scale[-3].m_quad;
      }
      if ( *(v24 - 1) > 0.0 )
      {
        v29 = transformTracksOut++;
        v29->m_translation = (hkVector4f)p_m_scale[-2].m_quad;
        v29->m_rotation.m_vec = (hkVector4f)p_m_scale[-1].m_quad;
        v29->m_scale = (hkVector4f)p_m_scale->m_quad;
      }
      if ( *v24 > 0.0 )
      {
        v30 = transformTracksOut++;
        v30->m_translation = (hkVector4f)p_m_scale[1].m_quad;
        v30->m_rotation.m_vec = (hkVector4f)p_m_scale[2].m_quad;
        v30->m_scale = (hkVector4f)p_m_scale[3].m_quad;
      }
      if ( v24[1] > 0.0 )
      {
        v31 = transformTracksOut++;
        v31->m_translation = (hkVector4f)p_m_scale[4].m_quad;
        v31->m_rotation.m_vec = (hkVector4f)p_m_scale[5].m_quad;
        v31->m_scale = (hkVector4f)p_m_scale[6].m_quad;
      }
      v24 += 4;
      p_m_scale += 12;
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
        v35 = transformTracksOut++;
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
        *floatTracksOut++ = *(v39 - 1);
      if ( *(float *)((char *)v39 + v40) > 0.0 )
        *floatTracksOut++ = *v39;
      if ( *(float *)((char *)v39 + v40 + 4) > 0.0 )
        *floatTracksOut++ = v39[1];
      if ( *(float *)((char *)v39 + v40 + 8) > 0.0 )
        *floatTracksOut++ = v39[2];
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
        *floatTracksOut++ = *v43;
      ++v43;
      --v38;
    }
    while ( v38 );
  }
  if ( v50 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v37,
      (unsigned int)(4 * v50),
      v38);
  if ( v16 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, float *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v36,
      (unsigned int)(4 * v16),
      v38);
  if ( v14 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, float *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v20,
      (unsigned int)(4 * v14),
      v38);
  if ( v52 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkQsTransformf *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      bonesOut,
      48 * (v52 & 0x3FFFFFFFu),
      v38);
}

// File Line: 547
// RVA: 0xB2D1A0
void __fastcall hkaQuantizedAnimation::samplePartialTracks(
        hkaQuantizedAnimation *this,
        float time,
        unsigned int maxNumTransformTracks,
        hkQsTransformf *transformTracksOut,
        unsigned int maxNumFloatTracks,
        float *floatTracksOut)
{
  char *m_data; // rax
  unsigned int v7; // r14d
  int v8; // r13d
  int v9; // r12d
  unsigned int v12; // edi
  unsigned int v13; // esi
  int v15; // edx
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  int v19; // edi
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
  hkVector4f *p_m_scale; // rdx
  hkQsTransformf *v36; // rax
  unsigned int v37; // r10d
  __int64 v38; // rbx
  float *v39; // rdx
  unsigned int v40; // ecx
  __int64 v41; // r11
  float *v42; // r8
  int v43; // [rsp+50h] [rbp-78h] BYREF
  int v44; // [rsp+54h] [rbp-74h] BYREF
  hkQsTransformf *bonesOut; // [rsp+58h] [rbp-70h]
  int v46; // [rsp+60h] [rbp-68h] BYREF
  float *boneWeightsOut; // [rsp+68h] [rbp-60h]
  int v48; // [rsp+70h] [rbp-58h]
  int v49; // [rsp+74h] [rbp-54h]
  float *v50; // [rsp+78h] [rbp-50h]
  int v51; // [rsp+80h] [rbp-48h]
  float *floatsOut; // [rsp+88h] [rbp-40h]
  int v53; // [rsp+D0h] [rbp+8h] BYREF

  m_data = this->m_data.m_data;
  v7 = 0;
  v8 = *((unsigned __int16 *)m_data + 1);
  v9 = *((unsigned __int16 *)m_data + 2);
  v12 = (v8 + 3) & 0xFFFFFFFC;
  v13 = (v9 + 3) & 0xFFFFFFFC;
  v15 = v12;
  if ( v12 )
  {
    v53 = 48 * v12;
    bonesOut = (hkQsTransformf *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                   &hkContainerTempAllocator::s_alloc,
                                   &v53);
    v15 = v53 / 48;
  }
  else
  {
    bonesOut = 0i64;
  }
  v16 = 0x80000000;
  if ( v15 )
    v16 = v15;
  v49 = v16;
  if ( v12 )
  {
    v46 = 4 * v12;
    boneWeightsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerTempAllocator::s_alloc,
                                &v46);
    v12 = v46 / 4;
  }
  else
  {
    boneWeightsOut = 0i64;
  }
  v17 = 0x80000000;
  if ( v12 )
    v17 = v12;
  v48 = v17;
  v18 = (v9 + 3) & 0xFFFFFFFC;
  if ( v13 )
  {
    v44 = 4 * v13;
    floatsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v44);
    v18 = v44 / 4;
  }
  else
  {
    floatsOut = 0i64;
  }
  v19 = 0x80000000;
  if ( v18 )
    v19 = v18;
  if ( v13 )
  {
    v43 = 4 * v13;
    floatWeightsOut = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                 &hkContainerTempAllocator::s_alloc,
                                 &v43);
    v13 = v43 / 4;
  }
  else
  {
    floatWeightsOut = 0i64;
  }
  v21 = 0x80000000;
  if ( v13 )
    v21 = v13;
  v22 = floatsOut;
  v51 = v21;
  v50 = floatWeightsOut;
  hkaQuantizedAnimation::sampleFullPose(
    this,
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
  if ( v8 < 4 )
  {
LABEL_36:
    if ( (unsigned int)v25 < v8 )
    {
      v34 = &v23[v27];
      p_m_scale = &v24[v27].m_scale;
      do
      {
        if ( v26 >= maxNumTransformTracks )
          break;
        if ( *v34 > 0.0 )
        {
          v36 = transformTracksOut++;
          v36->m_translation = (hkVector4f)p_m_scale[-2].m_quad;
          ++v26;
          v36->m_rotation.m_vec = (hkVector4f)p_m_scale[-1].m_quad;
          v36->m_scale = (hkVector4f)p_m_scale->m_quad;
        }
        v25 = (unsigned int)(v25 + 1);
        ++v34;
        p_m_scale += 3;
      }
      while ( (unsigned int)v25 < v8 );
    }
  }
  else
  {
    v28 = boneWeightsOut + 2;
    v29 = &bonesOut[1].m_scale;
    while ( v26 < maxNumTransformTracks )
    {
      if ( *(v28 - 2) > 0.0 )
      {
        v30 = transformTracksOut++;
        v30->m_translation = (hkVector4f)v29[-5].m_quad;
        ++v26;
        v30->m_rotation.m_vec = (hkVector4f)v29[-4].m_quad;
        v30->m_scale = (hkVector4f)v29[-3].m_quad;
      }
      if ( v26 >= maxNumTransformTracks )
        break;
      if ( *(v28 - 1) > 0.0 )
      {
        v31 = transformTracksOut++;
        v31->m_translation = (hkVector4f)v29[-2].m_quad;
        ++v26;
        v31->m_rotation.m_vec = (hkVector4f)v29[-1].m_quad;
        v31->m_scale = (hkVector4f)v29->m_quad;
      }
      if ( v26 >= maxNumTransformTracks )
        break;
      if ( *v28 > 0.0 )
      {
        v32 = transformTracksOut++;
        v32->m_translation = (hkVector4f)v29[1].m_quad;
        ++v26;
        v32->m_rotation.m_vec = (hkVector4f)v29[2].m_quad;
        v32->m_scale = (hkVector4f)v29[3].m_quad;
      }
      if ( v26 >= maxNumTransformTracks )
        break;
      if ( v28[1] > 0.0 )
      {
        v33 = transformTracksOut++;
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
  if ( v9 < 4 )
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
}nt)(4 * v48),
      v25);
  if ( v49 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkQsTransformf *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      bonesOut,

// File Line: 590
// RVA: 0xB2E200
__int64 __fastcall hkaQuantizedAnimation::getNumDataChunks(
        hkaQuantizedAnimation *this,
        unsigned int frame,
        float delta)
{
  return 4i64;
}

// File Line: 595
// RVA: 0xB2E210
void __fastcall hkaQuantizedAnimation::getDataChunks(
        hkaQuantizedAnimation *this,
        unsigned int frame,
        float delta,
        hkaAnimation::DataChunk *chunks)
{
  char *m_data; // r8
  unsigned int v5; // r10d
  __int64 v6; // r11
  unsigned int v7; // eax
  char *v8; // r11

  m_data = this->m_data.m_data;
  v5 = *((unsigned __int16 *)m_data + 14);
  v6 = *(unsigned __int16 *)m_data;
  chunks->m_data = (const char *)this;
  chunks->m_size = 88;
  v7 = *(unsigned __int16 *)m_data;
  chunks[1].m_data = m_data;
  chunks[1].m_size = v7;
  v8 = &m_data[v6];
  chunks[2].m_size = v5;
  chunks[2].m_data = &v8[frame * v5];
  chunks[3].m_size = v5;
  chunks[3].m_data = &v8[v5 * (frame + 1)];
}

// File Line: 612
// RVA: 0xB2E270
__int64 __fastcall hkaQuantizedAnimation::getMaxSizeOfCombinedDataChunks(hkaQuantizedAnimation *this)
{
  return 2 * ((*((unsigned __int16 *)this->m_data.m_data + 14) + 15) & 0xFFFFFFF0)
       + ((*(unsigned __int16 *)this->m_data.m_data + 15) & 0xFFFFFFF0)
       + 96i64;
}

// File Line: 622
// RVA: 0xB2E2A0
__int64 __fastcall hkaQuantizedAnimation::getMaxDecompressionTempBytes(hkaQuantizedAnimation *this)
{
  return 148 * ((this->m_skeleton->m_bones.m_size + 3) & 0xFFFFFFFC)
       + 16i64 * ((this->m_skeleton->m_floatSlots.m_size + 3) & 0xFFFFFFFC);
}

// File Line: 641
// RVA: 0xB2E2D0
void __fastcall hkaQuantizedAnimation::samplePartialWithDataChunks(
        unsigned int frameIndex,
        float frameDelta,
        unsigned int maxNumTransformTracks,
        unsigned int maxNumFloatTracks,
        hkQsTransformf *referenceTransforms,
        const float *referenceFloats,
        hkaAnimation::DataChunk *dataChunks,
        int numDataChunks,
        hkQsTransformf *transformTracksOut,
        float *floatTracksOut)
{
  char *m_data; // rbp
  const char *v11; // r14
  const char *v12; // r15
  int v13; // r13d
  unsigned int v16; // ebx
  unsigned int v17; // edi
  hkLifoAllocator *Value; // rax
  int v19; // edx
  char *v20; // rcx
  hkLifoAllocator *v21; // rax
  char *v22; // rcx
  hkLifoAllocator *v23; // rax
  char *v24; // rcx
  hkLifoAllocator *v25; // rax
  int v26; // r8d
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
  unsigned int v40; // r11d
  unsigned int v41; // r10d
  unsigned int v42; // ecx
  __int64 v43; // rbx
  float *v44; // r9
  hkVector4f *v45; // rdx
  hkQsTransformf *v46; // rax
  hkQsTransformf *v47; // rax
  hkQsTransformf *v48; // rax
  hkQsTransformf *v49; // rax
  float *v50; // r9
  hkVector4f *p_m_scale; // rdx
  hkQsTransformf *v52; // rax
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
  int v65; // r8d
  hkLifoAllocator *v66; // rax
  int v67; // ebx
  hkLifoAllocator *v68; // rax
  hkLifoAllocator *v69; // rax
  int numFloats; // [rsp+90h] [rbp-88h]
  float *floatsScratch1; // [rsp+98h] [rbp-80h]
  float *floatsScratch0; // [rsp+A0h] [rbp-78h]
  hkQsTransformf *bonesScratch1; // [rsp+A8h] [rbp-70h]
  hkQsTransformf *bonesOut; // [rsp+B0h] [rbp-68h]
  hkQsTransformf *bonesScratch0; // [rsp+B8h] [rbp-60h]
  float *boneWeightsOut; // [rsp+C0h] [rbp-58h]
  float *p; // [rsp+C8h] [rbp-50h]
  int v78; // [rsp+D0h] [rbp-48h]
  float *v79; // [rsp+D8h] [rbp-40h]
  int dataChunksa; // [rsp+150h] [rbp+38h]

  m_data = (char *)dataChunks[1].m_data;
  v11 = dataChunks[2].m_data;
  v12 = dataChunks[3].m_data;
  v13 = *((unsigned __int16 *)m_data + 1);
  v16 = (v13 + 3) & 0xFFFFFFFC;
  v17 = (*((unsigned __int16 *)m_data + 2) + 3) & 0xFFFFFFFC;
  numFloats = *((unsigned __int16 *)m_data + 2);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  bonesOut = (hkQsTransformf *)Value->m_cur;
  v19 = (48 * v16 + 127) & 0xFFFFFF80;
  dataChunksa = v19;
  v20 = (char *)bonesOut + v19;
  if ( v19 > Value->m_slabSize || v20 > Value->m_end )
    bonesOut = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v19);
  else
    Value->m_cur = v20;
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
  v78 = v26;
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
  p = floatWeightsOut;
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
    m_data,
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
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0i64;
  if ( v13 < 4 )
  {
LABEL_48:
    if ( v41 < v13 )
    {
      v50 = &boneWeightsOut[v43];
      p_m_scale = &bonesOut[v43].m_scale;
      do
      {
        if ( v42 >= maxNumTransformTracks )
          break;
        if ( *v50 > 0.0 )
        {
          v52 = transformTracksOut++;
          v52->m_translation = (hkVector4f)p_m_scale[-2].m_quad;
          ++v42;
          v52->m_rotation.m_vec = (hkVector4f)p_m_scale[-1].m_quad;
          v52->m_scale = (hkVector4f)p_m_scale->m_quad;
        }
        ++v41;
        ++v50;
        p_m_scale += 3;
      }
      while ( v41 < v13 );
    }
  }
  else
  {
    v44 = boneWeightsOut + 2;
    v45 = &bonesOut[1].m_scale;
    while ( v42 < maxNumTransformTracks )
    {
      if ( *(v44 - 2) > 0.0 )
      {
        v46 = transformTracksOut++;
        v46->m_translation = (hkVector4f)v45[-5].m_quad;
        ++v42;
        v46->m_rotation.m_vec = (hkVector4f)v45[-4].m_quad;
        v46->m_scale = (hkVector4f)v45[-3].m_quad;
      }
      if ( v42 >= maxNumTransformTracks )
        break;
      if ( *(v44 - 1) > 0.0 )
      {
        v47 = transformTracksOut++;
        v47->m_translation = (hkVector4f)v45[-2].m_quad;
        ++v42;
        v47->m_rotation.m_vec = (hkVector4f)v45[-1].m_quad;
        v47->m_scale = (hkVector4f)v45->m_quad;
      }
      if ( v42 >= maxNumTransformTracks )
        break;
      if ( *v44 > 0.0 )
      {
        v48 = transformTracksOut++;
        v48->m_translation = (hkVector4f)v45[1].m_quad;
        ++v42;
        v48->m_rotation.m_vec = (hkVector4f)v45[2].m_quad;
        v48->m_scale = (hkVector4f)v45[3].m_quad;
      }
      if ( v42 >= maxNumTransformTracks )
        break;
      if ( v44[1] > 0.0 )
      {
        v49 = transformTracksOut++;
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
  v54 = 0;
  v55 = 0i64;
  if ( numFloats < 4 )
  {
LABEL_69:
    if ( v40 < numFloats )
    {
      v58 = &v79[v55];
      do
      {
        if ( v54 >= maxNumFloatTracks )
          break;
        if ( *(float *)((char *)v58 + (char *)p - (char *)v79) > 0.0 )
        {
          ++floatTracksOut;
          ++v54;
          *(floatTracksOut - 1) = *v58;
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
    v57 = (char *)p - (char *)v79;
    while ( v54 < maxNumFloatTracks )
    {
      if ( *(float *)((char *)v56 + v57 - 4) > 0.0 )
      {
        ++floatTracksOut;
        ++v54;
        *(floatTracksOut - 1) = *(v56 - 1);
      }
      if ( v54 >= maxNumFloatTracks )
        break;
      if ( *(float *)((char *)v56 + v57) > 0.0 )
      {
        ++floatTracksOut;
        ++v54;
        *(floatTracksOut - 1) = *v56;
      }
      if ( v54 >= maxNumFloatTracks )
        break;
      if ( *(float *)((char *)v56 + v57 + 4) > 0.0 )
      {
        ++floatTracksOut;
        ++v54;
        *(floatTracksOut - 1) = v56[1];
      }
      if ( v54 >= maxNumFloatTracks )
        break;
      if ( *(float *)((char *)v56 + v57 + 8) > 0.0 )
      {
        ++floatTracksOut;
        ++v54;
        *(floatTracksOut - 1) = v56[2];
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
  if ( v30 > v59->m_slabSize || (char *)p + v60 != v59->m_cur || v59->m_firstNonLifoEnd == p )
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
}_firstNonLifoEnd == bonesOut )
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

