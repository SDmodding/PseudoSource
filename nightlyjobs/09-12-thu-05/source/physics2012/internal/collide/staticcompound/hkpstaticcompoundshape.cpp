// File Line: 39
// RVA: 0xDC29F0
void __fastcall hkpStaticCompoundShape::hkpStaticCompoundShape(hkpStaticCompoundShape *this, hkpShapeContainer::ReferencePolicy ref)
{
  __m128 *v2; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1040;
  this->m_userData = 0i64;
  this->m_bvTreeType.m_storage = 2;
  this->m_numBitsForChildShapeKey = -1;
  this->m_referencePolicy = ref;
  this->m_childShapeKeyMask = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpBvTreeShape};
  v2 = (__m128 *)this;
  this->vfptr = (hkpShapeContainerVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpShapeContainer};
  this->m_instances.m_data = 0i64;
  this->m_instances.m_size = 0;
  this->m_instances.m_capacityAndFlags = 2147483648;
  this->m_instanceExtraInfos.m_data = 0i64;
  this->m_instanceExtraInfos.m_size = 0;
  this->m_instanceExtraInfos.m_capacityAndFlags = 2147483648;
  hkpShapeKeyTable::hkpShapeKeyTable(&this->m_disabledLargeShapeKeyTable);
  if ( v2 != (__m128 *)-112i64 )
  {
    v2[7].m128_u64[0] = 0i64;
    v2[7].m128_i32[2] = 0;
    v2[7].m128_i32[3] = 2147483648;
    v2[8] = (__m128)xmmword_141A712A0;
    v2[9] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v2[8]);
  }
}

// File Line: 49
// RVA: 0xDC2AB0
void __fastcall hkpStaticCompoundShape::hkpStaticCompoundShape(hkpStaticCompoundShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpStaticCompoundShape *v2; // rbx
  char v3; // cl
  int flaga; // [rsp+38h] [rbp+10h]

  flaga = flag.m_finishing;
  v2 = this;
  hkpBvTreeShape::hkpBvTreeShape((hkpBvTreeShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpBvTreeShape};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpShapeContainer};
  hkpShapeKeyTable::hkpShapeKeyTable(&v2->m_disabledLargeShapeKeyTable, (hkFinishLoadedObjectFlag)flaga);
  if ( flaga )
  {
    v3 = v2->m_numBitsForChildShapeKey;
    v2->m_type.m_storage = 16;
    v2->m_bvTreeType.m_storage = 2;
    v2->m_referencePolicy = 1;
    if ( v3 < 0 )
      v2->m_childShapeKeyMask = 0;
    else
      v2->m_childShapeKeyMask = (1 << v3) - 1;
  }
}

// File Line: 60
// RVA: 0xDC2B30
void __fastcall hkpStaticCompoundShape::~hkpStaticCompoundShape(hkpStaticCompoundShape *this)
{
  hkpStaticCompoundShape *v1; // rbx
  int v2; // eax
  int v3; // esi
  __int64 v4; // rdi
  hkReferencedObject *v5; // rcx
  int v6; // er8
  int v7; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpBvTreeShape};
  v1 = this;
  this->vfptr = (hkpShapeContainerVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpShapeContainer};
  v2 = *(_DWORD *)&this->m_tree[12];
  *(_DWORD *)&this->m_tree[8] = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)this->m_tree,
      6 * (v2 & 0x3FFFFFFF));
  *(_QWORD *)v1->m_tree = 0i64;
  *(_DWORD *)&v1->m_tree[12] = 2147483648;
  v3 = 0;
  if ( v1->m_instances.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = (hkReferencedObject *)&v1->m_instances.m_data[v4].m_shape->vfptr;
      if ( v5 )
      {
        if ( v1->m_referencePolicy == 1 )
          hkReferencedObject::removeReference(v5);
        v1->m_instances.m_data[v4].m_shape = 0i64;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < v1->m_instances.m_size );
  }
  hkpShapeKeyTable::~hkpShapeKeyTable(&v1->m_disabledLargeShapeKeyTable);
  v6 = v1->m_instanceExtraInfos.m_capacityAndFlags;
  v1->m_instanceExtraInfos.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_instanceExtraInfos.m_data,
      2 * (v6 & 0x3FFFFFFF));
  v1->m_instanceExtraInfos.m_data = 0i64;
  v1->m_instanceExtraInfos.m_capacityAndFlags = 2147483648;
  v7 = v1->m_instances.m_capacityAndFlags;
  v1->m_instances.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_instances.m_data,
      80 * (v7 & 0x3FFFFFFF));
  v1->m_instances.m_data = 0i64;
  v1->m_instances.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 82
// RVA: 0xDC2C80
signed __int64 __fastcall hkpStaticCompoundShape::addInstance(hkpStaticCompoundShape *this, hkpShape *shape, hkQsTransformf *transform)
{
  hkQsTransformf *v3; // r13
  hkpShape *v4; // r12
  hkpStaticCompoundShape *v5; // r14
  signed __int64 result; // rax
  signed int v7; // ebp
  char v8; // si
  signed int v9; // edi
  __int64 v10; // r15
  unsigned int v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int i; // ebx
  unsigned int v15; // eax
  signed int v16; // ecx
  int j; // eax
  char v18; // dl
  __int64 v19; // rcx
  signed __int64 v20; // rdx
  hkErrStream v21; // [rsp+20h] [rbp-248h]
  char buf; // [rsp+40h] [rbp-228h]
  hkpStaticCompoundShape *v23; // [rsp+270h] [rbp+8h]

  v23 = this;
  v3 = transform;
  v4 = shape;
  v5 = this;
  if ( *(_DWORD *)&this->m_tree[8] )
  {
    hkErrStream::hkErrStream(&v21, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v21.vfptr, "Shape already baked! Cannot add more instances.");
    if ( (unsigned int)hkError::messageError(356428112, &buf, "Collide\\StaticCompound\\hkpStaticCompoundShape.cpp", 89) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v21.vfptr);
    result = 0xFFFFFFFFi64;
  }
  else
  {
    v7 = 0;
    v8 = 1;
    v9 = 1;
    if ( ((unsigned __int8 (__fastcall *)(hkpShape *))shape->vfptr[1].__first_virtual_table_function__)(shape) )
    {
      v7 = 1;
    }
    else
    {
      v10 = ((__int64 (__fastcall *)(hkpShape *))v4->vfptr[7].__vecDelDtor)(v4);
      v21.vfptr = 0i64;
      *(_DWORD *)&v21.m_memSizeAndFlags = 0;
      *(_DWORD *)(&v21.m_referenceCount + 1) = -1;
      v11 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21,
              (unsigned __int64)v4,
              0xFFFFFFFFui64);
      if ( v11 == -1 )
      {
        v11 = 0;
        v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 16i64))(v10);
        if ( v12 != -1 )
        {
          do
          {
            v13 = v12;
            if ( v11 > v12 )
              v13 = v11;
            v11 = v13;
            v12 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 24i64))(v10, v12);
          }
          while ( v12 != -1 );
          v5 = v23;
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (unsigned __int64)v4,
          v11);
      }
      for ( i = v11 >> 1; i; i >>= 1 )
        ++v8;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v21,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v21);
    }
    if ( !hkQsTransformf::isApproximatelyEqual(v3, &hkQsTransformf_identityStorage, 0.001) )
    {
      v7 |= 2u;
      if ( _mm_movemask_ps(_mm_cmpneqps(v3->m_scale.m_quad, query.m_quad)) & 7 )
      {
        v7 |= 4u;
        v15 = _mm_movemask_ps(_mm_cmpltps(v3->m_scale.m_quad, (__m128)0i64)) & 7;
        if ( v15 <= 7 )
        {
          v16 = 150;
          if ( _bittest(&v16, v15) )
            v7 |= 8u;
        }
      }
    }
    for ( j = (v5->m_instances.m_size + 1) >> 1; j; j >>= 1 )
      ++v9;
    v18 = v8;
    if ( v5->m_numBitsForChildShapeKey > v8 )
      v18 = v5->m_numBitsForChildShapeKey;
    if ( v9 + v18 <= 32 )
    {
      v5->m_numBitsForChildShapeKey = v18;
      if ( v5->m_instances.m_size == (v5->m_instances.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_instances, 80);
      v19 = v5->m_instances.m_size;
      v5->m_instances.m_size = v19 + 1;
      v20 = (signed __int64)&v5->m_instances.m_data[v19];
      *(hkVector4f *)v20 = v3->m_translation;
      *(hkQuaternionf *)(v20 + 16) = v3->m_rotation;
      *(hkVector4f *)(v20 + 32) = v3->m_scale;
      *(_QWORD *)(v20 + 48) = v4;
      *(_DWORD *)(v20 + 44) = 1056964608;
      *(_DWORD *)(v20 + 12) = v7 | 0x3F000000;
      *(_DWORD *)(v20 + 56) = 0;
      *(_DWORD *)(v20 + 60) = -1;
      *(_QWORD *)(v20 + 64) = 0i64;
      if ( v5->m_referencePolicy == 1 )
        hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
      result = (unsigned int)(v5->m_instances.m_size - 1);
    }
    else
    {
      result = 0xFFFFFFFFi64;
    }
  }
  return result;
}

// File Line: 219
// RVA: 0xDC2F60
void __fastcall hkpStaticCompoundShape::bake(hkpStaticCompoundShape *this)
{
  hkArray<hkpStaticCompoundShape::Instance,hkContainerHeapAllocator> *v1; // r10
  hkpStaticCompoundShape *v2; // r13
  int requestedCapacity; // ecx
  char v4; // cl
  unsigned int v5; // edx
  int v6; // er15
  __m128 v7; // xmm6
  __int64 v8; // rsi
  hkpStaticCompoundShape::Instance *v9; // rbx
  __m128 v10; // xmm0
  hkpShape *v11; // rcx
  __m128 v12; // xmm10
  hkpShape *v13; // rcx
  __m128 v14; // xmm9
  hkpShape *v15; // rcx
  __m128 v16; // xmm7
  hkpShape *v17; // rcx
  __m128 v18; // xmm8
  hkpShape *v19; // rcx
  __m128 v20; // xmm6
  __m128 v21; // xmm0
  unsigned int v22; // er14
  hkcdDynamicTree::CodecRawUint *v23; // rdx
  unsigned __int64 v24; // rbx
  hkcdDynamicTree::CodecRawUint *v25; // r9
  __int64 v26; // r12
  hkVector4f v27; // xmm7
  hkVector4f v28; // xmm8
  unsigned int v29; // edx
  __m128 *v30; // r10
  __int64 v31; // rax
  signed __int64 v32; // rdi
  __m128 v33; // xmm9
  __m128 v34; // xmm10
  signed __int64 v35; // rcx
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 *v38; // rcx
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  __m128 v44; // xmm6
  __m128 v45; // xmm5
  __m128 v46; // xmm5
  unsigned __int64 v47; // r11
  float v48; // eax
  signed __int64 v49; // rcx
  __m128 v50; // xmm1
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> v51; // [rsp+30h] [rbp-C8h]
  __int64 v52; // [rsp+48h] [rbp-B0h]
  unsigned int branch; // [rsp+50h] [rbp-A8h]
  hkVector4f direction; // [rsp+60h] [rbp-98h]
  hkAabb v55; // [rsp+70h] [rbp-88h]
  hkcdDynamicTree::CodecRawUint *v56; // [rsp+98h] [rbp-60h]
  __m128 *v57; // [rsp+A0h] [rbp-58h]
  hkQsTransformf transform; // [rsp+A8h] [rbp-50h]
  void *retaddr; // [rsp+1B8h] [rbp+C0h]
  hkResult result; // [rsp+1C0h] [rbp+C8h]

  v1 = &this->m_instances;
  v2 = this;
  requestedCapacity = this->m_instances.m_size;
  if ( requestedCapacity < (v1->m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, 80, 0i64, requestedCapacity);
    v1 = &v2->m_instances;
  }
  v4 = v2->m_numBitsForChildShapeKey;
  v5 = 0;
  v51.m_nodes.m_size = 0;
  v51.m_nodes.m_data = 0i64;
  v51.m_nodes.m_capacityAndFlags = 2147483648;
  v51.m_firstFree = 0;
  branch = 0;
  v52 = 0i64;
  v2->m_childShapeKeyMask = (1 << v4) - 1;
  v6 = 0;
  if ( v2->m_instances.m_size > 0 )
  {
    v7 = (__m128)_xmm;
    v8 = 0i64;
    do
    {
      v9 = v1->m_data;
      direction.m_quad = (__m128)_xmm;
      transform.m_translation = v9[v8].m_transform.m_translation;
      transform.m_rotation = v9[v8].m_transform.m_rotation;
      v10 = v9[v8].m_transform.m_scale.m_quad;
      transform.m_scale = v9[v8].m_transform.m_scale;
      v10.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(
                          v9[v8].m_shape,
                          &transform,
                          &direction);
      v11 = v9[v8].m_shape;
      direction.m_quad = _xmm;
      v12 = v10;
      v10.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(v11, &transform, &direction);
      v13 = v9[v8].m_shape;
      direction.m_quad = _xmm;
      v14 = v10;
      v10.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(v13, &transform, &direction);
      v15 = v9[v8].m_shape;
      direction.m_quad = (__m128)_xmm;
      v16 = v10;
      v10.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(v15, &transform, &direction);
      v17 = v9[v8].m_shape;
      direction.m_quad = v7;
      v18 = _mm_xor_ps(v10, (__m128)(unsigned int)_xmm[0]);
      v10.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(v17, &transform, &direction);
      v19 = v9[v8].m_shape;
      v20 = v10;
      v21 = (__m128)_xmm;
      direction.m_quad = (__m128)_xmm;
      v21.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(v19, &transform, &direction);
      *(__m128 *)((char *)&v55.m_min.m_quad + 8) = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps(v12, v16),
                                                     _mm_unpacklo_ps(v14, (__m128)0i64));
      v55.m_min.m_quad = _mm_unpacklo_ps(
                           _mm_unpacklo_ps(v18, _mm_xor_ps(v21, (__m128)(unsigned int)_xmm[0])),
                           _mm_unpacklo_ps(_mm_xor_ps(v20, (__m128)(unsigned int)_xmm[0]), (__m128)0i64));
      if ( hkAabb::isValid(&v55) )
      {
        v22 = v51.m_firstFree;
        if ( !v51.m_firstFree )
        {
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
            &v51,
            (hkResult *)&retaddr,
            v51.m_firstFree + 1);
          v22 = v51.m_firstFree;
        }
        v23 = v51.m_nodes.m_data;
        v51.m_firstFree = v51.m_nodes.m_data[v22].m_aabb.m_min.m_quad.m128_u32[0];
        v24 = v22;
        v51.m_nodes.m_data[v24].m_children[0] = 0;
        v23[v24].m_children[1] = v6;
        v23[v24].m_aabb.m_min = v55.m_min;
        v23[v24].m_aabb.m_max = *(hkVector4f *)((char *)&v55.m_min + 8);
        v25 = v51.m_nodes.m_data;
        v26 = branch;
        v27.m_quad = (__m128)v51.m_nodes.m_data[v22].m_aabb.m_min;
        v28.m_quad = (__m128)v51.m_nodes.m_data[v22].m_aabb.m_max;
        if ( branch )
        {
          v29 = v51.m_firstFree;
          if ( !v51.m_firstFree )
          {
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
              &v51,
              &result,
              v51.m_firstFree + 1);
            v29 = v51.m_firstFree;
            v25 = v51.m_nodes.m_data;
          }
          v30 = &v25[v26].m_aabb.m_min.m_quad;
          v51.m_firstFree = v25[v29].m_aabb.m_min.m_quad.m128_u32[0];
          v31 = v30[2].m128_u32[1];
          v32 = (signed __int64)&v25[v29];
          if ( (_DWORD)v31 )
          {
            v33 = _mm_add_ps(v28.m_quad, v27.m_quad);
            v34 = _mm_sub_ps(v28.m_quad, v27.m_quad);
            do
            {
              v35 = v30[2].m128_u32[2];
              v36 = _mm_max_ps(v30[1], v28.m_quad);
              *v30 = _mm_min_ps(*v30, v27.m_quad);
              v30[1] = v36;
              v56 = &v25[v31];
              v37 = v56->m_aabb.m_max.m_quad;
              v38 = &v25[v35].m_aabb.m_min.m_quad;
              v25 = v51.m_nodes.m_data;
              v39 = v37;
              v40 = _mm_sub_ps(v37, v56->m_aabb.m_min.m_quad);
              v57 = v38;
              v41 = _mm_add_ps(v40, v34);
              v42 = _mm_sub_ps(_mm_add_ps(v39, v56->m_aabb.m_min.m_quad), v33);
              v43 = _mm_mul_ps(v42, v42);
              v44 = _mm_add_ps(_mm_sub_ps(v38[1], *v38), v34);
              v45 = _mm_sub_ps(_mm_add_ps(v38[1], *v38), v33);
              v46 = _mm_mul_ps(v45, v45);
              v30 = (__m128 *)*(&v56
                              + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 170)))
                                       * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170))))));
              v31 = v30[2].m128_u32[1];
            }
            while ( (_DWORD)v31 );
          }
          v47 = ((unsigned __int64)((unsigned __int128)((v32 - (signed __int64)v25)
                                                      * (signed __int128)3074457345618258603i64) >> 64) >> 63)
              + ((signed __int64)((unsigned __int128)((v32 - (signed __int64)v25)
                                                    * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          v48 = v30[2].m128_f32[0];
          if ( v48 == 0.0 )
            branch = ((unsigned __int64)((unsigned __int128)((v32 - (signed __int64)v25)
                                                           * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                   + ((signed __int64)((unsigned __int128)((v32 - (signed __int64)v25)
                                                         * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          else
            v25->m_children[(v25[LODWORD(v48)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v30 - (char *)v25) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                              + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v30 - (char *)v25) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                          + 12i64 * LODWORD(v48)] = v47;
          *(float *)(v32 + 32) = v30[2].m128_f32[0];
          v49 = (char *)v30 - (char *)v51.m_nodes.m_data;
          *(_DWORD *)(v32 + 40) = v22;
          *(_DWORD *)(v32 + 36) = ((unsigned __int64)((unsigned __int128)(v49 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                + ((signed __int64)((unsigned __int128)(v49 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          v30[2].m128_i32[0] = v47;
          v51.m_nodes.m_data[v22].m_parent = v47;
          v50 = _mm_max_ps(v30[1], v28.m_quad);
          *(__m128 *)v32 = _mm_min_ps(*v30, v27.m_quad);
          *(__m128 *)(v32 + 16) = v50;
        }
        else
        {
          branch = v22;
          v51.m_nodes.m_data[v22].m_parent = 0;
        }
        LODWORD(v52) = v52 + 1;
      }
      v7 = (__m128)_xmm;
      ++v6;
      ++v8;
      v1 = &v2->m_instances;
    }
    while ( v6 < v2->m_instances.m_size );
    v5 = branch;
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v51,
    v5,
    (hkBool)1,
    32,
    16);
  if ( branch )
  {
    v55.m_min.m_quad.m128_u64[0] = 0i64;
    v55.m_min.m_quad.m128_u64[1] = 0x8000000000000000i64;
    *(unsigned __int64 *)((char *)v55.m_max.m_quad.m128_u64 + 4) = 0i64;
    v55.m_max.m_quad.m128_i32[0] = 0;
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>>(
      (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v51,
      (hkcdDynamicTree::DefaultTree48Storage *)&v55);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v55,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v51);
    v51.m_firstFree = v55.m_min.m_quad.m128_u32[2];
    branch = 1;
    v55.m_min.m_quad.m128_i32[2] = 0;
    if ( v55.m_min.m_quad.m128_i32[3] >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        (void *)v55.m_min.m_quad.m128_u64[0],
        48 * (v55.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF));
  }
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::convertFromDynamicTree<hkcdDynamicTree::DefaultTree48Storage>(
    (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6> *)v2->m_tree,
    (hkcdDynamicTree::DefaultTree48Storage *)&v51);
  v51.m_nodes.m_size = 0;
  if ( v51.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v51.m_nodes.m_data,
      48 * (v51.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}nodes.m_size = 0;
  if ( v51.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocato

// File Line: 288
// RVA: 0xDC4630
__int64 __fastcall hkpStaticCompoundShape::getNumChildShapes(hkpStaticCompoundShape *this)
{
  unsigned int v1; // edi
  hkpStaticCompoundShape *v2; // r15
  int v3; // esi
  __int64 v4; // rbp
  unsigned __int64 v5; // r14
  signed int v6; // ebx
  __int64 v7; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v9; // [rsp+20h] [rbp-28h]

  v1 = 0;
  v2 = this;
  v9.m_hashMod = -1;
  v9.m_elem = 0i64;
  v9.m_numElems = 0;
  v3 = 0;
  if ( SLODWORD(this->m_userData) > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = *(_QWORD *)(*(_QWORD *)&v2->m_type.m_storage + v4 + 48);
      v6 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
             &v9,
             v5,
             0xFFFFFFFFFFFFFFFFui64);
      if ( v6 == -1 )
      {
        v7 = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)v5 + 112i64))(v5);
        if ( v7 )
          v6 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 8i64))(v7);
        else
          v6 = 1;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v9,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v5,
          v6);
      }
      ++v3;
      v1 += v6;
      v4 += 80i64;
    }
    while ( v3 < SLODWORD(v2->m_userData) );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v9,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v9);
  return v1;
}

// File Line: 315
// RVA: 0xDC4720
signed __int64 __fastcall hkpStaticCompoundShape::getFirstKey(hkpStaticCompoundShape *this)
{
  int v1; // ebx
  hkpStaticCompoundShape *v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // rax
  unsigned int v5; // eax

  v1 = 0;
  v2 = this;
  if ( SLODWORD(this->m_userData) <= 0 )
    return 0xFFFFFFFFi64;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = (*(__int64 (**)(void))(**(_QWORD **)(*(_QWORD *)&v2->m_type.m_storage + v3 + 48) + 112i64))();
    if ( !v4 )
      break;
    v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 16i64))(v4);
    if ( v5 != -1 )
      return (v1 << LOBYTE(v2->m_memSizeAndFlags)) | v5;
    ++v1;
    v3 += 80i64;
    if ( v1 >= SLODWORD(v2->m_userData) )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)(v1 << LOBYTE(v2->m_memSizeAndFlags));
}

// File Line: 345
// RVA: 0xDC47C0
signed __int64 __fastcall hkpStaticCompoundShape::getNextKey(hkpStaticCompoundShape *this, unsigned int oldKey)
{
  hkpStaticCompoundShape *v2; // rsi
  signed int v3; // ebx
  unsigned int v4; // ebp
  signed __int64 v5; // rdi
  __int64 v6; // rax
  unsigned int i; // eax
  __int64 v9; // rax

  v2 = this;
  v3 = oldKey >> LOBYTE(this->m_memSizeAndFlags);
  v4 = oldKey & *(_DWORD *)(&this->m_referenceCount + 1);
  v5 = 80i64 * v3;
  v6 = (*(__int64 (**)(void))(**(_QWORD **)(v5 + *(_QWORD *)&this->m_type.m_storage + 48) + 112i64))();
  if ( !v6 )
    goto LABEL_5;
  for ( i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v6 + 24i64))(v6, v4);
        ;
        i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9) )
  {
    if ( i != -1 )
      return (v3 << LOBYTE(v2->m_memSizeAndFlags)) | i;
LABEL_5:
    ++v3;
    v5 += 80i64;
    if ( v3 >= SLODWORD(v2->m_userData) )
      break;
    v9 = (*(__int64 (**)(void))(**(_QWORD **)(v5 + *(_QWORD *)&v2->m_type.m_storage + 48) + 112i64))();
    if ( !v9 )
      return (unsigned int)(v3 << LOBYTE(v2->m_memSizeAndFlags));
  }
  return 0xFFFFFFFFi64;
}

// File Line: 391
// RVA: 0xDC3620
void __fastcall hkpStaticCompoundShape::setShapeKeyEnabled(hkpStaticCompoundShape *this, unsigned int key, unsigned int isEnabled)
{
  hkpStaticCompoundShape *v3; // rsi
  unsigned int v4; // er10
  signed int v5; // eax
  unsigned int v6; // ecx
  signed __int64 v7; // r8
  unsigned int *v8; // rdi
  int v9; // ebx
  int v10; // ecx
  char v11; // cl
  signed int v12; // eax

  v3 = this;
  v4 = isEnabled;
  v5 = key >> this->m_numBitsForChildShapeKey;
  v6 = key & this->m_childShapeKeyMask;
  v7 = (signed __int64)&v3->m_instances.m_data[v5];
  v8 = (unsigned int *)(v7 + 12);
  v9 = *(_DWORD *)(v7 + 12) & 0x7F;
  if ( *(_BYTE *)(v7 + 12) & 1 )
  {
    if ( v4 )
      v10 = *(_DWORD *)(v7 + 12) & 0x6F;
    else
      v10 = *(_DWORD *)(v7 + 12) & 0x7F | 0x10;
    *(_DWORD *)(v7 + 12) = v10 | *(_DWORD *)(v7 + 12) & 0xFFFFFF80 | 0x3F000000;
  }
  else if ( v6 >= 0x25 )
  {
    if ( v4 )
    {
      if ( *(_BYTE *)(v7 + 12) & 0x40 )
      {
        hkpShapeKeyTable::remove(&v3->m_disabledLargeShapeKeyTable, key);
        if ( !v3->m_disabledLargeShapeKeyTable.m_occupancyBitField )
        {
          *v8 &= 0xFFFFFF80;
          *v8 |= v9 & 0xFFFFFFBF | 0x3F000000;
        }
      }
    }
    else
    {
      hkpShapeKeyTable::insert(&v3->m_disabledLargeShapeKeyTable, key);
      *v8 = v9 | *v8 & 0xFFFFFFC0 | 0x3F000040;
    }
  }
  else if ( !v4 || *(_BYTE *)(v7 + 12) & 0x20 )
  {
    if ( v6 >= 0xD )
    {
      v7 += 32i64;
      v11 = v6 - 13;
    }
    else
    {
      v11 = v6 + 11;
    }
    v12 = 1 << v11;
    if ( v4 )
    {
      *(_DWORD *)(v7 + 12) = *(_DWORD *)(v7 + 12) & ~v12 | 0x3F000000;
    }
    else
    {
      *(_DWORD *)(v7 + 12) |= v12 | 0x3F000000;
      *v8 &= 0xFFFFFFA0;
      *v8 |= v9 | 0x3F000020;
    }
  }
}

// File Line: 465
// RVA: 0xDC3790
__int64 __usercall hkpStaticCompoundShape::isShapeKeyEnabled@<rax>(hkpStaticCompoundShape *this@<rcx>, unsigned int key@<edx>, __int64 a3@<rbx>)
{
  unsigned int v3; // edi
  hkpStaticCompoundShape::Instance *v4; // rsi
  unsigned int v6; // ebx
  hkpStaticCompoundShape::Instance *v7; // rax
  char v8; // cl
  signed int v9; // edx
  unsigned int v10; // ecx
  bool v11; // zf
  bool v12; // al
  hkpShape *v13; // r8
  int v14; // eax
  __int64 v15; // [rsp+30h] [rbp+8h]

  while ( 1 )
  {
    v3 = key & this->m_childShapeKeyMask;
    v4 = &this->m_instances.m_data[key >> this->m_numBitsForChildShapeKey];
    if ( v4->m_transform.m_translation.m_quad.m128_i8[12] & 0x10 )
      return 0i64;
    v15 = a3;
    v6 = 1;
    if ( v3 >= 0x25 )
    {
      if ( !(v4->m_transform.m_translation.m_quad.m128_i8[12] & 0x40) )
      {
LABEL_13:
        v10 = 1;
        goto LABEL_14;
      }
      v12 = hkpShapeKeyTable::exists(&this->m_disabledLargeShapeKeyTable, key);
      v10 = 0;
      v11 = v12 == 0;
    }
    else
    {
      if ( !(v4->m_transform.m_translation.m_quad.m128_i8[12] & 0x20) )
        goto LABEL_13;
      if ( v3 >= 0xD )
      {
        v7 = (hkpStaticCompoundShape::Instance *)((char *)v4 + 32);
        v8 = v3 - 13;
      }
      else
      {
        v7 = &this->m_instances.m_data[key >> this->m_numBitsForChildShapeKey];
        v8 = v3 + 11;
      }
      v9 = 1 << v8;
      v10 = 0;
      v11 = (v9 & v7->m_transform.m_translation.m_quad.m128_i32[3] & 0xC0FFFFFF) == 0;
    }
    LOBYTE(v10) = v11;
    if ( !v10 )
      return v10;
LABEL_14:
    v13 = v4->m_shape;
    v14 = (unsigned __int8)v13->m_type.m_storage;
    if ( v14 == 8 )
      break;
    if ( v14 != 16 )
      return v10;
    key = v3;
    this = (hkpStaticCompoundShape *)v4->m_shape;
    a3 = v15;
  }
  if ( v3 < 0x100 )
    v6 = *((_DWORD *)&v13[3].m_type.m_storage + ((unsigned __int64)v3 >> 5)) & (1 << (v3 & 0x1F));
  return v6;
}

// File Line: 505
// RVA: 0xDC38A0
void __fastcall hkpStaticCompoundShape::enableAllInstancesAndShapeKeys(hkpStaticCompoundShape *this)
{
  hkpStaticCompoundShape *v1; // rbx
  int v2; // edx
  __int64 v3; // r8
  hkpStaticCompoundShape::Instance *v4; // rax

  v1 = this;
  hkpShapeKeyTable::clear(&this->m_disabledLargeShapeKeyTable);
  v2 = 0;
  if ( v1->m_instances.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->m_instances.m_data;
      ++v2;
      ++v3;
      *((_DWORD *)&v4[v3] - 17) &= 0x78Fu;
      *((_DWORD *)&v4[v3] - 17) |= 0x3F000000u;
      *((_DWORD *)&v4[v3] - 9) = 1056964608;
    }
    while ( v2 < v1->m_instances.m_size );
  }
}

// File Line: 523
// RVA: 0xDC4130
void __fastcall hkpStaticCompoundShape::queryAabb(hkpStaticCompoundShape *this, hkAabb *aabb, hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  hkpStaticCompoundShape *v3; // rdi
  hkArray<unsigned int,hkContainerHeapAllocator> *v4; // rsi
  hkAabb *v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  __int128 v11; // xmm0
  __int128 v12; // xmm1
  hkLifoAllocator *v13; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpStaticCompoundShape_Internals::UnlimitedAabbQuery> *v14; // r9
  hkcdStaticTree::Codec3Axis6 *v15; // rdx
  unsigned __int64 v16; // rcx
  int v17; // eax
  char *v18; // rdi
  signed int v19; // ebx
  hkLifoAllocator *v20; // rax
  int v21; // er8
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  hkcdStaticTree::DefaultTreeStorage6 tree; // [rsp+20h] [rbp-39h]
  __int128 v27; // [rsp+50h] [rbp-9h]
  __int128 v28; // [rsp+60h] [rbp+7h]
  hkpStaticCompoundShape *v29; // [rsp+70h] [rbp+17h]
  __int128 v30; // [rsp+80h] [rbp+27h]
  __int128 v31; // [rsp+90h] [rbp+37h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v32; // [rsp+A0h] [rbp+47h]

  v3 = this;
  v4 = hits;
  v5 = aabb;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtSCS::queryAabb";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = (__int128)v5->m_min;
  v12 = (__int128)v5->m_max;
  v32 = v4;
  v30 = v11;
  v31 = v12;
  v27 = v11;
  v29 = v3;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  v28 = v12;
  tree.m_domain.m_max.m_quad.m128_u64[0] = (unsigned __int64)&v29;
  tree.m_nodes.m_capacityAndFlags = 2147483648;
  tree.m_domain.m_min.m_quad.m128_i32[2] = 64;
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkcdStaticTree::Codec3Axis6 *)v13->m_cur;
  v16 = (unsigned __int64)&v15[512];
  if ( v13->m_slabSize < 3072 || (void *)v16 > v13->m_end )
    v15 = (hkcdStaticTree::Codec3Axis6 *)hkLifoAllocator::allocateFromNewSlab(v13, 3072);
  else
    v13->m_cur = (void *)v16;
  tree.m_nodes.m_data = v15;
  tree.m_domain.m_min.m_quad.m128_u64[0] = (unsigned __int64)v15;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdStaticTree::DefaultTreeStorage6,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpStaticCompoundShape_Internals::UnlimitedAabbQuery>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v3->m_tree,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot> *)&tree.m_domain.m_max,
    v14);
  v17 = tree.m_nodes.m_size;
  v18 = (char *)tree.m_domain.m_min.m_quad.m128_u64[0];
  if ( (hkcdStaticTree::Codec3Axis6 *)tree.m_domain.m_min.m_quad.m128_u64[0] == tree.m_nodes.m_data )
    v17 = 0;
  tree.m_nodes.m_size = v17;
  v19 = (48 * tree.m_domain.m_min.m_quad.m128_i32[2] + 127) & 0xFFFFFF80;
  v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (v19 + 15) & 0xFFFFFFF0;
  if ( v19 > v20->m_slabSize || &v18[v21] != v20->m_cur || v20->m_firstNonLifoEnd == v18 )
    hkLifoAllocator::slowBlockFree(v20, v18, v21);
  else
    v20->m_cur = v18;
  tree.m_nodes.m_size = 0;
  if ( tree.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      48 * (tree.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v24 = __rdtsc();
    v25 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v22[1] = v25;
  }
}

// File Line: 534
// RVA: 0xDC3A30
signed __int64 __fastcall hkpStaticCompoundShape::calcSizeForSpu(hkpStaticCompoundShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  int v3; // edi
  hkpShape::CalcSizeForSpuInput *v4; // r14
  hkpStaticCompoundShape *v5; // rbp
  __int64 v6; // rsi
  hkpStaticCompoundShape::Instance *v7; // rbx
  int v8; // eax

  v3 = 0;
  v4 = input;
  v5 = this;
  if ( this->m_instances.m_size <= 0 )
    return 160i64;
  v6 = 0i64;
  while ( 1 )
  {
    v7 = v5->m_instances.m_data;
    v8 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, signed __int64))v7[v6].m_shape->vfptr[8].__vecDelDtor)(
           v7[v6].m_shape,
           v4,
           256i64);
    if ( v8 == -1 )
      break;
    v7[v6].m_transform.m_translation.m_quad.m128_i32[3] &= 0xFFFFF87F;
    ++v3;
    ++v6;
    *((_DWORD *)&v7[v6] - 17) |= 8 * v8 & 0xFFFFFF80 | 0x3F000000;
    if ( v3 >= v5->m_instances.m_size )
      return 160i64;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 569
// RVA: 0xDC3B80
void __fastcall hkpStaticCompoundShape::getAabb(hkpStaticCompoundShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkpStaticCompoundShape *v4; // rdi
  hkAabb *v5; // rbx
  hkTransformf *v6; // rsi
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkVector4f v12; // xmm1
  __m128 v13; // xmm2
  hkVector4f v14; // xmm1
  hkVector4f v15; // xmm0
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  v4 = this;
  v5 = out;
  v6 = localToWorld;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtSCS::getAabb";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  v12.m_quad = *(__m128 *)&v4->m_tree[32];
  aabb.m_min = *(hkVector4f *)&v4->m_tree[16];
  aabb.m_max = (hkVector4f)v12.m_quad;
  hkAabbUtil::calcAabb(v6, &aabb, &aabb);
  v13 = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  v14.m_quad = _mm_add_ps(aabb.m_max.m_quad, v13);
  v15.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v13);
  v5->m_min = (hkVector4f)v15.m_quad;
  v5->m_max = (hkVector4f)v14.m_quad;
  aabb.m_max = (hkVector4f)v14.m_quad;
  aabb.m_min = (hkVector4f)v15.m_quad;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
}

// File Line: 585
// RVA: 0xDC4310
__int64 __fastcall hkpStaticCompoundShape::queryAabbImpl(hkpStaticCompoundShape *this, hkAabb *aabb, unsigned int *hits, int maxNumKeys)
{
  hkpStaticCompoundShape *v4; // rdi
  int v5; // esi
  unsigned int *v6; // r14
  hkAabb *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  hkLifoAllocator *v15; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkpStaticCompoundShape_Internals::LimitedAabbQuery> *v16; // r9
  hkcdStaticTree::Codec3Axis6 *v17; // rdx
  unsigned __int64 v18; // rcx
  int v19; // eax
  char *v20; // rdi
  signed int v21; // ebx
  hkLifoAllocator *v22; // rax
  int v23; // er8
  unsigned int v24; // ebx
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  hkcdStaticTree::DefaultTreeStorage6 tree; // [rsp+20h] [rbp-39h]
  __int128 v31; // [rsp+50h] [rbp-9h]
  __int128 v32; // [rsp+60h] [rbp+7h]
  unsigned int *v33; // [rsp+70h] [rbp+17h]
  int v34; // [rsp+78h] [rbp+1Fh]
  unsigned int v35; // [rsp+7Ch] [rbp+23h]
  hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot> stackInstance; // [rsp+80h] [rbp+27h]
  __int128 v37; // [rsp+A0h] [rbp+47h]

  v4 = this;
  v5 = maxNumKeys;
  v6 = hits;
  v7 = aabb;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSCS::queryAabbImpl";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (__int128)v7->m_min;
  v14 = (__int128)v7->m_max;
  v34 = v5;
  v31 = v13;
  v32 = v14;
  *(_OWORD *)&stackInstance.m_stack.m_localMemory = v13;
  tree.m_domain.m_max.m_quad.m128_u64[0] = (unsigned __int64)v4;
  v33 = v6;
  v35 = 0;
  v37 = v14;
  stackInstance.m_stack.m_data = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot *)&tree.m_domain.m_max;
  stackInstance.m_stack.m_size = 1;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  tree.m_nodes.m_capacityAndFlags = 2147483648;
  tree.m_domain.m_min.m_quad.m128_i32[2] = 64;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkcdStaticTree::Codec3Axis6 *)v15->m_cur;
  v18 = (unsigned __int64)&v17[512];
  if ( v15->m_slabSize < 3072 || (void *)v18 > v15->m_end )
    v17 = (hkcdStaticTree::Codec3Axis6 *)hkLifoAllocator::allocateFromNewSlab(v15, 3072);
  else
    v15->m_cur = (void *)v18;
  tree.m_nodes.m_data = v17;
  tree.m_domain.m_min.m_quad.m128_u64[0] = (unsigned __int64)v17;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdStaticTree::DefaultTreeStorage6,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkpStaticCompoundShape_Internals::LimitedAabbQuery>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v4->m_tree,
    &tree,
    &stackInstance,
    v16);
  v19 = tree.m_nodes.m_size;
  v20 = (char *)tree.m_domain.m_min.m_quad.m128_u64[0];
  if ( (hkcdStaticTree::Codec3Axis6 *)tree.m_domain.m_min.m_quad.m128_u64[0] == tree.m_nodes.m_data )
    v19 = 0;
  tree.m_nodes.m_size = v19;
  v21 = (48 * tree.m_domain.m_min.m_quad.m128_i32[2] + 127) & 0xFFFFFF80;
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (v21 + 15) & 0xFFFFFFF0;
  if ( v21 > v22->m_slabSize || &v20[v23] != v22->m_cur || v22->m_firstNonLifoEnd == v20 )
    hkLifoAllocator::slowBlockFree(v22, v20, v23);
  else
    v22->m_cur = v20;
  tree.m_nodes.m_size = 0;
  if ( tree.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      48 * (tree.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  v24 = v35;
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v27 = __rdtsc();
    v28 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v28 - 8) = v27;
    v25[1] = v28;
  }
  return v24;
}

// File Line: 597
// RVA: 0xDC4510
void __fastcall hkpStaticCompoundShape::castAabbImpl(hkpStaticCompoundShape *this, hkAabb *from, hkVector4f *to, hkpAabbCastCollector *collector)
{
  hkpStaticCompoundShape *v4; // rsi
  hkpAabbCastCollector *v5; // rbp
  hkAabb *v6; // rdi
  hkAabb *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __m128i v15; // xmm0
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  hkpStaticCompoundShape_Internals::AabbCastQuery *query; // [rsp+28h] [rbp-80h]
  float v21[4]; // [rsp+30h] [rbp-78h]
  hkVector4f v22; // [rsp+40h] [rbp-68h]
  __int128 v23; // [rsp+50h] [rbp-58h]
  __int128 v24; // [rsp+60h] [rbp-48h]
  __int64 v25; // [rsp+70h] [rbp-38h]
  hkVector4f *v26; // [rsp+78h] [rbp-30h]
  __int128 v27; // [rsp+80h] [rbp-28h]
  hkpAabbCastCollector *v28; // [rsp+90h] [rbp-18h]

  v4 = this;
  v5 = collector;
  v6 = (hkAabb *)to;
  v7 = from;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSCS::castAabb";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (__int128)v7->m_min;
  v14 = (__int128)v7->m_max;
  v26 = &transform;
  v23 = v13;
  v15 = (__m128i)v6->m_min;
  v24 = v14;
  v22.m_quad.m128_u64[0] = (unsigned __int64)v4;
  v25 = 0i64;
  v28 = v5;
  _mm_store_si128((__m128i *)&v27, v15);
  LODWORD(query) = (_DWORD)FLOAT_1_0;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkcdStaticTree::DefaultTreeStorage6,hkpStaticCompoundShape_Internals::AabbCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v21,
    (hkSimdFloat32 *)v4->m_tree,
    (hkcdStaticTree::DefaultTreeStorage6 *)v7,
    v6,
    &v22,
    query,
    v21[0]);
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
}

// File Line: 607
// RVA: 0xDC3900
void __fastcall hkpStaticCompoundShape::castAabb(hkpStaticCompoundShape *this, hkpShape *shapeA, hkTransformf *AtoB, hkVector4f *to, hkpAabbCastCollector *collector, float tolerance)
{
  hkpStaticCompoundShape *v6; // rbp
  hkAabb *v7; // rdi
  hkTransformf *v8; // rsi
  hkpShape *v9; // rbx
  _QWORD *v10; // rax
  __int64 v11; // r8
  _QWORD *v12; // rcx
  _QWORD *v13; // r10
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  __m128i v16; // xmm0
  hkBaseObjectVtbl *v17; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  hkpStaticCompoundShape_Internals::AabbCastQuery *query; // [rsp+28h] [rbp-80h]
  float v23[4]; // [rsp+30h] [rbp-78h]
  hkVector4f v24; // [rsp+40h] [rbp-68h]
  hkcdStaticTree::DefaultTreeStorage6 tree; // [rsp+50h] [rbp-58h]
  __int128 v26; // [rsp+80h] [rbp-28h]
  hkpAabbCastCollector *v27; // [rsp+90h] [rbp-18h]
  float v28; // [rsp+98h] [rbp-10h]

  v6 = this;
  v7 = (hkAabb *)to;
  v8 = AtoB;
  v9 = shapeA;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v10[1];
  v13 = v10;
  if ( (unsigned __int64)v12 < v10[3] )
  {
    *v12 = "TtSCS::castAabb";
    v14 = __rdtsc();
    v15 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v13[1] = v15;
  }
  v16 = (__m128i)v7->m_min;
  v27 = collector;
  v17 = v9->vfptr;
  v28 = tolerance;
  _mm_store_si128((__m128i *)&v26, v16);
  v24.m_quad.m128_u64[0] = (unsigned __int64)v6;
  tree.m_domain.m_max.m_quad.m128_u64[0] = (unsigned __int64)v9;
  tree.m_domain.m_max.m_quad.m128_u64[1] = (unsigned __int64)v8;
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkcdStaticTree::DefaultTreeStorage6 *))v17[2].__vecDelDtor)(
    v9,
    v8,
    v11,
    &tree);
  LODWORD(query) = (_DWORD)FLOAT_1_0;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkcdStaticTree::DefaultTreeStorage6,hkpStaticCompoundShape_Internals::AabbCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v23,
    (hkSimdFloat32 *)v6->m_tree,
    &tree,
    v7,
    &v24,
    query,
    v23[0]);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v21 - 8) = v20;
    v18[1] = v21;
  }
}

// File Line: 616
// RVA: 0xDC4880
hkpShape *__usercall hkpStaticCompoundShape::getChildShape@<rax>(hkpStaticCompoundShape *this@<rcx>, unsigned int key@<edx>, char (*buffer)[512]@<r8>, __int128 a4@<xmm9>)
{
  hkpStaticCompoundShape *v4; // rbp
  char (*v5)[512]; // rsi
  unsigned int v6; // ebx
  _QWORD *v7; // rax
  unsigned __int64 v8; // rdx
  _QWORD *v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  unsigned int v13; // er14
  hkVector4f *v14; // rdi
  char *v15; // rbx
  int v16; // ebp
  __int64 v17; // rax
  int v18; // er8
  char *v19; // rcx
  signed __int64 v20; // rdx
  __int64 v21; // rax
  int v22; // er8
  hkQuaternionf v23; // xmm1
  char *v24; // r14
  hkVector4f v25; // xmm0
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm7
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm6
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  __m128 v37; // xmm5
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm5
  __m128 v42; // xmm2
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  __m128 v45; // xmm6
  __m128 v46; // xmm6
  __m128 v47; // xmm3
  __m128 v48; // xmm5
  __m128 v49; // xmm3
  __m128 v50; // xmm4
  __m128 v51; // xmm7
  __m128 v52; // xmm4
  unsigned int v53; // eax
  hkpConvexShape *v54; // rdx
  unsigned int v55; // eax
  signed __int64 v56; // rcx
  __int64 v57; // r9
  char *v58; // r8
  int v59; // eax
  __m128 v60; // xmm2
  __m128 v61; // xmm5
  __m128 v62; // xmm6
  __m128 v63; // xmm1
  __m128 v64; // xmm4
  __m128 v65; // xmm0
  __m128 v66; // xmm5
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm5
  __m128 v70; // xmm1
  __m128 v71; // xmm4
  __m128 v72; // xmm6
  __m128 v73; // xmm0
  __m128 v74; // xmm5
  __m128 v75; // xmm3
  __m128 v76; // xmm2
  __m128 v77; // xmm5
  __m128 v78; // xmm1
  __m128 v79; // xmm6
  __m128 v80; // xmm4
  __m128 v81; // xmm3
  _QWORD *v82; // rax
  _QWORD *v83; // rcx
  _QWORD *v84; // r8
  unsigned __int64 v85; // rax
  signed __int64 v86; // rcx
  hkQsTransformf transform; // [rsp+20h] [rbp-268h]
  char buf; // [rsp+50h] [rbp-238h]
  __int128 v90; // [rsp+250h] [rbp-38h]

  v4 = this;
  v5 = buffer;
  v6 = key;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v7[1];
  v10 = v7;
  if ( (unsigned __int64)v9 < v7[3] )
  {
    *v9 = "TtSCS::getChildShape";
    v11 = __rdtsc();
    v8 = (unsigned __int64)HIDWORD(v11) << 32;
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v6 & *(_DWORD *)(&v4->m_referenceCount + 1);
  v14 = (hkVector4f *)(*(_QWORD *)&v4->m_type.m_storage + 80i64 * (signed int)(v6 >> LOBYTE(v4->m_memSizeAndFlags)));
  v15 = (char *)v14[3].m_quad.m128_u64[0];
  v16 = v14->m_quad.m128_i32[3] & 0x7F;
  if ( !(v14->m_quad.m128_i8[12] & 1) )
  {
    v17 = (*(__int64 (__fastcall **)(unsigned __int64, unsigned __int64, _QWORD *))(*(_QWORD *)v15 + 112i64))(
            v14[3].m_quad.m128_u64[0],
            v8,
            v10);
    v15 = (char *)(*(__int64 (__fastcall **)(__int64, _QWORD, char (*)[512]))(*(_QWORD *)v17 + 40i64))(v17, v13, v5);
  }
  if ( v16 & 2 )
  {
    v18 = (unsigned __int8)v15[16];
    switch ( v18 )
    {
      case 0:
      case 1:
      case 3:
      case 4:
      case 5:
      case 10:
      case 11:
        if ( v5 == (char (*)[512])v15 )
        {
          v19 = &buf;
          v20 = 8i64;
          do
          {
            v21 = *(_QWORD *)v15;
            v19 += 32;
            v15 += 32;
            *((_QWORD *)v19 - 4) = v21;
            *((_QWORD *)v19 - 3) = *((_QWORD *)v15 - 3);
            *((_QWORD *)v19 - 2) = *((_QWORD *)v15 - 2);
            *((_QWORD *)v19 - 1) = *((_QWORD *)v15 - 1);
            --v20;
          }
          while ( v20 );
          v15 = &buf;
        }
        v22 = v18 - 10;
        if ( v22 )
        {
          if ( v22 == 1 )
          {
            v26 = v14[1].m_quad;
            v24 = (char *)*((_QWORD *)v15 + 6);
            v27 = _mm_mul_ps(*((__m128 *)v15 + 4), v14[2].m_quad);
            v28 = _mm_shuffle_ps(v14[1].m_quad, v26, 255);
            v29 = _mm_mul_ps(v27, v26);
            v30 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v26),
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v27));
            v31 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                          _mm_shuffle_ps(v29, v29, 170)),
                        v26),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v28, v28), (__m128)xmmword_141A711B0), v27)),
                    _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v28));
            v32 = v14[1].m_quad;
            v33 = *((__m128 *)v15 + 5);
            v34 = v14[1].m_quad;
            v35 = *((__m128 *)v15 + 5);
            transform.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v31, v31), v14->m_quad);
            v36 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v33);
            v37 = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v32);
            v38 = _mm_mul_ps(v32, v33);
            v39 = _mm_sub_ps(v37, v36);
            v40 = _mm_shuffle_ps(v35, v35, 255);
            v41 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 201), _mm_mul_ps(v33, v28)), _mm_mul_ps(v34, v40));
            v25.m_quad = _mm_mul_ps(*((__m128 *)v15 + 6), v14[2].m_quad);
            transform.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                  v41,
                                                  _mm_unpackhi_ps(
                                                    v41,
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(v40, v28),
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v38, v38, 85),
                                                          _mm_shuffle_ps(v38, v38, 0)),
                                                        _mm_shuffle_ps(v38, v38, 170)))),
                                                  196);
          }
          else
          {
            v23.m_vec.m_quad = (__m128)v14[1];
            v24 = v15;
            transform.m_translation = (hkVector4f)v14->m_quad;
            v25.m_quad = (__m128)v14[2];
            transform.m_rotation = (hkQuaternionf)v23.m_vec.m_quad;
          }
          transform.m_scale = (hkVector4f)v25.m_quad;
        }
        else
        {
          v42 = v14[1].m_quad;
          v24 = (char *)*((_QWORD *)v15 + 6);
          v43 = _mm_mul_ps(*((__m128 *)v15 + 4), v14[2].m_quad);
          v44 = _mm_mul_ps(v14[1].m_quad, v43);
          v45 = v14[1].m_quad;
          v90 = a4;
          v46 = _mm_shuffle_ps(v45, v42, 255);
          v47 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v42),
                  _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v43));
          transform.m_scale.m_quad = _mm_mul_ps(query.m_quad, v14[2].m_quad);
          v48 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                        _mm_shuffle_ps(v44, v44, 170)),
                      v42),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v46, v46), (__m128)xmmword_141A711B0), v43)),
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v46));
          v49 = _mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 255);
          v50 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 201), v42),
                  _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), qi.m_vec.m_quad));
          transform.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v48, v48), v14->m_quad);
          v51 = _mm_mul_ps(qi.m_vec.m_quad, v42);
          v52 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v50, v50, 201), _mm_mul_ps(qi.m_vec.m_quad, v46)),
                  _mm_mul_ps(v42, v49));
          transform.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                v52,
                                                _mm_unpackhi_ps(
                                                  v52,
                                                  _mm_sub_ps(
                                                    _mm_mul_ps(v49, v46),
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_shuffle_ps(v51, v51, 85),
                                                        _mm_shuffle_ps(v51, v51, 0)),
                                                      _mm_shuffle_ps(v51, v51, 170)))),
                                                196);
        }
        v53 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v24 + 144i64))(v24);
        v54 = (hkpConvexShape *)&(*v5)[128];
        v55 = v53 >> 4;
        if ( (signed int)v55 > 0 )
        {
          v56 = (signed __int64)(v24 + 8);
          v57 = v55;
          v58 = (char *)((char *)v54 - v24);
          do
          {
            v59 = *(_DWORD *)(v56 - 8);
            v56 += 16i64;
            *(_DWORD *)&v58[v56 - 24] = v59;
            *(_DWORD *)&v58[v56 - 20] = *(_DWORD *)(v56 - 20);
            *(_DWORD *)&v58[v56 - 16] = *(_DWORD *)(v56 - 16);
            *(_DWORD *)&v58[v56 - 12] = *(_DWORD *)(v56 - 12);
            --v57;
          }
          while ( v57 );
        }
        if ( v5 )
          hkpConvexTransformShape::hkpConvexTransformShape((hkpConvexTransformShape *)v5, v54, &transform, 0);
        v15 = (char *)v5;
        break;
      case 2:
        v60 = v14[1].m_quad;
        v61 = _mm_mul_ps(*((__m128 *)v15 + 3), v14[2].m_quad);
        v62 = _mm_shuffle_ps(v14[1].m_quad, v60, 255);
        v63 = _mm_mul_ps(v61, v60);
        v64 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v60), _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v61));
        v65 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v62, v62), (__m128)xmmword_141A711B0), v61);
        v66 = *((__m128 *)v15 + 4);
        v67 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                      _mm_shuffle_ps(v63, v63, 170)),
                    v60),
                  v65),
                _mm_mul_ps(_mm_shuffle_ps(v64, v64, 201), v62));
        *((__m128 *)v15 + 3) = _mm_add_ps(_mm_add_ps(v67, v67), v14->m_quad);
        v68 = v14[1].m_quad;
        v69 = _mm_mul_ps(v66, v14[2].m_quad);
        v70 = _mm_mul_ps(v69, v68);
        v71 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v68), _mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v69));
        v72 = _mm_shuffle_ps(v14[1].m_quad, v68, 255);
        v73 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v72, v72), (__m128)xmmword_141A711B0), v69);
        v74 = *((__m128 *)v15 + 5);
        v75 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                      _mm_shuffle_ps(v70, v70, 170)),
                    v68),
                  v73),
                _mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v72));
        *((__m128 *)v15 + 4) = _mm_add_ps(_mm_add_ps(v75, v75), v14->m_quad);
        v76 = v14[1].m_quad;
        v77 = _mm_mul_ps(v74, v14[2].m_quad);
        v78 = _mm_mul_ps(v77, v76);
        v79 = _mm_shuffle_ps(v14[1].m_quad, v76, 255);
        v80 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v76), _mm_mul_ps(_mm_shuffle_ps(v76, v76, 201), v77));
        v81 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)),
                      _mm_shuffle_ps(v78, v78, 170)),
                    v76),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v79, v79), (__m128)xmmword_141A711B0), v77)),
                _mm_mul_ps(_mm_shuffle_ps(v80, v80, 201), v79));
        *((__m128 *)v15 + 5) = _mm_add_ps(_mm_add_ps(v81, v81), v14->m_quad);
        break;
      default:
        hkErrStream::hkErrStream((hkErrStream *)&transform, &buf, 512);
        hkOstream::operator<<((hkOstream *)&transform, "Unhandled child shape");
        if ( (unsigned int)hkError::messageError(
                             1587046957,
                             &buf,
                             "Collide\\StaticCompound\\hkpStaticCompoundShape.cpp",
                             751) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&transform);
        break;
    }
  }
  v82 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v83 = (_QWORD *)v82[1];
  v84 = v82;
  if ( (unsigned __int64)v83 < v82[3] )
  {
    *v83 = "Et";
    v85 = __rdtsc();
    v86 = (signed __int64)(v83 + 2);
    *(_DWORD *)(v86 - 8) = v85;
    v84[1] = v86;
  }
  return (hkpShape *)v15;
}

// File Line: 771
// RVA: 0xDC4EA0
__int64 __fastcall hkpStaticCompoundShape::getCollisionFilterInfo(hkpStaticCompoundShape *this, unsigned int key)
{
  hkpStaticCompoundShape *v2; // rdi
  unsigned int v3; // ebx
  unsigned __int64 v4; // rdx
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  unsigned int v9; // esi
  int v10; // eax
  signed __int64 v11; // rbx
  __int64 v12; // rax
  unsigned int v13; // edi
  _QWORD *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx

  v2 = this;
  v3 = key;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)v5[1];
  if ( (unsigned __int64)v6 < v5[3] )
  {
    *v6 = "TtSCS::getCollisionFilterInfo";
    v7 = __rdtsc();
    v4 = (unsigned __int64)HIDWORD(v7) << 32;
    v8 = (signed __int64)(v6 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v5[1] = v8;
  }
  v9 = v3 & *(_DWORD *)(&v2->m_referenceCount + 1);
  v10 = 0;
  v11 = *(_QWORD *)&v2->m_type.m_storage + 80i64 * (signed int)(v3 >> LOBYTE(v2->m_memSizeAndFlags));
  if ( *(_DWORD *)(v11 + 60) && !(*(_BYTE *)(v11 + 12) & 1) )
  {
    v12 = (*(__int64 (__fastcall **)(_QWORD, unsigned __int64, _QWORD *))(**(_QWORD **)(v11 + 48) + 112i64))(
            *(_QWORD *)(v11 + 48),
            v4,
            v5);
    v10 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v12 + 32i64))(v12, v9);
  }
  v13 = *(_DWORD *)(v11 + 56) | v10 & *(_DWORD *)(v11 + 60);
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  v16 = v14;
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v17 = __rdtsc();
    v18 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v18 - 8) = v17;
    v16[1] = v18;
  }
  return v13;
}

// File Line: 797
// RVA: 0xDC3C80
hkBool *__fastcall hkpStaticCompoundShape::castRay(hkpStaticCompoundShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpStaticCompoundShape *v4; // r14
  hkpShapeRayCastOutput *v5; // rsi
  hkpShapeRayCastInput *v6; // rdi
  hkBool *v7; // rbx
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm3
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  hkcdStaticTree::DynamicStorage6 v18; // xmm6
  __m128i v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  hkpRayShapeCollectionFilter *v22; // rcx
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm2
  __m128 v29; // xmm6
  __m128 v30; // xmm1
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  hkpStaticCompoundShape_Internals::RayCastQuery *query; // [rsp+20h] [rbp-D8h]
  __m128 v39; // [rsp+30h] [rbp-C8h]
  __m128 v40; // [rsp+40h] [rbp-B8h]
  __int128 v41; // [rsp+50h] [rbp-A8h]
  __int128 v42; // [rsp+60h] [rbp-98h]
  __m128 *v43; // [rsp+70h] [rbp-88h]
  unsigned int v44; // [rsp+78h] [rbp-80h]
  int v45; // [rsp+88h] [rbp-70h]
  __int64 v46; // [rsp+90h] [rbp-68h]
  __int64 v47; // [rsp+98h] [rbp-60h]
  hkcdStaticTree::DefaultTreeStorage6 tree; // [rsp+A8h] [rbp-50h]
  char v49; // [rsp+D8h] [rbp-20h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSCS::castRay";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v6->m_from.m_quad;
  v13 = *(_OWORD *)&v6->m_filterInfo;
  v14 = *(_OWORD *)&v6->m_collidable;
  v15 = _mm_shuffle_ps((__m128)LODWORD(v5->m_hitFraction), (__m128)LODWORD(v5->m_hitFraction), 0);
  v46 = 0i64;
  v47 = 0i64;
  v16 = v6->m_to.m_quad;
  v41 = v13;
  query = (hkpStaticCompoundShape_Internals::RayCastQuery *)v4;
  v43 = &v5->m_normal.m_quad;
  v44 = LODWORD(v5->m_hitFraction);
  v17 = _mm_shuffle_ps((__m128)v44, (__m128)v44, 0);
  v39 = v12;
  v42 = v14;
  v5->m_hitFraction = 1.0;
  v45 = -1;
  v18 = (hkcdStaticTree::DynamicStorage6)v6->m_from;
  v19 = (__m128i)_mm_sub_ps(v6->m_to.m_quad, v6->m_from.m_quad);
  v40 = _mm_add_ps(_mm_mul_ps(v17, _mm_sub_ps(v16, v12)), v12);
  v20 = _mm_rcp_ps((__m128)v19);
  v21 = _mm_cmpeqps((__m128)0i64, (__m128)v19);
  tree.0 = v18;
  tree.m_domain.m_min.m_quad = _mm_shuffle_ps((__m128)v19, _mm_unpackhi_ps((__m128)v19, v15), 196);
  tree.m_domain.m_max.m_quad = _mm_or_ps(
                                 _mm_and_ps(
                                   _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v19, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                   v21),
                                 _mm_andnot_ps(
                                   v21,
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v19, v20)), v20)));
  tree.m_domain.m_max.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, tree.m_domain.m_min.m_quad)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkcdStaticTree::DefaultTreeStorage6,hkpStaticCompoundShape_Internals::RayCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v49,
    (hkSimdFloat32 *)v4->m_tree,
    &tree,
    (hkcdRay *)&query,
    query);
  if ( v43 )
  {
    v43[1].m128_i32[0] = v44;
    if ( v45 >= 0 )
    {
      v22 = &query->m_input.m_rayShapeCollectionFilter[10 * v45];
      if ( BYTE4(v22[1].vfptr) & 2 )
      {
        if ( BYTE4(v22[1].vfptr) & 4 )
        {
          v23 = *(__m128 *)&v22[4].vfptr;
          v24 = _mm_rcp_ps(v23);
          *v43 = _mm_mul_ps(*v43, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v24)), v24));
          v25 = _mm_mul_ps(*v43, *v43);
          v26 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                  _mm_shuffle_ps(v25, v25, 170));
          v27 = _mm_rsqrt_ps(v26);
          *v43 = _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v26, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                       _mm_mul_ps(*(__m128 *)_xmm, v27))),
                   *v43);
        }
        v28 = *(__m128 *)&v22[2].vfptr;
        v29 = _mm_shuffle_ps(*(__m128 *)&v22[2].vfptr, v28, 255);
        v30 = _mm_mul_ps(*v43, v28);
        v31 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 201), v28),
                _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), *v43));
        v32 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                      _mm_shuffle_ps(v30, v30, 170)),
                    v28),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v29, v29), (__m128)xmmword_141A711B0), *v43)),
                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v29));
        *v43 = _mm_add_ps(v32, v32);
      }
      v7->m_bool = 1;
    }
    else
    {
      v7->m_bool = 0;
    }
  }
  else
  {
    v7->m_bool = 0;
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v35 = __rdtsc();
    v36 = (signed __int64)(v34 + 2);
    *(_DWORD *)(v36 - 8) = v35;
    v33[1] = v36;
  }
  return v7;
}

// File Line: 813
// RVA: 0xDC3F90
void __fastcall hkpStaticCompoundShape::castRayWithCollector(hkpStaticCompoundShape *this, hkpShapeRayCastInput *input, hkpCdBody *body, hkpRayHitCollector *collector)
{
  hkpStaticCompoundShape *v4; // rdi
  hkpRayHitCollector *v5; // rsi
  hkpCdBody *v6; // rbp
  hkpShapeRayCastInput *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkVector4f v13; // xmm0
  __m128 v14; // xmm7
  hkVector4f v15; // xmm1
  __m128 v16; // xmm6
  __m128i v17; // xmm6
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  hkpStaticCompoundShape_Internals::RayCastQuery *query[2]; // [rsp+20h] [rbp-F8h]
  __m128 v27; // [rsp+30h] [rbp-E8h]
  __m128 v28; // [rsp+40h] [rbp-D8h]
  char v29; // [rsp+50h] [rbp-C8h]
  hkcdRay ray; // [rsp+60h] [rbp-B8h]
  __int128 v31; // [rsp+90h] [rbp-88h]
  __int128 v32; // [rsp+A0h] [rbp-78h]
  __int64 v33; // [rsp+B0h] [rbp-68h]
  hkpCdBody *v34; // [rsp+D8h] [rbp-40h]
  hkpRayHitCollector *v35; // [rsp+E0h] [rbp-38h]

  v4 = this;
  v5 = collector;
  v6 = body;
  v7 = input;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSCS::castRayWithCollector";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)v7->m_from;
  v14 = v7->m_from.m_quad;
  v15.m_quad = (__m128)v7->m_to;
  ray.m_origin.m_quad.m128_u64[0] = (unsigned __int64)v4;
  v16 = v7->m_to.m_quad;
  ray.m_direction = (hkVector4f)v13.m_quad;
  v33 = 0i64;
  v34 = v6;
  v35 = v5;
  v17 = (__m128i)_mm_sub_ps(v16, v14);
  v18 = *(_OWORD *)&v7->m_filterInfo;
  ray.m_invDirection = (hkVector4f)v15.m_quad;
  v19 = *(_OWORD *)&v7->m_collidable;
  v31 = v18;
  v32 = v19;
  *(__m128 *)query = v14;
  v20 = _mm_rcp_ps((__m128)v17);
  v21 = _mm_cmpeqps((__m128)0i64, (__m128)v17);
  v27 = _mm_shuffle_ps((__m128)v17, _mm_unpackhi_ps((__m128)v17, ::query.m_quad), 196);
  v28 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v17, 0x1Fu), 0x1Fu), (__m128)_xmm), v21),
          _mm_andnot_ps(v21, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, (__m128)v17)), v20)));
  v28.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v27)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkcdStaticTree::DefaultTreeStorage6,hkpStaticCompoundShape_Internals::RayCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v29,
    (hkSimdFloat32 *)v4->m_tree,
    (hkcdStaticTree::DefaultTreeStorage6 *)query,
    &ray,
    (hkpStaticCompoundShape_Internals::RayCastQuery *)v14.m128_u64[0]);
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v24 = __rdtsc();
    v25 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v22[1] = v25;
  }
}

// File Line: 825
// RVA: 0xDC3AE0
float __fastcall hkpStaticCompoundShape::getMaximumProjection(hkpStaticCompoundShape *this, hkVector4f *direction)
{
  int v2; // ebx
  float v3; // xmm6_4
  hkVector4f *v4; // rbp
  hkpStaticCompoundShape *v5; // rsi
  __int64 v6; // rdi
  hkpStaticCompoundShape::Instance *v7; // rcx
  float v8; // xmm0_4
  hkQsTransformf transform; // [rsp+20h] [rbp-48h]

  v2 = 0;
  v3 = FLOAT_N3_40282e38;
  v4 = direction;
  v5 = this;
  if ( this->m_instances.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = v5->m_instances.m_data;
      transform.m_translation = v7[v6].m_transform.m_translation;
      transform.m_rotation = v7[v6].m_transform.m_rotation;
      transform.m_scale = v7[v6].m_transform.m_scale;
      v8 = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(v7[v6].m_shape, &transform, v4);
      if ( v8 > v3 )
        v3 = v8;
      ++v2;
      ++v6;
    }
    while ( v2 < v5->m_instances.m_size );
  }
  return v3;
}

