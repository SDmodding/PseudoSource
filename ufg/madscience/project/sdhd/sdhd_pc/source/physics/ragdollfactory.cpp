// File Line: 66
// RVA: 0x1513EC0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::RagdollDefinition_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::RagdollDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::RagdollDefinition,UFG::qReflectObject>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::RagdollDefinition>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 131
// RVA: 0x44D240
void __fastcall UFG::RagdollSkeletonMapper::RagdollSkeletonMapper(
        UFG::RagdollSkeletonMapper *this,
        int numSimpleMappings,
        int numChainMappings)
{
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  this->m_userMappingsAtoB.m_data = 0i64;
  this->m_userMappingsAtoB.m_size = 0;
  this->m_userMappingsAtoB.m_capacityAndFlags = 0x80000000;
  this->m_userMappingsBtoA.m_data = 0i64;
  this->m_userMappingsBtoA.m_size = 0;
  this->m_userMappingsBtoA.m_capacityAndFlags = 0x80000000;
  this->m_userChains.m_data = 0i64;
  this->m_userChains.m_size = 0;
  this->m_userChains.m_capacityAndFlags = 0x80000000;
  if ( (this->m_userMappingsAtoB.m_capacityAndFlags & 0x3FFFFFFF) < numSimpleMappings )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_userMappingsAtoB, numSimpleMappings, 8);
  if ( (this->m_userMappingsBtoA.m_capacityAndFlags & 0x3FFFFFFF) < numSimpleMappings )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_userMappingsBtoA, numSimpleMappings, 8);
  if ( numChainMappings )
  {
    if ( (this->m_userChains.m_capacityAndFlags & 0x3FFFFFFF) < numChainMappings )
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_userChains, numChainMappings, 8);
  }
}

// File Line: 144
// RVA: 0x450E00
void __fastcall UFG::RagdollSkeletonMapper::~RagdollSkeletonMapper(UFG::RagdollSkeletonMapper *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d

  this->m_userChains.m_size = 0;
  m_capacityAndFlags = this->m_userChains.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_userChains.m_data,
      8 * m_capacityAndFlags);
  this->m_userChains.m_data = 0i64;
  this->m_userChains.m_capacityAndFlags = 0x80000000;
  this->m_userMappingsBtoA.m_size = 0;
  v3 = this->m_userMappingsBtoA.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_userMappingsBtoA.m_data,
      8 * v3);
  this->m_userMappingsBtoA.m_data = 0i64;
  this->m_userMappingsBtoA.m_capacityAndFlags = 0x80000000;
  this->m_userMappingsAtoB.m_size = 0;
  v4 = this->m_userMappingsAtoB.m_capacityAndFlags;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_userMappingsAtoB.m_data,
      8 * v4);
  this->m_userMappingsAtoB.m_capacityAndFlags = 0x80000000;
  this->m_userMappingsAtoB.m_data = 0i64;
}

// File Line: 150
// RVA: 0x455870
void __fastcall UFG::RagdollSkeletonMapper::AddSimpleMapping(
        UFG::RagdollSkeletonMapper *this,
        UFG::qSymbolUC *boneA,
        UFG::qSymbolUC *boneB)
{
  unsigned int mUID; // edi
  unsigned int v5; // esi
  UFG::RagdollSkeletonMapper::UserMapping *v6; // rdx
  UFG::RagdollSkeletonMapper::UserMapping *v7; // rdx

  mUID = boneA->mUID;
  v5 = boneB->mUID;
  if ( this->m_userMappingsAtoB.m_size == (this->m_userMappingsAtoB.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_userMappingsAtoB, 8);
  v6 = &this->m_userMappingsAtoB.m_data[this->m_userMappingsAtoB.m_size];
  if ( v6 )
  {
    v6->m_boneIn.mUID = mUID;
    v6->m_boneOut.mUID = v5;
  }
  ++this->m_userMappingsAtoB.m_size;
  if ( this->m_userMappingsBtoA.m_size == (this->m_userMappingsBtoA.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_userMappingsBtoA, 8);
  v7 = &this->m_userMappingsBtoA.m_data[this->m_userMappingsBtoA.m_size];
  if ( v7 )
  {
    v7->m_boneIn.mUID = v5;
    v7->m_boneOut.mUID = mUID;
  }
  ++this->m_userMappingsBtoA.m_size;
}

// File Line: 174
// RVA: 0x45CA90
void __fastcall UFG::RagdollSkeletonMapper::CreateMapping(
        UFG::RagdollSkeletonMapper *this,
        hkaSkeletonMapperData *aToB,
        hkaSkeletonMapperData *bToA)
{
  int v6; // r13d
  int m_size; // r12d
  hkQsTransformf *v8; // r15
  hkLifoAllocator *Value; // rax
  int v10; // edx
  hkQsTransformf *m_cur; // rdi
  char *v12; // rcx
  hkLifoAllocator *v13; // rax
  int v14; // edx
  char *v15; // rcx
  hkLifoAllocator *v16; // rax
  int v17; // edx
  __int16 *v18; // rcx
  char *v19; // rdi
  int v20; // r9d
  __int16 *v21; // rdi
  __int64 v22; // rcx
  hkLifoAllocator *v23; // rdi
  int v24; // edx
  char *v25; // rax
  char *v26; // rcx
  int v27; // r9d
  _WORD *v28; // rdi
  __int64 v29; // rcx
  hkaSkeleton *m_skeletonA; // rdi
  hkaSkeleton *m_skeletonB; // rdi
  hkaSkeleton *m_pntr; // rcx
  hkaSkeleton *v33; // rdi
  hkaSkeleton *v34; // rdi
  hkaSkeleton *v35; // rcx
  __int64 v36; // rbx
  _DWORD *v37; // r13
  __int64 v38; // r12
  UFG::RagdollSkeletonMapper::UserMapping *m_data; // rdi
  __int16 BoneID; // r15
  __int16 v41; // si
  __int64 v42; // rax
  __int64 v43; // rbx
  _DWORD *v44; // r12
  __int64 v45; // r13
  UFG::RagdollSkeletonMapper::UserMapping *v46; // rdi
  __int16 v47; // r15
  __int16 v48; // si
  __int64 v49; // rax
  __int64 v50; // rcx
  UFG::RagdollSkeletonMapper::UserChain *v51; // rbx
  int v52; // eax
  __int16 v53; // r12
  __int16 v54; // r13
  int v55; // eax
  __int16 v56; // di
  int v57; // eax
  unsigned __int16 v58; // r15
  char *v59; // rdi
  char *v60; // rax
  char *v61; // rdi
  char *v62; // rax
  hkLifoAllocator *v63; // rax
  __int16 *v64; // rcx
  __int16 *v65; // rdx
  hkLifoAllocator *v66; // rax
  __int16 *v67; // rcx
  __int16 *v68; // rdx
  __int64 v69; // r15
  __int64 v70; // r12
  char *v71; // rdi
  char *v72; // rax
  int v73; // r12d
  __int64 v74; // r15
  __int64 v75; // r12
  char *v76; // rdi
  char *v77; // rax
  __int16 v78; // si
  hkQuaternionf *v79; // r15
  __int16 v80; // di
  __int16 v81; // bx
  __m128 v82; // xmm8
  __m128 m_quad; // xmm0
  __m128 v84; // xmm1
  __m128 v85; // xmm10
  __m128 v86; // xmm7
  __m128 v87; // xmm2
  __m128 v88; // xmm4
  __m128 v89; // xmm1
  __m128 v90; // xmm6
  __m128 v91; // xmm12
  __m128 v92; // xmm2
  __m128 v93; // xmm3
  __m128 v94; // xmm9
  __m128 v95; // xmm9
  __m128 v96; // xmm8
  __m128 v97; // xmm9
  __m128 v98; // xmm10
  __m128 v99; // xmm8
  __m128 v100; // xmm0
  __m128 v101; // xmm1
  __m128 v102; // xmm11
  __m128 v103; // xmm7
  __m128 v104; // xmm2
  __m128 v105; // xmm4
  __m128 v106; // xmm1
  __m128 v107; // xmm6
  __m128 v108; // xmm15
  __m128 v109; // xmm2
  __m128 v110; // xmm3
  __m128 v111; // xmm6
  __m128 v112; // xmm6
  __m128 v113; // xmm8
  __m128 v114; // xmm6
  __m128 v115; // xmm11
  __int64 v116; // r15
  __int64 v117; // rax
  hkVector4f *v118; // r15
  __m128 v119; // xmm8
  __m128 v120; // xmm0
  __m128 v121; // xmm1
  __m128 v122; // xmm7
  __m128 v123; // xmm6
  __m128 v124; // xmm3
  __m128 v125; // xmm4
  __m128 v126; // xmm1
  __m128 v127; // xmm5
  __m128 v128; // xmm10
  __m128 v129; // xmm2
  __m128 v130; // xmm3
  __m128 v131; // xmm9
  __m128 v132; // xmm9
  __m128 v133; // xmm8
  __m128 v134; // xmm9
  __m128 v135; // xmm12
  hkVector4f *v136; // r15
  __m128 v137; // xmm8
  __m128 v138; // xmm0
  __m128 v139; // xmm1
  __m128 v140; // xmm13
  __m128 v141; // xmm7
  __m128 v142; // xmm2
  __m128 v143; // xmm4
  __m128 v144; // xmm1
  __m128 v145; // xmm6
  __m128 v146; // xmm11
  __m128 v147; // xmm2
  __m128 v148; // xmm3
  __m128 v149; // xmm6
  __m128 v150; // xmm6
  __m128 v151; // xmm8
  __m128 v152; // xmm6
  __m128 v153; // xmm7
  __int64 v154; // r15
  __int64 v155; // rax
  __int64 v156; // rdx
  __int64 v157; // rdi
  __int64 v158; // rdx
  __int64 v159; // rdi
  char *v160; // rbx
  int v161; // ecx
  int v162; // edi
  hkLifoAllocator *v163; // rax
  signed int v164; // edi
  int v165; // r8d
  __int16 *v166; // rbx
  int v167; // ecx
  int v168; // edi
  hkLifoAllocator *v169; // rax
  signed int v170; // edi
  int v171; // r8d
  char *v172; // rdi
  char *v173; // rax
  char *v174; // rbx
  int v175; // ecx
  int v176; // edi
  hkLifoAllocator *v177; // rax
  signed int v178; // edi
  int v179; // r8d
  int v180; // ecx
  int v181; // edi
  signed int v182; // edi
  char *v183; // rdi
  char *v184; // rax
  char *v185; // rbx
  int v186; // ecx
  int v187; // edi
  hkLifoAllocator *v188; // rax
  signed int v189; // edi
  int v190; // r8d
  int v191; // ecx
  int v192; // edi
  signed int v193; // edi
  int v194; // ebx
  __int64 v195; // rsi
  _DWORD *v196; // r13
  int v197; // ebx
  __int64 v198; // rsi
  _DWORD *v199; // r12
  char *v200; // rbx
  int v201; // ecx
  int v202; // edi
  hkLifoAllocator *v203; // rax
  signed int v204; // edi
  int v205; // r8d
  __int16 *v206; // rbx
  int v207; // ecx
  int v208; // edi
  hkLifoAllocator *v209; // rax
  signed int v210; // edi
  int v211; // r8d
  hkLifoAllocator *v212; // rdi
  signed int v213; // ecx
  int v214; // r8d
  void *v215; // rbx
  hkLifoAllocator *v216; // rdi
  signed int v217; // ecx
  int v218; // r8d
  void *v219; // rbx
  hkArray<short,hkContainerHeapAllocator> bonesOut; // [rsp+30h] [rbp-90h] BYREF
  __int16 *array; // [rsp+40h] [rbp-80h] BYREF
  int v222; // [rsp+48h] [rbp-78h]
  int v223; // [rsp+4Ch] [rbp-74h]
  hkArray<short,hkContainerHeapAllocator> v224; // [rsp+50h] [rbp-70h] BYREF
  void *p; // [rsp+60h] [rbp-60h] BYREF
  int v226; // [rsp+68h] [rbp-58h]
  int v227; // [rsp+6Ch] [rbp-54h]
  void *v228; // [rsp+70h] [rbp-50h]
  hkVector4f *direction; // [rsp+78h] [rbp-48h]
  void *v230; // [rsp+80h] [rbp-40h]
  hkVector4f *v231; // [rsp+88h] [rbp-38h]
  void *v232; // [rsp+90h] [rbp-30h]
  hkVector4f *v233; // [rsp+98h] [rbp-28h]
  int v234; // [rsp+A0h] [rbp-20h]
  int v235; // [rsp+A4h] [rbp-1Ch]
  int v236; // [rsp+A8h] [rbp-18h]
  hkVector4f *v237; // [rsp+B0h] [rbp-10h]
  hkQsTransformf *v238; // [rsp+B8h] [rbp-8h]
  int v239; // [rsp+C0h] [rbp+0h]
  unsigned int v240; // [rsp+C4h] [rbp+4h]
  hkQsTransformf *v241; // [rsp+C8h] [rbp+8h]
  int v242; // [rsp+D0h] [rbp+10h]
  hkQsTransformf *v243; // [rsp+D8h] [rbp+18h]
  int v244; // [rsp+E0h] [rbp+20h]
  unsigned int v245; // [rsp+E4h] [rbp+24h]
  hkQsTransformf *v246; // [rsp+E8h] [rbp+28h]
  int v247; // [rsp+F0h] [rbp+30h]
  __int64 v248; // [rsp+F8h] [rbp+38h]
  __m128 *p_m_quad; // [rsp+100h] [rbp+40h]
  __int64 v250; // [rsp+108h] [rbp+48h]
  hkVector4f v251; // [rsp+110h] [rbp+50h] BYREF
  __int64 v252; // [rsp+140h] [rbp+80h]
  hkResult result; // [rsp+240h] [rbp+180h] BYREF
  __int64 v254; // [rsp+248h] [rbp+188h]
  __int64 v255; // [rsp+250h] [rbp+190h]
  hkBool v256; // [rsp+258h] [rbp+198h] BYREF

  v252 = -2i64;
  LODWORD(v228) = this->m_skeletonA->m_bones.m_size;
  v6 = (int)v228;
  m_size = this->m_skeletonB->m_bones.m_size;
  HIDWORD(v228) = m_size;
  v8 = 0i64;
  v238 = 0i64;
  v239 = 0;
  v240 = 0x80000000;
  v242 = (int)v228;
  if ( (_DWORD)v228 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (((48 * (_DWORD)v228 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    m_cur = (hkQsTransformf *)Value->m_cur;
    v230 = m_cur;
    v12 = (char *)m_cur + v10;
    if ( v10 > Value->m_slabSize || v12 > Value->m_end )
    {
      m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
      v230 = m_cur;
    }
    else
    {
      Value->m_cur = v12;
    }
  }
  else
  {
    m_cur = 0i64;
    v230 = 0i64;
  }
  v238 = m_cur;
  v235 = v6 | 0x80000000;
  v240 = v6 | 0x80000000;
  v241 = m_cur;
  v243 = 0i64;
  v244 = 0;
  v245 = 0x80000000;
  v247 = m_size;
  if ( m_size )
  {
    v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (((48 * m_size + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v8 = (hkQsTransformf *)v13->m_cur;
    v232 = v8;
    v15 = (char *)v8 + v14;
    if ( v14 > v13->m_slabSize || v15 > v13->m_end )
    {
      v8 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v13, v14);
      v232 = v8;
    }
    else
    {
      v13->m_cur = v15;
    }
  }
  else
  {
    v232 = 0i64;
  }
  v243 = v8;
  v236 = m_size | 0x80000000;
  v245 = m_size | 0x80000000;
  v246 = v8;
  v239 = v6;
  v244 = m_size;
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    v6,
    this->m_skeletonA->m_parentIndices.m_data,
    this->m_skeletonA->m_referencePose.m_data,
    m_cur);
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    m_size,
    this->m_skeletonB->m_parentIndices.m_data,
    this->m_skeletonB->m_referencePose.m_data,
    v8);
  array = 0i64;
  v222 = 0;
  v223 = 0x80000000;
  v224.m_size = v6;
  if ( v6 )
  {
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (((2 * v6 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v18 = (__int16 *)v16->m_cur;
    v19 = (char *)v18 + v17;
    if ( v17 > v16->m_slabSize || v19 > v16->m_end )
      v18 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v16, v17);
    else
      v16->m_cur = v19;
  }
  else
  {
    v18 = 0i64;
  }
  array = v18;
  v223 = v235;
  v224.m_data = v18;
  if ( (v235 & 0x3FFFFFFF) < v6 )
  {
    v20 = v6;
    if ( v6 < 2 * (v235 & 0x3FFFFFFF) )
      v20 = 2 * (v235 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v20, 2);
  }
  v21 = &array[v222];
  v22 = v6 - v222;
  if ( v6 - v222 > 0 )
  {
    while ( v22 )
    {
      *v21++ = -1;
      --v22;
    }
  }
  v222 = v6;
  p = 0i64;
  v226 = 0;
  v227 = 0x80000000;
  LODWORD(direction) = m_size;
  if ( m_size )
  {
    v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (((2 * m_size + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v25 = (char *)v23->m_cur;
    v26 = &v25[v24];
    if ( v24 > v23->m_slabSize || v26 > v23->m_end )
      v25 = (char *)hkLifoAllocator::allocateFromNewSlab(v23, v24);
    else
      v23->m_cur = v26;
  }
  else
  {
    v25 = 0i64;
  }
  p = v25;
  v227 = v236;
  v228 = v25;
  if ( (v236 & 0x3FFFFFFF) < m_size )
  {
    v27 = m_size;
    if ( m_size < 2 * (v236 & 0x3FFFFFFF) )
      v27 = 2 * (v236 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &p, v27, 2);
  }
  v28 = (char *)p + 2 * v226;
  v29 = m_size - v226;
  if ( m_size - v226 > 0 )
  {
    while ( v29 )
    {
      *v28++ = -1;
      --v29;
    }
  }
  v226 = m_size;
  m_skeletonA = this->m_skeletonA;
  if ( m_skeletonA )
    hkReferencedObject::addReference(this->m_skeletonA);
  if ( aToB->m_skeletonA.m_pntr )
    hkReferencedObject::removeReference(aToB->m_skeletonA.m_pntr);
  aToB->m_skeletonA.m_pntr = m_skeletonA;
  m_skeletonB = this->m_skeletonB;
  if ( m_skeletonB )
    hkReferencedObject::addReference(this->m_skeletonB);
  m_pntr = aToB->m_skeletonB.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  aToB->m_skeletonB.m_pntr = m_skeletonB;
  v33 = this->m_skeletonB;
  if ( v33 )
    hkReferencedObject::addReference(this->m_skeletonB);
  if ( bToA->m_skeletonA.m_pntr )
    hkReferencedObject::removeReference(bToA->m_skeletonA.m_pntr);
  bToA->m_skeletonA.m_pntr = v33;
  v34 = this->m_skeletonA;
  if ( v34 )
    hkReferencedObject::addReference(this->m_skeletonA);
  v35 = bToA->m_skeletonB.m_pntr;
  if ( v35 )
    hkReferencedObject::removeReference(v35);
  bToA->m_skeletonB.m_pntr = v34;
  v36 = 0i64;
  if ( this->m_userMappingsAtoB.m_size > 0i64 )
  {
    v37 = (_DWORD *)v254;
    v38 = this->m_userMappingsAtoB.m_size;
    do
    {
      m_data = this->m_userMappingsAtoB.m_data;
      BoneID = Skeleton::GetBoneID(this->ufgSkeletonA, m_data[v36].m_boneIn.mUID);
      v41 = Skeleton::GetBoneID(this->ufgSkeletonB, m_data[v36].m_boneOut.mUID);
      if ( BoneID != -1 && v41 != -1 )
      {
        if ( v37[18] == (v37[19] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v37 + 16, 64);
        v42 = *((_QWORD *)v37 + 8) + ((__int64)(int)v37[18] << 6);
        *(_WORD *)v42 = BoneID;
        *(_WORD *)(v42 + 2) = v41;
        *(_OWORD *)(v42 + 16) = 0i64;
        *(hkQuaternionf *)(v42 + 32) = (hkQuaternionf)qi.m_vec.m_quad;
        *(hkVector4f *)(v42 + 48) = (hkVector4f)query.m_quad;
        ++v37[18];
        *((_WORD *)p + v41) = BoneID;
      }
      ++v36;
    }
    while ( v36 < v38 );
    m_size = HIDWORD(v228);
    v6 = (int)v228;
  }
  v43 = 0i64;
  if ( this->m_userMappingsBtoA.m_size > 0i64 )
  {
    v44 = (_DWORD *)v255;
    v45 = this->m_userMappingsBtoA.m_size;
    do
    {
      v46 = this->m_userMappingsBtoA.m_data;
      v47 = Skeleton::GetBoneID(this->ufgSkeletonB, v46[v43].m_boneIn.mUID);
      v48 = Skeleton::GetBoneID(this->ufgSkeletonA, v46[v43].m_boneOut.mUID);
      if ( v47 != -1 && v48 != -1 )
      {
        if ( v44[18] == (v44[19] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v44 + 16, 64);
        v49 = *((_QWORD *)v44 + 8) + ((__int64)(int)v44[18] << 6);
        *(_WORD *)v49 = v47;
        *(_WORD *)(v49 + 2) = v48;
        *(_OWORD *)(v49 + 16) = 0i64;
        *(hkQuaternionf *)(v49 + 32) = (hkQuaternionf)qi.m_vec.m_quad;
        *(hkVector4f *)(v49 + 48) = (hkVector4f)query.m_quad;
        ++v44[18];
        array[v48] = v47;
      }
      ++v43;
    }
    while ( v43 < v45 );
    m_size = HIDWORD(v228);
    v6 = (int)v228;
  }
  v50 = 0i64;
  v248 = 0i64;
  v250 = this->m_userChains.m_size;
  if ( v250 > 0 )
  {
    while ( 1 )
    {
      v51 = &this->m_userChains.m_data[v50];
      v52 = Skeleton::GetBoneID(this->ufgSkeletonA, v51->m_start.mUID);
      v53 = v52;
      LODWORD(v231) = v52;
      v54 = Skeleton::GetBoneID(this->ufgSkeletonA, v51->m_end.mUID);
      v55 = Skeleton::GetBoneID(this->ufgSkeletonB, v51->m_start.mUID);
      v56 = v55;
      LODWORD(v233) = v55;
      v57 = Skeleton::GetBoneID(this->ufgSkeletonB, v51->m_end.mUID);
      v58 = v57;
      LODWORD(v237) = v57;
      if ( v53 >= 0 || v56 >= 0 )
      {
        if ( v54 >= 0 || (v57 & 0x8000u) == 0 )
        {
          if ( v53 < 0 )
          {
            v53 = *((_WORD *)p + v56);
            LODWORD(v231) = (unsigned __int16)v53;
          }
          if ( v54 < 0 )
            v54 = *((_WORD *)p + (__int16)v57);
          if ( v56 < 0 )
          {
            v56 = array[v53];
            LODWORD(v233) = (unsigned __int16)v56;
          }
          if ( (v57 & 0x8000u) != 0 )
          {
            v58 = array[v54];
            LODWORD(v237) = v58;
          }
          bonesOut.m_data = 0i64;
          bonesOut.m_size = 0;
          bonesOut.m_capacityAndFlags = 0x80000000;
          v222 = 16;
          v63 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v64 = (__int16 *)v63->m_cur;
          v65 = v64 + 64;
          if ( v63->m_slabSize < 128 || v65 > v63->m_end )
            v64 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v63, 128);
          else
            v63->m_cur = v65;
          bonesOut.m_data = v64;
          bonesOut.m_capacityAndFlags = -2147483632;
          array = v64;
          v224.m_data = 0i64;
          v224.m_size = 0;
          v224.m_capacityAndFlags = 0x80000000;
          v226 = 16;
          v66 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v67 = (__int16 *)v66->m_cur;
          v68 = v67 + 64;
          if ( v66->m_slabSize < 128 || v68 > v66->m_end )
            v67 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v66, 128);
          else
            v66->m_cur = v68;
          v224.m_data = v67;
          v224.m_capacityAndFlags = -2147483632;
          p = v67;
          hkaSkeletonUtils::getBoneChain((hkBool *)&result, this->m_skeletonA, v53, v54, &bonesOut);
          hkaSkeletonUtils::getBoneChain(&v256, this->m_skeletonB, v56, v58, &v224);
          if ( LOBYTE(result.m_enum) && v256.m_bool )
          {
            LODWORD(direction) = v224.m_size;
            if ( bonesOut.m_size < 2 || v224.m_size < 2 )
            {
              v172 = UFG::qSymbol::as_cstr_dbg(&v51->m_end);
              v173 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v51);
              UFG::qPrintf("Couldnt make a chain (%s - %s).\n", v173, v172);
              v174 = (char *)p;
              v175 = v224.m_size;
              if ( p == v224.m_data )
                v175 = 0;
              v224.m_size = v175;
              v176 = v226;
              v177 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v178 = (2 * v176 + 127) & 0xFFFFFF80;
              v179 = (v178 + 15) & 0xFFFFFFF0;
              if ( v178 > v177->m_slabSize || &v174[v179] != v177->m_cur || v177->m_firstNonLifoEnd == v174 )
                hkLifoAllocator::slowBlockFree(v177, v174, v179);
              else
                v177->m_cur = v174;
              v224.m_size = 0;
              if ( v224.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  v224.m_data,
                  2 * (v224.m_capacityAndFlags & 0x3FFFFFFF));
              v224.m_data = 0i64;
              v224.m_capacityAndFlags = 0x80000000;
              v166 = array;
              v180 = bonesOut.m_size;
              if ( array == bonesOut.m_data )
                v180 = 0;
              bonesOut.m_size = v180;
              v181 = v222;
              v169 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v182 = (2 * v181 + 127) & 0xFFFFFF80;
              v171 = (v182 + 15) & 0xFFFFFFF0;
              if ( v182 <= v169->m_slabSize && (char *)v166 + v171 == v169->m_cur && v169->m_firstNonLifoEnd != v166 )
              {
                v169->m_cur = v166;
                goto LABEL_169;
              }
            }
            else
            {
              v234 = bonesOut.m_size - 1;
              if ( bonesOut.m_size - 1 > 1 )
              {
                v234 = bonesOut.m_size - 1;
                v69 = 1i64;
                v70 = (unsigned int)(bonesOut.m_size - 2);
                do
                {
                  if ( array[bonesOut.m_data[v69]] != -1 )
                  {
                    v71 = UFG::qSymbol::as_cstr_dbg(&v51->m_end);
                    v72 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v51);
                    UFG::qPrintf("Couldnt make a chain (%s - %s).\n", v72, v71);
                  }
                  ++v69;
                  --v70;
                }
                while ( v70 );
              }
              v73 = (_DWORD)direction - 1;
              LODWORD(direction) = v73;
              if ( v73 > 1 )
              {
                v74 = 1i64;
                v75 = (unsigned int)(v73 - 1);
                do
                {
                  if ( *((_WORD *)p + v224.m_data[v74]) != 0xFFFF )
                  {
                    v76 = UFG::qSymbol::as_cstr_dbg(&v51->m_end);
                    v77 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v51);
                    UFG::qPrintf("Couldnt make a chain (%s - %s).\n", v77, v76);
                  }
                  ++v74;
                  --v75;
                }
                while ( v75 );
                v73 = (int)direction;
              }
              v78 = (__int16)v231;
              v79 = (hkQuaternionf *)((char *)v230 + 48 * (__int16)v231);
              p_m_quad = &v79->m_vec.m_quad;
              v80 = (__int16)v233;
              v231 = (hkVector4f *)((char *)v232 + 48 * (__int16)v233);
              v233 = (hkVector4f *)((char *)v230 + 48 * v54);
              v81 = (__int16)v237;
              direction = (hkVector4f *)((char *)v232 + 48 * (__int16)v237);
              v237 = v233 + 1;
              hkVector4f::setRotatedInverseDir(&v251, (hkQuaternionf *)&v233[1], v233);
              v82 = _mm_xor_ps(v237->m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
              m_quad = v233[2].m_quad;
              v84 = _mm_rcp_ps(m_quad);
              v85 = (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(m_quad, v84)), v84),
                                4),
                              4);
              v86 = _mm_shuffle_ps(v82, v82, 255);
              v87 = _mm_mul_ps(v82, direction->m_quad);
              v88 = _mm_shuffle_ps(v82, v82, 201);
              v89 = _mm_sub_ps(
                      _mm_mul_ps(v82, _mm_shuffle_ps(direction->m_quad, direction->m_quad, 201)),
                      _mm_mul_ps(direction->m_quad, v88));
              v90 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(direction->m_quad, _mm_sub_ps(_mm_mul_ps(v86, v86), (__m128)xmmword_141A711B0)),
                        _mm_mul_ps(
                          v82,
                          _mm_add_ps(
                            _mm_shuffle_ps(v87, v87, 170),
                            _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0))))),
                      _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v86));
              v91 = _mm_add_ps(
                      _mm_xor_ps(v251.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0)),
                      _mm_add_ps(v90, v90));
              v92 = direction[1].m_quad;
              v93 = _mm_shuffle_ps(v92, v92, 255);
              v94 = _mm_sub_ps(_mm_mul_ps(v82, _mm_shuffle_ps(v92, v92, 201)), _mm_mul_ps(v92, v88));
              v95 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v94, v94, 201), _mm_mul_ps(v92, v86)), _mm_mul_ps(v82, v93));
              v96 = _mm_mul_ps(v82, v92);
              v97 = _mm_shuffle_ps(
                      v95,
                      _mm_unpackhi_ps(
                        v95,
                        _mm_sub_ps(
                          _mm_mul_ps(v93, v86),
                          _mm_add_ps(
                            _mm_shuffle_ps(v96, v96, 170),
                            _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0))))),
                      196);
              v98 = _mm_mul_ps(v85, direction[2].m_quad);
              hkVector4f::setRotatedInverseDir(&v251, v79 + 1, &v79->m_vec);
              v99 = _mm_xor_ps(
                      v79[1].m_vec.m_quad,
                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
              v100 = v79[2].m_vec.m_quad;
              v101 = _mm_rcp_ps(v100);
              v102 = (__m128)_mm_srli_si128(
                               _mm_slli_si128(
                                 (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v100, v101)), v101),
                                 4),
                               4);
              v103 = _mm_shuffle_ps(v99, v99, 255);
              v104 = _mm_mul_ps(v99, v231->m_quad);
              v105 = _mm_shuffle_ps(v99, v99, 201);
              v106 = _mm_sub_ps(
                       _mm_mul_ps(v99, _mm_shuffle_ps(v231->m_quad, v231->m_quad, 201)),
                       _mm_mul_ps(v231->m_quad, v105));
              v107 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v231->m_quad, _mm_sub_ps(_mm_mul_ps(v103, v103), (__m128)xmmword_141A711B0)),
                         _mm_mul_ps(
                           v99,
                           _mm_add_ps(
                             _mm_shuffle_ps(v104, v104, 170),
                             _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0))))),
                       _mm_mul_ps(_mm_shuffle_ps(v106, v106, 201), v103));
              v108 = _mm_add_ps(
                       _mm_xor_ps(
                         v251.m_quad,
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0)),
                       _mm_add_ps(v107, v107));
              v109 = v231[1].m_quad;
              v110 = _mm_shuffle_ps(v109, v109, 255);
              v111 = _mm_sub_ps(_mm_mul_ps(v99, _mm_shuffle_ps(v109, v109, 201)), _mm_mul_ps(v109, v105));
              v112 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v111, v111, 201), _mm_mul_ps(v109, v103)),
                       _mm_mul_ps(v99, v110));
              v113 = _mm_mul_ps(v99, v109);
              v114 = _mm_shuffle_ps(
                       v112,
                       _mm_unpackhi_ps(
                         v112,
                         _mm_sub_ps(
                           _mm_mul_ps(v110, v103),
                           _mm_add_ps(
                             _mm_shuffle_ps(v113, v113, 170),
                             _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0))))),
                       196);
              v115 = _mm_mul_ps(v102, v231[2].m_quad);
              v116 = v254;
              if ( *(_DWORD *)(v254 + 88) == (*(_DWORD *)(v254 + 92) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v254 + 80), 112);
              v117 = *(_QWORD *)(v116 + 80) + 112i64 * *(int *)(v116 + 88);
              *(_WORD *)v117 = v78;
              *(_WORD *)(v117 + 2) = v54;
              *(_WORD *)(v117 + 4) = v80;
              *(_WORD *)(v117 + 6) = v81;
              *(__m128 *)(v117 + 16) = v108;
              *(__m128 *)(v117 + 32) = v114;
              *(__m128 *)(v117 + 48) = v115;
              *(__m128 *)(v117 + 64) = v91;
              *(__m128 *)(v117 + 80) = v97;
              *(__m128 *)(v117 + 96) = v98;
              ++*(_DWORD *)(v116 + 88);
              v118 = direction;
              hkVector4f::setRotatedInverseDir(&v251, (hkQuaternionf *)&direction[1], direction);
              v119 = _mm_xor_ps(
                       v118[1].m_quad,
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
              v120 = v118[2].m_quad;
              v121 = _mm_rcp_ps(v120);
              v122 = (__m128)_mm_srli_si128(
                               _mm_slli_si128(
                                 (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v120, v121)), v121),
                                 4),
                               4);
              v123 = _mm_shuffle_ps(v119, v119, 255);
              v124 = _mm_mul_ps(v233->m_quad, v119);
              v125 = _mm_shuffle_ps(v119, v119, 201);
              v126 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v233->m_quad, v233->m_quad, 201), v119),
                       _mm_mul_ps(v125, v233->m_quad));
              v127 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v123, v123), (__m128)xmmword_141A711B0), v233->m_quad),
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_shuffle_ps(v124, v124, 170),
                             _mm_add_ps(_mm_shuffle_ps(v124, v124, 85), _mm_shuffle_ps(v124, v124, 0))),
                           v119)),
                       _mm_mul_ps(v123, _mm_shuffle_ps(v126, v126, 201)));
              v128 = _mm_add_ps(
                       _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         v251.m_quad),
                       _mm_add_ps(v127, v127));
              v129 = v233[1].m_quad;
              v130 = _mm_shuffle_ps(v129, v129, 255);
              v131 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v129, v129, 201), v119), _mm_mul_ps(v125, v129));
              v132 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v131, v131, 201), _mm_mul_ps(v123, v129)),
                       _mm_mul_ps(v130, v119));
              v133 = _mm_mul_ps(v119, v129);
              v134 = _mm_shuffle_ps(
                       v132,
                       _mm_unpackhi_ps(
                         v132,
                         _mm_sub_ps(
                           _mm_mul_ps(v130, v123),
                           _mm_add_ps(
                             _mm_shuffle_ps(v133, v133, 170),
                             _mm_add_ps(_mm_shuffle_ps(v133, v133, 85), _mm_shuffle_ps(v133, v133, 0))))),
                       196);
              v135 = _mm_mul_ps(v233[2].m_quad, v122);
              v136 = v231;
              hkVector4f::setRotatedInverseDir(&v251, (hkQuaternionf *)&v231[1], v231);
              v137 = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                       v136[1].m_quad);
              v138 = v136[2].m_quad;
              v139 = _mm_rcp_ps(v138);
              v140 = (__m128)_mm_srli_si128(
                               _mm_slli_si128(
                                 (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v138, v139)), v139),
                                 4),
                               4);
              v141 = _mm_shuffle_ps(v137, v137, 255);
              v142 = _mm_mul_ps(*p_m_quad, v137);
              v143 = _mm_shuffle_ps(v137, v137, 201);
              v144 = _mm_sub_ps(
                       _mm_mul_ps(v137, _mm_shuffle_ps(*p_m_quad, *p_m_quad, 201)),
                       _mm_mul_ps(*p_m_quad, v143));
              v145 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v141, v141), (__m128)xmmword_141A711B0), *p_m_quad),
                         _mm_mul_ps(
                           v137,
                           _mm_add_ps(
                             _mm_shuffle_ps(v142, v142, 170),
                             _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0))))),
                       _mm_mul_ps(v141, _mm_shuffle_ps(v144, v144, 201)));
              v146 = _mm_add_ps(
                       _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         v251.m_quad),
                       _mm_add_ps(v145, v145));
              v147 = p_m_quad[1];
              v148 = _mm_shuffle_ps(v147, v147, 255);
              v149 = _mm_sub_ps(_mm_mul_ps(v137, _mm_shuffle_ps(v147, v147, 201)), _mm_mul_ps(v147, v143));
              v150 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v149, v149, 201), _mm_mul_ps(v147, v141)),
                       _mm_mul_ps(v137, v148));
              v151 = _mm_mul_ps(v137, v147);
              v152 = _mm_shuffle_ps(
                       v150,
                       _mm_unpackhi_ps(
                         v150,
                         _mm_sub_ps(
                           _mm_mul_ps(v148, v141),
                           _mm_add_ps(
                             _mm_shuffle_ps(v151, v151, 170),
                             _mm_add_ps(_mm_shuffle_ps(v151, v151, 85), _mm_shuffle_ps(v151, v151, 0))))),
                       196);
              v153 = _mm_mul_ps(p_m_quad[2], v140);
              v154 = v255;
              if ( *(_DWORD *)(v255 + 88) == (*(_DWORD *)(v255 + 92) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (void *)(v255 + 80), 112);
              v155 = *(_QWORD *)(v154 + 80) + 112i64 * *(int *)(v154 + 88);
              *(_WORD *)v155 = v80;
              *(_WORD *)(v155 + 2) = v81;
              *(_WORD *)(v155 + 4) = v78;
              *(_WORD *)(v155 + 6) = v54;
              *(__m128 *)(v155 + 16) = v146;
              *(__m128 *)(v155 + 32) = v152;
              *(__m128 *)(v155 + 48) = v153;
              *(__m128 *)(v155 + 64) = v128;
              *(__m128 *)(v155 + 80) = v134;
              *(__m128 *)(v155 + 96) = v135;
              ++*(_DWORD *)(v154 + 88);
              if ( v234 > 1 )
              {
                v156 = 1i64;
                v157 = (unsigned int)(v234 - 1);
                do
                {
                  array[bonesOut.m_data[v156++]] = -2;
                  --v157;
                }
                while ( v157 );
              }
              if ( v73 > 1 )
              {
                v158 = 1i64;
                v159 = (unsigned int)(v73 - 1);
                do
                {
                  *((_WORD *)p + v224.m_data[v158++]) = -2;
                  --v159;
                }
                while ( v159 );
              }
              v160 = (char *)p;
              v161 = v224.m_size;
              if ( p == v224.m_data )
                v161 = 0;
              v224.m_size = v161;
              v162 = v226;
              v163 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v164 = (2 * v162 + 127) & 0xFFFFFF80;
              v165 = (v164 + 15) & 0xFFFFFFF0;
              if ( v164 > v163->m_slabSize || &v160[v165] != v163->m_cur || v163->m_firstNonLifoEnd == v160 )
                hkLifoAllocator::slowBlockFree(v163, v160, v165);
              else
                v163->m_cur = v160;
              v224.m_size = 0;
              if ( v224.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  v224.m_data,
                  2 * (v224.m_capacityAndFlags & 0x3FFFFFFF));
              v224.m_data = 0i64;
              v224.m_capacityAndFlags = 0x80000000;
              v166 = array;
              v167 = bonesOut.m_size;
              if ( array == bonesOut.m_data )
                v167 = 0;
              bonesOut.m_size = v167;
              v168 = v222;
              v169 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v170 = (2 * v168 + 127) & 0xFFFFFF80;
              v171 = (v170 + 15) & 0xFFFFFFF0;
              if ( v170 <= v169->m_slabSize && (char *)v166 + v171 == v169->m_cur && v169->m_firstNonLifoEnd != v166 )
              {
                v169->m_cur = v166;
LABEL_169:
                bonesOut.m_size = 0;
                if ( bonesOut.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    bonesOut.m_data,
                    2 * (bonesOut.m_capacityAndFlags & 0x3FFFFFFF));
                bonesOut.m_data = 0i64;
                bonesOut.m_capacityAndFlags = 0x80000000;
                goto LABEL_172;
              }
            }
          }
          else
          {
            v183 = UFG::qSymbol::as_cstr_dbg(&v51->m_end);
            v184 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v51);
            UFG::qPrintf("Couldnt make a chain (%s - %s).\n", v184, v183);
            v185 = (char *)p;
            v186 = v224.m_size;
            if ( p == v224.m_data )
              v186 = 0;
            v224.m_size = v186;
            v187 = v226;
            v188 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v189 = (2 * v187 + 127) & 0xFFFFFF80;
            v190 = (v189 + 15) & 0xFFFFFFF0;
            if ( v189 > v188->m_slabSize || &v185[v190] != v188->m_cur || v188->m_firstNonLifoEnd == v185 )
              hkLifoAllocator::slowBlockFree(v188, v185, v190);
            else
              v188->m_cur = v185;
            v224.m_size = 0;
            if ( v224.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                v224.m_data,
                2 * (v224.m_capacityAndFlags & 0x3FFFFFFF));
            v224.m_data = 0i64;
            v224.m_capacityAndFlags = 0x80000000;
            v166 = array;
            v191 = bonesOut.m_size;
            if ( array == bonesOut.m_data )
              v191 = 0;
            bonesOut.m_size = v191;
            v192 = v222;
            v169 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v193 = (2 * v192 + 127) & 0xFFFFFF80;
            v171 = (v193 + 15) & 0xFFFFFFF0;
            if ( v193 <= v169->m_slabSize && (char *)v166 + v171 == v169->m_cur && v169->m_firstNonLifoEnd != v166 )
            {
              v169->m_cur = v166;
              goto LABEL_169;
            }
          }
          hkLifoAllocator::slowBlockFree(v169, v166, v171);
          goto LABEL_169;
        }
        v61 = UFG::qSymbol::as_cstr_dbg(&v51->m_end);
        v62 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v51);
        UFG::qPrintf("Couldnt make a chain (%s - %s). End bone not found in either skeleton\n", v62, v61);
      }
      else
      {
        v59 = UFG::qSymbol::as_cstr_dbg(&v51->m_end);
        v60 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v51);
        UFG::qPrintf("Couldnt make a chain (%s - %s). Start bone not found in either skeleton\n", v60, v59);
      }
LABEL_172:
      v50 = v248 + 1;
      v248 = v50;
      if ( v50 >= v250 )
      {
        m_size = HIDWORD(v228);
        v6 = (int)v228;
        break;
      }
    }
  }
  v194 = 0;
  if ( m_size > 0 )
  {
    v195 = 0i64;
    v196 = (_DWORD *)v254;
    do
    {
      if ( *(_WORD *)((char *)p + v195) == 0xFFFF )
      {
        if ( v196[26] == (v196[27] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v196 + 24, 2);
        *(_WORD *)(*((_QWORD *)v196 + 12) + 2i64 * (int)v196[26]++) = v194;
      }
      ++v194;
      v195 += 2i64;
    }
    while ( v194 < m_size );
    v6 = (int)v228;
  }
  v197 = 0;
  if ( v6 > 0 )
  {
    v198 = 0i64;
    v199 = (_DWORD *)v255;
    do
    {
      if ( array[v198] == -1 )
      {
        if ( v199[26] == (v199[27] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v199 + 24, 2);
        *(_WORD *)(*((_QWORD *)v199 + 12) + 2i64 * (int)v199[26]++) = v197;
      }
      ++v197;
      ++v198;
    }
    while ( v197 < v6 );
    m_size = HIDWORD(v228);
  }
  *(_BYTE *)(v254 + 160) = 1;
  *(_BYTE *)(v255 + 160) = 1;
  v200 = (char *)v228;
  v201 = v226;
  if ( v228 == p )
    v201 = 0;
  v226 = v201;
  v202 = (int)direction;
  v203 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v204 = (2 * v202 + 127) & 0xFFFFFF80;
  v205 = (v204 + 15) & 0xFFFFFFF0;
  if ( v204 > v203->m_slabSize || &v200[v205] != v203->m_cur || v203->m_firstNonLifoEnd == v200 )
    hkLifoAllocator::slowBlockFree(v203, v200, v205);
  else
    v203->m_cur = v200;
  v226 = 0;
  if ( v227 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, p, 2 * (v227 & 0x3FFFFFFF));
  p = 0i64;
  v227 = 0x80000000;
  v206 = v224.m_data;
  v207 = v222;
  if ( v224.m_data == array )
    v207 = 0;
  v222 = v207;
  v208 = v224.m_size;
  v209 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v210 = (2 * v208 + 127) & 0xFFFFFF80;
  v211 = (v210 + 15) & 0xFFFFFFF0;
  if ( v210 > v209->m_slabSize || (char *)v206 + v211 != v209->m_cur || v209->m_firstNonLifoEnd == v206 )
    hkLifoAllocator::slowBlockFree(v209, v206, v211);
  else
    v209->m_cur = v206;
  v222 = 0;
  if ( v223 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 2 * (v223 & 0x3FFFFFFF));
  array = 0i64;
  v223 = 0x80000000;
  v244 = 0;
  v212 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v213 = (48 * m_size + 127) & 0xFFFFFF80;
  v214 = (v213 + 15) & 0xFFFFFFF0;
  v215 = v232;
  if ( v213 > v212->m_slabSize || (char *)v232 + v214 != v212->m_cur || v212->m_firstNonLifoEnd == v232 )
    hkLifoAllocator::slowBlockFree(v212, v232, v214);
  else
    v212->m_cur = v232;
  v244 = 0;
  if ( v236 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v215, 48 * (v236 & 0x3FFFFFFF));
  v243 = 0i64;
  v245 = 0x80000000;
  v239 = 0;
  v216 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v217 = (48 * v6 + 127) & 0xFFFFFF80;
  v218 = (v217 + 15) & 0xFFFFFFF0;
  v219 = v230;
  if ( v217 > v216->m_slabSize || (char *)v230 + v218 != v216->m_cur || v216->m_firstNonLifoEnd == v230 )
    hkLifoAllocator::slowBlockFree(v216, v230, v218);
  else
    v216->m_cur = v230;
  v239 = 0;
  if ( v235 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v219, 48 * (v235 & 0x3FFFFFFF));
}244 = 0;
  v212 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v213 = (48 * m_size + 127) & 0xFFFFFF80;
  v214 = (v213 + 15) & 0xFFFFFFF0;
  v215 = v232;
  if ( v213 > v212->m_slabSize || (char *)v232 + v214 != v212->m_cur || v212->m_firstNonLifoEnd == v232 )
    hkLifoAllocator::slowBlockFree(v212, v232, v214);
  else
    v212->m_cur = v232;
  v244 = 0;
  if ( v236 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAlloc

// File Line: 489
// RVA: 0x44CFA0
void __fastcall UFG::RagdollFactory::RagdollFactory(UFG::RagdollFactory *this)
{
  UFG::qTreeRB<UFG::RagdollDefinitionSearchNode,UFG::RagdollDefinitionSearchNode,1> *p_mDefinitions; // rbp
  int v3; // r9d
  unsigned __int64 v4; // rbx
  UFG::qReflectWarehouse *v5; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // r15
  UFG::qTree64Base *Head; // rax
  __int64 *p_mCount; // rsi
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rdi
  UFG::allocator::free_link *v11; // rbx
  UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData> *v12; // rcx
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rdi
  UFG::allocator::free_link *v15; // rbx
  __int64 v16; // rbx
  const char *StaticTypeName; // rax
  unsigned __int64 v18; // rax
  unsigned int v19; // ecx
  unsigned int v20; // r10d
  __int64 v21; // r9
  __int64 v22; // rcx
  unsigned int v23; // r8d
  UFG::qResourceHandle *v24; // rcx
  UFG::qTree64Base *Next; // rax
  UFG::qTreeRB<UFG::RagdollDefinitionSearchNode,UFG::RagdollDefinitionSearchNode,1> *result; // [rsp+88h] [rbp+10h] BYREF
  UFG::allocator::free_link *v27; // [rsp+90h] [rbp+18h]

  this->mDisableCaching = 0;
  p_mDefinitions = &this->mDefinitions;
  result = &this->mDefinitions;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mDefinitions.mTree);
  this->mRagdollData.m_data = 0i64;
  this->mRagdollData.m_size = 0;
  this->mRagdollData.m_capacityAndFlags = 0x80000000;
  this->mSkeletonMapper = 0i64;
  if ( (this->mRagdollData.m_capacityAndFlags & 0x3FFFFFFFu) < 8 )
  {
    v3 = 8;
    if ( 2 * (this->mRagdollData.m_capacityAndFlags & 0x3FFFFFFF) > 8 )
      v3 = 2 * (this->mRagdollData.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &this->mRagdollData, v3, 8);
  }
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\RagdollDefinitions.perm.bin", 0i64, 0, 0i64, 0i64, 0i64);
  v4 = UFG::qStringHash64("UFG::RagdollDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v5 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v5, v4)->mItems;
  Head = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( Head )
  {
    p_mCount = &Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      do
      {
        if ( p_mCount[14] )
        {
          v9 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
          v10 = v9;
          result = (UFG::qTreeRB<UFG::RagdollDefinitionSearchNode,UFG::RagdollDefinitionSearchNode,1> *)v9;
          if ( v9 )
          {
            v9->mNext = 0i64;
            v9[1].mNext = 0i64;
            v9[2].mNext = 0i64;
            v11 = v9 + 4;
            v27 = v9 + 4;
            UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v9[4]);
            v11[2].mNext = (UFG::allocator::free_link *)UFG::qStringHash64(
                                                          "UFG::RagdollDefinition",
                                                          0xFFFFFFFFFFFFFFFFui64);
          }
          else
          {
            v10 = 0i64;
          }
          LODWORD(v10[3].mNext) = *((_DWORD *)p_mCount + 30);
          UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v10[4], (unsigned __int64)v10[6].mNext, p_mCount[1]);
          UFG::qBaseTreeRB::Add(&p_mDefinitions->mTree, (UFG::qBaseNodeRB *)v10);
          if ( *((_DWORD *)p_mCount + 31) != -1 )
          {
            v13 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
            v14 = v13;
            result = (UFG::qTreeRB<UFG::RagdollDefinitionSearchNode,UFG::RagdollDefinitionSearchNode,1> *)v13;
            if ( v13 )
            {
              v13->mNext = 0i64;
              v13[1].mNext = 0i64;
              v13[2].mNext = 0i64;
              v15 = v13 + 4;
              v27 = v13 + 4;
              UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v13[4]);
              v15[2].mNext = (UFG::allocator::free_link *)UFG::qStringHash64(
                                                            "UFG::RagdollDefinition",
                                                            0xFFFFFFFFFFFFFFFFui64);
            }
            else
            {
              v14 = 0i64;
            }
            LODWORD(v14[3].mNext) = *((_DWORD *)p_mCount + 31);
            UFG::qReflectHandleBase::Init(
              (UFG::qReflectHandleBase *)&v14[4],
              (unsigned __int64)v14[6].mNext,
              p_mCount[1]);
            UFG::qBaseTreeRB::Add(&p_mDefinitions->mTree, (UFG::qBaseNodeRB *)v14);
          }
          v16 = p_mCount[14];
          StaticTypeName = UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::GetStaticTypeName(v12);
          v18 = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
          v19 = 0;
          v20 = *(_DWORD *)(v16 + 224);
          if ( v20 )
          {
            v21 = *(_QWORD *)(v16 + 216);
            while ( *(_QWORD *)(*(_QWORD *)(v21 + 8i64 * v19) + 56i64) != v18 )
            {
              if ( ++v19 >= v20 )
                goto LABEL_22;
            }
            v22 = *(_QWORD *)(v21 + 8i64 * v19);
          }
          else
          {
LABEL_22:
            v22 = 0i64;
          }
          v23 = *(_DWORD *)(v22 + 104);
          v24 = (UFG::qResourceHandle *)(v22 + 80);
          v24[1].mPrev = 0i64;
          UFG::qResourceHandle::Init(v24, 0x1723EA91u, v23);
        }
        Next = UFG::qTree64Base::GetNext(&p_mItems->mTree, (UFG::qTree64Base::BaseNode *)(p_mCount + 1));
        if ( !Next )
          break;
        p_mCount = &Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 531
// RVA: 0x450C80
void __fastcall UFG::RagdollFactory::~RagdollFactory(UFG::RagdollFactory *this)
{
  int v2; // esi
  __int64 v3; // rdi
  hkaSkeletonMapper *highResToRagdollMapper; // rcx
  hkaSkeletonMapper *ragdollToHighResMapper; // rcx
  UFG::RagdollData *v6; // rcx
  int m_capacityAndFlags; // r8d
  UFG::RagdollSkeletonMapper *mSkeletonMapper; // rdi
  int v9; // r8d
  Render::Skinning *p_mDefinitions; // rdi
  Render::SkinningCacheNode *Head; // rbx

  v2 = 0;
  if ( this->mRagdollData.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->mRagdollData.m_data[v3]->havokInstance);
      highResToRagdollMapper = this->mRagdollData.m_data[v3]->highResToRagdollMapper;
      if ( highResToRagdollMapper )
        highResToRagdollMapper->vfptr->__vecDelDtor(highResToRagdollMapper, 1u);
      ragdollToHighResMapper = this->mRagdollData.m_data[v3]->ragdollToHighResMapper;
      if ( ragdollToHighResMapper )
        ragdollToHighResMapper->vfptr->__vecDelDtor(ragdollToHighResMapper, 1u);
      v6 = this->mRagdollData.m_data[v3];
      if ( v6 )
        v6->vfptr->__vecDelDtor(v6, 1u);
      ++v2;
      ++v3;
    }
    while ( v2 < this->mRagdollData.m_size );
  }
  this->mRagdollData.m_size = 0;
  m_capacityAndFlags = this->mRagdollData.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mRagdollData.m_data,
      8 * m_capacityAndFlags);
  this->mRagdollData.m_data = 0i64;
  this->mRagdollData.m_capacityAndFlags = 0x80000000;
  mSkeletonMapper = this->mSkeletonMapper;
  if ( mSkeletonMapper )
  {
    UFG::RagdollSkeletonMapper::~RagdollSkeletonMapper(this->mSkeletonMapper);
    operator delete[](mSkeletonMapper);
  }
  this->mRagdollData.m_size = 0;
  v9 = this->mRagdollData.m_capacityAndFlags;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mRagdollData.m_data,
      8 * v9);
  this->mRagdollData.m_data = 0i64;
  this->mRagdollData.m_capacityAndFlags = 0x80000000;
  p_mDefinitions = (Render::Skinning *)&this->mDefinitions;
  if ( this->mDefinitions.mTree.mCount )
  {
    do
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mDefinitions->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mDefinitions->mSkinnedVertexBuffers.mTree, &Head->mNode);
      if ( Head )
      {
        UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&Head->mCachedBufferPtr);
        operator delete[](Head);
      }
    }
    while ( p_mDefinitions->mSkinnedVertexBuffers.mTree.mCount );
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mDefinitions);
}

// File Line: 547
// RVA: 0x45E390
UFG::RagdollData *__fastcall UFG::RagdollFactory::CreateRagdollFromSkeleton(
        UFG::RagdollFactory *this,
        Skeleton *skeleton,
        component_Ragdoll *rag_doll_data,
        UFG::RagdollQuality quality)
{
  UFG::qSafePointerNode<UFG::RagdollData> *v7; // rax
  UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData> *v8; // rcx
  UFG::qSafePointerNode<UFG::RagdollData> *v9; // rdi
  UFG::qBaseTreeRB *v10; // rax
  unsigned int v11; // eax
  __int64 v12; // r13
  const char *StaticTypeName; // rax
  unsigned __int64 v14; // r10
  unsigned int v15; // edx
  unsigned int v16; // r9d
  __int64 v17; // r8
  __int64 v18; // rcx
  UFG::qBaseNodeRB *v19; // rcx
  unsigned __int64 v20; // rbx
  Skeleton *v21; // rax
  Skeleton *v22; // rax
  Skeleton *v23; // rcx
  __int64 v24; // r12
  unsigned __int64 v25; // rax
  unsigned int v26; // r15d
  __int64 v27; // rbx
  __int64 v28; // r14
  __int64 v29; // r12
  UFG::allocator::free_link *v30; // rax
  UFG::RagdollSkeletonMapper *v31; // rax
  UFG::RagdollFactory *v32; // r15
  unsigned int i; // ebx
  UFG::qSymbolUC *v34; // rdx
  int vecDelDtor; // ebx
  hkLifoAllocator *Value; // rcx
  int v37; // edx
  hkQsTransformf *m_cur; // rax
  char *v39; // r8
  UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData> *v40; // rcx
  const char *v41; // rax
  unsigned __int64 v42; // r10
  unsigned int v43; // edx
  unsigned int v44; // r9d
  __int64 v45; // r8
  __int64 v46; // rbx
  unsigned int v47; // r8d
  void *v48; // rbx
  int v49; // r14d
  hkLifoAllocator *v50; // rcx
  int v51; // eax
  hkQsTransformf *v52; // rdx
  char *v53; // r8
  int v54; // r9d
  hkResultEnum v55; // r8d
  __int64 v56; // r12
  __int64 v57; // r13
  __int64 v58; // rbx
  int v59; // r14d
  __int64 v60; // r15
  __int64 v61; // rbx
  __int64 v62; // r14
  __int64 v63; // rcx
  __int64 v64; // r8
  __m128 m_quad; // xmm0
  hkVector4f v66; // xmm1
  char v67; // dl
  char v68; // cl
  _QWORD **v69; // rax
  hkpRigidBody *v70; // rax
  hkpWorldObject *v71; // rax
  hkpWorldObject *v72; // rbx
  char v73; // al
  void (__fastcall ***v74)(void *, __int64); // rbx
  hkLifoAllocator *v75; // r8
  int v76; // edx
  hkpConstraintInstance **v77; // rcx
  char *v78; // rax
  int v79; // r9d
  __int64 v80; // rcx
  void (__fastcall ***v81)(void *, __int64); // rdx
  unsigned int mUID; // r15d
  char *Name; // rax
  hkResultEnum m_enum; // edx
  __int64 v85; // r13
  int v86; // r8d
  hkResultEnum v87; // ebx
  __int64 v88; // r14
  hkaSkeleton *mhkaSkeleton; // rcx
  int m_size; // eax
  __int64 v91; // r15
  __int32 mPrev; // eax
  hkpRigidBody *v93; // r15
  hkpRigidBody *v94; // r13
  unsigned __int64 mTypeUID; // r14
  UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef> *v96; // rcx
  const char *v97; // rax
  UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef> *v98; // rcx
  UFG::allocator::free_link *v99; // rbx
  __int64 v100; // rax
  UFG::allocator::free_link *v101; // rbx
  __int64 v102; // rax
  hkpConstraintInstance *v103; // r13
  const char *v104; // rax
  UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef> *v105; // rcx
  UFG::qReflectObject *mData; // r15
  __int64 v107; // rbx
  char v108; // dl
  char v109; // cl
  _QWORD **v110; // rax
  hkpPositionConstraintMotor *v111; // rax
  __int64 v112; // rax
  __int64 v113; // r14
  char v114; // al
  int mParent_high; // eax
  const char *TypeName; // rax
  UFG::qReflectObjectType<UFG::ConstraintDefBallAndSocket,UFG::ConstraintDef> *v117; // rcx
  UFG::qReflectObject *v118; // r15
  char v119; // dl
  char v120; // cl
  _QWORD **v121; // rax
  hkpPositionConstraintMotor *v122; // rax
  __int64 v123; // rax
  char v124; // al
  char v125; // r8
  char v126; // dl
  char v127; // al
  const char *v128; // rax
  UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef> *v129; // rcx
  const char *v130; // rax
  char *v131; // rax
  __int64 v132; // rbx
  char v133; // dl
  char v134; // cl
  _QWORD **v135; // rax
  hkaRagdollInstance *v136; // rax
  UFG::qSafePointerNode<UFG::RagdollData>Vtbl *v137; // rax
  char v138; // al
  int v139; // r14d
  __int64 v140; // rbx
  int v141; // r14d
  __int64 v142; // rbx
  __int64 v143; // r12
  unsigned __int64 v144; // rax
  UFG::allocator::free_link *v145; // rbx
  unsigned int j; // r8d
  unsigned int vfptr; // ecx
  unsigned int vfptr_high; // ebx
  unsigned int v149; // ebx
  unsigned __int64 v150; // rax
  UFG::allocator::free_link *v151; // r15
  unsigned int k; // r8d
  __int64 v153; // rcx
  unsigned int m; // ebx
  unsigned int BoneID; // eax
  unsigned int v156; // eax
  unsigned int v157; // ecx
  int v158; // r15d
  __int64 n; // r13
  __int64 v160; // rdx
  void *(__fastcall *v161)(UFG::qSafePointerNode<UFG::RagdollData> *, unsigned int); // rcx
  __int64 mNext_low; // rcx
  unsigned int v163; // r14d
  unsigned int mNext_high; // ebx
  unsigned int v165; // ebx
  unsigned __int64 v166; // rax
  UFG::allocator::free_link *v167; // r12
  unsigned int ii; // r8d
  Skeleton *v169; // rbx
  UFG::RagdollFactory *v170; // r15
  UFG::RagdollSkeletonMapper *mSkeletonMapper; // rbx
  char *v172; // r14
  int v173; // ecx
  int v174; // ebx
  hkLifoAllocator *v175; // rcx
  signed int v176; // ebx
  int v177; // r8d
  char *v178; // r14
  int v179; // ecx
  int v180; // ebx
  hkLifoAllocator *v181; // rcx
  signed int v182; // ebx
  int v183; // r8d
  char *v184; // r14
  int v185; // ecx
  int v186; // ebx
  hkLifoAllocator *v187; // rcx
  signed int v188; // eax
  int v189; // r8d
  UFG::qSafePointerNode<UFG::RagdollData>Vtbl *check_null; // [rsp+20h] [rbp-A8h]
  UFG::qSymbolUC result; // [rsp+30h] [rbp-98h] BYREF
  __int64 v193; // [rsp+38h] [rbp-90h]
  hkArrayBase<hkpConstraintInstance *> array; // [rsp+40h] [rbp-88h] BYREF
  void *p; // [rsp+50h] [rbp-78h]
  void *v196; // [rsp+58h] [rbp-70h]
  hkArray<hkQsTransformf,hkContainerHeapAllocator> transforms; // [rsp+60h] [rbp-68h] BYREF
  void *v198; // [rsp+70h] [rbp-58h]
  int v199; // [rsp+78h] [rbp-50h]
  __int64 v200; // [rsp+80h] [rbp-48h]
  __int64 v201; // [rsp+88h] [rbp-40h]
  UFG::qReflectHandleBase v202; // [rsp+98h] [rbp-30h] BYREF
  hkVector4f inertiaDiagonal; // [rsp+C8h] [rbp+0h] BYREF
  UFG::qReflectHandleBase other; // [rsp+D8h] [rbp+10h] BYREF
  __int64 v205; // [rsp+100h] [rbp+38h]
  hkVector4f halfExtents; // [rsp+108h] [rbp+40h] BYREF
  _OWORD v207[3]; // [rsp+118h] [rbp+50h] BYREF
  void *ptr[2]; // [rsp+148h] [rbp+80h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+158h] [rbp+90h] BYREF
  UFG::qReflectHandleBase v210; // [rsp+238h] [rbp+170h] BYREF
  UFG::RagdollFactory *v211; // [rsp+2C8h] [rbp+200h]
  hkResult v212[2]; // [rsp+2D0h] [rbp+208h] BYREF
  unsigned int v213; // [rsp+2E0h] [rbp+218h]

  v205 = -2i64;
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
    v9->vfptr = (UFG::qSafePointerNode<UFG::RagdollData>Vtbl *)&UFG::RagdollData::`vftable;
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
  HIDWORD(v9[4].m_SafePointerList.mNode.mPrev) = skeleton->mNameUID;
  LODWORD(v9[4].m_SafePointerList.mNode.mPrev) = quality;
  if ( !skeleton->mNameUID || (v10 = UFG::qBaseTreeRB::Get(&this->mDefinitions.mTree, skeleton->mNameUID)) == 0i64 )
  {
    if ( (_S12_5 & 1) != 0 )
    {
      v11 = defaultGuid;
    }
    else
    {
      _S12_5 |= 1u;
      v11 = UFG::qStringHashUpper32("default", -1);
      defaultGuid = v11;
    }
    if ( v11 )
      v10 = UFG::qBaseTreeRB::Get(&this->mDefinitions.mTree, v11);
    else
      v10 = 0i64;
  }
  v12 = *(_QWORD *)&v10->mCount;
  v201 = v12;
  v200 = *(_QWORD *)(v12 + 112);
  StaticTypeName = UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData>::GetStaticTypeName(v8);
  v14 = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
  v15 = 0;
  v16 = *(_DWORD *)(v200 + 224);
  if ( v16 )
  {
    v17 = *(_QWORD *)(v200 + 216);
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
  v19 = UFG::qResourceInventory::Get(&UFG::gRigInventory, *(_DWORD *)(v18 + 80))[1].mNode.mChild[0];
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
    skeleton = *(Skeleton **)&v212[0].m_enum;
  }
  UFG::qQuickSortImpl<UFG::RigResource::BoneLookupEntry,UFG::sortBones>(
    UFG::gpRagDollSkeleton->mBoneIDLookup,
    &UFG::gpRagDollSkeleton->mBoneIDLookup[v24 - 1],
    0);
  LODWORD(v9[3].m_SafePointerList.mNode.mPrev) = Skeleton::GetBoneID(UFG::gpRagDollSkeleton, *(_DWORD *)(v12 + 128));
  v29 = -1i64;
  HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) = -1;
  v30 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  *(_QWORD *)&v212[0].m_enum = v30;
  if ( v30 )
    UFG::RagdollSkeletonMapper::RagdollSkeletonMapper((UFG::RagdollSkeletonMapper *)v30, *(_DWORD *)(v12 + 152), 0);
  else
    v31 = 0i64;
  v32 = v211;
  v211->mSkeletonMapper = v31;
  for ( i = 0; i < *(_DWORD *)(v12 + 152); ++i )
  {
    v34 = (UFG::qSymbolUC *)(*(_QWORD *)(v12 + 144) + 8i64 * i);
    UFG::RagdollSkeletonMapper::AddSimpleMapping(v32->mSkeletonMapper, v34, v34 + 1);
  }
  UFG::RagdollFactory::CreateSkeletonMappings(v32, skeleton, (UFG::RagdollData *)v9);
  vecDelDtor = (int)v9[1].vfptr[6].__vecDelDtor;
  transforms.m_data = 0i64;
  transforms.m_size = 0;
  transforms.m_capacityAndFlags = 0x80000000;
  v199 = vecDelDtor;
  if ( vecDelDtor )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v37 = (((48 * vecDelDtor + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    m_cur = (hkQsTransformf *)Value->m_cur;
    v39 = (char *)m_cur + v37;
    if ( v37 > Value->m_slabSize || v39 > Value->m_end )
      m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v37);
    else
      Value->m_cur = v39;
  }
  else
  {
    m_cur = 0i64;
  }
  transforms.m_data = m_cur;
  transforms.m_capacityAndFlags = vecDelDtor | 0x80000000;
  v198 = m_cur;
  check_null = v9[1].vfptr;
  UFG::RagdollFactory::BuildAndSetReferencePose(v32, (UFG::RagdollData *)v9, skeleton, &transforms);
  v41 = UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::GetStaticTypeName(v40);
  v42 = UFG::qStringHash64(v41, 0xFFFFFFFFFFFFFFFFui64);
  v43 = 0;
  v44 = *(_DWORD *)(v200 + 224);
  if ( v44 )
  {
    v45 = *(_QWORD *)(v200 + 216);
    while ( *(_QWORD *)(*(_QWORD *)(v45 + 8i64 * v43) + 56i64) != v42 )
    {
      if ( ++v43 >= v44 )
        goto LABEL_45;
    }
    v46 = *(_QWORD *)(v45 + 8i64 * v43);
  }
  else
  {
LABEL_45:
    v46 = 0i64;
  }
  v47 = *(_DWORD *)(v46 + 104);
  *(_QWORD *)(v46 + 112) = 0i64;
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v46 + 80), 0x1723EA91u, v47);
  v48 = *(void **)(v46 + 96);
  p = v48;
  LODWORD(v200) = *((_DWORD *)v48 + 22);
  v49 = v200;
  transforms.m_data = 0i64;
  transforms.m_size = 0;
  transforms.m_capacityAndFlags = 0x80000000;
  v199 = v200;
  if ( (_DWORD)v200 )
  {
    v50 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v51 = (((8 * v49 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v52 = (hkQsTransformf *)v50->m_cur;
    v53 = (char *)v52 + v51;
    if ( v51 > v50->m_slabSize || v53 > v50->m_end )
      v52 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v50, v51);
    else
      v50->m_cur = v53;
  }
  else
  {
    v52 = 0i64;
  }
  transforms.m_data = v52;
  transforms.m_capacityAndFlags = v49 | 0x80000000;
  v198 = v52;
  if ( (v49 & 0x3FFFFFFF) < v49 )
  {
    v54 = v49;
    if ( v49 < 2 * (v49 & 0x3FFFFFFF) )
      v54 = 2 * (v49 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(v212, &hkContainerHeapAllocator::s_alloc, &transforms, v54, 8);
  }
  transforms.m_size = v49;
  v55 = HK_SUCCESS;
  v212[0].m_enum = HK_SUCCESS;
  if ( *((_DWORD *)v48 + 22) )
  {
    v56 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    do
    {
      v57 = *(_QWORD *)(*((_QWORD *)v48 + 14) + 8i64 * (unsigned int)v55);
      v58 = -1i64;
      v193 = -1i64;
      v59 = 0;
      v60 = 0i64;
      if ( SLODWORD(v9[1].vfptr[6].__vecDelDtor) > 0 )
      {
        v61 = 0i64;
        while ( 1 )
        {
          UFG::qSymbol::create_from_string(
            (UFG::qSymbol *)&result,
            (const char *)(*(_QWORD *)((_BYTE *)v9[1].vfptr[5].__vecDelDtor + v61) & 0xFFFFFFFFFFFFFFFEui64));
          if ( result.mUID == *(_DWORD *)(v57 + 216) )
            break;
          ++v59;
          ++v60;
          v61 += 16i64;
          if ( v59 >= SLODWORD(v9[1].vfptr[6].__vecDelDtor) )
          {
            v58 = v193;
            goto LABEL_64;
          }
        }
        v58 = v60;
        v193 = v60;
      }
LABEL_64:
      v62 = *(_QWORD *)(v57 + 256);
      hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
      bodyInfo.m_solverDeactivation.m_storage = 3;
      if ( v213 )
        bodyInfo.m_qualityType.m_storage = *(_DWORD *)(v62 + 188);
      else
        bodyInfo.m_qualityType.m_storage = 4;
      bodyInfo.m_shape = *(hkpShape **)(v57 + 192);
      bodyInfo.m_friction = 0.30000001;
      bodyInfo.m_restitution = 0.0;
      bodyInfo.m_linearDamping = *(float *)(v62 + 88);
      bodyInfo.m_angularDamping = *(float *)(v62 + 92);
      bodyInfo.m_mass = *(float *)(v57 + 144);
      v207[0] = transform.m_quad;
      v207[1] = direction.m_quad;
      v207[2] = stru_141A71280.m_quad;
      *(_OWORD *)ptr = 0i64;
      ((void (__fastcall *)(__int64, _OWORD *, __int64, UFG::qReflectHandleBase *, UFG::qSafePointerNode<UFG::RagdollData>Vtbl *))bodyInfo.m_shape->vfptr[2].__vecDelDtor)(
        v63,
        v207,
        v64,
        &v202,
        check_null);
      halfExtents.m_quad = _mm_mul_ps(
                             _mm_sub_ps(
                               *(__m128 *)&v202.mTypeUID,
                               (__m128)v202.UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase>),
                             (__m128)xmmword_141A711B0);
      hkInertiaTensorComputer::computeBoxVolumeMassPropertiesDiagonalized(
        (hkResult *)&array.m_capacityAndFlags,
        &halfExtents,
        bodyInfo.m_mass,
        &inertiaDiagonal,
        (float *)&array.m_size);
      m_quad = bodyInfo.m_inertiaTensor.m_col0.m_quad;
      m_quad.m128_f32[0] = inertiaDiagonal.m_quad.m128_f32[0] * *(float *)(v62 + 108);
      bodyInfo.m_inertiaTensor.m_col0.m_quad = m_quad;
      m_quad.m128_f32[0] = inertiaDiagonal.m_quad.m128_f32[1] * *(float *)(v62 + 108);
      v66.m_quad = (__m128)bodyInfo.m_inertiaTensor.m_col1;
      bodyInfo.m_inertiaTensor.m_col1.m_quad = _mm_shuffle_ps(
                                                 _mm_unpacklo_ps(
                                                   bodyInfo.m_inertiaTensor.m_col1.m_quad,
                                                   _mm_shuffle_ps(m_quad, m_quad, 0)),
                                                 bodyInfo.m_inertiaTensor.m_col1.m_quad,
                                                 228);
      v66.m_quad.m128_f32[0] = inertiaDiagonal.m_quad.m128_f32[2] * *(float *)(v62 + 108);
      bodyInfo.m_inertiaTensor.m_col2.m_quad = _mm_shuffle_ps(
                                                 bodyInfo.m_inertiaTensor.m_col2.m_quad,
                                                 _mm_unpackhi_ps(
                                                   bodyInfo.m_inertiaTensor.m_col2.m_quad,
                                                   _mm_shuffle_ps(v66.m_quad, v66.m_quad, 0)),
                                                 180);
      hkpInertiaTensorComputer::clipInertia(3.0, &bodyInfo);
      bodyInfo.m_position = transforms.m_data[v58].m_translation;
      bodyInfo.m_rotation = transforms.m_data[v58].m_rotation;
      bodyInfo.m_collisionFilterInfo = *(_DWORD *)(v62 + 184);
      v67 = ++*(_BYTE *)(v56 + 80);
      *(_DWORD *)(v56 + 4i64 * v67) = 0;
      *(_QWORD *)(v56 + 8i64 * v67 + 16) = "hkpRigidBody";
      *(_QWORD *)(v56 + 8i64 * v67 + 48) = 0i64;
      v68 = *(_BYTE *)(v56 + 81);
      if ( v67 > v68 )
        v68 = v67;
      *(_BYTE *)(v56 + 81) = v68;
      v69 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v70 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v69[11] + 8i64))(v69[11], 720i64);
      v196 = v70;
      if ( v70 )
      {
        hkpRigidBody::hkpRigidBody(v70, &bodyInfo);
        v72 = v71;
      }
      else
      {
        v72 = 0i64;
      }
      UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(*(hkSimplePropertyValue *)(v62 + 8), v72);
      v73 = *(_BYTE *)(v56 + 80);
      if ( v73 > 0 )
      {
        *(_BYTE *)(v56 + 80) = v73 - 1;
      }
      else
      {
        *(_BYTE *)(v56 + 80) = 0;
        *(_DWORD *)v56 = 3;
        *(_QWORD *)(v56 + 16) = 0i64;
        *(_QWORD *)(v56 + 48) = 0i64;
      }
      transforms.m_data->m_translation.m_quad.m128_u64[v193] = (unsigned __int64)v72;
      v55 = v212[0].m_enum + 1;
      v212[0].m_enum = v55;
      v48 = p;
    }
    while ( (unsigned int)v55 < *((_DWORD *)p + 22) );
    v12 = v201;
    v29 = -1i64;
  }
  v74 = (void (__fastcall ***)(void *, __int64))*(unsigned int *)(v12 + 168);
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  LODWORD(v196) = (_DWORD)v74;
  if ( (_DWORD)v74 )
  {
    v75 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v76 = (((8 * (_DWORD)v74 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v77 = (hkpConstraintInstance **)v75->m_cur;
    v78 = (char *)v77 + v76;
    if ( v76 > v75->m_slabSize || v78 > v75->m_end )
      v77 = (hkpConstraintInstance **)hkLifoAllocator::allocateFromNewSlab(v75, v76);
    else
      v75->m_cur = v78;
  }
  else
  {
    v77 = 0i64;
  }
  array.m_data = v77;
  array.m_capacityAndFlags = (unsigned int)v74 | 0x80000000;
  p = v77;
  if ( (int)((unsigned int)v74 & 0x3FFFFFFF) < (int)v74 )
  {
    v79 = (int)v74;
    if ( (int)v74 < (int)(2 * ((unsigned int)v74 & 0x3FFFFFFF)) )
      v79 = 2 * ((unsigned int)v74 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(v212, &hkContainerHeapAllocator::s_alloc, &array, v79, 8);
  }
  array.m_size = (int)v74;
  if ( (_DWORD)v74 )
  {
    v80 = 0i64;
    v81 = v74;
    do
    {
      array.m_data[v80++] = 0i64;
      v81 = (void (__fastcall ***)(void *, __int64))((char *)v81 - 1);
    }
    while ( v81 );
  }
  mUID = 0;
  result.mUID = 0;
  p = v74;
  if ( (_DWORD)v74 )
  {
    while ( 1 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(
        &v202,
        (UFG::qReflectHandleBase *)(*(_QWORD *)(v12 + 160) + 40i64 * mUID));
      if ( !v202.mData )
        goto LABEL_157;
      if ( !BYTE5(v202.mData[1].mBaseNode.mParent) )
      {
        Name = UFG::qReflectObject::GetName(v202.mData);
        UFG::qPrintf("RagdollFactory constraint %s is not set to use TOI, is that correct?\n", Name);
      }
      m_enum = -1;
      v212[0].m_enum = -1;
      v85 = -1i64;
      v86 = -1;
      LODWORD(v193) = -1;
      v87 = HK_SUCCESS;
      v88 = 0i64;
      mhkaSkeleton = UFG::gpRagDollSkeleton->mhkaSkeleton;
      m_size = mhkaSkeleton->m_bones.m_size;
      if ( m_size > 0 )
      {
        v91 = 0i64;
        while ( 1 )
        {
          UFG::qSymbol::create_from_string(
            (UFG::qSymbol *)&array.m_capacityAndFlags,
            (const char *)((unsigned __int64)mhkaSkeleton->m_bones.m_data[v91].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
          if ( array.m_capacityAndFlags == HIDWORD(v202.mData[1].vfptr) )
            break;
          m_enum = v212[0].m_enum;
          if ( array.m_capacityAndFlags != LODWORD(v202.mData[1].mBaseNode.mUID) )
            goto LABEL_102;
          v86 = v87;
          LODWORD(v193) = v87;
          v29 = v88;
LABEL_103:
          if ( v85 == -1 || v29 == -1 )
          {
            ++v87;
            ++v88;
            ++v91;
            mhkaSkeleton = UFG::gpRagDollSkeleton->mhkaSkeleton;
            if ( v87 < mhkaSkeleton->m_bones.m_size )
              continue;
          }
          mUID = result.mUID;
          goto LABEL_107;
        }
        m_enum = v87;
        v212[0].m_enum = v87;
        v85 = v88;
LABEL_102:
        v86 = v193;
        goto LABEL_103;
      }
LABEL_107:
      mPrev = (__int32)v9[3].m_SafePointerList.mNode.mPrev;
      if ( (m_enum > mPrev || v86 > mPrev) && HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) == -1 )
        HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) = mUID - 1;
      v93 = (hkpRigidBody *)transforms.m_data->m_translation.m_quad.m128_u64[v85];
      v94 = (hkpRigidBody *)transforms.m_data->m_translation.m_quad.m128_u64[v29];
      UFG::qReflectHandleBase::qReflectHandleBase(&other);
      other.mTypeUID = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&other, other.mTypeUID, v202.mData->mBaseNode.mUID);
      mTypeUID = v202.mData->mTypeUID;
      v97 = UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef>::GetStaticTypeName(v96);
      if ( mTypeUID == UFG::qStringHash64(v97, 0xFFFFFFFFFFFFFFFFui64) )
      {
        v99 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
        v196 = v99;
        if ( v99 )
        {
          *(_QWORD *)&v212[0].m_enum = &v210;
          UFG::qReflectHandleBase::qReflectHandleBase(&v210, &other);
          UFG::Constraint::Constraint(
            (UFG::Constraint *)v99,
            (UFG::qReflectHandle<UFG::qReflectObject> *)&v210,
            v94,
            v93);
          *(_QWORD *)&v212[0].m_enum = v100;
        }
        else
        {
          *(_QWORD *)&v212[0].m_enum = 0i64;
        }
      }
      else
      {
        v101 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
        v196 = v101;
        if ( v101 )
        {
          *(_QWORD *)&v212[0].m_enum = v207;
          UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)v207, &other);
          UFG::Constraint::Constraint(
            (UFG::Constraint *)v101,
            (UFG::qReflectHandle<UFG::qReflectObject> *)v207,
            v93,
            v94);
          *(_QWORD *)&v212[0].m_enum = v102;
        }
        else
        {
          *(_QWORD *)&v212[0].m_enum = 0i64;
        }
      }
      v74 = *(void (__fastcall ****)(void *, __int64))&v212[0].m_enum;
      v103 = *(hkpConstraintInstance **)(*(_QWORD *)&v212[0].m_enum + 40i64);
      if ( !v213 )
        hkpConstraintInstance::setPriority(v103, PRIORITY_PSI);
      v104 = UFG::qReflectObjectType<UFG::ConstraintDefHinge,UFG::ConstraintDef>::GetStaticTypeName(v98);
      if ( mTypeUID == UFG::qStringHash64(v104, 0xFFFFFFFFFFFFFFFFui64) )
      {
        mData = v202.mData;
        v107 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v108 = ++*(_BYTE *)(v107 + 80);
        *(_DWORD *)(v107 + 4i64 * v108) = 3;
        *(_QWORD *)(v107 + 8i64 * v108 + 16) = "hkpPositionConstraintMotor";
        *(_QWORD *)(v107 + 8i64 * v108 + 48) = 0i64;
        v109 = *(_BYTE *)(v107 + 81);
        if ( v108 > v109 )
          v109 = v108;
        *(_BYTE *)(v107 + 81) = v109;
        v110 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v111 = (hkpPositionConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v110[11] + 8i64))(
                                               v110[11],
                                               48i64);
        v196 = v111;
        if ( v111 )
        {
          hkpPositionConstraintMotor::hkpPositionConstraintMotor(v111, 0.0);
          v113 = v112;
        }
        else
        {
          v113 = 0i64;
        }
        v114 = *(_BYTE *)(v107 + 80);
        if ( v114 > 0 )
        {
          *(_BYTE *)(v107 + 80) = v114 - 1;
        }
        else
        {
          *(_BYTE *)(v107 + 80) = 0;
          *(_DWORD *)v107 = 3;
          *(_QWORD *)(v107 + 16) = 0i64;
          *(_QWORD *)(v107 + 48) = 0i64;
        }
        *(_DWORD *)(v113 + 32) = mData[2].mBaseNode.mUID;
        *(_DWORD *)(v113 + 36) = HIDWORD(mData[2].mBaseNode.mUID);
        *(_DWORD *)(v113 + 28) = HIDWORD(mData[2].vfptr);
        *(_DWORD *)(v113 + 40) = mData[2].mBaseNode.mParent;
        mParent_high = HIDWORD(mData[2].mBaseNode.mParent);
      }
      else
      {
        TypeName = UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef>::GetTypeName(v105);
        if ( mTypeUID != UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64) )
        {
          v128 = UFG::qReflectObjectType<UFG::ConstraintDefBallAndSocket,UFG::ConstraintDef>::GetTypeName(v117);
          if ( mTypeUID != UFG::qStringHash64(v128, 0xFFFFFFFFFFFFFFFFui64) )
          {
            v130 = UFG::qReflectObjectType<UFG::ConstraintDefStiffSpring,UFG::ConstraintDef>::GetStaticTypeName(v129);
            UFG::qStringHash64(v130, 0xFFFFFFFFFFFFFFFFui64);
          }
          hkReferencedObject::addReference(v103);
          goto LABEL_149;
        }
        v118 = v202.mData;
        v107 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v119 = ++*(_BYTE *)(v107 + 80);
        *(_DWORD *)(v107 + 4i64 * v119) = 3;
        *(_QWORD *)(v107 + 8i64 * v119 + 16) = "hkpPositionConstraintMotor";
        *(_QWORD *)(v107 + 8i64 * v119 + 48) = 0i64;
        v120 = *(_BYTE *)(v107 + 81);
        if ( v119 > v120 )
          v120 = v119;
        *(_BYTE *)(v107 + 81) = v120;
        v121 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v122 = (hkpPositionConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v121[11] + 8i64))(
                                               v121[11],
                                               48i64);
        v196 = v122;
        if ( v122 )
        {
          hkpPositionConstraintMotor::hkpPositionConstraintMotor(v122, 0.0);
          v113 = v123;
        }
        else
        {
          v113 = 0i64;
        }
        v124 = *(_BYTE *)(v107 + 80);
        if ( v124 > 0 )
        {
          *(_BYTE *)(v107 + 80) = v124 - 1;
        }
        else
        {
          *(_BYTE *)(v107 + 80) = 0;
          *(_DWORD *)v107 = 3;
          *(_QWORD *)(v107 + 16) = 0i64;
          *(_QWORD *)(v107 + 48) = 0i64;
        }
        *(_DWORD *)(v113 + 32) = v118[2].mBaseNode.mChildren[1];
        *(_DWORD *)(v113 + 36) = HIDWORD(v118[2].mBaseNode.mChildren[1]);
        *(_DWORD *)(v113 + 28) = HIDWORD(v118[2].mBaseNode.mChildren[0]);
        *(_DWORD *)(v113 + 40) = v118[2].mBaseNode.mNeighbours[0];
        mParent_high = HIDWORD(v118[2].mBaseNode.mNeighbours[0]);
      }
      *(_DWORD *)(v113 + 44) = mParent_high;
      v125 = ++*(_BYTE *)(v107 + 80);
      *(_DWORD *)(v107 + 4i64 * v125) = 3;
      *(_QWORD *)(v107 + 8i64 * v125 + 16) = "convertToPowered";
      *(_QWORD *)(v107 + 8i64 * v125 + 48) = 0i64;
      v126 = *(_BYTE *)(v107 + 81);
      if ( v125 > v126 )
        v126 = v125;
      *(_BYTE *)(v107 + 81) = v126;
      v103 = hkpConstraintUtils::convertToPowered(v103, (hkpConstraintMotor *)v113, 0);
      hkReferencedObject::removeReference((hkReferencedObject *)v113);
      v127 = *(_BYTE *)(v107 + 80);
      if ( v127 > 0 )
      {
        *(_BYTE *)(v107 + 80) = v127 - 1;
      }
      else
      {
        *(_BYTE *)(v107 + 80) = 0;
        *(_DWORD *)v107 = 3;
        *(_QWORD *)(v107 + 16) = 0i64;
        *(_QWORD *)(v107 + 48) = 0i64;
      }
      v74 = *(void (__fastcall ****)(void *, __int64))&v212[0].m_enum;
LABEL_149:
      if ( array.m_data[v29 - 1] )
      {
        v131 = (char *)p - 1;
        if ( (__int64)p - 1 >= 0 )
        {
          while ( array.m_data[(_QWORD)v131] )
          {
            if ( (__int64)--v131 < 0 )
              goto LABEL_156;
          }
          array.m_data[(_QWORD)v131] = v103;
        }
      }
      else
      {
        array.m_data[v29 - 1] = v103;
      }
LABEL_156:
      (**v74)(v74, 1i64);
      UFG::qReflectHandleBase::~qReflectHandleBase(&other);
      v12 = v201;
      mUID = result.mUID;
      LODWORD(v74) = array.m_size;
LABEL_157:
      UFG::qReflectHandleBase::~qReflectHandleBase(&v202);
      result.mUID = ++mUID;
      if ( mUID >= (unsigned int)v74 )
        break;
      v29 = -1i64;
    }
  }
  if ( HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) == -1 )
    HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) = array.m_size - 1;
  hkpInertiaTensorComputer::optimizeInertiasOfConstraintTree(
    array.m_data,
    HIDWORD(v9[3].m_SafePointerList.mNode.mPrev) + 1,
    (hkpRigidBody *)transforms.m_data->m_translation.m_quad.m128_u64[0],
    1.5);
  v132 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v133 = ++*(_BYTE *)(v132 + 80);
  *(_DWORD *)(v132 + 4i64 * v133) = 3;
  *(_QWORD *)(v132 + 8i64 * v133 + 16) = "hkaRagdollInstance";
  *(_QWORD *)(v132 + 8i64 * v133 + 48) = 0i64;
  v134 = *(_BYTE *)(v132 + 81);
  if ( v133 > v134 )
    v134 = v133;
  *(_BYTE *)(v132 + 81) = v134;
  v135 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v136 = (hkaRagdollInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v135[11] + 8i64))(v135[11], 72i64);
  *(_QWORD *)&v212[0].m_enum = v136;
  if ( v136 )
    hkaRagdollInstance::hkaRagdollInstance(
      v136,
      (hkArrayBase<hkpRigidBody *> *)&transforms,
      &array,
      (hkaSkeleton *)v9[1].vfptr);
  else
    v137 = 0i64;
  v9[5].vfptr = v137;
  v138 = *(_BYTE *)(v132 + 80);
  if ( v138 > 0 )
  {
    *(_BYTE *)(v132 + 80) = v138 - 1;
  }
  else
  {
    *(_BYTE *)(v132 + 80) = 0;
    *(_DWORD *)v132 = 3;
    *(_QWORD *)(v132 + 16) = 0i64;
    *(_QWORD *)(v132 + 48) = 0i64;
  }
  v139 = 0;
  if ( array.m_size > 0 )
  {
    v140 = 0i64;
    do
    {
      hkReferencedObject::removeReference(array.m_data[v140]);
      ++v139;
      ++v140;
    }
    while ( v139 < array.m_size );
  }
  v141 = 0;
  if ( transforms.m_size > 0 )
  {
    v142 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)transforms.m_data->m_translation.m_quad.m128_u64[v142]);
      ++v141;
      ++v142;
    }
    while ( v141 < transforms.m_size );
  }
  LODWORD(v9[3].m_SafePointerList.mNode.mNext) = *(_DWORD *)(v12 + 132);
  HIDWORD(v9[3].m_SafePointerList.mNode.mNext) = *(_DWORD *)(v12 + 136);
  LODWORD(v9[4].vfptr) = *(_DWORD *)(v12 + 140);
  v143 = (int)v200;
  if ( (unsigned int)v200 > HIDWORD(v9[2].vfptr) && (_DWORD)v200 != LODWORD(v9[2].vfptr) )
  {
    v144 = 4i64 * (unsigned int)v200;
    if ( !is_mul_ok((unsigned int)v200, 4ui64) )
      v144 = -1i64;
    v145 = UFG::qMalloc(v144, "qArray.Reallocate(Reserve)", 0i64);
    if ( v9[2].m_SafePointerList.mNode.mPrev )
    {
      for ( j = 0; j < LODWORD(v9[2].vfptr); ++j )
        *((_DWORD *)&v145->mNext + j) = *((_DWORD *)&v9[2].m_SafePointerList.mNode.mPrev->mPrev + j);
      operator delete[](v9[2].m_SafePointerList.mNode.mPrev);
    }
    v9[2].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)v145;
    HIDWORD(v9[2].vfptr) = v143;
  }
  vfptr = (unsigned int)v9[2].vfptr;
  if ( (int)(v143 - vfptr) <= 0 )
  {
    if ( vfptr != (_DWORD)v143 )
    {
      if ( vfptr - (unsigned int)v143 < vfptr )
        LODWORD(v9[2].vfptr) = v143;
      else
        LODWORD(v9[2].vfptr) = 0;
    }
  }
  else
  {
    vfptr_high = HIDWORD(v9[2].vfptr);
    if ( (unsigned int)v143 > vfptr_high )
    {
      if ( vfptr_high )
        v149 = 2 * vfptr_high;
      else
        v149 = 1;
      for ( ; v149 < (unsigned int)v143; v149 *= 2 )
        ;
      if ( v149 <= 4 )
        v149 = 4;
      if ( v149 - (unsigned int)v143 > 0x10000 )
        v149 = v143 + 0x10000;
      if ( v149 != vfptr )
      {
        v150 = 4i64 * v149;
        if ( !is_mul_ok(v149, 4ui64) )
          v150 = -1i64;
        v151 = UFG::qMalloc(v150, "qArray.Reallocate(Resize)", 0i64);
        if ( v9[2].m_SafePointerList.mNode.mPrev )
        {
          for ( k = 0; k < LODWORD(v9[2].vfptr); ++k )
            *((_DWORD *)&v151->mNext + k) = *((_DWORD *)&v9[2].m_SafePointerList.mNode.mPrev->mPrev + k);
          operator delete[](v9[2].m_SafePointerList.mNode.mPrev);
        }
        v9[2].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)v151;
        HIDWORD(v9[2].vfptr) = v149;
      }
    }
    LODWORD(v9[2].vfptr) = v143;
  }
  v153 = 0i64;
  if ( (int)v143 > 0 )
  {
    do
      *((_DWORD *)&v9[2].m_SafePointerList.mNode.mPrev->mPrev + v153++) = 21;
    while ( v153 < v143 );
  }
  for ( m = 0; m < *(_DWORD *)(v12 + 184); ++m )
  {
    BoneID = Skeleton::GetBoneID(UFG::gpRagDollSkeleton, *(_DWORD *)(*(_QWORD *)(v12 + 176) + 12i64 * m));
    if ( BoneID != -1 )
      *((_DWORD *)&v9[2].m_SafePointerList.mNode.mPrev->mPrev + BoneID) = 32
                                                                        * (*(_DWORD *)(*(_QWORD *)(v12 + 176)
                                                                                     + 12i64 * m
                                                                                     + 4) | (32
                                                                                           * *(_DWORD *)(*(_QWORD *)(v12 + 176) + 12i64 * m + 8)));
  }
  v156 = 0;
  v157 = (unsigned int)v9[2].vfptr;
  if ( v157 )
  {
    do
      ++v156;
    while ( v156 < v157 );
  }
  v158 = 0;
  for ( n = SLODWORD(v9[1].vfptr[4].__vecDelDtor); v158 <= SLODWORD(v9[3].m_SafePointerList.mNode.mPrev); ++v158 )
  {
    v160 = 0i64;
    if ( n <= 0 )
    {
LABEL_220:
      mNext_low = LODWORD(v9[2].m_SafePointerList.mNode.mNext);
      v213 = mNext_low;
      v163 = mNext_low + 1;
      mNext_high = HIDWORD(v9[2].m_SafePointerList.mNode.mNext);
      if ( (int)mNext_low + 1 > mNext_high )
      {
        if ( mNext_high )
          v165 = 2 * mNext_high;
        else
          v165 = 1;
        for ( ; v165 < v163; v165 *= 2 )
          ;
        if ( v165 <= 4 )
          v165 = 4;
        if ( v165 - v163 > 0x10000 )
          v165 = mNext_low + 65537;
        if ( v165 != (_DWORD)mNext_low )
        {
          v166 = 4i64 * v165;
          if ( !is_mul_ok(v165, 4ui64) )
            v166 = -1i64;
          v167 = UFG::qMalloc(v166, "qArray.Add", 0i64);
          if ( v9[3].vfptr )
          {
            for ( ii = 0; ii < LODWORD(v9[2].m_SafePointerList.mNode.mNext); ++ii )
              *((_DWORD *)&v167->mNext + ii) = *((_DWORD *)&v9[3].vfptr->__vecDelDtor + ii);
            operator delete[](v9[3].vfptr);
          }
          v9[3].vfptr = (UFG::qSafePointerNode<UFG::RagdollData>Vtbl *)v167;
          HIDWORD(v9[2].m_SafePointerList.mNode.mNext) = v165;
          mNext_low = v213;
        }
      }
      LODWORD(v9[2].m_SafePointerList.mNode.mNext) = v163;
      *((_DWORD *)&v9[3].vfptr->__vecDelDtor + mNext_low) = v158;
    }
    else
    {
      v161 = v9[1].vfptr[3].__vecDelDtor;
      while ( *(__int16 *)v161 != v158 )
      {
        ++v160;
        v161 = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::RagdollData> *, unsigned int))((char *)v161 + 2);
        if ( v160 >= n )
          goto LABEL_220;
      }
    }
  }
  v169 = UFG::gpRagDollSkeleton;
  if ( UFG::gpRagDollSkeleton )
  {
    _((AMD_HD3D *)UFG::gpRagDollSkeleton);
    operator delete[](v169);
  }
  UFG::gpRagDollSkeleton = 0i64;
  v170 = v211;
  mSkeletonMapper = v211->mSkeletonMapper;
  if ( mSkeletonMapper )
  {
    UFG::RagdollSkeletonMapper::~RagdollSkeletonMapper(v211->mSkeletonMapper);
    operator delete[](mSkeletonMapper);
  }
  v170->mSkeletonMapper = 0i64;
  v172 = (char *)p;
  v173 = array.m_size;
  if ( p == array.m_data )
    v173 = 0;
  array.m_size = v173;
  v174 = (int)v196;
  v175 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v176 = (8 * v174 + 127) & 0xFFFFFF80;
  v177 = (v176 + 15) & 0xFFFFFFF0;
  if ( v176 > v175->m_slabSize || &v172[v177] != v175->m_cur || v175->m_firstNonLifoEnd == v172 )
    hkLifoAllocator::slowBlockFree(v175, v172, v177);
  else
    v175->m_cur = v172;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  v178 = (char *)v198;
  v179 = transforms.m_size;
  if ( v198 == transforms.m_data )
    v179 = 0;
  transforms.m_size = v179;
  v180 = v199;
  v181 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v182 = (8 * v180 + 127) & 0xFFFFFF80;
  v183 = (v182 + 15) & 0xFFFFFFF0;
  if ( v182 > v181->m_slabSize || &v178[v183] != v181->m_cur || v181->m_firstNonLifoEnd == v178 )
    hkLifoAllocator::slowBlockFree(v181, v178, v183);
  else
    v181->m_cur = v178;
  transforms.m_size = 0;
  if ( transforms.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      transforms.m_data,
      8 * transforms.m_capacityAndFlags);
  transforms.m_data = 0i64;
  transforms.m_capacityAndFlags = 0x80000000;
  v184 = (char *)v198;
  v185 = transforms.m_size;
  if ( !v198 )
    v185 = 0;
  transforms.m_size = v185;
  v186 = v199;
  v187 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v188 = (48 * v186 + 127) & 0xFFFFFF80;
  v189 = (v188 + 15) & 0xFFFFFFF0;
  if ( v188 > v187->m_slabSize || &v184[v189] != v187->m_cur || v187->m_firstNonLifoEnd == v184 )
    hkLifoAllocator::slowBlockFree(v187, v184, v189);
  else
    v187->m_cur = v184;
  transforms.m_size = 0;
  if ( transforms.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      transforms.m_data,
      48 * (transforms.m_capacityAndFlags & 0x3FFFFFFF));
  return (UFG::RagdollData *)v9;
}ansforms.m_data,
      48 * (transforms.m_capacityAndFlags & 0x3FFFFFFF));
  return (UFG::RagdollData *)v9;
}

// File Line: 1012
// RVA: 0x459270
void __fastcall UFG::RagdollFactory::BuildAndSetReferencePose(
        UFG::RagdollFactory *this,
        UFG::RagdollData *data,
        Skeleton *skeleton,
        hkArray<hkQsTransformf,hkContainerHeapAllocator> *transforms)
{
  hkaSkeleton *mhkaSkeleton; // r14
  __int64 v6; // r15
  char v7; // di
  int v8; // esi
  char v9; // cl
  _QWORD **Value; // rax
  __int64 v11; // rax
  hkaPose *v12; // r12
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *p_m_localPose; // rcx
  int v14; // edi
  int v15; // r13d
  int v16; // eax
  int v17; // eax
  int v18; // r9d
  int v19; // eax
  int v20; // eax
  int v21; // r9d
  int v22; // eax
  int v23; // eax
  int v24; // r9d
  int m_size; // r13d
  int v26; // r9d
  int v27; // eax
  int v28; // eax
  int v29; // r9d
  int v30; // edx
  float *v31; // rdi
  __int64 v32; // rcx
  char v33; // al
  char v34; // dl
  char v35; // cl
  _QWORD **v36; // rax
  __int64 v37; // rax
  hkaPose *v38; // r14
  __int64 v39; // r13
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v40; // rdx
  int v41; // edi
  int m_enum; // ecx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *p_m_modelPose; // rcx
  int v44; // eax
  int v45; // eax
  int v46; // r9d
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v47; // rcx
  int v48; // eax
  int v49; // eax
  int v50; // r9d
  hkArray<unsigned int,hkContainerHeapAllocator> *p_m_boneFlags; // rcx
  int v52; // eax
  int v53; // eax
  int v54; // r9d
  hkResultEnum v55; // r8d
  int v56; // r9d
  hkArray<float,hkContainerHeapAllocator> *p_m_floatSlotValues; // rdi
  int v58; // eax
  int v59; // eax
  int v60; // r9d
  int v61; // edx
  __int64 v62; // rcx
  float *v63; // rdi
  char v64; // al
  int v65; // edi
  __int64 v66; // r15
  __int64 v67; // rdx
  __int64 v68; // rcx
  __int64 v69; // r8
  __int16 *v70; // rcx
  __int64 v71; // rdx
  hkQsTransformf *v72; // rax
  hkaPose *v73; // rcx
  hkVector4f v74; // xmm6
  hkQuaternionf v75; // xmm7
  hkVector4f v76; // xmm8
  hkQsTransformf *v77; // rcx
  __int64 v78; // r15
  __int64 v79; // rdx
  __int64 v80; // r9
  unsigned int *m_data; // r8
  hkQsTransformf *v82; // rdi
  __int16 v83; // ax
  hkQsTransformf *v84; // r13
  hkQsTransformf *v85; // rbx
  __m128i inserted; // xmm0
  __m128 v87; // xmm8
  __m128 v88; // xmm2
  __m128 v89; // xmm9
  __m128 v90; // xmm7
  __m128 m_quad; // xmm3
  __m128 v92; // xmm1
  __m128 v93; // xmm5
  __m128 v94; // xmm4
  __m128 v95; // xmm2
  __m128 v96; // xmm3
  __m128 v97; // xmm2
  __m128 v98; // xmm4
  __m128 v99; // xmm4
  __m128 v100; // xmm3
  hkQsTransformf *v101; // rax
  _OWORD *m128_f32; // rcx
  __int64 v103; // rax
  _QWORD **v104; // rax
  _QWORD **v105; // rax
  hkResult v106; // [rsp+Ch] [rbp-7Dh] BYREF
  hkResult v107; // [rsp+10h] [rbp-79h] BYREF
  hkResult v108[2]; // [rsp+18h] [rbp-71h] BYREF
  int sizeElem[2]; // [rsp+20h] [rbp-69h]
  __int64 v110; // [rsp+28h] [rbp-61h]
  hkResult v111[2]; // [rsp+30h] [rbp-59h] BYREF
  hkVector4f v112; // [rsp+38h] [rbp-51h] BYREF
  __m128 v113; // [rsp+48h] [rbp-41h]
  __m128 v114; // [rsp+58h] [rbp-31h]
  void *p; // [rsp+F0h] [rbp+67h]
  hkResult result[2]; // [rsp+F8h] [rbp+6Fh] BYREF
  __int64 v117; // [rsp+108h] [rbp+7Fh]

  v110 = -2i64;
  mhkaSkeleton = skeleton->mhkaSkeleton;
  v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v7 = ++*(_BYTE *)(v6 + 80);
  *(_DWORD *)(v6 + 4i64 * v7) = 2;
  *(_QWORD *)(v6 + 8i64 * v7 + 16) = "hkaPose4";
  v8 = 0;
  *(_QWORD *)(v6 + 8i64 * v7 + 48) = 0i64;
  v9 = *(_BYTE *)(v6 + 81);
  if ( v7 > v9 )
    v9 = v7;
  *(_BYTE *)(v6 + 81) = v9;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  v12 = (hkaPose *)v11;
  *(_QWORD *)sizeElem = v11;
  *(_QWORD *)&v108[0].m_enum = v11;
  if ( v11 )
  {
    *(_QWORD *)v11 = mhkaSkeleton;
    p_m_localPose = (hkArray<hkQsTransformf,hkContainerHeapAllocator> *)(v11 + 8);
    *(_QWORD *)(v11 + 8) = 0i64;
    *(_DWORD *)(v11 + 16) = 0;
    *(_DWORD *)(v11 + 20) = 0x80000000;
    *(_QWORD *)(v11 + 24) = 0i64;
    *(_DWORD *)(v11 + 32) = 0;
    *(_DWORD *)(v11 + 36) = 0x80000000;
    *(_QWORD *)(v11 + 40) = 0i64;
    *(_DWORD *)(v11 + 48) = 0;
    *(_DWORD *)(v11 + 52) = 0x80000000;
    *(_WORD *)(v11 + 56) = 0;
    *(_QWORD *)(v11 + 64) = 0i64;
    *(_DWORD *)(v11 + 72) = 0;
    *(_DWORD *)(v11 + 76) = 0x80000000;
    v14 = *(_DWORD *)(*(_QWORD *)v11 + 48i64);
    v15 = (v14 + 3) & 0xFFFFFFFC;
    if ( (*(_DWORD *)(v11 + 36) & 0x3FFFFFFF) >= v15 )
    {
      result[0].m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, (void *)(v11 + 24), v15, 48);
      p_m_localPose = &v12->m_localPose;
    }
    if ( (p_m_localPose->m_capacityAndFlags & 0x3FFFFFFF) >= v15 )
      v106.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v106, &hkContainerHeapAllocator::s_alloc, p_m_localPose, v15, 48);
    if ( (v12->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v15 )
      v112.m_quad.m128_i32[0] = 0;
    else
      hkArrayUtil::_reserve((hkResult *)&v112, &hkContainerHeapAllocator::s_alloc, &v12->m_boneFlags, v15, 4);
    v16 = v12->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v16 >= v14 )
    {
      v112.m_quad.m128_i32[2] = 0;
    }
    else
    {
      v17 = 2 * v16;
      v18 = v14;
      if ( v14 < v17 )
        v18 = v17;
      hkArrayUtil::_reserve(
        (hkResult *)&v112.m_quad.m128_u16[4],
        &hkContainerHeapAllocator::s_alloc,
        &v12->m_modelPose,
        v18,
        48);
    }
    v12->m_modelPose.m_size = v14;
    v19 = v12->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v19 >= v14 )
    {
      v111[1].m_enum = HK_SUCCESS;
    }
    else
    {
      v20 = 2 * v19;
      v21 = v14;
      if ( v14 < v20 )
        v21 = v20;
      hkArrayUtil::_reserve(&v111[1], &hkContainerHeapAllocator::s_alloc, &v12->m_localPose, v21, 48);
    }
    v12->m_localPose.m_size = v14;
    v22 = v12->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v22 >= v14 )
    {
      v112.m_quad.m128_i32[1] = 0;
    }
    else
    {
      v23 = 2 * v22;
      v24 = v14;
      if ( v14 < v23 )
        v24 = v23;
      hkArrayUtil::_reserve(
        (hkResult *)&v112.m_quad.m128_i16[2],
        &hkContainerHeapAllocator::s_alloc,
        &v12->m_boneFlags,
        v24,
        4);
    }
    v12->m_boneFlags.m_size = v14;
    m_size = v12->m_skeleton->m_floatSlots.m_size;
    v26 = (m_size + 3) & 0xFFFFFFFC;
    if ( (v12->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v26 )
      v111[0].m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(v111, &hkContainerHeapAllocator::s_alloc, &v12->m_floatSlotValues, v26, 4);
    v27 = v12->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 >= m_size )
    {
      v107.m_enum = HK_SUCCESS;
    }
    else
    {
      v28 = 2 * v27;
      v29 = m_size;
      if ( m_size < v28 )
        v29 = v28;
      hkArrayUtil::_reserve(&v107, &hkContainerHeapAllocator::s_alloc, &v12->m_floatSlotValues, v29, 4);
    }
    v30 = m_size - v12->m_floatSlotValues.m_size;
    v31 = &v12->m_floatSlotValues.m_data[v12->m_floatSlotValues.m_size];
    v32 = v30;
    if ( v30 > 0 )
    {
      while ( v32 )
      {
        *v31++ = 0.0;
        --v32;
      }
    }
    v12->m_floatSlotValues.m_size = m_size;
  }
  else
  {
    v12 = 0i64;
    *(_QWORD *)sizeElem = 0i64;
  }
  hkaPose::setToReferencePose(v12);
  v33 = *(_BYTE *)(v6 + 80);
  if ( v33 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v33 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v34 = ++*(_BYTE *)(v6 + 80);
  *(_DWORD *)(v6 + 4i64 * v34) = 2;
  *(_QWORD *)(v6 + 8i64 * v34 + 16) = "hkaPose5";
  *(_QWORD *)(v6 + 8i64 * v34 + 48) = 0i64;
  v35 = *(_BYTE *)(v6 + 81);
  if ( v34 > v35 )
    v35 = v34;
  *(_BYTE *)(v6 + 81) = v35;
  v36 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v37 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v36[11] + 8i64))(v36[11], 80i64);
  v38 = (hkaPose *)v37;
  *(_QWORD *)&v111[0].m_enum = v37;
  v39 = v117;
  if ( v37 )
  {
    *(_QWORD *)v37 = v117;
    v40 = (hkArray<hkQsTransformf,hkContainerHeapAllocator> *)(v37 + 8);
    *(_QWORD *)(v37 + 8) = 0i64;
    *(_DWORD *)(v37 + 16) = 0;
    *(_DWORD *)(v37 + 20) = 0x80000000;
    *(_QWORD *)(v37 + 24) = 0i64;
    *(_DWORD *)(v37 + 32) = 0;
    *(_DWORD *)(v37 + 36) = 0x80000000;
    *(_QWORD *)(v37 + 40) = 0i64;
    *(_DWORD *)(v37 + 48) = 0;
    *(_DWORD *)(v37 + 52) = 0x80000000;
    *(_WORD *)(v37 + 56) = 0;
    *(_QWORD *)(v37 + 64) = 0i64;
    *(_DWORD *)(v37 + 72) = 0;
    *(_DWORD *)(v37 + 76) = 0x80000000;
    v41 = *(_DWORD *)(*(_QWORD *)v37 + 48i64);
    m_enum = (v41 + 3) & 0xFFFFFFFC;
    result[0].m_enum = m_enum;
    if ( (*(_DWORD *)(v37 + 36) & 0x3FFFFFFF) >= m_enum )
    {
      v107.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v107, &hkContainerHeapAllocator::s_alloc, (void *)(v37 + 24), m_enum, 48);
      m_enum = result[0].m_enum;
      v40 = &v38->m_localPose;
    }
    if ( (v40->m_capacityAndFlags & 0x3FFFFFFF) >= m_enum )
    {
      v111[0].m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(v111, &hkContainerHeapAllocator::s_alloc, v40, m_enum, 48);
      m_enum = result[0].m_enum;
    }
    if ( (v38->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= m_enum )
      v112.m_quad.m128_i32[1] = 0;
    else
      hkArrayUtil::_reserve(
        (hkResult *)&v112.m_quad.m128_i16[2],
        &hkContainerHeapAllocator::s_alloc,
        &v38->m_boneFlags,
        m_enum,
        4);
    p_m_modelPose = &v38->m_modelPose;
    v44 = v38->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v44 >= v41 )
    {
      v111[1].m_enum = HK_SUCCESS;
    }
    else
    {
      v45 = 2 * v44;
      v46 = v41;
      if ( v41 < v45 )
        v46 = v45;
      hkArrayUtil::_reserve(&v111[1], &hkContainerHeapAllocator::s_alloc, &v38->m_modelPose, v46, 48);
      p_m_modelPose = &v38->m_modelPose;
    }
    p_m_modelPose->m_size = v41;
    v47 = &v38->m_localPose;
    v48 = v38->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v48 >= v41 )
    {
      v112.m_quad.m128_i32[2] = 0;
    }
    else
    {
      v49 = 2 * v48;
      v50 = v41;
      if ( v41 < v49 )
        v50 = v49;
      hkArrayUtil::_reserve(
        (hkResult *)&v112.m_quad.m128_u16[4],
        &hkContainerHeapAllocator::s_alloc,
        &v38->m_localPose,
        v50,
        48);
      v47 = &v38->m_localPose;
    }
    v47->m_size = v41;
    p_m_boneFlags = &v38->m_boneFlags;
    v52 = v38->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v52 >= v41 )
    {
      v112.m_quad.m128_i32[0] = 0;
    }
    else
    {
      v53 = 2 * v52;
      v54 = v41;
      if ( v41 < v53 )
        v54 = v53;
      hkArrayUtil::_reserve((hkResult *)&v112, &hkContainerHeapAllocator::s_alloc, &v38->m_boneFlags, v54, 4);
      p_m_boneFlags = &v38->m_boneFlags;
    }
    p_m_boneFlags->m_size = v41;
    v55 = v38->m_skeleton->m_floatSlots.m_size;
    result[0].m_enum = v55;
    v56 = (v55 + 3) & 0xFFFFFFFC;
    p_m_floatSlotValues = &v38->m_floatSlotValues;
    if ( (v38->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v56 )
    {
      v106.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v106, &hkContainerHeapAllocator::s_alloc, &v38->m_floatSlotValues, v56, 4);
      v55 = result[0].m_enum;
    }
    v58 = v38->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v58 >= v55 )
    {
      v108[0].m_enum = HK_SUCCESS;
    }
    else
    {
      v59 = 2 * v58;
      v60 = v55;
      if ( v55 < v59 )
        v60 = v59;
      hkArrayUtil::_reserve(v108, &hkContainerHeapAllocator::s_alloc, &v38->m_floatSlotValues, v60, 4);
      v55 = result[0].m_enum;
    }
    v61 = v55 - v38->m_floatSlotValues.m_size;
    v62 = v61;
    if ( v61 > 0 )
    {
      v63 = &v38->m_floatSlotValues.m_data[v38->m_floatSlotValues.m_size];
      while ( v62 )
      {
        *v63++ = 0.0;
        --v62;
      }
      p_m_floatSlotValues = &v38->m_floatSlotValues;
    }
    p_m_floatSlotValues->m_size = v55;
  }
  else
  {
    v38 = 0i64;
  }
  hkaPose::setToReferencePose(v38);
  v64 = *(_BYTE *)(v6 + 80);
  if ( v64 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v64 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v65 = 0;
  if ( *(int *)(v39 + 48) > 0 )
  {
    v66 = 0i64;
    do
    {
      v67 = 0i64;
      v68 = *((_QWORD *)p + 4);
      v69 = *(int *)(v68 + 88);
      if ( v69 <= 0 )
        goto LABEL_100;
      v70 = *(__int16 **)(v68 + 80);
      while ( *v70 != v65 )
      {
        ++v67;
        v70 += 32;
        if ( v67 >= v69 )
          goto LABEL_100;
      }
      v71 = v70[1];
      if ( (_DWORD)v71 == -1 )
      {
LABEL_100:
        if ( (v38->m_boneFlags.m_data[v66] & 2) != 0 )
        {
          LODWORD(v71) = v65;
          v73 = v38;
          goto LABEL_103;
        }
        v72 = &v38->m_modelPose.m_data[v65];
      }
      else
      {
        if ( (v12->m_boneFlags.m_data[v71] & 2) != 0 )
        {
          v73 = v12;
LABEL_103:
          v72 = hkaPose::calculateBoneModelSpace(v73, v71);
          goto LABEL_104;
        }
        v72 = &v12->m_modelPose.m_data[v71];
      }
LABEL_104:
      v74.m_quad = (__m128)v72->m_translation;
      v75.m_vec.m_quad = (__m128)v72->m_rotation;
      v76.m_quad = (__m128)v72->m_scale;
      if ( transforms->m_size == (transforms->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, transforms, 48);
      v77 = &transforms->m_data[transforms->m_size];
      v77->m_translation = (hkVector4f)v74.m_quad;
      v77->m_rotation = (hkQuaternionf)v75.m_vec.m_quad;
      v77->m_scale = (hkVector4f)v76.m_quad;
      ++transforms->m_size;
      ++v65;
      ++v66;
    }
    while ( v65 < *(_DWORD *)(v39 + 48) );
  }
  hkaPose::setPoseModelSpace(v38, transforms);
  if ( *(int *)(v39 + 48) > 0 )
  {
    v78 = 0i64;
    v79 = 0i64;
    *(_QWORD *)&v108[0].m_enum = 0i64;
    v80 = 0i64;
    *(_QWORD *)&result[0].m_enum = 0i64;
    do
    {
      m_data = v38->m_boneFlags.m_data;
      if ( (*((_BYTE *)m_data + v79) & 1) != 0 )
      {
        v82 = v38->m_modelPose.m_data;
        v83 = *(__int16 *)((char *)v38->m_skeleton->m_parentIndices.m_data + v80);
        if ( v83 == -1 )
        {
          v101 = v38->m_localPose.m_data;
          v101[v78].m_translation = v82[v78].m_translation;
          v101[v78].m_rotation = v82[v78].m_rotation;
          v101[v78].m_scale = v82[v78].m_scale;
        }
        else
        {
          if ( (m_data[v83] & 2) != 0 )
            v84 = hkaPose::calculateBoneModelSpace(v38, v83);
          else
            v84 = &v82[v83];
          v85 = v38->m_localPose.m_data;
          hkVector4f::setRotatedInverseDir(&v112, &v84->m_rotation, &v84->m_translation);
          inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
          v112.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), v112.m_quad);
          v87 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), v84->m_rotation.m_vec.m_quad);
          v113 = v87;
          v88 = _mm_rcp_ps(v84->m_scale.m_quad);
          v89 = (__m128)_mm_srli_si128(
                          _mm_slli_si128(
                            (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v88, v84->m_scale.m_quad)), v88),
                            4),
                          4);
          v114 = v89;
          v90 = _mm_shuffle_ps(v87, v87, 255);
          m_quad = v82[v78].m_translation.m_quad;
          v92 = _mm_mul_ps(m_quad, v87);
          v93 = _mm_shuffle_ps(v87, v87, 201);
          v94 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v87), _mm_mul_ps(m_quad, v93));
          v95 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
                        _mm_shuffle_ps(v92, v92, 170)),
                      v87),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v90, v90), (__m128)xmmword_141A711B0), m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v90));
          v85[v78].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v95, v95), v112.m_quad);
          v96 = v82[v78].m_rotation.m_vec.m_quad;
          v97 = _mm_shuffle_ps(v96, v96, 255);
          v98 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v96, v96, 201), v87), _mm_mul_ps(v96, v93));
          v99 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v98, v98, 201), _mm_mul_ps(v96, v90)), _mm_mul_ps(v97, v87));
          v100 = _mm_mul_ps(v96, v87);
          v85[v78].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                               v99,
                                               _mm_unpackhi_ps(
                                                 v99,
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(v97, v90),
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_shuffle_ps(v100, v100, 85),
                                                       _mm_shuffle_ps(v100, v100, 0)),
                                                     _mm_shuffle_ps(v100, v100, 170)))),
                                               196);
          v85[v78].m_scale.m_quad = _mm_mul_ps(v82[v78].m_scale.m_quad, v89);
          v79 = *(_QWORD *)&v108[0].m_enum;
          v39 = v117;
          v80 = *(_QWORD *)&result[0].m_enum;
        }
        *(unsigned int *)((char *)v38->m_boneFlags.m_data + v79) &= ~1u;
      }
      m128_f32 = (_OWORD *)v38->m_localPose.m_data[v8].m_translation.m_quad.m128_f32;
      v103 = *(_QWORD *)(v39 + 56);
      *(_OWORD *)(v78 * 48 + v103) = *m128_f32;
      *(_OWORD *)(v78 * 48 + v103 + 16) = m128_f32[1];
      *(_OWORD *)(v78 * 48 + v103 + 32) = m128_f32[2];
      ++v8;
      v80 += 2i64;
      *(_QWORD *)&result[0].m_enum = v80;
      v79 += 4i64;
      *(_QWORD *)&v108[0].m_enum = v79;
      ++v78;
    }
    while ( v8 < *(_DWORD *)(v39 + 48) );
    v12 = *(hkaPose **)sizeElem;
  }
  if ( v38 )
  {
    hkaPose::~hkaPose(v38);
    v104 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkaPose *, __int64))(*v104[11] + 16i64))(v104[11], v38, 80i64);
  }
  if ( v12 )
  {
    hkaPose::~hkaPose(v12);
    v105 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkaPose *, __int64))(*v105[11] + 16i64))(v105[11], v12, 80i64);
  }
}

// File Line: 1076
// RVA: 0x460010
void __fastcall UFG::RagdollFactory::CreateSkeletonMappings(
        UFG::RagdollFactory *this,
        Skeleton *skeleton,
        UFG::RagdollData *mData)
{
  hkaSkeleton *mhkaSkeleton; // r10
  int m_size; // esi
  int v7; // edi
  __int64 v8; // rbx
  char v9; // dl
  char v10; // cl
  char v11; // al
  char v12; // dl
  char v13; // cl
  _QWORD **Value; // rax
  hkaSkeletonMapper *v15; // rax
  hkaSkeletonMapper *v16; // rax
  _QWORD **v17; // rax
  hkaSkeletonMapper *v18; // rax
  hkaSkeletonMapper *v19; // rax
  char v20; // al
  hkaSkeletonMapperData array; // [rsp+40h] [rbp-98h] BYREF
  _DWORD v22[8]; // [rsp+108h] [rbp+30h] BYREF
  _DWORD v23[30]; // [rsp+128h] [rbp+50h] BYREF
  hkResult result[2]; // [rsp+1A8h] [rbp+D0h] BYREF

  mhkaSkeleton = skeleton->mhkaSkeleton;
  this->mSkeletonMapper->ufgSkeletonB = skeleton;
  this->mSkeletonMapper->ufgSkeletonA = UFG::gpRagDollSkeleton;
  this->mSkeletonMapper->m_skeletonB = mhkaSkeleton;
  this->mSkeletonMapper->m_skeletonA = mData->ragdollSkeleton;
  m_size = UFG::gpRagDollSkeleton->mhkaSkeleton->m_bones.m_size;
  v7 = skeleton->mhkaSkeleton->m_bones.m_size - m_size;
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v9) = 3;
  *(_QWORD *)(v8 + 8i64 * v9 + 16) = "hkaSkeletonMapperData";
  *(_QWORD *)(v8 + 8i64 * v9 + 48) = 0i64;
  v10 = *(_BYTE *)(v8 + 81);
  if ( v9 > v10 )
    v10 = v9;
  *(_BYTE *)(v8 + 81) = v10;
  hkaSkeletonMapperData::hkaSkeletonMapperData((hkaSkeletonMapperData *)&array.m_extractedMotionMapping.m_rotation.m_vec.m_quad.m128_u16[4]);
  if ( (v22[3] & 0x3FFFFFFF) < m_size )
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, v22, m_size, 64);
  if ( (v23[3] & 0x3FFFFFFF) < v7 )
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, v23, v7, 2);
  v23[17] = 0;
  hkaSkeletonMapperData::hkaSkeletonMapperData(&array);
  if ( (HIDWORD(array.m_simpleMappingPartitionRanges.m_data) & 0x3FFFFFFF) < m_size )
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &array.m_partitionMap.m_size, m_size, 64);
  if ( (HIDWORD(array.m_simpleMappings.m_data) & 0x3FFFFFFF) < v7 )
    hkArrayUtil::_reserve(
      result,
      &hkContainerHeapAllocator::s_alloc,
      &array.m_chainMappingPartitionRanges.m_size,
      v7,
      2);
  array.m_extractedMotionMapping.m_translation.m_quad.m128_i32[3] = 0;
  v11 = *(_BYTE *)(v8 + 80);
  if ( v11 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v11 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  UFG::RagdollSkeletonMapper::CreateMapping(
    this->mSkeletonMapper,
    &array,
    (hkaSkeletonMapperData *)&array.m_extractedMotionMapping.m_rotation.m_vec.m_quad.m128_u16[4]);
  v12 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v12) = 3;
  *(_QWORD *)(v8 + 8i64 * v12 + 16) = "hkaSkeletonMapper";
  *(_QWORD *)(v8 + 8i64 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v8 + 81);
  if ( v12 > v13 )
    v13 = v12;
  *(_BYTE *)(v8 + 81) = v13;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkaSkeletonMapper *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 192i64);
  *(_QWORD *)&result[0].m_enum = v15;
  if ( v15 )
    hkaSkeletonMapper::hkaSkeletonMapper(
      v15,
      (hkaSkeletonMapperData *)&array.m_extractedMotionMapping.m_rotation.m_vec.m_quad.m128_u16[4]);
  else
    v16 = 0i64;
  mData->highResToRagdollMapper = v16;
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (hkaSkeletonMapper *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v17[11] + 8i64))(v17[11], 192i64);
  *(_QWORD *)&result[0].m_enum = v18;
  if ( v18 )
    hkaSkeletonMapper::hkaSkeletonMapper(v18, &array);
  else
    v19 = 0i64;
  mData->ragdollToHighResMapper = v19;
  v20 = *(_BYTE *)(v8 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  hkaSkeletonMapperData::~hkaSkeletonMapperData(&array);
  hkaSkeletonMapperData::~hkaSkeletonMapperData((hkaSkeletonMapperData *)&array.m_extractedMotionMapping.m_rotation.m_vec.m_quad.m128_u16[4]);
}

// File Line: 1187
// RVA: 0x47C610
void __fastcall UFG::RagdollFactory::Update(UFG::RagdollFactory *this, float deltaTime)
{
  int v2; // ebx
  int v4; // r8d
  __int64 v5; // rcx
  UFG::RagdollData *v6; // rdx
  __int64 m_size; // rdx
  __int64 v8; // rax
  UFG::RagdollData **i; // rcx
  UFG::RagdollData *v10; // rdi
  hkaSkeletonMapper *highResToRagdollMapper; // rcx
  hkaSkeletonMapper *ragdollToHighResMapper; // rcx
  __int64 v13; // rax

  v2 = 0;
  v4 = 0;
  if ( this->mRagdollData.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = this->mRagdollData.m_data[v5];
      if ( v6->mRefcount )
        v6->m_timeSinceLastUsed = 0.0;
      else
        v6->m_timeSinceLastUsed = deltaTime + v6->m_timeSinceLastUsed;
      ++v4;
      ++v5;
    }
    while ( v4 < this->mRagdollData.m_size );
  }
  m_size = this->mRagdollData.m_size;
  v8 = 0i64;
  if ( m_size > 0 )
  {
    for ( i = this->mRagdollData.m_data; ; ++i )
    {
      v10 = *i;
      if ( (*i)->m_timeSinceLastUsed > 5.0 )
        break;
      ++v8;
      ++v2;
      if ( v8 >= m_size )
        return;
    }
    hkReferencedObject::removeReference(v10->havokInstance);
    highResToRagdollMapper = v10->highResToRagdollMapper;
    if ( highResToRagdollMapper )
      highResToRagdollMapper->vfptr->__vecDelDtor(highResToRagdollMapper, 1u);
    ragdollToHighResMapper = v10->ragdollToHighResMapper;
    if ( ragdollToHighResMapper )
      ragdollToHighResMapper->vfptr->__vecDelDtor(ragdollToHighResMapper, 1u);
    v10->vfptr->__vecDelDtor(v10, 1u);
    v13 = --this->mRagdollData.m_size;
    if ( (_DWORD)v13 != v2 )
      this->mRagdollData.m_data[v2] = this->mRagdollData.m_data[v13];
  }
}

// File Line: 1222
// RVA: 0x458650
UFG::Ragdoll *__fastcall UFG::RagdollFactory::AquireRagdoll(
        UFG::RagdollFactory *this,
        Skeleton *skeleton,
        component_Ragdoll *ragdoll_data,
        unsigned __int16 collisionSystem,
        UFG::RagdollQuality quality)
{
  __int64 v7; // rbp
  int v8; // eax
  int m_size; // r10d
  UFG::RagdollData **m_data; // rbx
  UFG::RagdollData **v11; // rcx
  UFG::RagdollData *RagdollFromSkeleton; // rbx
  hkaRagdollInstance *havokInstance; // r14
  __int64 v14; // rdi
  char v15; // dl
  char v16; // cl
  char v17; // cl
  UFG::allocator::free_link *v18; // rax
  __int64 v19; // rax

  v7 = 0i64;
  if ( this->mDisableCaching )
  {
    RagdollFromSkeleton = UFG::RagdollFactory::CreateRagdollFromSkeleton(this, skeleton, ragdoll_data, quality);
  }
  else
  {
    v8 = 0;
    m_size = this->mRagdollData.m_size;
    if ( m_size <= 0 )
      goto LABEL_9;
    m_data = this->mRagdollData.m_data;
    v11 = m_data;
    while ( (*v11)->rigGuid != skeleton->mNameUID || (*v11)->mQuality != quality )
    {
      ++v8;
      ++v11;
      if ( v8 >= m_size )
        goto LABEL_9;
    }
    RagdollFromSkeleton = m_data[v8];
    if ( !RagdollFromSkeleton )
    {
LABEL_9:
      RagdollFromSkeleton = UFG::RagdollFactory::CreateRagdollFromSkeleton(this, skeleton, ragdoll_data, quality);
      if ( this->mRagdollData.m_size == (this->mRagdollData.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mRagdollData, 8);
      this->mRagdollData.m_data[this->mRagdollData.m_size++] = RagdollFromSkeleton;
    }
  }
  if ( RagdollFromSkeleton->mRefcount )
  {
    v14 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v15 = ++*(_BYTE *)(v14 + 80);
    *(_DWORD *)(v14 + 4i64 * v15) = 3;
    *(_QWORD *)(v14 + 8i64 * v15 + 16) = "hkRagdollInstance::clone";
    *(_QWORD *)(v14 + 8i64 * v15 + 48) = 0i64;
    v16 = *(_BYTE *)(v14 + 81);
    if ( v15 > v16 )
      v16 = v15;
    *(_BYTE *)(v14 + 81) = v16;
    havokInstance = (hkaRagdollInstance *)((__int64 (__fastcall *)(hkaRagdollInstance *, __int64))RagdollFromSkeleton->havokInstance->vfptr[1].__first_virtual_table_function__)(
                                            RagdollFromSkeleton->havokInstance,
                                            1i64);
    v17 = *(_BYTE *)(v14 + 80);
    if ( v17 > 0 )
    {
      *(_BYTE *)(v14 + 80) = v17 - 1;
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
    havokInstance = RagdollFromSkeleton->havokInstance;
  }
  ++RagdollFromSkeleton->mRefcount;
  v18 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x170ui64, "ragdoll", 0i64, 1u);
  if ( v18 )
  {
    UFG::Ragdoll::Ragdoll((UFG::Ragdoll *)v18, RagdollFromSkeleton, havokInstance, collisionSystem);
    v7 = v19;
  }
  *(_BYTE *)(v7 + 352) = !this->mDisableCaching;
  return (UFG::Ragdoll *)v7;
}

// File Line: 1271
// RVA: 0x4729F0
void __fastcall UFG::RagdollFactory::ReleaseRagdoll(UFG::RagdollFactory *this, UFG::Ragdoll *ragdoll)
{
  __int64 m_size; // r11
  int v4; // esi
  int v5; // r10d
  __int64 v6; // r8
  unsigned int mUID; // ebx
  UFG::RagdollData **i; // rdx
  UFG::RagdollData *v9; // rbx
  hkaRagdollInstance *mRagdollInstance; // rbp
  hkaRagdollInstance *havokInstance; // rdi
  __int64 v12; // r14
  hkpEntity *v13; // rbx
  hkpEntity *v14; // rbx
  __int128 v15; // [rsp+20h] [rbp-18h] BYREF

  if ( ragdoll->mWasCreatedFromCache )
  {
    m_size = this->mRagdollData.m_size;
    v4 = 0;
    v5 = 0;
    v6 = 0i64;
    if ( m_size > 0 )
    {
      mUID = ragdoll->mUID;
      for ( i = this->mRagdollData.m_data;
            (*i)->rigGuid != mUID || (*i)->mQuality != ragdoll->mRagdollData.m_pPointer->mQuality;
            ++i )
      {
        ++v6;
        ++v5;
        if ( v6 >= m_size )
          return;
      }
      v9 = this->mRagdollData.m_data[v5];
      --v9->mRefcount;
      mRagdollInstance = ragdoll->mRagdollInstance;
      ((void (__fastcall *)(UFG::Ragdoll *, __int64, __int64))ragdoll->vfptr->__vecDelDtor)(ragdoll, 1i64, v6);
      havokInstance = v9->havokInstance;
      if ( mRagdollInstance == havokInstance )
      {
        v15 = 0i64;
        if ( havokInstance->m_rigidBodies.m_size > 0 )
        {
          v12 = 0i64;
          do
          {
            v13 = havokInstance->m_rigidBodies.m_data[v12];
            hkpEntity::activate(v13);
            v13->m_motion.vfptr[9].__vecDelDtor(&v13->m_motion, (unsigned int)&v15);
            v14 = havokInstance->m_rigidBodies.m_data[v12];
            hkpEntity::activate(v14);
            ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v14->m_motion.vfptr[9].__first_virtual_table_function__)(
              &v14->m_motion,
              &v15);
            ++v4;
            ++v12;
          }
          while ( v4 < havokInstance->m_rigidBodies.m_size );
        }
      }
      else
      {
        hkReferencedObject::removeReference(mRagdollInstance);
      }
    }
  }
  else
  {
    hkReferencedObject::removeReference(ragdoll->mRagdollInstance);
    ragdoll->vfptr->__vecDelDtor(ragdoll, 1i64);
  }
}

