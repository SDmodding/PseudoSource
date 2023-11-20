// File Line: 66
// RVA: 0x1513EC0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::RagdollDefinition_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::RagdollDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::RagdollDefinition,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::RagdollDefinition>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 131
// RVA: 0x44D240
void __fastcall UFG::RagdollSkeletonMapper::RagdollSkeletonMapper(UFG::RagdollSkeletonMapper *this, int numSimpleMappings, int numChainMappings)
{
  int v3; // edi
  int v4; // esi
  UFG::RagdollSkeletonMapper *v5; // rbx
  hkArray<UFG::RagdollSkeletonMapper::UserMapping,hkContainerHeapAllocator> *v6; // r8
  hkResult result; // [rsp+68h] [rbp+10h]

  v3 = numChainMappings;
  v4 = numSimpleMappings;
  v5 = this;
  v6 = &this->m_userMappingsAtoB;
  v6->m_data = 0i64;
  v6->m_size = 0;
  v6->m_capacityAndFlags = 2147483648;
  this->m_userMappingsBtoA.m_data = 0i64;
  this->m_userMappingsBtoA.m_size = 0;
  this->m_userMappingsBtoA.m_capacityAndFlags = 2147483648;
  this->m_userChains.m_data = 0i64;
  this->m_userChains.m_size = 0;
  this->m_userChains.m_capacityAndFlags = 2147483648;
  if ( (this->m_userMappingsAtoB.m_capacityAndFlags & 0x3FFFFFFF) < numSimpleMappings )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v6,
      numSimpleMappings,
      8);
  if ( (v5->m_userMappingsBtoA.m_capacityAndFlags & 0x3FFFFFFF) < v4 )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_userMappingsBtoA,
      v4,
      8);
  if ( v3 )
  {
    if ( (v5->m_userChains.m_capacityAndFlags & 0x3FFFFFFF) < v3 )
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_userChains,
        v3,
        8);
  }
}

// File Line: 144
// RVA: 0x450E00
void __fastcall UFG::RagdollSkeletonMapper::~RagdollSkeletonMapper(UFG::RagdollSkeletonMapper *this)
{
  UFG::RagdollSkeletonMapper *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8

  v1 = this;
  this->m_userChains.m_size = 0;
  v2 = this->m_userChains.m_capacityAndFlags;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_userChains.m_data,
      8 * v2);
  v1->m_userChains.m_data = 0i64;
  v1->m_userChains.m_capacityAndFlags = 2147483648;
  v1->m_userMappingsBtoA.m_size = 0;
  v3 = v1->m_userMappingsBtoA.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_userMappingsBtoA.m_data,
      8 * v3);
  v1->m_userMappingsBtoA.m_data = 0i64;
  v1->m_userMappingsBtoA.m_capacityAndFlags = 2147483648;
  v1->m_userMappingsAtoB.m_size = 0;
  v4 = v1->m_userMappingsAtoB.m_capacityAndFlags;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_userMappingsAtoB.m_data,
      8 * v4);
  v1->m_userMappingsAtoB.m_capacityAndFlags = 2147483648;
  v1->m_userMappingsAtoB.m_data = 0i64;
}

// File Line: 150
// RVA: 0x455870
void __fastcall UFG::RagdollSkeletonMapper::AddSimpleMapping(UFG::RagdollSkeletonMapper *this, UFG::qSymbolUC *boneA, UFG::qSymbolUC *boneB)
{
  UFG::RagdollSkeletonMapper *v3; // rbp
  unsigned int v4; // edi
  unsigned int v5; // esi
  UFG::RagdollSkeletonMapper::UserMapping *v6; // rdx
  UFG::RagdollSkeletonMapper::UserMapping *v7; // rdx

  v3 = this;
  v4 = boneA->mUID;
  v5 = boneB->mUID;
  if ( this->m_userMappingsAtoB.m_size == (this->m_userMappingsAtoB.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_userMappingsAtoB,
      8);
  v6 = &v3->m_userMappingsAtoB.m_data[v3->m_userMappingsAtoB.m_size];
  if ( v6 )
  {
    v6->m_boneIn.mUID = v4;
    v6->m_boneOut.mUID = v5;
  }
  ++v3->m_userMappingsAtoB.m_size;
  if ( v3->m_userMappingsBtoA.m_size == (v3->m_userMappingsBtoA.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_userMappingsBtoA, 8);
  v7 = &v3->m_userMappingsBtoA.m_data[v3->m_userMappingsBtoA.m_size];
  if ( v7 )
  {
    v7->m_boneIn.mUID = v5;
    v7->m_boneOut.mUID = v4;
  }
  ++v3->m_userMappingsBtoA.m_size;
}

// File Line: 174
// RVA: 0x45CA90
void __fastcall UFG::RagdollSkeletonMapper::CreateMapping(UFG::RagdollSkeletonMapper *this, hkaSkeletonMapperData *aToB, hkaSkeletonMapperData *bToA)
{
  hkaSkeletonMapperData *v3; // rsi
  hkaSkeletonMapperData *v4; // rbx
  UFG::RagdollSkeletonMapper *v5; // r14
  int v6; // er13
  hkaSkeleton *v7; // rax
  int v8; // er12
  hkQsTransformf *v9; // r15
  hkLifoAllocator *v10; // rax
  int v11; // edx
  hkQsTransformf *v12; // rdi
  char *v13; // rcx
  hkLifoAllocator *v14; // rax
  int v15; // edx
  char *v16; // rcx
  hkLifoAllocator *v17; // rax
  int v18; // edx
  __int16 *v19; // rcx
  char *v20; // rdi
  int v21; // er9
  __int16 *v22; // rdi
  __int64 v23; // rcx
  hkLifoAllocator *v24; // rax
  hkLifoAllocator *v25; // rdi
  int v26; // edx
  char *v27; // rax
  char *v28; // rcx
  int v29; // er9
  _WORD *v30; // rdi
  __int64 v31; // rcx
  hkaSkeleton *v32; // rdi
  hkaSkeleton *v33; // rdi
  hkReferencedObject *v34; // rcx
  hkaSkeleton *v35; // rdi
  hkaSkeleton *v36; // rdi
  hkReferencedObject *v37; // rcx
  __int64 v38; // rbx
  _DWORD *v39; // r13
  __int64 v40; // r12
  UFG::RagdollSkeletonMapper::UserMapping *v41; // rdi
  __int16 v42; // r15
  __int16 v43; // si
  signed __int64 v44; // rax
  __int64 v45; // rbx
  _DWORD *v46; // r12
  __int64 v47; // r13
  UFG::RagdollSkeletonMapper::UserMapping *v48; // rdi
  __int16 v49; // r15
  __int16 v50; // si
  signed __int64 v51; // rax
  __int64 v52; // rcx
  UFG::qSymbolUC *v53; // rbx
  int v54; // eax
  __int16 v55; // r12
  __int16 v56; // r13
  int v57; // eax
  __int16 v58; // di
  int v59; // eax
  __int16 v60; // r15
  char *v61; // rdi
  char *v62; // rax
  char *v63; // rdi
  char *v64; // rax
  hkLifoAllocator *v65; // rax
  __int16 *v66; // rcx
  unsigned __int64 v67; // rdx
  hkLifoAllocator *v68; // rax
  __int16 *v69; // rcx
  unsigned __int64 v70; // rdx
  signed __int64 v71; // r15
  __int64 v72; // r12
  char *v73; // rdi
  char *v74; // rax
  int v75; // er12
  signed __int64 v76; // r15
  __int64 v77; // r12
  char *v78; // rdi
  char *v79; // rax
  __int16 v80; // si
  hkQuaternionf *v81; // r15
  __int16 v82; // di
  __int16 v83; // bx
  __m128 v84; // xmm8
  __m128 v85; // xmm0
  __m128 v86; // xmm1
  __m128 v87; // xmm10
  __m128 v88; // xmm7
  __m128 v89; // xmm2
  __m128 v90; // xmm4
  __m128 v91; // xmm1
  __m128 v92; // xmm6
  __m128 v93; // xmm12
  __m128 v94; // xmm2
  __m128 v95; // xmm3
  __m128 v96; // xmm9
  __m128 v97; // xmm9
  __m128 v98; // xmm8
  __m128 v99; // xmm9
  __m128 v100; // xmm10
  __m128 v101; // xmm8
  __m128 v102; // xmm0
  __m128 v103; // xmm1
  __m128 v104; // xmm11
  __m128 v105; // xmm7
  __m128 v106; // xmm2
  __m128 v107; // xmm4
  __m128 v108; // xmm1
  __m128 v109; // xmm6
  __m128 v110; // xmm15
  __m128 v111; // xmm2
  __m128 v112; // xmm3
  __m128 v113; // xmm6
  __m128 v114; // xmm6
  __m128 v115; // xmm8
  __m128 v116; // xmm6
  __m128 v117; // xmm11
  __int64 v118; // r15
  signed __int64 v119; // rax
  hkVector4f *v120; // r15
  __m128 v121; // xmm8
  __m128 v122; // xmm0
  __m128 v123; // xmm1
  __m128 v124; // xmm7
  __m128 v125; // xmm6
  __m128 v126; // xmm3
  __m128 v127; // xmm4
  __m128 v128; // xmm1
  __m128 v129; // xmm5
  __m128 v130; // xmm10
  __m128 v131; // xmm2
  __m128 v132; // xmm3
  __m128 v133; // xmm9
  __m128 v134; // xmm9
  __m128 v135; // xmm8
  __m128 v136; // xmm9
  __m128 v137; // xmm12
  hkVector4f *v138; // r15
  __m128 v139; // xmm8
  __m128 v140; // xmm0
  __m128 v141; // xmm1
  __m128 v142; // xmm13
  __m128 v143; // xmm7
  __m128 v144; // xmm2
  __m128 v145; // xmm4
  __m128 v146; // xmm1
  __m128 v147; // xmm6
  __m128 v148; // xmm11
  __m128 v149; // xmm2
  __m128 v150; // xmm3
  __m128 v151; // xmm6
  __m128 v152; // xmm6
  __m128 v153; // xmm8
  __m128 v154; // xmm6
  __m128 v155; // xmm7
  __int64 v156; // r15
  signed __int64 v157; // rax
  signed __int64 v158; // rdx
  __int64 v159; // rdi
  signed __int64 v160; // rdx
  __int64 v161; // rdi
  char *v162; // rbx
  int v163; // ecx
  int v164; // edi
  hkLifoAllocator *v165; // rax
  signed int v166; // edi
  int v167; // er8
  __int16 *v168; // rbx
  int v169; // ecx
  int v170; // edi
  hkLifoAllocator *v171; // rax
  signed int v172; // edi
  int v173; // er8
  char *v174; // rdi
  char *v175; // rax
  char *v176; // rbx
  int v177; // ecx
  int v178; // edi
  hkLifoAllocator *v179; // rax
  signed int v180; // edi
  int v181; // er8
  __int16 *v182; // rbx
  int v183; // ecx
  int v184; // edi
  hkLifoAllocator *v185; // rax
  signed int v186; // edi
  int v187; // er8
  char *v188; // rdi
  char *v189; // rax
  char *v190; // rbx
  int v191; // ecx
  int v192; // edi
  hkLifoAllocator *v193; // rax
  signed int v194; // edi
  int v195; // er8
  __int16 *v196; // rbx
  int v197; // ecx
  int v198; // edi
  hkLifoAllocator *v199; // rax
  signed int v200; // edi
  int v201; // er8
  int v202; // ebx
  __int64 v203; // rsi
  _DWORD *v204; // r13
  int v205; // ebx
  __int64 v206; // rsi
  _DWORD *v207; // r12
  char *v208; // rbx
  int v209; // ecx
  int v210; // edi
  hkLifoAllocator *v211; // rax
  signed int v212; // edi
  int v213; // er8
  __int16 *v214; // rbx
  int v215; // ecx
  int v216; // edi
  hkLifoAllocator *v217; // rax
  signed int v218; // edi
  int v219; // er8
  hkLifoAllocator *v220; // rdi
  signed int v221; // ecx
  int v222; // er8
  void *v223; // rbx
  hkLifoAllocator *v224; // rdi
  signed int v225; // ecx
  int v226; // er8
  void *v227; // rbx
  hkArray<short,hkContainerHeapAllocator> bonesOut; // [rsp+30h] [rbp-90h]
  __int16 *array; // [rsp+40h] [rbp-80h]
  int v230; // [rsp+48h] [rbp-78h]
  int v231; // [rsp+4Ch] [rbp-74h]
  hkArray<short,hkContainerHeapAllocator> v232; // [rsp+50h] [rbp-70h]
  void *p; // [rsp+60h] [rbp-60h]
  int v234; // [rsp+68h] [rbp-58h]
  int v235; // [rsp+6Ch] [rbp-54h]
  void *v236; // [rsp+70h] [rbp-50h]
  hkVector4f *direction; // [rsp+78h] [rbp-48h]
  void *v238; // [rsp+80h] [rbp-40h]
  hkVector4f *v239; // [rsp+88h] [rbp-38h]
  void *v240; // [rsp+90h] [rbp-30h]
  hkQuaternionf *v241; // [rsp+98h] [rbp-28h]
  int v242; // [rsp+A0h] [rbp-20h]
  int v243; // [rsp+A4h] [rbp-1Ch]
  int v244; // [rsp+A8h] [rbp-18h]
  __m128 *v245; // [rsp+B0h] [rbp-10h]
  hkQsTransformf *v246; // [rsp+B8h] [rbp-8h]
  int v247; // [rsp+C0h] [rbp+0h]
  unsigned int v248; // [rsp+C4h] [rbp+4h]
  hkQsTransformf *v249; // [rsp+C8h] [rbp+8h]
  int v250; // [rsp+D0h] [rbp+10h]
  hkQsTransformf *v251; // [rsp+D8h] [rbp+18h]
  int v252; // [rsp+E0h] [rbp+20h]
  unsigned int v253; // [rsp+E4h] [rbp+24h]
  hkQsTransformf *v254; // [rsp+E8h] [rbp+28h]
  int v255; // [rsp+F0h] [rbp+30h]
  __int64 v256; // [rsp+F8h] [rbp+38h]
  __m128 *v257; // [rsp+100h] [rbp+40h]
  __int64 v258; // [rsp+108h] [rbp+48h]
  hkVector4f v259; // [rsp+110h] [rbp+50h]
  __int64 v260; // [rsp+140h] [rbp+80h]
  hkResult result; // [rsp+240h] [rbp+180h]
  __int64 v262; // [rsp+248h] [rbp+188h]
  __int64 v263; // [rsp+250h] [rbp+190h]
  hkBool v264; // [rsp+258h] [rbp+198h]

  v260 = -2i64;
  v3 = bToA;
  v4 = aToB;
  v5 = this;
  LODWORD(v236) = this->m_skeletonA->m_bones.m_size;
  v6 = (signed int)v236;
  v7 = this->m_skeletonB;
  v8 = v7->m_bones.m_size;
  HIDWORD(v236) = v7->m_bones.m_size;
  v9 = 0i64;
  v246 = 0i64;
  v247 = 0;
  v248 = 2147483648;
  v250 = (signed int)v236;
  if ( (_DWORD)v236 )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (((48 * (_DWORD)v236 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v12 = (hkQsTransformf *)v10->m_cur;
    v238 = v12;
    v13 = (char *)v12 + v11;
    if ( v11 > v10->m_slabSize || v13 > v10->m_end )
    {
      v12 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v10, v11);
      v238 = v12;
    }
    else
    {
      v10->m_cur = v13;
    }
  }
  else
  {
    v12 = 0i64;
    v238 = 0i64;
  }
  v246 = v12;
  v243 = v6 | 0x80000000;
  v248 = v6 | 0x80000000;
  v249 = v12;
  v251 = 0i64;
  v252 = 0;
  v253 = 2147483648;
  v255 = v8;
  if ( v8 )
  {
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (((48 * v8 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v9 = (hkQsTransformf *)v14->m_cur;
    v240 = v9;
    v16 = (char *)v9 + v15;
    if ( v15 > v14->m_slabSize || v16 > v14->m_end )
    {
      v9 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v14, v15);
      v240 = v9;
    }
    else
    {
      v14->m_cur = v16;
    }
  }
  else
  {
    v240 = 0i64;
  }
  v251 = v9;
  v244 = v8 | 0x80000000;
  v253 = v8 | 0x80000000;
  v254 = v9;
  v247 = v6;
  v252 = v8;
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    v6,
    v5->m_skeletonA->m_parentIndices.m_data,
    v5->m_skeletonA->m_referencePose.m_data,
    v12);
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    v8,
    v5->m_skeletonB->m_parentIndices.m_data,
    v5->m_skeletonB->m_referencePose.m_data,
    v9);
  array = 0i64;
  v230 = 0;
  v231 = 2147483648;
  v232.m_size = v6;
  if ( v6 )
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (((2 * v6 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v19 = (__int16 *)v17->m_cur;
    v20 = (char *)v19 + v18;
    if ( v18 > v17->m_slabSize || v20 > v17->m_end )
      v19 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v17, v18);
    else
      v17->m_cur = v20;
  }
  else
  {
    v19 = 0i64;
  }
  array = v19;
  v231 = v243;
  v232.m_data = v19;
  if ( (v243 & 0x3FFFFFFF) < v6 )
  {
    v21 = v6;
    if ( v6 < 2 * (v243 & 0x3FFFFFFF) )
      v21 = 2 * (v243 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v21, 2);
  }
  v22 = &array[v230];
  v23 = v6 - v230;
  if ( v6 - v230 > 0 )
  {
    while ( v23 )
    {
      *v22 = -1;
      ++v22;
      --v23;
    }
  }
  v230 = v6;
  p = 0i64;
  v234 = 0;
  v235 = 2147483648;
  LODWORD(direction) = v8;
  if ( v8 )
  {
    v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v25 = v24;
    v26 = (((2 * v8 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v27 = (char *)v24->m_cur;
    v28 = &v27[v26];
    if ( v26 > v25->m_slabSize || v28 > v25->m_end )
      v27 = (char *)hkLifoAllocator::allocateFromNewSlab(v25, v26);
    else
      v25->m_cur = v28;
  }
  else
  {
    v27 = 0i64;
  }
  p = v27;
  v235 = v244;
  v236 = v27;
  if ( (v244 & 0x3FFFFFFF) < v8 )
  {
    v29 = v8;
    if ( v8 < 2 * (v244 & 0x3FFFFFFF) )
      v29 = 2 * (v244 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &p, v29, 2);
  }
  v30 = (char *)p + 2 * v234;
  v31 = v8 - v234;
  if ( v8 - v234 > 0 )
  {
    while ( v31 )
    {
      *v30 = -1;
      ++v30;
      --v31;
    }
  }
  v234 = v8;
  v32 = v5->m_skeletonA;
  if ( v32 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->m_skeletonA->vfptr);
  if ( v4->m_skeletonA.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v4->m_skeletonA.m_pntr->vfptr);
  v4->m_skeletonA.m_pntr = v32;
  v33 = v5->m_skeletonB;
  if ( v33 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->m_skeletonB->vfptr);
  v34 = (hkReferencedObject *)&v4->m_skeletonB.m_pntr->vfptr;
  if ( v34 )
    hkReferencedObject::removeReference(v34);
  v4->m_skeletonB.m_pntr = v33;
  v35 = v5->m_skeletonB;
  if ( v35 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->m_skeletonB->vfptr);
  if ( v3->m_skeletonA.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->m_skeletonA.m_pntr->vfptr);
  v3->m_skeletonA.m_pntr = v35;
  v36 = v5->m_skeletonA;
  if ( v36 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->m_skeletonA->vfptr);
  v37 = (hkReferencedObject *)&v3->m_skeletonB.m_pntr->vfptr;
  if ( v37 )
    hkReferencedObject::removeReference(v37);
  v3->m_skeletonB.m_pntr = v36;
  v38 = 0i64;
  if ( v5->m_userMappingsAtoB.m_size > 0i64 )
  {
    v39 = (_DWORD *)v262;
    v40 = v5->m_userMappingsAtoB.m_size;
    do
    {
      v41 = v5->m_userMappingsAtoB.m_data;
      v42 = Skeleton::GetBoneID(v5->ufgSkeletonA, v41[v38].m_boneIn.mUID);
      v43 = Skeleton::GetBoneID(v5->ufgSkeletonB, v41[v38].m_boneOut.mUID);
      if ( v42 != -1 && v43 != -1 )
      {
        if ( v39[18] == (v39[19] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v39 + 16, 64);
        v44 = *((_QWORD *)v39 + 8) + ((signed __int64)(signed int)v39[18] << 6);
        *(_WORD *)v44 = v42;
        *(_WORD *)(v44 + 2) = v43;
        *(_OWORD *)(v44 + 16) = 0i64;
        *(hkQuaternionf *)(v44 + 32) = (hkQuaternionf)qi.m_vec.m_quad;
        *(hkVector4f *)(v44 + 48) = (hkVector4f)query.m_quad;
        ++v39[18];
        *((_WORD *)p + v43) = v42;
      }
      ++v38;
    }
    while ( v38 < v40 );
    v8 = HIDWORD(v236);
    v6 = (signed int)v236;
  }
  v45 = 0i64;
  if ( v5->m_userMappingsBtoA.m_size > 0i64 )
  {
    v46 = (_DWORD *)v263;
    v47 = v5->m_userMappingsBtoA.m_size;
    do
    {
      v48 = v5->m_userMappingsBtoA.m_data;
      v49 = Skeleton::GetBoneID(v5->ufgSkeletonB, v48[v45].m_boneIn.mUID);
      v50 = Skeleton::GetBoneID(v5->ufgSkeletonA, v48[v45].m_boneOut.mUID);
      if ( v49 != -1 && v50 != -1 )
      {
        if ( v46[18] == (v46[19] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v46 + 16, 64);
        v51 = *((_QWORD *)v46 + 8) + ((signed __int64)(signed int)v46[18] << 6);
        *(_WORD *)v51 = v49;
        *(_WORD *)(v51 + 2) = v50;
        *(_OWORD *)(v51 + 16) = 0i64;
        *(hkQuaternionf *)(v51 + 32) = (hkQuaternionf)qi.m_vec.m_quad;
        *(hkVector4f *)(v51 + 48) = (hkVector4f)query.m_quad;
        ++v46[18];
        array[v50] = v49;
      }
      ++v45;
    }
    while ( v45 < v47 );
    v8 = HIDWORD(v236);
    v6 = (signed int)v236;
  }
  v52 = 0i64;
  v256 = 0i64;
  v258 = v5->m_userChains.m_size;
  if ( v258 > 0 )
  {
    do
    {
      v53 = (UFG::qSymbolUC *)&v5->m_userChains.m_data[v52];
      v54 = Skeleton::GetBoneID(v5->ufgSkeletonA, v53->mUID);
      v55 = v54;
      LODWORD(v239) = v54;
      v56 = Skeleton::GetBoneID(v5->ufgSkeletonA, v53[1].mUID);
      v57 = Skeleton::GetBoneID(v5->ufgSkeletonB, v53->mUID);
      v58 = v57;
      LODWORD(v241) = v57;
      v59 = Skeleton::GetBoneID(v5->ufgSkeletonB, v53[1].mUID);
      v60 = v59;
      LODWORD(v245) = v59;
      if ( v55 >= 0 || v58 >= 0 )
      {
        if ( v56 >= 0 || (v59 & 0x8000u) == 0 )
        {
          if ( v55 < 0 )
          {
            v55 = *((_WORD *)p + v58);
            LODWORD(v239) = *((unsigned __int16 *)p + v58);
          }
          if ( v56 < 0 )
            v56 = *((_WORD *)p + (signed __int16)v59);
          if ( v58 < 0 )
          {
            v58 = array[v55];
            LODWORD(v241) = (unsigned __int16)array[v55];
          }
          if ( (v59 & 0x8000u) != 0 )
          {
            v60 = array[v56];
            LODWORD(v245) = (unsigned __int16)array[v56];
          }
          bonesOut.m_data = 0i64;
          bonesOut.m_size = 0;
          bonesOut.m_capacityAndFlags = 2147483648;
          v230 = 16;
          v65 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v66 = (__int16 *)v65->m_cur;
          v67 = (unsigned __int64)(v66 + 64);
          if ( v65->m_slabSize < 128 || (void *)v67 > v65->m_end )
            v66 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v65, 128);
          else
            v65->m_cur = (void *)v67;
          bonesOut.m_data = v66;
          bonesOut.m_capacityAndFlags = -2147483632;
          array = v66;
          v232.m_data = 0i64;
          v232.m_size = 0;
          v232.m_capacityAndFlags = 2147483648;
          v234 = 16;
          v68 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v69 = (__int16 *)v68->m_cur;
          v70 = (unsigned __int64)(v69 + 64);
          if ( v68->m_slabSize < 128 || (void *)v70 > v68->m_end )
            v69 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v68, 128);
          else
            v68->m_cur = (void *)v70;
          v232.m_data = v69;
          v232.m_capacityAndFlags = -2147483632;
          p = v69;
          hkaSkeletonUtils::getBoneChain((hkBool *)&result, v5->m_skeletonA, v55, v56, &bonesOut);
          hkaSkeletonUtils::getBoneChain(&v264, v5->m_skeletonB, v58, v60, &v232);
          if ( LOBYTE(result.m_enum) && v264.m_bool )
          {
            LODWORD(direction) = v232.m_size;
            if ( bonesOut.m_size < 2 || v232.m_size < 2 )
            {
              v174 = UFG::qSymbol::as_cstr_dbg(v53 + 1);
              v175 = UFG::qSymbol::as_cstr_dbg(v53);
              UFG::qPrintf("Couldn't make a chain (%s - %s).\n", v175, v174);
              v176 = (char *)p;
              v177 = v232.m_size;
              if ( p == v232.m_data )
                v177 = 0;
              v232.m_size = v177;
              v178 = v234;
              v179 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v180 = (2 * v178 + 127) & 0xFFFFFF80;
              v181 = (v180 + 15) & 0xFFFFFFF0;
              if ( v180 > v179->m_slabSize || &v176[v181] != v179->m_cur || v179->m_firstNonLifoEnd == v176 )
                hkLifoAllocator::slowBlockFree(v179, v176, v181);
              else
                v179->m_cur = v176;
              v232.m_size = 0;
              if ( v232.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v232.m_data,
                  2 * (v232.m_capacityAndFlags & 0x3FFFFFFF));
              v232.m_data = 0i64;
              v232.m_capacityAndFlags = 2147483648;
              v182 = array;
              v183 = bonesOut.m_size;
              if ( array == bonesOut.m_data )
                v183 = 0;
              bonesOut.m_size = v183;
              v184 = v230;
              v185 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v186 = (2 * v184 + 127) & 0xFFFFFF80;
              v187 = (v186 + 15) & 0xFFFFFFF0;
              if ( v186 > v185->m_slabSize || (char *)v182 + v187 != v185->m_cur || v185->m_firstNonLifoEnd == v182 )
                hkLifoAllocator::slowBlockFree(v185, v182, v187);
              else
                v185->m_cur = v182;
            }
            else
            {
              v242 = bonesOut.m_size - 1;
              if ( bonesOut.m_size - 1 > 1 )
              {
                v242 = bonesOut.m_size - 1;
                v71 = 1i64;
                v72 = (unsigned int)(bonesOut.m_size - 2);
                do
                {
                  if ( array[bonesOut.m_data[v71]] != -1 )
                  {
                    v73 = UFG::qSymbol::as_cstr_dbg(v53 + 1);
                    v74 = UFG::qSymbol::as_cstr_dbg(v53);
                    UFG::qPrintf("Couldn't make a chain (%s - %s).\n", v74, v73);
                  }
                  ++v71;
                  --v72;
                }
                while ( v72 );
              }
              v75 = (_DWORD)direction - 1;
              LODWORD(direction) = v75;
              if ( v75 > 1 )
              {
                v76 = 1i64;
                v77 = (unsigned int)(v75 - 1);
                do
                {
                  if ( *((_WORD *)p + v232.m_data[v76]) != -1 )
                  {
                    v78 = UFG::qSymbol::as_cstr_dbg(v53 + 1);
                    v79 = UFG::qSymbol::as_cstr_dbg(v53);
                    UFG::qPrintf("Couldn't make a chain (%s - %s).\n", v79, v78);
                  }
                  ++v76;
                  --v77;
                }
                while ( v77 );
                v75 = (signed int)direction;
              }
              v80 = (signed __int16)v239;
              v81 = (hkQuaternionf *)((char *)v238 + 48 * (signed __int16)v239);
              v257 = (__m128 *)((char *)v238 + 48 * (signed __int16)v239);
              v82 = (signed __int16)v241;
              v239 = (hkVector4f *)((char *)v240 + 48 * (signed __int16)v241);
              v241 = (hkQuaternionf *)((char *)v238 + 48 * v56);
              v83 = (signed __int16)v245;
              direction = (hkVector4f *)((char *)v240 + 48 * (signed __int16)v245);
              v245 = &v241[1].m_vec.m_quad;
              hkVector4f::setRotatedInverseDir(&v259, v241 + 1, &v241->m_vec);
              v84 = _mm_xor_ps(*v245, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
              v85 = v241[2].m_vec.m_quad;
              v86 = _mm_rcp_ps(v85);
              v87 = (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v85, v86)), v86),
                                4),
                              4);
              v88 = _mm_shuffle_ps(v84, v84, 255);
              v89 = _mm_mul_ps(v84, direction->m_quad);
              v90 = _mm_shuffle_ps(v84, v84, 201);
              v91 = _mm_sub_ps(
                      _mm_mul_ps(v84, _mm_shuffle_ps(direction->m_quad, direction->m_quad, 201)),
                      _mm_mul_ps(direction->m_quad, v90));
              v92 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(direction->m_quad, _mm_sub_ps(_mm_mul_ps(v88, v88), (__m128)xmmword_141A711B0)),
                        _mm_mul_ps(
                          v84,
                          _mm_add_ps(
                            _mm_shuffle_ps(v89, v89, 170),
                            _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0))))),
                      _mm_mul_ps(_mm_shuffle_ps(v91, v91, 201), v88));
              v93 = _mm_add_ps(
                      _mm_xor_ps(v259.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0)),
                      _mm_add_ps(v92, v92));
              v94 = direction[1].m_quad;
              v95 = _mm_shuffle_ps(v94, v94, 255);
              v96 = _mm_sub_ps(
                      _mm_mul_ps(v84, _mm_shuffle_ps(direction[1].m_quad, v94, 201)),
                      _mm_mul_ps(direction[1].m_quad, v90));
              v97 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v96, v96, 201), _mm_mul_ps(direction[1].m_quad, v88)),
                      _mm_mul_ps(v84, v95));
              v98 = _mm_mul_ps(v84, v94);
              v99 = _mm_shuffle_ps(
                      v97,
                      _mm_unpackhi_ps(
                        v97,
                        _mm_sub_ps(
                          _mm_mul_ps(v95, v88),
                          _mm_add_ps(
                            _mm_shuffle_ps(v98, v98, 170),
                            _mm_add_ps(_mm_shuffle_ps(v98, v98, 85), _mm_shuffle_ps(v98, v98, 0))))),
                      196);
              v100 = _mm_mul_ps(v87, direction[2].m_quad);
              hkVector4f::setRotatedInverseDir(&v259, v81 + 1, &v81->m_vec);
              v101 = _mm_xor_ps(
                       v81[1].m_vec.m_quad,
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
              v102 = v81[2].m_vec.m_quad;
              v103 = _mm_rcp_ps(v102);
              v104 = (__m128)_mm_srli_si128(
                               _mm_slli_si128(
                                 (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v102, v103)), v103),
                                 4),
                               4);
              v105 = _mm_shuffle_ps(v101, v101, 255);
              v106 = _mm_mul_ps(v101, v239->m_quad);
              v107 = _mm_shuffle_ps(v101, v101, 201);
              v108 = _mm_sub_ps(
                       _mm_mul_ps(v101, _mm_shuffle_ps(v239->m_quad, v239->m_quad, 201)),
                       _mm_mul_ps(v239->m_quad, v107));
              v109 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v239->m_quad, _mm_sub_ps(_mm_mul_ps(v105, v105), (__m128)xmmword_141A711B0)),
                         _mm_mul_ps(
                           v101,
                           _mm_add_ps(
                             _mm_shuffle_ps(v106, v106, 170),
                             _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0))))),
                       _mm_mul_ps(_mm_shuffle_ps(v108, v108, 201), v105));
              v110 = _mm_add_ps(
                       _mm_xor_ps(
                         v259.m_quad,
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0)),
                       _mm_add_ps(v109, v109));
              v111 = v239[1].m_quad;
              v112 = _mm_shuffle_ps(v111, v111, 255);
              v113 = _mm_sub_ps(
                       _mm_mul_ps(v101, _mm_shuffle_ps(v239[1].m_quad, v111, 201)),
                       _mm_mul_ps(v239[1].m_quad, v107));
              v114 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v113, v113, 201), _mm_mul_ps(v239[1].m_quad, v105)),
                       _mm_mul_ps(v101, v112));
              v115 = _mm_mul_ps(v101, v111);
              v116 = _mm_shuffle_ps(
                       v114,
                       _mm_unpackhi_ps(
                         v114,
                         _mm_sub_ps(
                           _mm_mul_ps(v112, v105),
                           _mm_add_ps(
                             _mm_shuffle_ps(v115, v115, 170),
                             _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0))))),
                       196);
              v117 = _mm_mul_ps(v104, v239[2].m_quad);
              v118 = v262;
              if ( *(_DWORD *)(v262 + 88) == (*(_DWORD *)(v262 + 92) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  (void *)(v262 + 80),
                  112);
              v119 = *(_QWORD *)(v118 + 80) + 112i64 * *(signed int *)(v118 + 88);
              *(_WORD *)v119 = v80;
              *(_WORD *)(v119 + 2) = v56;
              *(_WORD *)(v119 + 4) = v82;
              *(_WORD *)(v119 + 6) = v83;
              *(__m128 *)(v119 + 16) = v110;
              *(__m128 *)(v119 + 32) = v116;
              *(__m128 *)(v119 + 48) = v117;
              *(__m128 *)(v119 + 64) = v93;
              *(__m128 *)(v119 + 80) = v99;
              *(__m128 *)(v119 + 96) = v100;
              ++*(_DWORD *)(v118 + 88);
              v120 = direction;
              hkVector4f::setRotatedInverseDir(&v259, (hkQuaternionf *)&direction[1], direction);
              v121 = _mm_xor_ps(
                       v120[1].m_quad,
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
              v122 = v120[2].m_quad;
              v123 = _mm_rcp_ps(v122);
              v124 = (__m128)_mm_srli_si128(
                               _mm_slli_si128(
                                 (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v122, v123)), v123),
                                 4),
                               4);
              v125 = _mm_shuffle_ps(v121, v121, 255);
              v126 = _mm_mul_ps(v241->m_vec.m_quad, v121);
              v127 = _mm_shuffle_ps(v121, v121, 201);
              v128 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v241->m_vec.m_quad, v241->m_vec.m_quad, 201), v121),
                       _mm_mul_ps(v127, v241->m_vec.m_quad));
              v129 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v125, v125), (__m128)xmmword_141A711B0), v241->m_vec.m_quad),
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_shuffle_ps(v126, v126, 170),
                             _mm_add_ps(_mm_shuffle_ps(v126, v126, 85), _mm_shuffle_ps(v126, v126, 0))),
                           v121)),
                       _mm_mul_ps(v125, _mm_shuffle_ps(v128, v128, 201)));
              v130 = _mm_add_ps(
                       _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         v259.m_quad),
                       _mm_add_ps(v129, v129));
              v131 = v241[1].m_vec.m_quad;
              v132 = _mm_shuffle_ps(v131, v131, 255);
              v133 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v241[1].m_vec.m_quad, v131, 201), v121),
                       _mm_mul_ps(v127, v131));
              v134 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v133, v133, 201), _mm_mul_ps(v125, v131)),
                       _mm_mul_ps(v132, v121));
              v135 = _mm_mul_ps(v121, v131);
              v136 = _mm_shuffle_ps(
                       v134,
                       _mm_unpackhi_ps(
                         v134,
                         _mm_sub_ps(
                           _mm_mul_ps(v132, v125),
                           _mm_add_ps(
                             _mm_shuffle_ps(v135, v135, 170),
                             _mm_add_ps(_mm_shuffle_ps(v135, v135, 85), _mm_shuffle_ps(v135, v135, 0))))),
                       196);
              v137 = _mm_mul_ps(v241[2].m_vec.m_quad, v124);
              v138 = v239;
              hkVector4f::setRotatedInverseDir(&v259, (hkQuaternionf *)&v239[1], v239);
              v139 = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                       v138[1].m_quad);
              v140 = v138[2].m_quad;
              v141 = _mm_rcp_ps(v140);
              v142 = (__m128)_mm_srli_si128(
                               _mm_slli_si128(
                                 (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v140, v141)), v141),
                                 4),
                               4);
              v143 = _mm_shuffle_ps(v139, v139, 255);
              v144 = _mm_mul_ps(*v257, v139);
              v145 = _mm_shuffle_ps(v139, v139, 201);
              v146 = _mm_sub_ps(_mm_mul_ps(v139, _mm_shuffle_ps(*v257, *v257, 201)), _mm_mul_ps(*v257, v145));
              v147 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v143, v143), (__m128)xmmword_141A711B0), *v257),
                         _mm_mul_ps(
                           v139,
                           _mm_add_ps(
                             _mm_shuffle_ps(v144, v144, 170),
                             _mm_add_ps(_mm_shuffle_ps(v144, v144, 85), _mm_shuffle_ps(v144, v144, 0))))),
                       _mm_mul_ps(v143, _mm_shuffle_ps(v146, v146, 201)));
              v148 = _mm_add_ps(
                       _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         v259.m_quad),
                       _mm_add_ps(v147, v147));
              v149 = v257[1];
              v150 = _mm_shuffle_ps(v149, v149, 255);
              v151 = _mm_sub_ps(_mm_mul_ps(v139, _mm_shuffle_ps(v257[1], v149, 201)), _mm_mul_ps(v257[1], v145));
              v152 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v151, v151, 201), _mm_mul_ps(v257[1], v143)),
                       _mm_mul_ps(v139, v150));
              v153 = _mm_mul_ps(v139, v149);
              v154 = _mm_shuffle_ps(
                       v152,
                       _mm_unpackhi_ps(
                         v152,
                         _mm_sub_ps(
                           _mm_mul_ps(v150, v143),
                           _mm_add_ps(
                             _mm_shuffle_ps(v153, v153, 170),
                             _mm_add_ps(_mm_shuffle_ps(v153, v153, 85), _mm_shuffle_ps(v153, v153, 0))))),
                       196);
              v155 = _mm_mul_ps(v257[2], v142);
              v156 = v263;
              if ( *(_DWORD *)(v263 + 88) == (*(_DWORD *)(v263 + 92) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  (void *)(v263 + 80),
                  112);
              v157 = *(_QWORD *)(v156 + 80) + 112i64 * *(signed int *)(v156 + 88);
              *(_WORD *)v157 = v82;
              *(_WORD *)(v157 + 2) = v83;
              *(_WORD *)(v157 + 4) = v80;
              *(_WORD *)(v157 + 6) = v56;
              *(__m128 *)(v157 + 16) = v148;
              *(__m128 *)(v157 + 32) = v154;
              *(__m128 *)(v157 + 48) = v155;
              *(__m128 *)(v157 + 64) = v130;
              *(__m128 *)(v157 + 80) = v136;
              *(__m128 *)(v157 + 96) = v137;
              ++*(_DWORD *)(v156 + 88);
              if ( v242 > 1 )
              {
                v158 = 1i64;
                v159 = (unsigned int)(v242 - 1);
                do
                {
                  array[bonesOut.m_data[v158]] = -2;
                  ++v158;
                  --v159;
                }
                while ( v159 );
              }
              if ( v75 > 1 )
              {
                v160 = 1i64;
                v161 = (unsigned int)(v75 - 1);
                do
                {
                  *((_WORD *)p + v232.m_data[v160]) = -2;
                  ++v160;
                  --v161;
                }
                while ( v161 );
              }
              v162 = (char *)p;
              v163 = v232.m_size;
              if ( p == v232.m_data )
                v163 = 0;
              v232.m_size = v163;
              v164 = v234;
              v165 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v166 = (2 * v164 + 127) & 0xFFFFFF80;
              v167 = (v166 + 15) & 0xFFFFFFF0;
              if ( v166 > v165->m_slabSize || &v162[v167] != v165->m_cur || v165->m_firstNonLifoEnd == v162 )
                hkLifoAllocator::slowBlockFree(v165, v162, v167);
              else
                v165->m_cur = v162;
              v232.m_size = 0;
              if ( v232.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v232.m_data,
                  2 * (v232.m_capacityAndFlags & 0x3FFFFFFF));
              v232.m_data = 0i64;
              v232.m_capacityAndFlags = 2147483648;
              v168 = array;
              v169 = bonesOut.m_size;
              if ( array == bonesOut.m_data )
                v169 = 0;
              bonesOut.m_size = v169;
              v170 = v230;
              v171 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v172 = (2 * v170 + 127) & 0xFFFFFF80;
              v173 = (v172 + 15) & 0xFFFFFFF0;
              if ( v172 > v171->m_slabSize || (char *)v168 + v173 != v171->m_cur || v171->m_firstNonLifoEnd == v168 )
                hkLifoAllocator::slowBlockFree(v171, v168, v173);
              else
                v171->m_cur = v168;
            }
          }
          else
          {
            v188 = UFG::qSymbol::as_cstr_dbg(v53 + 1);
            v189 = UFG::qSymbol::as_cstr_dbg(v53);
            UFG::qPrintf("Couldn't make a chain (%s - %s).\n", v189, v188);
            v190 = (char *)p;
            v191 = v232.m_size;
            if ( p == v232.m_data )
              v191 = 0;
            v232.m_size = v191;
            v192 = v234;
            v193 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v194 = (2 * v192 + 127) & 0xFFFFFF80;
            v195 = (v194 + 15) & 0xFFFFFFF0;
            if ( v194 > v193->m_slabSize || &v190[v195] != v193->m_cur || v193->m_firstNonLifoEnd == v190 )
              hkLifoAllocator::slowBlockFree(v193, v190, v195);
            else
              v193->m_cur = v190;
            v232.m_size = 0;
            if ( v232.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v232.m_data,
                2 * (v232.m_capacityAndFlags & 0x3FFFFFFF));
            v232.m_data = 0i64;
            v232.m_capacityAndFlags = 2147483648;
            v196 = array;
            v197 = bonesOut.m_size;
            if ( array == bonesOut.m_data )
              v197 = 0;
            bonesOut.m_size = v197;
            v198 = v230;
            v199 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v200 = (2 * v198 + 127) & 0xFFFFFF80;
            v201 = (v200 + 15) & 0xFFFFFFF0;
            if ( v200 > v199->m_slabSize || (char *)v196 + v201 != v199->m_cur || v199->m_firstNonLifoEnd == v196 )
              hkLifoAllocator::slowBlockFree(v199, v196, v201);
            else
              v199->m_cur = v196;
          }
          bonesOut.m_size = 0;
          if ( bonesOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              bonesOut.m_data,
              2 * (bonesOut.m_capacityAndFlags & 0x3FFFFFFF));
          bonesOut.m_data = 0i64;
          bonesOut.m_capacityAndFlags = 2147483648;
        }
        else
        {
          v63 = UFG::qSymbol::as_cstr_dbg(v53 + 1);
          v64 = UFG::qSymbol::as_cstr_dbg(v53);
          UFG::qPrintf("Couldn't make a chain (%s - %s). End bone not found in either skeleton\n", v64, v63);
        }
      }
      else
      {
        v61 = UFG::qSymbol::as_cstr_dbg(v53 + 1);
        v62 = UFG::qSymbol::as_cstr_dbg(v53);
        UFG::qPrintf("Couldn't make a chain (%s - %s). Start bone not found in either skeleton\n", v62, v61);
      }
      v52 = v256 + 1;
      v256 = v52;
    }
    while ( v52 < v258 );
    v8 = HIDWORD(v236);
    v6 = (signed int)v236;
  }
  v202 = 0;
  if ( v8 > 0 )
  {
    v203 = 0i64;
    v204 = (_DWORD *)v262;
    do
    {
      if ( -1 == *(_WORD *)((char *)p + v203) )
      {
        if ( v204[26] == (v204[27] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v204 + 24, 2);
        *(_WORD *)(*((_QWORD *)v204 + 12) + 2i64 * (signed int)v204[26]++) = v202;
      }
      ++v202;
      v203 += 2i64;
    }
    while ( v202 < v8 );
    v6 = (signed int)v236;
  }
  v205 = 0;
  if ( v6 > 0 )
  {
    v206 = 0i64;
    v207 = (_DWORD *)v263;
    do
    {
      if ( -1 == array[v206] )
      {
        if ( v207[26] == (v207[27] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v207 + 24, 2);
        *(_WORD *)(*((_QWORD *)v207 + 12) + 2i64 * (signed int)v207[26]++) = v205;
      }
      ++v205;
      ++v206;
    }
    while ( v205 < v6 );
    v8 = HIDWORD(v236);
  }
  *(_BYTE *)(v262 + 160) = 1;
  *(_BYTE *)(v263 + 160) = 1;
  v208 = (char *)v236;
  v209 = v234;
  if ( v236 == p )
    v209 = 0;
  v234 = v209;
  v210 = (signed int)direction;
  v211 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v212 = (2 * v210 + 127) & 0xFFFFFF80;
  v213 = (v212 + 15) & 0xFFFFFFF0;
  if ( v212 > v211->m_slabSize || &v208[v213] != v211->m_cur || v211->m_firstNonLifoEnd == v208 )
    hkLifoAllocator::slowBlockFree(v211, v208, v213);
  else
    v211->m_cur = v208;
  v234 = 0;
  if ( v235 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      p,
      2 * (v235 & 0x3FFFFFFF));
  p = 0i64;
  v235 = 2147483648;
  v214 = v232.m_data;
  v215 = v230;
  if ( v232.m_data == array )
    v215 = 0;
  v230 = v215;
  v216 = v232.m_size;
  v217 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v218 = (2 * v216 + 127) & 0xFFFFFF80;
  v219 = (v218 + 15) & 0xFFFFFFF0;
  if ( v218 > v217->m_slabSize || (char *)v214 + v219 != v217->m_cur || v217->m_firstNonLifoEnd == v214 )
    hkLifoAllocator::slowBlockFree(v217, v214, v219);
  else
    v217->m_cur = v214;
  v230 = 0;
  if ( v231 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      2 * (v231 & 0x3FFFFFFF));
  array = 0i64;
  v231 = 2147483648;
  v252 = 0;
  v220 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v221 = (48 * v8 + 127) & 0xFFFFFF80;
  v222 = (v221 + 15) & 0xFFFFFFF0;
  v223 = v240;
  if ( v221 > v220->m_slabSize || (char *)v240 + v222 != v220->m_cur || v220->m_firstNonLifoEnd == v240 )
    hkLifoAllocator::slowBlockFree(v220, v240, v222);
  else
    v220->m_cur = v240;
  v252 = 0;
  if ( v244 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v223,
      48 * (v244 & 0x3FFFFFFF));
  v251 = 0i64;
  v253 = 2147483648;
  v247 = 0;
  v224 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v225 = (48 * v6 + 127) & 0xFFFFFF80;
  v226 = (v225 + 15) & 0xFFFFFFF0;
  v227 = v238;
  if ( v225 > v224->m_slabSize || (char *)v238 + v226 != v224->m_cur || v224->m_firstNonLifoEnd == v238 )
    hkLifoAllocator::slowBlockFree(v224, v238, v226);
  else
    v224->m_cur = v238;
  v247 = 0;
  if ( v243 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v227,
      48 * (v243 & 0x3FFFFFFF));
}

// File Line: 489
// RVA: 0x44CFA0
void __fastcall UFG::RagdollFactory::RagdollFactory(UFG::RagdollFactory *this)
{
  UFG::RagdollFactory *v1; // r14
  UFG::qBaseTreeRB *v2; // rbp
  hkArray<UFG::RagdollData *,hkContainerHeapAllocator> *v3; // r8
  int v4; // eax
  int v5; // eax
  int v6; // er9
  unsigned __int64 v7; // rbx
  UFG::qReflectWarehouse *v8; // rax
  UFG::qReflectInventoryBase *v9; // rax
  UFG::qTree64Base *v10; // r15
  UFG::qTree64Base *v11; // rax
  signed __int64 v12; // rsi
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rdi
  signed __int64 v15; // rbx
  UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData> *v16; // rcx
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rdi
  signed __int64 v19; // rbx
  __int64 v20; // rbx
  const char *v21; // rax
  unsigned __int64 v22; // rax
  unsigned int v23; // ecx
  unsigned int v24; // er10
  __int64 v25; // r9
  __int64 v26; // rcx
  unsigned int v27; // er8
  UFG::qResourceHandle *v28; // rcx
  UFG::qTree64Base *v29; // rax
  UFG::qTreeRB<UFG::RagdollDefinitionSearchNode,UFG::RagdollDefinitionSearchNode,1> *result; // [rsp+88h] [rbp+10h]
  UFG::allocator::free_link *v31; // [rsp+90h] [rbp+18h]

  v1 = this;
  this->mDisableCaching = 0;
  v2 = &this->mDefinitions.mTree;
  result = &this->mDefinitions;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mDefinitions.mTree);
  v3 = &v1->mRagdollData;
  v3->m_data = 0i64;
  v3->m_size = 0;
  v3->m_capacityAndFlags = 2147483648;
  v1->mSkeletonMapper = 0i64;
  v4 = v1->mRagdollData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < 8 )
  {
    v5 = 2 * v4;
    v6 = 8;
    if ( v5 > 8 )
      v6 = v5;
    hkArrayUtil::_reserve((hkResult *)&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v6, 8);
  }
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\RagdollDefinitions.perm.bin", 0i64, 0, 0i64, 0i64, 0i64);
  v7 = UFG::qStringHash64("UFG::RagdollDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v8 = UFG::qReflectWarehouse::Instance();
  v9 = UFG::qReflectWarehouse::GetInventory(v8, v7);
  v10 = &v9->mItems.mTree;
  v11 = UFG::qTree64Base::GetHead(&v9->mItems.mTree);
  if ( v11 )
  {
    v12 = (signed __int64)&v11[-1].mCount;
    if ( v11 != (UFG::qTree64Base *)8 )
    {
      do
      {
        if ( *(_QWORD *)(v12 + 112) )
        {
          v13 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
          v14 = v13;
          result = (UFG::qTreeRB<UFG::RagdollDefinitionSearchNode,UFG::RagdollDefinitionSearchNode,1> *)v13;
          if ( v13 )
          {
            v13->mNext = 0i64;
            v13[1].mNext = 0i64;
            v13[2].mNext = 0i64;
            v15 = (signed __int64)&v13[4];
            v31 = v13 + 4;
            UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v13[4]);
            *(_QWORD *)(v15 + 16) = UFG::qStringHash64("UFG::RagdollDefinition", 0xFFFFFFFFFFFFFFFFui64);
          }
          else
          {
            v14 = 0i64;
          }
          LODWORD(v14[3].mNext) = *(_DWORD *)(v12 + 120);
          UFG::qReflectHandleBase::Init(
            (UFG::qReflectHandleBase *)&v14[4],
            (unsigned __int64)v14[6].mNext,
            *(_QWORD *)(v12 + 8));
          UFG::qBaseTreeRB::Add(v2, (UFG::qBaseNodeRB *)v14);
          if ( *(_DWORD *)(v12 + 124) != -1 )
          {
            v17 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
            v18 = v17;
            result = (UFG::qTreeRB<UFG::RagdollDefinitionSearchNode,UFG::RagdollDefinitionSearchNode,1> *)v17;
            if ( v17 )
            {
              v17->mNext = 0i64;
              v17[1].mNext = 0i64;
              v17[2].mNext = 0i64;
              v19 = (signed __int64)&v17[4];
              v31 = v17 + 4;
              UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v17[4]);
              *(_QWORD *)(v19 + 16) = UFG::qStringHash64("UFG::RagdollDefinition", 0xFFFFFFFFFFFFFFFFui64);
            }
            else
            {
              v18 = 0i64;
            }
            LODWORD(v18[3].mNext) = *(_DWORD *)(v12 + 124);
            UFG::qReflectHandleBase::Init(
              (UFG::qReflectHandleBase *)&v18[4],
              (unsigned __int64)v18[6].mNext,
              *(_QWORD *)(v12 + 8));
            UFG::qBaseTreeRB::Add(v2, (UFG::qBaseNodeRB *)v18);
          }
          v20 = *(_QWORD *)(v12 + 112);
          v21 = UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::GetStaticTypeName(v16);
          v22 = UFG::qStringHash64(v21, 0xFFFFFFFFFFFFFFFFui64);
          v23 = 0;
          v24 = *(_DWORD *)(v20 + 224);
          if ( v24 )
          {
            v25 = *(_QWORD *)(v20 + 216);
            while ( *(_QWORD *)(*(_QWORD *)(v25 + 8i64 * v23) + 56i64) != v22 )
            {
              if ( ++v23 >= v24 )
                goto LABEL_22;
            }
            v26 = *(_QWORD *)(v25 + 8i64 * v23);
          }
          else
          {
LABEL_22:
            v26 = 0i64;
          }
          v27 = *(_DWORD *)(v26 + 104);
          v28 = (UFG::qResourceHandle *)(v26 + 80);
          v28[1].mPrev = 0i64;
          UFG::qResourceHandle::Init(v28, 0x1723EA91u, v27);
        }
        v29 = UFG::qTree64Base::GetNext(v10, (UFG::qTree64Base::BaseNode *)(v12 + 8));
        if ( !v29 )
          break;
        v12 = (signed __int64)&v29[-1].mCount;
      }
      while ( v29 != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 531
// RVA: 0x450C80
void __fastcall UFG::RagdollFactory::~RagdollFactory(UFG::RagdollFactory *this)
{
  UFG::RagdollFactory *v1; // rbx
  int v2; // esi
  __int64 v3; // rdi
  hkaSkeletonMapper *v4; // rcx
  hkaSkeletonMapper *v5; // rcx
  UFG::RagdollData *v6; // rcx
  int v7; // er8
  UFG::RagdollSkeletonMapper *v8; // rdi
  int v9; // er8
  Render::Skinning *v10; // rdi
  Render::SkinningCacheNode *v11; // rbx

  v1 = this;
  v2 = 0;
  if ( this->mRagdollData.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->mRagdollData.m_data[v3]->havokInstance->vfptr);
      v4 = v1->mRagdollData.m_data[v3]->highResToRagdollMapper;
      if ( v4 )
        v4->vfptr->__vecDelDtor((hkBaseObject *)&v4->vfptr, 1u);
      v5 = v1->mRagdollData.m_data[v3]->ragdollToHighResMapper;
      if ( v5 )
        v5->vfptr->__vecDelDtor((hkBaseObject *)&v5->vfptr, 1u);
      v6 = v1->mRagdollData.m_data[v3];
      if ( v6 )
        v6->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::RagdollData> *)&v6->vfptr, 1u);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->mRagdollData.m_size );
  }
  v1->mRagdollData.m_size = 0;
  v7 = v1->mRagdollData.m_capacityAndFlags;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mRagdollData.m_data,
      8 * v7);
  v1->mRagdollData.m_data = 0i64;
  v1->mRagdollData.m_capacityAndFlags = 2147483648;
  v8 = v1->mSkeletonMapper;
  if ( v8 )
  {
    UFG::RagdollSkeletonMapper::~RagdollSkeletonMapper(v1->mSkeletonMapper);
    operator delete[](v8);
  }
  v1->mRagdollData.m_size = 0;
  v9 = v1->mRagdollData.m_capacityAndFlags;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mRagdollData.m_data,
      8 * v9);
  v1->mRagdollData.m_data = 0i64;
  v1->mRagdollData.m_capacityAndFlags = 2147483648;
  v10 = (Render::Skinning *)&v1->mDefinitions;
  if ( v1->mDefinitions.mTree.mCount )
  {
    do
    {
      v11 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v10->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v10->mSkinnedVertexBuffers.mTree, &v11->mNode);
      if ( v11 )
      {
        UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v11->mCachedBufferPtr);
        operator delete[](v11);
      }
    }
    while ( v10->mSkinnedVertexBuffers.mTree.mCount );
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(v10);
}

// File Line: 547
// RVA: 0x45E390
UFG::qSafePointerNode<UFG::RagdollData> *__fastcall UFG::RagdollFactory::CreateRagdollFromSkeleton(UFG::RagdollFactory *this, Skeleton *skeleton, component_Ragdoll *rag_doll_data, UFG::RagdollQuality quality)
{
  UFG::RagdollQuality v4; // ebx
  Skeleton *v5; // r14
  UFG::RagdollFactory *v6; // r15
  UFG::qSafePointerNode<UFG::RagdollData> *v7; // rax
  UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData> *v8; // rcx
  UFG::qSafePointerNode<UFG::RagdollData> *v9; // rdi
  UFG::qBaseTreeRB *v10; // rax
  unsigned int v11; // eax
  __int64 v12; // r13
  const char *v13; // rax
  unsigned __int64 v14; // r10
  unsigned int v15; // edx
  unsigned int v16; // er9
  __int64 v17; // r8
  __int64 v18; // rcx
  UFG::qBaseNodeRB *v19; // rcx
  unsigned __int64 v20; // rbx
  Skeleton *v21; // rax
  Skeleton *v22; // rax
  Skeleton *v23; // rcx
  signed __int64 v24; // r12
  unsigned __int64 v25; // rax
  unsigned int v26; // er15
  signed __int64 v27; // rbx
  __int64 v28; // r14
  signed __int64 v29; // r12
  UFG::allocator::free_link *v30; // rax
  UFG::RagdollSkeletonMapper *v31; // rax
  UFG::RagdollFactory *v32; // r15
  unsigned int v33; // ebx
  UFG::qSymbolUC *v34; // rdx
  int v35; // ebx
  LPVOID v36; // rax
  hkLifoAllocator *v37; // rcx
  int v38; // edx
  hkQsTransformf *v39; // rax
  char *v40; // r8
  UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData> *v41; // rcx
  const char *v42; // rax
  unsigned __int64 v43; // r10
  unsigned int v44; // edx
  unsigned int v45; // er9
  __int64 v46; // r8
  __int64 v47; // rbx
  unsigned int v48; // er8
  void *v49; // rbx
  int v50; // er14
  hkLifoAllocator *v51; // rcx
  int v52; // eax
  hkQsTransformf *v53; // rdx
  char *v54; // r8
  int v55; // er9
  hkResultEnum v56; // er8
  signed __int64 v57; // r12
  __int64 v58; // r13
  signed __int64 v59; // rbx
  int v60; // er14
  __int64 v61; // r15
  __int64 v62; // rbx
  __int64 v63; // r14
  __int64 v64; // rcx
  __int64 v65; // r8
  __m128 v66; // xmm0
  hkVector4f v67; // xmm1
  char v68; // dl
  __int64 v69; // rax
  char v70; // cl
  _QWORD **v71; // rax
  hkpRigidBody *v72; // rax
  hkpWorldObject *v73; // rax
  hkpWorldObject *v74; // rbx
  char v75; // al
  void (__fastcall ***v76)(void *, signed __int64); // rbx
  hkLifoAllocator *v77; // rax
  hkLifoAllocator *v78; // r8
  int v79; // edx
  hkpConstraintInstance **v80; // rcx
  char *v81; // rax
  int v82; // er9
  __int64 v83; // rcx
  void (__fastcall ***v84)(void *, signed __int64); // rdx
  unsigned int v85; // er15
  char *v86; // rax
  hkResultEnum v87; // edx
  signed __int64 v88; // r13
  signed int v89; // er8
  hkResultEnum v90; // ebx
  signed __int64 v91; // r14
  hkaSkeleton *v92; // rcx
  int v93; // eax
  __int64 v94; // r15
  const char *v95; // rdx
  __int32 v96; // eax
  hkpRigidBody *v97; // r15
  hkpRigidBody *v98; // r13
  unsigned __int64 v99; // r14
  UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef> *v100; // rcx
  const char *v101; // rax
  UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef> *v102; // rcx
  UFG::allocator::free_link *v103; // rbx
  __int64 v104; // rax
  UFG::allocator::free_link *v105; // rbx
  __int64 v106; // rax
  hkpConstraintInstance *v107; // r13
  const char *v108; // rax
  UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef> *v109; // rcx
  UFG::qReflectObject *v110; // r15
  signed __int64 v111; // rbx
  char v112; // dl
  __int64 v113; // rax
  char v114; // cl
  _QWORD **v115; // rax
  hkpPositionConstraintMotor *v116; // rax
  __int64 v117; // rax
  __int64 v118; // r14
  char v119; // al
  int v120; // eax
  const char *v121; // rax
  UFG::qReflectObjectType<UFG::ConstraintDefBallAndSocket,UFG::ConstraintDef> *v122; // rcx
  UFG::qReflectObject *v123; // r15
  char v124; // dl
  __int64 v125; // rax
  char v126; // cl
  _QWORD **v127; // rax
  hkpPositionConstraintMotor *v128; // rax
  __int64 v129; // rax
  char v130; // al
  char v131; // r8
  __int64 v132; // rax
  char v133; // dl
  char v134; // al
  const char *v135; // rax
  UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef> *v136; // rcx
  const char *v137; // rax
  char *v138; // rax
  signed __int64 v139; // rbx
  char v140; // dl
  __int64 v141; // rax
  char v142; // cl
  _QWORD **v143; // rax
  hkaRagdollInstance *v144; // rax
  UFG::qSafePointerNode<UFG::RagdollData>Vtbl *v145; // rax
  char v146; // al
  int v147; // er14
  __int64 v148; // rbx
  int v149; // er14
  __int64 v150; // rbx
  __int64 v151; // r12
  unsigned __int64 v152; // rax
  UFG::allocator::free_link *v153; // rbx
  unsigned int v154; // er8
  unsigned int v155; // ecx
  unsigned int v156; // ebx
  unsigned int v157; // ebx
  unsigned __int64 v158; // rax
  UFG::allocator::free_link *v159; // r15
  unsigned int v160; // er8
  __int64 v161; // rcx
  unsigned int v162; // ebx
  unsigned int v163; // eax
  unsigned int v164; // eax
  unsigned int v165; // ecx
  int v166; // er15
  __int64 i; // r13
  __int64 v168; // rdx
  void *(__fastcall *v169)(UFG::qSafePointerNode<UFG::RagdollData> *, unsigned int); // rcx
  __int64 v170; // rcx
  unsigned int v171; // er14
  unsigned int v172; // ebx
  unsigned int v173; // ebx
  unsigned __int64 v174; // rax
  UFG::allocator::free_link *v175; // r12
  unsigned int v176; // er8
  Skeleton *v177; // rbx
  UFG::RagdollFactory *v178; // r15
  UFG::RagdollSkeletonMapper *v179; // rbx
  char *v180; // r14
  float v181; // ecx
  int v182; // ebx
  hkLifoAllocator *v183; // rcx
  signed int v184; // ebx
  int v185; // er8
  char *v186; // r14
  int v187; // ecx
  int v188; // ebx
  hkLifoAllocator *v189; // rcx
  signed int v190; // ebx
  int v191; // er8
  char *v192; // r14
  int v193; // ecx
  int v194; // ebx
  hkLifoAllocator *v195; // rcx
  signed int v196; // eax
  int v197; // er8
  UFG::qSafePointerNode<UFG::RagdollData>Vtbl *check_null; // [rsp+20h] [rbp-A8h]
  UFG::qSymbolUC result; // [rsp+30h] [rbp-98h]
  __int64 v201; // [rsp+38h] [rbp-90h]
  hkpConstraintInstance **array; // [rsp+40h] [rbp-88h]
  float volume; // [rsp+48h] [rbp-80h]
  hkResult v204; // [rsp+4Ch] [rbp-7Ch]
  void *p; // [rsp+50h] [rbp-78h]
  void *v206; // [rsp+58h] [rbp-70h]
  hkArray<hkQsTransformf,hkContainerHeapAllocator> transforms; // [rsp+60h] [rbp-68h]
  void *v208; // [rsp+70h] [rbp-58h]
  int v209; // [rsp+78h] [rbp-50h]
  __int64 v210; // [rsp+80h] [rbp-48h]
  __int64 v211; // [rsp+88h] [rbp-40h]
  UFG::qReflectHandleBase v212; // [rsp+98h] [rbp-30h]
  hkVector4f inertiaDiagonal; // [rsp+C8h] [rbp+0h]
  UFG::qReflectHandleBase other; // [rsp+D8h] [rbp+10h]
  __int64 v215; // [rsp+100h] [rbp+38h]
  hkVector4f halfExtents; // [rsp+108h] [rbp+40h]
  UFG::qReflectHandleBase v217; // [rsp+118h] [rbp+50h]
  void *ptr[2]; // [rsp+148h] [rbp+80h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+158h] [rbp+90h]
  UFG::qReflectHandleBase v220; // [rsp+238h] [rbp+170h]
  UFG::RagdollFactory *v221; // [rsp+2C8h] [rbp+200h]
  hkResult v222[2]; // [rsp+2D0h] [rbp+208h]
  unsigned int v223; // [rsp+2E0h] [rbp+218h]

  v215 = -2i64;
  v4 = quality;
  v5 = skeleton;
  v6 = this;
  v7 = (UFG::qSafePointerNode<UFG::RagdollData> *)UFG::qMemoryPool::Allocate(
                                                    &gPhysicsMemoryPool,
                                                    0x80ui64,
                                                    "RagdollData",
                                                    0i64,
                                                    1u);
  v9 = v7;
  p = v7;
  if ( v7 )
  {
    UFG::qSafePointerNode<UFG::RagdollData>::qSafePointerNode<UFG::RagdollData>(v7);
    v9->vfptr = (UFG::qSafePointerNode<UFG::RagdollData>Vtbl *)&UFG::RagdollData::`vftable';
    v9[2].m_SafePointerList.mNode.mPrev = 0i64;
    v9[2].vfptr = 0i64;
    v9[3].vfptr = 0i64;
    v9[2].m_SafePointerList.mNode.mNext = 0i64;
    HIDWORD(v9[4].vfptr) = 0;
    LODWORD(v9[4].m_SafePointerList.mNode.mNext) = 0;
  }
  else
  {
    v9 = 0i64;
  }
  HIDWORD(v9[4].m_SafePointerList.mNode.mPrev) = v5->mNameUID;
  LODWORD(v9[4].m_SafePointerList.mNode.mPrev) = v4;
  if ( !v5->mNameUID || (v10 = UFG::qBaseTreeRB::Get(&v6->mDefinitions.mTree, v5->mNameUID)) == 0i64 )
  {
    if ( _S12_5 & 1 )
    {
      v11 = defaultGuid;
    }
    else
    {
      _S12_5 |= 1u;
      v11 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
      defaultGuid = v11;
    }
    if ( v11 )
      v10 = UFG::qBaseTreeRB::Get(&v6->mDefinitions.mTree, v11);
    else
      v10 = 0i64;
  }
  v12 = *(_QWORD *)&v10->mCount;
  v211 = v12;
  v210 = *(_QWORD *)(v12 + 112);
  v13 = UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData>::GetStaticTypeName(v8);
  v14 = UFG::qStringHash64(v13, 0xFFFFFFFFFFFFFFFFui64);
  v15 = 0;
  v16 = *(_DWORD *)(v210 + 224);
  if ( v16 )
  {
    v17 = *(_QWORD *)(v210 + 216);
    while ( *(_QWORD *)(*(_QWORD *)(v17 + 8i64 * v15) + 56i64) != v14 )
    {
      if ( ++v15 >= v16 )
        goto LABEL_18;
    }
    v18 = *(_QWORD *)(v17 + 8i64 * v15);
  }
  else
  {
LABEL_18:
    v18 = 0i64;
  }
  v19 = UFG::qResourceInventory::Get((UFG::qResourceInventory *)&UFG::gRigInventory.vfptr, *(_DWORD *)(v18 + 80))[1].mNode.mChild[0];
  v9[1].vfptr = (UFG::qSafePointerNode<UFG::RagdollData>Vtbl *)v19;
  v20 = SLODWORD(v19[1].mChild[1]);
  v21 = (Skeleton *)UFG::qMalloc(0x38ui64, "Skeleton", 0x800ui64);
  p = v21;
  if ( v21 )
  {
    Skeleton::Skeleton(v21, "RagDoll");
    v23 = v22;
  }
  else
  {
    v23 = 0i64;
  }
  UFG::gpRagDollSkeleton = v23;
  v23->mhkaSkeleton = (hkaSkeleton *)v9[1].vfptr;
  v24 = v20;
  v25 = 8 * v20;
  if ( !is_mul_ok(v20, 8ui64) )
    v25 = -1i64;
  UFG::gpRagDollSkeleton->mBoneIDLookup = (UFG::RigResource::BoneLookupEntry *)UFG::qMalloc(
                                                                                 v25,
                                                                                 UFG::gGlobalNewName,
                                                                                 0i64);
  v26 = 0;
  v27 = 0i64;
  if ( v24 > 0 )
  {
    v28 = 0i64;
    do
    {
      UFG::qSymbolUC::create_from_string(
        &result,
        (const char *)(*(_QWORD *)((_BYTE *)v9[1].vfptr[5].__vecDelDtor + v28) & 0xFFFFFFFFFFFFFFFEui64));
      UFG::gpRagDollSkeleton->mBoneIDLookup[v27].guid = result.mUID;
      UFG::gpRagDollSkeleton->mBoneIDLookup[v27++].index = v26++;
      v28 += 16i64;
    }
    while ( v27 < v24 );
    v5 = *(Skeleton **)&v222[0].m_enum;
  }
  UFG::qQuickSortImpl<UFG::RigResource::BoneLookupEntry,UFG::sortBones>(
    UFG::gpRagDollSkeleton->mBoneIDLookup,
    &UFG::gpRagDollSkeleton->mBoneIDLookup[v24 - 1],
    0);
  LODWORD(v9[3].m_SafePointerList.mNode.mPrev) = Skeleton::GetBoneID(UFG::gpRagDollSkeleton, *(_DWORD *)(v12 + 128));
  v29 = -1i64;
  HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) = -1;
  v30 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  *(_QWORD *)&v222[0].m_enum = v30;
  if ( v30 )
    UFG::RagdollSkeletonMapper::RagdollSkeletonMapper((UFG::RagdollSkeletonMapper *)v30, *(_DWORD *)(v12 + 152), 0);
  else
    v31 = 0i64;
  v32 = v221;
  v221->mSkeletonMapper = v31;
  v33 = 0;
  if ( *(_DWORD *)(v12 + 152) )
  {
    do
    {
      v34 = (UFG::qSymbolUC *)(*(_QWORD *)(v12 + 144) + 8i64 * v33);
      UFG::RagdollSkeletonMapper::AddSimpleMapping(v32->mSkeletonMapper, v34, v34 + 1);
      ++v33;
    }
    while ( v33 < *(_DWORD *)(v12 + 152) );
  }
  UFG::RagdollFactory::CreateSkeletonMappings(v32, v5, (UFG::RagdollData *)v9);
  v35 = (int)v9[1].vfptr[6].__vecDelDtor;
  transforms.m_data = 0i64;
  transforms.m_size = 0;
  transforms.m_capacityAndFlags = 2147483648;
  v209 = v35;
  if ( v35 )
  {
    v36 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v37 = (hkLifoAllocator *)v36;
    v38 = (((48 * v35 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v39 = (hkQsTransformf *)*((_QWORD *)v36 + 3);
    v40 = (char *)v39 + v38;
    if ( v38 > v37->m_slabSize || v40 > v37->m_end )
      v39 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v37, v38);
    else
      v37->m_cur = v40;
  }
  else
  {
    v39 = 0i64;
  }
  transforms.m_data = v39;
  transforms.m_capacityAndFlags = v35 | 0x80000000;
  v208 = v39;
  check_null = v9[1].vfptr;
  UFG::RagdollFactory::BuildAndSetReferencePose(v32, (UFG::RagdollData *)v9, v5, &transforms);
  v42 = UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::GetStaticTypeName(v41);
  v43 = UFG::qStringHash64(v42, 0xFFFFFFFFFFFFFFFFui64);
  v44 = 0;
  v45 = *(_DWORD *)(v210 + 224);
  if ( v45 )
  {
    v46 = *(_QWORD *)(v210 + 216);
    while ( *(_QWORD *)(*(_QWORD *)(v46 + 8i64 * v44) + 56i64) != v43 )
    {
      if ( ++v44 >= v45 )
        goto LABEL_45;
    }
    v47 = *(_QWORD *)(v46 + 8i64 * v44);
  }
  else
  {
LABEL_45:
    v47 = 0i64;
  }
  v48 = *(_DWORD *)(v47 + 104);
  *(_QWORD *)(v47 + 112) = 0i64;
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v47 + 80), 0x1723EA91u, v48);
  v49 = *(void **)(v47 + 96);
  p = v49;
  LODWORD(v210) = *((_DWORD *)v49 + 22);
  v50 = v210;
  transforms.m_data = 0i64;
  transforms.m_size = 0;
  transforms.m_capacityAndFlags = 2147483648;
  v209 = v210;
  if ( (_DWORD)v210 )
  {
    v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v52 = (((8 * v50 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v53 = (hkQsTransformf *)v51->m_cur;
    v54 = (char *)v53 + v52;
    if ( v52 > v51->m_slabSize || v54 > v51->m_end )
      v53 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v51, v52);
    else
      v51->m_cur = v54;
  }
  else
  {
    v53 = 0i64;
  }
  transforms.m_data = v53;
  transforms.m_capacityAndFlags = v50 | 0x80000000;
  v208 = v53;
  if ( (signed int)((v50 | 0x80000000) & 0x3FFFFFFF) < v50 )
  {
    v55 = v50;
    if ( v50 < (signed int)(2 * ((v50 | 0x80000000) & 0x3FFFFFFF)) )
      v55 = 2 * ((v50 | 0x80000000) & 0x3FFFFFFF);
    hkArrayUtil::_reserve(v222, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &transforms, v55, 8);
  }
  transforms.m_size = v50;
  v56 = 0;
  v222[0].m_enum = 0;
  if ( *((_DWORD *)v49 + 22) )
  {
    v57 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    do
    {
      v58 = *(_QWORD *)(*((_QWORD *)v49 + 14) + 8i64 * (unsigned int)v56);
      v59 = -1i64;
      v201 = -1i64;
      v60 = 0;
      v61 = 0i64;
      if ( SLODWORD(v9[1].vfptr[6].__vecDelDtor) > 0 )
      {
        v62 = 0i64;
        while ( 1 )
        {
          UFG::qSymbol::create_from_string(
            (UFG::qSymbol *)&result,
            (const char *)(*(_QWORD *)((_BYTE *)v9[1].vfptr[5].__vecDelDtor + v62) & 0xFFFFFFFFFFFFFFFEui64));
          if ( result.mUID == *(_DWORD *)(v58 + 216) )
            break;
          ++v60;
          ++v61;
          v62 += 16i64;
          if ( v60 >= SLODWORD(v9[1].vfptr[6].__vecDelDtor) )
          {
            v59 = v201;
            goto LABEL_64;
          }
        }
        v59 = v61;
        v201 = v61;
      }
LABEL_64:
      v63 = *(_QWORD *)(v58 + 256);
      hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
      bodyInfo.m_solverDeactivation.m_storage = 3;
      if ( v223 )
        bodyInfo.m_qualityType.m_storage = *(_DWORD *)(v63 + 188);
      else
        bodyInfo.m_qualityType.m_storage = 4;
      bodyInfo.m_shape = *(hkpShape **)(v58 + 192);
      bodyInfo.m_friction = 0.30000001;
      bodyInfo.m_restitution = 0.0;
      bodyInfo.m_linearDamping = *(float *)(v63 + 88);
      bodyInfo.m_angularDamping = *(float *)(v63 + 92);
      bodyInfo.m_mass = *(float *)(v58 + 144);
      v217.0 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase>)transform.m_quad;
      *(hkVector4f *)&v217.mTypeUID = (hkVector4f)direction.m_quad;
      *(hkVector4f *)&v217.mData = (hkVector4f)stru_141A71280.m_quad;
      *(_OWORD *)ptr = 0i64;
      ((void (__fastcall *)(__int64, UFG::qReflectHandleBase *, __int64, UFG::qReflectHandleBase *, UFG::qSafePointerNode<UFG::RagdollData>Vtbl *))bodyInfo.m_shape->vfptr[2].__vecDelDtor)(
        v64,
        &v217,
        v65,
        &v212,
        check_null);
      halfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(*(__m128 *)&v212.mTypeUID, (__m128)v212.0), (__m128)xmmword_141A711B0);
      hkInertiaTensorComputer::computeBoxVolumeMassPropertiesDiagonalized(
        &v204,
        &halfExtents,
        bodyInfo.m_mass,
        &inertiaDiagonal,
        &volume);
      v66 = bodyInfo.m_inertiaTensor.m_col0.m_quad;
      v66.m128_f32[0] = inertiaDiagonal.m_quad.m128_f32[0] * *(float *)(v63 + 108);
      bodyInfo.m_inertiaTensor.m_col0.m_quad = v66;
      v66.m128_f32[0] = inertiaDiagonal.m_quad.m128_f32[1] * *(float *)(v63 + 108);
      v67.m_quad = (__m128)bodyInfo.m_inertiaTensor.m_col1;
      bodyInfo.m_inertiaTensor.m_col1.m_quad = _mm_shuffle_ps(
                                                 _mm_unpacklo_ps(
                                                   bodyInfo.m_inertiaTensor.m_col1.m_quad,
                                                   _mm_shuffle_ps(v66, v66, 0)),
                                                 bodyInfo.m_inertiaTensor.m_col1.m_quad,
                                                 228);
      v67.m_quad.m128_f32[0] = inertiaDiagonal.m_quad.m128_f32[2] * *(float *)(v63 + 108);
      bodyInfo.m_inertiaTensor.m_col2.m_quad = _mm_shuffle_ps(
                                                 bodyInfo.m_inertiaTensor.m_col2.m_quad,
                                                 _mm_unpackhi_ps(
                                                   bodyInfo.m_inertiaTensor.m_col2.m_quad,
                                                   _mm_shuffle_ps(v67.m_quad, v67.m_quad, 0)),
                                                 180);
      hkpInertiaTensorComputer::clipInertia(3.0, &bodyInfo);
      bodyInfo.m_position = transforms.m_data[v59].m_translation;
      bodyInfo.m_rotation = transforms.m_data[v59].m_rotation;
      bodyInfo.m_collisionFilterInfo = *(_DWORD *)(v63 + 184);
      v68 = ++*(_BYTE *)(v57 + 80);
      v69 = v68;
      *(_DWORD *)(v57 + 4 * v69) = 0;
      *(_QWORD *)(v57 + 8 * v69 + 16) = "hkpRigidBody";
      *(_QWORD *)(v57 + 8 * v69 + 48) = 0i64;
      v70 = *(_BYTE *)(v57 + 81);
      if ( v68 > v70 )
        v70 = v68;
      *(_BYTE *)(v57 + 81) = v70;
      v71 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v72 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v71[11] + 8i64))(v71[11], 720i64);
      v206 = v72;
      if ( v72 )
      {
        hkpRigidBody::hkpRigidBody(v72, &bodyInfo);
        v74 = v73;
      }
      else
      {
        v74 = 0i64;
      }
      UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(*(_QWORD *)(v63 + 8), v74);
      v75 = *(_BYTE *)(v57 + 80);
      if ( v75 > 0 )
      {
        *(_BYTE *)(v57 + 80) = v75 - 1;
      }
      else
      {
        *(_BYTE *)(v57 + 80) = 0;
        *(_DWORD *)v57 = 3;
        *(_QWORD *)(v57 + 16) = 0i64;
        *(_QWORD *)(v57 + 48) = 0i64;
      }
      transforms.m_data->m_translation.m_quad.m128_u64[v201] = (unsigned __int64)v74;
      v56 = v222[0].m_enum + 1;
      v222[0].m_enum = v56;
      v49 = p;
    }
    while ( (unsigned int)v56 < *((_DWORD *)p + 22) );
    v12 = v211;
    v29 = -1i64;
  }
  v76 = (void (__fastcall ***)(void *, signed __int64))*(unsigned int *)(v12 + 168);
  array = 0i64;
  volume = 0.0;
  v204.m_enum = 2147483648;
  LODWORD(v206) = (_DWORD)v76;
  if ( (_DWORD)v76 )
  {
    v77 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v78 = v77;
    v79 = (((8 * (_DWORD)v76 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v80 = (hkpConstraintInstance **)v77->m_cur;
    v81 = (char *)v80 + v79;
    if ( v79 > v78->m_slabSize || v81 > v78->m_end )
      v80 = (hkpConstraintInstance **)hkLifoAllocator::allocateFromNewSlab(v78, v79);
    else
      v78->m_cur = v81;
  }
  else
  {
    v80 = 0i64;
  }
  array = v80;
  v204.m_enum = (unsigned int)v76 | 0x80000000;
  p = v80;
  if ( (signed int)(((unsigned int)v76 | 0x80000000) & 0x3FFFFFFF) < (signed int)v76 )
  {
    v82 = (signed int)v76;
    if ( (signed int)v76 < (signed int)(2 * (((unsigned int)v76 | 0x80000000) & 0x3FFFFFFF)) )
      v82 = 2 * (((unsigned int)v76 | 0x80000000) & 0x3FFFFFFF);
    hkArrayUtil::_reserve(v222, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v82, 8);
  }
  volume = *(float *)&v76;
  if ( (_DWORD)v76 )
  {
    v83 = 0i64;
    v84 = v76;
    do
    {
      array[v83] = 0i64;
      ++v83;
      v84 = (void (__fastcall ***)(void *, signed __int64))((char *)v84 - 1);
    }
    while ( v84 );
  }
  v85 = 0;
  result.mUID = 0;
  p = v76;
  if ( (_DWORD)v76 )
  {
    while ( 1 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(
        &v212,
        (UFG::qReflectHandleBase *)(*(_QWORD *)(v12 + 160) + 40i64 * v85));
      if ( !v212.mData )
        goto LABEL_160;
      if ( !BYTE5(v212.mData[1].mBaseNode.mParent) )
      {
        v86 = UFG::qReflectObject::GetName(v212.mData);
        UFG::qPrintf("RagdollFactory constraint %s is not set to use TOI, is that correct?\n", v86);
      }
      v87 = -1;
      v222[0].m_enum = -1;
      v88 = -1i64;
      v89 = -1;
      LODWORD(v201) = -1;
      v90 = 0;
      v91 = 0i64;
      v92 = UFG::gpRagDollSkeleton->mhkaSkeleton;
      v93 = v92->m_bones.m_size;
      if ( v93 > 0 )
        break;
LABEL_109:
      v96 = (__int32)v9[3].m_SafePointerList.mNode.mPrev;
      if ( (v87 > v96 || v89 > v96) && HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) == -1 )
        HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) = v85 - 1;
      v97 = (hkpRigidBody *)transforms.m_data->m_translation.m_quad.m128_u64[v88];
      v98 = (hkpRigidBody *)transforms.m_data->m_translation.m_quad.m128_u64[v29];
      UFG::qReflectHandleBase::qReflectHandleBase(&other);
      other.mTypeUID = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&other, other.mTypeUID, v212.mData->mBaseNode.mUID);
      v99 = v212.mData->mTypeUID;
      v101 = UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef>::GetStaticTypeName(v100);
      if ( v99 == UFG::qStringHash64(v101, 0xFFFFFFFFFFFFFFFFui64) )
      {
        v103 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
        v206 = v103;
        if ( v103 )
        {
          *(_QWORD *)&v222[0].m_enum = &v220;
          UFG::qReflectHandleBase::qReflectHandleBase(&v220, &other);
          UFG::Constraint::Constraint(
            (UFG::Constraint *)v103,
            (UFG::qReflectHandle<UFG::qReflectObject> *)&v220,
            v98,
            v97);
          *(_QWORD *)&v222[0].m_enum = v104;
        }
        else
        {
          *(_QWORD *)&v222[0].m_enum = 0i64;
        }
      }
      else
      {
        v105 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
        v206 = v105;
        if ( v105 )
        {
          *(_QWORD *)&v222[0].m_enum = &v217;
          UFG::qReflectHandleBase::qReflectHandleBase(&v217, &other);
          UFG::Constraint::Constraint(
            (UFG::Constraint *)v105,
            (UFG::qReflectHandle<UFG::qReflectObject> *)&v217,
            v97,
            v98);
          *(_QWORD *)&v222[0].m_enum = v106;
        }
        else
        {
          *(_QWORD *)&v222[0].m_enum = 0i64;
        }
      }
      v76 = *(void (__fastcall ****)(void *, signed __int64))&v222[0].m_enum;
      v107 = *(hkpConstraintInstance **)(*(_QWORD *)&v222[0].m_enum + 40i64);
      if ( !v223 )
        hkpConstraintInstance::setPriority(v107, PRIORITY_PSI);
      v108 = UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef>::GetStaticTypeName(v102);
      if ( v99 == UFG::qStringHash64(v108, 0xFFFFFFFFFFFFFFFFui64) )
      {
        v110 = v212.mData;
        v111 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v112 = ++*(_BYTE *)(v111 + 80);
        v113 = v112;
        *(_DWORD *)(v111 + 4 * v113) = 3;
        *(_QWORD *)(v111 + 8 * v113 + 16) = "hkpPositionConstraintMotor";
        *(_QWORD *)(v111 + 8 * v113 + 48) = 0i64;
        v114 = *(_BYTE *)(v111 + 81);
        if ( v112 > v114 )
          v114 = v112;
        *(_BYTE *)(v111 + 81) = v114;
        v115 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v116 = (hkpPositionConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v115[11] + 8i64))(
                                               v115[11],
                                               48i64);
        v206 = v116;
        if ( v116 )
        {
          hkpPositionConstraintMotor::hkpPositionConstraintMotor(v116, 0.0);
          v118 = v117;
        }
        else
        {
          v118 = 0i64;
        }
        v119 = *(_BYTE *)(v111 + 80);
        if ( v119 > 0 )
        {
          *(_BYTE *)(v111 + 80) = v119 - 1;
        }
        else
        {
          *(_BYTE *)(v111 + 80) = 0;
          *(_DWORD *)v111 = 3;
          *(_QWORD *)(v111 + 16) = 0i64;
          *(_QWORD *)(v111 + 48) = 0i64;
        }
        *(_DWORD *)(v118 + 32) = v110[2].mBaseNode.mUID;
        *(_DWORD *)(v118 + 36) = HIDWORD(v110[2].mBaseNode.mUID);
        *(_DWORD *)(v118 + 28) = HIDWORD(v110[2].vfptr);
        *(_DWORD *)(v118 + 40) = v110[2].mBaseNode.mParent;
        v120 = HIDWORD(v110[2].mBaseNode.mParent);
      }
      else
      {
        v121 = UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef>::GetTypeName(v109);
        if ( v99 != UFG::qStringHash64(v121, 0xFFFFFFFFFFFFFFFFui64) )
        {
          v135 = UFG::qReflectObjectType<UFG::ConstraintDefBallAndSocket,UFG::ConstraintDef>::GetTypeName(v122);
          if ( v99 != UFG::qStringHash64(v135, 0xFFFFFFFFFFFFFFFFui64) )
          {
            v137 = UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::GetStaticTypeName(v136);
            UFG::qStringHash64(v137, 0xFFFFFFFFFFFFFFFFui64);
          }
          hkReferencedObject::addReference((hkReferencedObject *)&v107->vfptr);
          goto LABEL_152;
        }
        v123 = v212.mData;
        v111 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v124 = ++*(_BYTE *)(v111 + 80);
        v125 = v124;
        *(_DWORD *)(v111 + 4 * v125) = 3;
        *(_QWORD *)(v111 + 8 * v125 + 16) = "hkpPositionConstraintMotor";
        *(_QWORD *)(v111 + 8 * v125 + 48) = 0i64;
        v126 = *(_BYTE *)(v111 + 81);
        if ( v124 > v126 )
          v126 = v124;
        *(_BYTE *)(v111 + 81) = v126;
        v127 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v128 = (hkpPositionConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v127[11] + 8i64))(
                                               v127[11],
                                               48i64);
        v206 = v128;
        if ( v128 )
        {
          hkpPositionConstraintMotor::hkpPositionConstraintMotor(v128, 0.0);
          v118 = v129;
        }
        else
        {
          v118 = 0i64;
        }
        v130 = *(_BYTE *)(v111 + 80);
        if ( v130 > 0 )
        {
          *(_BYTE *)(v111 + 80) = v130 - 1;
        }
        else
        {
          *(_BYTE *)(v111 + 80) = 0;
          *(_DWORD *)v111 = 3;
          *(_QWORD *)(v111 + 16) = 0i64;
          *(_QWORD *)(v111 + 48) = 0i64;
        }
        *(_DWORD *)(v118 + 32) = v123[2].mBaseNode.mChildren[1];
        *(_DWORD *)(v118 + 36) = HIDWORD(v123[2].mBaseNode.mChildren[1]);
        *(_DWORD *)(v118 + 28) = HIDWORD(v123[2].mBaseNode.mChildren[0]);
        *(_DWORD *)(v118 + 40) = v123[2].mBaseNode.mNeighbours[0];
        v120 = HIDWORD(v123[2].mBaseNode.mNeighbours[0]);
      }
      *(_DWORD *)(v118 + 44) = v120;
      v131 = ++*(_BYTE *)(v111 + 80);
      v132 = v131;
      *(_DWORD *)(v111 + 4 * v132) = 3;
      *(_QWORD *)(v111 + 8 * v132 + 16) = "convertToPowered";
      *(_QWORD *)(v111 + 8 * v132 + 48) = 0i64;
      v133 = *(_BYTE *)(v111 + 81);
      if ( v131 > v133 )
        v133 = v131;
      *(_BYTE *)(v111 + 81) = v133;
      v107 = hkpConstraintUtils::convertToPowered(v107, (hkpConstraintMotor *)v118, 0);
      hkReferencedObject::removeReference((hkReferencedObject *)v118);
      v134 = *(_BYTE *)(v111 + 80);
      if ( v134 > 0 )
      {
        *(_BYTE *)(v111 + 80) = v134 - 1;
      }
      else
      {
        *(_BYTE *)(v111 + 80) = 0;
        *(_DWORD *)v111 = 3;
        *(_QWORD *)(v111 + 16) = 0i64;
        *(_QWORD *)(v111 + 48) = 0i64;
      }
      v76 = *(void (__fastcall ****)(void *, signed __int64))&v222[0].m_enum;
LABEL_152:
      if ( array[v29 - 1] )
      {
        v138 = (char *)p - 1;
        if ( (_QWORD)((_QWORD)p - 1) >= 0 )
        {
          while ( array[(_QWORD)v138] )
          {
            if ( (signed __int64)--v138 < 0 )
              goto LABEL_159;
          }
          array[(_QWORD)v138] = v107;
        }
      }
      else
      {
        array[v29 - 1] = v107;
      }
LABEL_159:
      (**v76)(v76, 1i64);
      UFG::qReflectHandleBase::~qReflectHandleBase(&other);
      v12 = v211;
      v85 = result.mUID;
      *(float *)&v76 = volume;
LABEL_160:
      UFG::qReflectHandleBase::~qReflectHandleBase(&v212);
      result.mUID = ++v85;
      if ( v85 >= (unsigned int)v76 )
        goto LABEL_161;
      v29 = -1i64;
    }
    v94 = 0i64;
    if ( v93 <= 0 )
    {
      v95 = 0i64;
      goto LABEL_100;
    }
    while ( 1 )
    {
      v95 = (const char *)((_QWORD)v92->m_bones.m_data[v94].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
LABEL_100:
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&v204, v95);
      if ( v204.m_enum == HIDWORD(v212.mData[1].vfptr) )
        break;
      v87 = v222[0].m_enum;
      if ( v204.m_enum != LODWORD(v212.mData[1].mBaseNode.mUID) )
        goto LABEL_104;
      v89 = v90;
      LODWORD(v201) = v90;
      v29 = v91;
LABEL_105:
      if ( v88 == -1 || v29 == -1 )
      {
        ++v90;
        ++v91;
        ++v94;
        v92 = UFG::gpRagDollSkeleton->mhkaSkeleton;
        if ( v90 < v92->m_bones.m_size )
          continue;
      }
      v85 = result.mUID;
      goto LABEL_109;
    }
    v87 = v90;
    v222[0].m_enum = v90;
    v88 = v91;
LABEL_104:
    v89 = v201;
    goto LABEL_105;
  }
LABEL_161:
  if ( HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) == -1 )
    HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) = LODWORD(volume) - 1;
  hkpInertiaTensorComputer::optimizeInertiasOfConstraintTree(
    array,
    HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) + 1,
    (hkpRigidBody *)transforms.m_data->m_translation.m_quad.m128_u64[0],
    1.5);
  v139 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v140 = ++*(_BYTE *)(v139 + 80);
  v141 = v140;
  *(_DWORD *)(v139 + 4 * v141) = 3;
  *(_QWORD *)(v139 + 8 * v141 + 16) = "hkaRagdollInstance";
  *(_QWORD *)(v139 + 8 * v141 + 48) = 0i64;
  v142 = *(_BYTE *)(v139 + 81);
  if ( v140 > v142 )
    v142 = v140;
  *(_BYTE *)(v139 + 81) = v142;
  v143 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v144 = (hkaRagdollInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v143[11] + 8i64))(v143[11], 72i64);
  *(_QWORD *)&v222[0].m_enum = v144;
  if ( v144 )
    hkaRagdollInstance::hkaRagdollInstance(
      v144,
      (hkArrayBase<hkpRigidBody *> *)&transforms,
      (hkArrayBase<hkpConstraintInstance *> *)&array,
      (hkaSkeleton *)v9[1].vfptr);
  else
    v145 = 0i64;
  v9[5].vfptr = v145;
  v146 = *(_BYTE *)(v139 + 80);
  if ( v146 > 0 )
  {
    *(_BYTE *)(v139 + 80) = v146 - 1;
  }
  else
  {
    *(_BYTE *)(v139 + 80) = 0;
    *(_DWORD *)v139 = 3;
    *(_QWORD *)(v139 + 16) = 0i64;
    *(_QWORD *)(v139 + 48) = 0i64;
  }
  v147 = 0;
  if ( SLODWORD(volume) > 0 )
  {
    v148 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&array[v148]->vfptr);
      ++v147;
      ++v148;
    }
    while ( v147 < SLODWORD(volume) );
  }
  v149 = 0;
  if ( transforms.m_size > 0 )
  {
    v150 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)transforms.m_data->m_translation.m_quad.m128_u64[v150]);
      ++v149;
      ++v150;
    }
    while ( v149 < transforms.m_size );
  }
  LODWORD(v9[3].m_SafePointerList.mNode.mNext) = *(_DWORD *)(v12 + 132);
  HIDWORD(v9[3].m_SafePointerList.mNode.mNext) = *(_DWORD *)(v12 + 136);
  LODWORD(v9[4].vfptr) = *(_DWORD *)(v12 + 140);
  v151 = (signed int)v210;
  if ( (unsigned int)v210 > HIDWORD(v9[2].vfptr) && (_DWORD)v210 != LODWORD(v9[2].vfptr) )
  {
    v152 = 4i64 * (unsigned int)v210;
    if ( !is_mul_ok((unsigned int)v210, 4ui64) )
      v152 = -1i64;
    v153 = UFG::qMalloc(v152, "qArray.Reallocate(Reserve)", 0i64);
    if ( v9[2].m_SafePointerList.mNode.mPrev )
    {
      v154 = 0;
      if ( LODWORD(v9[2].vfptr) )
      {
        do
        {
          *((_DWORD *)&v153->mNext + v154) = *((_DWORD *)&v9[2].m_SafePointerList.mNode.mPrev->mPrev + v154);
          ++v154;
        }
        while ( v154 < LODWORD(v9[2].vfptr) );
      }
      operator delete[](v9[2].m_SafePointerList.mNode.mPrev);
    }
    v9[2].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)v153;
    HIDWORD(v9[2].vfptr) = v151;
  }
  v155 = (unsigned int)v9[2].vfptr;
  if ( (signed int)(v151 - v155) <= 0 )
  {
    if ( v155 != (_DWORD)v151 )
    {
      if ( v155 - (unsigned int)v151 < v155 )
        LODWORD(v9[2].vfptr) = v151;
      else
        LODWORD(v9[2].vfptr) = 0;
    }
  }
  else
  {
    v156 = HIDWORD(v9[2].vfptr);
    if ( (unsigned int)v151 > v156 )
    {
      if ( v156 )
        v157 = 2 * v156;
      else
        v157 = 1;
      for ( ; v157 < (unsigned int)v151; v157 *= 2 )
        ;
      if ( v157 <= 4 )
        v157 = 4;
      if ( v157 - (unsigned int)v151 > 0x10000 )
        v157 = v151 + 0x10000;
      if ( v157 != v155 )
      {
        v158 = 4i64 * v157;
        if ( !is_mul_ok(v157, 4ui64) )
          v158 = -1i64;
        v159 = UFG::qMalloc(v158, "qArray.Reallocate(Resize)", 0i64);
        if ( v9[2].m_SafePointerList.mNode.mPrev )
        {
          v160 = 0;
          if ( LODWORD(v9[2].vfptr) )
          {
            do
            {
              *((_DWORD *)&v159->mNext + v160) = *((_DWORD *)&v9[2].m_SafePointerList.mNode.mPrev->mPrev + v160);
              ++v160;
            }
            while ( v160 < LODWORD(v9[2].vfptr) );
          }
          operator delete[](v9[2].m_SafePointerList.mNode.mPrev);
        }
        v9[2].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)v159;
        HIDWORD(v9[2].vfptr) = v157;
      }
    }
    LODWORD(v9[2].vfptr) = v151;
  }
  v161 = 0i64;
  if ( (signed int)v151 > 0 )
  {
    do
      *((_DWORD *)&v9[2].m_SafePointerList.mNode.mPrev->mPrev + v161++) = 21;
    while ( v161 < v151 );
  }
  v162 = 0;
  if ( *(_DWORD *)(v12 + 184) )
  {
    do
    {
      v163 = Skeleton::GetBoneID(UFG::gpRagDollSkeleton, *(_DWORD *)(*(_QWORD *)(v12 + 176) + 12i64 * v162));
      if ( v163 != -1 )
        *((_DWORD *)&v9[2].m_SafePointerList.mNode.mPrev->mPrev + v163) = 32
                                                                        * (*(_DWORD *)(*(_QWORD *)(v12 + 176)
                                                                                     + 12i64 * v162
                                                                                     + 4) | 32
                                                                                          * *(_DWORD *)(*(_QWORD *)(v12 + 176) + 12i64 * v162 + 8));
      ++v162;
    }
    while ( v162 < *(_DWORD *)(v12 + 184) );
  }
  v164 = 0;
  v165 = (unsigned int)v9[2].vfptr;
  if ( v165 )
  {
    do
      ++v164;
    while ( v164 < v165 );
  }
  v166 = 0;
  for ( i = SLODWORD(v9[1].vfptr[4].__vecDelDtor); v166 <= SLODWORD(v9[3].m_SafePointerList.mNode.mPrev); ++v166 )
  {
    v168 = 0i64;
    if ( i <= 0 )
    {
LABEL_223:
      v170 = LODWORD(v9[2].m_SafePointerList.mNode.mNext);
      v223 = v170;
      v171 = v170 + 1;
      v172 = HIDWORD(v9[2].m_SafePointerList.mNode.mNext);
      if ( (signed int)v170 + 1 > v172 )
      {
        if ( v172 )
          v173 = 2 * v172;
        else
          v173 = 1;
        for ( ; v173 < v171; v173 *= 2 )
          ;
        if ( v173 <= 4 )
          v173 = 4;
        if ( v173 - v171 > 0x10000 )
          v173 = v170 + 65537;
        if ( v173 != (_DWORD)v170 )
        {
          v174 = 4i64 * v173;
          if ( !is_mul_ok(v173, 4ui64) )
            v174 = -1i64;
          v175 = UFG::qMalloc(v174, "qArray.Add", 0i64);
          if ( v9[3].vfptr )
          {
            v176 = 0;
            if ( LODWORD(v9[2].m_SafePointerList.mNode.mNext) )
            {
              do
              {
                *((_DWORD *)&v175->mNext + v176) = *((_DWORD *)&v9[3].vfptr->__vecDelDtor + v176);
                ++v176;
              }
              while ( v176 < LODWORD(v9[2].m_SafePointerList.mNode.mNext) );
            }
            operator delete[](v9[3].vfptr);
          }
          v9[3].vfptr = (UFG::qSafePointerNode<UFG::RagdollData>Vtbl *)v175;
          HIDWORD(v9[2].m_SafePointerList.mNode.mNext) = v173;
          v170 = v223;
        }
      }
      LODWORD(v9[2].m_SafePointerList.mNode.mNext) = v171;
      *((_DWORD *)&v9[3].vfptr->__vecDelDtor + v170) = v166;
    }
    else
    {
      v169 = v9[1].vfptr[3].__vecDelDtor;
      while ( *(signed __int16 *)v169 != v166 )
      {
        ++v168;
        v169 = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::RagdollData> *, unsigned int))((char *)v169 + 2);
        if ( v168 >= i )
          goto LABEL_223;
      }
    }
  }
  v177 = UFG::gpRagDollSkeleton;
  if ( UFG::gpRagDollSkeleton )
  {
    _((AMD_HD3D *)UFG::gpRagDollSkeleton);
    operator delete[](v177);
  }
  UFG::gpRagDollSkeleton = 0i64;
  v178 = v221;
  v179 = v221->mSkeletonMapper;
  if ( v179 )
  {
    UFG::RagdollSkeletonMapper::~RagdollSkeletonMapper(v221->mSkeletonMapper);
    operator delete[](v179);
  }
  v178->mSkeletonMapper = 0i64;
  v180 = (char *)p;
  v181 = volume;
  if ( p == array )
    v181 = 0.0;
  volume = v181;
  v182 = (signed int)v206;
  v183 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v184 = (8 * v182 + 127) & 0xFFFFFF80;
  v185 = (v184 + 15) & 0xFFFFFFF0;
  if ( v184 > v183->m_slabSize || &v180[v185] != v183->m_cur || v183->m_firstNonLifoEnd == v180 )
    hkLifoAllocator::slowBlockFree(v183, v180, v185);
  else
    v183->m_cur = v180;
  volume = 0.0;
  if ( (signed int)v204.m_enum >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v204.m_enum);
  array = 0i64;
  v204.m_enum = 2147483648;
  v186 = (char *)v208;
  v187 = transforms.m_size;
  if ( v208 == transforms.m_data )
    v187 = 0;
  transforms.m_size = v187;
  v188 = v209;
  v189 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v190 = (8 * v188 + 127) & 0xFFFFFF80;
  v191 = (v190 + 15) & 0xFFFFFFF0;
  if ( v190 > v189->m_slabSize || &v186[v191] != v189->m_cur || v189->m_firstNonLifoEnd == v186 )
    hkLifoAllocator::slowBlockFree(v189, v186, v191);
  else
    v189->m_cur = v186;
  transforms.m_size = 0;
  if ( transforms.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      transforms.m_data,
      8 * transforms.m_capacityAndFlags);
  transforms.m_data = 0i64;
  transforms.m_capacityAndFlags = 2147483648;
  v192 = (char *)v208;
  v193 = transforms.m_size;
  if ( !v208 )
    v193 = 0;
  transforms.m_size = v193;
  v194 = v209;
  v195 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v196 = (48 * v194 + 127) & 0xFFFFFF80;
  v197 = (v196 + 15) & 0xFFFFFFF0;
  if ( v196 > v195->m_slabSize || &v192[v197] != v195->m_cur || v195->m_firstNonLifoEnd == v192 )
    hkLifoAllocator::slowBlockFree(v195, v192, v197);
  else
    v195->m_cur = v192;
  transforms.m_size = 0;
  if ( transforms.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      transforms.m_data,
      48 * (transforms.m_capacityAndFlags & 0x3FFFFFFF));
  return v9;
}onLifoEnd == v186 )
    hkLifoAllocator::slowBlockFree(v189, v186, v191);
  else
    v189->m_cur = v186;
  transforms.m_size = 0;
  if ( transforms.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      transforms.m_data,
      8 * transforms.m_capacityAndFlags);
  transforms.m_data = 0i64;
  transforms.m_capacityAndFlags = 2147483648;
  v192 = (char *)v208;
  v193 = transform

// File Line: 1012
// RVA: 0x459270
void __fastcall UFG::RagdollFactory::BuildAndSetReferencePose(UFG::RagdollFactory *this, UFG::RagdollData *data, Skeleton *skeleton, hkArray<hkQsTransformf,hkContainerHeapAllocator> *transforms)
{
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v4; // rbx
  hkaSkeleton *v5; // r14
  signed __int64 v6; // r15
  char v7; // di
  __int64 v8; // rax
  int v9; // esi
  char v10; // cl
  _QWORD **v11; // rax
  __int64 v12; // rax
  hkaPose *v13; // r12
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v14; // rcx
  int v15; // edi
  int v16; // er13
  int v17; // eax
  int v18; // eax
  int v19; // er9
  int v20; // eax
  int v21; // eax
  int v22; // er9
  int v23; // eax
  int v24; // eax
  int v25; // er9
  int v26; // er13
  int v27; // er9
  int v28; // eax
  int v29; // eax
  int v30; // er9
  int v31; // edx
  float *v32; // rdi
  __int64 v33; // rcx
  char v34; // al
  char v35; // dl
  __int64 v36; // rax
  char v37; // cl
  _QWORD **v38; // rax
  __int64 v39; // rax
  hkaPose *v40; // r14
  __int64 v41; // r13
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v42; // rdx
  _DWORD *v43; // r8
  int v44; // edi
  int v45; // ecx
  signed __int64 v46; // rcx
  int v47; // eax
  int v48; // eax
  int v49; // er9
  signed __int64 v50; // rcx
  int v51; // eax
  int v52; // eax
  int v53; // er9
  signed __int64 v54; // rcx
  int v55; // eax
  int v56; // eax
  int v57; // er9
  hkResultEnum v58; // er8
  int v59; // er9
  signed __int64 v60; // rdi
  int v61; // eax
  int v62; // eax
  int v63; // er9
  int v64; // edx
  __int64 v65; // rcx
  float *v66; // rdi
  char v67; // al
  int v68; // edi
  __int64 v69; // r15
  __int64 v70; // rdx
  __int64 v71; // rcx
  __int64 v72; // r8
  signed __int16 *v73; // rcx
  __int64 v74; // rdx
  hkQsTransformf *v75; // rax
  hkaPose *v76; // rcx
  hkVector4f v77; // xmm6
  hkQuaternionf v78; // xmm7
  hkVector4f v79; // xmm8
  __m128 *v80; // rcx
  __int64 v81; // r15
  __int64 v82; // rdx
  __int64 v83; // r9
  unsigned int *v84; // r8
  hkQsTransformf *v85; // rdi
  __int16 v86; // ax
  hkQsTransformf *v87; // r13
  hkQsTransformf *v88; // rbx
  __m128i v89; // xmm0
  __m128 v90; // xmm8
  __m128 v91; // xmm2
  __m128 v92; // xmm9
  __m128 v93; // xmm7
  __m128 v94; // xmm3
  __m128 v95; // xmm1
  __m128 v96; // xmm5
  __m128 v97; // xmm4
  __m128 v98; // xmm2
  __m128 v99; // xmm3
  __m128 v100; // xmm2
  __m128 v101; // xmm4
  __m128 v102; // xmm4
  __m128 v103; // xmm3
  hkQsTransformf *v104; // rax
  _OWORD *v105; // rcx
  __int64 v106; // rax
  _QWORD **v107; // rax
  _QWORD **v108; // rax
  hkResult v109; // [rsp+Ch] [rbp-7Dh]
  hkResult v110; // [rsp+10h] [rbp-79h]
  hkResult v111[2]; // [rsp+18h] [rbp-71h]
  int sizeElem[2]; // [rsp+20h] [rbp-69h]
  __int64 v113; // [rsp+28h] [rbp-61h]
  hkResult v114[2]; // [rsp+30h] [rbp-59h]
  hkVector4f v115; // [rsp+38h] [rbp-51h]
  __m128 v116; // [rsp+48h] [rbp-41h]
  __m128 v117; // [rsp+58h] [rbp-31h]
  void *p; // [rsp+F0h] [rbp+67h]
  hkResult result[2]; // [rsp+F8h] [rbp+6Fh]
  __int64 v120; // [rsp+108h] [rbp+7Fh]

  v113 = -2i64;
  v4 = transforms;
  v5 = skeleton->mhkaSkeleton;
  v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v7 = ++*(_BYTE *)(v6 + 80);
  v8 = v7;
  *(_DWORD *)(v6 + 4 * v8) = 2;
  *(_QWORD *)(v6 + 8 * v8 + 16) = "hkaPose4";
  v9 = 0;
  *(_QWORD *)(v6 + 8 * v8 + 48) = 0i64;
  v10 = *(_BYTE *)(v6 + 81);
  if ( v7 > v10 )
    v10 = v7;
  *(_BYTE *)(v6 + 81) = v10;
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 80i64);
  v13 = (hkaPose *)v12;
  *(_QWORD *)sizeElem = v12;
  *(_QWORD *)&v111[0].m_enum = v12;
  if ( v12 )
  {
    *(_QWORD *)v12 = v5;
    v14 = (hkArray<hkQsTransformf,hkContainerHeapAllocator> *)(v12 + 8);
    v14->m_data = 0i64;
    v14->m_size = 0;
    v14->m_capacityAndFlags = 2147483648;
    *(_QWORD *)(v12 + 24) = 0i64;
    *(_DWORD *)(v12 + 32) = 0;
    *(_DWORD *)(v12 + 36) = 2147483648;
    *(_QWORD *)(v12 + 40) = 0i64;
    *(_DWORD *)(v12 + 48) = 0;
    *(_DWORD *)(v12 + 52) = 2147483648;
    *(_WORD *)(v12 + 56) = 0;
    *(_QWORD *)(v12 + 64) = 0i64;
    *(_DWORD *)(v12 + 72) = 0;
    *(_DWORD *)(v12 + 76) = 2147483648;
    v15 = *(_DWORD *)(*(_QWORD *)v12 + 48i64);
    v16 = (v15 + 3) & 0xFFFFFFFC;
    if ( (*(_DWORD *)(v12 + 36) & 0x3FFFFFFF) >= v16 )
    {
      result[0].m_enum = 0;
    }
    else
    {
      hkArrayUtil::_reserve(
        result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (void *)(v12 + 24),
        v16,
        48);
      v14 = &v13->m_localPose;
    }
    if ( (v14->m_capacityAndFlags & 0x3FFFFFFF) >= v16 )
      v109.m_enum = 0;
    else
      hkArrayUtil::_reserve(&v109, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v14, v16, 48);
    if ( (v13->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v16 )
      v115.m_quad.m128_i32[0] = 0;
    else
      hkArrayUtil::_reserve(
        (hkResult *)&v115,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v13->m_boneFlags,
        v16,
        4);
    v17 = v13->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 >= v15 )
    {
      v115.m_quad.m128_i32[2] = 0;
    }
    else
    {
      v18 = 2 * v17;
      v19 = v15;
      if ( v15 < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(
        (hkResult *)&v115.m_quad.m128_u16[4],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v13->m_modelPose,
        v19,
        48);
    }
    v13->m_modelPose.m_size = v15;
    v20 = v13->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v20 >= v15 )
    {
      v114[1].m_enum = 0;
    }
    else
    {
      v21 = 2 * v20;
      v22 = v15;
      if ( v15 < v21 )
        v22 = v21;
      hkArrayUtil::_reserve(
        &v114[1],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v13->m_localPose,
        v22,
        48);
    }
    v13->m_localPose.m_size = v15;
    v23 = v13->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v23 >= v15 )
    {
      v115.m_quad.m128_i32[1] = 0;
    }
    else
    {
      v24 = 2 * v23;
      v25 = v15;
      if ( v15 < v24 )
        v25 = v24;
      hkArrayUtil::_reserve(
        (hkResult *)&v115.m_quad.m128_i16[2],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v13->m_boneFlags,
        v25,
        4);
    }
    v13->m_boneFlags.m_size = v15;
    v26 = v13->m_skeleton->m_floatSlots.m_size;
    v27 = (v26 + 3) & 0xFFFFFFFC;
    if ( (v13->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v27 )
      v114[0].m_enum = 0;
    else
      hkArrayUtil::_reserve(
        v114,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v13->m_floatSlotValues,
        v27,
        4);
    v28 = v13->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v28 >= v26 )
    {
      v110.m_enum = 0;
    }
    else
    {
      v29 = 2 * v28;
      v30 = v26;
      if ( v26 < v29 )
        v30 = v29;
      hkArrayUtil::_reserve(
        &v110,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v13->m_floatSlotValues,
        v30,
        4);
    }
    v31 = v26 - v13->m_floatSlotValues.m_size;
    v32 = &v13->m_floatSlotValues.m_data[v13->m_floatSlotValues.m_size];
    v33 = v31;
    if ( v31 > 0 )
    {
      while ( v33 )
      {
        *v32 = 0.0;
        ++v32;
        --v33;
      }
    }
    v13->m_floatSlotValues.m_size = v26;
  }
  else
  {
    v13 = 0i64;
    *(_QWORD *)sizeElem = 0i64;
  }
  hkaPose::setToReferencePose(v13);
  v34 = *(_BYTE *)(v6 + 80);
  if ( v34 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v34 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v35 = ++*(_BYTE *)(v6 + 80);
  v36 = v35;
  *(_DWORD *)(v6 + 4 * v36) = 2;
  *(_QWORD *)(v6 + 8 * v36 + 16) = "hkaPose5";
  *(_QWORD *)(v6 + 8 * v36 + 48) = 0i64;
  v37 = *(_BYTE *)(v6 + 81);
  if ( v35 > v37 )
    v37 = v35;
  *(_BYTE *)(v6 + 81) = v37;
  v38 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v38[11] + 8i64))(v38[11], 80i64);
  v40 = (hkaPose *)v39;
  *(_QWORD *)&v114[0].m_enum = v39;
  v41 = v120;
  if ( v39 )
  {
    *(_QWORD *)v39 = v120;
    v42 = (hkArray<hkQsTransformf,hkContainerHeapAllocator> *)(v39 + 8);
    v42->m_data = 0i64;
    v42->m_size = 0;
    v42->m_capacityAndFlags = 2147483648;
    v43 = (_DWORD *)(v39 + 24);
    *(_QWORD *)v43 = 0i64;
    v43[2] = 0;
    v43[3] = 2147483648;
    *(_QWORD *)(v39 + 40) = 0i64;
    *(_DWORD *)(v39 + 48) = 0;
    *(_DWORD *)(v39 + 52) = 2147483648;
    *(_WORD *)(v39 + 56) = 0;
    *(_QWORD *)(v39 + 64) = 0i64;
    *(_DWORD *)(v39 + 72) = 0;
    *(_DWORD *)(v39 + 76) = 2147483648;
    v44 = *(_DWORD *)(*(_QWORD *)v39 + 48i64);
    v45 = (v44 + 3) & 0xFFFFFFFC;
    result[0].m_enum = v45;
    if ( (*(_DWORD *)(v39 + 36) & 0x3FFFFFFF) >= v45 )
    {
      v110.m_enum = 0;
    }
    else
    {
      hkArrayUtil::_reserve(&v110, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v43, v45, 48);
      v45 = result[0].m_enum;
      v42 = &v40->m_localPose;
    }
    if ( (v42->m_capacityAndFlags & 0x3FFFFFFF) >= v45 )
    {
      v114[0].m_enum = 0;
    }
    else
    {
      hkArrayUtil::_reserve(v114, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v42, v45, 48);
      v45 = result[0].m_enum;
    }
    if ( (v40->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v45 )
      v115.m_quad.m128_i32[1] = 0;
    else
      hkArrayUtil::_reserve(
        (hkResult *)&v115.m_quad.m128_i16[2],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v40->m_boneFlags,
        v45,
        4);
    v46 = (signed __int64)&v40->m_modelPose;
    v47 = v40->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v47 >= v44 )
    {
      v114[1].m_enum = 0;
    }
    else
    {
      v48 = 2 * v47;
      v49 = v44;
      if ( v44 < v48 )
        v49 = v48;
      hkArrayUtil::_reserve(
        &v114[1],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v40->m_modelPose,
        v49,
        48);
      v46 = (signed __int64)&v40->m_modelPose;
    }
    *(_DWORD *)(v46 + 8) = v44;
    v50 = (signed __int64)&v40->m_localPose;
    v51 = v40->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v51 >= v44 )
    {
      v115.m_quad.m128_i32[2] = 0;
    }
    else
    {
      v52 = 2 * v51;
      v53 = v44;
      if ( v44 < v52 )
        v53 = v52;
      hkArrayUtil::_reserve(
        (hkResult *)&v115.m_quad.m128_u16[4],
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v40->m_localPose,
        v53,
        48);
      v50 = (signed __int64)&v40->m_localPose;
    }
    *(_DWORD *)(v50 + 8) = v44;
    v54 = (signed __int64)&v40->m_boneFlags;
    v55 = v40->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v55 >= v44 )
    {
      v115.m_quad.m128_i32[0] = 0;
    }
    else
    {
      v56 = 2 * v55;
      v57 = v44;
      if ( v44 < v56 )
        v57 = v56;
      hkArrayUtil::_reserve(
        (hkResult *)&v115,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v40->m_boneFlags,
        v57,
        4);
      v54 = (signed __int64)&v40->m_boneFlags;
    }
    *(_DWORD *)(v54 + 8) = v44;
    v58 = v40->m_skeleton->m_floatSlots.m_size;
    result[0].m_enum = v58;
    v59 = (v58 + 3) & 0xFFFFFFFC;
    v60 = (signed __int64)&v40->m_floatSlotValues;
    if ( (v40->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v59 )
    {
      v109.m_enum = 0;
    }
    else
    {
      hkArrayUtil::_reserve(
        &v109,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v40->m_floatSlotValues,
        v59,
        4);
      v58 = result[0].m_enum;
    }
    v61 = v40->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v61 >= v58 )
    {
      v111[0].m_enum = 0;
    }
    else
    {
      v62 = 2 * v61;
      v63 = v58;
      if ( v58 < v62 )
        v63 = v62;
      hkArrayUtil::_reserve(
        v111,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v40->m_floatSlotValues,
        v63,
        4);
      v58 = result[0].m_enum;
    }
    v64 = v58 - v40->m_floatSlotValues.m_size;
    v65 = v64;
    if ( v64 > 0 )
    {
      v66 = &v40->m_floatSlotValues.m_data[v40->m_floatSlotValues.m_size];
      while ( v65 )
      {
        *v66 = 0.0;
        ++v66;
        --v65;
      }
      v60 = (signed __int64)&v40->m_floatSlotValues;
    }
    *(_DWORD *)(v60 + 8) = v58;
  }
  else
  {
    v40 = 0i64;
  }
  hkaPose::setToReferencePose(v40);
  v67 = *(_BYTE *)(v6 + 80);
  if ( v67 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v67 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v68 = 0;
  if ( *(_DWORD *)(v41 + 48) > 0 )
  {
    v69 = 0i64;
    do
    {
      v70 = 0i64;
      v71 = *((_QWORD *)p + 4);
      v72 = *(signed int *)(v71 + 88);
      if ( v72 <= 0 )
        goto LABEL_100;
      v73 = *(signed __int16 **)(v71 + 80);
      while ( *v73 != v68 )
      {
        ++v70;
        v73 += 32;
        if ( v70 >= v72 )
          goto LABEL_100;
      }
      v74 = v73[1];
      if ( (_DWORD)v74 == -1 )
      {
LABEL_100:
        if ( v40->m_boneFlags.m_data[v69] & 2 )
        {
          LODWORD(v74) = v68;
          v76 = v40;
          goto LABEL_103;
        }
        v75 = &v40->m_modelPose.m_data[v68];
      }
      else
      {
        if ( v13->m_boneFlags.m_data[v74] & 2 )
        {
          v76 = v13;
LABEL_103:
          v75 = hkaPose::calculateBoneModelSpace(v76, v74);
          goto LABEL_104;
        }
        v75 = &v13->m_modelPose.m_data[v74];
      }
LABEL_104:
      v77.m_quad = (__m128)v75->m_translation;
      v78.m_vec.m_quad = (__m128)v75->m_rotation;
      v79.m_quad = (__m128)v75->m_scale;
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 48);
      v80 = &v4->m_data[v4->m_size].m_translation.m_quad;
      *(hkVector4f *)v80 = (hkVector4f)v77.m_quad;
      v80[1] = v78.m_vec.m_quad;
      v80[2] = v79.m_quad;
      ++v4->m_size;
      ++v68;
      ++v69;
    }
    while ( v68 < *(_DWORD *)(v41 + 48) );
  }
  hkaPose::setPoseModelSpace(v40, (hkArrayBase<hkQsTransformf> *)&v4->m_data);
  if ( *(_DWORD *)(v41 + 48) > 0 )
  {
    v81 = 0i64;
    v82 = 0i64;
    *(_QWORD *)&v111[0].m_enum = 0i64;
    v83 = 0i64;
    *(_QWORD *)&result[0].m_enum = 0i64;
    do
    {
      v84 = v40->m_boneFlags.m_data;
      if ( *((_BYTE *)v84 + v82) & 1 )
      {
        v85 = v40->m_modelPose.m_data;
        v86 = *(__int16 *)((char *)v40->m_skeleton->m_parentIndices.m_data + v83);
        if ( v86 == -1 )
        {
          v104 = v40->m_localPose.m_data;
          v104[v81].m_translation = v85[v81].m_translation;
          v104[v81].m_rotation = v85[v81].m_rotation;
          v104[v81].m_scale = v85[v81].m_scale;
        }
        else
        {
          if ( v84[v86] & 2 )
            v87 = hkaPose::calculateBoneModelSpace(v40, v86);
          else
            v87 = &v85[v86];
          v88 = v40->m_localPose.m_data;
          hkVector4f::setRotatedInverseDir(&v115, &v87->m_rotation, &v87->m_translation);
          v89 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
          v115.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v89, 0), v115.m_quad);
          v90 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v89, 64), v87->m_rotation.m_vec.m_quad);
          v116 = v90;
          v91 = _mm_rcp_ps(v87->m_scale.m_quad);
          v92 = (__m128)_mm_srli_si128(
                          _mm_slli_si128(
                            (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v91, v87->m_scale.m_quad)), v91),
                            4),
                          4);
          v117 = v92;
          v93 = _mm_shuffle_ps(v90, v90, 255);
          v94 = v85[v81].m_translation.m_quad;
          v95 = _mm_mul_ps(v85[v81].m_translation.m_quad, v90);
          v96 = _mm_shuffle_ps(v90, v90, 201);
          v97 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v90),
                  _mm_mul_ps(v85[v81].m_translation.m_quad, v96));
          v98 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                        _mm_shuffle_ps(v95, v95, 170)),
                      v90),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v93, v93), (__m128)xmmword_141A711B0), v94)),
                  _mm_mul_ps(_mm_shuffle_ps(v97, v97, 201), v93));
          v88[v81].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v98, v98), v115.m_quad);
          v99 = v85[v81].m_rotation.m_vec.m_quad;
          v100 = _mm_shuffle_ps(v99, v99, 255);
          v101 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v85[v81].m_rotation.m_vec.m_quad, v99, 201), v90),
                   _mm_mul_ps(v85[v81].m_rotation.m_vec.m_quad, v96));
          v102 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v101, v101, 201), _mm_mul_ps(v85[v81].m_rotation.m_vec.m_quad, v93)),
                   _mm_mul_ps(v100, v90));
          v103 = _mm_mul_ps(v99, v90);
          v88[v81].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                               v102,
                                               _mm_unpackhi_ps(
                                                 v102,
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(v100, v93),
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_shuffle_ps(v103, v103, 85),
                                                       _mm_shuffle_ps(v103, v103, 0)),
                                                     _mm_shuffle_ps(v103, v103, 170)))),
                                               196);
          v88[v81].m_scale.m_quad = _mm_mul_ps(v85[v81].m_scale.m_quad, v92);
          v82 = *(_QWORD *)&v111[0].m_enum;
          v41 = v120;
          v83 = *(_QWORD *)&result[0].m_enum;
        }
        *(unsigned int *)((char *)v40->m_boneFlags.m_data + v82) &= 0xFFFFFFFE;
      }
      v105 = (_OWORD *)v40->m_localPose.m_data[v9].m_translation.m_quad.m128_f32;
      v106 = *(_QWORD *)(v41 + 56);
      *(_OWORD *)(v81 * 48 + v106) = *v105;
      *(_OWORD *)(v81 * 48 + v106 + 16) = v105[1];
      *(_OWORD *)(v81 * 48 + v106 + 32) = v105[2];
      ++v9;
      v83 += 2i64;
      *(_QWORD *)&result[0].m_enum = v83;
      v82 += 4i64;
      *(_QWORD *)&v111[0].m_enum = v82;
      ++v81;
    }
    while ( v9 < *(_DWORD *)(v41 + 48) );
    v13 = *(hkaPose **)sizeElem;
  }
  if ( v40 )
  {
    hkaPose::~hkaPose(v40);
    v107 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkaPose *, signed __int64))(*v107[11] + 16i64))(v107[11], v40, 80i64);
  }
  if ( v13 )
  {
    hkaPose::~hkaPose(v13);
    v108 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkaPose *, signed __int64))(*v108[11] + 16i64))(v108[11], v13, 80i64);
  }
}*, hkaPose *, signed __int64))(*v108[11] + 16i64))(v108[11], v13, 80i64);
  }
}

// File Line: 1076
// RVA: 0x460010
void __fastcall UFG::RagdollFactory::CreateSkeletonMappings(UFG::RagdollFactory *this, Skeleton *skeleton, UFG::RagdollData *mData)
{
  UFG::RagdollData *v3; // r14
  UFG::RagdollFactory *v4; // r15
  hkaSkeleton *v5; // r10
  int v6; // esi
  int v7; // edi
  signed __int64 v8; // rbx
  char v9; // dl
  __int64 v10; // rax
  char v11; // cl
  char v12; // al
  char v13; // dl
  __int64 v14; // rax
  char v15; // cl
  _QWORD **v16; // rax
  hkaSkeletonMapper *v17; // rax
  hkaSkeletonMapper *v18; // rax
  _QWORD **v19; // rax
  hkaSkeletonMapper *v20; // rax
  hkaSkeletonMapper *v21; // rax
  char v22; // al
  hkaSkeletonMapperData array; // [rsp+40h] [rbp-98h]
  __int64 v24; // [rsp+108h] [rbp+30h]
  int v25; // [rsp+114h] [rbp+3Ch]
  __int64 v26; // [rsp+128h] [rbp+50h]
  int v27; // [rsp+134h] [rbp+5Ch]
  int v28; // [rsp+16Ch] [rbp+94h]
  hkResult result[2]; // [rsp+1A8h] [rbp+D0h]

  v3 = mData;
  v4 = this;
  v5 = skeleton->mhkaSkeleton;
  this->mSkeletonMapper->ufgSkeletonB = skeleton;
  this->mSkeletonMapper->ufgSkeletonA = UFG::gpRagDollSkeleton;
  this->mSkeletonMapper->m_skeletonB = v5;
  this->mSkeletonMapper->m_skeletonA = mData->ragdollSkeleton;
  v6 = UFG::gpRagDollSkeleton->mhkaSkeleton->m_bones.m_size;
  v7 = skeleton->mhkaSkeleton->m_bones.m_size - v6;
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  v10 = v9;
  *(_DWORD *)(v8 + 4 * v10) = 3;
  *(_QWORD *)(v8 + 8 * v10 + 16) = "hkaSkeletonMapperData";
  *(_QWORD *)(v8 + 8 * v10 + 48) = 0i64;
  v11 = *(_BYTE *)(v8 + 81);
  if ( v9 > v11 )
    v11 = v9;
  *(_BYTE *)(v8 + 81) = v11;
  hkaSkeletonMapperData::hkaSkeletonMapperData((hkaSkeletonMapperData *)((char *)&array + 136));
  if ( (v25 & 0x3FFFFFFF) < v6 )
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v24, v6, 64);
  if ( (v27 & 0x3FFFFFFF) < v7 )
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v26, v7, 2);
  v28 = 0;
  hkaSkeletonMapperData::hkaSkeletonMapperData(&array);
  if ( (HIDWORD(array.m_simpleMappingPartitionRanges.m_data) & 0x3FFFFFFF) < v6 )
    hkArrayUtil::_reserve(
      result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_partitionMap.m_size,
      v6,
      64);
  if ( (HIDWORD(array.m_simpleMappings.m_data) & 0x3FFFFFFF) < v7 )
    hkArrayUtil::_reserve(
      result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_chainMappingPartitionRanges.m_size,
      v7,
      2);
  array.m_extractedMotionMapping.m_translation.m_quad.m128_i32[3] = 0;
  v12 = *(_BYTE *)(v8 + 80);
  if ( v12 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v12 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  UFG::RagdollSkeletonMapper::CreateMapping(
    v4->mSkeletonMapper,
    &array,
    (hkaSkeletonMapperData *)((char *)&array + 136));
  v13 = ++*(_BYTE *)(v8 + 80);
  v14 = v13;
  *(_DWORD *)(v8 + 4 * v14) = 3;
  *(_QWORD *)(v8 + 8 * v14 + 16) = "hkaSkeletonMapper";
  *(_QWORD *)(v8 + 8 * v14 + 48) = 0i64;
  v15 = *(_BYTE *)(v8 + 81);
  if ( v13 > v15 )
    v15 = v13;
  *(_BYTE *)(v8 + 81) = v15;
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkaSkeletonMapper *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 192i64);
  *(_QWORD *)&result[0].m_enum = v17;
  if ( v17 )
    hkaSkeletonMapper::hkaSkeletonMapper(v17, (hkaSkeletonMapperData *)((char *)&array + 136));
  else
    v18 = 0i64;
  v3->highResToRagdollMapper = v18;
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (hkaSkeletonMapper *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 192i64);
  *(_QWORD *)&result[0].m_enum = v20;
  if ( v20 )
    hkaSkeletonMapper::hkaSkeletonMapper(v20, &array);
  else
    v21 = 0i64;
  v3->ragdollToHighResMapper = v21;
  v22 = *(_BYTE *)(v8 + 80);
  if ( v22 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v22 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  hkaSkeletonMapperData::~hkaSkeletonMapperData(&array);
  hkaSkeletonMapperData::~hkaSkeletonMapperData((hkaSkeletonMapperData *)((char *)&array + 136));
}

// File Line: 1187
// RVA: 0x47C610
void __fastcall UFG::RagdollFactory::Update(UFG::RagdollFactory *this, float deltaTime)
{
  int v2; // ebx
  UFG::RagdollFactory *v3; // rsi
  int v4; // er8
  __int64 v5; // rcx
  UFG::RagdollData *v6; // rdx
  __int64 v7; // rdx
  __int64 v8; // rax
  UFG::RagdollData **v9; // rcx
  UFG::RagdollData *v10; // rdi
  hkaSkeletonMapper *v11; // rcx
  hkaSkeletonMapper *v12; // rcx
  __int64 v13; // rax

  v2 = 0;
  v3 = this;
  v4 = 0;
  if ( this->mRagdollData.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v3->mRagdollData.m_data[v5];
      if ( v6->mRefcount )
        v6->m_timeSinceLastUsed = 0.0;
      else
        v6->m_timeSinceLastUsed = deltaTime + v6->m_timeSinceLastUsed;
      ++v4;
      ++v5;
    }
    while ( v4 < v3->mRagdollData.m_size );
  }
  v7 = v3->mRagdollData.m_size;
  v8 = 0i64;
  if ( v7 > 0 )
  {
    v9 = v3->mRagdollData.m_data;
    while ( 1 )
    {
      v10 = *v9;
      if ( (*v9)->m_timeSinceLastUsed > 5.0 )
        break;
      ++v8;
      ++v2;
      ++v9;
      if ( v8 >= v7 )
        return;
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v10->havokInstance->vfptr);
    v11 = v10->highResToRagdollMapper;
    if ( v11 )
      v11->vfptr->__vecDelDtor((hkBaseObject *)&v11->vfptr, 1u);
    v12 = v10->ragdollToHighResMapper;
    if ( v12 )
      v12->vfptr->__vecDelDtor((hkBaseObject *)&v12->vfptr, 1u);
    v10->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::RagdollData> *)&v10->vfptr, 1u);
    v13 = --v3->mRagdollData.m_size;
    if ( (_DWORD)v13 != v2 )
      v3->mRagdollData.m_data[v2] = v3->mRagdollData.m_data[v13];
  }
}

// File Line: 1222
// RVA: 0x458650
UFG::Ragdoll *__fastcall UFG::RagdollFactory::AquireRagdoll(UFG::RagdollFactory *this, Skeleton *skeleton, component_Ragdoll *ragdoll_data, unsigned int collisionSystem, UFG::RagdollQuality quality)
{
  unsigned int v5; // er15
  UFG::RagdollFactory *v6; // rsi
  __int64 v7; // rbp
  int v8; // eax
  int v9; // er10
  UFG::RagdollData **v10; // rbx
  UFG::RagdollData **v11; // rcx
  UFG::RagdollData *v12; // rbx
  hkaRagdollInstance *v13; // r14
  signed __int64 v14; // rdi
  char v15; // dl
  __int64 v16; // rax
  char v17; // cl
  char v18; // cl
  UFG::allocator::free_link *v19; // rax
  __int64 v20; // rax

  v5 = collisionSystem;
  v6 = this;
  v7 = 0i64;
  if ( this->mDisableCaching )
  {
    v12 = UFG::RagdollFactory::CreateRagdollFromSkeleton(this, skeleton, ragdoll_data, quality);
  }
  else
  {
    v8 = 0;
    v9 = this->mRagdollData.m_size;
    if ( v9 <= 0 )
      goto LABEL_8;
    v10 = this->mRagdollData.m_data;
    v11 = this->mRagdollData.m_data;
    while ( *(_QWORD *)&(*v11)->mQuality != __PAIR__(skeleton->mNameUID, quality) )
    {
      ++v8;
      ++v11;
      if ( v8 >= v9 )
        goto LABEL_8;
    }
    v12 = v10[v8];
    if ( !v12 )
    {
LABEL_8:
      v12 = UFG::RagdollFactory::CreateRagdollFromSkeleton(v6, skeleton, ragdoll_data, quality);
      if ( v6->mRagdollData.m_size == (v6->mRagdollData.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->mRagdollData, 8);
      v6->mRagdollData.m_data[v6->mRagdollData.m_size++] = v12;
    }
  }
  if ( v12->mRefcount )
  {
    v14 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v15 = ++*(_BYTE *)(v14 + 80);
    v16 = v15;
    *(_DWORD *)(v14 + 4 * v16) = 3;
    *(_QWORD *)(v14 + 8 * v16 + 16) = "hkRagdollInstance::clone";
    *(_QWORD *)(v14 + 8 * v16 + 48) = 0i64;
    v17 = *(_BYTE *)(v14 + 81);
    if ( v15 > v17 )
      v17 = v15;
    *(_BYTE *)(v14 + 81) = v17;
    v13 = (hkaRagdollInstance *)((__int64 (__fastcall *)(hkaRagdollInstance *, signed __int64))v12->havokInstance->vfptr[1].__first_virtual_table_function__)(
                                  v12->havokInstance,
                                  1i64);
    v18 = *(_BYTE *)(v14 + 80);
    if ( v18 > 0 )
    {
      *(_BYTE *)(v14 + 80) = v18 - 1;
    }
    else
    {
      *(_BYTE *)(v14 + 80) = 0;
      *(_DWORD *)v14 = 3;
      *(_QWORD *)(v14 + 16) = 0i64;
      *(_QWORD *)(v14 + 48) = 0i64;
    }
  }
  else
  {
    v13 = v12->havokInstance;
  }
  ++v12->mRefcount;
  v19 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x170ui64, "ragdoll", 0i64, 1u);
  if ( v19 )
  {
    UFG::Ragdoll::Ragdoll((UFG::Ragdoll *)v19, v12, v13, v5);
    v7 = v20;
  }
  *(_BYTE *)(v7 + 352) = v6->mDisableCaching == 0;
  return (UFG::Ragdoll *)v7;
}

// File Line: 1271
// RVA: 0x4729F0
void __fastcall UFG::RagdollFactory::ReleaseRagdoll(UFG::RagdollFactory *this, UFG::Ragdoll *ragdoll)
{
  UFG::Ragdoll *v2; // rdi
  __int64 v3; // r11
  int v4; // esi
  int v5; // er10
  __int64 v6; // r8
  unsigned int v7; // ebx
  UFG::RagdollData **v8; // rdx
  UFG::RagdollData *v9; // rbx
  hkReferencedObject *v10; // rbp
  hkaRagdollInstance *v11; // rdi
  __int64 v12; // r14
  hkpEntity *v13; // rbx
  hkpEntity *v14; // rbx
  __int128 v15; // [rsp+20h] [rbp-18h]

  v2 = ragdoll;
  if ( ragdoll->mWasCreatedFromCache )
  {
    v3 = this->mRagdollData.m_size;
    v4 = 0;
    v5 = 0;
    v6 = 0i64;
    if ( v3 > 0 )
    {
      v7 = ragdoll->mUID;
      v8 = this->mRagdollData.m_data;
      while ( (*v8)->rigGuid != v7 || (*v8)->mQuality != v2->mRagdollData.m_pPointer->mQuality )
      {
        ++v6;
        ++v5;
        ++v8;
        if ( v6 >= v3 )
          return;
      }
      v9 = this->mRagdollData.m_data[v5];
      --v9->mRefcount;
      v10 = (hkReferencedObject *)&v2->mRagdollInstance->vfptr;
      ((void (__fastcall *)(UFG::Ragdoll *, signed __int64, __int64))v2->vfptr->__vecDelDtor)(v2, 1i64, v6);
      v11 = v9->havokInstance;
      if ( v10 == (hkReferencedObject *)v11 )
      {
        v15 = 0i64;
        if ( v11->m_rigidBodies.m_size > 0 )
        {
          v12 = 0i64;
          do
          {
            v13 = (hkpEntity *)&v11->m_rigidBodies.m_data[v12]->vfptr;
            hkpEntity::activate(v13);
            v13->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v13->m_motion.vfptr, (unsigned int)&v15);
            v14 = (hkpEntity *)&v11->m_rigidBodies.m_data[v12]->vfptr;
            hkpEntity::activate(v14);
            ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v14->m_motion.vfptr[9].__first_virtual_table_function__)(
              &v14->m_motion,
              &v15);
            ++v4;
            ++v12;
          }
          while ( v4 < v11->m_rigidBodies.m_size );
        }
      }
      else
      {
        hkReferencedObject::removeReference(v10);
      }
    }
  }
  else
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&ragdoll->mRagdollInstance->vfptr);
    v2->vfptr->__vecDelDtor((UFG::BasePhysicsObject *)&v2->vfptr, 1u);
  }
}

