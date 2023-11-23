// File Line: 22
// RVA: 0xF4C00
void __fastcall UFG::HavokAIUtilGame::getClosestPointOnTriangle2d(
        hkVector4f *p,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkVector4f *closestPointOut)
{
  __m128 m_quad; // xmm6
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
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm9
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm6
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  __m128 v28; // xmm6
  __m128 v29; // xmm10
  __m128 v30; // xmm1
  __m128 v31; // xmm0
  __m128 v32; // xmm7
  __m128 v33; // xmm4
  __m128 v34; // xmm3
  __m128 v35; // xmm3
  __m128 v36; // xmm1
  __m128 v37; // xmm7
  __m128 v38; // xmm1
  __m128 v39; // xmm0

  m_quad = p->m_quad;
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
    v16 = _mm_sub_ps(m_quad, v8);
    v17 = _mm_mul_ps(v16, v11);
    v18 = _mm_mul_ps(v16, v10);
    v19 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0));
    v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0));
    if ( v20.m128_f32[0] < 0.0 || v19.m128_f32[0] > v20.m128_f32[0] )
    {
      v21 = _mm_sub_ps(_mm_mul_ps(v19, v13), _mm_mul_ps(v20, v15));
      if ( v21.m128_f32[0] > 0.0 || v13.m128_f32[0] < 0.0 || v20.m128_f32[0] > 0.0 )
      {
        v24 = _mm_sub_ps(m_quad, v6);
        v25 = _mm_mul_ps(v24, v10);
        v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0));
        v27 = _mm_mul_ps(v11, v24);
        v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0));
        if ( v28.m128_f32[0] < 0.0 || v26.m128_f32[0] > v28.m128_f32[0] )
        {
          v29 = _mm_sub_ps(_mm_mul_ps(v26, v15), _mm_mul_ps(v28, v13));
          if ( v29.m128_f32[0] > 0.0 || v15.m128_f32[0] < 0.0 || v28.m128_f32[0] > 0.0 )
          {
            v32 = _mm_sub_ps(_mm_mul_ps(v28, v20), _mm_mul_ps(v26, v19));
            if ( v32.m128_f32[0] > 0.0
              || (v33 = _mm_sub_ps(v19, v20), v33.m128_f32[0] < 0.0)
              || (v34 = _mm_sub_ps(v26, v28), v34.m128_f32[0] < 0.0) )
            {
              v37 = _mm_add_ps(_mm_add_ps(v32, v29), v21);
              v38 = _mm_rcp_ps(v37);
              v39 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v37)), v38), query.m_quad);
              closestPointOut->m_quad = _mm_add_ps(
                                          _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v39, v29), v10), v7),
                                          _mm_mul_ps(_mm_mul_ps(v39, v21), v11));
            }
            else
            {
              v35 = _mm_add_ps(v34, v33);
              v36 = _mm_rcp_ps(v35);
              closestPointOut->m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps(v6, v8),
                                            _mm_mul_ps(
                                              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v35)), v36),
                                              v33)),
                                          v8);
            }
          }
          else
          {
            v30 = _mm_sub_ps(v15, v28);
            v31 = _mm_rcp_ps(v30);
            closestPointOut->m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_mul_ps(
                                            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v30, v31)), v31),
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
        v22 = _mm_sub_ps(v13, v20);
        v23 = _mm_rcp_ps(v22);
        closestPointOut->m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v23)), v23), v13),
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
void __fastcall UFG::HavokAIUtilGame::getClosestPointOnFace2d<hkaiNavMeshInstance>(
        UFG::HavokAIUtilGame *this,
        hkVector4f *mesh,
        hkVector4f *position,
        hkVector4f *faceIndex,
        hkVector4f *closestPointOut)
{
  int v5; // eax
  int *v9; // rsi
  int v10; // edx
  __int64 v11; // rdx
  int v12; // ecx
  __int64 v13; // rcx
  __int64 v14; // rax
  int v15; // r8d
  int *v16; // r8
  int v17; // ecx
  __int64 v18; // rax
  __m128 *v19; // rax
  __m128 v20; // xmm1
  int v21; // eax
  float v22; // xmm7_4
  int v23; // edi
  __int64 v24; // r14
  int v25; // ecx
  __int64 v26; // rcx
  __int64 v27; // rax
  int v28; // ecx
  int *v29; // rdx
  int v30; // ecx
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
  hkVector4f c; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f b; // [rsp+40h] [rbp-68h] BYREF
  hkVector4f a; // [rsp+50h] [rbp-58h] BYREF
  hkVector4f v48; // [rsp+60h] [rbp-48h] BYREF

  v5 = *(_DWORD *)&this[24];
  if ( (int)position < v5 )
  {
    if ( *(_DWORD *)&this[232] )
      v10 = *(_DWORD *)(*(_QWORD *)&this[224] + 4i64 * (int)position);
    else
      v10 = (int)position;
    if ( v10 == -1 )
      v9 = (int *)(*(_QWORD *)&this[16] + 16i64 * (int)position);
    else
      v9 = (int *)(*(_QWORD *)&this[240] + 16i64 * v10);
  }
  else
  {
    v9 = (int *)(*(_QWORD *)&this[272] + 16i64 * ((int)position - v5));
  }
  v11 = *v9;
  v12 = *(_DWORD *)&this[40];
  if ( (int)v11 < v12 )
  {
    if ( *(_DWORD *)&this[216] )
      v15 = *(_DWORD *)(*(_QWORD *)&this[208] + 4 * v11);
    else
      v15 = *v9;
    if ( v15 == -1 )
    {
      v14 = *(_QWORD *)&this[32];
      v13 = 5 * v11;
    }
    else
    {
      v13 = 5i64 * v15;
      v14 = *(_QWORD *)&this[256];
    }
  }
  else
  {
    v13 = 5i64 * ((int)v11 - v12);
    v14 = *(_QWORD *)&this[288];
  }
  v16 = (int *)(v14 + 4 * v13);
  v17 = *(_DWORD *)&this[56];
  v18 = *v16;
  if ( (int)v18 >= v17 )
    v19 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)v18 - v17));
  else
    v19 = (__m128 *)(*(_QWORD *)&this[48] + 16 * v18);
  v20 = *v19;
  v21 = *((__int16 *)v9 + 4);
  v22 = *(float *)&_xmm;
  v23 = v11 + 1;
  a.m_quad = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), *(__m128 *)&this[112]),
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), *(__m128 *)&this[128])),
                 _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), *(__m128 *)&this[144])),
               *(__m128 *)&this[160]);
  if ( (int)v11 + 1 < v21 + (int)v11 - 1 )
  {
    v24 = 4i64 * v23;
    do
    {
      v25 = *(_DWORD *)&this[40];
      if ( v23 < v25 )
      {
        if ( *(_DWORD *)&this[216] )
          v28 = *(_DWORD *)(v24 + *(_QWORD *)&this[208]);
        else
          v28 = v23;
        if ( v28 == -1 )
        {
          v26 = 5i64 * v23;
          v27 = *(_QWORD *)&this[32];
        }
        else
        {
          v26 = 5i64 * v28;
          v27 = *(_QWORD *)&this[256];
        }
      }
      else
      {
        v26 = 5i64 * (v23 - v25);
        v27 = *(_QWORD *)&this[288];
      }
      v29 = (int *)(v27 + 4 * v26);
      v30 = *(_DWORD *)&this[56];
      v31 = *v29;
      if ( (int)v31 >= v30 )
        v32 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)v31 - v30));
      else
        v32 = (__m128 *)(*(_QWORD *)&this[48] + 16 * v31);
      v33 = *v32;
      v34 = *(__m128 *)&this[128];
      v35 = *(__m128 *)&this[112];
      v36 = v29[1];
      v37 = *(__m128 *)&this[144];
      v38 = *(__m128 *)&this[160];
      v39 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v35), _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v34)),
                _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v37)),
              v38);
      if ( (int)v36 >= v30 )
        v40 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)v36 - v30));
      else
        v40 = (__m128 *)(*(_QWORD *)&this[48] + 16 * v36);
      v41 = *v40;
      b.m_quad = v39;
      c.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v35),
                       _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v34)),
                     _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v37)),
                   v38);
      UFG::HavokAIUtilGame::getClosestPointOnTriangle2d(mesh, &a, &b, &c, &v48);
      v42 = _mm_sub_ps(mesh->m_quad, v48.m_quad);
      v43 = _mm_mul_ps(v42, v42);
      v44 = (float)(_mm_shuffle_ps(v43, v43, 85).m128_f32[0] + _mm_shuffle_ps(v43, v43, 0).m128_f32[0])
          + _mm_shuffle_ps(v43, v43, 170).m128_f32[0];
      if ( v44 < v22 )
      {
        v22 = v44;
        *faceIndex = (hkVector4f)v48.m_quad;
      }
      ++v23;
      v24 += 4i64;
    }
    while ( v23 < *v9 + *((__int16 *)v9 + 4) - 1 );
  }
}

// File Line: 200
// RVA: 0xF5160
void __fastcall UFG::HavokAIUtilGame::getFaceNormal(unsigned int faceKey, hkVector4f *normalOut)
{
  hkaiNavMeshQueryMediator *DynamicQueryMediator; // rax
  void *(__fastcall *vecDelDtor)(hkBaseObject *, unsigned int); // rcx
  hkaiNavMeshInstance *v6; // rdi
  hkaiNavMesh::Face *Face; // rbx
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm5
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  hkVector4f edgeB; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f edgeA; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f v17; // [rsp+40h] [rbp-18h] BYREF

  *normalOut = (hkVector4f)_xmm;
  if ( faceKey != -1 )
  {
    if ( UFG::NavManager::ms_pInstance )
    {
      DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
      if ( DynamicQueryMediator )
      {
        vecDelDtor = DynamicQueryMediator[1].vfptr[2].__vecDelDtor;
        v6 = (hkaiNavMeshInstance *)*((_QWORD *)vecDelDtor + 6 * (faceKey >> 22));
        if ( v6 )
        {
          Face = hkaiNavMeshInstance::getFace(
                   *((hkaiNavMeshInstance **)vecDelDtor + 6 * (faceKey >> 22)),
                   faceKey & 0x3FFFFF);
          hkaiNavMeshInstance::getEdgePoints(v6, Face->m_startEdgeIndex, &edgeA, &edgeB);
          hkaiNavMeshInstance::getEdgePoints(v6, Face->m_startEdgeIndex + 1, &edgeB, &v17);
          v8 = _mm_sub_ps(edgeB.m_quad, v17.m_quad);
          v9 = _mm_sub_ps(edgeB.m_quad, edgeA.m_quad);
          v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
          v11 = _mm_shuffle_ps(v10, v10, 201);
          v12 = _mm_mul_ps(v11, v11);
          v13 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                  _mm_shuffle_ps(v12, v12, 170));
          v14 = _mm_rsqrt_ps(v13);
          normalOut->m_quad = _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmple_ps(v13, (__m128)0i64),
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
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall UFG::HavokAIUtilGame::FindClosestMeshPosition2d(
        hkVector4f *hkvPosition,
        double fToleranceXY,
        double fToleranceZ,
        hkVector4f *hkvClosestPointOut,
        unsigned int *meshUidOut)
{
  float v5; // xmm9_4
  __m128 v6; // xmm6
  __int64 v8; // rdi
  char v9; // dl
  __int64 v10; // rsi
  char v11; // cl
  hkaiNavMeshQueryMediator *DynamicQueryMediator; // rcx
  unsigned int v13; // r14d
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  float v17; // xmm6_4
  hkVector4f v18; // xmm7
  unsigned int v19; // r12d
  int v20; // ebx
  __int64 v21; // rdi
  unsigned int v22; // ebp
  __int64 v23; // r15
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  float v26; // xmm1_4
  char v27; // cl
  __int64 result; // rax
  hkVector4f *closestPointOut; // [rsp+20h] [rbp-E8h] BYREF
  int v30; // [rsp+28h] [rbp-E0h]
  int v31; // [rsp+2Ch] [rbp-DCh]
  int faceIndex[4]; // [rsp+30h] [rbp-D8h] BYREF
  __int64 v33; // [rsp+40h] [rbp-C8h]
  __int64 v34; // [rsp+48h] [rbp-C0h]
  int v35; // [rsp+50h] [rbp-B8h] BYREF
  __int64 v36; // [rsp+58h] [rbp-B0h]
  __int128 v37; // [rsp+60h] [rbp-A8h]
  __int64 v38; // [rsp+70h] [rbp-98h]
  __m128 v39; // [rsp+80h] [rbp-88h]
  __m128 v40; // [rsp+90h] [rbp-78h]

  v34 = -2i64;
  v5 = *(float *)&fToleranceZ;
  v6 = *(__m128 *)&fToleranceXY;
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v33 = v8;
  v9 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v9) = 1;
  *(_QWORD *)(v8 + 8i64 * v9 + 16) = "FindClosestMeshPosition2d";
  v10 = 0i64;
  *(_QWORD *)(v8 + 8i64 * v9 + 48) = 0i64;
  v11 = *(_BYTE *)(v8 + 81);
  if ( v9 > v11 )
    v11 = v9;
  *(_BYTE *)(v8 + 81) = v11;
  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  *(_QWORD *)faceIndex = DynamicQueryMediator;
  v13 = -1;
  *meshUidOut = -1;
  if ( DynamicQueryMediator )
  {
    closestPointOut = 0i64;
    v30 = 0;
    v31 = 0x80000000;
    v14 = _mm_unpacklo_ps(
            _mm_unpacklo_ps(*(__m128 *)&fToleranceXY, *(__m128 *)&fToleranceZ),
            _mm_unpacklo_ps(*(__m128 *)&fToleranceXY, (__m128)0i64));
    v15 = _mm_sub_ps(hkvPosition->m_quad, v14);
    v16 = _mm_add_ps(hkvPosition->m_quad, v14);
    v35 = 0;
    v36 = 0i64;
    v37 = 0i64;
    v38 = 0i64;
    v39 = v15;
    v40 = v16;
    ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkVector4f **))DynamicQueryMediator->vfptr[3].__first_virtual_table_function__)(
      DynamicQueryMediator,
      &v35,
      &closestPointOut);
    v6.m128_f32[0] = v6.m128_f32[0] * v6.m128_f32[0];
    LODWORD(v17) = _mm_shuffle_ps(v6, v6, 0).m128_u32[0];
    v18.m_quad = 0i64;
    v19 = -1;
    v20 = 0;
    if ( v30 > 0 )
    {
      v21 = *(_QWORD *)faceIndex;
      do
      {
        v22 = closestPointOut->m_quad.m128_u32[v10];
        v23 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 16) + 32i64) + 48i64 * (v22 >> 22));
        UFG::HavokAIUtilGame::getClosestPointOnFace2d<hkaiNavMeshInstance>(
          (UFG::HavokAIUtilGame *)v23,
          hkvPosition,
          (hkVector4f *)(v22 & 0x3FFFFF),
          (hkVector4f *)faceIndex,
          closestPointOut);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(hkvPosition->m_quad.m128_f32[2] - *(float *)&faceIndex[2]) & _xmm) < v5 )
        {
          v24 = _mm_sub_ps(hkvPosition->m_quad, *(__m128 *)faceIndex);
          v25 = _mm_mul_ps(v24, v24);
          v26 = _mm_shuffle_ps(v25, v25, 85).m128_f32[0] + _mm_shuffle_ps(v25, v25, 0).m128_f32[0];
          if ( v26 < v17 )
          {
            v17 = v26;
            v13 = v22;
            v18.m_quad = *(__m128 *)faceIndex;
            v19 = *(_DWORD *)(v23 + 468);
          }
        }
        ++v20;
        ++v10;
      }
      while ( v20 < v30 );
      v8 = v33;
    }
    *hkvClosestPointOut = (hkVector4f)v18.m_quad;
    *meshUidOut = v19;
    v30 = 0;
    if ( v31 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, closestPointOut, 4 * v31);
    closestPointOut = 0i64;
    v31 = 0x80000000;
  }
  v27 = *(_BYTE *)(v8 + 80);
  result = v13;
  if ( v27 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v27 - 1;
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
_BOOL8 __fastcall UFG::HavokAIUtilGame::_isPointOnFaceAndProject(
        hkaiNavMeshInstance *meshInstance,
        unsigned int faceIndex,
        hkVector4f *point,
        float edgeTolerance,
        float coherencyTolerance,
        hkVector4f *projectionOut)
{
  __m128 v6; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  hkVector4f *tolerance; // [rsp+20h] [rbp-38h]
  hkSimdFloat32 v14; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f faceNormal; // [rsp+40h] [rbp-18h] BYREF

  v6.m128_f32[0] = edgeTolerance;
  faceNormal.m_quad = _xmm;
  v14.m_real = _mm_shuffle_ps(v6, v6, 0);
  if ( !hkaiNavMeshUtils::isPointOnFace(meshInstance, faceIndex, &faceNormal, point, &v14) )
    return 0i64;
  UFG::HavokAIUtilGame::getClosestPointOnFace2d<hkaiNavMeshInstance>(
    (UFG::HavokAIUtilGame *)meshInstance,
    point,
    (hkVector4f *)faceIndex,
    projectionOut,
    tolerance);
  v10 = _mm_sub_ps(projectionOut->m_quad, point->m_quad);
  v11 = _mm_mul_ps(v10, v10);
  return (float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0]) <= (float)(coherencyTolerance * coherencyTolerance);
}

// File Line: 335
// RVA: 0xEF500
bool __fastcall UFG::HavokAIUtilGame::IsFaceKeyValid(
        hkaiDynamicNavMeshQueryMediator *pQueryMediator,
        unsigned int key,
        unsigned int meshUid)
{
  hkaiStreamingCollection *m_pntr; // rdx
  __int64 v6; // rax
  hkaiNavMeshInstance *m_instancePtr; // rdx
  signed int v8; // r9d

  m_pntr = pQueryMediator->m_collection.m_pntr;
  v6 = key >> 22;
  if ( (int)v6 >= m_pntr->m_instances.m_size )
    return 0;
  m_instancePtr = m_pntr->m_instances.m_data[v6].m_instancePtr;
  if ( !m_instancePtr )
    return 0;
  if ( m_instancePtr->m_sectionUid != meshUid )
    return 0;
  v8 = key & 0x3FFFFF;
  if ( v8 >= m_instancePtr->m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size )
    return 0;
  if ( m_instancePtr->m_faceFlags.m_size )
    return (m_instancePtr->m_faceFlags.m_data[v8].m_storage & 1) == 0;
  return 1;
}

// File Line: 359
// RVA: 0xEA5E0
__int64 __fastcall UFG::HavokAIUtilGame::FindClosestMeshPosition2dCoherent(
        hkVector4f *hkvPoint,
        hkVector4f *hkvPreviousPoint,
        unsigned int previousFaceKey,
        unsigned int previousMeshUid,
        float fToleranceXY,
        float fToleranceZ,
        hkVector4f *closestPointOut,
        unsigned int *meshUidOut)
{
  __int64 v10; // r14
  char v12; // r10
  char v14; // cl
  UFG::NavManager *v15; // rax
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // rdi
  hkaiNavMeshInstance *m_instancePtr; // rdi
  hkJobType v18; // edx
  __int64 result; // rax
  hkaiNavMesh::Face *Face; // r13
  __int64 m_startEdgeIndex; // rbx
  __m128 v22; // xmm0
  __m128 v23; // xmm7
  __m128 v24; // xmm7
  __m128 v25; // xmm1
  __m128 v26; // xmm7
  __int64 v27; // r15
  int m_numOriginalEdges; // ecx
  __int64 v29; // rcx
  hkaiNavMesh::Edge *m_originalEdges; // rax
  int v31; // ecx
  hkaiNavMesh::Edge *v32; // rsi
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  unsigned int m_oppositeFace; // esi
  hkaiNavMeshInstance *v40; // rcx
  hkJobType v41; // edx
  char v42; // cl
  char v43; // al
  hkVector4f projectionOut; // [rsp+30h] [rbp-B8h] BYREF
  hkVector4f edgeA; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f edgeB; // [rsp+50h] [rbp-98h] BYREF
  hkaiDynamicNavMeshQueryMediator *v47; // [rsp+F0h] [rbp+8h]

  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v12 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v12) = 1;
  *(_QWORD *)(v10 + 8i64 * v12 + 16) = "FindClosestMeshPosition2dCoherent";
  *(_QWORD *)(v10 + 8i64 * v12 + 48) = 0i64;
  v14 = *(_BYTE *)(v10 + 81);
  v15 = UFG::NavManager::ms_pInstance;
  if ( v12 > v14 )
    v14 = v12;
  *(_BYTE *)(v10 + 81) = v14;
  DynamicQueryMediator = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)v15[3].vfptr);
  v47 = DynamicQueryMediator;
  projectionOut.m_quad = hkvPoint->m_quad;
  *meshUidOut = previousMeshUid;
  if ( DynamicQueryMediator )
  {
    if ( previousFaceKey == -1
      || previousMeshUid == -1
      || !UFG::HavokAIUtilGame::IsFaceKeyValid(DynamicQueryMediator, previousFaceKey, previousMeshUid) )
    {
      goto LABEL_30;
    }
    m_instancePtr = DynamicQueryMediator->m_collection.m_pntr->m_instances.m_data[previousFaceKey >> 22].m_instancePtr;
    if ( UFG::HavokAIUtilGame::_isPointOnFaceAndProject(
           m_instancePtr,
           previousFaceKey & 0x3FFFFF,
           hkvPoint,
           0.001,
           0.1,
           &projectionOut)
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(projectionOut.m_quad.m128_f32[2] - hkvPoint->m_quad.m128_f32[2]) & _xmm) <= fToleranceZ )
    {
      *closestPointOut = (hkVector4f)projectionOut.m_quad;
      *meshUidOut = previousMeshUid;
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v18);
      return previousFaceKey;
    }
    Face = hkaiNavMeshInstance::getFace(m_instancePtr, previousFaceKey & 0x3FFFFF);
    m_startEdgeIndex = Face->m_startEdgeIndex;
    v22 = _mm_sub_ps(hkvPoint->m_quad, hkvPreviousPoint->m_quad);
    v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), _xmm), _mm_mul_ps(_mm_shuffle_ps(_xmm, _xmm, 201), v22));
    v24 = _mm_shuffle_ps(v23, v23, 201);
    v25 = _mm_mul_ps(hkvPreviousPoint->m_quad, v24);
    v26 = _mm_shuffle_ps(
            v24,
            _mm_unpackhi_ps(
              v24,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                  _mm_shuffle_ps(v25, v25, 170)))),
            196);
    if ( (int)m_startEdgeIndex >= (int)m_startEdgeIndex + Face->m_numEdges )
    {
LABEL_30:
      result = UFG::HavokAIUtilGame::FindClosestMeshPosition2d(
                 hkvPoint,
                 COERCE_DOUBLE((unsigned __int64)LODWORD(fToleranceXY)),
                 COERCE_DOUBLE((unsigned __int64)LODWORD(fToleranceZ)),
                 closestPointOut,
                 meshUidOut);
      v42 = *(_BYTE *)(v10 + 80);
      if ( v42 > 0 )
      {
        *(_BYTE *)(v10 + 80) = v42 - 1;
      }
      else
      {
        *(_BYTE *)(v10 + 80) = 0;
        *(_DWORD *)v10 = 3;
        *(_QWORD *)(v10 + 16) = 0i64;
        *(_QWORD *)(v10 + 48) = 0i64;
      }
    }
    else
    {
      v27 = m_startEdgeIndex;
      while ( 1 )
      {
        m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
        if ( (int)m_startEdgeIndex < m_numOriginalEdges )
        {
          v31 = m_instancePtr->m_edgeMap.m_size ? m_instancePtr->m_edgeMap.m_data[v27] : m_startEdgeIndex;
          if ( v31 == -1 )
          {
            v29 = (int)m_startEdgeIndex;
            m_originalEdges = m_instancePtr->m_originalEdges;
          }
          else
          {
            v29 = v31;
            m_originalEdges = m_instancePtr->m_instancedEdges.m_data;
          }
        }
        else
        {
          v29 = (int)m_startEdgeIndex - m_numOriginalEdges;
          m_originalEdges = m_instancePtr->m_ownedEdges.m_data;
        }
        v32 = &m_originalEdges[v29];
        if ( v32->m_oppositeEdge != -1 && (v32->m_flags.m_storage & 0x20) == 0 )
        {
          hkaiNavMeshInstance::getEdgePoints(m_instancePtr, m_startEdgeIndex, &edgeA, &edgeB);
          v33 = _mm_mul_ps(edgeA.m_quad, v26);
          v34 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v26), 196);
          v35 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 78), v34);
          v36 = _mm_mul_ps(edgeB.m_quad, v26);
          v37 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v26), 196);
          v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
          if ( (float)(_mm_shuffle_ps(v35, v35, 177).m128_f32[0] + v35.m128_f32[0]) <= 0.0
            && (float)(_mm_shuffle_ps(v38, v38, 177).m128_f32[0] + v38.m128_f32[0]) >= 0.0 )
          {
            m_oppositeFace = v32->m_oppositeFace;
            v40 = v47->m_collection.m_pntr->m_instances.m_data[m_oppositeFace >> 22].m_instancePtr;
            if ( v40 )
            {
              if ( v40->m_sectionUid == previousMeshUid
                && UFG::HavokAIUtilGame::_isPointOnFaceAndProject(
                     v40,
                     m_oppositeFace & 0x3FFFFF,
                     hkvPoint,
                     0.001,
                     0.1,
                     &projectionOut)
                && COERCE_FLOAT(COERCE_UNSIGNED_INT(projectionOut.m_quad.m128_f32[2] - hkvPoint->m_quad.m128_f32[2]) & _xmm) <= fToleranceZ )
              {
                break;
              }
            }
          }
        }
        LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
        ++v27;
        if ( (int)m_startEdgeIndex >= Face->m_startEdgeIndex + Face->m_numEdges )
          goto LABEL_30;
      }
      *closestPointOut = (hkVector4f)projectionOut.m_quad;
      *meshUidOut = previousMeshUid;
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v41);
      return m_oppositeFace;
    }
  }
  else
  {
    v43 = *(_BYTE *)(v10 + 80);
    if ( v43 > 0 )
    {
      *(_BYTE *)(v10 + 80) = v43 - 1;
      return 0xFFFFFFFFi64;
    }
    else
    {
      *(_BYTE *)(v10 + 80) = 0;
      result = 0xFFFFFFFFi64;
      *(_DWORD *)v10 = 3;
      *(_QWORD *)(v10 + 16) = 0i64;
      *(_QWORD *)(v10 + 48) = 0i64;
    }
  }
  return result;
}

// File Line: 470
// RVA: 0xEABF0
// local variable allocation has failed, the output may be wrong!
char __fastcall UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(
        hkVector4f *hkvPosition,
        hkVector4f *hkvNewPosition,
        double fRadius)
{
  __m128 v3; // xmm13
  __int64 v6; // rsi
  char v7; // r8
  char v8; // cl
  UFG::NavManager *v9; // rdi
  hkaiNavMeshQueryMediator *DynamicQueryMediator; // rax
  float v11; // xmm14_4
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  hkaiStreamingCollection::InstanceInfo *v15; // rax
  float v16; // xmm8_4
  int v17; // r14d
  __int64 v18; // r15
  float y; // xmm11_4
  float x; // xmm12_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  __m128 y_low; // xmm7
  float v24; // xmm6_4
  unsigned int v25; // ebx
  int v26; // ebx
  hkaiNavMeshInstance *m_accessor; // rdx
  int m_numOriginalFaces; // eax
  hkaiNavMesh::Face *v29; // rbx
  int v30; // r8d
  int i; // edi
  int v32; // r8d
  int m_numOriginalEdges; // eax
  __int64 v34; // rcx
  hkaiNavMesh::Edge *m_originalEdges; // rax
  int v36; // r9d
  hkaiNavMesh::Edge *v37; // r8
  __int64 m_a; // rax
  int m_numOriginalVertices; // ecx
  __m128 *v40; // rax
  __m128 v41; // xmm3
  __int64 m_b; // rax
  __m128 *v43; // rax
  __m128 v44; // xmm0
  __m128 v45; // xmm3
  float v46; // xmm5_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm5_4
  float v51; // xmm2_4
  bool v52; // al
  float v53; // xmm1_4
  __m128 x_low; // xmm4
  float v55; // xmm2_4
  float v56; // xmm3_4
  float v57; // xmm5_4
  char v58; // al
  char v60; // al
  UFG::qVector2 P; // [rsp+20h] [rbp-E0h] BYREF
  char *v62; // [rsp+28h] [rbp-D8h] BYREF
  int v63; // [rsp+30h] [rbp-D0h]
  int v64; // [rsp+34h] [rbp-CCh]
  UFG::qVector2 lA0; // [rsp+38h] [rbp-C8h] BYREF
  UFG::qVector2 lA1; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int v67; // [rsp+48h] [rbp-B8h]
  UFG::qVector2 closest_point; // [rsp+50h] [rbp-B0h] BYREF
  hkaiGeneralAccessor v69; // [rsp+58h] [rbp-A8h] BYREF
  __int64 v70; // [rsp+70h] [rbp-90h]
  int v71; // [rsp+80h] [rbp-80h] BYREF
  __int64 v72; // [rsp+88h] [rbp-78h]
  __int128 v73; // [rsp+90h] [rbp-70h]
  __int64 v74; // [rsp+A0h] [rbp-60h]
  __m128 v75; // [rsp+B0h] [rbp-50h]
  __m128 v76; // [rsp+C0h] [rbp-40h]
  float v77; // [rsp+1B4h] [rbp+B4h]
  float v78; // [rsp+1B8h] [rbp+B8h]
  float v79; // [rsp+1C8h] [rbp+C8h]

  v70 = -2i64;
  v3 = *(__m128 *)&fRadius;
  v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v7 = ++*(_BYTE *)(v6 + 80);
  *(_DWORD *)(v6 + 4i64 * v7) = 1;
  *(_QWORD *)(v6 + 8i64 * v7 + 16) = "FindMeshPositionAwayFromWall";
  *(_QWORD *)(v6 + 8i64 * v7 + 48) = 0i64;
  v8 = *(_BYTE *)(v6 + 81);
  if ( v7 > v8 )
    v8 = v7;
  *(_BYTE *)(v6 + 81) = v8;
  v9 = UFG::NavManager::ms_pInstance;
  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  *hkvNewPosition = (hkVector4f)hkvPosition->m_quad;
  if ( !DynamicQueryMediator )
    goto LABEL_60;
  v62 = 0i64;
  v63 = 0;
  v64 = 0x80000000;
  v11 = 0.0;
  v12 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(*(__m128 *)&fRadius, (__m128)(unsigned int)FLOAT_1_0),
          _mm_unpacklo_ps(*(__m128 *)&fRadius, (__m128)0i64));
  v13 = _mm_sub_ps(hkvPosition->m_quad, v12);
  v14 = _mm_add_ps(v12, hkvPosition->m_quad);
  v71 = 0;
  v72 = 0i64;
  v73 = 0i64;
  v74 = 0i64;
  v75 = v13;
  v76 = v14;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, char **))DynamicQueryMediator->vfptr[3].__first_virtual_table_function__)(
    DynamicQueryMediator,
    &v71,
    &v62);
  v15 = (hkaiStreamingCollection::InstanceInfo *)*((_QWORD *)v9[3].vfptr->LowHealthDefrag + 4);
  v69.m_currentSection = -1;
  v69.m_sectionInfo = v15;
  v69.m_accessor = 0i64;
  v79 = hkvPosition->m_quad.m128_f32[0];
  v78 = hkvPosition->m_quad.m128_f32[1];
  v67 = hkvPosition->m_quad.m128_u32[2];
  P.x = v79;
  P.y = v78;
  v16 = *(float *)&fRadius * *(float *)&fRadius;
  v17 = 0;
  if ( v63 <= 0 )
    goto LABEL_57;
  v18 = 0i64;
  y = v77;
  x = *(float *)&fRadius * *(float *)&fRadius;
  v21 = v77;
  v22 = *(float *)&fRadius * *(float *)&fRadius;
  y_low = (__m128)LODWORD(v77);
  v24 = *(float *)&fRadius * *(float *)&fRadius;
  do
  {
    v25 = *(_DWORD *)&v62[v18];
    hkaiGeneralAccessor::setSection(&v69, v25 >> 22);
    v26 = v25 & 0x3FFFFF;
    m_accessor = v69.m_accessor;
    m_numOriginalFaces = v69.m_accessor->m_numOriginalFaces;
    if ( v26 < m_numOriginalFaces )
    {
      if ( v69.m_accessor->m_faceMap.m_size )
        v30 = v69.m_accessor->m_faceMap.m_data[v26];
      else
        v30 = v26;
      if ( v30 == -1 )
        v29 = &v69.m_accessor->m_originalFaces[v26];
      else
        v29 = &v69.m_accessor->m_instancedFaces.m_data[v30];
    }
    else
    {
      v29 = &v69.m_accessor->m_ownedFaces.m_data[v26 - m_numOriginalFaces];
    }
    for ( i = 0; i < v29->m_numEdges; ++i )
    {
      v32 = i + v29->m_startEdgeIndex;
      m_numOriginalEdges = m_accessor->m_numOriginalEdges;
      if ( v32 < m_numOriginalEdges )
      {
        if ( m_accessor->m_edgeMap.m_size )
          v36 = m_accessor->m_edgeMap.m_data[v32];
        else
          v36 = i + v29->m_startEdgeIndex;
        if ( v36 == -1 )
        {
          v34 = v32;
          m_originalEdges = m_accessor->m_originalEdges;
        }
        else
        {
          v34 = v36;
          m_originalEdges = m_accessor->m_instancedEdges.m_data;
        }
      }
      else
      {
        v34 = v32 - m_numOriginalEdges;
        m_originalEdges = m_accessor->m_ownedEdges.m_data;
      }
      v37 = &m_originalEdges[v34];
      if ( v37->m_oppositeEdge == -1 )
      {
        m_a = v37->m_a;
        m_numOriginalVertices = m_accessor->m_numOriginalVertices;
        v40 = (__m128 *)((int)m_a >= m_numOriginalVertices
                       ? &m_accessor->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices]
                       : &m_accessor->m_originalVertices[m_a]);
        v41 = _mm_add_ps(
                m_accessor->m_referenceFrame.m_transform.m_translation.m_quad,
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(*v40, *v40, 85),
                      m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(
                      _mm_shuffle_ps(*v40, *v40, 0),
                      m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(*v40, *v40, 170),
                    m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)));
        m_b = v37->m_b;
        v43 = (__m128 *)((int)m_b >= m_numOriginalVertices
                       ? &m_accessor->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices]
                       : &m_accessor->m_originalVertices[m_b]);
        v44 = _mm_add_ps(
                m_accessor->m_referenceFrame.m_transform.m_translation.m_quad,
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(*v43, *v43, 85),
                      m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(
                      _mm_shuffle_ps(*v43, *v43, 0),
                      m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(*v43, *v43, 170),
                    m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)));
        LODWORD(lA0.x) = v41.m128_i32[0];
        LODWORD(lA0.y) = _mm_shuffle_ps(v41, v41, 85).m128_u32[0];
        LODWORD(lA1.x) = v44.m128_i32[0];
        LODWORD(lA1.y) = _mm_shuffle_ps(v44, v44, 85).m128_u32[0];
        UFG::qGetClosestPointOnSegment(&closest_point, &lA0, &lA1, &P);
        m_accessor = v69.m_accessor;
        if ( (float)((float)((float)(P.x - closest_point.x) * (float)(P.x - closest_point.x))
                   + (float)((float)(P.y - closest_point.y) * (float)(P.y - closest_point.y))) < v16 )
        {
          v16 = (float)((float)(P.x - closest_point.x) * (float)(P.x - closest_point.x))
              + (float)((float)(P.y - closest_point.y) * (float)(P.y - closest_point.y));
          x = closest_point.x;
          y = closest_point.y;
          v22 = lA0.x;
          v21 = lA0.y;
          v24 = lA1.x;
          y_low = (__m128)LODWORD(lA1.y);
        }
      }
    }
    ++v17;
    v18 += 4i64;
  }
  while ( v17 < v63 );
  if ( v16 >= (float)(*(float *)&fRadius * *(float *)&fRadius) )
  {
LABEL_57:
    v63 = 0;
    if ( v64 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v62, 4 * v64);
    v62 = 0i64;
    v64 = 0x80000000;
LABEL_60:
    v60 = *(_BYTE *)(v6 + 80);
    if ( v60 > 0 )
    {
      *(_BYTE *)(v6 + 80) = v60 - 1;
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
  v45 = y_low;
  v45.m128_f32[0] = y_low.m128_f32[0] - v21;
  v46 = v24 - v22;
  v47 = (float)(v46 * v46) + (float)(v45.m128_f32[0] * v45.m128_f32[0]);
  if ( v47 == 0.0 )
    v48 = 0.0;
  else
    v48 = 1.0 / fsqrt(v47);
  v49 = v45.m128_f32[0] * v48;
  v50 = v46 * v48;
  v51 = fsqrt(v16);
  v52 = (float)((float)((float)(v22 - x) * (float)(v22 - x)) + (float)((float)(v21 - y) * (float)(v21 - y))) < 0.0099999998
     || (float)((float)((float)(v24 - x) * (float)(v24 - x))
              + (float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))) < 0.0099999998;
  if ( v51 <= 0.001 )
  {
    x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    v55 = (float)(v50 * UFG::qVector3::msDirUp.y) - (float)(v49 * UFG::qVector3::msDirUp.x);
    x_low.m128_f32[0] = (float)(UFG::qVector3::msDirUp.x * 0.0) - (float)(v50 * UFG::qVector3::msDirUp.z);
    v56 = (float)(v49 * UFG::qVector3::msDirUp.z) - (float)(UFG::qVector3::msDirUp.y * 0.0);
    v57 = (float)((float)(v56 * v56) + (float)(x_low.m128_f32[0] * x_low.m128_f32[0])) + (float)(v55 * v55);
    if ( v57 != 0.0 )
      v11 = 1.0 / fsqrt(v57);
    v45.m128_f32[0] = v56 * v11;
    v3.m128_f32[0] = COERCE_FLOAT(v3.m128_i32[0] ^ _xmm[0]) - 0.050000001;
    x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * v11) * v3.m128_f32[0];
  }
  else
  {
    if ( (float)((float)(v50 * (float)(P.y - v21)) - (float)((float)(P.x - v22) * v49)) > 0.0 || v52 )
      v53 = *(float *)&FLOAT_1_0;
    else
      v53 = FLOAT_N1_0;
    v45 = (__m128)LODWORD(P.x);
    v45.m128_f32[0] = P.x - x;
    v3.m128_f32[0] = (float)((float)((float)(v3.m128_f32[0] + 0.050000001) - (float)(v51 * v53)) * v53) / v51;
    x_low = v3;
    x_low.m128_f32[0] = v3.m128_f32[0] * (float)(P.y - y);
  }
  x_low.m128_f32[0] = x_low.m128_f32[0] + v78;
  v45.m128_f32[0] = (float)(v45.m128_f32[0] * v3.m128_f32[0]) + v79;
  hkvNewPosition->m_quad = _mm_unpacklo_ps(
                             _mm_unpacklo_ps(v45, (__m128)v67),
                             _mm_unpacklo_ps(x_low, (__m128)(unsigned int)FLOAT_1_0));
  v58 = *(_BYTE *)(v6 + 80);
  if ( v58 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v58 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v63 = 0;
  if ( v64 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v62, 4 * v64);
  v62 = 0i64;
  v64 = 0x80000000;
  return 1;
}

// File Line: 640
// RVA: 0xEF7E0
bool __fastcall UFG::HavokAIUtilGame::IsValidKey(unsigned int key, unsigned int meshUid)
{
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // rax

  if ( key == -1 )
  {
    LOBYTE(DynamicQueryMediator) = 1;
  }
  else
  {
    DynamicQueryMediator = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
    if ( DynamicQueryMediator )
      LOBYTE(DynamicQueryMediator) = UFG::HavokAIUtilGame::IsFaceKeyValid(DynamicQueryMediator, key, meshUid);
  }
  return (char)DynamicQueryMediator;
}

