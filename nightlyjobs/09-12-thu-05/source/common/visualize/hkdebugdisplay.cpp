// File Line: 16
// RVA: 0xE6E200
void __fastcall hkDebugDisplay::hkDebugDisplay(hkDebugDisplay *this)
{
  hkDebugDisplay *v1; // rbx
  _QWORD **v2; // rax
  hkCriticalSection *v3; // rax
  hkCriticalSection *v4; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkDebugDisplay::`vftable;
  this->m_debugDisplayHandlers.m_data = 0i64;
  this->m_debugDisplayHandlers.m_size = 0;
  this->m_debugDisplayHandlers.m_capacityAndFlags = 2147483648;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 40i64);
  if ( v3 )
  {
    hkCriticalSection::hkCriticalSection(v3, 1000);
    v1->m_arrayLock = v4;
  }
  else
  {
    v1->m_arrayLock = 0i64;
  }
}

// File Line: 21
// RVA: 0xE6E290
void __fastcall hkDebugDisplay::~hkDebugDisplay(hkDebugDisplay *this)
{
  hkCriticalSection *v1; // rdi
  hkDebugDisplay *v2; // rbx
  _QWORD **v3; // rax
  int v4; // er8

  v1 = this->m_arrayLock;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkDebugDisplay::`vftable;
  if ( v1 )
  {
    DeleteCriticalSection(&v1->m_section);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, signed __int64))(*v3[11] + 16i64))(v3[11], v1, 40i64);
  }
  v4 = v2->m_debugDisplayHandlers.m_capacityAndFlags;
  v2->m_debugDisplayHandlers.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_debugDisplayHandlers.m_data,
      8 * v4);
  v2->m_debugDisplayHandlers.m_data = 0i64;
  v2->m_debugDisplayHandlers.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 26
// RVA: 0xE6E330
void __fastcall hkDebugDisplay::addDebugDisplayHandler(hkDebugDisplay *this, hkDebugDisplayHandler *debugDisplay)
{
  hkDebugDisplay *v2; // rdi
  hkDebugDisplayHandler *v3; // rsi

  v2 = this;
  v3 = debugDisplay;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  if ( v2->m_debugDisplayHandlers.m_size == (v2->m_debugDisplayHandlers.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_debugDisplayHandlers,
      8);
  v2->m_debugDisplayHandlers.m_data[v2->m_debugDisplayHandlers.m_size++] = v3;
  LeaveCriticalSection(&v2->m_arrayLock->m_section);
}

// File Line: 33
// RVA: 0xE6E3B0
void __fastcall hkDebugDisplay::removeDebugDisplayHandler(hkDebugDisplay *this, hkDebugDisplayHandler *debugDisplay)
{
  hkDebugDisplay *v2; // rbx
  hkDebugDisplayHandler *v3; // rdi
  __int64 v4; // rdx
  int v5; // er8
  __int64 v6; // r9
  hkDebugDisplayHandler **v7; // rax

  v2 = this;
  v3 = debugDisplay;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v4 = v2->m_debugDisplayHandlers.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( (signed int)v4 > 0 )
  {
    v7 = v2->m_debugDisplayHandlers.m_data;
    while ( *v7 != v3 )
    {
      ++v6;
      ++v5;
      ++v7;
      if ( v6 >= v4 )
        goto LABEL_9;
    }
    if ( v5 >= 0 )
    {
      v2->m_debugDisplayHandlers.m_size = v4 - 1;
      if ( (_DWORD)v4 - 1 != v5 )
        v2->m_debugDisplayHandlers.m_data[v5] = v2->m_debugDisplayHandlers.m_data[(signed int)v4 - 1];
    }
  }
LABEL_9:
  LeaveCriticalSection(&v2->m_arrayLock->m_section);
}

// File Line: 44
// RVA: 0xE6E440
void __fastcall hkDebugDisplay::clear(hkDebugDisplay *this)
{
  hkDebugDisplay *v1; // rbx
  _RTL_CRITICAL_SECTION *v2; // rcx

  v1 = this;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v2 = &v1->m_arrayLock->m_section;
  v1->m_debugDisplayHandlers.m_size = 0;
  LeaveCriticalSection(v2);
}

// File Line: 54
// RVA: 0xE6E470
void __fastcall hkDebugDisplay::addGeometry(hkDebugDisplay *this, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *geometries, hkTransformf *transform, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint)
{
  hkDebugDisplay *v6; // rbx
  unsigned __int64 v7; // r15
  hkTransformf *v8; // r12
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v9; // r13
  int v10; // esi
  unsigned __int64 v11; // rbp
  int v12; // er14
  __int64 v13; // rdi
  __int64 v14; // [rsp+28h] [rbp-40h]
  _QWORD v15[6]; // [rsp+38h] [rbp-30h]
  char v16; // [rsp+70h] [rbp+8h]

  v6 = this;
  v7 = id;
  v8 = transform;
  v9 = geometries;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v6->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = shapeIdHint;
    v12 = tag;
    v13 = 0i64;
    do
    {
      LODWORD(v15[0]) = 0;
      LODWORD(v14) = v12;
      (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *, hkTransformf *, unsigned __int64, __int64, unsigned __int64, _QWORD))v6->m_debugDisplayHandlers.m_data[v13]->vfptr->gap8)(
        v6->m_debugDisplayHandlers.m_data[v13],
        &v16,
        v9,
        v8,
        v7,
        v14,
        v11,
        v15[0]);
      ++v10;
      ++v13;
    }
    while ( v10 < v6->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v6->m_arrayLock->m_section);
}

// File Line: 64
// RVA: 0xE6E530
void __fastcall hkDebugDisplay::addGeometry(hkDebugDisplay *this, hkDisplayGeometry *geometry, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint)
{
  hkDebugDisplay *v5; // rbx
  int v6; // er14
  unsigned __int64 v7; // r15
  hkDisplayGeometry *v8; // r12
  int v9; // edi
  unsigned __int64 v10; // rbp
  __int64 v11; // rsi
  __int64 v12; // [rsp+20h] [rbp-38h]
  char v13; // [rsp+60h] [rbp+8h]

  v5 = this;
  v6 = tag;
  v7 = id;
  v8 = geometry;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v9 = 0;
  if ( v5->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = shapeIdHint;
    v11 = 0i64;
    do
    {
      LODWORD(v12) = v6;
      (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, hkDisplayGeometry *, unsigned __int64, __int64, unsigned __int64))&v5->m_debugDisplayHandlers.m_data[v11]->vfptr->gap8[8])(
        v5->m_debugDisplayHandlers.m_data[v11],
        &v13,
        v8,
        v7,
        v12,
        v10);
      ++v9;
      ++v11;
    }
    while ( v9 < v5->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v5->m_arrayLock->m_section);
}

// File Line: 74
// RVA: 0xE6E5D0
void __fastcall hkDebugDisplay::addGeometryInstance(hkDebugDisplay *this, unsigned __int64 instanceId, hkTransformf *transform, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint)
{
  hkDebugDisplay *v6; // rbx
  unsigned __int64 v7; // r15
  hkTransformf *v8; // r12
  unsigned __int64 v9; // r13
  int v10; // edi
  unsigned __int64 v11; // rbp
  int v12; // er14
  __int64 v13; // rsi
  __int64 v14; // [rsp+28h] [rbp-40h]
  char v15; // [rsp+70h] [rbp+8h]

  v6 = this;
  v7 = id;
  v8 = transform;
  v9 = instanceId;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v6->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = shapeIdHint;
    v12 = tag;
    v13 = 0i64;
    do
    {
      LODWORD(v14) = v12;
      (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, unsigned __int64, hkTransformf *, unsigned __int64, __int64, unsigned __int64))&v6->m_debugDisplayHandlers.m_data[v13]->vfptr->gap8[16])(
        v6->m_debugDisplayHandlers.m_data[v13],
        &v15,
        v9,
        v8,
        v7,
        v14,
        v11);
      ++v10;
      ++v13;
    }
    while ( v10 < v6->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v6->m_arrayLock->m_section);
}

// File Line: 85
// RVA: 0xE6E690
void __fastcall hkDebugDisplay::setGeometryPickable(hkDebugDisplay *this, hkBool isPickable, unsigned __int64 id, int tag)
{
  hkDebugDisplay *v4; // rbx
  int v5; // ebp
  unsigned __int64 v6; // r14
  int v7; // edi
  __int64 v8; // rsi
  _QWORD v9[5]; // [rsp+20h] [rbp-28h]
  char v10; // [rsp+50h] [rbp+8h]
  unsigned __int8 v11; // [rsp+58h] [rbp+10h]

  v11 = isPickable.m_bool;
  v4 = this;
  v5 = tag;
  v6 = id;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v7 = 0;
  if ( v4->m_debugDisplayHandlers.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      LODWORD(v9[0]) = v5;
      (*(void (__fastcall **)(hkDebugDisplayHandler *, char *, _QWORD, unsigned __int64, _QWORD))&v4->m_debugDisplayHandlers.m_data[v8]->vfptr->gap8[24])(
        v4->m_debugDisplayHandlers.m_data[v8],
        &v10,
        v11,
        v6,
        v9[0]);
      ++v7;
      ++v8;
    }
    while ( v7 < v4->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v4->m_arrayLock->m_section);
}

// File Line: 95
// RVA: 0xE6E720
void __fastcall hkDebugDisplay::setGeometryColor(hkDebugDisplay *this, unsigned int color, unsigned __int64 id, int tag)
{
  hkDebugDisplay *v4; // rbx
  int v5; // ebp
  unsigned __int64 v6; // r14
  unsigned int v7; // er15
  int v8; // edi
  __int64 v9; // rsi
  _QWORD v10[5]; // [rsp+20h] [rbp-28h]
  char v11; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = tag;
  v6 = id;
  v7 = color;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( v4->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      LODWORD(v10[0]) = v5;
      v4->m_debugDisplayHandlers.m_data[v9]->vfptr->setGeometryColor(
        v4->m_debugDisplayHandlers.m_data[v9],
        (hkResult *)&v11,
        v7,
        v6,
        v10[0]);
      ++v8;
      ++v9;
    }
    while ( v8 < v4->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v4->m_arrayLock->m_section);
}

// File Line: 108
// RVA: 0xE6E7C0
void __fastcall hkDebugDisplay::updateGeometry(hkDebugDisplay *this, hkTransformf *transform, unsigned __int64 id, int tag)
{
  hkDebugDisplay *v4; // rbx
  int v5; // ebp
  unsigned __int64 v6; // r14
  hkTransformf *v7; // r15
  int v8; // edi
  __int64 v9; // rsi
  _QWORD v10[5]; // [rsp+20h] [rbp-28h]
  char v11; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = tag;
  v6 = id;
  v7 = transform;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( v4->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      LODWORD(v10[0]) = v5;
      v4->m_debugDisplayHandlers.m_data[v9]->vfptr->updateGeometry(
        v4->m_debugDisplayHandlers.m_data[v9],
        (hkResult *)&v11,
        v7,
        v6,
        v10[0]);
      ++v8;
      ++v9;
    }
    while ( v8 < v4->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v4->m_arrayLock->m_section);
}

// File Line: 118
// RVA: 0xE6E860
void __fastcall hkDebugDisplay::updateGeometry(hkDebugDisplay *this, hkMatrix4f *transform, unsigned __int64 id, int tag)
{
  hkDebugDisplay *v4; // rbx
  int v5; // ebp
  unsigned __int64 v6; // r14
  hkMatrix4f *v7; // r15
  int v8; // edi
  __int64 v9; // rsi
  _QWORD v10[5]; // [rsp+20h] [rbp-28h]
  char v11; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = tag;
  v6 = id;
  v7 = transform;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( v4->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      LODWORD(v10[0]) = v5;
      v4->m_debugDisplayHandlers.m_data[v9]->vfptr->updateGeometry(
        v4->m_debugDisplayHandlers.m_data[v9],
        (hkResult *)&v11,
        v7,
        v6,
        v10[0]);
      ++v8;
      ++v9;
    }
    while ( v8 < v4->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v4->m_arrayLock->m_section);
}

// File Line: 128
// RVA: 0xE6E900
void __fastcall hkDebugDisplay::updateGeometry(hkDebugDisplay *this, hkQsTransformf *transform, unsigned __int64 id, int tag)
{
  hkDebugDisplay *v4; // rdi
  int v5; // ebp
  unsigned __int64 v6; // r14
  hkQsTransformf *v7; // r15
  int v8; // ebx
  __int64 v9; // rsi
  hkResult result; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = tag;
  v6 = id;
  v7 = transform;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( v4->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      hkDebugDisplayHandler::updateGeometry(v4->m_debugDisplayHandlers.m_data[v9], &result, v7, v6, v5);
      ++v8;
      ++v9;
    }
    while ( v8 < v4->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v4->m_arrayLock->m_section);
}

// File Line: 138
// RVA: 0xE6E990
void __fastcall hkDebugDisplay::skinGeometry(hkDebugDisplay *this, unsigned __int64 *ids, int numIds, hkMatrix4f *poseModel, int numPoseModel, hkMatrix4f *worldFromModel, int tag)
{
  hkDebugDisplay *v7; // rbx
  hkMatrix4f *v8; // r12
  unsigned int v9; // er13
  int v10; // edi
  int v11; // ebp
  hkMatrix4f *v12; // r14
  int v13; // er15
  __int64 v14; // rsi
  __int64 v15; // [rsp+28h] [rbp-50h]
  __int64 v16; // [rsp+38h] [rbp-40h]
  char v17; // [rsp+80h] [rbp+8h]
  unsigned __int64 *v18; // [rsp+88h] [rbp+10h]

  v18 = ids;
  v7 = this;
  v8 = poseModel;
  v9 = numIds;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v7->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = worldFromModel;
    v13 = numPoseModel;
    v14 = 0i64;
    do
    {
      LODWORD(v16) = v11;
      LODWORD(v15) = v13;
      v7->m_debugDisplayHandlers.m_data[v14]->vfptr->skinGeometry(
        v7->m_debugDisplayHandlers.m_data[v14],
        (hkResult *)&v17,
        v18,
        v9,
        v8,
        v15,
        v12,
        v16);
      ++v10;
      ++v14;
    }
    while ( v10 < v7->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v7->m_arrayLock->m_section);
}

// File Line: 148
// RVA: 0xE6EA70
void __fastcall hkDebugDisplay::skinGeometry(hkDebugDisplay *this, unsigned __int64 *ids, int numIds, hkQsTransformf *poseModel, int numPoseModel, hkQsTransformf *worldFromModel, int tag)
{
  hkDebugDisplay *v7; // rbx
  hkQsTransformf *v8; // r12
  int v9; // er13
  int v10; // edi
  int v11; // ebp
  hkQsTransformf *v12; // r14
  int v13; // er15
  __int64 v14; // rsi
  hkResult result; // [rsp+80h] [rbp+8h]
  unsigned __int64 *idsa; // [rsp+88h] [rbp+10h]

  idsa = ids;
  v7 = this;
  v8 = poseModel;
  v9 = numIds;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v7->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = worldFromModel;
    v13 = numPoseModel;
    v14 = 0i64;
    do
    {
      hkDebugDisplayHandler::skinGeometry(v7->m_debugDisplayHandlers.m_data[v14], &result, idsa, v9, v8, v13, v12, v11);
      ++v10;
      ++v14;
    }
    while ( v10 < v7->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v7->m_arrayLock->m_section);
}

// File Line: 158
// RVA: 0xE6EB40
void __fastcall hkDebugDisplay::removeGeometry(hkDebugDisplay *this, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint)
{
  hkDebugDisplay *v4; // rbx
  unsigned __int64 v5; // rbp
  unsigned int v6; // er14
  unsigned __int64 v7; // r15
  int v8; // edi
  __int64 v9; // rsi
  char v10; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = shapeIdHint;
  v6 = tag;
  v7 = id;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v8 = 0;
  if ( v4->m_debugDisplayHandlers.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v4->m_debugDisplayHandlers.m_data[v9]->vfptr->removeGeometry(
        v4->m_debugDisplayHandlers.m_data[v9],
        (hkResult *)&v10,
        v7,
        v6,
        v5);
      ++v8;
      ++v9;
    }
    while ( v8 < v4->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v4->m_arrayLock->m_section);
}

// File Line: 168
// RVA: 0xE6EBE0
void __fastcall hkDebugDisplay::updateCamera(hkDebugDisplay *this, hkVector4f *from, hkVector4f *to, hkVector4f *up, float nearPlane, float farPlane, float fov, const char *name)
{
  hkDebugDisplay *v8; // rbx
  hkVector4f *v9; // r14
  hkVector4f *v10; // r15
  hkVector4f *v11; // r12
  int v12; // edi
  const char *v13; // rbp
  float v14; // xmm6_4
  float v15; // xmm7_4
  __int64 v16; // rsi
  float v17; // xmm8_4
  __int64 v18; // [rsp+28h] [rbp-80h]
  __int64 v19; // [rsp+30h] [rbp-78h]
  __int64 v20; // [rsp+38h] [rbp-70h]
  char v21; // [rsp+B0h] [rbp+8h]

  v8 = this;
  v9 = up;
  v10 = to;
  v11 = from;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v12 = 0;
  if ( v8->m_debugDisplayHandlers.m_size > 0 )
  {
    v13 = name;
    v14 = fov;
    v15 = farPlane;
    v16 = 0i64;
    v17 = nearPlane;
    do
    {
      *(float *)&v20 = v14;
      *(float *)&v19 = v15;
      *(float *)&v18 = v17;
      ((void (__fastcall *)(hkDebugDisplayHandler *, char *, hkVector4f *, hkVector4f *, hkVector4f *, __int64, __int64, __int64, const char *))v8->m_debugDisplayHandlers.m_data[v16]->vfptr->updateCamera)(
        v8->m_debugDisplayHandlers.m_data[v16],
        &v21,
        v11,
        v10,
        v9,
        v18,
        v19,
        v20,
        v13);
      ++v12;
      ++v16;
    }
    while ( v12 < v8->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v8->m_arrayLock->m_section);
}

// File Line: 179
// RVA: 0xE6ECF0
void __fastcall hkDebugDisplay::displayPoint(hkDebugDisplay *this, hkVector4f *position, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v5; // rbx
  int v6; // er14
  unsigned int v7; // er15
  hkVector4f *v8; // r12
  int v9; // edi
  int v10; // ebp
  __int64 v11; // rsi
  __int64 v12; // [rsp+20h] [rbp-38h]
  _QWORD v13[6]; // [rsp+28h] [rbp-30h]
  char v14; // [rsp+60h] [rbp+8h]

  v5 = this;
  v6 = id;
  v7 = color;
  v8 = position;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v9 = 0;
  if ( v5->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = tag;
    v11 = 0i64;
    do
    {
      LODWORD(v13[0]) = v10;
      LODWORD(v12) = v6;
      v5->m_debugDisplayHandlers.m_data[v11]->vfptr->displayPoint(
        v5->m_debugDisplayHandlers.m_data[v11],
        (hkResult *)&v14,
        v8,
        v7,
        v12,
        v13[0]);
      ++v9;
      ++v11;
    }
    while ( v9 < v5->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v5->m_arrayLock->m_section);
}

// File Line: 189
// RVA: 0xE6ED90
void __fastcall hkDebugDisplay::displayLine(hkDebugDisplay *this, hkVector4f *start, hkVector4f *end, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v6; // rbx
  unsigned int v7; // er15
  hkVector4f *v8; // r12
  hkVector4f *v9; // r13
  int v10; // edi
  int v11; // ebp
  int v12; // er14
  __int64 v13; // rsi
  __int64 v14; // [rsp+20h] [rbp-48h]
  __int64 v15; // [rsp+28h] [rbp-40h]
  _QWORD v16[7]; // [rsp+30h] [rbp-38h]
  char v17; // [rsp+70h] [rbp+8h]

  v6 = this;
  v7 = color;
  v8 = end;
  v9 = start;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v6->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = id;
    v13 = 0i64;
    do
    {
      LODWORD(v16[0]) = v11;
      LODWORD(v15) = v12;
      LODWORD(v14) = v7;
      v6->m_debugDisplayHandlers.m_data[v13]->vfptr->displayLine(
        v6->m_debugDisplayHandlers.m_data[v13],
        (hkResult *)&v17,
        v9,
        v8,
        v14,
        v15,
        v16[0]);
      ++v10;
      ++v13;
    }
    while ( v10 < v6->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v6->m_arrayLock->m_section);
}

// File Line: 201
// RVA: 0xE6EE50
void __fastcall hkDebugDisplay::displayTriangle(hkDebugDisplay *this, hkVector4f *a, hkVector4f *b, hkVector4f *c, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v7; // rbx
  hkVector4f *v8; // r12
  hkVector4f *v9; // r13
  int v10; // edi
  int v11; // ebp
  int v12; // er14
  unsigned int v13; // er15
  __int64 v14; // rsi
  __int64 v15; // [rsp+28h] [rbp-50h]
  __int64 v16; // [rsp+30h] [rbp-48h]
  __int64 v17; // [rsp+38h] [rbp-40h]
  char v18; // [rsp+80h] [rbp+8h]
  hkVector4f *v19; // [rsp+88h] [rbp+10h]

  v19 = a;
  v7 = this;
  v8 = c;
  v9 = b;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v7->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = id;
    v13 = color;
    v14 = 0i64;
    do
    {
      LODWORD(v17) = v11;
      LODWORD(v16) = v12;
      LODWORD(v15) = v13;
      v7->m_debugDisplayHandlers.m_data[v14]->vfptr->displayTriangle(
        v7->m_debugDisplayHandlers.m_data[v14],
        (hkResult *)&v18,
        v19,
        v9,
        v8,
        v15,
        v16,
        v17);
      ++v10;
      ++v14;
    }
    while ( v10 < v7->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v7->m_arrayLock->m_section);
}

// File Line: 211
// RVA: 0xE6EF30
void __fastcall hkDebugDisplay::displayLineModelSpace(hkDebugDisplay *this, hkQsTransformf *worldFromModel, hkVector4f *start, hkVector4f *end, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v7; // rsi
  hkVector4f *v8; // rdi
  hkQsTransformf *v9; // rbx
  hkVector4f enda; // [rsp+30h] [rbp-28h]
  hkVector4f starta; // [rsp+40h] [rbp-18h]

  v7 = this;
  v8 = end;
  v9 = worldFromModel;
  hkVector4f::setTransformedPos(&starta, worldFromModel, start);
  hkVector4f::setTransformedPos(&enda, v9, v8);
  hkDebugDisplay::displayLine(v7, &starta, &enda, color, id, tag);
}

// File Line: 222
// RVA: 0xE6EFB0
void __fastcall hkDebugDisplay::displayLineModelSpace(hkDebugDisplay *this, hkTransformf *worldFromModel, hkVector4f *start, hkVector4f *end, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v7; // rsi
  hkVector4f *v8; // rbx
  hkVector4f *v9; // rdi
  hkQsTransformf worldFromModela; // [rsp+40h] [rbp-38h]

  v7 = this;
  v8 = end;
  v9 = start;
  hkQsTransformf::setFromTransform(&worldFromModela, worldFromModel);
  hkDebugDisplay::displayLineModelSpace(v7, &worldFromModela, v9, v8, color, id, tag);
}

// File Line: 229
// RVA: 0xE6F020
void __fastcall hkDebugDisplay::displayRay(hkDebugDisplay *this, hkVector4f *start, hkVector4f *direction, unsigned int color, int id, int tag)
{
  int v6; // ebx
  unsigned int v7; // er12
  hkVector4f *v8; // r15
  hkDebugDisplay *v9; // rsi
  int v10; // ebp
  int v11; // er14
  __int64 v12; // rdi
  __int64 v13; // [rsp+20h] [rbp-58h]
  __int64 v14; // [rsp+28h] [rbp-50h]
  _QWORD v15[2]; // [rsp+30h] [rbp-48h]
  __m128 v16; // [rsp+40h] [rbp-38h]
  char v17; // [rsp+80h] [rbp+8h]

  v6 = 0;
  v7 = color;
  v8 = start;
  v9 = this;
  v16 = _mm_add_ps(start->m_quad, direction->m_quad);
  if ( this->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = tag;
    v11 = id;
    v12 = 0i64;
    do
    {
      LODWORD(v15[0]) = v10;
      LODWORD(v14) = v11;
      LODWORD(v13) = v7;
      v9->m_debugDisplayHandlers.m_data[v12]->vfptr->displayLine(
        v9->m_debugDisplayHandlers.m_data[v12],
        (hkResult *)&v17,
        v8,
        (hkVector4f *)&v16,
        v13,
        v14,
        v15[0]);
      ++v6;
      ++v12;
    }
    while ( v6 < v9->m_debugDisplayHandlers.m_size );
  }
}

// File Line: 240
// RVA: 0xE6F0D0
void __fastcall hkDebugDisplay::displayRayModelSpace(hkDebugDisplay *this, hkQsTransformf *worldFromModel, hkVector4f *start, hkVector4f *direction, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v7; // rsi
  hkVector4f *v8; // rdi
  hkQsTransformf *v9; // rbx
  hkVector4f directiona; // [rsp+30h] [rbp-28h]
  hkVector4f starta; // [rsp+40h] [rbp-18h]

  v7 = this;
  v8 = direction;
  v9 = worldFromModel;
  hkVector4f::setTransformedPos(&starta, worldFromModel, start);
  hkVector4f::setRotatedDir(&directiona, &v9->m_rotation, v8);
  hkDebugDisplay::displayRay(v7, &starta, &directiona, color, id, tag);
}

// File Line: 251
// RVA: 0xE6F150
void __fastcall hkDebugDisplay::displayRayModelSpace(hkDebugDisplay *this, hkTransformf *worldFromModel, hkVector4f *start, hkVector4f *direction, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v7; // rsi
  hkVector4f *v8; // rbx
  hkVector4f *v9; // rdi
  hkQsTransformf worldFromModela; // [rsp+40h] [rbp-38h]

  v7 = this;
  v8 = direction;
  v9 = start;
  hkQsTransformf::setFromTransform(&worldFromModela, worldFromModel);
  hkDebugDisplay::displayRayModelSpace(v7, &worldFromModela, v9, v8, color, id, tag);
}

// File Line: 258
// RVA: 0xE6FC70
int hkDebugDisplay::displayFrame(...)
{
  hkDebugDisplay *v4; // rsi
  int v5; // edi
  hkTransformf *v6; // rbx
  hkVector4f b; // [rsp+28h] [rbp-41h]
  hkVector4f from; // [rsp+38h] [rbp-31h]
  hkVector4f v9; // [rsp+48h] [rbp-21h]
  hkVector4f v10; // [rsp+58h] [rbp-11h]
  hkVector4f v11; // [rsp+68h] [rbp-1h]
  hkVector4f dir; // [rsp+78h] [rbp+Fh]
  hkVector4f v13; // [rsp+88h] [rbp+1Fh]
  hkVector4f v14; // [rsp+98h] [rbp+2Fh]
  int v15; // [rsp+E8h] [rbp+7Fh]

  v4 = this;
  v5 = id;
  b.m_quad = 0i64;
  v6 = worldFromLocal;
  hkVector4f::setTransformedPos((hkVector4f *)((char *)&from + 8), worldFromLocal, (hkVector4f *)((char *)&b + 8));
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)size, (__m128)0i64), (__m128)0i64);
  hkVector4f::setTransformedPos(&v9, v6, &b);
  b.m_quad = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps((__m128)size, (__m128)0i64));
  hkVector4f::setTransformedPos(&v10, v6, &b);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, (__m128)size), (__m128)0i64);
  hkVector4f::setTransformedPos(&v11, v6, &b);
  dir.m_quad = _mm_sub_ps(v9.m_quad, from.m_quad);
  v14.m_quad = _mm_sub_ps(v11.m_quad, from.m_quad);
  v13.m_quad = _mm_sub_ps(v10.m_quad, from.m_quad);
  hkDebugDisplay::displayArrow(v4, &from, &dir, hkColor::RED, v5, v15);
  hkDebugDisplay::displayArrow(v4, &from, &v13, hkColor::GREEN, v5, v15);
  hkDebugDisplay::displayArrow(v4, &from, &v14, hkColor::BLUE, v5, v15);
}

// File Line: 283
// RVA: 0xE6FDD0
int hkDebugDisplay::displayFrame(...)
{
  hkDebugDisplay *v4; // rsi
  int v5; // edi
  hkQsTransformf *v6; // rbx
  hkVector4f b; // [rsp+28h] [rbp-41h]
  hkVector4f from; // [rsp+38h] [rbp-31h]
  hkVector4f v9; // [rsp+48h] [rbp-21h]
  hkVector4f v10; // [rsp+58h] [rbp-11h]
  hkVector4f v11; // [rsp+68h] [rbp-1h]
  hkVector4f dir; // [rsp+78h] [rbp+Fh]
  hkVector4f v13; // [rsp+88h] [rbp+1Fh]
  hkVector4f v14; // [rsp+98h] [rbp+2Fh]
  int v15; // [rsp+E8h] [rbp+7Fh]

  v4 = this;
  v5 = id;
  b.m_quad = 0i64;
  v6 = worldFromLocal;
  hkVector4f::setTransformedPos((hkVector4f *)((char *)&from + 8), worldFromLocal, (hkVector4f *)((char *)&b + 8));
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)size, (__m128)0i64), (__m128)0i64);
  hkVector4f::setTransformedPos(&v9, v6, &b);
  b.m_quad = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps((__m128)size, (__m128)0i64));
  hkVector4f::setTransformedPos(&v10, v6, &b);
  b.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, (__m128)size), (__m128)0i64);
  hkVector4f::setTransformedPos(&v11, v6, &b);
  dir.m_quad = _mm_sub_ps(v9.m_quad, from.m_quad);
  v14.m_quad = _mm_sub_ps(v11.m_quad, from.m_quad);
  v13.m_quad = _mm_sub_ps(v10.m_quad, from.m_quad);
  hkDebugDisplay::displayArrow(v4, &from, &dir, hkColor::RED, v5, v15);
  hkDebugDisplay::displayArrow(v4, &from, &v13, hkColor::GREEN, v5, v15);
  hkDebugDisplay::displayArrow(v4, &from, &v14, hkColor::BLUE, v5, v15);
}

// File Line: 308
// RVA: 0xE6F1C0
void __fastcall hkDebugDisplay::displayArrow(hkDebugDisplay *this, hkVector4f *from, hkVector4f *dir, unsigned int color, int id, int tag)
{
  __m128 v6; // xmm12
  unsigned int v7; // esi
  hkDebugDisplay *v8; // rbp
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
  hkVector4f end; // [rsp+30h] [rbp-C8h]
  hkVector4f v31; // [rsp+40h] [rbp-B8h]
  hkVector4f v32; // [rsp+50h] [rbp-A8h]
  hkVector4f v33; // [rsp+60h] [rbp-98h]
  hkVector4f v34; // [rsp+70h] [rbp-88h]

  v6 = dir->m_quad;
  v7 = color;
  v8 = this;
  v9 = _mm_mul_ps(v6, v6);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170))) >= 0.00000011920929 )
  {
    v10 = from->m_quad;
    v11 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, (__m128)0i64), 196);
    end.m_quad = _mm_add_ps(from->m_quad, v6);
    v12 = _mm_shuffle_ps(v11, v11, 241);
    v13 = _mm_shuffle_ps(v11, v11, 206);
    v14 = _mm_mul_ps(v12, v12);
    v15 = _mm_mul_ps(v13, v13);
    v16 = _mm_cmpltps(
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
              _mm_cmpleps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))));
    v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v21));
    v23 = _mm_shuffle_ps(v22, v22, 201);
    v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v25 = _mm_rsqrt_ps(v24);
    v26 = _mm_mul_ps(
            v21,
            _mm_andnot_ps(
              _mm_cmpleps(v24, (__m128)0i64),
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
    hkDebugDisplay::displayLine(v8, &end, &v31, v7, id, tag);
    hkDebugDisplay::displayLine(v8, &end, &v32, v7, id, tag);
    hkDebugDisplay::displayLine(v8, &end, &v33, v7, id, tag);
    hkDebugDisplay::displayLine(v8, &end, &v34, v7, id, tag);
  }
}

// File Line: 338
// RVA: 0xE6F4F0
void __fastcall hkDebugDisplay::displayStar(hkDebugDisplay *this, hkVector4f *position, float scale, unsigned int color, int id, int tag)
{
  unsigned int v6; // edi
  hkVector4f *v7; // rsi
  hkDebugDisplay *v8; // rbp
  signed __int64 v9; // rbx
  __m128 v10; // xmm3
  __m128 v11; // [rsp+30h] [rbp-68h]
  hkVector4f end; // [rsp+40h] [rbp-58h]
  hkVector4f start; // [rsp+50h] [rbp-48h]

  v6 = color;
  v7 = position;
  v8 = this;
  v9 = 0i64;
  do
  {
    v10 = v7->m_quad;
    v11 = 0i64;
    v11.m128_f32[v9] = scale;
    end.m_quad = _mm_sub_ps(v10, v11);
    start.m_quad = _mm_add_ps(v10, v11);
    hkDebugDisplay::displayLine(v8, &start, &end, v6, id, tag);
    ++v9;
  }
  while ( v9 < 3 );
}

// File Line: 352
// RVA: 0xE6F5C0
void __fastcall hkDebugDisplay::displayStarModelSpace(hkDebugDisplay *this, hkQsTransformf *worldFromModel, hkVector4f *position, float scale, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v7; // rbx
  hkVector4f positiona; // [rsp+30h] [rbp-28h]

  v7 = this;
  hkVector4f::setTransformedPos(&positiona, worldFromModel, position);
  hkDebugDisplay::displayStar(v7, &positiona, scale, color, id, tag);
}

// File Line: 359
// RVA: 0xE6F620
void __fastcall hkDebugDisplay::displayStarModelSpace(hkDebugDisplay *this, hkTransformf *worldFromModel, hkVector4f *position, float scale, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v7; // rbx
  hkVector4f positiona; // [rsp+30h] [rbp-28h]

  v7 = this;
  hkVector4f::setTransformedPos(&positiona, worldFromModel, position);
  hkDebugDisplay::displayStar(v7, &positiona, scale, color, id, tag);
}

// File Line: 366
// RVA: 0xE70090
void __fastcall hkDebugDisplay::displayAabb(hkDebugDisplay *this, hkAabb *aabb, unsigned int color, int id)
{
  __m128 v4; // xmm4
  __m128 v5; // xmm6
  int v6; // esi
  unsigned int v7; // er14
  hkDebugDisplay *v8; // r15
  __m128 v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm11
  __m128 v12; // xmm13
  __m128 v13; // xmm12
  __m128 v14; // xmm10
  __m128 v15; // xmm5
  __m128 v16; // xmm2
  __m128 v17; // xmm10
  hkVector4f *v18; // rbx
  signed __int64 v19; // rdi
  hkVector4f start; // [rsp+30h] [rbp-B8h]
  __m128 v21; // [rsp+40h] [rbp-A8h]
  __m128 v22; // [rsp+50h] [rbp-98h]
  __m128 v23; // [rsp+60h] [rbp-88h]
  char v24[24]; // [rsp+70h] [rbp-78h]
  __m128 v25; // [rsp+88h] [rbp-60h]
  __int128 v26; // [rsp+98h] [rbp-50h]
  __m128 v27; // [rsp+A8h] [rbp-40h]
  __int128 v28; // [rsp+B8h] [rbp-30h]
  __m128 v29; // [rsp+C8h] [rbp-20h]
  __m128 v30; // [rsp+D8h] [rbp-10h]
  __m128 v31; // [rsp+E8h] [rbp+0h]
  __m128 v32; // [rsp+F8h] [rbp+10h]
  __m128 v33; // [rsp+108h] [rbp+20h]
  __m128 v34; // [rsp+118h] [rbp+30h]
  __int128 v35; // [rsp+128h] [rbp+40h]
  __m128 v36; // [rsp+138h] [rbp+50h]
  __m128 v37; // [rsp+148h] [rbp+60h]
  __m128 v38; // [rsp+158h] [rbp+70h]
  __m128 v39; // [rsp+168h] [rbp+80h]
  __m128 v40; // [rsp+178h] [rbp+90h]
  __int128 v41; // [rsp+188h] [rbp+A0h]
  int v42; // [rsp+258h] [rbp+170h]

  v4 = (__m128)aabb->m_min.m_quad.m128_u32[2];
  v5 = (__m128)aabb->m_max.m_quad.m128_u32[0];
  v6 = id;
  v7 = color;
  v8 = this;
  v9 = (__m128)aabb->m_max.m_quad.m128_u32[2];
  v10 = (__m128)aabb->m_max.m_quad.m128_u32[1];
  v11 = (__m128)aabb->m_min.m_quad.m128_u32[0];
  v12 = (__m128)aabb->m_min.m_quad.m128_u32[1];
  v13 = _mm_unpacklo_ps(v11, v4);
  v14 = (__m128)aabb->m_min.m_quad.m128_u32[0];
  v15 = _mm_unpacklo_ps(v5, v4);
  v16 = _mm_unpacklo_ps(v10, (__m128)0i64);
  start.m_quad = _mm_unpacklo_ps(v13, _mm_unpacklo_ps(v12, (__m128)0i64));
  v22 = start.m_quad;
  v17 = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v9), _mm_unpacklo_ps(v12, (__m128)0i64));
  v21 = _mm_unpacklo_ps(v13, v16);
  v23 = v17;
  v30 = v21;
  *(__m128 *)&v24[8] = _mm_unpacklo_ps(_mm_unpacklo_ps(v5, v9), v16);
  v26 = *(_OWORD *)&v24[8];
  v28 = *(_OWORD *)&v24[8];
  *(__m128 *)((char *)&v23 + 8) = _mm_unpacklo_ps(v15, _mm_unpacklo_ps(v12, (__m128)0i64));
  v32 = v21;
  v25 = _mm_unpacklo_ps(v15, v16);
  v31 = v25;
  v34 = v25;
  v27 = _mm_unpacklo_ps(_mm_unpacklo_ps(v11, v9), v16);
  v33 = v27;
  v29 = _mm_unpacklo_ps(_mm_unpacklo_ps(v5, v9), _mm_unpacklo_ps(v12, (__m128)0i64));
  v35 = *(__int128 *)((char *)&v23 + 8);
  v36 = v27;
  v18 = &start;
  v19 = 12i64;
  v37 = v17;
  v38 = v17;
  v39 = v29;
  v40 = v29;
  v41 = *(__int128 *)((char *)&v23 + 8);
  do
  {
    hkDebugDisplay::displayLine(v8, v18, v18 + 1, v7, v6, v42);
    v18 += 2;
    --v19;
  }
  while ( v19 );
}

// File Line: 412
// RVA: 0xE702B0
void __fastcall hkDebugDisplay::displayAabb(hkDebugDisplay *this, hkTransformf *transform, hkAabb *aabb, unsigned int color, int id)
{
  hkVector4f v5; // xmm3
  hkVector4f v6; // xmm4
  hkVector4f v7; // xmm5
  unsigned int v8; // esi
  hkDebugDisplay *v9; // r14
  hkVector4f *v10; // r10
  hkVector4f v11; // xmm6
  signed int v12; // eax
  __m128 *v13; // r9
  __m128 *v14; // rdx
  __m128 *v15; // rcx
  __m128 v16; // xmm2
  hkVector4f start; // [rsp+30h] [rbp-C8h]
  hkVector4f end; // [rsp+40h] [rbp-B8h]
  hkVector4f v19; // [rsp+50h] [rbp-A8h]
  hkVector4f v20; // [rsp+60h] [rbp-98h]
  hkVector4f v21; // [rsp+70h] [rbp-88h]
  hkVector4f v22; // [rsp+88h] [rbp-70h]
  hkVector4f v23; // [rsp+98h] [rbp-60h]
  __m128 v24; // [rsp+A8h] [rbp-50h]
  __m128 v25; // [rsp+B8h] [rbp-40h]
  __m128 v26; // [rsp+C8h] [rbp-30h]
  __m128 v27; // [rsp+D8h] [rbp-20h]
  __m128 v28; // [rsp+E8h] [rbp-10h]
  __m128 v29; // [rsp+F8h] [rbp+0h]
  int v30; // [rsp+158h] [rbp+60h]

  v5.m_quad = (__m128)transform->m_rotation.m_col1;
  v6.m_quad = (__m128)transform->m_rotation.m_col0;
  v7.m_quad = (__m128)transform->m_rotation.m_col2;
  v8 = color;
  v9 = this;
  v10 = &start;
  v11.m_quad = (__m128)transform->m_translation;
  v12 = 0;
  do
  {
    if ( v12 & 4 )
    {
      v13 = &v28;
      v28 = _mm_shuffle_ps(aabb->m_max.m_quad, aabb->m_max.m_quad, 170);
    }
    else
    {
      v13 = &v29;
      v29 = _mm_shuffle_ps(aabb->m_min.m_quad, aabb->m_min.m_quad, 170);
    }
    if ( v12 & 2 )
    {
      v14 = &v26;
      v26 = _mm_shuffle_ps(aabb->m_max.m_quad, aabb->m_max.m_quad, 85);
    }
    else
    {
      v14 = &v24;
      v24 = _mm_shuffle_ps(aabb->m_min.m_quad, aabb->m_min.m_quad, 85);
    }
    if ( v12 & 1 )
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
    ++v10;
    v16 = _mm_movelh_ps(_mm_unpacklo_ps(*v15, *v14), _mm_unpacklo_ps(*v13, aabbOut.m_quad));
    v10[-1].m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v6.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v5.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v7.m_quad)),
                       v11.m_quad);
  }
  while ( v12 < 8 );
  hkDebugDisplay::displayLine(v9, &start, &end, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &end, &v20, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &v20, &v19, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &v19, &start, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &v21, (hkVector4f *)((char *)&v21 + 8), v8, v30, id);
  hkDebugDisplay::displayLine(v9, (hkVector4f *)((char *)&v21 + 8), &v23, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &v23, &v22, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &v22, &v21, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &start, &v21, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &end, (hkVector4f *)((char *)&v21 + 8), v8, v30, id);
  hkDebugDisplay::displayLine(v9, &v19, &v22, v8, v30, id);
  hkDebugDisplay::displayLine(v9, &v20, &v23, v8, v30, id);
}

// File Line: 441
// RVA: 0xE6F680
void __fastcall hkDebugDisplay::displayPlane(hkDebugDisplay *this, hkVector4f *plane, hkVector4f *offset, float scale, unsigned int color, int id, int tag)
{
  __m128 v7; // xmm5
  hkVector4f *v8; // r12
  hkDebugDisplay *v9; // rsi
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
  signed int v23; // ebx
  __m128 v24; // xmm2
  signed __int64 v25; // rdi
  __m128 v26; // xmm9
  __m128 v27; // xmm0
  int v28; // eax
  __m128 v29; // xmm0
  __m128 v30; // xmm7
  __m128 v31; // xmm7
  hkVector4f end; // [rsp+30h] [rbp-A8h]
  hkVector4f start; // [rsp+40h] [rbp-98h]
  hkVector4f from; // [rsp+50h] [rbp-88h]
  float v35; // [rsp+F8h] [rbp+20h]

  v35 = scale;
  v7 = plane->m_quad;
  v8 = plane;
  v9 = this;
  v10 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)plane->m_quad, 1u), 1u);
  v11 = _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(plane->m_quad, plane->m_quad, 255));
  end.m_quad = 0i64;
  v12 = _mm_shuffle_ps(v7, v7, 201);
  v13 = _mm_add_ps(_mm_mul_ps(v11, v7), offset->m_quad);
  v14 = _mm_shuffle_ps((__m128)LODWORD(v35), (__m128)LODWORD(v35), 0);
  from.m_quad = v13;
  end.m_quad.m128_i32[((unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                              _mm_and_ps(
                                                                                _mm_cmpleps(
                                                                                  _mm_max_ps(
                                                                                    _mm_shuffle_ps(v10, v10, 170),
                                                                                    _mm_max_ps(
                                                                                      _mm_shuffle_ps(v10, v10, 85),
                                                                                      _mm_shuffle_ps(v10, v10, 0))),
                                                                                  v10),
                                                                                (__m128)xmmword_141ABC4C0))]
                     + 1)
                    % 3] = 1065353216;
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(end.m_quad, end.m_quad, 201), v7), _mm_mul_ps(v12, end.m_quad));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_mul_ps(_mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v18, (__m128)0i64), _mm_rsqrt_ps(v18)), v16), v14);
  v20 = _mm_sub_ps(_mm_mul_ps(v12, v19), _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v7));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_mul_ps(v21, v21);
  v23 = 1;
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v25 = 4i64;
  v26 = _mm_mul_ps(_mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v24, (__m128)0i64), _mm_rsqrt_ps(v24)), v21), v14);
  while ( 1 )
  {
    v27 = ((_BYTE)v23 - 1) & 2 ? _mm_sub_ps(v13, v26) : _mm_add_ps(v26, v13);
    v28 = v23 % 4 / 2;
    v29 = v28 ? _mm_sub_ps(v27, v19) : _mm_add_ps(v27, v19);
    start.m_quad = v29;
    v30 = v28 ? _mm_sub_ps(v13, v26) : _mm_add_ps(v13, v26);
    v31 = ++v23 % 4 / 2 ? _mm_sub_ps(v30, v19) : _mm_add_ps(v30, v19);
    end.m_quad = v31;
    hkDebugDisplay::displayLine(v9, &start, &end, color, id, tag);
    if ( !--v25 )
      break;
    v13 = from.m_quad;
  }
  start.m_quad = _mm_mul_ps(v8->m_quad, v14);
  hkDebugDisplay::displayArrow(v9, &from, &start, color, id, tag);
}

// File Line: 481
// RVA: 0xE6F930
void __fastcall hkDebugDisplay::displayModelSpacePose(hkDebugDisplay *this, int numTransforms, const __int16 *parentIndices, hkQsTransformf *modelSpacePose, hkQsTransformf *worldFromModel, int id, int tag, unsigned int color)
{
  hkDebugDisplay *v8; // rbx
  hkQsTransformf *v9; // r13
  int v10; // edi
  __int64 v11; // rsi
  int numTransformsa; // [rsp+88h] [rbp+10h]
  __int16 *parentIndicesa; // [rsp+90h] [rbp+18h]

  parentIndicesa = (__int16 *)parentIndices;
  numTransformsa = numTransforms;
  v8 = this;
  v9 = modelSpacePose;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v8->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      hkDebugDisplayHandler::displayModelSpacePose(
        v8->m_debugDisplayHandlers.m_data[v11],
        numTransformsa,
        parentIndicesa,
        v9,
        worldFromModel,
        color,
        id,
        tag);
      ++v10;
      ++v11;
    }
    while ( v10 < v8->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v8->m_arrayLock->m_section);
}

// File Line: 491
// RVA: 0xE6FA20
void __fastcall hkDebugDisplay::displayLocalSpacePose(hkDebugDisplay *this, int numTransforms, const __int16 *parentIndices, hkQsTransformf *localSpacePose, hkQsTransformf *worldFromModel, int id, int tag, unsigned int color)
{
  hkDebugDisplay *v8; // rbx
  hkQsTransformf *v9; // r13
  int v10; // edi
  __int64 v11; // rsi
  int numTransformsa; // [rsp+88h] [rbp+10h]
  __int16 *parentIndicesa; // [rsp+90h] [rbp+18h]

  parentIndicesa = (__int16 *)parentIndices;
  numTransformsa = numTransforms;
  v8 = this;
  v9 = localSpacePose;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v8->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      hkDebugDisplayHandler::displayLocalSpacePose(
        v8->m_debugDisplayHandlers.m_data[v11],
        numTransformsa,
        parentIndicesa,
        v9,
        worldFromModel,
        color,
        id,
        tag);
      ++v10;
      ++v11;
    }
    while ( v10 < v8->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v8->m_arrayLock->m_section);
}

// File Line: 501
// RVA: 0xE6FB10
void __fastcall hkDebugDisplay::displayText(hkDebugDisplay *this, const char *text, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v5; // rbx
  int v6; // er14
  unsigned int v7; // er15
  const char *v8; // r12
  int v9; // edi
  int v10; // ebp
  __int64 v11; // rsi
  __int64 v12; // [rsp+20h] [rbp-38h]
  _QWORD v13[6]; // [rsp+28h] [rbp-30h]
  char v14; // [rsp+60h] [rbp+8h]

  v5 = this;
  v6 = id;
  v7 = color;
  v8 = text;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v9 = 0;
  if ( v5->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = tag;
    v11 = 0i64;
    do
    {
      LODWORD(v13[0]) = v10;
      LODWORD(v12) = v6;
      v5->m_debugDisplayHandlers.m_data[v11]->vfptr->displayText(
        v5->m_debugDisplayHandlers.m_data[v11],
        (hkResult *)&v14,
        v8,
        v7,
        v12,
        v13[0]);
      ++v9;
      ++v11;
    }
    while ( v9 < v5->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v5->m_arrayLock->m_section);
}

// File Line: 512
// RVA: 0xE6FBB0
void __fastcall hkDebugDisplay::display3dText(hkDebugDisplay *this, const char *text, hkVector4f *pos, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v6; // rbx
  unsigned int v7; // er15
  hkVector4f *v8; // r12
  const char *v9; // r13
  int v10; // edi
  int v11; // ebp
  int v12; // er14
  __int64 v13; // rsi
  __int64 v14; // [rsp+20h] [rbp-48h]
  __int64 v15; // [rsp+28h] [rbp-40h]
  _QWORD v16[7]; // [rsp+30h] [rbp-38h]
  char v17; // [rsp+70h] [rbp+8h]

  v6 = this;
  v7 = color;
  v8 = pos;
  v9 = text;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v6->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = id;
    v13 = 0i64;
    do
    {
      LODWORD(v16[0]) = v11;
      LODWORD(v15) = v12;
      LODWORD(v14) = v7;
      v6->m_debugDisplayHandlers.m_data[v13]->vfptr->display3dText(
        v6->m_debugDisplayHandlers.m_data[v13],
        (hkResult *)&v17,
        v9,
        v8,
        v14,
        v15,
        v16[0]);
      ++v10;
      ++v13;
    }
    while ( v10 < v6->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v6->m_arrayLock->m_section);
}

// File Line: 522
// RVA: 0xE6FF30
void __fastcall hkDebugDisplay::displayGeometry(hkDebugDisplay *this, hkArrayBase<hkDisplayGeometry *> *geometries, hkTransformf *transform, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v6; // rbx
  unsigned int v7; // er15
  hkTransformf *v8; // r12
  hkArrayBase<hkDisplayGeometry *> *v9; // r13
  int v10; // edi
  int v11; // ebp
  int v12; // er14
  __int64 v13; // rsi
  __int64 v14; // [rsp+20h] [rbp-48h]
  __int64 v15; // [rsp+28h] [rbp-40h]
  _QWORD v16[7]; // [rsp+30h] [rbp-38h]
  char v17; // [rsp+70h] [rbp+8h]

  v6 = this;
  v7 = color;
  v8 = transform;
  v9 = geometries;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v10 = 0;
  if ( v6->m_debugDisplayHandlers.m_size > 0 )
  {
    v11 = tag;
    v12 = id;
    v13 = 0i64;
    do
    {
      LODWORD(v16[0]) = v11;
      LODWORD(v15) = v12;
      LODWORD(v14) = v7;
      v6->m_debugDisplayHandlers.m_data[v13]->vfptr->displayGeometry(
        v6->m_debugDisplayHandlers.m_data[v13],
        (hkResult *)&v17,
        v9,
        v8,
        v14,
        v15,
        v16[0]);
      ++v10;
      ++v13;
    }
    while ( v10 < v6->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v6->m_arrayLock->m_section);
}

// File Line: 533
// RVA: 0xE6FFF0
void __fastcall hkDebugDisplay::displayGeometry(hkDebugDisplay *this, hkArrayBase<hkDisplayGeometry *> *geometries, unsigned int color, int id, int tag)
{
  hkDebugDisplay *v5; // rbx
  int v6; // er14
  unsigned int v7; // er15
  hkArrayBase<hkDisplayGeometry *> *v8; // r12
  int v9; // edi
  int v10; // ebp
  __int64 v11; // rsi
  __int64 v12; // [rsp+20h] [rbp-38h]
  _QWORD v13[6]; // [rsp+28h] [rbp-30h]
  char v14; // [rsp+60h] [rbp+8h]

  v5 = this;
  v6 = id;
  v7 = color;
  v8 = geometries;
  EnterCriticalSection(&this->m_arrayLock->m_section);
  v9 = 0;
  if ( v5->m_debugDisplayHandlers.m_size > 0 )
  {
    v10 = tag;
    v11 = 0i64;
    do
    {
      LODWORD(v13[0]) = v10;
      LODWORD(v12) = v6;
      v5->m_debugDisplayHandlers.m_data[v11]->vfptr->displayGeometry(
        v5->m_debugDisplayHandlers.m_data[v11],
        (hkResult *)&v14,
        v8,
        v7,
        v12,
        v13[0]);
      ++v9;
      ++v11;
    }
    while ( v9 < v5->m_debugDisplayHandlers.m_size );
  }
  LeaveCriticalSection(&v5->m_arrayLock->m_section);
}

// File Line: 543
// RVA: 0xE70550
void __fastcall hkDebugDisplay::displayLitTriangle(hkDebugDisplay *this, hkVector4f *a, hkVector4f *b, hkVector4f *c, unsigned int color)
{
  hkVector4f *v5; // rbx
  hkVector4f *v6; // rdi
  hkVector4f *v7; // rsi
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

  v5 = c;
  v6 = b;
  v7 = a;
  v8 = _mm_sub_ps(b->m_quad, a->m_quad);
  v9 = _mm_sub_ps(c->m_quad, a->m_quad);
  v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v13), (__m128)0i64);
  v16 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v13, (__m128)0i64),
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
    v21 = _mm_cmpleps(v19, (__m128)0i64);
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
                  _mm_cmpleps(v25, (__m128)0i64),
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
            COERCE_CONST_FLOAT(_mm_shuffle_ps(v31, v31, 85)),
            COERCE_CONST_FLOAT(_mm_shuffle_ps(v31, v31, 170)),
            (float)(color >> 24) * 0.0039215689);
    hkDebugDisplay::displayTriangle(
      hkSingleton<hkDebugDisplay>::s_instance,
      v7,
      v6,
      v5,
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

