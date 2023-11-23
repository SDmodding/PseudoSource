// File Line: 19
// RVA: 0xE19F60
void __fastcall hkpSerializedAgentNnEntry::~hkpSerializedAgentNnEntry(hkpSerializedAgentNnEntry *this)
{
  hkpEntity *m_bodyA; // rcx
  hkpEntity *m_bodyB; // rcx
  int m_capacityAndFlags; // r8d
  int v5; // r8d
  int v6; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpSerializedAgentNnEntry::`vftable;
  m_bodyA = this->m_bodyA;
  if ( m_bodyA )
    hkReferencedObject::removeReference(m_bodyA);
  m_bodyB = this->m_bodyB;
  if ( m_bodyB )
    hkReferencedObject::removeReference(m_bodyB);
  hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(&this->m_trackInfo);
  m_capacityAndFlags = this->m_cpIdMgr.m_capacityAndFlags;
  this->m_cpIdMgr.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_cpIdMgr.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_cpIdMgr.m_data = 0i64;
  this->m_cpIdMgr.m_capacityAndFlags = 0x80000000;
  v5 = this->m_contactPoints.m_capacityAndFlags;
  this->m_contactPoints.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_contactPoints.m_data,
      32 * v5);
  this->m_contactPoints.m_data = 0i64;
  this->m_contactPoints.m_capacityAndFlags = 0x80000000;
  v6 = this->m_propertiesStream.m_capacityAndFlags;
  this->m_propertiesStream.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_propertiesStream.m_data,
      v6 & 0x3FFFFFFF);
  this->m_propertiesStream.m_data = 0i64;
  this->m_propertiesStream.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 29
// RVA: 0xE19E10
void __fastcall hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(hkpSerializedTrack1nInfo *this)
{
  int v2; // edi
  __int64 v3; // rsi
  hkpAgent1nSector *v4; // rbp
  _QWORD **Value; // rax
  int v6; // edi
  __int64 v7; // rsi
  hkpSerializedSubTrack1nInfo **m_data; // rax
  hkpSerializedSubTrack1nInfo *v9; // rbp
  _QWORD **v10; // rax
  int m_capacityAndFlags; // r8d
  int v12; // r8d

  if ( this->m_sectors.m_capacityAndFlags >= 0 )
  {
    v2 = 0;
    if ( this->m_sectors.m_size > 0 )
    {
      v3 = 0i64;
      do
      {
        v4 = this->m_sectors.m_data[v3];
        if ( v4 )
        {
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*Value[11] + 16i64))(Value[11], v4, 512i64);
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->m_sectors.m_size );
    }
  }
  if ( this->m_subTracks.m_capacityAndFlags >= 0 )
  {
    v6 = 0;
    if ( this->m_subTracks.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        m_data = this->m_subTracks.m_data;
        v9 = m_data[v7];
        if ( v9 )
        {
          hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(m_data[v7]);
          v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpSerializedSubTrack1nInfo *, __int64))(*v10[11] + 16i64))(
            v10[11],
            v9,
            40i64);
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_subTracks.m_size );
    }
  }
  m_capacityAndFlags = this->m_subTracks.m_capacityAndFlags;
  this->m_subTracks.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_subTracks.m_data,
      8 * m_capacityAndFlags);
  this->m_subTracks.m_data = 0i64;
  this->m_subTracks.m_capacityAndFlags = 0x80000000;
  v12 = this->m_sectors.m_capacityAndFlags;
  this->m_sectors.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sectors.m_data,
      8 * v12);
  this->m_sectors.m_capacityAndFlags = 0x80000000;
  this->m_sectors.m_data = 0i64;
}

