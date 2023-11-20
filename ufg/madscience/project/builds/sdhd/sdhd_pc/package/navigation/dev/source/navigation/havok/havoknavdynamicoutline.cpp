// File Line: 14
// RVA: 0xE4540
void __fastcall UFG::HavokNavDynamicOutline::HavokNavDynamicOutline(UFG::HavokNavDynamicOutline *this, UFG::qMatrix44 *transform, UFG::qVector3 *aabbMin, UFG::qVector3 *aabbMax, UFG::DynamicUserEdgeInfo *edgesInfo, unsigned int edgesCount)
{
  UFG::qVector3 *v6; // rdi
  UFG::qVector3 *v7; // rbx
  UFG::qMatrix44 *v8; // r12
  UFG::HavokNavDynamicOutline *v9; // rsi
  __m128 v10; // xmm6
  int v11; // eax
  int v12; // ecx
  __m128 v13; // xmm6
  int v14; // ecx
  __m128 v15; // xmm6
  int v16; // ecx
  __m128 v17; // xmm6
  int v18; // ecx
  __m128 v19; // xmm6
  int v20; // ecx
  __m128 v21; // xmm6
  int v22; // ecx
  __m128 v23; // xmm6
  int v24; // ecx
  __m128 v25; // xmm6
  _QWORD **v26; // rax
  hkaiPointCloudSilhouetteGenerator *v27; // rax
  __int64 v28; // rax
  UFG::DynamicUserEdgeInfo *v29; // rbx
  __int64 v30; // rdi
  __m128 *array; // [rsp+38h] [rbp-28h]
  int v32; // [rsp+40h] [rbp-20h]
  int v33; // [rsp+44h] [rbp-1Ch]
  hkResult result; // [rsp+B0h] [rbp+50h]

  v6 = aabbMax;
  v7 = aabbMin;
  v8 = transform;
  v9 = this;
  UFG::NavDynamicOutline::NavDynamicOutline((UFG::NavDynamicOutline *)&this->vfptr);
  v9->vfptr = (UFG::NavDynamicOutlineVtbl *)&UFG::HavokNavDynamicOutline::`vftable;
  v9->m_dynamicEdgesLocal.p = 0i64;
  *(_QWORD *)&v9->m_dynamicEdgesLocal.size = 0i64;
  v9->m_dynamicEdgesWorld.p = 0i64;
  *(_QWORD *)&v9->m_dynamicEdgesWorld.size = 0i64;
  v9->m_pSilhouette = 0i64;
  v9->m_firstInsertion = 1;
  array = 0i64;
  v32 = 0;
  v33 = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8, 16);
  v10 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v7->x), (__m128)LODWORD(v7->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v7->y), (__m128)0i64));
  v11 = v32;
  if ( v32 == (v33 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v11 = v32;
  }
  array[v11] = v10;
  v12 = v32 + 1;
  v32 = v12;
  v13 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v6->x), (__m128)LODWORD(v7->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v7->y), (__m128)0i64));
  if ( v12 == (v33 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v12 = v32;
  }
  array[v12] = v13;
  v14 = v32 + 1;
  v32 = v14;
  v15 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v6->x), (__m128)LODWORD(v7->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v6->y), (__m128)0i64));
  if ( v14 == (v33 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v14 = v32;
  }
  array[v14] = v15;
  v16 = v32 + 1;
  v32 = v16;
  v17 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v7->x), (__m128)LODWORD(v7->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v6->y), (__m128)0i64));
  if ( v16 == (v33 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v16 = v32;
  }
  array[v16] = v17;
  v18 = v32 + 1;
  v32 = v18;
  v19 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v7->x), (__m128)LODWORD(v6->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v7->y), (__m128)0i64));
  if ( v18 == (v33 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v18 = v32;
  }
  array[v18] = v19;
  v20 = v32 + 1;
  v32 = v20;
  v21 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v6->x), (__m128)LODWORD(v6->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v7->y), (__m128)0i64));
  if ( v20 == (v33 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v20 = v32;
  }
  array[v20] = v21;
  v22 = v32 + 1;
  v32 = v22;
  v23 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v6->x), (__m128)LODWORD(v6->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v6->y), (__m128)0i64));
  if ( v22 == (v33 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v22 = v32;
  }
  array[v22] = v23;
  v24 = v32 + 1;
  v32 = v24;
  v25 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(v7->x), (__m128)LODWORD(v6->z)),
          _mm_unpacklo_ps((__m128)LODWORD(v6->y), (__m128)0i64));
  if ( v24 == (v33 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v24 = v32;
  }
  array[v24] = v25;
  ++v32;
  v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkaiPointCloudSilhouetteGenerator *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v26[11] + 8i64))(
                                               v26[11],
                                               160i64);
  *(_QWORD *)&result.m_enum = v27;
  if ( v27 )
    hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(v27);
  else
    v28 = 0i64;
  v9->m_pSilhouette = (hkaiPointCloudSilhouetteGenerator *)v28;
  *(_DWORD *)(v28 + 24) = 1036831949;
  hkaiPointCloudSilhouetteGenerator::setLocalPoints(v9->m_pSilhouette, (hkArrayBase<hkVector4f> *)&array);
  if ( edgesCount )
  {
    v29 = edgesInfo;
    v30 = edgesCount;
    do
    {
      UFG::qArray<UFG::DynamicUserEdgeInfo,0>::Add(&v9->m_dynamicEdgesLocal, v29, "qArray.Add");
      UFG::qArray<UFG::DynamicUserEdgeInfo,0>::Add(&v9->m_dynamicEdgesWorld, v29, "qArray.Add");
      ++v29;
      --v30;
    }
    while ( v30 );
  }
  UFG::HavokNavDynamicOutline::UpdateTransform(v9, v8);
  v32 = 0;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v33);
}

// File Line: 48
// RVA: 0xE5D60
void __fastcall UFG::HavokNavDynamicOutline::~HavokNavDynamicOutline(UFG::HavokNavDynamicOutline *this)
{
  UFG::NavDynamicOutline *v1; // rbx
  UFG::NavDynamicOutlineVtbl *v2; // rcx
  UFG::NavDynamicOutlineVtbl *v3; // rcx

  v1 = (UFG::NavDynamicOutline *)&this->vfptr;
  this->vfptr = (UFG::NavDynamicOutlineVtbl *)&UFG::HavokNavDynamicOutline::`vftable;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_pSilhouette->vfptr);
  v1[14].vfptr = 0i64;
  v2 = v1[13].vfptr;
  if ( v2 )
    operator delete[](v2);
  v1[13].vfptr = 0i64;
  v1[12].vfptr = 0i64;
  v3 = v1[11].vfptr;
  if ( v3 )
    operator delete[](v3);
  v1[11].vfptr = 0i64;
  v1[10].vfptr = 0i64;
  UFG::NavDynamicOutline::~NavDynamicOutline(v1);
}

// File Line: 55
// RVA: 0xF3CB0
void __fastcall UFG::HavokNavDynamicOutline::UpdateTransform(UFG::HavokNavDynamicOutline *this, UFG::qMatrix44 *transform)
{
  UFG::qVector4 v2; // xmm1
  UFG::qVector4 v3; // xmm2
  UFG::HavokNavDynamicOutline *v4; // rdi
  UFG::qVector4 v5; // xmm3
  hkaiPointCloudSilhouetteGenerator *v6; // rax
  unsigned int v7; // eax
  __int64 v8; // rcx
  __int64 v9; // rdx
  UFG::DynamicUserEdgeInfo *v10; // rax
  float v11; // xmm6_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  UFG::DynamicUserEdgeInfo *v14; // rax
  float v15; // xmm5_4
  float v16; // xmm2_4
  float v17; // xmm6_4
  UFG::DynamicUserEdgeInfo *v18; // rax
  float v19; // xmm6_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  UFG::DynamicUserEdgeInfo *v22; // rax
  float v23; // xmm5_4
  float v24; // xmm2_4
  float v25; // xmm6_4
  UFG::DynamicUserEdgeInfo *v26; // rax
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm6_4
  float v32; // xmm3_4
  UFG::DynamicUserEdgeInfo *v33; // rax
  float v34; // xmm6_4
  float v35; // xmm2_4
  UFG::DynamicUserEdgeInfo *v36; // rax
  float v37; // xmm6_4
  float v38; // xmm3_4
  float v39; // xmm4_4
  UFG::DynamicUserEdgeInfo *v40; // rax
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm6_4
  hkQuaternionf v44; // [rsp+20h] [rbp-78h]
  hkVector4f v45; // [rsp+30h] [rbp-68h]
  hkTransformf v46; // [rsp+40h] [rbp-58h]

  v2 = transform->v1;
  v3 = transform->v2;
  v4 = this;
  v5 = transform->v3;
  this->m_transform.v0 = transform->v0;
  this->m_transform.v1 = v2;
  this->m_transform.v2 = v3;
  this->m_transform.v3 = v5;
  hkTransformf::set4x4ColumnMajor(&v46, &this->m_transform.v0.x);
  hkQuaternionf::set(&v44, &v46.m_rotation);
  v6 = v4->m_pSilhouette;
  v45.m_quad = (__m128)v46.m_translation;
  v6->m_transform.m_rotation = (hkQuaternionf)v44.m_vec.m_quad;
  v6->m_transform.m_translation = (hkVector4f)v45.m_quad;
  v7 = v4->m_dynamicEdgesLocal.size;
  if ( v7 )
  {
    v8 = 0i64;
    v9 = v7;
    do
    {
      v10 = v4->m_dynamicEdgesLocal.p;
      v11 = v10[v8].m_edgeStartA.x;
      v12 = v10[v8].m_edgeStartA.y;
      v13 = v10[v8].m_edgeStartA.z;
      v14 = v4->m_dynamicEdgesWorld.p;
      v15 = (float)((float)((float)(v12 * v4->m_transform.v1.x) + (float)(v11 * v4->m_transform.v0.x))
                  + (float)(v13 * v4->m_transform.v2.x))
          + v4->m_transform.v3.x;
      v16 = (float)((float)((float)(v12 * v4->m_transform.v1.y) + (float)(v11 * v4->m_transform.v0.y))
                  + (float)(v13 * v4->m_transform.v2.y))
          + v4->m_transform.v3.y;
      v17 = (float)((float)((float)(v11 * v4->m_transform.v0.z) + (float)(v12 * v4->m_transform.v1.z))
                  + (float)(v13 * v4->m_transform.v2.z))
          + v4->m_transform.v3.z;
      v14[v8].m_edgeStartA.x = v15;
      v14[v8].m_edgeStartA.y = v16;
      v14[v8].m_edgeStartA.z = v17;
      v18 = v4->m_dynamicEdgesLocal.p;
      v19 = v18[v8].m_edgeEndA.x;
      v20 = v18[v8].m_edgeEndA.y;
      v21 = v18[v8].m_edgeEndA.z;
      v22 = v4->m_dynamicEdgesWorld.p;
      v23 = (float)((float)((float)(v20 * v4->m_transform.v1.x) + (float)(v19 * v4->m_transform.v0.x))
                  + (float)(v21 * v4->m_transform.v2.x))
          + v4->m_transform.v3.x;
      v24 = (float)((float)((float)(v20 * v4->m_transform.v1.y) + (float)(v19 * v4->m_transform.v0.y))
                  + (float)(v21 * v4->m_transform.v2.y))
          + v4->m_transform.v3.y;
      v25 = (float)((float)((float)(v19 * v4->m_transform.v0.z) + (float)(v20 * v4->m_transform.v1.z))
                  + (float)(v21 * v4->m_transform.v2.z))
          + v4->m_transform.v3.z;
      v22[v8].m_edgeEndA.x = v23;
      v22[v8].m_edgeEndA.y = v24;
      v22[v8].m_edgeEndA.z = v25;
      v26 = v4->m_dynamicEdgesLocal.p;
      v27 = v26[v8].m_edgeStartB.z;
      v28 = (float)((float)((float)(v26[v8].m_edgeStartB.y * v4->m_transform.v1.x)
                          + (float)(v26[v8].m_edgeStartB.x * v4->m_transform.v0.x))
                  + (float)(v26[v8].m_edgeStartB.z * v4->m_transform.v2.x))
          + v4->m_transform.v3.x;
      v29 = v26[v8].m_edgeStartB.y * v4->m_transform.v1.y;
      v30 = v26[v8].m_edgeStartB.x * v4->m_transform.v0.y;
      v31 = v26[v8].m_edgeStartB.x * v4->m_transform.v0.z;
      v32 = v26[v8].m_edgeStartB.y * v4->m_transform.v1.z;
      v33 = v4->m_dynamicEdgesWorld.p;
      ++v8;
      v34 = (float)((float)(v31 + v32) + (float)(v27 * v4->m_transform.v2.z)) + v4->m_transform.v3.z;
      v35 = (float)((float)(v29 + v30) + (float)(v27 * v4->m_transform.v2.y)) + v4->m_transform.v3.y;
      *((float *)&v33[v8] - 6) = v28;
      *((float *)&v33[v8] - 5) = v35;
      *((float *)&v33[v8] - 4) = v34;
      v36 = v4->m_dynamicEdgesLocal.p;
      v37 = *((float *)&v36[v8] - 3);
      v38 = *((float *)&v36[v8] - 2);
      v39 = *((float *)&v36[v8] - 1);
      v40 = v4->m_dynamicEdgesWorld.p;
      v41 = (float)((float)((float)(v38 * v4->m_transform.v1.x) + (float)(v37 * v4->m_transform.v0.x))
                  + (float)(v39 * v4->m_transform.v2.x))
          + v4->m_transform.v3.x;
      v42 = v37 * v4->m_transform.v0.y;
      v43 = (float)((float)((float)(v37 * v4->m_transform.v0.z) + (float)(v38 * v4->m_transform.v1.z))
                  + (float)(v39 * v4->m_transform.v2.z))
          + v4->m_transform.v3.z;
      *((float *)&v40[v8] - 2) = (float)((float)((float)(v38 * v4->m_transform.v1.y) + v42)
                                       + (float)(v39 * v4->m_transform.v2.y))
                               + v4->m_transform.v3.y;
      *((float *)&v40[v8] - 3) = v41;
      *((float *)&v40[v8] - 1) = v43;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 99
// RVA: 0xF5850
void __fastcall UFG::qMatrix44_To_hkTransform(hkTransformf *out, UFG::qMatrix44 *in)
{
  float v2; // xmm1_4
  hkTransformf *v3; // rbx
  float v4; // xmm0_4
  hkMatrix4f matrixIn; // [rsp+20h] [rbp-138h]
  hkMatrixDecompositionImpl<float>::Decomposition decompOut; // [rsp+60h] [rbp-F8h]

  v2 = in->v0.y;
  v3 = out;
  matrixIn.m_col0.m_quad.m128_i32[0] = LODWORD(in->v0.x);
  *(unsigned __int64 *)((char *)matrixIn.m_col0.m_quad.m128_u64 + 4) = __PAIR__(LODWORD(in->v0.z), LODWORD(v2));
  v4 = in->v1.x;
  matrixIn.m_col0.m_quad.m128_i32[3] = LODWORD(in->v0.w);
  matrixIn.m_col1.m_quad.m128_u64[0] = __PAIR__(LODWORD(in->v1.y), LODWORD(v4));
  matrixIn.m_col1.m_quad.m128_u64[1] = *(_QWORD *)&in->v1.z;
  matrixIn.m_col2 = (hkVector4f)in->v2;
  matrixIn.m_col3 = (hkVector4f)in->v3;
  hkMatrixDecompositionImpl<float>::decomposeMatrix(&matrixIn, &decompOut);
  hkRotationf::set(&v3->m_rotation, &decompOut.m_rotation);
  v3->m_translation = decompOut.m_translation;
}

