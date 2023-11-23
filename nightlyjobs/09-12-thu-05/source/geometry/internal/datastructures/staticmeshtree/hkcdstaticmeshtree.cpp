// File Line: 22
// RVA: 0x15C95C0
void dynamic_initializer_for__hkcdStaticMeshTreeBase::s_zeroDistance__()
{
  hkcdStaticMeshTreeBase::s_zeroDistance.m_real = _mm_shuffle_ps(
                                                    (__m128)LODWORD(FLOAT_0_000099999997),
                                                    (__m128)LODWORD(FLOAT_0_000099999997),
                                                    0);
}

// File Line: 68
// RVA: 0xC97FB0
void __fastcall hkcdStaticMeshTreeBase::hkcdStaticMeshTreeBase(
        hkcdStaticMeshTreeBase *this,
        hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 72
// RVA: 0xC97FC0
void __fastcall hkcdStaticMeshTreeBase::initializeFilter(
        hkcdStaticMeshTreeBase *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *filter)
{
  int m_size; // edi
  int m_capacityAndFlags; // r8d
  int v5; // eax
  int v7; // r14d
  int v8; // ebp
  __int64 v9; // rdx
  unsigned int *v10; // rdi
  __int64 v11; // rcx
  int v12; // r9d
  hkcdStaticMeshTreeBase::Section *m_data; // rdx
  __int64 v14; // rdi
  int v15; // r11d
  unsigned int *v16; // r14
  int v17; // r10d
  int v18; // eax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = this->m_sections.m_size;
  m_capacityAndFlags = filter->m_capacityAndFlags;
  v5 = this->m_nodes.m_size + 31;
  filter->m_size = 0;
  v7 = v5 / 32;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      filter->m_data,
      4 * m_capacityAndFlags);
  v8 = v7 + 8 * m_size;
  filter->m_data = 0i64;
  filter->m_capacityAndFlags = 0x80000000;
  if ( v8 > 0 )
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&filter->m_data,
      v7 + 8 * m_size,
      4);
  v9 = filter->m_size;
  v10 = &filter->m_data[v9];
  v11 = v8 - (int)v9;
  if ( v8 - (int)v9 > 0 )
  {
    while ( v11 )
    {
      *v10++ = 0;
      --v11;
    }
  }
  filter->m_size = v8;
  v12 = 0;
  if ( this->m_sections.m_size > 0 )
  {
    m_data = this->m_sections.m_data;
    v14 = 0i64;
    do
    {
      v15 = 0;
      v16 = &filter->m_data[8 * v12];
      if ( LOBYTE(m_data[v14].m_primitives.m_data) )
      {
        v17 = 0;
        do
        {
          v18 = v17;
          ++v15;
          v17 += 2;
          v16[v18 / 32] = (3 << (v18 % 32)) | v16[v18 / 32] & ~(3 << (v18 % 32));
          m_data = this->m_sections.m_data;
        }
        while ( v15 < LOBYTE(m_data[v14].m_primitives.m_data) );
      }
      ++v12;
      ++v14;
    }
    while ( v12 < this->m_sections.m_size );
  }
  hkcdStaticMeshTreeBase::commitFilterChanges(this, filter);
}

// File Line: 100
// RVA: 0xC98130
void __fastcall hkcdStaticMeshTreeBase::setKeyFilter(
        hkcdStaticMeshTreeBase *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *filter,
        unsigned int key,
        bool enable)
{
  unsigned __int8 v4; // bl
  __int64 v5; // r8
  unsigned int *v6; // r14
  int v7; // r11d
  hkcdStaticMeshTreeBase::Primitive *m_data; // rax
  __int64 v9; // rdx
  int v10; // r8d
  hkcdStaticMeshTreeBase::Primitive *v11; // r10
  int v12; // edx
  int v13; // esi
  int v14; // r11d
  int v15; // eax
  int v16; // ecx
  int v17[6]; // [rsp+0h] [rbp-18h]

  v4 = key;
  v5 = key >> 8;
  v6 = &filter->m_data[8 * (_DWORD)v5];
  v7 = v4 >> 1;
  LODWORD(v5) = this->m_sections.m_data[v5].m_primitives.m_data;
  m_data = this->m_primitives.m_data;
  v17[0] = 0;
  v17[1] = 3;
  v17[3] = 3;
  v9 = (int)(v7 + ((unsigned int)v5 >> 8));
  v10 = 1;
  v11 = &m_data[v9];
  v17[2] = 1 << (v4 & 1);
  v12 = (unsigned __int8)v11->m_indices[3];
  v13 = 2 * v7 / 32;
  v14 = 2 * v7 % 32;
  v15 = (unsigned __int8)v11->m_indices[1];
  v16 = (unsigned __int8)v11->m_indices[2];
  if ( v12 == v16 )
  {
    if ( v16 == v15 )
      v10 = 3;
  }
  else if ( v11->m_indices[0] == -34 && v15 == 173 && v16 == 222 && v12 == 173 )
  {
    v10 = 0;
  }
  else
  {
    v10 = 2;
  }
  v6[v13] = v6[v13] & ~(3 << v14) | (((v6[v13] >> v14) & 3 & ~v17[v10] | (unsigned __int8)v17[v10] & (enable ? 3 : 0)) << v14);
}

// File Line: 112
// RVA: 0xC98270
bool __fastcall hkcdStaticMeshTreeBase::getKeyFilter(
        hkcdStaticMeshTreeBase *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *filter,
        unsigned int key)
{
  __int64 v4; // r11
  char v5; // r10
  int v6; // r9d
  unsigned int m_data; // r8d
  hkcdStaticMeshTreeBase::Primitive *v8; // rax
  char v9; // cl
  int v10; // r10d
  hkcdStaticMeshTreeBase::Primitive *v11; // rdi
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v16[6]; // [rsp+0h] [rbp-18h]

  v4 = key >> 8;
  v5 = key & 1;
  v6 = (unsigned __int8)key >> 1;
  m_data = this->m_sections.m_data[v4].m_primitives.m_data;
  v8 = this->m_primitives.m_data;
  v9 = v5;
  v10 = 1;
  v16[0] = 0;
  v16[1] = 3;
  v16[3] = 3;
  v11 = &v8[v6 + (m_data >> 8)];
  v16[2] = 1 << v9;
  v12 = (unsigned __int8)v11->m_indices[3];
  v13 = (unsigned __int8)v11->m_indices[2];
  v14 = (unsigned __int8)v11->m_indices[1];
  if ( v12 == v13 )
  {
    if ( v13 == v14 )
      v10 = 3;
  }
  else if ( v11->m_indices[0] == -34 && v14 == 173 && v13 == 222 && v12 == 173 )
  {
    v10 = 0;
  }
  else
  {
    v10 = 2;
  }
  return ((filter->m_data[2 * v6 / 32 + (__int64)(8 * (int)v4)] >> (2 * v6 % 32)) & 3 & v16[v10]) != 0;
}

// File Line: 123
// RVA: 0xC98380
void __fastcall hkcdStaticMeshTreeBase::setSectionFilter(
        hkcdStaticMeshTreeBase *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *filter,
        int section,
        bool enable)
{
  unsigned int *v4; // rbx
  hkcdStaticMeshTreeBase::Section *m_data; // rax
  __int64 v6; // rdx
  int v7; // r11d
  int v8; // r9d
  __int64 m_data_low; // r10
  int v10; // eax

  v4 = &filter->m_data[8 * section];
  m_data = this->m_sections.m_data;
  v6 = section;
  v7 = enable ? 3 : 0;
  if ( LOBYTE(m_data[v6].m_primitives.m_data) )
  {
    v8 = 0;
    m_data_low = LOBYTE(m_data[v6].m_primitives.m_data);
    do
    {
      v10 = v8;
      v8 += 2;
      v4[v10 / 32] = (v7 << (v10 % 32)) | v4[v10 / 32] & ~(3 << (v10 % 32));
      --m_data_low;
    }
    while ( m_data_low );
  }
}

// File Line: 135
// RVA: 0xC98410
bool __fastcall hkcdStaticMeshTreeBase::getSectionFilter(
        hkcdStaticMeshTreeBase *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *filter,
        int section)
{
  unsigned int *v3; // rdx

  v3 = &filter->m_data[8 * section];
  return (*v3 | v3[1] | v3[2] | v3[3] | v3[4] | v3[5] | v3[6] | v3[7]) != 0;
}

// File Line: 142
// RVA: 0xC98450
bool __fastcall hkcdStaticMeshTreeBase::commitFilterChanges(
        hkcdStaticMeshTreeBase *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *filter)
{
  int m_size; // r9d
  int v3; // edi
  unsigned int *v6; // r8
  hkcdStaticMeshTreeBase *v7; // r14
  __int64 v8; // rsi
  bool v9; // zf
  unsigned __int16 m_leafIndex; // ax

  m_size = this->m_sections.m_size;
  v3 = 0;
  v6 = (unsigned int *)(8 * m_size);
  v7 = (hkcdStaticMeshTreeBase *)&filter->m_data[(_QWORD)v6];
  if ( m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      ++v8;
      v9 = !hkcdStaticMeshTreeBase::getSectionFilter(this, filter, v3++);
      m_leafIndex = this->m_sections.m_data[v8 - 1].m_leafIndex;
      v6 = (unsigned int *)((char *)v7 + 4 * ((int)m_leafIndex >> 5));
      *v6 = (!v9 << (m_leafIndex & 0x1F)) | *v6 & ~(1 << (m_leafIndex & 0x1F));
    }
    while ( v3 < this->m_sections.m_size );
  }
  return hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(
           (hkcdStaticTree::Filtering<1> *)this,
           v7,
           v6);
}

// File Line: 155
// RVA: 0xC97CC0
void __fastcall hkcdStaticMeshTreeBase::Connectivity::reset(hkcdStaticMeshTreeBase::Connectivity *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d

  m_capacityAndFlags = this->m_headers.m_capacityAndFlags;
  this->m_headers.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_headers.m_data,
      8 * m_capacityAndFlags);
  this->m_headers.m_data = 0i64;
  this->m_headers.m_capacityAndFlags = 0x80000000;
  v3 = this->m_localLinks.m_capacityAndFlags;
  this->m_localLinks.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_localLinks.m_data,
      v3 & 0x3FFFFFFF);
  this->m_localLinks.m_data = 0i64;
  this->m_localLinks.m_capacityAndFlags = 0x80000000;
  v4 = this->m_globalLinks.m_capacityAndFlags;
  this->m_globalLinks.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_globalLinks.m_data,
      4 * v4);
  this->m_globalLinks.m_capacityAndFlags = 0x80000000;
  this->m_globalLinks.m_data = 0i64;
}

// File Line: 163
// RVA: 0xC97D80
__int64 __fastcall hkcdStaticMeshTreeBase::Connectivity::getMemoryFootPrint(hkcdStaticMeshTreeBase::Connectivity *this)
{
  return (unsigned int)(this->m_localLinks.m_size + 4 * (this->m_globalLinks.m_size + 12 + 2 * this->m_headers.m_size));
}

// File Line: 173
// RVA: 0xC97DA0
hkcdStaticMeshTreeBase::Edge *__fastcall hkcdStaticMeshTreeBase::Connectivity::link(
        hkcdStaticMeshTreeBase::Connectivity *this,
        hkcdStaticMeshTreeBase::Edge *result,
        hkcdStaticMeshTreeBase::Edge *e)
{
  unsigned __int64 v3; // r10
  signed int v6; // r8d
  hkcdStaticMeshTreeBase::Connectivity::SectionHeader *m_data; // r14
  char *v8; // r15
  unsigned int v9; // ebx
  int v10; // r11d
  int v11; // edi
  hkcdStaticMeshTreeBase::Connectivity::SectionHeader *v12; // rcx
  char *v13; // rbp
  unsigned int *v14; // rsi
  unsigned __int64 v15; // rax
  unsigned int v16; // eax
  char v17; // cl
  unsigned int v18; // edx
  unsigned __int8 v19; // r10

  v3 = (unsigned __int64)*e;
  v6 = *(unsigned int *)e >> 30;
  if ( v6 == 3 )
    goto LABEL_28;
  m_data = this->m_headers.m_data;
  v8 = this->m_localLinks.m_data;
  v9 = ((unsigned int)v3 >> 8) & 0x3FFFFF;
  v10 = v3 & 1;
  v11 = (unsigned __int8)v3 >> 1;
  v12 = &this->m_headers.m_data[v9];
  v13 = &v8[v12->m_baseLocal + 5 * v11];
  v14 = &this->m_globalLinks.m_data[(unsigned __int64)v12->m_baseGlobal >> 1];
  if ( (v12->m_baseGlobal & 1) != 0 )
  {
    if ( v8[5 * (((v3 & 0x3FFFFFFF) >> 1) & 0x7F) + 3 + m_data[(v3 & 0x3FFFFFFF) >> 8].m_baseLocal] == -1 )
    {
      v15 = v3 >> 30;
LABEL_12:
      v16 = v14[(unsigned int)(4 * v11) + v15];
      if ( v16 != -1 )
      {
        *result = (hkcdStaticMeshTreeBase::Edge)__ROR4__(v16, 2);
        return result;
      }
LABEL_28:
      *result = (hkcdStaticMeshTreeBase::Edge)-1;
      return result;
    }
    if ( (v3 & 1) == 0 )
    {
      if ( v6 == 2 )
      {
        *result = (hkcdStaticMeshTreeBase::Edge)((v3 + 1) & 0x3FFFFFFF);
        return result;
      }
      goto LABEL_10;
    }
    if ( v10 != 1 || v6 )
    {
LABEL_10:
      v15 = (unsigned int)(v6 + v10);
      goto LABEL_12;
    }
LABEL_9:
    *result = (hkcdStaticMeshTreeBase::Edge)((v3 - 1) & 0x3FFFFFFF | 0x80000000);
    return result;
  }
  if ( v8[5 * (((v3 & 0x3FFFFFFF) >> 1) & 0x7F) + 3 + m_data[(v3 & 0x3FFFFFFF) >> 8].m_baseLocal] != -1 )
  {
    if ( (v3 & 1) != 0 )
    {
      if ( v10 == 1 && !v6 )
        goto LABEL_9;
    }
    else if ( v6 == 2 )
    {
      *result = (hkcdStaticMeshTreeBase::Edge)((v3 + 1) & 0x3FFFFFFF);
      return result;
    }
    v6 += v10;
  }
  v17 = v13[v6];
  if ( v17 >= 0 )
    v18 = (v9 << 8) | (2 * (unsigned __int8)v17);
  else
    v18 = v14[v17 & 0x7F];
  if ( v18 == -1 )
    goto LABEL_28;
  v19 = ((unsigned __int8)v13[4] >> (2 * v6)) & 3;
  if ( v8[5 * ((unsigned __int8)v18 >> 1) + 3 + m_data[v18 >> 8].m_baseLocal] == -1 )
    *result = (hkcdStaticMeshTreeBase::Edge)(v18 & 0x3FFFFFFF | (v19 << 30));
  else
    *result = (hkcdStaticMeshTreeBase::Edge)((v18 | (v19 >> 1)) & 0x3FFFFFFF ^ (((v19 >> 1) + (v19 & 1)) << 30));
  return result;
}

