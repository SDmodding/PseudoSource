// File Line: 19
// RVA: 0xE19F60
void __fastcall hkpSerializedAgentNnEntry::~hkpSerializedAgentNnEntry(hkpSerializedAgentNnEntry *this)
{
  hkpSerializedAgentNnEntry *v1; // rbx
  hkpEntity *v2; // rcx
  hkReferencedObject *v3; // rcx
  int v4; // er8
  int v5; // er8
  int v6; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSerializedAgentNnEntry::`vftable;
  v2 = this->m_bodyA;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v3 = (hkReferencedObject *)&v1->m_bodyB->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(&v1->m_trackInfo);
  v4 = v1->m_cpIdMgr.m_capacityAndFlags;
  v1->m_cpIdMgr.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_cpIdMgr.m_data,
      v4 & 0x3FFFFFFF);
  v1->m_cpIdMgr.m_data = 0i64;
  v1->m_cpIdMgr.m_capacityAndFlags = 2147483648;
  v5 = v1->m_contactPoints.m_capacityAndFlags;
  v1->m_contactPoints.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_contactPoints.m_data,
      32 * v5);
  v1->m_contactPoints.m_data = 0i64;
  v1->m_contactPoints.m_capacityAndFlags = 2147483648;
  v6 = v1->m_propertiesStream.m_capacityAndFlags;
  v1->m_propertiesStream.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_propertiesStream.m_data,
      v6 & 0x3FFFFFFF);
  v1->m_propertiesStream.m_data = 0i64;
  v1->m_propertiesStream.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 29
// RVA: 0xE19E10
void __fastcall hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo(hkpSerializedTrack1nInfo *this)
{
  hkpSerializedTrack1nInfo *v1; // rbx
  int v2; // edi
  __int64 v3; // rsi
  hkpAgent1nSector *v4; // rbp
  _QWORD **v5; // rax
  int v6; // edi
  __int64 v7; // rsi
  hkpSerializedSubTrack1nInfo **v8; // rax
  hkpSerializedSubTrack1nInfo *v9; // rbp
  _QWORD **v10; // rax
  int v11; // er8
  int v12; // er8

  v1 = this;
  if ( this->m_sectors.m_capacityAndFlags >= 0 )
  {
    v2 = 0;
    if ( this->m_sectors.m_size > 0 )
    {
      v3 = 0i64;
      do
      {
        v4 = v1->m_sectors.m_data[v3];
        if ( v4 )
        {
          v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v5[11] + 16i64))(v5[11], v4, 512i64);
        }
        ++v2;
        ++v3;
      }
      while ( v2 < v1->m_sectors.m_size );
    }
  }
  if ( v1->m_subTracks.m_capacityAndFlags >= 0 )
  {
    v6 = 0;
    if ( v1->m_subTracks.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = v1->m_subTracks.m_data;
        v9 = v8[v7];
        if ( v9 )
        {
          hkpSerializedTrack1nInfo::~hkpSerializedTrack1nInfo((hkpSerializedTrack1nInfo *)&v8[v7]->m_sectors);
          v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpSerializedSubTrack1nInfo *, signed __int64))(*v10[11] + 16i64))(
            v10[11],
            v9,
            40i64);
        }
        ++v6;
        ++v7;
      }
      while ( v6 < v1->m_subTracks.m_size );
    }
  }
  v11 = v1->m_subTracks.m_capacityAndFlags;
  v1->m_subTracks.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_subTracks.m_data,
      8 * v11);
  v1->m_subTracks.m_data = 0i64;
  v1->m_subTracks.m_capacityAndFlags = 2147483648;
  v12 = v1->m_sectors.m_capacityAndFlags;
  v1->m_sectors.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sectors.m_data,
      8 * v12);
  v1->m_sectors.m_capacityAndFlags = 2147483648;
  v1->m_sectors.m_data = 0i64;
}

