// File Line: 14
// RVA: 0xE725A0
void __fastcall hkDisplaySphere::hkDisplaySphere(hkDisplaySphere *this, hkSphere *sphere, int xRes, int yRes)
{
  hkDisplaySphere *v4; // rsi
  hkSphere *v5; // rdi
  __m128 v6; // xmm0

  v4 = this;
  v5 = sphere;
  this->m_memSizeAndFlags = -1;
  this->m_geometry = 0i64;
  this->m_referenceCount = 1;
  this->m_type = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySphere::`vftable';
  v6 = sphere->m_pos.m_quad;
  this->m_xRes = xRes;
  this->m_yRes = yRes;
  this->m_sphere.m_pos.m_quad = v6;
  hkRotationf::set(&this->m_transform.m_rotation, &qi);
  v4->m_transform.m_translation = (hkVector4f)v5->m_pos.m_quad;
}

// File Line: 20
// RVA: 0xE72C20
void __fastcall subdivideRecursive(hkGeometry *geometry, int triIndex, const float radius, float recursionsLeft)
{
  hkGeometry *v4; // rsi
  float v5; // xmm7_4
  float v6; // xmm8_4
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  __int64 *v8; // rdi
  __m128 v9; // xmm6
  int v10; // er9
  signed __int64 v11; // rbp
  int v12; // er9
  int v13; // eax
  int v14; // eax
  int v15; // er9
  int v16; // eax
  int v17; // eax
  hkVector4f *v18; // rax
  signed __int64 v19; // rdx
  signed __int64 v20; // r10
  signed __int64 v21; // r9
  signed __int64 v22; // rcx
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
  __int64 v34; // r9
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __int64 v37; // rax
  int v38; // er11
  int v39; // edi
  int v40; // ebx
  _DWORD *v41; // rdx
  _DWORD *v42; // rcx
  _DWORD *v43; // r8
  __int64 v44; // rdx
  hkResult result; // [rsp+30h] [rbp-C8h]
  hkResult v46; // [rsp+34h] [rbp-C4h]
  int v47; // [rsp+38h] [rbp-C0h]
  __int64 v48; // [rsp+40h] [rbp-B8h]
  __int64 v49; // [rsp+48h] [rbp-B0h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v50; // [rsp+50h] [rbp-A8h]
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v51; // [rsp+58h] [rbp-A0h]
  hkGeometry *geometrya; // [rsp+100h] [rbp+8h]
  int v53; // [rsp+118h] [rbp+20h]

  geometrya = geometry;
  v4 = geometry;
  v5 = recursionsLeft;
  v6 = radius;
  if ( recursionsLeft != 0.0 )
  {
    v7 = &geometry->m_vertices;
    v8 = (__int64 *)&geometry->m_triangles;
    v9 = _mm_shuffle_ps((__m128)LODWORD(radius), (__m128)LODWORD(radius), 0);
    v50 = &geometry->m_vertices;
    v51 = &geometry->m_triangles;
    v48 = 16i64 * triIndex;
    do
    {
      v10 = v7->m_size;
      v11 = v4->m_vertices.m_size;
      v47 = v4->m_triangles.m_size;
      v12 = v10 + 3;
      v13 = v7->m_capacityAndFlags & 0x3FFFFFFF;
      v53 = v11;
      if ( v13 >= v12 )
      {
        result.m_enum = 0;
      }
      else
      {
        v14 = 2 * v13;
        if ( v12 < v14 )
          v12 = v14;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v12, 16);
      }
      v7->m_size += 3;
      v15 = *((_DWORD *)v8 + 2) + 3;
      v16 = *((_DWORD *)v8 + 3) & 0x3FFFFFFF;
      if ( v16 >= v15 )
      {
        v46.m_enum = 0;
      }
      else
      {
        v17 = 2 * v16;
        if ( v15 < v17 )
          v15 = v17;
        hkArrayUtil::_reserve(&v46, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v15, 16);
      }
      *((_DWORD *)v8 + 2) += 3;
      v18 = v7->m_data;
      v49 = *v8;
      v19 = *(signed int *)(v48 + v49 + 4);
      v20 = *(signed int *)(v48 + v49);
      v21 = *(signed int *)(v48 + v49 + 8);
      v22 = v11;
      v23 = v11 + 1;
      v24 = _mm_add_ps(v18[*(signed int *)(v48 + v49 + 4)].m_quad, v18[*(signed int *)(v48 + v49)].m_quad);
      v25 = _mm_mul_ps(v24, v24);
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
              _mm_shuffle_ps(v25, v25, 170));
      v27 = _mm_rsqrt_ps(v26);
      v18[v22].m_quad = _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmpleps(v26, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                                _mm_mul_ps(*(__m128 *)_xmm, v27))),
                            v24),
                          v9);
      v28 = _mm_add_ps(v18[v21].m_quad, v18[v19].m_quad);
      v29 = _mm_mul_ps(v28, v28);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170));
      v31 = _mm_rsqrt_ps(v30);
      v18[v23].m_quad = _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmpleps(v30, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                                _mm_mul_ps(*(__m128 *)_xmm, v31))),
                            v28),
                          v9);
      v32 = _mm_add_ps(v18[v21].m_quad, v18[v20].m_quad);
      v33 = _mm_mul_ps(v32, v32);
      v34 = v49;
      v5 = v5 - 1.0;
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
              _mm_shuffle_ps(v33, v33, 170));
      v36 = _mm_rsqrt_ps(v35);
      v18[v53 + 2].m_quad = _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmpleps(v35, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v36))),
                                v32),
                              v9);
      v37 = *v8;
      v38 = v47;
      v39 = v47 + 1;
      v40 = v47 + 2;
      v41 = (_DWORD *)(v37 + 16i64 * v47);
      v42 = (_DWORD *)(v37 + 16i64 * (v47 + 2));
      v43 = (_DWORD *)(v37 + 16i64 * (v47 + 1));
      LODWORD(v37) = *(_DWORD *)(v48 + v34);
      v41[2] = v53 + 2;
      v41[1] = v53;
      *v41 = v37;
      v44 = v48;
      *v43 = v53;
      LODWORD(v37) = *(_DWORD *)(v44 + v34 + 4);
      v43[2] = v23;
      v43[1] = v37;
      *v42 = v53 + 2;
      v42[1] = v23;
      v42[2] = *(_DWORD *)(v44 + v34 + 8);
      *(_DWORD *)(v44 + v34 + 8) = v53 + 2;
      v4 = geometrya;
      *(_DWORD *)(v44 + v34) = v53;
      *(_DWORD *)(v44 + v34 + 4) = v23;
      subdivideRecursive(geometrya, v38, v6, v5);
      subdivideRecursive(geometrya, v39, v6, v5);
      subdivideRecursive(geometrya, v40, v6, v5);
      v7 = v50;
      v8 = (__int64 *)v51;
    }
    while ( v5 != 0.0 );
  }
}

// File Line: 70
// RVA: 0xE72660
void __fastcall hkDisplaySphere::buildGeometry(hkDisplaySphere *this)
{
  hkDisplaySphere *v1; // rdi
  _QWORD **v2; // rax
  __int64 v3; // rax
  int v4; // ebx
  __m128 v5; // xmm6
  int v6; // esi
  hkSimdFloat32 r; // [rsp+20h] [rbp-38h]

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 48i64);
  v4 = 0;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable';
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_DWORD *)(v3 + 24) = 0;
    *(_DWORD *)(v3 + 28) = 2147483648;
    *(_QWORD *)(v3 + 32) = 0i64;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 44) = 2147483648;
  }
  else
  {
    v3 = 0i64;
  }
  v1->m_geometry = (hkGeometry *)v3;
  v5 = _mm_shuffle_ps(v1->m_sphere.m_pos.m_quad, v1->m_sphere.m_pos.m_quad, 255);
  r.m_real = v5;
  hkDisplaySphere::buildIcosahedron((hkGeometry *)v3, &r);
  v6 = v1->m_geometry->m_triangles.m_size;
  if ( v6 > 0 )
  {
    do
      subdivideRecursive(v1->m_geometry, v4++, v5.m128_f32[0], 2.0);
    while ( v4 < v6 );
  }
}

// File Line: 87
// RVA: 0xE72740
void __fastcall hkDisplaySphere::getWireframeGeometry(hkDisplaySphere *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  ;
}

// File Line: 92
// RVA: 0xE72750
void __fastcall hkDisplaySphere::buildIcosahedron(hkGeometry *geomOut, hkSimdFloat32 *r)
{
  hkGeometry *v2; // rdi
  __m128 v3; // xmm7
  int v4; // eax
  __m128 v5; // xmm6
  int v6; // eax
  int v7; // er9
  __m128 *v8; // rax
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  int v18; // eax
  int v19; // eax
  int v20; // er9
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
  hkGeometry::Triangle *v37; // rax
  hkGeometry::Triangle *v38; // rax
  hkGeometry::Triangle *v39; // rax
  hkGeometry::Triangle *v40; // rax
  hkResult result; // [rsp+70h] [rbp+8h]

  v2 = geomOut;
  v3 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_52573109), (__m128)LODWORD(FLOAT_0_52573109), 0), r->m_real);
  result.m_enum = LODWORD(FLOAT_0_85065079);
  v4 = geomOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_85065079), (__m128)LODWORD(FLOAT_0_85065079), 0), r->m_real);
  if ( v4 < 12 )
  {
    v6 = 2 * v4;
    v7 = 12;
    if ( v6 > 12 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &geomOut->m_vertices,
      v7,
      16);
  }
  v8 = &v2->m_vertices.m_data->m_quad;
  v2->m_vertices.m_size = 12;
  v9 = _mm_unpacklo_ps(v5, aabbOut.m_quad);
  v10 = _mm_unpacklo_ps(v3, aabbOut.m_quad);
  v11 = _mm_sub_ps((__m128)0i64, v5);
  v12 = _mm_sub_ps((__m128)0i64, v3);
  v13 = _mm_unpacklo_ps(v12, aabbOut.m_quad);
  *v8 = _mm_movelh_ps(v13, v9);
  v2->m_vertices.m_data[1].m_quad = _mm_movelh_ps(v10, v9);
  v14 = _mm_unpacklo_ps(v11, aabbOut.m_quad);
  v2->m_vertices.m_data[2].m_quad = _mm_movelh_ps(v13, v14);
  v2->m_vertices.m_data[3].m_quad = _mm_movelh_ps(v10, v14);
  v15 = _mm_unpacklo_ps(aabbOut.m_quad, v5);
  v2->m_vertices.m_data[4].m_quad = _mm_movelh_ps(v15, v10);
  v2->m_vertices.m_data[5].m_quad = _mm_movelh_ps(v15, v13);
  v16 = _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad);
  v17 = _mm_unpacklo_ps(aabbOut.m_quad, v11);
  v2->m_vertices.m_data[6].m_quad = _mm_movelh_ps(v17, v10);
  v2->m_vertices.m_data[7].m_quad = _mm_movelh_ps(v17, v13);
  v2->m_vertices.m_data[8].m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v5, v3), v16);
  v2->m_vertices.m_data[9].m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v11, v3), v16);
  v2->m_vertices.m_data[10].m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v5, v12), v16);
  v2->m_vertices.m_data[11].m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v11, v12), v16);
  v18 = v2->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < 20 )
  {
    v19 = 2 * v18;
    v20 = 20;
    if ( v19 > 20 )
      v20 = v19;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_triangles,
      v20,
      16);
  }
  v21 = v2->m_triangles.m_data;
  v2->m_triangles.m_size = 20;
  v21->m_a = 1;
  *(_QWORD *)&v21->m_b = 4i64;
  v21->m_material = -1;
  v22 = v2->m_triangles.m_data;
  v22[1].m_a = 4;
  *(_QWORD *)&v22[1].m_b = 9i64;
  v22[1].m_material = -1;
  v23 = v2->m_triangles.m_data;
  v23[2].m_a = 4;
  v23[2].m_b = 5;
  v23[2].m_c = 9;
  v23[2].m_material = -1;
  v24 = v2->m_triangles.m_data;
  v24[3].m_a = 8;
  v24[3].m_b = 5;
  v24[3].m_c = 4;
  v24[3].m_material = -1;
  v25 = v2->m_triangles.m_data;
  v25[4].m_a = 1;
  v25[4].m_b = 8;
  v25[4].m_c = 4;
  v25[4].m_material = -1;
  v26 = v2->m_triangles.m_data;
  v26[5].m_a = 1;
  v26[5].m_b = 10;
  v26[5].m_c = 8;
  v26[5].m_material = -1;
  v27 = v2->m_triangles.m_data;
  v27[6].m_a = 10;
  v27[6].m_b = 3;
  v27[6].m_c = 8;
  v27[6].m_material = -1;
  v28 = v2->m_triangles.m_data;
  v28[7].m_a = 8;
  v28[7].m_b = 3;
  v28[7].m_c = 5;
  v28[7].m_material = -1;
  v29 = v2->m_triangles.m_data;
  v29[8].m_a = 3;
  v29[8].m_b = 2;
  v29[8].m_c = 5;
  v29[8].m_material = -1;
  v30 = v2->m_triangles.m_data;
  v30[9].m_a = 3;
  v30[9].m_b = 7;
  v30[9].m_c = 2;
  v30[9].m_material = -1;
  v31 = v2->m_triangles.m_data;
  v31[10].m_a = 3;
  v31[10].m_b = 10;
  v31[10].m_c = 7;
  v31[10].m_material = -1;
  v32 = v2->m_triangles.m_data;
  v32[11].m_a = 10;
  v32[11].m_b = 6;
  v32[11].m_c = 7;
  v32[11].m_material = -1;
  v33 = v2->m_triangles.m_data;
  v33[12].m_a = 6;
  v33[12].m_b = 11;
  v33[12].m_c = 7;
  v33[12].m_material = -1;
  v34 = v2->m_triangles.m_data;
  *(_QWORD *)&v34[13].m_a = 6i64;
  v34[13].m_c = 11;
  v34[13].m_material = -1;
  v35 = v2->m_triangles.m_data;
  v35[14].m_a = 6;
  *(_QWORD *)&v35[14].m_b = 1i64;
  v35[14].m_material = -1;
  v36 = v2->m_triangles.m_data;
  v36[15].m_a = 10;
  v36[15].m_b = 1;
  v36[15].m_c = 6;
  v36[15].m_material = -1;
  v37 = v2->m_triangles.m_data;
  *(_QWORD *)&v37[16].m_a = 11i64;
  v37[16].m_c = 9;
  v37[16].m_material = -1;
  v38 = v2->m_triangles.m_data;
  v38[17].m_a = 2;
  v38[17].m_b = 11;
  v38[17].m_c = 9;
  v38[17].m_material = -1;
  v39 = v2->m_triangles.m_data;
  v39[18].m_a = 5;
  v39[18].m_b = 2;
  v39[18].m_c = 9;
  v39[18].m_material = -1;
  v40 = v2->m_triangles.m_data;
  v40[19].m_a = 11;
  v40[19].m_b = 2;
  v40[19].m_c = 7;
  v40[19].m_material = -1;
}

