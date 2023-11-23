// File Line: 47
// RVA: 0xE09F30
char __fastcall hkpBvCompressedMeshShapeGc::isKeyConvertionAllowed(hkpBvCompressedMeshShapeGc *this, unsigned int key)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *m_includeKeys; // r11
  __int64 m_size; // rdx
  int v5; // eax
  __int64 v6; // r8
  unsigned int *m_data; // rcx
  hkArray<unsigned int,hkContainerHeapAllocator> *m_excludeKeys; // rcx
  __int64 v10; // r8
  int v11; // eax
  __int64 v12; // rdx
  unsigned int *v13; // rcx

  m_includeKeys = this->m_includeKeys;
  if ( m_includeKeys )
  {
    m_size = m_includeKeys->m_size;
    v5 = 0;
    v6 = 0i64;
    if ( m_size <= 0 )
    {
LABEL_6:
      v5 = -1;
    }
    else
    {
      m_data = m_includeKeys->m_data;
      while ( *m_data != key )
      {
        ++v6;
        ++v5;
        ++m_data;
        if ( v6 >= m_size )
          goto LABEL_6;
      }
    }
    return v5 != -1;
  }
  else
  {
    m_excludeKeys = this->m_excludeKeys;
    if ( m_excludeKeys )
    {
      v10 = m_excludeKeys->m_size;
      v11 = 0;
      v12 = 0i64;
      if ( v10 <= 0 )
      {
LABEL_13:
        v11 = -1;
      }
      else
      {
        v13 = m_excludeKeys->m_data;
        while ( *v13 != key )
        {
          ++v12;
          ++v11;
          ++v13;
          if ( v12 >= v10 )
            goto LABEL_13;
        }
      }
      return v11 == -1;
    }
    else
    {
      return 1;
    }
  }
}

// File Line: 54
// RVA: 0xE070A0
void __fastcall hkpBvCompressedMeshShapeGc::appendCustomPrimitiveToGeometry(
        hkpBvCompressedMeshShapeGc *this,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Decoder *decoder,
        int primitiveIndex,
        hkGeometry *geometry)
{
  hkpBvCompressedMeshShapeTreeDataRun *m_primitiveDataRuns; // r11
  int v5; // edi
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *m_section; // r15
  __int64 v8; // rbx
  int v11; // r10d
  hkpBvCompressedMeshShapeTreeDataRun *v12; // r14
  int v13; // r8d
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // r9d
  hkpBvCompressedMeshShapeTreeDataRun *v18; // rcx
  int v19; // r8d
  int m_value; // eax
  hkcdStaticMeshTreeBase::Primitive *m_primitives; // rcx
  __int64 v22; // r14
  int v23; // edx
  int v24; // edx
  __int64 m_size; // r8
  int v26; // r9d
  __int64 v27; // rdx
  char *p_m_data; // rcx
  const unsigned __int16 *m_sharedVerticesIndex; // r9
  __int64 v30; // r8
  unsigned int v31; // ecx
  unsigned __int16 v32; // dx
  int v33; // r10d
  __int64 v34; // r9
  int v35; // ecx
  int v36; // ecx
  int v37; // ebx
  hkOstream *v38; // rax
  hkOstream *v39; // rax
  hkVector4f v40; // xmm5
  int v41; // ebx
  int v42; // r8d
  __m128 v43; // xmm4
  const unsigned __int64 *v44; // r11
  hkAabb *v45; // r10
  unsigned int v46; // eax
  __m128i v47; // xmm0
  __m128i v48; // xmm2
  __m128i v49; // xmm3
  int v50; // ecx
  int v51; // eax
  unsigned int v52; // eax
  __m128 *v53; // r10
  __int64 v54; // r9
  unsigned int v55; // ecx
  unsigned int v56; // eax
  hkVector4f v57; // xmm4
  __m128i v58; // xmm5
  __int64 v59; // rcx
  int v60; // r10d
  int v61; // edx
  __m128i v62; // xmm6
  __m128i v63; // xmm7
  __m128 v64; // xmm3
  const unsigned __int64 *v65; // r11
  hkAabb *v66; // r8
  __m128i v67; // xmm1
  int v68; // eax
  __m128 *v69; // r8
  __int64 v70; // r9
  int v71; // eax
  unsigned int v72; // ecx
  __m128i v73; // xmm3
  __m128i v74; // xmm4
  __m128i v75; // xmm5
  const unsigned __int64 *v76; // r11
  int v77; // ecx
  hkAabb *v78; // rdx
  const __m128i *v79; // r8
  unsigned int v80; // eax
  __int64 v81; // r10
  __m128i v82; // xmm2
  __m128i v83; // xmm1
  __m128i v84; // xmm2
  __m128 v85; // xmm0
  __m128 *v86; // rdx
  __int64 v87; // r9
  __int64 v88; // rax
  hkVector4f v89; // xmm11
  hkVector4f v90; // xmm12
  __m128 v91; // xmm6
  __m128 v92; // xmm14
  __m128 v93; // xmm1
  __m128 v94; // xmm3
  __m128 v95; // xmm2
  __m128 v96; // xmm6
  __m128 v97; // xmm1
  __m128 v98; // xmm4
  float v99; // xmm1_4
  __m128 v100; // xmm7
  __m128 v101; // xmm2
  __m128 v102; // xmm8
  __m128 v103; // xmm2
  __m128 v104; // xmm6
  __m128 v105; // xmm6
  __m128 v106; // xmm1
  __m128 v107; // xmm3
  __m128 v108; // xmm2
  __m128 v109; // xmm1
  __m128 v110; // xmm6
  __m128 v111; // xmm10
  int j; // ebx
  __m128i v113; // xmm6
  __m128 v114; // xmm9
  __m128i v115; // xmm8
  __m128 v116; // xmm9
  __m128 v117; // xmm2
  __m128i v118; // xmm6
  __m128 v119; // xmm4
  __m128 v120; // xmm5
  __m128 v121; // xmm4
  __m128 v122; // xmm2
  __m128 v123; // xmm0
  __m128 v124; // xmm4
  __m128 v125; // xmm3
  __m128 v126; // xmm5
  __m128 v127; // xmm1
  __m128 v128; // xmm3
  int v129; // ecx
  __m128 v130; // xmm6
  __m128 v131; // xmm6
  int v132; // ecx
  int v133; // r8d
  hkVector4f *v134; // rdx
  unsigned __int16 v135; // dx
  int v136; // r10d
  __int64 v137; // r9
  int v138; // ecx
  int v139; // ecx
  int v140; // ebx
  hkOstream *v141; // rax
  hkOstream *v142; // rax
  hkVector4f v143; // xmm5
  int v144; // ebx
  int v145; // r8d
  __m128 v146; // xmm4
  const unsigned __int64 *v147; // r11
  hkAabb *v148; // r10
  unsigned int v149; // eax
  __m128i v150; // xmm0
  __m128i v151; // xmm2
  __m128i v152; // xmm3
  int v153; // ecx
  int v154; // eax
  unsigned int v155; // eax
  __m128 *v156; // r10
  __int64 v157; // r9
  unsigned int v158; // ecx
  unsigned int v159; // eax
  hkVector4f v160; // xmm4
  __m128i v161; // xmm5
  __int64 v162; // rcx
  int v163; // r10d
  int v164; // edx
  __m128i v165; // xmm6
  __m128i v166; // xmm7
  __m128 v167; // xmm3
  const unsigned __int64 *v168; // r11
  hkAabb *v169; // r8
  __m128i v170; // xmm1
  int v171; // eax
  __m128 *v172; // r8
  __int64 v173; // r9
  int v174; // eax
  unsigned int v175; // ecx
  __m128i v176; // xmm3
  __m128i v177; // xmm4
  __m128i v178; // xmm5
  const unsigned __int64 *v179; // r11
  int v180; // ecx
  hkAabb *v181; // rdx
  const __m128i *v182; // r8
  unsigned int v183; // eax
  __int64 v184; // r10
  __m128i v185; // xmm2
  __m128i v186; // xmm1
  __m128i v187; // xmm2
  __m128 v188; // xmm0
  __m128 *v189; // rdx
  __int64 v190; // r9
  __int64 v191; // rax
  hkVector4f v192; // xmm10
  hkVector4f v193; // xmm11
  __m128 v194; // xmm9
  __m128 v195; // xmm12
  __m128 v196; // xmm1
  __m128 v197; // xmm3
  __m128 v198; // xmm2
  __m128 v199; // xmm9
  __m128 v200; // xmm1
  __m128 v201; // xmm4
  float v202; // xmm1_4
  __m128 v203; // xmm7
  __m128 v204; // xmm2
  __m128 v205; // xmm8
  __m128 v206; // xmm6
  __m128 v207; // xmm2
  __m128 v208; // xmm6
  __m128 v209; // xmm1
  __m128 v210; // xmm3
  __m128 v211; // xmm2
  __m128 v212; // xmm1
  __m128 v213; // xmm6
  int i; // r14d
  int v215; // esi
  __m128 v216; // xmm7
  int v217; // ecx
  __m128 v218; // xmm1
  hkVector4f *v219; // rbx
  __m128 v220; // xmm1
  __m128 v221; // xmm5
  __m128 v222; // xmm4
  __m128 v223; // xmm6
  __m128 v224; // xmm6
  __m128 v225; // xmm2
  __m128 m_quad; // xmm0
  unsigned __int16 v227; // dx
  BOOL v228; // ebx
  __int64 v229; // r9
  int v230; // ecx
  int v231; // ecx
  int v232; // ebx
  hkOstream *v233; // rax
  hkOstream *v234; // rax
  hkVector4f v235; // xmm5
  int v236; // ebx
  int v237; // r8d
  __m128 v238; // xmm4
  const unsigned __int64 *v239; // r11
  hkAabb *p_aabb; // r10
  unsigned int v241; // eax
  __m128i v242; // xmm0
  __m128i v243; // xmm2
  __m128i v244; // xmm3
  int v245; // ecx
  int v246; // eax
  unsigned int v247; // eax
  __m128 *v248; // r10
  __int64 v249; // r9
  unsigned int v250; // ecx
  unsigned int v251; // eax
  hkVector4f v252; // xmm4
  __m128i si128; // xmm5
  __int64 v254; // rcx
  int v255; // ebx
  int v256; // edx
  __m128i v257; // xmm6
  __m128i v258; // xmm7
  __m128 v259; // xmm3
  const unsigned __int64 *v260; // r10
  hkAabb *v261; // r8
  __m128i v262; // xmm1
  int v263; // eax
  __m128 *v264; // r8
  __int64 v265; // r9
  int v266; // eax
  unsigned int v267; // ecx
  __m128i v268; // xmm3
  __m128i v269; // xmm4
  __m128i v270; // xmm5
  const unsigned __int64 *v271; // r11
  int v272; // ecx
  hkAabb *v273; // rdx
  const __m128i *v274; // r8
  unsigned int v275; // eax
  __int64 v276; // r10
  __m128i v277; // xmm2
  __m128i v278; // xmm1
  __m128i v279; // xmm2
  __m128 v280; // xmm0
  __m128 *v281; // rdx
  __int64 v282; // r9
  __int64 v283; // rax
  int v284; // edx
  __m128 v285; // xmm8
  int v286; // r14d
  hkVector4f v287; // xmm9
  int v288; // esi
  __m128 v289; // xmm6
  int v290; // ecx
  __m128 v291; // xmm1
  hkVector4f *v292; // rbx
  unsigned __int16 v293; // r10
  int v294; // edx
  __int64 v295; // r9
  int v296; // ecx
  int v297; // ecx
  int v298; // ebx
  hkOstream *v299; // rax
  hkOstream *v300; // rax
  hkVector4f v301; // xmm5
  int v302; // r8d
  __m128 v303; // xmm4
  const unsigned __int64 *v304; // r11
  hkVector4f *v305; // r10
  unsigned int v306; // eax
  __m128i v307; // xmm0
  __m128i v308; // xmm2
  __m128i v309; // xmm3
  int v310; // ecx
  int v311; // eax
  unsigned int v312; // eax
  hkVector4f *v313; // r10
  __int64 v314; // r9
  unsigned int v315; // ecx
  unsigned int v316; // eax
  hkVector4f v317; // xmm4
  __m128i v318; // xmm5
  __int64 v319; // rcx
  int v320; // r10d
  __m128i v321; // xmm6
  __m128i v322; // xmm7
  __m128 v323; // xmm3
  const unsigned __int64 *v324; // r8
  hkVector4f *v325; // rdx
  __m128i v326; // xmm1
  int v327; // eax
  hkVector4f *v328; // rdx
  __int64 v329; // r9
  int v330; // eax
  unsigned int v331; // ecx
  __m128i v332; // xmm3
  __m128i v333; // xmm4
  __m128i v334; // xmm5
  const unsigned __int64 *v335; // r10
  int v336; // eax
  hkVector4f *v337; // rcx
  const __m128i *v338; // rdx
  unsigned int v339; // eax
  __int64 v340; // r8
  __m128i v341; // xmm2
  hkVector4f *v342; // rcx
  __int64 v343; // r9
  __int64 v344; // rax
  __m128 v345; // xmm5
  hkVector4f *array; // [rsp+30h] [rbp-D0h] BYREF
  int numVertices; // [rsp+38h] [rbp-C8h]
  int v348; // [rsp+3Ch] [rbp-C4h]
  hkAabb aabb; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f *vertices; // [rsp+60h] [rbp-A0h] BYREF
  int v351; // [rsp+68h] [rbp-98h]
  int v352; // [rsp+6Ch] [rbp-94h]
  hkVector4f *v353; // [rsp+70h] [rbp-90h] BYREF
  int v354; // [rsp+78h] [rbp-88h]
  int v355; // [rsp+7Ch] [rbp-84h]
  hkResult v356; // [rsp+80h] [rbp-80h] BYREF
  hkResult result; // [rsp+84h] [rbp-7Ch] BYREF
  hkQuaternionf v358; // [rsp+90h] [rbp-70h] BYREF
  hkResult v359; // [rsp+A0h] [rbp-60h] BYREF
  hkQuaternionf v360; // [rsp+B0h] [rbp-50h] BYREF
  hkVector4f from; // [rsp+C0h] [rbp-40h] BYREF
  hkErrStream v362; // [rsp+D0h] [rbp-30h] BYREF
  hkVector4f v363; // [rsp+F0h] [rbp-10h] BYREF
  hkErrStream v364; // [rsp+100h] [rbp+0h] BYREF
  hkVector4f v365; // [rsp+120h] [rbp+20h] BYREF
  hkErrStream v366; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f uv; // [rsp+150h] [rbp+50h] BYREF
  hkErrStream v368; // [rsp+160h] [rbp+60h] BYREF
  hkErrStream v369; // [rsp+178h] [rbp+78h] BYREF
  hkVector4f v370; // [rsp+190h] [rbp+90h] BYREF
  __m128 v371; // [rsp+1A0h] [rbp+A0h]
  __m128 v372; // [rsp+1B0h] [rbp+B0h]
  __m128 v373; // [rsp+1C0h] [rbp+C0h]
  __m128 v374; // [rsp+1D0h] [rbp+D0h]
  __m128 v375; // [rsp+1E0h] [rbp+E0h]
  __m128 v376; // [rsp+1F0h] [rbp+F0h]
  __m128 v377; // [rsp+200h] [rbp+100h]
  __m128 v378; // [rsp+210h] [rbp+110h]
  __m128i v379; // [rsp+220h] [rbp+120h]
  __m128i v380; // [rsp+230h] [rbp+130h]
  __m128 v381; // [rsp+240h] [rbp+140h]
  __m128i v382; // [rsp+250h] [rbp+150h]
  __m128i v383; // [rsp+260h] [rbp+160h]
  __m128i v384; // [rsp+270h] [rbp+170h]
  __m128i v385; // [rsp+280h] [rbp+180h]
  __m128i v386; // [rsp+290h] [rbp+190h]
  __m128i v387; // [rsp+2A0h] [rbp+1A0h]
  __m128i v388; // [rsp+2B0h] [rbp+1B0h]
  __m128 v389; // [rsp+2C0h] [rbp+1C0h]
  __m128i v390; // [rsp+2D0h] [rbp+1D0h]
  __m128i v391; // [rsp+2E0h] [rbp+1E0h]
  __m128i v392; // [rsp+2F0h] [rbp+1F0h]
  __m128i v393; // [rsp+300h] [rbp+200h]
  __m128i v394; // [rsp+310h] [rbp+210h]
  __m128i v395; // [rsp+320h] [rbp+220h]
  hkVector4f v396; // [rsp+330h] [rbp+230h]
  __m128 v397; // [rsp+340h] [rbp+240h]
  __m128i v398; // [rsp+350h] [rbp+250h]
  hkVector4f v399; // [rsp+360h] [rbp+260h]
  __m128 v400; // [rsp+370h] [rbp+270h]
  __m128i v401; // [rsp+380h] [rbp+280h]
  hkVector4f v402; // [rsp+390h] [rbp+290h]
  __m128 v403; // [rsp+3A0h] [rbp+2A0h]
  __m128 v404; // [rsp+3B0h] [rbp+2B0h]
  hkVector4f v405; // [rsp+3C0h] [rbp+2C0h]
  __m128 v406; // [rsp+3D0h] [rbp+2D0h]
  __m128i v407; // [rsp+3E0h] [rbp+2E0h]
  hkVector4f v408; // [rsp+3F0h] [rbp+2F0h]
  __m128 v409; // [rsp+400h] [rbp+300h]
  __m128i v410; // [rsp+410h] [rbp+310h]
  hkVector4f v411; // [rsp+420h] [rbp+320h]
  __m128 v412; // [rsp+430h] [rbp+330h]
  __m128 v413; // [rsp+440h] [rbp+340h]
  hkVector4f v414; // [rsp+450h] [rbp+350h]
  __m128 v415; // [rsp+460h] [rbp+360h]
  __m128i v416; // [rsp+470h] [rbp+370h]
  hkVector4f v417; // [rsp+480h] [rbp+380h]
  __m128 v418; // [rsp+490h] [rbp+390h]
  __m128i v419; // [rsp+4A0h] [rbp+3A0h]
  __m128 v420; // [rsp+4B0h] [rbp+3B0h]
  __m128i v421; // [rsp+4C0h] [rbp+3C0h]
  __m128i v422; // [rsp+4D0h] [rbp+3D0h]
  __m128 v423; // [rsp+4E0h] [rbp+3E0h]
  __m128i v424; // [rsp+4F0h] [rbp+3F0h]
  __m128 v425; // [rsp+500h] [rbp+400h]
  char buf[512]; // [rsp+510h] [rbp+410h] BYREF
  char v427[512]; // [rsp+710h] [rbp+610h] BYREF
  char v428[512]; // [rsp+910h] [rbp+810h] BYREF
  char description[512]; // [rsp+B10h] [rbp+A10h] BYREF
  char v430[512]; // [rsp+D10h] [rbp+C10h] BYREF
  unsigned int v431; // [rsp+FF8h] [rbp+EF8h]
  unsigned int v432; // [rsp+FF8h] [rbp+EF8h]
  int material; // [rsp+1000h] [rbp+F00h]

  m_primitiveDataRuns = decoder->m_primitiveDataRuns;
  v5 = 0;
  m_section = decoder->m_section;
  v8 = primitiveIndex;
  v11 = (unsigned __int8)m_section[1].m_domain.m_max.m_quad.m128_i8[4] - 1;
  v12 = 0i64;
  v13 = 0;
  v14 = (unsigned __int8)m_section[1].m_domain.m_max.m_quad.m128_i8[4];
  if ( (unsigned int)v14 > 4 )
  {
    do
    {
      v15 = (v11 + v13) >> 1;
      v16 = v8 - (unsigned __int8)m_primitiveDataRuns[v15].m_index;
      if ( v16 < 0 )
      {
        v11 = (v11 + v13) >> 1;
      }
      else
      {
        if ( v16 < (unsigned __int8)m_primitiveDataRuns[v15].m_count )
        {
          v12 = &m_primitiveDataRuns[v15];
          goto LABEL_14;
        }
        v13 = v15 + 1;
      }
      v14 = v11 - v13 + 1;
    }
    while ( v14 > 4 );
  }
  v17 = 0;
  v18 = &m_primitiveDataRuns[v13];
  if ( v14 > 0 )
  {
    while ( 1 )
    {
      v19 = v8 - (unsigned __int8)v18->m_index;
      if ( v19 >= 0 && v19 < (unsigned __int8)v18->m_count )
        break;
      ++v17;
      ++v18;
      if ( v17 >= v14 )
        goto LABEL_14;
    }
    v12 = v18;
  }
LABEL_14:
  m_value = v12->m_value;
  m_primitives = decoder->m_primitives;
  v22 = v8;
  v23 = (unsigned __int8)m_primitives[v8].m_indices[2];
  material = m_value;
  if ( (unsigned __int8)m_primitives[v8].m_indices[3] == v23 && v23 == (unsigned __int8)m_primitives[v8].m_indices[1] )
  {
    v24 = (unsigned __int8)m_primitives[v8].m_indices[1];
  }
  else
  {
    m_size = m_section->m_nodes.m_size;
    v26 = 0;
    v27 = 0i64;
    if ( m_size <= 0 )
    {
LABEL_22:
      v26 = -1;
    }
    else
    {
      p_m_data = &m_section->m_nodes.m_data->m_data;
      while ( (*p_m_data & 1) != 0 || (_DWORD)v8 != (unsigned __int8)*p_m_data >> 1 )
      {
        ++v27;
        ++v26;
        p_m_data += 4;
        if ( v27 >= m_size )
          goto LABEL_22;
      }
    }
    v24 = v26;
  }
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(m_section, v24, &aabb);
  m_sharedVerticesIndex = decoder->m_sharedVerticesIndex;
  v30 = (unsigned __int8)decoder->m_primitives[v8].m_indices[0];
  v31 = m_sharedVerticesIndex[v30];
  if ( (m_sharedVerticesIndex[v30] & 0xF) != 0 )
  {
    switch ( m_sharedVerticesIndex[v30] & 0xF )
    {
      case 1:
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendCustomPrimitiveToGeometry(
          this,
          decoder,
          v8,
          geometry);
        return;
      case 2:
        v227 = m_sharedVerticesIndex[v30 + 1];
        v228 = v31 >> 8 != 0;
        v229 = v31 >> 8 != 0;
        v230 = (v31 >> 4) & 3;
        if ( v230 )
        {
          v231 = v230 - 1;
          if ( v231 )
          {
            if ( v231 == 1 )
            {
              v235.m_quad = (__m128)aabb.m_min;
              v236 = v228 - 1;
              v237 = 0;
              v408.m_quad = (__m128)aabb.m_min;
              v238 = _mm_mul_ps(
                       _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                       (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters::`2::invBitScalesBuffer);
              v409 = v238;
              v239 = &decoder->m_sharedVertices[v227];
              if ( v236 > 0 )
              {
                p_aabb = &aabb;
                do
                {
                  ++p_aabb;
                  v241 = *((unsigned __int16 *)v239 + (int)((v237 & 0xFFFFFFFC) - (v237 & 3) + 3));
                  v242 = _mm_cvtsi32_si128(v241 >> 10);
                  v243 = _mm_cvtsi32_si128((v241 >> 5) & 0x1F);
                  v244 = _mm_cvtsi32_si128(*((_WORD *)v239 + (int)((v237 & 0xFFFFFFFC) - (v237 & 3) + 3)) & 0x1F);
                  v245 = v237 + 1;
                  v246 = (v237 + 1) & 3;
                  v237 += 2;
                  v247 = *((unsigned __int16 *)v239 + (int)((v245 & 0xFFFFFFFC) - v246 + 3));
                  p_aabb[-1].m_min.m_quad = _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_cvtepi32_ps(
                                                  _mm_unpacklo_epi32(
                                                    _mm_unpacklo_epi32(v244, v242),
                                                    _mm_unpacklo_epi32(v243, _mm_cvtsi32_si128(0)))),
                                                v238),
                                              v235.m_quad);
                  p_aabb[-1].m_max.m_quad = _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_cvtepi32_ps(
                                                  _mm_unpacklo_epi32(
                                                    _mm_unpacklo_epi32(
                                                      _mm_cvtsi32_si128(v247 & 0x1F),
                                                      _mm_cvtsi32_si128(v247 >> 10)),
                                                    _mm_unpacklo_epi32(
                                                      _mm_cvtsi32_si128((v247 >> 5) & 0x1F),
                                                      _mm_cvtsi32_si128(0)))),
                                                v238),
                                              v235.m_quad);
                }
                while ( v237 < v236 );
              }
              if ( v237 < v229 )
              {
                v248 = &aabb.m_min.m_quad + v237;
                v249 = v229 - v237;
                do
                {
                  ++v248;
                  v250 = (v237 & 0xFFFFFFFC) - (v237 & 3);
                  ++v237;
                  v251 = *((unsigned __int16 *)v239 + (int)(v250 + 3));
                  v248[-1] = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(
                                       _mm_cvtsi32_si128(*((_WORD *)v239 + (int)(v250 + 3)) & 0x1F),
                                       _mm_cvtsi32_si128(v251 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v251 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                 v238),
                               v235.m_quad);
                  --v249;
                }
                while ( v249 );
              }
            }
            else
            {
              hkErrStream::hkErrStream(&v368, v428, 512);
              v232 = (decoder->m_sharedVerticesIndex[(unsigned __int8)decoder->m_primitives[v22].m_indices[0]] >> 4) & 3;
              v233 = hkOstream::operator<<(&v368, "Compression method #");
              v234 = hkOstream::operator<<(v233, v232);
              hkOstream::operator<<(v234, " not implemented");
              if ( (unsigned int)hkError::messageError(
                                   0x902F09ED,
                                   v428,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTre"
                                   "e/hkcdStaticMeshTree.inl",
                                   499) )
                __debugbreak();
              hkOstream::~hkOstream(&v368);
            }
          }
          else
          {
            v252.m_quad = (__m128)aabb.m_min;
            si128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
            v254 = v227;
            v255 = v228 - 1;
            v256 = 0;
            v257 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
            v258 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
            v411.m_quad = (__m128)aabb.m_min;
            v259 = _mm_mul_ps(
                     _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                     (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
            v412 = v259;
            v260 = &decoder->m_sharedVertices[v254];
            if ( v255 > 0 )
            {
              v261 = &aabb;
              do
              {
                ++v261;
                v262 = (__m128i)*((unsigned int *)v260 + (int)((v256 & 0xFFFFFFFE) - (v256 & 1) + 1));
                v263 = v256 + 1;
                v256 += 2;
                v393 = v262;
                v261[-1].m_min.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_cvtepi32_ps(
                                              _mm_or_si128(
                                                _mm_or_si128(
                                                  _mm_and_si128(
                                                    _mm_shuffle_epi32(_mm_srli_epi32(v262, 0x16u), 0),
                                                    si128),
                                                  _mm_and_si128(v262, v258)),
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v262, 0xBu), 0), v257))),
                                            v259),
                                          v252.m_quad);
                v424 = (__m128i)*((unsigned int *)v260 + (int)((v263 & 0xFFFFFFFE) - (v263 & 1) + 1));
                v261[-1].m_max.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_cvtepi32_ps(
                                              _mm_or_si128(
                                                _mm_or_si128(
                                                  _mm_and_si128(
                                                    _mm_shuffle_epi32(_mm_srli_epi32(v424, 0x16u), 0),
                                                    si128),
                                                  _mm_and_si128(v424, v258)),
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v424, 0xBu), 0), v257))),
                                            v259),
                                          v252.m_quad);
              }
              while ( v256 < v255 );
            }
            if ( v256 < v229 )
            {
              v264 = &aabb.m_min.m_quad + v256;
              v265 = v229 - v256;
              do
              {
                ++v264;
                v266 = v256 & 1;
                v267 = v256++ & 0xFFFFFFFE;
                v395 = (__m128i)*((unsigned int *)v260 + (int)(v267 - v266 + 1));
                v264[-1] = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v395, 0x16u), 0), si128),
                                     _mm_and_si128(v395, v258)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v395, 0xBu), 0), v257))),
                               v259),
                             v252.m_quad);
                --v265;
              }
              while ( v265 );
            }
          }
        }
        else
        {
          v268 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
          v269 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
          v270 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
          v271 = &decoder->m_sharedVertices[v227];
          v272 = 0;
          if ( v228 - 1 > 0 )
          {
            v273 = &aabb;
            v274 = (const __m128i *)v271;
            v275 = ((unsigned int)(v228 - 2) >> 1) + 1;
            v276 = v275;
            v272 = 2 * v275;
            do
            {
              v277 = _mm_loadl_epi64(v274);
              ++v273;
              ++v274;
              v416 = v277;
              v278 = _mm_or_si128(
                       _mm_or_si128(
                         _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v277, 0xAu), 85), v268),
                         _mm_and_si128(v277, v270)),
                       _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v277, 2), 5u), v269));
              v279 = _mm_loadl_epi64((const __m128i *)((char *)v274 - 8));
              v280 = _mm_add_ps(
                       _mm_mul_ps(_mm_cvtepi32_ps(v278), decoder->m_sharedParms.m_scale.m_quad),
                       decoder->m_sharedParms.m_origin.m_quad);
              v398 = v279;
              v273[-1].m_min.m_quad = v280;
              v273[-1].m_max.m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_cvtepi32_ps(
                                            _mm_or_si128(
                                              _mm_or_si128(
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v279, 0xAu), 85), v268),
                                                _mm_and_si128(v279, v270)),
                                              _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v279, 2), 5u), v269))),
                                          decoder->m_sharedParms.m_scale.m_quad),
                                        decoder->m_sharedParms.m_origin.m_quad);
              --v276;
            }
            while ( v276 );
          }
          if ( v272 < (__int64)v228 )
          {
            v281 = &aabb.m_min.m_quad + v272;
            v282 = v228 - (__int64)v272;
            do
            {
              v283 = v272;
              ++v281;
              ++v272;
              v422 = _mm_loadl_epi64((const __m128i *)&v271[v283]);
              v281[-1] = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v422, 0xAu), 85), v268),
                                   _mm_and_si128(v422, v270)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v422, 2), 5u), v269))),
                             decoder->m_sharedParms.m_scale.m_quad),
                           decoder->m_sharedParms.m_origin.m_quad);
              --v282;
            }
            while ( v282 );
          }
        }
        v284 = (__int16)decoder->m_sharedVerticesIndex[(unsigned __int8)decoder->m_primitives[v22].m_indices[0] + 2];
        v353 = 0i64;
        v354 = 0;
        v355 = 0x80000000;
        v285 = _mm_shuffle_ps((__m128)(unsigned int)(v284 << 16), (__m128)(unsigned int)(v284 << 16), 0);
        hkArrayUtil::_reserve(&v356, &hkContainerHeapAllocator::s_alloc, (const void **)&v353, 144, 16);
        v286 = 0;
        v287.m_quad = (__m128)aabb.m_min;
        do
        {
          v288 = 0;
          v289 = (__m128)COERCE_UNSIGNED_INT((float)v286);
          v289.m128_f32[0] = v289.m128_f32[0] * 0.090909094;
          do
          {
            v290 = v354;
            v291 = (__m128)COERCE_UNSIGNED_INT((float)v288);
            v291.m128_f32[0] = v291.m128_f32[0] * 0.090909094;
            v365.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v289, (__m128)0i64), _mm_unpacklo_ps(v291, (__m128)0i64));
            if ( v354 == (v355 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v353, 16);
              v290 = v354;
            }
            v354 = v290 + 1;
            v292 = &v353[v290];
            hkGeometryProcessing::octahedronToNormal(&v365, v292);
            ++v288;
            v292->m_quad = _mm_add_ps(_mm_mul_ps(v285, v292->m_quad), v287.m_quad);
          }
          while ( v288 < 12 );
          ++v286;
        }
        while ( v286 < 12 );
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
          v353,
          v354,
          material,
          geometry);
        v354 = 0;
        if ( v355 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v353, 16 * v355);
        break;
      case 3:
        v135 = m_sharedVerticesIndex[v30 + 1];
        v136 = 2;
        if ( v31 >> 8 < 2 )
          v136 = v31 >> 8;
        v137 = v136;
        v138 = (v31 >> 4) & 3;
        if ( v138 )
        {
          v139 = v138 - 1;
          if ( v139 )
          {
            if ( v139 == 1 )
            {
              v143.m_quad = (__m128)aabb.m_min;
              v144 = v136 - 1;
              v145 = 0;
              v402.m_quad = (__m128)aabb.m_min;
              v146 = _mm_mul_ps(
                       _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                       (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters::`2::invBitScalesBuffer);
              v403 = v146;
              v147 = &decoder->m_sharedVertices[v135];
              if ( v136 - 1 > 0 )
              {
                v148 = &aabb;
                do
                {
                  ++v148;
                  v149 = *((unsigned __int16 *)v147 + (int)((v145 & 0xFFFFFFFC) - (v145 & 3) + 3));
                  v150 = _mm_cvtsi32_si128(v149 >> 10);
                  v151 = _mm_cvtsi32_si128((v149 >> 5) & 0x1F);
                  v152 = _mm_cvtsi32_si128(*((_WORD *)v147 + (int)((v145 & 0xFFFFFFFC) - (v145 & 3) + 3)) & 0x1F);
                  v153 = v145 + 1;
                  v154 = (v145 + 1) & 3;
                  v145 += 2;
                  v155 = *((unsigned __int16 *)v147 + (int)((v153 & 0xFFFFFFFC) - v154 + 3));
                  v148[-1].m_min.m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_cvtepi32_ps(
                                                _mm_unpacklo_epi32(
                                                  _mm_unpacklo_epi32(v152, v150),
                                                  _mm_unpacklo_epi32(v151, _mm_cvtsi32_si128(0)))),
                                              v146),
                                            v143.m_quad);
                  v148[-1].m_max.m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_cvtepi32_ps(
                                                _mm_unpacklo_epi32(
                                                  _mm_unpacklo_epi32(
                                                    _mm_cvtsi32_si128(v155 & 0x1F),
                                                    _mm_cvtsi32_si128(v155 >> 10)),
                                                  _mm_unpacklo_epi32(
                                                    _mm_cvtsi32_si128((v155 >> 5) & 0x1F),
                                                    _mm_cvtsi32_si128(0)))),
                                              v146),
                                            v143.m_quad);
                }
                while ( v145 < v144 );
              }
              if ( v145 < v137 )
              {
                v156 = &aabb.m_min.m_quad + v145;
                v157 = v137 - v145;
                do
                {
                  ++v156;
                  v158 = (v145 & 0xFFFFFFFC) - (v145 & 3);
                  ++v145;
                  v159 = *((unsigned __int16 *)v147 + (int)(v158 + 3));
                  v156[-1] = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(
                                       _mm_cvtsi32_si128(*((_WORD *)v147 + (int)(v158 + 3)) & 0x1F),
                                       _mm_cvtsi32_si128(v159 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v159 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                 v146),
                               v143.m_quad);
                  --v157;
                }
                while ( v157 );
              }
            }
            else
            {
              hkErrStream::hkErrStream(&v366, v427, 512);
              v140 = (decoder->m_sharedVerticesIndex[(unsigned __int8)decoder->m_primitives[v8].m_indices[0]] >> 4) & 3;
              v141 = hkOstream::operator<<(&v366, "Compression method #");
              v142 = hkOstream::operator<<(v141, v140);
              hkOstream::operator<<(v142, " not implemented");
              if ( (unsigned int)hkError::messageError(
                                   0x902F09ED,
                                   v427,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTre"
                                   "e/hkcdStaticMeshTree.inl",
                                   499) )
                __debugbreak();
              hkOstream::~hkOstream(&v366);
            }
          }
          else
          {
            v160.m_quad = (__m128)aabb.m_min;
            v161 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
            v162 = v135;
            v163 = v136 - 1;
            v164 = 0;
            v165 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
            v166 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
            v405.m_quad = (__m128)aabb.m_min;
            v167 = _mm_mul_ps(
                     _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                     (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
            v406 = v167;
            v168 = &decoder->m_sharedVertices[v162];
            if ( v163 > 0 )
            {
              v169 = &aabb;
              do
              {
                ++v169;
                v170 = (__m128i)*((unsigned int *)v168 + (int)((v164 & 0xFFFFFFFE) - (v164 & 1) + 1));
                v171 = v164 + 1;
                v164 += 2;
                v383 = v170;
                v169[-1].m_min.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_cvtepi32_ps(
                                              _mm_or_si128(
                                                _mm_or_si128(
                                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v170, 0x16u), 0), v161),
                                                  _mm_and_si128(v170, v166)),
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v170, 0xBu), 0), v165))),
                                            v167),
                                          v160.m_quad);
                v407 = (__m128i)*((unsigned int *)v168 + (int)((v171 & 0xFFFFFFFE) - (v171 & 1) + 1));
                v169[-1].m_max.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_cvtepi32_ps(
                                              _mm_or_si128(
                                                _mm_or_si128(
                                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v407, 0x16u), 0), v161),
                                                  _mm_and_si128(v407, v166)),
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v407, 0xBu), 0), v165))),
                                            v167),
                                          v160.m_quad);
              }
              while ( v164 < v163 );
            }
            if ( v164 < v137 )
            {
              v172 = &aabb.m_min.m_quad + v164;
              v173 = v137 - v164;
              do
              {
                ++v172;
                v174 = v164 & 1;
                v175 = v164++ & 0xFFFFFFFE;
                v385 = (__m128i)*((unsigned int *)v168 + (int)(v175 - v174 + 1));
                v172[-1] = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v385, 0x16u), 0), v161),
                                     _mm_and_si128(v385, v166)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v385, 0xBu), 0), v165))),
                               v167),
                             v160.m_quad);
                --v173;
              }
              while ( v173 );
            }
          }
        }
        else
        {
          v176 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
          v177 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
          v178 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
          v179 = &decoder->m_sharedVertices[v135];
          v180 = 0;
          if ( v136 - 1 > 0 )
          {
            v181 = &aabb;
            v182 = (const __m128i *)v179;
            v183 = ((unsigned int)(v136 - 2) >> 1) + 1;
            v184 = v183;
            v180 = 2 * v183;
            do
            {
              v185 = _mm_loadl_epi64(v182);
              ++v181;
              ++v182;
              v421 = v185;
              v186 = _mm_or_si128(
                       _mm_or_si128(
                         _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v185, 0xAu), 85), v176),
                         _mm_and_si128(v185, v178)),
                       _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v185, 2), 5u), v177));
              v187 = _mm_loadl_epi64((const __m128i *)((char *)v182 - 8));
              v188 = _mm_add_ps(
                       _mm_mul_ps(_mm_cvtepi32_ps(v186), decoder->m_sharedParms.m_scale.m_quad),
                       decoder->m_sharedParms.m_origin.m_quad);
              v387 = v187;
              v181[-1].m_min.m_quad = v188;
              v181[-1].m_max.m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_cvtepi32_ps(
                                            _mm_or_si128(
                                              _mm_or_si128(
                                                _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v187, 0xAu), 85), v176),
                                                _mm_and_si128(v187, v178)),
                                              _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v187, 2), 5u), v177))),
                                          decoder->m_sharedParms.m_scale.m_quad),
                                        decoder->m_sharedParms.m_origin.m_quad);
              --v184;
            }
            while ( v184 );
          }
          if ( v180 < v137 )
          {
            v189 = &aabb.m_min.m_quad + v180;
            v190 = v137 - v180;
            do
            {
              v191 = v180;
              ++v189;
              ++v180;
              v410 = _mm_loadl_epi64((const __m128i *)&v179[v191]);
              v189[-1] = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v410, 0xAu), 85), v176),
                                   _mm_and_si128(v410, v178)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v410, 2), 5u), v177))),
                             decoder->m_sharedParms.m_scale.m_quad),
                           decoder->m_sharedParms.m_origin.m_quad);
              --v190;
            }
            while ( v190 );
          }
        }
        v192.m_quad = (__m128)aabb.m_max;
        v193.m_quad = (__m128)aabb.m_min;
        v432 = (__int16)decoder->m_sharedVerticesIndex[(unsigned __int8)decoder->m_primitives[v22].m_indices[0] + 2] << 16;
        v194 = _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad);
        v363.m_quad = _xmm;
        v195 = _mm_shuffle_ps((__m128)v432, (__m128)v432, 0);
        v196 = _mm_mul_ps(v194, v194);
        v197 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v196, v196, 85), _mm_shuffle_ps(v196, v196, 0)),
                 _mm_shuffle_ps(v196, v196, 170));
        v198 = _mm_rsqrt_ps(v197);
        v389 = v197;
        v199 = _mm_mul_ps(
                 v194,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v197, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v198, v197), v198)),
                     _mm_mul_ps(v198, *(__m128 *)_xmm))));
        v200 = _mm_mul_ps(_xmm, v199);
        v201 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v200, v200, 85), _mm_shuffle_ps(v200, v200, 0)),
                 _mm_shuffle_ps(v200, v200, 170));
        v202 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99998999), (__m128)LODWORD(FLOAT_0_99998999), 0).m128_f32[0];
        if ( v201.m128_f32[0] <= v202 )
        {
          if ( v201.m128_f32[0] >= (float)(0.0 - v202) )
          {
            v203 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v201), (__m128)xmmword_141A711B0);
            v204 = _mm_rsqrt_ps(v203);
            v425 = v203;
            v205 = _mm_andnot_ps(
                     _mm_cmple_ps(v203, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v204, v203), v204)),
                       _mm_mul_ps(v204, *(__m128 *)_xmm)));
            v206 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v199, v199, 201), _xmm),
                     _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 201), v199));
            v207 = _mm_mul_ps(v205, (__m128)xmmword_141A711B0);
            v208 = _mm_shuffle_ps(v206, v206, 201);
            if ( v201.m128_f32[0] < _mm_shuffle_ps(
                                      (__m128)LODWORD(FLOAT_N0_99900001),
                                      (__m128)LODWORD(FLOAT_N0_99900001),
                                      0).m128_f32[0] )
            {
              v209 = _mm_mul_ps(v208, v208);
              v378 = _mm_sub_ps(v203, v201);
              v210 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v209, v209, 85), _mm_shuffle_ps(v209, v209, 0)),
                       _mm_shuffle_ps(v209, v209, 170));
              v211 = _mm_rsqrt_ps(v210);
              v413 = v210;
              v212 = _mm_rsqrt_ps(v378);
              v207 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v378, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v212, v378), v212)),
                             _mm_mul_ps(*(__m128 *)_xmm, v212))),
                         v378),
                       _mm_andnot_ps(
                         _mm_cmple_ps(v210, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v211, v210), v211)),
                           _mm_mul_ps(*(__m128 *)_xmm, v211))));
            }
            v213 = _mm_mul_ps(v208, v207);
            v360.m_vec.m_quad = _mm_shuffle_ps(v213, _mm_unpackhi_ps(v213, _mm_mul_ps(v205, v203)), 196);
          }
          else
          {
            hkQuaternionf::setFlippedRotation(&v360, &v363);
          }
        }
        else
        {
          v360.m_vec.m_quad = qi.m_vec.m_quad;
        }
        vertices = 0i64;
        v351 = 0;
        v352 = 0x80000000;
        hkArrayUtil::_reserve(&v359, &hkContainerHeapAllocator::s_alloc, (const void **)&vertices, 144, 16);
        for ( i = 0; i < 12; ++i )
        {
          v215 = 0;
          v216 = (__m128)COERCE_UNSIGNED_INT((float)i);
          v216.m128_f32[0] = v216.m128_f32[0] * 0.090909094;
          do
          {
            v217 = v351;
            v218 = (__m128)COERCE_UNSIGNED_INT((float)v215);
            v218.m128_f32[0] = v218.m128_f32[0] * 0.090909094;
            uv.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v216, (__m128)0i64), _mm_unpacklo_ps(v218, (__m128)0i64));
            if ( v351 == (v352 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vertices, 16);
              v217 = v351;
            }
            v351 = v217 + 1;
            v219 = &vertices[v217];
            hkGeometryProcessing::octahedronToNormal(&uv, v219);
            v220 = _mm_mul_ps(v360.m_vec.m_quad, v219->m_quad);
            v221 = _mm_shuffle_ps(v360.m_vec.m_quad, v360.m_vec.m_quad, 255);
            v222 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v219->m_quad, v219->m_quad, 201), v360.m_vec.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v360.m_vec.m_quad, v360.m_vec.m_quad, 201), v219->m_quad));
            v223 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v220, v220, 85), _mm_shuffle_ps(v220, v220, 0)),
                           _mm_shuffle_ps(v220, v220, 170)),
                         v360.m_vec.m_quad),
                       _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v221, v221), (__m128)xmmword_141A711B0), v219->m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v222, v222, 201), v221));
            v224 = _mm_mul_ps(_mm_add_ps(v223, v223), v195);
            v225 = _mm_mul_ps(v199, v224);
            *v219 = (hkVector4f)v224;
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v225, v225, 85), _mm_shuffle_ps(v225, v225, 0)),
                     _mm_shuffle_ps(v225, v225, 170))) )
            {
              m_quad = v193.m_quad;
            }
            else
            {
              m_quad = v192.m_quad;
            }
            ++v215;
            v219->m_quad = _mm_add_ps(m_quad, v224);
          }
          while ( v215 < 12 );
        }
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
          vertices,
          v351,
          material,
          geometry);
        v133 = v352;
        v351 = 0;
        if ( v352 >= 0 )
        {
          v134 = vertices;
          goto LABEL_122;
        }
        break;
      case 4:
        v32 = m_sharedVerticesIndex[v30 + 1];
        v33 = 2;
        if ( v31 >> 8 < 2 )
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
              v396.m_quad = (__m128)aabb.m_min;
              v43 = _mm_mul_ps(
                      _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                      (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters::`2::invBitScalesBuffer);
              v397 = v43;
              v44 = &decoder->m_sharedVertices[v32];
              if ( v33 - 1 > 0 )
              {
                v45 = &aabb;
                do
                {
                  ++v45;
                  v46 = *((unsigned __int16 *)v44 + (int)((v42 & 0xFFFFFFFC) - (v42 & 3) + 3));
                  v47 = _mm_cvtsi32_si128(v46 >> 10);
                  v48 = _mm_cvtsi32_si128((v46 >> 5) & 0x1F);
                  v49 = _mm_cvtsi32_si128(*((_WORD *)v44 + (int)((v42 & 0xFFFFFFFC) - (v42 & 3) + 3)) & 0x1F);
                  v50 = v42 + 1;
                  v51 = (v42 + 1) & 3;
                  v42 += 2;
                  v52 = *((unsigned __int16 *)v44 + (int)((v50 & 0xFFFFFFFC) - v51 + 3));
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
                  v56 = *((unsigned __int16 *)v44 + (int)(v55 + 3));
                  v53[-1] = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_unpacklo_epi32(
                                    _mm_unpacklo_epi32(
                                      _mm_cvtsi32_si128(*((_WORD *)v44 + (int)(v55 + 3)) & 0x1F),
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
              hkErrStream::hkErrStream(&v364, description, 512);
              v37 = (decoder->m_sharedVerticesIndex[(unsigned __int8)decoder->m_primitives[v8].m_indices[0]] >> 4) & 3;
              v38 = hkOstream::operator<<(&v364, "Compression method #");
              v39 = hkOstream::operator<<(v38, v37);
              hkOstream::operator<<(v39, " not implemented");
              if ( (unsigned int)hkError::messageError(
                                   0x902F09ED,
                                   description,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTre"
                                   "e/hkcdStaticMeshTree.inl",
                                   499) )
                __debugbreak();
              hkOstream::~hkOstream(&v364);
            }
          }
          else
          {
            v57.m_quad = (__m128)aabb.m_min;
            v58 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
            v59 = v32;
            v60 = v33 - 1;
            v61 = 0;
            v62 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
            v63 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
            v399.m_quad = (__m128)aabb.m_min;
            v64 = _mm_mul_ps(
                    _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                    (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
            v400 = v64;
            v65 = &decoder->m_sharedVertices[v59];
            if ( v60 > 0 )
            {
              v66 = &aabb;
              do
              {
                ++v66;
                v67 = (__m128i)*((unsigned int *)v65 + (int)((v61 & 0xFFFFFFFE) - (v61 & 1) + 1));
                v68 = v61 + 1;
                v61 += 2;
                v391 = v67;
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
                v386 = (__m128i)*((unsigned int *)v65 + (int)((v68 & 0xFFFFFFFE) - (v68 & 1) + 1));
                v66[-1].m_max.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_cvtepi32_ps(
                                             _mm_or_si128(
                                               _mm_or_si128(
                                                 _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v386, 0x16u), 0), v58),
                                                 _mm_and_si128(v386, v63)),
                                               _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v386, 0xBu), 0), v62))),
                                           v64),
                                         v57.m_quad);
              }
              while ( v61 < v60 );
            }
            if ( v61 < v34 )
            {
              v69 = &aabb.m_min.m_quad + v61;
              v70 = v34 - v61;
              do
              {
                ++v69;
                v71 = v61 & 1;
                v72 = v61++ & 0xFFFFFFFE;
                v388 = (__m128i)*((unsigned int *)v65 + (int)(v72 - v71 + 1));
                v69[-1] = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_cvtepi32_ps(
                                _mm_or_si128(
                                  _mm_or_si128(
                                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v388, 0x16u), 0), v58),
                                    _mm_and_si128(v388, v63)),
                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v388, 0xBu), 0), v62))),
                              v64),
                            v57.m_quad);
                --v70;
              }
              while ( v70 );
            }
          }
        }
        else
        {
          v73 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
          v74 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
          v75 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
          v76 = &decoder->m_sharedVertices[v32];
          v77 = 0;
          if ( v33 - 1 > 0 )
          {
            v78 = &aabb;
            v79 = (const __m128i *)v76;
            v80 = ((unsigned int)(v33 - 2) >> 1) + 1;
            v81 = v80;
            v77 = 2 * v80;
            do
            {
              v82 = _mm_loadl_epi64(v79);
              ++v78;
              ++v79;
              v390 = v82;
              v83 = _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v82, 0xAu), 85), v73),
                        _mm_and_si128(v82, v75)),
                      _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v82, 2), 5u), v74));
              v84 = _mm_loadl_epi64((const __m128i *)((char *)v79 - 8));
              v85 = _mm_add_ps(
                      _mm_mul_ps(_mm_cvtepi32_ps(v83), decoder->m_sharedParms.m_scale.m_quad),
                      decoder->m_sharedParms.m_origin.m_quad);
              v392 = v84;
              v78[-1].m_min.m_quad = v85;
              v78[-1].m_max.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_cvtepi32_ps(
                                           _mm_or_si128(
                                             _mm_or_si128(
                                               _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v84, 0xAu), 85), v73),
                                               _mm_and_si128(v84, v75)),
                                             _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v84, 2), 5u), v74))),
                                         decoder->m_sharedParms.m_scale.m_quad),
                                       decoder->m_sharedParms.m_origin.m_quad);
              --v81;
            }
            while ( v81 );
          }
          if ( v77 < v34 )
          {
            v86 = &aabb.m_min.m_quad + v77;
            v87 = v34 - v77;
            do
            {
              v88 = v77;
              ++v86;
              ++v77;
              v394 = _mm_loadl_epi64((const __m128i *)&v76[v88]);
              v86[-1] = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_cvtepi32_ps(
                              _mm_or_si128(
                                _mm_or_si128(
                                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v394, 0xAu), 85), v73),
                                  _mm_and_si128(v394, v75)),
                                _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v394, 2), 5u), v74))),
                            decoder->m_sharedParms.m_scale.m_quad),
                          decoder->m_sharedParms.m_origin.m_quad);
              --v87;
            }
            while ( v87 );
          }
        }
        v89.m_quad = (__m128)aabb.m_max;
        v90.m_quad = (__m128)aabb.m_min;
        v431 = (__int16)decoder->m_sharedVerticesIndex[(unsigned __int8)decoder->m_primitives[v22].m_indices[0] + 3] << 16;
        v91 = _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad);
        from.m_quad = stru_141A71280.m_quad;
        v92 = _mm_shuffle_ps((__m128)v431, (__m128)v431, 0);
        v93 = _mm_mul_ps(v91, v91);
        v94 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                _mm_shuffle_ps(v93, v93, 170));
        v95 = _mm_rsqrt_ps(v94);
        v420 = v94;
        v96 = _mm_mul_ps(
                v91,
                _mm_andnot_ps(
                  _mm_cmple_ps(v94, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v95, v94), v95)),
                    _mm_mul_ps(v95, *(__m128 *)_xmm))));
        v97 = _mm_mul_ps(stru_141A71280.m_quad, v96);
        v98 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                _mm_shuffle_ps(v97, v97, 170));
        v99 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99998999), (__m128)LODWORD(FLOAT_0_99998999), 0).m128_f32[0];
        if ( v98.m128_f32[0] <= v99 )
        {
          if ( v98.m128_f32[0] >= (float)(0.0 - v99) )
          {
            v100 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v98), (__m128)xmmword_141A711B0);
            v101 = _mm_rsqrt_ps(v100);
            v404 = v100;
            v102 = _mm_andnot_ps(
                     _mm_cmple_ps(v100, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v101, v100), v101)),
                       _mm_mul_ps(v101, *(__m128 *)_xmm)));
            v103 = _mm_mul_ps(v102, (__m128)xmmword_141A711B0);
            v104 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v96, v96, 201), stru_141A71280.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v96));
            v105 = _mm_shuffle_ps(v104, v104, 201);
            if ( v98.m128_f32[0] < _mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_N0_99900001),
                                     (__m128)LODWORD(FLOAT_N0_99900001),
                                     0).m128_f32[0] )
            {
              v106 = _mm_mul_ps(v105, v105);
              v381 = _mm_sub_ps(v100, v98);
              v107 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
                       _mm_shuffle_ps(v106, v106, 170));
              v108 = _mm_rsqrt_ps(v107);
              v423 = v107;
              v109 = _mm_rsqrt_ps(v381);
              v103 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v381, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v109, v381), v109)),
                             _mm_mul_ps(*(__m128 *)_xmm, v109))),
                         v381),
                       _mm_andnot_ps(
                         _mm_cmple_ps(v107, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v108, v107), v108)),
                           _mm_mul_ps(*(__m128 *)_xmm, v108))));
            }
            v110 = _mm_mul_ps(v105, v103);
            v358.m_vec.m_quad = _mm_shuffle_ps(v110, _mm_unpackhi_ps(v110, _mm_mul_ps(v102, v100)), 196);
          }
          else
          {
            hkQuaternionf::setFlippedRotation(&v358, &from);
          }
        }
        else
        {
          v358.m_vec.m_quad = qi.m_vec.m_quad;
        }
        array = 0i64;
        numVertices = 0;
        v111 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_52359879), (__m128)LODWORD(FLOAT_0_52359879), 0);
        v348 = 0x80000000;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, 24, 16);
        for ( j = 0; j < 12; ++j )
        {
          v113 = _mm_load_si128((const __m128i *)_xmm);
          v114 = 0i64;
          v114.m128_f32[0] = (float)j;
          v115 = _mm_add_epi32(v113, v113);
          v116 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v114, v114, 0), v111), *(__m128 *)offset_1);
          v117 = _mm_andnot_ps(*(__m128 *)_xmm, v116);
          v118 = _mm_andnot_si128(v113, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v117, *(__m128 *)_xmm)), v113));
          v119 = _mm_cvtepi32_ps(v118);
          v120 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v118, v115), (__m128i)0i64);
          v121 = _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v119, *(__m128 *)DP1_0), v117), _mm_mul_ps(v119, *(__m128 *)DP2)),
                   _mm_mul_ps(v119, *(__m128 *)DP3));
          v122 = _mm_mul_ps(v121, v121);
          v123 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)sinCoeff0, v122), *(__m128 *)sinCoeff1_0), v122),
                         *(__m128 *)sinCoeff2_0),
                       v122),
                     v121),
                   v121);
          v124 = _mm_shuffle_ps(v358.m_vec.m_quad, v358.m_vec.m_quad, 255);
          v125 = _mm_xor_ps(
                   _mm_or_ps(
                     _mm_andnot_ps(
                       v120,
                       _mm_add_ps(
                         _mm_sub_ps(
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_add_ps(_mm_mul_ps(*(__m128 *)cosCoeff0_0, v122), *(__m128 *)cosCoeff1),
                                   v122),
                                 *(__m128 *)cosCoeff2_0),
                               v122),
                             v122),
                           _mm_mul_ps(*(__m128 *)_xmm, v122)),
                         *(__m128 *)_xmm)),
                     _mm_and_ps(v123, v120)),
                   _mm_xor_ps(
                     (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v115, v115), v118), 0x1Du),
                     _mm_and_ps(v116, *(__m128 *)_xmm)));
          v126 = _mm_mul_ps(
                   _mm_movelh_ps(
                     _mm_unpacklo_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
                     _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad)),
                   v92);
          v127 = _mm_mul_ps(v358.m_vec.m_quad, v126);
          v128 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v126, v126, 201), v358.m_vec.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v358.m_vec.m_quad, v358.m_vec.m_quad, 201), v126));
          v129 = numVertices;
          v130 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v127, v127, 85), _mm_shuffle_ps(v127, v127, 0)),
                         _mm_shuffle_ps(v127, v127, 170)),
                       v358.m_vec.m_quad),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v124, v124), (__m128)xmmword_141A711B0), v126)),
                   _mm_mul_ps(_mm_shuffle_ps(v128, v128, 201), v124));
          v131 = _mm_add_ps(v130, v130);
          if ( numVertices == (v348 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v129 = numVertices;
          }
          numVertices = v129 + 1;
          array[v129].m_quad = _mm_add_ps(v90.m_quad, v131);
          v132 = numVertices;
          if ( numVertices == (v348 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v132 = numVertices;
          }
          numVertices = v132 + 1;
          array[v132].m_quad = _mm_add_ps(v89.m_quad, v131);
        }
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
          array,
          numVertices,
          material,
          geometry);
        v133 = v348;
        numVertices = 0;
        if ( v348 >= 0 )
        {
          v134 = array;
LABEL_122:
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v134, 16 * v133);
        }
        break;
      default:
        hkErrStream::hkErrStream(&v362, buf, 512);
        hkOstream::operator<<(&v362, "Not implemented");
        if ( (unsigned int)hkError::messageError(
                             0x93D510B9,
                             buf,
                             "Collide\\BvCompressedMesh\\hkpBvCompressedMeshShape.cpp",
                             165) )
          __debugbreak();
        hkOstream::~hkOstream(&v362);
        return;
    }
  }
  else
  {
    v293 = m_sharedVerticesIndex[v30 + 1];
    v294 = 4;
    if ( v31 >> 8 < 4 )
      v294 = v31 >> 8;
    v295 = v294;
    v296 = (v31 >> 4) & 3;
    if ( v296 )
    {
      v297 = v296 - 1;
      if ( v297 )
      {
        if ( v297 == 1 )
        {
          v301.m_quad = (__m128)aabb.m_min;
          v302 = 0;
          v414.m_quad = (__m128)aabb.m_min;
          v303 = _mm_mul_ps(
                   _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                   (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters::`2::invBitScalesBuffer);
          v415 = v303;
          v304 = &decoder->m_sharedVertices[v293];
          if ( v294 - 1 > 0 )
          {
            v305 = &v370;
            do
            {
              v305 += 2;
              v306 = *((unsigned __int16 *)v304 + (int)((v302 & 0xFFFFFFFC) - (v302 & 3) + 3));
              v307 = _mm_cvtsi32_si128(v306 >> 10);
              v308 = _mm_cvtsi32_si128((v306 >> 5) & 0x1F);
              v309 = _mm_cvtsi32_si128(*((_WORD *)v304 + (int)((v302 & 0xFFFFFFFC) - (v302 & 3) + 3)) & 0x1F);
              v310 = v302 + 1;
              v311 = (v302 + 1) & 3;
              v302 += 2;
              v305[-2].m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(
                                      _mm_unpacklo_epi32(
                                        _mm_unpacklo_epi32(v309, v307),
                                        _mm_unpacklo_epi32(v308, _mm_cvtsi32_si128(0)))),
                                    v303),
                                  v301.m_quad);
              v312 = *((unsigned __int16 *)v304 + (int)((v310 & 0xFFFFFFFC) - v311 + 3));
              v305[-1].m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(
                                      _mm_unpacklo_epi32(
                                        _mm_unpacklo_epi32(
                                          _mm_cvtsi32_si128(v312 & 0x1F),
                                          _mm_cvtsi32_si128(v312 >> 10)),
                                        _mm_unpacklo_epi32(_mm_cvtsi32_si128((v312 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                    v303),
                                  v301.m_quad);
            }
            while ( v302 < v294 - 1 );
          }
          if ( v302 < (__int64)v294 )
          {
            v313 = &v370 + v302;
            v314 = v294 - (__int64)v302;
            do
            {
              ++v313;
              v315 = (v302 & 0xFFFFFFFC) - (v302 & 3);
              ++v302;
              v316 = *((unsigned __int16 *)v304 + (int)(v315 + 3));
              v313[-1].m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(
                                      _mm_unpacklo_epi32(
                                        _mm_unpacklo_epi32(
                                          _mm_cvtsi32_si128(*((_WORD *)v304 + (int)(v315 + 3)) & 0x1F),
                                          _mm_cvtsi32_si128(v316 >> 10)),
                                        _mm_unpacklo_epi32(_mm_cvtsi32_si128((v316 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                    v303),
                                  v301.m_quad);
              --v314;
            }
            while ( v314 );
          }
        }
        else
        {
          hkErrStream::hkErrStream(&v369, v430, 512);
          v298 = (decoder->m_sharedVerticesIndex[(unsigned __int8)decoder->m_primitives[v8].m_indices[0]] >> 4) & 3;
          v299 = hkOstream::operator<<(&v369, "Compression method #");
          v300 = hkOstream::operator<<(v299, v298);
          hkOstream::operator<<(v300, " not implemented");
          if ( (unsigned int)hkError::messageError(
                               0x902F09ED,
                               v430,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTree/hk"
                               "cdStaticMeshTree.inl",
                               499) )
            __debugbreak();
          hkOstream::~hkOstream(&v369);
        }
      }
      else
      {
        v317.m_quad = (__m128)aabb.m_min;
        v318 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
        v319 = v293;
        v320 = v294 - 1;
        v321 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
        v322 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
        v417.m_quad = (__m128)aabb.m_min;
        v323 = _mm_mul_ps(
                 _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                 (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
        v418 = v323;
        v324 = &decoder->m_sharedVertices[v319];
        if ( v294 - 1 > 0 )
        {
          v325 = &v370;
          do
          {
            v325 += 2;
            v326 = (__m128i)*((unsigned int *)v324 + (int)((v5 & 0xFFFFFFFE) - (v5 & 1) + 1));
            v327 = v5 + 1;
            v5 += 2;
            v401 = v326;
            v325[-2].m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_cvtepi32_ps(
                                    _mm_or_si128(
                                      _mm_or_si128(
                                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v326, 0x16u), 0), v318),
                                        _mm_and_si128(v326, v322)),
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v326, 0xBu), 0), v321))),
                                  v323),
                                v317.m_quad);
            v419 = (__m128i)*((unsigned int *)v324 + (int)((v327 & 0xFFFFFFFE) - (v327 & 1) + 1));
            v325[-1].m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_cvtepi32_ps(
                                    _mm_or_si128(
                                      _mm_or_si128(
                                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v419, 0x16u), 0), v318),
                                        _mm_and_si128(v419, v322)),
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v419, 0xBu), 0), v321))),
                                  v323),
                                v317.m_quad);
          }
          while ( v5 < v320 );
        }
        if ( v5 < v295 )
        {
          v328 = &v370 + v5;
          v329 = v295 - v5;
          do
          {
            ++v328;
            v330 = v5 & 1;
            v331 = v5++ & 0xFFFFFFFE;
            v379 = (__m128i)*((unsigned int *)v324 + (int)(v331 - v330 + 1));
            v328[-1].m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_cvtepi32_ps(
                                    _mm_or_si128(
                                      _mm_or_si128(
                                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v379, 0x16u), 0), v318),
                                        _mm_and_si128(v379, v322)),
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v379, 0xBu), 0), v321))),
                                  v323),
                                v317.m_quad);
            --v329;
          }
          while ( v329 );
        }
      }
    }
    else
    {
      v332 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
      v333 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
      v334 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
      v335 = &decoder->m_sharedVertices[v293];
      v336 = v294 - 1;
      if ( v294 - 1 > 0 )
      {
        v337 = &v370;
        v338 = (const __m128i *)v335;
        v339 = ((unsigned int)(v336 - 1) >> 1) + 1;
        v340 = v339;
        v5 = 2 * v339;
        do
        {
          v341 = _mm_loadl_epi64(v338);
          v337 += 2;
          ++v338;
          v380 = v341;
          v337[-2].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v341, 0xAu), 85), v332),
                                      _mm_and_si128(v341, v334)),
                                    _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v341, 2), 5u), v333))),
                                decoder->m_sharedParms.m_scale.m_quad),
                              decoder->m_sharedParms.m_origin.m_quad);
          v382 = _mm_loadl_epi64((const __m128i *)((char *)v338 - 8));
          v337[-1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v382, 0xAu), 85), v332),
                                      _mm_and_si128(v382, v334)),
                                    _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v382, 2), 5u), v333))),
                                decoder->m_sharedParms.m_scale.m_quad),
                              decoder->m_sharedParms.m_origin.m_quad);
          --v340;
        }
        while ( v340 );
      }
      if ( v5 < v295 )
      {
        v342 = &v370 + v5;
        v343 = v295 - v5;
        do
        {
          v344 = v5;
          ++v342;
          ++v5;
          v384 = _mm_loadl_epi64((const __m128i *)&v335[v344]);
          v342[-1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v384, 0xAu), 85), v332),
                                      _mm_and_si128(v384, v334)),
                                    _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v384, 2), 5u), v333))),
                                decoder->m_sharedParms.m_scale.m_quad),
                              decoder->m_sharedParms.m_origin.m_quad);
          --v343;
        }
        while ( v343 );
      }
    }
    v345 = _mm_sub_ps(v373, v370.m_quad);
    v375 = _mm_add_ps(v372, v345);
    v374 = _mm_add_ps(_mm_sub_ps(v372, v370.m_quad), v371);
    v377 = _mm_add_ps(v374, v345);
    v376 = _mm_add_ps(v373, _mm_sub_ps(v371, v370.m_quad));
    hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
      &v370,
      8,
      material,
      geometry);
  }
}        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v382, 0xAu), 85), v332),
                                      _mm_and_si128(v382, v334)),
                                    _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v382, 2), 5u), v333))),
                                decoder->m_sharedParms.m_scale.m_quad),
                              decoder->m_sharedParms.m_origin.m_quad);
          --v340;
        }
        while ( v340 );
      }
      if ( v5 < v295 )
      {
        v342 = &v370 + v5;
        v343 = v295 - v5;
        do
        {
          v344 = v5;
          ++v342;
          ++v5;
          v384 = _mm_loadl_epi64((const __m128i *)&v335[v344]);
          v342[-1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v384, 0xAu), 85), v332),
                                      _mm_and_si128(v384, v334)),
                                    _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v384, 2), 5u), v333))),
                                decoder->m_sharedParms.m_scale.m_quad),
                              decoder->m_sharedParms.m_origin.m_quad);
          --v343;
        }
        while ( v343 );
      }
    }
    v345 = _mm_sub_ps(v373, v370.m_quad);
    v375 = _mm_add_ps(v372, v345);
    v374 = _mm_add_ps(_mm_sub_ps(v372, v370.m_quad), v371);
    v377 = _mm_add_ps(v374, v345);
    v376 = _mm_add_ps(v373, _mm_sub_ps(v371, v370.m_quad));
    hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfi

// File Line: 175
// RVA: 0xDFEF00
void __fastcall hkpBvCompressedMeshShape::convertToGeometry(
        hkpBvCompressedMeshShape *this,
        hkGeometry *geometryOut,
        hkArray<unsigned int,hkContainerHeapAllocator> *inclKeys,
        hkArray<unsigned int,hkContainerHeapAllocator> *exclKeys)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *m_tree; // rdi
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  int i; // ebx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter gc; // [rsp+40h] [rbp-28h] BYREF
  hkArray<unsigned int,hkContainerHeapAllocator> *v14; // [rsp+48h] [rbp-20h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v15; // [rsp+50h] [rbp-18h]
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  m_tree = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)this->m_tree;
  v14 = inclKeys;
  v15 = exclKeys;
  gc.vfptr = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverterVtbl *)&hkpBvCompressedMeshShapeGc::`vftable;
  hkGeometry::clear(geometryOut);
  v6 = m_tree->m_numPrimitiveKeys + geometryOut->m_triangles.m_size;
  v7 = geometryOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&geometryOut->m_triangles.m_data,
      v6,
      16);
  }
  v9 = geometryOut->m_vertices.m_size + 3 * m_tree->m_numPrimitiveKeys;
  v10 = geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v9 )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&geometryOut->m_vertices.m_data,
      v9,
      16);
  }
  for ( i = 0; i < m_tree->m_sections.m_size; ++i )
    hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::convertToGeometry(
      m_tree,
      i,
      geometryOut,
      &gc,
      1,
      0,
      TM_SET_FROM_TRIANGLE_DATA_TYPE);
  hkGeometryUtils::weldVertices(geometryOut, 0.0);
}

// File Line: 183
// RVA: 0xDFEE40
__int64 __fastcall hkpBvCompressedMeshShape::getPrimitiveUserData(hkpBvCompressedMeshShape *this, unsigned int key)
{
  __int64 result; // rax

  if ( !this->m_hasPerPrimitiveUserData.m_bool )
    return 0i64;
  LODWORD(result) = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getPrimitiveData(
                      (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)this->m_tree,
                      key) >> 8;
  if ( this->m_userDataPalette.m_size )
    return this->m_userDataPalette.m_data[(unsigned __int8)result];
  else
    return (unsigned __int8)result;
}

// File Line: 206
// RVA: 0xDFEE90
hkStringPtr *__fastcall hkpBvCompressedMeshShape::getPrimitiveUserString(
        hkpBvCompressedMeshShape *this,
        hkStringPtr *result,
        unsigned int key)
{
  unsigned int PrimitiveData; // eax

  if ( this->m_hasPerPrimitiveUserData.m_bool && this->m_userStringPalette.m_size )
  {
    PrimitiveData = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getPrimitiveData(
                      (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)this->m_tree,
                      key);
    hkStringPtr::hkStringPtr(result, &this->m_userStringPalette.m_data[BYTE1(PrimitiveData)]);
    return result;
  }
  else
  {
    hkStringPtr::hkStringPtr(result, 0i64);
    return result;
  }
}

// File Line: 229
// RVA: 0xDFF020
void __fastcall hkpBvCompressedMeshShape::getAabb(
        hkpBvCompressedMeshShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-18h] BYREF

  extraRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  hkAabbUtil::calcAabb(localToWorld, (hkAabb *)&this->m_tree[16], &extraRadius, out);
}

// File Line: 239
// RVA: 0xDFF060
hkBool *__fastcall hkpBvCompressedMeshShape::castRay(
        hkpBvCompressedMeshShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  hkVector4f v4; // xmm5
  hkVector4f v8; // xmm6
  __m128i v9; // xmm5
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __int128 v13; // xmm0
  __m128 v14; // xmm1
  float v15; // xmm9_4
  __m128 v16; // xmm4
  hkVector4f v17; // xmm5
  __int64 m_shapeKeyIndex; // rcx
  unsigned int v19; // eax
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm2
  __int128 v27; // [rsp+20h] [rbp-D8h] BYREF
  hkpBvCompressedMeshShapeTree tree; // [rsp+30h] [rbp-C8h] BYREF
  int v29; // [rsp+D0h] [rbp-28h]
  __int64 v30; // [rsp+D4h] [rbp-24h]
  hkpBvCompressedMeshShape *v31; // [rsp+E8h] [rbp-10h]
  hkpShapeRayCastInput *v32; // [rsp+F0h] [rbp-8h]
  unsigned int v33; // [rsp+F8h] [rbp+0h]
  __m128 v34; // [rsp+108h] [rbp+10h]
  __int128 v35; // [rsp+118h] [rbp+20h]

  v4.m_quad = (__m128)input->m_to;
  v30 = -1i64;
  v8.m_quad = (__m128)input->m_from;
  *(_QWORD *)&tree.m_sharedVerticesIndex.m_size = this->m_tree;
  v9 = (__m128i)_mm_sub_ps(v4.m_quad, v8.m_quad);
  v10 = _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0);
  memset(&tree.m_numPrimitiveKeys, 0, 56);
  memset(&tree.m_packedVertices, 0, 48);
  v29 = 0;
  v11 = *(__m128 *)&this->m_tree[32];
  tree.hkcdStaticTree::DynamicStorage5 = (hkcdStaticTree::DynamicStorage5)v8.m_quad;
  v12 = _mm_cmpeq_ps((__m128)0i64, (__m128)v9);
  tree.m_sections = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_sub_ps(
                                                                                         v11,
                                                                                         *(__m128 *)&this->m_tree[16]);
  v13 = *(_OWORD *)&this->m_tree[16];
  v31 = this;
  v32 = input;
  *(_OWORD *)&tree.m_numPrimitiveKeys = v13;
  tree.m_sections = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_mul_ps(
                                                                                         (__m128)tree.m_sections,
                                                                                         (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  v14 = _mm_rcp_ps((__m128)v9);
  v35 = 0i64;
  tree.m_domain.m_min.m_quad = _mm_shuffle_ps((__m128)v9, _mm_unpackhi_ps((__m128)v9, v10), 196);
  tree.m_domain.m_max.m_quad = _mm_or_ps(
                                 _mm_and_ps(
                                   _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v9, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                   v12),
                                 _mm_andnot_ps(
                                   v12,
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v9, v14)), v14)));
  tree.m_domain.m_max.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, tree.m_domain.m_min.m_quad)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::RayCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v27,
    (hkSimdFloat32 *)this->m_tree,
    &tree,
    (hkcdRay *)&tree.m_numPrimitiveKeys,
    (hkpBvCompressedMeshShape_Internals::RayCastQuery *)v27);
  v15 = *(float *)&v27;
  if ( *(float *)&v27 >= v10.m128_f32[0] )
  {
    result->m_bool = 0;
  }
  else
  {
    v16 = v34;
    v17.m_quad = (__m128)input->m_to;
    m_shapeKeyIndex = results->m_shapeKeyIndex;
    v19 = v33;
    result->m_bool = 1;
    v20 = _mm_sub_ps(v17.m_quad, input->m_from.m_quad);
    results->m_hitFraction = v15;
    v21 = _mm_mul_ps(v16, v16);
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170));
    v23 = _mm_rsqrt_ps(v22);
    v24 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v22, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                _mm_mul_ps(*(__m128 *)_xmm, v23))),
            v16);
    v25 = _mm_mul_ps(v24, v20);
    results->m_normal.m_quad = _mm_xor_ps(
                                 (__m128)_mm_slli_epi32(
                                           _mm_srli_epi32(
                                             (__m128i)_mm_cmplt_ps(
                                                        (__m128)0i64,
                                                        _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_shuffle_ps(v25, v25, 85),
                                                            _mm_shuffle_ps(v25, v25, 0)),
                                                          _mm_shuffle_ps(v25, v25, 170))),
                                             0x1Fu),
                                           0x1Fu),
                                 v24);
    results->m_shapeKeys[m_shapeKeyIndex] = v19;
    results->m_shapeKeys[++results->m_shapeKeyIndex] = -1;
    --results->m_shapeKeyIndex;
  }
  return result;
}

// File Line: 272
// RVA: 0xDFF2B0
void __fastcall hkpBvCompressedMeshShape::castRayWithCollector(
        hkpBvCompressedMeshShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *body,
        hkpRayHitCollector *collector)
{
  hkVector4f v4; // xmm5
  hkVector4f v5; // xmm6
  __m128i v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __int128 v9; // xmm0
  __m128 v10; // xmm1
  hkpBvCompressedMeshShapeTree tree; // [rsp+20h] [rbp-D8h] BYREF
  int v12; // [rsp+C0h] [rbp-38h]
  __int64 v13; // [rsp+C4h] [rbp-34h]
  hkpBvCompressedMeshShape *v14; // [rsp+D8h] [rbp-20h]
  hkpShapeRayCastInput *v15; // [rsp+E0h] [rbp-18h]
  hkpCdBody *v16; // [rsp+108h] [rbp+10h]
  hkpRayHitCollector *v17; // [rsp+110h] [rbp+18h]
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> v18; // [rsp+120h] [rbp+28h] BYREF

  v4.m_quad = (__m128)input->m_to;
  v13 = -1i64;
  *(_QWORD *)&tree.m_sharedVerticesIndex.m_size = this->m_tree;
  v5.m_quad = (__m128)input->m_from;
  memset(&tree.m_packedVertices, 0, 48);
  v12 = 0;
  v6 = (__m128i)_mm_sub_ps(v4.m_quad, v5.m_quad);
  memset(&tree.m_numPrimitiveKeys, 0, 56);
  v7 = *(__m128 *)&this->m_tree[32];
  tree.hkcdStaticTree::DynamicStorage5 = (hkcdStaticTree::DynamicStorage5)v5.m_quad;
  v8 = _mm_cmpeq_ps((__m128)0i64, (__m128)v6);
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
                                                                                         (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
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
  tree.m_domain.m_max.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, tree.m_domain.m_min.m_quad)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::RayCastQuery>(
    &v18,
    (hkSimdFloat32 *)this->m_tree,
    &tree,
    (hkcdRay *)&tree.m_numPrimitiveKeys,
    (hkpBvCompressedMeshShape_Internals::RayCastQuery *)v5.m_quad.m128_u64[0]);
}

// File Line: 287
// RVA: 0xDFF790
void __fastcall hkpBvCompressedMeshShape::castAabbImpl(
        hkpBvCompressedMeshShape *this,
        hkpBvCompressedMeshShapeTree *from,
        hkAabb *to,
        hkpAabbCastCollector *collector)
{
  hkpBvCompressedMeshShape_Internals::AabbCastQuery *query; // [rsp+28h] [rbp-C0h]
  hkVector4f v5; // [rsp+30h] [rbp-B8h] BYREF
  __m128 v6; // [rsp+40h] [rbp-A8h]
  __int128 v7; // [rsp+50h] [rbp-98h]
  __int128 v8; // [rsp+60h] [rbp-88h]
  char *m_tree; // [rsp+70h] [rbp-78h]
  __int64 v10; // [rsp+78h] [rbp-70h]
  __int128 v11; // [rsp+80h] [rbp-68h]
  __int128 v12; // [rsp+90h] [rbp-58h]
  __int64 v13; // [rsp+A0h] [rbp-48h]
  int v14; // [rsp+A8h] [rbp-40h]
  __int64 v15; // [rsp+ACh] [rbp-3Ch]
  hkpAabbCastCollector *v16; // [rsp+C0h] [rbp-28h]
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> v17; // [rsp+D0h] [rbp-18h] BYREF

  v5.m_quad = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  v10 = 0i64;
  v13 = 0i64;
  v14 = 0;
  m_tree = this->m_tree;
  v15 = -1i64;
  v6 = _mm_sub_ps(*(__m128 *)&this->m_tree[32], *(__m128 *)&this->m_tree[16]);
  v5.m_quad = *(__m128 *)&this->m_tree[16];
  v6 = _mm_mul_ps(
         v6,
         (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  v16 = collector;
  LODWORD(query) = (_DWORD)FLOAT_1_0;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::AabbCastQuery>(
    &v17,
    (hkSimdFloat32 *)this->m_tree,
    from,
    to,
    &v5,
    query,
    v5.m_quad.m128_f32[0]);
}

// File Line: 298
// RVA: 0xDFF010
__int64 __fastcall hkpBvCompressedMeshShape::calcSizeForSpu(
        hkpBvCompressedMeshShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  return 272i64;
}

// File Line: 311
// RVA: 0xDFF3F0
void __fastcall hkpBvCompressedMeshShape::queryAabb(
        hkpBvCompressedMeshShape *this,
        hkAabb *aabb,
        hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  char *m_tree; // rbx
  __m128 v4; // xmm1
  __int128 v5; // xmm0
  hkVector4f v6; // xmm0
  hkVector4f v7; // xmm1
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpBvCompressedMeshShape_Internals::AabbOverlaps> *v9; // r9
  __int64 m_cur; // rcx
  void *v11; // rdx
  int v12; // eax
  char *v13; // rdi
  signed int v14; // ebx
  hkLifoAllocator *v15; // rax
  int v16; // r8d
  char tree[164]; // [rsp+20h] [rbp-E0h] BYREF
  hkArray<unsigned int,hkContainerHeapAllocator> *v18; // [rsp+D0h] [rbp-30h]
  hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot> stackInstance; // [rsp+E0h] [rbp-20h] BYREF
  __m128 m_quad; // [rsp+100h] [rbp+0h]

  m_tree = this->m_tree;
  *(_QWORD *)&tree[156] = -1i64;
  memset(&tree[32], 0, 64);
  *(_QWORD *)&tree[96] = this->m_tree;
  memset(&tree[104], 0, 52);
  *(_QWORD *)tree = 0i64;
  v4 = *(__m128 *)&this->m_tree[32];
  *(_DWORD *)&tree[8] = 0;
  *(_DWORD *)&tree[12] = 0x80000000;
  *(_DWORD *)&tree[24] = 64;
  *(__m128 *)&tree[48] = _mm_sub_ps(v4, *(__m128 *)&this->m_tree[16]);
  v5 = *(_OWORD *)&this->m_tree[16];
  v18 = hits;
  stackInstance.m_stack.m_data = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot *)&tree[32];
  *(_OWORD *)&tree[32] = v5;
  v6.m_quad = (__m128)aabb->m_min;
  *(__m128 *)&tree[48] = _mm_mul_ps(
                           *(__m128 *)&tree[48],
                           (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  v7.m_quad = (__m128)aabb->m_max;
  *(hkVector4f *)&stackInstance.m_stack.m_localMemory = (hkVector4f)v6.m_quad;
  m_quad = v7.m_quad;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v11 = (void *)(m_cur + 3072);
  if ( Value->m_slabSize < 3072 || v11 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, 3072);
  else
    Value->m_cur = v11;
  *(_QWORD *)tree = m_cur;
  *(_QWORD *)&tree[16] = m_cur;
  *(_DWORD *)&tree[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpBvCompressedMeshShapeTree,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpBvCompressedMeshShape_Internals::AabbOverlaps>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)m_tree,
    (hkpBvCompressedMeshShapeTree *)tree,
    &stackInstance,
    v9);
  v12 = *(_DWORD *)&tree[8];
  v13 = *(char **)&tree[16];
  if ( *(_QWORD *)&tree[16] == *(_QWORD *)tree )
    v12 = 0;
  *(_DWORD *)&tree[8] = v12;
  v14 = (48 * *(_DWORD *)&tree[24] + 127) & 0xFFFFFF80;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v15->m_slabSize || &v13[v16] != v15->m_cur || v15->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v15, v13, v16);
  else
    v15->m_cur = v13;
  *(_DWORD *)&tree[8] = 0;
  if ( *(int *)&tree[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)tree,
      48 * (*(_DWORD *)&tree[12] & 0x3FFFFFFF));
}

// File Line: 320
// RVA: 0xDFF5C0
__int64 __fastcall hkpBvCompressedMeshShape::queryAabbImpl(
        hkpBvCompressedMeshShape *this,
        hkAabb *aabb,
        unsigned int *hits,
        int maxNumKeys)
{
  char *m_tree; // rbx
  __m128 v5; // xmm1
  __int128 v6; // xmm0
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpBvCompressedMeshShape_Internals::AabbOverlapsWithMaxHits> *v10; // r9
  __int64 m_cur; // rcx
  void *v12; // rdx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // r8d
  char tree[164]; // [rsp+20h] [rbp-E0h] BYREF
  unsigned int *v20; // [rsp+D0h] [rbp-30h]
  int v21; // [rsp+D8h] [rbp-28h]
  unsigned int v22; // [rsp+DCh] [rbp-24h]
  hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot> stackInstance; // [rsp+E0h] [rbp-20h] BYREF
  __m128 m_quad; // [rsp+100h] [rbp+0h]

  m_tree = this->m_tree;
  *(_QWORD *)&tree[156] = -1i64;
  memset(&tree[32], 0, 64);
  *(_QWORD *)&tree[96] = this->m_tree;
  memset(&tree[104], 0, 52);
  *(_QWORD *)tree = 0i64;
  v5 = *(__m128 *)&this->m_tree[32];
  *(_DWORD *)&tree[8] = 0;
  *(_DWORD *)&tree[12] = 0x80000000;
  *(_DWORD *)&tree[24] = 64;
  *(__m128 *)&tree[48] = _mm_sub_ps(v5, *(__m128 *)&this->m_tree[16]);
  v6 = *(_OWORD *)&this->m_tree[16];
  v20 = hits;
  v21 = maxNumKeys;
  v22 = 0;
  *(_OWORD *)&tree[32] = v6;
  v7.m_quad = (__m128)aabb->m_min;
  *(__m128 *)&tree[48] = _mm_mul_ps(
                           *(__m128 *)&tree[48],
                           (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  stackInstance.m_stack.m_data = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot *)&tree[32];
  v8.m_quad = (__m128)aabb->m_max;
  *(hkVector4f *)&stackInstance.m_stack.m_localMemory = (hkVector4f)v7.m_quad;
  m_quad = v8.m_quad;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v12 = (void *)(m_cur + 3072);
  if ( Value->m_slabSize < 3072 || v12 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, 3072);
  else
    Value->m_cur = v12;
  *(_QWORD *)tree = m_cur;
  *(_QWORD *)&tree[16] = m_cur;
  *(_DWORD *)&tree[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpBvCompressedMeshShapeTree,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpBvCompressedMeshShape_Internals::AabbOverlapsWithMaxHits>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)m_tree,
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
  if ( *(int *)&tree[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)tree,
      48 * (*(_DWORD *)&tree[12] & 0x3FFFFFFF));
  return v22;
}

// File Line: 335
// RVA: 0xDFF840
__int64 __fastcall hkpBvCompressedMeshShape::getNumChildShapes(hkpBvCompressedMeshShape *this)
{
  return *(unsigned int *)&this->m_tree[8];
}

// File Line: 340
// RVA: 0xDFF850
__int64 __fastcall hkpBvCompressedMeshShape::getFirstKey(hkpBvCompressedMeshShape *this)
{
  __int64 result; // rax
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *p_m_userDataPalette; // rbx
  unsigned __int64 v3; // r9
  __int64 v4; // rcx
  __int64 v5; // rcx
  int v6; // edx
  int v7; // r8d

  if ( !*(_DWORD *)&this->m_tree[32] )
    return 0xFFFFFFFFi64;
  result = 0i64;
  p_m_userDataPalette = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)&this->m_userDataPalette;
  do
  {
    v3 = 0i64;
    v4 = (unsigned int)result >> 8;
    if ( (_DWORD)v4 != -1 )
      v3 = (unsigned __int64)&p_m_userDataPalette->m_primitives.m_data[(unsigned __int64)p_m_userDataPalette->m_sections.m_data[v4].m_primitives.m_data >> 8];
    v5 = (unsigned __int8)result >> 1;
    v6 = *(unsigned __int8 *)(v3 + 4 * v5 + 3);
    v7 = *(unsigned __int8 *)(v3 + 4 * v5 + 2);
    if ( v6 == v7 )
      break;
    if ( *(_BYTE *)(v3 + 4 * v5) != 0xDE )
      break;
    if ( *(unsigned __int8 *)(v3 + 4 * v5 + 1) != 173 )
      break;
    if ( v7 != 222 )
      break;
    if ( v6 != 173 )
      break;
    result = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getNextKey(
               p_m_userDataPalette,
               result);
  }
  while ( (_DWORD)result != -1 );
  return result;
}

// File Line: 357
// RVA: 0xDFF910
__int64 __fastcall hkpBvCompressedMeshShape::getNextKey(hkpBvCompressedMeshShape *this, unsigned int oldKey)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *p_m_userDataPalette; // rbx
  __int64 result; // rax
  __int64 v4; // rax
  unsigned __int64 v5; // r9
  __int64 v6; // rax
  int v7; // ecx
  int v8; // r8d

  p_m_userDataPalette = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *)&this->m_userDataPalette;
  while ( 1 )
  {
    result = hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getNextKey(
               p_m_userDataPalette,
               oldKey);
    oldKey = result;
    if ( (_DWORD)result == -1 )
      break;
    v4 = (unsigned int)result >> 8;
    v5 = 0i64;
    if ( (_DWORD)v4 != -1 )
      v5 = (unsigned __int64)&p_m_userDataPalette->m_primitives.m_data[(unsigned __int64)p_m_userDataPalette->m_sections.m_data[v4].m_primitives.m_data >> 8];
    v6 = (unsigned __int8)oldKey >> 1;
    v7 = *(unsigned __int8 *)(v5 + 4 * v6 + 3);
    v8 = *(unsigned __int8 *)(v5 + 4 * v6 + 2);
    if ( v7 == v8
      || *(_BYTE *)(v5 + 4 * v6) != 0xDE
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
hkpConvexVerticesShape *__fastcall hkpBvCompressedMeshShape::getChildShape(
        hkpBvCompressedMeshShape *this,
        unsigned int key,
        hkpConvexVerticesShape *buffer)
{
  __m128 v3; // xmm8
  int v5; // r8d
  __int64 v6; // r15
  unsigned __int64 v7; // r11
  hkArray<hkStringPtr,hkContainerHeapAllocator> m_userStringPalette; // xmm9
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
  unsigned __int64 v29; // rdx
  int v30; // edi
  unsigned int v31; // ebx
  __int64 v32; // r13
  int v33; // edx
  int v34; // eax
  int v35; // ecx
  hkpConvexVerticesShape *v36; // r14
  hkVector4f v37; // xmm7
  __m128 v38; // xmm6
  int v39; // ecx
  int LeafByValue; // edx
  unsigned int Value; // eax
  __int64 v42; // r11
  __int64 v43; // rcx
  unsigned int v44; // edx
  unsigned __int16 v45; // r9
  hkVector4f *v46; // r15
  int v47; // r8d
  __int64 v48; // rdi
  int v49; // edx
  int v50; // edx
  int v51; // edi
  hkOstream *v52; // rax
  hkOstream *v53; // rax
  __int64 v54; // r10
  __m128 v55; // xmm6
  int v56; // esi
  hkVector4f *v57; // r9
  unsigned int v58; // eax
  __m128i v59; // xmm0
  __m128i v60; // xmm2
  __m128i v61; // xmm3
  int v62; // ecx
  int v63; // eax
  __m128i v64; // xmm1
  unsigned int v65; // eax
  hkVector4f *v66; // r8
  __int64 v67; // rdi
  unsigned int v68; // ecx
  unsigned int v69; // eax
  __m128i v70; // xmm3
  __m128i v71; // xmm4
  __m128i v72; // xmm5
  __int64 v73; // r9
  __m128 v74; // xmm6
  int v75; // edx
  hkVector4f *v76; // rsi
  __m128i v77; // xmm1
  int v78; // eax
  __m128i v79; // xmm1
  hkVector4f *v80; // rsi
  __int64 v81; // rdi
  int v82; // eax
  unsigned int v83; // ecx
  __m128i v84; // xmm1
  __m128i v85; // xmm3
  __m128i v86; // xmm4
  __m128i v87; // xmm5
  __int64 v88; // r10
  int v89; // edx
  hkVector4f *v90; // rcx
  const __m128i *v91; // rsi
  unsigned int v92; // eax
  __int64 v93; // r9
  __m128i v94; // xmm2
  __m128i v95; // xmm2
  hkVector4f *v96; // rcx
  __int64 v97; // rdi
  __int64 v98; // rax
  __m128i v99; // xmm2
  unsigned __int64 v100; // rdi
  __int64 v101; // rcx
  unsigned int v102; // eax
  hkpConvexVerticesShape *v103; // rax
  __int64 v104; // r11
  hkpConvexVerticesShape *v105; // rax
  signed int v106; // eax
  __int64 v107; // r9
  int v108; // r10d
  __m128 v109; // xmm8
  int v110; // esi
  __m128 v111; // xmm7
  __m128 *p_m_quad; // rdx
  __m128 v113; // xmm8
  __m128 v114; // xmm7
  __m128 v115; // xmm6
  __m128 v116; // xmm4
  __m128 v117; // xmm5
  __m128 v118; // xmm3
  __int64 v119; // rax
  __int64 v120; // rcx
  __m128 v121; // xmm2
  __m128 v122; // xmm1
  __int64 v123; // rcx
  char v125; // cl
  float v126; // xmm0_4
  __int64 v127; // rax
  __m128i si128; // xmm5
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
  __int64 v143; // rcx
  hkVector4f v144; // xmm0
  unsigned int v145; // ebx
  __int64 v146; // [rsp+30h] [rbp-90h]
  __m128 v147; // [rsp+40h] [rbp-80h]
  __m128 v148; // [rsp+50h] [rbp-70h]
  __m128 v149; // [rsp+60h] [rbp-60h]
  hkAabb aabb; // [rsp+70h] [rbp-50h] BYREF
  __int128 v151; // [rsp+C0h] [rbp+0h]
  __int128 v152; // [rsp+D0h] [rbp+10h]
  char buf[592]; // [rsp+100h] [rbp+40h] BYREF
  __int64 v154; // [rsp+3D0h] [rbp+310h]
  float paddingRadius; // [rsp+3D8h] [rbp+318h]
  float cylinderRadius; // [rsp+3E0h] [rbp+320h]
  __int64 v157; // [rsp+3E8h] [rbp+328h]

  v3 = *((__m128 *)&this->m_userStringPalette + 1);
  v5 = (unsigned __int8)key >> 1;
  v149.m128_u64[0] = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  paddingRadius = 0.0;
  m_userStringPalette = this->m_userStringPalette;
  v9 = key >> 8;
  LODWORD(cylinderRadius) = key & 1;
  v10 = 0i64;
  v11 = 0i64;
  v151 = 0i64;
  v12 = _mm_mul_ps(
          _mm_sub_ps(v3, (__m128)m_userStringPalette),
          (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  v152 = 0i64;
  if ( (_DWORD)v9 == -1 )
  {
    v19 = v151;
    v157 = *((_QWORD *)&v152 + 1);
    v147.m128_u64[0] = *((_QWORD *)&v151 + 1);
    v146 = v152;
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
    if ( *(_BYTE *)(v19 + 4i64 * v5) == 0xDE && v35 == 173 && v34 == 222 && v33 == 173 )
      return 0i64;
    goto LABEL_83;
  }
  if ( v34 != v35 )
  {
LABEL_83:
    v125 = *(_BYTE *)(v154 + 12);
    v126 = *(float *)(v154 + 8);
    if ( buffer )
    {
      *(_DWORD *)&buffer->m_memSizeAndFlags = 0x1FFFF;
      *(_DWORD *)&buffer->m_type.m_storage = 1026;
      buffer->m_radius = v126;
      *(_OWORD *)&buffer->m_numVertices = 0i64;
      buffer->vfptr = (hkBaseObjectVtbl *)&hkpTriangleShape::`vftable;
      buffer->m_userData = 0i64;
      *((_BYTE *)&buffer->hkpConvexShape + 42) = v125;
      *((_BYTE *)&buffer->hkpConvexShape + 43) = 0;
      *((_WORD *)&buffer->hkpConvexShape + 20) = HIWORD(v31);
      v36 = buffer;
    }
    v127 = *(unsigned __int8 *)(v19 + 4i64 * v5);
    si128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
    v129 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
    v130 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
    v131 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
    v132 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
    v133 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
    if ( (int)v127 < SLODWORD(paddingRadius) )
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
                                si128),
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
                      (__m128)m_userStringPalette);
    }
    v137 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 1);
    aabb.m_min = (hkVector4f)v136.m_quad;
    if ( (int)v137 < SLODWORD(paddingRadius) )
    {
      v147 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(
                         _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v137), 0x16u), 0),
                         si128),
                       _mm_and_si128((__m128i)*(unsigned int *)(v135 + 4 * v137), v130)),
                     _mm_and_si128(
                       _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v137), 0xBu), 0),
                       v129))),
                 v11),
               v10);
    }
    else
    {
      v138 = _mm_loadl_epi64((const __m128i *)(v146 + 8i64 * *(unsigned __int16 *)(v157 + 2i64 * (int)v137)));
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
               (__m128)m_userStringPalette);
    }
    v139 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 2);
    if ( (int)v139 < SLODWORD(paddingRadius) )
    {
      v148 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(
                         _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v139), 0x16u), 0),
                         si128),
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
               (__m128)m_userStringPalette);
    }
    v141 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 3);
    if ( (int)v141 < SLODWORD(paddingRadius) )
    {
      v149 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(
                   _mm_or_si128(
                     _mm_or_si128(
                       _mm_and_si128(
                         _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v135 + 4 * v141), 0x16u), 0),
                         si128),
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
               (__m128)m_userStringPalette);
    }
    v143 = 2i64 * SLODWORD(cylinderRadius);
    v144.m_quad = (__m128)*((_OWORD *)&v147 + SLODWORD(cylinderRadius));
    v36->m_aabbHalfExtents = (hkVector4f)v136.m_quad;
    v36->m_aabbCenter = (hkVector4f)v144.m_quad;
    v36->m_rotatedVertices = *(hkArray<hkFourTransposedPointsf,hkContainerHeapAllocator> *)((char *)&v148 + 8 * v143);
    goto LABEL_59;
  }
  if ( (*(_BYTE *)(v157 + 2i64 * *(unsigned __int8 *)(v19 + 4i64 * v5)) & 0x30) != 0 )
  {
    v39 = *(unsigned __int8 *)(v19 + 4i64 * v5 + 2);
    if ( *(unsigned __int8 *)(v19 + 4i64 * v5 + 3) == v39 && v39 == *(unsigned __int8 *)(v19 + 4i64 * v5 + 1) )
      LeafByValue = *(unsigned __int8 *)(v19 + 4i64 * v5 + 1);
    else
      LeafByValue = hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::findLeafByValue(
                      (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)v6,
                      v5);
    hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(
      (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)v6,
      LeafByValue,
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
  Value = (unsigned int)TlsGetValue(hkThreadNumber.m_slotID);
  v42 = v157;
  v43 = *(unsigned __int8 *)(v148.m128_u64[0] + 4 * v32);
  v44 = *(unsigned __int16 *)(v157 + 2 * v43);
  v45 = *(_WORD *)(v157 + 2 * v43 + 2);
  v46 = hkpBvCompressedMeshShape::g_vertexBufferPool[Value];
  v47 = 255;
  if ( v44 >> 8 < 0xFF )
    v47 = HIBYTE(*(unsigned __int16 *)(v157 + 2 * v43));
  LODWORD(paddingRadius) = v47;
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
                (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters::`2::invBitScalesBuffer);
        v56 = 0;
        if ( v47 - 1 > 0 )
        {
          v57 = hkpBvCompressedMeshShape::g_vertexBufferPool[Value];
          do
          {
            v57 += 2;
            v58 = *(unsigned __int16 *)(v54 + 2i64 * (int)((v56 & 0xFFFFFFFC) - (v56 & 3) + 3));
            v59 = _mm_cvtsi32_si128(v58 >> 10);
            v60 = _mm_cvtsi32_si128((v58 >> 5) & 0x1F);
            v61 = _mm_cvtsi32_si128(*(_WORD *)(v54 + 2i64 * (int)((v56 & 0xFFFFFFFC) - (v56 & 3) + 3)) & 0x1F);
            v62 = v56 + 1;
            v63 = (v56 + 1) & 3;
            v56 += 2;
            v64 = _mm_cvtsi32_si128(v149.m128_u32[0]);
            v57[-2].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v61, v59), _mm_unpacklo_epi32(v60, v64))),
                                 v55),
                               v37.m_quad);
            v65 = *(unsigned __int16 *)(v54 + 2i64 * (int)((v62 & 0xFFFFFFFC) - v63 + 3));
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
        if ( v56 < (__int64)v47 )
        {
          v66 = &v46[v56];
          v67 = v48 - v56;
          do
          {
            ++v66;
            v68 = (v56 & 0xFFFFFFFC) - (v56 & 3);
            ++v56;
            v69 = *(unsigned __int16 *)(v54 + 2i64 * (int)(v68 + 3));
            v66[-1].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(
                                       _mm_cvtsi32_si128(*(_WORD *)(v54 + 2i64 * (int)(v68 + 3)) & 0x1F),
                                       _mm_cvtsi32_si128(v69 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v69 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
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
        hkErrStream::hkErrStream((hkErrStream *)&aabb, buf, 512);
        v51 = (*(unsigned __int16 *)(v157 + 2i64 * *(unsigned __int8 *)(v148.m128_u64[0] + 4 * v32)) >> 4) & 3;
        v52 = hkOstream::operator<<((hkOstream *)&aabb, "Compression method #");
        v53 = hkOstream::operator<<(v52, v51);
        hkOstream::operator<<(v53, " not implemented");
        if ( (unsigned int)hkError::messageError(
                             0x902F09ED,
                             buf,
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
      v70 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
      v71 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
      v72 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
      v73 = v146 + 8i64 * v45;
      v74 = _mm_mul_ps(
              _mm_sub_ps(v38, v37.m_quad),
              (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
      v75 = 0;
      if ( v47 - 1 > 0 )
      {
        v76 = hkpBvCompressedMeshShape::g_vertexBufferPool[Value];
        do
        {
          v76 += 2;
          v77 = (__m128i)*(unsigned int *)(v73 + 4i64 * (int)((v75 & 0xFFFFFFFE) - (v75 & 1) + 1));
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
          v79 = (__m128i)*(unsigned int *)(v73 + 4i64 * (int)((v78 & 0xFFFFFFFE) - (v78 & 1) + 1));
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
      if ( v75 < (__int64)v47 )
      {
        v80 = &v46[v75];
        v81 = v47 - (__int64)v75;
        do
        {
          ++v80;
          v82 = v75 & 1;
          v83 = v75++ & 0xFFFFFFFE;
          v84 = (__m128i)*(unsigned int *)(v73 + 4i64 * (int)(v83 - v82 + 1));
          v80[-1].m_quad = _mm_add_ps(
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
    v85 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
    v86 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
    v87 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
    v88 = v146 + 8i64 * v45;
    v89 = 0;
    if ( v47 - 1 > 0 )
    {
      v90 = hkpBvCompressedMeshShape::g_vertexBufferPool[Value];
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
                           (__m128)m_userStringPalette);
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
                           (__m128)m_userStringPalette);
        --v93;
      }
      while ( v93 );
    }
    if ( v89 < (__int64)v47 )
    {
      v96 = &v46[v89];
      v97 = v47 - (__int64)v89;
      do
      {
        v98 = v89;
        ++v96;
        ++v89;
        v99 = _mm_loadl_epi64((const __m128i *)(v88 + 8 * v98));
        v96[-1].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v99, 0xAu), 85), v85),
                                   _mm_and_si128(v87, v99)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v99, 2), 5u), v86))),
                             v12),
                           (__m128)m_userStringPalette);
        --v97;
      }
      while ( v97 );
    }
  }
  v100 = v148.m128_u64[0];
  v101 = *(unsigned __int8 *)(v148.m128_u64[0] + 4 * v32);
  v102 = *(_WORD *)(v42 + 2 * v101) & 0xF;
  if ( v102 <= 3 )
  {
    if ( !v102 )
    {
      hkpBvCompressedMeshShape_Internals::expandBoxVertices(v46);
      v47 = 8;
      LODWORD(paddingRadius) = 8;
    }
    if ( buffer )
    {
      hkpConvexVerticesShape::hkpConvexVerticesShape(buffer, *(float *)(v154 + 8));
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
    if ( v47 < (__int64)v106 )
    {
      qmemcpy(&v46[v47], &v46[v47 - 1], 8 * ((2 * (v106 - (__int64)v47)) & 0x1FFFFFFFFFFFFFFEi64));
      v100 = v148.m128_u64[0];
    }
    v109 = (__m128)xmmword_141A712A0;
    v110 = 0;
    v111 = _mm_xor_ps(
             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
             (__m128)xmmword_141A712A0);
    if ( v106 > 0i64 )
    {
      p_m_quad = &v46[2].m_quad;
      do
      {
        v113 = _mm_min_ps(v109, p_m_quad[-2]);
        v114 = _mm_max_ps(v111, p_m_quad[-2]);
        v115 = p_m_quad[-2];
        v116 = p_m_quad[-1];
        v117 = *p_m_quad;
        v118 = p_m_quad[1];
        v119 = v110;
        v104 += 4i64;
        v110 += 4;
        p_m_quad += 4;
        v120 = 3 * (v119 >> 2);
        v121 = _mm_shuffle_ps(v115, v116, 68);
        v122 = _mm_shuffle_ps(v117, v118, 68);
        v109 = _mm_min_ps(_mm_min_ps(_mm_min_ps(v113, p_m_quad[-5]), p_m_quad[-4]), p_m_quad[-3]);
        v111 = _mm_max_ps(_mm_max_ps(_mm_max_ps(v114, p_m_quad[-5]), p_m_quad[-4]), p_m_quad[-3]);
        v46[v120].m_quad = _mm_shuffle_ps(v121, v122, 136);
        v46[v120 + 1].m_quad = _mm_shuffle_ps(v121, v122, 221);
        v46[v120 + 2].m_quad = _mm_shuffle_ps(_mm_shuffle_ps(v115, v116, 238), _mm_shuffle_ps(v117, v118, 238), 136);
      }
      while ( v104 < v107 );
    }
    v36->m_rotatedVertices.m_data = (hkFourTransposedPointsf *)v46;
    v36->m_rotatedVertices.m_size = v108;
    v36->m_rotatedVertices.m_capacityAndFlags = v108;
    v36->m_numVertices = v47;
    v36->m_useSpuBuffer.m_bool = 1;
    v36->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v111, v109), (__m128)xmmword_141A711B0);
    v36->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v111, v109), (__m128)xmmword_141A711B0);
    goto LABEL_76;
  }
  if ( v102 != 4 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&aabb, buf, 512);
    hkOstream::operator<<((hkOstream *)&aabb, "Not implemented");
    if ( (unsigned int)hkError::messageError(
                         0x7798B41Bu,
                         buf,
                         "Collide\\BvCompressedMesh\\hkpBvCompressedMeshShape.cpp",
                         506) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&aabb);
    *v46 = 0i64;
LABEL_76:
    v123 = *(unsigned __int8 *)(v100 + 4 * v32);
    if ( (*(_BYTE *)(v157 + 2 * v123) & 0xC0) != 0 )
    {
      LODWORD(paddingRadius) = *(__int16 *)(v157 + 2 * v123 + 4) << 16;
      v36->m_radius = paddingRadius;
    }
    goto LABEL_59;
  }
  LODWORD(paddingRadius) = *(__int16 *)(v42 + 2 * v101 + 4) << 16;
  LODWORD(cylinderRadius) = *(__int16 *)(v42 + 2 * v101 + 6) << 16;
  if ( buffer )
  {
    hkpCylinderShape::hkpCylinderShape((hkpCylinderShape *)buffer, v46, v46 + 1, cylinderRadius, paddingRadius);
    v36 = v103;
  }
  else
  {
    v36 = 0i64;
  }
LABEL_59:
  if ( *(_BYTE *)(v154 + 14) )
  {
    v145 = v31 >> 8;
    if ( *(_DWORD *)(v154 + 40) )
      v36->m_userData = *(unsigned int *)(*(_QWORD *)(v154 + 32) + 4i64 * (unsigned __int8)v145);
    else
      v36->m_userData = (unsigned __int8)v145;
  }
  else
  {
    v36->m_userData = 0i64;
  }
  return v36;
}

// File Line: 557
// RVA: 0xE00860
__int64 __fastcall hkpBvCompressedMeshShape::getCollisionFilterInfo(hkpBvCompressedMeshShape *this, unsigned int key)
{
  __int64 result; // rax
  _BYTE *v4; // rbx
  __int64 v5; // rax
  int v6; // r11d
  __int64 v7; // rdx
  unsigned __int64 v8; // rdi
  int v9; // r8d
  int v10; // edx
  int i; // ecx
  int v12; // ecx
  unsigned __int64 v13; // r10
  int v14; // r9d
  int v15; // r9d
  _BYTE *v16; // rdx
  int v17; // r8d

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
    v13 = v8 + 8i64 * v12;
    v14 = v6 - *(unsigned __int8 *)(v13 + 4);
    if ( v14 < 0 )
    {
      v10 = (v10 + v9) >> 1;
    }
    else
    {
      if ( v14 < *(unsigned __int8 *)(v13 + 5) )
      {
        v4 = (_BYTE *)(v8 + 8i64 * v12);
        goto LABEL_18;
      }
      v9 = v12 + 1;
    }
  }
  v15 = 0;
  v16 = (_BYTE *)(v8 + 8i64 * v9);
  if ( i > 0 )
  {
    while ( 1 )
    {
      v17 = v6 - (unsigned __int8)v16[4];
      if ( v17 >= 0 && v17 < (unsigned __int8)v16[5] )
        break;
      ++v15;
      v16 += 8;
      if ( v15 >= i )
        goto LABEL_18;
    }
    v4 = v16;
  }
LABEL_18:
  LOBYTE(result) = *v4;
  if ( LODWORD(this->m_userData) )
    return *(unsigned int *)(*(_QWORD *)&this->m_type.m_storage + 4i64 * (unsigned __int8)result);
  else
    return (unsigned __int8)result;
}

