// File Line: 38
// RVA: 0xBADFE0
void __usercall hkaNURBS::ApproximateCurve(int numSamples@<ecx>, const float *sampleTimes@<rdx>, hkVector4f *sampleData@<r8>, int degree@<r9d>, __int64 a5@<rbx>, float tolerance, int *numKnotsOut, float *knotsOut, int *numPointsOut, hkVector4f *pointsOut)
{
  hkVector4f *v10; // r15
  int v11; // eax
  int v12; // er12
  __int64 v13; // rdi
  hkaNURBS::Point *v14; // rbx
  int v15; // er14
  __int64 v16; // rsi
  int v17; // eax
  float *v18; // r13
  int v19; // esi
  signed __int64 v20; // r15
  float *v21; // r12
  __int64 v22; // rsi
  float *v23; // rax
  int v24; // ecx
  int v25; // ecx
  int *v26; // rdx
  int *v27; // rdi
  int v28; // eax
  int v29; // er12
  hkaNURBS::Point *v30; // rdi
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
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> v42; // [rsp+40h] [rbp-51h]
  hkArray<float,hkContainerHeapAllocator> v43; // [rsp+50h] [rbp-41h]
  hkArray<float,hkContainerHeapAllocator> ub; // [rsp+60h] [rbp-31h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> Q; // [rsp+70h] [rbp-21h]
  int vars0; // [rsp+D0h] [rbp+3Fh]
  char *retaddr; // [rsp+D8h] [rbp+47h]
  const float *n; // [rsp+E8h] [rbp+57h]
  __int64 E; // [rsp+F0h] [rbp+5Fh]
  int *v50; // [rsp+F8h] [rbp+67h]

  LODWORD(v50) = degree;
  n = sampleTimes;
  E = a5;
  v10 = sampleData;
  v11 = numSamples;
  v12 = degree;
  v13 = (unsigned int)numSamples;
  if ( numSamples )
  {
    vars0 = 16 * numSamples;
    v14 = (hkaNURBS::Point *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                               (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                               &vars0);
    v11 = vars0 / 16;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = 2147483648;
  P = (hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *)v14;
  if ( v11 )
    v15 = v11;
  Q.m_data = v14;
  Q.m_size = v13;
  Q.m_capacityAndFlags = v15;
  if ( (signed int)v13 > 0 )
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
    v18 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &vars0);
    v17 = vars0 / 4;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = 2147483648;
  ub.m_data = v18;
  if ( v17 )
    v19 = v17;
  ub.m_size = v13;
  vars0 = v19;
  ub.m_capacityAndFlags = v19;
  if ( (signed int)v13 > 0 )
  {
    v20 = (signed __int64)&v10->m_quad.m128_i64[1];
    v21 = v18;
    v22 = v13;
    do
    {
      *v21 = *(float *)((char *)v21 + retaddr - (char *)v18);
      *hkaNURBS::Point::operator[](v14, 0) = *(float *)(v20 - 8);
      *hkaNURBS::Point::operator[](v14, 1) = *(float *)(v20 - 4);
      *hkaNURBS::Point::operator[](v14, 2) = *(float *)v20;
      v23 = hkaNURBS::Point::operator[](v14, 3);
      v24 = *(_DWORD *)(v20 + 4);
      ++v14;
      ++v21;
      v20 += 16i64;
      *(_DWORD *)v23 = v24;
      --v22;
    }
    while ( v22 );
    v19 = vars0;
    v12 = (signed int)n;
  }
  v42.m_data = 0i64;
  v42.m_size = 0;
  v42.m_capacityAndFlags = 2147483648;
  v43.m_data = 0i64;
  v43.m_size = 0;
  v43.m_capacityAndFlags = 2147483648;
  hkaNURBS::GlobalCurveApproxErrBnd(v13 - 1, &Q, &ub, v12, *(float *)&E, (int *)&n, &v43, &v42);
  v25 = (signed int)n;
  v26 = numKnotsOut;
  v27 = v50;
  *numKnotsOut = (_DWORD)n + 1;
  v28 = v12 + v25 + 2;
  v29 = 0;
  *v27 = v28;
  if ( *v26 > 0 )
  {
    v30 = v42.m_data;
    v31 = v26;
    v32 = knotsOut + 2;
    do
    {
      v33 = &v30[v29];
      *(v32 - 2) = *hkaNURBS::Point::operator[](&v30[v29], 0);
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
    v36 = *(_QWORD *)&tolerance;
    v37 = (char *)v43.m_data - *(_QWORD *)&tolerance;
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v34,
      4 * v43.m_capacityAndFlags);
  v43.m_data = 0i64;
  v43.m_capacityAndFlags = 2147483648;
  v42.m_size = 0;
  if ( v42.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaNURBS::Point *, _QWORD, float *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v42.m_data,
      (unsigned int)(16 * v42.m_capacityAndFlags),
      v34);
  v42.m_data = 0i64;
  v42.m_capacityAndFlags = 2147483648;
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
__int64 __fastcall hkaNURBS::FindSpan(int n, int p, float u, hkArray<float,hkContainerHeapAllocator> *U)
{
  float *v4; // r10
  int v5; // er8
  __int64 result; // rax
  int v7; // er9
  int v8; // eax
  float v9; // xmm0_4

  v4 = U->m_data;
  v5 = p;
  if ( u != U->m_data[n + 1] )
  {
    v7 = n + 1;
    v8 = n + 1 + p;
    while ( 1 )
    {
      result = v8 / 2;
      v9 = v4[(signed int)result];
      if ( u < v9 )
        goto LABEL_12;
      if ( u < v4[(signed int)result + 1] )
        return result;
      if ( u >= v9 )
      {
        v5 = result;
        v8 = v7 + result;
      }
      else
      {
LABEL_12:
        v7 = result;
        v8 = result + v5;
      }
    }
  }
  return (unsigned int)n;
}

// File Line: 121
// RVA: 0xBB0C10
void __fastcall hkaNURBS::BasisFuns(int i, float u, int p, hkArray<float,hkContainerHeapAllocator> *U, float *N)
{
  signed int v5; // er10
  int v6; // er12
  float v7; // xmm6_4
  signed __int64 v8; // r11
  float *v9; // r14
  char *v10; // r13
  float *v11; // rdx
  signed int v12; // er8
  signed __int64 v13; // rdi
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
  int v49; // [rsp+0h] [rbp-58h]
  char v50; // [rsp+4h] [rbp-54h]
  char v51[8]; // [rsp+8h] [rbp-50h]
  char v52[16]; // [rsp+10h] [rbp-48h]

  v5 = 1;
  v6 = p;
  v7 = u;
  *N = 1.0;
  v8 = 1i64;
  if ( p >= 1 )
  {
    v9 = &U->m_data[i];
    v10 = (char *)U->m_data + 4i64 * i + 8 - (_QWORD)v52;
    do
    {
      v11 = (float *)&v51[4 * v8];
      v12 = 0;
      v13 = 0i64;
      v14 = 0.0;
      v15 = *(float *)&v10[(_QWORD)v11];
      v11[2] = v7 - *v9;
      *((float *)&v49 + v8) = v15 - v7;
      if ( v5 >= 4 )
      {
        v16 = &v50 - (char *)N;
        v17 = (char *)&v49 - (char *)N;
        v18 = v51 - (char *)N;
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
        v43 = (float *)&v52[4 * (v8 - v13)];
        v44 = (unsigned int)(v5 - v12);
        do
        {
          v45 = *(float *)((char *)v42 + &v50 - (char *)N);
          v46 = *v43;
          v47 = *v42;
          ++v42;
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
    while ( v5 <= v6 );
  }
}

// File Line: 152
// RVA: 0xBB1260
void __fastcall hkaNURBS::DersBasisFuns(int i, float u, int p, int n, hkArray<float,hkContainerHeapAllocator> *U, float (*ders)[4])
{
  signed __int64 v6; // rdi
  float v7; // xmm5_4
  signed __int64 v8; // rbx
  signed int v9; // er10
  float *v10; // r12
  float *v11; // r13
  signed __int64 v12; // r11
  char *v13; // rdi
  signed __int64 v14; // rax
  float *v15; // r8
  int v16; // er14
  signed __int64 v17; // rsi
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
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  float v40; // xmm4_4
  float v41; // xmm1_4
  float *v42; // rdx
  float *v43; // rcx
  float *v44; // r8
  __int64 v45; // r9
  float v46; // xmm3_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  signed __int64 v49; // r10
  __int64 v50; // r12
  signed __int64 v51; // r8
  __int64 v52; // r15
  __int64 v53; // rcx
  unsigned __int64 v54; // r9
  int *v55; // rdx
  int v56; // eax
  int *v57; // rcx
  int v58; // eax
  __int64 v59; // r11
  signed __int64 v60; // r8
  int v61; // ecx
  int v62; // eax
  signed int v63; // edx
  signed __int64 v64; // r9
  __int64 v65; // rsi
  signed __int64 v66; // r13
  signed int v67; // er14
  signed __int64 v68; // r12
  signed __int64 v69; // rbx
  int v70; // edx
  __int64 v71; // r10
  __int64 v72; // r11
  float v73; // xmm2_4
  float v74; // xmm2_4
  signed __int64 v75; // r10
  int v76; // eax
  bool v77; // zf
  bool v78; // sf
  unsigned __int8 v79; // of
  int v80; // eax
  signed __int64 v81; // r9
  signed __int64 v82; // rdx
  int *v83; // r8
  int *v84; // r11
  signed __int64 v85; // rcx
  char *v86; // r14
  signed __int64 v87; // rax
  char *v88; // r13
  signed __int64 v89; // rax
  char *v90; // r15
  char *v91; // rdi
  char *v92; // r12
  char *v93; // rdx
  char *v94; // rcx
  char *v95; // rsi
  unsigned __int64 v96; // rax
  float v97; // xmm0_4
  float v98; // xmm0_4
  float v99; // xmm2_4
  float v100; // xmm1_4
  float v101; // xmm2_4
  float v102; // xmm0_4
  float v103; // xmm0_4
  float v104; // xmm1_4
  float *v105; // rcx
  float *v106; // rdx
  signed __int64 v107; // r9
  float v108; // xmm0_4
  float v109; // xmm0_4
  float v110; // xmm0_4
  float *v111; // r10
  signed int v112; // eax
  __int64 v113; // r9
  __int64 v114; // rcx
  signed int v115; // er11
  signed __int64 v116; // rbx
  unsigned int v117; // er14
  int v118; // edi
  signed __int64 v119; // r9
  __int64 v120; // rsi
  __int64 v121; // rdx
  int v122; // er8
  int v123; // er10
  __m128 v124; // xmm1
  int v125; // eax
  signed __int64 v126; // rcx
  unsigned __int64 v127; // rax
  float v128; // xmm2_4
  float v129; // xmm1_4
  float v130; // xmm1_4
  signed __int64 v131; // rcx
  signed __int64 v132; // rax
  int v133; // [rsp+0h] [rbp-C8h]
  int v134; // [rsp+4h] [rbp-C4h]
  int v135; // [rsp+8h] [rbp-C0h]
  signed int v136; // [rsp+Ch] [rbp-BCh]
  signed int v137; // [rsp+10h] [rbp-B8h]
  signed int v138; // [rsp+14h] [rbp-B4h]
  signed __int64 v139; // [rsp+18h] [rbp-B0h]
  signed __int64 v140; // [rsp+18h] [rbp-B0h]
  signed __int64 v141; // [rsp+20h] [rbp-A8h]
  signed __int64 v142; // [rsp+28h] [rbp-A0h]
  __int64 v143; // [rsp+30h] [rbp-98h]
  int v144; // [rsp+38h] [rbp-90h]
  char v145[4]; // [rsp+3Ch] [rbp-8Ch]
  char v146[4]; // [rsp+40h] [rbp-88h]
  char v147[4]; // [rsp+44h] [rbp-84h]
  __int64 v148; // [rsp+48h] [rbp-80h]
  __int64 v149; // [rsp+50h] [rbp-78h]
  __int64 v150; // [rsp+58h] [rbp-70h]
  __int64 v151; // [rsp+60h] [rbp-68h]
  __int64 v152; // [rsp+68h] [rbp-60h]
  __int64 v153; // [rsp+70h] [rbp-58h]
  float *v154; // [rsp+78h] [rbp-50h]
  int v155; // [rsp+88h] [rbp-40h]
  char v156; // [rsp+8Ch] [rbp-3Ch]
  char *v157; // [rsp+B8h] [rbp-10h]
  __int64 v158; // [rsp+C0h] [rbp-8h]
  char *v159; // [rsp+C8h] [rbp+0h]
  int *v160; // [rsp+D0h] [rbp+8h]
  __int64 v161; // [rsp+D8h] [rbp+10h]
  __int64 v162; // [rsp+E0h] [rbp+18h]
  char *v163; // [rsp+E8h] [rbp+20h]
  char *v164; // [rsp+F0h] [rbp+28h]
  int v165; // [rsp+148h] [rbp+80h]
  int v166; // [rsp+150h] [rbp+88h]
  _QWORD *v167; // [rsp+158h] [rbp+90h]
  __int64 vars0; // [rsp+160h] [rbp+98h]

  v6 = 1i64;
  v7 = u;
  v8 = 1i64;
  LODWORD(v154) = 1065353216;
  v9 = 1;
  if ( p >= 1 )
  {
    v10 = (float *)&v156;
    v11 = (float *)(*v167 + 4i64 * i);
    v12 = -52i64;
    v13 = &v156;
    v14 = *v167 + 4i64 * i + 8 - (_QWORD)&v151;
    v139 = *v167 + 4i64 * i + 8 - (_QWORD)&v151;
    do
    {
      v15 = (float *)((char *)&v150 + 4 * v8);
      v16 = 0;
      v17 = 0i64;
      v18 = 0.0;
      v19 = *(float *)((char *)v15 + v14);
      v15[2] = v7 - *v11;
      *((float *)&v149 + v8) = v19 - v7;
      if ( v9 >= 4 )
      {
        v20 = v13;
        v21 = (float *)((char *)&v154 + 4 * v8);
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
          v30 = v15[5];
          *(v21 - 16) = v28;
          v31 = *(float *)&v20[v12 - 16];
          v32 = v30 + v31;
          *((float *)v20 - 4) = v32;
          v33 = *(v21 - 13) / v32;
          v34 = (float)(v31 * v33) + v27;
          v35 = v15[4];
          v36 = v15[4] + *(float *)&v20[v12 - 12];
          *(v21 - 12) = v34;
          *((float *)v20 - 3) = v36;
          v37 = v35 * (float)(*(v21 - 9) / v36);
          v38 = *(float *)&v20[v12 - 8];
          v39 = (float)((float)(*(v21 - 9) / v36) * *(float *)&v20[v12 - 12]) + (float)(v29 * v33);
          v40 = v15[3];
          *(v21 - 8) = v39;
          *((float *)v20 - 2) = v40 + v38;
          v41 = *(v21 - 5) / (float)(v40 + v38);
          v18 = v40 * v41;
          *(v21 - 4) = (float)(v38 * v41) + v37;
          --v23;
        }
        while ( v23 );
      }
      if ( v16 < v9 )
      {
        v42 = (float *)((char *)&v154 + 4 * (v8 + 4 * v17));
        v43 = (float *)((char *)&v149 + 4 * v17 + 4);
        v44 = (float *)((char *)&v151 + 4 * (v8 - v17));
        v45 = (unsigned int)(v9 - v16);
        do
        {
          v46 = *v44;
          v47 = *v43;
          v42 += 4;
          --v44;
          ++v43;
          *(float *)((char *)v43 + v13 - (char *)&v150 - 4) = v46 + v47;
          v48 = *(v42 - 5) / (float)(v46 + v47);
          *(v42 - 4) = (float)(v47 * v48) + v18;
          v18 = v46 * v48;
          --v45;
        }
        while ( v45 );
      }
      v14 = v139;
      ++v9;
      *v10 = v18;
      ++v8;
      --v11;
      v13 += 16;
      v12 -= 16i64;
      v10 += 5;
    }
    while ( v9 <= v165 );
    v6 = 1i64;
  }
  v49 = v165;
  v50 = vars0;
  v51 = 0i64;
  v52 = v165;
  v161 = v165;
  if ( v165 >= 0 )
  {
    if ( v165 + 1i64 >= 4 )
    {
      v53 = vars0 + 8;
      v54 = (unsigned __int64)(v165 + 1i64) >> 2;
      v55 = &v155 + v165;
      v51 = 4 * v54;
      do
      {
        v56 = *(v55 - 4);
        v53 += 16i64;
        v55 += 16;
        *(_DWORD *)(v53 - 24) = v56;
        *(_DWORD *)(v53 - 20) = *(v55 - 16);
        *(_DWORD *)(v53 - 16) = *(v55 - 12);
        *(_DWORD *)(v53 - 12) = *(v55 - 8);
        --v54;
      }
      while ( v54 );
    }
    if ( v51 <= v49 )
    {
      v57 = (int *)((char *)&v154 + 4 * (v49 + 4 * v51));
      do
      {
        v58 = *v57;
        ++v51;
        v57 += 4;
        *(_DWORD *)(v50 + 4 * v51 - 4) = v58;
      }
      while ( v51 <= v49 );
    }
    if ( (signed int)v49 >= 0 )
    {
      v59 = 0i64;
      v158 = v50 + 16 + 4 * v49;
      v60 = -v49;
      v61 = -(signed int)v49;
      v62 = v49;
      v143 = 0i64;
      v142 = -v49;
      v133 = -(signed int)v49;
      v162 = -v49;
      v63 = v166;
      v134 = v49;
      v64 = 1i64;
      v140 = 1i64;
      do
      {
        v65 = 0i64;
        v138 = 0;
        v137 = 1;
        v66 = 1i64;
        v151 = 1i64;
        v144 = 1065353216;
        v153 = 0i64;
        v67 = 1;
        v136 = 1;
        v148 = 1i64;
        if ( v63 >= 1 )
        {
          v68 = 4 * v52 - 4;
          v69 = v52 - 1;
          v70 = v49 - 1;
          v135 = v49 - 1;
          v71 = v59 + 4 * v162;
          v150 = 4 * v52 - 4;
          v152 = v64;
          v149 = v59 + 4 * v162;
          v154 = (float *)(v71 + v158);
          v141 = 16 * v52 - 16;
          do
          {
            v72 = v60 + v52;
            v73 = 0.0;
            v151 = v60 + v52;
            if ( v60 + v52 >= v6 )
            {
              v61 = v133;
              v74 = *((float *)&v144 + 4 * v65) / *((float *)&v155 + v60 + v68 + v69);
              *((float *)&v144 + 4 * v66) = v74;
              v73 = v74 * *((float *)&v154 + v71 + v68 + v69);
            }
            v75 = v64;
            if ( v70 + v61 >= -1 )
              v75 = 1i64;
            v76 = v61 + v165 - 1;
            v79 = __OFSUB__(v76, v70);
            v77 = v76 == v70;
            v78 = v76 - v70 < 0;
            v80 = v67 - 1;
            if ( !((unsigned __int8)(v78 ^ v79) | v77) )
              v80 = v134;
            v81 = v80;
            if ( v75 <= v80 )
            {
              if ( v80 - v75 + 1 >= 4 )
              {
                v82 = v69 + v60;
                v83 = &v155 + v75 + v68 + v69 + v60;
                v84 = &v155 + v69 + 4 * (v82 + v75);
                v85 = 4 * (4 * (v65 - v69) - v82) - (_QWORD)&v155;
                v86 = (char *)&v144 + v85;
                v87 = 4 * (v66 - v69);
                v159 = &v147[v85];
                v88 = &v147[v85];
                v89 = 4 * (v87 - v82) - (_QWORD)&v155;
                v160 = (int *)((char *)&v144 + v89);
                v164 = &v146[v89];
                v90 = (char *)&v144 + v89;
                v91 = &v146[v89];
                v157 = &v145[v89];
                v92 = &v145[v89];
                v93 = &v145[v85];
                v94 = &v146[v85];
                v163 = &v147[v89];
                v95 = &v147[v89];
                v96 = ((unsigned __int64)(v81 - v75 - 3) >> 2) + 1;
                v75 += 4 * v96;
                do
                {
                  v97 = *(float *)((char *)v83 + (_QWORD)v86);
                  v84 += 16;
                  v83 += 4;
                  v98 = (float)(v97 - *(float *)((char *)v83 + (_QWORD)v86 - 20)) / *((float *)v83 - 4);
                  *(float *)((char *)v83 + (_QWORD)v90 - 16) = v98;
                  v99 = v73 + (float)(v98 * *((float *)v84 - 20));
                  v100 = (float)(*(float *)((char *)v83 + (_QWORD)v93 - 16) - *(float *)((char *)v83 + (_QWORD)v86 - 16))
                       / *((float *)v83 - 3);
                  *(float *)((char *)v83 + (_QWORD)v92 - 16) = v100;
                  v101 = v99 + (float)(v100 * *((float *)v84 - 16));
                  v102 = (float)(*(float *)((char *)v83 + (_QWORD)v94 - 16) - *(float *)((char *)v83 + (_QWORD)v93 - 16))
                       / *((float *)v83 - 2);
                  *(float *)((char *)v83 + (_QWORD)v91 - 16) = v102;
                  v103 = v102 * *((float *)v84 - 12);
                  v104 = (float)(*(float *)((char *)v83 + (_QWORD)v88 - 16) - *(float *)((char *)v83 + (_QWORD)v94 - 16))
                       / *((float *)v83 - 1);
                  *(float *)((char *)v83 + (_QWORD)v95 - 16) = v104;
                  v73 = (float)(v101 + v103) + (float)(v104 * *((float *)v84 - 8));
                  --v96;
                }
                while ( v96 );
                v6 = v148;
                v65 = v153;
                v52 = v161;
                v66 = v151;
                v72 = v151;
                v68 = v150;
                v67 = v136;
              }
              if ( v75 <= v81 )
              {
                v105 = (float *)(&v144 + v75 + 4 * v65);
                v106 = (float *)((char *)&v154 + 4 * (v69 + 4 * (v75 + v72 - v6)));
                v107 = v81 - v75 + 1;
                do
                {
                  v108 = *v105;
                  v106 += 4;
                  ++v105;
                  v109 = (float)(v108 - *(v105 - 2))
                       / *(float *)((char *)v105 + (_QWORD)&v155 + 4 * (v72 + 4 * (v69 - v65) - v6) - (_QWORD)&v144 - 4);
                  v105[4 * (v66 - v65) - 1] = v109;
                  v73 = v73 + (float)(v109 * *(v106 - 4));
                  --v107;
                }
                while ( v107 );
              }
            }
            v79 = __OFSUB__(v72, v69);
            v77 = v72 == v69;
            v78 = v72 - v69 < 0;
            v59 = v143;
            if ( (unsigned __int8)(v78 ^ v79) | v77 )
            {
              v110 = (float)(-1.0 / *(float *)((char *)&v155 + v143 + v141)) * *((float *)&v143 + v6 + 4 * v65 + 1);
              *((float *)&v144 + v6 + 4 * v66) = v110;
              v73 = v73 + (float)(v110 * *((float *)&v154 + v69 + v59));
            }
            v111 = v154;
            v112 = v138;
            v113 = v152;
            v141 -= 16i64;
            v60 = v142;
            *v154 = v73;
            v114 = v65;
            v138 = v137;
            ++v67;
            ++v6;
            v64 = v113 + 1;
            v68 -= 4i64;
            v70 = v135 - 1;
            v65 = v66;
            v153 = v66;
            --v69;
            v151 = v114;
            v154 = v111 + 4;
            v71 = v149;
            v66 = v114;
            v61 = v133;
            --v135;
            v137 = v112;
            v136 = v67;
            v148 = v6;
            v152 = v64;
            v150 = v68;
          }
          while ( v67 <= v166 );
          v62 = v134;
          LODWORD(v49) = v165;
          v63 = v166;
          v64 = v140;
        }
        ++v60;
        ++v61;
        v134 = v62 - 1;
        --v64;
        v59 += 4i64;
        --v62;
        v133 = v61;
        v140 = v64;
        v142 = v60;
        v143 = v59;
        v6 = 1i64;
      }
      while ( v60 + v52 <= v52 );
      v50 = vars0;
    }
  }
  v115 = v49;
  if ( v166 >= 1 )
  {
    v116 = 4i64;
    v117 = v49 + 1;
    v118 = v49 - 1;
    v119 = 4i64;
    v120 = (unsigned int)v166;
    do
    {
      v121 = 0i64;
      if ( (signed int)v49 >= 0 && v117 >= 8 )
      {
        v122 = 0;
        v123 = v49 - (signed int)v117 % 8;
        v124 = _mm_cvtepi32_ps(_mm_shuffle_epi32(_mm_cvtsi32_si128(v115), 0));
        do
        {
          v121 += 8i64;
          *(__m128 *)(v50 + 4 * (v119 + v122)) = _mm_mul_ps(*(__m128 *)(v50 + 4 * (v119 + v122)), v124);
          v125 = v122 + 4;
          v122 += 8;
          *(__m128 *)(v50 + 4 * (v119 + v125)) = _mm_mul_ps(*(__m128 *)(v50 + 4 * (v119 + v125)), v124);
        }
        while ( v122 <= v123 );
        LODWORD(v49) = v165;
      }
      if ( v121 <= v52 )
      {
        if ( v52 - v121 + 1 >= 4 )
        {
          v126 = v50 + 4 * (v121 + v116);
          v127 = ((unsigned __int64)(v52 - v121 - 3) >> 2) + 1;
          v128 = (float)v115;
          v121 += 4 * v127;
          do
          {
            v126 += 16i64;
            v129 = v128 * *(float *)(v126 - 12);
            *(float *)(v126 - 16) = v128 * *(float *)(v126 - 16);
            *(float *)(v126 - 12) = v129;
            v130 = v128 * *(float *)(v126 - 4);
            *(float *)(v126 - 8) = v128 * *(float *)(v126 - 8);
            *(float *)(v126 - 4) = v130;
            --v127;
          }
          while ( v127 );
        }
        if ( v121 <= v52 )
        {
          v131 = v50 + 4 * (v121 + v116);
          v132 = v52 - v121 + 1;
          do
          {
            v131 += 4i64;
            *(float *)(v131 - 4) = (float)v115 * *(float *)(v131 - 4);
            --v132;
          }
          while ( v132 );
        }
      }
      v115 *= v118;
      v119 += 4i64;
      v116 += 4i64;
      --v118;
      --v120;
    }
    while ( v120 );
  }
}8);
            *(float *)(v126 - 4) = v130;
      

// File Line: 233
// RVA: 0xBB0E60
float __fastcall hkaNURBS::OneBasisFun(int p, int m, hkArray<float,hkContainerHeapAllocator> *U, int i, float u)
{
  signed __int64 v5; // rdi
  __int64 v7; // rbx
  float *v8; // r12
  unsigned __int64 v9; // r9
  float v10; // xmm7_4
  signed __int64 v11; // r11
  signed __int64 v12; // rcx
  float *v13; // rdx
  signed __int64 v14; // r14
  signed __int64 v15; // r10
  char *v16; // r8
  signed __int64 v17; // r15
  signed __int64 v18; // r13
  float v19; // xmm1_4
  int v20; // esi
  signed __int64 v21; // rbp
  float *v22; // rdx
  float *v23; // r9
  signed __int64 v24; // rcx
  char *v25; // r11
  char *v26; // rbx
  unsigned int v27; // eax
  __int64 v28; // rcx
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm3_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm4_4
  float v39; // xmm4_4
  float v40; // xmm3_4
  float v41; // xmm5_4
  float v42; // xmm3_4
  float v43; // xmm4_4
  float v44; // xmm4_4
  float v45; // xmm5_4
  float v46; // xmm1_4
  float v47; // xmm4_4
  float *v48; // rdx
  __int64 v49; // r9
  float *v50; // rcx
  float v51; // xmm4_4
  float v52; // xmm5_4
  float v53; // xmm3_4
  float v54; // xmm4_4
  char *v55; // [rsp+0h] [rbp-78h]
  float *v56; // [rsp+8h] [rbp-70h]
  signed __int64 v57; // [rsp+10h] [rbp-68h]
  __int64 v58; // [rsp+18h] [rbp-60h]
  float v59; // [rsp+20h] [rbp-58h]
  char v60[12]; // [rsp+24h] [rbp-54h]

  v5 = p;
  if ( !i && u == *U->m_data || i == m - p - 1 && u == U->m_data[m] )
    return *(float *)&FLOAT_1_0;
  v7 = i;
  v8 = U->m_data;
  v9 = 4i64 * i;
  v58 = v7;
  v56 = U->m_data;
  v10 = U->m_data[v9 / 4];
  if ( u < v10 )
    return 0.0;
  v11 = p;
  v57 = p;
  if ( u >= v8[p + 1 + v7] )
    return 0.0;
  v12 = 0i64;
  if ( (signed int)v5 >= 0 )
  {
    v13 = &v8[v9 / 4 + 1];
    do
    {
      if ( u < *(float *)((char *)&v59 + (_QWORD)&v8[v12] + v9 - (_QWORD)&v59) || u >= *v13 )
        *(&v59 + v12) = 0.0;
      else
        *(&v59 + v12) = 1.0;
      ++v12;
      ++v13;
    }
    while ( v12 <= v5 );
  }
  v14 = 1i64;
  if ( v5 >= 1 )
  {
    v15 = 0x3FFFFFFFFFFFFFFFi64;
    v16 = (char *)(&v60[-v9] - (char *)v8);
    v17 = 1i64;
    v18 = (signed __int64)&v8[v7 + 2];
    v55 = (char *)v8 + v9 - (_QWORD)v60;
    do
    {
      if ( v59 == 0.0 )
        v19 = 0.0;
      else
        v19 = (float)((float)(u - v10) * v59) / (float)(*(float *)(v18 - 4) - v10);
      v20 = 0;
      v21 = 0i64;
      if ( (signed int)v5 >= 4 )
      {
        v22 = (float *)(v18 + 4);
        v23 = (float *)v18;
        v24 = -4 * (v14 + v7 + 2);
        v25 = &v60[v24 - (_QWORD)v8];
        v26 = (char *)&v59 + v24 - (_QWORD)v8;
        v27 = ((unsigned int)(v5 - 4) >> 2) + 1;
        v28 = v27;
        v20 = 4 * v27;
        v21 = 4i64 * v27;
        do
        {
          v29 = *(float *)&v25[(_QWORD)v22];
          v30 = v23[v15];
          v31 = *v23;
          if ( v29 == 0.0 )
          {
            *(float *)&v26[(_QWORD)v22] = v19;
            v32 = 0.0;
          }
          else
          {
            v33 = v29 / (float)(v31 - v30);
            *(float *)&v26[(_QWORD)v22] = (float)((float)(v31 - u) * v33) + v19;
            v32 = (float)(u - v30) * v33;
          }
          v34 = *(float *)&v16[(_QWORD)v22 - 8];
          v35 = v22[v15];
          v36 = *v22;
          if ( v34 == 0.0 )
          {
            *(float *)&v25[(_QWORD)v22] = v32;
            v37 = 0.0;
          }
          else
          {
            v38 = v34 / (float)(v36 - v35);
            *(float *)&v25[(_QWORD)v22] = (float)((float)(v36 - u) * v38) + v32;
            v37 = (float)(u - v35) * v38;
          }
          v39 = *(float *)&v16[(_QWORD)v22 - 4];
          v40 = v22[1];
          v41 = *(float *)&v55[(_QWORD)v22 + (unsigned __int64)v16];
          if ( v39 == 0.0 )
          {
            *(float *)&v16[(_QWORD)v22 - 8] = v37;
            v42 = 0.0;
          }
          else
          {
            v43 = v39 / (float)(v40 - v41);
            *(float *)&v16[(_QWORD)v22 - 8] = (float)((float)(v40 - u) * v43) + v37;
            v42 = (float)(u - v41) * v43;
          }
          v44 = *(float *)&v16[(_QWORD)v22];
          v45 = v22[v17];
          v46 = v22[2];
          if ( v44 == 0.0 )
          {
            *(float *)&v16[(_QWORD)v22 - 4] = v42;
            v19 = 0.0;
          }
          else
          {
            v47 = v44 / (float)(v46 - v45);
            *(float *)&v16[(_QWORD)v22 - 4] = (float)((float)(v46 - u) * v47) + v42;
            v19 = (float)(u - v45) * v47;
          }
          v23 += 4;
          v22 += 4;
          --v28;
        }
        while ( v28 );
        v8 = v56;
        v11 = v57;
        v7 = v58;
      }
      if ( v20 < (signed int)v5 )
      {
        v48 = &v59 + v21;
        v49 = (unsigned int)(v5 - v20);
        v50 = &v8[v14 + v7 + v21 + 1];
        do
        {
          v51 = v48[1];
          v52 = v50[v15];
          v53 = *v50;
          if ( v51 == 0.0 )
          {
            *v48 = v19;
            v19 = 0.0;
          }
          else
          {
            v54 = v51 / (float)(v53 - v52);
            *v48 = (float)((float)(v53 - u) * v54) + v19;
            v19 = (float)(u - v52) * v54;
          }
          ++v50;
          ++v48;
          --v49;
        }
        while ( v49 );
      }
      ++v14;
      LODWORD(v5) = v5 - 1;
      v16 -= 4;
      v18 += 4i64;
      --v17;
      --v15;
    }
    while ( v14 <= v11 );
  }
  return v59;
}

// File Line: 290
// RVA: 0xBB43A0
void __fastcall hkaNURBS::CurveDerivs(int n, int p, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, float u, int d, hkaNURBS::Point *CK)
{
  int v7; // er10
  int v8; // esi
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v9; // r13
  hkArray<float,hkContainerHeapAllocator> *v10; // rbp
  int v11; // edi
  int v12; // er14
  hkaNURBS::Point *v13; // rbx
  __int64 v14; // rdi
  hkaNURBS::Point *v15; // rax
  __int64 v16; // rbx
  int v17; // er15
  float *v18; // rbp
  signed __int64 v19; // r12
  hkaNURBS::Point *v20; // r14
  hkaNURBS::Point *v21; // rax
  int v22; // ebx
  float *v23; // rdi
  signed __int64 v24; // rsi
  hkaNURBS::Point *v25; // rax
  hkaNURBS::Point v26; // [rsp+30h] [rbp-A8h]
  hkaNURBS::Point v27; // [rsp+40h] [rbp-98h]
  hkaNURBS::Point result; // [rsp+50h] [rbp-88h]
  float ders[4]; // [rsp+60h] [rbp-78h]
  int v30; // [rsp+E8h] [rbp+10h]
  int da; // [rsp+108h] [rbp+30h]

  v30 = p;
  v7 = p + 1;
  v8 = p;
  v9 = P;
  if ( d < p )
    v8 = d;
  v10 = U;
  v11 = p;
  v12 = n;
  if ( v7 <= d )
  {
    v13 = &CK[v7];
    v14 = (unsigned int)(d - p);
    do
    {
      hkaNURBS::Point::Point(&v26, 0.0, 0.0, 0.0, 0.0);
      hkaNURBS::Point::operator=(v13, v15);
      ++v13;
      --v14;
    }
    while ( v14 );
    v11 = v30;
  }
  da = hkaNURBS::FindSpan(v12, v11, u, v10);
  hkaNURBS::DersBasisFuns(da, u, v11, v8, v10, (float (*)[4])ders);
  v16 = v11;
  v17 = 0;
  *(_QWORD *)v26.point = v11;
  if ( v8 >= 0 )
  {
    v18 = ders;
    v19 = v8 + 1i64;
    do
    {
      v20 = &CK[v17];
      hkaNURBS::Point::Point(&v27, 0.0, 0.0, 0.0, 0.0);
      hkaNURBS::Point::operator=(v20, v21);
      if ( v16 >= 0 )
      {
        v22 = da - v11;
        v23 = v18;
        v24 = *(_QWORD *)v26.point + 1i64;
        do
        {
          v25 = operator*(&result, *v23, &v9->m_data[v22]);
          hkaNURBS::Point::operator+=(v20, v25);
          ++v22;
          ++v23;
          --v24;
        }
        while ( v24 );
        v11 = v30;
        v16 = *(_QWORD *)v26.point;
      }
      ++v17;
      v18 += 4;
      --v19;
    }
    while ( v19 );
  }
}

// File Line: 323
// RVA: 0xBAF910
hkaNURBS::Point *__fastcall hkaNURBS::CurvePoint(hkaNURBS::Point *result, int n, int p, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, float u)
{
  signed __int64 v6; // rdi
  hkaNURBS::Point *v7; // rsi
  hkArray<float,hkContainerHeapAllocator> *v8; // rbx
  int v9; // er15
  int v10; // er15
  signed __int64 v11; // rbx
  signed __int64 v12; // r14
  int v13; // edi
  hkaNURBS::Point *v14; // rax
  float d[4]; // [rsp+30h] [rbp-38h]
  hkaNURBS::Point resulta; // [rsp+40h] [rbp-28h]

  v6 = p;
  v7 = result;
  v8 = U;
  v9 = hkaNURBS::FindSpan(n, p, u, U);
  hkaNURBS::BasisFuns(v9, u, v6, v8, d);
  v10 = v9 - v6;
  operator*(v7, d[0], &P->m_data[v10]);
  v11 = 1i64;
  v12 = v6;
  if ( v6 >= 1 )
  {
    v13 = v10 + 1;
    do
    {
      v14 = operator*(&resulta, d[v11], &P->m_data[v13]);
      hkaNURBS::Point::operator+=(v7, v14);
      ++v11;
      ++v13;
    }
    while ( v11 <= v12 );
  }
  return v7;
}

// File Line: 355
// RVA: 0xBAFA00
void __fastcall hkaNURBS::CurvePoint(int n, int p, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, int mb, hkArray<float,hkContainerHeapAllocator> *ub, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Cb)
{
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v7; // rbp
  hkArray<float,hkContainerHeapAllocator> *v8; // r14
  int v9; // er15
  int v10; // er12
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rsi
  hkaNURBS::Point *v14; // rax
  hkaNURBS::Point result; // [rsp+30h] [rbp-38h]

  v7 = P;
  v8 = U;
  v9 = p;
  v10 = n;
  if ( mb >= 0 )
  {
    v11 = 0i64;
    v12 = 0i64;
    v13 = (unsigned int)(mb + 1);
    do
    {
      v14 = hkaNURBS::CurvePoint(&result, v10, v9, v8, v7, ub->m_data[v11]);
      hkaNURBS::Point::operator=(&Cb->m_data[v12], v14);
      ++v12;
      ++v11;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 369
// RVA: 0xBB2820
__int64 __usercall hkaNURBS::RemoveCurveKnot@<rax>(int n@<ecx>, int p@<edx>, hkArray<float,hkContainerHeapAllocator> *U@<r8>, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Pw@<r9>, float a5@<xmm0>, float u, int r, int s, int num, float TOL)
{
  hkArray<float,hkContainerHeapAllocator> *v10; // r12
  int v11; // er15
  __int32 v12; // er13
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v13; // r14
  hkaNURBS::Point *v14; // rdi
  signed int v15; // esi
  __int32 v16; // ebx
  int v17; // esi
  float v18; // xmm9_4
  signed int v19; // edi
  int v20; // er15
  int v21; // ecx
  int v22; // ebx
  __int64 v23; // r10
  __int32 v24; // ecx
  signed int v25; // er8
  float *v26; // rcx
  int v27; // er12
  float *v28; // rdx
  __int32 v29; // er14
  __int64 v30; // r13
  float *v31; // rcx
  float v32; // xmm6_4
  float v33; // xmm7_4
  hkaNURBS::Point *v34; // rax
  hkaNURBS::Point *v35; // rax
  hkaNURBS::Point *v36; // rax
  hkaNURBS::Point *v37; // rax
  hkaNURBS::Point *v38; // rax
  hkaNURBS::Point *v39; // rax
  __int64 v40; // ST40_8
  hkaNURBS::Point *v41; // rdx
  hkaNURBS::Point *v42; // rcx
  float v43; // xmm6_4
  hkaNURBS::Point *v44; // rbx
  hkaNURBS::Point *v45; // rax
  __int32 v46; // eax
  __int32 v47; // edi
  __int32 v48; // ebx
  signed __int64 v49; // r9
  signed __int64 v50; // r8
  unsigned __int64 v51; // r11
  signed __int64 v52; // rdx
  int v53; // ecx
  signed __int64 v54; // rax
  signed __int64 v55; // rax
  float v56; // er8
  float v57; // ecx
  signed __int64 v58; // rbx
  signed __int64 v59; // rdi
  __int64 v60; // r15
  int v61; // er15
  int v62; // eax
  int v63; // eax
  int v64; // er9
  __int64 v65; // rax
  hkaNURBS::Point *v66; // rbx
  __int64 v67; // rdi
  int v68; // ebx
  int v69; // ecx
  int v70; // ecx
  int v71; // er9
  __int32 v73; // [rsp+30h] [rbp-90h]
  int v74; // [rsp+34h] [rbp-8Ch]
  int v75; // [rsp+3Ch] [rbp-84h]
  int v76; // [rsp+40h] [rbp-80h]
  signed __int64 v77; // [rsp+48h] [rbp-78h]
  signed __int64 v78; // [rsp+50h] [rbp-70h]
  __int64 v79; // [rsp+58h] [rbp-68h]
  hkaNURBS::Point *v80; // [rsp+60h] [rbp-60h]
  __int64 v81; // [rsp+68h] [rbp-58h]
  hkaNURBS::Point v82[7]; // [rsp+70h] [rbp-50h]
  hkaNURBS::Point v83; // [rsp+E0h] [rbp+20h]
  hkaNURBS::Point v84; // [rsp+F0h] [rbp+30h]
  hkaNURBS::Point v85; // [rsp+100h] [rbp+40h]
  hkaNURBS::Point v86; // [rsp+110h] [rbp+50h]
  hkaNURBS::Point v87; // [rsp+120h] [rbp+60h]
  hkaNURBS::Point v88; // [rsp+130h] [rbp+70h]
  hkaNURBS::Point v89; // [rsp+140h] [rbp+80h]
  hkaNURBS::Point result; // [rsp+150h] [rbp+90h]
  hkaNURBS::Point v91; // [rsp+160h] [rbp+A0h]
  int v92; // [rsp+220h] [rbp+160h]
  int v93; // [rsp+228h] [rbp+168h]
  hkArray<float,hkContainerHeapAllocator> *v94; // [rsp+230h] [rbp+170h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v95; // [rsp+238h] [rbp+178h]
  float v96; // [rsp+240h] [rbp+180h]
  hkResult v97; // [rsp+248h] [rbp+188h]
  int vars0; // [rsp+250h] [rbp+190h]
  void *retaddr; // [rsp+258h] [rbp+198h]
  int v100; // [rsp+260h] [rbp+1A0h]

  v100 = n;
  v10 = U;
  v11 = p + 1;
  v12 = v97.m_enum - vars0;
  v13 = Pw;
  v14 = v82;
  v15 = 6;
  v16 = v97.m_enum - p;
  v73 = v97.m_enum - p;
  LODWORD(v82[0].point[2]) = (2 * v97.m_enum - p - vars0) / 2;
  do
  {
    hkaNURBS::Point::Point(v14, 0.0, 0.0, 0.0, 0.0);
    ++v14;
    --v15;
  }
  while ( v15 >= 0 );
  v17 = 0;
  v77 = 0i64;
  v81 = v12;
  v79 = v11;
  if ( (signed int)retaddr <= 0i64 )
    return 0i64;
  v18 = v96;
  v19 = 1;
  v78 = 4i64 * v11;
  v20 = 1 - v16;
  v21 = v16 - 1;
  v74 = v16 - 1;
  v76 = 1 - v16;
  LODWORD(v82[0].point[0]) = v97.m_enum - v12 - vars0 + 1;
  do
  {
    v80 = v13->m_data;
    hkaNURBS::Point::operator=(v82, &v13->m_data[v21]);
    v22 = v12 - v74;
    hkaNURBS::Point::operator=(&v82[v12 - v74 + 1], &v13->m_data[v12 + LODWORD(v82[0].point[0])]);
    v93 = v73;
    v23 = v79;
    v24 = v12;
    v25 = 1;
    vars0 = 1;
    LODWORD(v82[0].point[1]) = v12 - v73;
    if ( v12 - v73 > v17 )
    {
      v26 = v10->m_data;
      v27 = v93;
      v28 = &v26[v79];
      v29 = v12;
      v75 = v22 + 1;
      v77 = (signed __int64)&v26[v79];
      v30 = v79;
      v31 = &v26[v81 - v77];
      v78 = (signed __int64)v31;
      do
      {
        v32 = (float)(v18 - *v28) / (float)(*(float *)((char *)v28 + v78) - *v28);
        a5 = *(float *)((char *)v31 + v78) - *v31;
        v33 = (float)(v18 - *v31) / a5;
        v34 = operator*(&result, 1.0 - v32, &v82[v19 - 1]);
        v35 = hkaNURBS::Point::operator-(&v80[v27], &v91, v34);
        v36 = hkaNURBS::Point::operator/(v35, &v88, v32);
        hkaNURBS::Point::operator=(&v82[v19], v36);
        v37 = operator*(&v86, v33, &v82[v75]);
        v38 = hkaNURBS::Point::operator-(&v80[v29], &v83, v37);
        v39 = hkaNURBS::Point::operator/(v38, &v84, 1.0 - v33);
        hkaNURBS::Point::operator=(&v82[v22], v39);
        --v75;
        --v29;
        ++v27;
        v28 = (float *)(v77 + 4);
        v31 = (float *)(v78 - 4);
        ++v30;
        ++v19;
        --v22;
        v77 += 4i64;
        v78 -= 4i64;
      }
      while ( v29 - v27 > v17 );
      v20 = v76;
      v40 = v30;
      v12 = HIDWORD(v30);
      v23 = v40;
      vars0 = v19;
      v24 = v29;
      v25 = v19;
      v13 = v95;
      v93 = v27;
      v10 = v94;
      v19 = 1;
    }
    if ( v24 - v93 >= v17 )
    {
      a5 = v10->m_data[v23 + v79 + v77] - v10->m_data[v23];
      v43 = (float)(v18 - v10->m_data[v23]) / a5;
      v44 = operator*(&v85, 1.0 - v43, &v82[v25 - 1]);
      v45 = operator*(&v87, v43, &v82[v17 + vars0 + 1]);
      v41 = hkaNURBS::Point::operator+(v45, &v89, v44);
      v42 = &v13->m_data[v93];
    }
    else
    {
      v41 = &v82[v22 + 1];
      v42 = &v82[v25 - 1];
    }
    a5 = hkaNURBS::Distance3D(v42, v41, a5);
    if ( a5 > *(float *)&v100 )
      break;
    v46 = v73;
    v47 = v12;
    v48 = v73;
    if ( SLODWORD(v82[0].point[1]) > v17 )
    {
      do
      {
        hkaNURBS::Point::operator=(&v13->m_data[v48], &v82[v20 + v48]);
        hkaNURBS::Point::operator=(&v13->m_data[v47], &v82[v20 + v47]);
        --v47;
        ++v48;
      }
      while ( v47 - v48 > v17 );
      v46 = v73;
    }
    --v79;
    ++v81;
    v78 += 4i64;
    v73 = v46 - 1;
    v21 = v74 - 1;
    ++v20;
    ++v12;
    ++v17;
    --v74;
    v19 = 1;
    v76 = v20;
    ++v77;
  }
  while ( v77 < (signed int)retaddr );
  if ( !v17 )
    return 0i64;
  v49 = v97.m_enum + 1;
  if ( v49 <= (signed int)v80 )
  {
    if ( (signed int)v80 - (signed __int64)(v97.m_enum + 1) + 1 >= 4 )
    {
      v50 = 4 * (v49 - v17) + 12;
      v51 = ((unsigned __int64)((signed int)v80 - v49 - 3) >> 2) + 1;
      v49 += 4 * v51;
      do
      {
        v52 = v50 + 4i64 * v17;
        *(float *)((char *)v10->m_data + v50 - 12) = *(float *)((char *)v10->m_data + v52 - 12);
        *(float *)((char *)v10->m_data + v50 - 8) = *(float *)((char *)v10->m_data + v52 - 8);
        v53 = *(_DWORD *)((char *)&v10->m_data[v17 - 1] + v50);
        v54 = v50 + 4i64 * v17;
        v50 += 16i64;
        *(_DWORD *)((char *)v10->m_data + v50 - 20) = v53;
        *(float *)((char *)v10->m_data + v50 - 16) = *(float *)((char *)v10->m_data + v54);
        --v51;
      }
      while ( v51 );
    }
    for ( ; v49 <= (signed int)v80; *(float *)((char *)v10->m_data + v55 * 4 - 4i64 * v17) = v10->m_data[v55] )
      v55 = v49++;
  }
  v56 = v82[0].point[2];
  v57 = v82[0].point[2];
  if ( v17 > 1 )
  {
    do
    {
      if ( v19 & 1 )
        ++LODWORD(v57);
      else
        --LODWORD(v56);
      ++v19;
    }
    while ( v19 < v17 );
  }
  if ( LODWORD(v57) + 1 <= v92 )
  {
    v58 = LODWORD(v57) + 1;
    v59 = SLODWORD(v56);
    v60 = (unsigned int)(v92 - LODWORD(v57));
    do
    {
      hkaNURBS::Point::operator=(&v13->m_data[v59], &v13->m_data[v58]);
      ++v58;
      ++v59;
      --v60;
    }
    while ( v60 );
  }
  v61 = v13->m_size - (_DWORD)retaddr;
  v62 = v13->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v62 < v61 )
  {
    v63 = 2 * v62;
    v64 = v13->m_size - (_DWORD)retaddr;
    if ( v61 < v63 )
      v64 = v63;
    hkArrayUtil::_reserve(&v97, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, v64, 16);
  }
  v65 = v13->m_size;
  v66 = &v13->m_data[v65];
  if ( v61 - (signed int)v65 > 0 )
  {
    v67 = (unsigned int)(v61 - v65);
    do
    {
      if ( v66 )
        hkaNURBS::Point::Point(v66, 0.0, 0.0, 0.0, 0.0);
      ++v66;
      --v67;
    }
    while ( v67 );
  }
  v13->m_size = v61;
  v68 = v10->m_size - (_DWORD)retaddr;
  v69 = v10->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v69 < v68 )
  {
    v70 = 2 * v69;
    v71 = v10->m_size - (_DWORD)retaddr;
    if ( v68 < v70 )
      v71 = v70;
    hkArrayUtil::_reserve(&v97, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, v71, 4);
  }
  v10->m_size = v68;
  return (unsigned int)v17;
}

// File Line: 450
// RVA: 0xBB41D0
signed __int64 __fastcall hkaNURBS::Factorial(int i)
{
  signed __int64 result; // rax
  int v2; // edx
  signed int j; // ecx
  int v4; // [rsp+0h] [rbp-38h]
  int v5; // [rsp+4h] [rbp-34h]
  int v6; // [rsp+8h] [rbp-30h]
  int v7; // [rsp+Ch] [rbp-2Ch]
  int v8; // [rsp+10h] [rbp-28h]
  int v9; // [rsp+14h] [rbp-24h]
  int v10; // [rsp+18h] [rbp-20h]
  int v11; // [rsp+1Ch] [rbp-1Ch]
  int v12; // [rsp+20h] [rbp-18h]
  int v13; // [rsp+24h] [rbp-14h]
  int v14; // [rsp+28h] [rbp-10h]

  v4 = 1;
  v5 = 1;
  v6 = 2;
  v7 = 6;
  v8 = 24;
  v9 = 120;
  v10 = 720;
  v11 = 5040;
  v12 = 40320;
  v13 = 362880;
  result = 3628800i64;
  v2 = i;
  v14 = 3628800;
  if ( i <= 0 )
    return 1i64;
  if ( i <= 10 )
    return (unsigned int)*(&v4 + i);
  for ( j = 11; j <= v2; ++j )
    result = (unsigned int)(j * result);
  return result;
}

// File Line: 469
// RVA: 0xBB4180
__int64 __fastcall hkaNURBS::Bin(int i, int j)
{
  int v2; // esi
  int v3; // ebx
  int v4; // edi
  int v5; // edi

  v2 = i;
  v3 = j;
  v4 = hkaNURBS::Factorial(i - j);
  v5 = hkaNURBS::Factorial(v3) * v4;
  return (unsigned int)(hkaNURBS::Factorial(v2) / v5);
}

// File Line: 483
// RVA: 0xBAFCB0
void __fastcall hkaNURBS::DegreeElevateCurve(int *n, int p, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Pw, int t)
{
  int v5; // er14
  int v6; // er15
  hkArray<float,hkContainerHeapAllocator> *v7; // r13
  signed int v8; // ebx
  hkaNURBS::Point *v9; // rdi
  signed int v10; // esi
  hkaNURBS::Point *v11; // rdi
  signed int v12; // esi
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
  int v26; // er15
  __int64 v27; // rdi
  __int64 v28; // rdx
  int v29; // eax
  hkaNURBS::Point *v30; // r13
  signed __int64 v31; // r12
  int v32; // edi
  __m128i v33; // xmm0
  int v34; // eax
  float v35; // xmm7_4
  int v36; // er13
  int v37; // ebx
  int *v38; // r14
  signed __int64 v39; // rsi
  float v40; // xmm6_4
  signed int v41; // eax
  int v42; // er10
  int v43; // esi
  signed __int64 v44; // rbx
  __int64 v45; // r11
  int v46; // eax
  signed __int64 v47; // r9
  int v48; // eax
  signed __int64 v49; // rdi
  char *v50; // rcx
  unsigned __int64 v51; // r8
  char *v52; // rdx
  int v53; // eax
  __int64 v54; // r15
  int *v55; // rcx
  signed __int64 v56; // rdi
  int *v57; // rdx
  int v58; // eax
  int v59; // esi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v60; // r13
  hkRelocationInfo::Import *v61; // rdx
  int v62; // xmm11_4
  int v63; // er12
  int v64; // er14
  int v65; // eax
  int *v66; // rdi
  signed __int64 j; // rcx
  hkaNURBS::Point *v68; // rdi
  signed __int64 v69; // rsi
  __int64 v70; // rbx
  signed __int64 v71; // r13
  __int64 v72; // r9
  signed __int64 v73; // r15
  int v74; // edx
  signed __int64 v75; // rbx
  float *v76; // rcx
  float v77; // xmm0_4
  float v78; // xmm0_4
  float *v79; // rcx
  hkRelocationInfo::Import *v80; // r10
  int v81; // eax
  int v82; // ecx
  float v83; // xmm12_4
  int v84; // er8
  signed __int64 v85; // r12
  int v86; // ecx
  __int64 v87; // r14
  signed __int64 v88; // rdi
  float v89; // xmm3_4
  float *v90; // rdx
  float *v91; // r8
  signed __int64 v92; // r11
  signed __int64 v93; // r9
  unsigned __int64 v94; // rcx
  float v95; // xmm1_4
  float v96; // xmm2_4
  float v97; // xmm0_4
  float v98; // xmm1_4
  float v99; // xmm0_4
  float v100; // xmm2_4
  float *v101; // rcx
  signed __int64 v102; // rdi
  float v103; // xmm1_4
  int v104; // edi
  signed __int64 v105; // r12
  signed __int64 v106; // rax
  hkaNURBS::Point *v107; // r13
  signed __int64 v108; // rax
  int *v109; // rcx
  int v110; // eax
  int *v111; // r15
  signed __int64 v112; // r14
  int v113; // esi
  hkaNURBS::Point *v114; // rbx
  float v115; // xmm1_4
  hkaNURBS::Point *v116; // rdi
  hkaNURBS::Point *v117; // rax
  hkaNURBS::Point *v118; // rax
  bool v119; // zf
  int v120; // er15
  __int64 v121; // r9
  __int64 v122; // r12
  __int64 v123; // r13
  hkaNURBS::Point *v124; // r14
  hkaNURBS::Point *v125; // rax
  int v126; // edi
  int v127; // eax
  float *v128; // rsi
  signed __int64 v129; // rbx
  hkaNURBS::Point *v130; // rax
  hkaNURBS::Point *v131; // rax
  signed __int64 v132; // rcx
  int v133; // er12
  hkaNURBS::Point *v134; // r14
  __int64 v135; // rsi
  hkaNURBS::Point *v136; // rdi
  int v137; // er8
  float v138; // xmm9_4
  float v139; // xmm7_4
  __int64 v140; // rbx
  int v141; // ecx
  __int64 v142; // r10
  __int64 v143; // r13
  int v144; // edx
  int v145; // esi
  __int64 v146; // r11
  signed int v147; // er14
  hkaNURBS::Point *v148; // r12
  int v149; // er15
  int v150; // esi
  float *v151; // rcx
  float *v152; // r13
  hkaNURBS::Point *v153; // rbx
  float v154; // xmm6_4
  hkaNURBS::Point *v155; // rdi
  hkaNURBS::Point *v156; // rax
  hkaNURBS::Point *v157; // rax
  hkaNURBS::Point *v158; // rbx
  float v159; // xmm6_4
  hkaNURBS::Point *v160; // rdi
  hkaNURBS::Point *v161; // rax
  hkaNURBS::Point *v162; // rdx
  hkaNURBS::Point *v163; // rax
  __int64 v164; // rdx
  int v165; // eax
  int *v166; // rdi
  int v167; // er12
  __int64 v168; // rcx
  int v169; // er15
  hkaNURBS::Point *v170; // r13
  hkaNURBS::Point *v171; // rdi
  __int64 v172; // rbx
  __int64 v173; // r12
  __int64 v174; // rbx
  __int64 v175; // rdi
  int v176; // er14
  hkaNURBS::Point *v177; // rdi
  char *v178; // rsi
  __int64 v179; // rbx
  __int64 v180; // r8
  __int64 v181; // rcx
  float *v182; // rax
  int v183; // er8
  int v184; // [rsp+30h] [rbp-A8h]
  int v185; // [rsp+34h] [rbp-A4h]
  int v186; // [rsp+38h] [rbp-A0h]
  int v187; // [rsp+3Ch] [rbp-9Ch]
  int v188; // [rsp+40h] [rbp-98h]
  __int64 v189; // [rsp+48h] [rbp-90h]
  int v190; // [rsp+50h] [rbp-88h]
  int v191; // [rsp+54h] [rbp-84h]
  __int64 v192; // [rsp+58h] [rbp-80h]
  hkaNURBS::Point *a; // [rsp+60h] [rbp-78h]
  hkRelocationInfo::Import *v194; // [rsp+68h] [rbp-70h]
  __int64 v195; // [rsp+70h] [rbp-68h]
  int *v196; // [rsp+78h] [rbp-60h]
  hkaNURBS::Point *k; // [rsp+80h] [rbp-58h]
  hkaNURBS::Point *v198; // [rsp+88h] [rbp-50h]
  __int64 v199; // [rsp+90h] [rbp-48h]
  __int64 v200; // [rsp+98h] [rbp-40h]
  int v201; // [rsp+A0h] [rbp-38h]
  int v202; // [rsp+A4h] [rbp-34h]
  __int64 v203; // [rsp+A8h] [rbp-30h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v204; // [rsp+B0h] [rbp-28h]
  hkRelocationInfo::Import *v205; // [rsp+C0h] [rbp-18h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v206; // [rsp+C8h] [rbp-10h]
  char v207[16]; // [rsp+D8h] [rbp+0h]
  __int64 v208; // [rsp+E8h] [rbp+10h]
  hkaNURBS::Point v209[3]; // [rsp+F8h] [rbp+20h]
  char v210[8]; // [rsp+130h] [rbp+58h]
  int v211; // [rsp+138h] [rbp+60h]
  char v212[60]; // [rsp+13Ch] [rbp+64h]
  hkaNURBS::Point v213[4]; // [rsp+178h] [rbp+A0h]
  hkaNURBS::Point v214; // [rsp+1B8h] [rbp+E0h]
  char v215; // [rsp+1C8h] [rbp+F0h]
  hkaNURBS::Point v216; // [rsp+1D8h] [rbp+100h]
  hkaNURBS::Point v217; // [rsp+1E8h] [rbp+110h]
  hkaNURBS::Point result; // [rsp+1F8h] [rbp+120h]
  hkaNURBS::Point v219; // [rsp+208h] [rbp+130h]
  hkaNURBS::Point v220; // [rsp+218h] [rbp+140h]
  hkaNURBS::Point v221; // [rsp+228h] [rbp+150h]
  hkaNURBS::Point v222; // [rsp+238h] [rbp+160h]
  hkaNURBS::Point v223; // [rsp+248h] [rbp+170h]
  hkaNURBS::Point v224; // [rsp+258h] [rbp+180h]
  hkaNURBS::Point v225; // [rsp+268h] [rbp+190h]
  hkaNURBS::Point v226; // [rsp+278h] [rbp+1A0h]
  hkaNURBS::Point v227; // [rsp+288h] [rbp+1B0h]
  hkaNURBS::Point v228; // [rsp+298h] [rbp+1C0h]
  hkaNURBS::Point v229[6]; // [rsp+2A8h] [rbp+1D0h]
  _DWORD *v230; // [rsp+3A8h] [rbp+2D0h]
  int i; // [rsp+3B0h] [rbp+2D8h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v232; // [rsp+3B8h] [rbp+2E0h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *vars0; // [rsp+3C0h] [rbp+2E8h]
  void *retaddr; // [rsp+3C8h] [rbp+2F0h]

  v5 = *n;
  v6 = *n + p + 1;
  v7 = U;
  LODWORD(v194) = *n + p + 1;
  if ( (_DWORD)retaddr )
  {
    v8 = 3;
    v9 = v209;
    v10 = 3;
    do
    {
      hkaNURBS::Point::Point(v9, 0.0, 0.0, 0.0, 0.0);
      ++v9;
      --v10;
    }
    while ( v10 >= 0 );
    v11 = v213;
    v12 = 3;
    do
    {
      hkaNURBS::Point::Point(v11, 0.0, 0.0, 0.0, 0.0);
      ++v11;
      --v12;
    }
    while ( v12 >= 0 );
    v13 = v229;
    do
    {
      hkaNURBS::Point::Point(v13, 0.0, 0.0, 0.0, 0.0);
      ++v13;
      --v8;
    }
    while ( v8 >= 0 );
    v14 = (signed int)retaddr;
    v15 = v5 + (_DWORD)retaddr * (hkaNURBS::UniqueKnotCount(v7, v6) - 1);
    v16 = i;
    v201 = v15;
    v17 = v15 + i + (_DWORD)retaddr + 2;
    v18 = v17;
    if ( v17 )
    {
      v184 = 4 * v17;
      v19 = (hkRelocationInfo::Import *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                          &hkContainerHeapAllocator::s_alloc,
                                          &v184,
                                          0i64);
      v17 = v184 / 4;
    }
    else
    {
      v19 = 0i64;
    }
    v194 = v19;
    v204.m_data = v19;
    v20 = v15 + 1;
    v21 = 2147483648;
    v204.m_size = v18;
    if ( v17 )
      v21 = v17;
    v22 = v20;
    v204.m_capacityAndFlags = v21;
    if ( v20 )
    {
      v184 = 16 * v20;
      v23 = (hkaNURBS::Point *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                 &hkContainerHeapAllocator::s_alloc,
                                 &v184,
                                 0i64);
      v20 = v184 / 16;
    }
    else
    {
      v23 = 0i64;
    }
    v24 = 2147483648;
    v198 = v23;
    if ( v20 )
      v24 = v20;
    v206.m_data = (hkRelocationInfo::Import *)v23;
    v206.m_size = v22;
    v206.m_capacityAndFlags = v24;
    if ( (signed int)v22 > 0 )
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
    v27 = (signed int)v16 + (signed int)retaddr;
    v28 = v16;
    *(&v211 + v16 + 4 * v27) = 1065353216;
    v29 = ((signed int)v16 + (signed int)retaddr) / 2;
    v188 = v16 + (_DWORD)retaddr;
    v200 = (signed int)v16 + (signed int)retaddr;
    v30 = (hkaNURBS::Point *)v29;
    v199 = v16;
    v211 = 1065353216;
    LODWORD(v192) = ((signed int)v16 + (signed int)retaddr) / 2;
    v184 = 1;
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
        if ( (signed int)v16 < v26 )
          v34 = v16;
        v35 = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v33));
        if ( v32 <= (signed __int64)v34 )
        {
          v36 = i;
          v37 = v26 - v32;
          v38 = &v211 + v32 + 4 * v31;
          v39 = v34 - (signed __int64)v32 + 1;
          do
          {
            v40 = (float)hkaNURBS::Bin(v36, v32) * v35;
            v41 = hkaNURBS::Bin((int)retaddr, v37);
            ++v32;
            --v37;
            ++v38;
            *((float *)v38 - 1) = v40 * (float)v41;
            --v39;
          }
          while ( v39 );
          v26 = v184;
          v30 = a;
          LODWORD(v16) = i;
          v25 = v188;
        }
        ++v26;
        ++v31;
        v184 = v26;
        if ( v31 > (signed __int64)v30 )
          break;
        v14 = (signed int)retaddr;
      }
      v29 = v192;
      v28 = (signed int)v16;
      v27 = v25;
    }
    v42 = v29 + 1;
    v43 = v25 - 1;
    if ( v29 + 1 > v25 - 1 )
    {
      v54 = v199;
    }
    else
    {
      v44 = 4i64 * v42;
      v45 = 4 * (v27 - v42);
      while ( 1 )
      {
        v46 = v42 - (_DWORD)retaddr;
        if ( v42 - (signed int)retaddr < 0 )
          v46 = 0;
        v47 = v46;
        v48 = v42;
        if ( (signed int)v16 < v42 )
          v48 = v16;
        v49 = v48;
        if ( v47 > v48 )
        {
          v54 = (signed int)v16;
        }
        else
        {
          if ( v48 - v47 + 1 >= 4 )
          {
            v50 = &v212[4 * (v47 + v44)];
            v51 = ((unsigned __int64)(v48 - v47 - 3) >> 2) + 1;
            v52 = &v210[4 * (v45 + v28 - v47)];
            v47 += 4 * v51;
            do
            {
              v53 = *((_DWORD *)v52 + 2);
              v50 += 16;
              v52 -= 16;
              *((_DWORD *)v50 - 5) = v53;
              *((_DWORD *)v50 - 4) = *((_DWORD *)v52 + 5);
              *((_DWORD *)v50 - 3) = *((_DWORD *)v52 + 4);
              *((_DWORD *)v50 - 2) = *((_DWORD *)v52 + 3);
              --v51;
            }
            while ( v51 );
          }
          v54 = (signed int)v16;
          if ( v47 <= v49 )
          {
            v55 = &v211 + v44 + v47;
            v56 = v49 - v47 + 1;
            v57 = &v211 + v45 + (signed int)v16 - v47;
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
        v28 = (signed int)v16;
      }
      v25 = v188;
    }
    v59 = i;
    v60 = vars0;
    v61 = vars0->m_data;
    v62 = v232->m_data->m_fromOffset;
    v63 = v25 + 1;
    v64 = i + 1;
    v184 = v232->m_data->m_fromOffset;
    v190 = -1;
    LODWORD(v195) = 1;
    v186 = v25 + 1;
    v185 = i + 1;
    hkaNURBS::Point::operator=(v198, (hkaNURBS::Point *)v61);
    if ( v25 >= 0 )
    {
      v65 = v184;
      v66 = &v194->m_fromOffset;
      for ( j = v25 + 1i64; j; --j )
      {
        *v66 = v65;
        ++v66;
      }
    }
    if ( v59 >= 0 )
    {
      v68 = v209;
      v69 = (char *)v60->m_data - (char *)v209;
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
    v195 = v54;
    v73 = (signed int)v194;
    v189 = v64;
    for ( k = (hkaNURBS::Point *)v63; v71 < v73; v59 = i )
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
            v79 = (float *)(&v232->m_data->m_fromOffset + v71);
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
            v189 = v71;
            v185 = v64;
          }
        }
        else
        {
          v76 = (float *)((char *)&v232->m_data->m_identifier + 4 * v71);
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
            v185 = v64;
            v189 = v71;
            if ( v71 >= v73 - 3 )
              goto LABEL_71;
          }
        }
      }
      v80 = v232->m_data;
      v81 = v190;
      v82 = v64 - v74 + 1;
      v83 = *((float *)&v232->m_data->m_fromOffset + v71);
      v84 = v59 - v82;
      v85 = v71 - v75 + 1;
      LODWORD(a) = v190;
      v190 = v59 - v82;
      if ( (signed int)a <= 0 )
        HIDWORD(v192) = 1;
      else
        HIDWORD(v192) = (v81 + 2) / 2;
      v86 = v188;
      if ( v84 > 0 )
        v86 = v188 - (v84 + 1) / 2;
      LODWORD(v192) = v86;
      if ( v84 > 0 )
      {
        v87 = v59;
        v88 = v59;
        v89 = v83 - *(float *)&v62;
        if ( v59 > v85 )
        {
          if ( v59 - v85 >= 4 )
          {
            v90 = (float *)(&v206.m_size + v59 - v85);
            v91 = (float *)(&v80->m_fromOffset + v59 + v72 - 1);
            v92 = (signed __int64)v80 + 4 * (v85 + v72) + 8 - (_QWORD)v207;
            v93 = (signed __int64)v80 + 4 * (v85 + v72) - (_QWORD)v207;
            v94 = ((unsigned __int64)(v59 - v85 - 4) >> 2) + 1;
            v88 = v59 - 4 * v94;
            do
            {
              v95 = *(float *)((char *)v90 + v92);
              v96 = *v91;
              v90 -= 4;
              v91 -= 4;
              v97 = v89 / (float)(v95 - *(float *)&v62);
              v98 = *(float *)((char *)v90 + v93 + 16) - *(float *)&v62;
              v90[5] = v97;
              v99 = v89 / (float)(v96 - *(float *)&v62);
              v100 = *(float *)((char *)v90 + v93 + 12) - *(float *)&v62;
              v90[4] = v99;
              v90[3] = v89 / v98;
              v90[2] = v89 / v100;
              --v94;
            }
            while ( v94 );
            v84 = v190;
            v72 = v195;
          }
          if ( v88 > v85 )
          {
            v101 = (float *)(&v80->m_fromOffset + v72 + v88);
            v102 = v88 - v85;
            do
            {
              v103 = *v101;
              --v101;
              *(float *)((char *)v101 + &v207[-4 * (v85 + v72)] - (char *)v80) = v89 / (float)(v103 - *(float *)&v62);
              --v102;
            }
            while ( v102 );
          }
        }
        v192 = v84;
        if ( v84 >= 1i64 )
        {
          v104 = v84 - 1;
          v187 = v84 - 1;
          v105 = v71 - v75 + 2;
          a = &v209[v59];
          v106 = v59 - v71;
          v107 = &v209[v59];
          v108 = v75 + v106;
          v109 = &v206.m_size + v108;
          v196 = &v206.m_size + v108;
          do
          {
            v110 = v59;
            if ( v87 >= v105 )
            {
              v111 = v109;
              v112 = v87 - v105 + 1;
              do
              {
                v113 = v110 - 1;
                v114 = &v209[v110];
                v115 = *(float *)v111;
                v116 = operator*(&result, 1.0 - *(float *)v111, &v209[v110 - 1]);
                v117 = operator*(&v223, v115, v114);
                v118 = hkaNURBS::Point::operator+(v117, &v225, v116);
                hkaNURBS::Point::operator=(v114, v118);
                --v111;
                v110 = v113;
                --v112;
              }
              while ( v112 );
              v104 = v187;
              v59 = i;
              v87 = v199;
            }
            hkaNURBS::Point::operator=(&v229[v104--], v107);
            v109 = v196 - 1;
            ++v105;
            v119 = v192-- == 1;
            --v196;
            v187 = v104;
          }
          while ( !v119 );
          v71 = v189;
        }
      }
      v120 = HIDWORD(v192);
      v192 = SHIDWORD(v192);
      v121 = v192;
      v122 = v192;
      if ( v192 <= v200 )
      {
        v123 = v200;
        do
        {
          v124 = &v213[v120];
          hkaNURBS::Point::Point(&v227, 0.0, 0.0, 0.0, 0.0);
          hkaNURBS::Point::operator=(v124, v125);
          v126 = v120 - (_DWORD)retaddr;
          if ( v120 - (signed int)retaddr < 0 )
            v126 = 0;
          v127 = v120;
          if ( v59 < v120 )
            v127 = v59;
          if ( v126 <= (signed __int64)v127 )
          {
            v128 = (float *)(&v211 + v126 + 4 * v122);
            v129 = v127 - (signed __int64)v126 + 1;
            do
            {
              v130 = operator*(&v216, *v128, &v209[v126]);
              v131 = hkaNURBS::Point::operator+(v124, &v226, v130);
              hkaNURBS::Point::operator=(v124, v131);
              ++v126;
              ++v128;
              --v129;
            }
            while ( v129 );
            v59 = i;
          }
          ++v122;
          ++v120;
        }
        while ( v122 <= v123 );
        v71 = v189;
        v121 = v192;
      }
      v132 = (signed int)a;
      v133 = v186;
      v134 = k;
      v135 = (__int64)v194;
      if ( (signed int)a > 1 )
      {
        v136 = k;
        a = k;
        v203 = v132;
        v137 = v186 - 2;
        LODWORD(v196) = v186 - 2;
        v138 = 1.0 / (float)(v83 - *(float *)&v62);
        v139 = (float)(v83 - *((float *)v194 + (_QWORD)k - 1)) * v138;
        if ( v132 > 1 )
        {
          v140 = v203;
          v141 = 1;
          v142 = (__int64)v194 + 4 * (_QWORD)k - 8;
          v143 = (__int64)v194;
          v144 = v186 - 3;
          v145 = v186 - 1;
          v146 = 1i64 - (_QWORD)k;
          v205 = (hkRelocationInfo::Import *)((char *)v194 + 4 * (_QWORD)k - 8);
          v187 = 1;
          v202 = v186 - 1;
          v191 = v186 - 3;
          v208 = 1i64 - (_QWORD)k;
          do
          {
            v147 = v137;
            v148 = v136;
            v149 = v141;
            if ( v145 + v141 - v137 > v141 )
            {
              v150 = v141 + 1;
              v151 = (float *)v142;
              v152 = (float *)(v143 - 4 * v146);
              v196 = (int *)v142;
              do
              {
                if ( v147 < (signed int)v195 )
                {
                  v153 = &v198[v147];
                  v154 = (float)(v83 - *v151) / (float)(*(float *)&v62 - *v151);
                  v155 = operator*(&v214, 1.0 - v154, &v198[v147 - 1]);
                  v156 = operator*(&v224, v154, v153);
                  v157 = hkaNURBS::Point::operator+(v156, &v220, v155);
                  hkaNURBS::Point::operator=(v153, v157);
                  v151 = (float *)v196;
                  v144 = v191;
                  v121 = v192;
                }
                if ( (signed __int64)v148 >= v121 )
                {
                  if ( v144 + v150 > v186 + (signed int)a - v188 )
                  {
                    v158 = &v213[v149];
                    v160 = operator*(&v217, 1.0 - v139, &v213[v150]);
                    v161 = operator*(&v219, v139, v158);
                    v162 = &v221;
                  }
                  else
                  {
                    v158 = &v213[v149];
                    v159 = (float)(v83 - *v152) * v138;
                    v160 = operator*(&v228, 1.0 - v159, &v213[v150]);
                    v161 = operator*(&v222, v159, v158);
                    v162 = (hkaNURBS::Point *)&v215;
                  }
                  v163 = hkaNURBS::Point::operator+(v161, v162, v160);
                  hkaNURBS::Point::operator=(v158, v163);
                  v121 = v192;
                  v151 = (float *)v196;
                }
                v144 = v191;
                ++v147;
                --v150;
                ++v151;
                v148 = (hkaNURBS::Point *)((char *)v148 - 1);
                --v152;
                --v149;
                v196 = (int *)v151;
              }
              while ( v150 + v186 - 2 - v147 > v187 );
              v141 = v187;
              v136 = a;
              v137 = (signed int)v196;
              v142 = (__int64)v205;
              v146 = v208;
              v140 = v203;
              v145 = v202;
              v143 = (__int64)v194;
            }
            v136 = (hkaNURBS::Point *)((char *)v136 + 1);
            --v137;
            v142 -= 4i64;
            ++v141;
            --v144;
            LODWORD(v196) = v137;
            v205 = (hkRelocationInfo::Import *)v142;
            a = v136;
            v187 = v141;
            v191 = v144;
          }
          while ( (signed __int64)v136 + v146 < v140 );
          v71 = v189;
          LODWORD(v132) = (_DWORD)a;
          v133 = v186;
          v134 = k;
          v135 = (__int64)v194;
        }
      }
      if ( v195 != v199 && v188 - (signed int)v132 > 0 )
      {
        v164 = (unsigned int)(v188 - v132);
        v165 = v184;
        v166 = (int *)(v135 + 4i64 * (_QWORD)v134);
        v167 = v164 + v133;
        v168 = (unsigned int)v164;
        v134 = (hkaNURBS::Point *)((char *)v134 + v164);
        while ( v168 )
        {
          *v166 = v165;
          ++v166;
          --v168;
        }
        k = v134;
        v186 = v167;
      }
      if ( SHIDWORD(v192) <= (signed int)v192 )
      {
        v169 = v195;
        v170 = v198;
        v171 = &v213[v121];
        v172 = (unsigned int)(v192 - HIDWORD(v192) + 1);
        do
        {
          hkaNURBS::Point::operator=(&v170[v169++], v171);
          ++v171;
          --v172;
        }
        while ( v172 );
        v71 = v189;
        LODWORD(v195) = v169;
      }
      v73 = (signed int)v194;
      if ( v71 >= (signed int)v194 )
      {
        v180 = v200;
        v181 = 0i64;
        if ( v200 >= 0 )
        {
          v182 = (float *)(v135 + 4i64 * (_QWORD)v134);
          do
          {
            ++v181;
            *v182 = v83;
            ++v182;
          }
          while ( v181 <= v180 );
        }
        v72 = v195;
        v64 = v185;
      }
      else
      {
        v173 = v190;
        if ( v190 > 0 )
        {
          v174 = (unsigned int)v190;
          v175 = 0i64;
          do
          {
            hkaNURBS::Point::operator=(&v209[v175], &v229[v175]);
            ++v175;
            --v174;
          }
          while ( v174 );
        }
        v176 = v185;
        if ( (signed int)v173 <= i )
        {
          v177 = &v209[v173];
          v178 = (char *)vars0->m_data + 16 * ((signed int)v173 + v185 - i - v173) - (_QWORD)v209;
          v179 = (unsigned int)(i - v173 + 1);
          do
          {
            hkaNURBS::Point::operator=(v177, (hkaNURBS::Point *)((char *)v177 + (_QWORD)v178));
            ++v177;
            --v179;
          }
          while ( v179 );
        }
        v64 = v176 + 1;
        v72 = v71;
        v195 = v71;
        *(float *)&v62 = v83;
        ++v71;
        v185 = v64;
        v184 = LODWORD(v83);
        v189 = v71;
      }
    }
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(vars0, &v206);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(&v204, v232);
    v183 = v206.m_capacityAndFlags;
    *v230 = v201;
    if ( v183 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v206.m_data,
        16 * v183);
    if ( v204.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v204.m_data,
        4 * v204.m_capacityAndFlags);
  }
}

// File Line: 651
// RVA: 0xBAFB30
void __usercall hkaNURBS::ChordLengthParameterization(int m@<ecx>, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q@<rdx>, hkArray<float,hkContainerHeapAllocator> *U@<r8>, float a4@<xmm0>)
{
  signed __int64 v4; // r15
  int v5; // ebx
  int v6; // eax
  hkArray<float,hkContainerHeapAllocator> *v7; // rdi
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v8; // rsi
  signed __int64 v9; // rbp
  int v10; // eax
  int v11; // er9
  float *v12; // rax
  __int64 v13; // r14
  hkaNURBS::Point *v14; // rsi
  float *v15; // rbx
  hkaNURBS::Point *v16; // rax
  signed __int64 v17; // rcx
  hkaNURBS::Point v18; // [rsp+30h] [rbp-28h]
  hkResult result; // [rsp+60h] [rbp+8h]

  v4 = m;
  v5 = m + 1;
  v6 = U->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = U;
  v8 = Q;
  v9 = 1i64;
  if ( v6 < m + 1 )
  {
    v10 = 2 * v6;
    v11 = m + 1;
    if ( v5 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, U, v11, 4);
  }
  v12 = v7->m_data;
  v7->m_size = v5;
  *v12 = 0.0;
  if ( (signed int)v4 >= 1 )
  {
    v13 = (unsigned int)v4;
    v14 = v8->m_data + 1;
    do
    {
      v15 = v7->m_data;
      v16 = hkaNURBS::Point::operator-(v14, &v18, v14 - 1);
      ++v9;
      ++v14;
      a4 = hkaNURBS::Point::mag(v16, a4) + v15[v9 - 2];
      v15[v9 - 1] = a4;
      --v13;
    }
    while ( v13 );
  }
  v17 = 1i64;
  if ( v4 > 1 )
  {
    if ( v4 - 1 >= 4 )
    {
      do
      {
        v17 += 4i64;
        v7->m_data[v17 - 4] = v7->m_data[v17 - 4] / v7->m_data[v4];
        v7->m_data[v17 - 3] = v7->m_data[v17 - 3] / v7->m_data[v4];
        v7->m_data[v17 - 2] = v7->m_data[v17 - 2] / v7->m_data[v4];
        v7->m_data[v17 - 1] = v7->m_data[v17 - 1] / v7->m_data[v4];
      }
      while ( v17 < v4 - 3 );
    }
    for ( ; v17 < v4; v7->m_data[v17 - 1] = v7->m_data[v17 - 1] / v7->m_data[v4] )
      ++v17;
  }
  v7->m_data[v4] = 1.0;
}

// File Line: 685
// RVA: 0xBB1BA0
float __fastcall hkaNURBS::GetRemovalBoundCurve(int n, int p, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, float u, int r, int s)
{
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v7; // r12
  hkArray<float,hkContainerHeapAllocator> *v8; // r13
  int v9; // er14
  hkaNURBS::Point *v10; // rbx
  signed int v11; // edi
  hkaNURBS::Point *v12; // r12
  int v13; // ebp
  int v14; // edi
  int v15; // esi
  int v16; // ebx
  int v17; // er14
  __int64 v18; // rdx
  signed int v19; // er15
  float *v20; // rax
  int v21; // er13
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
  hkaNURBS::Point v38; // [rsp+30h] [rbp-148h]
  hkaNURBS::Point v39; // [rsp+40h] [rbp-138h]
  hkaNURBS::Point v40; // [rsp+50h] [rbp-128h]
  hkaNURBS::Point v41[7]; // [rsp+60h] [rbp-118h]
  hkaNURBS::Point result; // [rsp+D0h] [rbp-A8h]
  hkaNURBS::Point v43; // [rsp+E0h] [rbp-98h]
  hkaNURBS::Point v44; // [rsp+F0h] [rbp-88h]
  hkArray<float,hkContainerHeapAllocator> *v45; // [rsp+190h] [rbp+18h]
  __int64 v46; // [rsp+198h] [rbp+20h]

  v45 = U;
  v7 = P;
  v8 = U;
  v9 = p;
  v10 = v41;
  v11 = 6;
  do
  {
    hkaNURBS::Point::Point(v10, 0.0, 0.0, 0.0, 0.0);
    ++v10;
    --v11;
  }
  while ( v11 >= 0 );
  v12 = v7->m_data;
  v13 = r - v9;
  v14 = v9 + 1;
  v15 = r - s;
  v16 = r - v9 - 1;
  hkaNURBS::Point::operator=(v41, &v12[v16]);
  v17 = -s - (-v9 - 1);
  hkaNURBS::Point::operator=(&v41[v15 - v16 + 1], &v12[v15 + 1]);
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
      v27 = hkaNURBS::Point::operator-(&v12[v13], &v43, v26);
      v28 = hkaNURBS::Point::operator/(v27, &v44, v24);
      hkaNURBS::Point::operator=(&v41[v19], v28);
      v29 = operator*(&v38, v25, &v41[v21]);
      v30 = hkaNURBS::Point::operator-(&v12[v15], &v39, v29);
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
    v8 = v45;
  }
  if ( v15 - v13 >= 0 )
  {
    v34 = (float)(u - v8->m_data[v13]) / (float)(v8->m_data[v18 + v13] - v8->m_data[v13]);
    v35 = operator*(&v40, 1.0 - v34, &v41[v19 - 1]);
    v36 = operator*(&v39, v34, &v41[v19 + 1]);
    v32 = hkaNURBS::Point::operator+(v36, &v38, v35);
    v33 = &v12[v13];
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
__int64 __fastcall hkaNURBS::RemoveKnotsBoundCurve(int *n, int p, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, int mb, hkArray<float,hkContainerHeapAllocator> *ub, hkArray<float,hkContainerHeapAllocator> *e, float E, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q_JUNK)
{
  __int64 v9; // r14
  int *v10; // r15
  int v11; // er13
  int v12; // er12
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
  signed __int64 v32; // r15
  int v33; // eax
  signed __int64 v34; // r8
  signed __int64 v35; // rdi
  float *v36; // r13
  int v37; // edx
  __int64 v38; // r9
  float v39; // xmm6_4
  int v40; // er15
  int v41; // eax
  float *v42; // rbx
  int v43; // eax
  float v44; // xmm7_4
  __int64 v45; // rsi
  __int64 v46; // r12
  __int64 v47; // rbx
  char *v48; // rsi
  __int64 v49; // rdi
  float v50; // xmm0_4
  float *v51; // rcx
  float v52; // xmm0_4
  int v53; // eax
  _BYTE *v54; // r13
  int v55; // er15
  signed __int64 v56; // rdi
  float *v57; // r9
  signed __int64 v58; // r10
  signed __int64 v59; // rcx
  signed __int64 v60; // rdx
  unsigned __int64 v61; // r8
  int v62; // eax
  signed __int64 v63; // r9
  signed __int64 v64; // rcx
  signed __int64 v65; // rdi
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
  int v77; // er12
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
  int s; // [rsp+50h] [rbp-B0h]
  int m; // [rsp+54h] [rbp-ACh]
  int r; // [rsp+58h] [rbp-A8h]
  int v94; // [rsp+5Ch] [rbp-A4h]
  int v95; // [rsp+60h] [rbp-A0h]
  int v96; // [rsp+64h] [rbp-9Ch]
  int v97; // [rsp+68h] [rbp-98h]
  char *v98; // [rsp+70h] [rbp-90h]
  int v99; // [rsp+78h] [rbp-88h]
  int v100; // [rsp+7Ch] [rbp-84h]
  int v101; // [rsp+80h] [rbp-80h]
  hkArray<float,hkContainerHeapAllocator> arr; // [rsp+88h] [rbp-78h]
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
  int *v116; // [rsp+1A0h] [rbp+A0h]
  int pa; // [rsp+1A8h] [rbp+A8h]
  hkArray<float,hkContainerHeapAllocator> *Ua; // [rsp+1B0h] [rbp+B0h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Pa; // [rsp+1B8h] [rbp+B8h]

  Pa = P;
  Ua = U;
  pa = p;
  v116 = n;
  v9 = p;
  v10 = n;
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
    v14 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &s);
    v13 = s / 4;
  }
  v15 = 2147483648;
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
      *v17 = 3.40282e38;
      ++v17;
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
    v20 = (_DWORD *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      &v101);
    v19 = v101 / 4;
  }
  v21 = 2147483648;
  v104 = v20;
  if ( v19 )
    v21 = v19;
  v105 = v21;
  v22 = v18;
  if ( v18 > 0 )
  {
    while ( v22 )
    {
      *v20 = 0;
      ++v20;
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
    v24 = (char *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    &v100);
    v23 = v100 / 4;
  }
  v25 = 2147483648;
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
    v112 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
             &v94);
    v27 = v94 / 4;
  }
  v28 = 2147483648;
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
    v114 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
             &v97);
    v18 = v97 / 4;
  }
  v29 = 2147483648;
  v96 = v9 + 1;
  if ( v18 )
    v29 = v18;
  v30 = Ua;
  v108 = v29;
  hkaNURBS::ComputeBounds(*v10, v9, Ua, Pa, &arr, v9 + 1, v11 - v9 - 1);
  v31 = hkaNURBS::MinIndex(&arr, v12);
  v32 = v31;
  r = v31;
  v33 = hkaNURBS::Multiplicity(v31, v11, Ua);
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
      if ( (v37 + pa) % 2 )
      {
        v41 = (v37 + v96) / 2;
        v40 = v32 - v41 + 1;
        v39 = (float)(v30->m_data[v34] - v30->m_data[v35 - v41 + 1])
            / (float)(v30->m_data[v38 + 2 + v35 - v41] - v30->m_data[v35 - v41 + 1]);
      }
      else
      {
        v39 = 0.0;
        v40 = v32 - (v37 + pa) / 2;
      }
      v42 = v30->m_data;
      v43 = hkaNURBS::Find(v42[v40], ub, mb);
      v44 = 0.0;
      v45 = v43;
      v115 = v43;
      v46 = v43;
      v47 = hkaNURBS::Find(v42[v40 + 1 + i], ub, mb) - 1;
      if ( v45 <= v47 )
      {
        v48 = v98;
        v49 = v104 - v98;
        do
        {
          v50 = hkaNURBS::OneBasisFun(pa, m, Ua, v40, ub->m_data[v46]);
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
        v30 = Ua;
        *v36 = 3.40282e38;
      }
      else
      {
        v53 = e->m_size;
        v54 = 0i64;
        v55 = 2147483648;
        if ( v53 > 0 )
        {
          v95 = 4 * v53;
          v54 = (_BYTE *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                           &v95);
          v55 = v95 / 4;
        }
        v56 = e->m_size;
        v57 = e->m_data;
        v58 = 0i64;
        if ( v56 >= 4 )
        {
          v59 = (signed __int64)(v54 + 4);
          v60 = (char *)v57 - v54;
          v61 = ((unsigned __int64)(v56 - 4) >> 2) + 1;
          v58 = 4 * v61;
          do
          {
            v62 = *(_DWORD *)(v59 + v60 - 4);
            v59 += 16i64;
            *(_DWORD *)(v59 - 20) = v62;
            *(_DWORD *)(v59 - 16) = *(_DWORD *)(v60 + v59 - 16);
            *(_DWORD *)(v59 - 12) = *(_DWORD *)(v60 + v59 - 12);
            *(_DWORD *)(v59 - 8) = *(_DWORD *)(v59 + v60 - 8);
            --v61;
          }
          while ( v61 );
        }
        if ( v58 < v56 )
        {
          v63 = (char *)v57 - v54;
          v64 = (signed __int64)&v54[4 * v58];
          v65 = v56 - v58;
          do
          {
            v66 = *(_DWORD *)(v63 + v64);
            v64 += 4i64;
            *(_DWORD *)(v64 - 4) = v66;
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
        hkaNURBS::RemoveCurveKnot(*v116, pa, Ua, Pa, Ua->m_data[v111 / 4], r, s, 1, 3.40282e38);
        v76 = m;
        --*v116;
        m = v76 - 1;
        v77 = v76;
        v99 = v76;
        if ( v76 <= 2 * pa + 2 )
        {
          if ( v55 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v54,
              4 * v55);
          break;
        }
        hkaNURBS::Remove(v75, &arr, v76);
        v78 = v75;
        v79 = v75 - pa;
        v80 = *v116;
        v81 = *v116;
        v82 = pa + v78 - s;
        if ( v82 < *v116 )
          v81 = v82;
        v83 = hkaNURBS::UniqueKnot(v81, Ua, m);
        v84 = v96;
        hi = v83;
        if ( v79 > v96 )
          v84 = v79;
        v30 = Ua;
        lo = hkaNURBS::UniqueKnot(v84, Ua, m);
        hkaNURBS::ComputeBounds(v80, pa, Ua, Pa, &arr, lo, hi);
        if ( v55 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v54,
            4 * v55);
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
  v89 = v103 - *v116;
  if ( v108 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v114,
      4 * v108);
  if ( v110 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v112,
      4 * v110);
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v98,
      4 * v107);
  if ( v105 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v104,
      4 * v105);
  if ( arr.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      arr.m_data,
      4 * arr.m_capacityAndFlags);
  return v89;
}kMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      arr.m_data,
      4 * arr.m_capacityAndFlags);
  return v89;
}

// File Line: 907
// RVA: 0xBAEFE0
void __fastcall hkaNURBS::GlobalCurveApproxErrBnd(int m, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q, int p, float E, int *n, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P)
{
  int v7; // er9
  int v8; // esi
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v9; // rdi
  int v10; // ebx
  int v11; // ebp
  float *v12; // rcx
  int v13; // eax
  hkArray<float,hkContainerHeapAllocator> ub; // [rsp+50h] [rbp-28h]
  int v15; // [rsp+80h] [rbp+8h]

  v7 = m + 1;
  ub.m_data = 0i64;
  v8 = p;
  v9 = Q;
  v10 = m;
  ub.m_size = 0;
  ub.m_capacityAndFlags = 2147483648;
  v11 = m + 1;
  if ( m == -1 )
  {
    v12 = 0i64;
  }
  else
  {
    v15 = 4 * v7;
    v12 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v15);
    v7 = v15 / 4;
  }
  v13 = 2147483648;
  ub.m_data = v12;
  if ( v7 )
    v13 = v7;
  ub.m_size = v11;
  ub.m_capacityAndFlags = v13;
  hkaNURBS::ChordLengthParameterization(v10, v9, &ub);
  hkaNURBS::GlobalCurveApproxErrBnd(v10, v9, &ub, (hkBool)1, v8, E, n, U, P);
  ub.m_size = 0;
  if ( ub.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      ub.m_data,
      4 * ub.m_capacityAndFlags);
}

// File Line: 930
// RVA: 0xBAF130
void __fastcall hkaNURBS::GlobalCurveApproxErrBnd(int m, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q, hkArray<float,hkContainerHeapAllocator> *ub, int p, float E, int *n, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P)
{
  int v8; // eax
  signed __int64 v9; // rsi
  int v10; // ebx
  int v11; // ebp
  hkArray<float,hkContainerHeapAllocator> *v12; // r14
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v13; // r15
  int v14; // er12
  float *v15; // rdi
  float *v16; // r9
  signed __int64 v17; // rdx
  signed __int64 v18; // rcx
  signed __int64 v19; // r8
  unsigned __int64 v20; // r10
  int v21; // eax
  signed __int64 v22; // r9
  signed __int64 v23; // rcx
  signed __int64 v24; // rdx
  int v25; // eax
  hkArray<float,hkContainerHeapAllocator> uba; // [rsp+50h] [rbp-38h]
  int v27; // [rsp+A0h] [rbp+18h]

  v8 = ub->m_size;
  v9 = 0i64;
  v10 = 2147483648;
  uba.m_data = 0i64;
  v11 = p;
  v12 = ub;
  v13 = Q;
  v14 = m;
  v15 = 0i64;
  uba.m_capacityAndFlags = 2147483648;
  if ( v8 > 0 )
  {
    v27 = 4 * v8;
    v15 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v27);
    uba.m_data = v15;
    v10 = v27 / 4;
    uba.m_capacityAndFlags = v27 / 4;
  }
  v16 = v12->m_data;
  uba.m_size = v12->m_size;
  v17 = uba.m_size;
  if ( uba.m_size >= 4i64 )
  {
    v18 = (signed __int64)(v15 + 1);
    v19 = (char *)v16 - (char *)v15;
    v20 = ((unsigned __int64)(uba.m_size - 4i64) >> 2) + 1;
    v9 = 4 * v20;
    do
    {
      v21 = *(_DWORD *)(v19 + v18 - 4);
      v18 += 16i64;
      *(_DWORD *)(v18 - 20) = v21;
      *(_DWORD *)(v18 - 16) = *(_DWORD *)(v19 + v18 - 16);
      *(_DWORD *)(v18 - 12) = *(_DWORD *)(v19 + v18 - 12);
      *(_DWORD *)(v18 - 8) = *(_DWORD *)(v19 + v18 - 8);
      --v20;
    }
    while ( v20 );
  }
  if ( v9 < v17 )
  {
    v22 = (char *)v16 - (char *)v15;
    v23 = (signed __int64)&v15[v9];
    v24 = v17 - v9;
    do
    {
      v25 = *(_DWORD *)(v23 + v22);
      v23 += 4i64;
      *(_DWORD *)(v23 - 4) = v25;
      --v24;
    }
    while ( v24 );
  }
  hkaNURBS::GlobalCurveApproxErrBnd(v14, v13, &uba, 0, v11, E, n, U, P);
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v15,
      4 * v10);
}

// File Line: 950
// RVA: 0xBAF2C0
void __fastcall hkaNURBS::GlobalCurveApproxErrBnd(int m, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q, hkArray<float,hkContainerHeapAllocator> *ub, hkBool project, int p, float E, int *n, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P)
{
  int *v9; // r12
  hkArray<float,hkContainerHeapAllocator> *v10; // r15
  int v11; // edi
  int v12; // eax
  hkArray<float,hkContainerHeapAllocator> *v13; // rbp
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v14; // r13
  int v15; // ebx
  int v16; // eax
  int v17; // er9
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v18; // r14
  int v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // er9
  __int64 v23; // rax
  hkaNURBS::Point *v24; // rdi
  __int64 v25; // rbx
  float *v26; // rdi
  signed __int64 v27; // rdx
  __int64 v28; // rbx
  __int64 v29; // rsi
  signed __int64 v30; // rdi
  int v31; // eax
  hkaNURBS::Point *v32; // rdx
  int v33; // eax
  float *v34; // r9
  int v35; // esi
  __int64 v36; // rcx
  float *v37; // rdi
  int v38; // er13
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q_JUNK; // rdi
  int v40; // esi
  float errorBound; // xmm7_4
  int v42; // eax
  int v43; // esi
  int v44; // eax
  int v45; // eax
  int v46; // er9
  __int64 v47; // rax
  hkaNURBS::Point *v48; // rdi
  __int64 v49; // rbx
  hkArray<float,hkContainerHeapAllocator> *v50; // ST38_8
  int v51; // ebp
  int v52; // esi
  int v53; // eax
  int v54; // eax
  int v55; // er9
  __int64 v56; // rax
  hkaNURBS::Point *v57; // rdi
  __int64 v58; // rbx
  bool v59; // zf
  bool v60; // sf
  unsigned __int8 v61; // of
  hkResult result; // [rsp+70h] [rbp-A8h]
  int v63; // [rsp+74h] [rbp-A4h]
  float *v64; // [rsp+78h] [rbp-A0h]
  hkArray<float,hkContainerHeapAllocator> e; // [rsp+80h] [rbp-98h]
  int v66; // [rsp+120h] [rbp+8h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Qa; // [rsp+128h] [rbp+10h]
  hkArray<float,hkContainerHeapAllocator> *v68; // [rsp+130h] [rbp+18h]
  char v69; // [rsp+138h] [rbp+20h]

  v69 = project.m_bool;
  v68 = ub;
  Qa = Q;
  v66 = m;
  v9 = n;
  v10 = U;
  *n = m;
  v11 = m + 3;
  v12 = v10->m_capacityAndFlags & 0x3FFFFFFF;
  v13 = ub;
  v14 = Q;
  v15 = m;
  if ( v12 < m + 3 )
  {
    v16 = 2 * v12;
    v17 = m + 3;
    if ( v11 < v16 )
      v17 = v16;
    hkArrayUtil::_reserve((hkResult *)&n, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, v17, 4);
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
    hkArrayUtil::_reserve((hkResult *)&n, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v18, v22, 16);
  }
  v23 = v18->m_size;
  v24 = &v18->m_data[v23];
  if ( v19 - (signed int)v23 > 0 )
  {
    v25 = (unsigned int)(v19 - v23);
    do
    {
      if ( v24 )
        hkaNURBS::Point::Point(v24, 0.0, 0.0, 0.0, 0.0);
      ++v24;
      --v25;
    }
    while ( v25 );
    v15 = v66;
  }
  v18->m_size = v19;
  v26 = v13->m_data;
  *v10->m_data = *v13->m_data;
  v10->m_data[v15 + 2] = v26[v15];
  if ( v15 >= 0 )
  {
    v27 = 0i64;
    v28 = 0i64;
    v29 = v66 + 1;
    do
    {
      v30 = v27 + 4;
      v31 = *(_DWORD *)((char *)v13->m_data + v27);
      v32 = v14->m_data;
      *(_DWORD *)((char *)v10->m_data + v30) = v31;
      hkaNURBS::Point::operator=(&v18->m_data[v28], &v32[v28]);
      ++v28;
      v27 = v30;
      --v29;
    }
    while ( v29 );
    v15 = v66;
  }
  v33 = v15 + 1;
  if ( v15 == -1 )
  {
    v34 = 0i64;
  }
  else
  {
    LODWORD(n) = 4 * v33;
    v34 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     (int *)&n);
    v33 = (signed int)n / 4;
  }
  v35 = 2147483648;
  v64 = v34;
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
      *v37 = 0.0;
      ++v37;
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
      v63 = v42;
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
        hkArrayUtil::_reserve(
          (hkResult *)&P,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v18,
          v46,
          16);
      }
      v47 = v18->m_size;
      v48 = &v18->m_data[v47];
      if ( v43 - (signed int)v47 > 0 )
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
        v15 = v66;
      }
      Q_JUNK = Qa;
      v50 = v68;
      v18->m_size = v43;
      v51 = v38 + 1;
      hkaNURBS::LeastSquaresFit((hkBool *)&n, *v9, v38 + 1, v18, v10, v15, Q_JUNK, v50, 0.0000099999997, errorBound);
      if ( !(_BYTE)n )
      {
        *v9 += -1 - hkaNURBS::DegreeLowerKnotVector(v10, v38 + *v9 + 1);
        v52 = *v9 + 1;
        v53 = v18->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v53 >= v52 )
        {
          result.m_enum = 0;
        }
        else
        {
          v54 = 2 * v53;
          v55 = *v9 + 1;
          if ( v52 < v54 )
            v55 = v54;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v18, v55, 16);
        }
        v56 = v18->m_size;
        v57 = &v18->m_data[v56];
        if ( v52 - (signed int)v56 > 0 )
        {
          v58 = (unsigned int)(v52 - v56);
          do
          {
            if ( v57 )
              hkaNURBS::Point::Point(v57, 0.0, 0.0, 0.0, 0.0);
            ++v57;
            --v58;
          }
          while ( v58 );
          v15 = v66;
        }
        v18->m_size = v52;
        hkaNURBS::DegreeElevateCurve(v9, v38, v10, v18, 1);
        Q_JUNK = Qa;
      }
      hkaNURBS::UpdateFit(v15, Q_JUNK, *v9, v51, v10, v18, &e, v68, 100, 10, 0.000001, 0.000001, (hkBool)v69);
      v40 = p;
      ++v38;
      v61 = __OFSUB__(v51, p);
      v59 = v51 == p;
      v60 = v51 - p < 0;
      v13 = v68;
      if ( !((unsigned __int8)(v60 ^ v61) | v59) )
      {
        v42 = v63;
        break;
      }
    }
    if ( v42 )
    {
      hkaNURBS::LeastSquaresFit((hkBool *)&v66, *v9, v40, v18, v10, v15, Q_JUNK, v13, 0.0000099999997, errorBound);
      hkaNURBS::UpdateFit(v15, Q_JUNK, *v9, v40, v10, v18, &e, v13, 100, 10, 0.000001, 0.000001, (hkBool)v69);
      hkaNURBS::RemoveKnotsBoundCurve(v9, v40, v10, v18, v15, v13, &e, errorBound, Q_JUNK);
    }
    v34 = v64;
    v35 = (signed int)U;
  }
  if ( v35 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v34,
      4 * v35);
}

// File Line: 1055
// RVA: 0xBB30E0
__int64 __fastcall hkaNURBS::Find(float val, hkArray<float,hkContainerHeapAllocator> *arr, int m)
{
  float *v3; // r10
  int v4; // er9
  int v5; // edx

  v3 = arr->m_data;
  v4 = 0;
  v5 = m / 2;
  if ( val > v3[m] )
    return (unsigned int)(m + 1);
  if ( val <= *v3 )
    return 0i64;
  if ( v5 )
  {
    do
    {
      if ( val > v3[v5] )
        v4 = v5;
      else
        m = v5;
      v5 = (m + v4) / 2;
    }
    while ( v4 != v5 );
  }
  return (unsigned int)m;
}

// File Line: 1080
// RVA: 0xBB1ED0
float __usercall hkaNURBS::Distance3D@<xmm0>(hkaNURBS::Point *a@<rcx>, hkaNURBS::Point *b@<rdx>, float a3@<xmm0>)
{
  hkaNURBS::Point *v3; // rax
  hkaNURBS::Point result; // [rsp+20h] [rbp-18h]

  v3 = hkaNURBS::Point::operator-(b, &result, a);
  return hkaNURBS::Point::mag(v3, a3);
}

// File Line: 1090
// RVA: 0xBB1F00
__int64 __fastcall hkaNURBS::Multiplicity(int i, int m, hkArray<float,hkContainerHeapAllocator> *U)
{
  unsigned int v3; // er11
  float *v4; // r10
  int v5; // eax
  float v6; // xmm0_4
  int v7; // edx
  signed int v8; // er9
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
  v10 = &U->m_data[i - 1i64];
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
void __fastcall hkaNURBS::ComputeBounds(int n, int p, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, hkArray<float,hkContainerHeapAllocator> *B, int lo, int hi)
{
  signed __int64 r; // rsi
  int v8; // er14
  hkArray<float,hkContainerHeapAllocator> *v9; // rbx
  hkArray<float,hkContainerHeapAllocator> *v10; // r15
  int v11; // er13
  int v12; // er12
  float *v13; // rdi
  signed __int64 i; // rcx
  signed __int64 v15; // rbp
  float *v16; // rdi
  float *v17; // rbx
  int s; // eax
  int na; // [rsp+80h] [rbp+8h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Pa; // [rsp+98h] [rbp+20h]

  Pa = P;
  na = n;
  r = lo;
  v8 = hi;
  v9 = B;
  v10 = U;
  v11 = p;
  v12 = n + p;
  if ( lo <= hi )
  {
    v13 = &B->m_data[lo];
    for ( i = hi - (signed __int64)lo + 1; i; --i )
    {
      *v13 = 3.40282e38;
      ++v13;
    }
    if ( (signed int)r <= v8 )
    {
      v15 = r;
      do
      {
        if ( hkaNURBS::IsUnique((hkBool *)&lo, r, v10, v12 + 1)->m_bool )
        {
          v16 = v10->m_data;
          v17 = v9->m_data;
          s = hkaNURBS::Multiplicity(r, v12 + 1, v10);
          v17[v15] = hkaNURBS::GetRemovalBoundCurve(na, v11, v10, Pa, v16[v15], r, s);
        }
        v9 = B;
        LODWORD(r) = r + 1;
        ++v15;
      }
      while ( (signed int)r <= v8 );
    }
  }
}

// File Line: 1135
// RVA: 0xBB30A0
__int64 __fastcall hkaNURBS::UniqueKnotCount(hkArray<float,hkContainerHeapAllocator> *U, __int64 m)
{
  int v2; // er8
  float *v3; // rcx
  __int64 v4; // rax

  v2 = 0;
  if ( (signed int)m > 0 )
  {
    v3 = U->m_data;
    v4 = 0i64;
    m = (signed int)m;
    do
    {
      if ( v3[v4 + 1] != v3[v4] )
        ++v2;
      ++v4;
    }
    while ( v4 < m );
  }
  return (unsigned int)(v2 + 1);
}

// File Line: 1152
// RVA: 0xBB4270
__int64 __fastcall hkaNURBS::UniqueKnot(int i, hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  int v3; // edi
  hkArray<float,hkContainerHeapAllocator> *v4; // rsi
  unsigned int v5; // ebx
  hkBool result; // [rsp+30h] [rbp+8h]

  v3 = m;
  v4 = U;
  v5 = i;
  if ( !hkaNURBS::IsUnique(&result, i, U, m)->m_bool )
  {
    do
      ++v5;
    while ( !hkaNURBS::IsUnique(&result, v5, v4, v3)->m_bool );
  }
  return v5;
}

// File Line: 1166
// RVA: 0xBB42E0
void __fastcall hkaNURBS::Remove(int i, hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  float *v3; // rax
  int v4; // er9
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
      v6 = *((_DWORD *)v3 + 1);
      ++v3;
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
  signed __int64 v2; // rsi
  hkArray<float,hkContainerHeapAllocator> *v3; // rbx
  int v4; // eax
  int v5; // ebp
  int v6; // edx
  int v7; // er14
  int v8; // edi
  int v9; // edx
  int v10; // er9
  signed __int64 v11; // r9
  signed __int64 v12; // rdx
  signed __int64 v13; // r8
  unsigned __int64 v14; // r10
  float v15; // xmm0_4
  signed __int64 v16; // rdx
  float v17; // xmm0_4
  signed __int64 v18; // rdx
  float v19; // xmm0_4
  signed __int64 v20; // rdx
  float v21; // xmm0_4
  signed __int64 v22; // rdx
  float v23; // xmm0_4
  hkResult result; // [rsp+58h] [rbp+10h]

  v2 = m;
  v3 = U;
  v4 = hkaNURBS::UniqueKnotCount(U, (unsigned int)m);
  v5 = v4 + v2;
  v6 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = v4;
  v8 = v4 + v2 + 1;
  if ( v6 < v8 )
  {
    v9 = 2 * v6;
    v10 = v4 + v2 + 1;
    if ( v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v10, 4);
  }
  v3->m_size = v8;
  v11 = v2;
  v12 = v5;
  if ( v2 >= 4 )
  {
    v13 = 4 * v2 - 8;
    v14 = ((unsigned __int64)(v2 - 4) >> 2) + 1;
    v11 = v2 - 4 * v14;
    do
    {
      v15 = *(float *)((char *)v3->m_data + v13 + 8);
      if ( v15 != *(float *)((char *)v3->m_data + v13 + 4) )
        v3->m_data[v12--] = v15;
      v16 = v12 - 1;
      v3->m_data[v16 + 1] = *(float *)((char *)v3->m_data + v13 + 8);
      v17 = *(float *)((char *)v3->m_data + v13 + 4);
      if ( v17 != *(float *)((char *)v3->m_data + v13) )
        v3->m_data[v16--] = v17;
      v18 = v16 - 1;
      v3->m_data[v18 + 1] = *(float *)((char *)v3->m_data + v13 + 4);
      v19 = *(float *)((char *)v3->m_data + v13);
      if ( v19 != *(float *)((char *)v3->m_data + v13 - 4) )
        v3->m_data[v18--] = v19;
      v20 = v18 - 1;
      v3->m_data[v20 + 1] = *(float *)((char *)v3->m_data + v13);
      v21 = *(float *)((char *)v3->m_data + v13 - 4);
      if ( v21 != *(float *)((char *)v3->m_data + v13 - 8) )
        v3->m_data[v20--] = v21;
      v12 = v20 - 1;
      v13 -= 16i64;
      v3->m_data[v12 + 1] = *(float *)((char *)v3->m_data + v13 + 12);
      --v14;
    }
    while ( v14 );
  }
  if ( v11 > 0 )
  {
    v22 = v12;
    do
    {
      v23 = v3->m_data[v11];
      if ( v23 != v3->m_data[v11 - 1] )
      {
        v3->m_data[v22] = v23;
        --v22;
      }
      --v11;
      --v22;
      v3->m_data[v22 + 1] = v3->m_data[v11 + 1];
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
  int v3; // ebp
  hkArray<float,hkContainerHeapAllocator> *v4; // rdi
  signed __int64 v5; // r9
  signed __int64 v6; // rax
  signed __int64 v7; // r8
  unsigned __int64 v8; // r10
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  signed __int64 v13; // rcx
  float v14; // xmm0_4
  int v15; // esi
  int v16; // eax
  int v17; // eax
  int v18; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = 0;
  v3 = m;
  v4 = U;
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
      v14 = v4->m_data[v5];
      if ( v14 == v4->m_data[v5 + 1] )
      {
        v4->m_data[v13] = v14;
        ++v2;
        ++v13;
      }
      ++v5;
    }
    while ( v5 < m );
  }
  v15 = v2 + 1;
  v4->m_data[v2] = v4->m_data[m];
  v16 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v2 + 1 )
  {
    v17 = 2 * v16;
    v18 = v2 + 1;
    if ( v15 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v18, 4);
  }
  v4->m_size = v15;
  return (unsigned int)(v3 - v2 - 1);
}

// File Line: 1238
// RVA: 0xBB4330
void __fastcall hkaNURBS::RemoveSubtractOne(int i, hkArray<int,hkContainerHeapAllocator> *U, int m)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // r10
  signed __int64 v4; // rax
  int *v5; // r9
  int v6; // edx
  __int64 v7; // rdx
  int v8; // ecx

  --U->m_size;
  v3 = U;
  v4 = i;
  v5 = &U->m_data[i];
  v6 = 4 * (U->m_size - i);
  if ( v6 > 0 )
  {
    v7 = ((unsigned int)(v6 - 1) >> 2) + 1;
    do
    {
      v8 = v5[1];
      ++v5;
      *(v5 - 1) = v8;
      --v7;
    }
    while ( v7 );
  }
  for ( ; v4 < m; --v3->m_data[v4 - 1] )
    ++v4;
}

// File Line: 1252
// RVA: 0xBB4710
hkBool *__fastcall hkaNURBS::IsUnique(hkBool *result, int i, hkArray<float,hkContainerHeapAllocator> *U, int m)
{
  hkBool *v4; // rax

  if ( i == m || U->m_data[i + 1] != U->m_data[i] )
  {
    result->m_bool = 1;
    v4 = result;
  }
  else
  {
    result->m_bool = 0;
    v4 = result;
  }
  return v4;
}

// File Line: 1264
// RVA: 0xBB4A30
signed __int64 __fastcall hkaNURBS::MinIndex(hkArray<float,hkContainerHeapAllocator> *arr, int len)
{
  int v2; // er10
  float *v4; // rbx
  signed int v5; // ecx
  unsigned int v6; // er8
  signed __int64 v7; // rdi
  float v8; // xmm0_4
  int v9; // er11
  signed int v10; // er9
  float *v11; // rdx
  float *v12; // rdx

  v2 = len;
  if ( len <= 0 )
    return 0xFFFFFFFFi64;
  v4 = arr->m_data;
  v5 = 1;
  v6 = 0;
  v7 = 1i64;
  v8 = *v4;
  if ( len > 1 )
  {
    if ( len - 1 >= 4 )
    {
      v9 = len - 3;
      v10 = 3;
      v11 = v4 + 3;
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
    if ( v5 < v2 )
    {
      v12 = &v4[v7];
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
      while ( v5 < v2 );
    }
  }
  return v6;
}

// File Line: 1288
// RVA: 0xBB4B20
signed __int64 __fastcall hkaNURBS::MaxIndex(hkArray<float,hkContainerHeapAllocator> *arr, int len)
{
  int v2; // er10
  float *v4; // rbx
  signed int v5; // ecx
  unsigned int v6; // er8
  signed __int64 v7; // rdi
  float v8; // xmm0_4
  int v9; // er11
  signed int v10; // er9
  float *v11; // rdx
  float *v12; // rdx

  v2 = len;
  if ( len <= 0 )
    return 0xFFFFFFFFi64;
  v4 = arr->m_data;
  v5 = 1;
  v6 = 0;
  v7 = 1i64;
  v8 = *v4;
  if ( len > 1 )
  {
    if ( len - 1 >= 4 )
    {
      v9 = len - 3;
      v10 = 3;
      v11 = v4 + 3;
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
    if ( v5 < v2 )
    {
      v12 = &v4[v7];
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
      while ( v5 < v2 );
    }
  }
  return v6;
}

// File Line: 1317
// RVA: 0xBB3FC0
hkBool *__fastcall hkaNURBS::IsWellPosed(hkBool *result, int n, int p, hkArray<float,hkContainerHeapAllocator> *U, int mb, hkArray<float,hkContainerHeapAllocator> *ub, float tol)
{
  __int64 v7; // rsi
  __int64 v8; // rbx
  int v9; // er15
  int v10; // eax
  hkArray<float,hkContainerHeapAllocator> *v11; // r13
  unsigned __int64 v12; // rdi
  void *v13; // rbp
  signed int v14; // er14
  __int64 v15; // r12
  __int64 v16; // rdi
  int v17; // er14
  hkArray<float,hkContainerHeapAllocator> *v18; // rbx
  float v19; // xmm7_4
  float v20; // xmm6_4
  int v21; // eax
  __int64 v22; // rcx
  float v23; // xmm0_4
  int v24; // eax
  __int64 v25; // rdi
  hkBool *v26; // rdi
  signed int v28; // [rsp+20h] [rbp-68h]
  hkBool *v29; // [rsp+90h] [rbp+8h]
  int na; // [rsp+98h] [rbp+10h]
  int v31; // [rsp+A0h] [rbp+18h]

  na = n;
  v29 = result;
  v7 = p;
  v8 = 0i64;
  v9 = p + n + 1;
  v10 = n + 1;
  v11 = U;
  v12 = n + 1;
  if ( n == -1 )
  {
    v13 = 0i64;
  }
  else
  {
    v31 = n + 1;
    v13 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            &v31);
    v10 = v31;
  }
  v14 = 2147483648;
  if ( v10 )
    v14 = v10;
  v28 = v14;
  if ( (signed int)v12 > 0 )
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
      v21 = hkaNURBS::FindSpan(v17, v7, v18->m_data[v16], v11);
      v22 = v21;
      v23 = v19 + v11->m_data[v21];
      if ( v21 == v9 )
        v24 = v9;
      else
        v24 = v21 + 1;
      if ( v20 >= v23 && v20 <= (float)(v11->m_data[v24] - v19) )
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
    v26 = v29;
    v29->m_bool = 1;
  }
  else
  {
    while ( !hkaNURBS::IsUnique((hkBool *)&na, v7, v11, v9)->m_bool || *((_BYTE *)v13 + v8) )
    {
      ++v8;
      LODWORD(v7) = v7 + 1;
      if ( v8 > v25 )
        goto LABEL_22;
    }
    v26 = v29;
    v29->m_bool = 0;
  }
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v13,
      v14 & 0x3FFFFFFF);
  return v26;
}

// File Line: 1369
// RVA: 0xBB37C0
hkBool *__fastcall hkaNURBS::LeastSquaresFit(hkBool *result, int n, int p, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, hkArray<float,hkContainerHeapAllocator> *U, int m, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q, hkArray<float,hkContainerHeapAllocator> *ub, float numericalTolerance, float errorBound)
{
  signed __int64 v10; // rbx
  int v11; // er15
  signed int v12; // er14
  hkBool *v13; // rax
  signed int v14; // er13
  __int64 v15; // rsi
  signed __int64 v16; // rdi
  int v17; // esi
  __int64 v18; // rax
  int v19; // ebx
  hkArray<float,hkContainerHeapAllocator> *v20; // r13
  float v21; // xmm0_4
  int v22; // eax
  __int64 v23; // rdi
  hkaNURBS::Point *v24; // rcx
  signed int v25; // er12
  hkaNURBS::Point *v26; // rbx
  hkaNURBS::Point *v27; // rdi
  hkaNURBS::Point *v28; // rax
  hkaNURBS::Point *v29; // rax
  hkArray<float,hkContainerHeapAllocator> *v30; // r12
  hkArray<float,hkContainerHeapAllocator> *v31; // r13
  int v32; // ecx
  signed __int64 v33; // rax
  float *v34; // rdi
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
  int v48; // er14
  float *v49; // rbx
  __int64 v50; // r12
  float v51; // xmm0_4
  hkaNURBS::Point *v52; // rax
  signed int v53; // edi
  float *v54; // rbx
  float *v55; // rax
  float v56; // xmm8_4
  hkBool *v57; // rbx
  int v58; // ebx
  int v59; // eax
  int v60; // esi
  int v61; // eax
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v62; // r14
  int v63; // edi
  int v64; // ebx
  hkaNURBS::Point *v65; // r12
  float v66; // xmm6_4
  float *v67; // rax
  int v68; // ebx
  hkaNURBS::Point *v69; // rcx
  int v70; // eax
  signed __int64 v71; // rsi
  int v72; // er9
  int v73; // edx
  hkaNURBS::Point *v74; // rbx
  __int64 v75; // rdi
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v76; // rbx
  hkaNURBS::Point *v77; // rdx
  signed int v78; // edi
  float *v79; // rbx
  float *v80; // rax
  hkaNURBS::Point *array; // [rsp+50h] [rbp-B0h]
  int v82; // [rsp+58h] [rbp-A8h]
  int v83; // [rsp+5Ch] [rbp-A4h]
  hkaNURBS::Point *v84; // [rsp+60h] [rbp-A0h]
  int v85; // [rsp+68h] [rbp-98h]
  hkBool v86; // [rsp+6Ch] [rbp-94h]
  __int64 v87; // [rsp+70h] [rbp-90h]
  int v88[2]; // [rsp+78h] [rbp-88h]
  int v89; // [rsp+80h] [rbp-80h]
  hkaMatrix<float> X; // [rsp+88h] [rbp-78h]
  hkaNURBS::Point v91; // [rsp+A0h] [rbp-60h]
  hkaMatrix<float> B; // [rsp+B0h] [rbp-50h]
  __int64 v93; // [rsp+C8h] [rbp-38h]
  hkaNURBS::Point v94; // [rsp+D0h] [rbp-30h]
  hkaSparseLSQMatrix<float> A; // [rsp+E0h] [rbp-20h]
  hkaNURBS::Point v96; // [rsp+118h] [rbp+18h]
  hkaNURBS::Point v97; // [rsp+128h] [rbp+28h]
  hkaNURBS::Point resulta; // [rsp+138h] [rbp+38h]
  hkBool *v99; // [rsp+1D0h] [rbp+D0h]
  int v100; // [rsp+1D8h] [rbp+D8h]
  int v101; // [rsp+1E0h] [rbp+E0h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v102; // [rsp+1E8h] [rbp+E8h]

  v102 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)P;
  v101 = p;
  v100 = n;
  v99 = result;
  v10 = m;
  v11 = p;
  v12 = n;
  v13 = result;
  if ( n <= m )
  {
    hkaSparseLSQMatrix<float>::hkaSparseLSQMatrix<float>(&A, m - 1, n - 1);
    v14 = 1;
    v15 = v10;
    v87 = v10;
    v16 = 1i64;
    if ( v10 > 1 )
    {
      v17 = 0;
      v18 = v10;
      do
      {
        v19 = 1;
        if ( v12 > 1 )
        {
          v20 = U;
          do
          {
            v21 = hkaNURBS::OneBasisFun(v11, v12 + v11 + 1, v20, v19, ub->m_data[v16]);
            hkaSparseLSQMatrix<float>::Set(&A, v17, v19++ - 1, v21);
          }
          while ( v19 < v12 );
          v18 = v87;
          v14 = 1;
        }
        ++v16;
        ++v17;
      }
      while ( v16 < v18 );
      LODWORD(v10) = m;
      v15 = v87;
    }
    *(_QWORD *)v88 = 4i64;
    hkaMatrix<float>::hkaMatrix<float>(&B, v12 - 1, 4, 0.0);
    v22 = v10 + 1;
    v23 = (unsigned int)(v10 + 1);
    if ( (_DWORD)v10 == -1 )
    {
      v24 = 0i64;
    }
    else
    {
      v89 = 16 * v22;
      v24 = (hkaNURBS::Point *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                 &v89);
      v22 = v89 / 16;
    }
    v25 = 2147483648;
    v84 = v24;
    if ( v22 )
      v25 = v22;
    v85 = v25;
    if ( (signed int)v23 > 0 )
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
    v87 = 16 * v15;
    hkaNURBS::Point::Point(&v91, 0.0, 0.0, 0.0, 0.0);
    v27 = v84;
    v29 = hkaNURBS::Point::operator=(&v84[v15], v28);
    hkaNURBS::Point::operator=(v84, v29);
    if ( (signed int)v10 > 1 )
    {
      v30 = U;
      v31 = ub;
      v32 = v12 + v11 + 1;
      v93 = 16i64;
      *(_QWORD *)v91.point = (unsigned int)(v10 - 1);
      v33 = 4i64;
      do
      {
        v34 = v31->m_data;
        v35 = Q->m_data;
        v36 = (hkaNURBS::Point *)((char *)Q->m_data + v87);
        v37 = hkaNURBS::OneBasisFun(v11, v32, v30, v12, *(float *)((char *)v31->m_data + v33));
        v38 = operator*(&resulta, v37, v36);
        v39 = hkaNURBS::OneBasisFun(v11, v12 + v11 + 1, v30, 0, *(float *)((char *)v34 + *(_QWORD *)v88));
        v40 = operator*(&v96, v39, v35);
        v41 = v93;
        v42 = hkaNURBS::Point::operator-((hkaNURBS::Point *)((char *)v35 + v93), &v97, v40);
        v43 = hkaNURBS::Point::operator-(v42, &v94, v38);
        hkaNURBS::Point::operator=((hkaNURBS::Point *)((char *)v84 + v41), v43);
        v33 = *(_QWORD *)v88 + 4i64;
        v44 = (*(_QWORD *)v91.point)-- == 1i64;
        *(_QWORD *)v88 += 4i64;
        v93 = v41 + 16;
        v32 = v11 + 1 + v12;
      }
      while ( !v44 );
      v25 = v85;
      v27 = v84;
      LODWORD(v10) = m;
      v14 = 1;
    }
    v45 = 1;
    if ( v12 > 1 )
    {
      v46 = U;
      while ( 1 )
      {
        hkaNURBS::Point::Point(&v91, 0.0, 0.0, 0.0, 0.0);
        if ( (signed int)v10 > 1 )
        {
          v47 = v27 + 1;
          v88[0] = v12 + v11 + 1;
          v48 = v12 + v11 + 1;
          v49 = ub->m_data + 1;
          v50 = (unsigned int)(m - 1);
          do
          {
            v51 = hkaNURBS::OneBasisFun(v11, v48, v46, v45, *v49);
            v52 = operator*(&v94, v51, v47);
            hkaNURBS::Point::operator+=(&v91, v52);
            ++v47;
            ++v49;
            --v50;
          }
          while ( v50 );
          v12 = v100;
        }
        v53 = 0;
        do
        {
          v54 = hkaNURBS::Point::operator[](&v91, v53);
          v55 = hkaMatrix<float>::operator()(&B, v45 - 1, v53++);
          *v55 = *v54;
        }
        while ( v53 < 4 );
        v27 = v84;
        if ( ++v45 >= v12 )
          break;
        LODWORD(v10) = m;
      }
      v25 = v85;
      v14 = 1;
    }
    v56 = numericalTolerance;
    if ( hkaNURBS::IsWellPosed(&v86, v12, v11, U, ub->m_size - 1, ub, numericalTolerance)->m_bool )
    {
      v58 = hkaMatrix<float>::Width(&B);
      v59 = hkaMatrix<float>::Height(&B);
      hkaMatrix<float>::hkaMatrix<float>(&X, v59, v58);
      v60 = 0;
      if ( (signed int)hkaMatrix<float>::Height(&X) > 0 )
      {
        v61 = hkaMatrix<float>::Width(&X);
        v62 = Q;
        v63 = v61;
        do
        {
          v64 = 0;
          if ( v63 > 0 )
          {
            v65 = &v62->m_data[v60 + 1];
            do
            {
              v66 = hkaNURBS::Point::operator[](v65, v64);
              v67 = hkaMatrix<float>::operator()(&X, v60, v64++);
              *v67 = v66;
              v63 = hkaMatrix<float>::Width(&X);
            }
            while ( v64 < v63 );
          }
          ++v60;
        }
        while ( v60 < (signed int)hkaMatrix<float>::Height(&X) );
        v12 = v100;
        v11 = v101;
        v25 = v85;
      }
      hkaCGSolver<float>::Solve((hkBool *)&v100, &A, &X, &B, 50, v56);
      if ( (_BYTE)v100 )
      {
        v68 = v12 + 1;
        v69 = 0i64;
        v70 = 0;
        v83 = 2147483648;
        v71 = 1i64;
        array = 0i64;
        v82 = 0;
        if ( v12 + 1 > 0 )
        {
          v72 = v12 + 1;
          if ( v68 < 0 )
            v72 = 0;
          hkArrayUtil::_reserve(
            (hkResult *)&v100,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &array,
            v72,
            16);
          v70 = v82;
          v69 = array;
        }
        v73 = v68 - v70;
        v74 = &v69[v70];
        if ( v73 > 0 )
        {
          v75 = (unsigned int)v73;
          do
          {
            if ( v74 )
              hkaNURBS::Point::Point(v74, 0.0, 0.0, 0.0, 0.0);
            ++v74;
            --v75;
          }
          while ( v75 );
          v69 = array;
        }
        v76 = Q;
        v77 = Q->m_data;
        v82 = v12 + 1;
        hkaNURBS::Point::operator=(v69, v77);
        hkaNURBS::Point::operator=(&array[v12], (hkaNURBS::Point *)((char *)v76->m_data + v87));
        if ( v12 > 1 )
        {
          do
          {
            v78 = 0;
            do
            {
              v79 = hkaMatrix<float>::operator()(&X, v14 - 1, v78);
              v80 = hkaNURBS::Point::operator[](&array[v71], v78++);
              *v80 = *v79;
            }
            while ( v78 < 4 );
            ++v14;
            ++v71;
          }
          while ( v14 < v12 );
          v25 = v85;
          v76 = Q;
        }
        if ( hkaNURBS::WithinTolerance(
               (hkBool *)&m,
               v12,
               v11,
               (hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *)&array,
               U,
               m,
               v76,
               ub,
               errorBound)->m_bool )
        {
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            v102,
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
          v57 = v99;
          v99->m_bool = 1;
        }
        else
        {
          v57 = v99;
          v99->m_bool = 0;
        }
        v82 = 0;
        if ( v83 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            16 * v83);
        v83 = 2147483648;
        array = 0i64;
      }
      else
      {
        v57 = v99;
        v99->m_bool = 0;
      }
      hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&X);
    }
    else
    {
      v57 = v99;
      v99->m_bool = 0;
    }
    if ( v25 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v84,
        16 * v25);
    hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&B);
    hkaSparseLSQMatrix<float>::~hkaSparseLSQMatrix<float>(&A);
    v13 = v57;
  }
  else
  {
    result->m_bool = 0;
  }
  return v13;
}

// File Line: 1521
// RVA: 0xBB4740
float __usercall hkaNURBS::ClosestPoint@<xmm0>(int n@<ecx>, int p@<edx>, hkArray<float,hkContainerHeapAllocator> *U@<r8>, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P@<r9>, float a5@<xmm0>, hkaNURBS::Point *Q, int d, int maxiter, float e1, float e2)
{
  float v10; // edi
  hkaNURBS::Point *v11; // r13
  int v12; // esi
  int v13; // er12
  hkArray<float,hkContainerHeapAllocator> *v14; // r14
  float v15; // xmm7_4
  int v16; // er15
  signed int v17; // ebx
  int v18; // eax
  float *v19; // rcx
  __int64 v20; // rax
  float v21; // xmm12_4
  float v22; // xmm10_4
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v23; // rsi
  float v24; // xmm8_4
  float v25; // xmm9_4
  int v26; // er13
  hkaNURBS::Point *v27; // rbx
  signed int v28; // edi
  bool v29; // di
  float v30; // xmm0_4
  bool v31; // bl
  float v32; // xmm8_4
  float v33; // xmm7_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  hkaNURBS::Point result; // [rsp+40h] [rbp-81h]
  hkaNURBS::Point CK; // [rsp+50h] [rbp-71h]
  hkaNURBS::Point v39; // [rsp+60h] [rbp-61h]
  hkaNURBS::Point v40; // [rsp+70h] [rbp-51h]
  __int64 v41; // [rsp+118h] [rbp+57h]
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v42; // [rsp+120h] [rbp+5Fh]
  hkaNURBS::Point *a; // [rsp+128h] [rbp+67h]
  float vars0; // [rsp+130h] [rbp+6Fh]
  void *retaddr; // [rsp+138h] [rbp+77h]
  float v46; // [rsp+140h] [rbp+7Fh]
  float v47; // [rsp+148h] [rbp+87h]

  v10 = vars0;
  v11 = a;
  v12 = 0;
  v13 = n;
  v14 = U;
  v15 = FLOAT_3_40282e38;
  v16 = p;
  v17 = 0;
  v18 = n + 1;
  v19 = U->m_data;
  v20 = p + v18;
  v41 = v20;
  v21 = *v19;
  v22 = *v19;
  if ( vars0 >= 0.0 )
  {
    v23 = v42;
    v24 = v19[v20] - v21;
    a5 = (float)SLODWORD(vars0);
    v25 = 1.0 / (float)SLODWORD(vars0);
    do
    {
      hkaNURBS::CurvePoint(&result, v13, v16, v14, v23, (float)((float)((float)v17 * v25) * v24) + v21);
      a5 = hkaNURBS::Point::Dist(&result, v11, a5);
      if ( a5 < v15 )
      {
        v15 = a5;
        v22 = (float)((float)((float)v17 * v25) * v24) + v21;
      }
      ++v17;
    }
    while ( v17 <= SLODWORD(v10) );
    v12 = 0;
  }
  v26 = (signed int)retaddr;
  if ( (signed int)retaddr <= 0 )
    return v22;
  do
  {
    v27 = &CK;
    v28 = 2;
    do
    {
      hkaNURBS::Point::Point(v27, 0.0, 0.0, 0.0, 0.0);
      ++v27;
      --v28;
    }
    while ( v28 >= 0 );
    hkaNURBS::CurveDerivs(v13, v16, v14, v42, v22, 2, &CK);
    hkaNURBS::Point::operator-=(&CK, a);
    v29 = v46 >= hkaNURBS::Point::mag(&CK, a5);
    v30 = hkaNURBS::Point::Cos(&v39, &CK);
    v31 = v47 >= v30;
    if ( v29 && v47 >= v30 )
      break;
    vars0 = v21;
    v32 = v22;
    v33 = hkaNURBS::Point::Dot(&v39, &CK);
    v34 = hkaNURBS::Point::Dot(&v40, &CK);
    hkaNURBS::Point::mag2(&v39);
    v35 = fmaxf(v22 - (float)(v33 / (float)(v34 + v34)), vars0);
    vars0 = v14->m_data[v41];
    *(float *)&retaddr = v35;
    v22 = fminf(v35, vars0);
    vars0 = v22 - v32;
    if ( v29 )
      break;
    if ( v31 )
      break;
    a5 = hkaNURBS::Point::mag(&v39, v22 - v32) * COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v22 - v32)) >> 1);
    if ( a5 <= v46 )
      break;
    ++v12;
  }
  while ( v12 < v26 );
  return v22;
}

// File Line: 1606
// RVA: 0xBB4570
void __usercall hkaNURBS::UpdateFit(int m@<ecx>, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q@<rdx>, int n@<r8d>, int p@<r9d>, float a5@<xmm0>, hkArray<float,hkContainerHeapAllocator> *U, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, hkArray<float,hkContainerHeapAllocator> *e, hkArray<float,hkContainerHeapAllocator> *ub, int density, int maxiter, float e1, float e2, hkBool project)
{
  __int64 v14; // rbx
  int v15; // ebp
  int v16; // er14
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v17; // r15
  __int64 v18; // rdi
  float v19; // xmm6_4
  hkaNURBS::Point *v20; // rcx
  hkaNURBS::Point *v21; // rax
  bool v22; // zf
  __int64 v23; // [rsp+50h] [rbp-88h]
  hkaNURBS::Point result; // [rsp+58h] [rbp-80h]
  hkaNURBS::Point v25; // [rsp+68h] [rbp-70h]

  if ( m >= 0 )
  {
    v14 = 0i64;
    v15 = p;
    v16 = n;
    v17 = Q;
    v18 = 0i64;
    v23 = (unsigned int)(m + 1);
    do
    {
      if ( project.m_bool )
      {
        a5 = hkaNURBS::ClosestPoint(v16, v15, U, P, &v17->m_data[v18], density, maxiter, e1, e2);
        v19 = a5;
      }
      else
      {
        v19 = ub->m_data[v14];
      }
      hkaNURBS::CurvePoint(&result, v16, v15, U, P, v19);
      v20 = &v17->m_data[v18];
      ub->m_data[v14] = v19;
      v21 = hkaNURBS::Point::operator-(v20, &v25, &result);
      a5 = hkaNURBS::Point::mag(v21, a5);
      ++v14;
      ++v18;
      v22 = v23-- == 1;
      e->m_data[v14 - 1] = a5;
    }
    while ( !v22 );
  }
}

// File Line: 1660
// RVA: 0xBB3440
hkBool *__fastcall hkaNURBS::WithinTolerance(hkBool *result, int n, int p, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, hkArray<float,hkContainerHeapAllocator> *U, int m, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q, hkArray<float,hkContainerHeapAllocator> *ub, float E)
{
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v9; // r14
  int v10; // er15
  int v11; // er12
  hkBool *v12; // rsi
  signed __int64 v13; // rbp
  float *v14; // rdi
  hkaNURBS::Point *v15; // rbx
  float u; // xmm0_4
  hkaNURBS::Point v18; // [rsp+30h] [rbp-58h]
  hkaNURBS::Point resulta; // [rsp+40h] [rbp-48h]

  v9 = P;
  v10 = p;
  v11 = n;
  v12 = result;
  result->m_bool = 1;
  if ( m >= 0i64 )
  {
    v13 = m + 1i64;
    v14 = ub->m_data;
    v15 = Q->m_data;
    do
    {
      u = *v14;
      v18.point[0] = v15->point[0];
      v18.point[1] = v15->point[1];
      v18.point[2] = v15->point[2];
      v18.point[3] = v15->point[3];
      hkaNURBS::CurvePoint(&resulta, v11, v10, U, v9, u);
      if ( hkaNURBS::Point::Dist(&v18, &resulta, u) > (float)(E * 1.1) )
        v12->m_bool = 0;
      ++v15;
      ++v14;
      --v13;
    }
    while ( v13 );
  }
  return v12;
}

// File Line: 1695
// RVA: 0xBB3550
hkBool *__fastcall hkaNURBS::WithinTolerance(hkBool *result, int n, int p, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, hkArray<float,hkContainerHeapAllocator> *U, int m, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q, hkArray<float,hkContainerHeapAllocator> *ub, hkArray<float,hkContainerHeapAllocator> *E)
{
  signed __int64 v9; // rbx
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v10; // r12
  int v11; // er13
  hkBool *v12; // r14
  float *v13; // rsi
  hkaNURBS::Point *v14; // rdi
  signed __int64 v15; // r15
  float u; // xmm0_4
  hkaNURBS::Point v18; // [rsp+30h] [rbp-58h]
  hkaNURBS::Point resulta; // [rsp+40h] [rbp-48h]
  int v20; // [rsp+98h] [rbp+10h]

  v20 = n;
  v9 = 0i64;
  v10 = P;
  v11 = p;
  v12 = result;
  if ( m < 0i64 )
  {
LABEL_5:
    v12->m_bool = 1;
  }
  else
  {
    v13 = E->m_data;
    v14 = Q->m_data;
    v15 = (char *)ub->m_data - (char *)E->m_data;
    while ( 1 )
    {
      u = *(float *)((char *)v13 + v15);
      v18.point[0] = v14->point[0];
      v18.point[1] = v14->point[1];
      v18.point[2] = v14->point[2];
      v18.point[3] = v14->point[3];
      hkaNURBS::CurvePoint(&resulta, n, v11, U, v10, u);
      if ( hkaNURBS::Point::Dist(&v18, &resulta, u) > (float)(*v13 + 0.001) )
        break;
      n = v20;
      ++v9;
      ++v14;
      ++v13;
      if ( v9 > m )
        goto LABEL_5;
    }
    v12->m_bool = 0;
  }
  return v12;
}

// File Line: 1723
// RVA: 0xBB3670
hkBool *__fastcall hkaNURBS::WithinTolerance(hkBool *result, int n, int p, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *P, hkArray<float,hkContainerHeapAllocator> *U, int m, hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *Q, float E)
{
  int v8; // ebx
  hkArray<hkaNURBS::Point,hkContainerHeapAllocator> *v9; // r14
  int v10; // er15
  int v11; // er12
  hkBool *v12; // rsi
  __int64 v13; // rdi
  hkaNURBS::Point *v14; // rcx
  float v15; // xmm0_4
  hkaNURBS::Point Pa; // [rsp+50h] [rbp-68h]
  hkaNURBS::Point resulta; // [rsp+60h] [rbp-58h]

  v8 = 0;
  v9 = P;
  v10 = p;
  v11 = n;
  v12 = result;
  if ( m < 0 )
  {
LABEL_5:
    v12->m_bool = 1;
  }
  else
  {
    v13 = 0i64;
    while ( 1 )
    {
      v14 = Q->m_data;
      Pa.point[0] = Q->m_data[v13].point[0];
      Pa.point[1] = v14[v13].point[1];
      Pa.point[2] = v14[v13].point[2];
      Pa.point[3] = v14[v13].point[3];
      v15 = hkaNURBS::ClosestPoint(v11, v10, U, v9, &v14[v8], 100, 10, 0.000099999997, 0.000099999997);
      hkaNURBS::CurvePoint(&resulta, v11, v10, U, v9, v15);
      if ( hkaNURBS::Point::Dist(&Pa, &resulta, v15) > E )
        break;
      ++v8;
      ++v13;
      if ( v8 > m )
        goto LABEL_5;
    }
    v12->m_bool = 0;
  }
  return v12;
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
  this->point[0] = a->point[0];
  this->point[1] = a->point[1];
  this->point[2] = a->point[2];
  this->point[3] = a->point[3];
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
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator+(hkaNURBS::Point *this, hkaNURBS::Point *result, hkaNURBS::Point *a)
{
  hkaNURBS::Point *v3; // rbx
  hkaNURBS::Point *v4; // rax
  float v5; // ecx
  hkaNURBS::Point v7; // [rsp+20h] [rbp-18h]

  v3 = result;
  v7.point[0] = this->point[0];
  v7.point[1] = this->point[1];
  v7.point[2] = this->point[2];
  v7.point[3] = this->point[3];
  v4 = hkaNURBS::Point::operator+=(&v7, a);
  v3->point[0] = v4->point[0];
  v3->point[1] = v4->point[1];
  v5 = v4->point[2];
  *(float *)&v4 = v4->point[3];
  v3->point[2] = v5;
  LODWORD(v3->point[3]) = (_DWORD)v4;
  return v3;
}

// File Line: 1841
// RVA: 0xBAE590
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator-(hkaNURBS::Point *this, hkaNURBS::Point *result, hkaNURBS::Point *a)
{
  hkaNURBS::Point *v3; // rbx
  hkaNURBS::Point *v4; // rax
  float v5; // ecx
  hkaNURBS::Point v7; // [rsp+20h] [rbp-18h]

  v3 = result;
  v7.point[0] = this->point[0];
  v7.point[1] = this->point[1];
  v7.point[2] = this->point[2];
  v7.point[3] = this->point[3];
  v4 = hkaNURBS::Point::operator-=(&v7, a);
  v3->point[0] = v4->point[0];
  v3->point[1] = v4->point[1];
  v5 = v4->point[2];
  *(float *)&v4 = v4->point[3];
  v3->point[2] = v5;
  LODWORD(v3->point[3]) = (_DWORD)v4;
  return v3;
}

// File Line: 1848
// RVA: 0xBAE5F0
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator*(hkaNURBS::Point *this, hkaNURBS::Point *result, float d)
{
  hkaNURBS::Point *v3; // rbx
  hkaNURBS::Point *v4; // rax
  float v5; // ecx
  hkaNURBS::Point v7; // [rsp+20h] [rbp-18h]

  v3 = result;
  v7.point[0] = this->point[0];
  v7.point[1] = this->point[1];
  v7.point[2] = this->point[2];
  v7.point[3] = this->point[3];
  v4 = hkaNURBS::Point::operator*=(&v7, d);
  v3->point[0] = v4->point[0];
  v3->point[1] = v4->point[1];
  v5 = v4->point[2];
  *(float *)&v4 = v4->point[3];
  v3->point[2] = v5;
  LODWORD(v3->point[3]) = (_DWORD)v4;
  return v3;
}

// File Line: 1855
// RVA: 0xBAE650
hkaNURBS::Point *__fastcall hkaNURBS::Point::operator/(hkaNURBS::Point *this, hkaNURBS::Point *result, float d)
{
  hkaNURBS::Point *v3; // rbx
  hkaNURBS::Point *v4; // rax
  float v5; // ecx
  hkaNURBS::Point v7; // [rsp+20h] [rbp-18h]

  v3 = result;
  v7.point[0] = this->point[0];
  v7.point[1] = this->point[1];
  v7.point[2] = this->point[2];
  v7.point[3] = this->point[3];
  v4 = hkaNURBS::Point::operator=/(&v7, d);
  v3->point[0] = v4->point[0];
  v3->point[1] = v4->point[1];
  v5 = v4->point[2];
  *(float *)&v4 = v4->point[3];
  v3->point[2] = v5;
  LODWORD(v3->point[3]) = (_DWORD)v4;
  return v3;
}

// File Line: 1862
// RVA: 0xBB4C10
hkaNURBS::Point *__fastcall operator*(hkaNURBS::Point *result, float d, hkaNURBS::Point *p)
{
  hkaNURBS::Point *v3; // rbx

  v3 = result;
  hkaNURBS::Point::operator*(p, result, d);
  return v3;
}

// File Line: 1867
// RVA: 0xBB4C40
hkaNURBS::Point *__fastcall operator/(hkaNURBS::Point *result, float d, hkaNURBS::Point *p)
{
  hkaNURBS::Point *v3; // rbx

  v3 = result;
  hkaNURBS::Point::operator/(p, result, d);
  return v3;
}

// File Line: 1872
// RVA: 0xBAE6D0
void __fastcall hkaNURBS::Point::mag2(hkaNURBS::Point *this)
{
  hkaNURBS::Point::Dot(this, this);
}

// File Line: 1877
// RVA: 0xBAE6E0
float __usercall hkaNURBS::Point::mag@<xmm0>(hkaNURBS::Point *this@<rcx>, float a2@<xmm0>)
{
  hkaNURBS::Point::mag2(this);
  return fsqrt(a2);
}

// File Line: 1882
// RVA: 0xBAE700
hkaNURBS::Point *__fastcall hkaNURBS::Point::abs(hkaNURBS::Point *this, hkaNURBS::Point *result)
{
  hkaNURBS::Point *v2; // rbx

  v2 = result;
  hkaNURBS::Point::Point(
    result,
    COERCE_FLOAT((unsigned int)(2 * LODWORD(this->point[0])) >> 1),
    COERCE_FLOAT((unsigned int)(2 * LODWORD(this->point[1])) >> 1),
    COERCE_FLOAT((unsigned int)(2 * LODWORD(this->point[2])) >> 1),
    COERCE_FLOAT((unsigned int)(2 * LODWORD(this->point[3])) >> 1));
  return v2;
}

// File Line: 1887
// RVA: 0xBAE7A0
hkaNURBS::Point *__fastcall hkaNURBS::Point::floor(hkaNURBS::Point *this, hkaNURBS::Point *result)
{
  hkaNURBS::Point *v2; // rbx
  __m128i v3; // xmm12
  __m128 v4; // xmm9
  __m128i v5; // xmm11
  __m128 v6; // xmm5
  __m128 v7; // xmm3
  __m128i v8; // xmm8
  __m128 v9; // xmm10
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm6
  __m128 v13; // xmm13

  v2 = result;
  v3 = (__m128i)LODWORD(this->point[3]);
  v4 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v3, 1u), 1u));
  v5 = (__m128i)LODWORD(this->point[2]);
  v6 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v3, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v7 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v5, 1u), 1u));
  v8 = (__m128i)LODWORD(this->point[1]);
  v9 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v5, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v10 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v8, 1u), 1u));
  v11 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v8, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v12 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_sub_ps((__m128)LODWORD(this->point[0]), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23),
          *(__m128 *)two23);
  v13 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)LODWORD(this->point[0]), 1u), 1u));
  hkaNURBS::Point::Point(
    result,
    COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                          v13,
                                          _mm_add_ps(
                                            _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)LODWORD(this->point[0]), v12)),
                                            v12)) | v13.m128_i32[0] & LODWORD(this->point[0])),
    COERCE_FLOAT(v10.m128_i32[0] & v8.m128i_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                              v10,
                                                                              _mm_add_ps(
                                                                                _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v8, v11)),
                                                                                v11))),
    COERCE_FLOAT(v7.m128_i32[0] & v5.m128i_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                             v7,
                                                                             _mm_add_ps(
                                                                               _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v5, v9)),
                                                                               v9))),
    COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                          v4,
                                          _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v3, v6)), v6)) | v4.m128_i32[0] & v3.m128i_i32[0]));
  return v2;
}

// File Line: 1892
// RVA: 0xBAE990
hkaNURBS::Point *__fastcall hkaNURBS::Point::ceil(hkaNURBS::Point *this, hkaNURBS::Point *result)
{
  hkaNURBS::Point *v2; // rbx
  __m128i v3; // xmm12
  __m128 v4; // xmm5
  __m128i v5; // xmm11
  __m128 v6; // xmm6
  __m128 v7; // xmm3
  __m128i v8; // xmm10
  __m128 v9; // xmm9
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm7
  __m128 v13; // xmm13

  v2 = result;
  v3 = (__m128i)LODWORD(this->point[3]);
  v4 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v3, 1u), 1u));
  v5 = (__m128i)LODWORD(this->point[2]);
  v6 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v3, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v7 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v5, 1u), 1u));
  v8 = (__m128i)LODWORD(this->point[1]);
  v9 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v5, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v10 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v8, 1u), 1u));
  v11 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v8, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v12 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_sub_ps((__m128)LODWORD(this->point[0]), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23),
          *(__m128 *)two23);
  v13 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)LODWORD(this->point[0]), 1u), 1u));
  hkaNURBS::Point::Point(
    result,
    COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                          v13,
                                          _mm_add_ps(
                                            _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)LODWORD(this->point[0]), v12)),
                                            v12)) | v13.m128_i32[0] & LODWORD(this->point[0]))
  + 1.0,
    COERCE_FLOAT(v10.m128_i32[0] & v8.m128i_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                              v10,
                                                                              _mm_add_ps(
                                                                                _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v8, v11)),
                                                                                v11)))
  + 1.0,
    COERCE_FLOAT(v7.m128_i32[0] & v5.m128i_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                             v7,
                                                                             _mm_add_ps(
                                                                               _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v5, v9)),
                                                                               v9)))
  + 1.0,
    COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                          v4,
                                          _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v3, v6)), v6)) | v4.m128_i32[0] & v3.m128i_i32[0])
  + 1.0);
  return v2;
}

// File Line: 1897
// RVA: 0xBAEB90
hkaNURBS::Point *__usercall hkaNURBS::Point::normalize@<rax>(hkaNURBS::Point *this@<rcx>, hkaNURBS::Point *result@<rdx>, float a3@<xmm0>)
{
  hkaNURBS::Point *v3; // rdi
  hkaNURBS::Point *v4; // rbx
  float v5; // xmm0_4

  v3 = result;
  v4 = this;
  v5 = hkaNURBS::Point::mag(this, a3);
  hkaNURBS::Point::operator/(v4, v3, v5);
  return v3;
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
  return (float *)((char *)this + 4 * u);
}

// File Line: 1916
// RVA: 0xBAEBD0
float __usercall hkaNURBS::Point::Dist@<xmm0>(hkaNURBS::Point *P@<rcx>, hkaNURBS::Point *Q@<rdx>, float a3@<xmm0>)
{
  hkaNURBS::Point *v3; // rax
  hkaNURBS::Point result; // [rsp+20h] [rbp-18h]

  v3 = hkaNURBS::Point::operator-(P, &result, Q);
  return hkaNURBS::Point::mag(v3, a3);
}

// File Line: 1921
// RVA: 0xBAEC00
float __fastcall hkaNURBS::Point::Dot(hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  hkaNURBS::Point *v2; // rdi
  hkaNURBS::Point *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm7_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm6_4

  v2 = Q;
  v3 = P;
  v4 = hkaNURBS::Point::operator[](P, 1);
  v5 = v4 * hkaNURBS::Point::operator[](v2, 1);
  v6 = hkaNURBS::Point::operator[](v3, 0);
  v7 = v5 + (float)(v6 * hkaNURBS::Point::operator[](v2, 0));
  v8 = hkaNURBS::Point::operator[](v3, 2);
  v9 = v7 + (float)(v8 * hkaNURBS::Point::operator[](v2, 2));
  v10 = hkaNURBS::Point::operator[](v3, 3);
  return v9 + (float)(v10 * hkaNURBS::Point::operator[](v2, 3));
}

// File Line: 1926
// RVA: 0xBAECC0
float __fastcall hkaNURBS::Point::Cos(hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  hkaNURBS::Point *v2; // rdi
  hkaNURBS::Point *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm7_4
  float v6; // xmm0_4

  v2 = Q;
  v3 = P;
  v4 = hkaNURBS::Point::Dot(P, Q);
  v5 = v4;
  v6 = hkaNURBS::Point::mag(v3, v4);
  return v5 / (float)(v6 * hkaNURBS::Point::mag(v2, v6));
}

// File Line: 1931
// RVA: 0xBAED20
hkaNURBS::Point *__fastcall hkaNURBS::Point::Max(hkaNURBS::Point *result, hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  hkaNURBS::Point *v3; // rbx
  hkaNURBS::Point *v4; // rdi
  hkaNURBS::Point *v5; // rsi
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

  v3 = Q;
  v4 = P;
  v5 = result;
  hkaNURBS::Point::Point(result, 0.0, 0.0, 0.0, 0.0);
  v6 = hkaNURBS::Point::operator[](v4, 0);
  v7 = hkaNURBS::Point::operator[](v3, 0);
  v8 = v4;
  if ( v6 <= v7 )
    v8 = v3;
  v9 = hkaNURBS::Point::operator[](v8, 0);
  *hkaNURBS::Point::operator[](v5, 0) = v9;
  v10 = hkaNURBS::Point::operator[](v4, 1);
  v11 = hkaNURBS::Point::operator[](v3, 1);
  v12 = v4;
  if ( v10 <= v11 )
    v12 = v3;
  v13 = hkaNURBS::Point::operator[](v12, 1);
  *hkaNURBS::Point::operator[](v5, 1) = v13;
  v14 = hkaNURBS::Point::operator[](v4, 2);
  v15 = hkaNURBS::Point::operator[](v3, 2);
  v16 = v4;
  if ( v14 <= v15 )
    v16 = v3;
  v17 = hkaNURBS::Point::operator[](v16, 2);
  *hkaNURBS::Point::operator[](v5, 2) = v17;
  v18 = hkaNURBS::Point::operator[](v4, 3);
  v19 = hkaNURBS::Point::operator[](v3, 3);
  v20 = v4;
  if ( v18 <= v19 )
    v20 = v3;
  v21 = hkaNURBS::Point::operator[](v20, 3);
  *hkaNURBS::Point::operator[](v5, 3) = v21;
  return v5;
}

// File Line: 1943
// RVA: 0xBAEE80
hkaNURBS::Point *__fastcall hkaNURBS::Point::Min(hkaNURBS::Point *result, hkaNURBS::Point *P, hkaNURBS::Point *Q)
{
  hkaNURBS::Point *v3; // rbx
  hkaNURBS::Point *v4; // rdi
  hkaNURBS::Point *v5; // rsi
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

  v3 = Q;
  v4 = P;
  v5 = result;
  hkaNURBS::Point::Point(result, 0.0, 0.0, 0.0, 0.0);
  v6 = hkaNURBS::Point::operator[](v4, 0);
  v7 = hkaNURBS::Point::operator[](v3, 0);
  v8 = v4;
  if ( v6 >= v7 )
    v8 = v3;
  v9 = hkaNURBS::Point::operator[](v8, 0);
  *hkaNURBS::Point::operator[](v5, 0) = v9;
  v10 = hkaNURBS::Point::operator[](v4, 1);
  v11 = hkaNURBS::Point::operator[](v3, 1);
  v12 = v4;
  if ( v10 >= v11 )
    v12 = v3;
  v13 = hkaNURBS::Point::operator[](v12, 1);
  *hkaNURBS::Point::operator[](v5, 1) = v13;
  v14 = hkaNURBS::Point::operator[](v4, 2);
  v15 = hkaNURBS::Point::operator[](v3, 2);
  v16 = v4;
  if ( v14 >= v15 )
    v16 = v3;
  v17 = hkaNURBS::Point::operator[](v16, 2);
  *hkaNURBS::Point::operator[](v5, 2) = v17;
  v18 = hkaNURBS::Point::operator[](v4, 3);
  v19 = hkaNURBS::Point::operator[](v3, 3);
  v20 = v4;
  if ( v18 >= v19 )
    v20 = v3;
  v21 = hkaNURBS::Point::operator[](v20, 3);
  *hkaNURBS::Point::operator[](v5, 3) = v21;
  return v5;
}

// File Line: 2083
// RVA: 0xBADFD0
void __fastcall hkaCompression::approximateNURBSCurve(int numSamples, const float *sampleTimes, hkVector4f *sampleData, int degree, float tolerance, int *numKnotsOut, float *knotsOut, int *numPointsOut, hkVector4f *pointsOut)
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

