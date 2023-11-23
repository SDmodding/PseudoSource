// File Line: 38
// RVA: 0xBADFE0
void __fastcall hkaNURBS::ApproximateCurve(
        unsigned int numSamples,
        const float *sampleTimes,
        hkVector4f *sampleData,
        int degree,
        __int64 tolerance,
        int *numKnotsOut,
        float *knotsOut,
        int *numPointsOut,
        hkVector4f *pointsOut)
{
  __int64 v9; // rbx
  int v11; // eax
  int v12; // r12d
  __int64 v13; // rdi
  hkaNURBS::Point *v14; // rbx
  int v15; // r14d
  __int64 v16; // rsi
  int v17; // eax
  float *v18; // r13
  int v19; // esi
  unsigned __int64 *v20; // r15
  float *v21; // r12
  __int64 v22; // rsi
  float *v23; // rax
  int v24; // ecx
  int v25; // ecx
  int *v26; // rdx
  int *v27; // rdi
  int v28; // eax
  int v29; // r12d
  hkaNURBS::Point *m_data; // rdi
  int *v31; // r14
  float *v32; // r15
  hkaNURBS::Point *v33; // rbx
  float *v34; // r9
  int v35; // edx
  __int64 v36; // rcx
  char *v37; // r8
  int v38; // eax
  int U; // [rsp+30h] [rbp-61h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P; // [rsp+38h] [rbp-59h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Pa; // [rsp+38h] [rbp-59h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> v42; // [rsp+40h] [rbp-51h] BYREF
  hkArray<float,hkContainerHeapAllocator> v43; // [rsp+50h] [rbp-41h] BYREF
  hkArray<float,hkContainerHeapAllocator> ub; // [rsp+60h] [rbp-31h] BYREF
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> Q; // [rsp+70h] [rbp-21h] BYREF
  int vars0; // [rsp+D0h] [rbp+3Fh] BYREF
  char *retaddr; // [rsp+D8h] [rbp+47h]
  const float *n; // [rsp+E8h] [rbp+57h] BYREF
  __int64 E; // [rsp+F0h] [rbp+5Fh]
  int *v50; // [rsp+F8h] [rbp+67h]

  LODWORD(v50) = degree;
  n = sampleTimes;
  E = v9;
  v11 = numSamples;
  v12 = degree;
  v13 = numSamples;
  if ( numSamples )
  {
    vars0 = 16 * numSamples;
    v14 = (hkaNURBS::Point *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                               &hkContainerHeapAllocator::s_alloc,
                               &vars0);
    v11 = vars0 / 16;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = 0x80000000;
  P = (hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *)v14;
  if ( v11 )
    v15 = v11;
  Q.m_data = v14;
  Q.m_size = v13;
  Q.m_capacityAndFlags = v15;
  if ( (int)v13 > 0 )
  {
    v16 = v13;
    do
    {
      if ( v14 )
        hkaNURBS::Point::Point(v14, 0.0, 0.0, 0.0, 0.0);
      ++v14;
      --v16;
    }
    while ( v16 );
    v14 = (hkaNURBS::Point *)P;
  }
  v17 = v13;
  if ( (_DWORD)v13 )
  {
    vars0 = 4 * v13;
    v18 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &vars0);
    v17 = vars0 / 4;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = 0x80000000;
  ub.m_data = v18;
  if ( v17 )
    v19 = v17;
  ub.m_size = v13;
  vars0 = v19;
  ub.m_capacityAndFlags = v19;
  if ( (int)v13 > 0 )
  {
    v20 = &sampleData->m_quad.m128_u64[1];
    v21 = v18;
    v22 = v13;
    do
    {
      *v21 = *(float *)((char *)v21 + retaddr - (char *)v18);
      *hkaNURBS::Point::operator[](v14, 0) = *((float *)v20 - 2);
      *hkaNURBS::Point::operator[](v14, 1) = *((float *)v20 - 1);
      *hkaNURBS::Point::operator[](v14, 2) = *(float *)v20;
      v23 = hkaNURBS::Point::operator[](v14, 3);
      v24 = *((_DWORD *)v20 + 1);
      ++v14;
      ++v21;
      v20 += 2;
      *(_DWORD *)v23 = v24;
      --v22;
    }
    while ( v22 );
    v19 = vars0;
    v12 = (int)n;
  }
  v42.m_data = 0i64;
  v42.m_size = 0;
  v42.m_capacityAndFlags = 0x80000000;
  v43.m_data = 0i64;
  v43.m_size = 0;
  v43.m_capacityAndFlags = 0x80000000;
  hkaNURBS::GlobalCurveApproxErrBnd(v13 - 1, &Q, &ub, v12, *(float *)&E, (int *)&n, &v43, &v42);
  v25 = (int)n;
  v26 = numKnotsOut;
  v27 = v50;
  *numKnotsOut = (_DWORD)n + 1;
  v28 = v12 + v25 + 2;
  v29 = 0;
  *v27 = v28;
  if ( *v26 > 0 )
  {
    m_data = v42.m_data;
    v31 = v26;
    v32 = knotsOut + 2;
    do
    {
      v33 = &m_data[v29];
      *(v32 - 2) = *hkaNURBS::Point::operator[](v33, 0);
      *(v32 - 1) = *hkaNURBS::Point::operator[](v33, 1);
      *v32 = *hkaNURBS::Point::operator[](v33, 2);
      ++v29;
      v32 += 4;
      *(v32 - 3) = *hkaNURBS::Point::operator[](v33, 3);
    }
    while ( v29 < *v31 );
    v15 = U;
    v27 = v50;
  }
  v34 = v43.m_data;
  v35 = 0;
  if ( *v27 > 0 )
  {
    v36 = tolerance;
    v37 = (char *)v43.m_data - tolerance;
    do
    {
      v38 = *(_DWORD *)&v37[v36];
      ++v35;
      v36 += 4i64;
      *(_DWORD *)(v36 - 4) = v38;
    }
    while ( v35 < *v27 );
  }
  v43.m_size = 0;
  if ( v43.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v34,
      4 * v43.m_capacityAndFlags);
  v43.m_data = 0i64;
  v43.m_capacityAndFlags = 0x80000000;
  v42.m_size = 0;
  if ( v42.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaNURBS::Point *, _QWORD, float *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v42.m_data,
      (unsigned int)(16 * v42.m_capacityAndFlags),
      v34);
  v42.m_data = 0i64;
  v42.m_capacityAndFlags = 0x80000000;
  if ( v19 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, float *, _QWORD, float *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v18,
      (unsigned int)(4 * v19),
      v34);
  if ( v15 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *, _QWORD, float *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      Pa,
      (unsigned int)(16 * v15),
      v34);
}

// File Line: 96
// RVA: 0xBAFAD0
float __fastcall hkaNURBS::FindSpan(int n, int p, float u, hkArray<float,hkContainerHeapAllocator> *U)
{
  float result; // xmm0_4
  float *m_data; // r10
  int v6; // r8d
  int v7; // r9d
  int v8; // eax
  int v9; // eax

  m_data = U->m_data;
  v6 = p;
  if ( u != U->m_data[n + 1] )
  {
    v7 = n + 1;
    v8 = n + 1 + p;
    while ( 1 )
    {
      v9 = v8 / 2;
      result = m_data[v9];
      if ( u < result )
        goto LABEL_7;
      if ( u < m_data[v9 + 1] )
        return result;
      if ( u >= result )
      {
        v6 = v9;
        v8 = v7 + v9;
      }
      else
      {
LABEL_7:
        v7 = v9;
        v8 = v9 + v6;
      }
    }
  }
  return result;
}

// File Line: 121
// RVA: 0xBB0C10
void __fastcall hkaNURBS::BasisFuns(int i, float u, int p, hkArray<float,hkContainerHeapAllocator> *U, float *N)
{
  int v5; // r10d
  __int64 v8; // r11
  float *v9; // r14
  char *v10; // r13
  float *v11; // rdx
  int v12; // r8d
  __int64 v13; // rdi
  float v14; // xmm5_4
  float v15; // xmm1_4
  signed __int64 v16; // r9
  signed __int64 v17; // rsi
  signed __int64 v18; // rbp
  __int64 v19; // rax
  float *v20; // rcx
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm5_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm4_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm4_4
  float v40; // xmm1_4
  float v41; // xmm1_4
  float *v42; // rcx
  float *v43; // rdx
  __int64 v44; // r8
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  float v48; // xmm1_4
  int v49; // [rsp+0h] [rbp-58h] BYREF
  char v50[4]; // [rsp+4h] [rbp-54h] BYREF
  _DWORD v51[2]; // [rsp+8h] [rbp-50h] BYREF
  _DWORD v52[4]; // [rsp+10h] [rbp-48h] BYREF

  v5 = 1;
  *N = 1.0;
  v8 = 1i64;
  if ( p >= 1 )
  {
    v9 = &U->m_data[i];
    v10 = (char *)U->m_data + 4i64 * i + 8 - (_QWORD)v52;
    do
    {
      v11 = (float *)&v51[v8];
      v12 = 0;
      v13 = 0i64;
      v14 = 0.0;
      v15 = *(float *)&v10[(_QWORD)v11];
      v11[2] = u - *v9;
      *(float *)&v50[4 * v8 - 4] = v15 - u;
      if ( v5 >= 4 )
      {
        v16 = v50 - (char *)N;
        v17 = (char *)&v49 - (char *)N;
        v18 = (char *)v51 - (char *)N;
        v19 = ((unsigned int)(v5 - 4) >> 2) + 1;
        v12 = 4 * v19;
        v13 = 4i64 * (unsigned int)v19;
        v20 = N + 2;
        do
        {
          v21 = *(float *)((char *)v20 + v16 - 8);
          v22 = v11[2];
          v23 = *(v20 - 2);
          v20 += 4;
          v24 = v11[1];
          v11 -= 4;
          v25 = v23 / (float)(v21 + v22);
          v26 = v21 * v25;
          v27 = v22 * v25;
          v28 = *(v20 - 5);
          v29 = v26 + v14;
          v30 = v11[3];
          *(v20 - 6) = v29;
          v31 = v28 / (float)(*(float *)((char *)v20 + v17 - 16) + v24);
          v32 = *(float *)((char *)v20 + v17 - 16) * v31;
          v33 = v24 * v31;
          v34 = *(v20 - 4);
          v35 = v32 + v27;
          v36 = v11[4];
          *(v20 - 5) = v35;
          v37 = v34 / (float)(*(float *)((char *)v20 + v16 - 16) + v36);
          v38 = *(float *)((char *)v20 + v16 - 16) * v37;
          v39 = v36 * v37;
          v40 = *(v20 - 3);
          *(v20 - 4) = v38 + v33;
          v41 = v40 / (float)(*(float *)((char *)v20 + v18 - 16) + v30);
          v14 = v30 * v41;
          *(v20 - 3) = (float)(*(float *)((char *)v20 + v18 - 16) * v41) + v39;
          --v19;
        }
        while ( v19 );
      }
      if ( v12 < v5 )
      {
        v42 = &N[v13];
        v43 = (float *)&v52[v8 - v13];
        v44 = (unsigned int)(v5 - v12);
        do
        {
          v45 = *(float *)((char *)v42 + v50 - (char *)N);
          v46 = *v43;
          v47 = *v42++;
          --v43;
          v48 = v47 / (float)(v45 + v46);
          *(v42 - 1) = (float)(v45 * v48) + v14;
          v14 = v46 * v48;
          --v44;
        }
        while ( v44 );
      }
      ++v5;
      N[v8++] = v14;
      --v9;
    }
    while ( v5 <= p );
  }
}

// File Line: 152
// RVA: 0xBB1260
void __fastcall hkaNURBS::DersBasisFuns(
        int i,
        float u,
        int p,
        int n,
        hkArray<float,hkContainerHeapAllocator> *U,
        float (*ders)[4])
{
  __int64 v6; // rdi
  __int64 v8; // rbx
  int v9; // r10d
  float *v10; // r12
  float *v11; // r13
  __int64 v12; // r11
  char *v13; // rdi
  __int64 v14; // rax
  float *v15; // r8
  int v16; // r14d
  __int64 v17; // rsi
  float v18; // xmm4_4
  float v19; // xmm1_4
  char *v20; // rcx
  float *v21; // rdx
  unsigned int v22; // eax
  __int64 v23; // r9
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm1_4
  float *v40; // rdx
  float *v41; // rcx
  float *v42; // r8
  __int64 v43; // r9
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  __int64 v47; // r10
  __int64 v48; // r12
  __int64 v49; // r8
  __int64 v50; // r15
  __int64 v51; // rcx
  unsigned __int64 v52; // r9
  char *v53; // rdx
  int v54; // eax
  int *v55; // rcx
  int v56; // eax
  __int64 v57; // r11
  __int64 v58; // r8
  int v59; // ecx
  int v60; // eax
  int v61; // edx
  __int64 v62; // r9
  __int64 v63; // rsi
  __int64 v64; // r13
  int v65; // r14d
  __int64 v66; // r12
  __int64 v67; // rbx
  int v68; // edx
  __int64 v69; // r10
  __int64 v70; // r11
  float v71; // xmm2_4
  int v72; // xmm2_4
  __int64 v73; // r10
  int v74; // eax
  __int64 v75; // r9
  __int64 v76; // rdx
  char *v77; // r8
  char *v78; // r11
  __int64 v79; // rcx
  char *v80; // r14
  __int64 v81; // rax
  char *v82; // r13
  __int64 v83; // rax
  char *v84; // r15
  char *v85; // rdi
  char *v86; // r12
  char *v87; // rdx
  char *v88; // rcx
  char *v89; // rsi
  unsigned __int64 v90; // rax
  float v91; // xmm0_4
  float v92; // xmm0_4
  float v93; // xmm2_4
  float v94; // xmm1_4
  float v95; // xmm2_4
  float v96; // xmm0_4
  float v97; // xmm0_4
  float v98; // xmm1_4
  float *v99; // rcx
  float *v100; // rdx
  __int64 v101; // r9
  float v102; // xmm0_4
  float v103; // xmm0_4
  bool v104; // cc
  int v105; // xmm0_4
  __int64 v106; // r10
  int v107; // eax
  __int64 v108; // r9
  __int64 v109; // rcx
  signed int v110; // r11d
  __int64 v111; // rbx
  unsigned int v112; // r14d
  int v113; // edi
  __int64 v114; // r9
  __int64 v115; // rsi
  __int64 v116; // rdx
  int v117; // r8d
  int v118; // r10d
  __m128 v119; // xmm1
  int v120; // eax
  __int64 v121; // rcx
  unsigned __int64 v122; // rax
  float v123; // xmm2_4
  float v124; // xmm1_4
  float v125; // xmm1_4
  __int64 v126; // rcx
  __int64 v127; // rax
  int v128; // [rsp+0h] [rbp-C8h]
  int v129; // [rsp+4h] [rbp-C4h]
  int v130; // [rsp+8h] [rbp-C0h]
  int v131; // [rsp+Ch] [rbp-BCh]
  int v132; // [rsp+10h] [rbp-B8h]
  int v133; // [rsp+14h] [rbp-B4h]
  __int64 v134; // [rsp+18h] [rbp-B0h]
  __int64 v135; // [rsp+18h] [rbp-B0h]
  __int64 v136; // [rsp+20h] [rbp-A8h]
  __int64 v137; // [rsp+28h] [rbp-A0h]
  __int64 v138; // [rsp+30h] [rbp-98h]
  int v139[4]; // [rsp+38h] [rbp-90h] BYREF
  __int64 v140; // [rsp+48h] [rbp-80h]
  __int64 v141; // [rsp+50h] [rbp-78h] BYREF
  __int64 v142; // [rsp+58h] [rbp-70h] BYREF
  __int64 v143; // [rsp+60h] [rbp-68h] BYREF
  __int64 v144; // [rsp+68h] [rbp-60h]
  __int64 v145; // [rsp+70h] [rbp-58h]
  __int64 v146[2]; // [rsp+78h] [rbp-50h] BYREF
  int v147; // [rsp+88h] [rbp-40h] BYREF
  char v148[44]; // [rsp+8Ch] [rbp-3Ch] BYREF
  __int64 v149; // [rsp+B8h] [rbp-10h]
  __int64 v150; // [rsp+C0h] [rbp-8h]
  __int64 v151; // [rsp+C8h] [rbp+0h]
  __int64 v152; // [rsp+D0h] [rbp+8h]
  __int64 v153; // [rsp+D8h] [rbp+10h]
  __int64 v154; // [rsp+E0h] [rbp+18h]
  __int64 v155; // [rsp+E8h] [rbp+20h]
  __int64 v156; // [rsp+F0h] [rbp+28h]
  int v157; // [rsp+148h] [rbp+80h]
  int v158; // [rsp+150h] [rbp+88h]
  _QWORD *v159; // [rsp+158h] [rbp+90h]
  __int64 vars0; // [rsp+160h] [rbp+98h]

  v6 = 1i64;
  v8 = 1i64;
  LODWORD(v146[0]) = 1065353216;
  v9 = 1;
  if ( p >= 1 )
  {
    v10 = (float *)v148;
    v11 = (float *)(*v159 + 4i64 * i);
    v12 = -52i64;
    v13 = v148;
    v14 = *v159 + 4i64 * i + 8 - (_QWORD)&v143;
    v134 = v14;
    do
    {
      v15 = (float *)&v142 + v8;
      v16 = 0;
      v17 = 0i64;
      v18 = 0.0;
      v19 = *(float *)((char *)v15 + v14);
      v15[2] = u - *v11;
      *((float *)&v141 + v8) = v19 - u;
      if ( v9 >= 4 )
      {
        v20 = v13;
        v21 = (float *)v146 + v8;
        v22 = ((unsigned int)(v9 - 4) >> 2) + 1;
        v23 = v22;
        v16 = 4 * v22;
        v17 = 4i64 * v22;
        do
        {
          v24 = *(float *)&v20[v12 - 4];
          v25 = v15[2];
          v21 += 16;
          v15 -= 4;
          v20 += 16;
          *((float *)v20 - 5) = v24 + v25;
          v26 = *(v21 - 17) / (float)(v24 + v25);
          v27 = v25 * v26;
          v28 = (float)(v24 * v26) + v18;
          v29 = v15[5];
          *(v21 - 16) = v28;
          v30 = *(float *)&v20[v12 - 16];
          *((float *)v20 - 4) = v29 + v30;
          v31 = *(v21 - 13) / (float)(v29 + v30);
          v32 = (float)(v30 * v31) + v27;
          v33 = v15[4];
          v34 = v33 + *(float *)&v20[v12 - 12];
          *(v21 - 12) = v32;
          *((float *)v20 - 3) = v34;
          v35 = v33 * (float)(*(v21 - 9) / v34);
          v36 = *(float *)&v20[v12 - 8];
          v37 = (float)((float)(*(v21 - 9) / v34) * *(float *)&v20[v12 - 12]) + (float)(v29 * v31);
          v38 = v15[3];
          *(v21 - 8) = v37;
          *((float *)v20 - 2) = v38 + v36;
          v39 = *(v21 - 5) / (float)(v38 + v36);
          v18 = v38 * v39;
          *(v21 - 4) = (float)(v36 * v39) + v35;
          --v23;
        }
        while ( v23 );
      }
      if ( v16 < v9 )
      {
        v40 = (float *)&v146[2 * v17] + v8;
        v41 = (float *)&v141 + v17 + 1;
        v42 = (float *)&v143 + v8 - v17;
        v43 = (unsigned int)(v9 - v16);
        do
        {
          v44 = *v42;
          v45 = *v41;
          v40 += 4;
          --v42;
          *(float *)((char *)++v41 + v13 - (char *)&v142 - 4) = v44 + v45;
          v46 = *(v40 - 5) / (float)(v44 + v45);
          *(v40 - 4) = (float)(v45 * v46) + v18;
          v18 = v44 * v46;
          --v43;
        }
        while ( v43 );
      }
      v14 = v134;
      ++v9;
      *v10 = v18;
      ++v8;
      --v11;
      v13 += 16;
      v12 -= 16i64;
      v10 += 5;
    }
    while ( v9 <= v157 );
    v6 = 1i64;
  }
  v47 = v157;
  v48 = vars0;
  v49 = 0i64;
  v50 = v157;
  v153 = v157;
  if ( v157 >= 0 )
  {
    if ( v157 + 1i64 >= 4 )
    {
      v51 = vars0 + 8;
      v52 = (unsigned __int64)(v157 + 1i64) >> 2;
      v53 = &v148[4 * v157 - 4];
      v49 = 4 * v52;
      do
      {
        v54 = *((_DWORD *)v53 - 4);
        v51 += 16i64;
        v53 += 64;
        *(_DWORD *)(v51 - 24) = v54;
        *(_DWORD *)(v51 - 20) = *((_DWORD *)v53 - 16);
        *(_DWORD *)(v51 - 16) = *((_DWORD *)v53 - 12);
        *(_DWORD *)(v51 - 12) = *((_DWORD *)v53 - 8);
        --v52;
      }
      while ( v52 );
    }
    if ( v49 <= v47 )
    {
      v55 = (int *)&v146[2 * v49] + v47;
      do
      {
        v56 = *v55;
        ++v49;
        v55 += 4;
        *(_DWORD *)(v48 + 4 * v49 - 4) = v56;
      }
      while ( v49 <= v47 );
    }
    if ( (int)v47 >= 0 )
    {
      v57 = 0i64;
      v150 = v48 + 16 + 4 * v47;
      v58 = -v47;
      v59 = -(int)v47;
      v60 = v47;
      v138 = 0i64;
      v137 = -v47;
      v128 = -(int)v47;
      v154 = -v47;
      v61 = v158;
      v129 = v47;
      v62 = 1i64;
      v135 = 1i64;
      do
      {
        v63 = 0i64;
        v133 = 0;
        v132 = 1;
        v64 = 1i64;
        v143 = 1i64;
        v139[0] = 1065353216;
        v145 = 0i64;
        v65 = 1;
        v131 = 1;
        v140 = 1i64;
        if ( v61 >= 1 )
        {
          v66 = 4 * v50 - 4;
          v67 = v50 - 1;
          v68 = v47 - 1;
          v130 = v47 - 1;
          v69 = v57 + 4 * v154;
          v142 = v66;
          v144 = v62;
          v141 = v69;
          v146[0] = v69 + v150;
          v136 = 16 * v50 - 16;
          do
          {
            v70 = v58 + v50;
            v71 = 0.0;
            v143 = v58 + v50;
            if ( v58 + v50 >= v6 )
            {
              v59 = v128;
              *(float *)&v72 = *(float *)&v139[4 * v63] / *(float *)&v148[4 * v58 - 4 + 4 * v66 + 4 * v67];
              v139[4 * v64] = v72;
              v71 = *(float *)&v72 * *((float *)v146 + v69 + v66 + v67);
            }
            v73 = v62;
            if ( v68 + v59 >= -1 )
              v73 = 1i64;
            v74 = v65 - 1;
            if ( v59 + v157 - 1 > v68 )
              v74 = v129;
            v75 = v74;
            if ( v73 <= v74 )
            {
              if ( v74 - v73 + 1 >= 4 )
              {
                v76 = v67 + v58;
                v77 = &v148[4 * v73 - 4 + 4 * v66 + 4 * v67 + 4 * v58];
                v78 = &v148[16 * v76 - 4 + 16 * v73 + 4 * v67];
                v79 = 4 * (4 * (v63 - v67) - v76) - (_QWORD)&v147;
                v80 = (char *)v139 + v79;
                v81 = 4 * (v64 - v67);
                v151 = (__int64)&v139[3] + v79;
                v82 = (char *)&v139[3] + v79;
                v83 = 4 * (v81 - v76) - (_QWORD)&v147;
                v152 = (__int64)v139 + v83;
                v156 = (__int64)&v139[2] + v83;
                v84 = (char *)v139 + v83;
                v85 = (char *)&v139[2] + v83;
                v149 = (__int64)&v139[1] + v83;
                v86 = (char *)&v139[1] + v83;
                v87 = (char *)&v139[1] + v79;
                v88 = (char *)&v139[2] + v79;
                v155 = (__int64)&v139[3] + v83;
                v89 = (char *)&v139[3] + v83;
                v90 = ((unsigned __int64)(v75 - v73 - 3) >> 2) + 1;
                v73 += 4 * v90;
                do
                {
                  v91 = *(float *)&v77[(_QWORD)v80];
                  v78 += 64;
                  v77 += 16;
                  v92 = (float)(v91 - *(float *)&v77[(_QWORD)v80 - 20]) / *((float *)v77 - 4);
                  *(float *)&v77[(_QWORD)v84 - 16] = v92;
                  v93 = v71 + (float)(v92 * *((float *)v78 - 20));
                  v94 = (float)(*(float *)&v77[(_QWORD)v87 - 16] - *(float *)&v77[(_QWORD)v80 - 16])
                      / *((float *)v77 - 3);
                  *(float *)&v77[(_QWORD)v86 - 16] = v94;
                  v95 = v93 + (float)(v94 * *((float *)v78 - 16));
                  v96 = (float)(*(float *)&v77[(_QWORD)v88 - 16] - *(float *)&v77[(_QWORD)v87 - 16])
                      / *((float *)v77 - 2);
                  *(float *)&v77[(_QWORD)v85 - 16] = v96;
                  v97 = v96 * *((float *)v78 - 12);
                  v98 = (float)(*(float *)&v77[(_QWORD)v82 - 16] - *(float *)&v77[(_QWORD)v88 - 16])
                      / *((float *)v77 - 1);
                  *(float *)&v77[(_QWORD)v89 - 16] = v98;
                  v71 = (float)(v95 + v97) + (float)(v98 * *((float *)v78 - 8));
                  --v90;
                }
                while ( v90 );
                v6 = v140;
                v63 = v145;
                v50 = v153;
                v64 = v143;
                v70 = v143;
                v66 = v142;
                v65 = v131;
              }
              if ( v73 <= v75 )
              {
                v99 = (float *)&v139[4 * v63 + v73];
                v100 = (float *)&v146[2 * v73 + 2 * (v70 - v6)] + v67;
                v101 = v75 - v73 + 1;
                do
                {
                  v102 = *v99;
                  v100 += 4;
                  ++v99;
                  v103 = (float)(v102 - *(v99 - 2))
                       / *(float *)&v148[4 * (v70 + 4 * (v67 - v63) - v6) - (_QWORD)v139 - 8 + (_QWORD)v99];
                  v99[4 * (v64 - v63) - 1] = v103;
                  v71 = v71 + (float)(v103 * *(v100 - 4));
                  --v101;
                }
                while ( v101 );
              }
            }
            v104 = v70 <= v67;
            v57 = v138;
            if ( v104 )
            {
              *(float *)&v105 = (float)(-1.0 / *(float *)&v148[v138 - 4 + v136]) * *(float *)&v139[4 * v63 - 1 + v6];
              v139[4 * v64 + v6] = v105;
              v71 = v71 + (float)(*(float *)&v105 * *((float *)v146 + v67 + v57));
            }
            v106 = v146[0];
            v107 = v133;
            v108 = v144;
            v136 -= 16i64;
            v58 = v137;
            *(float *)v146[0] = v71;
            v109 = v63;
            v133 = v132;
            ++v65;
            ++v6;
            v62 = v108 + 1;
            v66 -= 4i64;
            v68 = v130 - 1;
            v63 = v64;
            v145 = v64;
            --v67;
            v143 = v109;
            v146[0] = v106 + 16;
            v69 = v141;
            v64 = v109;
            v59 = v128;
            --v130;
            v132 = v107;
            v131 = v65;
            v140 = v6;
            v144 = v62;
            v142 = v66;
          }
          while ( v65 <= v158 );
          v60 = v129;
          LODWORD(v47) = v157;
          v61 = v158;
          v62 = v135;
        }
        ++v58;
        ++v59;
        v129 = v60 - 1;
        --v62;
        v57 += 4i64;
        --v60;
        v128 = v59;
        v135 = v62;
        v137 = v58;
        v138 = v57;
        v6 = 1i64;
      }
      while ( v58 + v50 <= v50 );
      v48 = vars0;
    }
  }
  v110 = v47;
  if ( v158 >= 1 )
  {
    v111 = 4i64;
    v112 = v47 + 1;
    v113 = v47 - 1;
    v114 = 4i64;
    v115 = (unsigned int)v158;
    do
    {
      v116 = 0i64;
      if ( (int)v47 >= 0 && v112 >= 8 )
      {
        v117 = 0;
        v118 = v47 - (int)v112 % 8;
        v119 = _mm_cvtepi32_ps(_mm_shuffle_epi32(_mm_cvtsi32_si128(v110), 0));
        do
        {
          v116 += 8i64;
          *(__m128 *)(v48 + 4 * (v114 + v117)) = _mm_mul_ps(*(__m128 *)(v48 + 4 * (v114 + v117)), v119);
          v120 = v117 + 4;
          v117 += 8;
          *(__m128 *)(v48 + 4 * (v114 + v120)) = _mm_mul_ps(*(__m128 *)(v48 + 4 * (v114 + v120)), v119);
        }
        while ( v117 <= v118 );
        LODWORD(v47) = v157;
      }
      if ( v116 <= v50 )
      {
        if ( v50 - v116 + 1 >= 4 )
        {
          v121 = v48 + 4 * (v116 + v111);
          v122 = ((unsigned __int64)(v50 - v116 - 3) >> 2) + 1;
          v123 = (float)v110;
          v116 += 4 * v122;
          do
          {
            v121 += 16i64;
            v124 = v123 * *(float *)(v121 - 12);
            *(float *)(v121 - 16) = v123 * *(float *)(v121 - 16);
            *(float *)(v121 - 12) = v124;
            v125 = v123 * *(float *)(v121 - 4);
            *(float *)(v121 - 8) = v123 * *(float *)(v121 - 8);
            *(float *)(v121 - 4) = v125;
            --v122;
          }
          while ( v122 );
        }
        if ( v116 <= v50 )
        {
          v126 = v48 + 4 * (v116 + v111);
          v127 = v50 - v116 + 1;
          do
          {
            v126 += 4i64;
            *(float *)(v126 - 4) = (float)v110 * *(float *)(v126 - 4);
            --v127;
          }
          while ( v127 );
        }
      }
      v110 *= v113;
      v114 += 4i64;
      v111 += 4i64;
      --v113;
      --v115;
    }
    while ( v115 );
  }
}      }
      v110 *= v113;
      v114 += 4i64;
      v111 += 4i64;
      --v113;
      --v115;
    }
    while ( v115 );
  }
}

// File Line: 233
// RVA: 0xBB0E60
float __fastcall hkaNURBS::OneBasisFun(int p, int m, hkArray<float,hkContainerHeapAllocator> *U, int i, float u)
{
  __int64 v5; // rdi
  __int64 v7; // rbx
  float *m_data; // r12
  unsigned __int64 v9; // r9
  float v10; // xmm7_4
  __int64 v11; // r11
  __int64 v12; // rcx
  float *v13; // rdx
  __int64 v14; // r14
  __int64 v15; // r10
  char *v16; // r8
  __int64 v17; // r15
  float *v18; // r13
  float v19; // xmm1_4
  int v20; // esi
  __int64 v21; // rbp
  float *v22; // rdx
  float *v23; // r9
  __int64 v24; // rax
  char *v25; // r11
  char *v26; // rbx
  __int64 v27; // rcx
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm3_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm4_4
  float v38; // xmm4_4
  float v39; // xmm3_4
  float v40; // xmm5_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm4_4
  float v44; // xmm5_4
  float v45; // xmm1_4
  float v46; // xmm4_4
  float *v47; // rdx
  __int64 v48; // r9
  float *v49; // rcx
  float v50; // xmm4_4
  float v51; // xmm5_4
  float v52; // xmm3_4
  float v53; // xmm4_4
  char *v54; // [rsp+0h] [rbp-78h]
  float *v55; // [rsp+8h] [rbp-70h]
  __int64 v56; // [rsp+10h] [rbp-68h]
  __int64 v57; // [rsp+18h] [rbp-60h]
  float v58; // [rsp+20h] [rbp-58h] BYREF
  char v59[12]; // [rsp+24h] [rbp-54h] BYREF

  v5 = p;
  if ( !i && u == *U->m_data || i == m - p - 1 && u == U->m_data[m] )
    return *(float *)&FLOAT_1_0;
  v7 = i;
  m_data = U->m_data;
  v9 = 4i64 * i;
  v57 = v7;
  v55 = U->m_data;
  v10 = U->m_data[v9 / 4];
  if ( u < v10 )
    return 0.0;
  v11 = p;
  v56 = p;
  if ( u >= m_data[p + 1 + v7] )
    return 0.0;
  v12 = 0i64;
  if ( (int)v5 >= 0 )
  {
    v13 = &m_data[v9 / 4 + 1];
    do
    {
      if ( u < *(float *)&v59[(_QWORD)&m_data[v12] + v9 - (_QWORD)&v58 - 4] || u >= *v13 )
        *(float *)&v59[4 * v12 - 4] = 0.0;
      else
        *(float *)&v59[4 * v12 - 4] = 1.0;
      ++v12;
      ++v13;
    }
    while ( v12 <= v5 );
  }
  v14 = 1i64;
  if ( v5 >= 1 )
  {
    v15 = 0x3FFFFFFFFFFFFFFFi64;
    v16 = (char *)(&v59[-v9] - (char *)m_data);
    v17 = 1i64;
    v18 = &m_data[v7 + 2];
    v54 = (char *)m_data + v9 - (_QWORD)v59;
    do
    {
      if ( v58 == 0.0 )
        v19 = 0.0;
      else
        v19 = (float)((float)(u - v10) * v58) / (float)(*(v18 - 1) - v10);
      v20 = 0;
      v21 = 0i64;
      if ( (int)v5 >= 4 )
      {
        v22 = v18 + 1;
        v23 = v18;
        v24 = -4 * (v14 + v7 + 2) - (_QWORD)m_data;
        v25 = &v59[v24];
        v26 = &v59[v24 - 4];
        LODWORD(v24) = ((unsigned int)(v5 - 4) >> 2) + 1;
        v27 = (unsigned int)v24;
        v20 = 4 * v24;
        v21 = 4i64 * (unsigned int)v24;
        do
        {
          v28 = *(float *)&v25[(_QWORD)v22];
          v29 = v23[v15];
          v30 = *v23;
          if ( v28 == 0.0 )
          {
            *(float *)&v26[(_QWORD)v22] = v19;
            v31 = 0.0;
          }
          else
          {
            v32 = v28 / (float)(v30 - v29);
            *(float *)&v26[(_QWORD)v22] = (float)((float)(v30 - u) * v32) + v19;
            v31 = (float)(u - v29) * v32;
          }
          v33 = *(float *)&v16[(_QWORD)v22 - 8];
          v34 = v22[v15];
          v35 = *v22;
          if ( v33 == 0.0 )
          {
            *(float *)&v25[(_QWORD)v22] = v31;
            v36 = 0.0;
          }
          else
          {
            v37 = v33 / (float)(v35 - v34);
            *(float *)&v25[(_QWORD)v22] = (float)((float)(v35 - u) * v37) + v31;
            v36 = (float)(u - v34) * v37;
          }
          v38 = *(float *)&v16[(_QWORD)v22 - 4];
          v39 = v22[1];
          v40 = *(float *)&v54[(_QWORD)v22 + (unsigned __int64)v16];
          if ( v38 == 0.0 )
          {
            *(float *)&v16[(_QWORD)v22 - 8] = v36;
            v41 = 0.0;
          }
          else
          {
            v42 = v38 / (float)(v39 - v40);
            *(float *)&v16[(_QWORD)v22 - 8] = (float)((float)(v39 - u) * v42) + v36;
            v41 = (float)(u - v40) * v42;
          }
          v43 = *(float *)&v16[(_QWORD)v22];
          v44 = v22[v17];
          v45 = v22[2];
          if ( v43 == 0.0 )
          {
            *(float *)&v16[(_QWORD)v22 - 4] = v41;
            v19 = 0.0;
          }
          else
          {
            v46 = v43 / (float)(v45 - v44);
            *(float *)&v16[(_QWORD)v22 - 4] = (float)((float)(v45 - u) * v46) + v41;
            v19 = (float)(u - v44) * v46;
          }
          v23 += 4;
          v22 += 4;
          --v27;
        }
        while ( v27 );
        m_data = v55;
        v11 = v56;
        v7 = v57;
      }
      if ( v20 < (int)v5 )
      {
        v47 = (float *)&v59[4 * v21 - 4];
        v48 = (unsigned int)(v5 - v20);
        v49 = &m_data[v14 + 1 + v7 + v21];
        do
        {
          v50 = v47[1];
          v51 = v49[v15];
          v52 = *v49;
          if ( v50 == 0.0 )
          {
            *v47 = v19;
            v19 = 0.0;
          }
          else
          {
            v53 = v50 / (float)(v52 - v51);
            *v47 = (float)((float)(v52 - u) * v53) + v19;
            v19 = (float)(u - v51) * v53;
          }
          ++v49;
          ++v47;
          --v48;
        }
        while ( v48 );
      }
      ++v14;
      LODWORD(v5) = v5 - 1;
      v16 -= 4;
      ++v18;
      --v17;
      --v15;
    }
    while ( v14 <= v11 );
  }
  return v58;
}

// File Line: 290
// RVA: 0xBB43A0
void __fastcall hkaNURBS::CurveDerivs(
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        float u,
        int d,
        hkaNURBS::Point *CK)
{
  int v7; // r10d
  int v8; // esi
  int v11; // edi
  hkaNURBS::Point *v13; // rbx
  __int64 v14; // rdi
  hkaNURBS::Point *v15; // rax
  int v16; // eax
  __int64 v17; // rbx
  int v18; // r15d
  float *v19; // rbp
  __int64 v20; // r12
  hkaNURBS::Point *v21; // r14
  hkaNURBS::Point *v22; // rax
  int v23; // ebx
  float *v24; // rdi
  __int64 v25; // rsi
  hkaNURBS::Point *v26; // rax
  hkaNURBS::Point v27; // [rsp+30h] [rbp-A8h] BYREF
  hkaNURBS::Point v28; // [rsp+40h] [rbp-98h] BYREF
  hkaNURBS::Point result; // [rsp+50h] [rbp-88h] BYREF
  float ders[5][4]; // [rsp+60h] [rbp-78h] BYREF
  int da; // [rsp+108h] [rbp+30h]

  v7 = p + 1;
  v8 = p;
  if ( d < p )
    v8 = d;
  v11 = p;
  if ( v7 <= d )
  {
    v13 = &CK[v7];
    v14 = (unsigned int)(d - p);
    do
    {
      hkaNURBS::Point::Point(&v27, 0.0, 0.0, 0.0, 0.0);
      hkaNURBS::Point::operator=(v13++, v15);
      --v14;
    }
    while ( v14 );
    v11 = p;
  }
  hkaNURBS::FindSpan(n, v11, u, U);
  da = v16;
  hkaNURBS::DersBasisFuns(v16, u, v11, v8, U, ders);
  v17 = v11;
  v18 = 0;
  *(_QWORD *)v27.point = v11;
  if ( v8 >= 0 )
  {
    v19 = ders[0];
    v20 = v8 + 1i64;
    do
    {
      v21 = &CK[v18];
      hkaNURBS::Point::Point(&v28, 0.0, 0.0, 0.0, 0.0);
      hkaNURBS::Point::operator=(v21, v22);
      if ( v17 >= 0 )
      {
        v23 = da - v11;
        v24 = v19;
        v25 = *(_QWORD *)v27.point + 1i64;
        do
        {
          v26 = operator*(&result, *v24, &P->m_data[v23]);
          hkaNURBS::Point::operator+=(v21, v26);
          ++v23;
          ++v24;
          --v25;
        }
        while ( v25 );
        v11 = p;
        v17 = *(_QWORD *)v27.point;
      }
      ++v18;
      v19 += 4;
      --v20;
    }
    while ( v20 );
  }
}

// File Line: 323
// RVA: 0xBAF910
hkaNURBS::Point *__fastcall hkaNURBS::CurvePoint(
        hkaNURBS::Point *result,
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        float u)
{
  __int64 v6; // rdi
  int Span; // r15d
  int v10; // r15d
  __int64 v11; // rbx
  __int64 v12; // r14
  int v13; // edi
  hkaNURBS::Point *v14; // rax
  float d[4]; // [rsp+30h] [rbp-38h] BYREF
  hkaNURBS::Point resulta; // [rsp+40h] [rbp-28h] BYREF

  v6 = p;
  Span = hkaNURBS::FindSpan(n, p, u, U);
  hkaNURBS::BasisFuns(Span, u, v6, U, d);
  v10 = Span - v6;
  operator*(result, d[0], &P->m_data[v10]);
  v11 = 1i64;
  v12 = v6;
  if ( v6 >= 1 )
  {
    v13 = v10 + 1;
    do
    {
      v14 = operator*(&resulta, d[v11], &P->m_data[v13]);
      hkaNURBS::Point::operator+=(result, v14);
      ++v11;
      ++v13;
    }
    while ( v11 <= v12 );
  }
  return result;
}

// File Line: 355
// RVA: 0xBAFA00
void __fastcall hkaNURBS::CurvePoint(
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        int mb,
        hkArray<float,hkContainerHeapAllocator> *ub,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Cb)
{
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rsi
  hkaNURBS::Point *v14; // rax
  hkaNURBS::Point result; // [rsp+30h] [rbp-38h] BYREF

  if ( mb >= 0 )
  {
    v11 = 0i64;
    v12 = 0i64;
    v13 = (unsigned int)(mb + 1);
    do
    {
      v14 = hkaNURBS::CurvePoint(&result, n, p, U, P, ub->m_data[v11]);
      hkaNURBS::Point::operator=(&Cb->m_data[v12++], v14);
      ++v11;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 369
// RVA: 0xBB2820
__int64 __fastcall hkaNURBS::RemoveCurveKnot(
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Pw,
        float u,
        int r,
        int s,
        int num,
        float TOL)
{
  int v10; // r15d
  int v11; // r13d
  hkaNURBS::Point *v13; // rdi
  int v14; // esi
  int v15; // ebx
  int v16; // esi
  float v17; // xmm9_4
  int v18; // edi
  int v19; // r15d
  int v20; // ecx
  int v21; // ebx
  __int64 v22; // r10
  int v23; // ecx
  int v24; // r8d
  float *v25; // rcx
  int v26; // r12d
  float *v27; // rdx
  int v28; // r14d
  __int64 v29; // r13
  float *v30; // rcx
  float v31; // xmm6_4
  float v32; // xmm7_4
  hkaNURBS::Point *v33; // rax
  hkaNURBS::Point *v34; // rax
  hkaNURBS::Point *v35; // rax
  hkaNURBS::Point *v36; // rax
  hkaNURBS::Point *v37; // rax
  hkaNURBS::Point *v38; // rax
  hkaNURBS::Point *v39; // rdx
  hkaNURBS::Point *v40; // rcx
  float v41; // xmm6_4
  hkaNURBS::Point *v42; // rbx
  hkaNURBS::Point *v43; // rax
  int v44; // eax
  int v45; // edi
  int v46; // ebx
  __int64 v47; // r9
  __int64 v48; // r8
  unsigned __int64 v49; // r11
  __int64 v50; // rdx
  __int64 v51; // rax
  float v52; // r8d
  float v53; // ecx
  __int64 v54; // rbx
  __int64 v55; // rdi
  __int64 v56; // r15
  int v57; // r15d
  int v58; // eax
  int v59; // eax
  int v60; // r9d
  __int64 m_size; // rax
  hkaNURBS::Point *v62; // rbx
  __int64 v63; // rdi
  int v64; // ebx
  int v65; // ecx
  int v66; // ecx
  int v67; // r9d
  int v69; // [rsp+30h] [rbp-90h]
  int v70; // [rsp+34h] [rbp-8Ch]
  int v71; // [rsp+3Ch] [rbp-84h]
  int v72; // [rsp+40h] [rbp-80h]
  __int64 v73; // [rsp+40h] [rbp-80h]
  float *v74; // [rsp+48h] [rbp-78h]
  __int64 v75; // [rsp+50h] [rbp-70h]
  __int64 v76; // [rsp+58h] [rbp-68h]
  hkaNURBS::Point *m_data; // [rsp+60h] [rbp-60h]
  __int64 v78; // [rsp+68h] [rbp-58h]
  hkaNURBS::Point v79[7]; // [rsp+70h] [rbp-50h] BYREF
  hkaNURBS::Point v80; // [rsp+E0h] [rbp+20h] BYREF
  hkaNURBS::Point v81; // [rsp+F0h] [rbp+30h] BYREF
  hkaNURBS::Point v82; // [rsp+100h] [rbp+40h] BYREF
  hkaNURBS::Point v83; // [rsp+110h] [rbp+50h] BYREF
  hkaNURBS::Point v84; // [rsp+120h] [rbp+60h] BYREF
  hkaNURBS::Point v85; // [rsp+130h] [rbp+70h] BYREF
  hkaNURBS::Point v86; // [rsp+140h] [rbp+80h] BYREF
  hkaNURBS::Point result; // [rsp+150h] [rbp+90h] BYREF
  hkaNURBS::Point v88; // [rsp+160h] [rbp+A0h] BYREF
  int v89; // [rsp+220h] [rbp+160h]
  int v90; // [rsp+228h] [rbp+168h]
  hkArray<float,hkContainerHeapAllocator> *v91; // [rsp+230h] [rbp+170h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v92; // [rsp+238h] [rbp+178h]
  float v93; // [rsp+240h] [rbp+180h]
  hkResult v94; // [rsp+248h] [rbp+188h] BYREF
  int vars0; // [rsp+250h] [rbp+190h]
  void *retaddr; // [rsp+258h] [rbp+198h]

  v10 = p + 1;
  v11 = v94.m_enum - vars0;
  v13 = v79;
  v14 = 6;
  v15 = v94.m_enum - p;
  v69 = v94.m_enum - p;
  LODWORD(v79[0].point[2]) = (2 * v94.m_enum - p - vars0) / 2;
  do
  {
    hkaNURBS::Point::Point(v13++, 0.0, 0.0, 0.0, 0.0);
    --v14;
  }
  while ( v14 >= 0 );
  v16 = 0;
  v74 = 0i64;
  v78 = v11;
  v76 = v10;
  if ( (int)retaddr <= 0 )
    return 0i64;
  v17 = v93;
  v18 = 1;
  v75 = 4i64 * v10;
  v19 = 1 - v15;
  v20 = v15 - 1;
  v70 = v15 - 1;
  v72 = 1 - v15;
  LODWORD(v79[0].point[0]) = v94.m_enum - v11 - vars0 + 1;
  do
  {
    m_data = Pw->m_data;
    hkaNURBS::Point::operator=(v79, &Pw->m_data[v20]);
    v21 = v11 - v70;
    hkaNURBS::Point::operator=(&v79[v11 - v70 + 1], &Pw->m_data[v11 + LODWORD(v79[0].point[0])]);
    v90 = v69;
    v22 = v76;
    v23 = v11;
    v24 = 1;
    vars0 = 1;
    LODWORD(v79[0].point[1]) = v11 - v69;
    if ( v11 - v69 > v16 )
    {
      v25 = U->m_data;
      v26 = v90;
      v27 = &v25[v76];
      v28 = v11;
      v71 = v21 + 1;
      v74 = v27;
      v29 = v76;
      v30 = &v25[v78 - (_QWORD)v27];
      v75 = (__int64)v30;
      do
      {
        v31 = (float)(v17 - *v27) / (float)(*(float *)((char *)v27 + v75) - *v27);
        v32 = (float)(v17 - *v30) / (float)(*(float *)((char *)v30 + v75) - *v30);
        v33 = operator*(&result, 1.0 - v31, &v79[v18 - 1]);
        v34 = hkaNURBS::Point::operator-(&m_data[v26], &v88, v33);
        v35 = hkaNURBS::Point::operator/(v34, &v85, v31);
        hkaNURBS::Point::operator=(&v79[v18], v35);
        v36 = operator*(&v83, v32, &v79[v71]);
        v37 = hkaNURBS::Point::operator-(&m_data[v28], &v80, v36);
        v38 = hkaNURBS::Point::operator/(v37, &v81, 1.0 - v32);
        hkaNURBS::Point::operator=(&v79[v21], v38);
        --v71;
        --v28;
        ++v26;
        v27 = v74 + 1;
        v30 = (float *)(v75 - 4);
        ++v29;
        ++v18;
        --v21;
        ++v74;
        v75 -= 4i64;
      }
      while ( v28 - v26 > v16 );
      v19 = v72;
      v73 = v29;
      v11 = HIDWORD(v29);
      v22 = v73;
      vars0 = v18;
      v23 = v28;
      v24 = v18;
      Pw = v92;
      v90 = v26;
      U = v91;
      v18 = 1;
    }
    if ( v23 - v90 >= v16 )
    {
      v41 = (float)(v17 - U->m_data[v22]) / (float)(U->m_data[(_QWORD)v74 + v76 + v22] - U->m_data[v22]);
      v42 = operator*(&v82, 1.0 - v41, &v79[v24 - 1]);
      v43 = operator*(&v84, v41, &v79[v16 + 1 + vars0]);
      v39 = hkaNURBS::Point::operator+(v43, &v86, v42);
      v40 = &Pw->m_data[v90];
    }
    else
    {
      v39 = &v79[v21 + 1];
      v40 = &v79[v24 - 1];
    }
    if ( hkaNURBS::Distance3D(v40, v39) > *(float *)&n )
      break;
    v44 = v69;
    v45 = v11;
    v46 = v69;
    if ( SLODWORD(v79[0].point[1]) > v16 )
    {
      do
      {
        hkaNURBS::Point::operator=(&Pw->m_data[v46], &v79[v19 + v46]);
        hkaNURBS::Point::operator=(&Pw->m_data[v45], &v79[v19 + v45]);
        --v45;
        ++v46;
      }
      while ( v45 - v46 > v16 );
      v44 = v69;
    }
    --v76;
    ++v78;
    v75 += 4i64;
    v69 = v44 - 1;
    v20 = v70 - 1;
    ++v19;
    ++v11;
    ++v16;
    --v70;
    v18 = 1;
    v72 = v19;
    v74 = (float *)((char *)v74 + 1);
  }
  while ( (__int64)v74 < (int)retaddr );
  if ( !v16 )
    return 0i64;
  v47 = v94.m_enum + 1;
  if ( v47 <= (int)m_data )
  {
    if ( (int)m_data - (__int64)(v94.m_enum + 1) + 1 >= 4 )
    {
      v48 = 4 * (v47 - v16) + 12;
      v49 = ((unsigned __int64)((int)m_data - v47 - 3) >> 2) + 1;
      v47 += 4 * v49;
      do
      {
        v50 = v48 + 4i64 * v16;
        *(float *)((char *)U->m_data + v48 - 12) = *(float *)((char *)U->m_data + v50 - 12);
        *(float *)((char *)U->m_data + v48 - 8) = *(float *)((char *)U->m_data + v50 - 8);
        v48 += 16i64;
        *(float *)((char *)U->m_data + v48 - 20) = *(float *)((char *)U->m_data + v50 - 4);
        *(float *)((char *)U->m_data + v48 - 16) = *(float *)((char *)U->m_data + v50);
        --v49;
      }
      while ( v49 );
    }
    for ( ; v47 <= (int)m_data; *(float *)((char *)U->m_data + v51 * 4 - 4i64 * v16) = U->m_data[v51] )
      v51 = v47++;
  }
  v52 = v79[0].point[2];
  v53 = v79[0].point[2];
  if ( v16 > 1 )
  {
    do
    {
      if ( (v18 & 1) != 0 )
        ++LODWORD(v53);
      else
        --LODWORD(v52);
      ++v18;
    }
    while ( v18 < v16 );
  }
  if ( LODWORD(v53) + 1 <= v89 )
  {
    v54 = LODWORD(v53) + 1;
    v55 = SLODWORD(v52);
    v56 = (unsigned int)(v89 - LODWORD(v53));
    do
    {
      hkaNURBS::Point::operator=(&Pw->m_data[v55++], &Pw->m_data[v54++]);
      --v56;
    }
    while ( v56 );
  }
  v57 = Pw->m_size - (_DWORD)retaddr;
  v58 = Pw->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v58 < v57 )
  {
    v59 = 2 * v58;
    v60 = Pw->m_size - (_DWORD)retaddr;
    if ( v57 < v59 )
      v60 = v59;
    hkArrayUtil::_reserve(&v94, &hkContainerHeapAllocator::s_alloc, Pw, v60, 16);
  }
  m_size = Pw->m_size;
  v62 = &Pw->m_data[m_size];
  if ( v57 - (int)m_size > 0 )
  {
    v63 = (unsigned int)(v57 - m_size);
    do
    {
      if ( v62 )
        hkaNURBS::Point::Point(v62, 0.0, 0.0, 0.0, 0.0);
      ++v62;
      --v63;
    }
    while ( v63 );
  }
  Pw->m_size = v57;
  v64 = U->m_size - (_DWORD)retaddr;
  v65 = U->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v65 < v64 )
  {
    v66 = 2 * v65;
    v67 = U->m_size - (_DWORD)retaddr;
    if ( v64 < v66 )
      v67 = v66;
    hkArrayUtil::_reserve(&v94, &hkContainerHeapAllocator::s_alloc, U, v67, 4);
  }
  U->m_size = v64;
  return (unsigned int)v16;
}

// File Line: 450
// RVA: 0xBB41D0
__int64 __fastcall hkaNURBS::Factorial(int i)
{
  __int64 result; // rax
  int j; // ecx
  int v4[14]; // [rsp+0h] [rbp-38h]

  v4[0] = 1;
  v4[1] = 1;
  v4[2] = 2;
  v4[3] = 6;
  v4[4] = 24;
  v4[5] = 120;
  v4[6] = 720;
  v4[7] = 5040;
  v4[8] = 40320;
  v4[9] = 362880;
  LODWORD(result) = 3628800;
  v4[10] = 3628800;
  if ( i <= 0 )
    return 1i64;
  if ( i <= 10 )
    return (unsigned int)v4[i];
  for ( j = 11; j <= i; ++j )
    result = (unsigned int)(j * result);
  return result;
}

// File Line: 469
// RVA: 0xBB4180
__int64 __fastcall hkaNURBS::Bin(int i, int j)
{
  int v4; // edi
  int v5; // edi

  v4 = hkaNURBS::Factorial(i - j);
  v5 = hkaNURBS::Factorial(j) * v4;
  return (unsigned int)(hkaNURBS::Factorial(i) / v5);
}

// File Line: 483
// RVA: 0xBAFCB0
void __fastcall hkaNURBS::DegreeElevateCurve(
        int *n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Pw,
        int t)
{
  int v5; // r14d
  int v6; // r15d
  int v8; // ebx
  hkaNURBS::Point *v9; // rdi
  int j; // esi
  hkaNURBS::Point *v11; // rdi
  int k; // esi
  hkaNURBS::Point *v13; // rdi
  int v14; // esi
  int v15; // ebx
  __int64 v16; // r14
  int v17; // edx
  int v18; // edi
  hkRelocationInfo::Import *v19; // rcx
  unsigned int v20; // ecx
  int v21; // eax
  __int64 v22; // rbx
  hkaNURBS::Point *v23; // rdi
  int v24; // eax
  int v25; // ebx
  int v26; // r15d
  __int64 v27; // rdi
  __int64 v28; // rdx
  int v29; // eax
  hkaNURBS::Point *v30; // r13
  __int64 v31; // r12
  int v32; // edi
  __m128i v33; // xmm0
  int v34; // eax
  float v35; // xmm7_4
  int v36; // r13d
  int v37; // ebx
  int *v38; // r14
  __int64 v39; // rsi
  float v40; // xmm6_4
  int v41; // eax
  int v42; // r10d
  int v43; // esi
  __int64 v44; // rbx
  __int64 v45; // r11
  int v46; // eax
  __int64 v47; // r9
  int v48; // eax
  __int64 v49; // rdi
  int *v50; // rcx
  unsigned __int64 v51; // r8
  _DWORD *v52; // rdx
  int v53; // eax
  __int64 v54; // r15
  int *v55; // rcx
  __int64 v56; // rdi
  int *v57; // rdx
  int v58; // eax
  int v59; // esi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v60; // r13
  hkRelocationInfo::Import *m_data; // rdx
  int m_fromOffset; // xmm11_4
  int v63; // r12d
  int v64; // r14d
  int v65; // eax
  int *p_m_fromOffset; // rdi
  __int64 m; // rcx
  hkaNURBS::Point *v68; // rdi
  signed __int64 v69; // rsi
  __int64 v70; // rbx
  __int64 v71; // r13
  __int64 v72; // r9
  __int64 v73; // r15
  int v74; // edx
  __int64 v75; // rbx
  float *v76; // rcx
  float v77; // xmm0_4
  float v78; // xmm0_4
  float *v79; // rcx
  hkRelocationInfo::Import *v80; // r10
  unsigned int v81; // eax
  float v82; // xmm12_4
  int v83; // r8d
  __int64 v84; // r12
  int v85; // ecx
  __int64 v86; // r14
  __int64 v87; // rdi
  float v88; // xmm3_4
  float *v89; // rdx
  float *v90; // r8
  char *v91; // r11
  char *v92; // r9
  unsigned __int64 v93; // rcx
  float v94; // xmm1_4
  float v95; // xmm2_4
  float v96; // xmm0_4
  float v97; // xmm1_4
  float v98; // xmm0_4
  float v99; // xmm2_4
  float *v100; // rcx
  __int64 v101; // rdi
  float v102; // xmm1_4
  int v103; // edi
  __int64 v104; // r12
  __int64 v105; // rax
  hkaNURBS::Point *v106; // r13
  int *v107; // rcx
  int v108; // eax
  int *v109; // r15
  __int64 v110; // r14
  int v111; // esi
  hkaNURBS::Point *v112; // rbx
  float v113; // xmm1_4
  hkaNURBS::Point *v114; // rdi
  hkaNURBS::Point *v115; // rax
  hkaNURBS::Point *v116; // rax
  bool v117; // zf
  int v118; // r15d
  __int64 v119; // r9
  __int64 v120; // r12
  __int64 v121; // r13
  hkaNURBS::Point *v122; // r14
  hkaNURBS::Point *v123; // rax
  int v124; // edi
  int v125; // eax
  float *v126; // rsi
  __int64 v127; // rbx
  hkaNURBS::Point *v128; // rax
  hkaNURBS::Point *v129; // rax
  __int64 v130; // rcx
  int v131; // r12d
  hkaNURBS::Point *v132; // r14
  __int64 v133; // rsi
  hkaNURBS::Point *v134; // rdi
  int v135; // r8d
  float v136; // xmm9_4
  float v137; // xmm7_4
  __int64 v138; // rbx
  int v139; // ecx
  __int64 v140; // r10
  __int64 v141; // r13
  int v142; // edx
  int v143; // esi
  __int64 v144; // r11
  int v145; // r14d
  hkaNURBS::Point *v146; // r12
  int v147; // r15d
  int v148; // esi
  float *v149; // rcx
  float *v150; // r13
  hkaNURBS::Point *v151; // rbx
  float v152; // xmm6_4
  hkaNURBS::Point *v153; // rdi
  hkaNURBS::Point *v154; // rax
  hkaNURBS::Point *v155; // rax
  float v156; // xmm6_4
  hkaNURBS::Point *v157; // rdi
  hkaNURBS::Point *v158; // rax
  hkaNURBS::Point *v159; // rdx
  hkaNURBS::Point *v160; // rax
  __int64 v161; // rdx
  int v162; // eax
  int *v163; // rdi
  int v164; // r12d
  __int64 v165; // rcx
  int v166; // r15d
  hkaNURBS::Point *v167; // r13
  hkaNURBS::Point *v168; // rdi
  __int64 v169; // rbx
  __int64 v170; // r12
  __int64 v171; // rbx
  __int64 v172; // rdi
  int v173; // r14d
  hkaNURBS::Point *v174; // rdi
  char *v175; // rsi
  __int64 v176; // rbx
  __int64 v177; // r8
  __int64 v178; // rcx
  float *v179; // rax
  int m_capacityAndFlags; // r8d
  int v181; // [rsp+30h] [rbp-A8h] BYREF
  int v182; // [rsp+34h] [rbp-A4h]
  int v183; // [rsp+38h] [rbp-A0h]
  int v184; // [rsp+3Ch] [rbp-9Ch]
  int v185; // [rsp+40h] [rbp-98h]
  __int64 v186; // [rsp+48h] [rbp-90h]
  unsigned int v187; // [rsp+50h] [rbp-88h]
  int v188; // [rsp+54h] [rbp-84h]
  __int64 v189; // [rsp+58h] [rbp-80h]
  hkaNURBS::Point *a; // [rsp+60h] [rbp-78h]
  hkRelocationInfo::Import *v191; // [rsp+68h] [rbp-70h]
  __int64 v192; // [rsp+70h] [rbp-68h]
  float *v193; // [rsp+78h] [rbp-60h]
  hkaNURBS::Point *ii; // [rsp+80h] [rbp-58h]
  hkaNURBS::Point *v195; // [rsp+88h] [rbp-50h]
  __int64 v196; // [rsp+90h] [rbp-48h]
  __int64 v197; // [rsp+98h] [rbp-40h]
  int v198; // [rsp+A0h] [rbp-38h]
  int v199; // [rsp+A4h] [rbp-34h]
  __int64 v200; // [rsp+A8h] [rbp-30h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v201; // [rsp+B0h] [rbp-28h] BYREF
  __int64 v202; // [rsp+C0h] [rbp-18h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v203; // [rsp+C8h] [rbp-10h] BYREF
  char v204[16]; // [rsp+D8h] [rbp+0h] BYREF
  __int64 v205; // [rsp+E8h] [rbp+10h]
  hkaNURBS::Point v206[3]; // [rsp+F8h] [rbp+20h] BYREF
  _DWORD v207[2]; // [rsp+130h] [rbp+58h] BYREF
  int v208[16]; // [rsp+138h] [rbp+60h] BYREF
  hkaNURBS::Point v209[4]; // [rsp+178h] [rbp+A0h] BYREF
  hkaNURBS::Point v210; // [rsp+1B8h] [rbp+E0h] BYREF
  char v211; // [rsp+1C8h] [rbp+F0h] BYREF
  hkaNURBS::Point v212; // [rsp+1D8h] [rbp+100h] BYREF
  hkaNURBS::Point v213; // [rsp+1E8h] [rbp+110h] BYREF
  hkaNURBS::Point result; // [rsp+1F8h] [rbp+120h] BYREF
  hkaNURBS::Point v215; // [rsp+208h] [rbp+130h] BYREF
  hkaNURBS::Point v216; // [rsp+218h] [rbp+140h] BYREF
  hkaNURBS::Point v217; // [rsp+228h] [rbp+150h] BYREF
  hkaNURBS::Point v218; // [rsp+238h] [rbp+160h] BYREF
  hkaNURBS::Point v219; // [rsp+248h] [rbp+170h] BYREF
  hkaNURBS::Point v220; // [rsp+258h] [rbp+180h] BYREF
  hkaNURBS::Point v221; // [rsp+268h] [rbp+190h] BYREF
  hkaNURBS::Point v222; // [rsp+278h] [rbp+1A0h] BYREF
  hkaNURBS::Point v223; // [rsp+288h] [rbp+1B0h] BYREF
  hkaNURBS::Point v224; // [rsp+298h] [rbp+1C0h] BYREF
  hkaNURBS::Point v225[6]; // [rsp+2A8h] [rbp+1D0h] BYREF
  _DWORD *v226; // [rsp+3A8h] [rbp+2D0h]
  int i; // [rsp+3B0h] [rbp+2D8h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v228; // [rsp+3B8h] [rbp+2E0h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *vars0; // [rsp+3C0h] [rbp+2E8h]
  void *retaddr; // [rsp+3C8h] [rbp+2F0h]

  v5 = *n;
  v6 = *n + p + 1;
  LODWORD(v191) = v6;
  if ( (_DWORD)retaddr )
  {
    v8 = 3;
    v9 = v206;
    for ( j = 3; j >= 0; --j )
      hkaNURBS::Point::Point(v9++, 0.0, 0.0, 0.0, 0.0);
    v11 = v209;
    for ( k = 3; k >= 0; --k )
      hkaNURBS::Point::Point(v11++, 0.0, 0.0, 0.0, 0.0);
    v13 = v225;
    do
    {
      hkaNURBS::Point::Point(v13++, 0.0, 0.0, 0.0, 0.0);
      --v8;
    }
    while ( v8 >= 0 );
    v14 = (int)retaddr;
    v15 = v5 + (_DWORD)retaddr * (hkaNURBS::UniqueKnotCount(U, v6) - 1);
    v16 = i;
    v198 = v15;
    v17 = v15 + i + (_DWORD)retaddr + 2;
    v18 = v17;
    if ( v17 )
    {
      v181 = 4 * v17;
      v19 = (hkRelocationInfo::Import *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                          &hkContainerHeapAllocator::s_alloc,
                                          &v181,
                                          0i64);
      v17 = v181 / 4;
    }
    else
    {
      v19 = 0i64;
    }
    v191 = v19;
    v201.m_data = v19;
    v20 = v15 + 1;
    v21 = 0x80000000;
    v201.m_size = v18;
    if ( v17 )
      v21 = v17;
    v22 = v20;
    v201.m_capacityAndFlags = v21;
    if ( v20 )
    {
      v181 = 16 * v20;
      v23 = (hkaNURBS::Point *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                 &hkContainerHeapAllocator::s_alloc,
                                 &v181,
                                 0i64);
      v20 = v181 / 16;
    }
    else
    {
      v23 = 0i64;
    }
    v24 = 0x80000000;
    v195 = v23;
    if ( v20 )
      v24 = v20;
    v203.m_data = (hkRelocationInfo::Import *)v23;
    v203.m_size = v22;
    v203.m_capacityAndFlags = v24;
    if ( (int)v22 > 0 )
    {
      do
      {
        if ( v23 )
          hkaNURBS::Point::Point(v23, 0.0, 0.0, 0.0, 0.0);
        ++v23;
        --v22;
      }
      while ( v22 );
    }
    v25 = v16 + (_DWORD)retaddr;
    v26 = 1;
    v27 = (int)v16 + (int)retaddr;
    v28 = v16;
    v208[4 * v27 + v16] = 1065353216;
    v29 = ((int)v16 + (int)retaddr) / 2;
    v185 = v16 + (_DWORD)retaddr;
    v197 = v27;
    v30 = (hkaNURBS::Point *)v29;
    v196 = v16;
    v208[0] = 1065353216;
    LODWORD(v189) = v29;
    v181 = 1;
    v31 = 1i64;
    a = (hkaNURBS::Point *)v29;
    if ( v29 >= 1i64 )
    {
      while ( 1 )
      {
        v32 = v26 - v14;
        v33 = _mm_cvtsi32_si128(hkaNURBS::Bin(v25, v26));
        if ( v26 - v14 < 0 )
          v32 = 0;
        v34 = v26;
        if ( (int)v16 < v26 )
          v34 = v16;
        v35 = 1.0 / _mm_cvtepi32_ps(v33).m128_f32[0];
        if ( v32 <= (__int64)v34 )
        {
          v36 = i;
          v37 = v26 - v32;
          v38 = &v208[4 * v31 + v32];
          v39 = v34 - (__int64)v32 + 1;
          do
          {
            v40 = (float)hkaNURBS::Bin(v36, v32) * v35;
            v41 = hkaNURBS::Bin((int)retaddr, v37);
            ++v32;
            --v37;
            *((float *)++v38 - 1) = v40 * (float)v41;
            --v39;
          }
          while ( v39 );
          v26 = v181;
          v30 = a;
          LODWORD(v16) = i;
          v25 = v185;
        }
        ++v26;
        ++v31;
        v181 = v26;
        if ( v31 > (__int64)v30 )
          break;
        v14 = (int)retaddr;
      }
      v29 = v189;
      v28 = (int)v16;
      v27 = v25;
    }
    v42 = v29 + 1;
    v43 = v25 - 1;
    if ( v29 + 1 > v25 - 1 )
    {
      v54 = v196;
    }
    else
    {
      v44 = 4i64 * v42;
      v45 = 4 * (v27 - v42);
      while ( 1 )
      {
        v46 = v42 - (_DWORD)retaddr;
        if ( v42 - (int)retaddr < 0 )
          v46 = 0;
        v47 = v46;
        v48 = v42;
        if ( (int)v16 < v42 )
          v48 = v16;
        v49 = v48;
        if ( v47 > v48 )
        {
          v54 = (int)v16;
        }
        else
        {
          if ( v48 - v47 + 1 >= 4 )
          {
            v50 = &v208[v47 + 1 + v44];
            v51 = ((unsigned __int64)(v48 - v47 - 3) >> 2) + 1;
            v52 = &v207[v45 + v28 - v47];
            v47 += 4 * v51;
            do
            {
              v53 = v52[2];
              v50 += 4;
              v52 -= 4;
              *(v50 - 5) = v53;
              *(v50 - 4) = v52[5];
              *(v50 - 3) = v52[4];
              *(v50 - 2) = v52[3];
              --v51;
            }
            while ( v51 );
          }
          v54 = (int)v16;
          if ( v47 <= v49 )
          {
            v55 = &v208[v44 + v47];
            v56 = v49 - v47 + 1;
            v57 = &v208[v45 + (int)v16 - v47];
            do
            {
              v58 = *v57;
              ++v55;
              --v57;
              *(v55 - 1) = v58;
              --v56;
            }
            while ( v56 );
          }
        }
        ++v42;
        v44 += 4i64;
        v45 -= 4i64;
        if ( v42 > v43 )
          break;
        v28 = (int)v16;
      }
      v25 = v185;
    }
    v59 = i;
    v60 = vars0;
    m_data = vars0->m_data;
    m_fromOffset = v228->m_data->m_fromOffset;
    v63 = v25 + 1;
    v64 = i + 1;
    v181 = m_fromOffset;
    v187 = -1;
    LODWORD(v192) = 1;
    v183 = v25 + 1;
    v182 = i + 1;
    hkaNURBS::Point::operator=(v195, (hkaNURBS::Point *)m_data);
    if ( v25 >= 0 )
    {
      v65 = v181;
      p_m_fromOffset = &v191->m_fromOffset;
      for ( m = v25 + 1i64; m; --m )
        *p_m_fromOffset++ = v65;
    }
    if ( v59 >= 0 )
    {
      v68 = v206;
      v69 = (char *)v60->m_data - (char *)v206;
      v70 = v64;
      do
      {
        hkaNURBS::Point::operator=(v68, (hkaNURBS::Point *)((char *)v68 + v69));
        ++v68;
        --v70;
      }
      while ( v70 );
      v59 = i;
    }
    v71 = v64;
    v72 = v54;
    v192 = v54;
    v73 = (int)v191;
    v186 = v64;
    for ( ii = (hkaNURBS::Point *)v63; v71 < v73; v59 = i )
    {
      v74 = v64;
      v75 = v71;
      if ( v71 < v73 )
      {
        if ( v73 - v71 < 4 )
        {
LABEL_71:
          if ( v71 < v73 )
          {
            v79 = (float *)(&v228->m_data->m_fromOffset + v71);
            do
            {
              if ( v79[1] != *v79 )
                break;
              ++v71;
              ++v64;
              ++v79;
            }
            while ( v71 < v73 );
LABEL_75:
            v186 = v71;
            v182 = v64;
          }
        }
        else
        {
          v76 = (float *)&v228->m_data->m_identifier + v71;
          while ( 1 )
          {
            v77 = *(v76 - 1);
            if ( v77 != *(v76 - 2) )
              break;
            if ( v77 != *v76 )
            {
              ++v71;
              ++v64;
              goto LABEL_75;
            }
            v78 = v76[1];
            if ( *v76 != v78 )
            {
              v71 += 2i64;
              v64 += 2;
              goto LABEL_75;
            }
            if ( v78 != v76[2] )
            {
              v71 += 3i64;
              v64 += 3;
              goto LABEL_75;
            }
            v71 += 4i64;
            v64 += 4;
            v76 += 4;
            v182 = v64;
            v186 = v71;
            if ( v71 >= v73 - 3 )
              goto LABEL_71;
          }
        }
      }
      v80 = v228->m_data;
      v81 = v187;
      v82 = *((float *)&v228->m_data->m_fromOffset + v71);
      v83 = v59 - (v64 - v74 + 1);
      v84 = v71 - v75 + 1;
      LODWORD(a) = v187;
      v187 = v83;
      if ( (int)a <= 0 )
        HIDWORD(v189) = 1;
      else
        HIDWORD(v189) = (int)(v81 + 2) / 2;
      v85 = v185;
      if ( v83 > 0 )
        v85 = v185 - (v59 - (v64 - v74)) / 2;
      LODWORD(v189) = v85;
      if ( v83 > 0 )
      {
        v86 = v59;
        v87 = v59;
        v88 = v82 - *(float *)&m_fromOffset;
        if ( v59 > v84 )
        {
          if ( v59 - v84 >= 4 )
          {
            v89 = (float *)(&v203.m_size + v59 - v84);
            v90 = (float *)v80 + v59 + v72 - 1;
            v91 = (char *)v80 + 4 * (v84 + v72) + 8 - (_QWORD)v204;
            v92 = (char *)v80 + 4 * (v84 + v72) - (_QWORD)v204;
            v93 = ((unsigned __int64)(v59 - v84 - 4) >> 2) + 1;
            v87 = v59 - 4 * v93;
            do
            {
              v94 = *(float *)((char *)v89 + (_QWORD)v91);
              v95 = *v90;
              v89 -= 4;
              v90 -= 4;
              v96 = v88 / (float)(v94 - *(float *)&m_fromOffset);
              v97 = *(float *)&v92[(_QWORD)v89 + 16] - *(float *)&m_fromOffset;
              v89[5] = v96;
              v98 = v88 / (float)(v95 - *(float *)&m_fromOffset);
              v99 = *(float *)&v92[(_QWORD)v89 + 12] - *(float *)&m_fromOffset;
              v89[4] = v98;
              v89[3] = v88 / v97;
              v89[2] = v88 / v99;
              --v93;
            }
            while ( v93 );
            v83 = v187;
            v72 = v192;
          }
          if ( v87 > v84 )
          {
            v100 = (float *)(&v80->m_fromOffset + v72 + v87);
            v101 = v87 - v84;
            do
            {
              v102 = *v100--;
              *(float *)((char *)v100 + &v204[-4 * v84 + -4 * v72] - (char *)v80) = v88
                                                                                  / (float)(v102
                                                                                          - *(float *)&m_fromOffset);
              --v101;
            }
            while ( v101 );
          }
        }
        v189 = v83;
        if ( v83 >= 1i64 )
        {
          v103 = v83 - 1;
          v184 = v83 - 1;
          v104 = v71 - v75 + 2;
          a = &v206[v59];
          v105 = v59 - v71;
          v106 = a;
          v107 = &v203.m_size + v75 + v105;
          v193 = (float *)v107;
          do
          {
            v108 = v59;
            if ( v86 >= v104 )
            {
              v109 = v107;
              v110 = v86 - v104 + 1;
              do
              {
                v111 = v108 - 1;
                v112 = &v206[v108];
                v113 = *(float *)v109;
                v114 = operator*(&result, 1.0 - *(float *)v109, &v206[v108 - 1]);
                v115 = operator*(&v219, v113, v112);
                v116 = hkaNURBS::Point::operator+(v115, &v221, v114);
                hkaNURBS::Point::operator=(v112, v116);
                --v109;
                v108 = v111;
                --v110;
              }
              while ( v110 );
              v103 = v184;
              v59 = i;
              v86 = v196;
            }
            hkaNURBS::Point::operator=(&v225[v103--], v106);
            v107 = (int *)(v193 - 1);
            ++v104;
            v117 = v189-- == 1;
            --v193;
            v184 = v103;
          }
          while ( !v117 );
          v71 = v186;
        }
      }
      v118 = HIDWORD(v189);
      v189 = SHIDWORD(v189);
      v119 = v189;
      v120 = v189;
      if ( v189 <= v197 )
      {
        v121 = v197;
        do
        {
          v122 = &v209[v118];
          hkaNURBS::Point::Point(&v223, 0.0, 0.0, 0.0, 0.0);
          hkaNURBS::Point::operator=(v122, v123);
          v124 = v118 - (_DWORD)retaddr;
          if ( v118 - (int)retaddr < 0 )
            v124 = 0;
          v125 = v118;
          if ( v59 < v118 )
            v125 = v59;
          if ( v124 <= (__int64)v125 )
          {
            v126 = (float *)&v208[4 * v120 + v124];
            v127 = v125 - (__int64)v124 + 1;
            do
            {
              v128 = operator*(&v212, *v126, &v206[v124]);
              v129 = hkaNURBS::Point::operator+(v122, &v222, v128);
              hkaNURBS::Point::operator=(v122, v129);
              ++v124;
              ++v126;
              --v127;
            }
            while ( v127 );
            v59 = i;
          }
          ++v120;
          ++v118;
        }
        while ( v120 <= v121 );
        v71 = v186;
        v119 = v189;
      }
      v130 = (int)a;
      v131 = v183;
      v132 = ii;
      v133 = (__int64)v191;
      if ( (int)a > 1 )
      {
        v134 = ii;
        a = ii;
        v200 = v130;
        v135 = v183 - 2;
        LODWORD(v193) = v183 - 2;
        v136 = 1.0 / (float)(v82 - *(float *)&m_fromOffset);
        v137 = (float)(v82 - *((float *)v191 + (_QWORD)ii - 1)) * v136;
        if ( v130 > 1 )
        {
          v138 = v200;
          v139 = 1;
          v140 = (__int64)v191 + 4 * (_QWORD)ii - 8;
          v141 = (__int64)v191;
          v142 = v183 - 3;
          v143 = v183 - 1;
          v144 = 1i64 - (_QWORD)ii;
          v202 = v140;
          v184 = 1;
          v199 = v183 - 1;
          v188 = v183 - 3;
          v205 = 1i64 - (_QWORD)ii;
          do
          {
            v145 = v135;
            v146 = v134;
            v147 = v139;
            if ( v143 + v139 - v135 > v139 )
            {
              v148 = v139 + 1;
              v149 = (float *)v140;
              v150 = (float *)(v141 - 4 * v144);
              v193 = (float *)v140;
              do
              {
                if ( v145 < (int)v192 )
                {
                  v151 = &v195[v145];
                  v152 = (float)(v82 - *v149) / (float)(*(float *)&m_fromOffset - *v149);
                  v153 = operator*(&v210, 1.0 - v152, &v195[v145 - 1]);
                  v154 = operator*(&v220, v152, v151);
                  v155 = hkaNURBS::Point::operator+(v154, &v216, v153);
                  hkaNURBS::Point::operator=(v151, v155);
                  v149 = v193;
                  v142 = v188;
                  v119 = v189;
                }
                if ( (__int64)v146 >= v119 )
                {
                  if ( v142 + v148 > v183 + (int)a - v185 )
                  {
                    v157 = operator*(&v213, 1.0 - v137, &v209[v148]);
                    v158 = operator*(&v215, v137, &v209[v147]);
                    v159 = &v217;
                  }
                  else
                  {
                    v156 = (float)(v82 - *v150) * v136;
                    v157 = operator*(&v224, 1.0 - v156, &v209[v148]);
                    v158 = operator*(&v218, v156, &v209[v147]);
                    v159 = (hkaNURBS::Point *)&v211;
                  }
                  v160 = hkaNURBS::Point::operator+(v158, v159, v157);
                  hkaNURBS::Point::operator=(&v209[v147], v160);
                  v119 = v189;
                  v149 = v193;
                }
                v142 = v188;
                ++v145;
                --v148;
                ++v149;
                v146 = (hkaNURBS::Point *)((char *)v146 - 1);
                --v150;
                --v147;
                v193 = v149;
              }
              while ( v148 + v183 - 2 - v145 > v184 );
              v139 = v184;
              v134 = a;
              v135 = (int)v193;
              v140 = v202;
              v144 = v205;
              v138 = v200;
              v143 = v199;
              v141 = (__int64)v191;
            }
            v134 = (hkaNURBS::Point *)((char *)v134 + 1);
            --v135;
            v140 -= 4i64;
            ++v139;
            --v142;
            LODWORD(v193) = v135;
            v202 = v140;
            a = v134;
            v184 = v139;
            v188 = v142;
          }
          while ( (__int64)v134 + v144 < v138 );
          v71 = v186;
          LODWORD(v130) = (_DWORD)a;
          v131 = v183;
          v132 = ii;
          v133 = (__int64)v191;
        }
      }
      if ( v192 != v196 && v185 - (int)v130 > 0 )
      {
        v161 = (unsigned int)(v185 - v130);
        v162 = v181;
        v163 = (int *)(v133 + 4i64 * (_QWORD)v132);
        v164 = v161 + v131;
        v165 = (unsigned int)v161;
        v132 = (hkaNURBS::Point *)((char *)v132 + v161);
        while ( v165 )
        {
          *v163++ = v162;
          --v165;
        }
        ii = v132;
        v183 = v164;
      }
      if ( SHIDWORD(v189) <= (int)v189 )
      {
        v166 = v192;
        v167 = v195;
        v168 = &v209[v119];
        v169 = (unsigned int)(v189 - HIDWORD(v189) + 1);
        do
        {
          hkaNURBS::Point::operator=(&v167[v166++], v168++);
          --v169;
        }
        while ( v169 );
        v71 = v186;
        LODWORD(v192) = v166;
      }
      v73 = (int)v191;
      if ( v71 >= (int)v191 )
      {
        v177 = v197;
        v178 = 0i64;
        if ( v197 >= 0 )
        {
          v179 = (float *)(v133 + 4i64 * (_QWORD)v132);
          do
          {
            ++v178;
            *v179++ = v82;
          }
          while ( v178 <= v177 );
        }
        v72 = v192;
        v64 = v182;
      }
      else
      {
        v170 = (int)v187;
        if ( (int)v187 > 0 )
        {
          v171 = v187;
          v172 = 0i64;
          do
          {
            hkaNURBS::Point::operator=(&v206[v172], &v225[v172]);
            ++v172;
            --v171;
          }
          while ( v171 );
        }
        v173 = v182;
        if ( (int)v170 <= i )
        {
          v174 = &v206[v170];
          v175 = (char *)vars0->m_data + 16 * ((int)v170 + v182 - i - v170) - (_QWORD)v206;
          v176 = (unsigned int)(i - v170 + 1);
          do
          {
            hkaNURBS::Point::operator=(v174, (hkaNURBS::Point *)((char *)v174 + (_QWORD)v175));
            ++v174;
            --v176;
          }
          while ( v176 );
        }
        v64 = v173 + 1;
        v72 = v71;
        v192 = v71;
        *(float *)&m_fromOffset = v82;
        ++v71;
        v182 = v64;
        v181 = LODWORD(v82);
        v186 = v71;
      }
    }
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(vars0, &v203);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(&v201, v228);
    m_capacityAndFlags = v203.m_capacityAndFlags;
    *v226 = v198;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v203.m_data,
        16 * m_capacityAndFlags);
    if ( v201.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v201.m_data,
        4 * v201.m_capacityAndFlags);
  }
}

// File Line: 651
// RVA: 0xBAFB30
void __fastcall hkaNURBS::ChordLengthParameterization(
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        hkArray<float,hkContainerHeapAllocator> *U)
{
  __int64 v3; // r15
  int v4; // ebx
  int v5; // eax
  __int64 v8; // rbp
  int v9; // eax
  int v10; // r9d
  float *m_data; // rax
  __int64 v12; // r14
  hkaNURBS::Point *v13; // rsi
  float *v14; // rbx
  hkaNURBS::Point *v15; // rax
  __int64 v16; // rcx
  hkaNURBS::Point v17; // [rsp+30h] [rbp-28h] BYREF
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  v3 = m;
  v4 = m + 1;
  v5 = U->m_capacityAndFlags & 0x3FFFFFFF;
  v8 = 1i64;
  if ( v5 < m + 1 )
  {
    v9 = 2 * v5;
    v10 = m + 1;
    if ( v4 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, U, v10, 4);
  }
  m_data = U->m_data;
  U->m_size = v4;
  *m_data = 0.0;
  if ( (int)v3 >= 1 )
  {
    v12 = (unsigned int)v3;
    v13 = Q->m_data + 1;
    do
    {
      v14 = U->m_data;
      v15 = hkaNURBS::Point::operator-(v13, &v17, v13 - 1);
      ++v8;
      ++v13;
      v14[v8 - 1] = hkaNURBS::Point::mag(v15) + v14[v8 - 2];
      --v12;
    }
    while ( v12 );
  }
  v16 = 1i64;
  if ( v3 > 1 )
  {
    if ( v3 - 1 >= 4 )
    {
      do
      {
        v16 += 4i64;
        U->m_data[v16 - 4] = U->m_data[v16 - 4] / U->m_data[v3];
        U->m_data[v16 - 3] = U->m_data[v16 - 3] / U->m_data[v3];
        U->m_data[v16 - 2] = U->m_data[v16 - 2] / U->m_data[v3];
        U->m_data[v16 - 1] = U->m_data[v16 - 1] / U->m_data[v3];
      }
      while ( v16 < v3 - 3 );
    }
    for ( ; v16 < v3; U->m_data[v16 - 1] = U->m_data[v16 - 1] / U->m_data[v3] )
      ++v16;
  }
  U->m_data[v3] = 1.0;
}

// File Line: 685
// RVA: 0xBB1BA0
float __fastcall hkaNURBS::GetRemovalBoundCurve(
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        float u,
        int r,
        int s)
{
  hkArray<float,hkContainerHeapAllocator> *v8; // r13
  hkaNURBS::Point *v10; // rbx
  int i; // edi
  hkaNURBS::Point *m_data; // r12
  int v13; // ebp
  int v14; // edi
  int v15; // esi
  int v16; // ebx
  int v17; // r14d
  __int64 v18; // rdx
  int v19; // r15d
  float *v20; // rax
  int v21; // r13d
  float *v22; // rbx
  float *v23; // rdi
  float v24; // xmm6_4
  float v25; // xmm7_4
  hkaNURBS::Point *v26; // rax
  hkaNURBS::Point *v27; // rax
  hkaNURBS::Point *v28; // rax
  hkaNURBS::Point *v29; // rax
  hkaNURBS::Point *v30; // rax
  hkaNURBS::Point *v31; // rax
  hkaNURBS::Point *v32; // rdx
  hkaNURBS::Point *v33; // rcx
  float v34; // xmm8_4
  hkaNURBS::Point *v35; // rbx
  hkaNURBS::Point *v36; // rax
  hkaNURBS::Point v38; // [rsp+30h] [rbp-148h] BYREF
  hkaNURBS::Point v39; // [rsp+40h] [rbp-138h] BYREF
  hkaNURBS::Point v40; // [rsp+50h] [rbp-128h] BYREF
  hkaNURBS::Point v41[7]; // [rsp+60h] [rbp-118h] BYREF
  hkaNURBS::Point result; // [rsp+D0h] [rbp-A8h] BYREF
  hkaNURBS::Point v43; // [rsp+E0h] [rbp-98h] BYREF
  hkaNURBS::Point v44; // [rsp+F0h] [rbp-88h] BYREF
  __int64 v46; // [rsp+198h] [rbp+20h]

  v8 = U;
  v10 = v41;
  for ( i = 6; i >= 0; --i )
    hkaNURBS::Point::Point(v10++, 0.0, 0.0, 0.0, 0.0);
  m_data = P->m_data;
  v13 = r - p;
  v14 = p + 1;
  v15 = r - s;
  v16 = r - p - 1;
  hkaNURBS::Point::operator=(v41, &m_data[v16]);
  v17 = -s - (-p - 1);
  hkaNURBS::Point::operator=(&v41[v15 - v16 + 1], &m_data[v15 + 1]);
  v18 = v14;
  v19 = 1;
  v46 = v14;
  if ( r - s - v13 > 0 )
  {
    v20 = v8->m_data;
    v21 = v17 + 1;
    v22 = &v20[v15];
    v23 = &v20[v13];
    do
    {
      v24 = (float)(u - *v23) / (float)(v23[v18] - *v23);
      v25 = (float)(u - *v22) / (float)(v22[v18] - *v22);
      v26 = operator*(&result, 1.0 - v24, &v41[v19 - 1]);
      v27 = hkaNURBS::Point::operator-(&m_data[v13], &v43, v26);
      v28 = hkaNURBS::Point::operator/(v27, &v44, v24);
      hkaNURBS::Point::operator=(&v41[v19], v28);
      v29 = operator*(&v38, v25, &v41[v21]);
      v30 = hkaNURBS::Point::operator-(&m_data[v15], &v39, v29);
      v31 = hkaNURBS::Point::operator/(v30, &v40, 1.0 - v25);
      hkaNURBS::Point::operator=(&v41[v17], v31);
      v18 = v46;
      --v15;
      ++v13;
      ++v23;
      ++v19;
      --v22;
      --v17;
      --v21;
    }
    while ( v15 - v13 > 0 );
    v8 = U;
  }
  if ( v15 - v13 >= 0 )
  {
    v34 = (float)(u - v8->m_data[v13]) / (float)(v8->m_data[v18 + v13] - v8->m_data[v13]);
    v35 = operator*(&v40, 1.0 - v34, &v41[v19 - 1]);
    v36 = operator*(&v39, v34, &v41[v19 + 1]);
    v32 = hkaNURBS::Point::operator+(v36, &v38, v35);
    v33 = &m_data[v13];
  }
  else
  {
    v32 = &v41[v17 + 1];
    v33 = &v41[v19 - 1];
  }
  return hkaNURBS::Distance3D(v33, v32);
}

// File Line: 733
// RVA: 0xBB1F80
__int64 __fastcall hkaNURBS::RemoveKnotsBoundCurve(
        int *n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        int mb,
        hkArray<float,hkContainerHeapAllocator> *ub,
        hkArray<float,hkContainerHeapAllocator> *e,
        float E,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q_JUNK)
{
  __int64 v9; // r14
  int v11; // r13d
  int v12; // r12d
  int v13; // edi
  float *v14; // rsi
  int v15; // eax
  __int64 v16; // rcx
  float *v17; // rdi
  int v18; // ebx
  int v19; // eax
  _DWORD *v20; // rdi
  unsigned int v21; // ecx
  __int64 v22; // rcx
  int v23; // eax
  char *v24; // rdi
  unsigned int v25; // ecx
  __int64 v26; // rcx
  int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // eax
  hkArray<float,hkContainerHeapAllocator> *v30; // rbx
  int v31; // eax
  __int64 v32; // r15
  int v33; // eax
  __int64 v34; // r8
  __int64 v35; // rdi
  float *v36; // r13
  int v37; // edx
  __int64 v38; // r9
  float v39; // xmm6_4
  int v40; // r15d
  int v41; // eax
  float *m_data; // rbx
  int v43; // eax
  float v44; // xmm7_4
  __int64 v45; // rsi
  __int64 v46; // r12
  __int64 v47; // rbx
  char *v48; // rsi
  signed __int64 v49; // rdi
  float v50; // xmm0_4
  float *v51; // rcx
  float v52; // xmm0_4
  int m_size; // eax
  char *v54; // r13
  int v55; // r15d
  __int64 v56; // rdi
  float *v57; // r9
  __int64 v58; // r10
  char *v59; // rcx
  signed __int64 v60; // rdx
  unsigned __int64 v61; // r8
  int v62; // eax
  signed __int64 v63; // r9
  char *v64; // rcx
  __int64 v65; // rdi
  int v66; // eax
  char *v67; // r12
  __int64 v68; // r10
  __int64 v69; // r11
  char *v70; // rdi
  unsigned __int64 v71; // r8
  char *v72; // rdx
  int v73; // eax
  float v74; // eax
  int v75; // ebx
  int v76; // eax
  int v77; // r12d
  int v78; // eax
  int v79; // ebx
  int v80; // esi
  int v81; // ecx
  int v82; // eax
  int v83; // eax
  int v84; // ecx
  int hi; // edi
  int lo; // eax
  int v87; // eax
  int v88; // eax
  unsigned int v89; // ebx
  int s; // [rsp+50h] [rbp-B0h] BYREF
  int m; // [rsp+54h] [rbp-ACh]
  int r; // [rsp+58h] [rbp-A8h]
  int v94; // [rsp+5Ch] [rbp-A4h] BYREF
  int v95; // [rsp+60h] [rbp-A0h] BYREF
  int v96; // [rsp+64h] [rbp-9Ch]
  int v97; // [rsp+68h] [rbp-98h] BYREF
  char *v98; // [rsp+70h] [rbp-90h]
  int v99; // [rsp+78h] [rbp-88h]
  int v100; // [rsp+7Ch] [rbp-84h] BYREF
  int v101; // [rsp+80h] [rbp-80h] BYREF
  hkArray<float,hkContainerHeapAllocator> arr; // [rsp+88h] [rbp-78h] BYREF
  int v103; // [rsp+98h] [rbp-68h]
  _BYTE *v104; // [rsp+A0h] [rbp-60h]
  int v105; // [rsp+A8h] [rbp-58h]
  float v106; // [rsp+B0h] [rbp-50h]
  int v107; // [rsp+B8h] [rbp-48h]
  int v108; // [rsp+BCh] [rbp-44h]
  float v109; // [rsp+C0h] [rbp-40h]
  int v110; // [rsp+C8h] [rbp-38h]
  unsigned __int64 v111; // [rsp+D0h] [rbp-30h]
  void *v112; // [rsp+D8h] [rbp-28h]
  __int64 i; // [rsp+E0h] [rbp-20h]
  void *v114; // [rsp+E8h] [rbp-18h]
  __int64 v115; // [rsp+F0h] [rbp-10h]

  v9 = p;
  v103 = *n;
  v11 = v103 + p + 1;
  m = v11;
  v12 = v11 + 1;
  v99 = v11 + 1;
  v13 = v11 + 1;
  if ( v11 == -1 )
  {
    v14 = 0i64;
  }
  else
  {
    s = 4 * v12;
    v14 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &s);
    v13 = s / 4;
  }
  v15 = 0x80000000;
  arr.m_data = v14;
  if ( v13 )
    v15 = v13;
  arr.m_size = v11 + 1;
  v16 = v12;
  arr.m_capacityAndFlags = v15;
  if ( v12 > 0 )
  {
    v17 = v14;
    while ( v16 )
    {
      *v17++ = 3.40282e38;
      --v16;
    }
  }
  v18 = mb + 1;
  v19 = mb + 1;
  if ( mb == -1 )
  {
    v20 = 0i64;
  }
  else
  {
    v101 = 4 * v18;
    v20 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v101);
    v19 = v101 / 4;
  }
  v21 = 0x80000000;
  v104 = v20;
  if ( v19 )
    v21 = v19;
  v105 = v21;
  v22 = v18;
  if ( v18 > 0 )
  {
    while ( v22 )
    {
      *v20++ = 0;
      --v22;
    }
  }
  v23 = mb + 1;
  if ( mb == -1 )
  {
    v24 = 0i64;
  }
  else
  {
    v100 = 4 * v18;
    v24 = (char *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v100);
    v23 = v100 / 4;
  }
  v25 = 0x80000000;
  v98 = v24;
  if ( v23 )
    v25 = v23;
  v107 = v25;
  v26 = v18;
  if ( v18 > 0 )
  {
    while ( v26 )
    {
      *(_DWORD *)v24 = 0;
      v24 += 4;
      --v26;
    }
  }
  v27 = mb + 1;
  if ( mb == -1 )
  {
    v112 = 0i64;
  }
  else
  {
    v94 = 4 * v18;
    v112 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v94);
    v27 = v94 / 4;
  }
  v28 = 0x80000000;
  if ( v27 )
    v28 = v27;
  v110 = v28;
  if ( mb == -1 )
  {
    v114 = 0i64;
  }
  else
  {
    v97 = 4 * v18;
    v114 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v97);
    v18 = v97 / 4;
  }
  v29 = 0x80000000;
  v96 = v9 + 1;
  if ( v18 )
    v29 = v18;
  v30 = U;
  v108 = v29;
  hkaNURBS::ComputeBounds(*n, v9, U, P, &arr, v9 + 1, v11 - v9 - 1);
  v31 = hkaNURBS::MinIndex(&arr, v12);
  v32 = v31;
  r = v31;
  v33 = hkaNURBS::Multiplicity(v31, v11, U);
  v34 = v32;
  v35 = v32;
  v36 = &v14[v32];
  v37 = v33;
  s = v33;
  v111 = 4 * v32;
  if ( 3.40282e38 != *v36 )
  {
    v38 = v9;
    for ( i = v9; ; v38 = i )
    {
      if ( (v37 + p) % 2 )
      {
        v41 = (v37 + v96) / 2;
        v40 = v32 - v41 + 1;
        v39 = (float)(v30->m_data[v34] - v30->m_data[v35 - v41 + 1])
            / (float)(v30->m_data[v38 + 2 + v35 - v41] - v30->m_data[v35 - v41 + 1]);
      }
      else
      {
        v39 = 0.0;
        v40 = v32 - (v37 + p) / 2;
      }
      m_data = v30->m_data;
      v43 = hkaNURBS::Find(m_data[v40], ub, mb);
      v44 = 0.0;
      v45 = v43;
      v115 = v43;
      v46 = v43;
      v47 = hkaNURBS::Find(m_data[v40 + 1 + i], ub, mb) - 1;
      if ( v45 <= v47 )
      {
        v48 = v98;
        v49 = v104 - v98;
        do
        {
          v50 = hkaNURBS::OneBasisFun(p, m, U, v40, ub->m_data[v46]);
          v51 = (float *)&v48[4 * v46];
          v109 = v44;
          ++v46;
          v52 = v50 * (float)((float)(1.0 - v39) * *v36);
          *(float *)((char *)v51 + v49) = v52;
          v106 = v52 + e->m_data[v46 - 1];
          v44 = fmaxf(v44, v106);
          *v51 = v106;
        }
        while ( v46 <= v47 );
        v45 = v115;
      }
      if ( v44 > E )
      {
        v77 = v99;
        v30 = U;
        *v36 = 3.40282e38;
      }
      else
      {
        m_size = e->m_size;
        v54 = 0i64;
        v55 = 0x80000000;
        if ( m_size > 0 )
        {
          v95 = 4 * m_size;
          v54 = (char *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v95);
          v55 = v95 / 4;
        }
        v56 = e->m_size;
        v57 = e->m_data;
        v58 = 0i64;
        if ( v56 >= 4 )
        {
          v59 = v54 + 4;
          v60 = (char *)v57 - v54;
          v61 = ((unsigned __int64)(v56 - 4) >> 2) + 1;
          v58 = 4 * v61;
          do
          {
            v62 = *(_DWORD *)&v59[v60 - 4];
            v59 += 16;
            *((_DWORD *)v59 - 5) = v62;
            *((_DWORD *)v59 - 4) = *(_DWORD *)&v59[v60 - 16];
            *((_DWORD *)v59 - 3) = *(_DWORD *)&v59[v60 - 12];
            *((_DWORD *)v59 - 2) = *(_DWORD *)&v59[v60 - 8];
            --v61;
          }
          while ( v61 );
        }
        if ( v58 < v56 )
        {
          v63 = (char *)v57 - v54;
          v64 = &v54[4 * v58];
          v65 = v56 - v58;
          do
          {
            v66 = *(_DWORD *)&v64[v63];
            v64 += 4;
            *((_DWORD *)v64 - 1) = v66;
            --v65;
          }
          while ( v65 );
        }
        if ( v45 <= v47 )
        {
          v67 = v98;
          if ( v47 - v45 + 1 >= 4 )
          {
            v68 = 4i64 - (_QWORD)v98;
            v69 = -8i64 - (_QWORD)v98;
            v70 = &v98[4 * v45 + 8];
            v71 = ((unsigned __int64)(v47 - v45 - 3) >> 2) + 1;
            v45 += 4 * v71;
            do
            {
              v72 = &v70[v69];
              *(_DWORD *)&v72[(unsigned __int64)e->m_data] = *((_DWORD *)v70 - 2);
              *(float *)((char *)e->m_data + (unsigned __int64)v72 + 4) = *((float *)v70 - 1);
              v73 = *(_DWORD *)v70;
              v70 += 16;
              *(_DWORD *)&v70[(char *)e->m_data - v67 - 16] = v73;
              *(float *)((char *)e->m_data + v68 + (unsigned __int64)v70 - 16) = *((float *)v70 - 3);
              --v71;
            }
            while ( v71 );
          }
          for ( ; v45 <= v47; e->m_data[v45 - 1] = v74 )
            v74 = *(float *)&v67[4 * v45++];
        }
        v75 = r;
        hkaNURBS::RemoveCurveKnot(*n, p, U, P, U->m_data[v111 / 4], r, s, 1, 3.40282e38);
        v76 = m;
        --*n;
        m = v76 - 1;
        v77 = v76;
        v99 = v76;
        if ( v76 <= 2 * p + 2 )
        {
          if ( v55 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v54, 4 * v55);
          break;
        }
        hkaNURBS::Remove(v75, &arr, v76);
        v78 = v75;
        v79 = v75 - p;
        v80 = *n;
        v81 = *n;
        v82 = p + v78 - s;
        if ( v82 < *n )
          v81 = v82;
        v83 = hkaNURBS::UniqueKnot(v81, U, m);
        v84 = v96;
        hi = v83;
        if ( v79 > v96 )
          v84 = v79;
        v30 = U;
        lo = hkaNURBS::UniqueKnot(v84, U, m);
        hkaNURBS::ComputeBounds(v80, p, U, P, &arr, lo, hi);
        if ( v55 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v54, 4 * v55);
      }
      v87 = hkaNURBS::MinIndex(&arr, v77);
      v32 = v87;
      r = v87;
      v88 = hkaNURBS::Multiplicity(v87, m, v30);
      v34 = v32;
      v36 = &arr.m_data[v32];
      v37 = v88;
      s = v88;
      v35 = v32;
      v111 = 4 * v32;
      if ( 3.40282e38 == *v36 )
        break;
    }
  }
  v89 = v103 - *n;
  if ( v108 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v114, 4 * v108);
  if ( v110 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v112, 4 * v110);
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v98, 4 * v107);
  if ( v105 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v104, 4 * v105);
  if ( arr.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      arr.m_data,
      4 * arr.m_capacityAndFlags);
  return v89;
}

// File Line: 907
// RVA: 0xBAEFE0
void __fastcall hkaNURBS::GlobalCurveApproxErrBnd(
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        int p,
        float E,
        int *n,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P)
{
  int v7; // r9d
  int v11; // ebp
  float *v12; // rcx
  int v13; // eax
  hkArray<float,hkContainerHeapAllocator> ub; // [rsp+50h] [rbp-28h] BYREF
  int v15; // [rsp+80h] [rbp+8h] BYREF

  v7 = m + 1;
  ub.m_data = 0i64;
  ub.m_size = 0;
  ub.m_capacityAndFlags = 0x80000000;
  v11 = m + 1;
  if ( m == -1 )
  {
    v12 = 0i64;
  }
  else
  {
    v15 = 4 * v7;
    v12 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v15);
    v7 = v15 / 4;
  }
  v13 = 0x80000000;
  ub.m_data = v12;
  if ( v7 )
    v13 = v7;
  ub.m_size = v11;
  ub.m_capacityAndFlags = v13;
  hkaNURBS::ChordLengthParameterization(m, Q, &ub);
  hkaNURBS::GlobalCurveApproxErrBnd(m, Q, &ub, (hkBool)1, p, E, n, U, P);
  ub.m_size = 0;
  if ( ub.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      ub.m_data,
      4 * ub.m_capacityAndFlags);
}

// File Line: 930
// RVA: 0xBAF130
void __fastcall hkaNURBS::GlobalCurveApproxErrBnd(
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        hkArray<float,hkContainerHeapAllocator> *ub,
        int p,
        float E,
        int *n,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P)
{
  int m_size; // eax
  __int64 v9; // rsi
  int v10; // ebx
  float *v15; // rdi
  float *m_data; // r9
  __int64 v17; // rdx
  float *v18; // rcx
  signed __int64 v19; // r8
  unsigned __int64 v20; // r10
  int v21; // eax
  signed __int64 v22; // r9
  float *v23; // rcx
  __int64 v24; // rdx
  int v25; // eax
  hkArray<float,hkContainerHeapAllocator> uba; // [rsp+50h] [rbp-38h] BYREF
  int v27; // [rsp+A0h] [rbp+18h] BYREF

  m_size = ub->m_size;
  v9 = 0i64;
  v10 = 0x80000000;
  uba.m_data = 0i64;
  v15 = 0i64;
  uba.m_capacityAndFlags = 0x80000000;
  if ( m_size > 0 )
  {
    v27 = 4 * m_size;
    v15 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v27);
    uba.m_data = v15;
    v10 = v27 / 4;
    uba.m_capacityAndFlags = v27 / 4;
  }
  m_data = ub->m_data;
  uba.m_size = ub->m_size;
  v17 = uba.m_size;
  if ( uba.m_size >= 4i64 )
  {
    v18 = v15 + 1;
    v19 = (char *)m_data - (char *)v15;
    v20 = ((unsigned __int64)(uba.m_size - 4i64) >> 2) + 1;
    v9 = 4 * v20;
    do
    {
      v21 = *(_DWORD *)((char *)v18 + v19 - 4);
      v18 += 4;
      *((_DWORD *)v18 - 5) = v21;
      *(v18 - 4) = *(float *)((char *)v18 + v19 - 16);
      *(v18 - 3) = *(float *)((char *)v18 + v19 - 12);
      *(v18 - 2) = *(float *)((char *)v18 + v19 - 8);
      --v20;
    }
    while ( v20 );
  }
  if ( v9 < v17 )
  {
    v22 = (char *)m_data - (char *)v15;
    v23 = &v15[v9];
    v24 = v17 - v9;
    do
    {
      v25 = *(_DWORD *)((char *)v23++ + v22);
      *((_DWORD *)v23 - 1) = v25;
      --v24;
    }
    while ( v24 );
  }
  hkaNURBS::GlobalCurveApproxErrBnd(m, Q, &uba, 0, p, E, n, U, P);
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v15, 4 * v10);
}

// File Line: 950
// RVA: 0xBAF2C0
void __fastcall hkaNURBS::GlobalCurveApproxErrBnd(
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        hkArray<float,hkContainerHeapAllocator> *ub,
        hkBool project,
        int p,
        float E,
        int *n,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P)
{
  int *v9; // r12
  hkArray<float,hkContainerHeapAllocator> *v10; // r15
  int v11; // edi
  int v12; // eax
  hkArray<float,hkContainerHeapAllocator> *v13; // rbp
  int v15; // ebx
  int v16; // eax
  int v17; // r9d
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v18; // r14
  int v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  __int64 m_size; // rax
  hkaNURBS::Point *v24; // rdi
  __int64 v25; // rbx
  float *m_data; // rdi
  __int64 v27; // rdx
  __int64 v28; // rbx
  __int64 v29; // rsi
  __int64 v30; // rdi
  int v31; // eax
  hkaNURBS::Point *v32; // rdx
  int v33; // eax
  float *v34; // r9
  int v35; // esi
  __int64 v36; // rcx
  float *v37; // rdi
  int v38; // r13d
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q_JUNK; // rdi
  int v40; // esi
  float errorBound; // xmm7_4
  int v42; // eax
  int v43; // esi
  int v44; // eax
  int v45; // eax
  int v46; // r9d
  __int64 v47; // rax
  hkaNURBS::Point *v48; // rdi
  __int64 v49; // rbx
  int v50; // ebp
  int v51; // esi
  int v52; // eax
  int v53; // eax
  int v54; // r9d
  __int64 v55; // rax
  hkaNURBS::Point *v56; // rdi
  __int64 v57; // rbx
  bool v58; // cc
  hkArray<float,hkContainerHeapAllocator> *v59; // [rsp+38h] [rbp-E0h]
  hkResult result; // [rsp+70h] [rbp-A8h] BYREF
  int v61; // [rsp+74h] [rbp-A4h]
  float *v62; // [rsp+78h] [rbp-A0h]
  hkArray<float,hkContainerHeapAllocator> e; // [rsp+80h] [rbp-98h] BYREF
  int v64; // [rsp+120h] [rbp+8h] BYREF
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Qa; // [rsp+128h] [rbp+10h]
  hkArray<float,hkContainerHeapAllocator> *v66; // [rsp+130h] [rbp+18h]
  hkBool v67; // [rsp+138h] [rbp+20h]

  v67.m_bool = project.m_bool;
  v66 = ub;
  Qa = Q;
  v64 = m;
  v9 = n;
  v10 = U;
  *n = m;
  v11 = m + 3;
  v12 = v10->m_capacityAndFlags & 0x3FFFFFFF;
  v13 = ub;
  v15 = m;
  if ( v12 < m + 3 )
  {
    v16 = 2 * v12;
    v17 = m + 3;
    if ( v11 < v16 )
      v17 = v16;
    hkArrayUtil::_reserve((hkResult *)&n, &hkContainerHeapAllocator::s_alloc, v10, v17, 4);
  }
  v18 = P;
  v10->m_size = v11;
  v19 = *v9 + 1;
  v20 = v18->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < v19 )
  {
    v21 = 2 * v20;
    v22 = *v9 + 1;
    if ( v19 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve((hkResult *)&n, &hkContainerHeapAllocator::s_alloc, v18, v22, 16);
  }
  m_size = v18->m_size;
  v24 = &v18->m_data[m_size];
  if ( v19 - (int)m_size > 0 )
  {
    v25 = (unsigned int)(v19 - m_size);
    do
    {
      if ( v24 )
        hkaNURBS::Point::Point(v24, 0.0, 0.0, 0.0, 0.0);
      ++v24;
      --v25;
    }
    while ( v25 );
    v15 = v64;
  }
  v18->m_size = v19;
  m_data = v13->m_data;
  *v10->m_data = *v13->m_data;
  v10->m_data[v15 + 2] = m_data[v15];
  if ( v15 >= 0 )
  {
    v27 = 0i64;
    v28 = 0i64;
    v29 = v64 + 1;
    do
    {
      v30 = v27 + 4;
      v31 = *(_DWORD *)((char *)v13->m_data + v27);
      v32 = Q->m_data;
      *(_DWORD *)((char *)v10->m_data + v30) = v31;
      hkaNURBS::Point::operator=(&v18->m_data[v28], &v32[v28]);
      ++v28;
      v27 = v30;
      --v29;
    }
    while ( v29 );
    v15 = v64;
  }
  v33 = v15 + 1;
  if ( v15 == -1 )
  {
    v34 = 0i64;
  }
  else
  {
    LODWORD(n) = 4 * v33;
    v34 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &n);
    v33 = (int)n / 4;
  }
  v35 = 0x80000000;
  v62 = v34;
  if ( v33 )
    v35 = v33;
  e.m_data = v34;
  e.m_size = v15 + 1;
  v36 = v15 + 1;
  LODWORD(U) = v35;
  e.m_capacityAndFlags = v35;
  if ( v15 + 1 > 0 )
  {
    v37 = v34;
    while ( v36 )
    {
      *v37++ = 0.0;
      --v36;
    }
  }
  v38 = 1;
  if ( p >= 1 )
  {
    Q_JUNK = Qa;
    v40 = p;
    errorBound = E;
    while ( 1 )
    {
      v42 = hkaNURBS::RemoveKnotsBoundCurve(v9, v38, v10, v18, v15, v13, &e, errorBound, Q_JUNK);
      v61 = v42;
      if ( v38 == v40 )
        break;
      *v9 += hkaNURBS::DegreeElevateKnotVector(v10, v38 + *v9 + 1) + 1;
      v43 = *v9 + 1;
      v44 = v18->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v44 >= v43 )
      {
        LODWORD(P) = 0;
      }
      else
      {
        v45 = 2 * v44;
        v46 = *v9 + 1;
        if ( v43 < v45 )
          v46 = v45;
        hkArrayUtil::_reserve((hkResult *)&P, &hkContainerHeapAllocator::s_alloc, v18, v46, 16);
      }
      v47 = v18->m_size;
      v48 = &v18->m_data[v47];
      if ( v43 - (int)v47 > 0 )
      {
        v49 = (unsigned int)(v43 - v47);
        do
        {
          if ( v48 )
            hkaNURBS::Point::Point(v48, 0.0, 0.0, 0.0, 0.0);
          ++v48;
          --v49;
        }
        while ( v49 );
        v15 = v64;
      }
      Q_JUNK = Qa;
      v59 = v66;
      v18->m_size = v43;
      v50 = v38 + 1;
      hkaNURBS::LeastSquaresFit((hkBool *)&n, *v9, v38 + 1, v18, v10, v15, Q_JUNK, v59, 0.0000099999997, errorBound);
      if ( !(_BYTE)n )
      {
        *v9 += -1 - hkaNURBS::DegreeLowerKnotVector(v10, v38 + *v9 + 1);
        v51 = *v9 + 1;
        v52 = v18->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v52 >= v51 )
        {
          result.m_enum = HK_SUCCESS;
        }
        else
        {
          v53 = 2 * v52;
          v54 = *v9 + 1;
          if ( v51 < v53 )
            v54 = v53;
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, v18, v54, 16);
        }
        v55 = v18->m_size;
        v56 = &v18->m_data[v55];
        if ( v51 - (int)v55 > 0 )
        {
          v57 = (unsigned int)(v51 - v55);
          do
          {
            if ( v56 )
              hkaNURBS::Point::Point(v56, 0.0, 0.0, 0.0, 0.0);
            ++v56;
            --v57;
          }
          while ( v57 );
          v15 = v64;
        }
        v18->m_size = v51;
        hkaNURBS::DegreeElevateCurve(v9, v38, v10, v18, 1);
        Q_JUNK = Qa;
      }
      hkaNURBS::UpdateFit(v15, Q_JUNK, *v9, v50, v10, v18, &e, v66, 100, 10, 0.000001, 0.000001, v67);
      v40 = p;
      ++v38;
      v58 = v50 <= p;
      v13 = v66;
      if ( !v58 )
      {
        v42 = v61;
        break;
      }
    }
    if ( v42 )
    {
      hkaNURBS::LeastSquaresFit((hkBool *)&v64, *v9, v40, v18, v10, v15, Q_JUNK, v13, 0.0000099999997, errorBound);
      hkaNURBS::UpdateFit(v15, Q_JUNK, *v9, v40, v10, v18, &e, v13, 100, 10, 0.000001, 0.000001, v67);
      hkaNURBS::RemoveKnotsBoundCurve(v9, v40, v10, v18, v15, v13, &e, errorBound, Q_JUNK);
    }
    v34 = v62;
    v35 = (int)U;
  }
  if ( v35 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v34, 4 * v35);
}

// File Line: 1055
// RVA: 0xBB30E0
__int64 __fastcall hkaNURBS::Find(float val, hkArray<float,hkContainerHeapAllocator> *arr, unsigned int m)
{
  float *m_data; // r10
  int v4; // r9d
  int v5; // edx

  m_data = arr->m_data;
  v4 = 0;
  v5 = (int)m / 2;
  if ( val > m_data[m] )
    return m + 1;
  if ( val <= *m_data )
    return 0i64;
  if ( v5 )
  {
    do
    {
      if ( val > m_data[v5] )
        v4 = v5;
      else
        m = v5;
      v5 = (int)(m + v4) / 2;
    }
    while ( v4 != v5 );
  }
  return m;
}

// File Line: 1080
// RVA: 0xBB1ED0
float __fastcall hkaNURBS::Distance3D(hkaNURBS::Point *a, hkaNURBS::Point *b)
{
  hkaNURBS::Point *v2; // rax
  hkaNURBS::Point result; // [rsp+20h] [rbp-18h] BYREF

  v2 = hkaNURBS::Point::operator-(b, &result, a);
  return hkaNURBS::Point::mag(v2);
}

// File Line: 1090
// RVA: 0xBB1F00
__int64 __fastcall hkaNURBS::Multiplicity(int i, int m, hkArray<float,hkContainerHeapAllocator> *U)
{
  unsigned int v3; // r11d
  float *v4; // r10
  int v5; // eax
  float v6; // xmm0_4
  int v7; // edx
  int v8; // r9d
  float v9; // xmm0_4
  float *v10; // r8

  v3 = 0;
  if ( i <= m )
  {
    v4 = &U->m_data[i];
    v5 = i;
    v6 = *v4;
    do
    {
      if ( v6 != *v4 )
        break;
      ++v5;
      ++v3;
      ++v4;
    }
    while ( v5 <= m );
  }
  v7 = i - 1;
  v8 = 1;
  if ( i - 1 < 0 )
    return v3;
  v9 = U->m_data[i];
  v10 = &U->m_data[i - 1];
  do
  {
    if ( v9 != *v10 )
      break;
    ++v8;
    --v10;
    --v7;
  }
  while ( v7 >= 0 );
  return v8 + v3 - 1;
}

// File Line: 1112
// RVA: 0xBB2F90
void __fastcall hkaNURBS::ComputeBounds(
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        hkArray<float,hkContainerHeapAllocator> *B,
        int lo,
        int hi)
{
  __int64 r; // rsi
  int v8; // r14d
  hkArray<float,hkContainerHeapAllocator> *v9; // rbx
  int v12; // r12d
  float *v13; // rdi
  __int64 i; // rcx
  __int64 v15; // rbp
  float *m_data; // rdi
  float *v17; // rbx
  int s; // eax

  r = lo;
  v8 = hi;
  v9 = B;
  v12 = n + p;
  if ( lo <= hi )
  {
    v13 = &B->m_data[lo];
    for ( i = hi - (__int64)lo + 1; i; --i )
      *v13++ = 3.40282e38;
    if ( (int)r <= v8 )
    {
      v15 = r;
      do
      {
        if ( hkaNURBS::IsUnique((hkBool *)&lo, r, U, v12 + 1)->m_bool )
        {
          m_data = U->m_data;
          v17 = v9->m_data;
          s = hkaNURBS::Multiplicity(r, v12 + 1, U);
          v17[v15] = hkaNURBS::GetRemovalBoundCurve(n, p, U, P, m_data[v15], r, s);
        }
        v9 = B;
        LODWORD(r) = r + 1;
        ++v15;
      }
      while ( (int)r <= v8 );
    }
  }
}

// File Line: 1135
// RVA: 0xBB30A0
__int64 __fastcall hkaNURBS::UniqueKnotCount(hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  int v2; // r8d
  float *m_data; // rcx
  __int64 i; // rax

  v2 = 0;
  if ( m > 0 )
  {
    m_data = U->m_data;
    for ( i = 0i64; i < m; ++i )
    {
      if ( m_data[i + 1] != m_data[i] )
        ++v2;
    }
  }
  return (unsigned int)(v2 + 1);
}

// File Line: 1152
// RVA: 0xBB4270
__int64 __fastcall hkaNURBS::UniqueKnot(unsigned int i, hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  unsigned int j; // ebx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  for ( j = i; !hkaNURBS::IsUnique(&result, j, U, m)->m_bool; ++j )
    ;
  return j;
}

// File Line: 1166
// RVA: 0xBB42E0
void __fastcall hkaNURBS::Remove(int i, hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  float *v3; // rax
  int v4; // r9d
  __int64 v5; // rdx
  int v6; // ecx

  --U->m_size;
  v3 = &U->m_data[i];
  v4 = 4 * (U->m_size - i);
  if ( v4 > 0 )
  {
    v5 = ((unsigned int)(v4 - 1) >> 2) + 1;
    do
    {
      v6 = *((_DWORD *)v3++ + 1);
      *((_DWORD *)v3 - 1) = v6;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 1180
// RVA: 0xBB3140
__int64 __fastcall hkaNURBS::DegreeElevateKnotVector(hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  __int64 v2; // rsi
  int v4; // eax
  int v5; // ebp
  int v6; // edx
  int v7; // r14d
  int v8; // edi
  int v9; // edx
  int v10; // r9d
  __int64 v11; // r9
  __int64 v12; // rdx
  __int64 v13; // r8
  unsigned __int64 v14; // r10
  float v15; // xmm0_4
  __int64 v16; // rdx
  float v17; // xmm0_4
  __int64 v18; // rdx
  float v19; // xmm0_4
  __int64 v20; // rdx
  float v21; // xmm0_4
  __int64 v22; // rdx
  float v23; // xmm0_4
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  v2 = m;
  v4 = hkaNURBS::UniqueKnotCount(U, m);
  v5 = v4 + v2;
  v6 = U->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = v4;
  v8 = v4 + v2 + 1;
  if ( v6 < v8 )
  {
    v9 = 2 * v6;
    v10 = v4 + v2 + 1;
    if ( v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, U, v10, 4);
  }
  U->m_size = v8;
  v11 = v2;
  v12 = v5;
  if ( v2 >= 4 )
  {
    v13 = 4 * v2 - 8;
    v14 = ((unsigned __int64)(v2 - 4) >> 2) + 1;
    v11 = v2 - 4 * v14;
    do
    {
      v15 = *(float *)((char *)U->m_data + v13 + 8);
      if ( v15 != *(float *)((char *)U->m_data + v13 + 4) )
        U->m_data[v12--] = v15;
      v16 = v12 - 1;
      U->m_data[v16 + 1] = *(float *)((char *)U->m_data + v13 + 8);
      v17 = *(float *)((char *)U->m_data + v13 + 4);
      if ( v17 != *(float *)((char *)U->m_data + v13) )
        U->m_data[v16--] = v17;
      v18 = v16 - 1;
      U->m_data[v18 + 1] = *(float *)((char *)U->m_data + v13 + 4);
      v19 = *(float *)((char *)U->m_data + v13);
      if ( v19 != *(float *)((char *)U->m_data + v13 - 4) )
        U->m_data[v18--] = v19;
      v20 = v18 - 1;
      U->m_data[v20 + 1] = *(float *)((char *)U->m_data + v13);
      v21 = *(float *)((char *)U->m_data + v13 - 4);
      if ( v21 != *(float *)((char *)U->m_data + v13 - 8) )
        U->m_data[v20--] = v21;
      v12 = v20 - 1;
      v13 -= 16i64;
      U->m_data[v12 + 1] = *(float *)((char *)U->m_data + v13 + 12);
      --v14;
    }
    while ( v14 );
  }
  if ( v11 > 0 )
  {
    v22 = v12;
    do
    {
      v23 = U->m_data[v11];
      if ( v23 != U->m_data[v11 - 1] )
        U->m_data[v22--] = v23;
      U->m_data[v22--] = U->m_data[v11--];
    }
    while ( v11 > 0 );
  }
  return (unsigned int)(v7 - 2);
}

// File Line: 1212
// RVA: 0xBB32E0
__int64 __fastcall hkaNURBS::DegreeLowerKnotVector(hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  int v2; // ebx
  __int64 v5; // r9
  __int64 v6; // rax
  __int64 v7; // r8
  unsigned __int64 v8; // r10
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  __int64 v13; // rcx
  float v14; // xmm0_4
  int v15; // esi
  int v16; // eax
  int v17; // eax
  int v18; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v2 = 0;
  v5 = 0i64;
  v6 = 0i64;
  if ( m >= 4i64 )
  {
    v7 = 2i64;
    v8 = ((unsigned __int64)(m - 4i64) >> 2) + 1;
    v5 = 4 * v8;
    do
    {
      v9 = U->m_data[v7 - 2];
      if ( v9 == U->m_data[v7 - 1] )
      {
        U->m_data[v6] = v9;
        ++v2;
        ++v6;
      }
      v10 = U->m_data[v7 - 1];
      if ( v10 == U->m_data[v7] )
      {
        U->m_data[v6] = v10;
        ++v2;
        ++v6;
      }
      v11 = U->m_data[v7];
      if ( v11 == U->m_data[v7 + 1] )
      {
        U->m_data[v6] = v11;
        ++v2;
        ++v6;
      }
      v12 = U->m_data[v7 + 1];
      if ( v12 == U->m_data[v7 + 2] )
      {
        U->m_data[v6] = v12;
        ++v2;
        ++v6;
      }
      v7 += 4i64;
      --v8;
    }
    while ( v8 );
  }
  if ( v5 < m )
  {
    v13 = v6;
    do
    {
      v14 = U->m_data[v5];
      if ( v14 == U->m_data[v5 + 1] )
      {
        U->m_data[v13] = v14;
        ++v2;
        ++v13;
      }
      ++v5;
    }
    while ( v5 < m );
  }
  v15 = v2 + 1;
  U->m_data[v2] = U->m_data[m];
  v16 = U->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v2 + 1 )
  {
    v17 = 2 * v16;
    v18 = v2 + 1;
    if ( v15 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, U, v18, 4);
  }
  U->m_size = v15;
  return (unsigned int)(m - v2 - 1);
}

// File Line: 1238
// RVA: 0xBB4330
void __fastcall hkaNURBS::RemoveSubtractOne(int i, hkArray<int,hkContainerHeapAllocator> *U, int m)
{
  __int64 v4; // rax
  int *v5; // r9
  int v6; // edx
  __int64 v7; // rdx
  int v8; // ecx

  --U->m_size;
  v4 = i;
  v5 = &U->m_data[i];
  v6 = 4 * (U->m_size - i);
  if ( v6 > 0 )
  {
    v7 = ((unsigned int)(v6 - 1) >> 2) + 1;
    do
    {
      v8 = v5[1];
      *v5++ = v8;
      --v7;
    }
    while ( v7 );
  }
  for ( ; v4 < m; --U->m_data[v4 - 1] )
    ++v4;
}

// File Line: 1252
// RVA: 0xBB4710
hkBool *__fastcall hkaNURBS::IsUnique(hkBool *result, int i, hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  if ( i == m || U->m_data[i + 1] != U->m_data[i] )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 1264
// RVA: 0xBB4A30
__int64 __fastcall hkaNURBS::MinIndex(hkArray<float,hkContainerHeapAllocator> *arr, int len)
{
  float *m_data; // rbx
  int v5; // ecx
  unsigned int v6; // r8d
  __int64 v7; // rdi
  float v8; // xmm0_4
  int v9; // r11d
  int v10; // r9d
  float *v11; // rdx
  float *v12; // rdx

  if ( len <= 0 )
    return 0xFFFFFFFFi64;
  m_data = arr->m_data;
  v5 = 1;
  v6 = 0;
  v7 = 1i64;
  v8 = *m_data;
  if ( len > 1 )
  {
    if ( len - 1 >= 4 )
    {
      v9 = len - 3;
      v10 = 3;
      v11 = m_data + 3;
      v7 = 4i64 * (((unsigned int)(v9 - 2) >> 2) + 1) + 1;
      do
      {
        if ( *(v11 - 2) < v8 )
        {
          v8 = *(v11 - 2);
          v6 = v5;
        }
        if ( *(v11 - 1) < v8 )
        {
          v8 = *(v11 - 1);
          v6 = v10 - 1;
        }
        if ( *v11 < v8 )
        {
          v8 = *v11;
          v6 = v10;
        }
        if ( v11[1] < v8 )
        {
          v8 = v11[1];
          v6 = v10 + 1;
        }
        v5 += 4;
        v11 += 4;
        v10 += 4;
      }
      while ( v5 < v9 );
    }
    if ( v5 < len )
    {
      v12 = &m_data[v7];
      do
      {
        if ( *v12 < v8 )
        {
          v8 = *v12;
          v6 = v5;
        }
        ++v5;
        ++v12;
      }
      while ( v5 < len );
    }
  }
  return v6;
}

// File Line: 1288
// RVA: 0xBB4B20
__int64 __fastcall hkaNURBS::MaxIndex(hkArray<float,hkContainerHeapAllocator> *arr, int len)
{
  float *m_data; // rbx
  int v5; // ecx
  unsigned int v6; // r8d
  __int64 v7; // rdi
  float v8; // xmm0_4
  int v9; // r11d
  int v10; // r9d
  float *v11; // rdx
  float *v12; // rdx

  if ( len <= 0 )
    return 0xFFFFFFFFi64;
  m_data = arr->m_data;
  v5 = 1;
  v6 = 0;
  v7 = 1i64;
  v8 = *m_data;
  if ( len > 1 )
  {
    if ( len - 1 >= 4 )
    {
      v9 = len - 3;
      v10 = 3;
      v11 = m_data + 3;
      v7 = 4i64 * (((unsigned int)(v9 - 2) >> 2) + 1) + 1;
      do
      {
        if ( *(v11 - 2) > v8 )
        {
          v8 = *(v11 - 2);
          v6 = v5;
        }
        if ( *(v11 - 1) > v8 )
        {
          v8 = *(v11 - 1);
          v6 = v10 - 1;
        }
        if ( *v11 > v8 )
        {
          v8 = *v11;
          v6 = v10;
        }
        if ( v11[1] > v8 )
        {
          v8 = v11[1];
          v6 = v10 + 1;
        }
        v5 += 4;
        v11 += 4;
        v10 += 4;
      }
      while ( v5 < v9 );
    }
    if ( v5 < len )
    {
      v12 = &m_data[v7];
      do
      {
        if ( *v12 > v8 )
        {
          v8 = *v12;
          v6 = v5;
        }
        ++v5;
        ++v12;
      }
      while ( v5 < len );
    }
  }
  return v6;
}

// File Line: 1317
// RVA: 0xBB3FC0
hkBool *__fastcall hkaNURBS::IsWellPosed(
        hkBool *result,
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        int mb,
        hkArray<float,hkContainerHeapAllocator> *ub,
        float tol)
{
  __int64 v7; // rsi
  __int64 v8; // rbx
  int v9; // r15d
  int v10; // eax
  unsigned __int64 v12; // rdi
  void *v13; // rbp
  int v14; // r14d
  __int64 v15; // r12
  __int64 v16; // rdi
  int v17; // r14d
  hkArray<float,hkContainerHeapAllocator> *v18; // rbx
  float v19; // xmm7_4
  float v20; // xmm6_4
  int v21; // eax
  __int64 v22; // rcx
  float v23; // xmm0_4
  int v24; // eax
  __int64 v25; // rdi
  hkBool *v26; // rdi
  int v28; // [rsp+20h] [rbp-68h]
  int na; // [rsp+98h] [rbp+10h] BYREF
  int v31; // [rsp+A0h] [rbp+18h] BYREF

  na = n;
  v7 = p;
  v8 = 0i64;
  v9 = p + n + 1;
  v10 = n + 1;
  v12 = n + 1;
  if ( n == -1 )
  {
    v13 = 0i64;
  }
  else
  {
    v31 = n + 1;
    v13 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v31);
    v10 = v31;
  }
  v14 = 0x80000000;
  if ( v10 )
    v14 = v10;
  v28 = v14;
  if ( (int)v12 > 0 )
    memset(v13, 0, v12);
  v15 = mb;
  v16 = 0i64;
  if ( mb >= 0i64 )
  {
    v17 = na;
    v18 = ub;
    v19 = tol;
    do
    {
      v20 = v18->m_data[v16];
      hkaNURBS::FindSpan(v17, v7, v20, U);
      v22 = v21;
      v23 = v19 + U->m_data[v21];
      if ( v21 == v9 )
        v24 = v9;
      else
        v24 = v21 + 1;
      if ( v20 >= v23 && v20 <= (float)(U->m_data[v24] - v19) )
        *((_BYTE *)v13 + v22 - v7) = 1;
      ++v16;
    }
    while ( v16 <= v15 );
    v14 = v28;
    v8 = 0i64;
  }
  v25 = na;
  if ( na < 0i64 )
  {
LABEL_22:
    v26 = result;
    result->m_bool = 1;
  }
  else
  {
    while ( !hkaNURBS::IsUnique((hkBool *)&na, v7, U, v9)->m_bool || *((_BYTE *)v13 + v8) )
    {
      ++v8;
      LODWORD(v7) = v7 + 1;
      if ( v8 > v25 )
        goto LABEL_22;
    }
    v26 = result;
    result->m_bool = 0;
  }
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v13, v14 & 0x3FFFFFFF);
  return v26;
}

// File Line: 1369
// RVA: 0xBB37C0
hkBool *__fastcall hkaNURBS::LeastSquaresFit(
        hkBool *result,
        hkResultEnum n,
        int p,
        hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *P,
        hkArray<float,hkContainerHeapAllocator> *U,
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        hkArray<float,hkContainerHeapAllocator> *ub,
        float numericalTolerance,
        float errorBound)
{
  __int64 v10; // rbx
  int v11; // r15d
  int m_enum; // r14d
  hkBool *v13; // rax
  int v14; // r13d
  __int64 v15; // rsi
  __int64 v16; // rdi
  int v17; // esi
  __int64 v18; // rax
  int v19; // ebx
  hkArray<float,hkContainerHeapAllocator> *v20; // r13
  float v21; // xmm0_4
  int v22; // eax
  __int64 v23; // rdi
  hkaNURBS::Point *v24; // rcx
  int v25; // r12d
  hkaNURBS::Point *v26; // rbx
  hkaNURBS::Point *v27; // rdi
  hkaNURBS::Point *v28; // rax
  hkaNURBS::Point *v29; // rax
  hkArray<float,hkContainerHeapAllocator> *v30; // r12
  hkArray<float,hkContainerHeapAllocator> *v31; // r13
  int v32; // ecx
  __int64 v33; // rax
  float *m_data; // rdi
  hkaNURBS::Point *v35; // rsi
  hkaNURBS::Point *v36; // rbx
  float v37; // xmm0_4
  hkaNURBS::Point *v38; // rbx
  float v39; // xmm0_4
  hkaNURBS::Point *v40; // rax
  __int64 v41; // rdi
  hkaNURBS::Point *v42; // rax
  hkaNURBS::Point *v43; // rax
  bool v44; // zf
  int v45; // esi
  hkArray<float,hkContainerHeapAllocator> *v46; // r13
  hkaNURBS::Point *v47; // rdi
  float *v48; // rbx
  __int64 v49; // r12
  float v50; // xmm0_4
  hkaNURBS::Point *v51; // rax
  int i; // edi
  float *v53; // rbx
  float *v54; // rax
  float v55; // xmm8_4
  hkBool *v56; // rbx
  int v57; // ebx
  int v58; // eax
  int v59; // esi
  int v60; // eax
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v61; // r14
  int v62; // edi
  int v63; // ebx
  hkaNURBS::Point *v64; // r12
  float v65; // xmm6_4
  float *v66; // rax
  int v67; // ebx
  hkRelocationInfo::Import *v68; // rcx
  int m_size; // eax
  __int64 v70; // rsi
  int v71; // r9d
  int v72; // edx
  hkaNURBS::Point *v73; // rbx
  __int64 v74; // rdi
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v75; // rbx
  hkaNURBS::Point *v76; // rdx
  int j; // edi
  float *v78; // rbx
  float *v79; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array; // [rsp+50h] [rbp-B0h] BYREF
  hkaNURBS::Point *v81; // [rsp+60h] [rbp-A0h]
  int v82; // [rsp+68h] [rbp-98h]
  hkBool v83; // [rsp+6Ch] [rbp-94h] BYREF
  __int64 v84; // [rsp+70h] [rbp-90h]
  int v85[2]; // [rsp+78h] [rbp-88h]
  int v86; // [rsp+80h] [rbp-80h] BYREF
  hkaMatrix<float> X; // [rsp+88h] [rbp-78h] BYREF
  hkaNURBS::Point v88; // [rsp+A0h] [rbp-60h] BYREF
  hkaMatrix<float> B; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v90; // [rsp+C8h] [rbp-38h]
  hkaNURBS::Point v91; // [rsp+D0h] [rbp-30h] BYREF
  hkaSparseLSQMatrix<float> A; // [rsp+E0h] [rbp-20h] BYREF
  hkaNURBS::Point v93; // [rsp+118h] [rbp+18h] BYREF
  hkaNURBS::Point v94; // [rsp+128h] [rbp+28h] BYREF
  hkaNURBS::Point resulta; // [rsp+138h] [rbp+38h] BYREF
  hkResult v97; // [rsp+1D8h] [rbp+D8h] BYREF
  int v98; // [rsp+1E0h] [rbp+E0h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v99; // [rsp+1E8h] [rbp+E8h]

  v99 = P;
  v98 = p;
  v97.m_enum = n;
  v10 = m;
  v11 = p;
  m_enum = n;
  v13 = result;
  if ( n <= m )
  {
    hkaSparseLSQMatrix<float>::hkaSparseLSQMatrix<float>(&A, m - 1, n - 1);
    v14 = 1;
    v15 = v10;
    v84 = v10;
    v16 = 1i64;
    if ( v10 > 1 )
    {
      v17 = 0;
      v18 = v10;
      do
      {
        v19 = 1;
        if ( m_enum > 1 )
        {
          v20 = U;
          do
          {
            v21 = hkaNURBS::OneBasisFun(v11, m_enum + v11 + 1, v20, v19, ub->m_data[v16]);
            hkaSparseLSQMatrix<float>::Set(&A, v17, v19++ - 1, v21);
          }
          while ( v19 < m_enum );
          v18 = v84;
          v14 = 1;
        }
        ++v16;
        ++v17;
      }
      while ( v16 < v18 );
      LODWORD(v10) = m;
      v15 = v84;
    }
    *(_QWORD *)v85 = 4i64;
    hkaMatrix<float>::hkaMatrix<float>(&B, m_enum - 1, 4, 0.0);
    v22 = v10 + 1;
    v23 = (unsigned int)(v10 + 1);
    if ( (_DWORD)v10 == -1 )
    {
      v24 = 0i64;
    }
    else
    {
      v86 = 16 * v22;
      v24 = (hkaNURBS::Point *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                 &hkContainerHeapAllocator::s_alloc,
                                 &v86);
      v22 = v86 / 16;
    }
    v25 = 0x80000000;
    v81 = v24;
    if ( v22 )
      v25 = v22;
    v82 = v25;
    if ( (int)v23 > 0 )
    {
      v26 = v24;
      do
      {
        if ( v26 )
          hkaNURBS::Point::Point(v26, 0.0, 0.0, 0.0, 0.0);
        ++v26;
        --v23;
      }
      while ( v23 );
      LODWORD(v10) = m;
    }
    v84 = 16 * v15;
    hkaNURBS::Point::Point(&v88, 0.0, 0.0, 0.0, 0.0);
    v27 = v81;
    v29 = hkaNURBS::Point::operator=(&v81[v15], v28);
    hkaNURBS::Point::operator=(v81, v29);
    if ( (int)v10 > 1 )
    {
      v30 = U;
      v31 = ub;
      v32 = m_enum + v11 + 1;
      v90 = 16i64;
      *(_QWORD *)v88.point = (unsigned int)(v10 - 1);
      v33 = 4i64;
      do
      {
        m_data = v31->m_data;
        v35 = Q->m_data;
        v36 = (hkaNURBS::Point *)((char *)Q->m_data + v84);
        v37 = hkaNURBS::OneBasisFun(v11, v32, v30, m_enum, *(float *)((char *)v31->m_data + v33));
        v38 = operator*(&resulta, v37, v36);
        v39 = hkaNURBS::OneBasisFun(v11, m_enum + v11 + 1, v30, 0, *(float *)((char *)m_data + *(_QWORD *)v85));
        v40 = operator*(&v93, v39, v35);
        v41 = v90;
        v42 = hkaNURBS::Point::operator-((hkaNURBS::Point *)((char *)v35 + v90), &v94, v40);
        v43 = hkaNURBS::Point::operator-(v42, &v91, v38);
        hkaNURBS::Point::operator=((hkaNURBS::Point *)((char *)v81 + v41), v43);
        v33 = *(_QWORD *)v85 + 4i64;
        v44 = (*(_QWORD *)v88.point)-- == 1i64;
        *(_QWORD *)v85 += 4i64;
        v90 = v41 + 16;
        v32 = v11 + 1 + m_enum;
      }
      while ( !v44 );
      v25 = v82;
      v27 = v81;
      LODWORD(v10) = m;
      v14 = 1;
    }
    v45 = 1;
    if ( m_enum > 1 )
    {
      v46 = U;
      while ( 1 )
      {
        hkaNURBS::Point::Point(&v88, 0.0, 0.0, 0.0, 0.0);
        if ( (int)v10 > 1 )
        {
          v47 = v27 + 1;
          v85[0] = m_enum + v11 + 1;
          v48 = ub->m_data + 1;
          v49 = (unsigned int)(m - 1);
          do
          {
            v50 = hkaNURBS::OneBasisFun(v11, v85[0], v46, v45, *v48);
            v51 = operator*(&v91, v50, v47);
            hkaNURBS::Point::operator+=(&v88, v51);
            ++v47;
            ++v48;
            --v49;
          }
          while ( v49 );
          m_enum = v97.m_enum;
        }
        for ( i = 0; i < 4; ++i )
        {
          v53 = hkaNURBS::Point::operator[](&v88, i);
          v54 = hkaMatrix<float>::operator()(&B, v45 - 1, i);
          *v54 = *v53;
        }
        v27 = v81;
        if ( ++v45 >= m_enum )
          break;
        LODWORD(v10) = m;
      }
      v25 = v82;
      v14 = 1;
    }
    v55 = numericalTolerance;
    if ( hkaNURBS::IsWellPosed(&v83, m_enum, v11, U, ub->m_size - 1, ub, numericalTolerance)->m_bool )
    {
      v57 = hkaMatrix<float>::Width(&B);
      v58 = hkaMatrix<float>::Height(&B);
      hkaMatrix<float>::hkaMatrix<float>(&X, v58, v57);
      v59 = 0;
      if ( (int)hkaMatrix<float>::Height(&X) > 0 )
      {
        v60 = hkaMatrix<float>::Width(&X);
        v61 = Q;
        v62 = v60;
        do
        {
          v63 = 0;
          if ( v62 > 0 )
          {
            v64 = &v61->m_data[v59 + 1];
            do
            {
              v65 = hkaNURBS::Point::operator[](v64, v63);
              v66 = hkaMatrix<float>::operator()(&X, v59, v63++);
              *v66 = v65;
              v62 = hkaMatrix<float>::Width(&X);
            }
            while ( v63 < v62 );
          }
          ++v59;
        }
        while ( v59 < (int)hkaMatrix<float>::Height(&X) );
        m_enum = v97.m_enum;
        v11 = v98;
        v25 = v82;
      }
      hkaCGSolver<float>::Solve((hkBool *)&v97, &A, &X, &B, 50, v55);
      if ( LOBYTE(v97.m_enum) )
      {
        v67 = m_enum + 1;
        v68 = 0i64;
        m_size = 0;
        array.m_capacityAndFlags = 0x80000000;
        v70 = 1i64;
        array.m_data = 0i64;
        array.m_size = 0;
        if ( m_enum + 1 > 0 )
        {
          v71 = m_enum + 1;
          if ( v67 < 0 )
            v71 = 0;
          hkArrayUtil::_reserve(&v97, &hkContainerHeapAllocator::s_alloc, &array, v71, 16);
          m_size = array.m_size;
          v68 = array.m_data;
        }
        v72 = v67 - m_size;
        v73 = (hkaNURBS::Point *)&v68[m_size];
        if ( v72 > 0 )
        {
          v74 = (unsigned int)v72;
          do
          {
            if ( v73 )
              hkaNURBS::Point::Point(v73, 0.0, 0.0, 0.0, 0.0);
            ++v73;
            --v74;
          }
          while ( v74 );
          v68 = array.m_data;
        }
        v75 = Q;
        v76 = Q->m_data;
        array.m_size = m_enum + 1;
        hkaNURBS::Point::operator=((hkaNURBS::Point *)v68, v76);
        hkaNURBS::Point::operator=(
          (hkaNURBS::Point *)&array.m_data[m_enum],
          (hkaNURBS::Point *)((char *)v75->m_data + v84));
        if ( m_enum > 1 )
        {
          do
          {
            for ( j = 0; j < 4; ++j )
            {
              v78 = hkaMatrix<float>::operator()(&X, v14 - 1, j);
              v79 = hkaNURBS::Point::operator[]((hkaNURBS::Point *)&array.m_data[v70], j);
              *v79 = *v78;
            }
            ++v14;
            ++v70;
          }
          while ( v14 < m_enum );
          v25 = v82;
          v75 = Q;
        }
        if ( hkaNURBS::WithinTolerance(
               (hkBool *)&m,
               m_enum,
               v11,
               (hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *)&array,
               U,
               m,
               v75,
               ub,
               errorBound)->m_bool )
        {
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v99, &array);
          v56 = result;
          result->m_bool = 1;
        }
        else
        {
          v56 = result;
          result->m_bool = 0;
        }
        array.m_size = 0;
        if ( array.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            array.m_data,
            16 * array.m_capacityAndFlags);
        array.m_capacityAndFlags = 0x80000000;
        array.m_data = 0i64;
      }
      else
      {
        v56 = result;
        result->m_bool = 0;
      }
      hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&X);
    }
    else
    {
      v56 = result;
      result->m_bool = 0;
    }
    if ( v25 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v81, 16 * v25);
    hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&B);
    hkaSparseLSQMatrix<float>::~hkaSparseLSQMatrix<float>(&A);
    return v56;
  }
  else
  {
    result->m_bool = 0;
  }
  return v13;
}

// File Line: 1521
// RVA: 0xBB4740
float __fastcall hkaNURBS::ClosestPoint(
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        hkaNURBS::Point *Q,
        int d,
        int maxiter,
        float e1,
        float e2)
{
  float v9; // edi
  hkaNURBS::Point *v10; // r13
  int v11; // esi
  float v14; // xmm7_4
  int v16; // ebx
  int v17; // eax
  float *m_data; // rcx
  __int64 v19; // rax
  float v20; // xmm12_4
  float v21; // xmm10_4
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v22; // rsi
  float v23; // xmm8_4
  float v24; // xmm9_4
  float v25; // xmm0_4
  int v26; // r13d
  hkaNURBS::Point *p_CK; // rbx
  int i; // edi
  bool v29; // di
  float v30; // xmm0_4
  bool v31; // bl
  float v32; // xmm8_4
  float v33; // xmm7_4
  float v34; // xmm6_4
  double v35; // xmm0_8
  float v36; // xmm1_4
  hkaNURBS::Point result; // [rsp+40h] [rbp-81h] BYREF
  hkaNURBS::Point CK; // [rsp+50h] [rbp-71h] BYREF
  hkaNURBS::Point v40; // [rsp+60h] [rbp-61h] BYREF
  hkaNURBS::Point v41; // [rsp+70h] [rbp-51h] BYREF
  __int64 v42; // [rsp+118h] [rbp+57h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v43; // [rsp+120h] [rbp+5Fh]
  hkaNURBS::Point *a; // [rsp+128h] [rbp+67h]
  float vars0; // [rsp+130h] [rbp+6Fh]
  void *retaddr; // [rsp+138h] [rbp+77h]
  float v47; // [rsp+140h] [rbp+7Fh]
  float v48; // [rsp+148h] [rbp+87h]

  v9 = vars0;
  v10 = a;
  v11 = 0;
  v14 = FLOAT_3_40282e38;
  v16 = 0;
  v17 = n + 1;
  m_data = U->m_data;
  v19 = p + v17;
  v42 = v19;
  v20 = *m_data;
  v21 = *m_data;
  if ( vars0 >= 0.0 )
  {
    v22 = v43;
    v23 = m_data[v19] - v20;
    v24 = 1.0 / (float)SLODWORD(vars0);
    do
    {
      hkaNURBS::CurvePoint(&result, n, p, U, v22, (float)((float)((float)v16 * v24) * v23) + v20);
      v25 = hkaNURBS::Point::Dist(&result, v10);
      if ( v25 < v14 )
      {
        v14 = v25;
        v21 = (float)((float)((float)v16 * v24) * v23) + v20;
      }
      ++v16;
    }
    while ( v16 <= SLODWORD(v9) );
    v11 = 0;
  }
  v26 = (int)retaddr;
  if ( (int)retaddr <= 0 )
    return v21;
  do
  {
    p_CK = &CK;
    for ( i = 2; i >= 0; --i )
      hkaNURBS::Point::Point(p_CK++, 0.0, 0.0, 0.0, 0.0);
    hkaNURBS::CurveDerivs(n, p, U, v43, v21, 2, &CK);
    hkaNURBS::Point::operator-=(&CK, a);
    v29 = v47 >= hkaNURBS::Point::mag(&CK);
    v30 = hkaNURBS::Point::Cos(&v40, &CK);
    v31 = v48 >= v30;
    if ( v29 && v48 >= v30 )
      break;
    vars0 = v20;
    v32 = v21;
    v33 = hkaNURBS::Point::Dot(&v40, &CK);
    v34 = hkaNURBS::Point::Dot(&v41, &CK);
    v35 = hkaNURBS::Point::mag2(&v40);
    v36 = fmaxf(v21 - (float)(v33 / (float)(v34 + *(float *)&v35)), vars0);
    vars0 = U->m_data[v42];
    *(float *)&retaddr = v36;
    v21 = fminf(v36, vars0);
    vars0 = v21 - v32;
    if ( v29 )
      break;
    if ( v31 )
      break;
    if ( (float)(hkaNURBS::Point::mag(&v40) * COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v21 - v32)) >> 1)) <= v47 )
      break;
    ++v11;
  }
  while ( v11 < v26 );
  return v21;
}

// File Line: 1606
// RVA: 0xBB4570
void __fastcall hkaNURBS::UpdateFit(
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        int n,
        int p,
        hkArray<float,hkContainerHeapAllocator> *U,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        hkArray<float,hkContainerHeapAllocator> *e,
        hkArray<float,hkContainerHeapAllocator> *ub,
        int density,
        int maxiter,
        float e1,
        float e2,
        hkBool project)
{
  __int64 v13; // rbx
  __int64 v17; // rdi
  float v18; // xmm6_4
  hkaNURBS::Point *v19; // rcx
  hkaNURBS::Point *v20; // rax
  float v21; // xmm0_4
  bool v22; // zf
  __int64 v23; // [rsp+50h] [rbp-88h]
  hkaNURBS::Point result; // [rsp+58h] [rbp-80h] BYREF
  hkaNURBS::Point v25; // [rsp+68h] [rbp-70h] BYREF

  if ( m >= 0 )
  {
    v13 = 0i64;
    v17 = 0i64;
    v23 = (unsigned int)(m + 1);
    do
    {
      if ( project.m_bool )
        v18 = hkaNURBS::ClosestPoint(n, p, U, P, &Q->m_data[v17], density, maxiter, e1, e2);
      else
        v18 = ub->m_data[v13];
      hkaNURBS::CurvePoint(&result, n, p, U, P, v18);
      v19 = &Q->m_data[v17];
      ub->m_data[v13] = v18;
      v20 = hkaNURBS::Point::operator-(v19, &v25, &result);
      v21 = hkaNURBS::Point::mag(v20);
      ++v13;
      ++v17;
      v22 = v23-- == 1;
      e->m_data[v13 - 1] = v21;
    }
    while ( !v22 );
  }
}

// File Line: 1660
// RVA: 0xBB3440
hkBool *__fastcall hkaNURBS::WithinTolerance(
        hkBool *result,
        int n,
        int p,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        hkArray<float,hkContainerHeapAllocator> *U,
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        hkArray<float,hkContainerHeapAllocator> *ub,
        float E)
{
  __int64 v13; // rbp
  float *m_data; // rdi
  hkaNURBS::Point *v15; // rbx
  float u; // xmm0_4
  hkaNURBS::Point v18; // [rsp+30h] [rbp-58h] BYREF
  hkaNURBS::Point resulta; // [rsp+40h] [rbp-48h] BYREF

  result->m_bool = 1;
  if ( m >= 0i64 )
  {
    v13 = m + 1i64;
    m_data = ub->m_data;
    v15 = Q->m_data;
    do
    {
      u = *m_data;
      v18 = *v15;
      hkaNURBS::CurvePoint(&resulta, n, p, U, P, u);
      if ( hkaNURBS::Point::Dist(&v18, &resulta) > (float)(E * 1.1) )
        result->m_bool = 0;
      ++v15;
      ++m_data;
      --v13;
    }
    while ( v13 );
  }
  return result;
}

// File Line: 1695
// RVA: 0xBB3550
hkBool *__fastcall hkaNURBS::WithinTolerance(
        hkBool *result,
        int n,
        int p,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        hkArray<float,hkContainerHeapAllocator> *U,
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        hkArray<float,hkContainerHeapAllocator> *ub,
        hkArray<float,hkContainerHeapAllocator> *E)
{
  __int64 v9; // rbx
  float *m_data; // rsi
  hkaNURBS::Point *v14; // rdi
  signed __int64 v15; // r15
  float u; // xmm0_4
  hkaNURBS::Point v18; // [rsp+30h] [rbp-58h] BYREF
  hkaNURBS::Point resulta; // [rsp+40h] [rbp-48h] BYREF
  int v20; // [rsp+98h] [rbp+10h]

  v20 = n;
  v9 = 0i64;
  if ( m < 0i64 )
  {
LABEL_5:
    result->m_bool = 1;
  }
  else
  {
    m_data = E->m_data;
    v14 = Q->m_data;
    v15 = (char *)ub->m_data - (char *)E->m_data;
    while ( 1 )
    {
      u = *(float *)((char *)m_data + v15);
      v18 = *v14;
      hkaNURBS::CurvePoint(&resulta, n, p, U, P, u);
      if ( hkaNURBS::Point::Dist(&v18, &resulta) > (float)(*m_data + 0.001) )
        break;
      n = v20;
      ++v9;
      ++v14;
      ++m_data;
      if ( v9 > m )
        goto LABEL_5;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 1723
// RVA: 0xBB3670
hkBool *__fastcall hkaNURBS::WithinTolerance(
        hkBool *result,
        int n,
        int p,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P,
        hkArray<float,hkContainerHeapAllocator> *U,
        int m,
        hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q,
        float E)
{
  int v8; // ebx
  __int64 v13; // rdi
  hkaNURBS::Point *m_data; // rcx
  float v15; // xmm0_4
  hkaNURBS::Point Pa; // [rsp+50h] [rbp-68h] BYREF
  hkaNURBS::Point resulta; // [rsp+60h] [rbp-58h] BYREF

  v8 = 0;
  if ( m < 0 )
  {
LABEL_5:
    result->m_bool = 1;
  }
  else
  {
    v13 = 0i64;
    while ( 1 )
    {
      m_data = Q->m_data;
      Pa = Q->m_data[v13];
      v15 = hkaNURBS::ClosestPoint(n, p, U, P, &m_data[v8], 100, 10, 0.000099999997, 0.000099999997);
      hkaNURBS::CurvePoint(&resulta, n, p, U, P, v15);
      if ( hkaNURBS::Point::Dist(&Pa, &resulta) > E )
        break;
      ++v8;
      ++v13;
      if ( v8 > m )
        goto LABEL_5;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 1776
// RVA: 0xBAE3B0
void __fastcall hkaNURBS::Point::Point(hkaNURBS::Point *this, float x, float y, float z, float w)
{
  this->point[0] = x;
  this->point[1] = y;
  this->point[3] = w;
  this->point[2] = z;
}

// File Line: 1784
// RVA: 0xBAE3E0
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator=(hkaNURBS::Point *this, hkaNURBS::Point *a)
{
  *this = *a;
  return this;
}

// File Line: 1794
// RVA: 0xBAE400
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator+=(hkaNURBS::Point *this, hkaNURBS::Point *a)
{
  hkaNURBS::Point *result; // rax

  result = this;
  this->point[0] = a->point[0] + this->point[0];
  this->point[1] = a->point[1] + this->point[1];
  this->point[2] = a->point[2] + this->point[2];
  this->point[3] = a->point[3] + this->point[3];
  return result;
}

// File Line: 1804
// RVA: 0xBAE450
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator-=(hkaNURBS::Point *this, hkaNURBS::Point *a)
{
  float v2; // xmm1_4
  hkaNURBS::Point *result; // rax
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = this->point[1];
  result = this;
  this->point[0] = this->point[0] - a->point[0];
  v4 = this->point[2];
  this->point[1] = v2 - a->point[1];
  v5 = this->point[3];
  this->point[2] = v4 - a->point[2];
  this->point[3] = v5 - a->point[3];
  return result;
}

// File Line: 1814
// RVA: 0xBAE4A0
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator*=(hkaNURBS::Point *this, float d)
{
  hkaNURBS::Point *result; // rax
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  result = this;
  v3 = d * this->point[1];
  this->point[0] = d * this->point[0];
  this->point[1] = v3;
  v4 = d * this->point[2];
  v5 = d * this->point[3];
  this->point[2] = v4;
  this->point[3] = v5;
  return result;
}

// File Line: 1824
// RVA: 0xBAE4E0
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator=/(hkaNURBS::Point *this, float d)
{
  hkaNURBS::Point *result; // rax
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm2_4

  result = this;
  v3 = 1.0 / d;
  v4 = 1.0 / d;
  v5 = (float)(1.0 / d) * this->point[1];
  this->point[0] = v4 * this->point[0];
  this->point[1] = v5;
  v6 = v3 * this->point[2];
  v7 = v3 * this->point[3];
  this->point[2] = v6;
  this->point[3] = v7;
  return result;
}

// File Line: 1834
// RVA: 0xBAE530
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator+(
        hkaNURBS::Point *this,
        hkaNURBS::Point *result,
        hkaNURBS::Point *a)
{
  hkaNURBS::Point *v4; // rax
  float v5; // ecx
  hkaNURBS::Point v7; // [rsp+20h] [rbp-18h] BYREF

  v7 = *this;
  v4 = hkaNURBS::Point::operator+=(&v7, a);
  result->point[0] = v4->point[0];
  result->point[1] = v4->point[1];
  v5 = v4->point[2];
  *(float *)&v4 = v4->point[3];
  result->point[2] = v5;
  LODWORD(result->point[3]) = (_DWORD)v4;
  return result;
}

// File Line: 1841
// RVA: 0xBAE590
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator-(
        hkaNURBS::Point *this,
        hkaNURBS::Point *result,
        hkaNURBS::Point *a)
{
  hkaNURBS::Point *v4; // rax
  float v5; // ecx
  hkaNURBS::Point v7; // [rsp+20h] [rbp-18h] BYREF

  v7 = *this;
  v4 = hkaNURBS::Point::operator-=(&v7, a);
  result->point[0] = v4->point[0];
  result->point[1] = v4->point[1];
  v5 = v4->point[2];
  *(float *)&v4 = v4->point[3];
  result->point[2] = v5;
  LODWORD(result->point[3]) = (_DWORD)v4;
  return result;
}

// File Line: 1848
// RVA: 0xBAE5F0
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator*(hkaNURBS::Point *this, hkaNURBS::Point *result, float d)
{
  hkaNURBS::Point *v4; // rax
  float v5; // ecx
  hkaNURBS::Point v7; // [rsp+20h] [rbp-18h] BYREF

  v7 = *this;
  v4 = hkaNURBS::Point::operator*=(&v7, d);
  result->point[0] = v4->point[0];
  result->point[1] = v4->point[1];
  v5 = v4->point[2];
  *(float *)&v4 = v4->point[3];
  result->point[2] = v5;
  LODWORD(result->point[3]) = (_DWORD)v4;
  return result;
}

// File Line: 1855
// RVA: 0xBAE650
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator/(hkaNURBS::Point *this, hkaNURBS::Point *result, float d)
{
  hkaNURBS::Point *v4; // rax
  float v5; // ecx
  hkaNURBS::Point v7; // [rsp+20h] [rbp-18h] BYREF

  v7 = *this;
  v4 = hkaNURBS::Point::operator=/(&v7, d);
  result->point[0] = v4->point[0];
  result->point[1] = v4->point[1];
  v5 = v4->point[2];
  *(float *)&v4 = v4->point[3];
  result->point[2] = v5;
  LODWORD(result->point[3]) = (_DWORD)v4;
  return result;
}

// File Line: 1862
// RVA: 0xBB4C10
hkaNURBS::Point *__fastcall operator*(hkaNURBS::Point *result, float d, hkaNURBS::Point *p)
{
  hkaNURBS::Point::operator*(p, result, d);
  return result;
}

// File Line: 1867
// RVA: 0xBB4C40
hkaNURBS::Point *__fastcall operator/(hkaNURBS::Point *result, float d, hkaNURBS::Point *p)
{
  hkaNURBS::Point::operator/(p, result, d);
  return result;
}

// File Line: 1872
// RVA: 0xBAE6D0
double __fastcall hkaNURBS::Point::mag2(hkaNURBS::Point *this)
{
  double result; // xmm0_8

  *(float *)&result = hkaNURBS::Point::Dot(this, this);
  return result;
}

// File Line: 1877
// RVA: 0xBAE6E0
float __fastcall hkaNURBS::Point::mag(hkaNURBS::Point *this)
{
  return fsqrt(COERCE_FLOAT(COERCE_UNSIGNED_INT64(hkaNURBS::Point::mag2(this))));
}

// File Line: 1882
// RVA: 0xBAE700
hkaNURBS::Point *__fastcall hkaNURBS::Point::abs(hkaNURBS::Point *this, hkaNURBS::Point *result)
{
  hkaNURBS::Point::Point(
    result,
    COERCE_FLOAT((unsigned int)(2 * LODWORD(this->point[0])) >> 1),
    COERCE_FLOAT((unsigned int)(2 * LODWORD(this->point[1])) >> 1),
    COERCE_FLOAT((unsigned int)(2 * LODWORD(this->point[2])) >> 1),
    COERCE_FLOAT((unsigned int)(2 * LODWORD(this->point[3])) >> 1));
  return result;
}

// File Line: 1887
// RVA: 0xBAE7A0
hkaNURBS::Point *__fastcall hkaNURBS::Point::floor(hkaNURBS::Point *this, hkaNURBS::Point *result)
{
  __m128i v3; // xmm12
  __m128i v4; // xmm11
  __m128 v5; // xmm5
  __m128i v6; // xmm8
  __m128 v7; // xmm10
  __m128 v8; // xmm4
  __m128 v9; // xmm6
  __m128 v10; // xmm13
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  float v14; // xmm3_4
  __m128 v15; // xmm0

  v3 = (__m128i)LODWORD(this->point[3]);
  v4 = (__m128i)LODWORD(this->point[2]);
  v5 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v3, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v6 = (__m128i)LODWORD(this->point[1]);
  v7 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v4, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v8 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v6, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v9 = _mm_sub_ps(
         _mm_add_ps(
           _mm_add_ps(_mm_sub_ps((__m128)LODWORD(this->point[0]), *(__m128 *)two23), *(__m128 *)two23),
           *(__m128 *)two23),
         *(__m128 *)two23);
  v10 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)LODWORD(this->point[0]), 1u), 1u));
  v11 = _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v3, v5)), v5);
  v12 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v3, 1u), 1u));
  v13 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v4, 1u), 1u));
  LODWORD(v14) = v13.m128_i32[0] & v4.m128i_i32[0] | _mm_andnot_ps(
                                                       v13,
                                                       _mm_add_ps(
                                                         _mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v4, v7)),
                                                         v7)).m128_u32[0];
  v15 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v6, 1u), 1u));
  hkaNURBS::Point::Point(
    result,
    COERCE_FLOAT(_mm_andnot_ps(
                   v10,
                   _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)LODWORD(this->point[0]), v9)), v9)).m128_u32[0] | v10.m128_i32[0] & LODWORD(this->point[0])),
    COERCE_FLOAT(v15.m128_i32[0] & v6.m128i_i32[0] | _mm_andnot_ps(
                                                       v15,
                                                       _mm_add_ps(
                                                         _mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v6, v8)),
                                                         v8)).m128_u32[0]),
    v14,
    COERCE_FLOAT(_mm_andnot_ps(v12, v11).m128_u32[0] | v12.m128_i32[0] & v3.m128i_i32[0]));
  return result;
}

// File Line: 1892
// RVA: 0xBAE990
hkaNURBS::Point *__fastcall hkaNURBS::Point::ceil(hkaNURBS::Point *this, hkaNURBS::Point *result)
{
  __m128i v3; // xmm12
  __m128i v4; // xmm11
  __m128 v5; // xmm6
  __m128i v6; // xmm10
  __m128 v7; // xmm9
  __m128 v8; // xmm4
  __m128 v9; // xmm7
  __m128 v10; // xmm13
  __m128 v11; // xmm1
  __m128 v12; // xmm6
  __m128 v13; // xmm0
  float v14; // xmm3_4
  __m128 v15; // xmm0

  v3 = (__m128i)LODWORD(this->point[3]);
  v4 = (__m128i)LODWORD(this->point[2]);
  v5 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v3, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v6 = (__m128i)LODWORD(this->point[1]);
  v7 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v4, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v8 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v6, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v9 = _mm_sub_ps(
         _mm_add_ps(
           _mm_add_ps(_mm_sub_ps((__m128)LODWORD(this->point[0]), *(__m128 *)two23), *(__m128 *)two23),
           *(__m128 *)two23),
         *(__m128 *)two23);
  v10 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)LODWORD(this->point[0]), 1u), 1u));
  v11 = _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v3, v5)), v5);
  v12 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v3, 1u), 1u));
  v13 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v4, 1u), 1u));
  v14 = COERCE_FLOAT(v13.m128_i32[0] & v4.m128i_i32[0] | _mm_andnot_ps(
                                                           v13,
                                                           _mm_add_ps(
                                                             _mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v4, v7)),
                                                             v7)).m128_u32[0])
      + 1.0;
  v15 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v6, 1u), 1u));
  hkaNURBS::Point::Point(
    result,
    COERCE_FLOAT(_mm_andnot_ps(
                   v10,
                   _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)LODWORD(this->point[0]), v9)), v9)).m128_u32[0] | v10.m128_i32[0] & LODWORD(this->point[0]))
  + 1.0,
    COERCE_FLOAT(v15.m128_i32[0] & v6.m128i_i32[0] | _mm_andnot_ps(
                                                       v15,
                                                       _mm_add_ps(
                                                         _mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v6, v8)),
                                                         v8)).m128_u32[0])
  + 1.0,
    v14,
    COERCE_FLOAT(_mm_andnot_ps(v12, v11).m128_u32[0] | v12.m128_i32[0] & v3.m128i_i32[0]) + 1.0);
  return result;
}

// File Line: 1897
// RVA: 0xBAEB90
hkaNURBS::Point *__fastcall hkaNURBS::Point::normalize(hkaNURBS::Point *this, hkaNURBS::Point *result)
{
  float v4; // xmm0_4

  v4 = hkaNURBS::Point::mag(this);
  hkaNURBS::Point::operator/(this, result, v4);
  return result;
}

// File Line: 1902
// RVA: 0xBAE6B0
float __fastcall hkaNURBS::Point::operator[](hkaNURBS::Point *this, int u)
{
  return this->point[u];
}

// File Line: 1909
// RVA: 0xBAE6C0
float *__fastcall hkaNURBS::Point::operator[](hkaNURBS::Point *this, int u)
{
  return (float *)this + u;
}

// File Line: 1916
// RVA: 0xBAEBD0
float __fastcall hkaNURBS::Point::Dist(hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  hkaNURBS::Point *v2; // rax
  hkaNURBS::Point result; // [rsp+20h] [rbp-18h] BYREF

  v2 = hkaNURBS::Point::operator-(P, &result, Q);
  return hkaNURBS::Point::mag(v2);
}

// File Line: 1921
// RVA: 0xBAEC00
float __fastcall hkaNURBS::Point::Dot(hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  float v4; // xmm0_4
  float v5; // xmm7_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm6_4

  v4 = hkaNURBS::Point::operator[](P, 1);
  v5 = v4 * hkaNURBS::Point::operator[](Q, 1);
  v6 = hkaNURBS::Point::operator[](P, 0);
  v7 = v5 + (float)(v6 * hkaNURBS::Point::operator[](Q, 0));
  v8 = hkaNURBS::Point::operator[](P, 2);
  v9 = v7 + (float)(v8 * hkaNURBS::Point::operator[](Q, 2));
  v10 = hkaNURBS::Point::operator[](P, 3);
  return v9 + (float)(v10 * hkaNURBS::Point::operator[](Q, 3));
}

// File Line: 1926
// RVA: 0xBAECC0
float __fastcall hkaNURBS::Point::Cos(hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  float v4; // xmm7_4
  float v5; // xmm6_4

  v4 = hkaNURBS::Point::Dot(P, Q);
  v5 = hkaNURBS::Point::mag(P);
  return v4 / (float)(v5 * hkaNURBS::Point::mag(Q));
}

// File Line: 1931
// RVA: 0xBAED20
hkaNURBS::Point *__fastcall hkaNURBS::Point::Max(hkaNURBS::Point *result, hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  float v6; // xmm6_4
  float v7; // xmm0_4
  hkaNURBS::Point *v8; // rcx
  float v9; // xmm6_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  hkaNURBS::Point *v12; // rcx
  float v13; // xmm6_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  hkaNURBS::Point *v16; // rcx
  float v17; // xmm6_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  hkaNURBS::Point *v20; // rcx
  float v21; // xmm6_4

  hkaNURBS::Point::Point(result, 0.0, 0.0, 0.0, 0.0);
  v6 = hkaNURBS::Point::operator[](P, 0);
  v7 = hkaNURBS::Point::operator[](Q, 0);
  v8 = P;
  if ( v6 <= v7 )
    v8 = Q;
  v9 = hkaNURBS::Point::operator[](v8, 0);
  *hkaNURBS::Point::operator[](result, 0) = v9;
  v10 = hkaNURBS::Point::operator[](P, 1);
  v11 = hkaNURBS::Point::operator[](Q, 1);
  v12 = P;
  if ( v10 <= v11 )
    v12 = Q;
  v13 = hkaNURBS::Point::operator[](v12, 1);
  *hkaNURBS::Point::operator[](result, 1) = v13;
  v14 = hkaNURBS::Point::operator[](P, 2);
  v15 = hkaNURBS::Point::operator[](Q, 2);
  v16 = P;
  if ( v14 <= v15 )
    v16 = Q;
  v17 = hkaNURBS::Point::operator[](v16, 2);
  *hkaNURBS::Point::operator[](result, 2) = v17;
  v18 = hkaNURBS::Point::operator[](P, 3);
  v19 = hkaNURBS::Point::operator[](Q, 3);
  v20 = P;
  if ( v18 <= v19 )
    v20 = Q;
  v21 = hkaNURBS::Point::operator[](v20, 3);
  *hkaNURBS::Point::operator[](result, 3) = v21;
  return result;
}

// File Line: 1943
// RVA: 0xBAEE80
hkaNURBS::Point *__fastcall hkaNURBS::Point::Min(hkaNURBS::Point *result, hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  float v6; // xmm6_4
  float v7; // xmm0_4
  hkaNURBS::Point *v8; // rcx
  float v9; // xmm6_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  hkaNURBS::Point *v12; // rcx
  float v13; // xmm6_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  hkaNURBS::Point *v16; // rcx
  float v17; // xmm6_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  hkaNURBS::Point *v20; // rcx
  float v21; // xmm6_4

  hkaNURBS::Point::Point(result, 0.0, 0.0, 0.0, 0.0);
  v6 = hkaNURBS::Point::operator[](P, 0);
  v7 = hkaNURBS::Point::operator[](Q, 0);
  v8 = P;
  if ( v6 >= v7 )
    v8 = Q;
  v9 = hkaNURBS::Point::operator[](v8, 0);
  *hkaNURBS::Point::operator[](result, 0) = v9;
  v10 = hkaNURBS::Point::operator[](P, 1);
  v11 = hkaNURBS::Point::operator[](Q, 1);
  v12 = P;
  if ( v10 >= v11 )
    v12 = Q;
  v13 = hkaNURBS::Point::operator[](v12, 1);
  *hkaNURBS::Point::operator[](result, 1) = v13;
  v14 = hkaNURBS::Point::operator[](P, 2);
  v15 = hkaNURBS::Point::operator[](Q, 2);
  v16 = P;
  if ( v14 >= v15 )
    v16 = Q;
  v17 = hkaNURBS::Point::operator[](v16, 2);
  *hkaNURBS::Point::operator[](result, 2) = v17;
  v18 = hkaNURBS::Point::operator[](P, 3);
  v19 = hkaNURBS::Point::operator[](Q, 3);
  v20 = P;
  if ( v18 >= v19 )
    v20 = Q;
  v21 = hkaNURBS::Point::operator[](v20, 3);
  *hkaNURBS::Point::operator[](result, 3) = v21;
  return result;
}

// File Line: 2083
// RVA: 0xBADFD0
// attributes: thunk
void __fastcall hkaCompression::approximateNURBSCurve(
        int numSamples,
        const float *sampleTimes,
        hkVector4f *sampleData,
        int degree,
        float tolerance,
        int *numKnotsOut,
        float *knotsOut,
        int *numPointsOut,
        hkVector4f *pointsOut)
{
  hkaNURBS::ApproximateCurve(
    numSamples,
    sampleTimes,
    sampleData,
    degree,
    tolerance,
    numKnotsOut,
    knotsOut,
    numPointsOut,
    pointsOut);
}

