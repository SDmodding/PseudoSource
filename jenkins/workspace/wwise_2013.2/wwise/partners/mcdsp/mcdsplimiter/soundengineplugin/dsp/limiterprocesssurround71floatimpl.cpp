// File Line: 235
// RVA: 0xB00510
void __fastcall McDSPLimiterProcessChannels(void *memoryMap, const float *inputBuf_L, const float *inputBuf_C, const float *inputBuf_R, const float *inputBuf_Ls, const float *inputBuf_Rs, const float *inputBuf_LFE, const float *inputBuf_Lsb, const float *inputBuf_Rsb, float *outputBuf_L, float *outputBuf_C, float *outputBuf_R, float *outputBuf_Ls, float *outputBuf_Rs, float *outputBuf_LFE, float *outputBuf_Lsb, float *outputBuf_Rsb, unsigned int samplesRemaining)
{
  int v18; // er13
  char *v19; // r15
  float *v20; // rbx
  const float *v21; // rsi
  signed int v22; // er9
  signed int v23; // er12
  signed int v24; // ecx
  int v25; // edi
  signed __int64 v26; // r14
  signed int v27; // eax
  unsigned int v28; // ecx
  float v29; // xmm9_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  _DWORD *v32; // r11
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  int v39; // edx
  signed __int64 v40; // r8
  float v41; // xmm4_4
  signed __int64 v42; // rax
  __int64 v43; // r14
  int v44; // xmm2_4
  int v45; // xmm1_4
  int v46; // ecx
  __int64 v47; // rax
  int v48; // edx
  int v49; // xmm2_4
  int v50; // xmm1_4
  __int64 v51; // rax
  int v52; // xmm2_4
  int v53; // xmm1_4
  __int64 v54; // rcx
  int v55; // xmm1_4
  int v56; // xmm0_4
  int v57; // xmm4_4
  int v58; // xmm2_4
  int v59; // xmm2_4
  int v60; // er9
  char *v61; // rcx
  unsigned int v62; // eax
  __int64 v63; // r8
  __int64 v64; // r8
  float v65; // xmm4_4
  float v66; // xmm6_4
  float v67; // xmm5_4
  float v68; // xmm5_4
  float v69; // xmm5_4
  float v70; // xmm0_4
  float v71; // xmm5_4
  float v72; // xmm2_4
  float v73; // xmm4_4
  int v74; // xmm0_4
  int v75; // xmm5_4
  float v76; // xmm1_4
  int v77; // xmm4_4
  int v78; // xmm0_4
  float v79; // xmm5_4
  float v80; // xmm0_4
  float v81; // xmm2_4
  float v82; // xmm0_4
  signed __int64 v83; // rcx
  signed __int64 v84; // r8
  int v85; // er9
  float v86; // xmm4_4
  signed __int64 v87; // rax
  float v88; // xmm5_4
  float v89; // xmm0_4
  signed __int64 v90; // rax
  signed __int64 v91; // rcx
  unsigned int v92; // eax
  __int64 v93; // r8
  signed __int64 v94; // rcx
  __int64 v95; // r8
  float v96; // xmm2_4
  float v97; // xmm4_4
  float v98; // xmm5_4
  int v99; // xmm4_4
  float v100; // xmm2_4
  float v101; // xmm4_4
  float v102; // xmm2_4
  int v103; // xmm4_4
  float v104; // xmm2_4
  float v105; // xmm4_4
  float v106; // xmm2_4
  int v107; // xmm4_4
  float v108; // xmm2_4
  float v109; // xmm4_4
  float v110; // xmm2_4
  int v111; // xmm4_4
  float v112; // xmm2_4
  float v113; // xmm4_4
  float v114; // xmm2_4
  int v115; // xmm4_4
  float v116; // xmm2_4
  float v117; // xmm4_4
  float v118; // xmm2_4
  int v119; // xmm4_4
  float v120; // xmm2_4
  float v121; // xmm4_4
  float v122; // xmm2_4
  int v123; // xmm4_4
  float v124; // xmm2_4
  float v125; // xmm4_4
  float v126; // xmm2_4
  int v127; // xmm4_4
  float v128; // xmm2_4
  float v129; // xmm4_4
  float v130; // xmm2_4
  int v131; // [rsp+0h] [rbp-F8h]
  signed int v132; // [rsp+4h] [rbp-F4h]
  signed int v133; // [rsp+8h] [rbp-F0h]
  signed int v134; // [rsp+Ch] [rbp-ECh]
  signed int v135; // [rsp+10h] [rbp-E8h]
  signed __int64 v136; // [rsp+18h] [rbp-E0h]
  __int64 v137; // [rsp+28h] [rbp-D0h]
  __int64 v138; // [rsp+30h] [rbp-C8h]
  signed __int64 v139; // [rsp+38h] [rbp-C0h]
  __int64 v140; // [rsp+40h] [rbp-B8h]
  signed __int64 v141; // [rsp+48h] [rbp-B0h]
  int v142; // [rsp+100h] [rbp+8h]
  const float *v143; // [rsp+108h] [rbp+10h]
  const float *v144; // [rsp+110h] [rbp+18h]
  unsigned int samplesRemaininga; // [rsp+188h] [rbp+90h]

  v18 = (signed int)*((float *)memoryMap + 8);
  v19 = (char *)memoryMap;
  v20 = (float *)((char *)memoryMap + 32);
  v21 = inputBuf_R;
  v22 = (signed int)*((float *)memoryMap + 1435);
  v23 = (signed int)*((float *)memoryMap + 1445);
  v24 = (signed int)*((float *)memoryMap + 9);
  *(_QWORD *)(v19 + 84) = 0i64;
  *(_QWORD *)(v19 + 116) = 0i64;
  *(_QWORD *)(v19 + 100) = 0i64;
  v134 = v24;
  *(_QWORD *)(v19 + 132) = 0i64;
  v140 = v24;
  *(_QWORD *)(v19 + 148) = 0i64;
  *(_QWORD *)(v19 + 164) = 0i64;
  *(_QWORD *)(v19 + 180) = 0i64;
  *(_QWORD *)(v19 + 196) = 0i64;
  *((_DWORD *)v19 + 53) = 0;
  v25 = (signed int)*((float *)v19 + 20);
  v133 = (signed int)*((float *)v19 + 13);
  v26 = v22;
  v138 = (signed int)*((float *)v19 + 10);
  v132 = (signed int)*((float *)v19 + 10);
  v142 = v25;
  v27 = (signed int)*((float *)v19 + 18);
  v135 = (signed int)*((float *)v19 + 19);
  v137 = v27;
  v136 = v25;
  v28 = samplesRemaining;
  if ( samplesRemaining )
  {
    v139 = v27 + 1;
    v29 = kHeadRoomScaleFactor_2;
    do
    {
      samplesRemaininga = v28 - 1;
      v143 = inputBuf_L + 1;
      v144 = inputBuf_C + 1;
      v30 = v29 * *inputBuf_L;
      v31 = v29 * *inputBuf_C;
      if ( v30 < 1.0 )
      {
        if ( v30 <= -1.0 )
          v30 = FLOAT_N1_0;
      }
      else
      {
        v30 = *(float *)&FLOAT_1_0;
      }
      if ( v31 < 1.0 )
      {
        if ( v31 <= -1.0 )
          v31 = FLOAT_N1_0;
      }
      else
      {
        v31 = *(float *)&FLOAT_1_0;
      }
      *((float *)v19 + 1427) = v30;
      v32 = v19 + 5712;
      ++v21;
      ++inputBuf_Ls;
      *((float *)v19 + 1428) = v31;
      v33 = v29 * *(v21 - 1);
      v34 = v29 * *(inputBuf_Ls - 1);
      if ( v33 < 1.0 )
      {
        if ( v33 <= -1.0 )
          v33 = FLOAT_N1_0;
      }
      else
      {
        v33 = *(float *)&FLOAT_1_0;
      }
      if ( v34 < 1.0 )
      {
        if ( v34 <= -1.0 )
          v34 = FLOAT_N1_0;
      }
      else
      {
        v34 = *(float *)&FLOAT_1_0;
      }
      *((float *)v19 + 1429) = v33;
      *((float *)v19 + 1430) = v34;
      ++inputBuf_Rs;
      v35 = v29 * *(inputBuf_Rs - 1);
      ++inputBuf_LFE;
      v36 = v29 * *(inputBuf_LFE - 1);
      if ( v35 < 1.0 )
      {
        if ( v35 <= -1.0 )
          v35 = FLOAT_N1_0;
      }
      else
      {
        v35 = *(float *)&FLOAT_1_0;
      }
      if ( v36 < 1.0 )
      {
        if ( v36 <= -1.0 )
          v36 = FLOAT_N1_0;
      }
      else
      {
        v36 = *(float *)&FLOAT_1_0;
      }
      *((float *)v19 + 1431) = v35;
      *((float *)v19 + 1432) = v36;
      ++inputBuf_Lsb;
      v37 = v29 * *(inputBuf_Lsb - 1);
      ++inputBuf_Rsb;
      v38 = v29 * *(inputBuf_Rsb - 1);
      if ( v37 < 1.0 )
      {
        if ( v37 <= -1.0 )
          v37 = FLOAT_N1_0;
      }
      else
      {
        v37 = *(float *)&FLOAT_1_0;
      }
      if ( v38 < 1.0 )
      {
        if ( v38 <= -1.0 )
          v38 = FLOAT_N1_0;
      }
      else
      {
        v38 = *(float *)&FLOAT_1_0;
      }
      *((float *)v19 + 1433) = v37;
      v39 = v22 + 1;
      *((float *)v19 + 1434) = v38;
      v40 = v26 + 1;
      v41 = *v20;
      if ( v22 + 1 >= v18 )
      {
        v39 = 0;
        v40 = 0i64;
      }
      v42 = v26 + v140;
      v43 = v138 + v26;
      v44 = *(_DWORD *)&v19[4 * v42];
      *(_DWORD *)&v19[4 * v42] = *((_DWORD *)v19 + 1427);
      v45 = *(_DWORD *)&v19[4 * v42 + 5708];
      v131 = v39;
      v141 = v40;
      v46 = (signed int)v41 + v22 + v134 + 1;
      *(_DWORD *)&v19[4 * v42 + 5708] = *v32;
      *((_DWORD *)v19 + 1436) = v44;
      *((_DWORD *)v19 + 1437) = v45;
      v47 = v46;
      v48 = (signed int)v41 + v46 + 1;
      v49 = *(_DWORD *)&v19[4 * v46];
      *(_DWORD *)&v19[4 * v47] = *((_DWORD *)v19 + 1429);
      v50 = *(_DWORD *)&v19[4 * v46 + 5708];
      *(_DWORD *)&v19[4 * v47 + 5708] = *((_DWORD *)v19 + 1430);
      *((_DWORD *)v19 + 1438) = v49;
      *((_DWORD *)v19 + 1439) = v50;
      v51 = v48;
      v52 = *(_DWORD *)&v19[4 * v48];
      *(_DWORD *)&v19[4 * v51] = *((_DWORD *)v19 + 1431);
      v53 = *(_DWORD *)&v19[4 * v48 + 5708];
      *(_DWORD *)&v19[4 * v51 + 5708] = *((_DWORD *)v19 + 1432);
      *((_DWORD *)v19 + 1440) = v52;
      *((_DWORD *)v19 + 1441) = v53;
      v54 = v48 + (signed int)v41 + 1;
      v55 = *(_DWORD *)&v19[4 * v54];
      *(_DWORD *)&v19[4 * v54] = *((_DWORD *)v19 + 1433);
      v56 = *(_DWORD *)&v19[4 * v54 + 5708];
      *(_DWORD *)&v19[4 * v54 + 5708] = *((_DWORD *)v19 + 1434);
      *((_DWORD *)v19 + 1442) = v55;
      *((_DWORD *)v19 + 1443) = v56;
      v57 = *v32;
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1427) & _xmm) > COERCE_FLOAT(*v32 & _xmm) )
        v57 = *((_DWORD *)v19 + 1427);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1429) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)v19 + 1429);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1430) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)v19 + 1430);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1431) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)v19 + 1431);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1432) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)v19 + 1432);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1433) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)v19 + 1433);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1434) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)v19 + 1434);
      v58 = *((_DWORD *)v19 + 1437);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1436) & _xmm) > COERCE_FLOAT(*((_DWORD *)v19 + 1437) & _xmm) )
        v58 = *((_DWORD *)v19 + 1436);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1438) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)v19 + 1438);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1439) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)v19 + 1439);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1440) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)v19 + 1440);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1441) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)v19 + 1441);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1442) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)v19 + 1442);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1443) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)v19 + 1443);
      *((_DWORD *)v19 + 1444) = v58;
      *(_DWORD *)&v19[4 * v43 + 5708] = v57;
      v59 = 0;
      v60 = 0;
      v61 = &v19[4 * (v132 + 1427i64)];
      if ( v18 >= 4 )
      {
        v62 = ((unsigned int)(v18 - 4) >> 2) + 1;
        v63 = v62;
        v60 = 4 * v62;
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v61 & _xmm) > COERCE_FLOAT(v59 & _xmm) )
            v59 = *(_DWORD *)v61;
          if ( COERCE_FLOAT(*((_DWORD *)v61 + 1) & _xmm) > COERCE_FLOAT(v59 & _xmm) )
            v59 = *((_DWORD *)v61 + 1);
          if ( COERCE_FLOAT(*((_DWORD *)v61 + 2) & _xmm) > COERCE_FLOAT(v59 & _xmm) )
            v59 = *((_DWORD *)v61 + 2);
          if ( COERCE_FLOAT(*((_DWORD *)v61 + 3) & _xmm) > COERCE_FLOAT(v59 & _xmm) )
            v59 = *((_DWORD *)v61 + 3);
          v61 += 16;
          --v63;
        }
        while ( v63 );
      }
      if ( v60 < v18 )
      {
        v64 = (unsigned int)(v18 - v60);
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v61 & _xmm) > COERCE_FLOAT(v59 & _xmm) )
            v59 = *(_DWORD *)v61;
          v61 += 4;
          --v64;
        }
        while ( v64 );
      }
      LODWORD(v65) = *((_DWORD *)v19 + 1427) & _xmm;
      v66 = v20[4];
      if ( COERCE_FLOAT(*v32 & _xmm) > v65 )
        LODWORD(v65) = *v32 & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1429) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)v19 + 1429) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1430) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)v19 + 1430) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1431) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)v19 + 1431) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1432) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)v19 + 1432) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1433) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)v19 + 1433) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1434) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)v19 + 1434) & _xmm;
      if ( v65 >= 1.0 )
        v65 = *(float *)&FLOAT_1_0;
      if ( COERCE_FLOAT((_DWORD)v20[3] & _xmm) <= COERCE_FLOAT(LODWORD(v65) & _xmm) )
        v65 = v20[3];
      v67 = *((float *)v19 + 1446);
      if ( COERCE_FLOAT(LODWORD(v65) & _xmm) > COERCE_FLOAT(*((_DWORD *)v19 + 1446) & _xmm) )
      {
        v23 = v133;
        v67 = v65;
      }
      LODWORD(v68) = LODWORD(v67) & _xmm;
      *((float *)v19 + 1446) = v68;
      v69 = v68 - v66;
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1447) & _xmm) > COERCE_FLOAT(LODWORD(v69) & _xmm) )
        v69 = *((float *)v19 + 1447);
      *((float *)v19 + 1447) = v69;
      v70 = v20[7];
      --v23;
      v71 = 0.0;
      if ( v23 < 0 )
        v23 = 0;
      if ( v23 <= 0 )
      {
        v71 = v20[6];
        v70 = 0.0;
      }
      LODWORD(v72) = v59 & _xmm;
      v73 = (float)((float)(*((float *)v19 + 1447) * v70) + v20[4]) + (float)((float)(v72 - v20[4]) * v71);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1446) & _xmm) <= COERCE_FLOAT(LODWORD(v73) & _xmm) )
        v73 = *((float *)v19 + 1446);
      v74 = *((_DWORD *)v19 + 1447);
      if ( v23 <= 0 )
        v74 = 0;
      *((_DWORD *)v19 + 1447) = v74;
      v75 = *((_DWORD *)v19 + 1444);
      LODWORD(v76) = *((_DWORD *)v19 + 1444) & _xmm;
      if ( v76 > COERCE_FLOAT(LODWORD(v73) & _xmm) )
        v73 = *((float *)v19 + 1444);
      v77 = LODWORD(v73) & _xmm;
      *((_DWORD *)v20 + 4) = v77;
      v78 = *((_DWORD *)v19 + 1446);
      if ( v76 > COERCE_FLOAT(v77 & _xmm) )
        v78 = v75;
      *((_DWORD *)v19 + 1446) = v78 & _xmm;
      v79 = v20[8];
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1448) & _xmm) < COERCE_FLOAT(LODWORD(v72) & _xmm) )
        v79 = v20[9];
      v80 = v20[4];
      v81 = (float)((float)(v72 - *((float *)v19 + 1448)) * v79) + *((float *)v19 + 1448);
      *((float *)v19 + 1448) = v81;
      if ( v80 > v81 )
        v81 = v80;
      v20[4] = v81;
      v82 = *((float *)v19 + 1446);
      if ( v23 <= 0 )
        v82 = v81;
      *((float *)v19 + 1446) = v82;
      v25 = v142 + 1;
      v83 = v136 + 1;
      v84 = v136;
      ++v142;
      if ( v136 + 1 >= v135 )
      {
        v25 = 0;
        v142 = 0;
        v83 = 0i64;
      }
      v85 = 0;
      v86 = 0.0;
      v87 = v137 + v136;
      v136 = v83;
      *(float *)&v19[4 * v87 + 5708] = v81;
      v88 = *(float *)&v19[4 * v137];
      v89 = *(float *)&v19[4 * (v87 - v84) + 5708];
      v90 = v139;
      if ( v135 >= 4 )
      {
        v91 = (signed __int64)&v19[4 * (v139 + 1429)];
        v92 = ((unsigned int)(v135 - 4) >> 2) + 1;
        v93 = v92;
        v85 = 4 * v92;
        v90 = v139 + 4i64 * v92;
        do
        {
          v91 += 16i64;
          v86 = (float)((float)((float)(v86 + (float)(v89 * v88)) + (float)(v88 * *(float *)(v91 - 24)))
                      + (float)(v88 * *(float *)(v91 - 20)))
              + (float)(v88 * *(float *)(v91 - 16));
          v89 = *(float *)(v91 - 12);
          --v93;
        }
        while ( v93 );
      }
      if ( v85 < v135 )
      {
        v94 = (signed __int64)&v19[4 * v90 + 5708];
        v95 = (unsigned int)(v135 - v85);
        do
        {
          v94 += 4i64;
          v86 = v86 + (float)(v89 * v88);
          v89 = *(float *)(v94 - 4);
          --v95;
        }
        while ( v95 );
      }
      v96 = (float)((float)((float)((float)(v86 * 2.0) - (float)(v86 * v86)) * 2.0)
                  - (float)((float)((float)(v86 * 2.0) - (float)(v86 * v86))
                          * (float)((float)(v86 * 2.0) - (float)(v86 * v86))))
          * 599.0;
      v97 = (float)((float)(*(float *)&v32[(signed int)v96 + 23] - *(float *)&v32[(signed int)v96 + 22])
                  * (float)(v96 - (float)(signed int)v96))
          + *(float *)&v32[(signed int)v96 + 22];
      v98 = (float)((float)(*(float *)&v32[(signed int)v96 + 23] - *(float *)&v32[(signed int)v96 + 22])
                  * (float)(v96 - (float)(signed int)v96))
          + *(float *)&v32[(signed int)v96 + 22];
      if ( COERCE_FLOAT((_DWORD)v20[13] & _xmm) > COERCE_FLOAT(LODWORD(v97) & _xmm) )
        v97 = v20[13];
      v20[13] = v97;
      v99 = *((_DWORD *)v20 + 14);
      v100 = *((float *)v19 + 1436);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1436) & _xmm) > COERCE_FLOAT((_DWORD)v20[14] & _xmm) )
        v99 = *((_DWORD *)v19 + 1436);
      *((_DWORD *)v20 + 14) = v99;
      v101 = v20[17];
      v102 = (float)(v100 * v98) * v20[15];
      if ( COERCE_FLOAT(LODWORD(v102) & _xmm) > COERCE_FLOAT((_DWORD)v20[17] & _xmm) )
        v101 = v102;
      v20[17] = v101;
      ++outputBuf_L;
      *(outputBuf_L - 1) = v102;
      v103 = *((_DWORD *)v20 + 18);
      v104 = *((float *)v19 + 1437);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1437) & _xmm) > COERCE_FLOAT((_DWORD)v20[18] & _xmm) )
        v103 = *((_DWORD *)v19 + 1437);
      *((_DWORD *)v20 + 18) = v103;
      v105 = v20[21];
      v106 = (float)(v104 * v98) * v20[19];
      if ( COERCE_FLOAT(LODWORD(v106) & _xmm) > COERCE_FLOAT((_DWORD)v20[21] & _xmm) )
        v105 = v106;
      v20[21] = v105;
      ++outputBuf_C;
      *(outputBuf_C - 1) = v106;
      v107 = *((_DWORD *)v20 + 22);
      v108 = *((float *)v19 + 1438);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1438) & _xmm) > COERCE_FLOAT((_DWORD)v20[22] & _xmm) )
        v107 = *((_DWORD *)v19 + 1438);
      *((_DWORD *)v20 + 22) = v107;
      v109 = v20[25];
      v110 = (float)(v108 * v98) * v20[23];
      if ( COERCE_FLOAT(LODWORD(v110) & _xmm) > COERCE_FLOAT((_DWORD)v20[25] & _xmm) )
        v109 = v110;
      v20[25] = v109;
      ++outputBuf_R;
      *(outputBuf_R - 1) = v110;
      v111 = *((_DWORD *)v20 + 26);
      v112 = *((float *)v19 + 1439);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1439) & _xmm) > COERCE_FLOAT((_DWORD)v20[26] & _xmm) )
        v111 = *((_DWORD *)v19 + 1439);
      *((_DWORD *)v20 + 26) = v111;
      v113 = v20[29];
      v114 = (float)(v112 * v98) * v20[27];
      if ( COERCE_FLOAT(LODWORD(v114) & _xmm) > COERCE_FLOAT((_DWORD)v20[29] & _xmm) )
        v113 = v114;
      v20[29] = v113;
      ++outputBuf_Ls;
      *(outputBuf_Ls - 1) = v114;
      v115 = *((_DWORD *)v20 + 30);
      v116 = *((float *)v19 + 1440);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1440) & _xmm) > COERCE_FLOAT((_DWORD)v20[30] & _xmm) )
        v115 = *((_DWORD *)v19 + 1440);
      *((_DWORD *)v20 + 30) = v115;
      v117 = v20[33];
      v118 = (float)(v116 * v98) * v20[31];
      if ( COERCE_FLOAT(LODWORD(v118) & _xmm) > COERCE_FLOAT((_DWORD)v20[33] & _xmm) )
        v117 = v118;
      v20[33] = v117;
      ++outputBuf_Rs;
      *(outputBuf_Rs - 1) = v118;
      v119 = *((_DWORD *)v20 + 34);
      v120 = *((float *)v19 + 1441);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1441) & _xmm) > COERCE_FLOAT((_DWORD)v20[34] & _xmm) )
        v119 = *((_DWORD *)v19 + 1441);
      *((_DWORD *)v20 + 34) = v119;
      v121 = v20[37];
      v122 = (float)(v120 * v98) * v20[35];
      if ( COERCE_FLOAT(LODWORD(v122) & _xmm) > COERCE_FLOAT((_DWORD)v20[37] & _xmm) )
        v121 = v122;
      v20[37] = v121;
      ++outputBuf_LFE;
      *(outputBuf_LFE - 1) = v122;
      v123 = *((_DWORD *)v20 + 38);
      v124 = *((float *)v19 + 1442);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1442) & _xmm) > COERCE_FLOAT((_DWORD)v20[38] & _xmm) )
        v123 = *((_DWORD *)v19 + 1442);
      *((_DWORD *)v20 + 38) = v123;
      v125 = v20[41];
      v126 = (float)(v124 * v98) * v20[39];
      if ( COERCE_FLOAT(LODWORD(v126) & _xmm) > COERCE_FLOAT((_DWORD)v20[41] & _xmm) )
        v125 = v126;
      v20[41] = v125;
      ++outputBuf_Lsb;
      *(outputBuf_Lsb - 1) = v126;
      v127 = *((_DWORD *)v20 + 42);
      v128 = *((float *)v19 + 1443);
      if ( COERCE_FLOAT(*((_DWORD *)v19 + 1443) & _xmm) > COERCE_FLOAT((_DWORD)v20[42] & _xmm) )
        v127 = *((_DWORD *)v19 + 1443);
      *((_DWORD *)v20 + 42) = v127;
      v129 = v20[45];
      v130 = (float)(v128 * v98) * v20[43];
      if ( COERCE_FLOAT(LODWORD(v130) & _xmm) > COERCE_FLOAT((_DWORD)v20[45] & _xmm) )
        v129 = v130;
      v28 = samplesRemaininga;
      inputBuf_C = v144;
      v20[45] = v129;
      inputBuf_L = v143;
      v22 = v131;
      v26 = v141;
      *outputBuf_Rsb = v130;
      v20 = (float *)(v19 + 32);
      ++outputBuf_Rsb;
    }
    while ( samplesRemaininga );
  }
  *((float *)v19 + 1445) = (float)v23;
  *((float *)v19 + 1435) = (float)v22;
  *((float *)v19 + 20) = (float)v25;
}

// File Line: 1160
// RVA: 0xB017F0
void __fastcall McDSPFillVUMetersDataSurround71(void *memoryMap, char *pMeteringData)
{
  *(_DWORD *)pMeteringData = 1599;
  *((_DWORD *)pMeteringData + 1) = *((_DWORD *)memoryMap + 21);
  *((float *)pMeteringData + 2) = *((float *)memoryMap + 22) * 3.9810717;
  *((float *)pMeteringData + 3) = *((float *)memoryMap + 30) * 3.9810717;
  *((float *)pMeteringData + 4) = *((float *)memoryMap + 26) * 3.9810717;
  *((float *)pMeteringData + 5) = *((float *)memoryMap + 34) * 3.9810717;
  *((float *)pMeteringData + 6) = *((float *)memoryMap + 38) * 3.9810717;
  *((float *)pMeteringData + 7) = *((float *)memoryMap + 42) * 3.9810717;
  *((float *)pMeteringData + 8) = *((float *)memoryMap + 46) * 3.9810717;
  *((float *)pMeteringData + 9) = *((float *)memoryMap + 50) * 3.9810717;
  *((_DWORD *)pMeteringData + 10) = *((_DWORD *)memoryMap + 25);
  *((_DWORD *)pMeteringData + 11) = *((_DWORD *)memoryMap + 33);
  *((_DWORD *)pMeteringData + 12) = *((_DWORD *)memoryMap + 29);
  *((_DWORD *)pMeteringData + 13) = *((_DWORD *)memoryMap + 37);
  *((_DWORD *)pMeteringData + 14) = *((_DWORD *)memoryMap + 41);
  *((_DWORD *)pMeteringData + 15) = *((_DWORD *)memoryMap + 45);
  *((_DWORD *)pMeteringData + 16) = *((_DWORD *)memoryMap + 49);
  *((_DWORD *)pMeteringData + 17) = *((_DWORD *)memoryMap + 53);
}

// File Line: 1244
// RVA: 0xB018D0
void __fastcall LimiterDSPSurround71MemoryMapHelper::LimiterDSPSurround71MemoryMapHelper(LimiterDSPSurround71MemoryMapHelper *this, int sampleRate)
{
  LimiterDSPSurround71MemoryMapHelper *v2; // rbx

  v2 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  LimiterUtilities::LimiterUtilities(&v2->mLimiterUtilities, 0.00085000001, 0.000325);
}

// File Line: 1250
// RVA: 0xB01910
void __fastcall LimiterDSPSurround71MemoryMapHelper::~LimiterDSPSurround71MemoryMapHelper(LimiterDSPSurround71MemoryMapHelper *this)
{
  LimiterDSPSurround71MemoryMapHelper *v1; // rbx

  v1 = this;
  LimiterUtilities::~LimiterUtilities(&this->mLimiterUtilities);
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&v1->0);
}

// File Line: 1255
// RVA: 0xB01940
unsigned __int64 __fastcall LimiterDSPSurround71MemoryMapHelper::GetMemoryMapSize(LimiterDSPSurround71MemoryMapHelper *this)
{
  return 11416i64;
}

// File Line: 1263
// RVA: 0xB01950
signed __int64 __fastcall LimiterDSPSurround71MemoryMapHelper::Init(LimiterDSPSurround71MemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int sampleRate)
{
  LimiterDSPSurround71MemoryMapHelper *v3; // rbx
  char *v4; // rax

  v3 = this;
  this->mNumChannels = 8;
  this->mSampleRate = sampleRate;
  v4 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x2C98ui64);
  v3->LimiterMemMapPtr = (LimiterSurround71MemoryMap *)v4;
  if ( !v4 )
    return 52i64;
  *((_DWORD *)v4 + 11) = 1065353216;
  v3->LimiterMemMapPtr->XMemory[10] = 1227.0;
  return 1i64;
}

// File Line: 1287
// RVA: 0xB019B0
LimiterSurround71MemoryMap *__fastcall LimiterDSPSurround71MemoryMapHelper::GetMemoryMap(LimiterDSPSurround71MemoryMapHelper *this)
{
  return this->LimiterMemMapPtr;
}

// File Line: 1294
// RVA: 0xB01A10
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetCeiling(LimiterDSPSurround71MemoryMapHelper *this, long double ceiling, long double threshold)
{
  LimiterDSPSurround71MemoryMapHelper *v3; // rbx
  double v4; // xmm0_8
  float *v5; // rax
  float v6; // xmm1_4

  v3 = this;
  if ( threshold < 0.0 )
    ceiling = ceiling + -0.01;
  v4 = pow(10.0, ceiling * 0.05);
  v5 = v3->LimiterMemMapPtr->XMemory;
  v6 = v4;
  v5[51] = v6;
  v5[47] = v6;
  v5[43] = v6;
  v5[39] = v6;
  v5[35] = v6;
  v5[31] = v6;
  v5[27] = v6;
  v5[23] = v6;
}

// File Line: 1317
// RVA: 0xB01A90
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetThreshold(LimiterDSPSurround71MemoryMapHelper *this, long double threshold, long double knee, long double ceiling)
{
  LimiterDSPSurround71MemoryMapHelper::SetCeiling(this, ceiling, threshold);
}

// File Line: 1327
// RVA: 0xB01AB0
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetKnee(LimiterDSPSurround71MemoryMapHelper *this, long double knee, long double threshold)
{
  ;
}

// File Line: 1337
// RVA: 0xB019E0
void __fastcall LimiterDSPSurround71MemoryMapHelper::GenerateExpTable(LimiterDSPSurround71MemoryMapHelper *this, long double knee, long double threshold)
{
  LimiterUtilities::GenerateExpTable(&this->LimiterMemMapPtr->YMemory[23], 600, threshold, knee);
}

// File Line: 1345
// RVA: 0xB01AC0
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetRelease(LimiterDSPSurround71MemoryMapHelper *this, long double release, LimiterCharacterType character)
{
  double v3; // xmm2_8
  LimiterDSPSurround71MemoryMapHelper *v4; // rbx
  double v5; // xmm0_8
  double v6; // xmm1_8
  float v7; // xmm1_4
  double v8; // [rsp+30h] [rbp+8h]

  v3 = release;
  v4 = this;
  switch ( character )
  {
    case 0:
      v5 = DOUBLE_3_0;
      v6 = 0.0;
      break;
    case 1:
      v5 = DOUBLE_4_0;
      v6 = 0.0;
      break;
    case 2:
      v5 = DOUBLE_5_0;
      v6 = 0.0;
      break;
    case 3:
      v5 = DOUBLE_6_0;
      v6 = 0.0;
      break;
    case 4:
      v5 = DOUBLE_10_0;
      v6 = 0.0;
      break;
    case 5:
      v5 = DOUBLE_15_0;
      v6 = 0.0;
      break;
    default:
      v6 = v8;
      v5 = v8;
      break;
  }
  if ( v3 > v5 )
    v3 = v5;
  v7 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v6 + v3);
  v4->LimiterMemMapPtr->XMemory[14] = v7;
}

// File Line: 1370
// RVA: 0xB01B90
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetCharacter(LimiterDSPSurround71MemoryMapHelper *this, LimiterCharacterType character, long double release)
{
  LimiterDSPSurround71MemoryMapHelper *v3; // rbx
  long double v4; // xmm1_8
  double v5; // xmm6_8
  double v6; // xmm7_8
  double v7; // xmm8_8
  float v8; // xmm2_4
  float v9; // xmm1_4
  double releasea; // [rsp+60h] [rbp+8h]

  v3 = this;
  switch ( character )
  {
    case 0:
      v4 = DOUBLE_50_0;
      v5 = DOUBLE_800_0;
      v6 = DOUBLE_3_0;
      break;
    case 1:
      v4 = DOUBLE_40_0;
      v5 = DOUBLE_600_0;
      v6 = DOUBLE_4_0;
      break;
    case 2:
      v4 = DOUBLE_30_0;
      v5 = DOUBLE_400_0;
      v6 = DOUBLE_5_0;
      break;
    case 3:
      v4 = DOUBLE_20_0;
      v5 = DOUBLE_200_0;
      v6 = DOUBLE_6_0;
      break;
    case 4:
      v4 = DOUBLE_10_0;
      v5 = DOUBLE_100_0;
      v6 = DOUBLE_10_0;
      break;
    case 5:
      v4 = DOUBLE_5_0;
      v5 = DOUBLE_50_0;
      v6 = DOUBLE_15_0;
      break;
    default:
      v4 = releasea;
      v5 = releasea;
      v6 = releasea;
      break;
  }
  v7 = release - v6;
  v8 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v4);
  v3->LimiterMemMapPtr->XMemory[17] = v8;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v9 = DynamicsCalculator::CalculateReleaseScalar(v3->mSampleRate, v5 + v7);
  v3->LimiterMemMapPtr->XMemory[16] = v9;
}

// File Line: 1403
// RVA: 0xB01D00
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetAttack(LimiterDSPSurround71MemoryMapHelper *this)
{
  LimiterDSPSurround71MemoryMapHelper *v1; // rbx
  signed int v2; // eax
  float v3; // xmm1_4

  v1 = this;
  v2 = LimiterUtilities::GetLookAheadDelayLength(&this->mLimiterUtilities, (double)(signed int)this->mSampleRate);
  v3 = GetTCScalar((double)v2);
  v1->LimiterMemMapPtr->XMemory[15] = v3;
}

// File Line: 1415
// RVA: 0xB01D50
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetHold(LimiterDSPSurround71MemoryMapHelper *this)
{
  this->LimiterMemMapPtr->XMemory[13] = (float)(LimiterUtilities::GetTotalLookAheadDelayLength(
                                                  &this->mLimiterUtilities,
                                                  (double)(signed int)this->mSampleRate)
                                              + 1);
}

// File Line: 1429
// RVA: 0xB01D90
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetLookAhead(LimiterDSPSurround71MemoryMapHelper *this)
{
  LimiterDSPSurround71MemoryMapHelper *v1; // rbx
  signed int v2; // eax
  float *v3; // rdi
  __int64 v4; // rcx
  float v5; // eax

  v1 = this;
  this->LimiterMemMapPtr->XMemory[9] = 623.0;
  this->LimiterMemMapPtr->XMemory[8] = (float)LimiterUtilities::GetTotalLookAheadDelayLength(
                                                &this->mLimiterUtilities,
                                                (double)(signed int)this->mSampleRate);
  v1->LimiterMemMapPtr->XMemory[18] = 1378.0;
  v1->LimiterMemMapPtr->XMemory[19] = (float)LimiterUtilities::GetFIRLength(
                                               &v1->mLimiterUtilities,
                                               (double)(signed int)v1->mSampleRate);
  v2 = LimiterUtilities::GetFIRLength(&v1->mLimiterUtilities, (double)(signed int)v1->mSampleRate);
  v3 = &v1->LimiterMemMapPtr->XMemory[1378];
  if ( v2 > 0 )
  {
    v4 = (unsigned int)v2;
    v5 = 1.0 / (float)v2;
    while ( v4 )
    {
      *v3 = v5;
      ++v3;
      --v4;
    }
  }
}

// File Line: 1454
// RVA: 0xB019C0
int __fastcall LimiterDSPSurround71MemoryMapHelper::GetTotalLookAheadDelayLength(LimiterDSPSurround71MemoryMapHelper *this, unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(&this->mLimiterUtilities, (double)(signed int)this->mSampleRate);
}

// File Line: 1461
// RVA: 0xB01A00
void __fastcall LimiterDSPSurround71MemoryMapHelper::FillMeteringData(LimiterDSPSurround71MemoryMapHelper *this, char *pMeteringData)
{
  McDSPFillVUMetersDataSurround71(this->LimiterMemMapPtr, pMeteringData);
}

// File Line: 1472
// RVA: 0xB013C0
void __fastcall LimiterProcessSurround71FloatImpl::LimiterProcessSurround71FloatImpl(LimiterProcessSurround71FloatImpl *this)
{
  this->mMemoryMapHelper = 0i64;
}

// File Line: 1478
// RVA: 0xB013E0
void __fastcall LimiterProcessSurround71FloatImpl::~LimiterProcessSurround71FloatImpl(LimiterProcessSurround71FloatImpl *this)
{
  ;
}

// File Line: 1484
// RVA: 0xB013F0
unsigned __int64 __fastcall LimiterProcessSurround71FloatImpl::GetMemoryMapSize(LimiterProcessSurround71FloatImpl *this)
{
  return 11416i64;
}

// File Line: 1494
// RVA: 0xB01400
signed __int64 __fastcall LimiterProcessSurround71FloatImpl::Init(LimiterProcessSurround71FloatImpl *this, PooledMemoryAllocator *memoryMapAllocator, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int sampleRate)
{
  PooledMemoryAllocator *v4; // rbp
  LimiterProcessSurround71FloatImpl *v5; // rdi
  unsigned int v6; // esi
  DSPMemoryMapHelper *v7; // rax
  LimiterDSPSurround71MemoryMapHelper *v8; // rbx
  char *v9; // rax

  v4 = memoryMapAllocator;
  v5 = this;
  v6 = sampleRate;
  v7 = (DSPMemoryMapHelper *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24ui64);
  v8 = (LimiterDSPSurround71MemoryMapHelper *)v7;
  if ( v7 )
  {
    DSPMemoryMapHelper::DSPMemoryMapHelper(v7);
    LimiterUtilities::LimiterUtilities(&v8->mLimiterUtilities, 0.00085000001, 0.000325);
  }
  else
  {
    v8 = 0i64;
  }
  v5->mMemoryMapHelper = v8;
  if ( !v8 )
    return 52i64;
  v8->mNumChannels = 8;
  v8->mSampleRate = v6;
  v9 = PooledMemoryAllocator::Malloc(v4, 0x2C98ui64);
  v8->LimiterMemMapPtr = (LimiterSurround71MemoryMap *)v9;
  if ( !v9 )
    return 52i64;
  *((_DWORD *)v9 + 11) = 1065353216;
  v8->LimiterMemMapPtr->XMemory[10] = 1227.0;
  return 1i64;
}

// File Line: 1505
// RVA: 0xB014C0
void __fastcall LimiterProcessSurround71FloatImpl::Term(LimiterProcessSurround71FloatImpl *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterDSPSurround71MemoryMapHelper *v2; // rdi
  AK::IAkPluginMemAlloc *v3; // rsi
  LimiterProcessSurround71FloatImpl *v4; // rbx

  v2 = this->mMemoryMapHelper;
  v3 = in_pAllocator;
  v4 = this;
  if ( this->mMemoryMapHelper )
  {
    LimiterUtilities::~LimiterUtilities(&v2->mLimiterUtilities);
    DSPMemoryMapHelper::~DSPMemoryMapHelper(&v2->0);
    v3->vfptr->Free(v3, v2);
    v4->mMemoryMapHelper = 0i64;
  }
  else
  {
    this->mMemoryMapHelper = 0i64;
  }
}

// File Line: 1513
// RVA: 0xB01530
void __fastcall LimiterProcessSurround71FloatImpl::SetParameters(LimiterProcessSurround71FloatImpl *this, LimiterParameters *limiterParams)
{
  LimiterParameters *v2; // rdi
  LimiterProcessSurround71FloatImpl *v3; // rsi
  long double v4; // xmm6_8
  LimiterDSPSurround71MemoryMapHelper *v5; // rbx
  signed int v6; // eax
  long double v7; // xmm0_8
  LimiterDSPSurround71MemoryMapHelper *v8; // rcx
  float v9; // xmm1_4
  LimiterDSPSurround71MemoryMapHelper *v10; // rbx
  int v11; // eax
  LimiterDSPSurround71MemoryMapHelper *v12; // rcx

  v2 = limiterParams;
  v3 = this;
  v4 = limiterParams->threshold - 12.0;
  if ( v4 < -36.0 )
    v4 = DOUBLE_N36_0;
  LimiterDSPSurround71MemoryMapHelper::SetCeiling(this->mMemoryMapHelper, limiterParams->ceiling, v4);
  LimiterDSPSurround71MemoryMapHelper::SetCeiling(v3->mMemoryMapHelper, v2->ceiling, v4);
  LimiterUtilities::GenerateExpTable(&v3->mMemoryMapHelper->LimiterMemMapPtr->YMemory[23], 600, v4, v2->knee);
  v5 = v3->mMemoryMapHelper;
  v6 = LimiterUtilities::GetLookAheadDelayLength(
         &v3->mMemoryMapHelper->mLimiterUtilities,
         (double)v3->mMemoryMapHelper->mSampleRate);
  v7 = GetTCScalar((double)v6);
  v8 = v3->mMemoryMapHelper;
  v9 = v7;
  v5->LimiterMemMapPtr->XMemory[15] = v9;
  LimiterDSPSurround71MemoryMapHelper::SetRelease(v8, v2->release, v2->character);
  LimiterDSPSurround71MemoryMapHelper::SetCharacter(v3->mMemoryMapHelper, v2->character, v2->release);
  v10 = v3->mMemoryMapHelper;
  v11 = LimiterUtilities::GetTotalLookAheadDelayLength(
          &v3->mMemoryMapHelper->mLimiterUtilities,
          (double)v3->mMemoryMapHelper->mSampleRate);
  v12 = v3->mMemoryMapHelper;
  v10->LimiterMemMapPtr->XMemory[13] = (float)(v11 + 1);
  LimiterDSPSurround71MemoryMapHelper::SetLookAhead(v12);
}

// File Line: 1566
// RVA: 0xB01650
void __fastcall LimiterProcessSurround71FloatImpl::ProcessAudio(LimiterProcessSurround71FloatImpl *this, void *memoryMap, AkAudioBuffer *inputBuffer, AkAudioBuffer *outputBuffer)
{
  float *outputBuf_L; // r10
  __int64 v5; // rcx
  __int64 v6; // r9

  outputBuf_L = (float *)outputBuffer->pData;
  v5 = outputBuffer->uMaxFrames;
  v6 = inputBuffer->uMaxFrames;
  McDSPLimiterProcessChannels(
    memoryMap,
    (const float *)inputBuffer->pData,
    (const float *)inputBuffer->pData + 2 * v6,
    (const float *)inputBuffer->pData + v6,
    (const float *)inputBuffer->pData + 3 * v6,
    (const float *)inputBuffer->pData + 4 * v6,
    (const float *)inputBuffer->pData + 5 * v6,
    (const float *)inputBuffer->pData + 6 * v6,
    (const float *)inputBuffer->pData + 7 * v6,
    outputBuf_L,
    &outputBuf_L[2 * v5],
    &outputBuf_L[v5],
    &outputBuf_L[3 * v5],
    &outputBuf_L[4 * (unsigned int)v5],
    &outputBuf_L[5 * v5],
    &outputBuf_L[6 * v5],
    &outputBuf_L[7 * (unsigned int)v5],
    inputBuffer->uValidFrames);
}

// File Line: 1596
// RVA: 0xB017B0
int __fastcall LimiterProcessSurround71FloatImpl::GetNumTailFrames(LimiterProcessSurround71FloatImpl *this, unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(
           &this->mMemoryMapHelper->mLimiterUtilities,
           (double)this->mMemoryMapHelper->mSampleRate);
}

// File Line: 1601
// RVA: 0xB017D0
void __fastcall LimiterProcessSurround71FloatImpl::FillMeteringData(LimiterProcessSurround71FloatImpl *this, char *pMeteringData)
{
  McDSPFillVUMetersDataSurround71(this->mMemoryMapHelper->LimiterMemMapPtr, pMeteringData);
}

