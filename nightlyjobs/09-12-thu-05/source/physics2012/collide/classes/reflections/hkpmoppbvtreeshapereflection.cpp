// File Line: 59
// RVA: 0x15C9AD0
void dynamic_initializer_for__hkMoppBvTreeShapeBaseClass__()
{
  hkClass::hkClass(
    &hkMoppBvTreeShapeBaseClass,
    "hkMoppBvTreeShapeBase",
    &hkpBvTreeShapeClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkMoppBvTreeShapeBaseClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xCEB0A0
hkClass *__fastcall hkMoppBvTreeShapeBase::staticClass()
{
  return &hkMoppBvTreeShapeBaseClass;
}

// File Line: 91
// RVA: 0x15C9B40
void dynamic_initializer_for__hkpMoppBvTreeShapeClass__()
{
  hkClass::hkClass(
    &hkpMoppBvTreeShapeClass,
    "hkpMoppBvTreeShape",
    &hkMoppBvTreeShapeBaseClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpMoppBvTreeShape::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 94
// RVA: 0xCEB0B0
hkClass *__fastcall hkpMoppBvTreeShape::staticClass()
{
  return &hkpMoppBvTreeShapeClass;
}

// File Line: 101
// RVA: 0xCEB0C0
void __fastcall finishLoadedObjecthkpMoppBvTreeShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpMoppBvTreeShape::hkpMoppBvTreeShape);
}

// File Line: 107
// RVA: 0xCEB0E0
void __fastcall cleanupLoadedObjecthkpMoppBvTreeShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 111
// RVA: 0xCEB0F0
hkBaseObjectVtbl *__fastcall getVtablehkpMoppBvTreeShape()
{
  hkpMoppBvTreeShape v1; // [rsp+20h] [rbp-78h]

  hkpMoppBvTreeShape::hkpMoppBvTreeShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 133
// RVA: 0x15C9BB0
hkBaseObjectVtbl *dynamic_initializer_for__hkpMoppBvTreeShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpMoppBvTreeShape();
  hkpMoppBvTreeShapeTypeInfo.m_size = 112i64;
  hkpMoppBvTreeShapeTypeInfo.m_typeName = "hkpMoppBvTreeShape";
  hkpMoppBvTreeShapeTypeInfo.m_vtable = result;
  hkpMoppBvTreeShapeTypeInfo.m_scopedName = "!hkpMoppBvTreeShape";
  hkpMoppBvTreeShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpMoppBvTreeShape;
  hkpMoppBvTreeShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpMoppBvTreeShape;
  return result;
}

