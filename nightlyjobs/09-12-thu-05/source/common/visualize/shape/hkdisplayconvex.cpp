// File Line: 13
// RVA: 0xE72010
void __fastcall hkDisplayConvex::hkDisplayConvex(hkDisplayConvex *this, hkGeometry *geom)
{
  this->m_geometry = 0i64;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = HK_DISPLAY_CONVEX;
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
void __fastcall hkDisplayConvex::getWireframeGeometry(
        hkDisplayConvex *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  hkGeometry *m_geometry; // rax
  int v7; // eax
  __int64 v8; // rbp
  __int64 v9; // r15
  hkGeometry *v10; // rcx
  hkGeometry::Triangle *m_data; // rax
  hkVector4f *v12; // r13
  __int64 m_b; // r12
  __int64 m_a; // r14
  __int64 v15; // r12
  hkVector4f *v16; // r13
  hkVector4f *v17; // r14
  hkVector4f *v18; // r13
  hkVector4f *v19; // r12
  hkVector4f *v20; // r14
  int m_c; // [rsp+50h] [rbp+8h]

  m_geometry = this->m_geometry;
  if ( m_geometry )
  {
    v7 = m_geometry->m_triangles.m_size - 1;
    v8 = v7;
    if ( v7 >= 0 )
    {
      v9 = v7;
      do
      {
        v10 = this->m_geometry;
        m_data = v10->m_triangles.m_data;
        v12 = v10->m_vertices.m_data;
        m_b = m_data[v9].m_b;
        m_a = m_data[v9].m_a;
        m_c = m_data[v9].m_c;
        if ( lines->m_size == (lines->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(a, (const void **)&lines->m_data, 16);
        v15 = m_b;
        lines->m_data[lines->m_size++] = v12[m_a];
        v16 = this->m_geometry->m_vertices.m_data;
        if ( lines->m_size == (lines->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(a, (const void **)&lines->m_data, 16);
        lines->m_data[lines->m_size++] = v16[v15];
        v17 = &this->m_geometry->m_vertices.m_data[m_a];
        if ( lines->m_size == (lines->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(a, (const void **)&lines->m_data, 16);
        lines->m_data[lines->m_size++] = (hkVector4f)v17->m_quad;
        v18 = this->m_geometry->m_vertices.m_data;
        if ( lines->m_size == (lines->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(a, (const void **)&lines->m_data, 16);
        lines->m_data[lines->m_size++] = v18[m_c];
        v19 = &this->m_geometry->m_vertices.m_data[v15];
        if ( lines->m_size == (lines->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(a, (const void **)&lines->m_data, 16);
        lines->m_data[lines->m_size++] = (hkVector4f)v19->m_quad;
        v20 = &this->m_geometry->m_vertices.m_data[m_c];
        if ( lines->m_size == (lines->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(a, (const void **)&lines->m_data, 16);
        --v9;
        lines->m_data[lines->m_size++] = (hkVector4f)v20->m_quad;
        --v8;
      }
      while ( v8 >= 0 );
    }
  }
}

