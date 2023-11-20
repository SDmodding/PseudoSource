// File Line: 16
// RVA: 0xC6EF80
void __fastcall hkGeometry::hkGeometry(hkGeometry *this, hkGeometry *other)
{
  hkGeometry *v2; // rdi
  hkGeometry *v3; // rbx
  __int64 v4; // rax
  hkVector4f *v5; // rcx
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  __int64 v9; // rcx
  hkGeometry::Triangle *v10; // rax
  __int64 v11; // rdx
  char *v12; // r8
  int v13; // ecx
  int v14; // [rsp+30h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = other;
  this->vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  this->m_vertices.m_capacityAndFlags = 2147483648;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_triangles.m_capacityAndFlags = 2147483648;
  v3 = this;
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < other->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        16 * this->m_vertices.m_capacityAndFlags);
    v14 = 16 * v2->m_vertices.m_size;
    v3->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            &v14);
    v3->m_vertices.m_capacityAndFlags = v14 / 16;
  }
  v4 = v2->m_vertices.m_size;
  v5 = v3->m_vertices.m_data;
  v3->m_vertices.m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v2->m_vertices.m_data - (char *)v5);
    do
    {
      v8.m_quad = *(__m128 *)((char *)v5 + (_QWORD)v7);
      ++v5;
      v5[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
  if ( (v3->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < v2->m_triangles.m_size )
  {
    if ( v3->m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_triangles.m_data,
        16 * v3->m_triangles.m_capacityAndFlags);
    v14 = 16 * v2->m_triangles.m_size;
    v3->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                       &v14);
    v3->m_triangles.m_capacityAndFlags = v14 / 16;
  }
  v9 = v2->m_triangles.m_size;
  v10 = v3->m_triangles.m_data;
  v3->m_triangles.m_size = v9;
  v11 = v9;
  if ( (signed int)v9 > 0 )
  {
    v12 = (char *)((char *)v2->m_triangles.m_data - (char *)v10);
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
  this->vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
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
  unsigned int v2; // er8
  __int64 v3; // r9
  hkGeometry *v4; // rbx
  unsigned int v5; // er10
  hkVector4f *v6; // r11
  __int64 v7; // rcx
  hkGeometry::Triangle *v8; // rax
  hkBool *v9; // rax

  v2 = this->m_vertices.m_size;
  v3 = 0i64;
  v4 = this;
  v5 = 0;
  if ( v2 )
  {
    v6 = this->m_vertices.m_data;
    while ( !(_mm_movemask_ps(_mm_cmpunordps(v6->m_quad, v6->m_quad)) & 7) )
    {
      ++v5;
      ++v6;
      if ( v5 >= v2 )
        goto LABEL_5;
    }
    result->m_bool = 0;
    v9 = result;
  }
  else
  {
LABEL_5:
    v7 = this->m_triangles.m_size;
    if ( v7 <= 0 )
    {
LABEL_11:
      result->m_bool = 1;
      v9 = result;
    }
    else
    {
      v8 = v4->m_triangles.m_data;
      while ( v8->m_a < v2 && v8->m_b < v2 && v8->m_c < v2 )
      {
        ++v3;
        ++v8;
        if ( v3 >= v7 )
          goto LABEL_11;
      }
      result->m_bool = 0;
      v9 = result;
    }
  }
  return v9;
}

// File Line: 65
// RVA: 0xC6F1D0
hkResult *__fastcall hkGeometry::appendGeometry(hkGeometry *this, hkResult *result, hkGeometry *geometry, hkMatrix4f *transform)
{
  signed __int64 v4; // rbx
  signed __int64 v5; // rdi
  hkMatrix4f *v6; // r13
  int v7; // eax
  int v8; // er9
  hkGeometry *v9; // r15
  hkResult *v10; // r14
  hkGeometry *v11; // rbp
  int v12; // eax
  int v13; // er9
  int v14; // eax
  int v15; // eax
  int v16; // edx
  signed __int64 v17; // rcx
  hkVector4f *v18; // rax
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  signed __int64 v21; // rax
  hkResult resulta; // [rsp+70h] [rbp+8h]
  hkResult v24; // [rsp+80h] [rbp+18h]

  v4 = this->m_vertices.m_size;
  v5 = this->m_triangles.m_size;
  v6 = transform;
  v7 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = v4 + geometry->m_vertices.m_size;
  v9 = geometry;
  v10 = result;
  v11 = this;
  if ( v7 >= v8 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v12 = 2 * v7;
    if ( v8 < v12 )
      v8 = v12;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_vertices,
      v8,
      16);
    if ( resulta.m_enum )
    {
      v10->m_enum = 1;
      return v10;
    }
  }
  v13 = v5 + v9->m_triangles.m_size;
  v14 = v11->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 >= v13 )
  {
    v24.m_enum = 0;
  }
  else
  {
    v15 = 2 * v14;
    if ( v13 < v15 )
      v13 = v15;
    hkArrayUtil::_reserve(
      &v24,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v11->m_triangles,
      v13,
      16);
    if ( v24.m_enum )
    {
      v10->m_enum = 1;
      return v10;
    }
  }
  hkArrayBase<hkVector4f>::_append(
    (hkArrayBase<hkVector4f> *)&v11->m_vertices.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v9->m_vertices.m_data,
    v9->m_vertices.m_size);
  hkArrayBase<hkGeometry::Triangle>::_append(
    (hkArrayBase<hkGeometry::Triangle> *)&v11->m_triangles.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v9->m_triangles.m_data,
    v9->m_triangles.m_size);
  if ( v6 )
  {
    v16 = v4;
    if ( (signed int)v4 < v11->m_vertices.m_size )
    {
      v17 = v4;
      do
      {
        v18 = v11->m_vertices.m_data;
        ++v16;
        ++v17;
        v19 = v18[v17 - 1].m_quad;
        v20 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v6->m_col0.m_quad), v6->m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v18[v17 - 1].m_quad, v19, 85), v6->m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v6->m_col2.m_quad));
        v18[v17 - 1].m_quad = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, v18[v17 - 1].m_quad), 196);
      }
      while ( v16 < v11->m_vertices.m_size );
    }
  }
  if ( (signed int)v4 > 0 && (signed int)v5 < v11->m_triangles.m_size )
  {
    v21 = v5;
    do
    {
      LODWORD(v5) = v5 + 1;
      ++v21;
      v11->m_triangles.m_data[v21 - 1].m_a += v4;
      *((_DWORD *)&v11->m_triangles.m_data[v21] - 3) += v4;
      *((_DWORD *)&v11->m_triangles.m_data[v21] - 2) += v4;
    }
    while ( (signed int)v5 < v11->m_triangles.m_size );
  }
  v10->m_enum = 0;
  return v10;
}

