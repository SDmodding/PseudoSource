// File Line: 58
// RVA: 0x15CB480
void dynamic_initializer_for__hkpConvexPieceMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpConvexPieceMeshShapeClass,
    "hkpConvexPieceMeshShape",
    &hkpShapeCollectionClass,
    72,
    0i64,
    0,
    0i64,
    0,
    &hkpConvexPieceMeshShape::Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xCEC410
hkClass *__fastcall hkpConvexPieceMeshShape::staticClass()
{
  return &hkpConvexPieceMeshShapeClass;
}

// File Line: 68
// RVA: 0xCEC420
void __fastcall finishLoadedObjecthkpConvexPieceMeshShape(
        hkpConvexPieceMeshShape *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpConvexPieceMeshShape::hkpConvexPieceMeshShape(p, finishing);
}

// File Line: 74
// RVA: 0xCEC440
void __fastcall cleanupLoadedObjecthkpConvexPieceMeshShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 78
// RVA: 0xCEC450
hkBaseObjectVtbl *__fastcall getVtablehkpConvexPieceMeshShape()
{
  hkpConvexPieceMeshShape v1; // [rsp+20h] [rbp-58h] BYREF

  hkpConvexPieceMeshShape::hkpConvexPieceMeshShape(&v1, 0);
  return v1.hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr;
}

// File Line: 100
// RVA: 0x15CB4F0
hkBaseObjectVtbl *dynamic_initializer_for__hkpConvexPieceMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpConvexPieceMeshShape();
  hkpConvexPieceMeshShapeTypeInfo.m_size = 72i64;
  hkpConvexPieceMeshShapeTypeInfo.m_typeName = "hkpConvexPieceMeshShape";
  hkpConvexPieceMeshShapeTypeInfo.m_vtable = result;
  hkpConvexPieceMeshShapeTypeInfo.m_scopedName = "!hkpConvexPieceMeshShape";
  hkpConvexPieceMeshShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpConvexPieceMeshShape;
  hkpConvexPieceMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpConvexPieceMeshShape;
  return result;
}

