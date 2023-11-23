// File Line: 15
// RVA: 0xE71240
void __fastcall hkDisplayAABB::hkDisplayAABB(hkDisplayAABB *this, hkVector4f *min, hkVector4f *max)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_AABB;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayAABB::`vftable;
  this->m_minExtent = (hkVector4f)min->m_quad;
  this->m_maxExtent = (hkVector4f)max->m_quad;
}

// File Line: 20
// RVA: 0xE711D0
void __fastcall hkDisplayAABB::hkDisplayAABB(hkDisplayAABB *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_AABB;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->m_minExtent = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayAABB::`vftable;
  this->m_maxExtent = 0i64;
}

// File Line: 28
// RVA: 0xE71F70
void __fastcall hkDisplayAABB::setExtents(hkDisplayAABB *this, hkVector4f *min, hkVector4f *max)
{
  this->m_minExtent = (hkVector4f)min->m_quad;
  this->m_maxExtent = (hkVector4f)max->m_quad;
}

// File Line: 35
// RVA: 0xE712B0
void __fastcall hkDisplayAABB::buildGeometry(hkDisplayAABB *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  __int64 v4; // rsi
  __int64 v5; // rbp
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  hkGeometry *m_geometry; // rsi
  __int64 m_size; // rbp
  int v11; // r9d
  int v12; // eax
  int v13; // eax
  hkGeometry *v14; // rsi
  __int64 v15; // rbp
  int v16; // r9d
  int v17; // eax
  int v18; // eax
  hkGeometry *v19; // rsi
  __int64 v20; // rbp
  int v21; // r9d
  int v22; // eax
  int v23; // eax
  hkGeometry *v24; // rsi
  __int64 v25; // rbp
  int v26; // r9d
  int v27; // eax
  int v28; // eax
  hkGeometry *v29; // rsi
  __int64 v30; // rbp
  int v31; // r9d
  int v32; // eax
  int v33; // eax
  hkGeometry *v34; // rsi
  __int64 v35; // rbp
  int v36; // r9d
  int v37; // eax
  int v38; // eax
  hkGeometry *v39; // rsi
  __int64 v40; // rbp
  int v41; // r9d
  int v42; // eax
  int v43; // eax
  hkGeometry *v44; // rsi
  __int64 v45; // rbp
  int v46; // r9d
  int v47; // eax
  int v48; // eax
  hkGeometry::Triangle *v49; // rax
  hkGeometry *v50; // rsi
  __int64 v51; // rbp
  int v52; // r9d
  int v53; // eax
  int v54; // eax
  hkGeometry::Triangle *v55; // rax
  hkGeometry *v56; // rsi
  __int64 v57; // rbp
  int v58; // r9d
  int v59; // eax
  int v60; // eax
  hkGeometry::Triangle *v61; // rax
  hkGeometry *v62; // rsi
  __int64 v63; // rbp
  int v64; // r9d
  int v65; // eax
  int v66; // eax
  hkGeometry::Triangle *v67; // rax
  hkGeometry *v68; // rsi
  __int64 v69; // rbp
  int v70; // r9d
  int v71; // eax
  int v72; // eax
  hkGeometry::Triangle *v73; // rax
  hkGeometry *v74; // rsi
  __int64 v75; // rbp
  int v76; // r9d
  int v77; // eax
  int v78; // eax
  hkGeometry::Triangle *v79; // rax
  hkGeometry *v80; // rsi
  __int64 v81; // rbp
  int v82; // r9d
  int v83; // eax
  int v84; // eax
  __int64 v85; // rax
  hkGeometry *v86; // rsi
  __int64 v87; // rbp
  int v88; // r9d
  int v89; // eax
  int v90; // eax
  hkGeometry::Triangle *v91; // rax
  hkGeometry *v92; // rsi
  __int64 v93; // rbp
  int v94; // r9d
  int v95; // eax
  int v96; // eax
  hkGeometry::Triangle *v97; // rax
  hkGeometry *v98; // rdi
  __int64 v99; // rsi
  int v100; // r9d
  int v101; // eax
  int v102; // eax
  hkGeometry::Triangle *v103; // rax
  hkGeometry *v104; // rdi
  __int64 v105; // rsi
  int v106; // r9d
  int v107; // eax
  int v108; // eax
  hkGeometry::Triangle *v109; // rax
  hkGeometry *v110; // rbx
  __int64 v111; // rdi
  int v112; // r9d
  int v113; // eax
  int v114; // eax
  hkGeometry::Triangle *v115; // rax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
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
  v4 = v3 + 16;
  this->m_geometry = (hkGeometry *)v3;
  v5 = *(int *)(v3 + 24);
  v6 = v5 + 1;
  v7 = *(_DWORD *)(v3 + 28) & 0x3FFFFFFF;
  if ( v7 < (int)v5 + 1 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)v4, v6, 16);
  }
  ++*(_DWORD *)(v4 + 8);
  *(__m128 *)(*(_QWORD *)v4 + 16 * v5) = _mm_unpacklo_ps(
                                           _mm_unpacklo_ps(
                                             (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                             (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                                           _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  m_geometry = this->m_geometry;
  m_size = m_geometry->m_vertices.m_size;
  v11 = m_size + 1;
  v12 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < (int)m_size + 1 )
  {
    v13 = 2 * v12;
    if ( v11 < v13 )
      v11 = v13;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&m_geometry->m_vertices.m_data,
      v11,
      16);
  }
  ++m_geometry->m_vertices.m_size;
  m_geometry->m_vertices.m_data[m_size].m_quad = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                                     (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                                                   _mm_unpacklo_ps(
                                                     (__m128)this->m_minExtent.m_quad.m128_u32[1],
                                                     (__m128)0i64));
  v14 = this->m_geometry;
  v15 = v14->m_vertices.m_size;
  v16 = v15 + 1;
  v17 = v14->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < (int)v15 + 1 )
  {
    v18 = 2 * v17;
    if ( v16 < v18 )
      v16 = v18;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v14->m_vertices.m_data, v16, 16);
  }
  ++v14->m_vertices.m_size;
  v14->m_vertices.m_data[v15].m_quad = _mm_unpacklo_ps(
                                         _mm_unpacklo_ps(
                                           (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                           (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                                         _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  v19 = this->m_geometry;
  v20 = v19->m_vertices.m_size;
  v21 = v20 + 1;
  v22 = v19->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < (int)v20 + 1 )
  {
    v23 = 2 * v22;
    if ( v21 < v23 )
      v21 = v23;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v19->m_vertices.m_data, v21, 16);
  }
  ++v19->m_vertices.m_size;
  v19->m_vertices.m_data[v20].m_quad = _mm_unpacklo_ps(
                                         _mm_unpacklo_ps(
                                           (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                           (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                                         _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  v24 = this->m_geometry;
  v25 = v24->m_vertices.m_size;
  v26 = v25 + 1;
  v27 = v24->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v27 < (int)v25 + 1 )
  {
    v28 = 2 * v27;
    if ( v26 < v28 )
      v26 = v28;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v24->m_vertices.m_data, v26, 16);
  }
  ++v24->m_vertices.m_size;
  v24->m_vertices.m_data[v25].m_quad = _mm_unpacklo_ps(
                                         _mm_unpacklo_ps(
                                           (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                           (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                                         _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  v29 = this->m_geometry;
  v30 = v29->m_vertices.m_size;
  v31 = v30 + 1;
  v32 = v29->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v32 < (int)v30 + 1 )
  {
    v33 = 2 * v32;
    if ( v31 < v33 )
      v31 = v33;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v29->m_vertices.m_data, v31, 16);
  }
  ++v29->m_vertices.m_size;
  v29->m_vertices.m_data[v30].m_quad = _mm_unpacklo_ps(
                                         _mm_unpacklo_ps(
                                           (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                           (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                                         _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  v34 = this->m_geometry;
  v35 = v34->m_vertices.m_size;
  v36 = v35 + 1;
  v37 = v34->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v37 < (int)v35 + 1 )
  {
    v38 = 2 * v37;
    if ( v36 < v38 )
      v36 = v38;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v34->m_vertices.m_data, v36, 16);
  }
  ++v34->m_vertices.m_size;
  v34->m_vertices.m_data[v35].m_quad = _mm_unpacklo_ps(
                                         _mm_unpacklo_ps(
                                           (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                           (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                                         _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  v39 = this->m_geometry;
  v40 = v39->m_vertices.m_size;
  v41 = v40 + 1;
  v42 = v39->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v42 < (int)v40 + 1 )
  {
    v43 = 2 * v42;
    if ( v41 < v43 )
      v41 = v43;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v39->m_vertices.m_data, v41, 16);
  }
  ++v39->m_vertices.m_size;
  v39->m_vertices.m_data[v40].m_quad = _mm_unpacklo_ps(
                                         _mm_unpacklo_ps(
                                           (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                           (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                                         _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  v44 = this->m_geometry;
  v45 = v44->m_triangles.m_size;
  v46 = v45 + 1;
  v47 = v44->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v47 < (int)v45 + 1 )
  {
    v48 = 2 * v47;
    if ( v46 < v48 )
      v46 = v48;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v44->m_triangles.m_data, v46, 16);
  }
  ++v44->m_triangles.m_size;
  v49 = &v44->m_triangles.m_data[v45];
  v49->m_a = 0;
  v49->m_b = 3;
  v49->m_c = 1;
  v49->m_material = -1;
  v50 = this->m_geometry;
  v51 = v50->m_triangles.m_size;
  v52 = v51 + 1;
  v53 = v50->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v53 < (int)v51 + 1 )
  {
    v54 = 2 * v53;
    if ( v52 < v54 )
      v52 = v54;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v50->m_triangles.m_data, v52, 16);
  }
  ++v50->m_triangles.m_size;
  v55 = &v50->m_triangles.m_data[v51];
  v55->m_a = 1;
  v55->m_b = 3;
  v55->m_c = 2;
  v55->m_material = -1;
  v56 = this->m_geometry;
  v57 = v56->m_triangles.m_size;
  v58 = v57 + 1;
  v59 = v56->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v59 < (int)v57 + 1 )
  {
    v60 = 2 * v59;
    if ( v58 < v60 )
      v58 = v60;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v56->m_triangles.m_data, v58, 16);
  }
  ++v56->m_triangles.m_size;
  v61 = &v56->m_triangles.m_data[v57];
  v61->m_a = 2;
  v61->m_b = 6;
  v61->m_c = 5;
  v61->m_material = -1;
  v62 = this->m_geometry;
  v63 = v62->m_triangles.m_size;
  v64 = v63 + 1;
  v65 = v62->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v65 < (int)v63 + 1 )
  {
    v66 = 2 * v65;
    if ( v64 < v66 )
      v64 = v66;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v62->m_triangles.m_data, v64, 16);
  }
  ++v62->m_triangles.m_size;
  v67 = &v62->m_triangles.m_data[v63];
  v67->m_a = 5;
  v67->m_b = 1;
  v67->m_c = 2;
  v67->m_material = -1;
  v68 = this->m_geometry;
  v69 = v68->m_triangles.m_size;
  v70 = v69 + 1;
  v71 = v68->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v71 < (int)v69 + 1 )
  {
    v72 = 2 * v71;
    if ( v70 < v72 )
      v70 = v72;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v68->m_triangles.m_data, v70, 16);
  }
  ++v68->m_triangles.m_size;
  v73 = &v68->m_triangles.m_data[v69];
  v73->m_a = 5;
  v73->m_b = 6;
  v73->m_c = 4;
  v73->m_material = -1;
  v74 = this->m_geometry;
  v75 = v74->m_triangles.m_size;
  v76 = v75 + 1;
  v77 = v74->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v77 < (int)v75 + 1 )
  {
    v78 = 2 * v77;
    if ( v76 < v78 )
      v76 = v78;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v74->m_triangles.m_data, v76, 16);
  }
  ++v74->m_triangles.m_size;
  v79 = &v74->m_triangles.m_data[v75];
  v79->m_a = 4;
  v79->m_b = 6;
  v79->m_c = 7;
  v79->m_material = -1;
  v80 = this->m_geometry;
  v81 = v80->m_triangles.m_size;
  v82 = v81 + 1;
  v83 = v80->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v83 < (int)v81 + 1 )
  {
    v84 = 2 * v83;
    if ( v82 < v84 )
      v82 = v84;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v80->m_triangles.m_data, v82, 16);
  }
  ++v80->m_triangles.m_size;
  v85 = (__int64)&v80->m_triangles.m_data[v81];
  *(_DWORD *)v85 = 7;
  *(_QWORD *)(v85 + 4) = 3i64;
  *(_DWORD *)(v85 + 12) = -1;
  v86 = this->m_geometry;
  v87 = v86->m_triangles.m_size;
  v88 = v87 + 1;
  v89 = v86->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v89 < (int)v87 + 1 )
  {
    v90 = 2 * v89;
    if ( v88 < v90 )
      v88 = v90;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v86->m_triangles.m_data, v88, 16);
  }
  ++v86->m_triangles.m_size;
  v91 = &v86->m_triangles.m_data[v87];
  v91->m_a = 0;
  v91->m_b = 4;
  v91->m_c = 7;
  v91->m_material = -1;
  v92 = this->m_geometry;
  v93 = v92->m_triangles.m_size;
  v94 = v93 + 1;
  v95 = v92->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v95 < (int)v93 + 1 )
  {
    v96 = 2 * v95;
    if ( v94 < v96 )
      v94 = v96;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v92->m_triangles.m_data, v94, 16);
  }
  ++v92->m_triangles.m_size;
  v97 = &v92->m_triangles.m_data[v93];
  v97->m_a = 0;
  v97->m_b = 1;
  v97->m_c = 4;
  v97->m_material = -1;
  v98 = this->m_geometry;
  v99 = v98->m_triangles.m_size;
  v100 = v99 + 1;
  v101 = v98->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v101 < (int)v99 + 1 )
  {
    v102 = 2 * v101;
    if ( v100 < v102 )
      v100 = v102;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&v98->m_triangles.m_data,
      v100,
      16);
  }
  ++v98->m_triangles.m_size;
  v103 = &v98->m_triangles.m_data[v99];
  v103->m_a = 4;
  v103->m_b = 1;
  v103->m_c = 5;
  v103->m_material = -1;
  v104 = this->m_geometry;
  v105 = v104->m_triangles.m_size;
  v106 = v105 + 1;
  v107 = v104->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v107 < (int)v105 + 1 )
  {
    v108 = 2 * v107;
    if ( v106 < v108 )
      v106 = v108;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&v104->m_triangles.m_data,
      v106,
      16);
  }
  ++v104->m_triangles.m_size;
  v109 = &v104->m_triangles.m_data[v105];
  v109->m_a = 2;
  v109->m_b = 3;
  v109->m_c = 6;
  v109->m_material = -1;
  v110 = this->m_geometry;
  v111 = v110->m_triangles.m_size;
  v112 = v111 + 1;
  v113 = v110->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v113 < (int)v111 + 1 )
  {
    v114 = 2 * v113;
    if ( v112 < v114 )
      v112 = v114;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&v110->m_triangles.m_data,
      v112,
      16);
  }
  ++v110->m_triangles.m_size;
  v115 = &v110->m_triangles.m_data[v111];
  v115->m_a = 6;
  v115->m_b = 3;
  v115->m_c = 7;
  v115->m_material = -1;
}iangles.m_size;
  v115 = &v110->m_triangles.m_data[v111];
  v115->m_a = 6;
  v115->m_b = 3;
  v115->m_c = 7;
  v115->m_material = -1;
}

// File Line: 66
// RVA: 0xE71F90
hkVector4f *__fastcall hkDisplayAABB::getMinExtent(hkDisplayAABB *this)
{
  return &this->m_minExtent;
}

// File Line: 72
// RVA: 0xE71FA0
hkVector4f *__fastcall hkDisplayAABB::getMaxExtent(hkDisplayAABB *this)
{
  return &this->m_maxExtent;
}

// File Line: 77
// RVA: 0xE71B80
void __fastcall hkDisplayAABB::getWireframeGeometry(
        hkDisplayAABB *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  int v5; // r9d
  hkVector4f *m_data; // rax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  if ( (lines->m_capacityAndFlags & 0x3FFFFFFFu) < 0x18 )
  {
    v5 = 24;
    if ( 2 * (lines->m_capacityAndFlags & 0x3FFFFFFF) > 24 )
      v5 = 2 * (lines->m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, a, (const void **)&lines->m_data, v5, 16);
  }
  m_data = lines->m_data;
  lines->m_size = 24;
  m_data->m_quad = _mm_unpacklo_ps(
                     _mm_unpacklo_ps(
                       (__m128)this->m_minExtent.m_quad.m128_u32[0],
                       (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                     _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[1].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[2].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[3].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[4].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[5].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[6].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[7].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[8].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[9].m_quad = _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                              _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[10].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[11].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[12].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[13].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[14].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[15].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[16].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[17].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[18].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[19].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[20].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_minExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[21].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[22].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  lines->m_data[23].m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)this->m_maxExtent.m_quad.m128_u32[0],
                                 (__m128)this->m_minExtent.m_quad.m128_u32[2]),
                               _mm_unpacklo_ps((__m128)this->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
}

