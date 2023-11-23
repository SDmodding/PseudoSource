// File Line: 25
// RVA: 0xDEACA0
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep12<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *this,
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *config,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *provider,
        hkcdStaticMeshTreeBase::BuildMapping *mapping,
        hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *quads,
        hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *roots,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *masterTree)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *v7; // r12
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v10; // r15
  hkResultEnum v11; // eax
  int m_provider_high; // r8d
  int m_enum; // r14d
  hkBitField *p_m_validTriangles; // rdi
  int m_capacityAndFlags; // r8d
  int v16; // r8d
  hkArray<int,hkContainerHeapAllocator> *p_m_vMap; // rsi
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  __int64 m_provider_low; // rdx
  _DWORD *v22; // rdi
  __int64 v23; // rcx
  int v24; // eax
  int v25; // ecx
  int v26; // ebx
  int v27; // ecx
  int v28; // r9d
  __int64 m_size; // r8
  int *v30; // rdi
  __int64 v31; // rcx
  int *v32; // rbx
  int v33; // eax
  int v34; // eax
  int v35; // r9d
  __int64 v36; // rdi
  int v37; // eax
  void *v38; // rdi
  __int64 v39; // rsi
  unsigned int v40; // edi
  __m128 v41; // xmm0
  hkResultEnum v42; // r14d
  int v43; // r12d
  __int64 v44; // r13
  unsigned __int64 m_firstFree; // rdx
  int v46; // ebx
  unsigned __int64 v47; // rdi
  hkGeometryUtils::IVertices v48; // rax
  hkOstream *v49; // rax
  hkOstream *v50; // rax
  int v51; // edi
  int v52; // ecx
  float *v53; // r8
  int v54; // eax
  int v55; // eax
  int v56; // eax
  int v57; // r9d
  int v58; // eax
  float *m_data; // rdi
  __int64 i; // rcx
  int v61; // edi
  hkResultEnum v62; // r12d
  __int64 v63; // r13
  unsigned __int64 v64; // rcx
  int v65; // edx
  int v66; // edi
  int v67; // r9d
  int v68; // r8d
  int v69; // eax
  int v70; // eax
  _DWORD *v71; // r11
  int v72; // edi
  int v73; // eax
  int v74; // r11d
  int *v75; // r9
  int v76; // eax
  int v77; // edi
  int v78; // r9d
  int *v79; // r8
  int v80; // r9d
  int v81; // eax
  int v82; // eax
  hkResultEnum v83; // ebx
  __int64 v84; // r12
  __int64 v85; // r14
  __int64 v86; // rdi
  hkBaseObjectVtbl *vfptr; // rsi
  __int64 *v88; // rax
  int v89; // r9d
  __int64 v90; // rcx
  __int64 v91; // rcx
  unsigned __int64 v92; // rdx
  hkResultEnum v93; // edi
  int v94; // ecx
  __int64 v95; // rdx
  __int64 v96; // r12
  hkBaseObjectVtbl *v97; // rbx
  int v98; // ecx
  int v99; // eax
  int v100; // eax
  int v101; // ecx
  _QWORD **v102; // rdi
  unsigned int v103; // esi
  unsigned __int64 v104; // rdx
  hkBaseObjectVtbl *v105; // r9
  unsigned int v106; // r8d
  unsigned int v107; // edi
  __int64 v108; // r8
  __int64 v109; // rdi
  int v110; // r10d
  unsigned int v111; // r11d
  unsigned int v112; // edi
  __int64 v113; // rax
  int v114; // r8d
  int v115; // edx
  bool v116; // zf
  __m128 v117; // xmm1
  __m128 v118; // xmm3
  __m128 v119; // xmm4
  __m128 v120; // xmm4
  int v121; // ecx
  int v122; // ebx
  unsigned __int64 v123; // rdi
  hkGeometryUtils::IVertices v124; // rax
  unsigned __int64 v125; // rdi
  hkGeometryUtils::IVertices v126; // rax
  __m128 v127; // xmm5
  __m128 v128; // xmm4
  __m128 v129; // xmm2
  __m128 v130; // xmm3
  __m128 v131; // xmm0
  __m128 v132; // xmm1
  int v133; // eax
  float v134; // xmm7_4
  __m128 v135; // xmm0
  __m128 v136; // xmm1
  __m128 v137; // xmm5
  float v138; // xmm8_4
  __m128 v139; // xmm1
  float v140; // xmm6_4
  __int64 v141; // rcx
  unsigned int *v142; // rsi
  __int64 v143; // r14
  __int64 v144; // rax
  unsigned int v145; // r9d
  int v146; // edi
  unsigned __int64 v147; // rdx
  __int64 v148; // rax
  unsigned int v149; // edi
  unsigned __int64 v150; // rdx
  unsigned int v151; // ebx
  unsigned __int64 v152; // rdx
  unsigned int v153; // edi
  unsigned __int64 v154; // rdx
  int v155; // r8d
  int v156; // edi
  __int64 v157; // r12
  int v158; // r15d
  unsigned int *v159; // r11
  unsigned int v160; // ebx
  unsigned __int64 v161; // r10
  int v162; // r9d
  hkResultEnum v163; // eax
  _QWORD *v164; // rdi
  int v165; // eax
  int v166; // eax
  int v167; // r9d
  hkLifoAllocator *Value; // rcx
  _QWORD *m_cur; // rax
  _QWORD *v170; // rdx
  __int64 v171; // rcx
  __m128 v172; // xmm11
  __int64 v173; // r14
  __m128 v174; // xmm12
  __m128 v175; // xmm7
  __m128 v176; // xmm6
  int v177; // r12d
  unsigned int *v178; // rdi
  __int64 v179; // rdx
  unsigned int v180; // ebx
  unsigned __int64 v181; // rdx
  unsigned int v182; // ebx
  unsigned __int64 v183; // rdx
  unsigned int v184; // ebx
  unsigned __int64 v185; // rdx
  unsigned int v186; // ebx
  unsigned __int64 v187; // rdx
  __m128 v188; // xmm7
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v189; // rbx
  __m128 v190; // xmm6
  unsigned __int64 v191; // r12
  hkcdDynamicTree::CodecRawUlong *v192; // rcx
  unsigned __int64 v193; // rsi
  hkcdDynamicTree::CodecRawUlong *v194; // rax
  __int64 v195; // rdi
  __m128 m_quad; // xmm9
  __m128 v197; // xmm10
  unsigned __int64 v198; // r8
  __int64 v199; // rax
  __m128 *p_m_quad; // rdi
  __m128 *v201; // r8
  __m128 v202; // xmm7
  __m128 v203; // xmm8
  __int64 v204; // rdx
  __int64 v205; // rcx
  __m128 v206; // xmm1
  __m128 v207; // xmm3
  __m128 v208; // xmm6
  __m128 v209; // xmm2
  __m128 v210; // xmm5
  __m128 v211; // xmm3
  __m128 v212; // xmm3
  __m128 v213; // xmm6
  __m128 v214; // xmm6
  unsigned __int64 v215; // r11
  __int64 v216; // r9
  __int64 v217; // rax
  __m128 v218; // xmm1
  int v219; // edi
  hkResultEnum v220; // r8d
  hkResultEnum v221; // r14d
  __int64 v222; // r12
  unsigned __int64 v223; // rdi
  hkGeometryUtils::IVertices v224; // rax
  __m128 v225; // xmm6
  __m128 v226; // xmm7
  __int64 v227; // rcx
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v228; // rbx
  unsigned __int64 v229; // r13
  hkcdDynamicTree::CodecRawUlong *v230; // rcx
  unsigned __int64 v231; // rsi
  hkcdDynamicTree::CodecRawUlong *v232; // rax
  __int64 v233; // rdi
  __m128 v234; // xmm9
  __m128 v235; // xmm10
  unsigned __int64 v236; // r8
  __int64 v237; // rax
  __m128 *v238; // rdi
  __m128 *v239; // r8
  __m128 v240; // xmm7
  __m128 v241; // xmm8
  __int64 v242; // rdx
  __int64 v243; // rcx
  __m128 v244; // xmm1
  __m128 v245; // xmm3
  __m128 v246; // xmm6
  __m128 v247; // xmm2
  __m128 v248; // xmm5
  __m128 v249; // xmm3
  __m128 v250; // xmm3
  __m128 v251; // xmm6
  __m128 v252; // xmm6
  unsigned __int64 v253; // r11
  __int64 v254; // r9
  __int64 v255; // rax
  __m128 v256; // xmm1
  __int32 v257; // edi
  int v258; // r12d
  __int64 v259; // r14
  int v260; // eax
  __m128 v261; // xmm12
  hkpBvCompressedMeshShape_Internals::GeometryProvider *v262; // rcx
  hkVector4f v263; // xmm6
  hkVector4f v264; // xmm7
  int v265; // r8d
  __m128 *v266; // rcx
  __int64 m_numVertices; // rax
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v268; // rbx
  unsigned __int64 v269; // r13
  hkcdDynamicTree::CodecRawUlong *v270; // rdx
  unsigned __int64 v271; // rsi
  hkcdDynamicTree::CodecRawUlong *v272; // rax
  __int64 v273; // rdi
  __m128 v274; // xmm9
  __m128 v275; // xmm10
  unsigned __int64 v276; // r8
  __int64 v277; // rax
  __m128 *v278; // rdi
  __m128 *v279; // r8
  __m128 v280; // xmm7
  __m128 v281; // xmm8
  __int64 v282; // rdx
  __int64 v283; // rcx
  __m128 v284; // xmm1
  __m128 v285; // xmm3
  __m128 v286; // xmm6
  __m128 v287; // xmm2
  __m128 v288; // xmm5
  __m128 v289; // xmm3
  __m128 v290; // xmm3
  __m128 v291; // xmm6
  __m128 v292; // xmm6
  unsigned __int64 v293; // r11
  __int64 v294; // r9
  __int64 v295; // rax
  __m128 v296; // xmm1
  __int64 v297; // rdi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v298; // r14
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v299; // rcx
  unsigned __int64 m_root; // r10
  int v301; // esi
  hkcdDynamicTree::CodecRawUlong *v302; // rdx
  int v303; // r11d
  unsigned __int64 v304; // r8
  unsigned __int64 m_parent; // rax
  unsigned __int64 v306; // rcx
  unsigned __int64 v307; // r8
  unsigned __int64 v308; // r9
  unsigned __int64 v309; // rax
  int j; // ecx
  int v311; // ecx
  unsigned __int64 v312; // rcx
  unsigned __int64 k; // rdi
  unsigned __int64 v314; // r11
  int v315; // r10d
  hkcdDynamicTree::CodecRawUlong *v316; // rdx
  int v317; // ebx
  unsigned __int64 v318; // r8
  unsigned __int64 v319; // rax
  unsigned __int64 v320; // rcx
  unsigned __int64 v321; // r8
  unsigned __int64 v322; // r9
  unsigned __int64 v323; // rax
  int m; // ecx
  int v325; // ecx
  unsigned __int64 v326; // rcx
  unsigned __int64 n; // rdi
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v328; // r11
  __int64 v329; // rbx
  int v330; // r10d
  hkcdDynamicTree::CodecRawUlong *v331; // rdx
  unsigned __int64 v332; // r8
  unsigned __int64 v333; // r9
  int v334; // ecx
  unsigned __int64 v335; // rcx
  unsigned __int64 ii; // rdi
  _QWORD *v337; // rdx
  __int64 v338; // rax
  __int64 v339; // rcx
  _OWORD *m128_f32; // rax
  __int128 v341; // xmm1
  __m128 v342; // xmm0
  unsigned __int8 v343; // si
  __int128 *v344; // rcx
  int v345; // eax
  char *v346; // rbx
  signed int v347; // edi
  hkLifoAllocator *v348; // rax
  int v349; // r8d
  hkResult result; // [rsp+30h] [rbp-B0h] BYREF
  int v352; // [rsp+34h] [rbp-ACh] BYREF
  int v353; // [rsp+38h] [rbp-A8h]
  unsigned __int64 v354; // [rsp+40h] [rbp-A0h] BYREF
  __int64 v355; // [rsp+48h] [rbp-98h]
  __int64 v356; // [rsp+50h] [rbp-90h]
  hkOstream tolerance; // [rsp+60h] [rbp-80h] BYREF
  int v358; // [rsp+78h] [rbp-68h]
  int v359; // [rsp+80h] [rbp-60h] BYREF
  int v360; // [rsp+84h] [rbp-5Ch]
  int v361; // [rsp+88h] [rbp-58h]
  __m128 v362; // [rsp+90h] [rbp-50h] BYREF
  __int64 v363; // [rsp+A0h] [rbp-40h] BYREF
  __int64 v364; // [rsp+A8h] [rbp-38h]
  int v365; // [rsp+B0h] [rbp-30h]
  __int64 v366; // [rsp+B8h] [rbp-28h] BYREF
  int v367; // [rsp+C0h] [rbp-20h]
  unsigned int v368; // [rsp+C8h] [rbp-18h]
  unsigned int v369; // [rsp+CCh] [rbp-14h]
  unsigned int v370; // [rsp+D0h] [rbp-10h]
  int v371; // [rsp+D8h] [rbp-8h] BYREF
  int v372; // [rsp+DCh] [rbp-4h]
  int v373; // [rsp+E0h] [rbp+0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v374; // [rsp+E8h] [rbp+8h] BYREF
  _QWORD *v375; // [rsp+F8h] [rbp+18h]
  int v376; // [rsp+100h] [rbp+20h]
  int v377; // [rsp+104h] [rbp+24h]
  void *p; // [rsp+108h] [rbp+28h]
  int v379; // [rsp+110h] [rbp+30h]
  unsigned int v380; // [rsp+118h] [rbp+38h]
  void *array; // [rsp+120h] [rbp+40h]
  hkaMatrix<float> v382; // [rsp+128h] [rbp+48h] BYREF
  hkcdStaticMeshTreeBase::BuildCustomInfos customPrimitive; // [rsp+140h] [rbp+60h] BYREF
  int v384; // [rsp+180h] [rbp+A0h]
  hkBaseObjectVtbl *v385; // [rsp+188h] [rbp+A8h]
  __int64 v386; // [rsp+190h] [rbp+B0h]
  __int64 v387; // [rsp+198h] [rbp+B8h]
  __int64 v388; // [rsp+1A0h] [rbp+C0h]
  __int64 v389; // [rsp+1A8h] [rbp+C8h]
  hkVector4f a; // [rsp+1B0h] [rbp+D0h] BYREF
  hkVector4f b; // [rsp+1C0h] [rbp+E0h] BYREF
  hkVector4f c; // [rsp+1D0h] [rbp+F0h] BYREF
  __m128 v393; // [rsp+1E0h] [rbp+100h] BYREF
  __m128 v394; // [rsp+1F0h] [rbp+110h] BYREF
  __m128 v395; // [rsp+200h] [rbp+120h] BYREF
  char buf[544]; // [rsp+210h] [rbp+130h] BYREF
  __int64 v397; // [rsp+4D0h] [rbp+3F0h]
  hkResult v398[2]; // [rsp+4D8h] [rbp+3F8h] BYREF
  hkResult vars0; // [rsp+4E0h] [rbp+400h] BYREF
  hkcdStaticMeshTreeBase::BuildMapping *retaddr; // [rsp+4E8h] [rbp+408h] BYREF

  v7 = this;
  v10 = config;
  v11 = (*(unsigned int (__fastcall **)(_QWORD))(**(_QWORD **)(*(_QWORD *)&config->m_nodes.m_size + 8i64) + 16i64))(*(_QWORD *)(*(_QWORD *)&config->m_nodes.m_size + 8i64));
  m_provider_high = HIDWORD(provider->m_provider);
  m_enum = v11;
  vars0.m_enum = v11;
  LODWORD(provider->m_provider) = 0;
  if ( m_provider_high >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      provider->vfptr,
      4 * m_provider_high);
  p_m_validTriangles = &provider->m_validTriangles;
  provider->vfptr = 0i64;
  HIDWORD(provider->m_provider) = 0x80000000;
  m_capacityAndFlags = provider->m_validTriangles.m_storage.m_words.m_capacityAndFlags;
  array = &provider->m_validTriangles;
  provider->m_validTriangles.m_storage.m_words.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_m_validTriangles->m_storage.m_words.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  p_m_validTriangles->m_storage.m_words.m_data = 0i64;
  provider->m_validTriangles.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  v16 = provider->m_vMap.m_capacityAndFlags;
  p_m_vMap = &provider->m_vMap;
  provider->m_vMap.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, p_m_vMap->m_data, 4 * v16);
  p_m_vMap->m_data = 0i64;
  provider->m_vMap.m_capacityAndFlags = 0x80000000;
  v18 = HIDWORD(provider->m_provider) & 0x3FFFFFFF;
  if ( v18 < m_enum )
  {
    v19 = 2 * v18;
    v20 = m_enum;
    if ( m_enum < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&provider->vfptr, v20, 4);
  }
  m_provider_low = SLODWORD(provider->m_provider);
  v22 = (_DWORD *)provider->vfptr + m_provider_low;
  v23 = m_enum - (int)m_provider_low;
  if ( v23 > 0 )
  {
    while ( v23 )
    {
      *v22++ = -1;
      --v23;
    }
  }
  LODWORD(provider->m_provider) = m_enum;
  v24 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64) + 64i64))(*(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64));
  v25 = provider->m_vMap.m_capacityAndFlags & 0x3FFFFFFF;
  v26 = v24;
  if ( v25 < v24 )
  {
    v27 = 2 * v25;
    v28 = v24;
    if ( v24 < v27 )
      v28 = v27;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_vMap->m_data, v28, 4);
  }
  m_size = p_m_vMap->m_size;
  v30 = &p_m_vMap->m_data[m_size];
  v31 = v26 - (int)m_size;
  if ( v31 > 0 )
  {
    while ( v31 )
    {
      *v30++ = -1;
      --v31;
    }
  }
  p_m_vMap->m_size = v26;
  v32 = (int *)array;
  v33 = *((_DWORD *)array + 3) & 0x3FFFFFFF;
  if ( v33 < m_enum )
  {
    v34 = 2 * v33;
    v35 = m_enum;
    if ( m_enum < v34 )
      v35 = v34;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)array, v35, 1);
  }
  v36 = v32[2];
  v37 = m_enum - v36;
  v38 = (void *)(*(_QWORD *)v32 + v36);
  if ( v37 > 0 )
    memset(v38, 0, v37);
  v32[2] = m_enum;
  if ( v7[24] )
    hkGeometryUtils::weldVerticesVirtual(
      (hkGeometryUtils::IVertices *)v10,
      (hkArray<int,hkContainerHeapAllocator> *)&v10->m_firstFree,
      *(float *)&v7[28]);
  v39 = 0i64;
  v40 = 0;
  v352 = 0;
  if ( *(float *)&v7[36] >= 0.0 )
  {
    v41 = (__m128)*(unsigned int *)&v7[36];
    v42 = HK_SUCCESS;
    v43 = 1;
    tolerance.hkReferencedObject = (hkReferencedObject)_mm_shuffle_ps(v41, v41, 0);
    if ( vars0.m_enum > HK_SUCCESS )
    {
      v44 = 0i64;
      do
      {
        if ( ((*(_DWORD *)(*(_QWORD *)&v10[1].m_nodes.m_size + 4 * (v44 >> 5)) >> (v42 & 0x1F)) & 1) != 0 )
        {
          (*(void (__fastcall **)(_QWORD, _QWORD, unsigned __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size
                                                                                   + 8i64)
                                                                     + 32i64))(
            *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
            (unsigned int)v42,
            &v354);
          m_firstFree = v10->m_firstFree;
          v46 = 1;
          LODWORD(v354) = *(_DWORD *)(m_firstFree + 4i64 * (int)v354);
          HIDWORD(v354) = *(_DWORD *)(m_firstFree + 4i64 * SHIDWORD(v354));
          LODWORD(v355) = *(_DWORD *)(m_firstFree + 4i64 * (int)v355);
          if ( (_DWORD)v355 == HIDWORD(v354) )
            v46 = 3;
          (*(void (__fastcall **)(_QWORD, _QWORD, __m128 *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64)
                                                           + 32i64))(
            *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
            (unsigned int)v42,
            &v362);
          v47 = v10->m_firstFree;
          v362.m128_i32[0] = *(_DWORD *)(v47 + 4i64 * v362.m128_i32[0]);
          v362.m128_i32[1] = *(_DWORD *)(v47 + 4i64 * v362.m128_i32[1]);
          v48.vfptr = (hkGeometryUtils::IVerticesVtbl *)v10->m_nodes.m_data;
          v362.m128_i32[2] = *(_DWORD *)(v47 + 4i64 * v362.m128_i32[2]);
          v48.vfptr->getVertex((hkGeometryUtils::IVertices *)v10, v362.m128_u32[0], &a);
          ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, hkVector4f *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
            v10,
            v362.m128_u32[1],
            &b);
          ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, hkVector4f *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
            v10,
            v362.m128_u32[2],
            &c);
          if ( v46 == 1 && !hkcdTriangleUtil::isDegenerate(&a, &b, &c, (hkSimdFloat32 *)&tolerance) )
          {
            v40 = v352;
          }
          else
          {
            v40 = v352 + 1;
            *(_DWORD *)(*(_QWORD *)&v10[1].m_nodes.m_size + 4 * (v44 >> 5)) &= ~v43;
            v352 = v40;
          }
        }
        v43 = __ROL4__(v43, 1);
        ++v42;
        ++v44;
      }
      while ( v42 < vars0.m_enum );
      mapping = retaddr;
      v39 = 0i64;
    }
    v7 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *)v397;
    m_enum = vars0.m_enum;
  }
  if ( (*(_BYTE *)&v7[20] & 1) != 0 && v40 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&tolerance, buf, 512);
    v49 = hkOstream::operator<<(&tolerance, "Found ");
    v50 = hkOstream::operator<<(v49, v40);
    hkOstream::operator<<(v50, " degenerated triangles in the input geometry, removing them.");
    hkError::messageReport(0, buf, 0i64, 0);
    hkOstream::~hkOstream(&tolerance);
  }
  v382.m_data.m_data = 0i64;
  v382.m_data.m_size = 0;
  v51 = (m_enum + 31) >> 5;
  v382.m_data.m_capacityAndFlags = 0x80000000;
  v52 = v51;
  if ( v51 )
  {
    v352 = 4 * v51;
    v53 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v352);
    v52 = v352 / 4;
  }
  else
  {
    v53 = 0i64;
  }
  v54 = 0x80000000;
  v382.m_data.m_data = v53;
  if ( v52 )
    v54 = v52;
  v382.m_data.m_size = (m_enum + 31) >> 5;
  v382.m_m = m_enum;
  v382.m_data.m_capacityAndFlags = v54;
  v55 = v54 & 0x3FFFFFFF;
  if ( v55 < v51 )
  {
    v56 = 2 * v55;
    v57 = (m_enum + 31) >> 5;
    if ( v51 < v56 )
      v57 = v56;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v382.m_data.m_data, v57, 4);
  }
  v58 = v51 - 1;
  v382.m_data.m_size = (m_enum + 31) >> 5;
  if ( v51 - 1 >= 0 )
  {
    m_data = v382.m_data.m_data;
    for ( i = (unsigned int)(v58 + 1); i; --i )
      *m_data++ = 0.0;
  }
  tolerance.vfptr = 0i64;
  v61 = 0;
  *(_QWORD *)&tolerance.m_memSizeAndFlags = 0x8000000000000000ui64;
  if ( 3 * m_enum > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&tolerance.vfptr, 3 * m_enum, 12);
    v61 = *(_DWORD *)&tolerance.m_memSizeAndFlags;
  }
  v62 = HK_SUCCESS;
  if ( m_enum > 0 )
  {
    v63 = 0i64;
    do
    {
      if ( ((*(_DWORD *)(*(_QWORD *)&v10[1].m_nodes.m_size + 4 * (v63 >> 5)) >> (v62 & 0x1F)) & 1) != 0 )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64) + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
          (unsigned int)v62,
          &v366);
        v64 = v10->m_firstFree;
        v65 = *(_DWORD *)(v64 + 4i64 * (int)v366);
        v66 = *(_DWORD *)&tolerance.m_memSizeAndFlags;
        LODWORD(v366) = v65;
        HIDWORD(v366) = *(_DWORD *)(v64 + 4i64 * SHIDWORD(v366));
        v67 = HIDWORD(v366);
        v68 = *(_DWORD *)(v64 + 4i64 * v367);
        v69 = HIDWORD(v366);
        if ( v65 < SHIDWORD(v366) )
          v69 = v65;
        v367 = *(_DWORD *)(v64 + 4i64 * v367);
        v353 = v69;
        v70 = HIDWORD(v366);
        if ( v65 > SHIDWORD(v366) )
          v70 = v65;
        v365 = v70;
        v71 = (_DWORD *)tolerance.vfptr + 3 * *(int *)&tolerance.m_memSizeAndFlags;
        if ( v71 )
        {
          *v71 = v353;
          v71[1] = v365;
          v71[2] = v62 & 0x3FFFFFFF;
          v66 = *(_DWORD *)&tolerance.m_memSizeAndFlags;
          v68 = v367;
          v67 = HIDWORD(v366);
          v65 = v366;
        }
        v72 = v66 + 1;
        v73 = v68;
        if ( v67 > v68 )
          v73 = v67;
        v74 = v68;
        *(_DWORD *)&tolerance.m_memSizeAndFlags = v72;
        if ( v67 < v68 )
          v74 = v67;
        v353 = v73;
        v75 = (int *)tolerance.vfptr + 3 * v72;
        if ( v75 )
        {
          v76 = v353;
          *v75 = v74;
          v75[1] = v76;
          v75[2] = v62 & 0x3FFFFFFF | 0x40000000;
          v72 = *(_DWORD *)&tolerance.m_memSizeAndFlags;
          v68 = v367;
          v65 = v366;
        }
        v77 = v72 + 1;
        v78 = v65;
        if ( v68 < v65 )
          v78 = v68;
        if ( v68 > v65 )
          v65 = v68;
        *(_DWORD *)&tolerance.m_memSizeAndFlags = v77;
        v79 = (int *)tolerance.vfptr + 3 * v77;
        if ( v79 )
        {
          *v79 = v78;
          v79[1] = v65;
          v79[2] = v62 & 0x3FFFFFFF | 0x80000000;
          v77 = *(_DWORD *)&tolerance.m_memSizeAndFlags;
        }
        v61 = v77 + 1;
        *(_DWORD *)&tolerance.m_memSizeAndFlags = v61;
      }
      ++v62;
      ++v63;
    }
    while ( v62 < vars0.m_enum );
    mapping = retaddr;
    m_enum = vars0.m_enum;
    v39 = 0i64;
  }
  if ( v61 > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::HalfEdge,hkAlgorithm::less<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::HalfEdge>>(
      (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::HalfEdge *)tolerance.vfptr,
      0,
      v61 - 1,
      0);
    v61 = *(_DWORD *)&tolerance.m_memSizeAndFlags;
  }
  v80 = m_enum + 1;
  v81 = mapping->m_triangleIndexToKey.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v81 < m_enum + 1 )
  {
    v82 = 2 * v81;
    if ( v80 < v82 )
      v80 = v82;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&mapping->m_triangleIndexToKey.m_data,
      v80,
      12);
    v61 = *(_DWORD *)&tolerance.m_memSizeAndFlags;
  }
  v83 = HK_SUCCESS;
  v84 = v61 - 1;
  v388 = v84;
  v352 = 0;
  if ( v61 - 1 > 0 )
  {
    v387 = 1i64;
    v85 = 0i64;
    v386 = 0i64;
    v366 = v61 - 1;
    while ( 1 )
    {
      v86 = *(_QWORD *)&v10->m_nodes.m_size;
      vfptr = tolerance.vfptr;
      v88 = *(__int64 **)v86;
      v89 = *(_DWORD *)((char *)&tolerance.vfptr->__first_virtual_table_function__ + v85);
      v385 = tolerance.vfptr;
      v90 = *v88;
      v370 = v89 & 0x3FFFFFFF;
      LODWORD(v88) = *(_DWORD *)(v90 + 4i64 * (v89 & 0x3FFFFFFF));
      v91 = *(_QWORD *)(v86 + 8);
      v384 = (int)v88;
      (*(void (__fastcall **)(__int64, _QWORD, __m128 *))(*(_QWORD *)v91 + 32i64))(v91, v89 & 0x3FFFFFFF, &v362);
      v92 = v10->m_firstFree;
      v93 = v83 + 1;
      v362.m128_i32[0] = *(_DWORD *)(v92 + 4i64 * v362.m128_i32[0]);
      v362.m128_i32[1] = *(_DWORD *)(v92 + 4i64 * v362.m128_i32[1]);
      v94 = *(_DWORD *)(v92 + 4i64 * v362.m128_i32[2]);
      v95 = v387;
      v362.m128_i32[2] = v94;
      result.m_enum = v83 + 1;
      LODWORD(retaddr) = v83 + 1;
      v389 = v387;
      if ( v387 >= v84 )
        goto LABEL_122;
      v96 = v85 + 12;
      do
      {
        v97 = tolerance.vfptr;
        v98 = *(_DWORD *)((char *)&vfptr->__vecDelDtor + v85);
        v99 = *(_DWORD *)((char *)&tolerance.vfptr->__vecDelDtor + v96);
        if ( v98 < v99 )
          break;
        if ( v98 > v99 )
          break;
        v100 = *(_DWORD *)((char *)&vfptr->__vecDelDtor + v85 + 4);
        v101 = *(_DWORD *)((char *)&tolerance.vfptr->__vecDelDtor + v96 + 4);
        if ( v100 < v101 || v100 > v101 )
          break;
        v102 = *(_QWORD ***)&v10->m_nodes.m_size;
        v103 = *(_DWORD *)((_BYTE *)&tolerance.vfptr->__first_virtual_table_function__ + v96) & 0x3FFFFFFF;
        if ( v384 != *(_DWORD *)(**v102 + 4i64 * (int)v103) )
          goto LABEL_120;
        (*(void (__fastcall **)(_QWORD *, _QWORD, int *))(*v102[1] + 32i64))(v102[1], v103, &v371);
        v104 = v10->m_firstFree;
        v105 = v385;
        v106 = *(_DWORD *)((char *)&v385->__first_virtual_table_function__ + v85);
        v107 = *(_DWORD *)((char *)&v97->__first_virtual_table_function__ + v96);
        v371 = *(_DWORD *)(v104 + 4i64 * v371);
        v108 = v106 >> 30;
        v372 = *(_DWORD *)(v104 + 4i64 * v372);
        v109 = v107 >> 30;
        v373 = *(_DWORD *)(v104 + 4i64 * v373);
        v110 = v362.m128_i32[((int)v108 + 2) % 3];
        v380 = v362.m128_u32[v108];
        v368 = v110;
        v111 = *(&v371 + ((int)v109 + 2) % 3);
        v353 = *(&v371 + v109);
        v369 = v111;
        if ( v380 != *(&v371 + ((int)v109 + 1) % 3) )
          goto LABEL_120;
        v112 = v353;
        if ( v353 != v362.m128_i32[((int)v108 + 1) % 3] || v110 == v111 )
          goto LABEL_120;
        v113 = v397;
        v114 = v352;
        v115 = (int)retaddr;
        v116 = *(_BYTE *)(v397 + 2) == 0;
        v365 = v352;
        v353 = (int)retaddr;
        if ( !v116 )
        {
          ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, hkcdStaticMeshTreeBase::BuildCustomInfos *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
            v10,
            v380,
            &customPrimitive);
          ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, hkVector4f *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
            v10,
            v112,
            &customPrimitive.m_aabb.m_max);
          ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, int *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
            v10,
            v368,
            &customPrimitive.m_numVertices);
          ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, unsigned __int16 *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
            v10,
            v369,
            &customPrimitive.m_tags.m_data[2]);
          v117 = _mm_sub_ps(*(__m128 *)&customPrimitive.m_numVertices, customPrimitive.m_aabb.m_min.m_quad);
          v118 = _mm_sub_ps(customPrimitive.m_aabb.m_max.m_quad, customPrimitive.m_aabb.m_min.m_quad);
          v119 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v117, v117, 201), v118),
                   _mm_mul_ps(_mm_shuffle_ps(v118, v118, 201), v117));
          v120 = _mm_mul_ps(
                   _mm_shuffle_ps(v119, v119, 201),
                   _mm_sub_ps(*(__m128 *)&customPrimitive.m_tags.m_data[2], customPrimitive.m_aabb.m_min.m_quad));
          if ( (float)((float)(_mm_shuffle_ps(v120, v120, 85).m128_f32[0] + _mm_shuffle_ps(v120, v120, 0).m128_f32[0])
                     + _mm_shuffle_ps(v120, v120, 170).m128_f32[0]) <= (float)(0.0 - 0.00000011920929) )
            goto LABEL_120;
          v115 = (int)retaddr;
          v105 = v385;
          v114 = v352;
          v113 = v397;
        }
        if ( *(_BYTE *)(v113 + 3)
          && ((v121 = *(_DWORD *)((char *)&v105->__first_virtual_table_function__ + v85) >> 30, v121 != 2)
           || (*(_DWORD *)((_BYTE *)&v97->__first_virtual_table_function__ + v96) & 0xC0000000) != 0) )
        {
          if ( (*(_DWORD *)((_BYTE *)&v97->__first_virtual_table_function__ + v96) & 0xC0000000) != 0x80000000 || v121 )
            goto LABEL_120;
          v122 = v115;
          v353 = v114;
        }
        else
        {
          v122 = v365;
        }
        (*(void (__fastcall **)(_QWORD, _QWORD, hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64) + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
          v370,
          &v374);
        v123 = v10->m_firstFree;
        LODWORD(v374.m_elem) = *(_DWORD *)(v123 + 4i64 * SLODWORD(v374.m_elem));
        HIDWORD(v374.m_elem) = *(_DWORD *)(v123 + 4i64 * SHIDWORD(v374.m_elem));
        v124.vfptr = (hkGeometryUtils::IVerticesVtbl *)v10->m_nodes.m_data;
        v374.m_numElems = *(_DWORD *)(v123 + 4i64 * v374.m_numElems);
        v124.vfptr->getVertex((hkGeometryUtils::IVertices *)v10, (int)v374.m_elem, (hkVector4f *)&v393);
        ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, __m128 *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
          v10,
          HIDWORD(v374.m_elem),
          &v394);
        ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, __m128 *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
          v10,
          (unsigned int)v374.m_numElems,
          &v395);
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64) + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
          v103,
          &v363);
        v125 = v10->m_firstFree;
        LODWORD(v363) = *(_DWORD *)(v125 + 4i64 * (int)v363);
        HIDWORD(v363) = *(_DWORD *)(v125 + 4i64 * SHIDWORD(v363));
        v126.vfptr = (hkGeometryUtils::IVerticesVtbl *)v10->m_nodes.m_data;
        LODWORD(v364) = *(_DWORD *)(v125 + 4i64 * (int)v364);
        v126.vfptr->getVertex((hkGeometryUtils::IVertices *)v10, v363, &customPrimitive.m_aabb.m_min);
        ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, hkVector4f *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
          v10,
          HIDWORD(v363),
          &customPrimitive.m_aabb.m_max);
        ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, int *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
          v10,
          (unsigned int)v364,
          &customPrimitive.m_numVertices);
        v127 = _mm_max_ps(_mm_max_ps(v393, v394), v395);
        v128 = _mm_min_ps(_mm_min_ps(v393, v394), v395);
        v129 = _mm_min_ps(
                 _mm_min_ps(customPrimitive.m_aabb.m_min.m_quad, customPrimitive.m_aabb.m_max.m_quad),
                 *(__m128 *)&customPrimitive.m_numVertices);
        v130 = _mm_max_ps(
                 _mm_max_ps(customPrimitive.m_aabb.m_min.m_quad, customPrimitive.m_aabb.m_max.m_quad),
                 *(__m128 *)&customPrimitive.m_numVertices);
        v131 = _mm_sub_ps(v127, v128);
        v132 = _mm_mul_ps(_mm_shuffle_ps(v131, v131, 201), v131);
        v133 = mapping->m_triangleIndexToKey.m_capacityAndFlags;
        a.m_quad = v128;
        v134 = (float)(_mm_shuffle_ps(v132, v132, 85).m128_f32[0] + _mm_shuffle_ps(v132, v132, 0).m128_f32[0])
             + _mm_shuffle_ps(v132, v132, 170).m128_f32[0];
        v135 = _mm_sub_ps(v130, v129);
        v136 = _mm_mul_ps(_mm_shuffle_ps(v135, v135, 201), v135);
        v137 = _mm_sub_ps(_mm_max_ps(v127, v130), _mm_min_ps(v128, v129));
        v138 = (float)(_mm_shuffle_ps(v136, v136, 85).m128_f32[0] + _mm_shuffle_ps(v136, v136, 0).m128_f32[0])
             + _mm_shuffle_ps(v136, v136, 170).m128_f32[0];
        v139 = _mm_mul_ps(_mm_shuffle_ps(v137, v137, 201), v137);
        v140 = (float)(_mm_shuffle_ps(v139, v139, 85).m128_f32[0] + _mm_shuffle_ps(v139, v139, 0).m128_f32[0])
             + _mm_shuffle_ps(v139, v139, 170).m128_f32[0];
        if ( mapping->m_triangleIndexToKey.m_size == (v133 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&mapping->m_triangleIndexToKey.m_data,
            12);
        v141 = mapping->m_triangleIndexToKey.m_size;
        v142 = mapping->m_triangleIndexToKey.m_data;
        v143 = 3 * v141;
        mapping->m_triangleIndexToKey.m_size = v141 + 1;
        v144 = v353;
        v142[v143] = *((_DWORD *)&tolerance.vfptr->__first_virtual_table_function__ + 3 * v122);
        v145 = *((_DWORD *)&tolerance.vfptr->__first_virtual_table_function__ + 3 * v144);
        v142[v143 + 1] = v145;
        *(float *)&v142[v143 + 2] = (float)(v140 - v138) + (float)(v140 - v134);
        v146 = (int)((v145 >> 30) + 2) % 3;
        (*(void (__fastcall **)(_QWORD, _QWORD, hkOstream *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64)
                                                            + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
          v145 & 0x3FFFFFFF,
          &tolerance);
        v147 = v10->m_firstFree;
        LODWORD(tolerance.vfptr) = *(_DWORD *)(v147 + 4i64 * SLODWORD(tolerance.vfptr));
        HIDWORD(tolerance.vfptr) = *(_DWORD *)(v147 + 4i64 * SHIDWORD(tolerance.vfptr));
        v148 = v146;
        v149 = v142[v143 + 1];
        *(_DWORD *)&tolerance.m_memSizeAndFlags = *(_DWORD *)(v147 + 4i64 * *(int *)&tolerance.m_memSizeAndFlags);
        v368 = *((_DWORD *)&tolerance.vfptr + v148);
        (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64) + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
          v149 & 0x3FFFFFFF,
          &v359);
        v150 = v10->m_firstFree;
        v359 = *(_DWORD *)(v150 + 4i64 * v359);
        v360 = *(_DWORD *)(v150 + 4i64 * v360);
        v361 = *(_DWORD *)(v150 + 4i64 * v361);
        v369 = *(&v359 + (int)((v149 >> 30) + 1) % 3);
        v151 = v142[v143];
        (*(void (__fastcall **)(_QWORD, _QWORD, hkRefPtr<hkStreamWriter> *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size
                                                                                         + 8i64)
                                                                           + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
          v151 & 0x3FFFFFFF,
          &tolerance.m_writer);
        v152 = v10->m_firstFree;
        v153 = v142[v143];
        LODWORD(tolerance.m_writer.m_pntr) = *(_DWORD *)(v152 + 4i64 * SLODWORD(tolerance.m_writer.m_pntr));
        HIDWORD(tolerance.m_writer.m_pntr) = *(_DWORD *)(v152 + 4i64 * SHIDWORD(tolerance.m_writer.m_pntr));
        v358 = *(_DWORD *)(v152 + 4i64 * v358);
        v353 = *((_DWORD *)&tolerance.m_writer.m_pntr + (int)((v151 >> 30) + 2) % 3);
        (*(void (__fastcall **)(_QWORD, _QWORD, unsigned __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64)
                                                                   + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
          v153 & 0x3FFFFFFF,
          &v354);
        v154 = v10->m_firstFree;
        LODWORD(v354) = *(_DWORD *)(v154 + 4i64 * (int)v354);
        HIDWORD(v354) = *(_DWORD *)(v154 + 4i64 * SHIDWORD(v354));
        LODWORD(v355) = *(_DWORD *)(v154 + 4i64 * (int)v355);
        if ( v368 != v369
          && (*((_DWORD *)&v354 + (int)((v153 >> 30) + 1) % 3) != 222 || v353 != 173 || v369 != 222 || v368 != 173) )
        {
          break;
        }
        --mapping->m_triangleIndexToKey.m_size;
        v85 = v386;
LABEL_120:
        LODWORD(retaddr) = (_DWORD)retaddr + 1;
        vfptr = v385;
        v96 += 12i64;
        ++v389;
      }
      while ( v389 < v388 );
      v85 = v386;
      v84 = v388;
      v95 = v387;
      v93 = result.m_enum;
LABEL_122:
      v85 += 12i64;
      v116 = v366-- == 1;
      v83 = v93;
      v386 = v85;
      v387 = v95 + 1;
      v352 = v93;
      if ( v116 )
      {
        v39 = 0i64;
        break;
      }
    }
  }
  v155 = mapping->m_triangleIndexToKey.m_size;
  if ( v155 )
  {
    v156 = 0;
    LODWORD(retaddr) = 0;
    if ( v155 > 1 )
      hkAlgorithm::quickSortRecursive<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkAlgorithm::less<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad>>(
        (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *)mapping->m_triangleIndexToKey.m_data,
        0,
        v155 - 1,
        0);
    if ( mapping->m_triangleIndexToKey.m_size > 0 )
    {
      v157 = 0i64;
      v158 = 0;
      do
      {
        v159 = mapping->m_triangleIndexToKey.m_data;
        v160 = *(unsigned int *)((char *)mapping->m_triangleIndexToKey.m_data + v39);
        HIDWORD(v354) = *(unsigned int *)((char *)mapping->m_triangleIndexToKey.m_data + v39 + 4);
        result.m_enum = HIDWORD(v354);
        v370 = *(unsigned int *)((char *)v159 + v39 + 8);
        LODWORD(v354) = v160;
        v161 = HIDWORD(v354);
        v162 = HIDWORD(v354) & 0x3FFFFFFF;
        if ( (((unsigned __int8)(LODWORD(v382.m_data.m_data[(__int64)(HIDWORD(v354) & 0x3FFFFFFF) >> 5]) >> (BYTE4(v354) & 0x1F)) | (unsigned __int8)(LODWORD(v382.m_data.m_data[(__int64)(v160 & 0x3FFFFFFF) >> 5]) >> (v160 & 0x1F))) & 1) == 0 )
        {
          v163 = result.m_enum;
          LODWORD(retaddr) = (_DWORD)retaddr + 1;
          v159[v157] = v160;
          v159[v157 + 1] = v163;
          v159[v157 + 2] = v370;
          v157 += 3i64;
          LODWORD(v382.m_data.m_data[(__int64)(v160 & 0x3FFFFFFF) >> 5]) |= 1 << (v160 & 0x1F);
          LODWORD(v382.m_data.m_data[(__int64)v162 >> 5]) |= 1 << (v162 & 0x1F);
          v164 = array;
          *(_BYTE *)((v160 & 0x3FFFFFFF) + *(_QWORD *)array) = `hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep12<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>::`65::rotationsMap[v160 >> 30];
          *(_BYTE *)((v161 & 0x3FFFFFFF) + *v164) = `hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep12<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>::`65::rotationsMap[(int)(((unsigned int)v161 >> 30) + 2) % 3];
        }
        ++v158;
        v39 += 12i64;
      }
      while ( v158 < mapping->m_triangleIndexToKey.m_size );
      v10 = *(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> **)&v398[0].m_enum;
      v156 = (int)retaddr;
      LODWORD(v39) = 0;
    }
    v165 = mapping->m_triangleIndexToKey.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v165 < v156 )
    {
      v166 = 2 * v165;
      v167 = v156;
      if ( v156 < v166 )
        v167 = v166;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&mapping->m_triangleIndexToKey.m_data,
        v167,
        12);
    }
    mapping->m_triangleIndexToKey.m_size = v156;
  }
  *(_DWORD *)&tolerance.m_memSizeAndFlags = 0;
  if ( *(int *)(&tolerance.m_referenceCount + 1) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      tolerance.vfptr,
      12 * (*(_DWORD *)(&tolerance.m_referenceCount + 1) & 0x3FFFFFFF));
  tolerance.vfptr = 0i64;
  *(_QWORD *)&tolerance.m_memSizeAndFlags = 0xFFFFFFFF00000000ui64;
  v374.m_elem = 0i64;
  v374.m_numElems = 0;
  v374.m_hashMod = -1;
  v375 = 0i64;
  v376 = 0;
  v377 = 0x80000000;
  v379 = 256;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = Value->m_cur;
  v170 = m_cur + 256;
  if ( Value->m_slabSize < 2048 || v170 > Value->m_end )
    m_cur = (_QWORD *)hkLifoAllocator::allocateFromNewSlab(Value, 2048);
  else
    Value->m_cur = v170;
  v375 = m_cur;
  v377 = -2147483392;
  p = m_cur;
  v171 = 1 - v376;
  if ( v171 > 0 )
  {
    memset(&m_cur[v376], 0, 8 * v171);
    m_cur = v375;
  }
  v376 = 1;
  *m_cur = config;
  v172 = _mm_shuffle_ps((__m128)*(unsigned int *)(v397 + 32), (__m128)*(unsigned int *)(v397 + 32), 0);
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
    config,
    (hkResult *)&retaddr,
    2 * (vars0.m_enum + mapping->m_triangleIndexToKey.m_size));
  LODWORD(retaddr) = 0;
  if ( mapping->m_triangleIndexToKey.m_size > 0 )
  {
    v173 = 0i64;
    v174 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v175 = (__m128)xmmword_141A712A0;
      v176 = _mm_xor_ps((__m128)xmmword_141A712A0, v174);
      v177 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
               (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&tolerance,
               0i64,
               0i64);
      do
      {
        v178 = mapping->m_triangleIndexToKey.m_data;
        if ( (_DWORD)v39 )
        {
          switch ( (_DWORD)v39 )
          {
            case 1:
              v184 = v178[v173];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64)
                                                            + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
                v184 & 0x3FFFFFFF,
                &v359);
              v185 = v10->m_firstFree;
              v359 = *(_DWORD *)(v185 + 4i64 * v359);
              v360 = *(_DWORD *)(v185 + 4i64 * v360);
              v361 = *(_DWORD *)(v185 + 4i64 * v361);
              v179 = (unsigned int)*(&v359 + (int)((v184 >> 30) + 2) % 3);
              break;
            case 2:
              v182 = v178[v173 + 1];
              (*(void (__fastcall **)(_QWORD, _QWORD, hkRefPtr<hkStreamWriter> *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size
                                                                                               + 8i64)
                                                                                 + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
                v182 & 0x3FFFFFFF,
                &tolerance.m_writer);
              v183 = v10->m_firstFree;
              LODWORD(tolerance.m_writer.m_pntr) = *(_DWORD *)(v183 + 4i64 * SLODWORD(tolerance.m_writer.m_pntr));
              HIDWORD(tolerance.m_writer.m_pntr) = *(_DWORD *)(v183 + 4i64 * SHIDWORD(tolerance.m_writer.m_pntr));
              v358 = *(_DWORD *)(v183 + 4i64 * v358);
              v179 = *((unsigned int *)&tolerance.m_writer.m_pntr + (int)((v182 >> 30) + 1) % 3);
              break;
            case 3:
              v180 = v178[v173 + 1];
              (*(void (__fastcall **)(_QWORD, _QWORD, unsigned __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size
                                                                                       + 8i64)
                                                                         + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
                v180 & 0x3FFFFFFF,
                &v354);
              v181 = v10->m_firstFree;
              LODWORD(v354) = *(_DWORD *)(v181 + 4i64 * (int)v354);
              HIDWORD(v354) = *(_DWORD *)(v181 + 4i64 * SHIDWORD(v354));
              LODWORD(v355) = *(_DWORD *)(v181 + 4i64 * (int)v355);
              v179 = *((unsigned int *)&v354 + (int)((v180 >> 30) + 2) % 3);
              break;
            default:
              v179 = 0xFFFFFFFFi64;
              break;
          }
        }
        else
        {
          v186 = v178[v173];
          (*(void (__fastcall **)(_QWORD, _QWORD, hkOstream *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64)
                                                              + 32i64))(
            *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
            v186 & 0x3FFFFFFF,
            &tolerance);
          v187 = v10->m_firstFree;
          LODWORD(tolerance.vfptr) = *(_DWORD *)(v187 + 4i64 * SLODWORD(tolerance.vfptr));
          HIDWORD(tolerance.vfptr) = *(_DWORD *)(v187 + 4i64 * SHIDWORD(tolerance.vfptr));
          *(_DWORD *)&tolerance.m_memSizeAndFlags = *(_DWORD *)(v187 + 4i64 * *(int *)&tolerance.m_memSizeAndFlags);
          v179 = *((unsigned int *)&tolerance.vfptr + (int)((v186 >> 30) + 1) % 3);
        }
        ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, __int64, __m128 *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
          v10,
          v179,
          &v362);
        LODWORD(v39) = v39 + 1;
        v175 = _mm_min_ps(v175, v362);
        v176 = _mm_max_ps(v176, v362);
      }
      while ( (int)v39 < 4 );
      v188 = _mm_sub_ps(v175, v172);
      v189 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)v375[v177];
      v190 = _mm_add_ps(v176, v172);
      if ( !v189->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)v375[v177],
          v398,
          1);
      v191 = v189->m_firstFree;
      v192 = v189->m_nodes.m_data;
      v193 = v191 << 6;
      v189->m_firstFree = v189->m_nodes.m_data[(__int64)(int)v191].m_aabb.m_min.m_quad.m128_u64[0];
      *(unsigned __int64 *)((char *)v192->m_children + v193) = 0i64;
      *(unsigned __int64 *)((char *)&v192->m_children[1] + v193) = (int)retaddr;
      *(__m128 *)((char *)&v192->m_aabb.m_min.m_quad + v193) = v188;
      *(__m128 *)((char *)&v192->m_aabb.m_max.m_quad + v193) = v190;
      v194 = v189->m_nodes.m_data;
      v195 = *(_QWORD *)&v189[1].m_nodes.m_size;
      m_quad = v189->m_nodes.m_data[v191].m_aabb.m_min.m_quad;
      v197 = v189->m_nodes.m_data[v191].m_aabb.m_max.m_quad;
      if ( v195 )
      {
        if ( !v189->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            v189,
            &result,
            1);
        v198 = v189->m_firstFree;
        v199 = (int)v198;
        p_m_quad = &v189->m_nodes.m_data[v195].m_aabb.m_min.m_quad;
        v201 = &v189->m_nodes.m_data[v198].m_aabb.m_min.m_quad;
        v189->m_firstFree = v189->m_nodes.m_data[v199].m_aabb.m_min.m_quad.m128_u64[0];
        if ( p_m_quad[2].m128_i32[2] )
        {
          v202 = _mm_add_ps(v197, m_quad);
          v203 = _mm_sub_ps(v197, m_quad);
          do
          {
            v204 = (__int64)&v189->m_nodes.m_data[p_m_quad[2].m128_u64[1]];
            v205 = (__int64)&v189->m_nodes.m_data[p_m_quad[3].m128_u64[0]];
            v206 = _mm_max_ps(p_m_quad[1], v197);
            *p_m_quad = _mm_min_ps(*p_m_quad, m_quad);
            p_m_quad[1] = v206;
            v363 = v204;
            v364 = v205;
            v207 = *(__m128 *)(v204 + 16);
            v208 = *(__m128 *)(v205 + 16);
            v209 = _mm_add_ps(_mm_sub_ps(v207, *(__m128 *)v204), v203);
            v210 = _mm_add_ps(_mm_sub_ps(v208, *(__m128 *)v205), v203);
            v211 = _mm_sub_ps(_mm_add_ps(v207, *(__m128 *)v204), v202);
            v212 = _mm_mul_ps(v211, v211);
            v213 = _mm_sub_ps(_mm_add_ps(v208, *(__m128 *)v205), v202);
            v214 = _mm_mul_ps(v213, v213);
            p_m_quad = (__m128 *)*(&v363
                                 + ((float)((float)((float)(_mm_shuffle_ps(v209, v209, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v209, v209, 0).m128_f32[0])
                                                  + _mm_shuffle_ps(v209, v209, 170).m128_f32[0])
                                          * (float)((float)(_mm_shuffle_ps(v212, v212, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v212, v212, 0).m128_f32[0])
                                                  + _mm_shuffle_ps(v212, v212, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v210, v210, 85).m128_f32[0] + _mm_shuffle_ps(v210, v210, 0).m128_f32[0]) + _mm_shuffle_ps(v210, v210, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v214, v214, 85).m128_f32[0] + _mm_shuffle_ps(v214, v214, 0).m128_f32[0]) + _mm_shuffle_ps(v214, v214, 170).m128_f32[0]))));
          }
          while ( p_m_quad[2].m128_i32[2] );
        }
        v215 = p_m_quad[2].m128_u64[0];
        v216 = ((char *)v201 - (char *)v189->m_nodes.m_data) >> 6;
        if ( v215 )
          v189->m_nodes.m_data[v215].m_children[v189->m_nodes.m_data[v215].m_children[1] == ((char *)p_m_quad
                                                                                           - (char *)v189->m_nodes.m_data) >> 6] = v216;
        else
          *(_QWORD *)&v189[1].m_nodes.m_size = v216;
        v201[2].m128_u64[0] = p_m_quad[2].m128_u64[0];
        v217 = (char *)p_m_quad - (char *)v189->m_nodes.m_data;
        v201[3].m128_u64[0] = v191;
        v201[2].m128_u64[1] = v217 >> 6;
        p_m_quad[2].m128_u64[0] = v216;
        *(unsigned __int64 *)((char *)&v189->m_nodes.m_data->m_parent + v193) = v216;
        v218 = _mm_max_ps(p_m_quad[1], v197);
        *v201 = _mm_min_ps(*p_m_quad, m_quad);
        v201[1] = v218;
      }
      else
      {
        *(_QWORD *)&v189[1].m_nodes.m_size = v191;
        *(unsigned __int64 *)((char *)&v194->m_parent + v193) = 0i64;
      }
      ++LODWORD(v189[1].m_nodes.m_data);
      v173 += 3i64;
      LODWORD(v39) = 0;
      LODWORD(retaddr) = (_DWORD)retaddr + 1;
    }
    while ( (int)retaddr < mapping->m_triangleIndexToKey.m_size );
  }
  v219 = mapping->m_triangleIndexToKey.m_size;
  v220 = vars0.m_enum;
  LODWORD(retaddr) = v219;
  v221 = HK_SUCCESS;
  if ( vars0.m_enum > HK_SUCCESS )
  {
    v222 = 0i64;
    do
    {
      if ( ((*(_DWORD *)(*(_QWORD *)&v10[1].m_nodes.m_size + 4 * (v222 >> 5)) >> (v221 & 0x1F)) & 1) != 0
        && ((LODWORD(v382.m_data.m_data[v222 >> 5]) >> (v221 & 0x1F)) & 1) == 0 )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64) + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64),
          (unsigned int)v221,
          &v363);
        v223 = v10->m_firstFree;
        LODWORD(v363) = *(_DWORD *)(v223 + 4i64 * (int)v363);
        HIDWORD(v363) = *(_DWORD *)(v223 + 4i64 * SHIDWORD(v363));
        v224.vfptr = (hkGeometryUtils::IVerticesVtbl *)v10->m_nodes.m_data;
        LODWORD(v364) = *(_DWORD *)(v223 + 4i64 * (int)v364);
        v224.vfptr->getVertex((hkGeometryUtils::IVertices *)v10, v363, &customPrimitive.m_aabb.m_min);
        ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, hkVector4f *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
          v10,
          HIDWORD(v363),
          &customPrimitive.m_aabb.m_max);
        ((void (__fastcall *)(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *, _QWORD, int *))v10->m_nodes.m_data->m_aabb.m_max.m_quad.m128_u64[0])(
          v10,
          (unsigned int)v364,
          &customPrimitive.m_numVertices);
        v225 = _mm_add_ps(
                 _mm_max_ps(
                   _mm_max_ps(customPrimitive.m_aabb.m_min.m_quad, customPrimitive.m_aabb.m_max.m_quad),
                   *(__m128 *)&customPrimitive.m_numVertices),
                 v172);
        v226 = _mm_sub_ps(
                 _mm_min_ps(
                   _mm_min_ps(customPrimitive.m_aabb.m_min.m_quad, customPrimitive.m_aabb.m_max.m_quad),
                   *(__m128 *)&customPrimitive.m_numVertices),
                 v172);
        v227 = (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&tolerance,
                      0i64,
                      0i64);
        v228 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)v375[v227];
        if ( !v228->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)v375[v227],
            v398,
            1);
        v229 = v228->m_firstFree;
        v230 = v228->m_nodes.m_data;
        v231 = v229 << 6;
        v228->m_firstFree = v228->m_nodes.m_data[(__int64)(int)v229].m_aabb.m_min.m_quad.m128_u64[0];
        *(unsigned __int64 *)((char *)v230->m_children + v231) = 0i64;
        *(unsigned __int64 *)((char *)&v230->m_children[1] + v231) = v222 + (int)retaddr;
        *(__m128 *)((char *)&v230->m_aabb.m_min.m_quad + v231) = v226;
        *(__m128 *)((char *)&v230->m_aabb.m_max.m_quad + v231) = v225;
        v232 = v228->m_nodes.m_data;
        v233 = *(_QWORD *)&v228[1].m_nodes.m_size;
        v234 = v228->m_nodes.m_data[v229].m_aabb.m_min.m_quad;
        v235 = v228->m_nodes.m_data[v229].m_aabb.m_max.m_quad;
        if ( v233 )
        {
          if ( !v228->m_firstFree )
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
              v228,
              &result,
              1);
          v236 = v228->m_firstFree;
          v237 = (int)v236;
          v238 = &v228->m_nodes.m_data[v233].m_aabb.m_min.m_quad;
          v239 = &v228->m_nodes.m_data[v236].m_aabb.m_min.m_quad;
          v228->m_firstFree = v228->m_nodes.m_data[v237].m_aabb.m_min.m_quad.m128_u64[0];
          if ( v238[2].m128_i32[2] )
          {
            v240 = _mm_add_ps(v235, v234);
            v241 = _mm_sub_ps(v235, v234);
            do
            {
              v242 = (__int64)&v228->m_nodes.m_data[v238[2].m128_u64[1]];
              v243 = (__int64)&v228->m_nodes.m_data[v238[3].m128_u64[0]];
              v244 = _mm_max_ps(v238[1], v235);
              *v238 = _mm_min_ps(*v238, v234);
              v238[1] = v244;
              v354 = v242;
              v355 = v243;
              v245 = *(__m128 *)(v242 + 16);
              v246 = *(__m128 *)(v243 + 16);
              v247 = _mm_add_ps(_mm_sub_ps(v245, *(__m128 *)v242), v241);
              v248 = _mm_add_ps(_mm_sub_ps(v246, *(__m128 *)v243), v241);
              v249 = _mm_sub_ps(_mm_add_ps(v245, *(__m128 *)v242), v240);
              v250 = _mm_mul_ps(v249, v249);
              v251 = _mm_sub_ps(_mm_add_ps(v246, *(__m128 *)v243), v240);
              v252 = _mm_mul_ps(v251, v251);
              v238 = (__m128 *)*(&v354
                               + ((float)((float)((float)(_mm_shuffle_ps(v247, v247, 85).m128_f32[0]
                                                        + _mm_shuffle_ps(v247, v247, 0).m128_f32[0])
                                                + _mm_shuffle_ps(v247, v247, 170).m128_f32[0])
                                        * (float)((float)(_mm_shuffle_ps(v250, v250, 85).m128_f32[0]
                                                        + _mm_shuffle_ps(v250, v250, 0).m128_f32[0])
                                                + _mm_shuffle_ps(v250, v250, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v248, v248, 85).m128_f32[0] + _mm_shuffle_ps(v248, v248, 0).m128_f32[0]) + _mm_shuffle_ps(v248, v248, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v252, v252, 85).m128_f32[0] + _mm_shuffle_ps(v252, v252, 0).m128_f32[0]) + _mm_shuffle_ps(v252, v252, 170).m128_f32[0]))));
            }
            while ( v238[2].m128_i32[2] );
          }
          v253 = v238[2].m128_u64[0];
          v254 = ((char *)v239 - (char *)v228->m_nodes.m_data) >> 6;
          if ( v253 )
            v228->m_nodes.m_data[v253].m_children[v228->m_nodes.m_data[v253].m_children[1] == ((char *)v238
                                                                                             - (char *)v228->m_nodes.m_data) >> 6] = v254;
          else
            *(_QWORD *)&v228[1].m_nodes.m_size = v254;
          v239[2].m128_u64[0] = v238[2].m128_u64[0];
          v255 = (char *)v238 - (char *)v228->m_nodes.m_data;
          v239[3].m128_u64[0] = v229;
          v239[2].m128_u64[1] = v255 >> 6;
          v238[2].m128_u64[0] = v254;
          *(unsigned __int64 *)((char *)&v228->m_nodes.m_data->m_parent + v231) = v254;
          v256 = _mm_max_ps(v238[1], v235);
          *v239 = _mm_min_ps(*v238, v234);
          v239[1] = v256;
        }
        else
        {
          *(_QWORD *)&v228[1].m_nodes.m_size = v229;
          *(unsigned __int64 *)((char *)&v232->m_parent + v231) = 0i64;
        }
        ++LODWORD(v228[1].m_nodes.m_data);
        v220 = vars0.m_enum;
      }
      ++v221;
      ++v222;
    }
    while ( v221 < v220 );
    v219 = (int)retaddr;
  }
  v257 = v220 + v219;
  v258 = 0;
  LODWORD(retaddr) = v257;
  v259 = 0i64;
  v260 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(*(_QWORD *)&v10->m_nodes.m_size + 8i64) + 64i64))(*(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 8i64));
  array = (void *)v260;
  if ( v260 > 0 )
  {
    v261 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v262 = *(hkpBvCompressedMeshShape_Internals::GeometryProvider **)&v10->m_nodes.m_size;
      customPrimitive.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
      *(_QWORD *)&customPrimitive.m_numVertices = 0i64;
      customPrimitive.m_aabb.m_max.m_quad = _mm_xor_ps((__m128)xmmword_141A712A0, v261);
      customPrimitive.m_layerData = 0;
      customPrimitive.m_tags.m_size = 0;
      customPrimitive.m_maxError = 3.40282e38;
      customPrimitive.m_compression = CM_LOCAL_4;
      hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(v262, v258, &customPrimitive);
      v263.m_quad = (__m128)customPrimitive.m_aabb.m_min;
      v264.m_quad = (__m128)customPrimitive.m_aabb.m_max;
      v265 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
               (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&tolerance,
               (unsigned __int8)customPrimitive.m_layerData,
               0i64);
      if ( (_mm_movemask_ps(_mm_cmple_ps(v264.m_quad, v263.m_quad)) & 7) != 0 )
      {
        if ( customPrimitive.m_numVertices > 0 )
        {
          v266 = *(__m128 **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v10->m_nodes.m_size + 16i64) + 8 * v259) + 32i64);
          m_numVertices = (unsigned int)customPrimitive.m_numVertices;
          do
          {
            v263.m_quad = _mm_min_ps(v263.m_quad, *v266);
            v264.m_quad = _mm_max_ps(v264.m_quad, *v266++);
            --m_numVertices;
          }
          while ( m_numVertices );
        }
        v257 = (int)retaddr;
        v263.m_quad = _mm_sub_ps(v263.m_quad, v172);
        v264.m_quad = _mm_add_ps(v264.m_quad, v172);
      }
      v268 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)v375[v265];
      if ( !v268->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
          v268,
          v398,
          1);
      v269 = v268->m_firstFree;
      v270 = v268->m_nodes.m_data;
      v271 = v269 << 6;
      v268->m_firstFree = v268->m_nodes.m_data[(__int64)(int)v269].m_aabb.m_min.m_quad.m128_u64[0];
      *(unsigned __int64 *)((char *)v270->m_children + v271) = 0i64;
      *(unsigned __int64 *)((char *)&v270->m_children[1] + v271) = v258 + v257;
      *(hkVector4f *)((char *)&v270->m_aabb.m_min + v271) = (hkVector4f)v263.m_quad;
      *(hkVector4f *)((char *)&v270->m_aabb.m_max + v271) = (hkVector4f)v264.m_quad;
      v272 = v268->m_nodes.m_data;
      v273 = *(_QWORD *)&v268[1].m_nodes.m_size;
      v274 = v268->m_nodes.m_data[v269].m_aabb.m_min.m_quad;
      v275 = v268->m_nodes.m_data[v269].m_aabb.m_max.m_quad;
      if ( v273 )
      {
        if ( !v268->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            v268,
            &vars0,
            1);
        v276 = v268->m_firstFree;
        v277 = (int)v276;
        v278 = &v268->m_nodes.m_data[v273].m_aabb.m_min.m_quad;
        v279 = &v268->m_nodes.m_data[v276].m_aabb.m_min.m_quad;
        v268->m_firstFree = v268->m_nodes.m_data[v277].m_aabb.m_min.m_quad.m128_u64[0];
        if ( v278[2].m128_i32[2] )
        {
          v280 = _mm_add_ps(v275, v274);
          v281 = _mm_sub_ps(v275, v274);
          do
          {
            v282 = (__int64)&v268->m_nodes.m_data[v278[2].m128_u64[1]];
            v283 = (__int64)&v268->m_nodes.m_data[v278[3].m128_u64[0]];
            v284 = _mm_max_ps(v278[1], v275);
            *v278 = _mm_min_ps(*v278, v274);
            v278[1] = v284;
            v354 = v282;
            v355 = v283;
            v285 = *(__m128 *)(v282 + 16);
            v286 = *(__m128 *)(v283 + 16);
            v287 = _mm_add_ps(_mm_sub_ps(v285, *(__m128 *)v282), v281);
            v288 = _mm_add_ps(_mm_sub_ps(v286, *(__m128 *)v283), v281);
            v289 = _mm_sub_ps(_mm_add_ps(v285, *(__m128 *)v282), v280);
            v290 = _mm_mul_ps(v289, v289);
            v291 = _mm_sub_ps(_mm_add_ps(v286, *(__m128 *)v283), v280);
            v292 = _mm_mul_ps(v291, v291);
            v278 = (__m128 *)*(&v354
                             + ((float)((float)((float)(_mm_shuffle_ps(v287, v287, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v287, v287, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v287, v287, 170).m128_f32[0])
                                      * (float)((float)(_mm_shuffle_ps(v290, v290, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v290, v290, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v290, v290, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v288, v288, 85).m128_f32[0] + _mm_shuffle_ps(v288, v288, 0).m128_f32[0]) + _mm_shuffle_ps(v288, v288, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v292, v292, 85).m128_f32[0] + _mm_shuffle_ps(v292, v292, 0).m128_f32[0]) + _mm_shuffle_ps(v292, v292, 170).m128_f32[0]))));
          }
          while ( v278[2].m128_i32[2] );
        }
        v293 = v278[2].m128_u64[0];
        v294 = ((char *)v279 - (char *)v268->m_nodes.m_data) >> 6;
        if ( v293 )
          v268->m_nodes.m_data[v293].m_children[v268->m_nodes.m_data[v293].m_children[1] == ((char *)v278
                                                                                           - (char *)v268->m_nodes.m_data) >> 6] = v294;
        else
          *(_QWORD *)&v268[1].m_nodes.m_size = v294;
        v279[2].m128_u64[0] = v278[2].m128_u64[0];
        v295 = (char *)v278 - (char *)v268->m_nodes.m_data;
        v279[3].m128_u64[0] = v269;
        v279[2].m128_u64[1] = v295 >> 6;
        v278[2].m128_u64[0] = v294;
        *(unsigned __int64 *)((char *)&v268->m_nodes.m_data->m_parent + v271) = v294;
        v296 = _mm_max_ps(v278[1], v275);
        *v279 = _mm_min_ps(*v278, v274);
        v279[1] = v296;
      }
      else
      {
        *(_QWORD *)&v268[1].m_nodes.m_size = v269;
        *(unsigned __int64 *)((char *)&v272->m_parent + v271) = 0i64;
      }
      ++LODWORD(v268[1].m_nodes.m_data);
      v257 = (int)retaddr;
      ++v259;
      ++v258;
    }
    while ( v259 < (__int64)array );
  }
  v297 = v397;
  v298 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)*v375;
  v299 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)*v375;
  if ( *(_BYTE *)v397 )
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildGlobalSAH(v299, 32, 128, 1);
  else
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(v299, v298->m_root, (hkBool)1, 32, 16);
  if ( *(int *)(v297 + 8) > 0 )
  {
    m_root = v298->m_root;
    v301 = 0;
    if ( m_root )
    {
      v302 = v298->m_nodes.m_data;
      v303 = 0;
      v304 = m_root << 6;
      m_parent = v298->m_nodes.m_data[m_root].m_parent;
      if ( m_parent )
      {
        v306 = v298->m_nodes.m_data[m_root].m_parent;
        do
        {
          ++v303;
          v306 = v302[v306].m_parent;
        }
        while ( v306 );
      }
      if ( *(_DWORD *)((char *)v302->m_children + v304) )
      {
        v307 = *(unsigned __int64 *)((char *)v302->m_children + v304);
        if ( v307 )
        {
          do
          {
            v308 = v307 << 6;
            if ( LODWORD(v302[v307].m_children[0]) )
            {
              v307 = *(unsigned __int64 *)((char *)v302->m_children + v308);
            }
            else
            {
              v309 = *(unsigned __int64 *)((char *)&v302->m_parent + v308);
              for ( j = 0; v309; v309 = v302[v309].m_parent )
                ++j;
              v311 = j - v303;
              if ( v301 > v311 )
                v311 = v301;
              v301 = v311;
              v312 = *(unsigned __int64 *)((char *)&v302->m_parent + v308);
              for ( k = v307; v312 != m_root; v312 = v302[v312].m_parent )
              {
                if ( v302[v312].m_children[1] != k )
                  break;
                k = v312;
              }
              if ( v312 )
                v307 = v302[v312].m_children[1];
              else
                v307 = k;
              if ( v312 == m_root && v307 == k )
                v307 = 0i64;
            }
          }
          while ( v307 );
          v297 = v397;
        }
      }
      else
      {
        for ( ; m_parent; m_parent = v302[m_parent].m_parent )
          ++v301;
        v301 -= v303;
        if ( v301 < 0 )
          v301 = 0;
      }
    }
    while ( 1 )
    {
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::balance(v298, *(_DWORD *)(v297 + 8), 0i64);
      v314 = v298->m_root;
      v315 = 0;
      if ( v314 )
      {
        v316 = v298->m_nodes.m_data;
        v317 = 0;
        v318 = v314 << 6;
        v319 = v298->m_nodes.m_data[v314].m_parent;
        if ( v319 )
        {
          v320 = v298->m_nodes.m_data[v314].m_parent;
          do
          {
            ++v317;
            v320 = v316[v320].m_parent;
          }
          while ( v320 );
        }
        if ( *(_DWORD *)((char *)v316->m_children + v318) )
        {
          v321 = *(unsigned __int64 *)((char *)v316->m_children + v318);
          if ( v321 )
          {
            do
            {
              v322 = v321 << 6;
              if ( LODWORD(v316[v321].m_children[0]) )
              {
                v321 = *(unsigned __int64 *)((char *)v316->m_children + v322);
              }
              else
              {
                v323 = *(unsigned __int64 *)((char *)&v316->m_parent + v322);
                for ( m = 0; v323; v323 = v316[v323].m_parent )
                  ++m;
                v325 = m - v317;
                if ( v315 > v325 )
                  v325 = v315;
                v315 = v325;
                v326 = *(unsigned __int64 *)((char *)&v316->m_parent + v322);
                for ( n = v321; v326 != v314; v326 = v316[v326].m_parent )
                {
                  if ( v316[v326].m_children[1] != n )
                    break;
                  n = v326;
                }
                if ( v326 )
                  v321 = v316[v326].m_children[1];
                else
                  v321 = n;
                if ( v326 == v314 && v321 == n )
                  v321 = 0i64;
              }
            }
            while ( v321 );
            v297 = v397;
          }
        }
        else
        {
          for ( ; v319; v319 = v316[v319].m_parent )
            ++v315;
          v315 -= v317;
          if ( v315 < 0 )
            v315 = 0;
        }
      }
      if ( v315 >= v301 )
        break;
      v301 = v315;
    }
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::compactIndices(v298);
  }
  v328 = config;
  LODWORD(v355) = 0;
  v329 = *(_QWORD *)&config[1].m_nodes.m_size;
  v330 = 0;
  if ( v329 )
  {
    v331 = config->m_nodes.m_data;
    if ( LODWORD(config->m_nodes.m_data[v329].m_children[0]) )
    {
      v332 = v331[v329].m_children[0];
      while ( v332 )
      {
        v333 = v332 << 6;
        v334 = v331[v332].m_children[0];
        v330 += v334 == 0;
        if ( v334 )
        {
          v332 = *(unsigned __int64 *)((char *)v331->m_children + v333);
        }
        else
        {
          v335 = *(unsigned __int64 *)((char *)&v331->m_parent + v333);
          for ( ii = v332; v335 != v329; v335 = v331[v335].m_parent )
          {
            if ( v331[v335].m_children[1] != ii )
              break;
            ii = v335;
          }
          if ( v335 )
            v332 = v331[v335].m_children[1];
          else
            v332 = ii;
          if ( v335 == v329 && v332 == ii )
            v332 = 0i64;
        }
      }
    }
    else
    {
      v330 = 1;
    }
  }
  HIDWORD(v355) = v330;
  LODWORD(v356) = -1;
  if ( *(_DWORD *)&this[8] == (*(_DWORD *)&this[12] & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)this, 24);
    v328 = config;
  }
  v337 = (_QWORD *)(*(_QWORD *)this + 24i64 * *(int *)&this[8]);
  if ( v337 )
  {
    v338 = v355;
    *v337 = v329;
    v337[1] = v338;
    v337[2] = v356;
  }
  ++*(_DWORD *)&this[8];
  if ( LODWORD(v328[1].m_nodes.m_data) )
  {
    v339 = *(_QWORD *)&v328[1].m_nodes.m_size;
    if ( v339 )
    {
      m128_f32 = (_OWORD *)v328->m_nodes.m_data[v339].m_aabb.m_min.m_quad.m128_f32;
      v341 = *m128_f32;
      v342 = *((__m128 *)m128_f32 + 1);
    }
    else
    {
      v341 = xmmword_141A712A0;
      v342 = _mm_xor_ps(
               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
               (__m128)xmmword_141A712A0);
    }
    v343 = 1;
    v344 = (__int128 *)&v328->m_nodes.m_data[v339];
    *v344 = v341;
    v344[1] = (__int128)v342;
  }
  else
  {
    v343 = 0;
  }
  v345 = v376;
  v346 = (char *)p;
  if ( p == v375 )
    v345 = 0;
  v376 = v345;
  v347 = (8 * v379 + 127) & 0xFFFFFF80;
  v348 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v349 = (v347 + 15) & 0xFFFFFFF0;
  if ( v347 > v348->m_slabSize || &v346[v349] != v348->m_cur || v348->m_firstNonLifoEnd == v346 )
    hkLifoAllocator::slowBlockFree(v348, v346, v349);
  else
    v348->m_cur = v346;
  v376 = 0;
  if ( v377 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v375, 8 * v377);
  v375 = 0i64;
  v377 = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v374,
    &hkContainerHeapAllocator::s_alloc);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&tolerance,
    &hkContainerHeapAllocator::s_alloc);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v382);
  return v343;
}>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v382);
  return v343;
}

// File Line: 402
// RVA: 0xDECF60
char __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep3<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *this,
        hkcdStaticMeshTreeBase::BuildConfig *config,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *qInfos,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *provider,
        hkcdStaticMeshTreeBase::BuildMapping *mapping,
        hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *quads,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *roots,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *masterTree,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *mesh)
{
  hkcdStaticMeshTreeBase::BuildMapping *v9; // rdi
  int m_size; // ebx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v11; // r14
  int v12; // eax
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v13; // r11
  int v14; // r13d
  int v15; // r12d
  __int64 v16; // rsi
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v17; // r9
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v18; // rdi
  hkcdDynamicTree::CodecRawUlong *m_data; // rdx
  int m_value_low; // r13d
  __int64 v21; // r15
  int v22; // r10d
  char *v23; // r15
  __int64 v24; // rbx
  unsigned __int64 v25; // r8
  unsigned __int64 v26; // r9
  int v27; // ecx
  unsigned __int64 m_parent; // rcx
  unsigned __int64 i; // rdi
  int m_capacityAndFlags; // eax
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v31; // rdx
  unsigned __int64 v32; // rax
  __int64 v33; // r9
  int v34; // r11d
  hkcdDynamicTree::CodecRawUlong *v35; // rdx
  unsigned __int64 v36; // r8
  unsigned __int64 v37; // r10
  int v38; // ecx
  unsigned __int64 v39; // rcx
  unsigned __int64 j; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v41; // rcx
  unsigned __int64 v42; // rax
  __int64 v43; // rsi
  void **p_m_numLeaves; // r12
  int v45; // eax
  int v46; // eax
  int v47; // r9d
  int v48; // eax
  __int64 v49; // rbx
  int *v50; // rdi
  __int64 m_root_low; // rcx
  __int64 v52; // rdx
  __int64 v53; // rax
  int v54; // esi
  int v55; // r15d
  int v56; // eax
  __int64 v57; // rdi
  int *v58; // rbx
  unsigned int v59; // ecx
  __int64 v60; // rdx
  int *v61; // rcx
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v62; // r8
  hkcdDynamicTree::CodecRawUlong *v63; // rax
  __m128 m_quad; // xmm12
  __int64 v65; // rdx
  __int64 v66; // rdi
  __m128 *v67; // rax
  __m128 *v68; // rcx
  unsigned int v69; // eax
  __int64 v70; // rdx
  int *v71; // rcx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *v72; // r11
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v73; // rax
  int v74; // edx
  __int64 v75; // r12
  int v76; // edi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v77; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v78; // rcx
  int v79; // eax
  __int64 v80; // rdx
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v81; // rdx
  unsigned int v82; // edi
  int v83; // r12d
  float v84; // xmm13_4
  char *v85; // rcx
  __m128 *v86; // rdi
  unsigned __int64 v87; // r10
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v88; // rdx
  __m128 v89; // xmm10
  __m128 v90; // xmm13
  __int64 v91; // r8
  unsigned __int64 v92; // r8
  __int64 v93; // r9
  __int64 v94; // rcx
  unsigned __int64 v95; // rdx
  __int64 v96; // rcx
  __int64 v97; // rcx
  __int64 k; // rdi
  __int64 v99; // rcx
  unsigned __int64 v100; // rdx
  __int64 v101; // rcx
  __int64 v102; // rsi
  int v103; // eax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v104; // rdi
  int v105; // edx
  __int64 m_elem_low; // rdx
  unsigned int *v107; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *v108; // r15
  __int64 v109; // r14
  unsigned int v110; // ebx
  unsigned int v111; // ebx
  int v112; // ebx
  unsigned int v113; // edi
  __int64 *v114; // rsi
  __int64 v115; // r15
  __int64 v116; // rdx
  __int64 v117; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *v118; // rcx
  int v119; // eax
  __m128 v120; // xmm7
  __m128 v121; // xmm1
  __m128 v122; // xmm2
  __m128 v123; // xmm3
  __m128 v124; // xmm0
  __m128 v125; // xmm4
  unsigned int v126; // ecx
  __m128 v127; // xmm4
  __m128 v128; // xmm0
  __m128 v129; // xmm3
  __m128 v130; // xmm5
  __m128 v131; // xmm5
  __m128 v132; // xmm2
  hkOstream *v133; // rax
  hkOstream *v134; // rax
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v135; // rsi
  unsigned int *v136; // rdx
  __m128 *v137; // rcx
  int v138; // r15d
  __m128 v139; // xmm8
  __int64 v140; // r13
  __m128 v141; // xmm7
  char *v142; // rax
  __m128 v143; // xmm6
  __m128 *v144; // r12
  int v145; // ecx
  __int64 v146; // rdx
  unsigned int *v147; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *v148; // r13
  __int64 v149; // r14
  unsigned int v150; // ebx
  unsigned int v151; // ebx
  int v152; // ebx
  unsigned int v153; // edi
  __int64 *v154; // rdi
  __int64 v155; // rsi
  __int64 v156; // rdx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v157; // rdi
  int v158; // r9d
  int v159; // eax
  int v160; // eax
  int v161; // r9d
  unsigned __int64 *p_m_firstFree; // r15
  signed int v163; // eax
  int v164; // eax
  int v165; // r9d
  int *p_m_size; // r12
  int m_firstFree_high; // eax
  int v168; // eax
  int v169; // eax
  int v170; // eax
  int v171; // eax
  float v172; // xmm15_4
  int v173; // r13d
  float v174; // xmm14_4
  __m128 *v175; // r9
  __m128 v176; // xmm11
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v177; // rdx
  __m128 v178; // xmm10
  __int64 v179; // rdi
  __int64 v180; // r8
  __m128 *v181; // r12
  __int64 v182; // r15
  __int64 v183; // rcx
  int v184; // eax
  __int64 v185; // rcx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v186; // r8
  unsigned __int64 *v187; // rdx
  __int64 v188; // rcx
  __m128 *p_m_quad; // rax
  int v190; // esi
  __m128 v191; // xmm7
  __m128 v192; // xmm8
  __int64 v193; // rdx
  unsigned int *v194; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *v195; // r13
  __int64 v196; // r14
  unsigned int v197; // ebx
  unsigned int v198; // ebx
  int v199; // ebx
  unsigned int v200; // edi
  int v201; // ebx
  __int64 v202; // rdx
  __int64 *v203; // r13
  __int64 v204; // rcx
  __int64 v205; // rsi
  int v206; // eax
  unsigned __int64 *v207; // r9
  unsigned __int64 v208; // rdx
  __int64 v209; // rdi
  __m128 v210; // xmm2
  __m128 v211; // xmm1
  __m128 v212; // xmm3
  __m128 v213; // xmm1
  __m128 v214; // xmm4
  __m128 v215; // xmm1
  unsigned __int64 v216; // rax
  __m128 v217; // xmm2
  __m128 v218; // xmm3
  __m128 v219; // xmm1
  float v220; // xmm4_4
  unsigned __int64 v221; // rdx
  float v222; // xmm0_4
  unsigned __int64 v223; // rcx
  unsigned __int64 v224; // rax
  float v225; // xmm0_4
  unsigned __int64 v226; // rdx
  unsigned __int64 v227; // rcx
  __m128 v228; // xmm0
  unsigned __int64 v229; // r9
  unsigned __int64 *v230; // r9
  unsigned __int64 v231; // rcx
  __int64 v232; // rdx
  __m128 v233; // xmm1
  __int64 v234; // r8
  __int64 m_numVertices; // r9
  __m128 v236; // xmm5
  __m128i si128; // xmm14
  __m128i v238; // xmm15
  __m128 v239; // xmm2
  unsigned __int64 v240; // rax
  __m128 v241; // xmm3
  __m128 v242; // xmm4
  __m128 v243; // xmm0
  float v244; // xmm2_4
  unsigned __int64 v245; // rdx
  unsigned __int64 v246; // rcx
  float v247; // xmm0_4
  unsigned __int64 v248; // rax
  float v249; // xmm0_4
  unsigned __int64 v250; // rdx
  unsigned __int64 v251; // rcx
  __m128 v252; // xmm0
  __int64 v253; // rdx
  __m128 v254; // xmm8
  __m128 v255; // xmm7
  hkcdDynamicTree::CodecRawUlong *v256; // rax
  unsigned __int64 m; // rcx
  hkcdDynamicTree::CodecRawUlong *v258; // rcx
  __m128 v259; // xmm3
  bool v260; // zf
  _WORD *v261; // rax
  int v262; // ecx
  _WORD *v263; // r13
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v264; // r9
  __int64 v265; // rsi
  char *v266; // rdx
  int v267; // r8d
  __int64 v268; // rsi
  int v269; // eax
  unsigned __int64 v270; // rdx
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v271; // rsi
  unsigned __int64 m_root; // r10
  int v273; // eax
  hkcdDynamicTree::CodecRawUlong *v274; // rdi
  unsigned __int64 v275; // rcx
  unsigned __int64 v276; // r9
  unsigned __int64 v277; // rdx
  unsigned __int64 v278; // rcx
  unsigned __int64 v279; // rdx
  unsigned __int64 n; // r8
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v281; // r10
  signed int v282; // r11d
  int v283; // edx
  int v284; // esi
  signed int v285; // r8d
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v286; // r9
  _WORD *v287; // rdi
  __int64 ii; // rcx
  int v289; // eax
  int v290; // ecx
  int v291; // eax
  int v292; // r8d
  __int64 v293; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v294; // rsi
  __int64 v295; // rdx
  char *v296; // r13
  __int64 v297; // rdi
  unsigned __int8 v298; // si
  __int64 v299; // rdx
  char *p_m_data; // rcx
  char v301; // di
  __int64 v302; // r9
  __m128 m_maxError_low; // xmm11
  hkVector4f v304; // xmm13
  hkVector4f v305; // xmm8
  float v306; // xmm11_4
  hkcdStaticMeshTreeBase::CompressionMode m_compression; // ecx
  __m128 v308; // xmm10
  unsigned __int64 v309; // rdi
  __int64 v310; // rsi
  int v311; // r9d
  int v312; // eax
  int v313; // eax
  int v314; // edi
  __int64 v315; // r8
  __m128 v316; // xmm2
  __m128 v317; // xmm1
  __m128 v318; // xmm5
  __m128 v319; // xmm3
  __m128 v320; // xmm1
  __m128 v321; // xmm4
  unsigned __int16 v322; // cx
  __m128 v323; // xmm1
  __m128 v324; // xmm1
  __m128 v325; // xmm4
  __m128 v326; // xmm2
  int v327; // esi
  int v328; // eax
  int v329; // eax
  int v330; // r9d
  __m128 v331; // xmm13
  unsigned __int64 v332; // rdi
  __int64 v333; // rsi
  int v334; // r9d
  int v335; // eax
  int v336; // eax
  int v337; // edx
  __int64 v338; // rdi
  int *v339; // r8
  __m128 v340; // xmm1
  __m128 v341; // xmm2
  __m128 v342; // xmm5
  __m128 v343; // xmm3
  __m128 v344; // xmm1
  __m128 v345; // xmm4
  __m128i v346; // xmm1
  __m128 v347; // xmm1
  __m128 v348; // xmm1
  __m128 v349; // xmm4
  __m128 v350; // xmm2
  int v351; // eax
  int v352; // eax
  int v353; // r9d
  int v354; // edi
  __int64 v355; // rsi
  int v356; // eax
  int v357; // eax
  __int64 v358; // rdi
  int v359; // r8d
  __m128 v360; // xmm2
  __m128 v361; // xmm1
  unsigned __int64 v362; // rax
  __m128 v363; // xmm3
  __m128 v364; // xmm4
  __m128 v365; // xmm1
  float v366; // xmm5_4
  unsigned __int64 v367; // rdx
  float v368; // xmm0_4
  unsigned __int64 v369; // rcx
  unsigned __int64 v370; // rax
  float v371; // xmm0_4
  unsigned __int64 v372; // rdx
  unsigned __int64 v373; // rcx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v374; // r8
  __int64 v375; // rdx
  __int64 v376; // rdi
  __int64 v377; // rcx
  __int64 v378; // rax
  __int64 v379; // rdi
  __int64 v380; // rcx
  __int64 v381; // rax
  __int16 v382; // di
  __int64 v383; // rdx
  int v384; // esi
  hkFixedInplaceArray<unsigned short,3> *p_m_tags; // rdi
  hkpBvCompressedMeshShape_Internals::GeometryProvider *m_provider; // rdi
  __int64 v387; // rdx
  hkArray<hkpBvCompressedMeshShape_Internals::PrimitiveData,hkContainerHeapAllocator> *m_primitiveData; // rax
  __int64 v389; // rdi
  __int64 v390; // rdx
  __int64 v391; // rdx
  unsigned int *v392; // rsi
  __int64 v393; // r14
  unsigned int v394; // r9d
  int v395; // edi
  unsigned int v396; // ebx
  int v397; // ebx
  unsigned int v398; // edi
  __int64 *v399; // rsi
  __int64 v400; // rdi
  _QWORD *v401; // r9
  __m128 v402; // xmm2
  __int64 v403; // r8
  unsigned __int64 v404; // rax
  __m128 v405; // xmm2
  __m128 v406; // xmm3
  __m128 v407; // xmm4
  __m128 v408; // xmm1
  float v409; // xmm5_4
  unsigned __int64 v410; // rdx
  float v411; // xmm0_4
  unsigned __int64 v412; // rcx
  unsigned __int64 v413; // rax
  float v414; // xmm0_4
  unsigned __int64 v415; // rdx
  unsigned __int64 v416; // rcx
  int v417; // eax
  __int64 v418; // rcx
  _WORD *v419; // r8
  char v420; // cl
  hkResult *v421; // rax
  int v422; // ecx
  _DWORD *v423; // rdi
  int v424; // esi
  int v425; // eax
  int v426; // eax
  int v427; // r9d
  int v428; // edi
  int v429; // eax
  int v430; // eax
  int v431; // r9d
  int v432; // eax
  int v433; // eax
  int v434; // r9d
  __int64 v435; // rcx
  int *v436; // rax
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v437; // r11
  int v438; // r10d
  int v439; // ecx
  int *v440; // rdx
  __int64 v441; // rax
  _QWORD *v442; // r9
  int v443; // edx
  int v444; // edi
  unsigned __int64 v445; // r8
  __int64 v446; // rdi
  __int64 v447; // r8
  int v448; // edi
  __int64 v449; // rdx
  unsigned __int8 v450; // al
  int v451; // r9d
  int *v452; // r8
  int *v453; // rdi
  __int64 v454; // rax
  int v455; // edx
  int v456; // r13d
  const void **v457; // rsi
  _DWORD *v458; // rdi
  int v459; // r8d
  __int64 v460; // rdx
  int *v461; // r9
  unsigned int v462; // edi
  int v463; // r10d
  __int64 v464; // rdx
  __int64 v465; // rcx
  __int64 v466; // r9
  __int64 v467; // r11
  __int64 v468; // rsi
  __int64 v469; // r8
  __int64 v470; // rdx
  __int64 v471; // rdi
  _BYTE *v472; // rcx
  int v473; // edx
  unsigned int *v474; // r13
  __int64 v475; // rdi
  int v476; // ecx
  int v477; // ecx
  int v478; // ecx
  int v479; // ecx
  int v480; // ecx
  int v481; // ecx
  int v482; // edi
  __int64 v483; // rdx
  int v484; // ecx
  int v485; // esi
  hkPointerMap<int,int,hkContainerHeapAllocator> *v486; // rdi
  int v488; // [rsp+30h] [rbp-D0h]
  int m_firstFree; // [rsp+30h] [rbp-D0h]
  __int16 v490; // [rsp+30h] [rbp-D0h]
  unsigned int v491; // [rsp+34h] [rbp-CCh]
  int v492; // [rsp+34h] [rbp-CCh]
  int v493; // [rsp+34h] [rbp-CCh]
  int v494; // [rsp+34h] [rbp-CCh]
  int v495; // [rsp+38h] [rbp-C8h]
  unsigned int v496; // [rsp+38h] [rbp-C8h]
  int v497; // [rsp+3Ch] [rbp-C4h]
  int v498; // [rsp+3Ch] [rbp-C4h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v499; // [rsp+40h] [rbp-C0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v500; // [rsp+40h] [rbp-C0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v501; // [rsp+40h] [rbp-C0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v502; // [rsp+40h] [rbp-C0h]
  int v503; // [rsp+48h] [rbp-B8h]
  __m128 *v504; // [rsp+50h] [rbp-B0h]
  __m128 *v505; // [rsp+50h] [rbp-B0h]
  __int64 v506; // [rsp+50h] [rbp-B0h]
  __int64 v507; // [rsp+50h] [rbp-B0h]
  signed int m_numLeaves; // [rsp+58h] [rbp-A8h]
  __int64 v509; // [rsp+60h] [rbp-A0h]
  __int64 v510; // [rsp+60h] [rbp-A0h]
  _WORD *v511; // [rsp+60h] [rbp-A0h]
  int primitiveIndex; // [rsp+68h] [rbp-98h]
  int primitiveIndexa; // [rsp+68h] [rbp-98h]
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v514; // [rsp+70h] [rbp-90h]
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v515; // [rsp+70h] [rbp-90h]
  char *v516; // [rsp+78h] [rbp-88h]
  const void **p_m_root; // [rsp+78h] [rbp-88h]
  int *v518; // [rsp+80h] [rbp-80h]
  int v519; // [rsp+88h] [rbp-78h]
  __m128 *v520; // [rsp+90h] [rbp-70h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *array; // [rsp+98h] [rbp-68h] BYREF
  int v522; // [rsp+A0h] [rbp-60h]
  int v523; // [rsp+A4h] [rbp-5Ch]
  __int64 v524; // [rsp+A8h] [rbp-58h] BYREF
  __int64 v525; // [rsp+B0h] [rbp-50h]
  __int64 v526; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v527; // [rsp+C0h] [rbp-40h]
  __int64 v528; // [rsp+C8h] [rbp-38h] BYREF
  __int64 v529; // [rsp+D0h] [rbp-30h]
  __int64 v530; // [rsp+D8h] [rbp-28h] BYREF
  __int64 v531; // [rsp+E0h] [rbp-20h]
  int v532; // [rsp+E8h] [rbp-18h]
  int v533; // [rsp+ECh] [rbp-14h]
  __m128i v534; // [rsp+F0h] [rbp-10h] BYREF
  hkResult v535[2]; // [rsp+100h] [rbp+0h] BYREF
  __int64 v536; // [rsp+108h] [rbp+8h]
  int v537; // [rsp+110h] [rbp+10h] BYREF
  int v538; // [rsp+114h] [rbp+14h] BYREF
  unsigned int v539; // [rsp+118h] [rbp+18h]
  int v540; // [rsp+11Ch] [rbp+1Ch] BYREF
  int v541; // [rsp+120h] [rbp+20h] BYREF
  int v542; // [rsp+124h] [rbp+24h]
  int v543; // [rsp+128h] [rbp+28h]
  int v544; // [rsp+130h] [rbp+30h] BYREF
  int v545; // [rsp+134h] [rbp+34h]
  int v546; // [rsp+138h] [rbp+38h]
  int v547; // [rsp+140h] [rbp+40h] BYREF
  int v548; // [rsp+144h] [rbp+44h]
  int v549; // [rsp+148h] [rbp+48h]
  int v550; // [rsp+150h] [rbp+50h] BYREF
  int v551; // [rsp+154h] [rbp+54h]
  int v552; // [rsp+158h] [rbp+58h]
  int v553; // [rsp+160h] [rbp+60h] BYREF
  int v554; // [rsp+164h] [rbp+64h]
  int v555; // [rsp+168h] [rbp+68h]
  int v556; // [rsp+170h] [rbp+70h] BYREF
  int v557; // [rsp+174h] [rbp+74h]
  int v558; // [rsp+178h] [rbp+78h]
  int v559; // [rsp+180h] [rbp+80h] BYREF
  int v560; // [rsp+184h] [rbp+84h]
  int v561; // [rsp+188h] [rbp+88h]
  int v562; // [rsp+190h] [rbp+90h] BYREF
  int v563; // [rsp+194h] [rbp+94h]
  int v564; // [rsp+198h] [rbp+98h]
  int v565; // [rsp+1A0h] [rbp+A0h] BYREF
  int v566; // [rsp+1A4h] [rbp+A4h]
  int v567; // [rsp+1A8h] [rbp+A8h]
  int v568; // [rsp+1B0h] [rbp+B0h] BYREF
  int v569; // [rsp+1B4h] [rbp+B4h]
  int v570; // [rsp+1B8h] [rbp+B8h]
  int v571; // [rsp+1C0h] [rbp+C0h] BYREF
  int v572; // [rsp+1C4h] [rbp+C4h]
  int v573; // [rsp+1C8h] [rbp+C8h]
  int v574; // [rsp+1D0h] [rbp+D0h] BYREF
  int v575; // [rsp+1D4h] [rbp+D4h]
  int v576; // [rsp+1D8h] [rbp+D8h]
  int v577; // [rsp+1E0h] [rbp+E0h] BYREF
  int v578; // [rsp+1E4h] [rbp+E4h]
  int v579; // [rsp+1E8h] [rbp+E8h]
  int v580; // [rsp+1F0h] [rbp+F0h] BYREF
  int v581; // [rsp+1F4h] [rbp+F4h]
  int v582; // [rsp+1F8h] [rbp+F8h]
  int v583; // [rsp+200h] [rbp+100h] BYREF
  int v584; // [rsp+204h] [rbp+104h]
  int v585; // [rsp+208h] [rbp+108h]
  int v586; // [rsp+210h] [rbp+110h] BYREF
  int v587; // [rsp+214h] [rbp+114h]
  int v588; // [rsp+218h] [rbp+118h]
  hkcdStaticMeshTreeBase::BuildCustomInfos v589; // [rsp+220h] [rbp+120h] BYREF
  unsigned int *v590; // [rsp+260h] [rbp+160h]
  void *v591; // [rsp+268h] [rbp+168h]
  __int64 v592; // [rsp+270h] [rbp+170h]
  __int64 v593; // [rsp+278h] [rbp+178h]
  __int64 v594; // [rsp+280h] [rbp+180h]
  __int64 v595; // [rsp+288h] [rbp+188h]
  hkResult v596; // [rsp+290h] [rbp+190h] BYREF
  hkResult v597; // [rsp+294h] [rbp+194h] BYREF
  unsigned int v598; // [rsp+298h] [rbp+198h]
  unsigned __int64 v599; // [rsp+2A0h] [rbp+1A0h]
  int v600; // [rsp+2A8h] [rbp+1A8h]
  hkResult v601; // [rsp+2ACh] [rbp+1ACh] BYREF
  hkResult v602; // [rsp+2B0h] [rbp+1B0h] BYREF
  hkResult v603; // [rsp+2B4h] [rbp+1B4h] BYREF
  hkResult v604; // [rsp+2B8h] [rbp+1B8h] BYREF
  unsigned __int64 *v605; // [rsp+2C0h] [rbp+1C0h]
  hkResult v606; // [rsp+2C8h] [rbp+1C8h] BYREF
  hkResult v607; // [rsp+2CCh] [rbp+1CCh] BYREF
  hkResult result; // [rsp+2D0h] [rbp+1D0h] BYREF
  hkResult v609; // [rsp+2D4h] [rbp+1D4h] BYREF
  hkResult v610; // [rsp+2D8h] [rbp+1D8h] BYREF
  hkResult v611; // [rsp+2DCh] [rbp+1DCh] BYREF
  hkResult v612; // [rsp+2E0h] [rbp+1E0h] BYREF
  __m128 v613; // [rsp+2F0h] [rbp+1F0h]
  int v614; // [rsp+300h] [rbp+200h]
  hkResult v615; // [rsp+304h] [rbp+204h] BYREF
  int *v616; // [rsp+308h] [rbp+208h]
  __m128 v617; // [rsp+310h] [rbp+210h]
  __int64 v618; // [rsp+320h] [rbp+220h]
  __m128 v619; // [rsp+330h] [rbp+230h]
  __m128 v620; // [rsp+340h] [rbp+240h]
  __int64 v621; // [rsp+350h] [rbp+250h]
  __m128 v622; // [rsp+360h] [rbp+260h]
  unsigned __int64 out[2]; // [rsp+370h] [rbp+270h] BYREF
  __int64 v624; // [rsp+380h] [rbp+280h]
  hkResult v625; // [rsp+388h] [rbp+288h] BYREF
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree dTree; // [rsp+390h] [rbp+290h] BYREF
  __m128 v627; // [rsp+3C0h] [rbp+2C0h]
  __m128i v628; // [rsp+3D0h] [rbp+2D0h]
  __m128 v629; // [rsp+3E0h] [rbp+2E0h]
  __m128 v630; // [rsp+3F0h] [rbp+2F0h]
  hkcdStaticMeshTreeBase::BuildCustomInfos v631; // [rsp+400h] [rbp+300h] BYREF
  hkcdStaticMeshTreeBase::BuildCustomInfos customPrimitive; // [rsp+440h] [rbp+340h] BYREF
  __m128 v633; // [rsp+480h] [rbp+380h] BYREF
  hkErrStream v634; // [rsp+490h] [rbp+390h] BYREF
  __m128 v635; // [rsp+4B0h] [rbp+3B0h] BYREF
  __m128 v636; // [rsp+4C0h] [rbp+3C0h]
  __m128 v637; // [rsp+4D0h] [rbp+3D0h]
  __m128 v638; // [rsp+4E0h] [rbp+3E0h] BYREF
  __m128 v639[2]; // [rsp+4F0h] [rbp+3F0h] BYREF
  __m128 v640; // [rsp+510h] [rbp+410h]
  __m128 v641; // [rsp+520h] [rbp+420h]
  __m128 v642; // [rsp+530h] [rbp+430h]
  __m128 v643; // [rsp+540h] [rbp+440h] BYREF
  __m128 v644; // [rsp+550h] [rbp+450h] BYREF
  char v645[16]; // [rsp+560h] [rbp+460h] BYREF
  hkAabb aabb; // [rsp+570h] [rbp+470h] BYREF
  __m128 v647; // [rsp+590h] [rbp+490h]
  __m128i v648; // [rsp+5A0h] [rbp+4A0h]
  __m128 v649; // [rsp+5B0h] [rbp+4B0h]
  __m128 v650; // [rsp+5C0h] [rbp+4C0h]
  __m128 v651; // [rsp+5D0h] [rbp+4D0h]
  __m128 v652; // [rsp+5E0h] [rbp+4E0h]
  __m128 v653; // [rsp+5F0h] [rbp+4F0h]
  __m128i v654; // [rsp+600h] [rbp+500h]
  __m128i v655; // [rsp+610h] [rbp+510h]
  __m128i v656; // [rsp+620h] [rbp+520h]
  __m128 v657; // [rsp+630h] [rbp+530h]
  __m128 v658; // [rsp+640h] [rbp+540h]
  __m128 v659; // [rsp+650h] [rbp+550h]
  __m128 v660; // [rsp+660h] [rbp+560h]
  __m128 v661; // [rsp+670h] [rbp+570h]
  int pArr[128]; // [rsp+680h] [rbp+580h] BYREF
  int v663; // [rsp+880h] [rbp+780h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DataSorter cmpLess; // [rsp+890h] [rbp+790h] BYREF
  int v665; // [rsp+A90h] [rbp+990h]
  int v666[129]; // [rsp+A9Ch] [rbp+99Ch]
  int v667; // [rsp+CA0h] [rbp+BA0h]
  int v668[128]; // [rsp+CB0h] [rbp+BB0h] BYREF
  int v669; // [rsp+EB0h] [rbp+DB0h]
  int v670[256]; // [rsp+EC0h] [rbp+DC0h] BYREF
  int v671; // [rsp+12C0h] [rbp+11C0h]
  char buf[512]; // [rsp+12D0h] [rbp+11D0h] BYREF

  v9 = mapping;
  m_size = mapping->m_triangleIndexToKey.m_size;
  v519 = m_size;
  v11 = qInfos;
  v12 = ((__int64 (*)(void))qInfos->m_provider->m_meshCInfo->vfptr->getNumTriangles)();
  v13 = quads;
  v14 = 0;
  v15 = 0;
  v503 = m_size + v12;
  if ( quads->m_size > 0 )
  {
    v16 = 0i64;
    while ( *(_DWORD *)v13->m_data[v16 + 1].m_edges < 128 )
    {
      v17 = (hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *)v9;
      v18 = roots;
      if ( hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree::countVertices<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
             (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *)&v13->m_data[2 * v15],
             roots,
             v11,
             v17) >= 256 )
      {
        v13 = quads;
LABEL_6:
        m_data = v18->m_nodes.m_data;
        m_value_low = LODWORD(v13->m_data[v16].m_value);
        v21 = *(_QWORD *)v13->m_data[v16].m_edges << 6;
        v617.m128_i32[2] = m_value_low;
        v22 = 0;
        v23 = (char *)m_data + v21;
        v24 = *((_QWORD *)v23 + 6);
        if ( v24 )
        {
          if ( LODWORD(m_data[v24].m_children[0]) )
          {
            v25 = m_data[v24].m_children[0];
            if ( v25 )
            {
              do
              {
                v26 = v25 << 6;
                v27 = m_data[v25].m_children[0];
                v22 += v27 == 0;
                if ( v27 )
                {
                  v25 = *(unsigned __int64 *)((char *)m_data->m_children + v26);
                }
                else
                {
                  m_parent = *(unsigned __int64 *)((char *)&m_data->m_parent + v26);
                  for ( i = v25; m_parent != v24; m_parent = m_data[m_parent].m_parent )
                  {
                    if ( m_data[m_parent].m_children[1] != i )
                      break;
                    i = m_parent;
                  }
                  if ( m_parent )
                    v25 = m_data[m_parent].m_children[1];
                  else
                    v25 = i;
                  if ( m_parent == v24 && v25 == i )
                    v25 = 0i64;
                }
              }
              while ( v25 );
              v11 = qInfos;
              v18 = roots;
            }
          }
          else
          {
            v22 = 1;
          }
        }
        m_capacityAndFlags = v13->m_capacityAndFlags;
        v617.m128_i32[3] = v22;
        LODWORD(v618) = -1;
        if ( v13->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v13->m_data, 24);
          v13 = quads;
        }
        v31 = &v13->m_data[2 * v13->m_size];
        if ( v31 )
        {
          v32 = v617.m128_u64[1];
          *(_QWORD *)v31->m_edges = v24;
          *(_QWORD *)&v31->m_value = v32;
          *(_QWORD *)&v31[1].m_edges[1] = v618;
        }
        ++v13->m_size;
        v33 = *((_QWORD *)v23 + 5);
        v620.m128_i32[2] = m_value_low;
        v14 = 0;
        v34 = 0;
        if ( v33 )
        {
          v35 = v18->m_nodes.m_data;
          if ( LODWORD(v18->m_nodes.m_data[v33].m_children[0]) )
          {
            v36 = v35[v33].m_children[0];
            while ( v36 )
            {
              v37 = v36 << 6;
              v38 = v35[v36].m_children[0];
              v34 += v38 == 0;
              if ( v38 )
              {
                v36 = *(unsigned __int64 *)((char *)v35->m_children + v37);
              }
              else
              {
                v39 = *(unsigned __int64 *)((char *)&v35->m_parent + v37);
                for ( j = v36; v39 != v33; v39 = v35[v39].m_parent )
                {
                  if ( v35[v39].m_children[1] != j )
                    break;
                  j = v39;
                }
                if ( v39 )
                  v36 = v35[v39].m_children[1];
                else
                  v36 = j;
                if ( v39 == v33 && v36 == j )
                  v36 = 0i64;
              }
            }
          }
          else
          {
            v34 = 1;
          }
        }
        v620.m128_i32[3] = v34;
        v13 = quads;
        v41 = quads->m_data;
        LODWORD(v621) = -1;
        v42 = v620.m128_u64[1];
        *(_QWORD *)v41[v16].m_edges = v33;
        *(_QWORD *)&v41[v16].m_value = v42;
        *(_QWORD *)&v41[v16 + 1].m_edges[1] = v621;
        --v15;
        v16 -= 2i64;
        goto LABEL_47;
      }
      v13 = quads;
LABEL_47:
      v9 = mapping;
      ++v15;
      v16 += 2i64;
      if ( v15 >= v13->m_size )
        goto LABEL_48;
    }
    v18 = roots;
    goto LABEL_6;
  }
LABEL_48:
  v43 = v13->m_size;
  p_m_numLeaves = (void **)&masterTree[1].m_numLeaves;
  v45 = HIDWORD(masterTree[1].m_root) & 0x3FFFFFFF;
  v590 = &masterTree[1].m_numLeaves;
  if ( v45 >= (int)v43 )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v46 = 2 * v45;
    v47 = v43;
    if ( (int)v43 < v46 )
      v47 = v46;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&masterTree[1].m_numLeaves,
      v47,
      96);
  }
  v48 = LODWORD(masterTree[1].m_root) - v43 - 1;
  v49 = v48;
  if ( v48 >= 0 )
  {
    v50 = (int *)((char *)*p_m_numLeaves + 96 * v43 + 96 * v48 + 12);
    do
    {
      *(v50 - 1) = 0;
      if ( *v50 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v50 - 3),
          4 * *v50);
      *(_QWORD *)(v50 - 3) = 0i64;
      *v50 = 0x80000000;
      v50 -= 24;
      --v49;
    }
    while ( v49 >= 0 );
  }
  m_root_low = SLODWORD(masterTree[1].m_root);
  v52 = (int)v43 - (int)m_root_low;
  if ( (int)v43 - (int)m_root_low > 0 )
  {
    v53 = (__int64)*p_m_numLeaves + 96 * m_root_low + 8;
    do
    {
      if ( v53 != 8 )
      {
        *(_QWORD *)(v53 - 8) = 0i64;
        *(_DWORD *)v53 = 0;
        *(_DWORD *)(v53 + 4) = 0x80000000;
        *(_OWORD *)(v53 + 8) = xmmword_141A712A0;
        *(__m128 *)(v53 + 24) = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                  *(__m128 *)(v53 + 8));
      }
      v53 += 96i64;
      --v52;
    }
    while ( v52 );
  }
  LODWORD(masterTree[1].m_root) = v43;
  hkString::memSet(*p_m_numLeaves, 0, 96 * LODWORD(masterTree[1].m_root));
  v54 = 0;
  v497 = 0;
  v55 = 0;
  v488 = 0;
  v495 = 0;
  v56 = v11->vfptr->getNumVertices(v11);
  v57 = v56;
  v598 = v56;
  if ( v56 )
  {
    v537 = 8 * v56;
    v58 = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v537);
    v56 = v537 / 8;
  }
  else
  {
    v58 = 0i64;
  }
  v59 = 0x80000000;
  v518 = v58;
  if ( v56 )
    v59 = v56;
  v60 = v57;
  v600 = v59;
  if ( (int)v57 > 0 )
  {
    v61 = v58;
    do
    {
      if ( v61 )
        *(_QWORD *)v61 = -1i64;
      v61 += 2;
      --v60;
    }
    while ( v60 );
  }
  v62 = quads;
  v63 = &roots->m_nodes.m_data[roots->m_root];
  m_quad = v63->m_aabb.m_min.m_quad;
  v617 = v63->m_aabb.m_max.m_quad;
  v629 = m_quad;
  v613 = m_quad;
  v619 = _mm_sub_ps(v617, m_quad);
  v630 = _mm_mul_ps(
           v619,
           (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  v65 = quads->m_size;
  v66 = v65;
  if ( (_DWORD)v65 )
  {
    v538 = 2096 * v65;
    v67 = (__m128 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v538);
    v62 = quads;
    v68 = v67;
    LODWORD(v65) = v538 / 2096;
  }
  else
  {
    v68 = 0i64;
  }
  v69 = 0x80000000;
  v520 = v68;
  if ( (_DWORD)v65 )
    v69 = v65;
  v70 = v66;
  v614 = v69;
  if ( (int)v66 > 0 )
  {
    v71 = &v68[130].m128_i32[2];
    do
    {
      if ( v71 != (int *)2088 )
      {
        *(v71 - 258) = 0;
        *v71 = 0;
      }
      v71 += 524;
      --v70;
    }
    while ( v70 );
  }
  v72 = this;
  v73 = 0i64;
  v74 = 0;
  array = 0i64;
  v522 = 0;
  v523 = 0x80000000;
  if ( *(_DWORD *)&this[12] == 2 )
  {
    v75 = v62->m_size;
    if ( (int)v75 <= 0 )
    {
      v602.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v602, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v75, 16);
      v74 = v522;
      v73 = array;
    }
    v76 = v74 - v75 - 1;
    if ( v76 >= 0 )
    {
      v77 = &v73[v75 + v76];
      do
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          v77--,
          &hkContainerHeapAllocator::s_alloc);
        --v76;
      }
      while ( v76 >= 0 );
      v74 = v522;
      v73 = array;
      v54 = 0;
    }
    v78 = &v73[v74];
    v79 = v75 - v74;
    v80 = (int)v75 - v74;
    if ( v79 > 0 )
    {
      do
      {
        if ( v78 )
        {
          v78->m_elem = 0i64;
          v78->m_numElems = 0;
          v78->m_hashMod = -1;
        }
        ++v78;
        --v80;
      }
      while ( v80 );
      v55 = 0;
    }
    v72 = this;
    v522 = v75;
  }
  v81 = quads;
  v82 = 0;
  v491 = 0;
  v83 = 0;
  v84 = FLOAT_2047_0;
  if ( quads->m_size > 0 )
  {
    v85 = 0i64;
    v86 = v520 + 66;
    v504 = v520 + 66;
    v516 = 0i64;
    while ( 1 )
    {
      v87 = *(_QWORD *)&v85[(unsigned __int64)v81->m_data];
      v88 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *)roots->m_nodes.m_data;
      v89 = roots->m_nodes.m_data[v87].m_aabb.m_min.m_quad;
      v90 = roots->m_nodes.m_data[v87].m_aabb.m_max.m_quad;
      if ( v87 )
      {
        v91 = v87 << 6;
        if ( !*(&v88[1].m_numVertices + 16 * v87) )
        {
          v99 = v86[64].m128_i32[2];
          v86[64].m128_i32[2] = v99 + 1;
          v86->m128_u64[v99 + 1] = v87;
          v100 = *(unsigned __int64 *)((char *)&roots->m_nodes.m_data->m_children[1] + v91);
          v101 = v86->m128_i32[0];
          v86->m128_i32[0] = v101 + 1;
          v86[-64].m128_u64[v101] = v100;
LABEL_119:
          v85 = v516;
          goto LABEL_120;
        }
        v92 = *(_QWORD *)((char *)&v88[1].m_numVertices + v91);
        if ( v92 )
        {
          do
          {
            v93 = v92 << 6;
            if ( !*(&v88[1].m_numVertices + 16 * v92) )
            {
              v94 = v86[64].m128_i32[2];
              v86[64].m128_i32[2] = v94 + 1;
              v86->m128_u64[v94 + 1] = v92;
              v95 = *(unsigned __int64 *)((char *)&roots->m_nodes.m_data->m_children[1] + v93);
              v96 = v86->m128_i32[0];
              v86->m128_i32[0] = v96 + 1;
              v86[-64].m128_u64[v96] = v95;
            }
            v88 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *)roots->m_nodes.m_data;
            if ( *(_DWORD *)((char *)roots->m_nodes.m_data->m_children + v93) )
            {
              v92 = *(_QWORD *)((char *)&v88[1].m_numVertices + v93);
            }
            else
            {
              v97 = *(_QWORD *)((char *)&v88[1].m_layer + v93);
              for ( k = v92; v97 != v87; v97 = *((_QWORD *)&v88[1].m_layer + 8 * v97) )
              {
                if ( *(&v88[2].m_node + 8 * v97) != k )
                  break;
                k = v97;
              }
              if ( v97 )
                v92 = *(&v88[2].m_node + 8 * v97);
              else
                v92 = k;
              if ( v97 == v87 && v92 == k )
                v92 = 0i64;
              v86 = v504;
            }
          }
          while ( v92 );
          v14 = v495;
          v11 = qInfos;
          goto LABEL_119;
        }
      }
LABEL_120:
      v509 = v86->m128_i32[0];
      v497 = v86->m128_i32[0] + v54;
      v102 = v509;
      if ( v86->m128_i32[0] <= 0 )
        goto LABEL_149;
      v103 = v503;
      v104 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v86[-64];
      v499 = v104;
      do
      {
        v105 = LODWORD(v104->m_elem) - v103;
        if ( v105 >= 0 )
        {
          customPrimitive.m_tags.m_size = 0;
          *(_QWORD *)&customPrimitive.m_numVertices = 0i64;
          customPrimitive.m_layerData = 0;
          customPrimitive.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
          customPrimitive.m_maxError = 3.40282e38;
          customPrimitive.m_compression = CM_LOCAL_4;
          customPrimitive.m_aabb.m_max.m_quad = _mm_xor_ps(
                                                  (__m128)_mm_shuffle_epi32(
                                                            _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                            0),
                                                  (__m128)xmmword_141A712A0);
          hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(
            v11->m_provider,
            v105,
            &customPrimitive);
          v55 += customPrimitive.m_numVertices;
          v488 = v55;
          goto LABEL_146;
        }
        if ( *(_DWORD *)&v72[12] != 2 )
        {
          v530 = 0i64;
          v531 = 0i64;
          m_elem_low = SLODWORD(v104->m_elem);
          if ( (int)m_elem_low < v519 )
          {
            v107 = mapping->m_triangleIndexToKey.m_data;
            v108 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *)qInfos;
            v109 = 3 * m_elem_low;
            v110 = mapping->m_triangleIndexToKey.m_data[3 * m_elem_low];
            qInfos->m_provider->m_meshCInfo->vfptr->getIndices(
              qInfos->m_provider->m_meshCInfo,
              v110 & 0x3FFFFFFF,
              &v553);
            v553 = qInfos->m_vMap.m_data[v553];
            v554 = qInfos->m_vMap.m_data[v554];
            v555 = qInfos->m_vMap.m_data[v555];
            LODWORD(v530) = *(&v553 + (int)((v110 >> 30) + 1) % 3);
            v111 = v107[v109];
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v108->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v108->m_size[2] + 8i64),
              v111 & 0x3FFFFFFF,
              &v571);
            v571 = qInfos->m_vMap.m_data[v571];
            v572 = qInfos->m_vMap.m_data[v572];
            v573 = qInfos->m_vMap.m_data[v573];
            HIDWORD(v530) = *(&v571 + (int)((v111 >> 30) + 2) % 3);
            v112 = (int)((v107[v109 + 1] >> 30) + 1) % 3;
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v108->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v108->m_size[2] + 8i64),
              v107[v109 + 1] & 0x3FFFFFFF,
              &v559);
            v559 = qInfos->m_vMap.m_data[v559];
            v560 = qInfos->m_vMap.m_data[v560];
            v561 = qInfos->m_vMap.m_data[v561];
            LODWORD(v531) = *(&v559 + v112);
            v113 = v107[v109 + 1];
            v11 = qInfos;
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v108->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v108->m_size[2] + 8i64),
              v113 & 0x3FFFFFFF,
              &v583);
            v583 = qInfos->m_vMap.m_data[v583];
            v584 = qInfos->m_vMap.m_data[v584];
            v585 = qInfos->m_vMap.m_data[v585];
            HIDWORD(v531) = *(&v583 + (int)((v113 >> 30) + 2) % 3);
          }
          else
          {
            v11->m_provider->m_meshCInfo->vfptr->getIndices(
              v11->m_provider->m_meshCInfo,
              m_elem_low - mapping->m_triangleIndexToKey.m_size,
              (int *)&v530);
            LODWORD(v530) = v11->m_vMap.m_data[(int)v530];
            HIDWORD(v530) = v11->m_vMap.m_data[SHIDWORD(v530)];
            LODWORD(v531) = v11->m_vMap.m_data[(int)v531];
            HIDWORD(v531) = v531;
          }
          v58 = v518;
          v114 = &v530;
          v115 = 4i64;
          while ( 1 )
          {
            v116 = *(int *)v114;
            v117 = v116;
            if ( v518[2 * v116] != -2 )
              break;
LABEL_144:
            v114 = (__int64 *)((char *)v114 + 4);
            if ( !--v115 )
            {
              v55 = v488;
              v104 = v499;
              v102 = v509;
              v495 = v14;
LABEL_146:
              v103 = v503;
              v72 = this;
              goto LABEL_147;
            }
          }
          v118 = this;
          if ( *(_DWORD *)&this[12] == 1 )
          {
            v518[2 * v116] = v83 + 1;
            goto LABEL_135;
          }
          if ( this[4] )
          {
            v11->vfptr->getVertex(v11, v116, (hkVector4f *)v645);
            v118 = this;
            if ( (v645[12] & 1) != 0 )
            {
              v518[2 * v117] = v83 + 1;
LABEL_135:
              ++v14;
            }
          }
          v119 = v518[2 * v117];
          if ( v119 != -1 )
            goto LABEL_142;
          if ( *(float *)&v118[40] < 3.40282e38 )
          {
            v11->vfptr->getVertex(v11, *(_DWORD *)v114, (hkVector4f *)&v635);
            v120 = _mm_sub_ps(v90, v89);
            v121 = _mm_max_ps(v120, aabbOut.m_quad);
            v122 = _mm_rcp_ps(v121);
            v652 = v121;
            v123 = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmpeq_ps((__m128)0i64, v121),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v122, v121)), v122)),
                     _mm_sub_ps(v635, v89));
            v124 = _mm_cmplt_ps(v123, query.m_quad);
            v125 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v124, query.m_quad), _mm_and_ps(v124, v123)));
            v126 = (int)(float)((float)(v125.m128_f32[0] * 2047.0) + 0.5) | (((int)(float)((float)(_mm_shuffle_ps(
                                                                                                     v125,
                                                                                                     v125,
                                                                                                     85).m128_f32[0]
                                                                                                 * 2047.0)
                                                                                         + 0.5) | ((int)(float)((float)(_mm_shuffle_ps(v125, v125, 170).m128_f32[0] * 1023.0) + 0.5) << 11)) << 11);
            v127 = (__m128)COERCE_UNSIGNED_INT((float)((int)(float)((float)(v125.m128_f32[0] * 2047.0) + 0.5) & 0x7FF));
            v127.m128_f32[0] = v127.m128_f32[0] * 0.00048851978;
            v128 = (__m128)COERCE_UNSIGNED_INT((float)(v126 >> 22));
            v129 = (__m128)COERCE_UNSIGNED_INT((float)((v126 >> 11) & 0x7FF));
            v128.m128_f32[0] = v128.m128_f32[0] * 0.00097751711;
            v129.m128_f32[0] = v129.m128_f32[0] * 0.00048851978;
            v130 = _mm_sub_ps(
                     v635,
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_unpacklo_ps(_mm_unpacklo_ps(v127, v128), _mm_unpacklo_ps(v129, (__m128)0i64)),
                         v120),
                       v89));
            v131 = _mm_mul_ps(v130, v130);
            v132 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v131, v131, 85), _mm_shuffle_ps(v131, v131, 0)),
                     _mm_shuffle_ps(v131, v131, 170));
            v647 = v132;
            if ( (float)(_mm_andnot_ps(_mm_cmple_ps(v132, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v132))).m128_f32[0]
                       * v132.m128_f32[0]) > *(float *)&this[40] )
            {
              ++v491;
              ++v14;
              v518[2 * v117] = v83 + 1;
            }
          }
          v119 = v518[2 * v117];
          if ( v119 == -1 )
          {
            ++v14;
            v518[2 * v117] = v83;
          }
          else
          {
LABEL_142:
            if ( v119 != v83 )
            {
              --v14;
              ++v488;
              v518[2 * v117] = -2;
            }
          }
          goto LABEL_144;
        }
LABEL_147:
        v104 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)v104 + 8);
        v509 = --v102;
        v499 = v104;
      }
      while ( v102 );
      v86 = v504;
      v85 = v516;
LABEL_149:
      v81 = quads;
      v54 = v497;
      v85 += 24;
      v86 += 131;
      ++v83;
      v516 = v85;
      v504 = v86;
      if ( v83 >= quads->m_size )
      {
        m_quad = v613;
        v84 = FLOAT_2047_0;
        v82 = v491;
        break;
      }
    }
  }
  if ( (*(_BYTE *)&v72[20] & 1) != 0 && v82 )
  {
    hkErrStream::hkErrStream(&v634, buf, 512);
    v133 = hkOstream::operator<<(&v634, "Promoted ");
    v134 = hkOstream::operator<<(v133, v82);
    hkOstream::operator<<(v134, " vertices in order to comply with compression error constraint.");
    hkError::messageReport(0, buf, 0i64, 0);
    hkOstream::~hkOstream(&v634);
  }
  v135 = quads;
  v492 = 0;
  if ( quads->m_size > 0 )
  {
    v136 = v590;
    v137 = v520 + 2;
    v138 = 0;
    v505 = v520 + 2;
    v139 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v140 = v137[64].m128_i32[0];
      v141 = (__m128)xmmword_141A712A0;
      v500 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v140;
      v142 = (char *)(*(_QWORD *)v136 + 96i64 * v138);
      v143 = _mm_xor_ps((__m128)xmmword_141A712A0, v139);
      v591 = v142;
      if ( v140 > 0 )
      {
        v144 = v137;
        v145 = v503;
        do
        {
          if ( v144->m128_i32[0] - v145 < 0 )
          {
            v528 = 0i64;
            v529 = 0i64;
            v146 = v144->m128_i32[0];
            if ( (int)v146 < v519 )
            {
              v147 = mapping->m_triangleIndexToKey.m_data;
              v148 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *)qInfos;
              v149 = 3 * v146;
              v150 = mapping->m_triangleIndexToKey.m_data[3 * v146];
              qInfos->m_provider->m_meshCInfo->vfptr->getIndices(
                qInfos->m_provider->m_meshCInfo,
                v150 & 0x3FFFFFFF,
                &v541);
              v541 = qInfos->m_vMap.m_data[v541];
              v542 = qInfos->m_vMap.m_data[v542];
              v543 = qInfos->m_vMap.m_data[v543];
              LODWORD(v528) = *(&v541 + (int)((v150 >> 30) + 1) % 3);
              v151 = v147[v149];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v148->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v148->m_size[2] + 8i64),
                v151 & 0x3FFFFFFF,
                &v565);
              v565 = qInfos->m_vMap.m_data[v565];
              v566 = qInfos->m_vMap.m_data[v566];
              v567 = qInfos->m_vMap.m_data[v567];
              HIDWORD(v528) = *(&v565 + (int)((v151 >> 30) + 2) % 3);
              v152 = (int)((v147[v149 + 1] >> 30) + 1) % 3;
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v148->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v148->m_size[2] + 8i64),
                v147[v149 + 1] & 0x3FFFFFFF,
                &v544);
              v544 = qInfos->m_vMap.m_data[v544];
              v545 = qInfos->m_vMap.m_data[v545];
              v546 = qInfos->m_vMap.m_data[v546];
              LODWORD(v529) = *(&v544 + v152);
              v153 = v147[v149 + 1];
              v11 = qInfos;
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v148->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v148->m_size[2] + 8i64),
                v153 & 0x3FFFFFFF,
                &v547);
              v547 = qInfos->m_vMap.m_data[v547];
              v548 = qInfos->m_vMap.m_data[v548];
              v140 = (__int64)v500;
              v549 = qInfos->m_vMap.m_data[v549];
              HIDWORD(v529) = *(&v547 + (int)((v153 >> 30) + 2) % 3);
            }
            else
            {
              v11->m_provider->m_meshCInfo->vfptr->getIndices(
                v11->m_provider->m_meshCInfo,
                v146 - mapping->m_triangleIndexToKey.m_size,
                (int *)&v528);
              LODWORD(v528) = v11->m_vMap.m_data[(int)v528];
              HIDWORD(v528) = v11->m_vMap.m_data[SHIDWORD(v528)];
              LODWORD(v529) = v11->m_vMap.m_data[(int)v529];
              HIDWORD(v529) = v529;
            }
            v58 = v518;
            v154 = &v528;
            v155 = 4i64;
            do
            {
              v156 = *(int *)v154;
              if ( v518[2 * v156] != -2 )
              {
                v11->vfptr->getVertex(v11, v156, (hkVector4f *)v639);
                v141 = _mm_min_ps(v141, v639[0]);
                v143 = _mm_max_ps(v143, v639[0]);
              }
              v154 = (__int64 *)((char *)v154 + 4);
              --v155;
            }
            while ( v155 );
            v145 = v503;
          }
          v144 = (__m128 *)((char *)v144 + 8);
          v500 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)--v140;
        }
        while ( v140 );
        v142 = (char *)v591;
        v137 = v505;
        v138 = v492;
        v135 = quads;
        v136 = v590;
      }
      v137[-2] = v141;
      v137[-1] = v143;
      v639[1] = v141;
      ++v138;
      v137 += 131;
      v492 = v138;
      v505 = v137;
      v640 = _mm_mul_ps(
               _mm_sub_ps(v143, v141),
               (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
      *((__m128 *)v142 + 3) = v141;
      *(_QWORD *)(v142 + 60) = v640.m128_u64[0];
      *((_DWORD *)v142 + 17) = _mm_movehl_ps(v640, v640).m128_u32[0];
    }
    while ( v138 < v135->m_size );
    v14 = v495;
    v55 = v488;
  }
  v157 = masterTree;
  v158 = v497;
  v159 = masterTree[2].m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
  v591 = &masterTree[2];
  if ( v159 >= v497 )
  {
    v615.m_enum = HK_SUCCESS;
  }
  else
  {
    v160 = 2 * v159;
    if ( v497 < v160 )
      v158 = v160;
    hkArrayUtil::_reserve(
      &v615,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&masterTree[2].m_nodes.m_data,
      v158,
      4);
  }
  v161 = 4 * v55;
  p_m_firstFree = &masterTree[2].m_firstFree;
  v163 = masterTree[2].m_path & 0x3FFFFFFF;
  v605 = &masterTree[2].m_firstFree;
  if ( v163 >= v161 )
  {
    v604.m_enum = HK_SUCCESS;
  }
  else
  {
    v164 = 2 * v163;
    if ( v161 < v164 )
      v161 = v164;
    hkArrayUtil::_reserve(&v604, &hkContainerHeapAllocator::s_alloc, (const void **)&masterTree[2].m_firstFree, v161, 2);
  }
  v165 = v488;
  p_m_size = &masterTree[3].m_nodes.m_size;
  m_firstFree_high = HIDWORD(masterTree[3].m_firstFree);
  v616 = &masterTree[3].m_nodes.m_size;
  v168 = m_firstFree_high & 0x3FFFFFFF;
  if ( v168 >= v488 )
  {
    v612.m_enum = HK_SUCCESS;
  }
  else
  {
    v169 = 2 * v168;
    if ( v488 < v169 )
      v165 = v169;
    hkArrayUtil::_reserve(
      &v612,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&masterTree[3].m_nodes.m_size,
      v165,
      8);
  }
  v170 = HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF;
  p_m_root = (const void **)&masterTree[2].m_root;
  if ( v170 >= v14 )
  {
    v606.m_enum = HK_SUCCESS;
  }
  else
  {
    v171 = 2 * v170;
    if ( v14 < v171 )
      v14 = v171;
    hkArrayUtil::_reserve(&v606, &hkContainerHeapAllocator::s_alloc, (const void **)&masterTree[2].m_root, v14, 4);
  }
  v172 = FLOAT_4194303_0;
  v173 = 0;
  v493 = 0;
  v174 = FLOAT_2097151_0;
  if ( v135->m_size > 0 )
  {
    v175 = v520;
    v176 = v619;
    v177 = 0i64;
    v178 = 0i64;
    v179 = 0i64;
    v180 = -(__int64)v520;
    v514 = 0i64;
    v506 = 0i64;
    v593 = -(__int64)v520;
    v181 = v520;
    do
    {
      v182 = *(_QWORD *)v590;
      v627 = v178;
      v628 = (__m128i)v178;
      v627 = *(__m128 *)(v179 + v182 + 48);
      v628 = _mm_srli_si128(
               _mm_slli_si128(
                 (__m128i)_mm_movelh_ps(
                            (__m128)*(unsigned __int64 *)(v179 + v182 + 60),
                            (__m128)*(unsigned int *)(v179 + v182 + 68)),
                 4),
               4);
      v183 = v181[66].m128_i32[0];
      *(_BYTE *)(v179 + v182 + 88) = 0;
      v184 = (int)masterTree[3].m_nodes.m_data;
      *(_QWORD *)&v535[0].m_enum = v183;
      *(_DWORD *)(v179 + v182 + 72) = v184;
      if ( (int)v183 > 0 )
      {
        v185 = v180 - 1032;
        v186 = roots;
        v187 = &v181[66].m128_u64[1];
        v188 = (__int64)v175 + v185;
        v592 = (__int64)&v181[66].m128_i64[1];
        v595 = v188;
        do
        {
          p_m_quad = &v186->m_nodes.m_data[*v187].m_aabb.m_min.m_quad;
          v190 = *(_DWORD *)((char *)v187 + v188) - v503;
          v191 = *p_m_quad;
          v192 = p_m_quad[1];
          if ( v190 >= 0 )
          {
            *(_QWORD *)&v631.m_numVertices = 0i64;
            v631.m_layerData = 0;
            v631.m_tags.m_size = 0;
            v631.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
            v631.m_maxError = 3.40282e38;
            v631.m_compression = CM_LOCAL_4;
            v631.m_aabb.m_max.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         (__m128)xmmword_141A712A0);
            hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(v11->m_provider, v190, &v631);
            if ( v631.m_numVertices > 0 )
            {
              v233 = (__m128)_xmm;
              v234 = 0i64;
              m_numVertices = (unsigned int)v631.m_numVertices;
              v236 = _mm_max_ps(v619, aabbOut.m_quad);
              si128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
              v238 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
              do
              {
                v239 = _mm_rcp_ps(v236);
                v240 = 0i64;
                v241 = v11->m_provider->m_caches.m_data[v190]->m_vertices.m_data[v234].m_quad;
                v657 = v236;
                v242 = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpeq_ps((__m128)0i64, v236),
                           _mm_mul_ps(_mm_sub_ps(v233, _mm_mul_ps(v239, v236)), v239)),
                         _mm_sub_ps(v241, v613));
                v243 = _mm_cmplt_ps(v242, query.m_quad);
                v622 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v243, query.m_quad), _mm_and_ps(v243, v242)));
                v244 = (float)(_mm_shuffle_ps(v622, v622, 170).m128_f32[0] * 4194303.0) + 0.5;
                if ( v244 >= 9.223372e18 )
                {
                  v244 = v244 - 9.223372e18;
                  if ( v244 < 9.223372e18 )
                    v240 = 0x8000000000000000ui64;
                }
                v245 = 0i64;
                v246 = (v240 + (unsigned int)(int)v244) << 21;
                v247 = (float)(v622.m128_f32[1] * 2097151.0) + 0.5;
                if ( v247 >= 9.223372e18 )
                {
                  v247 = v247 - 9.223372e18;
                  if ( v247 < 9.223372e18 )
                    v245 = 0x8000000000000000ui64;
                }
                v248 = v245 + (unsigned int)(int)v247;
                v249 = (float)(v622.m128_f32[0] * 2097151.0) + 0.5;
                v250 = 0i64;
                v251 = (v248 | v246) << 21;
                if ( v249 >= 9.223372e18 )
                {
                  v249 = v249 - 9.223372e18;
                  if ( v249 < 9.223372e18 )
                    v250 = 0x8000000000000000ui64;
                }
                ++v234;
                v534.m128i_i64[0] = (v250 + (unsigned int)(int)v249) | v251;
                v648 = _mm_loadl_epi64(&v534);
                v233 = (__m128)_xmm;
                v252 = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_cvtepi32_ps(
                             _mm_or_si128(
                               _mm_or_si128(
                                 _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v648, 0xAu), 85), si128),
                                 _mm_and_si128(
                                   v648,
                                   (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX)),
                               _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v648, 2), 5u), v238))),
                           v630),
                         v629);
                v191 = _mm_min_ps(v191, v252);
                v192 = _mm_max_ps(v192, v252);
                --m_numVertices;
              }
              while ( m_numVertices );
              v174 = FLOAT_2097151_0;
              v172 = FLOAT_4194303_0;
              m_quad = v613;
              v176 = v619;
              v58 = v518;
              v178 = 0i64;
            }
          }
          else
          {
            v524 = 0i64;
            v525 = 0i64;
            v193 = *(int *)((char *)v187 + v188);
            if ( (int)v193 < v519 )
            {
              v194 = mapping->m_triangleIndexToKey.m_data;
              v195 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *)qInfos;
              v196 = 3 * v193;
              v197 = mapping->m_triangleIndexToKey.m_data[3 * v193];
              qInfos->m_provider->m_meshCInfo->vfptr->getIndices(
                qInfos->m_provider->m_meshCInfo,
                v197 & 0x3FFFFFFF,
                &v550);
              v550 = qInfos->m_vMap.m_data[v550];
              v551 = qInfos->m_vMap.m_data[v551];
              v552 = qInfos->m_vMap.m_data[v552];
              LODWORD(v524) = *(&v550 + (int)((v197 >> 30) + 1) % 3);
              v198 = v194[v196];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v195->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v195->m_size[2] + 8i64),
                v198 & 0x3FFFFFFF,
                &v556);
              v556 = qInfos->m_vMap.m_data[v556];
              v557 = qInfos->m_vMap.m_data[v557];
              v558 = qInfos->m_vMap.m_data[v558];
              HIDWORD(v524) = *(&v556 + (int)((v198 >> 30) + 2) % 3);
              v199 = (int)((v194[v196 + 1] >> 30) + 1) % 3;
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v195->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v195->m_size[2] + 8i64),
                v194[v196 + 1] & 0x3FFFFFFF,
                &v562);
              v562 = qInfos->m_vMap.m_data[v562];
              v563 = qInfos->m_vMap.m_data[v563];
              v564 = qInfos->m_vMap.m_data[v564];
              LODWORD(v525) = *(&v562 + v199);
              v200 = v194[v196 + 1];
              v11 = qInfos;
              v201 = (int)((v200 >> 30) + 2) % 3;
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v195->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v195->m_size[2] + 8i64),
                v200 & 0x3FFFFFFF,
                &v568);
              v179 = v506;
              v568 = qInfos->m_vMap.m_data[v568];
              v569 = qInfos->m_vMap.m_data[v569];
              v570 = qInfos->m_vMap.m_data[v570];
              HIDWORD(v525) = *(&v568 + v201);
            }
            else
            {
              v11->m_provider->m_meshCInfo->vfptr->getIndices(
                v11->m_provider->m_meshCInfo,
                v193 - mapping->m_triangleIndexToKey.m_size,
                (int *)&v524);
              LODWORD(v524) = v11->m_vMap.m_data[(int)v524];
              HIDWORD(v524) = v11->m_vMap.m_data[SHIDWORD(v524)];
              LODWORD(v525) = v11->m_vMap.m_data[(int)v525];
              HIDWORD(v525) = v525;
            }
            v58 = v518;
            v202 = 4i64;
            v203 = &v524;
            v510 = 4i64;
            do
            {
              v204 = *(int *)v203;
              v205 = v204;
              v206 = v518[2 * v204];
              if ( v206 == v493 )
              {
                if ( v518[2 * v204 + 1] == -1 )
                {
                  v518[2 * v204 + 1] = (unsigned __int8)(*(_BYTE *)(v179 + v182 + 88))++;
                  v11->vfptr->getVertex(v11, *(_DWORD *)v203, (hkVector4f *)&v643);
                  v207 = &masterTree[2].m_root;
                  if ( LODWORD(masterTree[3].m_nodes.m_data) == (HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_root, 4);
                    v207 = &masterTree[2].m_root;
                  }
                  v208 = *v207;
                  v209 = *((int *)v207 + 2);
                  *((_DWORD *)v207 + 2) = v209 + 1;
                  v210 = _mm_max_ps(_mm_sub_ps(v181[1], *v181), aabbOut.m_quad);
                  v211 = _mm_rcp_ps(v210);
                  v661 = v210;
                  v212 = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpeq_ps(v178, v210),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v210, v211)), v211)),
                           _mm_sub_ps(v643, *v181));
                  v213 = _mm_cmplt_ps(v212, query.m_quad);
                  v214 = _mm_max_ps(
                           aabbOut.m_quad,
                           _mm_or_ps(_mm_andnot_ps(v213, query.m_quad), _mm_and_ps(v212, v213)));
                  *(_DWORD *)(v208 + 4 * v209) = (int)(float)((float)(v214.m128_f32[0] * v84) + 0.5) | (((int)(float)((float)(_mm_shuffle_ps(v214, v214, 85).m128_f32[0] * v84) + 0.5) | ((int)(float)((float)(_mm_shuffle_ps(v214, v214, 170).m128_f32[0] * 1023.0) + 0.5) << 11)) << 11);
                  v179 = v506;
                  v202 = v510;
                }
                else
                {
                  v207 = &masterTree[2].m_root;
                }
                v654 = (__m128i)*(unsigned int *)(*v207 + 4i64 * (*(_DWORD *)(v179 + v182 + 72) + v518[2 * v205 + 1]));
                v215 = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_cvtepi32_ps(
                             _mm_or_si128(
                               _mm_or_si128(
                                 _mm_and_si128(
                                   _mm_shuffle_epi32(_mm_srli_epi32(v654, 0x16u), 0),
                                   (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ),
                                 _mm_and_si128(
                                   v654,
                                   (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX)),
                               _mm_and_si128(
                                 _mm_shuffle_epi32(_mm_srli_epi32(v654, 0xBu), 0),
                                 (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY))),
                           (__m128)v628),
                         v627);
                v191 = _mm_min_ps(v191, v215);
                v192 = _mm_max_ps(v192, v215);
              }
              else
              {
                if ( v206 == -2 )
                {
                  v11->vfptr->getVertex(v11, v204, (hkVector4f *)&v633);
                  v216 = 0i64;
                  v660 = _mm_max_ps(v176, aabbOut.m_quad);
                  v217 = _mm_rcp_ps(v660);
                  v218 = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpeq_ps(v178, v660),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v217, v660)), v217)),
                           _mm_sub_ps(v633, m_quad));
                  v219 = _mm_cmplt_ps(v218, query.m_quad);
                  *(__m128 *)out = _mm_max_ps(
                                     aabbOut.m_quad,
                                     _mm_or_ps(_mm_andnot_ps(v219, query.m_quad), _mm_and_ps(v219, v218)));
                  v220 = (float)(_mm_shuffle_ps(*(__m128 *)out, *(__m128 *)out, 170).m128_f32[0] * v172) + 0.5;
                  if ( v220 >= 9.223372e18 )
                  {
                    v220 = v220 - 9.223372e18;
                    if ( v220 < 9.223372e18 )
                      v216 = 0x8000000000000000ui64;
                  }
                  v221 = 0i64;
                  v222 = (float)(*((float *)out + 1) * v174) + 0.5;
                  v223 = (v216 + (unsigned int)(int)v220) << 21;
                  if ( v222 >= 9.223372e18 )
                  {
                    v222 = v222 - 9.223372e18;
                    if ( v222 < 9.223372e18 )
                      v221 = 0x8000000000000000ui64;
                  }
                  v224 = v221 + (unsigned int)(int)v222;
                  v225 = (float)(*(float *)out * v174) + 0.5;
                  v226 = 0i64;
                  v227 = (v224 | v223) << 21;
                  if ( v225 >= 9.223372e18 )
                  {
                    v225 = v225 - 9.223372e18;
                    if ( v225 < 9.223372e18 )
                      v226 = 0x8000000000000000ui64;
                  }
                  v534.m128i_i64[0] = (v226 + (unsigned int)(int)v225) | v227;
                  v656 = _mm_loadl_epi64(&v534);
                  v228 = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(
                                     _mm_shuffle_epi32(_mm_srli_epi32(v656, 0xAu), 85),
                                     (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ),
                                   _mm_and_si128(
                                     v656,
                                     (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX)),
                                 _mm_and_si128(
                                   _mm_srli_epi32(_mm_slli_si128(v656, 2), 5u),
                                   (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY))),
                             v630),
                           v629);
                  v191 = _mm_min_ps(v191, v228);
                  v192 = _mm_max_ps(v192, v228);
                }
                else
                {
                  v501 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)array + (_QWORD)v514);
                  if ( (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)array + (_QWORD)v514),
                              *(int *)v203) > v501->m_hashMod )
                  {
                    v11->vfptr->getVertex(v11, *(_DWORD *)v203, (hkVector4f *)&v644);
                    v229 = (unsigned __int8)(*(_BYTE *)(v179 + v182 + 88))++;
                    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                      v501,
                      &hkContainerHeapAllocator::s_alloc,
                      *(int *)v203,
                      v229);
                    v230 = &masterTree[2].m_root;
                    if ( LODWORD(masterTree[3].m_nodes.m_data) == (HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_root, 4);
                      v230 = &masterTree[2].m_root;
                    }
                    v231 = *v230;
                    v232 = *((int *)v230 + 2);
                    *((_DWORD *)v230 + 2) = v232 + 1;
                    *(_DWORD *)(v231 + 4 * v232) = *(_DWORD *)v203;
                    v191 = _mm_min_ps(v191, v644);
                    v192 = _mm_max_ps(v192, v644);
                  }
                  v518[2 * v205 + 1] = 0;
                }
                v202 = v510;
              }
              v203 = (__int64 *)((char *)v203 + 4);
              v510 = --v202;
            }
            while ( v202 );
          }
          v253 = v592;
          v186 = roots;
          v254 = _mm_min_ps(v192, v617);
          v255 = _mm_max_ps(v191, m_quad);
          v256 = &roots->m_nodes.m_data[*(_QWORD *)v592];
          v256->m_aabb.m_min.m_quad = v255;
          v256->m_aabb.m_max.m_quad = v254;
          for ( m = v256->m_parent; m; m = v258->m_parent )
          {
            v258 = &roots->m_nodes.m_data[m];
            v259 = v258->m_aabb.m_max.m_quad;
            if ( (_mm_movemask_ps(_mm_or_ps(_mm_cmplt_ps(v259, v254), _mm_cmplt_ps(v255, v258->m_aabb.m_min.m_quad))) & 7) == 0 )
              break;
            v258->m_aabb.m_min.m_quad = _mm_min_ps(v258->m_aabb.m_min.m_quad, v255);
            v258->m_aabb.m_max.m_quad = _mm_max_ps(v259, v254);
          }
          v84 = FLOAT_2047_0;
          v188 = v595;
          v187 = (unsigned __int64 *)(v253 + 8);
          v260 = (*(_QWORD *)&v535[0].m_enum)-- == 1i64;
          v592 = (__int64)v187;
        }
        while ( !v260 );
        v173 = v493;
        v177 = v514;
        v180 = v593;
        v175 = v520;
        v135 = quads;
      }
      v84 = FLOAT_2047_0;
      ++v173;
      v179 += 96i64;
      v177 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)((char *)v177 + 16);
      v181 += 131;
      v493 = v173;
      v506 = v179;
      v514 = v177;
    }
    while ( v173 < v135->m_size );
    p_m_firstFree = v605;
    p_m_size = v616;
    v157 = masterTree;
  }
  v665 = 0;
  v663 = 0;
  v669 = 0;
  v671 = 0;
  v667 = 0;
  v540 = 131584;
  v261 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v540);
  v262 = 0x80000000;
  v263 = v261;
  v511 = v261;
  if ( v540 / 2 )
    v262 = v540 / 2;
  LODWORD(v592) = v262;
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree::DynamicTree(&dTree);
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
    &dTree,
    v535,
    256);
  v264 = quads;
  v265 = 0i64;
  v266 = 0i64;
  v532 = 0;
  v496 = 0;
  v267 = 0;
  v494 = 0;
  v502 = 0i64;
  if ( quads->m_size > 0 )
  {
    while ( 1 )
    {
      v268 = 3i64 * (_QWORD)v266;
      v269 = v520[131 * (_QWORD)v266 + 66].m128_i32[0];
      LODWORD(v605) = v157[2].m_nodes.m_size;
      v270 = *(_QWORD *)v264->m_data[2 * (_QWORD)v266].m_edges;
      v498 = v269;
      v271 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)(*(_QWORD *)&v157[1].m_numLeaves + 32 * v268);
      m_numLeaves = v157[2].m_numLeaves;
      v515 = v271;
      LODWORD(v593) = v157[3].m_firstFree;
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::detachBranch(roots, v270, v267, &dTree);
      m_root = dTree.m_root;
      v273 = 0;
      if ( dTree.m_root )
      {
        v274 = dTree.m_nodes.m_data;
        v275 = dTree.m_root << 6;
        if ( LODWORD(dTree.m_nodes.m_data[dTree.m_root].m_children[0]) )
        {
          v276 = *(unsigned __int64 *)((char *)dTree.m_nodes.m_data->m_children + v275);
          while ( v276 )
          {
            v277 = v276 << 6;
            if ( LODWORD(v274[v276].m_children[0])
              || (v278 = v273,
                  ++v273,
                  *(unsigned __int64 *)((char *)&v274->m_children[1] + v277) = v278,
                  v274 = dTree.m_nodes.m_data,
                  *(_DWORD *)((char *)dTree.m_nodes.m_data->m_children + v277)) )
            {
              v276 = *(unsigned __int64 *)((char *)v274->m_children + v277);
            }
            else
            {
              v279 = *(unsigned __int64 *)((char *)&dTree.m_nodes.m_data->m_parent + v277);
              for ( n = v276; v279 != m_root; v279 = dTree.m_nodes.m_data[v279].m_parent )
              {
                if ( dTree.m_nodes.m_data[v279].m_children[1] != n )
                  break;
                n = v279;
              }
              if ( v279 )
                v276 = dTree.m_nodes.m_data[v279].m_children[1];
              else
                v276 = n;
              if ( v279 == m_root && v276 == n )
                v276 = 0i64;
            }
          }
        }
        else
        {
          *(unsigned __int64 *)((char *)&dTree.m_nodes.m_data->m_children[1] + v275) = 0i64;
        }
      }
      hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::convertFromDynamicTree<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree>(
        v271,
        &dTree);
      v281 = masterTree;
      LOBYTE(v282) = m_numLeaves;
      v283 = v498;
      v284 = v496;
      v535[0] = (hkResult)masterTree[2].m_numLeaves;
      v534.m128i_i32[2] = 0;
      v285 = m_numLeaves << 8;
      LODWORD(v616) = (unsigned __int8)v498;
      LODWORD(v595) = m_numLeaves << 8;
      do
      {
        v286 = v515;
        v287 = v263;
        for ( ii = 65792i64; ii; --ii )
          *v287++ = -1;
        v515[1].m_domain.m_min.m_quad.m128_i32[3] = (unsigned __int8)v515[1].m_domain.m_min.m_quad.m128_i32[3];
        v515[1].m_domain.m_min.m_quad.m128_i32[3] |= v285;
        v289 = (unsigned __int8)v515[1].m_domain.m_max.m_quad.m128_i8[8];
        v290 = v515[1].m_domain.m_min.m_quad.m128_i32[3];
        v669 = v283;
        v515[1].m_domain.m_min.m_quad.m128_i32[3] = v289 | v290 & 0xFFFFFF00;
        v291 = (int)v616;
        v515[1].m_domain.m_max.m_quad.m128_i32[0] = (v281[2].m_nodes.m_size << 8) | (unsigned __int8)v515[1].m_domain.m_max.m_quad.m128_i8[0];
        v515[1].m_domain.m_max.m_quad.m128_i32[0] &= 0xFFFFFF00;
        v515[1].m_domain.m_max.m_quad.m128_i32[0] |= v291;
        LOBYTE(v291) = v532;
        v515[1].m_domain.m_max.m_quad.m128_i32[1] = (LODWORD(v281[3].m_root) << 8) | (unsigned __int8)v515[1].m_domain.m_max.m_quad.m128_i8[4];
        v515[1].m_domain.m_max.m_quad.m128_i8[4] = 0;
        v515[1].m_domain.m_max.m_quad.m128_i8[12] = v291;
        v515[1].m_domain.m_max.m_quad.m128_i8[9] = 0;
        v515[1].m_domain.m_max.m_quad.m128_i8[13] = 0;
        v515[1].m_domain.m_max.m_quad.m128_i8[14] = LOBYTE(quads->m_data[2 * (_QWORD)v502].m_value);
        v663 = v283;
        v665 = v283;
        v671 = v283;
        v292 = 0;
        v533 = 0;
        v293 = 0i64;
        v507 = 0i64;
        if ( v283 > 0 )
        {
          v622.m128_u64[0] = 262i64 * (_QWORD)v502;
          while ( 1 )
          {
            v294 = v281 + 2;
            pArr[v293] = v292;
            if ( v281[2].m_nodes.m_size == (v281[2].m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v281[2].m_nodes.m_data, 4);
              v286 = v515;
              v292 = v533;
              v281 = masterTree;
              LOBYTE(v282) = m_numLeaves;
            }
            v295 = v294->m_nodes.m_size;
            v296 = &v294->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i8[4 * v295];
            v294->m_nodes.m_size = v295 + 1;
            primitiveIndex = v520[2].m128_i32[2 * v293 + 2 * v622.m128_u64[0]] - v503;
            if ( primitiveIndex < 0 )
              break;
            v297 = v286->m_nodes.m_size;
            v298 = 0;
            v299 = 0i64;
            if ( v297 <= 0 )
            {
LABEL_282:
              v298 = -1;
            }
            else
            {
              p_m_data = &v286->m_nodes.m_data->m_data;
              while ( (*p_m_data & 1) != 0 || v292 != (unsigned __int8)*p_m_data >> 1 )
              {
                ++v299;
                ++v298;
                p_m_data += 4;
                if ( v299 >= v297 )
                  goto LABEL_282;
              }
            }
            m_firstFree = v281[3].m_firstFree;
            v301 = LOBYTE(v281[2].m_numLeaves) + v286[1].m_domain.m_max.m_quad.m128_i8[8] - v282;
            hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(v286, v298, &aabb);
            v589.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
            *(_QWORD *)&v589.m_numVertices = 0i64;
            v589.m_layerData = 0;
            v589.m_tags.m_size = 0;
            v589.m_maxError = 3.40282e38;
            v589.m_compression = CM_LOCAL_4;
            v589.m_aabb.m_max.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         (__m128)xmmword_141A712A0);
            hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(
              v11->m_provider,
              primitiveIndex,
              &v589);
            m_maxError_low = (__m128)LODWORD(v589.m_maxError);
            v304.m_quad = (__m128)aabb.m_max;
            v305.m_quad = (__m128)aabb.m_min;
            *v296 = v301;
            v296[1] = v298;
            v296[2] = v298;
            LODWORD(v306) = _mm_shuffle_ps(m_maxError_low, m_maxError_low, 0).m128_u32[0];
            v296[3] = v298;
            m_compression = v589.m_compression;
            if ( (unsigned int)(v589.m_compression - 2) > 1 )
            {
              v327 = m_firstFree;
            }
            else
            {
              v641 = v305.m_quad;
              v308 = _mm_sub_ps(v304.m_quad, v305.m_quad);
              v309 = (unsigned __int64)(2i64 * (v589.m_numVertices + 1)) >> 3;
              v642 = _mm_mul_ps(
                       v308,
                       (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters::`2::invBitScalesBuffer);
              v310 = p_m_size[2];
              v311 = v310 + v309;
              v312 = p_m_size[3] & 0x3FFFFFFF;
              if ( v312 >= (int)v310 + (int)v309 )
              {
                v596.m_enum = HK_SUCCESS;
              }
              else
              {
                v313 = 2 * v312;
                if ( v311 < v313 )
                  v311 = v313;
                hkArrayUtil::_reserve(&v596, &hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, v311, 8);
              }
              p_m_size[2] += v309;
              v302 = *(_QWORD *)p_m_size + 8 * v310;
              v314 = 0;
              if ( v589.m_numVertices <= 0 )
              {
LABEL_294:
                v327 = m_firstFree;
                m_compression = CM_LOCAL_2;
                v589.m_compression = CM_LOCAL_2;
                goto LABEL_339;
              }
              v315 = 0i64;
              while ( 1 )
              {
                v316 = _mm_max_ps(v308, aabbOut.m_quad);
                v317 = _mm_rcp_ps(v316);
                v318 = v11->m_provider->m_caches.m_data[primitiveIndex]->m_vertices.m_data[v315].m_quad;
                v649 = v316;
                v319 = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpeq_ps((__m128)0i64, v316),
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v316, v317)), v317)),
                         _mm_sub_ps(v318, v305.m_quad));
                v320 = _mm_cmplt_ps(v319, query.m_quad);
                v321 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v320, query.m_quad), _mm_and_ps(v320, v319)));
                v322 = (int)(float)((float)(v321.m128_f32[0] * 31.0) + 0.5) | (32
                                                                             * ((int)(float)((float)(_mm_shuffle_ps(v321, v321, 85).m128_f32[0] * 31.0)
                                                                                           + 0.5) | (32 * (int)(float)((float)(_mm_shuffle_ps(v321, v321, 170).m128_f32[0] * 63.0) + 0.5))));
                *(_WORD *)v302 = v322;
                if ( v589.m_compression == CM_AUTO )
                {
                  v323 = _mm_sub_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_unpacklo_epi32(
                                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(v322 & 0x1F), _mm_cvtsi32_si128(v322 >> 10)),
                                   _mm_unpacklo_epi32(_mm_cvtsi32_si128((v322 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                               v642),
                             v641),
                           v318);
                  v324 = _mm_mul_ps(v323, v323);
                  v325 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v324, v324, 85), _mm_shuffle_ps(v324, v324, 0)),
                           _mm_shuffle_ps(v324, v324, 170));
                  v326 = _mm_rsqrt_ps(v325);
                  v651 = v325;
                  if ( _mm_andnot_ps(
                         _mm_cmple_ps(v325, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v326, v325), v326)),
                             _mm_mul_ps(*(__m128 *)_xmm, v326)),
                           v325)).m128_f32[0] > v306 )
                    break;
                }
                ++v314;
                ++v315;
                v302 += 2i64;
                if ( v314 >= v589.m_numVertices )
                  goto LABEL_294;
              }
              v327 = m_firstFree;
              v328 = p_m_size[3] & 0x3FFFFFFF;
              if ( v328 >= m_firstFree )
              {
                v601.m_enum = HK_SUCCESS;
                p_m_size[2] = m_firstFree;
                m_compression = v589.m_compression;
              }
              else
              {
                v329 = 2 * v328;
                v330 = m_firstFree;
                if ( m_firstFree < v329 )
                  v330 = v329;
                hkArrayUtil::_reserve(&v601, &hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, v330, 8);
                p_m_size[2] = m_firstFree;
                m_compression = v589.m_compression;
              }
            }
            if ( ((m_compression - 1) & 0xFFFFFFFD) == 0 )
            {
              v636 = v305.m_quad;
              v331 = _mm_sub_ps(v304.m_quad, v305.m_quad);
              v332 = (unsigned __int64)(4i64 * (v589.m_numVertices + 1)) >> 3;
              v637 = _mm_mul_ps(
                       v331,
                       (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
              v333 = p_m_size[2];
              v334 = v333 + v332;
              v335 = p_m_size[3] & 0x3FFFFFFF;
              if ( v335 >= (int)v333 + (int)v332 )
              {
                v597.m_enum = HK_SUCCESS;
              }
              else
              {
                v336 = 2 * v335;
                if ( v334 < v336 )
                  v334 = v336;
                hkArrayUtil::_reserve(&v597, &hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, v334, 8);
              }
              p_m_size[2] += v332;
              v302 = *(_QWORD *)p_m_size + 8 * v333;
              v337 = 0;
              if ( v589.m_numVertices <= 0 )
              {
LABEL_312:
                v327 = m_firstFree;
                m_compression = CM_LOCAL_4;
                v589.m_compression = CM_LOCAL_4;
                goto LABEL_339;
              }
              v338 = 0i64;
              v339 = (int *)(*(_QWORD *)p_m_size + 8 * v333);
              while ( 1 )
              {
                v340 = _mm_max_ps(v331, aabbOut.m_quad);
                v341 = _mm_rcp_ps(v340);
                v342 = v11->m_provider->m_caches.m_data[primitiveIndex]->m_vertices.m_data[v338].m_quad;
                v653 = v340;
                v343 = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpeq_ps((__m128)0i64, v340),
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v341, v340)), v341)),
                         _mm_sub_ps(v342, v305.m_quad));
                v344 = _mm_cmplt_ps(v343, query.m_quad);
                v345 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v344, query.m_quad), _mm_and_ps(v344, v343)));
                *v339 = (int)(float)((float)(v345.m128_f32[0] * 2047.0) + 0.5) | (((int)(float)((float)(_mm_shuffle_ps(v345, v345, 85).m128_f32[0] * 2047.0)
                                                                                              + 0.5) | ((int)(float)((float)(_mm_shuffle_ps(v345, v345, 170).m128_f32[0] * 1023.0) + 0.5) << 11)) << 11);
                if ( v589.m_compression == CM_AUTO )
                {
                  v346 = (__m128i)*(unsigned int *)(v302 + 4i64 * v337);
                  v655 = v346;
                  v347 = _mm_sub_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(
                                       _mm_shuffle_epi32(_mm_srli_epi32(v346, 0x16u), 0),
                                       (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ),
                                     _mm_and_si128(
                                       v346,
                                       (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX)),
                                   _mm_and_si128(
                                     _mm_shuffle_epi32(_mm_srli_epi32(v346, 0xBu), 0),
                                     (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY))),
                               v637),
                             v636),
                           v342);
                  v348 = _mm_mul_ps(v347, v347);
                  v349 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v348, v348, 85), _mm_shuffle_ps(v348, v348, 0)),
                           _mm_shuffle_ps(v348, v348, 170));
                  v350 = _mm_rsqrt_ps(v349);
                  v658 = v349;
                  if ( _mm_andnot_ps(
                         _mm_cmple_ps(v349, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v350, v349), v350)),
                             _mm_mul_ps(*(__m128 *)_xmm, v350)),
                           v349)).m128_f32[0] > v306 )
                    break;
                }
                ++v337;
                ++v338;
                ++v339;
                if ( v337 >= v589.m_numVertices )
                  goto LABEL_312;
              }
              v327 = m_firstFree;
              v351 = p_m_size[3] & 0x3FFFFFFF;
              if ( v351 >= m_firstFree )
              {
                v610.m_enum = HK_SUCCESS;
                p_m_size[2] = m_firstFree;
                m_compression = v589.m_compression;
              }
              else
              {
                v352 = 2 * v351;
                v353 = m_firstFree;
                if ( m_firstFree < v352 )
                  v353 = v352;
                hkArrayUtil::_reserve(&v610, &hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, v353, 8);
                p_m_size[2] = m_firstFree;
                m_compression = v589.m_compression;
              }
            }
            if ( m_compression == CM_GLOBAL || m_compression == CM_AUTO )
            {
              v354 = v589.m_numVertices;
              v355 = p_m_size[2];
              v302 = (unsigned int)(v355 + v589.m_numVertices);
              v356 = p_m_size[3] & 0x3FFFFFFF;
              if ( v356 >= (int)v302 )
              {
                v603.m_enum = HK_SUCCESS;
              }
              else
              {
                v357 = 2 * v356;
                if ( (int)v302 < v357 )
                  LODWORD(v302) = v357;
                hkArrayUtil::_reserve(&v603, &hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, v302, 8);
              }
              p_m_size[2] += v354;
              v358 = *(_QWORD *)p_m_size + 8 * v355;
              v359 = 0;
              if ( v589.m_numVertices > 0 )
              {
                v302 = 0i64;
                do
                {
                  v360 = _mm_max_ps(v619, aabbOut.m_quad);
                  v361 = _mm_rcp_ps(v360);
                  v362 = 0i64;
                  v363 = *(__m128 *)((char *)&v11->m_provider->m_caches.m_data[primitiveIndex]->m_vertices.m_data->m_quad
                                   + v302);
                  v650 = v360;
                  v364 = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpeq_ps((__m128)0i64, v360),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v360, v361)), v361)),
                           _mm_sub_ps(v363, v613));
                  v365 = _mm_cmplt_ps(v364, query.m_quad);
                  v620 = _mm_max_ps(
                           aabbOut.m_quad,
                           _mm_or_ps(_mm_and_ps(v364, v365), _mm_andnot_ps(v365, query.m_quad)));
                  v366 = (float)(_mm_shuffle_ps(v620, v620, 170).m128_f32[0] * v172) + 0.5;
                  if ( v366 >= 9.223372e18 )
                  {
                    v366 = v366 - 9.223372e18;
                    if ( v366 < 9.223372e18 )
                      v362 = 0x8000000000000000ui64;
                  }
                  v367 = 0i64;
                  v368 = (float)(v620.m128_f32[1] * v174) + 0.5;
                  v369 = (v362 + (unsigned int)(int)v366) << 21;
                  if ( v368 >= 9.223372e18 )
                  {
                    v368 = v368 - 9.223372e18;
                    if ( v368 < 9.223372e18 )
                      v367 = 0x8000000000000000ui64;
                  }
                  v370 = v367 + (unsigned int)(int)v368;
                  v371 = (float)(v620.m128_f32[0] * v174) + 0.5;
                  v372 = 0i64;
                  v373 = (v370 | v369) << 21;
                  if ( v371 >= 9.223372e18 )
                  {
                    v371 = v371 - 9.223372e18;
                    if ( v371 < 9.223372e18 )
                      v372 = 0x8000000000000000ui64;
                  }
                  ++v359;
                  v358 += 8i64;
                  v302 += 16i64;
                  *(_QWORD *)(v358 - 8) = (v372 + (unsigned int)(int)v371) | v373;
                }
                while ( v359 < v589.m_numVertices );
                v58 = v518;
              }
              v327 = m_firstFree;
              m_compression = CM_GLOBAL;
              v589.m_compression = CM_GLOBAL;
            }
LABEL_339:
            v374 = masterTree;
            v375 = LODWORD(masterTree[3].m_firstFree) - v327;
            if ( m_compression == CM_LOCAL_4 )
            {
              v379 = *(_QWORD *)p_m_size + 8i64 * v327;
              v380 = 0i64;
              if ( v375 <= 0 )
                goto LABEL_348;
              do
              {
                v381 = *(_QWORD *)(v379 + 8 * v380++);
                v624 = v381;
                v599 = __PAIR64__(v381, HIDWORD(v381));
                *(_QWORD *)(v379 + 8 * v380 - 8) = __PAIR64__(v381, HIDWORD(v381));
              }
              while ( v380 < v375 );
            }
            else
            {
              if ( m_compression != CM_LOCAL_2 )
                goto LABEL_347;
              v376 = *(_QWORD *)p_m_size + 8i64 * v327;
              v377 = 0i64;
              if ( v375 <= 0 )
                goto LABEL_348;
              do
              {
                v378 = *(_QWORD *)(v376 + 8 * v377++);
                v594 = v378;
                WORD2(v536) = WORD1(v378);
                HIWORD(v536) = v378;
                WORD1(v536) = WORD2(v378);
                LOWORD(v536) = HIWORD(v378);
                *(_QWORD *)(v376 + 8 * v377 - 8) = v536;
              }
              while ( v377 < v375 );
            }
            m_compression = v589.m_compression;
LABEL_347:
            if ( (unsigned int)(m_compression - 1) <= 1 )
            {
LABEL_348:
              v515[1].m_domain.m_max.m_quad.m128_i8[13] |= 1u;
              m_compression = v589.m_compression;
            }
            *((_DWORD *)&config->m_vrp + (int)m_compression) += v589.m_numVertices;
            *((_DWORD *)&config->m_globalOptimizations.m_bool + (int)v589.m_compression) += 8
                                                                                          * (LODWORD(masterTree[3].m_firstFree)
                                                                                           - v327);
            *(_DWORD *)&config->m_weldVertices.m_bool += v589.m_tags.m_size;
            v382 = v589.m_customType & 0xF | (16
                                            * (v589.m_compression & 3 | (4
                                                                       * ((4 * LOWORD(v589.m_numVertices)) | v589.m_tags.m_size & 3))));
            if ( *((_DWORD *)p_m_firstFree + 2) == (*((_DWORD *)p_m_firstFree + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_firstFree, 2);
            *(_WORD *)(*p_m_firstFree + 2i64 * (int)(*((_DWORD *)p_m_firstFree + 2))++) = v382;
            if ( *((_DWORD *)p_m_firstFree + 2) == (*((_DWORD *)p_m_firstFree + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_firstFree, 2);
            v383 = v496;
            *(_WORD *)(*p_m_firstFree + 2i64 * (int)(*((_DWORD *)p_m_firstFree + 2))++) = v496;
            v384 = 0;
            if ( v589.m_tags.m_size > 0 )
            {
              p_m_tags = &v589.m_tags;
              do
              {
                if ( *((_DWORD *)p_m_firstFree + 2) == (*((_DWORD *)p_m_firstFree + 3) & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_firstFree, 2);
                v383 = *((int *)p_m_firstFree + 2);
                *(_WORD *)(*p_m_firstFree + 2 * v383) = p_m_tags->m_data[0];
                ++*((_DWORD *)p_m_firstFree + 2);
                ++v384;
                p_m_tags = (hkFixedInplaceArray<unsigned short,3> *)((char *)p_m_tags + 2);
              }
              while ( v384 < v589.m_tags.m_size );
            }
            v284 = LODWORD(masterTree[3].m_firstFree) - m_firstFree + v496;
            v496 = v284;
            v670[2 * v507] = -1 - primitiveIndex;
            v670[2 * v507 + 1] = 0;
            m_provider = v11->m_provider;
            v387 = ((int (__fastcall *)(hkpBvCompressedMeshShapeCinfo *, __int64, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *, __int64))m_provider->m_meshCInfo->vfptr->getNumTriangles)(
                     m_provider->m_meshCInfo,
                     v383,
                     v374,
                     v302);
            m_primitiveData = m_provider->m_primitiveData;
            v389 = v507;
            *((_DWORD *)&cmpLess.m_data + v507) = m_primitiveData->m_data[primitiveIndex + v387].m_data;
LABEL_389:
            if ( v284 > 0x10000 )
              goto LABEL_392;
            m_quad = v613;
            v281 = masterTree;
            LOBYTE(v282) = m_numLeaves;
            v292 = v533 + 1;
            v293 = v389 + 1;
            v533 = v292;
            v507 = v293;
            if ( v292 >= v498 )
              goto LABEL_391;
            v286 = v515;
          }
          v526 = 0i64;
          v527 = 0i64;
          v390 = v520[2].m128_i32[2 * v293 + 2 * v622.m128_u64[0]];
          if ( (int)v390 < v519 )
          {
            v392 = mapping->m_triangleIndexToKey.m_data;
            v393 = 3 * v390;
            v394 = mapping->m_triangleIndexToKey.m_data[3 * v390];
            v539 = mapping->m_triangleIndexToKey.m_data[3 * v390 + 1] & 0x3FFFFFFF;
            primitiveIndexa = v394 & 0x3FFFFFFF;
            v395 = (int)((v394 >> 30) + 1) % 3;
            qInfos->m_provider->m_meshCInfo->vfptr->getIndices(
              qInfos->m_provider->m_meshCInfo,
              v394 & 0x3FFFFFFF,
              &v574);
            v574 = qInfos->m_vMap.m_data[v574];
            v575 = qInfos->m_vMap.m_data[v575];
            v576 = qInfos->m_vMap.m_data[v576];
            LODWORD(v526) = *(&v574 + v395);
            v396 = v392[v393];
            qInfos->m_provider->m_meshCInfo->vfptr->getIndices(
              qInfos->m_provider->m_meshCInfo,
              v396 & 0x3FFFFFFF,
              &v580);
            v580 = qInfos->m_vMap.m_data[v580];
            v581 = qInfos->m_vMap.m_data[v581];
            v582 = qInfos->m_vMap.m_data[v582];
            HIDWORD(v526) = *(&v580 + (int)((v396 >> 30) + 2) % 3);
            v397 = (int)((v392[v393 + 1] >> 30) + 1) % 3;
            qInfos->m_provider->m_meshCInfo->vfptr->getIndices(
              qInfos->m_provider->m_meshCInfo,
              v392[v393 + 1] & 0x3FFFFFFF,
              &v586);
            v586 = qInfos->m_vMap.m_data[v586];
            v587 = qInfos->m_vMap.m_data[v587];
            v588 = qInfos->m_vMap.m_data[v588];
            LODWORD(v527) = *(&v586 + v397);
            v398 = v392[v393 + 1];
            v11 = qInfos;
            qInfos->m_provider->m_meshCInfo->vfptr->getIndices(
              qInfos->m_provider->m_meshCInfo,
              v398 & 0x3FFFFFFF,
              &v577);
            v577 = qInfos->m_vMap.m_data[v577];
            v578 = qInfos->m_vMap.m_data[v578];
            v579 = qInfos->m_vMap.m_data[v579];
            HIDWORD(v527) = *(&v577 + (int)((v398 >> 30) + 2) % 3);
          }
          else
          {
            v391 = (unsigned int)(v390 - mapping->m_triangleIndexToKey.m_size);
            v539 = -1;
            primitiveIndexa = v391;
            ((void (__fastcall *)(hkpBvCompressedMeshShapeCinfo *, __int64, __int64 *, hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *))v11->m_provider->m_meshCInfo->vfptr->getIndices)(
              v11->m_provider->m_meshCInfo,
              v391,
              &v526,
              v286);
            LODWORD(v526) = v11->m_vMap.m_data[(int)v526];
            HIDWORD(v526) = v11->m_vMap.m_data[SHIDWORD(v526)];
            LODWORD(v527) = v11->m_vMap.m_data[(int)v527];
            HIDWORD(v527) = v527;
          }
          v58 = v518;
          v399 = &v526;
          v534.m128i_i64[0] = 4i64;
          while ( 1 )
          {
            v400 = *(int *)v399;
            if ( v518[2 * v400 + 1] < 0 )
            {
              v518[2 * v400 + 1] = v496++;
              v11->vfptr->getVertex(v11, *(_DWORD *)v399, (hkVector4f *)&v638);
              if ( p_m_size[2] == (p_m_size[3] & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, 8);
              v401 = *(_QWORD **)p_m_size;
              v402 = v619;
              v403 = p_m_size[2];
              p_m_size[2] = v403 + 1;
              v404 = 0i64;
              v405 = _mm_max_ps(v402, aabbOut.m_quad);
              v406 = _mm_rcp_ps(v405);
              v659 = v405;
              v407 = _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmpeq_ps(v405, (__m128)0i64),
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v406, v405)), v406)),
                       _mm_sub_ps(v638, m_quad));
              v408 = _mm_cmplt_ps(v407, query.m_quad);
              v617 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v408, query.m_quad), _mm_and_ps(v408, v407)));
              v409 = (float)(_mm_shuffle_ps(v617, v617, 170).m128_f32[0] * v172) + 0.5;
              if ( v409 >= 9.223372e18 )
              {
                v409 = v409 - 9.223372e18;
                if ( v409 < 9.223372e18 )
                  v404 = 0x8000000000000000ui64;
              }
              v410 = 0i64;
              v411 = (float)(v617.m128_f32[1] * v174) + 0.5;
              v412 = (v404 + (unsigned int)(int)v409) << 21;
              if ( v411 >= 9.223372e18 )
              {
                v411 = v411 - 9.223372e18;
                if ( v411 < 9.223372e18 )
                  v410 = 0x8000000000000000ui64;
              }
              v413 = v410 + (unsigned int)(int)v411;
              v414 = (float)(v617.m128_f32[0] * v174) + 0.5;
              v415 = 0i64;
              v416 = (v413 | v412) << 21;
              if ( v414 >= 9.223372e18 )
              {
                v414 = v414 - 9.223372e18;
                if ( v414 < 9.223372e18 )
                  v415 = 0x8000000000000000ui64;
              }
              v401[v403] = (v415 + (unsigned int)(int)v414) | v416;
            }
            v417 = v518[2 * v400];
            if ( v417 == -2 )
              break;
            if ( v417 == -1 )
            {
              v421 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
                       &array[v494],
                       &v625,
                       *(int *)v399,
                       out);
              v420 = 0;
              if ( v421->m_enum == HK_SUCCESS )
                v420 = out[0];
              goto LABEL_386;
            }
            *v296 = v518[2 * v400 + 1];
LABEL_387:
            v399 = (__int64 *)((char *)v399 + 4);
            ++v296;
            if ( !--v534.m128i_i64[0] )
            {
              v389 = v507;
              v422 = v539;
              v284 = v496;
              v670[2 * v507] = primitiveIndexa;
              v670[2 * v507 + 1] = v422;
              *((_DWORD *)&cmpLess.m_data + v507) = v11->m_provider->m_primitiveData->m_data[primitiveIndexa].m_data;
              goto LABEL_389;
            }
          }
          v418 = v518[2 * v400 + 1];
          v419 = v511;
          if ( v511[v418] == 0xFFFF )
          {
            v511[v418] = LOWORD(masterTree[2].m_numLeaves)
                       + (unsigned __int8)v515[1].m_domain.m_max.m_quad.m128_i8[8]
                       - (_WORD)m_numLeaves;
            v490 = v518[2 * v400 + 1];
            if ( *((_DWORD *)p_m_firstFree + 2) == (*((_DWORD *)p_m_firstFree + 3) & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_firstFree, 2);
              v419 = v511;
            }
            *(_WORD *)(*p_m_firstFree + 2i64 * (int)(*((_DWORD *)p_m_firstFree + 2))++) = v490;
          }
          v420 = v419[v518[2 * v400 + 1]];
LABEL_386:
          *v296 = v420;
          goto LABEL_387;
        }
LABEL_391:
        if ( v284 <= 0x10000 )
          break;
LABEL_392:
        v423 = v591;
        v424 = (int)v605;
        v425 = *((_DWORD *)v591 + 3) & 0x3FFFFFFF;
        if ( v425 >= (int)v605 )
        {
          v607.m_enum = HK_SUCCESS;
        }
        else
        {
          v426 = 2 * v425;
          v427 = (int)v605;
          if ( (int)v605 < v426 )
            v427 = v426;
          hkArrayUtil::_reserve(&v607, &hkContainerHeapAllocator::s_alloc, (const void **)v591, v427, 4);
        }
        v423[2] = v424;
        v428 = v593;
        v429 = p_m_size[3] & 0x3FFFFFFF;
        if ( v429 >= (int)v593 )
        {
          v611.m_enum = HK_SUCCESS;
        }
        else
        {
          v430 = 2 * v429;
          v431 = v593;
          if ( (int)v593 < v430 )
            v431 = v430;
          hkArrayUtil::_reserve(&v611, &hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, v431, 8);
        }
        v282 = m_numLeaves;
        p_m_size[2] = v428;
        v432 = *((_DWORD *)p_m_firstFree + 3) & 0x3FFFFFFF;
        if ( v432 >= m_numLeaves )
        {
          v609.m_enum = HK_SUCCESS;
        }
        else
        {
          v433 = 2 * v432;
          v434 = m_numLeaves;
          if ( m_numLeaves < v433 )
            v434 = v433;
          hkArrayUtil::_reserve(&v609, &hkContainerHeapAllocator::s_alloc, (const void **)p_m_firstFree, v434, 2);
          v282 = m_numLeaves;
        }
        v281 = masterTree;
        *((_DWORD *)p_m_firstFree + 2) = v282;
        if ( SLODWORD(masterTree[3].m_firstFree) % 0x10000 )
        {
          do
          {
            if ( p_m_size[2] == (p_m_size[3] & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, 8);
              v281 = masterTree;
            }
            *(_QWORD *)(*(_QWORD *)p_m_size + 8i64 * p_m_size[2]++) = 0i64;
          }
          while ( SLODWORD(v281[3].m_firstFree) % 0x10000 );
          LOBYTE(v282) = m_numLeaves;
        }
        v435 = v598;
        if ( (int)v598 > 0 )
        {
          v436 = v58;
          do
          {
            if ( *v436 == -2 )
              v436[1] = -1;
            v436 += 2;
            --v435;
          }
          while ( v435 );
        }
        ++v532;
        m_quad = v613;
        v283 = v498;
        v285 = v595;
        v284 = 0;
        v496 = 0;
        v263 = v511;
        ++v534.m128i_i32[2];
      }
      while ( v534.m128i_i32[2] < 2 );
      v437 = v515;
      v515[1].m_domain.m_max.m_quad.m128_i8[9] = LOBYTE(v281[2].m_numLeaves) - LOBYTE(v535[0].m_enum);
      if ( v663 > 1 )
      {
        hkAlgorithm::quickSortRecursive<int,hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DataSorter>(
          pArr,
          0,
          v663 - 1,
          (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DataSorter)&cmpLess);
        v437 = v515;
      }
      v438 = v498;
      v439 = 0;
      if ( v498 > 0 )
      {
        v440 = pArr;
        do
        {
          v441 = *v440++;
          v668[v441] = v439++;
        }
        while ( v439 < v498 );
      }
      v442 = v591;
      v443 = 0;
      v444 = v498;
      v667 = 0;
      v445 = *(_QWORD *)v591 + 4 * ((unsigned __int64)v437[1].m_domain.m_max.m_quad.m128_u32[0] >> 8);
      if ( v498 )
      {
        while ( 1 )
        {
          v445 += 4i64;
          v667 = v443 + 1;
          v666[v443 + 1] = *(_DWORD *)(v445 - 4);
          if ( !--v444 )
            break;
          v443 = v667;
        }
        if ( v498 > 0 )
        {
          v446 = 0i64;
          v447 = (unsigned int)v498;
          do
          {
            ++v446;
            *(_DWORD *)(*v442
                      + 4i64
                      * (v661.m128_i32[v446 + 3] + ((unsigned int)v437[1].m_domain.m_max.m_quad.m128_i32[0] >> 8))) = v666[v446];
            --v447;
          }
          while ( v447 );
        }
      }
      v448 = 0;
      if ( v437->m_nodes.m_size > 0 )
      {
        v449 = 0i64;
        do
        {
          v450 = v437->m_nodes.m_data[v449].m_data;
          if ( (v450 & 1) == 0 )
            v437->m_nodes.m_data[v449].m_data = 2 * LOBYTE(pArr[(unsigned __int64)v450 >> 1]);
          ++v448;
          ++v449;
        }
        while ( v448 < v437->m_nodes.m_size );
      }
      v451 = 0;
      if ( v671 > 0 )
        break;
LABEL_444:
      v456 = 0;
      if ( v438 > 0 )
      {
        v457 = (const void **)&masterTree[3].m_numLeaves;
        do
        {
          if ( LODWORD(masterTree[3].m_root) == (HIDWORD(masterTree[3].m_root) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v457, 8);
            v437 = v515;
            v438 = v498;
          }
          v458 = *v457;
          v459 = v456 + 1;
          v460 = SLODWORD(masterTree[3].m_root);
          LODWORD(masterTree[3].m_root) = v460 + 1;
          v458[2 * v460] = *((_DWORD *)&cmpLess.m_data + v668[v456]);
          LOBYTE(v458[2 * v460 + 1]) = v456;
          BYTE1(v458[2 * v460 + 1]) = 1;
          if ( v456 + 1 < v438 )
          {
            v461 = &v668[v459];
            do
            {
              if ( v458[2 * v460] != *((_DWORD *)&cmpLess.m_data + *v461) )
                break;
              ++BYTE1(v458[2 * v460 + 1]);
              ++v459;
              ++v461;
            }
            while ( v459 < v438 );
          }
          v456 += BYTE1(v458[2 * v460 + 1]);
          v437[1].m_domain.m_max.m_quad.m128_i32[1] = v437[1].m_domain.m_max.m_quad.m128_i32[1] & 0xFFFFFF00 | ((unsigned __int8)v437[1].m_domain.m_max.m_quad.m128_i8[4] + 1);
        }
        while ( v456 < v438 );
      }
      if ( !*(_BYTE *)&this[1] )
        goto LABEL_464;
      v462 = v437[1].m_domain.m_max.m_quad.m128_u32[1];
      v463 = 0;
      v464 = *(_QWORD *)&masterTree[3].m_numLeaves;
      v465 = v462 >> 8;
      v466 = 0i64;
      v467 = v464 + 8 * v465;
      LODWORD(v465) = v465 - (unsigned __int8)v462;
      v468 = (int)v465;
      if ( (int)v465 > 0 )
      {
        v469 = (unsigned __int8)v462;
        v470 = v464 - v467 - 4;
        while ( 1 )
        {
          v471 = 0i64;
          if ( v469 <= 0 )
            break;
          v472 = (_BYTE *)(v467 + 4);
          while ( *v472 == v472[v470 + 4]
               && v472[1] == v472[v470 + 5]
               && *((_DWORD *)v472 - 1) == *(_DWORD *)&v472[v470] )
          {
            ++v471;
            v472 += 8;
            if ( v471 >= v469 )
              goto LABEL_462;
          }
          ++v466;
          ++v463;
          v470 += 8i64;
          if ( v466 >= v468 )
            goto LABEL_464;
        }
LABEL_462:
        v157 = masterTree;
        v515[1].m_domain.m_max.m_quad.m128_i32[1] = (unsigned __int8)v515[1].m_domain.m_max.m_quad.m128_i32[1];
        v515[1].m_domain.m_max.m_quad.m128_i32[1] |= v463 << 8;
        LODWORD(masterTree[3].m_root) -= (unsigned __int8)v515[1].m_domain.m_max.m_quad.m128_i8[4];
      }
      else
      {
LABEL_464:
        v157 = masterTree;
      }
      v264 = quads;
      m_quad = v613;
      v263 = v511;
      v267 = v494 + 1;
      v266 = (char *)&v502->m_elem + 1;
      v494 = v267;
      v502 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)v502 + 1);
      if ( v267 >= quads->m_size )
      {
        v265 = 0i64;
        goto LABEL_467;
      }
    }
    v452 = pArr;
    v453 = v670;
    while ( 1 )
    {
      v454 = *v453;
      v455 = 2 * (*v452 | (v494 << 7));
      if ( (int)v454 >= 0 )
        break;
      if ( v453[1] )
        goto LABEL_440;
      provider->m_vMap.m_data[-v454 - 1] = v455;
LABEL_442:
      ++v451;
      v453 += 2;
      ++v452;
      if ( v451 >= v671 )
      {
        v58 = v518;
        v438 = v498;
        goto LABEL_444;
      }
    }
    *((_DWORD *)&provider->vfptr->__vecDelDtor + *v453) = v455;
LABEL_440:
    if ( v453[1] >= 0 )
      *((_DWORD *)&provider->vfptr->__vecDelDtor + v453[1]) = v455 | 1;
    goto LABEL_442;
  }
LABEL_467:
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::convertFromDynamicTree<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree>(
    (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *)v157,
    roots);
  v473 = 0;
  if ( v157->m_nodes.m_size > 0 )
  {
    v474 = v590;
    do
    {
      v475 = 5i64 * v473;
      if ( masterTree->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i8[v475 + 3] >= 0 )
        *(_WORD *)(96
                 * ((unsigned __int8)masterTree->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i8[v475 + 4] | (unsigned __int64)((unsigned __int8)masterTree->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i8[v475 + 3] << 8))
                 + *(_QWORD *)v474
                 + 90) = v473;
      v157 = masterTree;
      ++v473;
    }
    while ( v473 < masterTree->m_nodes.m_size );
    v263 = v511;
  }
  v476 = v157->m_nodes.m_size;
  if ( v476 < (v157->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&v157->m_nodes.m_data, 5, 0i64, v476);
  v477 = v157[2].m_nodes.m_size;
  if ( v477 < (v157[2].m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&v157[2].m_nodes.m_data, 4, 0i64, v477);
  v478 = (int)masterTree[3].m_nodes.m_data;
  if ( v478 < (HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, p_m_root, 4, 0i64, v478);
  v479 = p_m_size[2];
  if ( v479 < (p_m_size[3] & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, 8, 0i64, v479);
  v480 = *((_DWORD *)p_m_firstFree + 2);
  if ( v480 < (*((_DWORD *)p_m_firstFree + 3) & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_firstFree, 2, 0i64, v480);
  v481 = v157[3].m_root;
  if ( v481 < (HIDWORD(v157[3].m_root) & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&v157[3].m_numLeaves, 8, 0i64, v481);
  v482 = 0;
  if ( SLODWORD(masterTree[1].m_root) > 0 )
  {
    do
    {
      v483 = v265 + *(_QWORD *)&masterTree[1].m_numLeaves;
      v484 = *(_DWORD *)(v483 + 8);
      if ( v484 < (*(_DWORD *)(v483 + 12) & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)v483, 4, 0i64, v484);
      ++v482;
      v265 += 96i64;
    }
    while ( v482 < SLODWORD(masterTree[1].m_root) );
    v58 = v518;
  }
  hkArray<hkSurfaceConstraintInfo,hkContainerHeapAllocator>::~hkArray<hkSurfaceConstraintInfo,hkContainerHeapAllocator>(&dTree);
  if ( (int)v592 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v263, 2 * (v592 & 0x3FFFFFFF));
  v485 = v522 - 1;
  if ( v522 - 1 >= 0 )
  {
    v486 = (hkPointerMap<int,int,hkContainerHeapAllocator> *)&array[v485];
    do
    {
      hkPointerMap<int,int,hkContainerHeapAllocator>::`scalar deleting destructor(v486--, 0);
      --v485;
    }
    while ( v485 >= 0 );
  }
  v522 = 0;
  if ( v523 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v523);
  array = 0i64;
  v523 = 0x80000000;
  if ( v614 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v520,
      2096 * (v614 & 0x3FFFFFFF));
  if ( v600 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v58, 8 * v600);
  return 1;
}_alloc, v58, 8 * v600);
  return 1;
}v475 + 4] | (unsigned __int64)((unsigned __int8)masterTree->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i8[v475 + 3] << 8))
                 + *(_QWORD *)v474
                 + 90) = v473;
      v157 = masterTree;
      ++v473;
    }
    while ( v473 < masterTree->m_nodes.m_size );
    v263 = v511;
  }
  v476 = v157->m_nodes.m_size;
  if ( v476 < (v157->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&v157->m_nodes.m_data, 5, 0i64, v476);
  v477 = v157[2].m_nodes.m_size;
  if ( v477 < (v157[2].m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&v157[2].m_nodes.m_data, 4, 0i64, v477);
  v478 = (int)masterTree[3].m_nodes.m_data;
  if ( v478 < (HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, p_m_root, 4, 0i64, v478);
  v479 = p_m_size[2];
  if ( v479 < (p_m_size[3] & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_size, 8, 0i64, v479);
  v480 = *((_DWORD *)p_m_firstFree + 2);
  if ( v480 < (*((_DWORD *)p_m_firstFree + 3) & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_firstFree, 2, 0i64, v480);
  v481 = v157[3].m_root;
  if ( v481 < (HIDWORD(v157[3].m_root) & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&v157[3].m_numLeaves, 8, 0i64, v481);
  v482 = 0;
  if ( SLODWORD(masterTree[1].m_root) > 0 )
  {

// File Line: 1057
// RVA: 0xDE9BD0
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::build<hkpBvCompressedMeshShape_Internals::GeometryProvider>(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this,
        hkcdStaticMeshTreeBase::BuildConfig *baseConfig,
        hkpBvCompressedMeshShape_Internals::GeometryProvider *baseProvider,
        hkcdStaticMeshTreeBase::BuildMapping *mapping)
{
  int v4; // r12d
  hkpBvCompressedMeshShapeCinfo *m_meshCInfo; // rcx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v7; // rdi
  int v10; // eax
  int v11; // r14d
  int v12; // ecx
  __int64 v13; // rdx
  int v14; // r14d
  int v15; // r9d
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  int v18; // eax
  __int64 j; // rax
  int m_size; // eax
  hkcdStaticMeshTreeBase::Primitive *v21; // rcx
  int v22; // edi
  __int64 v23; // r9
  int v24; // edx
  int v25; // eax
  int v26; // r8d
  int v27; // edx
  bool v28; // zf
  int v29; // edx
  unsigned int v30; // edi
  unsigned int k; // eax
  unsigned int v32; // edi
  int v33; // eax
  int m_bitsPerKey; // eax
  unsigned int v35; // r14d
  int v36; // esi
  int v37; // r15d
  int v38; // r13d
  int v39; // r11d
  hkcdStaticMeshTreeBase::Section::Primitives *v40; // r10
  unsigned __int64 v41; // rcx
  hkcdStaticMeshTreeBase::Primitive *v42; // rax
  hkcdStaticMeshTreeBase::Primitive *v43; // r12
  unsigned int v44; // r9d
  hkcdStaticMeshTreeBase::Primitive *v45; // rcx
  __int64 v46; // rax
  int v47; // r8d
  int v48; // edx
  int v49; // edi
  __int64 v50; // rax
  int v51; // edi
  __int64 v52; // rcx
  __int64 v53; // rdx
  unsigned int *v54; // rax
  __int64 v55; // r14
  char v56; // di
  __int64 v57; // r14
  unsigned int isDegenerate; // eax
  int v59; // r8d
  int v60; // edi
  int v61; // ecx
  int v62; // edx
  __int64 v63; // rax
  hkOstream *v64; // rax
  hkOstream *v65; // rax
  int v66; // esi
  int v67; // r15d
  int v68; // edx
  hkResultEnum m_enum; // r13d
  hkcdStaticMeshTreeBase::Section::Primitives *p_m_primitives; // r11
  unsigned __int64 v71; // rcx
  hkcdStaticMeshTreeBase::Primitive *v72; // rax
  unsigned int *v73; // r10
  int v74; // r14d
  hkcdStaticMeshTreeBase::Primitive *v75; // rsi
  unsigned int v76; // r14d
  __int64 v77; // rdi
  int v78; // eax
  int v79; // ecx
  int v80; // edx
  __int64 v81; // rax
  hkcdStaticMeshTreeBase::BuildMapping *v82; // r9
  __int64 v83; // rdx
  __int64 v84; // rcx
  unsigned int *v85; // rax
  char v86; // al
  char v87; // cl
  __int64 v88; // rcx
  __int64 v89; // rdx
  unsigned int *v90; // rax
  int v91; // edi
  int v92; // ecx
  int v93; // r8d
  int v94; // edx
  __int64 v95; // rax
  int v96; // eax
  hkOstream *v97; // rax
  hkOstream *v98; // rax
  hkOstream *v99; // rax
  hkOstream *v100; // rax
  int m_capacityAndFlags; // edi
  __int32 v102; // edi
  hkOstream *v103; // rax
  int v104; // r8d
  int v105; // esi
  int v106; // r14d
  unsigned int v107; // r15d
  __int64 v108; // rax
  int *p_m_size; // rdi
  int v110; // edx
  int v111; // edx
  int v112; // ecx
  int v113; // ecx
  hkOstream *v114; // rax
  __int64 v115; // r15
  int v116; // r8d
  unsigned int v117; // r11d
  int v118; // esi
  int v119; // r14d
  __int64 v120; // r9
  hkcdStaticMeshTreeBase::Primitive *v121; // rdx
  int v122; // ecx
  int v123; // eax
  int v124; // edi
  int v125; // ecx
  int v126; // ecx
  int v127; // ecx
  hkOstream *v128; // rax
  unsigned __int8 v129; // di
  __int64 sizeElem; // [rsp+20h] [rbp-E0h]
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *roots; // [rsp+28h] [rbp-D8h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v133; // [rsp+30h] [rbp-D0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *masterTree; // [rsp+38h] [rbp-C8h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v135; // [rsp+40h] [rbp-C0h]
  int v136; // [rsp+50h] [rbp-B0h]
  int v137; // [rsp+50h] [rbp-B0h]
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> quads; // [rsp+60h] [rbp-A0h] BYREF
  hkcdStaticMeshTreeBase::BuildMapping mappinga; // [rsp+70h] [rbp-90h] BYREF
  hkVector4f c; // [rsp+A0h] [rbp-60h] BYREF
  hkVector4f v141; // [rsp+B0h] [rbp-50h] BYREF
  int v142; // [rsp+C0h] [rbp-40h]
  hkcdStaticMeshTreeBase::Section::Primitives *v143; // [rsp+D0h] [rbp-30h]
  int v144[3]; // [rsp+D8h] [rbp-28h] BYREF
  hkcdStaticMeshTreeBase::BuildConfig::Vrp m_vrp; // [rsp+E4h] [rbp-1Ch]
  hkcdStaticMeshTreeBase::BuildConfig::Pbd m_pbd; // [rsp+E8h] [rbp-18h]
  int m_verbosity; // [rsp+ECh] [rbp-14h]
  int v148; // [rsp+F0h] [rbp-10h]
  float m_weldTolerance; // [rsp+F4h] [rbp-Ch]
  float m_convexRadius; // [rsp+F8h] [rbp-8h]
  float m_degenerateTolerance; // [rsp+FCh] [rbp-4h]
  float m_maxCompressionError; // [rsp+100h] [rbp+0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> config; // [rsp+108h] [rbp+8h] BYREF
  hkcdStaticMeshTreeBase::BuildConfig v154; // [rsp+140h] [rbp+40h] BYREF
  int v155; // [rsp+16Ch] [rbp+6Ch]
  char v156; // [rsp+170h] [rbp+70h] BYREF
  hkSimdFloat32 tolerance; // [rsp+1F0h] [rbp+F0h] BYREF
  char buf[560]; // [rsp+200h] [rbp+100h] BYREF
  hkResult result; // [rsp+448h] [rbp+348h] BYREF
  int v160; // [rsp+450h] [rbp+350h]
  hkcdStaticMeshTreeBase::BuildMapping *v161; // [rsp+458h] [rbp+358h]

  v161 = mapping;
  v4 = 0;
  m_meshCInfo = baseProvider->m_meshCInfo;
  config.m_provider = baseProvider;
  config.m_vMap.m_capacityAndFlags = 0x80000000;
  config.m_vMap.m_data = 0i64;
  config.m_vMap.m_size = 0;
  config.m_validTriangles.m_storage.m_words.m_data = 0i64;
  config.vfptr = (hkGeometryUtils::IVerticesVtbl *)&hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>::`vftable;
  config.m_validTriangles.m_storage.m_words.m_size = 0;
  config.m_validTriangles.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  config.m_validTriangles.m_storage.m_numBits = 0;
  v7 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)mapping;
  v10 = (*(__int64 (__fastcall **)(hkpBvCompressedMeshShapeCinfo *))m_meshCInfo->vfptr->gap8)(m_meshCInfo);
  v11 = v10;
  if ( v10 > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&config.m_vMap.m_data, v10, 4);
  config.m_vMap.m_size = v11;
  v12 = 0;
  if ( v11 > 0 )
  {
    v13 = 0i64;
    do
      config.m_vMap.m_data[v13++] = v12++;
    while ( v12 < config.m_vMap.m_size );
  }
  config.m_validTriangles.m_storage.m_numBits = baseProvider->m_meshCInfo->vfptr->getNumTriangles(baseProvider->m_meshCInfo);
  v14 = (config.m_validTriangles.m_storage.m_numBits + 31) >> 5;
  if ( (config.m_validTriangles.m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF) < v14 )
  {
    v15 = (config.m_validTriangles.m_storage.m_numBits + 31) >> 5;
    if ( v14 < 2 * (config.m_validTriangles.m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF) )
      v15 = 2 * (config.m_validTriangles.m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&config.m_validTriangles.m_storage.m_words.m_data,
      v15,
      4);
  }
  config.m_validTriangles.m_storage.m_words.m_size = v14;
  if ( v14 - 1 >= 0 )
  {
    m_data = config.m_validTriangles.m_storage.m_words.m_data;
    for ( i = (unsigned int)v14; i; --i )
      *m_data++ = -1;
    v7 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v161;
  }
  v18 = *(_DWORD *)&baseConfig->m_globalOptimizations.m_bool;
  *(_DWORD *)&v154.m_weldVertices.m_bool = 0;
  v144[0] = v18;
  v144[1] = *(_DWORD *)&baseConfig->m_vertexHasFlags.m_bool;
  v144[2] = baseConfig->m_balanceThreshold;
  m_vrp = baseConfig->m_vrp;
  m_pbd = baseConfig->m_pbd;
  m_verbosity = baseConfig->m_verbosity;
  v148 = *(_DWORD *)&baseConfig->m_weldVertices.m_bool;
  m_weldTolerance = baseConfig->m_weldTolerance;
  m_convexRadius = baseConfig->m_convexRadius;
  m_degenerateTolerance = baseConfig->m_degenerateTolerance;
  m_maxCompressionError = baseConfig->m_maxCompressionError;
  for ( j = 0i64; j < 3; ++j )
  {
    *((_DWORD *)&v154.m_vrp + j) = 0;
    *((_DWORD *)&v154.m_globalOptimizations.m_bool + j) = 0;
  }
  while ( 1 )
  {
    hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::clear(this);
    mappinga.m_triangleIndexToKey.m_data = 0i64;
    mappinga.m_triangleIndexToKey.m_size = 0;
    mappinga.m_triangleIndexToKey.m_capacityAndFlags = 0x80000000;
    mappinga.m_customIndexToKey.m_size = 0;
    mappinga.m_customIndexToKey.m_data = 0i64;
    mappinga.m_customIndexToKey.m_capacityAndFlags = 0x80000000;
    mappinga.m_triangleVertexRotations.m_data = 0i64;
    c.m_quad.m128_u64[0] = 0i64;
    *(_QWORD *)&mappinga.m_triangleVertexRotations.m_size = 0i64;
    quads.m_data = 0i64;
    quads.m_size = 0;
    quads.m_capacityAndFlags = 0x80000000;
    if ( !hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep12<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *)v144,
            (hkcdStaticMeshTreeBase::BuildConfig *)&config,
            v7,
            &mappinga,
            &quads,
            (hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *)&mappinga.m_customIndexToKey,
            v133)
      || !hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep3<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *)v144,
            &v154,
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *)&config,
            v7,
            &mappinga,
            &quads,
            (hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *)&mappinga.m_customIndexToKey,
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *)this,
            v135) )
    {
      break;
    }
    quads.m_size = 0;
    if ( quads.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        quads.m_data,
        24 * (quads.m_capacityAndFlags & 0x3FFFFFFF));
    quads.m_data = 0i64;
    quads.m_capacityAndFlags = 0x80000000;
    mappinga.m_customIndexToKey.m_size = 0;
    if ( mappinga.m_customIndexToKey.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        mappinga.m_customIndexToKey.m_data,
        mappinga.m_customIndexToKey.m_capacityAndFlags << 6);
    mappinga.m_customIndexToKey.m_data = 0i64;
    mappinga.m_customIndexToKey.m_capacityAndFlags = 0x80000000;
    mappinga.m_triangleIndexToKey.m_size = 0;
    if ( mappinga.m_triangleIndexToKey.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        mappinga.m_triangleIndexToKey.m_data,
        12 * (mappinga.m_triangleIndexToKey.m_capacityAndFlags & 0x3FFFFFFF));
    m_size = this->m_primitives.m_size;
    mappinga.m_triangleIndexToKey.m_data = 0i64;
    mappinga.m_triangleIndexToKey.m_capacityAndFlags = 0x80000000;
    this->m_numPrimitiveKeys = 0;
    if ( m_size > 0 )
    {
      v21 = this->m_primitives.m_data;
      v22 = 0;
      v23 = (unsigned int)m_size;
      do
      {
        v24 = (unsigned __int8)v21->m_indices[3];
        v25 = (unsigned __int8)v21->m_indices[2];
        v26 = (unsigned __int8)v21->m_indices[1];
        if ( v24 == v25 )
        {
          v27 = 1;
          if ( v25 == v26 )
            v27 = 3;
        }
        else if ( v21->m_indices[0] != -34 || v26 != 173 || v25 != 222 || (v28 = v24 == 173, v27 = 0, !v28) )
        {
          v27 = 2;
        }
        ++v21;
        v22 += (v27 == 2) + 1;
        this->m_numPrimitiveKeys = v22;
        --v23;
      }
      while ( v23 );
    }
    v29 = this->m_sections.m_size;
    v30 = 0;
    if ( v29 )
    {
      for ( k = 0;
            k != -1;
            k = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getNextKey(
                  this,
                  k) )
      {
        if ( k > v30 )
          v30 = k;
      }
      v29 = this->m_sections.m_size;
    }
    this->m_maxKeyValue = v30;
    this->m_bitsPerKey = 0;
    v32 = v30 + 1;
    if ( v32 )
    {
      v33 = 0;
      do
      {
        ++v33;
        v32 >>= 1;
      }
      while ( v32 );
      this->m_bitsPerKey = v33;
    }
    m_bitsPerKey = this->m_bitsPerKey;
    if ( !m_bitsPerKey )
      m_bitsPerKey = this->m_numPrimitiveKeys != 0;
    v28 = m_vrp == VRP_EXTERN;
    this->m_bitsPerKey = m_bitsPerKey;
    if ( v28 )
      goto LABEL_149;
    v35 = 0;
    result.m_enum = HK_SUCCESS;
    tolerance.m_real = _mm_shuffle_ps((__m128)LODWORD(m_degenerateTolerance), (__m128)LODWORD(m_degenerateTolerance), 0);
    if ( m_pbd == PBD_MARK )
    {
      v66 = 0;
      v67 = 0;
      v160 = 0;
      if ( v29 )
      {
        v68 = 0;
        m_enum = HK_SUCCESS;
        p_m_primitives = &this->m_sections.m_data->m_primitives;
        v142 = 0;
LABEL_97:
        v71 = p_m_primitives->m_data;
        v72 = this->m_primitives.m_data;
        quads.m_data = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *)p_m_primitives;
        v137 = v68;
        v73 = (unsigned int *)&v72[v71 >> 8];
        mappinga.m_triangleIndexToKey.m_data = v73;
        while ( 1 )
        {
          do
          {
            v74 = 2 * v66;
            v75 = this->m_primitives.m_data;
            v76 = (v68 << 8) | v74;
            v77 = ((unsigned __int8)v76 >> 1) + (this->m_sections.m_data[v76 >> 8].m_primitives.m_data >> 8);
            v78 = (unsigned __int8)v75[v77].m_indices[3];
            v79 = (unsigned __int8)v75[v77].m_indices[2];
            v80 = (unsigned __int8)v75[v77].m_indices[1];
            if ( v78 == v79 )
            {
              v81 = 1i64;
              if ( v79 == v80 )
                v81 = 3i64;
            }
            else if ( v75[v77].m_indices[0] == -34 && v80 == 173 && v79 == 222 && v78 == 173 )
            {
              v81 = 0i64;
            }
            else
            {
              v81 = 2i64;
            }
            LODWORD(v143) = hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v81];
            if ( (_DWORD)v143 )
            {
              hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getQuadVertices(
                this,
                v76,
                (hkVector4f *)&mappinga.m_customIndexToKey);
              if ( (int)v143 > 1
                && hkcdTriangleUtil::isDegenerate((hkVector4f *)&mappinga.m_customIndexToKey, &c, &v141, &tolerance) )
              {
                v82 = v161;
                ++m_enum;
                v75[v77].m_indices[3] = v75[v77].m_indices[2];
                v83 = v82->m_triangleIndexToKey.m_size;
                v84 = 0i64;
                result.m_enum = m_enum;
                if ( v83 <= 0 )
                {
LABEL_115:
                  v84 = -1i64;
                }
                else
                {
                  v85 = v82->m_triangleIndexToKey.m_data;
                  while ( *v85 != v76 + 1 )
                  {
                    ++v84;
                    ++v85;
                    if ( v84 >= v83 )
                      goto LABEL_115;
                  }
                }
                v82->m_triangleIndexToKey.m_data[v84] = -1;
              }
              if ( hkcdTriangleUtil::isDegenerate(
                     (hkVector4f *)&mappinga.m_customIndexToKey,
                     (hkVector4f *)&mappinga.m_triangleVertexRotations,
                     &c,
                     &tolerance) )
              {
                v86 = v75[v77].m_indices[3];
                v87 = v75[v77].m_indices[2];
                if ( v87 == v86 )
                {
                  v75[v77] = (hkcdStaticMeshTreeBase::Primitive)-1377915426;
                }
                else
                {
                  v75[v77].m_indices[1] = v87;
                  v75[v77].m_indices[2] = v86;
                }
                v88 = 0i64;
                v89 = v161->m_triangleIndexToKey.m_size;
                result.m_enum = m_enum + 1;
                if ( v89 <= 0 )
                {
LABEL_125:
                  v88 = -1i64;
                }
                else
                {
                  v90 = v161->m_triangleIndexToKey.m_data;
                  while ( *v90 != v76 )
                  {
                    ++v88;
                    ++v90;
                    if ( v88 >= v89 )
                      goto LABEL_125;
                  }
                }
                v161->m_triangleIndexToKey.m_data[v88] = -1;
              }
              v73 = mappinga.m_triangleIndexToKey.m_data;
            }
            v91 = HIBYTE(v73[v160]);
            v92 = BYTE2(v73[v160]);
            v93 = BYTE1(v73[v160]);
            do
            {
              v94 = ++v67;
              if ( v91 == v92 )
              {
                v95 = 1i64;
                if ( v92 == v93 )
                  v95 = 3i64;
              }
              else if ( LOBYTE(v73[v160]) == 0xDE && v93 == 173 && v92 == 222 && v91 == 173 )
              {
                v95 = 0i64;
              }
              else
              {
                v95 = 2i64;
              }
            }
            while ( v94 < hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v95] );
            m_enum = result.m_enum;
            v68 = v137;
            v96 = (unsigned __int8)quads.m_data->m_edges[0];
            v66 = v160 + 1;
            v67 = 0;
            v160 = v66;
          }
          while ( v66 < v96 );
          v66 = 0;
          ++v4;
          v160 = 0;
          if ( v4 >= this->m_sections.m_size )
            break;
          if ( v4 != v137 || v142 != v4 )
          {
            v142 = v4;
            v68 = v4;
            p_m_primitives = &this->m_sections.m_data[v4].m_primitives;
            goto LABEL_97;
          }
        }
        v35 = result.m_enum;
      }
      if ( (m_verbosity & 1) != 0 && v35 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, buf, 512);
        v97 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, "Found ");
        v98 = hkOstream::operator<<(v97, v35);
        hkOstream::operator<<(v98, " degenerated triangle(s) after build, marking them as invalid.");
        hkError::messageReport(0, buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
      }
LABEL_149:
      if ( (m_verbosity & 2) != 0 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, buf, 512);
        v99 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, "==== Statistics for ");
        v100 = hkOstream::operator<<(v99, this);
        hkOstream::operator<<(v100, " =====\n");
        hkError::messageReport(0, buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getMemoryFootPrint(
          this,
          (hkcdStaticMeshTreeBase::MemoryStatistics *)&quads);
        m_capacityAndFlags = quads.m_capacityAndFlags;
        *(_QWORD *)&v154.m_convexRadius = &v156;
        v155 = -2147483520;
        LODWORD(v154.m_maxCompressionError) = 1;
        v156 = 0;
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Total size: %d Kb\n",
          (unsigned int)((quads.m_capacityAndFlags + 512) >> 10));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Collision: %d (%d%%)\n",
          LODWORD(quads.m_data),
          (unsigned int)((100 * LODWORD(quads.m_data) + 50) / m_capacityAndFlags));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Geometry: %d (%d%%)\n",
          HIDWORD(quads.m_data),
          (unsigned int)((100 * HIDWORD(quads.m_data) + 50) / m_capacityAndFlags));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Data: %d (%d%%)\n",
          (unsigned int)quads.m_size,
          (unsigned int)((100 * quads.m_size + 50) / m_capacityAndFlags));
        v102 = v154.m_vrp + v154.m_pbd + v154.m_verbosity;
        if ( v102 < 1 )
          v102 = 1;
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Compression CM_GLOBAL : %d (%d%%)\n",
          (unsigned int)v154.m_vrp,
          (unsigned int)((100 * v154.m_vrp + 50) / v102));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Compression CM_LOCAL_4 : %d (%d%%)\n",
          (unsigned int)v154.m_pbd,
          (unsigned int)((100 * v154.m_pbd + 50) / v102));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Compression CM_LOCAL_2 : %d (%d%%)\n",
          (unsigned int)v154.m_verbosity,
          (unsigned int)((100 * v154.m_verbosity + 50) / v102));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Tags: %d (%d bytes)\n",
          *(int *)&v154.m_weldVertices.m_bool,
          2i64 * *(int *)&v154.m_weldVertices.m_bool);
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, buf, 512);
        v103 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, &customCaption);
        hkOstream::operator<<(v103, *(const char **)&v154.m_convexRadius);
        hkError::messageReport(0, buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        hkStringBuf::clear((hkStringBuf *)&v154.m_convexRadius);
        v104 = this->m_sections.m_size;
        v105 = 256;
        v106 = 0;
        v107 = 0;
        if ( v104 )
        {
          if ( v104 > 0 )
          {
            v108 = (unsigned int)v104;
            p_m_size = &this->m_sections.m_data->hkcdStaticMeshTreeBase::m_nodes.m_size;
            do
            {
              v110 = *p_m_size;
              p_m_size += 24;
              v111 = (v110 + 1) >> 1;
              v112 = v111;
              if ( v105 < v111 )
                v112 = v105;
              v105 = v112;
              v113 = v111;
              if ( v106 > v111 )
                v113 = v106;
              v107 += v111;
              v106 = v113;
              --v108;
            }
            while ( v108 );
          }
          v107 = (int)v107 / v104;
        }
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Number of pages: %u\n",
          (unsigned int)(unsigned __int8)this->m_sections.m_data[this->m_sections.m_size - 1].m_page + 1);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Number of sections: %d\n",
          (unsigned int)this->m_sections.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Number of primitives: %d\n",
          (unsigned int)this->m_primitives.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Number of shared indices: %d\n",
          (unsigned int)this->m_sharedVerticesIndex.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Number of shared vertices: %d\n",
          (unsigned int)this->m_sharedVertices.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Number of packed vertices: %d\n",
          (unsigned int)this->m_packedVertices.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Number of data-runs: %d\n",
          (unsigned int)this->m_primitiveDataRuns.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Number of keys: %d\n",
          (unsigned int)this->m_numPrimitiveKeys);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Min. keys per section: %d\n",
          (unsigned int)v105);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Max. keys per section: %d\n",
          (unsigned int)v106);
        hkStringBuf::appendPrintf((hkStringBuf *)&v154.m_convexRadius, "Avg. keys per section: %d\n", v107);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Data to primitive ratio: %f\n",
          (float)((float)this->m_primitiveDataRuns.m_size / (float)this->m_primitives.m_size));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Bits per key: %d\n",
          (unsigned int)this->m_bitsPerKey);
        hkStringBuf::appendPrintf((hkStringBuf *)&v154.m_convexRadius, "Max key value: %u\n", this->m_maxKeyValue);
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, buf, 512);
        v114 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, &customCaption);
        hkOstream::operator<<(v114, *(const char **)&v154.m_convexRadius);
        hkError::messageReport(0, buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        hkStringBuf::clear((hkStringBuf *)&v154.m_convexRadius);
        v115 = this->m_primitives.m_size;
        v116 = 0;
        v117 = 0;
        v118 = 0;
        v119 = 0;
        v120 = v115;
        if ( (int)v115 > 0 )
        {
          v121 = this->m_primitives.m_data;
          do
          {
            v122 = (unsigned __int8)v121->m_indices[3];
            v123 = (unsigned __int8)v121->m_indices[2];
            v124 = (unsigned __int8)v121->m_indices[1];
            if ( v122 == v123 )
            {
              v125 = 1;
              if ( v123 == v124 )
                v125 = 3;
            }
            else if ( v121->m_indices[0] != -34 || v124 != 173 || v123 != 222 || (v28 = v122 == 173, v125 = 0, !v28) )
            {
              v125 = 2;
            }
            if ( v125 )
            {
              v126 = v125 - 1;
              if ( v126 )
              {
                v127 = v126 - 1;
                if ( v127 )
                {
                  if ( v127 == 1 )
                    ++v119;
                }
                else
                {
                  ++v117;
                }
              }
              else
              {
                ++v118;
              }
            }
            else
            {
              ++v116;
            }
            ++v121;
            --v120;
          }
          while ( v120 );
          LODWORD(v115) = this->m_primitives.m_size;
        }
        LODWORD(v135) = v116;
        LODWORD(masterTree) = (100 * v119 + 50) / (int)v115;
        LODWORD(v133) = v119;
        LODWORD(roots) = (100 * v118 + 50) / (int)v115;
        LODWORD(sizeElem) = v118;
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v154.m_convexRadius,
          "Quads: %d(%d%%) Triangles: %d(%d%%) Customs: %d(%d%%) Invalids: %d(%d%%)\n",
          v117,
          (unsigned int)((int)(100 * v117 + 50) / (int)v115),
          sizeElem,
          roots,
          v133,
          masterTree,
          v135,
          (100 * v116 + 50) / (int)v115);
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, buf, 512);
        v128 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, &customCaption);
        hkOstream::operator<<(v128, *(const char **)&v154.m_convexRadius);
        hkError::messageReport(0, buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        hkStringBuf::clear((hkStringBuf *)&v154.m_convexRadius);
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, buf, 512);
        hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, "=====================");
        hkError::messageReport(0, buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        v154.m_maxCompressionError = 0.0;
        if ( v155 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            *(void **)&v154.m_convexRadius,
            v155 & 0x3FFFFFFF);
      }
      v129 = 1;
      goto LABEL_193;
    }
    if ( m_pbd != PBD_REMOVE )
      goto LABEL_149;
    v36 = 0;
    v37 = 0;
    v38 = 0;
    if ( !v29 )
      goto LABEL_149;
    v136 = 0;
    v39 = 0;
    v40 = &this->m_sections.m_data->m_primitives;
    v160 = 0;
LABEL_54:
    v41 = v40->m_data;
    v42 = this->m_primitives.m_data;
    v143 = v40;
    v43 = &v42[v41 >> 8];
    while ( 1 )
    {
      while ( 1 )
      {
        v44 = v38 | (v39 << 8) | (2 * v37);
        v45 = this->m_primitives.m_data;
        v46 = ((unsigned __int8)v44 >> 1) + (this->m_sections.m_data[v44 >> 8].m_primitives.m_data >> 8);
        v47 = (unsigned __int8)v45[v46].m_indices[3];
        v48 = (unsigned __int8)v45[v46].m_indices[2];
        v49 = (unsigned __int8)v45[v46].m_indices[1];
        if ( v47 == v48 )
        {
          v50 = 1i64;
          if ( v48 == v49 )
            v50 = 3i64;
        }
        else if ( v45[v46].m_indices[0] == -34 && v49 == 173 && v48 == 222 && v47 == 173 )
        {
          v50 = 0i64;
        }
        else
        {
          v50 = 2i64;
        }
        if ( hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v50] )
        {
          v51 = 0;
          v52 = 0i64;
          v53 = v161->m_triangleIndexToKey.m_size;
          if ( v53 <= 0 )
          {
LABEL_70:
            v51 = -1;
          }
          else
          {
            v54 = v161->m_triangleIndexToKey.m_data;
            while ( *v54 != v44 )
            {
              ++v52;
              ++v51;
              ++v54;
              if ( v52 >= v53 )
                goto LABEL_70;
            }
          }
          v55 = v51;
          v56 = v51 & 0x1F;
          v57 = v55 >> 5;
          if ( ((config.m_validTriangles.m_storage.m_words.m_data[v57] >> v56) & 1) != 0 )
          {
            hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getTriangleVertices(
              this,
              v44,
              (hkVector4f *)&mappinga.m_customIndexToKey);
            isDegenerate = hkcdTriangleUtil::isDegenerate(
                             (hkVector4f *)&mappinga.m_customIndexToKey,
                             (hkVector4f *)&mappinga.m_triangleVertexRotations,
                             &c,
                             &tolerance);
            v40 = v143;
            v39 = v160;
            if ( isDegenerate )
            {
              config.m_validTriangles.m_storage.m_words.m_data[v57] &= ~(1 << v56);
              v35 = ++result.m_enum;
            }
            else
            {
              v35 = result.m_enum;
            }
          }
          else
          {
            v35 = result.m_enum;
          }
        }
        v59 = v38 + 1;
        v60 = (unsigned __int8)v43[v37].m_indices[3];
        v61 = (unsigned __int8)v43[v37].m_indices[2];
        v62 = (unsigned __int8)v43[v37].m_indices[1];
        ++v38;
        if ( v60 == v61 )
        {
          v63 = 1i64;
          if ( v61 == v62 )
            v63 = 3i64;
        }
        else if ( v43[v37].m_indices[0] == -34 && v62 == 173 && v61 == 222 && v60 == 173 )
        {
          v63 = 0i64;
        }
        else
        {
          v63 = 2i64;
        }
        if ( v59 >= hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v63] )
        {
          ++v37;
          v38 = 0;
          if ( v37 >= LOBYTE(v40->m_data) )
            break;
        }
      }
      ++v36;
      v37 = 0;
      if ( v36 >= this->m_sections.m_size )
        break;
      if ( v36 != v39 || v136 != v36 )
      {
        v136 = v36;
        v39 = v36;
        v160 = v36;
        v40 = &this->m_sections.m_data[v36].m_primitives;
        goto LABEL_54;
      }
    }
    if ( !v35 )
      goto LABEL_149;
    v7 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v161;
    LOBYTE(v148) = 0;
    v4 = 0;
    if ( (m_verbosity & 1) != 0 )
    {
      hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, buf, 512);
      v64 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, "Found ");
      v65 = hkOstream::operator<<(v64, v35);
      hkOstream::operator<<(v65, " degenerated triangle(s) after build, rebuilding.");
      hkError::messageReport(0, buf, 0i64, 0);
      hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
    }
  }
  quads.m_size = 0;
  if ( quads.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      quads.m_data,
      24 * (quads.m_capacityAndFlags & 0x3FFFFFFF));
  quads.m_data = 0i64;
  quads.m_capacityAndFlags = 0x80000000;
  mappinga.m_customIndexToKey.m_size = 0;
  if ( mappinga.m_customIndexToKey.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      mappinga.m_customIndexToKey.m_data,
      mappinga.m_customIndexToKey.m_capacityAndFlags << 6);
  mappinga.m_customIndexToKey.m_data = 0i64;
  mappinga.m_customIndexToKey.m_capacityAndFlags = 0x80000000;
  mappinga.m_triangleIndexToKey.m_size = 0;
  if ( mappinga.m_triangleIndexToKey.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      mappinga.m_triangleIndexToKey.m_data,
      12 * (mappinga.m_triangleIndexToKey.m_capacityAndFlags & 0x3FFFFFFF));
  v129 = 0;
LABEL_193:
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>::~BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>(&config);
  return v129;
}loc.vfptr->bufFree(
      &hkContainer

// File Line: 1477
// RVA: 0xDF1110
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree::countVertices<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *this,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *tree,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *provider,
        hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *quads)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v5; // r15
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v6; // r13
  unsigned __int64 m_node; // r9
  int v8; // r14d
  hkcdDynamicTree::CodecRawUlong *m_data; // rdx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // r12
  unsigned __int64 v12; // r13
  __int64 v13; // rdi
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v14; // rbx
  int m_size; // esi
  int v16; // ebx
  hkpBvCompressedMeshShape_Internals::GeometryProvider *m_provider; // rax
  hkpBvCompressedMeshShapeCinfo *m_meshCInfo; // rcx
  hkpBvCompressedMeshShapeCinfoVtbl *vfptr; // rax
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // eax
  __int64 v24; // r8
  __int64 v25; // r10
  int v26; // ecx
  __int64 v27; // rax
  __int64 v28; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v29; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v30; // ebx
  int *v31; // rdx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v32; // ebx
  int *v33; // rdx
  int v34; // ebx
  int *v35; // rdx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v36; // ebx
  int *v37; // rdx
  int v38; // eax
  unsigned __int64 m_parent; // rcx
  unsigned __int64 i; // r8
  unsigned __int64 v41; // rdi
  int v42; // r12d
  int v43; // esi
  int v44; // ebx
  hkpBvCompressedMeshShapeCinfo *v45; // rcx
  int v46; // eax
  int v47; // ecx
  int j; // edx
  unsigned __int64 v49; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v50; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v51; // ebx
  int *v52; // rdx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v53; // ebx
  int *v54; // rdx
  int v55; // ebx
  int *v56; // r8
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v57; // ebx
  int *v58; // rdx
  __int64 k; // r8
  int v60; // ecx
  __int64 v61; // rax
  int v62; // eax
  int v64; // [rsp+20h] [rbp-C0h] BYREF
  int v65; // [rsp+24h] [rbp-BCh]
  int v66; // [rsp+28h] [rbp-B8h]
  __int64 v67; // [rsp+30h] [rbp-B0h] BYREF
  __int64 v68; // [rsp+38h] [rbp-A8h]
  int v69; // [rsp+40h] [rbp-A0h]
  int v70; // [rsp+48h] [rbp-98h] BYREF
  int v71; // [rsp+4Ch] [rbp-94h]
  int v72; // [rsp+50h] [rbp-90h]
  int v73; // [rsp+58h] [rbp-88h] BYREF
  int v74; // [rsp+5Ch] [rbp-84h]
  hkcdStaticMeshTreeBase::BuildCustomInfos customPrimitive; // [rsp+60h] [rbp-80h] BYREF
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v76; // [rsp+A0h] [rbp-40h]
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v77; // [rsp+A8h] [rbp-38h]
  int v78[256]; // [rsp+B0h] [rbp-30h]
  int v79; // [rsp+4B0h] [rbp+3D0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v80; // [rsp+500h] [rbp+420h]
  hkcdDynamicTree::CodecRawUlong **v81; // [rsp+508h] [rbp+428h]

  v5 = provider;
  v6 = this;
  if ( this->m_numVertices >= 0 )
    return (unsigned int)this->m_numVertices;
  m_node = this->m_node;
  v76 = provider;
  v77 = quads;
  v8 = 0;
  v79 = 0;
  customPrimitive.m_aabb.m_max.m_quad.m128_u64[1] = m_node;
  if ( m_node )
  {
    m_data = tree->m_nodes.m_data;
    v10 = m_node << 6;
    if ( LODWORD(m_data[m_node].m_children[0]) )
    {
      v11 = *(unsigned __int64 *)((char *)m_data->m_children + v10);
      if ( v11 )
      {
        do
        {
          v12 = v11 << 6;
          if ( !LODWORD(m_data[v11].m_children[0]) && v8 != 256 )
          {
            v13 = *(int *)((char *)&m_data->m_children[1] + v12);
            v14 = v77;
            v69 = 0;
            v67 = 0i64;
            v68 = 0i64;
            m_size = v77->m_size;
            if ( (int)v13 < m_size )
            {
              v28 = v13;
              v29 = v77->m_data;
              v30 = v77->m_data[v28].m_edges[0];
              v5->m_provider->m_meshCInfo->vfptr->getIndices(
                v5->m_provider->m_meshCInfo,
                *(_DWORD *)&v30 & 0x3FFFFFFF,
                &customPrimitive.m_aabb.m_min.m_quad.m128_i32[2]);
              v31 = v5->m_vMap.m_data;
              customPrimitive.m_aabb.m_min.m_quad.m128_i32[2] = v31[customPrimitive.m_aabb.m_min.m_quad.m128_i32[2]];
              customPrimitive.m_aabb.m_min.m_quad.m128_i32[3] = v31[customPrimitive.m_aabb.m_min.m_quad.m128_i32[3]];
              customPrimitive.m_aabb.m_max.m_quad.m128_i32[0] = v31[customPrimitive.m_aabb.m_max.m_quad.m128_i32[0]];
              LODWORD(v67) = customPrimitive.m_aabb.m_min.m_quad.m128_i32[(int)((*(unsigned int *)&v30 >> 30) + 1) % 3
                                                                        + 2];
              v32 = v29[v28].m_edges[0];
              v5->m_provider->m_meshCInfo->vfptr->getIndices(
                v5->m_provider->m_meshCInfo,
                *(_DWORD *)&v32 & 0x3FFFFFFF,
                &v73);
              v33 = v5->m_vMap.m_data;
              v73 = v33[v73];
              v74 = v33[v74];
              customPrimitive.m_aabb.m_min.m_quad.m128_i32[0] = v33[customPrimitive.m_aabb.m_min.m_quad.m128_i32[0]];
              HIDWORD(v67) = *(&v73 + (int)((*(unsigned int *)&v32 >> 30) + 2) % 3);
              v34 = ((*(_DWORD *)&v29[v28].m_edges[1] >> 30) + 1) % 3;
              v5->m_provider->m_meshCInfo->vfptr->getIndices(
                v5->m_provider->m_meshCInfo,
                *(_DWORD *)&v29[v28].m_edges[1] & 0x3FFFFFFF,
                &v70);
              v35 = v5->m_vMap.m_data;
              v70 = v35[v70];
              v71 = v35[v71];
              v72 = v35[v72];
              LODWORD(v68) = *(&v70 + v34);
              v36 = v29[v28].m_edges[1];
              v5->m_provider->m_meshCInfo->vfptr->getIndices(
                v5->m_provider->m_meshCInfo,
                *(_DWORD *)&v36 & 0x3FFFFFFF,
                &v64);
              v37 = v5->m_vMap.m_data;
              v64 = v37[v64];
              v65 = v37[v65];
              v66 = v37[v66];
              v23 = 4;
              HIDWORD(v68) = *(&v64 + (int)((*(unsigned int *)&v36 >> 30) + 2) % 3);
            }
            else if ( (int)v13 < (int)(m_size
                                     + ((__int64 (__fastcall *)(hkpBvCompressedMeshShapeCinfo *))v5->m_provider->m_meshCInfo->vfptr->getNumTriangles)(v5->m_provider->m_meshCInfo)) )
            {
              v5->m_provider->m_meshCInfo->vfptr->getIndices(
                v5->m_provider->m_meshCInfo,
                v13 - v14->m_size,
                (int *)&v67);
              LODWORD(v67) = v5->m_vMap.m_data[(int)v67];
              HIDWORD(v67) = v5->m_vMap.m_data[SHIDWORD(v67)];
              v23 = 3;
              LODWORD(v68) = v5->m_vMap.m_data[(int)v68];
            }
            else
            {
              v16 = v14->m_size;
              customPrimitive.m_maxError = 3.40282e38;
              customPrimitive.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
              m_provider = v5->m_provider;
              *(_QWORD *)&customPrimitive.m_numVertices = 0i64;
              m_meshCInfo = m_provider->m_meshCInfo;
              customPrimitive.m_layerData = 0;
              vfptr = m_meshCInfo->vfptr;
              customPrimitive.m_aabb.m_max.m_quad = _mm_xor_ps(
                                                      (__m128)_mm_shuffle_epi32(
                                                                _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                0),
                                                      (__m128)xmmword_141A712A0);
              customPrimitive.m_tags.m_size = 0;
              customPrimitive.m_compression = CM_LOCAL_4;
              v20 = vfptr->getNumTriangles(m_meshCInfo);
              hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(
                v5->m_provider,
                v13 - v20 - v16,
                &customPrimitive);
              v21 = 0;
              v22 = customPrimitive.m_tags.m_size + 2;
              if ( customPrimitive.m_tags.m_size + 2 > 0 )
              {
                do
                {
                  if ( v8 == 256 )
                    break;
                  ++v21;
                  v79 = v8 + 1;
                  v78[v8] = -1;
                  v8 = v79;
                }
                while ( v21 < v22 );
                v5 = v76;
              }
              v23 = v69;
            }
            v24 = 0i64;
            v25 = v23;
            if ( v23 > 0 )
            {
              do
              {
                v26 = 0;
                v27 = 0i64;
                if ( v8 <= 0 )
                  goto LABEL_22;
                while ( v78[v27] != *((_DWORD *)&v67 + v24) )
                {
                  ++v27;
                  ++v26;
                  if ( v27 >= v8 )
                    goto LABEL_22;
                }
                if ( v26 == -1 )
                {
LABEL_22:
                  v38 = *((_DWORD *)&v67 + v24);
                  v79 = v8 + 1;
                  v78[v8] = v38;
                  v8 = v79;
                  if ( v79 == 256 )
                    break;
                }
                ++v24;
              }
              while ( v24 < v25 );
              v5 = v76;
            }
            m_node = customPrimitive.m_aabb.m_max.m_quad.m128_u64[1];
          }
          m_data = *v81;
          if ( *(_DWORD *)((char *)(*v81)->m_children + v12) )
          {
            v11 = *(unsigned __int64 *)((char *)m_data->m_children + v12);
          }
          else
          {
            m_parent = *(unsigned __int64 *)((char *)&m_data->m_parent + v12);
            for ( i = v11; m_parent != m_node; m_parent = m_data[m_parent].m_parent )
            {
              if ( m_data[m_parent].m_children[1] != i )
                break;
              i = m_parent;
            }
            if ( m_parent )
              v11 = m_data[m_parent].m_children[1];
            else
              v11 = i;
            if ( m_parent == m_node && v11 == i )
              v11 = 0i64;
          }
        }
        while ( v11 );
        v6 = v80;
      }
    }
    else
    {
      v41 = *(int *)((char *)&m_data->m_children[1] + v10);
      v42 = 0;
      v67 = 0i64;
      v68 = 0i64;
      v43 = quads->m_size;
      if ( (int)v41 < v43 )
      {
        v49 = v41;
        v50 = quads->m_data;
        v51 = quads->m_data[v49].m_edges[0];
        provider->m_provider->m_meshCInfo->vfptr->getIndices(
          provider->m_provider->m_meshCInfo,
          *(_DWORD *)&v51 & 0x3FFFFFFF,
          &v64);
        v52 = v5->m_vMap.m_data;
        v64 = v52[v64];
        v65 = v52[v65];
        v66 = v52[v66];
        LODWORD(v67) = *(&v64 + (int)((*(unsigned int *)&v51 >> 30) + 1) % 3);
        v53 = v50[v49].m_edges[0];
        v5->m_provider->m_meshCInfo->vfptr->getIndices(v5->m_provider->m_meshCInfo, *(_DWORD *)&v53 & 0x3FFFFFFF, &v64);
        v54 = v5->m_vMap.m_data;
        v64 = v54[v64];
        v65 = v54[v65];
        v66 = v54[v66];
        HIDWORD(v67) = *(&v64 + (int)((*(unsigned int *)&v53 >> 30) + 2) % 3);
        v55 = ((*(_DWORD *)&v50[v49].m_edges[1] >> 30) + 1) % 3;
        v5->m_provider->m_meshCInfo->vfptr->getIndices(
          v5->m_provider->m_meshCInfo,
          *(_DWORD *)&v50[v49].m_edges[1] & 0x3FFFFFFF,
          &v64);
        v56 = v5->m_vMap.m_data;
        v64 = v56[v64];
        v65 = v56[v65];
        v66 = v56[v66];
        LODWORD(v68) = *(&v64 + v55);
        v57 = v50[v49].m_edges[1];
        v5->m_provider->m_meshCInfo->vfptr->getIndices(v5->m_provider->m_meshCInfo, *(_DWORD *)&v57 & 0x3FFFFFFF, &v64);
        v58 = v5->m_vMap.m_data;
        v42 = 4;
        v64 = v58[v64];
        v65 = v58[v65];
        v66 = v58[v66];
        HIDWORD(v68) = *(&v64 + (int)((*(unsigned int *)&v57 >> 30) + 2) % 3);
      }
      else if ( (int)v41 < (int)(v43
                               + ((__int64 (__fastcall *)(hkpBvCompressedMeshShapeCinfo *))provider->m_provider->m_meshCInfo->vfptr->getNumTriangles)(provider->m_provider->m_meshCInfo)) )
      {
        v5->m_provider->m_meshCInfo->vfptr->getIndices(v5->m_provider->m_meshCInfo, v41 - quads->m_size, (int *)&v67);
        v42 = 3;
        LODWORD(v67) = v5->m_vMap.m_data[(int)v67];
        HIDWORD(v67) = v5->m_vMap.m_data[SHIDWORD(v67)];
        LODWORD(v68) = v5->m_vMap.m_data[(int)v68];
      }
      else
      {
        v44 = quads->m_size;
        customPrimitive.m_maxError = FLOAT_3_40282e38;
        *(_QWORD *)&customPrimitive.m_numVertices = 0i64;
        customPrimitive.m_layerData = 0;
        customPrimitive.m_tags.m_size = 0;
        customPrimitive.m_compression = CM_LOCAL_4;
        customPrimitive.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
        v45 = v5->m_provider->m_meshCInfo;
        customPrimitive.m_aabb.m_max.m_quad = _mm_xor_ps(
                                                (__m128)_mm_shuffle_epi32(
                                                          _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                          0),
                                                (__m128)xmmword_141A712A0);
        v46 = v45->vfptr->getNumTriangles(v45);
        hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(
          v5->m_provider,
          v41 - v46 - v44,
          &customPrimitive);
        v47 = 0;
        for ( j = customPrimitive.m_tags.m_size + 2; v47 < j; v8 = v79 )
        {
          if ( v8 == 256 )
            break;
          ++v47;
          v79 = v8 + 1;
          v78[v8] = -1;
        }
      }
      for ( k = 0i64; k < v42; ++k )
      {
        v60 = 0;
        v61 = 0i64;
        if ( v8 <= 0 )
          goto LABEL_53;
        while ( v78[v61] != *((_DWORD *)&v67 + k) )
        {
          ++v61;
          ++v60;
          if ( v61 >= v8 )
            goto LABEL_53;
        }
        if ( v60 == -1 )
        {
LABEL_53:
          v62 = *((_DWORD *)&v67 + k);
          v79 = v8 + 1;
          v78[v8] = v62;
          v8 = v79;
          if ( v79 == 256 )
            break;
        }
      }
    }
  }
  v6->m_numVertices = v8;
  return (unsigned int)v8;
}

