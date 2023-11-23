// File Line: 53
// RVA: 0x15C9DB0
void dynamic_initializer_for__hkpConvexTransformShapeClass__()
{
  hkClass::hkClass(
    &hkpConvexTransformShapeClass,
    "hkpConvexTransformShape",
    &hkpConvexTransformShapeBaseClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpConvexTransformShape::Members,
    2,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 56
// RVA: 0xCEB3A0
hkClass *__fastcall hkpConvexTransformShape::staticClass()
{
  return &hkpConvexTransformShapeClass;
}

// File Line: 63
// RVA: 0xCEB3B0
void __fastcall finishLoadedObjecthkpConvexTransformShape(
        hkpConvexTransformShape *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpConvexTransformShape::hkpConvexTransformShape(p, finishing);
}

// File Line: 69
// RVA: 0xCEB3D0
void __fastcall cleanupLoadedObjecthkpConvexTransformShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 73
// RVA: 0xCEB3E0
hkBaseObjectVtbl *__fastcall getVtablehkpConvexTransformShape()
{
  hkpConvexTransformShape v1; // [rsp+20h] [rbp-88h] BYREF

  hkpConvexTransformShape::hkpConvexTransformShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 95
// RVA: 0x15C9E20
hkBaseObjectVtbl *dynamic_initializer_for__hkpConvexTransformShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpConvexTransformShape();
  hkpConvexTransformShapeTypeInfo.m_size = 128i64;
  hkpConvexTransformShapeTypeInfo.m_typeName = "hkpConvexTransformShape";
  hkpConvexTransformShapeTypeInfo.m_vtable = result;
  hkpConvexTransformShapeTypeInfo.m_scopedName = "!hkpConvexTransformShape";
  hkpConvexTransformShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpConvexTransformShape;
  hkpConvexTransformShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpConvexTransformShape;
  return result;
}

