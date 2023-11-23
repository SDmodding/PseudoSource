// File Line: 16
// RVA: 0xE6E200
void __fastcall hkDebugDisplay::hkDebugDisplay(hkDebugDisplay *this)
{
  _QWORD **Value; // rax
  hkCriticalSection *v3; // rax
  hkCriticalSection *v4; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDebugDisplay::`vftable;
  this->m_debugDisplayHandlers.m_data = 0i64;
  this->m_debugDisplayHandlers.m_size = 0;
  this->m_debugDisplayHandlers.m_capacityAndFlags = 0x80000000;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v3 )
  {
    hkCriticalSection::hkCriticalSection(v3, 0x3E8u);
    this->m_arrayLock = v4;
  }
  else
  {
    this->m_arrayLock = 0i64;
  }
}

// File Line: 21
// RVA: 0xE6E290
void __fastcall hkDebugDisplay::~hkDebugDisplay(hkDebugDisplay *this)
{
  hkCriticalSection *m_arrayLock; // rdi
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d

  m_arrayLock = this->m_arrayLock;
  this->vfptr = (hkBaseObjectVtbl *)&hkDebugDisplay::`vftable;
  if ( m_arrayLock )
  {
    DeleteCriticalSection(&m_arrayLock->m_section);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*Value[11] + 16i64))(Value[11], m_arrayLock, 40i64);
  }
  m_capacityAndFlags = this->m_debugDisplayHandlers.m_capacityAndFlags;
  this->m_debugDisplayHandlers.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_debugDisplayHandlers.m_data,
      8 * m_capacityAndFlags);
  this->m_debugDisplayHandlers.m_data = 0i64;
  this->m_debugDisplayHandlers.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 26
// RVA: 0xE6E330
void __fastcall hkDebugDisplay::addDebugDisplayHandler(hkDebugDisplay *this, hkDebugDisplayHandler *debugDisplay)
{
  EnterCriticalSection(&this->m_arrayLock->m_section);
  if ( this->m_debugDisplayHandlers.m_size == (this->m_debugDisplayHandlers.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_debugDisplayHandlers.m_data,
      8);
  this->m_debugDisplayHandlers.m_data[this->m_debugDisplayHandlers.m_size++] = debugDisplay;
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 33
// RVA: 0xE6E3B0
void __fastcall hkDebugDisplay::removeDebugDisplayHandler(hkDebugDisplay *this, hkDebugDisplayHandler *debugDisplay)
{
  __int64 m_size; // rdx
  int v5; // r8d
  __int64 v6; // r9
  hkDebugDisplayHandler **m_data; // rax

  EnterCriticalSection(&this->m_arrayLock->m_section);
  m_size = this->m_debugDisplayHandlers.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( (int)m_size > 0 )
  {
    m_data = this->m_debugDisplayHandlers.m_data;
    while ( *m_data != debugDisplay )
    {
      ++v6;
      ++v5;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_9;
    }
    if ( v5 >= 0 )
    {
      this->m_debugDisplayHandlers.m_size = m_size - 1;
      if ( (_DWORD)m_size - 1 != v5 )
        this->m_debugDisplayHandlers.m_data[v5] = this->m_debugDisplayHandlers.m_data[(int)m_size - 1];
    }
  }
LABEL_9:
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 44
// RVA: 0xE6E440
void __fastcall hkDebugDisplay::clear(hkDebugDisplay *this)
{
  hkCriticalSection *m_arrayLock; // rcx

  EnterCriticalSection(&this->m_arrayLock->m_section);
  m_arrayLock = this->m_arrayLock;
  this->m_debugDisplayHandlers.m_size = 0;
  LeaveCriticalSection(&m_arrayLock->m_section);
}

// File Line: 54
// RVA: 0xE6E470
void __fastcall hkDebugDisplay::addGeometry(
        hkDebugDisplay *this,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *geometries,
        hkTransformf *transform,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  int v10; // esi
  unsigned __int64 v11; // rbp
  int v12; // r14d
  __int64 v13; // rdi
  char v14; // [rsp+70h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = shapeIdHint;
    v12 = tag;
    v13 = 0i64;
    do
    {
      (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *, hkTransformf *, unsigned __int64, int, unsigned __int64, _DWORD))this->m_debugDisplayHandlers.m_data[v13]->vfptr->gap8)(
        this->m_debugDisplayHandlers.m_data[v13],
        &v14,
        geometries,
        transform,
        id,
        v12,
        v11,
        0);
      ++v10;
      ++v13;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 64
// RVA: 0xE6E530
void __fastcall hkDebugDisplay::addGeometry(
        hkDebugDisplay *this,
        hkDisplayGeometry *geometry,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  int v9; // edi
  unsigned __int64 v10; // rbp
  __int64 v11; // rsi
  char v12; // [rsp+60h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v9 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = shapeIdHint;
    v11 = 0i64;
    do
    {
      (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, hkDisplayGeometry *, unsigned __int64, int, unsigned __int64))&this->m_debugDisplayHandlers.m_data[v11]->vfptr->gap8[8])(
        this->m_debugDisplayHandlers.m_data[v11],
        &v12,
        geometry,
        id,
        tag,
        v10);
      ++v9;
      ++v11;
    }
    while ( v9 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 74
// RVA: 0xE6E5D0
void __fastcall hkDebugDisplay::addGeometryInstance(
        hkDebugDisplay *this,
        unsigned __int64 instanceId,
        hkTransformf *transform,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  int v10; // edi
  unsigned __int64 v11; // rbp
  int v12; // r14d
  __int64 v13; // rsi
  char v14; // [rsp+70h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = shapeIdHint;
    v12 = tag;
    v13 = 0i64;
    do
    {
      (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, unsigned __int64, hkTransformf *, unsigned __int64, int, unsigned __int64))&this->m_debugDisplayHandlers.m_data[v13]->vfptr->gap8[16])(
        this->m_debugDisplayHandlers.m_data[v13],
        &v14,
        instanceId,
        transform,
        id,
        v12,
        v11);
      ++v10;
      ++v13;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 85
// RVA: 0xE6E690
void __fastcall hkDebugDisplay::setGeometryPickable(
        hkDebugDisplay *this,
        hkBool isPickable,
        unsigned __int64 id,
        int tag)
{
  int v7; // edi
  __int64 v8; // rsi
  char v9; // [rsp+50h] [rbp+8h] BYREF
  unsigned __int8 m_bool; // [rsp+58h] [rbp+10h]

  m_bool = isPickable.m_bool;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v7 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, _QWORD, unsigned __int64, int))&this->m_debugDisplayHandlers.m_data[v8]->vfptr->gap8[24])(
        this->m_debugDisplayHandlers.m_data[v8],
        &v9,
        m_bool,
        id,
        tag);
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 95
// RVA: 0xE6E720
void __fastcall hkDebugDisplay::setGeometryColor(
        hkDebugDisplay *this,
        unsigned int color,
        unsigned __int64 id,
        int tag)
{
  int v8; // edi
  __int64 v9; // rsi
  char v10; // [rsp+50h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v9]->vfptr->setGeometryColor(
        this->m_debugDisplayHandlers.m_data[v9],
        (hkResult *)&v10,
        color,
        id,
        tag);
      ++v8;
      ++v9;
    }
    while ( v8 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 108
// RVA: 0xE6E7C0
void __fastcall hkDebugDisplay::updateGeometry(
        hkDebugDisplay *this,
        hkTransformf *transform,
        unsigned __int64 id,
        int tag)
{
  int v8; // edi
  __int64 v9; // rsi
  char v10; // [rsp+50h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v9]->vfptr->updateGeometry(
        this->m_debugDisplayHandlers.m_data[v9],
        (hkResult *)&v10,
        transform,
        id,
        tag);
      ++v8;
      ++v9;
    }
    while ( v8 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 118
// RVA: 0xE6E860
void __fastcall hkDebugDisplay::updateGeometry(
        hkDebugDisplay *this,
        hkMatrix4f *transform,
        unsigned __int64 id,
        int tag)
{
  int v8; // edi
  __int64 v9; // rsi
  char v10; // [rsp+50h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v9]->vfptr->updateGeometry(
        this->m_debugDisplayHandlers.m_data[v9],
        (hkResult *)&v10,
        transform,
        id,
        tag);
      ++v8;
      ++v9;
    }
    while ( v8 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 128
// RVA: 0xE6E900
void __fastcall hkDebugDisplay::updateGeometry(
        hkDebugDisplay *this,
        hkQsTransformf *transform,
        unsigned __int64 id,
        int tag)
{
  int v8; // ebx
  __int64 v9; // rsi
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      hkDebugDisplayHandler::updateGeometry(this->m_debugDisplayHandlers.m_data[v9], &result, transform, id, tag);
      ++v8;
      ++v9;
    }
    while ( v8 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 138
// RVA: 0xE6E990
void __fastcall hkDebugDisplay::skinGeometry(
        hkDebugDisplay *this,
        unsigned __int64 *ids,
        int numIds,
        hkMatrix4f *poseModel,
        int numPoseModel,
        hkMatrix4f *worldFromModel,
        int tag)
{
  int v10; // edi
  int v11; // ebp
  hkMatrix4f *v12; // r14
  int v13; // r15d
  __int64 v14; // rsi
  char v15; // [rsp+80h] [rbp+8h] BYREF
  unsigned __int64 *v16; // [rsp+88h] [rbp+10h]

  v16 = ids;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = worldFromModel;
    v13 = numPoseModel;
    v14 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v14]->vfptr->skinGeometry(
        this->m_debugDisplayHandlers.m_data[v14],
        (hkResult *)&v15,
        v16,
        numIds,
        poseModel,
        v13,
        v12,
        v11);
      ++v10;
      ++v14;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 148
// RVA: 0xE6EA70
void __fastcall hkDebugDisplay::skinGeometry(
        hkDebugDisplay *this,
        unsigned __int64 *ids,
        int numIds,
        hkQsTransformf *poseModel,
        int numPoseModel,
        hkQsTransformf *worldFromModel,
        int tag)
{
  int v10; // edi
  int v11; // ebp
  hkQsTransformf *v12; // r14
  unsigned int v13; // r15d
  __int64 v14; // rsi
  hkResult result; // [rsp+80h] [rbp+8h] BYREF
  unsigned __int64 *idsa; // [rsp+88h] [rbp+10h]

  idsa = ids;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = worldFromModel;
    v13 = numPoseModel;
    v14 = 0i64;
    do
    {
      hkDebugDisplayHandler::skinGeometry(
        this->m_debugDisplayHandlers.m_data[v14],
        &result,
        idsa,
        numIds,
        poseModel,
        v13,
        v12,
        v11);
      ++v10;
      ++v14;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 158
// RVA: 0xE6EB40
void __fastcall hkDebugDisplay::removeGeometry(
        hkDebugDisplay *this,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  int v8; // edi
  __int64 v9; // rsi
  char v10; // [rsp+50h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v9]->vfptr->removeGeometry(
        this->m_debugDisplayHandlers.m_data[v9],
        (hkResult *)&v10,
        id,
        tag,
        shapeIdHint);
      ++v8;
      ++v9;
    }
    while ( v8 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 168
// RVA: 0xE6EBE0
void __fastcall hkDebugDisplay::updateCamera(
        hkDebugDisplay *this,
        hkVector4f *from,
        hkVector4f *to,
        hkVector4f *up,
        float nearPlane,
        float farPlane,
        float fov,
        const char *name)
{
  int v12; // edi
  const char *v13; // rbp
  float v14; // xmm6_4
  float v15; // xmm7_4
  __int64 v16; // rsi
  float v17; // xmm8_4
  char v18; // [rsp+B0h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v12 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v13 = name;
    v14 = fov;
    v15 = farPlane;
    v16 = 0i64;
    v17 = nearPlane;
    do
    {
      ((void (__fastcall *)(hkDebugDisplayHandler *, char *, hkVector4f *, hkVector4f *, hkVector4f *, _DWORD, _DWORD, _DWORD, const char *))this->m_debugDisplayHandlers.m_data[v16]->vfptr->updateCamera)(
        this->m_debugDisplayHandlers.m_data[v16],
        &v18,
        from,
        to,
        up,
        LODWORD(v17),
        LODWORD(v15),
        LODWORD(v14),
        v13);
      ++v12;
      ++v16;
    }
    while ( v12 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 179
// RVA: 0xE6ECF0
void __fastcall hkDebugDisplay::displayPoint(
        hkDebugDisplay *this,
        hkVector4f *position,
        unsigned int color,
        int id,
        int tag)
{
  int v9; // edi
  int v10; // ebp
  __int64 v11; // rsi
  char v12; // [rsp+60h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v9 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = tag;
    v11 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v11]->vfptr->displayPoint(
        this->m_debugDisplayHandlers.m_data[v11],
        (hkResult *)&v12,
        position,
        color,
        id,
        v10);
      ++v9;
      ++v11;
    }
    while ( v9 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 189
// RVA: 0xE6ED90
void __fastcall hkDebugDisplay::displayLine(
        hkDebugDisplay *this,
        hkVector4f *start,
        hkVector4f *end,
        unsigned int color,
        int id,
        int tag)
{
  int v10; // edi
  int v11; // ebp
  int v12; // r14d
  __int64 v13; // rsi
  char v14; // [rsp+70h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = id;
    v13 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v13]->vfptr->displayLine(
        this->m_debugDisplayHandlers.m_data[v13],
        (hkResult *)&v14,
        start,
        end,
        color,
        v12,
        v11);
      ++v10;
      ++v13;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 201
// RVA: 0xE6EE50
void __fastcall hkDebugDisplay::displayTriangle(
        hkDebugDisplay *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        unsigned int color,
        int id,
        int tag)
{
  int v10; // edi
  int v11; // ebp
  int v12; // r14d
  unsigned int v13; // r15d
  __int64 v14; // rsi
  char v15; // [rsp+80h] [rbp+8h] BYREF
  hkVector4f *v16; // [rsp+88h] [rbp+10h]

  v16 = a;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = id;
    v13 = color;
    v14 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v14]->vfptr->displayTriangle(
        this->m_debugDisplayHandlers.m_data[v14],
        (hkResult *)&v15,
        v16,
        b,
        c,
        v13,
        v12,
        v11);
      ++v10;
      ++v14;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 211
// RVA: 0xE6EF30
void __fastcall hkDebugDisplay::displayLineModelSpace(
        hkDebugDisplay *this,
        hkQsTransformf *worldFromModel,
        hkVector4f *start,
        hkVector4f *end,
        unsigned int color,
        int id,
        int tag)
{
  hkVector4f enda; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f starta; // [rsp+40h] [rbp-18h] BYREF

  hkVector4f::setTransformedPos(&starta, worldFromModel, start);
  hkVector4f::setTransformedPos(&enda, worldFromModel, end);
  hkDebugDisplay::displayLine(this, &starta, &enda, color, id, tag);
}

// File Line: 222
// RVA: 0xE6EFB0
void __fastcall hkDebugDisplay::displayLineModelSpace(
        hkDebugDisplay *this,
        hkTransformf *worldFromModel,
        hkVector4f *start,
        hkVector4f *end,
        unsigned int color,
        int id,
        int tag)
{
  hkQsTransformf worldFromModela; // [rsp+40h] [rbp-38h] BYREF

  hkQsTransformf::setFromTransform(&worldFromModela, worldFromModel);
  hkDebugDisplay::displayLineModelSpace(this, &worldFromModela, start, end, color, id, tag);
}

// File Line: 229
// RVA: 0xE6F020
void __fastcall hkDebugDisplay::displayRay(
        hkDebugDisplay *this,
        hkVector4f *start,
        hkVector4f *direction,
        unsigned int color,
        int id,
        int tag)
{
  int v6; // ebx
  int v10; // ebp
  int v11; // r14d
  __int64 v12; // rdi
  __m128 v13; // [rsp+40h] [rbp-38h] BYREF
  char v14; // [rsp+80h] [rbp+8h] BYREF

  v6 = 0;
  v13 = _mm_add_ps(start->m_quad, direction->m_quad);
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = tag;
    v11 = id;
    v12 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v12]->vfptr->displayLine(
        this->m_debugDisplayHandlers.m_data[v12],
        (hkResult *)&v14,
        start,
        (hkVector4f *)&v13,
        color,
        v11,
        v10);
      ++v6;
      ++v12;
    }
    while ( v6 < this->m_debugDisplayHandlers.m_size );
  }
}

// File Line: 240
// RVA: 0xE6F0D0
void __fastcall hkDebugDisplay::displayRayModelSpace(
        hkDebugDisplay *this,
        hkQsTransformf *worldFromModel,
        hkVector4f *start,
        hkVector4f *direction,
        unsigned int color,
        int id,
        int tag)
{
  hkVector4f directiona; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f starta; // [rsp+40h] [rbp-18h] BYREF

  hkVector4f::setTransformedPos(&starta, worldFromModel, start);
  hkVector4f::setRotatedDir(&directiona, &worldFromModel->m_rotation, direction);
  hkDebugDisplay::displayRay(this, &starta, &directiona, color, id, tag);
}

// File Line: 251
// RVA: 0xE6F150
void __fastcall hkDebugDisplay::displayRayModelSpace(
        hkDebugDisplay *this,
        hkTransformf *worldFromModel,
        hkVector4f *start,
        hkVector4f *direction,
        unsigned int color,
        int id,
        int tag)
{
  hkQsTransformf worldFromModela; // [rsp+40h] [rbp-38h] BYREF

  hkQsTransformf::setFromTransform(&worldFromModela, worldFromModel);
  hkDebugDisplay::displayRayModelSpace(this, &worldFromModela, start, direction, color, id, tag);
}

// File Line: 258
// RVA: 0xE6FC70
// local variable allocation has failed, the output may be wrong!
void __fastcall hkDebugDisplay::displayFrame(hkDebugDisplay *this, hkTransformf *worldFromLocal, double size, int id)
{
  hkVector4f b; // [rsp+28h] [rbp-41h] BYREF
  hkVector4f from; // [rsp+38h] [rbp-31h] BYREF
  hkVector4f v9; // [rsp+48h] [rbp-21h] BYREF
  hkVector4f v10; // [rsp+58h] [rbp-11h] BYREF
  hkVector4f v11; // [rsp+68h] [rbp-1h] BYREF
  hkVector4f dir; // [rsp+78h] [rbp+Fh] BYREF
  hkVector4f v13; // [rsp+88h] [rbp+1Fh] BYREF
  hkVector4f v14; // [rsp+98h] [rbp+2Fh] BYREF
  int v15; // [rsp+E8h] [rbp+7Fh]

  b.m_quad = 0i64;
  hkVector4f::setTransformedPos(
    (hkVector4f *)&from.m_quad.m128_u16[4],
    worldFromLocal,
    (hkVector4f *)&b.m_quad.m128_u16[4]);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(*(__m128 *)&size, (__m128)0i64), (__m128)0i64);
  hkVector4f::setTransformedPos(&v9, worldFromLocal, &b);
  b.m_quad = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(*(__m128 *)&size, (__m128)0i64));
  hkVector4f::setTransformedPos(&v10, worldFromLocal, &b);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, *(__m128 *)&size), (__m128)0i64);
  hkVector4f::setTransformedPos(&v11, worldFromLocal, &b);
  dir.m_quad = _mm_sub_ps(v9.m_quad, from.m_quad);
  v14.m_quad = _mm_sub_ps(v11.m_quad, from.m_quad);
  v13.m_quad = _mm_sub_ps(v10.m_quad, from.m_quad);
  hkDebugDisplay::displayArrow(this, &from, &dir, hkColor::RED, id, v15);
  hkDebugDisplay::displayArrow(this, &from, &v13, hkColor::GREEN, id, v15);
  hkDebugDisplay::displayArrow(this, &from, &v14, hkColor::BLUE, id, v15);
}

// File Line: 283
// RVA: 0xE6FDD0
// local variable allocation has failed, the output may be wrong!
void __fastcall hkDebugDisplay::displayFrame(hkDebugDisplay *this, hkQsTransformf *worldFromLocal, double size, int id)
{
  hkVector4f b; // [rsp+28h] [rbp-41h] BYREF
  hkVector4f from; // [rsp+38h] [rbp-31h] BYREF
  hkVector4f v9; // [rsp+48h] [rbp-21h] BYREF
  hkVector4f v10; // [rsp+58h] [rbp-11h] BYREF
  hkVector4f v11; // [rsp+68h] [rbp-1h] BYREF
  hkVector4f dir; // [rsp+78h] [rbp+Fh] BYREF
  hkVector4f v13; // [rsp+88h] [rbp+1Fh] BYREF
  hkVector4f v14; // [rsp+98h] [rbp+2Fh] BYREF
  int v15; // [rsp+E8h] [rbp+7Fh]

  b.m_quad = 0i64;
  hkVector4f::setTransformedPos(
    (hkVector4f *)&from.m_quad.m128_u16[4],
    worldFromLocal,
    (hkVector4f *)&b.m_quad.m128_u16[4]);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(*(__m128 *)&size, (__m128)0i64), (__m128)0i64);
  hkVector4f::setTransformedPos(&v9, worldFromLocal, &b);
  b.m_quad = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(*(__m128 *)&size, (__m128)0i64));
  hkVector4f::setTransformedPos(&v10, worldFromLocal, &b);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, *(__m128 *)&size), (__m128)0i64);
  hkVector4f::setTransformedPos(&v11, worldFromLocal, &b);
  dir.m_quad = _mm_sub_ps(v9.m_quad, from.m_quad);
  v14.m_quad = _mm_sub_ps(v11.m_quad, from.m_quad);
  v13.m_quad = _mm_sub_ps(v10.m_quad, from.m_quad);
  hkDebugDisplay::displayArrow(this, &from, &dir, hkColor::RED, id, v15);
  hkDebugDisplay::displayArrow(this, &from, &v13, hkColor::GREEN, id, v15);
  hkDebugDisplay::displayArrow(this, &from, &v14, hkColor::BLUE, id, v15);
}

// File Line: 308
// RVA: 0xE6F1C0
void __fastcall hkDebugDisplay::displayArrow(
        hkDebugDisplay *this,
        hkVector4f *from,
        hkVector4f *dir,
        unsigned int color,
        int id,
        int tag)
{
  __m128 m_quad; // xmm12
  __m128 v9; // xmm11
  __m128 v10; // xmm9
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm7
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm7
  __m128 v22; // xmm4
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm7
  __m128 v27; // xmm1
  __m128 v28; // xmm10
  __m128 v29; // xmm2
  hkVector4f end; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f v31; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f v32; // [rsp+50h] [rbp-A8h] BYREF
  hkVector4f v33; // [rsp+60h] [rbp-98h] BYREF
  hkVector4f v34; // [rsp+70h] [rbp-88h] BYREF

  m_quad = dir->m_quad;
  v9 = _mm_mul_ps(m_quad, m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
             + _mm_shuffle_ps(v9, v9, 170).m128_f32[0]) >= 0.00000011920929 )
  {
    v10 = from->m_quad;
    v11 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 196);
    end.m_quad = _mm_add_ps(from->m_quad, m_quad);
    v12 = _mm_shuffle_ps(v11, v11, 241);
    v13 = _mm_shuffle_ps(v11, v11, 206);
    v14 = _mm_mul_ps(v12, v12);
    v15 = _mm_mul_ps(v13, v13);
    v16 = _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170)));
    v17 = _mm_xor_ps(
            _mm_or_ps(_mm_andnot_ps(v16, v12), _mm_and_ps(v13, v16)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v18 = _mm_mul_ps(v17, v17);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v20 = _mm_rsqrt_ps(v19);
    v21 = _mm_mul_ps(
            v17,
            _mm_andnot_ps(
              _mm_cmple_ps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))));
    v22 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), m_quad),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v21));
    v23 = _mm_shuffle_ps(v22, v22, 201);
    v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v25 = _mm_rsqrt_ps(v24);
    v26 = _mm_mul_ps(
            v21,
            _mm_andnot_ps(
              _mm_cmple_ps(v24, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25)),
                  _mm_mul_ps(*(__m128 *)_xmm, v25)),
                v24)));
    v27 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_14999998), (__m128)LODWORD(FLOAT_0_14999998), 0);
    v28 = _mm_sub_ps((__m128)0i64, v27);
    v29 = _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_85000002), (__m128)LODWORD(FLOAT_0_85000002), 0),
              _mm_sub_ps(end.m_quad, v10)),
            v10);
    v31.m_quad = _mm_add_ps(_mm_mul_ps(v27, v26), v29);
    v33.m_quad = _mm_add_ps(_mm_mul_ps(v27, v23), v29);
    v34.m_quad = _mm_add_ps(_mm_mul_ps(v28, v23), v29);
    v32.m_quad = _mm_add_ps(_mm_mul_ps(v28, v26), v29);
    hkDebugDisplay::displayLine(this, from, &end, color, id, tag);
    hkDebugDisplay::displayLine(this, &end, &v31, color, id, tag);
    hkDebugDisplay::displayLine(this, &end, &v32, color, id, tag);
    hkDebugDisplay::displayLine(this, &end, &v33, color, id, tag);
    hkDebugDisplay::displayLine(this, &end, &v34, color, id, tag);
  }
}nd, &v33, color, id, tag);
    hkDebugDisplay::displayLine(this, &end, &v34, co

// File Line: 338
// RVA: 0xE6F4F0
void __fastcall hkDebugDisplay::displayStar(
        hkDebugDisplay *this,
        hkVector4f *position,
        float scale,
        unsigned int color,
        int id,
        int tag)
{
  __int64 i; // rbx
  __m128 m_quad; // xmm3
  __m128 v11; // [rsp+30h] [rbp-68h]
  hkVector4f end; // [rsp+40h] [rbp-58h] BYREF
  hkVector4f start; // [rsp+50h] [rbp-48h] BYREF

  for ( i = 0i64; i < 3; ++i )
  {
    m_quad = position->m_quad;
    v11 = 0i64;
    v11.m128_f32[i] = scale;
    end.m_quad = _mm_sub_ps(m_quad, v11);
    start.m_quad = _mm_add_ps(m_quad, v11);
    hkDebugDisplay::displayLine(this, &start, &end, color, id, tag);
  }
}

// File Line: 352
// RVA: 0xE6F5C0
void __fastcall hkDebugDisplay::displayStarModelSpace(
        hkDebugDisplay *this,
        hkQsTransformf *worldFromModel,
        hkVector4f *position,
        float scale,
        unsigned int color,
        int id,
        int tag)
{
  hkVector4f positiona; // [rsp+30h] [rbp-28h] BYREF

  hkVector4f::setTransformedPos(&positiona, worldFromModel, position);
  hkDebugDisplay::displayStar(this, &positiona, scale, color, id, tag);
}

// File Line: 359
// RVA: 0xE6F620
void __fastcall hkDebugDisplay::displayStarModelSpace(
        hkDebugDisplay *this,
        hkTransformf *worldFromModel,
        hkVector4f *position,
        float scale,
        unsigned int color,
        int id,
        int tag)
{
  hkVector4f positiona; // [rsp+30h] [rbp-28h] BYREF

  hkVector4f::setTransformedPos(&positiona, worldFromModel, position);
  hkDebugDisplay::displayStar(this, &positiona, scale, color, id, tag);
}

// File Line: 366
// RVA: 0xE70090
void __fastcall hkDebugDisplay::displayAabb(hkDebugDisplay *this, hkAabb *aabb, unsigned int color, int id)
{
  __m128 v4; // xmm4
  __m128 v5; // xmm6
  __m128 v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm11
  __m128 v12; // xmm13
  __m128 v13; // xmm12
  __m128 v14; // xmm5
  __m128 v15; // xmm2
  __m128 v16; // xmm10
  hkVector4f *p_start; // rbx
  __int64 v18; // rdi
  hkVector4f start; // [rsp+30h] [rbp-B8h] BYREF
  __m128 v20; // [rsp+40h] [rbp-A8h]
  __m128 m_quad; // [rsp+50h] [rbp-98h]
  unsigned __int64 v22; // [rsp+60h] [rbp-88h]
  __m128 v23; // [rsp+68h] [rbp-80h]
  __m128 v24; // [rsp+78h] [rbp-70h]
  __m128 v25; // [rsp+88h] [rbp-60h]
  __m128 v26; // [rsp+98h] [rbp-50h]
  __m128 v27; // [rsp+A8h] [rbp-40h]
  __m128 v28; // [rsp+B8h] [rbp-30h]
  __m128 v29; // [rsp+C8h] [rbp-20h]
  __m128 v30; // [rsp+D8h] [rbp-10h]
  __m128 v31; // [rsp+E8h] [rbp+0h]
  __m128 v32; // [rsp+F8h] [rbp+10h]
  __m128 v33; // [rsp+108h] [rbp+20h]
  __m128 v34; // [rsp+118h] [rbp+30h]
  __m128 v35; // [rsp+128h] [rbp+40h]
  __m128 v36; // [rsp+138h] [rbp+50h]
  __m128 v37; // [rsp+148h] [rbp+60h]
  __m128 v38; // [rsp+158h] [rbp+70h]
  __m128 v39; // [rsp+168h] [rbp+80h]
  __m128 v40; // [rsp+178h] [rbp+90h]
  __m128 v41; // [rsp+188h] [rbp+A0h]
  int v42; // [rsp+258h] [rbp+170h]

  v4 = (__m128)aabb->m_min.m_quad.m128_u32[2];
  v5 = (__m128)aabb->m_max.m_quad.m128_u32[0];
  v9 = (__m128)aabb->m_max.m_quad.m128_u32[2];
  v10 = (__m128)aabb->m_max.m_quad.m128_u32[1];
  v11 = (__m128)aabb->m_min.m_quad.m128_u32[0];
  v12 = (__m128)aabb->m_min.m_quad.m128_u32[1];
  v13 = _mm_unpacklo_ps(v11, v4);
  v14 = _mm_unpacklo_ps(v5, v4);
  v15 = _mm_unpacklo_ps(v10, (__m128)0i64);
  start.m_quad = _mm_unpacklo_ps(v13, _mm_unpacklo_ps(v12, (__m128)0i64));
  m_quad = start.m_quad;
  v16 = _mm_unpacklo_ps(_mm_unpacklo_ps(v11, v9), _mm_unpacklo_ps(v12, (__m128)0i64));
  v20 = _mm_unpacklo_ps(v13, v15);
  v22 = v16.m128_u64[0];
  v30 = v20;
  v24 = _mm_unpacklo_ps(_mm_unpacklo_ps(v5, v9), v15);
  v26 = v24;
  v28 = v24;
  v23 = _mm_unpacklo_ps(v14, _mm_unpacklo_ps(v12, (__m128)0i64));
  v32 = v20;
  v25 = _mm_unpacklo_ps(v14, v15);
  v31 = v25;
  v34 = v25;
  v27 = _mm_unpacklo_ps(_mm_unpacklo_ps(v11, v9), v15);
  v33 = v27;
  v29 = _mm_unpacklo_ps(_mm_unpacklo_ps(v5, v9), _mm_unpacklo_ps(v12, (__m128)0i64));
  v35 = v23;
  v36 = v27;
  p_start = &start;
  v18 = 12i64;
  v37 = v16;
  v38 = v16;
  v39 = v29;
  v40 = v29;
  v41 = v23;
  do
  {
    hkDebugDisplay::displayLine(this, p_start, p_start + 1, color, id, v42);
    p_start += 2;
    --v18;
  }
  while ( v18 );
}

// File Line: 412
// RVA: 0xE702B0
void __fastcall hkDebugDisplay::displayAabb(
        hkDebugDisplay *this,
        hkTransformf *transform,
        hkAabb *aabb,
        unsigned int color,
        int id)
{
  hkVector4f v5; // xmm3
  hkVector4f v6; // xmm4
  hkVector4f v7; // xmm5
  hkVector4f *p_start; // r10
  hkVector4f v11; // xmm6
  int v12; // eax
  __m128 *v13; // r9
  __m128 *v14; // rdx
  __m128 *v15; // rcx
  __m128 v16; // xmm2
  hkVector4f start; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f end; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f v19; // [rsp+50h] [rbp-A8h] BYREF
  hkVector4f v20; // [rsp+60h] [rbp-98h] BYREF
  hkVector4f v21; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f v22; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f v23; // [rsp+98h] [rbp-60h] BYREF
  __m128 v24; // [rsp+A8h] [rbp-50h] BYREF
  __m128 v25; // [rsp+B8h] [rbp-40h] BYREF
  __m128 v26; // [rsp+C8h] [rbp-30h] BYREF
  __m128 v27; // [rsp+D8h] [rbp-20h] BYREF
  __m128 v28; // [rsp+E8h] [rbp-10h] BYREF
  __m128 v29; // [rsp+F8h] [rbp+0h] BYREF
  int v30; // [rsp+158h] [rbp+60h]

  v5.m_quad = (__m128)transform->m_rotation.m_col1;
  v6.m_quad = (__m128)transform->m_rotation.m_col0;
  v7.m_quad = (__m128)transform->m_rotation.m_col2;
  p_start = &start;
  v11.m_quad = (__m128)transform->m_translation;
  v12 = 0;
  do
  {
    if ( (v12 & 4) != 0 )
    {
      v13 = &v28;
      v28 = _mm_shuffle_ps(aabb->m_max.m_quad, aabb->m_max.m_quad, 170);
    }
    else
    {
      v13 = &v29;
      v29 = _mm_shuffle_ps(aabb->m_min.m_quad, aabb->m_min.m_quad, 170);
    }
    if ( (v12 & 2) != 0 )
    {
      v14 = &v26;
      v26 = _mm_shuffle_ps(aabb->m_max.m_quad, aabb->m_max.m_quad, 85);
    }
    else
    {
      v14 = &v24;
      v24 = _mm_shuffle_ps(aabb->m_min.m_quad, aabb->m_min.m_quad, 85);
    }
    if ( (v12 & 1) != 0 )
    {
      v15 = &v25;
      v25 = _mm_shuffle_ps(aabb->m_max.m_quad, aabb->m_max.m_quad, 0);
    }
    else
    {
      v15 = &v27;
      v27 = _mm_shuffle_ps(aabb->m_min.m_quad, aabb->m_min.m_quad, 0);
    }
    ++v12;
    ++p_start;
    v16 = _mm_movelh_ps(_mm_unpacklo_ps(*v15, *v14), _mm_unpacklo_ps(*v13, aabbOut.m_quad));
    p_start[-1].m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v6.m_quad),
                               _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v5.m_quad)),
                             _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v7.m_quad)),
                           v11.m_quad);
  }
  while ( v12 < 8 );
  hkDebugDisplay::displayLine(this, &start, &end, color, v30, id);
  hkDebugDisplay::displayLine(this, &end, &v20, color, v30, id);
  hkDebugDisplay::displayLine(this, &v20, &v19, color, v30, id);
  hkDebugDisplay::displayLine(this, &v19, &start, color, v30, id);
  hkDebugDisplay::displayLine(this, &v21, (hkVector4f *)&v21.m_quad.m128_u16[4], color, v30, id);
  hkDebugDisplay::displayLine(this, (hkVector4f *)&v21.m_quad.m128_u16[4], &v23, color, v30, id);
  hkDebugDisplay::displayLine(this, &v23, &v22, color, v30, id);
  hkDebugDisplay::displayLine(this, &v22, &v21, color, v30, id);
  hkDebugDisplay::displayLine(this, &start, &v21, color, v30, id);
  hkDebugDisplay::displayLine(this, &end, (hkVector4f *)&v21.m_quad.m128_u16[4], color, v30, id);
  hkDebugDisplay::displayLine(this, &v19, &v22, color, v30, id);
  hkDebugDisplay::displayLine(this, &v20, &v23, color, v30, id);
}

// File Line: 441
// RVA: 0xE6F680
void __fastcall hkDebugDisplay::displayPlane(
        hkDebugDisplay *this,
        hkVector4f *plane,
        hkVector4f *offset,
        float scale,
        unsigned int color,
        int id,
        int tag)
{
  __m128 m_quad; // xmm5
  __m128 v10; // xmm3
  __m128 v11; // xmm7
  __m128 v12; // xmm4
  __m128 v13; // xmm7
  __m128 v14; // xmm10
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm8
  __m128 v20; // xmm4
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  int v23; // ebx
  __m128 v24; // xmm2
  __int64 v25; // rdi
  __m128 v26; // xmm9
  __m128 v27; // xmm0
  int v28; // eax
  __m128 v29; // xmm0
  __m128 v30; // xmm7
  __m128 v31; // xmm7
  hkVector4f end; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4f start; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f from; // [rsp+50h] [rbp-88h] BYREF

  m_quad = plane->m_quad;
  v10 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)plane->m_quad, 1u), 1u);
  v11 = _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(plane->m_quad, plane->m_quad, 255));
  end.m_quad = 0i64;
  v12 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v13 = _mm_add_ps(_mm_mul_ps(v11, m_quad), offset->m_quad);
  v14 = _mm_shuffle_ps((__m128)LODWORD(scale), (__m128)LODWORD(scale), 0);
  from.m_quad = v13;
  end.m_quad.m128_i32[((unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                              _mm_and_ps(
                                                                                _mm_cmple_ps(
                                                                                  _mm_max_ps(
                                                                                    _mm_shuffle_ps(v10, v10, 170),
                                                                                    _mm_max_ps(
                                                                                      _mm_shuffle_ps(v10, v10, 85),
                                                                                      _mm_shuffle_ps(v10, v10, 0))),
                                                                                  v10),
                                                                                (__m128)xmmword_141ABC4C0))]
                     + 1)
                    % 3] = 1065353216;
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(end.m_quad, end.m_quad, 201), m_quad), _mm_mul_ps(v12, end.m_quad));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_mul_ps(_mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v18, (__m128)0i64), _mm_rsqrt_ps(v18)), v16), v14);
  v20 = _mm_sub_ps(_mm_mul_ps(v12, v19), _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), m_quad));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_mul_ps(v21, v21);
  v23 = 1;
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v25 = 4i64;
  v26 = _mm_mul_ps(_mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v24, (__m128)0i64), _mm_rsqrt_ps(v24)), v21), v14);
  while ( 1 )
  {
    v27 = (((_BYTE)v23 - 1) & 2) != 0 ? _mm_sub_ps(v13, v26) : _mm_add_ps(v26, v13);
    v28 = v23 % 4 / 2;
    v29 = v28 ? _mm_sub_ps(v27, v19) : _mm_add_ps(v27, v19);
    start.m_quad = v29;
    v30 = v28 ? _mm_sub_ps(v13, v26) : _mm_add_ps(v13, v26);
    v31 = ++v23 % 4 / 2 ? _mm_sub_ps(v30, v19) : _mm_add_ps(v30, v19);
    end.m_quad = v31;
    hkDebugDisplay::displayLine(this, &start, &end, color, id, tag);
    if ( !--v25 )
      break;
    v13 = from.m_quad;
  }
  start.m_quad = _mm_mul_ps(plane->m_quad, v14);
  hkDebugDisplay::displayArrow(this, &from, &start, color, id, tag);
}

// File Line: 481
// RVA: 0xE6F930
void __fastcall hkDebugDisplay::displayModelSpacePose(
        hkDebugDisplay *this,
        __int16 numTransforms,
        const __int16 *parentIndices,
        hkQsTransformf *modelSpacePose,
        hkQsTransformf *worldFromModel,
        int id,
        int tag,
        unsigned int color)
{
  int v10; // edi
  __int64 v11; // rsi

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      hkDebugDisplayHandler::displayModelSpacePose(
        this->m_debugDisplayHandlers.m_data[v11],
        numTransforms,
        parentIndices,
        modelSpacePose,
        worldFromModel,
        color,
        id,
        tag);
      ++v10;
      ++v11;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 491
// RVA: 0xE6FA20
void __fastcall hkDebugDisplay::displayLocalSpacePose(
        hkDebugDisplay *this,
        int numTransforms,
        const __int16 *parentIndices,
        hkQsTransformf *localSpacePose,
        hkQsTransformf *worldFromModel,
        int id,
        int tag,
        unsigned int color)
{
  int v10; // edi
  __int64 v11; // rsi

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      hkDebugDisplayHandler::displayLocalSpacePose(
        this->m_debugDisplayHandlers.m_data[v11],
        numTransforms,
        parentIndices,
        localSpacePose,
        worldFromModel,
        color,
        id,
        tag);
      ++v10;
      ++v11;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 501
// RVA: 0xE6FB10
void __fastcall hkDebugDisplay::displayText(
        hkDebugDisplay *this,
        const char *text,
        unsigned int color,
        int id,
        int tag)
{
  int v9; // edi
  int v10; // ebp
  __int64 v11; // rsi
  char v12; // [rsp+60h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v9 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = tag;
    v11 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v11]->vfptr->displayText(
        this->m_debugDisplayHandlers.m_data[v11],
        (hkResult *)&v12,
        text,
        color,
        id,
        v10);
      ++v9;
      ++v11;
    }
    while ( v9 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 512
// RVA: 0xE6FBB0
void __fastcall hkDebugDisplay::display3dText(
        hkDebugDisplay *this,
        const char *text,
        hkVector4f *pos,
        unsigned int color,
        int id,
        int tag)
{
  int v10; // edi
  int v11; // ebp
  int v12; // r14d
  __int64 v13; // rsi
  char v14; // [rsp+70h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = id;
    v13 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v13]->vfptr->display3dText(
        this->m_debugDisplayHandlers.m_data[v13],
        (hkResult *)&v14,
        text,
        pos,
        color,
        v12,
        v11);
      ++v10;
      ++v13;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 522
// RVA: 0xE6FF30
void __fastcall hkDebugDisplay::displayGeometry(
        hkDebugDisplay *this,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        hkTransformf *transform,
        unsigned int color,
        int id,
        int tag)
{
  int v10; // edi
  int v11; // ebp
  int v12; // r14d
  __int64 v13; // rsi
  char v14; // [rsp+70h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = id;
    v13 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v13]->vfptr->displayGeometry(
        this->m_debugDisplayHandlers.m_data[v13],
        (hkResult *)&v14,
        geometries,
        transform,
        color,
        v12,
        v11);
      ++v10;
      ++v13;
    }
    while ( v10 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 533
// RVA: 0xE6FFF0
void __fastcall hkDebugDisplay::displayGeometry(
        hkDebugDisplay *this,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        unsigned int color,
        int id,
        int tag)
{
  int v9; // edi
  int v10; // ebp
  __int64 v11; // rsi
  char v12; // [rsp+60h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_arrayLock->m_section);
  v9 = 0;
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = tag;
    v11 = 0i64;
    do
    {
      this->m_debugDisplayHandlers.m_data[v11]->vfptr->displayGeometry(
        this->m_debugDisplayHandlers.m_data[v11],
        (hkResult *)&v12,
        geometries,
        color,
        id,
        v10);
      ++v9;
      ++v11;
    }
    while ( v9 < this->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&this->m_arrayLock->m_section);
}

// File Line: 543
// RVA: 0xE70550
void __fastcall hkDebugDisplay::displayLitTriangle(
        hkDebugDisplay *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        unsigned int color)
{
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm5
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm10
  __m128 v17; // xmm4
  __m128 v18; // xmm8
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm9
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm9
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm9
  __m128 v28; // xmm0
  __m128 v29; // xmm6
  __m128 v30; // xmm4
  __m128 v31; // xmm0
  unsigned int v32; // eax

  v8 = _mm_sub_ps(b->m_quad, a->m_quad);
  v9 = _mm_sub_ps(c->m_quad, a->m_quad);
  v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v13), (__m128)0i64);
  v16 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v13, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                  _mm_mul_ps(*(__m128 *)_xmm, v14))),
              v11),
            v15),
          _mm_andnot_ps(v15, v11));
  if ( _mm_movemask_ps(v15) )
  {
    v17 = 0i64;
    v18 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_89999998), (__m128)LODWORD(FLOAT_0_89999998), 0);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 85), _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 0)),
            _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 170));
    v20 = _mm_rsqrt_ps(v19);
    v21 = _mm_cmple_ps(v19, (__m128)0i64);
    v22 = _mm_mul_ps(v20, v19);
    v23 = 0i64;
    v24 = _mm_mul_ps(
            _mm_andnot_ps(
              v21,
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v20)), _mm_mul_ps(*(__m128 *)_xmm, v20))),
            (__m128)_xmm);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 85), _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 0)),
            _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 170));
    v26 = _mm_rsqrt_ps(v25);
    v27 = _mm_mul_ps(_mm_mul_ps(v24, v18), v16);
    v17.m128_f32[0] = (float)BYTE2(color) * 0.0039215689;
    v23.m128_f32[0] = (float)BYTE1(color) * 0.0039215689;
    v28 = 0i64;
    v28.m128_f32[0] = (float)(unsigned __int8)color * 0.0039215689;
    v29 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v25, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                    _mm_mul_ps(*(__m128 *)_xmm, v26))),
                (__m128)_xmm),
              v18),
            v16);
    v30 = _mm_unpacklo_ps(_mm_unpacklo_ps(v17, v28), _mm_unpacklo_ps(v23, (__m128)0i64));
    v31 = _mm_min_ps(
            _mm_max_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                          _mm_shuffle_ps(v29, v29, 170)),
                        (__m128)xmmword_141A711B0),
                      (__m128)xmmword_141A711B0),
                    _mm_mul_ps((__m128)_xmm, v30)),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                          _mm_shuffle_ps(v27, v27, 170)),
                        (__m128)xmmword_141A711B0),
                      (__m128)xmmword_141A711B0),
                    _mm_mul_ps((__m128)_xmm, v30))),
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0),
                  v30)),
              aabbOut.m_quad),
            query.m_quad);
    v32 = hkColor::rgbFromFloats(
            v31.m128_f32[0],
            _mm_shuffle_ps(v31, v31, 85).m128_f32[0],
            _mm_shuffle_ps(v31, v31, 170).m128_f32[0],
            (float)HIBYTE(color) * 0.0039215689);
    hkDebugDisplay::displayTriangle(
      hkSingleton<hkDebugDisplay>::s_instance,
      a,
      b,
      c,
      v32,
      0,
      (int)hkDebugDisplayProcess::m_tag);
  }
}

// File Line: 573
// RVA: 0x15D8A50
hkSingletonInitNode *dynamic_initializer_for__hkSingletonRegisterhkDebugDisplay__()
{
  hkSingletonInitNode *result; // rax

  hkSingletonRegisterhkDebugDisplay.m_next = hkSingletonInitList;
  result = &hkSingletonRegisterhkDebugDisplay;
  hkSingletonInitList = &hkSingletonRegisterhkDebugDisplay;
  return result;
}

