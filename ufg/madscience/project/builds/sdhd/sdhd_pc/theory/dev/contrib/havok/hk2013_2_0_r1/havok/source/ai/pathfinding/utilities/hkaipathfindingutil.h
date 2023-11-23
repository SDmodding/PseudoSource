// File Line: 77
// RVA: 0xE57C0
void __fastcall hkaiPathfindingUtil::FindPathInput::~FindPathInput(hkaiPathfindingUtil::FindPathInput *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
  this->m_goalFaceKeys.m_size = 0;
  m_capacityAndFlags = this->m_goalFaceKeys.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_goalFaceKeys.m_data,
      4 * m_capacityAndFlags);
  this->m_goalFaceKeys.m_data = 0i64;
  this->m_goalFaceKeys.m_capacityAndFlags = 0x80000000;
  this->m_goalPoints.m_size = 0;
  v3 = this->m_goalPoints.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_goalPoints.m_data,
      16 * v3);
  this->m_goalPoints.m_data = 0i64;
  this->m_goalPoints.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 167
// RVA: 0xE6350
void __fastcall hkaiPathfindingUtil::NearestFeatureCallback::~NearestFeatureCallback(
        hkaiPathfindingUtil::NearestFeatureCallback *this)
{
  this->vfptr = (hkaiPathfindingUtil::NearestFeatureCallbackVtbl *)&hkaiPathfindingUtil::NearestFeatureCallback::`vftable;
}

