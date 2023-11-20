// File Line: 94
// RVA: 0x15CA360
void dynamic_initializer_for__hkpCylinderShapeClass__()
{
  hkClass::hkClass(
    &hkpCylinderShapeClass,
    "hkpCylinderShape",
    &hkpConvexShapeClass,
    112,
    0i64,
    0,
    &hkpCylinderShapeEnums,
    1,
    &hkpCylinderShape::Members,
    6,
    &hkpCylinderShape_Default,
    0i64,
    0,
    0);
}

// File Line: 97
// RVA: 0xCEB940
hkClass *__fastcall hkpCylinderShape::staticClass()
{
  return &hkpCylinderShapeClass;
}

// File Line: 104
// RVA: 0xCEB950
void __fastcall finishLoadedObjecthkpCylinderShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpCylinderShape::hkpCylinderShape);
}

// File Line: 110
// RVA: 0xCEB970
void __fastcall cleanupLoadedObjecthkpCylinderShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 114
// RVA: 0xCEB980
hkBaseObjectVtbl *__fastcall getVtablehkpCylinderShape()
{
  hkpCylinderShape v1; // [rsp+20h] [rbp-78h]

  hkpCylinderShape::hkpCylinderShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 136
// RVA: 0x15CA3E0
hkBaseObjectVtbl *dynamic_initializer_for__hkpCylinderShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpCylinderShape();
  hkpCylinderShapeTypeInfo.m_size = 112i64;
  hkpCylinderShapeTypeInfo.m_typeName = "hkpCylinderShape";
  hkpCylinderShapeTypeInfo.m_vtable = result;
  hkpCylinderShapeTypeInfo.m_scopedName = "!hkpCylinderShape";
  hkpCylinderShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpCylinderShape;
  hkpCylinderShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpCylinderShape;
  return result;
}

