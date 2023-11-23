// File Line: 19
// RVA: 0xDB6080
void __fastcall hkpMoppShapeMediator::hkpMoppShapeMediator(hkpMoppShapeMediator *this, hkpShapeContainer *shapeArray)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_shape = shapeArray;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppShapeMediator::`vftable;
  this->m_numChildShapes = shapeArray->vfptr->getNumChildShapes(shapeArray);
}

// File Line: 25
// RVA: 0xDB60C0
void __fastcall hkpMoppShapeMediator::~hkpMoppShapeMediator(hkpMoppShapeMediator *this)
{
  this->m_shape = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 31
// RVA: 0xDB60E0
void __fastcall hkpMoppShapeMediator::setSplittingPlaneDirections(
        hkpMoppShapeMediator *this,
        hkpMoppSplittingPlaneDirection *directions,
        int numDirections)
{
  ;
}

// File Line: 37
// RVA: 0xDB64E0
__int64 __fastcall hkpMoppShapeMediator::getPrimitiveProperties(
        hkpMoppShapeMediator *this,
        hkpMoppCompilerPrimitive *primitiveIn,
        unsigned int *cid)
{
  *cid = primitiveIn->m_primitiveID2;
  return 1i64;
}

// File Line: 108
// RVA: 0xDB61A0
void __fastcall hkpMoppShapeMediator::projectPrimitives(
        hkpMoppShapeMediator *this,
        hkVector4f *direction,
        int directionIndex,
        hkpMoppCompilerPrimitive *primitives,
        int numPrimitives,
        float *absMinOut,
        float *absMaxOut)
{
  __m128 v7; // xmm0
  hkpShape *v11; // rax
  hkpShape *v12; // rdi
  double v13; // xmm0_8
  hkBaseObjectVtbl *vfptr; // rax
  float v15; // xmm8_4
  float v16; // xmm7_4
  float *p_m_max; // rbx
  __int64 v18; // rsi
  hkpShape *v19; // rax
  hkpShape *v20; // rdi
  hkBaseObjectVtbl *v21; // rax
  float v22; // xmm6_4
  __m128 v23; // [rsp+20h] [rbp-268h] BYREF
  char v24[560]; // [rsp+30h] [rbp-258h] BYREF

  v11 = this->m_shape->vfptr->getChildShape(this->m_shape, primitives->m_primitiveID, v24);
  v12 = v11;
  if ( v11 )
  {
    v13 = ((double (__fastcall *)(hkpShape *, hkVector4f *))v11->vfptr[7].__first_virtual_table_function__)(
            v11,
            direction);
    vfptr = v12->vfptr;
    v15 = *(float *)&v13;
    v7 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), direction->m_quad);
    v23 = v7;
    *(double *)v7.m128_u64 = ((double (__fastcall *)(hkpShape *, __m128 *))vfptr[7].__first_virtual_table_function__)(
                               v12,
                               &v23);
    LODWORD(v16) = v7.m128_i32[0] ^ _xmm[0];
  }
  else
  {
    v16 = 0.0;
    v15 = 0.0;
  }
  primitives->m_extent.m_min = v16;
  primitives->m_extent.m_max = v15;
  if ( numPrimitives > 1i64 )
  {
    p_m_max = &primitives[1].m_extent.m_max;
    v18 = numPrimitives - 1i64;
    do
    {
      v19 = this->m_shape->vfptr->getChildShape(this->m_shape, *((unsigned int *)p_m_max - 3), v24);
      v20 = v19;
      if ( v19 )
      {
        *(double *)v7.m128_u64 = ((double (__fastcall *)(hkpShape *, hkVector4f *))v19->vfptr[7].__first_virtual_table_function__)(
                                   v19,
                                   direction);
        v21 = v20->vfptr;
        v22 = v7.m128_f32[0];
        v23 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), direction->m_quad);
        *(double *)v7.m128_u64 = ((double (__fastcall *)(hkpShape *, __m128 *))v21[7].__first_virtual_table_function__)(
                                   v20,
                                   &v23);
        v7 = _mm_xor_ps(v7, (__m128)(unsigned int)_xmm[0]);
      }
      else
      {
        v7 = 0i64;
        v22 = 0.0;
      }
      *(p_m_max - 1) = v7.m128_f32[0];
      *p_m_max = v22;
      if ( v7.m128_f32[0] < v16 )
        v16 = v7.m128_f32[0];
      if ( v22 > v15 )
        v15 = v22;
      p_m_max += 5;
      --v18;
    }
    while ( v18 );
  }
  *absMinOut = v16;
  *absMaxOut = v15;
}

// File Line: 148
// RVA: 0xDB6350
void __fastcall hkpMoppShapeMediator::findExtents(
        hkpMoppShapeMediator *this,
        hkVector4f *direction,
        int directionIndex,
        hkpMoppCompilerPrimitive *primitives,
        int numPrimitives,
        float *absMinOut,
        float *absMaxOut)
{
  __m128 v7; // xmm0
  hkpShape *v11; // rax
  hkpShape *v12; // rbx
  double v13; // xmm0_8
  hkBaseObjectVtbl *vfptr; // rax
  float v15; // xmm8_4
  float v16; // xmm7_4
  hkpMoppCompilerPrimitive *v17; // rbx
  __int64 v18; // rsi
  hkpShape *v19; // rax
  hkpShape *v20; // rdi
  hkBaseObjectVtbl *v21; // rax
  float v22; // xmm6_4
  __m128 v23; // [rsp+20h] [rbp-268h] BYREF
  char v24[560]; // [rsp+30h] [rbp-258h] BYREF

  v11 = this->m_shape->vfptr->getChildShape(this->m_shape, primitives->m_primitiveID, v24);
  v12 = v11;
  if ( v11 )
  {
    v13 = ((double (__fastcall *)(hkpShape *, hkVector4f *))v11->vfptr[7].__first_virtual_table_function__)(
            v11,
            direction);
    vfptr = v12->vfptr;
    v15 = *(float *)&v13;
    v7 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), direction->m_quad);
    v23 = v7;
    *(double *)v7.m128_u64 = ((double (__fastcall *)(hkpShape *, __m128 *))vfptr[7].__first_virtual_table_function__)(
                               v12,
                               &v23);
    LODWORD(v16) = v7.m128_i32[0] ^ _xmm[0];
  }
  else
  {
    v16 = 0.0;
    v15 = 0.0;
  }
  if ( numPrimitives > 1i64 )
  {
    v17 = primitives + 1;
    v18 = numPrimitives - 1i64;
    do
    {
      v19 = this->m_shape->vfptr->getChildShape(this->m_shape, v17->m_primitiveID, v24);
      v20 = v19;
      if ( v19 )
      {
        *(double *)v7.m128_u64 = ((double (__fastcall *)(hkpShape *, hkVector4f *))v19->vfptr[7].__first_virtual_table_function__)(
                                   v19,
                                   direction);
        v21 = v20->vfptr;
        v22 = v7.m128_f32[0];
        v23 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), direction->m_quad);
        *(double *)v7.m128_u64 = ((double (__fastcall *)(hkpShape *, __m128 *))v21[7].__first_virtual_table_function__)(
                                   v20,
                                   &v23);
        v7 = _mm_xor_ps(v7, (__m128)(unsigned int)_xmm[0]);
      }
      else
      {
        v7 = 0i64;
        v22 = 0.0;
      }
      if ( v7.m128_f32[0] < v16 )
        v16 = v7.m128_f32[0];
      if ( v22 > v15 )
        v15 = v22;
      ++v17;
      --v18;
    }
    while ( v18 );
  }
  *absMinOut = v16;
  *absMaxOut = v15;
}

// File Line: 185
// RVA: 0xDB6130
void __fastcall hkpMoppShapeMediator::getPrimitives(hkpMoppShapeMediator *this, hkpMoppCompilerPrimitive *primitives)
{
  __int64 m_numChildShapes; // rdi
  unsigned int v5; // eax

  m_numChildShapes = (unsigned int)this->m_numChildShapes;
  v5 = this->m_shape->vfptr->getFirstKey(this->m_shape);
  if ( (int)m_numChildShapes > 0 )
  {
    do
    {
      primitives->m_primitiveID = v5;
      primitives->m_primitiveID2 = 0;
      ++primitives;
      v5 = this->m_shape->vfptr->getNextKey(this->m_shape, v5);
      --m_numChildShapes;
    }
    while ( m_numChildShapes );
  }
}

// File Line: 201
// RVA: 0xDB6100
void __fastcall hkpMoppShapeMediator::splitPrimitive(
        hkpMoppShapeMediator *this,
        hkpMoppCompilerPrimitive *primitiveIn,
        hkVector4f *direction,
        float planeOffset,
        int depth,
        hkpMoppCompilerPrimitive *primitiveOut)
{
  *primitiveOut = *primitiveIn;
}

// File Line: 239
// RVA: 0xDB60F0
__int64 __fastcall hkpMoppShapeMediator::getNumPrimitives(hkpMoppShapeMediator *this)
{
  return (unsigned int)this->m_numChildShapes;
}

