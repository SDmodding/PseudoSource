// File Line: 20
// RVA: 0xB39300
void __fastcall hkaQuantizedAnimation::hkaQuantizedAnimation(hkaQuantizedAnimation *this, hkaAnimationBinding *binding, hkaSkeleton *skeleton, hkaQuantizedAnimation::TrackCompressionParams *param)
{
  hkaAnimationBinding *v4; // r13
  hkaQuantizedAnimation::TrackCompressionParams *v5; // rbx
  hkaQuantizedAnimation *v6; // r14
  hkaQuantizedAnimation::TrackCompressionParams *v7; // r15
  __int64 v8; // rax
  __int64 v9; // rdi
  hkaQuantizedAnimation::TrackCompressionParams *v10; // r12
  int v11; // esi
  __int64 v12; // rdx
  _DWORD *v13; // rcx
  __int64 v14; // rax
  __int64 v15; // rbp
  int v16; // edi
  __int64 v17; // rdx
  _DWORD *v18; // rcx
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> floatParamsPerTrack; // [rsp+30h] [rbp-78h]
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> transformParamsPerTrack; // [rsp+40h] [rbp-68h]
  hkaQuantizedAnimationBuilder v21; // [rsp+50h] [rbp-58h]
  int v22; // [rsp+B0h] [rbp+8h]
  hkaSkeleton *skeletona; // [rsp+C0h] [rbp+18h]

  skeletona = skeleton;
  v4 = binding;
  v5 = param;
  v6 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, binding->m_animation.m_pntr);
  v7 = 0i64;
  v6->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable';
  v6->m_data.m_data = 0i64;
  v6->m_data.m_size = 0;
  v6->m_data.m_capacityAndFlags = 2147483648;
  v8 = v4->m_animation.m_pntr->m_numberOfTransformTracks;
  v9 = v8;
  if ( (_DWORD)v8 )
  {
    v22 = 16 * v8;
    v10 = (hkaQuantizedAnimation::TrackCompressionParams *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                             &v22);
    LODWORD(v8) = v22 / 16;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 2147483648;
  transformParamsPerTrack.m_data = v10;
  if ( (_DWORD)v8 )
    v11 = v8;
  transformParamsPerTrack.m_size = v9;
  v12 = v9;
  transformParamsPerTrack.m_capacityAndFlags = v11;
  if ( (signed int)v9 > 0 )
  {
    v13 = (_DWORD *)&v10->m_rotationTolerance;
    do
    {
      if ( v13 )
      {
        *v13 = LODWORD(v5->m_rotationTolerance);
        v13[1] = LODWORD(v5->m_translationTolerance);
        v13[2] = LODWORD(v5->m_scaleTolerance);
        v13[3] = LODWORD(v5->m_floatingTolerance);
      }
      v13 += 4;
      --v12;
    }
    while ( v12 );
  }
  v14 = v4->m_animation.m_pntr->m_numberOfFloatTracks;
  v15 = v14;
  if ( (_DWORD)v14 )
  {
    v22 = 16 * v14;
    v7 = (hkaQuantizedAnimation::TrackCompressionParams *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                            &v22);
    LODWORD(v14) = v22 / 16;
  }
  v16 = 2147483648;
  floatParamsPerTrack.m_data = v7;
  if ( (_DWORD)v14 )
    v16 = v14;
  floatParamsPerTrack.m_size = v15;
  v17 = v15;
  floatParamsPerTrack.m_capacityAndFlags = v16;
  if ( (signed int)v15 > 0 )
  {
    v18 = (_DWORD *)&v7->m_rotationTolerance;
    do
    {
      if ( v18 )
      {
        *v18 = LODWORD(v5->m_rotationTolerance);
        v18[1] = LODWORD(v5->m_translationTolerance);
        v18[2] = LODWORD(v5->m_scaleTolerance);
        v18[3] = LODWORD(v5->m_floatingTolerance);
      }
      v18 += 4;
      --v17;
    }
    while ( v17 );
  }
  hkaQuantizedAnimationBuilder::hkaQuantizedAnimationBuilder(&v21, v6);
  hkaQuantizedAnimationBuilder::initialize(&v21, v4, skeletona, &transformParamsPerTrack, &floatParamsPerTrack);
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v7,
      16 * v16);
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v10,
      16 * v11);
}

// File Line: 34
// RVA: 0xB39500
void __fastcall hkaQuantizedAnimation::hkaQuantizedAnimation(hkaQuantizedAnimation *this, hkaAnimationBinding *binding, hkaSkeleton *skeleton, hkaQuantizedAnimation::PerTrackCompressionParams *perTrackParams)
{
  hkaAnimationBinding *v4; // rsi
  hkaQuantizedAnimation *v5; // rbx
  __int64 v6; // r14
  unsigned int v7; // eax
  __int64 v8; // r12
  hkaQuantizedAnimation::TrackCompressionParams *v9; // rcx
  int v10; // ebp
  hkaQuantizedAnimation::TrackCompressionParams *v11; // rbx
  __int64 v12; // rdi
  unsigned int v13; // eax
  __int64 v14; // r15
  hkaQuantizedAnimation::TrackCompressionParams *v15; // r13
  int v16; // esi
  hkaQuantizedAnimation::TrackCompressionParams *v17; // rbx
  __int64 v18; // rdi
  hkaQuantizedAnimation::TrackCompressionParams *v19; // rdi
  __int64 v20; // r9
  __int64 v21; // r8
  __int64 v22; // r10
  _DWORD *v23; // rdx
  hkaQuantizedAnimation::TrackCompressionParams *v24; // r8
  __int64 v25; // r9
  float *v26; // rdx
  int v27; // [rsp+30h] [rbp-98h]
  hkaQuantizedAnimation::TrackCompressionParams *v28; // [rsp+38h] [rbp-90h]
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> floatParamsPerTrack; // [rsp+40h] [rbp-88h]
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> transformParamsPerTrack; // [rsp+50h] [rbp-78h]
  hkaQuantizedAnimationBuilder v31; // [rsp+60h] [rbp-68h]
  hkaQuantizedAnimation *anim; // [rsp+D0h] [rbp+8h]
  hkaAnimationBinding *bindinga; // [rsp+D8h] [rbp+10h]
  hkaSkeleton *skeletona; // [rsp+E0h] [rbp+18h]
  hkaQuantizedAnimation::PerTrackCompressionParams *v35; // [rsp+E8h] [rbp+20h]

  v35 = perTrackParams;
  skeletona = skeleton;
  bindinga = binding;
  anim = this;
  v4 = binding;
  v5 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, binding->m_animation.m_pntr);
  v6 = 0i64;
  v5->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable';
  v5->m_data.m_data = 0i64;
  v5->m_data.m_size = 0;
  v5->m_data.m_capacityAndFlags = 2147483648;
  v7 = v4->m_animation.m_pntr->m_numberOfTransformTracks;
  v8 = v7;
  if ( v7 )
  {
    v27 = 16 * v7;
    v9 = (hkaQuantizedAnimation::TrackCompressionParams *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                            &v27);
    v7 = v27 / 16;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = 2147483648;
  v28 = v9;
  if ( v7 )
    v10 = v7;
  transformParamsPerTrack.m_data = v9;
  transformParamsPerTrack.m_size = v8;
  transformParamsPerTrack.m_capacityAndFlags = v10;
  if ( (signed int)v8 > 0 )
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
  v13 = v4->m_animation.m_pntr->m_numberOfFloatTracks;
  v14 = v13;
  if ( v13 )
  {
    v27 = 16 * v13;
    v15 = (hkaQuantizedAnimation::TrackCompressionParams *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                             &v27);
    v13 = v27 / 16;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = 2147483648;
  floatParamsPerTrack.m_data = v15;
  if ( v13 )
    v16 = v13;
  floatParamsPerTrack.m_size = v14;
  floatParamsPerTrack.m_capacityAndFlags = v16;
  if ( (signed int)v14 > 0 )
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
  if ( (signed int)v8 > 0 )
  {
    v20 = 0i64;
    v21 = (__int64)v28;
    v22 = v8;
    do
    {
      v21 += 16i64;
      ++v20;
      v23 = (_DWORD *)&v35->m_parameterPalette.m_data[v35->m_trackIndexToPaletteIndex.m_data[v20 - 1]].m_rotationTolerance;
      *(_DWORD *)(v21 - 16) = *v23;
      *(_DWORD *)(v21 - 12) = v23[1];
      *(_DWORD *)(v21 - 8) = v23[2];
      *(_DWORD *)(v21 - 4) = v23[3];
      --v22;
    }
    while ( v22 );
  }
  if ( (signed int)v14 > 0 )
  {
    v24 = v15;
    v25 = v14;
    do
    {
      ++v24;
      ++v6;
      v26 = &v35->m_parameterPalette.m_data[v35->m_floatTrackIndexToPaletteIndex.m_data[v6 - 1]].m_rotationTolerance;
      v24[-1].m_rotationTolerance = *v26;
      v24[-1].m_translationTolerance = v26[1];
      v24[-1].m_scaleTolerance = v26[2];
      v24[-1].m_floatingTolerance = v26[3];
      --v25;
    }
    while ( v25 );
  }
  hkaQuantizedAnimationBuilder::hkaQuantizedAnimationBuilder(&v31, anim);
  hkaQuantizedAnimationBuilder::initialize(&v31, bindinga, skeletona, &transformParamsPerTrack, &floatParamsPerTrack);
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v15,
      16 * v16);
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v19,
      16 * v10);
}

// File Line: 67
// RVA: 0xB397D0
void __fastcall hkaQuantizedAnimation::hkaQuantizedAnimation(hkaQuantizedAnimation *this, hkaAnimationBinding *binding, hkaSkeleton *skeleton, hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> *transformParamsPerTrack, hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> *floatParamsPerTrack)
{
  hkaAnimationBinding *v5; // rdi
  hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> *v6; // r14
  hkaSkeleton *v7; // rbx
  hkaQuantizedAnimation *v8; // r15
  int v9; // er8
  int v10; // er8
  hkaQuantizedAnimationBuilder v11; // [rsp+30h] [rbp-38h]

  v5 = binding;
  v6 = transformParamsPerTrack;
  v7 = skeleton;
  v8 = this;
  hkaAnimation::hkaAnimation((hkaAnimation *)&this->vfptr, binding->m_animation.m_pntr);
  v8->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable';
  v8->m_data.m_data = 0i64;
  v8->m_data.m_size = 0;
  v8->m_data.m_capacityAndFlags = 2147483648;
  hkaQuantizedAnimationBuilder::hkaQuantizedAnimationBuilder(&v11, v8);
  hkaQuantizedAnimationBuilder::initialize(&v11, v5, v7, v6, floatParamsPerTrack);
  v9 = v6->m_capacityAndFlags;
  v6->m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v6->m_data,
      16 * v9);
  v6->m_data = 0i64;
  v6->m_capacityAndFlags = 2147483648;
  v10 = floatParamsPerTrack->m_capacityAndFlags;
  floatParamsPerTrack->m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      floatParamsPerTrack->m_data,
      16 * v10);
  floatParamsPerTrack->m_data = 0i64;
  floatParamsPerTrack->m_capacityAndFlags = 2147483648;
}

// File Line: 73
// RVA: 0xB398E0
void __fastcall hkaQuantizedAnimation::~hkaQuantizedAnimation(hkaQuantizedAnimation *this)
{
  hkaQuantizedAnimation *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable';
  v2 = this->m_data.m_capacityAndFlags;
  this->m_data.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_data.m_data,
      v2 & 0x3FFFFFFF);
  v1->m_data.m_data = 0i64;
  v1->m_data.m_capacityAndFlags = 2147483648;
  hkaAnimation::~hkaAnimation((hkaAnimation *)&v1->vfptr);
}

// File Line: 78
// RVA: 0xB39C40
void __fastcall hkaQuantizedAnimationBuilder::hkaQuantizedAnimationBuilder(hkaQuantizedAnimationBuilder *this, hkaQuantizedAnimation *anim)
{
  this->m_data = &anim->m_data;
  this->m_endian = &anim->m_endian;
  this->m_skeleton = &anim->m_skeleton;
  this->m_type = &anim->m_type;
}

// File Line: 88
// RVA: 0xB39C70
void __fastcall hkaQuantizedAnimationBuilder::initialize(hkaQuantizedAnimationBuilder *this, hkaAnimationBinding *binding, hkaSkeleton *skeleton, hkArray<hkaQuantizedAnimation::TrackCompressionParams,hkContainerHeapAllocator> *transformParamsPerTrack)
{
  hkaSkeleton *v4; // r12
  hkaAnimationBinding *v5; // rbx
  hkaAnimation *v6; // r15
  hkBaseObjectVtbl *v7; // rax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  hkaQuantizedAnimationBuilder::Range *v12; // r14
  unsigned int v13; // ecx
  int v14; // eax
  const float *v15; // r12
  const float *v16; // rsi
  const float *v17; // r13
  unsigned int v18; // ecx
  int v19; // eax
  int v20; // er15
  hkaQuantizedAnimationBuilder::Range *v21; // rdi
  __int64 v22; // r12
  int v23; // eax
  hkaQuantizedAnimationBuilder::Range *v24; // rdi
  __int64 v25; // rsi
  unsigned __int16 v26; // r13
  int v27; // edx
  __int16 v28; // ax
  unsigned __int16 v29; // di
  __int16 v30; // ax
  signed __int64 v31; // rsi
  signed __int64 v32; // r13
  float *v33; // rsi
  __int16 v34; // bx
  signed __int64 v35; // r13
  unsigned __int16 v36; // di
  __int16 v37; // r13
  unsigned __int16 v38; // si
  _QWORD *v39; // r13
  int v40; // er9
  __int16 v41; // r14
  int v42; // esi
  int v43; // ecx
  hkaQuantizedAnimationBuilder::Range *v44; // rax
  hkaQuantizedAnimationBuilder::Range *v45; // r8
  int v46; // eax
  int v47; // ecx
  __int64 v48; // rdx
  int v49; // eax
  int v50; // edx
  __int64 v51; // rdi
  int v52; // ecx
  int v53; // xmm0_4
  __int16 v54; // r13
  __int16 v55; // r12
  int v56; // esi
  int v57; // er14
  int v58; // edi
  int v59; // er15
  int v60; // ebx
  __int64 v61; // rdi
  hkaQuantizedAnimationBuilder *v62; // rbx
  hkArray<unsigned char,hkContainerHeapAllocator> *v63; // r8
  int v64; // er9
  int v65; // eax
  int v66; // eax
  hkaAnimation *v67; // r14
  int v68; // eax
  char *v69; // r14
  __int64 v70; // r13
  unsigned int v71; // esi
  int v72; // er15
  int v73; // er12
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
  hkaQuantizedAnimationBuilder::Range *rangeOut; // [rsp+40h] [rbp-80h]
  hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> v97; // [rsp+48h] [rbp-78h]
  int v98; // [rsp+58h] [rbp-68h]
  int n; // [rsp+5Ch] [rbp-64h]
  hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> dynamicElementsOut; // [rsp+60h] [rbp-60h]
  hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> v101; // [rsp+70h] [rbp-50h]
  hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> staticElementsOut; // [rsp+80h] [rbp-40h]
  int v103; // [rsp+90h] [rbp-30h]
  const float *v104; // [rsp+98h] [rbp-28h]
  int v105; // [rsp+A0h] [rbp-20h]
  int v106; // [rsp+A4h] [rbp-1Ch]
  hkaAnimation *v107; // [rsp+A8h] [rbp-18h]
  hkArray<unsigned char,hkContainerHeapAllocator> v108; // [rsp+B0h] [rbp-10h]
  __int64 v109; // [rsp+C0h] [rbp+0h]
  __int16 data; // [rsp+C8h] [rbp+8h]
  __int16 v111; // [rsp+CAh] [rbp+Ah]
  __int16 v112; // [rsp+CCh] [rbp+Ch]
  __int16 v113; // [rsp+CEh] [rbp+Eh]
  int v114; // [rsp+D0h] [rbp+10h]
  __int16 v115; // [rsp+D4h] [rbp+14h]
  __int16 v116; // [rsp+D6h] [rbp+16h]
  __int16 v117; // [rsp+D8h] [rbp+18h]
  __int16 v118; // [rsp+DAh] [rbp+1Ah]
  __int16 v119; // [rsp+DCh] [rbp+1Ch]
  __int16 v120; // [rsp+DEh] [rbp+1Eh]
  __int16 v121; // [rsp+E0h] [rbp+20h]
  __int16 v122; // [rsp+E2h] [rbp+22h]
  unsigned __int16 v123; // [rsp+E4h] [rbp+24h]
  __int16 v124; // [rsp+E6h] [rbp+26h]
  __int16 v125; // [rsp+E8h] [rbp+28h]
  __int16 v126; // [rsp+EAh] [rbp+2Ah]
  __int16 v127; // [rsp+ECh] [rbp+2Ch]
  __int16 v128; // [rsp+EEh] [rbp+2Eh]
  hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> v129; // [rsp+F0h] [rbp+30h]
  char buf; // [rsp+100h] [rbp+40h]
  hkaQuantizedAnimationBuilder *v131; // [rsp+360h] [rbp+2A0h]
  unsigned int numInOut[2]; // [rsp+368h] [rbp+2A8h]
  int v133; // [rsp+370h] [rbp+2B0h]
  _QWORD *v134; // [rsp+378h] [rbp+2B8h]
  _QWORD *v135; // [rsp+380h] [rbp+2C0h]

  *this->m_endian = 0;
  v4 = skeleton;
  this->m_type->m_storage = 4;
  v5 = binding;
  *this->m_skeleton = skeleton;
  v6 = binding->m_animation.m_pntr;
  v7 = v6->vfptr;
  v107 = binding->m_animation.m_pntr;
  v8 = ((__int64 (__fastcall *)(hkaAnimation *))v7[4].__vecDelDtor)(v107);
  staticElementsOut.m_data = 0i64;
  staticElementsOut.m_size = 0;
  n = v8;
  v9 = v4->m_bones.m_size;
  staticElementsOut.m_capacityAndFlags = 2147483648;
  v103 = v9;
  v98 = v4->m_floatSlots.m_size;
  dynamicElementsOut.m_data = 0i64;
  dynamicElementsOut.m_size = 0;
  dynamicElementsOut.m_capacityAndFlags = 2147483648;
  v97.m_data = 0i64;
  v97.m_size = 0;
  v97.m_capacityAndFlags = 2147483648;
  v101.m_data = 0i64;
  v101.m_size = 0;
  v101.m_capacityAndFlags = 2147483648;
  v10 = v6->m_numberOfTransformTracks;
  rangeOut = 0i64;
  v97.m_data = (hkaQuantizedAnimationBuilder::DynamicRotation *)0x8000000000000000i64;
  v129.m_data = 0i64;
  v11 = 12 * v10;
  v129.m_size = 0;
  v129.m_capacityAndFlags = 2147483648;
  if ( v11 )
  {
    v106 = 32 * v11;
    v12 = (hkaQuantizedAnimationBuilder::Range *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                   &v106);
    v11 = v106 / 32;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = 2147483648;
  if ( v11 )
    v13 = v11;
  v14 = v6->m_numberOfFloatTracks;
  LODWORD(v108.m_data) = v13;
  if ( v14 )
  {
    v105 = 32 * v14;
    rangeOut = (hkaQuantizedAnimationBuilder::Range *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                        &v105);
    v14 = v105 / 32;
  }
  else
  {
    rangeOut = 0i64;
  }
  v15 = v4->m_referencePose.m_data->m_translation.m_quad.m128_f32;
  v16 = (const float *)v6[1].vfptr;
  v17 = *(const float **)&v6[1].m_type.m_storage;
  v18 = 2147483648;
  v104 = v15;
  if ( v14 )
    v18 = v14;
  v19 = v6->m_numberOfTransformTracks;
  LODWORD(v109) = v18;
  if ( 12 * v19 > 0 )
  {
    v20 = 12 * v19;
    v21 = v12;
    v22 = (unsigned int)(12 * v19);
    do
    {
      hkaQuantizedAnimationBuilder::getRange(v21, v16, v20, n);
      ++v16;
      ++v21;
      --v22;
    }
    while ( v22 );
    v6 = v107;
    v15 = v104;
    v5 = *(hkaAnimationBinding **)numInOut;
  }
  v23 = v6->m_numberOfFloatTracks;
  if ( v23 > 0 )
  {
    v24 = rangeOut;
    v25 = (unsigned int)v23;
    do
    {
      hkaQuantizedAnimationBuilder::getRange(v24, v17, v6->m_numberOfFloatTracks, n);
      ++v17;
      ++v24;
      --v25;
    }
    while ( v25 );
    v5 = *(hkaAnimationBinding **)numInOut;
  }
  v26 = 0;
  LOWORD(v98) = 0;
  if ( v6->m_numberOfTransformTracks > 0 )
  {
    LOWORD(v27) = 0;
    LODWORD(v104) = 0;
    do
    {
      if ( v5->m_transformTrackToBoneIndices.m_size <= 0 )
        v28 = v26;
      else
        v28 = v5->m_transformTrackToBoneIndices.m_data[v26];
      LOWORD(v133) = v28;
      v29 = v27;
      v30 = v28 - v26;
      v31 = 16i64 * v26;
      v32 = 3i64;
      v33 = (float *)(*v134 + v31);
      v34 = 12 * v30;
      do
      {
        hkaQuantizedAnimationBuilder::identifyScalarElements(
          v29,
          v29 + v34,
          v12,
          v15,
          v33[1],
          &staticElementsOut,
          &dynamicElementsOut);
        ++v29;
        --v32;
      }
      while ( v32 );
      v35 = 3i64;
      v36 = (_WORD)v104 + 8;
      do
      {
        hkaQuantizedAnimationBuilder::identifyScalarElements(
          v36,
          v34 + v36,
          v12,
          v15,
          v33[2],
          &staticElementsOut,
          &dynamicElementsOut);
        ++v36;
        --v35;
      }
      while ( v35 );
      v37 = v98;
      hkaQuantizedAnimationBuilder::identifyRotations(
        v98,
        v133,
        v12,
        v15,
        *v33,
        (hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *)&dynamicElementsOut,
        &v97);
      HIWORD(v27) = WORD1(v104);
      v5 = *(hkaAnimationBinding **)numInOut;
      v26 = v37 + 1;
      LOWORD(v27) = (_WORD)v104 + 12;
      LODWORD(v104) = v27;
      LOWORD(v98) = v26;
    }
    while ( v26 < v6->m_numberOfTransformTracks );
  }
  v38 = 0;
  if ( v6->m_numberOfFloatTracks > 0 )
  {
    v39 = v135;
    do
    {
      hkaQuantizedAnimationBuilder::identifyScalarElements(
        v38,
        v5->m_floatTrackToFloatSlotIndices.m_data[v38],
        rangeOut,
        0i64,
        *(float *)(*v39 + 16i64 * v38 + 12),
        &v101,
        (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v101);
      ++v38;
    }
    while ( v38 < v6->m_numberOfFloatTracks );
  }
  if ( (signed int)v109 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      rangeOut,
      32 * v109);
  if ( SLODWORD(v108.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v12,
      32 * LODWORD(v108.m_data));
  v40 = v103;
  v41 = v98;
  v42 = v98 + v103;
  v43 = v98 + v103;
  if ( v98 + v103 )
  {
    numInOut[0] = v98 + v103;
    v44 = (hkaQuantizedAnimationBuilder::Range *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                   (int *)numInOut);
    v43 = numInOut[0];
    v40 = v103;
    v45 = v44;
  }
  else
  {
    v45 = 0i64;
  }
  v46 = 2147483648;
  rangeOut = v45;
  if ( v43 )
    v46 = v43;
  v108.m_data = (char *)v45;
  v108.m_size = v42;
  v98 = v46;
  v108.m_capacityAndFlags = v46;
  if ( v42 > 0 )
    memset(v45, 0, v42);
  v47 = 0;
  if ( v6->m_numberOfTransformTracks > 0 )
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
      v45->m_minimum.m_real.m128_i8[v49] = -1;
    }
    while ( v47 < v6->m_numberOfTransformTracks );
  }
  v50 = 0;
  if ( v6->m_numberOfFloatTracks > 0 )
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
      v45->m_minimum.m_real.m128_i8[v52 + v40] = -1;
    }
    while ( v50 < v6->m_numberOfFloatTracks );
  }
  v53 = LODWORD(v6->m_duration);
  v54 = dynamicElementsOut.m_size;
  v55 = v101.m_size;
  v113 = n;
  v114 = v53;
  v115 = staticElementsOut.m_size;
  v116 = dynamicElementsOut.m_size;
  v118 = v101.m_size;
  v111 = v40;
  v120 = v97.m_size;
  v112 = v41;
  v117 = 0;
  v119 = dynamicElementsOut.m_size;
  v121 = 0;
  numInOut[0] = v42 + 40;
  v122 = v101.m_size;
  hkaQuantizedAnimationBuilder::align(numInOut, 2);
  v56 = staticElementsOut.m_size;
  v57 = v101.m_size;
  v58 = dynamicElementsOut.m_size;
  v124 = numInOut[0];
  numInOut[0] += 2 * (dynamicElementsOut.m_size + staticElementsOut.m_size + v101.m_size);
  hkaQuantizedAnimationBuilder::align(numInOut, 2);
  v59 = v101.m_size;
  v60 = dynamicElementsOut.m_size;
  v125 = numInOut[0];
  numInOut[0] += 2 * (dynamicElementsOut.m_size + v101.m_size + v97.m_size);
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  v126 = numInOut[0];
  numInOut[0] += 4 * v56 + 6 * v58;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  numInOut[0] += 4 * v57;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  v60 *= 4;
  v127 = numInOut[0];
  numInOut[0] += v60;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  numInOut[0] += 4 * v59;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  v128 = numInOut[0];
  numInOut[0] += v60;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  numInOut[0] += 4 * v59;
  hkaQuantizedAnimationBuilder::align(numInOut, 16);
  v61 = (unsigned int)n;
  v62 = v131;
  v63 = v131->m_data;
  data = numInOut[0];
  v123 = (2 * (v54 + v55 + 3 * LOWORD(v97.m_size)) + 15) & 0xFFF0;
  v64 = LOWORD(numInOut[0]) + (unsigned __int16)n * v123;
  v65 = v63->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v65 < v64 )
  {
    v66 = 2 * v65;
    if ( v64 < v66 )
      v64 = v66;
    hkArrayUtil::_reserve(
      (hkResult *)numInOut,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v63,
      v64,
      1);
  }
  hkaQuantizedAnimationBuilder::appendData(v62, &data, 40);
  hkaQuantizedAnimationBuilder::appendData(v62, &v108);
  hkaQuantizedAnimationBuilder::appendElements(v62, &staticElementsOut);
  hkaQuantizedAnimationBuilder::appendElements(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *)&rangeOut);
  hkaQuantizedAnimationBuilder::appendElements(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *)&dynamicElementsOut);
  hkaQuantizedAnimationBuilder::appendElements(v62, &v101);
  hkaQuantizedAnimationBuilder::appendElements(v62, &dynamicElementsOut);
  hkaQuantizedAnimationBuilder::appendElements(v62, &v129);
  hkaQuantizedAnimationBuilder::appendElements(v62, &v97);
  hkaQuantizedAnimationBuilder::appendElements(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v101);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendValues(v62, &staticElementsOut);
  hkaQuantizedAnimationBuilder::appendValues(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *)&rangeOut);
  hkaQuantizedAnimationBuilder::appendValues(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *)&dynamicElementsOut);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendValues(v62, &v101);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendRangeMinimums(v62, &dynamicElementsOut);
  hkaQuantizedAnimationBuilder::appendRangeMinimums(v62, &v129);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendRangeMinimums(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v101);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendRangeSpans(v62, &dynamicElementsOut);
  hkaQuantizedAnimationBuilder::appendRangeSpans(v62, &v129);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::appendRangeSpans(
    v62,
    (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v101);
  hkaQuantizedAnimationBuilder::align(v62, 16);
  v67 = v107;
  v108.m_data = (char *)v107[1].vfptr;
  v109 = *(_QWORD *)&v107[1].m_type.m_storage;
  v68 = v107->m_numberOfTransformTracks;
  LODWORD(v131) = 3 * v68;
  numInOut[0] = 12 * v68;
  v133 = v107->m_numberOfFloatTracks;
  if ( (_DWORD)v61 )
  {
    v69 = v108.m_data;
    v70 = v61;
    v71 = 0;
    v72 = 0;
    v73 = 0;
    do
    {
      hkaQuantizedAnimationBuilder::align(v62, 16);
      hkaQuantizedAnimationBuilder::appendValues(v62, &dynamicElementsOut, (const float *)&v69[4 * v73]);
      hkaQuantizedAnimationBuilder::appendValues(v62, &v129, (const float *)&v69[4 * v73]);
      hkaQuantizedAnimationBuilder::appendValues(v62, &v97, (hkQuaternionf *)&v69[16 * v72]);
      hkaQuantizedAnimationBuilder::appendValues(
        v62,
        (hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *)&v101,
        (const float *)(v109 + 4i64 * v71));
      hkaQuantizedAnimationBuilder::align(v62, 16);
      v73 += numInOut[0];
      v72 += (signed int)v131;
      v71 += v133;
      --v70;
    }
    while ( v70 );
    v67 = v107;
  }
  hkaQuantizedAnimationBuilder::align(v62, 16);
  hkaQuantizedAnimationBuilder::align(v62, 64);
  v74 = ((__int64 (__fastcall *)(hkaAnimation *))v67->vfptr[3].__first_virtual_table_function__)(v67);
  v75 = v62->m_data->m_size + 88;
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    510016177i64,
    "Compression");
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v76 = hkOstream::operator<<((hkOstream *)&rangeOut, "Original Size ");
  hkOstream::operator<<(v76, v74);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 396);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v77 = hkOstream::operator<<((hkOstream *)&rangeOut, " Compressed Size ");
  hkOstream::operator<<(v77, v75);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 397);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v78 = hkOstream::operator<<((hkOstream *)&rangeOut, "Compression Ratio: ");
  v79 = hkOstream::operator<<(v78, (float)v74 / (float)v75);
  hkOstream::operator<<(v79, ":1");
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 398);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v80 = 3 * *(_DWORD *)&v67[1].m_memSizeAndFlags - staticElementsOut.m_size - dynamicElementsOut.m_size;
  v81 = hkOstream::operator<<((hkOstream *)&rangeOut, "Reference Translations: ");
  hkOstream::operator<<(v81, v80);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 400);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v82 = 3 * *(_DWORD *)&v67[1].m_memSizeAndFlags - v97.m_size - dynamicElementsOut.m_size;
  v83 = hkOstream::operator<<((hkOstream *)&rangeOut, "Reference Rotations:    ");
  hkOstream::operator<<(v83, v82);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 401);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v84 = 3 * *(_DWORD *)&v67[1].m_memSizeAndFlags;
  v85 = hkOstream::operator<<((hkOstream *)&rangeOut, "Reference Scales:       ");
  hkOstream::operator<<(v85, v84);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 402);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v86 = v67[1].m_numberOfTransformTracks - v101.m_size - v101.m_size;
  v87 = hkOstream::operator<<((hkOstream *)&rangeOut, "Reference Floats:       ");
  hkOstream::operator<<(v87, v86);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 403);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v88 = hkOstream::operator<<((hkOstream *)&rangeOut, "Static Translations:   ");
  hkOstream::operator<<(v88, staticElementsOut.m_size);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 405);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v89 = hkOstream::operator<<((hkOstream *)&rangeOut, "Static Rotations:      ");
  hkOstream::operator<<(v89, dynamicElementsOut.m_size);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 406);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v90 = hkOstream::operator<<((hkOstream *)&rangeOut, "Static Scales:         ");
  hkOstream::operator<<(v90, 0);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 407);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v91 = hkOstream::operator<<((hkOstream *)&rangeOut, "Static Floats:         ");
  hkOstream::operator<<(v91, v101.m_size);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 408);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v92 = hkOstream::operator<<((hkOstream *)&rangeOut, "Dynamic Translations:  ");
  hkOstream::operator<<(v92, dynamicElementsOut.m_size);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 410);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v93 = hkOstream::operator<<((hkOstream *)&rangeOut, "Dynamic Rotations:     ");
  hkOstream::operator<<(v93, v97.m_size);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 411);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v94 = hkOstream::operator<<((hkOstream *)&rangeOut, "Dynamic Scales:        ");
  hkOstream::operator<<(v94, 0);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 412);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  hkErrStream::hkErrStream((hkErrStream *)&rangeOut, &buf, 512);
  v95 = hkOstream::operator<<((hkOstream *)&rangeOut, "Dynamic Floats:        ");
  hkOstream::operator<<(v95, v101.m_size);
  hkError::messageReport(-1, &buf, "Animation\\Quantized\\hkaQuantizedAnimationCtor.cpp", 413);
  hkOstream::~hkOstream((hkOstream *)&rangeOut);
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
  if ( v98 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      rangeOut,
      v98 & 0x3FFFFFFF);
  v101.m_size = 0;
  if ( v101.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v101.m_data,
      48 * (v101.m_capacityAndFlags & 0x3FFFFFFF));
  v101.m_data = 0i64;
  v101.m_capacityAndFlags = 2147483648;
  v97.m_size = 0;
  if ( v97.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v97.m_data,
      4 * v97.m_capacityAndFlags);
  v97.m_data = 0i64;
  v97.m_capacityAndFlags = 2147483648;
  dynamicElementsOut.m_size = 0;
  if ( dynamicElementsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      dynamicElementsOut.m_data,
      48 * (dynamicElementsOut.m_capacityAndFlags & 0x3FFFFFFF));
  dynamicElementsOut.m_data = 0i64;
  dynamicElementsOut.m_capacityAndFlags = 2147483648;
  v101.m_size = 0;
  if ( v101.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v101.m_data,
      32 * v101.m_capacityAndFlags);
  v101.m_data = 0i64;
  v101.m_capacityAndFlags = 2147483648;
  dynamicElementsOut.m_size = 0;
  if ( dynamicElementsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      dynamicElementsOut.m_data,
      32 * dynamicElementsOut.m_capacityAndFlags);
  dynamicElementsOut.m_data = 0i64;
  dynamicElementsOut.m_capacityAndFlags = 2147483648;
  staticElementsOut.m_size = 0;
  if ( staticElementsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      staticElementsOut.m_data,
      32 * staticElementsOut.m_capacityAndFlags);
}namicElementsOut.m_size = 0;
  if ( dynamicElementsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocat

// File Line: 420
// RVA: 0xB3ACF0
void __fastcall hkaQuantizedAnimationBuilder::getRange(hkaQuantizedAnimationBuilder::Range *rangeOut, const float *base, int stride, int n)
{
  hkaQuantizedAnimationBuilder::getRange(&rangeOut->m_minimum, &rangeOut->m_span, base, stride, n);
}

// File Line: 425
// RVA: 0xB3AD20
void __fastcall hkaQuantizedAnimationBuilder::getRange(hkSimdFloat32 *minimumOut, hkSimdFloat32 *spanOut, const float *base, int stride, int n)
{
  hkSimdFloat32 v5; // xmm3
  __m128 v6; // xmm2
  __int64 v7; // rax
  __int64 v8; // r9
  signed __int64 v9; // rax
  __m128 v10; // xmm1
  __m128 v11; // xmm1

  v5.m_real = (__m128)xmmword_141A712A0;
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
      v5.m_real = _mm_min_ps(v11, v5.m_real);
      --v8;
    }
    while ( v8 );
  }
  *minimumOut = (hkSimdFloat32)v5.m_real;
  spanOut->m_real = _mm_sub_ps(v6, v5.m_real);
}

// File Line: 451
// RVA: 0xB3AD80
void __fastcall hkaQuantizedAnimationBuilder::identifyScalarElements(unsigned __int16 trackElement, unsigned __int16 boneElement, hkaQuantizedAnimationBuilder::Range *rangeBase, const float *referenceBase, float tol, hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *staticElementsOut, hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *dynamicElementsOut)
{
  hkaQuantizedAnimationBuilder::Range *v7; // r10
  __m128 v8; // xmm1
  float v9; // xmm1_4
  __m128 v10; // xmm6
  float v11; // xmm2_4
  __m128 v12; // xmm3
  _DWORD *v13; // rbx
  __m128 v14; // xmm6
  hkaQuantizedAnimationBuilder::StaticScalar *v15; // rax
  __m128 v16; // xmm7
  hkaQuantizedAnimationBuilder::DynamicScalar *v17; // rcx
  __int128 v18; // [rsp+30h] [rbp-48h]
  __int128 v19; // [rsp+40h] [rbp-38h]

  v7 = &rangeBase[trackElement];
  if ( referenceBase )
  {
    v8 = (__m128)LODWORD(referenceBase[boneElement]);
    LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(v8, v8, 0);
  }
  else
  {
    v9 = 0.0;
  }
  v10 = v7->m_span.m_real;
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(tol), (__m128)LODWORD(tol), 0);
  if ( v10.m128_f32[0] > (float)(v11 + v11) )
  {
    v13 = dynamicElementsOut;
    v16 = v7->m_minimum.m_real;
    WORD1(v19) = boneElement;
    LOWORD(v19) = trackElement;
    if ( dynamicElementsOut->m_size == (dynamicElementsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, dynamicElementsOut, 48);
    v17 = &dynamicElementsOut->m_data[dynamicElementsOut->m_size];
    if ( v17 )
    {
      v17->m_range.m_minimum.m_real = v16;
      v17->m_range.m_span.m_real = v10;
      *(_OWORD *)&v17->m_trackElement = v19;
    }
LABEL_16:
    ++v13[2];
    return;
  }
  if ( !referenceBase
    || COERCE_FLOAT(*(_OWORD *)&v7->m_minimum) < (float)(v9 - v11)
    || (v12 = v7->m_minimum.m_real, (float)(v12.m128_f32[0] + v10.m128_f32[0]) > (float)(v11 + v9)) )
  {
    v13 = staticElementsOut;
    LOWORD(v18) = boneElement;
    v14 = _mm_add_ps(_mm_mul_ps(v10, (__m128)xmmword_141A711B0), v7->m_minimum.m_real);
    if ( staticElementsOut->m_size == (staticElementsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, staticElementsOut, 32);
    v15 = &staticElementsOut->m_data[staticElementsOut->m_size];
    if ( v15 )
    {
      v15->m_value.m_real = v14;
      *(_OWORD *)&v15->m_boneElement = v18;
      ++staticElementsOut->m_size;
      return;
    }
    goto LABEL_16;
  }
}

// File Line: 491
// RVA: 0xB3AEE0
void __fastcall hkaQuantizedAnimationBuilder::identifyRotations(unsigned __int16 track, unsigned __int16 bone, hkaQuantizedAnimationBuilder::Range *rangeBase, const float *referenceBase, float tol, hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *staticElementsOut, hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *dynamicElementsOut)
{
  __m128 v7; // xmm6
  __int16 v8; // si
  float v9; // xmm5_4
  __m128 v10; // xmm7
  const float *v11; // r10
  __int16 v12; // di
  hkaQuantizedAnimationBuilder::Range *v13; // r11
  int v14; // ecx
  __int128 *v15; // r9
  int v16; // ebx
  int v17; // er8
  __int64 v18; // rdx
  signed __int64 v19; // rcx
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  float v22; // xmm3_4
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  signed int *v25; // rbx
  __m128 v26; // xmm6
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm6
  __m128 *v32; // rax
  _DWORD *v33; // rdx
  __m128 v34; // [rsp+20h] [rbp-50h]
  __m128 v35; // [rsp+30h] [rbp-40h]
  int v36; // [rsp+90h] [rbp+20h]
  int v37; // [rsp+98h] [rbp+28h]

  v7 = v34;
  v8 = 2 * track + track + 1;
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(tol), (__m128)LODWORD(tol), 0);
  v10 = v34;
  v11 = referenceBase;
  v12 = 2 * bone + bone + 1;
  v13 = rangeBase;
  v36 = 0;
  v14 = 12 * track;
  v37 = 0;
  v15 = &`hkVector4f::getComponent'::`2'::indexToMask;
  v16 = -4 - v14;
  v17 = v14 + 4;
  v18 = 0i64;
  do
  {
    v19 = v17;
    v20 = (__m128)LODWORD(v11[v17]);
    v21 = v13[v19].m_span.m_real;
    LODWORD(v22) = (unsigned __int128)_mm_shuffle_ps(v20, v20, 0);
    if ( v21.m128_f32[0] > (float)(v9 + v9) )
    {
      v25 = (signed int *)dynamicElementsOut;
      LOWORD(v36) = v8;
      HIWORD(v36) = v12;
      if ( dynamicElementsOut->m_size == (dynamicElementsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, dynamicElementsOut, 4);
      v33 = (_DWORD *)(*(_QWORD *)v25 + 4i64 * v25[2]);
      if ( v33 )
        *v33 = v36;
      goto LABEL_26;
    }
    v23 = v13[v19].m_minimum.m_real;
    if ( v23.m128_f32[0] >= (float)(v22 - v9) && (float)(v23.m128_f32[0] + v21.m128_f32[0]) <= (float)(v9 + v22) )
      *((_BYTE *)&v36 + v18) = 1;
    if ( v23.m128_f32[0] >= (float)((float)(0.0 - v22) - v9)
      && (float)(v23.m128_f32[0] + v21.m128_f32[0]) <= (float)((float)(0.0 - v22) + v9) )
    {
      *((_BYTE *)&v37 + v18) = 1;
    }
    v24 = (__m128)*v15;
    ++v17;
    ++v18;
    ++v15;
    v10 = _mm_or_ps(_mm_andnot_ps(v24, v10), _mm_and_ps(v23, v24));
    v7 = _mm_or_ps(_mm_andnot_ps(v24, v7), _mm_and_ps(v21, v24));
  }
  while ( v16 + v17 < 4 );
  if ( (!(_BYTE)v36 || !BYTE1(v36) || !BYTE2(v36) || !HIBYTE(v36))
    && (!(_BYTE)v37 || !BYTE1(v37) || !BYTE2(v37) || !HIBYTE(v37)) )
  {
    v25 = (signed int *)staticElementsOut;
    v35.m128_i16[0] = v12;
    v26 = _mm_add_ps(_mm_mul_ps(v7, (__m128)xmmword_141A711B0), v10);
    v27 = _mm_mul_ps(v26, v26);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
    v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28);
    v30 = _mm_rsqrt_ps(v29);
    v31 = _mm_mul_ps(
            v26,
            _mm_andnot_ps(
              _mm_cmpleps(v29, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                _mm_mul_ps(*(__m128 *)_xmm, v30))));
    if ( staticElementsOut->m_size == (staticElementsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, staticElementsOut, 32);
    v32 = (__m128 *)(*(_QWORD *)v25 + 32i64 * v25[2]);
    if ( v32 )
    {
      *v32 = v31;
      v32[1] = v35;
    }
LABEL_26:
    ++v25[2];
  }
}

// File Line: 567
// RVA: 0xB392D0
void __fastcall hkaQuantizedAnimation::TrackCompressionParams::TrackCompressionParams(hkaQuantizedAnimation::TrackCompressionParams *this)
{
  this->m_floatingTolerance = 0.000099999997;
  this->m_scaleTolerance = 0.000099999997;
  this->m_translationTolerance = 0.000099999997;
  this->m_rotationTolerance = 0.000099999997;
}

// File Line: 572
// RVA: 0xB3B210
void __fastcall hkaQuantizedAnimationBuilder::appendData(hkaQuantizedAnimationBuilder *this, const void *data, int size)
{
  __int64 v3; // rsi
  const void *v4; // rbp
  hkaQuantizedAnimationBuilder *v5; // r14
  hkArray<unsigned char,hkContainerHeapAllocator> *v6; // rdi
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // er9
  hkResult result; // [rsp+60h] [rbp+18h]

  v3 = size;
  v4 = data;
  v5 = this;
  hkaQuantizedAnimationBuilder::align(this, size);
  v6 = v5->m_data;
  v7 = v3 + v5->m_data->m_size;
  v8 = v5->m_data->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = v3 + v5->m_data->m_size;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5->m_data, v10, 1);
  }
  v6->m_size = v7;
  hkString::memCpy(&v5->m_data->m_data[v5->m_data->m_size - v3], v4, v3);
}

// File Line: 584
// RVA: 0xB3B2C0
void __fastcall hkaQuantizedAnimationBuilder::appendData(hkaQuantizedAnimationBuilder *this, const unsigned int *val)
{
  const unsigned int *v2; // rbx
  hkaQuantizedAnimationBuilder *v3; // rdi

  v2 = val;
  v3 = this;
  hkaQuantizedAnimationBuilder::align(this, 4);
  hkaQuantizedAnimationBuilder::appendData(v3, v2, 4);
}

// File Line: 591
// RVA: 0xB3B330
void __fastcall hkaQuantizedAnimationBuilder::appendData(hkaQuantizedAnimationBuilder *this, hkArray<unsigned char,hkContainerHeapAllocator> *data)
{
  int v2; // esi
  hkArray<unsigned char,hkContainerHeapAllocator> *v3; // r14
  hkaQuantizedAnimationBuilder *v4; // rbp
  __int64 i; // rdi
  hkArray<unsigned char,hkContainerHeapAllocator> *v6; // rbx
  char *v7; // r15
  char v8; // al

  v2 = 0;
  v3 = data;
  v4 = this;
  for ( i = 0i64; v2 < v3->m_size; ++v6->m_size )
  {
    v6 = v4->m_data;
    v7 = v3->m_data;
    if ( v4->m_data->m_size == (v4->m_data->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4->m_data, 1);
    v8 = v7[i];
    ++v2;
    ++i;
    v6->m_data[v6->m_size] = v8;
  }
}

// File Line: 601
// RVA: 0xB3B3D0
void __fastcall hkaQuantizedAnimationBuilder::appendElements(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *data)
{
  hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *v2; // rdi
  hkaQuantizedAnimationBuilder *v3; // rsi
  int i; // ebx

  v2 = data;
  v3 = this;
  hkaQuantizedAnimationBuilder::align(this, 2);
  for ( i = 0; i < v2->m_size; ++i )
    hkaQuantizedAnimationBuilder::appendData(v3, &v2->m_data[i].m_boneElement);
}

// File Line: 613
// RVA: 0xB3B440
void __fastcall hkaQuantizedAnimationBuilder::appendElements(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *data)
{
  hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *v2; // rdi
  hkaQuantizedAnimationBuilder *v3; // rsi
  int i; // ebx

  v2 = data;
  v3 = this;
  hkaQuantizedAnimationBuilder::align(this, 2);
  for ( i = 0; i < v2->m_size; ++i )
    hkaQuantizedAnimationBuilder::appendData(v3, &v2->m_data[i].m_boneElement);
}

// File Line: 625
// RVA: 0xB3B4B0
void __fastcall hkaQuantizedAnimationBuilder::appendElements(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *data)
{
  hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *v2; // rdi
  hkaQuantizedAnimationBuilder *v3; // rsi
  int i; // ebx

  v2 = data;
  v3 = this;
  hkaQuantizedAnimationBuilder::align(this, 2);
  for ( i = 0; i < v2->m_size; ++i )
    hkaQuantizedAnimationBuilder::appendData(v3, &v2->m_data[i].m_boneElement);
}

// File Line: 637
// RVA: 0xB3B520
void __fastcall hkaQuantizedAnimationBuilder::appendElements(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *data)
{
  hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *v2; // rdi
  hkaQuantizedAnimationBuilder *v3; // rsi
  int i; // ebx

  v2 = data;
  v3 = this;
  hkaQuantizedAnimationBuilder::align(this, 2);
  for ( i = 0; i < v2->m_size; ++i )
    hkaQuantizedAnimationBuilder::appendData(v3, &v2->m_data[i].m_boneElement);
}

// File Line: 649
// RVA: 0xB3B590
void __fastcall hkaQuantizedAnimationBuilder::appendValues(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *data)
{
  hkArray<hkaQuantizedAnimationBuilder::StaticScalar,hkContainerHeapAllocator> *v2; // rsi
  hkaQuantizedAnimationBuilder *v3; // rbp
  int v4; // ebx
  __int64 v5; // rdi
  float value; // [rsp+38h] [rbp+10h]

  v2 = data;
  v3 = this;
  hkaQuantizedAnimationBuilder::align(this, 4);
  v4 = 0;
  if ( v2->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      LODWORD(value) = v2->m_data[v5].m_value;
      hkaQuantizedAnimationBuilder::appendData(v3, &value);
      ++v4;
      ++v5;
    }
    while ( v4 < v2->m_size );
  }
}

// File Line: 662
// RVA: 0xB3B600
void __fastcall hkaQuantizedAnimationBuilder::appendValues(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *data)
{
  int v2; // ebx
  hkArray<hkaQuantizedAnimationBuilder::StaticRotation,hkContainerHeapAllocator> *v3; // rsi
  hkaQuantizedAnimationBuilder *i; // rdi
  unsigned __int16 dst; // [rsp+38h] [rbp+10h]
  unsigned __int16 value; // [rsp+3Ah] [rbp+12h]
  unsigned __int16 v7; // [rsp+3Ch] [rbp+14h]

  v2 = 0;
  v3 = data;
  for ( i = this; v2 < v3->m_size; ++v2 )
  {
    hkaQuantizedAnimationBuilder::quantizeQuaternion(&dst, &v3->m_data[v2].m_value);
    hkaQuantizedAnimationBuilder::appendData(i, &dst);
    hkaQuantizedAnimationBuilder::appendData(i, &value);
    hkaQuantizedAnimationBuilder::appendData(i, &v7);
  }
}

// File Line: 677
// RVA: 0xB3B680
void __fastcall hkaQuantizedAnimationBuilder::appendRangeMinimums(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *data)
{
  hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *v2; // rsi
  hkaQuantizedAnimationBuilder *v3; // rbp
  int v4; // ebx
  __int64 v5; // rdi
  float value; // [rsp+38h] [rbp+10h]

  v2 = data;
  v3 = this;
  hkaQuantizedAnimationBuilder::align(this, 4);
  v4 = 0;
  if ( v2->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      LODWORD(value) = v2->m_data[v5].m_range.m_minimum;
      hkaQuantizedAnimationBuilder::appendData(v3, &value);
      ++v4;
      ++v5;
    }
    while ( v4 < v2->m_size );
  }
}

// File Line: 689
// RVA: 0xB3B6F0
void __fastcall hkaQuantizedAnimationBuilder::appendRangeSpans(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *data)
{
  hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *v2; // rsi
  hkaQuantizedAnimationBuilder *v3; // rbp
  int v4; // ebx
  float v5; // xmm6_4
  __int64 v6; // rdi
  float value; // [rsp+48h] [rbp+10h]

  v2 = data;
  v3 = this;
  hkaQuantizedAnimationBuilder::align(this, 4);
  v4 = 0;
  value = FLOAT_0_000015259022;
  LODWORD(v5) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_0_000015259022),
                                     (__m128)LODWORD(FLOAT_0_000015259022),
                                     0);
  if ( v2->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      value = v2->m_data[v6].m_range.m_span.m_real.m128_f32[0] * v5;
      hkaQuantizedAnimationBuilder::appendData(v3, &value);
      ++v4;
      ++v6;
    }
    while ( v4 < v2->m_size );
  }
}

// File Line: 703
// RVA: 0xB3B790
void __fastcall hkaQuantizedAnimationBuilder::appendValues(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *data, const float *base)
{
  int v3; // ebx
  const float *v4; // rbp
  hkArray<hkaQuantizedAnimationBuilder::DynamicScalar,hkContainerHeapAllocator> *v5; // rsi
  hkaQuantizedAnimationBuilder *v6; // r14
  __int64 v7; // rdi
  unsigned __int16 value; // [rsp+48h] [rbp+10h]

  v3 = 0;
  v4 = base;
  v5 = data;
  v6 = this;
  if ( data->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      value = hkaQuantizedAnimationBuilder::quantize16(v4[v5->m_data[v7].m_trackElement], &v5->m_data[v7].m_range);
      hkaQuantizedAnimationBuilder::appendData(v6, &value);
      ++v3;
      ++v7;
    }
    while ( v3 < v5->m_size );
  }
}

// File Line: 718
// RVA: 0xB3B810
void __fastcall hkaQuantizedAnimationBuilder::appendValues(hkaQuantizedAnimationBuilder *this, hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *data, hkQuaternionf *base)
{
  int v3; // ebx
  hkQuaternionf *v4; // rbp
  hkArray<hkaQuantizedAnimationBuilder::DynamicRotation,hkContainerHeapAllocator> *v5; // r14
  hkaQuantizedAnimationBuilder *v6; // rsi
  __int64 v7; // rdi
  unsigned __int16 dst; // [rsp+48h] [rbp+10h]
  unsigned __int16 value; // [rsp+4Ah] [rbp+12h]
  unsigned __int16 v10; // [rsp+4Ch] [rbp+14h]

  v3 = 0;
  v4 = base;
  v5 = data;
  v6 = this;
  if ( data->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      hkaQuantizedAnimationBuilder::quantizeQuaternion(&dst, &v4[v5->m_data[v7].m_trackElement]);
      hkaQuantizedAnimationBuilder::appendData(v6, &dst);
      hkaQuantizedAnimationBuilder::appendData(v6, &value);
      hkaQuantizedAnimationBuilder::appendData(v6, &v10);
      ++v3;
      ++v7;
    }
    while ( v3 < v5->m_size );
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
  hkaQuantizedAnimationBuilder *v2; // rsi
  int v3; // ecx
  int v4; // er8
  __int64 v5; // rdi
  hkArray<unsigned char,hkContainerHeapAllocator> *v6; // rbx

  v2 = this;
  v3 = this->m_data->m_size;
  v4 = ~(size - 1) & (v3 + size - 1);
  if ( v3 < v4 )
  {
    v5 = (unsigned int)(v4 - v3);
    do
    {
      v6 = v2->m_data;
      if ( v2->m_data->m_size == (v2->m_data->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2->m_data, 1);
      v6->m_data[v6->m_size++] = 0;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 753
// RVA: 0xB3B2A0
void __fastcall hkaQuantizedAnimationBuilder::appendData(hkaQuantizedAnimationBuilder *this, const unsigned __int16 *value)
{
  hkaQuantizedAnimationBuilder::appendData(this, value, 2);
}

// File Line: 758
// RVA: 0xB3B300
void __fastcall hkaQuantizedAnimationBuilder::appendData(hkaQuantizedAnimationBuilder *this, const float *value)
{
  int data; // [rsp+38h] [rbp+10h]

  data = *(_DWORD *)value;
  hkaQuantizedAnimationBuilder::appendData(this, &data, 4);
}

// File Line: 764
// RVA: 0xB39C00
void __fastcall hkaQuantizedAnimation::QuantizedAnimationHeader::swizzleEndian(hkaQuantizedAnimation::QuantizedAnimationHeader *this)
{
  hkaQuantizedAnimation::QuantizedAnimationHeader *v1; // rbx
  char v2; // dl
  char v3; // dl

  v1 = this;
  hkaQuantizedAnimation::swizzleEndian16(this, 20);
  v2 = LOBYTE(v1->m_duration);
  LOBYTE(v1->m_duration) = BYTE2(v1->m_duration);
  BYTE2(v1->m_duration) = v2;
  v3 = BYTE1(v1->m_duration);
  BYTE1(v1->m_duration) = HIBYTE(v1->m_duration);
  HIBYTE(v1->m_duration) = v3;
}

// File Line: 781
// RVA: 0xB39960
void __fastcall hkaQuantizedAnimation::handleEndian(hkaQuantizedAnimation *this)
{
  hkaQuantizedAnimation *v1; // rdi
  unsigned __int16 *v2; // rbx
  unsigned __int16 *v3; // rcx
  unsigned __int16 *v4; // r9
  signed int v5; // ebx
  unsigned __int16 *v6; // r9

  v1 = this;
  if ( this->m_endian )
  {
    hkaQuantizedAnimation::QuantizedAnimationHeader::swizzleEndian((hkaQuantizedAnimation::QuantizedAnimationHeader *)this->m_data.m_data);
    v2 = (unsigned __int16 *)v1->m_data.m_data;
    hkaQuantizedAnimation::swizzleEndian16((char *)v2 + v2[15], v2[6] + v2[7] + v2[8] + v2[9]);
    v3 = (unsigned __int16 *)v1->m_data.m_data;
    hkaQuantizedAnimation::swizzleEndian16((char *)v2 + v3[16], v3[10] + v3[11] + v3[12] + v3[13]);
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)v2 + *((unsigned __int16 *)v1->m_data.m_data + 17),
      *((unsigned __int16 *)v1->m_data.m_data + 6) + *((unsigned __int16 *)v1->m_data.m_data + 8));
    hkaQuantizedAnimation::swizzleEndian16(
      (char *)&v2[2 * *((unsigned __int16 *)v1->m_data.m_data + 6) + 2 * *((unsigned __int16 *)v1->m_data.m_data + 8)]
    + *((unsigned __int16 *)v1->m_data.m_data + 17),
      3 * *((unsigned __int16 *)v1->m_data.m_data + 7));
    v4 = (unsigned __int16 *)v1->m_data.m_data;
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)v2 + ((6 * v4[7] + 4 * (v4[6] + v4[8]) + 15i64) & 0xFFFFFFFFFFFFFFF0ui64) + v4[17],
      v4[9]);
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)v2 + *((unsigned __int16 *)v1->m_data.m_data + 18),
      *((unsigned __int16 *)v1->m_data.m_data + 10) + *((unsigned __int16 *)v1->m_data.m_data + 12));
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)v2
    + ((4 * (*((unsigned __int16 *)v1->m_data.m_data + 12) + *((unsigned __int16 *)v1->m_data.m_data + 10)) + 15i64) & 0xFFFFFFFFFFFFFFF0ui64)
    + *((unsigned __int16 *)v1->m_data.m_data + 18),
      *((unsigned __int16 *)v1->m_data.m_data + 13));
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)v2 + *((unsigned __int16 *)v1->m_data.m_data + 19),
      *((unsigned __int16 *)v1->m_data.m_data + 10) + *((unsigned __int16 *)v1->m_data.m_data + 12));
    hkaQuantizedAnimation::swizzleEndian32(
      (char *)v2
    + ((4 * (*((unsigned __int16 *)v1->m_data.m_data + 12) + *((unsigned __int16 *)v1->m_data.m_data + 10)) + 15i64) & 0xFFFFFFFFFFFFFFF0ui64)
    + *((unsigned __int16 *)v1->m_data.m_data + 19),
      *((unsigned __int16 *)v1->m_data.m_data + 13));
    v5 = 0;
    if ( *((_WORD *)v1->m_data.m_data + 3) > 0u )
    {
      do
      {
        v6 = (unsigned __int16 *)v1->m_data.m_data;
        hkaQuantizedAnimation::swizzleEndian16((char *)v6 + v5++ * v6[14] + *v6, v6[10] + v6[12] + v6[13] + 3 * v6[11]);
      }
      while ( v5 < *((unsigned __int16 *)v1->m_data.m_data + 3) );
    }
    v1->m_endian = 0;
  }
}

// File Line: 866
// RVA: 0xB39B80
void __fastcall hkaQuantizedAnimation::swizzleEndian16(void *valInOut, int n)
{
  __int64 v2; // rax
  __int64 v3; // r9
  char v4; // dl
  char v5; // r8

  v2 = 0i64;
  v3 = n;
  if ( n > 0 )
  {
    do
    {
      v4 = *((_BYTE *)valInOut + 2 * v2 + 1);
      v5 = *((_BYTE *)valInOut + 2 * v2++);
      *((char *)valInOut + 2 * v2 - 2) = v4;
      *((char *)valInOut + 2 * v2 - 1) = v5;
    }
    while ( v2 < v3 );
  }
}

// File Line: 877
// RVA: 0xB39BC0
void __fastcall hkaQuantizedAnimation::swizzleEndian32(void *valInOut, int n)
{
  __int64 v2; // r8
  char *v3; // rax
  char v4; // cl
  char v5; // dl
  char v6; // dl

  v2 = n;
  if ( n > 0 )
  {
    v3 = (char *)valInOut + 2;
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
  float v7; // [rsp+8h] [rbp+8h]

  v7 = value;
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
                                     _mm_shuffle_ps((__m128)LODWORD(v7), (__m128)LODWORD(v7), 0),
                                     range->m_minimum.m_real)),
                                 _mm_shuffle_ps(v5, v5, 0)),
                               (__m128)0i64),
                             (__m128)_xmm)));
}

// File Line: 902
// RVA: 0xB3B910
void __fastcall hkaQuantizedAnimationBuilder::quantizeQuaternion(unsigned __int16 *dst, hkQuaternionf *src)
{
  hkaSignedQuaternion::packSignedQuaternion48(src, (char *)dst);
}

// File Line: 907
// RVA: 0xB39950
signed __int64 __fastcall hkaQuantizedAnimation::getSizeInBytes(hkaQuantizedAnimation *this)
{
  return (unsigned int)this->m_data.m_size + 88i64;
}

