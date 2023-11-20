// File Line: 58
// RVA: 0xEF1440
void __fastcall FSHA1Transform(unsigned int *state, const char *buffer)
{
  unsigned int *v2; // rsi
  unsigned int *v3; // ST68_8
  unsigned int v4; // edi
  unsigned int v5; // ebx
  int v6; // edx
  unsigned int v7; // er9
  unsigned int v8; // ST38_4
  int v9; // er10
  int v10; // er8
  int v11; // ecx
  unsigned int v12; // er11
  unsigned int v13; // ST40_4
  int v14; // er11
  unsigned int v15; // ST30_4
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  unsigned int v19; // ST34_4
  int v20; // er8
  int v21; // ecx
  unsigned int v22; // ST48_4
  int v23; // er9
  int v24; // ecx
  unsigned int v25; // ST60_4
  int v26; // er10
  unsigned int v27; // ST58_4
  int v28; // ecx
  int v29; // er11
  int v30; // ecx
  unsigned int v31; // ST2C_4
  int v32; // edx
  int v33; // ecx
  unsigned int v34; // ST28_4
  int v35; // er8
  unsigned int v36; // ebx
  unsigned int v37; // ST44_4
  int v38; // ecx
  int v39; // ebx
  int v40; // er9
  unsigned int v41; // ST3C_4
  int v42; // er9
  int v43; // er10
  unsigned int v44; // er10
  int v45; // er11
  int v46; // ecx
  unsigned int v47; // ST54_4
  int v48; // er11
  int v49; // er11
  unsigned int v50; // edx
  unsigned int v51; // ST20_4
  int v52; // edx
  unsigned int v53; // er8
  int v54; // ecx
  unsigned int v55; // ST24_4
  int v56; // er8
  int v57; // ST4C_4
  int v58; // er12
  int v59; // ST30_4
  int v60; // ecx
  int v61; // er12
  int v62; // er9
  int v63; // ST38_4
  int v64; // ebx
  int v65; // ecx
  int v66; // er10
  int v67; // ecx
  int v68; // er11
  int v69; // edx
  int v70; // ecx
  int v71; // er8
  int v72; // ST40_4
  int v73; // edi
  int v74; // er9
  int v75; // ecx
  int v76; // er14
  int v77; // er15
  int v78; // er10
  int v79; // ecx
  int v80; // er13
  int v81; // er11
  int v82; // ecx
  int v83; // edx
  int v84; // ecx
  int v85; // er8
  int v86; // ST2C_4
  int v87; // ecx
  int v88; // er9
  int v89; // ecx
  int v90; // ST3C_4
  int v91; // er10
  int v92; // ecx
  int v93; // ST34_4
  int v94; // er11
  int v95; // ecx
  int v96; // ST28_4
  int v97; // edx
  int v98; // ecx
  int v99; // ST20_4
  int v100; // er8
  int v101; // ST24_4
  int v102; // ecx
  int v103; // er9
  int v104; // ecx
  int v105; // ST4C_4
  int v106; // er10
  int v107; // ecx
  int v108; // ST54_4
  int v109; // er11
  int v110; // ecx
  int v111; // ST5C_4
  int v112; // edx
  int v113; // ecx
  int v114; // ST48_4
  int v115; // eax
  int v116; // er12
  int v117; // er8
  int v118; // ST34_4
  int v119; // ecx
  int v120; // er9
  int v121; // ecx
  int v122; // ST58_4
  int v123; // er10
  int v124; // ecx
  int v125; // ST38_4
  int v126; // ebx
  int v127; // er11
  int v128; // er15
  int v129; // edi
  int v130; // ST44_4
  int v131; // ebx
  int v132; // ST30_4
  int v133; // ecx
  int v134; // er8
  int v135; // eax
  int v136; // er13
  int v137; // ST50_4
  int v138; // ecx
  unsigned int v139; // eax
  int v140; // er9
  int v141; // ST3C_4
  int v142; // eax
  int v143; // ecx
  int v144; // er10
  int v145; // ST28_4
  int v146; // ecx
  int v147; // er11
  int v148; // ST2C_4
  int v149; // ebx
  int v150; // ST40_4
  int v151; // ecx
  int v152; // ST20_4
  int v153; // er8
  int v154; // ecx
  int v155; // er9
  int v156; // ST24_4
  int v157; // ecx
  int v158; // er10
  int v159; // ST5C_4
  int v160; // ST4C_4
  int v161; // ecx
  int v162; // er11
  int v163; // ecx
  int v164; // eax
  int v165; // ecx
  int v166; // eax
  int v167; // ebx
  int v168; // ecx
  int v169; // ecx
  int v170; // er12
  int v171; // eax
  unsigned int v172; // er14
  int v173; // ST34_4
  int v174; // ST48_4
  int v175; // er8
  int v176; // ecx
  int v177; // ecx
  int v178; // eax
  int v179; // er9
  int v180; // ecx
  int v181; // er10
  int v182; // ecx
  int v183; // er11
  int v184; // ecx
  int v185; // ST38_4
  int v186; // eax
  int v187; // edi
  int v188; // ST30_4
  int v189; // ecx
  int v190; // ebx
  int v191; // ST44_4
  int v192; // ecx
  int v193; // er9
  int v194; // ST50_4
  int v195; // ecx
  int v196; // er10
  int v197; // eax
  int v198; // er13
  int v199; // ecx
  int v200; // ecx
  int v201; // eax
  int v202; // ST60_4
  int v203; // er11
  int v204; // ecx
  int v205; // ecx
  int v206; // ST3C_4
  int v207; // er8
  int v208; // ST2C_4
  int v209; // eax
  int v210; // er8
  int v211; // ST40_4
  int v212; // edx
  int v213; // ST20_4
  int v214; // er9
  int v215; // eax
  int v216; // er10
  int v217; // eax
  int v218; // ST28_4
  int v219; // ST24_4
  int v220; // ebx
  int v221; // er13
  int v222; // er11
  int v223; // eax
  int v224; // er14
  int v225; // er8
  int v226; // ST4C_4
  int v227; // ST34_4
  int v228; // ST54_4
  int v229; // edx
  int v230; // er9
  int v231; // eax
  int v232; // er15
  int v233; // er10
  int v234; // er14
  int v235; // eax
  int v236; // er11
  int v237; // ST5C_4
  int v238; // ST38_4
  int v239; // ecx
  int v240; // eax
  int v241; // er11
  int v242; // ebx
  int v243; // er13
  int v244; // eax
  int v245; // ST30_4
  int v246; // er15
  int v247; // er8
  int v248; // eax
  int v249; // er12
  int v250; // eax
  int v251; // er14
  int v252; // edx
  int v253; // eax
  int v254; // er10
  int v255; // eax
  int v256; // er11
  int v257; // edi
  int v258; // er9
  unsigned int v259; // ebx
  unsigned int v260; // eax
  int v261; // er10
  int v262; // er8
  unsigned int v263; // eax
  unsigned int v264; // er8
  int v265; // er15
  unsigned int *v266; // r9
  int v267; // eax
  int v268; // edx
  int Dst; // [rsp+70h] [rbp-29h]
  int v270; // [rsp+74h] [rbp-25h]
  int v271; // [rsp+78h] [rbp-21h]
  int v272; // [rsp+7Ch] [rbp-1Dh]
  int v273; // [rsp+80h] [rbp-19h]
  int v274; // [rsp+84h] [rbp-15h]
  int v275; // [rsp+88h] [rbp-11h]
  int v276; // [rsp+8Ch] [rbp-Dh]
  int v277; // [rsp+90h] [rbp-9h]
  int v278; // [rsp+94h] [rbp-5h]
  int v279; // [rsp+98h] [rbp-1h]
  int v280; // [rsp+9Ch] [rbp+3h]
  int v281; // [rsp+A0h] [rbp+7h]
  int v282; // [rsp+A4h] [rbp+Bh]
  int v283; // [rsp+A8h] [rbp+Fh]
  int v284; // [rsp+ACh] [rbp+13h]

  v2 = state;
  v3 = state;
  memmove(&Dst, buffer, 0x40ui64);
  v4 = v2[2];
  v5 = v2[3];
  v6 = __ROR4__(v2[1], 2);
  v7 = v2[4]
     + __ROL4__(*v2, 5)
     + (v5 ^ v2[1] & (v4 ^ v2[3]))
     + (__ROL4__(Dst, 8) & 0xFF00FF | __ROR4__(Dst, 8) & 0xFF00FF00)
     + 1518500249;
  v8 = __ROL4__(v270, 8) & 0xFF00FF | __ROR4__(v270, 8) & 0xFF00FF00;
  v9 = v5 + 1518500249 + v8 + __ROL4__(v7, 5) + (v4 ^ *v2 & (v6 ^ v4));
  v10 = __ROR4__(*v2, 2);
  v11 = (v6 ^ v7 & (v10 ^ v6)) + 1518500249;
  v7 = __ROR4__(v7, 2);
  v12 = __ROL4__(v271, 8) & 0xFF00FF | __ROR4__(v271, 8) & 0xFF00FF00;
  v13 = v12;
  v14 = v4 + v11 + __ROL4__(v9, 5) + v12;
  v15 = __ROL4__(v272, 8) & 0xFF00FF | __ROR4__(v272, 8) & 0xFF00FF00;
  v16 = v9 & (v10 ^ v7);
  v9 = __ROR4__(v9, 2);
  v17 = v15 + __ROL4__(v14, 5) + (v10 ^ v16) + v6 + 1518500249;
  v18 = v7 ^ v14 & (v9 ^ v7);
  v19 = __ROL4__(v273, 8) & 0xFF00FF | __ROR4__(v273, 8) & 0xFF00FF00;
  v14 = __ROR4__(v14, 2);
  v20 = v19 + __ROL4__(v17, 5) + v18 + v10 + 1518500249;
  v21 = v9 ^ v17 & (v14 ^ v9);
  v22 = __ROL4__(v274, 8) & 0xFF00FF | __ROR4__(v274, 8) & 0xFF00FF00;
  v17 = __ROR4__(v17, 2);
  v23 = v22 + 1518500249 + __ROL4__(v20, 5) + v21 + v7;
  v24 = v14 ^ v20 & (v17 ^ v14);
  v25 = __ROL4__(v275, 8) & 0xFF00FF | __ROR4__(v275, 8) & 0xFF00FF00;
  v20 = __ROR4__(v20, 2);
  v26 = v25 + 1518500249 + __ROL4__(v23, 5) + v24 + v9;
  v27 = __ROL4__(v276, 8) & 0xFF00FF | __ROR4__(v276, 8) & 0xFF00FF00;
  v28 = v27 + __ROL4__(v26, 5) + 1518500249 + (v17 ^ v23 & (v20 ^ v17));
  v23 = __ROR4__(v23, 2);
  v29 = v28 + v14;
  v30 = v20 ^ v26 & (v20 ^ v23);
  v26 = __ROR4__(v26, 2);
  v31 = __ROL4__(v277, 8) & 0xFF00FF | __ROR4__(v277, 8) & 0xFF00FF00;
  v32 = v31 + __ROL4__(v29, 5) + 1518500249 + v30 + v17;
  v33 = v23 ^ v29 & (v26 ^ v23);
  v29 = __ROR4__(v29, 2);
  v34 = __ROL4__(v278, 8) & 0xFF00FF | __ROR4__(v278, 8) & 0xFF00FF00;
  v35 = v34 + __ROL4__(v32, 5) + 1518500249 + v33 + v20;
  v36 = __ROL4__(v279, 8) & 0xFF00FF | __ROR4__(v279, 8) & 0xFF00FF00;
  v37 = v36;
  v38 = v26 ^ v32 & (v29 ^ v26);
  v32 = __ROR4__(v32, 2);
  v39 = v23 + 1518500249 + v38 + __ROL4__(v35, 5) + v36;
  v40 = v35 & (v32 ^ v29);
  v35 = __ROR4__(v35, 2);
  v41 = __ROL4__(v280, 8) & 0xFF00FF | __ROR4__(v280, 8) & 0xFF00FF00;
  v42 = v26 + 1518500249 + v41 + __ROL4__(v39, 5) + (v29 ^ v40);
  v43 = v32 ^ v39 & (v35 ^ v32);
  v39 = __ROR4__(v39, 2);
  v44 = v29 + 1518500249 + (__ROL4__(v281, 8) & 0xFF00FF | __ROR4__(v281, 8) & 0xFF00FF00) + __ROL4__(v42, 5) + v43;
  v45 = v35 ^ v42 & (v35 ^ v39);
  v42 = __ROR4__(v42, 2);
  v46 = v39 ^ v44 & (v42 ^ v39);
  v47 = __ROL4__(v282, 8) & 0xFF00FF | __ROR4__(v282, 8) & 0xFF00FF00;
  v48 = v47 + __ROL4__(v44, 5) + v45;
  v44 = __ROR4__(v44, 2);
  v49 = v32 + 1518500249 + v48;
  v50 = __ROL4__(v283, 8) & 0xFF00FF | __ROR4__(v283, 8) & 0xFF00FF00;
  v51 = v50;
  v52 = v35 + 1518500249 + v46 + __ROL4__(v49, 5) + v50;
  v53 = __ROL4__(v284, 8) & 0xFF00FF | __ROR4__(v284, 8) & 0xFF00FF00;
  v54 = v42 ^ v49 & (v44 ^ v42);
  v49 = __ROR4__(v49, 2);
  v55 = v53;
  v56 = v39 + 1518500249 + v54 + __ROL4__(v52, 5) + v53;
  v57 = __ROL4__((__ROL4__(Dst, 8) & 0xFF00FF | __ROR4__(Dst, 8) & 0xFF00FF00) ^ v13 ^ v31 ^ v47, 1);
  v58 = v15 ^ v22 ^ v41;
  v59 = __ROL4__(v8 ^ v15 ^ v34 ^ v51, 1);
  v60 = v52 & (v49 ^ v44);
  v52 = __ROR4__(v52, 2);
  v61 = __ROL4__(v57 ^ v58, 1);
  v62 = v57 + __ROL4__(v56, 5) + 1518500249 + (v44 ^ v60) + v42;
  v63 = __ROL4__(v13 ^ v19 ^ v37 ^ v55, 1);
  v64 = __ROL4__(v59 ^ v19 ^ v25 ^ (__ROL4__(v281, 8) & 0xFF00FF | __ROR4__(v281, 8) & 0xFF00FF00), 1);
  v65 = v49 ^ v56 & (v52 ^ v49);
  v56 = __ROR4__(v56, 2);
  v66 = v59 + __ROL4__(v62, 5) + 1518500249 + v65 + v44;
  v67 = v52 ^ v62 & (v52 ^ v56);
  v62 = __ROR4__(v62, 2);
  v68 = v63 + __ROL4__(v66, 5) + 1518500249 + v67 + v49;
  v69 = v61 + __ROL4__(v68, 5) + 1518500249 + (v56 ^ v66 & (v62 ^ v56)) + v52;
  v66 = __ROR4__(v66, 2);
  v70 = v68 ^ v66 ^ v62;
  v68 = __ROR4__(v68, 2);
  v71 = v64 + __ROL4__(v69, 5) + 1859775393 + v70 + v56;
  v72 = __ROL4__(v63 ^ v22 ^ v27 ^ v47, 1);
  v73 = __ROL4__(v57 ^ v72 ^ v31 ^ v37, 1);
  v74 = v72 + __ROL4__(v71, 5) + 1859775393 + (v69 ^ v68 ^ v66) + v62;
  v69 = __ROR4__(v69, 2);
  v75 = v68 ^ v71;
  v71 = __ROR4__(v71, 2);
  v76 = __ROL4__(v61 ^ v25 ^ v31 ^ v51, 1);
  v77 = __ROL4__(v64 ^ v27 ^ v34 ^ v55, 1);
  v78 = v76 + __ROL4__(v74, 5) + 1859775393 + (v69 ^ v75) + v66;
  v79 = v74 ^ v71;
  v74 = __ROR4__(v74, 2);
  v80 = __ROL4__(v59 ^ v76 ^ v34 ^ v41, 1);
  v81 = v77 + __ROL4__(v78, 5) + 1859775393 + (v69 ^ v79) + v68;
  v82 = v78 ^ v74 ^ v71;
  v78 = __ROR4__(v78, 2);
  v83 = v73 + __ROL4__(v81, 5) + 1859775393 + v82 + v69;
  v84 = v81 ^ v78 ^ v74;
  v81 = __ROR4__(v81, 2);
  v85 = v80 + __ROL4__(v83, 5) + 1859775393 + v84 + v71;
  v86 = __ROL4__(v63 ^ v77 ^ v37 ^ (__ROL4__(v281, 8) & 0xFF00FF | __ROR4__(v281, 8) & 0xFF00FF00), 1);
  v87 = v83 ^ v81 ^ v78;
  v83 = __ROR4__(v83, 2);
  v88 = v86 + 1859775393 + __ROL4__(v85, 5) + v87 + v74;
  v89 = v81 ^ v85;
  v85 = __ROR4__(v85, 2);
  v90 = __ROL4__(v61 ^ v73 ^ v41 ^ v47, 1);
  v91 = v90 + 1859775393 + __ROL4__(v88, 5) + (v83 ^ v89) + v78;
  v92 = v83 ^ v88 ^ v85;
  v93 = __ROL4__(v64 ^ v80 ^ (__ROL4__(v281, 8) & 0xFF00FF | __ROR4__(v281, 8) & 0xFF00FF00) ^ v51, 1);
  v88 = __ROR4__(v88, 2);
  v94 = v93 + 1859775393 + __ROL4__(v91, 5) + v92 + v81;
  v95 = v91 ^ v88 ^ v85;
  v91 = __ROR4__(v91, 2);
  v96 = __ROL4__(v72 ^ v86 ^ v47 ^ v55, 1);
  v97 = v96 + 1859775393 + __ROL4__(v94, 5) + v95 + v83;
  v98 = v94 ^ v91 ^ v88;
  v99 = __ROL4__(v57 ^ v76 ^ v90 ^ v51, 1);
  v94 = __ROR4__(v94, 2);
  v100 = v99 + 1859775393 + __ROL4__(v97, 5) + v98 + v85;
  v101 = __ROL4__(v59 ^ v77 ^ v93 ^ v55, 1);
  v102 = v97 ^ v94 ^ v91;
  v97 = __ROR4__(v97, 2);
  v103 = v101 + 1859775393 + __ROL4__(v100, 5) + v102 + v88;
  v104 = v94 ^ v100;
  v100 = __ROR4__(v100, 2);
  v105 = __ROL4__(v57 ^ v63 ^ v73 ^ v96, 1);
  v106 = v105 + 1859775393 + __ROL4__(v103, 5) + (v97 ^ v104) + v91;
  v107 = v103 ^ v100;
  v103 = __ROR4__(v103, 2);
  v108 = __ROL4__(v59 ^ v61 ^ v80 ^ v99, 1);
  v109 = v108 + 1859775393 + __ROL4__(v106, 5) + (v97 ^ v107) + v94;
  v110 = v106 ^ v103 ^ v100;
  LODWORD(v2) = __ROL4__(v63 ^ v64 ^ v86 ^ v101, 1);
  v111 = __ROL4__(v63 ^ v64 ^ v86 ^ v101, 1);
  v106 = __ROR4__(v106, 2);
  v112 = (_DWORD)v2 + __ROL4__(v109, 5) + 1859775393 + v110 + v97;
  v113 = v109 ^ v106 ^ v103;
  v114 = __ROL4__(v105 ^ v61 ^ v72 ^ v90, 1);
  v109 = __ROR4__(v109, 2);
  v115 = v114 + 1859775393 + __ROL4__(v112, 5);
  v116 = v93;
  v117 = v115 + v113 + v100;
  v118 = __ROL4__(v108 ^ v64 ^ v76 ^ v93, 1);
  v119 = v112 ^ v109 ^ v106;
  v112 = __ROR4__(v112, 2);
  v120 = v118 + __ROL4__(v117, 5) + 1859775393 + v119 + v103;
  v121 = v112 ^ v109 ^ v117;
  v117 = __ROR4__(v117, 2);
  v122 = __ROL4__((unsigned int)v2 ^ v72 ^ v77 ^ v96, 1);
  v123 = v122 + 1859775393 + __ROL4__(v120, 5) + v121 + v106;
  v124 = v112 ^ v120 ^ v117;
  v125 = __ROL4__(v114 ^ v76 ^ v73 ^ v99, 1);
  v120 = __ROR4__(v120, 2);
  v126 = v123 ^ v120 ^ v117;
  v127 = v125 + 1859775393 + __ROL4__(v123, 5) + v124 + v109;
  LODWORD(v2) = v77 ^ v80 ^ v101;
  v123 = __ROR4__(v123, 2);
  v128 = v122 ^ v73 ^ v86;
  v129 = v90;
  LODWORD(v2) = __ROL4__(v118 ^ (unsigned int)v2, 1);
  v130 = __ROL4__(v105 ^ v128, 1);
  v131 = v112 + 1859775393 + (_DWORD)v2 + __ROL4__(v127, 5) + v126;
  v132 = (signed int)v2;
  v133 = v130 + (v127 & v123 | v120 & (v127 | v123));
  v127 = __ROR4__(v127, 2);
  v134 = v117 + v133 + __ROL4__(v131, 5) - 1894007588;
  v135 = __ROL4__(v108 ^ v125 ^ v80 ^ v90, 1);
  v136 = v111;
  v137 = v135;
  v138 = v135 + (v131 & v127 | v123 & (v131 | v127));
  v131 = __ROR4__(v131, 2);
  v139 = (unsigned int)v2 ^ v86 ^ v116;
  LODWORD(v2) = v96;
  v140 = v120 + v138 + __ROL4__(v134, 5) - 1894007588;
  v141 = __ROL4__(v111 ^ v139, 1);
  v142 = v131 & v134;
  v143 = v127 & (v131 | v134);
  v134 = __ROR4__(v134, 2);
  v144 = v123 + v141 + (v142 | v143) + __ROL4__(v140, 5) - 1894007588;
  v145 = __ROL4__(v114 ^ v130 ^ v129 ^ v96, 1);
  v146 = v145 + (v140 & v134 | v131 & (v140 | v134));
  v140 = __ROR4__(v140, 2);
  v147 = v127 + v146 + __ROL4__(v144, 5) - 1894007588;
  v148 = __ROL4__(v118 ^ v137 ^ v116 ^ v99, 1);
  v149 = v131 + v148 + (v144 & v140 | v134 & (v144 | v140)) + __ROL4__(v147, 5) - 1894007588;
  v144 = __ROR4__(v144, 2);
  v150 = __ROL4__(v122 ^ v141 ^ (unsigned int)v2 ^ v101, 1);
  v151 = v147 & v144 | v140 & (v147 | v144);
  v147 = __ROR4__(v147, 2);
  v152 = __ROL4__(v105 ^ v125 ^ v145 ^ v99, 1);
  v153 = v134 + v150 + v151 + __ROL4__(v149, 5) - 1894007588;
  v154 = v149 & v147 | v144 & (v149 | v147);
  v149 = __ROR4__(v149, 2);
  v155 = v140 + v152 + v154 + __ROL4__(v153, 5) - 1894007588;
  v156 = __ROL4__(v108 ^ v132 ^ v148 ^ v101, 1);
  v157 = v156 + (v149 & v153 | v147 & (v149 | v153));
  v153 = __ROR4__(v153, 2);
  v158 = v144 + v157 + __ROL4__(v155, 5) - 1894007588;
  v159 = __ROL4__(v105 ^ v111 ^ v130 ^ v150, 1);
  v160 = __ROL4__(v108 ^ v114 ^ v137 ^ v152, 1);
  v161 = v155 & v153 | v149 & (v155 | v153);
  v155 = __ROR4__(v155, 2);
  v162 = v147 + v159 + v161 + __ROL4__(v158, 5) - 1894007588;
  v163 = v153 & (v158 | v155);
  v164 = v158 & v155;
  v158 = __ROR4__(v158, 2);
  v165 = v160 + (v164 | v163);
  v166 = v162 & v158;
  v167 = v149 + v165 + __ROL4__(v162, 5) - 1894007588;
  v168 = v155 & (v162 | v158);
  v162 = __ROR4__(v162, 2);
  LODWORD(v2) = __ROL4__(v136 ^ v118 ^ v141 ^ v156, 1);
  v169 = v153 + (_DWORD)v2 + (v166 | v168);
  v170 = __ROL4__(v160 ^ v118 ^ v125 ^ v148, 1);
  v171 = v167 & v162;
  v172 = (unsigned int)v2 ^ v122 ^ v132 ^ v150;
  v173 = __ROL4__(v136 ^ v118 ^ v141 ^ v156, 1);
  v174 = __ROL4__(v159 ^ v114 ^ v122 ^ v145, 1);
  v175 = v169 + __ROL4__(v167, 5) - 1894007588;
  v176 = v167 | v162;
  v167 = __ROR4__(v167, 2);
  v177 = v171 | v158 & v176;
  v178 = v167 & v175;
  v179 = v155 + v174 + v177 + __ROL4__(v175, 5) - 1894007588;
  v180 = v167 | v175;
  v175 = __ROR4__(v175, 2);
  v181 = v158 + v170 + (v178 | v162 & v180) + __ROL4__(v179, 5) - 1894007588;
  v182 = __ROL4__(v172, 1) + (v179 & v175 | v167 & (v179 | v175)) - 1894007588;
  v179 = __ROR4__(v179, 2);
  v183 = __ROL4__(v181, 5) + v182 + v162;
  v184 = v181 & v179 | v175 & (v181 | v179);
  v181 = __ROR4__(v181, 2);
  v185 = __ROL4__(v174 ^ v125 ^ v130 ^ v152, 1);
  v186 = v183 & v181;
  v187 = v167 - 1894007588 + v185 + v184 + __ROL4__(v183, 5);
  v188 = __ROL4__(v170 ^ v132 ^ v137 ^ v156, 1);
  v189 = v183 | v181;
  v183 = __ROR4__(v183, 2);
  v190 = v175 - 1894007588 + v188 + (v186 | v179 & v189) + __ROL4__(v187, 5);
  v191 = __ROL4__(v159 ^ __ROL4__(v172, 1) ^ v130 ^ v141, 1);
  v192 = v179 + v191 + (v187 & v183 | v181 & (v187 | v183));
  v187 = __ROR4__(v187, 2);
  v193 = v192 + __ROL4__(v190, 5) - 1894007588;
  v194 = __ROL4__(v160 ^ v185 ^ v137 ^ v145, 1);
  v195 = v194 + (v187 & v190 | v183 & (v187 | v190));
  v190 = __ROR4__(v190, 2);
  v196 = v181 + v195 + __ROL4__(v193, 5) - 1894007588;
  v197 = v193 & v190;
  v198 = __ROL4__(v173 ^ v188 ^ v141 ^ v148, 1);
  v199 = v187 & (v193 | v190);
  v193 = __ROR4__(v193, 2);
  v200 = v183 + v198 + (v197 | v199);
  v201 = v196 & v193;
  v202 = __ROL4__(v173 ^ v188 ^ v141 ^ v148, 1);
  v203 = v200 + __ROL4__(v196, 5) - 1894007588;
  v204 = v196 | v193;
  v196 = __ROR4__(v196, 2);
  v205 = v201 | v190 & v204;
  v206 = __ROL4__(v174 ^ v191 ^ v145 ^ v150, 1);
  v207 = __ROL4__(v203, 5);
  v208 = __ROL4__(v170 ^ v194 ^ v148 ^ v152, 1);
  v209 = v190 - 899497514 + v208 + (v203 ^ v196 ^ v193);
  v203 = __ROR4__(v203, 2);
  v210 = v187 + v206 + v205 - 1894007588 + v207;
  v211 = __ROL4__(__ROL4__(v172, 1) ^ v198 ^ v150 ^ v156, 1);
  v212 = v209 + __ROL4__(v210, 5);
  v213 = __ROL4__(v159 ^ v185 ^ v206 ^ v152, 1);
  v214 = v193 + v211 + (v210 ^ v203 ^ v196) + __ROL4__(v212, 5) - 899497514;
  v210 = __ROR4__(v210, 2);
  v215 = v213 + (v210 ^ v203 ^ v212);
  v212 = __ROR4__(v212, 2);
  v216 = v196 + v215 + __ROL4__(v214, 5) - 899497514;
  v217 = v210 ^ v214 ^ v212;
  v218 = __ROL4__(v160 ^ v174 ^ v194 ^ v213, 1);
  v214 = __ROR4__(v214, 2);
  v219 = __ROL4__(v160 ^ v188 ^ v208 ^ v156, 1);
  v220 = v170 ^ v198 ^ v219;
  v221 = __ROL4__(v172, 1);
  v222 = v203 + v219 + v217 + __ROL4__(v216, 5) - 899497514;
  v223 = v216 ^ v214 ^ v212;
  v216 = __ROR4__(v216, 2);
  v224 = __ROL4__(v159 ^ v173 ^ v191 ^ v211, 1);
  v225 = v210 + v224 + v223 + __ROL4__(v222, 5) - 899497514;
  v226 = __ROL4__(v159 ^ v173 ^ v191 ^ v211, 1);
  v227 = __ROL4__(v173 ^ v220, 1);
  v228 = __ROL4__(v224 ^ v174 ^ v221 ^ v206, 1);
  v229 = v212 + v218 + (v222 ^ v216 ^ v214) + __ROL4__(v225, 5) - 899497514;
  v222 = __ROR4__(v222, 2);
  v230 = v214 + v227 + (v225 ^ v222 ^ v216) + __ROL4__(v229, 5) - 899497514;
  v225 = __ROR4__(v225, 2);
  v231 = v216 + v228 + (v225 ^ v222 ^ v229);
  v229 = __ROR4__(v229, 2);
  v232 = v185;
  v233 = v231 + __ROL4__(v230, 5) - 899497514;
  v234 = __ROL4__(v218 ^ v170 ^ v185 ^ v208, 1);
  v235 = v234 + (v225 ^ v230 ^ v229) - 899497514;
  v230 = __ROR4__(v230, 2);
  v236 = v235 + v222;
  v237 = __ROL4__(v227 ^ v221 ^ v188 ^ v211, 1);
  v238 = __ROL4__(v218 ^ v170 ^ v185 ^ v208, 1);
  v239 = __ROL4__(v233, 5);
  v240 = v225 + v237 - 899497514 + (v233 ^ v230 ^ v229);
  v233 = __ROR4__(v233, 2);
  v241 = v239 + v236;
  v242 = v240 + __ROL4__(v241, 5);
  v243 = __ROL4__(v234 ^ v188 ^ v194 ^ v219, 1);
  v244 = v241 ^ v233 ^ v230;
  v245 = __ROL4__(v228 ^ v232 ^ v191 ^ v213, 1);
  v241 = __ROR4__(v241, 2);
  v246 = v229 + v245 + v244 - 899497514 + __ROL4__(v242, 5);
  v247 = __ROL4__(v226 ^ v237 ^ v191 ^ v202, 1);
  v248 = v230 + v243 + (v242 ^ v241 ^ v233) - 899497514;
  v242 = __ROR4__(v242, 2);
  v249 = v248 + __ROL4__(v246, 5);
  v250 = v233 - 899497514 + v247 + (v242 ^ v241 ^ v246);
  v246 = __ROR4__(v246, 2);
  v251 = v250 + __ROL4__(v249, 5);
  v252 = __ROL4__(v228 ^ v247 ^ v206 ^ v211, 1);
  v253 = v242 ^ v249 ^ v246;
  v254 = __ROL4__(v218 ^ v245 ^ v194 ^ v206, 1);
  v249 = __ROR4__(v249, 2);
  LODWORD(v2) = v241 - 899497514 + v254 + v253 + __ROL4__(v251, 5);
  v255 = v251 ^ v249 ^ v246;
  v251 = __ROR4__(v251, 2);
  v256 = __ROL4__(v227 ^ v243 ^ v202 ^ v208, 1);
  v257 = v242 - 899497514 + v256 + v255 + __ROL4__((_DWORD)v2, 5);
  v258 = __ROL4__(v238 ^ v254 ^ v208 ^ v213, 1);
  v259 = v246 - 899497514 + v252 + ((unsigned int)v2 ^ v251 ^ v249) + __ROL4__(v257, 5);
  LODWORD(v2) = __ROR4__((_DWORD)v2, 2);
  v260 = v257 ^ (unsigned int)v2 ^ v251;
  v257 = __ROR4__(v257, 2);
  v261 = v249 + v258 + v260 - 899497514 + __ROL4__(v259, 5);
  v262 = __ROL4__(v261, 5) + __ROL4__(v237 ^ v256 ^ v211 ^ v219, 1);
  v263 = v259;
  v259 = __ROR4__(v259, 2);
  v264 = v251 + (v257 ^ (unsigned int)v2 ^ v263) - 899497514 + v262;
  v265 = v258 ^ v219;
  v266 = v3;
  v267 = v257 ^ v261 ^ v259;
  v261 = __ROR4__(v261, 2);
  v266[3] += v261;
  v268 = (_DWORD)v2 + v267 - 899497514 + __ROL4__(v264, 5) + __ROL4__(v226 ^ v245 ^ v213 ^ v252, 1);
  v266[1] += v268;
  v266[2] += __ROR4__(v264, 2);
  *v266 += __ROL4__(v268, 5) + __ROL4__(v218 ^ v243 ^ v265, 1) - 899497514 + v257 + (v264 ^ v261 ^ v259);
  v266[4] += v259;
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
  SHA1_CTX *v3; // rbx
  unsigned int v4; // esi
  unsigned int v5; // er9
  const char *v6; // r14
  unsigned int v7; // ecx
  unsigned int v8; // edi
  unsigned int i; // ebp

  v3 = context;
  v4 = len;
  v5 = context->count[0] + 8 * len;
  v6 = data;
  v7 = (context->count[0] >> 3) & 0x3F;
  v3->count[0] = v5;
  if ( v5 < 8 * len )
    ++v3->count[1];
  v3->count[1] += len >> 29;
  if ( v7 + len <= 0x3F )
  {
    v8 = 0;
  }
  else
  {
    v8 = 64 - v7;
    memmove(&v3->buffer[v7], data, 64 - v7);
    FSHA1Transform(v3->state, v3->buffer);
    for ( i = v8 + 63; i < v4; i += 64 )
    {
      FSHA1Transform(v3->state, &v6[v8]);
      v8 += 64;
    }
    v7 = 0;
  }
  memmove(&v3->buffer[v7], &v6[v8], v4 - v8);
}

// File Line: 168
// RVA: 0xEF25B0
void __fastcall SHA1_Final(char *digest, SHA1_CTX *context)
{
  unsigned int v2; // ebx
  SHA1_CTX *v3; // rdi
  char *v4; // r14
  unsigned int v5; // er8
  char *v6; // r9
  int v7; // ecx
  _BOOL8 v8; // rax
  unsigned __int64 v9; // r8
  char v10; // al
  char v11; // cl
  unsigned __int64 v12; // rax
  char data; // [rsp+20h] [rbp-28h]

  v2 = 0;
  v3 = context;
  v4 = digest;
  v5 = 0;
  v6 = &data;
  do
  {
    v7 = 8 * (3 - (v5 & 3));
    v8 = v5++ < 4;
    *v6++ = context->count[v8] >> v7;
  }
  while ( v5 < 8 );
  SHA1_Update(context, "€", 1u);
  while ( (v3->count[0] & 0x1F8) != 448 )
    SHA1_Update(v3, byte_1416A7BD8, 1u);
  SHA1_Update(v3, &data, 8u);
  v9 = 0i64;
  do
  {
    v10 = v2++;
    v11 = 3 - (v10 & 3);
    v12 = v9++;
    *v4++ = v3->state[v12 >> 2] >> 8 * v11;
  }
  while ( v2 < 0x14 );
  memset(v3->buffer, 0, 0x40ui64);
  memset(v3, 0, 0x14ui64);
  memset(v3->count, 0, 8ui64);
  memset(&data, 0, 8ui64);
  FSHA1Transform(v3->state, v3->buffer);
}

