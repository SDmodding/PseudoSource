// File Line: 51
// RVA: 0x15CC040
void dynamic_initializer_for__hkpFastMeshShapeClass__()
{
  hkClass::hkClass(
    &hkpFastMeshShapeClass,
    "hkpFastMeshShape",
    &hkpMeshShapeClass,
    128,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 54
// RVA: 0xCECBD0
hkClass *__fastcall hkpFastMeshShape::staticClass()
{
  return &hkpFastMeshShapeClass;
}

// File Line: 61
// RVA: 0xCECBE0
void __fastcall finishLoadedObjecthkpFastMeshShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpFastMeshShape::hkpFastMeshShape);
}

// File Line: 67
// RVA: 0xCECC00
void __fastcall cleanupLoadedObjecthkpFastMeshShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 71
// RVA: 0xCECC10
hkBaseObjectVtbl *__fastcall getVtablehkpFastMeshShape()
{
  hkpFastMeshShape v1; // [rsp+20h] [rbp-88h]

  hkpFastMeshShape::hkpFastMeshShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 93
// RVA: 0x15CC0A0
hkBaseObjectVtbl *dynamic_initializer_for__hkpFastMeshShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpFastMeshShape();
  hkpFastMeshShapeTypeInfo.m_size = 128i64;
  hkpFastMeshShapeTypeInfo.m_typeName = "hkpFastMeshShape";
  hkpFastMeshShapeTypeInfo.m_vtable = result;
  hkpFastMeshShapeTypeInfo.m_scopedName = "!hkpFastMeshShape";
  hkpFastMeshShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpFastMeshShape;
  hkpFastMeshShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpFastMeshShape;
  return result;
}

