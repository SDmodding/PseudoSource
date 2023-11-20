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
  this->m_sectors.m_capacityAndFlags = 2147483648;
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
  hkMemoryTrack *v1; // rbx
  int v2; // er8

  v1 = this;
  hkMemoryTrack::clear(this);
  v2 = v1->m_sectors.m_capacityAndFlags;
  v1->m_sectors.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sectors.m_data,
      8 * v2);
  v1->m_sectors.m_capacityAndFlags = 2147483648;
  v1->m_sectors.m_data = 0i64;
}

// File Line: 32
// RVA: 0xC81B10
void __fastcall hkMemoryTrack::clear(hkMemoryTrack *this)
{
  hkMemoryTrack *v1; // rbx
  int v2; // ebp
  __int64 v3; // r14
  unsigned int v4; // esi
  char *v5; // rdi
  _QWORD **v6; // rax
  int v7; // er8

  v1 = this;
  v2 = 0;
  if ( this->m_sectors.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->m_numBytesPerSector;
      v5 = v1->m_sectors.m_data[v3];
      v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v6[11] + 16i64))(v6[11], v5, v4);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_sectors.m_size );
  }
  v7 = v1->m_sectors.m_capacityAndFlags;
  v1->m_sectors.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sectors.m_data,
      8 * v7);
  v1->m_sectors.m_data = 0i64;
  v1->m_sectors.m_capacityAndFlags = 2147483648;
  v1->m_numBytesLastSector = v1->m_numBytesPerSector;
  *(_QWORD *)&v1->m_numBytesRead = 0i64;
}

// File Line: 44
// RVA: 0xC81BE0
void __fastcall hkMemoryTrack::write(hkMemoryTrack *this, const void *data, int numBytes)
{
  int v3; // ebp
  char *v4; // r12
  hkMemoryTrack *v5; // rbx
  signed __int64 v6; // r15
  unsigned int v7; // er14
  int v8; // edi
  _QWORD **v9; // rax
  __int64 v10; // rdi
  char *v11; // rcx

  if ( numBytes > 0 )
  {
    v3 = numBytes;
    v4 = (char *)data;
    v5 = this;
    v6 = this->m_sectors.m_size - 1;
    while ( 1 )
    {
      v7 = v5->m_numBytesPerSector;
      v8 = v5->m_numBytesPerSector - v5->m_numBytesLastSector;
      if ( v5->m_numBytesPerSector == v5->m_numBytesLastSector )
      {
        v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v10 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v9[11] + 8i64))(v9[11], v7);
        if ( v5->m_sectors.m_size == (v5->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_sectors, 8);
        v5->m_sectors.m_data[v5->m_sectors.m_size++] = (char *)v10;
        v8 = v5->m_numBytesPerSector;
        v5->m_numBytesLastSector = 0;
        ++v6;
      }
      v11 = &v5->m_sectors.m_data[v6][v5->m_numBytesLastSector];
      if ( v3 <= v8 )
        break;
      hkString::memCpy(v11, v4, v8);
      v3 -= v8;
      v4 += v8;
      v5->m_numBytesLastSector = v5->m_numBytesPerSector;
      if ( v3 <= 0 )
        return;
    }
    hkString::memCpy(v11, v4, v3);
    v5->m_numBytesLastSector += v3;
  }
}

// File Line: 76
// RVA: 0xC81DB0
void __fastcall hkMemoryTrack::appendByMove(hkMemoryTrack *this, hkMemoryTrack *other)
{
  __int64 v2; // r15
  signed __int64 v3; // rbp
  hkMemoryTrack *v4; // rbx
  hkMemoryTrack *v5; // r12
  char **v6; // rax
  char *v7; // rsi
  unsigned int v8; // edi
  _QWORD **v9; // rax
  char **v10; // rax
  char *v11; // rsi
  unsigned int v12; // edi
  _QWORD **v13; // rax
  int v14; // er8

  v2 = other->m_sectors.m_size;
  v3 = 0i64;
  v4 = other;
  v5 = this;
  if ( (signed int)v2 - 1 > 0 )
  {
    do
    {
      v6 = v4->m_sectors.m_data;
      v7 = v6[v3];
      hkMemoryTrack::write(v5, v6[v3], v4->m_numBytesPerSector);
      v8 = v4->m_numBytesPerSector;
      v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v9[11] + 16i64))(v9[11], v7, v8);
      ++v3;
    }
    while ( v3 < (signed int)v2 - 1 );
  }
  if ( (_DWORD)v2 )
  {
    v10 = v4->m_sectors.m_data;
    v11 = v10[v2 - 1];
    hkMemoryTrack::write(v5, v10[v2 - 1], v4->m_numBytesLastSector);
    v12 = v4->m_numBytesPerSector;
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v13[11] + 16i64))(v13[11], v11, v12);
  }
  v14 = v4->m_sectors.m_capacityAndFlags;
  v4->m_sectors.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v4->m_sectors.m_data,
      8 * v14);
  v4->m_sectors.m_data = 0i64;
  v4->m_sectors.m_capacityAndFlags = 2147483648;
  hkMemoryTrack::clear(v4);
}

// File Line: 96
// RVA: 0xC81EE0
void __fastcall hkMemoryTrack::read(hkMemoryTrack *this, void *data, int numBytes)
{
  hkMemoryTrack *v3; // rdi
  int v4; // ecx
  char *v5; // r15
  int v6; // esi
  int v7; // ebp
  int v8; // ecx
  signed __int64 v9; // r14
  int v10; // ebx
  int v11; // ebx
  char *v12; // rdx

  v3 = this;
  v4 = this->m_numBytesRead;
  v5 = (char *)data;
  v6 = numBytes;
  v7 = v4 / v3->m_numBytesPerSector - v3->m_numSectorsUnloaded;
  v8 = v4 - v3->m_numBytesPerSector * (v4 / v3->m_numBytesPerSector);
  if ( numBytes > 0 )
  {
    v9 = v7;
    while ( 1 )
    {
      v10 = v7 >= v3->m_sectors.m_size - 1 ? v3->m_numBytesLastSector : v3->m_numBytesPerSector;
      v11 = v10 - v8;
      v12 = &v3->m_sectors.m_data[v9][v8];
      if ( v6 <= v11 )
        break;
      hkString::memCpy(v5, v12, v11);
      v3->m_numBytesRead += v11;
      v6 -= v11;
      v5 += v11;
      ++v7;
      ++v9;
      v8 = 0;
      if ( v6 <= 0 )
        return;
    }
    hkString::memCpy(v5, v12, v6);
    v3->m_numBytesRead += v6;
  }
}

// File Line: 127
// RVA: 0xC81CF0
void __fastcall hkMemoryTrack::unloadReadSectors(hkMemoryTrack *this)
{
  hkMemoryTrack *v1; // rsi
  int v2; // eax
  __int64 v3; // rbp
  unsigned int v4; // edi
  char *v5; // rbx
  _QWORD **v6; // rax
  int v7; // ecx
  char **v8; // rax
  __int64 v9; // rdx
  char *v10; // rcx

  v1 = this;
  v2 = (this->m_numBytesRead - this->m_numSectorsUnloaded * this->m_numBytesPerSector) / this->m_numBytesPerSector;
  if ( v2 > 0 )
  {
    v3 = (unsigned int)v2;
    do
    {
      v4 = v1->m_numBytesPerSector;
      v5 = *v1->m_sectors.m_data;
      v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v6[11] + 16i64))(v6[11], v5, v4);
      v7 = 8 * --v1->m_sectors.m_size;
      v8 = v1->m_sectors.m_data;
      if ( v7 > 0 )
      {
        v9 = ((unsigned int)(v7 - 1) >> 3) + 1;
        do
        {
          v10 = v8[1];
          ++v8;
          *(v8 - 1) = v10;
          --v9;
        }
        while ( v9 );
      }
      ++v1->m_numSectorsUnloaded;
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
__int64 __fastcall hkMemoryTrackStreamWriter::write(hkMemoryTrackStreamWriter *this, const void *mem, int size)
{
  unsigned int v3; // ebx

  v3 = size;
  hkMemoryTrack::write(this->m_track, mem, size);
  return v3;
}

// File Line: 152
// RVA: 0xC82190
void __fastcall hkArrayStreamWriter::clear(hkArrayStreamWriter *this)
{
  hkArrayStreamWriter *v1; // rbx
  hkArrayBase<char> *v2; // r8
  int v3; // er9
  int v4; // eax
  int v5; // eax
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->m_arr->m_size = 0;
  v2 = this->m_arr;
  this->m_offset = 0;
  v3 = v2->m_size + 1;
  v4 = v2->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < v3 )
  {
    v5 = 2 * v4;
    if ( v3 < v5 )
      v3 = v5;
    hkArrayUtil::_reserve(&result, this->m_allocator, v2, v3, 1);
  }
  v1->m_arr->m_data[v1->m_arr->m_size] = 0;
}

// File Line: 159
// RVA: 0xC82200
__int64 __fastcall hkArrayStreamWriter::write(hkArrayStreamWriter *this, const void *mem, int size)
{
  int v3; // esi
  hkArrayBase<char> *v4; // r8
  const void *v5; // rbp
  __int64 v6; // rdi
  hkArrayStreamWriter *v7; // rbx
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // er9
  int v12; // eax
  hkResult result; // [rsp+50h] [rbp+18h]

  v3 = size;
  v4 = this->m_arr;
  v5 = mem;
  v6 = v4->m_size;
  v7 = this;
  v8 = v4->m_size - this->m_offset;
  if ( v3 <= v8 )
  {
    if ( (v4->m_capacityAndFlags & 0x3FFFFFFF) > (signed int)v6 )
      v4->m_data[v6] = 0;
  }
  else
  {
    v9 = v3 + v6 - v8;
    v10 = v4->m_capacityAndFlags & 0x3FFFFFFF;
    v11 = v9 + 1;
    if ( v10 < v9 + 1 )
    {
      v12 = 2 * v10;
      if ( v11 < v12 )
        v11 = v12;
      hkArrayUtil::_reserve(&result, this->m_allocator, v4, v11, 1);
    }
    v7->m_arr->m_size = v9;
    v7->m_arr->m_data[v9] = 0;
  }
  hkString::memCpy(&v7->m_arr->m_data[v7->m_offset], v5, v3);
  v7->m_offset += v3;
  return (unsigned int)v3;
}

// File Line: 182
// RVA: 0xC81FD0
void __fastcall hkMemoryTrackStreamReader::hkMemoryTrackStreamReader(hkMemoryTrackStreamReader *this, hkMemoryTrack *track, hkMemoryTrackStreamReader::MemoryType t, bool unloadSectorsAfterRead)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_memType = t;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryTrackStreamReader::`vftable';
  this->m_track = track;
  this->m_overflowOffset = -1;
  this->m_unloadSectorsAfterRead = unloadSectorsAfterRead;
}

// File Line: 190
// RVA: 0xC82000
void __fastcall hkMemoryTrackStreamReader::~hkMemoryTrackStreamReader(hkMemoryTrackStreamReader *this)
{
  bool v1; // zf
  hkMemoryTrackStreamReader *v2; // rbx
  hkMemoryTrack *v3; // rdi
  _QWORD **v4; // rax

  v1 = this->m_memType == 1;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryTrackStreamReader::`vftable';
  if ( v1 )
  {
    v3 = this->m_track;
    if ( v3 )
    {
      hkMemoryTrack::~hkMemoryTrack(this->m_track);
      v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkMemoryTrack *, signed __int64))(*v4[11] + 16i64))(v4[11], v3, 32i64);
      v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
    }
    else
    {
      this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
    }
  }
  else
  {
    this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  }
}

// File Line: 198
// RVA: 0xC82090
__int64 __fastcall hkMemoryTrackStreamReader::read(hkMemoryTrackStreamReader *this, void *buf, int nbytes)
{
  void *v3; // rbp
  int v4; // esi
  hkMemoryTrackStreamReader *v5; // rbx
  hkMemoryTrack *v6; // r9
  int v7; // edx
  int v8; // edi
  __int64 result; // rax
  hkMemoryTrack *v10; // rcx
  char v11; // [rsp+30h] [rbp+8h]

  v3 = buf;
  v4 = nbytes;
  v5 = this;
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkMemoryTrackStreamReader *, char *))this->vfptr[1].__first_virtual_table_function__)(
                    this,
                    &v11) )
    return 0i64;
  v6 = v5->m_track;
  v7 = v6->m_numSectorsUnloaded - 1;
  v8 = v6->m_numBytesLastSector + v6->m_numBytesPerSector * (v6->m_sectors.m_size + v7) - v6->m_numBytesRead;
  if ( v4 < v8 )
    v8 = v4;
  if ( v4 <= v6->m_numBytesLastSector + v6->m_numBytesPerSector * (v6->m_sectors.m_size + v7) - v6->m_numBytesRead )
  {
    hkMemoryTrack::read(v6, v3, v8);
    if ( v5->m_unloadSectorsAfterRead )
    {
      hkMemoryTrack::unloadReadSectors(v5->m_track);
      v10 = v5->m_track;
      if ( v10->m_numBytesRead == v10->m_numBytesLastSector
                                + v10->m_numBytesPerSector * (v10->m_sectors.m_size + v10->m_numSectorsUnloaded - 1) )
      {
        hkMemoryTrack::clear(v10);
        v5->m_overflowOffset = -1;
      }
    }
    result = (unsigned int)v8;
  }
  else
  {
    result = 0i64;
    v5->m_overflowOffset = v4 + v6->m_numBytesRead;
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
hkResult *__fastcall hkArrayStreamWriter::seek(hkArrayStreamWriter *this, hkResult *result, int offset, hkStreamWriter::SeekWhence whence)
{
  int v4; // ebx
  hkResult *v5; // r14
  hkArrayStreamWriter *v6; // rsi
  __int32 v7; // er9
  hkArrayBase<char> *v8; // rbp
  int v9; // er15
  int v10; // eax
  int v11; // eax
  int v12; // er9
  signed __int64 v13; // rcx
  hkResult *v14; // rax
  hkResult resulta; // [rsp+68h] [rbp+20h]

  v4 = this->m_offset;
  v5 = result;
  v6 = this;
  if ( whence )
  {
    v7 = whence - 1;
    if ( v7 )
    {
      if ( v7 == 1 )
        v4 = this->m_arr->m_size - offset;
    }
    else
    {
      v4 += offset;
    }
  }
  else
  {
    v4 = offset;
  }
  if ( v4 < 0 )
  {
    result->m_enum = 1;
    v14 = result;
  }
  else
  {
    v8 = this->m_arr;
    if ( v4 > v8->m_size )
    {
      v9 = v4 + 1;
      v10 = v8->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v10 < v4 + 1 )
      {
        v11 = 2 * v10;
        v12 = v4 + 1;
        if ( v9 < v11 )
          v12 = v11;
        hkArrayUtil::_reserve(&resulta, this->m_allocator, v8, v12, 1);
      }
      v13 = v9 - v8->m_size;
      if ( v13 > 0 )
        memset(&v8->m_data[v8->m_size], 0, v13);
      v8->m_size = v9;
      v6->m_arr->m_size = v4;
    }
    v6->m_offset = v4;
    v5->m_enum = 0;
    v14 = v5;
  }
  return v14;
}

