// File Line: 58
// RVA: 0xEF1440
void __fastcall FSHA1Transform(unsigned int *state, const char *buffer)
{
  unsigned int *v2; // rsi
  unsigned int v3; // edi
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // r9d
  int v7; // edx
  unsigned int v8; // r9d
  int v9; // r10d
  int v10; // r8d
  int v11; // ecx
  int v12; // r9d
  unsigned int v13; // r11d
  int v14; // ecx
  int v15; // r10d
  int v16; // edx
  int v17; // ecx
  int v18; // r11d
  int v19; // r8d
  int v20; // ecx
  int v21; // edx
  int v22; // r9d
  int v23; // ecx
  int v24; // r8d
  int v25; // r10d
  int v26; // ecx
  int v27; // r9d
  int v28; // r11d
  int v29; // ecx
  int v30; // r10d
  int v31; // edx
  int v32; // ecx
  int v33; // r11d
  int v34; // r8d
  int v35; // ecx
  int v36; // edx
  int v37; // ebx
  int v38; // r9d
  int v39; // r8d
  int v40; // r9d
  int v41; // r10d
  int v42; // ebx
  int v43; // r10d
  int v44; // r11d
  int v45; // r9d
  int v46; // ecx
  int v47; // eax
  int v48; // r10d
  int v49; // r11d
  int v50; // edx
  int v51; // ecx
  int v52; // r11d
  int v53; // r8d
  int v54; // r12d
  int v55; // ecx
  int v56; // edx
  int v57; // r12d
  int v58; // r9d
  int v59; // ebx
  int v60; // ecx
  int v61; // r8d
  int v62; // r10d
  int v63; // ecx
  int v64; // r9d
  int v65; // r11d
  int v66; // edx
  int v67; // r10d
  int v68; // ecx
  int v69; // r11d
  int v70; // r8d
  int v71; // edi
  int v72; // r9d
  int v73; // edx
  int v74; // ecx
  int v75; // r8d
  int v76; // r14d
  int v77; // r15d
  int v78; // r10d
  int v79; // ecx
  int v80; // r9d
  int v81; // r13d
  int v82; // r11d
  int v83; // ecx
  int v84; // r10d
  int v85; // edx
  int v86; // ecx
  int v87; // r11d
  int v88; // r8d
  int v89; // ecx
  int v90; // edx
  int v91; // r9d
  int v92; // ecx
  int v93; // r8d
  int v94; // r10d
  int v95; // ecx
  int v96; // r9d
  int v97; // r11d
  int v98; // ecx
  int v99; // r10d
  int v100; // edx
  int v101; // ecx
  int v102; // r11d
  int v103; // r8d
  int v104; // ecx
  int v105; // edx
  int v106; // r9d
  int v107; // ecx
  int v108; // r8d
  int v109; // r10d
  int v110; // ecx
  int v111; // r9d
  int v112; // r11d
  int v113; // ecx
  int v114; // r10d
  int v115; // edx
  int v116; // ecx
  int v117; // r11d
  int v118; // r12d
  int v119; // r8d
  int v120; // ecx
  int v121; // edx
  int v122; // r9d
  int v123; // ecx
  int v124; // r8d
  int v125; // r10d
  int v126; // ecx
  int v127; // r9d
  int v128; // ebx
  int v129; // r11d
  int v130; // r10d
  int v131; // r15d
  int v132; // edi
  int v133; // ebx
  int v134; // ecx
  int v135; // r11d
  int v136; // r8d
  int v137; // eax
  int v138; // r13d
  int v139; // ecx
  int v140; // ebx
  unsigned int v141; // eax
  int v142; // r9d
  int v143; // eax
  int v144; // ecx
  int v145; // r8d
  int v146; // r10d
  int v147; // ecx
  int v148; // r9d
  int v149; // r11d
  int v150; // ebx
  int v151; // r10d
  int v152; // ecx
  int v153; // r11d
  int v154; // r8d
  int v155; // ecx
  int v156; // ebx
  int v157; // r9d
  int v158; // ecx
  int v159; // r8d
  int v160; // r10d
  int v161; // ecx
  int v162; // r9d
  int v163; // r11d
  int v164; // ecx
  int v165; // eax
  int v166; // r10d
  int v167; // ecx
  int v168; // eax
  int v169; // ebx
  int v170; // ecx
  int v171; // r11d
  int v172; // ecx
  int v173; // r12d
  int v174; // eax
  int v175; // r8d
  int v176; // ecx
  int v177; // ebx
  int v178; // ecx
  int v179; // eax
  int v180; // r9d
  int v181; // ecx
  int v182; // r8d
  int v183; // r10d
  int v184; // ecx
  int v185; // r9d
  int v186; // r11d
  int v187; // ecx
  int v188; // r10d
  int v189; // eax
  int v190; // edi
  int v191; // ecx
  int v192; // r11d
  int v193; // ebx
  int v194; // ecx
  int v195; // edi
  int v196; // r9d
  int v197; // ecx
  int v198; // ebx
  int v199; // r10d
  int v200; // eax
  int v201; // r13d
  int v202; // ecx
  int v203; // r9d
  int v204; // ecx
  int v205; // eax
  int v206; // r11d
  int v207; // ecx
  int v208; // r10d
  int v209; // ecx
  int v210; // r8d
  int v211; // eax
  int v212; // r11d
  int v213; // r8d
  int v214; // edx
  int v215; // r9d
  int v216; // r8d
  int v217; // eax
  int v218; // edx
  int v219; // r10d
  int v220; // eax
  int v221; // r9d
  int v222; // ebx
  int v223; // r13d
  int v224; // r11d
  int v225; // eax
  int v226; // r10d
  int v227; // r14d
  int v228; // r8d
  int v229; // edx
  int v230; // r11d
  int v231; // r9d
  int v232; // r8d
  int v233; // eax
  int v234; // edx
  int v235; // r15d
  int v236; // r10d
  int v237; // r14d
  int v238; // eax
  int v239; // r9d
  int v240; // r11d
  int v241; // ecx
  int v242; // eax
  int v243; // r10d
  int v244; // r11d
  int v245; // ebx
  int v246; // r13d
  int v247; // eax
  int v248; // r11d
  int v249; // r15d
  int v250; // r8d
  int v251; // eax
  int v252; // ebx
  int v253; // r12d
  int v254; // eax
  int v255; // r15d
  int v256; // r14d
  int v257; // edx
  int v258; // eax
  int v259; // r10d
  int v260; // r12d
  int v261; // eax
  int v262; // r14d
  int v263; // r11d
  int v264; // edi
  int v265; // r9d
  unsigned int v266; // ebx
  unsigned int v267; // eax
  int v268; // edi
  int v269; // r10d
  unsigned int v270; // eax
  int v271; // ebx
  unsigned int v272; // r8d
  int v273; // eax
  int v274; // r10d
  int v275; // edx
  unsigned int v276; // [rsp+20h] [rbp-79h]
  int v277; // [rsp+20h] [rbp-79h]
  int v278; // [rsp+20h] [rbp-79h]
  int v279; // [rsp+20h] [rbp-79h]
  unsigned int v280; // [rsp+24h] [rbp-75h]
  int v281; // [rsp+24h] [rbp-75h]
  int v282; // [rsp+24h] [rbp-75h]
  int v283; // [rsp+24h] [rbp-75h]
  unsigned int v284; // [rsp+28h] [rbp-71h]
  int v285; // [rsp+28h] [rbp-71h]
  int v286; // [rsp+28h] [rbp-71h]
  int v287; // [rsp+28h] [rbp-71h]
  unsigned int v288; // [rsp+2Ch] [rbp-6Dh]
  int v289; // [rsp+2Ch] [rbp-6Dh]
  int v290; // [rsp+2Ch] [rbp-6Dh]
  int v291; // [rsp+2Ch] [rbp-6Dh]
  unsigned int v292; // [rsp+30h] [rbp-69h]
  int v293; // [rsp+30h] [rbp-69h]
  int v294; // [rsp+30h] [rbp-69h]
  int v295; // [rsp+30h] [rbp-69h]
  int v296; // [rsp+30h] [rbp-69h]
  unsigned int v297; // [rsp+34h] [rbp-65h]
  int v298; // [rsp+34h] [rbp-65h]
  int v299; // [rsp+34h] [rbp-65h]
  int v300; // [rsp+34h] [rbp-65h]
  unsigned int v301; // [rsp+38h] [rbp-61h]
  int v302; // [rsp+38h] [rbp-61h]
  int v303; // [rsp+38h] [rbp-61h]
  int v304; // [rsp+38h] [rbp-61h]
  int v305; // [rsp+38h] [rbp-61h]
  unsigned int v306; // [rsp+3Ch] [rbp-5Dh]
  int v307; // [rsp+3Ch] [rbp-5Dh]
  int v308; // [rsp+3Ch] [rbp-5Dh]
  int v309; // [rsp+3Ch] [rbp-5Dh]
  unsigned int v310; // [rsp+40h] [rbp-59h]
  int v311; // [rsp+40h] [rbp-59h]
  int v312; // [rsp+40h] [rbp-59h]
  int v313; // [rsp+40h] [rbp-59h]
  unsigned int v314; // [rsp+44h] [rbp-55h]
  int v315; // [rsp+44h] [rbp-55h]
  int v316; // [rsp+44h] [rbp-55h]
  unsigned int v317; // [rsp+48h] [rbp-51h]
  int v318; // [rsp+48h] [rbp-51h]
  int v319; // [rsp+48h] [rbp-51h]
  int v320; // [rsp+4Ch] [rbp-4Dh]
  int v321; // [rsp+4Ch] [rbp-4Dh]
  int v322; // [rsp+4Ch] [rbp-4Dh]
  int v323; // [rsp+4Ch] [rbp-4Dh]
  unsigned int v324; // [rsp+50h] [rbp-49h]
  int v325; // [rsp+50h] [rbp-49h]
  int v326; // [rsp+50h] [rbp-49h]
  unsigned int v327; // [rsp+54h] [rbp-45h]
  int v328; // [rsp+54h] [rbp-45h]
  int v329; // [rsp+54h] [rbp-45h]
  int v330; // [rsp+54h] [rbp-45h]
  unsigned int v331; // [rsp+58h] [rbp-41h]
  int v332; // [rsp+58h] [rbp-41h]
  unsigned int v333; // [rsp+5Ch] [rbp-3Dh]
  int v334; // [rsp+5Ch] [rbp-3Dh]
  int v335; // [rsp+5Ch] [rbp-3Dh]
  int v336; // [rsp+5Ch] [rbp-3Dh]
  unsigned int v337; // [rsp+60h] [rbp-39h]
  int v338; // [rsp+60h] [rbp-39h]
  int Dst; // [rsp+70h] [rbp-29h] BYREF
  int v341; // [rsp+74h] [rbp-25h]
  int v342; // [rsp+78h] [rbp-21h]
  int v343; // [rsp+7Ch] [rbp-1Dh]
  int v344; // [rsp+80h] [rbp-19h]
  int v345; // [rsp+84h] [rbp-15h]
  int v346; // [rsp+88h] [rbp-11h]
  int v347; // [rsp+8Ch] [rbp-Dh]
  int v348; // [rsp+90h] [rbp-9h]
  int v349; // [rsp+94h] [rbp-5h]
  int v350; // [rsp+98h] [rbp-1h]
  int v351; // [rsp+9Ch] [rbp+3h]
  int v352; // [rsp+A0h] [rbp+7h]
  int v353; // [rsp+A4h] [rbp+Bh]
  int v354; // [rsp+A8h] [rbp+Fh]
  int v355; // [rsp+ACh] [rbp+13h]

  v2 = state;
  memmove(&Dst, buffer, 0x40ui64);
  v3 = v2[2];
  v4 = v2[3];
  v5 = __ROL4__(Dst, 8) & 0xFF00FF | __ROR4__(Dst, 8) & 0xFF00FF00;
  v6 = v5 + 1518500249;
  v333 = v5;
  v7 = __ROR4__(v2[1], 2);
  v8 = v2[4] + __ROL4__(*v2, 5) + (v4 ^ v2[1] & (v3 ^ v4)) + v6;
  v301 = __ROL4__(v341, 8) & 0xFF00FF | __ROR4__(v341, 8) & 0xFF00FF00;
  v9 = v4 + 1518500249 + v301 + __ROL4__(v8, 5) + (v3 ^ *v2 & (v7 ^ v3));
  v10 = __ROR4__(*v2, 2);
  v11 = (v7 ^ v8 & (v10 ^ v7)) + 1518500249;
  v12 = __ROR4__(v8, 2);
  v310 = __ROL4__(v342, 8) & 0xFF00FF | __ROR4__(v342, 8) & 0xFF00FF00;
  v13 = v3 + v11 + __ROL4__(v9, 5) + v310;
  v292 = __ROL4__(v343, 8) & 0xFF00FF | __ROR4__(v343, 8) & 0xFF00FF00;
  v14 = v9 & (v10 ^ v12);
  v15 = __ROR4__(v9, 2);
  v16 = v292 + __ROL4__(v13, 5) + (v10 ^ v14) + v7 + 1518500249;
  v17 = v12 ^ v13 & (v15 ^ v12);
  v297 = __ROL4__(v344, 8) & 0xFF00FF | __ROR4__(v344, 8) & 0xFF00FF00;
  v18 = __ROR4__(v13, 2);
  v19 = v297 + __ROL4__(v16, 5) + v17 + v10 + 1518500249;
  v20 = v15 ^ v16 & (v18 ^ v15);
  v317 = __ROL4__(v345, 8) & 0xFF00FF | __ROR4__(v345, 8) & 0xFF00FF00;
  v21 = __ROR4__(v16, 2);
  v22 = v317 + 1518500249 + __ROL4__(v19, 5) + v20 + v12;
  v23 = v18 ^ v19 & (v21 ^ v18);
  v337 = __ROL4__(v346, 8) & 0xFF00FF | __ROR4__(v346, 8) & 0xFF00FF00;
  v24 = __ROR4__(v19, 2);
  v25 = v337 + 1518500249 + __ROL4__(v22, 5) + v23 + v15;
  v331 = __ROL4__(v347, 8) & 0xFF00FF | __ROR4__(v347, 8) & 0xFF00FF00;
  v26 = v331 + __ROL4__(v25, 5) + 1518500249 + (v21 ^ v22 & (v24 ^ v21));
  v27 = __ROR4__(v22, 2);
  v28 = v26 + v18;
  v29 = v24 ^ v25 & (v24 ^ v27);
  v30 = __ROR4__(v25, 2);
  v288 = __ROL4__(v348, 8) & 0xFF00FF | __ROR4__(v348, 8) & 0xFF00FF00;
  v31 = v288 + __ROL4__(v28, 5) + 1518500249 + v29 + v21;
  v32 = v27 ^ v28 & (v30 ^ v27);
  v33 = __ROR4__(v28, 2);
  v284 = __ROL4__(v349, 8) & 0xFF00FF | __ROR4__(v349, 8) & 0xFF00FF00;
  v34 = v284 + __ROL4__(v31, 5) + 1518500249 + v32 + v24;
  v314 = __ROL4__(v350, 8) & 0xFF00FF | __ROR4__(v350, 8) & 0xFF00FF00;
  v35 = v30 ^ v31 & (v33 ^ v30);
  v36 = __ROR4__(v31, 2);
  v37 = v27 + 1518500249 + v35 + __ROL4__(v34, 5) + v314;
  v38 = v34 & (v36 ^ v33);
  v39 = __ROR4__(v34, 2);
  v306 = __ROL4__(v351, 8) & 0xFF00FF | __ROR4__(v351, 8) & 0xFF00FF00;
  v40 = v30 + 1518500249 + v306 + __ROL4__(v37, 5) + (v33 ^ v38);
  v41 = v36 ^ v37 & (v39 ^ v36);
  v324 = __ROL4__(v352, 8) & 0xFF00FF | __ROR4__(v352, 8) & 0xFF00FF00;
  v42 = __ROR4__(v37, 2);
  v43 = v33 + 1518500249 + v324 + __ROL4__(v40, 5) + v41;
  v44 = v39 ^ v40 & (v39 ^ v42);
  v45 = __ROR4__(v40, 2);
  v46 = v42 ^ v43 & (v45 ^ v42);
  v327 = __ROL4__(v353, 8) & 0xFF00FF | __ROR4__(v353, 8) & 0xFF00FF00;
  v47 = __ROL4__(v43, 5);
  v48 = __ROR4__(v43, 2);
  v49 = v36 + 1518500249 + v327 + v47 + v44;
  v276 = __ROL4__(v354, 8) & 0xFF00FF | __ROR4__(v354, 8) & 0xFF00FF00;
  v50 = v39 + 1518500249 + v46 + __ROL4__(v49, 5) + v276;
  v51 = v45 ^ v49 & (v48 ^ v45);
  v52 = __ROR4__(v49, 2);
  v280 = __ROL4__(v355, 8) & 0xFF00FF | __ROR4__(v355, 8) & 0xFF00FF00;
  v53 = v42 + 1518500249 + v51 + __ROL4__(v50, 5) + v280;
  v320 = __ROL4__(v333 ^ v310 ^ v288 ^ v327, 1);
  v54 = v292 ^ v317 ^ v306;
  v293 = __ROL4__(v301 ^ v292 ^ v284 ^ v276, 1);
  v55 = v50 & (v52 ^ v48);
  v56 = __ROR4__(v50, 2);
  v57 = __ROL4__(v320 ^ v54, 1);
  v58 = v320 + __ROL4__(v53, 5) + 1518500249 + (v48 ^ v55) + v45;
  v302 = __ROL4__(v310 ^ v297 ^ v314 ^ v280, 1);
  v59 = __ROL4__(v293 ^ v297 ^ v337 ^ v324, 1);
  v60 = v52 ^ v53 & (v56 ^ v52);
  v61 = __ROR4__(v53, 2);
  v62 = v293 + __ROL4__(v58, 5) + 1518500249 + v60 + v48;
  v63 = v56 ^ v58 & (v56 ^ v61);
  v64 = __ROR4__(v58, 2);
  v65 = v302 + __ROL4__(v62, 5) + 1518500249 + v63 + v52;
  v66 = v57 + __ROL4__(v65, 5) + 1518500249 + (v61 ^ v62 & (v64 ^ v61)) + v56;
  v67 = __ROR4__(v62, 2);
  v68 = v65 ^ v67 ^ v64;
  v69 = __ROR4__(v65, 2);
  v70 = v59 + __ROL4__(v66, 5) + 1859775393 + v68 + v61;
  v311 = __ROL4__(v302 ^ v317 ^ v331 ^ v327, 1);
  v71 = __ROL4__(v320 ^ v311 ^ v288 ^ v314, 1);
  v72 = v311 + __ROL4__(v70, 5) + 1859775393 + (v66 ^ v69 ^ v67) + v64;
  v73 = __ROR4__(v66, 2);
  v74 = v69 ^ v70;
  v75 = __ROR4__(v70, 2);
  v76 = __ROL4__(v57 ^ v337 ^ v288 ^ v276, 1);
  v77 = __ROL4__(v59 ^ v331 ^ v284 ^ v280, 1);
  v78 = v76 + __ROL4__(v72, 5) + 1859775393 + (v73 ^ v74) + v67;
  v79 = v72 ^ v75;
  v80 = __ROR4__(v72, 2);
  v81 = __ROL4__(v293 ^ v76 ^ v284 ^ v306, 1);
  v82 = v77 + __ROL4__(v78, 5) + 1859775393 + (v73 ^ v79) + v69;
  v83 = v78 ^ v80 ^ v75;
  v84 = __ROR4__(v78, 2);
  v85 = v71 + __ROL4__(v82, 5) + 1859775393 + v83 + v73;
  v86 = v82 ^ v84 ^ v80;
  v87 = __ROR4__(v82, 2);
  v88 = v81 + __ROL4__(v85, 5) + 1859775393 + v86 + v75;
  v289 = __ROL4__(v302 ^ v77 ^ v314 ^ v324, 1);
  v89 = v85 ^ v87 ^ v84;
  v90 = __ROR4__(v85, 2);
  v91 = v289 + 1859775393 + __ROL4__(v88, 5) + v89 + v80;
  v92 = v87 ^ v88;
  v93 = __ROR4__(v88, 2);
  v307 = __ROL4__(v57 ^ v71 ^ v306 ^ v327, 1);
  v94 = v307 + 1859775393 + __ROL4__(v91, 5) + (v90 ^ v92) + v84;
  v95 = v90 ^ v91 ^ v93;
  v298 = __ROL4__(v59 ^ v81 ^ v324 ^ v276, 1);
  v96 = __ROR4__(v91, 2);
  v97 = v298 + 1859775393 + __ROL4__(v94, 5) + v95 + v87;
  v98 = v94 ^ v96 ^ v93;
  v99 = __ROR4__(v94, 2);
  v285 = __ROL4__(v311 ^ v289 ^ v327 ^ v280, 1);
  v100 = v285 + 1859775393 + __ROL4__(v97, 5) + v98 + v90;
  v101 = v97 ^ v99 ^ v96;
  v277 = __ROL4__(v320 ^ v76 ^ v307 ^ v276, 1);
  v102 = __ROR4__(v97, 2);
  v103 = v277 + 1859775393 + __ROL4__(v100, 5) + v101 + v93;
  v281 = __ROL4__(v293 ^ v77 ^ v298 ^ v280, 1);
  v104 = v100 ^ v102 ^ v99;
  v105 = __ROR4__(v100, 2);
  v106 = v281 + 1859775393 + __ROL4__(v103, 5) + v104 + v96;
  v107 = v102 ^ v103;
  v108 = __ROR4__(v103, 2);
  v321 = __ROL4__(v320 ^ v302 ^ v71 ^ v285, 1);
  v109 = v321 + 1859775393 + __ROL4__(v106, 5) + (v105 ^ v107) + v99;
  v110 = v106 ^ v108;
  v111 = __ROR4__(v106, 2);
  v328 = __ROL4__(v293 ^ v57 ^ v81 ^ v277, 1);
  v112 = v328 + 1859775393 + __ROL4__(v109, 5) + (v105 ^ v110) + v102;
  v113 = v109 ^ v111 ^ v108;
  v334 = __ROL4__(v302 ^ v59 ^ v289 ^ v281, 1);
  v114 = __ROR4__(v109, 2);
  v115 = v334 + __ROL4__(v112, 5) + 1859775393 + v113 + v105;
  v116 = v112 ^ v114 ^ v111;
  v318 = __ROL4__(v321 ^ v57 ^ v311 ^ v307, 1);
  v117 = __ROR4__(v112, 2);
  v118 = v298;
  v119 = v318 + 1859775393 + __ROL4__(v115, 5) + v116 + v108;
  v299 = __ROL4__(v328 ^ v59 ^ v76 ^ v298, 1);
  v120 = v115 ^ v117 ^ v114;
  v121 = __ROR4__(v115, 2);
  v122 = v299 + __ROL4__(v119, 5) + 1859775393 + v120 + v111;
  v123 = v121 ^ v117 ^ v119;
  v124 = __ROR4__(v119, 2);
  v332 = __ROL4__(v334 ^ v311 ^ v77 ^ v285, 1);
  v125 = v332 + 1859775393 + __ROL4__(v122, 5) + v123 + v114;
  v126 = v121 ^ v122 ^ v124;
  v303 = __ROL4__(v318 ^ v76 ^ v71 ^ v277, 1);
  v127 = __ROR4__(v122, 2);
  v128 = v125 ^ v127 ^ v124;
  v129 = v303 + 1859775393 + __ROL4__(v125, 5) + v126 + v117;
  LODWORD(v2) = v77 ^ v81 ^ v281;
  v130 = __ROR4__(v125, 2);
  v131 = v332 ^ v71 ^ v289;
  v132 = v307;
  LODWORD(v2) = __ROL4__(v299 ^ (unsigned int)v2, 1);
  v315 = __ROL4__(v321 ^ v131, 1);
  v133 = v121 + 1859775393 + (_DWORD)v2 + __ROL4__(v129, 5) + v128;
  v294 = (int)v2;
  v134 = v315 + (v129 & v130 | v127 & (v129 | v130));
  v135 = __ROR4__(v129, 2);
  v136 = v124 + v134 + __ROL4__(v133, 5) - 1894007588;
  v137 = __ROL4__(v328 ^ v303 ^ v81 ^ v307, 1);
  v138 = v334;
  v325 = v137;
  v139 = v137 + (v133 & v135 | v130 & (v133 | v135));
  v140 = __ROR4__(v133, 2);
  v141 = (unsigned int)v2 ^ v289 ^ v118;
  LODWORD(v2) = v285;
  v142 = v127 + v139 + __ROL4__(v136, 5) - 1894007588;
  v308 = __ROL4__(v334 ^ v141, 1);
  v143 = v140 & v136;
  v144 = v135 & (v140 | v136);
  v145 = __ROR4__(v136, 2);
  v146 = v130 + v308 + (v143 | v144) + __ROL4__(v142, 5) - 1894007588;
  v286 = __ROL4__(v318 ^ v315 ^ v132 ^ v285, 1);
  v147 = v286 + (v142 & v145 | v140 & (v142 | v145));
  v148 = __ROR4__(v142, 2);
  v149 = v135 + v147 + __ROL4__(v146, 5) - 1894007588;
  v290 = __ROL4__(v299 ^ v325 ^ v118 ^ v277, 1);
  v150 = v140 + v290 + (v146 & v148 | v145 & (v146 | v148)) + __ROL4__(v149, 5) - 1894007588;
  v151 = __ROR4__(v146, 2);
  v312 = __ROL4__(v332 ^ v308 ^ (unsigned int)v2 ^ v281, 1);
  v152 = v149 & v151 | v148 & (v149 | v151);
  v153 = __ROR4__(v149, 2);
  v278 = __ROL4__(v321 ^ v303 ^ v286 ^ v277, 1);
  v154 = v145 + v312 + v152 + __ROL4__(v150, 5) - 1894007588;
  v155 = v150 & v153 | v151 & (v150 | v153);
  v156 = __ROR4__(v150, 2);
  v157 = v148 + v278 + v155 + __ROL4__(v154, 5) - 1894007588;
  v282 = __ROL4__(v328 ^ v294 ^ v290 ^ v281, 1);
  v158 = v282 + (v156 & v154 | v153 & (v156 | v154));
  v159 = __ROR4__(v154, 2);
  v160 = v151 + v158 + __ROL4__(v157, 5) - 1894007588;
  v335 = __ROL4__(v321 ^ v334 ^ v315 ^ v312, 1);
  v322 = __ROL4__(v328 ^ v318 ^ v325 ^ v278, 1);
  v161 = v157 & v159 | v156 & (v157 | v159);
  v162 = __ROR4__(v157, 2);
  v163 = v153 + v335 + v161 + __ROL4__(v160, 5) - 1894007588;
  v164 = v159 & (v160 | v162);
  v165 = v160 & v162;
  v166 = __ROR4__(v160, 2);
  v167 = v322 + (v165 | v164);
  v168 = v163 & v166;
  v169 = v156 + v167 + __ROL4__(v163, 5) - 1894007588;
  v170 = v162 & (v163 | v166);
  v171 = __ROR4__(v163, 2);
  LODWORD(v2) = __ROL4__(v138 ^ v299 ^ v308 ^ v282, 1);
  v172 = v159 + (_DWORD)v2 + (v168 | v170);
  v173 = __ROL4__(v322 ^ v299 ^ v303 ^ v290, 1);
  v174 = v169 & v171;
  v319 = __ROL4__(v335 ^ v318 ^ v332 ^ v286, 1);
  v175 = v172 + __ROL4__(v169, 5) - 1894007588;
  v176 = v169 | v171;
  v177 = __ROR4__(v169, 2);
  v329 = __ROL4__((unsigned int)v2 ^ v332 ^ v294 ^ v312, 1);
  v178 = v174 | v166 & v176;
  v179 = v177 & v175;
  v180 = v162 + v319 + v178 + __ROL4__(v175, 5) - 1894007588;
  v181 = v177 | v175;
  v182 = __ROR4__(v175, 2);
  v183 = v166 + v173 + (v179 | v171 & v181) + __ROL4__(v180, 5) - 1894007588;
  v184 = v329 + (v180 & v182 | v177 & (v180 | v182)) - 1894007588;
  v185 = __ROR4__(v180, 2);
  v186 = __ROL4__(v183, 5) + v184 + v171;
  v187 = v183 & v185 | v182 & (v183 | v185);
  v188 = __ROR4__(v183, 2);
  v304 = __ROL4__(v319 ^ v303 ^ v315 ^ v278, 1);
  v189 = v186 & v188;
  v190 = v177 - 1894007588 + v304 + v187 + __ROL4__(v186, 5);
  v295 = __ROL4__(v173 ^ v294 ^ v325 ^ v282, 1);
  v191 = v186 | v188;
  v192 = __ROR4__(v186, 2);
  v193 = v182 - 1894007588 + v295 + (v189 | v185 & v191) + __ROL4__(v190, 5);
  v316 = __ROL4__(v335 ^ v329 ^ v315 ^ v308, 1);
  v194 = v185 + v316 + (v190 & v192 | v188 & (v190 | v192));
  v195 = __ROR4__(v190, 2);
  v196 = v194 + __ROL4__(v193, 5) - 1894007588;
  v326 = __ROL4__(v322 ^ v304 ^ v325 ^ v286, 1);
  v197 = v326 + (v195 & v193 | v192 & (v195 | v193));
  v198 = __ROR4__(v193, 2);
  v199 = v188 + v197 + __ROL4__(v196, 5) - 1894007588;
  v200 = v196 & v198;
  v201 = __ROL4__((unsigned int)v2 ^ v295 ^ v308 ^ v290, 1);
  v202 = v195 & (v196 | v198);
  v203 = __ROR4__(v196, 2);
  v204 = v192 + v201 + (v200 | v202);
  v205 = v199 & v203;
  v338 = v201;
  v206 = v204 + __ROL4__(v199, 5) - 1894007588;
  v207 = v199 | v203;
  v208 = __ROR4__(v199, 2);
  v209 = v205 | v198 & v207;
  v309 = __ROL4__(v319 ^ v316 ^ v286 ^ v312, 1);
  v210 = __ROL4__(v206, 5);
  v291 = __ROL4__(v173 ^ v326 ^ v290 ^ v278, 1);
  v211 = v198 - 899497514 + v291 + (v206 ^ v208 ^ v203);
  v212 = __ROR4__(v206, 2);
  v213 = v195 + v309 + v209 - 1894007588 + v210;
  v313 = __ROL4__(v329 ^ v201 ^ v312 ^ v282, 1);
  v214 = v211 + __ROL4__(v213, 5);
  v279 = __ROL4__(v335 ^ v304 ^ v309 ^ v278, 1);
  v215 = v203 + v313 + (v213 ^ v212 ^ v208) + __ROL4__(v214, 5) - 899497514;
  v216 = __ROR4__(v213, 2);
  v217 = v279 + (v216 ^ v212 ^ v214);
  v218 = __ROR4__(v214, 2);
  v219 = v208 + v217 + __ROL4__(v215, 5) - 899497514;
  v220 = v216 ^ v215 ^ v218;
  v287 = __ROL4__(v322 ^ v319 ^ v326 ^ v279, 1);
  v221 = __ROR4__(v215, 2);
  v283 = __ROL4__(v322 ^ v295 ^ v291 ^ v282, 1);
  v222 = v173 ^ v201 ^ v283;
  v223 = v329;
  v224 = v212 + v283 + v220 + __ROL4__(v219, 5) - 899497514;
  v225 = v219 ^ v221 ^ v218;
  v226 = __ROR4__(v219, 2);
  v227 = __ROL4__(v335 ^ (unsigned int)v2 ^ v316 ^ v313, 1);
  v228 = v216 + v227 + v225 + __ROL4__(v224, 5) - 899497514;
  v323 = v227;
  v300 = __ROL4__((unsigned int)v2 ^ v222, 1);
  v330 = __ROL4__(v227 ^ v319 ^ v329 ^ v309, 1);
  v229 = v218 + v287 + (v224 ^ v226 ^ v221) + __ROL4__(v228, 5) - 899497514;
  v230 = __ROR4__(v224, 2);
  v231 = v221 + v300 + (v228 ^ v230 ^ v226) + __ROL4__(v229, 5) - 899497514;
  v232 = __ROR4__(v228, 2);
  v233 = v226 + v330 + (v232 ^ v230 ^ v229);
  v234 = __ROR4__(v229, 2);
  v235 = v304;
  v236 = v233 + __ROL4__(v231, 5) - 899497514;
  v237 = __ROL4__(v287 ^ v173 ^ v304 ^ v291, 1);
  v238 = v237 + (v232 ^ v231 ^ v234) - 899497514;
  v239 = __ROR4__(v231, 2);
  v240 = v238 + v230;
  v336 = __ROL4__(v300 ^ v223 ^ v295 ^ v313, 1);
  v305 = v237;
  v241 = __ROL4__(v236, 5);
  v242 = v232 + v336 - 899497514 + (v236 ^ v239 ^ v234);
  v243 = __ROR4__(v236, 2);
  v244 = v241 + v240;
  v245 = v242 + __ROL4__(v244, 5);
  v246 = __ROL4__(v237 ^ v295 ^ v326 ^ v283, 1);
  v247 = v244 ^ v243 ^ v239;
  v296 = __ROL4__(v330 ^ v235 ^ v316 ^ v279, 1);
  v248 = __ROR4__(v244, 2);
  v249 = v234 + v296 + v247 - 899497514 + __ROL4__(v245, 5);
  v250 = __ROL4__(v323 ^ v336 ^ v316 ^ v338, 1);
  v251 = v239 + v246 + (v245 ^ v248 ^ v243) - 899497514;
  v252 = __ROR4__(v245, 2);
  v253 = v251 + __ROL4__(v249, 5);
  v254 = v243 - 899497514 + v250 + (v252 ^ v248 ^ v249);
  v255 = __ROR4__(v249, 2);
  v256 = v254 + __ROL4__(v253, 5);
  v257 = __ROL4__(v330 ^ v250 ^ v309 ^ v313, 1);
  v258 = v252 ^ v253 ^ v255;
  v259 = __ROL4__(v287 ^ v296 ^ v326 ^ v309, 1);
  v260 = __ROR4__(v253, 2);
  LODWORD(v2) = v248 - 899497514 + v259 + v258 + __ROL4__(v256, 5);
  v261 = v256 ^ v260 ^ v255;
  v262 = __ROR4__(v256, 2);
  v263 = __ROL4__(v300 ^ v246 ^ v338 ^ v291, 1);
  v264 = v252 - 899497514 + v263 + v261 + __ROL4__((_DWORD)v2, 5);
  v265 = __ROL4__(v305 ^ v259 ^ v291 ^ v279, 1);
  v266 = v255 - 899497514 + v257 + ((unsigned int)v2 ^ v262 ^ v260) + __ROL4__(v264, 5);
  LODWORD(v2) = __ROR4__((_DWORD)v2, 2);
  v267 = v264 ^ (unsigned int)v2 ^ v262;
  v268 = __ROR4__(v264, 2);
  v269 = v260 + v265 + v267 - 899497514 + __ROL4__(v266, 5);
  v270 = v266;
  v271 = __ROR4__(v266, 2);
  v272 = v262
       + (v268 ^ (unsigned int)v2 ^ v270)
       - 899497514
       + __ROL4__(v269, 5)
       + __ROL4__(v336 ^ v263 ^ v313 ^ v283, 1);
  v273 = v268 ^ v269 ^ v271;
  v274 = __ROR4__(v269, 2);
  state[3] += v274;
  v275 = (_DWORD)v2 + v273 - 899497514 + __ROL4__(v272, 5) + __ROL4__(v323 ^ v296 ^ v279 ^ v257, 1);
  state[1] += v275;
  state[2] += __ROR4__(v272, 2);
  *state += __ROL4__(v275, 5) + __ROL4__(v287 ^ v246 ^ v265 ^ v283, 1) - 899497514 + v268 + (v272 ^ v274 ^ v271);
  state[4] += v271;
}

// File Line: 113
// RVA: 0xEF26FC
void __fastcall SHA1_Init(SHA1_CTX *context)
{
  context->count[1] = 0;
  context->count[0] = 0;
  context->state[0] = 1732584193;
  context->state[1] = -271733879;
  context->state[2] = -1732584194;
  context->state[3] = 271733878;
  context->state[4] = -1009589776;
}

// File Line: 146
// RVA: 0xEF2728
void __fastcall SHA1_Update(SHA1_CTX *context, const char *data, unsigned int len)
{
  unsigned int v5; // r9d
  unsigned int v7; // ecx
  unsigned int v8; // edi
  unsigned int i; // ebp

  v5 = context->count[0] + 8 * len;
  v7 = (context->count[0] >> 3) & 0x3F;
  context->count[0] = v5;
  if ( v5 < 8 * len )
    ++context->count[1];
  context->count[1] += len >> 29;
  if ( v7 + len <= 0x3F )
  {
    v8 = 0;
  }
  else
  {
    v8 = 64 - v7;
    memmove(&context->buffer[v7], data, 64 - v7);
    FSHA1Transform(context->state, context->buffer);
    for ( i = v8 + 63; i < len; i += 64 )
    {
      FSHA1Transform(context->state, &data[v8]);
      v8 += 64;
    }
    v7 = 0;
  }
  memmove(&context->buffer[v7], &data[v8], len - v8);
}

// File Line: 168
// RVA: 0xEF25B0
void __fastcall SHA1_Final(char *digest, SHA1_CTX *context)
{
  unsigned int v2; // ebx
  unsigned int v5; // r8d
  char *v6; // r9
  char v7; // cl
  _BOOL8 v8; // rax
  unsigned __int64 v9; // r8
  char v10; // al
  char v11; // cl
  unsigned __int64 v12; // rax
  char data[8]; // [rsp+20h] [rbp-28h] BYREF

  v2 = 0;
  v5 = 0;
  v6 = data;
  do
  {
    v7 = 8 * (3 - (v5 & 3));
    v8 = v5++ < 4;
    *v6++ = context->count[v8] >> v7;
  }
  while ( v5 < 8 );
  SHA1_Update(context, "€", 1u);
  while ( (context->count[0] & 0x1F8) != 448 )
    SHA1_Update(context, byte_1416A7BD8, 1u);
  SHA1_Update(context, data, 8u);
  v9 = 0i64;
  do
  {
    v10 = v2++;
    v11 = 3 - (v10 & 3);
    v12 = v9++;
    *digest++ = context->state[v12 >> 2] >> (8 * v11);
  }
  while ( v2 < 0x14 );
  memset(context->buffer, 0, sizeof(context->buffer));
  memset(context, 0, 0x14ui64);
  memset(context->count, 0, sizeof(context->count));
  memset(data, 0, sizeof(data));
  FSHA1Transform(context->state, context->buffer);
}

