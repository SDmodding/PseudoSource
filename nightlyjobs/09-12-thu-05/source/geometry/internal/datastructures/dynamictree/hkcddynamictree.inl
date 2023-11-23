// File Line: 280
// RVA: 0xDF28D0
hkSimdFloat32 *__fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::computeCost(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this,
        hkSimdFloat32 *result)
{
  unsigned __int64 m_root; // rsi
  float v4; // xmm7_4
  hkcdDynamicTree::CodecRawUlong *m_data; // rdx
  unsigned __int64 v6; // rbp
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm6
  __int64 v10; // r11
  __int64 v11; // rbx
  int v12; // edi
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm9
  unsigned __int64 v19; // r9
  unsigned __int64 v20; // r10
  int v21; // ecx
  unsigned __int64 m_parent; // rcx
  unsigned __int64 i; // r8
  int v24; // r11d
  __m128 v25; // xmm5
  unsigned __int64 v26; // r9
  unsigned __int64 v27; // r10
  int v28; // ecx
  unsigned __int64 v29; // rcx
  unsigned __int64 j; // r8
  __m128 v31; // xmm2
  unsigned __int64 v32; // rcx
  unsigned __int64 v33; // r8

  m_root = this->m_root;
  *result = 0i64;
  LODWORD(v4) = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0eN7), (__m128)LODWORD(FLOAT_1_0eN7), 0).m128_u32[0];
  if ( m_root )
  {
    m_data = this->m_nodes.m_data;
    do
    {
      v6 = m_root << 6;
      if ( !LODWORD(m_data[m_root].m_children[0]) )
        goto LABEL_42;
      v7 = _mm_sub_ps(m_data[m_root].m_aabb.m_max.m_quad, m_data[m_root].m_aabb.m_min.m_quad);
      v8 = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v7);
      v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
      if ( v9.m128_f32[0] > v4 )
      {
        v10 = *(unsigned __int64 *)((char *)m_data->m_children + v6);
        v11 = *(unsigned __int64 *)((char *)&m_data->m_children[1] + v6);
        v12 = 0;
        v13 = _mm_sub_ps(m_data[v10].m_aabb.m_max.m_quad, m_data[v10].m_aabb.m_min.m_quad);
        v14 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v13);
        v15 = _mm_sub_ps(m_data[v11].m_aabb.m_max.m_quad, m_data[v11].m_aabb.m_min.m_quad);
        v16 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170));
        v17 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v15);
        v18 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170));
        if ( v10 )
        {
          if ( LODWORD(m_data[v10].m_children[0]) )
          {
            v19 = m_data[v10].m_children[0];
            while ( v19 )
            {
              v20 = v19 << 6;
              v21 = m_data[v19].m_children[0];
              v12 += v21 == 0;
              if ( v21 )
              {
                v19 = *(unsigned __int64 *)((char *)m_data->m_children + v20);
              }
              else
              {
                m_parent = *(unsigned __int64 *)((char *)&m_data->m_parent + v20);
                for ( i = v19; m_parent != v10; m_parent = m_data[m_parent].m_parent )
                {
                  if ( m_data[m_parent].m_children[1] != i )
                    break;
                  i = m_parent;
                }
                if ( m_parent )
                  v19 = m_data[m_parent].m_children[1];
                else
                  v19 = i;
                if ( m_parent == v10 && v19 == i )
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
          if ( LODWORD(m_data[v11].m_children[0]) )
          {
            v26 = m_data[v11].m_children[0];
            while ( v26 )
            {
              v27 = v26 << 6;
              v28 = m_data[v26].m_children[0];
              v24 += v28 == 0;
              if ( v28 )
              {
                v26 = *(unsigned __int64 *)((char *)m_data->m_children + v27);
              }
              else
              {
                v29 = *(unsigned __int64 *)((char *)&m_data->m_parent + v27);
                for ( j = v26; v29 != v11; v29 = m_data[v29].m_parent )
                {
                  if ( m_data[v29].m_children[1] != j )
                    break;
                  j = v29;
                }
                if ( v29 )
                  v26 = m_data[v29].m_children[1];
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
        result->m_real = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v9)), v31), v16),
                               v25),
                             result->m_real),
                           _mm_mul_ps(
                             _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v9)), v31), v18),
                             _mm_shuffle_ps(
                               (__m128)COERCE_UNSIGNED_INT((float)v24),
                               (__m128)COERCE_UNSIGNED_INT((float)v24),
                               0)));
      }
      if ( *(_DWORD *)((char *)m_data->m_children + v6) )
      {
        m_root = *(unsigned __int64 *)((char *)m_data->m_children + v6);
      }
      else
      {
LABEL_42:
        v32 = *(unsigned __int64 *)((char *)&m_data->m_parent + v6);
        v33 = m_root;
        if ( v32 )
        {
          while ( m_data[v32].m_children[1] == v33 )
          {
            v33 = v32;
            v32 = m_data[v32].m_parent;
            if ( !v32 )
              goto LABEL_45;
          }
          m_root = m_data[v32].m_children[1];
        }
        else
        {
LABEL_45:
          m_root = v33;
        }
        if ( !v32 && m_root == v33 )
          m_root = 0i64;
      }
    }
    while ( m_root );
  }
  return result;
}

// File Line: 305
// RVA: 0xDA4BA0
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16>::optimizeIncremental(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16> *this,
        int passes,
        int lookahead)
{
  unsigned __int16 m_root; // ax
  int v5; // r12d
  unsigned int m_path; // ecx
  __int64 v8; // r8
  hkcdDynamicTree::Codec32 *m_data; // rdx
  hkcdDynamicTree::Codec32 *v10; // rdi
  char v11; // al
  __int64 v12; // rdi
  unsigned __int64 v13; // r14
  hkcdDynamicTree::Codec32 *v14; // rbx
  __m128 m_quad; // xmm5
  __m128 v16; // xmm4
  hkcdDynamicTree::Codec32 *v17; // rbp
  unsigned __int16 v18; // ax
  hkcdDynamicTree::Codec32 *v19; // r11
  unsigned __int16 v20; // r8
  hkcdDynamicTree::Codec32 *v21; // rdx
  hkcdDynamicTree::Codec32 *v22; // rbx
  unsigned __int16 v23; // r8
  __int64 v24; // rbx
  __m128 *p_m_quad; // rcx
  __int64 v26; // rax
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __int64 v29; // rax
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  int i; // ecx
  hkcdDynamicTree::Codec32 *v33; // rcx
  hkVector4f v34; // xmm9
  __m128 v35; // xmm8
  hkcdDynamicTree::Codec32 *v36; // r9
  hkcdDynamicTree::Codec32 *v37; // r10
  unsigned __int16 v38; // cx
  __m128 v39; // xmm10
  __m128 v40; // xmm11
  hkcdDynamicTree::Codec32 *v41; // rcx
  hkcdDynamicTree::Codec32 *v42; // rdx
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
  __int64 v55; // r11
  __int64 v56; // rax
  int v57; // ecx
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __int64 v60[2]; // [rsp+20h] [rbp-98h]
  hkResult result; // [rsp+C8h] [rbp+10h] BYREF

  if ( passes > 0 )
  {
    m_root = this->m_root;
    v5 = passes;
    if ( m_root )
    {
      if ( this->m_nodes.m_data[m_root].m_aabb.m_max.m_quad.m128_i16[6] )
      {
        do
        {
          m_path = this->m_path;
          v8 = this->m_root;
          m_data = this->m_nodes.m_data;
          this->m_path = m_path + 1;
          v10 = &m_data[v8];
          do
          {
            v11 = m_path;
            m_path = __ROR4__(m_path, 1);
            v10 = &m_data[v10->m_aabb.m_max.m_quad.m128_u16[(v11 & 1) + 6]];
          }
          while ( v10->m_aabb.m_max.m_quad.m128_i16[6] );
          v12 = v10 - m_data;
          v13 = (unsigned __int16)v12;
          v14 = &m_data[v13];
          m_quad = m_data[v13].m_aabb.m_min.m_quad;
          v16 = _mm_shuffle_ps(
                  m_data[v13].m_aabb.m_max.m_quad,
                  _mm_unpackhi_ps(m_data[v13].m_aabb.m_max.m_quad, (__m128)0i64),
                  196);
          if ( (_WORD)v12 == (_WORD)v8 )
          {
            this->m_root = 0;
          }
          else
          {
            v17 = &m_data[v14->m_aabb.m_min.m_quad.m128_u16[6]];
            v18 = v17->m_aabb.m_min.m_quad.m128_u16[6];
            v19 = &m_data[v17->m_aabb.m_min.m_quad.m128_u16[15i64
                                                          - (v17->m_aabb.m_max.m_quad.m128_i16[7] == (unsigned __int16)v12)]];
            if ( v18 )
            {
              v19->m_aabb.m_min.m_quad.m128_i32[3] = v18 | 0x3F000000;
              this->m_nodes.m_data[v17->m_aabb.m_min.m_quad.m128_u16[6]].m_aabb.m_max.m_quad.m128_i16[(this->m_nodes.m_data[v17->m_aabb.m_min.m_quad.m128_u16[6]].m_aabb.m_max.m_quad.m128_i16[7] == v14->m_aabb.m_min.m_quad.m128_i16[6]) + 6] = v19 - this->m_nodes.m_data;
              v20 = v14->m_aabb.m_min.m_quad.m128_u16[6];
              this->m_nodes.m_data[v20].m_aabb.m_min.m_quad.m128_i16[0] = this->m_firstFree;
              v21 = this->m_nodes.m_data;
              this->m_firstFree = v20;
              v22 = &v21[v19->m_aabb.m_min.m_quad.m128_u16[6]];
              while ( 1 )
              {
                v23 = v22->m_aabb.m_min.m_quad.m128_u16[6];
                v24 = v22 - v21;
                p_m_quad = &v21[(unsigned __int16)v24].m_aabb.m_min.m_quad;
                v26 = p_m_quad[1].m128_u16[6];
                v27 = v21[v26].m_aabb.m_max.m_quad;
                v28 = v21[v26].m_aabb.m_min.m_quad;
                v29 = p_m_quad[1].m128_u16[7];
                v30 = _mm_min_ps(v28, v21[v29].m_aabb.m_min.m_quad);
                v31 = _mm_max_ps(
                        _mm_shuffle_ps(v27, _mm_unpackhi_ps(v27, (__m128)0i64), 196),
                        _mm_shuffle_ps(
                          v21[v29].m_aabb.m_max.m_quad,
                          _mm_unpackhi_ps(v21[v29].m_aabb.m_max.m_quad, (__m128)0i64),
                          196));
                *p_m_quad = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, *p_m_quad), 196);
                p_m_quad[1] = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, p_m_quad[1]), 196);
                if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v16, v31), _mm_cmple_ps(v30, m_quad))) & 7) == 7 )
                  goto LABEL_16;
                if ( v23 )
                {
                  v21 = this->m_nodes.m_data;
                  v22 = &this->m_nodes.m_data[v23];
                  if ( v22 )
                    continue;
                }
                goto LABEL_15;
              }
            }
            m_data[v8].m_aabb.m_min.m_quad.m128_i16[0] = this->m_firstFree;
            this->m_firstFree = v8;
            this->m_root = (__int64)(unsigned int)((_DWORD)v19 - LODWORD(this->m_nodes.m_data)) >> 5;
            v19->m_aabb.m_min.m_quad.m128_i32[3] = 1056964608;
          }
LABEL_15:
          LOWORD(v24) = this->m_root;
LABEL_16:
          if ( (_WORD)v24 )
          {
            if ( lookahead < 0 )
            {
              LOWORD(v24) = this->m_root;
            }
            else
            {
              for ( i = lookahead;
                    i;
                    LOWORD(v24) = this->m_nodes.m_data[(unsigned __int16)v24].m_aabb.m_min.m_quad.m128_i16[6] )
              {
                --i;
                if ( !this->m_nodes.m_data[(unsigned __int16)v24].m_aabb.m_min.m_quad.m128_i16[6] )
                  break;
              }
            }
          }
          v33 = this->m_nodes.m_data;
          v34.m_quad = (__m128)this->m_nodes.m_data[(unsigned __int16)v12].m_aabb.m_min;
          v35 = _mm_shuffle_ps(
                  this->m_nodes.m_data[v13].m_aabb.m_max.m_quad,
                  _mm_unpackhi_ps(this->m_nodes.m_data[v13].m_aabb.m_max.m_quad, (__m128)0i64),
                  196);
          if ( (_WORD)v24 )
          {
            if ( !this->m_firstFree )
              hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
                this,
                &result,
                1);
            v36 = &this->m_nodes.m_data[(unsigned __int16)v24];
            v37 = &this->m_nodes.m_data[this->m_firstFree];
            this->m_firstFree = v37->m_aabb.m_min.m_quad.m128_i16[0];
            v38 = v36->m_aabb.m_max.m_quad.m128_u16[6];
            if ( v38 )
            {
              v39 = _mm_add_ps(v34.m_quad, v35);
              v40 = _mm_sub_ps(v35, v34.m_quad);
              do
              {
                v41 = &this->m_nodes.m_data[v38];
                v42 = &this->m_nodes.m_data[v36->m_aabb.m_max.m_quad.m128_u16[7]];
                v43 = _mm_min_ps(v34.m_quad, v36->m_aabb.m_min.m_quad);
                v44 = _mm_max_ps(
                        v35,
                        _mm_shuffle_ps(
                          v36->m_aabb.m_max.m_quad,
                          _mm_unpackhi_ps(v36->m_aabb.m_max.m_quad, (__m128)0i64),
                          196));
                v60[0] = (__int64)v41;
                v60[1] = (__int64)v42;
                v36->m_aabb.m_min.m_quad = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, v36->m_aabb.m_min.m_quad), 196);
                v36->m_aabb.m_max.m_quad = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, v36->m_aabb.m_max.m_quad), 196);
                v45 = _mm_shuffle_ps(
                        v41->m_aabb.m_max.m_quad,
                        _mm_unpackhi_ps(v41->m_aabb.m_max.m_quad, (__m128)0i64),
                        196);
                v46 = _mm_shuffle_ps(
                        v42->m_aabb.m_max.m_quad,
                        _mm_unpackhi_ps(v42->m_aabb.m_max.m_quad, (__m128)0i64),
                        196);
                v47 = _mm_sub_ps(_mm_add_ps(v41->m_aabb.m_min.m_quad, v45), v39);
                v48 = _mm_add_ps(v42->m_aabb.m_min.m_quad, v46);
                v49 = _mm_mul_ps(v47, v47);
                v50 = _mm_add_ps(_mm_sub_ps(v45, v41->m_aabb.m_min.m_quad), v40);
                v51 = _mm_add_ps(_mm_sub_ps(v46, v42->m_aabb.m_min.m_quad), v40);
                v52 = _mm_sub_ps(v48, v39);
                v53 = _mm_mul_ps(v52, v52);
                v36 = (hkcdDynamicTree::Codec32 *)v60[(float)((float)((float)(_mm_shuffle_ps(v50, v50, 85).m128_f32[0]
                                                                            + _mm_shuffle_ps(v50, v50, 0).m128_f32[0])
                                                                    + _mm_shuffle_ps(v50, v50, 170).m128_f32[0])
                                                            * (float)((float)(_mm_shuffle_ps(v49, v49, 85).m128_f32[0]
                                                                            + _mm_shuffle_ps(v49, v49, 0).m128_f32[0])
                                                                    + _mm_shuffle_ps(v49, v49, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v51, v51, 85).m128_f32[0] + _mm_shuffle_ps(v51, v51, 0).m128_f32[0]) + _mm_shuffle_ps(v51, v51, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v53, v53, 85).m128_f32[0] + _mm_shuffle_ps(v53, v53, 0).m128_f32[0]) + _mm_shuffle_ps(v53, v53, 170).m128_f32[0]))];
                v38 = v36->m_aabb.m_max.m_quad.m128_u16[6];
              }
              while ( v38 );
            }
            v54 = v36->m_aabb.m_min.m_quad.m128_u16[6];
            v55 = v37 - this->m_nodes.m_data;
            if ( v54 )
              this->m_nodes.m_data[v54].m_aabb.m_max.m_quad.m128_i16[(this->m_nodes.m_data[v54].m_aabb.m_max.m_quad.m128_i16[7] == (unsigned __int16)(v36 - this->m_nodes.m_data))
                                                                   + 6] = v55;
            else
              this->m_root = v55;
            v37->m_aabb.m_min.m_quad.m128_i32[3] = v36->m_aabb.m_min.m_quad.m128_u16[6] | 0x3F000000;
            v56 = (unsigned int)((_DWORD)v36 - LODWORD(this->m_nodes.m_data));
            v37->m_aabb.m_max.m_quad.m128_i16[7] = v12;
            v57 = (unsigned __int16)v55 | 0x3F000000;
            v37->m_aabb.m_max.m_quad.m128_i16[6] = v56 >> 5;
            v36->m_aabb.m_min.m_quad.m128_i32[3] = v57;
            this->m_nodes.m_data[v13].m_aabb.m_min.m_quad.m128_i32[3] = v57;
            v58 = _mm_min_ps(v36->m_aabb.m_min.m_quad, v34.m_quad);
            v59 = _mm_max_ps(
                    _mm_shuffle_ps(
                      v36->m_aabb.m_max.m_quad,
                      _mm_unpackhi_ps(v36->m_aabb.m_max.m_quad, (__m128)0i64),
                      196),
                    v35);
            v37->m_aabb.m_min.m_quad = _mm_shuffle_ps(v58, _mm_unpackhi_ps(v58, v37->m_aabb.m_min.m_quad), 196);
            v37->m_aabb.m_max.m_quad = _mm_shuffle_ps(v59, _mm_unpackhi_ps(v59, v37->m_aabb.m_max.m_quad), 196);
          }
          else
          {
            this->m_root = v12;
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
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this,
        unsigned __int64 branch,
        hkBool minimize,
        int numBins,
        int bottomUpThreshold)
{
  char *v5; // rsi
  unsigned __int64 v6; // rdi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v7; // r15
  unsigned __int64 v8; // r14
  _QWORD **Value; // rax
  __int64 v10; // rax
  char *v11; // rbx
  int m_size; // ecx
  hkcdDynamicTree::CodecRawUlong *m_data; // rcx
  __int64 v14; // rax
  __m128 v15; // xmm10
  __m128 v16; // xmm11
  int v17; // edx
  hkcdDynamicTree::CodecRawUlong *v18; // rbx
  unsigned __int64 v19; // rdi
  __int64 v20; // rbx
  char *v21; // rbx
  int v22; // edx
  char *v23; // r8
  __m128 v24; // xmm13
  __m128 v25; // xmm14
  char *v26; // r13
  __int64 v27; // r14
  __int64 v28; // rdi
  int *v29; // rbx
  int v30; // r8d
  int v31; // eax
  char *v32; // rcx
  __int64 v33; // rdx
  int v34; // r9d
  __int64 v35; // rdi
  int *v36; // rbx
  int v37; // r8d
  __int64 v38; // rcx
  char *v39; // rdx
  int v40; // r9d
  __int64 v41; // rdi
  int *v42; // rbx
  int v43; // r8d
  __int64 v44; // rcx
  char *v45; // rdx
  int v46; // edx
  char *v47; // r12
  __int64 v48; // rax
  float v49; // xmm5_4
  int v50; // r10d
  int v51; // r9d
  int v52; // ebx
  __int128 v53; // xmm7
  __int64 v54; // r13
  __m128 v55; // xmm6
  hkcdDynamicTree::CodecRawUlong *v56; // rsi
  unsigned __int64 *v57; // rdi
  __int64 v58; // rdx
  __int64 v59; // r11
  int v60; // ecx
  unsigned __int64 v61; // rax
  __m128 v62; // xmm8
  __m128 v63; // xmm9
  _QWORD *v64; // rdx
  __int64 v65; // r8
  __int64 v66; // rax
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  float v71; // xmm2_4
  __int64 v72; // r14
  unsigned __int64 v73; // rdi
  unsigned __int64 v74; // rsi
  unsigned __int64 v75; // r8
  hkcdDynamicTree::CodecRawUlong *v76; // rdx
  unsigned __int64 v77; // rcx
  __int64 v78; // rax
  unsigned __int64 v79; // r8
  __m128 v80; // xmm7
  __int64 v81; // rdx
  __m128 v82; // xmm6
  hkcdDynamicTree::CodecRawUlong *v83; // r8
  unsigned __int64 *v84; // rcx
  __int64 v85; // rax
  __m128 v86; // xmm9
  __m128 v87; // xmm1
  __m128 v88; // xmm8
  __int64 m_firstFree; // rbx
  hkcdDynamicTree::CodecRawUlong *v90; // rcx
  __int64 v91; // rdx
  __int64 v92; // rax
  _QWORD **v93; // rax
  hkArrayBase<char *> *v94; // rsi
  _QWORD **v95; // rax
  hkArrayBase<char *> *v96; // rdi
  int m_capacityAndFlags; // eax
  int v98; // r9d
  int v99; // eax
  int v100; // eax
  int v101; // r9d
  int v102; // eax
  int v103; // eax
  __int64 v104; // rcx
  char *v105; // rdx
  char *v106; // rax
  char *v107; // rax
  char *v108; // rax
  bool v109; // cc
  __m128 v110; // xmm6
  int v111; // r14d
  __int64 v112; // rdi
  hkcdDynamicTree::CodecRawUlong *v113; // rcx
  __m128 m_quad; // xmm4
  __m128 v115; // xmm3
  __m128 v116; // xmm1
  __m128i v117; // xmm2
  char *v118; // rax
  __int64 v119; // rcx
  __m128 v120; // xmm1
  char *v121; // rax
  __int64 v122; // rsi
  __m128 v123; // xmm1
  char *v124; // rax
  __int64 v125; // r13
  __m128 v126; // xmm1
  const void **v127; // rbx
  char *v128; // rbx
  unsigned __int64 *v129; // rsi
  char *v130; // rbx
  char **v131; // rax
  int v132; // r14d
  __int64 v133; // rbx
  int v134; // edi
  float v135; // xmm3_4
  int v136; // r9d
  __int64 v137; // r8
  int v138; // edx
  int v139; // r13d
  char *v140; // rcx
  __m128 v141; // xmm4
  __m128 v142; // xmm5
  __m128 v143; // xmm6
  __m128 v144; // xmm7
  __int64 v145; // rsi
  __int64 v146; // r11
  int v147; // r13d
  __m128 *v148; // rcx
  __m128 *v149; // r10
  int v150; // eax
  __int64 v151; // r11
  __m128 v152; // xmm0
  __m128 v153; // xmm2
  __m128 v154; // xmm0
  __m128 v155; // xmm2
  int v156; // r10d
  __int64 v157; // rcx
  float *v158; // rax
  __int64 v159; // rsi
  __int64 v160; // rbx
  __int64 v161; // r13
  hkArrayBase<char *> *v162; // r12
  __int64 v163; // r15
  int v164; // eax
  hkArrayBase<char *> *v165; // r15
  __int64 v166; // rdi
  char *v167; // rsi
  int v168; // ecx
  int v169; // edx
  char *v170; // rax
  __int64 v171; // r13
  int v172; // edi
  unsigned __int64 *v173; // rsi
  hkArrayBase<char *> *v174; // rcx
  char *const *v175; // r8
  int v176; // r9d
  char *v177; // r8
  __int64 v178; // r13
  int v179; // r8d
  _QWORD **v180; // rax
  __int64 v181; // rdi
  char *v182; // rax
  hkcdDynamicTree::CodecRawUlong *v183; // r9
  char m_enum; // r8
  unsigned __int64 v185; // rbx
  unsigned __int64 v186; // rsi
  __m128 *p_m_quad; // rdi
  __m128 *v188; // r11
  __m128 v189; // xmm0
  __m128 v190; // xmm2
  __m128 v191; // xmm1
  __m128 v192; // xmm3
  float v193; // xmm12_4
  __m128 *v194; // r8
  unsigned __int64 *v195; // r10
  __int64 v196; // r14
  unsigned __int64 v197; // rcx
  unsigned __int64 v198; // rdx
  __m128 *v199; // rcx
  __m128 *v200; // rdx
  __m128 v201; // xmm1
  __m128 v202; // xmm0
  __m128 v203; // xmm1
  __m128 v204; // xmm3
  __m128 v205; // xmm7
  __m128 v206; // xmm11
  __m128 v207; // xmm9
  __m128 v208; // xmm1
  __m128 v209; // xmm2
  __m128 v210; // xmm3
  __m128 v211; // xmm4
  __m128 v212; // xmm1
  BOOL v213; // r10d
  _BOOL8 v214; // rcx
  __int64 v215; // rcx
  __int64 v216; // rdx
  __m128 v217; // xmm1
  int v218; // eax
  __m128 v219; // xmm0
  __m128 v220; // xmm1
  unsigned __int64 m_parent; // rcx
  unsigned __int64 i; // rdx
  hkcdDynamicTree::CodecRawUlong *v223; // rdx
  unsigned __int64 v224; // r10
  unsigned __int64 v225; // r9
  unsigned __int64 v226; // r8
  __m128 v227; // xmm0
  __m128 v228; // xmm3
  __m128 v229; // xmm1
  __m128 v230; // xmm2
  unsigned __int64 v231; // rcx
  unsigned __int64 j; // r8
  __int64 v233; // r8
  __int64 v234; // rdx
  hkcdDynamicTree::CodecRawUlong *v235; // rdx
  __int64 v236; // r8
  unsigned __int64 v237; // rax
  unsigned __int64 v238; // rcx
  __m128 v239; // xmm2
  int *v240; // rsi
  int v241; // eax
  __int64 v242; // rcx
  int v243; // eax
  __int64 v244; // rdi
  int *v245; // rbx
  int v246; // r8d
  int v247; // r8d
  bool v248; // sf
  __int64 v249; // [rsp+30h] [rbp-B0h]
  unsigned __int64 *v250; // [rsp+30h] [rbp-B0h]
  unsigned __int64 *v251; // [rsp+30h] [rbp-B0h]
  char *v252; // [rsp+30h] [rbp-B0h]
  hkArrayBase<char *> array; // [rsp+38h] [rbp-A8h] BYREF
  __int64 v254; // [rsp+48h] [rbp-98h]
  char *v255; // [rsp+50h] [rbp-90h] BYREF
  int v256; // [rsp+58h] [rbp-88h]
  int v257; // [rsp+5Ch] [rbp-84h]
  char *v258; // [rsp+60h] [rbp-80h] BYREF
  hkArrayBase<char *> *v259; // [rsp+68h] [rbp-78h] BYREF
  char *v260; // [rsp+70h] [rbp-70h] BYREF
  unsigned __int64 v261; // [rsp+78h] [rbp-68h]
  hkArrayBase<char *> *v262; // [rsp+80h] [rbp-60h]
  int v263; // [rsp+88h] [rbp-58h]
  char *v264; // [rsp+90h] [rbp-50h]
  hkResult v265; // [rsp+98h] [rbp-48h] BYREF
  int v266; // [rsp+9Ch] [rbp-44h]
  __int64 v267; // [rsp+A0h] [rbp-40h]
  char *a[3]; // [rsp+A8h] [rbp-38h] BYREF
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::SAHBin::Sorter v269; // [rsp+C0h] [rbp-20h] BYREF
  __m128 v270; // [rsp+E0h] [rbp+0h]
  __int64 v271; // [rsp+F0h] [rbp+10h]
  hkResult v272; // [rsp+F8h] [rbp+18h] BYREF
  hkResult v273; // [rsp+FCh] [rbp+1Ch] BYREF
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::SAHBin::Sorter v274; // [rsp+100h] [rbp+20h]
  __m128 v275; // [rsp+110h] [rbp+30h]
  __m128 v276; // [rsp+120h] [rbp+40h]
  __m128 v277; // [rsp+130h] [rbp+50h]
  __m128 v278; // [rsp+140h] [rbp+60h]
  __m128 v279; // [rsp+150h] [rbp+70h]
  __m128 v280; // [rsp+160h] [rbp+80h]
  __m128 v281; // [rsp+170h] [rbp+90h]
  __m128 v282; // [rsp+180h] [rbp+A0h]
  __m128 v283; // [rsp+190h] [rbp+B0h]
  __m128 v284; // [rsp+1A0h] [rbp+C0h]
  __m128 v285; // [rsp+1B0h] [rbp+D0h]
  __m128 v286; // [rsp+1C0h] [rbp+E0h]
  __m128 v287; // [rsp+1D0h] [rbp+F0h]
  __m128 v288; // [rsp+1E0h] [rbp+100h]
  __m128 v289; // [rsp+1F0h] [rbp+110h]
  __m128 v290; // [rsp+200h] [rbp+120h] BYREF
  __m128 v291; // [rsp+210h] [rbp+130h]
  __m128 v292; // [rsp+220h] [rbp+140h]
  char *v293; // [rsp+230h] [rbp+150h] BYREF
  int v294; // [rsp+238h] [rbp+158h]
  int v295; // [rsp+23Ch] [rbp+15Ch]
  char v296; // [rsp+240h] [rbp+160h] BYREF
  __m128 v297; // [rsp+440h] [rbp+360h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v298; // [rsp+540h] [rbp+460h]
  hkResult result; // [rsp+548h] [rbp+468h] BYREF
  char vars0; // [rsp+550h] [rbp+470h]
  int v301; // [rsp+560h] [rbp+480h]

  if ( branch )
  {
    v301 = (int)this;
    v5 = (char *)numBins;
    v6 = branch;
    v7 = this;
    if ( this->m_numLeaves > 2 )
    {
      v8 = branch << 6;
      if ( LODWORD(this->m_nodes.m_data[branch].m_children[0]) )
      {
        array.m_capacityAndFlags = 0x80000000;
        array.m_data = 0i64;
        array.m_size = 0;
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v10 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
        v11 = (char *)v10;
        if ( v10 )
        {
          *(_QWORD *)v10 = 0i64;
          *(_DWORD *)(v10 + 8) = 0;
          *(_DWORD *)(v10 + 12) = 0x80000000;
          *(_QWORD *)(v10 + 16) = 0i64;
          *(_DWORD *)(v10 + 24) = -1;
        }
        else
        {
          v11 = 0i64;
        }
        m_size = array.m_size;
        if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 8);
          m_size = array.m_size;
        }
        array.m_data[m_size] = v11;
        ++array.m_size;
        m_data = v7->m_nodes.m_data;
        v14 = *(unsigned __int64 *)((char *)&v7->m_nodes.m_data->m_parent + v8);
        v271 = v14;
        v15 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        v16 = _mm_xor_ps((__m128)xmmword_141A712A0, v15);
        if ( v14 )
          LODWORD(v258) = m_data[v14].m_children[1] == v6;
        else
          LODWORD(v258) = 0;
        v254 = 0i64;
        v17 = 0;
        v293 = &v296;
        v295 = -2147483584;
        while ( 1 )
        {
          v294 = v17;
          while ( 1 )
          {
            v18 = &v7->m_nodes.m_data[v6];
            if ( !LODWORD(v18->m_children[0]) )
              break;
            v19 = v18->m_children[1];
            if ( v17 == (v295 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v293, 8);
              v17 = v294;
            }
            *(_QWORD *)&v293[8 * v17] = v19;
            ++v294;
            v6 = v18->m_children[0];
            v20 = v18 - v7->m_nodes.m_data;
            v7->m_nodes.m_data[(__int64)(int)v20].m_aabb.m_min.m_quad.m128_u64[0] = v7->m_firstFree;
            v17 = v294;
            v7->m_firstFree = v20;
          }
          v21 = *array.m_data;
          if ( *((_DWORD *)*array.m_data + 2) == (*((_DWORD *)*array.m_data + 3) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, *(const void ***)array.m_data, 8);
          *(_QWORD *)(*(_QWORD *)v21 + 8i64 * (int)(*((_DWORD *)v21 + 2))++) = v6;
          if ( !v294 )
            break;
          v6 = *(_QWORD *)&v293[8 * v294 - 8];
          v17 = v294 - 1;
        }
        v294 = 0;
        if ( v295 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v293, 8 * v295);
        v22 = 0;
        v23 = 0i64;
        v255 = 0i64;
        v257 = 0x80000000;
        v256 = 0;
        v258 = 0i64;
        v259 = (hkArrayBase<char *> *)0x8000000000000000i64;
        v24 = _mm_shuffle_ps(
                (__m128)COERCE_UNSIGNED_INT((float)(int)v5),
                (__m128)COERCE_UNSIGNED_INT((float)(int)v5),
                0);
        v260 = 0i64;
        v261 = 0x8000000000000000ui64;
        v25 = _mm_shuffle_ps(
                (__m128)COERCE_UNSIGNED_INT((float)((int)v5 - 1)),
                (__m128)COERCE_UNSIGNED_INT((float)((int)v5 - 1)),
                0);
        if ( (int)v5 > 0 )
        {
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v255, (int)v5, 64);
          v22 = v256;
          v23 = v255;
        }
        v26 = v5;
        v27 = (_QWORD)v5 << 6;
        v260 = v5;
        v28 = v22 - (int)v5 - 1;
        if ( v22 - (int)v5 - 1 >= 0 )
        {
          v29 = (int *)&v23[64 * v28 + 12 + v27];
          do
          {
            v30 = *v29;
            *(v29 - 1) = 0;
            if ( v30 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v29 - 3),
                8 * v30);
            *(_QWORD *)(v29 - 3) = 0i64;
            *v29 = 0x80000000;
            v29 -= 16;
            --v28;
          }
          while ( v28 >= 0 );
          v22 = v256;
          v23 = v255;
        }
        v31 = (_DWORD)v5 - v22;
        v32 = &v23[64 * (__int64)v22];
        v33 = (int)v5 - v22;
        if ( v31 > 0 )
        {
          do
          {
            if ( v32 )
            {
              *(_QWORD *)v32 = 0i64;
              *((_DWORD *)v32 + 2) = 0;
              *((_DWORD *)v32 + 3) = 0x80000000;
            }
            v32 += 64;
            --v33;
          }
          while ( v33 );
        }
        v256 = (int)v5;
        if ( (HIDWORD(v259) & 0x3FFFFFFF) < (int)v5 )
        {
          v34 = (int)v5;
          if ( (int)v5 < 2 * (HIDWORD(v259) & 0x3FFFFFFF) )
            v34 = 2 * (HIDWORD(v259) & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v258, v34, 64);
        }
        v35 = (int)v259 - (int)v5 - 1;
        if ( (int)v259 - (int)v5 - 1 >= 0 )
        {
          v36 = (int *)&v258[64 * v35 + 12 + v27];
          do
          {
            v37 = *v36;
            *(v36 - 1) = 0;
            if ( v37 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v36 - 3),
                8 * v37);
            *(_QWORD *)(v36 - 3) = 0i64;
            *v36 = 0x80000000;
            v36 -= 16;
            --v35;
          }
          while ( v35 >= 0 );
        }
        v38 = (int)v5 - (int)v259;
        v39 = &v258[64 * (__int64)(int)v259];
        if ( (int)v5 - (int)v259 > 0 )
        {
          do
          {
            if ( v39 )
            {
              *(_QWORD *)v39 = 0i64;
              *((_DWORD *)v39 + 2) = 0;
              *((_DWORD *)v39 + 3) = 0x80000000;
            }
            v39 += 64;
            --v38;
          }
          while ( v38 );
        }
        LODWORD(v259) = (_DWORD)v5;
        if ( (HIDWORD(v261) & 0x3FFFFFFF) < (int)v5 )
        {
          v40 = (int)v5;
          if ( (int)v5 < 2 * (HIDWORD(v261) & 0x3FFFFFFF) )
            v40 = 2 * (HIDWORD(v261) & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v260, v40, 64);
        }
        v41 = (int)v261 - (int)v5 - 1;
        if ( (int)v261 - (int)v5 - 1 >= 0 )
        {
          v42 = (int *)&v260[64 * v41 + 12 + v27];
          do
          {
            v43 = *v42;
            *(v42 - 1) = 0;
            if ( v43 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v42 - 3),
                8 * v43);
            *(_QWORD *)(v42 - 3) = 0i64;
            *v42 = 0x80000000;
            v42 -= 16;
            --v41;
          }
          while ( v41 >= 0 );
        }
        v44 = (int)v5 - (int)v261;
        v45 = &v260[64 * (__int64)(int)v261];
        if ( (int)v5 - (int)v261 > 0 )
        {
          do
          {
            if ( v45 )
            {
              *(_QWORD *)v45 = 0i64;
              *((_DWORD *)v45 + 2) = 0;
              *((_DWORD *)v45 + 3) = 0x80000000;
            }
            v45 += 64;
            --v44;
          }
          while ( v44 );
        }
        v46 = array.m_size;
        v267 = 2i64;
        LODWORD(v261) = (_DWORD)v5;
        do
        {
          v47 = array.m_data[v46 - 1];
          array.m_size = v46 - 1;
          v48 = *((int *)v47 + 2);
          v264 = v47;
          if ( (int)v48 > v301 || *((_DWORD *)v47 + 6) == -1 )
          {
            v80 = (__m128)xmmword_141A712A0;
            v81 = v48;
            v82 = _mm_xor_ps(v15, (__m128)xmmword_141A712A0);
            if ( (int)v48 > 0 )
            {
              v83 = v7->m_nodes.m_data;
              v84 = *(unsigned __int64 **)v47;
              do
              {
                v85 = *v84++;
                v85 <<= 6;
                v80 = _mm_min_ps(v80, *(__m128 *)((char *)&v83->m_aabb.m_min.m_quad + v85));
                v82 = _mm_max_ps(v82, *(__m128 *)((char *)&v83->m_aabb.m_max.m_quad + v85));
                --v81;
              }
              while ( v81 );
            }
            v86 = 0i64;
            v87 = _mm_sub_ps(v82, v80);
            v88 = _mm_mul_ps(
                    (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_andnot_ps(_mm_cmpeq_ps(v87, (__m128)0i64), _mm_div_ps(query.m_quad, v87)),
                                4),
                              4),
                    v24);
            if ( !v7->m_firstFree )
              hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
                v7,
                &v273,
                1);
            m_firstFree = v7->m_firstFree;
            v90 = v7->m_nodes.m_data;
            v91 = m_firstFree << 6;
            v7->m_firstFree = v7->m_nodes.m_data[(__int64)(int)m_firstFree].m_aabb.m_min.m_quad.m128_u64[0];
            *(__m128 *)((char *)&v90->m_aabb.m_min.m_quad + v91) = v80;
            *(__m128 *)((char *)&v90->m_aabb.m_max.m_quad + v91) = v82;
            *(unsigned __int64 *)((char *)&v7->m_nodes.m_data->m_parent + v91) = *((_QWORD *)v47 + 2);
            v92 = *((int *)v47 + 6);
            if ( (_DWORD)v92 == -1 )
              v254 = m_firstFree;
            else
              v7->m_nodes.m_data[*((_QWORD *)v47 + 2)].m_children[v92] = m_firstFree;
            v93 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v94 = (hkArrayBase<char *> *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v93[11] + 8i64))(
                                           v93[11],
                                           32i64);
            v259 = v94;
            if ( v94 )
            {
              v94->m_capacityAndFlags = 0x80000000;
              v94->m_data = 0i64;
              v94->m_size = 0;
              v94[1].m_data = (char **)m_firstFree;
              v94[1].m_size = 0;
            }
            else
            {
              v94 = 0i64;
              v259 = 0i64;
            }
            a[0] = (char *)v94;
            v95 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v96 = (hkArrayBase<char *> *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v95[11] + 8i64))(
                                           v95[11],
                                           32i64);
            v262 = v96;
            if ( v96 )
            {
              v96->m_capacityAndFlags = 0x80000000;
              v96->m_data = 0i64;
              v96->m_size = 0;
              v96[1].m_data = (char **)m_firstFree;
              v96[1].m_size = 1;
            }
            else
            {
              v96 = 0i64;
              v262 = 0i64;
            }
            m_capacityAndFlags = v94->m_capacityAndFlags;
            v98 = *((_DWORD *)v47 + 2);
            a[1] = (char *)v96;
            v99 = m_capacityAndFlags & 0x3FFFFFFF;
            if ( v99 >= v98 )
            {
              result.m_enum = HK_SUCCESS;
            }
            else
            {
              v100 = 2 * v99;
              if ( v98 < v100 )
                v98 = v100;
              hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v94->m_data, v98, 8);
            }
            v101 = *((_DWORD *)v47 + 2);
            v102 = v96->m_capacityAndFlags & 0x3FFFFFFF;
            if ( v102 >= v101 )
            {
              v265.m_enum = HK_SUCCESS;
            }
            else
            {
              v103 = 2 * v102;
              if ( v101 < v103 )
                v101 = v103;
              hkArrayUtil::_reserve(&v265, &hkContainerHeapAllocator::s_alloc, (const void **)&v96->m_data, v101, 8);
            }
            hkArrayBase<unsigned __int64>::_append(&array, &hkContainerHeapAllocator::s_alloc, a, 2);
            if ( (__int64)v26 > 0 )
            {
              v104 = 0i64;
              v105 = v26;
              do
              {
                v106 = v255;
                v104 += 64i64;
                *(_DWORD *)&v255[v104 - 56] = 0;
                *(_OWORD *)&v106[v104 - 48] = xmmword_141A712A0;
                *(__m128 *)&v106[v104 - 32] = _mm_xor_ps(v15, (__m128)xmmword_141A712A0);
                *(_DWORD *)&v106[v104 - 16] = 0;
                v107 = v258;
                *(_DWORD *)&v258[v104 - 56] = 0;
                *(_OWORD *)&v107[v104 - 48] = xmmword_141A712A0;
                *(__m128 *)&v107[v104 - 32] = _mm_xor_ps((__m128)xmmword_141A712A0, v15);
                *(_DWORD *)&v107[v104 - 16] = 0;
                v108 = v260;
                *(_DWORD *)&v260[v104 - 56] = 0;
                *(_OWORD *)&v108[v104 - 48] = xmmword_141A712A0;
                *(__m128 *)&v108[v104 - 32] = _mm_xor_ps(v15, (__m128)xmmword_141A712A0);
                *(_DWORD *)&v108[v104 - 16] = 0;
                --v105;
              }
              while ( v105 );
            }
            v109 = *((_DWORD *)v47 + 2) <= 0;
            v110 = v24;
            v270 = 0i64;
            v111 = 0;
            v276 = v24;
            if ( !v109 )
            {
              v112 = 0i64;
              do
              {
                v113 = &v7->m_nodes.m_data[*(_QWORD *)(v112 * 8 + *(_QWORD *)v47)];
                m_quad = v113->m_aabb.m_max.m_quad;
                v115 = v113->m_aabb.m_min.m_quad;
                v116 = _mm_min_ps(
                         _mm_max_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_sub_ps(
                                 _mm_mul_ps(_mm_add_ps(m_quad, v113->m_aabb.m_min.m_quad), (__m128)xmmword_141A711B0),
                                 v80),
                               v88),
                             (__m128)xmmword_141A711B0),
                           aabbOut.m_quad),
                         v25);
                v86 = _mm_max_ps(v116, v86);
                v110 = _mm_min_ps(v116, v110);
                v117 = _mm_xor_si128(
                         (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v116),
                         _mm_cvttps_epi32(v116));
                v118 = v255;
                v119 = (__int64)_mm_cvtsi128_si32(v117) << 6;
                v120 = _mm_max_ps(*(__m128 *)&v255[v119 + 32], m_quad);
                *(__m128 *)&v255[v119 + 16] = _mm_min_ps(*(__m128 *)&v255[v119 + 16], v115);
                *(__m128 *)&v118[v119 + 32] = v120;
                v121 = v258;
                v122 = (__int64)_mm_cvtsi128_si32(_mm_srli_si128(v117, 4)) << 6;
                v123 = _mm_max_ps(*(__m128 *)&v258[v122 + 32], m_quad);
                *(__m128 *)&v258[v122 + 16] = _mm_min_ps(*(__m128 *)&v258[v122 + 16], v115);
                *(__m128 *)&v121[v122 + 32] = v123;
                v124 = v260;
                v125 = (__int64)_mm_cvtsi128_si32(_mm_srli_si128(v117, 8)) << 6;
                v126 = _mm_max_ps(*(__m128 *)&v260[v125 + 32], m_quad);
                *(__m128 *)&v260[v125 + 16] = _mm_min_ps(*(__m128 *)&v260[v125 + 16], v115);
                *(__m128 *)&v124[v125 + 32] = v126;
                v127 = (const void **)&v255[v119];
                v250 = *(unsigned __int64 **)v47;
                if ( *(_DWORD *)&v255[v119 + 8] == (*(_DWORD *)&v255[v119 + 12] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v127, 8);
                *((_QWORD *)*v127 + (int)(*((_DWORD *)v127 + 2))++) = v250[v112];
                v251 = *(unsigned __int64 **)v47;
                v128 = &v258[v122];
                if ( *(_DWORD *)&v258[v122 + 8] == (*(_DWORD *)&v258[v122 + 12] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v258[v122], 8);
                *(_QWORD *)(*(_QWORD *)v128 + 8i64 * (int)(*((_DWORD *)v128 + 2))++) = v251[v112];
                v129 = *(unsigned __int64 **)v47;
                v130 = &v260[v125];
                if ( *(_DWORD *)&v260[v125 + 8] == (*(_DWORD *)&v260[v125 + 12] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v260[v125], 8);
                *(_QWORD *)(*(_QWORD *)v130 + 8i64 * (int)(*((_DWORD *)v130 + 2))++) = v129[v112];
                ++v111;
                ++v112;
              }
              while ( v111 < *((_DWORD *)v47 + 2) );
              v276 = v110;
              v270 = v86;
            }
            v131 = &v255;
            v132 = 0;
            v133 = 0i64;
            v134 = -1;
            v135 = FLOAT_3_40282e38;
            v136 = 0;
            v261 = (unsigned __int64)&v255;
            v137 = 0i64;
            do
            {
              v138 = (int)v276.m128_f32[v137];
              v139 = (int)v270.m128_f32[v137];
              v140 = *v131;
              v263 = 0;
              v266 = 0;
              v141 = (__m128)xmmword_141A712A0;
              v142 = v16;
              v143 = (__m128)xmmword_141A712A0;
              v144 = v16;
              v145 = v138;
              v146 = v139;
              v252 = v140;
              if ( v138 <= (__int64)v139 )
              {
                v147 = v266;
                v148 = (__m128 *)&v140[64 * v146 + 16];
                v149 = (__m128 *)&v252[64 * (__int64)v138 + 16];
                v150 = v263;
                v151 = v146 - v138 + 1;
                do
                {
                  v142 = _mm_max_ps(v142, v149[1]);
                  v141 = _mm_min_ps(v141, *v149);
                  v150 += v149[-1].m128_i32[2];
                  v147 += v148[-1].m128_i32[2];
                  v149 += 4;
                  v144 = _mm_max_ps(v144, v148[1]);
                  v143 = _mm_min_ps(v143, *v148);
                  v152 = _mm_sub_ps(v142, v141);
                  v148 -= 4;
                  v153 = _mm_mul_ps(_mm_shuffle_ps(v152, v152, 201), v152);
                  v154 = _mm_sub_ps(v144, v143);
                  v149[-2].m128_f32[0] = (float)((float)((float)(_mm_shuffle_ps(v153, v153, 85).m128_f32[0]
                                                               + _mm_shuffle_ps(v153, v153, 0).m128_f32[0])
                                                       + _mm_shuffle_ps(v153, v153, 170).m128_f32[0])
                                               * (float)v150)
                                       + v149[-2].m128_f32[0];
                  v155 = _mm_mul_ps(_mm_shuffle_ps(v154, v154, 201), v154);
                  v148[6].m128_f32[0] = (float)((float)((float)(_mm_shuffle_ps(v155, v155, 85).m128_f32[0]
                                                              + _mm_shuffle_ps(v155, v155, 0).m128_f32[0])
                                                      + _mm_shuffle_ps(v155, v155, 170).m128_f32[0])
                                              * (float)v147)
                                      + v148[6].m128_f32[0];
                  --v151;
                }
                while ( v151 );
                v139 = (int)v270.m128_f32[v137];
                v140 = v252;
                v131 = (char **)v261;
              }
              if ( v138 <= v139 )
              {
                if ( v139 - v138 + 1 >= 4 )
                {
                  v156 = v138 + 2;
                  v157 = (__int64)&v140[64 * (__int64)v138 + 48];
                  v145 = v138 + 4i64 * (((unsigned int)(v139 - 3 - v138) >> 2) + 1);
                  do
                  {
                    if ( *(_DWORD *)(v157 - 40) && *(float *)v157 < v135 )
                    {
                      v132 = v136;
                      v133 = v137;
                      v135 = *(float *)v157;
                      v134 = v138;
                    }
                    if ( *(_DWORD *)(v157 + 24) && *(float *)(v157 + 64) < v135 )
                    {
                      v132 = v136;
                      v133 = v137;
                      v135 = *(float *)(v157 + 64);
                      v134 = v156 - 1;
                    }
                    if ( *(_DWORD *)(v157 + 88) && *(float *)(v157 + 128) < v135 )
                    {
                      v132 = v136;
                      v133 = v137;
                      v135 = *(float *)(v157 + 128);
                      v134 = v156;
                    }
                    if ( *(_DWORD *)(v157 + 152) && *(float *)(v157 + 192) < v135 )
                    {
                      v132 = v136;
                      v133 = v137;
                      v135 = *(float *)(v157 + 192);
                      v134 = v156 + 1;
                    }
                    v138 += 4;
                    v157 += 256i64;
                    v156 += 4;
                  }
                  while ( v138 <= v139 - 3 );
                }
                if ( v138 <= v139 )
                {
                  v158 = (float *)&v252[64 * v145 + 48];
                  do
                  {
                    if ( *((_DWORD *)v158 - 10) && *v158 < v135 )
                    {
                      v132 = v136;
                      v133 = v137;
                      v135 = *v158;
                      v134 = v138;
                    }
                    ++v138;
                    v158 += 16;
                  }
                  while ( v138 <= v139 );
                }
                v131 = (char **)v261;
              }
              v131 += 2;
              ++v136;
              ++v137;
              v261 = (unsigned __int64)v131;
              v159 = 0i64;
            }
            while ( v136 < 3 );
            v160 = 2 * v133;
            v161 = v134;
            if ( v134 > 0 )
            {
              v162 = v259;
              v163 = v134;
              do
              {
                hkArrayBase<unsigned __int64>::_append(
                  v162,
                  &hkContainerHeapAllocator::s_alloc,
                  *(char *const **)&(&v255)[v160][v159],
                  *(_DWORD *)&(&v255)[v160][v159 + 8]);
                v159 += 64i64;
                --v163;
              }
              while ( v163 );
              v7 = v298;
              v47 = v264;
            }
            v164 = v134 + 1;
            if ( v134 + 1 < (__int64)v260 )
            {
              v165 = v262;
              v166 = (__int64)v164 << 6;
              v167 = &v260[-v164];
              do
              {
                hkArrayBase<unsigned __int64>::_append(
                  v165,
                  &hkContainerHeapAllocator::s_alloc,
                  *(char *const **)&(&v255)[v160][v166],
                  *(_DWORD *)&(&v255)[v160][v166 + 8]);
                v166 += 64i64;
                --v167;
              }
              while ( v167 );
              v7 = v298;
            }
            v168 = v259->m_size;
            v169 = v262->m_size;
            if ( v168 && v169 || !(v168 | v169) )
            {
              v170 = (&v255)[v160];
              v171 = v161 << 6;
              v274.m_axis = v132;
              v172 = *(_DWORD *)&v170[v171 + 8];
              v173 = *(unsigned __int64 **)&v170[v171];
              v274.m_tree = v7;
              v269 = v274;
              hkAlgorithm::explicitStackQuickSort<unsigned __int64,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::SAHBin::Sorter>(
                v173,
                v172,
                &v269);
              hkArrayBase<unsigned __int64>::_append(
                v259,
                &hkContainerHeapAllocator::s_alloc,
                (char *const *)v173,
                v172 >> 1);
              v174 = v262;
              v175 = (char *const *)&v173[v172 >> 1];
              v176 = v172 - (v172 >> 1);
            }
            else
            {
              v177 = (&v255)[v160];
              v178 = v161 << 6;
              v176 = *(_DWORD *)&v177[v178 + 8];
              v175 = *(char *const **)&v177[v178];
              v174 = (hkArrayBase<char *> *)a[v169 == 0];
            }
            hkArrayBase<unsigned __int64>::_append(v174, &hkContainerHeapAllocator::s_alloc, v175, v176);
          }
          else
          {
            for ( ; (int)v48 > 1; LODWORD(v48) = *((_DWORD *)v47 + 2) )
            {
              v49 = 3.40282e38;
              v50 = -1;
              v51 = 0;
              v52 = -1;
              v53 = xmmword_141A712A0;
              v54 = (int)v48;
              v55 = _mm_xor_ps((__m128)xmmword_141A712A0, v15);
              v56 = v7->m_nodes.m_data;
              v57 = *(unsigned __int64 **)v47;
              v58 = (int)v48;
              v249 = (int)v48;
              v59 = 1i64;
              do
              {
                v60 = v51 + 1;
                v61 = *v57 << 6;
                v62 = *(__m128 *)((char *)&v56->m_aabb.m_min.m_quad + v61);
                v63 = *(__m128 *)((char *)&v56->m_aabb.m_max.m_quad + v61);
                if ( v59 < v54 )
                {
                  v64 = v57 + 1;
                  v65 = v54 - v59;
                  do
                  {
                    v66 = *v64 << 6;
                    v67 = _mm_max_ps(*(__m128 *)((char *)&v56->m_aabb.m_max.m_quad + v66), v63);
                    v297 = *(__m128 *)((char *)&v56->m_aabb.m_min.m_quad + v66);
                    v68 = _mm_min_ps(v297, v62);
                    v69 = _mm_sub_ps(v67, v68);
                    v70 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v69);
                    v71 = (float)(_mm_shuffle_ps(v70, v70, 85).m128_f32[0] + _mm_shuffle_ps(v70, v70, 0).m128_f32[0])
                        + _mm_shuffle_ps(v70, v70, 170).m128_f32[0];
                    if ( v71 < v49 )
                    {
                      v49 = v71;
                      v53 = (__int128)v68;
                      v55 = v67;
                      v50 = v51;
                      v52 = v60;
                    }
                    ++v60;
                    ++v64;
                    --v65;
                  }
                  while ( v65 );
                  v58 = v249;
                }
                ++v51;
                ++v57;
                ++v59;
                v249 = --v58;
              }
              while ( v58 );
              v72 = v50;
              v73 = *(_QWORD *)(*(_QWORD *)v47 + 8i64 * v50);
              v74 = *(_QWORD *)(*(_QWORD *)v47 + 8i64 * v52);
              if ( !v7->m_firstFree )
                hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
                  v7,
                  &v272,
                  1);
              v75 = v7->m_firstFree;
              v76 = v7->m_nodes.m_data;
              v77 = v75 << 6;
              v7->m_firstFree = v7->m_nodes.m_data[(__int64)(int)v75].m_aabb.m_min.m_quad.m128_u64[0];
              *(hkVector4f *)((char *)&v76->m_aabb.m_min + v77) = (hkVector4f)v53;
              *(__m128 *)((char *)&v76->m_aabb.m_max.m_quad + v77) = v55;
              *(unsigned __int64 *)((char *)v7->m_nodes.m_data->m_children + v77) = v73;
              *(unsigned __int64 *)((char *)&v7->m_nodes.m_data->m_children[1] + v77) = v74;
              v7->m_nodes.m_data[v73].m_parent = v75;
              v7->m_nodes.m_data[v74].m_parent = v75;
              v78 = (int)--*((_DWORD *)v47 + 2);
              if ( (_DWORD)v78 != v52 )
                *(_QWORD *)(*(_QWORD *)v47 + 8i64 * v52) = *(_QWORD *)(*(_QWORD *)v47 + 8 * v78);
              *(_QWORD *)(*(_QWORD *)v47 + 8 * v72) = v75;
            }
            v79 = **(_QWORD **)v47;
            v7->m_nodes.m_data[v79].m_parent = *((_QWORD *)v47 + 2);
            v7->m_nodes.m_data[*((_QWORD *)v47 + 2)].m_children[*((int *)v47 + 6)] = v79;
          }
          v179 = *((_DWORD *)v47 + 3);
          *((_DWORD *)v47 + 2) = 0;
          if ( v179 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)v47,
              8 * v179);
          *(_QWORD *)v47 = 0i64;
          *((_DWORD *)v47 + 3) = 0x80000000;
          v180 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, char *, __int64))(*v180[11] + 16i64))(v180[11], v47, 32i64);
          v46 = array.m_size;
          v26 = v260;
        }
        while ( array.m_size );
        if ( vars0 )
        {
          v181 = v254;
          v182 = (char *)(v254 << 6);
          v260 = (char *)(v254 << 6);
          do
          {
            v183 = v7->m_nodes.m_data;
            m_enum = 0;
            v185 = *(unsigned __int64 *)((char *)v7->m_nodes.m_data->m_children + (unsigned __int64)v182);
            LOBYTE(result.m_enum) = 0;
            if ( !v185 )
              break;
            do
            {
              v186 = v185 << 6;
              if ( LODWORD(v183[v185].m_children[0]) )
              {
                p_m_quad = &v183[*(unsigned __int64 *)((char *)v183->m_children + v186)].m_aabb.m_min.m_quad;
                v188 = &v183[*(unsigned __int64 *)((char *)&v183->m_children[1] + v186)].m_aabb.m_min.m_quad;
                v189 = _mm_sub_ps(v188[1], *v188);
                v190 = _mm_sub_ps(p_m_quad[1], *p_m_quad);
                v191 = _mm_mul_ps(_mm_shuffle_ps(v190, v190, 201), v190);
                v192 = _mm_mul_ps(_mm_shuffle_ps(v189, v189, 201), v189);
                v193 = (float)((float)(_mm_shuffle_ps(v191, v191, 85).m128_f32[0]
                                     + _mm_shuffle_ps(v191, v191, 0).m128_f32[0])
                             + _mm_shuffle_ps(v191, v191, 170).m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v192, v192, 85).m128_f32[0]
                                     + _mm_shuffle_ps(v192, v192, 0).m128_f32[0])
                             + _mm_shuffle_ps(v192, v192, 170).m128_f32[0]);
                if ( p_m_quad[2].m128_i32[2] && v188[2].m128_i32[2] )
                {
                  v194 = &v290;
                  v195 = &v188[2].m128_u64[1];
                  v196 = 2i64;
                  do
                  {
                    v194 += 2;
                    v197 = *(unsigned __int64 *)((char *)v195 + (char *)p_m_quad - (char *)v188) << 6;
                    v198 = *v195++ << 6;
                    v199 = (__m128 *)((char *)&v183->m_aabb.m_min.m_quad + v197);
                    v200 = (__m128 *)((char *)&v183->m_aabb.m_min.m_quad + v198);
                    *(unsigned __int64 *)((char *)v195 + (char *)&v265 - (char *)v188 - 8) = (unsigned __int64)v199;
                    *(unsigned __int64 *)((char *)v195 + (char *)a - (char *)v188 - 8) = (unsigned __int64)v200;
                    v201 = v199[1];
                    v194[-7] = *v199;
                    v202 = *v200;
                    v194[-6] = v201;
                    v203 = v200[1];
                    v194[-3] = v202;
                    v194[-2] = v203;
                    --v196;
                  }
                  while ( v196 );
                  v7 = v298;
                  v282 = _mm_max_ps(v286, v292);
                  v280 = _mm_max_ps(v288, v292);
                  v278 = _mm_max_ps(v286, v290);
                  v284 = _mm_max_ps(v288, v290);
                  v281 = _mm_min_ps(v285, v291);
                  v279 = _mm_min_ps(v287, v291);
                  v277 = _mm_min_ps(v285, v289);
                  v283 = _mm_min_ps(v287, v289);
                  v204 = _mm_sub_ps(v280, v279);
                  v205 = _mm_sub_ps(v278, v277);
                  v206 = _mm_sub_ps(v282, v281);
                  v207 = _mm_sub_ps(v284, v283);
                  v208 = _mm_mul_ps(_mm_shuffle_ps(v204, v204, 201), v204);
                  v209 = _mm_mul_ps(_mm_shuffle_ps(v205, v205, 201), v205);
                  v210 = _mm_mul_ps(_mm_shuffle_ps(v207, v207, 201), v207);
                  v211 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v208, v208, 85), _mm_shuffle_ps(v208, v208, 0)),
                             _mm_shuffle_ps(v208, v208, 170)),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v209, v209, 85), _mm_shuffle_ps(v209, v209, 0)),
                             _mm_shuffle_ps(v209, v209, 170)));
                  v212 = _mm_mul_ps(_mm_shuffle_ps(v206, v206, 201), v206);
                  v274 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::SAHBin::Sorter)v211;
                  v275 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v212, v212, 85), _mm_shuffle_ps(v212, v212, 0)),
                             _mm_shuffle_ps(v212, v212, 170)),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v210, v210, 85), _mm_shuffle_ps(v210, v210, 0)),
                             _mm_shuffle_ps(v210, v210, 170)));
                  v213 = v211.m128_f32[0] >= v275.m128_f32[0];
                  v214 = v211.m128_f32[0] >= v275.m128_f32[0];
                  if ( COERCE_FLOAT(*((_OWORD *)&v274 + v214)) >= v193 )
                  {
                    m_enum = result.m_enum;
                  }
                  else
                  {
                    p_m_quad[3].m128_u64[0] = (__int64)(*((_QWORD *)&v269.m_axis
                                                        + (int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH::`77::lut[v214][0])
                                                      - (_QWORD)v183) >> 6;
                    v188[2].m128_u64[1] = (__int64)(*((_QWORD *)&v269.m_axis
                                                    + (int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH::`77::lut[v214][1])
                                                  - (unsigned __int64)v7->m_nodes.m_data) >> 6;
                    v188[3].m128_u64[0] = (__int64)(*((_QWORD *)&v269.m_axis
                                                    + (int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH::`77::lut[v214][2])
                                                  - (unsigned __int64)v7->m_nodes.m_data) >> 6;
                    *(_QWORD *)(*((_QWORD *)&v269.m_axis
                                + (int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH::`77::lut[v214][0])
                              + 32i64) = ((char *)p_m_quad - (char *)v7->m_nodes.m_data) >> 6;
                    *(_QWORD *)(*((_QWORD *)&v269.m_axis
                                + (int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH::`77::lut[v214][1])
                              + 32i64) = ((char *)v188 - (char *)v7->m_nodes.m_data) >> 6;
                    v215 = *((_QWORD *)&v269.m_axis
                           + (int)`hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH::`77::lut[v214][2]);
                    m_enum = 1;
                    v216 = ((char *)v188 - (char *)v7->m_nodes.m_data) >> 6;
                    LOBYTE(result.m_enum) = 1;
                    *(_QWORD *)(v215 + 32) = v216;
                    v217 = *(&v278 + 4 * v213);
                    v218 = 2 * v213 + 1;
                    *p_m_quad = *(&v277 + 4 * v213);
                    v219 = *(&v277 + 2 * v218);
                    p_m_quad[1] = v217;
                    v220 = *(&v278 + 2 * v218);
                    *v188 = v219;
                    v188[1] = v220;
                  }
                }
                v181 = v254;
              }
              v183 = v7->m_nodes.m_data;
              if ( *(_DWORD *)((char *)v7->m_nodes.m_data->m_children + v186) )
              {
                v185 = *(unsigned __int64 *)((char *)v183->m_children + v186);
              }
              else
              {
                m_parent = *(unsigned __int64 *)((char *)&v183->m_parent + v186);
                for ( i = v185; m_parent != v181; m_parent = v183[m_parent].m_parent )
                {
                  if ( v183[m_parent].m_children[1] != i )
                    break;
                  i = m_parent;
                }
                if ( m_parent )
                  v185 = v183[m_parent].m_children[1];
                else
                  v185 = i;
                if ( m_parent == v181 && v185 == i )
                  v185 = 0i64;
              }
            }
            while ( v185 );
            v182 = v260;
          }
          while ( m_enum );
          v223 = v7->m_nodes.m_data;
          v224 = *(unsigned __int64 *)((char *)v7->m_nodes.m_data->m_children + (unsigned __int64)v182);
          while ( v224 )
          {
            v225 = v224 << 6;
            if ( LODWORD(v223[v224].m_children[0]) )
            {
              v226 = *(unsigned __int64 *)((char *)v223->m_children + v225);
              v227 = _mm_sub_ps(v223[v226].m_aabb.m_max.m_quad, v223[v226].m_aabb.m_min.m_quad);
              v228 = _mm_sub_ps(
                       v223[*(unsigned __int64 *)((char *)&v223->m_children[1] + v225)].m_aabb.m_max.m_quad,
                       v223[*(unsigned __int64 *)((char *)&v223->m_children[1] + v225)].m_aabb.m_min.m_quad);
              v229 = _mm_mul_ps(_mm_shuffle_ps(v227, v227, 201), v227);
              v230 = _mm_mul_ps(_mm_shuffle_ps(v228, v228, 201), v228);
              if ( (float)((float)(_mm_shuffle_ps(v230, v230, 85).m128_f32[0] + _mm_shuffle_ps(v230, v230, 0).m128_f32[0])
                         + _mm_shuffle_ps(v230, v230, 170).m128_f32[0]) > (float)((float)(_mm_shuffle_ps(v229, v229, 85).m128_f32[0]
                                                                                        + _mm_shuffle_ps(v229, v229, 0).m128_f32[0])
                                                                                + _mm_shuffle_ps(v229, v229, 170).m128_f32[0]) )
              {
                *(unsigned __int64 *)((char *)v223->m_children + v225) = *(unsigned __int64 *)((char *)&v223->m_children[1]
                                                                                             + v225);
                *(unsigned __int64 *)((char *)&v223->m_children[1] + v225) = v226;
              }
            }
            v223 = v7->m_nodes.m_data;
            if ( *(_DWORD *)((char *)v7->m_nodes.m_data->m_children + v225) )
            {
              v224 = *(unsigned __int64 *)((char *)v223->m_children + v225);
            }
            else
            {
              v231 = *(unsigned __int64 *)((char *)&v223->m_parent + v225);
              for ( j = v224; v231 != v181; v231 = v223[v231].m_parent )
              {
                if ( v223[v231].m_children[1] != j )
                  break;
                j = v231;
              }
              if ( v231 )
                v224 = v223[v231].m_children[1];
              else
                v224 = j;
              if ( v231 == v181 && v224 == j )
                v224 = 0i64;
            }
          }
        }
        v233 = v271;
        v234 = v254;
        v7->m_nodes.m_data[v254].m_parent = v271;
        if ( v233 )
        {
          v7->m_nodes.m_data[v233].m_children[(int)v258] = v234;
          v235 = v7->m_nodes.m_data;
          do
          {
            v236 = v233 << 6;
            v237 = *(unsigned __int64 *)((char *)v235->m_children + v236) << 6;
            v238 = *(unsigned __int64 *)((char *)&v235->m_children[1] + v236) << 6;
            v239 = _mm_max_ps(
                     *(__m128 *)((char *)&v235->m_aabb.m_max.m_quad + v237),
                     *(__m128 *)((char *)&v235->m_aabb.m_max.m_quad + v238));
            *(__m128 *)((char *)&v235->m_aabb.m_min.m_quad + v236) = _mm_min_ps(
                                                                       *(__m128 *)((char *)&v235->m_aabb.m_min.m_quad
                                                                                 + v237),
                                                                       *(__m128 *)((char *)&v235->m_aabb.m_min.m_quad
                                                                                 + v238));
            *(__m128 *)((char *)&v235->m_aabb.m_max.m_quad + v236) = v239;
            v235 = v7->m_nodes.m_data;
            v233 = *(unsigned __int64 *)((char *)&v7->m_nodes.m_data->m_parent + v236);
          }
          while ( v233 );
        }
        else
        {
          v7->m_root = v234;
        }
        v240 = (int *)&v259 + 1;
        do
        {
          v241 = *(v240 - 5);
          v242 = *(_QWORD *)(v240 - 7);
          v240 -= 4;
          v243 = v241 - 1;
          v244 = v243;
          if ( v243 >= 0 )
          {
            v245 = (int *)(((__int64)v243 << 6) + v242 + 12);
            do
            {
              v246 = *v245;
              *(v245 - 1) = 0;
              if ( v246 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerHeapAllocator::s_alloc,
                  *(void **)(v245 - 3),
                  8 * v246);
              *(_QWORD *)(v245 - 3) = 0i64;
              *v245 = 0x80000000;
              v245 -= 16;
              --v244;
            }
            while ( v244 >= 0 );
          }
          v247 = *v240;
          *(v240 - 1) = 0;
          if ( v247 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)(v240 - 3),
              v247 << 6);
          v248 = (int)v267 - 1 < 0;
          LODWORD(v267) = v267 - 1;
          *(_QWORD *)(v240 - 3) = 0i64;
          *v240 = 0x80000000;
        }
        while ( !v248 );
        array.m_size = 0;
        if ( array.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            array.m_data,
            8 * array.m_capacityAndFlags);
      }
    }
  }
}        array.m_data,
            8 * array.m_capacityAndFlags);
      }
    }
  }
}

// File Line: 661
// RVA: 0xDF4730
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildGlobalSAH(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this,
        int minBins,
        int maxBins,
        int step)
{
  float v8; // xmm7_4
  float v9; // xmm6_4
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree output; // [rsp+30h] [rbp-C8h] BYREF
  hkSimdFloat32 result; // [rsp+60h] [rbp-98h] BYREF
  hkErrStream v15; // [rsp+70h] [rbp-88h] BYREF
  char buf[520]; // [rsp+88h] [rbp-70h] BYREF

  output.m_nodes.m_capacityAndFlags = 0x80000000;
  output.m_nodes.m_size = 0;
  output.m_nodes.m_data = 0i64;
  memset(&output.m_firstFree, 0, 24);
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
    this,
    &output);
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::computeCost(&output, &result);
  if ( minBins <= maxBins )
  {
    v8 = result.m_real.m128_f32[0];
    do
    {
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(
        this,
        this->m_root,
        (hkBool)1,
        minBins,
        16);
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::computeCost(this, &result);
      v9 = result.m_real.m128_f32[0];
      if ( result.m_real.m128_f32[0] < v8 )
      {
        hkErrStream::hkErrStream(&v15, buf, 512);
        v10 = hkOstream::operator<<(&v15, "#");
        v11 = hkOstream::operator<<(v10, minBins);
        v12 = hkOstream::operator<<(v11, ": ");
        hkOstream::operator<<(v12, v9);
        hkError::messageReport(
          0xFFFFFFFF,
          buf,
          "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/DynamicTree/hkcdDynamicTree.inl",
          670);
        hkOstream::~hkOstream(&v15);
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
          this,
          &output);
        v8 = v9;
      }
      minBins += step;
    }
    while ( minBins <= maxBins );
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
    &output,
    (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *)this);
  output.m_nodes.m_size = 0;
  if ( output.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output.m_nodes.m_data,
      output.m_nodes.m_capacityAndFlags << 6);
}

// File Line: 711
// RVA: 0xCBED00
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *output)
{
  int m_capacityAndFlags; // r8d
  int m_size; // esi
  int v6; // eax
  unsigned __int64 m_root; // rsi
  __int64 v8; // r14
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rsi
  hkcdDynamicTree::CodecRawUlong *v11; // rdi
  hkVector4f v12; // xmm6
  hkVector4f v13; // xmm7
  unsigned __int64 m_firstFree; // rdx
  hkcdDynamicTree::CodecRawUlong *v15; // r8
  __int64 v16; // r14
  int v17; // ecx
  _QWORD *array; // [rsp+30h] [rbp-D0h] BYREF
  int v19; // [rsp+38h] [rbp-C8h]
  int v20; // [rsp+3Ch] [rbp-C4h]
  __int64 *v21; // [rsp+40h] [rbp-C0h] BYREF
  int v22; // [rsp+48h] [rbp-B8h]
  int v23; // [rsp+4Ch] [rbp-B4h]
  __int64 v24; // [rsp+50h] [rbp-B0h] BYREF
  hkResult result; // [rsp+2A0h] [rbp+1A0h] BYREF

  m_capacityAndFlags = output->m_nodes.m_capacityAndFlags;
  output->m_nodes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output->m_nodes.m_data,
      m_capacityAndFlags << 6);
  output->m_nodes.m_data = 0i64;
  output->m_nodes.m_capacityAndFlags = 0x80000000;
  output->m_firstFree = 0i64;
  output->m_root = 0i64;
  *(_QWORD *)&output->m_numLeaves = 0i64;
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
    output,
    &result,
    2 * this->m_numLeaves);
  if ( this->m_root )
  {
    m_size = this->m_nodes.m_size;
    v6 = 0;
    array = 0i64;
    v20 = 0x80000000;
    v19 = 0;
    if ( m_size > 0 )
    {
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_size, 8);
      v6 = v19;
    }
    if ( m_size - v6 > 0 )
      memset(&array[v6], 0, 8i64 * (m_size - v6));
    v19 = m_size;
    m_root = this->m_root;
    v21 = &v24;
    v23 = -2147483584;
    v24 = 0i64;
    v22 = 1;
    v8 = 0i64;
    do
    {
      v9 = m_root;
      v10 = array[(int)m_root];
      v11 = &this->m_nodes.m_data[v9];
      v12.m_quad = (__m128)v11->m_aabb.m_min;
      v13.m_quad = (__m128)v11->m_aabb.m_max;
      if ( !output->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
          output,
          &result,
          1);
      m_firstFree = output->m_firstFree;
      v15 = &output->m_nodes.m_data[m_firstFree];
      output->m_firstFree = output->m_nodes.m_data[(__int64)(int)m_firstFree].m_aabb.m_min.m_quad.m128_u64[0];
      v15->m_parent = v10;
      v15->m_aabb.m_min = (hkVector4f)v12.m_quad;
      v15->m_aabb.m_max = (hkVector4f)v13.m_quad;
      if ( v10 )
        output->m_nodes.m_data[v10].m_children[v8] = m_firstFree;
      else
        output->m_root = m_firstFree;
      m_root = v11->m_children[0];
      v16 = v11->m_children[1];
      if ( (_DWORD)m_root )
      {
        array[(int)m_root] = m_firstFree;
        array[(int)v16] = m_firstFree;
        v17 = v22;
        if ( v22 == (v23 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v21, 8);
          v17 = v22;
        }
        v21[v17] = v16;
        ++v22;
        v8 = 0i64;
      }
      else
      {
        v15->m_children[1] = v16;
        v15->m_children[0] = m_root;
        v8 = 1i64;
        m_root = v21[--v22];
      }
    }
    while ( m_root );
    v22 = 0;
    if ( v23 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v21, 8 * v23);
    v21 = 0i64;
    v23 = 0x80000000;
    v19 = 0;
    if ( v20 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v20);
  }
  output->m_numLeaves = this->m_numLeaves;
  output->m_path = this->m_path;
}

// File Line: 770
// RVA: 0xCBFD20
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::compactIndices(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this)
{
  unsigned __int64 m_firstFree; // rax
  int m_capacityAndFlags; // r8d
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree v4; // [rsp+20h] [rbp-38h] BYREF

  if ( this->m_root )
  {
    v4.m_nodes.m_size = 0;
    v4.m_nodes.m_data = 0i64;
    memset(&v4.m_firstFree, 0, 24);
    v4.m_nodes.m_capacityAndFlags = 0x80000000;
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
      this,
      &v4);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v4,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this);
    m_firstFree = this->m_firstFree;
    m_capacityAndFlags = v4.m_nodes.m_capacityAndFlags;
    this->m_firstFree = v4.m_firstFree;
    v4.m_nodes.m_size = 0;
    this->m_root = 1i64;
    v4.m_firstFree = m_firstFree;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v4.m_nodes.m_data,
        m_capacityAndFlags << 6);
  }
}

// File Line: 783
// RVA: 0xDF2C50
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::detachBranch(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this,
        unsigned __int64 node,
        __int64 leafData,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *branchOut)
{
  int m_capacityAndFlags; // r8d
  int v8; // r8d
  hkcdDynamicTree::CodecRawUlong *m_data; // rax
  unsigned __int64 v10; // rbx
  hkcdDynamicTree::CodecRawUlong *v11; // r9
  unsigned __int64 v12; // rax
  unsigned __int64 m_parent; // rax
  unsigned __int64 i; // rdx
  int v15; // eax
  int v16; // r12d
  __int64 j; // r15
  _QWORD *v18; // rdx
  unsigned __int64 v19; // r13
  hkcdDynamicTree::CodecRawUlong *v20; // rax
  unsigned __int64 v21; // r9
  hkcdDynamicTree::CodecRawUlong *v22; // rdi
  int v23; // ebx
  unsigned __int64 v24; // rcx
  hkVector4f v25; // xmm1
  unsigned __int64 v26; // rdx
  unsigned __int64 v27; // rax
  unsigned __int64 v28; // r9
  hkcdDynamicTree::CodecRawUlong *v29; // r8
  int v30; // edi
  __int64 v31; // r14
  unsigned int Key; // eax
  hkcdDynamicTree::CodecRawUlong *v33; // rbx
  unsigned int v34; // eax
  unsigned __int64 v35; // rdx
  unsigned int v36; // eax
  _QWORD *array; // [rsp+20h] [rbp-50h] BYREF
  int v38; // [rsp+28h] [rbp-48h]
  int v39; // [rsp+2Ch] [rbp-44h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v40; // [rsp+30h] [rbp-40h] BYREF
  hkResult result; // [rsp+88h] [rbp+18h] BYREF
  __int64 v42; // [rsp+90h] [rbp+20h]
  unsigned __int64 m_firstFree; // [rsp+98h] [rbp+28h]

  v42 = leafData;
  m_capacityAndFlags = branchOut->m_nodes.m_capacityAndFlags;
  branchOut->m_nodes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      branchOut->m_nodes.m_data,
      m_capacityAndFlags << 6);
  branchOut->m_nodes.m_data = 0i64;
  branchOut->m_nodes.m_capacityAndFlags = 0x80000000;
  branchOut->m_firstFree = 0i64;
  branchOut->m_root = 0i64;
  *(_QWORD *)&branchOut->m_numLeaves = 0i64;
  array = 0i64;
  v8 = 0;
  v38 = 0;
  v39 = 0x80000000;
  if ( node )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
    array[v38] = node;
    m_data = this->m_nodes.m_data;
    v8 = ++v38;
    if ( LODWORD(m_data[node].m_children[0]) )
    {
      v10 = m_data[node].m_children[0];
      while ( v10 )
      {
        if ( v8 == (v39 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
          v8 = v38;
        }
        array[v8] = v10;
        v8 = ++v38;
        v11 = this->m_nodes.m_data;
        v12 = v10 << 6;
        if ( LODWORD(this->m_nodes.m_data[v10].m_children[0]) )
        {
          v10 = *(unsigned __int64 *)((char *)v11->m_children + v12);
        }
        else
        {
          m_parent = *(unsigned __int64 *)((char *)&v11->m_parent + v12);
          for ( i = v10; m_parent != node; m_parent = v11[m_parent].m_parent )
          {
            if ( v11[m_parent].m_children[1] != i )
              break;
            i = m_parent;
          }
          if ( m_parent )
            v10 = v11[m_parent].m_children[1];
          else
            v10 = i;
          if ( m_parent == node && v10 == i )
            v10 = 0i64;
        }
      }
    }
  }
  v40.m_elem = 0i64;
  v40.m_numElems = 0;
  v40.m_hashMod = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &v40,
    &hkContainerHeapAllocator::s_alloc,
    v8);
  v15 = v38;
  v16 = 0;
  for ( j = 0i64; v16 < v38; ++j )
  {
    v18 = array;
    v19 = array[j];
    if ( !branchOut->m_firstFree )
    {
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
        branchOut,
        &result,
        1);
      v18 = array;
    }
    v20 = branchOut->m_nodes.m_data;
    m_firstFree = branchOut->m_firstFree;
    v21 = (int)m_firstFree;
    branchOut->m_firstFree = v20[(__int64)(int)m_firstFree].m_aabb.m_min.m_quad.m128_u64[0];
    v22 = &this->m_nodes.m_data[v19];
    v23 = LODWORD(v22->m_children[0]) == 0;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v40,
      &hkContainerHeapAllocator::s_alloc,
      SLODWORD(v18[j]),
      v21);
    v24 = v22->m_parent;
    v25.m_quad = (__m128)v22->m_aabb.m_max;
    v26 = v22->m_children[0];
    v27 = v22->m_children[1];
    v28 = m_firstFree;
    v29 = &branchOut->m_nodes.m_data[m_firstFree];
    v29->m_aabb.m_min = v22->m_aabb.m_min;
    v29->m_aabb.m_max = (hkVector4f)v25.m_quad;
    v29->m_parent = v24;
    v29->m_children[0] = v26;
    v29->m_children[1] = v27;
    branchOut->m_numLeaves += v23;
    this->m_numLeaves -= v23;
    if ( j )
    {
      this->m_nodes.m_data[(__int64)(int)v19].m_aabb.m_min.m_quad.m128_u64[0] = this->m_firstFree;
      this->m_firstFree = v19;
    }
    else
    {
      ++this->m_numLeaves;
      v22->m_children[1] = v42;
      v22->m_children[0] = 0i64;
      branchOut->m_root = v28;
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
      Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                            &v40,
                            SLODWORD(array[v31]));
      v33 = &branchOut->m_nodes.m_data[(__int64)SLODWORD(v40.m_elem[Key].val)];
      v33->m_parent = (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             &v40,
                             SLODWORD(v33->m_parent),
                             0i64);
      if ( LODWORD(v33->m_children[0]) )
      {
        v34 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              &v40,
                              SLODWORD(v33->m_children[0]));
        v35 = SLODWORD(v33->m_children[1]);
        v33->m_children[0] = SLODWORD(v40.m_elem[v34].val);
        v36 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              &v40,
                              v35);
        v33->m_children[1] = SLODWORD(v40.m_elem[v36].val);
      }
      ++v30;
      ++v31;
    }
    while ( v30 < v38 );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v40,
    &hkContainerHeapAllocator::s_alloc);
  v38 = 0;
  if ( v39 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v39);
}

// File Line: 862
// RVA: 0xDF4A20
unsigned __int64 __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rotateLeft(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this,
        unsigned __int64 node)
{
  hkcdDynamicTree::CodecRawUlong *m_data; // r11
  hkcdDynamicTree::CodecRawUlong *v4; // r8
  unsigned __int64 result; // rax
  hkcdDynamicTree::CodecRawUlong *v6; // r9
  unsigned __int64 m_parent; // rdi
  hkcdDynamicTree::CodecRawUlong *v8; // rcx
  __m128 *v9; // r8
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rcx
  __m128 v12; // xmm1
  __m128 *v13; // r8
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rcx
  __m128 v16; // xmm2

  m_data = this->m_nodes.m_data;
  v4 = &this->m_nodes.m_data[node];
  if ( !LODWORD(v4->m_children[0]) )
    return 0i64;
  v6 = &m_data[v4->m_children[1]];
  if ( !LODWORD(v6->m_children[0]) )
    return 0i64;
  m_parent = v4->m_parent;
  v8 = &m_data[v6->m_children[0]];
  v8->m_parent = v4 - m_data;
  v4->m_children[1] = v8 - this->m_nodes.m_data;
  v4->m_parent = v6 - this->m_nodes.m_data;
  v6->m_children[0] = v4 - this->m_nodes.m_data;
  v6->m_parent = m_parent;
  v9 = (__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad
                + (((char *)v4 - (char *)this->m_nodes.m_data) & 0xFFFFFFFFFFFFFFC0ui64));
  v10 = v9[2].m128_u64[1] << 6;
  v11 = v9[3].m128_u64[0] << 6;
  v12 = _mm_min_ps(
          *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad + v10),
          *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad + v11));
  v9[1] = _mm_max_ps(
            *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_max.m_quad + v10),
            *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_max.m_quad + v11));
  *v9 = v12;
  v13 = (__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad
                 + (((char *)v6 - (char *)this->m_nodes.m_data) & 0xFFFFFFFFFFFFFFC0ui64));
  v14 = v13[2].m128_u64[1] << 6;
  v15 = v13[3].m128_u64[0] << 6;
  v16 = _mm_max_ps(
          *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_max.m_quad + v14),
          *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_max.m_quad + v15));
  *v13 = _mm_min_ps(
           *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad + v14),
           *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad + v15));
  v13[1] = v16;
  if ( m_parent )
  {
    this->m_nodes.m_data[m_parent].m_children[this->m_nodes.m_data[m_parent].m_children[1] == node] = v6 - this->m_nodes.m_data;
    return v6 - this->m_nodes.m_data;
  }
  else
  {
    result = v6 - this->m_nodes.m_data;
    this->m_root = result;
  }
  return result;
}

// File Line: 891
// RVA: 0xDF4B80
unsigned __int64 __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rotateRight(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this,
        unsigned __int64 node)
{
  hkcdDynamicTree::CodecRawUlong *m_data; // r11
  hkcdDynamicTree::CodecRawUlong *v4; // r8
  unsigned __int64 result; // rax
  hkcdDynamicTree::CodecRawUlong *v6; // r9
  unsigned __int64 m_parent; // rdi
  hkcdDynamicTree::CodecRawUlong *v8; // rcx
  __m128 *v9; // r8
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rcx
  __m128 v12; // xmm1
  __m128 *v13; // r8
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rcx
  __m128 v16; // xmm2

  m_data = this->m_nodes.m_data;
  v4 = &this->m_nodes.m_data[node];
  if ( !LODWORD(v4->m_children[0]) )
    return 0i64;
  v6 = &m_data[v4->m_children[0]];
  if ( !LODWORD(v6->m_children[0]) )
    return 0i64;
  m_parent = v4->m_parent;
  v8 = &m_data[v6->m_children[1]];
  v8->m_parent = v4 - m_data;
  v4->m_children[0] = v8 - this->m_nodes.m_data;
  v4->m_parent = v6 - this->m_nodes.m_data;
  v6->m_children[1] = v4 - this->m_nodes.m_data;
  v6->m_parent = m_parent;
  v9 = (__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad
                + (((char *)v4 - (char *)this->m_nodes.m_data) & 0xFFFFFFFFFFFFFFC0ui64));
  v10 = v9[2].m128_u64[1] << 6;
  v11 = v9[3].m128_u64[0] << 6;
  v12 = _mm_min_ps(
          *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad + v10),
          *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad + v11));
  v9[1] = _mm_max_ps(
            *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_max.m_quad + v10),
            *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_max.m_quad + v11));
  *v9 = v12;
  v13 = (__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad
                 + (((char *)v6 - (char *)this->m_nodes.m_data) & 0xFFFFFFFFFFFFFFC0ui64));
  v14 = v13[2].m128_u64[1] << 6;
  v15 = v13[3].m128_u64[0] << 6;
  v16 = _mm_max_ps(
          *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_max.m_quad + v14),
          *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_max.m_quad + v15));
  *v13 = _mm_min_ps(
           *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad + v14),
           *(__m128 *)((char *)&this->m_nodes.m_data->m_aabb.m_min.m_quad + v15));
  v13[1] = v16;
  if ( m_parent )
  {
    this->m_nodes.m_data[m_parent].m_children[this->m_nodes.m_data[m_parent].m_children[1] == node] = v6 - this->m_nodes.m_data;
    return v6 - this->m_nodes.m_data;
  }
  else
  {
    result = v6 - this->m_nodes.m_data;
    this->m_root = result;
  }
  return result;
}

// File Line: 920
// RVA: 0xDF22F0
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::balance(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *this,
        int maxDelta,
        unsigned __int64 node)
{
  unsigned __int64 m_root; // rbp
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v5; // rdi
  hkcdDynamicTree::CodecRawUlong *v6; // rbx
  hkcdDynamicTree::CodecRawUlong *m_data; // rdx
  int v8; // esi
  hkcdDynamicTree::CodecRawUlong *v9; // rdi
  unsigned __int64 v10; // r11
  int v11; // ebx
  unsigned __int64 v12; // r9
  unsigned __int64 m_parent; // rax
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
  int k; // r8d
  int v32; // r8d
  unsigned __int64 v33; // rax
  unsigned __int64 m; // r8
  int n; // ebx
  int v36; // esi
  signed int v37; // eax
  unsigned __int64 v38; // rax
  signed int v41; // [rsp+60h] [rbp+18h]

  m_root = node;
  v5 = this;
  if ( node || (m_root = this->m_root) != 0 )
  {
    v6 = &this->m_nodes.m_data[m_root];
    if ( LODWORD(v6->m_children[0]) )
    {
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::balance(this, maxDelta, v6->m_children[0]);
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::balance(v5, maxDelta, v6->m_children[1]);
      v41 = 0;
      if ( m_root )
      {
        do
        {
          m_data = v5->m_nodes.m_data;
          v8 = 0;
          v9 = &v5->m_nodes.m_data[m_root];
          v10 = v9->m_children[0];
          if ( v10 )
          {
            v11 = 0;
            v12 = v10 << 6;
            m_parent = m_data[v10].m_parent;
            if ( m_parent )
            {
              v14 = m_data[v10].m_parent;
              do
              {
                ++v11;
                v14 = m_data[v14].m_parent;
              }
              while ( v14 );
            }
            if ( *(_DWORD *)((char *)m_data->m_children + v12) )
            {
              v15 = *(unsigned __int64 *)((char *)m_data->m_children + v12);
              while ( v15 )
              {
                v16 = &m_data[v15];
                if ( LODWORD(v16->m_children[0]) )
                {
                  v15 = v16->m_children[0];
                }
                else
                {
                  v17 = v16->m_parent;
                  for ( i = 0; v17; v17 = m_data[v17].m_parent )
                    ++i;
                  v19 = i - v11;
                  if ( v8 > v19 )
                    v19 = v8;
                  v8 = v19;
                  v20 = v16->m_parent;
                  for ( j = v15; v20 != v10; v20 = m_data[v20].m_parent )
                  {
                    if ( m_data[v20].m_children[1] != j )
                      break;
                    j = v20;
                  }
                  if ( v20 )
                    v15 = m_data[v20].m_children[1];
                  else
                    v15 = j;
                  if ( v20 == v10 && v15 == j )
                    v15 = 0i64;
                }
              }
            }
            else
            {
              for ( ; m_parent; m_parent = m_data[m_parent].m_parent )
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
            v26 = m_data[v22].m_parent;
            if ( v26 )
            {
              v27 = m_data[v22].m_parent;
              do
              {
                ++v24;
                v27 = m_data[v27].m_parent;
              }
              while ( v27 );
            }
            if ( *(_DWORD *)((char *)m_data->m_children + v25) )
            {
              v28 = *(unsigned __int64 *)((char *)m_data->m_children + v25);
              while ( v28 )
              {
                v29 = &m_data[v28];
                if ( LODWORD(v29->m_children[0]) )
                {
                  v28 = v29->m_children[0];
                }
                else
                {
                  v30 = v29->m_parent;
                  for ( k = 0; v30; v30 = m_data[v30].m_parent )
                    ++k;
                  v32 = k - v24;
                  if ( v23 > v32 )
                    v32 = v23;
                  v23 = v32;
                  v33 = v29->m_parent;
                  for ( m = v28; v33 != v22; v33 = m_data[v33].m_parent )
                  {
                    if ( m_data[v33].m_children[1] != m )
                      break;
                    m = v33;
                  }
                  if ( v33 )
                    v28 = m_data[v33].m_children[1];
                  else
                    v28 = m;
                  if ( v33 == v22 && v28 == m )
                    v28 = 0i64;
                }
              }
            }
            else
            {
              for ( n = 0; v26; v26 = m_data[v26].m_parent )
                ++n;
              v23 = n - v24;
              if ( v23 < 0 )
                v23 = 0;
            }
          }
          v36 = v8 - v23;
          v37 = abs32(v36);
          if ( v37 <= v41 || v37 <= maxDelta )
            break;
          v5 = this;
          v41 = v37;
          v38 = v36 >= 0
              ? hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rotateRight(this, m_root)
              : hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rotateLeft(this, m_root);
          m_root = v38;
        }
        while ( v38 );
      }
    }
  }
}

// File Line: 1138
// RVA: 0xDA19D0
void __fastcall hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16>::sortBranch<hkpTreeBroadPhaseInternals::MappingUpdater>(
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage16> *this,
        unsigned int branch,
        hkpTreeBroadPhaseInternals::MappingUpdater *mapping,
        int maxDepth)
{
  unsigned __int16 m_root; // bx
  hkcdDynamicTree::Codec32 *i; // rax
  unsigned __int16 v11; // r10
  unsigned __int16 v12; // r11
  __int16 v13; // cx
  __m128i m_min; // xmm2
  hkcdDynamicTree::Codec32 *v15; // rbp
  __m128i m_max; // xmm3
  unsigned __int64 v17; // xmm1_8
  unsigned __int64 v18; // rdx
  int v19; // r8d
  hkpTreeBroadPhase32::Handle *v20; // r8
  int v21; // esi
  unsigned __int64 v22; // xmm0_8
  char v23; // al
  hkVector4f v24; // [rsp+10h] [rbp-58h]
  hkVector4f v25; // [rsp+20h] [rbp-48h]
  unsigned __int16 v26; // [rsp+70h] [rbp+8h]
  __int16 v27; // [rsp+72h] [rbp+Ah]

  m_root = this->m_root;
  if ( m_root )
  {
    for ( i = &this->m_nodes.m_data[m_root]; i->m_aabb.m_max.m_quad.m128_i16[6]; i = &this->m_nodes.m_data[m_root] )
    {
      if ( !maxDepth-- )
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
      if ( v11 < m_root )
      {
        m_min = (__m128i)i->m_aabb.m_min;
        v15 = &this->m_nodes.m_data[v11];
        m_max = (__m128i)v15->m_aabb.m_max;
        v25.m_quad = (__m128)v15->m_aabb.m_min;
        v17 = _mm_srli_si128(m_max, 8).m128i_u64[0];
        v24.m_quad = (__m128)i->m_aabb.m_max;
        v18 = HIWORD(v17);
        if ( WORD2(v17) )
        {
          v19 = m_root | 0x3F000000;
          this->m_nodes.m_data[WORD2(v17)].m_aabb.m_min.m_quad.m128_i32[3] = v19;
          this->m_nodes.m_data[v18].m_aabb.m_min.m_quad.m128_i32[3] = v19;
        }
        else
        {
          v20 = &mapping->m_handles[v18];
          *((_DWORD *)v20 + 2) &= 0xFFE00000;
          *((_DWORD *)v20 + 2) |= m_root;
        }
        v21 = v11 | 0x3F000000;
        v25.m_quad.m128_i32[3] = v21;
        v22 = _mm_srli_si128(m_min, 8).m128i_u64[0];
        if ( WORD2(v22) )
          this->m_nodes.m_data[WORD2(v22)].m_aabb.m_max.m_quad.m128_i16[(this->m_nodes.m_data[WORD2(v22)].m_aabb.m_max.m_quad.m128_i16[7] == m_root)
                                                                      + 6] = v11;
        else
          this->m_root = v11;
        v24.m_quad.m128_i16[6] = m_root;
        v11 = m_root;
        this->m_nodes.m_data[v24.m_quad.m128_u16[7]].m_aabb.m_min.m_quad.m128_i32[3] = v21;
        v26 = m_root;
        i->m_aabb.m_min = (hkVector4f)v25.m_quad;
        i->m_aabb.m_max = (hkVector4f)m_max;
        i = v15;
        v15->m_aabb.m_max = (hkVector4f)v24.m_quad;
        v15->m_aabb.m_min = (hkVector4f)m_min;
      }
      if ( v12 < v11 )
      {
        v26 = v12;
        v27 = v11;
        i->m_aabb.m_max.m_quad.m128_i16[6] = v12;
        i->m_aabb.m_max.m_quad.m128_i16[7] = v11;
      }
      v23 = branch;
      branch >>= 1;
      m_root = *(&v26 + (v23 & 1));
    }
  }
}

