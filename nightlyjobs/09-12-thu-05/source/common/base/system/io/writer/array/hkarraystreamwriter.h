// File Line: 107
// RVA: 0xC66D50
void __fastcall hkMemoryTrackStreamWriter::~hkMemoryTrackStreamWriter(hkMemoryTrackStreamWriter *this)
{
  bool v1; // zf
  hkMemoryTrackStreamWriter *v2; // rbx
  hkMemoryTrack *v3; // rdi
  _QWORD **v4; // rax

  v1 = this->m_ownerShip == 0;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryTrackStreamWriter::`vftable;
  if ( v1 )
  {
    v3 = this->m_track;
    if ( v3 )
    {
      hkMemoryTrack::~hkMemoryTrack(this->m_track);
      v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkMemoryTrack *, signed __int64))(*v4[11] + 16i64))(v4[11], v3, 32i64);
      v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
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
hkResult *__fastcall ArrayOfTuplesImplementation::View::asStridedBasicArray(hkDebugDisplayHandler *this, hkResult *result, hkReferencedObject *source, hkDisplayGeometryBuilder *builder)
{
  result->m_enum = 1;
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
void __fastcall hkArrayStreamWriter::hkArrayStreamWriter(hkArrayStreamWriter *this, hkArray<char,hkContainerHeapAllocator> *arr, hkArrayStreamWriter::ArrayOwnership o)
{
  hkArrayStreamWriter *v3; // rbx
  int v4; // er9
  int v5; // eax
  int v6; // eax
  hkResult result; // [rsp+50h] [rbp+18h]

  v3 = this;
  this->m_memSizeAndFlags = -1;
  this->m_arr = (hkArrayBase<char> *)&arr->m_data;
  this->m_allocator = (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc;
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
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, arr, v4, 1);
  }
  v3->m_arr->m_data[v3->m_arr->m_size] = 0;
}

// File Line: 218
// RVA: 0xC66CD0
void __fastcall hkArrayStreamWriter::~hkArrayStreamWriter(hkArrayStreamWriter *this)
{
  bool v1; // zf
  hkArrayStreamWriter *v2; // rbx
  hkArrayBase<char> *v3; // rdi
  _QWORD **v4; // rax

  v1 = this->m_ownerShip == 0;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  if ( v1 )
  {
    v3 = this->m_arr;
    if ( v3 )
    {
      v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkArrayBase<char> *, signed __int64))(*v4[11] + 16i64))(v4[11], v3, 16i64);
      v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
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

