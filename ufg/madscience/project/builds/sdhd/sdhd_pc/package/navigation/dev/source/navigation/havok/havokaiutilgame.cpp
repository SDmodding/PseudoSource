// File Line: 22
// RVA: 0xF4C00
void __fastcall UFG::HavokAIUtilGame::getClosestPointOnTriangle2d(hkVector4f *p, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *closestPointOut)
{
  __m128 v5; // xmm6
  __m128 v6; // xmm8
  __m128 v7; // xmm12
  __m128 v8; // xmm13
  __m128 v9; // xmm1
  __m128 v10; // xmm14
  __m128 v11; // xmm15
  __m128 v12; // xmm0
  __m128 v13; // xmm11
  __m128 v14; // xmm0
  __m128 v15; // xmm7
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm9
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm6
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm6
  __m128 v30; // xmm10
  __m128 v31; // xmm1
  __m128 v32; // xmm0
  __m128 v33; // xmm7
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm7
  __m128 v39; // xmm1
  __m128 v40; // xmm2

  v5 = p->m_quad;
  v6 = c->m_quad;
  v7 = a->m_quad;
  v8 = b->m_quad;
  v9 = _mm_sub_ps(p->m_quad, a->m_quad);
  v10 = _mm_sub_ps(b->m_quad, a->m_quad);
  v11 = _mm_sub_ps(c->m_quad, a->m_quad);
  v12 = _mm_mul_ps(v10, v9);
  v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0));
  v14 = _mm_mul_ps(v11, v9);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0));
  if ( v13.m128_f32[0] > 0.0 || v15.m128_f32[0] > 0.0 )
  {
    v16 = _mm_sub_ps(v5, v8);
    v17 = v16;
    v18 = _mm_mul_ps(v16, v11);
    v19 = _mm_mul_ps(v17, v10);
    v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0));
    v21 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0));
    if ( v21.m128_f32[0] < 0.0 || v20.m128_f32[0] > v21.m128_f32[0] )
    {
      v22 = _mm_sub_ps(_mm_mul_ps(v20, v13), _mm_mul_ps(v21, v15));
      if ( v22.m128_f32[0] > 0.0 || v13.m128_f32[0] < 0.0 || v21.m128_f32[0] > 0.0 )
      {
        v25 = _mm_sub_ps(v5, v6);
        v26 = _mm_mul_ps(v25, v10);
        v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0));
        v28 = _mm_mul_ps(v11, v25);
        v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0));
        if ( v29.m128_f32[0] < 0.0 || v27.m128_f32[0] > v29.m128_f32[0] )
        {
          v30 = _mm_sub_ps(_mm_mul_ps(v27, v15), _mm_mul_ps(v29, v13));
          if ( v30.m128_f32[0] > 0.0 || v15.m128_f32[0] < 0.0 || v29.m128_f32[0] > 0.0 )
          {
            v33 = _mm_sub_ps(_mm_mul_ps(v29, v21), _mm_mul_ps(v27, v20));
            if ( v33.m128_f32[0] > 0.0
              || (v34 = _mm_sub_ps(v20, v21), v34.m128_f32[0] < 0.0)
              || (v35 = _mm_sub_ps(v27, v29), v35.m128_f32[0] < 0.0) )
            {
              v38 = _mm_add_ps(_mm_add_ps(v33, v30), v22);
              v39 = _mm_rcp_ps(v38);
              v40 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v38)), v39), query.m_quad);
              closestPointOut->m_quad = _mm_add_ps(
                                          _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v40, v30), v10), v7),
                                          _mm_mul_ps(_mm_mul_ps(v40, v22), v11));
            }
            else
            {
              v36 = _mm_add_ps(v35, v34);
              v37 = _mm_rcp_ps(v36);
              closestPointOut->m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps(v6, v8),
                                            _mm_mul_ps(
                                              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v37, v36)), v37),
                                              v34)),
                                          v8);
            }
          }
          else
          {
            v31 = _mm_sub_ps(v15, v29);
            v32 = _mm_rcp_ps(v31);
            closestPointOut->m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_mul_ps(
                                            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v32)), v32),
                                            v15),
                                          v11),
                                        v7);
          }
        }
        else
        {
          *closestPointOut = (hkVector4f)v6;
        }
      }
      else
      {
        v23 = _mm_sub_ps(v13, v21);
        v24 = _mm_rcp_ps(v23);
        closestPointOut->m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v24)), v24), v13),
                                      v10),
                                    v7);
      }
    }
    else
    {
      *closestPointOut = (hkVector4f)v8;
    }
  }
  else
  {
    *closestPointOut = (hkVector4f)v7;
  }
}

// File Line: 98
// RVA: 0xE3660
void __fastcall UFG::HavokAIUtilGame::getClosestPointOnFace2d<hkaiNavMeshInstance>(UFG::HavokAIUtilGame *this, hkaiNavMeshInstance *mesh, hkVector4f *position, __int64 faceIndex, hkVector4f *closestPointOut)
{
  signed int v5; // eax
  hkVector4f *v6; // rbp
  hkVector4f *v7; // r15
  __m128 *v8; // rbx
  signed int *v9; // rsi
  int v10; // edx
  __int64 v11; // rdx
  signed int v12; // ecx
  signed __int64 v13; // rcx
  unsigned __int64 v14; // rax
  int v15; // er8
  signed int *v16; // r8
  signed int v17; // ecx
  __int64 v18; // rax
  __m128 *v19; // rax
  __m128 v20; // xmm1
  int v21; // eax
  float v22; // xmm7_4
  int v23; // edi
  signed __int64 v24; // r14
  float v25; // ecx
  signed __int64 v26; // rcx
  unsigned __int64 v27; // rax
  int v28; // ecx
  signed int *v29; // rdx
  signed int v30; // ecx
  __int64 v31; // rax
  __m128 *v32; // rax
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  __int64 v36; // rax
  __m128 v37; // xmm5
  __m128 v38; // xmm6
  __m128 v39; // xmm2
  __m128 *v40; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm1
  __m128 v43; // xmm1
  float v44; // xmm2_4
  hkVector4f c; // [rsp+30h] [rbp-78h]
  hkVector4f b; // [rsp+40h] [rbp-68h]
  hkVector4f a; // [rsp+50h] [rbp-58h]
  hkVector4f v48; // [rsp+60h] [rbp-48h]

  v5 = *(_DWORD *)&this[24];
  v6 = (hkVector4f *)faceIndex;
  v7 = (hkVector4f *)mesh;
  v8 = (__m128 *)this;
  if ( (signed int)position < v5 )
  {
    if ( *(_DWORD *)&this[232] )
      v10 = *(_DWORD *)(*(_QWORD *)&this[224] + 4i64 * (signed int)position);
    else
      v10 = (signed int)position;
    if ( v10 == -1 )
      v9 = (signed int *)(*(_QWORD *)&this[16] + 16i64 * (signed int)position);
    else
      v9 = (signed int *)(*(_QWORD *)&this[240] + 16i64 * v10);
  }
  else
  {
    v9 = (signed int *)(*(_QWORD *)&this[272] + 16i64 * ((signed int)position - v5));
  }
  v11 = *v9;
  v12 = *(_DWORD *)&this[40];
  if ( (signed int)v11 < v12 )
  {
    if ( v8[13].m128_i32[2] )
      v15 = *(_DWORD *)(v8[13].m128_u64[0] + 4 * v11);
    else
      v15 = *v9;
    if ( v15 == -1 )
    {
      v14 = v8[2].m128_u64[0];
      v13 = 5 * v11;
    }
    else
    {
      v13 = 5i64 * v15;
      v14 = v8[16].m128_u64[0];
    }
  }
  else
  {
    v13 = 5i64 * ((signed int)v11 - v12);
    v14 = v8[18].m128_u64[0];
  }
  v16 = (signed int *)(v14 + 4 * v13);
  v17 = v8[3].m128_i32[2];
  v18 = *v16;
  if ( (signed int)v18 >= v17 )
    v19 = (__m128 *)(v8[19].m128_u64[0] + 16i64 * ((signed int)v18 - v17));
  else
    v19 = (__m128 *)(v8[3].m128_u64[0] + 16 * v18);
  v20 = *v19;
  v21 = *((signed __int16 *)v9 + 4);
  v22 = *(float *)&_xmm;
  v23 = v11 + 1;
  a.m_quad = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v8[7]),
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v8[8])),
                 _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v8[9])),
               v8[10]);
  if ( (signed int)v11 + 1 < v21 + (signed int)v11 - 1 )
  {
    v24 = 4i64 * v23;
    do
    {
      v25 = v8[2].m128_f32[2];
      if ( v23 < SLODWORD(v25) )
      {
        if ( v8[13].m128_i32[2] )
          v28 = *(_DWORD *)(v24 + v8[13].m128_u64[0]);
        else
          v28 = v23;
        if ( v28 == -1 )
        {
          v26 = 5i64 * v23;
          v27 = v8[2].m128_u64[0];
        }
        else
        {
          v26 = 5i64 * v28;
          v27 = v8[16].m128_u64[0];
        }
      }
      else
      {
        v26 = 5i64 * (v23 - LODWORD(v25));
        v27 = v8[18].m128_u64[0];
      }
      v29 = (signed int *)(v27 + 4 * v26);
      v30 = v8[3].m128_i32[2];
      v31 = *v29;
      if ( (signed int)v31 >= v30 )
        v32 = (__m128 *)(v8[19].m128_u64[0] + 16i64 * ((signed int)v31 - v30));
      else
        v32 = (__m128 *)(v8[3].m128_u64[0] + 16 * v31);
      v33 = *v32;
      v34 = v8[8];
      v35 = v8[7];
      v36 = v29[1];
      v37 = v8[9];
      v38 = v8[10];
      v39 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v35), _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v34)),
                _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v37)),
              v38);
      if ( (signed int)v36 >= v30 )
        v40 = (__m128 *)(v8[19].m128_u64[0] + 16i64 * ((signed int)v36 - v30));
      else
        v40 = (__m128 *)(v8[3].m128_u64[0] + 16 * v36);
      v41 = *v40;
      b.m_quad = v39;
      c.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v35),
                       _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v34)),
                     _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v37)),
                   v38);
      UFG::HavokAIUtilGame::getClosestPointOnTriangle2d(v7, &a, &b, &c, &v48);
      v42 = _mm_sub_ps(v7->m_quad, v48.m_quad);
      v43 = _mm_mul_ps(v42, v42);
      v44 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 170));
      if ( v44 < v22 )
      {
        v22 = v44;
        *v6 = (hkVector4f)v48.m_quad;
      }
      ++v23;
      v24 += 4i64;
    }
    while ( v23 < *v9 + *((signed __int16 *)v9 + 4) - 1 );
  }
}

// File Line: 200
// RVA: 0xF5160
void __fastcall UFG::HavokAIUtilGame::getFaceNormal(unsigned int faceKey, hkVector4f *normalOut)
{
  hkVector4f *v2; // rsi
  unsigned int v3; // ebx
  hkaiNavMeshQueryMediator *v4; // rax
  void *(__fastcall *v5)(hkBaseObject *, unsigned int); // rcx
  hkaiNavMeshInstance *v6; // rdi
  hkaiNavMesh::Face *v7; // rbx
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm5
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  hkVector4f edgeB; // [rsp+20h] [rbp-38h]
  hkVector4f edgeA; // [rsp+30h] [rbp-28h]
  hkVector4f v17; // [rsp+40h] [rbp-18h]

  v2 = normalOut;
  v3 = faceKey;
  *normalOut = (hkVector4f)_xmm;
  if ( faceKey != -1 )
  {
    if ( UFG::NavManager::ms_pInstance )
    {
      v4 = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
      if ( v4 )
      {
        v5 = v4[1].vfptr[2].__vecDelDtor;
        v6 = (hkaiNavMeshInstance *)*((_QWORD *)v5 + 6 * (v3 >> 22));
        if ( v6 )
        {
          v7 = hkaiNavMeshInstance::getFace(*((hkaiNavMeshInstance **)v5 + 6 * (v3 >> 22)), v3 & 0x3FFFFF);
          hkaiNavMeshInstance::getEdgePoints(v6, v7->m_startEdgeIndex, &edgeA, &edgeB);
          hkaiNavMeshInstance::getEdgePoints(v6, v7->m_startEdgeIndex + 1, &edgeB, &v17);
          v8 = _mm_sub_ps(edgeB.m_quad, v17.m_quad);
          v9 = _mm_sub_ps(edgeB.m_quad, edgeA.m_quad);
          v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
          v11 = _mm_shuffle_ps(v10, v10, 201);
          v12 = _mm_mul_ps(v11, v11);
          v13 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                  _mm_shuffle_ps(v12, v12, 170));
          v14 = _mm_rsqrt_ps(v13);
          v2->m_quad = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v13, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                             _mm_mul_ps(*(__m128 *)_xmm, v14))),
                         v11);
        }
      }
    }
  }
}

// File Line: 241
// RVA: 0xEA330
int UFG::HavokAIUtilGame::FindClosestMeshPosition2d(...)
{
  float v5; // xmm9_4
  __m128 v6; // xmm6
  hkVector4f *v7; // r13
  signed __int64 v8; // rdi
  char v9; // dl
  __int64 v10; // rax
  __int64 v11; // rsi
  char v12; // cl
  hkaiNavMeshQueryMediator *v13; // rcx
  unsigned int v14; // er14
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  float v18; // xmm6_4
  hkVector4f v19; // xmm7
  unsigned int v20; // er12
  int v21; // ebx
  __int64 v22; // rdi
  unsigned int v23; // ebp
  __int64 v24; // rax
  __int64 v25; // r15
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  float v28; // xmm1_4
  char v29; // cl
  __int64 result; // rax
  hkVector4f *closestPointOut; // [rsp+20h] [rbp-E8h]
  int v32; // [rsp+28h] [rbp-E0h]
  int v33; // [rsp+2Ch] [rbp-DCh]
  int faceIndex[4]; // [rsp+30h] [rbp-D8h]
  __int64 v35; // [rsp+40h] [rbp-C8h]
  __int64 v36; // [rsp+48h] [rbp-C0h]
  int v37; // [rsp+50h] [rbp-B8h]
  __int64 v38; // [rsp+58h] [rbp-B0h]
  __int128 v39; // [rsp+60h] [rbp-A8h]
  __int64 v40; // [rsp+70h] [rbp-98h]
  __m128 v41; // [rsp+80h] [rbp-88h]
  __m128 v42; // [rsp+90h] [rbp-78h]
  hkVector4f *v43; // [rsp+128h] [rbp+20h]

  v43 = hkvClosestPointOut;
  v36 = -2i64;
  v5 = *(float *)&fToleranceZ;
  v6 = (__m128)fToleranceXY;
  v7 = hkvPosition;
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v35 = v8;
  v9 = ++*(_BYTE *)(v8 + 80);
  v10 = v9;
  *(_DWORD *)(v8 + 4 * v10) = 1;
  *(_QWORD *)(v8 + 8 * v10 + 16) = "FindClosestMeshPosition2d";
  v11 = 0i64;
  *(_QWORD *)(v8 + 8 * v10 + 48) = 0i64;
  v12 = *(_BYTE *)(v8 + 81);
  if ( v9 > v12 )
    v12 = v9;
  *(_BYTE *)(v8 + 81) = v12;
  v13 = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  *(_QWORD *)faceIndex = v13;
  v14 = -1;
  *meshUidOut = -1;
  if ( v13 )
  {
    closestPointOut = 0i64;
    v32 = 0;
    v33 = 2147483648;
    v15 = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)fToleranceXY, (__m128)fToleranceZ),
            _mm_unpacklo_ps((__m128)fToleranceXY, (__m128)0i64));
    v16 = _mm_sub_ps(v7->m_quad, v15);
    v17 = _mm_add_ps(v7->m_quad, v15);
    v37 = 0;
    v38 = 0i64;
    _mm_store_si128((__m128i *)&v39, (__m128i)0i64);
    v40 = 0i64;
    v41 = v16;
    v42 = v17;
    ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkVector4f **))v13->vfptr[3].__first_virtual_table_function__)(
      v13,
      &v37,
      &closestPointOut);
    v6.m128_f32[0] = v6.m128_f32[0] * v6.m128_f32[0];
    LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(v6, v6, 0);
    v19.m_quad = 0i64;
    v20 = -1;
    v21 = 0;
    if ( v32 > 0 )
    {
      v22 = *(_QWORD *)faceIndex;
      do
      {
        v23 = *(unsigned int *)((char *)closestPointOut->m_quad.m128_u32 + v11);
        v24 = *(_QWORD *)(*(_QWORD *)(v22 + 16) + 32i64);
        v25 = *(_QWORD *)(v24 + 48i64 * (*(unsigned int *)((char *)closestPointOut->m_quad.m128_i32 + v11) >> 22));
        UFG::HavokAIUtilGame::getClosestPointOnFace2d<hkaiNavMeshInstance>(
          *(UFG::HavokAIUtilGame **)(v24
                                   + 48i64 * (*(unsigned int *)((char *)closestPointOut->m_quad.m128_i32 + v11) >> 22)),
          (hkaiNavMeshInstance *)v7,
          (hkVector4f *)(*(int *)((_BYTE *)closestPointOut->m_quad.m128_i32 + v11) & 0x3FFFFF),
          (__int64)faceIndex,
          closestPointOut);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v7->m_quad.m128_f32[2] - *(float *)&faceIndex[2]) & _xmm) < v5 )
        {
          v26 = _mm_sub_ps(v7->m_quad, *(__m128 *)faceIndex);
          v27 = _mm_mul_ps(v26, v26);
          v28 = COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 0));
          if ( v28 < v18 )
          {
            v18 = v28;
            v14 = v23;
            v19.m_quad = *(__m128 *)faceIndex;
            v20 = *(_DWORD *)(v25 + 468);
          }
        }
        ++v21;
        v11 += 4i64;
      }
      while ( v21 < v32 );
      v8 = v35;
      LODWORD(v11) = 0;
    }
    *v43 = (hkVector4f)v19.m_quad;
    *meshUidOut = v20;
    v32 = v11;
    if ( v33 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        closestPointOut,
        4 * v33);
    closestPointOut = 0i64;
    v33 = 2147483648;
  }
  v29 = *(_BYTE *)(v8 + 80);
  result = v14;
  if ( v29 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v29 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  return result;
}

// File Line: 313
// RVA: 0xF40A0
_BOOL8 __usercall UFG::HavokAIUtilGame::_isPointOnFaceAndProject@<rax>(hkaiNavMeshInstance *meshInstance@<rcx>, int faceIndex@<edx>, hkVector4f *point@<r8>, float edgeTolerance@<xmm3>, __m128 a5@<xmm1>, float coherencyTolerance, hkVector4f *projectionOut)
{
  hkVector4f *v7; // rdi
  unsigned int v8; // esi
  hkaiNavMeshInstance *v9; // rbp
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  hkVector4f *tolerance; // [rsp+20h] [rbp-38h]
  hkSimdFloat32 v14; // [rsp+30h] [rbp-28h]
  hkVector4f faceNormal; // [rsp+40h] [rbp-18h]

  a5.m128_f32[0] = edgeTolerance;
  v7 = point;
  faceNormal.m_quad = _xmm;
  v8 = faceIndex;
  v9 = meshInstance;
  v14.m_real = _mm_shuffle_ps(a5, a5, 0);
  if ( !hkaiNavMeshUtils::isPointOnFace(meshInstance, faceIndex, &faceNormal, point, &v14) )
    return 0i64;
  UFG::HavokAIUtilGame::getClosestPointOnFace2d<hkaiNavMeshInstance>(
    (UFG::HavokAIUtilGame *)v9,
    (hkaiNavMeshInstance *)v7,
    (hkVector4f *)v8,
    (__int64)projectionOut,
    tolerance);
  v10 = _mm_sub_ps(projectionOut->m_quad, v7->m_quad);
  v11 = _mm_mul_ps(v10, v10);
  return (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0))) <= (float)(coherencyTolerance * coherencyTolerance);
}

// File Line: 335
// RVA: 0xEF500
char __fastcall UFG::HavokAIUtilGame::IsFaceKeyValid(hkaiDynamicNavMeshQueryMediator *pQueryMediator, unsigned int key, unsigned int meshUid)
{
  unsigned int v3; // eax
  unsigned int v4; // er9
  hkaiStreamingCollection *v5; // rdx
  __int64 v6; // rax
  hkaiNavMeshInstance *v7; // rdx
  int v8; // er9

  v3 = key;
  v4 = key;
  v5 = pQueryMediator->m_collection.m_pntr;
  v6 = v3 >> 22;
  if ( (signed int)v6 >= v5->m_instances.m_size )
    return 0;
  v7 = v5->m_instances.m_data[v6].m_instancePtr;
  if ( !v7 )
    return 0;
  if ( v7->m_sectionUid != meshUid )
    return 0;
  v8 = v4 & 0x3FFFFF;
  if ( v8 >= v7->m_numOriginalFaces + v7->m_ownedFaces.m_size )
    return 0;
  if ( v7->m_faceFlags.m_size )
    return ~v7->m_faceFlags.m_data[v8].m_storage & 1;
  return 1;
}

// File Line: 359
// RVA: 0xEA5E0
unsigned int __fastcall UFG::HavokAIUtilGame::FindClosestMeshPosition2dCoherent(hkVector4f *hkvPoint, hkVector4f *hkvPreviousPoint, unsigned int previousFaceKey, unsigned int previousMeshUid, float fToleranceXY, float fToleranceZ, hkVector4f *closestPointOut, unsigned int *meshUidOut)
{
  hkVector4f *v8; // rbp
  unsigned int v9; // er12
  signed __int64 v10; // r14
  unsigned int v11; // ebx
  char v12; // r10
  hkVector4f *v13; // r15
  __int64 v14; // rax
  char v15; // cl
  UFG::NavManager *v16; // rax
  hkaiDynamicNavMeshQueryMediator *v17; // rdi
  hkaiNavMeshInstance *v18; // rdi
  hkJobType v19; // edx
  unsigned int result; // eax
  hkaiNavMesh::Face *v21; // r13
  signed __int64 v22; // rbx
  __m128 v23; // xmm0
  __m128 v24; // xmm7
  __m128 v25; // xmm7
  __m128 v26; // xmm1
  __m128 v27; // xmm7
  signed __int64 v28; // r15
  signed int v29; // ecx
  signed __int64 v30; // rcx
  hkaiNavMesh::Edge *v31; // rax
  int v32; // ecx
  signed __int64 v33; // rsi
  __m128 v34; // xmm1
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  unsigned int v40; // esi
  hkaiNavMeshInstance *v41; // rcx
  hkJobType v42; // edx
  char v43; // cl
  char v44; // al
  hkVector4f projectionOut; // [rsp+30h] [rbp-B8h]
  hkVector4f edgeA; // [rsp+40h] [rbp-A8h]
  hkVector4f edgeB; // [rsp+50h] [rbp-98h]
  hkaiDynamicNavMeshQueryMediator *v48; // [rsp+F0h] [rbp+8h]

  v8 = hkvPoint;
  v9 = previousMeshUid;
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = previousFaceKey;
  v12 = ++*(_BYTE *)(v10 + 80);
  v13 = hkvPreviousPoint;
  v14 = v12;
  *(_DWORD *)(v10 + 4 * v14) = 1;
  *(_QWORD *)(v10 + 8 * v14 + 16) = "FindClosestMeshPosition2dCoherent";
  *(_QWORD *)(v10 + 8 * v14 + 48) = 0i64;
  v15 = *(_BYTE *)(v10 + 81);
  v16 = UFG::NavManager::ms_pInstance;
  if ( v12 > v15 )
    v15 = v12;
  *(_BYTE *)(v10 + 81) = v15;
  v17 = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)v16[3].vfptr);
  v48 = v17;
  projectionOut.m_quad = v8->m_quad;
  *meshUidOut = v9;
  if ( v17 )
  {
    if ( v11 == -1 || v9 == -1 || !UFG::HavokAIUtilGame::IsFaceKeyValid(v17, v11, v9) )
      goto LABEL_30;
    v18 = v17->m_collection.m_pntr->m_instances.m_data[v11 >> 22].m_instancePtr;
    if ( UFG::HavokAIUtilGame::_isPointOnFaceAndProject(v18, v11 & 0x3FFFFF, v8, 0.001, 0.1, &projectionOut)
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(projectionOut.m_quad.m128_f32[2] - v8->m_quad.m128_f32[2]) & _xmm) <= fToleranceZ )
    {
      *closestPointOut = (hkVector4f)projectionOut.m_quad;
      *meshUidOut = v9;
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v19);
      return v11;
    }
    v21 = hkaiNavMeshInstance::getFace(v18, v11 & 0x3FFFFF);
    v22 = v21->m_startEdgeIndex;
    v23 = _mm_sub_ps(v8->m_quad, v13->m_quad);
    v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), _xmm), _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 201), v23));
    v25 = _mm_shuffle_ps(v24, v24, 201);
    v26 = _mm_mul_ps(v13->m_quad, v25);
    v27 = _mm_shuffle_ps(
            v25,
            _mm_unpackhi_ps(
              v25,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                  _mm_shuffle_ps(v26, v26, 170)))),
            196);
    if ( (signed int)v22 < (signed int)v22 + v21->m_numEdges )
    {
      v28 = v22;
      while ( 1 )
      {
        v29 = v18->m_numOriginalEdges;
        if ( (signed int)v22 < v29 )
        {
          v32 = v18->m_edgeMap.m_size ? v18->m_edgeMap.m_data[v28] : (_DWORD)v22;
          if ( v32 == -1 )
          {
            v30 = (signed int)v22;
            v31 = v18->m_originalEdges;
          }
          else
          {
            v30 = v32;
            v31 = v18->m_instancedEdges.m_data;
          }
        }
        else
        {
          v30 = (signed int)v22 - v29;
          v31 = v18->m_ownedEdges.m_data;
        }
        v33 = (signed __int64)&v31[v30];
        if ( v31[v30].m_oppositeEdge != -1 && !(*(_BYTE *)(v33 + 16) & 0x20) )
        {
          hkaiNavMeshInstance::getEdgePoints(v18, v22, &edgeA, &edgeB);
          v34 = _mm_mul_ps(edgeA.m_quad, v27);
          v35 = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, v27), 196);
          v36 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 78), v35);
          v37 = _mm_mul_ps(edgeB.m_quad, v27);
          v38 = _mm_shuffle_ps(v37, _mm_unpackhi_ps(v37, v27), 196);
          v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 78), v38);
          if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 177)) + v36.m128_f32[0]) <= 0.0
            && (float)(COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 177)) + v39.m128_f32[0]) >= 0.0 )
          {
            v40 = *(_DWORD *)(v33 + 12);
            v41 = v48->m_collection.m_pntr->m_instances.m_data[v40 >> 22].m_instancePtr;
            if ( v41 )
            {
              if ( v41->m_sectionUid == v9
                && UFG::HavokAIUtilGame::_isPointOnFaceAndProject(v41, v40 & 0x3FFFFF, v8, 0.001, 0.1, &projectionOut)
                && COERCE_FLOAT(COERCE_UNSIGNED_INT(projectionOut.m_quad.m128_f32[2] - v8->m_quad.m128_f32[2]) & _xmm) <= fToleranceZ )
              {
                break;
              }
            }
          }
        }
        LODWORD(v22) = v22 + 1;
        ++v28;
        if ( (signed int)v22 >= v21->m_startEdgeIndex + v21->m_numEdges )
          goto LABEL_30;
      }
      *closestPointOut = (hkVector4f)projectionOut.m_quad;
      *meshUidOut = v9;
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v42);
      result = v40;
    }
    else
    {
LABEL_30:
      result = UFG::HavokAIUtilGame::FindClosestMeshPosition2d(
                 v8,
                 fToleranceXY,
                 fToleranceZ,
                 closestPointOut,
                 meshUidOut);
      v43 = *(_BYTE *)(v10 + 80);
      if ( v43 > 0 )
      {
        *(_BYTE *)(v10 + 80) = v43 - 1;
      }
      else
      {
        *(_BYTE *)(v10 + 80) = 0;
        *(_DWORD *)v10 = 3;
        *(_QWORD *)(v10 + 16) = 0i64;
        *(_QWORD *)(v10 + 48) = 0i64;
      }
    }
  }
  else
  {
    v44 = *(_BYTE *)(v10 + 80);
    if ( v44 > 0 )
    {
      *(_BYTE *)(v10 + 80) = v44 - 1;
      result = -1;
    }
    else
    {
      *(_BYTE *)(v10 + 80) = 0;
      result = -1;
      *(_DWORD *)v10 = 3;
      *(_QWORD *)(v10 + 16) = 0i64;
      *(_QWORD *)(v10 + 48) = 0i64;
    }
  }
  return result;
}

// File Line: 470
// RVA: 0xEABF0
int UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(...)
{
  __m128 v3; // xmm13
  hkVector4f *v4; // r12
  hkVector4f *v5; // rbx
  signed __int64 v6; // rsi
  char v7; // r8
  __int64 v8; // rax
  char v9; // cl
  UFG::NavManager *v10; // rdi
  hkaiNavMeshQueryMediator *v11; // rax
  float v12; // xmm14_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  hkaiStreamingCollection::InstanceInfo *v16; // rax
  float v17; // xmm8_4
  int v18; // er14
  __int64 v19; // r15
  float v20; // xmm11_4
  float v21; // xmm12_4
  float v22; // xmm9_4
  float v23; // xmm10_4
  __m128 v24; // xmm7
  float v25; // xmm6_4
  int v26; // ebx
  int v27; // ebx
  hkaiNavMeshInstance *v28; // rdx
  int v29; // eax
  hkaiNavMesh::Face *v30; // rbx
  int v31; // er8
  signed int v32; // edi
  int v33; // er8
  int v34; // eax
  signed __int64 v35; // rcx
  hkaiNavMesh::Edge *v36; // rax
  int v37; // er9
  hkaiNavMesh::Edge *v38; // r8
  __int64 v39; // rax
  signed int v40; // ecx
  __m128 *v41; // rax
  __m128 v42; // xmm3
  __int64 v43; // rax
  __m128 *v44; // rax
  __m128 v45; // xmm0
  __m128 v46; // xmm3
  float v47; // xmm5_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  float v51; // xmm5_4
  float v52; // xmm2_4
  bool v53; // al
  float v54; // xmm1_4
  __m128 v55; // xmm4
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm5_4
  char v59; // al
  char v61; // al
  UFG::qVector2 P; // [rsp+20h] [rbp-E0h]
  char *v63; // [rsp+28h] [rbp-D8h]
  int v64; // [rsp+30h] [rbp-D0h]
  int v65; // [rsp+34h] [rbp-CCh]
  UFG::qVector2 lA0; // [rsp+38h] [rbp-C8h]
  UFG::qVector2 lA1; // [rsp+40h] [rbp-C0h]
  unsigned int v68; // [rsp+48h] [rbp-B8h]
  UFG::qVector2 closest_point; // [rsp+50h] [rbp-B0h]
  hkaiGeneralAccessor v70; // [rsp+58h] [rbp-A8h]
  __int64 v71; // [rsp+70h] [rbp-90h]
  int v72; // [rsp+80h] [rbp-80h]
  __int64 v73; // [rsp+88h] [rbp-78h]
  __int128 v74; // [rsp+90h] [rbp-70h]
  __int64 v75; // [rsp+A0h] [rbp-60h]
  __m128 v76; // [rsp+B0h] [rbp-50h]
  __m128 v77; // [rsp+C0h] [rbp-40h]
  float v78; // [rsp+1B4h] [rbp+B4h]
  float v79; // [rsp+1B8h] [rbp+B8h]
  float v80; // [rsp+1C8h] [rbp+C8h]

  v71 = -2i64;
  v3 = (__m128)fRadius;
  v4 = hkvNewPosition;
  v5 = hkvPosition;
  v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v7 = ++*(_BYTE *)(v6 + 80);
  v8 = v7;
  *(_DWORD *)(v6 + 4 * v8) = 1;
  *(_QWORD *)(v6 + 8 * v8 + 16) = "FindMeshPositionAwayFromWall";
  *(_QWORD *)(v6 + 8 * v8 + 48) = 0i64;
  v9 = *(_BYTE *)(v6 + 81);
  if ( v7 > v9 )
    v9 = v7;
  *(_BYTE *)(v6 + 81) = v9;
  v10 = UFG::NavManager::ms_pInstance;
  v11 = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  *v4 = (hkVector4f)v5->m_quad;
  if ( !v11 )
    goto LABEL_60;
  v63 = 0i64;
  v64 = 0;
  v65 = 2147483648;
  v12 = 0.0;
  v13 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)fRadius, (__m128)(unsigned int)FLOAT_1_0),
          _mm_unpacklo_ps((__m128)fRadius, (__m128)0i64));
  v14 = _mm_sub_ps(v5->m_quad, v13);
  v15 = _mm_add_ps(v13, v5->m_quad);
  v72 = 0;
  v73 = 0i64;
  _mm_store_si128((__m128i *)&v74, (__m128i)0i64);
  v75 = 0i64;
  v76 = v14;
  v77 = v15;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, char **))v11->vfptr[3].__first_virtual_table_function__)(
    v11,
    &v72,
    &v63);
  v16 = (hkaiStreamingCollection::InstanceInfo *)*((_QWORD *)v10[3].vfptr->LowHealthDefrag + 4);
  v70.m_currentSection = -1;
  v70.m_sectionInfo = v16;
  v70.m_accessor = 0i64;
  v80 = v5->m_quad.m128_f32[0];
  v79 = v5->m_quad.m128_f32[1];
  v68 = v5->m_quad.m128_u32[2];
  P.x = v80;
  P.y = v79;
  v17 = *(float *)&fRadius * *(float *)&fRadius;
  v18 = 0;
  if ( v64 <= 0 )
    goto LABEL_66;
  v19 = 0i64;
  v20 = v78;
  v21 = *(float *)&fRadius * *(float *)&fRadius;
  v22 = v78;
  v23 = *(float *)&fRadius * *(float *)&fRadius;
  v24 = (__m128)LODWORD(v78);
  v25 = *(float *)&fRadius * *(float *)&fRadius;
  do
  {
    v26 = *(_DWORD *)&v63[v19];
    hkaiGeneralAccessor::setSection(&v70, *(_DWORD *)&v63[v19] >> 22);
    v27 = v26 & 0x3FFFFF;
    v28 = v70.m_accessor;
    v29 = v70.m_accessor->m_numOriginalFaces;
    if ( v27 < v29 )
    {
      if ( v70.m_accessor->m_faceMap.m_size )
        v31 = v70.m_accessor->m_faceMap.m_data[v27];
      else
        v31 = v27;
      if ( v31 == -1 )
        v30 = &v70.m_accessor->m_originalFaces[v27];
      else
        v30 = &v70.m_accessor->m_instancedFaces.m_data[v31];
    }
    else
    {
      v30 = &v70.m_accessor->m_ownedFaces.m_data[v27 - v29];
    }
    v32 = 0;
    if ( v30->m_numEdges > 0 )
    {
      do
      {
        v33 = v32 + v30->m_startEdgeIndex;
        v34 = v28->m_numOriginalEdges;
        if ( v33 < v34 )
        {
          if ( v28->m_edgeMap.m_size )
            v37 = v28->m_edgeMap.m_data[v33];
          else
            v37 = v32 + v30->m_startEdgeIndex;
          if ( v37 == -1 )
          {
            v35 = v33;
            v36 = v28->m_originalEdges;
          }
          else
          {
            v35 = v37;
            v36 = v28->m_instancedEdges.m_data;
          }
        }
        else
        {
          v35 = v33 - v34;
          v36 = v28->m_ownedEdges.m_data;
        }
        v38 = &v36[v35];
        if ( v38->m_oppositeEdge == -1 )
        {
          v39 = v38->m_a;
          v40 = v28->m_numOriginalVertices;
          v41 = (__m128 *)((signed int)v39 >= v40 ? &v28->m_ownedVertices.m_data[(signed int)v39 - v40] : &v28->m_originalVertices[v39]);
          v42 = _mm_add_ps(
                  v28->m_referenceFrame.m_transform.m_translation.m_quad,
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(*v41, *v41, 85),
                        v28->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(
                        _mm_shuffle_ps(*v41, *v41, 0),
                        v28->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(*v41, *v41, 170),
                      v28->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)));
          v43 = v38->m_b;
          v44 = (__m128 *)((signed int)v43 >= v40 ? &v28->m_ownedVertices.m_data[(signed int)v43 - v40] : &v28->m_originalVertices[v43]);
          v45 = _mm_add_ps(
                  v28->m_referenceFrame.m_transform.m_translation.m_quad,
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(*v44, *v44, 85),
                        v28->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(
                        _mm_shuffle_ps(*v44, *v44, 0),
                        v28->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(*v44, *v44, 170),
                      v28->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)));
          LODWORD(lA0.x) = v42.m128_i32[0];
          LODWORD(lA0.y) = (unsigned __int128)_mm_shuffle_ps(v42, v42, 85);
          LODWORD(lA1.x) = v45.m128_i32[0];
          LODWORD(lA1.y) = (unsigned __int128)_mm_shuffle_ps(v45, v45, 85);
          UFG::qGetClosestPointOnSegment(&closest_point, &lA0, &lA1, &P);
          v28 = v70.m_accessor;
          if ( (float)((float)((float)(P.x - closest_point.x) * (float)(P.x - closest_point.x))
                     + (float)((float)(P.y - closest_point.y) * (float)(P.y - closest_point.y))) < v17 )
          {
            v17 = (float)((float)(P.x - closest_point.x) * (float)(P.x - closest_point.x))
                + (float)((float)(P.y - closest_point.y) * (float)(P.y - closest_point.y));
            v21 = closest_point.x;
            v20 = closest_point.y;
            v23 = lA0.x;
            v22 = lA0.y;
            v25 = lA1.x;
            v24 = (__m128)LODWORD(lA1.y);
          }
        }
        ++v32;
      }
      while ( v32 < v30->m_numEdges );
    }
    ++v18;
    v19 += 4i64;
  }
  while ( v18 < v64 );
  if ( v17 >= (float)(*(float *)&fRadius * *(float *)&fRadius) )
  {
LABEL_66:
    v64 = 0;
    if ( v65 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v63,
        4 * v65);
    v63 = 0i64;
    v65 = 2147483648;
LABEL_60:
    v61 = *(_BYTE *)(v6 + 80);
    if ( v61 > 0 )
    {
      *(_BYTE *)(v6 + 80) = v61 - 1;
    }
    else
    {
      *(_BYTE *)(v6 + 80) = 0;
      *(_DWORD *)v6 = 3;
      *(_QWORD *)(v6 + 16) = 0i64;
      *(_QWORD *)(v6 + 48) = 0i64;
    }
    return 0;
  }
  v46 = v24;
  v46.m128_f32[0] = v24.m128_f32[0] - v22;
  v47 = v25 - v23;
  v48 = (float)(v47 * v47) + (float)(v46.m128_f32[0] * v46.m128_f32[0]);
  if ( v48 == 0.0 )
    v49 = 0.0;
  else
    v49 = 1.0 / fsqrt(v48);
  v50 = v46.m128_f32[0] * v49;
  v51 = v47 * v49;
  v52 = fsqrt(v17);
  v53 = (float)((float)((float)(v23 - v21) * (float)(v23 - v21)) + (float)((float)(v22 - v20) * (float)(v22 - v20))) < 0.0099999998
     || (float)((float)((float)(v25 - v21) * (float)(v25 - v21))
              + (float)((float)(v24.m128_f32[0] - v20) * (float)(v24.m128_f32[0] - v20))) < 0.0099999998;
  if ( v52 <= 0.001 )
  {
    v55 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    v56 = (float)(v51 * UFG::qVector3::msDirUp.y) - (float)(v50 * UFG::qVector3::msDirUp.x);
    v55.m128_f32[0] = (float)(UFG::qVector3::msDirUp.x * 0.0) - (float)(v51 * UFG::qVector3::msDirUp.z);
    v57 = (float)(v50 * UFG::qVector3::msDirUp.z) - (float)(UFG::qVector3::msDirUp.y * 0.0);
    v58 = (float)((float)(v57 * v57) + (float)(v55.m128_f32[0] * v55.m128_f32[0])) + (float)(v56 * v56);
    if ( v58 != 0.0 )
      v12 = 1.0 / fsqrt(v58);
    v46.m128_f32[0] = v57 * v12;
    v3.m128_f32[0] = COERCE_FLOAT(v3.m128_i32[0] ^ _xmm[0]) - 0.050000001;
    v55.m128_f32[0] = (float)(v55.m128_f32[0] * v12) * v3.m128_f32[0];
  }
  else
  {
    if ( (float)((float)(v51 * (float)(P.y - v22)) - (float)((float)(P.x - v23) * v50)) > 0.0 || v53 )
      v54 = *(float *)&FLOAT_1_0;
    else
      v54 = FLOAT_N1_0;
    v46 = (__m128)LODWORD(P.x);
    v46.m128_f32[0] = P.x - v21;
    v3.m128_f32[0] = (float)((float)((float)(v3.m128_f32[0] + 0.050000001) - (float)(v52 * v54)) * v54) / v52;
    v55 = v3;
    v55.m128_f32[0] = v3.m128_f32[0] * (float)(P.y - v20);
  }
  v55.m128_f32[0] = v55.m128_f32[0] + v79;
  v46.m128_f32[0] = (float)(v46.m128_f32[0] * v3.m128_f32[0]) + v80;
  v4->m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v46, (__m128)v68), _mm_unpacklo_ps(v55, (__m128)(unsigned int)FLOAT_1_0));
  v59 = *(_BYTE *)(v6 + 80);
  if ( v59 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v59 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v64 = 0;
  if ( v65 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v63,
      4 * v65);
  v63 = 0i64;
  v65 = 2147483648;
  return 1;
}

// File Line: 640
// RVA: 0xEF7E0
bool __fastcall UFG::HavokAIUtilGame::IsValidKey(unsigned int key, unsigned int meshUid)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  hkaiDynamicNavMeshQueryMediator *v4; // rax

  v2 = meshUid;
  v3 = key;
  if ( key == -1 )
  {
    LOBYTE(v4) = 1;
  }
  else
  {
    v4 = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
    if ( v4 )
      LOBYTE(v4) = UFG::HavokAIUtilGame::IsFaceKeyValid(v4, v3, v2);
  }
  return (char)v4;
}

