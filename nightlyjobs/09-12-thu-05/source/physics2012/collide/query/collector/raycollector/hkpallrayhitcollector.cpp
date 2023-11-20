// File Line: 14
// RVA: 0xD08E90
void __fastcall hkpAllRayHitCollector::addRayHit(hkpAllRayHitCollector *this, hkpCdBody *cdBody, hkpShapeRayCastCollectorOutput *hitInfo)
{
  signed int *v3; // rbx
  hkpShapeRayCastCollectorOutput *v4; // rbp
  hkpCdBody *v5; // rsi
  signed __int64 v6; // rcx
  __int64 v7; // rcx
  signed __int64 v8; // rdi
  hkpCdBody *v9; // rax
  hkpCdBody *v10; // rcx

  v3 = (signed int *)&this->m_hits;
  v4 = hitInfo;
  v5 = cdBody;
  if ( this->m_hits.m_size == (this->m_hits.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 96);
  v6 = *(_QWORD *)v3 + 96i64 * v3[2];
  if ( v6 )
  {
    *(_DWORD *)(v6 + 16) = 1065353216;
    *(_DWORD *)(v6 + 20) = -1;
    *(_DWORD *)(v6 + 64) = 0;
    *(_DWORD *)(v6 + 32) = -1;
    *(_QWORD *)(v6 + 80) = 0i64;
  }
  v7 = v3[2];
  v3[2] = v7 + 1;
  v8 = *(_QWORD *)v3 + 96 * v7;
  *(hkVector4f *)v8 = v4->m_normal;
  *(float *)(v8 + 16) = v4->m_hitFraction;
  *(_DWORD *)(v8 + 20) = v4->m_extraInfo;
  *(_DWORD *)(v8 + 24) = v4->m_pad[0];
  *(_DWORD *)(v8 + 28) = v4->m_pad[1];
  hkpRayHitCollector::shapeKeysFromCdBody((unsigned int *)(v8 + 32), 8, v5);
  v9 = v5->m_parent;
  if ( v9 )
  {
    do
    {
      v10 = v9;
      v9 = v9->m_parent;
    }
    while ( v9 );
    *(_QWORD *)(v8 + 80) = v10;
  }
  else
  {
    *(_QWORD *)(v8 + 80) = v5;
  }
}

// File Line: 23
// RVA: 0xD08E60
void __fastcall hkpAllRayHitCollector::sortHits(hkpAllRayHitCollector *this)
{
  int v1; // er8

  v1 = this->m_hits.m_size;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkpWorldRayCastOutput,hkAlgorithm::less<hkpWorldRayCastOutput>>(
      this->m_hits.m_data,
      0,
      v1 - 1,
      0);
}

