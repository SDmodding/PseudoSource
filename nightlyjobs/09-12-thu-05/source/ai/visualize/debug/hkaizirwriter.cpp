// File Line: 19
// RVA: 0xC4F830
void __fastcall hkaiZirWriter::hkaiZirWriter(hkaiZirWriter *this, const char *filename, hkaiZirWriter::Window *window)
{
  hkaiZirWriter::Window *v3; // rbx
  hkaiZirWriter *v4; // rdi

  v3 = window;
  v4 = this;
  hkOstream::hkOstream(&this->m_out, filename);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v4->m_prefixCounters.m_map,
    0);
  v4->m_existingNames.m_capacityAndFlags = 2147483648;
  v4->m_existingNames.m_data = 0i64;
  v4->m_existingNames.m_size = 0;
  hkOstream::printf(
    &v4->m_out,
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
    "<CaR>\n"
    "<Construction>\n"
    "<Window x=\"%f\" y=\"%f\" w=\"%f\" h=\"%f\"/><Objects>\n",
    v3->m_minX,
    v3->m_minY,
    (float)(v3->m_maxX - v3->m_minX),
    (float)(v3->m_maxY - v3->m_minY));
}

// File Line: 33
// RVA: 0xC4F8D0
void __fastcall hkaiZirWriter::~hkaiZirWriter(hkaiZirWriter *this)
{
  hkaiZirWriter *v1; // rsi
  int v2; // ebx
  hkStringPtr *v3; // rdi
  int v4; // er8

  v1 = this;
  hkOstream::operator<<(&this->m_out, "</Objects>\n</Construction>\n</CaR>\n");
  hkOstream::flush(&v1->m_out);
  v2 = v1->m_existingNames.m_size - 1;
  if ( v2 >= 0 )
  {
    v3 = &v1->m_existingNames.m_data[v2];
    do
    {
      hkStringPtr::~hkStringPtr(v3);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  v4 = v1->m_existingNames.m_capacityAndFlags;
  v1->m_existingNames.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_existingNames.m_data,
      8 * v4);
  v1->m_existingNames.m_data = 0i64;
  v1->m_existingNames.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_prefixCounters.m_map);
  hkOstream::~hkOstream(&v1->m_out);
}

// File Line: 43
// RVA: 0xC4FE90
hkStringPtr *__fastcall hkaiZirWriter::getObjectName(hkaiZirWriter *this, int objectIndex)
{
  return &this->m_existingNames.m_data[objectIndex];
}

// File Line: 53
// RVA: 0xC4F980
__int64 __fastcall hkaiZirWriter::addPoint(hkaiZirWriter *this, float x, float y, hkaiZirWriter::PointStyle *pointStyle, hkaiZirWriter::NamePattern *namePattern, const char *description)
{
  hkaiZirWriter::PointStyle *v6; // rsi
  hkaiZirWriter *v7; // rbx
  unsigned int v8; // edi
  hkStringBuf result; // [rsp+50h] [rbp-B8h]

  v6 = pointStyle;
  v7 = this;
  hkaiZirWriter::makeUniqueName(this, &result, namePattern);
  v8 = hkaiZirWriter::addName(v7, result.m_string.m_data);
  hkOstream::printf(&v7->m_out, "<Point ");
  if ( v6->m_hidden )
    hkOstream::printf(&v7->m_out, "hidden=\"true\" ");
  hkOstream::printf(
    &v7->m_out,
    "name=\"%s\" color=\"%d\" type=\"%s\" x=\"%f\" y=\"%f\" shape=\"%s\" fixed=\"true\">%s </Point>\n",
    result.m_string.m_data,
    (unsigned int)v6->m_color,
    hkaiZirWriter::STROKE_STRINGS[v6->m_stroke],
    x,
    y,
    hkaiZirWriter::SHAPE_STRINGS[v6->m_shape],
    description);
  result.m_string.m_size = 0;
  if ( result.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      result.m_string.m_data,
      result.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v8;
}

// File Line: 90
// RVA: 0xC4FAB0
__int64 __fastcall hkaiZirWriter::addSegment(hkaiZirWriter *this, int pointA, int pointB, hkaiZirWriter::SegmentStyle *segmentStyle, hkaiZirWriter::NamePattern *namePattern, const char *descriptionIn)
{
  int v6; // edi
  int v7; // ebx
  hkaiZirWriter::SegmentStyle *v8; // r14
  hkaiZirWriter *v9; // rsi
  unsigned int v10; // er15
  hkStringPtr *v11; // rax
  hkStringPtr *v12; // rax
  hkStringBuf v14; // [rsp+30h] [rbp-D0h]
  hkStringBuf v15; // [rsp+C0h] [rbp-40h]
  hkStringBuf v16; // [rsp+150h] [rbp+50h]
  hkStringBuf result; // [rsp+1E0h] [rbp+E0h]

  v6 = pointB;
  v7 = pointA;
  v8 = segmentStyle;
  v9 = this;
  hkaiZirWriter::makeUniqueName(this, &result, namePattern);
  v10 = hkaiZirWriter::addName(v9, result.m_string.m_data);
  v11 = hkaiZirWriter::getObjectName(v9, v7);
  hkStringBuf::hkStringBuf(&v16, v11);
  v12 = hkaiZirWriter::getObjectName(v9, v6);
  hkStringBuf::hkStringBuf(&v15, v12);
  v14.m_string.m_data = v14.m_string.m_storage;
  v14.m_string.m_capacityAndFlags = -2147483520;
  v14.m_string.m_size = 1;
  v14.m_string.m_storage[0] = 0;
  if ( descriptionIn )
    hkStringBuf::operator=(&v14, descriptionIn);
  else
    hkStringBuf::printf(&v14, "Line segment from %s to %s", v16.m_string.m_data, v15.m_string.m_data);
  hkOstream::printf(&v9->m_out, "<Segment ");
  if ( v8->m_hidden )
    hkOstream::printf(&v9->m_out, "hidden=\"true\" ");
  hkOstream::printf(
    &v9->m_out,
    "name=\"%s\" color=\"%d\" type=\"%s\" ",
    result.m_string.m_data,
    (unsigned int)v8->m_color,
    hkaiZirWriter::STROKE_STRINGS[v8->m_stroke]);
  if ( v8->m_arrow )
    hkOstream::printf(&v9->m_out, "arrow=\"true\" ");
  hkOstream::printf(
    &v9->m_out,
    "from=\"%s\" to=\"%s\">%s </Segment>\n",
    v16.m_string.m_data,
    v15.m_string.m_data,
    v14.m_string.m_data);
  v14.m_string.m_size = 0;
  if ( v14.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v14.m_string.m_data,
      v14.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v14.m_string.m_data = 0i64;
  v14.m_string.m_capacityAndFlags = 2147483648;
  v15.m_string.m_size = 0;
  if ( v15.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v15.m_string.m_data,
      v15.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v15.m_string.m_data = 0i64;
  v15.m_string.m_capacityAndFlags = 2147483648;
  v16.m_string.m_size = 0;
  if ( v16.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v16.m_string.m_data,
      v16.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v16.m_string.m_data = 0i64;
  v16.m_string.m_capacityAndFlags = 2147483648;
  result.m_string.m_size = 0;
  if ( result.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      result.m_string.m_data,
      result.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v10;
}

// File Line: 146
// RVA: 0xC4FD00
__int64 __fastcall hkaiZirWriter::addPolygon(hkaiZirWriter *this, hkArrayBase<int> *points, hkaiZirWriter::PolygonStyle *polygonStyle, hkaiZirWriter::NamePattern *namePattern, const char *description)
{
  hkArrayBase<int> *v5; // r14
  hkaiZirWriter::PolygonStyle *v6; // rdi
  hkaiZirWriter *v7; // rbx
  unsigned int v8; // er15
  __int64 v9; // rbp
  __int64 v10; // rdi
  unsigned int v11; // esi
  hkStringPtr *v12; // rax
  hkStringBuf result; // [rsp+30h] [rbp-A8h]

  v5 = points;
  v6 = polygonStyle;
  v7 = this;
  hkaiZirWriter::makeUniqueName(this, &result, namePattern);
  v8 = hkaiZirWriter::addName(v7, result.m_string.m_data);
  hkOstream::printf(&v7->m_out, "<Polygon ");
  if ( v6->m_hidden )
    hkOstream::printf(&v7->m_out, "hidden=\"true\" ");
  hkOstream::printf(
    &v7->m_out,
    "name=\"%s\" color=\"%d\" type=\"%s\" background=\"true\" ",
    result.m_string.m_data,
    (unsigned int)v6->m_color,
    hkaiZirWriter::STROKE_STRINGS[v6->m_stroke]);
  if ( !v6->m_filled )
    hkOstream::printf(&v7->m_out, "filled=\"false\" ");
  if ( !v6->m_solid )
    hkOstream::printf(&v7->m_out, "solid=\"true\" ");
  v9 = v5->m_size;
  v10 = 0i64;
  if ( v9 > 0 )
  {
    v11 = 1;
    do
    {
      v12 = hkaiZirWriter::getObjectName(v7, v5->m_data[v10]);
      hkOstream::printf(&v7->m_out, "point%d=\"%s\" ", v11, (_QWORD)v12->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      ++v10;
      ++v11;
    }
    while ( v10 < v9 );
  }
  hkOstream::printf(&v7->m_out, ">%s </Polygon>\n", description);
  result.m_string.m_size = 0;
  if ( result.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      result.m_string.m_data,
      result.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v8;
}

// File Line: 192
// RVA: 0xC4FEB0
__int64 __fastcall hkaiZirWriter::getNextIndex(hkaiZirWriter *this, const char *prefix)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v2; // rdi
  const char *v3; // rsi
  unsigned int v4; // ebx

  v2 = &this->m_prefixCounters.m_map;
  v3 = prefix;
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_prefixCounters,
         (unsigned __int64)prefix,
         0i64)
     + 1;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(v2, (unsigned __int64)v3, (signed int)v4);
  return v4;
}

// File Line: 199
// RVA: 0xC4FF00
hkStringBuf *__fastcall hkaiZirWriter::makeUniqueName(hkaiZirWriter *this, hkStringBuf *result, hkaiZirWriter::NamePattern *namePattern)
{
  unsigned int v3; // eax
  hkaiZirWriter::NamePattern *v4; // rbx
  hkStringBuf *v5; // r15
  hkaiZirWriter *v6; // rbp
  const char *v7; // r8
  const char *v8; // ST20_8
  __int64 v9; // rsi
  signed int v10; // edi
  __int64 v11; // rbx
  _QWORD *v12; // rax
  _QWORD *v13; // r14
  const char *v14; // rdx
  int v15; // eax
  hkStringBuf s; // [rsp+30h] [rbp-A8h]
  hkStringPtr v18; // [rsp+E0h] [rbp+8h]

  v3 = namePattern->m_index;
  v4 = namePattern;
  v5 = result;
  v6 = this;
  if ( v3 == -1 )
    v3 = hkaiZirWriter::getNextIndex(this, namePattern->m_prefix);
  v7 = v4->m_prefix;
  s.m_string.m_data = s.m_string.m_storage;
  v8 = v4->m_suffix;
  s.m_string.m_capacityAndFlags = -2147483520;
  s.m_string.m_size = 1;
  s.m_string.m_storage[0] = 0;
  hkStringBuf::printf(&s, "%s%d%s", v7, v3, v8);
  while ( 1 )
  {
    hkStringPtr::hkStringPtr(&v18, s.m_string.m_data);
    v9 = v6->m_existingNames.m_size;
    v10 = 0;
    v11 = 0i64;
    v13 = v12;
    if ( v9 > 0 )
    {
      while ( 1 )
      {
        v14 = (const char *)(*v13 & 0xFFFFFFFFFFFFFFFEui64);
        if ( !((_QWORD)v6->m_existingNames.m_data[v11].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) )
          break;
        if ( v14 )
        {
          v15 = hkString::strCmp(
                  (const char *)((_QWORD)v6->m_existingNames.m_data[v11].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                  v14);
          goto LABEL_9;
        }
LABEL_10:
        ++v11;
        ++v10;
        if ( v11 >= v9 )
          goto LABEL_11;
      }
      v15 = -(v14 != 0i64);
LABEL_9:
      if ( !v15 )
        goto LABEL_12;
      goto LABEL_10;
    }
LABEL_11:
    v10 = -1;
LABEL_12:
    hkStringPtr::~hkStringPtr(&v18);
    if ( v10 == -1 )
      break;
    hkStringBuf::append(&s, "", -1);
  }
  hkStringBuf::hkStringBuf(v5, &s);
  s.m_string.m_size = 0;
  if ( s.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      s.m_string.m_data,
      s.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v5;
}

// File Line: 214
// RVA: 0xC50080
__int64 __fastcall hkaiZirWriter::addName(hkaiZirWriter *this, const char *name)
{
  unsigned int v2; // edi
  hkaiZirWriter *v3; // rbx
  hkStringPtr *v4; // rax
  hkStringPtr *v5; // rsi
  hkStringPtr *v6; // rcx
  hkStringPtr v8; // [rsp+30h] [rbp+8h]

  v2 = this->m_existingNames.m_size;
  v3 = this;
  hkStringPtr::hkStringPtr(&v8, name);
  v5 = v4;
  if ( v3->m_existingNames.m_size == (v3->m_existingNames.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_existingNames, 8);
  v6 = &v3->m_existingNames.m_data[v3->m_existingNames.m_size];
  if ( v6 )
    hkStringPtr::hkStringPtr(v6, v5);
  ++v3->m_existingNames.m_size;
  hkStringPtr::~hkStringPtr(&v8);
  return v2;
}

