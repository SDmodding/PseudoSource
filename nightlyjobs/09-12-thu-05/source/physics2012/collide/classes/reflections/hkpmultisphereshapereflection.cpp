// File Line: 53
// RVA: 0x15CA630
void dynamic_initializer_for__hkpMultiSphereShapeClass__()
{
  hkClass::hkClass(
    &hkpMultiSphereShapeClass,
    "hkpMultiSphereShape",
    &hkpSphereRepShapeClass,
    176,
    0i64,
    0,
    0i64,
    0,
    &hkpMultiSphereShape::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xCEBA70
hkClass *__fastcall hkpMultiSphereShape::staticClass()
{
  return &hkpMultiSphereShapeClass;
}

// File Line: 63
// RVA: 0xCEBA80
void __fastcall finishLoadedObjecthkpMultiSphereShape(hkpMultiSphereShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpMultiSphereShape::hkpMultiSphereShape(p, finishing);
}

// File Line: 69
// RVA: 0xCEBAA0
void __fastcall cleanupLoadedObjecthkpMultiSphereShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 73
// RVA: 0xCEBAB0
hkBaseObjectVtbl *__fastcall getVtablehkpMultiSphereShape()
{
  hkpMultiSphereShape v1; // [rsp+20h] [rbp-B8h] BYREF

  hkpMultiSphereShape::hkpMultiSphereShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 95
// RVA: 0x15CA6A0
hkBaseObjectVtbl *dynamic_initializer_for__hkpMultiSphereShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpMultiSphereShape();
  hkpMultiSphereShapeTypeInfo.m_size = 176i64;
  hkpMultiSphereShapeTypeInfo.m_typeName = "hkpMultiSphereShape";
  hkpMultiSphereShapeTypeInfo.m_vtable = result;
  hkpMultiSphereShapeTypeInfo.m_scopedName = "!hkpMultiSphereShape";
  hkpMultiSphereShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpMultiSphereShape;
  hkpMultiSphereShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpMultiSphereShape;
  return result;
}

