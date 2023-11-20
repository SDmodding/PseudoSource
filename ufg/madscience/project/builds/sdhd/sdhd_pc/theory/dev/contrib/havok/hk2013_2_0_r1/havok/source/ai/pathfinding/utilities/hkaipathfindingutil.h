// File Line: 77
// RVA: 0xE57C0
void __fastcall hkaiPathfindingUtil::FindPathInput::~FindPathInput(hkaiPathfindingUtil::FindPathInput *this)
{
  hkaiPathfindingUtil::FindPathInput *v1; // rbx
  int v2; // er8
  int v3; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable';
  this->m_goalFaceKeys.m_size = 0;
  v2 = this->m_goalFaceKeys.m_capacityAndFlags;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_goalFaceKeys.m_data,
      4 * v2);
  v1->m_goalFaceKeys.m_data = 0i64;
  v1->m_goalFaceKeys.m_capacityAndFlags = 2147483648;
  v1->m_goalPoints.m_size = 0;
  v3 = v1->m_goalPoints.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_goalPoints.m_data,
      16 * v3);
  v1->m_goalPoints.m_data = 0i64;
  v1->m_goalPoints.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 167
// RVA: 0xE6350
void __fastcall hkaiPathfindingUtil::NearestFeatureCallback::~NearestFeatureCallback(hkaiPathfindingUtil::NearestFeatureCallback *this)
{
  this->vfptr = (hkaiPathfindingUtil::NearestFeatureCallbackVtbl *)&hkaiPathfindingUtil::NearestFeatureCallback::`vftable';
}

