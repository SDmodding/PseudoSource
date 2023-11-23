// File Line: 48
// RVA: 0xBB5730
hkBool *__fastcall hkaCGSolver<float>::Solve(
        hkBool *result,
        hkaSparseLSQMatrix<float> *A,
        hkaMatrix<float> *X,
        hkaMatrix<float> *B,
        int maxiter,
        float tol)
{
  int v10; // eax
  int v11; // eax
  int v12; // ebp
  int i; // edi
  float *v14; // rbx
  float v15; // xmm6_4
  float *v16; // rax
  int j; // edi
  float *v18; // rbx
  float *v19; // rax
  hkBool resulta; // [rsp+30h] [rbp-88h] BYREF
  hkaMatrix<float> x; // [rsp+38h] [rbp-80h] BYREF
  hkaMatrix<float> b; // [rsp+50h] [rbp-68h] BYREF

  v10 = hkaMatrix<float>::Height(X);
  hkaMatrix<float>::hkaMatrix<float>(&x, v10, 1);
  v11 = hkaMatrix<float>::Height(B);
  hkaMatrix<float>::hkaMatrix<float>(&b, v11, 1);
  v12 = 0;
  if ( (int)hkaMatrix<float>::Width(X) <= 0 )
  {
LABEL_8:
    result->m_bool = 1;
  }
  else
  {
    while ( 1 )
    {
      for ( i = 0; i < (int)hkaMatrix<float>::Height(X); *v16 = v15 )
      {
        v14 = hkaMatrix<float>::operator()(X, i, v12);
        *hkaMatrix<float>::operator()(&x, i) = *v14;
        v15 = hkaMatrix<float>::operator()(B, i, v12);
        v16 = hkaMatrix<float>::operator()(&b, i++);
      }
      if ( !hkaCGSolver<float>::SolveOneColumn(&resulta, A, &x, &b, maxiter, tol)->m_bool )
        break;
      for ( j = 0; j < (int)hkaMatrix<float>::Height(X); *v19 = *v18 )
      {
        v18 = hkaMatrix<float>::operator()(&x, j);
        v19 = hkaMatrix<float>::operator()(X, j++, v12);
      }
      if ( ++v12 >= (int)hkaMatrix<float>::Width(X) )
        goto LABEL_8;
    }
    result->m_bool = 0;
  }
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&b);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&x);
  return result;
}

// File Line: 90
// RVA: 0xBB58F0
hkBool *__fastcall hkaCGSolver<float>::SolveOneColumn(
        hkBool *result,
        hkaSparseLSQMatrix<float> *A,
        hkaMatrix<float> *x,
        hkaMatrix<float> *b)
{
  int v8; // ebx
  hkaMatrix<float> *v9; // rax
  int v10; // eax
  float v11; // xmm0_4
  int v12; // ebx
  float v13; // xmm9_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm6_4
  hkaMatrix<float> Aa; // [rsp+20h] [rbp-71h] BYREF
  hkaMatrix<float> ba; // [rsp+38h] [rbp-59h] BYREF
  hkaMatrix<float> scratch; // [rsp+50h] [rbp-41h] BYREF
  hkaMatrix<float> resulta; // [rsp+68h] [rbp-29h] BYREF
  int v22; // [rsp+108h] [rbp+77h]
  float u; // [rsp+110h] [rbp+7Fh] BYREF

  v8 = hkaMatrix<float>::Height(x);
  v9 = hkaSparseLSQMatrix<float>::operator*(A, &resulta, x);
  hkaMatrix<float>::operator-(b, &Aa, v9);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&resulta);
  hkaMatrix<float>::hkaMatrix<float>(&Aa, &Aa);
  hkaMatrix<float>::hkaMatrix<float>(&ba, v8, 1);
  v10 = hkaSparseLSQMatrix<float>::Height((StructArrayImplementation *)A);
  hkaMatrix<float>::hkaMatrix<float>(&scratch, v10, 1);
  v11 = hkaCGSolver<float>::InnerProduct(&Aa, &Aa);
  v12 = 0;
  v13 = u * u;
  v14 = v11;
  if ( v22 <= 0 )
  {
LABEL_7:
    result->m_bool = 0;
  }
  else
  {
    while ( v14 >= v13 )
    {
      hkaSparseLSQMatrix<float>::Multiply(A, &ba, &Aa, &scratch);
      v15 = v14 / hkaCGSolver<float>::InnerProduct(&Aa, &ba);
      u = v15;
      hkaCGSolver<float>::ScaleAdd(x, &u, &Aa);
      ++v12;
      if ( v12 == 50 * (v12 / 50) )
      {
        hkaCGSolver<float>::CopyNegative(&Aa, b);
        hkaSparseLSQMatrix<float>::MultiplyAdd(A, &Aa, x, &scratch);
        hkaCGSolver<float>::Negate(&Aa);
      }
      else
      {
        LODWORD(u) = LODWORD(v15) ^ _xmm[0];
        hkaCGSolver<float>::ScaleAdd(&Aa, &u, &ba);
      }
      v16 = v14;
      v14 = hkaCGSolver<float>::InnerProduct(&Aa, &Aa);
      u = v14 / v16;
      hkaCGSolver<float>::ScaleAdd(&Aa, &Aa, &u, &Aa);
      if ( v12 >= v22 )
        goto LABEL_7;
    }
    result->m_bool = 1;
  }
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&scratch);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&ba);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&Aa);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&Aa);
  return result;
}

// File Line: 145
// RVA: 0xBB51E0
float __fastcall hkaCGSolver<float>::InnerProduct(hkaMatrix<float> *a, hkaMatrix<float> *b)
{
  int v4; // ebx
  int v5; // esi
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm0_4

  v4 = 0;
  v5 = hkaMatrix<float>::Size(a);
  v6 = 0.0;
  if ( v5 > 0 )
  {
    do
    {
      v7 = hkaMatrix<float>::operator()(a, v4);
      v8 = hkaMatrix<float>::operator()(b, v4++);
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
  int v6; // edi
  int v7; // ebp
  float *v8; // rbx
  float v9; // xmm0_4

  v6 = 0;
  v7 = hkaMatrix<float>::Size(a);
  if ( v7 > 0 )
  {
    do
    {
      v8 = hkaMatrix<float>::operator()(a, v6);
      v9 = hkaMatrix<float>::operator()(b, v6++);
      *v8 = (float)(v9 * *u) + *v8;
    }
    while ( v6 < v7 );
  }
}

// File Line: 188
// RVA: 0xBB5510
void __fastcall hkaCGSolver<float>::ScaleAdd(
        hkaMatrix<float> *c,
        hkaMatrix<float> *a,
        const float *u,
        hkaMatrix<float> *b)
{
  int v8; // edi
  int v9; // ebp
  float *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm0_4

  v8 = 0;
  v9 = hkaMatrix<float>::Size(a);
  if ( v9 > 0 )
  {
    do
    {
      v10 = hkaMatrix<float>::operator()(c, v8);
      v11 = hkaMatrix<float>::operator()(b, v8) * *u;
      v12 = hkaMatrix<float>::operator()(a, v8++);
      *v10 = v11 + v12;
    }
    while ( v8 < v9 );
  }
}

// File Line: 208
// RVA: 0xBB5140
void __fastcall hkaCGSolver<float>::CopyNegative(hkaMatrix<float> *a, hkaMatrix<float> *b)
{
  __m128 v2; // xmm0
  int v5; // edi
  int v6; // ebp
  float *v7; // rbx

  v5 = 0;
  v6 = hkaMatrix<float>::Size(a);
  if ( v6 > 0 )
  {
    do
    {
      v7 = hkaMatrix<float>::operator()(a, v5);
      v2.m128_f32[0] = hkaMatrix<float>::operator()(b, v5++);
      v2 = _mm_xor_ps(v2, (__m128)(unsigned int)_xmm[0]);
      *v7 = v2.m128_f32[0];
    }
    while ( v5 < v6 );
  }
}

// File Line: 225
// RVA: 0xBB5410
void __fastcall hkaCGSolver<float>::Negate(hkaMatrix<float> *a)
{
  int v2; // edi
  int v3; // ebp
  float *v4; // rbx
  float *v5; // rax

  v2 = 0;
  v3 = hkaMatrix<float>::Size(a);
  if ( v3 > 0 )
  {
    do
    {
      v4 = hkaMatrix<float>::operator()(a, v2);
      v5 = hkaMatrix<float>::operator()(a, v2++);
      *(_DWORD *)v5 = *(_DWORD *)v4 ^ _xmm[0];
    }
    while ( v2 < v3 );
  }
}

