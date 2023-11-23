// File Line: 52
// RVA: 0x15CA890
void dynamic_initializer_for__hkpShapeClass__()
{
  hkClass::hkClass(
    &hkpShapeClass,
    "hkpShape",
    &hkpShapeBaseClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpShapeClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 55
// RVA: 0xCEBC50
hkClass *__fastcall hkpShape::staticClass()
{
  return &hkpShapeClass;
}

// File Line: 62
// RVA: 0xCEBC60
void __fastcall finishLoadedObjecthkpShape(hkpShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpShape::hkpShape(p, finishing);
}

// File Line: 68
// RVA: 0xCEBC80
void __fastcall cleanupLoadedObjecthkpShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xCEBC90
hkBaseObjectVtbl *__fastcall getVtablehkpShape()
{
  hkpShape v1; // [rsp+20h] [rbp-28h] BYREF

  hkpShape::hkpShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 94
// RVA: 0x15CA900
hkBaseObjectVtbl *dynamic_initializer_for__hkpShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpShape();
  hkpShapeTypeInfo.m_size = 32i64;
  hkpShapeTypeInfo.m_typeName = "hkpShape";
  hkpShapeTypeInfo.m_vtable = result;
  hkpShapeTypeInfo.m_scopedName = "!hkpShape";
  hkpShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpShape;
  hkpShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpShape;
  return result;
}

