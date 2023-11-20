// File Line: 25
// RVA: 0xDEACA0
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep12<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *this, hkcdStaticMeshTreeBase::BuildConfig *config, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *provider, hkcdStaticMeshTreeBase::BuildMapping *mapping, hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *quads, hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *roots, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *masterTree)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *v7; // r12
  hkcdStaticMeshTreeBase::BuildMapping *v8; // r13
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v9; // rbx
  hkcdStaticMeshTreeBase::BuildConfig *v10; // r15
  hkResultEnum v11; // eax
  int v12; // er8
  int v13; // er14
  void **v14; // rdi
  int v15; // er8
  int v16; // er8
  signed __int64 v17; // rsi
  int v18; // eax
  int v19; // eax
  int v20; // er9
  __int64 v21; // rdx
  _DWORD *v22; // rdi
  __int64 v23; // rcx
  int v24; // eax
  int v25; // ecx
  int v26; // ebx
  int v27; // ecx
  int v28; // er9
  __int64 v29; // r8
  _DWORD *v30; // rdi
  __int64 v31; // rcx
  signed int *v32; // rbx
  int v33; // eax
  int v34; // eax
  int v35; // er9
  __int64 v36; // rcx
  int v37; // eax
  void *v38; // rdi
  unsigned __int64 v39; // rcx
  __int64 v40; // rsi
  int v41; // edi
  __m128 v42; // xmm0
  hkResultEnum v43; // er14
  signed int v44; // er12
  __int64 v45; // r13
  __int64 v46; // rdx
  signed int v47; // ebx
  __int64 v48; // rdi
  hkGeometryUtils::IVertices v49; // rax
  hkOstream *v50; // rax
  hkOstream *v51; // rax
  int v52; // edi
  int v53; // ecx
  float *v54; // r8
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // er9
  int v59; // eax
  float *v60; // rdi
  __int64 i; // rcx
  int v62; // er9
  int v63; // edi
  hkResultEnum v64; // er12
  unsigned int v65; // er14
  unsigned int v66; // ebx
  __int64 v67; // r13
  unsigned int v68; // esi
  __int64 v69; // rcx
  int v70; // edx
  float v71; // edi
  int v72; // er9
  int v73; // er8
  int v74; // eax
  int v75; // eax
  int v76; // er10
  _DWORD *v77; // r11
  int v78; // edi
  int v79; // eax
  int v80; // er11
  int *v81; // r9
  int v82; // eax
  int v83; // edi
  int v84; // er9
  int *v85; // r8
  int v86; // er9
  int v87; // eax
  int v88; // eax
  hkResultEnum v89; // ebx
  __int64 v90; // r12
  __int64 v91; // r14
  __int64 v92; // rdi
  unsigned __int64 v93; // rsi
  __int64 *v94; // rax
  int v95; // er9
  __int64 v96; // rcx
  __int64 v97; // rcx
  __int64 v98; // rdx
  hkResultEnum v99; // edi
  int v100; // ecx
  __int64 v101; // rdx
  signed __int64 v102; // r12
  unsigned __int64 v103; // rbx
  int v104; // ecx
  int v105; // eax
  int v106; // eax
  int v107; // ecx
  _QWORD **v108; // rdi
  unsigned int v109; // esi
  __int64 v110; // rdx
  unsigned __int64 v111; // r9
  unsigned int v112; // er8
  unsigned int v113; // edi
  __int64 v114; // r8
  __int64 v115; // rdi
  unsigned int v116; // er10
  unsigned int v117; // er11
  unsigned int v118; // edi
  __int64 v119; // rax
  int v120; // er8
  int v121; // edx
  bool v122; // zf
  __m128 v123; // xmm1
  __m128 v124; // xmm3
  __m128 v125; // xmm4
  __m128 v126; // xmm4
  int v127; // ecx
  int v128; // ebx
  __int64 v129; // rdi
  hkGeometryUtils::IVertices v130; // rax
  __int64 v131; // rdi
  hkGeometryUtils::IVertices v132; // rax
  __m128 v133; // xmm5
  __m128 v134; // xmm4
  __m128 v135; // xmm2
  __m128 v136; // xmm3
  __m128 v137; // xmm0
  __m128 v138; // xmm1
  int v139; // eax
  float v140; // xmm7_4
  __m128 v141; // xmm0
  __m128 v142; // xmm1
  __m128 v143; // xmm5
  float v144; // xmm8_4
  __m128 v145; // xmm1
  float v146; // xmm6_4
  signed __int64 v147; // rcx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v148; // rsi
  signed __int64 v149; // r14
  __int64 v150; // rax
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v151; // er9
  int v152; // edi
  __int64 v153; // rdx
  __int64 v154; // rax
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v155; // edi
  __int64 v156; // rdx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v157; // edi
  int v158; // ebx
  __int64 v159; // rdx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v160; // edi
  __int64 v161; // rdx
  signed int v162; // er8
  int v163; // edi
  __int64 v164; // r12
  int v165; // er15
  unsigned int *v166; // r11
  unsigned int v167; // ebx
  unsigned __int64 v168; // r10
  __int32 v169; // er9
  hkResultEnum v170; // eax
  _QWORD *v171; // rdi
  int v172; // eax
  int v173; // eax
  int v174; // er9
  hkLifoAllocator *v175; // rax
  hkLifoAllocator *v176; // rcx
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> **v177; // rax
  unsigned __int64 v178; // rdx
  __int64 v179; // rcx
  __m128 v180; // xmm11
  __int64 v181; // r14
  __m128 v182; // xmm12
  __m128 v183; // xmm7
  __m128 v184; // xmm6
  int v185; // er12
  unsigned int *v186; // rdi
  signed __int64 v187; // rdx
  unsigned int v188; // edi
  __int64 v189; // rdx
  unsigned int v190; // edi
  __int64 v191; // rdx
  unsigned int v192; // edi
  __int64 v193; // rdx
  unsigned int v194; // edi
  __int64 v195; // rdx
  __m128 v196; // xmm7
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v197; // rbx
  __m128 v198; // xmm6
  unsigned __int64 v199; // r12
  hkcdDynamicTree::CodecRawUlong *v200; // rcx
  unsigned __int64 v201; // rsi
  hkcdDynamicTree::CodecRawUlong *v202; // rax
  __int64 v203; // rdi
  __m128 v204; // xmm9
  __m128 v205; // xmm10
  unsigned __int64 v206; // r8
  __int64 v207; // rax
  __m128 *v208; // rdi
  __m128 *v209; // r8
  __m128 v210; // xmm7
  __m128 v211; // xmm8
  __int64 v212; // rdx
  __int64 v213; // rcx
  __m128 v214; // xmm1
  __m128 v215; // xmm2
  __m128 v216; // xmm5
  __m128 v217; // xmm3
  __m128 v218; // xmm6
  __m128 v219; // xmm2
  __m128 v220; // xmm5
  __m128 v221; // xmm3
  __m128 v222; // xmm3
  __m128 v223; // xmm6
  __m128 v224; // xmm6
  unsigned __int64 v225; // r11
  unsigned __int64 v226; // r9
  signed __int64 v227; // rax
  __m128 v228; // xmm1
  int v229; // edi
  hkResultEnum v230; // er8
  hkResultEnum v231; // er14
  __int64 v232; // r12
  __int64 v233; // rdi
  hkGeometryUtils::IVertices v234; // rax
  __m128 v235; // xmm6
  __m128 v236; // xmm7
  __int64 v237; // rcx
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v238; // rbx
  unsigned __int64 v239; // r13
  hkcdDynamicTree::CodecRawUlong *v240; // rcx
  unsigned __int64 v241; // rsi
  hkcdDynamicTree::CodecRawUlong *v242; // rax
  __int64 v243; // rdi
  __m128 v244; // xmm9
  __m128 v245; // xmm10
  unsigned __int64 v246; // r8
  __int64 v247; // rax
  __m128 *v248; // rdi
  __m128 *v249; // r8
  __m128 v250; // xmm7
  __m128 v251; // xmm8
  __int64 v252; // rdx
  __int64 v253; // rcx
  __m128 v254; // xmm1
  __m128 v255; // xmm2
  __m128 v256; // xmm5
  __m128 v257; // xmm3
  __m128 v258; // xmm6
  __m128 v259; // xmm2
  __m128 v260; // xmm5
  __m128 v261; // xmm3
  __m128 v262; // xmm3
  __m128 v263; // xmm6
  __m128 v264; // xmm6
  unsigned __int64 v265; // r11
  unsigned __int64 v266; // r9
  signed __int64 v267; // rax
  __m128 v268; // xmm1
  int v269; // edi
  int v270; // er12
  signed __int64 v271; // r14
  __m128 v272; // xmm12
  hkpBvCompressedMeshShape_Internals::GeometryProvider *v273; // rcx
  hkVector4f v274; // xmm6
  hkVector4f v275; // xmm7
  int v276; // er8
  __m128 *v277; // rcx
  __int64 v278; // rax
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v279; // rbx
  unsigned __int64 v280; // r13
  hkcdDynamicTree::CodecRawUlong *v281; // rdx
  unsigned __int64 v282; // rsi
  hkcdDynamicTree::CodecRawUlong *v283; // rax
  __int64 v284; // rdi
  __m128 v285; // xmm9
  __m128 v286; // xmm10
  unsigned __int64 v287; // r8
  __int64 v288; // rax
  __m128 *v289; // rdi
  __m128 *v290; // r8
  __m128 v291; // xmm7
  __m128 v292; // xmm8
  __int64 v293; // rdx
  __int64 v294; // rcx
  __m128 v295; // xmm1
  __m128 v296; // xmm2
  __m128 v297; // xmm5
  __m128 v298; // xmm3
  __m128 v299; // xmm6
  __m128 v300; // xmm2
  __m128 v301; // xmm5
  __m128 v302; // xmm3
  __m128 v303; // xmm3
  __m128 v304; // xmm6
  __m128 v305; // xmm6
  unsigned __int64 v306; // r11
  unsigned __int64 v307; // r9
  signed __int64 v308; // rax
  __m128 v309; // xmm1
  __int64 v310; // rdi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v311; // r14
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v312; // rcx
  unsigned __int64 v313; // r10
  int v314; // esi
  hkcdDynamicTree::CodecRawUlong *v315; // rdx
  int v316; // er11
  unsigned __int64 v317; // r8
  unsigned __int64 v318; // rax
  unsigned __int64 v319; // rcx
  unsigned __int64 v320; // r8
  unsigned __int64 v321; // r9
  unsigned __int64 v322; // rax
  int j; // ecx
  int v324; // ecx
  unsigned __int64 v325; // rcx
  unsigned __int64 k; // rdi
  unsigned __int64 v327; // r11
  int v328; // er10
  hkcdDynamicTree::CodecRawUlong *v329; // rdx
  int v330; // ebx
  unsigned __int64 v331; // r8
  unsigned __int64 v332; // rax
  unsigned __int64 v333; // rcx
  unsigned __int64 v334; // r8
  unsigned __int64 v335; // r9
  unsigned __int64 v336; // rax
  int l; // ecx
  int v338; // ecx
  unsigned __int64 v339; // rcx
  unsigned __int64 m; // rdi
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v341; // r11
  __int64 v342; // rbx
  signed int v343; // er10
  hkcdDynamicTree::CodecRawUlong *v344; // rdx
  unsigned __int64 v345; // r8
  unsigned __int64 v346; // r9
  int v347; // ecx
  unsigned __int64 v348; // rcx
  unsigned __int64 n; // rdi
  _QWORD *v350; // rdx
  __int64 v351; // rax
  __int64 v352; // rcx
  _OWORD *v353; // rax
  __int128 v354; // xmm1
  __m128 v355; // xmm0
  unsigned __int8 v356; // si
  __int128 *v357; // rcx
  int v358; // eax
  char *v359; // rbx
  signed int v360; // edi
  hkLifoAllocator *v361; // rax
  int v362; // er8
  hkResult result; // [rsp+30h] [rbp-B0h]
  int v365; // [rsp+34h] [rbp-ACh]
  int v366; // [rsp+38h] [rbp-A8h]
  __int64 v367; // [rsp+40h] [rbp-A0h]
  __int64 v368; // [rsp+48h] [rbp-98h]
  __int64 v369; // [rsp+50h] [rbp-90h]
  hkSimdFloat32 tolerance; // [rsp+60h] [rbp-80h]
  int v371; // [rsp+70h] [rbp-70h]
  int v372; // [rsp+74h] [rbp-6Ch]
  int v373; // [rsp+78h] [rbp-68h]
  int v374; // [rsp+80h] [rbp-60h]
  int v375; // [rsp+84h] [rbp-5Ch]
  int v376; // [rsp+88h] [rbp-58h]
  __m128 v377; // [rsp+90h] [rbp-50h]
  __int64 v378; // [rsp+A0h] [rbp-40h]
  __int64 v379; // [rsp+A8h] [rbp-38h]
  int v380; // [rsp+B0h] [rbp-30h]
  __int64 v381; // [rsp+B8h] [rbp-28h]
  int v382; // [rsp+C0h] [rbp-20h]
  unsigned int v383; // [rsp+C8h] [rbp-18h]
  unsigned int v384; // [rsp+CCh] [rbp-14h]
  unsigned int v385; // [rsp+D0h] [rbp-10h]
  int v386; // [rsp+D8h] [rbp-8h]
  int v387; // [rsp+DCh] [rbp-4h]
  int v388; // [rsp+E0h] [rbp+0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v389; // [rsp+E8h] [rbp+8h]
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> **v390; // [rsp+F8h] [rbp+18h]
  int v391; // [rsp+100h] [rbp+20h]
  int v392; // [rsp+104h] [rbp+24h]
  void *p; // [rsp+108h] [rbp+28h]
  int v394; // [rsp+110h] [rbp+30h]
  unsigned int v395; // [rsp+118h] [rbp+38h]
  void *array; // [rsp+120h] [rbp+40h]
  hkaMatrix<float> v397; // [rsp+128h] [rbp+48h]
  hkcdStaticMeshTreeBase::BuildCustomInfos customPrimitive; // [rsp+140h] [rbp+60h]
  int v399; // [rsp+180h] [rbp+A0h]
  unsigned __int64 v400; // [rsp+188h] [rbp+A8h]
  __int64 v401; // [rsp+190h] [rbp+B0h]
  __int64 v402; // [rsp+198h] [rbp+B8h]
  __int64 v403; // [rsp+1A0h] [rbp+C0h]
  __int64 v404; // [rsp+1A8h] [rbp+C8h]
  hkVector4f a; // [rsp+1B0h] [rbp+D0h]
  hkVector4f b; // [rsp+1C0h] [rbp+E0h]
  hkVector4f c; // [rsp+1D0h] [rbp+F0h]
  __m128 v408; // [rsp+1E0h] [rbp+100h]
  __m128 v409; // [rsp+1F0h] [rbp+110h]
  __m128 v410; // [rsp+200h] [rbp+120h]
  char buf; // [rsp+210h] [rbp+130h]
  __int64 v412; // [rsp+4D0h] [rbp+3F0h]
  hkResult v413[2]; // [rsp+4D8h] [rbp+3F8h]
  hkResult vars0; // [rsp+4E0h] [rbp+400h]
  hkcdStaticMeshTreeBase::BuildMapping *retaddr; // [rsp+4E8h] [rbp+408h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *v416; // [rsp+4F0h] [rbp+410h]
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v417; // [rsp+4F8h] [rbp+418h]

  v417 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)config;
  v416 = this;
  v7 = this;
  v8 = mapping;
  v9 = provider;
  v10 = config;
  v11 = (*(unsigned int (**)(void))(**(_QWORD **)(*(_QWORD *)&config->m_balanceThreshold + 8i64) + 16i64))();
  v12 = HIDWORD(v9->m_provider);
  v13 = v11;
  vars0.m_enum = v11;
  LODWORD(v9->m_provider) = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v9->vfptr,
      4 * v12);
  v14 = (void **)&v9->m_validTriangles.m_storage.m_words.m_data;
  v9->vfptr = 0i64;
  HIDWORD(v9->m_provider) = 2147483648;
  v15 = v9->m_validTriangles.m_storage.m_words.m_capacityAndFlags;
  array = v14;
  *((_DWORD *)v14 + 2) = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *v14,
      v15 & 0x3FFFFFFF);
  *v14 = 0i64;
  v9->m_validTriangles.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v16 = v9->m_vMap.m_capacityAndFlags;
  v17 = (signed __int64)&v9->m_vMap;
  v9->m_vMap.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)v17,
      4 * v16);
  *(_QWORD *)v17 = 0i64;
  v9->m_vMap.m_capacityAndFlags = 2147483648;
  v18 = HIDWORD(v9->m_provider) & 0x3FFFFFFF;
  if ( v18 < v13 )
  {
    v19 = 2 * v18;
    v20 = v13;
    if ( v13 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9, v20, 4);
  }
  v21 = SLODWORD(v9->m_provider);
  v22 = (_DWORD *)((char *)v9->vfptr + 4 * v21);
  v23 = v13 - (signed int)v21;
  if ( v23 > 0 )
  {
    while ( v23 )
    {
      *v22 = -1;
      ++v22;
      --v23;
    }
  }
  LODWORD(v9->m_provider) = v13;
  v24 = (*(__int64 (**)(void))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64) + 64i64))();
  v25 = v9->m_vMap.m_capacityAndFlags & 0x3FFFFFFF;
  v26 = v24;
  if ( v25 < v24 )
  {
    v27 = 2 * v25;
    v28 = v24;
    if ( v24 < v27 )
      v28 = v27;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)v17, v28, 4);
  }
  v29 = *(signed int *)(v17 + 8);
  v30 = (_DWORD *)(*(_QWORD *)v17 + 4 * v29);
  v31 = v26 - (signed int)v29;
  if ( v31 > 0 )
  {
    while ( v31 )
    {
      *v30 = -1;
      ++v30;
      --v31;
    }
  }
  *(_DWORD *)(v17 + 8) = v26;
  v32 = (signed int *)array;
  v33 = *((_DWORD *)array + 3) & 0x3FFFFFFF;
  if ( v33 < v13 )
  {
    v34 = 2 * v33;
    v35 = v13;
    if ( v13 < v34 )
      v35 = v34;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, array, v35, 1);
  }
  v36 = v32[2];
  v37 = v13 - v36;
  v38 = (void *)(*(_QWORD *)v32 + v36);
  v39 = v13 - (signed int)v36;
  if ( v37 > 0 )
    memset(v38, 0, v39);
  v32[2] = v13;
  if ( v7[24] )
    hkGeometryUtils::weldVerticesVirtual(
      (hkGeometryUtils::IVertices *)v10,
      (hkArray<int,hkContainerHeapAllocator> *)&v10->m_pbd,
      *(float *)&v7[28]);
  v40 = 0i64;
  v41 = 0;
  v365 = 0;
  if ( *(float *)&v7[36] >= 0.0 )
  {
    v42 = (__m128)*(unsigned int *)&v7[36];
    v43 = 0;
    v44 = 1;
    tolerance.m_real = _mm_shuffle_ps(v42, v42, 0);
    if ( (signed int)vars0.m_enum > 0 )
    {
      v45 = 0i64;
      do
      {
        if ( (*(_DWORD *)(*(_QWORD *)&v10->m_convexRadius + 4 * (v45 >> 5)) >> (v43 & 0x1F)) & 1 )
        {
          (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64)
                                                            + 32i64))(
            *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
            (unsigned int)v43,
            &v367);
          v46 = *(_QWORD *)&v10->m_pbd;
          v47 = 1;
          LODWORD(v367) = *(_DWORD *)(v46 + 4i64 * (signed int)v367);
          HIDWORD(v367) = *(_DWORD *)(v46 + 4i64 * SHIDWORD(v367));
          LODWORD(v368) = *(_DWORD *)(v46 + 4i64 * (signed int)v368);
          if ( (_DWORD)v368 == HIDWORD(v367) )
            v47 = 3;
          (*(void (__fastcall **)(_QWORD, _QWORD, __m128 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64)
                                                           + 32i64))(
            *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
            (unsigned int)v43,
            &v377);
          v48 = *(_QWORD *)&v10->m_pbd;
          v377.m128_i32[0] = *(_DWORD *)(v48 + 4i64 * v377.m128_i32[0]);
          v377.m128_i32[1] = *(_DWORD *)(v48 + 4i64 * v377.m128_i32[1]);
          v49.vfptr = *(hkGeometryUtils::IVerticesVtbl **)&v10->m_globalOptimizations.m_bool;
          v377.m128_i32[2] = *(_DWORD *)(v48 + 4i64 * v377.m128_i32[2]);
          v49.vfptr->getVertex((hkGeometryUtils::IVertices *)v10, v377.m128_u32[0], &a);
          (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, hkVector4f *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                              + 16i64))(
            v10,
            v377.m128_u32[1],
            &b);
          (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, hkVector4f *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                              + 16i64))(
            v10,
            v377.m128_u32[2],
            &c);
          if ( v47 != 1 || hkcdTriangleUtil::isDegenerate(&a, &b, &c, &tolerance) )
          {
            v41 = v365 + 1;
            *(_DWORD *)(*(_QWORD *)&v10->m_convexRadius + 4 * (v45 >> 5)) &= ~v44;
            v365 = v41;
          }
          else
          {
            v41 = v365;
          }
        }
        v44 = __ROL4__(v44, 1);
        ++v43;
        ++v45;
      }
      while ( v43 < vars0.m_enum );
      v8 = retaddr;
      v40 = 0i64;
    }
    v7 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *)v412;
    v13 = vars0.m_enum;
  }
  if ( *(_BYTE *)&v7[20] & 1 && v41 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&tolerance, &buf, 512);
    v50 = hkOstream::operator<<((hkOstream *)&tolerance, "Found ");
    v51 = hkOstream::operator<<(v50, v41, (int)v50);
    hkOstream::operator<<(v51, " degenerated triangles in the input geometry, removing them.");
    hkError::messageReport(0, &buf, 0i64, 0);
    hkOstream::~hkOstream((hkOstream *)&tolerance);
  }
  v397.m_data.m_data = 0i64;
  v397.m_data.m_size = 0;
  v52 = (v13 + 31) >> 5;
  v397.m_data.m_capacityAndFlags = 2147483648;
  v53 = v52;
  if ( v52 )
  {
    v365 = 4 * v52;
    v54 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v365);
    v53 = v365 / 4;
  }
  else
  {
    v54 = 0i64;
  }
  v55 = 2147483648;
  v397.m_data.m_data = v54;
  if ( v53 )
    v55 = v53;
  v397.m_data.m_size = (v13 + 31) >> 5;
  v397.m_m = v13;
  v397.m_data.m_capacityAndFlags = v55;
  v56 = v55 & 0x3FFFFFFF;
  if ( v56 < v52 )
  {
    v57 = 2 * v56;
    v58 = (v13 + 31) >> 5;
    if ( v52 < v57 )
      v58 = v57;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v397, v58, 4);
  }
  v59 = v52 - 1;
  v397.m_data.m_size = (v13 + 31) >> 5;
  if ( v52 - 1 >= 0 )
  {
    v60 = v397.m_data.m_data;
    for ( i = (unsigned int)(v59 + 1); i; --i )
    {
      *v60 = 0.0;
      ++v60;
    }
  }
  v62 = 3 * v13;
  tolerance.m_real.m128_u64[0] = 0i64;
  v63 = 0;
  tolerance.m_real.m128_u64[1] = 0x8000000000000000i64;
  if ( 3 * v13 > 0 )
  {
    if ( v62 < 0 )
      v62 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &tolerance, v62, 12);
    v63 = tolerance.m_real.m128_i32[2];
  }
  v64 = 0;
  if ( v13 > 0 )
  {
    v65 = v368;
    v66 = v368;
    v67 = 0i64;
    v68 = v368;
    do
    {
      if ( (*(_DWORD *)(*(_QWORD *)&v10->m_convexRadius + 4 * (v67 >> 5)) >> (v64 & 0x1F)) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64)
                                                          + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
          (unsigned int)v64,
          &v381);
        v69 = *(_QWORD *)&v10->m_pbd;
        v70 = *(_DWORD *)(v69 + 4i64 * (signed int)v381);
        v71 = tolerance.m_real.m128_f32[2];
        LODWORD(v381) = v70;
        HIDWORD(v381) = *(_DWORD *)(v69 + 4i64 * SHIDWORD(v381));
        v72 = HIDWORD(v381);
        v73 = *(_DWORD *)(v69 + 4i64 * v382);
        v74 = HIDWORD(v381);
        if ( v70 < SHIDWORD(v381) )
          v74 = v70;
        v382 = *(_DWORD *)(v69 + 4i64 * v382);
        v366 = v74;
        v75 = HIDWORD(v381);
        if ( v70 > SHIDWORD(v381) )
          v75 = v70;
        v76 = v64 & 0x3FFFFFFF;
        v380 = v75;
        v77 = (_DWORD *)(tolerance.m_real.m128_u64[0] + 12i64 * tolerance.m_real.m128_i32[2]);
        v65 = (v64 & 0x3FFFFFFF | v65 & 0xC0000000) & 0x3FFFFFFF;
        if ( v77 )
        {
          *v77 = v366;
          v77[1] = v380;
          v77[2] = v65;
          v71 = tolerance.m_real.m128_f32[2];
          v73 = v382;
          v72 = HIDWORD(v381);
          v70 = v381;
        }
        v78 = LODWORD(v71) + 1;
        v79 = v73;
        if ( v72 > v73 )
          v79 = v72;
        v80 = v73;
        tolerance.m_real.m128_i32[2] = v78;
        if ( v72 < v73 )
          v80 = v72;
        v366 = v79;
        v81 = (int *)(tolerance.m_real.m128_u64[0] + 12i64 * v78);
        v68 = (v76 | v68 & 0xC0000000) & 0x3FFFFFFF | 0x40000000;
        if ( v81 )
        {
          v82 = v366;
          *v81 = v80;
          v81[1] = v82;
          v81[2] = v68;
          v78 = tolerance.m_real.m128_i32[2];
          v73 = v382;
          v70 = v381;
        }
        v83 = v78 + 1;
        v84 = v70;
        if ( v73 < v70 )
          v84 = v73;
        if ( v73 > v70 )
          v70 = v73;
        tolerance.m_real.m128_i32[2] = v83;
        v85 = (int *)(tolerance.m_real.m128_u64[0] + 12i64 * v83);
        v66 = (v76 | v66 & 0xC0000000) & 0x3FFFFFFF | 0x80000000;
        if ( v85 )
        {
          *v85 = v84;
          v85[1] = v70;
          v85[2] = v66;
          v83 = tolerance.m_real.m128_i32[2];
        }
        v63 = v83 + 1;
        tolerance.m_real.m128_i32[2] = v63;
      }
      ++v64;
      ++v67;
    }
    while ( v64 < vars0.m_enum );
    v8 = retaddr;
    v13 = vars0.m_enum;
    v40 = 0i64;
  }
  if ( v63 > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::HalfEdge,hkAlgorithm::less<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::HalfEdge>>(
      (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::HalfEdge *)tolerance.m_real.m128_u64[0],
      0,
      v63 - 1,
      0);
    v63 = tolerance.m_real.m128_i32[2];
  }
  v86 = v13 + 1;
  v87 = v8->m_triangleIndexToKey.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v87 < v13 + 1 )
  {
    v88 = 2 * v87;
    if ( v86 < v88 )
      v86 = v88;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v8,
      v86,
      12);
    v63 = tolerance.m_real.m128_i32[2];
  }
  v89 = 0;
  v90 = v63 - 1;
  v403 = v63 - 1;
  v365 = 0;
  if ( v63 - 1 > 0 )
  {
    v402 = 1i64;
    v91 = 0i64;
    v401 = 0i64;
    v381 = v63 - 1;
    while ( 1 )
    {
      v92 = *(_QWORD *)&v10->m_balanceThreshold;
      v93 = tolerance.m_real.m128_u64[0];
      v94 = *(__int64 **)v92;
      v95 = *(_DWORD *)(v91 + tolerance.m_real.m128_u64[0] + 8);
      v400 = tolerance.m_real.m128_u64[0];
      v96 = *v94;
      v385 = v95 & 0x3FFFFFFF;
      LODWORD(v94) = *(_DWORD *)(v96 + 4i64 * (v95 & 0x3FFFFFFF));
      v97 = *(_QWORD *)(v92 + 8);
      v399 = (signed int)v94;
      (*(void (__fastcall **)(__int64, _QWORD, __m128 *))(*(_QWORD *)v97 + 32i64))(v97, v95 & 0x3FFFFFFF, &v377);
      v98 = *(_QWORD *)&v10->m_pbd;
      v99 = v89 + 1;
      v377.m128_i32[0] = *(_DWORD *)(v98 + 4i64 * v377.m128_i32[0]);
      v377.m128_i32[1] = *(_DWORD *)(v98 + 4i64 * v377.m128_i32[1]);
      v100 = *(_DWORD *)(v98 + 4i64 * v377.m128_i32[2]);
      v101 = v402;
      v377.m128_i32[2] = v100;
      result.m_enum = v89 + 1;
      LODWORD(retaddr) = v89 + 1;
      v404 = v402;
      if ( v402 >= v90 )
        goto LABEL_124;
      v102 = v91 + 12;
      do
      {
        v103 = tolerance.m_real.m128_u64[0];
        v104 = *(_DWORD *)(v91 + v93);
        v105 = *(_DWORD *)(v102 + tolerance.m_real.m128_u64[0]);
        if ( v104 < v105 )
          break;
        if ( v104 > v105 )
          break;
        v106 = *(_DWORD *)(v91 + v93 + 4);
        v107 = *(_DWORD *)(v102 + tolerance.m_real.m128_u64[0] + 4);
        if ( v106 < v107 || v106 > v107 )
          break;
        v108 = *(_QWORD ***)&v10->m_balanceThreshold;
        v109 = *(_DWORD *)(v102 + tolerance.m_real.m128_u64[0] + 8) & 0x3FFFFFFF;
        if ( v399 != *(_DWORD *)(**v108 + 4i64 * (signed int)v109) )
          goto LABEL_122;
        (*(void (__fastcall **)(_QWORD *, _QWORD, int *))(*v108[1] + 32i64))(v108[1], v109, &v386);
        v110 = *(_QWORD *)&v10->m_pbd;
        v111 = v400;
        v112 = *(_DWORD *)(v91 + v400 + 8);
        v113 = *(_DWORD *)(v102 + v103 + 8);
        v386 = *(_DWORD *)(v110 + 4i64 * v386);
        v114 = v112 >> 30;
        v387 = *(_DWORD *)(v110 + 4i64 * v387);
        v115 = v113 >> 30;
        v388 = *(_DWORD *)(v110 + 4i64 * v388);
        v116 = v377.m128_u32[((signed int)v114 + 2) % 3];
        v395 = v377.m128_u32[v114];
        v383 = v116;
        v117 = *(&v386 + ((signed int)v115 + 2) % 3);
        v366 = *(&v386 + v115);
        v384 = v117;
        if ( v395 != *(&v386 + ((signed int)v115 + 1) % 3) )
          goto LABEL_122;
        v118 = v366;
        if ( v366 != v377.m128_i32[((signed int)v114 + 1) % 3] || v116 == v117 )
          goto LABEL_122;
        v119 = v412;
        v120 = v365;
        v121 = (signed int)retaddr;
        v122 = *(_BYTE *)(v412 + 2) == 0;
        v380 = v365;
        v366 = (signed int)retaddr;
        if ( !v122 )
        {
          (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, hkcdStaticMeshTreeBase::BuildCustomInfos *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool + 16i64))(
            v10,
            v395,
            &customPrimitive);
          (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, hkVector4f *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                              + 16i64))(
            v10,
            v118,
            &customPrimitive.m_aabb.m_max);
          (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, int *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                       + 16i64))(
            v10,
            v383,
            &customPrimitive.m_numVertices);
          (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, unsigned __int16 *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool + 16i64))(
            v10,
            v384,
            &customPrimitive.m_tags.m_data[2]);
          v123 = _mm_sub_ps(*(__m128 *)&customPrimitive.m_numVertices, customPrimitive.m_aabb.m_min.m_quad);
          v124 = _mm_sub_ps(customPrimitive.m_aabb.m_max.m_quad, customPrimitive.m_aabb.m_min.m_quad);
          v125 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v123, v123, 201), v124),
                   _mm_mul_ps(_mm_shuffle_ps(v124, v124, 201), v123));
          v126 = _mm_mul_ps(
                   _mm_shuffle_ps(v125, v125, 201),
                   _mm_sub_ps(*(__m128 *)&customPrimitive.m_tags.m_data[2], customPrimitive.m_aabb.m_min.m_quad));
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v126, v126, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v126, v126, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v126, v126, 170))) <= (float)(0.0 - 0.00000011920929) )
            goto LABEL_122;
          v121 = (signed int)retaddr;
          v111 = v400;
          v120 = v365;
          v119 = v412;
        }
        if ( *(_BYTE *)(v119 + 3)
          && ((v127 = *(_DWORD *)(v91 + v111 + 8) >> 30, v127 != 2) || *(_DWORD *)(v102 + v103 + 8) & 0xC0000000) )
        {
          if ( (*(_DWORD *)(v102 + v103 + 8) & 0xC0000000) != 0x80000000 || v127 )
            goto LABEL_122;
          v128 = v121;
          v366 = v120;
        }
        else
        {
          v128 = v380;
        }
        (*(void (__fastcall **)(_QWORD, _QWORD, hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64) + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
          v385,
          &v389);
        v129 = *(_QWORD *)&v10->m_pbd;
        LODWORD(v389.m_elem) = *(_DWORD *)(v129 + 4i64 * SLODWORD(v389.m_elem));
        HIDWORD(v389.m_elem) = *(_DWORD *)(v129 + 4i64 * SHIDWORD(v389.m_elem));
        v130.vfptr = *(hkGeometryUtils::IVerticesVtbl **)&v10->m_globalOptimizations.m_bool;
        v389.m_numElems = *(_DWORD *)(v129 + 4i64 * v389.m_numElems);
        v130.vfptr->getVertex((hkGeometryUtils::IVertices *)v10, (int)v389.m_elem, (hkVector4f *)&v408);
        (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, __m128 *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                        + 16i64))(
          v10,
          HIDWORD(v389.m_elem),
          &v409);
        (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, __m128 *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                        + 16i64))(
          v10,
          (unsigned int)v389.m_numElems,
          &v410);
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64)
                                                          + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
          v109,
          &v378);
        v131 = *(_QWORD *)&v10->m_pbd;
        LODWORD(v378) = *(_DWORD *)(v131 + 4i64 * (signed int)v378);
        HIDWORD(v378) = *(_DWORD *)(v131 + 4i64 * SHIDWORD(v378));
        v132.vfptr = *(hkGeometryUtils::IVerticesVtbl **)&v10->m_globalOptimizations.m_bool;
        LODWORD(v379) = *(_DWORD *)(v131 + 4i64 * (signed int)v379);
        v132.vfptr->getVertex((hkGeometryUtils::IVertices *)v10, v378, &customPrimitive.m_aabb.m_min);
        (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, hkVector4f *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                            + 16i64))(
          v10,
          HIDWORD(v378),
          &customPrimitive.m_aabb.m_max);
        (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, int *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                     + 16i64))(
          v10,
          (unsigned int)v379,
          &customPrimitive.m_numVertices);
        v133 = _mm_max_ps(_mm_max_ps(v408, v409), v410);
        v134 = _mm_min_ps(_mm_min_ps(v408, v409), v410);
        v135 = _mm_min_ps(
                 _mm_min_ps(customPrimitive.m_aabb.m_min.m_quad, customPrimitive.m_aabb.m_max.m_quad),
                 *(__m128 *)&customPrimitive.m_numVertices);
        v136 = _mm_max_ps(
                 _mm_max_ps(customPrimitive.m_aabb.m_min.m_quad, customPrimitive.m_aabb.m_max.m_quad),
                 *(__m128 *)&customPrimitive.m_numVertices);
        v137 = _mm_sub_ps(v133, v134);
        v138 = _mm_mul_ps(_mm_shuffle_ps(v137, v137, 201), v137);
        v139 = v8->m_triangleIndexToKey.m_capacityAndFlags;
        a.m_quad = v134;
        v140 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v138, v138, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v138, v138, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v138, v138, 170));
        v141 = _mm_sub_ps(v136, v135);
        v142 = _mm_mul_ps(_mm_shuffle_ps(v141, v141, 201), v141);
        v143 = _mm_sub_ps(_mm_max_ps(v133, v136), _mm_min_ps(v134, v135));
        v144 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v142, v142, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v142, v142, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v142, v142, 170));
        v145 = _mm_mul_ps(_mm_shuffle_ps(v143, v143, 201), v143);
        v146 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v145, v145, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v145, v145, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v145, v145, 170));
        if ( v8->m_triangleIndexToKey.m_size == (v139 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 12);
        v147 = v8->m_triangleIndexToKey.m_size;
        v148 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *)v8->m_triangleIndexToKey.m_data;
        v149 = v147;
        v8->m_triangleIndexToKey.m_size = v147 + 1;
        v150 = v366;
        v148[v149].m_edges[0] = *(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase *)(tolerance.m_real.m128_u64[0] + 12i64 * v128 + 8);
        v151 = *(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase *)(tolerance.m_real.m128_u64[0] + 12 * v150 + 8);
        v148[v149].m_edges[1] = v151;
        v148[v149].m_value = (float)(v146 - v144) + (float)(v146 - v140);
        v152 = (signed int)((*(unsigned int *)&v151 >> 30) + 2) % 3;
        (*(void (__fastcall **)(_QWORD, _QWORD, hkSimdFloat32 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold
                                                                              + 8i64)
                                                                + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
          *(_DWORD *)&v151 & 0x3FFFFFFF,
          &tolerance);
        v153 = *(_QWORD *)&v10->m_pbd;
        tolerance.m_real.m128_i32[0] = *(_DWORD *)(v153 + 4i64 * tolerance.m_real.m128_i32[0]);
        tolerance.m_real.m128_i32[1] = *(_DWORD *)(v153 + 4i64 * tolerance.m_real.m128_i32[1]);
        v154 = v152;
        v155 = v148[v149].m_edges[1];
        tolerance.m_real.m128_i32[2] = *(_DWORD *)(v153 + 4i64 * tolerance.m_real.m128_i32[2]);
        v383 = tolerance.m_real.m128_u32[v154];
        (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64) + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
          *(_DWORD *)&v155 & 0x3FFFFFFF,
          &v374);
        v156 = *(_QWORD *)&v10->m_pbd;
        v374 = *(_DWORD *)(v156 + 4i64 * v374);
        v375 = *(_DWORD *)(v156 + 4i64 * v375);
        v376 = *(_DWORD *)(v156 + 4i64 * v376);
        v384 = *(&v374 + (signed int)((*(unsigned int *)&v155 >> 30) + 1) % 3);
        v157 = v148[v149].m_edges[0];
        v158 = (signed int)((*(unsigned int *)&v157 >> 30) + 2) % 3;
        (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64) + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
          *(_DWORD *)&v157 & 0x3FFFFFFF,
          &v371);
        v159 = *(_QWORD *)&v10->m_pbd;
        v160 = v148[v149].m_edges[0];
        v371 = *(_DWORD *)(v159 + 4i64 * v371);
        v372 = *(_DWORD *)(v159 + 4i64 * v372);
        v373 = *(_DWORD *)(v159 + 4i64 * v373);
        v366 = *(&v371 + v158);
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64)
                                                          + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
          *(_DWORD *)&v160 & 0x3FFFFFFF,
          &v367);
        v161 = *(_QWORD *)&v10->m_pbd;
        LODWORD(v367) = *(_DWORD *)(v161 + 4i64 * (signed int)v367);
        HIDWORD(v367) = *(_DWORD *)(v161 + 4i64 * SHIDWORD(v367));
        LODWORD(v368) = *(_DWORD *)(v161 + 4i64 * (signed int)v368);
        if ( v383 != v384
          && (*((_DWORD *)&v367 + (signed int)((*(unsigned int *)&v160 >> 30) + 1) % 3) != 222
           || v366 != 173
           || v384 != 222
           || v383 != 173) )
        {
          break;
        }
        --v8->m_triangleIndexToKey.m_size;
        v91 = v401;
LABEL_122:
        LODWORD(retaddr) = (_DWORD)retaddr + 1;
        v93 = v400;
        v102 += 12i64;
        ++v404;
      }
      while ( v404 < v403 );
      v91 = v401;
      v90 = v403;
      v101 = v402;
      v99 = result.m_enum;
LABEL_124:
      v91 += 12i64;
      v122 = v381-- == 1;
      v89 = v99;
      v401 = v91;
      v402 = v101 + 1;
      v365 = v99;
      if ( v122 )
      {
        v40 = 0i64;
        break;
      }
    }
  }
  v162 = v8->m_triangleIndexToKey.m_size;
  if ( v162 )
  {
    v163 = 0;
    LODWORD(retaddr) = 0;
    if ( v162 > 1 )
      hkAlgorithm::quickSortRecursive<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkAlgorithm::less<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad>>(
        (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *)v8->m_triangleIndexToKey.m_data,
        0,
        v162 - 1,
        0);
    if ( v8->m_triangleIndexToKey.m_size > 0 )
    {
      v164 = 0i64;
      v165 = 0;
      do
      {
        v166 = v8->m_triangleIndexToKey.m_data;
        v167 = *(unsigned int *)((char *)v8->m_triangleIndexToKey.m_data + v40);
        result.m_enum = *(unsigned int *)((char *)v8->m_triangleIndexToKey.m_data + v40 + 4);
        v385 = *(unsigned int *)((char *)v166 + v40 + 8);
        v367 = __PAIR__(result.m_enum, v167);
        v168 = __PAIR__((unsigned int)result.m_enum, v167) >> 32;
        v169 = result.m_enum & 0x3FFFFFFF;
        if ( !(((unsigned __int8)(LODWORD(v397.m_data.m_data[(signed __int64)(result.m_enum & 0x3FFFFFFF) >> 5]) >> (result.m_enum & 0x1F)) | (unsigned __int8)(LODWORD(v397.m_data.m_data[(signed __int64)(v167 & 0x3FFFFFFF) >> 5]) >> (v167 & 0x1F))) & 1) )
        {
          v170 = result.m_enum;
          LODWORD(retaddr) = (_DWORD)retaddr + 1;
          v166[v164] = v167;
          v166[v164 + 1] = v170;
          v166[v164 + 2] = v385;
          v164 += 3i64;
          LODWORD(v397.m_data.m_data[(signed __int64)(v167 & 0x3FFFFFFF) >> 5]) |= 1 << (v167 & 0x1F);
          LODWORD(v397.m_data.m_data[(signed __int64)v169 >> 5]) |= 1 << (v169 & 0x1F);
          v171 = array;
          *(_BYTE *)((v167 & 0x3FFFFFFF) + *(_QWORD *)array) = `hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep12<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>::`65::rotationsMap[v167 >> 30];
          *(_BYTE *)((v168 & 0x3FFFFFFF) + *v171) = `hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep12<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>::`65::rotationsMap[(signed int)(((unsigned int)v168 >> 30) + 2) % 3];
        }
        ++v165;
        v40 += 12i64;
      }
      while ( v165 < v8->m_triangleIndexToKey.m_size );
      v10 = *(hkcdStaticMeshTreeBase::BuildConfig **)&v413[0].m_enum;
      v163 = (signed int)retaddr;
      LODWORD(v40) = 0;
    }
    v172 = v8->m_triangleIndexToKey.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v172 < v163 )
    {
      v173 = 2 * v172;
      v174 = v163;
      if ( v163 < v173 )
        v174 = v173;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v8,
        v174,
        12);
    }
    v8->m_triangleIndexToKey.m_size = v163;
  }
  tolerance.m_real.m128_i32[2] = v40;
  if ( tolerance.m_real.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)tolerance.m_real.m128_u64[0],
      12 * (tolerance.m_real.m128_i32[3] & 0x3FFFFFFF));
  tolerance.m_real.m128_u64[0] = 0i64;
  tolerance.m_real.m128_u64[1] = -4294967296i64;
  v389.m_elem = 0i64;
  v389.m_numElems = 0;
  v389.m_hashMod = -1;
  v390 = 0i64;
  v391 = 0;
  v392 = 2147483648;
  v394 = 256;
  v175 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v176 = v175;
  v177 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> **)v175->m_cur;
  v178 = (unsigned __int64)(v177 + 256);
  if ( v176->m_slabSize < 2048 || (void *)v178 > v176->m_end )
    v177 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> **)hkLifoAllocator::allocateFromNewSlab(v176, 2048);
  else
    v176->m_cur = (void *)v178;
  v390 = v177;
  v392 = -2147483392;
  p = v177;
  v179 = 1 - v391;
  if ( v179 > 0 )
  {
    memset(&v177[v391], 0, 8 * v179);
    v177 = v390;
  }
  v391 = 1;
  *v177 = v417;
  v180 = _mm_shuffle_ps((__m128)*(unsigned int *)(v412 + 32), (__m128)*(unsigned int *)(v412 + 32), 0);
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
    v417,
    (hkResult *)&retaddr,
    2 * (vars0.m_enum + v8->m_triangleIndexToKey.m_size));
  LODWORD(retaddr) = v40;
  if ( v8->m_triangleIndexToKey.m_size > 0 )
  {
    v181 = 0i64;
    v182 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v183 = (__m128)xmmword_141A712A0;
      v184 = _mm_xor_ps((__m128)xmmword_141A712A0, v182);
      v185 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
               (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&tolerance,
               0i64,
               0i64);
      do
      {
        v186 = v8->m_triangleIndexToKey.m_data;
        if ( (_DWORD)v40 )
        {
          switch ( (_DWORD)v40 )
          {
            case 1:
              v192 = v186[v181];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64)
                                                            + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
                v192 & 0x3FFFFFFF,
                &v374);
              v193 = *(_QWORD *)&v10->m_pbd;
              v374 = *(_DWORD *)(v193 + 4i64 * v374);
              v375 = *(_DWORD *)(v193 + 4i64 * v375);
              v376 = *(_DWORD *)(v193 + 4i64 * v376);
              v187 = (unsigned int)*(&v374 + (signed int)((v192 >> 30) + 2) % 3);
              break;
            case 2:
              v190 = v186[v181 + 1];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64)
                                                            + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
                v190 & 0x3FFFFFFF,
                &v371);
              v191 = *(_QWORD *)&v10->m_pbd;
              v371 = *(_DWORD *)(v191 + 4i64 * v371);
              v372 = *(_DWORD *)(v191 + 4i64 * v372);
              v373 = *(_DWORD *)(v191 + 4i64 * v373);
              v187 = (unsigned int)*(&v371 + (signed int)((v190 >> 30) + 1) % 3);
              break;
            case 3:
              v188 = v186[v181 + 1];
              (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold
                                                                              + 8i64)
                                                                + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
                v188 & 0x3FFFFFFF,
                &v367);
              v189 = *(_QWORD *)&v10->m_pbd;
              LODWORD(v367) = *(_DWORD *)(v189 + 4i64 * (signed int)v367);
              HIDWORD(v367) = *(_DWORD *)(v189 + 4i64 * SHIDWORD(v367));
              LODWORD(v368) = *(_DWORD *)(v189 + 4i64 * (signed int)v368);
              v187 = *((unsigned int *)&v367 + (signed int)((v188 >> 30) + 2) % 3);
              break;
            default:
              v187 = 0xFFFFFFFFi64;
              break;
          }
        }
        else
        {
          v194 = v186[v181];
          (*(void (__fastcall **)(_QWORD, _QWORD, hkSimdFloat32 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold
                                                                                + 8i64)
                                                                  + 32i64))(
            *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
            v194 & 0x3FFFFFFF,
            &tolerance);
          v195 = *(_QWORD *)&v10->m_pbd;
          tolerance.m_real.m128_i32[0] = *(_DWORD *)(v195 + 4i64 * tolerance.m_real.m128_i32[0]);
          tolerance.m_real.m128_i32[1] = *(_DWORD *)(v195 + 4i64 * tolerance.m_real.m128_i32[1]);
          tolerance.m_real.m128_i32[2] = *(_DWORD *)(v195 + 4i64 * tolerance.m_real.m128_i32[2]);
          v187 = tolerance.m_real.m128_u32[(signed int)((v194 >> 30) + 1) % 3];
        }
        (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, signed __int64, __m128 *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                                + 16i64))(
          v10,
          v187,
          &v377);
        LODWORD(v40) = v40 + 1;
        v183 = _mm_min_ps(v183, v377);
        v184 = _mm_max_ps(v184, v377);
      }
      while ( (signed int)v40 < 4 );
      v196 = _mm_sub_ps(v183, v180);
      v197 = v390[v185];
      v198 = _mm_add_ps(v184, v180);
      if ( !v197->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
          v390[v185],
          v413,
          1);
      v199 = v197->m_firstFree;
      v200 = v197->m_nodes.m_data;
      v201 = v197->m_firstFree << 6;
      v197->m_firstFree = v197->m_nodes.m_data[(signed __int64)(signed int)v199].m_aabb.m_min.m_quad.m128_u64[0];
      *(unsigned __int64 *)((char *)v200->m_children + v201) = 0i64;
      *(unsigned __int64 *)((char *)&v200->m_children[1] + v201) = (signed int)retaddr;
      *(__m128 *)((char *)&v200->m_aabb.m_min.m_quad + v201) = v196;
      *(__m128 *)((char *)&v200->m_aabb.m_max.m_quad + v201) = v198;
      v202 = v197->m_nodes.m_data;
      v203 = *(_QWORD *)&v197[1].m_nodes.m_size;
      v204 = *(__m128 *)((char *)&v197->m_nodes.m_data->m_aabb.m_min.m_quad + v201);
      v205 = *(__m128 *)((char *)&v197->m_nodes.m_data->m_aabb.m_max.m_quad + v201);
      if ( v203 )
      {
        if ( !v197->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            v197,
            &result,
            1);
        v206 = v197->m_firstFree;
        v207 = (signed int)v206;
        v208 = &v197->m_nodes.m_data[v203].m_aabb.m_min.m_quad;
        v209 = &v197->m_nodes.m_data[v206].m_aabb.m_min.m_quad;
        v197->m_firstFree = v197->m_nodes.m_data[v207].m_aabb.m_min.m_quad.m128_u64[0];
        if ( v208[2].m128_i32[2] )
        {
          v210 = _mm_add_ps(v205, v204);
          v211 = _mm_sub_ps(v205, v204);
          do
          {
            v212 = (__int64)&v197->m_nodes.m_data[v208[2].m128_u64[1]];
            v213 = (__int64)&v197->m_nodes.m_data[v208[3].m128_u64[0]];
            v214 = _mm_max_ps(v208[1], v205);
            *v208 = _mm_min_ps(*v208, v204);
            v208[1] = v214;
            v378 = v212;
            v379 = v213;
            v215 = *(__m128 *)(v212 + 16);
            v216 = *(__m128 *)(v213 + 16);
            v217 = v215;
            v218 = v216;
            v219 = _mm_add_ps(_mm_sub_ps(v215, *(__m128 *)v212), v211);
            v220 = _mm_add_ps(_mm_sub_ps(v216, *(__m128 *)v213), v211);
            v221 = _mm_sub_ps(_mm_add_ps(v217, *(__m128 *)v212), v210);
            v222 = _mm_mul_ps(v221, v221);
            v223 = _mm_sub_ps(_mm_add_ps(v218, *(__m128 *)v213), v210);
            v224 = _mm_mul_ps(v223, v223);
            v208 = (__m128 *)*(&v378
                             + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v219, v219, 85))
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v219, v219, 0)))
                                              + COERCE_FLOAT(_mm_shuffle_ps(v219, v219, 170)))
                                      * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v222, v222, 85))
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v222, v222, 0)))
                                              + COERCE_FLOAT(_mm_shuffle_ps(v222, v222, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v220, v220, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v220, v220, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v220, v220, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v224, v224, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v224, v224, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v224, v224, 170))))));
          }
          while ( v208[2].m128_i32[2] );
        }
        v225 = v208[2].m128_u64[0];
        v226 = ((char *)v209 - (char *)v197->m_nodes.m_data) >> 6;
        if ( v225 )
          v197->m_nodes.m_data->m_children[(v197->m_nodes.m_data[v225].m_children[1] == ((char *)v208
                                                                                       - (char *)v197->m_nodes.m_data) >> 6)
                                         + 8 * v225] = v226;
        else
          *(_QWORD *)&v197[1].m_nodes.m_size = v226;
        v209[2].m128_u64[0] = v208[2].m128_u64[0];
        v227 = (char *)v208 - (char *)v197->m_nodes.m_data;
        v209[3].m128_u64[0] = v199;
        v209[2].m128_u64[1] = v227 >> 6;
        v208[2].m128_u64[0] = v226;
        *(unsigned __int64 *)((char *)&v197->m_nodes.m_data->m_parent + v201) = v226;
        v228 = _mm_max_ps(v208[1], v205);
        *v209 = _mm_min_ps(*v208, v204);
        v209[1] = v228;
      }
      else
      {
        *(_QWORD *)&v197[1].m_nodes.m_size = v199;
        *(unsigned __int64 *)((char *)&v202->m_parent + v201) = 0i64;
      }
      ++LODWORD(v197[1].m_nodes.m_data);
      v181 += 3i64;
      LODWORD(v40) = 0;
      LODWORD(retaddr) = (_DWORD)retaddr + 1;
    }
    while ( (signed int)retaddr < v8->m_triangleIndexToKey.m_size );
  }
  v229 = v8->m_triangleIndexToKey.m_size;
  v230 = vars0.m_enum;
  LODWORD(retaddr) = v8->m_triangleIndexToKey.m_size;
  v231 = 0;
  if ( (signed int)vars0.m_enum > 0 )
  {
    v232 = 0i64;
    do
    {
      if ( (*(_DWORD *)(*(_QWORD *)&v10->m_convexRadius + 4 * (v232 >> 5)) >> (v231 & 0x1F)) & 1
        && !((LODWORD(v397.m_data.m_data[v232 >> 5]) >> (v231 & 0x1F)) & 1) )
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64)
                                                          + 32i64))(
          *(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 8i64),
          (unsigned int)v231,
          &v378);
        v233 = *(_QWORD *)&v10->m_pbd;
        LODWORD(v378) = *(_DWORD *)(v233 + 4i64 * (signed int)v378);
        HIDWORD(v378) = *(_DWORD *)(v233 + 4i64 * SHIDWORD(v378));
        v234.vfptr = *(hkGeometryUtils::IVerticesVtbl **)&v10->m_globalOptimizations.m_bool;
        LODWORD(v379) = *(_DWORD *)(v233 + 4i64 * (signed int)v379);
        v234.vfptr->getVertex((hkGeometryUtils::IVertices *)v10, v378, &customPrimitive.m_aabb.m_min);
        (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, hkVector4f *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                            + 16i64))(
          v10,
          HIDWORD(v378),
          &customPrimitive.m_aabb.m_max);
        (*(void (__fastcall **)(hkcdStaticMeshTreeBase::BuildConfig *, _QWORD, int *))(*(_QWORD *)&v10->m_globalOptimizations.m_bool
                                                                                     + 16i64))(
          v10,
          (unsigned int)v379,
          &customPrimitive.m_numVertices);
        v235 = _mm_add_ps(
                 _mm_max_ps(
                   _mm_max_ps(customPrimitive.m_aabb.m_min.m_quad, customPrimitive.m_aabb.m_max.m_quad),
                   *(__m128 *)&customPrimitive.m_numVertices),
                 v180);
        v236 = _mm_sub_ps(
                 _mm_min_ps(
                   _mm_min_ps(customPrimitive.m_aabb.m_min.m_quad, customPrimitive.m_aabb.m_max.m_quad),
                   *(__m128 *)&customPrimitive.m_numVertices),
                 v180);
        v237 = (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&tolerance,
                             0i64,
                             0i64);
        v238 = v390[v237];
        if ( !v238->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            v390[v237],
            v413,
            1);
        v239 = v238->m_firstFree;
        v240 = v238->m_nodes.m_data;
        v241 = v238->m_firstFree << 6;
        v238->m_firstFree = v238->m_nodes.m_data[(signed __int64)(signed int)v239].m_aabb.m_min.m_quad.m128_u64[0];
        *(unsigned __int64 *)((char *)v240->m_children + v241) = 0i64;
        *(unsigned __int64 *)((char *)&v240->m_children[1] + v241) = v232 + (signed int)retaddr;
        *(__m128 *)((char *)&v240->m_aabb.m_min.m_quad + v241) = v236;
        *(__m128 *)((char *)&v240->m_aabb.m_max.m_quad + v241) = v235;
        v242 = v238->m_nodes.m_data;
        v243 = *(_QWORD *)&v238[1].m_nodes.m_size;
        v244 = *(__m128 *)((char *)&v238->m_nodes.m_data->m_aabb.m_min.m_quad + v241);
        v245 = *(__m128 *)((char *)&v238->m_nodes.m_data->m_aabb.m_max.m_quad + v241);
        if ( v243 )
        {
          if ( !v238->m_firstFree )
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
              v238,
              &result,
              1);
          v246 = v238->m_firstFree;
          v247 = (signed int)v246;
          v248 = &v238->m_nodes.m_data[v243].m_aabb.m_min.m_quad;
          v249 = &v238->m_nodes.m_data[v246].m_aabb.m_min.m_quad;
          v238->m_firstFree = v238->m_nodes.m_data[v247].m_aabb.m_min.m_quad.m128_u64[0];
          if ( v248[2].m128_i32[2] )
          {
            v250 = _mm_add_ps(v245, v244);
            v251 = _mm_sub_ps(v245, v244);
            do
            {
              v252 = (__int64)&v238->m_nodes.m_data[v248[2].m128_u64[1]];
              v253 = (__int64)&v238->m_nodes.m_data[v248[3].m128_u64[0]];
              v254 = _mm_max_ps(v248[1], v245);
              *v248 = _mm_min_ps(*v248, v244);
              v248[1] = v254;
              v367 = v252;
              v368 = v253;
              v255 = *(__m128 *)(v252 + 16);
              v256 = *(__m128 *)(v253 + 16);
              v257 = v255;
              v258 = v256;
              v259 = _mm_add_ps(_mm_sub_ps(v255, *(__m128 *)v252), v251);
              v260 = _mm_add_ps(_mm_sub_ps(v256, *(__m128 *)v253), v251);
              v261 = _mm_sub_ps(_mm_add_ps(v257, *(__m128 *)v252), v250);
              v262 = _mm_mul_ps(v261, v261);
              v263 = _mm_sub_ps(_mm_add_ps(v258, *(__m128 *)v253), v250);
              v264 = _mm_mul_ps(v263, v263);
              v248 = (__m128 *)*(&v367
                               + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v259, v259, 85))
                                                        + COERCE_FLOAT(_mm_shuffle_ps(v259, v259, 0)))
                                                + COERCE_FLOAT(_mm_shuffle_ps(v259, v259, 170)))
                                        * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v262, v262, 85))
                                                        + COERCE_FLOAT(_mm_shuffle_ps(v262, v262, 0)))
                                                + COERCE_FLOAT(_mm_shuffle_ps(v262, v262, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v260, v260, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v260, v260, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v260, v260, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v264, v264, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v264, v264, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v264, v264, 170))))));
            }
            while ( v248[2].m128_i32[2] );
          }
          v265 = v248[2].m128_u64[0];
          v266 = ((char *)v249 - (char *)v238->m_nodes.m_data) >> 6;
          if ( v265 )
            v238->m_nodes.m_data->m_children[(v238->m_nodes.m_data[v265].m_children[1] == ((char *)v248
                                                                                         - (char *)v238->m_nodes.m_data) >> 6)
                                           + 8 * v265] = v266;
          else
            *(_QWORD *)&v238[1].m_nodes.m_size = v266;
          v249[2].m128_u64[0] = v248[2].m128_u64[0];
          v267 = (char *)v248 - (char *)v238->m_nodes.m_data;
          v249[3].m128_u64[0] = v239;
          v249[2].m128_u64[1] = v267 >> 6;
          v248[2].m128_u64[0] = v266;
          *(unsigned __int64 *)((char *)&v238->m_nodes.m_data->m_parent + v241) = v266;
          v268 = _mm_max_ps(v248[1], v245);
          *v249 = _mm_min_ps(*v248, v244);
          v249[1] = v268;
        }
        else
        {
          *(_QWORD *)&v238[1].m_nodes.m_size = v239;
          *(unsigned __int64 *)((char *)&v242->m_parent + v241) = 0i64;
        }
        ++LODWORD(v238[1].m_nodes.m_data);
        v230 = vars0.m_enum;
      }
      ++v231;
      ++v232;
    }
    while ( v231 < v230 );
    v229 = (signed int)retaddr;
  }
  v269 = v230 + v229;
  v270 = 0;
  LODWORD(retaddr) = v269;
  v271 = 0i64;
  array = (void *)(*(signed int (**)(void))(**(_QWORD **)(*(_QWORD *)&v10->m_balanceThreshold + 8i64) + 64i64))();
  if ( (signed __int64)array > 0 )
  {
    v272 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v273 = *(hkpBvCompressedMeshShape_Internals::GeometryProvider **)&v10->m_balanceThreshold;
      customPrimitive.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
      *(_QWORD *)&customPrimitive.m_numVertices = 0i64;
      customPrimitive.m_aabb.m_max.m_quad = _mm_xor_ps((__m128)xmmword_141A712A0, v272);
      customPrimitive.m_layerData = 0;
      customPrimitive.m_tags.m_size = 0;
      customPrimitive.m_maxError = 3.40282e38;
      customPrimitive.m_compression = 1;
      hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(v273, v270, &customPrimitive);
      v274.m_quad = (__m128)customPrimitive.m_aabb.m_min;
      v275.m_quad = (__m128)customPrimitive.m_aabb.m_max;
      v276 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
               (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&tolerance,
               (unsigned __int8)customPrimitive.m_layerData,
               0i64);
      if ( _mm_movemask_ps(_mm_cmpleps(v275.m_quad, v274.m_quad)) & 7 )
      {
        if ( customPrimitive.m_numVertices > 0 )
        {
          v277 = *(__m128 **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v10->m_balanceThreshold + 16i64) + 8 * v271) + 32i64);
          v278 = (unsigned int)customPrimitive.m_numVertices;
          do
          {
            v274.m_quad = _mm_min_ps(v274.m_quad, *v277);
            v275.m_quad = _mm_max_ps(v275.m_quad, *v277);
            ++v277;
            --v278;
          }
          while ( v278 );
        }
        v269 = (signed int)retaddr;
        v274.m_quad = _mm_sub_ps(v274.m_quad, v180);
        v275.m_quad = _mm_add_ps(v275.m_quad, v180);
      }
      v279 = v390[v276];
      if ( !v279->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
          v279,
          v413,
          1);
      v280 = v279->m_firstFree;
      v281 = v279->m_nodes.m_data;
      v282 = v279->m_firstFree << 6;
      v279->m_firstFree = v279->m_nodes.m_data[(signed __int64)(signed int)v280].m_aabb.m_min.m_quad.m128_u64[0];
      *(unsigned __int64 *)((char *)v281->m_children + v282) = 0i64;
      *(unsigned __int64 *)((char *)&v281->m_children[1] + v282) = v270 + v269;
      *(hkVector4f *)((char *)&v281->m_aabb.m_min + v282) = (hkVector4f)v274.m_quad;
      *(hkVector4f *)((char *)&v281->m_aabb.m_max + v282) = (hkVector4f)v275.m_quad;
      v283 = v279->m_nodes.m_data;
      v284 = *(_QWORD *)&v279[1].m_nodes.m_size;
      v285 = *(__m128 *)((char *)&v279->m_nodes.m_data->m_aabb.m_min.m_quad + v282);
      v286 = *(__m128 *)((char *)&v279->m_nodes.m_data->m_aabb.m_max.m_quad + v282);
      if ( v284 )
      {
        if ( !v279->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            v279,
            &vars0,
            1);
        v287 = v279->m_firstFree;
        v288 = (signed int)v287;
        v289 = &v279->m_nodes.m_data[v284].m_aabb.m_min.m_quad;
        v290 = &v279->m_nodes.m_data[v287].m_aabb.m_min.m_quad;
        v279->m_firstFree = v279->m_nodes.m_data[v288].m_aabb.m_min.m_quad.m128_u64[0];
        if ( v289[2].m128_i32[2] )
        {
          v291 = _mm_add_ps(v286, v285);
          v292 = _mm_sub_ps(v286, v285);
          do
          {
            v293 = (__int64)&v279->m_nodes.m_data[v289[2].m128_u64[1]];
            v294 = (__int64)&v279->m_nodes.m_data[v289[3].m128_u64[0]];
            v295 = _mm_max_ps(v289[1], v286);
            *v289 = _mm_min_ps(*v289, v285);
            v289[1] = v295;
            v367 = v293;
            v368 = v294;
            v296 = *(__m128 *)(v293 + 16);
            v297 = *(__m128 *)(v294 + 16);
            v298 = v296;
            v299 = v297;
            v300 = _mm_add_ps(_mm_sub_ps(v296, *(__m128 *)v293), v292);
            v301 = _mm_add_ps(_mm_sub_ps(v297, *(__m128 *)v294), v292);
            v302 = _mm_sub_ps(_mm_add_ps(v298, *(__m128 *)v293), v291);
            v303 = _mm_mul_ps(v302, v302);
            v304 = _mm_sub_ps(_mm_add_ps(v299, *(__m128 *)v294), v291);
            v305 = _mm_mul_ps(v304, v304);
            v289 = (__m128 *)*(&v367
                             + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v300, v300, 85))
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v300, v300, 0)))
                                              + COERCE_FLOAT(_mm_shuffle_ps(v300, v300, 170)))
                                      * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v303, v303, 85))
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v303, v303, 0)))
                                              + COERCE_FLOAT(_mm_shuffle_ps(v303, v303, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v301, v301, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v301, v301, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v301, v301, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v305, v305, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v305, v305, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v305, v305, 170))))));
          }
          while ( v289[2].m128_i32[2] );
        }
        v306 = v289[2].m128_u64[0];
        v307 = ((char *)v290 - (char *)v279->m_nodes.m_data) >> 6;
        if ( v306 )
          v279->m_nodes.m_data->m_children[(v279->m_nodes.m_data[v306].m_children[1] == ((char *)v289
                                                                                       - (char *)v279->m_nodes.m_data) >> 6)
                                         + 8 * v306] = v307;
        else
          *(_QWORD *)&v279[1].m_nodes.m_size = v307;
        v290[2].m128_u64[0] = v289[2].m128_u64[0];
        v308 = (char *)v289 - (char *)v279->m_nodes.m_data;
        v290[3].m128_u64[0] = v280;
        v290[2].m128_u64[1] = v308 >> 6;
        v289[2].m128_u64[0] = v307;
        *(unsigned __int64 *)((char *)&v279->m_nodes.m_data->m_parent + v282) = v307;
        v309 = _mm_max_ps(v289[1], v286);
        *v290 = _mm_min_ps(*v289, v285);
        v290[1] = v309;
      }
      else
      {
        *(_QWORD *)&v279[1].m_nodes.m_size = v280;
        *(unsigned __int64 *)((char *)&v283->m_parent + v282) = 0i64;
      }
      ++LODWORD(v279[1].m_nodes.m_data);
      v269 = (signed int)retaddr;
      ++v271;
      ++v270;
    }
    while ( v271 < (signed __int64)array );
  }
  v310 = v412;
  v311 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)*v390;
  v312 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)*v390;
  if ( *(_BYTE *)v412 )
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildGlobalSAH(v312, 32, 128, 1);
  else
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(v312, v311->m_root, (hkBool)1, 32, 16);
  if ( *(_DWORD *)(v310 + 8) > 0 )
  {
    v313 = v311->m_root;
    v314 = 0;
    if ( v313 )
    {
      v315 = v311->m_nodes.m_data;
      v316 = 0;
      v317 = v313 << 6;
      v318 = v311->m_nodes.m_data[v313].m_parent;
      if ( v318 )
      {
        v319 = v311->m_nodes.m_data[v313].m_parent;
        do
        {
          ++v316;
          v319 = v315[v319].m_parent;
        }
        while ( v319 );
      }
      if ( *(_DWORD *)((char *)v315->m_children + v317) )
      {
        v320 = *(unsigned __int64 *)((char *)v315->m_children + v317);
        if ( v320 )
        {
          do
          {
            v321 = v320 << 6;
            if ( LODWORD(v315[v320].m_children[0]) )
            {
              v320 = *(unsigned __int64 *)((char *)v315->m_children + v321);
            }
            else
            {
              v322 = *(unsigned __int64 *)((char *)&v315->m_parent + v321);
              for ( j = 0; v322; v322 = v315[v322].m_parent )
                ++j;
              v324 = j - v316;
              if ( v314 > v324 )
                v324 = v314;
              v314 = v324;
              v325 = *(unsigned __int64 *)((char *)&v315->m_parent + v321);
              for ( k = v320; v325 != v313; v325 = v315[v325].m_parent )
              {
                if ( v315[v325].m_children[1] != k )
                  break;
                k = v325;
              }
              if ( v325 )
                v320 = v315[v325].m_children[1];
              else
                v320 = k;
              if ( v325 == v313 && v320 == k )
                v320 = 0i64;
            }
          }
          while ( v320 );
          v310 = v412;
        }
      }
      else
      {
        for ( ; v318; v318 = v315[v318].m_parent )
          ++v314;
        v314 -= v316;
        if ( v314 < 0 )
          v314 = 0;
      }
    }
    while ( 1 )
    {
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::balance(v311, *(_DWORD *)(v310 + 8), 0i64);
      v327 = v311->m_root;
      v328 = 0;
      if ( v327 )
      {
        v329 = v311->m_nodes.m_data;
        v330 = 0;
        v331 = v327 << 6;
        v332 = v311->m_nodes.m_data[v327].m_parent;
        if ( v332 )
        {
          v333 = v311->m_nodes.m_data[v327].m_parent;
          do
          {
            ++v330;
            v333 = v329[v333].m_parent;
          }
          while ( v333 );
        }
        if ( *(_DWORD *)((char *)v329->m_children + v331) )
        {
          v334 = *(unsigned __int64 *)((char *)v329->m_children + v331);
          if ( v334 )
          {
            do
            {
              v335 = v334 << 6;
              if ( LODWORD(v329[v334].m_children[0]) )
              {
                v334 = *(unsigned __int64 *)((char *)v329->m_children + v335);
              }
              else
              {
                v336 = *(unsigned __int64 *)((char *)&v329->m_parent + v335);
                for ( l = 0; v336; v336 = v329[v336].m_parent )
                  ++l;
                v338 = l - v330;
                if ( v328 > v338 )
                  v338 = v328;
                v328 = v338;
                v339 = *(unsigned __int64 *)((char *)&v329->m_parent + v335);
                for ( m = v334; v339 != v327; v339 = v329[v339].m_parent )
                {
                  if ( v329[v339].m_children[1] != m )
                    break;
                  m = v339;
                }
                if ( v339 )
                  v334 = v329[v339].m_children[1];
                else
                  v334 = m;
                if ( v339 == v327 && v334 == m )
                  v334 = 0i64;
              }
            }
            while ( v334 );
            v310 = v412;
          }
        }
        else
        {
          for ( ; v332; v332 = v329[v332].m_parent )
            ++v328;
          v328 -= v330;
          if ( v328 < 0 )
            v328 = 0;
        }
      }
      if ( v328 >= v314 )
        break;
      v314 = v328;
    }
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::compactIndices(v311);
  }
  v341 = v417;
  LODWORD(v368) = 0;
  v342 = *(_QWORD *)&v417[1].m_nodes.m_size;
  v343 = 0;
  if ( v342 )
  {
    v344 = v417->m_nodes.m_data;
    if ( LODWORD(v417->m_nodes.m_data[v342].m_children[0]) )
    {
      v345 = v344[v342].m_children[0];
      while ( v345 )
      {
        v346 = v345 << 6;
        v347 = v344[v345].m_children[0];
        v343 += v347 == 0;
        if ( v347 )
        {
          v345 = *(unsigned __int64 *)((char *)v344->m_children + v346);
        }
        else
        {
          v348 = *(unsigned __int64 *)((char *)&v344->m_parent + v346);
          for ( n = v345; v348 != v342; v348 = v344[v348].m_parent )
          {
            if ( v344[v348].m_children[1] != n )
              break;
            n = v348;
          }
          if ( v348 )
            v345 = v344[v348].m_children[1];
          else
            v345 = n;
          if ( v348 == v342 && v345 == n )
            v345 = 0i64;
        }
      }
    }
    else
    {
      v343 = 1;
    }
  }
  HIDWORD(v368) = v343;
  LODWORD(v369) = -1;
  if ( *(_DWORD *)&v416[8] == (*(_DWORD *)&v416[12] & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v416, 24);
    v341 = v417;
  }
  v350 = (_QWORD *)(*(_QWORD *)v416 + 24i64 * *(signed int *)&v416[8]);
  if ( v350 )
  {
    v351 = v368;
    *v350 = v342;
    v350[1] = v351;
    v350[2] = v369;
  }
  ++*(_DWORD *)&v416[8];
  if ( LODWORD(v341[1].m_nodes.m_data) )
  {
    v352 = *(_QWORD *)&v341[1].m_nodes.m_size;
    if ( v352 )
    {
      v353 = (_OWORD *)v341->m_nodes.m_data[v352].m_aabb.m_min.m_quad.m128_f32;
      v354 = *v353;
      v355 = *((__m128 *)v353 + 1);
    }
    else
    {
      v354 = xmmword_141A712A0;
      v355 = _mm_xor_ps(
               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
               (__m128)xmmword_141A712A0);
    }
    v356 = 1;
    v357 = (__int128 *)&v341->m_nodes.m_data[v352];
    *v357 = v354;
    v357[1] = (__int128)v355;
  }
  else
  {
    v356 = 0;
  }
  v358 = v391;
  v359 = (char *)p;
  if ( p == v390 )
    v358 = 0;
  v391 = v358;
  v360 = (8 * v394 + 127) & 0xFFFFFF80;
  v361 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v362 = (v360 + 15) & 0xFFFFFFF0;
  if ( v360 > v361->m_slabSize || &v359[v362] != v361->m_cur || v361->m_firstNonLifoEnd == v359 )
    hkLifoAllocator::slowBlockFree(v361, v359, v362);
  else
    v361->m_cur = v359;
  v391 = 0;
  if ( v392 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v390,
      8 * v392);
  v390 = 0i64;
  v392 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v389,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&tolerance,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v397);
  return v356;
}[8];
  if ( LODWORD(v341[1].m_nodes.m_data) )
  {
    v352 = *(_QWORD *)&v341[1].m_nodes.m_size;
    if ( v352 )
    {
      v353 = (_OWORD *)v341->m_nodes.m_data[v352].m_aabb.m_min.m_quad.m128_f32;
      v354 = *v353;
      v355 = *((__m128 *)v353 + 1);
    }
    else
    {
      v354 = xmmword_141A712A0;
      v355 = _mm_xor_ps(
               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
               (__m128)xmmword_141A712A0);
    }
    v356 = 1;
    v357 = (__int128 *)&v341->m_nodes.m_data[v352];
    *v357 = v354;
    v357[1] = (__int128)v355;
  }
  else
  {
    v356 = 0;
  }
  v358 = v391;
  v359 = (char *)p;
  if ( p == v390 )
    v358 = 0;
  v391 = v358;
  v360 = (8 * v394 + 127) & 0xFFFFFF80;
  v361 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v362 = (v360 + 15) & 0xFFFFFFF0;
  if ( v360 > v361->m_slabSize || &v359[v362] != v361->m_cur || v361->m_firstNonLifoEnd == v359 )
    hkLifoAllocator::slowBlockFree(v361, v359, v362);
  else
    v361->m_cur = v359;
  v391 = 0;
  if ( v392 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v390,
      8 * v392);
  v390 = 0i64;
  v392 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v389,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    

// File Line: 402
// RVA: 0xDECF60
char __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep3<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *this, hkcdStaticMeshTreeBase::BuildConfig *config, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *qInfos, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *provider, hkcdStaticMeshTreeBase::BuildMapping *mapping, hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *quads, hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *roots, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *masterTree, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *mesh)
{
  hkcdStaticMeshTreeBase::BuildMapping *v9; // rdi
  int v10; // ebx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v11; // r14
  int v12; // eax
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v13; // r11
  int v14; // er13
  int v15; // er12
  __int64 v16; // rsi
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v17; // r9
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *v18; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v19; // rdx
  float v20; // er13
  __int64 v21; // r15
  signed int v22; // er10
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v23; // r15
  unsigned __int64 v24; // rbx
  __int64 v25; // r8
  int v26; // ecx
  __int64 v27; // rcx
  __int64 i; // rdi
  int v29; // eax
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v30; // rdx
  unsigned __int64 v31; // rax
  __int64 v32; // r9
  signed int v33; // er11
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v34; // rdx
  __int64 v35; // r8
  int v36; // ecx
  __int64 v37; // rcx
  __int64 j; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v39; // rcx
  __int64 v40; // rax
  __int64 v41; // rsi
  void **v42; // r12
  int v43; // eax
  int v44; // eax
  int v45; // er9
  int v46; // eax
  __int64 v47; // rbx
  _DWORD *v48; // rdi
  __int64 v49; // rcx
  __int64 v50; // rdx
  signed __int64 v51; // rax
  int v52; // esi
  int v53; // er15
  int v54; // eax
  __int64 v55; // rdi
  signed int *v56; // rbx
  unsigned int v57; // ecx
  __int64 v58; // rdx
  signed int *v59; // rcx
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v60; // r8
  __m128 *v61; // rax
  __m128 v62; // xmm12
  __int64 v63; // rdx
  __int64 v64; // rdi
  __m128 *v65; // rax
  __m128 *v66; // rcx
  unsigned int v67; // eax
  __int64 v68; // rdx
  int *v69; // rcx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *v70; // r11
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v71; // rax
  int v72; // edx
  __int64 v73; // r12
  int v74; // er9
  int v75; // edi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v76; // rsi
  signed __int64 v77; // rcx
  int v78; // eax
  __int64 v79; // rdx
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v80; // rdx
  int v81; // edi
  int v82; // er12
  float v83; // xmm13_4
  char *v84; // rcx
  __m128 *v85; // rdi
  unsigned __int64 v86; // r10
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v87; // rdx
  __m128 v88; // xmm10
  __m128 v89; // xmm13
  unsigned __int64 v90; // r8
  __int64 v91; // rax
  unsigned __int64 v92; // rdx
  __int64 v93; // rcx
  __int64 v94; // rcx
  __int64 k; // rdi
  __int64 v96; // rax
  unsigned __int64 v97; // rdx
  __int64 v98; // rcx
  __int64 v99; // rsi
  int v100; // eax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v101; // rdi
  int v102; // edx
  __int64 v103; // rdx
  unsigned int *v104; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *v105; // r15
  signed __int64 v106; // r14
  unsigned int v107; // edi
  unsigned int v108; // edi
  int v109; // ebx
  unsigned int v110; // edi
  __int64 *v111; // rsi
  signed __int64 v112; // r15
  __int64 v113; // rdx
  __int64 v114; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *v115; // rcx
  int v116; // eax
  __m128 v117; // xmm7
  __m128 v118; // xmm1
  __m128 v119; // xmm2
  __m128 v120; // xmm3
  __m128 v121; // xmm1
  __m128 v122; // xmm4
  float v123; // xmm0_4
  unsigned int v124; // ecx
  __m128 v125; // xmm4
  __m128 v126; // xmm0
  __m128 v127; // xmm3
  __m128 v128; // xmm5
  __m128 v129; // xmm5
  __m128 v130; // xmm2
  hkOstream *v131; // rax
  hkOstream *v132; // rax
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v133; // rsi
  unsigned int *v134; // rdx
  signed __int64 v135; // rcx
  int v136; // er15
  __m128 v137; // xmm8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v138; // r13
  __m128 v139; // xmm7
  char *v140; // rax
  __m128 v141; // xmm6
  signed int *v142; // r12
  int v143; // ecx
  __int64 v144; // rdx
  unsigned int *v145; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *v146; // r13
  signed __int64 v147; // r14
  unsigned int v148; // edi
  unsigned int v149; // edi
  int v150; // ebx
  unsigned int v151; // edi
  __int64 *v152; // rdi
  signed __int64 v153; // rsi
  __int64 v154; // rdx
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *v155; // rdi
  int v156; // er9
  int v157; // eax
  int v158; // eax
  int v159; // er9
  unsigned __int64 *v160; // r15
  signed int v161; // eax
  int v162; // eax
  int v163; // er9
  int *v164; // r12
  int v165; // eax
  int v166; // eax
  int v167; // eax
  int v168; // eax
  int v169; // eax
  float v170; // xmm15_4
  int v171; // er13
  float v172; // xmm14_4
  __m128 *v173; // r9
  __m128 v174; // xmm11
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v175; // rdx
  __m128 v176; // xmm10
  __int64 v177; // rdi
  __int64 v178; // r8
  __m128 *v179; // r12
  __int64 v180; // r15
  __int64 v181; // rcx
  int v182; // eax
  signed __int64 v183; // rcx
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *v184; // r8
  unsigned __int64 *v185; // rdx
  __int64 v186; // rcx
  __m128 *v187; // rax
  int v188; // esi
  __m128 v189; // xmm7
  __m128 v190; // xmm8
  __int64 v191; // rdx
  unsigned int *v192; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *v193; // r13
  signed __int64 v194; // r14
  unsigned int v195; // edi
  unsigned int v196; // edi
  int v197; // ebx
  unsigned int v198; // edi
  int v199; // ebx
  signed __int64 v200; // rdx
  __int64 *v201; // r13
  __int64 v202; // rcx
  __int64 v203; // rsi
  int v204; // eax
  unsigned __int64 *v205; // r9
  unsigned __int64 v206; // rdx
  __int64 v207; // rdi
  __m128 v208; // xmm2
  __m128 v209; // xmm1
  __m128 v210; // xmm3
  __m128 v211; // xmm1
  __m128 v212; // xmm4
  __m128i v213; // xmm1
  __m128 v214; // xmm1
  signed __int64 v215; // rax
  __m128 v216; // xmm2
  __m128 v217; // xmm3
  __m128 v218; // xmm2
  __m128 v219; // xmm4
  float v220; // xmm4_4
  signed __int64 v221; // rdx
  float v222; // xmm0_4
  signed __int64 v223; // rcx
  signed __int64 v224; // rax
  float v225; // xmm0_4
  signed __int64 v226; // rdx
  signed __int64 v227; // rcx
  __m128i v228; // xmm2
  __m128 v229; // xmm0
  unsigned __int64 v230; // r9
  unsigned __int64 *v231; // r9
  unsigned __int64 v232; // rcx
  __int64 v233; // rdx
  __m128 v234; // xmm1
  __int64 v235; // r8
  __int64 v236; // r9
  __m128 v237; // xmm5
  __m128 v238; // xmm12
  __m128 v239; // xmm13
  __m128i v240; // xmm14
  __m128i v241; // xmm15
  __m128 v242; // xmm2
  signed __int64 v243; // rax
  __m128 v244; // xmm3
  __m128 v245; // xmm4
  __m128 v246; // xmm1
  __m128 v247; // xmm2
  float v248; // xmm2_4
  signed __int64 v249; // rdx
  signed __int64 v250; // rcx
  float v251; // xmm0_4
  signed __int64 v252; // rax
  float v253; // xmm0_4
  signed __int64 v254; // rdx
  signed __int64 v255; // rcx
  __m128i v256; // xmm2
  __m128 v257; // xmm0
  __int64 v258; // rdx
  __m128 v259; // xmm8
  __m128 v260; // xmm7
  __m128 *v261; // rax
  unsigned __int64 l; // rcx
  __m128 *v263; // rcx
  __m128 v264; // xmm3
  bool v265; // zf
  _WORD *v266; // rax
  int v267; // ecx
  _WORD *v268; // r13
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v269; // r9
  __int64 v270; // rsi
  signed __int64 v271; // rdx
  int v272; // er8
  signed __int64 v273; // rsi
  int v274; // eax
  unsigned __int64 v275; // rdx
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v276; // rsi
  unsigned __int64 v277; // r10
  int v278; // eax
  hkcdDynamicTree::CodecRawUlong *v279; // rdi
  unsigned __int64 v280; // r9
  unsigned __int64 v281; // rcx
  unsigned __int64 v282; // rdx
  unsigned __int64 m; // r8
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v284; // r10
  int v285; // er11
  int v286; // edx
  int v287; // esi
  int v288; // er8
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v289; // r9
  _WORD *v290; // rdi
  signed __int64 n; // rcx
  int v292; // eax
  float v293; // ecx
  int v294; // eax
  int v295; // er8
  signed __int64 v296; // rdi
  signed __int64 v297; // rsi
  __int64 v298; // rdx
  _BYTE *v299; // r13
  __int64 v300; // rdi
  unsigned __int8 v301; // si
  __int64 v302; // rdx
  char *v303; // rcx
  char v304; // di
  signed __int64 v305; // r9
  __m128 v306; // xmm11
  hkVector4f v307; // xmm13
  hkVector4f v308; // xmm8
  float v309; // xmm11_4
  hkcdStaticMeshTreeBase::CompressionMode v310; // ecx
  __m128 v311; // xmm10
  unsigned __int64 v312; // rdi
  __int64 v313; // rsi
  int v314; // er9
  int v315; // eax
  int v316; // eax
  int v317; // edi
  __int64 v318; // r8
  __m128 v319; // xmm2
  __m128 v320; // xmm1
  __m128 v321; // xmm5
  __m128 v322; // xmm3
  __m128 v323; // xmm2
  __m128 v324; // xmm4
  unsigned __int16 v325; // cx
  __m128 v326; // xmm1
  __m128 v327; // xmm1
  __m128 v328; // xmm4
  __m128 v329; // xmm2
  int v330; // esi
  int v331; // eax
  int v332; // eax
  int v333; // er9
  __m128 v334; // xmm13
  unsigned __int64 v335; // rdi
  __int64 v336; // rsi
  int v337; // er9
  int v338; // eax
  int v339; // eax
  int v340; // edx
  __int64 v341; // rdi
  int *v342; // r8
  __m128 v343; // xmm1
  __m128 v344; // xmm2
  __m128 v345; // xmm5
  __m128 v346; // xmm3
  __m128 v347; // xmm2
  __m128 v348; // xmm4
  __m128i v349; // xmm1
  __m128 v350; // xmm1
  __m128 v351; // xmm1
  __m128 v352; // xmm4
  __m128 v353; // xmm2
  int v354; // eax
  int v355; // eax
  int v356; // er9
  int v357; // edi
  __int64 v358; // rsi
  int v359; // eax
  int v360; // eax
  signed __int64 v361; // rdi
  int v362; // er8
  __m128 v363; // xmm2
  __m128 v364; // xmm1
  signed __int64 v365; // rax
  __m128 v366; // xmm3
  __m128 v367; // xmm4
  __m128 v368; // xmm1
  __m128 v369; // xmm5
  float v370; // xmm5_4
  signed __int64 v371; // rdx
  float v372; // xmm0_4
  signed __int64 v373; // rcx
  signed __int64 v374; // rax
  float v375; // xmm0_4
  signed __int64 v376; // rdx
  signed __int64 v377; // rcx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v378; // r8
  __int64 v379; // rdx
  signed __int64 v380; // rdi
  __int64 v381; // rcx
  __int64 v382; // rax
  signed __int64 v383; // rdi
  __int64 v384; // rcx
  __int64 v385; // rax
  hkcdStaticMeshTreeBase::BuildConfig *v386; // rdx
  __int16 v387; // di
  __int64 v388; // rdx
  int v389; // esi
  hkFixedInplaceArray<unsigned short,3> *v390; // rdi
  hkpBvCompressedMeshShape_Internals::GeometryProvider *v391; // rdi
  __int64 v392; // rdx
  hkArray<hkpBvCompressedMeshShape_Internals::PrimitiveData,hkContainerHeapAllocator> *v393; // rax
  signed __int64 v394; // rdi
  __int64 v395; // rdx
  __int64 v396; // rdx
  unsigned int *v397; // rsi
  signed __int64 v398; // r14
  unsigned int v399; // er9
  int v400; // edi
  unsigned int v401; // edi
  int v402; // ebx
  unsigned int v403; // edi
  __int64 *v404; // rsi
  __int64 v405; // rdi
  __int64 v406; // rax
  __int64 v407; // r9
  __m128 v408; // xmm2
  __int64 v409; // r8
  signed __int64 v410; // rax
  __m128 v411; // xmm2
  __m128 v412; // xmm3
  __m128 v413; // xmm4
  __m128 v414; // xmm2
  __m128 v415; // xmm5
  float v416; // xmm5_4
  signed __int64 v417; // rdx
  float v418; // xmm0_4
  signed __int64 v419; // rcx
  signed __int64 v420; // rax
  float v421; // xmm0_4
  signed __int64 v422; // rdx
  signed __int64 v423; // rcx
  int v424; // eax
  __int64 v425; // rcx
  _WORD *v426; // r8
  char v427; // cl
  hkResult *v428; // rax
  int v429; // ecx
  _DWORD *v430; // rdi
  int v431; // esi
  int v432; // eax
  int v433; // eax
  int v434; // er9
  int v435; // edi
  int v436; // eax
  int v437; // eax
  int v438; // er9
  int v439; // eax
  int v440; // eax
  int v441; // er9
  __int64 v442; // rcx
  signed int *v443; // rax
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v444; // r11
  int v445; // er10
  int v446; // ecx
  int *v447; // rdx
  __int64 v448; // rax
  _QWORD *v449; // r9
  int v450; // edx
  int v451; // edi
  unsigned __int64 v452; // r8
  __int64 v453; // rdi
  __int64 v454; // r8
  int v455; // edi
  __int64 v456; // rdx
  unsigned __int8 v457; // al
  int v458; // er9
  int *v459; // r8
  int *v460; // rdi
  __int64 v461; // rax
  int v462; // edx
  int v463; // er13
  unsigned int *v464; // rsi
  __int64 v465; // rdi
  int v466; // er8
  __int64 v467; // rdx
  int *v468; // r9
  unsigned int v469; // edi
  int v470; // er10
  __int64 v471; // rdx
  __int64 v472; // rcx
  __int64 v473; // r9
  signed __int64 v474; // r11
  __int64 v475; // rsi
  __int64 v476; // r8
  signed __int64 v477; // rdx
  __int64 v478; // rdi
  _BYTE *v479; // rcx
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v480; // rax
  int v481; // edx
  unsigned int *v482; // r13
  signed __int64 v483; // rdi
  int v484; // ecx
  int v485; // ecx
  int v486; // ecx
  int v487; // ecx
  int v488; // ecx
  int v489; // ecx
  int v490; // edi
  _DWORD *v491; // rdx
  int v492; // ecx
  int v493; // esi
  hkPointerMap<int,int,hkContainerHeapAllocator> *v494; // rdi
  int v496; // [rsp+30h] [rbp-D0h]
  int v497; // [rsp+30h] [rbp-D0h]
  __int16 v498; // [rsp+30h] [rbp-D0h]
  int v499; // [rsp+34h] [rbp-CCh]
  int v500; // [rsp+34h] [rbp-CCh]
  int v501; // [rsp+34h] [rbp-CCh]
  int v502; // [rsp+34h] [rbp-CCh]
  int v503; // [rsp+38h] [rbp-C8h]
  unsigned int v504; // [rsp+38h] [rbp-C8h]
  int v505; // [rsp+3Ch] [rbp-C4h]
  int v506; // [rsp+3Ch] [rbp-C4h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v507; // [rsp+40h] [rbp-C0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v508; // [rsp+40h] [rbp-C0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v509; // [rsp+40h] [rbp-C0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v510; // [rsp+40h] [rbp-C0h]
  int v511; // [rsp+48h] [rbp-B8h]
  signed __int64 v512; // [rsp+50h] [rbp-B0h]
  signed __int64 v513; // [rsp+50h] [rbp-B0h]
  __int64 v514; // [rsp+50h] [rbp-B0h]
  signed __int64 v515; // [rsp+50h] [rbp-B0h]
  int v516; // [rsp+58h] [rbp-A8h]
  __int64 v517; // [rsp+60h] [rbp-A0h]
  signed __int64 v518; // [rsp+60h] [rbp-A0h]
  _WORD *v519; // [rsp+60h] [rbp-A0h]
  int primitiveIndex; // [rsp+68h] [rbp-98h]
  int primitiveIndexa; // [rsp+68h] [rbp-98h]
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v522; // [rsp+70h] [rbp-90h]
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v523; // [rsp+70h] [rbp-90h]
  char *v524; // [rsp+78h] [rbp-88h]
  unsigned __int64 *v525; // [rsp+78h] [rbp-88h]
  signed int *v526; // [rsp+80h] [rbp-80h]
  int v527; // [rsp+88h] [rbp-78h]
  __m128 *v528; // [rsp+90h] [rbp-70h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *array; // [rsp+98h] [rbp-68h]
  int v530; // [rsp+A0h] [rbp-60h]
  int v531; // [rsp+A4h] [rbp-5Ch]
  __int64 v532; // [rsp+A8h] [rbp-58h]
  __int64 v533; // [rsp+B0h] [rbp-50h]
  __int64 v534; // [rsp+B8h] [rbp-48h]
  __int64 v535; // [rsp+C0h] [rbp-40h]
  __int64 v536; // [rsp+C8h] [rbp-38h]
  __int64 v537; // [rsp+D0h] [rbp-30h]
  __int64 v538; // [rsp+D8h] [rbp-28h]
  __int64 v539; // [rsp+E0h] [rbp-20h]
  int v540; // [rsp+E8h] [rbp-18h]
  int v541; // [rsp+ECh] [rbp-14h]
  __int64 v542; // [rsp+F0h] [rbp-10h]
  int v543; // [rsp+F8h] [rbp-8h]
  hkResult v544[2]; // [rsp+100h] [rbp+0h]
  __int64 v545; // [rsp+108h] [rbp+8h]
  int v546; // [rsp+110h] [rbp+10h]
  int v547; // [rsp+114h] [rbp+14h]
  unsigned int v548; // [rsp+118h] [rbp+18h]
  int v549; // [rsp+11Ch] [rbp+1Ch]
  int v550; // [rsp+120h] [rbp+20h]
  int v551; // [rsp+124h] [rbp+24h]
  int v552; // [rsp+128h] [rbp+28h]
  int v553; // [rsp+130h] [rbp+30h]
  int v554; // [rsp+134h] [rbp+34h]
  int v555; // [rsp+138h] [rbp+38h]
  int v556; // [rsp+140h] [rbp+40h]
  int v557; // [rsp+144h] [rbp+44h]
  int v558; // [rsp+148h] [rbp+48h]
  int v559; // [rsp+150h] [rbp+50h]
  int v560; // [rsp+154h] [rbp+54h]
  int v561; // [rsp+158h] [rbp+58h]
  int v562; // [rsp+160h] [rbp+60h]
  int v563; // [rsp+164h] [rbp+64h]
  int v564; // [rsp+168h] [rbp+68h]
  int v565; // [rsp+170h] [rbp+70h]
  int v566; // [rsp+174h] [rbp+74h]
  int v567; // [rsp+178h] [rbp+78h]
  int v568; // [rsp+180h] [rbp+80h]
  int v569; // [rsp+184h] [rbp+84h]
  int v570; // [rsp+188h] [rbp+88h]
  int v571; // [rsp+190h] [rbp+90h]
  int v572; // [rsp+194h] [rbp+94h]
  int v573; // [rsp+198h] [rbp+98h]
  int v574; // [rsp+1A0h] [rbp+A0h]
  int v575; // [rsp+1A4h] [rbp+A4h]
  int v576; // [rsp+1A8h] [rbp+A8h]
  int v577; // [rsp+1B0h] [rbp+B0h]
  int v578; // [rsp+1B4h] [rbp+B4h]
  int v579; // [rsp+1B8h] [rbp+B8h]
  int v580; // [rsp+1C0h] [rbp+C0h]
  int v581; // [rsp+1C4h] [rbp+C4h]
  int v582; // [rsp+1C8h] [rbp+C8h]
  int v583; // [rsp+1D0h] [rbp+D0h]
  int v584; // [rsp+1D4h] [rbp+D4h]
  int v585; // [rsp+1D8h] [rbp+D8h]
  int v586; // [rsp+1E0h] [rbp+E0h]
  int v587; // [rsp+1E4h] [rbp+E4h]
  int v588; // [rsp+1E8h] [rbp+E8h]
  int v589; // [rsp+1F0h] [rbp+F0h]
  int v590; // [rsp+1F4h] [rbp+F4h]
  int v591; // [rsp+1F8h] [rbp+F8h]
  int v592; // [rsp+200h] [rbp+100h]
  int v593; // [rsp+204h] [rbp+104h]
  int v594; // [rsp+208h] [rbp+108h]
  int v595; // [rsp+210h] [rbp+110h]
  int v596; // [rsp+214h] [rbp+114h]
  int v597; // [rsp+218h] [rbp+118h]
  hkcdStaticMeshTreeBase::BuildCustomInfos v598; // [rsp+220h] [rbp+120h]
  unsigned int *v599; // [rsp+260h] [rbp+160h]
  void *v600; // [rsp+268h] [rbp+168h]
  __int64 v601; // [rsp+270h] [rbp+170h]
  __int64 v602; // [rsp+278h] [rbp+178h]
  __int64 v603; // [rsp+280h] [rbp+180h]
  __int64 v604; // [rsp+288h] [rbp+188h]
  hkResult v605; // [rsp+290h] [rbp+190h]
  hkResult v606; // [rsp+294h] [rbp+194h]
  unsigned int v607; // [rsp+298h] [rbp+198h]
  unsigned __int64 v608; // [rsp+2A0h] [rbp+1A0h]
  int v609; // [rsp+2A8h] [rbp+1A8h]
  hkResult v610; // [rsp+2ACh] [rbp+1ACh]
  hkResult v611; // [rsp+2B0h] [rbp+1B0h]
  hkResult v612; // [rsp+2B4h] [rbp+1B4h]
  hkResult v613; // [rsp+2B8h] [rbp+1B8h]
  unsigned __int64 *v614; // [rsp+2C0h] [rbp+1C0h]
  hkResult v615; // [rsp+2C8h] [rbp+1C8h]
  hkResult v616; // [rsp+2CCh] [rbp+1CCh]
  hkResult result; // [rsp+2D0h] [rbp+1D0h]
  hkResult v618; // [rsp+2D4h] [rbp+1D4h]
  hkResult v619; // [rsp+2D8h] [rbp+1D8h]
  hkResult v620; // [rsp+2DCh] [rbp+1DCh]
  hkResult v621; // [rsp+2E0h] [rbp+1E0h]
  __m128 v622; // [rsp+2F0h] [rbp+1F0h]
  int v623; // [rsp+300h] [rbp+200h]
  hkResult v624; // [rsp+304h] [rbp+204h]
  int *v625; // [rsp+308h] [rbp+208h]
  __m128 v626; // [rsp+310h] [rbp+210h]
  __int64 v627; // [rsp+320h] [rbp+220h]
  __m128 v628; // [rsp+330h] [rbp+230h]
  __m128 v629; // [rsp+340h] [rbp+240h]
  __int64 v630; // [rsp+350h] [rbp+250h]
  __m128 v631; // [rsp+360h] [rbp+260h]
  unsigned __int64 out[2]; // [rsp+370h] [rbp+270h]
  __int64 v633; // [rsp+380h] [rbp+280h]
  hkResult v634; // [rsp+388h] [rbp+288h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree dTree; // [rsp+390h] [rbp+290h]
  __m128 v636; // [rsp+3C0h] [rbp+2C0h]
  __m128 v637; // [rsp+3D0h] [rbp+2D0h]
  __m128 v638; // [rsp+3E0h] [rbp+2E0h]
  __m128 v639; // [rsp+3F0h] [rbp+2F0h]
  hkcdStaticMeshTreeBase::BuildCustomInfos v640; // [rsp+400h] [rbp+300h]
  hkcdStaticMeshTreeBase::BuildCustomInfos customPrimitive; // [rsp+440h] [rbp+340h]
  __m128 v642; // [rsp+480h] [rbp+380h]
  hkErrStream v643; // [rsp+490h] [rbp+390h]
  __m128 v644; // [rsp+4B0h] [rbp+3B0h]
  __m128 v645; // [rsp+4C0h] [rbp+3C0h]
  __m128 v646; // [rsp+4D0h] [rbp+3D0h]
  __m128 v647; // [rsp+4E0h] [rbp+3E0h]
  __m128 v648; // [rsp+4F0h] [rbp+3F0h]
  __m128 v649; // [rsp+500h] [rbp+400h]
  __m128 v650; // [rsp+510h] [rbp+410h]
  __m128 v651; // [rsp+520h] [rbp+420h]
  __m128 v652; // [rsp+530h] [rbp+430h]
  __m128 v653; // [rsp+540h] [rbp+440h]
  __m128 v654; // [rsp+550h] [rbp+450h]
  char v655; // [rsp+560h] [rbp+460h]
  char v656; // [rsp+56Ch] [rbp+46Ch]
  hkAabb aabb; // [rsp+570h] [rbp+470h]
  __m128 v658; // [rsp+590h] [rbp+490h]
  __int128 v659; // [rsp+5A0h] [rbp+4A0h]
  __m128 v660; // [rsp+5B0h] [rbp+4B0h]
  __m128 v661; // [rsp+5C0h] [rbp+4C0h]
  __m128 v662; // [rsp+5D0h] [rbp+4D0h]
  __m128 v663; // [rsp+5E0h] [rbp+4E0h]
  __m128 v664; // [rsp+5F0h] [rbp+4F0h]
  __int128 v665; // [rsp+600h] [rbp+500h]
  __int128 v666; // [rsp+610h] [rbp+510h]
  __int128 v667; // [rsp+620h] [rbp+520h]
  __m128 v668; // [rsp+630h] [rbp+530h]
  __m128 v669; // [rsp+640h] [rbp+540h]
  __m128 v670; // [rsp+650h] [rbp+550h]
  __m128 v671; // [rsp+660h] [rbp+560h]
  __m128 v672; // [rsp+670h] [rbp+570h]
  int pArr[128]; // [rsp+680h] [rbp+580h]
  int v674; // [rsp+880h] [rbp+780h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DataSorter cmpLess; // [rsp+890h] [rbp+790h]
  int v676; // [rsp+A90h] [rbp+990h]
  int v677; // [rsp+A9Ch] [rbp+99Ch]
  int v678[128]; // [rsp+AA0h] [rbp+9A0h]
  int v679; // [rsp+CA0h] [rbp+BA0h]
  int v680[128]; // [rsp+CB0h] [rbp+BB0h]
  int v681; // [rsp+EB0h] [rbp+DB0h]
  int v682; // [rsp+EC0h] [rbp+DC0h]
  int v683[255]; // [rsp+EC4h] [rbp+DC4h]
  int v684; // [rsp+12C0h] [rbp+11C0h]
  char buf; // [rsp+12D0h] [rbp+11D0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *v686; // [rsp+15C0h] [rbp+14C0h]
  hkcdStaticMeshTreeBase::BuildConfig *v687; // [rsp+15C8h] [rbp+14C8h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *v688; // [rsp+15D0h] [rbp+14D0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v689; // [rsp+15D8h] [rbp+14D8h]

  v689 = provider;
  v688 = qInfos;
  v687 = config;
  v686 = this;
  v9 = mapping;
  v10 = mapping->m_triangleIndexToKey.m_size;
  v527 = mapping->m_triangleIndexToKey.m_size;
  v11 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)qInfos;
  v12 = (*(__int64 (**)(void))(**(_QWORD **)(*(_QWORD *)&qInfos->m_size[2] + 8i64) + 16i64))();
  v13 = quads;
  v14 = 0;
  v15 = 0;
  v511 = v10 + v12;
  if ( quads->m_size > 0 )
  {
    v16 = 0i64;
    while ( *(_DWORD *)v13->m_data[v16 + 1].m_edges < 128 )
    {
      v17 = (hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *)v9;
      v18 = roots;
      if ( hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree::countVertices<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
             (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *)&v13->m_data[2 * v15],
             (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *)roots,
             v11,
             v17) >= 256 )
      {
        v13 = quads;
LABEL_6:
        v19 = v18->m_data;
        v20 = v13->m_data[v16].m_value;
        v21 = *(_QWORD *)v13->m_data[v16].m_edges << 6;
        v626.m128_i32[2] = LODWORD(v13->m_data[v16].m_value);
        v22 = 0;
        v23 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *)((char *)v19 + v21);
        v24 = v23[2].m_node;
        if ( v24 )
        {
          if ( *(&v19[1].m_numVertices + 16 * v23[2].m_node) )
          {
            v25 = *((_QWORD *)&v19[1].m_numVertices + 8 * v23[2].m_node);
            if ( v25 )
            {
              do
              {
                v26 = *(&v19[1].m_numVertices + 16 * v25);
                v22 += v26 == 0;
                if ( v26 )
                {
                  v25 = *((_QWORD *)&v19[1].m_numVertices + 8 * v25);
                }
                else
                {
                  v27 = *((_QWORD *)&v19[1].m_layer + 8 * v25);
                  for ( i = v25; v27 != v24; v27 = *((_QWORD *)&v19[1].m_layer + 8 * v27) )
                  {
                    if ( *(&v19[2].m_node + 8 * v27) != i )
                      break;
                    i = v27;
                  }
                  if ( v27 )
                    v25 = *(&v19[2].m_node + 8 * v27);
                  else
                    v25 = i;
                  if ( v27 == v24 && v25 == i )
                    v25 = 0i64;
                }
              }
              while ( v25 );
              v11 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v688;
              v18 = roots;
            }
          }
          else
          {
            v22 = 1;
          }
        }
        v29 = v13->m_capacityAndFlags;
        v626.m128_i32[3] = v22;
        LODWORD(v627) = -1;
        if ( v13->m_size == (v29 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, 24);
          v13 = quads;
        }
        v30 = &v13->m_data[2 * v13->m_size];
        if ( v30 )
        {
          v31 = v626.m128_u64[1];
          *(_QWORD *)v30->m_edges = v24;
          *(_QWORD *)&v30->m_value = v31;
          *(_QWORD *)&v30[1].m_edges[1] = v627;
        }
        ++v13->m_size;
        v32 = *(_QWORD *)&v23[1].m_numVertices;
        v629.m128_f32[2] = v20;
        v14 = 0;
        v33 = 0;
        if ( v32 )
        {
          v34 = v18->m_data;
          if ( *(&v18->m_data[1].m_numVertices + 16 * v32) )
          {
            v35 = *((_QWORD *)&v18->m_data[1].m_numVertices + 8 * v32);
            while ( v35 )
            {
              v36 = *(&v34[1].m_numVertices + 16 * v35);
              v33 += v36 == 0;
              if ( v36 )
              {
                v35 = *((_QWORD *)&v34[1].m_numVertices + 8 * v35);
              }
              else
              {
                v37 = *((_QWORD *)&v34[1].m_layer + 8 * v35);
                for ( j = v35; v37 != v32; v37 = *((_QWORD *)&v34[1].m_layer + 8 * v37) )
                {
                  if ( *(&v34[2].m_node + 8 * v37) != j )
                    break;
                  j = v37;
                }
                if ( v37 )
                  v35 = *(&v34[2].m_node + 8 * v37);
                else
                  v35 = j;
                if ( v37 == v32 && v35 == j )
                  v35 = 0i64;
              }
            }
          }
          else
          {
            v33 = 1;
          }
        }
        v629.m128_i32[3] = v33;
        v13 = quads;
        v39 = quads->m_data;
        LODWORD(v630) = -1;
        v40 = v629.m128_i64[1];
        *(_QWORD *)v39[v16].m_edges = v32;
        *(_QWORD *)&v39[v16].m_value = v40;
        *(_QWORD *)&v39[v16 + 1].m_edges[1] = v630;
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
  v41 = v13->m_size;
  v42 = (void **)&masterTree[1].m_numLeaves;
  v43 = HIDWORD(masterTree[1].m_root) & 0x3FFFFFFF;
  v599 = &masterTree[1].m_numLeaves;
  if ( v43 >= (signed int)v41 )
  {
    result.m_enum = 0;
  }
  else
  {
    v44 = 2 * v43;
    v45 = v41;
    if ( (signed int)v41 < v44 )
      v45 = v44;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &masterTree[1].m_numLeaves,
      v45,
      96);
  }
  v46 = LODWORD(masterTree[1].m_root) - v41 - 1;
  v47 = v46;
  if ( v46 >= 0 )
  {
    v48 = (char *)*v42 + 96 * v41 + 96 * v46 + 12;
    do
    {
      *(v48 - 1) = 0;
      if ( *v48 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v48 - 3),
          4 * *v48);
      *(_QWORD *)(v48 - 3) = 0i64;
      *v48 = 2147483648;
      v48 -= 24;
      --v47;
    }
    while ( v47 >= 0 );
  }
  v49 = SLODWORD(masterTree[1].m_root);
  v50 = (signed int)v41 - (signed int)v49;
  if ( (signed int)v41 - (signed int)v49 > 0 )
  {
    v51 = (signed __int64)*v42 + 96 * v49 + 8;
    do
    {
      if ( v51 != 8 )
      {
        *(_QWORD *)(v51 - 8) = 0i64;
        *(_DWORD *)v51 = 0;
        *(_DWORD *)(v51 + 4) = 2147483648;
        *(_OWORD *)(v51 + 8) = xmmword_141A712A0;
        *(__m128 *)(v51 + 24) = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                  *(__m128 *)(v51 + 8));
      }
      v51 += 96i64;
      --v50;
    }
    while ( v50 );
  }
  LODWORD(masterTree[1].m_root) = v41;
  hkString::memSet(*v42, 0, 96 * LODWORD(masterTree[1].m_root));
  v52 = 0;
  v505 = 0;
  v53 = 0;
  v496 = 0;
  v503 = 0;
  v54 = v11->vfptr->getNumVertices((hkGeometryUtils::IVertices *)&v11->vfptr);
  v55 = v54;
  v607 = v54;
  if ( v54 )
  {
    v546 = 8 * v54;
    v56 = (signed int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                          &v546);
    v54 = v546 / 8;
  }
  else
  {
    v56 = 0i64;
  }
  v57 = 2147483648;
  v526 = v56;
  if ( v54 )
    v57 = v54;
  v58 = v55;
  v609 = v57;
  if ( (signed int)v55 > 0 )
  {
    v59 = v56;
    do
    {
      if ( v59 )
        *(_QWORD *)v59 = -1i64;
      v59 += 2;
      --v58;
    }
    while ( v58 );
  }
  v60 = quads;
  v61 = (__m128 *)((char *)roots->m_data + 64 * (_QWORD)roots[2].m_data);
  v62 = *v61;
  v626 = v61[1];
  v638 = v62;
  v622 = v62;
  v628 = _mm_sub_ps(v626, v62);
  v639 = _mm_mul_ps(
           v628,
           (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  v63 = quads->m_size;
  v64 = v63;
  if ( (_DWORD)v63 )
  {
    v547 = 2096 * v63;
    v65 = (__m128 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      &v547);
    v60 = quads;
    v66 = v65;
    LODWORD(v63) = v547 / 2096;
  }
  else
  {
    v66 = 0i64;
  }
  v67 = 2147483648;
  v528 = v66;
  if ( (_DWORD)v63 )
    v67 = v63;
  v68 = v64;
  v623 = v67;
  if ( (signed int)v64 > 0 )
  {
    v69 = &v66[130].m128_i32[2];
    do
    {
      if ( v69 != (int *)2088 )
      {
        *(v69 - 258) = 0;
        *v69 = 0;
      }
      v69 += 524;
      --v68;
    }
    while ( v68 );
  }
  v70 = v686;
  v71 = 0i64;
  v72 = 0;
  array = 0i64;
  v530 = 0;
  v531 = 2147483648;
  if ( *(_DWORD *)&v686[12] == 2 )
  {
    v73 = v60->m_size;
    if ( (signed int)v73 <= 0 )
    {
      v611.m_enum = 0;
    }
    else
    {
      v74 = v60->m_size;
      if ( (signed int)v73 < 0 )
        v74 = 0;
      hkArrayUtil::_reserve(&v611, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v74, 16);
      v72 = v530;
      v71 = array;
    }
    v75 = v72 - v73 - 1;
    if ( v75 >= 0 )
    {
      v76 = &v71[v73 + v75];
      do
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          v76,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
        --v76;
        --v75;
      }
      while ( v75 >= 0 );
      v72 = v530;
      v71 = array;
      v52 = 0;
    }
    v77 = (signed __int64)&v71[v72];
    v78 = v73 - v72;
    v79 = (signed int)v73 - v72;
    if ( v78 > 0 )
    {
      do
      {
        if ( v77 )
        {
          *(_QWORD *)v77 = 0i64;
          *(_DWORD *)(v77 + 8) = 0;
          *(_DWORD *)(v77 + 12) = -1;
        }
        v77 += 16i64;
        --v79;
      }
      while ( v79 );
      v53 = 0;
    }
    v70 = v686;
    v530 = v73;
  }
  v80 = quads;
  v81 = 0;
  v499 = 0;
  v82 = 0;
  v83 = FLOAT_2047_0;
  if ( quads->m_size > 0 )
  {
    v84 = 0i64;
    v85 = v528 + 66;
    v512 = (signed __int64)&v528[66];
    v524 = 0i64;
    while ( 1 )
    {
      v86 = *(_QWORD *)&v84[(unsigned __int64)v80->m_data];
      v87 = roots->m_data;
      v88 = *((__m128 *)&roots->m_data->m_node + 4 * v86);
      v89 = *((__m128 *)&roots->m_data->m_numVertices + 4 * v86);
      if ( v86 )
      {
        if ( !*(&roots->m_data[1].m_numVertices + 16 * v86) )
        {
          v96 = v85[64].m128_i32[2];
          v85[64].m128_i32[2] = v96 + 1;
          v85->m128_u64[v96 + 1] = v86;
          v97 = *(&roots->m_data[2].m_node + 8 * v86);
          v98 = SLODWORD(v85->m128_u64[0]);
          LODWORD(v85->m128_u64[0]) = v98 + 1;
          v85[-64].m128_u64[v98] = v97;
LABEL_121:
          v84 = v524;
          goto LABEL_122;
        }
        v90 = *((_QWORD *)&v87[1].m_numVertices + 8 * v86);
        if ( v90 )
        {
          do
          {
            if ( !*(&v87[1].m_numVertices + 16 * v90) )
            {
              v91 = v85[64].m128_i32[2];
              v85[64].m128_i32[2] = v91 + 1;
              v85->m128_u64[v91 + 1] = v90;
              v92 = *(&roots->m_data[2].m_node + 8 * v90);
              v93 = SLODWORD(v85->m128_u64[0]);
              LODWORD(v85->m128_u64[0]) = v93 + 1;
              v85[-64].m128_u64[v93] = v92;
            }
            v87 = roots->m_data;
            if ( *(&roots->m_data[1].m_numVertices + 16 * v90) )
            {
              v90 = *((_QWORD *)&v87[1].m_numVertices + 8 * v90);
            }
            else
            {
              v94 = *((_QWORD *)&v87[1].m_layer + 8 * v90);
              for ( k = v90; v94 != v86; v94 = *((_QWORD *)&roots->m_data[1].m_layer + 8 * v94) )
              {
                if ( *(&roots->m_data[2].m_node + 8 * v94) != k )
                  break;
                k = v94;
              }
              if ( v94 )
                v90 = *(&roots->m_data[2].m_node + 8 * v94);
              else
                v90 = k;
              if ( v94 == v86 && v90 == k )
                v90 = 0i64;
              v85 = (__m128 *)v512;
            }
          }
          while ( v90 );
          v14 = v503;
          v11 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v688;
          goto LABEL_121;
        }
      }
LABEL_122:
      v517 = SLODWORD(v85->m128_u64[0]);
      v505 = LODWORD(v85->m128_u64[0]) + v52;
      v99 = SLODWORD(v85->m128_u64[0]);
      if ( SLODWORD(v85->m128_u64[0]) <= 0 )
        goto LABEL_151;
      v100 = v511;
      v101 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v85[-64];
      v507 = v101;
      do
      {
        v102 = LODWORD(v101->m_elem) - v100;
        if ( v102 >= 0 )
        {
          customPrimitive.m_tags.m_size = 0;
          *(_QWORD *)&customPrimitive.m_numVertices = 0i64;
          customPrimitive.m_layerData = 0;
          customPrimitive.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
          customPrimitive.m_maxError = 3.40282e38;
          customPrimitive.m_compression = 1;
          customPrimitive.m_aabb.m_max.m_quad = _mm_xor_ps(
                                                  (__m128)_mm_shuffle_epi32(
                                                            _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                            0),
                                                  (__m128)xmmword_141A712A0);
          hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(
            v11->m_provider,
            v102,
            &customPrimitive);
          v53 += customPrimitive.m_numVertices;
          v496 = v53;
          goto LABEL_148;
        }
        if ( *(_DWORD *)&v70[12] != 2 )
        {
          v538 = 0i64;
          v539 = 0i64;
          v103 = SLODWORD(v101->m_elem);
          if ( (signed int)v103 < v527 )
          {
            v104 = mapping->m_triangleIndexToKey.m_data;
            v105 = v688;
            v106 = 3 * v103;
            v107 = mapping->m_triangleIndexToKey.m_data[3 * v103];
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v688->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v688->m_size[2] + 8i64),
              v107 & 0x3FFFFFFF,
              &v562);
            v562 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v562);
            v563 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v563);
            v564 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v564);
            LODWORD(v538) = *(&v562 + (signed int)((v107 >> 30) + 1) % 3);
            v108 = v104[v106];
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v105->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v105->m_size[2] + 8i64),
              v108 & 0x3FFFFFFF,
              &v580);
            v580 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v580);
            v581 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v581);
            v582 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v582);
            HIDWORD(v538) = *(&v580 + (signed int)((v108 >> 30) + 2) % 3);
            v109 = (signed int)((v104[v106 + 1] >> 30) + 1) % 3;
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v105->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v105->m_size[2] + 8i64),
              v104[v106 + 1] & 0x3FFFFFFF,
              &v568);
            v568 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v568);
            v569 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v569);
            v570 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v570);
            LODWORD(v539) = *(&v568 + v109);
            v110 = v104[v106 + 1];
            v11 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v688;
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v105->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v105->m_size[2] + 8i64),
              v110 & 0x3FFFFFFF,
              &v592);
            v592 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v592);
            v593 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v593);
            v594 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v594);
            HIDWORD(v539) = *(&v592 + (signed int)((v110 >> 30) + 2) % 3);
          }
          else
          {
            v11->m_provider->m_meshCInfo->vfptr->getIndices(
              v11->m_provider->m_meshCInfo,
              v103 - mapping->m_triangleIndexToKey.m_size,
              (int *)&v538);
            LODWORD(v538) = v11->m_vMap.m_data[(signed int)v538];
            HIDWORD(v538) = v11->m_vMap.m_data[SHIDWORD(v538)];
            LODWORD(v539) = v11->m_vMap.m_data[(signed int)v539];
            HIDWORD(v539) = v539;
          }
          v56 = v526;
          v111 = &v538;
          v112 = 4i64;
          while ( 1 )
          {
            v113 = *(signed int *)v111;
            v114 = v113;
            if ( v526[2 * v113] != -2 )
              break;
LABEL_146:
            v111 = (__int64 *)((char *)v111 + 4);
            if ( !--v112 )
            {
              v53 = v496;
              v101 = v507;
              v99 = v517;
              v503 = v14;
LABEL_148:
              v100 = v511;
              v70 = v686;
              goto LABEL_149;
            }
          }
          v115 = v686;
          if ( *(_DWORD *)&v686[12] == 1 )
          {
            v526[2 * v113] = v82 + 1;
            goto LABEL_137;
          }
          if ( v686[4] )
          {
            v11->vfptr->getVertex((hkGeometryUtils::IVertices *)&v11->vfptr, v113, (hkVector4f *)&v655);
            v115 = v686;
            if ( v656 & 1 )
            {
              v526[2 * v114] = v82 + 1;
LABEL_137:
              ++v14;
            }
          }
          v116 = v526[2 * v114];
          if ( v116 != -1 )
            goto LABEL_506;
          if ( *(float *)&v115[40] < 3.40282e38 )
          {
            v11->vfptr->getVertex((hkGeometryUtils::IVertices *)&v11->vfptr, *(_DWORD *)v111, (hkVector4f *)&v644);
            v117 = _mm_sub_ps(v89, v88);
            v118 = _mm_max_ps(v117, aabbOut.m_quad);
            v119 = _mm_rcp_ps(v118);
            v663 = v118;
            v120 = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmpeqps((__m128)0i64, v118),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v119, v118)), v119)),
                     _mm_sub_ps(v644, v88));
            v121 = _mm_cmpltps(v120, query.m_quad);
            v122 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v121, query.m_quad), _mm_and_ps(v121, v120)));
            LODWORD(v123) = (unsigned __int128)_mm_shuffle_ps(v122, v122, 170);
            v121.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v122, v122, 85);
            v124 = (signed int)(float)((float)(v122.m128_f32[0] * 2047.0) + 0.5) | (((signed int)(float)((float)(v121.m128_f32[0] * 2047.0) + 0.5) | ((signed int)(float)((float)(v123 * 1023.0) + 0.5) << 11)) << 11);
            v125 = (__m128)COERCE_UNSIGNED_INT((float)(((unsigned __int16)(signed int)(float)((float)(v122.m128_f32[0] * 2047.0)
                                                                                            + 0.5) | (unsigned __int16)(((unsigned __int16)(signed int)(float)((float)(v121.m128_f32[0] * 2047.0) + 0.5) | (unsigned __int16)((unsigned __int16)(signed int)(float)((float)(v123 * 1023.0) + 0.5) << 11)) << 11)) & 0x7FF));
            v125.m128_f32[0] = v125.m128_f32[0] * 0.00048851978;
            v126 = (__m128)COERCE_UNSIGNED_INT((float)(v124 >> 22));
            v127 = (__m128)COERCE_UNSIGNED_INT((float)((v124 >> 11) & 0x7FF));
            v126.m128_f32[0] = v126.m128_f32[0] * 0.00097751711;
            v127.m128_f32[0] = v127.m128_f32[0] * 0.00048851978;
            v128 = _mm_sub_ps(
                     v644,
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_unpacklo_ps(_mm_unpacklo_ps(v125, v126), _mm_unpacklo_ps(v127, (__m128)0i64)),
                         v117),
                       v88));
            v129 = _mm_mul_ps(v128, v128);
            v130 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v129, v129, 85), _mm_shuffle_ps(v129, v129, 0)),
                     _mm_shuffle_ps(v129, v129, 170));
            v658 = v130;
            if ( (float)(COERCE_FLOAT(_mm_andnot_ps(_mm_cmpleps(v130, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v130))))
                       * v130.m128_f32[0]) > *(float *)&v686[40] )
            {
              ++v499;
              ++v14;
              v526[2 * v114] = v82 + 1;
            }
          }
          v116 = v526[2 * v114];
          if ( v116 != -1 )
          {
LABEL_506:
            if ( v116 != v82 )
            {
              --v14;
              ++v496;
              v526[2 * v114] = -2;
            }
          }
          else
          {
            ++v14;
            v526[2 * v114] = v82;
          }
          goto LABEL_146;
        }
LABEL_149:
        v101 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)v101 + 8);
        v517 = --v99;
        v507 = v101;
      }
      while ( v99 );
      v85 = (__m128 *)v512;
      v84 = v524;
LABEL_151:
      v80 = quads;
      v52 = v505;
      v84 += 24;
      v85 += 131;
      ++v82;
      v524 = v84;
      v512 = (signed __int64)v85;
      if ( v82 >= quads->m_size )
      {
        v62 = v622;
        v83 = FLOAT_2047_0;
        v81 = v499;
        break;
      }
    }
  }
  if ( *(_BYTE *)&v70[20] & 1 && v81 )
  {
    hkErrStream::hkErrStream(&v643, &buf, 512);
    v131 = hkOstream::operator<<((hkOstream *)&v643.vfptr, "Promoted ");
    v132 = hkOstream::operator<<(v131, v81, (int)v131);
    hkOstream::operator<<(v132, " vertices in order to comply with compression error constraint.");
    hkError::messageReport(0, &buf, 0i64, 0);
    hkOstream::~hkOstream((hkOstream *)&v643.vfptr);
  }
  v133 = quads;
  v500 = 0;
  if ( quads->m_size > 0 )
  {
    v134 = v599;
    v135 = (signed __int64)&v528[2];
    v136 = 0;
    v513 = (signed __int64)&v528[2];
    v137 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v138 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)*(signed int *)(v135 + 1024);
      v139 = (__m128)xmmword_141A712A0;
      v508 = v138;
      v140 = (char *)(*(_QWORD *)v134 + 96i64 * v136);
      v141 = _mm_xor_ps((__m128)xmmword_141A712A0, v137);
      v600 = (void *)(*(_QWORD *)v134 + 96i64 * v136);
      if ( (signed __int64)v138 > 0 )
      {
        v142 = (signed int *)v135;
        v143 = v511;
        do
        {
          if ( *v142 - v143 < 0 )
          {
            v536 = 0i64;
            v537 = 0i64;
            v144 = *v142;
            if ( (signed int)v144 < v527 )
            {
              v145 = mapping->m_triangleIndexToKey.m_data;
              v146 = v688;
              v147 = 3 * v144;
              v148 = mapping->m_triangleIndexToKey.m_data[3 * v144];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v688->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v688->m_size[2] + 8i64),
                v148 & 0x3FFFFFFF,
                &v550);
              v550 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v550);
              v551 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v551);
              v552 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v552);
              LODWORD(v536) = *(&v550 + (signed int)((v148 >> 30) + 1) % 3);
              v149 = v145[v147];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v146->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v146->m_size[2] + 8i64),
                v149 & 0x3FFFFFFF,
                &v574);
              v574 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v574);
              v575 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v575);
              v576 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v576);
              HIDWORD(v536) = *(&v574 + (signed int)((v149 >> 30) + 2) % 3);
              v150 = (signed int)((v145[v147 + 1] >> 30) + 1) % 3;
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v146->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v146->m_size[2] + 8i64),
                v145[v147 + 1] & 0x3FFFFFFF,
                &v553);
              v553 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v553);
              v554 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v554);
              v555 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v555);
              LODWORD(v537) = *(&v553 + v150);
              v151 = v145[v147 + 1];
              v11 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v688;
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v146->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v146->m_size[2] + 8i64),
                v151 & 0x3FFFFFFF,
                &v556);
              v556 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v556);
              v557 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v557);
              v138 = v508;
              v558 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v558);
              HIDWORD(v537) = *(&v556 + (signed int)((v151 >> 30) + 2) % 3);
            }
            else
            {
              v11->m_provider->m_meshCInfo->vfptr->getIndices(
                v11->m_provider->m_meshCInfo,
                v144 - mapping->m_triangleIndexToKey.m_size,
                (int *)&v536);
              LODWORD(v536) = v11->m_vMap.m_data[(signed int)v536];
              HIDWORD(v536) = v11->m_vMap.m_data[SHIDWORD(v536)];
              LODWORD(v537) = v11->m_vMap.m_data[(signed int)v537];
              HIDWORD(v537) = v537;
            }
            v56 = v526;
            v152 = &v536;
            v153 = 4i64;
            do
            {
              v154 = *(signed int *)v152;
              if ( v526[2 * v154] != -2 )
              {
                v11->vfptr->getVertex((hkGeometryUtils::IVertices *)&v11->vfptr, v154, (hkVector4f *)&v648);
                v139 = _mm_min_ps(v139, v648);
                v141 = _mm_max_ps(v141, v648);
              }
              v152 = (__int64 *)((char *)v152 + 4);
              --v153;
            }
            while ( v153 );
            v143 = v511;
          }
          v142 += 2;
          v138 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)v138 - 1);
          v508 = v138;
        }
        while ( v138 );
        v140 = (char *)v600;
        v135 = v513;
        v136 = v500;
        v133 = quads;
        v134 = v599;
      }
      *(__m128 *)(v135 - 32) = v139;
      *(__m128 *)(v135 - 16) = v141;
      v649 = v139;
      ++v136;
      v135 += 2096i64;
      v500 = v136;
      v513 = v135;
      v650 = _mm_mul_ps(
               _mm_sub_ps(v141, v139),
               (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
      *((__m128 *)v140 + 3) = v139;
      *(_QWORD *)(v140 + 60) = v650.m128_u64[0];
      *((_DWORD *)v140 + 17) = (unsigned __int128)_mm_movehl_ps(v650, v650);
    }
    while ( v136 < v133->m_size );
    v14 = v503;
    v53 = v496;
  }
  v155 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *)masterTree;
  v156 = v505;
  v157 = masterTree[2].m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
  v600 = &masterTree[2];
  if ( v157 >= v505 )
  {
    v624.m_enum = 0;
  }
  else
  {
    v158 = 2 * v157;
    if ( v505 < v158 )
      v156 = v158;
    hkArrayUtil::_reserve(&v624, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &masterTree[2], v156, 4);
  }
  v159 = 4 * v53;
  v160 = &masterTree[2].m_firstFree;
  v161 = masterTree[2].m_path & 0x3FFFFFFF;
  v614 = &masterTree[2].m_firstFree;
  if ( v161 >= v159 )
  {
    v613.m_enum = 0;
  }
  else
  {
    v162 = 2 * v161;
    if ( v159 < v162 )
      v159 = v162;
    hkArrayUtil::_reserve(
      &v613,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &masterTree[2].m_firstFree,
      v159,
      2);
  }
  v163 = v496;
  v164 = &masterTree[3].m_nodes.m_size;
  v165 = HIDWORD(masterTree[3].m_firstFree);
  v625 = &masterTree[3].m_nodes.m_size;
  v166 = v165 & 0x3FFFFFFF;
  if ( v166 >= v496 )
  {
    v621.m_enum = 0;
  }
  else
  {
    v167 = 2 * v166;
    if ( v496 < v167 )
      v163 = v167;
    hkArrayUtil::_reserve(
      &v621,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &masterTree[3].m_nodes.m_size,
      v163,
      8);
  }
  v168 = HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF;
  v525 = &masterTree[2].m_root;
  if ( v168 >= v14 )
  {
    v615.m_enum = 0;
  }
  else
  {
    v169 = 2 * v168;
    if ( v14 < v169 )
      v14 = v169;
    hkArrayUtil::_reserve(
      &v615,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &masterTree[2].m_root,
      v14,
      4);
  }
  v170 = FLOAT_4194303_0;
  v171 = 0;
  v501 = 0;
  v172 = FLOAT_2097151_0;
  if ( v133->m_size > 0 )
  {
    v173 = v528;
    v174 = v628;
    v175 = 0i64;
    v176 = 0i64;
    v177 = 0i64;
    v178 = -(signed __int64)v528;
    v522 = 0i64;
    v514 = 0i64;
    v602 = -(signed __int64)v528;
    v179 = v528;
    do
    {
      v180 = *(_QWORD *)v599;
      v636 = v176;
      v637 = v176;
      v636 = *(__m128 *)(v177 + v180 + 48);
      _mm_store_si128(
        (__m128i *)&v637,
        _mm_srli_si128(
          _mm_slli_si128(
            (__m128i)_mm_movelh_ps(
                       (__m128)*(unsigned __int64 *)(v177 + v180 + 60),
                       (__m128)*(unsigned int *)(v177 + v180 + 68)),
            4),
          4));
      v181 = v179[66].m128_i32[0];
      *(_BYTE *)(v177 + v180 + 88) = 0;
      v182 = (int)masterTree[3].m_nodes.m_data;
      *(_QWORD *)&v544[0].m_enum = v181;
      *(_DWORD *)(v177 + v180 + 72) = v182;
      if ( (signed int)v181 > 0 )
      {
        v183 = v178 - 1032;
        v184 = roots;
        v185 = &v179[66].m128_u64[1];
        v186 = (__int64)v173 + v183;
        v601 = (__int64)&v179[66].m128_i64[1];
        v604 = v186;
        do
        {
          v187 = (__m128 *)((char *)v184->m_data + 64 * *v185);
          v188 = *(_DWORD *)((char *)v185 + v186) - v511;
          v189 = *v187;
          v190 = v187[1];
          if ( v188 >= 0 )
          {
            *(_QWORD *)&v640.m_numVertices = 0i64;
            v640.m_layerData = 0;
            v640.m_tags.m_size = 0;
            v640.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
            v640.m_maxError = 3.40282e38;
            v640.m_compression = 1;
            v640.m_aabb.m_max.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         (__m128)xmmword_141A712A0);
            hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(v11->m_provider, v188, &v640);
            if ( v640.m_numVertices > 0 )
            {
              v234 = (__m128)_xmm;
              v235 = 0i64;
              v236 = (unsigned int)v640.m_numVertices;
              v237 = _mm_max_ps(v628, aabbOut.m_quad);
              v238 = v639;
              v239 = v638;
              v240 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
              v241 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
              do
              {
                v242 = _mm_rcp_ps(v237);
                v243 = 0i64;
                v244 = v11->m_provider->m_caches.m_data[v188]->m_vertices.m_data[v235].m_quad;
                v668 = v237;
                v245 = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpeqps((__m128)0i64, v237),
                           _mm_mul_ps(_mm_sub_ps(v234, _mm_mul_ps(v242, v237)), v242)),
                         _mm_sub_ps(v244, v622));
                v246 = _mm_cmpltps(v245, query.m_quad);
                v247 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v246, query.m_quad), _mm_and_ps(v246, v245)));
                v631 = v247;
                v248 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v247, v247, 170)) * 4194303.0) + 0.5;
                if ( v248 >= 9.223372e18 )
                {
                  v248 = v248 - 9.223372e18;
                  if ( v248 < 9.223372e18 )
                    v243 = 0x8000000000000000i64;
                }
                v249 = 0i64;
                v250 = (v243 + (unsigned int)(signed int)v248) << 21;
                v251 = (float)(v631.m128_f32[1] * 2097151.0) + 0.5;
                if ( v251 >= 9.223372e18 )
                {
                  v251 = v251 - 9.223372e18;
                  if ( v251 < 9.223372e18 )
                    v249 = 0x8000000000000000i64;
                }
                v252 = v249 + (unsigned int)(signed int)v251;
                v253 = (float)(v631.m128_f32[0] * 2097151.0) + 0.5;
                v254 = 0i64;
                v255 = (v252 | v250) << 21;
                if ( v253 >= 9.223372e18 )
                {
                  v253 = v253 - 9.223372e18;
                  if ( v253 < 9.223372e18 )
                    v254 = 0x8000000000000000i64;
                }
                ++v235;
                v542 = (v254 + (unsigned int)(signed int)v253) | v255;
                v256 = _mm_loadl_epi64((const __m128i *)&v542);
                _mm_store_si128((__m128i *)&v659, v256);
                v234 = (__m128)_xmm;
                v257 = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_cvtepi32_ps(
                             _mm_or_si128(
                               _mm_or_si128(
                                 _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v256, 0xAu), 85), v240),
                                 _mm_and_si128(
                                   v256,
                                   (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX)),
                               _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v256, 2), 5u), v241))),
                           v238),
                         v239);
                v189 = _mm_min_ps(v189, v257);
                v190 = _mm_max_ps(v190, v257);
                --v236;
              }
              while ( v236 );
              v172 = FLOAT_2097151_0;
              v170 = FLOAT_4194303_0;
              v62 = v622;
              v174 = v628;
              v56 = v526;
              v176 = 0i64;
            }
          }
          else
          {
            v532 = 0i64;
            v533 = 0i64;
            v191 = *(signed int *)((char *)v185 + v186);
            if ( (signed int)v191 < v527 )
            {
              v192 = mapping->m_triangleIndexToKey.m_data;
              v193 = v688;
              v194 = 3 * v191;
              v195 = mapping->m_triangleIndexToKey.m_data[3 * v191];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v688->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v688->m_size[2] + 8i64),
                v195 & 0x3FFFFFFF,
                &v559);
              v559 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v559);
              v560 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v560);
              v561 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v561);
              LODWORD(v532) = *(&v559 + (signed int)((v195 >> 30) + 1) % 3);
              v196 = v192[v194];
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v193->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v193->m_size[2] + 8i64),
                v196 & 0x3FFFFFFF,
                &v565);
              v565 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v565);
              v566 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v566);
              v567 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v567);
              HIDWORD(v532) = *(&v565 + (signed int)((v196 >> 30) + 2) % 3);
              v197 = (signed int)((v192[v194 + 1] >> 30) + 1) % 3;
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v193->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v193->m_size[2] + 8i64),
                v192[v194 + 1] & 0x3FFFFFFF,
                &v571);
              v571 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v571);
              v572 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v572);
              v573 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v573);
              LODWORD(v533) = *(&v571 + v197);
              v198 = v192[v194 + 1];
              v11 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v688;
              v199 = (signed int)((v198 >> 30) + 2) % 3;
              (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v193->m_size[2] + 8i64) + 32i64))(
                *(_QWORD *)(*(_QWORD *)&v193->m_size[2] + 8i64),
                v198 & 0x3FFFFFFF,
                &v577);
              v177 = v514;
              v577 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v577);
              v578 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v578);
              v579 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v579);
              HIDWORD(v533) = *(&v577 + v199);
            }
            else
            {
              v11->m_provider->m_meshCInfo->vfptr->getIndices(
                v11->m_provider->m_meshCInfo,
                v191 - mapping->m_triangleIndexToKey.m_size,
                (int *)&v532);
              LODWORD(v532) = v11->m_vMap.m_data[(signed int)v532];
              HIDWORD(v532) = v11->m_vMap.m_data[SHIDWORD(v532)];
              LODWORD(v533) = v11->m_vMap.m_data[(signed int)v533];
              HIDWORD(v533) = v533;
            }
            v56 = v526;
            v200 = 4i64;
            v201 = &v532;
            v518 = 4i64;
            do
            {
              v202 = *(signed int *)v201;
              v203 = v202;
              v204 = v526[2 * v202];
              if ( v204 == v501 )
              {
                if ( v526[2 * v202 + 1] == -1 )
                {
                  v526[2 * v202 + 1] = (unsigned __int8)(*(_BYTE *)(v177 + v180 + 88))++;
                  v11->vfptr->getVertex((hkGeometryUtils::IVertices *)&v11->vfptr, *(_DWORD *)v201, (hkVector4f *)&v653);
                  v205 = &masterTree[2].m_root;
                  if ( LODWORD(masterTree[3].m_nodes.m_data) == (HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v525, 4);
                    v205 = &masterTree[2].m_root;
                  }
                  v206 = *v205;
                  v207 = *((signed int *)v205 + 2);
                  *((_DWORD *)v205 + 2) = v207 + 1;
                  v208 = _mm_max_ps(_mm_sub_ps(v179[1], *v179), aabbOut.m_quad);
                  v209 = _mm_rcp_ps(v208);
                  v672 = v208;
                  v210 = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpeqps(v176, v208),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v208, v209)), v209)),
                           _mm_sub_ps(v653, *v179));
                  v211 = _mm_cmpltps(v210, query.m_quad);
                  v212 = _mm_max_ps(
                           aabbOut.m_quad,
                           _mm_or_ps(_mm_andnot_ps(v211, query.m_quad), _mm_and_ps(v210, v211)));
                  *(_DWORD *)(v206 + 4 * v207) = (signed int)(float)((float)(v212.m128_f32[0] * v83) + 0.5) | (((signed int)(float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v212, v212, 85)) * v83) + 0.5) | ((signed int)(float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v212, v212, 170)) * 1023.0) + 0.5) << 11)) << 11);
                  v177 = v514;
                  v200 = v518;
                }
                else
                {
                  v205 = &masterTree[2].m_root;
                }
                v213 = (__m128i)*(unsigned int *)(*v205 + 4i64 * (*(_DWORD *)(v177 + v180 + 72) + v526[2 * v203 + 1]));
                _mm_store_si128((__m128i *)&v665, v213);
                v214 = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_cvtepi32_ps(
                             _mm_or_si128(
                               _mm_or_si128(
                                 _mm_and_si128(
                                   _mm_shuffle_epi32(_mm_srli_epi32(v213, 0x16u), 0),
                                   (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ),
                                 _mm_and_si128(
                                   v213,
                                   (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX)),
                               _mm_and_si128(
                                 _mm_shuffle_epi32(_mm_srli_epi32(v213, 0xBu), 0),
                                 (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY))),
                           v637),
                         v636);
                v189 = _mm_min_ps(v189, v214);
                v190 = _mm_max_ps(v190, v214);
              }
              else
              {
                if ( v204 == -2 )
                {
                  v11->vfptr->getVertex((hkGeometryUtils::IVertices *)&v11->vfptr, v202, (hkVector4f *)&v642);
                  v215 = 0i64;
                  v671 = _mm_max_ps(v174, aabbOut.m_quad);
                  v216 = _mm_rcp_ps(v671);
                  v217 = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpeqps(v176, v671),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v216, v671)), v216)),
                           _mm_sub_ps(v642, v62));
                  v218 = _mm_cmpltps(v217, query.m_quad);
                  v219 = _mm_max_ps(
                           aabbOut.m_quad,
                           _mm_or_ps(_mm_andnot_ps(v218, query.m_quad), _mm_and_ps(v218, v217)));
                  *(__m128 *)out = v219;
                  v220 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v219, v219, 170)) * v170) + 0.5;
                  if ( v220 >= 9.223372e18 )
                  {
                    v220 = v220 - 9.223372e18;
                    if ( v220 < 9.223372e18 )
                      v215 = 0x8000000000000000i64;
                  }
                  v221 = 0i64;
                  v222 = (float)(*((float *)out + 1) * v172) + 0.5;
                  v223 = (v215 + (unsigned int)(signed int)v220) << 21;
                  if ( v222 >= 9.223372e18 )
                  {
                    v222 = v222 - 9.223372e18;
                    if ( v222 < 9.223372e18 )
                      v221 = 0x8000000000000000i64;
                  }
                  v224 = v221 + (unsigned int)(signed int)v222;
                  v225 = (float)(*(float *)out * v172) + 0.5;
                  v226 = 0i64;
                  v227 = (v224 | v223) << 21;
                  if ( v225 >= 9.223372e18 )
                  {
                    v225 = v225 - 9.223372e18;
                    if ( v225 < 9.223372e18 )
                      v226 = 0x8000000000000000i64;
                  }
                  v542 = (v226 + (unsigned int)(signed int)v225) | v227;
                  v228 = _mm_loadl_epi64((const __m128i *)&v542);
                  _mm_store_si128((__m128i *)&v667, v228);
                  v229 = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(
                                     _mm_shuffle_epi32(_mm_srli_epi32(v228, 0xAu), 85),
                                     (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ),
                                   _mm_and_si128(
                                     v228,
                                     (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX)),
                                 _mm_and_si128(
                                   _mm_srli_epi32(_mm_slli_si128(v228, 2), 5u),
                                   (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY))),
                             v639),
                           v638);
                  v189 = _mm_min_ps(v189, v229);
                  v190 = _mm_max_ps(v190, v229);
                }
                else
                {
                  v509 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)array + (_QWORD)v522);
                  if ( (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)array + (_QWORD)v522),
                                     *(signed int *)v201) > v509->m_hashMod )
                  {
                    v11->vfptr->getVertex(
                      (hkGeometryUtils::IVertices *)&v11->vfptr,
                      *(_DWORD *)v201,
                      (hkVector4f *)&v654);
                    v230 = (unsigned __int8)(*(_BYTE *)(v177 + v180 + 88))++;
                    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                      v509,
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      *(signed int *)v201,
                      v230);
                    v231 = &masterTree[2].m_root;
                    if ( LODWORD(masterTree[3].m_nodes.m_data) == (HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v525, 4);
                      v231 = &masterTree[2].m_root;
                    }
                    v232 = *v231;
                    v233 = *((signed int *)v231 + 2);
                    *((_DWORD *)v231 + 2) = v233 + 1;
                    *(_DWORD *)(v232 + 4 * v233) = *(_DWORD *)v201;
                    v189 = _mm_min_ps(v189, v654);
                    v190 = _mm_max_ps(v190, v654);
                  }
                  v526[2 * v203 + 1] = 0;
                }
                v200 = v518;
              }
              v201 = (__int64 *)((char *)v201 + 4);
              v518 = --v200;
            }
            while ( v200 );
          }
          v258 = v601;
          v184 = roots;
          v259 = _mm_min_ps(v190, v626);
          v260 = _mm_max_ps(v189, v62);
          v261 = (__m128 *)((char *)roots->m_data + 64 * *(_QWORD *)v601);
          *v261 = v260;
          v261[1] = v259;
          for ( l = v261[2].m128_u64[0]; l; l = v263[2].m128_u64[0] )
          {
            v263 = (__m128 *)((char *)roots->m_data + 64 * l);
            v264 = v263[1];
            if ( !(_mm_movemask_ps(_mm_or_ps(_mm_cmpltps(v263[1], v259), _mm_cmpltps(v260, *v263))) & 7) )
              break;
            *v263 = _mm_min_ps(*v263, v260);
            v263[1] = _mm_max_ps(v264, v259);
          }
          v83 = FLOAT_2047_0;
          v186 = v604;
          v185 = (unsigned __int64 *)(v258 + 8);
          v265 = (*(_QWORD *)&v544[0].m_enum)-- == 1i64;
          v601 = (__int64)v185;
        }
        while ( !v265 );
        v171 = v501;
        v175 = v522;
        v178 = v602;
        v173 = v528;
        v133 = quads;
      }
      v83 = FLOAT_2047_0;
      ++v171;
      v177 += 96i64;
      v175 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)((char *)v175 + 16);
      v179 += 131;
      v501 = v171;
      v514 = v177;
      v522 = v175;
    }
    while ( v171 < v133->m_size );
    v160 = v614;
    v164 = v625;
    v155 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *)masterTree;
  }
  v676 = 0;
  v674 = 0;
  v681 = 0;
  v684 = 0;
  v679 = 0;
  v549 = 131584;
  v266 = (_WORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                    &v549);
  v267 = 2147483648;
  v268 = v266;
  v519 = v266;
  if ( v549 / 2 )
    v267 = v549 / 2;
  LODWORD(v601) = v267;
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree::DynamicTree(&dTree);
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
    (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)&dTree.m_nodes,
    v544,
    256);
  v269 = quads;
  v270 = 0i64;
  v271 = 0i64;
  v540 = 0;
  v504 = 0;
  v272 = 0;
  v502 = 0;
  v510 = 0i64;
  if ( quads->m_size > 0 )
  {
    while ( 1 )
    {
      v273 = 3 * v271;
      v274 = v528[131 * v271 + 66].m128_i32[0];
      *(float *)&v614 = v155[1].m_domain.m_max.m_quad.m128_f32[2];
      v275 = *(_QWORD *)v269->m_data[2 * v271].m_edges;
      v506 = v274;
      v276 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)(v155[1].m_domain.m_min.m_quad.m128_u64[0]
                                                                     + 32 * v273);
      v516 = v155[2].m_nodes.m_size;
      v523 = v276;
      *(float *)&v602 = v155[2].m_domain.m_max.m_quad.m128_f32[2];
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::detachBranch(
        (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)roots,
        v275,
        v272,
        (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&dTree.m_nodes);
      v277 = dTree.m_root;
      v278 = 0;
      if ( dTree.m_root )
      {
        v279 = dTree.m_nodes.m_data;
        if ( LODWORD(dTree.m_nodes.m_data[dTree.m_root].m_children[0]) )
        {
          v280 = dTree.m_nodes.m_data[dTree.m_root].m_children[0];
          while ( v280 )
          {
            if ( LODWORD(v279[v280].m_children[0])
              || (v281 = v278,
                  ++v278,
                  v279[v280].m_children[1] = v281,
                  v279 = dTree.m_nodes.m_data,
                  LODWORD(dTree.m_nodes.m_data[v280].m_children[0])) )
            {
              v280 = v279[v280].m_children[0];
            }
            else
            {
              v282 = dTree.m_nodes.m_data[v280].m_parent;
              for ( m = v280; v282 != v277; v282 = dTree.m_nodes.m_data[v282].m_parent )
              {
                if ( dTree.m_nodes.m_data[v282].m_children[1] != m )
                  break;
                m = v282;
              }
              if ( v282 )
                v280 = dTree.m_nodes.m_data[v282].m_children[1];
              else
                v280 = m;
              if ( v282 == v277 && v280 == m )
                v280 = 0i64;
            }
          }
        }
        else
        {
          dTree.m_nodes.m_data[dTree.m_root].m_children[1] = 0i64;
        }
      }
      hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::convertFromDynamicTree<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree>(
        v276,
        &dTree);
      v284 = masterTree;
      LOBYTE(v285) = v516;
      v286 = v506;
      v287 = v504;
      v544[0] = (hkResult)masterTree[2].m_numLeaves;
      v543 = 0;
      v288 = v516 << 8;
      LODWORD(v625) = (unsigned __int8)v506;
      LODWORD(v604) = v516 << 8;
      do
      {
        v289 = v523;
        v290 = v268;
        for ( n = 65792i64; n; --n )
        {
          *v290 = -1;
          ++v290;
        }
        v523[1].m_domain.m_min.m_quad.m128_i32[3] &= 0xFFu;
        v523[1].m_domain.m_min.m_quad.m128_i32[3] |= v288;
        v292 = (unsigned __int8)v523[1].m_domain.m_max.m_quad.m128_i8[8];
        v293 = v523[1].m_domain.m_min.m_quad.m128_f32[3];
        v681 = v286;
        v523[1].m_domain.m_min.m_quad.m128_i32[3] = v292 | LODWORD(v293) & 0xFFFFFF00;
        v294 = (signed int)v625;
        v523[1].m_domain.m_max.m_quad.m128_i32[0] = (v284[2].m_nodes.m_size << 8) | (unsigned __int8)v523[1].m_domain.m_max.m_quad.m128_i8[0];
        v523[1].m_domain.m_max.m_quad.m128_i32[0] &= 0xFFFFFF00;
        v523[1].m_domain.m_max.m_quad.m128_i32[0] |= v294;
        LOBYTE(v294) = v540;
        v523[1].m_domain.m_max.m_quad.m128_i32[1] = (LODWORD(v284[3].m_root) << 8) | (unsigned __int8)v523[1].m_domain.m_max.m_quad.m128_i8[4];
        v523[1].m_domain.m_max.m_quad.m128_i8[4] = 0;
        v523[1].m_domain.m_max.m_quad.m128_i8[12] = v294;
        v523[1].m_domain.m_max.m_quad.m128_i8[9] = 0;
        v523[1].m_domain.m_max.m_quad.m128_i8[13] = 0;
        v523[1].m_domain.m_max.m_quad.m128_i8[14] = LOBYTE(quads->m_data[2 * (_QWORD)v510].m_value);
        v674 = v286;
        v676 = v286;
        v684 = v286;
        v295 = 0;
        v541 = 0;
        v296 = 0i64;
        v515 = 0i64;
        if ( v286 > 0 )
        {
          v631.m128_u64[0] = 262i64 * (_QWORD)v510;
          while ( 1 )
          {
            v297 = (signed __int64)&v284[2];
            pArr[v296] = v295;
            if ( v284[2].m_nodes.m_size == (v284[2].m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v284[2], 4);
              v289 = v523;
              v295 = v541;
              v284 = masterTree;
              LOBYTE(v285) = v516;
            }
            v298 = *(signed int *)(v297 + 8);
            v299 = (_BYTE *)(*(_QWORD *)v297 + 4 * v298);
            *(_DWORD *)(v297 + 8) = v298 + 1;
            primitiveIndex = v528[2].m128_i32[2 * (v296 + v631.m128_u64[0])] - v511;
            if ( primitiveIndex < 0 )
              break;
            v300 = v289->m_nodes.m_size;
            v301 = 0;
            v302 = 0i64;
            if ( v300 <= 0 )
            {
LABEL_284:
              v301 = -1;
            }
            else
            {
              v303 = &v289->m_nodes.m_data->m_data;
              while ( *v303 & 1 || v295 != (unsigned int)(unsigned __int8)*v303 >> 1 )
              {
                ++v302;
                ++v301;
                v303 += 4;
                if ( v302 >= v300 )
                  goto LABEL_284;
              }
            }
            v497 = v284[3].m_firstFree;
            v304 = LOBYTE(v284[2].m_numLeaves) + v289[1].m_domain.m_max.m_quad.m128_i8[8] - v285;
            hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(v289, v301, &aabb);
            v598.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
            *(_QWORD *)&v598.m_numVertices = 0i64;
            v598.m_layerData = 0;
            v598.m_tags.m_size = 0;
            v598.m_maxError = 3.40282e38;
            v598.m_compression = 1;
            v598.m_aabb.m_max.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         (__m128)xmmword_141A712A0);
            hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(
              v11->m_provider,
              primitiveIndex,
              &v598);
            v306 = (__m128)LODWORD(v598.m_maxError);
            v307.m_quad = (__m128)aabb.m_max;
            v308.m_quad = (__m128)aabb.m_min;
            *v299 = v304;
            v299[1] = v301;
            v299[2] = v301;
            LODWORD(v309) = (unsigned __int128)_mm_shuffle_ps(v306, v306, 0);
            v299[3] = v301;
            v310 = v598.m_compression;
            if ( (unsigned int)(v598.m_compression - 2) > 1 )
            {
              v330 = v497;
            }
            else
            {
              v651 = v308.m_quad;
              v311 = _mm_sub_ps(v307.m_quad, v308.m_quad);
              v312 = (unsigned __int64)(2i64 * (v598.m_numVertices + 1)) >> 3;
              v652 = _mm_mul_ps(
                       v311,
                       (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters::`2::invBitScalesBuffer);
              v313 = v164[2];
              v314 = v313 + v312;
              v315 = v164[3] & 0x3FFFFFFF;
              if ( v315 >= (signed int)v313 + (signed int)v312 )
              {
                v605.m_enum = 0;
              }
              else
              {
                v316 = 2 * v315;
                if ( v314 < v316 )
                  v314 = v316;
                hkArrayUtil::_reserve(
                  &v605,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  v164,
                  v314,
                  8);
              }
              v164[2] += v312;
              v305 = *(_QWORD *)v164 + 8 * v313;
              v317 = 0;
              if ( v598.m_numVertices <= 0 )
              {
LABEL_296:
                v330 = v497;
                v310 = 2;
                v598.m_compression = 2;
                goto LABEL_341;
              }
              v318 = 0i64;
              while ( 1 )
              {
                v319 = _mm_max_ps(v311, aabbOut.m_quad);
                v320 = _mm_rcp_ps(v319);
                v321 = v11->m_provider->m_caches.m_data[primitiveIndex]->m_vertices.m_data[v318].m_quad;
                v660 = v319;
                v322 = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpeqps((__m128)0i64, v319),
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v319, v320)), v320)),
                         _mm_sub_ps(v321, v308.m_quad));
                v323 = _mm_cmpltps(v322, query.m_quad);
                v324 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v323, query.m_quad), _mm_and_ps(v323, v322)));
                v325 = (signed int)(float)((float)(v324.m128_f32[0] * 31.0) + 0.5) | 32
                                                                                   * ((signed int)(float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v324, v324, 85)) * 31.0) + 0.5) | 32 * (signed int)(float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v324, v324, 170)) * 63.0) + 0.5));
                *(_WORD *)v305 = v325;
                if ( v598.m_compression == 3 )
                {
                  v326 = _mm_sub_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_unpacklo_epi32(
                                   _mm_unpacklo_epi32(
                                     _mm_cvtsi32_si128(v325 & 0x1F),
                                     _mm_cvtsi32_si128((unsigned int)v325 >> 10)),
                                   _mm_unpacklo_epi32(
                                     _mm_cvtsi32_si128(((unsigned int)v325 >> 5) & 0x1F),
                                     _mm_cvtsi32_si128(0)))),
                               v652),
                             v651),
                           v321);
                  v327 = _mm_mul_ps(v326, v326);
                  v328 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v327, v327, 85), _mm_shuffle_ps(v327, v327, 0)),
                           _mm_shuffle_ps(v327, v327, 170));
                  v329 = _mm_rsqrt_ps(v328);
                  v662 = v328;
                  if ( COERCE_FLOAT(
                         _mm_andnot_ps(
                           _mm_cmpleps(v328, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v329, v328), v329)),
                               _mm_mul_ps(*(__m128 *)_xmm, v329)),
                             v328))) > v309 )
                    break;
                }
                ++v317;
                ++v318;
                v305 += 2i64;
                if ( v317 >= v598.m_numVertices )
                  goto LABEL_296;
              }
              v330 = v497;
              v331 = v164[3] & 0x3FFFFFFF;
              if ( v331 >= v497 )
              {
                v610.m_enum = 0;
                v164[2] = v497;
                v310 = v598.m_compression;
              }
              else
              {
                v332 = 2 * v331;
                v333 = v497;
                if ( v497 < v332 )
                  v333 = v332;
                hkArrayUtil::_reserve(
                  &v610,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  v164,
                  v333,
                  8);
                v164[2] = v497;
                v310 = v598.m_compression;
              }
            }
            if ( !((v310 - 1) & 0xFFFFFFFD) )
            {
              v645 = v308.m_quad;
              v334 = _mm_sub_ps(v307.m_quad, v308.m_quad);
              v335 = (unsigned __int64)(4i64 * (v598.m_numVertices + 1)) >> 3;
              v646 = _mm_mul_ps(
                       v334,
                       (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
              v336 = v164[2];
              v337 = v336 + v335;
              v338 = v164[3] & 0x3FFFFFFF;
              if ( v338 >= (signed int)v336 + (signed int)v335 )
              {
                v606.m_enum = 0;
              }
              else
              {
                v339 = 2 * v338;
                if ( v337 < v339 )
                  v337 = v339;
                hkArrayUtil::_reserve(
                  &v606,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  v164,
                  v337,
                  8);
              }
              v164[2] += v335;
              v305 = *(_QWORD *)v164 + 8 * v336;
              v340 = 0;
              if ( v598.m_numVertices <= 0 )
              {
LABEL_314:
                v330 = v497;
                v310 = 1;
                v598.m_compression = 1;
                goto LABEL_341;
              }
              v341 = 0i64;
              v342 = (int *)(*(_QWORD *)v164 + 8 * v336);
              while ( 1 )
              {
                v343 = _mm_max_ps(v334, aabbOut.m_quad);
                v344 = _mm_rcp_ps(v343);
                v345 = v11->m_provider->m_caches.m_data[primitiveIndex]->m_vertices.m_data[v341].m_quad;
                v664 = v343;
                v346 = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpeqps((__m128)0i64, v343),
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v344, v343)), v344)),
                         _mm_sub_ps(v345, v308.m_quad));
                v347 = _mm_cmpltps(v346, query.m_quad);
                v348 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v347, query.m_quad), _mm_and_ps(v347, v346)));
                *v342 = (signed int)(float)((float)(v348.m128_f32[0] * 2047.0) + 0.5) | (((signed int)(float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v348, v348, 85)) * 2047.0) + 0.5) | ((signed int)(float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v348, v348, 170)) * 1023.0) + 0.5) << 11)) << 11);
                if ( v598.m_compression == 3 )
                {
                  v349 = (__m128i)*(unsigned int *)(v305 + 4i64 * v340);
                  _mm_store_si128((__m128i *)&v666, v349);
                  v350 = _mm_sub_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(
                                       _mm_shuffle_epi32(_mm_srli_epi32(v349, 0x16u), 0),
                                       (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ),
                                     _mm_and_si128(
                                       v349,
                                       (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX)),
                                   _mm_and_si128(
                                     _mm_shuffle_epi32(_mm_srli_epi32(v349, 0xBu), 0),
                                     (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY))),
                               v646),
                             v645),
                           v345);
                  v351 = _mm_mul_ps(v350, v350);
                  v352 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v351, v351, 85), _mm_shuffle_ps(v351, v351, 0)),
                           _mm_shuffle_ps(v351, v351, 170));
                  v353 = _mm_rsqrt_ps(v352);
                  v669 = v352;
                  if ( COERCE_FLOAT(
                         _mm_andnot_ps(
                           _mm_cmpleps(v352, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v353, v352), v353)),
                               _mm_mul_ps(*(__m128 *)_xmm, v353)),
                             v352))) > v309 )
                    break;
                }
                ++v340;
                ++v341;
                ++v342;
                if ( v340 >= v598.m_numVertices )
                  goto LABEL_314;
              }
              v330 = v497;
              v354 = v164[3] & 0x3FFFFFFF;
              if ( v354 >= v497 )
              {
                v619.m_enum = 0;
                v164[2] = v497;
                v310 = v598.m_compression;
              }
              else
              {
                v355 = 2 * v354;
                v356 = v497;
                if ( v497 < v355 )
                  v356 = v355;
                hkArrayUtil::_reserve(
                  &v619,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  v164,
                  v356,
                  8);
                v164[2] = v497;
                v310 = v598.m_compression;
              }
            }
            if ( v310 == CM_GLOBAL || v310 == 3 )
            {
              v357 = v598.m_numVertices;
              v358 = v164[2];
              v305 = (unsigned int)(v358 + v598.m_numVertices);
              v359 = v164[3] & 0x3FFFFFFF;
              if ( v359 >= (signed int)v305 )
              {
                v612.m_enum = 0;
              }
              else
              {
                v360 = 2 * v359;
                if ( (signed int)v305 < v360 )
                  LODWORD(v305) = v360;
                hkArrayUtil::_reserve(
                  &v612,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  v164,
                  v305,
                  8);
              }
              v164[2] += v357;
              v361 = *(_QWORD *)v164 + 8 * v358;
              v362 = 0;
              if ( v598.m_numVertices > 0 )
              {
                v305 = 0i64;
                do
                {
                  v363 = _mm_max_ps(v628, aabbOut.m_quad);
                  v364 = _mm_rcp_ps(v363);
                  v365 = 0i64;
                  v366 = *(__m128 *)((char *)&v11->m_provider->m_caches.m_data[primitiveIndex]->m_vertices.m_data->m_quad
                                   + v305);
                  v661 = v363;
                  v367 = _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpeqps((__m128)0i64, v363),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v363, v364)), v364)),
                           _mm_sub_ps(v366, v622));
                  v368 = _mm_cmpltps(v367, query.m_quad);
                  v369 = _mm_max_ps(
                           aabbOut.m_quad,
                           _mm_or_ps(_mm_and_ps(v367, v368), _mm_andnot_ps(v368, query.m_quad)));
                  v629 = v369;
                  v370 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v369, v369, 170)) * v170) + 0.5;
                  if ( v370 >= 9.223372e18 )
                  {
                    v370 = v370 - 9.223372e18;
                    if ( v370 < 9.223372e18 )
                      v365 = 0x8000000000000000i64;
                  }
                  v371 = 0i64;
                  v372 = (float)(v629.m128_f32[1] * v172) + 0.5;
                  v373 = (v365 + (unsigned int)(signed int)v370) << 21;
                  if ( v372 >= 9.223372e18 )
                  {
                    v372 = v372 - 9.223372e18;
                    if ( v372 < 9.223372e18 )
                      v371 = 0x8000000000000000i64;
                  }
                  v374 = v371 + (unsigned int)(signed int)v372;
                  v375 = (float)(v629.m128_f32[0] * v172) + 0.5;
                  v376 = 0i64;
                  v377 = (v374 | v373) << 21;
                  if ( v375 >= 9.223372e18 )
                  {
                    v375 = v375 - 9.223372e18;
                    if ( v375 < 9.223372e18 )
                      v376 = 0x8000000000000000i64;
                  }
                  ++v362;
                  v361 += 8i64;
                  v305 += 16i64;
                  *(_QWORD *)(v361 - 8) = (v376 + (unsigned int)(signed int)v375) | v377;
                }
                while ( v362 < v598.m_numVertices );
                v56 = v526;
              }
              v330 = v497;
              v310 = 0;
              v598.m_compression = 0;
            }
LABEL_341:
            v378 = masterTree;
            v379 = LODWORD(masterTree[3].m_firstFree) - v330;
            if ( v310 == 1 )
            {
              v383 = *(_QWORD *)v164 + 8i64 * v330;
              v384 = 0i64;
              if ( v379 <= 0 )
                goto LABEL_350;
              do
              {
                v385 = *(_QWORD *)(v383 + 8 * v384++);
                v633 = v385;
                v608 = __PAIR__(v385, HIDWORD(v385));
                *(_QWORD *)(v383 + 8 * v384 - 8) = __PAIR__(v385, HIDWORD(v385));
              }
              while ( v384 < v379 );
            }
            else
            {
              if ( v310 != 2 )
                goto LABEL_349;
              v380 = *(_QWORD *)v164 + 8i64 * v330;
              v381 = 0i64;
              if ( v379 <= 0 )
                goto LABEL_350;
              do
              {
                v382 = *(_QWORD *)(v380 + 8 * v381++);
                v603 = v382;
                HIWORD(v545) = v382;
                WORD2(v545) = WORD1(v603);
                LOWORD(v545) = HIWORD(v382);
                WORD1(v545) = WORD2(v382);
                *(_QWORD *)(v380 + 8 * v381 - 8) = v545;
              }
              while ( v381 < v379 );
            }
            v310 = v598.m_compression;
LABEL_349:
            if ( (unsigned int)(v310 - 1) <= 1 )
            {
LABEL_350:
              v523[1].m_domain.m_max.m_quad.m128_i8[13] |= 1u;
              v310 = v598.m_compression;
            }
            v386 = v687;
            *((_DWORD *)&v386->m_vrp + (signed int)v310) += v598.m_numVertices;
            *((_DWORD *)&v386->m_globalOptimizations.m_bool + (signed int)v598.m_compression) += 8
                                                                                               * (LODWORD(masterTree[3].m_firstFree)
                                                                                                - v330);
            *(_DWORD *)&v386->m_weldVertices.m_bool += v598.m_tags.m_size;
            v387 = v598.m_customType & 0xF | 16
                                           * (v598.m_compression & 3 | 4
                                                                     * (4 * LOWORD(v598.m_numVertices) | v598.m_tags.m_size & 3));
            if ( *((_DWORD *)v160 + 2) == (*((_DWORD *)v160 + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v160, 2);
            *(_WORD *)(*v160 + 2i64 * (signed int)(*((_DWORD *)v160 + 2))++) = v387;
            if ( *((_DWORD *)v160 + 2) == (*((_DWORD *)v160 + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v160, 2);
            v388 = v504;
            *(_WORD *)(*v160 + 2i64 * (signed int)(*((_DWORD *)v160 + 2))++) = v504;
            v389 = 0;
            if ( v598.m_tags.m_size > 0 )
            {
              v390 = &v598.m_tags;
              do
              {
                if ( *((_DWORD *)v160 + 2) == (*((_DWORD *)v160 + 3) & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v160, 2);
                v388 = *((signed int *)v160 + 2);
                *(_WORD *)(*v160 + 2 * v388) = v390->m_data[0];
                ++*((_DWORD *)v160 + 2);
                ++v389;
                v390 = (hkFixedInplaceArray<unsigned short,3> *)((char *)v390 + 2);
              }
              while ( v389 < v598.m_tags.m_size );
            }
            v287 = LODWORD(masterTree[3].m_firstFree) - v497 + v504;
            v504 += LODWORD(masterTree[3].m_firstFree) - v497;
            *(&v682 + 2 * v515) = -1 - primitiveIndex;
            v683[2 * v515] = 0;
            v391 = v11->m_provider;
            v392 = ((signed int (__fastcall *)(hkpBvCompressedMeshShapeCinfo *, __int64, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *, signed __int64))v391->m_meshCInfo->vfptr->getNumTriangles)(
                     v391->m_meshCInfo,
                     v388,
                     v378,
                     v305);
            v393 = v391->m_primitiveData;
            v394 = v515;
            *((_DWORD *)&cmpLess.m_data + v515) = v393->m_data[primitiveIndex + v392].m_data;
LABEL_391:
            if ( v287 > 0x10000 )
              goto LABEL_394;
            v62 = v622;
            v284 = masterTree;
            LOBYTE(v285) = v516;
            v295 = v541 + 1;
            v296 = v394 + 1;
            v541 = v295;
            v515 = v296;
            if ( v295 >= v506 )
              goto LABEL_393;
            v289 = v523;
          }
          v534 = 0i64;
          v535 = 0i64;
          v395 = v528[2].m128_i32[2 * (v296 + v631.m128_u64[0])];
          if ( (signed int)v395 < v527 )
          {
            v397 = mapping->m_triangleIndexToKey.m_data;
            v398 = 3 * v395;
            v399 = mapping->m_triangleIndexToKey.m_data[3 * v395];
            v548 = mapping->m_triangleIndexToKey.m_data[3 * v395 + 1] & 0x3FFFFFFF;
            primitiveIndexa = v399 & 0x3FFFFFFF;
            v400 = (signed int)((v399 >> 30) + 1) % 3;
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v688->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v688->m_size[2] + 8i64),
              v399 & 0x3FFFFFFF,
              &v583);
            v583 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v583);
            v584 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v584);
            v585 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v585);
            LODWORD(v534) = *(&v583 + v400);
            v401 = v397[v398];
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v688->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v688->m_size[2] + 8i64),
              v401 & 0x3FFFFFFF,
              &v589);
            v589 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v589);
            v590 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v590);
            v591 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v591);
            HIDWORD(v534) = *(&v589 + (signed int)((v401 >> 30) + 2) % 3);
            v402 = (signed int)((v397[v398 + 1] >> 30) + 1) % 3;
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v688->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v688->m_size[2] + 8i64),
              v397[v398 + 1] & 0x3FFFFFFF,
              &v595);
            v595 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v595);
            v596 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v596);
            v597 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v597);
            LODWORD(v535) = *(&v595 + v402);
            v403 = v397[v398 + 1];
            v11 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v688;
            (*(void (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(*(_QWORD *)&v688->m_size[2] + 8i64) + 32i64))(
              *(_QWORD *)(*(_QWORD *)&v688->m_size[2] + 8i64),
              v403 & 0x3FFFFFFF,
              &v586);
            v586 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v586);
            v587 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v587);
            v588 = *(_DWORD *)(*(_QWORD *)&v688->m_count[1] + 4i64 * v588);
            HIDWORD(v535) = *(&v586 + (signed int)((v403 >> 30) + 2) % 3);
          }
          else
          {
            v396 = (unsigned int)(v395 - mapping->m_triangleIndexToKey.m_size);
            v548 = -1;
            primitiveIndexa = v396;
            ((void (__fastcall *)(hkpBvCompressedMeshShapeCinfo *, __int64, __int64 *, hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *))v11->m_provider->m_meshCInfo->vfptr->getIndices)(
              v11->m_provider->m_meshCInfo,
              v396,
              &v534,
              v289);
            LODWORD(v534) = v11->m_vMap.m_data[(signed int)v534];
            HIDWORD(v534) = v11->m_vMap.m_data[SHIDWORD(v534)];
            LODWORD(v535) = v11->m_vMap.m_data[(signed int)v535];
            HIDWORD(v535) = v535;
          }
          v56 = v526;
          v404 = &v534;
          v542 = 4i64;
          while ( 1 )
          {
            v405 = *(signed int *)v404;
            if ( v526[2 * v405 + 1] < 0 )
            {
              v526[2 * v405 + 1] = v504++;
              v11->vfptr->getVertex((hkGeometryUtils::IVertices *)&v11->vfptr, *(_DWORD *)v404, (hkVector4f *)&v647);
              if ( v164[2] == (v164[3] & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v164, 8);
              v406 = v164[2];
              v407 = *(_QWORD *)v164;
              v408 = v628;
              v409 = v406;
              v164[2] = v406 + 1;
              v410 = 0i64;
              v411 = _mm_max_ps(v408, aabbOut.m_quad);
              v412 = _mm_rcp_ps(v411);
              v670 = v411;
              v413 = _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmpeqps(v411, (__m128)0i64),
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v412, v411)), v412)),
                       _mm_sub_ps(v647, v62));
              v414 = _mm_cmpltps(v413, query.m_quad);
              v415 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v414, query.m_quad), _mm_and_ps(v414, v413)));
              v626 = v415;
              v416 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v415, v415, 170)) * v170) + 0.5;
              if ( v416 >= 9.223372e18 )
              {
                v416 = v416 - 9.223372e18;
                if ( v416 < 9.223372e18 )
                  v410 = 0x8000000000000000i64;
              }
              v417 = 0i64;
              v418 = (float)(v626.m128_f32[1] * v172) + 0.5;
              v419 = (v410 + (unsigned int)(signed int)v416) << 21;
              if ( v418 >= 9.223372e18 )
              {
                v418 = v418 - 9.223372e18;
                if ( v418 < 9.223372e18 )
                  v417 = 0x8000000000000000i64;
              }
              v420 = v417 + (unsigned int)(signed int)v418;
              v421 = (float)(v626.m128_f32[0] * v172) + 0.5;
              v422 = 0i64;
              v423 = (v420 | v419) << 21;
              if ( v421 >= 9.223372e18 )
              {
                v421 = v421 - 9.223372e18;
                if ( v421 < 9.223372e18 )
                  v422 = 0x8000000000000000i64;
              }
              *(_QWORD *)(v407 + 8 * v409) = (v422 + (unsigned int)(signed int)v421) | v423;
            }
            v424 = v526[2 * v405];
            if ( v424 == -2 )
              break;
            if ( v424 == -1 )
            {
              v428 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
                       &array[v502],
                       &v634,
                       *(signed int *)v404,
                       out);
              v427 = 0;
              if ( v428->m_enum == HK_SUCCESS )
                v427 = out[0];
              goto LABEL_388;
            }
            *v299 = v526[2 * v405 + 1];
LABEL_389:
            v404 = (__int64 *)((char *)v404 + 4);
            ++v299;
            if ( !--v542 )
            {
              v394 = v515;
              v429 = v548;
              v287 = v504;
              *(&v682 + 2 * v515) = primitiveIndexa;
              v683[2 * v515] = v429;
              *((_DWORD *)&cmpLess.m_data + v515) = v11->m_provider->m_primitiveData->m_data[primitiveIndexa].m_data;
              goto LABEL_391;
            }
          }
          v425 = v526[2 * v405 + 1];
          v426 = v519;
          if ( v519[v425] == -1 )
          {
            v519[v425] = LOWORD(masterTree[2].m_numLeaves)
                       + (unsigned __int8)v523[1].m_domain.m_max.m_quad.m128_i8[8]
                       - (_WORD)v516;
            v498 = v526[2 * v405 + 1];
            if ( *((_DWORD *)v160 + 2) == (*((_DWORD *)v160 + 3) & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v160, 2);
              v426 = v519;
            }
            *(_WORD *)(*v160 + 2i64 * (signed int)(*((_DWORD *)v160 + 2))++) = v498;
          }
          v427 = v426[v526[2 * v405 + 1]];
LABEL_388:
          *v299 = v427;
          goto LABEL_389;
        }
LABEL_393:
        if ( v287 <= 0x10000 )
          break;
LABEL_394:
        v430 = v600;
        v431 = (signed int)v614;
        v432 = *((_DWORD *)v600 + 3) & 0x3FFFFFFF;
        if ( v432 >= (signed int)v614 )
        {
          v616.m_enum = 0;
        }
        else
        {
          v433 = 2 * v432;
          v434 = (signed int)v614;
          if ( (signed int)v614 < v433 )
            v434 = v433;
          hkArrayUtil::_reserve(&v616, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v600, v434, 4);
        }
        v430[2] = v431;
        v435 = v602;
        v436 = v164[3] & 0x3FFFFFFF;
        if ( v436 >= (signed int)v602 )
        {
          v620.m_enum = 0;
        }
        else
        {
          v437 = 2 * v436;
          v438 = v602;
          if ( (signed int)v602 < v437 )
            v438 = v437;
          hkArrayUtil::_reserve(&v620, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v164, v438, 8);
        }
        v285 = v516;
        v164[2] = v435;
        v439 = *((_DWORD *)v160 + 3) & 0x3FFFFFFF;
        if ( v439 >= v516 )
        {
          v618.m_enum = 0;
        }
        else
        {
          v440 = 2 * v439;
          v441 = v516;
          if ( v516 < v440 )
            v441 = v440;
          hkArrayUtil::_reserve(&v618, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v160, v441, 2);
          v285 = v516;
        }
        v284 = masterTree;
        *((_DWORD *)v160 + 2) = v285;
        if ( SLODWORD(masterTree[3].m_firstFree) % 0x10000 )
        {
          do
          {
            if ( v164[2] == (v164[3] & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v164, 8);
              v284 = masterTree;
            }
            *(_QWORD *)(*(_QWORD *)v164 + 8i64 * v164[2]++) = 0i64;
          }
          while ( SLODWORD(v284[3].m_firstFree) % 0x10000 );
          LOBYTE(v285) = v516;
        }
        v442 = v607;
        if ( (signed int)v607 > 0 )
        {
          v443 = v56;
          do
          {
            if ( *v443 == -2 )
              v443[1] = -1;
            v443 += 2;
            --v442;
          }
          while ( v442 );
        }
        ++v540;
        v62 = v622;
        v286 = v506;
        v288 = v604;
        v287 = 0;
        v504 = 0;
        v268 = v519;
        ++v543;
      }
      while ( v543 < 2 );
      v444 = v523;
      v523[1].m_domain.m_max.m_quad.m128_i8[9] = LOBYTE(v284[2].m_numLeaves) - LOBYTE(v544[0].m_enum);
      if ( v674 > 1 )
      {
        hkAlgorithm::quickSortRecursive<int,hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DataSorter>(
          pArr,
          0,
          v674 - 1,
          (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DataSorter)&cmpLess);
        v444 = v523;
      }
      v445 = v506;
      v446 = 0;
      if ( v506 > 0 )
      {
        v447 = pArr;
        do
        {
          v448 = *v447;
          ++v447;
          v680[v448] = v446++;
        }
        while ( v446 < v506 );
      }
      v449 = v600;
      v450 = 0;
      v451 = v506;
      v679 = 0;
      v452 = *(_QWORD *)v600 + 4 * ((unsigned __int64)v444[1].m_domain.m_max.m_quad.m128_u32[0] >> 8);
      if ( v506 )
      {
        while ( 1 )
        {
          v452 += 4i64;
          v679 = v450 + 1;
          v678[v450] = *(_DWORD *)(v452 - 4);
          if ( !--v451 )
            break;
          v450 = v679;
        }
        if ( v506 > 0 )
        {
          v453 = 0i64;
          v454 = (unsigned int)v506;
          do
          {
            ++v453;
            *(_DWORD *)(*v449
                      + 4i64
                      * (v672.m128_i32[v453 + 3] + ((unsigned int)v444[1].m_domain.m_max.m_quad.m128_i32[0] >> 8))) = *(int *)((char *)&v677 + v453 * 4);
            --v454;
          }
          while ( v454 );
        }
      }
      v455 = 0;
      if ( v444->m_nodes.m_size > 0 )
      {
        v456 = 0i64;
        do
        {
          v457 = v444->m_nodes.m_data[v456].m_data;
          if ( !(v457 & 1) )
            v444->m_nodes.m_data[v456].m_data = 2 * LOBYTE(pArr[(unsigned __int64)v457 >> 1]);
          ++v455;
          ++v456;
        }
        while ( v455 < v444->m_nodes.m_size );
      }
      v458 = 0;
      if ( v684 > 0 )
        break;
LABEL_446:
      v463 = 0;
      if ( v445 > 0 )
      {
        v464 = &masterTree[3].m_numLeaves;
        do
        {
          if ( LODWORD(masterTree[3].m_root) == (HIDWORD(masterTree[3].m_root) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v464, 8);
            v444 = v523;
            v445 = v506;
          }
          v465 = *(_QWORD *)v464;
          v466 = v463 + 1;
          v467 = SLODWORD(masterTree[3].m_root);
          LODWORD(masterTree[3].m_root) = v467 + 1;
          *(_DWORD *)(v465 + 8 * v467) = *((_DWORD *)&cmpLess.m_data + v680[v463]);
          *(_BYTE *)(v465 + 8 * v467 + 4) = v463;
          *(_BYTE *)(v465 + 8 * v467 + 5) = 1;
          if ( v463 + 1 < v445 )
          {
            v468 = &v680[v466];
            do
            {
              if ( *(_DWORD *)(v465 + 8 * v467) != *((_DWORD *)&cmpLess.m_data + *v468) )
                break;
              ++*(_BYTE *)(v465 + 8 * v467 + 5);
              ++v466;
              ++v468;
            }
            while ( v466 < v445 );
          }
          v463 += *(unsigned __int8 *)(v465 + 8 * v467 + 5);
          v444[1].m_domain.m_max.m_quad.m128_i32[1] = v444[1].m_domain.m_max.m_quad.m128_i32[1] & 0xFFFFFF00 | ((unsigned __int8)v444[1].m_domain.m_max.m_quad.m128_i8[4] + 1);
        }
        while ( v463 < v445 );
      }
      if ( !*(_BYTE *)&v686[1] )
        goto LABEL_466;
      v469 = v444[1].m_domain.m_max.m_quad.m128_u32[1];
      v470 = 0;
      v471 = *(_QWORD *)&masterTree[3].m_numLeaves;
      v472 = v469 >> 8;
      v473 = 0i64;
      v474 = v471 + 8 * v472;
      LODWORD(v472) = v472 - (unsigned __int8)v469;
      v475 = (signed int)v472;
      if ( (signed int)v472 > 0 )
      {
        v476 = (unsigned __int8)v469;
        v477 = v471 - v474 - 4;
        while ( 1 )
        {
          v478 = 0i64;
          if ( v476 <= 0 )
            break;
          v479 = (_BYTE *)(v474 + 4);
          while ( *v479 == v479[v477 + 4]
               && v479[1] == v479[v477 + 5]
               && *((_DWORD *)v479 - 1) == *(_DWORD *)&v479[v477] )
          {
            ++v478;
            v479 += 8;
            if ( v478 >= v476 )
              goto LABEL_464;
          }
          ++v473;
          ++v470;
          v477 += 8i64;
          if ( v473 >= v475 )
            goto LABEL_466;
        }
LABEL_464:
        v480 = v523;
        v155 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *)masterTree;
        v480[1].m_domain.m_max.m_quad.m128_i32[1] &= 0xFFu;
        v480[1].m_domain.m_max.m_quad.m128_i32[1] |= v470 << 8;
        v155[3].m_nodes.m_size -= (unsigned __int8)v523[1].m_domain.m_max.m_quad.m128_i8[4];
      }
      else
      {
LABEL_466:
        v155 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *)masterTree;
      }
      v269 = quads;
      v62 = v622;
      v268 = v519;
      v272 = v502 + 1;
      v271 = (signed __int64)&v510->m_elem + 1;
      v502 = v272;
      v510 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)v510 + 1);
      if ( v272 >= quads->m_size )
      {
        v270 = 0i64;
        goto LABEL_469;
      }
    }
    v459 = pArr;
    v460 = &v682;
    while ( 1 )
    {
      v461 = *v460;
      v462 = 2 * (*v459 | (v502 << 7));
      if ( (signed int)v461 >= 0 )
        break;
      if ( v460[1] )
        goto LABEL_442;
      v689->m_vMap.m_data[-v461 - 1] = 2 * (*v459 | (v502 << 7));
LABEL_444:
      ++v458;
      v460 += 2;
      ++v459;
      if ( v458 >= v684 )
      {
        v56 = v526;
        v445 = v506;
        goto LABEL_446;
      }
    }
    *((_DWORD *)&v689->vfptr->__vecDelDtor + *v460) = 2 * (*v459 | (v502 << 7));
LABEL_442:
    if ( v460[1] >= 0 )
      *((_DWORD *)&v689->vfptr->__vecDelDtor + v460[1]) = v462 | 1;
    goto LABEL_444;
  }
LABEL_469:
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::convertFromDynamicTree<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree>(
    v155,
    (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *)roots);
  v481 = 0;
  if ( v155->m_nodes.m_size > 0 )
  {
    v482 = v599;
    do
    {
      v483 = 5i64 * v481;
      if ( masterTree->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i8[v483 + 3] >= 0 )
        *(_WORD *)(96
                 * ((unsigned __int8)masterTree->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i8[5 * v481 + 4] | (unsigned __int64)((unsigned __int8)masterTree->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i8[5 * v481 + 3] << 8))
                 + *(_QWORD *)v482
                 + 90) = v481;
      v155 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *)masterTree;
      ++v481;
    }
    while ( v481 < masterTree->m_nodes.m_size );
    v268 = v519;
  }
  v484 = v155->m_nodes.m_size;
  if ( v484 < (v155->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v155, 5, 0i64, v484);
  v485 = v155[1].m_domain.m_max.m_quad.m128_i32[2];
  if ( v485 < (v155[1].m_domain.m_max.m_quad.m128_i32[3] & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v155[1].m_domain.m_max,
      4,
      0i64,
      v485);
  v486 = (int)masterTree[3].m_nodes.m_data;
  if ( v486 < (HIDWORD(masterTree[3].m_nodes.m_data) & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v525, 4, 0i64, v486);
  v487 = v164[2];
  if ( v487 < (v164[3] & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v164, 8, 0i64, v487);
  v488 = *((_DWORD *)v160 + 2);
  if ( v488 < (*((_DWORD *)v160 + 3) & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v160, 2, 0i64, v488);
  v489 = v155[3].m_nodes.m_size;
  if ( v489 < (v155[3].m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v155[3], 8, 0i64, v489);
  v490 = 0;
  if ( SLODWORD(masterTree[1].m_root) > 0 )
  {
    do
    {
      v491 = (_DWORD *)(v270 + *(_QWORD *)&masterTree[1].m_numLeaves);
      v492 = v491[2];
      if ( v492 < (v491[3] & 0x3FFFFFFF) )
        hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v491, 4, 0i64, v492);
      ++v490;
      v270 += 96i64;
    }
    while ( v490 < SLODWORD(masterTree[1].m_root) );
    v56 = v526;
  }
  hkArray<hkSurfaceConstraintInfo,hkContainerHeapAllocator>::~hkArray<hkSurfaceConstraintInfo,hkContainerHeapAllocator>(&dTree);
  if ( (signed int)v601 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v268,
      2 * (v601 & 0x3FFFFFFF));
  v493 = v530 - 1;
  if ( v530 - 1 >= 0 )
  {
    v494 = (hkPointerMap<int,int,hkContainerHeapAllocator> *)&array[v493];
    do
    {
      hkPointerMap<int,int,hkContainerHeapAllocator>::`scalar deleting destructor(v494, 0);
      --v494;
      --v493;
    }
    while ( v493 >= 0 );
  }
  v530 = 0;
  if ( v531 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v531);
  array = 0i64;
  v531 = 2147483648;
  if ( v623 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v528,
      2096 * (v623 & 0x3FFFFFFF));
  if ( v609 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v56,
      8 * v609);
  return 1;
})&hkContainerHeapAllocator::s_alloc,
      v56,
      8 * v609);
  return 1;
}

// File Line: 1057
// RVA: 0xDE9BD0
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::build<hkpBvCompressedMeshShape_Internals::GeometryProvider>(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this, hkcdStaticMeshTreeBase::BuildConfig *baseConfig, hkpBvCompressedMeshShape_Internals::GeometryProvider *baseProvider, hkcdStaticMeshTreeBase::BuildMapping *mapping)
{
  int v4; // er12
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v5; // rbx
  hkpBvCompressedMeshShapeCinfo *v6; // rcx
  hkcdStaticMeshTreeBase::BuildMapping *v7; // rdi
  hkpBvCompressedMeshShape_Internals::GeometryProvider *v8; // r15
  hkcdStaticMeshTreeBase::BuildConfig *v9; // rsi
  int v10; // eax
  int v11; // er14
  int v12; // er9
  int v13; // ecx
  __int64 v14; // rdx
  int v15; // er14
  int v16; // er9
  _DWORD *v17; // rdi
  __int64 i; // rcx
  int v19; // eax
  signed __int64 v20; // rax
  int v21; // eax
  hkcdStaticMeshTreeBase::Primitive *v22; // rcx
  int v23; // edi
  __int64 v24; // r9
  int v25; // edx
  int v26; // eax
  int v27; // er8
  signed int v28; // edx
  bool v29; // zf
  int v30; // edx
  unsigned int v31; // edi
  unsigned int v32; // eax
  unsigned int v33; // edi
  int v34; // eax
  signed int v35; // eax
  int v36; // er14
  int v37; // esi
  signed int v38; // er15
  int v39; // er13
  int v40; // er11
  hkcdStaticMeshTreeBase::Section::Primitives *v41; // r10
  unsigned __int64 v42; // rcx
  hkcdStaticMeshTreeBase::Primitive *v43; // rax
  signed __int64 v44; // r12
  unsigned int v45; // er9
  hkcdStaticMeshTreeBase::Primitive *v46; // rcx
  __int64 v47; // rax
  int v48; // er8
  int v49; // edx
  int v50; // edi
  signed __int64 v51; // rax
  signed int v52; // edi
  __int64 v53; // rcx
  __int64 v54; // rdx
  unsigned int *v55; // rax
  __int64 v56; // r14
  char v57; // di
  __int64 v58; // r14
  unsigned int v59; // eax
  int v60; // er8
  int v61; // edi
  int v62; // ecx
  int v63; // edx
  signed __int64 v64; // rax
  hkOstream *v65; // rax
  hkOstream *v66; // rax
  int v67; // esi
  int v68; // er15
  int v69; // edx
  hkResultEnum v70; // er13
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v71; // r11
  unsigned __int64 v72; // rcx
  hkcdStaticMeshTreeBase::Primitive *v73; // rax
  unsigned int *v74; // r10
  int v75; // er14
  hkcdStaticMeshTreeBase::Primitive *v76; // rsi
  unsigned int v77; // er14
  __int64 v78; // rdi
  int v79; // eax
  int v80; // ecx
  int v81; // edx
  signed __int64 v82; // rax
  hkcdStaticMeshTreeBase::BuildMapping *v83; // r9
  signed __int64 v84; // rdx
  signed __int64 v85; // rcx
  unsigned int *v86; // rax
  char v87; // al
  char v88; // cl
  signed __int64 v89; // rcx
  signed __int64 v90; // rdx
  unsigned int *v91; // rax
  int v92; // edi
  int v93; // ecx
  int v94; // er8
  int v95; // edx
  signed __int64 v96; // rax
  int v97; // eax
  hkOstream *v98; // rax
  hkOstream *v99; // rax
  hkOstream *v100; // rax
  hkOstream *v101; // rax
  int v102; // edi
  __int32 v103; // edi
  hkOstream *v104; // rax
  int v105; // er8
  signed int v106; // esi
  int v107; // er14
  unsigned int v108; // er15
  __int64 v109; // rax
  int *v110; // rdi
  int v111; // edx
  int v112; // edx
  int v113; // ecx
  int v114; // ecx
  hkOstream *v115; // rax
  __int64 v116; // r15
  int v117; // er8
  unsigned int v118; // er11
  int v119; // esi
  int v120; // er14
  __int64 v121; // r9
  hkcdStaticMeshTreeBase::Primitive *v122; // rdx
  int v123; // ecx
  int v124; // eax
  int v125; // edi
  signed int v126; // ecx
  int v127; // ecx
  int v128; // ecx
  hkOstream *v129; // rax
  unsigned __int8 v130; // di
  __int64 sizeElem; // [rsp+20h] [rbp-E0h]
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *roots; // [rsp+28h] [rbp-D8h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v134; // [rsp+30h] [rbp-D0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *masterTree; // [rsp+38h] [rbp-C8h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v136; // [rsp+40h] [rbp-C0h]
  __int64 v137; // [rsp+48h] [rbp-B8h]
  int v138; // [rsp+50h] [rbp-B0h]
  int v139; // [rsp+50h] [rbp-B0h]
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> quads; // [rsp+60h] [rbp-A0h]
  hkcdStaticMeshTreeBase::BuildMapping mappinga; // [rsp+70h] [rbp-90h]
  hkVector4f c; // [rsp+A0h] [rbp-60h]
  hkVector4f v143; // [rsp+B0h] [rbp-50h]
  int v144; // [rsp+C0h] [rbp-40h]
  hkcdStaticMeshTreeBase::Section::Primitives *v145; // [rsp+D0h] [rbp-30h]
  int v146; // [rsp+D8h] [rbp-28h]
  int v147; // [rsp+DCh] [rbp-24h]
  int v148; // [rsp+E0h] [rbp-20h]
  hkcdStaticMeshTreeBase::BuildConfig::Vrp v149; // [rsp+E4h] [rbp-1Ch]
  hkcdStaticMeshTreeBase::BuildConfig::Pbd v150; // [rsp+E8h] [rbp-18h]
  int v151; // [rsp+ECh] [rbp-14h]
  int v152; // [rsp+F0h] [rbp-10h]
  float v153; // [rsp+F4h] [rbp-Ch]
  float v154; // [rsp+F8h] [rbp-8h]
  unsigned int v155; // [rsp+FCh] [rbp-4h]
  float v156; // [rsp+100h] [rbp+0h]
  hkcdStaticMeshTreeBase::BuildConfig config; // [rsp+108h] [rbp+8h]
  int v158; // [rsp+134h] [rbp+34h]
  int v159; // [rsp+138h] [rbp+38h]
  hkcdStaticMeshTreeBase::BuildConfig v160; // [rsp+140h] [rbp+40h]
  int v161; // [rsp+16Ch] [rbp+6Ch]
  char v162; // [rsp+170h] [rbp+70h]
  hkSimdFloat32 tolerance; // [rsp+1F0h] [rbp+F0h]
  char buf; // [rsp+200h] [rbp+100h]
  hkResult result; // [rsp+448h] [rbp+348h]
  int v166; // [rsp+450h] [rbp+350h]
  hkcdStaticMeshTreeBase::BuildMapping *v167; // [rsp+458h] [rbp+358h]

  v167 = mapping;
  v4 = 0;
  v5 = this;
  v6 = baseProvider->m_meshCInfo;
  *(_QWORD *)&config.m_balanceThreshold = baseProvider;
  config.m_weldTolerance = -0.0;
  *(_QWORD *)&config.m_pbd = 0i64;
  *(_DWORD *)&config.m_weldVertices.m_bool = 0;
  *(_QWORD *)&config.m_convexRadius = 0i64;
  *(_QWORD *)&config.m_globalOptimizations.m_bool = &hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>::`vftable;
  config.m_maxCompressionError = 0.0;
  v158 = 2147483648;
  v159 = 0;
  v7 = mapping;
  v8 = baseProvider;
  v9 = baseConfig;
  v10 = (*(__int64 (**)(void))v6->vfptr->gap8)();
  v11 = v10;
  if ( (LODWORD(config.m_weldTolerance) & 0x3FFFFFFF) < v10 )
  {
    v12 = v10;
    if ( v10 < 2 * (LODWORD(config.m_weldTolerance) & 0x3FFFFFFF) )
      v12 = 2 * (LODWORD(config.m_weldTolerance) & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &config.m_pbd, v12, 4);
  }
  *(_DWORD *)&config.m_weldVertices.m_bool = v11;
  v13 = 0;
  if ( v11 > 0 )
  {
    v14 = 0i64;
    do
    {
      v14 += 4i64;
      *(_DWORD *)(*(_QWORD *)&config.m_pbd + v14 - 4) = v13++;
    }
    while ( v13 < *(_DWORD *)&config.m_weldVertices.m_bool );
  }
  v159 = ((__int64 (*)(void))v8->m_meshCInfo->vfptr->getNumTriangles)();
  v15 = (v159 + 31) >> 5;
  if ( (v158 & 0x3FFFFFFF) < v15 )
  {
    v16 = (v159 + 31) >> 5;
    if ( v15 < 2 * (v158 & 0x3FFFFFFF) )
      v16 = 2 * (v158 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &config.m_convexRadius,
      v16,
      4);
  }
  LODWORD(config.m_maxCompressionError) = v15;
  if ( v15 - 1 >= 0 )
  {
    v17 = *(_DWORD **)&config.m_convexRadius;
    for ( i = (unsigned int)v15; i; --i )
    {
      *v17 = -1;
      ++v17;
    }
    v7 = v167;
  }
  v19 = *(_DWORD *)&v9->m_globalOptimizations.m_bool;
  *(_DWORD *)&v160.m_weldVertices.m_bool = 0;
  v146 = v19;
  v147 = *(_DWORD *)&v9->m_vertexHasFlags.m_bool;
  v148 = v9->m_balanceThreshold;
  v149 = v9->m_vrp;
  v150 = v9->m_pbd;
  v151 = v9->m_verbosity;
  v152 = *(_DWORD *)&v9->m_weldVertices.m_bool;
  v153 = v9->m_weldTolerance;
  v154 = v9->m_convexRadius;
  v155 = LODWORD(v9->m_degenerateTolerance);
  v156 = v9->m_maxCompressionError;
  v20 = 0i64;
  do
  {
    *((_DWORD *)&v160.m_vrp + v20) = 0;
    *((_DWORD *)&v160.m_globalOptimizations.m_bool + v20++) = 0;
  }
  while ( v20 < 3 );
  while ( 1 )
  {
    hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::clear(v5);
    mappinga.m_triangleIndexToKey.m_data = 0i64;
    mappinga.m_triangleIndexToKey.m_size = 0;
    mappinga.m_triangleIndexToKey.m_capacityAndFlags = 2147483648;
    mappinga.m_customIndexToKey.m_size = 0;
    mappinga.m_customIndexToKey.m_data = 0i64;
    mappinga.m_customIndexToKey.m_capacityAndFlags = 2147483648;
    mappinga.m_triangleVertexRotations.m_data = 0i64;
    c.m_quad.m128_u64[0] = 0i64;
    *(_QWORD *)&mappinga.m_triangleVertexRotations.m_size = 0i64;
    quads.m_data = 0i64;
    quads.m_size = 0;
    quads.m_capacityAndFlags = 2147483648;
    if ( !hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep12<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *)&v146,
            &config,
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v7,
            &mappinga,
            &quads,
            (hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *)&mappinga.m_customIndexToKey,
            v134)
      || !hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::buildStep3<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities *)&v146,
            &v160,
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Utilities::QuantizersInfos *)&config,
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)v7,
            &mappinga,
            &quads,
            (hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree,hkContainerHeapAllocator> *)&mappinga.m_customIndexToKey,
            (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *)v5,
            v136) )
    {
      break;
    }
    quads.m_size = 0;
    if ( quads.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        quads.m_data,
        24 * (quads.m_capacityAndFlags & 0x3FFFFFFF));
    quads.m_data = 0i64;
    quads.m_capacityAndFlags = 2147483648;
    mappinga.m_customIndexToKey.m_size = 0;
    if ( mappinga.m_customIndexToKey.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        mappinga.m_customIndexToKey.m_data,
        mappinga.m_customIndexToKey.m_capacityAndFlags << 6);
    mappinga.m_customIndexToKey.m_data = 0i64;
    mappinga.m_customIndexToKey.m_capacityAndFlags = 2147483648;
    mappinga.m_triangleIndexToKey.m_size = 0;
    if ( mappinga.m_triangleIndexToKey.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        mappinga.m_triangleIndexToKey.m_data,
        12 * (mappinga.m_triangleIndexToKey.m_capacityAndFlags & 0x3FFFFFFF));
    v21 = v5->m_primitives.m_size;
    mappinga.m_triangleIndexToKey.m_data = 0i64;
    mappinga.m_triangleIndexToKey.m_capacityAndFlags = 2147483648;
    v5->m_numPrimitiveKeys = 0;
    if ( v21 > 0 )
    {
      v22 = v5->m_primitives.m_data;
      v23 = 0;
      v24 = (unsigned int)v21;
      do
      {
        v25 = (unsigned __int8)v22->m_indices[3];
        v26 = (unsigned __int8)v22->m_indices[2];
        v27 = (unsigned __int8)v22->m_indices[1];
        if ( v25 == v26 )
        {
          v28 = 1;
          if ( v26 == v27 )
            v28 = 3;
        }
        else if ( v22->m_indices[0] != -34 || v27 != 173 || v26 != 222 || (v29 = v25 == 173, v28 = 0, !v29) )
        {
          v28 = 2;
        }
        ++v22;
        v23 += (v28 == 2) + 1;
        v5->m_numPrimitiveKeys = v23;
        --v24;
      }
      while ( v24 );
    }
    v30 = v5->m_sections.m_size;
    v31 = 0;
    if ( v30 )
    {
      v32 = 0;
      do
      {
        if ( v32 > v31 )
          v31 = v32;
        v32 = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getNextKey(
                v5,
                v32);
      }
      while ( v32 != -1 );
      v30 = v5->m_sections.m_size;
    }
    v5->m_maxKeyValue = v31;
    v5->m_bitsPerKey = 0;
    v33 = v31 + 1;
    if ( v33 )
    {
      v34 = 0;
      do
      {
        ++v34;
        v33 >>= 1;
      }
      while ( v33 );
      v5->m_bitsPerKey = v34;
    }
    v35 = v5->m_bitsPerKey;
    if ( !v35 && v5->m_numPrimitiveKeys )
      v35 = 1;
    v29 = v149 == 2;
    v5->m_bitsPerKey = v35;
    if ( v29 )
      goto LABEL_152;
    v36 = 0;
    result.m_enum = 0;
    tolerance.m_real = _mm_shuffle_ps((__m128)v155, (__m128)v155, 0);
    if ( v150 == 1 )
    {
      v67 = 0;
      v68 = 0;
      v166 = 0;
      if ( v30 )
      {
        v69 = 0;
        v70 = 0;
        v71 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *)&v5->m_sections.m_data->m_primitives;
        v144 = 0;
LABEL_100:
        v72 = (unsigned int)v71->m_edges[0];
        v73 = v5->m_primitives.m_data;
        quads.m_data = v71;
        v72 >>= 8;
        v139 = v69;
        v74 = (unsigned int *)&v73[v72];
        mappinga.m_triangleIndexToKey.m_data = (unsigned int *)&v73[v72];
        while ( 1 )
        {
          do
          {
            v75 = 2 * v67;
            v76 = v5->m_primitives.m_data;
            v77 = (v69 << 8) | v75;
            v78 = ((unsigned __int8)v77 >> 1) + (v5->m_sections.m_data[v77 >> 8].m_primitives.m_data >> 8);
            v79 = (unsigned __int8)v76[v78].m_indices[3];
            v80 = (unsigned __int8)v76[v78].m_indices[2];
            v81 = (unsigned __int8)v76[v78].m_indices[1];
            if ( v79 == v80 )
            {
              v82 = 1i64;
              if ( v80 == v81 )
                v82 = 3i64;
            }
            else if ( v76[v78].m_indices[0] != -34 || v81 != 173 || v80 != 222 || v79 != 173 )
            {
              v82 = 2i64;
            }
            else
            {
              v82 = 0i64;
            }
            LODWORD(v145) = hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v82];
            if ( (_DWORD)v145 )
            {
              hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getQuadVertices(
                v5,
                v77,
                (hkVector4f *)&mappinga.m_customIndexToKey);
              if ( (signed int)v145 > 1
                && hkcdTriangleUtil::isDegenerate((hkVector4f *)&mappinga.m_customIndexToKey, &c, &v143, &tolerance) )
              {
                v83 = v167;
                ++v70;
                v76[v78].m_indices[3] = v76[v78].m_indices[2];
                v84 = v83->m_triangleIndexToKey.m_size;
                v85 = 0i64;
                result.m_enum = v70;
                if ( v84 <= 0 )
                {
LABEL_118:
                  v85 = -1i64;
                }
                else
                {
                  v86 = v83->m_triangleIndexToKey.m_data;
                  while ( *v86 != v77 + 1 )
                  {
                    ++v85;
                    ++v86;
                    if ( v85 >= v84 )
                      goto LABEL_118;
                  }
                }
                v83->m_triangleIndexToKey.m_data[v85] = -1;
              }
              if ( hkcdTriangleUtil::isDegenerate(
                     (hkVector4f *)&mappinga.m_customIndexToKey,
                     (hkVector4f *)&mappinga.m_triangleVertexRotations,
                     &c,
                     &tolerance) )
              {
                v87 = v76[v78].m_indices[3];
                v88 = v76[v78].m_indices[2];
                if ( v88 == v87 )
                {
                  v76[v78] = (hkcdStaticMeshTreeBase::Primitive)-1377915426;
                }
                else
                {
                  v76[v78].m_indices[1] = v88;
                  v76[v78].m_indices[2] = v87;
                }
                v89 = 0i64;
                v90 = v167->m_triangleIndexToKey.m_size;
                result.m_enum = v70 + 1;
                if ( v90 <= 0 )
                {
LABEL_128:
                  v89 = -1i64;
                }
                else
                {
                  v91 = v167->m_triangleIndexToKey.m_data;
                  while ( *v91 != v77 )
                  {
                    ++v89;
                    ++v91;
                    if ( v89 >= v90 )
                      goto LABEL_128;
                  }
                }
                v167->m_triangleIndexToKey.m_data[v89] = -1;
              }
              v74 = mappinga.m_triangleIndexToKey.m_data;
            }
            v92 = HIBYTE(v74[v166]);
            v93 = BYTE2(v74[v166]);
            v94 = BYTE1(v74[v166]);
            do
            {
              v95 = v68++ + 1;
              if ( v92 == v93 )
              {
                v96 = 1i64;
                if ( v93 == v94 )
                  v96 = 3i64;
              }
              else if ( LOBYTE(v74[v166]) != -34 || v94 != 173 || v93 != 222 || v92 != 173 )
              {
                v96 = 2i64;
              }
              else
              {
                v96 = 0i64;
              }
            }
            while ( v95 < hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v96] );
            v70 = result.m_enum;
            v69 = v139;
            v97 = (unsigned __int8)quads.m_data->m_edges[0];
            v67 = v166 + 1;
            v68 = 0;
            v166 = v67;
          }
          while ( v67 < v97 );
          v67 = 0;
          ++v4;
          v166 = 0;
          if ( v4 >= v5->m_sections.m_size )
            break;
          if ( v4 != v139 || v144 != v4 )
          {
            v144 = v4;
            v69 = v4;
            v71 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *)&v5->m_sections.m_data[v4].m_primitives;
            goto LABEL_100;
          }
        }
        v36 = result.m_enum;
      }
      if ( v151 & 1 && v36 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, &buf, 512);
        v98 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, "Found ");
        v99 = hkOstream::operator<<(v98, v36, (int)v98);
        hkOstream::operator<<(v99, " degenerated triangle(s) after build, marking them as invalid.");
        hkError::messageReport(0, &buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
      }
LABEL_152:
      if ( v151 & 2 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, &buf, 512);
        v100 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, "==== Statistics for ");
        v101 = hkOstream::operator<<(v100, v5, (int)v100);
        hkOstream::operator<<(v101, " =====\n");
        hkError::messageReport(0, &buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getMemoryFootPrint(
          v5,
          (hkcdStaticMeshTreeBase::MemoryStatistics *)&quads);
        v102 = quads.m_capacityAndFlags;
        *(_QWORD *)&v160.m_convexRadius = &v162;
        v161 = -2147483520;
        LODWORD(v160.m_maxCompressionError) = 1;
        v162 = 0;
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Total size: %d Kb\n",
          (unsigned int)((quads.m_capacityAndFlags + 512) >> 10));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Collision: %d (%d%%)\n",
          LODWORD(quads.m_data),
          (unsigned int)((100 * LODWORD(quads.m_data) + 50) / v102));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Geometry: %d (%d%%)\n",
          HIDWORD(quads.m_data),
          (unsigned int)((100 * HIDWORD(quads.m_data) + 50) / v102));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Data: %d (%d%%)\n",
          (unsigned int)quads.m_size,
          (unsigned int)((100 * quads.m_size + 50) / v102));
        v103 = v160.m_vrp + v160.m_pbd + v160.m_verbosity;
        if ( v103 < 1 )
          v103 = 1;
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Compression CM_GLOBAL : %d (%d%%)\n",
          (unsigned int)v160.m_vrp,
          (unsigned int)((100 * v160.m_vrp + 50) / v103));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Compression CM_LOCAL_4 : %d (%d%%)\n",
          (unsigned int)v160.m_pbd,
          (unsigned int)((100 * v160.m_pbd + 50) / v103));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Compression CM_LOCAL_2 : %d (%d%%)\n",
          (unsigned int)v160.m_verbosity,
          (unsigned int)((100 * v160.m_verbosity + 50) / v103));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Tags: %d (%d bytes)\n",
          *(signed int *)&v160.m_weldVertices.m_bool,
          2i64 * *(signed int *)&v160.m_weldVertices.m_bool);
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, &buf, 512);
        v104 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, &customWorldMapCaption);
        hkOstream::operator<<(v104, *(const char **)&v160.m_convexRadius);
        hkError::messageReport(0, &buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        hkStringBuf::clear((hkStringBuf *)&v160.m_convexRadius);
        v105 = v5->m_sections.m_size;
        v106 = 256;
        v107 = 0;
        v108 = 0;
        if ( v105 )
        {
          if ( v105 > 0 )
          {
            v109 = (unsigned int)v105;
            v110 = &v5->m_sections.m_data->m_nodes.m_size;
            do
            {
              v111 = *v110;
              v110 += 24;
              v112 = (v111 + 1) >> 1;
              v113 = v112;
              if ( v106 < v112 )
                v113 = v106;
              v106 = v113;
              v114 = v112;
              if ( v107 > v112 )
                v114 = v107;
              v108 += v112;
              v107 = v114;
              --v109;
            }
            while ( v109 );
          }
          v108 = (signed int)v108 / v105;
        }
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Number of pages: %u\n",
          (unsigned int)*((unsigned __int8 *)&v5->m_sections.m_data[v5->m_sections.m_size] - 4) + 1);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Number of sections: %d\n",
          (unsigned int)v5->m_sections.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Number of primitives: %d\n",
          (unsigned int)v5->m_primitives.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Number of shared indices: %d\n",
          (unsigned int)v5->m_sharedVerticesIndex.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Number of shared vertices: %d\n",
          (unsigned int)v5->m_sharedVertices.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Number of packed vertices: %d\n",
          (unsigned int)v5->m_packedVertices.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Number of data-runs: %d\n",
          (unsigned int)v5->m_primitiveDataRuns.m_size);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Number of keys: %d\n",
          (unsigned int)v5->m_numPrimitiveKeys);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Min. keys per section: %d\n",
          (unsigned int)v106);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Max. keys per section: %d\n",
          (unsigned int)v107);
        hkStringBuf::appendPrintf((hkStringBuf *)&v160.m_convexRadius, "Avg. keys per section: %d\n", v108);
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Data to primitive ratio: %f\n",
          (float)((float)v5->m_primitiveDataRuns.m_size / (float)v5->m_primitives.m_size));
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Bits per key: %d\n",
          (unsigned int)v5->m_bitsPerKey);
        hkStringBuf::appendPrintf((hkStringBuf *)&v160.m_convexRadius, "Max key value: %u\n", v5->m_maxKeyValue);
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, &buf, 512);
        v115 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, &customWorldMapCaption);
        hkOstream::operator<<(v115, *(const char **)&v160.m_convexRadius);
        hkError::messageReport(0, &buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        hkStringBuf::clear((hkStringBuf *)&v160.m_convexRadius);
        v116 = v5->m_primitives.m_size;
        v117 = 0;
        v118 = 0;
        v119 = 0;
        v120 = 0;
        v121 = v116;
        if ( (signed int)v116 > 0 )
        {
          v122 = v5->m_primitives.m_data;
          do
          {
            v123 = (unsigned __int8)v122->m_indices[3];
            v124 = (unsigned __int8)v122->m_indices[2];
            v125 = (unsigned __int8)v122->m_indices[1];
            if ( v123 == v124 )
            {
              v126 = 1;
              if ( v124 == v125 )
                v126 = 3;
            }
            else if ( v122->m_indices[0] != -34 || v125 != 173 || v124 != 222 || (v29 = v123 == 173, v126 = 0, !v29) )
            {
              v126 = 2;
            }
            if ( v126 )
            {
              v127 = v126 - 1;
              if ( v127 )
              {
                v128 = v127 - 1;
                if ( v128 )
                {
                  if ( v128 == 1 )
                    ++v120;
                }
                else
                {
                  ++v118;
                }
              }
              else
              {
                ++v119;
              }
            }
            else
            {
              ++v117;
            }
            ++v122;
            --v121;
          }
          while ( v121 );
          LODWORD(v116) = v5->m_primitives.m_size;
        }
        LODWORD(v137) = (100 * v117 + 50) / (signed int)v116;
        LODWORD(v136) = v117;
        LODWORD(masterTree) = (100 * v120 + 50) / (signed int)v116;
        LODWORD(v134) = v120;
        LODWORD(roots) = (100 * v119 + 50) / (signed int)v116;
        LODWORD(sizeElem) = v119;
        hkStringBuf::appendPrintf(
          (hkStringBuf *)&v160.m_convexRadius,
          "Quads: %d(%d%%) Triangles: %d(%d%%) Customs: %d(%d%%) Invalids: %d(%d%%)\n",
          v118,
          (unsigned int)((signed int)(100 * v118 + 50) / (signed int)v116),
          sizeElem,
          roots,
          v134,
          masterTree,
          v136,
          v137);
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, &buf, 512);
        v129 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, &customWorldMapCaption);
        hkOstream::operator<<(v129, *(const char **)&v160.m_convexRadius);
        hkError::messageReport(0, &buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        hkStringBuf::clear((hkStringBuf *)&v160.m_convexRadius);
        hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, &buf, 512);
        hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, "=====================");
        hkError::messageReport(0, &buf, 0i64, 0);
        hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
        v160.m_maxCompressionError = 0.0;
        if ( v161 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            *(void **)&v160.m_convexRadius,
            v161 & 0x3FFFFFFF);
      }
      v130 = 1;
      goto LABEL_196;
    }
    if ( v150 != 2 )
      goto LABEL_152;
    v37 = 0;
    v38 = 0;
    v39 = 0;
    if ( !v30 )
      goto LABEL_152;
    v138 = 0;
    v40 = 0;
    v41 = &v5->m_sections.m_data->m_primitives;
    v166 = 0;
LABEL_57:
    v42 = v41->m_data;
    v43 = v5->m_primitives.m_data;
    v145 = v41;
    v44 = (signed __int64)v43[v42 >> 8].m_indices;
    while ( 1 )
    {
      while ( 1 )
      {
        v45 = v39 | (v40 << 8) | 2 * v38;
        v46 = v5->m_primitives.m_data;
        v47 = (signed int)((((v39 | (v40 << 8) | (unsigned int)(2 * v38)) >> 1) & 0x7F)
                         + (v5->m_sections.m_data[v45 >> 8].m_primitives.m_data >> 8));
        v48 = (unsigned __int8)v46[v47].m_indices[3];
        v49 = (unsigned __int8)v46[v47].m_indices[2];
        v50 = (unsigned __int8)v46[v47].m_indices[1];
        if ( v48 == v49 )
        {
          v51 = 1i64;
          if ( v49 == v50 )
            v51 = 3i64;
        }
        else if ( v46[v47].m_indices[0] != -34 || v50 != 173 || v49 != 222 || v48 != 173 )
        {
          v51 = 2i64;
        }
        else
        {
          v51 = 0i64;
        }
        if ( hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v51] )
        {
          v52 = 0;
          v53 = 0i64;
          v54 = v167->m_triangleIndexToKey.m_size;
          if ( v54 <= 0 )
          {
LABEL_73:
            v52 = -1;
          }
          else
          {
            v55 = v167->m_triangleIndexToKey.m_data;
            while ( *v55 != v45 )
            {
              ++v53;
              ++v52;
              ++v55;
              if ( v53 >= v54 )
                goto LABEL_73;
            }
          }
          v56 = v52;
          v57 = v52 & 0x1F;
          v58 = v56 >> 5;
          if ( (*(_DWORD *)(*(_QWORD *)&config.m_convexRadius + 4 * v58) >> v57) & 1 )
          {
            hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getTriangleVertices(
              v5,
              v45,
              (hkVector4f *)&mappinga.m_customIndexToKey);
            v59 = hkcdTriangleUtil::isDegenerate(
                    (hkVector4f *)&mappinga.m_customIndexToKey,
                    (hkVector4f *)&mappinga.m_triangleVertexRotations,
                    &c,
                    &tolerance);
            v41 = v145;
            v40 = v166;
            if ( v59 )
            {
              *(_DWORD *)(*(_QWORD *)&config.m_convexRadius + 4 * v58) &= ~(1 << v57);
              v36 = result.m_enum++ + 1;
            }
            else
            {
              v36 = result.m_enum;
            }
          }
          else
          {
            v36 = result.m_enum;
          }
        }
        v60 = v39 + 1;
        v61 = *(unsigned __int8 *)(v44 + 4i64 * v38 + 3);
        v62 = *(unsigned __int8 *)(v44 + 4i64 * v38 + 2);
        v63 = *(unsigned __int8 *)(v44 + 4i64 * v38 + 1);
        ++v39;
        if ( v61 == v62 )
        {
          v64 = 1i64;
          if ( v62 == v63 )
            v64 = 3i64;
        }
        else if ( *(_BYTE *)(v44 + 4i64 * v38) != -34 || v63 != 173 || v62 != 222 || v61 != 173 )
        {
          v64 = 2i64;
        }
        else
        {
          v64 = 0i64;
        }
        if ( v60 >= hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v64] )
        {
          ++v38;
          v39 = 0;
          if ( v38 >= LOBYTE(v41->m_data) )
            break;
        }
      }
      ++v37;
      v38 = 0;
      if ( v37 >= v5->m_sections.m_size )
        break;
      if ( v37 != v40 || v138 != v37 )
      {
        v138 = v37;
        v40 = v37;
        v166 = v37;
        v41 = &v5->m_sections.m_data[v37].m_primitives;
        goto LABEL_57;
      }
    }
    if ( !v36 )
      goto LABEL_152;
    v7 = v167;
    LOBYTE(v152) = 0;
    v4 = 0;
    if ( v151 & 1 )
    {
      hkErrStream::hkErrStream((hkErrStream *)&mappinga.m_customIndexToKey, &buf, 512);
      v65 = hkOstream::operator<<((hkOstream *)&mappinga.m_customIndexToKey, "Found ");
      v66 = hkOstream::operator<<(v65, v36, (int)v65);
      hkOstream::operator<<(v66, " degenerated triangle(s) after build, rebuilding.");
      hkError::messageReport(0, &buf, 0i64, 0);
      hkOstream::~hkOstream((hkOstream *)&mappinga.m_customIndexToKey);
    }
  }
  quads.m_size = 0;
  if ( quads.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      quads.m_data,
      24 * (quads.m_capacityAndFlags & 0x3FFFFFFF));
  quads.m_data = 0i64;
  quads.m_capacityAndFlags = 2147483648;
  mappinga.m_customIndexToKey.m_size = 0;
  if ( mappinga.m_customIndexToKey.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      mappinga.m_customIndexToKey.m_data,
      mappinga.m_customIndexToKey.m_capacityAndFlags << 6);
  mappinga.m_customIndexToKey.m_data = 0i64;
  mappinga.m_customIndexToKey.m_capacityAndFlags = 2147483648;
  mappinga.m_triangleIndexToKey.m_size = 0;
  if ( mappinga.m_triangleIndexToKey.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      mappinga.m_triangleIndexToKey.m_data,
      12 * (mappinga.m_triangleIndexToKey.m_capacityAndFlags & 0x3FFFFFFF));
  v130 = 0;
LABEL_196:
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>::~BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>((hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *)&config);
  return v130;
}data = 0i64;
  mappinga.m_customIndexToKey.m_capacityAndFlags = 2147483648;
  mappinga.m_triangleIndexToKey.m_size = 0;
  if ( mappinga.m_triangl

// File Line: 1477
// RVA: 0xDF1110
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree::countVertices<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>>(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *this, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *tree, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *provider, hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *quads)
{
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v4; // rbx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v5; // r15
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v6; // r13
  unsigned __int64 v7; // r9
  int v8; // er14
  hkcdDynamicTree::CodecRawUlong *v9; // rdx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // r12
  unsigned __int64 v12; // r13
  __int64 v13; // rdi
  __int64 v14; // rbx
  signed int v15; // esi
  int v16; // ebx
  hkpBvCompressedMeshShape_Internals::GeometryProvider *v17; // rax
  hkpBvCompressedMeshShapeCinfo *v18; // rcx
  hkpBvCompressedMeshShapeCinfoVtbl *v19; // rax
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  signed int v23; // eax
  __int64 v24; // r8
  __int64 v25; // r10
  int v26; // ecx
  signed __int64 v27; // rax
  signed __int64 v28; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v29; // rdi
  unsigned int v30; // er9
  int v31; // ebx
  int *v32; // rdx
  unsigned int v33; // er9
  int v34; // ebx
  int *v35; // rdx
  int v36; // ebx
  int *v37; // rdx
  unsigned int v38; // er9
  int v39; // ebx
  int *v40; // rdx
  int v41; // eax
  unsigned __int64 v42; // rcx
  unsigned __int64 i; // r8
  signed __int64 v44; // rdi
  signed int v45; // er12
  signed int v46; // esi
  int v47; // ebx
  hkpBvCompressedMeshShapeCinfo *v48; // rcx
  int v49; // eax
  int v50; // ecx
  int j; // edx
  signed __int64 v52; // rsi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad *v53; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::EdgeBase v54; // er9
  int v55; // ebx
  int *v56; // rdx
  unsigned int v57; // er9
  int v58; // ebx
  int *v59; // rdx
  int v60; // ebx
  int *v61; // r8
  unsigned int v62; // er9
  int v63; // ebx
  int *v64; // rdx
  signed __int64 v65; // r8
  int v66; // ecx
  signed __int64 v67; // rax
  int v68; // eax
  int v70; // [rsp+20h] [rbp-C0h]
  int v71; // [rsp+24h] [rbp-BCh]
  int v72; // [rsp+28h] [rbp-B8h]
  __int64 v73; // [rsp+30h] [rbp-B0h]
  __int64 v74; // [rsp+38h] [rbp-A8h]
  int v75; // [rsp+40h] [rbp-A0h]
  int v76; // [rsp+48h] [rbp-98h]
  int v77; // [rsp+4Ch] [rbp-94h]
  int v78; // [rsp+50h] [rbp-90h]
  int v79; // [rsp+58h] [rbp-88h]
  int v80; // [rsp+5Ch] [rbp-84h]
  hkcdStaticMeshTreeBase::BuildCustomInfos customPrimitive; // [rsp+60h] [rbp-80h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *v82; // [rsp+A0h] [rbp-40h]
  hkArray<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Quad,hkContainerHeapAllocator> *v83; // [rsp+A8h] [rbp-38h]
  int v84[256]; // [rsp+B0h] [rbp-30h]
  int v85; // [rsp+4B0h] [rbp+3D0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::SubTree *v86; // [rsp+500h] [rbp+420h]
  hkcdDynamicTree::CodecRawUlong **v87; // [rsp+508h] [rbp+428h]

  v4 = quads;
  v5 = provider;
  v6 = this;
  if ( this->m_numVertices >= 0 )
    return (unsigned int)this->m_numVertices;
  v7 = this->m_node;
  v82 = provider;
  v83 = v4;
  v8 = 0;
  v85 = 0;
  customPrimitive.m_aabb.m_max.m_quad.m128_u64[1] = v7;
  if ( v7 )
  {
    v9 = tree->m_nodes.m_data;
    v10 = v7 << 6;
    if ( LODWORD(v9[v7].m_children[0]) )
    {
      v11 = *(unsigned __int64 *)((char *)v9->m_children + v10);
      if ( v11 )
      {
        do
        {
          v12 = v11 << 6;
          if ( !LODWORD(v9[v11].m_children[0]) && v8 != 256 )
          {
            v13 = *(signed int *)((char *)&v9->m_children[1] + v12);
            v14 = (__int64)v83;
            v75 = 0;
            v73 = 0i64;
            v74 = 0i64;
            v15 = v83->m_size;
            if ( (signed int)v13 < v15 )
            {
              v28 = v13;
              v29 = v83->m_data;
              v30 = (unsigned int)v83->m_data[v28].m_edges[0];
              v31 = (signed int)((v30 >> 30) + 1) % 3;
              v5->m_provider->m_meshCInfo->vfptr->getIndices(
                v5->m_provider->m_meshCInfo,
                v30 & 0x3FFFFFFF,
                &customPrimitive.m_aabb.m_min.m_quad.m128_i32[2]);
              v32 = v5->m_vMap.m_data;
              customPrimitive.m_aabb.m_min.m_quad.m128_i32[2] = v32[customPrimitive.m_aabb.m_min.m_quad.m128_i32[2]];
              customPrimitive.m_aabb.m_min.m_quad.m128_i32[3] = v32[customPrimitive.m_aabb.m_min.m_quad.m128_i32[3]];
              customPrimitive.m_aabb.m_max.m_quad.m128_i32[0] = v32[customPrimitive.m_aabb.m_max.m_quad.m128_i32[0]];
              *(float *)&v73 = customPrimitive.m_aabb.m_min.m_quad.m128_f32[v31 + 2];
              v33 = (unsigned int)v29[v28].m_edges[0];
              v34 = (signed int)((v33 >> 30) + 2) % 3;
              v5->m_provider->m_meshCInfo->vfptr->getIndices(v5->m_provider->m_meshCInfo, v33 & 0x3FFFFFFF, &v79);
              v35 = v5->m_vMap.m_data;
              v79 = v35[v79];
              v80 = v35[v80];
              customPrimitive.m_aabb.m_min.m_quad.m128_i32[0] = v35[customPrimitive.m_aabb.m_min.m_quad.m128_i32[0]];
              HIDWORD(v73) = *(&v79 + v34);
              v36 = ((*(_DWORD *)&v29[v28].m_edges[1] >> 30) + 1) % 3;
              v5->m_provider->m_meshCInfo->vfptr->getIndices(
                v5->m_provider->m_meshCInfo,
                *(_DWORD *)&v29[v28].m_edges[1] & 0x3FFFFFFF,
                &v76);
              v37 = v5->m_vMap.m_data;
              v76 = v37[v76];
              v77 = v37[v77];
              v78 = v37[v78];
              LODWORD(v74) = *(&v76 + v36);
              v38 = (unsigned int)v29[v28].m_edges[1];
              v39 = (signed int)((v38 >> 30) + 2) % 3;
              v5->m_provider->m_meshCInfo->vfptr->getIndices(v5->m_provider->m_meshCInfo, v38 & 0x3FFFFFFF, &v70);
              v40 = v5->m_vMap.m_data;
              v70 = v40[v70];
              v71 = v40[v71];
              v72 = v40[v72];
              v23 = 4;
              HIDWORD(v74) = *(&v70 + v39);
            }
            else if ( (signed int)v13 < (signed int)(v15
                                                   + (unsigned __int64)((__int64 (*)(void))v5->m_provider->m_meshCInfo->vfptr->getNumTriangles)()) )
            {
              v5->m_provider->m_meshCInfo->vfptr->getIndices(
                v5->m_provider->m_meshCInfo,
                v13 - *(_DWORD *)(v14 + 8),
                (int *)&v73);
              LODWORD(v73) = v5->m_vMap.m_data[(signed int)v73];
              HIDWORD(v73) = v5->m_vMap.m_data[SHIDWORD(v73)];
              v23 = 3;
              LODWORD(v74) = v5->m_vMap.m_data[(signed int)v74];
            }
            else
            {
              v16 = *(_DWORD *)(v14 + 8);
              customPrimitive.m_maxError = 3.40282e38;
              customPrimitive.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
              v17 = v5->m_provider;
              *(_QWORD *)&customPrimitive.m_numVertices = 0i64;
              v18 = v17->m_meshCInfo;
              customPrimitive.m_layerData = 0;
              v19 = v18->vfptr;
              customPrimitive.m_aabb.m_max.m_quad = _mm_xor_ps(
                                                      (__m128)_mm_shuffle_epi32(
                                                                _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                0),
                                                      (__m128)xmmword_141A712A0);
              customPrimitive.m_tags.m_size = 0;
              customPrimitive.m_compression = 1;
              v20 = ((__int64 (*)(void))v19->getNumTriangles)();
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
                  v85 = v8 + 1;
                  v84[v8] = -1;
                  v8 = v85;
                }
                while ( v21 < v22 );
                v5 = v82;
              }
              v23 = v75;
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
                while ( v84[v27] != *((_DWORD *)&v73 + v24) )
                {
                  ++v27;
                  ++v26;
                  if ( v27 >= v8 )
                    goto LABEL_22;
                }
                if ( v26 == -1 )
                {
LABEL_22:
                  v41 = *((_DWORD *)&v73 + v24);
                  v85 = v8 + 1;
                  v84[v8] = v41;
                  v8 = v85;
                  if ( v85 == 256 )
                    break;
                }
                ++v24;
              }
              while ( v24 < v25 );
              v5 = v82;
            }
            v7 = customPrimitive.m_aabb.m_max.m_quad.m128_u64[1];
          }
          v9 = *v87;
          if ( *(_DWORD *)((char *)(*v87)->m_children + v12) )
          {
            v11 = *(unsigned __int64 *)((char *)v9->m_children + v12);
          }
          else
          {
            v42 = *(unsigned __int64 *)((char *)&v9->m_parent + v12);
            for ( i = v11; v42 != v7; v42 = v9[v42].m_parent )
            {
              if ( v9[v42].m_children[1] != i )
                break;
              i = v42;
            }
            if ( v42 )
              v11 = v9[v42].m_children[1];
            else
              v11 = i;
            if ( v42 == v7 && v11 == i )
              v11 = 0i64;
          }
        }
        while ( v11 );
        v6 = v86;
      }
    }
    else
    {
      v44 = *(signed int *)((char *)&v9->m_children[1] + v10);
      v45 = 0;
      v73 = 0i64;
      v74 = 0i64;
      v46 = v4->m_size;
      if ( (signed int)v44 < v46 )
      {
        v52 = v44;
        v53 = v4->m_data;
        v54 = v4->m_data[v52].m_edges[0];
        v55 = (signed int)((*(unsigned int *)&v54 >> 30) + 1) % 3;
        provider->m_provider->m_meshCInfo->vfptr->getIndices(
          provider->m_provider->m_meshCInfo,
          *(_DWORD *)&v54 & 0x3FFFFFFF,
          &v70);
        v56 = v5->m_vMap.m_data;
        v70 = v56[v70];
        v71 = v56[v71];
        v72 = v56[v72];
        LODWORD(v73) = *(&v70 + v55);
        v57 = (unsigned int)v53[v52].m_edges[0];
        v58 = (signed int)((v57 >> 30) + 2) % 3;
        v5->m_provider->m_meshCInfo->vfptr->getIndices(v5->m_provider->m_meshCInfo, v57 & 0x3FFFFFFF, &v70);
        v59 = v5->m_vMap.m_data;
        v70 = v59[v70];
        v71 = v59[v71];
        v72 = v59[v72];
        HIDWORD(v73) = *(&v70 + v58);
        v60 = ((*(_DWORD *)&v53[v52].m_edges[1] >> 30) + 1) % 3;
        v5->m_provider->m_meshCInfo->vfptr->getIndices(
          v5->m_provider->m_meshCInfo,
          *(_DWORD *)&v53[v52].m_edges[1] & 0x3FFFFFFF,
          &v70);
        v61 = v5->m_vMap.m_data;
        v70 = v61[v70];
        v71 = v61[v71];
        v72 = v61[v72];
        LODWORD(v74) = *(&v70 + v60);
        v62 = (unsigned int)v53[v52].m_edges[1];
        v63 = (signed int)((v62 >> 30) + 2) % 3;
        v5->m_provider->m_meshCInfo->vfptr->getIndices(v5->m_provider->m_meshCInfo, v62 & 0x3FFFFFFF, &v70);
        v64 = v5->m_vMap.m_data;
        v45 = 4;
        v70 = v64[v70];
        v71 = v64[v71];
        v72 = v64[v72];
        HIDWORD(v74) = *(&v70 + v63);
      }
      else if ( (signed int)v44 < (signed int)(v46
                                             + (unsigned __int64)((__int64 (*)(void))provider->m_provider->m_meshCInfo->vfptr->getNumTriangles)()) )
      {
        v5->m_provider->m_meshCInfo->vfptr->getIndices(v5->m_provider->m_meshCInfo, v44 - v4->m_size, (int *)&v73);
        v45 = 3;
        LODWORD(v73) = v5->m_vMap.m_data[(signed int)v73];
        HIDWORD(v73) = v5->m_vMap.m_data[SHIDWORD(v73)];
        LODWORD(v74) = v5->m_vMap.m_data[(signed int)v74];
      }
      else
      {
        v47 = v4->m_size;
        customPrimitive.m_maxError = FLOAT_3_40282e38;
        *(_QWORD *)&customPrimitive.m_numVertices = 0i64;
        customPrimitive.m_layerData = 0;
        customPrimitive.m_tags.m_size = 0;
        customPrimitive.m_compression = 1;
        customPrimitive.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
        v48 = v5->m_provider->m_meshCInfo;
        customPrimitive.m_aabb.m_max.m_quad = _mm_xor_ps(
                                                (__m128)_mm_shuffle_epi32(
                                                          _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                          0),
                                                (__m128)xmmword_141A712A0);
        v49 = ((__int64 (*)(void))v48->vfptr->getNumTriangles)();
        hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(
          v5->m_provider,
          v44 - v49 - v47,
          &customPrimitive);
        v50 = 0;
        for ( j = customPrimitive.m_tags.m_size + 2; v50 < j; v8 = v85 )
        {
          if ( v8 == 256 )
            break;
          ++v50;
          v85 = v8 + 1;
          v84[v8] = -1;
        }
      }
      v65 = 0i64;
      if ( v45 > 0 )
      {
        do
        {
          v66 = 0;
          v67 = 0i64;
          if ( v8 <= 0 )
            goto LABEL_53;
          while ( v84[v67] != *((_DWORD *)&v73 + v65) )
          {
            ++v67;
            ++v66;
            if ( v67 >= v8 )
              goto LABEL_53;
          }
          if ( v66 == -1 )
          {
LABEL_53:
            v68 = *((_DWORD *)&v73 + v65);
            v85 = v8 + 1;
            v84[v8] = v68;
            v8 = v85;
            if ( v85 == 256 )
              break;
          }
          ++v65;
        }
        while ( v65 < v45 );
      }
    }
  }
  v6->m_numVertices = v8;
  return (unsigned int)v8;
} }
        while ( v65 < v45 );
      }
    }
  }
  v6->m_numVertices = v8;
  return (unsigned int)v8;
}

