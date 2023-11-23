// File Line: 22
// RVA: 0xDB6550
void __fastcall hkpMoppCachedShapeMediator::hkpMoppCachedShapeMediator(
        hkpMoppCachedShapeMediator *this,
        hkpShapeContainer *shapeArray)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCachedShapeMediator::`vftable;
  this->m_arrayConvexShapeData.m_capacityAndFlags = 0x80000000;
  this->m_arrayConvexShapeData.m_data = 0i64;
  this->m_arrayConvexShapeData.m_size = 0;
  this->m_shapeCollection = shapeArray;
  this->m_numChildShapes = shapeArray->vfptr->getNumChildShapes(shapeArray);
}

// File Line: 29
// RVA: 0xDB65A0
void __fastcall hkpMoppCachedShapeMediator::~hkpMoppCachedShapeMediator(hkpMoppCachedShapeMediator *this)
{
  int m_capacityAndFlags; // r8d

  this->m_shapeCollection = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCachedShapeMediator::`vftable;
  m_capacityAndFlags = this->m_arrayConvexShapeData.m_capacityAndFlags;
  this->m_arrayConvexShapeData.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_arrayConvexShapeData.m_data,
      108 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_arrayConvexShapeData.m_data = 0i64;
  this->m_arrayConvexShapeData.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 35
// RVA: 0xDB6610
void __fastcall hkpMoppCachedShapeMediator::setSplittingPlaneDirections(
        hkpMoppCachedShapeMediator *this,
        hkpMoppSplittingPlaneDirection *directions,
        int numDirections)
{
  int v6; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbp
  hkpConvexShape *v9; // rsi
  char v10[512]; // [rsp+30h] [rbp-218h] BYREF

  v6 = this->m_shapeCollection->vfptr->getNumChildShapes(this->m_shapeCollection);
  v7 = this->m_shapeCollection->vfptr->getFirstKey(this->m_shapeCollection);
  if ( v6 > 0 )
  {
    v8 = (unsigned int)v6;
    do
    {
      v9 = (hkpConvexShape *)this->m_shapeCollection->vfptr->getChildShape(this->m_shapeCollection, v7, v10);
      if ( ((unsigned __int8 (__fastcall *)(hkpConvexShape *))v9->vfptr[1].__first_virtual_table_function__)(v9) )
        hkpMoppCachedShapeMediator::addConvexShape(this, v9, v7, directions, numDirections);
      v7 = this->m_shapeCollection->vfptr->getNextKey(this->m_shapeCollection, v7);
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 67
// RVA: 0xDB6910
void __fastcall hkpMoppCachedShapeMediator::addConvexShape(
        hkpMoppCachedShapeMediator *this,
        hkpConvexShape *convexShape,
        unsigned int key,
        hkpMoppSplittingPlaneDirection *directions,
        int numDirections)
{
  __int64 v9; // rbp
  hkLifoAllocator *Value; // rax
  __m128 *m_cur; // rdi
  int v12; // r13d
  char *v13; // rcx
  __int64 v14; // r9
  hkpMoppCachedShapeMediator::hkpConvexShapeData *v15; // rdx
  float *p_m_max; // rdx
  __m128 v17; // xmm1
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  __m128 *v21; // rax
  __int64 v22; // rcx
  __m128 v23; // xmm1
  float v24; // xmm2_4
  float v25; // xmm1_4
  hkLifoAllocator *v26; // rax
  int v27; // r8d

  v9 = ((int (__fastcall *)(hkpConvexShape *))convexShape->vfptr[5].__first_virtual_table_function__)(convexShape);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__m128 *)Value->m_cur;
  v12 = (16 * v9 + 127) & 0xFFFFFF80;
  v13 = (char *)m_cur + v12;
  if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    m_cur = (__m128 *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
  else
    Value->m_cur = v13;
  convexShape->vfptr[6].__vecDelDtor(convexShape, (unsigned int)m_cur);
  if ( this->m_arrayConvexShapeData.m_size == (this->m_arrayConvexShapeData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_arrayConvexShapeData.m_data,
      108);
  v14 = numDirections;
  v15 = &this->m_arrayConvexShapeData.m_data[this->m_arrayConvexShapeData.m_size++];
  v15->m_key = key;
  if ( numDirections > 0i64 )
  {
    p_m_max = &v15->m_extents[0].m_max;
    do
    {
      if ( (int)v9 <= 0 )
      {
        v20 = 0.0;
        v19 = 0.0;
      }
      else
      {
        v17 = _mm_mul_ps(*m_cur, directions->m_direction.m_quad);
        v18 = (float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
            + _mm_shuffle_ps(v17, v17, 170).m128_f32[0];
        v19 = v18 + m_cur->m128_f32[3];
        v20 = v18 - m_cur->m128_f32[3];
        if ( v9 > 1 )
        {
          v21 = m_cur + 1;
          v22 = v9 - 1;
          do
          {
            v23 = _mm_mul_ps(directions->m_direction.m_quad, *v21);
            v23.m128_f32[0] = (float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                            + _mm_shuffle_ps(v23, v23, 170).m128_f32[0];
            v24 = v23.m128_f32[0] + v21->m128_f32[3];
            v25 = v23.m128_f32[0] - v21->m128_f32[3];
            if ( v25 < v20 )
              v20 = v25;
            if ( v24 > v19 )
              v19 = v24;
            ++v21;
            --v22;
          }
          while ( v22 );
        }
      }
      *(p_m_max - 1) = v20;
      *p_m_max = v19;
      p_m_max += 2;
      ++directions;
      --v14;
    }
    while ( v14 );
  }
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v26->m_slabSize || (char *)m_cur + v27 != v26->m_cur || v26->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v26, (char *)m_cur, v27);
  else
    v26->m_cur = m_cur;
}

// File Line: 156
// RVA: 0xDB68F0
__int64 __fastcall hkpMoppCachedShapeMediator::getPrimitiveProperties(
        hkpMoppCachedShapeMediator *this,
        hkpMoppCompilerPrimitive *primitiveIn,
        unsigned int *cid)
{
  *cid = 0;
  return 1i64;
}

// File Line: 172
// RVA: 0xDB6790
void __fastcall hkpMoppCachedShapeMediator::projectPrimitives(
        hkpMoppCachedShapeMediator *this,
        hkVector4f *direction,
        int directionIndex,
        hkpMoppCompilerPrimitive *primitives,
        int numPrimitives,
        float *absMinOut,
        float *absMaxOut)
{
  hkpMoppCachedShapeMediator::hkpConvexShapeData *m_data; // rax
  __int64 v8; // r10
  __int64 v10; // rdx
  float v11; // xmm2_4
  float v12; // xmm3_4
  float *p_m_primitiveID2; // rdx
  __int64 v14; // r8
  __int64 v15; // rcx
  hkpMoppCachedShapeMediator::hkpConvexShapeData *v16; // rax
  __int64 v17; // rcx
  float v18; // xmm0_4
  float v19; // xmm1_4

  m_data = this->m_arrayConvexShapeData.m_data;
  v8 = 8i64 * directionIndex;
  v10 = v8 + 108i64 * (int)primitives->m_primitiveID2;
  v11 = *(float *)((char *)&m_data->m_extents[0].m_min + v10);
  v12 = *(float *)((char *)&m_data->m_extents[0].m_max + v10);
  primitives->m_extent.m_min = v11;
  primitives->m_extent.m_max = v12;
  if ( numPrimitives > 1i64 )
  {
    p_m_primitiveID2 = (float *)&primitives[1].m_primitiveID2;
    v14 = numPrimitives - 1i64;
    do
    {
      v15 = *(int *)p_m_primitiveID2;
      v16 = this->m_arrayConvexShapeData.m_data;
      p_m_primitiveID2 += 5;
      v17 = v8 + 108 * v15;
      v18 = *(float *)((char *)&v16->m_extents[0].m_min + v17);
      v19 = *(float *)((char *)&v16->m_extents[0].m_max + v17);
      v11 = fminf(v11, v18);
      *(p_m_primitiveID2 - 4) = v18;
      v12 = fmaxf(v12, v19);
      *(p_m_primitiveID2 - 3) = v19;
      --v14;
    }
    while ( v14 );
  }
  *absMinOut = v11;
  *absMaxOut = v12;
}

// File Line: 210
// RVA: 0xDB6850
void __fastcall hkpMoppCachedShapeMediator::findExtents(
        hkpMoppCachedShapeMediator *this,
        hkVector4f *direction,
        int directionIndex,
        hkpMoppCompilerPrimitive *primitives,
        int numPrimitives,
        float *absMinOut,
        float *absMaxOut)
{
  hkpMoppCachedShapeMediator::hkpConvexShapeData *m_data; // r10
  __int64 v8; // rdx
  hkpMoppCachedShapeMediator::hkpConvexShapeData *v9; // rax
  float m_min; // xmm1_4
  float m_max; // xmm2_4
  unsigned int *p_m_primitiveID2; // rcx
  __int64 v13; // r8
  __int64 v14; // rax
  hkpMoppCachedShapeMediator::hkpConvexShapeData *v15; // rax

  m_data = this->m_arrayConvexShapeData.m_data;
  v8 = directionIndex;
  v9 = &m_data[primitives->m_primitiveID2];
  m_min = v9->m_extents[directionIndex].m_min;
  m_max = v9->m_extents[directionIndex].m_max;
  if ( numPrimitives > 1i64 )
  {
    p_m_primitiveID2 = &primitives[1].m_primitiveID2;
    v13 = numPrimitives - 1i64;
    do
    {
      v14 = (int)*p_m_primitiveID2;
      p_m_primitiveID2 += 5;
      v15 = &m_data[v14];
      m_min = fminf(m_min, v15->m_extents[v8].m_min);
      m_max = fmaxf(m_max, v15->m_extents[v8].m_max);
      --v13;
    }
    while ( v13 );
  }
  *absMinOut = m_min;
  *absMaxOut = m_max;
}

// File Line: 240
// RVA: 0xDB6720
void __fastcall hkpMoppCachedShapeMediator::getPrimitives(
        hkpMoppCachedShapeMediator *this,
        hkpMoppCompilerPrimitive *primitives)
{
  int m_numChildShapes; // ebp
  unsigned int v5; // eax
  signed int i; // ebx

  m_numChildShapes = this->m_numChildShapes;
  v5 = this->m_shapeCollection->vfptr->getFirstKey(this->m_shapeCollection);
  for ( i = 0; i < m_numChildShapes; ++i )
  {
    primitives->m_primitiveID = v5;
    primitives->m_primitiveID2 = i;
    ++primitives;
    v5 = this->m_shapeCollection->vfptr->getNextKey(this->m_shapeCollection, v5);
  }
}

// File Line: 256
// RVA: 0xDB66F0
void __fastcall hkpMoppCachedShapeMediator::splitPrimitive(
        hkpMoppCachedShapeMediator *this,
        hkpMoppCompilerPrimitive *primitiveIn,
        hkVector4f *direction,
        float planeOffset,
        int depth,
        hkpMoppCompilerPrimitive *primitiveOut)
{
  *primitiveOut = *primitiveIn;
}

// File Line: 262
// RVA: 0xDB66E0
__int64 __fastcall hkpMoppCachedShapeMediator::getNumPrimitives(hkpMoppCachedShapeMediator *this)
{
  return (unsigned int)this->m_numChildShapes;
}

