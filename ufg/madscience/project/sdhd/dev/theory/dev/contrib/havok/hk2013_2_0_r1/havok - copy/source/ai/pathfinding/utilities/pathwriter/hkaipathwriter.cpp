// File Line: 15
// RVA: 0xC20F80
void __fastcall hkaiPathWriter::hkaiPathWriter(hkaiPathWriter *this)
{
  this->m_totalNumOutput = 0;
}

// File Line: 19
// RVA: 0xC20FA0
void __fastcall hkaiPathWriter::init(
        hkaiPathWriter *this,
        hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArray,
        hkaiPath::PathPoint *pathPtr,
        int maxLength)
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
void __fastcall hkaiPathWriter::addPointToPath(
        hkaiPathWriter *this,
        hkVector4f *p,
        hkVector4f *normal,
        int sectionId,
        unsigned int edgeData,
        char flags)
{
  __m128 m_quad; // xmm0
  __m128 v7; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  hkaiPath::PathPoint point; // [rsp+20h] [rbp-38h] BYREF

  m_quad = p->m_quad;
  v7 = normal->m_quad;
  point.m_userEdgeData = edgeData;
  point.m_position.m_quad = m_quad;
  point.m_normal.m_quad = v7;
  point.m_sectionId = sectionId;
  point.m_flags.m_storage = flags;
  hkaiPathWriter::addPointToPathArray(this, &point);
  hkaiPathWriter::addPointToPathPointer(this, &point);
  if ( this->m_numWritten > 0 )
  {
    v10 = _mm_sub_ps(this->m_previousPoint.m_quad, p->m_quad);
    v11 = _mm_mul_ps(v10, v10);
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_rsqrt_ps(v12);
    this->m_totalDistance.m_real = _mm_add_ps(
                                     _mm_andnot_ps(
                                       _mm_cmple_ps(v12, (__m128)0i64),
                                       _mm_mul_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v13), v13)),
                                           _mm_mul_ps(*(__m128 *)_xmm, v13)),
                                         v12)),
                                     this->m_totalDistance.m_real);
  }
  ++this->m_numWritten;
  this->m_previousPoint = (hkVector4f)p->m_quad;
}

// File Line: 59
// RVA: 0xC210F0
void __fastcall hkaiPathWriter::addPointToPathArray(hkaiPathWriter *this, hkaiPath::PathPoint *point)
{
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *m_pathArrayOut; // rbx
  __int64 v4; // rcx

  m_pathArrayOut = this->m_pathArrayOut;
  if ( this->m_pathArrayOut )
  {
    if ( m_pathArrayOut->m_size == (m_pathArrayOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, m_pathArrayOut, 48);
    v4 = (__int64)&m_pathArrayOut->m_data[m_pathArrayOut->m_size];
    if ( v4 )
    {
      *(hkVector4f *)v4 = point->m_position;
      *(hkVector4f *)(v4 + 16) = point->m_normal;
      *(_OWORD *)(v4 + 32) = *(_OWORD *)&point->m_userEdgeData;
    }
    ++m_pathArrayOut->m_size;
  }
}

// File Line: 69
// RVA: 0xC21170
void __fastcall hkaiPathWriter::addPointToPathPointer(hkaiPathWriter *this, hkaiPath::PathPoint *point)
{
  hkaiPath::PathPoint *m_pathPtrOut; // r8

  m_pathPtrOut = this->m_pathPtrOut;
  if ( m_pathPtrOut )
  {
    if ( this->m_totalNumOutput < this->m_maxNumOutput )
    {
      *m_pathPtrOut = *point;
      ++this->m_pathPtrOut;
      ++this->m_totalNumOutput;
    }
  }
}

// File Line: 80
// RVA: 0xC210B0
void __fastcall hkaiPathWriter::addTerminatorToPathPointer(hkaiPathWriter *this)
{
  hkaiPath::PathPoint point; // [rsp+20h] [rbp-38h] BYREF

  *(_QWORD *)&point.m_userEdgeData = 0xFFFFFFFF80000000ui64;
  point.m_flags.m_storage = 0;
  memset(&point, 0, 32);
  hkaiPathWriter::addPointToPathPointer(this, &point);
}

