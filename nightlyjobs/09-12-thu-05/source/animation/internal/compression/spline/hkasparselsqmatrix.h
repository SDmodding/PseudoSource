// File Line: 50
// RVA: 0xBB4EB0
void __fastcall hkaSparseLSQMatrix<float>::hkaSparseLSQMatrix<float>(hkaSparseLSQMatrix<float> *this, int i, int j)
{
  this->val.m_capacityAndFlags = 0x80000000;
  this->val.m_data = 0i64;
  this->val.m_size = 0;
  this->row.m_data = 0i64;
  this->row.m_size = 0;
  this->row.m_capacityAndFlags = 0x80000000;
  this->col.m_data = 0i64;
  this->col.m_size = 0;
  this->col.m_capacityAndFlags = 0x80000000;
  this->m_m = i;
  this->m_n = j;
}

// File Line: 58
// RVA: 0xBB4EF0
void __fastcall hkaSparseLSQMatrix<float>::~hkaSparseLSQMatrix<float>(hkaSparseLSQMatrix<float> *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d

  m_capacityAndFlags = this->col.m_capacityAndFlags;
  this->col.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->col.m_data,
      4 * m_capacityAndFlags);
  this->col.m_data = 0i64;
  this->col.m_capacityAndFlags = 0x80000000;
  v3 = this->row.m_capacityAndFlags;
  this->row.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->row.m_data, 4 * v3);
  this->row.m_data = 0i64;
  this->row.m_capacityAndFlags = 0x80000000;
  v4 = this->val.m_capacityAndFlags;
  this->val.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->val.m_data, 4 * v4);
  this->val.m_capacityAndFlags = 0x80000000;
  this->val.m_data = 0i64;
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
  if ( v != 0.0 )
  {
    if ( this->row.m_size == (this->row.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->row, 4);
    this->row.m_data[this->row.m_size++] = i;
    if ( this->col.m_size == (this->col.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->col, 4);
    this->col.m_data[this->col.m_size++] = j;
    if ( this->val.m_size == (this->val.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 4);
    this->val.m_data[this->val.m_size++] = v;
  }
}

// File Line: 112
// RVA: 0xBB4FB0
hkaMatrix<float> *__fastcall hkaSparseLSQMatrix<float>::operator*(
        hkaSparseLSQMatrix<float> *this,
        hkaMatrix<float> *result,
        hkaMatrix<float> *x)
{
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  hkaMatrix<float> scratch; // [rsp+20h] [rbp-28h] BYREF

  v6 = hkaMatrix<float>::Width(x);
  v7 = hkaMatrix<float>::Height(x);
  hkaMatrix<float>::hkaMatrix<float>(result, v7, v6, 0.0);
  v8 = hkaMatrix<float>::Width(x);
  v9 = hkaSparseLSQMatrix<float>::Height((StructArrayImplementation *)this);
  hkaMatrix<float>::hkaMatrix<float>(&scratch, v9, v8, 0.0);
  hkaSparseLSQMatrix<float>::MultiplyAdd(this, result, x, &scratch);
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&scratch);
  return result;
}

// File Line: 126
// RVA: 0xBB5260
void __fastcall hkaSparseLSQMatrix<float>::Multiply(
        hkaSparseLSQMatrix<float> *this,
        hkaMatrix<float> *b,
        hkaMatrix<float> *x,
        hkaMatrix<float> *scratch)
{
  float v[6]; // [rsp+20h] [rbp-18h] BYREF

  v[0] = 0.0;
  hkaMatrix<float>::SetAll(b, v);
  hkaSparseLSQMatrix<float>::MultiplyAdd(this, b, x, scratch);
}

// File Line: 138
// RVA: 0xBB52C0
void __fastcall hkaSparseLSQMatrix<float>::MultiplyAdd(
        hkaSparseLSQMatrix<float> *this,
        hkaMatrix<float> *b,
        hkaMatrix<float> *x,
        hkaMatrix<float> *scratch)
{
  int v8; // ebp
  int m_size; // ebx
  int v10; // r14d
  __int64 v11; // rsi
  float *v12; // rbx
  float v13; // xmm0_4
  int v14; // ebp
  int v15; // ebx
  int v16; // r14d
  __int64 v17; // rsi
  float *v18; // rbx
  float *v19; // rax
  float v[14]; // [rsp+20h] [rbp-38h] BYREF

  v[0] = 0.0;
  hkaMatrix<float>::SetAll(scratch, v);
  v8 = 0;
  if ( (int)hkaMatrix<float>::Width(b) > 0 )
  {
    m_size = this->val.m_size;
    do
    {
      v10 = 0;
      if ( m_size > 0 )
      {
        v11 = 0i64;
        do
        {
          v12 = hkaMatrix<float>::operator()(scratch, this->row.m_data[v11], v8);
          v13 = hkaMatrix<float>::operator()(x, this->col.m_data[v11], v8);
          ++v10;
          *v12 = (float)(v13 * this->val.m_data[v11++]) + *v12;
          m_size = this->val.m_size;
        }
        while ( v10 < m_size );
      }
      ++v8;
    }
    while ( v8 < (int)hkaMatrix<float>::Width(b) );
  }
  v14 = 0;
  if ( (int)hkaMatrix<float>::Width(b) > 0 )
  {
    v15 = this->val.m_size;
    do
    {
      v16 = 0;
      if ( v15 > 0 )
      {
        v17 = 0i64;
        do
        {
          v18 = hkaMatrix<float>::operator()(b, this->col.m_data[v17], v14);
          v19 = hkaMatrix<float>::operator()(scratch, this->row.m_data[v17], v14);
          ++v16;
          *v18 = (float)(this->val.m_data[v17++] * *v19) + *v18;
          v15 = this->val.m_size;
        }
        while ( v16 < v15 );
      }
      ++v14;
    }
    while ( v14 < (int)hkaMatrix<float>::Width(b) );
  }
}

