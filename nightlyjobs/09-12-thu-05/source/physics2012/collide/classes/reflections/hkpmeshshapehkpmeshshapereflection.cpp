// File Line: 74
// RVA: 0x15CC260
hkClassEnum *dynamic_initializer_for__hkpMeshShape_SubpartClass_Members__()
{
  hkClassEnum *result; // rax

  unk_14210D560 = hkpMeshShapeMeshShapeIndexStridingTypeEnum;
  result = hkpMeshShapeMeshShapeMaterialIndexStridingTypeEnum;
  unk_14210D588 = hkpMeshShapeMeshShapeMaterialIndexStridingTypeEnum;
  return result;
}

// File Line: 121
// RVA: 0x15CC190
void dynamic_initializer_for__hkpMeshShapeSubpartClass__()
{
  hkClass::hkClass(
    &hkpMeshShapeSubpartClass,
    "hkpMeshShapeSubpart",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpMeshShape_SubpartClass_Members,
    15,
    &hkpMeshShapeSubpart_Default,
    0i64,
    0,
    0);
}

// File Line: 124
// RVA: 0xCECC40
hkClass *__fastcall hkpMeshShape::Subpart::staticClass()
{
  return &hkpMeshShapeSubpartClass;
}

// File Line: 131
// RVA: 0xCECC50
void __fastcall cleanupLoadedObjecthkpMeshShapeSubpart(void *p)
{
  ;
}

// File Line: 157
// RVA: 0x15CC100
hkClassEnum *dynamic_initializer_for__hkpMeshShape::Members__()
{
  hkClassEnum *result; // rax

  result = hkpWeldingUtilityWeldingTypeEnum;
  unk_14210D440 = hkpWeldingUtilityWeldingTypeEnum;
  return result;
}

// File Line: 197
// RVA: 0x15CC110
void dynamic_initializer_for__hkpMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpMeshShapeClass,
    "hkpMeshShape",
    &hkpShapeCollectionClass,
    128,
    0i64,
    0,
    &hkpMeshShapeEnums,
    2,
    &hkpMeshShape::Members,
    7,
    &hkpMeshShape_Default,
    0i64,
    0,
    0);
}

// File Line: 200
// RVA: 0xCECC30
hkClass *__fastcall hkpMeshShape::staticClass()
{
  return &hkpMeshShapeClass;
}

// File Line: 207
// RVA: 0xCECC60
void __fastcall finishLoadedObjecthkpMeshShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpMeshShape::hkpMeshShape);
}

// File Line: 213
// RVA: 0xCECC80
void __fastcall cleanupLoadedObjecthkpMeshShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 217
// RVA: 0xCECC90
hkBaseObjectVtbl *__fastcall getVtablehkpMeshShape()
{
  hkpMeshShape v1; // [rsp+20h] [rbp-88h]

  hkpMeshShape::hkpMeshShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 239
// RVA: 0x15CC200
hkBaseObjectVtbl *dynamic_initializer_for__hkpMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpMeshShape();
  hkpMeshShapeTypeInfo.m_size = 128i64;
  hkpMeshShapeTypeInfo.m_typeName = "hkpMeshShape";
  hkpMeshShapeTypeInfo.m_vtable = result;
  hkpMeshShapeTypeInfo.m_scopedName = "!hkpMeshShape";
  hkpMeshShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpMeshShape;
  hkpMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpMeshShape;
  return result;
}

