// File Line: 61
// RVA: 0x15CC2F0
void dynamic_initializer_for__hkpStorageMeshShapeSubpartStorageClass__()
{
  hkClass::hkClass(
    &hkpStorageMeshShapeSubpartStorageClass,
    "hkpStorageMeshShapeSubpartStorage",
    &hkReferencedObjectClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpStorageMeshShape_SubpartStorageClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0xCECCC0
hkClass *__fastcall hkpStorageMeshShape::SubpartStorage::staticClass()
{
  return &hkpStorageMeshShapeSubpartStorageClass;
}

// File Line: 71
// RVA: 0xCECCD0
void __fastcall finishLoadedObjecthkpStorageMeshShapeSubpartStorage(
        hkpStorageMeshShape::SubpartStorage *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpStorageMeshShape::SubpartStorage::SubpartStorage(p, finishing);
}

// File Line: 77
// RVA: 0xCECCF0
void __fastcall cleanupLoadedObjecthkpStorageMeshShapeSubpartStorage(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 81
// RVA: 0xCECD00
hkBaseObjectVtbl *__fastcall getVtablehkpStorageMeshShapeSubpartStorage()
{
  hkpStorageMeshShape::SubpartStorage v1; // [rsp+20h] [rbp-78h] BYREF

  hkpStorageMeshShape::SubpartStorage::SubpartStorage(&v1, 0);
  return v1.vfptr;
}

// File Line: 103
// RVA: 0x15CC360
hkBaseObjectVtbl *dynamic_initializer_for__hkpStorageMeshShapeSubpartStorageTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpStorageMeshShapeSubpartStorage();
  hkpStorageMeshShapeSubpartStorageTypeInfo.m_size = 112i64;
  hkpStorageMeshShapeSubpartStorageTypeInfo.m_typeName = "hkpStorageMeshShapeSubpartStorage";
  hkpStorageMeshShapeSubpartStorageTypeInfo.m_vtable = result;
  hkpStorageMeshShapeSubpartStorageTypeInfo.m_scopedName = "!hkpStorageMeshShape::SubpartStorage";
  hkpStorageMeshShapeSubpartStorageTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpStorageMeshShapeSubpartStorage;
  hkpStorageMeshShapeSubpartStorageTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpStorageMeshShapeSubpartStorage;
  return result;
}

// File Line: 131
// RVA: 0x15CC280
void dynamic_initializer_for__hkpStorageMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpStorageMeshShapeClass,
    "hkpStorageMeshShape",
    &hkpMeshShapeClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpStorageMeshShape::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 134
// RVA: 0xCECCB0
hkClass *__fastcall hkpStorageMeshShape::staticClass()
{
  return &hkpStorageMeshShapeClass;
}

// File Line: 141
// RVA: 0xCECD30
void __fastcall finishLoadedObjecthkpStorageMeshShape(hkpStorageMeshShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpStorageMeshShape::hkpStorageMeshShape(p, finishing);
}

// File Line: 147
// RVA: 0xCECD50
void __fastcall cleanupLoadedObjecthkpStorageMeshShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 151
// RVA: 0xCECD60
hkBaseObjectVtbl *__fastcall getVtablehkpStorageMeshShape()
{
  hkpStorageMeshShape v1; // [rsp+20h] [rbp-98h] BYREF

  hkpStorageMeshShape::hkpStorageMeshShape(&v1, 0);
  return v1.hkpMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr;
}

// File Line: 173
// RVA: 0x15CC3C0
hkBaseObjectVtbl *dynamic_initializer_for__hkpStorageMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpStorageMeshShape();
  hkpStorageMeshShapeTypeInfo.m_size = 144i64;
  hkpStorageMeshShapeTypeInfo.m_typeName = "hkpStorageMeshShape";
  hkpStorageMeshShapeTypeInfo.m_vtable = result;
  hkpStorageMeshShapeTypeInfo.m_scopedName = "!hkpStorageMeshShape";
  hkpStorageMeshShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpStorageMeshShape;
  hkpStorageMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpStorageMeshShape;
  return result;
}

