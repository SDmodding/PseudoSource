// File Line: 67
// RVA: 0x15C9CE0
void dynamic_initializer_for__hkpCapsuleShapeClass__()
{
  hkClass::hkClass(
    &hkpCapsuleShapeClass,
    "hkpCapsuleShape",
    &hkpConvexShapeClass,
    80,
    0i64,
    0,
    &hkpCapsuleShapeEnums,
    1,
    &hkpCapsuleShape::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 70
// RVA: 0xCEB340
hkClass *__fastcall hkpCapsuleShape::staticClass()
{
  return &hkpCapsuleShapeClass;
}

// File Line: 77
// RVA: 0xCEB350
void __fastcall finishLoadedObjecthkpCapsuleShape(hkpCapsuleShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpCapsuleShape::hkpCapsuleShape(p, finishing);
}

// File Line: 83
// RVA: 0xCEB370
void __fastcall cleanupLoadedObjecthkpCapsuleShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 87
// RVA: 0xCEB380
hkBaseObjectVtbl *__fastcall getVtablehkpCapsuleShape()
{
  hkpCapsuleShape v1; // [rsp+20h] [rbp-58h] BYREF

  hkpCapsuleShape::hkpCapsuleShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 109
// RVA: 0x15C9D50
hkBaseObjectVtbl *dynamic_initializer_for__hkpCapsuleShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpCapsuleShape();
  hkpCapsuleShapeTypeInfo.m_size = 80i64;
  hkpCapsuleShapeTypeInfo.m_typeName = "hkpCapsuleShape";
  hkpCapsuleShapeTypeInfo.m_vtable = result;
  hkpCapsuleShapeTypeInfo.m_scopedName = "!hkpCapsuleShape";
  hkpCapsuleShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpCapsuleShape;
  hkpCapsuleShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpCapsuleShape;
  return result;
}

