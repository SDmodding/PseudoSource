// File Line: 28
// RVA: 0xC70740
void __fastcall hkRadixSort::sort16(hkRadixSort::SortData16 *data, int numObjects, hkRadixSort::SortData16 *buffer)
{
  signed int v3; // er10
  hkRadixSort::SortData16 *v4; // rsi
  __int64 v5; // rdi
  hkRadixSort::SortData16 *v6; // rbx
  int *v7; // r9
  signed int v8; // er11
  int *v9; // rax
  int *v10; // rcx
  int *v11; // rax
  __int64 v14; // r8
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rcx
  signed __int64 v20; // r8
  __int64 v21; // rax
  __int64 v22; // rdx
  __int64 v23; // rdx
  __int64 v24; // rcx
  signed __int64 v25; // r8
  unsigned __int64 v26; // r9
  __int64 v27; // rax
  _DWORD *v28; // rcx
  __int64 v29; // rax
  _DWORD *v30; // rcx
  __int64 v31; // rax
  _DWORD *v32; // rcx
  __int64 v33; // rax
  _DWORD *v34; // rcx
  signed __int64 v35; // r8
  unsigned __int64 v36; // r9
  __int64 v37; // rax
  _DWORD *v38; // rcx
  __int64 v39; // rax
  _DWORD *v40; // rcx
  __int64 v41; // rax
  _DWORD *v42; // rcx
  __int64 v43; // rax
  _DWORD *v44; // rcx
  int v45; // [rsp+0h] [rbp-104h]
  int v46[256]; // [rsp+4h] [rbp-100h]
  int v47[256]; // [rsp+404h] [rbp+300h]
  __int64 v48[256]; // [rsp+804h] [rbp+700h]
  __int64 v49[256]; // [rsp+1004h] [rbp+F00h]

  v3 = 63;
  v4 = buffer;
  v5 = numObjects;
  v6 = data;
  v7 = v47;
  v8 = 63;
  do
  {
    v9 = v7;
    v7 += 4;
    --v8;
    *(_OWORD *)v9 = 0i64;
  }
  while ( v8 >= 0 );
  v10 = v46;
  do
  {
    v11 = v10;
    v10 += 4;
    --v3;
    *(_OWORD *)v11 = 0i64;
  }
  while ( v3 >= 0 );
  if ( numObjects > 0 )
  {
    _RDX = (unsigned __int8 *)&v6->m_keys[1];
    _R9 = (char *)((char *)buffer - (char *)v6);
    v14 = ((unsigned int)(v5 - 1) >> 2) + 1;
    do
    {
      v15 = *_RDX;
      ++v47[*(_RDX - 1)];
      ++v46[v15];
      __asm { prefetchnta byte ptr [rdx+3FFh]; Prefetch to L1 cache }
      v16 = _RDX[4];
      ++v47[_RDX[3]];
      ++v46[v16];
      __asm { prefetchnta byte ptr [r9+rdx+3FFh]; Prefetch to L1 cache }
      v17 = _RDX[7];
      v18 = _RDX[8];
      _RDX += 16;
      ++v47[v17];
      ++v46[v18];
      v19 = *(_RDX - 4);
      ++v47[*(_RDX - 5)];
      ++v46[v19];
      --v14;
    }
    while ( v14 );
  }
  v20 = 0i64;
  v48[0] = (__int64)v4;
  v49[0] = (__int64)v6;
  v21 = 0i64;
  do
  {
    v22 = v47[v20];
    ++v20;
    v23 = v48[v21] + 4 * v22;
    v24 = v49[v21];
    ++v21;
    v48[v21] = v23;
    v49[v21] = v24 + 4i64 * *(int *)((char *)&v45 + v20 * 4);
  }
  while ( v20 < 255 );
  if ( (signed int)v5 > 0 )
  {
    v25 = (signed __int64)&v6[2];
    v26 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
    do
    {
      v27 = *(unsigned __int8 *)(v25 - 8);
      v25 += 16i64;
      v28 = (_DWORD *)v48[v27];
      *v28 = *(_DWORD *)(v25 - 24);
      v48[v27] = (__int64)(v28 + 1);
      v29 = *(unsigned __int8 *)(v25 - 20);
      v30 = (_DWORD *)v48[v29];
      *v30 = *(_DWORD *)(v25 - 20);
      v48[v29] = (__int64)(v30 + 1);
      v31 = *(unsigned __int8 *)(v25 - 16);
      v32 = (_DWORD *)v48[v31];
      *v32 = *(_DWORD *)(v25 - 16);
      v48[v31] = (__int64)(v32 + 1);
      v33 = *(unsigned __int8 *)(v25 - 12);
      v34 = (_DWORD *)v48[v33];
      *v34 = *(_DWORD *)(v25 - 12);
      v48[v33] = (__int64)(v34 + 1);
      --v26;
    }
    while ( v26 );
    if ( (signed int)v5 > 0 )
    {
      v35 = (signed __int64)&v4[2].m_key + 1;
      v36 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
      do
      {
        v37 = *(unsigned __int8 *)(v35 - 8);
        v35 += 16i64;
        v38 = (_DWORD *)v49[v37];
        *v38 = *(_DWORD *)(v35 - 25);
        v49[v37] = (__int64)(v38 + 1);
        v39 = *(unsigned __int8 *)(v35 - 20);
        v40 = (_DWORD *)v49[v39];
        *v40 = *(_DWORD *)(v35 - 21);
        v49[v39] = (__int64)(v40 + 1);
        v41 = *(unsigned __int8 *)(v35 - 16);
        v42 = (_DWORD *)v49[v41];
        *v42 = *(_DWORD *)(v35 - 17);
        v49[v41] = (__int64)(v42 + 1);
        v43 = *(unsigned __int8 *)(v35 - 12);
        v44 = (_DWORD *)v49[v43];
        *v44 = *(_DWORD *)(v35 - 13);
        v49[v43] = (__int64)(v44 + 1);
        --v36;
      }
      while ( v36 );
    }
  }
}

// File Line: 118
// RVA: 0xC70A10
void __fastcall hkRadixSort::sort32(hkRadixSort::SortData32 *data, int numObjects, hkRadixSort::SortData32 *buffer)
{
  signed int v3; // er10
  hkRadixSort::SortData32 *v4; // rdi
  __int64 v5; // rsi
  hkRadixSort::SortData32 *v6; // rbx
  int *v7; // r9
  signed int v8; // er11
  int *v9; // rax
  int *v10; // rcx
  signed int v11; // edx
  int *v12; // rax
  int *v13; // rcx
  signed int v14; // edx
  int *v15; // rax
  int *v16; // rcx
  int *v17; // rax
  __int64 v20; // r10
  __int64 v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rcx
  __int64 v25; // rdx
  __int64 v26; // r8
  __int64 v27; // rcx
  __int64 v28; // rdx
  __int64 v29; // r8
  __int64 v30; // rcx
  __int64 v31; // rdx
  __int64 v32; // r8
  signed __int64 v33; // r8
  __int64 v34; // rax
  __int64 v35; // rdx
  __int64 v36; // rdx
  __int64 v37; // rcx
  signed __int64 v38; // rdx
  __int64 v39; // rcx
  signed __int64 v40; // rdx
  __int64 v41; // rcx
  signed __int64 v42; // r8
  unsigned __int64 v43; // r9
  __int64 v44; // rax
  _QWORD *v45; // rcx
  __int64 v46; // rax
  _QWORD *v47; // rcx
  __int64 v48; // rax
  _QWORD *v49; // rcx
  __int64 v50; // rax
  _QWORD *v51; // rcx
  signed __int64 v52; // r8
  unsigned __int64 v53; // r9
  __int64 v54; // rax
  _QWORD *v55; // rcx
  __int64 v56; // rax
  _QWORD *v57; // rcx
  __int64 v58; // rax
  _QWORD *v59; // rcx
  __int64 v60; // rax
  _QWORD *v61; // rcx
  signed __int64 v62; // r8
  unsigned __int64 v63; // r9
  __int64 v64; // rax
  _QWORD *v65; // rcx
  __int64 v66; // rax
  _QWORD *v67; // rcx
  __int64 v68; // rax
  _QWORD *v69; // rcx
  __int64 v70; // rax
  _QWORD *v71; // rcx
  signed __int64 v72; // r8
  unsigned __int64 v73; // r9
  __int64 v74; // rax
  _QWORD *v75; // rcx
  __int64 v76; // rax
  _QWORD *v77; // rcx
  __int64 v78; // rax
  _QWORD *v79; // rcx
  __int64 v80; // rax
  _QWORD *v81; // rcx
  int v82; // [rsp+0h] [rbp-104h]
  int v83[255]; // [rsp+4h] [rbp-100h]
  int v84; // [rsp+400h] [rbp+2FCh]
  int v85[255]; // [rsp+404h] [rbp+300h]
  int v86; // [rsp+800h] [rbp+6FCh]
  int v87[256]; // [rsp+804h] [rbp+700h]
  int v88[256]; // [rsp+C04h] [rbp+B00h]
  __int64 v89[255]; // [rsp+1004h] [rbp+F00h]
  __int64 v90; // [rsp+17FCh] [rbp+16F8h]
  __int64 v91[256]; // [rsp+1804h] [rbp+1700h]
  __int64 v92[255]; // [rsp+2004h] [rbp+1F00h]
  __int64 v93; // [rsp+27FCh] [rbp+26F8h]
  __int64 v94[256]; // [rsp+2804h] [rbp+2700h]

  v3 = 63;
  v4 = buffer;
  v5 = numObjects;
  v6 = data;
  v7 = v88;
  v8 = 63;
  do
  {
    v9 = v7;
    v7 += 4;
    --v8;
    *(_OWORD *)v9 = 0i64;
  }
  while ( v8 >= 0 );
  v10 = v87;
  v11 = 63;
  do
  {
    v12 = v10;
    v10 += 4;
    --v11;
    *(_OWORD *)v12 = 0i64;
  }
  while ( v11 >= 0 );
  v13 = v85;
  v14 = 63;
  do
  {
    v15 = v13;
    v13 += 4;
    --v14;
    *(_OWORD *)v15 = 0i64;
  }
  while ( v14 >= 0 );
  v16 = v83;
  do
  {
    v17 = v16;
    v16 += 4;
    --v3;
    *(_OWORD *)v17 = 0i64;
  }
  while ( v3 >= 0 );
  if ( (signed int)v5 > 0 )
  {
    _R9 = (unsigned __int8 *)v6 + 1;
    _R11 = (char *)((char *)buffer - (char *)v6);
    v20 = ((unsigned int)(v5 - 1) >> 2) + 1;
    do
    {
      v21 = *_R9;
      v22 = _R9[1];
      v23 = _R9[2];
      ++v88[*(_R9 - 1)];
      ++v87[v21];
      ++v85[v22];
      ++v83[v23];
      __asm { prefetchnta byte ptr [r9+3FFh]; Prefetch to L1 cache }
      v24 = _R9[8];
      v25 = _R9[9];
      v26 = _R9[10];
      ++v88[_R9[7]];
      ++v87[v24];
      ++v85[v25];
      ++v83[v26];
      __asm { prefetchnta byte ptr [r11+r9+3FFh]; Prefetch to L1 cache }
      v27 = _R9[16];
      v28 = _R9[17];
      v29 = _R9[18];
      ++v88[_R9[15]];
      ++v87[v27];
      ++v85[v28];
      ++v83[v29];
      v30 = _R9[24];
      v31 = _R9[25];
      v32 = _R9[26];
      ++v88[_R9[23]];
      ++v87[v30];
      ++v85[v31];
      ++v83[v32];
      _R9 += 32;
      --v20;
    }
    while ( v20 );
  }
  v33 = 0i64;
  v89[0] = (__int64)v4;
  v92[0] = (__int64)v6;
  v91[0] = (__int64)v4;
  v94[0] = (__int64)v6;
  v34 = 0i64;
  do
  {
    v35 = v88[v33];
    ++v33;
    v36 = v89[v34] + 8 * v35;
    v37 = v92[v34];
    ++v34;
    v89[v34] = v36;
    v38 = v37 + 8i64 * *(int *)((char *)&v86 + v33 * 4);
    v39 = *(__int64 *)((char *)&v90 + v34 * 8);
    v92[v34] = v38;
    v40 = v39 + 8i64 * *(int *)((char *)&v84 + v33 * 4);
    v41 = *(__int64 *)((char *)&v93 + v34 * 8);
    v91[v34] = v40;
    v94[v34] = v41 + 8i64 * *(int *)((char *)&v82 + v33 * 4);
  }
  while ( v33 < 255 );
  if ( (signed int)v5 > 0 )
  {
    v42 = (signed __int64)&v6[2];
    v43 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
    do
    {
      v44 = *(unsigned __int8 *)(v42 - 16);
      v42 += 32i64;
      v45 = (_QWORD *)v89[v44];
      *v45 = *(_QWORD *)(v42 - 48);
      v89[v44] = (__int64)(v45 + 1);
      v46 = *(unsigned __int8 *)(v42 - 40);
      v47 = (_QWORD *)v89[v46];
      *v47 = *(_QWORD *)(v42 - 40);
      v89[v46] = (__int64)(v47 + 1);
      v48 = *(unsigned __int8 *)(v42 - 32);
      v49 = (_QWORD *)v89[v48];
      *v49 = *(_QWORD *)(v42 - 32);
      v89[v48] = (__int64)(v49 + 1);
      v50 = *(unsigned __int8 *)(v42 - 24);
      v51 = (_QWORD *)v89[v50];
      *v51 = *(_QWORD *)(v42 - 24);
      v89[v50] = (__int64)(v51 + 1);
      --v43;
    }
    while ( v43 );
    if ( (signed int)v5 > 0 )
    {
      v52 = (signed __int64)&v4[2] + 1;
      v53 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
      do
      {
        v54 = *(unsigned __int8 *)(v52 - 16);
        v52 += 32i64;
        v55 = (_QWORD *)v92[v54];
        *v55 = *(_QWORD *)(v52 - 49);
        v92[v54] = (__int64)(v55 + 1);
        v56 = *(unsigned __int8 *)(v52 - 40);
        v57 = (_QWORD *)v92[v56];
        *v57 = *(_QWORD *)(v52 - 41);
        v92[v56] = (__int64)(v57 + 1);
        v58 = *(unsigned __int8 *)(v52 - 32);
        v59 = (_QWORD *)v92[v58];
        *v59 = *(_QWORD *)(v52 - 33);
        v92[v58] = (__int64)(v59 + 1);
        v60 = *(unsigned __int8 *)(v52 - 24);
        v61 = (_QWORD *)v92[v60];
        *v61 = *(_QWORD *)(v52 - 25);
        v92[v60] = (__int64)(v61 + 1);
        --v53;
      }
      while ( v53 );
      if ( (signed int)v5 > 0 )
      {
        v62 = (signed __int64)&v6[2] + 2;
        v63 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
        do
        {
          v64 = *(unsigned __int8 *)(v62 - 16);
          v62 += 32i64;
          v65 = (_QWORD *)v91[v64];
          *v65 = *(_QWORD *)(v62 - 50);
          v91[v64] = (__int64)(v65 + 1);
          v66 = *(unsigned __int8 *)(v62 - 40);
          v67 = (_QWORD *)v91[v66];
          *v67 = *(_QWORD *)(v62 - 42);
          v91[v66] = (__int64)(v67 + 1);
          v68 = *(unsigned __int8 *)(v62 - 32);
          v69 = (_QWORD *)v91[v68];
          *v69 = *(_QWORD *)(v62 - 34);
          v91[v68] = (__int64)(v69 + 1);
          v70 = *(unsigned __int8 *)(v62 - 24);
          v71 = (_QWORD *)v91[v70];
          *v71 = *(_QWORD *)(v62 - 26);
          v91[v70] = (__int64)(v71 + 1);
          --v63;
        }
        while ( v63 );
        if ( (signed int)v5 > 0 )
        {
          v72 = (signed __int64)&v4[2] + 3;
          v73 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
          do
          {
            v74 = *(unsigned __int8 *)(v72 - 16);
            v72 += 32i64;
            v75 = (_QWORD *)v94[v74];
            *v75 = *(_QWORD *)(v72 - 51);
            v94[v74] = (__int64)(v75 + 1);
            v76 = *(unsigned __int8 *)(v72 - 40);
            v77 = (_QWORD *)v94[v76];
            *v77 = *(_QWORD *)(v72 - 43);
            v94[v76] = (__int64)(v77 + 1);
            v78 = *(unsigned __int8 *)(v72 - 32);
            v79 = (_QWORD *)v94[v78];
            *v79 = *(_QWORD *)(v72 - 35);
            v94[v78] = (__int64)(v79 + 1);
            v80 = *(unsigned __int8 *)(v72 - 24);
            v81 = (_QWORD *)v94[v80];
            *v81 = *(_QWORD *)(v72 - 27);
            v94[v80] = (__int64)(v81 + 1);
            --v73;
          }
          while ( v73 );
        }
      }
    }
  }
}        v94[v78] = (__int64)(v79 + 1);
            v80 = *(unsigned __int8 *)(v72 - 24);
            v81 = (_QWORD *)v94[v80];
            *v81 = *(_QWORD *)(v72 - 27);
            v94[v80] = (__int64)(v81 + 1)

