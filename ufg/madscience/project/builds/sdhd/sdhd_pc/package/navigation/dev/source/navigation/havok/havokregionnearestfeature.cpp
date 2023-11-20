// File Line: 15
// RVA: 0xF4700
char __fastcall UFG::HavokRegionNearestFeatureCallback::edgeTraversed(UFG::HavokRegionNearestFeatureCallback *this, unsigned int edgeIndex, hkaiAgentTraversalInfo *agentInfo)
{
  unsigned int v3; // er8
  __int64 v4; // rdx
  __int64 v5; // r9
  int v6; // er8
  UFG::HavokRegionNearestFeatureCallback *v7; // rbx
  __int64 v8; // r11
  __int64 v9; // rdx
  int v10; // eax
  signed __int64 v11; // rcx
  __int64 v12; // rax
  int v13; // er10
  signed int *v14; // r8
  __m128 *v15; // rcx
  __int64 v16; // rax
  signed int v17; // edx
  __m128 *v18; // rax
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __int64 v23; // rax
  __m128 *v24; // rax
  UFG::RegionComponent *v25; // rcx
  __m128 v26; // xmm2
  unsigned __int64 v27; // kr00_8
  char result; // al
  float v29; // xmm0_4
  __m128 v30; // [rsp+20h] [rbp-38h]

  v3 = edgeIndex;
  v4 = edgeIndex >> 22;
  v5 = (unsigned int)v4;
  v6 = v3 & 0x3FFFFF;
  v7 = this;
  v8 = *((_QWORD *)UFG::NavManager::ms_pInstance[3].vfptr->LowHealthDefrag + 4);
  v9 = *(_QWORD *)(v8 + 48 * v4);
  v10 = *(_DWORD *)(v9 + 40);
  if ( v6 < v10 )
  {
    if ( *(_DWORD *)(v9 + 216) )
      v13 = *(_DWORD *)(*(_QWORD *)(v9 + 208) + 4i64 * v6);
    else
      v13 = v6;
    if ( v13 == -1 )
    {
      v11 = 5i64 * v6;
      v12 = *(_QWORD *)(v9 + 32);
    }
    else
    {
      v11 = 5i64 * v13;
      v12 = *(_QWORD *)(v9 + 256);
    }
  }
  else
  {
    v11 = 5i64 * (v6 - v10);
    v12 = *(_QWORD *)(v9 + 288);
  }
  v14 = (signed int *)(v12 + 4 * v11);
  v15 = *(__m128 **)(v8 + 48 * v5);
  v16 = *v14;
  v17 = v15[3].m128_i32[2];
  if ( (signed int)v16 >= v17 )
    v18 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((signed int)v16 - v17));
  else
    v18 = (__m128 *)(v15[3].m128_u64[0] + 16 * v16);
  v19 = v15[8];
  v20 = v15[7];
  v21 = v15[9];
  v22 = v15[10];
  v30 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 0), v20), _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 85), v19)),
            _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 170), v21)),
          v22);
  v23 = v14[1];
  if ( (signed int)v23 >= v17 )
    v24 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((signed int)v23 - v17));
  else
    v24 = (__m128 *)(v15[3].m128_u64[0] + 16 * v23);
  v25 = v7->m_pRegionComponent;
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 0), v20), _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 85), v19)),
            _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 170), v21)),
          v22);
  v30.m128_f32[2] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170)) + v30.m128_f32[2]) * 0.5;
  v30.m128_f32[0] = (float)(v26.m128_f32[0] + v30.m128_f32[0]) * 0.5;
  v30.m128_f32[1] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + v30.m128_f32[1]) * 0.5;
  if ( !UFG::RegionComponent::IsHitPoint(v25, (UFG::qVector3 *)&v30) )
    return 1;
  v27 = v30.m128_u64[0];
  v7->m_bPointInRegionFound = 1;
  result = 0;
  LODWORD(v7->m_vNearestPointInRegion.x) = v27;
  v29 = v30.m128_f32[2];
  v7->m_vNearestPointInRegion.y = *((float *)&v27 + 1);
  v7->m_vNearestPointInRegion.z = v29;
  return result;
}

