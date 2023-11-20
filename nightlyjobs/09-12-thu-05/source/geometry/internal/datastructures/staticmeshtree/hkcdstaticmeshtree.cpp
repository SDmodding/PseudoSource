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
void __fastcall hkcdStaticMeshTreeBase::hkcdStaticMeshTreeBase(hkcdStaticMeshTreeBase *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 72
// RVA: 0xC97FC0
void __fastcall hkcdStaticMeshTreeBase::initializeFilter(hkcdStaticMeshTreeBase *this, hkArray<unsigned int,hkContainerHeapAllocator> *filter)
{
  int v2; // edi
  hkArray<unsigned int,hkContainerHeapAllocator> *v3; // rsi
  int v4; // er8
  int v5; // eax
  hkcdStaticMeshTreeBase *v6; // rbx
  int v7; // er14
  int v8; // ebp
  int v9; // er9
  __int64 v10; // rdx
  unsigned int *v11; // rdi
  __int64 v12; // rcx
  int v13; // er9
  hkcdStaticMeshTreeBase::Section *v14; // rdx
  __int64 v15; // rdi
  signed int v16; // er11
  signed __int64 v17; // r14
  int v18; // er10
  int v19; // eax
  int v20; // edx
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = this->m_sections.m_size;
  v3 = filter;
  v4 = filter->m_capacityAndFlags;
  v5 = this->m_nodes.m_size + 31;
  v6 = this;
  filter->m_size = 0;
  v7 = v5 / 32;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      filter->m_data,
      4 * v4);
  v8 = v7 + 8 * v2;
  v3->m_data = 0i64;
  v3->m_capacityAndFlags = 2147483648;
  if ( v8 > 0 )
  {
    v9 = v7 + 8 * v2;
    if ( v8 < 0 )
      v9 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v9, 4);
  }
  v10 = v3->m_size;
  v11 = &v3->m_data[v10];
  v12 = v8 - (signed int)v10;
  if ( v8 - (signed int)v10 > 0 )
  {
    while ( v12 )
    {
      *v11 = 0;
      ++v11;
      --v12;
    }
  }
  v3->m_size = v8;
  v13 = 0;
  if ( v6->m_sections.m_size > 0 )
  {
    v14 = v6->m_sections.m_data;
    v15 = 0i64;
    do
    {
      v16 = 0;
      v17 = (signed __int64)&v3->m_data[8 * v13];
      if ( (signed int)LOBYTE(v14[v15].m_primitives.m_data) > 0 )
      {
        v18 = 0;
        do
        {
          v19 = v18;
          ++v16;
          v18 += 2;
          v20 = (v19 >> 31) & 0x1F;
          *(_DWORD *)(v17 + 4i64 * ((v20 + v19) >> 5)) = (3 << (((v20 + v19) & 0x1F) - v20)) | *(_DWORD *)(v17 + 4i64 * ((v20 + v19) >> 5)) & ~(3 << (((v20 + v19) & 0x1F) - v20));
          v14 = v6->m_sections.m_data;
        }
        while ( v16 < LOBYTE(v14[v15].m_primitives.m_data) );
      }
      ++v13;
      ++v15;
    }
    while ( v13 < v6->m_sections.m_size );
  }
  hkcdStaticMeshTreeBase::commitFilterChanges(v6, v3);
}

// File Line: 100
// RVA: 0xC98130
void __fastcall hkcdStaticMeshTreeBase::setKeyFilter(hkcdStaticMeshTreeBase *this, hkArray<unsigned int,hkContainerHeapAllocator> *filter, unsigned int key, bool enable)
{
  unsigned __int8 v4; // bl
  __int64 v5; // r8
  unsigned int *v6; // r14
  int v7; // er11
  hkcdStaticMeshTreeBase::Primitive *v8; // rax
  __int64 v9; // rdx
  signed int v10; // er8
  hkcdStaticMeshTreeBase::Primitive *v11; // r10
  int v12; // edx
  int v13; // esi
  char v14; // r11
  char v15; // cl
  int v16; // eax
  unsigned int v17; // ebx
  int v18; // ecx
  int v19; // ebx
  int v20; // [rsp+0h] [rbp-18h]
  int v21; // [rsp+4h] [rbp-14h]
  int v22; // [rsp+8h] [rbp-10h]
  int v23; // [rsp+Ch] [rbp-Ch]

  v4 = key;
  v5 = key >> 8;
  v6 = &filter->m_data[8 * (_DWORD)v5];
  v7 = v4 >> 1;
  LODWORD(v5) = this->m_sections.m_data[v5].m_primitives.m_data;
  v8 = this->m_primitives.m_data;
  v20 = 0;
  v21 = 3;
  v23 = 3;
  v9 = (signed int)(v7 + ((unsigned int)v5 >> 8));
  v10 = 1;
  v11 = &v8[v9];
  v22 = 1 << (v4 & 1);
  LODWORD(v8) = 2 * v7 % -32;
  v12 = (unsigned __int8)v11->m_indices[3];
  v13 = 2 * v7 / 32;
  v14 = (char)v8;
  v15 = (char)v8;
  v16 = (unsigned __int8)v11->m_indices[1];
  v17 = v6[v13] >> v15;
  v18 = (unsigned __int8)v11->m_indices[2];
  v19 = v17 & 3;
  if ( v12 == v18 )
  {
    if ( v18 == v16 )
      v10 = 3;
  }
  else if ( v11->m_indices[0] != -34 || v16 != 173 || v18 != 222 || v12 != 173 )
  {
    v10 = 2;
  }
  else
  {
    v10 = 0;
  }
  v6[v13] = v6[v13] & ~(3 << v14) | ((v19 & ~*(&v20 + v10) | (unsigned __int8)*(&v20 + v10) & (enable != 0 ? 3 : 0)) << v14);
}

// File Line: 112
// RVA: 0xC98270
bool __fastcall hkcdStaticMeshTreeBase::getKeyFilter(hkcdStaticMeshTreeBase *this, hkArray<unsigned int,hkContainerHeapAllocator> *filter, unsigned int key)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *v3; // rbx
  __int64 v4; // r11
  char v5; // r10
  int v6; // er9
  unsigned int v7; // er8
  hkcdStaticMeshTreeBase::Primitive *v8; // rax
  char v9; // cl
  signed int v10; // er10
  hkcdStaticMeshTreeBase::Primitive *v11; // rdi
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v16; // [rsp+0h] [rbp-18h]
  int v17; // [rsp+4h] [rbp-14h]
  int v18; // [rsp+8h] [rbp-10h]
  int v19; // [rsp+Ch] [rbp-Ch]

  v3 = filter;
  v4 = key >> 8;
  v5 = key & 1;
  v6 = (unsigned __int8)key >> 1;
  v7 = this->m_sections.m_data[v4].m_primitives.m_data;
  v8 = this->m_primitives.m_data;
  v9 = v5;
  v10 = 1;
  v16 = 0;
  v17 = 3;
  v19 = 3;
  v11 = &v8[v6 + (v7 >> 8)];
  v18 = 1 << v9;
  v12 = (unsigned __int8)v11->m_indices[3];
  v13 = (unsigned __int8)v11->m_indices[2];
  v14 = (unsigned __int8)v11->m_indices[1];
  if ( v12 == v13 )
  {
    if ( v13 == v14 )
      v10 = 3;
  }
  else if ( v11->m_indices[0] != -34 || v14 != 173 || v13 != 222 || v12 != 173 )
  {
    v10 = 2;
  }
  else
  {
    v10 = 0;
  }
  return ((v3->m_data[2 * v6 / 32 + (signed __int64)(8 * (signed int)v4)] >> (char)(2 * v6) % -32) & 3 & *(&v16 + v10)) != 0;
}

// File Line: 123
// RVA: 0xC98380
void __fastcall hkcdStaticMeshTreeBase::setSectionFilter(hkcdStaticMeshTreeBase *this, hkArray<unsigned int,hkContainerHeapAllocator> *filter, int section, bool enable)
{
  unsigned int *v4; // rbx
  unsigned int v5; // ecx
  int v6; // er11
  int v7; // er9
  __int64 v8; // r10
  int v9; // eax
  int v10; // edx

  v4 = &filter->m_data[8 * section];
  v5 = LOBYTE(this->m_sections.m_data[section].m_primitives.m_data);
  v6 = enable != 0 ? 3 : 0;
  if ( (signed int)v5 > 0 )
  {
    v7 = 0;
    v8 = v5;
    do
    {
      v9 = v7;
      v7 += 2;
      v10 = (v9 >> 31) & 0x1F;
      v4[(v10 + v9) >> 5] = (v6 << (((v10 + v9) & 0x1F) - v10)) | v4[(v10 + v9) >> 5] & ~(3 << (((v10 + v9) & 0x1F) - v10));
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 135
// RVA: 0xC98410
bool __fastcall hkcdStaticMeshTreeBase::getSectionFilter(hkcdStaticMeshTreeBase *this, hkArray<unsigned int,hkContainerHeapAllocator> *filter, int section)
{
  unsigned int *v3; // rdx

  v3 = &filter->m_data[8 * section];
  return (*v3 | v3[1] | v3[2] | v3[3] | v3[4] | v3[5] | v3[6] | v3[7]) != 0;
}

// File Line: 142
// RVA: 0xC98450
bool __fastcall hkcdStaticMeshTreeBase::commitFilterChanges(hkcdStaticMeshTreeBase *this, hkArray<unsigned int,hkContainerHeapAllocator> *filter)
{
  int v2; // er9
  int v3; // edi
  hkArray<unsigned int,hkContainerHeapAllocator> *v4; // r15
  hkcdStaticMeshTreeBase *v5; // rbx
  unsigned int *v6; // r8
  hkcdStaticMeshTreeBase *v7; // r14
  __int64 v8; // rsi
  bool v9; // zf
  __int16 v10; // ax

  v2 = this->m_sections.m_size;
  v3 = 0;
  v4 = filter;
  v5 = this;
  v6 = (unsigned int *)(8 * v2);
  v7 = (hkcdStaticMeshTreeBase *)&filter->m_data[(_QWORD)v6];
  if ( v2 > 0 )
  {
    v8 = 0i64;
    do
    {
      ++v8;
      v9 = hkcdStaticMeshTreeBase::getSectionFilter(v5, v4, v3++) == 0;
      v10 = *((_WORD *)&v5->m_sections.m_data[v8] - 3);
      v6 = (unsigned int *)((char *)v7 + 4 * ((signed int)*((unsigned __int16 *)&v5->m_sections.m_data[v8] - 3) >> 5));
      *v6 = (!v9 << (v10 & 0x1F)) | *v6 & ~(1 << (v10 & 0x1F));
    }
    while ( v3 < v5->m_sections.m_size );
  }
  return hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>((hkcdStaticTree::Filtering<1> *)v5, v7, v6);
}

// File Line: 155
// RVA: 0xC97CC0
void __fastcall hkcdStaticMeshTreeBase::Connectivity::reset(hkcdStaticMeshTreeBase::Connectivity *this)
{
  int v1; // er8
  hkcdStaticMeshTreeBase::Connectivity *v2; // rbx
  int v3; // er8
  int v4; // er8

  v1 = this->m_headers.m_capacityAndFlags;
  v2 = this;
  this->m_headers.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_headers.m_data,
      8 * v1);
  v2->m_headers.m_data = 0i64;
  v2->m_headers.m_capacityAndFlags = 2147483648;
  v3 = v2->m_localLinks.m_capacityAndFlags;
  v2->m_localLinks.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_localLinks.m_data,
      v3 & 0x3FFFFFFF);
  v2->m_localLinks.m_data = 0i64;
  v2->m_localLinks.m_capacityAndFlags = 2147483648;
  v4 = v2->m_globalLinks.m_capacityAndFlags;
  v2->m_globalLinks.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_globalLinks.m_data,
      4 * v4);
  v2->m_globalLinks.m_capacityAndFlags = 2147483648;
  v2->m_globalLinks.m_data = 0i64;
}

// File Line: 163
// RVA: 0xC97D80
__int64 __fastcall hkcdStaticMeshTreeBase::Connectivity::getMemoryFootPrint(hkcdStaticMeshTreeBase::Connectivity *this)
{
  return (unsigned int)(this->m_localLinks.m_size + 4 * (this->m_globalLinks.m_size + 12 + 2 * this->m_headers.m_size));
}

// File Line: 173
// RVA: 0xC97DA0
hkcdStaticMeshTreeBase::Edge *__fastcall hkcdStaticMeshTreeBase::Connectivity::link(hkcdStaticMeshTreeBase::Connectivity *this, hkcdStaticMeshTreeBase::Edge *result, hkcdStaticMeshTreeBase::Edge *e)
{
  unsigned __int64 v3; // r10
  hkcdStaticMeshTreeBase::Edge *v4; // r9
  hkcdStaticMeshTreeBase::Connectivity *v5; // rsi
  signed int v6; // er8
  hkcdStaticMeshTreeBase::Connectivity::SectionHeader *v7; // r14
  char *v8; // r15
  unsigned int v9; // ebx
  int v10; // er11
  int v11; // edi
  hkcdStaticMeshTreeBase::Connectivity::SectionHeader *v12; // rcx
  char *v13; // rbp
  unsigned __int64 v14; // rsi
  unsigned __int64 v15; // rax
  int v16; // eax
  unsigned __int8 v17; // cl
  unsigned int v18; // edx

  v3 = (unsigned __int64)*e;
  v4 = result;
  v5 = this;
  v6 = *(unsigned int *)e >> 30;
  if ( v6 == 3 )
    goto LABEL_28;
  v7 = this->m_headers.m_data;
  v8 = this->m_localLinks.m_data;
  v9 = ((unsigned int)v3 >> 8) & 0x3FFFFF;
  v10 = v3 & 1;
  v11 = (unsigned __int8)v3 >> 1;
  v12 = &this->m_headers.m_data[v9];
  v13 = &v8[v12->m_baseLocal + 5 * v11];
  v14 = (unsigned __int64)&v5->m_globalLinks.m_data[(unsigned __int64)v12->m_baseGlobal >> 1];
  if ( v12->m_baseGlobal & 1 )
  {
    if ( v8[5 * ((unsigned __int8)v3 >> 1) + 3 + v7[(v3 & 0x3FFFFFFF) >> 8].m_baseLocal] == -1 )
    {
      v15 = v3 >> 30;
LABEL_12:
      v16 = *(_DWORD *)(v14 + 4i64 * (unsigned int)(4 * v11) + 4 * v15);
      if ( v16 != -1 )
      {
        *result = (hkcdStaticMeshTreeBase::Edge)__ROR4__(v16, 2);
        return v4;
      }
LABEL_28:
      *v4 = (hkcdStaticMeshTreeBase::Edge)-1;
      return v4;
    }
    if ( !(v3 & 1) )
    {
      if ( v6 == 2 )
      {
        *result = (hkcdStaticMeshTreeBase::Edge)((v3 + 1) & 0x3FFFFFFF);
        return v4;
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
    return v4;
  }
  if ( v8[5 * ((unsigned __int8)v3 >> 1) + 3 + v7[(v3 & 0x3FFFFFFF) >> 8].m_baseLocal] != -1 )
  {
    if ( v3 & 1 )
    {
      if ( v10 == 1 && !v6 )
        goto LABEL_9;
    }
    else if ( v6 == 2 )
    {
      *result = (hkcdStaticMeshTreeBase::Edge)((v3 + 1) & 0x3FFFFFFF);
      return v4;
    }
    v6 += v10;
  }
  v17 = v13[v6];
  if ( (v17 & 0x80u) == 0 )
    v18 = (v9 << 8) | 2 * v17;
  else
    v18 = *(_DWORD *)(v14 + 4i64 * (v17 & 0x7F));
  if ( v18 == -1 )
    goto LABEL_28;
  if ( v8[5 * ((unsigned __int8)v18 >> 1) + 3 + v7[v18 >> 8].m_baseLocal] == -1 )
    *v4 = (hkcdStaticMeshTreeBase::Edge)(v18 & 0x3FFFFFFF | ((((unsigned __int8)v13[4] >> 2 * v6) & 3) << 30));
  else
    *v4 = (hkcdStaticMeshTreeBase::Edge)((v18 | ((((unsigned __int8)v13[4] >> 2 * v6) & 3u) >> 1)) & 0x3FFFFFFF ^ ((((((unsigned __int8)v13[4] >> 2 * v6) & 3u) >> 1) + (((unsigned __int8)v13[4] >> 2 * v6) & 1)) << 30));
  return v4;
}

