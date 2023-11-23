// File Line: 220
// RVA: 0x6A45C0
void __fastcall Render::RasterizeZ::DrawAABB(
        Render::RasterizeZ *this,
        UFG::qVector3 *vmin,
        UFG::qVector3 *vmax,
        UFG::qMatrix44 *local_world)
{
  float y; // xmm0_4
  float v6; // xmm12_4
  float v7; // xmm14_4
  float v8; // xmm13_4
  float v9; // xmm6_4
  float v10; // xmm8_4
  float v11; // xmm12_4
  float v12; // xmm11_4
  float v13; // xmm5_4
  float v14; // xmm10_4
  float v15; // xmm13_4
  float v16; // xmm4_4
  float v17; // xmm15_4
  int v18; // xmm8_4
  float v19; // xmm12_4
  int v20; // xmm3_4
  unsigned __int8 v21; // r8
  float v22; // [rsp+20h] [rbp-D8h]
  float v23; // [rsp+24h] [rbp-D4h]
  float v24; // [rsp+24h] [rbp-D4h]
  float v25; // [rsp+28h] [rbp-D0h]
  float v26; // [rsp+2Ch] [rbp-CCh]
  float v27; // [rsp+30h] [rbp-C8h]
  float v28; // [rsp+34h] [rbp-C4h]
  float v29; // [rsp+38h] [rbp-C0h]
  float v30; // [rsp+3Ch] [rbp-BCh]
  float v31; // [rsp+3Ch] [rbp-BCh]
  float v32; // [rsp+40h] [rbp-B8h]
  float v33; // [rsp+44h] [rbp-B4h]
  float v34; // [rsp+44h] [rbp-B4h]
  float v35; // [rsp+4Ch] [rbp-ACh]
  float v36; // [rsp+50h] [rbp-A8h]
  float v37; // [rsp+58h] [rbp-A0h]
  UFG::qVector4 v38; // [rsp+60h] [rbp-98h] BYREF
  UFG::qVector4 v0; // [rsp+70h] [rbp-88h] BYREF
  float v40; // [rsp+80h] [rbp-78h]
  float v41; // [rsp+84h] [rbp-74h]
  UFG::qVector4 v42; // [rsp+88h] [rbp-70h] BYREF
  float v43; // [rsp+98h] [rbp-60h]
  int v44; // [rsp+9Ch] [rbp-5Ch]
  UFG::qVector4 v45; // [rsp+A0h] [rbp-58h] BYREF
  float v46; // [rsp+B0h] [rbp-48h]
  UFG::qVector4 v1; // [rsp+B8h] [rbp-40h] BYREF
  float v48; // [rsp+C8h] [rbp-30h]
  UFG::qVector4 v2; // [rsp+D0h] [rbp-28h] BYREF
  float v50; // [rsp+E0h] [rbp-18h]
  UFG::qVector4 v51; // [rsp+E8h] [rbp-10h] BYREF
  float v52; // [rsp+F8h] [rbp+0h]
  UFG::qMatrix44 result; // [rsp+108h] [rbp+10h] BYREF
  void *retaddr; // [rsp+1F8h] [rbp+100h]
  float v55; // [rsp+208h] [rbp+110h]

  y = vmax->y;
  v6 = (float)(y - vmin->y) * 0.5;
  v7 = (float)(vmax->x + vmin->x) * 0.5;
  v8 = (float)(vmax->z + vmin->z) * 0.5;
  *(float *)&retaddr = (float)(y + vmin->y) * 0.5;
  v23 = (float)(vmax->z - vmin->z) * 0.5;
  v9 = (float)(vmax->x - vmin->x) * 0.5;
  UFG::qMatrix44::operator*(local_world, (UFG::qMatrix44 *)&result.v0.z, this->mWorldViewProjection);
  v32 = result.v1.x * v6;
  v29 = result.v1.y * v6;
  v27 = result.v1.z * v6;
  v26 = v6 * result.v1.w;
  v22 = result.v2.x * v23;
  v25 = result.v2.y * v23;
  v37 = result.v2.z * v23;
  v24 = v23 * result.v2.w;
  v10 = result.v1.x * v6;
  v11 = (float)((float)((float)(*(float *)&retaddr * result.v1.x) + (float)(v7 * result.v0.x))
              + (float)(v8 * result.v2.x))
      + result.v3.x;
  v28 = v11 - (float)(result.v0.x * v9);
  v12 = (float)((float)((float)(*(float *)&retaddr * result.v1.y) + (float)(v7 * result.v0.y))
              + (float)(v8 * result.v2.y))
      + result.v3.y;
  v13 = (float)((float)(*(float *)&retaddr * result.v1.w) + (float)(v7 * result.v0.w)) + (float)(v8 * result.v2.w);
  v14 = (float)((float)((float)((float)(*(float *)&retaddr * result.v1.z) + (float)(v7 * result.v0.z))
                      + (float)(v8 * result.v2.z))
              + result.v3.z)
      - (float)(result.v0.z * v9);
  v33 = (float)((float)((float)(*(float *)&retaddr * result.v1.z) + (float)(v7 * result.v0.z))
              + (float)(v8 * result.v2.z))
      + result.v3.z;
  v30 = (float)(v13 + result.v3.w) - (float)(v9 * result.v0.w);
  v15 = v12 - (float)(result.v0.y * v9);
  v50 = (float)(v14 - v27) + v37;
  v35 = (float)(v30 - v26) + v24;
  v36 = v30 - v26;
  v16 = (float)(result.v0.x * v9) + v11;
  v43 = (float)(v28 - v32) + v22;
  v0.x = v43;
  v48 = (float)(v15 - v29) + v25;
  v0.y = v48;
  v55 = v12 + (float)(result.v0.y * v9);
  *(float *)&retaddr = (float)(v13 + result.v3.w) + (float)(v9 * result.v0.w);
  v34 = v33 + (float)(result.v0.z * v9);
  v31 = v30 + v26;
  v46 = (float)(v16 + v10) + v22;
  v42.x = v46;
  v52 = (float)(v55 + v29) + v25;
  v42.y = v52;
  v17 = (float)(*(float *)&retaddr + v26) + v24;
  v42.z = (float)(v34 + v27) + v37;
  v1.x = (float)(v16 - v10) + v22;
  v1.y = (float)(v55 - v29) + v25;
  v1.z = (float)(v34 - v27) + v37;
  v1.w = (float)(*(float *)&retaddr - v26) + v24;
  v2.x = (float)(v28 + v10) + v22;
  v2.y = (float)(v15 + v29) + v25;
  v2.z = (float)(v14 + v27) + v37;
  v2.w = v31 + v24;
  v42.w = v17;
  v38.x = (float)(v16 - v10) - v22;
  v38.y = (float)(v55 - v29) - v25;
  v51.z = (float)(v34 + v27) - v37;
  v38.z = (float)(v34 - v27) - v37;
  v38.w = (float)(*(float *)&retaddr - v26) - v24;
  v45.x = (float)(v28 - v32) - v22;
  v45.y = (float)(v15 - v29) - v25;
  v45.z = (float)(v14 - v27) - v37;
  v45.w = v36 - v24;
  v51.x = (float)(v16 + v10) - v22;
  v51.y = (float)(v55 + v29) - v25;
  v51.w = (float)(*(float *)&retaddr + v26) - v24;
  v0.w = (float)(v15 + v29) - v25;
  v0.z = (float)(v28 + v10) - v22;
  v18 = LODWORD(v17) ^ _xmm[0];
  LODWORD(v19) = COERCE_UNSIGNED_INT(v36 - v24) ^ _xmm[0];
  v40 = (float)(v14 + v27) - v37;
  v41 = v31 - v24;
  v44 = LODWORD(v35) ^ _xmm[0];
  v20 = LODWORD(v38.w) ^ _xmm[0];
  v21 = ((COERCE_FLOAT(LODWORD(v41) ^ _xmm[0]) > v0.z) | (2
                                                        * ((v0.z > v41) | (2
                                                                         * ((COERCE_FLOAT(LODWORD(v41) ^ _xmm[0]) > v0.w) | (2 * ((v0.w > v41) | (2 * ((v40 < 0.0) | (2 * (v40 > v41))))))))))) & ((COERCE_FLOAT(LODWORD(v51.w) ^ _xmm[0]) > v51.x) | (2 * ((v51.x > v51.w) | (2 * ((COERCE_FLOAT(LODWORD(v51.w) ^ _xmm[0]) > v51.y) | (2 * ((v51.y > v51.w) | (2 * ((v51.z < 0.0) | (2 * (v51.z > v51.w))))))))))) & ((v19 > v45.x) | (2 * ((v45.x > v45.w) | (2 * ((v19 > v45.y) | (2 * ((v45.y > v45.w) | (2 * ((v45.z < 0.0) | (2 * (v45.z > v45.w))))))))))) & ((*(float *)&v18 > v46) | (2 * ((v46 > v17) | (2 * ((*(float *)&v18 > v52) | (2 * ((v52 > v17) | (2 * ((v42.z < 0.0) | (2 * (v42.z > v17))))))))))) & ((*(float *)&v20 > v38.x) | (2 * ((v38.x > v38.w) | (2 * ((*(float *)&v20 > v38.y) | (2 * ((v38.y > v38.w) | (2 * ((v38.z < 0.0) | (2 * (v38.z > v38.w))))))))))) & ((COERCE_FLOAT(LODWORD(v2.w) ^ _xmm[0]) > v2.x) | (2 * ((v2.x > v2.w) | (2 * ((COERCE_FLOAT(LODWORD(v2.w) ^ _xmm[0]) > v2.y) | (2 * ((v2.y > v2.w) | (2 * ((v2.z < 0.0) | (2 * (v2.z > v2.w))))))))))) & ((COERCE_FLOAT(LODWORD(v1.w) ^ _xmm[0]) > v1.x) | (2 * ((v1.x > v1.w) | (2 * ((COERCE_FLOAT(LODWORD(v1.w) ^ _xmm[0]) > v1.y) | (2 * ((v1.y > v1.w) | (2 * ((v1.z < 0.0) | (2 * (v1.z > v1.w)))))))))));
  if ( (v21 & (unsigned __int8)((COERCE_FLOAT(LODWORD(v35) ^ _xmm[0]) > v43) | (2
                                                                              * ((v43 > v35) | (2
                                                                                              * ((COERCE_FLOAT(LODWORD(v35) ^ _xmm[0]) > v48) | (2 * ((v48 > v35) | (2 * ((v50 < 0.0) | (2 * (v50 > v35)))))))))))) == 0 )
  {
    Render::RasterizeZ::Draw2DH(this, &v0, &v1, &v2);
    Render::RasterizeZ::Draw2DH(this, &v2, &v1, &v42);
    Render::RasterizeZ::Draw2DH(this, &v1, &v38, &v42);
    Render::RasterizeZ::Draw2DH(this, &v42, &v38, &v51);
    Render::RasterizeZ::Draw2DH(this, &v38, &v45, &v51);
    Render::RasterizeZ::Draw2DH(this, &v51, &v45, (UFG::qVector4 *)&v0.z);
    Render::RasterizeZ::Draw2DH(this, &v45, &v0, (UFG::qVector4 *)&v0.z);
    Render::RasterizeZ::Draw2DH(this, (UFG::qVector4 *)&v0.z, &v0, &v2);
    Render::RasterizeZ::Draw2DH(this, &v45, &v38, &v0);
    Render::RasterizeZ::Draw2DH(this, &v0, &v38, &v1);
    Render::RasterizeZ::Draw2DH(this, &v2, &v42, (UFG::qVector4 *)&v0.z);
    Render::RasterizeZ::Draw2DH(this, (UFG::qVector4 *)&v0.z, &v42, &v51);
  }
}

// File Line: 733
// RVA: 0x6A2D40
void __fastcall Render::RasterizeZ::Draw2DH(
        Render::RasterizeZ *this,
        UFG::qVector4 *v0,
        UFG::qVector4 *v1,
        UFG::qVector4 *v2)
{
  float w; // xmm6_4
  float y; // xmm3_4
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
  float v26; // xmm5_4
  float v27; // xmm9_4
  float v28; // xmm10_4
  float v29; // xmm11_4
  float v30; // xmm9_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm14_4
  float v34; // xmm15_4
  float v35; // xmm13_4
  float v36; // xmm10_4
  float v37; // xmm4_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm12_4
  float v41; // xmm15_4
  float v42; // xmm8_4
  float v43; // xmm13_4
  float v44; // xmm0_4
  float v45; // xmm10_4
  float v46; // xmm9_4
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm11_4
  float v50; // xmm14_4
  float v51; // xmm4_4
  int v52; // ecx
  int v53; // edx
  int v54; // r8d
  int v55; // esi
  signed int v56; // r9d
  unsigned int v57; // edi
  signed int v58; // ebx
  signed int v59; // r10d
  signed int v60; // r13d
  signed int v61; // r11d
  int v62; // r14d
  int v63; // ebp
  int v64; // r12d
  int v65; // r15d
  int v66; // r14d
  int v67; // eax
  unsigned int v68; // r8d
  unsigned int v69; // ecx
  int v70; // edx
  unsigned int v71; // r14d
  int v72; // r15d
  int v73; // edx
  int v74; // r12d
  int v75; // edx
  unsigned int v76; // esi
  int v77; // edx
  __m128i v78; // xmm5
  __m128i v79; // xmm15
  __m128i v80; // xmm8
  __m128i v81; // xmm4
  __m128i v82; // xmm3
  __m128i v83; // xmm0
  __m128i v84; // xmm1
  __m128i v85; // xmm3
  __m128i v86; // xmm2
  __m128i v87; // xmm3
  __m128i v88; // xmm0
  __m128i v89; // xmm6
  __m128i v90; // xmm0
  __m128i v91; // xmm1
  __m128i v92; // xmm5
  int v93; // r14d
  unsigned int i; // r15d
  bool v95; // zf
  int v96; // eax
  int v97; // ecx
  __m128i v98; // xmm15
  __m128i v99; // xmm4
  int v100; // r14d
  int v101; // r9d
  unsigned int v102; // edx
  __m128i v103; // xmm7
  int v104; // eax
  int v105; // ecx
  __m128i v106; // xmm0
  int v107; // r9d
  char *mZBuffer; // rcx
  unsigned __int64 v109; // r8
  __m128i v110; // xmm5
  __m128i v111; // xmm1
  __m128i v112; // xmm4
  __m128i v113; // xmm3
  __m128i v114; // xmm8
  __m128i v115; // xmm11
  BOOL v116; // r11d
  __m128i v117; // xmm1
  BOOL v118; // ebx
  __m128i v119; // xmm2
  __m128i v120; // xmm5
  BOOL v121; // edi
  __m128i v122; // xmm10
  __m128i v123; // xmm3
  __m128i v124; // xmm6
  __m128i si128; // xmm0
  __m128i v126; // xmm12
  __m128i v127; // xmm9
  __m128i v128; // xmm1
  __m128i v129; // xmm9
  __m128i v130; // xmm3
  __m128i v131; // xmm7
  __m128i v132; // xmm2
  __m128i v133; // xmm15
  __m128i v134; // xmm10
  __m128i v135; // xmm4
  __m128i v136; // xmm11
  __m128i v137; // xmm8
  __m128i v138; // xmm5
  __m128i v139; // xmm14
  __m128i v140; // xmm13
  __m128 v141; // xmm12
  __m128 v142; // xmm0
  __m128i v143; // xmm9
  __m128 v144; // xmm1
  __m128 v145; // xmm6
  __m128 v146; // xmm0
  __m128i v147; // xmm4
  __m128 v148; // xmm3
  __m128 v149; // xmm2
  __m128i v150; // xmm5
  __m128 v151; // xmm9
  __m128 v152; // xmm4
  __m128 v153; // xmm0
  __m128 v154; // xmm2
  __m128 v155; // xmm1
  __m128 v156; // xmm0
  __m128 v157; // xmm12
  __m128 v158; // xmm0
  __m128i v159; // xmm0
  __m128i v160; // xmm12
  __m128i v161; // xmm1
  __m128i v162; // xmm9
  __m128i v163; // xmm3
  __m128i v164; // xmm6
  __m128i v165; // xmm9
  __m128i v166; // xmm3
  __m128i v167; // xmm7
  __m128i v168; // xmm2
  __m128i v169; // xmm15
  __m128i v170; // xmm10
  __m128i v171; // xmm8
  __m128i v172; // xmm4
  __m128i v173; // xmm14
  __m128i v174; // xmm5
  __m128i v175; // xmm13
  __m128 v176; // xmm12
  __m128 v177; // xmm6
  __m128 v178; // xmm1
  __m128 v179; // xmm3
  __m128 v180; // xmm2
  __m128 v181; // xmm1
  __m128 v182; // xmm1
  __m128 v183; // xmm1
  __m128 v184; // xmm2
  __m128i v185; // xmm6
  __m128i v186; // xmm0
  __m128i v187; // xmm12
  __m128i v188; // xmm1
  __m128i v189; // xmm9
  __m128i v190; // xmm2
  __m128i v191; // xmm3
  __m128i v192; // xmm15
  __m128i v193; // xmm4
  __m128i v194; // xmm10
  __m128i v195; // xmm7
  __m128i v196; // xmm5
  __m128i v197; // xmm11
  __m128i v198; // xmm8
  __m128i v199; // xmm14
  __m128i v200; // xmm13
  __m128 v201; // xmm12
  __m128 v202; // xmm0
  __m128i v203; // xmm9
  __m128 v204; // xmm1
  __m128 v205; // xmm6
  __m128 v206; // xmm0
  __m128i v207; // xmm4
  __m128 v208; // xmm3
  __m128 v209; // xmm2
  __m128i v210; // xmm5
  __m128 v211; // xmm2
  __m128 v212; // xmm0
  __m128 v213; // xmm12
  __m128i v214; // xmm12
  __m128i v215; // xmm1
  __m128i v216; // xmm6
  __m128i v217; // xmm3
  __m128i v218; // xmm9
  __m128i v219; // xmm2
  __m128i v220; // xmm15
  __m128i v221; // xmm15
  __m128i v222; // xmm2
  __m128i v223; // xmm0
  __m128i v224; // xmm1
  __m128i v225; // xmm3
  __m128i v226; // xmm0
  __m128i v227; // xmm9
  __m128i v228; // xmm7
  __m128i v229; // xmm10
  __m128i v230; // xmm4
  __m128i v231; // xmm8
  __m128i v232; // xmm5
  __m128i v233; // xmm14
  __m128i v234; // xmm13
  __m128 v235; // xmm12
  __m128 v236; // xmm1
  __m128 v237; // xmm6
  __m128 v238; // xmm3
  __m128 v239; // xmm4
  __m128 v240; // xmm2
  __m128 v241; // xmm0
  __m128 v242; // xmm12
  unsigned int v243; // [rsp+0h] [rbp-598h]
  unsigned int v244; // [rsp+8h] [rbp-590h]
  __m128i v245; // [rsp+10h] [rbp-588h] BYREF
  __m128 v246; // [rsp+20h] [rbp-578h] BYREF
  __m128 v247; // [rsp+30h] [rbp-568h] BYREF
  __m128i v248; // [rsp+40h] [rbp-558h] BYREF
  __m128 v249; // [rsp+50h] [rbp-548h] BYREF
  __m128i v250; // [rsp+60h] [rbp-538h] BYREF
  __m128i v251; // [rsp+70h] [rbp-528h] BYREF
  __m128i v252; // [rsp+80h] [rbp-518h] BYREF
  __m128i v253; // [rsp+90h] [rbp-508h] BYREF
  __m128i v254; // [rsp+A0h] [rbp-4F8h]
  __m128i v255; // [rsp+B0h] [rbp-4E8h]
  __m128i v256; // [rsp+C0h] [rbp-4D8h]
  __m128i v257; // [rsp+D0h] [rbp-4C8h]
  __m128i v258; // [rsp+E0h] [rbp-4B8h]
  __m128i v259; // [rsp+F0h] [rbp-4A8h] BYREF
  __m128i v260; // [rsp+100h] [rbp-498h] BYREF
  __m128i v261; // [rsp+110h] [rbp-488h] BYREF
  __m128i v262; // [rsp+120h] [rbp-478h] BYREF
  __m128i v263; // [rsp+130h] [rbp-468h] BYREF
  __m128i v264; // [rsp+140h] [rbp-458h] BYREF
  __m128i v265; // [rsp+150h] [rbp-448h] BYREF
  __m128i v266; // [rsp+160h] [rbp-438h] BYREF
  __m128i v267; // [rsp+170h] [rbp-428h] BYREF
  __m128i v268; // [rsp+180h] [rbp-418h]
  __m128i v269; // [rsp+190h] [rbp-408h]
  __m128i v270; // [rsp+1A0h] [rbp-3F8h]
  __m128i v271; // [rsp+1B0h] [rbp-3E8h]
  __m128i v272; // [rsp+1C0h] [rbp-3D8h]
  __m128i v273; // [rsp+1D0h] [rbp-3C8h]
  __m128i v274; // [rsp+1E0h] [rbp-3B8h]
  __m128i v275; // [rsp+1F0h] [rbp-3A8h]
  __m128i v276; // [rsp+200h] [rbp-398h] BYREF
  __m128i v277; // [rsp+210h] [rbp-388h]
  __m128i v278; // [rsp+220h] [rbp-378h]
  __m128i v279; // [rsp+230h] [rbp-368h]
  __m128i v280; // [rsp+240h] [rbp-358h]
  __m128i v281; // [rsp+250h] [rbp-348h]
  __m128i v282; // [rsp+260h] [rbp-338h] BYREF
  __m128i v283; // [rsp+270h] [rbp-328h]
  __m128i v284; // [rsp+280h] [rbp-318h]
  __m128i v285; // [rsp+290h] [rbp-308h]
  __m128i v286; // [rsp+2A0h] [rbp-2F8h]
  __m128i v287; // [rsp+2B0h] [rbp-2E8h]
  __m128i v288; // [rsp+2C0h] [rbp-2D8h]
  __m128i v289; // [rsp+2D0h] [rbp-2C8h]
  __m128i v290; // [rsp+2E0h] [rbp-2B8h]
  __m128i v291; // [rsp+2F0h] [rbp-2A8h]
  __m128i v292; // [rsp+300h] [rbp-298h]
  __m128i v293; // [rsp+310h] [rbp-288h]
  __m128i v294; // [rsp+320h] [rbp-278h]
  __m128i v295; // [rsp+330h] [rbp-268h]
  __m128i v296; // [rsp+340h] [rbp-258h]
  __m128 v297; // [rsp+350h] [rbp-248h]
  __m128 v298; // [rsp+360h] [rbp-238h]
  __m128 v299; // [rsp+370h] [rbp-228h]
  __m128 v300; // [rsp+380h] [rbp-218h]
  __m128i v301; // [rsp+3A0h] [rbp-1F8h]
  __m128i v302; // [rsp+3B0h] [rbp-1E8h]
  __m128i v303; // [rsp+3C0h] [rbp-1D8h]
  __m128i v304; // [rsp+3D0h] [rbp-1C8h]
  __m128i v305; // [rsp+3E0h] [rbp-1B8h]
  __m128i v306; // [rsp+3F0h] [rbp-1A8h]
  __m128i v307; // [rsp+400h] [rbp-198h]
  __m128i v308; // [rsp+410h] [rbp-188h]
  __m128i v309; // [rsp+420h] [rbp-178h]
  __m128i v310; // [rsp+430h] [rbp-168h]
  __m128i v311; // [rsp+440h] [rbp-158h]
  __m128i v312; // [rsp+450h] [rbp-148h]
  __m128 v313; // [rsp+460h] [rbp-138h]
  __m128 v314; // [rsp+470h] [rbp-128h]
  __m128 v315; // [rsp+480h] [rbp-118h]
  __m128 v316; // [rsp+490h] [rbp-108h]
  float v318; // [rsp+5A8h] [rbp+10h]
  int v319; // [rsp+5A8h] [rbp+10h]
  float v320; // [rsp+5B0h] [rbp+18h]
  float v321; // [rsp+5B0h] [rbp+18h]
  float v322; // [rsp+5B8h] [rbp+20h]

  w = v1->w;
  y = v1->y;
  v6 = v0->w;
  v7 = v2->w;
  v8 = v0->y;
  v9 = v2->y;
  v10 = (float)(w * v8) - (float)(y * v6);
  v11 = (float)(v7 * y) - (float)(v9 * w);
  v12 = (float)(v9 * v6) - (float)(v7 * v8);
  v13 = (float)(v1->x * v6) - (float)(v0->x * w);
  v14 = (float)(v2->x * w) - (float)(v1->x * v7);
  v15 = (float)(v0->x * v7) - (float)(v2->x * v6);
  v320 = v15;
  v16 = (float)(v0->x * y) - (float)(v1->x * v8);
  v17 = (float)(v1->x * v9) - (float)(v2->x * y);
  v18 = (float)(v2->x * v8) - (float)(v0->x * v9);
  v19 = (float)((float)(v7 * v16) + (float)(v6 * v17)) + (float)(w * v18);
  if ( v19 < 1.0 )
    return;
  v20 = 1.0 / v19;
  v21 = v17 + v16;
  v22 = v11 + v10;
  v23 = v11 * -1.0;
  v24 = v11 * 0.015625;
  v25 = v23 + v17;
  v26 = (float)((float)(v14 + v13) + v15) * v20;
  v27 = (float)(v10 * -1.0) + v16;
  v322 = (float)(v22 + v12) * v20;
  v28 = (float)(v12 * -1.0) + v18;
  v29 = v10 * 0.015625;
  v30 = v27 + (float)(v13 * -1.0);
  v31 = (float)(v322 * -1.0) + (float)((float)(v21 + v18) * v20);
  v32 = v14 * -1.0;
  v33 = v13 * 0.015625;
  v34 = v14 * 0.015625;
  v35 = v12 * 0.015625;
  v36 = v28 + (float)(v320 * -1.0);
  v321 = v320 * 0.015625;
  v318 = v31 + (float)(v26 * -1.0);
  v37 = (float)(1.0 / (float)(COERCE_FLOAT(LODWORD(v29) & _xmm) + COERCE_FLOAT(LODWORD(v33) & _xmm))) * 65536.0;
  v38 = (float)(1.0 / (float)(COERCE_FLOAT(LODWORD(v24) & _xmm) + COERCE_FLOAT(LODWORD(v34) & _xmm))) * 65536.0;
  v39 = (float)(1.0 / (float)(COERCE_FLOAT(LODWORD(v35) & _xmm) + COERCE_FLOAT(LODWORD(v321) & _xmm))) * 65536.0;
  v40 = v24 * v38;
  v41 = v34 * v38;
  v42 = (float)(v25 + v32) * v38;
  v43 = v35 * v39;
  v44 = v321 * v39;
  v45 = v36 * v39;
  v46 = v30 * v37;
  v47 = v318 * 65536.0;
  v48 = (float)(v26 * 0.015625) * 65536.0;
  v49 = v29 * v37;
  v50 = v33 * v37;
  v51 = FLOAT_1_6777216e7;
  if ( v46 <= -16777216.0 )
  {
    v46 = FLOAT_N1_6777216e7;
  }
  else if ( v46 >= 16777216.0 )
  {
    v46 = FLOAT_1_6777216e7;
  }
  if ( v42 <= -16777216.0 )
  {
    v42 = FLOAT_N1_6777216e7;
  }
  else if ( v42 >= 16777216.0 )
  {
    v42 = FLOAT_1_6777216e7;
  }
  if ( v45 <= -16777216.0 )
  {
    v45 = FLOAT_N1_6777216e7;
  }
  else if ( v45 >= 16777216.0 )
  {
    goto LABEL_15;
  }
  v51 = v45;
LABEL_15:
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = -(int)(float)((float)(v322 * 0.015625) * 65536.0);
  v57 = -(int)v48;
  v58 = (int)v49;
  v59 = (int)v40;
  v60 = (int)v41;
  v319 = (int)v51;
  v61 = (int)v43;
  v62 = (int)v44;
  v63 = 0x10000 - (int)v47;
  if ( (int)v50 < 0 )
    v52 = -(int)v50;
  v64 = 0;
  if ( v58 > 0 )
    v64 = (int)v49;
  if ( v60 < 0 )
    v53 = -v60;
  v65 = 0;
  if ( v59 > 0 )
    v65 = (int)v40;
  if ( v62 < 0 )
    v54 = -v62;
  v66 = 0;
  if ( v61 > 0 )
    v66 = (int)v43;
  if ( (int)v48 > 0 )
    v55 = (int)v48;
  v67 = 0;
  if ( (int)(float)((float)(v322 * 0.015625) * 65536.0) < 0 )
    v67 = -(int)(float)((float)(v322 * 0.015625) * 65536.0);
  v68 = v66 + v54;
  v244 = v64 + v52;
  v69 = v53 + v65;
  v70 = (int)v49;
  v243 = v55 + v67;
  if ( v58 < 0 )
    v70 = -v58;
  v71 = (int)v50;
  if ( v58 < 0 || v70 < 256 && (int)v50 > 0 )
    v72 = (int)v46 + 1;
  else
    v72 = (int)v46;
  v73 = (int)v40;
  if ( v59 < 0 )
    v73 = -v59;
  if ( v59 < 0 || v73 < 256 && v60 > 0 )
    v74 = (int)v42 + 1;
  else
    v74 = (int)v42;
  v75 = (int)v43;
  if ( v61 < 0 )
    v75 = -v61;
  v76 = (int)v44;
  if ( v61 < 0 || v75 < 256 && (int)v44 > 0 )
    v319 = (int)v51 + 1;
  v77 = -(int)(float)((float)(v322 * 0.015625) * 65536.0);
  if ( (int)(float)((float)(v322 * 0.015625) * 65536.0) > 0 )
    v77 = (int)(float)((float)(v322 * 0.015625) * 65536.0);
  if ( v56 < 0 || v77 < 256 && (int)v48 < 0 )
    ++v63;
  v78 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v58), _mm_cvtsi32_si128(v61)),
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v59), _mm_cvtsi32_si128(v56)));
  v79 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v71), _mm_cvtsi32_si128(v76)),
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v60), _mm_cvtsi32_si128(v57)));
  v283 = _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v78, (__m128)v78, 0), 2u);
  v270 = _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 85), 2u);
  v275 = _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v78, (__m128)v78, 85), 2u);
  v274 = _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 255), 2u);
  v246 = _mm_shuffle_ps((__m128)v79, (__m128)v79, 85);
  v281 = _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v78, (__m128)v78, 170), 2u);
  v245 = (__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 255);
  v277 = _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v78, (__m128)v78, 255), 2u);
  v269 = _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 0), 2u);
  v272 = _mm_slli_epi32((__m128i)_mm_shuffle_ps((__m128)v79, (__m128)v79, 170), 2u);
  v80 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v244), _mm_cvtsi32_si128(v68)),
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v69), _mm_cvtsi32_si128(v243)));
  v282 = _mm_slli_epi32(v80, 2u);
  v258 = _mm_slli_epi32(v80, 3u);
  v268 = _mm_slli_epi32(v80, 5u);
  v249 = _mm_shuffle_ps((__m128)v79, (__m128)v79, 0);
  v247 = _mm_shuffle_ps((__m128)v79, (__m128)v79, 170);
  v81 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(2 * v58), _mm_cvtsi32_si128(2 * v61)),
          _mm_unpacklo_epi32(
            _mm_cvtsi32_si128(2 * v59),
            _mm_cvtsi32_si128(-2 * (int)(float)((float)(v322 * 0.015625) * 65536.0))));
  v82 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(3 * v58), _mm_cvtsi32_si128(3 * v61)),
          _mm_unpacklo_epi32(
            _mm_cvtsi32_si128(3 * v59),
            _mm_cvtsi32_si128(-3 * (int)(float)((float)(v322 * 0.015625) * 65536.0))));
  v83 = _mm_unpacklo_epi32(v78, v82);
  v84 = _mm_unpackhi_epi32(v78, v82);
  v85 = _mm_unpacklo_epi32((__m128i)0i64, v81);
  v86 = _mm_unpackhi_epi32(v85, v83);
  v87 = _mm_unpacklo_epi32(v85, v83);
  v88 = _mm_unpackhi_epi32((__m128i)0i64, v81);
  v271 = v86;
  v89 = _mm_unpackhi_epi32(v88, v84);
  v279 = _mm_unpacklo_epi32(v88, v84);
  v90 = v78;
  v91 = v78;
  v92 = _mm_slli_epi32(v78, 5u);
  v278 = _mm_slli_epi32(v90, 2u);
  v276 = _mm_slli_epi32(v91, 3u);
  v280 = _mm_slli_epi32(v79, 2u);
  v259 = _mm_slli_epi32(v79, 3u);
  v284 = v87;
  v273 = v89;
  v252 = _mm_slli_epi32(v79, 5u);
  v285 = _mm_add_epi32(
           _mm_unpacklo_epi32(
             _mm_unpacklo_epi32(_mm_cvtsi32_si128(v72 + 127 * v71), _mm_cvtsi32_si128(v319 + 127 * v76)),
             _mm_unpacklo_epi32(_mm_cvtsi32_si128(v74 + 127 * v60), _mm_cvtsi32_si128(v63 + 127 * v57))),
           v268);
  v286 = _mm_add_epi32(v285, v92);
  v287 = _mm_add_epi32(v286, v92);
  v288 = _mm_add_epi32(v287, v92);
  v289 = _mm_sub_epi32(v285, v252);
  v290 = _mm_sub_epi32(v286, v252);
  v291 = _mm_sub_epi32(v287, v252);
  v292 = _mm_sub_epi32(v288, v252);
  v293 = _mm_sub_epi32(v289, v252);
  v294 = _mm_sub_epi32(v290, v252);
  v295 = _mm_sub_epi32(v291, v252);
  v296 = _mm_sub_epi32(v292, v252);
  v297 = (__m128)_mm_sub_epi32(v293, v252);
  v298 = (__m128)_mm_sub_epi32(v294, v252);
  v299 = (__m128)_mm_sub_epi32(v295, v252);
  v300 = (__m128)_mm_sub_epi32(v296, v252);
  v93 = 0;
  for ( i = ((_mm_movemask_ps(v300) == 0) | (2
                                           * ((_mm_movemask_ps(v299) == 0) | (2
                                                                            * ((_mm_movemask_ps(v298) == 0) | (2 * ((_mm_movemask_ps(v297) == 0) | (2 * ((_mm_movemask_ps((__m128)v296) == 0) | (2 * ((_mm_movemask_ps((__m128)v295) == 0) | (2 * ((_mm_movemask_ps((__m128)v294) == 0) | (2 * ((_mm_movemask_ps((__m128)v293) == 0) | (2 * ((_mm_movemask_ps((__m128)v292) == 0) | (2 * ((_mm_movemask_ps((__m128)v291) == 0) | (2 * ((_mm_movemask_ps((__m128)v290) == 0) | (2 * ((_mm_movemask_ps((__m128)v289) == 0) | (2 * ((_mm_movemask_ps((__m128)v288) == 0) | (2 * ((_mm_movemask_ps((__m128)v287) == 0) | (2 * ((_mm_movemask_ps((__m128)v286) == 0) | (2 * (_mm_movemask_ps((__m128)v285) == 0))))))))))))))))))))))))))))))) << 16;
        i;
        v93 = v100 + 1 )
  {
    v95 = !_BitScanReverse((unsigned int *)&v96, i);
    if ( v95 )
      v97 = 0;
    else
      v97 = 31 - v96;
    v98 = _mm_load_si128(&v259);
    v99 = _mm_load_si128(&v276);
    v100 = v97 + v93;
    i <<= v97 + 1;
    v301 = _mm_add_epi32(_mm_sub_epi32(*(&v285 + v100), v268), v258);
    v302 = _mm_add_epi32(v301, v99);
    v303 = _mm_add_epi32(v302, v99);
    v304 = _mm_add_epi32(v303, v99);
    v305 = _mm_sub_epi32(v301, v98);
    v306 = _mm_sub_epi32(v302, v98);
    v307 = _mm_sub_epi32(v303, v98);
    v308 = _mm_sub_epi32(v304, v98);
    v309 = _mm_sub_epi32(v305, v98);
    v310 = _mm_sub_epi32(v306, v98);
    v311 = _mm_sub_epi32(v307, v98);
    v312 = _mm_sub_epi32(v308, v98);
    v313 = (__m128)_mm_sub_epi32(v309, v98);
    v314 = (__m128)_mm_sub_epi32(v310, v98);
    v315 = (__m128)_mm_sub_epi32(v311, v98);
    v316 = (__m128)_mm_sub_epi32(v312, v259);
    v101 = 0;
    v102 = ((_mm_movemask_ps(v316) == 0) | (2
                                          * ((_mm_movemask_ps(v315) == 0) | (2
                                                                           * ((_mm_movemask_ps(v314) == 0) | (2 * ((_mm_movemask_ps(v313) == 0) | (2 * ((_mm_movemask_ps((__m128)v312) == 0) | (2 * ((_mm_movemask_ps((__m128)v311) == 0) | (2 * ((_mm_movemask_ps((__m128)v310) == 0) | (2 * ((_mm_movemask_ps((__m128)v309) == 0) | (2 * ((_mm_movemask_ps((__m128)v308) == 0) | (2 * ((_mm_movemask_ps((__m128)v307) == 0) | (2 * ((_mm_movemask_ps((__m128)v306) == 0) | (2 * ((_mm_movemask_ps((__m128)v305) == 0) | (2 * ((_mm_movemask_ps((__m128)v304) == 0) | (2 * ((_mm_movemask_ps((__m128)v303) == 0) | (2 * ((_mm_movemask_ps((__m128)v302) == 0) | (2 * (_mm_movemask_ps((__m128)v301) == 0))))))))))))))))))))))))))))))) << 16;
    if ( v102 )
    {
      v103 = 0i64;
      do
      {
        v95 = !_BitScanReverse((unsigned int *)&v104, v102);
        if ( v95 )
          v105 = 0;
        else
          v105 = 31 - v104;
        v106 = _mm_load_si128(&v282);
        v107 = v105 + v101;
        v102 <<= v105 + 1;
        mZBuffer = (char *)this->mZBuffer;
        v109 = ((4 * (v100 & 0xFFFFFFFC) + (v107 & 0xFFFFFFFC)) << 8)
             + (unsigned __int64)(16 * ((8 * (4 * (v100 & 3) + (v107 & 3u))) >> 2));
        v110 = _mm_sub_epi32(*(&v301 + v107), v258);
        v111 = _mm_add_epi32(v110, v278);
        v112 = _mm_add_epi32(v110, v106);
        v113 = _mm_sub_epi32(v111, v280);
        v114 = _mm_add_epi32((__m128i)_mm_shuffle_ps((__m128)v110, (__m128)v110, 170), v279);
        v255 = v114;
        v115 = _mm_add_epi32(v114, v281);
        v116 = _mm_movemask_epi8(_mm_cmpgt_epi32(v103, _mm_add_epi32(v111, v106))) != 0;
        v261 = v115;
        v117 = _mm_add_epi32((__m128i)_mm_shuffle_ps((__m128)v110, (__m128)v110, 0), v284);
        v118 = _mm_movemask_epi8(_mm_cmpgt_epi32(v103, _mm_add_epi32(_mm_sub_epi32(v110, v280), v106))) != 0;
        v256 = v117;
        v119 = _mm_add_epi32((__m128i)_mm_shuffle_ps((__m128)v110, (__m128)v110, 85), v271);
        v120 = _mm_add_epi32((__m128i)_mm_shuffle_ps((__m128)v110, (__m128)v110, 255), v273);
        v121 = _mm_movemask_epi8(_mm_cmpgt_epi32(v103, _mm_add_epi32(v113, v106))) != 0;
        v257 = v119;
        v122 = _mm_add_epi32(v120, v277);
        v123 = _mm_add_epi32(v117, v283);
        v264 = _mm_sub_epi32(v117, v269);
        v253 = v120;
        v251 = v122;
        v124 = _mm_add_epi32(v119, v275);
        v265 = v123;
        v263 = v124;
        v260 = _mm_sub_epi32(v119, v270);
        v267 = _mm_sub_epi32(v114, v272);
        v250 = _mm_sub_epi32(v120, v274);
        v252 = _mm_sub_epi32(v123, v269);
        v266 = _mm_sub_epi32(v124, v270);
        v262 = _mm_sub_epi32(v115, v272);
        v248 = _mm_sub_epi32(v122, v274);
        if ( !_mm_movemask_epi8(_mm_cmpgt_epi32(v103, v112)) )
        {
          si128 = _mm_load_si128((const __m128i *)&v249);
          v126 = _mm_load_si128((const __m128i *)&v247);
          v127 = v117;
          v128 = _mm_load_si128((const __m128i *)&v246);
          v129 = _mm_sub_epi32(v127, si128);
          v130 = _mm_sub_epi32(v119, v128);
          v254 = *(__m128i *)&mZBuffer[4 * v109];
          v131 = _mm_sub_epi32(v130, v128);
          v132 = _mm_sub_epi32(v114, v126);
          v133 = _mm_sub_epi32(v120, v245);
          v134 = _mm_sub_epi32(v129, si128);
          v135 = _mm_sub_epi32(v132, v126);
          v136 = _mm_sub_epi32(v134, si128);
          v137 = _mm_sub_epi32(v131, v128);
          v138 = _mm_sub_epi32(v135, v126);
          v139 = _mm_sub_epi32(v133, v245);
          v140 = _mm_sub_epi32(v139, v245);
          v141 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v253),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v255)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v257),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v256))),
                   (__m128)_mm_cmpgt_epi32(_mm_load_si128(&v253), v254));
          v142 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v129);
          v143 = *(__m128i *)&mZBuffer[4 * v109 + 16];
          v144 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v131);
          v103 = 0i64;
          v145 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v133),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v132)),
                     _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v130), v142)),
                   (__m128)_mm_cmpgt_epi32(v133, v143));
          v146 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v135);
          v147 = *(__m128i *)&mZBuffer[4 * v109 + 32];
          v148 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v139), v146),
                     _mm_or_ps(v144, (__m128)_mm_cmpgt_epi32((__m128i)0i64, v134))),
                   (__m128)_mm_cmpgt_epi32(v139, v147));
          v149 = _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v140), (__m128)_mm_cmpgt_epi32((__m128i)0i64, v138));
          v150 = *(__m128i *)&mZBuffer[4 * v109 + 48];
          v122 = _mm_load_si128(&v251);
          v151 = _mm_and_ps((__m128)v143, v145);
          v152 = _mm_and_ps((__m128)v147, v148);
          v153 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v136);
          v115 = _mm_load_si128(&v261);
          v154 = _mm_or_ps(
                   _mm_or_ps(v149, _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v137), v153)),
                   (__m128)_mm_cmpgt_epi32(v140, v150));
          v155 = v148;
          v123 = _mm_load_si128(&v265);
          v156 = _mm_and_ps((__m128)v254, v141);
          v157 = _mm_andnot_ps(v141, (__m128)v253);
          *(__m128 *)&mZBuffer[4 * v109 + 32] = _mm_or_ps(_mm_andnot_ps(v155, (__m128)v139), v152);
          *(__m128 *)&mZBuffer[4 * v109] = _mm_or_ps(v156, v157);
          v158 = v145;
          v124 = _mm_load_si128(&v263);
          *(__m128 *)&mZBuffer[4 * v109 + 16] = _mm_or_ps(_mm_andnot_ps(v158, (__m128)v133), v151);
          *(__m128 *)&mZBuffer[4 * v109 + 48] = _mm_or_ps(
                                                  _mm_andnot_ps(v154, (__m128)v140),
                                                  _mm_and_ps((__m128)v150, v154));
        }
        if ( !v116 )
        {
          v159 = _mm_load_si128((const __m128i *)&v249);
          v160 = _mm_load_si128(&v245);
          v161 = _mm_load_si128((const __m128i *)&v246);
          v162 = v123;
          v163 = v124;
          v164 = _mm_load_si128((const __m128i *)&v247);
          v165 = _mm_sub_epi32(v162, v159);
          v166 = _mm_sub_epi32(v163, v161);
          v167 = _mm_sub_epi32(v166, v161);
          v168 = _mm_sub_epi32(v115, v164);
          v169 = _mm_sub_epi32(v122, v160);
          v170 = _mm_sub_epi32(v165, v159);
          v171 = _mm_sub_epi32(v167, v161);
          v172 = _mm_sub_epi32(v168, v164);
          v173 = _mm_sub_epi32(v169, v160);
          v174 = _mm_sub_epi32(v172, v164);
          v175 = _mm_sub_epi32(v173, v160);
          v176 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v251),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v261)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v263),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v265))),
                   (__m128)_mm_cmpgt_epi32(_mm_load_si128(&v251), *(__m128i *)&mZBuffer[4 * v109 + 64]));
          v177 = _mm_or_ps(
                   _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v169), (__m128)_mm_cmpgt_epi32((__m128i)0i64, v168)),
                   _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v166), (__m128)_mm_cmpgt_epi32((__m128i)0i64, v165)));
          v178 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v167);
          v103 = 0i64;
          v179 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v173),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v172)),
                     _mm_or_ps(v178, (__m128)_mm_cmpgt_epi32((__m128i)0i64, v170))),
                   (__m128)_mm_cmpgt_epi32(v173, *(__m128i *)&mZBuffer[4 * v109 + 96]));
          v180 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v175),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v174)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v171),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, _mm_sub_epi32(v170, v159)))),
                   (__m128)_mm_cmpgt_epi32(v175, *(__m128i *)&mZBuffer[4 * v109 + 112]));
          v181 = _mm_or_ps(v177, (__m128)_mm_cmpgt_epi32(v169, *(__m128i *)&mZBuffer[4 * v109 + 80]));
          v182 = _mm_or_ps(_mm_andnot_ps(v181, (__m128)v169), _mm_and_ps(v181, *(__m128 *)&mZBuffer[4 * v109 + 80]));
          *(__m128 *)&mZBuffer[4 * v109 + 64] = _mm_or_ps(
                                                  _mm_and_ps(v176, *(__m128 *)&mZBuffer[4 * v109 + 64]),
                                                  _mm_andnot_ps(v176, (__m128)v251));
          *(__m128 *)&mZBuffer[4 * v109 + 80] = v182;
          v183 = v180;
          v184 = _mm_and_ps(v180, *(__m128 *)&mZBuffer[4 * v109 + 112]);
          *(__m128 *)&mZBuffer[4 * v109 + 96] = _mm_or_ps(
                                                  _mm_andnot_ps(v179, (__m128)v173),
                                                  _mm_and_ps(v179, *(__m128 *)&mZBuffer[4 * v109 + 96]));
          *(__m128 *)&mZBuffer[4 * v109 + 112] = _mm_or_ps(_mm_andnot_ps(v183, (__m128)v175), v184);
        }
        if ( !v118 )
        {
          v185 = _mm_load_si128((const __m128i *)&v247);
          v186 = _mm_load_si128((const __m128i *)&v249);
          v187 = _mm_load_si128(&v245);
          v188 = _mm_load_si128((const __m128i *)&v246);
          v189 = _mm_sub_epi32(_mm_load_si128(&v264), v186);
          v190 = _mm_sub_epi32(_mm_load_si128(&v267), v185);
          v191 = _mm_sub_epi32(_mm_load_si128(&v260), v188);
          v192 = _mm_sub_epi32(_mm_load_si128(&v250), v187);
          v193 = _mm_sub_epi32(v190, v185);
          v194 = _mm_sub_epi32(v189, v186);
          v195 = _mm_sub_epi32(v191, v188);
          v196 = _mm_sub_epi32(v193, v185);
          v197 = _mm_sub_epi32(v194, v186);
          v198 = _mm_sub_epi32(v195, v188);
          v199 = _mm_sub_epi32(v192, v187);
          v200 = _mm_sub_epi32(v199, v187);
          v201 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v250),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v267)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v260),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v264))),
                   (__m128)_mm_cmpgt_epi32(_mm_load_si128(&v250), *(__m128i *)&mZBuffer[4 * v109 + 2048]));
          v202 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v189);
          v203 = *(__m128i *)&mZBuffer[4 * v109 + 2064];
          v204 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v195);
          v103 = 0i64;
          v205 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v192),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v190)),
                     _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v191), v202)),
                   (__m128)_mm_cmpgt_epi32(v192, v203));
          v206 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v193);
          v207 = *(__m128i *)&mZBuffer[4 * v109 + 2080];
          v208 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v199), v206),
                     _mm_or_ps(v204, (__m128)_mm_cmpgt_epi32((__m128i)0i64, v194))),
                   (__m128)_mm_cmpgt_epi32(v199, v207));
          v209 = _mm_or_ps((__m128)_mm_cmpgt_epi32((__m128i)0i64, v200), (__m128)_mm_cmpgt_epi32((__m128i)0i64, v196));
          v210 = *(__m128i *)&mZBuffer[4 * v109 + 2096];
          v211 = _mm_or_ps(
                   _mm_or_ps(
                     v209,
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v198),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v197))),
                   (__m128)_mm_cmpgt_epi32(v200, v210));
          v212 = _mm_and_ps(v201, *(__m128 *)&mZBuffer[4 * v109 + 2048]);
          v213 = _mm_andnot_ps(v201, (__m128)v250);
          *(__m128 *)&mZBuffer[4 * v109 + 2064] = _mm_or_ps(
                                                    _mm_andnot_ps(v205, (__m128)v192),
                                                    _mm_and_ps(v205, (__m128)v203));
          *(__m128 *)&mZBuffer[4 * v109 + 2048] = _mm_or_ps(v212, v213);
          *(__m128 *)&mZBuffer[4 * v109 + 2096] = _mm_or_ps(
                                                    _mm_andnot_ps(v211, (__m128)v200),
                                                    _mm_and_ps(v211, (__m128)v210));
          *(__m128 *)&mZBuffer[4 * v109 + 2080] = _mm_or_ps(
                                                    _mm_andnot_ps(v208, (__m128)v199),
                                                    _mm_and_ps(v208, (__m128)v207));
        }
        if ( !v121 )
        {
          v214 = _mm_load_si128((const __m128i *)&v247);
          v215 = *(__m128i *)&mZBuffer[4 * v109 + 2144];
          v216 = *(__m128i *)&mZBuffer[4 * v109 + 2112];
          v217 = _mm_load_si128(&v266);
          v218 = _mm_load_si128(&v252);
          v219 = _mm_load_si128(&v262);
          v220 = _mm_load_si128(&v248);
          v254 = *(__m128i *)&mZBuffer[4 * v109 + 2128];
          v221 = _mm_sub_epi32(v220, v245);
          v222 = _mm_sub_epi32(v219, v214);
          v223 = *(__m128i *)&mZBuffer[4 * v109 + 2160];
          v256 = v215;
          v224 = _mm_load_si128((const __m128i *)&v246);
          v225 = _mm_sub_epi32(v217, v224);
          v257 = v223;
          v226 = _mm_load_si128((const __m128i *)&v249);
          v227 = _mm_sub_epi32(v218, v226);
          v228 = _mm_sub_epi32(v225, v224);
          v255 = v216;
          v229 = _mm_sub_epi32(v227, v226);
          v230 = _mm_sub_epi32(v222, v214);
          v231 = _mm_sub_epi32(v228, v224);
          v232 = _mm_sub_epi32(v230, v214);
          v233 = _mm_sub_epi32(v221, v245);
          v234 = _mm_sub_epi32(v233, v245);
          v235 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v248),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v262)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v266),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v252))),
                   (__m128)_mm_cmpgt_epi32(_mm_load_si128(&v248), v216));
          v236 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v228);
          v103 = 0i64;
          v237 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v221),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v222)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v225),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v227))),
                   (__m128)_mm_cmpgt_epi32(v221, v254));
          v238 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v233),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v230)),
                     _mm_or_ps(v236, (__m128)_mm_cmpgt_epi32((__m128i)0i64, v229))),
                   (__m128)_mm_cmpgt_epi32(v233, v256));
          v239 = _mm_and_ps((__m128)v256, v238);
          *(__m128 *)&mZBuffer[4 * v109 + 2128] = _mm_or_ps(
                                                    _mm_and_ps((__m128)v254, v237),
                                                    _mm_andnot_ps(v237, (__m128)v221));
          *(__m128 *)&mZBuffer[4 * v109 + 2144] = _mm_or_ps(v239, _mm_andnot_ps(v238, (__m128)v233));
          v240 = _mm_or_ps(
                   _mm_or_ps(
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v234),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v232)),
                     _mm_or_ps(
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, v231),
                       (__m128)_mm_cmpgt_epi32((__m128i)0i64, _mm_sub_epi32(v229, v226)))),
                   (__m128)_mm_cmpgt_epi32(v234, v257));
          v241 = _mm_and_ps((__m128)v255, v235);
          v242 = _mm_andnot_ps(v235, (__m128)v248);
          *(__m128 *)&mZBuffer[4 * v109 + 2160] = _mm_or_ps(
                                                    _mm_and_ps((__m128)v257, v240),
                                                    _mm_andnot_ps(v240, (__m128)v234));
          *(__m128 *)&mZBuffer[4 * v109 + 2112] = _mm_or_ps(v241, v242);
        }
        v101 = v107 + 1;
      }
      while ( v102 );
    }
  }
}   }
        v101 = v107 + 1;
      }
      while ( v102 );
    }
  }
}

