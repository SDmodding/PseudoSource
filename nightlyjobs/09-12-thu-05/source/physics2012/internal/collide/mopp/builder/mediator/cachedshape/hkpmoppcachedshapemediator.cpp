// File Line: 22
// RVA: 0xDB6550
void __fastcall hkpMoppCachedShapeMediator::hkpMoppCachedShapeMediator(hkpMoppCachedShapeMediator *this, hkpShapeContainer *shapeArray)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCachedShapeMediator::`vftable';
  this->m_arrayConvexShapeData.m_capacityAndFlags = 2147483648;
  this->m_arrayConvexShapeData.m_data = 0i64;
  this->m_arrayConvexShapeData.m_size = 0;
  this->m_shapeCollection = shapeArray;
  this->m_numChildShapes = shapeArray->vfptr->getNumChildShapes(shapeArray);
}

// File Line: 29
// RVA: 0xDB65A0
void __fastcall hkpMoppCachedShapeMediator::~hkpMoppCachedShapeMediator(hkpMoppCachedShapeMediator *this)
{
  hkpMoppCachedShapeMediator *v1; // rbx
  int v2; // er8

  this->m_shapeCollection = 0i64;
  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCachedShapeMediator::`vftable';
  v2 = this->m_arrayConvexShapeData.m_capacityAndFlags;
  this->m_arrayConvexShapeData.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_arrayConvexShapeData.m_data,
      108 * (v2 & 0x3FFFFFFF));
  v1->m_arrayConvexShapeData.m_data = 0i64;
  v1->m_arrayConvexShapeData.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 35
// RVA: 0xDB6610
void __fastcall hkpMoppCachedShapeMediator::setSplittingPlaneDirections(hkpMoppCachedShapeMediator *this, hkpMoppSplittingPlaneDirection *directions, int numDirections)
{
  hkpMoppCachedShapeMediator *v3; // rdi
  int v4; // er14
  hkpMoppSplittingPlaneDirection *v5; // r15
  unsigned int v6; // esi
  unsigned int v7; // ebx
  __int64 v8; // rbp
  hkpConvexShape *v9; // rsi
  char v10; // [rsp+30h] [rbp-218h]

  v3 = this;
  v4 = numDirections;
  v5 = directions;
  v6 = ((__int64 (*)(void))this->m_shapeCollection->vfptr->getNumChildShapes)();
  v7 = ((__int64 (*)(void))v3->m_shapeCollection->vfptr->getFirstKey)();
  if ( (signed int)v6 > 0 )
  {
    v8 = v6;
    do
    {
      v9 = (hkpConvexShape *)v3->m_shapeCollection->vfptr->getChildShape(v3->m_shapeCollection, v7, (char (*)[512])&v10);
      if ( ((unsigned __int8 (__fastcall *)(hkpConvexShape *))v9->vfptr[1].__first_virtual_table_function__)(v9) )
        hkpMoppCachedShapeMediator::addConvexShape(v3, v9, v7, v5, v4);
      v7 = v3->m_shapeCollection->vfptr->getNextKey(v3->m_shapeCollection, v7);
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 67
// RVA: 0xDB6910
void __fastcall hkpMoppCachedShapeMediator::addConvexShape(hkpMoppCachedShapeMediator *this, hkpConvexShape *convexShape, unsigned int key, hkpMoppSplittingPlaneDirection *directions, int numDirections)
{
  hkpMoppCachedShapeMediator *v5; // r14
  hkpMoppSplittingPlaneDirection *v6; // rsi
  unsigned int v7; // er15
  hkpConvexShape *v8; // rbx
  signed __int64 v9; // rbp
  hkLifoAllocator *v10; // rax
  __m128 *v11; // rdi
  int v12; // er13
  char *v13; // rcx
  __int64 v14; // r9
  hkpMoppCachedShapeMediator::hkpConvexShapeData *v15; // rdx
  float *v16; // rdx
  __m128 v17; // xmm1
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  __m128 *v21; // rax
  signed __int64 v22; // rcx
  __m128 v23; // xmm1
  float v24; // xmm2_4
  float v25; // xmm1_4
  hkLifoAllocator *v26; // rax
  int v27; // er8

  v5 = this;
  v6 = directions;
  v7 = key;
  v8 = convexShape;
  v9 = ((signed int (__fastcall *)(hkpConvexShape *))convexShape->vfptr[5].__first_virtual_table_function__)(convexShape);
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (__m128 *)v10->m_cur;
  v12 = (16 * v9 + 127) & 0xFFFFFF80;
  v13 = (char *)v11 + v12;
  if ( v12 > v10->m_slabSize || v13 > v10->m_end )
    v11 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
  else
    v10->m_cur = v13;
  v8->vfptr[6].__vecDelDtor((hkBaseObject *)&v8->vfptr, (unsigned int)v11);
  if ( v5->m_arrayConvexShapeData.m_size == (v5->m_arrayConvexShapeData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_arrayConvexShapeData,
      108);
  v14 = numDirections;
  v15 = &v5->m_arrayConvexShapeData.m_data[v5->m_arrayConvexShapeData.m_size++];
  v15->m_key = v7;
  if ( numDirections > 0i64 )
  {
    v16 = &v15->m_extents[0].m_max;
    do
    {
      if ( (signed int)v9 <= 0 )
      {
        v20 = 0.0;
        v19 = 0.0;
      }
      else
      {
        v17 = _mm_mul_ps(*v11, v6->m_direction.m_quad);
        v18 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170));
        v19 = v18 + *((float *)&v11->m128_u64[1] + 1);
        v20 = v18 - *((float *)&v11->m128_u64[1] + 1);
        if ( v9 > 1 )
        {
          v21 = v11 + 1;
          v22 = v9 - 1;
          do
          {
            v23 = _mm_mul_ps(v6->m_direction.m_quad, *v21);
            v23.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170));
            v24 = v23.m128_f32[0] + *((float *)&v21->m128_u64[1] + 1);
            v25 = v23.m128_f32[0] - *((float *)&v21->m128_u64[1] + 1);
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
      *(v16 - 1) = v20;
      *v16 = v19;
      v16 += 2;
      ++v6;
      --v14;
    }
    while ( v14 );
  }
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v26->m_slabSize || (char *)v11 + v27 != v26->m_cur || v26->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v26, v11, v27);
  else
    v26->m_cur = v11;
}

// File Line: 156
// RVA: 0xDB68F0
signed __int64 __fastcall hkpMoppCachedShapeMediator::getPrimitiveProperties(hkpMoppCachedShapeMediator *this, hkpMoppCompilerPrimitive *primitiveIn, unsigned int *cid)
{
  *cid = 0;
  return 1i64;
}

// File Line: 172
// RVA: 0xDB6790
void __fastcall hkpMoppCachedShapeMediator::projectPrimitives(hkpMoppCachedShapeMediator *this, hkVector4f *direction, int directionIndex, hkpMoppCompilerPrimitive *primitives, int numPrimitives, float *absMinOut, float *absMaxOut)
{
  hkpMoppCachedShapeMediator::hkpConvexShapeData *v7; // rax
  signed __int64 v8; // r10
  hkpMoppCachedShapeMediator *v9; // r11
  signed __int64 v10; // rdx
  float v11; // xmm2_4
  float v12; // xmm3_4
  float *v13; // rdx
  signed __int64 v14; // r8
  __int64 v15; // rcx
  hkpMoppCachedShapeMediator::hkpConvexShapeData *v16; // rax
  signed __int64 v17; // rcx
  float v18; // xmm0_4
  float v19; // xmm1_4

  v7 = this->m_arrayConvexShapeData.m_data;
  v8 = 8i64 * directionIndex;
  v9 = this;
  v10 = v8 + 108i64 * (signed int)primitives->m_primitiveID2;
  v11 = *(float *)((char *)&v7->m_extents[0].m_min + v10);
  v12 = *(float *)((char *)&v7->m_extents[0].m_max + v10);
  primitives->m_extent.m_min = v11;
  primitives->m_extent.m_max = v12;
  if ( numPrimitives > 1i64 )
  {
    v13 = (float *)&primitives[1].m_primitiveID2;
    v14 = numPrimitives - 1i64;
    do
    {
      v15 = *(signed int *)v13;
      v16 = v9->m_arrayConvexShapeData.m_data;
      v13 += 5;
      v17 = v8 + 108 * v15;
      v18 = *(float *)((char *)&v16->m_extents[0].m_min + v17);
      v19 = *(float *)((char *)&v16->m_extents[0].m_max + v17);
      v11 = fminf(v11, v18);
      *(v13 - 4) = v18;
      v12 = fmaxf(v12, v19);
      *(v13 - 3) = v19;
      --v14;
    }
    while ( v14 );
  }
  *absMinOut = v11;
  *absMaxOut = v12;
}

// File Line: 210
// RVA: 0xDB6850
void __fastcall hkpMoppCachedShapeMediator::findExtents(hkpMoppCachedShapeMediator *this, hkVector4f *direction, int directionIndex, hkpMoppCompilerPrimitive *primitives, int numPrimitives, float *absMinOut, float *absMaxOut)
{
  hkpMoppCachedShapeMediator::hkpConvexShapeData *v7; // r10
  __int64 v8; // rdx
  signed __int64 v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  unsigned int *v12; // rcx
  signed __int64 v13; // r8
  __int64 v14; // rax
  signed __int64 v15; // rax

  v7 = this->m_arrayConvexShapeData.m_data;
  v8 = directionIndex;
  v9 = (signed __int64)&v7[primitives->m_primitiveID2];
  v10 = *(float *)(v9 + 8i64 * directionIndex + 4);
  v11 = *(float *)(v9 + 8i64 * directionIndex + 8);
  if ( numPrimitives > 1i64 )
  {
    v12 = &primitives[1].m_primitiveID2;
    v13 = numPrimitives - 1i64;
    do
    {
      v14 = (signed int)*v12;
      v12 += 5;
      v15 = (signed __int64)&v7[v14];
      v10 = fminf(v10, *(float *)(v15 + 8 * v8 + 4));
      v11 = fmaxf(v11, *(float *)(v15 + 8 * v8 + 8));
      --v13;
    }
    while ( v13 );
  }
  *absMinOut = v10;
  *absMaxOut = v11;
}

// File Line: 240
// RVA: 0xDB6720
void __fastcall hkpMoppCachedShapeMediator::getPrimitives(hkpMoppCachedShapeMediator *this, hkpMoppCompilerPrimitive *primitives)
{
  int v2; // ebp
  hkpMoppCachedShapeMediator *v3; // rsi
  hkpMoppCompilerPrimitive *v4; // rdi
  unsigned int v5; // eax
  int i; // ebx

  v2 = this->m_numChildShapes;
  v3 = this;
  v4 = primitives;
  v5 = ((__int64 (*)(void))this->m_shapeCollection->vfptr->getFirstKey)();
  for ( i = 0; i < v2; ++i )
  {
    v4->m_primitiveID = v5;
    v4->m_primitiveID2 = i;
    ++v4;
    v5 = v3->m_shapeCollection->vfptr->getNextKey(v3->m_shapeCollection, v5);
  }
}

// File Line: 256
// RVA: 0xDB66F0
void __fastcall hkpMoppCachedShapeMediator::splitPrimitive(hkpMoppCachedShapeMediator *this, hkpMoppCompilerPrimitive *primitiveIn, hkVector4f *direction, float planeOffset, int depth, hkpMoppCompilerPrimitive *primitiveOut)
{
  *(_QWORD *)&primitiveOut->m_primitiveID = *(_QWORD *)&primitiveIn->m_primitiveID;
  primitiveOut->m_extent.m_min = primitiveIn->m_extent.m_min;
  primitiveOut->m_extent.m_max = primitiveIn->m_extent.m_max;
  primitiveOut->m_origPrimitiveID = primitiveIn->m_origPrimitiveID;
}

// File Line: 262
// RVA: 0xDB66E0
__int64 __fastcall hkpMoppCachedShapeMediator::getNumPrimitives(hkpMoppCachedShapeMediator *this)
{
  return (unsigned int)this->m_numChildShapes;
}

