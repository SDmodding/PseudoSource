// File Line: 14
// RVA: 0xE731A0
void __fastcall hkDisplayBox::hkDisplayBox(hkDisplayBox *this, hkVector4f *halfExtents)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_BOX;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayBox::`vftable;
  this->m_halfExtents = (hkVector4f)halfExtents->m_quad;
  this->m_halfExtents = (hkVector4f)halfExtents->m_quad;
}

// File Line: 20
// RVA: 0xE73210
void __fastcall hkDisplayBox::hkDisplayBox(hkDisplayBox *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_BOX;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->m_halfExtents = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayBox::`vftable;
}

// File Line: 25
// RVA: 0xE73270
void __fastcall hkDisplayBox::setParameters(hkDisplayBox *this, hkVector4f *halfExtents, hkTransformf *t)
{
  this->m_halfExtents = (hkVector4f)halfExtents->m_quad;
  this->m_transform = *t;
}

// File Line: 55
// RVA: 0xE732B0
void __fastcall hkDisplayBox::buildGeometry(hkDisplayBox *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  __int64 v4; // rsi
  __int64 v5; // rbp
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  __m128 *v9; // rax
  hkGeometry *m_geometry; // rsi
  __int64 m_size; // rbp
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  hkGeometry::Triangle *v15; // rax
  hkGeometry *v16; // rsi
  __int64 v17; // rbp
  int v18; // r9d
  int v19; // eax
  int v20; // eax
  __int64 v21; // rax
  hkGeometry *v22; // rsi
  __int64 v23; // rbp
  int v24; // r9d
  int v25; // eax
  int v26; // eax
  hkGeometry::Triangle *v27; // rax
  hkGeometry *v28; // rsi
  __int64 v29; // rbp
  int v30; // r9d
  int v31; // eax
  int v32; // eax
  hkGeometry::Triangle *v33; // rax
  hkGeometry *v34; // rsi
  __int64 v35; // rbp
  int v36; // r9d
  int v37; // eax
  int v38; // eax
  hkGeometry::Triangle *v39; // rax
  hkGeometry *v40; // rsi
  __int64 v41; // rbp
  int v42; // r9d
  int v43; // eax
  int v44; // eax
  __int64 v45; // rax
  hkGeometry *v46; // rsi
  __int64 v47; // rbp
  int v48; // r9d
  int v49; // eax
  int v50; // eax
  hkGeometry::Triangle *v51; // rax
  hkGeometry *v52; // rsi
  __int64 v53; // rbp
  int v54; // r9d
  int v55; // eax
  int v56; // eax
  hkGeometry::Triangle *v57; // rax
  hkGeometry *v58; // rsi
  __int64 v59; // rbp
  int v60; // r9d
  int v61; // eax
  int v62; // eax
  hkGeometry::Triangle *v63; // rax
  hkGeometry *v64; // rsi
  __int64 v65; // rbp
  int v66; // r9d
  int v67; // eax
  int v68; // eax
  hkGeometry::Triangle *v69; // rax
  hkGeometry *v70; // rsi
  __int64 v71; // rbp
  int v72; // r9d
  int v73; // eax
  int v74; // eax
  hkGeometry::Triangle *v75; // rax
  hkGeometry *v76; // rbx
  __int64 v77; // rsi
  int v78; // r9d
  int v79; // eax
  int v80; // eax
  __int64 v81; // rax
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

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
  v6 = v5 + 8;
  v7 = *(_DWORD *)(v3 + 28) & 0x3FFFFFFF;
  if ( v7 < (int)v5 + 8 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)v4, v6, 16);
  }
  *(_DWORD *)(v4 + 8) += 8;
  v9 = (__m128 *)(*(_QWORD *)v4 + 16 * v5);
  *v9 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(
            _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0]),
            (__m128)this->m_halfExtents.m_quad.m128_u32[2]),
          _mm_unpacklo_ps((__m128)this->m_halfExtents.m_quad.m128_u32[1], (__m128)0i64));
  v9[1] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)this->m_halfExtents.m_quad.m128_u32[0],
              (__m128)this->m_halfExtents.m_quad.m128_u32[2]),
            _mm_unpacklo_ps((__m128)this->m_halfExtents.m_quad.m128_u32[1], (__m128)0i64));
  v9[2] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)this->m_halfExtents.m_quad.m128_u32[0],
              (__m128)this->m_halfExtents.m_quad.m128_u32[2]),
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0]),
              (__m128)0i64));
  v9[3] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0]),
              (__m128)this->m_halfExtents.m_quad.m128_u32[2]),
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0]),
              (__m128)0i64));
  v9[4] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0]),
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])),
            _mm_unpacklo_ps((__m128)this->m_halfExtents.m_quad.m128_u32[1], (__m128)0i64));
  v9[5] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)this->m_halfExtents.m_quad.m128_u32[0],
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])),
            _mm_unpacklo_ps((__m128)this->m_halfExtents.m_quad.m128_u32[1], (__m128)0i64));
  v9[6] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)this->m_halfExtents.m_quad.m128_u32[0],
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])),
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0]),
              (__m128)0i64));
  v9[7] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0]),
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])),
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)this->m_halfExtents.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0]),
              (__m128)0i64));
  m_geometry = this->m_geometry;
  m_size = m_geometry->m_triangles.m_size;
  v12 = m_size + 1;
  v13 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < (int)m_size + 1 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&m_geometry->m_triangles.m_data,
      v12,
      16);
  }
  ++m_geometry->m_triangles.m_size;
  v15 = &m_geometry->m_triangles.m_data[m_size];
  v15->m_a = 3;
  v15->m_b = 2;
  v15->m_c = 1;
  v15->m_material = -1;
  v16 = this->m_geometry;
  v17 = v16->m_triangles.m_size;
  v18 = v17 + 1;
  v19 = v16->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v19 < (int)v17 + 1 )
  {
    v20 = 2 * v19;
    if ( v18 < v20 )
      v18 = v20;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v16->m_triangles.m_data, v18, 16);
  }
  ++v16->m_triangles.m_size;
  v21 = (__int64)&v16->m_triangles.m_data[v17];
  *(_DWORD *)v21 = 3;
  *(_QWORD *)(v21 + 4) = 1i64;
  *(_DWORD *)(v21 + 12) = -1;
  v22 = this->m_geometry;
  v23 = v22->m_triangles.m_size;
  v24 = v23 + 1;
  v25 = v22->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 < (int)v23 + 1 )
  {
    v26 = 2 * v25;
    if ( v24 < v26 )
      v24 = v26;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v22->m_triangles.m_data, v24, 16);
  }
  ++v22->m_triangles.m_size;
  v27 = &v22->m_triangles.m_data[v23];
  v27->m_a = 6;
  v27->m_b = 7;
  v27->m_c = 4;
  v27->m_material = -1;
  v28 = this->m_geometry;
  v29 = v28->m_triangles.m_size;
  v30 = v29 + 1;
  v31 = v28->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v31 < (int)v29 + 1 )
  {
    v32 = 2 * v31;
    if ( v30 < v32 )
      v30 = v32;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v28->m_triangles.m_data, v30, 16);
  }
  ++v28->m_triangles.m_size;
  v33 = &v28->m_triangles.m_data[v29];
  v33->m_a = 6;
  v33->m_b = 4;
  v33->m_c = 5;
  v33->m_material = -1;
  v34 = this->m_geometry;
  v35 = v34->m_triangles.m_size;
  v36 = v35 + 1;
  v37 = v34->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v37 < (int)v35 + 1 )
  {
    v38 = 2 * v37;
    if ( v36 < v38 )
      v36 = v38;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v34->m_triangles.m_data, v36, 16);
  }
  ++v34->m_triangles.m_size;
  v39 = &v34->m_triangles.m_data[v35];
  v39->m_a = 4;
  v39->m_b = 7;
  v39->m_c = 3;
  v39->m_material = -1;
  v40 = this->m_geometry;
  v41 = v40->m_triangles.m_size;
  v42 = v41 + 1;
  v43 = v40->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v43 < (int)v41 + 1 )
  {
    v44 = 2 * v43;
    if ( v42 < v44 )
      v42 = v44;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v40->m_triangles.m_data, v42, 16);
  }
  ++v40->m_triangles.m_size;
  v45 = (__int64)&v40->m_triangles.m_data[v41];
  *(_DWORD *)v45 = 4;
  *(_QWORD *)(v45 + 4) = 3i64;
  *(_DWORD *)(v45 + 12) = -1;
  v46 = this->m_geometry;
  v47 = v46->m_triangles.m_size;
  v48 = v47 + 1;
  v49 = v46->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v49 < (int)v47 + 1 )
  {
    v50 = 2 * v49;
    if ( v48 < v50 )
      v48 = v50;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v46->m_triangles.m_data, v48, 16);
  }
  ++v46->m_triangles.m_size;
  v51 = &v46->m_triangles.m_data[v47];
  v51->m_a = 2;
  v51->m_b = 6;
  v51->m_c = 5;
  v51->m_material = -1;
  v52 = this->m_geometry;
  v53 = v52->m_triangles.m_size;
  v54 = v53 + 1;
  v55 = v52->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v55 < (int)v53 + 1 )
  {
    v56 = 2 * v55;
    if ( v54 < v56 )
      v54 = v56;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v52->m_triangles.m_data, v54, 16);
  }
  ++v52->m_triangles.m_size;
  v57 = &v52->m_triangles.m_data[v53];
  v57->m_a = 2;
  v57->m_b = 5;
  v57->m_c = 1;
  v57->m_material = -1;
  v58 = this->m_geometry;
  v59 = v58->m_triangles.m_size;
  v60 = v59 + 1;
  v61 = v58->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v61 < (int)v59 + 1 )
  {
    v62 = 2 * v61;
    if ( v60 < v62 )
      v60 = v62;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v58->m_triangles.m_data, v60, 16);
  }
  ++v58->m_triangles.m_size;
  v63 = &v58->m_triangles.m_data[v59];
  v63->m_a = 7;
  v63->m_b = 6;
  v63->m_c = 2;
  v63->m_material = -1;
  v64 = this->m_geometry;
  v65 = v64->m_triangles.m_size;
  v66 = v65 + 1;
  v67 = v64->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v67 < (int)v65 + 1 )
  {
    v68 = 2 * v67;
    if ( v66 < v68 )
      v66 = v68;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v64->m_triangles.m_data, v66, 16);
  }
  ++v64->m_triangles.m_size;
  v69 = &v64->m_triangles.m_data[v65];
  v69->m_a = 7;
  v69->m_b = 2;
  v69->m_c = 3;
  v69->m_material = -1;
  v70 = this->m_geometry;
  v71 = v70->m_triangles.m_size;
  v72 = v71 + 1;
  v73 = v70->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v73 < (int)v71 + 1 )
  {
    v74 = 2 * v73;
    if ( v72 < v74 )
      v72 = v74;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v70->m_triangles.m_data, v72, 16);
  }
  ++v70->m_triangles.m_size;
  v75 = &v70->m_triangles.m_data[v71];
  v75->m_a = 1;
  v75->m_b = 5;
  v75->m_c = 4;
  v75->m_material = -1;
  v76 = this->m_geometry;
  v77 = v76->m_triangles.m_size;
  v78 = v77 + 1;
  v79 = v76->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v79 < (int)v77 + 1 )
  {
    v80 = 2 * v79;
    if ( v78 < v80 )
      v78 = v80;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v76->m_triangles.m_data, v78, 16);
  }
  ++v76->m_triangles.m_size;
  v81 = (__int64)&v76->m_triangles.m_data[v77];
  *(_DWORD *)v81 = 1;
  *(_QWORD *)(v81 + 4) = 4i64;
  *(_DWORD *)(v81 + 12) = -1;
}

// File Line: 85
// RVA: 0xE73980
void __fastcall hkDisplayBox::getWireframeGeometry(
        hkDisplayBox *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  int v5; // r9d
  int v6; // r11d
  __int64 v7; // r10
  __int128 m_quad; // xmm0
  __int128 v9; // xmm0
  __int128 v10; // xmm0
  float v11; // xmm1_4
  __int128 v12; // xmm0
  __int128 v13; // xmm0
  float v14; // xmm1_4
  hkVector4f v15; // xmm1
  __int128 *v16; // rdi
  __int128 v17; // xmm0
  int v18; // r9d
  __int64 v19; // rdx
  __int128 *v20; // rcx
  __int64 v21; // rdx
  _OWORD *v22; // rcx
  hkVector4f v23; // [rsp+30h] [rbp-39h]
  hkVector4f v24; // [rsp+30h] [rbp-39h]
  hkVector4f v25; // [rsp+30h] [rbp-39h]
  hkVector4f v26; // [rsp+30h] [rbp-39h]
  hkVector4f v27; // [rsp+30h] [rbp-39h]
  hkVector4f v28; // [rsp+30h] [rbp-39h]
  __int128 v29[8]; // [rsp+40h] [rbp-29h] BYREF
  hkResult result; // [rsp+D8h] [rbp+6Fh] BYREF

  if ( (lines->m_capacityAndFlags & 0x3FFFFFFFu) < 0x18 )
  {
    v5 = 24;
    if ( 2 * (lines->m_capacityAndFlags & 0x3FFFFFFF) > 24 )
      v5 = 2 * (lines->m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, a, (const void **)&lines->m_data, v5, 16);
  }
  lines->m_size = 24;
  v23.m_quad = (__m128)this->m_halfExtents;
  v29[0] = (__int128)v23.m_quad;
  v6 = 0;
  v7 = 0i64;
  v23.m_quad.m128_f32[0] = v23.m_quad.m128_f32[0] * -1.0;
  m_quad = (__int128)v23.m_quad;
  v24.m_quad = (__m128)this->m_halfExtents;
  v29[1] = m_quad;
  v24.m_quad.m128_f32[1] = this->m_halfExtents.m_quad.m128_f32[1] * -1.0;
  v9 = (__int128)v24.m_quad;
  v25.m_quad = (__m128)this->m_halfExtents;
  v29[2] = v9;
  v25.m_quad.m128_f32[0] = v25.m_quad.m128_f32[0] * -1.0;
  v25.m_quad.m128_f32[1] = v25.m_quad.m128_f32[1] * -1.0;
  v10 = (__int128)v25.m_quad;
  v26.m_quad = (__m128)this->m_halfExtents;
  v11 = this->m_halfExtents.m_quad.m128_f32[2] * -1.0;
  v29[3] = v10;
  v26.m_quad.m128_f32[2] = v11;
  v12 = (__int128)v26.m_quad;
  v27.m_quad = (__m128)this->m_halfExtents;
  v29[4] = v12;
  v27.m_quad.m128_f32[0] = v27.m_quad.m128_f32[0] * -1.0;
  v27.m_quad.m128_f32[2] = v27.m_quad.m128_f32[2] * -1.0;
  v13 = (__int128)v27.m_quad;
  v28.m_quad = (__m128)this->m_halfExtents;
  v14 = this->m_halfExtents.m_quad.m128_f32[1] * -1.0;
  v29[5] = v13;
  v28.m_quad.m128_f32[1] = v14;
  v15.m_quad = (__m128)this->m_halfExtents;
  v16 = v29;
  v28.m_quad.m128_f32[2] = v28.m_quad.m128_f32[2] * -1.0;
  v17 = (__int128)v28.m_quad;
  v28.m_quad.m128_i32[3] = v15.m_quad.m128_i32[3];
  v29[6] = v17;
  v28.m_quad.m128_f32[0] = v15.m_quad.m128_f32[0] * -1.0;
  v28.m_quad.m128_f32[2] = v15.m_quad.m128_f32[2] * -1.0;
  v28.m_quad.m128_f32[1] = v15.m_quad.m128_f32[1] * -1.0;
  v29[7] = (__int128)v28.m_quad;
  do
  {
    v18 = 1;
    v19 = 16 * v7;
    do
    {
      if ( v6 < (v6 ^ v18) )
      {
        v20 = (__int128 *)((char *)lines->m_data + v19);
        v21 = v19 + 16;
        v7 += 2i64;
        *v20 = *v16;
        v22 = (_OWORD *)((char *)lines->m_data->m_quad.m128_f32 + v21);
        v19 = v21 + 16;
        *v22 = v29[v6 ^ v18];
      }
      v18 *= 2;
    }
    while ( v18 < 8 );
    ++v6;
    ++v16;
  }
  while ( v6 < 8 );
}

