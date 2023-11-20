// File Line: 50
// RVA: 0xBB4EB0
void __fastcall hkaSparseLSQMatrix<float>::hkaSparseLSQMatrix<float>(hkaSparseLSQMatrix<float> *this, int i, int j)
{
  this->val.m_capacityAndFlags = 2147483648;
  this->val.m_data = 0i64;
  this->val.m_size = 0;
  this->row.m_data = 0i64;
  this->row.m_size = 0;
  this->row.m_capacityAndFlags = 2147483648;
  this->col.m_data = 0i64;
  this->col.m_size = 0;
  this->col.m_capacityAndFlags = 2147483648;
  this->m_m = i;
  this->m_n = j;
}

// File Line: 58
// RVA: 0xBB4EF0
void __fastcall hkaSparseLSQMatrix<float>::~hkaSparseLSQMatrix<float>(hkaSparseLSQMatrix<float> *this)
{
  int v1; // er8
  hkaSparseLSQMatrix<float> *v2; // rbx
  int v3; // er8
  int v4; // er8

  v1 = this->col.m_capacityAndFlags;
  v2 = this;
  this->col.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->col.m_data,
      4 * v1);
  v2->col.m_data = 0i64;
  v2->col.m_capacityAndFlags = 2147483648;
  v3 = v2->row.m_capacityAndFlags;
  v2->row.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->row.m_data,
      4 * v3);
  v2->row.m_data = 0i64;
  v2->row.m_capacityAndFlags = 2147483648;
  v4 = v2->val.m_capacityAndFlags;
  v2->val.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->val.m_data,
      4 * v4);
  v2->val.m_capacityAndFlags = 2147483648;
  v2->val.m_data = 0i64;
}

// File Line: 65
// RVA: 0xBB51D0
__int64 __fastcall hkaSparseLSQMatrix<float>::Height(StructArrayImplementation *this)
{
  return (unsigned int)this->m_size;
}

// File Line: 97
// RVA: 0xBB55B0
void __fastcall hkaSparseLSQMatrix<float>::Set(hkaSparseLSQMatrix<float> *this, int i, int j, float v)
{
  int v4; // ebp
  int v5; // esi
  hkaSparseLSQMatrix<float> *v6; // rbx

  v4 = j;
  v5 = i;
  v6 = this;
  if ( v != 0.0 )
  {
    if ( this->row.m_size == (this->row.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->row, 4);
    v6->row.m_data[v6->row.m_size++] = v5;
    if ( v6->col.m_size == (v6->col.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->col, 4);
    v6->col.m_data[v6->col.m_size++] = v4;
    if ( v6->val.m_size == (v6->val.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 4);
    v6->val.m_data[v6->val.m_size++] = v;
  }
}

// File Line: 112
// RVA: 0xBB4FB0
hkaMatrix<float> *__fastcall hkaSparseLSQMatrix<float>::operator*(hkaSparseLSQMatrix<float> *this, hkaMatrix<float> *result, hkaMatrix<float> *x)
{
  hkaSparseLSQMatrix<float> *v3; // rsi
  hkaMatrix<float> *v4; // rdi
  hkaMatrix<float> *v5; // rbp
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  hkaMatrix<float> scratch; // [rsp+20h] [rbp-28h]

  v3 = this;
  v4 = x;
  v5 = result;
  v6 = hkaMatrix<float>::Width(x);
  v7 = hkaMatrix<float>::Height(v4);
  hkaMatrix<float>::hkaMatrix<float>(v5, v7, v6, 0.0);
  v8 = hkaMatrix<float>::Width(v4);
  v9 = hkaSparseLSQMatrix<float>::Height((StructArrayImplementation *)v3);
  hkaMatrix<float>::hkaMatrix<float>(&scratch, v9, v8, 0.0);
  hkaSparseLSQMatrix<float>::MultiplyAdd(v3, v5, v4, &scratch);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&scratch);
  return v5;
}

// File Line: 126
// RVA: 0xBB5260
void __fastcall hkaSparseLSQMatrix<float>::Multiply(hkaSparseLSQMatrix<float> *this, hkaMatrix<float> *b, hkaMatrix<float> *x, hkaMatrix<float> *scratch)
{
  hkaMatrix<float> *v4; // rsi
  hkaSparseLSQMatrix<float> *v5; // rbp
  hkaMatrix<float> *v6; // rbx
  hkaMatrix<float> *v7; // rdi
  float v; // [rsp+20h] [rbp-18h]

  v4 = b;
  v5 = this;
  v6 = scratch;
  v7 = x;
  v = 0.0;
  hkaMatrix<float>::SetAll(b, &v);
  hkaSparseLSQMatrix<float>::MultiplyAdd(v5, v4, v7, v6);
}

// File Line: 138
// RVA: 0xBB52C0
void __fastcall hkaSparseLSQMatrix<float>::MultiplyAdd(hkaSparseLSQMatrix<float> *this, hkaMatrix<float> *b, hkaMatrix<float> *x, hkaMatrix<float> *scratch)
{
  hkaMatrix<float> *v4; // r15
  hkaSparseLSQMatrix<float> *v5; // rdi
  hkaMatrix<float> *v6; // r12
  hkaMatrix<float> *v7; // r13
  int v8; // ebp
  int v9; // ebx
  int v10; // er14
  __int64 v11; // rsi
  float *v12; // rbx
  float v13; // xmm0_4
  int v14; // ebp
  int v15; // ebx
  int v16; // er14
  __int64 v17; // rsi
  float *v18; // rbx
  float *v19; // rax
  float v; // [rsp+20h] [rbp-38h]

  v4 = b;
  v5 = this;
  v = 0.0;
  v6 = scratch;
  v7 = x;
  hkaMatrix<float>::SetAll(scratch, &v);
  v8 = 0;
  if ( (signed int)hkaMatrix<float>::Width(v4) > 0 )
  {
    v9 = v5->val.m_size;
    do
    {
      v10 = 0;
      if ( v9 > 0 )
      {
        v11 = 0i64;
        do
        {
          v12 = hkaMatrix<float>::operator()(v6, v5->row.m_data[v11], v8);
          v13 = hkaMatrix<float>::operator()(v7, v5->col.m_data[v11], v8);
          ++v10;
          ++v11;
          *v12 = (float)(v13 * v5->val.m_data[v11 - 1]) + *v12;
          v9 = v5->val.m_size;
        }
        while ( v10 < v9 );
      }
      ++v8;
    }
    while ( v8 < (signed int)hkaMatrix<float>::Width(v4) );
  }
  v14 = 0;
  if ( (signed int)hkaMatrix<float>::Width(v4) > 0 )
  {
    v15 = v5->val.m_size;
    do
    {
      v16 = 0;
      if ( v15 > 0 )
      {
        v17 = 0i64;
        do
        {
          v18 = hkaMatrix<float>::operator()(v4, v5->col.m_data[v17], v14);
          v19 = hkaMatrix<float>::operator()(v6, v5->row.m_data[v17], v14);
          ++v16;
          ++v17;
          *v18 = (float)(v5->val.m_data[v17 - 1] * *v19) + *v18;
          v15 = v5->val.m_size;
        }
        while ( v16 < v15 );
      }
      ++v14;
    }
    while ( v14 < (signed int)hkaMatrix<float>::Width(v4) );
  }
}

