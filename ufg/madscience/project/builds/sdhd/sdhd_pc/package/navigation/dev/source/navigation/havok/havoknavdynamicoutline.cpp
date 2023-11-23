// File Line: 14
// RVA: 0xE4540
void __fastcall UFG::HavokNavDynamicOutline::HavokNavDynamicOutline(
        UFG::HavokNavDynamicOutline *this,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *aabbMin,
        UFG::qVector3 *aabbMax,
        UFG::DynamicUserEdgeInfo *edgesInfo,
        unsigned int edgesCount)
{
  __m128 v10; // xmm6
  int m_size; // eax
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
  _QWORD **Value; // rax
  hkaiPointCloudSilhouetteGenerator *v27; // rax
  __int64 v28; // rax
  UFG::DynamicUserEdgeInfo *v29; // rbx
  __int64 v30; // rdi
  hkArrayBase<hkVector4f> array; // [rsp+38h] [rbp-28h] BYREF
  hkaiPointCloudSilhouetteGenerator *result; // [rsp+B0h] [rbp+50h] BYREF

  UFG::NavDynamicOutline::NavDynamicOutline(this);
  this->vfptr = (UFG::NavDynamicOutlineVtbl *)&UFG::HavokNavDynamicOutline::`vftable;
  this->m_dynamicEdgesLocal.p = 0i64;
  *(_QWORD *)&this->m_dynamicEdgesLocal.size = 0i64;
  this->m_dynamicEdgesWorld.p = 0i64;
  *(_QWORD *)&this->m_dynamicEdgesWorld.size = 0i64;
  this->m_pSilhouette = 0i64;
  this->m_firstInsertion = 1;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &array, 8, 16);
  v10 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(aabbMin->x), (__m128)LODWORD(aabbMin->z)),
          _mm_unpacklo_ps((__m128)LODWORD(aabbMin->y), (__m128)0i64));
  m_size = array.m_size;
  if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    m_size = array.m_size;
  }
  array.m_data[m_size].m_quad = v10;
  v12 = array.m_size + 1;
  array.m_size = v12;
  v13 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(aabbMax->x), (__m128)LODWORD(aabbMin->z)),
          _mm_unpacklo_ps((__m128)LODWORD(aabbMin->y), (__m128)0i64));
  if ( v12 == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    v12 = array.m_size;
  }
  array.m_data[v12].m_quad = v13;
  v14 = array.m_size + 1;
  array.m_size = v14;
  v15 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(aabbMax->x), (__m128)LODWORD(aabbMin->z)),
          _mm_unpacklo_ps((__m128)LODWORD(aabbMax->y), (__m128)0i64));
  if ( v14 == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    v14 = array.m_size;
  }
  array.m_data[v14].m_quad = v15;
  v16 = array.m_size + 1;
  array.m_size = v16;
  v17 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(aabbMin->x), (__m128)LODWORD(aabbMin->z)),
          _mm_unpacklo_ps((__m128)LODWORD(aabbMax->y), (__m128)0i64));
  if ( v16 == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    v16 = array.m_size;
  }
  array.m_data[v16].m_quad = v17;
  v18 = array.m_size + 1;
  array.m_size = v18;
  v19 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(aabbMin->x), (__m128)LODWORD(aabbMax->z)),
          _mm_unpacklo_ps((__m128)LODWORD(aabbMin->y), (__m128)0i64));
  if ( v18 == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    v18 = array.m_size;
  }
  array.m_data[v18].m_quad = v19;
  v20 = array.m_size + 1;
  array.m_size = v20;
  v21 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(aabbMax->x), (__m128)LODWORD(aabbMax->z)),
          _mm_unpacklo_ps((__m128)LODWORD(aabbMin->y), (__m128)0i64));
  if ( v20 == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    v20 = array.m_size;
  }
  array.m_data[v20].m_quad = v21;
  v22 = array.m_size + 1;
  array.m_size = v22;
  v23 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(aabbMax->x), (__m128)LODWORD(aabbMax->z)),
          _mm_unpacklo_ps((__m128)LODWORD(aabbMax->y), (__m128)0i64));
  if ( v22 == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    v22 = array.m_size;
  }
  array.m_data[v22].m_quad = v23;
  v24 = array.m_size + 1;
  array.m_size = v24;
  v25 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(aabbMin->x), (__m128)LODWORD(aabbMax->z)),
          _mm_unpacklo_ps((__m128)LODWORD(aabbMax->y), (__m128)0i64));
  if ( v24 == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    v24 = array.m_size;
  }
  array.m_data[v24].m_quad = v25;
  ++array.m_size;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (hkaiPointCloudSilhouetteGenerator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                               Value[11],
                                               160i64);
  result = v27;
  if ( v27 )
    hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(v27);
  else
    v28 = 0i64;
  this->m_pSilhouette = (hkaiPointCloudSilhouetteGenerator *)v28;
  *(_DWORD *)(v28 + 24) = 1036831949;
  hkaiPointCloudSilhouetteGenerator::setLocalPoints(this->m_pSilhouette, &array);
  if ( edgesCount )
  {
    v29 = edgesInfo;
    v30 = edgesCount;
    do
    {
      UFG::qArray<UFG::DynamicUserEdgeInfo,0>::Add(&this->m_dynamicEdgesLocal, v29, "qArray.Add");
      UFG::qArray<UFG::DynamicUserEdgeInfo,0>::Add(&this->m_dynamicEdgesWorld, v29++, "qArray.Add");
      --v30;
    }
    while ( v30 );
  }
  UFG::HavokNavDynamicOutline::UpdateTransform(this, transform);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      16 * array.m_capacityAndFlags);
}

// File Line: 48
// RVA: 0xE5D60
void __fastcall UFG::HavokNavDynamicOutline::~HavokNavDynamicOutline(UFG::HavokNavDynamicOutline *this)
{
  UFG::DynamicUserEdgeInfo *p; // rcx
  UFG::DynamicUserEdgeInfo *v3; // rcx

  this->vfptr = (UFG::NavDynamicOutlineVtbl *)&UFG::HavokNavDynamicOutline::`vftable;
  hkReferencedObject::removeReference(this->m_pSilhouette);
  this->m_pSilhouette = 0i64;
  p = this->m_dynamicEdgesWorld.p;
  if ( p )
    operator delete[](p);
  this->m_dynamicEdgesWorld.p = 0i64;
  *(_QWORD *)&this->m_dynamicEdgesWorld.size = 0i64;
  v3 = this->m_dynamicEdgesLocal.p;
  if ( v3 )
    operator delete[](v3);
  this->m_dynamicEdgesLocal.p = 0i64;
  *(_QWORD *)&this->m_dynamicEdgesLocal.size = 0i64;
  UFG::NavDynamicOutline::~NavDynamicOutline(this);
}

// File Line: 55
// RVA: 0xF3CB0
void __fastcall UFG::HavokNavDynamicOutline::UpdateTransform(
        UFG::HavokNavDynamicOutline *this,
        UFG::qMatrix44 *transform)
{
  UFG::qVector4 v2; // xmm1
  UFG::qVector4 v3; // xmm2
  UFG::qVector4 v5; // xmm3
  hkaiPointCloudSilhouetteGenerator *m_pSilhouette; // rax
  unsigned int size; // eax
  __int64 v8; // rcx
  __int64 v9; // rdx
  UFG::DynamicUserEdgeInfo *p; // rax
  float x; // xmm6_4
  float y; // xmm3_4
  float z; // xmm4_4
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
  hkQuaternionf v44; // [rsp+20h] [rbp-78h] BYREF
  hkVector4f v45; // [rsp+30h] [rbp-68h]
  hkTransformf v46; // [rsp+40h] [rbp-58h] BYREF

  v2 = transform->v1;
  v3 = transform->v2;
  v5 = transform->v3;
  this->m_transform.v0 = transform->v0;
  this->m_transform.v1 = v2;
  this->m_transform.v2 = v3;
  this->m_transform.v3 = v5;
  hkTransformf::set4x4ColumnMajor(&v46, &this->m_transform.v0.x);
  hkQuaternionf::set(&v44, &v46.m_rotation);
  m_pSilhouette = this->m_pSilhouette;
  v45.m_quad = (__m128)v46.m_translation;
  m_pSilhouette->m_transform.m_rotation = (hkQuaternionf)v44.m_vec.m_quad;
  m_pSilhouette->m_transform.m_translation = (hkVector4f)v45.m_quad;
  size = this->m_dynamicEdgesLocal.size;
  if ( size )
  {
    v8 = 0i64;
    v9 = size;
    do
    {
      p = this->m_dynamicEdgesLocal.p;
      x = p[v8].m_edgeStartA.x;
      y = p[v8].m_edgeStartA.y;
      z = p[v8].m_edgeStartA.z;
      v14 = this->m_dynamicEdgesWorld.p;
      v15 = (float)((float)((float)(y * this->m_transform.v1.x) + (float)(x * this->m_transform.v0.x))
                  + (float)(z * this->m_transform.v2.x))
          + this->m_transform.v3.x;
      v16 = (float)((float)((float)(y * this->m_transform.v1.y) + (float)(x * this->m_transform.v0.y))
                  + (float)(z * this->m_transform.v2.y))
          + this->m_transform.v3.y;
      v17 = (float)((float)((float)(x * this->m_transform.v0.z) + (float)(y * this->m_transform.v1.z))
                  + (float)(z * this->m_transform.v2.z))
          + this->m_transform.v3.z;
      v14[v8].m_edgeStartA.x = v15;
      v14[v8].m_edgeStartA.y = v16;
      v14[v8].m_edgeStartA.z = v17;
      v18 = this->m_dynamicEdgesLocal.p;
      v19 = v18[v8].m_edgeEndA.x;
      v20 = v18[v8].m_edgeEndA.y;
      v21 = v18[v8].m_edgeEndA.z;
      v22 = this->m_dynamicEdgesWorld.p;
      v23 = (float)((float)((float)(v20 * this->m_transform.v1.x) + (float)(v19 * this->m_transform.v0.x))
                  + (float)(v21 * this->m_transform.v2.x))
          + this->m_transform.v3.x;
      v24 = (float)((float)((float)(v20 * this->m_transform.v1.y) + (float)(v19 * this->m_transform.v0.y))
                  + (float)(v21 * this->m_transform.v2.y))
          + this->m_transform.v3.y;
      v25 = (float)((float)((float)(v19 * this->m_transform.v0.z) + (float)(v20 * this->m_transform.v1.z))
                  + (float)(v21 * this->m_transform.v2.z))
          + this->m_transform.v3.z;
      v22[v8].m_edgeEndA.x = v23;
      v22[v8].m_edgeEndA.y = v24;
      v22[v8].m_edgeEndA.z = v25;
      v26 = this->m_dynamicEdgesLocal.p;
      v27 = v26[v8].m_edgeStartB.z;
      v28 = (float)((float)((float)(v26[v8].m_edgeStartB.y * this->m_transform.v1.x)
                          + (float)(v26[v8].m_edgeStartB.x * this->m_transform.v0.x))
                  + (float)(v27 * this->m_transform.v2.x))
          + this->m_transform.v3.x;
      v29 = v26[v8].m_edgeStartB.y * this->m_transform.v1.y;
      v30 = v26[v8].m_edgeStartB.x * this->m_transform.v0.y;
      v31 = v26[v8].m_edgeStartB.x * this->m_transform.v0.z;
      v32 = v26[v8].m_edgeStartB.y * this->m_transform.v1.z;
      v33 = this->m_dynamicEdgesWorld.p;
      ++v8;
      v34 = (float)((float)(v31 + v32) + (float)(v27 * this->m_transform.v2.z)) + this->m_transform.v3.z;
      v35 = (float)((float)(v29 + v30) + (float)(v27 * this->m_transform.v2.y)) + this->m_transform.v3.y;
      v33[v8 - 1].m_edgeStartB.x = v28;
      v33[v8 - 1].m_edgeStartB.y = v35;
      v33[v8 - 1].m_edgeStartB.z = v34;
      v36 = this->m_dynamicEdgesLocal.p;
      v37 = v36[v8 - 1].m_edgeEndB.x;
      v38 = v36[v8 - 1].m_edgeEndB.y;
      v39 = v36[v8 - 1].m_edgeEndB.z;
      v40 = this->m_dynamicEdgesWorld.p;
      v41 = (float)((float)((float)(v38 * this->m_transform.v1.x) + (float)(v37 * this->m_transform.v0.x))
                  + (float)(v39 * this->m_transform.v2.x))
          + this->m_transform.v3.x;
      v42 = v37 * this->m_transform.v0.y;
      v43 = (float)((float)((float)(v37 * this->m_transform.v0.z) + (float)(v38 * this->m_transform.v1.z))
                  + (float)(v39 * this->m_transform.v2.z))
          + this->m_transform.v3.z;
      v40[v8 - 1].m_edgeEndB.y = (float)((float)((float)(v38 * this->m_transform.v1.y) + v42)
                                       + (float)(v39 * this->m_transform.v2.y))
                               + this->m_transform.v3.y;
      v40[v8 - 1].m_edgeEndB.x = v41;
      v40[v8 - 1].m_edgeEndB.z = v43;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 99
// RVA: 0xF5850
void __fastcall UFG::qMatrix44_To_hkTransform(hkTransformf *out, UFG::qMatrix44 *in)
{
  float y; // xmm1_4
  float x; // xmm0_4
  hkMatrix4f matrixIn; // [rsp+20h] [rbp-138h] BYREF
  hkMatrixDecompositionImpl<float>::Decomposition decompOut; // [rsp+60h] [rbp-F8h] BYREF

  y = in->v0.y;
  matrixIn.m_col0.m_quad.m128_i32[0] = LODWORD(in->v0.x);
  *(unsigned __int64 *)((char *)matrixIn.m_col0.m_quad.m128_u64 + 4) = __PAIR64__(LODWORD(in->v0.z), LODWORD(y));
  x = in->v1.x;
  matrixIn.m_col0.m_quad.m128_i32[3] = LODWORD(in->v0.w);
  matrixIn.m_col1.m_quad.m128_u64[0] = __PAIR64__(LODWORD(in->v1.y), LODWORD(x));
  matrixIn.m_col1.m_quad.m128_u64[1] = *(_QWORD *)&in->v1.z;
  matrixIn.m_col2 = (hkVector4f)in->v2;
  matrixIn.m_col3 = (hkVector4f)in->v3;
  hkMatrixDecompositionImpl<float>::decomposeMatrix(&matrixIn, &decompOut);
  hkRotationf::set(&out->m_rotation, &decompOut.m_rotation);
  out->m_translation = decompOut.m_translation;
}

