// File Line: 1111
// RVA: 0x1317F50
void __fastcall hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>::getSupportingVertices(hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *this, const void *shapeA, hkVector4f *directionA, const void *shapeB, hkTransformf *aTb, hkcdVertex *vertexAinAOut, hkcdVertex *vertexBinBOut, hkVector4f *vertexBinAout)
{
  *vertexBinBOut = 0i64;
  *vertexBinAout = 0i64;
  hkcdGsk_Vector4Shape::getSupportingVertex((hkcdGsk_Vector4Shape *)shapeA, directionA, vertexAinAOut);
}

// File Line: 1145
// RVA: 0x1313D30
_BOOL8 __fastcall hkcdGskBase::castRay<hkcdGsk_Vector4Shape>(hkcdGskBase *this, hkcdGsk_Vector4Shape *shape, hkcdGsk::RayCastInput *input, hkSimdFloat32 *fractionInOut)
{
  hkcdGsk::RayCastInput *v4; // rbx
  hkBool result; // [rsp+50h] [rbp-E8h]
  hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> shapeInterface; // [rsp+58h] [rbp-E0h]
  hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> > v8; // [rsp+70h] [rbp-C8h]

  v4 = input;
  shapeInterface.vfptr = (hkcdGskBase::ShapeInterfaceVtbl *)&hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>::`vftable;
  *(_DWORD *)shapeInterface.m_vertexIds = 0;
  shapeInterface.m_dimAb = 65;
  return hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>>::linearCast<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>>(
           &v8,
           &result,
           &shapeInterface,
           this,
           0i64,
           (hkcdGsk::LinearCastInput *)shape,
           &shapeInterface,
           (hkSimdFloat32 *)input,
           (hkVector4f *)fractionInOut)->m_bool
      && COERCE_FLOAT(*(_OWORD *)&v4->m_from) != 0.0;
}

// File Line: 1165
// RVA: 0x1313DC0
hkBool *__usercall hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>>::linearCast<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape>>@<rax>(hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> > *this@<rcx>, hkBool *result@<rdx>, hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *shapeInterface@<r8>, const void *shapeA@<r9>, __int64 a5@<rbx>, const void *shapeB, hkcdGsk::LinearCastInput *input, hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *cache, hkSimdFloat32 *fractionInOut, hkVector4f *normalOut)
{
  __m128 *v10; // r13
  const void *v11; // r11
  hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *v12; // r10
  hkBool *v13; // r12
  hkcdGskImpl<hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> > *v14; // rsi
  __m128 v15; // xmm5
  __m128 v16; // xmm14
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm4
  __m128 v21; // xmm8
  hkBool *v22; // rax
  __m128 *v23; // r15
  signed int v24; // ebx
  signed int v25; // edi
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
  signed int v36; // edx
  __m128 v37; // xmm1
  __m128 *v38; // rcx
  signed __int64 v39; // rax
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  unsigned int v46; // eax
  __m128 *v47; // rdx
  __m128 *v48; // rcx
  __m128 v49; // xmm11
  __m128 v50; // xmm0
  __m128 v51; // xmm13
  __m128 v52; // xmm5
  __m128 v53; // xmm6
  __m128 v54; // xmm1
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm4
  __m128 v60; // xmm10
  __m128 v61; // xmm3
  __m128 v62; // xmm1
  __m128 v63; // xmm0
  __m128 v64; // xmm7
  __m128 v65; // xmm1
  __m128 v66; // xmm3
  __m128 v67; // xmm0
  __m128 v68; // xmm7
  __m128 v69; // xmm4
  __m128 v70; // xmm1
  __m128 v71; // xmm6
  __m128 v72; // xmm5
  __m128 v73; // xmm5
  __m128 v74; // xmm1
  __m128 v75; // xmm3
  __m128 v76; // xmm0
  __m128 v77; // xmm2
  __m128 v78; // xmm7
  __m128 v79; // xmm1
  __m128 v80; // xmm3
  __m128 v81; // xmm1
  __m128 v82; // xmm7
  __m128 v83; // xmm2
  signed int v84; // ecx
  __m128 v85; // xmm3
  __m128 v86; // xmm2
  __m128 v87; // xmm10
  __m128 v88; // xmm4
  __m128 v89; // xmm7
  __m128 v90; // xmm10
  __m128 v91; // xmm8
  __m128 v92; // xmm5
  __m128 v93; // xmm1
  __m128 v94; // xmm2
  __m128 v95; // xmm6
  __m128 v96; // xmm3
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
  __m128 v107; // xmm8
  int v108; // er8
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
  __m128 v127; // xmm2
  __m128 v128; // xmm0
  __m128 v129; // xmm8
  __m128 v130; // xmm7
  __m128 v131; // xmm0
  __m128 v132; // xmm3
  __m128 v133; // xmm0
  __m128 v134; // xmm4
  __m128 v135; // xmm3
  __m128 v136; // xmm1
  __m128 v137; // xmm3
  __m128 v138; // xmm10
  __m128 v139; // xmm3
  __m128 v140; // xmm4
  __m128 v141; // xmm1
  __m128 v142; // xmm2
  __m128 v143; // xmm1
  __m128 v144; // xmm2
  __m128 v145; // xmm10
  __m128 v146; // xmm9
  __m128 v147; // xmm1
  __m128 v148; // xmm4
  __m128 v149; // xmm8
  __m128 v150; // xmm1
  __m128 v151; // xmm7
  __m128 v152; // xmm5
  __m128 v153; // xmm1
  __m128 v154; // xmm3
  __m128 v155; // xmm1
  __m128 v156; // xmm4
  __m128 v157; // xmm1
  __m128 v158; // xmm2
  __m128 v159; // xmm6
  __m128 v160; // xmm1
  __m128 v161; // xmm3
  __m128 v162; // xmm1
  __m128 v163; // xmm0
  __m128 v164; // xmm1
  __m128 v165; // xmm3
  __m128 v166; // xmm4
  __m128 v167; // xmm9
  __m128 v168; // xmm1
  __m128 v169; // xmm2
  __m128 v170; // xmm2
  __m128 v171; // xmm1
  __m128 v172; // xmm12
  __m128 v173; // xmm11
  __m128 v174; // xmm10
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
  __m128 v189; // xmm3
  __m128 v190; // xmm0
  __m128 v191; // xmm2
  __m128 v192; // xmm7
  __m128 v193; // xmm1
  __m128 v194; // xmm3
  __m128 v195; // xmm1
  __m128 v196; // xmm7
  __m128 v197; // xmm2
  __m128 v198; // xmm2
  __m128 v199; // xmm3
  __m128 v200; // xmm1
  __m128 v201; // xmm4
  __m128 v202; // xmm5
  __m128 v203; // xmm8
  __m128 v204; // xmm9
  __m128 v205; // xmm7
  __m128 v206; // xmm2
  __m128 v207; // xmm11
  __m128 v208; // xmm6
  __m128 v209; // xmm6
  __m128 v210; // xmm9
  __m128 v211; // xmm7
  __m128 v212; // xmm9
  __m128 v213; // xmm7
  __m128 v214; // xmm8
  __m128 v215; // xmm1
  __m128 v216; // xmm8
  __m128 v217; // xmm2
  __m128 v218; // xmm9
  int v219; // eax
  float v220; // xmm1_4
  float v221; // xmm10_4
  float v222; // xmm1_4
  float v223; // xmm10_4
  int v224; // ecx
  __m128 v225; // xmm15
  __m128 v226; // xmm12
  __m128 v227; // xmm10
  __m128 v228; // xmm13
  __m128 v229; // xmm9
  __m128 v230; // xmm8
  __m128 v231; // xmm6
  __m128 v232; // xmm3
  __m128 v233; // xmm1
  __m128 v234; // xmm2
  __m128 v235; // xmm5
  __m128 v236; // xmm5
  __m128 v237; // xmm4
  __m128 v238; // xmm5
  __m128 v239; // xmm5
  __m128 v240; // xmm4
  __m128 v241; // xmm0
  __m128 v242; // xmm7
  __m128 v243; // xmm3
  __m128 v244; // xmm6
  __m128 v245; // xmm2
  __m128 v246; // xmm1
  __m128 v247; // xmm7
  int v248; // ecx
  int v249; // ecx
  int v250; // ecx
  int v251; // ecx
  __m128 v252; // xmm12
  __m128 v253; // xmm1
  __m128 v254; // xmm11
  __m128 v255; // xmm1
  __m128 v256; // xmm12
  __m128 v257; // xmm8
  __m128 v258; // xmm10
  __m128 v259; // xmm1
  __m128 v260; // xmm9
  __m128 v261; // xmm1
  __m128 v262; // xmm3
  __m128 v263; // xmm1
  __m128 v264; // xmm5
  __m128 v265; // xmm1
  __m128 v266; // xmm7
  __m128 v267; // xmm0
  __m128 v268; // xmm2
  __m128 v269; // xmm3
  __m128 v270; // xmm1
  __m128 v271; // xmm3
  __m128 v272; // xmm2
  __m128 v273; // xmm1
  __m128 v274; // xmm2
  int v275; // eax
  float v276; // xmm1_4
  float v277; // xmm10_4
  __m128 v278; // xmm6
  __m128 v279; // xmm1
  __m128 v280; // xmm8
  __m128 v281; // xmm4
  __m128 v282; // xmm9
  __m128 v283; // xmm6
  __m128 v284; // xmm7
  __m128 v285; // xmm5
  __m128 v286; // xmm1
  __m128 v287; // xmm2
  __m128 v288; // xmm1
  __m128 v289; // xmm3
  __m128 v290; // xmm5
  __m128 v291; // xmm1
  __m128 v292; // xmm3
  __m128 v293; // xmm2
  __m128 v294; // xmm2
  __m128 v295; // xmm1
  __m128 v296; // xmm1
  __m128 v297; // xmm3
  __m128 v298; // xmm7
  __m128 v299; // xmm2
  __m128 v300; // xmm2
  __m128 v301; // xmm11
  __m128 v302; // xmm10
  __m128 *v303; // r9
  __m128 v304; // xmm1
  __m128 v305; // xmm2
  __m128 v306; // xmm6
  __m128 v307; // xmm4
  __m128 v308; // xmm5
  __m128 v309; // xmm3
  __m128 v310; // xmm0
  __m128 v311; // xmm1
  __m128 v312; // xmm9
  __m128 v313; // xmm3
  __m128 v314; // xmm9
  __m128 v315; // xmm8
  __m128 v316; // xmm8
  __m128 v317; // xmm0
  __m128 v318; // xmm8
  __m128 v319; // xmm4
  __m128 v320; // xmm5
  __m128 v321; // xmm9
  __m128 v322; // xmm4
  __m128 v323; // xmm1
  __m128 v324; // xmm3
  __m128 v325; // xmm2
  __m128 v326; // xmm4
  __m128i v327; // xmm5
  __m128 v328; // xmm1
  __m128 v329; // xmm2
  __m128 v330; // xmm9
  __m128 v331; // xmm3
  __m128 v332; // xmm1
  __m128 v333; // xmm4
  __m128 v334; // xmm6
  signed int v335; // edx
  __m128 v336; // xmm2
  signed int v337; // eax
  signed int v338; // ecx
  signed int v339; // er13
  signed __int64 v340; // r10
  signed __int64 v341; // r15
  __int64 v342; // r8
  signed __int64 v343; // r12
  int v344; // edx
  __m128 v345; // xmm0
  __m128 v346; // xmm2
  __m128 v347; // xmm4
  __m128 v348; // xmm7
  __m128 v349; // xmm5
  __m128 v350; // xmm1
  __m128 v351; // xmm3
  __m128 v352; // xmm4
  __m128 v353; // xmm7
  __m128 v354; // xmm3
  __m128 v355; // xmm2
  __m128 v356; // xmm9
  __m128 v357; // xmm4
  __m128 v358; // xmm7
  __m128 v359; // xmm1
  __m128 v360; // xmm5
  __m128 v361; // xmm8
  __m128 v362; // xmm2
  __m128 v363; // xmm6
  __m128 v364; // xmm3
  __m128 v365; // xmm10
  __m128 v366; // xmm10
  __m128 v367; // xmm8
  __m128 v368; // xmm6
  __m128 v369; // xmm8
  __m128 v370; // xmm6
  __m128 v371; // xmm7
  __m128 v372; // xmm1
  __m128 v373; // xmm7
  __m128 v374; // xmm2
  __m128 v375; // xmm8
  int v376; // ecx
  __m128 v377; // xmm9
  hkcdVertex v378; // xmm1
  __int64 v379; // rcx
  signed int v380; // ecx
  __m128 v381; // xmm1
  __m128 v382; // xmm4
  __m128 v383; // xmm3
  __m128 v384; // xmm12
  __m128 v385; // xmm5
  __m128 v386; // xmm7
  __m128 v387; // xmm10
  __m128 v388; // xmm8
  __m128 v389; // xmm9
  __m128 v390; // xmm2
  __m128 v391; // xmm6
  __m128 v392; // xmm12
  __m128 v393; // xmm11
  __m128 v394; // xmm11
  __m128 v395; // xmm10
  __m128 v396; // xmm8
  __m128 v397; // xmm10
  __m128 v398; // xmm8
  __m128 v399; // xmm9
  __m128 v400; // xmm1
  __m128 v401; // xmm9
  __m128 v402; // xmm2
  __m128 v403; // xmm10
  int v404; // ecx
  __m128 v405; // xmm2
  __int64 v406; // rcx
  signed int v407; // ecx
  __int64 v408; // r9
  __int64 v409; // r8
  __m128 v410; // xmm0
  __m128 v411; // xmm4
  __m128 v412; // xmm3
  __m128 v413; // xmm2
  hkcdVertex v414; // xmm0
  __m128 v415; // xmm3
  __m128 v416; // xmm4
  __m128 v417; // xmm9
  __m128 v418; // xmm8
  __m128 v419; // xmm6
  __m128 v420; // xmm7
  __m128 v421; // xmm5
  __m128 v422; // xmm1
  __m128 v423; // xmm2
  __m128 v424; // xmm1
  __m128 v425; // xmm3
  __m128 v426; // xmm5
  __m128 v427; // xmm1
  __m128 v428; // xmm2
  __m128 v429; // xmm3
  __m128 v430; // xmm3
  __m128 v431; // xmm3
  __m128 v432; // xmm3
  __m128 v433; // xmm2
  __m128 v434; // xmm2
  __int64 v435; // r9
  __int64 v436; // r8
  __m128 v437; // xmm0
  __m128 v438; // xmm3
  __m128 v439; // xmm4
  __m128 v440; // xmm2
  hkcdVertex v441; // xmm0
  __m128 v442; // xmm3
  __m128 v443; // xmm2
  __m128 v444; // xmm2
  __m128 v445; // xmm6
  __m128 v446; // xmm7
  __m128 v447; // xmm1
  __m128 v448; // xmm3
  __m128 v449; // xmm1
  signed __int64 v450; // rax
  __int64 v451; // rcx
  __m128 v452; // xmm1
  __m128 v453; // xmm2
  __m128 v454; // xmm2
  float v455; // xmm0_4
  __int64 v456; // [rsp+40h] [rbp-A0h]
  __m128 v457; // [rsp+50h] [rbp-90h]
  __m128 v458; // [rsp+60h] [rbp-80h]
  __m128 v459; // [rsp+70h] [rbp-70h]
  __m128 v460; // [rsp+80h] [rbp-60h]
  __m128 v461; // [rsp+90h] [rbp-50h]
  __m128 v462; // [rsp+A0h] [rbp-40h]
  __m128 v463; // [rsp+B0h] [rbp-30h]
  __m128 v464; // [rsp+C0h] [rbp-20h]
  __m128 v465; // [rsp+D0h] [rbp-10h]
  __m128 v466; // [rsp+E0h] [rbp+0h]
  __m128 v467; // [rsp+F0h] [rbp+10h]
  __m128 v468; // [rsp+100h] [rbp+20h]
  __m128 v469; // [rsp+110h] [rbp+30h]
  __m128 v470; // [rsp+120h] [rbp+40h]
  __m128 v471; // [rsp+130h] [rbp+50h]
  __m128 v472; // [rsp+140h] [rbp+60h]
  __m128 v473; // [rsp+150h] [rbp+70h]
  __m128 v474; // [rsp+160h] [rbp+80h]
  __m128 v475; // [rsp+170h] [rbp+90h]
  __m128 v476; // [rsp+180h] [rbp+A0h]
  __m128 v477; // [rsp+190h] [rbp+B0h]
  __m128 v478; // [rsp+1A0h] [rbp+C0h]
  __m128 v479; // [rsp+1B0h] [rbp+D0h]
  __m128 v480; // [rsp+1C0h] [rbp+E0h]
  __m128 v481; // [rsp+1D0h] [rbp+F0h]
  __m128 v482; // [rsp+1E0h] [rbp+100h]
  __m128 v483; // [rsp+1F0h] [rbp+110h]
  __m128 v484; // [rsp+200h] [rbp+120h]
  __m128 v485; // [rsp+210h] [rbp+130h]
  __m128 v486; // [rsp+220h] [rbp+140h]
  __m128 v487; // [rsp+230h] [rbp+150h]
  __m128 v488; // [rsp+240h] [rbp+160h]
  __m128 v489; // [rsp+250h] [rbp+170h]
  __m128 v490; // [rsp+260h] [rbp+180h]
  __m128 v491; // [rsp+270h] [rbp+190h]
  __m128 v492; // [rsp+280h] [rbp+1A0h]
  char v493; // [rsp+290h] [rbp+1B0h]
  __m128 v494; // [rsp+2A0h] [rbp+1C0h]
  __m128 v495; // [rsp+2B0h] [rbp+1D0h]
  __m128 v496; // [rsp+2C0h] [rbp+1E0h]
  __m128 v497; // [rsp+2D0h] [rbp+1F0h]
  __m128 v498; // [rsp+2E0h] [rbp+200h]
  __m128 v499; // [rsp+2F0h] [rbp+210h]
  __m128 v500; // [rsp+300h] [rbp+220h]
  __m128 v501; // [rsp+310h] [rbp+230h]
  __m128 v502; // [rsp+320h] [rbp+240h]
  __m128 v503; // [rsp+330h] [rbp+250h]
  __m128 v504; // [rsp+340h] [rbp+260h]
  __m128 v505; // [rsp+350h] [rbp+270h]
  __m128 v506; // [rsp+360h] [rbp+280h]
  __m128 v507; // [rsp+370h] [rbp+290h]
  __m128 v508; // [rsp+380h] [rbp+2A0h]
  hkBool *v509; // [rsp+478h] [rbp+398h]
  hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *vars0; // [rsp+480h] [rbp+3A0h]
  void *retaddr; // [rsp+488h] [rbp+3A8h]
  __int64 v512; // [rsp+490h] [rbp+3B0h]
  hkBool *v513; // [rsp+498h] [rbp+3B8h]
  float *v514; // [rsp+4A8h] [rbp+3C8h]

  v514 = (float *)shapeA;
  v513 = result;
  v10 = (__m128 *)result;
  v11 = shapeA;
  v12 = shapeInterface;
  v13 = result;
  v14 = this;
  v15 = *(__m128 *)&result[16].m_bool;
  v467 = *(__m128 *)_xmm;
  v16 = 0i64;
  v468 = (__m128)_xmm;
  v17 = _mm_mul_ps(v15, v15);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v501 = v18;
  v20 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v18), (__m128)0i64);
  v21 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v18, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                  _mm_mul_ps(v19, *(__m128 *)_xmm))),
              v15),
            v20),
          _mm_andnot_ps(v20, v15));
  if ( !_mm_movemask_ps(v20) )
  {
    result->m_bool = 0;
    return result;
  }
  v512 = a5;
  v459 = 0i64;
  v458 = 0i64;
  v23 = &this->m_support.m_quad;
  v24 = 0;
  HIDWORD(v456) = 0;
  v25 = 1;
  v26 = *(__m128 *)&result[96].m_bool;
  v27 = *(__m128 *)&result->m_bool;
  v28 = 0i64;
  LOBYTE(v456) = 0;
  v29 = _mm_shuffle_ps(v26, v26, 0);
  v30.m_quad = _mm_sub_ps(*(__m128 *)&result->m_bool, *(__m128 *)*(_QWORD *)shapeA);
  this->m_verticesA[0] = *(hkcdVertex *)*(_QWORD *)shapeA;
  this->m_support = (hkVector4f)v30.m_quad;
  v31 = _mm_mul_ps(v30.m_quad, v30.m_quad);
  v474 = v29;
  v472 = _mm_shuffle_ps(v26, v26, 85);
  v32 = 0i64;
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v457 = v27;
  v460 = 0i64;
  v34 = _mm_rsqrt_ps(v33);
  v477 = v33;
  v459.m128_f32[1] = FLOAT_1_0e7;
  v464 = (__m128)xmmword_141A712D0;
  v35 = _mm_mul_ps(
          v30.m_quad,
          _mm_andnot_ps(
            _mm_cmpleps(v33, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(v34, *(__m128 *)_xmm))));
  v461 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0e7), (__m128)LODWORD(FLOAT_1_0e7), 0);
  if ( (float)(v461.m128_f32[0] * v461.m128_f32[0]) <= v472.m128_f32[0] )
    goto $returnTrue;
LABEL_4:
  ((void (__fastcall *)(hkcdGskBase::RayCastShapeInterface<hkcdGsk_Vector4Shape> *, const void *, __m128 *, __int64, __m128 *, __m128 *, char *, __m128 *, __int64))v12->vfptr->getSupportingVertices)(
    v12,
    v11,
    v23,
    v512,
    &v10[2],
    &v460,
    &v493,
    &v473,
    v456);
  v36 = 0;
  v37 = _mm_sub_ps(v460, v473);
  v460 = v37;
  if ( v24 <= 0 )
  {
LABEL_8:
    v39 = v24++ + 2i64;
    *(&v14->m_checkTriangleDots.m_quad + v39) = v37;
    v37 = v460;
  }
  else
  {
    v38 = (__m128 *)v14->m_verticesA;
    while ( (_mm_movemask_ps(_mm_cmpeqps(v37, *v38)) & 7) != 7 )
    {
      ++v36;
      ++v38;
      if ( v36 >= v24 )
        goto LABEL_8;
    }
  }
  v40 = _mm_mul_ps(_mm_sub_ps(v27, _mm_add_ps(_mm_mul_ps(v35, v29), v37)), *v23);
  v41 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)), _mm_shuffle_ps(v40, v40, 170));
  if ( v41.m128_f32[0] > v16.m128_f32[0] )
  {
    v42 = _mm_mul_ps(*v23, v10[1]);
    v43 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
            _mm_shuffle_ps(v42, v42, 170));
    v479 = v43;
    if ( v43.m128_f32[0] >= v16.m128_f32[0]
      || (v44 = _mm_rcp_ps(v43),
          v45 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v43)), v44), v41),
          v28 = _mm_sub_ps(v28, v45),
          v475 = v45,
          v459 = v28,
          v28.m128_f32[0] >= 1.0) )
    {
      v22 = v509;
      v509->m_bool = 0;
      return v22;
    }
    v458 = v35;
    v27 = _mm_add_ps(*v10, _mm_mul_ps(v28, v10[1]));
    v457 = v27;
  }
  v470 = *v23;
  v14->m_verticesBinA[0].m_quad = v27;
  v46 = (v25 | 8 * v24) - 9;
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
        v301 = query.m_quad;
        v302 = v14->m_verticesA[0].m_quad;
        v303 = (__m128 *)v14->m_verticesBinA;
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
        v47 = (__m128 *)v14->m_verticesA;
        v48 = (__m128 *)v14->m_verticesBinA;
        goto LABEL_17;
      case 0x10u:
        goto LABEL_99;
      case 0x11u:
        v47 = (__m128 *)v14->m_verticesBinA;
        v48 = (__m128 *)v14->m_verticesA;
LABEL_17:
        if ( v14->m_lastDimB.m_storage == 2 )
        {
          v49 = *v48;
          v50 = v48[2];
          v51 = _mm_sub_ps(v48[1], v50);
          v52 = *v47;
          v53 = v47[1];
          v54 = _mm_sub_ps(*v48, v50);
          v465 = v54;
          v462 = v51;
          v55 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v51),
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v54));
          v56 = _mm_shuffle_ps(v55, v55, 201);
          v57 = _mm_mul_ps(_mm_sub_ps(v53, v49), v56);
          v58 = _mm_mul_ps(_mm_sub_ps(v52, v49), v56);
          v59 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                  _mm_shuffle_ps(v58, v58, 170));
          v60 = _mm_mul_ps(v59, v59);
          v61 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                  _mm_shuffle_ps(v57, v57, 170));
          v62 = _mm_mul_ps(v61, v61);
          if ( _mm_movemask_ps(_mm_mul_ps(v59, v61)) )
          {
            v481 = _mm_sub_ps(v59, v61);
            v63 = _mm_rcp_ps(v481);
            v495 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v481, v63)), v63), v59);
            v64 = v48[1];
            v65 = v64;
            v66 = _mm_add_ps(*v47, _mm_mul_ps(_mm_sub_ps(v47[1], *v47), v495));
            v67 = _mm_sub_ps(v48[2], *v48);
            v68 = _mm_sub_ps(v64, v66);
            v69 = _mm_sub_ps(v48[2], v66);
            v70 = _mm_sub_ps(v65, *v48);
            v71 = _mm_sub_ps(*v48, v66);
            v72 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v70),
                    _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v67));
            v73 = _mm_shuffle_ps(v72, v72, 201);
            v74 = _mm_shuffle_ps(v73, v73, 210);
            v75 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v74),
                      _mm_mul_ps(_mm_shuffle_ps(v69, v69, 210), v73)),
                    v68);
            v76 = _mm_shuffle_ps(v68, v68, 210);
            v77 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v74),
                      _mm_mul_ps(_mm_shuffle_ps(v71, v71, 210), v73)),
                    v69);
            v78 = _mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v74);
            v79 = v75;
            v80 = _mm_unpackhi_ps(v75, v77);
            v81 = _mm_unpacklo_ps(v79, v77);
            v82 = _mm_mul_ps(_mm_sub_ps(v78, _mm_mul_ps(v76, v73)), v71);
            v83 = _mm_movelh_ps(v81, v82);
            if ( (_mm_movemask_ps(
                    _mm_cmpltps(
                      v16,
                      _mm_add_ps(
                        _mm_shuffle_ps(v80, v82, 228),
                        _mm_add_ps(v83, _mm_shuffle_ps(_mm_movehl_ps(v83, v81), v82, 212))))) & 7) == 7 )
            {
              v84 = 1;
              goto LABEL_42;
            }
          }
          else
          {
            v85 = v48[2];
            v86 = v48[1];
            v87 = _mm_cmpltps(v60, v62);
            v88 = _mm_sub_ps(v48[2], v86);
            v89 = _mm_sub_ps(v86, v49);
            v90 = _mm_or_ps(_mm_and_ps(v87, v52), _mm_andnot_ps(v87, v53));
            v91 = _mm_shuffle_ps(v88, v88, 201);
            v92 = _mm_sub_ps(v49, v85);
            v93 = _mm_sub_ps(v90, v86);
            v94 = _mm_sub_ps(v90, v85);
            v95 = _mm_shuffle_ps(v92, v92, 201);
            v96 = _mm_sub_ps(v90, v49);
            v97 = _mm_sub_ps(_mm_mul_ps(v95, v88), _mm_mul_ps(v91, v92));
            v98 = _mm_shuffle_ps(v97, v97, 201);
            v99 = _mm_sub_ps(_mm_mul_ps(v91, v93), _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v88));
            v100 = _mm_sub_ps(_mm_mul_ps(v95, v94), _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v92));
            v101 = _mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), v98);
            v102 = _mm_mul_ps(_mm_shuffle_ps(v100, v100, 201), v98);
            v103 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v96),
                     _mm_mul_ps(_mm_shuffle_ps(v96, v96, 201), v89));
            v104 = _mm_unpacklo_ps(v101, v102);
            v105 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 201), v98);
            v106 = _mm_movelh_ps(v104, v105);
            v107 = _mm_add_ps(
                     _mm_shuffle_ps(_mm_unpackhi_ps(v101, v102), v105, 228),
                     _mm_add_ps(v106, _mm_shuffle_ps(_mm_movehl_ps(v106, v104), v105, 212)));
            v108 = _mm_movemask_ps(_mm_cmpltps(v107, v16)) & 7;
            if ( v108 == 7 )
            {
              v109 = _mm_mul_ps(_mm_sub_ps(v14->m_verticesA[0].m_quad, v14->m_verticesBinA[0].m_quad), v98);
              if ( _mm_movemask_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                       _mm_shuffle_ps(v109, v109, 170))) )
              {
                v110 = *v48;
                v98 = _mm_xor_ps(v98, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
                *v48 = v48[1];
                v48[1] = v110;
                v107 = _mm_shuffle_ps(v107, v107, 225);
              }
            }
            *v23 = v98;
            v14->m_checkTriangleDots.m_quad = v107;
            if ( v108 == 7 )
            {
              v84 = 0;
              *v47 = v90;
              goto LABEL_42;
            }
          }
          v111 = _mm_sub_ps(v47[1], *v47);
          v112 = _mm_sub_ps(v48[2], *v47);
          v113 = _mm_mul_ps(v111, v51);
          v463 = v111;
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
          v483 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                   _mm_shuffle_ps(v115, v115, 170));
          v505 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v120, v120, 85), _mm_shuffle_ps(v120, v120, 0)),
                   _mm_shuffle_ps(v120, v120, 170));
          v121 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v505, v483), _mm_mul_ps(v114, v114)), *(__m128 *)&epsilon);
          v122 = _mm_rcp_ps(v121);
          v485 = v121;
          v123 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v122, v121)), v122);
          v124 = _mm_rcp_ps(v505);
          v497 = v123;
          v125 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v124, v505)), v124);
          v126 = _mm_rcp_ps(v483);
          v487 = v125;
          v503 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v126, v483)), v126);
          v127 = _mm_cmpleps(v121, *(__m128 *)&epsilon);
          v128 = _mm_mul_ps(v119, v114);
          v129 = _mm_mul_ps(v119, v125);
          v130 = _mm_sub_ps(_mm_mul_ps(v505, v118), v128);
          v131 = _mm_cmpltps(v130, v121);
          v132 = _mm_or_ps(
                   _mm_andnot_ps(
                     v127,
                     _mm_mul_ps(
                       _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v131, v130), _mm_andnot_ps(v131, v121))),
                       v123)),
                   _mm_and_ps(v127, query.m_quad));
          v133 = _mm_mul_ps(v114, v125);
          v134 = v48[2];
          v135 = _mm_sub_ps(_mm_mul_ps(v132, v133), v129);
          v136 = _mm_cmpltps(v135, query.m_quad);
          v137 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v136, v135), _mm_andnot_ps(v136, query.m_quad)));
          v138 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v114, v503), v137), _mm_mul_ps(v118, v503));
          v139 = _mm_add_ps(_mm_mul_ps(v137, v462), v134);
          v140 = _mm_sub_ps(v134, *v47);
          v141 = _mm_cmpltps(v138, query.m_quad);
          v142 = _mm_sub_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v141, v138), _mm_andnot_ps(v141, query.m_quad))),
                       v463),
                     *v47),
                   v139);
          v143 = _mm_mul_ps(v463, v465);
          v144 = _mm_mul_ps(v142, v142);
          v145 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v144, v144, 85), _mm_shuffle_ps(v144, v144, 0)),
                   _mm_shuffle_ps(v144, v144, 170));
          v146 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v143, v143, 85), _mm_shuffle_ps(v143, v143, 0)),
                   _mm_shuffle_ps(v143, v143, 170));
          v147 = _mm_mul_ps(v140, v463);
          v148 = _mm_mul_ps(v140, v465);
          v149 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v147, v147, 85), _mm_shuffle_ps(v147, v147, 0)),
                   _mm_shuffle_ps(v147, v147, 170));
          v150 = _mm_mul_ps(v465, v465);
          v151 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v148, v148, 85), _mm_shuffle_ps(v148, v148, 0)),
                   _mm_shuffle_ps(v148, v148, 170));
          v499 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v150, v150, 85), _mm_shuffle_ps(v150, v150, 0)),
                   _mm_shuffle_ps(v150, v150, 170));
          v489 = v483;
          v152 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v499, v483), _mm_mul_ps(v146, v146)), *(__m128 *)&epsilon);
          v153 = _mm_rcp_ps(v152);
          v491 = v152;
          v154 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v153, v152)), v153);
          v155 = _mm_rcp_ps(v499);
          v507 = v154;
          v156 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v155, v499)), v155);
          v157 = _mm_rcp_ps(v483);
          v476 = v156;
          v158 = _mm_cmpleps(v152, *(__m128 *)&epsilon);
          v159 = _mm_sub_ps(_mm_mul_ps(v499, v149), _mm_mul_ps(v151, v146));
          v478 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v157, v483)), v157);
          v160 = _mm_cmpltps(v159, v152);
          v161 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_or_ps(
                       _mm_andnot_ps(
                         v158,
                         _mm_mul_ps(
                           _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v160, v159), _mm_andnot_ps(v160, v152))),
                           v154)),
                       _mm_and_ps(v158, query.m_quad)),
                     _mm_mul_ps(v146, v156)),
                   _mm_mul_ps(v151, v156));
          v162 = _mm_cmpltps(v161, query.m_quad);
          v163 = v162;
          v164 = _mm_and_ps(v162, v161);
          v165 = v48[2];
          v16 = 0i64;
          v166 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v163, query.m_quad), v164));
          v167 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v146, v478), v166), _mm_mul_ps(v149, v478));
          v168 = _mm_cmpltps(v167, query.m_quad);
          v169 = _mm_sub_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v168, query.m_quad), _mm_and_ps(v168, v167))),
                       v463),
                     *v47),
                   _mm_add_ps(_mm_mul_ps(v166, v465), v165));
          v170 = _mm_mul_ps(v169, v169);
          v171 = _mm_cmpltps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v170, v170, 85), _mm_shuffle_ps(v170, v170, 0)),
                     _mm_shuffle_ps(v170, v170, 170)),
                   v145);
          *v48 = _mm_or_ps(_mm_and_ps(v171, *v48), _mm_andnot_ps(v171, v48[1]));
          v48[1] = v165;
        }
        else
        {
          v172 = *v48;
          v173 = v47[1];
          v174 = v14->m_checkTriangleDots.m_quad;
          v175 = _mm_mul_ps(*v23, _mm_sub_ps(*v47, *v48));
          v176 = _mm_mul_ps(*v23, _mm_sub_ps(v47[1], *v48));
          v177 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v175, v175, 85), _mm_shuffle_ps(v175, v175, 0)),
                   _mm_shuffle_ps(v175, v175, 170));
          v178 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v176, v176, 85), _mm_shuffle_ps(v176, v176, 0)),
                   _mm_shuffle_ps(v176, v176, 170));
          if ( (float)(v178.m128_f32[0] * v177.m128_f32[0]) < v16.m128_f32[0] )
          {
            v480 = _mm_sub_ps(v177, v178);
            v179 = _mm_rcp_ps(v480);
            v482 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v480, v179)), v179), v177);
            v172 = *v48;
            v173 = v47[1];
            v180 = _mm_sub_ps(v48[1], *v48);
            v181 = _mm_add_ps(*v47, _mm_mul_ps(_mm_sub_ps(v47[1], *v47), v482));
            v182 = _mm_sub_ps(v48[2], *v48);
            v183 = _mm_sub_ps(v48[1], v181);
            v184 = _mm_sub_ps(*v48, v181);
            v185 = _mm_sub_ps(v48[2], v181);
            v186 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v182, v182, 201), v180),
                     _mm_mul_ps(_mm_shuffle_ps(v180, v180, 201), v182));
            v187 = _mm_shuffle_ps(v186, v186, 201);
            v188 = _mm_shuffle_ps(v187, v187, 210);
            v189 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v185, v185, 201), v188),
                       _mm_mul_ps(_mm_shuffle_ps(v185, v185, 210), v187)),
                     v183);
            v190 = _mm_shuffle_ps(v183, v183, 210);
            v191 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v184, v184, 201), v188),
                       _mm_mul_ps(_mm_shuffle_ps(v184, v184, 210), v187)),
                     v185);
            v192 = _mm_mul_ps(_mm_shuffle_ps(v183, v183, 201), v188);
            v193 = v189;
            v194 = _mm_unpackhi_ps(v189, v191);
            v195 = _mm_unpacklo_ps(v193, v191);
            v196 = _mm_mul_ps(_mm_sub_ps(v192, _mm_mul_ps(v190, v187)), v184);
            v197 = _mm_movelh_ps(v195, v196);
            if ( (_mm_movemask_ps(
                    _mm_cmpltps(
                      v16,
                      _mm_add_ps(
                        _mm_shuffle_ps(v194, v196, 228),
                        _mm_add_ps(v197, _mm_shuffle_ps(_mm_movehl_ps(v197, v195), v196, 212))))) & 7) == 7 )
            {
              v84 = 1;
              goto LABEL_42;
            }
          }
          v198 = v48[1];
          v199 = v48[2];
          v200 = _mm_sub_ps(v173, v198);
          v201 = _mm_sub_ps(v48[2], v198);
          v202 = _mm_sub_ps(v172, v199);
          v203 = _mm_sub_ps(v48[1], v172);
          v204 = _mm_shuffle_ps(v201, v201, 201);
          v205 = _mm_shuffle_ps(v202, v202, 201);
          v206 = _mm_sub_ps(v173, v199);
          v207 = _mm_sub_ps(v173, v172);
          v208 = _mm_sub_ps(_mm_mul_ps(v205, v201), _mm_mul_ps(v204, v202));
          v209 = _mm_shuffle_ps(v208, v208, 201);
          v210 = _mm_sub_ps(_mm_mul_ps(v204, v200), _mm_mul_ps(_mm_shuffle_ps(v200, v200, 201), v201));
          v211 = _mm_sub_ps(_mm_mul_ps(v205, v206), _mm_mul_ps(_mm_shuffle_ps(v206, v206, 201), v202));
          v212 = _mm_mul_ps(_mm_shuffle_ps(v210, v210, 201), v209);
          v213 = _mm_mul_ps(_mm_shuffle_ps(v211, v211, 201), v209);
          v214 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v203, v203, 201), v207),
                   _mm_mul_ps(_mm_shuffle_ps(v207, v207, 201), v203));
          v215 = _mm_unpacklo_ps(v212, v213);
          v216 = _mm_mul_ps(_mm_shuffle_ps(v214, v214, 201), v209);
          v217 = _mm_movelh_ps(v215, v216);
          v218 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v212, v213), v216, 228),
                   _mm_add_ps(v217, _mm_shuffle_ps(_mm_movehl_ps(v217, v215), v216, 212)));
          v14->m_checkTriangleDots.m_quad = v218;
          v219 = _mm_movemask_ps(_mm_cmpltps(v218, v16)) & 7;
          switch ( v219 )
          {
            case 7:
              v84 = 0;
              *v47 = v47[1];
              goto LABEL_42;
            case 6:
              goto LABEL_40;
            case 5:
              goto LABEL_56;
            case 3:
              goto LABEL_41;
          }
          if ( v219 != 1 )
          {
            if ( v219 == 2 )
            {
              LODWORD(v222) = (unsigned __int128)_mm_shuffle_ps(v174, v174, 170);
              LODWORD(v223) = (unsigned __int128)_mm_shuffle_ps(v174, v174, 0);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v218, v218, 170)) - v222) * v223) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v218, v218, 0)) - v223) * v222) )
                goto LABEL_41;
LABEL_40:
              *v48 = v48[2];
              goto LABEL_41;
            }
            if ( v219 != 4 )
              goto LABEL_40;
            LODWORD(v276) = (unsigned __int128)_mm_shuffle_ps(v174, v174, 0);
            LODWORD(v277) = (unsigned __int128)_mm_shuffle_ps(v174, v174, 85);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v218, v218, 0)) - v276) * v277) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v218, v218, 85)) - v277) * v276) )
              goto LABEL_40;
LABEL_56:
            v48[1] = v48[2];
            goto LABEL_41;
          }
          LODWORD(v220) = (unsigned __int128)_mm_shuffle_ps(v174, v174, 85);
          LODWORD(v221) = (unsigned __int128)_mm_shuffle_ps(v174, v174, 170);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v218, v218, 85)) - v220) * v221) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v218, v218, 170)) - v221) * v220) )
            v48[1] = v48[2];
        }
LABEL_41:
        v84 = 2;
LABEL_42:
        if ( !v84 )
        {
          if ( v24 == 2 )
            v24 = 1;
          else
            v25 = 1;
          goto LABEL_132;
        }
        v224 = v84 - 1;
        if ( !v224 )
          goto LABEL_64;
        if ( v224 != 1 )
          goto LABEL_132;
        v24 = 2;
        v25 = 2;
LABEL_46:
        v225 = v14->m_verticesA[0].m_quad;
        v226 = v14->m_verticesBinA[0].m_quad;
        v227 = v14->m_verticesA[1].m_quad;
        v228 = _mm_sub_ps(v14->m_verticesA[1].m_quad, v225);
        v229 = _mm_sub_ps(v225, v226);
        v230 = _mm_sub_ps(v14->m_verticesBinA[1].m_quad, v226);
        v231 = _mm_sub_ps(v14->m_verticesBinA[1].m_quad, v225);
        v232 = _mm_sub_ps(v14->m_verticesBinA[0].m_quad, v227);
        v233 = _mm_shuffle_ps(v228, v228, 201);
        v462 = v229;
        v234 = _mm_shuffle_ps(v230, v230, 201);
        v235 = _mm_sub_ps(_mm_mul_ps(v234, v228), _mm_mul_ps(v233, v230));
        v236 = _mm_shuffle_ps(v235, v235, 201);
        *v23 = v236;
        v237 = _mm_sub_ps(_mm_mul_ps(v236, v233), _mm_mul_ps(v236, v228));
        v238 = _mm_sub_ps(_mm_mul_ps(v236, v234), _mm_mul_ps(v236, v230));
        v239 = _mm_shuffle_ps(v238, v238, 201);
        v240 = _mm_shuffle_ps(v237, v237, 201);
        v241 = _mm_mul_ps(v229, v240);
        v242 = _mm_mul_ps(v229, v239);
        v243 = _mm_mul_ps(v232, v239);
        v244 = _mm_mul_ps(v231, v240);
        v245 = _mm_shuffle_ps(v242, v243, 68);
        v246 = _mm_shuffle_ps(v241, v244, 68);
        v247 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_shuffle_ps(v242, v243, 238), _mm_shuffle_ps(v241, v244, 238), 136),
                 _mm_add_ps(_mm_shuffle_ps(v245, v246, 221), _mm_shuffle_ps(v245, v246, 136)));
        v248 = _mm_movemask_ps(_mm_cmpltps(v16, v247));
        if ( v248 == 15 )
        {
          v297 = _mm_shuffle_ps(v247, v247, 0);
          v298 = _mm_add_ps(_mm_shuffle_ps(v247, v247, 85), v297);
          v299 = _mm_rcp_ps(v298);
          v496 = v298;
          v471 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v299, v298)), v299), v297);
          v300 = _mm_mul_ps(*v23, v229);
          *v23 = _mm_xor_ps(
                   *v23,
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(
                               (__m128i)_mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v300, v300, 85), _mm_shuffle_ps(v300, v300, 0)),
                                          _mm_shuffle_ps(v300, v300, 170)),
                               0x1Fu),
                             0x1Fu));
          v14->m_closestPointOnEdgeA.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v227, v225), v471), v225);
          goto LABEL_132;
        }
        v249 = v248 - 7;
        if ( !v249 )
        {
          v14->m_verticesBinA[0] = v14->m_verticesBinA[1];
LABEL_79:
          v25 = 1;
LABEL_120:
          v416 = v14->m_verticesA[1].m_quad;
          v417 = v14->m_verticesBinA[0].m_quad;
          v418 = v14->m_verticesA[0].m_quad;
          v419 = _mm_sub_ps(v14->m_verticesA[1].m_quad, v418);
          v420 = _mm_sub_ps(v416, v417);
          v421 = _mm_sub_ps(v418, v417);
          v422 = _mm_mul_ps(v420, v419);
          v423 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v422, v422, 85), _mm_shuffle_ps(v422, v422, 0)),
                   _mm_shuffle_ps(v422, v422, 170));
          v424 = _mm_mul_ps(v421, v419);
          v425 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v424, v424, 85), _mm_shuffle_ps(v424, v424, 0)),
                   _mm_shuffle_ps(v424, v424, 170));
          if ( (float)(v425.m128_f32[0] * v423.m128_f32[0]) >= v16.m128_f32[0] )
          {
            v433 = _mm_cmpleps(v423, v16);
            v24 = 1;
            v434 = _mm_or_ps(_mm_and_ps(v433, v416), _mm_andnot_ps(v433, v418));
            *v23 = _mm_sub_ps(v434, v417);
            v14->m_verticesA[0].m_quad = v434;
          }
          else
          {
            v24 = 2;
            v426 = _mm_sub_ps(_mm_mul_ps(v421, v423), _mm_mul_ps(v420, v425));
            v427 = _mm_mul_ps(v419, v419);
            v428 = _mm_shuffle_ps(v419, v419, 201);
            v429 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v426, v426, 201), v419), _mm_mul_ps(v426, v428));
            v504 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v427, v427, 85), _mm_shuffle_ps(v427, v427, 0)),
                     _mm_shuffle_ps(v427, v427, 170));
            v430 = _mm_shuffle_ps(v429, v429, 201);
            v469 = _mm_rcp_ps(v504);
            v431 = _mm_sub_ps(_mm_mul_ps(v430, v428), _mm_mul_ps(v430, v419));
            v432 = _mm_shuffle_ps(v431, v431, 201);
            *v23 = v432;
            *v23 = _mm_mul_ps(v469, v432);
          }
          goto LABEL_132;
        }
        v250 = v249 - 4;
        if ( !v250 )
          goto LABEL_79;
        v251 = v250 - 2;
        if ( v251 )
        {
          if ( v251 == 1 )
            goto LABEL_75;
          v252 = _mm_sub_ps(v226, v225);
          v253 = _mm_mul_ps(v230, v228);
          v254 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v253, v253, 85), _mm_shuffle_ps(v253, v253, 0)),
                   _mm_shuffle_ps(v253, v253, 170));
          v255 = _mm_mul_ps(v252, v228);
          v256 = _mm_mul_ps(v252, v230);
          v257 = _mm_mul_ps(v230, v230);
          v258 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v255, v255, 85), _mm_shuffle_ps(v255, v255, 0)),
                   _mm_shuffle_ps(v255, v255, 170));
          v259 = _mm_mul_ps(v228, v228);
          v260 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v256, v256, 85), _mm_shuffle_ps(v256, v256, 0)),
                   _mm_shuffle_ps(v256, v256, 170));
          v484 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v259, v259, 85), _mm_shuffle_ps(v259, v259, 0)),
                   _mm_shuffle_ps(v259, v259, 170));
          v486 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v257, v257, 85), _mm_shuffle_ps(v257, v257, 0)),
                   _mm_shuffle_ps(v257, v257, 170));
          v27 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v486, v484), _mm_mul_ps(v254, v254)), *(__m128 *)&epsilon);
          v261 = _mm_rcp_ps(v27);
          v488 = v27;
          v262 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v261, v27)), v261);
          v263 = _mm_rcp_ps(v486);
          v490 = v262;
          v264 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v263, v486)), v263);
          v265 = _mm_rcp_ps(v484);
          v492 = v264;
          v266 = _mm_sub_ps(_mm_mul_ps(v486, v258), _mm_mul_ps(v260, v254));
          v494 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v265, v484)), v265);
          v267 = _mm_cmpltps(v266, v27);
          v268 = _mm_cmpleps(v27, *(__m128 *)&epsilon);
          v28 = _mm_mul_ps(v258, v494);
          v269 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_or_ps(
                       _mm_andnot_ps(
                         v268,
                         _mm_mul_ps(
                           _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v267, v27), _mm_and_ps(v267, v266))),
                           v262)),
                       _mm_and_ps(v268, query.m_quad)),
                     _mm_mul_ps(v264, v254)),
                   _mm_mul_ps(v260, v264));
          v270 = _mm_cmpltps(v269, query.m_quad);
          v271 = _mm_max_ps(v16, _mm_or_ps(_mm_and_ps(v270, v269), _mm_andnot_ps(v270, query.m_quad)));
          v272 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v494, v254), v271), v28);
          v273 = _mm_cmpltps(v272, query.m_quad);
          v274 = _mm_max_ps(v16, _mm_or_ps(_mm_and_ps(v273, v272), _mm_andnot_ps(v273, query.m_quad)));
          v275 = _mm_movemask_ps(
                   _mm_cmpeqps(
                     (__m128)xmmword_141A71330,
                     _mm_movelh_ps(_mm_unpacklo_ps(v274, v274), _mm_unpacklo_ps(v271, v271))));
          v14->m_closestPointOnEdgeA.m_quad = _mm_add_ps(_mm_mul_ps(v274, v228), v225);
          if ( !v275 )
          {
            v279 = _mm_mul_ps(*v23, v462);
            *v23 = _mm_xor_ps(
                     *v23,
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v279, v279, 85), _mm_shuffle_ps(v279, v279, 0)),
                                            _mm_shuffle_ps(v279, v279, 170)),
                                 0x1Fu),
                               0x1Fu));
            goto LABEL_132;
          }
          if ( v275 & 1 )
          {
            v24 = 1;
            v14->m_verticesA[0] = v14->m_verticesA[1];
          }
          else if ( v275 & 2 )
          {
            v24 = 1;
          }
          if ( v275 & 4 )
          {
            v25 = 1;
            v14->m_verticesBinA[0] = v14->m_verticesBinA[1];
          }
          else if ( v275 & 8 )
          {
            v25 = 1;
          }
          v46 = (v25 | 8 * v24) - 9;
          if ( v46 > 0x18 )
            goto LABEL_64;
          continue;
        }
        v14->m_verticesA[0] = v14->m_verticesA[1];
LABEL_75:
        v24 = 1;
LABEL_76:
        v280 = v14->m_verticesBinA[1].m_quad;
        v281 = v14->m_verticesA[0].m_quad;
        v282 = v14->m_verticesBinA[0].m_quad;
        v283 = _mm_sub_ps(v14->m_verticesBinA[1].m_quad, v282);
        v284 = _mm_sub_ps(v280, v281);
        v285 = _mm_sub_ps(v282, v281);
        v286 = _mm_mul_ps(v284, v283);
        v287 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v286, v286, 85), _mm_shuffle_ps(v286, v286, 0)),
                 _mm_shuffle_ps(v286, v286, 170));
        v288 = _mm_mul_ps(v285, v283);
        v289 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v288, v288, 85), _mm_shuffle_ps(v288, v288, 0)),
                 _mm_shuffle_ps(v288, v288, 170));
        if ( (float)(v289.m128_f32[0] * v287.m128_f32[0]) >= v16.m128_f32[0] )
        {
          v443 = _mm_cmpleps(v287, v16);
          v25 = 1;
          v444 = _mm_or_ps(_mm_and_ps(v443, v280), _mm_andnot_ps(v443, v282));
          *v23 = _mm_sub_ps(v281, v444);
          v14->m_verticesBinA[0].m_quad = v444;
        }
        else
        {
          v25 = 2;
          v290 = _mm_sub_ps(_mm_mul_ps(v285, v287), _mm_mul_ps(v284, v289));
          v291 = _mm_mul_ps(v283, v283);
          v292 = _mm_shuffle_ps(v283, v283, 201);
          v506 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v291, v291, 85), _mm_shuffle_ps(v291, v291, 0)),
                   _mm_shuffle_ps(v291, v291, 170));
          v466 = _mm_rcp_ps(v506);
          v293 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v290, v290, 201), v283), _mm_mul_ps(v290, v292));
          v294 = _mm_shuffle_ps(v293, v293, 201);
          v295 = _mm_sub_ps(_mm_mul_ps(v294, v283), _mm_mul_ps(v294, v292));
          v296 = _mm_shuffle_ps(v295, v295, 201);
          *v23 = v296;
          *v23 = _mm_mul_ps(v466, v296);
        }
LABEL_132:
        v445 = v461;
        v14->m_lastDimB.m_storage = v25;
        v446 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v23);
        *v23 = v446;
        v447 = _mm_mul_ps(v446, v446);
        v448 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v447, v447, 85), _mm_shuffle_ps(v447, v447, 0)),
                 _mm_shuffle_ps(v447, v447, 170));
        v449 = _mm_rsqrt_ps(v448);
        v508 = v448;
        v35 = _mm_mul_ps(
                v446,
                _mm_andnot_ps(
                  _mm_cmpleps(v448, v16),
                  _mm_mul_ps(_mm_sub_ps(v468, _mm_mul_ps(_mm_mul_ps(v449, v448), v449)), _mm_mul_ps(v449, v467))));
        if ( v24 > 0 )
        {
          v450 = (signed __int64)v14->m_verticesA;
          v451 = (unsigned int)v24;
          do
          {
            v450 += 16i64;
            v452 = _mm_mul_ps(_mm_sub_ps(v14->m_verticesBinA[0].m_quad, *(__m128 *)(v450 - 16)), v35);
            v445 = _mm_min_ps(
                     v445,
                     (__m128)_mm_srli_epi32(
                               _mm_slli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v452, v452, 85), _mm_shuffle_ps(v452, v452, 0)),
                                            _mm_shuffle_ps(v452, v452, 170)),
                                 1u),
                               1u));
            --v451;
          }
          while ( v451 );
          v461 = v445;
        }
        v453 = _mm_sub_ps(*v23, v470);
        v464 = _mm_add_ps(v464, v464);
        v454 = _mm_mul_ps(v453, v453);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v454, v454, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v454, v454, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v454, v454, 170))) >= v464.m128_f32[0]
          || (++HIDWORD(v456), SHIDWORD(v456) < 3) )
        {
          v28 = v459;
          v455 = v445.m128_f32[0] * v445.m128_f32[0];
          v27 = v457;
          if ( v455 <= v472.m128_f32[0] )
            goto LABEL_65;
          v29 = v474;
          v12 = vars0;
          v11 = retaddr;
          goto LABEL_4;
        }
LABEL_64:
        v28 = v459;
        v27 = v457;
LABEL_65:
        v13 = v509;
        v32 = v458;
        v21 = v458;
$returnTrue:
        if ( v28.m128_f32[0] >= *v514
          || v28.m128_f32[0] > (float)(1.0 - 0.00000011920929)
          && (v278 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(v27, *v10), v10[1]), v21),
              (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v278, v278, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v278, v278, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v278, v278, 170))) < 0.00000011920929) )
        {
          v13->m_bool = 0;
        }
        else
        {
          *(__m128 *)v514 = v28;
          *(__m128 *)shapeB = v32;
          v13->m_bool = 1;
        }
        return v13;
      case 0x18u:
        v301 = g_vectorfConstants[0];
        v302 = v14->m_verticesBinA[0].m_quad;
        v303 = (__m128 *)v14->m_verticesA;
LABEL_83:
        v304 = v303[1];
        v305 = v303[2];
        v306 = _mm_sub_ps(v303[1], *v303);
        v307 = _mm_sub_ps(*v303, v305);
        v308 = _mm_sub_ps(v303[3], *v303);
        v309 = _mm_sub_ps(v303[2], v304);
        v310 = _mm_sub_ps(v303[3], v304);
        v311 = _mm_sub_ps(v303[3], v305);
        v312 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v310, v310, 201), v309),
                 _mm_mul_ps(_mm_shuffle_ps(v309, v309, 201), v310));
        v313 = _mm_mul_ps(_mm_sub_ps(v302, v303[3]), v301);
        v314 = _mm_shuffle_ps(v312, v312, 201);
        v315 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v311, v311, 201), v307),
                 _mm_mul_ps(_mm_shuffle_ps(v307, v307, 201), v311));
        v316 = _mm_shuffle_ps(v315, v315, 201);
        v317 = _mm_mul_ps(v313, v316);
        v318 = _mm_mul_ps(v316, v316);
        v319 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v308, v308, 201), v306),
                 _mm_mul_ps(_mm_shuffle_ps(v306, v306, 201), v308));
        v320 = _mm_mul_ps(v313, v314);
        v321 = _mm_mul_ps(v314, v314);
        v322 = _mm_shuffle_ps(v319, v319, 201);
        v323 = _mm_unpacklo_ps(v320, v317);
        v324 = _mm_mul_ps(v313, v322);
        v325 = _mm_movelh_ps(v323, v324);
        v326 = _mm_mul_ps(v322, v322);
        v327 = (__m128i)_mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v320, v317), v324, 228),
                          _mm_add_ps(v325, _mm_shuffle_ps(_mm_movehl_ps(v325, v323), v324, 212)));
        v328 = _mm_unpacklo_ps(v321, v318);
        v329 = _mm_movelh_ps(v328, v326);
        v330 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v321, v318), v326, 228),
                 _mm_add_ps(v329, _mm_shuffle_ps(_mm_movehl_ps(v329, v328), v326, 212)));
        v331 = _mm_cmpeqps(v16, v330);
        v332 = _mm_rcp_ps(v330);
        v498 = v330;
        v500 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v332, v330)), v332);
        v459.m128_i32[0] = 897988542;
        v333 = _mm_or_ps(
                 _mm_andnot_ps(
                   v331,
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v327, 1u), 1u), (__m128)v327), v500)),
                 _mm_and_ps(v331, (__m128)xmmword_141A712A0));
        v334 = _mm_max_ps(
                 _mm_shuffle_ps(v333, v333, 170),
                 _mm_max_ps(_mm_shuffle_ps(v333, v333, 85), _mm_shuffle_ps(v333, v333, 0)));
        v502 = _mm_and_ps(_mm_cmpleps(v334, v333), (__m128)xmmword_141C1F4F0);
        v335 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(v502)];
        if ( v334.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x358637BEu, (__m128)0x358637BEu, 0)) )
          goto LABEL_64;
        v459.m128_i32[2] = 1066192077;
        v336 = _mm_or_ps(
                 _mm_andnot_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v335], v333),
                 _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v335], (__m128)xmmword_141A712F0));
        if ( v334.m128_f32[0] <= (float)(fmax(
                                           COERCE_FLOAT(_mm_shuffle_ps(v336, v336, 170)),
                                           fmax(
                                             COERCE_FLOAT(_mm_shuffle_ps(v336, v336, 85)),
                                             COERCE_FLOAT(_mm_shuffle_ps(v336, v336, 0))))
                                       * COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F8CCCCDu, (__m128)0x3F8CCCCDu, 0))) )
        {
          v337 = 2;
          v338 = 1;
          v339 = 4;
          v340 = 32i64;
          v341 = 16i64;
          v342 = 0i64;
          v343 = 3i64;
          v344 = _mm_movemask_ps(_mm_cmpleps(v16, (__m128)v327));
          do
          {
            if ( v344 & v338 && v344 & v337 )
            {
              v345 = *(__m128 *)((char *)v303 + v340);
              v346 = _mm_sub_ps(v303[v342], v345);
              v347 = _mm_sub_ps(v303[3], v345);
              v348 = _mm_sub_ps(v302, v345);
              v349 = _mm_mul_ps(v347, v346);
              v350 = _mm_sub_ps(*(__m128 *)((char *)v303 + v341), v345);
              v351 = _mm_mul_ps(v348, v346);
              v352 = _mm_mul_ps(v347, v350);
              v353 = _mm_mul_ps(v348, v350);
              if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v351, v351, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v351, v351, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v351, v351, 170)))
                         * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v352, v352, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v352, v352, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v352, v352, 170)))) >= (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v349, v349, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v349, v349, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v349, v349, 170)))
                                                                                            * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v353, v353, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v353, v353, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v353, v353, 170)))) )
                v337 = v338;
              v344 &= ~v337;
            }
            v337 = v339;
            v341 = v340;
            v339 = v338;
            v338 = __ROL4__(v338, 1);
            v340 = v342 * 16;
            ++v342;
            --v343;
          }
          while ( v343 );
          v23 = &v14->m_support.m_quad;
          if ( v344 & 7 )
            v335 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v344];
          else
            v335 = -1;
          v10 = (__m128 *)v513;
        }
        if ( v335 < 0 )
          goto LABEL_64;
        v303[v335] = v303[3];
        if ( v24 == 4 )
        {
          v24 = 3;
LABEL_99:
          v354 = v14->m_verticesA[2].m_quad;
          v355 = v14->m_verticesA[1].m_quad;
          v356 = v14->m_verticesA[0].m_quad;
          v357 = _mm_sub_ps(v14->m_verticesA[2].m_quad, v355);
          v358 = _mm_sub_ps(v355, v356);
          v359 = _mm_sub_ps(v14->m_verticesBinA[0].m_quad, v355);
          v360 = _mm_sub_ps(v14->m_verticesA[0].m_quad, v354);
          v361 = _mm_shuffle_ps(v357, v357, 201);
          v362 = _mm_sub_ps(v14->m_verticesBinA[0].m_quad, v354);
          v363 = _mm_shuffle_ps(v360, v360, 201);
          v364 = _mm_sub_ps(v14->m_verticesBinA[0].m_quad, v356);
          v365 = _mm_sub_ps(_mm_mul_ps(v363, v357), _mm_mul_ps(v361, v360));
          v366 = _mm_shuffle_ps(v365, v365, 201);
          v367 = _mm_sub_ps(_mm_mul_ps(v361, v359), _mm_mul_ps(_mm_shuffle_ps(v359, v359, 201), v357));
          v368 = _mm_sub_ps(_mm_mul_ps(v363, v362), _mm_mul_ps(_mm_shuffle_ps(v362, v362, 201), v360));
          v369 = _mm_mul_ps(_mm_shuffle_ps(v367, v367, 201), v366);
          v370 = _mm_mul_ps(_mm_shuffle_ps(v368, v368, 201), v366);
          v371 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v358, v358, 201), v364),
                   _mm_mul_ps(_mm_shuffle_ps(v364, v364, 201), v358));
          v372 = _mm_unpacklo_ps(v369, v370);
          v373 = _mm_mul_ps(_mm_shuffle_ps(v371, v371, 201), v366);
          v374 = _mm_movelh_ps(v372, v373);
          v375 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v369, v370), v373, 228),
                   _mm_add_ps(v374, _mm_shuffle_ps(_mm_movehl_ps(v374, v372), v373, 212)));
          v376 = _mm_movemask_ps(_mm_cmpltps(v375, v16)) & 7;
          if ( v376 == 7 )
          {
            v377 = _mm_mul_ps(_mm_sub_ps(v356, v14->m_verticesBinA[0].m_quad), v366);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v377, v377, 85), _mm_shuffle_ps(v377, v377, 0)),
                     _mm_shuffle_ps(v377, v377, 170))) )
            {
              v378.m_quad = (__m128)v14->m_verticesA[0];
              v366 = _mm_xor_ps(v366, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              v14->m_verticesA[0] = v14->m_verticesA[1];
              v14->m_verticesA[1] = (hkcdVertex)v378.m_quad;
              v375 = _mm_shuffle_ps(v375, v375, 225);
            }
          }
          *v23 = v366;
          v14->m_checkTriangleDots.m_quad = v375;
          if ( v376 == 7 )
            goto LABEL_132;
          v379 = hkcdGskBase::maskToIndex[v376];
          if ( (signed int)v379 >= 0 )
          {
            v408 = *(char *)(v379 + 5398197060i64);
            v409 = *(char *)(v379 + 5398197062i64);
            v410 = *(&v14->m_checkTriangleDots.m_quad + v379 + 2);
            v411 = _mm_sub_ps(v14->m_verticesBinA[0].m_quad, v410);
            v412 = _mm_sub_ps(*(&v14->m_checkTriangleDots.m_quad + v409 + 2), v410);
            v413 = _mm_mul_ps(_mm_sub_ps(*(&v14->m_checkTriangleDots.m_quad + v408 + 2), v410), v411);
            v414.m_quad = (__m128)v14->m_verticesA[2];
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v413, v413, 85), _mm_shuffle_ps(v413, v413, 0)),
                      _mm_shuffle_ps(v413, v413, 170))) )
            {
              *((hkcdVertex *)&v14->m_checkTriangleDots + v409 + 2) = (hkcdVertex)v414.m_quad;
              goto LABEL_120;
            }
            v415 = _mm_mul_ps(v412, v411);
            *((hkcdVertex *)&v14->m_checkTriangleDots + v408 + 2) = (hkcdVertex)v414.m_quad;
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v415, v415, 85), _mm_shuffle_ps(v415, v415, 0)),
                      _mm_shuffle_ps(v415, v415, 170))) )
              goto LABEL_120;
            v24 = 1;
            if ( (_DWORD)v409 == 2 )
              LODWORD(v409) = v408;
            *((_OWORD *)&v14->m_checkTriangleDots + (signed int)v409 + 2i64) = v14->m_verticesA[1];
            *v23 = _mm_sub_ps(v14->m_verticesA[0].m_quad, v14->m_verticesBinA[0].m_quad);
            goto LABEL_132;
          }
          v380 = v379 + 8;
          if ( v380 < 3 )
          {
            *((_OWORD *)&v14->m_checkTriangleDots + v380 + 2i64) = v14->m_verticesA[2];
            goto LABEL_120;
          }
        }
        else
        {
          v25 = 3;
LABEL_107:
          v381 = v14->m_verticesBinA[1].m_quad;
          v382 = v14->m_verticesBinA[2].m_quad;
          v383 = v14->m_verticesBinA[0].m_quad;
          v384 = v14->m_verticesA[0].m_quad;
          v385 = _mm_sub_ps(v14->m_verticesBinA[2].m_quad, v381);
          v386 = _mm_sub_ps(v14->m_verticesBinA[0].m_quad, v382);
          v387 = _mm_sub_ps(v384, v381);
          v388 = _mm_sub_ps(v14->m_verticesA[0].m_quad, v382);
          v389 = _mm_sub_ps(v14->m_verticesBinA[1].m_quad, v383);
          v390 = _mm_shuffle_ps(v385, v385, 201);
          v391 = _mm_shuffle_ps(v386, v386, 201);
          v392 = _mm_sub_ps(v384, v383);
          v393 = _mm_sub_ps(_mm_mul_ps(v385, v391), _mm_mul_ps(v386, v390));
          v394 = _mm_shuffle_ps(v393, v393, 201);
          v395 = _mm_sub_ps(_mm_mul_ps(v387, v390), _mm_mul_ps(_mm_shuffle_ps(v387, v387, 201), v385));
          v396 = _mm_sub_ps(_mm_mul_ps(v388, v391), _mm_mul_ps(_mm_shuffle_ps(v388, v388, 201), v386));
          v397 = _mm_mul_ps(_mm_shuffle_ps(v395, v395, 201), v394);
          v398 = _mm_mul_ps(_mm_shuffle_ps(v396, v396, 201), v394);
          v399 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v389, v389, 201), v392),
                   _mm_mul_ps(_mm_shuffle_ps(v392, v392, 201), v389));
          v400 = _mm_unpacklo_ps(v397, v398);
          v401 = _mm_mul_ps(_mm_shuffle_ps(v399, v399, 201), v394);
          v402 = _mm_movelh_ps(v400, v401);
          v403 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v397, v398), v401, 228),
                   _mm_add_ps(v402, _mm_shuffle_ps(_mm_movehl_ps(v402, v400), v401, 212)));
          v404 = _mm_movemask_ps(_mm_cmpltps(v403, v16)) & 7;
          if ( v404 == 7 )
          {
            v405 = _mm_mul_ps(v394, v392);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v405, v405, 85), _mm_shuffle_ps(v405, v405, 0)),
                     _mm_shuffle_ps(v405, v405, 170))) )
            {
              v403 = _mm_shuffle_ps(v403, v403, 225);
              v394 = _mm_xor_ps(v394, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              v14->m_verticesBinA[0] = v14->m_verticesBinA[1];
              v14->m_verticesBinA[1].m_quad = v383;
            }
          }
          *v23 = v394;
          v14->m_checkTriangleDots.m_quad = v403;
          if ( v404 == 7 )
            goto LABEL_132;
          v406 = hkcdGskBase::maskToIndex[v404];
          if ( (signed int)v406 >= 0 )
          {
            v435 = *(char *)(v406 + 5398197060i64);
            v436 = *(char *)(v406 + 5398197062i64);
            v437 = *(&v14->m_checkTriangleDots.m_quad + v406 + 6);
            v438 = _mm_sub_ps(v14->m_verticesA[0].m_quad, v437);
            v439 = _mm_sub_ps(*(&v14->m_checkTriangleDots.m_quad + v436 + 6), v437);
            v440 = _mm_mul_ps(_mm_sub_ps(*(&v14->m_checkTriangleDots.m_quad + v435 + 6), v437), v438);
            v441.m_quad = (__m128)v14->m_verticesBinA[2];
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v440, v440, 85), _mm_shuffle_ps(v440, v440, 0)),
                      _mm_shuffle_ps(v440, v440, 170))) )
            {
              *((hkcdVertex *)&v14->m_checkTriangleDots + v436 + 6) = (hkcdVertex)v441.m_quad;
              goto LABEL_76;
            }
            v442 = _mm_mul_ps(v438, v439);
            *((hkcdVertex *)&v14->m_checkTriangleDots + v435 + 6) = (hkcdVertex)v441.m_quad;
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v442, v442, 85), _mm_shuffle_ps(v442, v442, 0)),
                      _mm_shuffle_ps(v442, v442, 170))) )
              goto LABEL_76;
            v25 = 1;
            if ( (_DWORD)v436 == 2 )
              LODWORD(v436) = v435;
            *((_OWORD *)&v14->m_checkTriangleDots + (signed int)v436 + 6i64) = v14->m_verticesBinA[1];
            *v23 = _mm_sub_ps(v14->m_verticesA[0].m_quad, v14->m_verticesBinA[0].m_quad);
            goto LABEL_132;
          }
          v407 = v406 + 8;
          if ( v407 < 3 )
          {
            *((_OWORD *)&v14->m_checkTriangleDots + v407 + 6i64) = v14->m_verticesBinA[2];
            goto LABEL_76;
          }
        }
        v24 = 1;
        v25 = 1;
LABEL_130:
        *v23 = _mm_sub_ps(v14->m_verticesA[0].m_quad, v14->m_verticesBinA[0].m_quad);
        goto LABEL_132;
      default:
        goto LABEL_65;
    }
  }
}437);
            v440 = _mm_mul_ps(_mm_sub_ps(*(&v14->m_checkTriangleDots.m_quad + v435 + 6), v437), v438);
            v441.m_quad = (__m128)v14->m_verticesBinA[2];
            if ( !_mm_movemask_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v

