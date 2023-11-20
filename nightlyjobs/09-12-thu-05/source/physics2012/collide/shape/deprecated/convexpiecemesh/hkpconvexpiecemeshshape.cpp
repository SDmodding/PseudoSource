// File Line: 43
// RVA: 0xD118E0
void __fastcall hkpConvexPieceMeshShape::hkpConvexPieceMeshShape(hkpConvexPieceMeshShape *this, hkpShapeCollection *inputMesh, hkpConvexPieceStreamData *convexPieceStream, float radius)
{
  hkpShapeCollection *v4; // rdi
  hkpConvexPieceStreamData *v5; // rbx
  hkpConvexPieceMeshShape *v6; // rsi

  v4 = inputMesh;
  v5 = convexPieceStream;
  v6 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, COLLECTION, COLLECTION_USER);
  v6->m_radius = radius;
  v6->vfptr = (hkBaseObjectVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShape};
  v6->m_convexPieceStream = v5;
  v6->vfptr = (hkpShapeContainerVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShapeContainer};
  v6->m_displayMesh = v4;
  hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  hkReferencedObject::addReference((hkReferencedObject *)&v6->m_convexPieceStream->vfptr);
}

// File Line: 56
// RVA: 0xD11960
void __fastcall hkpConvexPieceMeshShape::hkpConvexPieceMeshShape(hkpConvexPieceMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexPieceMeshShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShape};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShapeContainer};
  if ( v3 )
    v2->m_type.m_storage = 18;
}

// File Line: 66
// RVA: 0xD119A0
void __fastcall hkpConvexPieceMeshShape::~hkpConvexPieceMeshShape(hkpConvexPieceMeshShape *this)
{
  hkpConvexPieceMeshShape *v1; // rbx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShape};
  this->vfptr = (hkpShapeContainerVtbl *)&hkpConvexPieceMeshShape::`vftable{for `hkpShapeContainer};
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_displayMesh->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_convexPieceStream->vfptr);
  v1->vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 73
// RVA: 0xD11A00
__int64 __fastcall hkpConvexPieceMeshShape::getFirstKey(hkpConvexPieceMeshShape *this)
{
  return 0i64;
}

// File Line: 85
// RVA: 0xD11A10
signed __int64 __fastcall hkpConvexPieceMeshShape::getNextKey(hkpConvexPieceMeshShape *this, unsigned int oldKey)
{
  int v2; // edx
  signed __int64 result; // rax

  v2 = oldKey + 1;
  result = 0xFFFFFFFFi64;
  if ( v2 < *(_DWORD *)(*(_QWORD *)&this->m_type.m_storage + 40i64)
          + *(_DWORD *)(*(_QWORD *)&this->m_type.m_storage + 56i64) )
    result = (unsigned int)v2;
  return result;
}

// File Line: 97
// RVA: 0xD11A30
hkpShape *__fastcall hkpConvexPieceMeshShape::getChildShape(hkpConvexPieceMeshShape *this, unsigned int key, char (*buffer)[512])
{
  int v3; // er15
  char (*v4)[512]; // rbx
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
  signed __int64 v19; // r14
  _OWORD *v20; // rbx
  hkpShape *v21; // rax
  __int64 v22; // rax
  int v23; // edi
  __int64 v24; // rax
  _OWORD *v25; // rbx
  unsigned int *v26; // rdx
  _OWORD *v27; // rax
  __int128 v28; // xmm0
  char v29; // [rsp+20h] [rbp-238h]
  hkpConvexPieceMeshShape *v30; // [rsp+260h] [rbp+8h]
  hkBool result; // [rsp+268h] [rbp+10h]
  __int64 v32; // [rsp+270h] [rbp+18h]

  v30 = this;
  v3 = 0;
  v4 = buffer;
  v5 = (signed int)key;
  v6 = this;
  if ( buffer )
  {
    hkpConvexPieceShape::hkpConvexPieceShape((hkpConvexPieceShape *)buffer, *(float *)&this->vfptr);
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
    v25 = (_OWORD *)((unsigned __int64)&(*v4)[103] & 0xFFFFFFFFFFFFFFF0ui64);
    v26 = (unsigned int *)(v24 + 4i64 * v23);
    *(_QWORD *)(v8 + 48) = v25;
    *(_QWORD *)(v8 + 72) = v26;
    v27 = (_OWORD *)(*(__int64 (__fastcall **)(unsigned __int64, _QWORD, char *))(*(_QWORD *)(v6->m_userData + 32)
                                                                                + 40i64))(
                      v6->m_userData + 32,
                      *v26,
                      &v29);
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
    v14 = (unsigned __int64)&(*v4)[103] & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(v8 + 48) = v14;
    *(_DWORD *)(v8 + 56) = 0;
    *(_DWORD *)(v8 + 80) = v12;
    *(_QWORD *)(v8 + 72) = v13 + 1;
    if ( v12 <= 0 )
    {
      v21 = (hkpShape *)v8;
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
                &v29);
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
        v6 = v30;
        ++v3;
        v15 = v32 + 4;
        v32 += 4i64;
      }
      while ( v3 < *(_DWORD *)(v8 + 80) );
      v21 = (hkpShape *)v8;
    }
  }
  return v21;
}

// File Line: 197
// RVA: 0xD11C20
hkBool *__fastcall hkpConvexPieceMeshShape::vertexIsSet(hkpConvexPieceMeshShape *this, hkBool *result, const unsigned int *stream, int key)
{
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // r9

  v4 = key;
  v5 = (unsigned __int64)((v4 * (unsigned __int128)0x842108421084211ui64 >> 64)
                        + ((unsigned __int64)(key - (v4 * (unsigned __int128)0x842108421084211ui64 >> 64)) >> 1)) >> 4;
  result->m_bool = ((1 << (v4 - 31 * v5)) & stream[v5 + 1 + *stream]) != 0;
  return result;
}

// File Line: 207
// RVA: 0xD11C70
__int64 __fastcall hkpConvexPieceMeshShape::getCollisionFilterInfo(hkpConvexPieceMeshShape *this, unsigned int key)
{
  __int64 v2; // r9
  unsigned int v3; // eax
  __int64 result; // rax

  v2 = *(_QWORD *)&this->m_type.m_storage;
  v3 = *(_DWORD *)(v2 + 40);
  if ( key >= v3 )
    result = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(*(_QWORD *)(this->m_userData + 32) + 32i64))(
               this->m_userData + 32,
               *(unsigned int *)(*(_QWORD *)(v2 + 48) + 4i64 * (signed int)(key - v3)));
  else
    result = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(*(_QWORD *)(this->m_userData + 32) + 32i64))(
               this->m_userData + 32,
               *(unsigned int *)(*(_QWORD *)(v2 + 16)
                               + 4i64 * *(unsigned int *)(*(_QWORD *)(v2 + 32) + 4i64 * (signed int)key)
                               + 4));
  return result;
}

// File Line: 230
// RVA: 0xD11CD0
void __fastcall hkpConvexPieceMeshShape::getAabb(hkpConvexPieceMeshShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  char *v4; // rdi
  hkAabb *v5; // rbx
  hkTransformf *v6; // rbp
  unsigned int i; // esi
  _QWORD *v8; // rax
  __m128 v9; // xmm1
  __m128 v10; // [rsp+20h] [rbp-238h]
  __m128 v11; // [rsp+30h] [rbp-228h]
  char v12; // [rsp+40h] [rbp-218h]

  v4 = (char *)&this->vfptr;
  v5 = out;
  v6 = localToWorld;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  for ( i = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 16i64))(v4);
        i != -1;
        i = (*(__int64 (__fastcall **)(char *, _QWORD))(*(_QWORD *)v4 + 24i64))(v4, i) )
  {
    v8 = (_QWORD *)(*(__int64 (__fastcall **)(char *, _QWORD, char *))(*(_QWORD *)v4 + 40i64))(v4, i, &v12);
    (*(void (__fastcall **)(_QWORD *, hkTransformf *, _QWORD, __m128 *))(*v8 + 32i64))(v8, v6, *v8, &v10);
    v9 = _mm_max_ps(v5->m_max.m_quad, v11);
    v5->m_min.m_quad = _mm_min_ps(v5->m_min.m_quad, v10);
    v5->m_max.m_quad = v9;
  }
}

// File Line: 265
// RVA: 0xD11DA0
void __fastcall hkpConvexPieceMeshShape::getStats(hkpConvexPieceMeshShape *this, hkpConvexPieceMeshShape::Stats *statsOut)
{
  int v2; // er11
  hkpConvexPieceMeshShape::Stats *v3; // r9
  int v4; // er8
  __int64 v5; // rbx
  signed int v6; // edx
  float v7; // xmm1_4

  v2 = 0;
  v3 = statsOut;
  statsOut->m_numTriangles += this->m_convexPieceStream->m_convexPieceSingleTriangles.m_size;
  statsOut->m_numConvexPieces += this->m_convexPieceStream->m_convexPieceSingleTriangles.m_size;
  if ( this->m_convexPieceStream->m_convexPieceOffsets.m_size > 0 )
  {
    v4 = statsOut->m_maxTrianglesPerConvexPiece;
    v5 = 0i64;
    do
    {
      ++v5;
      v6 = this->m_convexPieceStream->m_convexPieceStream.m_data[this->m_convexPieceStream->m_convexPieceOffsets.m_data[v5 - 1]];
      v3->m_numTriangles += v6;
      if ( v4 > v6 )
        v6 = v4;
      ++v2;
      v3->m_maxTrianglesPerConvexPiece = v6;
      v4 = v6;
    }
    while ( v2 < this->m_convexPieceStream->m_convexPieceOffsets.m_size );
  }
  v7 = (float)v3->m_numTriangles;
  v3->m_numConvexPieces += this->m_convexPieceStream->m_convexPieceOffsets.m_size;
  v3->m_avgNumTriangles = v7 / (float)v3->m_numConvexPieces;
}

