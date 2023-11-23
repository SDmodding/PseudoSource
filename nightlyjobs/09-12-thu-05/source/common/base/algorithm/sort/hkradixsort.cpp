// File Line: 28
// RVA: 0xC70740
void __fastcall hkRadixSort::sort16(hkRadixSort::SortData16 *data, int numObjects, hkRadixSort::SortData16 *buffer)
{
  int v3; // r10d
  __int64 v5; // rdi
  int *v7; // r9
  int i; // r11d
  int *v9; // rax
  int *v10; // rcx
  int *v11; // rax
  char *v12; // rdx
  signed __int64 v13; // r9
  __int64 v14; // r8
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // r8
  __int64 v21; // rax
  __int64 v22; // rdx
  __int64 v23; // rdx
  __int64 v24; // rcx
  hkRadixSort::SortData16 *v25; // r8
  unsigned __int64 v26; // r9
  __int64 v27; // rax
  _DWORD *v28; // rcx
  __int64 v29; // rax
  _DWORD *v30; // rcx
  __int64 v31; // rax
  _DWORD *v32; // rcx
  __int64 v33; // rax
  _DWORD *v34; // rcx
  char *v35; // r8
  unsigned __int64 v36; // r9
  __int64 v37; // rax
  _DWORD *v38; // rcx
  __int64 v39; // rax
  _DWORD *v40; // rcx
  __int64 v41; // rax
  _DWORD *v42; // rcx
  __int64 v43; // rax
  _DWORD *v44; // rcx
  int v46[256]; // [rsp+4h] [rbp-100h] BYREF
  int v47[256]; // [rsp+404h] [rbp+300h] BYREF
  __int64 v48[256]; // [rsp+804h] [rbp+700h]
  __int64 v49[256]; // [rsp+1004h] [rbp+F00h]

  v3 = 63;
  v5 = numObjects;
  v7 = v47;
  for ( i = 63; i >= 0; --i )
  {
    v9 = v7;
    v7 += 4;
    *(_OWORD *)v9 = 0i64;
  }
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
    v12 = &data->m_keys[1];
    v13 = (char *)buffer - (char *)data;
    v14 = ((unsigned int)(v5 - 1) >> 2) + 1;
    do
    {
      v15 = (unsigned __int8)*v12;
      ++v47[(unsigned __int8)*(v12 - 1)];
      ++v46[v15];
      _mm_prefetch(v12 + 1023, 0);
      v16 = (unsigned __int8)v12[4];
      ++v47[(unsigned __int8)v12[3]];
      ++v46[v16];
      _mm_prefetch(&v12[v13 + 1023], 0);
      v17 = (unsigned __int8)v12[7];
      v18 = (unsigned __int8)v12[8];
      v12 += 16;
      ++v47[v17];
      ++v46[v18];
      v19 = (unsigned __int8)*(v12 - 4);
      ++v47[(unsigned __int8)*(v12 - 5)];
      ++v46[v19];
      --v14;
    }
    while ( v14 );
  }
  v20 = 0i64;
  v48[0] = (__int64)buffer;
  v49[0] = (__int64)data;
  v21 = 0i64;
  do
  {
    v22 = v47[v20++];
    v23 = v48[v21] + 4 * v22;
    v24 = v49[v21++];
    v48[v21] = v23;
    v49[v21] = v24 + 4i64 * v46[v20 - 1];
  }
  while ( v20 < 255 );
  if ( (int)v5 > 0 )
  {
    v25 = data + 2;
    v26 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
    do
    {
      v27 = (unsigned __int8)v25[-2].m_keys[0];
      v25 += 4;
      v28 = (_DWORD *)v48[v27];
      *v28 = v25[-6];
      v48[v27] = (__int64)(v28 + 1);
      v29 = (unsigned __int8)v25[-5].m_keys[0];
      v30 = (_DWORD *)v48[v29];
      *v30 = v25[-5];
      v48[v29] = (__int64)(v30 + 1);
      v31 = (unsigned __int8)v25[-4].m_keys[0];
      v32 = (_DWORD *)v48[v31];
      *v32 = v25[-4];
      v48[v31] = (__int64)(v32 + 1);
      v33 = (unsigned __int8)v25[-3].m_keys[0];
      v34 = (_DWORD *)v48[v33];
      *v34 = v25[-3];
      v48[v33] = (__int64)(v34 + 1);
      --v26;
    }
    while ( v26 );
    v35 = &buffer[2].m_keys[1];
    v36 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
    do
    {
      v37 = (unsigned __int8)*(v35 - 8);
      v35 += 16;
      v38 = (_DWORD *)v49[v37];
      *v38 = *(_DWORD *)(v35 - 25);
      v49[v37] = (__int64)(v38 + 1);
      v39 = (unsigned __int8)*(v35 - 20);
      v40 = (_DWORD *)v49[v39];
      *v40 = *(_DWORD *)(v35 - 21);
      v49[v39] = (__int64)(v40 + 1);
      v41 = (unsigned __int8)*(v35 - 16);
      v42 = (_DWORD *)v49[v41];
      *v42 = *(_DWORD *)(v35 - 17);
      v49[v41] = (__int64)(v42 + 1);
      v43 = (unsigned __int8)*(v35 - 12);
      v44 = (_DWORD *)v49[v43];
      *v44 = *(_DWORD *)(v35 - 13);
      v49[v43] = (__int64)(v44 + 1);
      --v36;
    }
    while ( v36 );
  }
}

// File Line: 118
// RVA: 0xC70A10
void __fastcall hkRadixSort::sort32(hkRadixSort::SortData32 *data, int numObjects, hkRadixSort::SortData32 *buffer)
{
  int v3; // r10d
  __int64 v5; // rsi
  int *v7; // r9
  int i; // r11d
  int *v9; // rax
  int *v10; // rcx
  int j; // edx
  int *v12; // rax
  int *v13; // rcx
  int k; // edx
  int *v15; // rax
  int *v16; // rcx
  int *v17; // rax
  const char *v18; // r9
  signed __int64 v19; // r11
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
  __int64 v33; // r8
  __int64 v34; // rax
  __int64 v35; // rdx
  __int64 v36; // rdx
  __int64 v37; // rcx
  __int64 v38; // rdx
  __int64 v39; // rcx
  __int64 v40; // rdx
  __int64 v41; // rcx
  hkRadixSort::SortData32 *v42; // r8
  unsigned __int64 v43; // r9
  __int64 v44; // rax
  _QWORD *v45; // rcx
  __int64 v46; // rax
  _QWORD *v47; // rcx
  __int64 v48; // rax
  _QWORD *v49; // rcx
  __int64 v50; // rax
  _QWORD *v51; // rcx
  char *v52; // r8
  unsigned __int64 v53; // r9
  __int64 v54; // rax
  _QWORD *v55; // rcx
  __int64 v56; // rax
  _QWORD *v57; // rcx
  __int64 v58; // rax
  _QWORD *v59; // rcx
  __int64 v60; // rax
  _QWORD *v61; // rcx
  char *v62; // r8
  unsigned __int64 v63; // r9
  __int64 v64; // rax
  _QWORD *v65; // rcx
  __int64 v66; // rax
  _QWORD *v67; // rcx
  __int64 v68; // rax
  _QWORD *v69; // rcx
  __int64 v70; // rax
  _QWORD *v71; // rcx
  char *v72; // r8
  unsigned __int64 v73; // r9
  __int64 v74; // rax
  _QWORD *v75; // rcx
  __int64 v76; // rax
  _QWORD *v77; // rcx
  __int64 v78; // rax
  _QWORD *v79; // rcx
  __int64 v80; // rax
  _QWORD *v81; // rcx
  int v83[256]; // [rsp+4h] [rbp-100h] BYREF
  int v84[256]; // [rsp+404h] [rbp+300h] BYREF
  int v85[256]; // [rsp+804h] [rbp+700h] BYREF
  int v86[256]; // [rsp+C04h] [rbp+B00h] BYREF
  __int64 v87[256]; // [rsp+1004h] [rbp+F00h]
  __int64 v88[256]; // [rsp+1804h] [rbp+1700h]
  __int64 v89[256]; // [rsp+2004h] [rbp+1F00h]
  __int64 v90[256]; // [rsp+2804h] [rbp+2700h]

  v3 = 63;
  v5 = numObjects;
  v7 = v86;
  for ( i = 63; i >= 0; --i )
  {
    v9 = v7;
    v7 += 4;
    *(_OWORD *)v9 = 0i64;
  }
  v10 = v85;
  for ( j = 63; j >= 0; --j )
  {
    v12 = v10;
    v10 += 4;
    *(_OWORD *)v12 = 0i64;
  }
  v13 = v84;
  for ( k = 63; k >= 0; --k )
  {
    v15 = v13;
    v13 += 4;
    *(_OWORD *)v15 = 0i64;
  }
  v16 = v83;
  do
  {
    v17 = v16;
    v16 += 4;
    --v3;
    *(_OWORD *)v17 = 0i64;
  }
  while ( v3 >= 0 );
  if ( (int)v5 > 0 )
  {
    v18 = (char *)data + 1;
    v19 = (char *)buffer - (char *)data;
    v20 = ((unsigned int)(v5 - 1) >> 2) + 1;
    do
    {
      v21 = *(unsigned __int8 *)v18;
      v22 = *((unsigned __int8 *)v18 + 1);
      v23 = *((unsigned __int8 *)v18 + 2);
      ++v86[*((unsigned __int8 *)v18 - 1)];
      ++v85[v21];
      ++v84[v22];
      ++v83[v23];
      _mm_prefetch(v18 + 1023, 0);
      v24 = *((unsigned __int8 *)v18 + 8);
      v25 = *((unsigned __int8 *)v18 + 9);
      v26 = *((unsigned __int8 *)v18 + 10);
      ++v86[*((unsigned __int8 *)v18 + 7)];
      ++v85[v24];
      ++v84[v25];
      ++v83[v26];
      _mm_prefetch(&v18[v19 + 1023], 0);
      v27 = *((unsigned __int8 *)v18 + 16);
      v28 = *((unsigned __int8 *)v18 + 17);
      v29 = *((unsigned __int8 *)v18 + 18);
      ++v86[*((unsigned __int8 *)v18 + 15)];
      ++v85[v27];
      ++v84[v28];
      ++v83[v29];
      v30 = *((unsigned __int8 *)v18 + 24);
      v31 = *((unsigned __int8 *)v18 + 25);
      v32 = *((unsigned __int8 *)v18 + 26);
      ++v86[*((unsigned __int8 *)v18 + 23)];
      ++v85[v30];
      ++v84[v31];
      ++v83[v32];
      v18 += 32;
      --v20;
    }
    while ( v20 );
  }
  v33 = 0i64;
  v87[0] = (__int64)buffer;
  v89[0] = (__int64)data;
  v88[0] = (__int64)buffer;
  v90[0] = (__int64)data;
  v34 = 0i64;
  do
  {
    v35 = v86[v33++];
    v36 = v87[v34] + 8 * v35;
    v37 = v89[v34++];
    v87[v34] = v36;
    v38 = v37 + 8i64 * v84[v33 + 255];
    v39 = v87[v34 + 255];
    v89[v34] = v38;
    v40 = v39 + 8i64 * v83[v33 + 255];
    v41 = v89[v34 + 255];
    v88[v34] = v40;
    v90[v34] = v41 + 8i64 * v83[v33 - 1];
  }
  while ( v33 < 255 );
  if ( (int)v5 > 0 )
  {
    v42 = data + 2;
    v43 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
    do
    {
      v44 = (unsigned __int8)v42[-2].m_keys[0];
      v42 += 4;
      v45 = (_QWORD *)v87[v44];
      *v45 = v42[-6];
      v87[v44] = (__int64)(v45 + 1);
      v46 = (unsigned __int8)v42[-5].m_keys[0];
      v47 = (_QWORD *)v87[v46];
      *v47 = v42[-5];
      v87[v46] = (__int64)(v47 + 1);
      v48 = (unsigned __int8)v42[-4].m_keys[0];
      v49 = (_QWORD *)v87[v48];
      *v49 = v42[-4];
      v87[v48] = (__int64)(v49 + 1);
      v50 = (unsigned __int8)v42[-3].m_keys[0];
      v51 = (_QWORD *)v87[v50];
      *v51 = v42[-3];
      v87[v50] = (__int64)(v51 + 1);
      --v43;
    }
    while ( v43 );
    v52 = (char *)&buffer[2] + 1;
    v53 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
    do
    {
      v54 = (unsigned __int8)*(v52 - 16);
      v52 += 32;
      v55 = (_QWORD *)v89[v54];
      *v55 = *(_QWORD *)(v52 - 49);
      v89[v54] = (__int64)(v55 + 1);
      v56 = (unsigned __int8)*(v52 - 40);
      v57 = (_QWORD *)v89[v56];
      *v57 = *(_QWORD *)(v52 - 41);
      v89[v56] = (__int64)(v57 + 1);
      v58 = (unsigned __int8)*(v52 - 32);
      v59 = (_QWORD *)v89[v58];
      *v59 = *(_QWORD *)(v52 - 33);
      v89[v58] = (__int64)(v59 + 1);
      v60 = (unsigned __int8)*(v52 - 24);
      v61 = (_QWORD *)v89[v60];
      *v61 = *(_QWORD *)(v52 - 25);
      v89[v60] = (__int64)(v61 + 1);
      --v53;
    }
    while ( v53 );
    v62 = (char *)&data[2] + 2;
    v63 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
    do
    {
      v64 = (unsigned __int8)*(v62 - 16);
      v62 += 32;
      v65 = (_QWORD *)v88[v64];
      *v65 = *(_QWORD *)(v62 - 50);
      v88[v64] = (__int64)(v65 + 1);
      v66 = (unsigned __int8)*(v62 - 40);
      v67 = (_QWORD *)v88[v66];
      *v67 = *(_QWORD *)(v62 - 42);
      v88[v66] = (__int64)(v67 + 1);
      v68 = (unsigned __int8)*(v62 - 32);
      v69 = (_QWORD *)v88[v68];
      *v69 = *(_QWORD *)(v62 - 34);
      v88[v68] = (__int64)(v69 + 1);
      v70 = (unsigned __int8)*(v62 - 24);
      v71 = (_QWORD *)v88[v70];
      *v71 = *(_QWORD *)(v62 - 26);
      v88[v70] = (__int64)(v71 + 1);
      --v63;
    }
    while ( v63 );
    v72 = (char *)&buffer[2] + 3;
    v73 = ((unsigned __int64)(v5 - 1) >> 2) + 1;
    do
    {
      v74 = (unsigned __int8)*(v72 - 16);
      v72 += 32;
      v75 = (_QWORD *)v90[v74];
      *v75 = *(_QWORD *)(v72 - 51);
      v90[v74] = (__int64)(v75 + 1);
      v76 = (unsigned __int8)*(v72 - 40);
      v77 = (_QWORD *)v90[v76];
      *v77 = *(_QWORD *)(v72 - 43);
      v90[v76] = (__int64)(v77 + 1);
      v78 = (unsigned __int8)*(v72 - 32);
      v79 = (_QWORD *)v90[v78];
      *v79 = *(_QWORD *)(v72 - 35);
      v90[v78] = (__int64)(v79 + 1);
      v80 = (unsigned __int8)*(v72 - 24);
      v81 = (_QWORD *)v90[v80];
      *v81 = *(_QWORD *)(v72 - 27);
      v90[v80] = (__int64)(v81 + 1);
      --v73;
    }
    while ( v73 );
  }
}

