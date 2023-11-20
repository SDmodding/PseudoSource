// File Line: 84
// RVA: 0x15CB2A0
void dynamic_initializer_for__hkpCompressedMeshShapeChunkClass__()
{
  hkClass::hkClass(
    &hkpCompressedMeshShapeChunkClass,
    "hkpCompressedMeshShapeChunk",
    0i64,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpCompressedMeshShape_ChunkClass_Members,
    8,
    0i64,
    0i64,
    0,
    4u);
}

// File Line: 87
// RVA: 0xCEC1E0
hkClass *__fastcall hkpCompressedMeshShape::Chunk::staticClass()
{
  return &hkpCompressedMeshShapeChunkClass;
}

// File Line: 94
// RVA: 0xCEC210
void __fastcall finishLoadedObjecthkpCompressedMeshShapeChunk(void *p, int finishing)
{
  ;
}

// File Line: 100
// RVA: 0xCEC220
void __fastcall cleanupLoadedObjecthkpCompressedMeshShapeChunk(void *p)
{
  hkpCompressedMeshShape::Chunk::~Chunk((hkpCompressedMeshShape::Chunk *)p);
}

// File Line: 160
// RVA: 0x15CB230
void dynamic_initializer_for__hkpCompressedMeshShapeBigTriangleClass__()
{
  hkClass::hkClass(
    &hkpCompressedMeshShapeBigTriangleClass,
    "hkpCompressedMeshShapeBigTriangle",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpCompressedMeshShape_BigTriangleClass_Members,
    6,
    &hkpCompressedMeshShapeBigTriangle_Default,
    0i64,
    0,
    2u);
}

// File Line: 163
// RVA: 0xCEC1F0
hkClass *__fastcall hkpCompressedMeshShape::BigTriangle::staticClass()
{
  return &hkpCompressedMeshShapeBigTriangleClass;
}

// File Line: 170
// RVA: 0xCEC230
void __fastcall cleanupLoadedObjecthkpCompressedMeshShapeBigTriangle(void *p)
{
  ;
}

// File Line: 208
// RVA: 0x15CB3B0
void dynamic_initializer_for__hkpCompressedMeshShapeConvexPieceClass__()
{
  hkClass::hkClass(
    &hkpCompressedMeshShapeConvexPieceClass,
    "hkpCompressedMeshShapeConvexPiece",
    0i64,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpCompressedMeshShape_ConvexPieceClass_Members,
    4,
    0i64,
    0i64,
    0,
    4u);
}

// File Line: 211
// RVA: 0xCEC200
hkClass *__fastcall hkpCompressedMeshShape::ConvexPiece::staticClass()
{
  return &hkpCompressedMeshShapeConvexPieceClass;
}

// File Line: 218
// RVA: 0xCEC240
void __fastcall finishLoadedObjecthkpCompressedMeshShapeConvexPiece(void *p, int finishing)
{
  ;
}

// File Line: 224
// RVA: 0xCEC250
void __fastcall cleanupLoadedObjecthkpCompressedMeshShapeConvexPiece(void *p)
{
  int v1; // er8
  _QWORD *v2; // rbx

  v1 = *((_DWORD *)p + 7);
  v2 = p;
  *((_DWORD *)p + 6) = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 2) = 0i64;
    *((_DWORD *)p + 7) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 2),
      2 * (v1 & 0x3FFFFFFF));
    v2[2] = 0i64;
    *((_DWORD *)v2 + 7) = 2147483648;
  }
}

// File Line: 251
// RVA: 0x15CB390
hkClassEnum *dynamic_initializer_for__hkpCompressedMeshShapeClass_Members__()
{
  hkClassEnum *result; // rax

  unk_14210C918 = hkpWeldingUtilityWeldingTypeEnum;
  result = hkpCompressedMeshShapeMaterialTypeEnum;
  unk_14210C940 = hkpCompressedMeshShapeMaterialTypeEnum;
  return result;
}

// File Line: 305
// RVA: 0x15CB310
void dynamic_initializer_for__hkpCompressedMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpCompressedMeshShapeClass,
    "hkpCompressedMeshShape",
    &hkpShapeCollectionClass,
    288,
    0i64,
    0,
    &hkpCompressedMeshShapeEnums,
    1,
    &hkpCompressedMeshShapeClass_Members,
    22,
    &hkpCompressedMeshShape_Default,
    0i64,
    0,
    0xBu);
}

// File Line: 308
// RVA: 0xCEC1D0
hkClass *__fastcall hkpCompressedMeshShape::staticClass()
{
  return &hkpCompressedMeshShapeClass;
}

// File Line: 315
// RVA: 0xCEC2C0
void __fastcall finishLoadedObjecthkpCompressedMeshShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpCompressedMeshShape::hkpCompressedMeshShape);
}

// File Line: 321
// RVA: 0xCEC2E0
void __fastcall cleanupLoadedObjecthkpCompressedMeshShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 325
// RVA: 0xCEC2F0
hkBaseObjectVtbl *__fastcall getVtablehkpCompressedMeshShape()
{
  hkpCompressedMeshShape v1; // [rsp+20h] [rbp-128h]

  hkpCompressedMeshShape::hkpCompressedMeshShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 347
// RVA: 0x15CB420
hkBaseObjectVtbl *dynamic_initializer_for__hkpCompressedMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpCompressedMeshShape();
  hkpCompressedMeshShapeTypeInfo.m_size = 288i64;
  hkpCompressedMeshShapeTypeInfo.m_typeName = "hkpCompressedMeshShape";
  hkpCompressedMeshShapeTypeInfo.m_vtable = result;
  hkpCompressedMeshShapeTypeInfo.m_scopedName = "!hkpCompressedMeshShape";
  hkpCompressedMeshShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpCompressedMeshShape;
  hkpCompressedMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpCompressedMeshShape;
  return result;
}

