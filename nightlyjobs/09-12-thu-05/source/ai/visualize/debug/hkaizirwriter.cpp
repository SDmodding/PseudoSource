// File Line: 19
// RVA: 0xC4F830
void __fastcall hkaiZirWriter::hkaiZirWriter(hkaiZirWriter *this, const char *filename, hkaiZirWriter::Window *window)
{
  hkOstream::hkOstream(&this->m_out, filename);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_prefixCounters.m_map,
    0);
  this->m_existingNames.m_capacityAndFlags = 0x80000000;
  this->m_existingNames.m_data = 0i64;
  this->m_existingNames.m_size = 0;
  hkOstream::printf(
    &this->m_out,
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
    "<CaR>\n"
    "<Construction>\n"
    "<Window x=\"%f\" y=\"%f\" w=\"%f\" h=\"%f\"/><Objects>\n",
    window->m_minX,
    window->m_minY,
    (float)(window->m_maxX - window->m_minX),
    (float)(window->m_maxY - window->m_minY));
}

// File Line: 33
// RVA: 0xC4F8D0
void __fastcall hkaiZirWriter::~hkaiZirWriter(hkaiZirWriter *this)
{
  int v2; // ebx
  hkStringPtr *v3; // rdi
  int m_capacityAndFlags; // r8d

  hkOstream::operator<<(&this->m_out, "</Objects>\n</Construction>\n</CaR>\n");
  hkOstream::flush(&this->m_out);
  v2 = this->m_existingNames.m_size - 1;
  if ( v2 >= 0 )
  {
    v3 = &this->m_existingNames.m_data[v2];
    do
    {
      hkStringPtr::~hkStringPtr(v3--);
      --v2;
    }
    while ( v2 >= 0 );
  }
  m_capacityAndFlags = this->m_existingNames.m_capacityAndFlags;
  this->m_existingNames.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_existingNames.m_data,
      8 * m_capacityAndFlags);
  this->m_existingNames.m_data = 0i64;
  this->m_existingNames.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_prefixCounters.m_map);
  hkOstream::~hkOstream(&this->m_out);
}

// File Line: 43
// RVA: 0xC4FE90
hkStringPtr *__fastcall hkaiZirWriter::getObjectName(hkaiZirWriter *this, int objectIndex)
{
  return &this->m_existingNames.m_data[objectIndex];
}

// File Line: 53
// RVA: 0xC4F980
__int64 __fastcall hkaiZirWriter::addPoint(
        hkaiZirWriter *this,
        float x,
        float y,
        hkaiZirWriter::PointStyle *pointStyle,
        hkaiZirWriter::NamePattern *namePattern,
        const char *description)
{
  unsigned int v8; // edi
  hkStringBuf result; // [rsp+50h] [rbp-B8h] BYREF

  hkaiZirWriter::makeUniqueName(this, &result, namePattern);
  v8 = hkaiZirWriter::addName(this, result.m_string.m_data);
  hkOstream::printf(&this->m_out, "<Point ");
  if ( pointStyle->m_hidden )
    hkOstream::printf(&this->m_out, "hidden=\"true\" ");
  hkOstream::printf(
    &this->m_out,
    "name=\"%s\" color=\"%d\" type=\"%s\" x=\"%f\" y=\"%f\" shape=\"%s\" fixed=\"true\">%s </Point>\n",
    result.m_string.m_data,
    (unsigned int)pointStyle->m_color,
    hkaiZirWriter::STROKE_STRINGS[pointStyle->m_stroke],
    x,
    y,
    hkaiZirWriter::SHAPE_STRINGS[pointStyle->m_shape],
    description);
  result.m_string.m_size = 0;
  if ( result.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      result.m_string.m_data,
      result.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v8;
}

// File Line: 90
// RVA: 0xC4FAB0
__int64 __fastcall hkaiZirWriter::addSegment(
        hkaiZirWriter *this,
        int pointA,
        int pointB,
        hkaiZirWriter::SegmentStyle *segmentStyle,
        hkaiZirWriter::NamePattern *namePattern,
        const char *descriptionIn)
{
  unsigned int v10; // r15d
  hkStringPtr *ObjectName; // rax
  hkStringPtr *v12; // rax
  hkStringBuf v14; // [rsp+30h] [rbp-D0h] BYREF
  hkStringBuf v15; // [rsp+C0h] [rbp-40h] BYREF
  hkStringBuf v16; // [rsp+150h] [rbp+50h] BYREF
  hkStringBuf result; // [rsp+1E0h] [rbp+E0h] BYREF

  hkaiZirWriter::makeUniqueName(this, &result, namePattern);
  v10 = hkaiZirWriter::addName(this, result.m_string.m_data);
  ObjectName = hkaiZirWriter::getObjectName(this, pointA);
  hkStringBuf::hkStringBuf(&v16, ObjectName);
  v12 = hkaiZirWriter::getObjectName(this, pointB);
  hkStringBuf::hkStringBuf(&v15, v12);
  v14.m_string.m_data = v14.m_string.m_storage;
  v14.m_string.m_capacityAndFlags = -2147483520;
  v14.m_string.m_size = 1;
  v14.m_string.m_storage[0] = 0;
  if ( descriptionIn )
    hkStringBuf::operator=(&v14, descriptionIn);
  else
    hkStringBuf::printf(&v14, "Line segment from %s to %s", v16.m_string.m_data, v15.m_string.m_data);
  hkOstream::printf(&this->m_out, "<Segment ");
  if ( segmentStyle->m_hidden )
    hkOstream::printf(&this->m_out, "hidden=\"true\" ");
  hkOstream::printf(
    &this->m_out,
    "name=\"%s\" color=\"%d\" type=\"%s\" ",
    result.m_string.m_data,
    (unsigned int)segmentStyle->m_color,
    hkaiZirWriter::STROKE_STRINGS[segmentStyle->m_stroke]);
  if ( segmentStyle->m_arrow )
    hkOstream::printf(&this->m_out, "arrow=\"true\" ");
  hkOstream::printf(
    &this->m_out,
    "from=\"%s\" to=\"%s\">%s </Segment>\n",
    v16.m_string.m_data,
    v15.m_string.m_data,
    v14.m_string.m_data);
  v14.m_string.m_size = 0;
  if ( v14.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v14.m_string.m_data,
      v14.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v14.m_string.m_data = 0i64;
  v14.m_string.m_capacityAndFlags = 0x80000000;
  v15.m_string.m_size = 0;
  if ( v15.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v15.m_string.m_data,
      v15.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v15.m_string.m_data = 0i64;
  v15.m_string.m_capacityAndFlags = 0x80000000;
  v16.m_string.m_size = 0;
  if ( v16.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v16.m_string.m_data,
      v16.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v16.m_string.m_data = 0i64;
  v16.m_string.m_capacityAndFlags = 0x80000000;
  result.m_string.m_size = 0;
  if ( result.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      result.m_string.m_data,
      result.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v10;
}

// File Line: 146
// RVA: 0xC4FD00
__int64 __fastcall hkaiZirWriter::addPolygon(
        hkaiZirWriter *this,
        hkArrayBase<int> *points,
        hkaiZirWriter::PolygonStyle *polygonStyle,
        hkaiZirWriter::NamePattern *namePattern,
        const char *description)
{
  unsigned int v8; // r15d
  __int64 m_size; // rbp
  __int64 v10; // rdi
  unsigned int v11; // esi
  hkStringPtr *ObjectName; // rax
  hkStringBuf result; // [rsp+30h] [rbp-A8h] BYREF

  hkaiZirWriter::makeUniqueName(this, &result, namePattern);
  v8 = hkaiZirWriter::addName(this, result.m_string.m_data);
  hkOstream::printf(&this->m_out, "<Polygon ");
  if ( polygonStyle->m_hidden )
    hkOstream::printf(&this->m_out, "hidden=\"true\" ");
  hkOstream::printf(
    &this->m_out,
    "name=\"%s\" color=\"%d\" type=\"%s\" background=\"true\" ",
    result.m_string.m_data,
    (unsigned int)polygonStyle->m_color,
    hkaiZirWriter::STROKE_STRINGS[polygonStyle->m_stroke]);
  if ( !polygonStyle->m_filled )
    hkOstream::printf(&this->m_out, "filled=\"false\" ");
  if ( !polygonStyle->m_solid )
    hkOstream::printf(&this->m_out, "solid=\"true\" ");
  m_size = points->m_size;
  v10 = 0i64;
  if ( m_size > 0 )
  {
    v11 = 1;
    do
    {
      ObjectName = hkaiZirWriter::getObjectName(this, points->m_data[v10]);
      hkOstream::printf(
        &this->m_out,
        "point%d=\"%s\" ",
        v11,
        (const char *)((unsigned __int64)ObjectName->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
      ++v10;
      ++v11;
    }
    while ( v10 < m_size );
  }
  hkOstream::printf(&this->m_out, ">%s </Polygon>\n", description);
  result.m_string.m_size = 0;
  if ( result.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      result.m_string.m_data,
      result.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v8;
}

// File Line: 192
// RVA: 0xC4FEB0
__int64 __fastcall hkaiZirWriter::getNextIndex(hkaiZirWriter *this, const char *prefix)
{
  hkStringMap<int,hkContainerHeapAllocator> *p_m_prefixCounters; // rdi
  unsigned int v4; // ebx

  p_m_prefixCounters = &this->m_prefixCounters;
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_prefixCounters,
         (unsigned __int64)prefix,
         0i64)
     + 1;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &p_m_prefixCounters->m_map,
    (unsigned __int64)prefix,
    (int)v4);
  return v4;
}

// File Line: 199
// RVA: 0xC4FF00
hkStringBuf *__fastcall hkaiZirWriter::makeUniqueName(
        hkaiZirWriter *this,
        hkStringBuf *result,
        hkaiZirWriter::NamePattern *namePattern)
{
  unsigned int m_index; // eax
  const char *m_prefix; // r8
  __int64 m_size; // rsi
  int v9; // edi
  __int64 v10; // rbx
  _QWORD *v11; // rax
  _QWORD *v12; // r14
  const char *v13; // rdx
  int v14; // eax
  const char *m_suffix; // [rsp+20h] [rbp-B8h]
  hkStringBuf s; // [rsp+30h] [rbp-A8h] BYREF
  hkStringPtr v18; // [rsp+E0h] [rbp+8h] BYREF

  m_index = namePattern->m_index;
  if ( m_index == -1 )
    m_index = hkaiZirWriter::getNextIndex(this, namePattern->m_prefix);
  m_prefix = namePattern->m_prefix;
  s.m_string.m_data = s.m_string.m_storage;
  m_suffix = namePattern->m_suffix;
  s.m_string.m_capacityAndFlags = -2147483520;
  s.m_string.m_size = 1;
  s.m_string.m_storage[0] = 0;
  hkStringBuf::printf(&s, "%s%d%s", m_prefix, m_index, m_suffix);
  while ( 1 )
  {
    hkStringPtr::hkStringPtr(&v18, s.m_string.m_data);
    m_size = this->m_existingNames.m_size;
    v9 = 0;
    v10 = 0i64;
    v12 = v11;
    if ( m_size > 0 )
    {
      while ( 1 )
      {
        v13 = (const char *)(*v12 & 0xFFFFFFFFFFFFFFFEui64);
        if ( ((unsigned __int64)this->m_existingNames.m_data[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) == 0 )
          break;
        if ( v13 )
        {
          v14 = hkString::strCmp(
                  (const char *)((unsigned __int64)this->m_existingNames.m_data[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                  v13);
          goto LABEL_9;
        }
LABEL_10:
        ++v10;
        ++v9;
        if ( v10 >= m_size )
          goto LABEL_11;
      }
      v14 = -(v13 != 0i64);
LABEL_9:
      if ( !v14 )
        goto LABEL_12;
      goto LABEL_10;
    }
LABEL_11:
    v9 = -1;
LABEL_12:
    hkStringPtr::~hkStringPtr(&v18);
    if ( v9 == -1 )
      break;
    hkStringBuf::append(&s, "", -1);
  }
  hkStringBuf::hkStringBuf(result, &s);
  s.m_string.m_size = 0;
  if ( s.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      s.m_string.m_data,
      s.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return result;
}

// File Line: 214
// RVA: 0xC50080
__int64 __fastcall hkaiZirWriter::addName(hkaiZirWriter *this, const char *name)
{
  unsigned int m_size; // edi
  hkStringPtr *v4; // rax
  hkStringPtr *v5; // rsi
  hkStringPtr *v6; // rcx
  hkStringPtr v8; // [rsp+30h] [rbp+8h] BYREF

  m_size = this->m_existingNames.m_size;
  hkStringPtr::hkStringPtr(&v8, name);
  v5 = v4;
  if ( this->m_existingNames.m_size == (this->m_existingNames.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_existingNames, 8);
  v6 = &this->m_existingNames.m_data[this->m_existingNames.m_size];
  if ( v6 )
    hkStringPtr::hkStringPtr(v6, v5);
  ++this->m_existingNames.m_size;
  hkStringPtr::~hkStringPtr(&v8);
  return m_size;
}

