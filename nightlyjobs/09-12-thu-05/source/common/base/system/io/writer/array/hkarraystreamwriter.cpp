// File Line: 15
// RVA: 0x15C7750
void dynamic_initializer_for__hkArrayStreamWriterClass__()
{
  hkClass::hkClass(
    &hkArrayStreamWriterClass,
    "hkArrayStreamWriter",
    0i64,
    40,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 19
// RVA: 0xC81A80
void __fastcall hkMemoryTrack::hkMemoryTrack(hkMemoryTrack *this, int numBytesPerSector)
{
  this->m_sectors.m_capacityAndFlags = 0x80000000;
  this->m_sectors.m_data = 0i64;
  this->m_sectors.m_size = 0;
  *(_QWORD *)&this->m_numBytesRead = 0i64;
  this->m_numBytesLastSector = numBytesPerSector;
  this->m_numBytesPerSector = numBytesPerSector;
}

// File Line: 27
// RVA: 0xC81AB0
void __fastcall hkMemoryTrack::~hkMemoryTrack(hkMemoryTrack *this)
{
  int m_capacityAndFlags; // r8d

  hkMemoryTrack::clear(this);
  m_capacityAndFlags = this->m_sectors.m_capacityAndFlags;
  this->m_sectors.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sectors.m_data,
      8 * m_capacityAndFlags);
  this->m_sectors.m_capacityAndFlags = 0x80000000;
  this->m_sectors.m_data = 0i64;
}

// File Line: 32
// RVA: 0xC81B10
void __fastcall hkMemoryTrack::clear(hkMemoryTrack *this)
{
  int v2; // ebp
  __int64 v3; // r14
  unsigned int m_numBytesPerSector; // esi
  char *v5; // rdi
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d

  v2 = 0;
  if ( this->m_sectors.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_numBytesPerSector = this->m_numBytesPerSector;
      v5 = this->m_sectors.m_data[v3];
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*Value[11] + 16i64))(Value[11], v5, m_numBytesPerSector);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_sectors.m_size );
  }
  m_capacityAndFlags = this->m_sectors.m_capacityAndFlags;
  this->m_sectors.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sectors.m_data,
      8 * m_capacityAndFlags);
  this->m_sectors.m_data = 0i64;
  this->m_sectors.m_capacityAndFlags = 0x80000000;
  this->m_numBytesLastSector = this->m_numBytesPerSector;
  *(_QWORD *)&this->m_numBytesRead = 0i64;
}

// File Line: 44
// RVA: 0xC81BE0
void __fastcall hkMemoryTrack::write(hkMemoryTrack *this, char *data, int numBytes)
{
  signed int v3; // ebp
  __int64 v6; // r15
  unsigned int m_numBytesPerSector; // r14d
  int v8; // edi
  _QWORD **Value; // rax
  char *v10; // rdi
  char *v11; // rcx

  if ( numBytes > 0 )
  {
    v3 = numBytes;
    v6 = this->m_sectors.m_size - 1;
    while ( 1 )
    {
      m_numBytesPerSector = this->m_numBytesPerSector;
      v8 = this->m_numBytesPerSector - this->m_numBytesLastSector;
      if ( this->m_numBytesPerSector == this->m_numBytesLastSector )
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v10 = (char *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(Value[11], m_numBytesPerSector);
        if ( this->m_sectors.m_size == (this->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_sectors.m_data, 8);
        this->m_sectors.m_data[this->m_sectors.m_size++] = v10;
        v8 = this->m_numBytesPerSector;
        this->m_numBytesLastSector = 0;
        ++v6;
      }
      v11 = &this->m_sectors.m_data[v6][this->m_numBytesLastSector];
      if ( v3 <= v8 )
        break;
      hkString::memCpy(v11, data, v8);
      v3 -= v8;
      data += v8;
      this->m_numBytesLastSector = this->m_numBytesPerSector;
      if ( v3 <= 0 )
        return;
    }
    hkString::memCpy(v11, data, v3);
    this->m_numBytesLastSector += v3;
  }
}

// File Line: 76
// RVA: 0xC81DB0
void __fastcall hkMemoryTrack::appendByMove(hkMemoryTrack *this, hkMemoryTrack *other)
{
  __int64 m_size; // r15
  __int64 i; // rbp
  char *v6; // rsi
  unsigned int m_numBytesPerSector; // edi
  _QWORD **Value; // rax
  char *v9; // rsi
  unsigned int v10; // edi
  _QWORD **v11; // rax
  int m_capacityAndFlags; // r8d

  m_size = other->m_sectors.m_size;
  for ( i = 0i64; i < (int)m_size - 1; ++i )
  {
    v6 = other->m_sectors.m_data[i];
    hkMemoryTrack::write(this, v6, other->m_numBytesPerSector);
    m_numBytesPerSector = other->m_numBytesPerSector;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*Value[11] + 16i64))(Value[11], v6, m_numBytesPerSector);
  }
  if ( (_DWORD)m_size )
  {
    v9 = other->m_sectors.m_data[m_size - 1];
    hkMemoryTrack::write(this, v9, other->m_numBytesLastSector);
    v10 = other->m_numBytesPerSector;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v11[11] + 16i64))(v11[11], v9, v10);
  }
  m_capacityAndFlags = other->m_sectors.m_capacityAndFlags;
  other->m_sectors.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      other->m_sectors.m_data,
      8 * m_capacityAndFlags);
  other->m_sectors.m_data = 0i64;
  other->m_sectors.m_capacityAndFlags = 0x80000000;
  hkMemoryTrack::clear(other);
}

// File Line: 96
// RVA: 0xC81EE0
void __fastcall hkMemoryTrack::read(hkMemoryTrack *this, char *data, int numBytes)
{
  int m_numBytesRead; // ecx
  signed int v6; // esi
  int v7; // ebp
  int v8; // ecx
  __int64 i; // r14
  int v10; // ebx
  signed int v11; // ebx
  char *v12; // rdx

  m_numBytesRead = this->m_numBytesRead;
  v6 = numBytes;
  v7 = m_numBytesRead / this->m_numBytesPerSector - this->m_numSectorsUnloaded;
  v8 = m_numBytesRead - this->m_numBytesPerSector * (m_numBytesRead / this->m_numBytesPerSector);
  if ( numBytes > 0 )
  {
    for ( i = v7; ; ++i )
    {
      v10 = v7 >= this->m_sectors.m_size - 1 ? this->m_numBytesLastSector : this->m_numBytesPerSector;
      v11 = v10 - v8;
      v12 = &this->m_sectors.m_data[i][v8];
      if ( v6 <= v11 )
        break;
      hkString::memCpy(data, v12, v11);
      this->m_numBytesRead += v11;
      v6 -= v11;
      data += v11;
      ++v7;
      v8 = 0;
      if ( v6 <= 0 )
        return;
    }
    hkString::memCpy(data, v12, v6);
    this->m_numBytesRead += v6;
  }
}

// File Line: 127
// RVA: 0xC81CF0
void __fastcall hkMemoryTrack::unloadReadSectors(hkMemoryTrack *this)
{
  int v2; // eax
  __int64 v3; // rbp
  unsigned int m_numBytesPerSector; // edi
  char *v5; // rbx
  _QWORD **Value; // rax
  int v7; // ecx
  char **m_data; // rax
  __int64 v9; // rdx
  char *v10; // rcx

  v2 = (this->m_numBytesRead - this->m_numSectorsUnloaded * this->m_numBytesPerSector) / this->m_numBytesPerSector;
  if ( v2 > 0 )
  {
    v3 = (unsigned int)v2;
    do
    {
      m_numBytesPerSector = this->m_numBytesPerSector;
      v5 = *this->m_sectors.m_data;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*Value[11] + 16i64))(Value[11], v5, m_numBytesPerSector);
      --this->m_sectors.m_size;
      v7 = 8 * this->m_sectors.m_size;
      m_data = this->m_sectors.m_data;
      if ( v7 > 0 )
      {
        v9 = ((unsigned int)(v7 - 1) >> 3) + 1;
        do
        {
          v10 = m_data[1];
          *m_data++ = v10;
          --v9;
        }
        while ( v9 );
      }
      ++this->m_numSectorsUnloaded;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 139
// RVA: 0xC81FA0
void __fastcall hkMemoryTrackStreamWriter::clear(hkMemoryTrackStreamWriter *this)
{
  hkMemoryTrack::clear(this->m_track);
}

// File Line: 144
// RVA: 0xC81FB0
__int64 __fastcall hkMemoryTrackStreamWriter::write(hkMemoryTrackStreamWriter *this, char *mem, unsigned int size)
{
  hkMemoryTrack::write(this->m_track, mem, size);
  return size;
}

// File Line: 152
// RVA: 0xC82190
void __fastcall hkArrayStreamWriter::clear(hkArrayStreamWriter *this)
{
  hkArrayBase<char> *m_arr; // r8
  int v3; // r9d
  int v4; // eax
  int v5; // eax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  this->m_arr->m_size = 0;
  m_arr = this->m_arr;
  this->m_offset = 0;
  v3 = m_arr->m_size + 1;
  v4 = m_arr->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < v3 )
  {
    v5 = 2 * v4;
    if ( v3 < v5 )
      v3 = v5;
    hkArrayUtil::_reserve(&result, this->m_allocator, (const void **)&m_arr->m_data, v3, 1);
  }
  this->m_arr->m_data[this->m_arr->m_size] = 0;
}

// File Line: 159
// RVA: 0xC82200
__int64 __fastcall hkArrayStreamWriter::write(hkArrayStreamWriter *this, const void *mem, unsigned int size)
{
  hkArrayBase<char> *m_arr; // r8
  __int64 m_size; // rdi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // r9d
  int v12; // eax
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  m_arr = this->m_arr;
  m_size = m_arr->m_size;
  v8 = m_arr->m_size - this->m_offset;
  if ( (int)size <= v8 )
  {
    if ( (m_arr->m_capacityAndFlags & 0x3FFFFFFF) > (int)m_size )
      m_arr->m_data[m_size] = 0;
  }
  else
  {
    v9 = size + m_size - v8;
    v10 = m_arr->m_capacityAndFlags & 0x3FFFFFFF;
    v11 = v9 + 1;
    if ( v10 < v9 + 1 )
    {
      v12 = 2 * v10;
      if ( v11 < v12 )
        v11 = v12;
      hkArrayUtil::_reserve(&result, this->m_allocator, (const void **)&m_arr->m_data, v11, 1);
    }
    this->m_arr->m_size = v9;
    this->m_arr->m_data[v9] = 0;
  }
  hkString::memCpy(&this->m_arr->m_data[this->m_offset], mem, size);
  this->m_offset += size;
  return size;
}

// File Line: 182
// RVA: 0xC81FD0
void __fastcall hkMemoryTrackStreamReader::hkMemoryTrackStreamReader(
        hkMemoryTrackStreamReader *this,
        hkMemoryTrack *track,
        hkMemoryTrackStreamReader::MemoryType t,
        bool unloadSectorsAfterRead)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_memType = t;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryTrackStreamReader::`vftable;
  this->m_track = track;
  this->m_overflowOffset = -1;
  this->m_unloadSectorsAfterRead = unloadSectorsAfterRead;
}

// File Line: 190
// RVA: 0xC82000
void __fastcall hkMemoryTrackStreamReader::~hkMemoryTrackStreamReader(hkMemoryTrackStreamReader *this)
{
  bool v1; // zf
  hkMemoryTrack *m_track; // rdi
  _QWORD **Value; // rax

  v1 = this->m_memType == MEMORY_TAKE;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryTrackStreamReader::`vftable;
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

// File Line: 198
// RVA: 0xC82090
__int64 __fastcall hkMemoryTrackStreamReader::read(hkMemoryTrackStreamReader *this, char *buf, int nbytes)
{
  hkMemoryTrack *m_track; // r9
  int v7; // edx
  int v8; // edi
  __int64 result; // rax
  hkMemoryTrack *v10; // rcx
  char v11; // [rsp+30h] [rbp+8h] BYREF

  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkMemoryTrackStreamReader *, char *))this->vfptr[1].__first_virtual_table_function__)(
                    this,
                    &v11) )
    return 0i64;
  m_track = this->m_track;
  v7 = m_track->m_numSectorsUnloaded - 1;
  v8 = m_track->m_numBytesLastSector
     + m_track->m_numBytesPerSector * (m_track->m_sectors.m_size + v7)
     - m_track->m_numBytesRead;
  if ( nbytes < v8 )
    v8 = nbytes;
  if ( nbytes <= m_track->m_numBytesLastSector
               + m_track->m_numBytesPerSector * (m_track->m_sectors.m_size + v7)
               - m_track->m_numBytesRead )
  {
    hkMemoryTrack::read(m_track, buf, v8);
    if ( this->m_unloadSectorsAfterRead )
    {
      hkMemoryTrack::unloadReadSectors(this->m_track);
      v10 = this->m_track;
      if ( v10->m_numBytesRead == v10->m_numBytesLastSector
                                + v10->m_numBytesPerSector * (v10->m_sectors.m_size + v10->m_numSectorsUnloaded - 1) )
      {
        hkMemoryTrack::clear(v10);
        this->m_overflowOffset = -1;
      }
    }
    return (unsigned int)v8;
  }
  else
  {
    result = 0i64;
    this->m_overflowOffset = nbytes + m_track->m_numBytesRead;
  }
  return result;
}

// File Line: 233
// RVA: 0xC82180
__int64 __fastcall hkMemoryTrackStreamReader::skip(hkMemoryTrackStreamReader *this, int nbytes)
{
  return 0i64;
}

// File Line: 239
// RVA: 0xC822D0
hkResult *__fastcall hkArrayStreamWriter::seek(
        hkArrayStreamWriter *this,
        hkResult *result,
        int offset,
        hkStreamWriter::SeekWhence whence)
{
  int m_offset; // ebx
  int v7; // r9d
  hkArrayBase<char> *m_arr; // rbp
  int v9; // r15d
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  signed __int64 v13; // rcx
  hkResult resulta; // [rsp+68h] [rbp+20h] BYREF

  m_offset = this->m_offset;
  if ( whence )
  {
    v7 = whence - 1;
    if ( v7 )
    {
      if ( v7 == 1 )
        m_offset = this->m_arr->m_size - offset;
    }
    else
    {
      m_offset += offset;
    }
  }
  else
  {
    m_offset = offset;
  }
  if ( m_offset < 0 )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    m_arr = this->m_arr;
    if ( m_offset > m_arr->m_size )
    {
      v9 = m_offset + 1;
      v10 = m_arr->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v10 < m_offset + 1 )
      {
        v11 = 2 * v10;
        v12 = m_offset + 1;
        if ( v9 < v11 )
          v12 = v11;
        hkArrayUtil::_reserve(&resulta, this->m_allocator, (const void **)&m_arr->m_data, v12, 1);
      }
      v13 = v9 - m_arr->m_size;
      if ( v13 > 0 )
        memset(&m_arr->m_data[m_arr->m_size], 0, v13);
      m_arr->m_size = v9;
      this->m_arr->m_size = m_offset;
    }
    this->m_offset = m_offset;
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

