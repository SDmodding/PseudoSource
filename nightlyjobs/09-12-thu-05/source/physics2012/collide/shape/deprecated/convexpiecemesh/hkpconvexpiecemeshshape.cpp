// File Line: 43
// RVA: 0xD118E0
void __fastcall hkpConvexPieceMeshShape::hkpConvexPieceMeshShape(
        hkpConvexPieceMeshShape *this,
        hkpShapeCollection *inputMesh,
        hkpConvexPieceStreamData *convexPieceStream,
        float radius)
{
  hkpShapeCollection::hkpShapeCollection(this, COLLECTION, COLLECTION_USER);
  this->m_radius = radius;
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShape};
  this->m_convexPieceStream = convexPieceStream;
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShapeContainer};
  this->m_displayMesh = inputMesh;
  hkReferencedObject::addReference(inputMesh);
  hkReferencedObject::addReference(this->m_convexPieceStream);
}

// File Line: 56
// RVA: 0xD11960
void __fastcall hkpConvexPieceMeshShape::hkpConvexPieceMeshShape(
        hkpConvexPieceMeshShape *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpShapeCollection::hkpShapeCollection(this, flag);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
    this->m_type.m_storage = 18;
}

// File Line: 66
// RVA: 0xD119A0
void __fastcall hkpConvexPieceMeshShape::~hkpConvexPieceMeshShape(hkpConvexPieceMeshShape *this)
{
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShapeContainer};
  hkReferencedObject::removeReference(this->m_displayMesh);
  hkReferencedObject::removeReference(this->m_convexPieceStream);
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 73
// RVA: 0xD11A00
__int64 __fastcall hkpConvexPieceMeshShape::getFirstKey(hkpConvexPieceMeshShape *this)
{
  return 0i64;
}

// File Line: 85
// RVA: 0xD11A10
__int64 __fastcall hkpConvexPieceMeshShape::getNextKey(hkpConvexPieceMeshShape *this, unsigned int oldKey)
{
  int v2; // edx
  __int64 result; // rax

  v2 = oldKey + 1;
  result = 0xFFFFFFFFi64;
  if ( v2 < *(_DWORD *)(*(_QWORD *)&this->m_type.m_storage + 40i64)
          + *(_DWORD *)(*(_QWORD *)&this->m_type.m_storage + 56i64) )
    return (unsigned int)v2;
  return result;
}

// File Line: 97
// RVA: 0xD11A30
hkpShape *__fastcall hkpConvexPieceMeshShape::getChildShape(
        hkpConvexPieceMeshShape *this,
        int key,
        hkpConvexPieceShape *buffer)
{
  int v3; // r15d
  __int64 v5; // rdi
  hkpConvexPieceMeshShape *v6; // r14
  __int64 v7; // rax
  __int64 v8; // rsi
  __int64 v9; // r8
  __int64 v10; // rdx
  __int64 v11; // rax
  int v12; // ecx
  const unsigned int *v13; // r12
  unsigned __int64 v14; // rbp
  __int64 v15; // rcx
  int v16; // edi
  hkpConvexPieceMeshShape *v17; // r13
  __int64 v18; // rax
  __int64 v19; // r14
  _OWORD *v20; // rbx
  hkpShape *v21; // rax
  __int64 v22; // rax
  int v23; // edi
  __int64 v24; // rax
  _OWORD *v25; // rbx
  unsigned int *v26; // rdx
  _OWORD *v27; // rax
  __int128 v28; // xmm0
  char v29[512]; // [rsp+20h] [rbp-238h] BYREF
  hkBool result; // [rsp+268h] [rbp+10h] BYREF
  __int64 v32; // [rsp+270h] [rbp+18h]

  v3 = 0;
  v5 = key;
  v6 = this;
  if ( buffer )
  {
    hkpConvexPieceShape::hkpConvexPieceShape(buffer, *(float *)&this->hkpShapeCollection::hkpShapeContainer::vfptr);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  *(_QWORD *)(v8 + 64) = v6->m_userData;
  v9 = *(_QWORD *)&v6->m_type.m_storage;
  if ( (unsigned int)v5 >= *(_DWORD *)(v9 + 40) )
  {
    *(_DWORD *)(v8 + 80) = 1;
    v22 = *(_QWORD *)&v6->m_type.m_storage;
    v23 = v5 - *(_DWORD *)(v22 + 40);
    v24 = *(_QWORD *)(v22 + 48);
    *(_DWORD *)(v8 + 56) = 3;
    v25 = (_OWORD *)(((unsigned __int64)&buffer[1].m_referenceCount + 5) & 0xFFFFFFFFFFFFFFF0ui64);
    v26 = (unsigned int *)(v24 + 4i64 * v23);
    *(_QWORD *)(v8 + 48) = v25;
    *(_QWORD *)(v8 + 72) = v26;
    v27 = (_OWORD *)(*(__int64 (__fastcall **)(unsigned __int64, _QWORD, char *))(*(_QWORD *)(v6->m_userData + 32)
                                                                                + 40i64))(
                      v6->m_userData + 32,
                      *v26,
                      v29);
    *v25 = v27[3];
    v25[1] = v27[4];
    v28 = v27[5];
    v21 = (hkpShape *)v8;
    v25[2] = v28;
  }
  else
  {
    v10 = *(unsigned int *)(*(_QWORD *)(v9 + 32) + 4 * v5);
    v11 = *(_QWORD *)(v9 + 16);
    v12 = *(_DWORD *)(v11 + 4 * v10);
    v13 = (const unsigned int *)(v11 + 4 * v10);
    v14 = ((unsigned __int64)&buffer[1].m_referenceCount + 5) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(v8 + 48) = v14;
    *(_DWORD *)(v8 + 56) = 0;
    *(_DWORD *)(v8 + 80) = v12;
    *(_QWORD *)(v8 + 72) = v13 + 1;
    if ( v12 <= 0 )
    {
      return (hkpShape *)v8;
    }
    else
    {
      v15 = 0i64;
      v16 = 0;
      v32 = 0i64;
      v17 = (hkpConvexPieceMeshShape *)((char *)v6 - 32);
      do
      {
        v18 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, char *))(*(_QWORD *)(v6->m_userData + 32) + 40i64))(
                v6->m_userData + 32,
                *(unsigned int *)(v15 + *(_QWORD *)(v8 + 72)),
                v29);
        v19 = 3i64;
        v20 = (_OWORD *)(v18 + 48);
        do
        {
          if ( hkpConvexPieceMeshShape::vertexIsSet(v17, &result, v13, v16)->m_bool )
          {
            v14 += 16i64;
            *(_OWORD *)(v14 - 16) = *v20;
            ++*(_DWORD *)(v8 + 56);
          }
          ++v16;
          ++v20;
          --v19;
        }
        while ( v19 );
        v6 = this;
        ++v3;
        v15 = v32 + 4;
        v32 += 4i64;
      }
      while ( v3 < *(_DWORD *)(v8 + 80) );
      return (hkpShape *)v8;
    }
  }
  return v21;
}

// File Line: 197
// RVA: 0xD11C20
hkBool *__fastcall hkpConvexPieceMeshShape::vertexIsSet(
        hkpConvexPieceMeshShape *this,
        hkBool *result,
        const unsigned int *stream,
        int key)
{
  result->m_bool = ((1 << (key % 0x1Fui64)) & stream[key / 0x1Fui64 + 1 + *stream]) != 0;
  return result;
}

// File Line: 207
// RVA: 0xD11C70
__int64 __fastcall hkpConvexPieceMeshShape::getCollisionFilterInfo(hkpConvexPieceMeshShape *this, int key)
{
  __int64 v2; // r9
  unsigned int v3; // eax

  v2 = *(_QWORD *)&this->m_type.m_storage;
  v3 = *(_DWORD *)(v2 + 40);
  if ( key >= v3 )
    return (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(*(_QWORD *)(this->m_userData + 32) + 32i64))(
             this->m_userData + 32,
             *(unsigned int *)(*(_QWORD *)(v2 + 48) + 4i64 * (int)(key - v3)));
  else
    return (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(*(_QWORD *)(this->m_userData + 32) + 32i64))(
             this->m_userData + 32,
             *(unsigned int *)(*(_QWORD *)(v2 + 16) + 4i64 * *(unsigned int *)(*(_QWORD *)(v2 + 32) + 4i64 * key) + 4));
}

// File Line: 230
// RVA: 0xD11CD0
void __fastcall hkpConvexPieceMeshShape::getAabb(
        hkpConvexPieceMeshShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkpShapeContainer *v4; // rdi
  unsigned int i; // esi
  hkpShape *v8; // rax
  hkVector4f v9; // xmm1
  __m128 v10[2]; // [rsp+20h] [rbp-238h] BYREF
  char v11[512]; // [rsp+40h] [rbp-218h] BYREF

  v4 = &this->hkpShapeContainer;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  for ( i = v4->vfptr->getFirstKey(v4); i != -1; i = v4->vfptr->getNextKey(v4, i) )
  {
    v8 = v4->vfptr->getChildShape(v4, i, (char (*)[512])v11);
    ((void (__fastcall *)(hkpShape *, hkTransformf *, hkBaseObjectVtbl *, __m128 *))v8->vfptr[2].__vecDelDtor)(
      v8,
      localToWorld,
      v8->vfptr,
      v10);
    v9.m_quad = _mm_max_ps(out->m_max.m_quad, v10[1]);
    out->m_min.m_quad = _mm_min_ps(out->m_min.m_quad, v10[0]);
    out->m_max = (hkVector4f)v9.m_quad;
  }
}

// File Line: 265
// RVA: 0xD11DA0
void __fastcall hkpConvexPieceMeshShape::getStats(
        hkpConvexPieceMeshShape *this,
        hkpConvexPieceMeshShape::Stats *statsOut)
{
  int v2; // r11d
  int m_maxTrianglesPerConvexPiece; // r8d
  __int64 v5; // rbx
  int v6; // edx
  float m_numTriangles; // xmm1_4

  v2 = 0;
  statsOut->m_numTriangles += this->m_convexPieceStream->m_convexPieceSingleTriangles.m_size;
  statsOut->m_numConvexPieces += this->m_convexPieceStream->m_convexPieceSingleTriangles.m_size;
  if ( this->m_convexPieceStream->m_convexPieceOffsets.m_size > 0 )
  {
    m_maxTrianglesPerConvexPiece = statsOut->m_maxTrianglesPerConvexPiece;
    v5 = 0i64;
    do
    {
      v6 = this->m_convexPieceStream->m_convexPieceStream.m_data[this->m_convexPieceStream->m_convexPieceOffsets.m_data[v5++]];
      statsOut->m_numTriangles += v6;
      if ( m_maxTrianglesPerConvexPiece > v6 )
        v6 = m_maxTrianglesPerConvexPiece;
      ++v2;
      statsOut->m_maxTrianglesPerConvexPiece = v6;
      m_maxTrianglesPerConvexPiece = v6;
    }
    while ( v2 < this->m_convexPieceStream->m_convexPieceOffsets.m_size );
  }
  m_numTriangles = (float)statsOut->m_numTriangles;
  statsOut->m_numConvexPieces += this->m_convexPieceStream->m_convexPieceOffsets.m_size;
  statsOut->m_avgNumTriangles = m_numTriangles / (float)statsOut->m_numConvexPieces;
}

