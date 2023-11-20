// File Line: 15
// RVA: 0xE71240
void __fastcall hkDisplayAABB::hkDisplayAABB(hkDisplayAABB *this, hkVector4f *min, hkVector4f *max)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 3;
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
  this->m_type = 3;
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
  hkDisplayAABB *v1; // rbx
  _QWORD **v2; // rax
  __int64 v3; // rax
  _DWORD *v4; // rsi
  __int64 v5; // rbp
  int v6; // er9
  int v7; // eax
  int v8; // eax
  signed int *v9; // rsi
  __int64 v10; // rbp
  int v11; // er9
  int v12; // eax
  int v13; // eax
  signed int *v14; // rsi
  __int64 v15; // rbp
  int v16; // er9
  int v17; // eax
  int v18; // eax
  signed int *v19; // rsi
  __int64 v20; // rbp
  int v21; // er9
  int v22; // eax
  int v23; // eax
  signed int *v24; // rsi
  __int64 v25; // rbp
  int v26; // er9
  int v27; // eax
  int v28; // eax
  signed int *v29; // rsi
  __int64 v30; // rbp
  int v31; // er9
  int v32; // eax
  int v33; // eax
  signed int *v34; // rsi
  __int64 v35; // rbp
  int v36; // er9
  int v37; // eax
  int v38; // eax
  signed int *v39; // rsi
  __int64 v40; // rbp
  int v41; // er9
  int v42; // eax
  int v43; // eax
  signed int *v44; // rsi
  __int64 v45; // rbp
  int v46; // er9
  int v47; // eax
  int v48; // eax
  _DWORD *v49; // rax
  signed int *v50; // rsi
  __int64 v51; // rbp
  int v52; // er9
  int v53; // eax
  int v54; // eax
  _DWORD *v55; // rax
  signed int *v56; // rsi
  __int64 v57; // rbp
  int v58; // er9
  int v59; // eax
  int v60; // eax
  _DWORD *v61; // rax
  signed int *v62; // rsi
  __int64 v63; // rbp
  int v64; // er9
  int v65; // eax
  int v66; // eax
  _DWORD *v67; // rax
  signed int *v68; // rsi
  __int64 v69; // rbp
  int v70; // er9
  int v71; // eax
  int v72; // eax
  _DWORD *v73; // rax
  signed int *v74; // rsi
  __int64 v75; // rbp
  int v76; // er9
  int v77; // eax
  int v78; // eax
  _DWORD *v79; // rax
  signed int *v80; // rsi
  __int64 v81; // rbp
  int v82; // er9
  int v83; // eax
  int v84; // eax
  signed __int64 v85; // rax
  signed int *v86; // rsi
  __int64 v87; // rbp
  int v88; // er9
  int v89; // eax
  int v90; // eax
  _DWORD *v91; // rax
  signed int *v92; // rsi
  __int64 v93; // rbp
  int v94; // er9
  int v95; // eax
  int v96; // eax
  _DWORD *v97; // rax
  signed int *v98; // rdi
  __int64 v99; // rsi
  int v100; // er9
  int v101; // eax
  int v102; // eax
  _DWORD *v103; // rax
  signed int *v104; // rdi
  __int64 v105; // rsi
  int v106; // er9
  int v107; // eax
  int v108; // eax
  _DWORD *v109; // rax
  signed int *v110; // rbx
  __int64 v111; // rdi
  int v112; // er9
  int v113; // eax
  int v114; // eax
  _DWORD *v115; // rax
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 48i64);
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable;
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
  v4 = (_DWORD *)(v3 + 16);
  v1->m_geometry = (hkGeometry *)v3;
  v5 = *(signed int *)(v3 + 24);
  v6 = v5 + 1;
  v7 = *(_DWORD *)(v3 + 28) & 0x3FFFFFFF;
  if ( v7 < (signed int)v5 + 1 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v6, 16);
  }
  ++v4[2];
  *(__m128 *)(*(_QWORD *)v4 + 16 * v5) = _mm_unpacklo_ps(
                                           _mm_unpacklo_ps(
                                             (__m128)v1->m_minExtent.m_quad.m128_u32[0],
                                             (__m128)v1->m_minExtent.m_quad.m128_u32[2]),
                                           _mm_unpacklo_ps((__m128)v1->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  v9 = (signed int *)v1->m_geometry;
  v10 = v9[6];
  v11 = v10 + 1;
  v12 = v9[7] & 0x3FFFFFFF;
  if ( v12 < (signed int)v10 + 1 )
  {
    v13 = 2 * v12;
    if ( v11 < v13 )
      v11 = v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 4, v11, 16);
  }
  ++v9[6];
  *(__m128 *)(*((_QWORD *)v9 + 2) + 16 * v10) = _mm_unpacklo_ps(
                                                  _mm_unpacklo_ps(
                                                    (__m128)v1->m_minExtent.m_quad.m128_u32[0],
                                                    (__m128)v1->m_maxExtent.m_quad.m128_u32[2]),
                                                  _mm_unpacklo_ps(
                                                    (__m128)v1->m_minExtent.m_quad.m128_u32[1],
                                                    (__m128)0i64));
  v14 = (signed int *)v1->m_geometry;
  v15 = v14[6];
  v16 = v15 + 1;
  v17 = v14[7] & 0x3FFFFFFF;
  if ( v17 < (signed int)v15 + 1 )
  {
    v18 = 2 * v17;
    if ( v16 < v18 )
      v16 = v18;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v14 + 4, v16, 16);
  }
  ++v14[6];
  *(__m128 *)(*((_QWORD *)v14 + 2) + 16 * v15) = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[0],
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[2]),
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_minExtent.m_quad.m128_u32[1],
                                                     (__m128)0i64));
  v19 = (signed int *)v1->m_geometry;
  v20 = v19[6];
  v21 = v20 + 1;
  v22 = v19[7] & 0x3FFFFFFF;
  if ( v22 < (signed int)v20 + 1 )
  {
    v23 = 2 * v22;
    if ( v21 < v23 )
      v21 = v23;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19 + 4, v21, 16);
  }
  ++v19[6];
  *(__m128 *)(*((_QWORD *)v19 + 2) + 16 * v20) = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[0],
                                                     (__m128)v1->m_minExtent.m_quad.m128_u32[2]),
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_minExtent.m_quad.m128_u32[1],
                                                     (__m128)0i64));
  v24 = (signed int *)v1->m_geometry;
  v25 = v24[6];
  v26 = v25 + 1;
  v27 = v24[7] & 0x3FFFFFFF;
  if ( v27 < (signed int)v25 + 1 )
  {
    v28 = 2 * v27;
    if ( v26 < v28 )
      v26 = v28;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v24 + 4, v26, 16);
  }
  ++v24[6];
  *(__m128 *)(*((_QWORD *)v24 + 2) + 16 * v25) = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_minExtent.m_quad.m128_u32[0],
                                                     (__m128)v1->m_minExtent.m_quad.m128_u32[2]),
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[1],
                                                     (__m128)0i64));
  v29 = (signed int *)v1->m_geometry;
  v30 = v29[6];
  v31 = v30 + 1;
  v32 = v29[7] & 0x3FFFFFFF;
  if ( v32 < (signed int)v30 + 1 )
  {
    v33 = 2 * v32;
    if ( v31 < v33 )
      v31 = v33;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v29 + 4, v31, 16);
  }
  ++v29[6];
  *(__m128 *)(*((_QWORD *)v29 + 2) + 16 * v30) = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_minExtent.m_quad.m128_u32[0],
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[2]),
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[1],
                                                     (__m128)0i64));
  v34 = (signed int *)v1->m_geometry;
  v35 = v34[6];
  v36 = v35 + 1;
  v37 = v34[7] & 0x3FFFFFFF;
  if ( v37 < (signed int)v35 + 1 )
  {
    v38 = 2 * v37;
    if ( v36 < v38 )
      v36 = v38;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v34 + 4, v36, 16);
  }
  ++v34[6];
  *(__m128 *)(*((_QWORD *)v34 + 2) + 16 * v35) = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[0],
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[2]),
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[1],
                                                     (__m128)0i64));
  v39 = (signed int *)v1->m_geometry;
  v40 = v39[6];
  v41 = v40 + 1;
  v42 = v39[7] & 0x3FFFFFFF;
  if ( v42 < (signed int)v40 + 1 )
  {
    v43 = 2 * v42;
    if ( v41 < v43 )
      v41 = v43;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v39 + 4, v41, 16);
  }
  ++v39[6];
  *(__m128 *)(*((_QWORD *)v39 + 2) + 16 * v40) = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[0],
                                                     (__m128)v1->m_minExtent.m_quad.m128_u32[2]),
                                                   _mm_unpacklo_ps(
                                                     (__m128)v1->m_maxExtent.m_quad.m128_u32[1],
                                                     (__m128)0i64));
  v44 = (signed int *)v1->m_geometry;
  v45 = v44[10];
  v46 = v45 + 1;
  v47 = v44[11] & 0x3FFFFFFF;
  if ( v47 < (signed int)v45 + 1 )
  {
    v48 = 2 * v47;
    if ( v46 < v48 )
      v46 = v48;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v44 + 8, v46, 16);
  }
  ++v44[10];
  v49 = (_DWORD *)(*((_QWORD *)v44 + 4) + 16 * v45);
  *v49 = 0;
  v49[1] = 3;
  v49[2] = 1;
  v49[3] = -1;
  v50 = (signed int *)v1->m_geometry;
  v51 = v50[10];
  v52 = v51 + 1;
  v53 = v50[11] & 0x3FFFFFFF;
  if ( v53 < (signed int)v51 + 1 )
  {
    v54 = 2 * v53;
    if ( v52 < v54 )
      v52 = v54;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v50 + 8, v52, 16);
  }
  ++v50[10];
  v55 = (_DWORD *)(*((_QWORD *)v50 + 4) + 16 * v51);
  *v55 = 1;
  v55[1] = 3;
  v55[2] = 2;
  v55[3] = -1;
  v56 = (signed int *)v1->m_geometry;
  v57 = v56[10];
  v58 = v57 + 1;
  v59 = v56[11] & 0x3FFFFFFF;
  if ( v59 < (signed int)v57 + 1 )
  {
    v60 = 2 * v59;
    if ( v58 < v60 )
      v58 = v60;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v56 + 8, v58, 16);
  }
  ++v56[10];
  v61 = (_DWORD *)(*((_QWORD *)v56 + 4) + 16 * v57);
  *v61 = 2;
  v61[1] = 6;
  v61[2] = 5;
  v61[3] = -1;
  v62 = (signed int *)v1->m_geometry;
  v63 = v62[10];
  v64 = v63 + 1;
  v65 = v62[11] & 0x3FFFFFFF;
  if ( v65 < (signed int)v63 + 1 )
  {
    v66 = 2 * v65;
    if ( v64 < v66 )
      v64 = v66;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v62 + 8, v64, 16);
  }
  ++v62[10];
  v67 = (_DWORD *)(*((_QWORD *)v62 + 4) + 16 * v63);
  *v67 = 5;
  v67[1] = 1;
  v67[2] = 2;
  v67[3] = -1;
  v68 = (signed int *)v1->m_geometry;
  v69 = v68[10];
  v70 = v69 + 1;
  v71 = v68[11] & 0x3FFFFFFF;
  if ( v71 < (signed int)v69 + 1 )
  {
    v72 = 2 * v71;
    if ( v70 < v72 )
      v70 = v72;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v68 + 8, v70, 16);
  }
  ++v68[10];
  v73 = (_DWORD *)(*((_QWORD *)v68 + 4) + 16 * v69);
  *v73 = 5;
  v73[1] = 6;
  v73[2] = 4;
  v73[3] = -1;
  v74 = (signed int *)v1->m_geometry;
  v75 = v74[10];
  v76 = v75 + 1;
  v77 = v74[11] & 0x3FFFFFFF;
  if ( v77 < (signed int)v75 + 1 )
  {
    v78 = 2 * v77;
    if ( v76 < v78 )
      v76 = v78;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v74 + 8, v76, 16);
  }
  ++v74[10];
  v79 = (_DWORD *)(*((_QWORD *)v74 + 4) + 16 * v75);
  *v79 = 4;
  v79[1] = 6;
  v79[2] = 7;
  v79[3] = -1;
  v80 = (signed int *)v1->m_geometry;
  v81 = v80[10];
  v82 = v81 + 1;
  v83 = v80[11] & 0x3FFFFFFF;
  if ( v83 < (signed int)v81 + 1 )
  {
    v84 = 2 * v83;
    if ( v82 < v84 )
      v82 = v84;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v80 + 8, v82, 16);
  }
  ++v80[10];
  v85 = *((_QWORD *)v80 + 4) + 16 * v81;
  *(_DWORD *)v85 = 7;
  *(_QWORD *)(v85 + 4) = 3i64;
  *(_DWORD *)(v85 + 12) = -1;
  v86 = (signed int *)v1->m_geometry;
  v87 = v86[10];
  v88 = v87 + 1;
  v89 = v86[11] & 0x3FFFFFFF;
  if ( v89 < (signed int)v87 + 1 )
  {
    v90 = 2 * v89;
    if ( v88 < v90 )
      v88 = v90;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v86 + 8, v88, 16);
  }
  ++v86[10];
  v91 = (_DWORD *)(*((_QWORD *)v86 + 4) + 16 * v87);
  *v91 = 0;
  v91[1] = 4;
  v91[2] = 7;
  v91[3] = -1;
  v92 = (signed int *)v1->m_geometry;
  v93 = v92[10];
  v94 = v93 + 1;
  v95 = v92[11] & 0x3FFFFFFF;
  if ( v95 < (signed int)v93 + 1 )
  {
    v96 = 2 * v95;
    if ( v94 < v96 )
      v94 = v96;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v92 + 8, v94, 16);
  }
  ++v92[10];
  v97 = (_DWORD *)(*((_QWORD *)v92 + 4) + 16 * v93);
  *v97 = 0;
  v97[1] = 1;
  v97[2] = 4;
  v97[3] = -1;
  v98 = (signed int *)v1->m_geometry;
  v99 = v98[10];
  v100 = v99 + 1;
  v101 = v98[11] & 0x3FFFFFFF;
  if ( v101 < (signed int)v99 + 1 )
  {
    v102 = 2 * v101;
    if ( v100 < v102 )
      v100 = v102;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v98 + 8, v100, 16);
  }
  ++v98[10];
  v103 = (_DWORD *)(*((_QWORD *)v98 + 4) + 16 * v99);
  *v103 = 4;
  v103[1] = 1;
  v103[2] = 5;
  v103[3] = -1;
  v104 = (signed int *)v1->m_geometry;
  v105 = v104[10];
  v106 = v105 + 1;
  v107 = v104[11] & 0x3FFFFFFF;
  if ( v107 < (signed int)v105 + 1 )
  {
    v108 = 2 * v107;
    if ( v106 < v108 )
      v106 = v108;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v104 + 8, v106, 16);
  }
  ++v104[10];
  v109 = (_DWORD *)(*((_QWORD *)v104 + 4) + 16 * v105);
  *v109 = 2;
  v109[1] = 3;
  v109[2] = 6;
  v109[3] = -1;
  v110 = (signed int *)v1->m_geometry;
  v111 = v110[10];
  v112 = v111 + 1;
  v113 = v110[11] & 0x3FFFFFFF;
  if ( v113 < (signed int)v111 + 1 )
  {
    v114 = 2 * v113;
    if ( v112 < v114 )
      v112 = v114;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v110 + 8, v112, 16);
  }
  ++v110[10];
  v115 = (_DWORD *)(*((_QWORD *)v110 + 4) + 16 * v111);
  *v115 = 6;
  v115[1] = 3;
  v115[2] = 7;
  v115[3] = -1;
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
void __fastcall hkDisplayAABB::getWireframeGeometry(hkDisplayAABB *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  __m128 **v3; // rbx
  int v4; // eax
  hkDisplayAABB *v5; // rdi
  int v6; // eax
  int v7; // er9
  __m128 *v8; // rax
  hkResult result; // [rsp+40h] [rbp+8h]

  v3 = (__m128 **)lines;
  v4 = lines->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < 24 )
  {
    v6 = 2 * v4;
    v7 = 24;
    if ( v6 > 24 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, a, lines, v7, 16);
  }
  v8 = *v3;
  *((_DWORD *)v3 + 2) = 24;
  *v8 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
          _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[1] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[2] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[3] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[4] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[5] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[6] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[7] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[8] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[9] = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
               _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[10] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[11] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[12] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[13] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[14] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[15] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[16] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[17] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[18] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[19] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[20] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[21] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[22] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_maxExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
  (*v3)[23] = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)v5->m_maxExtent.m_quad.m128_u32[0], (__m128)v5->m_minExtent.m_quad.m128_u32[2]),
                _mm_unpacklo_ps((__m128)v5->m_minExtent.m_quad.m128_u32[1], (__m128)0i64));
}

