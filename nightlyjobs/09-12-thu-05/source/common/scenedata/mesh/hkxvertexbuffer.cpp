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
void __fastcall hkxVertexBuffer::VertexData::setSize(hkxVertexBuffer::VertexData *this, int n)
{
  unsigned int v2; // edi
  int v3; // edi
  int v4; // eax
  int v5; // esi
  hkxVertexBuffer::VertexData *v6; // rbx
  int v7; // eax
  int v8; // er9
  int v9; // eax
  signed int v10; // edi
  int v11; // eax
  int v12; // er9
  int v13; // eax
  signed int v14; // edi
  int v15; // eax
  int v16; // er9
  int v17; // eax
  signed int v18; // edi
  int v19; // eax
  int v20; // er9
  int v21; // eax
  signed int v22; // edi
  int v23; // eax
  int v24; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this->m_uint8Stride;
  this->m_numVerts = n;
  v3 = n * v2;
  v4 = this->m_uint8Data.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = n;
  v6 = this;
  if ( v4 < v3 )
  {
    v7 = 2 * v4;
    v8 = v3;
    if ( v3 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_uint8Data,
      v8,
      1);
  }
  v6->m_uint8Data.m_size = v3;
  v9 = v6->m_uint16Data.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = v5 * v6->m_uint16Stride >> 1;
  if ( v9 < v10 )
  {
    v11 = 2 * v9;
    v12 = v5 * v6->m_uint16Stride >> 1;
    if ( v10 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_uint16Data,
      v12,
      2);
  }
  v6->m_uint16Data.m_size = v10;
  v13 = v6->m_uint32Data.m_capacityAndFlags & 0x3FFFFFFF;
  v14 = v5 * v6->m_uint32Stride >> 2;
  if ( v13 < v14 )
  {
    v15 = 2 * v13;
    v16 = v5 * v6->m_uint32Stride >> 2;
    if ( v14 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_uint32Data,
      v16,
      4);
  }
  v6->m_uint32Data.m_size = v14;
  v17 = v6->m_floatData.m_capacityAndFlags & 0x3FFFFFFF;
  v18 = v5 * v6->m_floatStride >> 2;
  if ( v17 < v18 )
  {
    v19 = 2 * v17;
    v20 = v5 * v6->m_floatStride >> 2;
    if ( v18 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_floatData,
      v20,
      4);
  }
  v6->m_floatData.m_size = v18;
  v21 = v6->m_vectorData.m_capacityAndFlags & 0x3FFFFFFF;
  v22 = v5 * v6->m_vectorStride >> 2;
  if ( v21 < v22 )
  {
    v23 = 2 * v21;
    v24 = v5 * v6->m_vectorStride >> 2;
    if ( v22 < v23 )
      v24 = v23;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v24, 4);
  }
  v6->m_vectorData.m_size = v22;
}

// File Line: 38
// RVA: 0xE36E40
void __fastcall hkxVertexBuffer::VertexData::expandBy(hkxVertexBuffer::VertexData *this, int n)
{
  unsigned int v2; // esi
  int v3; // er9
  int v4; // ebp
  int v5; // eax
  hkxVertexBuffer::VertexData *v6; // rbx
  int v7; // eax
  unsigned int v8; // edi
  int v9; // er9
  int v10; // eax
  int v11; // eax
  unsigned int v12; // edi
  int v13; // er9
  int v14; // eax
  int v15; // eax
  unsigned int v16; // edi
  int v17; // er9
  int v18; // eax
  int v19; // eax
  unsigned int v20; // edi
  int v21; // er9
  int v22; // eax
  int v23; // eax
  hkResult result; // [rsp+48h] [rbp+10h]

  this->m_numVerts += n;
  v2 = n * this->m_uint8Stride;
  v3 = v2 + this->m_uint8Data.m_size;
  v4 = n;
  v5 = this->m_uint8Data.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = this;
  if ( v5 < v3 )
  {
    v7 = 2 * v5;
    if ( v3 < v7 )
      v3 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_uint8Data,
      v3,
      1);
  }
  v6->m_uint8Data.m_size += v2;
  v8 = v4 * v6->m_uint16Stride >> 1;
  v9 = v8 + v6->m_uint16Data.m_size;
  v10 = v6->m_uint16Data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v9 )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_uint16Data,
      v9,
      2);
  }
  v6->m_uint16Data.m_size += v8;
  v12 = v4 * v6->m_uint32Stride >> 2;
  v13 = v12 + v6->m_uint32Data.m_size;
  v14 = v6->m_uint32Data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 < v13 )
  {
    v15 = 2 * v14;
    if ( v13 < v15 )
      v13 = v15;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_uint32Data,
      v13,
      4);
  }
  v6->m_uint32Data.m_size += v12;
  v16 = v4 * v6->m_floatStride >> 2;
  v17 = v16 + v6->m_floatData.m_size;
  v18 = v6->m_floatData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    if ( v17 < v19 )
      v17 = v19;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_floatData,
      v17,
      4);
  }
  v6->m_floatData.m_size += v16;
  v20 = v4 * v6->m_vectorStride >> 2;
  v21 = v20 + v6->m_vectorData.m_size;
  v22 = v6->m_vectorData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < v21 )
  {
    v23 = 2 * v22;
    if ( v21 < v23 )
      v21 = v23;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v21, 4);
  }
  v6->m_vectorData.m_size += v20;
}

// File Line: 50
// RVA: 0xE36490
void __fastcall hkxVertexBuffer::hkxVertexBuffer(hkxVertexBuffer *this, hkFinishLoadedObjectFlag f)
{
  hkxVertexDescription *v2; // rcx

  v2 = &this->m_desc;
  *(_QWORD *)&v2[-8].m_decls.m_size = &hkxVertexBuffer::`vftable;
  hkxVertexDescription::hkxVertexDescription(v2, f);
}

// File Line: 55
// RVA: 0xE364C0
void __fastcall hkxVertexBuffer::setNumVertices(hkxVertexBuffer *this, int n, hkxVertexDescription *format)
{
  hkxVertexDescription *v3; // r12
  int v4; // er13
  hkxVertexBuffer *v5; // rbx
  hkxVertexBuffer::VertexData *v6; // r15
  int v7; // edi
  int v8; // ebp
  __int64 v9; // r15
  hkxVertexDescription::ElementDecl *v10; // rsi
  signed __int64 v11; // rax
  signed __int64 v12; // rdx
  char v13; // cl
  __int64 v14; // r8
  hkxVertexDescription::ElementDecl *v15; // rdx
  char v16; // cl
  unsigned int v17; // eax
  unsigned int v18; // edi
  int v19; // edi
  int v20; // eax
  int v21; // eax
  int v22; // er9
  int v23; // eax
  signed int v24; // edi
  int v25; // eax
  int v26; // er9
  int v27; // eax
  signed int v28; // edi
  int v29; // eax
  int v30; // er9
  int v31; // eax
  signed int v32; // edi
  int v33; // eax
  int v34; // er9
  signed int v35; // ebx
  int v36; // eax
  int v37; // eax
  int v38; // er9
  hkResult result; // [rsp+68h] [rbp+10h]

  v3 = format;
  v4 = n;
  v5 = this;
  if ( n != this->m_data.m_numVerts || !hkxVertexDescription::operator==(format, &this->m_desc) )
  {
    v6 = &v5->m_data;
    v7 = 0;
    v5->m_desc.m_decls.m_size = 0;
    hkxVertexBuffer::VertexData::clear(&v5->m_data);
    v8 = 0;
    if ( v3->m_decls.m_size > 0 )
    {
      v9 = 0i64;
      do
      {
        v10 = &v3->m_decls.m_data[v9];
        if ( v5->m_desc.m_decls.m_size == (v5->m_desc.m_decls.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_desc, 16);
        v11 = (signed __int64)&v5->m_desc.m_decls.m_data[v5->m_desc.m_decls.m_size];
        if ( v11 )
        {
          *(_DWORD *)v11 = 0;
          *(_QWORD *)(v11 + 4) = 0i64;
          *(_WORD *)(v11 + 14) = 0;
        }
        v12 = (signed __int64)&v5->m_desc.m_decls.m_data[v5->m_desc.m_decls.m_size++];
        *(_WORD *)(v12 + 4) = v10->m_type.m_storage;
        *(_WORD *)(v12 + 6) = v10->m_usage.m_storage;
        *(_BYTE *)(v12 + 12) = v10->m_numElements;
        *(_WORD *)(v12 + 14) = v10->m_hint.m_storage;
        switch ( v10->m_type.m_storage )
        {
          case 1u:
            *(_DWORD *)v12 = v5->m_data.m_uint8Stride;
            v5->m_data.m_uint8Stride += (unsigned __int8)v10->m_numElements;
            break;
          case 2u:
            *(_DWORD *)v12 = v5->m_data.m_uint16Stride;
            v5->m_data.m_uint16Stride += 2 * (unsigned __int8)v10->m_numElements;
            break;
          case 3u:
            *(_DWORD *)v12 = v5->m_data.m_uint32Stride;
            v5->m_data.m_uint32Stride += 4 * (unsigned __int8)v10->m_numElements;
            break;
          case 4u:
            v13 = v10->m_numElements;
            if ( (unsigned __int8)(v13 - 3) <= 1u )
            {
              *(_DWORD *)v12 = v5->m_data.m_vectorStride;
              v5->m_data.m_vectorStride += 16;
            }
            else if ( (unsigned __int8)v13 < 3u )
            {
              *(_DWORD *)v12 = v5->m_data.m_floatStride;
              v5->m_data.m_floatStride += 4 * (unsigned __int8)v10->m_numElements;
            }
            break;
        }
        ++v8;
        ++v9;
      }
      while ( v8 < v3->m_decls.m_size );
      v6 = &v5->m_data;
    }
    if ( v5->m_desc.m_decls.m_size > 0 )
    {
      v14 = 0i64;
      do
      {
        v15 = &v5->m_desc.m_decls.m_data[v14];
        switch ( v15->m_type.m_storage )
        {
          case 1u:
            v17 = v5->m_data.m_uint8Stride;
            goto LABEL_35;
          case 2u:
            v17 = v5->m_data.m_uint16Stride;
            goto LABEL_35;
          case 3u:
            v17 = v5->m_data.m_uint32Stride;
            goto LABEL_35;
          case 4u:
            v16 = v3->m_decls.m_data[v14].m_numElements;
            if ( (unsigned __int8)(v16 - 3) <= 1u )
            {
              v17 = v5->m_data.m_vectorStride;
              goto LABEL_35;
            }
            if ( (unsigned __int8)v16 < 3u )
            {
              v17 = v5->m_data.m_floatStride;
LABEL_35:
              v15->m_byteStride = v17;
              break;
            }
            break;
        }
        ++v7;
        ++v14;
      }
      while ( v7 < v5->m_desc.m_decls.m_size );
    }
    v18 = v5->m_data.m_uint8Stride;
    v5->m_data.m_numVerts = v4;
    v19 = v4 * v18;
    v20 = v5->m_data.m_uint8Data.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v20 < v19 )
    {
      v21 = 2 * v20;
      v22 = v19;
      if ( v19 < v21 )
        v22 = v21;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_data.m_uint8Data,
        v22,
        1);
    }
    v5->m_data.m_uint8Data.m_size = v19;
    v23 = v5->m_data.m_uint16Data.m_capacityAndFlags & 0x3FFFFFFF;
    v24 = v4 * v5->m_data.m_uint16Stride >> 1;
    if ( v23 < v24 )
    {
      v25 = 2 * v23;
      v26 = v4 * v5->m_data.m_uint16Stride >> 1;
      if ( v24 < v25 )
        v26 = v25;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_data.m_uint16Data,
        v26,
        2);
    }
    v5->m_data.m_uint16Data.m_size = v24;
    v27 = v5->m_data.m_uint32Data.m_capacityAndFlags & 0x3FFFFFFF;
    v28 = v4 * v5->m_data.m_uint32Stride >> 2;
    if ( v27 < v28 )
    {
      v29 = 2 * v27;
      v30 = v4 * v5->m_data.m_uint32Stride >> 2;
      if ( v28 < v29 )
        v30 = v29;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_data.m_uint32Data,
        v30,
        4);
    }
    v5->m_data.m_uint32Data.m_size = v28;
    v31 = v5->m_data.m_floatData.m_capacityAndFlags & 0x3FFFFFFF;
    v32 = v4 * v5->m_data.m_floatStride >> 2;
    if ( v31 < v32 )
    {
      v33 = 2 * v31;
      v34 = v4 * v5->m_data.m_floatStride >> 2;
      if ( v32 < v33 )
        v34 = v33;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_data.m_floatData,
        v34,
        4);
    }
    v5->m_data.m_floatData.m_size = v32;
    v35 = v4 * v5->m_data.m_vectorStride >> 2;
    v36 = v6->m_vectorData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v36 < v35 )
    {
      v37 = 2 * v36;
      v38 = v35;
      if ( v35 < v37 )
        v38 = v37;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v38, 4);
    }
    v6->m_vectorData.m_size = v35;
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
  hkxVertexDescription::ElementDecl *v2; // r9
  char v3; // dl

  v2 = elem;
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
  v3 = elem->m_numElements;
  if ( (unsigned __int8)(v3 - 3) > 1u )
  {
    if ( (unsigned __int8)v3 < 3u )
      return (char *)this->m_data.m_floatData.m_data + v2->m_byteOffset;
    return 0i64;
  }
  return (char *)this->m_data.m_vectorData.m_data + v2->m_byteOffset;
}

// File Line: 189
// RVA: 0xE36830
void *__fastcall hkxVertexBuffer::getVertexDataPtr(hkxVertexBuffer *this, hkxVertexDescription::ElementDecl *elem)
{
  return hkxVertexBuffer::getVertexDataPtr(this, elem);
}

// File Line: 194
// RVA: 0xE368B0
void __fastcall hkxVertexBuffer::copy(hkxVertexBuffer *this, hkxVertexBuffer *other, bool resize)
{
  hkxVertexBuffer *v3; // rsi
  hkxVertexBuffer *v4; // rdi
  bool v5; // bl
  bool v6; // r14
  unsigned int v7; // ebx
  unsigned int v8; // er8
  unsigned int v9; // er8
  unsigned int v10; // er8
  unsigned int v11; // er8
  unsigned int v12; // er8
  unsigned int v13; // ebx

  v3 = other;
  v4 = this;
  v5 = resize;
  v6 = hkxVertexDescription::operator==(&this->m_desc, &other->m_desc);
  if ( v5 )
    hkxVertexBuffer::setNumVertices(v4, v3->m_data.m_numVerts, &v4->m_desc);
  if ( v6 )
  {
    v7 = v4->m_data.m_numVerts;
    v8 = v4->m_data.m_uint8Stride;
    if ( v3->m_data.m_numVerts < v7 )
      v7 = v3->m_data.m_numVerts;
    if ( v8 )
      hkString::memCpy(v4->m_data.m_uint8Data.m_data, v3->m_data.m_uint8Data.m_data, v7 * v8);
    v9 = v4->m_data.m_uint16Stride;
    if ( v9 )
      hkString::memCpy(v4->m_data.m_uint16Data.m_data, v3->m_data.m_uint16Data.m_data, v7 * v9);
    v10 = v4->m_data.m_uint32Stride;
    if ( v10 )
      hkString::memCpy(v4->m_data.m_uint32Data.m_data, v3->m_data.m_uint32Data.m_data, v7 * v10);
    v11 = v4->m_data.m_floatStride;
    if ( v11 )
      hkString::memCpy(v4->m_data.m_floatData.m_data, v3->m_data.m_floatData.m_data, v7 * v11);
    v12 = v4->m_data.m_vectorStride;
    if ( v12 )
      hkString::memCpy(v4->m_data.m_vectorData.m_data, v3->m_data.m_vectorData.m_data, v7 * v12);
  }
  else
  {
    v13 = 0;
    if ( v3->m_data.m_numVerts )
    {
      do
      {
        hkxVertexBuffer::copyVertex(v4, v3, v13, v13);
        ++v13;
      }
      while ( v13 < v3->m_data.m_numVerts );
    }
  }
}

// File Line: 232
// RVA: 0xE369E0
void __fastcall hkxVertexBuffer::copyVertex(hkxVertexBuffer *this, hkxVertexBuffer *other, int vertFrom, int vertTo)
{
  hkxVertexDescription *v4; // r14
  hkxVertexBuffer *v5; // rsi
  hkxVertexBuffer *v6; // rdi
  int v7; // ebp
  int v8; // er13
  bool v9; // bl
  int v10; // er8
  int v11; // er8
  int v12; // er8
  int v13; // er8
  int v14; // er8
  int v15; // ebp
  __int64 v16; // r15
  __int64 v17; // r10
  hkxVertexDescription::ElementDecl *v18; // r14
  int v19; // ecx
  __int64 v20; // r9
  int v21; // er8
  __int64 v22; // rdx
  int v23; // er11
  hkEnum<enum hkxVertexDescription::DataUsage,unsigned short> *v24; // rax
  hkxVertexDescription::ElementDecl *v25; // rbx
  char *v26; // rsi
  char *v27; // rax
  int v28; // er8
  char dst[1040]; // [rsp+20h] [rbp-448h]
  hkxVertexDescription *v30; // [rsp+470h] [rbp+8h]
  hkxVertexBuffer *v31; // [rsp+478h] [rbp+10h]
  int v32; // [rsp+488h] [rbp+20h]

  v32 = vertTo;
  v31 = other;
  v4 = &this->m_desc;
  v5 = other;
  v6 = this;
  v7 = vertTo;
  v8 = vertFrom;
  v30 = &other->m_desc;
  v9 = hkxVertexDescription::operator==(&this->m_desc, &other->m_desc);
  hkString::memSet(dst, 0, 1028);
  if ( v7 >= (signed int)v6->m_data.m_numVerts || v8 >= (signed int)v5->m_data.m_numVerts )
    return;
  if ( v9 )
  {
    v10 = v6->m_data.m_uint8Stride;
    if ( v10 )
      hkString::memCpy(&v6->m_data.m_uint8Data.m_data[v7 * v10], &v5->m_data.m_uint8Data.m_data[v8 * v10], v10);
    v11 = v6->m_data.m_uint16Stride;
    if ( v11 )
      hkString::memCpy(
        (char *)v6->m_data.m_uint16Data.m_data + (unsigned int)(v7 * v11),
        (char *)v5->m_data.m_uint16Data.m_data + (unsigned int)(v8 * v11),
        v11);
    v12 = v6->m_data.m_uint32Stride;
    if ( v12 )
      hkString::memCpy(
        (char *)v6->m_data.m_uint32Data.m_data + (unsigned int)(v7 * v12),
        (char *)v5->m_data.m_uint32Data.m_data + (unsigned int)(v8 * v12),
        v12);
    v13 = v6->m_data.m_floatStride;
    if ( v13 )
      hkString::memCpy(
        (char *)v6->m_data.m_floatData.m_data + (unsigned int)(v7 * v13),
        (char *)v5->m_data.m_floatData.m_data + (unsigned int)(v8 * v13),
        v13);
    v14 = v6->m_data.m_vectorStride;
    if ( v14 )
      hkString::memCpy(
        (char *)v6->m_data.m_vectorData.m_data + (unsigned int)(v7 * v14),
        (char *)v5->m_data.m_vectorData.m_data + (unsigned int)(v8 * v14),
        v14);
    return;
  }
  v15 = 0;
  if ( v6->m_desc.m_decls.m_size <= 0 )
    return;
  v16 = 0i64;
  do
  {
    v17 = v30->m_decls.m_size;
    v18 = &v4->m_decls.m_data[v16];
    v19 = 0;
    v20 = v18->m_usage.m_storage;
    v21 = 0;
    v22 = 0i64;
    v23 = *(_DWORD *)&dst[4 * v20];
    if ( v17 <= 0 )
      goto LABEL_36;
    v24 = &v30->m_decls.m_data->m_usage;
    while ( v24->m_storage != (_WORD)v20 )
    {
LABEL_21:
      ++v22;
      ++v21;
      v24 += 8;
      if ( v22 >= v17 )
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
      *(_DWORD *)&dst[4 * v20] = v23 + 1;
      v26 = hkxVertexBuffer::getVertexDataPtr(v6, v18);
      v27 = (char *)hkxVertexBuffer::getVertexDataPtr(v31, v25);
      v28 = (unsigned __int8)v25->m_numElements;
      switch ( v18->m_type.m_storage )
      {
        case 1u:
          break;
        case 2u:
          v28 *= 2;
          break;
        case 3u:
          goto LABEL_31;
        case 4u:
          if ( (unsigned int)(v28 - 3) <= 1 )
          {
            v28 = 16;
          }
          else
          {
            if ( v28 < 3 )
            {
LABEL_31:
              v28 *= 4;
              break;
            }
LABEL_33:
            v28 = 0;
          }
          break;
        default:
          goto LABEL_33;
      }
      hkString::memCpy(&v26[v32 * v18->m_byteStride], &v27[v8 * v25->m_byteStride], v28);
    }
LABEL_36:
    ++v15;
    ++v16;
    v4 = &v6->m_desc;
  }
  while ( v15 < v6->m_desc.m_decls.m_size );
}v8 * v25->m_byteStride], v28);
    }
LABEL_36:


