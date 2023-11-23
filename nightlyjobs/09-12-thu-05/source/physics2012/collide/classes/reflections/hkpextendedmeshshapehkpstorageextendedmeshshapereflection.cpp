// File Line: 61
// RVA: 0x15CB810
void dynamic_initializer_for__hkpStorageExtendedMeshShapeMaterialClass__()
{
  hkClass::hkClass(
    &hkpStorageExtendedMeshShapeMaterialClass,
    "hkpStorageExtendedMeshShapeMaterial",
    &hkpMeshMaterialClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpStorageExtendedMeshShape_MaterialClass_Members,
    3,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 64
// RVA: 0xCEC580
hkClass *__fastcall hkpStorageExtendedMeshShape::Material::staticClass()
{
  return &hkpStorageExtendedMeshShapeMaterialClass;
}

// File Line: 71
// RVA: 0xCEC5B0
void __fastcall cleanupLoadedObjecthkpStorageExtendedMeshShapeMaterial(void *p)
{
  ;
}

// File Line: 115
// RVA: 0x15CB880
void dynamic_initializer_for__hkpStorageExtendedMeshShapeMeshSubpartStorageClass__()
{
  hkClass::hkClass(
    &hkpStorageExtendedMeshShapeMeshSubpartStorageClass,
    "hkpStorageExtendedMeshShapeMeshSubpartStorage",
    &hkReferencedObjectClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpStorageExtendedMeshShape_MeshSubpartStorageClass_Members,
    8,
    0i64,
    0i64,
    0,
    3);
}

// File Line: 118
// RVA: 0xCEC590
hkClass *__fastcall hkpStorageExtendedMeshShape::MeshSubpartStorage::staticClass()
{
  return &hkpStorageExtendedMeshShapeMeshSubpartStorageClass;
}

// File Line: 125
// RVA: 0xCEC5C0
void __fastcall finishLoadedObjecthkpStorageExtendedMeshShapeMeshSubpartStorage(
        hkpStorageExtendedMeshShape::MeshSubpartStorage *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpStorageExtendedMeshShape::MeshSubpartStorage::MeshSubpartStorage(p, finishing);
}

// File Line: 131
// RVA: 0xCEC5E0
void __fastcall cleanupLoadedObjecthkpStorageExtendedMeshShapeMeshSubpartStorage(
        void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 135
// RVA: 0xCEC5F0
hkBaseObjectVtbl *__fastcall getVtablehkpStorageExtendedMeshShapeMeshSubpartStorage()
{
  hkpStorageExtendedMeshShape::MeshSubpartStorage v1; // [rsp+20h] [rbp-98h] BYREF

  hkpStorageExtendedMeshShape::MeshSubpartStorage::MeshSubpartStorage(&v1, 0);
  return v1.vfptr;
}

// File Line: 157
// RVA: 0x15CB8F0
hkBaseObjectVtbl *dynamic_initializer_for__hkpStorageExtendedMeshShapeMeshSubpartStorageTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpStorageExtendedMeshShapeMeshSubpartStorage();
  hkpStorageExtendedMeshShapeMeshSubpartStorageTypeInfo.m_size = 144i64;
  hkpStorageExtendedMeshShapeMeshSubpartStorageTypeInfo.m_typeName = "hkpStorageExtendedMeshShapeMeshSubpartStorage";
  hkpStorageExtendedMeshShapeMeshSubpartStorageTypeInfo.m_vtable = result;
  hkpStorageExtendedMeshShapeMeshSubpartStorageTypeInfo.m_scopedName = "!hkpStorageExtendedMeshShape::MeshSubpartStorage";
  hkpStorageExtendedMeshShapeMeshSubpartStorageTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpStorageExtendedMeshShapeMeshSubpartStorage;
  hkpStorageExtendedMeshShapeMeshSubpartStorageTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpStorageExtendedMeshShapeMeshSubpartStorage;
  return result;
}

// File Line: 184
// RVA: 0x15CB950
void dynamic_initializer_for__hkpStorageExtendedMeshShapeShapeSubpartStorageClass__()
{
  hkClass::hkClass(
    &hkpStorageExtendedMeshShapeShapeSubpartStorageClass,
    "hkpStorageExtendedMeshShapeShapeSubpartStorage",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkpStorageExtendedMeshShape_ShapeSubpartStorageClass_Members,
    3,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 187
// RVA: 0xCEC5A0
hkClass *__fastcall hkpStorageExtendedMeshShape::ShapeSubpartStorage::staticClass()
{
  return &hkpStorageExtendedMeshShapeShapeSubpartStorageClass;
}

// File Line: 194
// RVA: 0xCEC620
void __fastcall finishLoadedObjecthkpStorageExtendedMeshShapeShapeSubpartStorage(
        hkpStorageExtendedMeshShape::ShapeSubpartStorage *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpStorageExtendedMeshShape::ShapeSubpartStorage::ShapeSubpartStorage(p, finishing);
}

// File Line: 200
// RVA: 0xCEC640
void __fastcall cleanupLoadedObjecthkpStorageExtendedMeshShapeShapeSubpartStorage(
        void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 204
// RVA: 0xCEC650
hkBaseObjectVtbl *__fastcall getVtablehkpStorageExtendedMeshShapeShapeSubpartStorage()
{
  hkpStorageExtendedMeshShape::ShapeSubpartStorage v1; // [rsp+20h] [rbp-48h] BYREF

  hkpStorageExtendedMeshShape::ShapeSubpartStorage::ShapeSubpartStorage(&v1, 0);
  return v1.vfptr;
}

// File Line: 226
// RVA: 0x15CB9C0
hkBaseObjectVtbl *dynamic_initializer_for__hkpStorageExtendedMeshShapeShapeSubpartStorageTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpStorageExtendedMeshShapeShapeSubpartStorage();
  hkpStorageExtendedMeshShapeShapeSubpartStorageTypeInfo.m_size = 64i64;
  hkpStorageExtendedMeshShapeShapeSubpartStorageTypeInfo.m_typeName = "hkpStorageExtendedMeshShapeShapeSubpartStorage";
  hkpStorageExtendedMeshShapeShapeSubpartStorageTypeInfo.m_vtable = result;
  hkpStorageExtendedMeshShapeShapeSubpartStorageTypeInfo.m_scopedName = "!hkpStorageExtendedMeshShape::ShapeSubpartStorage";
  hkpStorageExtendedMeshShapeShapeSubpartStorageTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpStorageExtendedMeshShapeShapeSubpartStorage;
  hkpStorageExtendedMeshShapeShapeSubpartStorageTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpStorageExtendedMeshShapeShapeSubpartStorage;
  return result;
}

// File Line: 255
// RVA: 0x15CB7A0
void dynamic_initializer_for__hkpStorageExtendedMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpStorageExtendedMeshShapeClass,
    "hkpStorageExtendedMeshShape",
    &hkpExtendedMeshShapeClass,
    352,
    0i64,
    0,
    0i64,
    0,
    &hkpStorageExtendedMeshShape::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 258
// RVA: 0xCEC570
hkClass *__fastcall hkpStorageExtendedMeshShape::staticClass()
{
  return &hkpStorageExtendedMeshShapeClass;
}

// File Line: 265
// RVA: 0xCEC670
void __fastcall finishLoadedObjecthkpStorageExtendedMeshShape(
        hkpStorageExtendedMeshShape *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape(p, finishing);
}

// File Line: 271
// RVA: 0xCEC690
void __fastcall cleanupLoadedObjecthkpStorageExtendedMeshShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 275
// RVA: 0xCEC6A0
hkBaseObjectVtbl *__fastcall getVtablehkpStorageExtendedMeshShape()
{
  hkpStorageExtendedMeshShape v1; // [rsp+20h] [rbp-168h] BYREF

  hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape(&v1, 0);
  return v1.hkpExtendedMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr;
}

// File Line: 297
// RVA: 0x15CBA20
hkBaseObjectVtbl *dynamic_initializer_for__hkpStorageExtendedMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpStorageExtendedMeshShape();
  hkpStorageExtendedMeshShapeTypeInfo.m_size = 352i64;
  hkpStorageExtendedMeshShapeTypeInfo.m_typeName = "hkpStorageExtendedMeshShape";
  hkpStorageExtendedMeshShapeTypeInfo.m_vtable = result;
  hkpStorageExtendedMeshShapeTypeInfo.m_scopedName = "!hkpStorageExtendedMeshShape";
  hkpStorageExtendedMeshShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpStorageExtendedMeshShape;
  hkpStorageExtendedMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpStorageExtendedMeshShape;
  return result;
}

