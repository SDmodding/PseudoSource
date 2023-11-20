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
void __fastcall hkpMoppShapeMediator::setSplittingPlaneDirections(hkpMoppShapeMediator *this, hkpMoppSplittingPlaneDirection *directions, int numDirections)
{
  ;
}

// File Line: 37
// RVA: 0xDB64E0
signed __int64 __fastcall hkpMoppShapeMediator::getPrimitiveProperties(hkpMoppShapeMediator *this, hkpMoppCompilerPrimitive *primitiveIn, unsigned int *cid)
{
  *cid = primitiveIn->m_primitiveID2;
  return 1i64;
}

// File Line: 108
// RVA: 0xDB61A0
void __usercall hkpMoppShapeMediator::projectPrimitives(hkpMoppShapeMediator *this@<rcx>, hkVector4f *direction@<rdx>, int directionIndex@<r8d>, hkpMoppCompilerPrimitive *primitives@<r9>, __m128 a5@<xmm0>, int numPrimitives, float *absMinOut, float *absMaxOut)
{
  hkpMoppShapeMediator *v8; // rbp
  hkVector4f *v9; // r14
  hkpMoppCompilerPrimitive *v10; // rbx
  hkpShape *v11; // rax
  hkpShape *v12; // rdi
  hkBaseObjectVtbl *v13; // rax
  float v14; // xmm8_4
  float v15; // xmm7_4
  float *v16; // rbx
  signed __int64 v17; // rsi
  __int64 v18; // rax
  __int64 *v19; // rdi
  __int64 v20; // rax
  float v21; // xmm6_4
  __m128 v22; // [rsp+20h] [rbp-268h]
  char v23; // [rsp+30h] [rbp-258h]

  v8 = this;
  v9 = direction;
  v10 = primitives;
  v11 = this->m_shape->vfptr->getChildShape(this->m_shape, primitives->m_primitiveID, (char (*)[512])&v23);
  v12 = v11;
  if ( v11 )
  {
    ((void (__fastcall *)(hkpShape *, hkVector4f *))v11->vfptr[7].__first_virtual_table_function__)(v11, v9);
    v13 = v12->vfptr;
    v14 = a5.m128_f32[0];
    a5 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v9->m_quad);
    v22 = a5;
    ((void (__fastcall *)(hkpShape *, __m128 *))v13[7].__first_virtual_table_function__)(v12, &v22);
    LODWORD(v15) = a5.m128_i32[0] ^ _xmm[0];
  }
  else
  {
    v15 = 0.0;
    v14 = 0.0;
  }
  v10->m_extent.m_min = v15;
  v10->m_extent.m_max = v14;
  if ( numPrimitives > 1i64 )
  {
    v16 = &v10[1].m_extent.m_max;
    v17 = numPrimitives - 1i64;
    do
    {
      v18 = (__int64)v8->m_shape->vfptr->getChildShape(v8->m_shape, *((_DWORD *)v16 - 3), (char (*)[512])&v23);
      v19 = (__int64 *)v18;
      if ( v18 )
      {
        (*(void (__fastcall **)(__int64, hkVector4f *))(*(_QWORD *)v18 + 120i64))(v18, v9);
        v20 = *v19;
        v21 = a5.m128_f32[0];
        v22 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v9->m_quad);
        (*(void (__fastcall **)(__int64 *, __m128 *))(v20 + 120))(v19, &v22);
        a5 = _mm_xor_ps(a5, (__m128)(unsigned int)_xmm[0]);
      }
      else
      {
        a5 = 0i64;
        v21 = 0.0;
      }
      *(v16 - 1) = a5.m128_f32[0];
      *v16 = v21;
      if ( a5.m128_f32[0] < v15 )
        v15 = a5.m128_f32[0];
      if ( v21 > v14 )
        v14 = v21;
      v16 += 5;
      --v17;
    }
    while ( v17 );
  }
  *absMinOut = v15;
  *absMaxOut = v14;
}

// File Line: 148
// RVA: 0xDB6350
void __usercall hkpMoppShapeMediator::findExtents(hkpMoppShapeMediator *this@<rcx>, hkVector4f *direction@<rdx>, int directionIndex@<r8d>, hkpMoppCompilerPrimitive *primitives@<r9>, __m128 a5@<xmm0>, int numPrimitives, float *absMinOut, float *absMaxOut)
{
  hkpMoppShapeMediator *v8; // rbp
  hkVector4f *v9; // r14
  hkpMoppCompilerPrimitive *v10; // rdi
  hkpShape *v11; // rax
  hkpShape *v12; // rbx
  hkBaseObjectVtbl *v13; // rax
  float v14; // xmm8_4
  float v15; // xmm7_4
  hkpMoppCompilerPrimitive *v16; // rbx
  signed __int64 v17; // rsi
  __int64 v18; // rax
  __int64 *v19; // rdi
  __int64 v20; // rax
  float v21; // xmm6_4
  __m128 v22; // [rsp+20h] [rbp-268h]
  char v23; // [rsp+30h] [rbp-258h]

  v8 = this;
  v9 = direction;
  v10 = primitives;
  v11 = this->m_shape->vfptr->getChildShape(this->m_shape, primitives->m_primitiveID, (char (*)[512])&v23);
  v12 = v11;
  if ( v11 )
  {
    ((void (__fastcall *)(hkpShape *, hkVector4f *))v11->vfptr[7].__first_virtual_table_function__)(v11, v9);
    v13 = v12->vfptr;
    v14 = a5.m128_f32[0];
    a5 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v9->m_quad);
    v22 = a5;
    ((void (__fastcall *)(hkpShape *, __m128 *))v13[7].__first_virtual_table_function__)(v12, &v22);
    LODWORD(v15) = a5.m128_i32[0] ^ _xmm[0];
  }
  else
  {
    v15 = 0.0;
    v14 = 0.0;
  }
  if ( numPrimitives > 1i64 )
  {
    v16 = v10 + 1;
    v17 = numPrimitives - 1i64;
    do
    {
      v18 = (__int64)v8->m_shape->vfptr->getChildShape(v8->m_shape, v16->m_primitiveID, (char (*)[512])&v23);
      v19 = (__int64 *)v18;
      if ( v18 )
      {
        (*(void (__fastcall **)(__int64, hkVector4f *))(*(_QWORD *)v18 + 120i64))(v18, v9);
        v20 = *v19;
        v21 = a5.m128_f32[0];
        v22 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v9->m_quad);
        (*(void (__fastcall **)(__int64 *, __m128 *))(v20 + 120))(v19, &v22);
        a5 = _mm_xor_ps(a5, (__m128)(unsigned int)_xmm[0]);
      }
      else
      {
        a5 = 0i64;
        v21 = 0.0;
      }
      if ( a5.m128_f32[0] < v15 )
        v15 = a5.m128_f32[0];
      if ( v21 > v14 )
        v14 = v21;
      ++v16;
      --v17;
    }
    while ( v17 );
  }
  *absMinOut = v15;
  *absMaxOut = v14;
}

// File Line: 185
// RVA: 0xDB6130
void __fastcall hkpMoppShapeMediator::getPrimitives(hkpMoppShapeMediator *this, hkpMoppCompilerPrimitive *primitives)
{
  __int64 v2; // rdi
  hkpMoppShapeMediator *v3; // rsi
  hkpMoppCompilerPrimitive *v4; // rbx
  unsigned int v5; // eax

  v2 = (unsigned int)this->m_numChildShapes;
  v3 = this;
  v4 = primitives;
  v5 = ((__int64 (*)(void))this->m_shape->vfptr->getFirstKey)();
  if ( (signed int)v2 > 0 )
  {
    do
    {
      v4->m_primitiveID = v5;
      v4->m_primitiveID2 = 0;
      ++v4;
      v5 = v3->m_shape->vfptr->getNextKey(v3->m_shape, v5);
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 201
// RVA: 0xDB6100
void __fastcall hkpMoppShapeMediator::splitPrimitive(hkpMoppShapeMediator *this, hkpMoppCompilerPrimitive *primitiveIn, hkVector4f *direction, float planeOffset, int depth, hkpMoppCompilerPrimitive *primitiveOut)
{
  *(_QWORD *)&primitiveOut->m_primitiveID = *(_QWORD *)&primitiveIn->m_primitiveID;
  primitiveOut->m_extent.m_min = primitiveIn->m_extent.m_min;
  primitiveOut->m_extent.m_max = primitiveIn->m_extent.m_max;
  primitiveOut->m_origPrimitiveID = primitiveIn->m_origPrimitiveID;
}

// File Line: 239
// RVA: 0xDB60F0
__int64 __fastcall hkpMoppShapeMediator::getNumPrimitives(hkpMoppShapeMediator *this)
{
  return (unsigned int)this->m_numChildShapes;
}

