// File Line: 48
// RVA: 0xBB5730
hkBool *__fastcall hkaCGSolver<float>::Solve(hkBool *result, hkaSparseLSQMatrix<float> *A, hkaMatrix<float> *X, hkaMatrix<float> *B, int maxiter, float tol)
{
  hkBool *v6; // r15
  hkaMatrix<float> *v7; // r14
  hkaMatrix<float> *v8; // rsi
  hkaSparseLSQMatrix<float> *v9; // r13
  int v10; // eax
  int v11; // eax
  int v12; // ebp
  signed int i; // edi
  float *v14; // rbx
  float v15; // xmm6_4
  float *v16; // rax
  signed int j; // edi
  float *v18; // rbx
  float *v19; // rax
  hkBool resulta; // [rsp+30h] [rbp-88h]
  hkaMatrix<float> x; // [rsp+38h] [rbp-80h]
  hkaMatrix<float> b; // [rsp+50h] [rbp-68h]

  v6 = result;
  v7 = B;
  v8 = X;
  v9 = A;
  v10 = hkaMatrix<float>::Height(X);
  hkaMatrix<float>::hkaMatrix<float>(&x, v10, 1);
  v11 = hkaMatrix<float>::Height(v7);
  hkaMatrix<float>::hkaMatrix<float>(&b, v11, 1);
  v12 = 0;
  if ( (signed int)hkaMatrix<float>::Width(v8) <= 0 )
  {
LABEL_8:
    v6->m_bool = 1;
  }
  else
  {
    while ( 1 )
    {
      for ( i = 0; i < (signed int)hkaMatrix<float>::Height(v8); *v16 = v15 )
      {
        v14 = hkaMatrix<float>::operator()(v8, i, v12);
        *hkaMatrix<float>::operator()(&x, i) = *v14;
        v15 = hkaMatrix<float>::operator()(v7, i, v12);
        v16 = hkaMatrix<float>::operator()(&b, i++);
      }
      if ( !hkaCGSolver<float>::SolveOneColumn(&resulta, v9, &x, &b, maxiter, tol)->m_bool )
        break;
      for ( j = 0; j < (signed int)hkaMatrix<float>::Height(v8); *v19 = *v18 )
      {
        v18 = hkaMatrix<float>::operator()(&x, j);
        v19 = hkaMatrix<float>::operator()(v8, j++, v12);
      }
      if ( ++v12 >= (signed int)hkaMatrix<float>::Width(v8) )
        goto LABEL_8;
    }
    v6->m_bool = 0;
  }
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&b);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&x);
  return v6;
}

// File Line: 90
// RVA: 0xBB58F0
hkBool *__usercall hkaCGSolver<float>::SolveOneColumn@<rax>(hkBool *result@<rcx>, hkaSparseLSQMatrix<float> *A@<rdx>, hkaMatrix<float> *x@<r8>, hkaMatrix<float> *b@<r9>, __m128 *a5@<xmm0>)
{
  hkBool *v5; // r14
  hkaMatrix<float> *v6; // r15
  hkaMatrix<float> *v7; // rdi
  hkaSparseLSQMatrix<float> *v8; // rsi
  int v9; // ebx
  hkaMatrix<float> *v10; // rax
  int v11; // eax
  float v12; // xmm0_4
  int v13; // ebx
  float v14; // xmm9_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  hkaMatrix<float> Aa; // [rsp+20h] [rbp-71h]
  hkaMatrix<float> ba; // [rsp+38h] [rbp-59h]
  hkaMatrix<float> scratch; // [rsp+50h] [rbp-41h]
  hkaMatrix<float> resulta; // [rsp+68h] [rbp-29h]
  int v22; // [rsp+108h] [rbp+77h]
  float u; // [rsp+110h] [rbp+7Fh]

  v5 = result;
  v6 = b;
  v7 = x;
  v8 = A;
  v9 = hkaMatrix<float>::Height(x);
  v10 = hkaSparseLSQMatrix<float>::operator*(v8, &resulta, v7);
  hkaMatrix<float>::operator-(v6, &Aa, v10);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&resulta);
  hkaMatrix<float>::hkaMatrix<float>(&Aa, &Aa);
  hkaMatrix<float>::hkaMatrix<float>(&ba, v9, 1);
  v11 = hkaSparseLSQMatrix<float>::Height((StructArrayImplementation *)v8);
  hkaMatrix<float>::hkaMatrix<float>(&scratch, v11, 1);
  v12 = hkaCGSolver<float>::InnerProduct(&Aa, &Aa);
  v13 = 0;
  v14 = u * u;
  v15 = v12;
  if ( v22 <= 0 )
  {
LABEL_7:
    v5->m_bool = 0;
  }
  else
  {
    while ( v15 >= v14 )
    {
      hkaSparseLSQMatrix<float>::Multiply(v8, &ba, &Aa, &scratch);
      *(float *)&a5 = hkaCGSolver<float>::InnerProduct(&Aa, &ba);
      u = v15 / *(float *)&a5;
      hkaCGSolver<float>::ScaleAdd(v7, &u, &Aa);
      ++v13;
      if ( v13 == 50 * (v13 / 50) )
      {
        hkaCGSolver<float>::CopyNegative(&Aa, v6, a5);
        hkaSparseLSQMatrix<float>::MultiplyAdd(v8, &Aa, v7, &scratch);
        hkaCGSolver<float>::Negate(&Aa);
      }
      else
      {
        LODWORD(u) = COERCE_UNSIGNED_INT(v15 / *(float *)&a5) ^ _xmm[0];
        hkaCGSolver<float>::ScaleAdd(&Aa, &u, &ba);
      }
      v16 = v15;
      v15 = hkaCGSolver<float>::InnerProduct(&Aa, &Aa);
      u = v15 / v16;
      hkaCGSolver<float>::ScaleAdd(&Aa, &Aa, &u, &Aa);
      if ( v13 >= v22 )
        goto LABEL_7;
    }
    v5->m_bool = 1;
  }
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&scratch);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&ba);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&Aa);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&Aa);
  return v5;
}

// File Line: 145
// RVA: 0xBB51E0
float __fastcall hkaCGSolver<float>::InnerProduct(hkaMatrix<float> *a, hkaMatrix<float> *b)
{
  hkaMatrix<float> *v2; // rbp
  hkaMatrix<float> *v3; // rdi
  int v4; // ebx
  int v5; // esi
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm0_4

  v2 = b;
  v3 = a;
  v4 = 0;
  v5 = hkaMatrix<float>::Size(a);
  v6 = 0.0;
  if ( v5 > 0 )
  {
    do
    {
      v7 = hkaMatrix<float>::operator()(v3, v4);
      v8 = hkaMatrix<float>::operator()(v2, v4++);
      v6 = v6 + (float)(v7 * v8);
    }
    while ( v4 < v5 );
  }
  return v6;
}

// File Line: 168
// RVA: 0xBB5490
void __fastcall hkaCGSolver<float>::ScaleAdd(hkaMatrix<float> *a, const float *u, hkaMatrix<float> *b)
{
  hkaMatrix<float> *v3; // r14
  const float *v4; // r15
  hkaMatrix<float> *v5; // rsi
  int v6; // edi
  int v7; // ebp
  float *v8; // rbx
  float v9; // xmm0_4

  v3 = b;
  v4 = u;
  v5 = a;
  v6 = 0;
  v7 = hkaMatrix<float>::Size(a);
  if ( v7 > 0 )
  {
    do
    {
      v8 = hkaMatrix<float>::operator()(v5, v6);
      v9 = hkaMatrix<float>::operator()(v3, v6++);
      *v8 = (float)(v9 * *v4) + *v8;
    }
    while ( v6 < v7 );
  }
}

// File Line: 188
// RVA: 0xBB5510
void __fastcall hkaCGSolver<float>::ScaleAdd(hkaMatrix<float> *c, hkaMatrix<float> *a, const float *u, hkaMatrix<float> *b)
{
  hkaMatrix<float> *v4; // r12
  hkaMatrix<float> *v5; // r14
  const float *v6; // r15
  hkaMatrix<float> *v7; // rsi
  int v8; // edi
  int v9; // ebp
  float *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm0_4

  v4 = c;
  v5 = b;
  v6 = u;
  v7 = a;
  v8 = 0;
  v9 = hkaMatrix<float>::Size(a);
  if ( v9 > 0 )
  {
    do
    {
      v10 = hkaMatrix<float>::operator()(v4, v8);
      v11 = hkaMatrix<float>::operator()(v5, v8) * *v6;
      v12 = hkaMatrix<float>::operator()(v7, v8++);
      *v10 = v11 + v12;
    }
    while ( v8 < v9 );
  }
}

// File Line: 208
// RVA: 0xBB5140
void __usercall hkaCGSolver<float>::CopyNegative(hkaMatrix<float> *a@<rcx>, hkaMatrix<float> *b@<rdx>, __m128 a3@<xmm0>)
{
  hkaMatrix<float> *v3; // r14
  hkaMatrix<float> *v4; // rsi
  int v5; // edi
  int v6; // ebp
  float *v7; // rbx

  v3 = b;
  v4 = a;
  v5 = 0;
  v6 = hkaMatrix<float>::Size(a);
  if ( v6 > 0 )
  {
    do
    {
      v7 = hkaMatrix<float>::operator()(v4, v5);
      a3.m128_f32[0] = hkaMatrix<float>::operator()(v3, v5++);
      a3 = _mm_xor_ps(a3, (__m128)(unsigned int)_xmm[0]);
      *v7 = a3.m128_f32[0];
    }
    while ( v5 < v6 );
  }
}

// File Line: 225
// RVA: 0xBB5410
void __fastcall hkaCGSolver<float>::Negate(hkaMatrix<float> *a)
{
  hkaMatrix<float> *v1; // rsi
  int v2; // edi
  int v3; // ebp
  float *v4; // rbx
  float *v5; // rax

  v1 = a;
  v2 = 0;
  v3 = hkaMatrix<float>::Size(a);
  if ( v3 > 0 )
  {
    do
    {
      v4 = hkaMatrix<float>::operator()(v1, v2);
      v5 = hkaMatrix<float>::operator()(v1, v2++);
      *(_DWORD *)v5 = *(_DWORD *)v4 ^ _xmm[0];
    }
    while ( v2 < v3 );
  }
}

