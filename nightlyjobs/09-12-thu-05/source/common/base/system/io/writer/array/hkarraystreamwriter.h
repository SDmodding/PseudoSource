// File Line: 107
// RVA: 0xC66D50
void __fastcall hkMemoryTrackStreamWriter::~hkMemoryTrackStreamWriter(hkMemoryTrackStreamWriter *this)
{
  bool v1; // zf
  hkMemoryTrack *m_track; // rdi
  _QWORD **Value; // rax

  v1 = this->m_ownerShip == TRACK_TAKE;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryTrackStreamWriter::`vftable;
  if ( v1 )
  {
    m_track = this->m_track;
    if ( m_track )
    {
      hkMemoryTrack::~hkMemoryTrack(this->m_track);
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkMemoryTrack *, __int64))(*Value[11] + 16i64))(Value[11], m_track, 32i64);
      this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
    else
    {
      this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
  }
  else
  {
    this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
}

// File Line: 124
// RVA: 0xC66F10
hkResult *__fastcall ArrayOfTuplesImplementation::View::asStridedBasicArray(
        hkDebugDisplayHandler *this,
        hkResult *result,
        hkReferencedObject *source,
        hkDisplayGeometryBuilder *builder)
{
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 125
// RVA: 0xC66F20
__int64 __fastcall hkMemoryTrackStreamWriter::tell(hkMemoryTrackStreamWriter *this)
{
  return (unsigned int)(this->m_track->m_numBytesLastSector
                      + this->m_track->m_numBytesPerSector
                      * (this->m_track->m_sectors.m_size + this->m_track->m_numSectorsUnloaded - 1));
}

// File Line: 163
// RVA: 0xC82430
hkBool *__fastcall hkMemoryTrackStreamReader::isOk(hkMemoryTrackStreamReader *this, hkBool *result)
{
  result->m_bool = this->m_track->m_numBytesLastSector
                 + this->m_track->m_numBytesPerSector
                 * (this->m_track->m_sectors.m_size + this->m_track->m_numSectorsUnloaded - 1) > this->m_overflowOffset;
  return result;
}

// File Line: 206
// RVA: 0xC66C40
void __fastcall hkArrayStreamWriter::hkArrayStreamWriter(
        hkArrayStreamWriter *this,
        hkArray<char,hkContainerHeapAllocator> *arr,
        hkArrayStreamWriter::ArrayOwnership o)
{
  int v4; // r9d
  int v5; // eax
  int v6; // eax
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  this->m_memSizeAndFlags = -1;
  this->m_arr = arr;
  this->m_allocator = &hkContainerHeapAllocator::s_alloc;
  this->vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  this->m_referenceCount = 1;
  this->m_offset = arr->m_size;
  this->m_ownerShip = o;
  v4 = arr->m_size + 1;
  v5 = arr->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v4 )
  {
    v6 = 2 * v5;
    if ( v4 < v6 )
      v4 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&arr->m_data, v4, 1);
  }
  this->m_arr->m_data[this->m_arr->m_size] = 0;
}

// File Line: 218
// RVA: 0xC66CD0
void __fastcall hkArrayStreamWriter::~hkArrayStreamWriter(hkArrayStreamWriter *this)
{
  bool v1; // zf
  hkArrayBase<char> *m_arr; // rdi
  _QWORD **Value; // rax

  v1 = this->m_ownerShip == ARRAY_TAKE;
  this->vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  if ( v1 )
  {
    m_arr = this->m_arr;
    if ( m_arr )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkArrayBase<char> *, __int64))(*Value[11] + 16i64))(Value[11], m_arr, 16i64);
      this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
    else
    {
      this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
  }
  else
  {
    this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
}

// File Line: 247
// RVA: 0xC66F00
hkClass *__fastcall hkArrayStreamWriter::getClassType(hkArrayStreamWriter *this)
{
  return &hkArrayStreamWriterClass;
}

