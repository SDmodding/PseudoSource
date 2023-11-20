// File Line: 69
// RVA: 0x15C6680
void dynamic_initializer_for__hkGeometryTriangleClass__()
{
  hkClass::hkClass(
    &hkGeometryTriangleClass,
    "hkGeometryTriangle",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkGeometry_TriangleClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 72
// RVA: 0xC54DC0
hkClass *__fastcall hkGeometry::Triangle::staticClass()
{
  return &hkGeometryTriangleClass;
}

// File Line: 79
// RVA: 0xC54DD0
void __fastcall cleanupLoadedObjecthkGeometryTriangle(void *p)
{
  ;
}

// File Line: 118
// RVA: 0x15C6610
void dynamic_initializer_for__hkGeometryClass__()
{
  hkClass::hkClass(
    &hkGeometryClass,
    "hkGeometry",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    &hkGeometryEnums,
    1,
    &hkGeometryClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 121
// RVA: 0xC54DB0
hkClass *__fastcall hkGeometry::staticClass()
{
  return &hkGeometryClass;
}

// File Line: 128
// RVA: 0xC54DE0
void __fastcall finishLoadedObjecthkGeometry(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkGeometry::hkGeometry);
}

// File Line: 134
// RVA: 0xC54E00
void __fastcall cleanupLoadedObjecthkGeometry(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 138
// RVA: 0xC54E10
hkBaseObjectVtbl *__fastcall getVtablehkGeometry()
{
  hkGeometry v1; // [rsp+20h] [rbp-38h]

  hkGeometry::hkGeometry(&v1, 0);
  return v1.vfptr;
}

// File Line: 160
// RVA: 0x15C66E0
hkBaseObjectVtbl *dynamic_initializer_for__hkGeometryTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkGeometry();
  hkGeometryTypeInfo.m_size = 48i64;
  hkGeometryTypeInfo.m_typeName = "hkGeometry";
  hkGeometryTypeInfo.m_vtable = result;
  hkGeometryTypeInfo.m_scopedName = "!hkGeometry";
  hkGeometryTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkGeometry;
  hkGeometryTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkGeometry;
  return result;
}

