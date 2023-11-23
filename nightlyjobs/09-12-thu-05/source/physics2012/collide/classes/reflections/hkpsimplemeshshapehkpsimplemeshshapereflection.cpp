// File Line: 77
// RVA: 0x15CC4A0
void dynamic_initializer_for__hkpSimpleMeshShapeTriangleClass__()
{
  hkClass::hkClass(
    &hkpSimpleMeshShapeTriangleClass,
    "hkpSimpleMeshShapeTriangle",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpSimpleMeshShape_TriangleClass_Members,
    4,
    &hkpSimpleMeshShapeTriangle_Default,
    0i64,
    0,
    0);
}

// File Line: 80
// RVA: 0xCECD90
hkClass *__fastcall hkpSimpleMeshShape::Triangle::staticClass()
{
  return &hkpSimpleMeshShapeTriangleClass;
}

// File Line: 87
// RVA: 0xCECDA0
void __fastcall cleanupLoadedObjecthkpSimpleMeshShapeTriangle(void *p)
{
  ;
}

// File Line: 113
// RVA: 0x15CC490
hkClassEnum *dynamic_initializer_for__hkpSimpleMeshShapeClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpWeldingUtilityWeldingTypeEnum;
  unk_14210D820 = hkpWeldingUtilityWeldingTypeEnum;
  return result;
}

// File Line: 151
// RVA: 0x15CC420
void dynamic_initializer_for__hkpSimpleMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpSimpleMeshShapeClass,
    "hkpSimpleMeshShape",
    &hkpShapeCollectionClass,
    104,
    0i64,
    0,
    0i64,
    0,
    &hkpSimpleMeshShapeClass_Members,
    5,
    &hkpSimpleMeshShape_Default,
    0i64,
    0,
    0);
}

// File Line: 154
// RVA: 0xCECD80
hkClass *__fastcall hkpSimpleMeshShape::staticClass()
{
  return &hkpSimpleMeshShapeClass;
}

// File Line: 161
// RVA: 0xCECDB0
void __fastcall finishLoadedObjecthkpSimpleMeshShape(hkpSimpleMeshShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpSimpleMeshShape::hkpSimpleMeshShape(p, finishing);
}

// File Line: 167
// RVA: 0xCECDD0
void __fastcall cleanupLoadedObjecthkpSimpleMeshShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 171
// RVA: 0xCECDE0
hkBaseObjectVtbl *__fastcall getVtablehkpSimpleMeshShape()
{
  hkpSimpleMeshShape v1; // [rsp+20h] [rbp-78h] BYREF

  hkpSimpleMeshShape::hkpSimpleMeshShape(&v1, 0);
  return v1.hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr;
}

// File Line: 193
// RVA: 0x15CC510
hkBaseObjectVtbl *dynamic_initializer_for__hkpSimpleMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpSimpleMeshShape();
  hkpSimpleMeshShapeTypeInfo.m_size = 104i64;
  hkpSimpleMeshShapeTypeInfo.m_typeName = "hkpSimpleMeshShape";
  hkpSimpleMeshShapeTypeInfo.m_vtable = result;
  hkpSimpleMeshShapeTypeInfo.m_scopedName = "!hkpSimpleMeshShape";
  hkpSimpleMeshShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSimpleMeshShape;
  hkpSimpleMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSimpleMeshShape;
  return result;
}

