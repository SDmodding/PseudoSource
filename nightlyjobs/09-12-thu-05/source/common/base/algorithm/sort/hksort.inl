// File Line: 92
// RVA: 0xC704E0
void __fastcall hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(hkpRigidBody **pArr, int d, int h, hkBool *(__fastcall *cmpLess)(hkBool *result, hkpRigidBody *, hkpRigidBody *))
{
  int v4; // eax
  hkpRigidBody **v5; // rsi
  hkBool *(__fastcall *v6)(hkBool *, hkpRigidBody *, hkpRigidBody *); // r10
  __int64 v7; // rbx
  __int64 v8; // rcx
  int v9; // ebp
  __int64 v10; // rdi
  signed __int64 v11; // r9
  hkpRigidBody *v12; // rcx
  hkpRigidBody *v13; // rdi
  hkpRigidBody *v14; // rdx
  int v15; // ebp
  hkpRigidBody *v16; // rbx
  hkpRigidBody *v17; // r8
  hkpRigidBody *v18; // rcx
  int v19; // eax
  char v20; // [rsp+20h] [rbp-58h]
  int v21; // [rsp+24h] [rbp-54h]
  int v22; // [rsp+28h] [rbp-50h]
  hkpRigidBody *v23; // [rsp+30h] [rbp-48h]
  __int64 v24; // [rsp+40h] [rbp-38h]
  __int64 v25; // [rsp+48h] [rbp-30h]
  char v26; // [rsp+80h] [rbp+8h]
  int da; // [rsp+88h] [rbp+10h]
  int v28; // [rsp+90h] [rbp+18h]
  hkBool *(__fastcall *cmpLessa)(hkBool *, hkpRigidBody *, hkpRigidBody *); // [rsp+98h] [rbp+20h]

  cmpLessa = cmpLess;
  v28 = h;
  da = d;
  v4 = d;
  v5 = pArr;
  v6 = cmpLess;
  v7 = d;
  v8 = h;
  while ( 1 )
  {
    v9 = v4;
    v22 = v4;
    v10 = v8;
    v25 = v8;
    v11 = (signed __int64)(h + v4) >> 1;
    v21 = h;
    v24 = v7;
    v12 = v5[v11];
    v23 = v5[v11];
    while ( 1 )
    {
      if ( v6((hkBool *)&v26, v5[v7], v12)->m_bool )
      {
        v13 = v23;
        do
        {
          v14 = v5[v7++ + 1];
          ++v9;
        }
        while ( cmpLessa((hkBool *)&v26, v14, v13)->m_bool );
        v10 = v25;
        v22 = v9;
        v24 = v7;
      }
      if ( cmpLessa((hkBool *)&v20, v23, v5[v10])->m_bool )
      {
        v15 = v21;
        v16 = v23;
        do
        {
          v17 = v5[v10-- - 1];
          --v15;
        }
        while ( cmpLessa((hkBool *)&v20, v16, v17)->m_bool );
        v7 = v24;
        v21 = v15;
        v9 = v22;
      }
      if ( v10 < v7 )
        break;
      if ( v10 != v7 )
      {
        v18 = v5[v10];
        v5[v10] = v5[v7];
        v5[v7] = v18;
      }
      v12 = v23;
      --v10;
      ++v7;
      ++v9;
      v19 = v21-- - 1;
      v25 = v10;
      v22 = v9;
      v24 = v7;
      if ( v7 > v10 )
        goto LABEL_18;
      v6 = cmpLessa;
    }
    v19 = v21;
LABEL_18:
    if ( da < v19 )
      hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
        v5,
        da,
        v19,
        cmpLessa);
    h = v28;
    if ( v9 >= v28 )
      break;
    v6 = cmpLessa;
    v4 = v9;
    v8 = v28;
    da = v9;
  }
}

// File Line: 155
// RVA: 0xC915D0
void __fastcall hkAlgorithm::explicitStackQuickSort<unsigned int,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::SAHBin::Sorter>(unsigned int *base, int numMem, hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::SAHBin::Sorter *cmpLess)
{
  __m128 v3; // xmm4
  int v4; // edi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::SAHBin::Sorter *v5; // rbp
  __int64 v6; // rbx
  unsigned __int64 v7; // r11
  unsigned __int64 v8; // r10
  unsigned int *v9; // r8
  unsigned int *v10; // rax
  signed __int64 v11; // rsi
  hkcdDynamicTree::CodecRawUint *v12; // r9
  __m128 v13; // xmm5
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __int64 v19; // rcx
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __int64 v28; // rcx
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  unsigned int v32; // edx
  __int64 v33[64]; // [rsp+0h] [rbp-408h]
  __int64 v34[65]; // [rsp+200h] [rbp-208h]

  if ( numMem > 1 )
  {
    v3 = (__m128)xmmword_141A711B0;
    v4 = 0;
    v5 = cmpLess;
    v33[0] = (__int64)base;
    v34[0] = (__int64)&base[numMem - 1];
    v6 = 0i64;
    do
    {
      v7 = v33[v6];
      v8 = v34[v6];
      while ( 1 )
      {
        while ( 1 )
        {
          v9 = (unsigned int *)v7;
          v10 = (unsigned int *)v8;
          v11 = *(unsigned int *)(v7 + 4 * ((signed __int64)(v8 - v7) >> 3));
          do
          {
            v12 = v5->m_tree->m_nodes.m_data;
            v13 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v5->m_axis];
            v14 = _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(v12[v11].m_aabb.m_max.m_quad, v12[v11].m_aabb.m_min.m_quad), v3),
                    v13);
            v15 = _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(v12[*v9].m_aabb.m_max.m_quad, v12[*v9].m_aabb.m_min.m_quad), v3),
                    v13);
            v16 = _mm_or_ps(_mm_shuffle_ps(v14, v14, 78), v14);
            v17 = _mm_or_ps(_mm_shuffle_ps(v15, v15, 78), v15);
            if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v17, v17, 177) | v17.m128_i32[0]) < COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v16, v16, 177) | v16.m128_i32[0]) )
            {
              v18 = _mm_and_ps(
                      _mm_mul_ps(_mm_add_ps(v12[v11].m_aabb.m_max.m_quad, v12[v11].m_aabb.m_min.m_quad), v3),
                      v13);
              do
              {
                v19 = v9[1];
                ++v9;
                v20 = _mm_or_ps(_mm_shuffle_ps(v18, v18, 78), v18);
                v21 = _mm_and_ps(
                        _mm_mul_ps(_mm_add_ps(v12[v19].m_aabb.m_max.m_quad, v12[v19].m_aabb.m_min.m_quad), v3),
                        v13);
                v22 = _mm_or_ps(_mm_shuffle_ps(v21, v21, 78), v21);
              }
              while ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v22, v22, 177) | v22.m128_i32[0]) < COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v20, v20, 177) | v20.m128_i32[0]) );
            }
            v23 = _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(v12[v11].m_aabb.m_max.m_quad, v12[v11].m_aabb.m_min.m_quad), v3),
                    v13);
            v24 = _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(v12[*v10].m_aabb.m_max.m_quad, v12[*v10].m_aabb.m_min.m_quad), v3),
                    v13);
            v25 = _mm_or_ps(_mm_shuffle_ps(v24, v24, 78), v24);
            v26 = _mm_or_ps(_mm_shuffle_ps(v23, v23, 78), v23);
            if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v26, v26, 177) | v26.m128_i32[0]) < COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v25, v25, 177) | v25.m128_i32[0]) )
            {
              v27 = _mm_and_ps(
                      _mm_mul_ps(_mm_add_ps(v12[v11].m_aabb.m_max.m_quad, v12[v11].m_aabb.m_min.m_quad), v3),
                      v13);
              do
              {
                v28 = *(v10 - 1);
                --v10;
                v29 = _mm_and_ps(
                        _mm_mul_ps(_mm_add_ps(v12[v28].m_aabb.m_max.m_quad, v12[v28].m_aabb.m_min.m_quad), v3),
                        v13);
                v30 = _mm_or_ps(_mm_shuffle_ps(v29, v29, 78), v29);
                v31 = _mm_or_ps(_mm_shuffle_ps(v27, v27, 78), v27);
              }
              while ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v31, v31, 177) | v31.m128_i32[0]) < COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v30, v30, 177) | v30.m128_i32[0]) );
            }
            if ( v10 < v9 )
              break;
            if ( v10 != v9 )
            {
              v32 = *v10;
              *v10 = *v9;
              *v9 = v32;
              v3 = (__m128)xmmword_141A711B0;
            }
            --v10;
            ++v9;
          }
          while ( v9 <= v10 );
          if ( v7 >= (unsigned __int64)v10 )
            break;
          if ( (unsigned __int64)v9 >= v8 )
            goto LABEL_19;
          ++v4;
          if ( (signed __int64)((v8 - (_QWORD)v9) & 0xFFFFFFFFFFFFFFFCui64) <= (signed __int64)(((unsigned __int64)v10
                                                                                               - v7) & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v33[v6] = v7;
            v34[v6++] = (__int64)v10;
            v7 = (unsigned __int64)v9;
          }
          else
          {
            v33[v6] = (__int64)v9;
            v34[v6++] = v8;
LABEL_19:
            v8 = (unsigned __int64)v10;
          }
        }
        if ( (unsigned __int64)v9 >= v8 )
          break;
        v7 = (unsigned __int64)v9;
      }
      --v6;
    }
    while ( v6 >= 0 );
  }
}

