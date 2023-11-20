// File Line: 220
// RVA: 0x6A45C0
void __fastcall Render::RasterizeZ::DrawAABB(Render::RasterizeZ *this, UFG::qVector3 *vmin, UFG::qVector3 *vmax, UFG::qMatrix44 *local_world)
{
  Render::RasterizeZ *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm12_4
  float v7; // xmm14_4
  float v8; // xmm13_4
  float v9; // ST24_4
  float v10; // xmm6_4
  float v11; // xmm15_4
  float v12; // ST4C_4
  float v13; // ST40_4
  float v14; // ST38_4
  float v15; // ST30_4
  float v16; // ST2C_4
  float v17; // ST20_4
  float v18; // ST28_4
  float v19; // ST58_4
  float v20; // ST24_4
  float v21; // xmm8_4
  float v22; // xmm12_4
  float v23; // ST34_4
  float v24; // xmm11_4
  float v25; // xmm7_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm6_4
  float v31; // xmm10_4
  float v32; // ST3C_4
  float v33; // xmm6_4
  float v34; // xmm13_4
  float v35; // ST38_4
  float v36; // ST48_4
  float v37; // ST40_4
  float v38; // ST4C_4
  float v39; // xmm11_4
  float v40; // xmm5_4
  float v41; // xmm5_4
  float v42; // ST44_4
  float v43; // ST5C_4
  float v44; // ST3C_4
  float v45; // xmm15_4
  int v46; // xmm8_4
  float v47; // xmm2_4
  float v48; // xmm12_4
  float v49; // xmm1_4
  float v50; // xmm3_4
  __int16 v51; // r8
  UFG::qVector4 v52; // [rsp+60h] [rbp-98h]
  UFG::qVector4 v0; // [rsp+70h] [rbp-88h]
  float v54; // [rsp+80h] [rbp-78h]
  float v55; // [rsp+84h] [rbp-74h]
  UFG::qVector4 v56; // [rsp+88h] [rbp-70h]
  float v57; // [rsp+98h] [rbp-60h]
  unsigned int v58; // [rsp+9Ch] [rbp-5Ch]
  UFG::qVector4 v59; // [rsp+A0h] [rbp-58h]
  float v60; // [rsp+B0h] [rbp-48h]
  UFG::qVector4 v1; // [rsp+B8h] [rbp-40h]
  float v62; // [rsp+C8h] [rbp-30h]
  UFG::qVector4 v2; // [rsp+D0h] [rbp-28h]
  float v64; // [rsp+E0h] [rbp-18h]
  UFG::qVector4 v65; // [rsp+E8h] [rbp-10h]
  float v66; // [rsp+F8h] [rbp+0h]
  UFG::qMatrix44 result; // [rsp+108h] [rbp+10h]
  float retaddr; // [rsp+1F8h] [rbp+100h]
  float v69; // [rsp+200h] [rbp+108h]
  float v70; // [rsp+200h] [rbp+108h]

  v4 = this;
  v5 = vmax->y;
  v6 = (float)(v5 - vmin->y) * 0.5;
  v7 = (float)(vmax->x + vmin->x) * 0.5;
  v8 = (float)(vmax->z + vmin->z) * 0.5;
  retaddr = (float)(v5 + vmin->y) * 0.5;
  v9 = (float)(vmax->z - vmin->z) * 0.5;
  v10 = (float)(vmax->x - vmin->x) * 0.5;
  UFG::qMatrix44::operator*(local_world, (UFG::qMatrix44 *)((char *)&result + 8), this->mWorldViewProjection);
  v69 = result.v0.x * v10;
  v11 = result.v0.z * v10;
  v12 = result.v0.y * v10;
  v13 = result.v1.x * v6;
  v14 = result.v1.y * v6;
  v15 = result.v1.z * v6;
  v16 = v6 * result.v1.w;
  v17 = result.v2.x * v9;
  v18 = result.v2.y * v9;
  v19 = result.v2.z * v9;
  v20 = v9 * result.v2.w;
  v21 = result.v1.x * v6;
  v22 = (float)((float)((float)(retaddr * result.v1.x) + (float)(v7 * result.v0.x)) + (float)(v8 * result.v2.x))
      + result.v3.x;
  v23 = v22 - (float)(result.v0.x * v10);
  v24 = (float)((float)((float)(retaddr * result.v1.y) + (float)(v7 * result.v0.y)) + (float)(v8 * result.v2.y))
      + result.v3.y;
  v25 = v22 - (float)(result.v0.x * v10);
  v26 = v14;
  v27 = result.v0.y * v10;
  v28 = (float)((float)((float)(retaddr * result.v1.z) + (float)(v7 * result.v0.z)) + (float)(v8 * result.v2.z))
      + result.v3.z;
  v29 = v10 * result.v0.w;
  retaddr = (float)((float)((float)(retaddr * result.v1.w) + (float)(v7 * result.v0.w)) + (float)(v8 * result.v2.w))
          + result.v3.w;
  v30 = retaddr - (float)(v10 * result.v0.w);
  v31 = v28 - v11;
  v32 = v30;
  v33 = v30 - v16;
  v34 = v24 - v12;
  v35 = (float)(v28 - v11) - v15;
  v64 = v35 + v19;
  v36 = v25 - v13;
  v37 = (float)(v24 - v12) - v26;
  v38 = v33 + v20;
  v39 = v24 + v27;
  v57 = v36 + v17;
  v0.x = v36 + v17;
  v70 = v69 + v22;
  v62 = v37 + v18;
  v0.y = v62;
  v40 = retaddr + v29;
  retaddr = v40;
  v41 = v40 - v16;
  v42 = v28 + v11;
  v43 = (float)(v28 + v11) - v15;
  v44 = v32 + v16;
  v60 = (float)(v70 + v21) + v17;
  v56.x = v60;
  v66 = (float)(v39 + v26) + v18;
  v56.y = (float)(v39 + v26) + v18;
  v45 = (float)(retaddr + v16) + v20;
  v56.z = (float)(v42 + v15) + v19;
  v1.x = (float)(v70 - v21) + v17;
  v1.y = (float)(v39 - v26) + v18;
  v1.z = v43 + v19;
  v1.w = v41 + v20;
  v2.x = (float)(v23 + v21) + v17;
  v2.y = (float)(v34 + v26) + v18;
  v2.z = (float)(v31 + v15) + v19;
  v2.w = v44 + v20;
  v56.w = (float)(retaddr + v16) + v20;
  v52.x = (float)(v70 - v21) - v17;
  v52.y = (float)(v39 - v26) - v18;
  v65.z = (float)(v42 + v15) - v19;
  v52.z = v43 - v19;
  v52.w = v41 - v20;
  v59.x = v36 - v17;
  v59.y = v37 - v18;
  v59.z = v35 - v19;
  v59.w = v33 - v20;
  v65.x = (float)(v70 + v21) - v17;
  v65.y = (float)(v39 + v26) - v18;
  v65.w = (float)(retaddr + v16) - v20;
  v0.w = (float)(v34 + v26) - v18;
  v0.z = (float)(v23 + v21) - v17;
  v46 = LODWORD(v45) ^ _xmm[0];
  LODWORD(v47) = COERCE_UNSIGNED_INT(v44 + v20) ^ _xmm[0];
  LODWORD(v48) = COERCE_UNSIGNED_INT(v33 - v20) ^ _xmm[0];
  v54 = (float)(v31 + v15) - v19;
  v49 = v44 - v20;
  v55 = v44 - v20;
  v58 = COERCE_UNSIGNED_INT(v33 + v20) ^ _xmm[0];
  LODWORD(v50) = COERCE_UNSIGNED_INT(v41 - v20) ^ _xmm[0];
  v51 = ((v48 > v59.x) | (unsigned __int16)(2
                                          * ((v59.x > v59.w) | (unsigned __int16)(2
                                                                                * ((v48 > v59.y) | (unsigned __int16)(2 * ((v59.y > v59.w) | (unsigned __int16)(2 * ((v59.z < 0.0) | (unsigned __int16)(2 * (v59.z > v59.w))))))))))) & ((*(float *)&v46 > v60) | (unsigned __int16)(2 * ((v60 > v45) | (unsigned __int16)(2 * ((*(float *)&v46 > v66) | (unsigned __int16)(2 * ((v66 > v45) | (unsigned __int16)(2 * ((v56.z < 0.0) | (unsigned __int16)(2 * (v56.z > v45))))))))))) & ((v50 > v52.x) | (unsigned __int16)(2 * ((v52.x > v52.w) | (unsigned __int16)(2 * ((v50 > v52.y) | (unsigned __int16)(2 * ((v52.y > v52.w) | (unsigned __int16)(2 * ((v52.z < 0.0) | (unsigned __int16)(2 * (v52.z > v52.w))))))))))) & ((v47 > v2.x) | (unsigned __int16)(2 * ((v2.x > v2.w) | (unsigned __int16)(2 * ((v47 > v2.y) | (unsigned __int16)(2 * ((v2.y > v2.w) | (unsigned __int16)(2 * ((v2.z < 0.0) | (unsigned __int16)(2 * (v2.z > v2.w))))))))))) & ((COERCE_FLOAT(LODWORD(v1.w) ^ _xmm[0]) > v1.x) | (unsigned __int16)(2 * ((v1.x > v1.w) | (unsigned __int16)(2 * ((COERCE_FLOAT(LODWORD(v1.w) ^ _xmm[0]) > v1.y) | (unsigned __int16)(2 * ((v1.y > v1.w) | (unsigned __int16)(2 * ((v1.z < 0.0) | (unsigned __int16)(2 * (v1.z > v1.w)))))))))));
  if ( !((unsigned __int16)(((COERCE_FLOAT(LODWORD(v49) ^ _xmm[0]) > v0.z) | (unsigned __int16)(2
                                                                                              * ((v0.z > v49) | (unsigned __int16)(2 * ((COERCE_FLOAT(LODWORD(v49) ^ _xmm[0]) > v0.w) | (unsigned __int16)(2 * ((v0.w > v49) | (unsigned __int16)(2 * ((v54 < 0.0) | (unsigned __int16)(2 * (v54 > v49))))))))))) & ((COERCE_FLOAT(LODWORD(v65.w) ^ _xmm[0]) > v65.x) | (unsigned __int16)(2 * ((v65.x > v65.w) | (unsigned __int16)(2 * ((COERCE_FLOAT(LODWORD(v65.w) ^ _xmm[0]) > v65.y) | (unsigned __int16)(2 * ((v65.y > v65.w) | (unsigned __int16)(2 * ((v65.z < 0.0) | (unsigned __int16)(2 * (v65.z > v65.w))))))))))) & v51) & (unsigned __int16)((COERCE_FLOAT(LODWORD(v38) ^ _xmm[0]) > (float)(v36 + v17)) | (unsigned __int16)(2 * (((float)(v36 + v17) > (float)(v33 + v20)) | (unsigned __int16)(2 * ((COERCE_FLOAT(LODWORD(v38) ^ _xmm[0]) > v62) | (unsigned __int16)(2 * ((v62 > v38) | (unsigned __int16)(2 * ((v64 < 0.0) | (unsigned __int16)(2 * (v64 > v38)))))))))))) )
  {
    Render::RasterizeZ::Draw2DH(v4, &v0, &v1, &v2);
    Render::RasterizeZ::Draw2DH(v4, &v2, &v1, &v56);
    Render::RasterizeZ::Draw2DH(v4, &v1, &v52, &v56);
    Render::RasterizeZ::Draw2DH(v4, &v56, &v52, &v65);
    Render::RasterizeZ::Draw2DH(v4, &v52, &v59, &v65);
    Render::RasterizeZ::Draw2DH(v4, &v65, &v59, (UFG::qVector4 *)((char *)&v0 + 8));
    Render::RasterizeZ::Draw2DH(v4, &v59, &v0, (UFG::qVector4 *)((char *)&v0 + 8));
    Render::RasterizeZ::Draw2DH(v4, (UFG::qVector4 *)((char *)&v0 + 8), &v0, &v2);
    Render::RasterizeZ::Draw2DH(v4, &v59, &v52, &v0);
    Render::RasterizeZ::Draw2DH(v4, &v0, &v52, &v1);
    Render::RasterizeZ::Draw2DH(v4, &v2, &v56, (UFG::qVector4 *)((char *)&v0 + 8));
    Render::RasterizeZ::Draw2DH(v4, (UFG::qVector4 *)((char *)&v0 + 8), &v56, &v65);
  }
}

// File Line: 733
// RVA: 0x6A2D40
void __fastcall Render::RasterizeZ::Draw2DH(Render::RasterizeZ *this, UFG::qVector4 *v0, UFG::qVector4 *v1, UFG::qVector4 *v2)
{
  float v4; // xmm6_4
  float v5; // xmm3_4
  float v6; // xmm5_4
  float v7; // xmm8_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm15_4
  float v15; // xmm9_4
  float v16; // xmm7_4
  float v17; // xmm10_4
  float v18; // xmm3_4
  float v19; // xmm8_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm8_4
  float v24; // xmm12_4
  float v25; // xmm8_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm9_4
  float v29; // xmm10_4
  float v30; // xmm11_4
  float v31; // xmm9_4
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm14_4
  float v35; // xmm15_4
  float v36; // xmm13_4
  float v37; // xmm10_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm12_4
  float v42; // xmm15_4
  float v43; // xmm8_4
  float v44; // xmm13_4
  float v45; // xmm0_4
  float v46; // xmm10_4
  float v47; // xmm9_4
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm11_4
  float v51; // xmm14_4
  float v52; // xmm4_4
  int v53; // ecx
  int v54; // edx
  int v55; // er8
  signed int v56; // esi
  signed int v57; // er9
  signed int v58; // edi
  signed int v59; // ebx
  signed int v60; // er10
  signed int v61; // er13
  signed int v62; // er11
  signed int v63; // er14
  int v64; // ebp
  signed int v65; // er12
  signed int v66; // er15
  signed int v67; // er14
  int v68; // eax
  unsigned int v69; // er8
  unsigned int v70; // ecx
  int v71; // edx
  unsigned int v72; // er14
  int v73; // er15
  int v74; // edx
  int v75; // er12
  int v76; // edx
  unsigned int v77; // esi
  int v78; // edx
  __m128i v79; // xmm5
  __m128i v80; // xmm15
  __m128i v81; // xmm8
  __m128i v82; // xmm0
  __m128i v83; // xmm8
  __m128i v84; // xmm4
  __m128i v85; // xmm6
  __m128i v86; // xmm2
  _OWORD *v87; // rdx
  _OWORD *v88; // r10
  __m128i v89; // xmm3
  __m128i v90; // xmm0
  __m128i v91; // xmm1
  __m128i v92; // xmm2
  __m128i v93; // xmm3
  __m128i v94; // xmm2
  __m128i v95; // xmm3
  __m128i v96; // xmm0
  __m128i v97; // xmm6
  __m128i v98; // xmm0
  __m128i v99; // xmm1
  __m128i v100; // xmm5
  __m128i v101; // xmm0
  __m128i v102; // xmm15
  __m128i v103; // xmm4
  __m128i v104; // xmm0
  __m128i v105; // xmm3
  __m128i v106; // xmm1
  __m128i v107; // xmm2
  __m128i v108; // xmm6
  __m128i v109; // xmm5
  __m128i v110; // xmm7
  __m128i v111; // xmm8
  __m128i v112; // xmm9
  __m128i v113; // xmm10
  __m128i v114; // xmm11
  __m128 v115; // xmm12
  __m128 v116; // xmm13
  __m128 v117; // xmm14
  __m128 v118; // xmm15
  int v119; // er14
  unsigned int i; // er15
  bool v121; // zf
  int v122; // eax
  int v123; // ecx
  __m128i v124; // xmm15
  __m128i v125; // xmm4
  int v126; // er14
  __m128i v127; // xmm2
  __m128i v128; // xmm0
  __m128i v129; // xmm1
  __m128i v130; // xmm3
  __m128i v131; // xmm5
  __m128i v132; // xmm6
  __m128i v133; // xmm4
  __m128i v134; // xmm7
  __m128i v135; // xmm9
  __m128i v136; // xmm10
  __m128i v137; // xmm8
  __m128i v138; // xmm11
  __m128 v139; // xmm12
  __m128 v140; // xmm13
  __m128 v141; // xmm14
  __m128 v142; // xmm15
  int v143; // er9
  unsigned int v144; // edx
  __m128i v145; // xmm7
  int v146; // eax
  int v147; // ecx
  __m128i v148; // xmm0
  int v149; // er9
  char *v150; // rcx
  __m128i v151; // xmm5
  __m128i v152; // xmm1
  __m128i v153; // xmm4
  __m128i v154; // xmm3
  __m128i v155; // xmm2
  __m128i v156; // xmm8
  __m128i v157; // xmm11
  BOOL v158; // er11
  __m128i v159; // xmm1
  BOOL v160; // ebx
  __m128i v161; // xmm2
  __m128i v162; // xmm5
  BOOL v163; // edi
  __m128i v164; // xmm10
  __m128i v165; // xmm3
  __m128i v166; // xmm6
  __m128i v167; // xmm12
  __m128i v168; // xmm6
  __m128i v169; // xmm9
  __m128i v170; // xmm1
  __m128i v171; // xmm9
  __m128i v172; // xmm3
  __m128i v173; // xmm7
  __m128i v174; // xmm2
  __m128i v175; // xmm15
  __m128i v176; // xmm10
  __m128i v177; // xmm4
  __m128i v178; // xmm11
  __m128i v179; // xmm8
  __m128i v180; // xmm5
  __m128i v181; // xmm14
  __m128i v182; // xmm13
  __m128 v183; // xmm12
  __m128 v184; // xmm0
  __m128i v185; // xmm9
  __m128 v186; // xmm1
  __m128 v187; // xmm6
  __m128 v188; // xmm0
  __m128i v189; // xmm4
  __m128 v190; // xmm3
  __m128 v191; // xmm2
  __m128i v192; // xmm5
  __m128 v193; // xmm9
  __m128 v194; // xmm4
  __m128 v195; // xmm0
  __m128 v196; // xmm2
  __m128 v197; // xmm1
  __m128 v198; // xmm0
  __m128 v199; // xmm12
  __m128 v200; // xmm0
  __m128i v201; // xmm12
  __m128i v202; // xmm9
  __m128i v203; // xmm3
  __m128i v204; // xmm6
  __m128i v205; // xmm9
  __m128i v206; // xmm3
  __m128i v207; // xmm2
  __m128i v208; // xmm15
  __m128i v209; // xmm8
  __m128i v210; // xmm4
  __m128i v211; // xmm14
  __m128i v212; // xmm5
  __m128i v213; // xmm13
  __m128 v214; // xmm12
  __m128 v215; // xmm6
  __m128 v216; // xmm3
  __m128 v217; // xmm2
  __m128 v218; // xmm1
  __m128 v219; // xmm1
  __m128 v220; // xmm2
  __m128i v221; // xmm6
  __m128i v222; // xmm0
  __m128i v223; // xmm12
  __m128i v224; // xmm1
  __m128i v225; // xmm9
  __m128i v226; // xmm2
  __m128i v227; // xmm3
  __m128i v228; // xmm15
  __m128i v229; // xmm4
  __m128i v230; // xmm10
  __m128i v231; // xmm7
  __m128i v232; // xmm5
  __m128i v233; // xmm11
  __m128i v234; // xmm8
  __m128i v235; // xmm14
  __m128i v236; // xmm13
  __m128 v237; // xmm12
  __m128 v238; // xmm0
  __m128i v239; // xmm9
  __m128 v240; // xmm1
  __m128 v241; // xmm6
  __m128 v242; // xmm0
  __m128i v243; // xmm4
  __m128 v244; // xmm3
  __m128 v245; // xmm2
  __m128i v246; // xmm5
  __m128 v247; // xmm2
  __m128 v248; // xmm0
  __m128 v249; // xmm12
  __m128i v250; // xmm12
  __m128i v251; // xmm1
  __m128i v252; // xmm6
  __m128i v253; // xmm3
  __m128i v254; // xmm9
  __m128i v255; // xmm2
  __m128i v256; // xmm15
  __m128i v257; // xmm15
  __m128i v258; // xmm2
  __m128i v259; // xmm0
  __m128i v260; // xmm3
  __m128i v261; // xmm9
  __m128i v262; // xmm8
  __m128 v263; // xmm12
  __m128 v264; // xmm6
  __m128 v265; // xmm3
  __m128 v266; // xmm2
  __m128 v267; // xmm0
  __m128 v268; // xmm12
  unsigned int v269; // [rsp+0h] [rbp-598h]
  unsigned int v270; // [rsp+8h] [rbp-590h]
  __m128i v271; // [rsp+10h] [rbp-588h]
  __int128 v272; // [rsp+20h] [rbp-578h]
  __int128 v273; // [rsp+30h] [rbp-568h]
  __m128i v274; // [rsp+40h] [rbp-558h]
  __int128 v275; // [rsp+50h] [rbp-548h]
  __m128i v276; // [rsp+60h] [rbp-538h]
  __m128i v277; // [rsp+70h] [rbp-528h]
  __m128i v278; // [rsp+80h] [rbp-518h]
  __m128i v279; // [rsp+90h] [rbp-508h]
  __m128i v280; // [rsp+A0h] [rbp-4F8h]
  __m128i v281; // [rsp+B0h] [rbp-4E8h]
  __m128i v282; // [rsp+C0h] [rbp-4D8h]
  __m128i v283; // [rsp+D0h] [rbp-4C8h]
  __m128i v284; // [rsp+E0h] [rbp-4B8h]
  __m128i v285; // [rsp+F0h] [rbp-4A8h]
  __m128i v286; // [rsp+100h] [rbp-498h]
  __m128i v287; // [rsp+110h] [rbp-488h]
  __m128i v288; // [rsp+120h] [rbp-478h]
  __m128i v289; // [rsp+130h] [rbp-468h]
  __m128i v290; // [rsp+140h] [rbp-458h]
  __m128i v291; // [rsp+150h] [rbp-448h]
  __m128i v292; // [rsp+160h] [rbp-438h]
  __m128i v293; // [rsp+170h] [rbp-428h]
  __m128i v294; // [rsp+180h] [rbp-418h]
  __m128i v295; // [rsp+190h] [rbp-408h]
  __m128i v296; // [rsp+1A0h] [rbp-3F8h]
  __m128i v297; // [rsp+1B0h] [rbp-3E8h]
  __m128i v298; // [rsp+1C0h] [rbp-3D8h]
  __m128i v299; // [rsp+1D0h] [rbp-3C8h]
  __m128i v300; // [rsp+1E0h] [rbp-3B8h]
  __m128i v301; // [rsp+1F0h] [rbp-3A8h]
  __int128 v302; // [rsp+200h] [rbp-398h]
  __m128i v303; // [rsp+210h] [rbp-388h]
  __m128i v304; // [rsp+220h] [rbp-378h]
  __m128i v305; // [rsp+230h] [rbp-368h]
  __m128i v306; // [rsp+240h] [rbp-358h]
  __m128i v307; // [rsp+250h] [rbp-348h]
  __int128 v308; // [rsp+260h] [rbp-338h]
  __m128i v309; // [rsp+270h] [rbp-328h]
  __m128i v310; // [rsp+280h] [rbp-318h]
  char v311; // [rsp+29Fh] [rbp-2F9h]
  char v312; // [rsp+3AFh] [rbp-1E9h]
  Render::RasterizeZ *v313; // [rsp+5A0h] [rbp+8h]
  float v314; // [rsp+5A8h] [rbp+10h]
  int v315; // [rsp+5A8h] [rbp+10h]
  float v316; // [rsp+5B0h] [rbp+18h]
  float v317; // [rsp+5B0h] [rbp+18h]
  float v318; // [rsp+5B8h] [rbp+20h]
  unsigned __int64 v319; // [rsp+5B8h] [rbp+20h]

  v313 = this;
  v4 = v1->w;
  v5 = v1->y;
  v6 = v0->w;
  v7 = v2->w;
  v8 = v0->y;
  v9 = v2->y;
  v10 = (float)(v1->w * v8) - (float)(v1->y * v6);
  v11 = (float)(v2->w * v5) - (float)(v2->y * v4);
  v12 = (float)(v2->y * v6) - (float)(v2->w * v8);
  v13 = (float)(v1->x * v6) - (float)(v0->x * v4);
  v14 = (float)(v2->x * v4) - (float)(v1->x * v7);
  v15 = (float)(v0->x * v7) - (float)(v2->x * v6);
  v316 = (float)(v0->x * v7) - (float)(v2->x * v6);
  v16 = (float)(v0->x * v5) - (float)(v1->x * v8);
  v17 = (float)(v1->x * v9) - (float)(v2->x * v5);
  v18 = (float)(v2->x * v8) - (float)(v0->x * v9);
  v19 = (float)((float)(v7 * v16) + (float)(v6 * v17)) + (float)(v4 * v18);
  if ( v19 < 1.0 )
    return;
  v20 = 1.0 / v19;
  v21 = v17 + v16;
  v22 = v11 + v10;
  v23 = v11 * -1.0;
  v24 = v11 * 0.015625;
  v25 = v23 + v17;
  v26 = (float)(v22 + v12) * v20;
  v27 = (float)((float)(v14 + v13) + v15) * v20;
  v28 = (float)(v10 * -1.0) + v16;
  v318 = v26;
  v29 = (float)(v12 * -1.0) + v18;
  v30 = v10 * 0.015625;
  v31 = v28 + (float)(v13 * -1.0);
  v32 = (float)(v26 * -1.0) + (float)((float)(v21 + v18) * v20);
  v33 = v14 * -1.0;
  v34 = v13 * 0.015625;
  v35 = v14 * 0.015625;
  v36 = v12 * 0.015625;
  v37 = v29 + (float)(v316 * -1.0);
  v317 = v316 * 0.015625;
  v314 = v32 + (float)(v27 * -1.0);
  v38 = (float)(1.0 / (float)(COERCE_FLOAT(LODWORD(v30) & _xmm) + COERCE_FLOAT(LODWORD(v34) & _xmm))) * 65536.0;
  v39 = (float)(1.0 / (float)(COERCE_FLOAT(LODWORD(v24) & _xmm) + COERCE_FLOAT(LODWORD(v35) & _xmm))) * 65536.0;
  v40 = (float)(1.0 / (float)(COERCE_FLOAT(LODWORD(v36) & _xmm) + COERCE_FLOAT(LODWORD(v317) & _xmm))) * 65536.0;
  v41 = v24 * v39;
  v42 = v35 * v39;
  v43 = (float)(v25 + v33) * v39;
  v44 = v36 * v40;
  v45 = v317 * v40;
  v46 = v37 * v40;
  v47 = v31 * v38;
  v48 = v314 * 65536.0;
  v49 = (float)(v27 * 0.015625) * 65536.0;
  v50 = v30 * v38;
  v51 = v34 * v38;
  v52 = FLOAT_1_6777216e7;
  if ( v47 <= -16777216.0 )
  {
    v47 = FLOAT_N1_6777216e7;
  }
  else if ( v47 >= 16777216.0 )
  {
    v47 = FLOAT_1_6777216e7;
  }
  if ( v43 <= -16777216.0 )
  {
    v43 = FLOAT_N1_6777216e7;
  }
  else if ( v43 >= 16777216.0 )
  {
    v43 = FLOAT_1_6777216e7;
  }
  if ( v46 <= -16777216.0 )
  {
    v46 = FLOAT_N1_6777216e7;
  }
  else if ( v46 >= 16777216.0 )
  {
    goto LABEL_15;
  }
  v52 = v46;
LABEL_15:
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = -(signed int)(float)((float)(v318 * 0.015625) * 65536.0);
  v58 = -(signed int)v49;
  v59 = (signed int)v50;
  v60 = (signed int)v41;
  v61 = (signed int)v42;
  v315 = (signed int)v52;
  v62 = (signed int)v44;
  v63 = (signed int)v45;
  v64 = 0x10000 - (signed int)v48;
  if ( (signed int)v51 < 0 )
    v53 = -(signed int)v51;
  v65 = 0;
  if ( v59 > 0 )
    v65 = (signed int)v50;
  if ( v61 < 0 )
    v54 = -v61;
  v66 = 0;
  if ( v60 > 0 )
    v66 = (signed int)v41;
  if ( v63 < 0 )
    v55 = -v63;
  v67 = 0;
  if ( v62 > 0 )
    v67 = (signed int)v44;
  if ( v58 < 0 )
    v56 = (signed int)v49;
  v68 = 0;
  if ( (signed int)(float)((float)(v318 * 0.015625) * 65536.0) < 0 )
    v68 = -(signed int)(float)((float)(v318 * 0.015625) * 65536.0);
  v69 = v67 + v55;
  v270 = v65 + v53;
  v70 = v54 + v66;
  v71 = (signed int)v50;
  v269 = v56 + v68;
  if ( v59 < 0 )
    v71 = -v59;
  v72 = (signed int)v51;
  if ( v59 < 0 || v71 < 256 && (signed int)v51 > 0 )
    v73 = (signed int)v47 + 1;
  else
    v73 = (signed int)v47;
  v74 = (signed int)v41;
  if ( v60 < 0 )
    v74 = -v60;
  if ( v60 < 0 || v74 < 256 && v61 > 0 )
    v75 = (signed int)v43 + 1;
  else
    v75 = (signed int)v43;
  v76 = (signed int)v44;
  if ( v62 < 0 )
    v76 = -v62;
  v77 = (signed int)v45;
  if ( v62 < 0 || v76 < 256 && (signed int)v45 > 0 )
    v315 = (signed int)v52 + 1;
  v78 = -(signed int)(float)((float)(v318 * 0.015625) * 65536.0);
  if ( v57 < 0 )
    v78 = (signed int)(float)((float)(v318 * 0.015625) * 65536.0);
  if ( v57 < 0 || v78 < 256 && (signed int)v49 < 0 )
    ++v64;
  v79 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v59), _mm_cvtsi32_si128(v62)),
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v60), _mm_cvtsi32_si128(v57)));
  v80 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v72), _mm_cvtsi32_si128(v77)),
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v61), _mm_cvtsi32_si128(v58)));
  _mm_store_si128(&v309, _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 0), 2u));
  _mm_store_si128(&v296, _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v80, (__m128)v80, 85), 2u));
  _mm_store_si128(&v301, _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 85), 2u));
  _mm_store_si128(&v300, _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v80, (__m128)v80, 255), 2u));
  _mm_store_si128((__m128i *)&v272, (__m128i)_mm_shuffle_ps((__m128)v80, (__m128)v80, 85));
  _mm_store_si128(&v307, _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 170), 2u));
  _mm_store_si128(&v271, (__m128i)_mm_shuffle_ps((__m128)v80, (__m128)v80, 255));
  _mm_store_si128(&v303, _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 255), 2u));
  _mm_store_si128(&v295, _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v80, (__m128)v80, 0), 2u));
  _mm_store_si128(&v298, _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v80, (__m128)v80, 170), 2u));
  v81 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v270), _mm_cvtsi32_si128(v69)),
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v70), _mm_cvtsi32_si128(v269)));
  _mm_store_si128((__m128i *)&v308, _mm_slli_epi32(v81, 2u));
  v82 = v81;
  v83 = _mm_slli_epi32(v81, 5u);
  _mm_store_si128(&v284, _mm_slli_epi32(v82, 3u));
  _mm_store_si128(&v294, v83);
  _mm_store_si128((__m128i *)&v275, (__m128i)_mm_shuffle_ps((__m128)v80, (__m128)v80, 0));
  _mm_store_si128((__m128i *)&v273, (__m128i)_mm_shuffle_ps((__m128)v80, (__m128)v80, 170));
  v84 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(2 * v59), _mm_cvtsi32_si128(2 * v62)),
          _mm_unpacklo_epi32(
            _mm_cvtsi32_si128(2 * v60),
            _mm_cvtsi32_si128(-2 * (signed int)(float)((float)(v318 * 0.015625) * 65536.0))));
  v85 = _mm_unpackhi_epi32((__m128i)0i64, v84);
  v86 = _mm_cvtsi32_si128(3 * v60);
  v87 = (_OWORD *)((unsigned __int64)&v311 & 0xFFFFFFFFFFFFFFF0ui64);
  v88 = (_OWORD *)((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64);
  v89 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(3 * v59), _mm_cvtsi32_si128(3 * v62)),
          _mm_unpacklo_epi32(v86, _mm_cvtsi32_si128(-3 * (signed int)(float)((float)(v318 * 0.015625) * 65536.0))));
  v319 = (unsigned __int64)&v311 & 0xFFFFFFFFFFFFFFF0ui64;
  v90 = _mm_unpacklo_epi32(v79, v89);
  v91 = _mm_unpackhi_epi32(v79, v89);
  v92 = _mm_unpacklo_epi32((__m128i)0i64, v84);
  v93 = v92;
  v94 = _mm_unpackhi_epi32(v92, v90);
  v95 = _mm_unpacklo_epi32(v93, v90);
  v96 = v85;
  _mm_store_si128(&v297, v94);
  v97 = _mm_unpackhi_epi32(v85, v91);
  _mm_store_si128(&v305, _mm_unpacklo_epi32(v96, v91));
  v98 = v79;
  v99 = v79;
  v100 = _mm_slli_epi32(v79, 5u);
  _mm_store_si128(&v304, _mm_slli_epi32(v98, 2u));
  _mm_store_si128((__m128i *)&v302, _mm_slli_epi32(v99, 3u));
  _mm_store_si128(&v306, _mm_slli_epi32(v80, 2u));
  v101 = v80;
  v102 = _mm_slli_epi32(v80, 5u);
  _mm_store_si128(&v285, _mm_slli_epi32(v101, 3u));
  _mm_store_si128(&v310, v95);
  v103 = _mm_add_epi32(
           _mm_unpacklo_epi32(
             _mm_unpacklo_epi32(_mm_cvtsi32_si128(v73 + 127 * v72), _mm_cvtsi32_si128(v315 + 127 * v77)),
             _mm_unpacklo_epi32(_mm_cvtsi32_si128(v75 + 127 * v61), _mm_cvtsi32_si128(v64 + 127 * v58))),
           v83);
  _mm_store_si128(&v299, v97);
  _mm_store_si128(&v278, v102);
  v104 = _mm_add_epi32(v103, v100);
  v105 = _mm_sub_epi32(v103, v102);
  v106 = _mm_add_epi32(v104, v100);
  v107 = _mm_add_epi32(v106, v100);
  v108 = _mm_sub_epi32(v106, v102);
  v109 = _mm_sub_epi32(v104, v102);
  *v87 = v103;
  v87[1] = v104;
  v110 = _mm_sub_epi32(v107, v102);
  v87[2] = v106;
  v87[3] = v107;
  v87[4] = v105;
  v87[5] = v109;
  v87[6] = v108;
  v87[7] = v110;
  v111 = _mm_sub_epi32(v105, v102);
  v112 = _mm_sub_epi32(v109, v102);
  v87[8] = v111;
  v87[9] = v112;
  v113 = _mm_sub_epi32(v108, v102);
  v114 = _mm_sub_epi32(v110, v102);
  v87[10] = v113;
  v87[11] = v114;
  v115 = (__m128)_mm_sub_epi32(v111, v102);
  v87[12] = v115;
  v116 = (__m128)_mm_sub_epi32(v112, v102);
  v87[13] = v116;
  v117 = (__m128)_mm_sub_epi32(v113, v102);
  v118 = (__m128)_mm_sub_epi32(v114, v278);
  v87[14] = v117;
  v87[15] = v118;
  v119 = 0;
  for ( i = ((_mm_movemask_ps(v118) == 0) | 2
                                          * ((_mm_movemask_ps(v117) == 0) | 2
                                                                          * ((_mm_movemask_ps(v116) == 0) | 2 * ((_mm_movemask_ps(v115) == 0) | 2 * ((_mm_movemask_ps((__m128)v114) == 0) | 2 * ((_mm_movemask_ps((__m128)v113) == 0) | 2 * ((_mm_movemask_ps((__m128)v112) == 0) | 2 * ((_mm_movemask_ps((__m128)v111) == 0) | 2 * ((_mm_movemask_ps((__m128)v110) == 0) | 2 * ((_mm_movemask_ps((__m128)v108) == 0) | 2 * ((_mm_movemask_ps((__m128)v109) == 0) | 2 * ((_mm_movemask_ps((__m128)v105) == 0) | 2 * ((_mm_movemask_ps((__m128)v107) == 0) | 2 * ((_mm_movemask_ps((__m128)v106) == 0) | 2 * ((_mm_movemask_ps((__m128)v104) == 0) | 2 * (_mm_movemask_ps((__m128)v103) == 0)))))))))))))))) << 16;
        i;
        v119 = v126 + 1 )
  {
    v121 = !_BitScanReverse((unsigned int *)&v122, i);
    if ( v121 )
      v123 = 0;
    else
      v123 = 31 - v122;
    v124 = _mm_load_si128(&v285);
    v125 = _mm_load_si128((const __m128i *)&v302);
    v126 = v123 + v119;
    i <<= v123 + 1;
    v127 = _mm_add_epi32(_mm_sub_epi32((__m128i)v87[v126], v294), v284);
    *v88 = v127;
    v128 = _mm_add_epi32(v127, v125);
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x10) = v128;
    v129 = _mm_add_epi32(v128, v125);
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x20) = v129;
    v130 = _mm_add_epi32(v129, v125);
    v131 = _mm_sub_epi32(v128, v124);
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x30) = v130;
    v132 = _mm_sub_epi32(v129, v124);
    v133 = _mm_sub_epi32(v127, v124);
    v134 = _mm_sub_epi32(v130, v124);
    v135 = _mm_sub_epi32(v131, v124);
    v136 = _mm_sub_epi32(v132, v124);
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x40) = v133;
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x50) = v131;
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x60) = v132;
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x70) = v134;
    v137 = _mm_sub_epi32(v133, v124);
    v138 = _mm_sub_epi32(v134, v124);
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x80) = v137;
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0x90) = v135;
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0xA0) = v136;
    *(__m128i *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0xB0) = v138;
    v139 = (__m128)_mm_sub_epi32(v137, v124);
    v140 = (__m128)_mm_sub_epi32(v135, v124);
    *(__m128 *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0xC0) = v139;
    *(__m128 *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0xD0) = v140;
    v141 = (__m128)_mm_sub_epi32(v136, v124);
    *(__m128 *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0xE0) = v141;
    v142 = (__m128)_mm_sub_epi32(v138, v285);
    *(__m128 *)(((unsigned __int64)&v312 & 0xFFFFFFFFFFFFFFF0ui64) + 0xF0) = v142;
    v143 = 0;
    v144 = ((_mm_movemask_ps(v142) == 0) | 2
                                         * ((_mm_movemask_ps(v141) == 0) | 2
                                                                         * ((_mm_movemask_ps(v140) == 0) | 2 * ((_mm_movemask_ps(v139) == 0) | 2 * ((_mm_movemask_ps((__m128)v138) == 0) | 2 * ((_mm_movemask_ps((__m128)v136) == 0) | 2 * ((_mm_movemask_ps((__m128)v135) == 0) | 2 * ((_mm_movemask_ps((__m128)v137) == 0) | 2 * ((_mm_movemask_ps((__m128)v134) == 0) | 2 * ((_mm_movemask_ps((__m128)v132) == 0) | 2 * ((_mm_movemask_ps((__m128)v131) == 0) | 2 * ((_mm_movemask_ps((__m128)v133) == 0) | 2 * ((_mm_movemask_ps((__m128)v130) == 0) | 2 * ((_mm_movemask_ps((__m128)v129) == 0) | 2 * ((_mm_movemask_ps((__m128)v128) == 0) | 2 * (_mm_movemask_ps((__m128)v127) == 0)))))))))))))))) << 16;
    if ( v144 )
    {
      v145 = 0i64;
      do
      {
        v121 = !_BitScanReverse((unsigned int *)&v146, v144);
        if ( v121 )
          v147 = 0;
        else
          v147 = 31 - v146;
        v148 = _mm_load_si128((const __m128i *)&v308);
        v149 = v147 + v143;
        v144 <<= v147 + 1;
        v150 = (char *)v313->mZBuffer;
        v151 = _mm_sub_epi32((__m128i)v88[v149], v284);
        v152 = _mm_add_epi32(v151, v304);
        v153 = _mm_add_epi32(v151, v148);
        v154 = _mm_sub_epi32(v152, v306);
        v155 = _mm_add_epi32(_mm_sub_epi32(v151, v306), v148);
        v156 = _mm_add_epi32((__m128i)_mm_shuffle_ps((__m128)v151, (__m128)v151, 170), v305);
        _mm_store_si128(&v281, v156);
        v157 = _mm_add_epi32(v156, v307);
        v158 = _mm_movemask_epi8(_mm_cmpgt_epi32(v145, _mm_add_epi32(v152, v148))) != 0;
        _mm_store_si128(&v287, v157);
        v159 = _mm_add_epi32((__m128i)_mm_shuffle_ps((__m128)v151, (__m128)v151, 0), v310);
        v160 = _mm_movemask_epi8(_mm_cmpgt_epi32(v145, v155)) != 0;
        _mm_store_si128(&v282, v159);
        v161 = _mm_add_epi32((__m128i)_mm_shuffle_ps((__m128)v151, (__m128)v151, 85), v297);
        v162 = _mm_add_epi32((__m128i)_mm_shuffle_ps((__m128)v151, (__m128)v151, 255), v299);
        v163 = _mm_movemask_epi8(_mm_cmpgt_epi32(v145, _mm_add_epi32(v154, v148))) != 0;
        _mm_store_si128(&v283, v161);
        v164 = _mm_add_epi32(v162, v303);
        v165 = _mm_add_epi32(v159, v309);
        _mm_store_si128(&v290, _mm_sub_epi32(v159, v295));
        _mm_store_si128(&v279, v162);
        _mm_store_si128(&v277, v164);
        v166 = _mm_add_epi32(v161, v301);
        _mm_store_si128(&v291, v165);
        _mm_store_si128(&v289, v166);
        _mm_store_si128(&v286, _mm_sub_epi32(v161, v296));
        _mm_store_si128(&v293, _mm_sub_epi32(v156, v298));
        _mm_store_si128(&v276, _mm_sub_epi32(v162, v300));
        _mm_store_si128(&v278, _mm_sub_epi32(v165, v295));
        _mm_store_si128(&v292, _mm_sub_epi32(v166, v296));
        _mm_store_si128(&v288, _mm_sub_epi32(v157, v298));
        _mm_store_si128(&v274, _mm_sub_epi32(v164, v300));
        if ( !_mm_movemask_epi8(_mm_cmpgt_epi32(v145, v153)) )
        {
          v167 = _mm_load_si128((const __m128i *)&v273);
          v168 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))];
          v169 = v159;
          v170 = _mm_load_si128((const __m128i *)&v272);
          v171 = _mm_sub_epi32(v169, _mm_load_si128((const __m128i *)&v275));
          v172 = _mm_sub_epi32(v161, v170);
          v280 = v168;
          v173 = _mm_sub_epi32(v172, v170);
          v174 = _mm_sub_epi32(v156, v167);
          v175 = _mm_sub_epi32(v162, v271);
          v176 = v171;
          v177 = _mm_sub_epi32(v174, v167);
          v178 = v171;
          v179 = _mm_sub_epi32(v173, v170);
          v180 = _mm_sub_epi32(v177, v167);
          v181 = _mm_sub_epi32(v175, v271);
          v182 = _mm_sub_epi32(v181, v271);
          v183 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v279),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v281)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v283),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v282))),
                   (__m128)_mm_cmpgt_epi32(_mm_load_si128(&v279), v168));
          v184 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v171);
          v185 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 16];
          v186 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v173);
          v145 = 0i64;
          v187 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v175),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v174)),
                     _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v172), v184)),
                   (__m128)_mm_cmpgt_epi32(v175, v185));
          v188 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v177);
          v189 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 32];
          v190 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v181), v188),
                     _mm_or_ps(v186, (__m128)_mm_cmpgt_epi32((__m128i)0i64, v176))),
                   (__m128)_mm_cmpgt_epi32(v181, v189));
          v191 = _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v182), (__m128)_mm_cmpgt_epi32((__m128i)0i64, v180));
          v192 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 48];
          v164 = _mm_load_si128(&v277);
          v193 = _mm_and_ps((__m128)v185, v187);
          v194 = _mm_and_ps((__m128)v189, v190);
          v195 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v178);
          v157 = _mm_load_si128(&v287);
          v196 = _mm_or_ps(
                   _mm_or_ps(v191, _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v179), v195)),
                   (__m128)_mm_cmpgt_epi32(v182, v192));
          v197 = v190;
          v165 = _mm_load_si128(&v291);
          v198 = _mm_and_ps((__m128)v280, v183);
          v199 = _mm_andnot_ps(v183, (__m128)v279);
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 32] = _mm_or_ps(_mm_andnot_ps(v197, (__m128)v181), v194);
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))] = _mm_or_ps(v198, v199);
          v200 = v187;
          v166 = _mm_load_si128(&v289);
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 16] = _mm_or_ps(_mm_andnot_ps(v200, (__m128)v175), v193);
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 48] = _mm_or_ps(_mm_andnot_ps(v196, (__m128)v182), _mm_and_ps((__m128)v192, v196));
        }
        if ( !v158 )
        {
          v201 = _mm_load_si128(&v271);
          v202 = v165;
          v203 = v166;
          v204 = _mm_load_si128((const __m128i *)&v273);
          v205 = _mm_sub_epi32(v202, _mm_load_si128((const __m128i *)&v275));
          v206 = _mm_sub_epi32(v203, _mm_load_si128((const __m128i *)&v272));
          v207 = _mm_sub_epi32(v157, v204);
          v208 = _mm_sub_epi32(v164, v201);
          v209 = v206;
          v210 = _mm_sub_epi32(v207, v204);
          v211 = _mm_sub_epi32(v208, v201);
          v212 = _mm_sub_epi32(v210, v204);
          v213 = _mm_sub_epi32(v211, v201);
          v214 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v277),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v287)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v289),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v291))),
                   (__m128)_mm_cmpgt_epi32(
                             _mm_load_si128(&v277),
                             *(__m128i *)&v150[4
                                             * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                              + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                             + 64]));
          v215 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v208),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v207)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v206),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v205))),
                   (__m128)_mm_cmpgt_epi32(
                             v208,
                             *(__m128i *)&v150[4
                                             * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                              + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                             + 80]));
          v145 = 0i64;
          v216 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v211),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v210)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v206),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v205))),
                   (__m128)_mm_cmpgt_epi32(
                             v211,
                             *(__m128i *)&v150[4
                                             * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                              + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                             + 96]));
          v217 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v213),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v212)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v209),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v205))),
                   (__m128)_mm_cmpgt_epi32(
                             v213,
                             *(__m128i *)&v150[4
                                             * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                              + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                             + 112]));
          v218 = _mm_or_ps(
                   _mm_andnot_ps(v215, (__m128)v208),
                   _mm_and_ps(
                     v215,
                     *(__m128 *)&v150[4
                                    * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                     + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                    + 80]));
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 64] = _mm_or_ps(
                                   _mm_and_ps(
                                     v214,
                                     *(__m128 *)&v150[4
                                                    * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                                     + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                                    + 64]),
                                   _mm_andnot_ps(v214, (__m128)v277));
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 80] = v218;
          v219 = v217;
          v220 = _mm_and_ps(
                   v217,
                   *(__m128 *)&v150[4
                                  * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                   + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                  + 112]);
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 96] = _mm_or_ps(
                                   _mm_andnot_ps(v216, (__m128)v211),
                                   _mm_and_ps(
                                     v216,
                                     *(__m128 *)&v150[4
                                                    * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                                     + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                                    + 96]));
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 112] = _mm_or_ps(_mm_andnot_ps(v219, (__m128)v213), v220);
        }
        if ( !v160 )
        {
          v221 = _mm_load_si128((const __m128i *)&v273);
          v222 = _mm_load_si128((const __m128i *)&v275);
          v223 = _mm_load_si128(&v271);
          v224 = _mm_load_si128((const __m128i *)&v272);
          v225 = _mm_sub_epi32(_mm_load_si128(&v290), v222);
          v226 = _mm_sub_epi32(_mm_load_si128(&v293), v221);
          v227 = _mm_sub_epi32(_mm_load_si128(&v286), v224);
          v228 = _mm_sub_epi32(_mm_load_si128(&v276), v223);
          v229 = _mm_sub_epi32(v226, v221);
          v230 = _mm_sub_epi32(v225, v222);
          v231 = _mm_sub_epi32(v227, v224);
          v232 = _mm_sub_epi32(v229, v221);
          v233 = _mm_sub_epi32(v230, v222);
          v234 = _mm_sub_epi32(v231, v224);
          v235 = _mm_sub_epi32(v228, v223);
          v236 = _mm_sub_epi32(v235, v223);
          v237 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v276),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v293)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v286),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v290))),
                   (__m128)_mm_cmpgt_epi32(
                             _mm_load_si128(&v276),
                             *(__m128i *)&v150[4
                                             * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                              + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                             + 2048]));
          v238 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v225);
          v239 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 2064];
          v240 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v231);
          v145 = 0i64;
          v241 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v228),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v226)),
                     _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v227), v238)),
                   (__m128)_mm_cmpgt_epi32(v228, v239));
          v242 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v229);
          v243 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 2080];
          v244 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v235), v242),
                     _mm_or_ps(v240, (__m128)_mm_cmpgt_epi32((__m128i)0i64, v230))),
                   (__m128)_mm_cmpgt_epi32(v235, v243));
          v245 = _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v236), (__m128)_mm_cmpgt_epi32((__m128i)0i64, v232));
          v246 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 2096];
          v247 = _mm_or_ps(
                   _mm_or_ps(
                     v245,
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v234),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v233))),
                   (__m128)_mm_cmpgt_epi32(v236, v246));
          v248 = _mm_and_ps(
                   v237,
                   *(__m128 *)&v150[4
                                  * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                   + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                  + 2048]);
          v249 = _mm_andnot_ps(v237, (__m128)v276);
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 2064] = _mm_or_ps(_mm_andnot_ps(v241, (__m128)v228), _mm_and_ps(v241, (__m128)v239));
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 2048] = _mm_or_ps(v248, v249);
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 2096] = _mm_or_ps(_mm_andnot_ps(v247, (__m128)v236), _mm_and_ps(v247, (__m128)v246));
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 2080] = _mm_or_ps(_mm_andnot_ps(v244, (__m128)v235), _mm_and_ps(v244, (__m128)v243));
        }
        if ( !v163 )
        {
          v250 = _mm_load_si128((const __m128i *)&v273);
          v251 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 2144];
          v252 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 2112];
          v253 = _mm_load_si128(&v292);
          v254 = _mm_load_si128(&v278);
          v255 = _mm_load_si128(&v288);
          v256 = _mm_load_si128(&v274);
          v280 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 2128];
          v257 = _mm_sub_epi32(v256, v271);
          v258 = _mm_sub_epi32(v255, v250);
          v259 = *(__m128i *)&v150[4
                                 * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                                  + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                                 + 2160];
          v282 = v251;
          v260 = _mm_sub_epi32(v253, _mm_load_si128((const __m128i *)&v272));
          v283 = v259;
          v261 = _mm_sub_epi32(v254, _mm_load_si128((const __m128i *)&v275));
          v281 = v252;
          v262 = v260;
          v263 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v274),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v288)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v292),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v278))),
                   (__m128)_mm_cmpgt_epi32(_mm_load_si128(&v274), v252));
          v145 = 0i64;
          v264 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v257),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v258)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v260),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v261))),
                   (__m128)_mm_cmpgt_epi32(v257, v280));
          v265 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v257),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v258)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v260),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v261))),
                   (__m128)_mm_cmpgt_epi32(v257, v251));
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 2128] = _mm_or_ps(_mm_and_ps((__m128)v280, v264), _mm_andnot_ps(v264, (__m128)v257));
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 2144] = _mm_or_ps(_mm_and_ps((__m128)v251, v265), _mm_andnot_ps(v265, (__m128)v257));
          v266 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v257),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v258)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v262),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v261))),
                   (__m128)_mm_cmpgt_epi32(v257, v283));
          v267 = _mm_and_ps((__m128)v281, v263);
          v268 = _mm_andnot_ps(v263, (__m128)v274);
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 2160] = _mm_or_ps(_mm_and_ps((__m128)v283, v266), _mm_andnot_ps(v266, (__m128)v257));
          *(__m128 *)&v150[4
                         * (((4 * (v126 & 0xFFFFFFFC) + (v149 & 0xFFFFFFFC)) << 8)
                          + (unsigned __int64)(16 * (8 * (4 * (v126 & 3) + (v149 & 3u)) >> 2)))
                         + 2112] = _mm_or_ps(v267, v268);
        }
        v143 = v149 + 1;
      }
      while ( v144 );
    }
    v87 = (_OWORD *)v319;
  }
}

