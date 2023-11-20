// File Line: 83
// RVA: 0x15CA290
void dynamic_initializer_for__hkpConvexVerticesShapeClass__()
{
  hkClass::hkClass(
    &hkpConvexVerticesShapeClass,
    "hkpConvexVerticesShape",
    &hkpConvexShapeClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpConvexVerticesShapeClass_Members,
    7,
    &hkpConvexVerticesShape_Default,
    0i64,
    0,
    6u);
}

// File Line: 86
// RVA: 0xCEB8E0
hkClass *__fastcall hkpConvexVerticesShape::staticClass()
{
  return &hkpConvexVerticesShapeClass;
}

// File Line: 93
// RVA: 0xCEB8F0
void __fastcall finishLoadedObjecthkpConvexVerticesShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpConvexVerticesShape::hkpConvexVerticesShape);
}

// File Line: 99
// RVA: 0xCEB910
void __fastcall cleanupLoadedObjecthkpConvexVerticesShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 103
// RVA: 0xCEB920
hkBaseObjectVtbl *__fastcall getVtablehkpConvexVerticesShape()
{
  hkpConvexVerticesShape v1; // [rsp+20h] [rbp-88h]

  hkpConvexVerticesShape::hkpConvexVerticesShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 125
// RVA: 0x15CA300
hkBaseObjectVtbl *dynamic_initializer_for__hkpConvexVerticesShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpConvexVerticesShape();
  hkpConvexVerticesShapeTypeInfo.m_size = 128i64;
  hkpConvexVerticesShapeTypeInfo.m_typeName = "hkpConvexVerticesShape";
  hkpConvexVerticesShapeTypeInfo.m_vtable = result;
  hkpConvexVerticesShapeTypeInfo.m_scopedName = "!hkpConvexVerticesShape";
  hkpConvexVerticesShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConvexVerticesShape;
  hkpConvexVerticesShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConvexVerticesShape;
  return result;
}

