// File Line: 58
// RVA: 0x15CADB0
void dynamic_initializer_for__hkpTransformShapeClass__()
{
  hkClass::hkClass(
    &hkpTransformShapeClass,
    "hkpTransformShape",
    &hkpShapeClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpTransformShape::Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xCEBFE0
hkClass *__fastcall hkpTransformShape::staticClass()
{
  return &hkpTransformShapeClass;
}

// File Line: 68
// RVA: 0xCEBFF0
void __fastcall finishLoadedObjecthkpTransformShape(hkpTransformShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpTransformShape::hkpTransformShape(p, finishing);
}

// File Line: 74
// RVA: 0xCEC010
void __fastcall cleanupLoadedObjecthkpTransformShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 78
// RVA: 0xCEC020
hkBaseObjectVtbl *__fastcall getVtablehkpTransformShape()
{
  hkpTransformShape v1; // [rsp+20h] [rbp-98h] BYREF

  hkpTransformShape::hkpTransformShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 100
// RVA: 0x15CAE20
hkBaseObjectVtbl *dynamic_initializer_for__hkpTransformShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpTransformShape();
  hkpTransformShapeTypeInfo.m_size = 144i64;
  hkpTransformShapeTypeInfo.m_typeName = "hkpTransformShape";
  hkpTransformShapeTypeInfo.m_vtable = result;
  hkpTransformShapeTypeInfo.m_scopedName = "!hkpTransformShape";
  hkpTransformShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpTransformShape;
  hkpTransformShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpTransformShape;
  return result;
}

