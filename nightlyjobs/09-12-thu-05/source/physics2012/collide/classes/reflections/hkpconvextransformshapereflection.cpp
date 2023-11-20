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
    2u);
}

// File Line: 56
// RVA: 0xCEB3A0
hkClass *__fastcall hkpConvexTransformShape::staticClass()
{
  return &hkpConvexTransformShapeClass;
}

// File Line: 63
// RVA: 0xCEB3B0
void __fastcall finishLoadedObjecthkpConvexTransformShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpConvexTransformShape::hkpConvexTransformShape);
}

// File Line: 69
// RVA: 0xCEB3D0
void __fastcall cleanupLoadedObjecthkpConvexTransformShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 73
// RVA: 0xCEB3E0
hkBaseObjectVtbl *__fastcall getVtablehkpConvexTransformShape()
{
  hkpConvexTransformShape v1; // [rsp+20h] [rbp-88h]

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
  hkpConvexTransformShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConvexTransformShape;
  hkpConvexTransformShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConvexTransformShape;
  return result;
}

