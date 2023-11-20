// File Line: 47
// RVA: 0xE09F30
bool __fastcall hkpBvCompressedMeshShapeGc::isKeyConvertionAllowed(hkpBvCompressedMeshShapeGc *this, unsigned int key)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *v2; // r11
  unsigned int v3; // er9
  __int64 v4; // rdx
  signed int v5; // eax
  __int64 v6; // r8
  unsigned int *v7; // rcx
  bool result; // al
  hkArray<unsigned int,hkContainerHeapAllocator> *v9; // rcx
  __int64 v10; // r8
  signed int v11; // eax
  __int64 v12; // rdx
  unsigned int *v13; // rcx

  v2 = this->m_includeKeys;
  v3 = key;
  if ( v2 )
  {
    v4 = v2->m_size;
    v5 = 0;
    v6 = 0i64;
    if ( v4 <= 0 )
    {
LABEL_6:
      v5 = -1;
    }
    else
    {
      v7 = v2->m_data;
      while ( *v7 != v3 )
      {
        ++v6;
        ++v5;
        ++v7;
        if ( v6 >= v4 )
          goto LABEL_6;
      }
    }
    result = v5 != -1;
  }
  else
  {
    v9 = this->m_excludeKeys;
    if ( v9 )
    {
      v10 = v9->m_size;
      v11 = 0;
      v12 = 0i64;
      if ( v10 <= 0 )
      {
LABEL_13:
        v11 = -1;
      }
      else
      {
        v13 = v9->m_data;
        while ( *v13 != v3 )
        {
          ++v12;
          ++v11;
          ++v13;
          if ( v12 >= v10 )
            goto LABEL_13;
        }
      }
      result = v11 == -1;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}

// File Line: 54
// RVA: 0xE070A0
void __fastcall hkpBvCompressedMeshShapeGc::appendCustomPrimitiveToGeometry(hkpBvCompressedMeshShapeGc *this, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Decoder *decoder, int primitiveIndex, hkGeometry *geometry)
{
  hkpBvCompressedMeshShapeTreeDataRun *v4; // r11
  int v5; // edi
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v6; // r15
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Decoder *v7; // rsi
  __int64 v8; // rbx
  hkGeometry *v9; // r13
  hkpBvCompressedMeshShapeGc *v10; // r12
  int v11; // er10
  hkpBvCompressedMeshShapeTreeDataRun *v12; // r14
  int v13; // er8
  int i; // edx
  int v15; // ecx
  signed int v16; // edx
  int v17; // er9
  signed __int64 v18; // rcx
  signed int v19; // er8
  int v20; // eax
  hkcdStaticMeshTreeBase::Primitive *v21; // rcx
  __int64 v22; // r14
  int v23; // edx
  int v24; // edx
  __int64 v25; // r8
  signed int v26; // er9
  __int64 v27; // rdx
  char *v28; // rcx
  const unsigned __int16 *v29; // r9
  __int64 v30; // r8
  unsigned int v31; // ecx
  unsigned __int16 v32; // dx
  signed int v33; // er10
  signed __int64 v34; // r9
  int v35; // ecx
  int v36; // ecx
  int v37; // ebx
  hkOstream *v38; // rax
  hkOstream *v39; // rax
  hkVector4f v40; // xmm5
  int v41; // ebx
  int v42; // er8
  __m128 v43; // xmm4
  signed __int64 v44; // r11
  hkAabb *v45; // r10
  unsigned int v46; // ecx
  __m128i v47; // xmm0
  __m128i v48; // xmm2
  __m128i v49; // xmm3
  int v50; // ecx
  int v51; // eax
  unsigned int v52; // eax
  __m128 *v53; // r10
  signed __int64 v54; // r9
  unsigned int v55; // ecx
  unsigned int v56; // eax
  hkVector4f v57; // xmm4
  __m128i v58; // xmm5
  __int64 v59; // rcx
  int v60; // er10
  int v61; // edx
  __m128i v62; // xmm6
  __m128i v63; // xmm7
  __m128 v64; // xmm3
  signed __int64 v65; // r11
  hkAabb *v66; // r8
  __m128i v67; // xmm1
  int v68; // eax
  __m128i v69; // xmm1
  __m128 *v70; // r8
  signed __int64 v71; // r9
  int v72; // eax
  unsigned int v73; // ecx
  __m128i v74; // xmm1
  __m128i v75; // xmm3
  __m128i v76; // xmm4
  __m128i v77; // xmm5
  signed __int64 v78; // r11
  int v79; // ecx
  hkAabb *v80; // rdx
  const __m128i *v81; // r8
  unsigned int v82; // eax
  __int64 v83; // r10
  __m128i v84; // xmm2
  __m128i v85; // xmm1
  __m128i v86; // xmm2
  __m128 v87; // xmm0
  __m128 *v88; // rdx
  signed __int64 v89; // r9
  __int64 v90; // rax
  __m128i v91; // xmm2
  hkVector4f v92; // xmm11
  hkVector4f v93; // xmm12
  __m128 v94; // xmm6
  __m128 v95; // xmm14
  __m128 v96; // xmm1
  __m128 v97; // xmm3
  __m128 v98; // xmm2
  __m128 v99; // xmm6
  __m128 v100; // xmm1
  __m128 v101; // xmm4
  float v102; // xmm1_4
  __m128 v103; // xmm7
  __m128 v104; // xmm2
  __m128 v105; // xmm8
  __m128 v106; // xmm2
  __m128 v107; // xmm6
  __m128 v108; // xmm6
  __m128 v109; // xmm1
  __m128 v110; // xmm3
  __m128 v111; // xmm2
  __m128 v112; // xmm1
  __m128 v113; // xmm6
  __m128 v114; // xmm10
  signed int v115; // ebx
  __m128i v116; // xmm6
  __m128 v117; // xmm9
  __m128i v118; // xmm8
  __m128 v119; // xmm9
  __m128 v120; // xmm2
  __m128i v121; // xmm6
  __m128 v122; // xmm1
  __m128 v123; // xmm5
  __m128 v124; // xmm4
  __m128 v125; // xmm2
  __m128 v126; // xmm0
  __m128 v127; // xmm4
  __m128 v128; // xmm3
  __m128 v129; // xmm5
  __m128 v130; // xmm1
  __m128 v131; // xmm3
  int v132; // ecx
  __m128 v133; // xmm6
  __m128 v134; // xmm6
  int v135; // ecx
  int v136; // er8
  hkVector4f *v137; // rdx
  unsigned __int16 v138; // dx
  signed int v139; // er10
  signed __int64 v140; // r9
  int v141; // ecx
  int v142; // ecx
  int v143; // ebx
  hkOstream *v144; // rax
  hkOstream *v145; // rax
  hkVector4f v146; // xmm5
  int v147; // ebx
  int v148; // er8
  __m128 v149; // xmm4
  signed __int64 v150; // r11
  hkAabb *v151; // r10
  unsigned int v152; // ecx
  __m128i v153; // xmm0
  __m128i v154; // xmm2
  __m128i v155; // xmm3
  int v156; // ecx
  int v157; // eax
  unsigned int v158; // eax
  __m128 *v159; // r10
  signed __int64 v160; // r9
  unsigned int v161; // ecx
  unsigned int v162; // eax
  hkVector4f v163; // xmm4
  __m128i v164; // xmm5
  __int64 v165; // rcx
  int v166; // er10
  int v167; // edx
  __m128i v168; // xmm6
  __m128i v169; // xmm7
  __m128 v170; // xmm3
  signed __int64 v171; // r11
  hkAabb *v172; // r8
  __m128i v173; // xmm1
  int v174; // eax
  __m128i v175; // xmm1
  __m128 *v176; // r8
  signed __int64 v177; // r9
  int v178; // eax
  unsigned int v179; // ecx
  __m128i v180; // xmm1
  __m128i v181; // xmm3
  __m128i v182; // xmm4
  __m128i v183; // xmm5
  signed __int64 v184; // r11
  int v185; // ecx
  hkAabb *v186; // rdx
  const __m128i *v187; // r8
  unsigned int v188; // eax
  __int64 v189; // r10
  __m128i v190; // xmm2
  __m128i v191; // xmm1
  __m128i v192; // xmm2
  __m128 v193; // xmm0
  __m128 *v194; // rdx
  signed __int64 v195; // r9
  __int64 v196; // rax
  __m128i v197; // xmm2
  hkVector4f v198; // xmm10
  hkVector4f v199; // xmm11
  __m128 v200; // xmm9
  __m128 v201; // xmm12
  __m128 v202; // xmm1
  __m128 v203; // xmm3
  __m128 v204; // xmm2
  __m128 v205; // xmm9
  __m128 v206; // xmm1
  __m128 v207; // xmm4
  float v208; // xmm1_4
  __m128 v209; // xmm7
  __m128 v210; // xmm2
  __m128 v211; // xmm8
  __m128 v212; // xmm6
  __m128 v213; // xmm2
  __m128 v214; // xmm6
  __m128 v215; // xmm1
  __m128 v216; // xmm3
  __m128 v217; // xmm2
  __m128 v218; // xmm1
  __m128 v219; // xmm6
  signed int v220; // er14
  signed int v221; // esi
  __m128 v222; // xmm7
  int v223; // ecx
  __m128 v224; // xmm1
  hkVector4f *v225; // rbx
  __m128 v226; // xmm1
  __m128 v227; // xmm5
  __m128 v228; // xmm4
  __m128 v229; // xmm6
  __m128 v230; // xmm6
  __m128 v231; // xmm2
  __m128 v232; // xmm0
  unsigned __int16 v233; // dx
  signed int v234; // ebx
  signed __int64 v235; // r9
  int v236; // ecx
  int v237; // ecx
  int v238; // ebx
  hkOstream *v239; // rax
  hkOstream *v240; // rax
  hkVector4f v241; // xmm5
  int v242; // ebx
  int v243; // er8
  __m128 v244; // xmm4
  signed __int64 v245; // r11
  hkAabb *v246; // r10
  unsigned int v247; // ecx
  __m128i v248; // xmm0
  __m128i v249; // xmm2
  __m128i v250; // xmm3
  int v251; // ecx
  int v252; // eax
  unsigned int v253; // eax
  __m128 *v254; // r10
  signed __int64 v255; // r9
  unsigned int v256; // ecx
  unsigned int v257; // eax
  hkVector4f v258; // xmm4
  __m128i v259; // xmm5
  __int64 v260; // rcx
  int v261; // ebx
  int v262; // edx
  __m128i v263; // xmm6
  __m128i v264; // xmm7
  __m128 v265; // xmm3
  signed __int64 v266; // r10
  hkAabb *v267; // r8
  __m128i v268; // xmm1
  int v269; // eax
  __m128i v270; // xmm1
  __m128 *v271; // r8
  signed __int64 v272; // r9
  int v273; // eax
  unsigned int v274; // ecx
  __m128i v275; // xmm1
  __m128i v276; // xmm3
  __m128i v277; // xmm4
  __m128i v278; // xmm5
  signed __int64 v279; // r11
  int v280; // ecx
  hkAabb *v281; // rdx
  const __m128i *v282; // r8
  unsigned int v283; // eax
  __int64 v284; // r10
  __m128i v285; // xmm2
  __m128i v286; // xmm1
  __m128i v287; // xmm2
  __m128 v288; // xmm0
  __m128 *v289; // rdx
  signed __int64 v290; // r9
  __int64 v291; // rax
  __m128i v292; // xmm2
  int v293; // edx
  __m128 v294; // xmm8
  signed int v295; // er14
  hkVector4f v296; // xmm9
  signed int v297; // esi
  __m128 v298; // xmm6
  int v299; // ecx
  __m128 v300; // xmm1
  hkVector4f *v301; // rbx
  unsigned __int16 v302; // r10
  signed int v303; // edx
  signed __int64 v304; // r9
  int v305; // ecx
  int v306; // ecx
  int v307; // ebx
  hkOstream *v308; // rax
  hkOstream *v309; // rax
  hkVector4f v310; // xmm5
  int v311; // er8
  __m128 v312; // xmm4
  signed __int64 v313; // r11
  hkVector4f *v314; // r10
  unsigned int v315; // ecx
  __m128i v316; // xmm0
  __m128i v317; // xmm2
  __m128i v318; // xmm3
  int v319; // ecx
  int v320; // eax
  unsigned int v321; // eax
  hkVector4f *v322; // r10
  signed __int64 v323; // r9
  unsigned int v324; // ecx
  unsigned int v325; // eax
  hkVector4f v326; // xmm4
  __m128i v327; // xmm5
  __int64 v328; // rcx
  int v329; // er10
  __m128i v330; // xmm6
  __m128i v331; // xmm7
  __m128 v332; // xmm3
  signed __int64 v333; // r8
  hkVector4f *v334; // rdx
  __m128i v335; // xmm1
  int v336; // eax
  __m128i v337; // xmm1
  hkVector4f *v338; // rdx
  signed __int64 v339; // r9
  int v340; // eax
  unsigned int v341; // ecx
  __m128i v342; // xmm1
  __m128i v343; // xmm3
  __m128i v344; // xmm4
  __m128i v345; // xmm5
  signed __int64 v346; // r10
  int v347; // eax
  hkVector4f *v348; // rcx
  const __m128i *v349; // rdx
  unsigned int v350; // eax
  __int64 v351; // r8
  __m128i v352; // xmm2
  __m128i v353; // xmm2
  hkVector4f *v354; // rcx
  signed __int64 v355; // r9
  __int64 v356; // rax
  __m128i v357; // xmm2
  __m128 v358; // xmm5
  hkVector4f *array; // [rsp+30h] [rbp-D0h]
  int numVertices; // [rsp+38h] [rbp-C8h]
  int v361; // [rsp+3Ch] [rbp-C4h]
  hkAabb aabb; // [rsp+40h] [rbp-C0h]
  hkVector4f *vertices; // [rsp+60h] [rbp-A0h]
  int v364; // [rsp+68h] [rbp-98h]
  int v365; // [rsp+6Ch] [rbp-94h]
  hkVector4f *v366; // [rsp+70h] [rbp-90h]
  int v367; // [rsp+78h] [rbp-88h]
  int v368; // [rsp+7Ch] [rbp-84h]
  hkResult v369; // [rsp+80h] [rbp-80h]
  hkResult result; // [rsp+84h] [rbp-7Ch]
  hkQuaternionf v371; // [rsp+90h] [rbp-70h]
  hkResult v372; // [rsp+A0h] [rbp-60h]
  hkQuaternionf v373; // [rsp+B0h] [rbp-50h]
  hkVector4f from; // [rsp+C0h] [rbp-40h]
  hkErrStream v375; // [rsp+D0h] [rbp-30h]
  hkVector4f v376; // [rsp+F0h] [rbp-10h]
  hkErrStream v377; // [rsp+100h] [rbp+0h]
  hkVector4f v378; // [rsp+120h] [rbp+20h]
  hkErrStream v379; // [rsp+130h] [rbp+30h]
  hkVector4f uv; // [rsp+150h] [rbp+50h]
  hkErrStream v381; // [rsp+160h] [rbp+60h]
  hkErrStream v382; // [rsp+178h] [rbp+78h]
  hkVector4f v383; // [rsp+190h] [rbp+90h]
  __m128 v384; // [rsp+1A0h] [rbp+A0h]
  __m128 v385; // [rsp+1B0h] [rbp+B0h]
  __m128 v386; // [rsp+1C0h] [rbp+C0h]
  __m128 v387; // [rsp+1D0h] [rbp+D0h]
  __m128 v388; // [rsp+1E0h] [rbp+E0h]
  __m128 v389; // [rsp+1F0h] [rbp+F0h]
  __m128 v390; // [rsp+200h] [rbp+100h]
  __m128 v391; // [rsp+210h] [rbp+110h]
  __int128 v392; // [rsp+220h] [rbp+120h]
  __int128 v393; // [rsp+230h] [rbp+130h]
  __m128 v394; // [rsp+240h] [rbp+140h]
  __int128 v395; // [rsp+250h] [rbp+150h]
  __int128 v396; // [rsp+260h] [rbp+160h]
  __int128 v397; // [rsp+270h] [rbp+170h]
  __int128 v398; // [rsp+280h] [rbp+180h]
  __int128 v399; // [rsp+290h] [rbp+190h]
  __int128 v400; // [rsp+2A0h] [rbp+1A0h]
  __int128 v401; // [rsp+2B0h] [rbp+1B0h]
  __m128 v402; // [rsp+2C0h] [rbp+1C0h]
  __int128 v403; // [rsp+2D0h] [rbp+1D0h]
  __int128 v404; // [rsp+2E0h] [rbp+1E0h]
  __int128 v405; // [rsp+2F0h] [rbp+1F0h]
  __int128 v406; // [rsp+300h] [rbp+200h]
  __int128 v407; // [rsp+310h] [rbp+210h]
  __int128 v408; // [rsp+320h] [rbp+220h]
  hkVector4f v409; // [rsp+330h] [rbp+230h]
  __m128 v410; // [rsp+340h] [rbp+240h]
  __int128 v411; // [rsp+350h] [rbp+250h]
  hkVector4f v412; // [rsp+360h] [rbp+260h]
  __m128 v413; // [rsp+370h] [rbp+270h]
  __int128 v414; // [rsp+380h] [rbp+280h]
  hkVector4f v415; // [rsp+390h] [rbp+290h]
  __m128 v416; // [rsp+3A0h] [rbp+2A0h]
  __m128 v417; // [rsp+3B0h] [rbp+2B0h]
  hkVector4f v418; // [rsp+3C0h] [rbp+2C0h]
  __m128 v419; // [rsp+3D0h] [rbp+2D0h]
  __int128 v420; // [rsp+3E0h] [rbp+2E0h]
  hkVector4f v421; // [rsp+3F0h] [rbp+2F0h]
  __m128 v422; // [rsp+400h] [rbp+300h]
  __int128 v423; // [rsp+410h] [rbp+310h]
  hkVector4f v424; // [rsp+420h] [rbp+320h]
  __m128 v425; // [rsp+430h] [rbp+330h]
  __m128 v426; // [rsp+440h] [rbp+340h]
  hkVector4f v427; // [rsp+450h] [rbp+350h]
  __m128 v428; // [rsp+460h] [rbp+360h]
  __int128 v429; // [rsp+470h] [rbp+370h]
  hkVector4f v430; // [rsp+480h] [rbp+380h]
  __m128 v431; // [rsp+490h] [rbp+390h]
  __int128 v432; // [rsp+4A0h] [rbp+3A0h]
  __m128 v433; // [rsp+4B0h] [rbp+3B0h]
  __int128 v434; // [rsp+4C0h] [rbp+3C0h]
  __int128 v435; // [rsp+4D0h] [rbp+3D0h]
  __m128 v436; // [rsp+4E0h] [rbp+3E0h]
  __int128 v437; // [rsp+4F0h] [rbp+3F0h]
  __m128 v438; // [rsp+500h] [rbp+400h]
  char buf; // [rsp+510h] [rbp+410h]
  char v440; // [rsp+710h] [rbp+610h]
  char v441; // [rsp+910h] [rbp+810h]
  char description; // [rsp+B10h] [rbp+A10h]
  char v443; // [rsp+D10h] [rbp+C10h]
  unsigned int v444; // [rsp+FF8h] [rbp+EF8h]
  float v445; // [rsp+FF8h] [rbp+EF8h]
  float v446; // [rsp+FF8h] [rbp+EF8h]
  float v447; // [rsp+FF8h] [rbp+EF8h]
  unsigned int v448; // [rsp+FF8h] [rbp+EF8h]
  float v449; // [rsp+FF8h] [rbp+EF8h]
  float v450; // [rsp+FF8h] [rbp+EF8h]
  int material; // [rsp+1000h] [rbp+F00h]

  v4 = decoder->m_primitiveDataRuns;
  v5 = 0;
  v6 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)&decoder->m_section->m_nodes;
  v7 = decoder;
  v8 = primitiveIndex;
  v9 = geometry;
  v10 = this;
  v11 = (unsigned __int8)v6[1].m_domain.m_max.m_quad.m128_i8[4] - 1;
  v12 = 0i64;
  v13 = 0;
  for ( i = (unsigned __int8)v6[1].m_domain.m_max.m_quad.m128_i8[4]; i > 4; i = v11 - v13 + 1 )
  {
    v15 = (v11 + v13) >> 1;
    v16 = v8 - (unsigned __int8)v4[v15].m_index;
    if ( v16 < 0 )
    {
      v11 = (v11 + v13) >> 1;
    }
    else
    {
      if ( v16 < (unsigned __int8)v4[v15].m_count )
      {
        v12 = &v4[v15];
        goto LABEL_14;
      }
      v13 = v15 + 1;
    }
  }
  v17 = 0;
  v18 = (signed __int64)&v4[v13];
  if ( i > 0 )
  {
    while ( 1 )
    {
      v19 = v8 - *(unsigned __int8 *)(v18 + 4);
      if ( v19 >= 0 && v19 < *(unsigned __int8 *)(v18 + 5) )
        break;
      ++v17;
      v18 += 8i64;
      if ( v17 >= i )
        goto LABEL_14;
    }
    v12 = (hkpBvCompressedMeshShapeTreeDataRun *)v18;
  }
LABEL_14:
  v20 = v12->m_value;
  v21 = v7->m_primitives;
  v22 = v8;
  v23 = (unsigned __int8)v21[v8].m_indices[2];
  material = v20;
  if ( (unsigned __int8)v21[v8].m_indices[3] != v23 || v23 != (unsigned __int8)v21[v8].m_indices[1] )
  {
    v25 = v6->m_nodes.m_size;
    v26 = 0;
    v27 = 0i64;
    if ( v25 <= 0 )
    {
LABEL_22:
      v26 = -1;
    }
    else
    {
      v28 = &v6->m_nodes.m_data->m_data;
      while ( *v28 & 1 || (_DWORD)v8 != (unsigned int)(unsigned __int8)*v28 >> 1 )
      {
        ++v27;
        ++v26;
        v28 += 4;
        if ( v27 >= v25 )
          goto LABEL_22;
      }
    }
    v24 = v26;
  }
  else
  {
    v24 = (unsigned __int8)v21[v8].m_indices[1];
  }
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(v6, v24, &aabb);
  v29 = v7->m_sharedVerticesIndex;
  v30 = (unsigned __int8)v7->m_primitives[v8].m_indices[0];
  v31 = v29[v30];
  if ( v29[v30] & 0xF )
  {
    switch ( v29[v30] & 0xF )
    {
      case 1:
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendCustomPrimitiveToGeometry(
          (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *)&v10->vfptr,
          v7,
          v8,
          v9);
        return;
      case 2:
        v233 = v29[v30 + 1];
        v234 = 1;
        if ( (signed int)(v31 >> 8) < 1 )
          v234 = v31 >> 8;
        v235 = v234;
        v236 = (v31 >> 4) & 3;
        if ( v236 )
        {
          v237 = v236 - 1;
          if ( v237 )
          {
            if ( v237 == 1 )
            {
              v241.m_quad = (__m128)aabb.m_min;
              v242 = v234 - 1;
              v243 = 0;
              v421.m_quad = (__m128)aabb.m_min;
              v244 = _mm_mul_ps(
                       _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                       (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters'::`2'::invBitScalesBuffer);
              v422 = v244;
              v245 = (signed __int64)&v7->m_sharedVertices[v233];
              if ( v242 > 0 )
              {
                v246 = &aabb;
                do
                {
                  ++v246;
                  v247 = *(unsigned __int16 *)(v245 + 2i64 * (signed int)((v243 & 0xFFFFFFFC) - (v243 & 3) + 3));
                  v248 = _mm_cvtsi32_si128(v247 >> 10);
                  v249 = _mm_cvtsi32_si128((v247 >> 5) & 0x1F);
                  v250 = _mm_cvtsi32_si128(*(_WORD *)(v245 + 2i64 * (signed int)((v243 & 0xFFFFFFFC) - (v243 & 3) + 3)) & 0x1F);
                  v251 = v243 + 1;
                  v252 = (v243 + 1) & 3;
                  v243 += 2;
                  v253 = *(unsigned __int16 *)(v245 + 2i64 * (signed int)((v251 & 0xFFFFFFFC) - v252 + 3));
                  v246[-1].m_min.m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_cvtepi32_ps(
                                                _mm_unpacklo_epi32(
                                                  _mm_unpacklo_epi32(v250, v248),
                                                  _mm_unpacklo_epi32(v249, _mm_cvtsi32_si128(0)))),
                                              v244),
                                            v241.m_quad);
                  v246[-1].m_max.m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_cvtepi32_ps(
                                                _mm_unpacklo_epi32(
                                                  _mm_unpacklo_epi32(
                                                    _mm_cvtsi32_si128(v253 & 0x1F),
                                                    _mm_cvtsi32_si128(v253 >> 10)),
                                                  _mm_unpacklo_epi32(
                                                    _mm_cvtsi32_si128((v253 >> 5) & 0x1F),
                                                    _mm_cvtsi32_si128(0)))),
                                              v244),
                                            v241.m_quad);
                }
                while ( v243 < v242 );
              }
              if ( v243 < v235 )
              {
                v254 = &aabb.m_min.m_quad + v243;
                v255 = v235 - v243;
                do
                {
                  ++v254;
                  v256 = (v243 & 0xFFFFFFFC) - (v243 & 3);
                  ++v243;
                  v257 = *(unsigned __int16 *)(v245 + 2i64 * (signed int)(v256 + 3));
                  v254[-1] = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(
                                       _mm_cvtsi32_si128(*(_WORD *)(v245 + 2i64 * (signed int)(v256 + 3)) & 0x1F),
                                       _mm_cvtsi32_si128(v257 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v257 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                 v244),
                               v241.m_quad);
                  --v255;
                }
                while ( v255 );
              }
            }
            else
            {
              hkErrStream::hkErrStream(&v381, &v441, 512);
              v238 = ((unsigned int)v7->m_sharedVerticesIndex[(unsigned __int8)v7->m_primitives[v22].m_indices[0]] >> 4) & 3;
              v239 = hkOstream::operator<<((hkOstream *)&v381.vfptr, "Compression method #");
              v240 = hkOstream::operator<<(v239, v238, (int)v239);
              hkOstream::operator<<(v240, " not implemented");
              if ( (unsigned int)hkError::messageError(
                                   -1875965459,
                                   &v441,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTre"
                                   "e/hkcdStaticMeshTree.inl",
                                   499) )
                __debugbreak();
              hkOstream::~hkOstream((hkOstream *)&v381.vfptr);
            }
          }
          else
          {
            v258.m_quad = (__m128)aabb.m_min;
            v259 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
            v260 = v233;
            v261 = v234 - 1;
            v262 = 0;
            v263 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
            v264 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
            v424.m_quad = (__m128)aabb.m_min;
            v265 = _mm_mul_ps(
                     _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                     (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters'::`2'::invBitScalesBuffer);
            v425 = v265;
            v266 = (signed __int64)&v7->m_sharedVertices[v260];
            if ( v261 > 0 )
            {
              v267 = &aabb;
              do
              {
                ++v267;
                v268 = (__m128i)*(unsigned int *)(v266 + 4i64 * (signed int)((v262 & 0xFFFFFFFE) - (v262 & 1) + 1));
                v269 = v262 + 1;
                v262 += 2;
                _mm_store_si128((__m128i *)&v406, v268);
                v267[-1].m_min.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_cvtepi32_ps(
                                              _mm_or_si128(
                                                _mm_or_si128(
                                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v268, 0x16u), 0), v259),
                                                  _mm_and_si128(v268, v264)),
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v268, 0xBu), 0), v263))),
                                            v265),
                                          v258.m_quad);
                v270 = (__m128i)*(unsigned int *)(v266 + 4i64 * (signed int)((v269 & 0xFFFFFFFE) - (v269 & 1) + 1));
                _mm_store_si128((__m128i *)&v437, v270);
                v267[-1].m_max.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_cvtepi32_ps(
                                              _mm_or_si128(
                                                _mm_or_si128(
                                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v270, 0x16u), 0), v259),
                                                  _mm_and_si128(v270, v264)),
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v270, 0xBu), 0), v263))),
                                            v265),
                                          v258.m_quad);
              }
              while ( v262 < v261 );
            }
            if ( v262 < v235 )
            {
              v271 = &aabb.m_min.m_quad + v262;
              v272 = v235 - v262;
              do
              {
                ++v271;
                v273 = v262 & 1;
                v274 = v262++ & 0xFFFFFFFE;
                v275 = (__m128i)*(unsigned int *)(v266 + 4i64 * (signed int)(v274 - v273 + 1));
                _mm_store_si128((__m128i *)&v408, v275);
                v271[-1] = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v275, 0x16u), 0), v259),
                                     _mm_and_si128(v275, v264)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v275, 0xBu), 0), v263))),
                               v265),
                             v258.m_quad);
                --v272;
              }
              while ( v272 );
            }
          }
        }
        else
        {
          v276 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
          v277 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
          v278 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
          v279 = (signed __int64)&v7->m_sharedVertices[v233];
          v280 = 0;
          if ( v234 - 1 > 0 )
          {
            v281 = &aabb;
            v282 = (const __m128i *)v279;
            v283 = ((unsigned int)(v234 - 2) >> 1) + 1;
            v284 = v283;
            v280 = 2 * v283;
            do
            {
              v285 = _mm_loadl_epi64(v282);
              ++v281;
              ++v282;
              _mm_store_si128((__m128i *)&v429, v285);
              v286 = _mm_or_si128(
                       _mm_or_si128(
                         _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v285, 0xAu), 85), v276),
                         _mm_and_si128(v285, v278)),
                       _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v285, 2), 5u), v277));
              v287 = _mm_loadl_epi64((const __m128i *)((char *)v282 - 8));
              v288 = _mm_add_ps(
                       _mm_mul_ps(_mm_cvtepi32_ps(v286), v7->m_sharedParms.m_scale.m_quad),
                       v7->m_sharedParms.m_origin.m_quad);
              _mm_store_si128((__m128i *)&v411, v287);
              v281[-1].m_min.m_quad = v288;
              v281[-1].m_max.m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_cvtepi32_ps(
                                            _mm_or_si128(
                                              _mm_or_si128(
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v287, 0xAu), 85), v276),
                                                _mm_and_si128(v287, v278)),
                                              _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v287, 2), 5u), v277))),
                                          v7->m_sharedParms.m_scale.m_quad),
                                        v7->m_sharedParms.m_origin.m_quad);
              --v284;
            }
            while ( v284 );
          }
          if ( v280 < (signed __int64)v234 )
          {
            v289 = &aabb.m_min.m_quad + v280;
            v290 = v234 - (signed __int64)v280;
            do
            {
              v291 = v280;
              ++v289;
              ++v280;
              v292 = _mm_loadl_epi64((const __m128i *)(v279 + 8 * v291));
              _mm_store_si128((__m128i *)&v435, v292);
              v289[-1] = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v292, 0xAu), 85), v276),
                                   _mm_and_si128(v292, v278)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v292, 2), 5u), v277))),
                             v7->m_sharedParms.m_scale.m_quad),
                           v7->m_sharedParms.m_origin.m_quad);
              --v290;
            }
            while ( v290 );
          }
        }
        v293 = (signed __int16)v7->m_sharedVerticesIndex[(unsigned __int8)v7->m_primitives[v22].m_indices[0] + 2];
        v366 = 0i64;
        v367 = 0;
        v368 = 2147483648;
        v294 = _mm_shuffle_ps((__m128)(unsigned int)(v293 << 16), (__m128)(unsigned int)(v293 << 16), 0);
        hkArrayUtil::_reserve(&v369, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v366, 144, 16);
        v295 = 0;
        v296.m_quad = (__m128)aabb.m_min;
        do
        {
          v297 = 0;
          v298 = (__m128)COERCE_UNSIGNED_INT((float)v295);
          v298.m128_f32[0] = v298.m128_f32[0] * 0.090909094;
          do
          {
            v299 = v367;
            v300 = (__m128)COERCE_UNSIGNED_INT((float)v297);
            v300.m128_f32[0] = v300.m128_f32[0] * 0.090909094;
            v378.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v298, (__m128)0i64), _mm_unpacklo_ps(v300, (__m128)0i64));
            if ( v367 == (v368 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v366, 16);
              v299 = v367;
            }
            v367 = v299 + 1;
            v301 = &v366[v299];
            hkGeometryProcessing::octahedronToNormal(&v378, v301);
            ++v297;
            v301->m_quad = _mm_add_ps(_mm_mul_ps(v294, v301->m_quad), v296.m_quad);
          }
          while ( v297 < 12 );
          ++v295;
        }
        while ( v295 < 12 );
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
          v366,
          v367,
          material,
          v9);
        v367 = 0;
        if ( v368 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v366,
            16 * v368);
        break;
      case 3:
        v138 = v29[v30 + 1];
        v139 = 2;
        if ( (signed int)(v31 >> 8) < 2 )
          v139 = v31 >> 8;
        v140 = v139;
        v141 = (v31 >> 4) & 3;
        if ( v141 )
        {
          v142 = v141 - 1;
          if ( v142 )
          {
            if ( v142 == 1 )
            {
              v146.m_quad = (__m128)aabb.m_min;
              v147 = v139 - 1;
              v148 = 0;
              v415.m_quad = (__m128)aabb.m_min;
              v149 = _mm_mul_ps(
                       _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                       (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters'::`2'::invBitScalesBuffer);
              v416 = v149;
              v150 = (signed __int64)&v7->m_sharedVertices[v138];
              if ( v139 - 1 > 0 )
              {
                v151 = &aabb;
                do
                {
                  ++v151;
                  v152 = *(unsigned __int16 *)(v150 + 2i64 * (signed int)((v148 & 0xFFFFFFFC) - (v148 & 3) + 3));
                  v153 = _mm_cvtsi32_si128(v152 >> 10);
                  v154 = _mm_cvtsi32_si128((v152 >> 5) & 0x1F);
                  v155 = _mm_cvtsi32_si128(*(_WORD *)(v150 + 2i64 * (signed int)((v148 & 0xFFFFFFFC) - (v148 & 3) + 3)) & 0x1F);
                  v156 = v148 + 1;
                  v157 = (v148 + 1) & 3;
                  v148 += 2;
                  v158 = *(unsigned __int16 *)(v150 + 2i64 * (signed int)((v156 & 0xFFFFFFFC) - v157 + 3));
                  v151[-1].m_min.m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_cvtepi32_ps(
                                                _mm_unpacklo_epi32(
                                                  _mm_unpacklo_epi32(v155, v153),
                                                  _mm_unpacklo_epi32(v154, _mm_cvtsi32_si128(0)))),
                                              v149),
                                            v146.m_quad);
                  v151[-1].m_max.m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_cvtepi32_ps(
                                                _mm_unpacklo_epi32(
                                                  _mm_unpacklo_epi32(
                                                    _mm_cvtsi32_si128(v158 & 0x1F),
                                                    _mm_cvtsi32_si128(v158 >> 10)),
                                                  _mm_unpacklo_epi32(
                                                    _mm_cvtsi32_si128((v158 >> 5) & 0x1F),
                                                    _mm_cvtsi32_si128(0)))),
                                              v149),
                                            v146.m_quad);
                }
                while ( v148 < v147 );
              }
              if ( v148 < v140 )
              {
                v159 = &aabb.m_min.m_quad + v148;
                v160 = v140 - v148;
                do
                {
                  ++v159;
                  v161 = (v148 & 0xFFFFFFFC) - (v148 & 3);
                  ++v148;
                  v162 = *(unsigned __int16 *)(v150 + 2i64 * (signed int)(v161 + 3));
                  v159[-1] = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(
                                       _mm_cvtsi32_si128(*(_WORD *)(v150 + 2i64 * (signed int)(v161 + 3)) & 0x1F),
                                       _mm_cvtsi32_si128(v162 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v162 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                 v149),
                               v146.m_quad);
                  --v160;
                }
                while ( v160 );
              }
            }
            else
            {
              hkErrStream::hkErrStream(&v379, &v440, 512);
              v143 = ((unsigned int)v7->m_sharedVerticesIndex[(unsigned __int8)v7->m_primitives[v8].m_indices[0]] >> 4) & 3;
              v144 = hkOstream::operator<<((hkOstream *)&v379.vfptr, "Compression method #");
              v145 = hkOstream::operator<<(v144, v143, (int)v144);
              hkOstream::operator<<(v145, " not implemented");
              if ( (unsigned int)hkError::messageError(
                                   -1875965459,
                                   &v440,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTre"
                                   "e/hkcdStaticMeshTree.inl",
                                   499) )
                __debugbreak();
              hkOstream::~hkOstream((hkOstream *)&v379.vfptr);
            }
          }
          else
          {
            v163.m_quad = (__m128)aabb.m_min;
            v164 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
            v165 = v138;
            v166 = v139 - 1;
            v167 = 0;
            v168 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
            v169 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
            v418.m_quad = (__m128)aabb.m_min;
            v170 = _mm_mul_ps(
                     _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                     (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters'::`2'::invBitScalesBuffer);
            v419 = v170;
            v171 = (signed __int64)&v7->m_sharedVertices[v165];
            if ( v166 > 0 )
            {
              v172 = &aabb;
              do
              {
                ++v172;
                v173 = (__m128i)*(unsigned int *)(v171 + 4i64 * (signed int)((v167 & 0xFFFFFFFE) - (v167 & 1) + 1));
                v174 = v167 + 1;
                v167 += 2;
                _mm_store_si128((__m128i *)&v396, v173);
                v172[-1].m_min.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_cvtepi32_ps(
                                              _mm_or_si128(
                                                _mm_or_si128(
                                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v173, 0x16u), 0), v164),
                                                  _mm_and_si128(v173, v169)),
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v173, 0xBu), 0), v168))),
                                            v170),
                                          v163.m_quad);
                v175 = (__m128i)*(unsigned int *)(v171 + 4i64 * (signed int)((v174 & 0xFFFFFFFE) - (v174 & 1) + 1));
                _mm_store_si128((__m128i *)&v420, v175);
                v172[-1].m_max.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_cvtepi32_ps(
                                              _mm_or_si128(
                                                _mm_or_si128(
                                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v175, 0x16u), 0), v164),
                                                  _mm_and_si128(v175, v169)),
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v175, 0xBu), 0), v168))),
                                            v170),
                                          v163.m_quad);
              }
              while ( v167 < v166 );
            }
            if ( v167 < v140 )
            {
              v176 = &aabb.m_min.m_quad + v167;
              v177 = v140 - v167;
              do
              {
                ++v176;
                v178 = v167 & 1;
                v179 = v167++ & 0xFFFFFFFE;
                v180 = (__m128i)*(unsigned int *)(v171 + 4i64 * (signed int)(v179 - v178 + 1));
                _mm_store_si128((__m128i *)&v398, v180);
                v176[-1] = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v180, 0x16u), 0), v164),
                                     _mm_and_si128(v180, v169)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v180, 0xBu), 0), v168))),
                               v170),
                             v163.m_quad);
                --v177;
              }
              while ( v177 );
            }
          }
        }
        else
        {
          v181 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
          v182 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
          v183 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
          v184 = (signed __int64)&v7->m_sharedVertices[v138];
          v185 = 0;
          if ( v139 - 1 > 0 )
          {
            v186 = &aabb;
            v187 = (const __m128i *)v184;
            v188 = ((unsigned int)(v139 - 2) >> 1) + 1;
            v189 = v188;
            v185 = 2 * v188;
            do
            {
              v190 = _mm_loadl_epi64(v187);
              ++v186;
              ++v187;
              _mm_store_si128((__m128i *)&v434, v190);
              v191 = _mm_or_si128(
                       _mm_or_si128(
                         _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v190, 0xAu), 85), v181),
                         _mm_and_si128(v190, v183)),
                       _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v190, 2), 5u), v182));
              v192 = _mm_loadl_epi64((const __m128i *)((char *)v187 - 8));
              v193 = _mm_add_ps(
                       _mm_mul_ps(_mm_cvtepi32_ps(v191), v7->m_sharedParms.m_scale.m_quad),
                       v7->m_sharedParms.m_origin.m_quad);
              _mm_store_si128((__m128i *)&v400, v192);
              v186[-1].m_min.m_quad = v193;
              v186[-1].m_max.m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_cvtepi32_ps(
                                            _mm_or_si128(
                                              _mm_or_si128(
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v192, 0xAu), 85), v181),
                                                _mm_and_si128(v192, v183)),
                                              _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v192, 2), 5u), v182))),
                                          v7->m_sharedParms.m_scale.m_quad),
                                        v7->m_sharedParms.m_origin.m_quad);
              --v189;
            }
            while ( v189 );
          }
          if ( v185 < v140 )
          {
            v194 = &aabb.m_min.m_quad + v185;
            v195 = v140 - v185;
            do
            {
              v196 = v185;
              ++v194;
              ++v185;
              v197 = _mm_loadl_epi64((const __m128i *)(v184 + 8 * v196));
              _mm_store_si128((__m128i *)&v423, v197);
              v194[-1] = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v197, 0xAu), 85), v181),
                                   _mm_and_si128(v197, v183)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v197, 2), 5u), v182))),
                             v7->m_sharedParms.m_scale.m_quad),
                           v7->m_sharedParms.m_origin.m_quad);
              --v195;
            }
            while ( v195 );
          }
        }
        v198.m_quad = (__m128)aabb.m_max;
        v199.m_quad = (__m128)aabb.m_min;
        v448 = (signed __int16)v7->m_sharedVerticesIndex[(unsigned __int8)v7->m_primitives[v22].m_indices[0] + 2] << 16;
        v200 = _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad);
        v376.m_quad = _xmm;
        v201 = _mm_shuffle_ps((__m128)v448, (__m128)v448, 0);
        v202 = _mm_mul_ps(v200, v200);
        v203 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v202, v202, 85), _mm_shuffle_ps(v202, v202, 0)),
                 _mm_shuffle_ps(v202, v202, 170));
        v204 = _mm_rsqrt_ps(v203);
        v402 = v203;
        v205 = _mm_mul_ps(
                 v200,
                 _mm_andnot_ps(
                   _mm_cmpleps(v203, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v204, v203), v204)),
                     _mm_mul_ps(v204, *(__m128 *)_xmm))));
        v206 = _mm_mul_ps(_xmm, v205);
        v207 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v206, v206, 85), _mm_shuffle_ps(v206, v206, 0)),
                 _mm_shuffle_ps(v206, v206, 170));
        v449 = FLOAT_0_99998999;
        LODWORD(v208) = (unsigned __int128)_mm_shuffle_ps(
                                             (__m128)LODWORD(FLOAT_0_99998999),
                                             (__m128)LODWORD(FLOAT_0_99998999),
                                             0);
        if ( v207.m128_f32[0] <= v208 )
        {
          if ( v207.m128_f32[0] >= (float)(0.0 - v208) )
          {
            v209 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v207), (__m128)xmmword_141A711B0);
            v210 = _mm_rsqrt_ps(v209);
            v438 = v209;
            v211 = _mm_andnot_ps(
                     _mm_cmpleps(v209, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v210, v209), v210)),
                       _mm_mul_ps(v210, *(__m128 *)_xmm)));
            v212 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v205, v205, 201), _xmm),
                     _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 201), v205));
            v213 = _mm_mul_ps(v211, (__m128)xmmword_141A711B0);
            v450 = FLOAT_N0_99900001;
            v214 = _mm_shuffle_ps(v212, v212, 201);
            if ( v207.m128_f32[0] < COERCE_FLOAT(
                                      _mm_shuffle_ps(
                                        (__m128)LODWORD(FLOAT_N0_99900001),
                                        (__m128)LODWORD(FLOAT_N0_99900001),
                                        0)) )
            {
              v215 = _mm_mul_ps(v214, v214);
              v391 = _mm_sub_ps(v209, v207);
              v216 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v215, v215, 85), _mm_shuffle_ps(v215, v215, 0)),
                       _mm_shuffle_ps(v215, v215, 170));
              v217 = _mm_rsqrt_ps(v216);
              v426 = v216;
              v218 = _mm_rsqrt_ps(v391);
              v213 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v391, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v218, v391), v218)),
                             _mm_mul_ps(*(__m128 *)_xmm, v218))),
                         v391),
                       _mm_andnot_ps(
                         _mm_cmpleps(v216, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v217, v216), v217)),
                           _mm_mul_ps(*(__m128 *)_xmm, v217))));
            }
            v219 = _mm_mul_ps(v214, v213);
            v373.m_vec.m_quad = _mm_shuffle_ps(v219, _mm_unpackhi_ps(v219, _mm_mul_ps(v211, v209)), 196);
          }
          else
          {
            hkQuaternionf::setFlippedRotation(&v373, &v376);
          }
        }
        else
        {
          v373.m_vec.m_quad = qi.m_vec.m_quad;
        }
        vertices = 0i64;
        v364 = 0;
        v365 = 2147483648;
        hkArrayUtil::_reserve(&v372, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &vertices, 144, 16);
        v220 = 0;
        do
        {
          v221 = 0;
          v222 = (__m128)COERCE_UNSIGNED_INT((float)v220);
          v222.m128_f32[0] = v222.m128_f32[0] * 0.090909094;
          do
          {
            v223 = v364;
            v224 = (__m128)COERCE_UNSIGNED_INT((float)v221);
            v224.m128_f32[0] = v224.m128_f32[0] * 0.090909094;
            uv.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v222, (__m128)0i64), _mm_unpacklo_ps(v224, (__m128)0i64));
            if ( v364 == (v365 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &vertices, 16);
              v223 = v364;
            }
            v364 = v223 + 1;
            v225 = &vertices[v223];
            hkGeometryProcessing::octahedronToNormal(&uv, v225);
            v226 = _mm_mul_ps(v373.m_vec.m_quad, v225->m_quad);
            v227 = _mm_shuffle_ps(v373.m_vec.m_quad, v373.m_vec.m_quad, 255);
            v228 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v225->m_quad, v225->m_quad, 201), v373.m_vec.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v373.m_vec.m_quad, v373.m_vec.m_quad, 201), v225->m_quad));
            v229 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v226, v226, 85), _mm_shuffle_ps(v226, v226, 0)),
                           _mm_shuffle_ps(v226, v226, 170)),
                         v373.m_vec.m_quad),
                       _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v227, v227), (__m128)xmmword_141A711B0), v225->m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v228, v228, 201), v227));
            v230 = _mm_mul_ps(_mm_add_ps(v229, v229), v201);
            v231 = _mm_mul_ps(v205, v230);
            *v225 = (hkVector4f)v230;
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v231, v231, 85), _mm_shuffle_ps(v231, v231, 0)),
                     _mm_shuffle_ps(v231, v231, 170))) )
            {
              v232 = v199.m_quad;
            }
            else
            {
              v232 = v198.m_quad;
            }
            ++v221;
            v225->m_quad = _mm_add_ps(v232, v230);
          }
          while ( v221 < 12 );
          ++v220;
        }
        while ( v220 < 12 );
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
          vertices,
          v364,
          material,
          v9);
        v136 = v365;
        v364 = 0;
        if ( v365 >= 0 )
        {
          v137 = vertices;
          goto LABEL_122;
        }
        break;
      case 4:
        v32 = v29[v30 + 1];
        v33 = 2;
        if ( (signed int)(v31 >> 8) < 2 )
          v33 = v31 >> 8;
        v34 = v33;
        v35 = (v31 >> 4) & 3;
        if ( v35 )
        {
          v36 = v35 - 1;
          if ( v36 )
          {
            if ( v36 == 1 )
            {
              v40.m_quad = (__m128)aabb.m_min;
              v41 = v33 - 1;
              v42 = 0;
              v409.m_quad = (__m128)aabb.m_min;
              v43 = _mm_mul_ps(
                      _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                      (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters'::`2'::invBitScalesBuffer);
              v410 = v43;
              v44 = (signed __int64)&v7->m_sharedVertices[v32];
              if ( v33 - 1 > 0 )
              {
                v45 = &aabb;
                do
                {
                  ++v45;
                  v46 = *(unsigned __int16 *)(v44 + 2i64 * (signed int)((v42 & 0xFFFFFFFC) - (v42 & 3) + 3));
                  v47 = _mm_cvtsi32_si128(v46 >> 10);
                  v48 = _mm_cvtsi32_si128((v46 >> 5) & 0x1F);
                  v49 = _mm_cvtsi32_si128(*(_WORD *)(v44 + 2i64 * (signed int)((v42 & 0xFFFFFFFC) - (v42 & 3) + 3)) & 0x1F);
                  v50 = v42 + 1;
                  v51 = (v42 + 1) & 3;
                  v42 += 2;
                  v52 = *(unsigned __int16 *)(v44 + 2i64 * (signed int)((v50 & 0xFFFFFFFC) - v51 + 3));
                  v45[-1].m_min.m_quad = _mm_add_ps(
                                           _mm_mul_ps(
                                             _mm_cvtepi32_ps(
                                               _mm_unpacklo_epi32(
                                                 _mm_unpacklo_epi32(v49, v47),
                                                 _mm_unpacklo_epi32(v48, _mm_cvtsi32_si128(0)))),
                                             v43),
                                           v40.m_quad);
                  v45[-1].m_max.m_quad = _mm_add_ps(
                                           _mm_mul_ps(
                                             _mm_cvtepi32_ps(
                                               _mm_unpacklo_epi32(
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128(v52 & 0x1F),
                                                   _mm_cvtsi32_si128(v52 >> 10)),
                                                 _mm_unpacklo_epi32(
                                                   _mm_cvtsi32_si128((v52 >> 5) & 0x1F),
                                                   _mm_cvtsi32_si128(0)))),
                                             v43),
                                           v40.m_quad);
                }
                while ( v42 < v41 );
              }
              if ( v42 < v34 )
              {
                v53 = &aabb.m_min.m_quad + v42;
                v54 = v34 - v42;
                do
                {
                  ++v53;
                  v55 = (v42 & 0xFFFFFFFC) - (v42 & 3);
                  ++v42;
                  v56 = *(unsigned __int16 *)(v44 + 2i64 * (signed int)(v55 + 3));
                  v53[-1] = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_unpacklo_epi32(
                                    _mm_unpacklo_epi32(
                                      _mm_cvtsi32_si128(*(_WORD *)(v44 + 2i64 * (signed int)(v55 + 3)) & 0x1F),
                                      _mm_cvtsi32_si128(v56 >> 10)),
                                    _mm_unpacklo_epi32(_mm_cvtsi32_si128((v56 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                v43),
                              v40.m_quad);
                  --v54;
                }
                while ( v54 );
              }
            }
            else
            {
              hkErrStream::hkErrStream(&v377, &description, 512);
              v37 = ((unsigned int)v7->m_sharedVerticesIndex[(unsigned __int8)v7->m_primitives[v8].m_indices[0]] >> 4) & 3;
              v38 = hkOstream::operator<<((hkOstream *)&v377.vfptr, "Compression method #");
              v39 = hkOstream::operator<<(v38, v37, (int)v38);
              hkOstream::operator<<(v39, " not implemented");
              if ( (unsigned int)hkError::messageError(
                                   -1875965459,
                                   &description,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTre"
                                   "e/hkcdStaticMeshTree.inl",
                                   499) )
                __debugbreak();
              hkOstream::~hkOstream((hkOstream *)&v377.vfptr);
            }
          }
          else
          {
            v57.m_quad = (__m128)aabb.m_min;
            v58 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
            v59 = v32;
            v60 = v33 - 1;
            v61 = 0;
            v62 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
            v63 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
            v412.m_quad = (__m128)aabb.m_min;
            v64 = _mm_mul_ps(
                    _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                    (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters'::`2'::invBitScalesBuffer);
            v413 = v64;
            v65 = (signed __int64)&v7->m_sharedVertices[v59];
            if ( v60 > 0 )
            {
              v66 = &aabb;
              do
              {
                ++v66;
                v67 = (__m128i)*(unsigned int *)(v65 + 4i64 * (signed int)((v61 & 0xFFFFFFFE) - (v61 & 1) + 1));
                v68 = v61 + 1;
                v61 += 2;
                _mm_store_si128((__m128i *)&v404, v67);
                v66[-1].m_min.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_cvtepi32_ps(
                                             _mm_or_si128(
                                               _mm_or_si128(
                                                 _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v67, 0x16u), 0), v58),
                                                 _mm_and_si128(v67, v63)),
                                               _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v67, 0xBu), 0), v62))),
                                           v64),
                                         v57.m_quad);
                v69 = (__m128i)*(unsigned int *)(v65 + 4i64 * (signed int)((v68 & 0xFFFFFFFE) - (v68 & 1) + 1));
                _mm_store_si128((__m128i *)&v399, v69);
                v66[-1].m_max.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_cvtepi32_ps(
                                             _mm_or_si128(
                                               _mm_or_si128(
                                                 _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v69, 0x16u), 0), v58),
                                                 _mm_and_si128(v69, v63)),
                                               _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v69, 0xBu), 0), v62))),
                                           v64),
                                         v57.m_quad);
              }
              while ( v61 < v60 );
            }
            if ( v61 < v34 )
            {
              v70 = &aabb.m_min.m_quad + v61;
              v71 = v34 - v61;
              do
              {
                ++v70;
                v72 = v61 & 1;
                v73 = v61++ & 0xFFFFFFFE;
                v74 = (__m128i)*(unsigned int *)(v65 + 4i64 * (signed int)(v73 - v72 + 1));
                _mm_store_si128((__m128i *)&v401, v74);
                v70[-1] = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_cvtepi32_ps(
                                _mm_or_si128(
                                  _mm_or_si128(
                                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v74, 0x16u), 0), v58),
                                    _mm_and_si128(v74, v63)),
                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v74, 0xBu), 0), v62))),
                              v64),
                            v57.m_quad);
                --v71;
              }
              while ( v71 );
            }
          }
        }
        else
        {
          v75 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
          v76 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
          v77 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
          v78 = (signed __int64)&v7->m_sharedVertices[v32];
          v79 = 0;
          if ( v33 - 1 > 0 )
          {
            v80 = &aabb;
            v81 = (const __m128i *)v78;
            v82 = ((unsigned int)(v33 - 2) >> 1) + 1;
            v83 = v82;
            v79 = 2 * v82;
            do
            {
              v84 = _mm_loadl_epi64(v81);
              ++v80;
              ++v81;
              _mm_store_si128((__m128i *)&v403, v84);
              v85 = _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v84, 0xAu), 85), v75),
                        _mm_and_si128(v84, v77)),
                      _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v84, 2), 5u), v76));
              v86 = _mm_loadl_epi64((const __m128i *)((char *)v81 - 8));
              v87 = _mm_add_ps(
                      _mm_mul_ps(_mm_cvtepi32_ps(v85), v7->m_sharedParms.m_scale.m_quad),
                      v7->m_sharedParms.m_origin.m_quad);
              _mm_store_si128((__m128i *)&v405, v86);
              v80[-1].m_min.m_quad = v87;
              v80[-1].m_max.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_cvtepi32_ps(
                                           _mm_or_si128(
                                             _mm_or_si128(
                                               _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v86, 0xAu), 85), v75),
                                               _mm_and_si128(v86, v77)),
                                             _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v86, 2), 5u), v76))),
                                         v7->m_sharedParms.m_scale.m_quad),
                                       v7->m_sharedParms.m_origin.m_quad);
              --v83;
            }
            while ( v83 );
          }
          if ( v79 < v34 )
          {
            v88 = &aabb.m_min.m_quad + v79;
            v89 = v34 - v79;
            do
            {
              v90 = v79;
              ++v88;
              ++v79;
              v91 = _mm_loadl_epi64((const __m128i *)(v78 + 8 * v90));
              _mm_store_si128((__m128i *)&v407, v91);
              v88[-1] = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_cvtepi32_ps(
                              _mm_or_si128(
                                _mm_or_si128(
                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v91, 0xAu), 85), v75),
                                  _mm_and_si128(v91, v77)),
                                _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v91, 2), 5u), v76))),
                            v7->m_sharedParms.m_scale.m_quad),
                          v7->m_sharedParms.m_origin.m_quad);
              --v89;
            }
            while ( v89 );
          }
        }
        v92.m_quad = (__m128)aabb.m_max;
        v93.m_quad = (__m128)aabb.m_min;
        v444 = (signed __int16)v7->m_sharedVerticesIndex[(unsigned __int8)v7->m_primitives[v22].m_indices[0] + 3] << 16;
        v94 = _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad);
        from.m_quad = stru_141A71280.m_quad;
        v95 = _mm_shuffle_ps((__m128)v444, (__m128)v444, 0);
        v96 = _mm_mul_ps(v94, v94);
        v97 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                _mm_shuffle_ps(v96, v96, 170));
        v98 = _mm_rsqrt_ps(v97);
        v433 = v97;
        v99 = _mm_mul_ps(
                v94,
                _mm_andnot_ps(
                  _mm_cmpleps(v97, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v98, v97), v98)),
                    _mm_mul_ps(v98, *(__m128 *)_xmm))));
        v100 = _mm_mul_ps(stru_141A71280.m_quad, v99);
        v101 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                 _mm_shuffle_ps(v100, v100, 170));
        v445 = FLOAT_0_99998999;
        LODWORD(v102) = (unsigned __int128)_mm_shuffle_ps(
                                             (__m128)LODWORD(FLOAT_0_99998999),
                                             (__m128)LODWORD(FLOAT_0_99998999),
                                             0);
        if ( v101.m128_f32[0] <= v102 )
        {
          if ( v101.m128_f32[0] >= (float)(0.0 - v102) )
          {
            v103 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v101), (__m128)xmmword_141A711B0);
            v104 = _mm_rsqrt_ps(v103);
            v417 = v103;
            v105 = _mm_andnot_ps(
                     _mm_cmpleps(v103, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v104, v103), v104)),
                       _mm_mul_ps(v104, *(__m128 *)_xmm)));
            v106 = _mm_mul_ps(v105, (__m128)xmmword_141A711B0);
            v107 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), stru_141A71280.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v99));
            v108 = _mm_shuffle_ps(v107, v107, 201);
            v446 = FLOAT_N0_99900001;
            if ( v101.m128_f32[0] < COERCE_FLOAT(
                                      _mm_shuffle_ps(
                                        (__m128)LODWORD(FLOAT_N0_99900001),
                                        (__m128)LODWORD(FLOAT_N0_99900001),
                                        0)) )
            {
              v109 = _mm_mul_ps(v108, v108);
              v394 = _mm_sub_ps(v103, v101);
              v110 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                       _mm_shuffle_ps(v109, v109, 170));
              v111 = _mm_rsqrt_ps(v110);
              v436 = v110;
              v112 = _mm_rsqrt_ps(v394);
              v106 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v394, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v112, v394), v112)),
                             _mm_mul_ps(*(__m128 *)_xmm, v112))),
                         v394),
                       _mm_andnot_ps(
                         _mm_cmpleps(v110, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v111, v110), v111)),
                           _mm_mul_ps(*(__m128 *)_xmm, v111))));
            }
            v113 = _mm_mul_ps(v108, v106);
            v371.m_vec.m_quad = _mm_shuffle_ps(v113, _mm_unpackhi_ps(v113, _mm_mul_ps(v105, v103)), 196);
          }
          else
          {
            hkQuaternionf::setFlippedRotation(&v371, &from);
          }
        }
        else
        {
          v371.m_vec.m_quad = qi.m_vec.m_quad;
        }
        v447 = FLOAT_0_52359879;
        array = 0i64;
        numVertices = 0;
        v114 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_52359879), (__m128)LODWORD(FLOAT_0_52359879), 0);
        v361 = 2147483648;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 24, 16);
        v115 = 0;
        do
        {
          v116 = _mm_load_si128((const __m128i *)_xmm);
          v117 = 0i64;
          v117.m128_f32[0] = (float)v115;
          v118 = _mm_add_epi32(v116, v116);
          v119 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v117, v117, 0), v114), *(__m128 *)offset_1);
          v120 = _mm_andnot_ps(*(__m128 *)_xmm, v119);
          v121 = _mm_andnot_si128(v116, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v120, *(__m128 *)_xmm)), v116));
          v122 = _mm_cvtepi32_ps(v121);
          v123 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v121, v118), (__m128i)0i64);
          v124 = _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v122, *(__m128 *)DP1_0), v120), _mm_mul_ps(v122, *(__m128 *)DP2)),
                   _mm_mul_ps(v122, *(__m128 *)DP3));
          v125 = _mm_mul_ps(v124, v124);
          v126 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)sinCoeff0, v125), *(__m128 *)sinCoeff1_0), v125),
                         *(__m128 *)sinCoeff2_0),
                       v125),
                     v124),
                   v124);
          v127 = _mm_shuffle_ps(v371.m_vec.m_quad, v371.m_vec.m_quad, 255);
          v128 = _mm_xor_ps(
                   _mm_or_ps(
                     _mm_andnot_ps(
                       v123,
                       _mm_add_ps(
                         _mm_sub_ps(
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_add_ps(_mm_mul_ps(*(__m128 *)cosCoeff0_0, v125), *(__m128 *)cosCoeff1),
                                   v125),
                                 *(__m128 *)cosCoeff2_0),
                               v125),
                             v125),
                           _mm_mul_ps(*(__m128 *)_xmm, v125)),
                         *(__m128 *)_xmm)),
                     _mm_and_ps(v126, v123)),
                   _mm_xor_ps(
                     (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v118, v118), v121), 0x1Du),
                     _mm_and_ps(v119, *(__m128 *)_xmm)));
          v129 = _mm_mul_ps(
                   _mm_movelh_ps(
                     _mm_unpacklo_ps(_mm_shuffle_ps(v128, v128, 85), _mm_shuffle_ps(v128, v128, 0)),
                     _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad)),
                   v95);
          v130 = _mm_mul_ps(v371.m_vec.m_quad, v129);
          v131 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v129, v129, 201), v371.m_vec.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v371.m_vec.m_quad, v371.m_vec.m_quad, 201), v129));
          v132 = numVertices;
          v133 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                         _mm_shuffle_ps(v130, v130, 170)),
                       v371.m_vec.m_quad),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v127, v127), (__m128)xmmword_141A711B0), v129)),
                   _mm_mul_ps(_mm_shuffle_ps(v131, v131, 201), v127));
          v134 = _mm_add_ps(v133, v133);
          if ( numVertices == (v361 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v132 = numVertices;
          }
          numVertices = v132 + 1;
          array[v132].m_quad = _mm_add_ps(v93.m_quad, v134);
          v135 = numVertices;
          if ( numVertices == (v361 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v135 = numVertices;
          }
          ++v115;
          numVertices = v135 + 1;
          array[v135].m_quad = _mm_add_ps(v92.m_quad, v134);
        }
        while ( v115 < 12 );
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
          array,
          numVertices,
          material,
          v9);
        v136 = v361;
        numVertices = 0;
        if ( v361 >= 0 )
        {
          v137 = array;
LABEL_122:
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v137,
            16 * v136);
          return;
        }
        break;
      default:
        hkErrStream::hkErrStream(&v375, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v375.vfptr, "Not implemented");
        if ( (unsigned int)hkError::messageError(
                             -1814753095,
                             &buf,
                             "Collide\\BvCompressedMesh\\hkpBvCompressedMeshShape.cpp",
                             165) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&v375.vfptr);
        return;
    }
  }
  else
  {
    v302 = v29[v30 + 1];
    v303 = 4;
    if ( (signed int)(v31 >> 8) < 4 )
      v303 = v31 >> 8;
    v304 = v303;
    v305 = (v31 >> 4) & 3;
    if ( v305 )
    {
      v306 = v305 - 1;
      if ( v306 )
      {
        if ( v306 == 1 )
        {
          v310.m_quad = (__m128)aabb.m_min;
          v311 = 0;
          v427.m_quad = (__m128)aabb.m_min;
          v312 = _mm_mul_ps(
                   _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                   (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters'::`2'::invBitScalesBuffer);
          v428 = v312;
          v313 = (signed __int64)&v7->m_sharedVertices[v302];
          if ( v303 - 1 > 0 )
          {
            v314 = &v383;
            do
            {
              v314 += 2;
              v315 = *(unsigned __int16 *)(v313 + 2i64 * (signed int)((v311 & 0xFFFFFFFC) - (v311 & 3) + 3));
              v316 = _mm_cvtsi32_si128(v315 >> 10);
              v317 = _mm_cvtsi32_si128((v315 >> 5) & 0x1F);
              v318 = _mm_cvtsi32_si128(*(_WORD *)(v313 + 2i64 * (signed int)((v311 & 0xFFFFFFFC) - (v311 & 3) + 3)) & 0x1F);
              v319 = v311 + 1;
              v320 = (v311 + 1) & 3;
              v311 += 2;
              v314[-2].m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(
                                      _mm_unpacklo_epi32(
                                        _mm_unpacklo_epi32(v318, v316),
                                        _mm_unpacklo_epi32(v317, _mm_cvtsi32_si128(0)))),
                                    v312),
                                  v310.m_quad);
              v321 = *(unsigned __int16 *)(v313 + 2i64 * (signed int)((v319 & 0xFFFFFFFC) - v320 + 3));
              v314[-1].m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(
                                      _mm_unpacklo_epi32(
                                        _mm_unpacklo_epi32(
                                          _mm_cvtsi32_si128(v321 & 0x1F),
                                          _mm_cvtsi32_si128(v321 >> 10)),
                                        _mm_unpacklo_epi32(_mm_cvtsi32_si128((v321 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                    v312),
                                  v310.m_quad);
            }
            while ( v311 < v303 - 1 );
          }
          if ( v311 < (signed __int64)v303 )
          {
            v322 = &v383 + v311;
            v323 = v303 - (signed __int64)v311;
            do
            {
              ++v322;
              v324 = (v311 & 0xFFFFFFFC) - (v311 & 3);
              ++v311;
              v325 = *(unsigned __int16 *)(v313 + 2i64 * (signed int)(v324 + 3));
              v322[-1].m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(
                                      _mm_unpacklo_epi32(
                                        _mm_unpacklo_epi32(
                                          _mm_cvtsi32_si128(*(_WORD *)(v313 + 2i64 * (signed int)(v324 + 3)) & 0x1F),
                                          _mm_cvtsi32_si128(v325 >> 10)),
                                        _mm_unpacklo_epi32(_mm_cvtsi32_si128((v325 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                    v312),
                                  v310.m_quad);
              --v323;
            }
            while ( v323 );
          }
        }
        else
        {
          hkErrStream::hkErrStream(&v382, &v443, 512);
          v307 = ((unsigned int)v7->m_sharedVerticesIndex[(unsigned __int8)v7->m_primitives[v8].m_indices[0]] >> 4) & 3;
          v308 = hkOstream::operator<<((hkOstream *)&v382.vfptr, "Compression method #");
          v309 = hkOstream::operator<<(v308, v307, (int)v308);
          hkOstream::operator<<(v309, " not implemented");
          if ( (unsigned int)hkError::messageError(
                               -1875965459,
                               &v443,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTree/hk"
                               "cdStaticMeshTree.inl",
                               499) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&v382.vfptr);
        }
      }
      else
      {
        v326.m_quad = (__m128)aabb.m_min;
        v327 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
        v328 = v302;
        v329 = v303 - 1;
        v330 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
        v331 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
        v430.m_quad = (__m128)aabb.m_min;
        v332 = _mm_mul_ps(
                 _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                 (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters'::`2'::invBitScalesBuffer);
        v431 = v332;
        v333 = (signed __int64)&v7->m_sharedVertices[v328];
        if ( v303 - 1 > 0 )
        {
          v334 = &v383;
          do
          {
            v334 += 2;
            v335 = (__m128i)*(unsigned int *)(v333 + 4i64 * (signed int)((v5 & 0xFFFFFFFE) - (v5 & 1) + 1));
            v336 = v5 + 1;
            v5 += 2;
            _mm_store_si128((__m128i *)&v414, v335);
            v334[-2].m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_cvtepi32_ps(
                                    _mm_or_si128(
                                      _mm_or_si128(
                                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v335, 0x16u), 0), v327),
                                        _mm_and_si128(v335, v331)),
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v335, 0xBu), 0), v330))),
                                  v332),
                                v326.m_quad);
            v337 = (__m128i)*(unsigned int *)(v333 + 4i64 * (signed int)((v336 & 0xFFFFFFFE) - (v336 & 1) + 1));
            _mm_store_si128((__m128i *)&v432, v337);
            v334[-1].m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_cvtepi32_ps(
                                    _mm_or_si128(
                                      _mm_or_si128(
                                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v337, 0x16u), 0), v327),
                                        _mm_and_si128(v337, v331)),
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v337, 0xBu), 0), v330))),
                                  v332),
                                v326.m_quad);
          }
          while ( v5 < v329 );
        }
        if ( v5 < v304 )
        {
          v338 = &v383 + v5;
          v339 = v304 - v5;
          do
          {
            ++v338;
            v340 = v5 & 1;
            v341 = v5++ & 0xFFFFFFFE;
            v342 = (__m128i)*(unsigned int *)(v333 + 4i64 * (signed int)(v341 - v340 + 1));
            _mm_store_si128((__m128i *)&v392, v342);
            v338[-1].m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_cvtepi32_ps(
                                    _mm_or_si128(
                                      _mm_or_si128(
                                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v342, 0x16u), 0), v327),
                                        _mm_and_si128(v342, v331)),
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v342, 0xBu), 0), v330))),
                                  v332),
                                v326.m_quad);
            --v339;
          }
          while ( v339 );
        }
      }
    }
    else
    {
      v343 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
      v344 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
      v345 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
      v346 = (signed __int64)&v7->m_sharedVertices[v302];
      v347 = v303 - 1;
      if ( v303 - 1 > 0 )
      {
        v348 = &v383;
        v349 = (const __m128i *)v346;
        v350 = ((unsigned int)(v347 - 1) >> 1) + 1;
        v351 = v350;
        v5 = 2 * v350;
        do
        {
          v352 = _mm_loadl_epi64(v349);
          v348 += 2;
          ++v349;
          _mm_store_si128((__m128i *)&v393, v352);
          v348[-2].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v352, 0xAu), 85), v343),
                                      _mm_and_si128(v352, v345)),
                                    _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v352, 2), 5u), v344))),
                                v7->m_sharedParms.m_scale.m_quad),
                              v7->m_sharedParms.m_origin.m_quad);
          v353 = _mm_loadl_epi64((const __m128i *)((char *)v349 - 8));
          _mm_store_si128((__m128i *)&v395, v353);
          v348[-1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v353, 0xAu), 85), v343),
                                      _mm_and_si128(v353, v345)),
                                    _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v353, 2), 5u), v344))),
                                v7->m_sharedParms.m_scale.m_quad),
                              v7->m_sharedParms.m_origin.m_quad);
          --v351;
        }
        while ( v351 );
      }
      if ( v5 < v304 )
      {
        v354 = &v383 + v5;
        v355 = v304 - v5;
        do
        {
          v356 = v5;
          ++v354;
          ++v5;
          v357 = _mm_loadl_epi64((const __m128i *)(v346 + 8 * v356));
          _mm_store_si128((__m128i *)&v397, v357);
          v354[-1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v357, 0xAu), 85), v343),
                                      _mm_and_si128(v357, v345)),
                                    _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v357, 2), 5u), v344))),
                                v7->m_sharedParms.m_scale.m_quad),
                              v7->m_sharedParms.m_origin.m_quad);
          --v355;
        }
        while ( v355 );
      }
    }
    v358 = _mm_sub_ps(v386, v383.m_quad);
    v388 = _mm_add_ps(v385, v358);
    v387 = _mm_add_ps(_mm_sub_ps(v385, v383.m_quad), v384);
    v390 = _mm_add_ps(v387, v358);
    v389 = _mm_add_ps(v386, _mm_sub_ps(v384, v383.m_quad));
    hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
      &v383,
      8,
      material,
      v9);
  }
}xHull(
      &v383,
      8,
      material,
      v9);
  }
}

// File Line: 175
// RVA: 0xDFEF00
void __fastcall hkpBvCompressedMeshShape::convertToGeometry(hkpBvCompressedMeshShape *this, hkGeometry *geometryOut, hkArray<unsigned int,hkContainerHeapAllocator> *inclKeys, hkArray<unsigned int,hkContainerHeapAllocator> *exclKeys)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v4; // rdi
  hkGeometry *v5; // rsi
  int v6; // er9
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // eax
  int v11; // eax
  int i; // ebx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter gc; // [rsp+40h] [rbp-28h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v14; // [rsp+48h] [rbp-20h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v15; // [rsp+50h] [rbp-18h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v4 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)this->m_tree;
  v5 = geometryOut;
  v14 = inclKeys;
  v15 = exclKeys;
  gc.vfptr = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverterVtbl *)&hkpBvCompressedMeshShapeGc::`vftable';
  hkGeometry::clear(geometryOut);
  v6 = v4->m_numPrimitiveKeys + v5->m_triangles.m_size;
  v7 = v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_triangles,
      v6,
      16);
  }
  v9 = v5->m_vertices.m_size + 3 * v4->m_numPrimitiveKeys;
  v10 = v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v9 )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_vertices,
      v9,
      16);
  }
  for ( i = 0; i < v4->m_sections.m_size; ++i )
    hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::convertToGeometry(
      v4,
      i,
      v5,
      &gc,
      1,
      0,
      0);
  hkGeometryUtils::weldVertices(v5, 0.0);
}

// File Line: 183
// RVA: 0xDFEE40
__int64 __fastcall hkpBvCompressedMeshShape::getPrimitiveUserData(hkpBvCompressedMeshShape *this, unsigned int key)
{
  hkpBvCompressedMeshShape *v2; // rbx
  __int64 result; // rax

  v2 = this;
  if ( !this->m_hasPerPrimitiveUserData.m_bool )
    return 0i64;
  LODWORD(result) = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getPrimitiveData(
                      (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)this->m_tree,
                      key) >> 8;
  if ( v2->m_userDataPalette.m_size )
    result = v2->m_userDataPalette.m_data[(unsigned __int8)result];
  else
    result = (unsigned __int8)result;
  return result;
}

// File Line: 206
// RVA: 0xDFEE90
hkStringPtr *__fastcall hkpBvCompressedMeshShape::getPrimitiveUserString(hkpBvCompressedMeshShape *this, hkStringPtr *result, unsigned int key)
{
  hkStringPtr *v3; // rbx
  hkpBvCompressedMeshShape *v4; // rdi
  unsigned int v5; // eax
  hkStringPtr *v6; // rax

  v3 = result;
  v4 = this;
  if ( this->m_hasPerPrimitiveUserData.m_bool && this->m_userStringPalette.m_size )
  {
    v5 = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getPrimitiveData(
           (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)this->m_tree,
           key);
    hkStringPtr::hkStringPtr(v3, &v4->m_userStringPalette.m_data[BYTE1(v5)]);
    v6 = v3;
  }
  else
  {
    hkStringPtr::hkStringPtr(result, 0i64);
    v6 = v3;
  }
  return v6;
}

// File Line: 229
// RVA: 0xDFF020
void __fastcall hkpBvCompressedMeshShape::getAabb(hkpBvCompressedMeshShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-18h]

  extraRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  hkAabbUtil::calcAabb(localToWorld, (hkAabb *)&this->m_tree[16], &extraRadius, out);
}

// File Line: 239
// RVA: 0xDFF060
hkBool *__fastcall hkpBvCompressedMeshShape::castRay(hkpBvCompressedMeshShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkVector4f v4; // xmm5
  hkBool *v5; // rbx
  __m128 *v6; // rdi
  hkpShapeRayCastInput *v7; // rsi
  hkVector4f v8; // xmm6
  __m128i v9; // xmm5
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __int128 v13; // xmm0
  __m128 v14; // xmm1
  int v15; // xmm9_4
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __int64 v18; // rcx
  int v19; // eax
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm2
  __int128 v27; // [rsp+20h] [rbp-D8h]
  hkpBvCompressedMeshShapeTree tree; // [rsp+30h] [rbp-C8h]
  int v29; // [rsp+D0h] [rbp-28h]
  __int64 v30; // [rsp+D4h] [rbp-24h]
  hkpBvCompressedMeshShape *v31; // [rsp+E8h] [rbp-10h]
  hkpShapeRayCastInput *v32; // [rsp+F0h] [rbp-8h]
  int v33; // [rsp+F8h] [rbp+0h]
  __m128 v34; // [rsp+108h] [rbp+10h]
  __int128 v35; // [rsp+118h] [rbp+20h]

  v4.m_quad = (__m128)input->m_to;
  v30 = -1i64;
  v5 = result;
  v6 = &results->m_normal.m_quad;
  v7 = input;
  _mm_store_si128((__m128i *)&tree.m_sharedVertices, (__m128i)0i64);
  v8.m_quad = (__m128)input->m_from;
  *(_QWORD *)&tree.m_sharedVerticesIndex.m_size = (char *)this + 112;
  v9 = (__m128i)_mm_sub_ps(v4.m_quad, v8.m_quad);
  _mm_store_si128((__m128i *)&tree.m_primitiveDataRuns, (__m128i)0i64);
  v10 = _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0);
  *(_OWORD *)&tree.m_numPrimitiveKeys = 0i64;
  tree.m_packedVertices.m_data = 0i64;
  *(_QWORD *)&tree.m_primitiveDataRuns.m_size = 0i64;
  v29 = 0;
  tree.m_sections = 0i64;
  *(_OWORD *)&tree.m_sections.m_size = 0i64;
  *(_OWORD *)&tree.m_primitives.m_size = 0i64;
  v11 = *(__m128 *)&this->m_tree[32];
  tree.0 = (hkcdStaticTree::DynamicStorage5)v8.m_quad;
  v12 = _mm_cmpeqps((__m128)0i64, (__m128)v9);
  tree.m_sections = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_sub_ps(
                                                                                         v11,
                                                                                         *(__m128 *)&this->m_tree[16]);
  v13 = *(_OWORD *)&this->m_tree[16];
  v31 = this;
  v32 = input;
  *(_OWORD *)&tree.m_numPrimitiveKeys = v13;
  tree.m_sections = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_mul_ps(
                                                                                         (__m128)tree.m_sections,
                                                                                         (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  v14 = _mm_rcp_ps((__m128)v9);
  _mm_store_si128((__m128i *)((char *)&v35 + 8), (__m128i)0i64);
  tree.m_domain.m_min.m_quad = _mm_shuffle_ps((__m128)v9, _mm_unpackhi_ps((__m128)v9, v10), 196);
  tree.m_domain.m_max.m_quad = _mm_or_ps(
                                 _mm_and_ps(
                                   _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v9, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                   v12),
                                 _mm_andnot_ps(
                                   v12,
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v9, v14)), v14)));
  tree.m_domain.m_max.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, tree.m_domain.m_min.m_quad)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::RayCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v27,
    (hkSimdFloat32 *)this->m_tree,
    &tree,
    (hkcdRay *)&tree.m_numPrimitiveKeys,
    (hkpBvCompressedMeshShape_Internals::RayCastQuery *)v27);
  v15 = v27;
  if ( *(float *)&v27 >= v10.m128_f32[0] )
  {
    v5->m_bool = 0;
  }
  else
  {
    v16 = v34;
    v17 = v7->m_to.m_quad;
    v18 = v6[4].m128_i32[0];
    v19 = v33;
    v5->m_bool = 1;
    v20 = _mm_sub_ps(v17, v7->m_from.m_quad);
    v6[1].m128_i32[0] = v15;
    v21 = _mm_mul_ps(v16, v16);
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170));
    v23 = _mm_rsqrt_ps(v22);
    v24 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v22, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                _mm_mul_ps(*(__m128 *)_xmm, v23))),
            v16);
    v25 = _mm_mul_ps(v24, v20);
    *v6 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_cmpltps(
                                   (__m128)0i64,
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                                     _mm_shuffle_ps(v25, v25, 170))),
                        0x1Fu),
                      0x1Fu),
            v24);
    v6[2].m128_i32[v18] = v19;
    v6[2].m128_i32[++v6[4].m128_i32[0]] = -1;
    --v6[4].m128_i32[0];
  }
  return v5;
}

// File Line: 272
// RVA: 0xDFF2B0
void __fastcall hkpBvCompressedMeshShape::castRayWithCollector(hkpBvCompressedMeshShape *this, hkpShapeRayCastInput *input, hkpCdBody *body, hkpRayHitCollector *collector)
{
  hkVector4f v4; // xmm5
  hkVector4f v5; // xmm6
  __m128i v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __int128 v9; // xmm0
  __m128 v10; // xmm1
  hkpBvCompressedMeshShapeTree tree; // [rsp+20h] [rbp-D8h]
  int v12; // [rsp+C0h] [rbp-38h]
  __int64 v13; // [rsp+C4h] [rbp-34h]
  hkpBvCompressedMeshShape *v14; // [rsp+D8h] [rbp-20h]
  hkpShapeRayCastInput *v15; // [rsp+E0h] [rbp-18h]
  hkpCdBody *v16; // [rsp+108h] [rbp+10h]
  hkpRayHitCollector *v17; // [rsp+110h] [rbp+18h]
  __int64 v18; // [rsp+120h] [rbp+28h]

  v4.m_quad = (__m128)input->m_to;
  v13 = -1i64;
  *(_QWORD *)&tree.m_sharedVerticesIndex.m_size = (char *)this + 112;
  _mm_store_si128((__m128i *)&tree.m_primitiveDataRuns, (__m128i)0i64);
  _mm_store_si128((__m128i *)&tree.m_sharedVertices, (__m128i)0i64);
  v5.m_quad = (__m128)input->m_from;
  tree.m_packedVertices.m_data = 0i64;
  *(_QWORD *)&tree.m_primitiveDataRuns.m_size = 0i64;
  v12 = 0;
  v6 = (__m128i)_mm_sub_ps(v4.m_quad, v5.m_quad);
  *(_OWORD *)&tree.m_numPrimitiveKeys = 0i64;
  tree.m_sections = 0i64;
  tree.m_primitives = 0i64;
  *(_OWORD *)&tree.m_primitives.m_size = 0i64;
  v7 = *(__m128 *)&this->m_tree[32];
  tree.0 = (hkcdStaticTree::DynamicStorage5)v5.m_quad;
  v8 = _mm_cmpeqps((__m128)0i64, (__m128)v6);
  tree.m_sections = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_sub_ps(
                                                                                         v7,
                                                                                         *(__m128 *)&this->m_tree[16]);
  v9 = *(_OWORD *)&this->m_tree[16];
  v14 = this;
  v16 = body;
  v17 = collector;
  v15 = input;
  *(_OWORD *)&tree.m_numPrimitiveKeys = v9;
  tree.m_sections = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_mul_ps(
                                                                                         (__m128)tree.m_sections,
                                                                                         (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  v10 = _mm_rcp_ps((__m128)v6);
  tree.m_domain.m_min.m_quad = _mm_shuffle_ps(
                                 (__m128)v6,
                                 _mm_unpackhi_ps(
                                   (__m128)v6,
                                   _mm_shuffle_ps(
                                     (__m128)LODWORD(collector->m_earlyOutHitFraction),
                                     (__m128)LODWORD(collector->m_earlyOutHitFraction),
                                     0)),
                                 196);
  tree.m_domain.m_max.m_quad = _mm_or_ps(
                                 _mm_and_ps(
                                   _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v6, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                   v8),
                                 _mm_andnot_ps(
                                   v8,
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v6, v10)), v10)));
  tree.m_domain.m_max.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, tree.m_domain.m_min.m_quad)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::RayCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v18,
    (hkSimdFloat32 *)this->m_tree,
    &tree,
    (hkcdRay *)&tree.m_numPrimitiveKeys,
    (hkpBvCompressedMeshShape_Internals::RayCastQuery *)v5.m_quad.m128_u64[0]);
}

// File Line: 287
// RVA: 0xDFF790
void __fastcall hkpBvCompressedMeshShape::castAabbImpl(hkpBvCompressedMeshShape *this, hkAabb *from, hkVector4f *to, hkpAabbCastCollector *collector)
{
  hkpBvCompressedMeshShape_Internals::AabbCastQuery *query; // [rsp+28h] [rbp-C0h]
  hkVector4f v5; // [rsp+30h] [rbp-B8h]
  __m128 v6; // [rsp+40h] [rbp-A8h]
  __int128 v7; // [rsp+50h] [rbp-98h]
  __int128 v8; // [rsp+60h] [rbp-88h]
  char *v9; // [rsp+70h] [rbp-78h]
  __int64 v10; // [rsp+78h] [rbp-70h]
  __int64 v11; // [rsp+80h] [rbp-68h]
  __int64 v12; // [rsp+90h] [rbp-58h]
  __int64 v13; // [rsp+A0h] [rbp-48h]
  int v14; // [rsp+A8h] [rbp-40h]
  __int64 v15; // [rsp+ACh] [rbp-3Ch]
  hkpAabbCastCollector *v16; // [rsp+C0h] [rbp-28h]
  __int64 v17; // [rsp+D0h] [rbp-18h]

  v5.m_quad = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  _mm_store_si128((__m128i *)&v11, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v12, (__m128i)0i64);
  v10 = 0i64;
  v13 = 0i64;
  v14 = 0;
  v9 = this->m_tree;
  v15 = -1i64;
  v6 = _mm_sub_ps(*(__m128 *)&this->m_tree[32], *(__m128 *)&this->m_tree[16]);
  v5.m_quad = *(__m128 *)&this->m_tree[16];
  v6 = _mm_mul_ps(
         v6,
         (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  v16 = collector;
  LODWORD(query) = (_DWORD)FLOAT_1_0;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::AabbCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v17,
    (hkSimdFloat32 *)this->m_tree,
    (hkpBvCompressedMeshShapeTree *)from,
    (hkAabb *)to,
    &v5,
    query,
    v5.m_quad.m128_f32[0]);
}

// File Line: 298
// RVA: 0xDFF010
signed __int64 __fastcall hkpBvCompressedMeshShape::calcSizeForSpu(hkpBvCompressedMeshShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  return 272i64;
}

// File Line: 311
// RVA: 0xDFF3F0
void __fastcall hkpBvCompressedMeshShape::queryAabb(hkpBvCompressedMeshShape *this, hkAabb *aabb, hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  __m128 *v3; // rbx
  unsigned int v4; // ecx
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkLifoAllocator *v9; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpBvCompressedMeshShape_Internals::AabbOverlaps> *v10; // r9
  char *v11; // rcx
  unsigned __int64 v12; // rdx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // er8
  char tree[164]; // [rsp+20h] [rbp-E0h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v19; // [rsp+D0h] [rbp-30h]
  hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot> stackInstance; // [rsp+E0h] [rbp-20h]
  __m128 v21; // [rsp+100h] [rbp+0h]

  v3 = (__m128 *)this->m_tree;
  v4 = hkMemoryRouter::s_memoryRouter.m_slotID;
  *(_QWORD *)&tree[156] = -1i64;
  *(_OWORD *)&tree[32] = 0i64;
  *(_OWORD *)&tree[48] = 0i64;
  *(_OWORD *)&tree[64] = 0i64;
  *(_QWORD *)&tree[96] = v3;
  *(_QWORD *)&tree[104] = 0i64;
  *(_QWORD *)&tree[144] = 0i64;
  _mm_store_si128((__m128i *)&tree[128], (__m128i)0i64);
  *(_OWORD *)&tree[80] = 0i64;
  _mm_store_si128((__m128i *)&tree[112], (__m128i)0i64);
  *(_DWORD *)&tree[152] = 0;
  *(_QWORD *)tree = 0i64;
  v5 = v3[2];
  *(_DWORD *)&tree[8] = 0;
  *(_DWORD *)&tree[12] = 2147483648;
  *(_DWORD *)&tree[24] = 64;
  *(__m128 *)&tree[48] = _mm_sub_ps(v5, v3[1]);
  v6 = v3[1];
  v19 = hits;
  stackInstance.m_stack.m_data = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot *)&tree[32];
  *(__m128 *)&tree[32] = v6;
  v7.m_quad = (__m128)aabb->m_min;
  *(__m128 *)&tree[48] = _mm_mul_ps(
                           *(__m128 *)&tree[48],
                           (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  v8.m_quad = (__m128)aabb->m_max;
  *(hkVector4f *)&stackInstance.m_stack.m_localMemory = (hkVector4f)v7.m_quad;
  v21 = v8.m_quad;
  v9 = (hkLifoAllocator *)TlsGetValue(v4);
  v11 = (char *)v9->m_cur;
  v12 = (unsigned __int64)(v11 + 3072);
  if ( v9->m_slabSize < 3072 || (void *)v12 > v9->m_end )
    v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v9, 3072);
  else
    v9->m_cur = (void *)v12;
  *(_QWORD *)tree = v11;
  *(_QWORD *)&tree[16] = v11;
  *(_DWORD *)&tree[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpBvCompressedMeshShapeTree,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpBvCompressedMeshShape_Internals::AabbOverlaps>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v3,
    (hkpBvCompressedMeshShapeTree *)tree,
    &stackInstance,
    v10);
  v13 = *(_DWORD *)&tree[8];
  v14 = *(char **)&tree[16];
  if ( *(_QWORD *)&tree[16] == *(_QWORD *)tree )
    v13 = 0;
  *(_DWORD *)&tree[8] = v13;
  v15 = (48 * *(_DWORD *)&tree[24] + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  *(_DWORD *)&tree[8] = 0;
  if ( *(_DWORD *)&tree[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)tree,
      48 * (*(_DWORD *)&tree[12] & 0x3FFFFFFF));
}

// File Line: 320
// RVA: 0xDFF5C0
__int64 __fastcall hkpBvCompressedMeshShape::queryAabbImpl(hkpBvCompressedMeshShape *this, hkAabb *aabb, unsigned int *hits, int maxNumKeys)
{
  __m128 *v4; // rbx
  unsigned int v5; // ecx
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  hkVector4f v8; // xmm0
  hkVector4f v9; // xmm1
  hkLifoAllocator *v10; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpBvCompressedMeshShape_Internals::AabbOverlapsWithMaxHits> *v11; // r9
  char *v12; // rcx
  unsigned __int64 v13; // rdx
  int v14; // eax
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // er8
  char tree[164]; // [rsp+20h] [rbp-E0h]
  unsigned int *v21; // [rsp+D0h] [rbp-30h]
  int v22; // [rsp+D8h] [rbp-28h]
  unsigned int v23; // [rsp+DCh] [rbp-24h]
  hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot> stackInstance; // [rsp+E0h] [rbp-20h]
  __m128 v25; // [rsp+100h] [rbp+0h]

  v4 = (__m128 *)this->m_tree;
  v5 = hkMemoryRouter::s_memoryRouter.m_slotID;
  *(_QWORD *)&tree[156] = -1i64;
  *(_OWORD *)&tree[32] = 0i64;
  *(_OWORD *)&tree[48] = 0i64;
  *(_OWORD *)&tree[64] = 0i64;
  *(_QWORD *)&tree[96] = v4;
  *(_QWORD *)&tree[104] = 0i64;
  *(_QWORD *)&tree[144] = 0i64;
  _mm_store_si128((__m128i *)&tree[128], (__m128i)0i64);
  *(_OWORD *)&tree[80] = 0i64;
  _mm_store_si128((__m128i *)&tree[112], (__m128i)0i64);
  *(_DWORD *)&tree[152] = 0;
  *(_QWORD *)tree = 0i64;
  v6 = v4[2];
  *(_DWORD *)&tree[8] = 0;
  *(_DWORD *)&tree[12] = 2147483648;
  *(_DWORD *)&tree[24] = 64;
  *(__m128 *)&tree[48] = _mm_sub_ps(v6, v4[1]);
  v7 = v4[1];
  v21 = hits;
  v22 = maxNumKeys;
  v23 = 0;
  *(__m128 *)&tree[32] = v7;
  v8.m_quad = (__m128)aabb->m_min;
  *(__m128 *)&tree[48] = _mm_mul_ps(
                           *(__m128 *)&tree[48],
                           (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  stackInstance.m_stack.m_data = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot *)&tree[32];
  v9.m_quad = (__m128)aabb->m_max;
  *(hkVector4f *)&stackInstance.m_stack.m_localMemory = (hkVector4f)v8.m_quad;
  v25 = v9.m_quad;
  v10 = (hkLifoAllocator *)TlsGetValue(v5);
  v12 = (char *)v10->m_cur;
  v13 = (unsigned __int64)(v12 + 3072);
  if ( v10->m_slabSize < 3072 || (void *)v13 > v10->m_end )
    v12 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, 3072);
  else
    v10->m_cur = (void *)v13;
  *(_QWORD *)tree = v12;
  *(_QWORD *)&tree[16] = v12;
  *(_DWORD *)&tree[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpBvCompressedMeshShapeTree,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpBvCompressedMeshShape_Internals::AabbOverlapsWithMaxHits>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v4,
    (hkpBvCompressedMeshShapeTree *)tree,
    &stackInstance,
    v11);
  v14 = *(_DWORD *)&tree[8];
  v15 = *(char **)&tree[16];
  if ( *(_QWORD *)&tree[16] == *(_QWORD *)tree )
    v14 = 0;
  *(_DWORD *)&tree[8] = v14;
  v16 = (48 * *(_DWORD *)&tree[24] + 127) & 0xFFFFFF80;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (v16 + 15) & 0xFFFFFFF0;
  if ( v16 > v17->m_slabSize || &v15[v18] != v17->m_cur || v17->m_firstNonLifoEnd == v15 )
    hkLifoAllocator::slowBlockFree(v17, v15, v18);
  else
    v17->m_cur = v15;
  *(_DWORD *)&tree[8] = 0;
  if ( *(_DWORD *)&tree[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)tree,
      48 * (*(_DWORD *)&tree[12] & 0x3FFFFFFF));
  return v23;
}

// File Line: 335
// RVA: 0xDFF840
__int64 __fastcall hkpBvCompressedMeshShape::getNumChildShapes(hkpBvCompressedMeshShape *this)
{
  return *(unsigned int *)&this->m_tree[8];
}

// File Line: 340
// RVA: 0xDFF850
signed __int64 __fastcall hkpBvCompressedMeshShape::getFirstKey(hkpBvCompressedMeshShape *this)
{
  signed __int64 result; // rax
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v2; // rbx
  unsigned __int64 v3; // r9
  __int64 v4; // rcx
  __int64 v5; // rcx
  int v6; // edx
  int v7; // er8

  if ( !*(_DWORD *)&this->m_tree[32] )
    return 0xFFFFFFFFi64;
  result = 0i64;
  v2 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)&this->m_userDataPalette;
  do
  {
    v3 = 0i64;
    v4 = (unsigned int)result >> 8;
    if ( (_DWORD)v4 != -1 )
      v3 = (unsigned __int64)&v2->m_primitives.m_data[(unsigned __int64)v2->m_sections.m_data[v4].m_primitives.m_data >> 8];
    v5 = (unsigned __int8)result >> 1;
    v6 = *(unsigned __int8 *)(v3 + 4 * v5 + 3);
    v7 = *(unsigned __int8 *)(v3 + 4 * v5 + 2);
    if ( v6 == v7 )
      break;
    if ( *(_BYTE *)(v3 + 4 * v5) != -34 )
      break;
    if ( *(unsigned __int8 *)(v3 + 4 * v5 + 1) != 173 )
      break;
    if ( v7 != 222 )
      break;
    if ( v6 != 173 )
      break;
    result = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getNextKey(
               v2,
               result);
  }
  while ( (_DWORD)result != -1 );
  return result;
}

// File Line: 357
// RVA: 0xDFF910
signed __int64 __fastcall hkpBvCompressedMeshShape::getNextKey(hkpBvCompressedMeshShape *this, unsigned int oldKey)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v2; // rbx
  signed __int64 result; // rax
  __int64 v4; // rax
  unsigned __int64 v5; // r9
  __int64 v6; // rax
  int v7; // ecx
  int v8; // er8

  v2 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)&this->m_userDataPalette;
  while ( 1 )
  {
    result = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getNextKey(
               v2,
               oldKey);
    oldKey = result;
    if ( (_DWORD)result == -1 )
      break;
    v4 = (unsigned int)result >> 8;
    v5 = 0i64;
    if ( (_DWORD)v4 != -1 )
      v5 = (unsigned __int64)&v2->m_primitives.m_data[(unsigned __int64)v2->m_sections.m_data[v4].m_primitives.m_data >> 8];
    v6 = (unsigned __int8)oldKey >> 1;
    v7 = *(unsigned __int8 *)(v5 + 4 * v6 + 3);
    v8 = *(unsigned __int8 *)(v5 + 4 * v6 + 2);
    if ( v7 == v8
      || *(_BYTE *)(v5 + 4 * v6) != -34
      || *(unsigned __int8 *)(v5 + 4 * v6 + 1) != 173
      || v8 != 222
      || v7 != 173 )
    {
      return oldKey;
    }
  }
  return result;
}

// File Line: 376
// RVA: 0xDFF9B0
hkpShape *__fastcall hkpBvCompressedMeshShape::getChildShape(hkpBvCompressedMeshShape *this, unsigned int key, char (*buffer)[512])
{
  __m128 v3; // xmm8
  char (*v4)[512]; // r12
  int v5; // er8
  signed __int64 v6; // r15
  unsigned __int64 v7; // r11
  hkArray<hkStringPtr,hkContainerHeapAllocator> v8; // xmm9
  __int64 v9; // rax
  __m128 v10; // xmm13
  __m128 v11; // xmm4
  __m128 v12; // xmm8
  unsigned int v13; // edi
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  int v16; // eax
  unsigned __int64 v17; // rdx
  __int64 v18; // rax
  unsigned __int64 v19; // r10
  int v20; // edx
  unsigned int *v21; // rbx
  int v22; // edx
  int v23; // esi
  int i; // ecx
  int v25; // ecx
  int v26; // edi
  __int64 v27; // rax
  int v28; // esi
  signed __int64 v29; // rdx
  int v30; // edi
  unsigned int v31; // ebx
  __int64 v32; // r13
  int v33; // edx
  int v34; // eax
  int v35; // ecx
  char (*v36)[512]; // r14
  hkVector4f v37; // xmm7
  __m128 v38; // xmm6
  int v39; // ecx
  int v40; // edx
  int v41; // eax
  __int64 v42; // r11
  __int64 v43; // rcx
  unsigned int v44; // edx
  unsigned __int16 v45; // r9
  hkVector4f *v46; // r15
  signed int v47; // er8
  __int64 v48; // rdi
  int v49; // edx
  int v50; // edx
  int v51; // edi
  hkOstream *v52; // rax
  hkOstream *v53; // rax
  signed __int64 v54; // r10
  __m128 v55; // xmm6
  int v56; // esi
  hkVector4f *v57; // r9
  unsigned int v58; // ecx
  __m128i v59; // xmm0
  __m128i v60; // xmm2
  __m128i v61; // xmm3
  int v62; // ecx
  int v63; // eax
  __m128i v64; // xmm1
  unsigned int v65; // eax
  signed __int64 v66; // r8
  __int64 v67; // rdi
  unsigned int v68; // ecx
  unsigned int v69; // eax
  __m128i v70; // xmm3
  __m128i v71; // xmm4
  __m128i v72; // xmm5
  signed __int64 v73; // r9
  __m128 v74; // xmm6
  int v75; // edx
  hkVector4f *v76; // rsi
  __m128i v77; // xmm1
  int v78; // eax
  __m128i v79; // xmm1
  signed __int64 v80; // rsi
  signed __int64 v81; // rdi
  int v82; // eax
  unsigned int v83; // ecx
  __m128i v84; // xmm1
  __m128i v85; // xmm3
  __m128i v86; // xmm4
  __m128i v87; // xmm5
  signed __int64 v88; // r10
  int v89; // edx
  hkVector4f *v90; // rcx
  const __m128i *v91; // rsi
  unsigned int v92; // eax
  __int64 v93; // r9
  __m128i v94; // xmm2
  __m128i v95; // xmm2
  signed __int64 v96; // rcx
  signed __int64 v97; // rdi
  __int64 v98; // rax
  __m128i v99; // xmm2
  unsigned __int64 v100; // rdi
  __int64 v101; // rcx
  int v102; // eax
  char (*v103)[512]; // rax
  __int64 v104; // r11
  char (*v105)[512]; // rax
  signed int v106; // eax
  __int64 v107; // r9
  signed int v108; // er10
  __m128 v109; // xmm8
  int v110; // esi
  __m128 v111; // xmm7
  __m128 *v112; // rdx
  __m128 v113; // xmm8
  __m128 v114; // xmm7
  __m128 v115; // xmm6
  __m128 v116; // xmm4
  __m128 v117; // xmm5
  __m128 v118; // xmm3
  __int64 v119; // rax
  signed __int64 v120; // rcx
  __m128 v121; // xmm2
  __m128 v122; // xmm1
  __int64 v123; // rcx
  char v125; // cl
  int v126; // xmm0_4
  __int64 v127; // rax
  __m128i v128; // xmm5
  __m128i v129; // xmm6
  __m128i v130; // xmm7
  __m128i v131; // xmm10
  __m128i v132; // xmm11
  __m128i v133; // xmm12
  __m128i v134; // xmm2
  unsigned __int64 v135; // rcx
  hkVector4f v136; // xmm3
  __int64 v137; // rax
  __m128i v138; // xmm2
  __int64 v139; // rax
  __m128i v140; // xmm2
  __int64 v141; // rax
  __m128i v142; // xmm2
  signed __int64 v143; // rcx
  __int128 v144; // xmm0
  unsigned int v145; // ebx
  signed __int64 v146; // [rsp+30h] [rbp-90h]
  __m128 v147; // [rsp+40h] [rbp-80h]
  __m128 v148; // [rsp+50h] [rbp-70h]
  __m128 v149; // [rsp+60h] [rbp-60h]
  hkAabb aabb; // [rsp+70h] [rbp-50h]
  __int128 v151; // [rsp+C0h] [rbp+0h]
  __m128i v152; // [rsp+D0h] [rbp+10h]
  char buf; // [rsp+100h] [rbp+40h]
  __int64 v154; // [rsp+3D0h] [rbp+310h]
  float paddingRadius; // [rsp+3D8h] [rbp+318h]
  float cylinderRadius; // [rsp+3E0h] [rbp+320h]
  __int64 v157; // [rsp+3E8h] [rbp+328h]

  v3 = *((__m128 *)&this->m_userStringPalette + 1);
  v4 = buffer;
  v5 = (unsigned __int8)key >> 1;
  v149.m128_u64[0] = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  paddingRadius = 0.0;
  v8 = this->m_userStringPalette;
  v9 = key >> 8;
  LODWORD(cylinderRadius) = key & 1;
  v10 = 0i64;
  v11 = 0i64;
  _mm_store_si128((__m128i *)&v151, (__m128i)0i64);
  v12 = _mm_mul_ps(
          _mm_sub_ps(v3, (__m128)v8),
          (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  _mm_store_si128(&v152, (__m128i)0i64);
  if ( (_DWORD)v9 == -1 )
  {
    v19 = v151;
    v157 = v152.m128i_i64[1];
    v147.m128_u64[0] = *((_QWORD *)&v151 + 1);
    v146 = v152.m128i_i64[0];
  }
  else
  {
    v6 = *(_QWORD *)&this->m_tree[24] + 96 * v9;
    v13 = *(_DWORD *)(v6 + 76);
    v14 = (__m128)*(unsigned __int64 *)(v6 + 60);
    v15 = (__m128)*(unsigned int *)(v6 + 68);
    v10 = *(__m128 *)(v6 + 48);
    v16 = *(unsigned __int8 *)(v6 + 92);
    v147.m128_u64[0] = *(_QWORD *)&this->m_tree[72] + 4i64 * *(unsigned int *)(v6 + 72);
    v11 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v14, v15), 4), 4);
    v146 = *(_QWORD *)&this->m_tree[88] + 8i64 * (v16 << 16);
    v17 = *(_QWORD *)&this->m_tree[56] + 2 * ((unsigned __int64)v13 >> 8);
    v7 = *(_QWORD *)&this->m_tree[104] + 8 * ((unsigned __int64)*(unsigned int *)(v6 + 84) >> 8);
    v18 = *(_QWORD *)&this->m_tree[40];
    LODWORD(paddingRadius) = (unsigned __int8)v13;
    v19 = v18 + 4 * ((unsigned __int64)*(unsigned int *)(v6 + 80) >> 8);
    v157 = v17 - 2i64 * (unsigned __int8)v13;
  }
  v20 = *(unsigned __int8 *)(v6 + 84);
  v148.m128_u64[0] = v19;
  v21 = 0i64;
  v22 = v20 - 1;
  v23 = 0;
  for ( i = v22 + 1; i > 4; i = v22 - v23 + 1 )
  {
    v25 = (v22 + v23) >> 1;
    v26 = v5 - *(unsigned __int8 *)(v7 + 8i64 * v25 + 4);
    if ( v26 < 0 )
    {
      v22 = (v22 + v23) >> 1;
    }
    else
    {
      if ( v26 < *(unsigned __int8 *)(v7 + 8i64 * v25 + 5) )
      {
        v21 = (unsigned int *)(v7 + 8i64 * v25);
        goto LABEL_17;
      }
      v23 = v25 + 1;
    }
  }
  v27 = v23;
  v28 = 0;
  v29 = v7 + 8 * v27;
  if ( i > 0 )
  {
    while ( 1 )
    {
      v30 = v5 - *(unsigned __int8 *)(v29 + 4);
      if ( v30 >= 0 && v30 < *(unsigned __int8 *)(v29 + 5) )
        break;
      ++v28;
      v29 += 8i64;
      if ( v28 >= i )
        goto LABEL_17;
    }
    v21 = (unsigned int *)v29;
  }
LABEL_17:
  v31 = *v21;
  v32 = v5;
  v33 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 3);
  v34 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 2);
  v35 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 1);
  v36 = 0i64;
  if ( v33 != v34 )
  {
    if ( *(_BYTE *)(v19 + 4i64 * v5) == -34 && v35 == 173 && v34 == 222 && v33 == 173 )
      return 0i64;
    goto LABEL_84;
  }
  if ( v34 != v35 )
  {
LABEL_84:
    v125 = *(_BYTE *)(v154 + 12);
    v126 = *(_DWORD *)(v154 + 8);
    if ( v4 )
    {
      *(_DWORD *)&(*v4)[8] = 0x1FFFF;
      *(_DWORD *)&(*v4)[16] = 1026;
      *(_DWORD *)&(*v4)[32] = v126;
      *(_OWORD *)&(*v4)[96] = 0i64;
      *(_QWORD *)v4 = &hkpTriangleShape::`vftable';
      *(_QWORD *)&(*v4)[24] = 0i64;
      (*v4)[42] = v125;
      (*v4)[43] = 0;
      *(_WORD *)&(*v4)[40] = HIWORD(v31);
      v36 = v4;
    }
    v127 = *(unsigned __int8 *)(v19 + 4i64 * v5);
    v128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
    v129 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
    v130 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
    v131 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
    v132 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
    v133 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
    if ( (signed int)v127 < SLODWORD(paddingRadius) )
    {
      v135 = v147.m128_u64[0];
      v136.m_quad = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_cvtepi32_ps(
                          _mm_or_si128(
                            _mm_or_si128(
                              _mm_and_si128(
                                _mm_shuffle_epi32(
                                  _mm_srli_epi32((__m128i)*(unsigned int *)(v147.m128_u64[0] + 4 * v127), 0x16u),
                                  0),
                                v128),
                              _mm_and_si128(v130, (__m128i)*(unsigned int *)(v147.m128_u64[0] + 4 * v127))),
                            _mm_and_si128(
                              _mm_shuffle_epi32(
                                _mm_srli_epi32((__m128i)*(unsigned int *)(v147.m128_u64[0] + 4 * v127), 0xBu),
                                0),
                              v129))),
                        v11),
                      v10);
    }
    else
    {
      v134 = _mm_loadl_epi64((const __m128i *)(v146
                                             + 8i64
                                             * *(unsigned __int16 *)(v157 + 2i64 * *(unsigned __int8 *)(v19 + 4i64 * v5))));
      v135 = v147.m128_u64[0];
      v136.m_quad = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_cvtepi32_ps(
                          _mm_or_si128(
                            _mm_or_si128(
                              _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v134, 0xAu), 85), v131),
                              _mm_and_si128(v134, v133)),
                            _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v134, 2), 5u), v132))),
                        v12),
                      (__m128)v8);
    }
    v137 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 1);
    aabb.m_min = (hkVector4f)v136.m_quad;
    if ( (signed int)v137 < SLODWORD(paddingRadius) )
    {
      v147 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(
                         _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v137), 0x16u), 0),
                         v128),
                       _mm_and_si128((__m128i)*(unsigned int *)(v135 + 4 * v137), v130)),
                     _mm_and_si128(
                       _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v137), 0xBu), 0),
                       v129))),
                 v11),
               v10);
    }
    else
    {
      v138 = _mm_loadl_epi64((const __m128i *)(v146 + 8i64 * *(unsigned __int16 *)(v157 + 2i64 * (signed int)v137)));
      v135 = v147.m128_u64[0];
      v147 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v138, 0xAu), 85), v131),
                       _mm_and_si128(v138, v133)),
                     _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v138, 2), 5u), v132))),
                 v12),
               (__m128)v8);
    }
    v139 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 2);
    if ( (signed int)v139 < SLODWORD(paddingRadius) )
    {
      v148 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(
                         _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v139), 0x16u), 0),
                         v128),
                       _mm_and_si128((__m128i)*(unsigned int *)(v135 + 4 * v139), v130)),
                     _mm_and_si128(
                       _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v139), 0xBu), 0),
                       v129))),
                 v11),
               v10);
    }
    else
    {
      v140 = _mm_loadl_epi64((const __m128i *)(v146
                                             + 8i64
                                             * *(unsigned __int16 *)(v157
                                                                   + 2i64 * *(unsigned __int8 *)(v19 + 4i64 * v5 + 2))));
      v135 = v147.m128_u64[0];
      v148 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v140, 0xAu), 85), v131),
                       _mm_and_si128(v140, v133)),
                     _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v140, 2), 5u), v132))),
                 v12),
               (__m128)v8);
    }
    v141 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 3);
    if ( (signed int)v141 < SLODWORD(paddingRadius) )
    {
      v149 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(
                         _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v141), 0x16u), 0),
                         v128),
                       _mm_and_si128((__m128i)*(unsigned int *)(v135 + 4 * v141), v130)),
                     _mm_and_si128(
                       _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v141), 0xBu), 0),
                       v129))),
                 v11),
               v10);
    }
    else
    {
      v142 = _mm_loadl_epi64((const __m128i *)(v146
                                             + 8i64
                                             * *(unsigned __int16 *)(v157
                                                                   + 2i64 * *(unsigned __int8 *)(v19 + 4i64 * v5 + 3))));
      v149 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v142, 0xAu), 85), v131),
                       _mm_and_si128(v142, v133)),
                     _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v142, 2), 5u), v132))),
                 v12),
               (__m128)v8);
    }
    v143 = 2i64 * SLODWORD(cylinderRadius);
    v144 = *((_OWORD *)&v147 + SLODWORD(cylinderRadius));
    *(hkVector4f *)&(*v36)[48] = (hkVector4f)v136.m_quad;
    *(_OWORD *)&(*v36)[64] = v144;
    *(__m128 *)&(*v36)[80] = *(__m128 *)((char *)&v148 + 8 * v143);
    goto LABEL_60;
  }
  if ( *(_BYTE *)(v157 + 2i64 * *(unsigned __int8 *)(v19 + 4i64 * v5)) & 0x30 )
  {
    v39 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 2);
    if ( *(unsigned __int8 *)(v19 + 4i64 * v5 + 3) != v39 || v39 != *(unsigned __int8 *)(v19 + 4i64 * v5 + 1) )
      v40 = hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::findLeafByValue(
              (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)v6,
              v5);
    else
      v40 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 1);
    hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(
      (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)v6,
      v40,
      &aabb);
    v37.m_quad = (__m128)aabb.m_min;
    v38 = v147;
  }
  else
  {
    v37.m_quad = (__m128)xmmword_141A712A0;
    v38 = _mm_xor_ps(
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
            (__m128)xmmword_141A712A0);
  }
  v41 = (unsigned __int64)TlsGetValue(hkThreadNumber.m_slotID);
  v42 = v157;
  v43 = *(unsigned __int8 *)(v148.m128_u64[0] + 4 * v32);
  v44 = *(unsigned __int16 *)(v157 + 2 * v43);
  v45 = *(_WORD *)(v157 + 2 * v43 + 2);
  v46 = hkpBvCompressedMeshShape::g_vertexBufferPool[v41];
  v47 = 255;
  if ( (signed int)(v44 >> 8) < 255 )
    v47 = (unsigned int)*(unsigned __int16 *)(v157 + 2 * v43) >> 8;
  paddingRadius = *(float *)&v47;
  v48 = v47;
  v49 = (v44 >> 4) & 3;
  if ( v49 )
  {
    v50 = v49 - 1;
    if ( v50 )
    {
      if ( v50 == 1 )
      {
        v54 = v146 + 8i64 * v45;
        v55 = _mm_mul_ps(
                _mm_sub_ps(v38, v37.m_quad),
                (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters'::`2'::invBitScalesBuffer);
        v56 = 0;
        if ( v47 - 1 > 0 )
        {
          v57 = hkpBvCompressedMeshShape::g_vertexBufferPool[v41];
          do
          {
            v57 += 2;
            v58 = *(unsigned __int16 *)(v54 + 2i64 * (signed int)((v56 & 0xFFFFFFFC) - (v56 & 3) + 3));
            v59 = _mm_cvtsi32_si128(v58 >> 10);
            v60 = _mm_cvtsi32_si128((v58 >> 5) & 0x1F);
            v61 = _mm_cvtsi32_si128(*(_WORD *)(v54 + 2i64 * (signed int)((v56 & 0xFFFFFFFC) - (v56 & 3) + 3)) & 0x1F);
            v62 = v56 + 1;
            v63 = (v56 + 1) & 3;
            v56 += 2;
            v64 = _mm_cvtsi32_si128(v149.m128_u32[0]);
            v57[-2].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v61, v59), _mm_unpacklo_epi32(v60, v64))),
                                 v55),
                               v37.m_quad);
            v65 = *(unsigned __int16 *)(v54 + 2i64 * (signed int)((v62 & 0xFFFFFFFC) - v63 + 3));
            v57[-1].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128(v65 & 0x1F), _mm_cvtsi32_si128(v65 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v65 >> 5) & 0x1F), v64))),
                                 v55),
                               v37.m_quad);
          }
          while ( v56 < v47 - 1 );
          v42 = v157;
        }
        if ( v56 < (signed __int64)v47 )
        {
          v66 = (signed __int64)&v46[v56];
          v67 = v48 - v56;
          do
          {
            v66 += 16i64;
            v68 = (v56 & 0xFFFFFFFC) - (v56 & 3);
            ++v56;
            v69 = *(unsigned __int16 *)(v54 + 2i64 * (signed int)(v68 + 3));
            *(__m128 *)(v66 - 16) = _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_cvtepi32_ps(
                                          _mm_unpacklo_epi32(
                                            _mm_unpacklo_epi32(
                                              _mm_cvtsi32_si128(*(_WORD *)(v54 + 2i64 * (signed int)(v68 + 3)) & 0x1F),
                                              _mm_cvtsi32_si128(v69 >> 10)),
                                            _mm_unpacklo_epi32(
                                              _mm_cvtsi32_si128((v69 >> 5) & 0x1F),
                                              _mm_cvtsi32_si128(0)))),
                                        v55),
                                      v37.m_quad);
            --v67;
          }
          while ( v67 );
          v47 = LODWORD(paddingRadius);
        }
      }
      else
      {
        hkErrStream::hkErrStream((hkErrStream *)&aabb, &buf, 512);
        v51 = ((unsigned int)*(unsigned __int16 *)(v157 + 2i64 * *(unsigned __int8 *)(v148.m128_u64[0] + 4 * v32)) >> 4) & 3;
        v52 = hkOstream::operator<<((hkOstream *)&aabb, "Compression method #");
        v53 = hkOstream::operator<<(v52, v51, (int)v52);
        hkOstream::operator<<(v53, " not implemented");
        if ( (unsigned int)hkError::messageError(
                             -1875965459,
                             &buf,
                             "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTree/hkcd"
                             "StaticMeshTree.inl",
                             499) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&aabb);
        v47 = LODWORD(paddingRadius);
        v42 = v157;
      }
    }
    else
    {
      v70 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
      v71 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
      v72 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
      v73 = v146 + 8i64 * v45;
      v74 = _mm_mul_ps(
              _mm_sub_ps(v38, v37.m_quad),
              (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters'::`2'::invBitScalesBuffer);
      v75 = 0;
      if ( v47 - 1 > 0 )
      {
        v76 = hkpBvCompressedMeshShape::g_vertexBufferPool[v41];
        do
        {
          v76 += 2;
          v77 = (__m128i)*(unsigned int *)(v73 + 4i64 * (signed int)((v75 & 0xFFFFFFFE) - (v75 & 1) + 1));
          v78 = v75 + 1;
          v75 += 2;
          v76[-2].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v77, 0x16u), 0), v70),
                                     _mm_and_si128(v72, v77)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v77, 0xBu), 0), v71))),
                               v74),
                             v37.m_quad);
          v79 = (__m128i)*(unsigned int *)(v73 + 4i64 * (signed int)((v78 & 0xFFFFFFFE) - (v78 & 1) + 1));
          v76[-1].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v79, 0x16u), 0), v70),
                                     _mm_and_si128(v72, v79)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v79, 0xBu), 0), v71))),
                               v74),
                             v37.m_quad);
        }
        while ( v75 < v47 - 1 );
      }
      if ( v75 < (signed __int64)v47 )
      {
        v80 = (signed __int64)&v46[v75];
        v81 = v47 - (signed __int64)v75;
        do
        {
          v80 += 16i64;
          v82 = v75 & 1;
          v83 = v75++ & 0xFFFFFFFE;
          v84 = (__m128i)*(unsigned int *)(v73 + 4i64 * (signed int)(v83 - v82 + 1));
          *(__m128 *)(v80 - 16) = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_cvtepi32_ps(
                                        _mm_or_si128(
                                          _mm_or_si128(
                                            _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v84, 0x16u), 0), v70),
                                            _mm_and_si128(v72, v84)),
                                          _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v84, 0xBu), 0), v71))),
                                      v74),
                                    v37.m_quad);
          --v81;
        }
        while ( v81 );
      }
    }
  }
  else
  {
    v85 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
    v86 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
    v87 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
    v88 = v146 + 8i64 * v45;
    v89 = 0;
    if ( v47 - 1 > 0 )
    {
      v90 = hkpBvCompressedMeshShape::g_vertexBufferPool[v41];
      v91 = (const __m128i *)(v146 + 8i64 * v45);
      v92 = ((unsigned int)(v47 - 2) >> 1) + 1;
      v93 = v92;
      v89 = 2 * v92;
      do
      {
        v94 = _mm_loadl_epi64(v91);
        v90 += 2;
        ++v91;
        v90[-2].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v94, 0xAu), 85), v85),
                                   _mm_and_si128(v87, v94)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v94, 2), 5u), v86))),
                             v12),
                           (__m128)v8);
        v95 = _mm_loadl_epi64((const __m128i *)((char *)v91 - 8));
        v90[-1].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v95, 0xAu), 85), v85),
                                   _mm_and_si128(v87, v95)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v95, 2), 5u), v86))),
                             v12),
                           (__m128)v8);
        --v93;
      }
      while ( v93 );
    }
    if ( v89 < (signed __int64)v47 )
    {
      v96 = (signed __int64)&v46[v89];
      v97 = v47 - (signed __int64)v89;
      do
      {
        v98 = v89;
        v96 += 16i64;
        ++v89;
        v99 = _mm_loadl_epi64((const __m128i *)(v88 + 8 * v98));
        *(__m128 *)(v96 - 16) = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(
                                      _mm_or_si128(
                                        _mm_or_si128(
                                          _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v99, 0xAu), 85), v85),
                                          _mm_and_si128(v87, v99)),
                                        _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v99, 2), 5u), v86))),
                                    v12),
                                  (__m128)v8);
        --v97;
      }
      while ( v97 );
    }
  }
  v100 = v148.m128_u64[0];
  v101 = *(unsigned __int8 *)(v148.m128_u64[0] + 4 * v32);
  v102 = *(_WORD *)(v42 + 2 * v101) & 0xF;
  if ( v102 < 0 )
    goto LABEL_105;
  if ( v102 <= 3 )
  {
    if ( !v102 )
    {
      hkpBvCompressedMeshShape_Internals::expandBoxVertices(v46);
      v47 = 8;
      LODWORD(paddingRadius) = 8;
    }
    if ( v4 )
    {
      hkpConvexVerticesShape::hkpConvexVerticesShape((hkpConvexVerticesShape *)v4, *(float *)(v154 + 8));
      v47 = LODWORD(paddingRadius);
      v104 = 0i64;
      v36 = v105;
    }
    else
    {
      v104 = 0i64;
      v36 = 0i64;
    }
    v106 = (v47 + 3) & 0xFFFFFFFC;
    v107 = v106;
    v108 = v106 >> 2;
    if ( v47 < (signed __int64)v106 )
    {
      qmemcpy(&v46[v47], &v46[v47 - 1], 8 * (2 * (v106 - (signed __int64)v47) & 0x1FFFFFFFFFFFFFFEi64));
      v100 = v148.m128_u64[0];
    }
    v109 = (__m128)xmmword_141A712A0;
    v110 = 0;
    v111 = _mm_xor_ps(
             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
             (__m128)xmmword_141A712A0);
    if ( v106 > 0i64 )
    {
      v112 = &v46[2].m_quad;
      do
      {
        v113 = _mm_min_ps(v109, v112[-2]);
        v114 = _mm_max_ps(v111, v112[-2]);
        v115 = v112[-2];
        v116 = v112[-1];
        v117 = *v112;
        v118 = v112[1];
        v119 = v110;
        v104 += 4i64;
        v110 += 4;
        v112 += 4;
        v120 = 3 * (v119 >> 2);
        v121 = _mm_shuffle_ps(v115, v116, 68);
        v122 = _mm_shuffle_ps(v117, v118, 68);
        v109 = _mm_min_ps(_mm_min_ps(_mm_min_ps(v113, v112[-5]), v112[-4]), v112[-3]);
        v111 = _mm_max_ps(_mm_max_ps(_mm_max_ps(v114, v112[-5]), v112[-4]), v112[-3]);
        v46[v120].m_quad = _mm_shuffle_ps(v121, v122, 136);
        v46[v120 + 1].m_quad = _mm_shuffle_ps(v121, v122, 221);
        v46[v120 + 2].m_quad = _mm_shuffle_ps(_mm_shuffle_ps(v115, v116, 238), _mm_shuffle_ps(v117, v118, 238), 136);
      }
      while ( v104 < v107 );
    }
    *(_QWORD *)&(*v36)[80] = v46;
    *(_DWORD *)&(*v36)[88] = v108;
    *(_DWORD *)&(*v36)[92] = v108;
    *(_DWORD *)&(*v36)[96] = v47;
    (*v36)[100] = 1;
    *(__m128 *)&(*v36)[48] = _mm_mul_ps(_mm_sub_ps(v111, v109), (__m128)xmmword_141A711B0);
    *(__m128 *)&(*v36)[64] = _mm_mul_ps(_mm_add_ps(v111, v109), (__m128)xmmword_141A711B0);
    goto LABEL_77;
  }
  if ( v102 != 4 )
  {
LABEL_105:
    hkErrStream::hkErrStream((hkErrStream *)&aabb, &buf, 512);
    hkOstream::operator<<((hkOstream *)&aabb, "Not implemented");
    if ( (unsigned int)hkError::messageError(
                         2006496283,
                         &buf,
                         "Collide\\BvCompressedMesh\\hkpBvCompressedMeshShape.cpp",
                         506) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&aabb);
    *v46 = 0i64;
LABEL_77:
    v123 = *(unsigned __int8 *)(v100 + 4 * v32);
    if ( *(_BYTE *)(v157 + 2 * v123) & 0xC0 )
    {
      LODWORD(paddingRadius) = *(signed __int16 *)(v157 + 2i64 * *(unsigned __int8 *)(v100 + 4 * v32) + 4) << 16;
      *(float *)&(*v36)[32] = paddingRadius;
    }
    goto LABEL_60;
  }
  LODWORD(paddingRadius) = *(signed __int16 *)(v42 + 2i64 * *(unsigned __int8 *)(v148.m128_u64[0] + 4 * v32) + 4) << 16;
  LODWORD(cylinderRadius) = *(signed __int16 *)(v42 + 2 * v101 + 6) << 16;
  if ( v4 )
  {
    hkpCylinderShape::hkpCylinderShape((hkpCylinderShape *)v4, v46, v46 + 1, cylinderRadius, paddingRadius);
    v36 = v103;
  }
  else
  {
    v36 = 0i64;
  }
LABEL_60:
  if ( *(_BYTE *)(v154 + 14) )
  {
    v145 = v31 >> 8;
    if ( *(_DWORD *)(v154 + 40) )
      *(_QWORD *)&(*v36)[24] = *(unsigned int *)(*(_QWORD *)(v154 + 32) + 4i64 * (unsigned __int8)v145);
    else
      *(_QWORD *)&(*v36)[24] = (unsigned __int8)v145;
  }
  else
  {
    *(_QWORD *)&(*v36)[24] = 0i64;
  }
  return (hkpShape *)v36;
}

// File Line: 557
// RVA: 0xE00860
__int64 __fastcall hkpBvCompressedMeshShape::getCollisionFilterInfo(hkpBvCompressedMeshShape *this, unsigned int key)
{
  hkpBvCompressedMeshShape *v2; // rsi
  __int64 result; // rax
  _BYTE *v4; // rbx
  __int64 v5; // rax
  int v6; // er11
  signed __int64 v7; // rdx
  unsigned __int64 v8; // rdi
  int v9; // er8
  int v10; // edx
  int i; // ecx
  int v12; // ecx
  int v13; // er9
  int v14; // er9
  signed __int64 v15; // rdx
  int v16; // er8

  v2 = this;
  if ( !*((_BYTE *)&this->m_referenceCount + 3) )
    return 0i64;
  v4 = 0i64;
  v5 = key >> 8;
  v6 = (unsigned __int8)key >> 1;
  v7 = 0i64;
  v8 = 0i64;
  if ( (_DWORD)v5 != -1 )
  {
    v7 = *(_QWORD *)&this->m_tree[24] + 96 * v5;
    v8 = *(_QWORD *)&this->m_tree[104] + 8 * ((unsigned __int64)*(unsigned int *)(v7 + 84) >> 8);
  }
  v9 = 0;
  v10 = *(unsigned __int8 *)(v7 + 84) - 1;
  for ( i = v10 + 1; i > 4; i = v10 - v9 + 1 )
  {
    v12 = (v10 + v9) >> 1;
    v13 = v6 - *(unsigned __int8 *)(v8 + 8i64 * v12 + 4);
    if ( v13 < 0 )
    {
      v10 = (v10 + v9) >> 1;
    }
    else
    {
      if ( v13 < *(unsigned __int8 *)(v8 + 8i64 * v12 + 5) )
      {
        v4 = (_BYTE *)(v8 + 8i64 * v12);
        goto LABEL_18;
      }
      v9 = v12 + 1;
    }
  }
  v14 = 0;
  v15 = v8 + 8i64 * v9;
  if ( i > 0 )
  {
    while ( 1 )
    {
      v16 = v6 - *(unsigned __int8 *)(v15 + 4);
      if ( v16 >= 0 && v16 < *(unsigned __int8 *)(v15 + 5) )
        break;
      ++v14;
      v15 += 8i64;
      if ( v14 >= i )
        goto LABEL_18;
    }
    v4 = (_BYTE *)v15;
  }
LABEL_18:
  LOBYTE(result) = *v4;
  if ( LODWORD(v2->m_userData) )
    result = *(unsigned int *)(*(_QWORD *)&v2->m_type.m_storage + 4i64 * (unsigned __int8)result);
  else
    result = (unsigned __int8)result;
  return result;
}

