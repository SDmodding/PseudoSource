// File Line: 56
// RVA: 0x15C97C0
void dynamic_initializer_for__hkpBvShapeClass__()
{
  hkClass::hkClass(
    &hkpBvShapeClass,
    "hkpBvShape",
    &hkpShapeClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkpBvShapeClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xCEAEE0
hkClass *__fastcall hkpBvShape::staticClass()
{
  return &hkpBvShapeClass;
}

// File Line: 66
// RVA: 0xCEAEF0
void __fastcall finishLoadedObjecthkpBvShape(hkpBvShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpBvShape::hkpBvShape(p, finishing);
}

// File Line: 72
// RVA: 0xCEAF10
void __fastcall cleanupLoadedObjecthkpBvShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 76
// RVA: 0xCEAF20
hkBaseObjectVtbl *__fastcall getVtablehkpBvShape()
{
  hkpBvShape v1; // [rsp+20h] [rbp-48h] BYREF

  hkpBvShape::hkpBvShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 98
// RVA: 0x15C9830
hkBaseObjectVtbl *dynamic_initializer_for__hkpBvShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpBvShape();
  hkpBvShapeTypeInfo.m_size = 56i64;
  hkpBvShapeTypeInfo.m_typeName = "hkpBvShape";
  hkpBvShapeTypeInfo.m_vtable = result;
  hkpBvShapeTypeInfo.m_scopedName = "!hkpBvShape";
  hkpBvShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpBvShape;
  hkpBvShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpBvShape;
  return result;
}

