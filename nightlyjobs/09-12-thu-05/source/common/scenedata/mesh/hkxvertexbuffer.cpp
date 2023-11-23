// File Line: 12
// RVA: 0xE36C90
void __fastcall hkxVertexBuffer::VertexData::clear(hkxVertexBuffer::VertexData *this)
{
  this->m_vectorData.m_size = 0;
  this->m_floatData.m_size = 0;
  this->m_uint32Data.m_size = 0;
  this->m_uint16Data.m_size = 0;
  this->m_uint8Data.m_size = 0;
  *(_QWORD *)&this->m_numVerts = 0i64;
  *(_QWORD *)&this->m_floatStride = 0i64;
  *(_QWORD *)&this->m_uint16Stride = 0i64;
}

// File Line: 28
// RVA: 0xE36CC0
void __fastcall hkxVertexBuffer::VertexData::setSize(hkxVertexBuffer::VertexData *this, unsigned int n)
{
  unsigned int m_uint8Stride; // edi
  int v3; // edi
  int v4; // eax
  int v7; // eax
  int v8; // r9d
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // r9d
  int v13; // eax
  int v14; // edi
  int v15; // eax
  int v16; // r9d
  int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // r9d
  int v21; // eax
  int v22; // edi
  int v23; // eax
  int v24; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  m_uint8Stride = this->m_uint8Stride;
  this->m_numVerts = n;
  v3 = n * m_uint8Stride;
  v4 = this->m_uint8Data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < v3 )
  {
    v7 = 2 * v4;
    v8 = v3;
    if ( v3 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_uint8Data.m_data, v8, 1);
  }
  this->m_uint8Data.m_size = v3;
  v9 = this->m_uint16Data.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = (n * this->m_uint16Stride) >> 1;
  if ( v9 < v10 )
  {
    v11 = 2 * v9;
    v12 = (n * this->m_uint16Stride) >> 1;
    if ( v10 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_uint16Data.m_data,
      v12,
      2);
  }
  this->m_uint16Data.m_size = v10;
  v13 = this->m_uint32Data.m_capacityAndFlags & 0x3FFFFFFF;
  v14 = (n * this->m_uint32Stride) >> 2;
  if ( v13 < v14 )
  {
    v15 = 2 * v13;
    v16 = (n * this->m_uint32Stride) >> 2;
    if ( v14 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_uint32Data.m_data,
      v16,
      4);
  }
  this->m_uint32Data.m_size = v14;
  v17 = this->m_floatData.m_capacityAndFlags & 0x3FFFFFFF;
  v18 = (n * this->m_floatStride) >> 2;
  if ( v17 < v18 )
  {
    v19 = 2 * v17;
    v20 = (n * this->m_floatStride) >> 2;
    if ( v18 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_floatData.m_data, v20, 4);
  }
  this->m_floatData.m_size = v18;
  v21 = this->m_vectorData.m_capacityAndFlags & 0x3FFFFFFF;
  v22 = (n * this->m_vectorStride) >> 2;
  if ( v21 < v22 )
  {
    v23 = 2 * v21;
    v24 = (n * this->m_vectorStride) >> 2;
    if ( v22 < v23 )
      v24 = v23;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_vectorData.m_data,
      v24,
      4);
  }
  this->m_vectorData.m_size = v22;
}

// File Line: 38
// RVA: 0xE36E40
void __fastcall hkxVertexBuffer::VertexData::expandBy(hkxVertexBuffer::VertexData *this, int n)
{
  unsigned int v2; // esi
  int v3; // r9d
  int v5; // eax
  int v7; // eax
  unsigned int v8; // edi
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  unsigned int v12; // edi
  int v13; // r9d
  int v14; // eax
  int v15; // eax
  unsigned int v16; // edi
  int v17; // r9d
  int v18; // eax
  int v19; // eax
  unsigned int v20; // edi
  int v21; // r9d
  int v22; // eax
  int v23; // eax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  this->m_numVerts += n;
  v2 = n * this->m_uint8Stride;
  v3 = v2 + this->m_uint8Data.m_size;
  v5 = this->m_uint8Data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v3 )
  {
    v7 = 2 * v5;
    if ( v3 < v7 )
      v3 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_uint8Data.m_data, v3, 1);
  }
  this->m_uint8Data.m_size += v2;
  v8 = (n * this->m_uint16Stride) >> 1;
  v9 = v8 + this->m_uint16Data.m_size;
  v10 = this->m_uint16Data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v9 )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_uint16Data.m_data, v9, 2);
  }
  this->m_uint16Data.m_size += v8;
  v12 = (n * this->m_uint32Stride) >> 2;
  v13 = v12 + this->m_uint32Data.m_size;
  v14 = this->m_uint32Data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 < v13 )
  {
    v15 = 2 * v14;
    if ( v13 < v15 )
      v13 = v15;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_uint32Data.m_data,
      v13,
      4);
  }
  this->m_uint32Data.m_size += v12;
  v16 = (n * this->m_floatStride) >> 2;
  v17 = v16 + this->m_floatData.m_size;
  v18 = this->m_floatData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    if ( v17 < v19 )
      v17 = v19;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_floatData.m_data, v17, 4);
  }
  this->m_floatData.m_size += v16;
  v20 = (n * this->m_vectorStride) >> 2;
  v21 = v20 + this->m_vectorData.m_size;
  v22 = this->m_vectorData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < v21 )
  {
    v23 = 2 * v22;
    if ( v21 < v23 )
      v21 = v23;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_vectorData.m_data,
      v21,
      4);
  }
  this->m_vectorData.m_size += v20;
}

// File Line: 50
// RVA: 0xE36490
void __fastcall hkxVertexBuffer::hkxVertexBuffer(hkxVertexBuffer *this, hkFinishLoadedObjectFlag f)
{
  hkxVertexDescription *p_m_desc; // rcx

  p_m_desc = &this->m_desc;
  *(_QWORD *)&p_m_desc[-8].m_decls.m_size = &hkxVertexBuffer::`vftable;
  hkxVertexDescription::hkxVertexDescription(p_m_desc, f);
}

// File Line: 55
// RVA: 0xE364C0
void __fastcall hkxVertexBuffer::setNumVertices(hkxVertexBuffer *this, unsigned int n, hkxVertexDescription *format)
{
  hkxVertexBuffer::VertexData *p_m_data; // r15
  int v7; // edi
  int v8; // ebp
  __int64 v9; // r15
  hkxVertexDescription::ElementDecl *v10; // rsi
  hkxVertexDescription::ElementDecl *v11; // rax
  hkxVertexDescription::ElementDecl *v12; // rdx
  char m_numElements; // cl
  __int64 v14; // r8
  hkxVertexDescription::ElementDecl *v15; // rdx
  char v16; // cl
  unsigned int m_uint8Stride; // eax
  unsigned int v18; // edi
  int v19; // edi
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  int v23; // eax
  int v24; // edi
  int v25; // eax
  int v26; // r9d
  int v27; // eax
  int v28; // edi
  int v29; // eax
  int v30; // r9d
  int v31; // eax
  int v32; // edi
  int v33; // eax
  int v34; // r9d
  signed int v35; // ebx
  int v36; // eax
  int v37; // eax
  int v38; // r9d
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  if ( n != this->m_data.m_numVerts || !hkxVertexDescription::operator==(format, &this->m_desc) )
  {
    p_m_data = &this->m_data;
    v7 = 0;
    this->m_desc.m_decls.m_size = 0;
    hkxVertexBuffer::VertexData::clear(&this->m_data);
    v8 = 0;
    if ( format->m_decls.m_size > 0 )
    {
      v9 = 0i64;
      do
      {
        v10 = &format->m_decls.m_data[v9];
        if ( this->m_desc.m_decls.m_size == (this->m_desc.m_decls.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_desc.m_decls.m_data, 16);
        v11 = &this->m_desc.m_decls.m_data[this->m_desc.m_decls.m_size];
        if ( v11 )
        {
          v11->m_byteOffset = 0;
          *(_QWORD *)&v11->m_type.m_storage = 0i64;
          v11->m_hint.m_storage = 0;
        }
        v12 = &this->m_desc.m_decls.m_data[this->m_desc.m_decls.m_size++];
        v12->m_type.m_storage = v10->m_type.m_storage;
        v12->m_usage.m_storage = v10->m_usage.m_storage;
        v12->m_numElements = v10->m_numElements;
        v12->m_hint.m_storage = v10->m_hint.m_storage;
        switch ( v10->m_type.m_storage )
        {
          case 1u:
            v12->m_byteOffset = this->m_data.m_uint8Stride;
            this->m_data.m_uint8Stride += (unsigned __int8)v10->m_numElements;
            break;
          case 2u:
            v12->m_byteOffset = this->m_data.m_uint16Stride;
            this->m_data.m_uint16Stride += 2 * (unsigned __int8)v10->m_numElements;
            break;
          case 3u:
            v12->m_byteOffset = this->m_data.m_uint32Stride;
            this->m_data.m_uint32Stride += 4 * (unsigned __int8)v10->m_numElements;
            break;
          case 4u:
            m_numElements = v10->m_numElements;
            if ( (unsigned __int8)(m_numElements - 3) <= 1u )
            {
              v12->m_byteOffset = this->m_data.m_vectorStride;
              this->m_data.m_vectorStride += 16;
            }
            else if ( (unsigned __int8)m_numElements < 3u )
            {
              v12->m_byteOffset = this->m_data.m_floatStride;
              this->m_data.m_floatStride += 4 * (unsigned __int8)v10->m_numElements;
            }
            break;
        }
        ++v8;
        ++v9;
      }
      while ( v8 < format->m_decls.m_size );
      p_m_data = &this->m_data;
    }
    if ( this->m_desc.m_decls.m_size > 0 )
    {
      v14 = 0i64;
      do
      {
        v15 = &this->m_desc.m_decls.m_data[v14];
        switch ( v15->m_type.m_storage )
        {
          case 1u:
            m_uint8Stride = this->m_data.m_uint8Stride;
            goto LABEL_35;
          case 2u:
            m_uint8Stride = this->m_data.m_uint16Stride;
            goto LABEL_35;
          case 3u:
            m_uint8Stride = this->m_data.m_uint32Stride;
            goto LABEL_35;
          case 4u:
            v16 = format->m_decls.m_data[v14].m_numElements;
            if ( (unsigned __int8)(v16 - 3) <= 1u )
            {
              m_uint8Stride = this->m_data.m_vectorStride;
              goto LABEL_35;
            }
            if ( (unsigned __int8)v16 < 3u )
            {
              m_uint8Stride = this->m_data.m_floatStride;
LABEL_35:
              v15->m_byteStride = m_uint8Stride;
            }
            break;
        }
        ++v7;
        ++v14;
      }
      while ( v7 < this->m_desc.m_decls.m_size );
    }
    v18 = this->m_data.m_uint8Stride;
    this->m_data.m_numVerts = n;
    v19 = n * v18;
    v20 = this->m_data.m_uint8Data.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v20 < v19 )
    {
      v21 = 2 * v20;
      v22 = v19;
      if ( v19 < v21 )
        v22 = v21;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_data.m_uint8Data.m_data,
        v22,
        1);
    }
    this->m_data.m_uint8Data.m_size = v19;
    v23 = this->m_data.m_uint16Data.m_capacityAndFlags & 0x3FFFFFFF;
    v24 = (n * this->m_data.m_uint16Stride) >> 1;
    if ( v23 < v24 )
    {
      v25 = 2 * v23;
      v26 = (n * this->m_data.m_uint16Stride) >> 1;
      if ( v24 < v25 )
        v26 = v25;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_data.m_uint16Data.m_data,
        v26,
        2);
    }
    this->m_data.m_uint16Data.m_size = v24;
    v27 = this->m_data.m_uint32Data.m_capacityAndFlags & 0x3FFFFFFF;
    v28 = (n * this->m_data.m_uint32Stride) >> 2;
    if ( v27 < v28 )
    {
      v29 = 2 * v27;
      v30 = (n * this->m_data.m_uint32Stride) >> 2;
      if ( v28 < v29 )
        v30 = v29;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_data.m_uint32Data.m_data,
        v30,
        4);
    }
    this->m_data.m_uint32Data.m_size = v28;
    v31 = this->m_data.m_floatData.m_capacityAndFlags & 0x3FFFFFFF;
    v32 = (n * this->m_data.m_floatStride) >> 2;
    if ( v31 < v32 )
    {
      v33 = 2 * v31;
      v34 = (n * this->m_data.m_floatStride) >> 2;
      if ( v32 < v33 )
        v34 = v33;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_data.m_floatData.m_data,
        v34,
        4);
    }
    this->m_data.m_floatData.m_size = v32;
    v35 = (n * this->m_data.m_vectorStride) >> 2;
    v36 = p_m_data->m_vectorData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v36 < v35 )
    {
      v37 = 2 * v36;
      v38 = v35;
      if ( v35 < v37 )
        v38 = v37;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_data->m_vectorData.m_data,
        v38,
        4);
    }
    p_m_data->m_vectorData.m_size = v35;
  }
}

// File Line: 145
// RVA: 0xE36820
void __fastcall hkxVertexBuffer::expandNumVertices(hkxVertexBuffer *this, int n)
{
  hkxVertexBuffer::VertexData::expandBy(&this->m_data, n);
}

// File Line: 151
// RVA: 0xE36840
char *__fastcall hkxVertexBuffer::getVertexDataPtr(hkxVertexBuffer *this, hkxVertexDescription::ElementDecl *elem)
{
  char m_numElements; // dl

  switch ( elem->m_type.m_storage )
  {
    case 1u:
      return &this->m_data.m_uint8Data.m_data[elem->m_byteOffset];
    case 2u:
      return (char *)this->m_data.m_uint16Data.m_data + elem->m_byteOffset;
    case 3u:
      return (char *)this->m_data.m_uint32Data.m_data + elem->m_byteOffset;
  }
  if ( elem->m_type.m_storage != 4 )
    return 0i64;
  m_numElements = elem->m_numElements;
  if ( (unsigned __int8)(m_numElements - 3) > 1u )
  {
    if ( (unsigned __int8)m_numElements < 3u )
      return (char *)this->m_data.m_floatData.m_data + elem->m_byteOffset;
    return 0i64;
  }
  return (char *)this->m_data.m_vectorData.m_data + elem->m_byteOffset;
}

// File Line: 189
// RVA: 0xE36830
// attributes: thunk
void *__fastcall hkxVertexBuffer::getVertexDataPtr(hkxVertexBuffer *this, hkxVertexDescription::ElementDecl *elem)
{
  return ?getVertexDataPtr@hkxVertexBuffer@@QEAAPEAXAEBUElementDecl@hkxVertexDescription@@@Z(this, elem);
}

// File Line: 194
// RVA: 0xE368B0
void __fastcall hkxVertexBuffer::copy(hkxVertexBuffer *this, hkxVertexBuffer *other, bool resize)
{
  bool v6; // r14
  unsigned int m_numVerts; // ebx
  unsigned int m_uint8Stride; // r8d
  unsigned int m_uint16Stride; // r8d
  unsigned int m_uint32Stride; // r8d
  unsigned int m_floatStride; // r8d
  unsigned int m_vectorStride; // r8d
  unsigned int i; // ebx

  v6 = hkxVertexDescription::operator==(&this->m_desc, &other->m_desc);
  if ( resize )
    hkxVertexBuffer::setNumVertices(this, other->m_data.m_numVerts, &this->m_desc);
  if ( v6 )
  {
    m_numVerts = this->m_data.m_numVerts;
    m_uint8Stride = this->m_data.m_uint8Stride;
    if ( other->m_data.m_numVerts < m_numVerts )
      m_numVerts = other->m_data.m_numVerts;
    if ( m_uint8Stride )
      hkString::memCpy(this->m_data.m_uint8Data.m_data, other->m_data.m_uint8Data.m_data, m_numVerts * m_uint8Stride);
    m_uint16Stride = this->m_data.m_uint16Stride;
    if ( m_uint16Stride )
      hkString::memCpy(this->m_data.m_uint16Data.m_data, other->m_data.m_uint16Data.m_data, m_numVerts * m_uint16Stride);
    m_uint32Stride = this->m_data.m_uint32Stride;
    if ( m_uint32Stride )
      hkString::memCpy(this->m_data.m_uint32Data.m_data, other->m_data.m_uint32Data.m_data, m_numVerts * m_uint32Stride);
    m_floatStride = this->m_data.m_floatStride;
    if ( m_floatStride )
      hkString::memCpy(this->m_data.m_floatData.m_data, other->m_data.m_floatData.m_data, m_numVerts * m_floatStride);
    m_vectorStride = this->m_data.m_vectorStride;
    if ( m_vectorStride )
      hkString::memCpy(this->m_data.m_vectorData.m_data, other->m_data.m_vectorData.m_data, m_numVerts * m_vectorStride);
  }
  else
  {
    for ( i = 0; i < other->m_data.m_numVerts; ++i )
      hkxVertexBuffer::copyVertex(this, other, i, i);
  }
}

// File Line: 232
// RVA: 0xE369E0
void __fastcall hkxVertexBuffer::copyVertex(hkxVertexBuffer *this, hkxVertexBuffer *other, int vertFrom, int vertTo)
{
  hkxVertexDescription *p_m_desc; // r14
  bool v9; // bl
  unsigned int m_uint8Stride; // r8d
  unsigned int m_uint16Stride; // r8d
  unsigned int m_uint32Stride; // r8d
  unsigned int m_floatStride; // r8d
  unsigned int m_vectorStride; // r8d
  int v15; // ebp
  __int64 v16; // r15
  __int64 m_size; // r10
  hkxVertexDescription::ElementDecl *v18; // r14
  int v19; // ecx
  __int64 m_storage; // r9
  int v21; // r8d
  __int64 v22; // rdx
  int v23; // r11d
  hkEnum<enum hkxVertexDescription::DataUsage,unsigned short> *p_m_usage; // rax
  hkxVertexDescription::ElementDecl *v25; // rbx
  char *VertexDataPtr; // rsi
  char *v27; // rax
  unsigned int m_numElements; // r8d
  _DWORD dst[260]; // [rsp+20h] [rbp-448h] BYREF
  hkxVertexDescription *v30; // [rsp+470h] [rbp+8h]

  p_m_desc = &this->m_desc;
  v30 = &other->m_desc;
  v9 = hkxVertexDescription::operator==(&this->m_desc, &other->m_desc);
  hkString::memSet(dst, 0, 0x404u);
  if ( vertTo >= (signed int)this->m_data.m_numVerts || vertFrom >= (signed int)other->m_data.m_numVerts )
    return;
  if ( v9 )
  {
    m_uint8Stride = this->m_data.m_uint8Stride;
    if ( m_uint8Stride )
      hkString::memCpy(
        &this->m_data.m_uint8Data.m_data[vertTo * m_uint8Stride],
        &other->m_data.m_uint8Data.m_data[vertFrom * m_uint8Stride],
        m_uint8Stride);
    m_uint16Stride = this->m_data.m_uint16Stride;
    if ( m_uint16Stride )
      hkString::memCpy(
        (char *)this->m_data.m_uint16Data.m_data + vertTo * m_uint16Stride,
        (char *)other->m_data.m_uint16Data.m_data + vertFrom * m_uint16Stride,
        m_uint16Stride);
    m_uint32Stride = this->m_data.m_uint32Stride;
    if ( m_uint32Stride )
      hkString::memCpy(
        (char *)this->m_data.m_uint32Data.m_data + vertTo * m_uint32Stride,
        (char *)other->m_data.m_uint32Data.m_data + vertFrom * m_uint32Stride,
        m_uint32Stride);
    m_floatStride = this->m_data.m_floatStride;
    if ( m_floatStride )
      hkString::memCpy(
        (char *)this->m_data.m_floatData.m_data + vertTo * m_floatStride,
        (char *)other->m_data.m_floatData.m_data + vertFrom * m_floatStride,
        m_floatStride);
    m_vectorStride = this->m_data.m_vectorStride;
    if ( m_vectorStride )
      hkString::memCpy(
        (char *)this->m_data.m_vectorData.m_data + vertTo * m_vectorStride,
        (char *)other->m_data.m_vectorData.m_data + vertFrom * m_vectorStride,
        m_vectorStride);
    return;
  }
  v15 = 0;
  if ( this->m_desc.m_decls.m_size <= 0 )
    return;
  v16 = 0i64;
  do
  {
    m_size = v30->m_decls.m_size;
    v18 = &p_m_desc->m_decls.m_data[v16];
    v19 = 0;
    m_storage = v18->m_usage.m_storage;
    v21 = 0;
    v22 = 0i64;
    v23 = dst[m_storage];
    if ( m_size <= 0 )
      goto LABEL_36;
    p_m_usage = &v30->m_decls.m_data->m_usage;
    while ( p_m_usage->m_storage != (_WORD)m_storage )
    {
LABEL_21:
      ++v22;
      ++v21;
      p_m_usage += 8;
      if ( v22 >= m_size )
        goto LABEL_36;
    }
    if ( v19 != v23 )
    {
      ++v19;
      goto LABEL_21;
    }
    v25 = &v30->m_decls.m_data[v21];
    if ( v25 && v18->m_type.m_storage == v25->m_type.m_storage )
    {
      dst[m_storage] = v23 + 1;
      VertexDataPtr = hkxVertexBuffer::getVertexDataPtr(this, v18);
      v27 = (char *)hkxVertexBuffer::getVertexDataPtr(other, v25);
      m_numElements = (unsigned __int8)v25->m_numElements;
      switch ( v18->m_type.m_storage )
      {
        case 1u:
          break;
        case 2u:
          m_numElements *= 2;
          break;
        case 3u:
          goto LABEL_31;
        case 4u:
          if ( m_numElements - 3 <= 1 )
          {
            m_numElements = 16;
          }
          else
          {
            if ( (unsigned __int8)v25->m_numElements < 3u )
            {
LABEL_31:
              m_numElements *= 4;
              break;
            }
LABEL_33:
            m_numElements = 0;
          }
          break;
        default:
          goto LABEL_33;
      }
      hkString::memCpy(&VertexDataPtr[vertTo * v18->m_byteStride], &v27[vertFrom * v25->m_byteStride], m_numElements);
    }
LABEL_36:
    ++v15;
    ++v16;
    p_m_desc = &this->m_desc;
  }
  while ( v15 < this->m_desc.m_decls.m_size );
}

