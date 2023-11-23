// File Line: 20
// RVA: 0xB39300
void __fastcall hkaQuantizedAnimation::hkaQuantizedAnimation(
        hkaQuantizedAnimation *this,
        hkaAnimationBinding *binding,
        hkaSkeleton *skeleton,
        hkaQuantizedAnimation::TrackCompressionParams *param)
{
  hkaQuantizedAnimation::TrackCompressionParams *v7; // r15
  __int64 m_numberOfTransformTracks; // rax
  __int64 v9; // rdi
  hkaQuantizedAnimation::TrackCompressionParams *v10; // r12
  int v11; // esi
  __int64 v12; // rdx
  float *p_m_rotationTolerance; // rcx
  __int64 m_numberOfFloatTracks; // rax
  __int64 v15; // rbp
  int v16; // edi
  __int64 v17; // rdx
  float *v18; // rcx
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> floatParamsPerTrack; // [rsp+30h] [rbp-78h] BYREF
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> transformParamsPerTrack; // [rsp+40h] [rbp-68h] BYREF
  hkaQuantizedAnimationBuilder v21; // [rsp+50h] [rbp-58h] BYREF
  int v22; // [rsp+B0h] [rbp+8h] BYREF
  hkaSkeleton *skeletona; // [rsp+C0h] [rbp+18h]

  skeletona = skeleton;
  hkaAnimation::hkaAnimation(this, binding->m_animation.m_pntr);
  v7 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 0x80000000;
  m_numberOfTransformTracks = binding->m_animation.m_pntr->m_numberOfTransformTracks;
  v9 = m_numberOfTransformTracks;
  if ( (_DWORD)m_numberOfTransformTracks )
  {
    v22 = 16 * m_numberOfTransformTracks;
    v10 = (hkaQuantizedAnimation::TrackCompressionParams *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                             &hkContainerHeapAllocator::s_alloc,
                                                             &v22);
    LODWORD(m_numberOfTransformTracks) = v22 / 16;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 0x80000000;
  transformParamsPerTrack.m_data = v10;
  if ( (_DWORD)m_numberOfTransformTracks )
    v11 = m_numberOfTransformTracks;
  transformParamsPerTrack.m_size = v9;
  v12 = v9;
  transformParamsPerTrack.m_capacityAndFlags = v11;
  if ( (int)v9 > 0 )
  {
    p_m_rotationTolerance = &v10->m_rotationTolerance;
    do
    {
      if ( p_m_rotationTolerance )
      {
        *p_m_rotationTolerance = param->m_rotationTolerance;
        p_m_rotationTolerance[1] = param->m_translationTolerance;
        p_m_rotationTolerance[2] = param->m_scaleTolerance;
        p_m_rotationTolerance[3] = param->m_floatingTolerance;
      }
      p_m_rotationTolerance += 4;
      --v12;
    }
    while ( v12 );
  }
  m_numberOfFloatTracks = binding->m_animation.m_pntr->m_numberOfFloatTracks;
  v15 = m_numberOfFloatTracks;
  if ( (_DWORD)m_numberOfFloatTracks )
  {
    v22 = 16 * m_numberOfFloatTracks;
    v7 = (hkaQuantizedAnimation::TrackCompressionParams *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                            &hkContainerHeapAllocator::s_alloc,
                                                            &v22);
    LODWORD(m_numberOfFloatTracks) = v22 / 16;
  }
  v16 = 0x80000000;
  floatParamsPerTrack.m_data = v7;
  if ( (_DWORD)m_numberOfFloatTracks )
    v16 = m_numberOfFloatTracks;
  floatParamsPerTrack.m_size = v15;
  v17 = v15;
  floatParamsPerTrack.m_capacityAndFlags = v16;
  if ( (int)v15 > 0 )
  {
    v18 = &v7->m_rotationTolerance;
    do
    {
      if ( v18 )
      {
        *v18 = param->m_rotationTolerance;
        v18[1] = param->m_translationTolerance;
        v18[2] = param->m_scaleTolerance;
        v18[3] = param->m_floatingTolerance;
      }
      v18 += 4;
      --v17;
    }
    while ( v17 );
  }
  hkaQuantizedAnimationBuilder::hkaQuantizedAnimationBuilder(&v21, this);
  hkaQuantizedAnimationBuilder::initialize(&v21, binding, skeletona, &transformParamsPerTrack, &floatParamsPerTrack);
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v7, 16 * v16);
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 16 * v11);
}

// File Line: 34
// RVA: 0xB39500
void __fastcall hkaQuantizedAnimation::hkaQuantizedAnimation(
        hkaQuantizedAnimation *this,
        hkaAnimationBinding *binding,
        hkaSkeleton *skeleton,
        hkaQuantizedAnimation::PerTrackCompressionParams *perTrackParams)
{
  __int64 v6; // r14
  unsigned int m_numberOfTransformTracks; // eax
  __int64 v8; // r12
  hkaQuantizedAnimation::TrackCompressionParams *v9; // rcx
  int v10; // ebp
  hkaQuantizedAnimation::TrackCompressionParams *v11; // rbx
  __int64 v12; // rdi
  unsigned int m_numberOfFloatTracks; // eax
  __int64 v14; // r15
  hkaQuantizedAnimation::TrackCompressionParams *v15; // r13
  int v16; // esi
  hkaQuantizedAnimation::TrackCompressionParams *v17; // rbx
  __int64 v18; // rdi
  hkaQuantizedAnimation::TrackCompressionParams *v19; // rdi
  __int64 v20; // r9
  __int64 v21; // r8
  __int64 v22; // r10
  hkaQuantizedAnimation::TrackCompressionParams *v23; // rdx
  hkaQuantizedAnimation::TrackCompressionParams *v24; // r8
  __int64 v25; // r9
  hkaQuantizedAnimation::TrackCompressionParams *v26; // rdx
  int v27; // [rsp+30h] [rbp-98h] BYREF
  hkaQuantizedAnimation::TrackCompressionParams *v28; // [rsp+38h] [rbp-90h]
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> floatParamsPerTrack; // [rsp+40h] [rbp-88h] BYREF
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> transformParamsPerTrack; // [rsp+50h] [rbp-78h] BYREF
  hkaQuantizedAnimationBuilder v31; // [rsp+60h] [rbp-68h] BYREF

  hkaAnimation::hkaAnimation(this, binding->m_animation.m_pntr);
  v6 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 0x80000000;
  m_numberOfTransformTracks = binding->m_animation.m_pntr->m_numberOfTransformTracks;
  v8 = m_numberOfTransformTracks;
  if ( m_numberOfTransformTracks )
  {
    v27 = 16 * m_numberOfTransformTracks;
    v9 = (hkaQuantizedAnimation::TrackCompressionParams *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                            &hkContainerHeapAllocator::s_alloc,
                                                            &v27);
    m_numberOfTransformTracks = v27 / 16;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = 0x80000000;
  v28 = v9;
  if ( m_numberOfTransformTracks )
    v10 = m_numberOfTransformTracks;
  transformParamsPerTrack.m_data = v9;
  transformParamsPerTrack.m_size = v8;
  transformParamsPerTrack.m_capacityAndFlags = v10;
  if ( (int)v8 > 0 )
  {
    v11 = v9;
    v12 = v8;
    do
    {
      if ( v11 )
        hkaQuantizedAnimation::TrackCompressionParams::TrackCompressionParams(v11);
      ++v11;
      --v12;
    }
    while ( v12 );
  }
  m_numberOfFloatTracks = binding->m_animation.m_pntr->m_numberOfFloatTracks;
  v14 = m_numberOfFloatTracks;
  if ( m_numberOfFloatTracks )
  {
    v27 = 16 * m_numberOfFloatTracks;
    v15 = (hkaQuantizedAnimation::TrackCompressionParams *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                             &hkContainerHeapAllocator::s_alloc,
                                                             &v27);
    m_numberOfFloatTracks = v27 / 16;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = 0x80000000;
  floatParamsPerTrack.m_data = v15;
  if ( m_numberOfFloatTracks )
    v16 = m_numberOfFloatTracks;
  floatParamsPerTrack.m_size = v14;
  floatParamsPerTrack.m_capacityAndFlags = v16;
  if ( (int)v14 > 0 )
  {
    v17 = v15;
    v18 = v14;
    do
    {
      if ( v17 )
        hkaQuantizedAnimation::TrackCompressionParams::TrackCompressionParams(v17);
      ++v17;
      --v18;
    }
    while ( v18 );
  }
  v19 = v28;
  if ( (int)v8 > 0 )
  {
    v20 = 0i64;
    v21 = (__int64)v28;
    v22 = v8;
    do
    {
      v21 += 16i64;
      v23 = &perTrackParams->m_parameterPalette.m_data[perTrackParams->m_trackIndexToPaletteIndex.m_data[v20++]];
      *(float *)(v21 - 16) = v23->m_rotationTolerance;
      *(float *)(v21 - 12) = v23->m_translationTolerance;
      *(float *)(v21 - 8) = v23->m_scaleTolerance;
      *(float *)(v21 - 4) = v23->m_floatingTolerance;
      --v22;
    }
    while ( v22 );
  }
  if ( (int)v14 > 0 )
  {
    v24 = v15;
    v25 = v14;
    do
    {
      ++v24;
      v26 = &perTrackParams->m_parameterPalette.m_data[perTrackParams->m_floatTrackIndexToPaletteIndex.m_data[v6++]];
      v24[-1].m_rotationTolerance = v26->m_rotationTolerance;
      v24[-1].m_translationTolerance = v26->m_translationTolerance;
      v24[-1].m_scaleTolerance = v26->m_scaleTolerance;
      v24[-1].m_floatingTolerance = v26->m_floatingTolerance;
      --v25;
    }
    while ( v25 );
  }
  hkaQuantizedAnimationBuilder::hkaQuantizedAnimationBuilder(&v31, this);
  hkaQuantizedAnimationBuilder::initialize(&v31, binding, skeleton, &transformParamsPerTrack, &floatParamsPerTrack);
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v15, 16 * v16);
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v19, 16 * v10);
}

// File Line: 67
// RVA: 0xB397D0
void __fastcall hkaQuantizedAnimation::hkaQuantizedAnimation(
        hkaQuantizedAnimation *this,
        hkaAnimationBinding *binding,
        hkaSkeleton *skeleton,
        hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> *transformParamsPerTrack,
        hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> *floatParamsPerTrack)
{
  int m_capacityAndFlags; // r8d
  int v10; // r8d
  hkaQuantizedAnimationBuilder v11; // [rsp+30h] [rbp-38h] BYREF

  hkaAnimation::hkaAnimation(this, binding->m_animation.m_pntr);
  this->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 0x80000000;
  hkaQuantizedAnimationBuilder::hkaQuantizedAnimationBuilder(&v11, this);
  hkaQuantizedAnimationBuilder::initialize(&v11, binding, skeleton, transformParamsPerTrack, floatParamsPerTrack);
  m_capacityAndFlags = transformParamsPerTrack->m_capacityAndFlags;
  transformParamsPerTrack->m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      transformParamsPerTrack->m_data,
      16 * m_capacityAndFlags);
  transformParamsPerTrack->m_data = 0i64;
  transformParamsPerTrack->m_capacityAndFlags = 0x80000000;
  v10 = floatParamsPerTrack->m_capacityAndFlags;
  floatParamsPerTrack->m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      floatParamsPerTrack->m_data,
      16 * v10);
  floatParamsPerTrack->m_data = 0i64;
  floatParamsPerTrack->m_capacityAndFlags = 0x80000000;
}

// File Line: 73
// RVA: 0xB398E0
void __fastcall hkaQuantizedAnimation::~hkaQuantizedAnimation(hkaQuantizedAnimation *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable;
  m_capacityAndFlags = this->m_data.m_capacityAndFlags;
  this->m_data.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_data.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_data.m_data = 0i64;
  this->m_data.m_capacityAndFlags = 0x80000000;
  hkaAnimation::~hkaAnimation(this);
}

// File Line: 78
// RVA: 0xB39C40
void __fastcall hkaQuantizedAnimationBuilder::hkaQuantizedAnimationBuilder(
        hkaQuantizedAnimationBuilder *this,
        hkaQuantizedAnimation *anim)
{
  this->m_data = &anim->m_data;
  this->m_endian = &anim->m_endian;
  this->m_skeleton = &anim->m_skeleton;
  this->m_type = &anim->m_type;
}

// File Line: 88
// RVA: 0xB39C70
void __fastcall hkaQuantizedAnimationBuilder::initialize(
        hkaQuantizedAnimationBuilder *this,
        hkaAnimationBinding *binding,
        hkaSkeleton *skeleton,
        hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> *transformParamsPerTrack)
{
  hkaAnimationBinding *v5; // rbx
  hkaAnimation *m_pntr; // r15
  hkBaseObjectVtbl *vfptr; // rax
  int v8; // eax
  int m_size; // eax
  int m_numberOfTransformTracks; // eax
  int v11; // eax
  hkaQuantizedAnimationBuilder::Range *v12; // r14
  unsigned int v13; // ecx
  int m_numberOfFloatTracks; // eax
  hkQsTransformf *m_data; // r12
  const float *v16; // rsi
  const float *v17; // r13
  unsigned int v18; // ecx
  int v19; // eax
  int v20; // r15d
  hkaQuantizedAnimationBuilder::Range *v21; // rdi
  __int64 v22; // r12
  int v23; // eax
  hkBaseObjectVtbl *v24; // rdi
  __int64 v25; // rsi
  unsigned __int16 v26; // r13
  int v27; // edx
  __int16 v28; // ax
  unsigned __int16 v29; // di
  __int16 v30; // ax
  __int64 v31; // rsi
  __int64 v32; // r13
  float *v33; // rsi
  __int16 v34; // bx
  __int64 v35; // r13
  unsigned __int16 v36; // di
  __int16 v37; // r13
  unsigned __int16 v38; // si
  _QWORD *v39; // r13
  int v40; // r9d
  __int16 v41; // r14
  int v42; // esi
  unsigned int v43; // ecx
  hkBaseObjectVtbl *v44; // rax
  hkBaseObjectVtbl *v45; // r8
  int v46; // eax
  int v47; // ecx
  __int64 v48; // rdx
  int v49; // eax
  int v50; // edx
  __int64 v51; // rdi
  int v52; // ecx
  int m_duration_low; // xmm0_4
  __int16 v54; // r13
  __int16 v55; // r12
  int v56; // esi
  int v57; // r14d
  int v58; // edi
  int v59; // r15d
  int v60; // ebx
  __int64 v61; // rdi
  hkaQuantizedAnimationBuilder *v62; // rbx
  hkArray<unsigned char,hkContainerHeapAllocator> *v63; // r8
  int v64; // r9d
  int v65; // eax
  int v66; // eax
  hkaAnimation *v67; // r14
  int v68; // eax
  char *v69; // r14
  __int64 v70; // r13
  unsigned int v71; // esi
  int v72; // r15d
  int v73; // r12d
  int v74; // esi
  int v75; // ebx
  hkOstream *v76; // rax
  hkOstream *v77; // rax
  hkOstream *v78; // rax
  hkOstream *v79; // rax
  int v80; // edi
  hkOstream *v81; // rax
  int v82; // edi
  hkOstream *v83; // rax
  int v84; // edi
  hkOstream *v85; // rax
  int v86; // edi
  hkOstream *v87; // rax
  hkOstream *v88; // rax
  hkOstream *v89; // rax
  hkOstream *v90; // rax
  hkOstream *v91; // rax
  hkOstream *v92; // rax
  hkOstream *v93; // rax
  hkOstream *v94; // rax
  hkOstream *v95; // rax
  hkOstream rangeOut; // [rsp+40h] [rbp-80h] BYREF
  int v97; // [rsp+58h] [rbp-68h]
  int n; // [rsp+5Ch] [rbp-64h]
  hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> dynamicElementsOut; // [rsp+60h] [rbp-60h] BYREF
  hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> v100; // [rsp+70h] [rbp-50h] BYREF
  hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> staticElementsOut; // [rsp+80h] [rbp-40h] BYREF
  int v102; // [rsp+90h] [rbp-30h]
  hkQsTransformf *v103; // [rsp+98h] [rbp-28h]
  int v104; // [rsp+A0h] [rbp-20h] BYREF
  int v105; // [rsp+A4h] [rbp-1Ch] BYREF
  hkaAnimation *v106; // [rsp+A8h] [rbp-18h]
  hkArray<unsigned char,hkContainerHeapAllocator> v107; // [rsp+B0h] [rbp-10h] BYREF
  __int64 v108; // [rsp+C0h] [rbp+0h]
  __int16 data[4]; // [rsp+C8h] [rbp+8h] BYREF
  int v110; // [rsp+D0h] [rbp+10h]
  __int16 v111; // [rsp+D4h] [rbp+14h]
  __int16 v112; // [rsp+D6h] [rbp+16h]
  __int16 v113; // [rsp+D8h] [rbp+18h]
  __int16 v114; // [rsp+DAh] [rbp+1Ah]
  __int16 v115; // [rsp+DCh] [rbp+1Ch]
  __int16 v116; // [rsp+DEh] [rbp+1Eh]
  __int16 v117; // [rsp+E0h] [rbp+20h]
  __int16 v118; // [rsp+E2h] [rbp+22h]
  unsigned __int16 v119; // [rsp+E4h] [rbp+24h]
  __int16 v120; // [rsp+E6h] [rbp+26h]
  __int16 v121; // [rsp+E8h] [rbp+28h]
  __int16 v122; // [rsp+EAh] [rbp+2Ah]
  __int16 v123; // [rsp+ECh] [rbp+2Ch]
  __int16 v124; // [rsp+EEh] [rbp+2Eh]
  hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> v125; // [rsp+F0h] [rbp+30h] BYREF
  char buf[576]; // [rsp+100h] [rbp+40h] BYREF
  hkaQuantizedAnimationBuilder *v127; // [rsp+360h] [rbp+2A0h]
  unsigned int numInOut[2]; // [rsp+368h] [rbp+2A8h] BYREF
  int v129; // [rsp+370h] [rbp+2B0h]
  _QWORD *v130; // [rsp+378h] [rbp+2B8h]
  _QWORD *v131; // [rsp+380h] [rbp+2C0h]

  *this->m_endian = 0;
  this->m_type->m_storage = 4;
  v5 = binding;
  *this->m_skeleton = skeleton;
  m_pntr = binding->m_animation.m_pntr;
  vfptr = m_pntr->vfptr;
  v106 = m_pntr;
  v8 = ((__int64 (__fastcall *)(hkaAnimation *))vfptr[4].__vecDelDtor)(m_pntr);
  staticElementsOut.m_data = 0i64;
  staticElementsOut.m_size = 0;
  n = v8;
  m_size = skeleton->m_bones.m_size;
  staticElementsOut.m_capacityAndFlags = 0x80000000;
  v102 = m_size;
  v97 = skeleton->m_floatSlots.m_size;
  dynamicElementsOut.m_data = 0i64;
  dynamicElementsOut.m_size = 0;
  dynamicElementsOut.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&rangeOut.m_memSizeAndFlags = 0i64;
  rangeOut.m_writer.m_pntr = (hkStreamWriter *)0x8000000000000000i64;
  v100.m_data = 0i64;
  v100.m_size = 0;
  v100.m_capacityAndFlags = 0x80000000;
  m_numberOfTransformTracks = m_pntr->m_numberOfTransformTracks;
  rangeOut.vfptr = 0i64;
  *(_DWORD *)(&rangeOut.m_referenceCount + 1) = 0x80000000;
  v125.m_data = 0i64;
  v11 = 12 * m_numberOfTransformTracks;
  v125.m_size = 0;
  v125.m_capacityAndFlags = 0x80000000;
  if ( v11 )
  {
    v105 = 32 * v11;
    v12 = (hkaQuantizedAnimationBuilder::Range *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   &hkContainerHeapAllocator::s_alloc,
                                                   &v105);
    v11 = v105 / 32;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = 0x80000000;
  if ( v11 )
    v13 = v11;
  m_numberOfFloatTracks = m_pntr->m_numberOfFloatTracks;
  LODWORD(v107.m_data) = v13;
  if ( m_numberOfFloatTracks )
  {
    v104 = 32 * m_numberOfFloatTracks;
    rangeOut.vfptr = (hkBaseObjectVtbl *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                           &hkContainerHeapAllocator::s_alloc,
                                           &v104);
    m_numberOfFloatTracks = v104 / 32;
  }
  else
  {
    rangeOut.vfptr = 0i64;
  }
  m_data = skeleton->m_referencePose.m_data;
  v16 = (const float *)m_pntr[1].vfptr;
  v17 = *(const float **)&m_pntr[1].m_type.m_storage;
  v18 = 0x80000000;
  v103 = m_data;
  if ( m_numberOfFloatTracks )
    v18 = m_numberOfFloatTracks;
  v19 = m_pntr->m_numberOfTransformTracks;
  LODWORD(v108) = v18;
  if ( 12 * v19 > 0 )
  {
    v20 = 12 * v19;
    v21 = v12;
    v22 = (unsigned int)(12 * v19);
    do
    {
      hkaQuantizedAnimationBuilder::getRange(v21++, v16++, v20, n);
      --v22;
    }
    while ( v22 );
    m_pntr = v106;
    m_data = v103;
    v5 = *(hkaAnimationBinding **)numInOut;
  }
  v23 = m_pntr->m_numberOfFloatTracks;
  if ( v23 > 0 )
  {
    v24 = rangeOut.vfptr;
    v25 = (unsigned int)v23;
    do
    {
      hkaQuantizedAnimationBuilder::getRange(
        (hkaQuantizedAnimationBuilder::Range *)v24,
        v17++,
        m_pntr->m_numberOfFloatTracks,
        n);
      v24 += 2;
      --v25;
    }
    while ( v25 );
    v5 = *(hkaAnimationBinding **)numInOut;
  }
  v26 = 0;
  LOWORD(v97) = 0;
  if ( m_pntr->m_numberOfTransformTracks > 0 )
  {
    LOWORD(v27) = 0;
    LODWORD(v103) = 0;
    do
    {
      if ( v5->m_transformTrackToBoneIndices.m_size <= 0 )
        v28 = v26;
      else
        v28 = v5->m_transformTrackToBoneIndices.m_data[v26];
      LOWORD(v129) = v28;
      v29 = v27;
      v30 = v28 - v26;
      v31 = 16i64 * v26;
      v32 = 3i64;
      v33 = (float *)(*v130 + v31);
      v34 = 12 * v30;
      do
      {
        hkaQuantizedAnimationBuilder::identifyScalarElements(
          v29,
          v29 + v34,
          v12,
          m_data->m_translation.m_quad.m128_f32,
          v33[1],
          &staticElementsOut,
          &dynamicElementsOut);
        ++v29;
        --v32;
      }
      while ( v32 );
      v35 = 3i64;
      v36 = (_WORD)v103 + 8;
      do
      {
        hkaQuantizedAnimationBuilder::identifyScalarElements(
          v36,
          v34 + v36,
          v12,
          m_data->m_translation.m_quad.m128_f32,
          v33[2],
          &staticElementsOut,
          &dynamicElementsOut);
        ++v36;
        --v35;
      }
      while ( v35 );
      v37 = v97;
      hkaQuantizedAnimationBuilder::identifyRotations(
        v97,
        v129,
        v12,
        m_data->m_translation.m_quad.m128_f32,
        *v33,
        (hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *)&dynamicElementsOut,
        (hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *)&rangeOut.m_memSizeAndFlags);
      HIWORD(v27) = WORD1(v103);
      v5 = *(hkaAnimationBinding **)numInOut;
      v26 = v37 + 1;
      LOWORD(v27) = (_WORD)v103 + 12;
      LODWORD(v103) = v27;
      LOWORD(v97) = v26;
    }
    while ( v26 < m_pntr->m_numberOfTransformTracks );
  }
  v38 = 0;
  if ( m_pntr->m_numberOfFloatTracks > 0 )
  {
    v39 = v131;
    do
    {
      hkaQuantizedAnimationBuilder::identifyScalarElements(
        v38,
        v5->m_floatTrackToFloatSlotIndices.m_data[v38],
        (hkaQuantizedAnimationBuilder::Range *)rangeOut.vfptr,
        0i64,
        *(float *)(*v39 + 16i64 * v38 + 12),
        &v100,
        (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v100);
      ++v38;
    }
    while ( v38 < m_pntr->m_numberOfFloatTracks );
  }
  if ( (int)v108 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, rangeOut.vfptr, 32 * v108);
  if ( SLODWORD(v107.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v12, 32 * LODWORD(v107.m_data));
  v40 = v102;
  v41 = v97;
  v42 = v97 + v102;
  v43 = v97 + v102;
  if ( v97 + v102 )
  {
    numInOut[0] = v97 + v102;
    v44 = (hkBaseObjectVtbl *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                &hkContainerHeapAllocator::s_alloc,
                                numInOut);
    v43 = numInOut[0];
    v40 = v102;
    v45 = v44;
  }
  else
  {
    v45 = 0i64;
  }
  v46 = 0x80000000;
  rangeOut.vfptr = v45;
  if ( v43 )
    v46 = v43;
  v107.m_data = (char *)v45;
  v107.m_size = v42;
  v97 = v46;
  v107.m_capacityAndFlags = v46;
  if ( v42 > 0 )
    memset(v45, 0, v42);
  v47 = 0;
  if ( m_pntr->m_numberOfTransformTracks > 0 )
  {
    v48 = 0i64;
    do
    {
      if ( v5->m_transformTrackToBoneIndices.m_size )
        v49 = v5->m_transformTrackToBoneIndices.m_data[v48];
      else
        v49 = v47;
      ++v47;
      ++v48;
      *((_BYTE *)&v45->__vecDelDtor + v49) = -1;
    }
    while ( v47 < m_pntr->m_numberOfTransformTracks );
  }
  v50 = 0;
  if ( m_pntr->m_numberOfFloatTracks > 0 )
  {
    v51 = 0i64;
    do
    {
      if ( v5->m_floatTrackToFloatSlotIndices.m_size <= 0 )
        v52 = v50;
      else
        v52 = v5->m_floatTrackToFloatSlotIndices.m_data[v51];
      ++v50;
      ++v51;
      *((_BYTE *)&v45->__vecDelDtor + v52 + v40) = -1;
    }
    while ( v50 < m_pntr->m_numberOfFloatTracks );
  }
  m_duration_low = LODWORD(m_pntr->m_duration);
  v54 = dynamicElementsOut.m_size;
  v55 = v100.m_size;
  data[3] = n;
  v110 = m_duration_low;
  v111 = staticElementsOut.m_size;
  v112 = dynamicElementsOut.m_size;
  v114 = v100.m_size;
  data[1] = v40;
  v116 = (__int16)rangeOut.m_writer.m_pntr;
  data[2] = v41;
  v113 = 0;
  v115 = dynamicElementsOut.m_size;
  v117 = 0;
  numInOut[0] = v42 + 40;
  v118 = v100.m_size;
  hkaQuantizedAnimationBuilder::align(numInOut, 2);
  v56 = staticElementsOut.m_size;
  v57 = v100.m_size;
  v58 = dynamicElementsOut.m_size;
  v120 = numInOut[0];
  numInOut[0] += 2 * (dynamicElementsOut.m_size + staticElementsOut.m_size + v100.m_size);
  hkaQuantizedAnimationBuilder::align(numInOut, 2);
  v59 = v100.m_size;
  v60 = dynamicElementsOut.m_size;
  v121 = numInOut[0];
  numInOut[0] += 2 * (dynamicElementsOut.m_size + v100.m_size + LODWORD(rangeOut.m_writer.m_pntr));
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  v122 = numInOut[0];
  numInOut[0] += 4 * v56 + 6 * v58;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  numInOut[0] += 4 * v57;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  v60 *= 4;
  v123 = numInOut[0];
  numInOut[0] += v60;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  numInOut[0] += 4 * v59;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  v124 = numInOut[0];
  numInOut[0] += v60;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  numInOut[0] += 4 * v59;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  v61 = (unsigned int)n;
  v62 = v127;
  v63 = v127->m_data;
  data[0] = numInOut[0];
  v119 = (2 * (v54 + v55 + 3 * LOWORD(rangeOut.m_writer.m_pntr)) + 15) & 0xFFF0;
  v64 = LOWORD(numInOut[0]) + (unsigned __int16)n * v119;
  v65 = v63->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v65 < v64 )
  {
    v66 = 2 * v65;
    if ( v64 < v66 )
      v64 = v66;
    hkArrayUtil::_reserve((hkResult *)numInOut, &hkContainerHeapAllocator::s_alloc, v63, v64, 1);
  }
  hkaQuantizedAnimationBuilder::appendData(v62, data, 40);
  hkaQuantizedAnimationBuilder::appendData(v62, &v107);
  hkaQuantizedAnimationBuilder::appendElements(v62, &staticElementsOut);
  hkaQuantizedAnimationBuilder::appendElements(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *)&rangeOut);
  hkaQuantizedAnimationBuilder::appendElements(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *)&dynamicElementsOut);
  hkaQuantizedAnimationBuilder::appendElements(v62, &v100);
  hkaQuantizedAnimationBuilder::appendElements(v62, &dynamicElementsOut);
  hkaQuantizedAnimationBuilder::appendElements(v62, &v125);
  hkaQuantizedAnimationBuilder::appendElements(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *)&rangeOut.m_memSizeAndFlags);
  hkaQuantizedAnimationBuilder::appendElements(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v100);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendValues(v62, &staticElementsOut);
  hkaQuantizedAnimationBuilder::appendValues(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *)&rangeOut);
  hkaQuantizedAnimationBuilder::appendValues(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *)&dynamicElementsOut);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendValues(v62, &v100);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendRangeMinimums(v62, &dynamicElementsOut);
  hkaQuantizedAnimationBuilder::appendRangeMinimums(v62, &v125);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendRangeMinimums(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v100);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendRangeSpans(v62, &dynamicElementsOut);
  hkaQuantizedAnimationBuilder::appendRangeSpans(v62, &v125);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendRangeSpans(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v100);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  v67 = v106;
  v107.m_data = (char *)v106[1].vfptr;
  v108 = *(_QWORD *)&v106[1].m_type.m_storage;
  v68 = 12 * v106->m_numberOfTransformTracks;
  LODWORD(v127) = 3 * v106->m_numberOfTransformTracks;
  numInOut[0] = v68;
  v129 = v106->m_numberOfFloatTracks;
  if ( (_DWORD)v61 )
  {
    v69 = v107.m_data;
    v70 = v61;
    v71 = 0;
    v72 = 0;
    v73 = 0;
    do
    {
      hkaQuantizedAnimationBuilder::align(v62, 16);
      hkaQuantizedAnimationBuilder::appendValues(v62, &dynamicElementsOut, (const float *)&v69[4 * v73]);
      hkaQuantizedAnimationBuilder::appendValues(v62, &v125, (const float *)&v69[4 * v73]);
      hkaQuantizedAnimationBuilder::appendValues(
        v62,
        (hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *)&rangeOut.m_memSizeAndFlags,
        (hkQuaternionf *)&v69[16 * v72]);
      hkaQuantizedAnimationBuilder::appendValues(
        v62,
        (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v100,
        (const float *)(v108 + 4i64 * v71));
      hkaQuantizedAnimationBuilder::align(v62, 16);
      v73 += numInOut[0];
      v72 += (int)v127;
      v71 += v129;
      --v70;
    }
    while ( v70 );
    v67 = v106;
  }
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::align(v62, 64);
  v74 = ((__int64 (__fastcall *)(hkaAnimation *))v67->vfptr[3].__first_virtual_table_function__)(v67);
  v75 = v62->m_data->m_size + 88;
  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    510016177i64,
    "Compression");
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v76 = hkOstream::operator<<(&rangeOut, "Original Size ");
  hkOstream::operator<<(v76, v74);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 396);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v77 = hkOstream::operator<<(&rangeOut, " Compressed Size ");
  hkOstream::operator<<(v77, v75);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 397);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v78 = hkOstream::operator<<(&rangeOut, "Compression Ratio: ");
  v79 = hkOstream::operator<<(v78, (float)v74 / (float)v75);
  hkOstream::operator<<(v79, ":1");
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 398);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v80 = 3 * *(_DWORD *)&v67[1].m_memSizeAndFlags - staticElementsOut.m_size - dynamicElementsOut.m_size;
  v81 = hkOstream::operator<<(&rangeOut, "Reference Translations: ");
  hkOstream::operator<<(v81, v80);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 400);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v82 = 3 * *(_DWORD *)&v67[1].m_memSizeAndFlags - LODWORD(rangeOut.m_writer.m_pntr) - dynamicElementsOut.m_size;
  v83 = hkOstream::operator<<(&rangeOut, "Reference Rotations:    ");
  hkOstream::operator<<(v83, v82);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 401);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v84 = 3 * *(_DWORD *)&v67[1].m_memSizeAndFlags;
  v85 = hkOstream::operator<<(&rangeOut, "Reference Scales:       ");
  hkOstream::operator<<(v85, v84);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 402);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v86 = v67[1].m_numberOfTransformTracks - v100.m_size - v100.m_size;
  v87 = hkOstream::operator<<(&rangeOut, "Reference Floats:       ");
  hkOstream::operator<<(v87, v86);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 403);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v88 = hkOstream::operator<<(&rangeOut, "Static Translations:   ");
  hkOstream::operator<<(v88, staticElementsOut.m_size);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 405);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v89 = hkOstream::operator<<(&rangeOut, "Static Rotations:      ");
  hkOstream::operator<<(v89, dynamicElementsOut.m_size);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 406);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v90 = hkOstream::operator<<(&rangeOut, "Static Scales:         ");
  hkOstream::operator<<(v90, 0);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 407);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v91 = hkOstream::operator<<(&rangeOut, "Static Floats:         ");
  hkOstream::operator<<(v91, v100.m_size);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 408);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v92 = hkOstream::operator<<(&rangeOut, "Dynamic Translations:  ");
  hkOstream::operator<<(v92, dynamicElementsOut.m_size);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 410);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v93 = hkOstream::operator<<(&rangeOut, "Dynamic Rotations:     ");
  hkOstream::operator<<(v93, (int)rangeOut.m_writer.m_pntr);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 411);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v94 = hkOstream::operator<<(&rangeOut, "Dynamic Scales:        ");
  hkOstream::operator<<(v94, 0);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 412);
  hkOstream::~hkOstream(&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, buf, 512);
  v95 = hkOstream::operator<<(&rangeOut, "Dynamic Floats:        ");
  hkOstream::operator<<(v95, v100.m_size);
  hkError::messageReport(-1, buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 413);
  hkOstream::~hkOstream(&rangeOut);
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
  if ( v97 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      rangeOut.vfptr,
      v97 & 0x3FFFFFFF);
  v100.m_size = 0;
  if ( v100.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v100.m_data,
      48 * (v100.m_capacityAndFlags & 0x3FFFFFFF));
  v100.m_data = 0i64;
  v100.m_capacityAndFlags = 0x80000000;
  LODWORD(rangeOut.m_writer.m_pntr) = 0;
  if ( SHIDWORD(rangeOut.m_writer.m_pntr) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&rangeOut.m_memSizeAndFlags,
      4 * HIDWORD(rangeOut.m_writer.m_pntr));
  *(_QWORD *)&rangeOut.m_memSizeAndFlags = 0i64;
  HIDWORD(rangeOut.m_writer.m_pntr) = 0x80000000;
  dynamicElementsOut.m_size = 0;
  if ( dynamicElementsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      dynamicElementsOut.m_data,
      48 * (dynamicElementsOut.m_capacityAndFlags & 0x3FFFFFFF));
  dynamicElementsOut.m_data = 0i64;
  dynamicElementsOut.m_capacityAndFlags = 0x80000000;
  v100.m_size = 0;
  if ( v100.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v100.m_data,
      32 * v100.m_capacityAndFlags);
  v100.m_data = 0i64;
  v100.m_capacityAndFlags = 0x80000000;
  dynamicElementsOut.m_size = 0;
  if ( dynamicElementsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      dynamicElementsOut.m_data,
      32 * dynamicElementsOut.m_capacityAndFlags);
  dynamicElementsOut.m_data = 0i64;
  dynamicElementsOut.m_capacityAndFlags = 0x80000000;
  staticElementsOut.m_size = 0;
  if ( staticElementsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      staticElementsOut.m_data,
      32 * staticElementsOut.m_capacityAndFlags);
}pacityAndFlags = 0x80000000;
  dynamicElementsOu

// File Line: 420
// RVA: 0xB3ACF0
void __fastcall hkaQuantizedAnimationBuilder::getRange(
        hkaQuantizedAnimationBuilder::Range *rangeOut,
        const float *base,
        int stride,
        int n)
{
  hkaQuantizedAnimationBuilder::getRange(&rangeOut->m_minimum, &rangeOut->m_span, base, stride, n);
}

// File Line: 425
// RVA: 0xB3AD20
void __fastcall hkaQuantizedAnimationBuilder::getRange(
        hkSimdFloat32 *minimumOut,
        hkSimdFloat32 *spanOut,
        const float *base,
        int stride,
        int n)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __int64 v7; // rax
  __int64 v8; // r9
  __int64 v9; // rax
  __m128 v10; // xmm1
  __m128 v11; // xmm0

  v5 = (__m128)xmmword_141A712A0;
  v6 = (__m128)xmmword_141A712F0;
  if ( n > 0 )
  {
    v7 = stride;
    v8 = (unsigned int)n;
    v9 = 4 * v7;
    do
    {
      v10 = (__m128)*(unsigned int *)base;
      base = (const float *)((char *)base + v9);
      v11 = _mm_shuffle_ps(v10, v10, 0);
      v6 = _mm_max_ps(v11, v6);
      v5 = _mm_min_ps(v11, v5);
      --v8;
    }
    while ( v8 );
  }
  *minimumOut = (hkSimdFloat32)v5;
  spanOut->m_real = _mm_sub_ps(v6, v5);
}

// File Line: 451
// RVA: 0xB3AD80
void __fastcall hkaQuantizedAnimationBuilder::identifyScalarElements(
        unsigned __int16 trackElement,
        unsigned __int16 boneElement,
        hkaQuantizedAnimationBuilder::Range *rangeBase,
        const float *referenceBase,
        float tol,
        hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *staticElementsOut,
        hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *dynamicElementsOut)
{
  hkaQuantizedAnimationBuilder::Range *v7; // r10
  __m128 v8; // xmm1
  float v9; // xmm1_4
  __m128 m_real; // xmm6
  float v11; // xmm2_4
  hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *v12; // rbx
  __m128 v13; // xmm6
  hkaQuantizedAnimationBuilder::StaticScalar *v14; // rax
  __m128 v15; // xmm7
  hkaQuantizedAnimationBuilder::DynamicScalar *v16; // rcx
  __int128 v17; // [rsp+30h] [rbp-48h]
  __int128 v18; // [rsp+40h] [rbp-38h]

  v7 = &rangeBase[trackElement];
  if ( referenceBase )
  {
    v8 = (__m128)LODWORD(referenceBase[boneElement]);
    LODWORD(v9) = _mm_shuffle_ps(v8, v8, 0).m128_u32[0];
  }
  else
  {
    v9 = 0.0;
  }
  m_real = v7->m_span.m_real;
  v11 = _mm_shuffle_ps((__m128)LODWORD(tol), (__m128)LODWORD(tol), 0).m128_f32[0];
  if ( m_real.m128_f32[0] > (float)(v11 + v11) )
  {
    v12 = dynamicElementsOut;
    v15 = v7->m_minimum.m_real;
    WORD1(v18) = boneElement;
    LOWORD(v18) = trackElement;
    if ( dynamicElementsOut->m_size == (dynamicElementsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, dynamicElementsOut, 48);
    v16 = (hkaQuantizedAnimationBuilder::DynamicScalar *)((char *)dynamicElementsOut->m_data
                                                        + 48 * dynamicElementsOut->m_size);
    if ( v16 )
    {
      v16->m_range.m_minimum.m_real = v15;
      v16->m_range.m_span.m_real = m_real;
      *(_OWORD *)&v16->m_trackElement = v18;
    }
LABEL_16:
    ++v12->m_size;
    return;
  }
  if ( !referenceBase
    || COERCE_FLOAT(*(_OWORD *)&v7->m_minimum) < (float)(v9 - v11)
    || (float)(COERCE_FLOAT(*(_OWORD *)&v7->m_minimum) + m_real.m128_f32[0]) > (float)(v11 + v9) )
  {
    v12 = staticElementsOut;
    LOWORD(v17) = boneElement;
    v13 = _mm_add_ps(_mm_mul_ps(m_real, (__m128)xmmword_141A711B0), v7->m_minimum.m_real);
    if ( staticElementsOut->m_size == (staticElementsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, staticElementsOut, 32);
    v14 = &staticElementsOut->m_data[staticElementsOut->m_size];
    if ( v14 )
    {
      v14->m_value.m_real = v13;
      *(_OWORD *)&v14->m_boneElement = v17;
      ++staticElementsOut->m_size;
      return;
    }
    goto LABEL_16;
  }
}

// File Line: 491
// RVA: 0xB3AEE0
void __fastcall hkaQuantizedAnimationBuilder::identifyRotations(
        unsigned __int16 track,
        unsigned __int16 bone,
        hkaQuantizedAnimationBuilder::Range *rangeBase,
        const float *referenceBase,
        float tol,
        hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *staticElementsOut,
        hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *dynamicElementsOut)
{
  __m128 v7; // xmm6
  __int16 v8; // si
  float v9; // xmm5_4
  __m128 v10; // xmm7
  __int16 v12; // di
  int v14; // ecx
  __int128 *v15; // r9
  int v16; // ebx
  int v17; // r8d
  __int64 v18; // rdx
  __int64 v19; // rcx
  __m128 v20; // xmm3
  hkSimdFloat32 v21; // xmm4
  float v22; // xmm3_4
  hkSimdFloat32 v23; // xmm2
  __m128 v24; // xmm1
  hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *v25; // rbx
  __m128 v26; // xmm6
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm6
  __m128 *p_m_quad; // rax
  int *v33; // rdx
  __m128 v34; // [rsp+20h] [rbp-50h]
  __m128 v35; // [rsp+30h] [rbp-40h]
  int v36; // [rsp+90h] [rbp+20h]
  int v37; // [rsp+98h] [rbp+28h]

  v7 = v34;
  v8 = 2 * track + track + 1;
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(tol), (__m128)LODWORD(tol), 0).m128_u32[0];
  v10 = v34;
  v12 = 2 * bone + bone + 1;
  v36 = 0;
  v14 = 12 * track;
  v37 = 0;
  v15 = &`hkVector4f::getComponent::`2::indexToMask;
  v16 = -4 - v14;
  v17 = v14 + 4;
  v18 = 0i64;
  do
  {
    v19 = v17;
    v20 = (__m128)LODWORD(referenceBase[v17]);
    v21.m_real = (__m128)rangeBase[v19].m_span;
    LODWORD(v22) = _mm_shuffle_ps(v20, v20, 0).m128_u32[0];
    if ( v21.m_real.m128_f32[0] > (float)(v9 + v9) )
    {
      v25 = dynamicElementsOut;
      LOWORD(v36) = v8;
      HIWORD(v36) = v12;
      if ( dynamicElementsOut->m_size == (dynamicElementsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, dynamicElementsOut, 4);
      v33 = &v25->m_data->m_value.m_vec.m_quad.m128_i32[v25->m_size];
      if ( v33 )
        *v33 = v36;
      goto LABEL_26;
    }
    v23.m_real = (__m128)rangeBase[v19].m_minimum;
    if ( v23.m_real.m128_f32[0] >= (float)(v22 - v9)
      && (float)(v23.m_real.m128_f32[0] + v21.m_real.m128_f32[0]) <= (float)(v9 + v22) )
    {
      *((_BYTE *)&v36 + v18) = 1;
    }
    if ( v23.m_real.m128_f32[0] >= (float)((float)(0.0 - v22) - v9)
      && (float)(v23.m_real.m128_f32[0] + v21.m_real.m128_f32[0]) <= (float)((float)(0.0 - v22) + v9) )
    {
      *((_BYTE *)&v37 + v18) = 1;
    }
    v24 = (__m128)*v15;
    ++v17;
    ++v18;
    ++v15;
    v10 = _mm_or_ps(_mm_andnot_ps(v24, v10), _mm_and_ps(v23.m_real, v24));
    v7 = _mm_or_ps(_mm_andnot_ps(v24, v7), _mm_and_ps(v21.m_real, v24));
  }
  while ( v16 + v17 < 4 );
  if ( (!(_BYTE)v36 || !BYTE1(v36) || !BYTE2(v36) || !HIBYTE(v36))
    && (!(_BYTE)v37 || !BYTE1(v37) || !BYTE2(v37) || !HIBYTE(v37)) )
  {
    v25 = staticElementsOut;
    v35.m128_i16[0] = v12;
    v26 = _mm_add_ps(_mm_mul_ps(v7, (__m128)xmmword_141A711B0), v10);
    v27 = _mm_mul_ps(v26, v26);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
    v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28);
    v30 = _mm_rsqrt_ps(v29);
    v31 = _mm_mul_ps(
            v26,
            _mm_andnot_ps(
              _mm_cmple_ps(v29, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                _mm_mul_ps(*(__m128 *)_xmm, v30))));
    if ( staticElementsOut->m_size == (staticElementsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, staticElementsOut, 32);
    p_m_quad = &v25->m_data[v25->m_size].m_value.m_vec.m_quad;
    if ( p_m_quad )
    {
      *p_m_quad = v31;
      p_m_quad[1] = v35;
    }
LABEL_26:
    ++v25->m_size;
  }
}

// File Line: 567
// RVA: 0xB392D0
void __fastcall hkaQuantizedAnimation::TrackCompressionParams::TrackCompressionParams(
        hkaQuantizedAnimation::TrackCompressionParams *this)
{
  this->m_floatingTolerance = 0.000099999997;
  this->m_scaleTolerance = 0.000099999997;
  this->m_translationTolerance = 0.000099999997;
  this->m_rotationTolerance = 0.000099999997;
}

// File Line: 572
// RVA: 0xB3B210
void __fastcall hkaQuantizedAnimationBuilder::appendData(
        hkaQuantizedAnimationBuilder *this,
        const void *data,
        int size)
{
  __int64 v3; // rsi
  hkArray<unsigned char,hkContainerHeapAllocator> *m_data; // rdi
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  v3 = size;
  hkaQuantizedAnimationBuilder::align(this, size);
  m_data = this->m_data;
  v7 = v3 + this->m_data->m_size;
  v8 = this->m_data->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = v3 + this->m_data->m_size;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this->m_data, v10, 1);
  }
  m_data->m_size = v7;
  hkString::memCpy(&this->m_data->m_data[this->m_data->m_size - v3], data, v3);
}

// File Line: 584
// RVA: 0xB3B2C0
void __fastcall hkaQuantizedAnimationBuilder::appendData(hkaQuantizedAnimationBuilder *this, const unsigned int *val)
{
  hkaQuantizedAnimationBuilder::align(this, 4);
  hkaQuantizedAnimationBuilder::appendData(this, val, 4);
}

// File Line: 591
// RVA: 0xB3B330
void __fastcall hkaQuantizedAnimationBuilder::appendData(
        hkaQuantizedAnimationBuilder *this,
        hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  int v2; // esi
  __int64 i; // rdi
  hkArray<unsigned char,hkContainerHeapAllocator> *m_data; // rbx
  char *v7; // r15
  char v8; // al

  v2 = 0;
  for ( i = 0i64; v2 < data->m_size; ++m_data->m_size )
  {
    m_data = this->m_data;
    v7 = data->m_data;
    if ( this->m_data->m_size == (this->m_data->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this->m_data, 1);
    v8 = v7[i];
    ++v2;
    ++i;
    m_data->m_data[m_data->m_size] = v8;
  }
}

// File Line: 601
// RVA: 0xB3B3D0
void __fastcall hkaQuantizedAnimationBuilder::appendElements(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *data)
{
  int i; // ebx

  hkaQuantizedAnimationBuilder::align(this, 2);
  for ( i = 0; i < data->m_size; ++i )
    hkaQuantizedAnimationBuilder::appendData(this, &data->m_data[i].m_boneElement);
}

// File Line: 613
// RVA: 0xB3B440
void __fastcall hkaQuantizedAnimationBuilder::appendElements(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *data)
{
  int i; // ebx

  hkaQuantizedAnimationBuilder::align(this, 2);
  for ( i = 0; i < data->m_size; ++i )
    hkaQuantizedAnimationBuilder::appendData(this, &data->m_data[i].m_boneElement);
}

// File Line: 625
// RVA: 0xB3B4B0
void __fastcall hkaQuantizedAnimationBuilder::appendElements(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *data)
{
  int i; // ebx

  hkaQuantizedAnimationBuilder::align(this, 2);
  for ( i = 0; i < data->m_size; ++i )
    hkaQuantizedAnimationBuilder::appendData(this, &data->m_data[i].m_boneElement);
}

// File Line: 637
// RVA: 0xB3B520
void __fastcall hkaQuantizedAnimationBuilder::appendElements(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *data)
{
  int i; // ebx

  hkaQuantizedAnimationBuilder::align(this, 2);
  for ( i = 0; i < data->m_size; ++i )
    hkaQuantizedAnimationBuilder::appendData(this, &data->m_data[i].m_boneElement);
}

// File Line: 649
// RVA: 0xB3B590
void __fastcall hkaQuantizedAnimationBuilder::appendValues(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *data)
{
  int v4; // ebx
  __int64 v5; // rdi
  float value; // [rsp+38h] [rbp+10h] BYREF

  hkaQuantizedAnimationBuilder::align(this, 4);
  v4 = 0;
  if ( data->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      LODWORD(value) = data->m_data[v5].m_value;
      hkaQuantizedAnimationBuilder::appendData(this, &value);
      ++v4;
      ++v5;
    }
    while ( v4 < data->m_size );
  }
}

// File Line: 662
// RVA: 0xB3B600
void __fastcall hkaQuantizedAnimationBuilder::appendValues(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *data)
{
  int i; // ebx
  unsigned __int16 dst; // [rsp+38h] [rbp+10h] BYREF
  unsigned __int16 value; // [rsp+3Ah] [rbp+12h] BYREF
  unsigned __int16 v7; // [rsp+3Ch] [rbp+14h] BYREF

  for ( i = 0; i < data->m_size; ++i )
  {
    hkaQuantizedAnimationBuilder::quantizeQuaternion(&dst, &data->m_data[i].m_value);
    hkaQuantizedAnimationBuilder::appendData(this, &dst);
    hkaQuantizedAnimationBuilder::appendData(this, &value);
    hkaQuantizedAnimationBuilder::appendData(this, &v7);
  }
}

// File Line: 677
// RVA: 0xB3B680
void __fastcall hkaQuantizedAnimationBuilder::appendRangeMinimums(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *data)
{
  int v4; // ebx
  __int64 v5; // rdi
  float value; // [rsp+38h] [rbp+10h] BYREF

  hkaQuantizedAnimationBuilder::align(this, 4);
  v4 = 0;
  if ( data->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      LODWORD(value) = data->m_data[v5].m_range.m_minimum;
      hkaQuantizedAnimationBuilder::appendData(this, &value);
      ++v4;
      ++v5;
    }
    while ( v4 < data->m_size );
  }
}

// File Line: 689
// RVA: 0xB3B6F0
void __fastcall hkaQuantizedAnimationBuilder::appendRangeSpans(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *data)
{
  int v4; // ebx
  float v5; // xmm6_4
  __int64 v6; // rdi
  float value; // [rsp+48h] [rbp+10h] BYREF

  hkaQuantizedAnimationBuilder::align(this, 4);
  v4 = 0;
  value = FLOAT_0_000015259022;
  LODWORD(v5) = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000015259022), (__m128)LODWORD(FLOAT_0_000015259022), 0).m128_u32[0];
  if ( data->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      value = data->m_data[v6].m_range.m_span.m_real.m128_f32[0] * v5;
      hkaQuantizedAnimationBuilder::appendData(this, &value);
      ++v4;
      ++v6;
    }
    while ( v4 < data->m_size );
  }
}

// File Line: 703
// RVA: 0xB3B790
void __fastcall hkaQuantizedAnimationBuilder::appendValues(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *data,
        const float *base)
{
  int v3; // ebx
  __int64 v7; // rdi
  unsigned __int16 value; // [rsp+48h] [rbp+10h] BYREF

  v3 = 0;
  if ( data->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      value = hkaQuantizedAnimationBuilder::quantize16(base[data->m_data[v7].m_trackElement], &data->m_data[v7].m_range);
      hkaQuantizedAnimationBuilder::appendData(this, &value);
      ++v3;
      ++v7;
    }
    while ( v3 < data->m_size );
  }
}

// File Line: 718
// RVA: 0xB3B810
void __fastcall hkaQuantizedAnimationBuilder::appendValues(
        hkaQuantizedAnimationBuilder *this,
        hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *data,
        hkQuaternionf *base)
{
  int v3; // ebx
  __int64 v7; // rdi
  unsigned __int16 dst; // [rsp+48h] [rbp+10h] BYREF
  unsigned __int16 value; // [rsp+4Ah] [rbp+12h] BYREF
  unsigned __int16 v10; // [rsp+4Ch] [rbp+14h] BYREF

  v3 = 0;
  if ( data->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      hkaQuantizedAnimationBuilder::quantizeQuaternion(&dst, &base[data->m_data[v7].m_trackElement]);
      hkaQuantizedAnimationBuilder::appendData(this, &dst);
      hkaQuantizedAnimationBuilder::appendData(this, &value);
      hkaQuantizedAnimationBuilder::appendData(this, &v10);
      ++v3;
      ++v7;
    }
    while ( v3 < data->m_size );
  }
}

// File Line: 736
// RVA: 0xB3B160
void __fastcall hkaQuantizedAnimationBuilder::align(unsigned int *numInOut, int size)
{
  *numInOut = ~(size - 1) & (*numInOut + size - 1);
}

// File Line: 742
// RVA: 0xB3B180
void __fastcall hkaQuantizedAnimationBuilder::align(hkaQuantizedAnimationBuilder *this, const int size)
{
  int m_size; // ecx
  int v4; // r8d
  __int64 v5; // rdi
  hkArray<unsigned char,hkContainerHeapAllocator> *m_data; // rbx

  m_size = this->m_data->m_size;
  v4 = ~(size - 1) & (m_size + size - 1);
  if ( m_size < v4 )
  {
    v5 = (unsigned int)(v4 - m_size);
    do
    {
      m_data = this->m_data;
      if ( this->m_data->m_size == (this->m_data->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this->m_data, 1);
      m_data->m_data[m_data->m_size++] = 0;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 753
// RVA: 0xB3B2A0
void __fastcall hkaQuantizedAnimationBuilder::appendData(
        hkaQuantizedAnimationBuilder *this,
        const unsigned __int16 *value)
{
  hkaQuantizedAnimationBuilder::appendData(this, value, 2);
}

// File Line: 758
// RVA: 0xB3B300
void __fastcall hkaQuantizedAnimationBuilder::appendData(hkaQuantizedAnimationBuilder *this, const float *value)
{
  int data; // [rsp+38h] [rbp+10h] BYREF

  data = *(_DWORD *)value;
  hkaQuantizedAnimationBuilder::appendData(this, &data, 4);
}

// File Line: 764
// RVA: 0xB39C00
void __fastcall hkaQuantizedAnimation::QuantizedAnimationHeader::swizzleEndian(
        hkaQuantizedAnimation::QuantizedAnimationHeader *this)
{
  char m_duration_low; // dl
  char v3; // dl

  hkaQuantizedAnimation::swizzleEndian16(this, 20);
  m_duration_low = LOBYTE(this->m_duration);
  LOBYTE(this->m_duration) = BYTE2(this->m_duration);
  BYTE2(this->m_duration) = m_duration_low;
  v3 = BYTE1(this->m_duration);
  BYTE1(this->m_duration) = HIBYTE(this->m_duration);
  HIBYTE(this->m_duration) = v3;
}

// File Line: 781
// RVA: 0xB39960
void __fastcall hkaQuantizedAnimation::handleEndian(hkaQuantizedAnimation *this)
{
  unsigned __int16 *m_data; // rbx
  unsigned __int16 *v3; // rcx
  unsigned __int16 *v4; // r9
  int v5; // ebx
  unsigned __int16 *v6; // r9

  if ( this->m_endian )
  {
    hkaQuantizedAnimation::QuantizedAnimationHeader::swizzleEndian((hkaQuantizedAnimation::QuantizedAnimationHeader *)this->m_data.m_data);
    m_data = (unsigned __int16 *)this->m_data.m_data;
    hkaQuantizedAnimation::swizzleEndian16((char *)m_data + m_data[15], m_data[6] + m_data[7] + m_data[8] + m_data[9]);
    v3 = (unsigned __int16 *)this->m_data.m_data;
    hkaQuantizedAnimation::swizzleEndian16((char *)m_data + v3[16], v3[10] + v3[11] + v3[12] + v3[13]);
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)m_data + *((unsigned __int16 *)this->m_data.m_data + 17),
      *((unsigned __int16 *)this->m_data.m_data + 6) + *((unsigned __int16 *)this->m_data.m_data + 8));
    hkaQuantizedAnimation::swizzleEndian16(
      (char *)&m_data[2 * *((unsigned __int16 *)this->m_data.m_data + 6)
                    + 2 * *((unsigned __int16 *)this->m_data.m_data + 8)]
    + *((unsigned __int16 *)this->m_data.m_data + 17),
      3 * *((unsigned __int16 *)this->m_data.m_data + 7));
    v4 = (unsigned __int16 *)this->m_data.m_data;
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)m_data + ((6 * v4[7] + 4 * (v4[6] + v4[8]) + 15i64) & 0xFFFFFFFFFFFFFFF0ui64) + v4[17],
      v4[9]);
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)m_data + *((unsigned __int16 *)this->m_data.m_data + 18),
      *((unsigned __int16 *)this->m_data.m_data + 10) + *((unsigned __int16 *)this->m_data.m_data + 12));
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)m_data
    + ((4 * (*((unsigned __int16 *)this->m_data.m_data + 12) + *((unsigned __int16 *)this->m_data.m_data + 10)) + 15i64) & 0xFFFFFFFFFFFFFFF0ui64)
    + *((unsigned __int16 *)this->m_data.m_data + 18),
      *((unsigned __int16 *)this->m_data.m_data + 13));
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)m_data + *((unsigned __int16 *)this->m_data.m_data + 19),
      *((unsigned __int16 *)this->m_data.m_data + 10) + *((unsigned __int16 *)this->m_data.m_data + 12));
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)m_data
    + ((4 * (*((unsigned __int16 *)this->m_data.m_data + 12) + *((unsigned __int16 *)this->m_data.m_data + 10)) + 15i64) & 0xFFFFFFFFFFFFFFF0ui64)
    + *((unsigned __int16 *)this->m_data.m_data + 19),
      *((unsigned __int16 *)this->m_data.m_data + 13));
    v5 = 0;
    if ( *((_WORD *)this->m_data.m_data + 3) )
    {
      do
      {
        v6 = (unsigned __int16 *)this->m_data.m_data;
        hkaQuantizedAnimation::swizzleEndian16((char *)v6 + v5 * v6[14] + *v6, v6[10] + v6[12] + v6[13] + 3 * v6[11]);
        ++v5;
      }
      while ( v5 < *((unsigned __int16 *)this->m_data.m_data + 3) );
    }
    this->m_endian = 0;
  }
}

// File Line: 866
// RVA: 0xB39B80
void __fastcall hkaQuantizedAnimation::swizzleEndian16(_BYTE *valInOut, int n)
{
  __int64 v2; // rax
  __int64 i; // r9
  char v4; // dl
  char v5; // r8

  v2 = 0i64;
  for ( i = n; v2 < i; valInOut[2 * v2 - 1] = v5 )
  {
    v4 = valInOut[2 * v2 + 1];
    v5 = valInOut[2 * v2++];
    valInOut[2 * v2 - 2] = v4;
  }
}

// File Line: 877
// RVA: 0xB39BC0
void __fastcall hkaQuantizedAnimation::swizzleEndian32(char *valInOut, int n)
{
  __int64 v2; // r8
  char *v3; // rax
  char v4; // cl
  char v5; // dl
  char v6; // dl

  v2 = n;
  if ( n > 0 )
  {
    v3 = valInOut + 2;
    do
    {
      v4 = v3[1];
      v5 = *(v3 - 2);
      v3 += 4;
      *(v3 - 6) = v4;
      *(v3 - 3) = v5;
      v6 = *(v3 - 5);
      *(v3 - 5) = *(v3 - 4);
      *(v3 - 4) = v6;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 893
// RVA: 0xB3B8B0
__int64 __fastcall hkaQuantizedAnimationBuilder::quantize16(float value, hkaQuantizedAnimationBuilder::Range *range)
{
  hkSimdFloat32 v2; // xmm0
  __m128 v3; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm0

  v2.m_real = (__m128)range->m_span;
  v3 = _mm_rcp_ps(v2.m_real);
  v4 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v2.m_real, v3)), v3);
  v5 = 0i64;
  v5.m128_f32[0] = (float)0xFFFF;
  return (unsigned int)_mm_cvtsi128_si32(
                         _mm_cvttps_epi32(
                           _mm_min_ps(
                             _mm_max_ps(
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   v4,
                                   _mm_sub_ps(
                                     _mm_shuffle_ps((__m128)LODWORD(value), (__m128)LODWORD(value), 0),
                                     range->m_minimum.m_real)),
                                 _mm_shuffle_ps(v5, v5, 0)),
                               (__m128)0i64),
                             (__m128)_xmm)));
}

// File Line: 902
// RVA: 0xB3B910
void __fastcall hkaQuantizedAnimationBuilder::quantizeQuaternion(char *dst, hkQuaternionf *src)
{
  hkaSignedQuaternion::packSignedQuaternion48(src, dst);
}

// File Line: 907
// RVA: 0xB39950
__int64 __fastcall hkaQuantizedAnimation::getSizeInBytes(hkaQuantizedAnimation *this)
{
  return (unsigned int)this->m_data.m_size + 88i64;
}

