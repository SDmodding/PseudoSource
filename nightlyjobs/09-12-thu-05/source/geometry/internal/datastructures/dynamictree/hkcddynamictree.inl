// File Line: 280
// RVA: 0xDF28D0
hkSimdFloat32 *__fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::computeCost(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this, hkSimdFloat32 *result)
{
  unsigned __int64 v2; // rsi
  hkSimdFloat32 *v3; // r14
  float v4; // xmm7_4
  hkcdDynamicTree::CodecRawUlong *v5; // rdx
  unsigned __int64 v6; // rbp
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm6
  __int64 v10; // r11
  __int64 v11; // rbx
  signed int v12; // edi
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm9
  unsigned __int64 v19; // r9
  unsigned __int64 v20; // r10
  int v21; // ecx
  unsigned __int64 v22; // rcx
  unsigned __int64 i; // r8
  signed int v24; // er11
  __m128 v25; // xmm5
  unsigned __int64 v26; // r9
  unsigned __int64 v27; // r10
  int v28; // ecx
  unsigned __int64 v29; // rcx
  unsigned __int64 j; // r8
  __m128 v31; // xmm2
  unsigned __int64 v32; // rcx
  unsigned __int64 v33; // r8

  v2 = this->m_root;
  v3 = result;
  *result = 0i64;
  LODWORD(v4) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0eN7), (__m128)LODWORD(FLOAT_1_0eN7), 0);
  if ( v2 )
  {
    v5 = this->m_nodes.m_data;
    do
    {
      v6 = v2 << 6;
      if ( !LODWORD(v5[v2].m_children[0]) )
        goto LABEL_55;
      v7 = _mm_sub_ps(
             *(__m128 *)((char *)&v5->m_aabb.m_max.m_quad + v6),
             *(__m128 *)((char *)&v5->m_aabb.m_min.m_quad + v6));
      v8 = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v7);
      v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
      if ( v9.m128_f32[0] > v4 )
      {
        v10 = *(unsigned __int64 *)((char *)v5->m_children + v6);
        v11 = *(unsigned __int64 *)((char *)&v5->m_children[1] + v6);
        v12 = 0;
        v13 = _mm_sub_ps(
                v5[*(unsigned __int64 *)((char *)v5->m_children + v6)].m_aabb.m_max.m_quad,
                v5[*(unsigned __int64 *)((char *)v5->m_children + v6)].m_aabb.m_min.m_quad);
        v14 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v13);
        v15 = _mm_sub_ps(
                v5[*(unsigned __int64 *)((char *)&v5->m_children[1] + v6)].m_aabb.m_max.m_quad,
                v5[*(unsigned __int64 *)((char *)&v5->m_children[1] + v6)].m_aabb.m_min.m_quad);
        v16 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170));
        v17 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v15);
        v18 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170));
        if ( v10 )
        {
          if ( LODWORD(v5[v10].m_children[0]) )
          {
            v19 = v5[v10].m_children[0];
            while ( v19 )
            {
              v20 = v19 << 6;
              v21 = v5[v19].m_children[0];
              v12 += v21 == 0;
              if ( v21 )
              {
                v19 = *(unsigned __int64 *)((char *)v5->m_children + v20);
              }
              else
              {
                v22 = *(unsigned __int64 *)((char *)&v5->m_parent + v20);
                for ( i = v19; v22 != v10; v22 = v5[v22].m_parent )
                {
                  if ( v5[v22].m_children[1] != i )
                    break;
                  i = v22;
                }
                if ( v22 )
                  v19 = v5[v22].m_children[1];
                else
                  v19 = i;
                if ( v22 == v10 && v19 == i )
                  v19 = 0i64;
              }
            }
          }
          else
          {
            v12 = 1;
          }
        }
        v24 = 0;
        v25 = _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT((float)v12), (__m128)COERCE_UNSIGNED_INT((float)v12), 0);
        if ( v11 )
        {
          if ( LODWORD(v5[v11].m_children[0]) )
          {
            v26 = v5[v11].m_children[0];
            while ( v26 )
            {
              v27 = v26 << 6;
              v28 = v5[v26].m_children[0];
              v24 += v28 == 0;
              if ( v28 )
              {
                v26 = *(unsigned __int64 *)((char *)v5->m_children + v27);
              }
              else
              {
                v29 = *(unsigned __int64 *)((char *)&v5->m_parent + v27);
                for ( j = v26; v29 != v11; v29 = v5[v29].m_parent )
                {
                  if ( v5[v29].m_children[1] != j )
                    break;
                  j = v29;
                }
                if ( v29 )
                  v26 = v5[v29].m_children[1];
                else
                  v26 = j;
                if ( v29 == v11 && v26 == j )
                  v26 = 0i64;
              }
            }
          }
          else
          {
            v24 = 1;
          }
        }
        v31 = _mm_rcp_ps(v9);
        v3->m_real = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v9)), v31), v16),
                           v25),
                         v3->m_real),
                       _mm_mul_ps(
                         _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v9)), v31), v18),
                         _mm_shuffle_ps(
                           (__m128)COERCE_UNSIGNED_INT((float)v24),
                           (__m128)COERCE_UNSIGNED_INT((float)v24),
                           0)));
      }
      if ( *(_DWORD *)((char *)v5->m_children + v6) )
      {
        v2 = *(unsigned __int64 *)((char *)v5->m_children + v6);
      }
      else
      {
LABEL_55:
        v32 = *(unsigned __int64 *)((char *)&v5->m_parent + v6);
        v33 = v2;
        if ( !v32 )
          goto LABEL_45;
        while ( v5[v32].m_children[1] == v33 )
        {
          v33 = v32;
          v32 = v5[v32].m_parent;
          if ( !v32 )
            goto LABEL_45;
        }
        if ( v32 )
          v2 = v5[v32].m_children[1];
        else
LABEL_45:
          v2 = v33;
        if ( !v32 && v2 == v33 )
          v2 = 0i64;
      }
    }
    while ( v2 );
  }
  return v3;
}

// File Line: 305
// RVA: 0xDA4BA0
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16>::optimizeIncremental(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16> *this, int passes, int lookahead)
{
  unsigned __int16 v3; // ax
  int v4; // er15
  int v5; // er12
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16> *v6; // rsi
  unsigned int v7; // ecx
  __int64 v8; // r8
  hkcdDynamicTree::Codec32 *v9; // rdx
  signed __int64 v10; // rdi
  char v11; // al
  signed __int64 v12; // rdi
  signed __int64 v13; // r14
  signed __int64 v14; // rbx
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  signed __int64 v17; // rbp
  unsigned __int16 v18; // ax
  signed __int64 v19; // r11
  unsigned __int16 v20; // r8
  hkcdDynamicTree::Codec32 *v21; // rdx
  signed __int64 v22; // rbx
  unsigned __int16 v23; // r8
  signed __int64 v24; // rbx
  __m128 *v25; // rcx
  signed __int64 v26; // rax
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  signed __int64 v29; // rax
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  int i; // ecx
  hkcdDynamicTree::Codec32 *v33; // rcx
  __m128 v34; // xmm9
  __m128 v35; // xmm8
  __m128 *v36; // r9
  __m128 *v37; // r10
  unsigned __int16 v38; // cx
  __m128 v39; // xmm10
  __m128 v40; // xmm11
  __m128 *v41; // rcx
  __m128 *v42; // rdx
  __m128 v43; // xmm4
  __m128 v44; // xmm3
  __m128 v45; // xmm4
  __m128 v46; // xmm6
  __m128 v47; // xmm2
  __m128 v48; // xmm5
  __m128 v49; // xmm2
  __m128 v50; // xmm4
  __m128 v51; // xmm6
  __m128 v52; // xmm5
  __m128 v53; // xmm5
  unsigned __int16 v54; // ax
  signed __int64 v55; // r11
  __int64 v56; // rax
  int v57; // ecx
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 *v60; // [rsp+20h] [rbp-98h]
  __m128 *v61; // [rsp+28h] [rbp-90h]
  hkResult result; // [rsp+C8h] [rbp+10h]

  if ( passes > 0 )
  {
    v3 = this->m_root;
    v4 = lookahead;
    v5 = passes;
    v6 = this;
    if ( v3 )
    {
      if ( this->m_nodes.m_data[v3].m_aabb.m_max.m_quad.m128_i16[6] )
      {
        do
        {
          v7 = v6->m_path;
          v8 = v6->m_root;
          v9 = v6->m_nodes.m_data;
          v6->m_path = v7 + 1;
          v10 = (signed __int64)&v9[v8];
          do
          {
            v11 = v7;
            v7 = __ROR4__(v7, 1);
            v10 = (signed __int64)&v9[*(unsigned __int16 *)(v10 + 2i64 * (v11 & 1) + 28)];
          }
          while ( *(_WORD *)(v10 + 28) );
          v12 = (v10 - (signed __int64)v9) >> 5;
          v13 = (unsigned __int16)v12;
          v14 = (signed __int64)&v9[v13];
          v15 = v9[v13].m_aabb.m_min.m_quad;
          v16 = _mm_shuffle_ps(
                  v9[v13].m_aabb.m_max.m_quad,
                  _mm_unpackhi_ps(v9[v13].m_aabb.m_max.m_quad, (__m128)0i64),
                  196);
          if ( (_WORD)v12 == (_WORD)v8 )
          {
            v6->m_root = 0;
          }
          else
          {
            v17 = (signed __int64)&v9[*(unsigned __int16 *)(v14 + 12)];
            v18 = *(_WORD *)(v17 + 12);
            v19 = (signed __int64)&v9[*(unsigned __int16 *)(v17 + 2 * (15i64 - (*(_WORD *)(v17 + 30) == (_WORD)v12)))];
            if ( v18 )
            {
              *(_DWORD *)(v19 + 12) = v18 | 0x3F000000;
              v6->m_nodes.m_data->m_aabb.m_max.m_quad.m128_i16[16i64 * *(unsigned __int16 *)(v17 + 12)
                                                             + (v6->m_nodes.m_data[*(unsigned __int16 *)(v17 + 12)].m_aabb.m_max.m_quad.m128_i16[7] == *(_WORD *)(v14 + 12))
                                                             + 6] = (signed __int64)(v19
                                                                                   - (unsigned __int64)v6->m_nodes.m_data) >> 5;
              v20 = *(_WORD *)(v14 + 12);
              v6->m_nodes.m_data[*(unsigned __int16 *)(v14 + 12)].m_aabb.m_min.m_quad.m128_i16[0] = v6->m_firstFree;
              v21 = v6->m_nodes.m_data;
              v6->m_firstFree = v20;
              v22 = (signed __int64)&v21[*(unsigned __int16 *)(v19 + 12)];
              while ( 1 )
              {
                v23 = *(_WORD *)(v22 + 12);
                v24 = (v22 - (signed __int64)v21) >> 5;
                v25 = &v21[(unsigned __int16)v24].m_aabb.m_min.m_quad;
                v26 = v25[1].m128_u16[6];
                v27 = v21[v26].m_aabb.m_max.m_quad;
                v28 = v21[v26].m_aabb.m_min.m_quad;
                v29 = v25[1].m128_u16[7];
                v30 = _mm_min_ps(v28, v21[v29].m_aabb.m_min.m_quad);
                v31 = _mm_max_ps(
                        _mm_shuffle_ps(v27, _mm_unpackhi_ps(v27, (__m128)0i64), 196),
                        _mm_shuffle_ps(
                          v21[v29].m_aabb.m_max.m_quad,
                          _mm_unpackhi_ps(v21[v29].m_aabb.m_max.m_quad, (__m128)0i64),
                          196));
                *v25 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, *v25), 196);
                v25[1] = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, v25[1]), 196);
                if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v16, v31), _mm_cmpleps(v30, v15))) & 7) == 7 )
                  goto LABEL_16;
                if ( v23 )
                {
                  v21 = v6->m_nodes.m_data;
                  v22 = (signed __int64)&v6->m_nodes.m_data[v23];
                  if ( v22 )
                    continue;
                }
                goto LABEL_15;
              }
            }
            v9[v8].m_aabb.m_min.m_quad.m128_i16[0] = v6->m_firstFree;
            v6->m_firstFree = v8;
            v6->m_root = (signed __int64)(unsigned int)(v19 - LODWORD(v6->m_nodes.m_data)) >> 5;
            *(_DWORD *)(v19 + 12) = 1056964608;
          }
LABEL_15:
          LOWORD(v24) = v6->m_root;
LABEL_16:
          if ( (_WORD)v24 )
          {
            if ( v4 < 0 )
            {
              LOWORD(v24) = v6->m_root;
            }
            else
            {
              for ( i = v4; i; LOWORD(v24) = v6->m_nodes.m_data[(unsigned __int16)v24].m_aabb.m_min.m_quad.m128_i16[6] )
              {
                --i;
                if ( 0 == v6->m_nodes.m_data[(unsigned __int16)v24].m_aabb.m_min.m_quad.m128_i16[6] )
                  break;
              }
            }
          }
          v33 = v6->m_nodes.m_data;
          v34 = v6->m_nodes.m_data[v13].m_aabb.m_min.m_quad;
          v35 = _mm_shuffle_ps(
                  v6->m_nodes.m_data[v13].m_aabb.m_max.m_quad,
                  _mm_unpackhi_ps(v6->m_nodes.m_data[v13].m_aabb.m_max.m_quad, (__m128)0i64),
                  196);
          if ( (_WORD)v24 )
          {
            if ( !v6->m_firstFree )
              hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
                (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)&v6->m_nodes,
                &result,
                1);
            v36 = &v6->m_nodes.m_data[(unsigned __int16)v24].m_aabb.m_min.m_quad;
            v37 = &v6->m_nodes.m_data[v6->m_firstFree].m_aabb.m_min.m_quad;
            v6->m_firstFree = v37->m128_u64[0];
            v38 = v36[1].m128_u16[6];
            if ( v38 )
            {
              v39 = _mm_add_ps(v34, v35);
              v40 = _mm_sub_ps(v35, v34);
              do
              {
                v41 = &v6->m_nodes.m_data[v38].m_aabb.m_min.m_quad;
                v42 = &v6->m_nodes.m_data[v36[1].m128_u16[7]].m_aabb.m_min.m_quad;
                v43 = _mm_min_ps(v34, *v36);
                v44 = _mm_max_ps(v35, _mm_shuffle_ps(v36[1], _mm_unpackhi_ps(v36[1], (__m128)0i64), 196));
                v60 = v41;
                v61 = v42;
                *v36 = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, *v36), 196);
                v36[1] = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, v36[1]), 196);
                v45 = _mm_shuffle_ps(v41[1], _mm_unpackhi_ps(v41[1], (__m128)0i64), 196);
                v46 = _mm_shuffle_ps(v42[1], _mm_unpackhi_ps(v42[1], (__m128)0i64), 196);
                v47 = _mm_sub_ps(_mm_add_ps(*v41, v45), v39);
                v48 = _mm_add_ps(*v42, v46);
                v49 = _mm_mul_ps(v47, v47);
                v50 = _mm_add_ps(_mm_sub_ps(v45, *v41), v40);
                v51 = _mm_add_ps(_mm_sub_ps(v46, *v42), v40);
                v52 = _mm_sub_ps(v48, v39);
                v53 = _mm_mul_ps(v52, v52);
                v36 = *(&v60
                      + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 0)))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 170)))
                               * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 85))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 0)))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 170)))
                                                                                               * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v53, v53, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v53, v53, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v53, v53, 170))))));
                v38 = v36[1].m128_u16[6];
              }
              while ( v38 );
            }
            v54 = WORD2(v36->m128_u64[1]);
            v55 = ((char *)v37 - (char *)v6->m_nodes.m_data) >> 5;
            if ( v54 )
              v6->m_nodes.m_data->m_aabb.m_max.m_quad.m128_i16[16i64 * v54
                                                             + (v6->m_nodes.m_data[v54].m_aabb.m_max.m_quad.m128_i16[7] == (unsigned __int16)(((char *)v36 - (char *)v6->m_nodes.m_data) >> 5))
                                                             + 6] = v55;
            else
              v6->m_root = v55;
            HIDWORD(v37->m128_u64[1]) = WORD2(v36->m128_u64[1]) | 0x3F000000;
            v56 = (unsigned int)((_DWORD)v36 - LODWORD(v6->m_nodes.m_data));
            v37[1].m128_i16[7] = v12;
            v57 = (unsigned __int16)v55 | 0x3F000000;
            v37[1].m128_i16[6] = v56 >> 5;
            HIDWORD(v36->m128_u64[1]) = v57;
            v6->m_nodes.m_data[v13].m_aabb.m_min.m_quad.m128_i32[3] = v57;
            v58 = _mm_min_ps(*v36, v34);
            v59 = _mm_max_ps(_mm_shuffle_ps(v36[1], _mm_unpackhi_ps(v36[1], (__m128)0i64), 196), v35);
            *v37 = _mm_shuffle_ps(v58, _mm_unpackhi_ps(v58, *v37), 196);
            v37[1] = _mm_shuffle_ps(v59, _mm_unpackhi_ps(v59, v37[1]), 196);
          }
          else
          {
            v6->m_root = v12;
            v33[v13].m_aabb.m_min.m_quad.m128_i32[3] = 1056964608;
          }
          --v5;
        }
        while ( v5 );
      }
    }
  }
}

// File Line: 344
// RVA: 0xCC0120
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this, unsigned __int64 branch, hkBool minimize, int numBins, int bottomUpThreshold)
{
  __int64 v5; // rsi
  unsigned __int64 v6; // rdi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v7; // r15
  unsigned __int64 v8; // r14
  _QWORD **v9; // rax
  __int64 v10; // rax
  void *v11; // rbx
  int v12; // ecx
  hkcdDynamicTree::CodecRawUlong *v13; // rcx
  __int64 v14; // rax
  __m128 v15; // xmm10
  __m128 v16; // xmm11
  int v17; // edx
  hkcdDynamicTree::CodecRawUlong *v18; // rbx
  unsigned __int64 v19; // rdi
  signed __int64 v20; // rbx
  _DWORD *v21; // rbx
  int v22; // edx
  __int64 v23; // r8
  __m128 v24; // xmm13
  __m128 v25; // xmm14
  int v26; // er9
  __int64 v27; // r13
  __int64 v28; // r14
  __int64 v29; // rdi
  int *v30; // rbx
  int v31; // er8
  int v32; // eax
  signed __int64 v33; // rcx
  __int64 v34; // rdx
  int v35; // er9
  __int64 v36; // rdi
  int *v37; // rbx
  int v38; // er8
  __int64 v39; // rcx
  __int64 v40; // rdx
  int v41; // er9
  __int64 v42; // rdi
  int *v43; // rbx
  int v44; // er8
  __int64 v45; // rcx
  __int64 v46; // rdx
  int v47; // edx
  __int64 v48; // r12
  __int64 v49; // rax
  float v50; // xmm5_4
  signed int v51; // er10
  signed int v52; // er9
  signed int v53; // ebx
  __int128 v54; // xmm7
  signed __int64 v55; // r13
  __m128 v56; // xmm6
  hkcdDynamicTree::CodecRawUlong *v57; // rsi
  unsigned __int64 *v58; // rdi
  __int64 v59; // rdx
  signed __int64 v60; // r11
  int v61; // ecx
  unsigned __int64 v62; // rax
  __m128 v63; // xmm8
  __m128 v64; // xmm9
  _QWORD *v65; // rdx
  signed __int64 v66; // r8
  __int64 v67; // rax
  __m128 v68; // xmm3
  __m128 v69; // xmm4
  __m128 v70; // xmm3
  __m128 v71; // xmm0
  __m128 v72; // xmm1
  float v73; // xmm2_4
  __int64 v74; // r14
  unsigned __int64 v75; // rdi
  unsigned __int64 v76; // rsi
  unsigned __int64 v77; // r8
  hkcdDynamicTree::CodecRawUlong *v78; // rdx
  unsigned __int64 v79; // rcx
  __int64 v80; // rax
  unsigned __int64 v81; // r8
  __m128 v82; // xmm7
  __int64 v83; // rdx
  __m128 v84; // xmm6
  hkcdDynamicTree::CodecRawUlong *v85; // r8
  unsigned __int64 *v86; // rcx
  unsigned __int64 v87; // rax
  __m128 v88; // xmm9
  __m128 v89; // xmm1
  __m128 v90; // xmm8
  __int64 v91; // rbx
  hkcdDynamicTree::CodecRawUlong *v92; // rcx
  unsigned __int64 v93; // rdx
  __int64 v94; // rax
  _QWORD **v95; // rax
  hkArrayBase<char *> *v96; // rsi
  _QWORD **v97; // rax
  hkArrayBase<char *> *v98; // rdi
  int v99; // eax
  int v100; // er9
  int v101; // eax
  int v102; // eax
  int v103; // er9
  int v104; // eax
  int v105; // eax
  __int64 v106; // rcx
  __int64 v107; // rdx
  __int64 v108; // rax
  __int64 v109; // rax
  __int64 v110; // rax
  bool v111; // zf
  bool v112; // sf
  __m128 v113; // xmm6
  int v114; // er14
  __int64 v115; // rdi
  __m128 *v116; // rcx
  __m128 v117; // xmm4
  __m128 v118; // xmm3
  __m128 v119; // xmm1
  __m128i v120; // xmm2
  __int64 v121; // rax
  signed __int64 v122; // rcx
  __m128 v123; // xmm1
  __int64 v124; // rax
  signed __int64 v125; // rsi
  __m128 v126; // xmm1
  __int64 v127; // rax
  signed __int64 v128; // r13
  __m128 v129; // xmm1
  _DWORD *v130; // rbx
  __int64 v131; // rbx
  unsigned __int64 *v132; // rsi
  __int64 v133; // rbx
  __int64 *v134; // rax
  signed int v135; // er14
  __int64 v136; // rbx
  int v137; // edi
  float v138; // xmm3_4
  signed int v139; // er9
  __int64 v140; // r8
  int v141; // edx
  signed int v142; // er13
  __int64 v143; // rcx
  __m128 v144; // xmm4
  __m128 v145; // xmm5
  __m128 v146; // xmm6
  __m128 v147; // xmm7
  signed __int64 v148; // rsi
  __int64 v149; // r11
  signed int v150; // er13
  __m128 *v151; // rcx
  __m128 *v152; // r10
  signed int v153; // eax
  signed __int64 v154; // r11
  __m128 v155; // xmm0
  __m128 v156; // xmm2
  __m128 v157; // xmm0
  __m128 v158; // xmm2
  int v159; // er10
  signed __int64 v160; // rcx
  float *v161; // rax
  signed __int64 v162; // rbx
  __int64 v163; // r13
  hkArrayBase<char *> *v164; // r12
  __int64 v165; // r15
  int v166; // eax
  hkArrayBase<char *> *v167; // r15
  signed __int64 v168; // rdi
  __int64 v169; // rsi
  int v170; // ecx
  int v171; // edx
  __int64 v172; // rax
  __int64 v173; // r13
  int v174; // edi
  unsigned __int64 *v175; // rsi
  hkArrayBase<char *> *v176; // rcx
  char *const *v177; // r8
  int v178; // er9
  __int64 v179; // r8
  __int64 v180; // r13
  int v181; // er8
  _QWORD **v182; // rax
  __int64 v183; // rdi
  __int64 v184; // rax
  hkcdDynamicTree::CodecRawUlong *v185; // r9
  char v186; // r8
  unsigned __int64 v187; // rbx
  unsigned __int64 v188; // rsi
  __m128 *v189; // rdi
  __m128 *v190; // r11
  __m128 v191; // xmm0
  __m128 v192; // xmm2
  __m128 v193; // xmm1
  __m128 v194; // xmm3
  float v195; // xmm12_4
  __m128 *v196; // r8
  unsigned __int64 *v197; // r10
  signed __int64 v198; // r14
  unsigned __int64 v199; // rcx
  unsigned __int64 v200; // rdx
  __m128 *v201; // rcx
  __m128 *v202; // rdx
  __m128 v203; // xmm1
  __m128 v204; // xmm0
  __m128 v205; // xmm1
  __m128 v206; // xmm11
  __m128 v207; // xmm9
  __m128 v208; // xmm3
  __m128 v209; // xmm7
  __m128 v210; // xmm3
  __m128 v211; // xmm7
  __m128 v212; // xmm11
  __m128 v213; // xmm9
  __m128 v214; // xmm1
  __m128 v215; // xmm2
  __m128 v216; // xmm3
  __m128 v217; // xmm4
  __m128 v218; // xmm1
  BOOL v219; // er10
  _BOOL8 v220; // rcx
  __int64 v221; // rcx
  signed __int64 v222; // rdx
  __m128 v223; // xmm1
  int v224; // eax
  __m128 v225; // xmm0
  __m128 v226; // xmm1
  unsigned __int64 v227; // rcx
  unsigned __int64 i; // rdx
  hkcdDynamicTree::CodecRawUlong *v229; // rdx
  unsigned __int64 v230; // r10
  unsigned __int64 v231; // r9
  unsigned __int64 v232; // r8
  __m128 v233; // xmm0
  __m128 v234; // xmm3
  __m128 v235; // xmm1
  __m128 v236; // xmm2
  unsigned __int64 v237; // rcx
  unsigned __int64 j; // r8
  __int64 v239; // r8
  __int64 v240; // rdx
  hkcdDynamicTree::CodecRawUlong *v241; // rdx
  __int64 v242; // r8
  unsigned __int64 v243; // rax
  unsigned __int64 v244; // rcx
  __m128 v245; // xmm2
  int *v246; // rsi
  int v247; // eax
  __int64 v248; // rcx
  int v249; // eax
  __int64 v250; // rdi
  int *v251; // rbx
  int v252; // er8
  int v253; // er8
  __int64 v254; // [rsp+30h] [rbp-B0h]
  unsigned __int64 *v255; // [rsp+30h] [rbp-B0h]
  unsigned __int64 *v256; // [rsp+30h] [rbp-B0h]
  __int64 v257; // [rsp+30h] [rbp-B0h]
  void **array; // [rsp+38h] [rbp-A8h]
  int v259; // [rsp+40h] [rbp-A0h]
  int v260; // [rsp+44h] [rbp-9Ch]
  __int64 v261; // [rsp+48h] [rbp-98h]
  __int64 v262; // [rsp+50h] [rbp-90h]
  int v263; // [rsp+58h] [rbp-88h]
  int v264; // [rsp+5Ch] [rbp-84h]
  __int64 v265; // [rsp+60h] [rbp-80h]
  hkArrayBase<char *> *v266; // [rsp+68h] [rbp-78h]
  __int64 v267; // [rsp+70h] [rbp-70h]
  __int64 *v268; // [rsp+78h] [rbp-68h]
  hkArrayBase<char *> *v269; // [rsp+80h] [rbp-60h]
  int v270; // [rsp+88h] [rbp-58h]
  __int64 v271; // [rsp+90h] [rbp-50h]
  hkResult v272; // [rsp+98h] [rbp-48h]
  int v273; // [rsp+9Ch] [rbp-44h]
  __int64 v274; // [rsp+A0h] [rbp-40h]
  char *a; // [rsp+A8h] [rbp-38h]
  hkArrayBase<char *> *v276; // [rsp+B0h] [rbp-30h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::SAHBin::Sorter v277; // [rsp+C0h] [rbp-20h]
  __m128 v278; // [rsp+E0h] [rbp+0h]
  __int64 v279; // [rsp+F0h] [rbp+10h]
  hkResult v280; // [rsp+F8h] [rbp+18h]
  hkResult v281; // [rsp+FCh] [rbp+1Ch]
  __m128i v282; // [rsp+100h] [rbp+20h]
  __m128 v283; // [rsp+110h] [rbp+30h]
  __m128 v284; // [rsp+120h] [rbp+40h]
  __m128 v285; // [rsp+130h] [rbp+50h]
  __m128 v286; // [rsp+140h] [rbp+60h]
  __m128 v287; // [rsp+150h] [rbp+70h]
  __m128 v288; // [rsp+160h] [rbp+80h]
  __m128 v289; // [rsp+170h] [rbp+90h]
  __m128 v290; // [rsp+180h] [rbp+A0h]
  __m128 v291; // [rsp+190h] [rbp+B0h]
  __m128 v292; // [rsp+1A0h] [rbp+C0h]
  __m128 v293; // [rsp+1B0h] [rbp+D0h]
  __m128 v294; // [rsp+1C0h] [rbp+E0h]
  __m128 v295; // [rsp+1D0h] [rbp+F0h]
  __m128 v296; // [rsp+1E0h] [rbp+100h]
  __m128 v297; // [rsp+1F0h] [rbp+110h]
  __m128 v298; // [rsp+200h] [rbp+120h]
  __m128 v299; // [rsp+210h] [rbp+130h]
  __m128 v300; // [rsp+220h] [rbp+140h]
  char *v301; // [rsp+230h] [rbp+150h]
  int v302; // [rsp+238h] [rbp+158h]
  int v303; // [rsp+23Ch] [rbp+15Ch]
  char v304; // [rsp+240h] [rbp+160h]
  __m128 v305; // [rsp+440h] [rbp+360h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v306; // [rsp+540h] [rbp+460h]
  hkResult result; // [rsp+548h] [rbp+468h]
  char vars0; // [rsp+550h] [rbp+470h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v309; // [rsp+560h] [rbp+480h]

  if ( branch )
  {
    v309 = this;
    v5 = numBins;
    v6 = branch;
    v7 = this;
    if ( this->m_numLeaves > 2 )
    {
      v8 = branch << 6;
      if ( LODWORD(this->m_nodes.m_data[branch].m_children[0]) )
      {
        v260 = 2147483648;
        array = 0i64;
        v259 = 0;
        v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v10 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 32i64);
        v11 = (void *)v10;
        if ( v10 )
        {
          *(_QWORD *)v10 = 0i64;
          *(_DWORD *)(v10 + 8) = 0;
          *(_DWORD *)(v10 + 12) = 2147483648;
          *(_QWORD *)(v10 + 16) = 0i64;
          *(_DWORD *)(v10 + 24) = -1;
        }
        else
        {
          v11 = 0i64;
        }
        v12 = v259;
        if ( v259 == (v260 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
          v12 = v259;
        }
        array[v12] = v11;
        ++v259;
        v13 = v7->m_nodes.m_data;
        v14 = *(unsigned __int64 *)((char *)&v7->m_nodes.m_data->m_parent + v8);
        v279 = v14;
        v15 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        v16 = _mm_xor_ps((__m128)xmmword_141A712A0, v15);
        if ( v14 )
          LODWORD(v265) = v13[v14].m_children[1] == v6;
        else
          LODWORD(v265) = 0;
        v261 = 0i64;
        v17 = 0;
        v301 = &v304;
        v303 = -2147483584;
        while ( 1 )
        {
          v302 = v17;
          while ( 1 )
          {
            v18 = &v7->m_nodes.m_data[v6];
            if ( !LODWORD(v18->m_children[0]) )
              break;
            v19 = v18->m_children[1];
            if ( v17 == (v303 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v301, 8);
              v17 = v302;
            }
            *(_QWORD *)&v301[8 * v17] = v19;
            ++v302;
            v6 = v18->m_children[0];
            v20 = v18 - v7->m_nodes.m_data;
            v7->m_nodes.m_data[(signed __int64)(signed int)v20].m_aabb.m_min.m_quad.m128_u64[0] = v7->m_firstFree;
            v17 = v302;
            v7->m_firstFree = v20;
          }
          v21 = *array;
          if ( *((_DWORD *)*array + 2) == (*((_DWORD *)*array + 3) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, *array, 8);
          *(_QWORD *)(*(_QWORD *)v21 + 8i64 * (signed int)v21[2]++) = v6;
          if ( !v302 )
            break;
          v6 = *(_QWORD *)&v301[8 * v302 - 8];
          v17 = v302 - 1;
        }
        v302 = 0;
        if ( v303 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v301,
            8 * v303);
        v22 = 0;
        v23 = 0i64;
        v262 = 0i64;
        v264 = 2147483648;
        v263 = 0;
        v265 = 0i64;
        v266 = (hkArrayBase<char *> *)0x8000000000000000i64;
        v24 = _mm_shuffle_ps(
                (__m128)COERCE_UNSIGNED_INT((float)(signed int)v5),
                (__m128)COERCE_UNSIGNED_INT((float)(signed int)v5),
                0);
        v267 = 0i64;
        v268 = (__int64 *)0x8000000000000000i64;
        v25 = _mm_shuffle_ps(
                (__m128)COERCE_UNSIGNED_INT((float)(v5 - 1)),
                (__m128)COERCE_UNSIGNED_INT((float)(v5 - 1)),
                0);
        if ( (signed int)v5 > 0 )
        {
          v26 = v5;
          if ( (signed int)v5 < 0 )
            v26 = 0;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v262, v26, 64);
          v22 = v263;
          v23 = v262;
        }
        v27 = v5;
        v28 = v5 << 6;
        v267 = v5;
        v29 = v22 - (signed int)v5 - 1;
        if ( v22 - (signed int)v5 - 1 >= 0 )
        {
          v30 = (int *)((v29 << 6) + v23 + 12 + v28);
          do
          {
            v31 = *v30;
            *(v30 - 1) = 0;
            if ( v31 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v30 - 3),
                8 * v31);
            *(_QWORD *)(v30 - 3) = 0i64;
            *v30 = 2147483648;
            v30 -= 16;
            --v29;
          }
          while ( v29 >= 0 );
          v22 = v263;
          v23 = v262;
        }
        v32 = v5 - v22;
        v33 = v23 + ((signed __int64)v22 << 6);
        v34 = (signed int)v5 - v22;
        if ( v32 > 0 )
        {
          do
          {
            if ( v33 )
            {
              *(_QWORD *)v33 = 0i64;
              *(_DWORD *)(v33 + 8) = 0;
              *(_DWORD *)(v33 + 12) = 2147483648;
            }
            v33 += 64i64;
            --v34;
          }
          while ( v34 );
        }
        v263 = v5;
        if ( (HIDWORD(v266) & 0x3FFFFFFF) < (signed int)v5 )
        {
          v35 = v5;
          if ( (signed int)v5 < 2 * (HIDWORD(v266) & 0x3FFFFFFF) )
            v35 = 2 * (HIDWORD(v266) & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v265, v35, 64);
        }
        v36 = (signed int)v266 - (signed int)v5 - 1;
        if ( (signed int)v266 - (signed int)v5 - 1 >= 0 )
        {
          v37 = (int *)((v36 << 6) + v265 + 12 + v28);
          do
          {
            v38 = *v37;
            *(v37 - 1) = 0;
            if ( v38 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v37 - 3),
                8 * v38);
            *(_QWORD *)(v37 - 3) = 0i64;
            *v37 = 2147483648;
            v37 -= 16;
            --v36;
          }
          while ( v36 >= 0 );
        }
        v39 = (signed int)v5 - (signed int)v266;
        v40 = v265 + ((signed __int64)(signed int)v266 << 6);
        if ( (signed int)v5 - (signed int)v266 > 0 )
        {
          do
          {
            if ( v40 )
            {
              *(_QWORD *)v40 = 0i64;
              *(_DWORD *)(v40 + 8) = 0;
              *(_DWORD *)(v40 + 12) = 2147483648;
            }
            v40 += 64i64;
            --v39;
          }
          while ( v39 );
        }
        LODWORD(v266) = v5;
        if ( (HIDWORD(v268) & 0x3FFFFFFF) < (signed int)v5 )
        {
          v41 = v5;
          if ( (signed int)v5 < 2 * (HIDWORD(v268) & 0x3FFFFFFF) )
            v41 = 2 * (HIDWORD(v268) & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v267, v41, 64);
        }
        v42 = (signed int)v268 - (signed int)v5 - 1;
        if ( (signed int)v268 - (signed int)v5 - 1 >= 0 )
        {
          v43 = (int *)((v42 << 6) + v267 + 12 + v28);
          do
          {
            v44 = *v43;
            *(v43 - 1) = 0;
            if ( v44 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v43 - 3),
                8 * v44);
            *(_QWORD *)(v43 - 3) = 0i64;
            *v43 = 2147483648;
            v43 -= 16;
            --v42;
          }
          while ( v42 >= 0 );
        }
        v45 = (signed int)v5 - (signed int)v268;
        v46 = v267 + ((signed __int64)(signed int)v268 << 6);
        if ( (signed int)v5 - (signed int)v268 > 0 )
        {
          do
          {
            if ( v46 )
            {
              *(_QWORD *)v46 = 0i64;
              *(_DWORD *)(v46 + 8) = 0;
              *(_DWORD *)(v46 + 12) = 2147483648;
            }
            v46 += 64i64;
            --v45;
          }
          while ( v45 );
        }
        v47 = v259;
        v274 = 2i64;
        LODWORD(v268) = v5;
        do
        {
          v48 = (__int64)array[v47 - 1];
          v259 = v47 - 1;
          v49 = *(signed int *)(v48 + 8);
          v271 = v48;
          if ( (signed int)v49 > (signed int)v309 || *(_DWORD *)(v48 + 24) == -1 )
          {
            v82 = (__m128)xmmword_141A712A0;
            v83 = v49;
            v84 = _mm_xor_ps(v15, (__m128)xmmword_141A712A0);
            if ( (signed int)v49 > 0 )
            {
              v85 = v7->m_nodes.m_data;
              v86 = *(unsigned __int64 **)v48;
              do
              {
                v87 = *v86;
                ++v86;
                v87 <<= 6;
                v82 = _mm_min_ps(v82, *(__m128 *)((char *)&v85->m_aabb.m_min.m_quad + v87));
                v84 = _mm_max_ps(v84, *(__m128 *)((char *)&v85->m_aabb.m_max.m_quad + v87));
                --v83;
              }
              while ( v83 );
            }
            v88 = 0i64;
            v89 = _mm_sub_ps(v84, v82);
            v90 = _mm_mul_ps(
                    (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_andnot_ps(_mm_cmpeqps(v89, (__m128)0i64), _mm_div_ps(query.m_quad, v89)),
                                4),
                              4),
                    v24);
            if ( !v7->m_firstFree )
              hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
                (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)&v7->m_nodes,
                &v281,
                1);
            v91 = v7->m_firstFree;
            v92 = v7->m_nodes.m_data;
            v93 = v7->m_firstFree << 6;
            v7->m_firstFree = v7->m_nodes.m_data[(signed __int64)(signed int)v91].m_aabb.m_min.m_quad.m128_u64[0];
            *(__m128 *)((char *)&v92->m_aabb.m_min.m_quad + v93) = v82;
            *(__m128 *)((char *)&v92->m_aabb.m_max.m_quad + v93) = v84;
            *(unsigned __int64 *)((char *)&v7->m_nodes.m_data->m_parent + v93) = *(_QWORD *)(v48 + 16);
            v94 = *(signed int *)(v48 + 24);
            if ( (_DWORD)v94 == -1 )
              v261 = v91;
            else
              v7->m_nodes.m_data->m_children[v94 + 8i64 * *(_QWORD *)(v48 + 16)] = v91;
            v95 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v96 = (hkArrayBase<char *> *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v95[11] + 8i64))(
                                           v95[11],
                                           32i64);
            v266 = v96;
            if ( v96 )
            {
              v96->m_capacityAndFlags = 2147483648;
              v96->m_data = 0i64;
              v96->m_size = 0;
              v96[1].m_data = (char **)v91;
              v96[1].m_size = 0;
            }
            else
            {
              v96 = 0i64;
              v266 = 0i64;
            }
            a = (char *)v96;
            v97 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v98 = (hkArrayBase<char *> *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v97[11] + 8i64))(
                                           v97[11],
                                           32i64);
            v269 = v98;
            if ( v98 )
            {
              v98->m_capacityAndFlags = 2147483648;
              v98->m_data = 0i64;
              v98->m_size = 0;
              v98[1].m_data = (char **)v91;
              v98[1].m_size = 1;
            }
            else
            {
              v98 = 0i64;
              v269 = 0i64;
            }
            v99 = v96->m_capacityAndFlags;
            v100 = *(_DWORD *)(v48 + 8);
            v276 = v98;
            v101 = v99 & 0x3FFFFFFF;
            if ( v101 >= v100 )
            {
              LODWORD(v96) = 0;
              result.m_enum = 0;
            }
            else
            {
              v102 = 2 * v101;
              if ( v100 < v102 )
                v100 = v102;
              hkArrayUtil::_reserve(
                &result,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                v96,
                v100,
                8);
              LODWORD(v96) = 0;
            }
            v103 = *(_DWORD *)(v48 + 8);
            v104 = v98->m_capacityAndFlags & 0x3FFFFFFF;
            if ( v104 >= v103 )
            {
              v272.m_enum = 0;
            }
            else
            {
              v105 = 2 * v104;
              if ( v103 < v105 )
                v103 = v105;
              hkArrayUtil::_reserve(&v272, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v98, v103, 8);
            }
            hkArrayBase<unsigned __int64>::_append(
              (hkArrayBase<char *> *)&array,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &a,
              2);
            if ( v27 > 0 )
            {
              v106 = 0i64;
              v107 = v27;
              do
              {
                v108 = v262;
                v106 += 64i64;
                *(_DWORD *)(v262 + v106 - 56) = 0;
                *(_OWORD *)(v108 + v106 - 48) = xmmword_141A712A0;
                *(__m128 *)(v108 + v106 - 32) = _mm_xor_ps(v15, (__m128)xmmword_141A712A0);
                *(_DWORD *)(v108 + v106 - 16) = 0;
                v109 = v265;
                *(_DWORD *)(v265 + v106 - 56) = 0;
                *(_OWORD *)(v109 + v106 - 48) = xmmword_141A712A0;
                *(__m128 *)(v109 + v106 - 32) = _mm_xor_ps((__m128)xmmword_141A712A0, v15);
                *(_DWORD *)(v109 + v106 - 16) = 0;
                v110 = v267;
                *(_DWORD *)(v267 + v106 - 56) = 0;
                *(_OWORD *)(v110 + v106 - 48) = xmmword_141A712A0;
                *(__m128 *)(v110 + v106 - 32) = _mm_xor_ps(v15, (__m128)xmmword_141A712A0);
                *(_DWORD *)(v110 + v106 - 16) = 0;
                --v107;
              }
              while ( v107 );
            }
            v111 = *(_DWORD *)(v48 + 8) == 0;
            v112 = *(_DWORD *)(v48 + 8) < 0;
            v113 = v24;
            v278 = 0i64;
            v114 = 0;
            v284 = v24;
            if ( !v112 && !v111 )
            {
              v115 = 0i64;
              do
              {
                v116 = &v7->m_nodes.m_data[*(_QWORD *)(v115 * 8 + *(_QWORD *)v48)].m_aabb.m_min.m_quad;
                v117 = v116[1];
                v118 = *v116;
                v119 = _mm_min_ps(
                         _mm_max_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_sub_ps(_mm_mul_ps(_mm_add_ps(v116[1], *v116), (__m128)xmmword_141A711B0), v82),
                               v90),
                             (__m128)xmmword_141A711B0),
                           aabbOut.m_quad),
                         v25);
                v88 = _mm_max_ps(v119, v88);
                v113 = _mm_min_ps(v119, v113);
                v120 = _mm_xor_si128(
                         (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v119),
                         _mm_cvttps_epi32(v119));
                v121 = v262;
                v122 = (signed __int64)_mm_cvtsi128_si32(v120) << 6;
                v123 = _mm_max_ps(*(__m128 *)(v262 + v122 + 32), v117);
                *(__m128 *)(v262 + v122 + 16) = _mm_min_ps(*(__m128 *)(v262 + v122 + 16), v118);
                *(__m128 *)(v121 + v122 + 32) = v123;
                v124 = v265;
                v125 = (signed __int64)_mm_cvtsi128_si32(_mm_srli_si128(v120, 4)) << 6;
                v126 = _mm_max_ps(*(__m128 *)(v265 + v125 + 32), v117);
                *(__m128 *)(v265 + v125 + 16) = _mm_min_ps(*(__m128 *)(v265 + v125 + 16), v118);
                *(__m128 *)(v124 + v125 + 32) = v126;
                v127 = v267;
                v128 = (signed __int64)_mm_cvtsi128_si32(_mm_srli_si128(v120, 8)) << 6;
                v129 = _mm_max_ps(*(__m128 *)(v267 + v128 + 32), v117);
                *(__m128 *)(v267 + v128 + 16) = _mm_min_ps(*(__m128 *)(v267 + v128 + 16), v118);
                *(__m128 *)(v127 + v128 + 32) = v129;
                v130 = (_DWORD *)(v122 + v262);
                v255 = *(unsigned __int64 **)v48;
                if ( *(_DWORD *)(v122 + v262 + 8) == (*(_DWORD *)(v122 + v262 + 12) & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v130, 8);
                *(_QWORD *)(*(_QWORD *)v130 + 8i64 * (signed int)v130[2]++) = v255[v115];
                v256 = *(unsigned __int64 **)v48;
                v131 = v125 + v265;
                if ( *(_DWORD *)(v125 + v265 + 8) == (*(_DWORD *)(v125 + v265 + 12) & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    (void *)(v125 + v265),
                    8);
                *(_QWORD *)(*(_QWORD *)v131 + 8i64 * (signed int)(*(_DWORD *)(v131 + 8))++) = v256[v115];
                v132 = *(unsigned __int64 **)v48;
                v133 = v128 + v267;
                if ( *(_DWORD *)(v128 + v267 + 8) == (*(_DWORD *)(v128 + v267 + 12) & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    (void *)(v128 + v267),
                    8);
                *(_QWORD *)(*(_QWORD *)v133 + 8i64 * (signed int)(*(_DWORD *)(v133 + 8))++) = v132[v115];
                ++v114;
                ++v115;
              }
              while ( v114 < *(_DWORD *)(v48 + 8) );
              v284 = v113;
              v278 = v88;
              LODWORD(v96) = 0;
            }
            v134 = &v262;
            v135 = 0;
            v136 = 0i64;
            v137 = -1;
            v138 = FLOAT_3_40282e38;
            v139 = 0;
            v268 = &v262;
            v140 = 0i64;
            do
            {
              v141 = (signed int)v284.m128_f32[v140];
              v142 = (signed int)v278.m128_f32[v140];
              v143 = *v134;
              v270 = (signed int)v96;
              v273 = (signed int)v96;
              v144 = (__m128)xmmword_141A712A0;
              v145 = v16;
              v146 = (__m128)xmmword_141A712A0;
              v147 = v16;
              v148 = v141;
              v149 = v142;
              v257 = v143;
              if ( v141 <= (signed __int64)v142 )
              {
                v150 = v273;
                v151 = (__m128 *)((v149 << 6) + 16 + v143);
                v152 = (__m128 *)(((signed __int64)v141 << 6) + v257 + 16);
                v153 = v270;
                v154 = v149 - v141 + 1;
                do
                {
                  v145 = _mm_max_ps(v145, v152[1]);
                  v144 = _mm_min_ps(v144, *v152);
                  v153 += v152[-1].m128_i32[2];
                  v150 += v151[-1].m128_i32[2];
                  v152 += 4;
                  v147 = _mm_max_ps(v147, v151[1]);
                  v146 = _mm_min_ps(v146, *v151);
                  v155 = _mm_sub_ps(v145, v144);
                  v151 -= 4;
                  v156 = _mm_mul_ps(_mm_shuffle_ps(v155, v155, 201), v155);
                  v157 = _mm_sub_ps(v147, v146);
                  v152[-2].m128_f32[0] = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v156, v156, 85))
                                                               + COERCE_FLOAT(_mm_shuffle_ps(v156, v156, 0)))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v156, v156, 170)))
                                               * (float)v153)
                                       + v152[-2].m128_f32[0];
                  v158 = _mm_mul_ps(_mm_shuffle_ps(v157, v157, 201), v157);
                  v151[6].m128_f32[0] = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 85))
                                                              + COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 0)))
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 170)))
                                              * (float)v150)
                                      + v151[6].m128_f32[0];
                  --v154;
                }
                while ( v154 );
                v142 = (signed int)v278.m128_f32[v140];
                v143 = v257;
                v134 = v268;
              }
              if ( v141 <= v142 )
              {
                if ( v142 - v141 + 1 >= 4 )
                {
                  v159 = v141 + 2;
                  v160 = ((signed __int64)v141 << 6) + v143 + 48;
                  v148 = v141 + 4i64 * (((unsigned int)(v142 - 3 - v141) >> 2) + 1);
                  do
                  {
                    if ( *(_DWORD *)(v160 - 40) && *(float *)v160 < v138 )
                    {
                      v135 = v139;
                      v136 = v140;
                      v138 = *(float *)v160;
                      v137 = v141;
                    }
                    if ( *(_DWORD *)(v160 + 24) && *(float *)(v160 + 64) < v138 )
                    {
                      v135 = v139;
                      v136 = v140;
                      v138 = *(float *)(v160 + 64);
                      v137 = v159 - 1;
                    }
                    if ( *(_DWORD *)(v160 + 88) && *(float *)(v160 + 128) < v138 )
                    {
                      v135 = v139;
                      v136 = v140;
                      v138 = *(float *)(v160 + 128);
                      v137 = v159;
                    }
                    if ( *(_DWORD *)(v160 + 152) && *(float *)(v160 + 192) < v138 )
                    {
                      v135 = v139;
                      v136 = v140;
                      v138 = *(float *)(v160 + 192);
                      v137 = v159 + 1;
                    }
                    v141 += 4;
                    v160 += 256i64;
                    v159 += 4;
                  }
                  while ( v141 <= v142 - 3 );
                }
                if ( v141 <= v142 )
                {
                  v161 = (float *)((v148 << 6) + v257 + 48);
                  do
                  {
                    if ( *((_DWORD *)v161 - 10) && *v161 < v138 )
                    {
                      v135 = v139;
                      v136 = v140;
                      v138 = *v161;
                      v137 = v141;
                    }
                    ++v141;
                    v161 += 16;
                  }
                  while ( v141 <= v142 );
                }
                v134 = v268;
              }
              v134 += 2;
              ++v139;
              ++v140;
              v268 = v134;
              v96 = 0i64;
            }
            while ( v139 < 3 );
            v162 = 2 * v136;
            v163 = v137;
            if ( v137 > 0 )
            {
              v164 = v266;
              v165 = v137;
              do
              {
                hkArrayBase<unsigned __int64>::_append(
                  v164,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  *(char *const **)((char *)&v96->m_data + *(&v262 + v162)),
                  *(int *)((char *)&v96->m_size + *(&v262 + v162)));
                v96 += 4;
                --v165;
              }
              while ( v165 );
              v7 = v306;
              v48 = v271;
            }
            v166 = v137 + 1;
            if ( v137 + 1 < v267 )
            {
              v167 = v269;
              v168 = (signed __int64)v166 << 6;
              v169 = v267 - v166;
              do
              {
                hkArrayBase<unsigned __int64>::_append(
                  v167,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  *(char *const **)(v168 + *(&v262 + v162)),
                  *(_DWORD *)(v168 + *(&v262 + v162) + 8));
                v168 += 64i64;
                --v169;
              }
              while ( v169 );
              v7 = v306;
            }
            v170 = v266->m_size;
            v171 = v269->m_size;
            if ( v170 && v171 || !(v170 | v171) )
            {
              v172 = *(&v262 + v162);
              v173 = v163 << 6;
              v282.m128i_i32[0] = v135;
              v174 = *(_DWORD *)(v173 + v172 + 8);
              v175 = *(unsigned __int64 **)(v173 + v172);
              v282.m128i_i64[1] = (__int64)v7;
              _mm_store_si128((__m128i *)&v277, v282);
              hkAlgorithm::explicitStackQuickSort<unsigned __int64,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::SAHBin::Sorter>(
                v175,
                v174,
                &v277);
              hkArrayBase<unsigned __int64>::_append(
                v266,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                (char *const *)v175,
                v174 >> 1);
              v176 = v269;
              v177 = (char *const *)&v175[v174 >> 1];
              v178 = v174 - (v174 >> 1);
            }
            else
            {
              v179 = *(&v262 + v162);
              v180 = v163 << 6;
              v178 = *(_DWORD *)(v180 + v179 + 8);
              v177 = *(char *const **)(v180 + v179);
              v176 = (hkArrayBase<char *> *)(&a)[v171 == 0];
            }
            hkArrayBase<unsigned __int64>::_append(
              v176,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v177,
              v178);
          }
          else
          {
            for ( ; (signed int)v49 > 1; LODWORD(v49) = *(_DWORD *)(v48 + 8) )
            {
              v50 = *(float *)&xmmword_141A712A0;
              v51 = -1;
              v52 = 0;
              v53 = -1;
              v54 = xmmword_141A712A0;
              v55 = (signed int)v49;
              v56 = _mm_xor_ps((__m128)xmmword_141A712A0, v15);
              if ( (signed int)v49 > 0 )
              {
                v57 = v7->m_nodes.m_data;
                v58 = *(unsigned __int64 **)v48;
                v59 = (signed int)v49;
                v254 = (signed int)v49;
                v60 = 1i64;
                do
                {
                  v61 = v52 + 1;
                  v62 = *v58 << 6;
                  v63 = *(__m128 *)((char *)&v57->m_aabb.m_min.m_quad + v62);
                  v64 = *(__m128 *)((char *)&v57->m_aabb.m_max.m_quad + v62);
                  if ( v60 < v55 )
                  {
                    v65 = v58 + 1;
                    v66 = v55 - v60;
                    do
                    {
                      v67 = *v65 << 6;
                      v68 = *(__m128 *)((char *)&v57->m_aabb.m_min.m_quad + v67);
                      v69 = _mm_max_ps(*(__m128 *)((char *)&v57->m_aabb.m_max.m_quad + v67), v64);
                      v305 = v68;
                      v70 = _mm_min_ps(v68, v63);
                      v71 = _mm_sub_ps(v69, v70);
                      v72 = _mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v71);
                      v73 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 85))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 0)))
                          + COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 170));
                      if ( v73 < v50 )
                      {
                        v50 = v73;
                        v54 = (__int128)v70;
                        v56 = v69;
                        v51 = v52;
                        v53 = v61;
                      }
                      ++v61;
                      ++v65;
                      --v66;
                    }
                    while ( v66 );
                    v59 = v254;
                  }
                  ++v52;
                  ++v58;
                  ++v60;
                  v254 = --v59;
                }
                while ( v59 );
              }
              v74 = v51;
              v75 = *(_QWORD *)(*(_QWORD *)v48 + 8i64 * v51);
              v76 = *(_QWORD *)(*(_QWORD *)v48 + 8i64 * v53);
              if ( !v7->m_firstFree )
                hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
                  (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)&v7->m_nodes,
                  &v280,
                  1);
              v77 = v7->m_firstFree;
              v78 = v7->m_nodes.m_data;
              v79 = v7->m_firstFree << 6;
              v7->m_firstFree = v7->m_nodes.m_data[(signed __int64)(signed int)v77].m_aabb.m_min.m_quad.m128_u64[0];
              *(hkVector4f *)((char *)&v78->m_aabb.m_min + v79) = (hkVector4f)v54;
              *(__m128 *)((char *)&v78->m_aabb.m_max.m_quad + v79) = v56;
              *(unsigned __int64 *)((char *)v7->m_nodes.m_data->m_children + v79) = v75;
              *(unsigned __int64 *)((char *)&v7->m_nodes.m_data->m_children[1] + v79) = v76;
              v7->m_nodes.m_data[v75].m_parent = v77;
              v7->m_nodes.m_data[v76].m_parent = v77;
              v80 = (signed int)--*(_DWORD *)(v48 + 8);
              if ( (_DWORD)v80 != v53 )
                *(_QWORD *)(*(_QWORD *)v48 + 8i64 * v53) = *(_QWORD *)(*(_QWORD *)v48 + 8 * v80);
              *(_QWORD *)(*(_QWORD *)v48 + 8 * v74) = v77;
            }
            v81 = **(_QWORD **)v48;
            v7->m_nodes.m_data[**(_QWORD **)v48].m_parent = *(_QWORD *)(v48 + 16);
            v7->m_nodes.m_data->m_children[*(signed int *)(v48 + 24) + 8i64 * *(_QWORD *)(v48 + 16)] = v81;
          }
          v181 = *(_DWORD *)(v48 + 12);
          *(_DWORD *)(v48 + 8) = 0;
          if ( v181 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)v48,
              8 * v181);
          *(_QWORD *)v48 = 0i64;
          *(_DWORD *)(v48 + 12) = 2147483648;
          v182 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v182[11] + 16i64))(v182[11], v48, 32i64);
          v47 = v259;
          v27 = v267;
        }
        while ( v259 );
        if ( vars0 )
        {
          v183 = v261;
          v184 = v261 << 6;
          v267 = v261 << 6;
          do
          {
            v185 = v7->m_nodes.m_data;
            v186 = 0;
            v187 = *(unsigned __int64 *)((char *)v7->m_nodes.m_data->m_children + v184);
            LOBYTE(result.m_enum) = 0;
            if ( !v187 )
              break;
            do
            {
              v188 = v187 << 6;
              if ( LODWORD(v185[v187].m_children[0]) )
              {
                v189 = &v185[*(unsigned __int64 *)((char *)v185->m_children + v188)].m_aabb.m_min.m_quad;
                v190 = &v185[*(unsigned __int64 *)((char *)&v185->m_children[1] + v188)].m_aabb.m_min.m_quad;
                v191 = _mm_sub_ps(v190[1], *v190);
                v192 = _mm_sub_ps(v189[1], *v189);
                v193 = _mm_mul_ps(_mm_shuffle_ps(v192, v192, 201), v192);
                v194 = _mm_mul_ps(_mm_shuffle_ps(v191, v191, 201), v191);
                v195 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v193, v193, 85))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v193, v193, 0)))
                             + COERCE_FLOAT(_mm_shuffle_ps(v193, v193, 170)))
                     + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v194, v194, 85))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v194, v194, 0)))
                             + COERCE_FLOAT(_mm_shuffle_ps(v194, v194, 170)));
                if ( v189[2].m128_i32[2] && v190[2].m128_i32[2] )
                {
                  v196 = &v298;
                  v197 = &v190[2].m128_u64[1];
                  v198 = 2i64;
                  do
                  {
                    v196 += 2;
                    v199 = *(unsigned __int64 *)((char *)v197 + (char *)v189 - (char *)v190) << 6;
                    v200 = *v197 << 6;
                    ++v197;
                    v201 = (__m128 *)((char *)&v185->m_aabb.m_min.m_quad + v199);
                    v202 = (__m128 *)((char *)&v185->m_aabb.m_min.m_quad + v200);
                    *(unsigned __int64 *)((char *)v197 + (char *)&v272 - (char *)v190 - 8) = (unsigned __int64)v201;
                    *(unsigned __int64 *)((char *)v197 + (char *)&a - (char *)v190 - 8) = (unsigned __int64)v202;
                    v203 = v201[1];
                    v196[-7] = *v201;
                    v204 = *v202;
                    v196[-6] = v203;
                    v205 = v202[1];
                    v196[-3] = v204;
                    v196[-2] = v205;
                    --v198;
                  }
                  while ( v198 );
                  v7 = v306;
                  v206 = _mm_max_ps(v294, v300);
                  v207 = _mm_max_ps(v296, v298);
                  v290 = v206;
                  v208 = _mm_max_ps(v296, v300);
                  v209 = _mm_max_ps(v294, v298);
                  v288 = v208;
                  v286 = v209;
                  v292 = v207;
                  v289 = _mm_min_ps(v293, v299);
                  v287 = _mm_min_ps(v295, v299);
                  v285 = _mm_min_ps(v293, v297);
                  v291 = _mm_min_ps(v295, v297);
                  v210 = _mm_sub_ps(v208, v287);
                  v211 = _mm_sub_ps(v209, v285);
                  v212 = _mm_sub_ps(v206, v289);
                  v213 = _mm_sub_ps(v207, v291);
                  v214 = _mm_mul_ps(_mm_shuffle_ps(v210, v210, 201), v210);
                  v215 = _mm_mul_ps(_mm_shuffle_ps(v211, v211, 201), v211);
                  v216 = _mm_mul_ps(_mm_shuffle_ps(v213, v213, 201), v213);
                  v217 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v214, v214, 85), _mm_shuffle_ps(v214, v214, 0)),
                             _mm_shuffle_ps(v214, v214, 170)),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v215, v215, 85), _mm_shuffle_ps(v215, v215, 0)),
                             _mm_shuffle_ps(v215, v215, 170)));
                  v218 = _mm_mul_ps(_mm_shuffle_ps(v212, v212, 201), v212);
                  v282 = (__m128i)v217;
                  v283 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v218, v218, 85), _mm_shuffle_ps(v218, v218, 0)),
                             _mm_shuffle_ps(v218, v218, 170)),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v216, v216, 85), _mm_shuffle_ps(v216, v216, 0)),
                             _mm_shuffle_ps(v216, v216, 170)));
                  v219 = v217.m128_f32[0] >= v283.m128_f32[0];
                  v220 = v217.m128_f32[0] >= v283.m128_f32[0];
                  if ( COERCE_FLOAT(*((_OWORD *)&v282 + v220)) >= v195 )
                  {
                    v186 = result.m_enum;
                  }
                  else
                  {
                    v189[3].m128_u64[0] = (*((_QWORD *)&v277.m_axis
                                           + (signed int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH'::`77'::lut[v220][0])
                                         - (_QWORD)v185) >> 6;
                    v190[2].m128_u64[1] = (signed __int64)(*((_QWORD *)&v277.m_axis
                                                           + (signed int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH'::`77'::lut[v220][1])
                                                         - (unsigned __int64)v7->m_nodes.m_data) >> 6;
                    v190[3].m128_u64[0] = (signed __int64)(*((_QWORD *)&v277.m_axis
                                                           + (signed int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH'::`77'::lut[v220][2])
                                                         - (unsigned __int64)v7->m_nodes.m_data) >> 6;
                    *(_QWORD *)(*((_QWORD *)&v277.m_axis
                                + (signed int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH'::`77'::lut[v220][0])
                              + 32i64) = ((char *)v189 - (char *)v7->m_nodes.m_data) >> 6;
                    *(_QWORD *)(*((_QWORD *)&v277.m_axis
                                + (signed int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH'::`77'::lut[v220][1])
                              + 32i64) = ((char *)v190 - (char *)v7->m_nodes.m_data) >> 6;
                    v221 = *((_QWORD *)&v277.m_axis
                           + (signed int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH'::`77'::lut[v220][2]);
                    v186 = 1;
                    v222 = ((char *)v190 - (char *)v7->m_nodes.m_data) >> 6;
                    LOBYTE(result.m_enum) = 1;
                    *(_QWORD *)(v221 + 32) = v222;
                    v223 = *(&v286 + 4 * v219);
                    v224 = 2 * v219 + 1;
                    *v189 = *(&v285 + 4 * v219);
                    v225 = *(&v285 + 2 * v224);
                    v189[1] = v223;
                    v226 = *(&v286 + 2 * v224);
                    *v190 = v225;
                    v190[1] = v226;
                  }
                }
                v183 = v261;
              }
              v185 = v7->m_nodes.m_data;
              if ( *(_DWORD *)((char *)v7->m_nodes.m_data->m_children + v188) )
              {
                v187 = *(unsigned __int64 *)((char *)v185->m_children + v188);
              }
              else
              {
                v227 = *(unsigned __int64 *)((char *)&v185->m_parent + v188);
                for ( i = v187; v227 != v183; v227 = v185[v227].m_parent )
                {
                  if ( v185[v227].m_children[1] != i )
                    break;
                  i = v227;
                }
                if ( v227 )
                  v187 = v185[v227].m_children[1];
                else
                  v187 = i;
                if ( v227 == v183 && v187 == i )
                  v187 = 0i64;
              }
            }
            while ( v187 );
            v184 = v267;
          }
          while ( v186 );
          v229 = v7->m_nodes.m_data;
          v230 = *(unsigned __int64 *)((char *)v7->m_nodes.m_data->m_children + v184);
          while ( v230 )
          {
            v231 = v230 << 6;
            if ( LODWORD(v229[v230].m_children[0]) )
            {
              v232 = *(unsigned __int64 *)((char *)v229->m_children + v231);
              v233 = _mm_sub_ps(
                       v229[*(unsigned __int64 *)((char *)v229->m_children + v231)].m_aabb.m_max.m_quad,
                       v229[*(unsigned __int64 *)((char *)v229->m_children + v231)].m_aabb.m_min.m_quad);
              v234 = _mm_sub_ps(
                       v229[*(unsigned __int64 *)((char *)&v229->m_children[1] + v231)].m_aabb.m_max.m_quad,
                       v229[*(unsigned __int64 *)((char *)&v229->m_children[1] + v231)].m_aabb.m_min.m_quad);
              v235 = _mm_mul_ps(_mm_shuffle_ps(v233, v233, 201), v233);
              v236 = _mm_mul_ps(_mm_shuffle_ps(v234, v234, 201), v234);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v236, v236, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v236, v236, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v236, v236, 170))) > (float)((float)(COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                v235,
                                                                                                v235,
                                                                                                85))
                                                                                          + COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                v235,
                                                                                                v235,
                                                                                                0)))
                                                                                  + COERCE_FLOAT(_mm_shuffle_ps(v235, v235, 170))) )
              {
                *(unsigned __int64 *)((char *)v229->m_children + v231) = *(unsigned __int64 *)((char *)&v229->m_children[1]
                                                                                             + v231);
                *(unsigned __int64 *)((char *)&v229->m_children[1] + v231) = v232;
              }
            }
            v229 = v7->m_nodes.m_data;
            if ( *(_DWORD *)((char *)v7->m_nodes.m_data->m_children + v231) )
            {
              v230 = *(unsigned __int64 *)((char *)v229->m_children + v231);
            }
            else
            {
              v237 = *(unsigned __int64 *)((char *)&v229->m_parent + v231);
              for ( j = v230; v237 != v183; v237 = v229[v237].m_parent )
              {
                if ( v229[v237].m_children[1] != j )
                  break;
                j = v237;
              }
              if ( v237 )
                v230 = v229[v237].m_children[1];
              else
                v230 = j;
              if ( v237 == v183 && v230 == j )
                v230 = 0i64;
            }
          }
        }
        v239 = v279;
        v240 = v261;
        v7->m_nodes.m_data[v261].m_parent = v279;
        if ( v239 )
        {
          v7->m_nodes.m_data->m_children[(signed int)v265 + 8 * v239] = v240;
          v241 = v7->m_nodes.m_data;
          do
          {
            v242 = v239 << 6;
            v243 = *(unsigned __int64 *)((char *)v241->m_children + v242) << 6;
            v244 = *(unsigned __int64 *)((char *)&v241->m_children[1] + v242) << 6;
            v245 = _mm_max_ps(
                     *(__m128 *)((char *)&v241->m_aabb.m_max.m_quad + v243),
                     *(__m128 *)((char *)&v241->m_aabb.m_max.m_quad + v244));
            *(__m128 *)((char *)&v241->m_aabb.m_min.m_quad + v242) = _mm_min_ps(
                                                                       *(__m128 *)((char *)&v241->m_aabb.m_min.m_quad
                                                                                 + v243),
                                                                       *(__m128 *)((char *)&v241->m_aabb.m_min.m_quad
                                                                                 + v244));
            *(__m128 *)((char *)&v241->m_aabb.m_max.m_quad + v242) = v245;
            v241 = v7->m_nodes.m_data;
            v239 = *(unsigned __int64 *)((char *)&v7->m_nodes.m_data->m_parent + v242);
          }
          while ( v239 );
        }
        else
        {
          v7->m_root = v240;
        }
        v246 = (int *)((char *)&v266 + 4);
        do
        {
          v247 = *(v246 - 5);
          v248 = *(_QWORD *)(v246 - 7);
          v246 -= 4;
          v249 = v247 - 1;
          v250 = v249;
          if ( v249 >= 0 )
          {
            v251 = (int *)(((signed __int64)v249 << 6) + v248 + 12);
            do
            {
              v252 = *v251;
              *(v251 - 1) = 0;
              if ( v252 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  *(void **)(v251 - 3),
                  8 * v252);
              *(_QWORD *)(v251 - 3) = 0i64;
              *v251 = 2147483648;
              v251 -= 16;
              --v250;
            }
            while ( v250 >= 0 );
          }
          v253 = *v246;
          *(v246 - 1) = 0;
          if ( v253 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)(v246 - 3),
              v253 << 6);
          v112 = (signed int)v274 - 1 < 0;
          LODWORD(v274) = v274 - 1;
          *(_QWORD *)(v246 - 3) = 0i64;
          *v246 = 2147483648;
        }
        while ( !v112 );
        v259 = 0;
        if ( v260 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            8 * v260);
      }
    }
  }
}

// File Line: 661
// RVA: 0xDF4730
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildGlobalSAH(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this, int minBins, int maxBins, int step)
{
  int v4; // ebx
  int v5; // er14
  int v6; // esi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v7; // rdi
  float v8; // xmm7_4
  float v9; // xmm6_4
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree output; // [rsp+30h] [rbp-C8h]
  hkSimdFloat32 result; // [rsp+60h] [rbp-98h]
  hkErrStream v15; // [rsp+70h] [rbp-88h]
  char buf; // [rsp+88h] [rbp-70h]

  v4 = minBins;
  v5 = step;
  v6 = maxBins;
  v7 = (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *)this;
  output.m_nodes.m_capacityAndFlags = 2147483648;
  output.m_nodes.m_size = 0;
  output.m_nodes.m_data = 0i64;
  output.m_firstFree = 0i64;
  output.m_root = 0i64;
  *(_QWORD *)&output.m_numLeaves = 0i64;
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
    this,
    &output);
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::computeCost(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&output.m_nodes,
    &result);
  if ( v4 <= v6 )
  {
    v8 = result.m_real.m128_f32[0];
    do
    {
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(
        (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&v7->m_nodes,
        v7->m_root,
        (hkBool)1,
        v4,
        16);
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::computeCost(
        (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&v7->m_nodes,
        &result);
      v9 = result.m_real.m128_f32[0];
      if ( result.m_real.m128_f32[0] < v8 )
      {
        hkErrStream::hkErrStream(&v15, &buf, 512);
        v10 = hkOstream::operator<<((hkOstream *)&v15.vfptr, "#");
        v11 = hkOstream::operator<<(v10, v4, (int)v10);
        v12 = hkOstream::operator<<(v11, ": ");
        hkOstream::operator<<(v12, v9, (int)v12);
        hkError::messageReport(
          -1,
          &buf,
          "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/DynamicTree/hkcdDynamicTree.inl",
          670);
        hkOstream::~hkOstream((hkOstream *)&v15.vfptr);
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
          (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&v7->m_nodes,
          &output);
        v8 = v9;
      }
      v4 += v5;
    }
    while ( v4 <= v6 );
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&output.m_nodes,
    v7);
  output.m_nodes.m_size = 0;
  if ( output.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output.m_nodes.m_data,
      output.m_nodes.m_capacityAndFlags << 6);
}

// File Line: 711
// RVA: 0xCBED00
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *output)
{
  int v2; // er8
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *v3; // rbx
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v4; // r15
  int v5; // esi
  int v6; // eax
  int v7; // er9
  unsigned __int64 v8; // rsi
  signed __int64 v9; // r14
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rsi
  hkcdDynamicTree::CodecRawUlong *v12; // rdi
  hkVector4f v13; // xmm6
  hkVector4f v14; // xmm7
  unsigned __int64 v15; // rdx
  hkcdDynamicTree::CodecRawUlong *v16; // r8
  __int64 v17; // r14
  int v18; // ecx
  _QWORD *array; // [rsp+30h] [rbp-D0h]
  int v20; // [rsp+38h] [rbp-C8h]
  int v21; // [rsp+3Ch] [rbp-C4h]
  __int64 *v22; // [rsp+40h] [rbp-C0h]
  int v23; // [rsp+48h] [rbp-B8h]
  int v24; // [rsp+4Ch] [rbp-B4h]
  __int64 v25; // [rsp+50h] [rbp-B0h]
  hkResult result; // [rsp+2A0h] [rbp+1A0h]

  v2 = output->m_nodes.m_capacityAndFlags;
  v3 = output;
  v4 = this;
  output->m_nodes.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output->m_nodes.m_data,
      v2 << 6);
  v3->m_nodes.m_data = 0i64;
  v3->m_nodes.m_capacityAndFlags = 2147483648;
  v3->m_firstFree = 0i64;
  v3->m_root = 0i64;
  *(_QWORD *)&v3->m_numLeaves = 0i64;
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
    (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)&v3->m_nodes,
    &result,
    2 * v4->m_numLeaves);
  if ( v4->m_root )
  {
    v5 = v4->m_nodes.m_size;
    v6 = 0;
    array = 0i64;
    v21 = 2147483648;
    v20 = 0;
    if ( v5 > 0 )
    {
      v7 = v5;
      if ( v5 < 0 )
        v7 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v7, 8);
      v6 = v20;
    }
    if ( v5 - v6 > 0 )
      memset(&array[v6], 0, 8i64 * (v5 - v6));
    v20 = v5;
    v8 = v4->m_root;
    v22 = &v25;
    v24 = -2147483584;
    v25 = 0i64;
    v23 = 1;
    v9 = 0i64;
    do
    {
      v10 = v8;
      v11 = array[(signed int)v8];
      v12 = &v4->m_nodes.m_data[v10];
      v13.m_quad = (__m128)v12->m_aabb.m_min;
      v14.m_quad = (__m128)v12->m_aabb.m_max;
      if ( !v3->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)&v3->m_nodes,
          &result,
          1);
      v15 = v3->m_firstFree;
      v16 = &v3->m_nodes.m_data[v3->m_firstFree];
      v3->m_firstFree = v3->m_nodes.m_data[(signed __int64)(signed int)v15].m_aabb.m_min.m_quad.m128_u64[0];
      v16->m_parent = v11;
      v16->m_aabb.m_min = (hkVector4f)v13.m_quad;
      v16->m_aabb.m_max = (hkVector4f)v14.m_quad;
      if ( v11 )
        v3->m_nodes.m_data->m_children[v9 + 8 * v11] = v15;
      else
        v3->m_root = v15;
      v8 = v12->m_children[0];
      v17 = v12->m_children[1];
      if ( (_DWORD)v8 )
      {
        array[(signed int)v8] = v15;
        array[(signed int)v17] = v15;
        v18 = v23;
        if ( v23 == (v24 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v22, 8);
          v18 = v23;
        }
        v22[v18] = v17;
        ++v23;
        v9 = 0i64;
      }
      else
      {
        v16->m_children[1] = v17;
        v16->m_children[0] = v8;
        v9 = 1i64;
        v8 = v22[v23-- - 1];
      }
    }
    while ( v8 );
    v23 = 0;
    if ( v24 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v22,
        8 * v24);
    v22 = 0i64;
    v24 = 2147483648;
    v20 = 0;
    if ( v21 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v21);
  }
  v3->m_numLeaves = v4->m_numLeaves;
  v3->m_path = v4->m_path;
}

// File Line: 770
// RVA: 0xCBFD20
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::compactIndices(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this)
{
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v1; // rbx
  hkRelocationInfo::Import *v2; // rax
  int v3; // er8
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v4; // [rsp+20h] [rbp-38h]
  __int128 v5; // [rsp+30h] [rbp-28h]
  __int64 v6; // [rsp+40h] [rbp-18h]

  v1 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this;
  if ( this->m_root )
  {
    v4.m_size = 0;
    v4.m_data = 0i64;
    v5 = 0ui64;
    v6 = 0i64;
    v4.m_capacityAndFlags = 2147483648;
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
      this,
      (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *)&v4);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(&v4, v1);
    v2 = v1[1].m_data;
    v3 = v4.m_capacityAndFlags;
    v1[1].m_data = (hkRelocationInfo::Import *)v5;
    v4.m_size = 0;
    v1[2].m_data = (hkRelocationInfo::Import *)1;
    *(_QWORD *)&v5 = v2;
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v4.m_data,
        v3 << 6);
  }
}

// File Line: 783
// RVA: 0xDF2C50
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::detachBranch(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this, unsigned __int64 node, unsigned __int64 leafData, hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *branchOut)
{
  int v4; // er8
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v5; // rsi
  unsigned __int64 v6; // rdi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v7; // r14
  int v8; // er8
  hkcdDynamicTree::CodecRawUlong *v9; // rax
  unsigned __int64 v10; // rbx
  hkcdDynamicTree::CodecRawUlong *v11; // r9
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rax
  unsigned __int64 i; // rdx
  int v15; // eax
  int v16; // er12
  __int64 j; // r15
  signed int *v18; // rdx
  unsigned __int64 v19; // r13
  hkcdDynamicTree::CodecRawUlong *v20; // rax
  unsigned __int64 v21; // r9
  hkcdDynamicTree::CodecRawUlong *v22; // rdi
  int v23; // ebx
  unsigned __int64 v24; // rcx
  hkVector4f v25; // xmm1
  unsigned __int64 v26; // rdx
  unsigned __int64 v27; // rax
  __int64 v28; // r9
  __int64 v29; // r8
  int v30; // edi
  __int64 v31; // r14
  int v32; // eax
  signed __int64 v33; // rbx
  int v34; // eax
  unsigned __int64 v35; // rdx
  int v36; // eax
  signed int *array; // [rsp+20h] [rbp-50h]
  int v38; // [rsp+28h] [rbp-48h]
  int v39; // [rsp+2Ch] [rbp-44h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v40; // [rsp+30h] [rbp-40h]
  hkResult result; // [rsp+88h] [rbp+18h]
  unsigned __int64 v42; // [rsp+90h] [rbp+20h]
  __int64 v43; // [rsp+98h] [rbp+28h]

  v42 = leafData;
  v4 = branchOut->m_nodes.m_capacityAndFlags;
  v5 = branchOut;
  v6 = node;
  branchOut->m_nodes.m_size = 0;
  v7 = this;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      branchOut->m_nodes.m_data,
      v4 << 6);
  v5->m_nodes.m_data = 0i64;
  v5->m_nodes.m_capacityAndFlags = 2147483648;
  v5->m_firstFree = 0i64;
  v5->m_root = 0i64;
  *(_QWORD *)&v5->m_numLeaves = 0i64;
  array = 0i64;
  v8 = 0;
  v38 = 0;
  v39 = 2147483648;
  if ( v6 )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
    *(_QWORD *)&array[2 * v38] = v6;
    v9 = v7->m_nodes.m_data;
    v8 = v38++ + 1;
    if ( LODWORD(v9[v6].m_children[0]) )
    {
      v10 = v9[v6].m_children[0];
      if ( v10 )
      {
        while ( 1 )
        {
          if ( v8 == (v39 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v8 = v38;
          }
          *(_QWORD *)&array[2 * v8] = v10;
          v8 = v38++ + 1;
          if ( !v10 )
            goto LABEL_19;
          v11 = v7->m_nodes.m_data;
          v12 = v10 << 6;
          if ( !LODWORD(v7->m_nodes.m_data[v10].m_children[0]) )
            break;
          v10 = *(unsigned __int64 *)((char *)v11->m_children + v12);
LABEL_20:
          if ( !v10 )
            goto LABEL_21;
        }
        v13 = *(unsigned __int64 *)((char *)&v11->m_parent + v12);
        for ( i = v10; v13 != v6; v13 = v11[v13].m_parent )
        {
          if ( v11[v13].m_children[1] != i )
            break;
          i = v13;
        }
        if ( v13 )
          v10 = v11[v13].m_children[1];
        else
          v10 = i;
        if ( v13 != v6 || v10 != i )
          goto LABEL_20;
LABEL_19:
        v10 = 0i64;
        goto LABEL_20;
      }
    }
  }
LABEL_21:
  v40.m_elem = 0i64;
  v40.m_numElems = 0;
  v40.m_hashMod = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &v40,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v8);
  v15 = v38;
  v16 = 0;
  for ( j = 0i64; v16 < v38; ++j )
  {
    v18 = array;
    v19 = *(_QWORD *)&array[2 * j];
    if ( !v5->m_firstFree )
    {
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
        (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)&v5->m_nodes,
        &result,
        1);
      v18 = array;
    }
    v20 = v5->m_nodes.m_data;
    v43 = v5->m_firstFree;
    v21 = (signed int)v43;
    v5->m_firstFree = v20[(signed __int64)(signed int)v43].m_aabb.m_min.m_quad.m128_u64[0];
    v22 = &v7->m_nodes.m_data[v19];
    v23 = LODWORD(v22->m_children[0]) == 0;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v40,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v18[2 * j],
      v21);
    v24 = v22->m_parent;
    v25.m_quad = (__m128)v22->m_aabb.m_max;
    v26 = v22->m_children[0];
    v27 = v22->m_children[1];
    v28 = v43;
    v29 = (__int64)&v5->m_nodes.m_data[v43];
    *(hkVector4f *)v29 = v22->m_aabb.m_min;
    *(hkVector4f *)(v29 + 16) = (hkVector4f)v25.m_quad;
    *(_QWORD *)(v29 + 32) = v24;
    *(_QWORD *)(v29 + 40) = v26;
    *(_QWORD *)(v29 + 48) = v27;
    v5->m_numLeaves += v23;
    v7->m_numLeaves -= v23;
    if ( j )
    {
      v7->m_nodes.m_data[(signed __int64)(signed int)v19].m_aabb.m_min.m_quad.m128_u64[0] = v7->m_firstFree;
      v7->m_firstFree = v19;
    }
    else
    {
      ++v7->m_numLeaves;
      v22->m_children[1] = v42;
      v22->m_children[0] = 0i64;
      v5->m_root = v28;
    }
    v15 = v38;
    ++v16;
  }
  v30 = 0;
  if ( v15 > 0 )
  {
    v31 = 0i64;
    do
    {
      v32 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                &v40,
                                array[v31]);
      v33 = (signed __int64)&v5->m_nodes.m_data[(signed __int64)SLODWORD(v40.m_elem[v32].val)];
      *(_QWORD *)(v33 + 32) = (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                            &v40,
                                            *(signed int *)(v33 + 32),
                                            0i64);
      if ( *(_DWORD *)(v33 + 40) )
      {
        v34 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v40,
                                  *(signed int *)(v33 + 40));
        v35 = *(signed int *)(v33 + 48);
        *(_QWORD *)(v33 + 40) = SLODWORD(v40.m_elem[v34].val);
        v36 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v40,
                                  v35);
        *(_QWORD *)(v33 + 48) = SLODWORD(v40.m_elem[v36].val);
      }
      ++v30;
      v31 += 2i64;
    }
    while ( v30 < v38 );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v40,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  v38 = 0;
  if ( v39 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v39);
}

// File Line: 862
// RVA: 0xDF4A20
signed __int64 __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rotateLeft(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this, unsigned __int64 node)
{
  hkcdDynamicTree::CodecRawUlong *v2; // r11
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v3; // r10
  hkcdDynamicTree::CodecRawUlong *v4; // r8
  signed __int64 result; // rax
  hkcdDynamicTree::CodecRawUlong *v6; // r9
  unsigned __int64 v7; // rdi
  hkcdDynamicTree::CodecRawUlong *v8; // rcx
  unsigned __int64 v9; // r8
  __int64 v10; // rax
  __int64 v11; // rcx
  __m128 v12; // xmm1
  unsigned __int64 v13; // r8
  __int64 v14; // rax
  __int64 v15; // rcx
  __m128 v16; // xmm2

  v2 = this->m_nodes.m_data;
  v3 = this;
  v4 = &this->m_nodes.m_data[node];
  if ( !LODWORD(v4->m_children[0]) )
    return 0i64;
  v6 = &v2[v4->m_children[1]];
  if ( !LODWORD(v6->m_children[0]) )
    return 0i64;
  v7 = v4->m_parent;
  v8 = &v2[v6->m_children[0]];
  v8->m_parent = v4 - v2;
  v4->m_children[1] = v8 - v3->m_nodes.m_data;
  v4->m_parent = v6 - v3->m_nodes.m_data;
  v6->m_children[0] = v4 - v3->m_nodes.m_data;
  v6->m_parent = v7;
  v9 = (unsigned __int64)v3->m_nodes.m_data + (((char *)v4 - (char *)v3->m_nodes.m_data) & 0xFFFFFFFFFFFFFFC0ui64);
  v10 = *(_QWORD *)(v9 + 40) << 6;
  v11 = *(_QWORD *)(v9 + 48) << 6;
  v12 = _mm_min_ps(
          *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_min.m_quad + v10),
          *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_min.m_quad + v11));
  *(__m128 *)(v9 + 16) = _mm_max_ps(
                           *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_max.m_quad + v10),
                           *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_max.m_quad + v11));
  *(__m128 *)v9 = v12;
  v13 = (unsigned __int64)v3->m_nodes.m_data + (((char *)v6 - (char *)v3->m_nodes.m_data) & 0xFFFFFFFFFFFFFFC0ui64);
  v14 = *(_QWORD *)(v13 + 40) << 6;
  v15 = *(_QWORD *)(v13 + 48) << 6;
  v16 = _mm_max_ps(
          *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_max.m_quad + v14),
          *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_max.m_quad + v15));
  *(__m128 *)v13 = _mm_min_ps(
                     *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_min.m_quad + v14),
                     *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_min.m_quad + v15));
  *(__m128 *)(v13 + 16) = v16;
  if ( v7 )
  {
    v3->m_nodes.m_data->m_children[(v3->m_nodes.m_data[v7].m_children[1] == node) + 8 * v7] = v6 - v3->m_nodes.m_data;
    result = v6 - v3->m_nodes.m_data;
  }
  else
  {
    result = v6 - v3->m_nodes.m_data;
    v3->m_root = result;
  }
  return result;
}

// File Line: 891
// RVA: 0xDF4B80
signed __int64 __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rotateRight(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this, unsigned __int64 node)
{
  hkcdDynamicTree::CodecRawUlong *v2; // r11
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v3; // r10
  hkcdDynamicTree::CodecRawUlong *v4; // r8
  signed __int64 result; // rax
  hkcdDynamicTree::CodecRawUlong *v6; // r9
  unsigned __int64 v7; // rdi
  hkcdDynamicTree::CodecRawUlong *v8; // rcx
  unsigned __int64 v9; // r8
  __int64 v10; // rax
  __int64 v11; // rcx
  __m128 v12; // xmm1
  unsigned __int64 v13; // r8
  __int64 v14; // rax
  __int64 v15; // rcx
  __m128 v16; // xmm2

  v2 = this->m_nodes.m_data;
  v3 = this;
  v4 = &this->m_nodes.m_data[node];
  if ( !LODWORD(v4->m_children[0]) )
    return 0i64;
  v6 = &v2[v4->m_children[0]];
  if ( !LODWORD(v6->m_children[0]) )
    return 0i64;
  v7 = v4->m_parent;
  v8 = &v2[v6->m_children[1]];
  v8->m_parent = v4 - v2;
  v4->m_children[0] = v8 - v3->m_nodes.m_data;
  v4->m_parent = v6 - v3->m_nodes.m_data;
  v6->m_children[1] = v4 - v3->m_nodes.m_data;
  v6->m_parent = v7;
  v9 = (unsigned __int64)v3->m_nodes.m_data + (((char *)v4 - (char *)v3->m_nodes.m_data) & 0xFFFFFFFFFFFFFFC0ui64);
  v10 = *(_QWORD *)(v9 + 40) << 6;
  v11 = *(_QWORD *)(v9 + 48) << 6;
  v12 = _mm_min_ps(
          *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_min.m_quad + v10),
          *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_min.m_quad + v11));
  *(__m128 *)(v9 + 16) = _mm_max_ps(
                           *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_max.m_quad + v10),
                           *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_max.m_quad + v11));
  *(__m128 *)v9 = v12;
  v13 = (unsigned __int64)v3->m_nodes.m_data + (((char *)v6 - (char *)v3->m_nodes.m_data) & 0xFFFFFFFFFFFFFFC0ui64);
  v14 = *(_QWORD *)(v13 + 40) << 6;
  v15 = *(_QWORD *)(v13 + 48) << 6;
  v16 = _mm_max_ps(
          *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_max.m_quad + v14),
          *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_max.m_quad + v15));
  *(__m128 *)v13 = _mm_min_ps(
                     *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_min.m_quad + v14),
                     *(__m128 *)((char *)&v3->m_nodes.m_data->m_aabb.m_min.m_quad + v15));
  *(__m128 *)(v13 + 16) = v16;
  if ( v7 )
  {
    v3->m_nodes.m_data->m_children[(v3->m_nodes.m_data[v7].m_children[1] == node) + 8 * v7] = v6 - v3->m_nodes.m_data;
    result = v6 - v3->m_nodes.m_data;
  }
  else
  {
    result = v6 - v3->m_nodes.m_data;
    v3->m_root = result;
  }
  return result;
}

// File Line: 920
// RVA: 0xDF22F0
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::balance(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this, int maxDelta, unsigned __int64 node)
{
  unsigned __int64 v3; // rbp
  int v4; // esi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v5; // rdi
  hkcdDynamicTree::CodecRawUlong *v6; // rbx
  hkcdDynamicTree::CodecRawUlong *v7; // rdx
  int v8; // esi
  hkcdDynamicTree::CodecRawUlong *v9; // rdi
  unsigned __int64 v10; // r11
  int v11; // ebx
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // r9
  hkcdDynamicTree::CodecRawUlong *v16; // r10
  unsigned __int64 v17; // rax
  int i; // ecx
  int v19; // ecx
  unsigned __int64 v20; // rcx
  unsigned __int64 j; // r8
  unsigned __int64 v22; // r10
  int v23; // ebx
  int v24; // edi
  unsigned __int64 v25; // r8
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // rcx
  unsigned __int64 v28; // rcx
  hkcdDynamicTree::CodecRawUlong *v29; // r9
  unsigned __int64 v30; // rax
  int k; // er8
  int v32; // er8
  unsigned __int64 v33; // rax
  unsigned __int64 l; // r8
  int m; // ebx
  int v36; // esi
  int v37; // eax
  unsigned __int64 v38; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v39; // [rsp+50h] [rbp+8h]
  int v40; // [rsp+58h] [rbp+10h]
  int v41; // [rsp+60h] [rbp+18h]

  v40 = maxDelta;
  v39 = this;
  v3 = node;
  v4 = maxDelta;
  v5 = this;
  if ( node || (v3 = this->m_root) != 0 )
  {
    v6 = &this->m_nodes.m_data[v3];
    if ( LODWORD(v6->m_children[0]) )
    {
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::balance(this, maxDelta, v6->m_children[0]);
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::balance(v5, v4, v6->m_children[1]);
      v41 = 0;
      if ( v3 )
      {
        do
        {
          v7 = v5->m_nodes.m_data;
          v8 = 0;
          v9 = &v5->m_nodes.m_data[v3];
          v10 = v9->m_children[0];
          if ( v10 )
          {
            v11 = 0;
            v12 = v10 << 6;
            v13 = v7[v10].m_parent;
            if ( v13 )
            {
              v14 = v7[v10].m_parent;
              do
              {
                ++v11;
                v14 = v7[v14].m_parent;
              }
              while ( v14 );
            }
            if ( *(_DWORD *)((char *)v7->m_children + v12) )
            {
              v15 = *(unsigned __int64 *)((char *)v7->m_children + v12);
              while ( v15 )
              {
                v16 = &v7[v15];
                if ( LODWORD(v16->m_children[0]) )
                {
                  v15 = v16->m_children[0];
                }
                else
                {
                  v17 = v16->m_parent;
                  for ( i = 0; v17; v17 = v7[v17].m_parent )
                    ++i;
                  v19 = i - v11;
                  if ( v8 > v19 )
                    v19 = v8;
                  v8 = v19;
                  v20 = v16->m_parent;
                  for ( j = v15; v20 != v10; v20 = v7[v20].m_parent )
                  {
                    if ( v7[v20].m_children[1] != j )
                      break;
                    j = v20;
                  }
                  if ( v20 )
                    v15 = v7[v20].m_children[1];
                  else
                    v15 = j;
                  if ( v20 == v10 && v15 == j )
                    v15 = 0i64;
                }
              }
            }
            else
            {
              for ( ; v13; v13 = v7[v13].m_parent )
                ++v8;
              v8 -= v11;
              if ( v8 < 0 )
                v8 = 0;
            }
          }
          v22 = v9->m_children[1];
          v23 = 0;
          if ( v22 )
          {
            v24 = 0;
            v25 = v22 << 6;
            v26 = v7[v22].m_parent;
            if ( v26 )
            {
              v27 = v7[v22].m_parent;
              do
              {
                ++v24;
                v27 = v7[v27].m_parent;
              }
              while ( v27 );
            }
            if ( *(_DWORD *)((char *)v7->m_children + v25) )
            {
              v28 = *(unsigned __int64 *)((char *)v7->m_children + v25);
              while ( v28 )
              {
                v29 = &v7[v28];
                if ( LODWORD(v29->m_children[0]) )
                {
                  v28 = v29->m_children[0];
                }
                else
                {
                  v30 = v29->m_parent;
                  for ( k = 0; v30; v30 = v7[v30].m_parent )
                    ++k;
                  v32 = k - v24;
                  if ( v23 > v32 )
                    v32 = v23;
                  v23 = v32;
                  v33 = v29->m_parent;
                  for ( l = v28; v33 != v22; v33 = v7[v33].m_parent )
                  {
                    if ( v7[v33].m_children[1] != l )
                      break;
                    l = v33;
                  }
                  if ( v33 )
                    v28 = v7[v33].m_children[1];
                  else
                    v28 = l;
                  if ( v33 == v22 && v28 == l )
                    v28 = 0i64;
                }
              }
            }
            else
            {
              for ( m = 0; v26; v26 = v7[v26].m_parent )
                ++m;
              v23 = m - v24;
              if ( v23 < 0 )
                v23 = 0;
            }
          }
          v36 = v8 - v23;
          v37 = abs(v36);
          if ( v37 <= v41 || v37 <= v40 )
            break;
          v5 = v39;
          v41 = v37;
          v38 = v36 >= 0 ? hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rotateRight(v39, v3) : hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rotateLeft(v39, v3);
          v3 = v38;
        }
        while ( v38 );
      }
    }
  }
}

// File Line: 1138
// RVA: 0xDA19D0
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16>::sortBranch<hkpTreeBroadPhaseInternals::MappingUpdater>(hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16> *this, unsigned int branch, hkpTreeBroadPhaseInternals::MappingUpdater *mapping, int maxDepth)
{
  unsigned __int16 v4; // bx
  int v5; // er14
  hkpTreeBroadPhaseInternals::MappingUpdater *v6; // r12
  unsigned int v7; // er15
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16> *v8; // rdi
  hkcdDynamicTree::Codec32 *i; // rax
  int v10; // ecx
  unsigned __int16 v11; // r10
  unsigned __int16 v12; // r11
  __int16 v13; // cx
  __m128i v14; // xmm2
  signed __int64 v15; // rbp
  hkVector4f v16; // xmm3
  unsigned __int64 v17; // xmm1_8
  unsigned __int64 v18; // rdx
  int v19; // er8
  signed __int64 v20; // r8
  int v21; // esi
  __int64 v22; // xmm0_8
  char v23; // al
  hkVector4f v24; // [rsp+10h] [rbp-58h]
  hkVector4f v25; // [rsp+20h] [rbp-48h]
  unsigned __int16 v26; // [rsp+70h] [rbp+8h]
  __int16 v27; // [rsp+72h] [rbp+Ah]

  v4 = this->m_root;
  v5 = maxDepth;
  v6 = mapping;
  v7 = branch;
  v8 = this;
  if ( v4 )
  {
    for ( i = &this->m_nodes.m_data[v4]; i->m_aabb.m_max.m_quad.m128_i16[6]; i = &v8->m_nodes.m_data[*(&v26 + (v23 & 1))] )
    {
      v10 = v5--;
      if ( !v10 )
        break;
      v11 = i->m_aabb.m_max.m_quad.m128_u16[6];
      v12 = i->m_aabb.m_max.m_quad.m128_u16[7];
      v26 = v11;
      v27 = v12;
      if ( v12 < v11 )
      {
        v13 = v11;
        v11 = v12;
        v26 = v12;
        i->m_aabb.m_max.m_quad.m128_i16[6] = v12;
        v12 = v13;
        v27 = v13;
        i->m_aabb.m_max.m_quad.m128_i16[7] = v13;
      }
      if ( v11 < v4 )
      {
        v14 = (__m128i)i->m_aabb.m_min;
        v15 = (signed __int64)&v8->m_nodes.m_data[v11];
        v16.m_quad = *(__m128 *)(v15 + 16);
        v25.m_quad = *(__m128 *)v15;
        v17 = (unsigned __int128)_mm_srli_si128(*(__m128i *)(v15 + 16), 8);
        v24.m_quad = (__m128)i->m_aabb.m_max;
        v18 = v17 >> 48;
        if ( WORD2(v17) )
        {
          v19 = v4 | 0x3F000000;
          v8->m_nodes.m_data[WORD2(v17)].m_aabb.m_min.m_quad.m128_i32[3] = v19;
          v8->m_nodes.m_data[v18].m_aabb.m_min.m_quad.m128_i32[3] = v19;
        }
        else
        {
          v20 = (signed __int64)&v6->m_handles[v18];
          *(_DWORD *)(v20 + 8) &= 0xFFE00000;
          *(_DWORD *)(v20 + 8) |= v4;
        }
        v21 = v11 | 0x3F000000;
        v25.m_quad.m128_i32[3] = v11 | 0x3F000000;
        v22 = (unsigned __int128)_mm_srli_si128(v14, 8);
        if ( WORD2(v22) )
          v8->m_nodes.m_data->m_aabb.m_max.m_quad.m128_i16[16i64 * WORD2(v22)
                                                         + (v8->m_nodes.m_data[WORD2(v22)].m_aabb.m_max.m_quad.m128_i16[7] == v4)
                                                         + 6] = v11;
        else
          v8->m_root = v11;
        v24.m_quad.m128_i16[6] = v4;
        v11 = v4;
        v8->m_nodes.m_data[v24.m_quad.m128_u16[7]].m_aabb.m_min.m_quad.m128_i32[3] = v21;
        v26 = v4;
        i->m_aabb.m_min = (hkVector4f)v25.m_quad;
        i->m_aabb.m_max = (hkVector4f)v16.m_quad;
        i = (hkcdDynamicTree::Codec32 *)v15;
        *(hkVector4f *)(v15 + 16) = (hkVector4f)v24.m_quad;
        *(__m128i *)v15 = v14;
      }
      if ( v12 < v11 )
      {
        v26 = v12;
        v27 = v11;
        i->m_aabb.m_max.m_quad.m128_i16[6] = v12;
        i->m_aabb.m_max.m_quad.m128_i16[7] = v11;
      }
      v23 = v7;
      v7 >>= 1;
      v4 = *(&v26 + (v23 & 1));
    }
  }
}

