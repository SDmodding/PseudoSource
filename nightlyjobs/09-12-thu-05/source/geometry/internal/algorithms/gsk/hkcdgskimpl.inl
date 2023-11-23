// File Line: 1111
// RVA: 0x1317F50
void __fastcall hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>::getSupportingVertices(
        hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *this,
        hkcdGsk_Vector4Shape *shapeA,
        hkVector4f *directionA,
        const void *shapeB,
        hkTransformf *aTb,
        hkcdVertex *vertexAinAOut,
        hkcdVertex *vertexBinBOut,
        hkVector4f *vertexBinAout)
{
  *vertexBinBOut = 0i64;
  *vertexBinAout = 0i64;
  hkcdGsk_Vector4Shape::getSupportingVertex(shapeA, directionA, vertexAinAOut);
}

// File Line: 1145
// RVA: 0x1313D30
_BOOL8 __fastcall hkcdGskBase::castRay<hkcdGsk_Vector4Shape>(
        hkcdGskBase *this,
        hkcdGsk::LinearCastInput *shape,
        hkSimdFloat32 *input,
        hkVector4f *fractionInOut)
{
  hkBool result; // [rsp+50h] [rbp-E8h] BYREF
  hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> shapeInterface; // [rsp+58h] [rbp-E0h] BYREF
  hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> > v8; // [rsp+70h] [rbp-C8h] BYREF

  shapeInterface.vfptr = (hkcdGskBase::ShapeInterfaceVtbl *)&hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>::`vftable;
  *(_DWORD *)shapeInterface.m_vertexIds = 0;
  shapeInterface.m_dimAb = 65;
  return hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>>::linearCast<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>>(
           &v8,
           &result,
           &shapeInterface,
           this,
           0i64,
           shape,
           &shapeInterface,
           input,
           fractionInOut)->m_bool
      && COERCE_FLOAT(*input) != 0.0;
}

// File Line: 1165
// RVA: 0x1313DC0
hkBool *__fastcall hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>>::linearCast<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>>(
        hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> > *this,
        __m128 *result,
        hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *shapeInterface,
        __m128 **shapeA,
        __m128 *shapeB,
        hkcdGsk::LinearCastInput *input,
        hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *cache,
        hkSimdFloat32 *fractionInOut,
        hkVector4f *normalOut)
{
  __int64 v9; // rbx
  __m128 *v10; // r13
  __m128 **v11; // r11
  hkBool *v13; // r12
  __m128 v15; // xmm5
  __m128 v16; // xmm14
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm4
  __m128 v21; // xmm8
  hkBool *v22; // rax
  hkVector4f *p_m_support; // r15
  int v24; // ebx
  int v25; // edi
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 v28; // xmm10
  __m128 v29; // xmm9
  hkVector4f v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm11
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm7
  int v36; // edx
  __m128 v37; // xmm1
  hkcdVertex *m_verticesA; // rcx
  __int64 v39; // rax
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  unsigned int v46; // eax
  hkcdVertex *v47; // rdx
  hkcdVertex *v48; // rcx
  __m128 v49; // xmm11
  __m128 v50; // xmm0
  __m128 v51; // xmm13
  __m128 v52; // xmm5
  __m128 v53; // xmm6
  __m128 v54; // xmm3
  __m128 v55; // xmm3
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm4
  __m128 v59; // xmm10
  __m128 v60; // xmm3
  __m128 v61; // xmm1
  __m128 v62; // xmm0
  __m128 v63; // xmm1
  __m128 v64; // xmm3
  __m128 v65; // xmm0
  __m128 v66; // xmm7
  __m128 v67; // xmm4
  __m128 v68; // xmm1
  __m128 v69; // xmm6
  __m128 v70; // xmm5
  __m128 v71; // xmm5
  __m128 v72; // xmm1
  __m128 v73; // xmm5
  __m128 v74; // xmm3
  __m128 v75; // xmm0
  __m128 v76; // xmm2
  __m128 v77; // xmm7
  __m128 v78; // xmm1
  __m128 v79; // xmm3
  __m128 v80; // xmm1
  __m128 v81; // xmm7
  __m128 v82; // xmm2
  int v83; // ecx
  __m128 v84; // xmm3
  __m128 v85; // xmm2
  __m128 v86; // xmm0
  __m128 v87; // xmm4
  __m128 v88; // xmm7
  __m128 v89; // xmm10
  __m128 v90; // xmm8
  __m128 v91; // xmm5
  __m128 v92; // xmm1
  __m128 v93; // xmm2
  __m128 v94; // xmm3
  __m128 v95; // xmm9
  __m128 v96; // xmm6
  __m128 v97; // xmm9
  __m128 v98; // xmm9
  __m128 v99; // xmm8
  __m128 v100; // xmm6
  __m128 v101; // xmm8
  __m128 v102; // xmm6
  __m128 v103; // xmm7
  __m128 v104; // xmm1
  __m128 v105; // xmm7
  __m128 v106; // xmm2
  hkVector4f v107; // xmm8
  int v108; // r8d
  __m128 v109; // xmm2
  __m128 v110; // xmm1
  __m128 v111; // xmm3
  __m128 v112; // xmm2
  __m128 v113; // xmm1
  __m128 v114; // xmm10
  __m128 v115; // xmm12
  __m128 v116; // xmm1
  __m128 v117; // xmm2
  __m128 v118; // xmm9
  __m128 v119; // xmm8
  __m128 v120; // xmm1
  __m128 v121; // xmm5
  __m128 v122; // xmm1
  __m128 v123; // xmm3
  __m128 v124; // xmm1
  __m128 v125; // xmm4
  __m128 v126; // xmm1
  __m128 v127; // xmm0
  __m128 v128; // xmm8
  __m128 v129; // xmm7
  __m128 v130; // xmm1
  __m128 v131; // xmm0
  __m128 v132; // xmm3
  __m128 v133; // xmm3
  __m128 v134; // xmm0
  __m128 v135; // xmm4
  __m128 v136; // xmm3
  __m128 v137; // xmm0
  __m128 v138; // xmm3
  __m128 v139; // xmm10
  __m128 v140; // xmm3
  __m128 v141; // xmm4
  __m128 v142; // xmm0
  __m128 v143; // xmm2
  __m128 v144; // xmm1
  __m128 v145; // xmm2
  __m128 v146; // xmm10
  __m128 v147; // xmm9
  __m128 v148; // xmm1
  __m128 v149; // xmm4
  __m128 v150; // xmm8
  __m128 v151; // xmm1
  __m128 v152; // xmm7
  __m128 v153; // xmm5
  __m128 v154; // xmm1
  __m128 v155; // xmm3
  __m128 v156; // xmm1
  __m128 v157; // xmm4
  __m128 v158; // xmm1
  __m128 v159; // xmm2
  __m128 v160; // xmm6
  __m128 v161; // xmm0
  __m128 v162; // xmm3
  __m128 v163; // xmm0
  __m128 v164; // xmm1
  __m128 v165; // xmm3
  __m128 v166; // xmm4
  __m128 v167; // xmm9
  __m128 v168; // xmm0
  __m128 v169; // xmm2
  __m128 v170; // xmm2
  __m128 v171; // xmm0
  __m128 v172; // xmm12
  __m128 v173; // xmm11
  hkVector4f v174; // xmm10
  __m128 v175; // xmm1
  __m128 v176; // xmm3
  __m128 v177; // xmm4
  __m128 v178; // xmm2
  __m128 v179; // xmm0
  __m128 v180; // xmm1
  __m128 v181; // xmm3
  __m128 v182; // xmm0
  __m128 v183; // xmm7
  __m128 v184; // xmm4
  __m128 v185; // xmm5
  __m128 v186; // xmm6
  __m128 v187; // xmm6
  __m128 v188; // xmm1
  __m128 v189; // xmm6
  __m128 v190; // xmm3
  __m128 v191; // xmm0
  __m128 v192; // xmm2
  __m128 v193; // xmm7
  __m128 v194; // xmm1
  __m128 v195; // xmm3
  __m128 v196; // xmm1
  __m128 v197; // xmm7
  __m128 v198; // xmm2
  __m128 v199; // xmm2
  __m128 v200; // xmm3
  __m128 v201; // xmm1
  __m128 v202; // xmm4
  __m128 v203; // xmm5
  __m128 v204; // xmm8
  __m128 v205; // xmm9
  __m128 v206; // xmm7
  __m128 v207; // xmm2
  __m128 v208; // xmm11
  __m128 v209; // xmm6
  __m128 v210; // xmm6
  __m128 v211; // xmm9
  __m128 v212; // xmm7
  __m128 v213; // xmm9
  __m128 v214; // xmm7
  __m128 v215; // xmm8
  __m128 v216; // xmm1
  __m128 v217; // xmm8
  __m128 v218; // xmm2
  hkVector4f v219; // xmm9
  int v220; // eax
  float v221; // xmm1_4
  float v222; // xmm10_4
  float v223; // xmm1_4
  float v224; // xmm10_4
  int v225; // ecx
  __m128 v226; // xmm15
  __m128 v227; // xmm12
  __m128 v228; // xmm10
  __m128 v229; // xmm13
  __m128 v230; // xmm9
  __m128 v231; // xmm8
  __m128 v232; // xmm6
  __m128 v233; // xmm1
  __m128 v234; // xmm2
  __m128 v235; // xmm5
  __m128 v236; // xmm5
  __m128 v237; // xmm4
  __m128 v238; // xmm1
  __m128 v239; // xmm4
  __m128 v240; // xmm5
  __m128 v241; // xmm5
  __m128 v242; // xmm4
  __m128 v243; // xmm3
  __m128 v244; // xmm1
  __m128 v245; // xmm2
  __m128 v246; // xmm6
  __m128 v247; // xmm7
  __m128 v248; // xmm2
  __m128 v249; // xmm0
  __m128 v250; // xmm1
  __m128 v251; // xmm7
  int v252; // ecx
  int v253; // ecx
  int v254; // ecx
  int v255; // ecx
  __m128 v256; // xmm12
  __m128 v257; // xmm1
  __m128 v258; // xmm11
  __m128 v259; // xmm1
  __m128 v260; // xmm12
  __m128 v261; // xmm8
  __m128 v262; // xmm10
  __m128 v263; // xmm1
  __m128 v264; // xmm9
  __m128 v265; // xmm1
  __m128 v266; // xmm3
  __m128 v267; // xmm1
  __m128 v268; // xmm5
  __m128 v269; // xmm1
  __m128 v270; // xmm7
  __m128 v271; // xmm1
  __m128 v272; // xmm0
  __m128 v273; // xmm3
  __m128 v274; // xmm3
  __m128 v275; // xmm0
  __m128 v276; // xmm3
  __m128 v277; // xmm2
  __m128 v278; // xmm0
  __m128 v279; // xmm2
  int v280; // eax
  float v281; // xmm1_4
  float v282; // xmm10_4
  __m128 v283; // xmm6
  __m128 v284; // xmm1
  __m128 v285; // xmm8
  __m128 v286; // xmm4
  __m128 v287; // xmm9
  __m128 v288; // xmm6
  __m128 v289; // xmm7
  __m128 v290; // xmm5
  __m128 v291; // xmm1
  __m128 v292; // xmm2
  __m128 v293; // xmm1
  __m128 v294; // xmm3
  __m128 v295; // xmm5
  __m128 v296; // xmm1
  __m128 v297; // xmm3
  __m128 v298; // xmm2
  __m128 v299; // xmm2
  __m128 v300; // xmm1
  __m128 v301; // xmm1
  __m128 v302; // xmm3
  __m128 v303; // xmm7
  __m128 v304; // xmm2
  __m128 v305; // xmm2
  __m128 v306; // xmm11
  __m128 v307; // xmm10
  hkcdVertex *m_verticesBinA; // r9
  __m128 v309; // xmm1
  __m128 v310; // xmm2
  __m128 v311; // xmm6
  __m128 v312; // xmm4
  __m128 v313; // xmm5
  __m128 v314; // xmm3
  __m128 v315; // xmm0
  __m128 v316; // xmm1
  __m128 v317; // xmm9
  __m128 v318; // xmm3
  __m128 v319; // xmm9
  __m128 v320; // xmm8
  __m128 v321; // xmm8
  __m128 v322; // xmm0
  __m128 v323; // xmm8
  __m128 v324; // xmm4
  __m128 v325; // xmm5
  __m128 v326; // xmm9
  __m128 v327; // xmm4
  __m128 v328; // xmm1
  __m128 v329; // xmm3
  __m128 v330; // xmm2
  __m128 v331; // xmm4
  __m128i v332; // xmm5
  __m128 v333; // xmm1
  __m128 v334; // xmm2
  __m128 v335; // xmm9
  __m128 v336; // xmm1
  __m128 v337; // xmm4
  __m128 v338; // xmm4
  __m128 v339; // xmm6
  int v340; // edx
  __m128 v341; // xmm2
  int v342; // eax
  int v343; // ecx
  int v344; // r13d
  __int64 v345; // r10
  __int64 v346; // r15
  __int64 v347; // r8
  __int64 v348; // r12
  int v349; // edx
  __m128 v350; // xmm0
  __m128 v351; // xmm2
  __m128 v352; // xmm4
  __m128 v353; // xmm7
  __m128 v354; // xmm5
  __m128 v355; // xmm1
  __m128 v356; // xmm3
  __m128 v357; // xmm4
  __m128 v358; // xmm7
  __m128 v359; // xmm3
  __m128 v360; // xmm2
  __m128 v361; // xmm9
  __m128 v362; // xmm4
  __m128 v363; // xmm7
  __m128 v364; // xmm1
  __m128 v365; // xmm5
  __m128 v366; // xmm0
  __m128 v367; // xmm2
  __m128 v368; // xmm3
  __m128 v369; // xmm10
  __m128 v370; // xmm6
  __m128 v371; // xmm10
  __m128 v372; // xmm10
  __m128 v373; // xmm8
  __m128 v374; // xmm6
  __m128 v375; // xmm8
  __m128 v376; // xmm6
  __m128 v377; // xmm7
  __m128 v378; // xmm1
  __m128 v379; // xmm7
  __m128 v380; // xmm2
  hkVector4f v381; // xmm8
  int v382; // ecx
  __m128 v383; // xmm9
  hkcdVertex v384; // xmm1
  __int64 v385; // rcx
  int v386; // ecx
  __m128 v387; // xmm1
  __m128 v388; // xmm4
  __m128 v389; // xmm3
  __m128 v390; // xmm12
  __m128 v391; // xmm5
  __m128 v392; // xmm7
  __m128 v393; // xmm10
  __m128 v394; // xmm8
  __m128 v395; // xmm9
  __m128 v396; // xmm2
  __m128 v397; // xmm6
  __m128 v398; // xmm12
  __m128 v399; // xmm11
  __m128 v400; // xmm11
  __m128 v401; // xmm10
  __m128 v402; // xmm8
  __m128 v403; // xmm10
  __m128 v404; // xmm8
  __m128 v405; // xmm9
  __m128 v406; // xmm1
  __m128 v407; // xmm9
  __m128 v408; // xmm2
  hkVector4f v409; // xmm10
  int v410; // ecx
  __m128 v411; // xmm2
  __int64 v412; // rcx
  int v413; // ecx
  __int64 v414; // r9
  __int64 v415; // r8
  __m128 v416; // xmm0
  __m128 v417; // xmm4
  __m128 v418; // xmm3
  __m128 v419; // xmm2
  hkcdVertex v420; // xmm0
  __m128 v421; // xmm3
  __m128 v422; // xmm4
  __m128 v423; // xmm9
  __m128 v424; // xmm8
  __m128 v425; // xmm6
  __m128 v426; // xmm7
  __m128 v427; // xmm5
  __m128 v428; // xmm1
  __m128 v429; // xmm2
  __m128 v430; // xmm1
  __m128 v431; // xmm3
  __m128 v432; // xmm5
  __m128 v433; // xmm1
  __m128 v434; // xmm2
  __m128 v435; // xmm3
  __m128 v436; // xmm3
  __m128 v437; // xmm3
  __m128 v438; // xmm3
  __m128 v439; // xmm0
  __m128 v440; // xmm2
  __int64 v441; // r9
  __int64 v442; // r8
  __m128 v443; // xmm0
  __m128 v444; // xmm3
  __m128 v445; // xmm4
  __m128 v446; // xmm2
  hkcdVertex v447; // xmm0
  __m128 v448; // xmm3
  __m128 v449; // xmm0
  __m128 v450; // xmm2
  __m128 v451; // xmm6
  __m128 v452; // xmm7
  __m128 v453; // xmm1
  __m128 v454; // xmm3
  __m128 v455; // xmm1
  hkcdVertex *v456; // rax
  __int64 v457; // rcx
  __m128 v458; // xmm1
  __m128 v459; // xmm2
  __m128 v460; // xmm2
  float v461; // xmm0_4
  __int64 v462; // [rsp+40h] [rbp-A0h]
  __m128 v463; // [rsp+50h] [rbp-90h]
  __m128 v464; // [rsp+60h] [rbp-80h]
  __m128 v465; // [rsp+70h] [rbp-70h]
  __m128 v466; // [rsp+80h] [rbp-60h] BYREF
  __m128 v467; // [rsp+90h] [rbp-50h]
  __m128 v468; // [rsp+A0h] [rbp-40h]
  __m128 v469; // [rsp+B0h] [rbp-30h]
  __m128 v470; // [rsp+C0h] [rbp-20h]
  __m128 v471; // [rsp+D0h] [rbp-10h]
  __m128 v472; // [rsp+E0h] [rbp+0h]
  __m128 v473; // [rsp+F0h] [rbp+10h]
  __m128 v474; // [rsp+100h] [rbp+20h]
  __m128 v475; // [rsp+110h] [rbp+30h]
  __m128 m_quad; // [rsp+120h] [rbp+40h]
  __m128 v477; // [rsp+130h] [rbp+50h]
  __m128 v478; // [rsp+140h] [rbp+60h]
  __m128 v479; // [rsp+150h] [rbp+70h] BYREF
  __m128 v480; // [rsp+160h] [rbp+80h]
  __m128 v481; // [rsp+170h] [rbp+90h]
  __m128 v482; // [rsp+180h] [rbp+A0h]
  __m128 v483; // [rsp+190h] [rbp+B0h]
  __m128 v484; // [rsp+1A0h] [rbp+C0h]
  __m128 v485; // [rsp+1B0h] [rbp+D0h]
  __m128 v486; // [rsp+1C0h] [rbp+E0h]
  __m128 v487; // [rsp+1D0h] [rbp+F0h]
  __m128 v488; // [rsp+1E0h] [rbp+100h]
  __m128 v489; // [rsp+1F0h] [rbp+110h]
  __m128 v490; // [rsp+200h] [rbp+120h]
  __m128 v491; // [rsp+210h] [rbp+130h]
  __m128 v492; // [rsp+220h] [rbp+140h]
  __m128 v493; // [rsp+230h] [rbp+150h]
  __m128 v494; // [rsp+240h] [rbp+160h]
  __m128 v495; // [rsp+250h] [rbp+170h]
  __m128 v496; // [rsp+260h] [rbp+180h]
  __m128 v497; // [rsp+270h] [rbp+190h]
  __m128 v498; // [rsp+280h] [rbp+1A0h]
  char v499[16]; // [rsp+290h] [rbp+1B0h] BYREF
  __m128 v500; // [rsp+2A0h] [rbp+1C0h]
  __m128 v501; // [rsp+2B0h] [rbp+1D0h]
  __m128 v502; // [rsp+2C0h] [rbp+1E0h]
  __m128 v503; // [rsp+2D0h] [rbp+1F0h]
  __m128 v504; // [rsp+2E0h] [rbp+200h]
  __m128 v505; // [rsp+2F0h] [rbp+210h]
  __m128 v506; // [rsp+300h] [rbp+220h]
  __m128 v507; // [rsp+310h] [rbp+230h]
  __m128 v508; // [rsp+320h] [rbp+240h]
  __m128 v509; // [rsp+330h] [rbp+250h]
  __m128 v510; // [rsp+340h] [rbp+260h]
  __m128 v511; // [rsp+350h] [rbp+270h]
  __m128 v512; // [rsp+360h] [rbp+280h]
  __m128 v513; // [rsp+370h] [rbp+290h]
  __m128 v514; // [rsp+380h] [rbp+2A0h]
  hkBool *v515; // [rsp+478h] [rbp+398h]
  hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *vars0; // [rsp+480h] [rbp+3A0h]
  __m128 **retaddr; // [rsp+488h] [rbp+3A8h]
  __int64 v518; // [rsp+490h] [rbp+3B0h]

  v10 = result;
  v11 = shapeA;
  v13 = (hkBool *)result;
  v15 = result[1];
  v473 = *(__m128 *)_xmm;
  v16 = 0i64;
  v474 = (__m128)_xmm;
  v17 = _mm_mul_ps(v15, v15);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v507 = v18;
  v20 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v18), (__m128)0i64);
  v21 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v18, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                  _mm_mul_ps(v19, *(__m128 *)_xmm))),
              v15),
            v20),
          _mm_andnot_ps(v20, v15));
  if ( !_mm_movemask_ps(v20) )
  {
    result->m128_i8[0] = 0;
    return (hkBool *)result;
  }
  v518 = v9;
  v465 = 0i64;
  v464 = 0i64;
  p_m_support = &this->m_support;
  v24 = 0;
  HIDWORD(v462) = 0;
  v25 = 1;
  v26 = result[6];
  v27 = *result;
  v28 = 0i64;
  LOBYTE(v462) = 0;
  v29 = _mm_shuffle_ps(v26, v26, 0);
  v30.m_quad = _mm_sub_ps(*result, **shapeA);
  this->m_verticesA[0].m_quad = **shapeA;
  this->m_support = (hkVector4f)v30.m_quad;
  v31 = _mm_mul_ps(v30.m_quad, v30.m_quad);
  v480 = v29;
  v478 = _mm_shuffle_ps(v26, v26, 85);
  v32 = 0i64;
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v463 = v27;
  v466 = 0i64;
  v34 = _mm_rsqrt_ps(v33);
  v483 = v33;
  v465.m128_f32[1] = FLOAT_1_0e7;
  v470 = (__m128)xmmword_141A712D0;
  v35 = _mm_mul_ps(
          v30.m_quad,
          _mm_andnot_ps(
            _mm_cmple_ps(v33, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(v34, *(__m128 *)_xmm))));
  v467 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0e7), (__m128)LODWORD(FLOAT_1_0e7), 0);
  if ( (float)(v467.m128_f32[0] * v467.m128_f32[0]) <= v478.m128_f32[0] )
    goto $returnTrue;
LABEL_4:
  ((void (__fastcall *)(hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *, __m128 **, hkVector4f *, __int64, __m128 *, __m128 *, char *, __m128 *, __int64))shapeInterface->vfptr->getSupportingVertices)(
    shapeInterface,
    v11,
    p_m_support,
    v518,
    &v10[2],
    &v466,
    v499,
    &v479,
    v462);
  v36 = 0;
  v37 = _mm_sub_ps(v466, v479);
  v466 = v37;
  if ( v24 <= 0 )
  {
LABEL_8:
    v39 = v24++ + 2i64;
    *(&this->m_checkTriangleDots.m_quad + v39) = v37;
    v37 = v466;
  }
  else
  {
    m_verticesA = this->m_verticesA;
    while ( (_mm_movemask_ps(_mm_cmpeq_ps(v37, m_verticesA->m_quad)) & 7) != 7 )
    {
      ++v36;
      ++m_verticesA;
      if ( v36 >= v24 )
        goto LABEL_8;
    }
  }
  v40 = _mm_mul_ps(_mm_sub_ps(v27, _mm_add_ps(_mm_mul_ps(v35, v29), v37)), p_m_support->m_quad);
  v41 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)), _mm_shuffle_ps(v40, v40, 170));
  if ( v41.m128_f32[0] > v16.m128_f32[0] )
  {
    v42 = _mm_mul_ps(p_m_support->m_quad, v10[1]);
    v43 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
            _mm_shuffle_ps(v42, v42, 170));
    v485 = v43;
    if ( v43.m128_f32[0] >= v16.m128_f32[0]
      || (v44 = _mm_rcp_ps(v43),
          v45 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v43)), v44), v41),
          v28 = _mm_sub_ps(v28, v45),
          v481 = v45,
          v465 = v28,
          v28.m128_f32[0] >= 1.0) )
    {
      v22 = v515;
      v515->m_bool = 0;
      return v22;
    }
    v464 = v35;
    v27 = _mm_add_ps(*v10, _mm_mul_ps(v28, v10[1]));
    v463 = v27;
  }
  m_quad = p_m_support->m_quad;
  this->m_verticesBinA[0].m_quad = v27;
  v46 = (v25 | (8 * v24)) - 9;
  while ( 2 )
  {
    switch ( v46 )
    {
      case 0u:
        goto LABEL_130;
      case 1u:
        goto LABEL_76;
      case 2u:
        goto LABEL_107;
      case 3u:
        v306 = query.m_quad;
        v307 = this->m_verticesA[0].m_quad;
        m_verticesBinA = this->m_verticesBinA;
        goto LABEL_83;
      case 4u:
      case 5u:
      case 6u:
      case 7u:
      case 0xBu:
      case 0xCu:
      case 0xDu:
      case 0xEu:
      case 0xFu:
      case 0x12u:
      case 0x13u:
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
        goto LABEL_64;
      case 8u:
        goto LABEL_120;
      case 9u:
        goto LABEL_46;
      case 0xAu:
        v47 = this->m_verticesA;
        v48 = this->m_verticesBinA;
        goto LABEL_17;
      case 0x10u:
        goto LABEL_99;
      case 0x11u:
        v47 = this->m_verticesBinA;
        v48 = this->m_verticesA;
LABEL_17:
        if ( this->m_lastDimB.m_storage == 2 )
        {
          v49 = v48->m_quad;
          v50 = v48[2].m_quad;
          v51 = _mm_sub_ps(v48[1].m_quad, v50);
          v52 = v47->m_quad;
          v53 = v47[1].m_quad;
          v471 = _mm_sub_ps(v48->m_quad, v50);
          v468 = v51;
          v54 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v471, v471, 201), v51),
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v471));
          v55 = _mm_shuffle_ps(v54, v54, 201);
          v56 = _mm_mul_ps(_mm_sub_ps(v53, v49), v55);
          v57 = _mm_mul_ps(_mm_sub_ps(v52, v49), v55);
          v58 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                  _mm_shuffle_ps(v57, v57, 170));
          v59 = _mm_mul_ps(v58, v58);
          v60 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                  _mm_shuffle_ps(v56, v56, 170));
          v61 = _mm_mul_ps(v60, v60);
          if ( _mm_movemask_ps(_mm_mul_ps(v58, v60)) )
          {
            v487 = _mm_sub_ps(v58, v60);
            v62 = _mm_rcp_ps(v487);
            v501 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v487, v62)), v62), v58);
            v63 = v48[1].m_quad;
            v64 = _mm_add_ps(v47->m_quad, _mm_mul_ps(_mm_sub_ps(v47[1].m_quad, v47->m_quad), v501));
            v65 = _mm_sub_ps(v48[2].m_quad, v48->m_quad);
            v66 = _mm_sub_ps(v63, v64);
            v67 = _mm_sub_ps(v48[2].m_quad, v64);
            v68 = _mm_sub_ps(v63, v48->m_quad);
            v69 = _mm_sub_ps(v48->m_quad, v64);
            v70 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v68),
                    _mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v65));
            v71 = _mm_shuffle_ps(v70, v70, 201);
            v72 = _mm_shuffle_ps(v71, v71, 210);
            v73 = _mm_shuffle_ps(v71, v71, 201);
            v74 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v72),
                      _mm_mul_ps(_mm_shuffle_ps(v67, v67, 210), v73)),
                    v66);
            v75 = _mm_shuffle_ps(v66, v66, 210);
            v76 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v72),
                      _mm_mul_ps(_mm_shuffle_ps(v69, v69, 210), v73)),
                    v67);
            v77 = _mm_mul_ps(_mm_shuffle_ps(v66, v66, 201), v72);
            v78 = v74;
            v79 = _mm_unpackhi_ps(v74, v76);
            v80 = _mm_unpacklo_ps(v78, v76);
            v81 = _mm_mul_ps(_mm_sub_ps(v77, _mm_mul_ps(v75, v73)), v69);
            v82 = _mm_movelh_ps(v80, v81);
            if ( (_mm_movemask_ps(
                    _mm_cmplt_ps(
                      v16,
                      _mm_add_ps(
                        _mm_shuffle_ps(v79, v81, 228),
                        _mm_add_ps(v82, _mm_shuffle_ps(_mm_movehl_ps(v82, v80), v81, 212))))) & 7) == 7 )
            {
              v83 = 1;
              goto LABEL_42;
            }
          }
          else
          {
            v84 = v48[2].m_quad;
            v85 = v48[1].m_quad;
            v86 = _mm_cmplt_ps(v59, v61);
            v87 = _mm_sub_ps(v84, v85);
            v88 = _mm_sub_ps(v85, v49);
            v89 = _mm_or_ps(_mm_and_ps(v86, v52), _mm_andnot_ps(v86, v53));
            v90 = _mm_shuffle_ps(v87, v87, 201);
            v91 = _mm_sub_ps(v49, v84);
            v92 = _mm_sub_ps(v89, v85);
            v93 = _mm_sub_ps(v89, v84);
            v94 = _mm_sub_ps(v89, v49);
            v95 = _mm_shuffle_ps(v91, v91, 201);
            v96 = _mm_mul_ps(v95, v93);
            v97 = _mm_sub_ps(_mm_mul_ps(v95, v87), _mm_mul_ps(v90, v91));
            v98 = _mm_shuffle_ps(v97, v97, 201);
            v99 = _mm_sub_ps(_mm_mul_ps(v90, v92), _mm_mul_ps(_mm_shuffle_ps(v92, v92, 201), v87));
            v100 = _mm_sub_ps(v96, _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v91));
            v101 = _mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), v98);
            v102 = _mm_mul_ps(_mm_shuffle_ps(v100, v100, 201), v98);
            v103 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v88, v88, 201), v94),
                     _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v88));
            v104 = _mm_unpacklo_ps(v101, v102);
            v105 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 201), v98);
            v106 = _mm_movelh_ps(v104, v105);
            v107.m_quad = _mm_add_ps(
                            _mm_shuffle_ps(_mm_unpackhi_ps(v101, v102), v105, 228),
                            _mm_add_ps(v106, _mm_shuffle_ps(_mm_movehl_ps(v106, v104), v105, 212)));
            v108 = _mm_movemask_ps(_mm_cmplt_ps(v107.m_quad, v16)) & 7;
            if ( v108 == 7 )
            {
              v109 = _mm_mul_ps(_mm_sub_ps(this->m_verticesA[0].m_quad, this->m_verticesBinA[0].m_quad), v98);
              if ( _mm_movemask_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                       _mm_shuffle_ps(v109, v109, 170))) )
              {
                v110 = v48->m_quad;
                v98 = _mm_xor_ps(v98, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
                *v48 = (hkcdVertex)v48[1].m_quad;
                v48[1] = (hkcdVertex)v110;
                v107.m_quad = _mm_shuffle_ps(v107.m_quad, v107.m_quad, 225);
              }
            }
            *p_m_support = (hkVector4f)v98;
            this->m_checkTriangleDots = (hkVector4f)v107.m_quad;
            if ( v108 == 7 )
            {
              v83 = 0;
              *v47 = (hkcdVertex)v89;
              goto LABEL_42;
            }
          }
          v111 = _mm_sub_ps(v47[1].m_quad, v47->m_quad);
          v112 = _mm_sub_ps(v48[2].m_quad, v47->m_quad);
          v113 = _mm_mul_ps(v111, v51);
          v469 = v111;
          v114 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
                   _mm_shuffle_ps(v113, v113, 170));
          v115 = _mm_mul_ps(v111, v111);
          v116 = _mm_mul_ps(v112, v111);
          v117 = _mm_mul_ps(v112, v51);
          v118 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                   _mm_shuffle_ps(v116, v116, 170));
          v119 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                   _mm_shuffle_ps(v117, v117, 170));
          v120 = _mm_mul_ps(v51, v51);
          v489 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                   _mm_shuffle_ps(v115, v115, 170));
          v511 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v120, v120, 85), _mm_shuffle_ps(v120, v120, 0)),
                   _mm_shuffle_ps(v120, v120, 170));
          v121 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v511, v489), _mm_mul_ps(v114, v114)), *(__m128 *)&epsilon);
          v122 = _mm_rcp_ps(v121);
          v491 = v121;
          v123 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v122, v121)), v122);
          v124 = _mm_rcp_ps(v511);
          v503 = v123;
          v125 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v124, v511)), v124);
          v126 = _mm_rcp_ps(v489);
          v493 = v125;
          v509 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v126, v489)), v126);
          v127 = _mm_mul_ps(v119, v114);
          v128 = _mm_mul_ps(v119, v125);
          v129 = _mm_sub_ps(_mm_mul_ps(v511, v118), v127);
          v130 = _mm_cmplt_ps(v129, v121);
          v131 = _mm_mul_ps(
                   _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v130, v129), _mm_andnot_ps(v130, v121))),
                   v123);
          v132 = _mm_cmple_ps(v121, *(__m128 *)&epsilon);
          v133 = _mm_or_ps(_mm_andnot_ps(v132, v131), _mm_and_ps(v132, query.m_quad));
          v134 = _mm_mul_ps(v114, v125);
          v135 = v48[2].m_quad;
          v136 = _mm_sub_ps(_mm_mul_ps(v133, v134), v128);
          v137 = _mm_cmplt_ps(v136, query.m_quad);
          v138 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v137, v136), _mm_andnot_ps(v137, query.m_quad)));
          v139 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v114, v509), v138), _mm_mul_ps(v118, v509));
          v140 = _mm_add_ps(_mm_mul_ps(v138, v468), v135);
          v141 = _mm_sub_ps(v135, v47->m_quad);
          v142 = _mm_cmplt_ps(v139, query.m_quad);
          v143 = _mm_sub_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v142, v139), _mm_andnot_ps(v142, query.m_quad))),
                       v469),
                     v47->m_quad),
                   v140);
          v144 = _mm_mul_ps(v469, v471);
          v145 = _mm_mul_ps(v143, v143);
          v146 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v145, v145, 85), _mm_shuffle_ps(v145, v145, 0)),
                   _mm_shuffle_ps(v145, v145, 170));
          v147 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v144, v144, 85), _mm_shuffle_ps(v144, v144, 0)),
                   _mm_shuffle_ps(v144, v144, 170));
          v148 = _mm_mul_ps(v141, v469);
          v149 = _mm_mul_ps(v141, v471);
          v150 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v148, v148, 85), _mm_shuffle_ps(v148, v148, 0)),
                   _mm_shuffle_ps(v148, v148, 170));
          v151 = _mm_mul_ps(v471, v471);
          v152 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v149, v149, 85), _mm_shuffle_ps(v149, v149, 0)),
                   _mm_shuffle_ps(v149, v149, 170));
          v505 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v151, v151, 85), _mm_shuffle_ps(v151, v151, 0)),
                   _mm_shuffle_ps(v151, v151, 170));
          v495 = v489;
          v153 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v505, v489), _mm_mul_ps(v147, v147)), *(__m128 *)&epsilon);
          v154 = _mm_rcp_ps(v153);
          v497 = v153;
          v155 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v154, v153)), v154);
          v156 = _mm_rcp_ps(v505);
          v513 = v155;
          v157 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v156, v505)), v156);
          v158 = _mm_rcp_ps(v489);
          v482 = v157;
          v159 = _mm_cmple_ps(v153, *(__m128 *)&epsilon);
          v160 = _mm_sub_ps(_mm_mul_ps(v505, v150), _mm_mul_ps(v152, v147));
          v484 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v158, v489)), v158);
          v161 = _mm_cmplt_ps(v160, v153);
          v162 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_or_ps(
                       _mm_andnot_ps(
                         v159,
                         _mm_mul_ps(
                           _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v161, v160), _mm_andnot_ps(v161, v153))),
                           v155)),
                       _mm_and_ps(v159, query.m_quad)),
                     _mm_mul_ps(v147, v157)),
                   _mm_mul_ps(v152, v157));
          v163 = _mm_cmplt_ps(v162, query.m_quad);
          v164 = _mm_and_ps(v163, v162);
          v165 = v48[2].m_quad;
          v16 = 0i64;
          v166 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v163, query.m_quad), v164));
          v167 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v147, v484), v166), _mm_mul_ps(v150, v484));
          v168 = _mm_cmplt_ps(v167, query.m_quad);
          v169 = _mm_sub_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v168, query.m_quad), _mm_and_ps(v168, v167))),
                       v469),
                     v47->m_quad),
                   _mm_add_ps(_mm_mul_ps(v166, v471), v165));
          v170 = _mm_mul_ps(v169, v169);
          v171 = _mm_cmplt_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v170, v170, 85), _mm_shuffle_ps(v170, v170, 0)),
                     _mm_shuffle_ps(v170, v170, 170)),
                   v146);
          v48->m_quad = _mm_or_ps(_mm_and_ps(v171, v48->m_quad), _mm_andnot_ps(v171, v48[1].m_quad));
          v48[1] = (hkcdVertex)v165;
        }
        else
        {
          v172 = v48->m_quad;
          v173 = v47[1].m_quad;
          v174.m_quad = (__m128)this->m_checkTriangleDots;
          v175 = _mm_mul_ps(p_m_support->m_quad, _mm_sub_ps(v47->m_quad, v48->m_quad));
          v176 = _mm_mul_ps(p_m_support->m_quad, _mm_sub_ps(v173, v48->m_quad));
          v177 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v175, v175, 85), _mm_shuffle_ps(v175, v175, 0)),
                   _mm_shuffle_ps(v175, v175, 170));
          v178 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v176, v176, 85), _mm_shuffle_ps(v176, v176, 0)),
                   _mm_shuffle_ps(v176, v176, 170));
          if ( (float)(v178.m128_f32[0] * v177.m128_f32[0]) < v16.m128_f32[0] )
          {
            v486 = _mm_sub_ps(v177, v178);
            v179 = _mm_rcp_ps(v486);
            v488 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v486, v179)), v179), v177);
            v172 = v48->m_quad;
            v173 = v47[1].m_quad;
            v180 = _mm_sub_ps(v48[1].m_quad, v48->m_quad);
            v181 = _mm_add_ps(v47->m_quad, _mm_mul_ps(_mm_sub_ps(v173, v47->m_quad), v488));
            v182 = _mm_sub_ps(v48[2].m_quad, v48->m_quad);
            v183 = _mm_sub_ps(v48[1].m_quad, v181);
            v184 = _mm_sub_ps(v48->m_quad, v181);
            v185 = _mm_sub_ps(v48[2].m_quad, v181);
            v186 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v182, v182, 201), v180),
                     _mm_mul_ps(_mm_shuffle_ps(v180, v180, 201), v182));
            v187 = _mm_shuffle_ps(v186, v186, 201);
            v188 = _mm_shuffle_ps(v187, v187, 210);
            v189 = _mm_shuffle_ps(v187, v187, 201);
            v190 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v185, v185, 201), v188),
                       _mm_mul_ps(_mm_shuffle_ps(v185, v185, 210), v189)),
                     v183);
            v191 = _mm_shuffle_ps(v183, v183, 210);
            v192 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v184, v184, 201), v188),
                       _mm_mul_ps(_mm_shuffle_ps(v184, v184, 210), v189)),
                     v185);
            v193 = _mm_mul_ps(_mm_shuffle_ps(v183, v183, 201), v188);
            v194 = v190;
            v195 = _mm_unpackhi_ps(v190, v192);
            v196 = _mm_unpacklo_ps(v194, v192);
            v197 = _mm_mul_ps(_mm_sub_ps(v193, _mm_mul_ps(v191, v189)), v184);
            v198 = _mm_movelh_ps(v196, v197);
            if ( (_mm_movemask_ps(
                    _mm_cmplt_ps(
                      v16,
                      _mm_add_ps(
                        _mm_shuffle_ps(v195, v197, 228),
                        _mm_add_ps(v198, _mm_shuffle_ps(_mm_movehl_ps(v198, v196), v197, 212))))) & 7) == 7 )
            {
              v83 = 1;
              goto LABEL_42;
            }
          }
          v199 = v48[1].m_quad;
          v200 = v48[2].m_quad;
          v201 = _mm_sub_ps(v173, v199);
          v202 = _mm_sub_ps(v200, v199);
          v203 = _mm_sub_ps(v172, v200);
          v204 = _mm_sub_ps(v199, v172);
          v205 = _mm_shuffle_ps(v202, v202, 201);
          v206 = _mm_shuffle_ps(v203, v203, 201);
          v207 = _mm_sub_ps(v173, v200);
          v208 = _mm_sub_ps(v173, v172);
          v209 = _mm_sub_ps(_mm_mul_ps(v206, v202), _mm_mul_ps(v205, v203));
          v210 = _mm_shuffle_ps(v209, v209, 201);
          v211 = _mm_sub_ps(_mm_mul_ps(v205, v201), _mm_mul_ps(_mm_shuffle_ps(v201, v201, 201), v202));
          v212 = _mm_sub_ps(_mm_mul_ps(v206, v207), _mm_mul_ps(_mm_shuffle_ps(v207, v207, 201), v203));
          v213 = _mm_mul_ps(_mm_shuffle_ps(v211, v211, 201), v210);
          v214 = _mm_mul_ps(_mm_shuffle_ps(v212, v212, 201), v210);
          v215 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v204, v204, 201), v208),
                   _mm_mul_ps(_mm_shuffle_ps(v208, v208, 201), v204));
          v216 = _mm_unpacklo_ps(v213, v214);
          v217 = _mm_mul_ps(_mm_shuffle_ps(v215, v215, 201), v210);
          v218 = _mm_movelh_ps(v216, v217);
          v219.m_quad = _mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v213, v214), v217, 228),
                          _mm_add_ps(v218, _mm_shuffle_ps(_mm_movehl_ps(v218, v216), v217, 212)));
          this->m_checkTriangleDots = (hkVector4f)v219.m_quad;
          v220 = _mm_movemask_ps(_mm_cmplt_ps(v219.m_quad, v16)) & 7;
          switch ( v220 )
          {
            case 7:
              v83 = 0;
              *v47 = (hkcdVertex)v47[1].m_quad;
              goto LABEL_42;
            case 6:
              goto LABEL_40;
            case 5:
              goto LABEL_56;
            case 3:
              goto LABEL_41;
          }
          if ( v220 != 1 )
          {
            if ( v220 == 2 )
            {
              v223 = _mm_shuffle_ps(v174.m_quad, v174.m_quad, 170).m128_f32[0];
              v224 = _mm_shuffle_ps(v174.m_quad, v174.m_quad, 0).m128_f32[0];
              if ( (float)((float)(_mm_shuffle_ps(v219.m_quad, v219.m_quad, 170).m128_f32[0] - v223) * v224) <= (float)((float)(_mm_shuffle_ps(v219.m_quad, v219.m_quad, 0).m128_f32[0] - v224) * v223) )
                goto LABEL_41;
LABEL_40:
              *v48 = (hkcdVertex)v48[2].m_quad;
              goto LABEL_41;
            }
            if ( v220 != 4 )
              goto LABEL_40;
            v281 = _mm_shuffle_ps(v174.m_quad, v174.m_quad, 0).m128_f32[0];
            v282 = _mm_shuffle_ps(v174.m_quad, v174.m_quad, 85).m128_f32[0];
            if ( (float)((float)(_mm_shuffle_ps(v219.m_quad, v219.m_quad, 0).m128_f32[0] - v281) * v282) <= (float)((float)(_mm_shuffle_ps(v219.m_quad, v219.m_quad, 85).m128_f32[0] - v282) * v281) )
              goto LABEL_40;
LABEL_56:
            v48[1] = (hkcdVertex)v48[2].m_quad;
            goto LABEL_41;
          }
          v221 = _mm_shuffle_ps(v174.m_quad, v174.m_quad, 85).m128_f32[0];
          v222 = _mm_shuffle_ps(v174.m_quad, v174.m_quad, 170).m128_f32[0];
          if ( (float)((float)(_mm_shuffle_ps(v219.m_quad, v219.m_quad, 85).m128_f32[0] - v221) * v222) <= (float)((float)(_mm_shuffle_ps(v219.m_quad, v219.m_quad, 170).m128_f32[0] - v222) * v221) )
            v48[1] = (hkcdVertex)v48[2].m_quad;
        }
LABEL_41:
        v83 = 2;
LABEL_42:
        if ( !v83 )
        {
          if ( v24 == 2 )
            v24 = 1;
          else
            v25 = 1;
          goto LABEL_132;
        }
        v225 = v83 - 1;
        if ( !v225 )
          goto LABEL_64;
        if ( v225 != 1 )
          goto LABEL_132;
        v24 = 2;
        v25 = 2;
LABEL_46:
        v226 = this->m_verticesA[0].m_quad;
        v227 = this->m_verticesBinA[0].m_quad;
        v228 = this->m_verticesA[1].m_quad;
        v229 = _mm_sub_ps(v228, v226);
        v230 = _mm_sub_ps(v226, v227);
        v231 = _mm_sub_ps(this->m_verticesBinA[1].m_quad, v227);
        v232 = _mm_sub_ps(this->m_verticesBinA[1].m_quad, v226);
        v233 = _mm_shuffle_ps(v229, v229, 201);
        v468 = v230;
        v234 = _mm_shuffle_ps(v231, v231, 201);
        v235 = _mm_sub_ps(_mm_mul_ps(v234, v229), _mm_mul_ps(v233, v231));
        v236 = _mm_shuffle_ps(v235, v235, 201);
        *p_m_support = (hkVector4f)v236;
        v237 = _mm_mul_ps(v236, v233);
        v238 = _mm_shuffle_ps(v236, v236, 201);
        v239 = _mm_sub_ps(v237, _mm_mul_ps(v238, v229));
        v240 = _mm_sub_ps(_mm_mul_ps(v236, v234), _mm_mul_ps(v238, v231));
        v241 = _mm_shuffle_ps(v240, v240, 201);
        v242 = _mm_shuffle_ps(v239, v239, 201);
        v243 = _mm_mul_ps(_mm_sub_ps(v227, v228), v241);
        v244 = _mm_mul_ps(v230, v242);
        v245 = _mm_mul_ps(v230, v241);
        v246 = _mm_mul_ps(v232, v242);
        v247 = _mm_shuffle_ps(v245, v243, 238);
        v248 = _mm_shuffle_ps(v245, v243, 68);
        v249 = _mm_shuffle_ps(v244, v246, 238);
        v250 = _mm_shuffle_ps(v244, v246, 68);
        v251 = _mm_add_ps(
                 _mm_shuffle_ps(v247, v249, 136),
                 _mm_add_ps(_mm_shuffle_ps(v248, v250, 221), _mm_shuffle_ps(v248, v250, 136)));
        v252 = _mm_movemask_ps(_mm_cmplt_ps(v16, v251));
        if ( v252 == 15 )
        {
          v302 = _mm_shuffle_ps(v251, v251, 0);
          v303 = _mm_add_ps(_mm_shuffle_ps(v251, v251, 85), v302);
          v304 = _mm_rcp_ps(v303);
          v502 = v303;
          v477 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v304, v303)), v304), v302);
          v305 = _mm_mul_ps(p_m_support->m_quad, v230);
          p_m_support->m_quad = _mm_xor_ps(
                                  p_m_support->m_quad,
                                  (__m128)_mm_slli_epi32(
                                            _mm_srli_epi32(
                                              (__m128i)_mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v305, v305, 85),
                                                           _mm_shuffle_ps(v305, v305, 0)),
                                                         _mm_shuffle_ps(v305, v305, 170)),
                                              0x1Fu),
                                            0x1Fu));
          this->m_closestPointOnEdgeA.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v228, v226), v477), v226);
          goto LABEL_132;
        }
        v253 = v252 - 7;
        if ( !v253 )
        {
          this->m_verticesBinA[0] = this->m_verticesBinA[1];
LABEL_79:
          v25 = 1;
LABEL_120:
          v422 = this->m_verticesA[1].m_quad;
          v423 = this->m_verticesBinA[0].m_quad;
          v424 = this->m_verticesA[0].m_quad;
          v425 = _mm_sub_ps(v422, v424);
          v426 = _mm_sub_ps(v422, v423);
          v427 = _mm_sub_ps(v424, v423);
          v428 = _mm_mul_ps(v426, v425);
          v429 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v428, v428, 85), _mm_shuffle_ps(v428, v428, 0)),
                   _mm_shuffle_ps(v428, v428, 170));
          v430 = _mm_mul_ps(v427, v425);
          v431 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v430, v430, 85), _mm_shuffle_ps(v430, v430, 0)),
                   _mm_shuffle_ps(v430, v430, 170));
          if ( (float)(v431.m128_f32[0] * v429.m128_f32[0]) >= v16.m128_f32[0] )
          {
            v24 = 1;
            v439 = _mm_cmple_ps(v429, v16);
            v440 = _mm_or_ps(_mm_and_ps(v439, v422), _mm_andnot_ps(v439, v424));
            p_m_support->m_quad = _mm_sub_ps(v440, v423);
            this->m_verticesA[0].m_quad = v440;
          }
          else
          {
            v24 = 2;
            v432 = _mm_sub_ps(_mm_mul_ps(v427, v429), _mm_mul_ps(v426, v431));
            v433 = _mm_mul_ps(v425, v425);
            v434 = _mm_shuffle_ps(v425, v425, 201);
            v435 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v432, v432, 201), v425), _mm_mul_ps(v432, v434));
            v510 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v433, v433, 85), _mm_shuffle_ps(v433, v433, 0)),
                     _mm_shuffle_ps(v433, v433, 170));
            v436 = _mm_shuffle_ps(v435, v435, 201);
            v475 = _mm_rcp_ps(v510);
            v437 = _mm_sub_ps(_mm_mul_ps(v436, v434), _mm_mul_ps(_mm_shuffle_ps(v436, v436, 201), v425));
            v438 = _mm_shuffle_ps(v437, v437, 201);
            *p_m_support = (hkVector4f)v438;
            p_m_support->m_quad = _mm_mul_ps(v475, v438);
          }
          goto LABEL_132;
        }
        v254 = v253 - 4;
        if ( !v254 )
          goto LABEL_79;
        v255 = v254 - 2;
        if ( v255 )
        {
          if ( v255 == 1 )
            goto LABEL_75;
          v256 = _mm_sub_ps(v227, v226);
          v257 = _mm_mul_ps(v231, v229);
          v258 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v257, v257, 85), _mm_shuffle_ps(v257, v257, 0)),
                   _mm_shuffle_ps(v257, v257, 170));
          v259 = _mm_mul_ps(v256, v229);
          v260 = _mm_mul_ps(v256, v231);
          v261 = _mm_mul_ps(v231, v231);
          v262 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v259, v259, 85), _mm_shuffle_ps(v259, v259, 0)),
                   _mm_shuffle_ps(v259, v259, 170));
          v263 = _mm_mul_ps(v229, v229);
          v264 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v260, v260, 85), _mm_shuffle_ps(v260, v260, 0)),
                   _mm_shuffle_ps(v260, v260, 170));
          v490 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v263, v263, 85), _mm_shuffle_ps(v263, v263, 0)),
                   _mm_shuffle_ps(v263, v263, 170));
          v492 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v261, v261, 85), _mm_shuffle_ps(v261, v261, 0)),
                   _mm_shuffle_ps(v261, v261, 170));
          v27 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v492, v490), _mm_mul_ps(v258, v258)), *(__m128 *)&epsilon);
          v265 = _mm_rcp_ps(v27);
          v494 = v27;
          v266 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v265, v27)), v265);
          v267 = _mm_rcp_ps(v492);
          v496 = v266;
          v268 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v267, v492)), v267);
          v269 = _mm_rcp_ps(v490);
          v498 = v268;
          v270 = _mm_sub_ps(_mm_mul_ps(v492, v262), _mm_mul_ps(v264, v258));
          v500 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v269, v490)), v269);
          v271 = _mm_cmplt_ps(v270, v27);
          v28 = _mm_mul_ps(v262, v500);
          v272 = _mm_mul_ps(
                   _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v271, v27), _mm_and_ps(v271, v270))),
                   v266);
          v273 = _mm_cmple_ps(v27, *(__m128 *)&epsilon);
          v274 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_or_ps(_mm_andnot_ps(v273, v272), _mm_and_ps(v273, query.m_quad)),
                     _mm_mul_ps(v268, v258)),
                   _mm_mul_ps(v264, v268));
          v275 = _mm_cmplt_ps(v274, query.m_quad);
          v276 = _mm_max_ps(v16, _mm_or_ps(_mm_and_ps(v275, v274), _mm_andnot_ps(v275, query.m_quad)));
          v277 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v500, v258), v276), v28);
          v278 = _mm_cmplt_ps(v277, query.m_quad);
          v279 = _mm_max_ps(v16, _mm_or_ps(_mm_and_ps(v278, v277), _mm_andnot_ps(v278, query.m_quad)));
          v280 = _mm_movemask_ps(
                   _mm_cmpeq_ps(
                     (__m128)xmmword_141A71330,
                     _mm_movelh_ps(_mm_unpacklo_ps(v279, v279), _mm_unpacklo_ps(v276, v276))));
          this->m_closestPointOnEdgeA.m_quad = _mm_add_ps(_mm_mul_ps(v279, v229), v226);
          if ( !v280 )
          {
            v284 = _mm_mul_ps(p_m_support->m_quad, v468);
            p_m_support->m_quad = _mm_xor_ps(
                                    p_m_support->m_quad,
                                    (__m128)_mm_slli_epi32(
                                              _mm_srli_epi32(
                                                (__m128i)_mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_shuffle_ps(v284, v284, 85),
                                                             _mm_shuffle_ps(v284, v284, 0)),
                                                           _mm_shuffle_ps(v284, v284, 170)),
                                                0x1Fu),
                                              0x1Fu));
            goto LABEL_132;
          }
          if ( (v280 & 1) != 0 )
          {
            v24 = 1;
            this->m_verticesA[0] = this->m_verticesA[1];
          }
          else if ( (v280 & 2) != 0 )
          {
            v24 = 1;
          }
          if ( (v280 & 4) != 0 )
          {
            v25 = 1;
            this->m_verticesBinA[0] = this->m_verticesBinA[1];
          }
          else if ( (v280 & 8) != 0 )
          {
            v25 = 1;
          }
          v46 = (v25 | (8 * v24)) - 9;
          if ( v46 > 0x18 )
            goto LABEL_64;
          continue;
        }
        this->m_verticesA[0] = this->m_verticesA[1];
LABEL_75:
        v24 = 1;
LABEL_76:
        v285 = this->m_verticesBinA[1].m_quad;
        v286 = this->m_verticesA[0].m_quad;
        v287 = this->m_verticesBinA[0].m_quad;
        v288 = _mm_sub_ps(v285, v287);
        v289 = _mm_sub_ps(v285, v286);
        v290 = _mm_sub_ps(v287, v286);
        v291 = _mm_mul_ps(v289, v288);
        v292 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v291, v291, 85), _mm_shuffle_ps(v291, v291, 0)),
                 _mm_shuffle_ps(v291, v291, 170));
        v293 = _mm_mul_ps(v290, v288);
        v294 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v293, v293, 85), _mm_shuffle_ps(v293, v293, 0)),
                 _mm_shuffle_ps(v293, v293, 170));
        if ( (float)(v294.m128_f32[0] * v292.m128_f32[0]) >= v16.m128_f32[0] )
        {
          v25 = 1;
          v449 = _mm_cmple_ps(v292, v16);
          v450 = _mm_or_ps(_mm_and_ps(v449, v285), _mm_andnot_ps(v449, v287));
          p_m_support->m_quad = _mm_sub_ps(v286, v450);
          this->m_verticesBinA[0].m_quad = v450;
        }
        else
        {
          v25 = 2;
          v295 = _mm_sub_ps(_mm_mul_ps(v290, v292), _mm_mul_ps(v289, v294));
          v296 = _mm_mul_ps(v288, v288);
          v297 = _mm_shuffle_ps(v288, v288, 201);
          v512 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v296, v296, 85), _mm_shuffle_ps(v296, v296, 0)),
                   _mm_shuffle_ps(v296, v296, 170));
          v472 = _mm_rcp_ps(v512);
          v298 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v295, v295, 201), v288), _mm_mul_ps(v295, v297));
          v299 = _mm_shuffle_ps(v298, v298, 201);
          v300 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v299, v299, 201), v288), _mm_mul_ps(v299, v297));
          v301 = _mm_shuffle_ps(v300, v300, 201);
          *p_m_support = (hkVector4f)v301;
          p_m_support->m_quad = _mm_mul_ps(v472, v301);
        }
LABEL_132:
        v451 = v467;
        this->m_lastDimB.m_storage = v25;
        v452 = _mm_xor_ps(
                 (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                 p_m_support->m_quad);
        *p_m_support = (hkVector4f)v452;
        v453 = _mm_mul_ps(v452, v452);
        v454 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v453, v453, 85), _mm_shuffle_ps(v453, v453, 0)),
                 _mm_shuffle_ps(v453, v453, 170));
        v455 = _mm_rsqrt_ps(v454);
        v514 = v454;
        v35 = _mm_mul_ps(
                v452,
                _mm_andnot_ps(
                  _mm_cmple_ps(v454, v16),
                  _mm_mul_ps(_mm_sub_ps(v474, _mm_mul_ps(_mm_mul_ps(v455, v454), v455)), _mm_mul_ps(v455, v473))));
        if ( v24 > 0 )
        {
          v456 = this->m_verticesA;
          v457 = (unsigned int)v24;
          do
          {
            ++v456;
            v458 = _mm_mul_ps(_mm_sub_ps(this->m_verticesBinA[0].m_quad, v456[-1].m_quad), v35);
            v451 = _mm_min_ps(
                     v451,
                     (__m128)_mm_srli_epi32(
                               _mm_slli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v458, v458, 85), _mm_shuffle_ps(v458, v458, 0)),
                                            _mm_shuffle_ps(v458, v458, 170)),
                                 1u),
                               1u));
            --v457;
          }
          while ( v457 );
          v467 = v451;
        }
        v459 = _mm_sub_ps(p_m_support->m_quad, m_quad);
        v470 = _mm_add_ps(v470, v470);
        v460 = _mm_mul_ps(v459, v459);
        if ( (float)((float)(_mm_shuffle_ps(v460, v460, 85).m128_f32[0] + _mm_shuffle_ps(v460, v460, 0).m128_f32[0])
                   + _mm_shuffle_ps(v460, v460, 170).m128_f32[0]) >= v470.m128_f32[0]
          || (++HIDWORD(v462), SHIDWORD(v462) < 3) )
        {
          v28 = v465;
          v461 = v451.m128_f32[0] * v451.m128_f32[0];
          v27 = v463;
          if ( v461 <= v478.m128_f32[0] )
            goto LABEL_65;
          v29 = v480;
          shapeInterface = vars0;
          v11 = retaddr;
          goto LABEL_4;
        }
LABEL_64:
        v28 = v465;
        v27 = v463;
LABEL_65:
        v13 = v515;
        v32 = v464;
        v21 = v464;
$returnTrue:
        if ( v28.m128_f32[0] >= *(float *)shapeA
          || v28.m128_f32[0] > (float)(1.0 - 0.00000011920929)
          && (v283 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(v27, *v10), v10[1]), v21),
              (float)((float)(_mm_shuffle_ps(v283, v283, 85).m128_f32[0] + _mm_shuffle_ps(v283, v283, 0).m128_f32[0])
                    + _mm_shuffle_ps(v283, v283, 170).m128_f32[0]) < 0.00000011920929) )
        {
          v13->m_bool = 0;
        }
        else
        {
          *(__m128 *)shapeA = v28;
          *shapeB = v32;
          v13->m_bool = 1;
        }
        return v13;
      case 0x18u:
        v306 = g_vectorfConstants[0];
        v307 = this->m_verticesBinA[0].m_quad;
        m_verticesBinA = this->m_verticesA;
LABEL_83:
        v309 = m_verticesBinA[1].m_quad;
        v310 = m_verticesBinA[2].m_quad;
        v311 = _mm_sub_ps(v309, m_verticesBinA->m_quad);
        v312 = _mm_sub_ps(m_verticesBinA->m_quad, v310);
        v313 = _mm_sub_ps(m_verticesBinA[3].m_quad, m_verticesBinA->m_quad);
        v314 = _mm_sub_ps(v310, v309);
        v315 = _mm_sub_ps(m_verticesBinA[3].m_quad, v309);
        v316 = _mm_sub_ps(m_verticesBinA[3].m_quad, v310);
        v317 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v315, v315, 201), v314),
                 _mm_mul_ps(_mm_shuffle_ps(v314, v314, 201), v315));
        v318 = _mm_mul_ps(_mm_sub_ps(v307, m_verticesBinA[3].m_quad), v306);
        v319 = _mm_shuffle_ps(v317, v317, 201);
        v320 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v316, v316, 201), v312),
                 _mm_mul_ps(_mm_shuffle_ps(v312, v312, 201), v316));
        v321 = _mm_shuffle_ps(v320, v320, 201);
        v322 = _mm_mul_ps(v318, v321);
        v323 = _mm_mul_ps(v321, v321);
        v324 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v313, v313, 201), v311),
                 _mm_mul_ps(_mm_shuffle_ps(v311, v311, 201), v313));
        v325 = _mm_mul_ps(v318, v319);
        v326 = _mm_mul_ps(v319, v319);
        v327 = _mm_shuffle_ps(v324, v324, 201);
        v328 = _mm_unpacklo_ps(v325, v322);
        v329 = _mm_mul_ps(v318, v327);
        v330 = _mm_movelh_ps(v328, v329);
        v331 = _mm_mul_ps(v327, v327);
        v332 = (__m128i)_mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v325, v322), v329, 228),
                          _mm_add_ps(v330, _mm_shuffle_ps(_mm_movehl_ps(v330, v328), v329, 212)));
        v333 = _mm_unpacklo_ps(v326, v323);
        v334 = _mm_movelh_ps(v333, v331);
        v335 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v326, v323), v331, 228),
                 _mm_add_ps(v334, _mm_shuffle_ps(_mm_movehl_ps(v334, v333), v331, 212)));
        v336 = _mm_rcp_ps(v335);
        v504 = v335;
        v506 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v336, v335)), v336);
        v337 = _mm_cmpeq_ps(v16, v335);
        v465.m128_i32[0] = 897988542;
        v338 = _mm_or_ps(
                 _mm_andnot_ps(
                   v337,
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v332, 1u), 1u), (__m128)v332), v506)),
                 _mm_and_ps(v337, (__m128)xmmword_141A712A0));
        v339 = _mm_max_ps(
                 _mm_shuffle_ps(v338, v338, 170),
                 _mm_max_ps(_mm_shuffle_ps(v338, v338, 85), _mm_shuffle_ps(v338, v338, 0)));
        v508 = _mm_and_ps(_mm_cmple_ps(v339, v338), (__m128)xmmword_141C1F4F0);
        v340 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(v508)];
        if ( v339.m128_f32[0] < _mm_shuffle_ps((__m128)0x358637BEu, (__m128)0x358637BEu, 0).m128_f32[0] )
          goto LABEL_64;
        v465.m128_i32[2] = 1066192077;
        v341 = _mm_or_ps(
                 _mm_andnot_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v340], v338),
                 _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v340], (__m128)xmmword_141A712F0));
        if ( v339.m128_f32[0] <= (float)(fmax(
                                           _mm_shuffle_ps(v341, v341, 170).m128_f32[0],
                                           fmax(
                                             _mm_shuffle_ps(v341, v341, 85).m128_f32[0],
                                             _mm_shuffle_ps(v341, v341, 0).m128_f32[0]))
                                       * _mm_shuffle_ps((__m128)0x3F8CCCCDu, (__m128)0x3F8CCCCDu, 0).m128_f32[0]) )
        {
          v342 = 2;
          v343 = 1;
          v344 = 4;
          v345 = 32i64;
          v346 = 16i64;
          v347 = 0i64;
          v348 = 3i64;
          v349 = _mm_movemask_ps(_mm_cmple_ps(v16, (__m128)v332));
          do
          {
            if ( (v349 & v343) != 0 && (v349 & v342) != 0 )
            {
              v350 = *(__m128 *)((char *)&m_verticesBinA->m_quad + v345);
              v351 = _mm_sub_ps(m_verticesBinA[v347].m_quad, v350);
              v352 = _mm_sub_ps(m_verticesBinA[3].m_quad, v350);
              v353 = _mm_sub_ps(v307, v350);
              v354 = _mm_mul_ps(v352, v351);
              v355 = _mm_sub_ps(*(__m128 *)((char *)&m_verticesBinA->m_quad + v346), v350);
              v356 = _mm_mul_ps(v353, v351);
              v357 = _mm_mul_ps(v352, v355);
              v358 = _mm_mul_ps(v353, v355);
              if ( (float)((float)((float)(_mm_shuffle_ps(v356, v356, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v356, v356, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v356, v356, 170).m128_f32[0])
                         * (float)((float)(_mm_shuffle_ps(v357, v357, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v357, v357, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v357, v357, 170).m128_f32[0])) >= (float)((float)((float)(_mm_shuffle_ps(v354, v354, 85).m128_f32[0] + _mm_shuffle_ps(v354, v354, 0).m128_f32[0])
                                                                                                  + _mm_shuffle_ps(v354, v354, 170).m128_f32[0])
                                                                                          * (float)((float)(_mm_shuffle_ps(v358, v358, 85).m128_f32[0] + _mm_shuffle_ps(v358, v358, 0).m128_f32[0])
                                                                                                  + _mm_shuffle_ps(v358, v358, 170).m128_f32[0])) )
                v342 = v343;
              v349 &= ~v342;
            }
            v342 = v344;
            v346 = v345;
            v344 = v343;
            v343 = __ROL4__(v343, 1);
            v345 = v347 * 16;
            ++v347;
            --v348;
          }
          while ( v348 );
          p_m_support = &this->m_support;
          if ( (v349 & 7) != 0 )
            v340 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v349];
          else
            v340 = -1;
          v10 = result;
        }
        if ( v340 < 0 )
          goto LABEL_64;
        m_verticesBinA[v340] = (hkcdVertex)m_verticesBinA[3].m_quad;
        if ( v24 == 4 )
        {
          v24 = 3;
LABEL_99:
          v359 = this->m_verticesA[2].m_quad;
          v360 = this->m_verticesA[1].m_quad;
          v361 = this->m_verticesA[0].m_quad;
          v362 = _mm_sub_ps(v359, v360);
          v363 = _mm_sub_ps(v360, v361);
          v364 = _mm_sub_ps(this->m_verticesBinA[0].m_quad, v360);
          v365 = _mm_sub_ps(v361, v359);
          v366 = _mm_shuffle_ps(v362, v362, 201);
          v367 = _mm_sub_ps(this->m_verticesBinA[0].m_quad, v359);
          v368 = _mm_sub_ps(this->m_verticesBinA[0].m_quad, v361);
          v369 = _mm_shuffle_ps(v365, v365, 201);
          v370 = _mm_mul_ps(v369, v367);
          v371 = _mm_sub_ps(_mm_mul_ps(v369, v362), _mm_mul_ps(v366, v365));
          v372 = _mm_shuffle_ps(v371, v371, 201);
          v373 = _mm_sub_ps(_mm_mul_ps(v366, v364), _mm_mul_ps(_mm_shuffle_ps(v364, v364, 201), v362));
          v374 = _mm_sub_ps(v370, _mm_mul_ps(_mm_shuffle_ps(v367, v367, 201), v365));
          v375 = _mm_mul_ps(_mm_shuffle_ps(v373, v373, 201), v372);
          v376 = _mm_mul_ps(_mm_shuffle_ps(v374, v374, 201), v372);
          v377 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v363, v363, 201), v368),
                   _mm_mul_ps(_mm_shuffle_ps(v368, v368, 201), v363));
          v378 = _mm_unpacklo_ps(v375, v376);
          v379 = _mm_mul_ps(_mm_shuffle_ps(v377, v377, 201), v372);
          v380 = _mm_movelh_ps(v378, v379);
          v381.m_quad = _mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v375, v376), v379, 228),
                          _mm_add_ps(v380, _mm_shuffle_ps(_mm_movehl_ps(v380, v378), v379, 212)));
          v382 = _mm_movemask_ps(_mm_cmplt_ps(v381.m_quad, v16)) & 7;
          if ( v382 == 7 )
          {
            v383 = _mm_mul_ps(_mm_sub_ps(v361, this->m_verticesBinA[0].m_quad), v372);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v383, v383, 85), _mm_shuffle_ps(v383, v383, 0)),
                     _mm_shuffle_ps(v383, v383, 170))) )
            {
              v384.m_quad = (__m128)this->m_verticesA[0];
              v372 = _mm_xor_ps(v372, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              this->m_verticesA[0] = this->m_verticesA[1];
              this->m_verticesA[1] = (hkcdVertex)v384.m_quad;
              v381.m_quad = _mm_shuffle_ps(v381.m_quad, v381.m_quad, 225);
            }
          }
          *p_m_support = (hkVector4f)v372;
          this->m_checkTriangleDots = (hkVector4f)v381.m_quad;
          if ( v382 == 7 )
            goto LABEL_132;
          v385 = hkcdGskBase::maskToIndex[v382];
          if ( (int)v385 >= 0 )
          {
            v414 = hkcdGskBase::vertexToEdgeLut[v385];
            v415 = hkcdGskBase::vertexToEdgeLut[v385 + 2];
            v416 = this->m_verticesA[v385].m_quad;
            v417 = _mm_sub_ps(this->m_verticesBinA[0].m_quad, v416);
            v418 = _mm_sub_ps(this->m_verticesA[v415].m_quad, v416);
            v419 = _mm_mul_ps(_mm_sub_ps(this->m_verticesA[v414].m_quad, v416), v417);
            v420.m_quad = (__m128)this->m_verticesA[2];
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v419, v419, 85), _mm_shuffle_ps(v419, v419, 0)),
                      _mm_shuffle_ps(v419, v419, 170))) )
            {
              this->m_verticesA[v415] = (hkcdVertex)v420.m_quad;
              goto LABEL_120;
            }
            v421 = _mm_mul_ps(v418, v417);
            this->m_verticesA[v414] = (hkcdVertex)v420.m_quad;
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v421, v421, 85), _mm_shuffle_ps(v421, v421, 0)),
                      _mm_shuffle_ps(v421, v421, 170))) )
              goto LABEL_120;
            v24 = 1;
            if ( (_DWORD)v415 == 2 )
              LODWORD(v415) = v414;
            this->m_verticesA[(int)v415] = this->m_verticesA[1];
            p_m_support->m_quad = _mm_sub_ps(this->m_verticesA[0].m_quad, this->m_verticesBinA[0].m_quad);
            goto LABEL_132;
          }
          v386 = v385 + 8;
          if ( v386 < 3 )
          {
            this->m_verticesA[v386] = this->m_verticesA[2];
            goto LABEL_120;
          }
        }
        else
        {
          v25 = 3;
LABEL_107:
          v387 = this->m_verticesBinA[1].m_quad;
          v388 = this->m_verticesBinA[2].m_quad;
          v389 = this->m_verticesBinA[0].m_quad;
          v390 = this->m_verticesA[0].m_quad;
          v391 = _mm_sub_ps(v388, v387);
          v392 = _mm_sub_ps(v389, v388);
          v393 = _mm_sub_ps(v390, v387);
          v394 = _mm_sub_ps(v390, v388);
          v395 = _mm_sub_ps(v387, v389);
          v396 = _mm_shuffle_ps(v391, v391, 201);
          v397 = _mm_shuffle_ps(v392, v392, 201);
          v398 = _mm_sub_ps(v390, v389);
          v399 = _mm_sub_ps(_mm_mul_ps(v391, v397), _mm_mul_ps(v392, v396));
          v400 = _mm_shuffle_ps(v399, v399, 201);
          v401 = _mm_sub_ps(_mm_mul_ps(v393, v396), _mm_mul_ps(_mm_shuffle_ps(v393, v393, 201), v391));
          v402 = _mm_sub_ps(_mm_mul_ps(v394, v397), _mm_mul_ps(_mm_shuffle_ps(v394, v394, 201), v392));
          v403 = _mm_mul_ps(_mm_shuffle_ps(v401, v401, 201), v400);
          v404 = _mm_mul_ps(_mm_shuffle_ps(v402, v402, 201), v400);
          v405 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v395, v395, 201), v398),
                   _mm_mul_ps(_mm_shuffle_ps(v398, v398, 201), v395));
          v406 = _mm_unpacklo_ps(v403, v404);
          v407 = _mm_mul_ps(_mm_shuffle_ps(v405, v405, 201), v400);
          v408 = _mm_movelh_ps(v406, v407);
          v409.m_quad = _mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v403, v404), v407, 228),
                          _mm_add_ps(v408, _mm_shuffle_ps(_mm_movehl_ps(v408, v406), v407, 212)));
          v410 = _mm_movemask_ps(_mm_cmplt_ps(v409.m_quad, v16)) & 7;
          if ( v410 == 7 )
          {
            v411 = _mm_mul_ps(v400, v398);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v411, v411, 85), _mm_shuffle_ps(v411, v411, 0)),
                     _mm_shuffle_ps(v411, v411, 170))) )
            {
              v409.m_quad = _mm_shuffle_ps(v409.m_quad, v409.m_quad, 225);
              v400 = _mm_xor_ps(v400, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              this->m_verticesBinA[0] = this->m_verticesBinA[1];
              this->m_verticesBinA[1].m_quad = v389;
            }
          }
          *p_m_support = (hkVector4f)v400;
          this->m_checkTriangleDots = (hkVector4f)v409.m_quad;
          if ( v410 == 7 )
            goto LABEL_132;
          v412 = hkcdGskBase::maskToIndex[v410];
          if ( (int)v412 >= 0 )
          {
            v441 = hkcdGskBase::vertexToEdgeLut[v412];
            v442 = hkcdGskBase::vertexToEdgeLut[v412 + 2];
            v443 = this->m_verticesBinA[v412].m_quad;
            v444 = _mm_sub_ps(this->m_verticesA[0].m_quad, v443);
            v445 = _mm_sub_ps(this->m_verticesBinA[v442].m_quad, v443);
            v446 = _mm_mul_ps(_mm_sub_ps(this->m_verticesBinA[v441].m_quad, v443), v444);
            v447.m_quad = (__m128)this->m_verticesBinA[2];
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v446, v446, 85), _mm_shuffle_ps(v446, v446, 0)),
                      _mm_shuffle_ps(v446, v446, 170))) )
            {
              this->m_verticesBinA[v442] = (hkcdVertex)v447.m_quad;
              goto LABEL_76;
            }
            v448 = _mm_mul_ps(v444, v445);
            this->m_verticesBinA[v441] = (hkcdVertex)v447.m_quad;
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v448, v448, 85), _mm_shuffle_ps(v448, v448, 0)),
                      _mm_shuffle_ps(v448, v448, 170))) )
              goto LABEL_76;
            v25 = 1;
            if ( (_DWORD)v442 == 2 )
              LODWORD(v442) = v441;
            this->m_verticesBinA[(int)v442] = this->m_verticesBinA[1];
            p_m_support->m_quad = _mm_sub_ps(this->m_verticesA[0].m_quad, this->m_verticesBinA[0].m_quad);
            goto LABEL_132;
          }
          v413 = v412 + 8;
          if ( v413 < 3 )
          {
            this->m_verticesBinA[v413] = this->m_verticesBinA[2];
            goto LABEL_76;
          }
        }
        v24 = 1;
        v25 = 1;
LABEL_130:
        p_m_support->m_quad = _mm_sub_ps(this->m_verticesA[0].m_quad, this->m_verticesBinA[0].m_quad);
        goto LABEL_132;
      default:
        goto LABEL_65;
    }
  }
}to LABEL_132;
      default:
        goto LABEL_65;
    }
  }
}

