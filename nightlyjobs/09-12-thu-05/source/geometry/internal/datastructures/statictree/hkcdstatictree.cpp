// File Line: 17
// RVA: 0xC98740
void __fastcall hkcdStaticTree::Codec3Axis::pack(hkAabb *parent, hkAabb *child, hkcdStaticTree::Codec3Axis *nodeOut)
{
  signed __int64 v4; // r12
  __int64 v5; // rdi
  hkcdStaticTree::Codec3Axis *v7; // rbx
  __int64 v8; // r13
  char v9; // si
  char v10; // si
  hkAabb aabbOut; // [rsp+20h] [rbp-48h] BYREF

  v4 = (char *)child - (char *)&aabbOut;
  v5 = 0i64;
  *(_WORD *)nodeOut->m_xyz = 0;
  nodeOut->m_xyz[2] = 0;
  v7 = nodeOut;
  v8 = 3i64;
  do
  {
    if ( (v7->m_xyz[0] & 0xF0u) < 0xF0 )
    {
      while ( 1 )
      {
        v9 = v7->m_xyz[0];
        v7->m_xyz[0] += 16;
        hkcdStaticTree::Codec3Axis::unpack(parent, nodeOut, &aabbOut);
        if ( *(float *)((char *)&aabbOut.m_min.m_quad.m128_f32[v5] + v4) < aabbOut.m_min.m_quad.m128_f32[v5] )
          break;
        if ( (v7->m_xyz[0] & 0xF0u) >= 0xF0 )
          goto LABEL_7;
      }
      v7->m_xyz[0] = v9;
    }
LABEL_7:
    if ( (v7->m_xyz[0] & 0xF) != 15 )
    {
      while ( 1 )
      {
        v10 = v7->m_xyz[0]++;
        hkcdStaticTree::Codec3Axis::unpack(parent, nodeOut, &aabbOut);
        if ( *(float *)((char *)aabbOut.m_max.m_quad.m128_f32 + v4 + v5 * 4) > aabbOut.m_max.m_quad.m128_f32[v5] )
          break;
        if ( (v7->m_xyz[0] & 0xF) == 15 )
          goto LABEL_12;
      }
      v7->m_xyz[0] = v10;
    }
LABEL_12:
    ++v5;
    v7 = (hkcdStaticTree::Codec3Axis *)((char *)v7 + 1);
    --v8;
  }
  while ( v8 );
}

// File Line: 51
// RVA: 0xC98850
void __fastcall hkcdStaticTree::Codec3Axis::unpack(hkAabb *parent, hkcdStaticTree::Codec3Axis *child, hkAabb *aabbOut)
{
  __m128i v3; // xmm3
  __m128 v4; // xmm4
  __m128 v5; // xmm6
  __m128 v6; // xmm2

  v3 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)*(unsigned int *)child->m_xyz, (__m128i)0i64), (__m128i)0i64);
  v4 = _mm_cvtepi32_ps(_mm_and_si128(_mm_load_si128(&hkcdStaticTree::Codec3Axis::v_mask.m_quad), v3));
  v5 = _mm_mul_ps(_mm_sub_ps(parent->m_max.m_quad, parent->m_min.m_quad), (__m128)xmmword_141A71240);
  v6 = _mm_cvtepi32_ps(_mm_srli_epi32(v3, 4u));
  aabbOut->m_min.m_quad = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v6, v6), v5), parent->m_min.m_quad);
  aabbOut->m_max.m_quad = _mm_sub_ps(parent->m_max.m_quad, _mm_mul_ps(_mm_mul_ps(v4, v4), v5));
}

