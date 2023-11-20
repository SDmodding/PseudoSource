// File Line: 13
// RVA: 0xE72010
void __fastcall hkDisplayConvex::hkDisplayConvex(hkDisplayConvex *this, hkGeometry *geom)
{
  this->m_geometry = 0i64;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = 6;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayConvex::`vftable;
  this->m_geometry = geom;
}

// File Line: 19
// RVA: 0xE72070
void __fastcall hkDisplayConvex::buildGeometry(hkDisplayConvex *this)
{
  ;
}

// File Line: 25
// RVA: 0xE72080
void __fastcall hkDisplayConvex::getWireframeGeometry(hkDisplayConvex *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  hkGeometry *v3; // rax
  hkMemoryAllocator *v4; // rdi
  hkArrayBase<hkVector4f> *v5; // rbx
  hkDisplayConvex *v6; // rsi
  int v7; // eax
  __int64 v8; // rbp
  signed __int64 v9; // r15
  hkGeometry *v10; // rcx
  hkGeometry::Triangle *v11; // rax
  hkVector4f *v12; // r13
  signed __int64 v13; // r12
  signed __int64 v14; // r14
  signed __int64 v15; // r12
  hkVector4f *v16; // r13
  __m128 *v17; // r14
  hkVector4f v18; // xmm0
  signed __int64 v19; // r14
  hkVector4f *v20; // r13
  hkVector4f *v21; // r12
  hkVector4f *v22; // r14
  int v23; // [rsp+50h] [rbp+8h]

  v3 = this->m_geometry;
  v4 = a;
  v5 = lines;
  v6 = this;
  if ( v3 )
  {
    v7 = v3->m_triangles.m_size - 1;
    v8 = v7;
    if ( v7 >= 0 )
    {
      v9 = v7;
      do
      {
        v10 = v6->m_geometry;
        v11 = v10->m_triangles.m_data;
        v12 = v10->m_vertices.m_data;
        v13 = v11[v9].m_b;
        v14 = v11[v9].m_a;
        v23 = v11[v9].m_c;
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(v4, v5, 16);
        v15 = v13;
        v5->m_data[v5->m_size++] = v12[v14];
        v16 = v6->m_geometry->m_vertices.m_data;
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(v4, v5, 16);
        v5->m_data[v5->m_size++] = v16[v15];
        v17 = &v6->m_geometry->m_vertices.m_data[v14].m_quad;
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(v4, v5, 16);
        v18.m_quad = *v17;
        v19 = v23;
        v5->m_data[v5->m_size++] = (hkVector4f)v18.m_quad;
        v20 = v6->m_geometry->m_vertices.m_data;
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(v4, v5, 16);
        v5->m_data[v5->m_size++] = v20[v19];
        v21 = &v6->m_geometry->m_vertices.m_data[v15];
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(v4, v5, 16);
        v5->m_data[v5->m_size++] = (hkVector4f)v21->m_quad;
        v22 = &v6->m_geometry->m_vertices.m_data[v19];
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(v4, v5, 16);
        --v9;
        v5->m_data[v5->m_size++] = (hkVector4f)v22->m_quad;
        --v8;
      }
      while ( v8 >= 0 );
    }
  }
}

