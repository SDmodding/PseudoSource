// File Line: 78
// RVA: 0x15C9F50
void dynamic_initializer_for__hkpConvexListShapeClass__()
{
  hkClass::hkClass(
    &hkpConvexListShapeClass,
    "hkpConvexListShape",
    &hkpConvexShapeClass,
    128,
    0i64,
    1,
    0i64,
    0,
    &hkpConvexListShape::Members,
    5,
    &hkpConvexListShape_Default,
    0i64,
    0,
    0);
}

// File Line: 81
// RVA: 0xCEB5D0
hkClass *__fastcall hkpConvexListShape::staticClass()
{
  return &hkpConvexListShapeClass;
}

// File Line: 88
// RVA: 0xCEB5E0
void __fastcall finishLoadedObjecthkpConvexListShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpConvexListShape::hkpConvexListShape);
}

// File Line: 94
// RVA: 0xCEB600
void __fastcall cleanupLoadedObjecthkpConvexListShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 98
// RVA: 0xCEB610
hkBaseObjectVtbl *__fastcall getVtablehkpConvexListShape()
{
  hkpConvexListShape v1; // [rsp+20h] [rbp-88h]

  hkpConvexListShape::hkpConvexListShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 120
// RVA: 0x15C9FC0
hkBaseObjectVtbl *dynamic_initializer_for__hkpConvexListShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpConvexListShape();
  hkpConvexListShapeTypeInfo.m_size = 128i64;
  hkpConvexListShapeTypeInfo.m_typeName = "hkpConvexListShape";
  hkpConvexListShapeTypeInfo.m_vtable = result;
  hkpConvexListShapeTypeInfo.m_scopedName = "!hkpConvexListShape";
  hkpConvexListShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConvexListShape;
  hkpConvexListShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConvexListShape;
  return result;
}

