// File Line: 70
// RVA: 0xBB4D50
void __fastcall hkaMatrix<float>::hkaMatrix<float>(hkaMatrix<float> *this, int m, int n)
{
  int v3; // edi
  int v5; // eax
  int v6; // eax
  int v7; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  this->m_data.m_capacityAndFlags = 0x80000000;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_m = m;
  v3 = n * m;
  this->m_n = n;
  v5 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 >= n * m )
  {
    this->m_data.m_size = v3;
  }
  else
  {
    v6 = 2 * v5;
    v7 = n * m;
    if ( v3 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this, v7, 4);
    this->m_data.m_size = v3;
  }
}

// File Line: 76
// RVA: 0xBB4DD0
void __fastcall hkaMatrix<float>::hkaMatrix<float>(hkaMatrix<float> *this, int m, int n, float val)
{
  __int64 v4; // rbx
  int v5; // esi
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  v4 = 0i64;
  this->m_data.m_capacityAndFlags = 0x80000000;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_m = m;
  v5 = n * m;
  this->m_n = n;
  v7 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < n * m )
  {
    v8 = 2 * v7;
    v9 = n * m;
    if ( v5 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this, v9, 4);
  }
  this->m_data.m_size = v5;
  if ( v5 >= 4i64 )
  {
    do
    {
      v4 += 4i64;
      this->m_data.m_data[v4 - 4] = val;
      this->m_data.m_data[v4 - 3] = val;
      this->m_data.m_data[v4 - 2] = val;
      this->m_data.m_data[v4 - 1] = val;
    }
    while ( v4 < v5 - 3i64 );
  }
  for ( ; v4 < v5; this->m_data.m_data[v4 - 1] = val )
    ++v4;
}

// File Line: 87
// RVA: 0xBB4C90
void __fastcall hkaMatrix<float>::hkaMatrix<float>(hkaMatrix<float> *this, hkaMatrix<float> *A)
{
  int v2; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // ebp
  int v8; // ecx
  int v9; // r9d
  __int64 v10; // rdx
  float v11; // eax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  this->m_data.m_capacityAndFlags = 0x80000000;
  v2 = 0;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_m = A->m_m;
  this->m_n = A->m_n;
  v5 = hkaMatrix<float>::Size(this);
  v6 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = v5;
  if ( v6 < v5 )
  {
    v8 = 2 * v6;
    v9 = v5;
    if ( v5 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this, v9, 4);
  }
  this->m_data.m_size = v7;
  if ( this->m_m * this->m_n > 0 )
  {
    v10 = 0i64;
    do
    {
      ++v2;
      v11 = A->m_data.m_data[v10++];
      this->m_data.m_data[v10 - 1] = v11;
    }
    while ( v2 < this->m_m * this->m_n );
  }
}

// File Line: 138
// RVA: 0xBB50F0
hkaMatrix<float> *__fastcall hkaMatrix<float>::operator-=(hkaMatrix<float> *this, hkaMatrix<float> *A)
{
  int v2; // r8d
  float *m_data; // r9
  __int64 v4; // rdx

  v2 = 0;
  if ( this->m_m * this->m_n > 0 )
  {
    m_data = A->m_data.m_data;
    v4 = 0i64;
    do
    {
      ++v2;
      ++v4;
      this->m_data.m_data[v4 - 1] = this->m_data.m_data[v4 - 1] - m_data[v4 - 1];
    }
    while ( v2 < this->m_m * this->m_n );
  }
  return this;
}

// File Line: 220
// RVA: 0xBB5050
hkaMatrix<float> *__fastcall hkaMatrix<float>::operator-(
        hkaMatrix<float> *this,
        hkaMatrix<float> *result,
        hkaMatrix<float> *A)
{
  hkaMatrix<float>::hkaMatrix<float>(result, this);
  hkaMatrix<float>::operator-=(result, A);
  return result;
}

// File Line: 268
// RVA: 0xBB5690
void __fastcall hkaMatrix<float>::SetAll(hkaMatrix<float> *this, float *v)
{
  __int64 v2; // r8
  int v3; // eax

  v2 = 0i64;
  v3 = this->m_m * this->m_n;
  if ( v3 >= 4i64 )
  {
    do
    {
      v2 += 4i64;
      this->m_data.m_data[v2 - 4] = *v;
      this->m_data.m_data[v2 - 3] = *v;
      this->m_data.m_data[v2 - 2] = *v;
      this->m_data.m_data[v2 - 1] = *v;
    }
    while ( v2 < v3 - 3i64 );
  }
  for ( ; v2 < v3; this->m_data.m_data[v2 - 1] = *v )
    ++v2;
}

// File Line: 280
// RVA: 0xBB50D0
float __fastcall hkaMatrix<float>::operator()(hkaMatrix<float> *this, int i, int j)
{
  return this->m_data.m_data[j + i * (__int64)this->m_n];
}

// File Line: 289
// RVA: 0xBB50A0
float *__fastcall hkaMatrix<float>::operator()(hkaMatrix<float> *this, int i, int j)
{
  return &this->m_data.m_data[j + i * this->m_n];
}

// File Line: 298
// RVA: 0xBB50C0
float __fastcall hkaMatrix<float>::operator()(hkaMatrix<float> *this, int i)
{
  return this->m_data.m_data[i];
}

// File Line: 306
// RVA: 0xBB5090
float *__fastcall hkaMatrix<float>::operator()(hkaMatrix<float> *this, int i)
{
  return &this->m_data.m_data[i];
}

// File Line: 330
// RVA: 0xBB5720
__int64 __fastcall hkaMatrix<float>::Size(hkaMatrix<float> *this)
{
  return (unsigned int)(this->m_m * this->m_n);
}

