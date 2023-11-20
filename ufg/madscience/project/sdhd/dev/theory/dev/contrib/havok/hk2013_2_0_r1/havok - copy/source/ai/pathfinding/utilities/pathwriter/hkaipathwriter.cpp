// File Line: 15
// RVA: 0xC20F80
void __fastcall hkaiPathWriter::hkaiPathWriter(hkaiPathWriter *this)
{
  this->m_totalNumOutput = 0;
}

// File Line: 19
// RVA: 0xC20FA0
void __fastcall hkaiPathWriter::init(hkaiPathWriter *this, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArray, hkaiPath::PathPoint *pathPtr, int maxLength)
{
  this->m_pathArrayOut = pathArray;
  this->m_pathPtrOut = pathPtr;
  this->m_maxNumOutput = maxLength;
  this->m_numWritten = 0;
  this->m_previousPoint = 0i64;
  this->m_totalDistance = 0i64;
}

// File Line: 38
// RVA: 0xC20FD0
void __fastcall hkaiPathWriter::addPointToPath(hkaiPathWriter *this, hkVector4f *p, hkVector4f *normal, int sectionId, unsigned int edgeData, char flags)
{
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  hkVector4f *v8; // rdi
  hkaiPathWriter *v9; // rbx
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  hkaiPath::PathPoint point; // [rsp+20h] [rbp-38h]

  v6 = p->m_quad;
  v7 = normal->m_quad;
  point.m_userEdgeData = edgeData;
  v8 = p;
  point.m_position.m_quad = v6;
  point.m_normal.m_quad = v7;
  v9 = this;
  point.m_sectionId = sectionId;
  point.m_flags.m_storage = flags;
  hkaiPathWriter::addPointToPathArray(this, &point);
  hkaiPathWriter::addPointToPathPointer(v9, &point);
  if ( v9->m_numWritten > 0 )
  {
    v10 = _mm_sub_ps(v9->m_previousPoint.m_quad, v8->m_quad);
    v11 = _mm_mul_ps(v10, v10);
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_rsqrt_ps(v12);
    v9->m_totalDistance.m_real = _mm_add_ps(
                                   _mm_andnot_ps(
                                     _mm_cmpleps(v12, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v13), v13)),
                                         _mm_mul_ps(*(__m128 *)_xmm, v13)),
                                       v12)),
                                   v9->m_totalDistance.m_real);
  }
  ++v9->m_numWritten;
  v9->m_previousPoint = (hkVector4f)v8->m_quad;
}

// File Line: 59
// RVA: 0xC210F0
void __fastcall hkaiPathWriter::addPointToPathArray(hkaiPathWriter *this, hkaiPath::PathPoint *point)
{
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v2; // rbx
  hkaiPath::PathPoint *v3; // rdi
  hkVector4f *v4; // rcx

  v2 = this->m_pathArrayOut;
  v3 = point;
  if ( this->m_pathArrayOut )
  {
    if ( v2->m_size == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 48);
    v4 = &v2->m_data[v2->m_size].m_position;
    if ( v4 )
    {
      *v4 = v3->m_position;
      v4[1] = v3->m_normal;
      v4[2] = *(hkVector4f *)&v3->m_userEdgeData;
    }
    ++v2->m_size;
  }
}

// File Line: 69
// RVA: 0xC21170
void __fastcall hkaiPathWriter::addPointToPathPointer(hkaiPathWriter *this, hkaiPath::PathPoint *point)
{
  hkaiPath::PathPoint *v2; // r8

  v2 = this->m_pathPtrOut;
  if ( v2 )
  {
    if ( this->m_totalNumOutput < this->m_maxNumOutput )
    {
      v2->m_position = point->m_position;
      v2->m_normal = point->m_normal;
      v2->m_userEdgeData = point->m_userEdgeData;
      v2->m_sectionId = point->m_sectionId;
      v2->m_flags.m_storage = point->m_flags.m_storage;
      ++this->m_pathPtrOut;
      ++this->m_totalNumOutput;
    }
  }
}

// File Line: 80
// RVA: 0xC210B0
void __fastcall hkaiPathWriter::addTerminatorToPathPointer(hkaiPathWriter *this)
{
  hkaiPath::PathPoint point; // [rsp+20h] [rbp-38h]

  *(_QWORD *)&point.m_userEdgeData = -2147483648i64;
  point.m_flags.m_storage = 0;
  point.m_position = 0i64;
  point.m_normal = 0i64;
  hkaiPathWriter::addPointToPathPointer(this, &point);
}

