// File Line: 57
// RVA: 0x15D0900
void dynamic_initializer_for__hkpBreakableShapeClass__()
{
  hkClass::hkClass(
    &hkpBreakableShapeClass,
    "hkpBreakableShape",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpBreakableShape::Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 60
// RVA: 0xD50180
hkClass *__fastcall hkpBreakableShape::staticClass()
{
  return &hkpBreakableShapeClass;
}

// File Line: 67
// RVA: 0xD50190
void __fastcall finishLoadedObjecthkpBreakableShape(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpBreakableShape::`vftable;
}

// File Line: 73
// RVA: 0xD501B0
void __fastcall cleanupLoadedObjecthkpBreakableShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 77
// RVA: 0xD501C0
void **__fastcall getVtablehkpBreakableShape()
{
  return &hkpBreakableShape::`vftable;
}

// File Line: 99
// RVA: 0x15D0970
void **dynamic_initializer_for__hkpBreakableShapeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpBreakableShape();
  hkpBreakableShapeTypeInfo.m_size = 32i64;
  hkpBreakableShapeTypeInfo.m_typeName = "hkpBreakableShape";
  hkpBreakableShapeTypeInfo.m_vtable = result;
  hkpBreakableShapeTypeInfo.m_scopedName = "!hkpBreakableShape";
  hkpBreakableShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpBreakableShape;
  hkpBreakableShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpBreakableShape;
  return result;
}

