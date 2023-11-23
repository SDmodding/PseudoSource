// File Line: 39
// RVA: 0x15CAE80
hkClassEnum *dynamic_initializer_for__hkpTriangleShape::Members__()
{
  hkClassEnum *result; // rax

  result = hkpWeldingUtilityWeldingTypeEnum;
  unk_14210C558 = hkpWeldingUtilityWeldingTypeEnum;
  return result;
}

// File Line: 82
// RVA: 0x15CAE90
void dynamic_initializer_for__hkpTriangleShapeClass__()
{
  hkClass::hkClass(
    &hkpTriangleShapeClass,
    "hkpTriangleShape",
    &hkpConvexShapeClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpTriangleShape::Members,
    7,
    &hkpTriangleShape_Default,
    0i64,
    0,
    0);
}

// File Line: 85
// RVA: 0xCEC040
hkClass *__fastcall hkpTriangleShape::staticClass()
{
  return &hkpTriangleShapeClass;
}

// File Line: 92
// RVA: 0xCEC050
void __fastcall finishLoadedObjecthkpTriangleShape(hkpTriangleShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpTriangleShape::hkpTriangleShape(p, finishing);
}

// File Line: 98
// RVA: 0xCEC070
void __fastcall cleanupLoadedObjecthkpTriangleShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 102
// RVA: 0xCEC080
hkBaseObjectVtbl *__fastcall getVtablehkpTriangleShape()
{
  hkpTriangleShape v1; // [rsp+20h] [rbp-78h] BYREF

  hkpTriangleShape::hkpTriangleShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 124
// RVA: 0x15CAF00
hkBaseObjectVtbl *dynamic_initializer_for__hkpTriangleShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpTriangleShape();
  hkpTriangleShapeTypeInfo.m_size = 112i64;
  hkpTriangleShapeTypeInfo.m_typeName = "hkpTriangleShape";
  hkpTriangleShapeTypeInfo.m_vtable = result;
  hkpTriangleShapeTypeInfo.m_scopedName = "!hkpTriangleShape";
  hkpTriangleShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpTriangleShape;
  hkpTriangleShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpTriangleShape;
  return result;
}

