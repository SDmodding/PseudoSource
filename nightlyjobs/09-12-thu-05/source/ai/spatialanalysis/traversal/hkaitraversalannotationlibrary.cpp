// File Line: 18
// RVA: 0xC39840
__int64 __fastcall hkaiTraversalAnnotationLibrary::addAnnotation(hkaiTraversalAnnotationLibrary *this, hkaiUserEdgeUtils::UserEdgePair *userEdgePair, hkaiTraversalType traversalType, unsigned int userdata)
{
  unsigned int v4; // ebp
  unsigned int v5; // er14
  char v6; // r15
  unsigned __int128 v7; // di
  signed __int64 v8; // rdx
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  _OWORD *v18; // rcx
  __int64 result; // rax
  signed __int64 v20; // rcx

  v4 = this->m_annotations.m_size;
  v5 = userdata;
  v6 = traversalType;
  v7 = __PAIR__((unsigned __int64)this, (unsigned __int64)userEdgePair);
  if ( v4 == (this->m_annotations.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_annotations, 32);
  v8 = *(_QWORD *)(*((_QWORD *)&v7 + 1) + 80i64) + 32i64 * (signed int)(*(_DWORD *)(*((_QWORD *)&v7 + 1) + 88i64))++;
  *(_DWORD *)(v8 + 16) = v5;
  *(_BYTE *)(v8 + 30) = v6;
  *(_QWORD *)(v8 + 20) = -1i64;
  *(_WORD *)(v8 + 28) = 0;
  v9 = *(__m128 *)(v7 + 32);
  v10 = _mm_unpacklo_ps(*(__m128 *)v7, *(__m128 *)(v7 + 16));
  v11 = _mm_movelh_ps(v10, v9);
  v12 = _mm_sub_ps(_mm_shuffle_ps(_mm_movehl_ps(v11, v10), v9, 212), v11);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_mul_ps(v12, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15));
  v17 = _mm_mul_ps(v16, v11);
  *(__m128 *)v8 = _mm_shuffle_ps(
                    v16,
                    _mm_unpackhi_ps(
                      v16,
                      _mm_sub_ps(
                        (__m128)0i64,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                          _mm_shuffle_ps(v17, v17, 170)))),
                    196);
  if ( *(_DWORD *)(*((_QWORD *)&v7 + 1) + 72i64) == (*(_DWORD *)(*((_QWORD *)&v7 + 1) + 76i64) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(*((_QWORD *)&v7 + 1) + 64i64),
      80);
  v18 = (_OWORD *)(*(_QWORD *)(*((_QWORD *)&v7 + 1) + 64i64) + 80i64 * *(signed int *)(*((_QWORD *)&v7 + 1) + 72i64));
  if ( v18 )
  {
    *v18 = *(_OWORD *)v7;
    v18[1] = *(_OWORD *)(v7 + 16);
    v18[2] = *(_OWORD *)(v7 + 32);
    v18[3] = *(_OWORD *)(v7 + 48);
    v18[4] = *(_OWORD *)(v7 + 64);
  }
  ++*(_DWORD *)(*((_QWORD *)&v7 + 1) + 72i64);
  result = v4;
  v20 = *(_QWORD *)(*((_QWORD *)&v7 + 1) + 64i64) + 80i64 * (*(_DWORD *)(*((_QWORD *)&v7 + 1) + 72i64) - 1);
  *(_DWORD *)(v20 + 64) = v4 | 0x7F900000;
  *(_DWORD *)(v20 + 68) = 0;
  *(_BYTE *)(v20 + 76) = 1;
  return result;
}

// File Line: 64
// RVA: 0xC399F0
void __fastcall hkaiTraversalAnnotationLibrary::addIntervalPartition(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int offset, hkaiIntervalPartition *intervalPartition, bool storeYData, bool storeIntData)
{
  int v6; // eax
  hkaiIntervalPartitionLibrary *v7; // rcx
  signed __int64 v8; // rbx
  unsigned int v9; // eax
  char v10; // cl

  v6 = this->m_annotations.m_size - 1;
  v7 = &this->m_intervalPartitionLibrary;
  v8 = (signed __int64)&v7[1].m_partitionRecords.m_data[4 * v6];
  v9 = hkaiIntervalPartitionLibrary::addIntervalPartition(v7, intervalPartition, storeYData, storeIntData);
  v10 = *(_BYTE *)(v8 + 28);
  if ( !v10 )
    *(_DWORD *)(v8 + 20) = v9;
  *(_BYTE *)(v8 + 28) = v10 + 1;
}

// File Line: 91
// RVA: 0xC39A40
void __fastcall hkaiTraversalAnnotationLibrary::addVector(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int offset, hkVector4f *vector)
{
  int v4; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // rdi
  hkVector4f *v6; // rbp
  hkaiTraversalAnnotationLibrary::Annotation *v7; // rbx
  char v8; // al

  v4 = this->m_vectorLibrary.m_size;
  v5 = &this->m_vectorLibrary;
  v6 = vector;
  v7 = &this->m_annotations.m_data[this->m_annotations.m_size - 1];
  if ( this->m_vectorLibrary.m_size == (this->m_vectorLibrary.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
  v5->m_data[v5->m_size++] = (hkVector4f)v6->m_quad;
  v8 = v7->m_numVectors;
  if ( !v8 )
    v7->m_firstVectorIndex = v4;
  v7->m_numVectors = v8 + 1;
}

// File Line: 116
// RVA: 0xC39AD0
__int64 __fastcall hkaiTraversalAnnotationLibrary::getNumAnnotations(hkaiTraversalAnnotationLibrary *this)
{
  return (unsigned int)this->m_annotations.m_size;
}

// File Line: 121
// RVA: 0xC39AE0
hkaiUserEdgeUtils::UserEdgePair *__fastcall hkaiTraversalAnnotationLibrary::getUserEdgePair(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex)
{
  return &this->m_userEdgePairs.m_data[annotationIndex];
}

// File Line: 126
// RVA: 0xC39B00
hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *__fastcall hkaiTraversalAnnotationLibrary::getUserEdgePairArray(hkaiTraversalAnnotationLibrary *this)
{
  return &this->m_userEdgePairs;
}

// File Line: 131
// RVA: 0xC39B10
__int64 __fastcall hkaiTraversalAnnotationLibrary::getTraversalType(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex)
{
  return (unsigned __int8)this->m_annotations.m_data[annotationIndex].m_traversalType.m_storage;
}

// File Line: 136
// RVA: 0xC39B30
__int64 __fastcall hkaiTraversalAnnotationLibrary::getUserdata(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex)
{
  return this->m_annotations.m_data[annotationIndex].m_userdata;
}

// File Line: 141
// RVA: 0xC39B50
hkSimdFloat32 *__fastcall hkaiTraversalAnnotationLibrary::evaluateT(hkaiTraversalAnnotationLibrary *this, hkSimdFloat32 *result, unsigned int annotationIndex, hkVector4f *p)
{
  hkaiTraversalAnnotationLibrary::Annotation *v4; // rax
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  hkSimdFloat32 *v7; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm1

  v4 = &this->m_annotations.m_data[annotationIndex];
  v5 = _mm_mul_ps(p->m_quad, v4->m_tEquation.m_quad);
  v6 = _mm_unpackhi_ps(v5, v4->m_tEquation.m_quad);
  v7 = result;
  v8 = _mm_shuffle_ps(v5, v6, 196);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  result->m_real = _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9);
  return v7;
}

// File Line: 146
// RVA: 0xC39B90
hkSimdFloat32 *__fastcall hkaiTraversalAnnotationLibrary::evaluateT(hkaiTraversalAnnotationLibrary *this, hkSimdFloat32 *result, unsigned int annotationIndex, hkVector4f *p, hkVector4f *left, hkVector4f *right)
{
  hkVector4f v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  hkSimdFloat32 *v10; // rax
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm0

  v6.m_quad = (__m128)this->m_annotations.m_data[annotationIndex].m_tEquation;
  v7 = _mm_mul_ps(right->m_quad, v6.m_quad);
  v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, v6.m_quad), 196);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = result;
  v11 = _mm_mul_ps(left->m_quad, v6.m_quad);
  v12 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9);
  v13 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, v6.m_quad), 196);
  v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v15 = _mm_mul_ps(p->m_quad, v6.m_quad);
  v16 = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, v6.m_quad), 196);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
  v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17);
  v19 = _mm_cmpltps(v18, v12);
  result->m_real = _mm_max_ps(
                     _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14),
                     _mm_or_ps(_mm_andnot_ps(v19, v12), _mm_and_ps(v18, v19)));
  return v10;
}

// File Line: 157
// RVA: 0xC39C40
unsigned int __fastcall hkaiTraversalAnnotationLibrary::getClosestDefined(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int partitionOffset, float *tInOut)
{
  return hkaiIntervalPartitionLibrary::getClosestDefined(
           &this->m_intervalPartitionLibrary,
           partitionOffset + this->m_annotations.m_data[annotationIndex].m_firstPartitionIndex,
           tInOut);
}

// File Line: 167
// RVA: 0xC39C70
unsigned int __fastcall hkaiTraversalAnnotationLibrary::isDefinedAt(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int partitionOffset, float t)
{
  return hkaiIntervalPartitionLibrary::isDefinedAt(
           &this->m_intervalPartitionLibrary,
           partitionOffset + this->m_annotations.m_data[annotationIndex].m_firstPartitionIndex,
           t);
}

// File Line: 177
// RVA: 0xC39CA0
unsigned int __fastcall hkaiTraversalAnnotationLibrary::tryEvaluateYAt(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int partitionOffset, float t, float *y)
{
  return hkaiIntervalPartitionLibrary::tryEvaluateYAt(
           &this->m_intervalPartitionLibrary,
           partitionOffset + this->m_annotations.m_data[annotationIndex].m_firstPartitionIndex,
           t,
           y);
}

// File Line: 187
// RVA: 0xC39CD0
unsigned int __fastcall hkaiTraversalAnnotationLibrary::tryGetIntDataAt(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int partitionOffset, float t, unsigned int *intData)
{
  return hkaiIntervalPartitionLibrary::tryGetIntDataAt(
           &this->m_intervalPartitionLibrary,
           partitionOffset + this->m_annotations.m_data[annotationIndex].m_firstPartitionIndex,
           t,
           intData);
}

// File Line: 197
// RVA: 0xC39D00
void __fastcall hkaiTraversalAnnotationLibrary::getVectorData(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int vectorOffset, hkVector4f *vecOut)
{
  *vecOut = this->m_vectorLibrary.m_data[vectorOffset + this->m_annotations.m_data[annotationIndex].m_firstVectorIndex];
}

// File Line: 207
// RVA: 0xC39D30
unsigned __int16 __fastcall hkaiTraversalAnnotationLibrary::getNumPartitionIntervals(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int partitionOffset)
{
  return hkaiIntervalPartitionLibrary::getNumIntervals(
           &this->m_intervalPartitionLibrary,
           partitionOffset + this->m_annotations.m_data[annotationIndex].m_firstPartitionIndex);
}

// File Line: 218
// RVA: 0xC39D60
void __fastcall hkaiTraversalAnnotationLibrary::getPartitionInterval(hkaiTraversalAnnotationLibrary *this, unsigned int annotationIndex, int partitionOffset, unsigned __int16 intervalIndex, hkaiIntervalPartition::Interval *intervalOut)
{
  hkaiIntervalPartitionLibrary::getInterval(
    &this->m_intervalPartitionLibrary,
    partitionOffset + this->m_annotations.m_data[annotationIndex].m_firstPartitionIndex,
    intervalIndex,
    intervalOut);
}

