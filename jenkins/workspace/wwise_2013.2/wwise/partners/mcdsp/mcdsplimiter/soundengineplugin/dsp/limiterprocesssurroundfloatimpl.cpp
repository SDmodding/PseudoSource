// File Line: 214
// RVA: 0xAFED40
void __fastcall McDSPLimiterProcessChannels(void *memoryMap, const float *inputBuf_L, const float *inputBuf_C, const float *inputBuf_R, const float *inputBuf_Ls, const float *inputBuf_Rs, const float *inputBuf_LFE, float *outputBuf_L, float *outputBuf_C, float *outputBuf_R, float *outputBuf_Ls, float *outputBuf_Rs, float *outputBuf_LFE, unsigned int samplesRemaining)
{
  signed int v14; // edi
  int v15; // er13
  char *v16; // rbp
  float *v17; // r10
  const float *v18; // rbx
  signed __int64 v19; // r14
  signed int v20; // ecx
  signed int v21; // er15
  signed int v22; // eax
  int v23; // er11
  signed int v24; // eax
  unsigned int v25; // ecx
  signed int v26; // er12
  float v27; // xmm9_4
  float *v28; // r9
  float v29; // xmm1_4
  float v30; // xmm0_4
  float *v31; // r10
  float *v32; // rsi
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  int v37; // edx
  signed __int64 v38; // r8
  float v39; // xmm4_4
  signed __int64 v40; // rax
  int v41; // xmm2_4
  int v42; // xmm1_4
  int v43; // ecx
  __int64 v44; // rax
  int v45; // xmm2_4
  int v46; // xmm1_4
  __int64 v47; // rcx
  int v48; // xmm1_4
  int v49; // xmm0_4
  float v50; // xmm4_4
  int v51; // xmm2_4
  int v52; // xmm2_4
  char *v53; // rcx
  int v54; // er11
  unsigned int v55; // eax
  __int64 v56; // r8
  __int64 v57; // r8
  float v58; // xmm4_4
  float v59; // xmm6_4
  float v60; // xmm5_4
  float v61; // xmm5_4
  float v62; // xmm5_4
  float v63; // xmm0_4
  float v64; // xmm5_4
  float v65; // xmm2_4
  float v66; // xmm4_4
  int v67; // xmm0_4
  int v68; // xmm5_4
  float v69; // xmm1_4
  int v70; // xmm4_4
  int v71; // xmm0_4
  float v72; // xmm5_4
  float v73; // xmm0_4
  float v74; // xmm2_4
  float v75; // xmm0_4
  signed __int64 v76; // rax
  signed __int64 v77; // rcx
  signed __int64 v78; // r8
  float v79; // xmm4_4
  __int64 v80; // rax
  float v81; // xmm5_4
  int v82; // er10
  float v83; // xmm0_4
  signed __int64 v84; // rax
  signed __int64 v85; // rcx
  unsigned int v86; // eax
  __int64 v87; // r8
  signed __int64 v88; // rcx
  __int64 v89; // r8
  float v90; // xmm2_4
  float v91; // xmm4_4
  float v92; // xmm6_4
  int v93; // xmm5_4
  float v94; // xmm2_4
  float v95; // xmm4_4
  float v96; // xmm2_4
  int v97; // xmm4_4
  float v98; // xmm2_4
  float v99; // xmm4_4
  float v100; // xmm2_4
  int v101; // xmm4_4
  float v102; // xmm2_4
  float v103; // xmm4_4
  float v104; // xmm2_4
  int v105; // xmm4_4
  float v106; // xmm2_4
  float v107; // xmm4_4
  float v108; // xmm2_4
  int v109; // xmm4_4
  float v110; // xmm2_4
  float v111; // xmm4_4
  float v112; // xmm2_4
  int v113; // xmm4_4
  float v114; // xmm2_4
  float v115; // xmm4_4
  float v116; // xmm2_4
  int v117; // [rsp+0h] [rbp-E8h]
  signed int v118; // [rsp+4h] [rbp-E4h]
  signed int v119; // [rsp+8h] [rbp-E0h]
  signed int v120; // [rsp+Ch] [rbp-DCh]
  signed __int64 v121; // [rsp+10h] [rbp-D8h]
  __int64 v122; // [rsp+18h] [rbp-D0h]
  __int64 v123; // [rsp+20h] [rbp-C8h]
  signed __int64 v124; // [rsp+28h] [rbp-C0h]
  signed __int64 v125; // [rsp+38h] [rbp-B0h]
  int v126; // [rsp+F0h] [rbp+8h]
  const float *v127; // [rsp+F8h] [rbp+10h]
  const float *v128; // [rsp+100h] [rbp+18h]
  unsigned int samplesRemaininga; // [rsp+158h] [rbp+70h]

  v14 = (signed int)*((float *)memoryMap + 1278);
  v15 = (signed int)*((float *)memoryMap + 6);
  v16 = (char *)memoryMap;
  v17 = (float *)((char *)memoryMap + 24);
  v18 = inputBuf_R;
  v19 = v14;
  v20 = (signed int)*((float *)memoryMap + 7);
  v21 = (signed int)*((float *)v16 + 1286);
  v22 = (signed int)*((float *)v16 + 11);
  *(_QWORD *)(v16 + 76) = 0i64;
  *(_QWORD *)(v16 + 108) = 0i64;
  *(_QWORD *)(v16 + 92) = 0i64;
  v118 = v20;
  v120 = v22;
  v123 = v20;
  *(_QWORD *)(v16 + 124) = 0i64;
  *(_QWORD *)(v16 + 140) = 0i64;
  *(_QWORD *)(v16 + 156) = 0i64;
  *((_DWORD *)v16 + 43) = 0;
  v23 = (signed int)*((float *)v16 + 18);
  v24 = (signed int)*((float *)v16 + 16);
  v119 = (signed int)*((float *)v16 + 8);
  v126 = v23;
  v122 = v24;
  v121 = v23;
  v25 = samplesRemaining;
  v26 = (signed int)*((float *)v16 + 17);
  if ( samplesRemaining )
  {
    v124 = v24 + 1;
    v27 = kHeadRoomScaleFactor_1;
    do
    {
      v28 = v17;
      samplesRemaininga = v25 - 1;
      v127 = inputBuf_L + 1;
      v128 = inputBuf_C + 1;
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
      *((float *)v16 + 1272) = v29;
      v31 = (float *)(v16 + 5092);
      v32 = v31;
      ++inputBuf_Ls;
      *v31 = v30;
      v33 = v27 * *v18;
      v34 = v27 * *(inputBuf_Ls - 1);
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
      *((float *)v16 + 1274) = v33;
      *((float *)v16 + 1275) = v34;
      ++inputBuf_Rs;
      v35 = v27 * *(inputBuf_Rs - 1);
      ++inputBuf_LFE;
      v36 = v27 * *(inputBuf_LFE - 1);
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
      *((float *)v16 + 1276) = v35;
      v37 = v14 + 1;
      *((float *)v16 + 1277) = v36;
      v38 = v19 + 1;
      v39 = *v28;
      if ( v14 + 1 >= v15 )
      {
        v37 = 0;
        v38 = 0i64;
      }
      v40 = v19 + v123;
      v41 = *(_DWORD *)&v16[4 * (v19 + v123)];
      *(_DWORD *)&v16[4 * v40] = *((_DWORD *)v16 + 1272);
      v42 = *(_DWORD *)&v16[4 * (v19 + v123) + 5088];
      v117 = v37;
      v125 = v38;
      *(float *)&v16[4 * v40 + 5088] = *v31;
      *((_DWORD *)v16 + 1279) = v41;
      *((_DWORD *)v16 + 1280) = v42;
      v43 = (signed int)v39 + v14 + v118 + 1;
      v44 = v43;
      v45 = *(_DWORD *)&v16[4 * v43];
      *(_DWORD *)&v16[4 * v44] = *((_DWORD *)v16 + 1274);
      v46 = *(_DWORD *)&v16[4 * v43 + 5088];
      *(_DWORD *)&v16[4 * v44 + 5088] = *((_DWORD *)v16 + 1275);
      *((_DWORD *)v16 + 1281) = v45;
      *((_DWORD *)v16 + 1282) = v46;
      v47 = (signed int)v39 + v43 + 1;
      v48 = *(_DWORD *)&v16[4 * v47];
      *(_DWORD *)&v16[4 * v47] = *((_DWORD *)v16 + 1276);
      v49 = *(_DWORD *)&v16[4 * v47 + 5088];
      *(_DWORD *)&v16[4 * v47 + 5088] = *((_DWORD *)v16 + 1277);
      *((_DWORD *)v16 + 1283) = v48;
      *((_DWORD *)v16 + 1284) = v49;
      v50 = *v31;
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1272) & _xmm) > COERCE_FLOAT(*(_DWORD *)v31 & _xmm) )
        v50 = *((float *)v16 + 1272);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1274) & _xmm) > COERCE_FLOAT(LODWORD(v50) & _xmm) )
        v50 = *((float *)v16 + 1274);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1275) & _xmm) > COERCE_FLOAT(LODWORD(v50) & _xmm) )
        v50 = *((float *)v16 + 1275);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1276) & _xmm) > COERCE_FLOAT(LODWORD(v50) & _xmm) )
        v50 = *((float *)v16 + 1276);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1277) & _xmm) > COERCE_FLOAT(LODWORD(v50) & _xmm) )
        v50 = *((float *)v16 + 1277);
      v51 = *((_DWORD *)v16 + 1280);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1279) & _xmm) > COERCE_FLOAT(*((_DWORD *)v16 + 1280) & _xmm) )
        v51 = *((_DWORD *)v16 + 1279);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1281) & _xmm) > COERCE_FLOAT(v51 & _xmm) )
        v51 = *((_DWORD *)v16 + 1281);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1282) & _xmm) > COERCE_FLOAT(v51 & _xmm) )
        v51 = *((_DWORD *)v16 + 1282);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1283) & _xmm) > COERCE_FLOAT(v51 & _xmm) )
        v51 = *((_DWORD *)v16 + 1283);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1284) & _xmm) > COERCE_FLOAT(v51 & _xmm) )
        v51 = *((_DWORD *)v16 + 1284);
      *((_DWORD *)v16 + 1285) = v51;
      *(float *)&v16[4 * (v19 + v119) + 5088] = v50;
      v52 = 0;
      v53 = &v16[4 * v119 + 5088];
      v54 = 0;
      if ( v15 >= 4 )
      {
        v55 = ((unsigned int)(v15 - 4) >> 2) + 1;
        v56 = v55;
        v54 = 4 * v55;
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v53 & _xmm) > COERCE_FLOAT(v52 & _xmm) )
            v52 = *(_DWORD *)v53;
          if ( COERCE_FLOAT(*((_DWORD *)v53 + 1) & _xmm) > COERCE_FLOAT(v52 & _xmm) )
            v52 = *((_DWORD *)v53 + 1);
          if ( COERCE_FLOAT(*((_DWORD *)v53 + 2) & _xmm) > COERCE_FLOAT(v52 & _xmm) )
            v52 = *((_DWORD *)v53 + 2);
          if ( COERCE_FLOAT(*((_DWORD *)v53 + 3) & _xmm) > COERCE_FLOAT(v52 & _xmm) )
            v52 = *((_DWORD *)v53 + 3);
          v53 += 16;
          --v56;
        }
        while ( v56 );
      }
      if ( v54 < v15 )
      {
        v57 = (unsigned int)(v15 - v54);
        do
        {
          if ( COERCE_FLOAT(*(_DWORD *)v53 & _xmm) > COERCE_FLOAT(v52 & _xmm) )
            v52 = *(_DWORD *)v53;
          v53 += 4;
          --v57;
        }
        while ( v57 );
      }
      LODWORD(v58) = *((_DWORD *)v16 + 1272) & _xmm;
      v59 = v28[4];
      if ( COERCE_FLOAT(*(_DWORD *)v31 & _xmm) > v58 )
        LODWORD(v58) = *(_DWORD *)v31 & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1274) & _xmm) > v58 )
        LODWORD(v58) = *((_DWORD *)v16 + 1274) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1275) & _xmm) > v58 )
        LODWORD(v58) = *((_DWORD *)v16 + 1275) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1276) & _xmm) > v58 )
        LODWORD(v58) = *((_DWORD *)v16 + 1276) & _xmm;
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1277) & _xmm) > v58 )
        LODWORD(v58) = *((_DWORD *)v16 + 1277) & _xmm;
      if ( v58 >= 1.0 )
        v58 = *(float *)&FLOAT_1_0;
      if ( COERCE_FLOAT((_DWORD)v28[3] & _xmm) <= COERCE_FLOAT(LODWORD(v58) & _xmm) )
        v58 = v28[3];
      v60 = *((float *)v16 + 1287);
      if ( COERCE_FLOAT(LODWORD(v58) & _xmm) > COERCE_FLOAT(*((_DWORD *)v16 + 1287) & _xmm) )
      {
        v21 = v120;
        v60 = v58;
      }
      LODWORD(v61) = LODWORD(v60) & _xmm;
      *((float *)v16 + 1287) = v61;
      v62 = v61 - v59;
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1288) & _xmm) > COERCE_FLOAT(LODWORD(v62) & _xmm) )
        v62 = *((float *)v16 + 1288);
      *((float *)v16 + 1288) = v62;
      v63 = v28[7];
      --v21;
      v64 = 0.0;
      if ( v21 < 0 )
        v21 = 0;
      if ( v21 <= 0 )
      {
        v64 = v28[6];
        v63 = 0.0;
      }
      LODWORD(v65) = v52 & _xmm;
      v66 = (float)((float)(*((float *)v16 + 1288) * v63) + v28[4]) + (float)((float)(v65 - v28[4]) * v64);
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1287) & _xmm) <= COERCE_FLOAT(LODWORD(v66) & _xmm) )
        v66 = *((float *)v16 + 1287);
      v67 = *((_DWORD *)v16 + 1288);
      if ( v21 <= 0 )
        v67 = 0;
      *((_DWORD *)v16 + 1288) = v67;
      v68 = *((_DWORD *)v16 + 1285);
      LODWORD(v69) = *((_DWORD *)v16 + 1285) & _xmm;
      if ( v69 > COERCE_FLOAT(LODWORD(v66) & _xmm) )
        v66 = *((float *)v16 + 1285);
      v70 = LODWORD(v66) & _xmm;
      *((_DWORD *)v28 + 4) = v70;
      v71 = *((_DWORD *)v16 + 1287);
      if ( v69 > COERCE_FLOAT(v70 & _xmm) )
        v71 = v68;
      *((_DWORD *)v16 + 1287) = v71 & _xmm;
      v72 = v28[8];
      if ( COERCE_FLOAT(*((_DWORD *)v16 + 1289) & _xmm) < COERCE_FLOAT(LODWORD(v65) & _xmm) )
        v72 = v28[9];
      v73 = v28[4];
      v74 = (float)((float)(v65 - *((float *)v16 + 1289)) * v72) + *((float *)v16 + 1289);
      *((float *)v16 + 1289) = v74;
      if ( v73 > v74 )
        v74 = v73;
      v28[4] = v74;
      v75 = *((float *)v16 + 1287);
      if ( v21 <= 0 )
        v75 = v74;
      v76 = v121;
      *((float *)v16 + 1287) = v75;
      v23 = v126 + 1;
      v77 = v121 + 1;
      v78 = v121;
      ++v126;
      if ( v121 + 1 >= v26 )
      {
        v23 = 0;
        v126 = 0;
        v77 = 0i64;
      }
      v121 = v77;
      v79 = 0.0;
      v80 = v122 + v76;
      *(float *)&v16[4 * v80 + 5088] = v74;
      v81 = *(float *)&v16[4 * v122];
      v82 = 0;
      v83 = *(float *)&v16[4 * (v80 - v78) + 5088];
      v84 = v124;
      if ( v26 >= 4 )
      {
        v85 = (signed __int64)&v16[4 * v124 + 5096];
        v86 = ((unsigned int)(v26 - 4) >> 2) + 1;
        v87 = v86;
        v82 = 4 * v86;
        v84 = v124 + 4i64 * v86;
        do
        {
          v85 += 16i64;
          v79 = (float)((float)((float)(v79 + (float)(v83 * v81)) + (float)(v81 * *(float *)(v85 - 24)))
                      + (float)(v81 * *(float *)(v85 - 20)))
              + (float)(v81 * *(float *)(v85 - 16));
          v83 = *(float *)(v85 - 12);
          --v87;
        }
        while ( v87 );
      }
      if ( v82 < v26 )
      {
        v88 = (signed __int64)&v16[4 * v84 + 5088];
        v89 = (unsigned int)(v26 - v82);
        do
        {
          v88 += 4i64;
          v79 = v79 + (float)(v83 * v81);
          v83 = *(float *)(v88 - 4);
          --v89;
        }
        while ( v89 );
      }
      v90 = (float)((float)((float)((float)(v79 * 2.0) - (float)(v79 * v79)) * 2.0)
                  - (float)((float)((float)(v79 * 2.0) - (float)(v79 * v79))
                          * (float)((float)(v79 * 2.0) - (float)(v79 * v79))))
          * 599.0;
      v91 = (float)((float)(v32[(signed int)v90 + 19] - v32[(signed int)v90 + 18])
                  * (float)(v90 - (float)(signed int)v90))
          + v32[(signed int)v90 + 18];
      v92 = (float)((float)(v32[(signed int)v90 + 19] - v32[(signed int)v90 + 18])
                  * (float)(v90 - (float)(signed int)v90))
          + v32[(signed int)v90 + 18];
      if ( COERCE_FLOAT((_DWORD)v28[13] & _xmm) > COERCE_FLOAT(LODWORD(v91) & _xmm) )
        v91 = v28[13];
      v28[13] = v91;
      v93 = *((_DWORD *)v28 + 14);
      v94 = v32[6];
      if ( COERCE_FLOAT((_DWORD)v32[6] & _xmm) > COERCE_FLOAT((_DWORD)v28[14] & _xmm) )
        v93 = *((_DWORD *)v32 + 6);
      *((_DWORD *)v28 + 14) = v93;
      v95 = v28[17];
      v96 = (float)(v94 * v92) * v28[15];
      if ( COERCE_FLOAT(LODWORD(v96) & _xmm) > COERCE_FLOAT((_DWORD)v28[17] & _xmm) )
        v95 = v96;
      v28[17] = v95;
      ++outputBuf_L;
      *(outputBuf_L - 1) = v96;
      v97 = *((_DWORD *)v28 + 18);
      v98 = v32[7];
      if ( COERCE_FLOAT((_DWORD)v32[7] & _xmm) > COERCE_FLOAT((_DWORD)v28[18] & _xmm) )
        v97 = *((_DWORD *)v32 + 7);
      *((_DWORD *)v28 + 18) = v97;
      v99 = v28[21];
      v100 = (float)(v98 * v92) * v28[19];
      if ( COERCE_FLOAT(LODWORD(v100) & _xmm) > COERCE_FLOAT((_DWORD)v28[21] & _xmm) )
        v99 = v100;
      v28[21] = v99;
      ++outputBuf_C;
      *(outputBuf_C - 1) = v100;
      v101 = *((_DWORD *)v28 + 22);
      v102 = v32[8];
      if ( COERCE_FLOAT((_DWORD)v32[8] & _xmm) > COERCE_FLOAT((_DWORD)v28[22] & _xmm) )
        v101 = *((_DWORD *)v32 + 8);
      *((_DWORD *)v28 + 22) = v101;
      v103 = v28[25];
      v104 = (float)(v102 * v92) * v28[23];
      if ( COERCE_FLOAT(LODWORD(v104) & _xmm) > COERCE_FLOAT((_DWORD)v28[25] & _xmm) )
        v103 = v104;
      v28[25] = v103;
      ++outputBuf_R;
      *(outputBuf_R - 1) = v104;
      v105 = *((_DWORD *)v28 + 26);
      v106 = v32[9];
      if ( COERCE_FLOAT((_DWORD)v32[9] & _xmm) > COERCE_FLOAT((_DWORD)v28[26] & _xmm) )
        v105 = *((_DWORD *)v32 + 9);
      *((_DWORD *)v28 + 26) = v105;
      v107 = v28[29];
      v108 = (float)(v106 * v92) * v28[27];
      if ( COERCE_FLOAT(LODWORD(v108) & _xmm) > COERCE_FLOAT((_DWORD)v28[29] & _xmm) )
        v107 = v108;
      v28[29] = v107;
      ++outputBuf_Ls;
      *(outputBuf_Ls - 1) = v108;
      v109 = *((_DWORD *)v28 + 30);
      v110 = v32[10];
      if ( COERCE_FLOAT((_DWORD)v32[10] & _xmm) > COERCE_FLOAT((_DWORD)v28[30] & _xmm) )
        v109 = *((_DWORD *)v32 + 10);
      *((_DWORD *)v28 + 30) = v109;
      v111 = v28[33];
      v112 = (float)(v110 * v92) * v28[31];
      if ( COERCE_FLOAT(LODWORD(v112) & _xmm) > COERCE_FLOAT((_DWORD)v28[33] & _xmm) )
        v111 = v112;
      v28[33] = v111;
      ++outputBuf_Rs;
      *(outputBuf_Rs - 1) = v112;
      v113 = *((_DWORD *)v28 + 34);
      v114 = v32[11];
      if ( COERCE_FLOAT((_DWORD)v32[11] & _xmm) > COERCE_FLOAT((_DWORD)v28[34] & _xmm) )
        v113 = *((_DWORD *)v32 + 11);
      *((_DWORD *)v28 + 34) = v113;
      v115 = v28[37];
      v116 = (float)(v114 * v92) * v28[35];
      if ( COERCE_FLOAT(LODWORD(v116) & _xmm) > COERCE_FLOAT((_DWORD)v28[37] & _xmm) )
        v115 = v116;
      v25 = samplesRemaininga;
      inputBuf_C = v128;
      v28[37] = v115;
      inputBuf_L = v127;
      v14 = v117;
      ++v18;
      *outputBuf_LFE = v116;
      v19 = v125;
      v17 = (float *)(v16 + 24);
      ++outputBuf_LFE;
    }
    while ( samplesRemaininga );
  }
  *((float *)v16 + 1286) = (float)v21;
  *((float *)v16 + 1278) = (float)v14;
  *((float *)v16 + 18) = (float)v23;
}

// File Line: 1009
// RVA: 0xAFF910
void __fastcall McDSPFillVUMetersDataSurround(void *memoryMap, char *pMeteringData)
{
  *(_DWORD *)pMeteringData = 63;
  *((_DWORD *)pMeteringData + 1) = *((_DWORD *)memoryMap + 19);
  *((float *)pMeteringData + 2) = *((float *)memoryMap + 20) * 3.9810717;
  *((float *)pMeteringData + 3) = *((float *)memoryMap + 28) * 3.9810717;
  *((float *)pMeteringData + 4) = *((float *)memoryMap + 24) * 3.9810717;
  *((float *)pMeteringData + 5) = *((float *)memoryMap + 32) * 3.9810717;
  *((float *)pMeteringData + 6) = *((float *)memoryMap + 36) * 3.9810717;
  *((float *)pMeteringData + 7) = *((float *)memoryMap + 40) * 3.9810717;
  *((_DWORD *)pMeteringData + 8) = *((_DWORD *)memoryMap + 23);
  *((_DWORD *)pMeteringData + 9) = *((_DWORD *)memoryMap + 31);
  *((_DWORD *)pMeteringData + 10) = *((_DWORD *)memoryMap + 27);
  *((_DWORD *)pMeteringData + 11) = *((_DWORD *)memoryMap + 35);
  *((_DWORD *)pMeteringData + 12) = *((_DWORD *)memoryMap + 39);
  *((_DWORD *)pMeteringData + 13) = *((_DWORD *)memoryMap + 43);
}

// File Line: 1089
// RVA: 0xAFFEA0
void __fastcall LimiterDSPSurroundMemoryMapHelper::LimiterDSPSurroundMemoryMapHelper(LimiterDSPSurroundMemoryMapHelper *this, int sampleRate)
{
  LimiterDSPSurroundMemoryMapHelper *v2; // rbx

  v2 = this;
  DSPMemoryMapHelper::DSPMemoryMapHelper(&this->0);
  LimiterUtilities::LimiterUtilities(&v2->mLimiterUtilities, 0.00085000001, 0.000325);
}

// File Line: 1095
// RVA: 0xAFFEE0
void __fastcall LimiterDSPSurroundMemoryMapHelper::~LimiterDSPSurroundMemoryMapHelper(LimiterDSPSurroundMemoryMapHelper *this)
{
  LimiterDSPSurroundMemoryMapHelper *v1; // rbx

  v1 = this;
  LimiterUtilities::~LimiterUtilities(&this->mLimiterUtilities);
  DSPMemoryMapHelper::~DSPMemoryMapHelper(&v1->0);
}

// File Line: 1100
// RVA: 0xAFFF10
unsigned __int64 __fastcall LimiterDSPSurroundMemoryMapHelper::GetMemoryMapSize(LimiterDSPSurroundMemoryMapHelper *this)
{
  return 10176i64;
}

// File Line: 1108
// RVA: 0xAFFF20
signed __int64 __fastcall LimiterDSPSurroundMemoryMapHelper::Init(LimiterDSPSurroundMemoryMapHelper *this, PooledMemoryAllocator *memoryMapAllocator, unsigned int sampleRate)
{
  LimiterDSPSurroundMemoryMapHelper *v3; // rbx
  char *v4; // rax

  v3 = this;
  this->mNumChannels = 6;
  this->mSampleRate = sampleRate;
  v4 = PooledMemoryAllocator::Malloc(memoryMapAllocator, 0x27C0ui64);
  v3->LimiterMemMapPtr = (LimiterSurroundMemoryMap *)v4;
  if ( !v4 )
    return 52i64;
  *((_DWORD *)v4 + 9) = 1065353216;
  v3->LimiterMemMapPtr->XMemory[8] = 1072.0;
  return 1i64;
}

// File Line: 1132
// RVA: 0xAFFF80
LimiterSurroundMemoryMap *__fastcall LimiterDSPSurroundMemoryMapHelper::GetMemoryMap(LimiterDSPSurroundMemoryMapHelper *this)
{
  return this->LimiterMemMapPtr;
}

// File Line: 1139
// RVA: 0xB00090
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetCeiling(LimiterDSPSurroundMemoryMapHelper *this, long double ceiling, long double threshold)
{
  LimiterDSPSurroundMemoryMapHelper *v3; // rbx
  double v4; // xmm0_8
  float *v5; // rax
  float v6; // xmm1_4

  v3 = this;
  if ( threshold < 0.0 )
    ceiling = ceiling + -0.01;
  v4 = pow(10.0, ceiling * 0.05);
  v5 = v3->LimiterMemMapPtr->XMemory;
  v6 = v4;
  v5[41] = v6;
  v5[37] = v6;
  v5[33] = v6;
  v5[29] = v6;
  v5[25] = v6;
  v5[21] = v6;
}

// File Line: 1160
// RVA: 0xB00100
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetThreshold(LimiterDSPSurroundMemoryMapHelper *this, long double threshold, long double knee, long double ceiling)
{
  LimiterDSPSurroundMemoryMapHelper *v4; // rbx
  double v5; // xmm0_8
  float *v6; // rax
  float v7; // xmm1_4

  v4 = this;
  if ( threshold < 0.0 )
    ceiling = ceiling - 0.01;
  v5 = pow(10.0, ceiling * 0.05);
  v6 = v4->LimiterMemMapPtr->XMemory;
  v7 = v5;
  v6[41] = v7;
  v6[37] = v7;
  v6[33] = v7;
  v6[29] = v7;
  v6[25] = v7;
  v6[21] = v7;
}

// File Line: 1170
// RVA: 0xB00170
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetKnee(LimiterDSPSurroundMemoryMapHelper *this, long double knee, long double threshold)
{
  ;
}

// File Line: 1180
// RVA: 0xAFFFB0
void __fastcall LimiterDSPSurroundMemoryMapHelper::GenerateExpTable(LimiterDSPSurroundMemoryMapHelper *this, long double knee, long double threshold)
{
  LimiterUtilities::GenerateExpTable(&this->LimiterMemMapPtr->YMemory[19], 600, threshold, knee);
}

// File Line: 1188
// RVA: 0xB00180
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetRelease(LimiterDSPSurroundMemoryMapHelper *this, long double release, LimiterCharacterType character)
{
  double v3; // xmm2_8
  LimiterDSPSurroundMemoryMapHelper *v4; // rbx
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
  v4->LimiterMemMapPtr->XMemory[12] = v7;
}

// File Line: 1213
// RVA: 0xB00250
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetCharacter(LimiterDSPSurroundMemoryMapHelper *this, LimiterCharacterType character, long double release)
{
  LimiterDSPSurroundMemoryMapHelper *v3; // rbx
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
  v3->LimiterMemMapPtr->XMemory[15] = v8;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v9 = DynamicsCalculator::CalculateReleaseScalar(v3->mSampleRate, v5 + v7);
  v3->LimiterMemMapPtr->XMemory[14] = v9;
}

// File Line: 1246
// RVA: 0xB003C0
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetAttack(LimiterDSPSurroundMemoryMapHelper *this)
{
  LimiterDSPSurroundMemoryMapHelper *v1; // rbx
  signed int v2; // eax
  float v3; // xmm1_4

  v1 = this;
  v2 = LimiterUtilities::GetLookAheadDelayLength(&this->mLimiterUtilities, (double)(signed int)this->mSampleRate);
  v3 = GetTCScalar((double)v2);
  v1->LimiterMemMapPtr->XMemory[13] = v3;
}

// File Line: 1258
// RVA: 0xB00410
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetHold(LimiterDSPSurroundMemoryMapHelper *this)
{
  this->LimiterMemMapPtr->XMemory[11] = (float)(LimiterUtilities::GetTotalLookAheadDelayLength(
                                                  &this->mLimiterUtilities,
                                                  (double)(signed int)this->mSampleRate)
                                              + 1);
}

// File Line: 1272
// RVA: 0xB00450
void __fastcall LimiterDSPSurroundMemoryMapHelper::SetLookAhead(LimiterDSPSurroundMemoryMapHelper *this)
{
  LimiterDSPSurroundMemoryMapHelper *v1; // rbx
  signed int v2; // eax
  float *v3; // rdi
  __int64 v4; // rcx
  float v5; // eax

  v1 = this;
  this->LimiterMemMapPtr->XMemory[7] = 619.0;
  this->LimiterMemMapPtr->XMemory[6] = (float)LimiterUtilities::GetTotalLookAheadDelayLength(
                                                &this->mLimiterUtilities,
                                                (double)(signed int)this->mSampleRate);
  v1->LimiterMemMapPtr->XMemory[16] = 1223.0;
  v1->LimiterMemMapPtr->XMemory[17] = (float)LimiterUtilities::GetFIRLength(
                                               &v1->mLimiterUtilities,
                                               (double)(signed int)v1->mSampleRate);
  v2 = LimiterUtilities::GetFIRLength(&v1->mLimiterUtilities, (double)(signed int)v1->mSampleRate);
  v3 = &v1->LimiterMemMapPtr->XMemory[1223];
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

// File Line: 1297
// RVA: 0xAFFF90
int __fastcall LimiterDSPSurroundMemoryMapHelper::GetTotalLookAheadDelayLength(LimiterDSPSurroundMemoryMapHelper *this, unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(&this->mLimiterUtilities, (double)(signed int)this->mSampleRate);
}

// File Line: 1304
// RVA: 0xAFFFD0
void __fastcall LimiterDSPSurroundMemoryMapHelper::FillMeteringData(LimiterDSPSurroundMemoryMapHelper *this, char *pMeteringData)
{
  LimiterSurroundMemoryMap *v2; // r8

  v2 = this->LimiterMemMapPtr;
  *(_DWORD *)pMeteringData = 63;
  *((_DWORD *)pMeteringData + 1) = LODWORD(v2->XMemory[19]);
  *((float *)pMeteringData + 2) = v2->XMemory[20] * 3.9810717;
  *((float *)pMeteringData + 3) = v2->XMemory[28] * 3.9810717;
  *((float *)pMeteringData + 4) = v2->XMemory[24] * 3.9810717;
  *((float *)pMeteringData + 5) = v2->XMemory[32] * 3.9810717;
  *((float *)pMeteringData + 6) = v2->XMemory[36] * 3.9810717;
  *((float *)pMeteringData + 7) = v2->XMemory[40] * 3.9810717;
  *((_DWORD *)pMeteringData + 8) = LODWORD(v2->XMemory[23]);
  *((_DWORD *)pMeteringData + 9) = LODWORD(v2->XMemory[31]);
  *((_DWORD *)pMeteringData + 10) = LODWORD(v2->XMemory[27]);
  *((_DWORD *)pMeteringData + 11) = LODWORD(v2->XMemory[35]);
  *((_DWORD *)pMeteringData + 12) = LODWORD(v2->XMemory[39]);
  *((_DWORD *)pMeteringData + 13) = LODWORD(v2->XMemory[43]);
}

// File Line: 1315
// RVA: 0xAFFA40
void __fastcall LimiterProcessSurroundFloatImpl::LimiterProcessSurroundFloatImpl(LimiterProcessSurroundFloatImpl *this)
{
  this->mMemoryMapHelper = 0i64;
}

// File Line: 1321
// RVA: 0xAFFA60
void __fastcall LimiterProcessSurroundFloatImpl::~LimiterProcessSurroundFloatImpl(LimiterProcessSurroundFloatImpl *this)
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
signed __int64 __fastcall LimiterProcessSurroundFloatImpl::Init(LimiterProcessSurroundFloatImpl *this, PooledMemoryAllocator *memoryMapAllocator, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int sampleRate)
{
  PooledMemoryAllocator *v4; // rbp
  LimiterProcessSurroundFloatImpl *v5; // rdi
  unsigned int v6; // esi
  DSPMemoryMapHelper *v7; // rax
  LimiterDSPSurroundMemoryMapHelper *v8; // rbx
  char *v9; // rax

  v4 = memoryMapAllocator;
  v5 = this;
  v6 = sampleRate;
  v7 = (DSPMemoryMapHelper *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24ui64);
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
  v5->mMemoryMapHelper = v8;
  if ( !v8 )
    return 52i64;
  v8->mNumChannels = 6;
  v8->mSampleRate = v6;
  v9 = PooledMemoryAllocator::Malloc(v4, 0x27C0ui64);
  v8->LimiterMemMapPtr = (LimiterSurroundMemoryMap *)v9;
  if ( !v9 )
    return 52i64;
  *((_DWORD *)v9 + 9) = 1065353216;
  v8->LimiterMemMapPtr->XMemory[8] = 1072.0;
  return 1i64;
}

// File Line: 1348
// RVA: 0xAFFB40
void __fastcall LimiterProcessSurroundFloatImpl::Term(LimiterProcessSurroundFloatImpl *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterDSPSurroundMemoryMapHelper *v2; // rdi
  AK::IAkPluginMemAlloc *v3; // rsi
  LimiterProcessSurroundFloatImpl *v4; // rbx

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

// File Line: 1356
// RVA: 0xAFFBB0
void __fastcall LimiterProcessSurroundFloatImpl::SetParameters(LimiterProcessSurroundFloatImpl *this, LimiterParameters *limiterParams)
{
  LimiterParameters *v2; // rdi
  LimiterProcessSurroundFloatImpl *v3; // rsi
  long double v4; // xmm6_8
  double v5; // xmm1_8
  LimiterDSPSurroundMemoryMapHelper *v6; // rbx
  double v7; // xmm0_8
  float *v8; // rax
  float v9; // xmm1_4
  double v10; // xmm1_8
  double v11; // xmm0_8
  float *v12; // rax
  float v13; // xmm1_4
  LimiterUtilities *v14; // rbx
  signed int v15; // eax
  long double v16; // xmm0_8
  LimiterDSPSurroundMemoryMapHelper *v17; // rcx
  float v18; // xmm1_4
  LimiterDSPSurroundMemoryMapHelper *v19; // rbx
  int v20; // eax
  LimiterDSPSurroundMemoryMapHelper *v21; // rcx

  v2 = limiterParams;
  v3 = this;
  v4 = limiterParams->threshold - 12.0;
  if ( v4 < -36.0 )
    v4 = DOUBLE_N36_0;
  v5 = limiterParams->ceiling;
  v6 = this->mMemoryMapHelper;
  if ( v4 < 0.0 )
    v5 = v5 + -0.01;
  v7 = pow(10.0, v5 * 0.05);
  v8 = v6->LimiterMemMapPtr->XMemory;
  v9 = v7;
  v8[41] = v9;
  v8[37] = v9;
  v8[33] = v9;
  v8[29] = v9;
  v8[25] = v9;
  v8[21] = v9;
  v10 = v2->ceiling;
  if ( v4 < 0.0 )
    v10 = v10 + -0.01;
  v11 = pow(10.0, v10 * 0.05);
  v12 = v6->LimiterMemMapPtr->XMemory;
  v13 = v11;
  v12[41] = v13;
  v12[37] = v13;
  v12[33] = v13;
  v12[29] = v13;
  v12[25] = v13;
  v12[21] = v13;
  LimiterUtilities::GenerateExpTable(v12 + 1291, 600, v4, v2->knee);
  v14 = (LimiterUtilities *)v3->mMemoryMapHelper;
  v15 = LimiterUtilities::GetLookAheadDelayLength(
          &v3->mMemoryMapHelper->mLimiterUtilities,
          (double)v3->mMemoryMapHelper->mSampleRate);
  v16 = GetTCScalar((double)v15);
  v17 = v3->mMemoryMapHelper;
  v18 = v16;
  *(float *)(*(_QWORD *)&v14[1] + 52i64) = v18;
  LimiterDSPSurroundMemoryMapHelper::SetRelease(v17, v2->release, v2->character);
  LimiterDSPSurroundMemoryMapHelper::SetCharacter(v3->mMemoryMapHelper, v2->character, v2->release);
  v19 = v3->mMemoryMapHelper;
  v20 = LimiterUtilities::GetTotalLookAheadDelayLength(
          &v3->mMemoryMapHelper->mLimiterUtilities,
          (double)v3->mMemoryMapHelper->mSampleRate);
  v21 = v3->mMemoryMapHelper;
  v19->LimiterMemMapPtr->XMemory[11] = (float)(v20 + 1);
  LimiterDSPSurroundMemoryMapHelper::SetLookAhead(v21);
}

// File Line: 1405
// RVA: 0xAFFD70
void __fastcall LimiterProcessSurroundFloatImpl::ProcessAudio(LimiterProcessSurroundFloatImpl *this, void *memoryMap, AkAudioBuffer *inputBuffer, AkAudioBuffer *outputBuffer)
{
  __int64 v4; // rcx
  __int64 v5; // r12

  v4 = outputBuffer->uMaxFrames;
  v5 = inputBuffer->uMaxFrames;
  McDSPLimiterProcessChannels(
    memoryMap,
    (const float *)inputBuffer->pData,
    (const float *)inputBuffer->pData + 2 * v5,
    (const float *)inputBuffer->pData + v5,
    (const float *)inputBuffer->pData + 3 * v5,
    (const float *)inputBuffer->pData + 4 * (unsigned int)v5,
    (const float *)inputBuffer->pData + 5 * v5,
    (float *)outputBuffer->pData,
    (float *)outputBuffer->pData + 2 * v4,
    (float *)outputBuffer->pData + v4,
    (float *)outputBuffer->pData + 3 * v4,
    (float *)outputBuffer->pData + 4 * v4,
    (float *)outputBuffer->pData + 5 * v4,
    inputBuffer->uValidFrames);
}

// File Line: 1431
// RVA: 0xAFFE70
int __fastcall LimiterProcessSurroundFloatImpl::GetNumTailFrames(LimiterProcessSurroundFloatImpl *this, unsigned int sampleRate)
{
  return LimiterUtilities::GetTotalLookAheadDelayLength(
           &this->mMemoryMapHelper->mLimiterUtilities,
           (double)this->mMemoryMapHelper->mSampleRate);
}

// File Line: 1436
// RVA: 0xAFFE90
void __fastcall LimiterProcessSurroundFloatImpl::FillMeteringData(LimiterProcessSurroundFloatImpl *this, char *pMeteringData)
{
  LimiterDSPSurroundMemoryMapHelper::FillMeteringData(this->mMemoryMapHelper, pMeteringData);
}

