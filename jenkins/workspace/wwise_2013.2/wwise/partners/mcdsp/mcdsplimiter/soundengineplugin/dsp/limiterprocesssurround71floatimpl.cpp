// File Line: 235
// RVA: 0xB00510
void __fastcall McDSPLimiterProcessChannels(
        char *memoryMap,
        const float *inputBuf_L,
        const float *inputBuf_C,
        const float *inputBuf_R,
        const float *inputBuf_Ls,
        float *inputBuf_Rs,
        const float *inputBuf_LFE,
        float *inputBuf_Lsb,
        const float *inputBuf_Rsb,
        float *outputBuf_L,
        float *outputBuf_C,
        float *outputBuf_R,
        float *outputBuf_Ls,
        float *outputBuf_Rs,
        float *outputBuf_LFE,
        float *outputBuf_Lsb,
        float *outputBuf_Rsb,
        unsigned int samplesRemaining)
{
  int v18; // r13d
  float *v20; // rbx
  int v22; // r9d
  int v23; // r12d
  int v24; // ecx
  int v25; // edi
  __int64 v26; // r14
  int v27; // eax
  unsigned int v28; // ecx
  float v29; // xmm9_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  _DWORD *v32; // r11
  float v33; // xmm1_4
  float v34; // xmm0_4
  float *v35; // rax
  float v36; // xmm1_4
  float v37; // xmm0_4
  float *v38; // rax
  float v39; // xmm1_4
  float v40; // xmm0_4
  int v41; // edx
  __int64 v42; // r8
  float v43; // xmm4_4
  __int64 v44; // rax
  __int64 v45; // r14
  int v46; // xmm2_4
  int v47; // xmm1_4
  int v48; // ecx
  int v49; // edx
  int v50; // xmm2_4
  int v51; // xmm1_4
  int v52; // xmm2_4
  int v53; // xmm1_4
  __int64 v54; // rcx
  int v55; // xmm1_4
  int v56; // xmm0_4
  int v57; // xmm4_4
  int v58; // xmm2_4
  int v59; // xmm2_4
  int v60; // r9d
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
  int v76; // xmm4_4
  int v77; // xmm0_4
  float v78; // xmm5_4
  float v79; // xmm0_4
  float v80; // xmm2_4
  float v81; // xmm0_4
  __int64 v82; // rcx
  __int64 v83; // r8
  int v84; // r9d
  float v85; // xmm4_4
  __int64 v86; // rax
  float v87; // xmm5_4
  float v88; // xmm0_4
  __int64 v89; // rax
  float *v90; // rcx
  unsigned int v91; // eax
  __int64 v92; // r8
  float *v93; // rcx
  __int64 v94; // r8
  float v95; // xmm2_4
  float v96; // xmm4_4
  float v97; // xmm5_4
  int v98; // xmm4_4
  float v99; // xmm2_4
  float v100; // xmm4_4
  float v101; // xmm2_4
  float *v102; // rax
  int v103; // xmm4_4
  float v104; // xmm2_4
  float v105; // xmm4_4
  float v106; // xmm2_4
  float *v107; // rax
  int v108; // xmm4_4
  float v109; // xmm2_4
  float v110; // xmm4_4
  float v111; // xmm2_4
  float *v112; // rax
  int v113; // xmm4_4
  float v114; // xmm2_4
  float v115; // xmm4_4
  float v116; // xmm2_4
  float *v117; // rax
  int v118; // xmm4_4
  float v119; // xmm2_4
  float v120; // xmm4_4
  float v121; // xmm2_4
  float *v122; // rax
  int v123; // xmm4_4
  float v124; // xmm2_4
  float v125; // xmm4_4
  float v126; // xmm2_4
  float *v127; // rax
  int v128; // xmm4_4
  float v129; // xmm2_4
  float v130; // xmm4_4
  float v131; // xmm2_4
  float *v132; // rax
  int v133; // xmm4_4
  float v134; // xmm2_4
  float v135; // xmm4_4
  float v136; // xmm2_4
  int v137; // [rsp+0h] [rbp-F8h]
  int v138; // [rsp+4h] [rbp-F4h]
  int v139; // [rsp+8h] [rbp-F0h]
  int v140; // [rsp+Ch] [rbp-ECh]
  int v141; // [rsp+10h] [rbp-E8h]
  __int64 v142; // [rsp+18h] [rbp-E0h]
  __int64 v143; // [rsp+28h] [rbp-D0h]
  __int64 v144; // [rsp+30h] [rbp-C8h]
  __int64 v145; // [rsp+38h] [rbp-C0h]
  __int64 v146; // [rsp+40h] [rbp-B8h]
  __int64 v147; // [rsp+48h] [rbp-B0h]
  int v148; // [rsp+100h] [rbp+8h]
  const float *v149; // [rsp+108h] [rbp+10h]
  const float *v150; // [rsp+110h] [rbp+18h]
  unsigned int samplesRemaininga; // [rsp+188h] [rbp+90h]

  v18 = (int)*((float *)memoryMap + 8);
  v20 = (float *)(memoryMap + 32);
  v22 = (int)*((float *)memoryMap + 1435);
  v23 = (int)*((float *)memoryMap + 1445);
  v24 = (int)*((float *)memoryMap + 9);
  *(_QWORD *)(memoryMap + 84) = 0i64;
  *(_QWORD *)(memoryMap + 116) = 0i64;
  *(_QWORD *)(memoryMap + 100) = 0i64;
  v140 = v24;
  *(_QWORD *)(memoryMap + 132) = 0i64;
  v146 = v24;
  *(_QWORD *)(memoryMap + 148) = 0i64;
  *(_QWORD *)(memoryMap + 164) = 0i64;
  *(_QWORD *)(memoryMap + 180) = 0i64;
  *(_QWORD *)(memoryMap + 196) = 0i64;
  *((_DWORD *)memoryMap + 53) = 0;
  v25 = (int)*((float *)memoryMap + 20);
  v139 = (int)*((float *)memoryMap + 13);
  v26 = v22;
  v144 = (int)*((float *)memoryMap + 10);
  v138 = (int)*((float *)memoryMap + 10);
  v148 = v25;
  v27 = (int)*((float *)memoryMap + 18);
  v141 = (int)*((float *)memoryMap + 19);
  v143 = v27;
  v142 = v25;
  v28 = samplesRemaining;
  if ( samplesRemaining )
  {
    v145 = v27 + 1;
    v29 = kHeadRoomScaleFactor_2;
    do
    {
      samplesRemaininga = v28 - 1;
      v149 = inputBuf_L + 1;
      v150 = inputBuf_C + 1;
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
      *((float *)memoryMap + 1427) = v30;
      v32 = memoryMap + 5712;
      ++inputBuf_R;
      ++inputBuf_Ls;
      *((float *)memoryMap + 1428) = v31;
      v33 = v29 * *(inputBuf_R - 1);
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
      v35 = inputBuf_Rs;
      *((float *)memoryMap + 1429) = v33;
      *((float *)memoryMap + 1430) = v34;
      ++inputBuf_Rs;
      v36 = v29 * *v35;
      v37 = v29 * *inputBuf_LFE++;
      if ( v36 < 1.0 )
      {
        if ( v36 <= -1.0 )
          v36 = FLOAT_N1_0;
      }
      else
      {
        v36 = *(float *)&FLOAT_1_0;
      }
      if ( v37 < 1.0 )
      {
        if ( v37 <= -1.0 )
          v37 = FLOAT_N1_0;
      }
      else
      {
        v37 = *(float *)&FLOAT_1_0;
      }
      v38 = inputBuf_Lsb;
      *((float *)memoryMap + 1431) = v36;
      *((float *)memoryMap + 1432) = v37;
      ++inputBuf_Lsb;
      v39 = v29 * *v38;
      v40 = v29 * *inputBuf_Rsb++;
      if ( v39 < 1.0 )
      {
        if ( v39 <= -1.0 )
          v39 = FLOAT_N1_0;
      }
      else
      {
        v39 = *(float *)&FLOAT_1_0;
      }
      if ( v40 < 1.0 )
      {
        if ( v40 <= -1.0 )
          v40 = FLOAT_N1_0;
      }
      else
      {
        v40 = *(float *)&FLOAT_1_0;
      }
      *((float *)memoryMap + 1433) = v39;
      v41 = v22 + 1;
      *((float *)memoryMap + 1434) = v40;
      v42 = v26 + 1;
      v43 = *v20;
      if ( v22 + 1 >= v18 )
      {
        v41 = 0;
        v42 = 0i64;
      }
      v44 = v26 + v146;
      v45 = v144 + v26;
      v46 = *(_DWORD *)&memoryMap[4 * v44];
      *(_DWORD *)&memoryMap[4 * v44] = *((_DWORD *)memoryMap + 1427);
      v47 = *(_DWORD *)&memoryMap[4 * v44 + 5708];
      v137 = v41;
      v147 = v42;
      v48 = (int)v43 + v22 + v140 + 1;
      *(_DWORD *)&memoryMap[4 * v44 + 5708] = *v32;
      *((_DWORD *)memoryMap + 1436) = v46;
      *((_DWORD *)memoryMap + 1437) = v47;
      v49 = (int)v43 + v48 + 1;
      v50 = *(_DWORD *)&memoryMap[4 * v48];
      *(_DWORD *)&memoryMap[4 * v48] = *((_DWORD *)memoryMap + 1429);
      v51 = *(_DWORD *)&memoryMap[4 * v48 + 5708];
      *(_DWORD *)&memoryMap[4 * v48 + 5708] = *((_DWORD *)memoryMap + 1430);
      *((_DWORD *)memoryMap + 1438) = v50;
      *((_DWORD *)memoryMap + 1439) = v51;
      v52 = *(_DWORD *)&memoryMap[4 * v49];
      *(_DWORD *)&memoryMap[4 * v49] = *((_DWORD *)memoryMap + 1431);
      v53 = *(_DWORD *)&memoryMap[4 * v49 + 5708];
      *(_DWORD *)&memoryMap[4 * v49 + 5708] = *((_DWORD *)memoryMap + 1432);
      *((_DWORD *)memoryMap + 1440) = v52;
      *((_DWORD *)memoryMap + 1441) = v53;
      v54 = v49 + (int)v43 + 1;
      v55 = *(_DWORD *)&memoryMap[4 * v54];
      *(_DWORD *)&memoryMap[4 * v54] = *((_DWORD *)memoryMap + 1433);
      v56 = *(_DWORD *)&memoryMap[4 * v54 + 5708];
      *(_DWORD *)&memoryMap[4 * v54 + 5708] = *((_DWORD *)memoryMap + 1434);
      *((_DWORD *)memoryMap + 1442) = v55;
      *((_DWORD *)memoryMap + 1443) = v56;
      v57 = *v32;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1427) & _xmm) > COERCE_FLOAT(*v32 & _xmm) )
        v57 = *((_DWORD *)memoryMap + 1427);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1429) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)memoryMap + 1429);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1430) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)memoryMap + 1430);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1431) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)memoryMap + 1431);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1432) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)memoryMap + 1432);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1433) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)memoryMap + 1433);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1434) & _xmm) > COERCE_FLOAT(v57 & _xmm) )
        v57 = *((_DWORD *)memoryMap + 1434);
      v58 = *((_DWORD *)memoryMap + 1437);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1436) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)memoryMap + 1436);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1438) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)memoryMap + 1438);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1439) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)memoryMap + 1439);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1440) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)memoryMap + 1440);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1441) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)memoryMap + 1441);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1442) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)memoryMap + 1442);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1443) & _xmm) > COERCE_FLOAT(v58 & _xmm) )
        v58 = *((_DWORD *)memoryMap + 1443);
      *((_DWORD *)memoryMap + 1444) = v58;
      *(_DWORD *)&memoryMap[4 * v45 + 5708] = v57;
      v59 = 0;
      v60 = 0;
      v61 = &memoryMap[4 * v138 + 5708];
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
      LODWORD(v65) = *((_DWORD *)memoryMap + 1427) & _xmm;
      v66 = v20[4];
      if ( COERCE_FLOAT(*v32 & _xmm) > v65 )
        LODWORD(v65) = *v32 & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1429) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)memoryMap + 1429) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1430) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)memoryMap + 1430) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1431) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)memoryMap + 1431) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1432) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)memoryMap + 1432) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1433) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)memoryMap + 1433) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1434) & _xmm) > v65 )
        LODWORD(v65) = *((_DWORD *)memoryMap + 1434) & _xmm;
      if ( v65 >= 1.0 )
        v65 = *(float *)&FLOAT_1_0;
      if ( COERCE_FLOAT((_DWORD)v20[3] & _xmm) <= COERCE_FLOAT(LODWORD(v65) & _xmm) )
        v65 = v20[3];
      v67 = *((float *)memoryMap + 1446);
      if ( COERCE_FLOAT(LODWORD(v65) & _xmm) > COERCE_FLOAT(LODWORD(v67) & _xmm) )
      {
        v23 = v139;
        v67 = v65;
      }
      LODWORD(v68) = LODWORD(v67) & _xmm;
      *((float *)memoryMap + 1446) = v68;
      v69 = v68 - v66;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1447) & _xmm) > COERCE_FLOAT(LODWORD(v69) & _xmm) )
        v69 = *((float *)memoryMap + 1447);
      *((float *)memoryMap + 1447) = v69;
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
      v73 = (float)((float)(*((float *)memoryMap + 1447) * v70) + v20[4]) + (float)((float)(v72 - v20[4]) * v71);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1446) & _xmm) <= COERCE_FLOAT(LODWORD(v73) & _xmm) )
        v73 = *((float *)memoryMap + 1446);
      v74 = *((_DWORD *)memoryMap + 1447);
      if ( v23 <= 0 )
        v74 = 0;
      *((_DWORD *)memoryMap + 1447) = v74;
      v75 = *((_DWORD *)memoryMap + 1444);
      if ( COERCE_FLOAT(v75 & _xmm) > COERCE_FLOAT(LODWORD(v73) & _xmm) )
        v73 = *((float *)memoryMap + 1444);
      v76 = LODWORD(v73) & _xmm;
      *((_DWORD *)v20 + 4) = v76;
      v77 = *((_DWORD *)memoryMap + 1446);
      if ( COERCE_FLOAT(v75 & _xmm) > COERCE_FLOAT(v76 & _xmm) )
        v77 = v75;
      *((_DWORD *)memoryMap + 1446) = v77 & _xmm;
      v78 = v20[8];
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1448) & _xmm) < COERCE_FLOAT(LODWORD(v72) & _xmm) )
        v78 = v20[9];
      v79 = v20[4];
      v80 = (float)((float)(v72 - *((float *)memoryMap + 1448)) * v78) + *((float *)memoryMap + 1448);
      *((float *)memoryMap + 1448) = v80;
      if ( v79 > v80 )
        v80 = v79;
      v20[4] = v80;
      v81 = *((float *)memoryMap + 1446);
      if ( v23 <= 0 )
        v81 = v80;
      *((float *)memoryMap + 1446) = v81;
      v25 = v148 + 1;
      v82 = v142 + 1;
      v83 = v142;
      ++v148;
      if ( v142 + 1 >= v141 )
      {
        v25 = 0;
        v148 = 0;
        v82 = 0i64;
      }
      v84 = 0;
      v85 = 0.0;
      v86 = v143 + v142;
      v142 = v82;
      *(float *)&memoryMap[4 * v86 + 5708] = v80;
      v87 = *(float *)&memoryMap[4 * v143];
      v88 = *(float *)&memoryMap[4 * (v86 - v83) + 5708];
      v89 = v145;
      if ( v141 >= 4 )
      {
        v90 = (float *)&memoryMap[4 * v145 + 5716];
        v91 = ((unsigned int)(v141 - 4) >> 2) + 1;
        v92 = v91;
        v84 = 4 * v91;
        v89 = v145 + 4i64 * v91;
        do
        {
          v90 += 4;
          v85 = (float)((float)((float)(v85 + (float)(v88 * v87)) + (float)(v87 * *(v90 - 6)))
                      + (float)(v87 * *(v90 - 5)))
              + (float)(v87 * *(v90 - 4));
          v88 = *(v90 - 3);
          --v92;
        }
        while ( v92 );
      }
      if ( v84 < v141 )
      {
        v93 = (float *)&memoryMap[4 * v89 + 5708];
        v94 = (unsigned int)(v141 - v84);
        do
        {
          ++v93;
          v85 = v85 + (float)(v88 * v87);
          v88 = *(v93 - 1);
          --v94;
        }
        while ( v94 );
      }
      v95 = (float)((float)((float)((float)(v85 * 2.0) - (float)(v85 * v85)) * 2.0)
                  - (float)((float)((float)(v85 * 2.0) - (float)(v85 * v85))
                          * (float)((float)(v85 * 2.0) - (float)(v85 * v85))))
          * 599.0;
      v96 = (float)((float)(*(float *)&memoryMap[4 * (int)v95 + 5804] - *(float *)&memoryMap[4 * (int)v95 + 5800])
                  * (float)(v95 - (float)(int)v95))
          + *(float *)&memoryMap[4 * (int)v95 + 5800];
      v97 = v96;
      if ( COERCE_FLOAT((_DWORD)v20[13] & _xmm) > COERCE_FLOAT(LODWORD(v96) & _xmm) )
        v96 = v20[13];
      v20[13] = v96;
      v98 = *((_DWORD *)v20 + 14);
      v99 = *((float *)memoryMap + 1436);
      if ( COERCE_FLOAT(LODWORD(v99) & _xmm) > COERCE_FLOAT(v98 & _xmm) )
        v98 = *((_DWORD *)memoryMap + 1436);
      *((_DWORD *)v20 + 14) = v98;
      v100 = v20[17];
      v101 = (float)(v99 * v97) * v20[15];
      if ( COERCE_FLOAT(LODWORD(v101) & _xmm) > COERCE_FLOAT(LODWORD(v100) & _xmm) )
        v100 = v101;
      v102 = outputBuf_L;
      v20[17] = v100;
      ++outputBuf_L;
      *v102 = v101;
      v103 = *((_DWORD *)v20 + 18);
      v104 = *((float *)memoryMap + 1437);
      if ( COERCE_FLOAT(LODWORD(v104) & _xmm) > COERCE_FLOAT(v103 & _xmm) )
        v103 = *((_DWORD *)memoryMap + 1437);
      *((_DWORD *)v20 + 18) = v103;
      v105 = v20[21];
      v106 = (float)(v104 * v97) * v20[19];
      if ( COERCE_FLOAT(LODWORD(v106) & _xmm) > COERCE_FLOAT(LODWORD(v105) & _xmm) )
        v105 = v106;
      v107 = outputBuf_C;
      v20[21] = v105;
      ++outputBuf_C;
      *v107 = v106;
      v108 = *((_DWORD *)v20 + 22);
      v109 = *((float *)memoryMap + 1438);
      if ( COERCE_FLOAT(LODWORD(v109) & _xmm) > COERCE_FLOAT(v108 & _xmm) )
        v108 = *((_DWORD *)memoryMap + 1438);
      *((_DWORD *)v20 + 22) = v108;
      v110 = v20[25];
      v111 = (float)(v109 * v97) * v20[23];
      if ( COERCE_FLOAT(LODWORD(v111) & _xmm) > COERCE_FLOAT(LODWORD(v110) & _xmm) )
        v110 = v111;
      v112 = outputBuf_R;
      v20[25] = v110;
      ++outputBuf_R;
      *v112 = v111;
      v113 = *((_DWORD *)v20 + 26);
      v114 = *((float *)memoryMap + 1439);
      if ( COERCE_FLOAT(LODWORD(v114) & _xmm) > COERCE_FLOAT(v113 & _xmm) )
        v113 = *((_DWORD *)memoryMap + 1439);
      *((_DWORD *)v20 + 26) = v113;
      v115 = v20[29];
      v116 = (float)(v114 * v97) * v20[27];
      if ( COERCE_FLOAT(LODWORD(v116) & _xmm) > COERCE_FLOAT(LODWORD(v115) & _xmm) )
        v115 = v116;
      v117 = outputBuf_Ls;
      v20[29] = v115;
      ++outputBuf_Ls;
      *v117 = v116;
      v118 = *((_DWORD *)v20 + 30);
      v119 = *((float *)memoryMap + 1440);
      if ( COERCE_FLOAT(LODWORD(v119) & _xmm) > COERCE_FLOAT(v118 & _xmm) )
        v118 = *((_DWORD *)memoryMap + 1440);
      *((_DWORD *)v20 + 30) = v118;
      v120 = v20[33];
      v121 = (float)(v119 * v97) * v20[31];
      if ( COERCE_FLOAT(LODWORD(v121) & _xmm) > COERCE_FLOAT(LODWORD(v120) & _xmm) )
        v120 = v121;
      v122 = outputBuf_Rs;
      v20[33] = v120;
      ++outputBuf_Rs;
      *v122 = v121;
      v123 = *((_DWORD *)v20 + 34);
      v124 = *((float *)memoryMap + 1441);
      if ( COERCE_FLOAT(LODWORD(v124) & _xmm) > COERCE_FLOAT(v123 & _xmm) )
        v123 = *((_DWORD *)memoryMap + 1441);
      *((_DWORD *)v20 + 34) = v123;
      v125 = v20[37];
      v126 = (float)(v124 * v97) * v20[35];
      if ( COERCE_FLOAT(LODWORD(v126) & _xmm) > COERCE_FLOAT(LODWORD(v125) & _xmm) )
        v125 = v126;
      v127 = outputBuf_LFE;
      v20[37] = v125;
      ++outputBuf_LFE;
      *v127 = v126;
      v128 = *((_DWORD *)v20 + 38);
      v129 = *((float *)memoryMap + 1442);
      if ( COERCE_FLOAT(LODWORD(v129) & _xmm) > COERCE_FLOAT(v128 & _xmm) )
        v128 = *((_DWORD *)memoryMap + 1442);
      *((_DWORD *)v20 + 38) = v128;
      v130 = v20[41];
      v131 = (float)(v129 * v97) * v20[39];
      if ( COERCE_FLOAT(LODWORD(v131) & _xmm) > COERCE_FLOAT(LODWORD(v130) & _xmm) )
        v130 = v131;
      v132 = outputBuf_Lsb;
      v20[41] = v130;
      ++outputBuf_Lsb;
      *v132 = v131;
      v133 = *((_DWORD *)v20 + 42);
      v134 = *((float *)memoryMap + 1443);
      if ( COERCE_FLOAT(LODWORD(v134) & _xmm) > COERCE_FLOAT(v133 & _xmm) )
        v133 = *((_DWORD *)memoryMap + 1443);
      *((_DWORD *)v20 + 42) = v133;
      v135 = v20[45];
      v136 = (float)(v134 * v97) * v20[43];
      if ( COERCE_FLOAT(LODWORD(v136) & _xmm) > COERCE_FLOAT(LODWORD(v135) & _xmm) )
        v135 = v136;
      v28 = samplesRemaininga;
      inputBuf_C = v150;
      v20[45] = v135;
      inputBuf_L = v149;
      v22 = v137;
      v26 = v147;
      *outputBuf_Rsb = v136;
      v20 = (float *)(memoryMap + 32);
      ++outputBuf_Rsb;
    }
    while ( samplesRemaininga );
  }
  *((float *)memoryMap + 1445) = (float)v23;
  *((float *)memoryMap + 1435) = (float)v22;
  *((float *)memoryMap + 20) = (float)v25;
}

// File Line: 1160
// RVA: 0xB017F0
void __fastcall McDSPFillVUMetersDataSurround71(float *memoryMap, float *pMeteringData)
{
  *(_DWORD *)pMeteringData = 1599;
  pMeteringData[1] = memoryMap[21];
  pMeteringData[2] = memoryMap[22] * 3.9810717;
  pMeteringData[3] = memoryMap[30] * 3.9810717;
  pMeteringData[4] = memoryMap[26] * 3.9810717;
  pMeteringData[5] = memoryMap[34] * 3.9810717;
  pMeteringData[6] = memoryMap[38] * 3.9810717;
  pMeteringData[7] = memoryMap[42] * 3.9810717;
  pMeteringData[8] = memoryMap[46] * 3.9810717;
  pMeteringData[9] = memoryMap[50] * 3.9810717;
  pMeteringData[10] = memoryMap[25];
  pMeteringData[11] = memoryMap[33];
  pMeteringData[12] = memoryMap[29];
  pMeteringData[13] = memoryMap[37];
  pMeteringData[14] = memoryMap[41];
  pMeteringData[15] = memoryMap[45];
  pMeteringData[16] = memoryMap[49];
  pMeteringData[17] = memoryMap[53];
}

// File Line: 1244
// RVA: 0xB018D0
void __fastcall LimiterDSPSurround71MemoryMapHelper::LimiterDSPSurround71MemoryMapHelper(
        LimiterDSPSurround71MemoryMapHelper *this,
        int sampleRate)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  LimiterUtilities::LimiterUtilities(&this->mLimiterUtilities, 0.00085000001, 0.000325);
}

// File Line: 1250
// RVA: 0xB01910
void __fastcall LimiterDSPSurround71MemoryMapHelper::~LimiterDSPSurround71MemoryMapHelper(
        LimiterDSPSurround71MemoryMapHelper *this)
{
  LimiterUtilities::~LimiterUtilities(&this->mLimiterUtilities);
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 1255
// RVA: 0xB01940
unsigned __int64 __fastcall LimiterDSPSurround71MemoryMapHelper::GetMemoryMapSize(
        LimiterDSPSurround71MemoryMapHelper *this)
{
  return 11416i64;
}

// File Line: 1263
// RVA: 0xB01950
__int64 __fastcall LimiterDSPSurround71MemoryMapHelper::Init(
        LimiterDSPSurround71MemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int sampleRate)
{
  char *v4; // rax

  this->mNumChannels = 8;
  this->mSampleRate = sampleRate;
  v4 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x2C98ui64);
  this->LimiterMemMapPtr = (LimiterSurround71MemoryMap *)v4;
  if ( !v4 )
    return 52i64;
  *((_DWORD *)v4 + 11) = 1065353216;
  this->LimiterMemMapPtr->XMemory[10] = 1227.0;
  return 1i64;
}

// File Line: 1287
// RVA: 0xB019B0
LimiterSurround71MemoryMap *__fastcall LimiterDSPSurround71MemoryMapHelper::GetMemoryMap(
        LimiterDSPSurround71MemoryMapHelper *this)
{
  return this->LimiterMemMapPtr;
}

// File Line: 1294
// RVA: 0xB01A10
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetCeiling(
        LimiterDSPSurround71MemoryMapHelper *this,
        long double ceiling,
        double threshold)
{
  double v4; // xmm0_8
  LimiterSurround71MemoryMap *LimiterMemMapPtr; // rax
  float v6; // xmm1_4

  if ( threshold < 0.0 )
    ceiling = ceiling + -0.01;
  v4 = pow(10.0, ceiling * 0.05);
  LimiterMemMapPtr = this->LimiterMemMapPtr;
  v6 = v4;
  LimiterMemMapPtr->XMemory[51] = v6;
  LimiterMemMapPtr->XMemory[47] = v6;
  LimiterMemMapPtr->XMemory[43] = v6;
  LimiterMemMapPtr->XMemory[39] = v6;
  LimiterMemMapPtr->XMemory[35] = v6;
  LimiterMemMapPtr->XMemory[31] = v6;
  LimiterMemMapPtr->XMemory[27] = v6;
  LimiterMemMapPtr->XMemory[23] = v6;
}

// File Line: 1317
// RVA: 0xB01A90
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetThreshold(
        LimiterDSPSurround71MemoryMapHelper *this,
        double threshold,
        long double knee,
        long double ceiling)
{
  LimiterDSPSurround71MemoryMapHelper::SetCeiling(this, ceiling, threshold);
}

// File Line: 1327
// RVA: 0xB01AB0
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetKnee(
        LimiterDSPSurround71MemoryMapHelper *this,
        long double knee,
        long double threshold)
{
  ;
}

// File Line: 1337
// RVA: 0xB019E0
void __fastcall LimiterDSPSurround71MemoryMapHelper::GenerateExpTable(
        LimiterDSPSurround71MemoryMapHelper *this,
        long double knee,
        long double threshold)
{
  LimiterUtilities::GenerateExpTable(&this->LimiterMemMapPtr->YMemory[23], 600, threshold, knee);
}

// File Line: 1345
// RVA: 0xB01AC0
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetRelease(
        LimiterDSPSurround71MemoryMapHelper *this,
        double release,
        LimiterCharacterType character)
{
  double v5; // xmm0_8
  double v6; // xmm1_8
  float v7; // xmm1_4
  double v8; // [rsp+30h] [rbp+8h]

  switch ( character )
  {
    case eCharacterMode_Clean:
      v5 = DOUBLE_3_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Soft:
      v5 = DOUBLE_4_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Smart:
      v5 = DOUBLE_5_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Dynamic:
      v5 = DOUBLE_6_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Loud:
      v5 = DOUBLE_10_0;
      v6 = 0.0;
      break;
    case eCharacterMode_Crush:
      v5 = DOUBLE_15_0;
      v6 = 0.0;
      break;
    default:
      v6 = v8;
      v5 = v8;
      break;
  }
  if ( release > v5 )
    release = v5;
  v7 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v6 + release);
  this->LimiterMemMapPtr->XMemory[14] = v7;
}

// File Line: 1370
// RVA: 0xB01B90
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetCharacter(
        LimiterDSPSurround71MemoryMapHelper *this,
        LimiterCharacterType character,
        long double release)
{
  long double v4; // xmm1_8
  double v5; // xmm6_8
  double v6; // xmm7_8
  double v7; // xmm8_8
  float v8; // xmm2_4
  float v9; // xmm1_4
  double releasea; // [rsp+60h] [rbp+8h]

  switch ( character )
  {
    case eCharacterMode_Clean:
      v4 = DOUBLE_50_0;
      v5 = DOUBLE_800_0;
      v6 = DOUBLE_3_0;
      break;
    case eCharacterMode_Soft:
      v4 = DOUBLE_40_0;
      v5 = DOUBLE_600_0;
      v6 = DOUBLE_4_0;
      break;
    case eCharacterMode_Smart:
      v4 = DOUBLE_30_0;
      v5 = DOUBLE_400_0;
      v6 = DOUBLE_5_0;
      break;
    case eCharacterMode_Dynamic:
      v4 = DOUBLE_20_0;
      v5 = DOUBLE_200_0;
      v6 = DOUBLE_6_0;
      break;
    case eCharacterMode_Loud:
      v4 = DOUBLE_10_0;
      v5 = DOUBLE_100_0;
      v6 = DOUBLE_10_0;
      break;
    case eCharacterMode_Crush:
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
  this->LimiterMemMapPtr->XMemory[17] = v8;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v9 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v5 + v7);
  this->LimiterMemMapPtr->XMemory[16] = v9;
}

// File Line: 1403
// RVA: 0xB01D00
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetAttack(LimiterDSPSurround71MemoryMapHelper *this)
{
  int LookAheadDelayLength; // eax
  float TCScalar; // xmm1_4

  LookAheadDelayLength = LimiterUtilities::GetLookAheadDelayLength(
                           &this->mLimiterUtilities,
                           (double)(int)this->mSampleRate);
  TCScalar = GetTCScalar((double)LookAheadDelayLength);
  this->LimiterMemMapPtr->XMemory[15] = TCScalar;
}

// File Line: 1415
// RVA: 0xB01D50
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetHold(LimiterDSPSurround71MemoryMapHelper *this)
{
  this->LimiterMemMapPtr->XMemory[13] = (float)(LimiterUtilities::GetTotalLookAheadDelayLength(
                                                  &this->mLimiterUtilities,
                                                  (double)(int)this->mSampleRate)
                                              + 1);
}

// File Line: 1429
// RVA: 0xB01D90
void __fastcall LimiterDSPSurround71MemoryMapHelper::SetLookAhead(LimiterDSPSurround71MemoryMapHelper *this)
{
  int FIRLength; // eax
  float *v3; // rdi
  __int64 v4; // rcx
  float v5; // eax

  this->LimiterMemMapPtr->XMemory[9] = 623.0;
  this->LimiterMemMapPtr->XMemory[8] = (float)LimiterUtilities::GetTotalLookAheadDelayLength(
                                                &this->mLimiterUtilities,
                                                (double)(int)this->mSampleRate);
  this->LimiterMemMapPtr->XMemory[18] = 1378.0;
  this->LimiterMemMapPtr->XMemory[19] = (float)LimiterUtilities::GetFIRLength(
                                                 &this->mLimiterUtilities,
                                                 (double)(int)this->mSampleRate);
  FIRLength = LimiterUtilities::GetFIRLength(&this->mLimiterUtilities, (double)(int)this->mSampleRate);
  v3 = &this->LimiterMemMapPtr->XMemory[1378];
  if ( FIRLength > 0 )
  {
    v4 = (unsigned int)FIRLength;
    v5 = 1.0 / (float)FIRLength;
    while ( v4 )
    {
      *v3++ = v5;
      --v4;
    }
  }
}

// File Line: 1454
// RVA: 0xB019C0
int __fastcall LimiterDSPSurround71MemoryMapHelper::GetTotalLookAheadDelayLength(
        LimiterDSPSurround71MemoryMapHelper *this,
        unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(&this->mLimiterUtilities, (double)(int)this->mSampleRate);
}

// File Line: 1461
// RVA: 0xB01A00
void __fastcall LimiterDSPSurround71MemoryMapHelper::FillMeteringData(
        LimiterDSPSurround71MemoryMapHelper *this,
        float *pMeteringData)
{
  McDSPFillVUMetersDataSurround71(this->LimiterMemMapPtr->XMemory, pMeteringData);
}

// File Line: 1472
// RVA: 0xB013C0
void __fastcall LimiterProcessSurround71FloatImpl::LimiterProcessSurround71FloatImpl(
        LimiterProcessSurround71FloatImpl *this)
{
  this->mMemoryMapHelper = 0i64;
}

// File Line: 1478
// RVA: 0xB013E0
void __fastcall LimiterProcessSurround71FloatImpl::~LimiterProcessSurround71FloatImpl(
        LimiterProcessSurround71FloatImpl *this)
{
  ;
}

// File Line: 1484
// RVA: 0xB013F0
unsigned __int64 __fastcall LimiterProcessSurround71FloatImpl::GetMemoryMapSize(
        LimiterProcessSurround71FloatImpl *this)
{
  return 11416i64;
}

// File Line: 1494
// RVA: 0xB01400
__int64 __fastcall LimiterProcessSurround71FloatImpl::Init(
        LimiterProcessSurround71FloatImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int sampleRate)
{
  DSPMemoryMapHelper *v7; // rax
  LimiterDSPSurround71MemoryMapHelper *v8; // rbx
  char *v9; // rax

  v7 = (DSPMemoryMapHelper *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24i64);
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
  this->mMemoryMapHelper = v8;
  if ( !v8 )
    return 52i64;
  v8->mNumChannels = 8;
  v8->mSampleRate = sampleRate;
  v9 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x2C98ui64);
  v8->LimiterMemMapPtr = (LimiterSurround71MemoryMap *)v9;
  if ( !v9 )
    return 52i64;
  *((_DWORD *)v9 + 11) = 1065353216;
  v8->LimiterMemMapPtr->XMemory[10] = 1227.0;
  return 1i64;
}

// File Line: 1505
// RVA: 0xB014C0
void __fastcall LimiterProcessSurround71FloatImpl::Term(
        LimiterProcessSurround71FloatImpl *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterDSPSurround71MemoryMapHelper *mMemoryMapHelper; // rdi

  mMemoryMapHelper = this->mMemoryMapHelper;
  if ( this->mMemoryMapHelper )
  {
    LimiterUtilities::~LimiterUtilities(&mMemoryMapHelper->mLimiterUtilities);
    DSPMemoryMapHelper::~DSPMemoryMapHelper(mMemoryMapHelper);
    in_pAllocator->vfptr->Free(in_pAllocator, mMemoryMapHelper);
    this->mMemoryMapHelper = 0i64;
  }
  else
  {
    this->mMemoryMapHelper = 0i64;
  }
}

// File Line: 1513
// RVA: 0xB01530
void __fastcall LimiterProcessSurround71FloatImpl::SetParameters(
        LimiterProcessSurround71FloatImpl *this,
        LimiterParameters *limiterParams)
{
  long double v4; // xmm6_8
  LimiterDSPSurround71MemoryMapHelper *mMemoryMapHelper; // rbx
  int LookAheadDelayLength; // eax
  long double TCScalar; // xmm0_8
  LimiterDSPSurround71MemoryMapHelper *v8; // rcx
  float v9; // xmm1_4
  LimiterDSPSurround71MemoryMapHelper *v10; // rbx
  int TotalLookAheadDelayLength; // eax
  LimiterDSPSurround71MemoryMapHelper *v12; // rcx

  v4 = limiterParams->threshold - 12.0;
  if ( v4 < -36.0 )
    v4 = DOUBLE_N36_0;
  LimiterDSPSurround71MemoryMapHelper::SetCeiling(this->mMemoryMapHelper, limiterParams->ceiling, v4);
  LimiterDSPSurround71MemoryMapHelper::SetCeiling(this->mMemoryMapHelper, limiterParams->ceiling, v4);
  LimiterUtilities::GenerateExpTable(
    &this->mMemoryMapHelper->LimiterMemMapPtr->YMemory[23],
    600,
    v4,
    limiterParams->knee);
  mMemoryMapHelper = this->mMemoryMapHelper;
  LookAheadDelayLength = LimiterUtilities::GetLookAheadDelayLength(
                           &this->mMemoryMapHelper->mLimiterUtilities,
                           (double)this->mMemoryMapHelper->mSampleRate);
  TCScalar = GetTCScalar((double)LookAheadDelayLength);
  v8 = this->mMemoryMapHelper;
  v9 = TCScalar;
  mMemoryMapHelper->LimiterMemMapPtr->XMemory[15] = v9;
  LimiterDSPSurround71MemoryMapHelper::SetRelease(v8, limiterParams->release, limiterParams->character);
  LimiterDSPSurround71MemoryMapHelper::SetCharacter(
    this->mMemoryMapHelper,
    limiterParams->character,
    limiterParams->release);
  v10 = this->mMemoryMapHelper;
  TotalLookAheadDelayLength = LimiterUtilities::GetTotalLookAheadDelayLength(
                                &this->mMemoryMapHelper->mLimiterUtilities,
                                (double)this->mMemoryMapHelper->mSampleRate);
  v12 = this->mMemoryMapHelper;
  v10->LimiterMemMapPtr->XMemory[13] = (float)(TotalLookAheadDelayLength + 1);
  LimiterDSPSurround71MemoryMapHelper::SetLookAhead(v12);
}

// File Line: 1566
// RVA: 0xB01650
void __fastcall LimiterProcessSurround71FloatImpl::ProcessAudio(
        LimiterProcessSurround71FloatImpl *this,
        char *memoryMap,
        AkAudioBuffer *inputBuffer,
        AkAudioBuffer *outputBuffer)
{
  float *outputBuf_L; // r10
  __int64 uMaxFrames; // rcx
  __int64 v6; // r9

  outputBuf_L = (float *)outputBuffer->pData;
  uMaxFrames = outputBuffer->uMaxFrames;
  v6 = inputBuffer->uMaxFrames;
  McDSPLimiterProcessChannels(
    memoryMap,
    (const float *)inputBuffer->pData,
    (const float *)inputBuffer->pData + 2 * v6,
    (const float *)inputBuffer->pData + v6,
    (const float *)inputBuffer->pData + 3 * v6,
    (float *)inputBuffer->pData + 4 * v6,
    (const float *)inputBuffer->pData + 5 * v6,
    (float *)inputBuffer->pData + 6 * v6,
    (const float *)inputBuffer->pData + 7 * v6,
    outputBuf_L,
    &outputBuf_L[2 * uMaxFrames],
    &outputBuf_L[uMaxFrames],
    &outputBuf_L[3 * uMaxFrames],
    &outputBuf_L[4 * (unsigned int)uMaxFrames],
    &outputBuf_L[5 * uMaxFrames],
    &outputBuf_L[6 * uMaxFrames],
    &outputBuf_L[7 * (unsigned int)uMaxFrames],
    inputBuffer->uValidFrames);
}

// File Line: 1596
// RVA: 0xB017B0
int __fastcall LimiterProcessSurround71FloatImpl::GetNumTailFrames(
        LimiterProcessSurround71FloatImpl *this,
        unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(
           &this->mMemoryMapHelper->mLimiterUtilities,
           (double)this->mMemoryMapHelper->mSampleRate);
}

// File Line: 1601
// RVA: 0xB017D0
void __fastcall LimiterProcessSurround71FloatImpl::FillMeteringData(
        LimiterProcessSurround71FloatImpl *this,
        char *pMeteringData)
{
  McDSPFillVUMetersDataSurround71(this->mMemoryMapHelper->LimiterMemMapPtr, pMeteringData);
}

