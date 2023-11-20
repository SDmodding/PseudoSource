// File Line: 52
// RVA: 0x15C9C10
void dynamic_initializer_for__hkpBoxShapeClass__()
{
  hkClass::hkClass(
    &hkpBoxShapeClass,
    "hkpBoxShape",
    &hkpConvexShapeClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkpBoxShape::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 55
// RVA: 0xCEB2E0
hkClass *__fastcall hkpBoxShape::staticClass()
{
  return &hkpBoxShapeClass;
}

// File Line: 62
// RVA: 0xCEB2F0
void __fastcall finishLoadedObjecthkpBoxShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpBoxShape::hkpBoxShape);
}

// File Line: 68
// RVA: 0xCEB310
void __fastcall cleanupLoadedObjecthkpBoxShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 72
// RVA: 0xCEB320
hkBaseObjectVtbl *__fastcall getVtablehkpBoxShape()
{
  hkpBoxShape v1; // [rsp+20h] [rbp-48h]

  hkpBoxShape::hkpBoxShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 94
// RVA: 0x15C9C80
hkBaseObjectVtbl *dynamic_initializer_for__hkpBoxShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpBoxShape();
  hkpBoxShapeTypeInfo.m_size = 64i64;
  hkpBoxShapeTypeInfo.m_typeName = "hkpBoxShape";
  hkpBoxShapeTypeInfo.m_vtable = result;
  hkpBoxShapeTypeInfo.m_scopedName = "!hkpBoxShape";
  hkpBoxShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpBoxShape;
  hkpBoxShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpBoxShape;
  return result;
}

