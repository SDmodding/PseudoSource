// File Line: 14
// RVA: 0xE731A0
void __fastcall hkDisplayBox::hkDisplayBox(hkDisplayBox *this, hkVector4f *halfExtents)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 2;
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
  this->m_type = 2;
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
  this->m_transform.m_rotation.m_col0 = t->m_rotation.m_col0;
  this->m_transform.m_rotation.m_col1 = t->m_rotation.m_col1;
  this->m_transform.m_rotation.m_col2 = t->m_rotation.m_col2;
  this->m_transform.m_translation = t->m_translation;
}

// File Line: 55
// RVA: 0xE732B0
void __fastcall hkDisplayBox::buildGeometry(hkDisplayBox *this)
{
  hkDisplayBox *v1; // rbx
  _QWORD **v2; // rax
  __int64 v3; // rax
  _DWORD *v4; // rsi
  __int64 v5; // rbp
  int v6; // er9
  int v7; // eax
  int v8; // eax
  __m128 *v9; // rax
  signed int *v10; // rsi
  __int64 v11; // rbp
  int v12; // er9
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // rax
  signed int *v16; // rsi
  __int64 v17; // rbp
  int v18; // er9
  int v19; // eax
  int v20; // eax
  signed __int64 v21; // rax
  signed int *v22; // rsi
  __int64 v23; // rbp
  int v24; // er9
  int v25; // eax
  int v26; // eax
  _DWORD *v27; // rax
  signed int *v28; // rsi
  __int64 v29; // rbp
  int v30; // er9
  int v31; // eax
  int v32; // eax
  _DWORD *v33; // rax
  signed int *v34; // rsi
  __int64 v35; // rbp
  int v36; // er9
  int v37; // eax
  int v38; // eax
  _DWORD *v39; // rax
  signed int *v40; // rsi
  __int64 v41; // rbp
  int v42; // er9
  int v43; // eax
  int v44; // eax
  signed __int64 v45; // rax
  signed int *v46; // rsi
  __int64 v47; // rbp
  int v48; // er9
  int v49; // eax
  int v50; // eax
  _DWORD *v51; // rax
  signed int *v52; // rsi
  __int64 v53; // rbp
  int v54; // er9
  int v55; // eax
  int v56; // eax
  _DWORD *v57; // rax
  signed int *v58; // rsi
  __int64 v59; // rbp
  int v60; // er9
  int v61; // eax
  int v62; // eax
  _DWORD *v63; // rax
  signed int *v64; // rsi
  __int64 v65; // rbp
  int v66; // er9
  int v67; // eax
  int v68; // eax
  _DWORD *v69; // rax
  signed int *v70; // rsi
  __int64 v71; // rbp
  int v72; // er9
  int v73; // eax
  int v74; // eax
  _DWORD *v75; // rax
  signed int *v76; // rbx
  __int64 v77; // rsi
  int v78; // er9
  int v79; // eax
  int v80; // eax
  signed __int64 v81; // rax
  hkResult result; // [rsp+60h] [rbp+8h]

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
  v6 = v5 + 8;
  v7 = *(_DWORD *)(v3 + 28) & 0x3FFFFFFF;
  if ( v7 < (signed int)v5 + 8 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v6, 16);
  }
  v4[2] += 8;
  v9 = (__m128 *)(*(_QWORD *)v4 + 16 * v5);
  *v9 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(
            _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0]),
            (__m128)v1->m_halfExtents.m_quad.m128_u32[2]),
          _mm_unpacklo_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[1], (__m128)0i64));
  v9[1] = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[0], (__m128)v1->m_halfExtents.m_quad.m128_u32[2]),
            _mm_unpacklo_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[1], (__m128)0i64));
  v9[2] = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[0], (__m128)v1->m_halfExtents.m_quad.m128_u32[2]),
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0]),
              (__m128)0i64));
  v9[3] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0]),
              (__m128)v1->m_halfExtents.m_quad.m128_u32[2]),
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0]),
              (__m128)0i64));
  v9[4] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0]),
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])),
            _mm_unpacklo_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[1], (__m128)0i64));
  v9[5] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)v1->m_halfExtents.m_quad.m128_u32[0],
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])),
            _mm_unpacklo_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[1], (__m128)0i64));
  v9[6] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)v1->m_halfExtents.m_quad.m128_u32[0],
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])),
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0]),
              (__m128)0i64));
  v9[7] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0]),
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])),
            _mm_unpacklo_ps(
              _mm_xor_ps((__m128)v1->m_halfExtents.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0]),
              (__m128)0i64));
  v10 = (signed int *)v1->m_geometry;
  v11 = v10[10];
  v12 = v11 + 1;
  v13 = v10[11] & 0x3FFFFFFF;
  if ( v13 < (signed int)v11 + 1 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10 + 8, v12, 16);
  }
  ++v10[10];
  v15 = (_DWORD *)(*((_QWORD *)v10 + 4) + 16 * v11);
  *v15 = 3;
  v15[1] = 2;
  v15[2] = 1;
  v15[3] = -1;
  v16 = (signed int *)v1->m_geometry;
  v17 = v16[10];
  v18 = v17 + 1;
  v19 = v16[11] & 0x3FFFFFFF;
  if ( v19 < (signed int)v17 + 1 )
  {
    v20 = 2 * v19;
    if ( v18 < v20 )
      v18 = v20;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16 + 8, v18, 16);
  }
  ++v16[10];
  v21 = *((_QWORD *)v16 + 4) + 16 * v17;
  *(_DWORD *)v21 = 3;
  *(_QWORD *)(v21 + 4) = 1i64;
  *(_DWORD *)(v21 + 12) = -1;
  v22 = (signed int *)v1->m_geometry;
  v23 = v22[10];
  v24 = v23 + 1;
  v25 = v22[11] & 0x3FFFFFFF;
  if ( v25 < (signed int)v23 + 1 )
  {
    v26 = 2 * v25;
    if ( v24 < v26 )
      v24 = v26;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v22 + 8, v24, 16);
  }
  ++v22[10];
  v27 = (_DWORD *)(*((_QWORD *)v22 + 4) + 16 * v23);
  *v27 = 6;
  v27[1] = 7;
  v27[2] = 4;
  v27[3] = -1;
  v28 = (signed int *)v1->m_geometry;
  v29 = v28[10];
  v30 = v29 + 1;
  v31 = v28[11] & 0x3FFFFFFF;
  if ( v31 < (signed int)v29 + 1 )
  {
    v32 = 2 * v31;
    if ( v30 < v32 )
      v30 = v32;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v28 + 8, v30, 16);
  }
  ++v28[10];
  v33 = (_DWORD *)(*((_QWORD *)v28 + 4) + 16 * v29);
  *v33 = 6;
  v33[1] = 4;
  v33[2] = 5;
  v33[3] = -1;
  v34 = (signed int *)v1->m_geometry;
  v35 = v34[10];
  v36 = v35 + 1;
  v37 = v34[11] & 0x3FFFFFFF;
  if ( v37 < (signed int)v35 + 1 )
  {
    v38 = 2 * v37;
    if ( v36 < v38 )
      v36 = v38;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v34 + 8, v36, 16);
  }
  ++v34[10];
  v39 = (_DWORD *)(*((_QWORD *)v34 + 4) + 16 * v35);
  *v39 = 4;
  v39[1] = 7;
  v39[2] = 3;
  v39[3] = -1;
  v40 = (signed int *)v1->m_geometry;
  v41 = v40[10];
  v42 = v41 + 1;
  v43 = v40[11] & 0x3FFFFFFF;
  if ( v43 < (signed int)v41 + 1 )
  {
    v44 = 2 * v43;
    if ( v42 < v44 )
      v42 = v44;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v40 + 8, v42, 16);
  }
  ++v40[10];
  v45 = *((_QWORD *)v40 + 4) + 16 * v41;
  *(_DWORD *)v45 = 4;
  *(_QWORD *)(v45 + 4) = 3i64;
  *(_DWORD *)(v45 + 12) = -1;
  v46 = (signed int *)v1->m_geometry;
  v47 = v46[10];
  v48 = v47 + 1;
  v49 = v46[11] & 0x3FFFFFFF;
  if ( v49 < (signed int)v47 + 1 )
  {
    v50 = 2 * v49;
    if ( v48 < v50 )
      v48 = v50;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v46 + 8, v48, 16);
  }
  ++v46[10];
  v51 = (_DWORD *)(*((_QWORD *)v46 + 4) + 16 * v47);
  *v51 = 2;
  v51[1] = 6;
  v51[2] = 5;
  v51[3] = -1;
  v52 = (signed int *)v1->m_geometry;
  v53 = v52[10];
  v54 = v53 + 1;
  v55 = v52[11] & 0x3FFFFFFF;
  if ( v55 < (signed int)v53 + 1 )
  {
    v56 = 2 * v55;
    if ( v54 < v56 )
      v54 = v56;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v52 + 8, v54, 16);
  }
  ++v52[10];
  v57 = (_DWORD *)(*((_QWORD *)v52 + 4) + 16 * v53);
  *v57 = 2;
  v57[1] = 5;
  v57[2] = 1;
  v57[3] = -1;
  v58 = (signed int *)v1->m_geometry;
  v59 = v58[10];
  v60 = v59 + 1;
  v61 = v58[11] & 0x3FFFFFFF;
  if ( v61 < (signed int)v59 + 1 )
  {
    v62 = 2 * v61;
    if ( v60 < v62 )
      v60 = v62;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v58 + 8, v60, 16);
  }
  ++v58[10];
  v63 = (_DWORD *)(*((_QWORD *)v58 + 4) + 16 * v59);
  *v63 = 7;
  v63[1] = 6;
  v63[2] = 2;
  v63[3] = -1;
  v64 = (signed int *)v1->m_geometry;
  v65 = v64[10];
  v66 = v65 + 1;
  v67 = v64[11] & 0x3FFFFFFF;
  if ( v67 < (signed int)v65 + 1 )
  {
    v68 = 2 * v67;
    if ( v66 < v68 )
      v66 = v68;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v64 + 8, v66, 16);
  }
  ++v64[10];
  v69 = (_DWORD *)(*((_QWORD *)v64 + 4) + 16 * v65);
  *v69 = 7;
  v69[1] = 2;
  v69[2] = 3;
  v69[3] = -1;
  v70 = (signed int *)v1->m_geometry;
  v71 = v70[10];
  v72 = v71 + 1;
  v73 = v70[11] & 0x3FFFFFFF;
  if ( v73 < (signed int)v71 + 1 )
  {
    v74 = 2 * v73;
    if ( v72 < v74 )
      v72 = v74;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v70 + 8, v72, 16);
  }
  ++v70[10];
  v75 = (_DWORD *)(*((_QWORD *)v70 + 4) + 16 * v71);
  *v75 = 1;
  v75[1] = 5;
  v75[2] = 4;
  v75[3] = -1;
  v76 = (signed int *)v1->m_geometry;
  v77 = v76[10];
  v78 = v77 + 1;
  v79 = v76[11] & 0x3FFFFFFF;
  if ( v79 < (signed int)v77 + 1 )
  {
    v80 = 2 * v79;
    if ( v78 < v80 )
      v78 = v80;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v76 + 8, v78, 16);
  }
  ++v76[10];
  v81 = *((_QWORD *)v76 + 4) + 16 * v77;
  *(_DWORD *)v81 = 1;
  *(_QWORD *)(v81 + 4) = 4i64;
  *(_DWORD *)(v81 + 12) = -1;
}

// File Line: 85
// RVA: 0xE73980
void __fastcall hkDisplayBox::getWireframeGeometry(hkDisplayBox *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  hkArrayBase<hkVector4f> *v3; // rbx
  int v4; // eax
  hkDisplayBox *v5; // rdi
  int v6; // eax
  int v7; // er9
  float v8; // xmm1_4
  __m128i v9; // ST30_16
  int v10; // er11
  __int64 v11; // r10
  __int128 v12; // xmm0
  __int128 v13; // ST30_16
  __int128 v14; // xmm0
  __int128 v15; // ST30_16
  __int128 v16; // xmm0
  __int128 v17; // ST30_16
  float v18; // xmm1_4
  __int128 v19; // xmm0
  __int128 v20; // ST30_16
  __int128 v21; // xmm0
  __int128 v22; // ST30_16
  float v23; // xmm1_4
  __int128 v24; // xmm1
  __int128 *v25; // rdi
  __int128 v26; // xmm0
  __int128 v27; // ST30_16
  signed int v28; // er9
  signed __int64 v29; // rdx
  __int128 *v30; // rcx
  signed __int64 v31; // rdx
  _OWORD *v32; // rcx
  __int128 v33; // [rsp+40h] [rbp-29h]
  __int128 v34; // [rsp+50h] [rbp-19h]
  __int128 v35; // [rsp+60h] [rbp-9h]
  __int128 v36; // [rsp+70h] [rbp+7h]
  __int128 v37; // [rsp+80h] [rbp+17h]
  __int128 v38; // [rsp+90h] [rbp+27h]
  __int128 v39; // [rsp+A0h] [rbp+37h]
  __int128 v40; // [rsp+B0h] [rbp+47h]
  hkResult result; // [rsp+D8h] [rbp+6Fh]

  v3 = lines;
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
  v3->m_size = 24;
  LODWORD(v8) = v5->m_halfExtents;
  v9 = (__m128i)v5->m_halfExtents;
  _mm_store_si128((__m128i *)&v33, v9);
  v10 = 0;
  v11 = 0i64;
  *(float *)v9.m128i_i32 = v8 * -1.0;
  v12 = (__int128)v9;
  v13 = (__int128)v5->m_halfExtents;
  v34 = v12;
  *((float *)&v13 + 1) = v5->m_halfExtents.m_quad.m128_f32[1] * -1.0;
  v14 = v13;
  v15 = (__int128)v5->m_halfExtents;
  v35 = v14;
  *(float *)&v15 = *(float *)&v15 * -1.0;
  *((float *)&v15 + 1) = *((float *)&v15 + 1) * -1.0;
  v16 = v15;
  v17 = (__int128)v5->m_halfExtents;
  v18 = v5->m_halfExtents.m_quad.m128_f32[2] * -1.0;
  v36 = v16;
  *((float *)&v17 + 2) = v18;
  v19 = v17;
  v20 = (__int128)v5->m_halfExtents;
  v37 = v19;
  *(float *)&v20 = *(float *)&v20 * -1.0;
  *((float *)&v20 + 2) = *((float *)&v20 + 2) * -1.0;
  v21 = v20;
  v22 = (__int128)v5->m_halfExtents;
  v23 = v5->m_halfExtents.m_quad.m128_f32[1] * -1.0;
  v38 = v21;
  *((float *)&v22 + 1) = v23;
  v24 = (__int128)v5->m_halfExtents;
  v25 = &v33;
  *((float *)&v22 + 2) = *((float *)&v22 + 2) * -1.0;
  v26 = v22;
  v27 = v24;
  v39 = v26;
  *(float *)&v27 = *(float *)&v24 * -1.0;
  *((float *)&v27 + 2) = *((float *)&v24 + 2) * -1.0;
  *((float *)&v27 + 1) = *((float *)&v27 + 1) * -1.0;
  v40 = v27;
  do
  {
    v28 = 1;
    v29 = 16 * v11;
    do
    {
      if ( v10 < (v10 ^ v28) )
      {
        v30 = (__int128 *)((char *)v3->m_data + v29);
        v31 = v29 + 16;
        v11 += 2i64;
        *v30 = *v25;
        v32 = (_OWORD *)((char *)v3->m_data->m_quad.m128_f32 + v31);
        v29 = v31 + 16;
        *v32 = *(&v33 + (v10 ^ v28));
      }
      v28 *= 2;
    }
    while ( v28 < 8 );
    ++v10;
    ++v25;
  }
  while ( v10 < 8 );
}

