// File Line: 92
// RVA: 0xC704E0
void __fastcall hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
        hkpRigidBody **pArr,
        int d,
        int h,
        hkBool *(__fastcall *cmpLess)(hkBool *result, hkpRigidBody *, hkpRigidBody *))
{
  int v4; // eax
  hkBool *(__fastcall *v6)(hkBool *, hkpRigidBody *, hkpRigidBody *); // r10
  __int64 v7; // rbx
  __int64 v8; // rcx
  int v9; // ebp
  __int64 v10; // rdi
  hkpRigidBody *v11; // rcx
  hkpRigidBody *v12; // rdi
  hkpRigidBody *v13; // rdx
  int v14; // ebp
  hkpRigidBody *v15; // rbx
  hkpRigidBody *v16; // r8
  hkpRigidBody *v17; // rcx
  int v18; // eax
  char v19[4]; // [rsp+20h] [rbp-58h] BYREF
  int v20; // [rsp+24h] [rbp-54h]
  int v21; // [rsp+28h] [rbp-50h]
  hkpRigidBody *v22; // [rsp+30h] [rbp-48h]
  __int64 v23; // [rsp+40h] [rbp-38h]
  __int64 v24; // [rsp+48h] [rbp-30h]
  char v25; // [rsp+80h] [rbp+8h] BYREF
  int da; // [rsp+88h] [rbp+10h]
  int v27; // [rsp+90h] [rbp+18h]
  hkBool *(__fastcall *cmpLessa)(hkBool *, hkpRigidBody *, hkpRigidBody *); // [rsp+98h] [rbp+20h]

  cmpLessa = cmpLess;
  v27 = h;
  da = d;
  v4 = d;
  v6 = cmpLess;
  v7 = d;
  v8 = h;
  while ( 1 )
  {
    v9 = v4;
    v21 = v4;
    v10 = v8;
    v24 = v8;
    v20 = h;
    v23 = v7;
    v11 = pArr[(__int64)(h + v4) >> 1];
    v22 = v11;
    while ( 1 )
    {
      if ( v6((hkBool *)&v25, pArr[v7], v11)->m_bool )
      {
        v12 = v22;
        do
        {
          v13 = pArr[++v7];
          ++v9;
        }
        while ( cmpLessa((hkBool *)&v25, v13, v12)->m_bool );
        v10 = v24;
        v21 = v9;
        v23 = v7;
      }
      if ( cmpLessa((hkBool *)v19, v22, pArr[v10])->m_bool )
      {
        v14 = v20;
        v15 = v22;
        do
        {
          v16 = pArr[--v10];
          --v14;
        }
        while ( cmpLessa((hkBool *)v19, v15, v16)->m_bool );
        v7 = v23;
        v20 = v14;
        v9 = v21;
      }
      if ( v10 < v7 )
        break;
      if ( v10 != v7 )
      {
        v17 = pArr[v10];
        pArr[v10] = pArr[v7];
        pArr[v7] = v17;
      }
      v11 = v22;
      --v10;
      ++v7;
      ++v9;
      v18 = --v20;
      v24 = v10;
      v21 = v9;
      v23 = v7;
      if ( v7 > v10 )
        goto LABEL_18;
      v6 = cmpLessa;
    }
    v18 = v20;
LABEL_18:
    if ( da < v18 )
      hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
        pArr,
        da,
        v18,
        cmpLessa);
    h = v27;
    if ( v9 >= v27 )
      break;
    v6 = cmpLessa;
    v4 = v9;
    v8 = v27;
    da = v9;
  }
}

// File Line: 155
// RVA: 0xC915D0
void __fastcall hkAlgorithm::explicitStackQuickSort<unsigned int,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::SAHBin::Sorter>(
        unsigned int *base,
        int numMem,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::SAHBin::Sorter *cmpLess)
{
  __m128 v3; // xmm4
  int v4; // edi
  __int64 i; // rbx
  unsigned __int64 v7; // r11
  unsigned __int64 v8; // r10
  unsigned int *v9; // r8
  unsigned int *v10; // rax
  __int64 v11; // rsi
  hkcdDynamicTree::CodecRawUint *m_data; // r9
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
    v33[0] = (__int64)base;
    v34[0] = (__int64)&base[numMem - 1];
    for ( i = 0i64; i >= 0; --i )
    {
      v7 = v33[i];
      v8 = v34[i];
      while ( 1 )
      {
        while ( 1 )
        {
          v9 = (unsigned int *)v7;
          v10 = (unsigned int *)v8;
          v11 = *(unsigned int *)(v7 + 4 * ((__int64)(v8 - v7) >> 3));
          do
          {
            m_data = cmpLess->m_tree->m_nodes.m_data;
            v13 = (__m128)`hkVector4f::getComponent::`2::indexToMask[cmpLess->m_axis];
            v14 = _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(m_data[v11].m_aabb.m_max.m_quad, m_data[v11].m_aabb.m_min.m_quad), v3),
                    v13);
            v15 = _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(m_data[*v9].m_aabb.m_max.m_quad, m_data[*v9].m_aabb.m_min.m_quad), v3),
                    v13);
            v16 = _mm_or_ps(_mm_shuffle_ps(v14, v14, 78), v14);
            v17 = _mm_or_ps(_mm_shuffle_ps(v15, v15, 78), v15);
            if ( COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 177).m128_u32[0] | v17.m128_i32[0]) < COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 177).m128_u32[0] | v16.m128_i32[0]) )
            {
              v18 = _mm_and_ps(
                      _mm_mul_ps(_mm_add_ps(m_data[v11].m_aabb.m_max.m_quad, m_data[v11].m_aabb.m_min.m_quad), v3),
                      v13);
              do
              {
                v19 = v9[1];
                ++v9;
                v20 = _mm_or_ps(_mm_shuffle_ps(v18, v18, 78), v18);
                v21 = _mm_and_ps(
                        _mm_mul_ps(_mm_add_ps(m_data[v19].m_aabb.m_max.m_quad, m_data[v19].m_aabb.m_min.m_quad), v3),
                        v13);
                v22 = _mm_or_ps(_mm_shuffle_ps(v21, v21, 78), v21);
              }
              while ( COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 177).m128_u32[0] | v22.m128_i32[0]) < COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 177).m128_u32[0] | v20.m128_i32[0]) );
            }
            v23 = _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(m_data[v11].m_aabb.m_max.m_quad, m_data[v11].m_aabb.m_min.m_quad), v3),
                    v13);
            v24 = _mm_and_ps(
                    _mm_mul_ps(_mm_add_ps(m_data[*v10].m_aabb.m_max.m_quad, m_data[*v10].m_aabb.m_min.m_quad), v3),
                    v13);
            v25 = _mm_or_ps(_mm_shuffle_ps(v24, v24, 78), v24);
            v26 = _mm_or_ps(_mm_shuffle_ps(v23, v23, 78), v23);
            if ( COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 177).m128_u32[0] | v26.m128_i32[0]) < COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 177).m128_u32[0] | v25.m128_i32[0]) )
            {
              v27 = _mm_and_ps(
                      _mm_mul_ps(_mm_add_ps(m_data[v11].m_aabb.m_max.m_quad, m_data[v11].m_aabb.m_min.m_quad), v3),
                      v13);
              do
              {
                v28 = *--v10;
                v29 = _mm_and_ps(
                        _mm_mul_ps(_mm_add_ps(m_data[v28].m_aabb.m_max.m_quad, m_data[v28].m_aabb.m_min.m_quad), v3),
                        v13);
                v30 = _mm_or_ps(_mm_shuffle_ps(v29, v29, 78), v29);
                v31 = _mm_or_ps(_mm_shuffle_ps(v27, v27, 78), v27);
              }
              while ( COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 177).m128_u32[0] | v31.m128_i32[0]) < COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 177).m128_u32[0] | v30.m128_i32[0]) );
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
          if ( (__int64)((v8 - (_QWORD)v9) & 0xFFFFFFFFFFFFFFFCui64) <= (__int64)(((unsigned __int64)v10 - v7) & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v33[i] = v7;
            v34[i++] = (__int64)v10;
            v7 = (unsigned __int64)v9;
          }
          else
          {
            v33[i] = (__int64)v9;
            v34[i++] = v8;
LABEL_19:
            v8 = (unsigned __int64)v10;
          }
        }
        if ( (unsigned __int64)v9 >= v8 )
          break;
        v7 = (unsigned __int64)v9;
      }
    }
  }
}

