// File Line: 141
// RVA: 0x15CB650
void dynamic_initializer_for__hkpExtendedMeshShapeSubpartClass__()
{
  hkClass::hkClass(
    &hkpExtendedMeshShapeSubpartClass,
    "hkpExtendedMeshShapeSubpart",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpExtendedMeshShape::Subpart::Members,
    7,
    &hkpExtendedMeshShapeSubpart_Default,
    0i64,
    0,
    3u);
}

// File Line: 144
// RVA: 0xCEC480
hkClass *__fastcall hkpExtendedMeshShape::Subpart::staticClass()
{
  return &hkpExtendedMeshShapeSubpartClass;
}

// File Line: 151
// RVA: 0xCEC4B0
void __fastcall finishLoadedObjecthkpExtendedMeshShapeSubpart(void *p, int finishing)
{
  ;
}

// File Line: 157
// RVA: 0xCEC4C0
void __fastcall cleanupLoadedObjecthkpExtendedMeshShapeSubpart(void *p)
{
  ;
}

// File Line: 184
// RVA: 0x15CB790
hkClassEnum *dynamic_initializer_for__hkpExtendedMeshShape_TrianglesSubpartClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpExtendedMeshShapeIndexStridingTypeEnum;
  unk_14210CF38 = hkpExtendedMeshShapeIndexStridingTypeEnum;
  return result;
}

// File Line: 224
// RVA: 0x15CB6C0
void dynamic_initializer_for__hkpExtendedMeshShapeTrianglesSubpartClass__()
{
  hkClass::hkClass(
    &hkpExtendedMeshShapeTrianglesSubpartClass,
    "hkpExtendedMeshShapeTrianglesSubpart",
    &hkpExtendedMeshShapeSubpartClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpExtendedMeshShape_TrianglesSubpartClass_Members,
    11,
    &hkpExtendedMeshShapeTrianglesSubpart_Default,
    0i64,
    0,
    3u);
}

// File Line: 227
// RVA: 0xCEC490
hkClass *__fastcall hkpExtendedMeshShape::TrianglesSubpart::staticClass()
{
  return &hkpExtendedMeshShapeTrianglesSubpartClass;
}

// File Line: 234
// RVA: 0xCEC4D0
void __fastcall finishLoadedObjecthkpExtendedMeshShapeTrianglesSubpart(void *p, int finishing)
{
  ;
}

// File Line: 240
// RVA: 0xCEC4E0
void __fastcall cleanupLoadedObjecthkpExtendedMeshShapeTrianglesSubpart(void *p)
{
  ;
}

// File Line: 278
// RVA: 0x15CB5E0
void dynamic_initializer_for__hkpExtendedMeshShapeShapesSubpartClass__()
{
  hkClass::hkClass(
    &hkpExtendedMeshShapeShapesSubpartClass,
    "hkpExtendedMeshShapeShapesSubpart",
    &hkpExtendedMeshShapeSubpartClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpExtendedMeshShape::ShapesSubpart::Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 281
// RVA: 0xCEC4A0
hkClass *__fastcall hkpExtendedMeshShape::ShapesSubpart::staticClass()
{
  return &hkpExtendedMeshShapeShapesSubpartClass;
}

// File Line: 288
// RVA: 0xCEC4F0
void __fastcall finishLoadedObjecthkpExtendedMeshShapeShapesSubpart(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart);
}

// File Line: 294
// RVA: 0xCEC510
void __fastcall cleanupLoadedObjecthkpExtendedMeshShapeShapesSubpart(void *p)
{
  hkpExtendedMeshShape::ShapesSubpart::~ShapesSubpart((hkpExtendedMeshShape::ShapesSubpart *)p);
}

// File Line: 324
// RVA: 0x15CB550
hkClassEnum *dynamic_initializer_for__hkpExtendedMeshShape::Members__()
{
  hkClassEnum *result; // rax

  result = hkpWeldingUtilityWeldingTypeEnum;
  unk_14210CD20 = hkpWeldingUtilityWeldingTypeEnum;
  return result;
}

// File Line: 367
// RVA: 0x15CB560
void dynamic_initializer_for__hkpExtendedMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpExtendedMeshShapeClass,
    "hkpExtendedMeshShape",
    &hkpShapeCollectionClass,
    320,
    0i64,
    0,
    &hkpExtendedMeshShapeEnums,
    4,
    &hkpExtendedMeshShape::Members,
    13,
    &hkpExtendedMeshShape_Default,
    0i64,
    0,
    4u);
}

// File Line: 370
// RVA: 0xCEC470
hkClass *__fastcall hkpExtendedMeshShape::staticClass()
{
  return &hkpExtendedMeshShapeClass;
}

// File Line: 377
// RVA: 0xCEC520
void __fastcall finishLoadedObjecthkpExtendedMeshShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpExtendedMeshShape::hkpExtendedMeshShape);
}

// File Line: 383
// RVA: 0xCEC540
void __fastcall cleanupLoadedObjecthkpExtendedMeshShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 387
// RVA: 0xCEC550
hkBaseObjectVtbl *__fastcall getVtablehkpExtendedMeshShape()
{
  hkpExtendedMeshShape v1; // [rsp+20h] [rbp-148h]

  hkpExtendedMeshShape::hkpExtendedMeshShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 409
// RVA: 0x15CB730
hkBaseObjectVtbl *dynamic_initializer_for__hkpExtendedMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpExtendedMeshShape();
  hkpExtendedMeshShapeTypeInfo.m_size = 320i64;
  hkpExtendedMeshShapeTypeInfo.m_typeName = "hkpExtendedMeshShape";
  hkpExtendedMeshShapeTypeInfo.m_vtable = result;
  hkpExtendedMeshShapeTypeInfo.m_scopedName = "!hkpExtendedMeshShape";
  hkpExtendedMeshShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpExtendedMeshShape;
  hkpExtendedMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpExtendedMeshShape;
  return result;
}

