// File Line: 14
// RVA: 0xE725A0
void __fastcall hkDisplaySphere::hkDisplaySphere(hkDisplaySphere *this, hkSphere *sphere, int xRes, int yRes)
{
  __m128 m_quad; // xmm0

  this->m_memSizeAndFlags = -1;
  this->m_geometry = 0i64;
  this->m_referenceCount = 1;
  this->m_type = HK_DISPLAY_SPHERE;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySphere::`vftable;
  m_quad = sphere->m_pos.m_quad;
  this->m_xRes = xRes;
  this->m_yRes = yRes;
  this->m_sphere.m_pos.m_quad = m_quad;
  hkRotationf::set(&this->m_transform.m_rotation, &qi);
  this->m_transform.m_translation = (hkVector4f)sphere->m_pos.m_quad;
}

// File Line: 20
// RVA: 0xE72C20
void __fastcall subdivideRecursive(hkGeometry *geometry, int triIndex, float radius, float recursionsLeft)
{
  hkGeometry *v4; // rsi
  float v5; // xmm7_4
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rbx
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *p_m_triangles; // rdi
  __m128 v9; // xmm6
  int m_size; // r9d
  __int64 v11; // rbp
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  int v15; // r9d
  int v16; // eax
  int v17; // eax
  hkVector4f *m_data; // rax
  __int64 m_b; // rdx
  __int64 m_a; // r10
  __int64 m_c; // r9
  __int64 v22; // rcx
  int v23; // ebp
  __m128 v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  hkGeometry::Triangle *v34; // r9
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  hkGeometry::Triangle *v37; // rax
  int v38; // r11d
  int v39; // edi
  int v40; // ebx
  hkGeometry::Triangle *v41; // rdx
  hkGeometry::Triangle *v42; // rcx
  hkGeometry::Triangle *v43; // r8
  __int64 v44; // rdx
  hkResult result; // [rsp+30h] [rbp-C8h] BYREF
  hkResult v46; // [rsp+34h] [rbp-C4h] BYREF
  int v47; // [rsp+38h] [rbp-C0h]
  unsigned __int64 v48; // [rsp+40h] [rbp-B8h]
  hkGeometry::Triangle *v49; // [rsp+48h] [rbp-B0h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v50; // [rsp+50h] [rbp-A8h]
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v51; // [rsp+58h] [rbp-A0h]
  int v53; // [rsp+118h] [rbp+20h]

  v4 = geometry;
  v5 = recursionsLeft;
  if ( recursionsLeft != 0.0 )
  {
    p_m_vertices = &geometry->m_vertices;
    p_m_triangles = &geometry->m_triangles;
    v9 = _mm_shuffle_ps((__m128)LODWORD(radius), (__m128)LODWORD(radius), 0);
    v50 = &geometry->m_vertices;
    v51 = &geometry->m_triangles;
    v48 = 16i64 * triIndex;
    do
    {
      m_size = p_m_vertices->m_size;
      v11 = v4->m_vertices.m_size;
      v47 = v4->m_triangles.m_size;
      v12 = m_size + 3;
      v13 = p_m_vertices->m_capacityAndFlags & 0x3FFFFFFF;
      v53 = v11;
      if ( v13 >= v12 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v14 = 2 * v13;
        if ( v12 < v14 )
          v12 = v14;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&p_m_vertices->m_data,
          v12,
          16);
      }
      p_m_vertices->m_size += 3;
      v15 = p_m_triangles->m_size + 3;
      v16 = p_m_triangles->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v16 >= v15 )
      {
        v46.m_enum = HK_SUCCESS;
      }
      else
      {
        v17 = 2 * v16;
        if ( v15 < v17 )
          v15 = v17;
        hkArrayUtil::_reserve(&v46, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_triangles->m_data, v15, 16);
      }
      p_m_triangles->m_size += 3;
      m_data = p_m_vertices->m_data;
      v49 = p_m_triangles->m_data;
      m_b = v49[v48 / 0x10].m_b;
      m_a = v49[v48 / 0x10].m_a;
      m_c = v49[v48 / 0x10].m_c;
      v22 = v11;
      v23 = v11 + 1;
      v24 = _mm_add_ps(m_data[v49[v48 / 0x10].m_b].m_quad, m_data[v49[v48 / 0x10].m_a].m_quad);
      v25 = _mm_mul_ps(v24, v24);
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
              _mm_shuffle_ps(v25, v25, 170));
      v27 = _mm_rsqrt_ps(v26);
      m_data[v22].m_quad = _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_andnot_ps(
                                 _mm_cmple_ps(v26, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v27))),
                               v24),
                             v9);
      v28 = _mm_add_ps(m_data[m_c].m_quad, m_data[m_b].m_quad);
      v29 = _mm_mul_ps(v28, v28);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170));
      v31 = _mm_rsqrt_ps(v30);
      m_data[v23].m_quad = _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_andnot_ps(
                                 _mm_cmple_ps(v30, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v31))),
                               v28),
                             v9);
      v32 = _mm_add_ps(m_data[m_c].m_quad, m_data[m_a].m_quad);
      v33 = _mm_mul_ps(v32, v32);
      v34 = v49;
      v5 = v5 - 1.0;
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
              _mm_shuffle_ps(v33, v33, 170));
      v36 = _mm_rsqrt_ps(v35);
      m_data[v53 + 2].m_quad = _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_andnot_ps(
                                     _mm_cmple_ps(v35, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                                       _mm_mul_ps(*(__m128 *)_xmm, v36))),
                                   v32),
                                 v9);
      v37 = p_m_triangles->m_data;
      v38 = v47;
      v39 = v47 + 1;
      v40 = v47 + 2;
      v41 = &v37[v47];
      v42 = &v37[v47 + 2];
      v43 = &v37[v47 + 1];
      LODWORD(v37) = v34[v48 / 0x10].m_a;
      v41->m_c = v53 + 2;
      v41->m_b = v53;
      v41->m_a = (int)v37;
      v44 = v48;
      v43->m_a = v53;
      LODWORD(v37) = *(int *)((char *)&v34->m_b + v44);
      v43->m_c = v23;
      v43->m_b = (int)v37;
      v42->m_a = v53 + 2;
      v42->m_b = v23;
      v42->m_c = *(int *)((char *)&v34->m_c + v44);
      *(int *)((char *)&v34->m_c + v44) = v53 + 2;
      v4 = geometry;
      *(int *)((char *)&v34->m_a + v44) = v53;
      *(int *)((char *)&v34->m_b + v44) = v23;
      subdivideRecursive(geometry, v38, radius, v5);
      subdivideRecursive(geometry, v39, radius, v5);
      subdivideRecursive(geometry, v40, radius, v5);
      p_m_vertices = v50;
      p_m_triangles = v51;
    }
    while ( v5 != 0.0 );
  }
}

// File Line: 70
// RVA: 0xE72660
void __fastcall hkDisplaySphere::buildGeometry(hkDisplaySphere *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  int v4; // ebx
  __m128 v5; // xmm6
  int m_size; // esi
  hkSimdFloat32 r; // [rsp+20h] [rbp-38h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v4 = 0;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_DWORD *)(v3 + 24) = 0;
    *(_DWORD *)(v3 + 28) = 0x80000000;
    *(_QWORD *)(v3 + 32) = 0i64;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 44) = 0x80000000;
  }
  else
  {
    v3 = 0i64;
  }
  this->m_geometry = (hkGeometry *)v3;
  v5 = _mm_shuffle_ps(this->m_sphere.m_pos.m_quad, this->m_sphere.m_pos.m_quad, 255);
  r.m_real = v5;
  hkDisplaySphere::buildIcosahedron((hkGeometry *)v3, &r);
  m_size = this->m_geometry->m_triangles.m_size;
  if ( m_size > 0 )
  {
    do
      subdivideRecursive(this->m_geometry, v4++, v5.m128_f32[0], 2.0);
    while ( v4 < m_size );
  }
}

// File Line: 87
// RVA: 0xE72740
void __fastcall hkDisplaySphere::getWireframeGeometry(
        hkDisplaySphere *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  ;
}

// File Line: 92
// RVA: 0xE72750
void __fastcall hkDisplaySphere::buildIcosahedron(hkGeometry *geomOut, hkSimdFloat32 *r)
{
  __m128 v3; // xmm7
  __m128 v4; // xmm6
  int v5; // r9d
  hkVector4f *m_data; // rax
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm5
  __m128 v10; // xmm4
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm8
  __m128 v15; // xmm1
  int v16; // r9d
  hkGeometry::Triangle *v17; // rax
  hkGeometry::Triangle *v18; // rax
  hkGeometry::Triangle *v19; // rax
  hkGeometry::Triangle *v20; // rax
  hkGeometry::Triangle *v21; // rax
  hkGeometry::Triangle *v22; // rax
  hkGeometry::Triangle *v23; // rax
  hkGeometry::Triangle *v24; // rax
  hkGeometry::Triangle *v25; // rax
  hkGeometry::Triangle *v26; // rax
  hkGeometry::Triangle *v27; // rax
  hkGeometry::Triangle *v28; // rax
  hkGeometry::Triangle *v29; // rax
  hkGeometry::Triangle *v30; // rax
  hkGeometry::Triangle *v31; // rax
  hkGeometry::Triangle *v32; // rax
  hkGeometry::Triangle *v33; // rax
  hkGeometry::Triangle *v34; // rax
  hkGeometry::Triangle *v35; // rax
  hkGeometry::Triangle *v36; // rax
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  v3 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_52573109), (__m128)LODWORD(FLOAT_0_52573109), 0), r->m_real);
  result.m_enum = LODWORD(FLOAT_0_85065079);
  v4 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_85065079), (__m128)LODWORD(FLOAT_0_85065079), 0), r->m_real);
  if ( (geomOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFFu) < 0xC )
  {
    v5 = 12;
    if ( 2 * (geomOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) > 12 )
      v5 = 2 * (geomOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&geomOut->m_vertices.m_data,
      v5,
      16);
  }
  m_data = geomOut->m_vertices.m_data;
  geomOut->m_vertices.m_size = 12;
  v7 = _mm_unpacklo_ps(v4, aabbOut.m_quad);
  v8 = _mm_unpacklo_ps(v3, aabbOut.m_quad);
  v9 = _mm_sub_ps((__m128)0i64, v4);
  v10 = _mm_sub_ps((__m128)0i64, v3);
  v11 = _mm_unpacklo_ps(v10, aabbOut.m_quad);
  m_data->m_quad = _mm_movelh_ps(v11, v7);
  geomOut->m_vertices.m_data[1].m_quad = _mm_movelh_ps(v8, v7);
  v12 = _mm_unpacklo_ps(v9, aabbOut.m_quad);
  geomOut->m_vertices.m_data[2].m_quad = _mm_movelh_ps(v11, v12);
  geomOut->m_vertices.m_data[3].m_quad = _mm_movelh_ps(v8, v12);
  v13 = _mm_unpacklo_ps(aabbOut.m_quad, v4);
  geomOut->m_vertices.m_data[4].m_quad = _mm_movelh_ps(v13, v8);
  geomOut->m_vertices.m_data[5].m_quad = _mm_movelh_ps(v13, v11);
  v14 = _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad);
  v15 = _mm_unpacklo_ps(aabbOut.m_quad, v9);
  geomOut->m_vertices.m_data[6].m_quad = _mm_movelh_ps(v15, v8);
  geomOut->m_vertices.m_data[7].m_quad = _mm_movelh_ps(v15, v11);
  geomOut->m_vertices.m_data[8].m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v4, v3), v14);
  geomOut->m_vertices.m_data[9].m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v9, v3), v14);
  geomOut->m_vertices.m_data[10].m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v4, v10), v14);
  geomOut->m_vertices.m_data[11].m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v9, v10), v14);
  if ( (geomOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFFu) < 0x14 )
  {
    v16 = 20;
    if ( 2 * (geomOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) > 20 )
      v16 = 2 * (geomOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&geomOut->m_triangles.m_data,
      v16,
      16);
  }
  v17 = geomOut->m_triangles.m_data;
  geomOut->m_triangles.m_size = 20;
  v17->m_a = 1;
  *(_QWORD *)&v17->m_b = 4i64;
  v17->m_material = -1;
  v18 = geomOut->m_triangles.m_data;
  v18[1].m_a = 4;
  *(_QWORD *)&v18[1].m_b = 9i64;
  v18[1].m_material = -1;
  v19 = geomOut->m_triangles.m_data;
  v19[2].m_a = 4;
  v19[2].m_b = 5;
  v19[2].m_c = 9;
  v19[2].m_material = -1;
  v20 = geomOut->m_triangles.m_data;
  v20[3].m_a = 8;
  v20[3].m_b = 5;
  v20[3].m_c = 4;
  v20[3].m_material = -1;
  v21 = geomOut->m_triangles.m_data;
  v21[4].m_a = 1;
  v21[4].m_b = 8;
  v21[4].m_c = 4;
  v21[4].m_material = -1;
  v22 = geomOut->m_triangles.m_data;
  v22[5].m_a = 1;
  v22[5].m_b = 10;
  v22[5].m_c = 8;
  v22[5].m_material = -1;
  v23 = geomOut->m_triangles.m_data;
  v23[6].m_a = 10;
  v23[6].m_b = 3;
  v23[6].m_c = 8;
  v23[6].m_material = -1;
  v24 = geomOut->m_triangles.m_data;
  v24[7].m_a = 8;
  v24[7].m_b = 3;
  v24[7].m_c = 5;
  v24[7].m_material = -1;
  v25 = geomOut->m_triangles.m_data;
  v25[8].m_a = 3;
  v25[8].m_b = 2;
  v25[8].m_c = 5;
  v25[8].m_material = -1;
  v26 = geomOut->m_triangles.m_data;
  v26[9].m_a = 3;
  v26[9].m_b = 7;
  v26[9].m_c = 2;
  v26[9].m_material = -1;
  v27 = geomOut->m_triangles.m_data;
  v27[10].m_a = 3;
  v27[10].m_b = 10;
  v27[10].m_c = 7;
  v27[10].m_material = -1;
  v28 = geomOut->m_triangles.m_data;
  v28[11].m_a = 10;
  v28[11].m_b = 6;
  v28[11].m_c = 7;
  v28[11].m_material = -1;
  v29 = geomOut->m_triangles.m_data;
  v29[12].m_a = 6;
  v29[12].m_b = 11;
  v29[12].m_c = 7;
  v29[12].m_material = -1;
  v30 = geomOut->m_triangles.m_data;
  *(_QWORD *)&v30[13].m_a = 6i64;
  v30[13].m_c = 11;
  v30[13].m_material = -1;
  v31 = geomOut->m_triangles.m_data;
  v31[14].m_a = 6;
  *(_QWORD *)&v31[14].m_b = 1i64;
  v31[14].m_material = -1;
  v32 = geomOut->m_triangles.m_data;
  v32[15].m_a = 10;
  v32[15].m_b = 1;
  v32[15].m_c = 6;
  v32[15].m_material = -1;
  v33 = geomOut->m_triangles.m_data;
  *(_QWORD *)&v33[16].m_a = 11i64;
  v33[16].m_c = 9;
  v33[16].m_material = -1;
  v34 = geomOut->m_triangles.m_data;
  v34[17].m_a = 2;
  v34[17].m_b = 11;
  v34[17].m_c = 9;
  v34[17].m_material = -1;
  v35 = geomOut->m_triangles.m_data;
  v35[18].m_a = 5;
  v35[18].m_b = 2;
  v35[18].m_c = 9;
  v35[18].m_material = -1;
  v36 = geomOut->m_triangles.m_data;
  v36[19].m_a = 11;
  v36[19].m_b = 2;
  v36[19].m_c = 7;
  v36[19].m_material = -1;
}

