// File Line: 61
// RVA: 0x15CBBB0
void dynamic_initializer_for__hkpPlaneShapeClass__()
{
  hkClass::hkClass(
    &hkpPlaneShapeClass,
    "hkpPlaneShape",
    &hkpHeightFieldShapeClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpPlaneShape::Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0xCEC850
hkClass *__fastcall hkpPlaneShape::staticClass()
{
  return &hkpPlaneShapeClass;
}

// File Line: 71
// RVA: 0xCEC860
void __fastcall finishLoadedObjecthkpPlaneShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpPlaneShape::hkpPlaneShape);
}

// File Line: 77
// RVA: 0xCEC880
void __fastcall cleanupLoadedObjecthkpPlaneShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 81
// RVA: 0xCEC890
hkBaseObjectVtbl *__fastcall getVtablehkpPlaneShape()
{
  hkpPlaneShape v1; // [rsp+20h] [rbp-58h]

  hkpPlaneShape::hkpPlaneShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 103
// RVA: 0x15CBC20
hkBaseObjectVtbl *dynamic_initializer_for__hkpPlaneShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpPlaneShape();
  hkpPlaneShapeTypeInfo.m_size = 80i64;
  hkpPlaneShapeTypeInfo.m_typeName = "hkpPlaneShape";
  hkpPlaneShapeTypeInfo.m_vtable = result;
  hkpPlaneShapeTypeInfo.m_scopedName = "!hkpPlaneShape";
  hkpPlaneShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpPlaneShape;
  hkpPlaneShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpPlaneShape;
  return result;
}

