// File Line: 214
// RVA: 0xAFED40
void __fastcall McDSPLimiterProcessChannels(
        char *memoryMap,
        const float *inputBuf_L,
        const float *inputBuf_C,
        const float *inputBuf_R,
        const float *inputBuf_Ls,
        float *inputBuf_Rs,
        const float *inputBuf_LFE,
        float *outputBuf_L,
        float *outputBuf_C,
        float *outputBuf_R,
        float *outputBuf_Ls,
        float *outputBuf_Rs,
        float *outputBuf_LFE,
        unsigned int samplesRemaining)
{
  int v14; // edi
  int v15; // r13d
  float *v17; // r10
  __int64 v19; // r14
  int v20; // ecx
  int v21; // r15d
  int v22; // eax
  int v23; // r11d
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // r12d
  float v27; // xmm9_4
  float *v28; // r9
  float v29; // xmm1_4
  float v30; // xmm0_4
  _DWORD *v31; // r10
  float v32; // xmm1_4
  float v33; // xmm0_4
  float *v34; // rax
  float v35; // xmm1_4
  float v36; // xmm0_4
  int v37; // edx
  __int64 v38; // r8
  float v39; // xmm4_4
  __int64 v40; // rax
  int v41; // xmm2_4
  int v42; // xmm1_4
  int v43; // ecx
  int v44; // xmm2_4
  int v45; // xmm1_4
  __int64 v46; // rcx
  int v47; // xmm1_4
  int v48; // xmm0_4
  int v49; // xmm4_4
  int v50; // xmm2_4
  int v51; // xmm2_4
  char *v52; // rcx
  int v53; // r11d
  unsigned int v54; // eax
  __int64 v55; // r8
  __int64 v56; // r8
  float v57; // xmm4_4
  float v58; // xmm6_4
  float v59; // xmm5_4
  float v60; // xmm5_4
  float v61; // xmm5_4
  float v62; // xmm0_4
  float v63; // xmm5_4
  float v64; // xmm2_4
  float v65; // xmm4_4
  int v66; // xmm0_4
  int v67; // xmm5_4
  int v68; // xmm4_4
  int v69; // xmm0_4
  float v70; // xmm5_4
  float v71; // xmm0_4
  float v72; // xmm2_4
  float v73; // xmm0_4
  __int64 v74; // rax
  __int64 v75; // rcx
  __int64 v76; // r8
  float v77; // xmm4_4
  __int64 v78; // rax
  float v79; // xmm5_4
  int v80; // r10d
  float v81; // xmm0_4
  __int64 v82; // rax
  float *v83; // rcx
  unsigned int v84; // eax
  __int64 v85; // r8
  float *v86; // rcx
  __int64 v87; // r8
  float v88; // xmm2_4
  float v89; // xmm4_4
  float v90; // xmm6_4
  int v91; // xmm5_4
  float v92; // xmm2_4
  float v93; // xmm4_4
  float v94; // xmm2_4
  float *v95; // rax
  int v96; // xmm4_4
  float v97; // xmm2_4
  float v98; // xmm4_4
  float v99; // xmm2_4
  float *v100; // rax
  int v101; // xmm4_4
  float v102; // xmm2_4
  float v103; // xmm4_4
  float v104; // xmm2_4
  float *v105; // rax
  int v106; // xmm4_4
  float v107; // xmm2_4
  float v108; // xmm4_4
  float v109; // xmm2_4
  float *v110; // rax
  int v111; // xmm4_4
  float v112; // xmm2_4
  float v113; // xmm4_4
  float v114; // xmm2_4
  float *v115; // rax
  int v116; // xmm4_4
  float v117; // xmm2_4
  float v118; // xmm4_4
  float v119; // xmm2_4
  int v120; // [rsp+0h] [rbp-E8h]
  int v121; // [rsp+4h] [rbp-E4h]
  int v122; // [rsp+8h] [rbp-E0h]
  int v123; // [rsp+Ch] [rbp-DCh]
  __int64 v124; // [rsp+10h] [rbp-D8h]
  __int64 v125; // [rsp+18h] [rbp-D0h]
  __int64 v126; // [rsp+20h] [rbp-C8h]
  __int64 v127; // [rsp+28h] [rbp-C0h]
  __int64 v128; // [rsp+38h] [rbp-B0h]
  int v129; // [rsp+F0h] [rbp+8h]
  const float *v130; // [rsp+F8h] [rbp+10h]
  const float *v131; // [rsp+100h] [rbp+18h]
  unsigned int samplesRemaininga; // [rsp+158h] [rbp+70h]

  v14 = (int)*((float *)memoryMap + 1278);
  v15 = (int)*((float *)memoryMap + 6);
  v17 = (float *)(memoryMap + 24);
  v19 = v14;
  v20 = (int)*((float *)memoryMap + 7);
  v21 = (int)*((float *)memoryMap + 1286);
  v22 = (int)*((float *)memoryMap + 11);
  *(_QWORD *)(memoryMap + 76) = 0i64;
  *(_QWORD *)(memoryMap + 108) = 0i64;
  *(_QWORD *)(memoryMap + 92) = 0i64;
  v121 = v20;
  v123 = v22;
  v126 = v20;
  *(_QWORD *)(memoryMap + 124) = 0i64;
  *(_QWORD *)(memoryMap + 140) = 0i64;
  *(_QWORD *)(memoryMap + 156) = 0i64;
  *((_DWORD *)memoryMap + 43) = 0;
  v23 = (int)*((float *)memoryMap + 18);
  v24 = (int)*((float *)memoryMap + 16);
  v122 = (int)*((float *)memoryMap + 8);
  v129 = v23;
  v125 = v24;
  v124 = v23;
  v25 = samplesRemaining;
  v26 = (int)*((float *)memoryMap + 17);
  if ( samplesRemaining )
  {
    v127 = v24 + 1;
    v27 = kHeadRoomScaleFactor_1;
    do
    {
      v28 = v17;
      samplesRemaininga = v25 - 1;
      v130 = inputBuf_L + 1;
      v131 = inputBuf_C + 1;
      v29 = v27 * *inputBuf_L;
      v30 = v27 * *inputBuf_C;
      if ( v29 < 1.0 )
      {
        if ( v29 <= -1.0 )
          v29 = FLOAT_N1_0;
      }
      else
      {
        v29 = *(float *)&FLOAT_1_0;
      }
      if ( v30 < 1.0 )
      {
        if ( v30 <= -1.0 )
          v30 = FLOAT_N1_0;
      }
      else
      {
        v30 = *(float *)&FLOAT_1_0;
      }
      *((float *)memoryMap + 1272) = v29;
      v31 = memoryMap + 5092;
      ++inputBuf_Ls;
      *((float *)memoryMap + 1273) = v30;
      v32 = v27 * *inputBuf_R;
      v33 = v27 * *(inputBuf_Ls - 1);
      if ( v32 < 1.0 )
      {
        if ( v32 <= -1.0 )
          v32 = FLOAT_N1_0;
      }
      else
      {
        v32 = *(float *)&FLOAT_1_0;
      }
      if ( v33 < 1.0 )
      {
        if ( v33 <= -1.0 )
          v33 = FLOAT_N1_0;
      }
      else
      {
        v33 = *(float *)&FLOAT_1_0;
      }
      v34 = inputBuf_Rs;
      *((float *)memoryMap + 1274) = v32;
      *((float *)memoryMap + 1275) = v33;
      ++inputBuf_Rs;
      v35 = v27 * *v34;
      v36 = v27 * *inputBuf_LFE++;
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
      *((float *)memoryMap + 1276) = v35;
      v37 = v14 + 1;
      *((float *)memoryMap + 1277) = v36;
      v38 = v19 + 1;
      v39 = *v28;
      if ( v14 + 1 >= v15 )
      {
        v37 = 0;
        v38 = 0i64;
      }
      v40 = v19 + v126;
      v41 = *(_DWORD *)&memoryMap[4 * v19 + 4 * v126];
      *(_DWORD *)&memoryMap[4 * v40] = *((_DWORD *)memoryMap + 1272);
      v42 = *(_DWORD *)&memoryMap[4 * v19 + 5088 + 4 * v126];
      v120 = v37;
      v128 = v38;
      *(_DWORD *)&memoryMap[4 * v40 + 5088] = *v31;
      *((_DWORD *)memoryMap + 1279) = v41;
      *((_DWORD *)memoryMap + 1280) = v42;
      v43 = (int)v39 + v14 + v121 + 1;
      v44 = *(_DWORD *)&memoryMap[4 * v43];
      *(_DWORD *)&memoryMap[4 * v43] = *((_DWORD *)memoryMap + 1274);
      v45 = *(_DWORD *)&memoryMap[4 * v43 + 5088];
      *(_DWORD *)&memoryMap[4 * v43 + 5088] = *((_DWORD *)memoryMap + 1275);
      *((_DWORD *)memoryMap + 1281) = v44;
      *((_DWORD *)memoryMap + 1282) = v45;
      v46 = (int)v39 + v43 + 1;
      v47 = *(_DWORD *)&memoryMap[4 * v46];
      *(_DWORD *)&memoryMap[4 * v46] = *((_DWORD *)memoryMap + 1276);
      v48 = *(_DWORD *)&memoryMap[4 * v46 + 5088];
      *(_DWORD *)&memoryMap[4 * v46 + 5088] = *((_DWORD *)memoryMap + 1277);
      *((_DWORD *)memoryMap + 1283) = v47;
      *((_DWORD *)memoryMap + 1284) = v48;
      v49 = *v31;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1272) & _xmm) > COERCE_FLOAT(*v31 & _xmm) )
        v49 = *((_DWORD *)memoryMap + 1272);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1274) & _xmm) > COERCE_FLOAT(v49 & _xmm) )
        v49 = *((_DWORD *)memoryMap + 1274);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1275) & _xmm) > COERCE_FLOAT(v49 & _xmm) )
        v49 = *((_DWORD *)memoryMap + 1275);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1276) & _xmm) > COERCE_FLOAT(v49 & _xmm) )
        v49 = *((_DWORD *)memoryMap + 1276);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1277) & _xmm) > COERCE_FLOAT(v49 & _xmm) )
        v49 = *((_DWORD *)memoryMap + 1277);
      v50 = *((_DWORD *)memoryMap + 1280);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1279) & _xmm) > COERCE_FLOAT(v50 & _xmm) )
        v50 = *((_DWORD *)memoryMap + 1279);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1281) & _xmm) > COERCE_FLOAT(v50 & _xmm) )
        v50 = *((_DWORD *)memoryMap + 1281);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1282) & _xmm) > COERCE_FLOAT(v50 & _xmm) )
        v50 = *((_DWORD *)memoryMap + 1282);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1283) & _xmm) > COERCE_FLOAT(v50 & _xmm) )
        v50 = *((_DWORD *)memoryMap + 1283);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1284) & _xmm) > COERCE_FLOAT(v50 & _xmm) )
        v50 = *((_DWORD *)memoryMap + 1284);
      *((_DWORD *)memoryMap + 1285) = v50;
      *(_DWORD *)&memoryMap[4 * v19 + 5088 + 4 * v122] = v49;
      v51 = 0;
      v52 = &memoryMap[4 * v122 + 5088];
      v53 = 0;
      if ( v15 >= 4 )
      {
        v54 = ((unsigned int)(v15 - 4) >> 2) + 1;
        v55 = v54;
        v53 = 4 * v54;
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v52 & _xmm) > COERCE_FLOAT(v51 & _xmm) )
            v51 = *(_DWORD *)v52;
          if ( COERCE_FLOAT(*((_DWORD *)v52 + 1) & _xmm) > COERCE_FLOAT(v51 & _xmm) )
            v51 = *((_DWORD *)v52 + 1);
          if ( COERCE_FLOAT(*((_DWORD *)v52 + 2) & _xmm) > COERCE_FLOAT(v51 & _xmm) )
            v51 = *((_DWORD *)v52 + 2);
          if ( COERCE_FLOAT(*((_DWORD *)v52 + 3) & _xmm) > COERCE_FLOAT(v51 & _xmm) )
            v51 = *((_DWORD *)v52 + 3);
          v52 += 16;
          --v55;
        }
        while ( v55 );
      }
      if ( v53 < v15 )
      {
        v56 = (unsigned int)(v15 - v53);
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v52 & _xmm) > COERCE_FLOAT(v51 & _xmm) )
            v51 = *(_DWORD *)v52;
          v52 += 4;
          --v56;
        }
        while ( v56 );
      }
      LODWORD(v57) = *((_DWORD *)memoryMap + 1272) & _xmm;
      v58 = v28[4];
      if ( COERCE_FLOAT(*v31 & _xmm) > v57 )
        LODWORD(v57) = *v31 & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1274) & _xmm) > v57 )
        LODWORD(v57) = *((_DWORD *)memoryMap + 1274) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1275) & _xmm) > v57 )
        LODWORD(v57) = *((_DWORD *)memoryMap + 1275) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1276) & _xmm) > v57 )
        LODWORD(v57) = *((_DWORD *)memoryMap + 1276) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1277) & _xmm) > v57 )
        LODWORD(v57) = *((_DWORD *)memoryMap + 1277) & _xmm;
      if ( v57 >= 1.0 )
        v57 = *(float *)&FLOAT_1_0;
      if ( COERCE_FLOAT((_DWORD)v28[3] & _xmm) <= COERCE_FLOAT(LODWORD(v57) & _xmm) )
        v57 = v28[3];
      v59 = *((float *)memoryMap + 1287);
      if ( COERCE_FLOAT(LODWORD(v57) & _xmm) > COERCE_FLOAT(LODWORD(v59) & _xmm) )
      {
        v21 = v123;
        v59 = v57;
      }
      LODWORD(v60) = LODWORD(v59) & _xmm;
      *((float *)memoryMap + 1287) = v60;
      v61 = v60 - v58;
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1288) & _xmm) > COERCE_FLOAT(LODWORD(v61) & _xmm) )
        v61 = *((float *)memoryMap + 1288);
      *((float *)memoryMap + 1288) = v61;
      v62 = v28[7];
      --v21;
      v63 = 0.0;
      if ( v21 < 0 )
        v21 = 0;
      if ( v21 <= 0 )
      {
        v63 = v28[6];
        v62 = 0.0;
      }
      LODWORD(v64) = v51 & _xmm;
      v65 = (float)((float)(*((float *)memoryMap + 1288) * v62) + v28[4]) + (float)((float)(v64 - v28[4]) * v63);
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1287) & _xmm) <= COERCE_FLOAT(LODWORD(v65) & _xmm) )
        v65 = *((float *)memoryMap + 1287);
      v66 = *((_DWORD *)memoryMap + 1288);
      if ( v21 <= 0 )
        v66 = 0;
      *((_DWORD *)memoryMap + 1288) = v66;
      v67 = *((_DWORD *)memoryMap + 1285);
      if ( COERCE_FLOAT(v67 & _xmm) > COERCE_FLOAT(LODWORD(v65) & _xmm) )
        v65 = *((float *)memoryMap + 1285);
      v68 = LODWORD(v65) & _xmm;
      *((_DWORD *)v28 + 4) = v68;
      v69 = *((_DWORD *)memoryMap + 1287);
      if ( COERCE_FLOAT(v67 & _xmm) > COERCE_FLOAT(v68 & _xmm) )
        v69 = v67;
      *((_DWORD *)memoryMap + 1287) = v69 & _xmm;
      v70 = v28[8];
      if ( COERCE_FLOAT(*((_DWORD *)memoryMap + 1289) & _xmm) < COERCE_FLOAT(LODWORD(v64) & _xmm) )
        v70 = v28[9];
      v71 = v28[4];
      v72 = (float)((float)(v64 - *((float *)memoryMap + 1289)) * v70) + *((float *)memoryMap + 1289);
      *((float *)memoryMap + 1289) = v72;
      if ( v71 > v72 )
        v72 = v71;
      v28[4] = v72;
      v73 = *((float *)memoryMap + 1287);
      if ( v21 <= 0 )
        v73 = v72;
      v74 = v124;
      *((float *)memoryMap + 1287) = v73;
      v23 = v129 + 1;
      v75 = v124 + 1;
      v76 = v124;
      ++v129;
      if ( v124 + 1 >= v26 )
      {
        v23 = 0;
        v129 = 0;
        v75 = 0i64;
      }
      v124 = v75;
      v77 = 0.0;
      v78 = v125 + v74;
      *(float *)&memoryMap[4 * v78 + 5088] = v72;
      v79 = *(float *)&memoryMap[4 * v125];
      v80 = 0;
      v81 = *(float *)&memoryMap[4 * (v78 - v76) + 5088];
      v82 = v127;
      if ( v26 >= 4 )
      {
        v83 = (float *)&memoryMap[4 * v127 + 5096];
        v84 = ((unsigned int)(v26 - 4) >> 2) + 1;
        v85 = v84;
        v80 = 4 * v84;
        v82 = v127 + 4i64 * v84;
        do
        {
          v83 += 4;
          v77 = (float)((float)((float)(v77 + (float)(v81 * v79)) + (float)(v79 * *(v83 - 6)))
                      + (float)(v79 * *(v83 - 5)))
              + (float)(v79 * *(v83 - 4));
          v81 = *(v83 - 3);
          --v85;
        }
        while ( v85 );
      }
      if ( v80 < v26 )
      {
        v86 = (float *)&memoryMap[4 * v82 + 5088];
        v87 = (unsigned int)(v26 - v80);
        do
        {
          ++v86;
          v77 = v77 + (float)(v81 * v79);
          v81 = *(v86 - 1);
          --v87;
        }
        while ( v87 );
      }
      v88 = (float)((float)((float)((float)(v77 * 2.0) - (float)(v77 * v77)) * 2.0)
                  - (float)((float)((float)(v77 * 2.0) - (float)(v77 * v77))
                          * (float)((float)(v77 * 2.0) - (float)(v77 * v77))))
          * 599.0;
      v89 = (float)((float)(*(float *)&memoryMap[4 * (int)v88 + 5168] - *(float *)&memoryMap[4 * (int)v88 + 5164])
                  * (float)(v88 - (float)(int)v88))
          + *(float *)&memoryMap[4 * (int)v88 + 5164];
      v90 = v89;
      if ( COERCE_FLOAT((_DWORD)v28[13] & _xmm) > COERCE_FLOAT(LODWORD(v89) & _xmm) )
        v89 = v28[13];
      v28[13] = v89;
      v91 = *((_DWORD *)v28 + 14);
      v92 = *((float *)memoryMap + 1279);
      if ( COERCE_FLOAT(LODWORD(v92) & _xmm) > COERCE_FLOAT(v91 & _xmm) )
        v91 = *((_DWORD *)memoryMap + 1279);
      *((_DWORD *)v28 + 14) = v91;
      v93 = v28[17];
      v94 = (float)(v92 * v90) * v28[15];
      if ( COERCE_FLOAT(LODWORD(v94) & _xmm) > COERCE_FLOAT(LODWORD(v93) & _xmm) )
        v93 = v94;
      v95 = outputBuf_L;
      v28[17] = v93;
      ++outputBuf_L;
      *v95 = v94;
      v96 = *((_DWORD *)v28 + 18);
      v97 = *((float *)memoryMap + 1280);
      if ( COERCE_FLOAT(LODWORD(v97) & _xmm) > COERCE_FLOAT(v96 & _xmm) )
        v96 = *((_DWORD *)memoryMap + 1280);
      *((_DWORD *)v28 + 18) = v96;
      v98 = v28[21];
      v99 = (float)(v97 * v90) * v28[19];
      if ( COERCE_FLOAT(LODWORD(v99) & _xmm) > COERCE_FLOAT(LODWORD(v98) & _xmm) )
        v98 = v99;
      v100 = outputBuf_C;
      v28[21] = v98;
      ++outputBuf_C;
      *v100 = v99;
      v101 = *((_DWORD *)v28 + 22);
      v102 = *((float *)memoryMap + 1281);
      if ( COERCE_FLOAT(LODWORD(v102) & _xmm) > COERCE_FLOAT(v101 & _xmm) )
        v101 = *((_DWORD *)memoryMap + 1281);
      *((_DWORD *)v28 + 22) = v101;
      v103 = v28[25];
      v104 = (float)(v102 * v90) * v28[23];
      if ( COERCE_FLOAT(LODWORD(v104) & _xmm) > COERCE_FLOAT(LODWORD(v103) & _xmm) )
        v103 = v104;
      v105 = outputBuf_R;
      v28[25] = v103;
      ++outputBuf_R;
      *v105 = v104;
      v106 = *((_DWORD *)v28 + 26);
      v107 = *((float *)memoryMap + 1282);
      if ( COERCE_FLOAT(LODWORD(v107) & _xmm) > COERCE_FLOAT(v106 & _xmm) )
        v106 = *((_DWORD *)memoryMap + 1282);
      *((_DWORD *)v28 + 26) = v106;
      v108 = v28[29];
      v109 = (float)(v107 * v90) * v28[27];
      if ( COERCE_FLOAT(LODWORD(v109) & _xmm) > COERCE_FLOAT(LODWORD(v108) & _xmm) )
        v108 = v109;
      v110 = outputBuf_Ls;
      v28[29] = v108;
      ++outputBuf_Ls;
      *v110 = v109;
      v111 = *((_DWORD *)v28 + 30);
      v112 = *((float *)memoryMap + 1283);
      if ( COERCE_FLOAT(LODWORD(v112) & _xmm) > COERCE_FLOAT(v111 & _xmm) )
        v111 = *((_DWORD *)memoryMap + 1283);
      *((_DWORD *)v28 + 30) = v111;
      v113 = v28[33];
      v114 = (float)(v112 * v90) * v28[31];
      if ( COERCE_FLOAT(LODWORD(v114) & _xmm) > COERCE_FLOAT(LODWORD(v113) & _xmm) )
        v113 = v114;
      v115 = outputBuf_Rs;
      v28[33] = v113;
      ++outputBuf_Rs;
      *v115 = v114;
      v116 = *((_DWORD *)v28 + 34);
      v117 = *((float *)memoryMap + 1284);
      if ( COERCE_FLOAT(LODWORD(v117) & _xmm) > COERCE_FLOAT(v116 & _xmm) )
        v116 = *((_DWORD *)memoryMap + 1284);
      *((_DWORD *)v28 + 34) = v116;
      v118 = v28[37];
      v119 = (float)(v117 * v90) * v28[35];
      if ( COERCE_FLOAT(LODWORD(v119) & _xmm) > COERCE_FLOAT(LODWORD(v118) & _xmm) )
        v118 = v119;
      v25 = samplesRemaininga;
      inputBuf_C = v131;
      v28[37] = v118;
      inputBuf_L = v130;
      v14 = v120;
      ++inputBuf_R;
      *outputBuf_LFE = v119;
      v19 = v128;
      v17 = (float *)(memoryMap + 24);
      ++outputBuf_LFE;
    }
    while ( samplesRemaininga );
  }
  *((float *)memoryMap + 1286) = (float)v21;
  *((float *)memoryMap + 1278) = (float)v14;
  *((float *)memoryMap + 18) = (float)v23;
}

// File Line: 1009
// RVA: 0xAFF910
void __fastcall McDSPFillVUMetersDataSurround(float *memoryMap, float *pMeteringData)
{
  *(_DWORD *)pMeteringData = 63;
  pMeteringData[1] = memoryMap[19];
  pMeteringData[2] = memoryMap[20] * 3.9810717;
  pMeteringData[3] = memoryMap[28] * 3.9810717;
  pMeteringData[4] = memoryMap[24] * 3.9810717;
  pMeteringData[5] = memoryMap[32] * 3.9810717;
  pMeteringData[6] = memoryMap[36] * 3.9810717;
  pMeteringData[7] = memoryMap[40] * 3.9810717;
  pMeteringData[8] = memoryMap[23];
  pMeteringData[9] = memoryMap[31];
  pMeteringData[10] = memoryMap[27];
  pMeteringData[11] = memoryMap[35];
  pMeteringData[12] = memoryMap[39];
  pMeteringData[13] = memoryMap[43];
}

// File Line: 1089
// RVA: 0xAFFEA0
void __fastcall LimiterDSPSurroundMemoryMapHelper::LimiterDSPSurroundMemoryMapHelper(
        LimiterDSPSurroundMemoryMapHelper *this,
        int sampleRate)
{
  DSPMemoryMapHelper::DSPMemoryMapHelper(this);
  LimiterUtilities::LimiterUtilities(&this->mLimiterUtilities, 0.00085000001, 0.000325);
}

// File Line: 1095
// RVA: 0xAFFEE0
void __fastcall LimiterDSPSurroundMemoryMapHelper::~LimiterDSPSurroundMemoryMapHelper(
        LimiterDSPSurroundMemoryMapHelper *this)
{
  LimiterUtilities::~LimiterUtilities(&this->mLimiterUtilities);
  DSPMemoryMapHelper::~DSPMemoryMapHelper(this);
}

// File Line: 1100
// RVA: 0xAFFF10
unsigned __int64 __fastcall LimiterDSPSurroundMemoryMapHelper::GetMemoryMapSize(
        LimiterDSPSurroundMemoryMapHelper *this)
{
  return 10176i64;
}

// File Line: 1108
// RVA: 0xAFFF20
__int64 __fastcall LimiterDSPSurroundMemoryMapHelper::Init(
        LimiterDSPSurroundMemoryMapHelper *this,
        PooledMemoryAllocator *memoryMapAllocator,
        unsigned int sampleRate)
{
  char *v4; // rax

  this->mNumChannels = 6;
  this->mSampleRate = sampleRate;
  v4 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x27C0ui64);
  this->LimiterMemMapPtr = (LimiterSurroundMemoryMap *)v4;
  if ( !v4 )
    return 52i64;
  *((_DWORD *)v4 + 9) = 1065353216;
  this->LimiterMemMapPtr->XMemory[8] = 1072.0;
  return 1i64;
}

// File Line: 1132
// RVA: 0xAFFF80
LimiterSurroundMemoryMap *__fastcall LimiterDSPSurroundMemoryMapHelper::GetMemoryMap(
        LimiterDSPSurroundMemoryMapHelper *this)
{
  return this->LimiterMemMapPtr;
}

// File Line: 1139
// RVA: 0xB00090
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetCeiling(
        LimiterDSPSurroundMemoryMapHelper *this,
        long double ceiling,
        double threshold)
{
  double v4; // xmm0_8
  LimiterSurroundMemoryMap *LimiterMemMapPtr; // rax
  float v6; // xmm1_4

  if ( threshold < 0.0 )
    ceiling = ceiling + -0.01;
  v4 = pow(10.0, ceiling * 0.05);
  LimiterMemMapPtr = this->LimiterMemMapPtr;
  v6 = v4;
  LimiterMemMapPtr->XMemory[41] = v6;
  LimiterMemMapPtr->XMemory[37] = v6;
  LimiterMemMapPtr->XMemory[33] = v6;
  LimiterMemMapPtr->XMemory[29] = v6;
  LimiterMemMapPtr->XMemory[25] = v6;
  LimiterMemMapPtr->XMemory[21] = v6;
}

// File Line: 1160
// RVA: 0xB00100
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetThreshold(
        LimiterDSPSurroundMemoryMapHelper *this,
        double threshold,
        long double knee,
        long double ceiling)
{
  double v5; // xmm0_8
  LimiterSurroundMemoryMap *LimiterMemMapPtr; // rax
  float v7; // xmm1_4

  if ( threshold < 0.0 )
    ceiling = ceiling - 0.01;
  v5 = pow(10.0, ceiling * 0.05);
  LimiterMemMapPtr = this->LimiterMemMapPtr;
  v7 = v5;
  LimiterMemMapPtr->XMemory[41] = v7;
  LimiterMemMapPtr->XMemory[37] = v7;
  LimiterMemMapPtr->XMemory[33] = v7;
  LimiterMemMapPtr->XMemory[29] = v7;
  LimiterMemMapPtr->XMemory[25] = v7;
  LimiterMemMapPtr->XMemory[21] = v7;
}

// File Line: 1170
// RVA: 0xB00170
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetKnee(
        LimiterDSPSurroundMemoryMapHelper *this,
        long double knee,
        long double threshold)
{
  ;
}

// File Line: 1180
// RVA: 0xAFFFB0
void __fastcall LimiterDSPSurroundMemoryMapHelper::GenerateExpTable(
        LimiterDSPSurroundMemoryMapHelper *this,
        long double knee,
        long double threshold)
{
  LimiterUtilities::GenerateExpTable(&this->LimiterMemMapPtr->YMemory[19], 600, threshold, knee);
}

// File Line: 1188
// RVA: 0xB00180
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetRelease(
        LimiterDSPSurroundMemoryMapHelper *this,
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
  this->LimiterMemMapPtr->XMemory[12] = v7;
}

// File Line: 1213
// RVA: 0xB00250
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetCharacter(
        LimiterDSPSurroundMemoryMapHelper *this,
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
  this->LimiterMemMapPtr->XMemory[15] = v8;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v9 = DynamicsCalculator::CalculateReleaseScalar(this->mSampleRate, v5 + v7);
  this->LimiterMemMapPtr->XMemory[14] = v9;
}

// File Line: 1246
// RVA: 0xB003C0
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetAttack(LimiterDSPSurroundMemoryMapHelper *this)
{
  int LookAheadDelayLength; // eax
  float TCScalar; // xmm1_4

  LookAheadDelayLength = LimiterUtilities::GetLookAheadDelayLength(
                           &this->mLimiterUtilities,
                           (double)(int)this->mSampleRate);
  TCScalar = GetTCScalar((double)LookAheadDelayLength);
  this->LimiterMemMapPtr->XMemory[13] = TCScalar;
}

// File Line: 1258
// RVA: 0xB00410
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetHold(LimiterDSPSurroundMemoryMapHelper *this)
{
  this->LimiterMemMapPtr->XMemory[11] = (float)(LimiterUtilities::GetTotalLookAheadDelayLength(
                                                  &this->mLimiterUtilities,
                                                  (double)(int)this->mSampleRate)
                                              + 1);
}

// File Line: 1272
// RVA: 0xB00450
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetLookAhead(LimiterDSPSurroundMemoryMapHelper *this)
{
  int FIRLength; // eax
  float *v3; // rdi
  __int64 v4; // rcx
  float v5; // eax

  this->LimiterMemMapPtr->XMemory[7] = 619.0;
  this->LimiterMemMapPtr->XMemory[6] = (float)LimiterUtilities::GetTotalLookAheadDelayLength(
                                                &this->mLimiterUtilities,
                                                (double)(int)this->mSampleRate);
  this->LimiterMemMapPtr->XMemory[16] = 1223.0;
  this->LimiterMemMapPtr->XMemory[17] = (float)LimiterUtilities::GetFIRLength(
                                                 &this->mLimiterUtilities,
                                                 (double)(int)this->mSampleRate);
  FIRLength = LimiterUtilities::GetFIRLength(&this->mLimiterUtilities, (double)(int)this->mSampleRate);
  v3 = &this->LimiterMemMapPtr->XMemory[1223];
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

// File Line: 1297
// RVA: 0xAFFF90
int __fastcall LimiterDSPSurroundMemoryMapHelper::GetTotalLookAheadDelayLength(
        LimiterDSPSurroundMemoryMapHelper *this,
        unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(&this->mLimiterUtilities, (double)(int)this->mSampleRate);
}

// File Line: 1304
// RVA: 0xAFFFD0
void __fastcall LimiterDSPSurroundMemoryMapHelper::FillMeteringData(
        LimiterDSPSurroundMemoryMapHelper *this,
        char *pMeteringData)
{
  LimiterSurroundMemoryMap *LimiterMemMapPtr; // r8

  LimiterMemMapPtr = this->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 63;
  *((_DWORD *)pMeteringData + 1) = LODWORD(LimiterMemMapPtr->XMemory[19]);
  *((float *)pMeteringData + 2) = LimiterMemMapPtr->XMemory[20] * 3.9810717;
  *((float *)pMeteringData + 3) = LimiterMemMapPtr->XMemory[28] * 3.9810717;
  *((float *)pMeteringData + 4) = LimiterMemMapPtr->XMemory[24] * 3.9810717;
  *((float *)pMeteringData + 5) = LimiterMemMapPtr->XMemory[32] * 3.9810717;
  *((float *)pMeteringData + 6) = LimiterMemMapPtr->XMemory[36] * 3.9810717;
  *((float *)pMeteringData + 7) = LimiterMemMapPtr->XMemory[40] * 3.9810717;
  *((_DWORD *)pMeteringData + 8) = LODWORD(LimiterMemMapPtr->XMemory[23]);
  *((_DWORD *)pMeteringData + 9) = LODWORD(LimiterMemMapPtr->XMemory[31]);
  *((_DWORD *)pMeteringData + 10) = LODWORD(LimiterMemMapPtr->XMemory[27]);
  *((_DWORD *)pMeteringData + 11) = LODWORD(LimiterMemMapPtr->XMemory[35]);
  *((_DWORD *)pMeteringData + 12) = LODWORD(LimiterMemMapPtr->XMemory[39]);
  *((_DWORD *)pMeteringData + 13) = LODWORD(LimiterMemMapPtr->XMemory[43]);
}

// File Line: 1315
// RVA: 0xAFFA40
void __fastcall LimiterProcessSurroundFloatImpl::LimiterProcessSurroundFloatImpl(LimiterProcessSurroundFloatImpl *this)
{
  this->mMemoryMapHelper = 0i64;
}

// File Line: 1321
// RVA: 0xAFFA60
void __fastcall LimiterProcessSurroundFloatImpl::~LimiterProcessSurroundFloatImpl(
        LimiterProcessSurroundFloatImpl *this)
{
  ;
}

// File Line: 1327
// RVA: 0xAFFA70
unsigned __int64 __fastcall LimiterProcessSurroundFloatImpl::GetMemoryMapSize(LimiterProcessSurroundFloatImpl *this)
{
  return 10176i64;
}

// File Line: 1337
// RVA: 0xAFFA80
__int64 __fastcall LimiterProcessSurroundFloatImpl::Init(
        LimiterProcessSurroundFloatImpl *this,
        PooledMemoryAllocator *memoryMapAllocator,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int sampleRate)
{
  DSPMemoryMapHelper *v7; // rax
  LimiterDSPSurroundMemoryMapHelper *v8; // rbx
  char *v9; // rax

  v7 = (DSPMemoryMapHelper *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24i64);
  v8 = (LimiterDSPSurroundMemoryMapHelper *)v7;
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
  v8->mNumChannels = 6;
  v8->mSampleRate = sampleRate;
  v9 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x27C0ui64);
  v8->LimiterMemMapPtr = (LimiterSurroundMemoryMap *)v9;
  if ( !v9 )
    return 52i64;
  *((_DWORD *)v9 + 9) = 1065353216;
  v8->LimiterMemMapPtr->XMemory[8] = 1072.0;
  return 1i64;
}

// File Line: 1348
// RVA: 0xAFFB40
void __fastcall LimiterProcessSurroundFloatImpl::Term(
        LimiterProcessSurroundFloatImpl *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterDSPSurroundMemoryMapHelper *mMemoryMapHelper; // rdi

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

// File Line: 1356
// RVA: 0xAFFBB0
void __fastcall LimiterProcessSurroundFloatImpl::SetParameters(
        LimiterProcessSurroundFloatImpl *this,
        LimiterParameters *limiterParams)
{
  long double v4; // xmm6_8
  double ceiling; // xmm1_8
  LimiterDSPSurroundMemoryMapHelper *mMemoryMapHelper; // rbx
  double v7; // xmm0_8
  float *XMemory; // rax
  float v9; // xmm1_4
  double v10; // xmm1_8
  double v11; // xmm0_8
  float *v12; // rax
  float v13; // xmm1_4
  LimiterDSPSurroundMemoryMapHelper *v14; // rbx
  int LookAheadDelayLength; // eax
  long double TCScalar; // xmm0_8
  LimiterDSPSurroundMemoryMapHelper *v17; // rcx
  float v18; // xmm1_4
  LimiterDSPSurroundMemoryMapHelper *v19; // rbx
  int TotalLookAheadDelayLength; // eax
  LimiterDSPSurroundMemoryMapHelper *v21; // rcx

  v4 = limiterParams->threshold - 12.0;
  if ( v4 < -36.0 )
    v4 = DOUBLE_N36_0;
  ceiling = limiterParams->ceiling;
  mMemoryMapHelper = this->mMemoryMapHelper;
  if ( v4 < 0.0 )
    ceiling = ceiling + -0.01;
  v7 = pow(10.0, ceiling * 0.05);
  XMemory = mMemoryMapHelper->LimiterMemMapPtr->XMemory;
  v9 = v7;
  XMemory[41] = v9;
  XMemory[37] = v9;
  XMemory[33] = v9;
  XMemory[29] = v9;
  XMemory[25] = v9;
  XMemory[21] = v9;
  v10 = limiterParams->ceiling;
  if ( v4 < 0.0 )
    v10 = v10 + -0.01;
  v11 = pow(10.0, v10 * 0.05);
  v12 = mMemoryMapHelper->LimiterMemMapPtr->XMemory;
  v13 = v11;
  v12[41] = v13;
  v12[37] = v13;
  v12[33] = v13;
  v12[29] = v13;
  v12[25] = v13;
  v12[21] = v13;
  LimiterUtilities::GenerateExpTable(v12 + 1291, 600, v4, limiterParams->knee);
  v14 = this->mMemoryMapHelper;
  LookAheadDelayLength = LimiterUtilities::GetLookAheadDelayLength(
                           &this->mMemoryMapHelper->mLimiterUtilities,
                           (double)this->mMemoryMapHelper->mSampleRate);
  TCScalar = GetTCScalar((double)LookAheadDelayLength);
  v17 = this->mMemoryMapHelper;
  v18 = TCScalar;
  v14->LimiterMemMapPtr->XMemory[13] = v18;
  LimiterDSPSurroundMemoryMapHelper::SetRelease(v17, limiterParams->release, limiterParams->character);
  LimiterDSPSurroundMemoryMapHelper::SetCharacter(
    this->mMemoryMapHelper,
    limiterParams->character,
    limiterParams->release);
  v19 = this->mMemoryMapHelper;
  TotalLookAheadDelayLength = LimiterUtilities::GetTotalLookAheadDelayLength(
                                &this->mMemoryMapHelper->mLimiterUtilities,
                                (double)this->mMemoryMapHelper->mSampleRate);
  v21 = this->mMemoryMapHelper;
  v19->LimiterMemMapPtr->XMemory[11] = (float)(TotalLookAheadDelayLength + 1);
  LimiterDSPSurroundMemoryMapHelper::SetLookAhead(v21);
}

// File Line: 1405
// RVA: 0xAFFD70
void __fastcall LimiterProcessSurroundFloatImpl::ProcessAudio(
        LimiterProcessSurroundFloatImpl *this,
        char *memoryMap,
        AkAudioBuffer *inputBuffer,
        AkAudioBuffer *outputBuffer)
{
  __int64 uMaxFrames; // rcx
  __int64 v5; // r12

  uMaxFrames = outputBuffer->uMaxFrames;
  v5 = inputBuffer->uMaxFrames;
  McDSPLimiterProcessChannels(
    memoryMap,
    (const float *)inputBuffer->pData,
    (const float *)inputBuffer->pData + 2 * v5,
    (const float *)inputBuffer->pData + v5,
    (const float *)inputBuffer->pData + 3 * v5,
    (float *)inputBuffer->pData + 4 * (unsigned int)v5,
    (const float *)inputBuffer->pData + 5 * v5,
    (float *)outputBuffer->pData,
    (float *)outputBuffer->pData + 2 * uMaxFrames,
    (float *)outputBuffer->pData + uMaxFrames,
    (float *)outputBuffer->pData + 3 * uMaxFrames,
    (float *)outputBuffer->pData + 4 * uMaxFrames,
    (float *)outputBuffer->pData + 5 * uMaxFrames,
    inputBuffer->uValidFrames);
}

// File Line: 1431
// RVA: 0xAFFE70
int __fastcall LimiterProcessSurroundFloatImpl::GetNumTailFrames(
        LimiterProcessSurroundFloatImpl *this,
        unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(
           &this->mMemoryMapHelper->mLimiterUtilities,
           (double)this->mMemoryMapHelper->mSampleRate);
}

// File Line: 1436
// RVA: 0xAFFE90
void __fastcall LimiterProcessSurroundFloatImpl::FillMeteringData(
        LimiterProcessSurroundFloatImpl *this,
        char *pMeteringData)
{
  LimiterDSPSurroundMemoryMapHelper::FillMeteringData(this->mMemoryMapHelper, pMeteringData);
}

