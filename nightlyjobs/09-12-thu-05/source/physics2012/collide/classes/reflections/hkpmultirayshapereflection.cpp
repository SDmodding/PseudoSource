// File Line: 53
// RVA: 0x15CA570
void dynamic_initializer_for__hkpMultiRayShapeRayClass__()
{
  hkClass::hkClass(
    &hkpMultiRayShapeRayClass,
    "hkpMultiRayShapeRay",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpMultiRayShape_RayClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xCEBA00
hkClass *__fastcall hkpMultiRayShape::Ray::staticClass()
{
  return &hkpMultiRayShapeRayClass;
}

// File Line: 63
// RVA: 0xCEBA10
void __fastcall cleanupLoadedObjecthkpMultiRayShapeRay(void *p)
{
  ;
}

// File Line: 102
// RVA: 0x15CA500
void dynamic_initializer_for__hkpMultiRayShapeClass__()
{
  hkClass::hkClass(
    &hkpMultiRayShapeClass,
    "hkpMultiRayShape",
    &hkpShapeClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkpMultiRayShape::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 105
// RVA: 0xCEB9F0
hkClass *__fastcall hkpMultiRayShape::staticClass()
{
  return &hkpMultiRayShapeClass;
}

// File Line: 112
// RVA: 0xCEBA20
void __fastcall finishLoadedObjecthkpMultiRayShape(hkpMultiRayShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpMultiRayShape::hkpMultiRayShape(p, finishing);
}

// File Line: 118
// RVA: 0xCEBA40
void __fastcall cleanupLoadedObjecthkpMultiRayShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 122
// RVA: 0xCEBA50
hkBaseObjectVtbl *__fastcall getVtablehkpMultiRayShape()
{
  hkpMultiRayShape v1; // [rsp+20h] [rbp-48h] BYREF

  hkpMultiRayShape::hkpMultiRayShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 144
// RVA: 0x15CA5D0
hkBaseObjectVtbl *dynamic_initializer_for__hkpMultiRayShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpMultiRayShape();
  hkpMultiRayShapeTypeInfo.m_size = 56i64;
  hkpMultiRayShapeTypeInfo.m_typeName = "hkpMultiRayShape";
  hkpMultiRayShapeTypeInfo.m_vtable = result;
  hkpMultiRayShapeTypeInfo.m_scopedName = "!hkpMultiRayShape";
  hkpMultiRayShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpMultiRayShape;
  hkpMultiRayShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpMultiRayShape;
  return result;
}

