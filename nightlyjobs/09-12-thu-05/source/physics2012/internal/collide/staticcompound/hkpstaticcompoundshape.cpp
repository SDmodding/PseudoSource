// File Line: 39
// RVA: 0xDC29F0
void __fastcall hkpStaticCompoundShape::hkpStaticCompoundShape(
        hkpStaticCompoundShape *this,
        hkpShapeContainer::ReferencePolicy ref)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1040;
  this->m_userData = 0i64;
  this->m_bvTreeType.m_storage = 2;
  this->m_numBitsForChildShapeKey = -1;
  this->m_referencePolicy = ref;
  this->m_childShapeKeyMask = 0;
  this->hkpBvTreeShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpBvTreeShape};
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpShapeContainer};
  this->m_instances.m_data = 0i64;
  this->m_instances.m_size = 0;
  this->m_instances.m_capacityAndFlags = 0x80000000;
  this->m_instanceExtraInfos.m_data = 0i64;
  this->m_instanceExtraInfos.m_size = 0;
  this->m_instanceExtraInfos.m_capacityAndFlags = 0x80000000;
  hkpShapeKeyTable::hkpShapeKeyTable(&this->m_disabledLargeShapeKeyTable);
  if ( this != (hkpStaticCompoundShape *)-112i64 )
  {
    *(_QWORD *)this->m_tree = 0i64;
    *(_DWORD *)&this->m_tree[8] = 0;
    *(_DWORD *)&this->m_tree[12] = 0x80000000;
    *(_OWORD *)&this->m_tree[16] = xmmword_141A712A0;
    *(__m128 *)&this->m_tree[32] = _mm_xor_ps(
                                     (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                     *(__m128 *)&this->m_tree[16]);
  }
}

// File Line: 49
// RVA: 0xDC2AB0
void __fastcall hkpStaticCompoundShape::hkpStaticCompoundShape(
        hkpStaticCompoundShape *this,
        hkFinishLoadedObjectFlag flag)
{
  char m_numBitsForChildShapeKey; // cl

  hkpBvTreeShape::hkpBvTreeShape(this, flag);
  this->hkpBvTreeShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpBvTreeShape};
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpShapeContainer};
  hkpShapeKeyTable::hkpShapeKeyTable(&this->m_disabledLargeShapeKeyTable, flag);
  if ( flag.m_finishing )
  {
    m_numBitsForChildShapeKey = this->m_numBitsForChildShapeKey;
    this->m_type.m_storage = 16;
    this->m_bvTreeType.m_storage = 2;
    this->m_referencePolicy = 1;
    if ( m_numBitsForChildShapeKey < 0 )
      this->m_childShapeKeyMask = 0;
    else
      this->m_childShapeKeyMask = (1 << m_numBitsForChildShapeKey) - 1;
  }
}

// File Line: 60
// RVA: 0xDC2B30
void __fastcall hkpStaticCompoundShape::~hkpStaticCompoundShape(hkpStaticCompoundShape *this)
{
  int v2; // eax
  int v3; // esi
  __int64 v4; // rdi
  hkpShape *m_shape; // rcx
  int m_capacityAndFlags; // r8d
  int v7; // eax

  this->hkpBvTreeShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpBvTreeShape};
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStaticCompoundShape::`vftable{for `hkpShapeContainer};
  v2 = *(_DWORD *)&this->m_tree[12];
  *(_DWORD *)&this->m_tree[8] = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)this->m_tree,
      6 * (v2 & 0x3FFFFFFF));
  *(_QWORD *)this->m_tree = 0i64;
  *(_DWORD *)&this->m_tree[12] = 0x80000000;
  v3 = 0;
  if ( this->m_instances.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      m_shape = this->m_instances.m_data[v4].m_shape;
      if ( m_shape )
      {
        if ( this->m_referencePolicy == 1 )
          hkReferencedObject::removeReference(m_shape);
        this->m_instances.m_data[v4].m_shape = 0i64;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_instances.m_size );
  }
  hkpShapeKeyTable::~hkpShapeKeyTable(&this->m_disabledLargeShapeKeyTable);
  m_capacityAndFlags = this->m_instanceExtraInfos.m_capacityAndFlags;
  this->m_instanceExtraInfos.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_instanceExtraInfos.m_data,
      2 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_instanceExtraInfos.m_data = 0i64;
  this->m_instanceExtraInfos.m_capacityAndFlags = 0x80000000;
  v7 = this->m_instances.m_capacityAndFlags;
  this->m_instances.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_instances.m_data,
      80 * (v7 & 0x3FFFFFFF));
  this->m_instances.m_data = 0i64;
  this->m_instances.m_capacityAndFlags = 0x80000000;
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->hkpBvTreeShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 82
// RVA: 0xDC2C80
__int64 __fastcall hkpStaticCompoundShape::addInstance(
        hkpStaticCompoundShape *this,
        hkpShape *shape,
        hkQsTransformf *transform)
{
  hkpStaticCompoundShape *v5; // r14
  int v7; // ebp
  char v8; // si
  int v9; // edi
  __int64 v10; // r15
  unsigned int v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int i; // ebx
  int v15; // ecx
  int j; // eax
  char m_numBitsForChildShapeKey; // dl
  __int64 m_size; // rcx
  hkQuaternionf *v19; // rdx
  AMD_HD3D v20; // [rsp+20h] [rbp-248h] BYREF
  char buf[512]; // [rsp+40h] [rbp-228h] BYREF

  v5 = this;
  if ( *(_DWORD *)&this->m_tree[8] )
  {
    hkErrStream::hkErrStream((hkErrStream *)&v20, buf, 512);
    hkOstream::operator<<((hkOstream *)&v20, "Shape already baked! Cannot add more instances.");
    if ( (unsigned int)hkError::messageError(
                         0x153EA950u,
                         buf,
                         "Collide\\StaticCompound\\hkpStaticCompoundShape.cpp",
                         89) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v20);
    return 0xFFFFFFFFi64;
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
      v10 = ((__int64 (__fastcall *)(hkpShape *))shape->vfptr[7].__vecDelDtor)(shape);
      *(_QWORD *)&v20.mEnableStereo = 0i64;
      v20.mWidth = 0;
      v20.mHeight = -1;
      v11 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v20,
              (unsigned __int64)shape,
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
          v5 = this;
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v20,
          &hkContainerHeapAllocator::s_alloc,
          (unsigned __int64)shape,
          v11);
      }
      for ( i = v11 >> 1; i; i >>= 1 )
        ++v8;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v20,
        &hkContainerHeapAllocator::s_alloc);
      _(&v20);
    }
    if ( !hkQsTransformf::isApproximatelyEqual(transform, &hkQsTransformf_identityStorage, 0.001) )
    {
      v7 |= 2u;
      if ( (_mm_movemask_ps(_mm_cmpneq_ps(transform->m_scale.m_quad, query.m_quad)) & 7) != 0 )
      {
        v7 |= 4u;
        v15 = 150;
        if ( _bittest(&v15, _mm_movemask_ps(_mm_cmplt_ps(transform->m_scale.m_quad, (__m128)0i64)) & 7) )
          v7 |= 8u;
      }
    }
    for ( j = (v5->m_instances.m_size + 1) >> 1; j; j >>= 1 )
      ++v9;
    m_numBitsForChildShapeKey = v8;
    if ( v5->m_numBitsForChildShapeKey > v8 )
      m_numBitsForChildShapeKey = v5->m_numBitsForChildShapeKey;
    if ( v9 + m_numBitsForChildShapeKey <= 32 )
    {
      v5->m_numBitsForChildShapeKey = m_numBitsForChildShapeKey;
      if ( v5->m_instances.m_size == (v5->m_instances.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_instances.m_data, 80);
      m_size = v5->m_instances.m_size;
      v5->m_instances.m_size = m_size + 1;
      v19 = (hkQuaternionf *)&v5->m_instances.m_data[m_size];
      *v19 = (hkQuaternionf)transform->m_translation;
      v19[1] = transform->m_rotation;
      v19[2] = (hkQuaternionf)transform->m_scale;
      v19[3].m_vec.m_quad.m128_u64[0] = (unsigned __int64)shape;
      v19[2].m_vec.m_quad.m128_i32[3] = 1056964608;
      v19->m_vec.m_quad.m128_i32[3] = v7 | 0x3F000000;
      v19[3].m_vec.m_quad.m128_i32[2] = 0;
      v19[3].m_vec.m_quad.m128_i32[3] = -1;
      v19[4].m_vec.m_quad.m128_u64[0] = 0i64;
      if ( v5->m_referencePolicy == 1 )
        hkReferencedObject::addReference(shape);
      return (unsigned int)(v5->m_instances.m_size - 1);
    }
    else
    {
      return 0xFFFFFFFFi64;
    }
  }
}

// File Line: 219
// RVA: 0xDC2F60
void __fastcall hkpStaticCompoundShape::bake(hkpStaticCompoundShape *this)
{
  hkArray<hkpStaticCompoundShape::Instance,hkContainerHeapAllocator> *p_m_instances; // r10
  int requestedCapacity; // ecx
  char m_numBitsForChildShapeKey; // cl
  unsigned int v5; // edx
  int v6; // r15d
  __m128 v7; // xmm6
  __int64 v8; // rsi
  hkpStaticCompoundShape::Instance *m_data; // rbx
  hkVector4f v10; // xmm0
  hkpShape *m_shape; // rcx
  __m128 m_quad; // xmm10
  hkpShape *v13; // rcx
  __m128 v14; // xmm9
  hkpShape *v15; // rcx
  __m128 v16; // xmm7
  hkpShape *v17; // rcx
  __m128 v18; // xmm8
  hkpShape *v19; // rcx
  __m128 v20; // xmm6
  __m128 v21; // xmm0
  unsigned int m_firstFree; // r14d
  hkcdDynamicTree::CodecRawUint *v23; // rdx
  unsigned __int64 v24; // rbx
  hkcdDynamicTree::CodecRawUint *v25; // r9
  __int64 m_root; // r12
  hkVector4f v27; // xmm7
  hkVector4f v28; // xmm8
  unsigned int v29; // edx
  __m128 *p_m_quad; // r10
  __int64 v31; // rax
  hkcdDynamicTree::CodecRawUint *v32; // rdi
  __m128 v33; // xmm9
  __m128 v34; // xmm10
  __int64 v35; // rcx
  __m128 v36; // xmm1
  __m128 *v37; // rcx
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm2
  __m128 v43; // xmm6
  __m128 v44; // xmm5
  __m128 v45; // xmm5
  __int64 v46; // r11
  int v47; // eax
  signed __int64 v48; // rcx
  __m128 v49; // xmm1
  hkcdDynamicTree::DefaultTree48Storage v50; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f direction; // [rsp+60h] [rbp-98h] BYREF
  hkcdDynamicTree::DefaultTree48Storage v52; // [rsp+70h] [rbp-88h] BYREF
  __int64 v53[2]; // [rsp+98h] [rbp-60h]
  hkQsTransformf transform; // [rsp+A8h] [rbp-50h] BYREF
  void *retaddr; // [rsp+1B8h] [rbp+C0h] BYREF
  hkResult result; // [rsp+1C0h] [rbp+C8h] BYREF

  p_m_instances = &this->m_instances;
  requestedCapacity = this->m_instances.m_size;
  if ( requestedCapacity < (p_m_instances->m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reduce(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_instances->m_data,
      80,
      0i64,
      requestedCapacity);
    p_m_instances = &this->m_instances;
  }
  m_numBitsForChildShapeKey = this->m_numBitsForChildShapeKey;
  v5 = 0;
  v50.m_nodes.m_size = 0;
  v50.m_nodes.m_data = 0i64;
  v50.m_nodes.m_capacityAndFlags = 0x80000000;
  v50.m_firstFree = 0;
  v50.m_root = 0;
  *(_QWORD *)&v50.m_numLeaves = 0i64;
  this->m_childShapeKeyMask = (1 << m_numBitsForChildShapeKey) - 1;
  v6 = 0;
  if ( this->m_instances.m_size > 0 )
  {
    v7 = (__m128)_xmm;
    v8 = 0i64;
    do
    {
      m_data = p_m_instances->m_data;
      direction.m_quad = (__m128)_xmm;
      transform = m_data[v8].m_transform;
      v10.m_quad = (__m128)transform.m_scale;
      v10.m_quad.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(
                                 m_data[v8].m_shape,
                                 &transform,
                                 &direction);
      m_shape = m_data[v8].m_shape;
      direction.m_quad = _xmm;
      m_quad = v10.m_quad;
      v10.m_quad.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(
                                 m_shape,
                                 &transform,
                                 &direction);
      v13 = m_data[v8].m_shape;
      direction.m_quad = _xmm;
      v14 = v10.m_quad;
      v10.m_quad.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(
                                 v13,
                                 &transform,
                                 &direction);
      v15 = m_data[v8].m_shape;
      direction.m_quad = (__m128)_xmm;
      v16 = v10.m_quad;
      v10.m_quad.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(
                                 v15,
                                 &transform,
                                 &direction);
      v17 = m_data[v8].m_shape;
      direction.m_quad = v7;
      v18 = _mm_xor_ps(v10.m_quad, (__m128)(unsigned int)_xmm[0]);
      v10.m_quad.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(
                                 v17,
                                 &transform,
                                 &direction);
      v19 = m_data[v8].m_shape;
      v20 = v10.m_quad;
      v21 = (__m128)_xmm;
      direction.m_quad = (__m128)_xmm;
      v21.m128_f32[0] = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(v19, &transform, &direction);
      *(_QWORD *)&v52.m_firstFree = *(unsigned __int128 *)&_mm_unpacklo_ps(
                                                             _mm_unpacklo_ps(m_quad, v16),
                                                             _mm_unpacklo_ps(v14, (__m128)0i64)) >> 64;
      v52.m_nodes = (hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator>)_mm_unpacklo_ps(
                                                                                       _mm_unpacklo_ps(
                                                                                         v18,
                                                                                         _mm_xor_ps(
                                                                                           v21,
                                                                                           (__m128)(unsigned int)_xmm[0])),
                                                                                       _mm_unpacklo_ps(
                                                                                         _mm_xor_ps(
                                                                                           v20,
                                                                                           (__m128)(unsigned int)_xmm[0]),
                                                                                         (__m128)0i64));
      if ( hkAabb::isValid((hkAabb *)&v52) )
      {
        m_firstFree = v50.m_firstFree;
        if ( !v50.m_firstFree )
        {
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
            &v50,
            (hkResult *)&retaddr,
            1);
          m_firstFree = v50.m_firstFree;
        }
        v23 = v50.m_nodes.m_data;
        v50.m_firstFree = v50.m_nodes.m_data[m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
        v24 = m_firstFree;
        v50.m_nodes.m_data[v24].m_children[0] = 0;
        v23[v24].m_children[1] = v6;
        v23[v24].m_aabb.m_min = (hkVector4f)v52.m_nodes;
        v23[v24].m_aabb.m_max = *(hkVector4f *)&v52.m_nodes.m_size;
        v25 = v50.m_nodes.m_data;
        m_root = v50.m_root;
        v27.m_quad = (__m128)v50.m_nodes.m_data[m_firstFree].m_aabb.m_min;
        v28.m_quad = (__m128)v50.m_nodes.m_data[m_firstFree].m_aabb.m_max;
        if ( v50.m_root )
        {
          v29 = v50.m_firstFree;
          if ( !v50.m_firstFree )
          {
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
              &v50,
              &result,
              1);
            v29 = v50.m_firstFree;
            v25 = v50.m_nodes.m_data;
          }
          p_m_quad = &v25[m_root].m_aabb.m_min.m_quad;
          v50.m_firstFree = v25[v29].m_aabb.m_min.m_quad.m128_u32[0];
          v31 = p_m_quad[2].m128_u32[1];
          v32 = &v25[v29];
          if ( (_DWORD)v31 )
          {
            v33 = _mm_add_ps(v28.m_quad, v27.m_quad);
            v34 = _mm_sub_ps(v28.m_quad, v27.m_quad);
            do
            {
              v35 = p_m_quad[2].m128_u32[2];
              v36 = _mm_max_ps(p_m_quad[1], v28.m_quad);
              *p_m_quad = _mm_min_ps(*p_m_quad, v27.m_quad);
              p_m_quad[1] = v36;
              v53[0] = (__int64)&v25[v31];
              v37 = &v25[v35].m_aabb.m_min.m_quad;
              v25 = v50.m_nodes.m_data;
              v38 = *(__m128 *)(v53[0] + 16);
              v39 = _mm_sub_ps(v38, *(__m128 *)v53[0]);
              v53[1] = (__int64)v37;
              v40 = _mm_add_ps(v39, v34);
              v41 = _mm_sub_ps(_mm_add_ps(v38, *(__m128 *)v53[0]), v33);
              v42 = _mm_mul_ps(v41, v41);
              v43 = _mm_add_ps(_mm_sub_ps(v37[1], *v37), v34);
              v44 = _mm_sub_ps(_mm_add_ps(v37[1], *v37), v33);
              v45 = _mm_mul_ps(v44, v44);
              p_m_quad = (__m128 *)v53[(float)((float)((float)(_mm_shuffle_ps(v42, v42, 85).m128_f32[0]
                                                             + _mm_shuffle_ps(v42, v42, 0).m128_f32[0])
                                                     + _mm_shuffle_ps(v42, v42, 170).m128_f32[0])
                                             * (float)((float)(_mm_shuffle_ps(v40, v40, 85).m128_f32[0]
                                                             + _mm_shuffle_ps(v40, v40, 0).m128_f32[0])
                                                     + _mm_shuffle_ps(v40, v40, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v45, v45, 85).m128_f32[0] + _mm_shuffle_ps(v45, v45, 0).m128_f32[0]) + _mm_shuffle_ps(v45, v45, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v43, v43, 85).m128_f32[0] + _mm_shuffle_ps(v43, v43, 0).m128_f32[0]) + _mm_shuffle_ps(v43, v43, 170).m128_f32[0]))];
              v31 = p_m_quad[2].m128_u32[1];
            }
            while ( (_DWORD)v31 );
          }
          v46 = v32 - v25;
          v47 = p_m_quad[2].m128_i32[0];
          if ( v47 )
            v25[v47].m_children[v25[v47].m_children[1] == (unsigned int)(((char *)p_m_quad - (char *)v25) / 48)] = v46;
          else
            v50.m_root = v32 - v25;
          v32->m_parent = p_m_quad[2].m128_u32[0];
          v48 = (char *)p_m_quad - (char *)v50.m_nodes.m_data;
          v32->m_children[1] = m_firstFree;
          v32->m_children[0] = v48 / 48;
          p_m_quad[2].m128_i32[0] = v46;
          v50.m_nodes.m_data[m_firstFree].m_parent = v46;
          v49 = _mm_max_ps(p_m_quad[1], v28.m_quad);
          v32->m_aabb.m_min.m_quad = _mm_min_ps(*p_m_quad, v27.m_quad);
          v32->m_aabb.m_max.m_quad = v49;
        }
        else
        {
          v50.m_root = m_firstFree;
          v50.m_nodes.m_data[m_firstFree].m_parent = 0;
        }
        ++v50.m_numLeaves;
      }
      v7 = (__m128)_xmm;
      ++v6;
      ++v8;
      p_m_instances = &this->m_instances;
    }
    while ( v6 < this->m_instances.m_size );
    v5 = v50.m_root;
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(&v50, v5, (hkBool)1, 32, 16);
  if ( v50.m_root )
  {
    v52.m_nodes.m_data = 0i64;
    *(_QWORD *)&v52.m_nodes.m_size = 0x8000000000000000ui64;
    *(_QWORD *)(&v52.m_firstFree + 1) = 0i64;
    v52.m_firstFree = 0;
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>>(
      &v50,
      &v52);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v52,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v50);
    v50.m_firstFree = v52.m_nodes.m_size;
    v50.m_root = 1;
    v52.m_nodes.m_size = 0;
    if ( v52.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v52.m_nodes.m_data,
        48 * (v52.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  }
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::convertFromDynamicTree<hkcdDynamicTree::DefaultTree48Storage>(
    (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6> *)this->m_tree,
    &v50);
  v50.m_nodes.m_size = 0;
  if ( v50.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v50.m_nodes.m_data,
      48 * (v50.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}
    &v50);
  v50.m_nodes.m_size = 0;
  if ( v50.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v50.m_nodes.m_data,
      48 * (v50.m_nodes.m_capacityAndFlags & 0x3

// File Line: 288
// RVA: 0xDC4630
__int64 __fastcall hkpStaticCompoundShape::getNumChildShapes(hkpStaticCompoundShape *this)
{
  unsigned int v1; // edi
  int v3; // esi
  __int64 v4; // rbp
  unsigned __int64 v5; // r14
  int v6; // ebx
  __int64 v7; // rax
  AMD_HD3D v9; // [rsp+20h] [rbp-28h] BYREF

  v1 = 0;
  v9.mHeight = -1;
  *(_QWORD *)&v9.mEnableStereo = 0i64;
  v9.mWidth = 0;
  v3 = 0;
  if ( SLODWORD(this->m_userData) > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = *(_QWORD *)(*(_QWORD *)&this->m_type.m_storage + v4 + 48);
      v6 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9,
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
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9,
          &hkContainerHeapAllocator::s_alloc,
          v5,
          v6);
      }
      ++v3;
      v1 += v6;
      v4 += 80i64;
    }
    while ( v3 < SLODWORD(this->m_userData) );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9,
    &hkContainerHeapAllocator::s_alloc);
  _(&v9);
  return v1;
}

// File Line: 315
// RVA: 0xDC4720
__int64 __fastcall hkpStaticCompoundShape::getFirstKey(hkpStaticCompoundShape *this)
{
  int v1; // ebx
  __int64 i; // rdi
  __int64 v4; // rcx
  __int64 v5; // rax
  unsigned int v6; // eax

  v1 = 0;
  if ( SLODWORD(this->m_userData) <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = 0i64; ; i += 80i64 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)&this->m_type.m_storage + i + 48);
    v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 112i64))(v4);
    if ( !v5 )
      break;
    v6 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5);
    if ( v6 != -1 )
      return (v1 << LOBYTE(this->m_memSizeAndFlags)) | v6;
    if ( ++v1 >= SLODWORD(this->m_userData) )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)(v1 << LOBYTE(this->m_memSizeAndFlags));
}

// File Line: 345
// RVA: 0xDC47C0
__int64 __fastcall hkpStaticCompoundShape::getNextKey(hkpStaticCompoundShape *this, unsigned int oldKey)
{
  signed int v3; // ebx
  unsigned int v4; // ebp
  __int64 v5; // rdi
  __int64 v6; // rcx
  __int64 v7; // rax
  unsigned int i; // eax
  __int64 v10; // rcx
  __int64 v11; // rax

  v3 = oldKey >> LOBYTE(this->m_memSizeAndFlags);
  v4 = oldKey & *(_DWORD *)(&this->m_referenceCount + 1);
  v5 = 80i64 * v3;
  v6 = *(_QWORD *)(v5 + *(_QWORD *)&this->m_type.m_storage + 48);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 112i64))(v6);
  if ( !v7 )
    goto LABEL_5;
  for ( i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v7 + 24i64))(v7, v4);
        ;
        i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 16i64))(v11) )
  {
    if ( i != -1 )
      return (v3 << LOBYTE(this->m_memSizeAndFlags)) | i;
LABEL_5:
    ++v3;
    v5 += 80i64;
    if ( v3 >= SLODWORD(this->m_userData) )
      break;
    v10 = *(_QWORD *)(v5 + *(_QWORD *)&this->m_type.m_storage + 48);
    v11 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 112i64))(v10);
    if ( !v11 )
      return (unsigned int)(v3 << LOBYTE(this->m_memSizeAndFlags));
  }
  return 0xFFFFFFFFi64;
}

// File Line: 391
// RVA: 0xDC3620
void __fastcall hkpStaticCompoundShape::setShapeKeyEnabled(
        hkpStaticCompoundShape *this,
        unsigned int key,
        unsigned int isEnabled)
{
  unsigned int v5; // eax
  unsigned int v6; // ecx
  hkpStaticCompoundShape::Instance *v7; // r8
  unsigned int *v8; // rdi
  int v9; // ebx
  int v10; // ecx
  char v11; // cl
  int v12; // eax

  v5 = key >> this->m_numBitsForChildShapeKey;
  v6 = key & this->m_childShapeKeyMask;
  v7 = &this->m_instances.m_data[v5];
  v8 = &v7->m_transform.m_translation.m_quad.m128_u32[3];
  v9 = v7->m_transform.m_translation.m_quad.m128_i32[3] & 0x7F;
  if ( (v7->m_transform.m_translation.m_quad.m128_i8[12] & 1) != 0 )
  {
    if ( isEnabled )
      v10 = v7->m_transform.m_translation.m_quad.m128_i32[3] & 0x6F;
    else
      v10 = v7->m_transform.m_translation.m_quad.m128_i32[3] & 0x6F | 0x10;
    v7->m_transform.m_translation.m_quad.m128_i32[3] = v10 | v7->m_transform.m_translation.m_quad.m128_i32[3] & 0xFFFFFF80 | 0x3F000000;
  }
  else if ( v6 >= 0x25 )
  {
    if ( isEnabled )
    {
      if ( (v7->m_transform.m_translation.m_quad.m128_i8[12] & 0x40) != 0 )
      {
        hkpShapeKeyTable::remove(&this->m_disabledLargeShapeKeyTable, key);
        if ( !this->m_disabledLargeShapeKeyTable.m_occupancyBitField )
        {
          *v8 &= 0xFFFFFF80;
          *v8 |= v9 & 0xC0FFFFBF | 0x3F000000;
        }
      }
    }
    else
    {
      hkpShapeKeyTable::insert(&this->m_disabledLargeShapeKeyTable, key);
      *v8 = v9 | *v8 & 0xFFFFFFC0 | 0x3F000040;
    }
  }
  else if ( !isEnabled || (v7->m_transform.m_translation.m_quad.m128_i8[12] & 0x20) != 0 )
  {
    if ( v6 >= 0xD )
    {
      v7 = (hkpStaticCompoundShape::Instance *)((char *)v7 + 32);
      v11 = v6 - 13;
    }
    else
    {
      v11 = v6 + 11;
    }
    v12 = 1 << v11;
    if ( isEnabled )
    {
      v7->m_transform.m_translation.m_quad.m128_i32[3] = v7->m_transform.m_translation.m_quad.m128_i32[3] & ~v12 | 0x3F000000;
    }
    else
    {
      v7->m_transform.m_translation.m_quad.m128_i32[3] |= v12 | 0x3F000000;
      *v8 &= 0xFFFFFFA0;
      *v8 |= v9 | 0x3F000020;
    }
  }
}

// File Line: 465
// RVA: 0xDC3790
__int64 __fastcall hkpStaticCompoundShape::isShapeKeyEnabled(hkpStaticCompoundShape *this, unsigned int key)
{
  __int64 v2; // rbx
  unsigned int v3; // edi
  hkpStaticCompoundShape::Instance *v4; // rsi
  unsigned int v6; // ebx
  hkpStaticCompoundShape::Instance *p_m_scale; // rax
  char v8; // cl
  int v9; // edx
  unsigned int v10; // ecx
  bool v11; // zf
  bool v12; // al
  hkpShape *m_shape; // r8
  int m_storage; // eax
  __int64 v15; // [rsp+30h] [rbp+8h]

  while ( 1 )
  {
    v3 = key & this->m_childShapeKeyMask;
    v4 = &this->m_instances.m_data[key >> this->m_numBitsForChildShapeKey];
    if ( (v4->m_transform.m_translation.m_quad.m128_i8[12] & 0x10) != 0 )
      return 0i64;
    v15 = v2;
    v6 = 1;
    if ( v3 >= 0x25 )
    {
      if ( (v4->m_transform.m_translation.m_quad.m128_i8[12] & 0x40) == 0 )
      {
LABEL_13:
        v10 = 1;
        goto LABEL_14;
      }
      v12 = hkpShapeKeyTable::exists(&this->m_disabledLargeShapeKeyTable, key);
      v10 = 0;
      v11 = !v12;
    }
    else
    {
      if ( (v4->m_transform.m_translation.m_quad.m128_i8[12] & 0x20) == 0 )
        goto LABEL_13;
      if ( v3 >= 0xD )
      {
        p_m_scale = (hkpStaticCompoundShape::Instance *)&v4->m_transform.m_scale;
        v8 = v3 - 13;
      }
      else
      {
        p_m_scale = &this->m_instances.m_data[key >> this->m_numBitsForChildShapeKey];
        v8 = v3 + 11;
      }
      v9 = 1 << v8;
      v10 = 0;
      v11 = (v9 & p_m_scale->m_transform.m_translation.m_quad.m128_i32[3] & 0xC0FFFFFF) == 0;
    }
    LOBYTE(v10) = v11;
    if ( !v10 )
      return v10;
LABEL_14:
    m_shape = v4->m_shape;
    m_storage = (unsigned __int8)m_shape->m_type.m_storage;
    if ( m_storage == 8 )
      break;
    if ( m_storage != 16 )
      return v10;
    key = v3;
    this = (hkpStaticCompoundShape *)v4->m_shape;
    v2 = v15;
  }
  if ( v3 < 0x100 )
    return *((_DWORD *)&m_shape[3].m_type.m_storage + ((unsigned __int64)v3 >> 5)) & (unsigned int)(1 << (v3 & 0x1F));
  return v6;
}

// File Line: 505
// RVA: 0xDC38A0
void __fastcall hkpStaticCompoundShape::enableAllInstancesAndShapeKeys(hkpStaticCompoundShape *this)
{
  int v2; // edx
  __int64 v3; // r8
  hkpStaticCompoundShape::Instance *m_data; // rax

  hkpShapeKeyTable::clear(&this->m_disabledLargeShapeKeyTable);
  v2 = 0;
  if ( this->m_instances.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_data = this->m_instances.m_data;
      ++v2;
      m_data[v3++].m_transform.m_translation.m_quad.m128_i32[3] &= 0x78Fu;
      m_data[v3 - 1].m_transform.m_translation.m_quad.m128_i32[3] |= 0x3F000000u;
      m_data[v3 - 1].m_transform.m_scale.m_quad.m128_i32[3] = 1056964608;
    }
    while ( v2 < this->m_instances.m_size );
  }
}

// File Line: 523
// RVA: 0xDC4130
void __fastcall hkpStaticCompoundShape::queryAabb(
        hkpStaticCompoundShape *this,
        hkAabb *aabb,
        hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkVector4f v11; // xmm0
  hkVector4f v12; // xmm1
  hkLifoAllocator *v13; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpStaticCompoundShape_Internals::UnlimitedAabbQuery> *v14; // r9
  hkcdStaticTree::Codec3Axis6 *m_cur; // rdx
  hkcdStaticTree::Codec3Axis6 *v16; // rcx
  int m_size; // eax
  char *v18; // rdi
  signed int v19; // ebx
  hkLifoAllocator *v20; // rax
  int v21; // r8d
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  hkcdStaticTree::DefaultTreeStorage6 tree; // [rsp+20h] [rbp-39h] BYREF
  __m128 v27; // [rsp+50h] [rbp-9h]
  __m128 v28; // [rsp+60h] [rbp+7h]
  hkpStaticCompoundShape *v29; // [rsp+70h] [rbp+17h] BYREF
  __m128 m_quad; // [rsp+80h] [rbp+27h]
  __m128 v31; // [rsp+90h] [rbp+37h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v32; // [rsp+A0h] [rbp+47h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtSCS::queryAabb";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  v11.m_quad = (__m128)aabb->m_min;
  v12.m_quad = (__m128)aabb->m_max;
  v32 = hits;
  m_quad = v11.m_quad;
  v31 = v12.m_quad;
  v27 = v11.m_quad;
  v29 = this;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  v28 = v12.m_quad;
  tree.m_domain.m_max.m_quad.m128_u64[0] = (unsigned __int64)&v29;
  tree.m_nodes.m_capacityAndFlags = 0x80000000;
  tree.m_domain.m_min.m_quad.m128_i32[2] = 64;
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkcdStaticTree::Codec3Axis6 *)v13->m_cur;
  v16 = m_cur + 512;
  if ( v13->m_slabSize < 3072 || v16 > v13->m_end )
    m_cur = (hkcdStaticTree::Codec3Axis6 *)hkLifoAllocator::allocateFromNewSlab(v13, 3072);
  else
    v13->m_cur = v16;
  tree.m_nodes.m_data = m_cur;
  tree.m_domain.m_min.m_quad.m128_u64[0] = (unsigned __int64)m_cur;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdStaticTree::DefaultTreeStorage6,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpStaticCompoundShape_Internals::UnlimitedAabbQuery>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_tree,
    &tree,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot> *)&tree.m_domain.m_max,
    v14);
  m_size = tree.m_nodes.m_size;
  v18 = (char *)tree.m_domain.m_min.m_quad.m128_u64[0];
  if ( (hkcdStaticTree::Codec3Axis6 *)tree.m_domain.m_min.m_quad.m128_u64[0] == tree.m_nodes.m_data )
    m_size = 0;
  tree.m_nodes.m_size = m_size;
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
      &hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      48 * (tree.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v24 = __rdtsc();
    v25 = v23 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v22[1] = v25;
  }
}

// File Line: 534
// RVA: 0xDC3A30
__int64 __fastcall hkpStaticCompoundShape::calcSizeForSpu(
        hkpStaticCompoundShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  int v3; // edi
  __int64 v6; // rsi
  hkpStaticCompoundShape::Instance *m_data; // rbx
  int v8; // eax

  v3 = 0;
  if ( this->m_instances.m_size <= 0 )
    return 160i64;
  v6 = 0i64;
  while ( 1 )
  {
    m_data = this->m_instances.m_data;
    v8 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, __int64))m_data[v6].m_shape->vfptr[8].__vecDelDtor)(
           m_data[v6].m_shape,
           input,
           256i64);
    if ( v8 == -1 )
      break;
    m_data[v6].m_transform.m_translation.m_quad.m128_i32[3] &= 0xFFFFF87F;
    ++v3;
    m_data[v6++].m_transform.m_translation.m_quad.m128_i32[3] |= (8 * v8) & 0xC0FFFF80 | 0x3F000000;
    if ( v3 >= this->m_instances.m_size )
      return 160i64;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 569
// RVA: 0xDC3B80
void __fastcall hkpStaticCompoundShape::getAabb(
        hkpStaticCompoundShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  _QWORD *Value; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkVector4f v12; // xmm1
  __m128 v13; // xmm2
  hkVector4f v14; // xmm1
  hkVector4f v15; // xmm0
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtSCS::getAabb";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  v12.m_quad = *(__m128 *)&this->m_tree[32];
  aabb.m_min = *(hkVector4f *)&this->m_tree[16];
  aabb.m_max = (hkVector4f)v12.m_quad;
  hkAabbUtil::calcAabb(localToWorld, &aabb, &aabb);
  v13 = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  v14.m_quad = _mm_add_ps(aabb.m_max.m_quad, v13);
  v15.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v13);
  out->m_min = (hkVector4f)v15.m_quad;
  out->m_max = (hkVector4f)v14.m_quad;
  aabb.m_max = (hkVector4f)v14.m_quad;
  aabb.m_min = (hkVector4f)v15.m_quad;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
}

// File Line: 585
// RVA: 0xDC4310
__int64 __fastcall hkpStaticCompoundShape::queryAabbImpl(
        hkpStaticCompoundShape *this,
        hkAabb *aabb,
        unsigned int *hits,
        int maxNumKeys)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  hkLifoAllocator *v15; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkpStaticCompoundShape_Internals::LimitedAabbQuery> *v16; // r9
  hkcdStaticTree::Codec3Axis6 *m_cur; // rdx
  hkcdStaticTree::Codec3Axis6 *v18; // rcx
  int m_size; // eax
  char *v20; // rdi
  signed int v21; // ebx
  hkLifoAllocator *v22; // rax
  int v23; // r8d
  unsigned int v24; // ebx
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  hkcdStaticTree::DefaultTreeStorage6 tree; // [rsp+20h] [rbp-39h] BYREF
  __m128 m_quad; // [rsp+50h] [rbp-9h]
  __m128 v32; // [rsp+60h] [rbp+7h]
  unsigned int *v33; // [rsp+70h] [rbp+17h]
  int v34; // [rsp+78h] [rbp+1Fh]
  unsigned int v35; // [rsp+7Ch] [rbp+23h]
  hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot> stackInstance; // [rsp+80h] [rbp+27h] BYREF
  __m128 v37; // [rsp+A0h] [rbp+47h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSCS::queryAabbImpl";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)aabb->m_min;
  v14.m_quad = (__m128)aabb->m_max;
  v34 = maxNumKeys;
  m_quad = v13.m_quad;
  v32 = v14.m_quad;
  *(hkVector4f *)&stackInstance.m_stack.m_localMemory = (hkVector4f)v13.m_quad;
  tree.m_domain.m_max.m_quad.m128_u64[0] = (unsigned __int64)this;
  v33 = hits;
  v35 = 0;
  v37 = v14.m_quad;
  stackInstance.m_stack.m_data = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot *)&tree.m_domain.m_max;
  stackInstance.m_stack.m_size = 1;
  tree.m_nodes.m_data = 0i64;
  tree.m_nodes.m_size = 0;
  tree.m_nodes.m_capacityAndFlags = 0x80000000;
  tree.m_domain.m_min.m_quad.m128_i32[2] = 64;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkcdStaticTree::Codec3Axis6 *)v15->m_cur;
  v18 = m_cur + 512;
  if ( v15->m_slabSize < 3072 || v18 > v15->m_end )
    m_cur = (hkcdStaticTree::Codec3Axis6 *)hkLifoAllocator::allocateFromNewSlab(v15, 3072);
  else
    v15->m_cur = v18;
  tree.m_nodes.m_data = m_cur;
  tree.m_domain.m_min.m_quad.m128_u64[0] = (unsigned __int64)m_cur;
  tree.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdStaticTree::DefaultTreeStorage6,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage6>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkpStaticCompoundShape_Internals::LimitedAabbQuery>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)this->m_tree,
    &tree,
    &stackInstance,
    v16);
  m_size = tree.m_nodes.m_size;
  v20 = (char *)tree.m_domain.m_min.m_quad.m128_u64[0];
  if ( (hkcdStaticTree::Codec3Axis6 *)tree.m_domain.m_min.m_quad.m128_u64[0] == tree.m_nodes.m_data )
    m_size = 0;
  tree.m_nodes.m_size = m_size;
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
      &hkContainerHeapAllocator::s_alloc,
      tree.m_nodes.m_data,
      48 * (tree.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  v24 = v35;
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v27 = __rdtsc();
    v28 = v26 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v25[1] = v28;
  }
  return v24;
}

// File Line: 597
// RVA: 0xDC4510
void __fastcall hkpStaticCompoundShape::castAabbImpl(
        hkpStaticCompoundShape *this,
        hkcdStaticTree::DefaultTreeStorage6 *from,
        hkAabb *to,
        hkpAabbCastCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  __m128 v15; // xmm0
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  hkpStaticCompoundShape_Internals::AabbCastQuery *query; // [rsp+28h] [rbp-80h]
  float v21[4]; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f v22; // [rsp+40h] [rbp-68h] BYREF
  __m128 m_quad; // [rsp+50h] [rbp-58h]
  __m128 v24; // [rsp+60h] [rbp-48h]
  __int64 v25; // [rsp+70h] [rbp-38h]
  hkVector4f *v26; // [rsp+78h] [rbp-30h]
  __m128 v27; // [rsp+80h] [rbp-28h]
  hkpAabbCastCollector *v28; // [rsp+90h] [rbp-18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSCS::castAabb";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)from->hkcdStaticTree::DynamicStorage6;
  v14.m_quad = (__m128)from->m_domain.m_min;
  v26 = &transform;
  m_quad = v13.m_quad;
  v15 = to->m_min.m_quad;
  v24 = v14.m_quad;
  v22.m_quad.m128_u64[0] = (unsigned __int64)this;
  v25 = 0i64;
  v28 = collector;
  v27 = v15;
  LODWORD(query) = (_DWORD)FLOAT_1_0;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkcdStaticTree::DefaultTreeStorage6,hkpStaticCompoundShape_Internals::AabbCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v21,
    (hkSimdFloat32 *)this->m_tree,
    from,
    to,
    &v22,
    query,
    v21[0]);
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
}

// File Line: 607
// RVA: 0xDC3900
void __fastcall hkpStaticCompoundShape::castAabb(
        hkpStaticCompoundShape *this,
        hkpShape *shapeA,
        hkTransformf *AtoB,
        hkAabb *to,
        hkpAabbCastCollector *collector,
        float tolerance)
{
  _QWORD *Value; // rax
  __int64 v11; // r8
  _QWORD *v12; // rcx
  _QWORD *v13; // r10
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  __m128 m_quad; // xmm0
  hkBaseObjectVtbl *vfptr; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  hkpStaticCompoundShape_Internals::AabbCastQuery *query; // [rsp+28h] [rbp-80h]
  float v23[4]; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f v24; // [rsp+40h] [rbp-68h] BYREF
  hkcdStaticTree::DefaultTreeStorage6 tree; // [rsp+50h] [rbp-58h] BYREF
  __m128 v26; // [rsp+80h] [rbp-28h]
  hkpAabbCastCollector *v27; // [rsp+90h] [rbp-18h]
  float v28; // [rsp+98h] [rbp-10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)Value[1];
  v13 = Value;
  if ( (unsigned __int64)v12 < Value[3] )
  {
    *v12 = "TtSCS::castAabb";
    v14 = __rdtsc();
    v15 = v12 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v13[1] = v15;
  }
  m_quad = to->m_min.m_quad;
  v27 = collector;
  vfptr = shapeA->vfptr;
  v28 = tolerance;
  v26 = m_quad;
  v24.m_quad.m128_u64[0] = (unsigned __int64)this;
  tree.m_domain.m_max.m_quad.m128_u64[0] = (unsigned __int64)shapeA;
  tree.m_domain.m_max.m_quad.m128_u64[1] = (unsigned __int64)AtoB;
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkcdStaticTree::DefaultTreeStorage6 *))vfptr[2].__vecDelDtor)(
    shapeA,
    AtoB,
    v11,
    &tree);
  LODWORD(query) = (_DWORD)FLOAT_1_0;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkcdStaticTree::DefaultTreeStorage6,hkpStaticCompoundShape_Internals::AabbCastQuery>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v23,
    (hkSimdFloat32 *)this->m_tree,
    &tree,
    to,
    &v24,
    query,
    v23[0]);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = v19 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v18[1] = v21;
  }
}

// File Line: 616
// RVA: 0xDC4880
hkpConvexTransformShape *__fastcall hkpStaticCompoundShape::getChildShape(
        hkpStaticCompoundShape *this,
        unsigned int key,
        hkpConvexTransformShape *buffer)
{
  __int128 v3; // xmm9
  _QWORD *Value; // rax
  unsigned __int64 v8; // rdx
  _QWORD *v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  unsigned int v13; // r14d
  __int64 v14; // rdi
  hkpConvexTransformShape *v15; // rbx
  int v16; // ebp
  __int64 v17; // rax
  int m_storage; // r8d
  char *v19; // rcx
  __int64 v20; // rdx
  hkBaseObjectVtbl *vfptr; // rax
  int v22; // r8d
  hkQuaternionf v23; // xmm1
  hkpConvexTransformShape *m_childShape; // r14
  hkVector4f v25; // xmm0
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm7
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm6
  __m128 v32; // xmm3
  __m128 m_quad; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm5
  __m128 v37; // xmm3
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  __m128 v40; // xmm5
  __m128 v41; // xmm2
  __m128 v42; // xmm4
  __m128 v43; // xmm1
  __m128 v44; // xmm6
  __m128 v45; // xmm3
  __m128 v46; // xmm5
  __m128 v47; // xmm3
  __m128 v48; // xmm4
  __m128 v49; // xmm7
  __m128 v50; // xmm4
  unsigned int v51; // eax
  hkpConvexShape *v52; // rdx
  int v53; // eax
  unsigned __int16 *p_m_memSizeAndFlags; // rcx
  __int64 v55; // r9
  char *v56; // r8
  int v57; // eax
  __m128 v58; // xmm2
  __m128 v59; // xmm5
  __m128 v60; // xmm6
  __m128 v61; // xmm1
  __m128 v62; // xmm4
  __m128 v63; // xmm0
  __m128 v64; // xmm5
  __m128 v65; // xmm3
  __m128 v66; // xmm2
  __m128 v67; // xmm5
  __m128 v68; // xmm1
  __m128 v69; // xmm4
  __m128 v70; // xmm6
  __m128 v71; // xmm0
  __m128 v72; // xmm5
  __m128 v73; // xmm3
  __m128 v74; // xmm2
  __m128 v75; // xmm5
  __m128 v76; // xmm1
  __m128 v77; // xmm6
  __m128 v78; // xmm4
  __m128 v79; // xmm3
  _QWORD *v80; // rax
  _QWORD *v81; // rcx
  _QWORD *v82; // r8
  unsigned __int64 v83; // rax
  _QWORD *v84; // rcx
  hkQsTransformf transform; // [rsp+20h] [rbp-268h] BYREF
  char buf[512]; // [rsp+50h] [rbp-238h] BYREF
  __int128 v88; // [rsp+250h] [rbp-38h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSCS::getChildShape";
    v11 = __rdtsc();
    v8 = (unsigned __int64)HIDWORD(v11) << 32;
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13 = key & *(_DWORD *)(&this->m_referenceCount + 1);
  v14 = *(_QWORD *)&this->m_type.m_storage + 80i64 * (int)(key >> LOBYTE(this->m_memSizeAndFlags));
  v15 = *(hkpConvexTransformShape **)(v14 + 48);
  v16 = *(_DWORD *)(v14 + 12) & 0x7F;
  if ( (*(_BYTE *)(v14 + 12) & 1) == 0 )
  {
    v17 = ((__int64 (__fastcall *)(_QWORD, unsigned __int64, _QWORD *))v15->vfptr[7].__vecDelDtor)(
            *(_QWORD *)(v14 + 48),
            v8,
            v10);
    v15 = (hkpConvexTransformShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, hkpConvexTransformShape *))(*(_QWORD *)v17 + 40i64))(
                                       v17,
                                       v13,
                                       buffer);
  }
  if ( (v16 & 2) != 0 )
  {
    m_storage = (unsigned __int8)v15->m_type.m_storage;
    switch ( v15->m_type.m_storage )
    {
      case 0:
      case 1:
      case 3:
      case 4:
      case 5:
      case 0xA:
      case 0xB:
        if ( buffer == v15 )
        {
          v19 = buf;
          v20 = 8i64;
          do
          {
            vfptr = v15->vfptr;
            v19 += 32;
            v15 = (hkpConvexTransformShape *)((char *)v15 + 32);
            *((_QWORD *)v19 - 4) = vfptr;
            *((_QWORD *)v19 - 3) = v15[-1].m_transform.m_scale.m_quad.m128_u64[1];
            *((_QWORD *)v19 - 2) = v15[-1].m_extraScale.m_quad.m128_u64[0];
            *((_QWORD *)v19 - 1) = v15[-1].m_extraScale.m_quad.m128_u64[1];
            --v20;
          }
          while ( v20 );
          v15 = (hkpConvexTransformShape *)buf;
        }
        v22 = m_storage - 10;
        if ( v22 )
        {
          if ( v22 == 1 )
          {
            v26 = *(__m128 *)(v14 + 16);
            m_childShape = (hkpConvexTransformShape *)v15->m_childShape.m_childShape;
            v27 = _mm_mul_ps(v15->m_transform.m_translation.m_quad, *(__m128 *)(v14 + 32));
            v28 = _mm_shuffle_ps(v26, v26, 255);
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
            v32 = v26;
            m_quad = v15->m_transform.m_rotation.m_vec.m_quad;
            v34 = *(__m128 *)(v14 + 16);
            transform.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v31, v31), *(__m128 *)v14);
            v35 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), m_quad);
            v36 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v32);
            v37 = _mm_mul_ps(v32, m_quad);
            v38 = _mm_sub_ps(v36, v35);
            v39 = _mm_shuffle_ps(m_quad, m_quad, 255);
            v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 201), _mm_mul_ps(m_quad, v28)), _mm_mul_ps(v34, v39));
            v25.m_quad = _mm_mul_ps(v15->m_transform.m_scale.m_quad, *(__m128 *)(v14 + 32));
            transform.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                  v40,
                                                  _mm_unpackhi_ps(
                                                    v40,
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(v39, v28),
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v37, v37, 85),
                                                          _mm_shuffle_ps(v37, v37, 0)),
                                                        _mm_shuffle_ps(v37, v37, 170)))),
                                                  196);
          }
          else
          {
            v23.m_vec.m_quad = *(__m128 *)(v14 + 16);
            m_childShape = v15;
            transform.m_translation = *(hkVector4f *)v14;
            v25.m_quad = *(__m128 *)(v14 + 32);
            transform.m_rotation = (hkQuaternionf)v23.m_vec.m_quad;
          }
          transform.m_scale = (hkVector4f)v25.m_quad;
        }
        else
        {
          v41 = *(__m128 *)(v14 + 16);
          m_childShape = (hkpConvexTransformShape *)v15->m_childShape.m_childShape;
          v42 = _mm_mul_ps(v15->m_transform.m_translation.m_quad, *(__m128 *)(v14 + 32));
          v43 = _mm_mul_ps(v41, v42);
          v88 = v3;
          v44 = _mm_shuffle_ps(v41, v41, 255);
          v45 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v41),
                  _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v42));
          transform.m_scale.m_quad = _mm_mul_ps(query.m_quad, *(__m128 *)(v14 + 32));
          v46 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                        _mm_shuffle_ps(v43, v43, 170)),
                      v41),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v44, v44), (__m128)xmmword_141A711B0), v42)),
                  _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v44));
          v47 = _mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 255);
          v48 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 201), v41),
                  _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), qi.m_vec.m_quad));
          transform.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v46, v46), *(__m128 *)v14);
          v49 = _mm_mul_ps(qi.m_vec.m_quad, v41);
          v50 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v48, v48, 201), _mm_mul_ps(qi.m_vec.m_quad, v44)),
                  _mm_mul_ps(v41, v47));
          transform.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                v50,
                                                _mm_unpackhi_ps(
                                                  v50,
                                                  _mm_sub_ps(
                                                    _mm_mul_ps(v47, v44),
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_shuffle_ps(v49, v49, 85),
                                                        _mm_shuffle_ps(v49, v49, 0)),
                                                      _mm_shuffle_ps(v49, v49, 170)))),
                                                196);
        }
        v51 = ((__int64 (__fastcall *)(hkpConvexTransformShape *))m_childShape->vfptr[9].__vecDelDtor)(m_childShape);
        v52 = buffer + 1;
        v53 = v51 >> 4;
        if ( v53 > 0 )
        {
          p_m_memSizeAndFlags = &m_childShape->m_memSizeAndFlags;
          v55 = (unsigned int)v53;
          v56 = (char *)((char *)v52 - (char *)m_childShape);
          do
          {
            v57 = *((_DWORD *)p_m_memSizeAndFlags - 2);
            p_m_memSizeAndFlags += 8;
            *(_DWORD *)((char *)p_m_memSizeAndFlags + (_QWORD)v56 - 24) = v57;
            *(_DWORD *)((char *)p_m_memSizeAndFlags + (_QWORD)v56 - 20) = *((_DWORD *)p_m_memSizeAndFlags - 5);
            *(_DWORD *)((char *)p_m_memSizeAndFlags + (_QWORD)v56 - 16) = *((_DWORD *)p_m_memSizeAndFlags - 4);
            *(_DWORD *)((char *)p_m_memSizeAndFlags + (_QWORD)v56 - 12) = *((_DWORD *)p_m_memSizeAndFlags - 3);
            --v55;
          }
          while ( v55 );
        }
        if ( buffer )
          hkpConvexTransformShape::hkpConvexTransformShape(buffer, v52, &transform, REFERENCE_POLICY_IGNORE);
        v15 = buffer;
        break;
      case 2:
        v58 = *(__m128 *)(v14 + 16);
        v59 = _mm_mul_ps(*(__m128 *)&v15->m_childShape.m_childShape, *(__m128 *)(v14 + 32));
        v60 = _mm_shuffle_ps(v58, v58, 255);
        v61 = _mm_mul_ps(v59, v58);
        v62 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v58), _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v59));
        v63 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v60, v60), (__m128)xmmword_141A711B0), v59);
        v64 = v15->m_transform.m_translation.m_quad;
        v65 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                      _mm_shuffle_ps(v61, v61, 170)),
                    v58),
                  v63),
                _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v60));
        *(__m128 *)&v15->m_childShape.m_childShape = _mm_add_ps(_mm_add_ps(v65, v65), *(__m128 *)v14);
        v66 = *(__m128 *)(v14 + 16);
        v67 = _mm_mul_ps(v64, *(__m128 *)(v14 + 32));
        v68 = _mm_mul_ps(v67, v66);
        v69 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v66), _mm_mul_ps(_mm_shuffle_ps(v66, v66, 201), v67));
        v70 = _mm_shuffle_ps(v66, v66, 255);
        v71 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v70, v70), (__m128)xmmword_141A711B0), v67);
        v72 = v15->m_transform.m_rotation.m_vec.m_quad;
        v73 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                      _mm_shuffle_ps(v68, v68, 170)),
                    v66),
                  v71),
                _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v70));
        v15->m_transform.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v73, v73), *(__m128 *)v14);
        v74 = *(__m128 *)(v14 + 16);
        v75 = _mm_mul_ps(v72, *(__m128 *)(v14 + 32));
        v76 = _mm_mul_ps(v75, v74);
        v77 = _mm_shuffle_ps(v74, v74, 255);
        v78 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v74), _mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), v75));
        v79 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
                      _mm_shuffle_ps(v76, v76, 170)),
                    v74),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v77, v77), (__m128)xmmword_141A711B0), v75)),
                _mm_mul_ps(_mm_shuffle_ps(v78, v78, 201), v77));
        v15->m_transform.m_rotation.m_vec.m_quad = _mm_add_ps(_mm_add_ps(v79, v79), *(__m128 *)v14);
        break;
      default:
        hkErrStream::hkErrStream((hkErrStream *)&transform, buf, 512);
        hkOstream::operator<<((hkOstream *)&transform, "Unhandled child shape");
        if ( (unsigned int)hkError::messageError(
                             0x5E986A2Du,
                             buf,
                             "Collide\\StaticCompound\\hkpStaticCompoundShape.cpp",
                             751) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&transform);
        break;
    }
  }
  v80 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v81 = (_QWORD *)v80[1];
  v82 = v80;
  if ( (unsigned __int64)v81 < v80[3] )
  {
    *v81 = "Et";
    v83 = __rdtsc();
    v84 = v81 + 2;
    *((_DWORD *)v84 - 2) = v83;
    v82[1] = v84;
  }
  return v15;
}

// File Line: 771
// RVA: 0xDC4EA0
__int64 __fastcall hkpStaticCompoundShape::getCollisionFilterInfo(hkpStaticCompoundShape *this, unsigned int key)
{
  unsigned __int64 v4; // rdx
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  unsigned int v9; // esi
  int v10; // eax
  __int64 v11; // rbx
  __int64 v12; // rax
  unsigned int v13; // edi
  _QWORD *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v6 < Value[3] )
  {
    *v6 = "TtSCS::getCollisionFilterInfo";
    v7 = __rdtsc();
    v4 = (unsigned __int64)HIDWORD(v7) << 32;
    v8 = v6 + 2;
    *((_DWORD *)v8 - 2) = v7;
    Value[1] = v8;
  }
  v9 = key & *(_DWORD *)(&this->m_referenceCount + 1);
  v10 = 0;
  v11 = *(_QWORD *)&this->m_type.m_storage + 80i64 * (int)(key >> LOBYTE(this->m_memSizeAndFlags));
  if ( *(_DWORD *)(v11 + 60) && (*(_BYTE *)(v11 + 12) & 1) == 0 )
  {
    v12 = (*(__int64 (__fastcall **)(_QWORD, unsigned __int64, _QWORD *))(**(_QWORD **)(v11 + 48) + 112i64))(
            *(_QWORD *)(v11 + 48),
            v4,
            Value);
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
    v18 = v15 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v16[1] = v18;
  }
  return v13;
}

// File Line: 797
// RVA: 0xDC3C80
hkBool *__fastcall hkpStaticCompoundShape::castRay(
        hkpStaticCompoundShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 m_quad; // xmm3
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __m128 v15; // xmm4
  hkVector4f v16; // xmm2
  __m128 v17; // xmm0
  hkVector4f v18; // xmm6
  __m128i v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __int64 v22; // rcx
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
  _QWORD *v36; // rcx
  hkcdRay query; // [rsp+20h] [rbp-D8h] BYREF
  __int128 v39; // [rsp+50h] [rbp-A8h]
  __int128 v40; // [rsp+60h] [rbp-98h]
  __m128 *p_m_quad; // [rsp+70h] [rbp-88h]
  float m_hitFraction; // [rsp+78h] [rbp-80h]
  int v43; // [rsp+88h] [rbp-70h]
  __int64 v44; // [rsp+90h] [rbp-68h]
  __int64 v45; // [rsp+98h] [rbp-60h]
  hkcdStaticTree::DefaultTreeStorage6 tree; // [rsp+A8h] [rbp-50h] BYREF
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> v47; // [rsp+D8h] [rbp-20h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSCS::castRay";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_quad = input->m_from.m_quad;
  v13 = *(_OWORD *)&input->m_filterInfo;
  v14 = *(_OWORD *)&input->m_collidable;
  v15 = _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0);
  v44 = 0i64;
  v45 = 0i64;
  v16.m_quad = (__m128)input->m_to;
  v39 = v13;
  query.m_origin.m_quad.m128_u64[0] = (unsigned __int64)this;
  p_m_quad = &results->m_normal.m_quad;
  m_hitFraction = results->m_hitFraction;
  v17 = _mm_shuffle_ps((__m128)LODWORD(m_hitFraction), (__m128)LODWORD(m_hitFraction), 0);
  query.m_direction.m_quad = m_quad;
  v40 = v14;
  results->m_hitFraction = 1.0;
  v43 = -1;
  v18.m_quad = (__m128)input->m_from;
  v19 = (__m128i)_mm_sub_ps(input->m_to.m_quad, input->m_from.m_quad);
  query.m_invDirection.m_quad = _mm_add_ps(_mm_mul_ps(v17, _mm_sub_ps(v16.m_quad, m_quad)), m_quad);
  v20 = _mm_rcp_ps((__m128)v19);
  v21 = _mm_cmpeq_ps((__m128)0i64, (__m128)v19);
  tree.hkcdStaticTree::DynamicStorage6 = (hkcdStaticTree::DynamicStorage6)v18.m_quad;
  tree.m_domain.m_min.m_quad = _mm_shuffle_ps((__m128)v19, _mm_unpackhi_ps((__m128)v19, v15), 196);
  tree.m_domain.m_max.m_quad = _mm_or_ps(
                                 _mm_and_ps(
                                   _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v19, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                   v21),
                                 _mm_andnot_ps(
                                   v21,
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v19, v20)), v20)));
  tree.m_domain.m_max.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, tree.m_domain.m_min.m_quad)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkcdStaticTree::DefaultTreeStorage6,hkpStaticCompoundShape_Internals::RayCastQuery>(
    &v47,
    (hkSimdFloat32 *)this->m_tree,
    &tree,
    &query,
    (hkpStaticCompoundShape_Internals::RayCastQuery *)query.m_origin.m_quad.m128_u64[0]);
  if ( p_m_quad )
  {
    p_m_quad[1].m128_f32[0] = m_hitFraction;
    if ( v43 >= 0 )
    {
      v22 = *(_QWORD *)(query.m_origin.m_quad.m128_u64[0] + 56) + 80i64 * v43;
      if ( (*(_BYTE *)(v22 + 12) & 2) != 0 )
      {
        if ( (*(_BYTE *)(v22 + 12) & 4) != 0 )
        {
          v23 = *(__m128 *)(v22 + 32);
          v24 = _mm_rcp_ps(v23);
          *p_m_quad = _mm_mul_ps(*p_m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v24)), v24));
          v25 = _mm_mul_ps(*p_m_quad, *p_m_quad);
          v26 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                  _mm_shuffle_ps(v25, v25, 170));
          v27 = _mm_rsqrt_ps(v26);
          *p_m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v26, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                            _mm_mul_ps(*(__m128 *)_xmm, v27))),
                        *p_m_quad);
        }
        v28 = *(__m128 *)(v22 + 16);
        v29 = _mm_shuffle_ps(v28, v28, 255);
        v30 = _mm_mul_ps(*p_m_quad, v28);
        v31 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 201), v28),
                _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), *p_m_quad));
        v32 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                      _mm_shuffle_ps(v30, v30, 170)),
                    v28),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v29, v29), (__m128)xmmword_141A711B0), *p_m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v29));
        *p_m_quad = _mm_add_ps(v32, v32);
      }
      result->m_bool = 1;
    }
    else
    {
      result->m_bool = 0;
    }
  }
  else
  {
    result->m_bool = 0;
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v35 = __rdtsc();
    v36 = v34 + 2;
    *((_DWORD *)v36 - 2) = v35;
    v33[1] = v36;
  }
  return result;
}

// File Line: 813
// RVA: 0xDC3F90
void __fastcall hkpStaticCompoundShape::castRayWithCollector(
        hkpStaticCompoundShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *body,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm7
  hkVector4f v15; // xmm1
  hkVector4f v16; // xmm6
  __m128i v17; // xmm6
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  hkcdStaticTree::DefaultTreeStorage6 query; // [rsp+20h] [rbp-F8h] BYREF
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> v27; // [rsp+50h] [rbp-C8h] BYREF
  hkcdRay ray; // [rsp+60h] [rbp-B8h] BYREF
  __int128 v29; // [rsp+90h] [rbp-88h]
  __int128 v30; // [rsp+A0h] [rbp-78h]
  __int64 v31; // [rsp+B0h] [rbp-68h]
  hkpCdBody *v32; // [rsp+D8h] [rbp-40h]
  hkpRayHitCollector *v33; // [rsp+E0h] [rbp-38h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSCS::castRayWithCollector";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)input->m_from;
  v14.m_quad = (__m128)input->m_from;
  v15.m_quad = (__m128)input->m_to;
  ray.m_origin.m_quad.m128_u64[0] = (unsigned __int64)this;
  v16.m_quad = (__m128)input->m_to;
  ray.m_direction = (hkVector4f)v13.m_quad;
  v31 = 0i64;
  v32 = body;
  v33 = collector;
  v17 = (__m128i)_mm_sub_ps(v16.m_quad, v14.m_quad);
  v18 = *(_OWORD *)&input->m_filterInfo;
  ray.m_invDirection = (hkVector4f)v15.m_quad;
  v19 = *(_OWORD *)&input->m_collidable;
  v29 = v18;
  v30 = v19;
  *(_QWORD *)&query.m_nodes.m_size = v14.m_quad.m128_u64[1];
  v20 = _mm_rcp_ps((__m128)v17);
  v21 = _mm_cmpeq_ps((__m128)0i64, (__m128)v17);
  query.m_domain.m_min.m_quad = _mm_shuffle_ps((__m128)v17, _mm_unpackhi_ps((__m128)v17, ::query.m_quad), 196);
  query.m_domain.m_max.m_quad = _mm_or_ps(
                                  _mm_and_ps(
                                    _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v17, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                    v21),
                                  _mm_andnot_ps(
                                    v21,
                                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, (__m128)v17)), v20)));
  query.m_domain.m_max.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, query.m_domain.m_min.m_quad)) & 7 | 0x3F000000;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkcdStaticTree::DefaultTreeStorage6,hkpStaticCompoundShape_Internals::RayCastQuery>(
    &v27,
    (hkSimdFloat32 *)this->m_tree,
    &query,
    &ray,
    (hkpStaticCompoundShape_Internals::RayCastQuery *)v14.m_quad.m128_u64[0]);
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v24 = __rdtsc();
    v25 = v23 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v22[1] = v25;
  }
}

// File Line: 825
// RVA: 0xDC3AE0
float __fastcall hkpStaticCompoundShape::getMaximumProjection(hkpStaticCompoundShape *this, hkVector4f *direction)
{
  int v2; // ebx
  float v3; // xmm6_4
  __int64 v6; // rdi
  hkpStaticCompoundShape::Instance *m_data; // rcx
  float TransformedMaximumProjection; // xmm0_4
  hkQsTransformf transform; // [rsp+20h] [rbp-48h] BYREF

  v2 = 0;
  v3 = FLOAT_N3_40282e38;
  if ( this->m_instances.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      m_data = this->m_instances.m_data;
      transform = m_data[v6].m_transform;
      TransformedMaximumProjection = hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(
                                       m_data[v6].m_shape,
                                       &transform,
                                       direction);
      if ( TransformedMaximumProjection > v3 )
        v3 = TransformedMaximumProjection;
      ++v2;
      ++v6;
    }
    while ( v2 < this->m_instances.m_size );
  }
  return v3;
}

