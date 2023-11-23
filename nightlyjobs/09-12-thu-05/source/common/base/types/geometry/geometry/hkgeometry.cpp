// File Line: 16
// RVA: 0xC6EF80
void __fastcall hkGeometry::hkGeometry(hkGeometry *this, hkGeometry *other)
{
  __int64 m_size; // rax
  hkVector4f *m_data; // rcx
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  __int64 v9; // rcx
  hkGeometry::Triangle *v10; // rax
  __int64 v11; // rdx
  char *v12; // r8
  int v13; // ecx
  int v14; // [rsp+30h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_triangles.m_capacityAndFlags = 0x80000000;
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < other->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        16 * this->m_vertices.m_capacityAndFlags);
    v14 = 16 * other->m_vertices.m_size;
    this->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              &hkContainerHeapAllocator::s_alloc,
                                              &v14);
    this->m_vertices.m_capacityAndFlags = v14 / 16;
  }
  m_size = other->m_vertices.m_size;
  m_data = this->m_vertices.m_data;
  this->m_vertices.m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)((char *)other->m_vertices.m_data - (char *)m_data);
    do
    {
      v8.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v7);
      m_data[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
  if ( (this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < other->m_triangles.m_size )
  {
    if ( this->m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_triangles.m_data,
        16 * this->m_triangles.m_capacityAndFlags);
    v14 = 16 * other->m_triangles.m_size;
    this->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                         &hkContainerHeapAllocator::s_alloc,
                                                         &v14);
    this->m_triangles.m_capacityAndFlags = v14 / 16;
  }
  v9 = other->m_triangles.m_size;
  v10 = this->m_triangles.m_data;
  this->m_triangles.m_size = v9;
  v11 = v9;
  if ( (int)v9 > 0 )
  {
    v12 = (char *)((char *)other->m_triangles.m_data - (char *)v10);
    do
    {
      v13 = *(int *)((char *)&v10->m_a + (_QWORD)v12);
      ++v10;
      v10[-1].m_a = v13;
      v10[-1].m_b = *(_DWORD *)((char *)v10 + (_QWORD)v12 - 12);
      v10[-1].m_c = *(_DWORD *)((char *)v10 + (_QWORD)v12 - 8);
      v10[-1].m_material = *(_DWORD *)((char *)v10 + (_QWORD)v12 - 4);
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 26
// RVA: 0xC6F110
void __fastcall hkGeometry::hkGeometry(hkGeometry *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
}

// File Line: 32
// RVA: 0xC6F130
void __fastcall hkGeometry::clear(hkGeometry *this)
{
  this->m_triangles.m_size = 0;
  this->m_vertices.m_size = 0;
}

// File Line: 39
// RVA: 0xC6F140
hkBool *__fastcall hkGeometry::isValid(hkGeometry *this, hkBool *result)
{
  unsigned int m_size; // r8d
  __int64 v3; // r9
  unsigned int v5; // r10d
  hkVector4f *m_data; // r11
  __int64 v7; // rcx
  hkGeometry::Triangle *v8; // rax

  m_size = this->m_vertices.m_size;
  v3 = 0i64;
  v5 = 0;
  if ( m_size )
  {
    m_data = this->m_vertices.m_data;
    while ( (_mm_movemask_ps(_mm_cmpunord_ps(m_data->m_quad, m_data->m_quad)) & 7) == 0 )
    {
      ++v5;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_5;
    }
    result->m_bool = 0;
    return result;
  }
  else
  {
LABEL_5:
    v7 = this->m_triangles.m_size;
    if ( v7 <= 0 )
    {
LABEL_11:
      result->m_bool = 1;
      return result;
    }
    else
    {
      v8 = this->m_triangles.m_data;
      while ( v8->m_a < m_size && v8->m_b < m_size && v8->m_c < m_size )
      {
        ++v3;
        ++v8;
        if ( v3 >= v7 )
          goto LABEL_11;
      }
      result->m_bool = 0;
      return result;
    }
  }
}

// File Line: 65
// RVA: 0xC6F1D0
hkResult *__fastcall hkGeometry::appendGeometry(
        hkGeometry *this,
        hkResult *result,
        hkGeometry *geometry,
        hkMatrix4f *transform)
{
  __int64 m_size; // rbx
  __int64 v5; // rdi
  int v7; // eax
  int v8; // r9d
  int v12; // eax
  int v13; // r9d
  int v14; // eax
  int v15; // eax
  int v16; // edx
  __int64 v17; // rcx
  hkVector4f *m_data; // rax
  __m128 m_quad; // xmm1
  __m128 v20; // xmm2
  __int64 v21; // rax
  hkResult resulta; // [rsp+70h] [rbp+8h] BYREF
  hkResult v24; // [rsp+80h] [rbp+18h] BYREF

  m_size = this->m_vertices.m_size;
  v5 = this->m_triangles.m_size;
  v7 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = m_size + geometry->m_vertices.m_size;
  if ( v7 >= v8 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v12 = 2 * v7;
    if ( v8 < v12 )
      v8 = v12;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_vertices.m_data, v8, 16);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  v13 = v5 + geometry->m_triangles.m_size;
  v14 = this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 >= v13 )
  {
    v24.m_enum = HK_SUCCESS;
  }
  else
  {
    v15 = 2 * v14;
    if ( v13 < v15 )
      v13 = v15;
    hkArrayUtil::_reserve(&v24, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_triangles.m_data, v13, 16);
    if ( v24.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  hkArrayBase<hkVector4f>::_append(
    &this->m_vertices,
    &hkContainerHeapAllocator::s_alloc,
    geometry->m_vertices.m_data,
    geometry->m_vertices.m_size);
  hkArrayBase<hkGeometry::Triangle>::_append(
    &this->m_triangles,
    &hkContainerHeapAllocator::s_alloc,
    geometry->m_triangles.m_data,
    geometry->m_triangles.m_size);
  if ( transform )
  {
    v16 = m_size;
    if ( (int)m_size < this->m_vertices.m_size )
    {
      v17 = m_size;
      do
      {
        m_data = this->m_vertices.m_data;
        ++v16;
        m_quad = m_data[v17++].m_quad;
        v20 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), transform->m_col0.m_quad),
                    transform->m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), transform->m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), transform->m_col2.m_quad));
        m_data[v17 - 1].m_quad = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, m_quad), 196);
      }
      while ( v16 < this->m_vertices.m_size );
    }
  }
  if ( (int)m_size > 0 && (int)v5 < this->m_triangles.m_size )
  {
    v21 = v5;
    do
    {
      LODWORD(v5) = v5 + 1;
      this->m_triangles.m_data[v21++].m_a += m_size;
      this->m_triangles.m_data[v21 - 1].m_b += m_size;
      this->m_triangles.m_data[v21 - 1].m_c += m_size;
    }
    while ( (int)v5 < this->m_triangles.m_size );
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

