// File Line: 15
// RVA: 0xF4700
char __fastcall UFG::HavokRegionNearestFeatureCallback::edgeTraversed(
        UFG::HavokRegionNearestFeatureCallback *this,
        unsigned int edgeIndex,
        hkaiAgentTraversalInfo *agentInfo)
{
  __int64 v4; // rdx
  __int64 v5; // r9
  signed int v6; // r8d
  __int64 v8; // r11
  __int64 v9; // rdx
  int v10; // eax
  __int64 v11; // rcx
  __int64 v12; // rax
  signed int v13; // r10d
  int *v14; // r8
  __m128 *v15; // rcx
  __int64 v16; // rax
  int v17; // edx
  __m128 *v18; // rax
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __int64 v23; // rax
  __m128 *v24; // rax
  UFG::RegionComponent *m_pRegionComponent; // rcx
  __m128 v26; // xmm2
  float v27; // xmm0_4
  float v28; // xmm1_4
  char result; // al
  float v30; // xmm0_4
  __m128 v31; // [rsp+20h] [rbp-38h] BYREF

  v4 = edgeIndex >> 22;
  v5 = (unsigned int)v4;
  v6 = edgeIndex & 0x3FFFFF;
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
  v14 = (int *)(v12 + 4 * v11);
  v15 = *(__m128 **)(v8 + 48 * v5);
  v16 = *v14;
  v17 = v15[3].m128_i32[2];
  if ( (int)v16 >= v17 )
    v18 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((int)v16 - v17));
  else
    v18 = (__m128 *)(v15[3].m128_u64[0] + 16 * v16);
  v19 = v15[8];
  v20 = v15[7];
  v21 = v15[9];
  v22 = v15[10];
  v31 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 0), v20), _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 85), v19)),
            _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 170), v21)),
          v22);
  v23 = v14[1];
  if ( (int)v23 >= v17 )
    v24 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((int)v23 - v17));
  else
    v24 = (__m128 *)(v15[3].m128_u64[0] + 16 * v23);
  m_pRegionComponent = this->m_pRegionComponent;
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 0), v20), _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 85), v19)),
            _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 170), v21)),
          v22);
  v31.m128_f32[2] = (float)(_mm_shuffle_ps(v26, v26, 170).m128_f32[0] + v31.m128_f32[2]) * 0.5;
  v31.m128_f32[0] = (float)(v26.m128_f32[0] + v31.m128_f32[0]) * 0.5;
  v31.m128_f32[1] = (float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] + v31.m128_f32[1]) * 0.5;
  if ( !UFG::RegionComponent::IsHitPoint(m_pRegionComponent, (UFG::qVector3 *)&v31) )
    return 1;
  v27 = v31.m128_f32[0];
  v28 = v31.m128_f32[1];
  this->m_bPointInRegionFound = 1;
  result = 0;
  this->m_vNearestPointInRegion.x = v27;
  v30 = v31.m128_f32[2];
  this->m_vNearestPointInRegion.y = v28;
  this->m_vNearestPointInRegion.z = v30;
  return result;
}

