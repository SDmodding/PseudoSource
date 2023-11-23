// File Line: 81
// RVA: 0x15D24C0
hkClassEnum *dynamic_initializer_for__hkpBvCompressedMeshShape::Members__()
{
  hkClassEnum *result; // rax

  result = hkpWeldingUtilityWeldingTypeEnum;
  unk_142112848 = hkpWeldingUtilityWeldingTypeEnum;
  return result;
}

// File Line: 125
// RVA: 0x15D24D0
void dynamic_initializer_for__hkpBvCompressedMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpBvCompressedMeshShapeClass,
    "hkpBvCompressedMeshShape",
    &hkpBvTreeShapeClass,
    272,
    0i64,
    1,
    &hkpBvCompressedMeshShapeEnums,
    3,
    &hkpBvCompressedMeshShape::Members,
    8,
    &hkpBvCompressedMeshShape_Default,
    0i64,
    0,
    2);
}

// File Line: 128
// RVA: 0xD99020
hkClass *__fastcall hkpBvCompressedMeshShape::staticClass()
{
  return &hkpBvCompressedMeshShapeClass;
}

// File Line: 135
// RVA: 0xD99030
void __fastcall finishLoadedObjecthkpBvCompressedMeshShape(
        hkpBvCompressedMeshShape *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpBvCompressedMeshShape::hkpBvCompressedMeshShape(p, finishing);
}

// File Line: 141
// RVA: 0xD99050
void __fastcall cleanupLoadedObjecthkpBvCompressedMeshShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 145
// RVA: 0xD99060
hkBaseObjectVtbl *__fastcall getVtablehkpBvCompressedMeshShape()
{
  hkpBvCompressedMeshShape v1; // [rsp+20h] [rbp-118h] BYREF

  hkpBvCompressedMeshShape::hkpBvCompressedMeshShape(&v1, 0);
  return v1.hkpBvTreeShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr;
}

// File Line: 167
// RVA: 0x15D2550
hkBaseObjectVtbl *dynamic_initializer_for__hkpBvCompressedMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpBvCompressedMeshShape();
  hkpBvCompressedMeshShapeTypeInfo.m_size = 272i64;
  hkpBvCompressedMeshShapeTypeInfo.m_typeName = "hkpBvCompressedMeshShape";
  hkpBvCompressedMeshShapeTypeInfo.m_vtable = result;
  hkpBvCompressedMeshShapeTypeInfo.m_scopedName = "!hkpBvCompressedMeshShape";
  hkpBvCompressedMeshShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpBvCompressedMeshShape;
  hkpBvCompressedMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpBvCompressedMeshShape;
  return result;
}

