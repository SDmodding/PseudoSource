// File Line: 52
// RVA: 0x15CACE0
void dynamic_initializer_for__hkpSphereShapeClass__()
{
  hkClass::hkClass(
    &hkpSphereShapeClass,
    "hkpSphereShape",
    &hkpConvexShapeClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkpSphereShapeClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 55
// RVA: 0xCEBF80
hkClass *__fastcall hkpSphereShape::staticClass()
{
  return &hkpSphereShapeClass;
}

// File Line: 62
// RVA: 0xCEBF90
void __fastcall finishLoadedObjecthkpSphereShape(hkpSphereShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpSphereShape::hkpSphereShape(p, finishing);
}

// File Line: 68
// RVA: 0xCEBFB0
void __fastcall cleanupLoadedObjecthkpSphereShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xCEBFC0
hkBaseObjectVtbl *__fastcall getVtablehkpSphereShape()
{
  hkpSphereShape v1; // [rsp+20h] [rbp-48h] BYREF

  hkpSphereShape::hkpSphereShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 94
// RVA: 0x15CAD50
hkBaseObjectVtbl *dynamic_initializer_for__hkpSphereShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpSphereShape();
  hkpSphereShapeTypeInfo.m_size = 56i64;
  hkpSphereShapeTypeInfo.m_typeName = "hkpSphereShape";
  hkpSphereShapeTypeInfo.m_vtable = result;
  hkpSphereShapeTypeInfo.m_scopedName = "!hkpSphereShape";
  hkpSphereShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSphereShape;
  hkpSphereShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSphereShape;
  return result;
}

