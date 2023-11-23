// File Line: 52
// RVA: 0x15CA020
void dynamic_initializer_for__hkpConvexTranslateShapeClass__()
{
  hkClass::hkClass(
    &hkpConvexTranslateShapeClass,
    "hkpConvexTranslateShape",
    &hkpConvexTransformShapeBaseClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpConvexTranslateShape::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 55
// RVA: 0xCEB630
hkClass *__fastcall hkpConvexTranslateShape::staticClass()
{
  return &hkpConvexTranslateShapeClass;
}

// File Line: 62
// RVA: 0xCEB640
void __fastcall finishLoadedObjecthkpConvexTranslateShape(
        hkpConvexTranslateShape *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpConvexTranslateShape::hkpConvexTranslateShape(p, finishing);
}

// File Line: 68
// RVA: 0xCEB660
void __fastcall cleanupLoadedObjecthkpConvexTranslateShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xCEB670
hkBaseObjectVtbl *__fastcall getVtablehkpConvexTranslateShape()
{
  hkpConvexTranslateShape v1; // [rsp+20h] [rbp-58h] BYREF

  hkpConvexTranslateShape::hkpConvexTranslateShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 94
// RVA: 0x15CA090
hkBaseObjectVtbl *dynamic_initializer_for__hkpConvexTranslateShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpConvexTranslateShape();
  hkpConvexTranslateShapeTypeInfo.m_size = 80i64;
  hkpConvexTranslateShapeTypeInfo.m_typeName = "hkpConvexTranslateShape";
  hkpConvexTranslateShapeTypeInfo.m_vtable = result;
  hkpConvexTranslateShapeTypeInfo.m_scopedName = "!hkpConvexTranslateShape";
  hkpConvexTranslateShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpConvexTranslateShape;
  hkpConvexTranslateShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpConvexTranslateShape;
  return result;
}

