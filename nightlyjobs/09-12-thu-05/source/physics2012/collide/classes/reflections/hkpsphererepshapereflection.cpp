// File Line: 48
// RVA: 0x15CAC20
void dynamic_initializer_for__hkpSphereRepShapeClass__()
{
  hkClass::hkClass(
    &hkpSphereRepShapeClass,
    "hkpSphereRepShape",
    &hkpShapeClass,
    32,
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

// File Line: 51
// RVA: 0xCEBF10
hkClass *__fastcall hkpSphereRepShape::staticClass()
{
  return &hkpSphereRepShapeClass;
}

// File Line: 58
// RVA: 0xCEBF20
void __fastcall finishLoadedObjecthkpSphereRepShape(void *p, int finishing)
{
  _BYTE *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpShape::hkpShape((hkpShape *)p, (hkFinishLoadedObjectFlag)finishing);
    *(_QWORD *)v2 = &hkpSphereRepShape::`vftable;
    v2[16] = 29;
  }
}

// File Line: 64
// RVA: 0xCEBF50
void __fastcall cleanupLoadedObjecthkpSphereRepShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 68
// RVA: 0xCEBF60
void **__fastcall getVtablehkpSphereRepShape()
{
  hkpShape v1; // [rsp+20h] [rbp-28h]

  hkpShape::hkpShape(&v1, 0);
  return &hkpSphereRepShape::`vftable;
}

// File Line: 90
// RVA: 0x15CAC80
void **dynamic_initializer_for__hkpSphereRepShapeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSphereRepShape();
  hkpSphereRepShapeTypeInfo.m_size = 32i64;
  hkpSphereRepShapeTypeInfo.m_typeName = "hkpSphereRepShape";
  hkpSphereRepShapeTypeInfo.m_vtable = result;
  hkpSphereRepShapeTypeInfo.m_scopedName = "!hkpSphereRepShape";
  hkpSphereRepShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpSphereRepShape;
  hkpSphereRepShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpSphereRepShape;
  return result;
}

